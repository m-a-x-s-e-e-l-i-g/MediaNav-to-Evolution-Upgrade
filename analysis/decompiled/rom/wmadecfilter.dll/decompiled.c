/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40ae1000 FUN_40ae1000 */

int FUN_40ae1000(uint param_1,uint param_2,undefined4 param_3,int param_4,ushort param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  
  if ((param_2 == 0) && (param_4 < 3)) {
    return 0;
  }
  if (3 < param_4) {
    return 0;
  }
  if ((((int)param_1 < 0x1f41) || ((int)param_1 < 0x2b12)) || ((int)param_1 < 0x3e81)) {
    iVar3 = 0x200;
    iVar6 = 0x400;
    iVar5 = 0x100;
    iVar1 = 0x80;
LAB_40ae1048:
    if (param_4 == 3) {
      uVar4 = param_5 & 6;
      if (uVar4 == 2) {
        return iVar6;
      }
      if (uVar4 == 4) {
        return iVar5;
      }
      if (uVar4 == 6) {
        return iVar1;
      }
      return iVar3;
    }
  }
  else {
    iVar3 = 0x400;
    if ((int)param_1 < 0x5623) {
      iVar6 = 0x800;
      iVar5 = 0x200;
      iVar1 = 0x100;
      goto LAB_40ae1048;
    }
    if (32000 < (int)param_1) {
      if (((int)param_1 < 0xac45) || ((int)param_1 < 0xbb81)) goto LAB_40ae11a4;
      if ((int)param_1 < 0x17701) {
        iVar3 = 0x1000;
        iVar6 = 0x2000;
        iVar5 = 0x800;
        iVar1 = 0x400;
      }
      else {
        iVar3 = 0x2000;
        if (0x2ee00 < (int)param_1) {
          return 0;
        }
        iVar6 = 0x4000;
        iVar5 = 0x1000;
        iVar1 = 0x800;
      }
      goto LAB_40ae1048;
    }
    if (param_4 != 1) {
LAB_40ae11a4:
      iVar6 = 0x1000;
      iVar3 = 0x800;
      iVar5 = 0x400;
      iVar1 = 0x200;
      goto LAB_40ae1048;
    }
    iVar3 = 0x400;
  }
  iVar1 = (int)param_1 / 2;
  if (param_1 == 0) {
    trap(7);
  }
  uVar2 = (iVar3 * param_2 + iVar1) / param_1 + 7 >> 3;
  if (uVar2 == 0) {
    if (iVar3 * param_2 != 0) goto LAB_40ae10fc;
    if (param_1 == 0) {
      trap(7);
    }
    uVar2 = (iVar3 * param_1 + iVar1) / param_1 + 7 >> 3;
    param_2 = param_1;
  }
  if ((1 < uVar2) || (uVar2 != 0)) {
    return iVar3;
  }
LAB_40ae10fc:
  while( true ) {
    if (param_1 == 0) {
      trap(7);
    }
    if ((iVar3 * 2 * param_2 + iVar1) / param_1 + 7 >> 3 != 0) break;
    iVar3 = iVar3 * 4;
    if (param_1 == 0) {
      trap(7);
    }
    if ((iVar3 * param_2 + iVar1) / param_1 + 7 >> 3 != 0) {
      return iVar3;
    }
  }
  return iVar3 * 2;
}



/* 40ae1264 FUN_40ae1264 */

/* Boundary evidence: original MIPS .pdata 40ae1264..40ae129b. Semantic name remains unreviewed. */

int FUN_40ae1264(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_40ae1000(param_2,param_4,param_3 & 0xffff,param_1,0);
  return iVar1 * 0x11;
}



/* 40ae129c FUN_40ae129c */

void FUN_40ae129c(void)

{
  return;
}



/* 40ae12b4 FUN_40ae12b4 */

undefined4 FUN_40ae12b4(void)

{
  return 0;
}



/* 40ae132c FUN_40ae132c */

undefined4 FUN_40ae132c(void)

{
  return 0;
}



/* 40ae1370 FUN_40ae1370 */

/* WARNING: Removing unreachable block (ram,0x40ae2690) */
/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40ae1370..40ae28e7. Semantic name remains unreviewed. */

int FUN_40ae1370(int *param_1,int *param_2)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 *puVar6;
  void *_Dst;
  int iVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  short *psVar12;
  int *piVar13;
  uint uVar14;
  undefined *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  uint local_34;
  int *local_30;
  
  iVar18 = *param_1;
  local_30 = param_1 + 0x39;
  local_38 = *(int *)(iVar18 + 0xfc);
  iVar17 = 0;
  iVar5 = param_1[10];
  local_34 = 0;
LAB_40ae13cc:
  if (iVar5 == 10) {
    return iVar17;
  }
switchD_40ae13f8_caseD_1:
  switch(iVar5) {
  case 0:
    goto switchD_40ae13f8_caseD_0;
  default:
    goto switchD_40ae13f8_caseD_1;
  case 3:
    iVar5 = *(int *)(iVar18 + 0x84);
    if ((((iVar5 == 1) && (*(int *)(iVar18 + 0xb8) == 1)) && (*(int *)(iVar18 + 0xc4) != 1)) &&
       ((*(int *)(iVar18 + 0x8c) != 1 && (*(int *)(iVar18 + 0x94) != 1)))) {
      iVar17 = (*(code *)param_1[0x4c])(local_30,1);
      if (iVar17 < 0) {
        return iVar17;
      }
      iVar17 = FUN_40af774c((int)local_30,1,&local_48);
      if (iVar17 < 0) {
        return iVar17;
      }
      if (local_48 == 1) {
        return -0x7ffbfffe;
      }
      iVar5 = *(int *)(iVar18 + 0x84);
      *(uint *)(iVar18 + 0xb0) = local_48;
    }
    param_1[10] = 0x12;
    break;
  case 4:
    goto switchD_40ae13f8_caseD_4;
  case 5:
    goto switchD_40ae13f8_caseD_5;
  case 6:
  case 7:
    goto switchD_40ae13f8_caseD_6;
  case 8:
    goto switchD_40ae13f8_caseD_8;
  case 9:
    goto switchD_40ae13f8_caseD_9;
  case 0xb:
    iVar17 = (*(code *)param_1[0x4c])(local_30,1);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    if (local_48 == 0) goto LAB_40ae1e08;
    iVar17 = (*(code *)param_1[0x4c])(local_30,2);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,2,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    if (local_48 == 0) {
      iVar17 = (*(code *)param_1[0x4c])(local_30,4);
      if (iVar17 < 0) {
        return iVar17;
      }
      iVar17 = FUN_40af774c((int)local_30,4,&local_44);
      if (iVar17 < 0) {
        return iVar17;
      }
      iVar17 = (*(code *)param_1[0x4c])(local_30,local_44);
      if (iVar17 < 0) {
        return iVar17;
      }
      iVar17 = FUN_40af774c((int)local_30,local_44,&local_48);
      if (iVar17 < 0) {
        return iVar17;
      }
      param_1[0xf] = local_48 + 1;
      param_1[10] = 0xc;
      iVar5 = 0xc;
    }
    else {
      param_1[0xf] = local_48;
      param_1[10] = 0xc;
      iVar5 = 0xc;
    }
    goto LAB_40ae13cc;
  case 0xc:
    uVar9 = param_1[0xf];
    while (0 < (int)uVar9) {
      uVar14 = 0x18;
      if ((int)uVar9 < 0x19) {
        uVar14 = uVar9;
      }
      iVar17 = (*(code *)param_1[0x4c])(local_30,uVar14);
      if (iVar17 < 0) {
        return iVar17;
      }
      iVar17 = FUN_40af774c((int)local_30,uVar14,&local_48);
      if (iVar17 < 0) {
        return iVar17;
      }
      uVar9 = param_1[0xf] - uVar14;
      param_1[0xf] = uVar9;
    }
LAB_40ae1e08:
    param_1[10] = 0xd;
    iVar5 = 0xd;
    goto LAB_40ae13cc;
  case 0xd:
    iVar17 = (*(code *)param_1[0x4c])(local_30,1);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    *(undefined4 *)(iVar18 + 0x84) = 0;
    *(uint *)(iVar18 + 0x7c) = local_48;
    if (local_48 == 0) {
      *(undefined4 *)(iVar18 + 0xb8) = 1;
      param_1[10] = 0xe;
      param_1[0x17] = 0;
      iVar5 = 0xe;
    }
    else {
      param_1[10] = 0x27;
      *(undefined4 *)(iVar18 + 0xb8) = 1;
      iVar5 = 0x27;
    }
    goto LAB_40ae13cc;
  case 0xe:
    iVar17 = 0;
    param_1[10] = 0x1f;
  case 0x1f:
    param_1[10] = 0x1d;
    iVar5 = 0x1d;
    goto LAB_40ae13cc;
  case 0x11:
    goto switchD_40ae13f8_caseD_11;
  case 0x12:
    iVar5 = *(int *)(iVar18 + 0x84);
    break;
  case 0x1c:
    iVar5 = *(int *)(iVar18 + 0x84);
    goto LAB_40ae1f8c;
  case 0x1d:
    *(undefined4 *)(iVar18 + 0x228) = 0;
    if (*(int *)(iVar18 + 0x40) == 3) {
      iVar17 = (*(code *)param_1[0x4c])(local_30,1);
      if (iVar17 < 0) {
        return iVar17;
      }
      iVar17 = FUN_40af774c((int)local_30,1,&local_48);
      if (iVar17 < 0) {
        return iVar17;
      }
      if (local_48 != 0) {
        *(undefined4 *)(iVar18 + 0x228) = 1;
      }
    }
    param_1[10] = 0x1e;
    *(undefined2 *)(param_1 + 0x25) = 0;
  case 0x1e:
    if ((*(int *)(iVar18 + 0x228) == 1) &&
       (iVar17 = (int)(short)param_1[0x25], iVar17 < *(short *)(iVar18 + 0x21c))) {
      iVar5 = *(int *)(iVar18 + 0x220);
      while( true ) {
        iVar5 = *(short *)(iVar5 + iVar17 * 2) * 0x594 + *(int *)(iVar18 + 0x134);
        uVar9 = (LZCOUNT(*(int *)(iVar5 + 0x24) + 3 >> 2) ^ 0x1fU) + 1;
        iVar17 = (*(code *)param_1[0x4c])(local_30,uVar9);
        if (iVar17 < 0) {
          return iVar17;
        }
        iVar17 = FUN_40af774c((int)local_30,uVar9,&local_48);
        if (iVar17 < 0) {
          return iVar17;
        }
        iVar7 = ((short)param_1[0x25] + 1) * 0x10000;
        iVar17 = iVar7 >> 0x10;
        *(short *)(param_1 + 0x25) = (short)((uint)iVar7 >> 0x10);
        sVar1 = *(short *)(iVar18 + 0x21c);
        *(uint *)(iVar5 + 0x588) = local_48;
        if (sVar1 <= iVar17) break;
        iVar5 = *(int *)(iVar18 + 0x220);
      }
    }
    param_1[10] = 4;
switchD_40ae13f8_caseD_4:
    if ((*(int *)(iVar18 + 0x40) < 3) && (iVar17 = FUN_40ae3384(param_1), iVar17 < 0)) {
      return iVar17;
    }
    FUN_40af352c(iVar18,*(int *)(iVar18 + 0x120));
    *(undefined2 *)(param_1 + 0x25) = 0xffff;
    if (0 < *(short *)(iVar18 + 0x21c)) {
      iVar17 = 0;
      iVar5 = 0;
      do {
        iVar7 = *(short *)(*(int *)(iVar18 + 0x220) + iVar5) * 0x594 + *(int *)(iVar18 + 0x134);
        *(undefined1 *)(iVar7 + 0xbc) = 0;
        FUN_40aeafec(&local_40);
        sVar1 = *(short *)(iVar18 + 0x21c);
        iVar17 = (iVar17 + 1) * 0x10000 >> 0x10;
        *(undefined4 *)(iVar7 + 0xc4) = local_3c;
        *(undefined4 *)(iVar7 + 0xc0) = local_40;
        iVar5 = iVar5 + 2;
      } while (iVar17 < sVar1);
    }
    param_1[10] = 5;
    param_1[0x22] = 0;
switchD_40ae13f8_caseD_5:
    iVar17 = 0;
    *(short *)((int)param_1 + 0x96) = (short)*(undefined4 *)(iVar18 + 0x180);
    param_1[10] = 6;
    *(undefined2 *)(param_1 + 0x25) = 0;
switchD_40ae13f8_caseD_6:
    if ((*(int *)(iVar18 + 0x2c) == 1) && (iVar17 = FUN_40ae3444(param_1,param_2), iVar17 < 0)) {
      return iVar17;
    }
    param_1[10] = 8;
switchD_40ae13f8_caseD_8:
    if (*(int *)(iVar18 + 0x40) < 3) {
      iVar17 = (*(code *)param_1[0x4c])(local_30,1);
      if (iVar17 < 0) {
        return iVar17;
      }
      if ((*(int *)(iVar18 + 0xd0) == 0) || (**(short **)(*(int *)(iVar18 + 0x134) + 200) < 2)) {
        local_34 = 1;
      }
      else {
        iVar17 = FUN_40af774c((int)local_30,1,&local_48);
        if (iVar17 < 0) {
          return iVar17;
        }
        sVar1 = *(short *)(*(int *)(iVar18 + 0x134) + 0x78);
        *param_2 = *param_2 + 1;
        local_34 = local_48;
        if ((sVar1 == 0) && (local_48 != 1)) {
          return -0x7ffbfffe;
        }
      }
    }
    if (0 < *(short *)(iVar18 + 0x21c)) {
      iVar5 = 0;
      uVar4 = (undefined1)local_34;
      iVar7 = 0;
      do {
        iVar16 = (int)*(short *)(*(int *)(iVar18 + 0x220) + iVar7);
        iVar8 = *(int *)(iVar18 + 0x1a8);
        piVar13 = (int *)(iVar16 * 0x594 + *(int *)(iVar18 + 0x134));
        iVar19 = param_1[2];
        if (iVar8 == 0) {
          iVar11 = piVar13[9];
          _Dst = (void *)(piVar13[0xf] + (short)piVar13[0x1f] * 4 + iVar11 * -4);
          *piVar13 = (int)_Dst;
        }
        else {
          iVar11 = piVar13[9];
          _Dst = (void *)(piVar13[0xf] +
                         ((int)(short)piVar13[0x1f] << (*(uint *)(iVar18 + 0x1b0) & 0x1f)) * 4 +
                         (iVar11 << (*(uint *)(iVar18 + 0x1b0) & 0x1f)) * -4);
          *piVar13 = (int)_Dst;
          if (iVar8 != 0) {
            iVar11 = iVar11 << (*(uint *)(iVar18 + 0x1b0) & 0x1f);
          }
        }
        memset(_Dst,0,iVar11 << 2);
        puVar6 = *(undefined1 **)(piVar13[0x32] + 0x10);
        *(undefined4 *)(iVar19 + iVar16 * 8 + 4) = 0;
        *puVar6 = uVar4;
        iVar5 = (iVar5 + 1) * 0x10000 >> 0x10;
        iVar7 = iVar7 + 2;
      } while (iVar5 < *(short *)(iVar18 + 0x21c));
    }
    param_1[10] = 9;
    *(undefined2 *)(param_1 + 0x25) = 0;
    *(undefined2 *)((int)param_1 + 0x96) = 0;
switchD_40ae13f8_caseD_9:
    if (*(int *)(iVar18 + 0x114) == 1) {
      iVar5 = (int)(short)param_1[0x25];
      if (iVar5 < *(short *)(iVar18 + 0x21c)) {
        do {
          bVar3 = 2 < *(int *)(iVar18 + 0x40);
          iVar5 = (int)*(short *)(*(int *)(iVar18 + 0x220) + iVar5 * 2);
          if ((bVar3) && (*(int *)(param_1[2] + iVar5 * 8 + 4) == 0)) {
            iVar17 = 0;
          }
          if (iVar17 < 0) {
            return iVar17;
          }
          iVar7 = iVar5 * 0x594 + *(int *)(iVar18 + 0x134);
          iVar5 = *(int *)(iVar7 + 200);
          local_34 = (uint)**(byte **)(iVar5 + 0x10);
          if (*(int *)(iVar7 + 0x28) == 0) {
            if (bVar3) {
              puVar15 = &UNK_40b111f8;
              piVar13 = *(int **)(iVar7 + 4);
              goto joined_r0x40ae1904;
            }
            if (local_34 == 1) {
              memset(*(void **)(iVar7 + 4),0,*(int *)(iVar18 + 0x124) << 2);
              *(undefined4 *)(iVar7 + 0x44) = 0;
              goto LAB_40ae165c;
            }
          }
          else {
            puVar15 = &UNK_40b111f8;
            if (!bVar3) {
              puVar15 = &DAT_40b07020;
            }
            piVar13 = *(int **)(iVar7 + 4);
joined_r0x40ae1904:
            if (local_34 == 1) {
              if ((bVar3) && (*(int *)(iVar7 + 0xd8) == 1)) {
                iVar17 = 0;
              }
              else {
                if (*(int *)(iVar18 + 0x40) == 1) {
                  iVar17 = FUN_40af774c((int)local_30,5,&local_48);
                  if (iVar17 < 0) {
                    return iVar17;
                  }
                  sVar1 = *(short *)((int)param_1 + 0x96);
                  *piVar13 = local_48 + 10;
                  *(short *)((int)param_1 + 0x96) = sVar1 + 1;
                }
                if ((int)*(short *)((int)param_1 + 0x96) < *(int *)(iVar18 + 0x124)) {
                  do {
                    while( true ) {
                      iVar17 = FUN_40ae5398((int)puVar15,(int)local_30,&local_48,&local_44,
                                            (int *)0x0);
                      if (iVar17 < 0) {
                        return iVar17;
                      }
                      iVar17 = FUN_40af75e4((int)local_30,local_48);
                      if (iVar17 < 0) {
                        return iVar17;
                      }
                      uVar9 = local_44 - 0x3c;
                      if (*(int *)(iVar18 + 0x40) < 3) break;
                      iVar5 = (int)*(short *)((int)param_1 + 0x96);
                      if (iVar5 == 0) {
                        iVar8 = 0x2d / *(int *)(iVar7 + 0xd4);
                        if (*(int *)(iVar7 + 0xd4) == 0) {
                          trap(7);
                        }
                        iVar5 = 0;
                      }
                      else {
LAB_40ae1a78:
                        iVar8 = piVar13[iVar5 + -1];
                      }
                      uVar2 = *(ushort *)((int)param_1 + 0x96);
                      piVar13[iVar5] = iVar8 + uVar9;
                      iVar8 = *(int *)(iVar18 + 0x124);
                      iVar5 = (uVar2 + 1) * 0x10000;
                      *(short *)((int)param_1 + 0x96) = (short)((uint)iVar5 >> 0x10);
                      local_44 = uVar9;
                      if (iVar8 <= iVar5 >> 0x10) goto LAB_40ae1a2c;
                    }
                    iVar5 = (int)*(short *)((int)param_1 + 0x96);
                    if (iVar5 != 0) goto LAB_40ae1a78;
                    uVar2 = *(ushort *)((int)param_1 + 0x96);
                    *piVar13 = local_44 - 0x18;
                    iVar8 = *(int *)(iVar18 + 0x124);
                    iVar5 = (uVar2 + 1) * 0x10000;
                    *(short *)((int)param_1 + 0x96) = (short)((uint)iVar5 >> 0x10);
                    local_44 = uVar9;
                  } while (iVar5 >> 0x10 < iVar8);
LAB_40ae1a2c:
                  iVar5 = *(int *)(iVar7 + 200);
                  local_44 = uVar9;
                }
                else {
                  iVar5 = *(int *)(iVar7 + 200);
                }
              }
              sVar1 = *(short *)(*(int *)(iVar5 + 8) + *(short *)(iVar7 + 0x78) * 2);
              *(undefined2 *)((int)param_1 + 0x96) = 0;
              *(int *)(iVar18 + 0xdc) = (int)sVar1;
            }
            if (local_34 != 0) {
              iVar5 = *piVar13;
              if (1 < *(int *)(iVar18 + 0x124)) {
                iVar8 = 0;
                do {
                  iVar16 = *(int *)((int)piVar13 + iVar8 + 4);
                  iVar8 = iVar8 + 4;
                  if (iVar5 < iVar16) {
                    iVar5 = iVar16;
                  }
                } while (iVar8 != (*(int *)(iVar18 + 0x124) + 0x3fffffff) * 4);
              }
              *(int *)(iVar7 + 0x44) = iVar5;
              *(undefined4 *)(iVar7 + 0xd8) = 1;
            }
LAB_40ae165c:
            if ((2 < *(int *)(iVar18 + 0x40)) && (local_34 == 1)) {
              *(int *)(iVar7 + 0xcc) = (int)*(short *)(iVar7 + 0x7c);
              *(undefined4 *)(iVar7 + 0xd0) = *(undefined4 *)(iVar18 + 0x124);
            }
          }
          iVar7 = ((short)param_1[0x25] + 1) * 0x10000;
          iVar5 = iVar7 >> 0x10;
          *(short *)(param_1 + 0x25) = (short)((uint)iVar7 >> 0x10);
        } while (iVar5 < *(short *)(iVar18 + 0x21c));
      }
    }
    else {
      iVar17 = FUN_40ae3830(param_1,param_2);
      if (iVar17 < 0) {
        return iVar17;
      }
      if (*(int *)(iVar18 + 0x2c) == 1) {
        FUN_40ae41c8(param_1);
      }
    }
    goto LAB_40ae16a0;
  case 0x20:
    iVar5 = *(int *)(iVar18 + 0x84);
    goto LAB_40ae1fa8;
  case 0x23:
    goto switchD_40ae13f8_caseD_23;
  case 0x24:
    goto switchD_40ae13f8_caseD_24;
  case 0x25:
    goto switchD_40ae13f8_caseD_25;
  case 0x26:
    goto switchD_40ae13f8_caseD_26;
  case 0x27:
    iVar17 = (*(code *)param_1[0x4c])(local_30,1);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    *(uint *)(iVar18 + 0x84) = local_48;
    if (local_48 == 1) {
      param_1[10] = 0x28;
      iVar5 = 0x28;
    }
    else {
      param_1[10] = 0x23;
      iVar5 = 0x23;
    }
    goto LAB_40ae13cc;
  case 0x28:
    iVar17 = (*(code *)param_1[0x4c])(local_30,1);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    *(uint *)(iVar18 + 0x8c) = local_48;
    param_1[10] = 0x29;
  case 0x29:
    iVar17 = (*(code *)param_1[0x4c])(local_30,1);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    *(uint *)(iVar18 + 0x94) = local_48;
    param_1[10] = 0x26;
switchD_40ae13f8_caseD_26:
    iVar17 = (*(code *)param_1[0x4c])(local_30,1);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    *(uint *)(iVar18 + 0xb8) = local_48;
    param_1[10] = 0x23;
switchD_40ae13f8_caseD_23:
    param_1[10] = 0x2f;
switchD_40ae13f8_caseD_2f:
    param_1[10] = 0x11;
switchD_40ae13f8_caseD_11:
    param_1[10] = 0x25;
switchD_40ae13f8_caseD_25:
    param_1[10] = 0x24;
switchD_40ae13f8_caseD_24:
    param_1[10] = 0x2b;
switchD_40ae13f8_caseD_2b:
    param_1[10] = 0x2d;
switchD_40ae13f8_caseD_2d:
    param_1[10] = 0x2c;
switchD_40ae13f8_caseD_2c:
    if (*(int *)(iVar18 + 0x84) != 1) goto code_r0x40ae1508;
    param_1[10] = 3;
    iVar5 = 3;
    goto LAB_40ae13cc;
  case 0x2b:
    goto switchD_40ae13f8_caseD_2b;
  case 0x2c:
    goto switchD_40ae13f8_caseD_2c;
  case 0x2d:
    goto switchD_40ae13f8_caseD_2d;
  case 0x2f:
    goto switchD_40ae13f8_caseD_2f;
  case 0x33:
    goto switchD_40ae13f8_caseD_33;
  }
  if (((iVar5 == 1) && (*(int *)(iVar18 + 0xb8) == 1)) &&
     ((*(int *)(iVar18 + 0xc4) != 1 &&
      ((*(int *)(iVar18 + 0x8c) != 1 && (*(int *)(iVar18 + 0x94) != 1)))))) {
    iVar17 = (*(code *)param_1[0x4c])(local_30);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    if (local_48 == 1) {
      return -0x7ffbfffe;
    }
    iVar5 = *(int *)(iVar18 + 0x84);
    *(uint *)(iVar18 + 0x268) = local_48;
  }
  param_1[10] = 0x1c;
LAB_40ae1f8c:
  if ((((iVar5 == 1) && (*(int *)(iVar18 + 0xb8) == 1)) && (*(int *)(iVar18 + 0xc4) != 1)) &&
     ((*(int *)(iVar18 + 0x8c) != 1 && (*(int *)(iVar18 + 0x94) != 1)))) {
    iVar17 = (*(code *)param_1[0x4c])(local_30,1);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    if (local_48 == 1) {
      return -0x7ffbfffe;
    }
    iVar5 = *(int *)(iVar18 + 0x84);
    *(uint *)(iVar18 + 0x2a4) = local_48;
  }
  param_1[10] = 0x20;
  *(undefined2 *)(param_1 + 0x25) = 0;
  param_1[0xb] = 0;
LAB_40ae1fa8:
  if (((iVar5 != 1) || (*(int *)(iVar18 + 0xb8) != 1)) ||
     ((*(int *)(iVar18 + 0xc4) == 1 ||
      ((*(int *)(iVar18 + 0x8c) == 1 || (*(int *)(iVar18 + 0x94) == 1)))))) goto LAB_40ae16a0;
  iVar5 = (int)(short)param_1[0x25];
  if ((int)(uint)*(ushort *)(iVar18 + 0x58) <= iVar5) goto LAB_40ae277c;
  goto LAB_40ae2004;
switchD_40ae13f8_caseD_33:
  iVar17 = (*(code *)param_1[0x4c])(local_30,*(ushort *)(iVar18 + 0x58) + 1);
  if (iVar17 < 0) {
    return iVar17;
  }
  if (*(short *)(iVar18 + 0x58) == 1) {
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar5 = *(int *)(iVar18 + 0x134);
    *(undefined4 *)(iVar5 + 0x48) = 0;
    *(uint *)(iVar5 + 0x28) = local_48;
    bVar3 = local_48 == 0;
  }
  else {
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = *(int *)(iVar18 + 0x134);
    *(uint *)(iVar17 + 0x5dc) = local_48;
    *(uint *)(iVar17 + 0x48) = local_48;
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    *(uint *)(*(int *)(iVar18 + 0x134) + 0x28) = local_48;
    iVar17 = FUN_40af774c((int)local_30,1,&local_48);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar5 = *(int *)(iVar18 + 0x134);
    bVar3 = *(int *)(iVar5 + 0x28) == 0 && local_48 == 0;
    *(uint *)(iVar5 + 0x5bc) = local_48;
    if (*(int *)(iVar5 + 0x48) == 1) {
      FUN_40ae2f48(param_1,iVar5 + 0x594,1);
    }
    else {
      FUN_40ae2f48(param_1,iVar5 + 0x594,0);
    }
  }
  *(undefined4 *)(iVar18 + 0x120) = 1;
  if (bVar3) {
    if (*(int *)(iVar18 + 0x114) == 0) {
      *(undefined2 *)(param_1 + 0x25) = 0;
      iVar17 = 0;
      if (0 < *(short *)(iVar18 + 0x21c)) {
        do {
          iVar17 = *(short *)(*(int *)(iVar18 + 0x220) + iVar17 * 2) * 0x594 +
                   *(int *)(iVar18 + 0x134);
          if (*(short *)(iVar17 + 0x78) < 1) {
            **(undefined1 **)(*(int *)(iVar17 + 200) + 0x10) = 1;
          }
          else {
            **(undefined1 **)(*(int *)(iVar17 + 200) + 0x10) = 0;
          }
          iVar5 = ((short)param_1[0x25] + 1) * 0x10000;
          iVar17 = iVar5 >> 0x10;
          *(short *)(param_1 + 0x25) = (short)((uint)iVar5 >> 0x10);
        } while (iVar17 < *(short *)(iVar18 + 0x21c));
      }
      *(undefined2 *)(param_1 + 0x25) = 0;
      iVar17 = FUN_40ae3830(param_1,param_2);
      if (iVar17 < 0) {
        return iVar17;
      }
    }
    param_1[10] = 10;
    return iVar17;
  }
  param_1[10] = 4;
  iVar5 = 4;
  goto LAB_40ae13cc;
code_r0x40ae1508:
  param_1[10] = 8;
  iVar5 = 8;
  goto switchD_40ae13f8_caseD_1;
LAB_40ae2004:
  do {
    iVar7 = param_1[0xb];
    iVar5 = iVar5 * 0x594 + *(int *)(iVar18 + 0x134);
    if (iVar7 == 1) {
LAB_40ae2074:
      iVar7 = (int)*(short *)(iVar5 + 0x450);
      if (*(short *)(iVar5 + 0x554) < iVar7) {
        do {
          iVar17 = (*(code *)param_1[0x4c])(local_30,7);
          if (iVar17 < 0) {
            return iVar17;
          }
          iVar17 = FUN_40af774c((int)local_30,7,&local_48);
          if (iVar17 < 0) {
            return iVar17;
          }
          if (0xf8 < local_48 << 3) {
            return -0x7ffbfffe;
          }
          iVar7 = (int)*(short *)(iVar5 + 0x450);
          iVar8 = (*(ushort *)(iVar5 + 0x554) + 1) * 0x10000;
          *(uint *)(iVar5 + *(short *)(iVar5 + 0x554) * 0x40 + 0x454) = (local_48 + 1) * 8;
          *(short *)(iVar5 + 0x554) = (short)((uint)iVar8 >> 0x10);
        } while (iVar8 >> 0x10 < iVar7);
        *(undefined2 *)(iVar5 + 0x554) = 0;
      }
      else {
        *(undefined2 *)(iVar5 + 0x554) = 0;
      }
      param_1[0xb] = 2;
LAB_40ae278c:
      if (*(short *)(iVar5 + 0x554) < iVar7) {
        do {
          iVar17 = (*(code *)param_1[0x4c])(local_30,4);
          if (iVar17 < 0) {
            return iVar17;
          }
          iVar17 = FUN_40af774c((int)local_30,4,&local_48);
          if (iVar17 < 0) {
            return iVar17;
          }
          if (0xc < (local_48 & 0xffff)) {
            return -0x7ffbfffe;
          }
          sVar1 = *(short *)(iVar5 + 0x450);
          iVar7 = (*(ushort *)(iVar5 + 0x554) + 1) * 0x10000;
          *(uint *)(iVar5 + *(short *)(iVar5 + 0x554) * 0x40 + 0x470) = local_48;
          *(short *)(iVar5 + 0x554) = (short)((uint)iVar7 >> 0x10);
        } while (iVar7 >> 0x10 < (int)sVar1);
        *(undefined2 *)(iVar5 + 0x554) = 0;
      }
      else {
        *(undefined2 *)(iVar5 + 0x554) = 0;
      }
      param_1[0xb] = 0;
    }
    else {
      if (iVar7 == 0) {
        iVar17 = (*(code *)param_1[0x4c])(local_30,3);
        if (iVar17 < 0) {
          return iVar17;
        }
        iVar17 = FUN_40af774c((int)local_30,3,&local_48);
        if (iVar17 < 0) {
          return iVar17;
        }
        if (3 < (ushort)local_48) {
          return -0x7ffbfffe;
        }
        *(ushort *)(iVar5 + 0x450) = (ushort)local_48 + 1;
        *(undefined2 *)(iVar5 + 0x554) = 0;
        param_1[0xb] = 1;
        goto LAB_40ae2074;
      }
      if (iVar7 == 2) {
        iVar7 = (int)*(short *)(iVar5 + 0x450);
        goto LAB_40ae278c;
      }
    }
    iVar7 = ((short)param_1[0x25] + 1) * 0x10000;
    iVar5 = iVar7 >> 0x10;
    *(short *)(param_1 + 0x25) = (short)((uint)iVar7 >> 0x10);
  } while (iVar5 < (int)(uint)*(ushort *)(iVar18 + 0x58));
LAB_40ae277c:
  param_1[5] = 1;
LAB_40ae16a0:
  iVar5 = 10;
  param_1[10] = 10;
  goto LAB_40ae13cc;
switchD_40ae13f8_caseD_0:
  if (*(int *)(iVar18 + 0x40) < 3) {
    if (*(int *)(iVar18 + 0xd0) != 0) {
      uVar9 = (LZCOUNT(LZCOUNT(*(undefined4 *)(iVar18 + 0xe0)) ^ 0x1f) ^ 0x1fU) + 1;
      iVar17 = (*(code *)param_1[0x4c])(local_30,uVar9);
      if (iVar17 < 0) {
        return iVar17;
      }
      iVar17 = FUN_40af774c((int)local_30,uVar9,&local_48);
      if (iVar17 < 0) {
        return iVar17;
      }
      iVar17 = 1 << (local_48 & 0x1f);
      local_38 = *(int *)(iVar18 + 0xfc) / iVar17;
      if (iVar17 == 0) {
        trap(7);
      }
      if (local_38 < *(int *)(iVar18 + 0xe8)) {
        return -0x7ffbfffe;
      }
      if (*(int *)(iVar18 + 0xfc) < local_38) {
        return -0x7ffbfffe;
      }
    }
    *(short *)(iVar18 + 0x21c) = *(short *)(iVar18 + 0x58);
    if (*(short *)(iVar18 + 0x58) != 0) {
      iVar5 = *(int *)(iVar18 + 0x220);
      iVar17 = 0;
      iVar8 = 0;
      iVar7 = 1;
      do {
        *(short *)(iVar5 + iVar8) = (short)iVar17;
        bVar3 = iVar7 < (int)(uint)*(ushort *)(iVar18 + 0x58);
        iVar17 = (iVar17 + 1) * 0x10000 >> 0x10;
        iVar8 = iVar8 + 2;
        iVar7 = iVar7 + 1;
      } while (bVar3);
    }
    iVar17 = FUN_40aeee4c(param_1,local_38);
    if (iVar17 < 0) {
      return iVar17;
    }
LAB_40ae1d00:
    iVar17 = FUN_40aec4b8(iVar18);
    if (iVar17 < 0) {
      return iVar17;
    }
    iVar17 = FUN_40aef114(iVar18);
    if (iVar17 < 0) {
      return iVar17;
    }
    if (*(int *)(iVar18 + 0x40) < 3) {
      param_1[10] = 0x33;
      iVar5 = 0x33;
    }
    else {
      iVar5 = 0;
      if (0 < *(short *)(iVar18 + 0x21c)) {
        iVar7 = 0;
        do {
          iVar8 = *(short *)(*(int *)(iVar18 + 0x220) + iVar7) * 0x594 + *(int *)(iVar18 + 0x134);
          if (*(short *)(iVar8 + 0x78) == 0) {
            *(undefined4 *)(iVar8 + 0xd4) = 1;
            *(undefined4 *)(iVar8 + 0xd8) = 0;
            memset(*(void **)(iVar8 + 4),0,0x70);
            memset(*(void **)(iVar8 + 8),0,0x70);
            *(undefined4 *)(iVar8 + 0x44) = 0;
          }
          FUN_40ae2f48(param_1,iVar8,0);
          iVar5 = (iVar5 + 1) * 0x10000 >> 0x10;
          iVar7 = iVar7 + 2;
        } while (iVar5 < *(short *)(iVar18 + 0x21c));
      }
      param_1[10] = 0xb;
      iVar5 = 0xb;
    }
    goto LAB_40ae13cc;
  }
  uVar9 = (uint)*(ushort *)(iVar18 + 0x58);
  iVar5 = (int)(short)*(int *)(iVar18 + 0xfc);
  iVar17 = uVar9 * *(int *)(iVar18 + 0xfc);
  iVar8 = *(int *)(iVar18 + 0x134);
  iVar7 = iVar5;
  if (uVar9 != 0) {
    iVar19 = *(int *)(iVar8 + 200);
    iVar16 = iVar8;
    while( true ) {
      if (**(short **)(iVar19 + 0xc) < iVar5) {
        iVar7 = (int)*(short *)(*(int *)(iVar19 + 8) + *(short *)(iVar16 + 0x78) * 2);
        iVar5 = (int)**(short **)(iVar19 + 0xc);
      }
      if (iVar16 == iVar8 + uVar9 * 0x594 + -0x594) break;
      iVar19 = *(int *)(iVar16 + 0x65c);
      iVar16 = iVar16 + 0x594;
    }
  }
  *(undefined2 *)(iVar18 + 0x21c) = 0;
  if (uVar9 != 0) {
    iVar16 = 0;
    do {
      psVar12 = *(short **)(*(int *)(iVar8 + 200) + 0xc);
      iVar19 = *(int *)(*(int *)(iVar8 + 200) + 8);
      iVar17 = iVar17 - *psVar12;
      if ((iVar5 == *psVar12) && (*(short *)(iVar19 + *(short *)(iVar8 + 0x78) * 2) == iVar7)) {
        *(short *)(*(int *)(iVar18 + 0x220) + *(short *)(iVar18 + 0x21c) * 2) = (short)iVar16;
        *(short *)(iVar18 + 0x21c) = *(short *)(iVar18 + 0x21c) + 1;
        iVar11 = (int)*(short *)(iVar8 + 0x78);
        *(undefined2 *)(iVar8 + 0x84) = *(undefined2 *)(iVar19 + (iVar11 + 1) * 2);
        psVar10 = (short *)(iVar19 + iVar11 * 2);
        *(short *)(iVar8 + 0x82) = *psVar10;
        *(undefined2 *)(iVar8 + 0x80) = *(undefined2 *)(iVar19 + (iVar11 + -1) * 2);
        sVar1 = *psVar10;
        iVar17 = iVar17 - sVar1;
        *psVar12 = sVar1 + *psVar12;
        uVar9 = (uint)*(ushort *)(iVar18 + 0x58);
      }
      iVar16 = iVar16 + 1;
      iVar8 = iVar8 + 0x594;
    } while (iVar16 < (int)uVar9);
    if ((((int)*(short *)(iVar18 + 0x21c) <= (int)uVar9) && (0 < *(short *)(iVar18 + 0x21c))) &&
       (-1 < iVar17)) {
      param_1[0x37] = (uint)(iVar17 == 0);
      goto LAB_40ae1d00;
    }
  }
  return -0x7ffbfffe;
}



/* 40ae28e8 FUN_40ae28e8 */

/* WARNING: Removing unreachable block (ram,0x40ae2efc) */
/* Boundary evidence: original MIPS .pdata 40ae28e8..40ae2f47. Semantic name remains unreviewed. */

int FUN_40ae28e8(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  code *pcVar6;
  undefined2 *puVar7;
  int iVar8;
  short *psVar9;
  uint uVar10;
  short sVar11;
  short sVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  uint local_38 [2];
  uint *local_30;
  
  iVar14 = *param_1;
  if ((*(int *)(iVar14 + 0xd0) != 0) && (*(int *)(iVar14 + 0xe0) < 2)) {
    return -0x7ffbfffe;
  }
  iVar2 = 0;
  if (*(int *)(iVar14 + 0xa8) == 1) {
    *(undefined4 *)(iVar14 + 0x16c) = 0;
  }
  local_30 = (uint *)(iVar14 + 0x234);
  iVar5 = param_1[0xd];
  piVar15 = param_1 + 0x39;
LAB_40ae2974:
  if (iVar5 == 0) {
    if (*(int *)(iVar14 + 0xa8) != 1) {
      return iVar2;
    }
    *(int *)(iVar14 + 0x170) = *(int *)(iVar14 + 0xfc) - *(int *)(iVar14 + 0x16c);
    return iVar2;
  }
switchD_40ae2990_caseD_0:
  switch(iVar5) {
  default:
    goto switchD_40ae2990_caseD_0;
  case 1:
    if (*(int *)(iVar14 + 0x230) != 0) {
      iVar2 = (*(code *)param_1[0x4c])(piVar15,*(undefined4 *)(iVar14 + 0x23c));
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_40af774c((int)piVar15,*(uint *)(iVar14 + 0x23c),local_30);
      if (iVar2 < 0) {
        return iVar2;
      }
      if (param_1[0x89] != 0) {
        iVar5 = *(int *)(iVar14 + 0x234);
        iVar2 = *(int *)(iVar14 + 0x23c);
        uVar13 = FUN_40aef3d4(param_1);
        FUN_40af76f8((int)piVar15,iVar5 - iVar2,uVar13 & 7);
      }
    }
    param_1[0xd] = 3;
    break;
  case 2:
    goto switchD_40ae2990_caseD_2;
  case 4:
    goto switchD_40ae2990_caseD_4;
  case 5:
    goto switchD_40ae2990_caseD_5;
  case 6:
    local_38[0] = 0;
    if (*(int *)(iVar14 + 0x40) < 3) goto LAB_40ae2c6c;
    pcVar6 = (code *)param_1[0x4c];
    *(undefined4 *)(iVar14 + 0x164) = 0;
    iVar2 = (*pcVar6)(piVar15,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_40af774c((int)piVar15,1,local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (local_38[0] == 0) goto LAB_40ae2c6c;
    param_1[0xd] = 7;
    iVar5 = 7;
    goto LAB_40ae2974;
  case 7:
    iVar2 = (*(code *)param_1[0x4c])(piVar15,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_40af774c((int)piVar15,1,local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar5 = 8;
    if (local_38[0] == 0) {
      iVar5 = 9;
    }
    *(uint *)(iVar14 + 0x164) = local_38[0];
    param_1[0xd] = iVar5;
    goto LAB_40ae2974;
  case 8:
    uVar13 = LZCOUNT(*(undefined4 *)(iVar14 + 0xf8)) ^ 0x1f;
    local_38[0] = 0;
    iVar2 = (*(code *)param_1[0x4c])(piVar15,uVar13);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_40af774c((int)piVar15,uVar13,local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    param_1[0xd] = 9;
    iVar5 = param_1[0xd];
    *(uint *)(iVar14 + 0x168) = local_38[0];
    goto LAB_40ae2974;
  case 9:
    iVar2 = (*(code *)param_1[0x4c])(piVar15,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_40af774c((int)piVar15,1,local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar5 = 10;
    if (local_38[0] == 0) {
      iVar5 = 0;
    }
    param_1[0xd] = iVar5;
    goto LAB_40ae2974;
  case 10:
    uVar13 = LZCOUNT(*(undefined4 *)(iVar14 + 0xf8)) ^ 0x1f;
    local_38[0] = 0;
    iVar2 = (*(code *)param_1[0x4c])(piVar15,uVar13);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_40af774c((int)piVar15,uVar13,local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    param_1[0xd] = 0;
    *(uint *)(iVar14 + 0x16c) = local_38[0];
    iVar5 = param_1[0xd];
    goto LAB_40ae2974;
  }
  if (((2 < *(int *)(iVar14 + 0x40)) && (param_1[0x2e] != 0)) && (param_1[0x2f] == 0)) {
    uVar13 = FUN_40aeafac();
    iVar5 = param_1[0x2d];
    iVar2 = (int)uVar13 >> 0x1f;
    uVar10 = param_1[0x2c];
    if ((iVar5 < iVar2) || ((iVar2 == iVar5 && (uVar10 < uVar13)))) {
      param_1[0x2c] = 0;
      param_1[0x2d] = 0;
      param_1[0x2e] = 0;
    }
    else {
      param_1[0x2c] = uVar10 - uVar13;
      param_1[0x2d] = (iVar5 - iVar2) - (uint)(uVar10 < uVar10 - uVar13);
      param_1[0x2e] = 0;
    }
  }
  param_1[0x62] = 0;
  param_1[0xd] = 4;
switchD_40ae2990_caseD_4:
  param_1[0xd] = 5;
  iVar2 = 0;
switchD_40ae2990_caseD_5:
  if (*(int *)(iVar14 + 0x244) == 0) {
    param_1[0xd] = 6;
  }
  else {
    iVar2 = (*(code *)param_1[0x4c])(piVar15,8);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_40af774c((int)piVar15,8,local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    *(char *)(iVar14 + 0x20c) = (char)local_38[0];
    param_1[0xd] = 6;
  }
  iVar5 = 6;
  goto switchD_40ae2990_caseD_0;
switchD_40ae2990_caseD_2:
  if (*(int *)(iVar14 + 0xd0) == 0) {
    if (*(int *)(iVar14 + 0x40) < 3) {
      param_1[0xd] = 0;
      iVar5 = param_1[0xd];
      goto LAB_40ae2974;
    }
  }
  else if (*(int *)(iVar14 + 0x40) < 3) {
    uVar13 = (LZCOUNT(LZCOUNT(*(undefined4 *)(iVar14 + 0xe0)) ^ 0x1f) ^ 0x1fU) + 1;
    iVar2 = (*(code *)param_1[0x4c])(piVar15,uVar13 * 2);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_40af774c((int)piVar15,uVar13,local_38);
    uVar10 = local_38[0];
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar5 = *(int *)(iVar14 + 0xfc);
    iVar2 = FUN_40af774c((int)piVar15,uVar13,local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar3 = 1 << (uVar10 & 0x1f);
    if (iVar3 == 0) {
      trap(7);
    }
    iVar8 = *(int *)(iVar14 + 0xfc);
    sVar12 = (short)(iVar5 / iVar3);
    if ((*(int *)(iVar14 + 0xe8) <= (int)sVar12) &&
       (iVar5 = 1 << (local_38[0] & 0x1f), sVar12 <= iVar8)) {
      if (iVar5 == 0) {
        trap(7);
      }
      sVar11 = (short)(iVar8 / iVar5);
      if ((*(int *)(iVar14 + 0xe8) <= (int)sVar11) && (sVar11 <= iVar8)) {
        iVar5 = 0;
        if (*(short *)(iVar14 + 0x58) == 0) {
LAB_40ae2c6c:
          param_1[0xd] = 0;
          iVar5 = param_1[0xd];
        }
        else {
          iVar8 = *(int *)(iVar14 + 0x134);
          iVar3 = 1;
          do {
            psVar9 = *(short **)(iVar8 + iVar5 + 200);
            psVar4 = *(short **)(psVar9 + 4);
            puVar7 = *(undefined2 **)(psVar9 + 6);
            psVar4[-1] = sVar12;
            *psVar9 = 0;
            *psVar4 = sVar11;
            *puVar7 = 0;
            iVar5 = iVar5 + 0x594;
            *psVar9 = *psVar9 + 1;
            bVar1 = iVar3 < (int)(uint)*(ushort *)(iVar14 + 0x58);
            iVar3 = iVar3 + 1;
          } while (bVar1);
          param_1[0xd] = 0;
          iVar5 = param_1[0xd];
        }
        goto LAB_40ae2974;
      }
    }
    return -0x7ffbfffe;
  }
  param_1[0xd] = 1;
  iVar5 = 1;
  goto LAB_40ae2974;
}



/* 40ae2f48 FUN_40ae2f48 */

void FUN_40ae2f48(int *param_1,int param_2,short param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x11c);
  if (iVar1 == 3) {
    if (param_3 != 1) {
      *(undefined **)(param_2 + 0x20) = &DAT_40b0be58;
      *(undefined2 *)((int)param_1 + 0x136) = 0x46;
      *(undefined **)(param_2 + 0x18) = &DAT_40b0727c;
      *(undefined **)(param_2 + 0x1c) = &DAT_40b0baa4;
      return;
    }
    *(undefined **)(param_2 + 0x20) = &DAT_40b0c570;
    *(undefined2 *)((int)param_1 + 0x136) = 0x28;
    *(undefined **)(param_2 + 0x18) = &DAT_40b08f8c;
    *(undefined **)(param_2 + 0x1c) = &DAT_40b0c20c;
    return;
  }
  if (iVar1 == 1) {
    if (param_3 != 1) {
      *(undefined **)(param_2 + 0x20) = &DAT_40b0f394;
      *(undefined2 *)((int)param_1 + 0x136) = 0x3c;
      *(undefined **)(param_2 + 0x18) = &DAT_40b0a5d0;
      *(undefined **)(param_2 + 0x1c) = &DAT_40b0ee64;
      return;
    }
    *(undefined **)(param_2 + 0x20) = &DAT_40b0fd18;
    *(undefined2 *)((int)param_1 + 0x136) = 0x28;
    *(undefined **)(param_2 + 0x18) = &DAT_40b0af88;
    *(undefined **)(param_2 + 0x1c) = &DAT_40b0f8c4;
    return;
  }
  if (iVar1 != 2) {
    return;
  }
  if (param_3 != 1) {
    *(undefined **)(param_2 + 0x20) = &DAT_40b0d340;
    *(undefined2 *)((int)param_1 + 0x136) = 0x154;
    *(undefined **)(param_2 + 0x18) = &DAT_40b0794c;
    *(undefined **)(param_2 + 0x1c) = &DAT_40b0c8d4;
    return;
  }
  *(undefined **)(param_2 + 0x20) = &DAT_40b0e608;
  *(undefined2 *)((int)param_1 + 0x136) = 0xb4;
  *(undefined **)(param_2 + 0x18) = &DAT_40b0962c;
  *(undefined **)(param_2 + 0x1c) = &DAT_40b0ddac;
  return;
}



/* 40ae30ac FUN_40ae30ac */

/* Boundary evidence: original MIPS .pdata 40ae30ac..40ae3297. Semantic name remains unreviewed. */

int * FUN_40ae30ac(int *param_1,int param_2,undefined4 param_3,uint param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  int local_18;
  uint local_14;
  
  if (param_5 != 0) {
    uVar6 = FUN_40aff9f8();
    uVar3 = (uint)((ulonglong)uVar6 >> 0x20);
    uVar1 = (uint)uVar6;
    uVar5 = uVar3;
    if (uVar3 == 0) {
      uVar5 = uVar1;
    }
    local_18 = 1;
    if (uVar3 == 0) {
      local_18 = 0x21;
    }
    iVar4 = 0;
    if (uVar3 == 0) {
      iVar4 = 0x20;
    }
    if ((uVar5 & 0xf0000000) == 0) {
      do {
        local_18 = iVar4;
        uVar5 = uVar5 << 4;
        iVar4 = local_18 + 4;
      } while ((uVar5 & 0xf0000000) == 0);
      local_18 = local_18 + 5;
    }
    if (-1 < (int)uVar5) {
      do {
        local_18 = iVar4;
        uVar5 = uVar5 << 1;
        iVar4 = local_18 + 1;
      } while (-1 < (int)uVar5);
      local_18 = local_18 + 2;
    }
    if (local_18 < 0x21) {
      uVar2 = 0x20 - local_18;
      uVar5 = uVar3 >> (uVar2 & 0x1f);
      if ((uVar2 & 0x20) == 0) {
        uVar5 = (uVar3 << 1) << (~uVar2 & 0x1f) | uVar1 >> (uVar2 & 0x1f);
      }
    }
    else {
      uVar5 = uVar1 << (local_18 - 0x20U & 0x1f);
      if ((local_18 - 0x20U & 0x20) != 0) {
        uVar5 = 0;
      }
    }
    iVar4 = param_2 - param_4;
    local_14 = (&DAT_40b10a78)[uVar5 >> 0x18] +
               (int)((ulonglong)
                     (uint)((&DAT_40b10a78)[(uVar5 >> 0x18) + 1] - (&DAT_40b10a78)[uVar5 >> 0x18]) *
                     (ulonglong)(uVar5 << 8) >> 0x20);
    if ((iVar4 + local_18 & 1U) != 0) {
      iVar4 = ~param_4 + param_2;
      local_14 = (uint)((ulonglong)local_14 * 0xb504f333 >> 0x20);
    }
    local_18 = (iVar4 >> 1) + -3 + local_18;
    local_14 = local_14 >> 1;
    FUN_40aeab1c(&local_18);
    *param_1 = local_18;
    param_1[1] = local_14;
    return param_1;
  }
  param_1[1] = 0x7fffffff;
  *param_1 = 0;
  return param_1;
}



/* 40ae3298 FUN_40ae3298 */

/* Boundary evidence: original MIPS .pdata 40ae3298..40ae3383. Semantic name remains unreviewed. */

int * FUN_40ae3298(int *param_1,uint *param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  
  if (param_3 < 1) {
    uVar2 = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    puVar5 = param_2;
    do {
      param_3 = param_3 + -1;
      lVar1 = (ulonglong)*puVar5 * (ulonglong)*puVar5;
      puVar5 = puVar5 + 1;
      uVar2 = uVar3 + (int)lVar1;
      param_2 = (uint *)(uVar4 + (int)((ulonglong)lVar1 >> 0x20));
      uVar4 = (uint)(uVar2 < uVar3) + (int)param_2;
      uVar3 = uVar2;
    } while (0 < param_3);
  }
  FUN_40aeab90(&local_18,param_2,uVar2,uVar4,0x2a);
  local_1c = local_14;
  local_20 = local_18;
  local_1c = FUN_40aff9dc();
  FUN_40aeab1c(&local_20);
  *param_1 = local_20;
  param_1[1] = local_1c;
  return param_1;
}



/* 40ae3384 FUN_40ae3384 */

/* Boundary evidence: original MIPS .pdata 40ae3384..40ae3443. Semantic name remains unreviewed. */

int FUN_40ae3384(int *param_1)

{
  int iVar1;
  int iVar2;
  uint local_20 [3];
  
  iVar2 = *param_1;
  iVar1 = (*(code *)param_1[0x4c])(param_1 + 0x39,0x15);
  if (-1 < iVar1) {
    while (iVar1 = FUN_40af774c((int)(param_1 + 0x39),7,local_20), -1 < iVar1) {
      if (local_20[0] != 0x7f) {
        *(uint *)(iVar2 + 0x120) = *(int *)(iVar2 + 0x120) + local_20[0];
        return iVar1;
      }
      *(int *)(iVar2 + 0x120) = *(int *)(iVar2 + 0x120) + 0x7f;
    }
  }
  return iVar1;
}



/* 40ae3444 FUN_40ae3444 */

/* Boundary evidence: original MIPS .pdata 40ae3444..40ae382f. Semantic name remains unreviewed. */

int FUN_40ae3444(int *param_1,int *param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  byte *pbVar13;
  int iVar14;
  char *pcVar15;
  uint local_38;
  uint local_34;
  uint local_30 [2];
  
  iVar9 = 0;
  iVar14 = *param_1;
  if (param_1[10] == 6) {
    iVar3 = (int)(short)param_1[0x25];
    if (iVar3 < (int)(uint)*(ushort *)(iVar14 + 0x58)) {
      iVar5 = *(int *)(iVar14 + 0x180);
      do {
        iVar11 = *(int *)(iVar14 + 0x134);
        iVar9 = (*(code *)param_1[0x4c])(param_1 + 0x39,*(int *)(iVar14 + 0x124) - iVar5);
        if (iVar9 < 0) {
          return iVar9;
        }
        iVar11 = iVar3 * 0x594 + iVar11;
        if (*(int *)(iVar11 + 0x28) == 0) {
          *(undefined4 *)(iVar11 + 0x24) = 0;
        }
        else {
          pcVar15 = *(char **)(iVar11 + 0xc);
          *pcVar15 = '\0';
          iVar6 = (int)*(short *)((int)param_1 + 0x96);
          iVar8 = *(int *)(iVar14 + 0x128);
          *(int *)(iVar11 + 0x24) = *(int *)(iVar14 + 0x184) - *(int *)(iVar14 + 0x104);
          iVar4 = *(int *)(iVar8 + iVar6 * 4);
          iVar3 = *(int *)(iVar14 + 0x108);
          iVar5 = *(int *)(iVar14 + 0x184);
          if (*(int *)(iVar14 + 0x184) <= iVar4) {
            iVar5 = iVar4;
          }
          if (iVar5 < iVar3) {
            do {
              while( true ) {
                iVar4 = *(int *)(iVar8 + (iVar6 + 1) * 4);
                iVar9 = FUN_40af774c((int)(param_1 + 0x39),1,local_30);
                if (iVar4 <= iVar3) {
                  iVar3 = iVar4;
                }
                if (iVar9 < 0) {
                  return iVar9;
                }
                pcVar15[*(short *)((int)param_1 + 0x96)] = (char)local_30[0];
                sVar2 = *(short *)((int)param_1 + 0x96);
                *param_2 = *param_2 + 1;
                if (pcVar15[sVar2] != '\0') break;
                iVar8 = *(int *)(iVar14 + 0x128);
                *(int *)(iVar11 + 0x24) = (*(int *)(iVar11 + 0x24) - iVar5) + iVar3;
                iVar7 = (sVar2 + 1) * 0x10000;
                iVar6 = iVar7 >> 0x10;
                iVar4 = *(int *)(iVar8 + iVar6 * 4);
                iVar3 = *(int *)(iVar14 + 0x108);
                iVar5 = *(int *)(iVar14 + 0x184);
                if (*(int *)(iVar14 + 0x184) <= iVar4) {
                  iVar5 = iVar4;
                }
                *(short *)((int)param_1 + 0x96) = (short)((uint)iVar7 >> 0x10);
                if (iVar3 <= iVar5) goto LAB_40ae37d0;
              }
              *pcVar15 = *pcVar15 + '\x01';
              iVar8 = *(int *)(iVar14 + 0x128);
              iVar7 = (*(short *)((int)param_1 + 0x96) + 1) * 0x10000;
              iVar6 = iVar7 >> 0x10;
              iVar4 = *(int *)(iVar8 + iVar6 * 4);
              iVar3 = *(int *)(iVar14 + 0x108);
              iVar5 = *(int *)(iVar14 + 0x184);
              if (*(int *)(iVar14 + 0x184) <= iVar4) {
                iVar5 = iVar4;
              }
              *(short *)((int)param_1 + 0x96) = (short)((uint)iVar7 >> 0x10);
            } while (iVar5 < iVar3);
LAB_40ae37d0:
            iVar3 = *(int *)(iVar14 + 0x124);
          }
          else {
            iVar3 = *(int *)(iVar14 + 0x124);
          }
          if (iVar6 < iVar3) {
            pcVar15[iVar6] = '\0';
          }
        }
        iVar5 = *(int *)(iVar14 + 0x180);
        iVar11 = ((short)param_1[0x25] + 1) * 0x10000;
        iVar3 = iVar11 >> 0x10;
        *(short *)((int)param_1 + 0x96) = (short)iVar5;
        *(short *)(param_1 + 0x25) = (short)((uint)iVar11 >> 0x10);
      } while (iVar3 < (int)(uint)*(ushort *)(iVar14 + 0x58));
    }
    param_1[10] = 7;
    *(undefined2 *)(param_1 + 0x25) = 0;
    *(undefined2 *)((int)param_1 + 0x96) = 0;
  }
  else if (param_1[10] != 7) {
    return 0;
  }
  iVar3 = (int)(short)param_1[0x25];
  piVar12 = param_1 + 0x39;
  if (iVar3 < (int)(uint)*(ushort *)(iVar14 + 0x58)) {
    do {
      iVar3 = iVar3 * 0x594 + *(int *)(iVar14 + 0x134);
      if (*(int *)(iVar3 + 0x28) != 0) {
        pbVar13 = *(byte **)(iVar3 + 0xc);
        piVar10 = *(int **)(iVar3 + 0x14);
        uVar1 = (ushort)*pbVar13;
        if (uVar1 != 0) {
          sVar2 = *(short *)((int)param_1 + 0x96);
          if (sVar2 == 0) {
            iVar9 = FUN_40af774c((int)piVar12,7,local_30);
            if (iVar9 < 0) {
              return iVar9;
            }
            sVar2 = *(short *)((int)param_1 + 0x96);
            *piVar10 = local_30[0] - 0x13;
            iVar3 = *param_2;
            sVar2 = sVar2 + 1;
            *(short *)((int)param_1 + 0x96) = sVar2;
            *param_2 = iVar3 + 7;
            uVar1 = (ushort)*pbVar13;
          }
          if (sVar2 < (short)uVar1) {
            do {
              iVar9 = FUN_40ae5398(0x40b071e4,(int)piVar12,&local_34,&local_38,(int *)0x0);
              if (iVar9 < 0) {
                return iVar9;
              }
              iVar9 = FUN_40af75e4((int)piVar12,local_34);
              if (iVar9 < 0) {
                return iVar9;
              }
              sVar2 = *(short *)((int)param_1 + 0x96);
              iVar5 = piVar10[sVar2 + -1];
              iVar3 = (*(ushort *)((int)param_1 + 0x96) + 1) * 0x10000;
              *(short *)((int)param_1 + 0x96) = (short)((uint)iVar3 >> 0x10);
              piVar10[sVar2] = (local_38 - 0x12) + iVar5;
            } while (iVar3 >> 0x10 < (int)(uint)*pbVar13);
          }
        }
      }
      *(undefined2 *)((int)param_1 + 0x96) = 0;
      iVar5 = ((short)param_1[0x25] + 1) * 0x10000;
      iVar3 = iVar5 >> 0x10;
      *(short *)(param_1 + 0x25) = (short)((uint)iVar5 >> 0x10);
    } while (iVar3 < (int)(uint)*(ushort *)(iVar14 + 0x58));
  }
  return iVar9;
}



/* 40ae3830 FUN_40ae3830 */

/* Boundary evidence: original MIPS .pdata 40ae3830..40ae3a63. Semantic name remains unreviewed. */

int FUN_40ae3830(int *param_1,int *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint local_58;
  int aiStack_54 [11];
  
  iVar9 = *param_1;
  iVar3 = (int)(short)param_1[0x25];
  iVar8 = 0;
  if (iVar3 < *(short *)(iVar9 + 0x21c)) {
    do {
      while( true ) {
        iVar3 = *(short *)(*(int *)(iVar9 + 0x220) + iVar3 * 2) * 0x594 + *(int *)(iVar9 + 0x134);
        cVar1 = **(char **)(*(int *)(iVar3 + 200) + 0x10);
        if (*(int *)(iVar3 + 0x28) == 0) break;
        if (cVar1 == '\x01') {
          iVar5 = *(int *)(iVar3 + 0x38);
          for (iVar8 = (int)*(short *)((int)param_1 + 0x96); iVar8 < 10; iVar8 = iVar8 >> 0x10) {
            iVar7 = 3;
            if ((iVar8 == 0) || (iVar8 == 8)) {
              uVar6 = 3;
            }
            else {
              uVar6 = 3;
              if (iVar8 != 9) {
                iVar7 = 4;
                uVar6 = 4;
              }
            }
            iVar8 = FUN_40af774c((int)(param_1 + 0x39),uVar6,&local_58);
            if (iVar8 < 0) {
              return iVar8;
            }
            *(char *)(iVar5 + *(short *)((int)param_1 + 0x96)) = (char)local_58;
            iVar8 = (*(short *)((int)param_1 + 0x96) + 1) * 0x10000;
            *param_2 = *param_2 + iVar7;
            *(short *)((int)param_1 + 0x96) = (short)((uint)iVar8 >> 0x10);
          }
          FUN_40ae8460(iVar9,iVar5,aiStack_54,10);
          iVar8 = FUN_40ae9390(iVar9,aiStack_54,iVar3);
          if (iVar8 < 0) {
            return iVar8;
          }
        }
        else {
LAB_40ae389c:
          if (0 < *(short *)(iVar3 + 0x78)) {
            FUN_40ae5a0c(iVar9,iVar3);
          }
        }
LAB_40ae38b0:
        *(undefined2 *)((int)param_1 + 0x96) = 0;
        iVar5 = ((short)param_1[0x25] + 1) * 0x10000;
        iVar3 = iVar5 >> 0x10;
        *(short *)(param_1 + 0x25) = (short)((uint)iVar5 >> 0x10);
        if (*(short *)(iVar9 + 0x21c) <= iVar3) {
          return iVar8;
        }
      }
      if (cVar1 != '\x01') goto LAB_40ae389c;
      *(undefined4 *)(iVar3 + 0xa0) = 0x200000;
      puVar4 = *(undefined4 **)(iVar3 + 0x38);
      if (*(short *)(iVar3 + 0x7c) < 1) goto LAB_40ae38b0;
      puVar2 = puVar4 + ((int)*(short *)(iVar3 + 0x7c) - 1U & 0xffff) + 1;
      do {
        *puVar4 = 0x200000;
        puVar4 = puVar4 + 1;
      } while (puVar4 != puVar2);
      *(undefined2 *)((int)param_1 + 0x96) = 0;
      iVar5 = ((short)param_1[0x25] + 1) * 0x10000;
      iVar3 = iVar5 >> 0x10;
      *(short *)(param_1 + 0x25) = (short)((uint)iVar5 >> 0x10);
    } while (iVar3 < *(short *)(iVar9 + 0x21c));
  }
  return iVar8;
}



/* 40ae3a64 FUN_40ae3a64 */

/* Boundary evidence: original MIPS .pdata 40ae3a64..40ae3e9b. Semantic name remains unreviewed. */

int FUN_40ae3a64(int *param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int local_30;
  uint local_2c;
  uint local_28 [3];
  
  uVar5 = param_1[0xe];
  local_30 = 0;
  local_2c = 0;
  iVar8 = *param_1;
  piVar9 = param_1 + 0x39;
  if (uVar5 == 4) {
    iVar3 = (*(code *)param_1[0x4c])(piVar9,1);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_40af774c((int)piVar9,1,local_28);
    if (iVar3 < 0) {
      return iVar3;
    }
    FUN_40ae2f48(param_1,param_2,(short)local_28[0]);
    param_1[0xe] = 0;
LAB_40ae3b08:
    iVar3 = FUN_40ae5398(*(int *)(param_2 + 0x18),(int)piVar9,local_28,&local_2c,&local_30);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_40af75e4((int)piVar9,local_28[0]);
    if (iVar3 < 0) {
      return iVar3;
    }
    if (local_2c != 0) {
      if (local_2c == 1) {
        *(undefined4 *)(iVar8 + 0x18) = 0;
        *(int *)(iVar8 + 0x14) =
             (int)(((*(int *)(param_2 + 0x24) + -1) - (uint)*(ushort *)(iVar8 + 0xd8)) * 0x10000) >>
             0x10;
        return iVar3;
      }
      iVar3 = FUN_40af75e4((int)piVar9,1);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar4 = (local_2c - 2) * 2;
      uVar1 = *(ushort *)(*(int *)(param_2 + 0x1c) + iVar4);
      uVar2 = *(ushort *)(*(int *)(param_2 + 0x20) + iVar4);
      *(int *)(iVar8 + 0x1c) = -1 - (local_30 >> 0x1f);
      *(uint *)(iVar8 + 0x14) = (uint)uVar1;
      *(uint *)(iVar8 + 0x18) = (uint)uVar2;
      return iVar3;
    }
    iVar3 = *(int *)(iVar8 + 0x40);
    if (iVar3 < 3) {
      param_1[0xe] = 5;
    }
    else {
      param_1[0xe] = 5;
      *(undefined4 *)(iVar8 + 0x1c) = 0;
    }
  }
  else {
    if (uVar5 < 5) {
      if (uVar5 != 0) {
        return 0;
      }
      goto LAB_40ae3b08;
    }
    if (uVar5 != 5) {
      if (uVar5 != 6) {
        return 0;
      }
      goto LAB_40ae3c24;
    }
    iVar3 = *(int *)(iVar8 + 0x40);
  }
  if (iVar3 < 3) {
    uVar1 = *(ushort *)(iVar8 + 0x38);
    iVar3 = (*(code *)param_1[0x4c])(piVar9,(uint)uVar1);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_40af774c((int)piVar9,(uint)uVar1,local_28);
    if (iVar3 < 0) {
      return iVar3;
    }
    *(uint *)(iVar8 + 0x18) = local_28[0];
    param_1[0xe] = 6;
  }
  else {
    iVar3 = *(int *)(iVar8 + 0x1c);
    if (iVar3 == 0) {
      iVar3 = (*(code *)param_1[0x4b])(piVar9,4,local_28);
      if (iVar3 < 0) {
        return iVar3;
      }
      *(undefined4 *)(iVar8 + 0x1c) = 4;
      *(undefined4 *)(iVar8 + 0x18) = 0;
      if ((int)local_28[0] < 0) {
        *(undefined4 *)(iVar8 + 0x18) = 0x10;
        *(undefined4 *)(iVar8 + 0x1c) = 8;
        if ((local_28[0] & 0x40000000) == 0) {
          uVar5 = 2;
        }
        else {
          uVar6 = 8;
          iVar3 = 0x10;
          uVar7 = 1;
          do {
            uVar5 = uVar7;
            uVar7 = uVar5 + 1;
            iVar3 = iVar3 + (1 << (uVar6 & 0x1f));
            uVar6 = uVar6 + 8;
            *(int *)(iVar8 + 0x18) = iVar3;
            *(uint *)(iVar8 + 0x1c) = uVar6;
          } while ((0x80000000U >> (uVar7 & 0x1f) & local_28[0]) != 0);
          uVar5 = uVar5 + 2;
        }
      }
      else {
        uVar5 = 1;
      }
      iVar3 = FUN_40af75e4((int)piVar9,uVar5);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = *(int *)(iVar8 + 0x1c);
    }
    iVar3 = (*(code *)param_1[0x4c])(piVar9,iVar3 + 1);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_40af774c((int)piVar9,*(int *)(iVar8 + 0x1c) + 1,local_28);
    if (iVar3 < 0) {
      return iVar3;
    }
    *(uint *)(iVar8 + 0x18) = (local_28[0] >> 1) + *(int *)(iVar8 + 0x18) + 1;
    *(uint *)(iVar8 + 0x1c) = (local_28[0] & 1) - 1;
    param_1[0xe] = 6;
  }
LAB_40ae3c24:
  if (*(int *)(iVar8 + 0x40) < 3) {
    uVar5 = *(int *)(iVar8 + 0xf4) + 1U & 0xffff;
    iVar3 = (*(code *)param_1[0x4c])(piVar9,uVar5,piVar9);
    if ((-1 < iVar3) && (iVar3 = FUN_40af774c((int)piVar9,uVar5,local_28), -1 < iVar3)) {
      *(uint *)(iVar8 + 0x14) =
           (int)(short)((ushort)(0xffffffff >> (~*(uint *)(*param_1 + 0xf4) & 0x1f)) &
                       (ushort)local_28[0]) >> 1 & 0x7fffffff;
      *(uint *)(iVar8 + 0x1c) = (local_28[0] & 1) - 1;
      param_1[0xe] = 0;
    }
  }
  else {
    iVar3 = FUN_40ae132c();
    if (-1 < iVar3) {
      *(int *)(iVar8 + 0x14) = (int)(short)local_28[0];
      if ((short)local_28[0] == 0) {
        *(int *)(iVar8 + 0x18) = *(int *)(iVar8 + 0x18) + (int)*(short *)((int)param_1 + 0x136);
      }
      param_1[0xe] = 0;
      return iVar3;
    }
  }
  return iVar3;
}



/* 40ae3e9c FUN_40ae3e9c */

/* Boundary evidence: original MIPS .pdata 40ae3e9c..40ae3fd7. Semantic name remains unreviewed. */

int FUN_40ae3e9c(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *param_2;
  iVar6 = *param_1;
  iVar5 = 0;
  *(ushort *)(param_1 + 0x4d) = ((ushort)LZCOUNT(param_4 + -1) ^ 0x1f) + 1;
  iVar2 = (int)*(short *)(iVar6 + 0xd8);
  while ((iVar2 < param_4 && (iVar5 = FUN_40ae3a64(param_1,(int)param_2), -1 < iVar5))) {
    iVar2 = (int)*(short *)(iVar6 + 0xd8) + *(int *)(iVar6 + 0x14);
    iVar1 = iVar2 * 0x10000 >> 0x10;
    iVar4 = iVar1 + 1;
    iVar3 = (*(uint *)(iVar6 + 0x1c) ^ *(uint *)(iVar6 + 0x18)) - *(uint *)(iVar6 + 0x1c);
    *(int *)(iVar6 + 0x18) = iVar3;
    if (param_4 <= iVar2) {
      return -0x7ffbfffe;
    }
    iVar2 = iVar4 * 0x10000 >> 0x10;
    *(short *)(iVar6 + 0xd8) = (short)iVar4;
    *(int *)(iVar7 + iVar1 * 4) = iVar3;
    param_1[0xe] = 0;
  }
  return iVar5;
}



/* 40ae3fd8 FUN_40ae3fd8 */

/* Boundary evidence: original MIPS .pdata 40ae3fd8..40ae41c7. Semantic name remains unreviewed. */

int FUN_40ae3fd8(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar10 = *param_1;
  iVar3 = (int)(short)param_1[0x25];
  iVar12 = 0;
  iVar1 = iVar12;
  if (iVar3 < *(short *)(iVar10 + 0x21c)) {
    do {
      piVar9 = (int *)(*(short *)(*(int *)(iVar10 + 0x220) + iVar3 * 2) * 0x594 +
                      *(int *)(iVar10 + 0x134));
      iVar1 = iVar12;
      if (piVar9[10] != 0) {
        iVar8 = piVar9[9];
        iVar11 = *piVar9;
        iVar4 = *param_1;
        *(ushort *)(param_1 + 0x4d) = ((ushort)LZCOUNT(iVar8 + -1) ^ 0x1f) + 1;
        iVar3 = (int)*(short *)(iVar4 + 0xd8);
        while (iVar3 < iVar8) {
          iVar1 = FUN_40ae3a64(param_1,(int)piVar9);
          if (iVar1 < 0) {
            return iVar1;
          }
          iVar5 = (int)*(short *)(iVar4 + 0xd8) + *(int *)(iVar4 + 0x14);
          iVar3 = iVar5 * 0x10000 >> 0x10;
          iVar7 = iVar3 + 1;
          iVar6 = (*(uint *)(iVar4 + 0x1c) ^ *(uint *)(iVar4 + 0x18)) - *(uint *)(iVar4 + 0x1c);
          *(int *)(iVar4 + 0x18) = iVar6;
          if (iVar8 <= iVar5) {
            iVar1 = -0x7ffbfffe;
            break;
          }
          *(short *)(iVar4 + 0xd8) = (short)iVar7;
          *(int *)(iVar11 + iVar3 * 4) = iVar6;
          param_1[0xe] = 0;
          iVar3 = iVar7 * 0x10000 >> 0x10;
        }
      }
      if (iVar1 < 0) {
        return iVar1;
      }
      if (*(int *)(iVar10 + 0x40) == 1) {
        iVar3 = *param_3;
        uVar2 = FUN_40af7894((int)(param_1 + 0x39));
        *param_3 = (uVar2 & 7) + iVar3;
        FUN_40af78f4((int)(param_1 + 0x39));
        *(undefined2 *)(iVar10 + 0xd8) = 0;
      }
      else {
        *(undefined2 *)(iVar10 + 0xd8) = 0;
      }
      FUN_40aeee14(param_1);
      iVar4 = ((short)param_1[0x25] + 1) * 0x10000;
      iVar3 = iVar4 >> 0x10;
      *(short *)(param_1 + 0x25) = (short)((uint)iVar4 >> 0x10);
    } while (iVar3 < *(short *)(iVar10 + 0x21c));
  }
  return iVar1;
}



/* 40ae41c8 FUN_40ae41c8 */

/* Boundary evidence: original MIPS .pdata 40ae41c8..40ae466b. Semantic name remains unreviewed. */

void FUN_40ae41c8(int *param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  int iVar17;
  uint *puVar18;
  uint *puVar19;
  uint uVar20;
  undefined8 uVar21;
  uint local_120;
  uint local_11c;
  uint local_118 [50];
  uint local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined1 *local_3c;
  uint local_38;
  uint *local_30;
  
  iVar12 = *param_1;
  uVar6 = (uint)*(ushort *)(iVar12 + 0x58);
  if (uVar6 == 0) {
    return;
  }
  local_48 = 0;
  local_40 = 0;
  local_30 = local_118;
LAB_40ae4220:
  iVar13 = *(int *)(iVar12 + 0x134) + local_48;
  if (*(int *)(iVar13 + 0x28) != 0) {
    iVar10 = *(int *)(iVar12 + 0x180);
    iVar11 = *(int *)(iVar12 + 0x128);
    uVar7 = *(uint *)(iVar11 + iVar10 * 4);
    iVar9 = *(int *)(iVar12 + 0x108);
    uVar6 = *(uint *)(iVar12 + 0x184);
    if ((int)*(uint *)(iVar12 + 0x184) <= (int)uVar7) {
      uVar6 = uVar7;
    }
    uVar7 = (uint)((int)uVar6 < iVar9);
    local_3c = *(undefined1 **)(iVar13 + 0xc);
    local_44 = *(int *)(iVar13 + 0x10);
    iVar13 = *(int *)(iVar13 + 0x38);
    if (uVar7 != 0) {
      iVar17 = (iVar10 + 1) * 4;
      uVar20 = 0;
      iVar16 = iVar10 + 1;
      do {
        iVar11 = *(int *)(iVar11 + iVar16 * 4);
        if (local_3c[iVar10] == '\x01') {
          if (iVar11 <= iVar9) {
            iVar9 = iVar11;
          }
          iVar9 = iVar9 - uVar6;
          if (iVar9 < 1) {
            uVar6 = 0;
            uVar14 = 0;
          }
          else {
            puVar15 = (uint *)(iVar13 + uVar6 * 4);
            uVar14 = 0;
            uVar5 = 0;
            do {
              iVar9 = iVar9 + -1;
              lVar1 = (ulonglong)*puVar15 * (ulonglong)*puVar15;
              puVar15 = puVar15 + 1;
              uVar6 = uVar5 + (int)lVar1;
              uVar7 = uVar14 + (int)((ulonglong)lVar1 >> 0x20);
              uVar14 = (uVar6 < uVar5) + uVar7;
              uVar5 = uVar6;
            } while (0 < iVar9);
          }
          FUN_40aeab90((int *)&local_50,uVar7,uVar6,uVar14,0x2a);
          local_11c = local_4c;
          local_120 = local_50;
          local_11c = FUN_40aff9dc();
          FUN_40aeab1c((int *)&local_120);
          iVar12 = *param_1;
          iVar11 = *(int *)(iVar12 + 0x128);
          local_118[uVar20 * 2 + 1] = local_11c;
          local_118[uVar20 * 2] = local_120;
          uVar20 = uVar20 + 1 & 0xff;
          uVar7 = *(uint *)(iVar12 + 0x184);
          iVar9 = *(int *)(iVar12 + 0x108);
          uVar6 = uVar7;
          if ((int)uVar7 <= (int)*(uint *)(iVar11 + iVar17)) {
            uVar6 = *(uint *)(iVar11 + iVar17);
          }
          if (iVar9 <= (int)uVar6) goto LAB_40ae43e4;
        }
        else {
          iVar11 = *(int *)(iVar12 + 0x128);
          uVar7 = *(uint *)(iVar12 + 0x184);
          iVar9 = *(int *)(iVar12 + 0x108);
          uVar6 = uVar7;
          if ((int)uVar7 <= (int)*(uint *)(iVar11 + iVar17)) {
            uVar6 = *(uint *)(iVar11 + iVar17);
          }
          if (iVar9 <= (int)uVar6) goto LAB_40ae43e4;
        }
        iVar17 = iVar17 + 4;
        iVar10 = iVar16;
        iVar16 = iVar16 + 1;
      } while( true );
    }
    uVar20 = 0;
    goto LAB_40ae45b8;
  }
  goto LAB_40ae45d0;
LAB_40ae43e4:
  iVar12 = uVar20 - 1;
  if (0 < iVar12) {
    uVar7 = local_118[iVar12 * 2];
    puVar19 = local_30 + -(uVar20 * -2 + 1);
    uVar6 = local_118[iVar12 * 2 + 1];
    puVar15 = local_118 + 1;
    puVar18 = (uint *)(local_44 + 4);
    local_38 = ~uVar7;
    do {
      while (uVar14 = puVar15[-1], uVar6 != 0) {
        uVar21 = FUN_40aff9f8();
        uVar4 = (uint)((ulonglong)uVar21 >> 0x20);
        uVar2 = (uint)uVar21;
        uVar5 = uVar4;
        if (uVar4 == 0) {
          uVar5 = uVar2;
        }
        iVar12 = 0x20;
        iVar13 = 0x21;
        if (uVar4 != 0) {
          iVar12 = 0;
        }
        if (uVar4 != 0) {
          iVar13 = 1;
        }
        if ((uVar5 & 0xf0000000) == 0) {
          do {
            iVar13 = iVar12;
            uVar5 = uVar5 << 4;
            iVar12 = iVar13 + 4;
          } while ((uVar5 & 0xf0000000) == 0);
          iVar13 = iVar13 + 5;
        }
        if (-1 < (int)uVar5) {
          do {
            iVar13 = iVar12;
            uVar5 = uVar5 << 1;
            iVar12 = iVar13 + 1;
          } while (-1 < (int)uVar5);
          iVar13 = iVar13 + 2;
        }
        if (iVar13 < 0x21) {
          uVar8 = 0x20 - iVar13;
          uVar5 = uVar4 >> (uVar8 & 0x1f);
          if ((uVar8 & 0x20) == 0) {
            uVar5 = (uVar4 << 1) << (~uVar8 & 0x1f) | uVar2 >> (uVar8 & 0x1f);
          }
        }
        else {
          uVar5 = uVar2 << (iVar13 - 0x20U & 0x1f);
          if ((iVar13 - 0x20U & 0x20) != 0) {
            uVar5 = 0;
          }
        }
        iVar12 = uVar14 - uVar7;
        local_11c = (&DAT_40b10a78)[uVar5 >> 0x18] +
                    (int)((ulonglong)
                          (uint)((&DAT_40b10a78)[(uVar5 >> 0x18) + 1] -
                                (&DAT_40b10a78)[uVar5 >> 0x18]) * (ulonglong)(uVar5 << 8) >> 0x20);
        if ((iVar12 + iVar13 & 1U) != 0) {
          local_11c = (uint)((ulonglong)local_11c * 0xb504f333 >> 0x20);
          iVar12 = local_38 + uVar14;
        }
        local_120 = (iVar12 >> 1) + -3 + iVar13;
        local_11c = local_11c >> 1;
        FUN_40aeab1c((int *)&local_120);
        puVar15 = puVar15 + 2;
        *puVar18 = local_11c;
        puVar18[-1] = local_120;
        puVar18 = puVar18 + 2;
        if (puVar15 == puVar19) goto LAB_40ae4594;
      }
      puVar15 = puVar15 + 2;
      local_11c = 0x7fffffff;
      local_120 = 0;
      *puVar18 = 0x7fffffff;
      puVar18[-1] = 0;
      puVar18 = puVar18 + 2;
    } while (puVar15 != puVar19);
  }
LAB_40ae4594:
  if (uVar20 != 0) {
    puVar3 = (undefined4 *)(local_44 + (uVar20 - 1) * 8);
    *puVar3 = 0x1e;
    puVar3[1] = 0x40000000;
  }
LAB_40ae45b8:
  *local_3c = (char)uVar20;
  iVar12 = *param_1;
  uVar6 = (uint)*(ushort *)(iVar12 + 0x58);
LAB_40ae45d0:
  local_40 = local_40 + 1;
  local_48 = local_48 + 0x594;
  if ((int)uVar6 <= local_40) {
    return;
  }
  goto LAB_40ae4220;
}



/* 40ae466c FUN_40ae466c */

/* Boundary evidence: original MIPS .pdata 40ae466c..40ae47af. Semantic name remains unreviewed. */

int FUN_40ae466c(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = 0;
  if (param_2[10] != 0) {
    iVar7 = param_2[9];
    iVar8 = *param_2;
    iVar6 = *param_1;
    *(ushort *)(param_1 + 0x4d) = ((ushort)LZCOUNT(iVar7 + -1) ^ 0x1f) + 1;
    iVar2 = (int)*(short *)(iVar6 + 0xd8);
    while ((iVar2 < iVar7 && (iVar5 = FUN_40ae3a64(param_1,(int)param_2), -1 < iVar5))) {
      iVar2 = (int)*(short *)(iVar6 + 0xd8) + *(int *)(iVar6 + 0x14);
      iVar1 = iVar2 * 0x10000 >> 0x10;
      iVar4 = iVar1 + 1;
      iVar3 = (*(uint *)(iVar6 + 0x1c) ^ *(uint *)(iVar6 + 0x18)) - *(uint *)(iVar6 + 0x1c);
      *(int *)(iVar6 + 0x18) = iVar3;
      if (iVar7 <= iVar2) {
        return -0x7ffbfffe;
      }
      iVar2 = iVar4 * 0x10000 >> 0x10;
      *(short *)(iVar6 + 0xd8) = (short)iVar4;
      *(int *)(iVar8 + iVar1 * 4) = iVar3;
      param_1[0xe] = 0;
    }
  }
  return iVar5;
}



/* 40ae47b0 FUN_40ae47b0 */

/* Boundary evidence: original MIPS .pdata 40ae47b0..40ae4f3b. Semantic name remains unreviewed. */

void FUN_40ae47b0(int param_1,uint param_2)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int *piVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int *piVar25;
  int iVar26;
  int *piVar27;
  int iVar28;
  int iVar29;
  int local_50;
  int *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  iVar23 = 1 << (param_2 & 0x1f);
  iVar29 = iVar23 * 2;
  iVar28 = iVar29 + -7;
  if (2 < iVar23) {
    iVar24 = iVar23 >> 1;
    iVar20 = param_1 + (iVar23 + 1) * 4;
    iVar26 = 0;
    iVar16 = 0;
    iVar17 = param_1;
    while( true ) {
      puVar4 = (undefined4 *)(param_1 + (iVar16 + iVar23) * 4);
      uVar11 = *(undefined4 *)(iVar17 + 8);
      *(undefined4 *)(iVar17 + 8) = *puVar4;
      *puVar4 = uVar11;
      uVar11 = *(undefined4 *)(iVar17 + 0xc);
      *(undefined4 *)(iVar17 + 0xc) = puVar4[1];
      puVar4[1] = uVar11;
      iVar5 = iVar24;
      if (iVar24 <= iVar16) {
        iVar16 = iVar16 - iVar24;
        do {
          iVar5 = iVar5 >> 1;
          bVar1 = iVar5 <= iVar16;
          iVar16 = iVar16 - iVar5;
        } while (bVar1);
        iVar16 = iVar16 + iVar5;
      }
      iVar26 = iVar26 + 4;
      iVar16 = iVar16 + iVar5;
      if (iVar23 <= iVar26) break;
      if (iVar26 < iVar16) {
        puVar4 = (undefined4 *)(param_1 + iVar16 * 4);
        uVar11 = *(undefined4 *)(iVar17 + 0x10);
        *(undefined4 *)(iVar17 + 0x10) = *puVar4;
        *puVar4 = uVar11;
        uVar11 = *(undefined4 *)(iVar17 + 0x14);
        *(undefined4 *)(iVar17 + 0x14) = puVar4[1];
        puVar8 = puVar4 + iVar23 + 2;
        puVar4[1] = uVar11;
        uVar11 = *(undefined4 *)(iVar20 + 0x14);
        *(undefined4 *)(iVar20 + 0x14) = *puVar8;
        *puVar8 = uVar11;
        uVar11 = *(undefined4 *)(iVar20 + 0x18);
        *(undefined4 *)(iVar20 + 0x18) = puVar8[1];
        puVar8[1] = uVar11;
      }
      iVar17 = iVar17 + 0x10;
      iVar20 = iVar20 + 0x10;
    }
  }
  iVar23 = 0;
  if (0 < iVar29) {
    iVar17 = 8;
    do {
      piVar21 = (int *)(param_1 + iVar23 * 4);
      iVar23 = iVar17 + iVar23;
      do {
        iVar20 = *piVar21;
        iVar16 = piVar21[1];
        iVar23 = iVar23 + iVar17;
        *piVar21 = piVar21[2] + iVar20;
        piVar21[2] = iVar20 - piVar21[2];
        piVar21[1] = piVar21[3] + iVar16;
        piVar21[3] = iVar16 - piVar21[3];
        piVar21 = piVar21 + iVar17;
      } while (iVar23 - iVar17 < iVar29);
      iVar23 = iVar17 * 2 + -4;
      iVar17 = iVar17 << 2;
    } while (iVar23 < iVar29);
  }
  if (1 < (int)param_2) {
    local_50 = 2;
    local_34 = 0;
    iVar24 = 0;
    iVar20 = 0;
    local_38 = 0;
    iVar16 = 0;
    iVar17 = 0;
    local_4c = &DAT_40b13500;
    iVar23 = 4;
    do {
      iVar5 = iVar23 >> 1;
      iVar26 = iVar23 * 2;
      if (iVar26 < iVar29) {
        iVar14 = iVar26;
        iVar10 = iVar23 << 3;
        do {
          piVar21 = (int *)(param_1 + iVar14 * 4);
          iVar14 = iVar10 + iVar14;
          do {
            if (0 < iVar26) {
              iVar12 = 0;
              piVar9 = piVar21;
              do {
                iVar12 = iVar12 + 1;
                *piVar9 = *piVar9 >> 1;
                piVar9 = piVar9 + 1;
              } while (iVar12 < iVar26);
            }
            iVar14 = iVar14 + iVar10;
            piVar21 = piVar21 + iVar10;
          } while (iVar14 - iVar10 < iVar29);
          iVar14 = iVar10 * 2 + iVar23 * -2;
          iVar10 = iVar10 * 4;
        } while (iVar14 < iVar29);
      }
      if (0 < iVar29) {
        iVar10 = 0;
        iVar14 = iVar23 << 2;
        do {
          if (iVar10 < iVar28) {
            piVar25 = (int *)(param_1 + iVar10 * 4);
            piVar9 = piVar25 + iVar5;
            piVar21 = piVar9 + iVar5;
            iVar10 = iVar10 + iVar14;
            piVar27 = piVar21 + iVar5;
            do {
              iVar15 = *piVar21;
              iVar18 = *piVar27;
              iVar12 = *piVar25;
              iVar6 = (iVar18 >> 1) + (iVar15 >> 1);
              iVar13 = piVar21[1];
              iVar7 = piVar27[1];
              *piVar21 = (iVar12 >> 1) - iVar6;
              *piVar25 = iVar6 + (iVar12 >> 1);
              iVar12 = *piVar9;
              iVar6 = (iVar13 >> 1) - (iVar7 >> 1);
              *piVar27 = (iVar12 >> 1) - iVar6;
              *piVar9 = iVar6 + (iVar12 >> 1);
              iVar12 = piVar25[1];
              iVar6 = (iVar7 >> 1) + (iVar13 >> 1);
              piVar21[1] = (iVar12 >> 1) - iVar6;
              piVar25[1] = iVar6 + (iVar12 >> 1);
              iVar12 = piVar9[1];
              iVar10 = iVar10 + iVar14;
              iVar6 = (iVar15 >> 1) - (iVar18 >> 1);
              piVar27[1] = (iVar12 >> 1) + iVar6;
              piVar25 = piVar25 + iVar14;
              piVar9[1] = (iVar12 >> 1) - iVar6;
              piVar21 = piVar21 + iVar14;
              piVar9 = piVar9 + iVar14;
              piVar27 = piVar27 + iVar14;
            } while (iVar10 - iVar14 < iVar28);
          }
          iVar10 = (iVar14 - iVar23) * 2;
          iVar14 = iVar14 << 2;
        } while (iVar10 < iVar29);
      }
      if (1 < iVar23 >> 2) {
        iVar14 = *local_4c;
        if (iVar14 != 0) {
          local_38 = local_4c[3];
          iVar24 = local_4c[1];
          iVar20 = local_4c[2];
          iVar16 = local_4c[4];
          iVar17 = local_4c[5];
          local_4c = local_4c + 6;
          local_34 = iVar14;
        }
        iVar14 = -iVar23;
        iVar13 = 1;
        local_3c = 0x3fffffff;
        local_40 = 0;
        local_44 = 0x3fffffff;
        local_48 = 0;
        iVar10 = iVar17;
        iVar12 = iVar16;
        iVar6 = iVar20;
        iVar7 = iVar24;
        while( true ) {
          iVar24 = iVar7;
          iVar20 = iVar6;
          iVar16 = iVar12;
          iVar17 = iVar10;
          iVar14 = iVar14 + 1;
          iVar10 = iVar23 << 2;
          for (iVar12 = iVar13 << 1; iVar12 < iVar29; iVar12 = iVar12 * 2) {
            if (iVar12 < iVar28) {
              piVar25 = (int *)(param_1 + iVar12 * 4);
              piVar9 = piVar25 + iVar5;
              piVar21 = piVar9 + iVar5;
              iVar12 = iVar10 + iVar12;
              piVar27 = piVar21 + iVar5;
              do {
                lVar2 = (longlong)iVar24 * (longlong)(*piVar21 >> 1);
                lVar3 = (longlong)iVar20 * (longlong)(piVar21[1] >> 1);
                iVar22 = ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e) +
                         ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e);
                lVar2 = (longlong)iVar24 * (longlong)(piVar21[1] >> 1);
                lVar3 = (longlong)iVar20 * (longlong)(*piVar21 >> 1);
                iVar19 = ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e) -
                         ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e);
                lVar2 = (longlong)iVar16 * (longlong)(*piVar27 >> 1);
                lVar3 = (longlong)iVar17 * (longlong)(piVar27[1] >> 1);
                iVar18 = ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e) +
                         ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e);
                lVar2 = (longlong)iVar16 * (longlong)(piVar27[1] >> 1);
                lVar3 = (longlong)iVar17 * (longlong)(*piVar27 >> 1);
                iVar7 = *piVar25;
                iVar6 = iVar18 + iVar22;
                *piVar21 = (iVar7 >> 1) - iVar6;
                *piVar25 = (iVar7 >> 1) + iVar6;
                iVar6 = *piVar9;
                iVar15 = ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e) -
                         ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e);
                iVar7 = iVar19 - iVar15;
                *piVar27 = (iVar6 >> 1) - iVar7;
                *piVar9 = (iVar6 >> 1) + iVar7;
                iVar6 = piVar25[1];
                iVar15 = iVar15 + iVar19;
                piVar21[1] = (iVar6 >> 1) - iVar15;
                piVar25[1] = (iVar6 >> 1) + iVar15;
                iVar6 = piVar9[1];
                iVar12 = iVar12 + iVar10;
                iVar22 = iVar22 - iVar18;
                piVar27[1] = (iVar6 >> 1) + iVar22;
                piVar25 = piVar25 + iVar10;
                piVar9[1] = (iVar6 >> 1) - iVar22;
                piVar21 = piVar21 + iVar10;
                piVar9 = piVar9 + iVar10;
                piVar27 = piVar27 + iVar10;
              } while (iVar12 - iVar10 < iVar28);
            }
            iVar12 = iVar14 + iVar10;
            iVar10 = iVar10 << 2;
          }
          iVar13 = iVar13 + 1;
          if (iVar23 >> 2 <= iVar13) break;
          iVar10 = ((int)((ulonglong)((longlong)local_38 * (longlong)iVar16) >> 0x20) << 2 |
                   (uint)((longlong)local_38 * (longlong)iVar16) >> 0x1e) + local_48;
          iVar12 = local_44 -
                   ((int)((ulonglong)((longlong)local_38 * (longlong)iVar17) >> 0x20) << 2 |
                   (uint)((longlong)local_38 * (longlong)iVar17) >> 0x1e);
          iVar6 = ((int)((ulonglong)((longlong)local_34 * (longlong)iVar24) >> 0x20) << 2 |
                  (uint)((longlong)local_34 * (longlong)iVar24) >> 0x1e) + local_40;
          iVar7 = local_3c -
                  ((int)((ulonglong)((longlong)local_34 * (longlong)iVar20) >> 0x20) << 2 |
                  (uint)((longlong)local_34 * (longlong)iVar20) >> 0x1e);
          local_48 = iVar17;
          local_44 = iVar16;
          local_40 = iVar20;
          local_3c = iVar24;
        }
      }
      local_50 = local_50 + 1;
      iVar23 = iVar26;
    } while (local_50 <= (int)param_2);
  }
  return;
}



/* 40ae4f3c FUN_40ae4f3c */

/* Boundary evidence: original MIPS .pdata 40ae4f3c..40ae5397. Semantic name remains unreviewed. */

undefined4 FUN_40ae4f3c(int *param_1,int param_2,undefined4 param_3,int param_4,undefined *param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  iVar3 = 1;
  do {
    bVar1 = iVar3 != 0x1d;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  uVar15 = 0;
  if (1 < param_4) {
    uVar7 = 1;
    do {
      uVar15 = uVar7;
      uVar7 = uVar15 + 1;
    } while (1 < param_4 >> (uVar15 & 0x1f));
  }
  if (param_2 < 2) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar2 = 1;
    do {
      uVar7 = uVar2;
      uVar2 = uVar7 + 1;
    } while (1 < param_2 >> (uVar7 & 0x1f));
    uVar7 = uVar7 - 1;
  }
  piVar5 = (int *)(&PTR_DAT_40b10fb4)[param_4 >> 7];
  iVar4 = (param_4 >> (uVar7 & 0x1f)) << 0x1d;
  iVar16 = param_4 / 4;
  iVar3 = -piVar5[10];
  iVar18 = piVar5[4];
  iVar17 = piVar5[5];
  if (iVar16 < 1) {
    (*(code *)param_5)(param_1,uVar15 - 1,0);
  }
  else {
    piVar10 = param_1 + param_4 + -1;
    piVar9 = param_1;
    iVar6 = (int)((ulonglong)((longlong)iVar4 * (longlong)*piVar5) >> 0x20) * -2;
    iVar8 = (int)((ulonglong)((longlong)iVar4 * (longlong)piVar5[1]) >> 0x20) << 1;
    iVar11 = iVar16;
    iVar13 = (int)((ulonglong)((longlong)iVar4 * (longlong)piVar5[3]) >> 0x20) << 1;
    iVar4 = (int)((ulonglong)((longlong)iVar4 * (longlong)piVar5[2]) >> 0x20) << 1;
    do {
      iVar12 = iVar8;
      iVar14 = iVar6;
      iVar6 = *piVar10;
      *piVar10 = piVar9[1];
      iVar8 = *piVar9;
      *piVar9 = ((int)((ulonglong)((longlong)iVar12 * (longlong)iVar8) >> 0x20) -
                (int)((ulonglong)((longlong)iVar14 * (longlong)iVar6) >> 0x20)) * 2;
      piVar9[1] = ((int)((ulonglong)((longlong)iVar12 * (longlong)iVar6) >> 0x20) +
                  (int)((ulonglong)((longlong)iVar14 * (longlong)iVar8) >> 0x20)) * 2;
      iVar8 = iVar13 + (int)((ulonglong)((longlong)iVar3 * (longlong)iVar14) >> 0x20) * -2;
      iVar6 = (int)((ulonglong)((longlong)iVar3 * (longlong)iVar12) >> 0x20) * 2 + iVar4;
      iVar11 = iVar11 + -1;
      piVar9 = piVar9 + 2;
      piVar10 = piVar10 + -2;
      iVar13 = iVar12;
      iVar4 = iVar14;
    } while (0 < iVar11);
    piVar5 = param_1 + iVar16 * 2;
    iVar4 = iVar16;
    do {
      iVar13 = iVar8;
      iVar11 = iVar6;
      iVar6 = *piVar5;
      *piVar5 = ((int)((ulonglong)((longlong)iVar13 * (longlong)iVar6) >> 0x20) -
                (int)((ulonglong)((longlong)iVar11 * (longlong)piVar5[1]) >> 0x20)) * 2;
      piVar5[1] = ((int)((ulonglong)((longlong)iVar13 * (longlong)piVar5[1]) >> 0x20) +
                  (int)((ulonglong)((longlong)iVar11 * (longlong)iVar6) >> 0x20)) * 2;
      iVar4 = iVar4 + -1;
      piVar5 = piVar5 + 2;
      iVar6 = (int)((ulonglong)((longlong)iVar3 * (longlong)iVar13) >> 0x20) * 2 + iVar14;
      iVar8 = iVar12 + (int)((ulonglong)((longlong)iVar3 * (longlong)iVar11) >> 0x20) * -2;
      iVar12 = iVar13;
      iVar14 = iVar11;
    } while (0 < iVar4);
    (*(code *)param_5)(param_1,uVar15 - 1,0);
    piVar5 = param_1 + param_4 + -2;
    iVar4 = 0;
    iVar6 = 0x7fffffff;
    do {
      iVar12 = iVar6;
      iVar13 = iVar4;
      iVar4 = *param_1;
      iVar8 = *piVar5;
      iVar11 = piVar5[1];
      *param_1 = ((int)((ulonglong)((longlong)iVar12 * (longlong)iVar4) >> 0x20) -
                 (int)((ulonglong)((longlong)iVar13 * (longlong)param_1[1]) >> 0x20)) * 2;
      piVar5[1] = ((int)((ulonglong)((longlong)-iVar13 * (longlong)iVar4) >> 0x20) -
                  (int)((ulonglong)((longlong)iVar12 * (longlong)param_1[1]) >> 0x20)) * 2;
      iVar6 = iVar17 + (int)((ulonglong)((longlong)iVar3 * (longlong)iVar13) >> 0x20) * -2;
      iVar4 = (int)((ulonglong)((longlong)iVar3 * (longlong)iVar12) >> 0x20) * 2 + iVar18;
      param_1[1] = ((int)((ulonglong)((longlong)iVar6 * (longlong)iVar8) >> 0x20) +
                   (int)((ulonglong)((longlong)iVar4 * (longlong)iVar11) >> 0x20)) * 2;
      iVar16 = iVar16 + -1;
      *piVar5 = ((int)((ulonglong)((longlong)-iVar4 * (longlong)iVar8) >> 0x20) +
                (int)((ulonglong)((longlong)iVar6 * (longlong)iVar11) >> 0x20)) * 2;
      param_1 = param_1 + 2;
      piVar5 = piVar5 + -2;
      iVar17 = iVar12;
      iVar18 = iVar13;
    } while (0 < iVar16);
  }
  return 0;
}



/* 40ae5398 FUN_40ae5398 */

/* Boundary evidence: original MIPS .pdata 40ae5398..40ae560f. Semantic name remains unreviewed. */

int FUN_40ae5398(int param_1,int param_2,uint *param_3,uint *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  uint local_20 [3];
  
  iVar1 = (**(code **)(param_2 + 0x48))(param_2,0x17,local_20);
  if (-1 < iVar1) {
    puVar3 = (ushort *)(param_1 + (local_20[0] >> 0x1e) * 2);
    uVar2 = (uint)*puVar3;
    if ((*puVar3 & 0x8000) == 0) {
      puVar3 = (ushort *)((int)puVar3 + (local_20[0] >> 0x1b & 6) + uVar2 * 2);
      uVar2 = (uint)*puVar3;
      if ((*puVar3 & 0x8000) == 0) {
        puVar3 = (ushort *)((int)puVar3 + (local_20[0] >> 0x19 & 6) + uVar2 * 2);
        uVar2 = (uint)*puVar3;
        if ((*puVar3 & 0x8000) == 0) {
          puVar3 = (ushort *)((int)puVar3 + (local_20[0] >> 0x17 & 6) + uVar2 * 2);
          uVar2 = (uint)*puVar3;
          if ((*puVar3 & 0x8000) == 0) {
            puVar3 = (ushort *)((int)puVar3 + (local_20[0] >> 0x15 & 6) + uVar2 * 2);
            uVar2 = (uint)*puVar3;
            if ((*puVar3 & 0x8000) == 0) {
              puVar3 = (ushort *)((int)puVar3 + (local_20[0] >> 0x13 & 6) + uVar2 * 2);
              uVar2 = (uint)*puVar3;
              if ((*puVar3 & 0x8000) == 0) {
                puVar3 = (ushort *)((int)puVar3 + (local_20[0] >> 0x11 & 6) + uVar2 * 2);
                uVar2 = (uint)*puVar3;
                if ((*puVar3 & 0x8000) == 0) {
                  puVar3 = (ushort *)((int)puVar3 + (local_20[0] >> 0xf & 6) + uVar2 * 2);
                  uVar2 = (uint)*puVar3;
                  if ((*puVar3 & 0x8000) == 0) {
                    puVar3 = puVar3 + uVar2 + ((local_20[0] & 0xffff) >> 0xf);
                    uVar2 = (uint)*puVar3;
                    if ((*puVar3 & 0x8000) == 0) {
                      puVar3 = (ushort *)
                               ((int)puVar3 + ((local_20[0] & 0xffff) >> 0xd & 2) + uVar2 * 2);
                      uVar2 = (uint)*puVar3;
                      if ((*puVar3 & 0x8000) == 0) {
                        puVar3 = (ushort *)
                                 ((int)puVar3 + ((local_20[0] & 0xffff) >> 0xc & 2) + uVar2 * 2);
                        uVar2 = (uint)*puVar3;
                        if ((*puVar3 & 0x8000) == 0) {
                          puVar3 = (ushort *)
                                   ((int)puVar3 + ((local_20[0] & 0xffff) >> 0xb & 2) + uVar2 * 2);
                          uVar2 = (uint)*puVar3;
                          if ((*puVar3 & 0x8000) == 0) {
                            puVar3 = (ushort *)
                                     ((int)puVar3 + ((local_20[0] & 0xffff) >> 10 & 2) + uVar2 * 2);
                            uVar2 = (uint)*puVar3;
                            if ((*puVar3 & 0x8000) == 0) {
                              puVar3 = (ushort *)
                                       ((int)puVar3 + ((local_20[0] & 0xffff) >> 9 & 2) + uVar2 * 2)
                              ;
                              uVar2 = (uint)*puVar3;
                              if ((*puVar3 & 0x8000) == 0) {
                                puVar3 = puVar3 + uVar2;
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
          }
        }
      }
    }
    *param_3 = uVar2 >> 10 & 0x1f;
    *param_4 = uVar2 & 0x3ff;
    if (0x3fb < (uVar2 & 0x3ff)) {
      *param_4 = (uint)puVar3[(uVar2 & 3) + 1];
    }
    if (param_5 != (int *)0x0) {
      *param_5 = local_20[0] << (*param_3 & 0x1f);
    }
  }
  return iVar1;
}



/* 40ae56d0 FUN_40ae56d0 */

undefined4 FUN_40ae56d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = iVar1 >> 1;
  *(undefined4 *)(param_1 + 0x2c) = 1;
  *(int *)(param_1 + 0x17c) = iVar2;
  if ((*(int *)(param_1 + 0x40) < 3) && (iVar1 < 0xbb81)) {
    if (iVar1 < 0xac44) {
      if (iVar1 < 0x5622) {
        if (15999 < iVar1) {
          if (*(int *)(param_1 + 0x30) < 0x201) {
            *(int *)(param_1 + 0x17c) = iVar2 * 0x2666 >> 0xf;
            return 0;
          }
          *(undefined4 *)(param_1 + 0x188) = 3;
          *(int *)(param_1 + 0x17c) = iVar1 >> 2;
          return 0;
        }
        if (0x2b10 < iVar1) {
          *(int *)(param_1 + 0x17c) = iVar2 * 0x5999 >> 0xf;
          if (*(int *)(param_1 + 0x30) < 0x399) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0x188) = 3;
          return 0;
        }
        if (iVar1 < 8000) {
          if (0x332 < *(int *)(param_1 + 0x30)) {
            *(int *)(param_1 + 0x17c) = iVar2 * 0x6000 >> 0xf;
            return 0;
          }
          if (0x265 < *(int *)(param_1 + 0x30)) goto LAB_40ae5810;
        }
        else if (0x280 < *(int *)(param_1 + 0x30)) {
          if (*(int *)(param_1 + 0x30) < 0x301) {
            *(int *)(param_1 + 0x17c) = iVar2 * 0x5333 >> 0xf;
            return 0;
          }
          goto LAB_40ae5760;
        }
        *(int *)(param_1 + 0x17c) = iVar1 >> 2;
        return 0;
      }
      if (*(int *)(param_1 + 0x34) < 0x4a3) {
        if (0x2e0 < *(int *)(param_1 + 0x34)) {
          *(int *)(param_1 + 0x17c) = iVar2 * 0x5999 >> 0xf;
          return 0;
        }
LAB_40ae5810:
        *(int *)(param_1 + 0x17c) = iVar2 * 0x4ccc >> 0xf;
        return 0;
      }
    }
    else if (*(int *)(param_1 + 0x34) < 0x270) {
      *(int *)(param_1 + 0x17c) = iVar2 * 0x3333 >> 0xf;
      return 0;
    }
  }
LAB_40ae5760:
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return 0;
}



/* 40ae5890 FUN_40ae5890 */

/* Boundary evidence: original MIPS .pdata 40ae5890..40ae5a0b. Semantic name remains unreviewed. */

undefined4 FUN_40ae5890(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    return 0;
  }
  iVar10 = *(int *)(param_1 + 0x148);
  if (0 < *(int *)(param_1 + 0xf0)) {
    puVar9 = *(undefined4 **)(param_1 + 0x18c);
    iVar11 = *(int *)(param_1 + 0x144);
    uVar8 = 0;
    iVar7 = 0;
    do {
      piVar3 = (int *)(iVar11 + iVar7);
      *(int *)((int)puVar9 + iVar7) = *piVar3 + -1;
      iVar6 = *piVar3;
      iVar4 = *(int *)(param_1 + 0x50);
      if (iVar6 < 2) {
LAB_40ae597c:
        iVar7 = *(int *)((int)puVar9 + iVar7);
      }
      else {
        iVar1 = 1 << (uVar8 & 0x1f);
        if (iVar1 == 0) {
          trap(7);
        }
        iVar1 = ((*(int *)(param_1 + 0xf8) / iVar1) * *(int *)(param_1 + 0x17c) + (iVar4 >> 1)) /
                iVar4;
        if (iVar4 == 0) {
          trap(7);
        }
        if (iVar1 < *(int *)(iVar10 + 4)) {
          *(undefined4 *)((int)puVar9 + iVar7) = 0;
        }
        else {
          iVar4 = 1;
          iVar5 = iVar10;
          do {
            iVar2 = iVar4;
            iVar4 = iVar2 + 1;
            if (iVar6 <= iVar4) goto LAB_40ae597c;
            piVar3 = (int *)(iVar5 + 8);
            iVar5 = iVar5 + 4;
          } while (*piVar3 <= iVar1);
          *(int *)((int)puVar9 + iVar7) = iVar2;
        }
        iVar7 = *(int *)((int)puVar9 + iVar7);
      }
      if (iVar7 < 1) {
        return 0x80040000;
      }
      uVar8 = uVar8 + 1;
      iVar10 = iVar10 + 0x74;
      if (*(int *)(param_1 + 0xf0) <= (int)uVar8) goto LAB_40ae59e4;
      iVar7 = uVar8 * 4;
    } while( true );
  }
  puVar9 = *(undefined4 **)(param_1 + 0x18c);
LAB_40ae59e4:
  *(undefined4 *)(param_1 + 0x180) = *puVar9;
  return 0;
}



/* 40ae5a0c FUN_40ae5a0c */

void FUN_40ae5a0c(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar2 = *(int *)(*(int *)(param_2 + 200) + 8);
  iVar5 = (int)*(short *)(iVar2 + (*(short *)(param_2 + 0x78) + -1) * 2);
  iVar2 = (int)*(short *)(iVar2 + *(short *)(param_2 + 0x78) * 2);
  puVar8 = *(undefined4 **)(param_2 + 0x38);
  if (iVar2 < iVar5) {
    sVar1 = *(short *)(param_2 + 0x7c);
    if (iVar2 == 0) {
      trap(7);
    }
    if (0 < sVar1) {
      iVar3 = 0;
      puVar4 = puVar8;
      do {
        iVar3 = iVar3 + 1;
        *puVar4 = *puVar8;
        puVar8 = puVar8 + iVar5 / iVar2;
        puVar4 = puVar4 + 1;
      } while (iVar3 < sVar1);
    }
  }
  else {
    if (iVar2 <= iVar5) {
      return;
    }
    iVar2 = iVar2 / iVar5;
    if (iVar5 == 0) {
      trap(7);
    }
    iVar5 = (int)*(short *)(param_2 + 0x7c) / iVar2;
    if (iVar2 == 0) {
      trap(7);
    }
    iVar3 = iVar5 + -1;
    if (-1 < iVar3) {
      puVar4 = puVar8 + iVar3;
      puVar8 = puVar8 + iVar2 * iVar3;
      iVar3 = 0;
      do {
        if (0 < iVar2) {
          iVar6 = 0;
          puVar7 = puVar8;
          do {
            iVar6 = iVar6 + 1;
            *puVar7 = *puVar4;
            puVar7 = puVar7 + 1;
          } while (iVar6 < iVar2);
        }
        iVar3 = iVar3 + 1;
        puVar8 = puVar8 + -iVar2;
        puVar4 = puVar4 + -1;
      } while (iVar3 != iVar5);
      return;
    }
  }
  return;
}



/* 40ae5ce8 FUN_40ae5ce8 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40ae5ce8..40ae66b3. Semantic name remains unreviewed. */

void FUN_40ae5ce8(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int *piVar16;
  int iVar17;
  uint uVar18;
  int local_108 [4];
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8 [10];
  int local_a0;
  int local_9c [19];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined1 *local_3c;
  int *local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  local_3c = *(undefined1 **)(param_2 + 0xc);
  local_40 = *(int *)(param_2 + 0x10);
  local_44 = *(int *)(param_2 + 4);
  if ((param_6 == 6) ||
     (((*(int *)(param_1 + 0x40) != 1 && (31999 < *(int *)(param_1 + 0x50))) &&
      (*(int *)(param_1 + 0x50) < 0xac44)))) {
    iVar11 = *(int *)(param_1 + 0x180);
    local_48 = 1;
    iVar13 = *(int *)(param_1 + 0x184);
    iVar7 = *(int *)(param_3 + iVar11 * 4);
    iVar9 = *(int *)(param_1 + 0x108);
    iVar6 = iVar13;
    if (iVar13 <= iVar7) {
      iVar6 = iVar7;
    }
    local_4c = 0;
    if (iVar9 <= iVar6) goto LAB_40ae6618;
  }
  else {
    if (*(int *)(param_1 + 0xfc) == 0) {
      trap(7);
    }
    iVar11 = *(int *)(param_1 + 0x180);
    iVar13 = *(int *)(param_1 + 0x184);
    iVar9 = *(int *)(param_1 + 0x108);
    local_48 = 0;
    local_4c = ((((int)*(short *)(param_2 + 0x7c) << (param_6 & 0x1f)) >> 6) *
               *(int *)(param_1 + 0x110)) / *(int *)(param_1 + 0xfc);
    iVar7 = *(int *)(param_3 + iVar11 * 4);
    iVar6 = iVar13;
    if (iVar13 <= iVar7) {
      iVar6 = iVar7;
    }
    if (iVar9 <= iVar6) {
LAB_40ae6618:
      **(undefined1 **)(param_2 + 0xc) = 0;
      return;
    }
  }
  local_50 = 1 << (param_6 - 7 & 0x1f);
  local_30 = 6 - param_6;
  piVar16 = (int *)(param_3 + (iVar11 + 1) * 4);
  uVar18 = 0;
  iVar14 = 0;
  iVar17 = 0;
  local_34 = (uint)((int)param_6 < 7);
  local_2c = param_6 - 6;
  iVar7 = iVar11 + 1;
  do {
    if (local_3c[iVar11] == '\x01') {
      iVar12 = *(int *)(param_4 + (iVar14 + 1) * 4);
      iVar11 = (iVar6 << (param_6 & 0x1f)) >> 6;
      if (iVar12 <= iVar11) {
        piVar8 = (int *)(param_4 + (iVar14 + 2) * 4);
        iVar3 = iVar14 + 1;
        do {
          iVar14 = iVar3;
          iVar12 = *piVar8;
          piVar8 = piVar8 + 1;
          iVar3 = iVar14 + 1;
        } while (iVar12 <= iVar11);
      }
      if (local_48 == 0) {
        iVar11 = *(int *)(param_3 + iVar7 * 4);
        if (iVar11 <= iVar9) {
          iVar9 = iVar11;
        }
        iVar11 = (iVar9 << (param_6 & 0x1f)) >> 6;
        if (local_4c < iVar11) {
          iVar11 = local_4c;
        }
        if (*(int *)(param_4 + (iVar17 + 1) * 4) < iVar11) {
          piVar8 = (int *)(param_4 + (iVar17 + 2) * 4);
          iVar13 = iVar17 + 1;
          do {
            iVar17 = iVar13;
            iVar3 = *piVar8;
            piVar8 = piVar8 + 1;
            iVar13 = iVar17 + 1;
          } while (iVar3 < iVar11);
        }
        if (iVar17 == iVar14) {
          iVar11 = *(int *)(local_44 + iVar17 * 4);
          if (iVar11 < 1) {
            iVar6 = -iVar11;
            if (iVar11 < -0x48) {
              iVar6 = 0x47;
              local_108[0] = 0x2d;
            }
            else {
              local_108[0] = (iVar6 >> 2) + 0x1c;
            }
            local_108[1] = *(int *)(&DAT_40b0b828 + iVar6 * 4);
          }
          else {
            if (iVar11 < 0x3e) {
              local_108[0] = 0x1c - (iVar11 >> 2);
              iVar11 = iVar11 + -1;
            }
            else {
              iVar11 = 0x3d;
              local_108[0] = 0xd;
            }
            local_108[1] = *(int *)(&DAT_40b0b948 + iVar11 * 4);
          }
          FUN_40aec0dc(local_9c + uVar18 * 2 + -1,local_108[0],local_108[1],local_108[0],
                       local_108[1]);
          iVar13 = *(int *)(param_1 + 0x184);
          iVar9 = *(int *)(param_1 + 0x108);
          uVar18 = uVar18 + 1 & 0xff;
        }
        else {
          iVar11 = local_4c;
          if (iVar12 <= local_4c) {
            iVar11 = iVar12;
          }
          if (local_34 == 0) {
            iVar11 = iVar11 + local_50 >> (local_2c & 0x1f);
            iVar13 = *(int *)(local_44 + iVar14 * 4);
            if (0 < iVar13) goto LAB_40ae625c;
LAB_40ae64b8:
            iVar12 = -iVar13;
            if (iVar13 < -0x48) {
              iVar12 = 0x47;
              local_108[2] = 0x2d;
            }
            else {
              local_108[2] = (iVar12 >> 2) + 0x1c;
            }
            local_108[3] = *(int *)(&DAT_40b0b828 + iVar12 * 4);
            iVar13 = *(int *)(local_44 + iVar17 * 4);
            if (iVar13 < 1) goto LAB_40ae6500;
LAB_40ae62ac:
            if (iVar13 < 0x3e) {
              local_f8 = 0x1c - (iVar13 >> 2);
              iVar13 = iVar13 + -1;
            }
            else {
              iVar13 = 0x3d;
              local_f8 = 0xd;
            }
            local_f4 = *(int *)(&DAT_40b0b948 + iVar13 * 4);
          }
          else {
            iVar11 = iVar11 << (local_30 & 0x1f);
            iVar13 = *(int *)(local_44 + iVar14 * 4);
            if (iVar13 < 1) goto LAB_40ae64b8;
LAB_40ae625c:
            iVar12 = 0x3d;
            if (iVar13 < 0x3e) {
              local_108[2] = 0x1c - (iVar13 >> 2);
              iVar12 = iVar13 + -1;
            }
            else {
              local_108[2] = 0xd;
            }
            local_108[3] = *(int *)(&DAT_40b0b948 + iVar12 * 4);
            iVar13 = *(int *)(local_44 + iVar17 * 4);
            if (0 < iVar13) goto LAB_40ae62ac;
LAB_40ae6500:
            if (iVar13 < -0x48) {
              iVar13 = 0x47;
              local_f8 = 0x2d;
            }
            else {
              iVar13 = -iVar13;
              local_f8 = (iVar13 >> 2) + 0x1c;
            }
            local_f4 = *(int *)(&DAT_40b0b828 + iVar13 * 4);
          }
          FUN_40aec0dc(&local_f0,local_108[2],local_108[3],local_108[2],local_108[3]);
          FUN_40aec260(&local_e8,iVar11 - iVar6,local_f0,local_ec);
          FUN_40aec0dc(&local_e0,local_f8,local_f4,local_f8,local_f4);
          FUN_40aec260(&local_d8,iVar9 - iVar11,local_e0,local_dc);
          FUN_40aec3d8(&local_d0,local_e8,local_e4,local_d8,local_d4);
          FUN_40aec318(local_108,local_d0,local_cc,iVar9 - iVar6);
          iVar13 = *(int *)(param_1 + 0x184);
          iVar9 = *(int *)(param_1 + 0x108);
          local_9c[uVar18 * 2 + -1] = local_108[0];
          local_9c[uVar18 * 2] = local_108[1];
          uVar18 = uVar18 + 1 & 0xff;
        }
      }
      else {
        local_c8[uVar18] = *(int *)(local_44 + iVar14 * 4);
        uVar18 = uVar18 + 1 & 0xff;
      }
      iVar6 = iVar13;
      if (iVar13 <= *piVar16) {
        iVar6 = *piVar16;
      }
      if (iVar9 <= iVar6) break;
    }
    else {
      iVar6 = iVar13;
      if (iVar13 <= *piVar16) {
        iVar6 = *piVar16;
      }
      if (iVar9 <= iVar6) break;
    }
    piVar16 = piVar16 + 1;
    iVar11 = iVar7;
    iVar7 = iVar7 + 1;
  } while( true );
  iVar11 = uVar18 - 1;
  if (0 < iVar11) {
    local_38 = local_108 + iVar11;
    puVar15 = (uint *)(local_40 + 4);
    iVar6 = (int)local_9c;
    piVar16 = local_c8;
    iVar9 = 0;
    do {
      while (local_48 == 0) {
        iVar7 = *(int *)(iVar6 + 0xfffffffc);
        iVar13 = local_9c[iVar11 * 2 + -1];
        iVar9 = iVar9 + 1;
        uVar1 = FUN_40aff9dc();
        uVar5 = 0x80000000;
        if (uVar1 < 0x40000000) {
          uVar5 = 0;
        }
        uVar5 = uVar5 >> 1;
        uVar10 = uVar1 + 0xc0000000;
        if (uVar1 < 0x40000000) {
          uVar10 = uVar1;
        }
        uVar2 = uVar5 + 0x10000000;
        uVar1 = uVar5 + 0x20000000;
        if (uVar10 < uVar2) {
          uVar1 = uVar5;
        }
        uVar1 = uVar1 >> 1;
        uVar5 = uVar10 - uVar2;
        if (uVar10 < uVar2) {
          uVar5 = uVar10;
        }
        uVar2 = uVar1 + 0x4000000;
        uVar10 = uVar1 + 0x8000000;
        if (uVar5 < uVar2) {
          uVar10 = uVar1;
        }
        uVar1 = uVar5 - uVar2;
        if (uVar5 < uVar2) {
          uVar1 = uVar5;
        }
        uVar10 = uVar10 >> 1;
        uVar2 = uVar10 + 0x1000000;
        uVar5 = uVar10 + 0x2000000;
        if (uVar1 < uVar2) {
          uVar5 = uVar10;
        }
        uVar10 = uVar1 - uVar2;
        if (uVar1 < uVar2) {
          uVar10 = uVar1;
        }
        uVar5 = uVar5 >> 1;
        uVar2 = uVar5 + 0x400000;
        uVar1 = uVar5 + 0x800000;
        if (uVar10 < uVar2) {
          uVar1 = uVar5;
        }
        uVar5 = uVar10 - uVar2;
        if (uVar10 < uVar2) {
          uVar5 = uVar10;
        }
        uVar1 = uVar1 >> 1;
        uVar2 = uVar1 + 0x100000;
        uVar10 = uVar1 + 0x200000;
        if (uVar5 < uVar2) {
          uVar10 = uVar1;
        }
        uVar10 = uVar10 >> 1;
        uVar1 = uVar5 - uVar2;
        if (uVar5 < uVar2) {
          uVar1 = uVar5;
        }
        uVar2 = uVar10 + 0x40000;
        uVar5 = uVar10 + 0x80000;
        if (uVar1 < uVar2) {
          uVar5 = uVar10;
        }
        uVar5 = uVar5 >> 1;
        uVar10 = uVar1 - uVar2;
        if (uVar1 < uVar2) {
          uVar10 = uVar1;
        }
        uVar2 = uVar5 + 0x10000;
        uVar1 = uVar5 + 0x20000;
        if (uVar10 < uVar2) {
          uVar1 = uVar5;
        }
        uVar1 = uVar1 >> 1;
        uVar5 = uVar10 - uVar2;
        if (uVar10 < uVar2) {
          uVar5 = uVar10;
        }
        uVar2 = uVar1 + 0x4000;
        uVar10 = uVar1 + 0x8000;
        if (uVar5 < uVar2) {
          uVar10 = uVar1;
        }
        uVar10 = uVar10 >> 1;
        uVar1 = uVar5 - uVar2;
        if (uVar5 < uVar2) {
          uVar1 = uVar5;
        }
        uVar2 = uVar10 + 0x1000;
        uVar5 = uVar10 + 0x2000;
        if (uVar1 < uVar2) {
          uVar5 = uVar10;
        }
        uVar5 = uVar5 >> 1;
        uVar10 = uVar1 - uVar2;
        if (uVar1 < uVar2) {
          uVar10 = uVar1;
        }
        uVar2 = uVar5 + 0x400;
        uVar1 = uVar5 + 0x800;
        if (uVar10 < uVar2) {
          uVar1 = uVar5;
        }
        uVar1 = uVar1 >> 1;
        uVar5 = uVar10 - uVar2;
        if (uVar10 < uVar2) {
          uVar5 = uVar10;
        }
        uVar2 = uVar1 + 0x100;
        uVar10 = uVar1 + 0x200;
        if (uVar5 < uVar2) {
          uVar10 = uVar1;
        }
        uVar10 = uVar10 >> 1;
        uVar1 = uVar5 - uVar2;
        if (uVar5 < uVar2) {
          uVar1 = uVar5;
        }
        uVar2 = uVar10 + 0x40;
        uVar5 = uVar10 + 0x80;
        if (uVar1 < uVar2) {
          uVar5 = uVar10;
        }
        uVar5 = uVar5 >> 1;
        uVar10 = uVar1 - uVar2;
        if (uVar1 < uVar2) {
          uVar10 = uVar1;
        }
        uVar2 = uVar5 + 0x10;
        uVar1 = uVar5 + 0x20;
        if (uVar10 < uVar2) {
          uVar1 = uVar5;
        }
        uVar1 = uVar1 >> 1;
        uVar5 = uVar10 - uVar2;
        if (uVar10 < uVar2) {
          uVar5 = uVar10;
        }
        uVar2 = uVar1 + 4;
        uVar10 = uVar1 + 8;
        if (uVar5 < uVar2) {
          uVar10 = uVar1;
        }
        uVar10 = uVar10 >> 1;
        uVar1 = uVar5 - uVar2;
        if (uVar5 < uVar2) {
          uVar1 = uVar5;
        }
        uVar5 = uVar10 + 2;
        if (uVar1 < uVar10 + 1) {
          uVar5 = uVar10;
        }
        *puVar15 = uVar5 >> 1;
        puVar15[-1] = (iVar7 - iVar13) + 0x1e >> 1;
        iVar6 = iVar6 + 8;
        puVar15 = puVar15 + 2;
        piVar16 = piVar16 + 1;
        if (iVar11 <= iVar9) goto LAB_40ae63f4;
      }
      iVar7 = *piVar16 - local_38[0x10];
      if (iVar7 < 1) {
        if (iVar7 < -0x48) {
          iVar7 = 0x47;
          uVar1 = 0x2d;
        }
        else {
          iVar7 = -iVar7;
          uVar1 = (iVar7 >> 2) + 0x1c;
        }
        uVar5 = *(uint *)(&DAT_40b0b828 + iVar7 * 4);
        puVar15[-1] = uVar1;
        *puVar15 = uVar5;
      }
      else {
        if (iVar7 < 0x3e) {
          uVar1 = 0x1c - (iVar7 >> 2);
          iVar7 = iVar7 + -1;
        }
        else {
          iVar7 = 0x3d;
          uVar1 = 0xd;
        }
        uVar5 = *(uint *)(&DAT_40b0b948 + iVar7 * 4);
        puVar15[-1] = uVar1;
        *puVar15 = uVar5;
      }
      iVar9 = iVar9 + 1;
      puVar15 = puVar15 + 2;
      iVar6 = iVar6 + 8;
      piVar16 = piVar16 + 1;
    } while (iVar9 < iVar11);
  }
LAB_40ae63f4:
  if (uVar18 != 0) {
    puVar4 = (undefined4 *)(local_40 + (uVar18 - 1) * 8);
    *puVar4 = 0x1e;
    puVar4[1] = 0x40000000;
  }
  *local_3c = (char)uVar18;
  return;
}



/* 40ae66b4 FUN_40ae66b4 */

/* Boundary evidence: original MIPS .pdata 40ae66b4..40ae75db. Semantic name remains unreviewed. */

undefined4 FUN_40ae66b4(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  uint local_b4;
  int local_b0;
  undefined4 *local_a8;
  int local_a4;
  int *local_a0;
  uint local_9c;
  int local_98;
  int local_94;
  void *local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined4 *local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  local_68 = *param_2;
  local_6c = param_2[3];
  local_70 = param_2[5];
  local_74 = param_2[4];
  local_78 = param_2[1];
  local_7c = param_2[0x11];
  local_88 = param_2[0xf];
  if (param_2[0x2d] == 0) {
    local_90 = (void *)0x0;
  }
  else {
    local_90 = (void *)param_2[0x2e];
  }
  iVar8 = param_1[0x37];
  if ((0 < iVar8) && (iVar2 = (int)(short)param_2[0x1f], 0 < iVar2)) {
    if (local_90 != (void *)0x0) {
      memset(local_90,0,100);
      iVar8 = param_1[0x37];
      iVar2 = (int)(short)param_2[0x1f];
    }
    local_b8 = (iVar8 << 6) / iVar2;
    if (iVar2 == 0) {
      trap(7);
    }
    local_b4 = LZCOUNT(local_b8) ^ 0x1f;
    if (iVar8 == 0) {
      trap(7);
    }
    local_84 = param_1[0x52] + (LZCOUNT(param_1[0x3f] / iVar8) ^ 0x1fU) * 0x74;
    local_b0 = *(int *)(param_1[0x51] + (LZCOUNT(param_1[0x3f] / iVar8) ^ 0x1fU) * 4);
    local_80 = param_1[0x4a];
    local_9c = local_b4;
    local_98 = local_b0;
    FUN_40ae5ce8((int)param_1,(int)param_2,local_80,local_84,local_b8,local_b4);
    iVar8 = 0;
    iVar3 = *(int *)(local_84 + 4);
    iVar2 = local_84;
    while (iVar3 < 1) {
      piVar10 = (int *)(iVar2 + 8);
      iVar8 = iVar8 + 1;
      iVar2 = iVar2 + 4;
      iVar3 = *piVar10;
    }
    if (*(int *)(local_80 + 4) < 1) {
      local_60 = 0;
      iVar2 = local_80;
      do {
        piVar10 = (int *)(iVar2 + 8);
        local_60 = local_60 + 1;
        iVar2 = iVar2 + 4;
      } while (*piVar10 < 1);
    }
    else {
      local_60 = 0;
    }
    local_94 = 1 << (local_9c - 7 & 0x1f);
    local_30 = 6 - local_9c;
    local_58 = param_1 + 0x7c;
    local_34 = (uint)((int)local_9c < 7);
    local_2c = local_9c - 6;
    local_64 = 0;
    uVar17 = 0;
    while (iVar2 = local_98, iVar3 = param_1[0x61], (int)uVar17 < iVar3) {
      local_50 = (int *)(local_84 + (iVar8 + 1) * 4);
      iVar12 = *local_50;
      iVar4 = (int)(uVar17 << (local_9c & 0x1f)) >> 6;
      if (iVar12 <= iVar4) {
        iVar6 = (iVar8 + 2) * 4;
        piVar10 = (int *)(local_84 + iVar6);
        iVar1 = iVar8 + 1;
        do {
          iVar8 = iVar1;
          iVar5 = iVar6;
          iVar12 = *piVar10;
          piVar10 = piVar10 + 1;
          iVar6 = iVar5 + 4;
          iVar1 = iVar8 + 1;
        } while (iVar12 <= iVar4);
        local_50 = (int *)(local_84 + iVar5);
      }
      if (iVar8 < local_98) {
        if (local_34 == 0) {
          iVar12 = iVar12 + local_94 >> (local_2c & 0x1f);
        }
        else {
          iVar12 = iVar12 << (local_30 & 0x1f);
        }
        iVar2 = iVar3;
        if (iVar12 <= iVar3) {
          iVar2 = iVar12;
        }
        FUN_40af2b3c(&local_d0,param_1,(int)param_2,iVar8);
      }
      else {
        FUN_40af2b3c(&local_d0,param_1,(int)param_2,iVar8);
      }
      iVar3 = local_d0 + -9;
      iVar4 = local_d0;
      iVar12 = local_cc;
      if (0x23 < iVar3) {
        do {
          iVar4 = iVar4 + -1;
          iVar12 = iVar12 >> 1;
        } while (iVar4 != 0x2c);
        iVar3 = iVar3 + (0x2c - local_d0);
      }
      uVar16 = iVar3 - 5;
      if ((int)uVar17 < iVar2) {
        local_5c = (undefined4 *)((int)local_90 + local_60 * 4);
        puVar13 = (uint *)(local_68 + local_64 * 4);
        local_38 = -uVar16;
        piVar10 = (int *)(local_88 + uVar17 * 4);
        uVar14 = uVar17;
        do {
          iVar4 = FUN_40aeac3c(local_58);
          uVar9 = *puVar13;
          iVar4 = ((int)((ulonglong)((longlong)iVar4 * 0x28f5c28f) >> 0x20) << 1) >> 0xb;
          uVar7 = uVar9;
          if ((int)uVar9 < 0) {
            uVar7 = -uVar9;
          }
          if ((int)uVar7 < 0x200) {
            iVar4 = (int)((ulonglong)((longlong)(int)(iVar4 + uVar9 * 0x400000) * (longlong)iVar12)
                         >> 0x20) << 1;
            if ((int)uVar16 < 0) {
              *piVar10 = iVar4 << (local_38 & 0x1f);
            }
            else {
              *piVar10 = iVar4 >> (uVar16 & 0x1f);
            }
          }
          else {
            uVar11 = 0;
            do {
              uVar7 = uVar7 >> 1;
              uVar11 = uVar11 + 1;
            } while (0x1ff < uVar7);
            iVar6 = iVar3 - uVar11;
            if (0x23 < (int)(iVar3 - uVar11)) {
              iVar6 = 0x23;
            }
            uVar7 = iVar6 - 5;
            iVar4 = (int)((ulonglong)
                          ((longlong)
                           (int)((uVar9 << (0x16 - uVar11 & 0x1f)) + (iVar4 >> (uVar11 & 0x1f))) *
                          (longlong)iVar12) >> 0x20) << 1;
            if ((int)uVar7 < 0) {
              iVar4 = iVar4 << (-uVar7 & 0x1f);
            }
            else {
              iVar4 = iVar4 >> (uVar7 & 0x1f);
            }
            *piVar10 = iVar4;
          }
          if ((local_90 != (void *)0x0) && (*puVar13 != 0)) {
            *local_5c = 1;
          }
          uVar14 = uVar14 + 1;
          puVar13 = puVar13 + 1;
          piVar10 = piVar10 + 1;
        } while ((int)uVar14 < iVar2);
        uVar16 = ~uVar17;
        uVar17 = iVar2 + uVar16 + uVar17 + 1;
        local_64 = local_64 + 1 + iVar2 + uVar16;
      }
      local_4c = local_60 + 1;
      if (*local_50 <= (int)(uVar17 + 1 << (local_9c & 0x1f)) >> 6) {
        iVar8 = iVar8 + 1;
      }
      if (*(int *)(local_80 + local_4c * 4) <= (int)uVar17) {
        piVar10 = (int *)(local_80 + (local_60 + 2) * 4);
        while (iVar2 = *piVar10, piVar10 = piVar10 + 1, local_60 = local_4c, iVar2 <= (int)uVar17) {
          local_4c = local_4c + 1;
        }
      }
    }
    iVar3 = param_1[0x42];
    local_3c = local_9c - 6;
    local_40 = 6 - local_9c;
    local_44 = (uint)((int)local_9c < 7);
    local_8c = 0;
    iVar2 = iVar8;
    if ((int)uVar17 < iVar3) {
      do {
        iVar8 = iVar2 + 1;
        if (*(char *)(local_6c + local_60) == '\x01') {
          if (local_90 != (void *)0x0) {
            *(undefined4 *)((int)local_90 + local_60 * 4) = 1;
          }
          FUN_40af5ca4(&local_c0,*(int *)(local_70 + local_8c * 4));
          piVar10 = (int *)(local_74 + local_8c * 8);
          local_4c = local_60 + 1;
          FUN_40aec0dc(&local_c0,local_c0,local_bc,*piVar10,piVar10[1]);
          local_54 = (int *)(local_80 + local_4c * 4);
          iVar12 = *local_54;
          iVar3 = param_1[0x42];
          iVar8 = iVar3;
          if (iVar12 <= iVar3) {
            iVar8 = iVar12;
          }
          if ((int)uVar17 < iVar8) {
            do {
              iVar3 = *(int *)(local_78 + iVar2 * 4) - local_7c;
              if (iVar3 < 1) {
                if (iVar3 < -0x48) {
                  iVar3 = 0x47;
                  local_c8 = 0x2d;
                }
                else {
                  iVar3 = -iVar3;
                  local_c8 = (iVar3 >> 2) + 0x1c;
                }
                local_c4 = *(int *)(&DAT_40b0b828 + iVar3 * 4);
                FUN_40aec0dc(&local_d0,local_c8,local_c4,local_c0,local_bc);
              }
              else {
                if (iVar3 < 0x3e) {
                  local_c8 = 0x1c - (iVar3 >> 2);
                  iVar3 = iVar3 + -1;
                }
                else {
                  iVar3 = 0x3d;
                  local_c8 = 0xd;
                }
                local_c4 = *(int *)(&DAT_40b0b948 + iVar3 * 4);
                FUN_40aec0dc(&local_d0,local_c8,local_c4,local_c0,local_bc);
              }
              iVar3 = local_d0 + -2;
              iVar4 = local_d0;
              iVar12 = local_cc;
              if (0x23 < iVar3) {
                do {
                  iVar4 = iVar4 + -1;
                  iVar12 = iVar12 >> 1;
                } while (iVar4 != 0x25);
                iVar3 = iVar3 + (0x25 - local_d0);
              }
              piVar10 = (int *)(local_84 + (iVar2 + 1) * 4);
              iVar4 = *piVar10;
              iVar6 = (int)(uVar17 << (local_9c & 0x1f)) >> 6;
              uVar16 = iVar3 - 5;
              if (iVar4 <= iVar6) {
                iVar3 = (iVar2 + 2) * 4;
                piVar10 = (int *)(local_84 + iVar3);
                iVar1 = iVar2 + 1;
                do {
                  iVar2 = iVar1;
                  iVar5 = iVar3;
                  iVar4 = *piVar10;
                  piVar10 = piVar10 + 1;
                  iVar3 = iVar5 + 4;
                  iVar1 = iVar2 + 1;
                } while (iVar4 <= iVar6);
                piVar10 = (int *)(local_84 + iVar5);
              }
              iVar3 = local_98;
              if (iVar2 < local_98) {
                if (local_44 == 0) {
                  iVar4 = local_94 + iVar4 >> (local_3c & 0x1f);
                }
                else {
                  iVar4 = iVar4 << (local_40 & 0x1f);
                }
                iVar3 = iVar8;
                if (iVar4 <= iVar8) {
                  iVar3 = iVar4;
                }
              }
              if ((int)uVar17 < iVar3) {
                if ((int)uVar16 < 0) {
                  piVar15 = (int *)(local_88 + uVar17 * 4);
                  uVar14 = uVar17;
                  do {
                    iVar4 = FUN_40aeac3c(local_58);
                    uVar14 = uVar14 + 1;
                    *piVar15 = ((int)((ulonglong)((longlong)iVar4 * (longlong)iVar12) >> 0x20) << 1)
                               << (-uVar16 & 0x1f);
                    piVar15 = piVar15 + 1;
                  } while ((int)uVar14 < iVar3);
                }
                else {
                  piVar15 = (int *)(local_88 + uVar17 * 4);
                  uVar14 = uVar17;
                  do {
                    iVar4 = FUN_40aeac3c(local_58);
                    uVar14 = uVar14 + 1;
                    *piVar15 = ((int)((ulonglong)((longlong)iVar4 * (longlong)iVar12) >> 0x20) << 1)
                               >> (uVar16 & 0x1f);
                    piVar15 = piVar15 + 1;
                  } while ((int)uVar14 < iVar3);
                }
                uVar17 = uVar17 + 1 + iVar3 + ~uVar17;
              }
              iVar4 = (int)(uVar17 + 1 << (local_9c & 0x1f)) >> 6;
              if (*piVar10 <= iVar4) {
                iVar2 = iVar2 + 1;
              }
            } while ((int)uVar17 < iVar8);
            iVar12 = *local_54;
            iVar3 = param_1[0x42];
          }
          else {
            iVar4 = (int)(uVar17 + 1 << (local_9c & 0x1f)) >> 6;
          }
          iVar8 = iVar2 + 1;
          local_8c = local_8c + 1;
        }
        else {
          iVar12 = *(int *)(local_84 + iVar8 * 4);
          iVar4 = (int)(uVar17 << (local_9c & 0x1f)) >> 6;
          if (iVar12 <= iVar4) {
            piVar10 = (int *)(local_84 + (iVar2 + 2) * 4);
            iVar2 = iVar8;
            while( true ) {
              iVar12 = *piVar10;
              piVar10 = piVar10 + 1;
              if (iVar4 < iVar12) break;
              iVar2 = iVar2 + 1;
            }
            iVar8 = iVar2 + 1;
          }
          iVar4 = local_98;
          if (iVar2 < local_98) {
            if (local_44 == 0) {
              iVar12 = local_94 + iVar12 >> (local_3c & 0x1f);
            }
            else {
              iVar12 = iVar12 << (local_40 & 0x1f);
            }
            iVar4 = iVar3;
            if (iVar12 <= iVar3) {
              iVar4 = iVar12;
            }
          }
          local_4c = local_60 + 1;
          local_a0 = (int *)(local_80 + local_4c * 4);
          iVar3 = *local_a0;
          if (iVar4 <= *local_a0) {
            iVar3 = iVar4;
          }
          FUN_40af2b3c(&local_d0,param_1,(int)param_2,iVar2);
          local_a4 = local_d0 + -9;
          iVar4 = local_d0;
          iVar12 = local_cc;
          if (0x23 < local_a4) {
            do {
              iVar4 = iVar4 + -1;
              iVar12 = iVar12 >> 1;
            } while (iVar4 != 0x2c);
            local_a4 = (local_a4 - local_d0) + 0x2c;
          }
          uVar16 = local_a4 - 5;
          if ((int)uVar17 < iVar3) {
            local_a8 = (undefined4 *)((int)local_90 + local_60 * 4);
            puVar13 = (uint *)(local_68 + local_64 * 4);
            piVar10 = (int *)(local_88 + uVar17 * 4);
            local_48 = -uVar16;
            uVar14 = uVar17;
            do {
              iVar4 = FUN_40aeac3c(local_58);
              uVar9 = *puVar13;
              iVar4 = ((int)((ulonglong)((longlong)iVar4 * 0x28f5c28f) >> 0x20) << 1) >> 0xb;
              uVar7 = uVar9;
              if ((int)uVar9 < 0) {
                uVar7 = -uVar9;
              }
              if ((int)uVar7 < 0x200) {
                iVar4 = (int)((ulonglong)
                              ((longlong)(int)(iVar4 + uVar9 * 0x400000) * (longlong)iVar12) >> 0x20
                             ) << 1;
                if ((int)uVar16 < 0) {
                  *piVar10 = iVar4 << (local_48 & 0x1f);
                }
                else {
                  *piVar10 = iVar4 >> (uVar16 & 0x1f);
                }
              }
              else {
                uVar11 = 0;
                do {
                  uVar7 = uVar7 >> 1;
                  uVar11 = uVar11 + 1;
                } while (0x1ff < uVar7);
                iVar6 = local_a4 - uVar11;
                if (0x23 < (int)(local_a4 - uVar11)) {
                  iVar6 = 0x23;
                }
                uVar7 = iVar6 - 5;
                iVar4 = (int)((ulonglong)
                              ((longlong)
                               (int)((uVar9 << (0x16 - uVar11 & 0x1f)) + (iVar4 >> (uVar11 & 0x1f)))
                              * (longlong)iVar12) >> 0x20) << 1;
                if ((int)uVar7 < 0) {
                  iVar4 = iVar4 << (-uVar7 & 0x1f);
                }
                else {
                  iVar4 = iVar4 >> (uVar7 & 0x1f);
                }
                *piVar10 = iVar4;
              }
              if ((local_90 != (void *)0x0) && (*puVar13 != 0)) {
                *local_a8 = 1;
              }
              uVar14 = uVar14 + 1;
              puVar13 = puVar13 + 1;
              piVar10 = piVar10 + 1;
            } while ((int)uVar14 < iVar3);
            uVar16 = ~uVar17;
            uVar17 = iVar3 + uVar16 + uVar17 + 1;
            iVar12 = *local_a0;
            local_64 = local_64 + 1 + iVar3 + uVar16;
            iVar3 = param_1[0x42];
            iVar4 = (int)(uVar17 + 1 << (local_9c & 0x1f)) >> 6;
          }
          else {
            iVar4 = (int)(uVar17 + 1 << (local_9c & 0x1f)) >> 6;
            iVar3 = param_1[0x42];
            iVar12 = *local_a0;
          }
        }
        if (iVar4 < *(int *)(local_84 + iVar8 * 4)) {
          iVar8 = iVar2;
        }
        if (iVar12 <= (int)uVar17) {
          piVar10 = (int *)(local_80 + (local_60 + 2) * 4);
          while (iVar2 = *piVar10, piVar10 = piVar10 + 1, local_60 = local_4c, iVar2 <= (int)uVar17)
          {
            local_4c = local_4c + 1;
          }
        }
        iVar2 = iVar8;
      } while ((int)uVar17 < iVar3);
    }
    iVar2 = (int)(short)param_2[0x1f];
    if ((int)uVar17 < iVar2) {
      iVar3 = (iVar3 + -1 << (local_9c & 0x1f)) >> 6;
      if (iVar3 < *(int *)(local_84 + iVar8 * 4)) {
        piVar10 = (int *)(local_84 + (iVar8 + -1) * 4);
        iVar4 = iVar8 + -1;
        do {
          iVar8 = iVar4;
          iVar12 = *piVar10;
          piVar10 = piVar10 + -1;
          iVar4 = iVar8 + -1;
        } while (iVar3 < iVar12);
      }
      FUN_40af2b3c(&local_d0,param_1,(int)param_2,iVar8);
      iVar3 = local_d0 + 2;
      iVar4 = (int)((ulonglong)((longlong)local_cc * 0x28f5c28f) >> 0x20) << 1;
      iVar8 = local_d0;
      if (0x23 < iVar3) {
        do {
          iVar8 = iVar8 + -1;
          iVar4 = iVar4 >> 1;
        } while (iVar8 != 0x21);
        iVar3 = (iVar3 - local_d0) + 0x21;
      }
      uVar16 = iVar3 - 5;
      if ((int)uVar16 < 0) {
        piVar10 = (int *)(local_88 + uVar17 * 4);
        do {
          iVar8 = FUN_40aeac3c(local_58);
          uVar17 = uVar17 + 1;
          *piVar10 = ((int)((ulonglong)((longlong)iVar8 * (longlong)iVar4) >> 0x20) << 1) <<
                     (-uVar16 & 0x1f);
          piVar10 = piVar10 + 1;
        } while ((int)uVar17 < iVar2);
      }
      else {
        piVar10 = (int *)(local_88 + uVar17 * 4);
        do {
          iVar8 = FUN_40aeac3c(local_58);
          uVar17 = uVar17 + 1;
          *piVar10 = ((int)((ulonglong)((longlong)iVar8 * (longlong)iVar4) >> 0x20) << 1) >>
                     (uVar16 & 0x1f);
          piVar10 = piVar10 + 1;
        } while ((int)uVar17 < iVar2);
      }
    }
    if (local_90 != (void *)0x0) {
      iVar8 = param_1[0x49] + -1;
      if (-1 < iVar8) {
        iVar2 = iVar8 * 4;
        piVar15 = (int *)(local_80 + param_1[0x49] * 4);
        piVar10 = (int *)(local_80 + iVar2);
        do {
          iVar3 = *piVar10;
          iVar8 = iVar8 + -1;
          piVar10 = piVar10 + -1;
          if ((iVar3 <= param_1[0x42]) && (param_1[0x42] < *piVar15)) {
            *(undefined4 *)((int)local_90 + iVar2) = 1;
            return 0;
          }
          iVar2 = iVar2 + -4;
          piVar15 = piVar15 + -1;
        } while (-1 < iVar8);
      }
    }
    return 0;
  }
  return 0x80040002;
}



/* 40ae75dc FUN_40ae75dc */

/* Boundary evidence: original MIPS .pdata 40ae75dc..40ae7f67. Semantic name remains unreviewed. */

undefined4 FUN_40ae75dc(int *param_1,undefined4 *param_2,int param_3)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  int local_80;
  int local_7c;
  int local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  int local_68;
  uint local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int *local_4c;
  void *local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  int *local_38;
  int *local_34;
  int local_30;
  
  local_48 = (void *)param_2[0xf];
  local_4c = (int *)*param_2;
  uVar7 = param_2[0x28];
  local_58 = param_2[4];
  local_50 = param_2[3];
  local_54 = param_2[5];
  if (uVar7 == 0) {
    return 0x80040002;
  }
  if (uVar7 < 0x80000) {
    local_60 = 0xffffffff;
  }
  else {
    if ((uVar7 & 0xf0000000) == 0) {
      iVar6 = 0xd;
      do {
        iVar9 = iVar6;
        uVar7 = uVar7 << 4;
        iVar6 = iVar9 + -4;
      } while ((uVar7 & 0xf0000000) == 0);
      uVar8 = iVar9 - 5;
    }
    else {
      iVar6 = 0xd;
      uVar8 = 0xc;
    }
    if (-1 < (int)uVar7) {
      do {
        iVar9 = iVar6;
        uVar7 = uVar7 << 1;
        iVar6 = iVar9 + -1;
      } while (-1 < (int)uVar7);
      uVar8 = iVar9 - 2;
    }
    if ((int)uVar8 < 0) {
      local_60 = 0xffffffff;
    }
    else {
      uVar3 = (uVar7 & 0x7fffffff) >> 0x17;
      local_60 = (uint)(*(int *)(&DAT_40b10674 + uVar3 * 4) -
                       (int)((ulonglong)
                             (uint)(*(int *)(&DAT_40b10674 + uVar3 * 4) -
                                   *(int *)(&DAT_40b10674 + (uVar3 + 1) * 4)) *
                             (ulonglong)(uVar7 << 9) >> 0x20)) >> (uVar8 & 0x1f);
    }
  }
  local_44 = 0x1f - param_1[0xe];
  local_88 = (uint)((ulonglong)((longlong)param_1[1] * (longlong)(int)local_60) >> 0x20);
  local_80 = *param_1 + -2;
  FUN_40aeb0ac(&local_88,&local_80,0x3fffffff);
  local_8c = param_2[0x28];
  local_74 = 0;
  FUN_40aeb0ac(&local_8c,(int *)&local_74,0x3fffffff);
  uVar7 = local_44;
  if (param_1[0xb] == 0) {
    memset(local_48,0,param_1[0x41] << 2);
    uVar7 = local_44;
    iVar9 = param_1[0x41];
    iVar6 = param_1[0x42];
    if (iVar9 < iVar6) {
      piVar11 = (int *)(param_3 + iVar9 * 4);
      piVar12 = (int *)((int)local_48 + iVar9 * 4);
      local_38 = &local_78;
      piVar10 = local_4c;
      do {
        local_78 = local_74 + 0x15;
        local_90 = *piVar11 << (local_74 & 0x1f);
        FUN_40aeb0ac(&local_90,local_38,0x3fffffff);
        local_84 = (int)((ulonglong)((longlong)(int)local_88 * (longlong)(int)local_90) >> 0x20) <<
                   1;
        local_7c = uVar7 + local_80 + local_78 + -0x3e;
        iVar6 = FUN_40aeb044((int)((ulonglong)
                                   ((longlong)(*piVar10 << (local_44 & 0x1f)) *
                                   (longlong)(int)local_84) >> 0x20) << 1,local_7c,5);
        *piVar12 = iVar6;
        iVar9 = iVar9 + 1;
        iVar6 = param_1[0x42];
        piVar11 = piVar11 + 1;
        piVar10 = piVar10 + 1;
        piVar12 = piVar12 + 1;
      } while (iVar9 < iVar6);
    }
    memset((void *)((int)local_48 + iVar6 * 4),0,(*(short *)(param_2 + 0x1f) - iVar6) * 4);
    return 0;
  }
  if (param_1[0x61] < 1) {
    local_38 = &local_78;
    local_34 = param_1 + 0x7c;
    iVar6 = 0;
    local_40 = 0;
  }
  else {
    local_34 = param_1 + 0x7c;
    local_38 = &local_78;
    iVar6 = 0;
    uVar8 = 0;
    iVar9 = 0;
    do {
      iVar4 = FUN_40aeac3c(local_34);
      local_90 = *(int *)(param_3 + iVar9) << (local_74 & 0x1f);
      local_78 = local_74 + 0x15;
      if (*(int *)(param_1[0x4a] + (iVar6 + 1) * 4) <= (int)uVar8) {
        iVar6 = iVar6 + 1;
      }
      FUN_40aeb0ac(&local_90,local_38,0x3fffffff);
      local_84 = (int)((ulonglong)((longlong)(int)local_88 * (longlong)(int)local_90) >> 0x20) << 1;
      local_7c = uVar7 + local_80 + local_78 + -0x3e;
      iVar5 = FUN_40aeb044((int)((ulonglong)
                                 ((longlong)(*(int *)((int)local_4c + iVar9) << (local_44 & 0x1f)) *
                                 (longlong)(int)local_84) >> 0x20) << 1,local_7c,5);
      iVar4 = FUN_40aeb044((int)((ulonglong)
                                 ((longlong)
                                  ((int)((ulonglong)((longlong)iVar4 * 0x51eb851f) >> 0x20) << 1) *
                                 (longlong)(int)local_84) >> 0x20) << 1,local_80 + local_78 + -0x1d,
                           5);
      *(int *)((int)local_48 + iVar9) = iVar4 + iVar5;
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + 4;
      local_40 = uVar8;
    } while ((int)uVar8 < param_1[0x61]);
  }
  local_3c = local_60 >> 1;
  local_30 = local_44 - 0x1f;
  local_5c = 0;
  uVar7 = local_40;
  while (iVar9 = param_1[0x42], (int)uVar7 < iVar9) {
    while( true ) {
      iVar4 = *(int *)(param_1[0x4a] + (iVar6 + 1) * 4);
      if (iVar4 <= (int)uVar7) {
        iVar4 = *(int *)(param_1[0x4a] + (iVar6 + 2) * 4);
        iVar6 = iVar6 + 1;
      }
      if (*(char *)(local_50 + iVar6) == '\x01') break;
      if (iVar4 <= (int)uVar7) {
        iVar6 = iVar6 + 1;
      }
      iVar9 = FUN_40aeac3c(local_34);
      local_90 = *(int *)(param_3 + uVar7 * 4) << (local_74 & 0x1f);
      local_78 = local_74 + 0x15;
      FUN_40aeb0ac(&local_90,local_38,0x3fffffff);
      local_84 = (int)((ulonglong)((longlong)(int)local_88 * (longlong)(int)local_90) >> 0x20) << 1;
      iVar5 = local_80 + local_78;
      lVar2 = (longlong)(int)local_84;
      local_7c = local_30 + iVar5 + -0x1f;
      iVar4 = FUN_40aeb044((int)((ulonglong)
                                 ((longlong)(local_4c[local_40] << (local_44 & 0x1f)) *
                                 (longlong)(int)local_84) >> 0x20) << 1,local_7c,5);
      *(int *)((int)local_48 + uVar7 * 4) =
           (((int)((ulonglong)
                   (((int)((ulonglong)((longlong)iVar9 * 0x51eb851f) >> 0x20) << 1) * lVar2) >> 0x20
                  ) << 1) >> (iVar5 - 0x22U & 0x1f)) + iVar4;
      iVar9 = param_1[0x42];
      uVar7 = uVar7 + 1;
      local_40 = local_40 + 1;
      if (iVar9 <= (int)uVar7) goto LAB_40ae7aec;
    }
    if (iVar4 <= iVar9) {
      iVar9 = iVar4;
    }
    FUN_40af5ca4(&local_6c,*(int *)(local_54 + local_5c * 4));
    piVar10 = (int *)(local_58 + local_5c * 8);
    FUN_40aec0dc(&local_6c,local_6c,local_68,*piVar10,piVar10[1]);
    local_7c = local_6c + -1;
    local_70 = (int)((ulonglong)((longlong)local_68 * (longlong)(int)local_3c) >> 0x20) << 2;
    FUN_40aeb0ac(&local_70,&local_7c,0x3fffffff);
    if ((int)uVar7 < iVar9) {
      piVar12 = (int *)((int)local_48 + uVar7 * 4);
      piVar10 = (int *)(param_3 + uVar7 * 4);
      uVar8 = uVar7;
      do {
        iVar5 = FUN_40aeac3c(local_34);
        iVar4 = local_7c;
        lVar2 = (longlong)(int)local_70;
        local_90 = *piVar10 << (local_74 & 0x1f);
        local_78 = local_74 + 0x15;
        FUN_40aeb0ac(&local_90,local_38,0x3fffffff);
        uVar8 = uVar8 + 1;
        iVar4 = FUN_40aeb044((int)((ulonglong)
                                   ((longlong)((int)((ulonglong)(lVar2 * iVar5) >> 0x20) << 1) *
                                   (longlong)(int)local_90) >> 0x20) << 1,iVar4 + local_78 + -0x21,5
                            );
        *piVar12 = iVar4;
        piVar10 = piVar10 + 1;
        piVar12 = piVar12 + 1;
      } while ((int)uVar8 < iVar9);
      uVar7 = uVar7 + 1 + iVar9 + ~uVar7;
    }
    local_5c = local_5c + 1;
  }
LAB_40ae7aec:
  local_90 = *(uint *)(param_3 + (iVar9 + -1) * 4);
  local_78 = 0x15;
  FUN_40aeb0ac(&local_90,local_38,0x3fffffff);
  local_84 = (int)((ulonglong)((longlong)(int)local_88 * (longlong)(int)local_90) >> 0x20) << 1;
  local_7c = local_80 + local_78 + -0x1f;
  FUN_40aeb0ac(&local_84,&local_7c,0x3fffffff);
  local_7c = local_7c + 4;
  local_70 = (int)((ulonglong)((longlong)(int)local_84 * 0x51eb851f) >> 0x20) << 1;
  FUN_40aeb0ac(&local_70,&local_7c,0x3fffffff);
  if ((int)uVar7 < (int)*(short *)(param_2 + 0x1f)) {
    piVar10 = (int *)((int)local_48 + uVar7 * 4);
    do {
      iVar6 = FUN_40aeac3c(local_34);
      iVar6 = FUN_40aeb044((int)((ulonglong)((longlong)(int)local_70 * (longlong)iVar6) >> 0x20) <<
                           1,local_7c + -2,5);
      uVar7 = uVar7 + 1;
      sVar1 = *(short *)(param_2 + 0x1f);
      *piVar10 = iVar6;
      piVar10 = piVar10 + 1;
    } while ((int)uVar7 < (int)sVar1);
  }
  return 0;
}



/* 40ae7f68 FUN_40ae7f68 */

/* Boundary evidence: original MIPS .pdata 40ae7f68..40ae845f. Semantic name remains unreviewed. */

void FUN_40ae7f68(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_360 [103];
  int local_1c4 [101];
  undefined *local_30;
  
  local_360[0] = 0x40000000;
  local_360[2] = 0x40000000;
  local_360[3] = 0x8000000;
  local_360[4] = 0x8000000;
  if (param_5 < 1) {
    local_30 = &DAT_40b1366c;
  }
  else {
    iVar12 = 0;
    iVar11 = 2;
    local_30 = &DAT_40b1366c;
    piVar4 = local_360 + 6;
    do {
      local_360[1] = *(int *)(local_30 + (iVar12 * 0x10 + (uint)*(byte *)(param_2 + iVar12)) * 4);
      iVar10 = 0;
      piVar5 = local_1c4;
      piVar2 = local_360 + 3;
      do {
        *piVar5 = 0;
        iVar9 = 0;
        iVar6 = 0;
        piVar3 = piVar2;
        piVar7 = local_360;
        do {
          iVar6 = iVar6 + 1;
          iVar9 = iVar9 + ((int)((ulonglong)((longlong)*piVar3 * (longlong)*piVar7) >> 0x20) << 2 |
                          (uint)((longlong)*piVar3 * (longlong)*piVar7) >> 0x1e);
          piVar7 = piVar7 + 1;
          piVar3 = piVar3 + -1;
        } while (iVar6 <= iVar10);
        iVar10 = iVar10 + 1;
        *piVar5 = iVar9;
        if (iVar10 == 3) break;
        piVar5 = piVar5 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar10 < iVar11);
      iVar10 = iVar12 + 5 >> 1;
      if (3 < iVar10) {
        piVar2 = local_1c4 + 3;
        piVar5 = local_360 + 6;
        do {
          *piVar2 = 0;
          lVar1 = (longlong)local_360[1] * (longlong)piVar5[-1];
          *piVar2 = ((int)((ulonglong)((longlong)*piVar5 * 0x40000000) >> 0x20) << 2 |
                    (uint)((longlong)*piVar5 * 0x40000000) >> 0x1e) +
                    ((int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e) +
                    ((int)((ulonglong)((longlong)piVar5[-2] * 0x40000000) >> 0x20) << 2 |
                    (uint)((longlong)piVar5[-2] * 0x40000000) >> 0x1e);
          piVar2 = piVar2 + 1;
          piVar5 = piVar5 + 1;
        } while (piVar2 != local_1c4 + iVar10);
      }
      iVar11 = iVar11 + 2;
      iVar10 = 0;
      piVar5 = piVar4;
      do {
        iVar6 = *(int *)((int)local_1c4 + iVar10);
        piVar2 = (int *)((int)(local_360 + 3) + iVar10);
        iVar10 = iVar10 + 4;
        *piVar2 = iVar6;
        *piVar5 = iVar6;
        piVar5 = piVar5 + -1;
      } while (iVar10 != (iVar11 >> 1) << 2);
      iVar12 = iVar12 + 2;
      piVar4 = piVar4 + 2;
    } while (iVar12 < param_5);
  }
  iVar12 = param_5 / 2;
  iVar11 = 0;
  if (0 < iVar12) {
    do {
      iVar10 = iVar11 + 0x10;
      iVar6 = param_3 + iVar11;
      iVar11 = iVar11 + 4;
      *(undefined4 *)(iVar6 + 4) = *(undefined4 *)((int)local_360 + iVar10);
    } while (iVar11 != iVar12 << 2);
  }
  local_360[4] = *(int *)(local_30 + (*(byte *)(param_2 + 1) + 0x10) * 4) >> 3;
  local_360[5] = 0x8000000;
  local_360[3] = 0x8000000;
  if (3 < param_5) {
    piVar5 = local_360 + 7;
    iVar11 = 3;
    piVar4 = local_360 + 3;
    do {
      local_360[1] = *(int *)(local_30 + (iVar11 * 0x10 + (uint)*(byte *)(param_2 + iVar11)) * 4);
      iVar10 = 0;
      piVar2 = local_1c4;
      piVar3 = piVar4;
      do {
        *piVar2 = 0;
        iVar9 = 0;
        iVar6 = 0;
        piVar7 = piVar3;
        piVar8 = local_360;
        do {
          iVar6 = iVar6 + 1;
          iVar9 = iVar9 + ((int)((ulonglong)((longlong)*piVar7 * (longlong)*piVar8) >> 0x20) << 2 |
                          (uint)((longlong)*piVar7 * (longlong)*piVar8) >> 0x1e);
          piVar8 = piVar8 + 1;
          piVar7 = piVar7 + -1;
        } while (iVar6 <= iVar10);
        iVar10 = iVar10 + 1;
        *piVar2 = iVar9;
        piVar3 = piVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar10 != 3);
      iVar10 = iVar11 + 3 >> 1;
      if (3 < iVar10) {
        piVar3 = local_1c4 + 3;
        piVar2 = local_360 + 6;
        do {
          *piVar3 = 0;
          lVar1 = (longlong)local_360[1] * (longlong)piVar2[-1];
          *piVar3 = ((int)((ulonglong)((longlong)*piVar2 * 0x40000000) >> 0x20) << 2 |
                    (uint)((longlong)*piVar2 * 0x40000000) >> 0x1e) +
                    ((int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e) +
                    ((int)((ulonglong)((longlong)piVar2[-2] * 0x40000000) >> 0x20) << 2 |
                    (uint)((longlong)piVar2[-2] * 0x40000000) >> 0x1e);
          piVar3 = piVar3 + 1;
          piVar2 = piVar2 + 1;
        } while (piVar3 != local_1c4 + iVar10);
      }
      iVar11 = iVar11 + 2;
      iVar10 = iVar11 >> 1;
      iVar6 = 0;
      if (0 < iVar10) {
        piVar2 = piVar5;
        do {
          iVar9 = *(int *)((int)local_1c4 + iVar6);
          piVar3 = (int *)((int)piVar4 + iVar6);
          iVar6 = iVar6 + 4;
          *piVar3 = iVar9;
          *piVar2 = iVar9;
          piVar2 = piVar2 + -1;
        } while (iVar6 != iVar10 << 2);
      }
      piVar4[iVar10] = local_1c4[iVar10];
      piVar5 = piVar5 + 2;
    } while (iVar11 < param_5);
  }
  if (0 < iVar12) {
    piVar4 = local_360 + 3;
    piVar5 = piVar4 + iVar12;
    do {
      piVar2 = piVar4 + 1;
      iVar11 = *piVar4;
      piVar4 = piVar4 + 1;
      *(int *)(param_4 + 4) = *piVar2 - iVar11;
      param_4 = param_4 + 4;
    } while (piVar4 != piVar5);
  }
  return;
}



/* 40ae8460 FUN_40ae8460 */

/* Boundary evidence: original MIPS .pdata 40ae8460..40ae8507. Semantic name remains unreviewed. */

void FUN_40ae8460(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_70 [4];
  int local_6c [11];
  undefined1 auStack_40 [4];
  int local_3c [12];
  
  FUN_40ae7f68(param_1,param_2,(int)auStack_70,(int)auStack_40,param_4);
  if (0 < param_4 / 2) {
    piVar3 = param_3 + param_4 + -1;
    piVar6 = local_6c;
    piVar5 = local_3c;
    iVar4 = 1;
    do {
      iVar2 = *piVar6;
      iVar1 = *piVar5;
      iVar4 = iVar4 + 1;
      *param_3 = -(iVar1 >> 1) - (iVar2 >> 1);
      piVar6 = piVar6 + 1;
      *piVar3 = (iVar1 >> 1) - (iVar2 >> 1);
      piVar5 = piVar5 + 1;
      param_3 = param_3 + 1;
      piVar3 = piVar3 + -1;
    } while (iVar4 <= param_4 / 2);
  }
  return;
}



/* 40ae8508 FUN_40ae8508 */

/* WARNING: Removing unreachable block (ram,0x40ae8558) */

void FUN_40ae8508(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  byte *pbVar6;
  
  pbVar6 = &DAT_40b1b260;
  uVar3 = 0;
  do {
    while ((uVar3 & 0x80) == 0) {
      if ((uVar3 & 0x40) == 0) {
        if ((uVar3 & 0x20) == 0) {
          if ((uVar3 & 0x10) == 0) {
            if ((uVar3 & 8) == 0) {
              if ((uVar3 & 4) == 0) {
                if ((uVar3 & 2) == 0) {
                  bVar4 = 8;
                }
                else {
                  bVar4 = 6;
                }
              }
              else {
                bVar4 = 5;
              }
            }
            else {
              bVar4 = 4;
            }
          }
          else {
            bVar4 = 3;
          }
        }
        else {
          bVar4 = 2;
        }
      }
      else {
        bVar4 = 1;
      }
      bVar5 = bVar4;
      if ((uVar3 + 1 & 0x80) != 0) goto LAB_40ae85fc;
LAB_40ae856c:
      uVar2 = uVar3 + 1;
      cVar1 = '\x01';
      if (((((uVar2 & 0x40) == 0) && (cVar1 = '\x02', (uVar2 & 0x20) == 0)) &&
          (cVar1 = '\x03', (uVar2 & 0x10) == 0)) &&
         (((cVar1 = '\x04', (uVar2 & 8) == 0 && (cVar1 = '\x05', (uVar2 & 4) == 0)) &&
          ((cVar1 = '\x06', (uVar2 & 2) == 0 && (cVar1 = '\b', (uVar2 & 1) != 0)))))) {
        cVar1 = '\a';
      }
      uVar3 = uVar3 + 2;
      *pbVar6 = cVar1 << 4 | bVar4;
      pbVar6 = pbVar6 + 1;
      if (uVar3 == 0x100) {
        return;
      }
    }
    bVar5 = 0;
    bVar4 = 0;
    if ((uVar3 + 1 & 0x80) == 0) goto LAB_40ae856c;
LAB_40ae85fc:
    uVar3 = uVar3 + 2;
    *pbVar6 = bVar5;
    pbVar6 = pbVar6 + 1;
    if (uVar3 == 0x100) {
      return;
    }
  } while( true );
}



/* 40ae884c FUN_40ae884c */

/* Boundary evidence: original MIPS .pdata 40ae884c..40ae938f. Semantic name remains unreviewed. */

void FUN_40ae884c(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  lVar1 = (longlong)(param_6 - param_5) * (longlong)param_2[2];
  lVar2 = (longlong)(param_6 + param_5) * (longlong)param_2[3];
  iVar16 = ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e) +
           ((int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e);
  lVar1 = (longlong)(param_6 + param_5) * (longlong)param_2[2];
  lVar2 = (longlong)(param_6 - param_5) * (longlong)param_2[3];
  iVar15 = ((int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e) -
           ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e);
  uVar6 = (int)((ulonglong)((longlong)param_6 * (longlong)param_5) >> 0x20) << 2 |
          (uint)((longlong)param_6 * (longlong)param_5) >> 0x1e;
  iVar7 = uVar6 * 2;
  iVar8 = ((int)((ulonglong)((longlong)param_5 * (longlong)param_5) >> 0x20) << 2 |
          (uint)((longlong)param_5 * (longlong)param_5) >> 0x1e) * -2 + 0x40000000;
  iVar11 = iVar8 + uVar6 * -2;
  lVar1 = (longlong)iVar11 * (longlong)*param_2;
  lVar2 = (longlong)(iVar8 + iVar7) * (longlong)param_2[1];
  iVar18 = ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e) +
           ((int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e);
  lVar1 = (longlong)(iVar8 + iVar7) * (longlong)*param_2;
  lVar2 = (longlong)iVar11 * (longlong)param_2[1];
  iVar17 = ((int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e) -
           ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e);
  iVar11 = ((int)((ulonglong)((longlong)param_6 * (longlong)iVar7) >> 0x20) << 2 |
           (uint)((longlong)param_6 * (longlong)iVar7) >> 0x1e) +
           ((int)((ulonglong)((longlong)param_5 * (longlong)iVar8) >> 0x20) << 2 |
           (uint)((longlong)param_5 * (longlong)iVar8) >> 0x1e);
  iVar7 = ((int)((ulonglong)((longlong)param_6 * (longlong)iVar8) >> 0x20) << 2 |
          (uint)((longlong)param_6 * (longlong)iVar8) >> 0x1e) -
          ((int)((ulonglong)((longlong)param_5 * (longlong)iVar7) >> 0x20) << 2 |
          (uint)((longlong)param_5 * (longlong)iVar7) >> 0x1e);
  iVar8 = iVar7 + iVar11;
  iVar7 = iVar7 - iVar11;
  lVar1 = (longlong)iVar7 * (longlong)param_2[4];
  lVar2 = (longlong)iVar8 * (longlong)param_2[5];
  iVar14 = ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e) +
           ((int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e);
  lVar1 = (longlong)iVar8 * (longlong)param_2[4];
  lVar2 = (longlong)iVar7 * (longlong)param_2[5];
  iVar13 = param_2[6] - param_2[7];
  iVar7 = param_2[7] + param_2[6];
  iVar12 = ((int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e) -
           ((int)((ulonglong)lVar2 >> 0x20) << 2 | (uint)lVar2 >> 0x1e);
  iVar8 = iVar16 + iVar18 + iVar7 + iVar14;
  iVar11 = iVar15 + iVar17 + iVar13 + iVar12;
  uVar4 = iVar8 >> 1;
  uVar6 = iVar11 >> 1;
  uVar3 = (iVar11 >> 0x1f) * uVar6 * 2 + (int)((ulonglong)uVar6 * (ulonglong)uVar6 >> 0x20);
  uVar5 = (iVar8 >> 0x1f) * uVar4 * 2 + (int)((ulonglong)uVar4 * (ulonglong)uVar4 >> 0x20);
  uVar9 = uVar3 * 0x1000 | (uint)((ulonglong)uVar6 * (ulonglong)uVar6) >> 0x14;
  uVar6 = uVar9 + (uVar5 * 0x1000 | (uint)((ulonglong)uVar4 * (ulonglong)uVar4) >> 0x14);
  uVar3 = (uint)(uVar6 < uVar9) + (uVar3 >> 0x14) + (uVar5 >> 0x14);
  if (uVar3 == 0) {
    if (uVar6 != 0) {
      iVar11 = 0x20;
      iVar8 = 0x21;
      uVar4 = uVar6;
      goto LAB_40ae8c70;
    }
    uVar10 = 0xffffffff;
  }
  else {
    iVar11 = 0;
    iVar8 = 1;
    uVar4 = uVar3;
LAB_40ae8c70:
    if ((uVar4 & 0xff000000) == 0) {
      do {
        iVar8 = iVar11;
        uVar4 = uVar4 << 8;
        iVar11 = iVar8 + 8;
      } while ((uVar4 & 0xff000000) == 0);
      iVar8 = iVar8 + 9;
    }
    iVar8 = ((int)(uint)(byte)(&DAT_40b1b260)[uVar4 >> 0x19] >> ((uVar4 >> 0x18 & 1) << 2) & 0xfU) +
            iVar8;
    if (iVar8 < 0x21) {
      uVar5 = 0x20 - iVar8;
      uVar4 = uVar3 >> (uVar5 & 0x1f);
      if ((uVar5 & 0x20) == 0) {
        uVar4 = uVar3 * 2 << (~uVar5 & 0x1f) | uVar6 >> (uVar5 & 0x1f);
      }
    }
    else {
      uVar4 = uVar6 << (iVar8 - 0x20U & 0x1f);
      if ((iVar8 - 0x20U & 0x20) != 0) {
        uVar4 = 0;
      }
    }
    uVar10 = (undefined4)
             ((ulonglong)
              (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                    (int)((ulonglong)
                          (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                                (&DAT_40b1016c)[(uVar4 >> 0x18) + 1]) * (ulonglong)(uVar4 << 8) >>
                         0x20)) * (ulonglong)*(uint *)(&DAT_40b10570 + iVar8 * 4) >> 0x20);
  }
  iVar8 = ((iVar15 - iVar18) - iVar12) + iVar7;
  iVar11 = ((iVar16 + iVar17) - iVar13) - iVar14;
  uVar4 = iVar8 >> 1;
  uVar6 = iVar11 >> 1;
  uVar3 = (iVar11 >> 0x1f) * uVar6 * 2 + (int)((ulonglong)uVar6 * (ulonglong)uVar6 >> 0x20);
  uVar5 = (iVar8 >> 0x1f) * uVar4 * 2 + (int)((ulonglong)uVar4 * (ulonglong)uVar4 >> 0x20);
  uVar9 = uVar3 * 0x1000 | (uint)((ulonglong)uVar6 * (ulonglong)uVar6) >> 0x14;
  uVar6 = uVar9 + (uVar5 * 0x1000 | (uint)((ulonglong)uVar4 * (ulonglong)uVar4) >> 0x14);
  uVar3 = (uint)(uVar6 < uVar9) + (uVar3 >> 0x14) + (uVar5 >> 0x14);
  *(undefined4 *)(param_3 + param_1 * 4) = uVar10;
  if (uVar3 == 0) {
    if (uVar6 != 0) {
      iVar11 = 0x20;
      iVar8 = 0x21;
      uVar4 = uVar6;
      goto LAB_40ae8e34;
    }
    uVar10 = 0xffffffff;
  }
  else {
    iVar11 = 0;
    iVar8 = 1;
    uVar4 = uVar3;
LAB_40ae8e34:
    if ((uVar4 & 0xff000000) == 0) {
      do {
        iVar8 = iVar11;
        uVar4 = uVar4 << 8;
        iVar11 = iVar8 + 8;
      } while ((uVar4 & 0xff000000) == 0);
      iVar8 = iVar8 + 9;
    }
    iVar8 = ((int)(uint)(byte)(&DAT_40b1b260)[uVar4 >> 0x19] >> ((uVar4 >> 0x18 & 1) << 2) & 0xfU) +
            iVar8;
    if (iVar8 < 0x21) {
      uVar5 = 0x20 - iVar8;
      uVar4 = uVar3 >> (uVar5 & 0x1f);
      if ((uVar5 & 0x20) == 0) {
        uVar4 = uVar3 * 2 << (~uVar5 & 0x1f) | uVar6 >> (uVar5 & 0x1f);
      }
    }
    else {
      uVar4 = uVar6 << (iVar8 - 0x20U & 0x1f);
      if ((iVar8 - 0x20U & 0x20) != 0) {
        uVar4 = 0;
      }
    }
    uVar10 = (undefined4)
             ((ulonglong)
              (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                    (int)((ulonglong)
                          (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                                (&DAT_40b1016c)[(uVar4 >> 0x18) + 1]) * (ulonglong)(uVar4 << 8) >>
                         0x20)) * (ulonglong)*(uint *)(&DAT_40b10570 + iVar8 * 4) >> 0x20);
  }
  iVar8 = ((iVar12 + iVar7) - iVar18) - iVar15;
  iVar11 = ((iVar16 - iVar17) - iVar14) + iVar13;
  uVar4 = iVar8 >> 1;
  uVar6 = iVar11 >> 1;
  uVar3 = (iVar11 >> 0x1f) * uVar6 * 2 + (int)((ulonglong)uVar6 * (ulonglong)uVar6 >> 0x20);
  uVar5 = (iVar8 >> 0x1f) * uVar4 * 2 + (int)((ulonglong)uVar4 * (ulonglong)uVar4 >> 0x20);
  uVar9 = uVar3 * 0x1000 | (uint)((ulonglong)uVar6 * (ulonglong)uVar6) >> 0x14;
  uVar6 = uVar9 + (uVar5 * 0x1000 | (uint)((ulonglong)uVar4 * (ulonglong)uVar4) >> 0x14);
  uVar3 = (uint)(uVar6 < uVar9) + (uVar3 >> 0x14) + (uVar5 >> 0x14);
  *(undefined4 *)(param_3 + (param_4 - param_1) * 4) = uVar10;
  if (uVar3 == 0) {
    if (uVar6 == 0) {
      uVar10 = 0xffffffff;
      goto LAB_40ae90ac;
    }
    iVar11 = 0x20;
    iVar8 = 0x21;
    uVar4 = uVar6;
  }
  else {
    iVar11 = 0;
    iVar8 = 1;
    uVar4 = uVar3;
  }
  if ((uVar4 & 0xff000000) == 0) {
    do {
      iVar8 = iVar11;
      uVar4 = uVar4 << 8;
      iVar11 = iVar8 + 8;
    } while ((uVar4 & 0xff000000) == 0);
    iVar8 = iVar8 + 9;
  }
  iVar8 = ((int)(uint)(byte)(&DAT_40b1b260)[uVar4 >> 0x19] >> ((uVar4 >> 0x18 & 1) << 2) & 0xfU) +
          iVar8;
  if (iVar8 < 0x21) {
    uVar5 = 0x20 - iVar8;
    uVar4 = uVar3 >> (uVar5 & 0x1f);
    if ((uVar5 & 0x20) == 0) {
      uVar4 = uVar3 * 2 << (~uVar5 & 0x1f) | uVar6 >> (uVar5 & 0x1f);
    }
  }
  else {
    uVar4 = uVar6 << (iVar8 - 0x20U & 0x1f);
    if ((iVar8 - 0x20U & 0x20) != 0) {
      uVar4 = 0;
    }
  }
  uVar10 = (undefined4)
           ((ulonglong)
            (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                  (int)((ulonglong)
                        (uint)((&DAT_40b1016c)[uVar4 >> 0x18] - (&DAT_40b1016c)[(uVar4 >> 0x18) + 1]
                              ) * (ulonglong)(uVar4 << 8) >> 0x20)) *
            (ulonglong)*(uint *)(&DAT_40b10570 + iVar8 * 4) >> 0x20);
LAB_40ae90ac:
  iVar17 = ((iVar15 + iVar12) - iVar13) - iVar17;
  iVar7 = ((iVar18 - iVar16) - iVar14) + iVar7;
  uVar4 = iVar17 >> 1;
  uVar6 = iVar7 >> 1;
  uVar3 = (iVar7 >> 0x1f) * uVar6 * 2 + (int)((ulonglong)uVar6 * (ulonglong)uVar6 >> 0x20);
  uVar5 = (iVar17 >> 0x1f) * uVar4 * 2 + (int)((ulonglong)uVar4 * (ulonglong)uVar4 >> 0x20);
  uVar9 = uVar3 * 0x1000 | (uint)((ulonglong)uVar6 * (ulonglong)uVar6) >> 0x14;
  uVar6 = uVar9 + (uVar5 * 0x1000 | (uint)((ulonglong)uVar4 * (ulonglong)uVar4) >> 0x14);
  uVar3 = (uint)(uVar6 < uVar9) + (uVar3 >> 0x14) + (uVar5 >> 0x14);
  *(undefined4 *)(param_3 + (param_4 + param_1) * 4) = uVar10;
  if (uVar3 == 0) {
    if (uVar6 == 0) {
      *(undefined4 *)(param_3 + (param_4 * 2 - param_1) * 4) = 0xffffffff;
      return;
    }
    iVar11 = 0x20;
    iVar7 = 0x21;
    uVar4 = uVar6;
  }
  else {
    iVar11 = 0;
    iVar7 = 1;
    uVar4 = uVar3;
  }
  if ((uVar4 & 0xff000000) == 0) {
    do {
      iVar7 = iVar11;
      uVar4 = uVar4 << 8;
      iVar11 = iVar7 + 8;
    } while ((uVar4 & 0xff000000) == 0);
    iVar7 = iVar7 + 9;
  }
  iVar7 = ((int)(uint)(byte)(&DAT_40b1b260)[uVar4 >> 0x19] >> ((uVar4 >> 0x18 & 1) << 2) & 0xfU) +
          iVar7;
  if (iVar7 < 0x21) {
    uVar5 = 0x20 - iVar7;
    uVar4 = uVar3 >> (uVar5 & 0x1f);
    if ((uVar5 & 0x20) == 0) {
      uVar4 = uVar3 * 2 << (~uVar5 & 0x1f) | uVar6 >> (uVar5 & 0x1f);
    }
  }
  else {
    uVar4 = uVar6 << (iVar7 - 0x20U & 0x1f);
    if ((iVar7 - 0x20U & 0x20) != 0) {
      uVar4 = 0;
    }
  }
  *(int *)(param_3 + (param_4 * 2 - param_1) * 4) =
       (int)((ulonglong)
             (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                   (int)((ulonglong)
                         (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                               (&DAT_40b1016c)[(uVar4 >> 0x18) + 1]) * (ulonglong)(uVar4 << 8) >>
                        0x20)) * (ulonglong)*(uint *)(&DAT_40b10570 + iVar7 * 4) >> 0x20);
  return;
}



/* 40ae9390 FUN_40ae9390 */

/* Boundary evidence: original MIPS .pdata 40ae9390..40aea73b. Semantic name remains unreviewed. */

undefined4 FUN_40ae9390(int param_1,int *param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  uint *local_74;
  uint local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
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
  uint local_30;
  
  local_74 = *(uint **)(param_3 + 0x38);
  if (*(int *)(param_1 + 0xd4) == 0) {
    iVar21 = *(int *)(param_1 + 0xfc);
  }
  else {
    iVar21 = (int)*(short *)(param_3 + 0x7c);
  }
  if (iVar21 == 0) {
    trap(7);
  }
  local_34 = -(param_2[7] >> 2);
  local_4c = -(param_2[8] >> 2);
  local_dc = param_2[5] >> 2;
  local_cc = param_2[6] >> 2;
  local_48 = -(*param_2 >> 2);
  local_50 = -(param_2[4] >> 2);
  local_44 = -local_dc;
  local_58 = -local_cc;
  iVar8 = param_2[2] >> 2;
  local_c4 = param_2[3] >> 2;
  local_38 = -local_c4;
  local_3c = -(param_2[9] >> 2);
  local_40 = -(param_2[1] >> 2);
  local_ec = -iVar8;
  local_e8 = local_34 + 0x2000000;
  local_78 = iVar21 >> 1;
  local_7c = iVar21 >> 2;
  local_80 = iVar21 >> 3;
  local_84 = iVar21 >> 4;
  local_70 = (int)((ulonglong)((longlong)local_38 * 0x5a827998) >> 0x20) << 2 |
             (uint)((longlong)local_38 * 0x5a827998) >> 0x1e;
  local_e4 = (param_2[7] >> 2) + 0x2000000;
  iVar20 = local_3c + local_40;
  uVar22 = (int)((ulonglong)((longlong)local_44 * 0x5a827998) >> 0x20) << 2 |
           (uint)((longlong)local_44 * 0x5a827998) >> 0x1e;
  iVar16 = local_4c + local_48;
  local_fc = local_40 + (param_2[9] >> 2);
  uVar14 = (int)((ulonglong)((longlong)local_50 * 0x5a827998) >> 0x20) << 2 |
           (uint)((longlong)local_50 * 0x5a827998) >> 0x1e;
  local_f4 = local_48 + (param_2[8] >> 2);
  uVar10 = (int)((ulonglong)((longlong)local_58 * 0x5a827998) >> 0x20) << 2 |
           (uint)((longlong)local_58 * 0x5a827998) >> 0x1e;
  local_60 = local_50 + local_cc;
  local_6c = iVar20 + local_44;
  local_64 = local_e8 + local_38;
  local_68 = local_e8 + local_c4;
  lVar1 = (longlong)((iVar16 - local_60) + iVar8) * 0x2d413ccc;
  local_9c = (int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e;
  lVar1 = (longlong)((iVar16 + local_ec) - (local_58 + local_50)) * 0x2d413ccc;
  local_a0 = (int)((ulonglong)lVar1 >> 0x20) << 2 | (uint)lVar1 >> 0x1e;
  uVar2 = iVar16 + local_58 + local_50 + local_ec + local_64 + local_6c;
  uVar4 = ((int)uVar2 >> 0x1f) * uVar2 * 2 + (int)((ulonglong)uVar2 * (ulonglong)uVar2 >> 0x20);
  uVar7 = uVar4 >> 0x14;
  uVar2 = uVar4 * 0x1000 | (uint)((ulonglong)uVar2 * (ulonglong)uVar2) >> 0x14;
  if (uVar7 == 0) {
    if (uVar2 != 0) {
      iVar5 = 0x20;
      iVar9 = 0x21;
      uVar4 = uVar2;
      goto LAB_40ae9708;
    }
    local_30 = 0xffffffff;
  }
  else {
    iVar5 = 0;
    iVar9 = 1;
    uVar4 = uVar7;
LAB_40ae9708:
    if ((uVar4 & 0xff000000) == 0) {
      do {
        iVar9 = iVar5;
        uVar4 = uVar4 << 8;
        iVar5 = iVar9 + 8;
      } while ((uVar4 & 0xff000000) == 0);
      iVar9 = iVar9 + 9;
    }
    iVar9 = ((int)(uint)(byte)(&DAT_40b1b260)[uVar4 >> 0x19] >> ((uVar4 >> 0x18 & 1) << 2) & 0xfU) +
            iVar9;
    if (iVar9 < 0x21) {
      uVar3 = 0x20 - iVar9;
      uVar4 = uVar7 >> (uVar3 & 0x1f);
      if ((uVar3 & 0x20) == 0) {
        uVar4 = (uVar7 << 1) << (~uVar3 & 0x1f) | uVar2 >> (uVar3 & 0x1f);
      }
    }
    else {
      uVar4 = uVar2 << (iVar9 - 0x20U & 0x1f);
      if ((iVar9 - 0x20U & 0x20) != 0) {
        uVar4 = 0;
      }
    }
    local_30 = (uint)((ulonglong)
                      (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                            (int)((ulonglong)
                                  (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                                        (&DAT_40b1016c)[(uVar4 >> 0x18) + 1]) *
                                  (ulonglong)(uVar4 << 8) >> 0x20)) *
                      (ulonglong)*(uint *)(&DAT_40b10570 + iVar9 * 4) >> 0x20);
  }
  uVar2 = iVar20 + local_dc + local_a0;
  uVar7 = local_9c + local_68;
  uVar4 = ((int)uVar2 >> 0x1f) * uVar2 * 2 + (int)((ulonglong)uVar2 * (ulonglong)uVar2 >> 0x20);
  uVar3 = ((int)uVar7 >> 0x1f) * uVar7 * 2 + (int)((ulonglong)uVar7 * (ulonglong)uVar7 >> 0x20);
  uVar2 = uVar4 * 0x1000 | (uint)((ulonglong)uVar2 * (ulonglong)uVar2) >> 0x14;
  uVar7 = uVar2 + (uVar3 * 0x1000 | (uint)((ulonglong)uVar7 * (ulonglong)uVar7) >> 0x14);
  local_a4 = local_e8 - local_70;
  uVar2 = (uint)(uVar7 < uVar2) + (uVar4 >> 0x14) + (uVar3 >> 0x14);
  local_e8 = local_70 + local_e8;
  local_b4 = iVar16 - uVar14;
  local_f8 = uVar14 + iVar16;
  local_ac = local_ec - uVar10;
  local_bc = iVar20 - uVar22;
  local_c8 = local_e4 + local_38;
  local_100 = uVar22 + iVar20;
  local_c4 = local_e4 + local_c4;
  local_e0 = local_fc + local_44;
  local_d8 = local_f4 + local_50;
  local_f0 = uVar10 + local_ec;
  local_dc = local_fc + local_dc;
  local_d0 = local_58 + local_ec;
  local_d4 = local_f4 + (param_2[4] >> 2);
  local_cc = local_ec + local_cc;
  puVar11 = local_74 + local_7c;
  *local_74 = local_30;
  if (uVar2 == 0) {
    if (uVar7 != 0) {
      iVar5 = 0x20;
      iVar9 = 0x21;
      uVar4 = uVar7;
      goto LAB_40ae999c;
    }
    uVar2 = 0xffffffff;
  }
  else {
    iVar5 = 0;
    iVar9 = 1;
    uVar4 = uVar2;
LAB_40ae999c:
    if ((uVar4 & 0xff000000) == 0) {
      do {
        iVar9 = iVar5;
        uVar4 = uVar4 << 8;
        iVar5 = iVar9 + 8;
      } while ((uVar4 & 0xff000000) == 0);
      iVar9 = iVar9 + 9;
    }
    iVar9 = ((int)(uint)(byte)(&DAT_40b1b260)[uVar4 >> 0x19] >> ((uVar4 >> 0x18 & 1) << 2) & 0xfU) +
            iVar9;
    if (iVar9 < 0x21) {
      uVar10 = 0x20 - iVar9;
      uVar4 = uVar2 >> (uVar10 & 0x1f);
      if ((uVar10 & 0x20) == 0) {
        uVar4 = uVar2 * 2 << (~uVar10 & 0x1f) | uVar7 >> (uVar10 & 0x1f);
      }
    }
    else {
      uVar4 = uVar7 << (iVar9 - 0x20U & 0x1f);
      if ((iVar9 - 0x20U & 0x20) != 0) {
        uVar4 = 0;
      }
    }
    uVar2 = (uint)((ulonglong)
                   (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                         (int)((ulonglong)
                               (uint)((&DAT_40b1016c)[uVar4 >> 0x18] -
                                     (&DAT_40b1016c)[(uVar4 >> 0x18) + 1]) * (ulonglong)(uVar4 << 8)
                              >> 0x20)) * (ulonglong)*(uint *)(&DAT_40b10570 + iVar9 * 4) >> 0x20);
  }
  uVar10 = local_64 - local_6c;
  uVar4 = iVar16 + iVar8 + local_60;
  uVar7 = ((int)uVar4 >> 0x1f) * uVar4 * 2 + (int)((ulonglong)uVar4 * (ulonglong)uVar4 >> 0x20);
  uVar14 = ((int)uVar10 >> 0x1f) * uVar10 * 2 + (int)((ulonglong)uVar10 * (ulonglong)uVar10 >> 0x20)
  ;
  uVar4 = uVar7 * 0x1000 | (uint)((ulonglong)uVar4 * (ulonglong)uVar4) >> 0x14;
  uVar10 = uVar4 + (uVar14 * 0x1000 | (uint)((ulonglong)uVar10 * (ulonglong)uVar10) >> 0x14);
  uVar4 = (uint)(uVar10 < uVar4) + (uVar7 >> 0x14) + (uVar14 >> 0x14);
  *puVar11 = uVar2;
  if (uVar4 == 0) {
    if (uVar10 != 0) {
      iVar8 = 0x20;
      iVar16 = 0x21;
      uVar2 = uVar10;
      goto LAB_40ae9b30;
    }
    uVar2 = 0xffffffff;
  }
  else {
    iVar8 = 0;
    iVar16 = 1;
    uVar2 = uVar4;
LAB_40ae9b30:
    if ((uVar2 & 0xff000000) == 0) {
      do {
        iVar16 = iVar8;
        uVar2 = uVar2 << 8;
        iVar8 = iVar16 + 8;
      } while ((uVar2 & 0xff000000) == 0);
      iVar16 = iVar16 + 9;
    }
    iVar16 = ((int)(uint)(byte)(&DAT_40b1b260)[uVar2 >> 0x19] >> ((uVar2 >> 0x18 & 1) << 2) & 0xfU)
             + iVar16;
    if (iVar16 < 0x21) {
      uVar7 = 0x20 - iVar16;
      uVar2 = uVar4 >> (uVar7 & 0x1f);
      if ((uVar7 & 0x20) == 0) {
        uVar2 = uVar4 * 2 << (~uVar7 & 0x1f) | uVar10 >> (uVar7 & 0x1f);
      }
    }
    else {
      uVar2 = uVar10 << (iVar16 - 0x20U & 0x1f);
      if ((iVar16 - 0x20U & 0x20) != 0) {
        uVar2 = 0;
      }
    }
    uVar2 = (uint)((ulonglong)
                   (uint)((&DAT_40b1016c)[uVar2 >> 0x18] -
                         (int)((ulonglong)
                               (uint)((&DAT_40b1016c)[uVar2 >> 0x18] -
                                     (&DAT_40b1016c)[(uVar2 >> 0x18) + 1]) * (ulonglong)(uVar2 << 8)
                              >> 0x20)) * (ulonglong)*(uint *)(&DAT_40b10570 + iVar16 * 4) >> 0x20);
  }
  uVar10 = local_68 - local_9c;
  uVar4 = (local_44 - iVar20) + local_a0;
  uVar7 = ((int)uVar4 >> 0x1f) * uVar4 * 2 + (int)((ulonglong)uVar4 * (ulonglong)uVar4 >> 0x20);
  uVar14 = ((int)uVar10 >> 0x1f) * uVar10 * 2 + (int)((ulonglong)uVar10 * (ulonglong)uVar10 >> 0x20)
  ;
  uVar22 = uVar7 * 0x1000 | (uint)((ulonglong)uVar4 * (ulonglong)uVar4) >> 0x14;
  uVar4 = uVar22 + (uVar14 * 0x1000 | (uint)((ulonglong)uVar10 * (ulonglong)uVar10) >> 0x14);
  uVar7 = (uint)(uVar4 < uVar22) + (uVar7 >> 0x14) + (uVar14 >> 0x14);
  puVar11[local_7c] = uVar2;
  if (uVar7 == 0) {
    if (uVar4 == 0) {
      uVar2 = 0xffffffff;
      goto LAB_40ae9d98;
    }
    iVar8 = 0x20;
    iVar16 = 0x21;
    uVar2 = uVar4;
  }
  else {
    iVar8 = 0;
    iVar16 = 1;
    uVar2 = uVar7;
  }
  if ((uVar2 & 0xff000000) == 0) {
    do {
      iVar16 = iVar8;
      uVar2 = uVar2 << 8;
      iVar8 = iVar16 + 8;
    } while ((uVar2 & 0xff000000) == 0);
    iVar16 = iVar16 + 9;
  }
  iVar16 = ((int)(uint)(byte)(&DAT_40b1b260)[uVar2 >> 0x19] >> ((uVar2 >> 0x18 & 1) << 2) & 0xfU) +
           iVar16;
  if (iVar16 < 0x21) {
    uVar10 = 0x20 - iVar16;
    uVar2 = uVar7 >> (uVar10 & 0x1f);
    if ((uVar10 & 0x20) == 0) {
      uVar2 = uVar7 * 2 << (~uVar10 & 0x1f) | uVar4 >> (uVar10 & 0x1f);
    }
  }
  else {
    uVar2 = uVar4 << (iVar16 - 0x20U & 0x1f);
    if ((iVar16 - 0x20U & 0x20) != 0) {
      uVar2 = 0;
    }
  }
  uVar2 = (uint)((ulonglong)
                 (uint)((&DAT_40b1016c)[uVar2 >> 0x18] -
                       (int)((ulonglong)
                             (uint)((&DAT_40b1016c)[uVar2 >> 0x18] -
                                   (&DAT_40b1016c)[(uVar2 >> 0x18) + 1]) * (ulonglong)(uVar2 << 8)
                            >> 0x20)) * (ulonglong)*(uint *)(&DAT_40b10570 + iVar16 * 4) >> 0x20);
LAB_40ae9d98:
  (puVar11 + local_7c)[local_7c] = uVar2;
  local_c0 = local_fc;
  local_b8 = local_f4;
  local_b0 = local_ec;
  local_a8 = local_e4;
  local_54 = local_ec;
  FUN_40ae884c(local_84,&local_100,(int)local_74,local_78,0xc7c5c1e,0x3ec52f9e);
  FUN_40ae884c(local_80,&local_e0,(int)local_74,local_78,0x187de2a6,0x3b20d79d);
  FUN_40ae884c(local_84 + local_80,&local_c0,(int)local_74,local_78,0x238e7672,0x3536cc51);
  puVar6 = (&PTR_DAT_40b10fb4)[iVar21 >> 7];
  local_98 = *(int *)(puVar6 + 0x28) >> 1;
  local_8c = *(int *)(puVar6 + 0x2c) << 1;
  if (1 < local_84) {
    local_5c = 1;
    local_90 = 0;
    local_94 = 0x40000000;
    iVar21 = 0x40000000;
    iVar8 = 0;
    iVar16 = *(int *)(puVar6 + 0x14) >> 1;
    iVar20 = *(int *)(puVar6 + 0x10) >> 1;
    iVar5 = *(int *)(puVar6 + 0x2c);
    local_88 = *(int *)(puVar6 + 0x30);
    do {
      iVar19 = iVar20;
      iVar18 = iVar16;
      iVar13 = iVar5 - local_88;
      iVar12 = local_88 + iVar5;
      iVar20 = ((int)((ulonglong)((longlong)local_88 * (longlong)iVar5) >> 0x20) << 2 |
               (uint)((longlong)local_88 * (longlong)iVar5) >> 0x1e) * 2;
      iVar16 = ((int)((ulonglong)((longlong)iVar5 * (longlong)iVar5) >> 0x20) << 2 |
               (uint)((longlong)iVar5 * (longlong)iVar5) >> 0x1e) * -2 + 0x40000000;
      iVar9 = iVar16 + iVar20;
      iVar20 = iVar20 - iVar16;
      iVar17 = iVar21 - ((int)((ulonglong)((longlong)local_8c * (longlong)iVar5) >> 0x20) << 2 |
                        (uint)((longlong)local_8c * (longlong)iVar5) >> 0x1e);
      iVar15 = iVar8 + ((int)((ulonglong)((longlong)local_8c * (longlong)local_88) >> 0x20) << 2 |
                       (uint)((longlong)local_8c * (longlong)local_88) >> 0x1e);
      uVar2 = (int)((ulonglong)((longlong)iVar9 * (longlong)local_34) >> 0x20) << 2 |
              (uint)((longlong)iVar9 * (longlong)local_34) >> 0x1e;
      local_a4 = uVar2 + 0x2000000;
      uVar7 = (int)((ulonglong)((longlong)iVar12 * (longlong)local_38) >> 0x20) << 2 |
              (uint)((longlong)iVar12 * (longlong)local_38) >> 0x1e;
      local_108 = local_a4 + uVar7;
      uVar4 = (int)((ulonglong)((longlong)iVar20 * (longlong)local_34) >> 0x20) << 2 |
              (uint)((longlong)iVar20 * (longlong)local_34) >> 0x1e;
      local_c4 = uVar4 + 0x2000000;
      local_e8 = local_c4 + uVar7;
      local_c8 = 0x2000000 - uVar2;
      uVar2 = (int)((ulonglong)((longlong)iVar13 * (longlong)local_38) >> 0x20) << 2 |
              (uint)((longlong)iVar13 * (longlong)local_38) >> 0x1e;
      local_a8 = 0x2000000 - uVar4;
      local_104 = local_a8 - uVar2;
      local_e4 = local_c8 + uVar2;
      local_c4 = local_c4 - uVar7;
      local_a4 = local_a4 - uVar7;
      local_c8 = local_c8 - uVar2;
      local_a8 = local_a8 + uVar2;
      uVar2 = (int)((ulonglong)((longlong)iVar9 * (longlong)local_3c) >> 0x20) << 2 |
              (uint)((longlong)iVar9 * (longlong)local_3c) >> 0x1e;
      local_bc = uVar2 + local_40;
      uVar7 = (int)((ulonglong)((longlong)iVar12 * (longlong)local_44) >> 0x20) << 2 |
              (uint)((longlong)iVar12 * (longlong)local_44) >> 0x1e;
      local_120 = local_bc + uVar7;
      uVar4 = (int)((ulonglong)((longlong)iVar20 * (longlong)local_3c) >> 0x20) << 2 |
              (uint)((longlong)iVar20 * (longlong)local_3c) >> 0x1e;
      local_dc = uVar4 + local_40;
      local_100 = local_dc + uVar7;
      local_e0 = local_40 - uVar2;
      uVar2 = (int)((ulonglong)((longlong)iVar13 * (longlong)local_44) >> 0x20) << 2 |
              (uint)((longlong)iVar13 * (longlong)local_44) >> 0x1e;
      local_c0 = local_40 - uVar4;
      local_11c = local_c0 - uVar2;
      local_fc = local_e0 + uVar2;
      local_c0 = local_c0 + uVar2;
      local_dc = local_dc - uVar7;
      local_bc = local_bc - uVar7;
      local_e0 = local_e0 - uVar2;
      uVar2 = (int)((ulonglong)((longlong)iVar9 * (longlong)local_4c) >> 0x20) << 2 |
              (uint)((longlong)iVar9 * (longlong)local_4c) >> 0x1e;
      local_b4 = uVar2 + local_48;
      uVar7 = (int)((ulonglong)((longlong)iVar12 * (longlong)local_50) >> 0x20) << 2 |
              (uint)((longlong)iVar12 * (longlong)local_50) >> 0x1e;
      local_118 = local_b4 + uVar7;
      uVar4 = (int)((ulonglong)((longlong)iVar20 * (longlong)local_4c) >> 0x20) << 2 |
              (uint)((longlong)iVar20 * (longlong)local_4c) >> 0x1e;
      local_d4 = uVar4 + local_48;
      local_f8 = local_d4 + uVar7;
      local_d8 = local_48 - uVar2;
      uVar2 = (int)((ulonglong)((longlong)iVar13 * (longlong)local_50) >> 0x20) << 2 |
              (uint)((longlong)iVar13 * (longlong)local_50) >> 0x1e;
      local_b8 = local_48 - uVar4;
      local_114 = local_b8 - uVar2;
      local_f4 = local_d8 + uVar2;
      local_d4 = local_d4 - uVar7;
      local_b4 = local_b4 - uVar7;
      local_d8 = local_d8 - uVar2;
      local_b8 = local_b8 + uVar2;
      uVar4 = (int)((ulonglong)((longlong)iVar12 * (longlong)local_58) >> 0x20) << 2 |
              (uint)((longlong)iVar12 * (longlong)local_58) >> 0x1e;
      local_110 = uVar4 + local_54;
      uVar2 = (int)((ulonglong)((longlong)iVar13 * (longlong)local_58) >> 0x20) << 2 |
              (uint)((longlong)iVar13 * (longlong)local_58) >> 0x1e;
      local_ec = uVar2 + local_54;
      local_cc = local_54 - uVar4;
      local_10c = local_54 - uVar2;
      local_f0 = local_110;
      local_d0 = local_10c;
      local_b0 = local_ec;
      local_ac = local_cc;
      FUN_40ae884c(local_5c,&local_120,(int)local_74,local_78,iVar19,iVar18);
      uVar10 = (int)((ulonglong)((longlong)iVar18 * 0x187de2a6) >> 0x20) << 2 |
               (uint)((longlong)iVar18 * 0x187de2a6) >> 0x1e;
      uVar7 = (int)((ulonglong)((longlong)iVar19 * 0x3b20d79d) >> 0x20) << 2 |
              (uint)((longlong)iVar19 * 0x3b20d79d) >> 0x1e;
      uVar2 = (int)((ulonglong)((longlong)iVar18 * 0x3b20d79d) >> 0x20) << 2 |
              (uint)((longlong)iVar18 * 0x3b20d79d) >> 0x1e;
      uVar4 = (int)((ulonglong)((longlong)iVar19 * 0x187de2a6) >> 0x20) << 2 |
              (uint)((longlong)iVar19 * 0x187de2a6) >> 0x1e;
      FUN_40ae884c(local_80 - local_5c,&local_100,(int)local_74,local_78,uVar10 - uVar7,
                   uVar4 + uVar2);
      FUN_40ae884c(local_5c + local_80,&local_e0,(int)local_74,local_78,uVar7 + uVar10,uVar2 - uVar4
                  );
      FUN_40ae884c(local_7c - local_5c,&local_c0,(int)local_74,local_78,
                   ((int)((ulonglong)((longlong)iVar18 * 0x2d413ccc) >> 0x20) << 2 |
                   (uint)((longlong)iVar18 * 0x2d413ccc) >> 0x1e) -
                   ((int)((ulonglong)((longlong)iVar19 * 0x2d413ccc) >> 0x20) << 2 |
                   (uint)((longlong)iVar19 * 0x2d413ccc) >> 0x1e),
                   ((int)((ulonglong)((longlong)iVar19 * 0x2d413ccc) >> 0x20) << 2 |
                   (uint)((longlong)iVar19 * 0x2d413ccc) >> 0x1e) +
                   ((int)((ulonglong)((longlong)iVar18 * 0x2d413ccc) >> 0x20) << 2 |
                   (uint)((longlong)iVar18 * 0x2d413ccc) >> 0x1e));
      local_5c = local_5c + 1;
      iVar21 = local_88;
      iVar8 = iVar5;
      iVar16 = local_94 -
               ((int)((ulonglong)((longlong)local_98 * (longlong)iVar19) >> 0x20) << 2 |
               (uint)((longlong)local_98 * (longlong)iVar19) >> 0x1e);
      iVar20 = ((int)((ulonglong)((longlong)local_98 * (longlong)iVar18) >> 0x20) << 2 |
               (uint)((longlong)local_98 * (longlong)iVar18) >> 0x1e) + local_90;
      iVar5 = iVar15;
      local_94 = iVar18;
      local_90 = iVar19;
      local_88 = iVar17;
    } while (local_5c < local_84);
  }
  if (0 < *(short *)(param_3 + 0x7c)) {
    uVar2 = 0;
    iVar21 = 0;
    do {
      iVar21 = iVar21 + 1;
      if (uVar2 < *local_74) {
        uVar2 = *local_74;
      }
      local_74 = local_74 + 1;
    } while (iVar21 < *(short *)(param_3 + 0x7c));
    if (uVar2 != 0) {
      *(uint *)(param_3 + 0xa0) = uVar2;
      return 0;
    }
  }
  return 0x80004005;
}



/* 40aea73c FUN_40aea73c */

void FUN_40aea73c(void)

{
  return;
}



/* 40aea900 FUN_40aea900 */

undefined4 FUN_40aea900(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 1;
  if (*(short *)(param_1 + 0x58) != 0) {
    do {
      *(undefined2 *)(param_2 + 0x450) = 4;
      param_2 = param_2 + 0x594;
      bVar1 = iVar2 < (int)(uint)*(ushort *)(param_1 + 0x58);
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  return 0;
}



/* 40aea930 FUN_40aea930 */

undefined4 FUN_40aea930(int param_1,int param_2)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  
  if (*(short *)(param_1 + 0x58) != 0) {
    iVar6 = 1;
    iVar3 = param_2;
    do {
      *(undefined1 *)(iVar3 + 0xbc) = 0;
      uVar7 = (uint)*(ushort *)(param_1 + 0x58);
      *(undefined4 *)(iVar3 + 0xc4) = 0x40000000;
      bVar1 = iVar6 < (int)uVar7;
      *(undefined4 *)(iVar3 + 0xc0) = 0x1e;
      iVar6 = iVar6 + 1;
      iVar3 = iVar3 + 0x594;
    } while (bVar1);
    iVar6 = 1;
    iVar3 = param_2;
    if (uVar7 != 0) {
      do {
        bVar1 = iVar6 < (int)uVar7;
        *(undefined4 *)(iVar3 + 8) = 0;
        *(undefined4 *)(iVar3 + 0xd8) = 0;
        *(undefined4 *)(iVar3 + 0xd4) = 1;
        iVar6 = iVar6 + 1;
        iVar3 = iVar3 + 0x594;
      } while (bVar1);
      iVar3 = 1;
      if (uVar7 != 0) {
        sVar2 = (short)*(undefined4 *)(param_1 + 0xfc);
        sVar5 = sVar2 / 2;
        do {
          *(short *)(param_2 + 0x80) = sVar5;
          psVar4 = *(short **)(*(int *)(param_2 + 200) + 8);
          *(short *)(param_2 + 0x82) = sVar5;
          *psVar4 = sVar2;
          *(undefined2 *)(param_2 + 0x7a) = 0;
          param_2 = param_2 + 0x594;
          bVar1 = iVar3 < (int)(uint)*(ushort *)(param_1 + 0x58);
          iVar3 = iVar3 + 1;
        } while (bVar1);
      }
    }
  }
  return 0;
}



/* 40aea9e8 FUN_40aea9e8 */

void FUN_40aea9e8(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = &LAB_40aeb1a0;
  *param_1 = &LAB_40aeaf94;
  return;
}



/* 40aeaa90 FUN_40aeaa90 */

void FUN_40aeaa90(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1[1];
  uVar2 = uVar3;
  if ((int)uVar3 < 0) {
    uVar2 = -uVar3;
  }
  if (uVar2 == 0) {
    *param_1 = 0;
    return;
  }
  if (uVar2 < 0x1fffffff) {
    uVar1 = 0;
    do {
      uVar2 = uVar2 << 2;
      uVar1 = uVar1 + 2;
    } while (uVar2 < 0x1fffffff);
  }
  else {
    uVar1 = 0;
  }
  if (uVar2 < 0x3fffffff) {
    uVar1 = uVar1 + 1;
  }
  *param_1 = *param_1 + uVar1;
  param_1[1] = uVar3 << (uVar1 & 0x1f);
  return;
}



/* 40aeab1c FUN_40aeab1c */

void FUN_40aeab1c(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1[1];
  if (uVar2 < 0x1fffffff) {
    iVar1 = 0;
    do {
      uVar2 = uVar2 << 2;
      iVar1 = iVar1 + 2;
    } while (uVar2 < 0x1fffffff);
  }
  else {
    iVar1 = 0;
  }
  if (uVar2 < 0x3fffffff) {
    uVar2 = uVar2 << 1;
    iVar1 = iVar1 + 1;
  }
  param_1[1] = uVar2;
  *param_1 = *param_1 + iVar1;
  return;
}



/* 40aeab90 FUN_40aeab90 */

int * FUN_40aeab90(int *param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  
  if (param_4 == 0) {
    if (param_3 == 0) {
      param_1[1] = 0;
      *param_1 = 0;
      return param_1;
    }
    uVar2 = 0x20;
    uVar1 = param_3;
  }
  else {
    uVar2 = 0;
    uVar1 = param_4;
  }
  for (; (uVar1 & 0xf0000000) == 0; uVar1 = uVar1 << 3) {
    uVar2 = uVar2 + 3;
  }
  for (; (uVar1 & 0xc0000000) == 0; uVar1 = uVar1 << 1) {
    uVar2 = uVar2 + 1;
  }
  uVar1 = (param_3 >> 1) >> (~uVar2 & 0x1f) | param_4 << (uVar2 & 0x1f);
  if ((uVar2 & 0x20) != 0) {
    uVar1 = param_3 << (uVar2 & 0x1f);
  }
  *param_1 = param_5 + -0x20 + uVar2;
  param_1[1] = uVar1;
  return param_1;
}



/* 40aeac3c FUN_40aeac3c */

int FUN_40aeac3c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[1] * 0x19660d + 0x3c6ef35f;
  iVar3 = *param_1;
  iVar1 = (iVar2 >> 4) + (iVar2 >> 2);
  *param_1 = iVar1;
  param_1[1] = iVar2;
  return iVar1 - iVar3;
}



/* 40aeadb8 FUN_40aeadb8 */

void FUN_40aeadb8(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  *(undefined4 *)(param_3 + 0x34) = 0;
  if ((((param_4 == 3) && (*(int *)(param_3 + 0x28) != 0)) && (param_1 != (int *)0x0)) &&
     (0 < param_2)) {
    if (*param_1 != 0) {
LAB_40aeae18:
      *(undefined4 *)(param_3 + 0x34) = 1;
      return;
    }
    for (iVar2 = 1; iVar2 < param_2; iVar2 = iVar2 + 1) {
      piVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      if (*piVar1 != 0) goto LAB_40aeae18;
    }
  }
  return;
}



/* 40aeae24 FUN_40aeae24 */

void FUN_40aeae24(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  *(undefined4 *)(param_3 + 0x34) = 0;
  if ((((param_4 == 3) && (*(int *)(param_3 + 0x28) != 0)) && (param_1 != (int *)0x0)) &&
     (0 < param_2)) {
    if (*param_1 != 0) {
LAB_40aeae84:
      *(undefined4 *)(param_3 + 0x34) = 1;
      return;
    }
    for (iVar2 = 1; iVar2 < param_2; iVar2 = iVar2 + 1) {
      piVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      if (*piVar1 != 0) goto LAB_40aeae84;
    }
  }
  return;
}



/* 40aeae90 FUN_40aeae90 */

/* Boundary evidence: original MIPS .pdata 40aeae90..40aeaf93. Semantic name remains unreviewed. */

undefined4 FUN_40aeae90(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if ((param_3 & 0xffff) != 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x58);
    iVar8 = 0;
    iVar10 = 0;
    do {
      if (uVar2 != 0) {
        iVar7 = 0;
        iVar6 = 1;
        iVar9 = iVar8;
        do {
          iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x134) + iVar7 + 0x40) + iVar10);
          iVar4 = 1 << (*(ushort *)(param_1 + 100) - 1 & 0x1f);
          iVar5 = iVar4 + -1;
          iVar4 = -iVar4;
          iVar8 = iVar9 + 1;
          iVar7 = iVar7 + 0x594;
          if ((iVar4 <= iVar3) && (iVar4 = iVar5, iVar3 <= iVar5)) {
            iVar4 = iVar3;
          }
          (**(code **)(param_1 + 0x1e8))(iVar4,param_2,param_1,iVar9);
          uVar2 = (uint)*(ushort *)(param_1 + 0x58);
          bVar1 = iVar6 < (int)uVar2;
          iVar6 = iVar6 + 1;
          iVar9 = iVar8;
        } while (bVar1);
      }
      iVar10 = iVar10 + 4;
    } while (iVar10 != (param_3 & 0xffff) << 2);
  }
  return 0;
}



/* 40aeafa4 FUN_40aeafa4 */

undefined4 FUN_40aeafa4(void)

{
  return 0;
}



/* 40aeafac FUN_40aeafac */

undefined4 FUN_40aeafac(void)

{
  return 0;
}



/* 40aeafdc FUN_40aeafdc */

undefined4 FUN_40aeafdc(void)

{
  return 0;
}



/* 40aeafe4 FUN_40aeafe4 */

void FUN_40aeafe4(void)

{
  return;
}



/* 40aeafec FUN_40aeafec */

void FUN_40aeafec(undefined4 *param_1)

{
  *param_1 = 0x1e;
  param_1[1] = 0x40000000;
  return;
}



/* 40aeb004 FUN_40aeb004 */

undefined4 FUN_40aeb004(void)

{
  return 0;
}



/* 40aeb00c FUN_40aeb00c */

undefined4 FUN_40aeb00c(void)

{
  return 0;
}



/* 40aeb014 FUN_40aeb014 */

undefined4 FUN_40aeb014(void)

{
  return 0;
}



/* 40aeb01c FUN_40aeb01c */

undefined4 FUN_40aeb01c(void)

{
  return 0;
}



/* 40aeb024 FUN_40aeb024 */

undefined4 FUN_40aeb024(void)

{
  return 0;
}



/* 40aeb044 FUN_40aeb044 */

int FUN_40aeb044(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_2 - param_3;
  if ((int)uVar1 < 0) {
    return param_1 << (-uVar1 & 0x1f);
  }
  if ((int)uVar1 < 0x20) {
    return param_1 >> (uVar1 & 0x1f);
  }
  return 0;
}



/* 40aeb0ac FUN_40aeb0ac */

void FUN_40aeb0ac(uint *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_1;
  iVar2 = *param_2;
  if (uVar1 != 0) {
    for (; uVar1 < param_3 >> 1; uVar1 = uVar1 << 2) {
      iVar2 = iVar2 + 2;
    }
    if (uVar1 < param_3) {
      uVar1 = uVar1 << 1;
      iVar2 = iVar2 + 1;
    }
    *param_1 = uVar1;
    *param_2 = iVar2;
  }
  return;
}



/* 40aeb0fc FUN_40aeb0fc */

uint FUN_40aeb0fc(int param_1,int param_2)

{
  return (param_2 + -1) * 4 | param_1 - 1U;
}



/* 40aeb110 FUN_40aeb110 */

bool FUN_40aeb110(int param_1)

{
  if ((param_1 != 0x5e) && (param_1 != 0x4e)) {
    return param_1 == 0x3d;
  }
  return true;
}



/* 40aeb194 FUN_40aeb194 */

int FUN_40aeb194(int param_1,int param_2,int param_3)

{
  return param_3 * param_2 + param_1;
}



/* 40aeb1b0 FUN_40aeb1b0 */

/* Boundary evidence: original MIPS .pdata 40aeb1b0..40aeb39b. Semantic name remains unreviewed. */

void FUN_40aeb1b0(int param_1,int *param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short local_30;
  short asStack_2e [3];
  
  uVar4 = (uint)*(ushort *)(param_1 + 0x58);
  if (uVar4 == 0) {
    iVar9 = 0x7fff;
  }
  else {
    iVar8 = 0;
    iVar9 = 0x7fff;
    iVar7 = 0;
    do {
      while( true ) {
        psVar1 = *(short **)(*(int *)(param_1 + 0x134) + iVar7 + 200);
        iVar3 = (int)*psVar1;
        iVar2 = *(int *)(psVar1 + 4);
        iVar6 = (int)*(short *)(iVar2 + (iVar3 + -1) * 2);
        if (*(int *)(param_1 + 0x1a4) != 0) break;
        if (*(int *)(param_1 + 0x1a8) == 0) goto LAB_40aeb210;
        iVar6 = iVar6 << (*(uint *)(param_1 + 0x1b0) & 0x1f);
        if (*(int *)(param_1 + 0x40) < 3) goto LAB_40aeb224;
LAB_40aeb308:
        iVar2 = *(int *)(param_1 + 0x1b8) / 2 + (*(int *)(param_1 + 0x1b8) - iVar6 / 2);
        iVar8 = iVar8 + 1;
        if (iVar2 < iVar9) {
          iVar9 = iVar2;
        }
        iVar7 = iVar7 + 0x594;
        if ((int)uVar4 <= iVar8) goto LAB_40aeb340;
      }
      iVar6 = iVar6 >> (*(uint *)(param_1 + 0x1b0) & 0x1f);
LAB_40aeb210:
      if (2 < *(int *)(param_1 + 0x40)) goto LAB_40aeb308;
LAB_40aeb224:
      sVar5 = *(short *)(iVar2 + iVar3 * 2);
      if (*(int *)(param_1 + 0x1a4) == 0) {
        if (*(int *)(param_1 + 0x1a8) != 0) {
          sVar5 = (short)((int)sVar5 << (*(uint *)(param_1 + 0x1b0) & 0x1f));
        }
      }
      else {
        sVar5 = (short)((int)sVar5 >> (*(uint *)(param_1 + 0x1b0) & 0x1f));
      }
      FUN_40af333c(param_1,1,(short)iVar6,sVar5,(int)(short)iVar6,&local_30,asStack_2e);
      uVar4 = (uint)*(ushort *)(param_1 + 0x58);
      iVar2 = *(int *)(param_1 + 0x1b8) / 2 +
              (((int)local_30 + *(int *)(param_1 + 0x1b8)) - (iVar6 * 3) / 2);
      iVar8 = iVar8 + 1;
      if (iVar2 < iVar9) {
        iVar9 = iVar2;
      }
      iVar7 = iVar7 + 0x594;
    } while (iVar8 < (int)uVar4);
  }
LAB_40aeb340:
  *param_2 = iVar9 - *(int *)(param_1 + 0x174);
  return;
}



/* 40aeb39c FUN_40aeb39c */

/* Boundary evidence: original MIPS .pdata 40aeb39c..40aeb497. Semantic name remains unreviewed. */

void FUN_40aeb39c(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = *(int *)(param_1 + 0x174);
  iVar1 = *(int *)(param_1 + 0x1b8);
  if (iVar1 <= iVar3) {
    if (*(int *)(param_1 + 0x1a8) == 0) {
      iVar4 = *(int *)(param_1 + 0xfc);
    }
    else {
      iVar4 = *(int *)(param_1 + 0xfc) << (*(uint *)(param_1 + 0x1b0) & 0x1f);
    }
    if (*(short *)(param_1 + 0x58) != 0) {
      iVar3 = iVar1 >> 1;
      iVar6 = ((iVar4 >> 1) - iVar3) * 4;
      iVar5 = 0;
      while( true ) {
        piVar2 = (int *)(*(int *)(param_1 + 0x138) + iVar6);
        FUN_40afcef8(piVar2,piVar2 + iVar1,iVar3 << 2);
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + ((iVar4 * 3) / 2) * 4;
        if ((int)(uint)*(ushort *)(param_1 + 0x58) <= iVar5) break;
        iVar1 = *(int *)(param_1 + 0x1b8);
      }
      iVar3 = *(int *)(param_1 + 0x174);
      iVar1 = *(int *)(param_1 + 0x1b8);
    }
    *(int *)(param_1 + 0x178) = *(int *)(param_1 + 0x178) - iVar1;
    *(int *)(param_1 + 0x174) = iVar3 - iVar1;
  }
  return;
}



/* 40aeb498 FUN_40aeb498 */

/* Boundary evidence: original MIPS .pdata 40aeb498..40aeb7ff. Semantic name remains unreviewed. */

void FUN_40aeb498(int param_1,short *param_2,undefined4 param_3,int param_4,int param_5)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  ushort local_38;
  short sStack_36;
  ushort local_34;
  short sStack_32;
  int local_30;
  uint local_2c;
  
  if (*(int *)(param_1 + 0x48) == 3) {
    FUN_40af691c(param_1,param_5);
    uVar2 = *(ushort *)(param_1 + 0x58);
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x58);
  }
  uVar8 = (uint)uVar2;
  if (uVar8 == 0) {
    local_2c = 0x7fff;
LAB_40aeb658:
    iVar14 = *(int *)(param_1 + 0xa8);
  }
  else {
    iVar14 = 0;
    local_2c = 0x7fff;
    local_30 = 0;
    do {
      while( true ) {
        iVar7 = *(int *)(param_1 + 0x154);
        iVar13 = iVar14 * 4;
        iVar10 = *(int *)(param_1 + 0x134) + local_30;
        uVar9 = (uint)*(ushort *)(iVar7 + iVar13);
        if (param_4 == 0) break;
        iVar11 = 0;
        iVar7 = 0;
        do {
          while( true ) {
            iVar12 = iVar7 + -2;
            iVar3 = *(int *)(*(int *)(iVar10 + 200) + 8);
            sVar1 = *(short *)(iVar3 + iVar7);
            uVar8 = (uint)sVar1;
            FUN_40af3244(param_1,1,*(short *)(iVar3 + iVar12),sVar1,(short *)&local_38,&sStack_36);
            iVar7 = iVar7 + 2;
            FUN_40af333c(param_1,1,sVar1,*(short *)(*(int *)(*(int *)(iVar10 + 200) + 8) + iVar7),
                         uVar8,(short *)&local_34,&sStack_32);
            if (*(int *)(param_1 + 0x40) < 3) break;
            iVar11 = iVar11 + uVar8;
            uVar9 = uVar9 + (int)((int)*(short *)(*(int *)(*(int *)(iVar10 + 200) + 8) + iVar12) +
                                 uVar8) / 2 & 0xffff;
            if (*(int *)(param_1 + 0xfc) <= iVar11) goto LAB_40aeb608;
          }
          iVar11 = iVar11 + uVar8;
          uVar9 = uVar9 + ((uint)local_34 - (uint)local_38) & 0xffff;
        } while (iVar11 < *(int *)(param_1 + 0xfc));
LAB_40aeb608:
        uVar8 = *(uint *)(*(int *)(param_1 + 0x158) + iVar13);
        if (0 < (int)uVar8) {
          if ((int)uVar9 <= (int)uVar8) {
            uVar8 = uVar9;
          }
          uVar9 = uVar9 - uVar8 & 0xffff;
        }
        if (local_2c < uVar9) {
          uVar9 = local_2c;
        }
        uVar8 = (uint)*(ushort *)(param_1 + 0x58);
        iVar14 = iVar14 + 1;
        local_30 = local_30 + 0x594;
        local_2c = uVar9;
        if ((int)uVar8 <= iVar14) goto LAB_40aeb658;
      }
      if ((*(int *)(param_1 + 0xa8) == 0) && (*(short *)(iVar10 + 0x4c) != 0x7fff)) {
        if (*(int *)(param_1 + 0x40) < 3) {
          uVar9 = uVar9 + ((uint)*(ushort *)(iVar10 + 0x8a) - (uint)*(ushort *)(iVar10 + 0x86)) &
                  0xffff;
        }
        else {
          uVar9 = uVar9 + ((int)*(short *)(iVar10 + 0x80) + (int)*(short *)(iVar10 + 0x82)) / 2 &
                  0xffff;
        }
      }
      puVar6 = (uint *)(*(int *)(param_1 + 0x158) + iVar13);
      uVar5 = *puVar6;
      if (0 < (int)uVar5) {
        uVar4 = uVar5;
        if ((int)uVar9 <= (int)uVar5) {
          uVar4 = uVar9;
        }
        *puVar6 = uVar5 - (uVar4 & 0xffff);
        uVar9 = uVar9 - (uVar4 & 0xffff) & 0xffff;
      }
      uVar5 = uVar9;
      if (local_2c < uVar9) {
        uVar5 = local_2c;
      }
      iVar14 = iVar14 + 1;
      *(uint *)(iVar7 + iVar13) = uVar9;
      local_30 = local_30 + 0x594;
      local_2c = uVar5;
    } while (iVar14 < (int)uVar8);
    iVar14 = *(int *)(param_1 + 0xa8);
  }
  if (iVar14 != 0) {
    if (param_4 == 0) {
      uVar8 = *(uint *)(param_1 + 0x170);
      if (local_2c <= *(uint *)(param_1 + 0x170)) {
        uVar8 = local_2c;
      }
      *param_2 = (short)uVar8 - *(short *)(param_1 + 0xca);
      return;
    }
    local_2c = (uint)*(ushort *)(param_1 + 0xfc);
    if (*(uint *)(param_1 + 0x170) < (uint)*(ushort *)(param_1 + 0xfc)) {
      local_2c = *(uint *)(param_1 + 0x170);
    }
    local_2c = local_2c & 0xffff;
  }
  *param_2 = (short)local_2c;
  return;
}



/* 40aeb800 FUN_40aeb800 */

/* Boundary evidence: original MIPS .pdata 40aeb800..40aebba7. Semantic name remains unreviewed. */

int FUN_40aeb800(int param_1,ushort *param_2,undefined4 *param_3,uint param_4,int param_5)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  ushort *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  ushort *puVar16;
  uint uVar17;
  ushort local_28 [6];
  
  uVar13 = (uint)*(ushort *)(param_1 + 0x58);
  if (*(uint *)(param_1 + 0x5c) == 0) {
    trap(7);
  }
  local_28[0] = *param_2;
  puVar16 = *(ushort **)(param_1 + 0x2c0);
  uVar17 = (param_4 / *(uint *)(param_1 + 0x5c)) / uVar13;
  if (uVar13 == 0) {
    trap(7);
  }
  if (*(int *)(param_1 + 0xa8) == 1) {
    FUN_40aeb498(param_1,(short *)local_28,0,0,param_5);
    uVar2 = *param_2 & 0xfff0;
    if (*param_2 < local_28[0]) {
      *param_2 = uVar2;
      uVar13 = (uint)*(ushort *)(param_1 + 0x58);
      local_28[0] = uVar2;
    }
    else {
      uVar13 = (uint)*(ushort *)(param_1 + 0x58);
    }
  }
  if (uVar13 == 0) {
    uVar11 = 0;
  }
  else {
    iVar14 = *(int *)(param_1 + 0x134);
    iVar6 = 0;
    iVar4 = 1;
    do {
      bVar1 = iVar4 < (int)uVar13;
      *(uint *)(iVar14 + iVar6 + 0x58c) = (uint)local_28[0];
      iVar6 = iVar6 + 0x594;
      iVar4 = iVar4 + 1;
      uVar11 = uVar13;
    } while (bVar1);
  }
  if (*(int *)(param_1 + 0xa8) == 0) {
    iVar6 = *(int *)(param_1 + 0x174);
    if (*(int *)(param_1 + 0x1a8) == 0) {
      iVar14 = *(int *)(param_1 + 0xfc);
    }
    else {
      iVar14 = *(int *)(param_1 + 0xfc) << (*(uint *)(param_1 + 0x1b0) & 0x1f);
    }
    uVar8 = *(int *)(param_1 + 0x178) - iVar6 & 0xffff;
    uVar3 = (uint)local_28[0];
    if (uVar17 <= local_28[0]) {
      uVar3 = uVar17;
    }
    uVar17 = 0x7fff;
    if (uVar8 < 0x8000) {
      uVar17 = uVar8;
    }
    if ((int)uVar17 <= (int)uVar3) {
      uVar3 = uVar17;
    }
    uVar17 = uVar3 & 0xffff;
    iVar4 = 0;
    if (uVar17 == 0) {
      *param_2 = 0;
    }
    else {
      uVar9 = *param_3;
      if (uVar11 != 0) {
        iVar5 = *(int *)(param_1 + 0x1b8);
        iVar15 = *(int *)(param_1 + 0x134);
        iVar10 = 0;
        iVar4 = 0;
        iVar7 = 1;
        do {
          bVar1 = iVar7 < (int)uVar13;
          *(int *)(iVar15 + iVar10 + 0x40) =
               *(int *)(param_1 + 0x138) +
               (iVar4 * ((iVar14 * 3) / 2) + ((iVar14 >> 1) - (iVar5 >> 1)) + iVar6) * 4;
          iVar10 = iVar10 + 0x594;
          iVar4 = iVar7;
          iVar7 = iVar7 + 1;
        } while (bVar1);
      }
      iVar4 = (**(code **)(param_1 + 0x1cc))(param_1,uVar9,uVar17);
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar7 = *(int *)(param_1 + 0x1b8);
      iVar6 = *(int *)(param_1 + 0x174) + uVar17;
      *param_2 = (ushort)uVar3;
      *(int *)(param_1 + 0x174) = iVar6;
      if (iVar7 <= iVar6) {
        iVar6 = iVar6 - iVar7;
        *(int *)(param_1 + 0x178) = *(int *)(param_1 + 0x178) - iVar7;
        *(int *)(param_1 + 0x174) = iVar6;
        if ((iVar6 < 0) || (iVar7 / 2 <= iVar6)) {
          return -0x7fffbffb;
        }
        if (*(short *)(param_1 + 0x58) != 0) {
          iVar15 = iVar7 >> 1;
          iVar5 = 0;
          iVar10 = 1;
          while( true ) {
            iVar5 = *(int *)(param_1 + 0x138) +
                    (iVar5 * ((iVar14 * 3) / 2) + ((iVar14 >> 1) - iVar15)) * 4;
            FUN_40afcef8((int *)(iVar5 + iVar6 * 4),(int *)(iVar5 + (iVar7 + iVar6) * 4),
                         (iVar15 - iVar6) * 4);
            if ((int)(uint)*(ushort *)(param_1 + 0x58) <= iVar10) break;
            iVar6 = *(int *)(param_1 + 0x174);
            iVar7 = *(int *)(param_1 + 0x1b8);
            iVar5 = iVar10;
            iVar10 = iVar10 + 1;
          }
          iVar6 = *(int *)(param_1 + 0x48);
          goto LAB_40aeb91c;
        }
      }
    }
  }
  else {
    if (uVar11 != 0) {
      iVar14 = *(int *)(param_1 + 0x134);
      iVar6 = 0;
      iVar4 = 1;
      puVar12 = puVar16;
      do {
        uVar13 = *(uint *)(iVar14 + iVar6 + 0x58c);
        iVar6 = iVar6 + 0x594;
        if (0x7fff < uVar13) {
          uVar13 = 0x7fff;
        }
        if ((uVar17 & 0xfffffff0) < uVar13) {
          uVar13 = uVar17 & 0xfffffff0;
        }
        *puVar12 = (ushort)uVar13;
        puVar12 = puVar12 + 1;
        bVar1 = iVar4 < (int)(uint)*(ushort *)(param_1 + 0x58);
        iVar4 = iVar4 + 1;
      } while (bVar1);
    }
    iVar4 = 0;
    *param_2 = *puVar16;
  }
  iVar6 = *(int *)(param_1 + 0x48);
LAB_40aeb91c:
  if (iVar6 == 3) {
    *(undefined4 *)(param_1 + 0x48) = 1;
  }
  return iVar4;
}



/* 40aebba8 FUN_40aebba8 */

/* Boundary evidence: original MIPS .pdata 40aebba8..40aebca3. Semantic name remains unreviewed. */

void FUN_40aebba8(int param_1,short *param_2,undefined2 *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0xa8) == 1) {
    FUN_40aeb498(param_1,param_2,0,0,param_4);
    if (param_3 != (undefined2 *)0x0) {
      *param_3 = 0;
      return;
    }
  }
  else {
    iVar4 = 0;
    if (*(short *)(param_1 + 0x58) != 0) {
      iVar5 = *(int *)(param_1 + 0x134);
      iVar3 = 1;
      do {
        *(undefined2 *)(iVar5 + iVar4 + 0x4c) = 0x7fff;
        iVar4 = iVar4 + 0x594;
        bVar1 = iVar3 < (int)(uint)*(ushort *)(param_1 + 0x58);
        iVar3 = iVar3 + 1;
      } while (bVar1);
    }
    iVar4 = 0;
    if (0 < *(short *)(param_1 + 0x21c)) {
      iVar5 = *(int *)(param_1 + 0x134);
      iVar6 = *(int *)(param_1 + 0x220);
      iVar3 = 0;
      do {
        iVar2 = *(short *)(iVar6 + iVar3) * 0x594 + iVar5;
        iVar4 = (iVar4 + 1) * 0x10000 >> 0x10;
        *(undefined2 *)(iVar2 + 0x4c) = *(undefined2 *)(iVar2 + 0x86);
        iVar3 = iVar3 + 2;
      } while (iVar4 < *(short *)(param_1 + 0x21c));
    }
    FUN_40aeb498(param_1,param_2,1,0,param_4);
  }
  return;
}



/* 40aebca4 FUN_40aebca4 */

/* Boundary evidence: original MIPS .pdata 40aebca4..40aebd97. Semantic name remains unreviewed. */

undefined4 FUN_40aebca4(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  memset(*(void **)(param_1 + 0x154),0,(uint)*(ushort *)(param_1 + 0x58) << 2);
  if (*(int *)(param_1 + 0x1a8) == 0) {
    iVar1 = (*(int *)(param_1 + 0xfc) * 3) / 2;
  }
  else {
    iVar1 = (*(int *)(param_1 + 0xfc) * 3) / 2 << (*(uint *)(param_1 + 0x1b0) & 0x1f);
  }
  memset(*(void **)(param_1 + 0x138),0,(uint)*(ushort *)(param_1 + 0x58) * iVar1 * 4);
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  memset(*(void **)(param_1 + 0x158),0,(uint)*(ushort *)(param_1 + 0x58) << 2);
  memset(*(void **)(param_1 + 0x15c),0,(uint)*(ushort *)(param_1 + 0x58) << 2);
  memset(*(void **)(param_1 + 0x160),0,(uint)*(ushort *)(param_1 + 0x58) << 2);
  *(undefined4 *)(param_1 + 0x120) = 0x40;
  return 0;
}



/* 40aebda8 FUN_40aebda8 */

/* Boundary evidence: original MIPS .pdata 40aebda8..40aec047. Semantic name remains unreviewed. */

undefined4 * FUN_40aebda8(void)

{
  undefined4 *_Dst;
  
  _Dst = malloc(0x2e0);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x2e0);
    _Dst[0xe] = 9;
    _Dst[0x17] = 2;
    _Dst[0xf] = 0x1ff;
    _Dst[0x1a] = 0x3d;
    *(undefined2 *)(_Dst + 0x1c) = 0xffff;
    *(undefined2 *)(_Dst + 0x19) = 0x10;
    *_Dst = 0;
    _Dst[1] = 0;
    _Dst[2] = 0;
    _Dst[3] = 0;
    _Dst[4] = 0;
    _Dst[5] = 0;
    _Dst[6] = 0;
    _Dst[7] = 0;
    *(undefined2 *)(_Dst + 8) = 0;
    *(undefined2 *)((int)_Dst + 0x22) = 0;
    *(undefined2 *)(_Dst + 10) = 0;
    _Dst[0xb] = 0;
    _Dst[0xc] = 0;
    _Dst[0xd] = 0;
    _Dst[0x10] = 0;
    _Dst[0x11] = 0;
    _Dst[0x12] = 0;
    _Dst[0x13] = 0;
    _Dst[0x14] = 0;
    _Dst[0x15] = 0;
    *(undefined2 *)(_Dst + 0x16) = 0;
    _Dst[0x18] = 0x10;
    _Dst[0x1d] = 0;
    _Dst[0x1e] = 1;
    _Dst[0x1f] = 0;
    _Dst[0x21] = 0;
    _Dst[0x22] = 0;
    _Dst[0x23] = 0;
    _Dst[0x48] = 0x40;
    _Dst[0x24] = 0;
    _Dst[0x25] = 0;
    _Dst[0x2a] = 0;
    _Dst[0x2c] = 0;
    _Dst[0x9a] = 0;
    _Dst[0x2e] = 0;
    *(undefined1 *)(_Dst + 0x30) = 0;
    _Dst[0x31] = 0;
    *(undefined2 *)((int)_Dst + 0xca) = 0;
    _Dst[0x33] = 0;
    _Dst[0x34] = 0;
    _Dst[0x35] = 0;
    *(undefined2 *)(_Dst + 0x36) = 0;
    _Dst[0x37] = 0;
    _Dst[0x38] = 1;
    _Dst[0x39] = 0;
    _Dst[0x3a] = 0;
    _Dst[0x3b] = 0;
    _Dst[0x3c] = 0;
    _Dst[0x3d] = 0;
    _Dst[0x3e] = 0;
    _Dst[0x3f] = 0;
    _Dst[0x40] = 0;
    _Dst[0x41] = 0;
    _Dst[0x42] = 0;
    _Dst[0x43] = 0;
    _Dst[0x44] = 0;
    _Dst[0x45] = 0;
    _Dst[0x46] = 0;
    _Dst[0x47] = 0;
    _Dst[0x49] = 0;
    _Dst[0x4a] = 0;
    _Dst[0x4b] = 0;
    _Dst[0x62] = 1;
    _Dst[0x4c] = 0;
    _Dst[0x4d] = 0;
    _Dst[0x4e] = 0;
    _Dst[0x4f] = 0;
    _Dst[0x50] = 0;
    _Dst[0x51] = 0;
    _Dst[0x52] = 0;
    _Dst[0x53] = 0;
    _Dst[0x54] = 0;
    _Dst[0x55] = 0;
    _Dst[0x56] = 0;
    _Dst[0x57] = 0;
    _Dst[0x58] = 0;
    _Dst[0x59] = 0;
    _Dst[0x5a] = 0;
    _Dst[0x5b] = 0;
    _Dst[0x5d] = 0;
    _Dst[0x5e] = 0;
    _Dst[0x5f] = 0;
    _Dst[0x60] = 0;
    _Dst[0x61] = 0;
    _Dst[99] = 0;
    _Dst[100] = 0;
    _Dst[0x65] = 0;
    _Dst[0x66] = 0;
    _Dst[0x67] = 0;
    _Dst[0x68] = 0;
    _Dst[0x69] = 0;
    _Dst[0x6a] = 0;
    _Dst[0x6b] = 0;
    _Dst[0x6c] = 0;
    _Dst[0x6d] = 0;
    _Dst[0x6e] = 0;
    _Dst[0x70] = FUN_40ae66b4;
    _Dst[0x73] = FUN_40aeae90;
    _Dst[0x74] = FUN_40ae4f3c;
    _Dst[0x79] = FUN_40ae47b0;
    _Dst[0x6f] = 0;
    _Dst[0x71] = 0;
    _Dst[0x72] = 0;
    _Dst[0x7a] = 0;
    _Dst[0x7b] = 0;
    _Dst[0x7c] = 0;
    _Dst[0x7d] = 0;
    _Dst[0x7e] = 0;
    _Dst[0x7f] = 0;
    _Dst[0x80] = 0;
    _Dst[0x81] = 0;
    _Dst[0x82] = 0;
    *(undefined1 *)(_Dst + 0x83) = 0;
    _Dst[0x84] = 0;
    _Dst[0x85] = 0;
    _Dst[0x86] = 0;
    *(undefined2 *)(_Dst + 0x87) = 0;
    _Dst[0x88] = 0;
    _Dst[0x89] = 0;
    _Dst[0x8c] = 0;
    _Dst[0x8b] = 0;
    _Dst[0x8d] = 0;
    _Dst[0x91] = 0;
    _Dst[0xb0] = 0;
    _Dst[0xb2] = 0;
    _Dst[0xb3] = 0;
    _Dst[0xb5] = 0;
    _Dst[0xb4] = 0;
    _Dst[0xb6] = 0;
    _Dst[0xb7] = 0;
  }
  return _Dst;
}



/* 40aec048 FUN_40aec048 */

void FUN_40aec048(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40b062e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(param_1);
  return;
}



/* 40aec050 FUN_40aec050 */

/* Boundary evidence: original MIPS .pdata 40aec050..40aec0bf. Semantic name remains unreviewed. */

uint FUN_40aec050(int param_1,int param_2)

{
  void *_Memory;
  uint uVar1;
  
  _Memory = malloc(param_2 + param_1);
  if (_Memory != (void *)0x0) {
    if (3 < param_2) {
      uVar1 = -1 << ((LZCOUNT(param_2) ^ 0x1fU) & 0x1f) & (int)_Memory + param_2;
      *(char *)(uVar1 - 1) = (char)uVar1 - (char)_Memory;
      return uVar1;
    }
    free(_Memory);
  }
  return 0;
}



/* 40aec0dc FUN_40aec0dc */

int * FUN_40aec0dc(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (int)((ulonglong)((longlong)param_3 * (longlong)param_5) >> 0x20);
  uVar4 = iVar1 * 2;
  uVar3 = uVar4;
  if ((int)uVar4 < 0) {
    uVar3 = iVar1 * -2;
  }
  if (uVar3 == 0) {
    *param_1 = 0;
    param_1[1] = uVar4;
    return param_1;
  }
  if (uVar3 < 0x1fffffff) {
    uVar2 = 0;
    do {
      uVar3 = uVar3 << 2;
      uVar2 = uVar2 + 2;
    } while (uVar3 < 0x1fffffff);
  }
  else {
    uVar2 = 0;
  }
  if (uVar3 < 0x3fffffff) {
    uVar2 = uVar2 + 1;
  }
  *param_1 = param_2 + param_4 + -0x1f + uVar2;
  param_1[1] = uVar4 << (uVar2 & 0x1f);
  return param_1;
}



/* 40aec260 FUN_40aec260 */

int * FUN_40aec260(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (LZCOUNT(param_2) ^ 0x1fU) + 1;
  uVar1 = (param_4 >> (uVar4 & 0x1f)) * param_2;
  uVar3 = uVar1;
  if ((int)uVar1 < 0) {
    uVar3 = -uVar1;
  }
  if (uVar3 == 0) {
    *param_1 = 0;
    param_1[1] = uVar1;
    return param_1;
  }
  if (uVar3 < 0x1fffffff) {
    uVar2 = 0;
    do {
      uVar3 = uVar3 << 2;
      uVar2 = uVar2 + 2;
    } while (uVar3 < 0x1fffffff);
  }
  else {
    uVar2 = 0;
  }
  if (uVar3 < 0x3fffffff) {
    uVar2 = uVar2 + 1;
  }
  *param_1 = (param_3 - uVar4) + uVar2;
  param_1[1] = uVar1 << (uVar2 & 0x1f);
  return param_1;
}



/* 40aec318 FUN_40aec318 */

int * FUN_40aec318(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_3 / param_4;
  if (param_4 == 0) {
    trap(7);
  }
  uVar2 = uVar3;
  if ((int)uVar3 < 0) {
    uVar2 = -uVar3;
  }
  if (uVar2 == 0) {
    param_1[1] = uVar3;
    *param_1 = 0;
    return param_1;
  }
  if (uVar2 < 0x1fffffff) {
    uVar1 = 0;
    do {
      uVar2 = uVar2 << 2;
      uVar1 = uVar1 + 2;
    } while (uVar2 < 0x1fffffff);
  }
  else {
    uVar1 = 0;
  }
  if (uVar2 < 0x3fffffff) {
    uVar1 = uVar1 + 1;
  }
  param_1[1] = uVar3 << (uVar1 & 0x1f);
  *param_1 = uVar1 + param_2;
  return param_1;
}



/* 40aec3d8 FUN_40aec3d8 */

int * FUN_40aec3d8(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_2 - param_4;
  if (iVar3 < 0) {
    uVar2 = (param_5 >> (1U - iVar3 & 0x1f)) + (param_3 >> 1);
    param_4 = param_2;
  }
  else {
    uVar2 = (param_3 >> (iVar3 + 1U & 0x1f)) + (param_5 >> 1);
  }
  uVar4 = uVar2;
  if ((int)uVar2 < 0) {
    uVar4 = -uVar2;
  }
  if (uVar4 == 0) {
    *param_1 = 0;
    param_1[1] = uVar2;
    return param_1;
  }
  if (uVar4 < 0x1fffffff) {
    uVar1 = 0;
    do {
      uVar4 = uVar4 << 2;
      uVar1 = uVar1 + 2;
    } while (uVar4 < 0x1fffffff);
  }
  else {
    uVar1 = 0;
  }
  if (uVar4 < 0x3fffffff) {
    uVar1 = uVar1 + 1;
  }
  *param_1 = uVar1 + param_4 + -1;
  param_1[1] = uVar2 << (uVar1 & 0x1f);
  return param_1;
}



/* 40aec4b8 FUN_40aec4b8 */

/* Boundary evidence: original MIPS .pdata 40aec4b8..40aec92f. Semantic name remains unreviewed. */

undefined4 FUN_40aec4b8(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (*(int *)(param_1 + 0xa8) == 1) {
    if (0 < *(short *)(param_1 + 0x21c)) {
      iVar6 = *(int *)(param_1 + 0x220);
      iVar7 = *(int *)(param_1 + 0x134);
      iVar10 = 0;
      iVar11 = 0;
      do {
        iVar8 = *(short *)(iVar6 + iVar11) * 0x594 + iVar7;
        uVar2 = *(undefined2 *)(*(int *)(*(int *)(iVar8 + 200) + 8) + *(short *)(iVar8 + 0x78) * 2);
        iVar10 = (iVar10 + 1) * 0x10000 >> 0x10;
        *(undefined2 *)(iVar8 + 0x7c) = uVar2;
        *(undefined2 *)(iVar8 + 0x82) = uVar2;
        iVar11 = iVar11 + 2;
      } while (iVar10 < *(short *)(param_1 + 0x21c));
    }
  }
  else if (*(int *)(param_1 + 0xa8) == 0) {
    iVar10 = 0;
    if (0 < *(short *)(param_1 + 0x21c)) {
      iVar11 = 0;
      do {
        iVar9 = *(short *)(*(int *)(param_1 + 0x220) + iVar11) * 0x594 + *(int *)(param_1 + 0x134);
        iVar6 = (int)*(short *)(iVar9 + 0x78);
        iVar7 = *(int *)(*(short **)(iVar9 + 200) + 4);
        sVar1 = *(short *)(iVar7 + iVar6 * 2);
        iVar8 = (int)sVar1;
        *(short *)(iVar9 + 0x82) = sVar1;
        *(undefined2 *)(iVar9 + 0x80) = *(undefined2 *)(iVar7 + (iVar6 + -1) * 2);
        *(undefined2 *)(iVar9 + 0x84) = *(undefined2 *)(iVar7 + (iVar6 + 1) * 2);
        iVar6 = 0;
        if (**(short **)(iVar9 + 200) < 2) {
          *(undefined4 *)(param_1 + 0x124) = **(undefined4 **)(param_1 + 0x144);
          uVar3 = **(undefined4 **)(param_1 + 0x150);
          iVar7 = *(int *)(param_1 + 0xfc);
          *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x148);
          *(undefined4 *)(param_1 + 300) = uVar3;
        }
        else {
          iVar7 = *(int *)(param_1 + 0xfc);
          if (iVar8 == 0) {
            trap(7);
          }
          iVar5 = (int)(short)((ushort)LZCOUNT(iVar7 / iVar8) ^ 0x1f);
          if (*(int *)(param_1 + 0xf0) <= iVar5) {
            return 0x80040002;
          }
          iVar6 = iVar5 * 4;
          *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0x144) + iVar6);
          uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x150) + iVar6);
          *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x148) + iVar5 * 0x74;
          *(undefined4 *)(param_1 + 300) = uVar3;
        }
        iVar5 = *(int *)(param_1 + 0x110);
        iVar12 = (iVar8 * *(int *)(param_1 + 0x10c)) / iVar7;
        if (iVar7 == 0) {
          trap(7);
        }
        *(short *)(iVar9 + 0x7c) = sVar1;
        iVar8 = (iVar8 * iVar5) / iVar7;
        if (iVar7 == 0) {
          trap(7);
        }
        *(int *)(param_1 + 0x104) = iVar12;
        *(int *)(param_1 + 0x108) = iVar8;
        *(int *)(iVar9 + 0x24) = iVar8 - iVar12;
        if (*(int *)(param_1 + 0x2c) == 1) {
          iVar8 = (int)*(short *)(iVar9 + 0x7c);
          iVar7 = *(int *)(param_1 + 0x50);
          iVar5 = (*(int *)(param_1 + 0x17c) * 2 * iVar8 + (iVar7 >> 1) + 0x5dc) / iVar7;
          if (iVar7 == 0) {
            trap(7);
          }
          *(int *)(param_1 + 0x184) = iVar5;
          if (iVar8 < iVar5) {
            *(int *)(param_1 + 0x184) = iVar8;
          }
          *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(*(int *)(param_1 + 0x18c) + iVar6);
        }
        else {
          iVar8 = (int)*(short *)(iVar9 + 0x7c);
        }
        if (*(int *)(param_1 + 0x1a4) == 0) {
          if (*(int *)(param_1 + 0x1a8) == 0) {
            *(undefined4 *)(param_1 + 0x1b4) = *(undefined4 *)(param_1 + 0xf8);
            *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0xfc);
            *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x108);
          }
          else {
            *(int *)(param_1 + 0x1b4) =
                 *(int *)(param_1 + 0xf8) << (*(uint *)(param_1 + 0x1b0) & 0x1f);
            *(int *)(param_1 + 0x1b8) =
                 *(int *)(param_1 + 0xfc) << (*(uint *)(param_1 + 0x1b0) & 0x1f);
            *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x108);
          }
          if (*(int *)(param_1 + 0x1a8) == 0) {
            *(int *)(iVar9 + 0x94) = iVar8;
            *(undefined2 *)(iVar9 + 0x7e) = *(undefined2 *)(iVar9 + 0x7c);
          }
          else {
            iVar8 = iVar8 << (*(uint *)(param_1 + 0x1b0) & 0x1f);
            *(int *)(iVar9 + 0x94) = iVar8;
            uVar4 = *(uint *)(param_1 + 0x1b0);
            *(short *)(iVar9 + 0x80) = (short)((int)*(short *)(iVar9 + 0x80) << (uVar4 & 0x1f));
            *(short *)(iVar9 + 0x82) = (short)((int)*(short *)(iVar9 + 0x82) << (uVar4 & 0x1f));
            *(short *)(iVar9 + 0x84) = (short)((int)*(short *)(iVar9 + 0x84) << (uVar4 & 0x1f));
            *(short *)(iVar9 + 0x7e) = (short)iVar8;
          }
        }
        else {
          uVar4 = *(uint *)(param_1 + 0x1b0);
          iVar8 = iVar8 >> (uVar4 & 0x1f);
          *(int *)(param_1 + 0x1b4) = *(int *)(param_1 + 0xf8) >> (uVar4 & 0x1f);
          *(int *)(param_1 + 0x1b8) = *(int *)(param_1 + 0xfc) >> (uVar4 & 0x1f);
          *(int *)(param_1 + 0x1bc) = *(int *)(param_1 + 0x108) >> (uVar4 & 0x1f);
          *(int *)(iVar9 + 0x94) = iVar8;
          uVar4 = *(uint *)(param_1 + 0x1b0);
          *(short *)(iVar9 + 0x80) = (short)((int)*(short *)(iVar9 + 0x80) >> (uVar4 & 0x1f));
          *(short *)(iVar9 + 0x82) = (short)((int)*(short *)(iVar9 + 0x82) >> (uVar4 & 0x1f));
          *(short *)(iVar9 + 0x84) = (short)((int)*(short *)(iVar9 + 0x84) >> (uVar4 & 0x1f));
          *(short *)(iVar9 + 0x7e) = (short)iVar8;
        }
        FUN_40af3244(param_1,1,*(short *)(iVar9 + 0x80),*(short *)(iVar9 + 0x82),
                     (short *)(iVar9 + 0x86),(short *)(iVar9 + 0x88));
        FUN_40af333c(param_1,1,*(short *)(iVar9 + 0x82),*(short *)(iVar9 + 0x84),
                     *(uint *)(iVar9 + 0x94),(short *)(iVar9 + 0x8a),(short *)(iVar9 + 0x8c));
        iVar10 = (iVar10 + 1) * 0x10000 >> 0x10;
        iVar11 = iVar11 + 2;
      } while (iVar10 < *(short *)(param_1 + 0x21c));
    }
    FUN_40af3458(param_1);
    return 0;
  }
  return 0;
}



/* 40aec930 FUN_40aec930 */

/* Boundary evidence: original MIPS .pdata 40aec930..40aecb8f. Semantic name remains unreviewed. */

void FUN_40aec930(void *param_1)

{
  int iVar1;
  
  if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 0x154) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x154));
      *(undefined4 *)((int)param_1 + 0x154) = 0;
    }
    if (*(void **)((int)param_1 + 0x158) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x158));
      *(undefined4 *)((int)param_1 + 0x158) = 0;
    }
    iVar1 = *(int *)((int)param_1 + 0x15c);
    if (iVar1 != 0) {
      free((void *)(iVar1 - (uint)*(byte *)(iVar1 + -1)));
    }
    iVar1 = *(int *)((int)param_1 + 0x160);
    if (iVar1 != 0) {
      free((void *)(iVar1 - (uint)*(byte *)(iVar1 + -1)));
    }
    iVar1 = *(int *)((int)param_1 + 0x138);
    if (iVar1 != 0) {
      free((void *)(iVar1 - (uint)*(byte *)(iVar1 + -1)));
    }
    if (*(void **)((int)param_1 + 0x19c) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x19c));
      *(undefined4 *)((int)param_1 + 0x19c) = 0;
    }
    if (*(void **)((int)param_1 + 0x144) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x144));
      *(undefined4 *)((int)param_1 + 0x144) = 0;
    }
    if (*(void **)((int)param_1 + 0x148) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x148));
      *(undefined4 *)((int)param_1 + 0x148) = 0;
    }
    if (*(void **)((int)param_1 + 0x150) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x150));
      *(undefined4 *)((int)param_1 + 0x150) = 0;
    }
    if (*(void **)((int)param_1 + 0x13c) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x13c));
      *(undefined4 *)((int)param_1 + 0x13c) = 0;
    }
    if (*(void **)((int)param_1 + 0x140) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x140));
      *(undefined4 *)((int)param_1 + 0x140) = 0;
    }
    if (*(void **)((int)param_1 + 0x18c) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x18c));
      *(undefined4 *)((int)param_1 + 0x18c) = 0;
    }
    if (*(void **)((int)param_1 + 400) != (void *)0x0) {
      free(*(void **)((int)param_1 + 400));
      *(undefined4 *)((int)param_1 + 400) = 0;
    }
    if (*(void **)((int)param_1 + 0x194) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x194));
      *(undefined4 *)((int)param_1 + 0x194) = 0;
    }
    if (*(void **)((int)param_1 + 0x198) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x198));
      *(undefined4 *)((int)param_1 + 0x198) = 0;
    }
    if (*(void **)((int)param_1 + 0x130) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x130));
      *(undefined4 *)((int)param_1 + 0x130) = 0;
    }
    if (*(void **)((int)param_1 + 0x1fc) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x1fc));
      *(undefined4 *)((int)param_1 + 0x1fc) = 0;
    }
    if (*(void **)((int)param_1 + 0x200) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x200));
      *(undefined4 *)((int)param_1 + 0x200) = 0;
    }
    if (*(void **)((int)param_1 + 0x204) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x204));
      *(undefined4 *)((int)param_1 + 0x204) = 0;
    }
    if (*(void **)((int)param_1 + 0x208) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x208));
      *(undefined4 *)((int)param_1 + 0x208) = 0;
    }
    if (*(void **)((int)param_1 + 0x210) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x210));
      *(undefined4 *)((int)param_1 + 0x210) = 0;
    }
    if (*(void **)((int)param_1 + 0x220) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x220));
      *(undefined4 *)((int)param_1 + 0x220) = 0;
    }
    if (*(void **)((int)param_1 + 0x2c0) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x2c0));
      *(undefined4 *)((int)param_1 + 0x2c0) = 0;
    }
    free(param_1);
    return;
  }
  return;
}



/* 40aecb90 FUN_40aecb90 */

/* Boundary evidence: original MIPS .pdata 40aecb90..40aed06b. Semantic name remains unreviewed. */

int FUN_40aecb90(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 0x40);
  if (2 < iVar5) {
    *(undefined4 *)(param_1 + 0xcc) = 1;
  }
  uVar6 = (uint)*(ushort *)(param_1 + 0x58);
  iVar1 = uVar6 * *(int *)(param_1 + 0x50);
  iVar7 = (*(int *)(param_1 + 0x54) << 0xd) / iVar1;
  if (iVar1 == 0) {
    trap(7);
  }
  *(uint *)(param_1 + 0x68) = (*(ushort *)(param_1 + 100) - 1) * 4 | *(int *)(param_1 + 0x5c) - 1U;
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x5c) << 3;
  *(int *)(param_1 + 0x30) = iVar7;
  *(int *)(param_1 + 0x34) = iVar7;
  if (uVar6 == 2) {
    iVar1 = 0x66666664;
LAB_40aecc2c:
    *(uint *)(param_1 + 0x34) =
         (int)((ulonglong)((longlong)iVar7 * (longlong)iVar1) >> 0x20) << 2 |
         (uint)((longlong)iVar7 * (longlong)iVar1) >> 0x1e;
  }
  else if (2 < uVar6) {
    iVar1 = 0x5eb85200;
    goto LAB_40aecc2c;
  }
  iVar1 = *(int *)(param_1 + 0xfc);
  *(int *)(param_1 + 0xf8) = iVar1 << 1;
  *(int *)(param_1 + 0x100) = iVar1 / 2;
  if (iVar5 < 3) {
    uVar4 = *(uint *)(param_1 + 0x44);
    uVar3 = uVar4 >> 1 & 1;
    *(uint *)(param_1 + 0x114) = uVar4 & 1;
    *(uint *)(param_1 + 0xd4) = uVar4 >> 5 & 1;
    *(uint *)(param_1 + 0xcc) = uVar3;
    if ((uVar3 == 0) || ((uVar4 & 4) == 0)) {
      iVar7 = 1;
      *(undefined4 *)(param_1 + 0xe0) = 1;
      *(undefined4 *)(param_1 + 0xd0) = 0;
    }
    else {
      if (uVar6 == 0) {
        trap(7);
      }
      iVar7 = (int)(uVar4 & 0x18) >> 3;
      *(undefined4 *)(param_1 + 0xd0) = 1;
      *(int *)(param_1 + 0xe0) = iVar7;
      if (*(int *)(param_1 + 0x54) / (int)uVar6 < 4000) {
        iVar7 = 2 << iVar7;
        *(int *)(param_1 + 0xe0) = iVar7;
      }
      else {
        iVar7 = 8 << iVar7;
        *(int *)(param_1 + 0xe0) = iVar7;
      }
    }
    iVar2 = *(int *)(param_1 + 0xf8);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xff;
    }
    iVar2 = iVar2 >> 8;
    if (iVar7 <= iVar2) goto LAB_40aecd24;
    *(int *)(param_1 + 0xe0) = iVar2;
    if (iVar5 != 1) goto LAB_40aecd30;
LAB_40aecce8:
    *(int *)(param_1 + 0xf0) = iVar5;
  }
  else {
    iVar7 = 1 << ((int)(*(uint *)(param_1 + 0x44) & 0x38) >> 3);
    *(undefined4 *)(param_1 + 0x114) = 1;
    *(undefined4 *)(param_1 + 0xd4) = 1;
    *(undefined4 *)(param_1 + 0xcc) = 1;
    *(int *)(param_1 + 0xe0) = iVar7;
    if (iVar7 < 2) {
      *(undefined4 *)(param_1 + 0xd0) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0xd0) = 1;
    }
LAB_40aecd24:
    iVar2 = iVar7;
    if (iVar5 == 1) goto LAB_40aecce8;
LAB_40aecd30:
    *(uint *)(param_1 + 0xf0) = (LZCOUNT(iVar2) ^ 0x1fU) + 1;
  }
  iVar5 = (iVar1 << 1) / iVar2;
  if (iVar2 == 0) {
    trap(7);
  }
  iVar1 = iVar5 / 2;
  *(int *)(param_1 + 0xec) = iVar1 / 2;
  *(int *)(param_1 + 0xe4) = iVar5;
  *(int *)(param_1 + 0xe8) = iVar1;
  iVar5 = FUN_40ae56d0(param_1);
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar1 = *(int *)(param_1 + 0xfc);
  iVar7 = *(int *)(param_1 + 0x40);
  *(uint *)(param_1 + 0xf4) = LZCOUNT(iVar1) ^ 0x1f;
  if (iVar7 == 1) {
    *(undefined4 *)(param_1 + 0x10c) = 3;
  }
  else {
    *(undefined4 *)(param_1 + 0x10c) = 0;
  }
  if (iVar7 < 3) {
    iVar2 = iVar1 - (iVar1 * 9) / 100;
    *(int *)(param_1 + 0x110) = iVar2;
  }
  else {
    *(int *)(param_1 + 0x110) = iVar1;
    iVar2 = iVar1;
  }
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0x10c);
  *(int *)(param_1 + 0x108) = iVar2;
  if (iVar7 < 3) {
    *(undefined4 *)(param_1 + 0x11c) = 3;
    if (*(int *)(param_1 + 0x34) < 0x2e1) {
      if (31999 < *(int *)(param_1 + 0x50)) {
        *(undefined4 *)(param_1 + 0x11c) = 1;
      }
      goto LAB_40aeceac;
    }
    if ((0x4a2 < *(int *)(param_1 + 0x34)) || (*(int *)(param_1 + 0x50) < 32000)) goto LAB_40aeceac;
  }
  *(undefined4 *)(param_1 + 0x11c) = 2;
LAB_40aeceac:
  if (*(int *)(param_1 + 0x1a4) == 0) {
    if (*(int *)(param_1 + 0x1a8) == 0) {
      *(undefined4 *)(param_1 + 0x1b4) = *(undefined4 *)(param_1 + 0xf8);
      *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x108);
      *(int *)(param_1 + 0x1b8) = iVar1;
    }
    else {
      *(int *)(param_1 + 0x1b4) = *(int *)(param_1 + 0xf8) << (*(uint *)(param_1 + 0x1b0) & 0x1f);
      *(int *)(param_1 + 0x1b8) = iVar1 << (*(uint *)(param_1 + 0x1b0) & 0x1f);
      *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x108);
    }
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x1b0);
    *(int *)(param_1 + 0x1b4) = *(int *)(param_1 + 0xf8) >> (uVar6 & 0x1f);
    *(int *)(param_1 + 0x1b8) = iVar1 >> (uVar6 & 0x1f);
    *(int *)(param_1 + 0x1bc) = *(int *)(param_1 + 0x108) >> (uVar6 & 0x1f);
  }
  if (iVar7 < 3) {
    iVar1 = iVar1 * *(int *)(param_1 + 0x30);
    iVar7 = iVar1 + 0x1000;
    if (iVar7 < 0) {
      iVar7 = iVar1 + 0x2fff;
    }
    *(uint *)(param_1 + 0xc) = (LZCOUNT(iVar7 >> 0xd) ^ 0x1fU) + 2;
  }
  else {
    *(uint *)(param_1 + 0xc) = (LZCOUNT(*(undefined4 *)(param_1 + 0x10)) ^ 0x1fU) + 1;
  }
  thunk_FUN_40ae8508();
  if (2 < *(int *)(param_1 + 0x40)) {
    if ((*(uint *)(param_1 + 0x44) & 0xfe00) != 0) {
      return -0x7ffc0000;
    }
    *(undefined4 *)(param_1 + 0x224) = 1;
    if ((*(uint *)(param_1 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(param_1 + 0x230) = 1;
    }
  }
  *(undefined4 *)(param_1 + 0x2c4) = 0;
  if (2 < *(int *)(param_1 + 0x40)) {
    if ((*(uint *)(param_1 + 0x44) & 0x80) != 0) {
      *(undefined4 *)(param_1 + 0x244) = 1;
    }
    if (*(short *)(param_1 + 0x58) == 1) {
      *(undefined4 *)(param_1 + 0x2c4) = 1;
    }
    if ((*(uint *)(param_1 + 0x44) & 0x100) != 0) {
      *(undefined4 *)(param_1 + 0x74) = 1;
    }
  }
  return iVar5;
}



/* 40aed06c FUN_40aed06c */

/* Boundary evidence: original MIPS .pdata 40aed06c..40aed3f7. Semantic name remains unreviewed. */

undefined4 FUN_40aed06c(int param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  uint uVar4;
  size_t _Size;
  size_t _Size_00;
  
  iVar1 = 1 << (*(int *)(param_1 + 0x60) - 1U & 0x1f);
  _Size_00 = (uint)*(ushort *)(param_1 + 0x58) * 4;
  *(int *)(param_1 + 0x2ac) = -iVar1;
  *(int *)(param_1 + 0x2a8) = iVar1 + -1;
  pvVar2 = malloc(_Size_00);
  *(void **)(param_1 + 0x154) = pvVar2;
  if (pvVar2 != (void *)0x0) {
    memset(pvVar2,0,_Size_00);
    _Size = (uint)*(ushort *)(param_1 + 0x58) << 2;
    pvVar2 = malloc(_Size);
    *(void **)(param_1 + 0x158) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memset(pvVar2,0,_Size);
      pvVar2 = malloc(_Size_00 + 0x20);
      if (pvVar2 == (void *)0x0) {
        *(undefined4 *)(param_1 + 0x15c) = 0;
        return 0x8007000e;
      }
      pvVar3 = (void *)((int)pvVar2 + 0x20U & 0xffffffe0);
      *(char *)((int)pvVar3 + -1) = (char)pvVar3 - (char)pvVar2;
      *(void **)(param_1 + 0x15c) = pvVar3;
      if (pvVar3 != (void *)0x0) {
        memset(pvVar3,0,_Size_00);
        pvVar2 = malloc(_Size_00 + 0x20);
        if (pvVar2 == (void *)0x0) {
          *(undefined4 *)(param_1 + 0x160) = 0;
        }
        else {
          pvVar3 = (void *)((int)pvVar2 + 0x20U & 0xffffffe0);
          *(char *)((int)pvVar3 + -1) = (char)pvVar3 - (char)pvVar2;
          *(void **)(param_1 + 0x160) = pvVar3;
          if (pvVar3 != (void *)0x0) {
            memset(pvVar3,0,_Size_00);
            if (*(int *)(param_1 + 0x1a8) == 0) {
              iVar1 = (*(int *)(param_1 + 0xfc) * 3) / 2;
            }
            else {
              iVar1 = (*(int *)(param_1 + 0xfc) * 3) / 2 << (*(uint *)(param_1 + 0x1b0) & 0x1f);
            }
            pvVar2 = malloc(iVar1 * 4 * (uint)*(ushort *)(param_1 + 0x58) + 0x20);
            if (pvVar2 == (void *)0x0) {
              *(undefined4 *)(param_1 + 0x138) = 0;
              return 0x8007000e;
            }
            uVar4 = (int)pvVar2 + 0x20U & 0xffffffe0;
            *(char *)(uVar4 - 1) = (char)uVar4 - (char)pvVar2;
            *(uint *)(param_1 + 0x138) = uVar4;
            if (uVar4 != 0) {
              pvVar2 = malloc(*(int *)(param_1 + 0xf0) << 2);
              *(void **)(param_1 + 0x144) = pvVar2;
              if (pvVar2 != (void *)0x0) {
                pvVar2 = malloc(*(int *)(param_1 + 0xf0) * 0x74);
                *(void **)(param_1 + 0x148) = pvVar2;
                if (pvVar2 != (void *)0x0) {
                  FUN_40af2be0(param_1);
                  pvVar2 = malloc(*(int *)(param_1 + 0xf0) << 2);
                  *(void **)(param_1 + 0x150) = pvVar2;
                  if (pvVar2 != (void *)0x0) {
                    pvVar2 = malloc((uint)*(ushort *)(param_1 + 0x58) * 0x70);
                    *(void **)(param_1 + 0x13c) = pvVar2;
                    if (pvVar2 != (void *)0x0) {
                      pvVar2 = malloc(*(int *)(param_1 + 0xf0) << 2);
                      *(void **)(param_1 + 0x18c) = pvVar2;
                      if (pvVar2 != (void *)0x0) {
                        pvVar2 = malloc((uint)*(ushort *)(param_1 + 0x58) *
                                        *(int *)(param_1 + 0x124));
                        *(void **)(param_1 + 400) = pvVar2;
                        if (pvVar2 != (void *)0x0) {
                          pvVar2 = malloc((uint)*(ushort *)(param_1 + 0x58) *
                                          *(int *)(param_1 + 0x124) * 4);
                          *(void **)(param_1 + 0x198) = pvVar2;
                          if (pvVar2 != (void *)0x0) {
                            pvVar2 = malloc((uint)*(ushort *)(param_1 + 0x58) *
                                            *(int *)(param_1 + 0x124) * 8);
                            *(void **)(param_1 + 0x194) = pvVar2;
                            if (pvVar2 != (void *)0x0) {
                              pvVar2 = malloc((uint)*(ushort *)(param_1 + 0x58) << 2);
                              *(void **)(param_1 + 0x1fc) = pvVar2;
                              if (pvVar2 != (void *)0x0) {
                                pvVar2 = malloc((uint)*(ushort *)(param_1 + 0x58) << 2);
                                *(void **)(param_1 + 0x200) = pvVar2;
                                if (pvVar2 != (void *)0x0) {
                                  pvVar2 = malloc((uint)*(ushort *)(param_1 + 0x58) << 1);
                                  *(void **)(param_1 + 0x220) = pvVar2;
                                  if (pvVar2 != (void *)0x0) {
                                    pvVar2 = malloc((uint)*(ushort *)(param_1 + 0x58) << 1);
                                    *(void **)(param_1 + 0x2c0) = pvVar2;
                                    if (pvVar2 != (void *)0x0) {
                                      if (*(int *)(param_1 + 0x114) != 0) {
                                        return 0;
                                      }
                                      if (*(int *)(param_1 + 0x19c) != 0) {
                                        return 0;
                                      }
                                      if (*(int *)(param_1 + 0x1a8) == 0) {
                                        iVar1 = *(int *)(param_1 + 0xfc);
                                      }
                                      else {
                                        iVar1 = *(int *)(param_1 + 0xfc) <<
                                                (*(uint *)(param_1 + 0x1b0) & 0x1f);
                                      }
                                      pvVar2 = malloc(iVar1 * 4 * (uint)*(ushort *)(param_1 + 0x58))
                                      ;
                                      *(void **)(param_1 + 0x19c) = pvVar2;
                                      if (pvVar2 != (void *)0x0) {
                                        return 0;
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
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0x8007000e;
}



/* 40aed3f8 FUN_40aed3f8 */

/* Boundary evidence: original MIPS .pdata 40aed3f8..40aed673. Semantic name remains unreviewed. */

int FUN_40aed3f8(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5,
                undefined4 param_6,undefined2 param_7,undefined4 param_8,undefined4 param_9,
                int param_10,ushort param_11,int param_12,ushort *param_13)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_13 == (ushort *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)*param_13;
  }
  iVar1 = param_10 << 3;
  *(undefined4 *)(param_1 + 0xfc) = param_3;
  *(undefined4 *)(param_1 + 0x50) = param_4;
  *(undefined2 *)(param_1 + 0x58) = param_5;
  *(undefined4 *)(param_1 + 0x5c) = param_6;
  *(undefined2 *)(param_1 + 100) = param_7;
  *(undefined4 *)(param_1 + 0x6c) = param_8;
  *(undefined4 *)(param_1 + 0x54) = param_9;
  *(uint *)(param_1 + 0x44) = (uint)param_11;
  *(int *)(param_1 + 0x40) = param_2;
  *(int *)(param_1 + 0x10) = iVar1;
  *(int *)(param_1 + 0x240) = iVar1 >> 3;
  *(uint *)(param_1 + 0x238) = (LZCOUNT(iVar1 >> 3) ^ 0x1fU) + 1;
  *(uint *)(param_1 + 0x23c) = (LZCOUNT(iVar1) ^ 0x1fU) + 1;
  if (*(int *)(param_1 + 0xa8) == 1) {
    uVar2 = 0xff7f;
  }
  else {
    uVar2 = 0xfe75;
    if (param_2 < 3) {
      uVar2 = 0xff75;
    }
  }
  if (((uVar2 & uVar3) == 0) && ((&DAT_40b13988)[uVar3 & 0xf] != '\0')) {
    if ((uVar3 & 10) == 10) {
      uVar3 = 0;
    }
    iVar1 = *(int *)(param_1 + 0x50);
    *(int *)(param_1 + 0x1ac) = iVar1;
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    if ((uVar3 & 2) == 0) {
      if ((uVar3 & 8) == 0) {
        if (param_12 != iVar1) {
          if (param_12 == 0) {
            trap(7);
          }
          uVar3 = LZCOUNT(iVar1 / param_12) ^ 0x1f;
          *(uint *)(param_1 + 0x1b0) = uVar3;
          if (uVar3 == 0) {
            *(int *)(param_1 + 0x1ac) = iVar1;
          }
          else {
            *(int *)(param_1 + 0x1ac) = iVar1 >> (uVar3 & 0x1f);
          }
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x1b0) = 0xffffffff;
        *(int *)(param_1 + 0x1ac) = iVar1 << 1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1b0) = 1;
      *(int *)(param_1 + 0x1ac) = iVar1 >> 1;
    }
    iVar1 = *(int *)(param_1 + 0x1b0);
    *(undefined4 *)(param_1 + 0x1a4) = 0;
    *(undefined4 *)(param_1 + 0x1a8) = 0;
    if (iVar1 < 0) {
      *(int *)(param_1 + 0x1b0) = -iVar1;
      *(undefined4 *)(param_1 + 0x1a8) = 1;
    }
    else if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x1a4) = 1;
    }
    iVar1 = FUN_40aecb90(param_1);
    if (-1 < iVar1) {
      *(undefined1 **)(param_1 + 0x1e8) = &LAB_40aeb1a0;
      *(undefined1 **)(param_1 + 0x1ec) = &LAB_40aeaf94;
      *(code **)(param_1 + 0x1d0) = FUN_40ae4f3c;
      *(code **)(param_1 + 0x1e4) = FUN_40ae47b0;
      *(code **)(param_1 + 0x1cc) = FUN_40aeae90;
      if (*(int *)(param_1 + 0x114) == 1) {
        if (*(int *)(param_1 + 0x2c) == 0) {
          *(undefined4 *)(param_1 + 0x1c0) = 0;
        }
        else {
          *(code **)(param_1 + 0x1c0) = FUN_40ae66b4;
        }
      }
      else {
        *(code **)(param_1 + 0x1c0) = FUN_40ae75dc;
      }
      iVar1 = FUN_40aed06c(param_1);
      if ((-1 < iVar1) && (iVar1 = FUN_40ae5890(param_1), -1 < iVar1)) {
        iVar1 = FUN_40aebca4(param_1);
        return iVar1;
      }
    }
  }
  else {
    iVar1 = -0x7ffc0000;
  }
  return iVar1;
}



/* 40aed67c FUN_40aed67c */

undefined4 FUN_40aed67c(ushort *param_1,uint *param_2,ushort *param_3)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == (ushort *)0x0) {
    return 0x80070057;
  }
  if (param_2 == (uint *)0x0) {
    return 0x80070057;
  }
  uVar2 = *param_1;
  if (3 < (ushort)(uVar2 - 0x160)) {
    return 0x80040000;
  }
  if (uVar2 < 0x162) {
    uVar4 = *(uint *)(param_1 + 2);
    if (48000 < uVar4) {
      return 0x80040000;
    }
    if (2 < param_1[1]) {
      return 0x80040000;
    }
    if (param_1[7] != 0x10) {
      return 0x80040000;
    }
  }
  else {
    if (uVar2 == 0x162) {
      return 0x80040000;
    }
    if (uVar2 == 0x163) {
      return 0x80040000;
    }
    uVar4 = *(uint *)(param_1 + 2);
  }
  if (uVar4 == 0) {
    return 0x80040000;
  }
  uVar5 = (uint)param_1[1];
  if (uVar5 == 0) {
    return 0x80040000;
  }
  uVar3 = param_2[4];
  if (1 < uVar3 - 2) {
    return 0x80040000;
  }
  if ((param_2[3] == 0x10) && (uVar3 != 2)) {
    return 0x80070057;
  }
  uVar2 = param_1[7];
  if (((uVar2 != 0x10) && (uVar2 != 0x14)) && (uVar2 != 0x18)) {
    return 0x80040000;
  }
  if (uVar3 < param_2[3] + 7 >> 3) {
    return 0x80040000;
  }
  if (*(int *)(param_1 + 4) < 0) {
    return 0x80070057;
  }
  if (param_1[6] == 0) {
    return 0x80070057;
  }
  if (param_2[1] == uVar5) {
    if (param_2[2] != *(uint *)(param_1 + 8)) {
      return 0x80040000;
    }
  }
  else {
    if (param_2[1] != 2) {
      return 0x80070057;
    }
    if (uVar5 != 6) {
      return 0x80070057;
    }
  }
  if (param_3 == (ushort *)0x0) {
    uVar5 = *param_2;
  }
  else {
    if (2 < param_3[0xc]) {
      return 0x80040000;
    }
    if ((*param_3 & 8) != 0) {
      uVar4 = uVar4 << 1;
    }
    uVar5 = *param_2;
    if ((*param_3 & 2) != 0) {
      uVar4 = uVar4 >> 1;
    }
  }
  uVar3 = uVar4 << 1;
  if (uVar4 == uVar5) {
    return 0;
  }
  if (uVar3 != uVar5) {
    return 0;
  }
  if (uVar5 == 0x5622) {
    if (uVar4 == 32000) {
      return 0;
    }
  }
  else if (uVar5 == 0xac44) goto LAB_40aed84c;
  if (uVar3 != 48000) {
    return 0x80040000;
  }
LAB_40aed84c:
  if (uVar3 == 0) {
    trap(7);
  }
  uVar5 = uVar4 << 2;
  if (uVar4 % uVar3 != 0) {
    bVar1 = uVar3 != 0xac44;
    uVar3 = 48000;
    if (bVar1) {
      return 0x80040000;
    }
    uVar5 = 96000;
  }
  if (uVar4 != uVar5) {
    if (uVar3 << 2 != uVar4) {
      return 0x80040000;
    }
    return 0;
  }
  return 0;
}



/* 40aed8ec FUN_40aed8ec */

/* WARNING: Removing unreachable block (ram,0x40aedbf8) */
/* WARNING: Removing unreachable block (ram,0x40aedc00) */
/* Boundary evidence: original MIPS .pdata 40aed8ec..40aedc33. Semantic name remains unreviewed. */

int FUN_40aed8ec(int *param_1,undefined4 param_2,int param_3,uint param_4,int param_5,int param_6,
                int param_7,int param_8,int *param_9,uint *param_10)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint auStack_28 [2];
  
  if (param_1[0x85] != 1) {
    iVar3 = -0x7ffbfff6;
    goto LAB_40aed97c;
  }
  iVar3 = 0;
  iVar2 = param_1[0x89];
  if (((iVar2 != 0) && (param_1[0x86] != 0)) && (param_4 == 0)) {
    param_1[0x85] = 1;
    goto LAB_40aed97c;
  }
  param_1[0x85] = 0;
  if (param_3 == 0) {
LAB_40aedb10:
    param_1[0x88] = 1;
    param_1[0x4b] = (int)&LAB_40af71d0;
    param_1[0x4c] = (int)&LAB_40af7510;
  }
  else {
    if ((param_4 == 0) || (param_6 == 0)) {
LAB_40aeda20:
      if (iVar2 != 0) {
LAB_40aedb3c:
        if (param_1[0x86] != 0) {
          FUN_40af71b4((int)(param_1 + 0x39));
          iVar2 = param_1[0x89];
          param_1[0x4b] = (int)&LAB_40af7308;
          param_1[0x4c] = (int)FUN_40af7430;
        }
      }
      iVar3 = *param_1;
    }
    else {
      if (1 < (short)param_1[0x27]) {
        iVar3 = -0x7ffbfff6;
        goto LAB_40aed97c;
      }
      if ((param_1[0x28] != param_7) || (param_1[0x29] != param_8)) {
        if (param_1[0x26] == 0) {
          param_1[0x28] = param_7;
          param_1[0x29] = param_8;
          *(undefined2 *)(param_1 + 0x27) = 1;
          param_1[0x26] = 1;
        }
        else {
          iVar3 = (*(ushort *)(param_1 + 0x27) + 1) * 0x10000;
          param_1[0x2a] = param_7;
          param_1[0x2b] = param_8;
          *(short *)(param_1 + 0x27) = (short)((uint)iVar3 >> 0x10);
          if (iVar3 >> 0x10 != 2) {
            iVar3 = -0x7ffbfff6;
            goto LAB_40aed97c;
          }
        }
        goto LAB_40aeda20;
      }
      if (iVar2 != 0) goto LAB_40aedb3c;
      iVar3 = *param_1;
    }
    piVar4 = param_1 + 0x39;
    iVar3 = FUN_40af79a8((int)piVar4,param_2,param_3,iVar2 == 0 & param_4,*(int *)(iVar3 + 0x40));
    if (iVar3 < 0) goto LAB_40aed97c;
    if (iVar3 == 6) {
      *(undefined4 *)(*param_1 + 0x48) = 6;
      param_1[0x86] = 1;
    }
    if (param_1[0x89] != 0) {
      if (param_4 == 0) {
        if ((param_10 != (uint *)0x0) && (*param_10 != 0)) {
          iVar3 = -0x7ff8ffa9;
          goto LAB_40aed97c;
        }
      }
      else {
        FUN_40af76f8((int)piVar4,0,0);
        if (param_10 != (uint *)0x0) {
          uVar1 = *param_10;
          if (uVar1 != 0) {
            if (7 < (int)uVar1) {
              iVar3 = -0x7ff8ffa9;
              goto LAB_40aed97c;
            }
            if (param_1[0x86] == 0) {
              uVar1 = FUN_40af7894((int)piVar4);
              iVar3 = FUN_40af76f8((int)piVar4,uVar1,*param_10);
            }
            else {
              iVar3 = FUN_40af7430((int)piVar4,uVar1);
              if (iVar3 < 0) goto LAB_40aed97c;
              iVar3 = FUN_40af774c((int)piVar4,*param_10,auStack_28);
            }
            if (iVar3 < 0) goto LAB_40aed97c;
          }
        }
      }
    }
    if (param_5 != 0) goto LAB_40aedb10;
  }
  param_1[0x85] = 2;
LAB_40aed97c:
  if (param_9 != (int *)0x0) {
    *param_9 = param_1[0x85];
  }
  return iVar3;
}



/* 40aedc34 FUN_40aedc34 */

/* Boundary evidence: original MIPS .pdata 40aedc34..40aedeb7. Semantic name remains unreviewed. */

void FUN_40aedc34(int *param_1)

{
  bool bVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  int iVar19;
  
  iVar17 = *param_1;
  uVar18 = *(undefined4 *)(iVar17 + 0x1b8);
  memset((void *)param_1[2],0,(uint)*(ushort *)(iVar17 + 0x58) << 3);
  if (*(short *)(iVar17 + 0x58) != 0) {
    iVar16 = (int)(short)uVar18;
    iVar15 = *(int *)(iVar17 + 0x134);
    iVar19 = (iVar16 * 3) / 2;
    iVar12 = 0;
    iVar13 = 0;
    iVar11 = 0;
    iVar14 = 1;
    do {
      puVar10 = (undefined4 *)(iVar15 + iVar12);
      *puVar10 = 0;
      iVar8 = *(int *)(iVar17 + 0x104);
      iVar5 = *(int *)(iVar17 + 0x108);
      puVar10[1] = *(int *)(iVar17 + 0x13c) + iVar13;
      iVar3 = *(int *)(iVar17 + 0x140);
      puVar10[9] = iVar5 - iVar8;
      puVar10[10] = 0;
      puVar10[0xd] = 0;
      iVar6 = *(int *)(iVar17 + 0x1a8);
      puVar10[2] = iVar3 + iVar13;
      puVar10[6] = 0;
      puVar10[7] = 0;
      puVar10[8] = 0;
      iVar8 = *(int *)(iVar17 + 0x138);
      iVar3 = iVar16 / 2;
      iVar5 = iVar19;
      if (iVar6 != 0) {
        iVar3 = iVar16 / 2 << (*(uint *)(iVar17 + 0x1b0) & 0x1f);
        iVar5 = iVar19 << (*(uint *)(iVar17 + 0x1b0) & 0x1f);
      }
      puVar10[0x11] = 0;
      puVar10[0x14] = 0;
      puVar10[0x15] = 0;
      puVar10[0x16] = 0;
      puVar10[0x17] = 0;
      puVar10[0x18] = 0;
      puVar10[0x19] = 0;
      puVar10[0x1a] = 0;
      puVar10[0x1b] = 0;
      puVar10[0x1c] = 0;
      puVar10[0x1d] = 0;
      puVar10[0x28] = 0;
      iVar6 = *(int *)(iVar17 + 0x114);
      iVar8 = iVar8 + iVar11 * iVar5 * 4 + iVar3 * 4;
      puVar10[0x26] = iVar8;
      puVar10[0xf] = iVar8;
      *(undefined2 *)(puVar10 + 0x13) = 0x7fff;
      *(undefined2 *)(puVar10 + 0x20) = 0;
      *(undefined2 *)((int)puVar10 + 0x82) = 0;
      *(undefined2 *)(puVar10 + 0x21) = 0;
      *(undefined2 *)((int)puVar10 + 0x86) = 0;
      *(undefined2 *)(puVar10 + 0x22) = 0;
      *(undefined2 *)((int)puVar10 + 0x8a) = 0;
      *(undefined2 *)(puVar10 + 0x23) = 0;
      *(undefined2 *)(puVar10 + 0x1e) = 0;
      *(undefined2 *)(puVar10 + 0x1f) = 0;
      if (iVar6 == 0) {
        iVar5 = *(int *)(iVar17 + 0x1a8);
        iVar3 = iVar16;
        if (iVar5 == 0) {
          puVar10[0xe] = *(int *)(iVar17 + 0x19c) + iVar16 * iVar11 * 4;
          iVar8 = *(int *)(iVar17 + 0x19c);
        }
        else {
          puVar10[0xe] = *(int *)(iVar17 + 0x19c) +
                         (iVar16 << (*(uint *)(iVar17 + 0x1b0) & 0x1f)) * iVar11 * 4;
          iVar8 = *(int *)(iVar17 + 0x19c);
          if (iVar5 != 0) {
            iVar3 = iVar16 << (*(uint *)(iVar17 + 0x1b0) & 0x1f);
          }
        }
        puVar10[0x27] = iVar8 + iVar3 * iVar11 * 4;
      }
      else {
        uVar18 = *(undefined4 *)(iVar15 + iVar12 + 4);
        puVar10[0x27] = uVar18;
        puVar10[0xe] = uVar18;
      }
      puVar2 = (undefined2 *)puVar10[0x32];
      puVar7 = *(undefined2 **)(puVar2 + 4);
      iVar11 = iVar11 * *(int *)(iVar17 + 0x124);
      puVar9 = *(undefined2 **)(puVar2 + 6);
      uVar18 = *(undefined4 *)(iVar17 + 0xfc);
      *puVar2 = 1;
      puVar10[3] = 0;
      uVar4 = (undefined2)uVar18;
      puVar7[-1] = uVar4;
      *puVar7 = uVar4;
      puVar10[4] = 0;
      puVar10[5] = 0;
      *puVar9 = 0;
      iVar3 = *(int *)(iVar17 + 0x194);
      iVar5 = *(int *)(iVar17 + 0x198);
      bVar1 = iVar14 < (int)(uint)*(ushort *)(iVar17 + 0x58);
      puVar10[3] = *(int *)(iVar17 + 400) + iVar11;
      puVar10[4] = iVar3 + iVar11 * 8;
      puVar10[5] = iVar5 + iVar11 * 4;
      *(undefined4 *)(iVar15 + iVar12 + 0xb4) = 0;
      iVar12 = iVar12 + 0x594;
      iVar13 = iVar13 + 0x70;
      iVar11 = iVar14;
      iVar14 = iVar14 + 1;
    } while (bVar1);
  }
  return;
}



/* 40aedeb8 FUN_40aedeb8 */

/* Boundary evidence: original MIPS .pdata 40aedeb8..40aee03b. Semantic name remains unreviewed. */

undefined4 FUN_40aedeb8(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  
  if (param_1 != (int *)0x0) {
    iVar8 = *param_1;
    piVar9 = param_1 + 0x39;
    if (iVar8 != 0) {
      FUN_40af71b4((int)piVar9);
      FUN_40af7888((int)piVar9);
      FUN_40af78d4((int)piVar9,0);
      FUN_40af78e4((int)piVar9,0);
      memset(*(void **)(iVar8 + 0x154),0,(uint)*(ushort *)(iVar8 + 0x58) << 2);
      *(undefined4 *)(iVar8 + 0x48) = 3;
      *(undefined4 *)(iVar8 + 8) = 0xfffffffe;
      *(undefined4 *)(iVar8 + 0x174) = 0;
      *(undefined4 *)(iVar8 + 0x178) = 0;
      if (*(short *)(iVar8 + 0x58) != 0) {
        iVar6 = *(int *)(iVar8 + 0xfc);
        iVar7 = *(int *)(iVar8 + 0x134);
        iVar4 = 0;
        iVar3 = 0;
        do {
          iVar1 = iVar7 + iVar3;
          uVar5 = (undefined2)(iVar6 / 2);
          *(undefined2 *)(iVar1 + 0x80) = uVar5;
          iVar2 = *(int *)(*(int *)(iVar1 + 200) + 8);
          *(undefined2 *)(iVar1 + 0x82) = uVar5;
          *(short *)(iVar2 + -2) = (short)iVar6;
          *(undefined2 *)(iVar1 + 0x7a) = 0;
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0x594;
        } while (iVar4 < (int)(uint)*(ushort *)(iVar8 + 0x58));
      }
      *(undefined4 *)(iVar8 + 0x2dc) = 0;
      *(undefined4 *)(iVar8 + 0x2c8) = 0;
      *(undefined4 *)(iVar8 + 0x2cc) = 0;
      *(undefined4 *)(iVar8 + 0x2d4) = 0;
      *(undefined4 *)(iVar8 + 0x2d0) = 0;
      *(undefined4 *)(iVar8 + 0x2d8) = 0;
      param_1[3] = 1;
      param_1[5] = 0;
      FUN_40af78ec((int)piVar9,0xfffffffe);
      param_1[0x2f] = 2;
      param_1[0x2a] = 0;
      param_1[0x28] = 0;
      param_1[0x86] = 1;
      param_1[0x2b] = -0x80000000;
      param_1[0x2c] = 0;
      param_1[0x2d] = 0;
      param_1[0x2e] = 0;
      param_1[0xf] = 0;
      param_1[0x85] = 1;
      param_1[0x88] = 0;
      param_1[0x26] = 0;
      param_1[0x29] = -0x80000000;
      *(undefined2 *)(param_1 + 0x27) = 0;
      param_1[8] = 0;
      FUN_40aef200(param_1);
    }
  }
  return 0;
}



/* 40aee03c FUN_40aee03c */

/* WARNING: Removing unreachable block (ram,0x40aee0b4) */
/* WARNING: Removing unreachable block (ram,0x40aee270) */
/* WARNING: Removing unreachable block (ram,0x40aee22c) */
/* WARNING: Removing unreachable block (ram,0x40aee29c) */
/* Boundary evidence: original MIPS .pdata 40aee03c..40aee2b7. Semantic name remains unreviewed. */

int FUN_40aee03c(int *param_1,uint *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort local_30 [6];
  
  iVar3 = *param_1;
  iVar4 = 0;
  if (((iVar3 == 0) || (param_2 == (uint *)0x0)) || (param_3 == (int *)0x0)) {
    iVar4 = -0x7ff8ffa9;
    iVar2 = param_1[0x89];
    param_1[0x85] = 0;
    goto LAB_40aee188;
  }
  if (param_1[0x85] != 2) {
    iVar1 = -0x7ffbfff6;
LAB_40aee204:
    iVar2 = param_1[0x89];
LAB_40aee208:
    param_1[0x85] = 0;
    iVar4 = iVar1;
    goto LAB_40aee188;
  }
  iVar2 = *(int *)(iVar3 + 0x48);
  param_1[0x85] = 0;
  *param_2 = 0;
  if (iVar2 == 2) {
    iVar2 = param_1[0x89];
LAB_40aee224:
    iVar4 = 0;
  }
  else {
    if (param_1[0x86] == 0) {
LAB_40aee134:
      local_30[0] = 0;
      iVar1 = FUN_40af0864(param_1,local_30,(short *)0x0);
      *param_2 = (uint)local_30[0];
      if (iVar1 == -0x7ffbfffe) {
        FUN_40aedeb8(param_1);
        iVar2 = param_1[0x89];
        goto LAB_40aee224;
      }
      if (iVar1 == 4) {
        param_1[0x86] = 1;
        *(undefined4 *)(iVar3 + 0x48) = 6;
        iVar2 = param_1[0x89];
        iVar4 = iVar1;
        goto LAB_40aee188;
      }
      if (iVar1 != -0x7ffbfffc) {
        iVar2 = param_1[0x89];
        *(undefined4 *)(iVar3 + 0x48) = 7;
        iVar4 = iVar1;
        if (-1 < iVar1) goto LAB_40aee188;
        goto LAB_40aee208;
      }
    }
    else {
      iVar2 = 0;
      do {
        iVar1 = FUN_40af1234(param_1);
        iVar2 = iVar2 + 1;
        if (iVar1 != -0x7ffbfffe) {
          if (iVar1 != -0x7ffbfffc) {
            if (iVar1 < 0) goto LAB_40aee204;
            param_1[0x86] = 0;
            goto LAB_40aee134;
          }
          break;
        }
        FUN_40aedeb8(param_1);
      } while (iVar2 != 0xf4242);
    }
    if (param_1[0x88] == 0) {
      iVar2 = param_1[0x89];
      param_1[0x85] = 1;
    }
    else {
      iVar2 = param_1[0x89];
      param_1[0x85] = (uint)(iVar2 != 0);
    }
  }
LAB_40aee188:
  if (((iVar2 != 0) && (param_1[0x86] != 0)) && (param_1[0x85] == 2)) {
    param_1[0x85] = 1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = param_1[0x85];
  }
  return iVar4;
}



/* 40aee2b8 FUN_40aee2b8 */

/* Boundary evidence: original MIPS .pdata 40aee2b8..40aee3ef. Semantic name remains unreviewed. */

undefined4 FUN_40aee2b8(int *param_1,int param_2,undefined4 param_3,va_list param_4)

{
  short sVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined *_Dst;
  int iVar8;
  int iVar9;
  
  iVar9 = *param_1;
  sVar1 = *(short *)(iVar9 + 0x58);
  param_1[2] = (int)&DAT_40b1b250;
  if (sVar1 != 0) {
    puVar7 = &DAT_40b1b220;
    _Dst = &DAT_40b1b100;
    iVar8 = 1;
    do {
      *(undefined4 **)(param_2 + 200) = puVar7;
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[3] = 0;
      puVar7[4] = 0;
      puVar7[5] = 0;
      uVar6 = 0x47;
      puVar7 = puVar7 + 6;
      if (0x20 < *(int *)(iVar9 + 0xe0)) {
        sVar3 = FUN_40aff968(s_pau_>m_iMaxSubFrameDiv__d_40b170f0);
        FUN_40aff918(sVar3,*(undefined4 *)(iVar9 + 0xe0),uVar6,param_4);
        return 0x8007000e;
      }
      *(undefined **)(*(int *)(param_2 + 200) + 4) = _Dst;
      memset(_Dst,0,0x47);
      iVar5 = *(int *)(param_2 + 200);
      iVar4 = *(int *)(iVar5 + 4) + 2;
      iVar2 = iVar4 + (*(int *)(iVar9 + 0xe0) + 1) * 2;
      param_4 = (va_list)(uint)(iVar8 < (int)(uint)*(ushort *)(iVar9 + 0x58));
      *(int *)(iVar5 + 0x10) = iVar2 + 2;
      *(int *)(iVar5 + 8) = iVar4;
      *(int *)(iVar5 + 0xc) = iVar2;
      param_2 = param_2 + 0x594;
      _Dst = _Dst + 0x8e;
      iVar8 = iVar8 + 1;
    } while (param_4 != (va_list)0x0);
  }
  return 0;
}



/* 40aee3f0 FUN_40aee3f0 */

/* Boundary evidence: original MIPS .pdata 40aee3f0..40aee4fb. Semantic name remains unreviewed. */

undefined4 FUN_40aee3f0(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if (iVar1 != 0) {
      FUN_40aeafe4();
    }
    FUN_40aea73c();
    param_1[1] = 0;
    if ((void *)param_1[0x60] != (void *)0x0) {
      FUN_40aec048((void *)param_1[0x60]);
    }
    if ((void *)param_1[0x56] != (void *)0x0) {
      FUN_40aec048((void *)param_1[0x56]);
    }
    if ((void *)param_1[0x55] != (void *)0x0) {
      FUN_40aec048((void *)param_1[0x55]);
    }
    if ((void *)param_1[0x65] != (void *)0x0) {
      FUN_40aec048((void *)param_1[0x65]);
      param_1[0x65] = 0;
    }
    if ((void *)param_1[0x69] != (void *)0x0) {
      FUN_40aec048((void *)param_1[0x69]);
      param_1[0x69] = 0;
    }
    if ((void *)param_1[0x6a] != (void *)0x0) {
      FUN_40aec048((void *)param_1[0x6a]);
      param_1[0x6a] = 0;
    }
    if ((void *)param_1[0x67] != (void *)0x0) {
      FUN_40aec048((void *)param_1[0x67]);
      param_1[0x67] = 0;
    }
    if (iVar1 != 0) {
      FUN_40aec930((void *)*param_1);
      *param_1 = 0;
    }
  }
  return 0;
}



/* 40aee4fc FUN_40aee4fc */

/* Boundary evidence: original MIPS .pdata 40aee4fc..40aee587. Semantic name remains unreviewed. */

int FUN_40aee4fc(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_40aee3f0(param_1);
  if (-1 < iVar2) {
    iVar1 = param_1[0x8a];
    memset(param_1,0,0x230);
    param_1[0x86] = 1;
    *(char *)(param_1 + 0x8a) = (char)iVar1;
    param_1[0x2f] = 2;
    param_1[3] = 1;
    param_1[5] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xd] = 2;
    param_1[0xe] = 0;
    param_1[0x37] = 1;
    param_1[0x85] = 0;
  }
  return iVar2;
}



/* 40aee588 FUN_40aee588 */

void FUN_40aee588(int *param_1)

{
  if (param_1 != (int *)0x0) {
    FUN_40aee3f0(param_1);
    return;
  }
  return;
}



/* 40aee5a0 FUN_40aee5a0 */

/* Boundary evidence: original MIPS .pdata 40aee5a0..40aee6ab. Semantic name remains unreviewed. */

undefined * FUN_40aee5a0(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (-1 < param_2)) {
    memset(&DAT_40b1aec0,0,0x230);
    iVar1 = FUN_40aee3f0((int *)&DAT_40b1aec0);
    if (-1 < iVar1) {
      memset(&DAT_40b1aec0,0,0x230);
      DAT_40b1af7c = 2;
      DAT_40b1aef4 = 2;
      DAT_40b1b0d8 = 1;
      DAT_40b1aecc = 1;
      DAT_40b1aed4 = 0;
      DAT_40b1aee0 = 0;
      DAT_40b1aee4 = 0;
      DAT_40b1aee8 = 0;
      DAT_40b1aef8 = 0;
      DAT_40b1af9c = 1;
      DAT_40b1b0d4 = 0;
      DAT_40b1b0e8 = 0;
      return &DAT_40b1aec0;
    }
  }
  return (undefined *)0x0;
}



/* 40aee6ac FUN_40aee6ac */

/* WARNING: Removing unreachable block (ram,0x40aee7ec) */
/* Boundary evidence: original MIPS .pdata 40aee6ac..40aeed17. Semantic name remains unreviewed. */

int FUN_40aee6ac(int *param_1,ushort *param_2,uint *param_3,ushort *param_4,undefined4 *param_5,
                int param_6)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  size_t _Size;
  int iVar7;
  va_list pcVar8;
  
  if (param_1 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  iVar3 = FUN_40aed67c(param_2,param_3,param_4);
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = FUN_40aee3f0(param_1);
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar7 = param_1[0x8a];
  memset(param_1,0,0x230);
  *(char *)(param_1 + 0x8a) = (char)iVar7;
  param_1[0x2f] = 2;
  param_1[0x86] = 1;
  param_1[3] = 1;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xd] = 2;
  param_1[0xe] = 0;
  param_1[0x37] = 1;
  param_1[0x85] = 0;
  if (param_6 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(param_6 + 0xc);
  }
  param_1[0x89] = iVar7;
  puVar4 = FUN_40aebda8();
  *param_1 = (int)puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[0x72] = FUN_40ae3a64;
    if (puVar4[0x12] == 3) {
      return iVar3;
    }
    uVar1 = *param_2;
    if (uVar1 == 0x161) {
      iVar3 = 2;
      bVar2 = false;
    }
    else if (uVar1 < 0x162) {
      iVar3 = 1;
      if (uVar1 != 0x160) {
        return -0x7ffc0000;
      }
      bVar2 = false;
    }
    else if (uVar1 == 0x162) {
      iVar3 = 3;
      bVar2 = false;
    }
    else {
      iVar3 = 3;
      if (uVar1 != 0x163) {
        return -0x7ffc0000;
      }
      bVar2 = true;
    }
    iVar7 = FUN_40ae1000(*(uint *)(param_2 + 2),*(int *)(param_2 + 4) << 3,(uint)param_2[1],iVar3,
                         param_2[10]);
    if (iVar7 < 1) {
      iVar3 = -0x7ffc0000;
    }
    else {
      if (param_4 == (ushort *)0x0) {
        param_1[0x6c] = 0;
        param_1[0x6d] = 0;
        param_1[0x6e] = 0;
        param_1[0x6f] = 0;
        param_1[0x70] = 0;
        param_1[0x71] = 0;
        param_1[0x72] = 0;
      }
      else {
        FUN_40afcef8(param_1 + 0x6c,(int *)param_4,0x1c);
      }
      if ((short)param_1[0x72] != 0) {
        *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 0x80;
      }
      uVar5 = (int)(param_2[7] + 7) >> 3;
      pcVar8 = *(va_list *)(param_2 + 2);
      if (uVar5 < param_3[4]) {
        uVar5 = param_3[4];
      }
      iVar3 = FUN_40aed3f8((int)puVar4,iVar3,iVar7,pcVar8,param_2[1],uVar5,param_2[7],
                           *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                           (uint)param_2[6],param_2[10],*param_3,(ushort *)(param_1 + 0x6c));
      if (-1 < iVar3) {
        _Size = (uint)*(ushort *)(puVar4 + 0x16) * 0x594;
        param_1[1] = (int)&DAT_40b1a380;
        memset(&DAT_40b1a380,0,_Size);
        iVar3 = FUN_40aea900((int)puVar4,param_1[1]);
        if (((-1 < iVar3) && (iVar3 = FUN_40aee2b8(param_1,param_1[1],_Size,pcVar8), -1 < iVar3)) &&
           (iVar3 = FUN_40aea930((int)puVar4,param_1[1]), -1 < iVar3)) {
          puVar4[0x4d] = param_1[1];
          iVar3 = FUN_40aef264(param_1);
          if (-1 < iVar3) {
            if (puVar4[0x89] != 0) {
              param_1[0x75] = (int)&LAB_40ae1368;
              puVar4[0x72] = &LAB_40ae1354;
              param_1[0x76] = 0;
            }
            param_1[0x57] = 0;
            param_1[0x5e] = 0;
            uVar5 = param_3[1];
            uVar1 = *(ushort *)(puVar4 + 0x16);
            param_1[0x59] = uVar5;
            if (uVar5 != uVar1) {
              param_1[0x57] = 1;
            }
            uVar1 = param_2[7];
            param_1[0x58] = 0;
            *(ushort *)(param_1 + 0x5d) = uVar1;
            iVar3 = puVar4[0x17];
            uVar1 = param_2[7];
            param_1[0x5c] = (int)&DAT_40b1a370;
            param_1[0x5a] = iVar3;
            if ((uVar1 != 0x10) && (param_3[3] == 0x10)) {
              param_1[0x58] = 1;
              uVar5 = 2;
              if ((uint)puVar4[0x17] < 3) {
                uVar5 = puVar4[0x17];
              }
              param_1[0x5a] = uVar5;
              uVar6 = puVar4[0x17];
              *(undefined2 *)(param_1 + 0x5d) = 0x10;
              if (uVar5 == uVar6) {
                uVar1 = param_2[7];
                param_1[0x58] = 0;
                *(ushort *)(param_1 + 0x5d) = uVar1;
              }
            }
            uVar5 = *param_3;
            param_1[0x4e] = 0;
            param_1[0x53] = uVar5;
            param_1[0x50] = 0;
            param_1[0x4f] = 0;
            if (uVar5 == puVar4[0x6b] << 1) {
              param_1[0x4e] = 1;
              uVar6 = puVar4[0x6b];
            }
            else {
              uVar6 = uVar5;
              if (uVar5 != puVar4[0x6b]) {
                param_1[0x50] = 1;
                uVar6 = puVar4[0x6b];
                if ((int)uVar5 < (int)uVar6) {
                  param_1[0x4f] = 1;
                  uVar6 = puVar4[0x6b];
                }
              }
            }
            FUN_40aeed40((int)param_1,uVar6,uVar5);
            param_1[0x54] = param_1[0x52];
            if ((param_1[0x51] < 10000) && (param_1[0x52] < 10000)) {
              FUN_40aedc34(param_1);
              if (param_2[1] == 1) {
                param_1[0x74] = (int)FUN_40ae466c;
              }
              else {
                param_1[0x74] = (int)FUN_40ae3fd8;
              }
              FUN_40af716c(param_1 + 0x39,puVar4[0x33]);
              FUN_40af78c4((int)(param_1 + 0x39),param_1);
              iVar3 = puVar4[0x47];
              if (iVar3 == 3) {
                iVar3 = puVar4[0x4d];
                *(undefined **)(iVar3 + 0x20) = &DAT_40b0be58;
                *(undefined **)(iVar3 + 0x18) = &DAT_40b0727c;
                *(undefined **)(iVar3 + 0x1c) = &DAT_40b0baa4;
              }
              else if (iVar3 == 1) {
                iVar3 = puVar4[0x4d];
                *(undefined **)(iVar3 + 0x20) = &DAT_40b0f394;
                *(undefined **)(iVar3 + 0x18) = &DAT_40b0a5d0;
                *(undefined **)(iVar3 + 0x1c) = &DAT_40b0ee64;
              }
              else {
                if (iVar3 != 2) {
                  return -0x7ff8ffa9;
                }
                iVar3 = puVar4[0x4d];
                *(undefined **)(iVar3 + 0x20) = &DAT_40b0d340;
                *(undefined **)(iVar3 + 0x18) = &DAT_40b0794c;
                *(undefined **)(iVar3 + 0x1c) = &DAT_40b0c8d4;
              }
              puVar4[2] = 0xfffffffe;
              puVar4[0x12] = 3;
              param_1[0x1e] = 0;
              iVar3 = FUN_40aeafdc();
              if (-1 < iVar3) {
                puVar4[0x86] = param_1[0x1f];
                puVar4[0x85] = 0;
                if (((puVar4[0x10] == 3) && ((puVar4[0x11] & 1) != 0)) || (bVar2)) {
                  puVar4[0x2a] = 1;
                }
                else {
                  puVar4[0x2a] = 0;
                }
                uVar1 = *(ushort *)(puVar4 + 0x16);
                param_1[0x30] = (int)&DAT_40b1a360;
                puVar4[0xae] = 1;
                memset(&DAT_40b1a360,0,(uint)uVar1 << 2);
                param_1[0x2a] = 0;
                param_1[0x2b] = -0x80000000;
                *(undefined2 *)(param_1 + 0x27) = 0;
                param_1[0x85] = 1;
                param_1[0x86] = 1;
                param_1[0x88] = 0;
                param_1[0x26] = 0;
                param_1[0x28] = 0;
                param_1[0x29] = -0x80000000;
                if (param_5 != (undefined4 *)0x0) {
                  *param_5 = 1;
                }
              }
            }
            else {
              iVar3 = -0x7ffc0000;
            }
          }
        }
      }
    }
    return iVar3;
  }
  return -0x7ff8fff2;
}



/* 40aeed40 FUN_40aeed40 */

void FUN_40aeed40(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x144) = param_2;
  *(int *)(param_1 + 0x148) = param_3;
  if (0 < param_2) {
    bVar1 = param_2 < param_3;
    iVar2 = param_3;
    do {
      param_3 = iVar2;
      if (bVar1) {
        param_3 = param_2;
        param_2 = iVar2;
      }
      param_2 = param_2 - param_3;
      bVar1 = param_2 < param_3;
      iVar2 = param_3;
    } while (0 < param_2);
  }
  if (param_3 != 0) {
    if (param_3 == 0) {
      trap(7);
    }
    if (param_3 == 0) {
      trap(7);
    }
    *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0x144) / param_3;
    *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) / param_3;
  }
  return;
}



/* 40aeee14 FUN_40aeee14 */

void FUN_40aeee14(int *param_1)

{
  if (*(int *)(*param_1 + 0x40) < 3) {
    param_1[0xe] = 0;
    return;
  }
  param_1[0xe] = 4;
  if ((code *)param_1[0x75] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x40aeee34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)param_1[0x75])();
    return;
  }
  return;
}



/* 40aeee4c FUN_40aeee4c */

/* Boundary evidence: original MIPS .pdata 40aeee4c..40aeefaf. Semantic name remains unreviewed. */

undefined4 FUN_40aeee4c(int *param_1,int param_2)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar10 = *param_1;
  if (param_2 == 0) {
    param_1[0x37] = 1;
    return 0;
  }
  if (0 < *(short *)(iVar10 + 0x21c)) {
    iVar11 = *(int *)(iVar10 + 0x220);
    iVar12 = *(int *)(iVar10 + 0x134);
    iVar6 = 0;
    iVar7 = 0;
    do {
      while( true ) {
        iVar9 = *(int *)(iVar10 + 0xfc);
        iVar1 = *(short *)(iVar11 + iVar7) * 0x594 + iVar12;
        psVar4 = *(short **)(iVar1 + 200);
        iVar1 = (int)*(short *)(iVar1 + 0x78);
        psVar8 = (short *)(*(int *)(psVar4 + 4) + (iVar1 + 1) * 2);
        psVar3 = *(short **)(psVar4 + 6);
        psVar5 = (short *)(*(int *)(psVar4 + 4) + iVar1 * 2);
        if (iVar9 <= (int)*psVar5 + (int)*psVar3) break;
        *psVar8 = (short)param_2;
        sVar2 = *psVar5 + *psVar3;
        *psVar3 = sVar2;
        if (iVar9 < (int)*psVar8 + (int)sVar2) {
          return 0x80040002;
        }
        *psVar4 = *psVar4 + 1;
        iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
        iVar7 = iVar7 + 2;
        if (*(short *)(iVar10 + 0x21c) <= iVar6) {
          return 0;
        }
      }
      *psVar8 = (short)param_2;
      sVar2 = *(short *)(iVar10 + 0x21c);
      iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
      param_1[0x37] = 1;
      iVar7 = iVar7 + 2;
    } while (iVar6 < sVar2);
  }
  return 0;
}



/* 40aef114 FUN_40aef114 */

undefined4 FUN_40aef114(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = (int)*(short *)(param_1 + 0x21c);
  if (0 < iVar4) {
    iVar6 = 0;
    iVar7 = *(int *)(param_1 + 0x220);
    iVar8 = *(int *)(param_1 + 0x134);
    if (*(int *)(param_1 + 0xa8) == 0) {
      do {
        iVar4 = (int)*(short *)(iVar7 + iVar6 * 2);
        if (*(int *)(param_1 + 0x1a8) == 0) {
          iVar3 = *(int *)(param_1 + 0xfc);
        }
        else {
          iVar3 = *(int *)(param_1 + 0xfc) << (*(uint *)(param_1 + 0x1b0) & 0x1f);
        }
        iVar5 = iVar4 * 0x594 + iVar8;
        sVar1 = *(short *)(iVar5 + 0x7a);
        *(short *)(iVar5 + 0x7a) = (short)*(undefined4 *)(iVar5 + 0x94) + *(short *)(iVar5 + 0x7a);
        sVar2 = *(short *)(param_1 + 0x21c);
        iVar6 = iVar6 + 1;
        iVar4 = *(int *)(param_1 + 0x138) +
                (((iVar3 * 3) / 2) * iVar4 + (iVar3 >> 1) + (int)sVar1) * 4;
        *(int *)(iVar5 + 0x98) = iVar4;
        *(int *)(iVar5 + 0x3c) = iVar4;
      } while (iVar6 < sVar2);
    }
    else {
      iVar6 = 1;
      do {
        if (iVar4 <= iVar6) {
          return 0;
        }
        iVar7 = iVar6 + 1;
        iVar6 = iVar6 + 2;
      } while (iVar7 < iVar4);
    }
  }
  return 0;
}



/* 40aef200 FUN_40aef200 */

undefined4 FUN_40aef200(int *param_1)

{
  if (*(int *)(*param_1 + 0xcc) == 0) {
    param_1[0x4c] = (int)&LAB_40af7510;
    param_1[0x4b] = (int)&LAB_40af71d0;
    return 0;
  }
  param_1[0x47] = *(int *)(*param_1 + 0xcc);
  param_1[0x4b] = (int)&LAB_40af7308;
  param_1[0x4c] = (int)FUN_40af7430;
  return 0;
}



/* 40aef264 FUN_40aef264 */

undefined4 FUN_40aef264(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar3 = *param_1;
  iVar4 = *(int *)(iVar3 + 0xcc);
  if (iVar4 == 0) {
    param_1[0x4b] = (int)&LAB_40af71d0;
    param_1[0x4c] = (int)&LAB_40af7510;
  }
  else {
    param_1[0x4b] = (int)&LAB_40af7308;
    param_1[0x4c] = (int)FUN_40af7430;
    param_1[0x47] = iVar4;
  }
  iVar4 = *(int *)(iVar3 + 0x114);
  if ((iVar4 == 0) || (*(int *)(iVar3 + 0x2c) != 0)) {
    param_1[0x73] = (int)FUN_40af1848;
  }
  else {
    param_1[0x73] = (int)FUN_40af1e54;
  }
  uVar9 = (uint)*(ushort *)(iVar3 + 0x58);
  if (uVar9 != 0) {
    iVar7 = 1;
    iVar5 = 0;
    iVar10 = *(int *)(iVar3 + 0x134);
    iVar6 = 0;
    if (iVar4 == 0) {
      do {
        iVar4 = *(int *)(iVar3 + 0x1a8);
        if (iVar4 == 0) {
          iVar2 = *(int *)(iVar3 + 0xfc);
          iVar8 = iVar2;
        }
        else {
          iVar2 = *(int *)(iVar3 + 0xfc) << (*(uint *)(iVar3 + 0x1b0) & 0x1f);
          iVar8 = *(int *)(iVar3 + 0xfc);
        }
        *(int *)(iVar10 + iVar5 + 0x38) = *(int *)(iVar3 + 0x19c) + iVar2 * iVar6 * 4;
        if (iVar4 != 0) {
          iVar8 = iVar8 << (*(uint *)(iVar3 + 0x1b0) & 0x1f);
        }
        bVar1 = iVar7 < (int)uVar9;
        *(int *)(iVar10 + iVar5 + 0x9c) = *(int *)(iVar3 + 0x19c) + iVar8 * iVar6 * 4;
        iVar5 = iVar5 + 0x594;
        iVar6 = iVar7;
        iVar7 = iVar7 + 1;
      } while (bVar1);
    }
    else {
      do {
        iVar3 = iVar10 + iVar5;
        *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(iVar3 + 4);
        *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar3 + 4);
        iVar3 = iVar7 + 1;
        if ((int)uVar9 <= iVar7) {
          return 0;
        }
        iVar4 = iVar10 + iVar5 + 0x594;
        *(undefined4 *)(iVar4 + 0x9c) = *(undefined4 *)(iVar4 + 4);
        *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)(iVar4 + 4);
        iVar7 = iVar7 + 2;
        iVar5 = iVar5 + 0xb28;
      } while (iVar3 < (int)uVar9);
    }
  }
  return 0;
}



/* 40aef3cc FUN_40aef3cc */

void FUN_40aef3cc(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}



/* 40aef3d4 FUN_40aef3d4 */

uint FUN_40aef3d4(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x40) < 3) {
    uVar1 = 0;
    if (*(int *)(iVar2 + 0xcc) != 0) {
      return *(int *)(iVar2 + 0xc) + 0xbU & 0xff;
    }
  }
  else {
    uVar1 = *(int *)(iVar2 + 0xc) + 6U & 0xff;
  }
  return uVar1;
}



/* 40aef420 FUN_40aef420 */

/* WARNING: Removing unreachable block (ram,0x40aef798) */
/* Boundary evidence: original MIPS .pdata 40aef420..40aefa6b. Semantic name remains unreviewed. */

int FUN_40aef420(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  void *_Dst;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  iVar8 = param_1[0x37];
  _Dst = *(void **)(param_3 + 0x3c);
  if ((iVar8 < 1) || (iVar3 = (int)*(short *)(param_3 + 0x7c), iVar3 < 1)) {
    return -0x7ffbfffe;
  }
  local_3c = (iVar8 << 0xc) / iVar3;
  if (iVar3 == 0) {
    trap(7);
  }
  uVar10 = LZCOUNT(local_3c) ^ 0x1f;
  if (iVar8 == 0) {
    trap(7);
  }
  local_48 = param_1[0x52] + (LZCOUNT(param_1[0x3f] / iVar8) ^ 0x1fU) * 0x74;
  local_44 = *(int *)(param_1[0x51] + (LZCOUNT(param_1[0x3f] / iVar8) ^ 0x1fU) * 4);
  iVar8 = local_3c * (short)param_1[0x36] >> 0xc;
  iVar3 = *(int *)(param_3 + 0x24);
  if (iVar8 < *(int *)(local_48 + 4)) {
    iVar12 = 0;
  }
  else {
    iVar12 = 0;
    iVar4 = local_48;
    do {
      piVar11 = (int *)(iVar4 + 8);
      iVar12 = iVar12 + 1;
      iVar4 = iVar4 + 4;
    } while (*piVar11 <= iVar8);
  }
  iVar8 = (*(code *)param_1[0x72])(param_2,param_3,param_4);
  if (iVar8 < 0) {
    return iVar8;
  }
  iVar4 = ((uint)*(ushort *)(param_1 + 0x36) + param_1[5] + 1) * 0x10000;
  iVar5 = iVar4 >> 0x10;
  local_4c = (iVar3 + -1) * 0x10000 >> 0x10;
  *(short *)(param_1 + 0x36) = (short)((uint)iVar4 >> 0x10);
  if (iVar5 < local_4c) {
    if (iVar12 < local_44) {
      local_34 = 0xc - uVar10;
      local_40 = 1 << (uVar10 - 0xd & 0x1f);
      local_30 = uVar10 - 0xc;
      local_38 = (uint)(uVar10 < 0xd);
      uVar10 = 0;
      local_50 = -1;
      iVar3 = 0;
      local_2c = local_4c;
      do {
        bVar1 = true;
        piVar11 = (int *)(local_48 + (iVar12 + 1) * 4);
        iVar4 = iVar5 * local_3c >> 0xc;
        if (*piVar11 <= iVar4) {
          piVar2 = (int *)(local_48 + (iVar12 + 2) * 4);
          iVar6 = iVar12 + 1;
          do {
            iVar12 = iVar6;
            piVar11 = piVar2;
            piVar2 = piVar11 + 1;
            iVar6 = iVar12 + 1;
          } while (*piVar11 <= iVar4);
          bVar1 = iVar12 < local_44;
        }
        if (!bVar1) break;
        if (local_50 == iVar5) {
          iVar8 = (int)((ulonglong)((longlong)(param_1[6] << 0x10) * (longlong)iVar3) >> 0x20) << 1;
          if ((int)uVar10 < 0) {
            uVar9 = iVar8 << (-uVar10 & 0x1f);
          }
          else {
            uVar9 = iVar8 >> (uVar10 & 0x1f);
          }
          FUN_40af2b3c(&local_58,param_1,param_3,iVar12);
          uVar10 = local_58 - 0x14;
          if (local_38 == 0) goto LAB_40aef7ec;
LAB_40aef698:
          iVar4 = ((short)(*piVar11 << (local_34 & 0x1f)) + -1) * 0x10000 >> 0x10;
          if (local_2c < iVar4) {
            iVar4 = local_2c;
          }
          iVar3 = local_54;
          local_50 = iVar4;
          if (-1 < (int)uVar10) goto LAB_40aef874;
          uVar13 = -uVar10;
LAB_40aef718:
          while( true ) {
            pcVar7 = (code *)param_1[0x72];
            *(uint *)((int)_Dst + (short)param_1[0x36] * 4) = (uVar9 ^ param_1[7]) - param_1[7];
            iVar8 = (*pcVar7)(param_2,param_3,param_4);
            if (iVar8 < 0) {
              return iVar8;
            }
            iVar6 = ((uint)*(ushort *)(param_1 + 0x36) + param_1[5] + 1) * 0x10000;
            iVar5 = iVar6 >> 0x10;
            *(short *)(param_1 + 0x36) = (short)((uint)iVar6 >> 0x10);
            if (iVar4 <= iVar5) break;
            uVar9 = ((int)((ulonglong)((longlong)(param_1[6] << 0x10) * (longlong)iVar3) >> 0x20) <<
                    1) << (uVar13 & 0x1f);
          }
        }
        else {
          FUN_40af2b3c(&local_58,param_1,param_3,iVar12);
          uVar10 = local_58 - 0x14;
          iVar8 = (int)((ulonglong)((longlong)(param_1[6] << 0x10) * (longlong)local_54) >> 0x20) <<
                  1;
          if ((int)uVar10 < 0) {
            uVar9 = iVar8 << (-uVar10 & 0x1f);
          }
          else {
            uVar9 = iVar8 >> (uVar10 & 0x1f);
          }
          if (local_38 != 0) goto LAB_40aef698;
LAB_40aef7ec:
          iVar4 = ((short)(local_40 + *piVar11 >> (local_30 & 0x1f)) + -1) * 0x10000 >> 0x10;
          if (local_2c < iVar4) {
            iVar4 = local_2c;
          }
          iVar3 = local_54;
          local_50 = iVar4;
          if ((int)uVar10 < 0) {
            uVar13 = -uVar10;
            goto LAB_40aef718;
          }
LAB_40aef874:
          while( true ) {
            pcVar7 = (code *)param_1[0x72];
            *(uint *)((int)_Dst + (short)param_1[0x36] * 4) = (uVar9 ^ param_1[7]) - param_1[7];
            iVar8 = (*pcVar7)(param_2,param_3,param_4);
            if (iVar8 < 0) {
              return iVar8;
            }
            iVar6 = ((uint)*(ushort *)(param_1 + 0x36) + param_1[5] + 1) * 0x10000;
            iVar5 = iVar6 >> 0x10;
            *(short *)(param_1 + 0x36) = (short)((uint)iVar6 >> 0x10);
            if (iVar4 <= iVar5) break;
            uVar9 = ((int)((ulonglong)((longlong)(param_1[6] << 0x10) * (longlong)iVar3) >> 0x20) <<
                    1) >> (uVar10 & 0x1f);
          }
        }
        iVar12 = iVar12 + 1;
        if (local_4c <= iVar5) goto LAB_40aef96c;
      } while (iVar12 < local_44);
    }
  }
  else {
    local_50 = -1;
    uVar10 = 0;
    iVar3 = 0;
LAB_40aef96c:
    if (local_4c == iVar5) {
      if (local_50 <= local_4c) {
        if (iVar12 <= local_44) {
          iVar4 = local_3c * local_4c >> 0xc;
          if (*(int *)(local_48 + iVar12 * 4) <= iVar4) {
            piVar11 = (int *)(local_48 + (iVar12 + 1) * 4);
            iVar5 = iVar12 + 1;
            do {
              iVar12 = iVar5;
              if (local_44 < iVar12) break;
              iVar6 = *piVar11;
              piVar11 = piVar11 + 1;
              iVar5 = iVar12 + 1;
            } while (iVar6 <= iVar4);
          }
        }
        if (iVar12 + -1 <= local_44) {
          FUN_40af2b3c(&local_58,param_1,param_3,iVar12 + -1);
          uVar10 = local_58 - 0x14;
          iVar3 = local_54;
        }
      }
      iVar3 = (int)((ulonglong)((longlong)(param_1[6] << 0x10) * (longlong)iVar3) >> 0x20) << 1;
      if ((int)uVar10 < 0) {
        uVar10 = iVar3 << (-uVar10 & 0x1f);
      }
      else {
        uVar10 = iVar3 >> (uVar10 & 0x1f);
      }
      iVar3 = (int)(short)param_1[0x36];
      *(uint *)((int)_Dst + iVar3 * 4) = (uVar10 ^ param_1[7]) - param_1[7];
      goto LAB_40aef8d8;
    }
  }
  iVar3 = (int)(short)param_1[0x36];
LAB_40aef8d8:
  if (*(short *)(param_3 + 0x7c) < iVar3) {
    iVar8 = -0x7ffbfffe;
  }
  else {
    if (0 < param_1[0x41]) {
      memset(_Dst,0,param_1[0x41] << 2);
    }
    memset((void *)((int)_Dst + param_1[0x6f] * 4),0,
           ((int)*(short *)(param_3 + 0x7e) - param_1[0x6f]) * 4);
  }
  return iVar8;
}



/* 40aefa6c FUN_40aefa6c */

/* Boundary evidence: original MIPS .pdata 40aefa6c..40aefb33. Semantic name remains unreviewed. */

int FUN_40aefa6c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *param_1;
  iVar3 = 0;
  if (2 < *(int *)(iVar5 + 0x40)) {
    iVar2 = *(int *)(iVar5 + 0x214);
    iVar6 = 0;
    if (0 < iVar2) {
      iVar4 = 0;
      do {
        while( true ) {
          iVar6 = iVar6 + 1;
          iVar1 = *(int *)(iVar5 + 0x218) + iVar4;
          iVar4 = iVar4 + 0x98;
          if (*(int *)(iVar1 + 0xc) != 0) break;
          iVar3 = FUN_40aeb004();
          if (iVar3 < 0) {
            return iVar3;
          }
          iVar2 = *(int *)(iVar5 + 0x214);
          if (iVar2 <= iVar6) {
            return iVar3;
          }
        }
      } while (iVar6 < iVar2);
    }
  }
  return iVar3;
}



/* 40aefb34 FUN_40aefb34 */

/* Boundary evidence: original MIPS .pdata 40aefb34..40aefebb. Semantic name remains unreviewed. */

undefined4 FUN_40aefb34(undefined4 *param_1,int param_2,ushort *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  undefined3 extraout_var;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  code *local_48;
  code *local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  
  local_34 = (uint)*(ushort *)(param_1 + 0x5d);
  iVar11 = param_1[0x5a];
  local_38 = param_1[0x59];
  uVar12 = *param_1;
  uVar1 = *param_3;
  uVar4 = FUN_40aeb0fc(iVar11,local_34);
  if ((param_1[0x58] != 0) && (bVar3 = FUN_40aeb110(uVar4), CONCAT31(extraout_var,bVar3) == 0)) {
    return 0x80040000;
  }
  FUN_40aea9e8(&local_44,&local_48);
  uVar4 = (uint)*param_3;
  if (param_4 < (int)(local_38 * 2 * iVar11 * uVar4)) {
    return 0x80070057;
  }
  if (0 < local_38) {
    local_3c = (uVar1 - 1) * local_38;
    local_40 = ((uint)uVar1 * 2 + -1) * local_38;
    iVar2 = -local_38;
    local_2c = 0;
    do {
      iVar5 = FUN_40aeb194(param_2,iVar11,local_2c + local_3c);
      uVar6 = FUN_40aeb194(param_2,iVar11,local_40 + local_2c);
      local_30 = (*local_44)(iVar5,iVar11,local_34,0);
      FUN_40aeb194(param_2,iVar11,local_2c);
      uVar4 = FUN_40aeb194(param_2,iVar11,local_38 + local_2c);
      iVar9 = local_30;
      if (uVar4 < uVar6) {
        do {
          (*local_48)(iVar9,uVar6,uVar12,0);
          iVar7 = FUN_40aeb194(uVar6,iVar11,iVar2);
          iVar5 = FUN_40aeb194(iVar5,iVar11,iVar2);
          iVar8 = (*local_44)(iVar5,iVar11,local_34,0);
          iVar10 = iVar8 >> 1;
          (*local_48)(iVar10 + (iVar9 >> 1),iVar7,uVar12,0);
          uVar6 = FUN_40aeb194(iVar7,iVar11,iVar2);
          iVar9 = iVar8;
        } while (uVar4 < uVar6);
      }
      else {
        iVar10 = local_30 >> 1;
        iVar8 = local_30;
      }
      (*local_48)(iVar8,uVar6,uVar12,0);
      iVar9 = FUN_40aeb194(uVar6,iVar11,iVar2);
      iVar5 = local_2c * 4;
      (*local_48)(iVar10 + (*(int *)(param_1[0x55] + iVar5) >> 1),iVar9,uVar12,0);
      local_2c = local_2c + 1;
      *(int *)(param_1[0x55] + iVar5) = local_30;
    } while (local_2c < local_38);
    uVar4 = (uint)*param_3;
  }
  *param_3 = (ushort)(uVar4 << 1);
  return 0;
}



/* 40aefebc FUN_40aefebc */

/* Boundary evidence: original MIPS .pdata 40aefebc..40af051b. Semantic name remains unreviewed. */

undefined4 FUN_40aefebc(int param_1,int *param_2,ushort *param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  code *local_60;
  code *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  
  iVar15 = *(int *)(param_1 + 0x168);
  uVar14 = (uint)*(ushort *)(param_1 + 0x174);
  local_50 = *(int *)(param_1 + 0x144);
  iVar13 = *(int *)(param_1 + 0x164);
  iVar12 = *(int *)(param_1 + 0x148);
  uVar2 = FUN_40aeb0fc(iVar15,uVar14);
  if ((*(int *)(param_1 + 0x160) != 0) &&
     (bVar1 = FUN_40aeb110(uVar2), CONCAT31(extraout_var,bVar1) == 0)) {
    return 0x80040000;
  }
  FUN_40aea9e8(&local_5c,&local_60);
  uVar2 = (uint)*param_3;
  local_48 = *(int *)(param_1 + 0x150);
  iVar3 = uVar2 * iVar12;
  if (iVar3 < local_48) {
    *(int *)(param_1 + 0x150) = local_48 - iVar3;
    if ((uVar2 != 0) && (iVar12 = 0, 0 < iVar13)) {
      while( true ) {
        iVar10 = *(int *)(param_1 + 0x154);
        iVar8 = (uVar2 - 1) * iVar13 + iVar12;
        iVar3 = iVar12 * 4;
        iVar12 = iVar12 + 1;
        uVar4 = (*local_5c)(param_2,iVar15,uVar14,iVar8);
        *(undefined4 *)(iVar10 + iVar3) = uVar4;
        if (iVar13 <= iVar12) break;
        uVar2 = (uint)*param_3;
      }
    }
    *param_3 = 0;
    return 0;
  }
  iVar3 = (iVar3 - local_48) / local_50;
  if (local_50 == 0) {
    trap(7);
  }
  local_38 = iVar3 + 1;
  local_3c = iVar15 * iVar13 * local_38;
  if (param_4 < (int)local_3c) {
    return 0x80070057;
  }
  local_48 = local_48 + iVar3 * local_50;
  iVar8 = local_48 / iVar12;
  if (iVar12 == 0) {
    trap(7);
  }
  if (0 < iVar13) {
    iVar10 = 0;
    while( true ) {
      iVar11 = *(int *)(param_1 + 0x158);
      iVar9 = (uVar2 - 1) * iVar13 + iVar10;
      iVar5 = iVar10 * 4;
      iVar10 = iVar10 + 1;
      uVar4 = (*local_5c)(param_2,iVar15,uVar14,iVar9);
      *(undefined4 *)(iVar11 + iVar5) = uVar4;
      if (iVar13 <= iVar10) break;
      uVar2 = (uint)*param_3;
    }
  }
  uVar2 = FUN_40aeb194((int)param_2,iVar15,iVar8 * iVar13);
  iVar10 = iVar3;
  if (iVar3 <= iVar8) {
    iVar10 = iVar8;
  }
  local_40 = FUN_40aeb194((int)param_2,iVar15,iVar10 * iVar13);
  if (iVar3 < iVar8) {
    local_4c = iVar8 - iVar3;
  }
  else {
    local_4c = 0;
  }
  local_44 = FUN_40aeb194((int)param_2,iVar15,iVar13);
  local_34 = (uint)(uVar2 < local_44);
  iVar3 = local_48 - iVar8 * iVar12;
  if (local_34 == 0) {
    local_30 = 1 - iVar12;
    local_54 = -iVar13;
    do {
      if (0 < iVar13) {
        local_58 = iVar12 - iVar3;
        if (iVar3 == 0) {
          iVar8 = 0;
          iVar10 = local_54;
          do {
            iVar5 = (*local_5c)(uVar2,iVar15,uVar14,iVar10);
            if (iVar12 == 0) {
              trap(7);
            }
            iVar9 = iVar8 + 1;
            iVar10 = iVar10 + 1;
            (*local_60)((iVar5 * local_58) / iVar12,local_40,0,iVar8);
            iVar8 = iVar9;
          } while (iVar9 < iVar13);
        }
        else {
          iVar8 = 0;
          iVar10 = local_54;
          do {
            iVar5 = (*local_5c)(uVar2,iVar15,uVar14,iVar8);
            iVar9 = (*local_5c)(uVar2,iVar15,uVar14,iVar10);
            iVar11 = iVar8 + 1;
            if (iVar12 == 0) {
              trap(7);
            }
            iVar10 = iVar10 + 1;
            (*local_60)((iVar9 * local_58 + iVar5 * iVar3) / iVar12,local_40,0,iVar8);
            iVar8 = iVar11;
          } while (iVar11 < iVar13);
        }
      }
      iVar3 = iVar3 - local_50;
      if (iVar3 < 1) {
        iVar8 = (local_30 + iVar3) / iVar12;
        if (iVar12 == 0) {
          trap(7);
        }
        iVar3 = iVar3 - iVar8 * iVar12;
        uVar2 = FUN_40aeb194(uVar2,iVar15,iVar8 * iVar13);
        local_34 = (uint)(uVar2 < local_44);
      }
      local_40 = FUN_40aeb194(local_40,iVar15,local_54);
    } while (local_34 == 0);
  }
  if ((*(int *)(param_1 + 0x150) < 1) || (iVar12 <= *(int *)(param_1 + 0x150))) {
    if (iVar13 < 1) goto LAB_40af02e8;
  }
  else {
    if (iVar13 < 1) goto LAB_40af02e8;
    iVar8 = 0;
    do {
      iVar10 = (*local_5c)(param_2,iVar15,uVar14,iVar8);
      if (iVar12 == 0) {
        trap(7);
      }
      iVar5 = iVar8 + 1;
      (*local_60)((iVar10 * iVar3 +
                  (iVar12 - iVar3) * *(int *)(*(int *)(param_1 + 0x154) + iVar8 * 4)) / iVar12,
                  local_40,0,iVar8);
      iVar8 = iVar5;
    } while (iVar5 < iVar13);
  }
  iVar3 = 0;
  iVar10 = *(int *)(param_1 + 0x154);
  iVar8 = *(int *)(param_1 + 0x158);
  do {
    iVar5 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(iVar10 + iVar5) = *(undefined4 *)(iVar8 + iVar5);
  } while (iVar3 < iVar13);
LAB_40af02e8:
  *(uint *)(param_1 + 0x150) = (local_50 - (uint)*param_3 * iVar12) + local_48;
  if (local_4c == 0) {
    uVar7 = (ushort)local_38;
  }
  else {
    piVar6 = (int *)FUN_40aeb194((int)param_2,iVar15,local_4c * iVar13);
    FUN_40afcef8(param_2,piVar6,local_3c);
    uVar7 = (ushort)local_38;
  }
  *param_3 = uVar7;
  return 0;
}



/* 40af051c FUN_40af051c */

/* Boundary evidence: original MIPS .pdata 40af051c..40af085b. Semantic name remains unreviewed. */

int FUN_40af051c(int *param_1,int param_2,uint *param_3,int *param_4,uint param_5,int *param_6,
                int *param_7,int *param_8)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *_Dst;
  uint uVar10;
  ushort local_30 [6];
  
  local_30[0] = 0;
  if (param_1[0x85] == 3) {
    iVar7 = *param_1;
    if (((iVar7 == 0) || (param_3 == (uint *)0x0)) || ((param_2 != 0 && (param_4 == (int *)0x0)))) {
      iVar7 = -0x7ff8ffa9;
      goto LAB_40af0698;
    }
    uVar1 = *(ushort *)(iVar7 + 0x58);
    _Dst = (int *)param_1[0x30];
    param_1[0x85] = 0;
    local_30[0] = (ushort)param_2;
    memset(_Dst,0,(uint)uVar1 << 2);
    if (*(short *)(iVar7 + 0x58) != 0) {
      iVar3 = 0;
      iVar8 = 1;
      piVar9 = _Dst;
      do {
        iVar3 = FUN_40aeb194((int)param_4,*(int *)(iVar7 + 0x5c),iVar3);
        bVar2 = iVar8 < (int)(uint)*(ushort *)(iVar7 + 0x58);
        *piVar9 = iVar3;
        piVar9 = piVar9 + 1;
        iVar3 = iVar8;
        iVar8 = iVar8 + 1;
      } while (bVar2);
    }
    iVar3 = param_1[8];
    if (((iVar3 == 2) || (iVar3 == 4)) || (uVar6 = 0, iVar3 == 8)) {
      uVar6 = param_5;
      if (*(int *)(*param_1 + 0x1ac) != param_1[0x53]) {
        uVar10 = (param_5 * param_1[0x51]) / (uint)param_1[0x52];
        if (param_1[0x52] == 0) {
          trap(7);
        }
        if (uVar10 <= param_5) {
          uVar6 = uVar10;
        }
      }
      iVar7 = FUN_40aeb800(iVar7,local_30,_Dst,uVar6,param_1[0x89]);
      if (-1 < iVar7) {
        uVar10 = (uint)local_30[0];
        if (((param_1[0x4e] == 0) || (uVar10 == 0)) ||
           (iVar7 = FUN_40aefb34(param_1,(int)param_4,local_30,param_5), -1 < iVar7)) {
          if (((param_1[0x50] == 0) || (local_30[0] == 0)) ||
             (iVar7 = FUN_40aefebc((int)param_1,param_4,local_30,param_5), -1 < iVar7)) {
            if (param_6 != (int *)0x0) {
              *param_6 = (uint)local_30[0] * param_1[0x59] * param_1[0x5a];
            }
            if (param_7 != (int *)0x0) {
              iVar3 = FUN_40aff9dc();
              param_7[1] = iVar3 >> 0x1f;
              *param_7 = iVar3;
            }
            uVar4 = param_1[0x2c];
            uVar6 = (uint)local_30[0];
            uVar5 = uVar4 + uVar6;
            iVar3 = param_1[0x87] - uVar10;
            param_1[0x2c] = uVar5;
            param_1[0x2d] = (uint)(uVar5 < uVar4) + param_1[0x2d];
            param_1[0x87] = iVar3;
            if (iVar3 == 0) {
              param_1[0x85] = 2;
            }
            else {
              param_1[0x85] = 3;
            }
          }
          else {
            uVar6 = (uint)local_30[0];
          }
        }
        else {
          uVar6 = (uint)local_30[0];
        }
        goto LAB_40af0630;
      }
      goto LAB_40af06a0;
    }
    iVar7 = -0x7fffbffb;
  }
  else {
    iVar7 = -0x7ffbfff6;
LAB_40af0698:
    if (param_3 == (uint *)0x0) goto LAB_40af0634;
LAB_40af06a0:
    uVar6 = (uint)local_30[0];
  }
LAB_40af0630:
  *param_3 = uVar6;
LAB_40af0634:
  if (((param_1[0x89] != 0) && (param_1[0x86] != 0)) && (param_1[0x85] == 2)) {
    param_1[0x85] = 1;
  }
  if (param_8 != (int *)0x0) {
    *param_8 = param_1[0x85];
  }
  return iVar7;
}



/* 40af0864 FUN_40af0864 */

/* Boundary evidence: original MIPS .pdata 40af0864..40af1233. Semantic name remains unreviewed. */

int FUN_40af0864(int *param_1,ushort *param_2,short *param_3)

{
  bool bVar1;
  int iVar2;
  short *psVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  undefined2 *puVar10;
  short sVar11;
  int iVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  short local_48;
  short local_46;
  short local_44 [2];
  uint local_40 [2];
  int *local_38;
  short *local_30;
  
  iVar15 = 0;
  if ((param_1 == (int *)0x0) || (param_2 == (ushort *)0x0)) {
    iVar15 = -0x7ff8ffa9;
    if (param_2 == (ushort *)0x0) goto LAB_40af0c30;
    uVar6 = (uint)*param_2;
  }
  else {
    iVar14 = *param_1;
    if (iVar14 == 0) {
      uVar6 = (uint)*param_2;
      iVar15 = -0x7ff8ffa9;
    }
    else {
      *param_2 = 0;
      if (param_3 != (short *)0x0) {
        *param_3 = 0;
      }
      iVar5 = param_1[8];
      local_38 = param_1 + 0x10;
      local_30 = &local_48;
switchD_40af0910_caseD_1:
      switch(iVar5) {
      case 0:
        param_1[8] = 2;
        param_1[0xd] = 2;
        if (0 < param_1[0x2f]) {
          param_1[0x2f] = param_1[0x2f] + -1;
        }
        FUN_40ae129c();
        iVar5 = param_1[8];
      default:
        goto switchD_40af0910_caseD_1;
      case 2:
        iVar12 = *param_1;
        *(undefined2 *)(param_1 + 0x38) = 0;
        *(int *)(iVar12 + 0x1a0) = *(int *)(iVar12 + 0x1a0) + 1;
        param_1[0x37] = 0;
        *(undefined4 *)(iVar14 + 0x16c) = 0;
        param_1[0x10] = 0;
        if (*(int *)(iVar12 + 0xa8) == 1) {
          *(undefined2 *)(iVar14 + 0xca) = 0;
        }
        else {
          iVar12 = *(int *)(iVar14 + 0x174);
          if (iVar12 < *(int *)(iVar14 + 0x178)) {
            *param_2 = (short)*(int *)(iVar14 + 0x178) - (short)iVar12;
            goto switchD_40af0910_caseD_1;
          }
          if (*(int *)(iVar14 + 0x1b8) / 2 <= iVar12) {
            *(undefined4 *)(iVar14 + 0x178) = 0;
            *(undefined4 *)(iVar14 + 0x174) = 0;
          }
        }
        iVar5 = 0;
        if (*(short *)(iVar14 + 0x58) != 0) {
          iVar8 = *(int *)(iVar14 + 0x134);
          iVar12 = 0;
          do {
            while (iVar2 = *(int *)(iVar14 + 0xa8), *(undefined2 *)(iVar8 + iVar12 + 0x78) = 0,
                  iVar2 != 1) {
              iVar5 = iVar5 + 1;
              iVar12 = iVar12 + 0x594;
              if ((int)(uint)*(ushort *)(iVar14 + 0x58) <= iVar5) goto LAB_40af0dfc;
            }
            *(undefined4 *)(*(int *)(iVar14 + 0x154) + iVar5 * 4) = 0;
            iVar5 = iVar5 + 1;
            iVar12 = iVar12 + 0x594;
          } while (iVar5 < (int)(uint)*(ushort *)(iVar14 + 0x58));
        }
LAB_40af0dfc:
        param_1[8] = 3;
        iVar5 = 3;
        goto switchD_40af0910_caseD_1;
      case 3:
        if ((short)param_1[4] == 0) goto LAB_40af1074;
        iVar15 = FUN_40ae28e8(param_1);
        if (iVar15 < 0) goto LAB_40af0c1c;
        iVar5 = 1;
        if (*(short *)(iVar14 + 0x58) != 0) {
          iVar8 = *(int *)(iVar14 + 0x134);
          iVar12 = 0;
          do {
            *(undefined2 *)(iVar8 + iVar12 + 0x7a) = 0;
            iVar12 = iVar12 + 0x594;
            bVar1 = iVar5 < (int)(uint)*(ushort *)(iVar14 + 0x58);
            iVar5 = iVar5 + 1;
          } while (bVar1);
        }
        param_1[8] = 4;
        iVar5 = 4;
        goto switchD_40af0910_caseD_1;
      case 4:
        if (param_1[0x37] == 0) {
          iVar5 = 0;
          if (0 < *(short *)(iVar14 + 0x21c)) {
            iVar8 = *(int *)(iVar14 + 0x220);
            iVar2 = *(int *)(iVar14 + 0x134);
            iVar12 = 0;
            do {
              *(undefined2 *)(*(short *)(iVar8 + iVar5) * 0x594 + iVar2 + 0x4c) = 0x7fff;
              iVar12 = (iVar12 + 1) * 0x10000 >> 0x10;
              iVar5 = iVar5 + 2;
            } while (iVar12 < *(short *)(iVar14 + 0x21c));
          }
          param_1[8] = 5;
          param_1[9] = 0;
          param_1[10] = 0;
          *(undefined2 *)(param_1 + 0x25) = 0;
          *(undefined2 *)((int)param_1 + 0x96) = 0;
        }
        else {
          param_1[8] = 9;
        }
        break;
      case 6:
        goto switchD_40af0910_caseD_6;
      case 7:
        if (2 < *(int *)(iVar14 + 0x40)) goto LAB_40af0d84;
        goto LAB_40af09f0;
      case 8:
        goto switchD_40af0910_caseD_8;
      case 9:
        goto switchD_40af0910_caseD_9;
      }
      if (*(int *)(*param_1 + 0xa8) != 1) {
        iVar15 = (*(code *)param_1[0x73])(param_1,local_38);
        if (((iVar15 != -0x7ffbfffc) || (param_1[0x88] == 0)) || (iVar5 = 8, param_1[0x89] == 0)) {
          if (-1 < iVar15) goto LAB_40af0960;
          goto LAB_40af0c1c;
        }
        param_1[8] = 8;
        param_1[0x37] = 1;
        iVar15 = 4;
        *(undefined2 *)(param_1 + 4) = 0;
        goto switchD_40af0910_caseD_1;
      }
LAB_40af0960:
      if (param_1[9] == 8) {
        if (param_1[0x37] != 0) {
          if (*(int *)(*param_1 + 0xa8) == 1) {
            param_1[8] = 7;
            iVar5 = 7;
            goto switchD_40af0910_caseD_1;
          }
          if ((char)param_1[0x8a] == '\0') {
            param_1[8] = 6;
            goto switchD_40af0910_caseD_6;
          }
        }
        param_1[8] = 8;
        iVar5 = 8;
        goto switchD_40af0910_caseD_1;
      }
switchD_40af0910_caseD_6:
      bVar1 = *(int *)(iVar14 + 0x40) < 3;
      if (!bVar1) {
        local_40[0] = 0;
        do {
          iVar15 = FUN_40af774c((int)(param_1 + 0x39),1,local_40);
          if (iVar15 < 0) goto LAB_40af0c1c;
          param_1[0x10] = param_1[0x10] + 1;
        } while (local_40[0] != 1);
        bVar1 = *(int *)(iVar14 + 0x40) < 3;
      }
      param_1[8] = 7;
      if (bVar1) {
LAB_40af09f0:
        *(short *)(param_1 + 4) = (short)param_1[4] + -1;
      }
      else {
LAB_40af0d84:
        iVar15 = FUN_40ae12b4();
      }
      if (iVar15 < 0) goto LAB_40af0c1c;
      if (param_1[0x89] != 0) {
        *(undefined2 *)(param_1 + 4) = 0;
      }
      param_1[8] = 8;
switchD_40af0910_caseD_8:
      if (param_3 == (short *)0x0) {
        param_3 = local_30;
      }
      if (*(int *)(*param_1 + 0xa8) == 1) {
        FUN_40aeb498(iVar14,(short *)param_2,0,0,param_1[0x89]);
        *param_3 = 0;
      }
      else {
        FUN_40af5db4(iVar14);
      }
      *(short *)(param_1 + 0x38) = (short)param_1[0x38] + 1;
      if (0 < *(short *)(iVar14 + 0x21c)) {
        psVar3 = *(short **)(iVar14 + 0x220);
        iVar8 = *(int *)(iVar14 + 0x134);
        iVar5 = *psVar3 * 0x594 + iVar8;
        sVar13 = *(short *)(iVar5 + 0x78);
        iVar12 = 0;
        if (**(short **)(iVar5 + 200) <= sVar13) goto LAB_40af0ca0;
        iVar2 = 2;
        while( true ) {
          *(short *)(iVar5 + 0x78) = sVar13 + 1;
          iVar12 = (iVar12 + 1) * 0x10000 >> 0x10;
          if (*(short *)(iVar14 + 0x21c) <= iVar12) break;
          iVar5 = *(short *)((int)psVar3 + iVar2) * 0x594 + iVar8;
          sVar13 = *(short *)(iVar5 + 0x78);
          iVar2 = iVar2 + 2;
          if (**(short **)(iVar5 + 200) <= sVar13) goto LAB_40af0ca0;
        }
      }
switchD_40af0910_caseD_9:
      if ((*(int *)(*param_1 + 0xa8) == 0) && (*(int *)(iVar14 + 0x48) == 3)) {
        if ((char)param_1[0x8a] != '\0') {
          *(undefined4 *)(*param_1 + 0x164) = 1;
        }
        FUN_40af691c(iVar14,param_1[0x89]);
        iVar5 = param_1[0x37];
      }
      else {
        iVar5 = param_1[0x37];
      }
      if (iVar5 == 0) {
        param_1[8] = 4;
        goto LAB_40af0c1c;
      }
      if (*(int *)(*param_1 + 0xa8) != 0) goto LAB_40af0fec;
      iVar5 = *(int *)(iVar14 + 0x174);
      if (iVar5 < *(int *)(iVar14 + 0x178)) {
        *param_2 = (short)*(int *)(iVar14 + 0x178) - (short)iVar5;
        iVar5 = param_1[8];
        goto switchD_40af0910_caseD_1;
      }
      if ((iVar5 < 0) || (*(int *)(iVar14 + 0x1b8) / 2 <= iVar5)) {
        iVar15 = -0x7fffbffb;
        uVar6 = (uint)*param_2;
      }
      else {
        if (param_1[0x89] == 0) {
          FUN_40aeb1b0(iVar14,(int *)local_40);
        }
        else {
          local_40[0] = *(int *)(iVar14 + 0x1b8) - iVar5;
        }
        iVar12 = *(int *)(iVar14 + 0x174);
        piVar7 = *(int **)(iVar14 + 0x158);
        *(uint *)(iVar14 + 0x178) = local_40[0] + iVar12;
        iVar5 = *piVar7;
        if ((iVar5 < 1) || (param_1[0x89] != 0)) {
          iVar5 = *(int *)(iVar14 + 0x40);
LAB_40af10fc:
          if (iVar5 < 3) {
            iVar8 = *(int *)(iVar14 + 0x178);
            goto LAB_40af0f38;
          }
          iVar8 = *(int *)(iVar14 + 0x178);
LAB_40af1114:
          bVar1 = iVar8 < iVar12;
          if (param_1[0x89] == 0) {
            if (*(int *)(iVar14 + 0x1a4) == 0) {
              if (*(int *)(iVar14 + 0x1a8) == 0) {
                iVar8 = iVar8 - *(int *)(iVar14 + 0x16c);
                *(int *)(iVar14 + 0x178) = iVar8;
              }
              else {
                iVar8 = iVar8 - (*(int *)(iVar14 + 0x16c) << (*(uint *)(iVar14 + 0x1b0) & 0x1f));
                *(int *)(iVar14 + 0x178) = iVar8;
              }
            }
            else {
              iVar8 = iVar8 - (*(uint *)(iVar14 + 0x16c) >> (*(uint *)(iVar14 + 0x1b0) & 0x1f));
              *(int *)(iVar14 + 0x178) = iVar8;
            }
            goto LAB_40af0f38;
          }
        }
        else {
          if (iVar5 < (int)local_40[0]) {
            *(int *)(iVar14 + 0x174) = iVar12 + iVar5;
            *piVar7 = 0;
          }
          else {
            *piVar7 = iVar5 - local_40[0];
            *(undefined4 *)(iVar14 + 0x174) = *(undefined4 *)(iVar14 + 0x178);
          }
          FUN_40aeb39c(iVar14);
          iVar5 = *(int *)(iVar14 + 0x40);
          if (2 < iVar5) {
            uVar6 = *(uint *)(iVar14 + 0x16c);
            if (uVar6 == 0) {
              iVar8 = *(int *)(iVar14 + 0x178);
              iVar12 = *(int *)(iVar14 + 0x174);
            }
            else {
              if (*(int *)(iVar14 + 0x1a4) == 0) {
                if (*(int *)(iVar14 + 0x1a8) != 0) {
                  uVar6 = uVar6 << (*(uint *)(iVar14 + 0x1b0) & 0x1f);
                }
              }
              else {
                uVar6 = uVar6 >> (*(uint *)(iVar14 + 0x1b0) & 0x1f);
              }
              iVar8 = *(int *)(iVar14 + 0x178);
              iVar12 = *(int *)(iVar14 + 0x174);
              if ((int)(iVar8 - uVar6) < iVar12) {
                *(undefined4 *)(iVar14 + 0x174) = 0;
                *(undefined4 *)(iVar14 + 0x178) = 0;
                *(undefined4 *)(iVar14 + 0x16c) = 0;
                iVar12 = 0;
                goto LAB_40af10fc;
              }
            }
            goto LAB_40af1114;
          }
          iVar8 = *(int *)(iVar14 + 0x178);
          iVar12 = *(int *)(iVar14 + 0x174);
LAB_40af0f38:
          bVar1 = iVar8 < iVar12;
        }
        if (bVar1) {
LAB_40af0ca0:
          uVar6 = (uint)*param_2;
          iVar15 = -0x7ffbfffe;
        }
        else {
          iVar2 = *(int *)(iVar14 + 0x4c);
          *param_2 = (short)iVar8 - (short)iVar12;
          if (iVar2 != 0) {
            if (param_3 == (short *)0x0) {
              param_3 = &local_48;
            }
            *param_3 = 0;
            if (iVar5 < 3) {
              psVar3 = *(short **)(*(int *)(*(int *)(iVar14 + 0x134) + 200) + 8);
              sVar13 = *psVar3;
              sVar11 = psVar3[-1];
              if (*(int *)(iVar14 + 0x1a4) == 0) {
                if (*(int *)(iVar14 + 0x1a8) != 0) {
                  sVar13 = (short)((int)sVar13 << (*(uint *)(iVar14 + 0x1b0) & 0x1f));
                  sVar11 = (short)((int)sVar11 << (*(uint *)(iVar14 + 0x1b0) & 0x1f));
                }
              }
              else {
                sVar11 = (short)((int)sVar11 >> (*(uint *)(iVar14 + 0x1b0) & 0x1f));
                sVar13 = (short)((int)sVar13 >> (*(uint *)(iVar14 + 0x1b0) & 0x1f));
              }
              FUN_40af3244(iVar14,1,sVar11,sVar13,&local_46,local_44);
              *param_3 = (local_44[0] - local_46) + *param_3;
            }
            uVar6 = param_1[0x2c];
            sVar13 = *param_3;
            uVar9 = uVar6 + (int)sVar13;
            param_1[0x2c] = uVar9;
            param_1[0x2d] = (uint)(uVar9 < uVar6) + param_1[0x2d] + ((int)sVar13 >> 0x1f);
            *(undefined4 *)(iVar14 + 0x4c) = 0;
          }
LAB_40af0fec:
          if ((*(int *)(iVar14 + 0xcc) == 0) || (*(short *)(iVar14 + 0x58) == 0)) {
LAB_40af105c:
            sVar13 = (short)param_1[4];
          }
          else {
            iVar12 = 0;
            iVar5 = 1;
            iVar8 = *(int *)(iVar14 + 0x134);
            if (2 < *(int *)(iVar14 + 0x40)) {
              do {
                psVar3 = *(short **)(iVar8 + iVar12 + 200);
                iVar2 = *(int *)(psVar3 + 4);
                iVar12 = iVar12 + 0x594;
                *(undefined2 *)(iVar2 + -2) = *(undefined2 *)(iVar2 + (*psVar3 + -1) * 2);
                bVar1 = iVar5 < (int)(uint)*(ushort *)(iVar14 + 0x58);
                iVar5 = iVar5 + 1;
              } while (bVar1);
              goto LAB_40af105c;
            }
            do {
              psVar3 = *(short **)(iVar8 + iVar12 + 200);
              iVar12 = iVar12 + 0x594;
              sVar13 = *psVar3;
              puVar4 = *(undefined2 **)(psVar3 + 4);
              puVar4[-1] = puVar4[sVar13 + -1];
              puVar10 = *(undefined2 **)(psVar3 + 6);
              *puVar4 = puVar4[sVar13];
              *puVar10 = 0;
              *psVar3 = 1;
              bVar1 = iVar5 < (int)(uint)*(ushort *)(iVar14 + 0x58);
              iVar5 = iVar5 + 1;
            } while (bVar1);
            sVar13 = (short)param_1[4];
          }
          param_1[8] = 2;
          param_1[0xd] = 1;
          if (sVar13 < 1) {
LAB_40af1074:
            iVar15 = 4;
            uVar6 = (uint)*param_2;
          }
          else {
LAB_40af0c1c:
            uVar6 = (uint)*param_2;
          }
        }
      }
    }
  }
  if (uVar6 != 0) {
    param_1[0x85] = 3;
    param_1[0x87] = uVar6;
    return iVar15;
  }
LAB_40af0c30:
  param_1[0x85] = 2;
  return iVar15;
}



/* 40af1234 FUN_40af1234 */

/* WARNING: Removing unreachable block (ram,0x40af159c) */
/* WARNING: Removing unreachable block (ram,0x40af1594) */
/* Boundary evidence: original MIPS .pdata 40af1234..40af1847. Semantic name remains unreviewed. */

int FUN_40af1234(int *param_1)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (param_1 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  iVar10 = *param_1;
  iVar11 = 0x1c;
  if (iVar10 == 0) {
    return -0x7ff8ffa9;
  }
  bVar2 = 2 < *(int *)(iVar10 + 0x40);
  iVar12 = 8;
  if (bVar2) {
    iVar11 = 0;
  }
  if (bVar2) {
    iVar12 = 4;
  }
  if (param_1[8] != 1) {
    param_1[8] = 0;
    *(undefined2 *)(param_1 + 4) = 1;
    if (param_1[0x89] != 0) {
      return 0;
    }
    if ((*(int *)(iVar10 + 0xcc) != 0) || (bVar2)) {
      piVar9 = param_1 + 0x39;
LAB_40af12cc:
      do {
        iVar3 = FUN_40af78cc((int)piVar9);
        while (iVar3 != 0) {
          if (*(int *)(iVar10 + 0x40) < 3) {
            iVar3 = FUN_40af78cc((int)piVar9);
            iVar8 = *(int *)(iVar10 + 0xc);
            *(short *)(param_1 + 4) = (short)((uint)(iVar3 << 4) >> iVar11);
            iVar11 = FUN_40af78cc((int)piVar9);
            uVar7 = (uint)(iVar11 << iVar12) >> (0x1dU - iVar8 & 0x1f);
            param_1[0x11] = uVar7;
            param_1[0x12] = uVar7;
            if ((*(int *)(iVar10 + 0x2cc) == 1) && ((short)param_1[4] == 0)) {
              *(undefined4 *)(iVar10 + 0x2d4) = 1;
            }
LAB_40af14a0:
            if (uVar7 == 0) {
              FUN_40af7918((int)piVar9);
            }
            FUN_40af78d4((int)piVar9,0);
            goto LAB_40af14b4;
          }
          iVar3 = FUN_40af78cc((int)piVar9);
          uVar7 = (uint)(iVar3 << 6) >> (0x20U - *(int *)(iVar10 + 0xc) & 0x1f);
          *(ushort *)((int)param_1 + 0x12) = ((ushort)((uint)iVar3 >> 0x10) & 0xfff) >> 0xb;
          param_1[0x11] = uVar7;
          param_1[0x12] = uVar7;
          sVar1 = *(short *)((int)param_1 + 0x12);
          iVar3 = *(int *)(iVar10 + 0xc) + 6;
          if (sVar1 == 1) {
            iVar8 = *(int *)(iVar10 + 0x10);
            *(undefined2 *)(param_1 + 4) = 1;
            if (iVar8 <= (int)(uVar7 + iVar3)) {
              return -0x7ffbfffe;
            }
          }
          else {
            iVar8 = *(int *)(iVar10 + 0x10);
            if ((int)(uVar7 + iVar3) < iVar8) {
              iVar4 = *(int *)(iVar10 + 0x2cc);
              *(undefined2 *)(param_1 + 4) = 1;
            }
            else {
              iVar4 = *(int *)(iVar10 + 0x2cc);
              *(undefined2 *)(param_1 + 4) = 0;
            }
            if (iVar4 == 1) {
              *(undefined4 *)(iVar10 + 0x2d4) = 1;
            }
          }
          iVar4 = param_1[3];
          if (iVar4 == 0) {
            if ((short)param_1[4] != 0) goto LAB_40af1360;
          }
          else {
            if ((iVar4 == 1) && (sVar1 == 0)) {
              FUN_40af78ec((int)piVar9,0xfffffffe);
              FUN_40af78d4((int)piVar9,0);
              FUN_40af71b4((int)piVar9);
              FUN_40af7888((int)piVar9);
              goto LAB_40af12cc;
            }
LAB_40af1360:
            if ((int)(uVar7 + iVar3) < iVar8) goto LAB_40af14a0;
            if (iVar4 == 1) {
              FUN_40af78ec((int)piVar9,0xfffffffe);
            }
          }
          FUN_40af78d4((int)piVar9,0);
          iVar3 = FUN_40af78cc((int)piVar9);
        }
        iVar3 = FUN_40af78dc((int)piVar9);
        if (iVar3 == 0) {
          FUN_40af71b4((int)piVar9);
          return -0x7ffbfffc;
        }
        uVar5 = FUN_40af78dc((int)piVar9);
        FUN_40af78d4((int)piVar9,uVar5);
        FUN_40af78e4((int)piVar9,0);
      } while( true );
    }
    param_1[3] = 0;
    if (*(int *)(iVar10 + 8) < 0) {
      *(undefined4 *)(iVar10 + 8) = 0;
      param_1[3] = 1;
    }
    piVar9 = param_1 + 0x39;
    iVar11 = FUN_40af78cc((int)piVar9);
    if (iVar11 != *(int *)(iVar10 + 8)) {
      FUN_40af7918((int)piVar9);
    }
    iVar11 = FUN_40af78cc((int)piVar9);
    if (iVar11 == *(int *)(iVar10 + 8)) {
      FUN_40af71b4((int)piVar9);
      return -0x7ffbfffc;
    }
    uVar5 = FUN_40af78cc((int)piVar9);
    *(undefined4 *)(iVar10 + 8) = uVar5;
LAB_40af14b4:
    if (param_1[0x26] == 1) {
      if ((short)param_1[0x27] == 1) {
        iVar11 = FUN_40aff9dc();
        param_1[0x2c] = iVar11;
        param_1[0x2d] = iVar11 >> 0x1f;
        param_1[0x26] = 0;
        param_1[0x2e] = 1;
      }
      else {
        if ((short)param_1[0x27] != 2) {
          return -0x7ffbfffe;
        }
        iVar11 = FUN_40aff9dc();
        param_1[0x2c] = iVar11;
        param_1[0x2d] = iVar11 >> 0x1f;
        param_1[0x28] = param_1[0x2a];
        param_1[0x29] = param_1[0x2b];
        *(short *)(param_1 + 0x27) = (short)param_1[0x27] + -1;
        param_1[0x2e] = 1;
      }
    }
    if (param_1[3] == 0) {
      return 0;
    }
  }
  piVar9 = param_1 + 0x39;
  param_1[8] = 1;
  if (param_1[0x11] < 0x19) {
    pcVar6 = (code *)param_1[0x4c];
  }
  else {
    do {
      iVar11 = (*(code *)param_1[0x4c])(piVar9,0x18);
      if (iVar11 < 0) {
        return iVar11;
      }
      iVar11 = FUN_40af75e4((int)piVar9,0x18);
      if (iVar11 < 0) {
        return iVar11;
      }
      iVar11 = param_1[0x11];
      param_1[0x11] = iVar11 + -0x18;
    } while (0x18 < iVar11 + -0x18);
    pcVar6 = (code *)param_1[0x4c];
  }
  iVar11 = (*pcVar6)(piVar9);
  if ((-1 < iVar11) && (iVar11 = FUN_40af75e4((int)piVar9,param_1[0x11]), -1 < iVar11)) {
    if (*(short *)(iVar10 + 0x58) != 0) {
      iVar3 = *(int *)(iVar10 + 0x134);
      iVar12 = 0;
      iVar11 = 1;
      do {
        *(undefined2 *)(iVar3 + iVar12 + 0x4c) = 0x7fff;
        iVar12 = iVar12 + 0x594;
        bVar2 = iVar11 < (int)(uint)*(ushort *)(iVar10 + 0x58);
        iVar11 = iVar11 + 1;
      } while (bVar2);
    }
    iVar11 = 0;
    *(undefined4 *)(iVar10 + 0x48) = 3;
    param_1[8] = 0;
  }
  return iVar11;
}



/* 40af1848 FUN_40af1848 */

/* Boundary evidence: original MIPS .pdata 40af1848..40af1e53. Semantic name remains unreviewed. */

int FUN_40af1848(int *param_1,int *param_2)

{
  short *psVar1;
  short sVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_30;
  int local_2c;
  
  iVar14 = 0;
  piVar12 = (int *)*param_1;
LAB_40af1894:
  iVar8 = param_1[9];
  do {
    if (iVar8 == 8) {
      return iVar14;
    }
code_r0x40af18bc:
    switch(iVar8) {
    case 0:
      iVar14 = FUN_40ae1370(param_1,param_2);
      if (iVar14 < 0) {
        return iVar14;
      }
      if (piVar12[0x1f] != 0) goto LAB_40af1894;
      iVar8 = *(int *)(*param_1 + 0x40);
      *(undefined2 *)(*param_1 + 0xd8) = 0;
      param_1[9] = 1;
      *(undefined2 *)(param_1 + 0x25) = 0;
      if (iVar8 < 3) {
        param_1[0xe] = 0;
        goto LAB_40af1894;
      }
      param_1[0xe] = 4;
      if ((code *)param_1[0x75] == (code *)0x0) goto LAB_40af1894;
      (*(code *)param_1[0x75])(param_1);
      iVar8 = param_1[9];
      break;
    case 1:
      goto switchD_40af18c0_caseD_1;
    case 2:
      param_1[9] = 4;
      goto LAB_40af1894;
    default:
      goto code_r0x40af18bc;
    case 5:
      if (piVar12[0x12] == 3) {
        uVar11 = (uint)*(ushort *)(piVar12 + 0x16);
        iVar14 = 0;
        if (uVar11 != 0) {
          iVar8 = 1;
          do {
            puVar7 = (undefined4 *)(*(short *)(piVar12[0x88] + iVar14) * 0x594 + piVar12[0x4d]);
            if (puVar7[10] != 0) {
              FUN_40aeadb8((int *)*puVar7,puVar7[9],(int)puVar7,piVar12[0x12]);
              uVar11 = (uint)*(ushort *)(piVar12 + 0x16);
            }
            bVar5 = iVar8 < (int)uVar11;
            iVar14 = iVar14 + 2;
            iVar8 = iVar8 + 1;
          } while (bVar5);
        }
      }
      FUN_40af5ca4(&local_30,piVar12[0x48]);
      *piVar12 = local_30;
      piVar12[1] = local_2c;
      if ((short)piVar12[0x16] != 0) {
        iVar14 = 0;
        iVar8 = 1;
        do {
          iVar10 = *(short *)(piVar12[0x88] + iVar14) * 0x594 + piVar12[0x4d];
          if (*(int *)(iVar10 + 0x28) == 0) {
            if (piVar12[0x6a] == 0) {
              iVar6 = (int)*(short *)(iVar10 + 0x7c);
            }
            else {
              iVar6 = (int)*(short *)(iVar10 + 0x7c) << (piVar12[0x6c] & 0x1fU);
            }
            memset(*(void **)(iVar10 + 0x3c),0,iVar6 << 2);
            uVar3 = *(ushort *)(piVar12 + 0x16);
          }
          else {
            iVar10 = (*(code *)piVar12[0x70])(piVar12,iVar10,*(undefined4 *)(iVar10 + 0x38));
            if (iVar10 < 0) {
              return iVar10;
            }
            uVar3 = *(ushort *)(piVar12 + 0x16);
          }
          bVar5 = iVar8 < (int)(uint)uVar3;
          iVar14 = iVar14 + 2;
          iVar8 = iVar8 + 1;
        } while (bVar5);
      }
      iVar8 = *param_1;
      if ((*(int *)(iVar8 + 0x40) < 3) || (iVar10 = *(int *)(iVar8 + 0x214), iVar10 < 1)) {
        iVar14 = 0;
      }
      else {
        iVar14 = 0;
        iVar13 = 0;
        iVar6 = 0;
        do {
          while (*(int *)(*(int *)(iVar8 + 0x218) + iVar6 + 0xc) != 0) {
            iVar13 = iVar13 + 1;
            iVar6 = iVar6 + 0x98;
            if (iVar10 <= iVar13) goto LAB_40af1b14;
          }
          iVar14 = FUN_40aeb004();
          if (iVar14 < 0) {
            return iVar14;
          }
          iVar10 = *(int *)(iVar8 + 0x214);
          iVar13 = iVar13 + 1;
          iVar6 = iVar6 + 0x98;
        } while (iVar13 < iVar10);
      }
LAB_40af1b14:
      if (iVar14 < 0) {
        return iVar14;
      }
      FUN_40af3608((int)piVar12,1);
      FUN_40af3608((int)piVar12,0);
      bVar5 = true;
      if (0 < (short)piVar12[0x87]) {
        psVar9 = (short *)piVar12[0x88];
        bVar5 = false;
        if (*(int *)(*psVar9 * 0x594 + piVar12[0x4d] + 0x28) == 0) {
          iVar8 = 0;
          do {
            iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
            bVar5 = true;
            if ((short)piVar12[0x87] <= iVar8) goto LAB_40af1b98;
            psVar1 = psVar9 + 1;
            psVar9 = psVar9 + 1;
          } while (*(int *)(*psVar1 * 0x594 + piVar12[0x4d] + 0x28) == 0);
          bVar5 = false;
        }
      }
LAB_40af1b98:
      if (((2 < piVar12[0x10]) && (!bVar5)) && (iVar8 = 0, (short)piVar12[0x16] != 0)) {
        iVar10 = 1;
        do {
          iVar14 = *(short *)(piVar12[0x88] + iVar8) * 0x594 + piVar12[0x4d];
          if ((int)(short)piVar12[0x1c] == (int)*(short *)(piVar12[0x88] + iVar8)) {
            memset((void *)(*(int *)(iVar14 + 0x3c) + piVar12[0x4b] * 4),0,
                   ((int)*(short *)(iVar14 + 0x7c) - piVar12[0x4b]) * 4);
          }
          *(undefined2 *)(piVar12 + 0x36) = 0xffff;
          iVar14 = FUN_40aeb00c();
          if (iVar14 < 0) {
            return iVar14;
          }
          iVar8 = iVar8 + 2;
          bVar4 = iVar10 < (int)(uint)*(ushort *)(piVar12 + 0x16);
          iVar10 = iVar10 + 1;
        } while (bVar4);
      }
      if ((piVar12[0xb] == 0) && ((short)piVar12[0x16] != 0)) {
        iVar10 = 0;
        iVar8 = 1;
        do {
          psVar9 = (short *)(piVar12[0x88] + iVar10);
          iVar10 = iVar10 + 2;
          iVar6 = *psVar9 * 0x594 + piVar12[0x4d];
          memset((void *)(*(int *)(iVar6 + 0x3c) + piVar12[0x6f] * 4),0,
                 ((int)*(short *)(iVar6 + 0x7e) - piVar12[0x6f]) * 4);
          bVar4 = iVar8 < (int)(uint)*(ushort *)(piVar12 + 0x16);
          iVar8 = iVar8 + 1;
        } while (bVar4);
      }
      if (!bVar5) {
        uVar11 = (uint)*(ushort *)(piVar12 + 0x16);
        iVar8 = 0;
        if (uVar11 != 0) {
          iVar10 = 1;
          do {
            iVar6 = *(short *)(piVar12[0x88] + iVar8) * 0x594 + piVar12[0x4d];
            sVar2 = *(short *)(iVar6 + 0x7c);
            if (param_1[0x4f] == 0) {
LAB_40af1cd8:
              iVar13 = *(int *)(iVar6 + 0x28);
            }
            else {
              iVar13 = (int)sVar2 / 2;
              iVar15 = (iVar13 * param_1[0x52]) / param_1[0x51];
              if (param_1[0x51] == 0) {
                trap(7);
              }
              iVar13 = iVar13 - iVar15;
              if (iVar13 < 1) goto LAB_40af1cd8;
              puVar7 = (undefined4 *)(*(int *)(iVar6 + 0x3c) + iVar15 * 8);
              do {
                iVar13 = iVar13 + -1;
                *puVar7 = 0;
                puVar7[1] = 0;
                puVar7 = puVar7 + 2;
              } while (iVar13 != 0);
              iVar13 = *(int *)(iVar6 + 0x28);
            }
            if ((iVar13 != 0) || (2 < piVar12[0x10])) {
              (*(code *)piVar12[0x74])
                        (*(undefined4 *)(iVar6 + 0x3c),(int)sVar2,0,(int)*(short *)(iVar6 + 0x7e),
                         piVar12[0x79],piVar12[0x68],(int)*(short *)(iVar6 + 0x78),piVar12[0x6d],
                         *(int *)(iVar6 + 0x94) << 1);
              uVar11 = (uint)*(ushort *)(piVar12 + 0x16);
            }
            bVar5 = iVar10 < (int)uVar11;
            iVar8 = iVar8 + 2;
            iVar10 = iVar10 + 1;
          } while (bVar5);
        }
      }
    case 4:
      param_1[9] = 8;
      iVar8 = param_1[9];
    }
  } while( true );
switchD_40af18c0_caseD_1:
  iVar14 = (*(code *)param_1[0x74])(param_1,piVar12[0x4d],param_2);
  if (iVar14 < 0) {
    return iVar14;
  }
  param_1[9] = 5;
  goto LAB_40af1894;
}



/* 40af1e54 FUN_40af1e54 */

/* WARNING: Removing unreachable block (ram,0x40af28c0) */
/* WARNING: Removing unreachable block (ram,0x40af28c8) */
/* WARNING: Removing unreachable block (ram,0x40af2904) */
/* WARNING: Removing unreachable block (ram,0x40af2a2c) */
/* WARNING: Removing unreachable block (ram,0x40af2a44) */
/* WARNING: Removing unreachable block (ram,0x40af2ac0) */
/* WARNING: Removing unreachable block (ram,0x40af2a50) */
/* WARNING: Removing unreachable block (ram,0x40af2a54) */
/* WARNING: Removing unreachable block (ram,0x40af2ab0) */
/* WARNING: Removing unreachable block (ram,0x40af2a6c) */
/* WARNING: Removing unreachable block (ram,0x40af2a7c) */
/* WARNING: Removing unreachable block (ram,0x40af2a84) */
/* WARNING: Removing unreachable block (ram,0x40af2aa8) */
/* WARNING: Removing unreachable block (ram,0x40af29b8) */
/* WARNING: Removing unreachable block (ram,0x40af2928) */
/* WARNING: Removing unreachable block (ram,0x40af2aec) */
/* WARNING: Removing unreachable block (ram,0x40af2b04) */
/* WARNING: Removing unreachable block (ram,0x40af2938) */
/* WARNING: Removing unreachable block (ram,0x40af2944) */
/* WARNING: Removing unreachable block (ram,0x40af2914) */
/* WARNING: Removing unreachable block (ram,0x40af2950) */
/* WARNING: Removing unreachable block (ram,0x40af29f4) */
/* WARNING: Removing unreachable block (ram,0x40af2960) */
/* WARNING: Removing unreachable block (ram,0x40af2a00) */
/* WARNING: Removing unreachable block (ram,0x40af2964) */
/* WARNING: Removing unreachable block (ram,0x40af2ab8) */
/* WARNING: Removing unreachable block (ram,0x40af297c) */
/* WARNING: Removing unreachable block (ram,0x40af298c) */
/* WARNING: Removing unreachable block (ram,0x40af2994) */
/* Boundary evidence: original MIPS .pdata 40af1e54..40af2b3b. Semantic name remains unreviewed. */

int FUN_40af1e54(int *param_1,int *param_2)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  short *psVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int *local_2c;
  
  local_2c = param_1 + 0x39;
  piVar10 = (int *)*param_1;
  iVar14 = 0;
  local_38 = -0x7ffbfffc;
  iVar13 = 0;
  local_34 = 0;
LAB_40af1ebc:
  iVar5 = param_1[9];
LAB_40af1ec0:
  if (iVar5 != 8) {
    do {
      switch(iVar5) {
      case 0:
        goto switchD_40af1eec_caseD_0;
      case 1:
        iVar5 = (int)(short)param_1[0x25];
        if ((short)piVar10[0x87] <= iVar5) goto LAB_40af22ec;
        if (local_38 != 0) goto LAB_40af223c;
        iVar13 = piVar10[0x88];
        goto LAB_40af235c;
      case 2:
        param_1[9] = 4;
        goto LAB_40af1ebc;
      case 4:
        param_1[9] = 8;
        goto LAB_40af1ebc;
      case 5:
        iVar5 = (int)(short)piVar10[0x87];
        iVar9 = 0;
        if (iVar5 < 1) {
LAB_40af1fec:
          local_30 = 1;
        }
        else {
          iVar11 = 0;
          do {
            while (iVar13 = *(short *)(piVar10[0x88] + iVar11) * 0x594 + piVar10[0x4d],
                  *(int *)(iVar13 + 0x28) != 0) {
              iVar12 = piVar10[0x12];
              *(undefined4 *)(iVar13 + 0x34) = 0;
              if (iVar12 == 3) {
                FUN_40aeae24(*(int **)(iVar13 + 0x3c),(int)*(short *)(iVar13 + 0x7c),iVar13,3);
                iVar5 = (int)(short)piVar10[0x87];
              }
              iVar9 = (iVar9 + 1) * 0x10000 >> 0x10;
              iVar11 = iVar11 + 2;
              if (iVar5 <= iVar9) goto LAB_40af1f84;
            }
            memset(*(void **)(iVar13 + 0x3c),0,(int)*(short *)(iVar13 + 0x7e) << 2);
            iVar5 = (int)(short)piVar10[0x87];
            iVar9 = (iVar9 + 1) * 0x10000 >> 0x10;
            *(undefined4 *)(iVar13 + 0x34) = 0;
            iVar11 = iVar11 + 2;
          } while (iVar9 < iVar5);
LAB_40af1f84:
          if (iVar5 < 1) goto LAB_40af1fec;
          psVar6 = (short *)piVar10[0x88];
          if (*(int *)(*psVar6 * 0x594 + piVar10[0x4d] + 0x28) == 0) {
            iVar9 = 0;
            do {
              iVar9 = (iVar9 + 1) * 0x10000 >> 0x10;
              if (iVar5 <= iVar9) goto LAB_40af1fec;
              psVar1 = psVar6 + 1;
              psVar6 = psVar6 + 1;
            } while (*(int *)(*psVar1 * 0x594 + piVar10[0x4d] + 0x28) == 0);
          }
          local_30 = 0;
        }
        if ((2 < piVar10[0x10]) && (local_30 == 0)) {
          iVar14 = FUN_40aeb01c();
        }
        if (iVar14 < 0) goto LAB_40af213c;
        iVar5 = *param_1;
        if ((*(int *)(iVar5 + 0x40) < 3) || (iVar9 = *(int *)(iVar5 + 0x214), iVar9 < 1)) {
          iVar14 = 0;
        }
        else {
          iVar14 = 0;
          iVar12 = 0;
          iVar11 = 0;
          do {
            while (*(int *)(*(int *)(iVar5 + 0x218) + iVar11 + 0xc) != 0) {
              iVar12 = iVar12 + 1;
              iVar11 = iVar11 + 0x98;
              if (iVar9 <= iVar12) goto LAB_40af20b8;
            }
            iVar14 = FUN_40aeb004();
            if (iVar14 < 0) goto LAB_40af213c;
            iVar9 = *(int *)(iVar5 + 0x214);
            iVar12 = iVar12 + 1;
            iVar11 = iVar11 + 0x98;
          } while (iVar12 < iVar9);
        }
LAB_40af20b8:
        if (iVar14 < 0) goto LAB_40af213c;
        if ((2 < piVar10[0x10]) && (local_30 == 0)) {
          if ((short)piVar10[0x87] == 0) {
            trap(7);
          }
          iVar14 = FUN_40aeb014();
          if (iVar14 < 0) goto LAB_40af213c;
        }
        FUN_40af3608((int)piVar10,1);
        FUN_40af3608((int)piVar10,0);
        iVar5 = piVar10[0x10];
        if (iVar5 < 3) {
          if (local_30 == 0) goto LAB_40af2504;
        }
        else if (local_30 == 0) {
          iVar14 = FUN_40aeb014();
          if (iVar14 < 0) goto LAB_40af213c;
          if (2 < piVar10[0x10]) {
            iVar5 = 0;
            if (0 < (short)piVar10[0x87]) {
              iVar9 = 0;
              do {
                iVar13 = *(short *)(piVar10[0x88] + iVar9) * 0x594 + piVar10[0x4d];
                if ((int)(short)piVar10[0x1c] == (int)*(short *)(piVar10[0x88] + iVar9)) {
                  memset((void *)(*(int *)(iVar13 + 0x3c) + piVar10[0x4b] * 4),0,
                         ((int)*(short *)(iVar13 + 0x7c) - piVar10[0x4b]) * 4);
                }
                *(undefined2 *)(piVar10 + 0x36) = 0xffff;
                iVar14 = FUN_40aeb00c();
                if (iVar14 < 0) goto LAB_40af213c;
                iVar5 = (iVar5 + 1) * 0x10000 >> 0x10;
                iVar9 = iVar9 + 2;
              } while (iVar5 < (short)piVar10[0x87]);
              if (piVar10[0x10] < 3) goto LAB_40af2504;
            }
            iVar14 = FUN_40aeb014();
            if (iVar14 < 0) goto LAB_40af213c;
          }
LAB_40af2504:
          sVar7 = (short)piVar10[0x87];
          sVar2 = *(short *)(iVar13 + 0x7c);
          if (0 < sVar7) {
            sVar8 = 0;
            iVar5 = 0;
            do {
              iVar13 = *(short *)(piVar10[0x88] + iVar5) * 0x594 + piVar10[0x4d];
              if (param_1[0x4f] == 0) {
LAB_40af251c:
                iVar9 = *(int *)(iVar13 + 0x28);
              }
              else {
                iVar9 = (int)*(short *)(iVar13 + 0x7c) / 2;
                iVar11 = (iVar9 * param_1[0x52]) / param_1[0x51];
                if (param_1[0x51] == 0) {
                  trap(7);
                }
                iVar9 = iVar9 - iVar11;
                if (iVar9 < 1) goto LAB_40af251c;
                puVar4 = (undefined4 *)(*(int *)(iVar13 + 0x3c) + iVar11 * 8);
                do {
                  iVar9 = iVar9 + -1;
                  *puVar4 = 0;
                  puVar4[1] = 0;
                  puVar4 = puVar4 + 2;
                } while (iVar9 != 0);
                iVar9 = *(int *)(iVar13 + 0x28);
              }
              if ((iVar9 != 0) || (2 < piVar10[0x10])) {
                (*(code *)piVar10[0x74])
                          (*(undefined4 *)(iVar13 + 0x3c),(int)sVar2,0,
                           (int)*(short *)(iVar13 + 0x7e),piVar10[0x79],piVar10[0x68],
                           (int)*(short *)(iVar13 + 0x78),piVar10[0x6d],*(int *)(iVar13 + 0x94) << 1
                          );
                sVar7 = (short)piVar10[0x87];
              }
              sVar8 = sVar8 + 1;
              iVar5 = iVar5 + 2;
            } while (sVar8 < sVar7);
          }
          iVar5 = piVar10[0x10];
        }
        if ((iVar5 < 3) || (local_30 != 0)) {
          param_1[9] = 8;
        }
        else {
          iVar14 = FUN_40aeb024();
          if (iVar14 < 0) goto LAB_40af213c;
          param_1[9] = 8;
        }
        iVar5 = param_1[9];
        if (iVar5 == 8) goto LAB_40af213c;
      }
    } while( true );
  }
  goto LAB_40af213c;
LAB_40af223c:
  do {
    iVar13 = *(short *)(piVar10[0x88] + iVar5 * 2) * 0x594 + piVar10[0x4d];
    iVar5 = *(int *)(iVar13 + 0x28);
    *(ushort *)(param_1 + 0x4d) = ((ushort)LZCOUNT(*(int *)(iVar13 + 0x24) + -1) ^ 0x1f) + 1;
    if (iVar5 == 0) {
      if (piVar10[0x10] != 1) goto LAB_40af21e4;
LAB_40af2288:
      iVar5 = *param_2;
      uVar3 = FUN_40af7894((int)local_2c);
      *param_2 = (uVar3 & 7) + iVar5;
      FUN_40af78f4((int)local_2c);
      iVar5 = *(int *)(*param_1 + 0x40);
      *(short *)(piVar10 + 0x36) = (short)piVar10[0x41] + -1;
      if (iVar5 < 3) goto LAB_40af22c4;
LAB_40af2200:
      param_1[0xe] = 4;
      if ((code *)param_1[0x75] != (code *)0x0) {
        (*(code *)param_1[0x75])(param_1);
      }
      iVar9 = ((short)param_1[0x25] + 1) * 0x10000;
      iVar5 = iVar9 >> 0x10;
      *(short *)(param_1 + 0x25) = (short)((uint)iVar9 >> 0x10);
      if ((short)piVar10[0x87] <= iVar5) break;
      goto LAB_40af223c;
    }
    if (piVar10[0x10] < 3) {
      iVar14 = FUN_40aef420(piVar10,param_1,iVar13,param_2);
      if (iVar14 < 0) goto LAB_40af213c;
      if (piVar10[0x10] == 1) goto LAB_40af2288;
    }
    else {
      iVar14 = 0;
    }
LAB_40af21e4:
    iVar5 = *(int *)(*param_1 + 0x40);
    *(short *)(piVar10 + 0x36) = (short)piVar10[0x41] + -1;
    if (2 < iVar5) goto LAB_40af2200;
LAB_40af22c4:
    param_1[0xe] = 0;
    iVar9 = ((short)param_1[0x25] + 1) * 0x10000;
    iVar5 = iVar9 >> 0x10;
    *(short *)(param_1 + 0x25) = (short)((uint)iVar9 >> 0x10);
  } while (iVar5 < (short)piVar10[0x87]);
LAB_40af22ec:
  param_1[9] = 5;
  goto LAB_40af1ebc;
LAB_40af235c:
  iVar13 = *(short *)(iVar13 + iVar5 * 2) * 0x594 + piVar10[0x4d];
  iVar5 = *(int *)(iVar13 + 0x28);
  *(ushort *)(param_1 + 0x4d) = ((ushort)LZCOUNT(*(int *)(iVar13 + 0x24) + -1) ^ 0x1f) + 1;
  if (iVar5 == 0) {
LAB_40af244c:
    if (piVar10[0x10] != 1) goto LAB_40af2300;
    iVar5 = *param_2;
    uVar3 = FUN_40af7894((int)local_2c);
    *param_2 = (uVar3 & 7) + iVar5;
    FUN_40af78f4((int)local_2c);
    iVar5 = *(int *)(*param_1 + 0x40);
    *(short *)(piVar10 + 0x36) = (short)piVar10[0x41] + -1;
    if (2 < iVar5) goto LAB_40af231c;
LAB_40af2498:
    param_1[0xe] = 0;
  }
  else {
    if (piVar10[0x10] < 3) {
      iVar14 = FUN_40aef420(piVar10,param_1,iVar13,param_2);
      if (iVar14 < 0) {
LAB_40af213c:
        if (local_34 == 0) {
          local_38 = iVar14;
        }
        return local_38;
      }
      goto LAB_40af244c;
    }
    if ((param_1[0x88] != 0) && (param_1[0x89] != 0)) {
      local_34 = 1;
    }
    iVar14 = 0;
LAB_40af2300:
    iVar5 = *(int *)(*param_1 + 0x40);
    *(short *)(piVar10 + 0x36) = (short)piVar10[0x41] + -1;
    if (iVar5 < 3) goto LAB_40af2498;
LAB_40af231c:
    param_1[0xe] = 4;
    if ((code *)param_1[0x75] != (code *)0x0) {
      (*(code *)param_1[0x75])(param_1);
    }
  }
  iVar9 = ((short)param_1[0x25] + 1) * 0x10000;
  iVar5 = iVar9 >> 0x10;
  *(short *)(param_1 + 0x25) = (short)((uint)iVar9 >> 0x10);
  if ((short)piVar10[0x87] <= iVar5) goto LAB_40af22ec;
  iVar13 = piVar10[0x88];
  goto LAB_40af235c;
switchD_40af1eec_caseD_0:
  iVar14 = FUN_40ae1370(param_1,param_2);
  if (iVar14 < 0) goto LAB_40af213c;
  if (piVar10[0xb3] == 1) {
    if ((2 < piVar10[0x10]) && (piVar10[0x1f] == 1)) {
      piVar10[0xb5] = 1;
    }
    piVar10[0xb4] = 1;
    return local_38;
  }
  if (piVar10[0x1f] == 0) {
    FUN_40af5ca4(&local_40,piVar10[0x48]);
    *piVar10 = local_40;
    piVar10[1] = local_3c;
    if (0 < (short)piVar10[0x87]) {
      iVar5 = 0;
      iVar9 = 0;
      do {
        iVar13 = *(short *)(piVar10[0x88] + iVar9) * 0x594 + piVar10[0x4d];
        memset(*(void **)(iVar13 + 0x3c),0,piVar10[0x42] << 2);
        iVar5 = (iVar5 + 1) * 0x10000 >> 0x10;
        iVar9 = iVar9 + 2;
      } while (iVar5 < (short)piVar10[0x87]);
    }
    iVar5 = *(int *)(*param_1 + 0x40);
    *(short *)(*param_1 + 0xd8) = (short)piVar10[0x41] + -1;
    param_1[9] = 1;
    *(undefined2 *)(param_1 + 0x25) = 0;
    if (iVar5 < 3) {
      param_1[0xe] = 0;
      goto LAB_40af1ebc;
    }
    param_1[0xe] = 4;
    if ((code *)param_1[0x75] == (code *)0x0) goto LAB_40af1ebc;
    (*(code *)param_1[0x75])(param_1);
    iVar5 = param_1[9];
    goto LAB_40af1ec0;
  }
  if (piVar10[0x1f] == 1) {
    if (piVar10[0x21] != 1) {
      iVar14 = FUN_40aeafa4();
      if (iVar14 < 0) goto LAB_40af213c;
      goto LAB_40af23f4;
    }
  }
  else {
LAB_40af23f4:
    if (piVar10[0x21] != 1) goto LAB_40af2400;
  }
  if ((piVar10[0x2e] == 1) && (iVar14 = FUN_40aeafa4(), iVar14 < 0)) goto LAB_40af213c;
LAB_40af2400:
  *(undefined2 *)(param_1 + 0x25) = 0;
  *(undefined1 *)((int)param_1 + 0xc6) = 0;
  *(undefined2 *)(param_1 + 0x32) = 0;
  param_1[9] = 2;
  *(undefined2 *)(*param_1 + 0xd8) = 0;
  param_1[0x13] = 6;
  param_1[0x14] = 0;
  param_1[0x33] = 0;
  param_1[0x35] = 0;
  goto LAB_40af1ebc;
}



/* 40af2b3c FUN_40af2b3c */

/* Boundary evidence: original MIPS .pdata 40af2b3c..40af2bdf. Semantic name remains unreviewed. */

int * FUN_40af2b3c(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  iVar1 = *(int *)(param_3 + 0x44) - *(int *)(*(int *)(param_3 + 4) + param_4 * 4);
  iVar2 = 0x47;
  if (iVar1 < 0x48) {
    iVar2 = iVar1;
  }
  local_10 = *param_2 + -3 + (iVar2 >> 2);
  local_c = (int)((ulonglong)((longlong)param_2[1] * (longlong)*(int *)(&DAT_40b0b828 + iVar2 * 4))
                 >> 0x20) << 1;
  FUN_40aeaa90(&local_10);
  *param_1 = local_10;
  param_1[1] = local_c;
  return param_1;
}



/* 40af2be0 FUN_40af2be0 */

/* Boundary evidence: original MIPS .pdata 40af2be0..40af3243. Semantic name remains unreviewed. */

void FUN_40af2be0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined4 *puVar14;
  uint uVar15;
  int iVar16;
  
  puVar14 = *(undefined4 **)(param_1 + 0x148);
  iVar11 = 0x19;
  piVar13 = (int *)&UNK_40b0ba40;
  if (2 < *(int *)(param_1 + 0x40)) {
    iVar11 = 0x1c;
    piVar13 = &DAT_40b12ef8;
  }
  if (0 < *(int *)(param_1 + 0xf0)) {
    puVar12 = *(undefined4 **)(param_1 + 0x144);
    uVar15 = 0;
    iVar10 = 0;
    puVar9 = puVar14;
    do {
      *puVar9 = 0;
      iVar2 = 1 << (uVar15 & 0x1f);
      iVar16 = *(int *)(param_1 + 0xf8) / iVar2;
      if (iVar2 == 0) {
        trap(7);
      }
      if (2 < *(int *)(param_1 + 0x40)) {
        uVar4 = *(uint *)(param_1 + 0x50);
        goto LAB_40af2ca0;
      }
      uVar4 = *(uint *)(param_1 + 0x50);
      if ((int)uVar4 < 0xac44) {
        if (31999 < (int)uVar4) {
          if (iVar16 == 0x400) {
            *(undefined4 *)((int)puVar12 + iVar10) = 0x10;
            puVar9[1] = 6;
            puVar9[2] = 0xd;
            puVar9[3] = 0x14;
            puVar9[4] = 0x1d;
            puVar9[5] = 0x29;
            puVar9[6] = 0x37;
            puVar9[7] = 0x4a;
            puVar9[8] = 0x65;
            puVar9[9] = 0x8d;
            puVar9[10] = 0xaa;
            puVar9[0xb] = 0xcd;
            puVar9[0xc] = 0xf6;
            puVar9[0xd] = 0x130;
            puVar9[0xe] = 0x180;
            puVar9[0xf] = 0x1f0;
            puVar9[0x10] = 0x200;
          }
          else if (iVar16 == 0x200) {
            *(undefined4 *)((int)puVar12 + iVar10) = 0xf;
            puVar9[3] = 0xf;
            puVar9[4] = 0x14;
            puVar9[5] = 0x1c;
            puVar9[6] = 0x25;
            puVar9[7] = 0x32;
            puVar9[8] = 0x46;
            puVar9[9] = 0x55;
            puVar9[10] = 0x66;
            puVar9[0xb] = 0x7b;
            puVar9[0xc] = 0x98;
            puVar9[0xd] = 0xc0;
            puVar9[0xe] = 0xf8;
            puVar9[1] = 5;
            puVar9[2] = 10;
            puVar9[0xf] = 0x100;
          }
          else {
            if (iVar16 != 0x100) goto LAB_40af2ca0;
            *(undefined4 *)((int)puVar12 + iVar10) = 0xb;
            puVar9[1] = 4;
            puVar9[2] = 9;
            puVar9[3] = 0xe;
            puVar9[4] = 0x13;
            puVar9[5] = 0x19;
            puVar9[6] = 0x23;
            puVar9[7] = 0x33;
            puVar9[8] = 0x4c;
            puVar9[9] = 0x60;
            puVar9[10] = 0x7c;
            puVar9[0xb] = 0x80;
          }
          goto LAB_40af2ff4;
        }
        if (0x5621 < (int)uVar4) {
          if (iVar16 == 0x200) {
            *(undefined4 *)((int)puVar12 + iVar10) = 0xe;
            puVar9[3] = 0x12;
            puVar9[2] = 0xc;
            puVar9[5] = 0x22;
            puVar9[4] = 0x19;
            puVar9[7] = 0x3f;
            puVar9[6] = 0x2e;
            puVar9[9] = 0x66;
            puVar9[8] = 0x56;
            puVar9[0xb] = 0x95;
            puVar9[10] = 0x7b;
            puVar9[0xd] = 0xdd;
            puVar9[0xc] = 0xb3;
            puVar9[1] = 5;
            puVar9[0xe] = 0x100;
          }
          else {
            if (iVar16 != 0x100) goto LAB_40af2ca0;
            *(undefined4 *)((int)puVar12 + iVar10) = 10;
            puVar9[8] = 0x59;
            puVar9[9] = 0x6e;
            puVar9[10] = 0x80;
            puVar9[1] = 5;
            puVar9[2] = 0xb;
            puVar9[3] = 0x11;
            puVar9[4] = 0x17;
            puVar9[5] = 0x1f;
            puVar9[6] = 0x2b;
            puVar9[7] = 0x3e;
          }
          goto LAB_40af2ff4;
        }
LAB_40af2ca0:
        iVar7 = 0;
        iVar2 = 1;
        piVar8 = piVar13;
        while( true ) {
          if (uVar4 == 0) {
            trap(7);
          }
          iVar7 = iVar7 + 1;
          uVar5 = (uint)(iVar16 * *piVar8) / uVar4 + 2;
          uVar4 = uVar5 & 0x80000003;
          piVar8 = piVar8 + 1;
          if ((int)uVar4 < 0) {
            uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
          }
          iVar3 = uVar5 - uVar4;
          if ((int)puVar9[iVar2 + -1] < iVar3) {
            puVar9[iVar2] = iVar3;
            iVar2 = iVar2 + 1;
          }
          if ((iVar11 <= iVar7) || (iVar16 / 2 <= (int)puVar9[iVar2 + -1])) break;
          uVar4 = *(uint *)(param_1 + 0x50);
        }
        puVar9[iVar2 + -1] = iVar16 / 2;
        *(int *)((int)puVar12 + iVar10) = iVar2 + -1;
LAB_40af2e0c:
        iVar2 = *(int *)(param_1 + 0xf0);
      }
      else {
        if (iVar16 == 0x400) {
          *(undefined4 *)((int)puVar12 + iVar10) = 0x11;
          puVar9[2] = 0xc;
          puVar9[3] = 0x12;
          puVar9[4] = 0x19;
          puVar9[5] = 0x22;
          puVar9[6] = 0x2e;
          puVar9[7] = 0x36;
          puVar9[8] = 0x3f;
          puVar9[9] = 0x56;
          puVar9[10] = 0x66;
          puVar9[0xb] = 0x7b;
          puVar9[0xc] = 0x95;
          puVar9[0xd] = 0xb3;
          puVar9[0xe] = 0xdd;
          puVar9[0xf] = 0x117;
          puVar9[0x10] = 0x168;
          puVar9[1] = 5;
          puVar9[0x11] = 0x200;
        }
        else if (iVar16 == 0x200) {
          *(undefined4 *)((int)puVar12 + iVar10) = 0xf;
          puVar9[6] = 0x25;
          puVar9[10] = 0x4a;
          puVar9[8] = 0x33;
          puVar9[0xc] = 0x6e;
          puVar9[0xb] = 0x59;
          puVar9[0xe] = 0xb4;
          puVar9[0xd] = 0x8b;
          puVar9[1] = 5;
          puVar9[2] = 0xb;
          puVar9[3] = 0x11;
          puVar9[4] = 0x17;
          puVar9[5] = 0x1f;
          puVar9[7] = 0x2b;
          puVar9[9] = 0x3e;
          puVar9[0xf] = 0x100;
        }
        else {
          if (iVar16 != 0x100) goto LAB_40af2ca0;
          *(undefined4 *)((int)puVar12 + iVar10) = 0xc;
          puVar9[2] = 9;
          puVar9[1] = 4;
          puVar9[4] = 0x10;
          puVar9[5] = 0x15;
          puVar9[6] = 0x1a;
          puVar9[7] = 0x25;
          puVar9[8] = 0x2d;
          puVar9[9] = 0x37;
          puVar9[10] = 0x46;
          puVar9[3] = 0xc;
          puVar9[0xb] = 0x5a;
          puVar9[0xc] = 0x80;
        }
LAB_40af2ff4:
        if (*(int *)((int)puVar12 + iVar10) < 1) goto LAB_40af2e0c;
        iVar2 = 0;
        puVar6 = puVar9;
        do {
          iVar2 = iVar2 + 1;
          iVar16 = puVar6[1] + 2;
          if (iVar16 < 0) {
            iVar16 = puVar6[1] + 5;
          }
          puVar6[1] = (iVar16 >> 2) << 2;
          puVar6 = puVar6 + 1;
        } while (iVar2 < *(int *)((int)puVar12 + iVar10));
        iVar2 = *(int *)(param_1 + 0xf0);
      }
      uVar15 = uVar15 + 1;
      iVar10 = iVar10 + 4;
      if (iVar2 <= (int)uVar15) goto LAB_40af2f30;
      puVar9 = puVar9 + 0x1d;
    } while( true );
  }
  puVar12 = *(undefined4 **)(param_1 + 0x144);
LAB_40af2f30:
  uVar1 = *puVar12;
  *(undefined4 **)(param_1 + 0x128) = puVar14;
  *(undefined4 *)(param_1 + 0x124) = uVar1;
  return;
}



/* 40af3244 FUN_40af3244 */

void FUN_40af3244(int param_1,int param_2,short param_3,short param_4,short *param_5,short *param_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = (int)param_3;
  iVar4 = (int)param_4;
  if (iVar2 < iVar4) {
    iVar3 = iVar4 - iVar2;
    sVar1 = (short)((iVar4 + iVar2) / 2);
    iVar4 = (int)sVar1;
    *param_5 = (short)(iVar3 / 2);
    *param_6 = sVar1;
  }
  else {
    *param_5 = 0;
    *param_6 = param_4;
  }
  if (param_2 == 1) {
    if ((*(int *)(param_1 + 0x84) == 1) && (*(int *)(param_1 + 0x8c) == 0)) {
      sVar1 = (short)((iVar4 + *param_5) / 2);
      *param_5 = sVar1;
      *param_6 = sVar1;
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x84) == 1) && (*(int *)(param_1 + 0x94) == 0)) {
    sVar1 = (short)((iVar4 + *param_5) / 2);
    *param_5 = sVar1;
    *param_6 = sVar1;
    return;
  }
  return;
}



/* 40af333c FUN_40af333c */

void FUN_40af333c(int param_1,int param_2,short param_3,short param_4,uint param_5,short *param_6,
                 short *param_7)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_3;
  iVar4 = (int)param_4;
  sVar1 = (short)param_5;
  if (iVar4 < iVar3) {
    iVar2 = ((param_5 & 0xffff) + (iVar4 + iVar3) / 2) * 0x10000;
    *param_6 = sVar1 + (short)((iVar3 - iVar4) / 2);
    *param_7 = (short)((uint)iVar2 >> 0x10);
  }
  else {
    iVar2 = (int)sVar1 << 0x11;
    *param_6 = sVar1;
    *param_7 = (short)((uint)iVar2 >> 0x10);
  }
  if (param_2 == 1) {
    if ((*(int *)(param_1 + 0x84) == 1) && (*(int *)(param_1 + 0x94) == 0)) {
      sVar1 = (short)(((iVar2 >> 0x10) + (int)*param_6) / 2);
      *param_6 = sVar1;
      *param_7 = sVar1;
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x84) == 1) && (*(int *)(param_1 + 0x8c) == 0)) {
    sVar1 = (short)(((iVar2 >> 0x10) + (int)*param_6) / 2);
    *param_6 = sVar1;
    *param_7 = sVar1;
    return;
  }
  return;
}



/* 40af3458 FUN_40af3458 */

undefined4 FUN_40af3458(int param_1)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  sVar1 = *(short *)(param_1 + 0x21c);
  if (0 < sVar1) {
    iVar8 = *(int *)(param_1 + 0x134);
    iVar7 = *(int *)(param_1 + 0x220);
    iVar5 = 0;
    iVar6 = 0;
    do {
      iVar4 = *(short *)(iVar7 + iVar6) * 0x594 + iVar8;
      iVar5 = (iVar5 + 1) * 0x10000 >> 0x10;
      iVar2 = (int)*(short *)(iVar4 + 0x82);
      if ((int)*(short *)(iVar4 + 0x80) < (int)*(short *)(iVar4 + 0x82)) {
        iVar2 = (int)*(short *)(iVar4 + 0x80);
      }
      iVar6 = iVar6 + 2;
      if ((iVar2 - 0x40U & 0xffff) < 0x7c1) {
        piVar3 = (int *)(&PTR_DAT_40b10fb4)[iVar2 >> 7];
        *(int *)(iVar4 + 0x50) = *piVar3 >> 1;
        *(int *)(iVar4 + 0x54) = piVar3[1] >> 1;
        *(int *)(iVar4 + 0x58) = -(*piVar3 >> 1);
        *(int *)(iVar4 + 0x5c) = piVar3[1] >> 1;
        *(int *)(iVar4 + 0x60) = piVar3[8];
      }
    } while (iVar5 < sVar1);
  }
  return 0;
}



/* 40af352c FUN_40af352c */

void FUN_40af352c(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x40) != 3) {
    if ((param_2 < 5) || (param_2 < 0xf)) {
      iVar1 = 0xd;
      *(undefined4 *)(param_1 + 0x38) = 0xd;
    }
    else if (param_2 < 0x20) {
      *(undefined4 *)(param_1 + 0x38) = 0xc;
      iVar1 = 0xc;
    }
    else if (param_2 < 0x28) {
      *(undefined4 *)(param_1 + 0x38) = 0xb;
      iVar1 = 0xb;
    }
    else if (param_2 < 0x2d) {
      *(undefined4 *)(param_1 + 0x38) = 10;
      iVar1 = 10;
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = 9;
      iVar1 = 9;
    }
    *(int *)(param_1 + 0x3c) = (1 << iVar1) + -1;
    return;
  }
  *(undefined4 *)(param_1 + 0x3c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x38) = 0x1f;
  return;
}



/* 40af3608 FUN_40af3608 */

/* Boundary evidence: original MIPS .pdata 40af3608..40af5ca3. Semantic name remains unreviewed. */

undefined4 FUN_40af3608(int param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  longlong lVar3;
  short *psVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  undefined4 uVar15;
  int *piVar16;
  uint uVar17;
  int *piVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int *piVar25;
  uint uVar26;
  uint uVar27;
  int *piVar28;
  int *piVar29;
  uint *puVar30;
  int iVar31;
  int iVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  int iVar36;
  uint uVar37;
  int iVar38;
  uint *puVar39;
  uint uVar40;
  uint uVar41;
  int iVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  int iVar46;
  int *piVar47;
  uint uVar48;
  uint uVar49;
  int *piVar50;
  uint uVar51;
  uint uVar52;
  uint uVar53;
  uint uVar54;
  uint uVar55;
  uint *puVar56;
  uint uVar57;
  uint uVar58;
  uint uVar59;
  uint uVar60;
  int *piVar61;
  uint uVar62;
  int *piVar63;
  int local_34c;
  int local_33c;
  int local_338;
  int local_330;
  int local_328;
  int local_324;
  int local_320;
  int local_31c;
  int local_318;
  int local_314;
  int local_310;
  int local_30c;
  int local_308;
  int local_304;
  int local_300;
  uint *local_2fc;
  uint *local_2f4;
  int local_2ec;
  undefined4 local_2e4;
  uint local_2a8;
  int local_2a4;
  uint local_290;
  int local_28c;
  uint local_260;
  int local_25c;
  uint local_240;
  int local_23c;
  uint local_230;
  int local_22c;
  uint local_220;
  int local_21c;
  uint local_200;
  int local_1fc;
  uint local_1e8;
  int local_1e4;
  uint local_1c0;
  int local_1bc;
  uint local_188;
  int local_184;
  
  iVar36 = *(int *)(param_1 + 0x40);
  iVar8 = *(int *)(param_1 + 0x134);
  piVar9 = *(int **)(param_1 + 0x1fc);
  local_2e4 = 0;
  if ((iVar36 < 3) || ((*(int *)(param_1 + 0x218) != 0 && (*(int *)(param_1 + 0x214) != 0)))) {
    iVar22 = (int)*(short *)(param_1 + 0x21c);
    if (iVar22 < 1) {
      bVar2 = true;
    }
    else {
      bVar2 = true;
      iVar10 = 0;
      do {
        psVar4 = (short *)(*(int *)(param_1 + 0x220) + iVar10);
        iVar10 = iVar10 + 2;
        bVar2 = (bool)(bVar2 & *(int *)(iVar8 + *psVar4 * 0x594 + 0x28) == 0);
      } while (iVar10 != ((iVar22 - 1U & 0xffff) + 1) * 2);
    }
    uVar15 = local_2e4;
    if ((iVar36 < 3) && (param_2 == 0)) {
      if ((*(int *)(iVar8 + 0x48) != 0) && (!bVar2)) {
        uVar1 = *(ushort *)(param_1 + 0x58);
        piVar29 = *(int **)(iVar8 + 0x3c);
        piVar9 = *(int **)(iVar8 + 0x5d0);
        if (uVar1 != 0) {
          iVar36 = 1;
          iVar22 = 0;
          do {
            bVar2 = iVar36 < (int)(uint)uVar1;
            *(undefined4 *)(iVar8 + iVar22 + 0x28) = 1;
            iVar22 = iVar22 + 0x594;
            iVar36 = iVar36 + 1;
          } while (bVar2);
        }
        iVar8 = (int)*(short *)(iVar8 + 0x7e);
        uVar15 = 0;
        if (0 < iVar8) {
          do {
            iVar36 = *piVar29;
            iVar22 = *piVar9;
            iVar8 = iVar8 + -1;
            *piVar29 = iVar22 + iVar36;
            *piVar9 = iVar36 - iVar22;
            piVar29 = piVar29 + 1;
            piVar9 = piVar9 + 1;
          } while (iVar8 != 0);
          uVar15 = 0;
        }
      }
    }
    else {
      uVar15 = 0;
      if ((iVar36 == 3) &&
         ((!bVar2 && (iVar36 = *(int *)(param_1 + 0x214), uVar15 = local_2e4, 0 < iVar36)))) {
        iVar10 = *(int *)(param_1 + 0x218);
        local_31c = 0;
        local_2ec = 0;
        do {
          piVar29 = (int *)(iVar10 + local_31c);
          iVar42 = piVar29[1];
          if (((piVar29[2] == param_2) && (iVar46 = *piVar29, iVar46 != 1)) &&
             ((piVar29[3] != 1 || (piVar29[4] != 2)))) {
            if (((*(short *)(param_1 + 0x58) == 2) && (piVar29[3] == 1)) && (piVar29[4] == 1)) {
              iVar42 = *(int *)(param_1 + 0x124);
              puVar56 = *(uint **)(iVar8 + 0x3c);
              puVar30 = *(uint **)(iVar8 + 0x5d0);
              if (0 < iVar42) {
                iVar36 = *(int *)(param_1 + 0x128);
                iVar19 = 0;
                iVar46 = 0;
                iVar13 = 4;
                do {
                  if (*(int *)((int)piVar29 + iVar46 + 0x18) == 1) {
                    iVar23 = *(int *)(iVar36 + iVar46);
                    if (iVar23 < *(int *)(iVar36 + iVar13)) {
                      do {
                        uVar6 = *puVar56;
                        uVar7 = *puVar30;
                        iVar23 = iVar23 + 1;
                        *puVar56 = uVar6 - uVar7;
                        *puVar30 = uVar7 + uVar6;
                        puVar56 = puVar56 + 1;
                        puVar30 = puVar30 + 1;
                      } while (iVar23 < *(int *)(iVar36 + iVar13));
                      iVar42 = *(int *)(param_1 + 0x124);
                    }
                  }
                  else {
                    iVar23 = *(int *)(iVar36 + iVar46);
                    if (iVar23 < *(int *)(iVar36 + iVar13)) {
                      do {
                        iVar23 = iVar23 + 1;
                        *puVar56 = (int)((ulonglong)((longlong)(int)*puVar56 * 0x16a) >> 0x20) <<
                                   0x18 | (uint)((longlong)(int)*puVar56 * 0x16a) >> 8;
                        puVar56 = puVar56 + 1;
                        *puVar30 = (int)((ulonglong)((longlong)(int)*puVar30 * 0x16a) >> 0x20) <<
                                   0x18 | (uint)((longlong)(int)*puVar30 * 0x16a) >> 8;
                        puVar30 = puVar30 + 1;
                      } while (iVar23 < *(int *)(iVar36 + iVar13));
                      iVar42 = *(int *)(param_1 + 0x124);
                    }
                  }
                  iVar19 = iVar19 + 1;
                  iVar46 = iVar46 + 4;
                  iVar13 = iVar13 + 4;
                } while (iVar19 < iVar42);
                iVar36 = *(int *)(param_1 + 0x214);
              }
            }
            else {
              puVar30 = (uint *)piVar29[0x25];
              piVar63 = *(int **)(param_1 + 0x200);
              if (0 < iVar22) {
                iVar23 = *(int *)(param_1 + 0x220);
                iVar13 = 0;
                iVar38 = 0;
                iVar19 = 0;
                do {
                  while( true ) {
                    iVar31 = (int)*(short *)(iVar23 + iVar19);
                    iVar13 = (iVar13 + 1) * 0x10000 >> 0x10;
                    iVar19 = iVar19 + 2;
                    if (*(int *)(iVar42 + iVar31 * 4) == 1) break;
                    if (iVar13 >= iVar22) goto LAB_40af38e8;
                  }
                  piVar25 = piVar63 + iVar38;
                  iVar38 = iVar38 + 1;
                  *piVar25 = *(int *)(iVar8 + iVar31 * 0x594 + 0x98);
                } while (iVar13 < iVar22);
              }
LAB_40af38e8:
              if (iVar46 == 2) {
                iVar42 = *(int *)(param_1 + 0x124);
                if (0 < iVar42) {
                  local_300 = 0;
                  local_324 = 0;
                  iVar36 = 4;
                  piVar25 = piVar63 + 1;
                  do {
                    if (*(int *)((int)piVar29 + local_300 + 0x18) == 1) {
                      iVar46 = *(int *)(*(int *)(param_1 + 0x128) + local_300);
                      if (iVar46 < *(int *)(*(int *)(param_1 + 0x128) + iVar36)) {
                        puVar56 = (uint *)*piVar25;
                        do {
                          puVar39 = (uint *)*piVar63;
                          uVar17 = *puVar39;
                          uVar12 = *puVar30;
                          uVar7 = puVar30[2];
                          uVar20 = puVar30[3];
                          uVar11 = puVar30[1];
                          uVar6 = *puVar56;
                          *piVar63 = (int)(puVar39 + 1);
                          piVar14 = (int *)*piVar25;
                          puVar56 = (uint *)(piVar14 + 1);
                          *piVar25 = (int)puVar56;
                          iVar42 = *(int *)(param_1 + 0x128);
                          *puVar39 = ((((int)uVar6 >> 0x1f) * uVar11 + ((int)uVar11 >> 0x1f) * uVar6
                                      + (int)((ulonglong)uVar6 * (ulonglong)uVar11 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar6 * (ulonglong)uVar11) >> 0x1e) +
                                     ((((int)uVar17 >> 0x1f) * uVar12 +
                                       ((int)uVar12 >> 0x1f) * uVar17 +
                                      (int)((ulonglong)uVar17 * (ulonglong)uVar12 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar17 * (ulonglong)uVar12) >> 0x1e);
                          *piVar14 = ((((int)uVar6 >> 0x1f) * uVar20 + ((int)uVar20 >> 0x1f) * uVar6
                                      + (int)((ulonglong)uVar6 * (ulonglong)uVar20 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar6 * (ulonglong)uVar20) >> 0x1e) +
                                     ((((int)uVar7 >> 0x1f) * uVar17 + ((int)uVar17 >> 0x1f) * uVar7
                                      + (int)((ulonglong)uVar7 * (ulonglong)uVar17 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar7 * (ulonglong)uVar17) >> 0x1e);
                          iVar46 = iVar46 + 1;
                        } while (iVar46 < *(int *)(iVar42 + iVar36));
                        iVar42 = *(int *)(param_1 + 0x124);
                      }
                    }
                    else {
                      *piVar63 = *piVar63 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + iVar36) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_300)) * 4;
                      *piVar25 = *piVar25 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + iVar36) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_300)) * 4;
                    }
                    local_324 = local_324 + 1;
                    local_300 = local_300 + 4;
                    iVar36 = iVar36 + 4;
                  } while (local_324 < iVar42);
LAB_40af39a0:
                  iVar36 = *(int *)(param_1 + 0x214);
                }
              }
              else if (iVar46 == 3) {
                iVar42 = *(int *)(param_1 + 0x124);
                if (0 < iVar42) {
                  piVar25 = piVar63 + 1;
                  piVar14 = piVar63 + 2;
                  local_33c = 0;
                  local_304 = 0;
                  local_308 = 4;
                  do {
                    if (*(int *)((int)piVar29 + local_304 + 0x18) == 1) {
                      local_328 = *(int *)(*(int *)(param_1 + 0x128) + local_304);
                      if (local_328 < *(int *)(*(int *)(param_1 + 0x128) + local_308)) {
                        local_2fc = (uint *)*piVar14;
                        do {
                          uVar34 = puVar30[7];
                          uVar6 = *(uint *)*piVar25;
                          uVar20 = puVar30[4];
                          uVar27 = puVar30[5];
                          puVar56 = (uint *)*piVar63;
                          uVar11 = puVar30[8];
                          uVar21 = puVar30[1];
                          uVar35 = *puVar56;
                          uVar17 = puVar30[6];
                          uVar26 = *puVar30;
                          uVar7 = *local_2fc;
                          uVar33 = puVar30[2];
                          *piVar63 = (int)(puVar56 + 1);
                          uVar12 = puVar30[3];
                          iVar36 = (int)uVar35 >> 0x1f;
                          piVar47 = (int *)*piVar25;
                          *piVar25 = (int)(piVar47 + 1);
                          iVar46 = (int)uVar6 >> 0x1f;
                          piVar16 = (int *)*piVar14;
                          local_2fc = (uint *)(piVar16 + 1);
                          *piVar14 = (int)local_2fc;
                          iVar13 = (int)uVar7 >> 0x1f;
                          iVar42 = *(int *)(param_1 + 0x128);
                          *puVar56 = ((iVar46 * uVar21 + ((int)uVar21 >> 0x1f) * uVar6 +
                                      (int)((ulonglong)uVar6 * (ulonglong)uVar21 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar6 * (ulonglong)uVar21) >> 0x1e) +
                                     ((iVar36 * uVar26 + ((int)uVar26 >> 0x1f) * uVar35 +
                                      (int)((ulonglong)uVar35 * (ulonglong)uVar26 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar35 * (ulonglong)uVar26) >> 0x1e) +
                                     ((((int)uVar33 >> 0x1f) * uVar7 + iVar13 * uVar33 +
                                      (int)((ulonglong)uVar7 * (ulonglong)uVar33 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar7 * (ulonglong)uVar33) >> 0x1e);
                          *piVar47 = ((iVar46 * uVar20 + ((int)uVar20 >> 0x1f) * uVar6 +
                                      (int)((ulonglong)uVar6 * (ulonglong)uVar20 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar6 * (ulonglong)uVar20) >> 0x1e) +
                                     ((((int)uVar12 >> 0x1f) * uVar35 + iVar36 * uVar12 +
                                      (int)((ulonglong)uVar12 * (ulonglong)uVar35 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar12 * (ulonglong)uVar35) >> 0x1e) +
                                     ((((int)uVar27 >> 0x1f) * uVar7 + iVar13 * uVar27 +
                                      (int)((ulonglong)uVar7 * (ulonglong)uVar27 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar7 * (ulonglong)uVar27) >> 0x1e);
                          *piVar16 = ((((int)uVar34 >> 0x1f) * uVar6 + iVar46 * uVar34 +
                                      (int)((ulonglong)uVar6 * (ulonglong)uVar34 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar6 * (ulonglong)uVar34) >> 0x1e) +
                                     ((((int)uVar17 >> 0x1f) * uVar35 + iVar36 * uVar17 +
                                      (int)((ulonglong)uVar17 * (ulonglong)uVar35 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar17 * (ulonglong)uVar35) >> 0x1e) +
                                     ((((int)uVar11 >> 0x1f) * uVar7 + iVar13 * uVar11 +
                                      (int)((ulonglong)uVar7 * (ulonglong)uVar11 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar7 * (ulonglong)uVar11) >> 0x1e);
                          local_328 = local_328 + 1;
                        } while (local_328 < *(int *)(iVar42 + local_308));
                        iVar42 = *(int *)(param_1 + 0x124);
                      }
                    }
                    else {
                      *piVar63 = *piVar63 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_308) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_304)) * 4;
                      *piVar25 = *piVar25 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_308) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_304)) * 4;
                      *piVar14 = *piVar14 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_308) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_304)) * 4;
                    }
                    local_33c = local_33c + 1;
                    local_304 = local_304 + 4;
                    local_308 = local_308 + 4;
                  } while (local_33c < iVar42);
                  iVar36 = *(int *)(param_1 + 0x214);
                }
              }
              else if (iVar46 == 4) {
                iVar42 = *(int *)(param_1 + 0x124);
                if (0 < iVar42) {
                  piVar14 = piVar63 + 2;
                  piVar25 = piVar63 + 1;
                  piVar47 = piVar63 + 3;
                  local_310 = 4;
                  local_338 = 0;
                  local_30c = 0;
                  do {
                    if (*(int *)((int)piVar29 + local_30c + 0x18) == 1) {
                      local_330 = *(int *)(*(int *)(param_1 + 0x128) + local_30c);
                      if (local_330 < *(int *)(*(int *)(param_1 + 0x128) + local_310)) {
                        puVar56 = (uint *)*piVar47;
                        do {
                          puVar39 = (uint *)*piVar63;
                          uVar20 = puVar30[5];
                          uVar41 = puVar30[0xd];
                          uVar44 = puVar30[0xe];
                          uVar21 = puVar30[4];
                          uVar27 = puVar30[7];
                          uVar11 = *(uint *)*piVar14;
                          uVar17 = *puVar39;
                          uVar26 = puVar30[6];
                          uVar35 = puVar30[10];
                          uVar33 = puVar30[9];
                          uVar40 = puVar30[1];
                          uVar49 = *puVar30;
                          uVar43 = puVar30[2];
                          uVar7 = *(uint *)*piVar25;
                          uVar6 = puVar30[3];
                          *piVar63 = (int)(puVar39 + 1);
                          uVar12 = *puVar56;
                          uVar34 = puVar30[8];
                          iVar19 = (int)uVar17 >> 0x1f;
                          uVar45 = puVar30[0xc];
                          uVar48 = puVar30[0xf];
                          uVar37 = puVar30[0xb];
                          piVar16 = (int *)*piVar25;
                          iVar42 = (int)uVar7 >> 0x1f;
                          *piVar25 = (int)(piVar16 + 1);
                          iVar46 = (int)uVar11 >> 0x1f;
                          iVar36 = (int)uVar12 >> 0x1f;
                          piVar18 = (int *)*piVar14;
                          local_28c = (int)((ulonglong)uVar34 * (ulonglong)uVar17 >> 0x20);
                          local_290 = (uint)((ulonglong)uVar34 * (ulonglong)uVar17);
                          *piVar14 = (int)(piVar18 + 1);
                          local_2a4 = (int)((ulonglong)uVar12 * (ulonglong)uVar27 >> 0x20);
                          local_25c = (int)((ulonglong)uVar12 * (ulonglong)uVar6 >> 0x20);
                          local_2a8 = (uint)((ulonglong)uVar12 * (ulonglong)uVar27);
                          local_260 = (uint)((ulonglong)uVar12 * (ulonglong)uVar6);
                          piVar28 = (int *)*piVar47;
                          *puVar39 = ((iVar42 * uVar40 + ((int)uVar40 >> 0x1f) * uVar7 +
                                      (int)((ulonglong)uVar7 * (ulonglong)uVar40 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar7 * (ulonglong)uVar40) >> 0x1e) +
                                     ((iVar46 * uVar43 + ((int)uVar43 >> 0x1f) * uVar11 +
                                      (int)((ulonglong)uVar11 * (ulonglong)uVar43 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar11 * (ulonglong)uVar43) >> 0x1e) +
                                     ((((int)uVar49 >> 0x1f) * uVar17 + iVar19 * uVar49 +
                                      (int)((ulonglong)uVar17 * (ulonglong)uVar49 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar17 * (ulonglong)uVar49) >> 0x1e) +
                                     ((((int)uVar6 >> 0x1f) * uVar12 + iVar36 * uVar6 + local_25c) *
                                      4 | local_260 >> 0x1e);
                          puVar56 = (uint *)(piVar28 + 1);
                          *piVar47 = (int)puVar56;
                          *piVar16 = ((((int)uVar20 >> 0x1f) * uVar7 + iVar42 * uVar20 +
                                      (int)((ulonglong)uVar7 * (ulonglong)uVar20 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar7 * (ulonglong)uVar20) >> 0x1e) +
                                     ((((int)uVar26 >> 0x1f) * uVar11 + iVar46 * uVar26 +
                                      (int)((ulonglong)uVar11 * (ulonglong)uVar26 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar11 * (ulonglong)uVar26) >> 0x1e) +
                                     ((iVar19 * uVar21 + ((int)uVar21 >> 0x1f) * uVar17 +
                                      (int)((ulonglong)uVar21 * (ulonglong)uVar17 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar21 * (ulonglong)uVar17) >> 0x1e) +
                                     ((((int)uVar27 >> 0x1f) * uVar12 + iVar36 * uVar27 + local_2a4)
                                      * 4 | local_2a8 >> 0x1e);
                          iVar13 = *(int *)(param_1 + 0x128);
                          *piVar18 = ((((int)uVar33 >> 0x1f) * uVar7 + iVar42 * uVar33 +
                                      (int)((ulonglong)uVar7 * (ulonglong)uVar33 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar7 * (ulonglong)uVar33) >> 0x1e) +
                                     ((((int)uVar35 >> 0x1f) * uVar11 + iVar46 * uVar35 +
                                      (int)((ulonglong)uVar11 * (ulonglong)uVar35 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar11 * (ulonglong)uVar35) >> 0x1e) +
                                     ((iVar19 * uVar34 + ((int)uVar34 >> 0x1f) * uVar17 + local_28c)
                                      * 4 | local_290 >> 0x1e) +
                                     ((((int)uVar37 >> 0x1f) * uVar12 + iVar36 * uVar37 +
                                      (int)((ulonglong)uVar12 * (ulonglong)uVar37 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar12 * (ulonglong)uVar37) >> 0x1e);
                          *piVar28 = ((((int)uVar41 >> 0x1f) * uVar7 + iVar42 * uVar41 +
                                      (int)((ulonglong)uVar7 * (ulonglong)uVar41 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar7 * (ulonglong)uVar41) >> 0x1e) +
                                     ((((int)uVar44 >> 0x1f) * uVar11 + iVar46 * uVar44 +
                                      (int)((ulonglong)uVar11 * (ulonglong)uVar44 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar11 * (ulonglong)uVar44) >> 0x1e) +
                                     ((iVar19 * uVar45 + ((int)uVar45 >> 0x1f) * uVar17 +
                                      (int)((ulonglong)uVar45 * (ulonglong)uVar17 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar45 * (ulonglong)uVar17) >> 0x1e) +
                                     ((((int)uVar48 >> 0x1f) * uVar12 + iVar36 * uVar48 +
                                      (int)((ulonglong)uVar12 * (ulonglong)uVar48 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar12 * (ulonglong)uVar48) >> 0x1e);
                          local_330 = local_330 + 1;
                        } while (local_330 < *(int *)(iVar13 + local_310));
                        iVar42 = *(int *)(param_1 + 0x124);
                      }
                    }
                    else {
                      *piVar63 = *piVar63 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_310) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_30c)) * 4;
                      *piVar25 = *piVar25 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_310) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_30c)) * 4;
                      *piVar14 = *piVar14 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_310) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_30c)) * 4;
                      *piVar47 = *piVar47 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_310) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_30c)) * 4;
                    }
                    local_338 = local_338 + 1;
                    local_30c = local_30c + 4;
                    local_310 = local_310 + 4;
                  } while (local_338 < iVar42);
                  iVar36 = *(int *)(param_1 + 0x214);
                }
              }
              else if (iVar46 == 5) {
                iVar42 = *(int *)(param_1 + 0x124);
                if (0 < iVar42) {
                  piVar25 = piVar63 + 1;
                  piVar14 = piVar63 + 2;
                  piVar47 = piVar63 + 3;
                  piVar16 = piVar63 + 4;
                  local_318 = 4;
                  local_320 = 0;
                  local_314 = 0;
                  do {
                    if (*(int *)((int)piVar29 + local_314 + 0x18) == 1) {
                      local_34c = *(int *)(*(int *)(param_1 + 0x128) + local_314);
                      if (local_34c < *(int *)(*(int *)(param_1 + 0x128) + local_318)) {
                        local_2f4 = (uint *)*piVar16;
                        do {
                          uVar11 = puVar30[1];
                          uVar53 = *(uint *)*piVar25;
                          uVar33 = *puVar30;
                          uVar59 = *(uint *)*piVar63;
                          uVar43 = puVar30[3];
                          uVar55 = *(uint *)*piVar14;
                          uVar58 = *(uint *)*piVar47;
                          uVar40 = puVar30[4];
                          iVar19 = (int)uVar53 >> 0x1f;
                          iVar36 = (int)uVar55 >> 0x1f;
                          uVar20 = puVar30[2];
                          uVar60 = *local_2f4;
                          iVar42 = (int)uVar58 >> 0x1f;
                          iVar23 = (int)uVar59 >> 0x1f;
                          iVar46 = (int)uVar60 >> 0x1f;
                          uVar26 = puVar30[5];
                          uVar12 = puVar30[6];
                          uVar62 = puVar30[7];
                          uVar48 = puVar30[0xd];
                          uVar34 = puVar30[8];
                          uVar37 = puVar30[9];
                          uVar44 = puVar30[10];
                          uVar51 = puVar30[0xe];
                          uVar6 = puVar30[0xf];
                          uVar17 = puVar30[0x12];
                          uVar27 = puVar30[0x13];
                          uVar35 = puVar30[0xc];
                          uVar49 = puVar30[0x14];
                          uVar21 = puVar30[0xb];
                          uVar41 = puVar30[0x10];
                          uVar45 = puVar30[0x11];
                          uVar54 = puVar30[0x15];
                          uVar57 = puVar30[0x16];
                          piVar18 = (int *)*piVar63;
                          *piVar63 = *piVar63 + 4;
                          piVar28 = (int *)*piVar25;
                          uVar7 = puVar30[0x18];
                          *piVar25 = (int)(piVar28 + 1);
                          piVar50 = (int *)*piVar14;
                          uVar52 = puVar30[0x17];
                          *piVar18 = ((iVar19 * uVar11 + ((int)uVar11 >> 0x1f) * uVar53 +
                                      (int)((ulonglong)uVar53 * (ulonglong)uVar11 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar53 * (ulonglong)uVar11) >> 0x1e) +
                                     ((iVar36 * uVar20 + ((int)uVar20 >> 0x1f) * uVar55 +
                                      (int)((ulonglong)uVar55 * (ulonglong)uVar20 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar55 * (ulonglong)uVar20) >> 0x1e) +
                                     ((iVar23 * uVar33 + ((int)uVar33 >> 0x1f) * uVar59 +
                                      (int)((ulonglong)uVar59 * (ulonglong)uVar33 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar59 * (ulonglong)uVar33) >> 0x1e) +
                                     ((iVar42 * uVar43 + ((int)uVar43 >> 0x1f) * uVar58 +
                                      (int)((ulonglong)uVar58 * (ulonglong)uVar43 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar58 * (ulonglong)uVar43) >> 0x1e) +
                                     ((iVar46 * uVar40 + ((int)uVar40 >> 0x1f) * uVar60 +
                                      (int)((ulonglong)uVar60 * (ulonglong)uVar40 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar60 * (ulonglong)uVar40) >> 0x1e);
                          *piVar14 = (int)(piVar50 + 1);
                          piVar18 = (int *)*piVar47;
                          *piVar47 = (int)(piVar18 + 1);
                          local_23c = (int)((ulonglong)uVar26 * (ulonglong)uVar59 >> 0x20);
                          local_240 = (uint)((ulonglong)uVar26 * (ulonglong)uVar59);
                          local_1fc = (int)((ulonglong)uVar44 * (ulonglong)uVar59 >> 0x20);
                          local_1bc = (int)((ulonglong)uVar6 * (ulonglong)uVar59 >> 0x20);
                          local_1c0 = (uint)((ulonglong)uVar6 * (ulonglong)uVar59);
                          local_200 = (uint)((ulonglong)uVar44 * (ulonglong)uVar59);
                          local_184 = (int)((ulonglong)uVar49 * (ulonglong)uVar59 >> 0x20);
                          local_188 = (uint)((ulonglong)uVar49 * (ulonglong)uVar59);
                          piVar61 = (int *)*piVar16;
                          local_22c = (int)((ulonglong)uVar58 * (ulonglong)uVar34 >> 0x20);
                          local_1e4 = (int)((ulonglong)uVar58 * (ulonglong)uVar48 >> 0x20);
                          local_230 = (uint)((ulonglong)uVar58 * (ulonglong)uVar34);
                          local_1e8 = (uint)((ulonglong)uVar58 * (ulonglong)uVar48);
                          local_21c = (int)((ulonglong)uVar60 * (ulonglong)uVar37 >> 0x20);
                          local_2f4 = (uint *)(piVar61 + 1);
                          local_220 = (uint)((ulonglong)uVar60 * (ulonglong)uVar37);
                          *piVar16 = (int)local_2f4;
                          iVar13 = *(int *)(param_1 + 0x128);
                          *piVar28 = ((iVar19 * uVar12 + ((int)uVar12 >> 0x1f) * uVar53 +
                                      (int)((ulonglong)uVar53 * (ulonglong)uVar12 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar53 * (ulonglong)uVar12) >> 0x1e) +
                                     ((iVar36 * uVar62 + ((int)uVar62 >> 0x1f) * uVar55 +
                                      (int)((ulonglong)uVar55 * (ulonglong)uVar62 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar55 * (ulonglong)uVar62) >> 0x1e) +
                                     ((iVar23 * uVar26 + ((int)uVar26 >> 0x1f) * uVar59 + local_23c)
                                      * 4 | local_240 >> 0x1e) +
                                     ((((int)uVar34 >> 0x1f) * uVar58 + iVar42 * uVar34 + local_22c)
                                      * 4 | local_230 >> 0x1e) +
                                     ((((int)uVar37 >> 0x1f) * uVar60 + iVar46 * uVar37 + local_21c)
                                      * 4 | local_220 >> 0x1e);
                          *piVar50 = ((((int)uVar21 >> 0x1f) * uVar53 + iVar19 * uVar21 +
                                      (int)((ulonglong)uVar53 * (ulonglong)uVar21 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar53 * (ulonglong)uVar21) >> 0x1e) +
                                     ((((int)uVar35 >> 0x1f) * uVar55 + iVar36 * uVar35 +
                                      (int)((ulonglong)uVar55 * (ulonglong)uVar35 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar55 * (ulonglong)uVar35) >> 0x1e) +
                                     ((iVar23 * uVar44 + ((int)uVar44 >> 0x1f) * uVar59 + local_1fc)
                                      * 4 | local_200 >> 0x1e) +
                                     ((((int)uVar48 >> 0x1f) * uVar58 + iVar42 * uVar48 + local_1e4)
                                      * 4 | local_1e8 >> 0x1e) +
                                     ((((int)uVar51 >> 0x1f) * uVar60 + iVar46 * uVar51 +
                                      (int)((ulonglong)uVar60 * (ulonglong)uVar51 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar60 * (ulonglong)uVar51) >> 0x1e);
                          *piVar18 = ((((int)uVar41 >> 0x1f) * uVar53 + iVar19 * uVar41 +
                                      (int)((ulonglong)uVar53 * (ulonglong)uVar41 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar53 * (ulonglong)uVar41) >> 0x1e) +
                                     ((((int)uVar45 >> 0x1f) * uVar55 + iVar36 * uVar45 +
                                      (int)((ulonglong)uVar55 * (ulonglong)uVar45 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar55 * (ulonglong)uVar45) >> 0x1e) +
                                     ((iVar23 * uVar6 + ((int)uVar6 >> 0x1f) * uVar59 + local_1bc) *
                                      4 | local_1c0 >> 0x1e) +
                                     ((((int)uVar17 >> 0x1f) * uVar58 + iVar42 * uVar17 +
                                      (int)((ulonglong)uVar58 * (ulonglong)uVar17 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar58 * (ulonglong)uVar17) >> 0x1e) +
                                     ((((int)uVar27 >> 0x1f) * uVar60 + iVar46 * uVar27 +
                                      (int)((ulonglong)uVar60 * (ulonglong)uVar27 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar60 * (ulonglong)uVar27) >> 0x1e);
                          *piVar61 = ((((int)uVar54 >> 0x1f) * uVar53 + iVar19 * uVar54 +
                                      (int)((ulonglong)uVar53 * (ulonglong)uVar54 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar53 * (ulonglong)uVar54) >> 0x1e) +
                                     ((((int)uVar57 >> 0x1f) * uVar55 + iVar36 * uVar57 +
                                      (int)((ulonglong)uVar55 * (ulonglong)uVar57 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar55 * (ulonglong)uVar57) >> 0x1e) +
                                     ((iVar23 * uVar49 + ((int)uVar49 >> 0x1f) * uVar59 + local_184)
                                      * 4 | local_188 >> 0x1e) +
                                     ((((int)uVar52 >> 0x1f) * uVar58 + iVar42 * uVar52 +
                                      (int)((ulonglong)uVar58 * (ulonglong)uVar52 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar58 * (ulonglong)uVar52) >> 0x1e) +
                                     ((((int)uVar7 >> 0x1f) * uVar60 + iVar46 * uVar7 +
                                      (int)((ulonglong)uVar60 * (ulonglong)uVar7 >> 0x20)) * 4 |
                                     (uint)((ulonglong)uVar60 * (ulonglong)uVar7) >> 0x1e);
                          local_34c = local_34c + 1;
                        } while (local_34c < *(int *)(iVar13 + local_318));
                        iVar42 = *(int *)(param_1 + 0x124);
                      }
                    }
                    else {
                      *piVar63 = *piVar63 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_318) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_314)) * 4;
                      *piVar25 = *piVar25 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_318) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_314)) * 4;
                      *piVar14 = *piVar14 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_318) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_314)) * 4;
                      *piVar47 = *piVar47 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_318) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_314)) * 4;
                      *piVar16 = *piVar16 +
                                 (*(int *)(*(int *)(param_1 + 0x128) + local_318) -
                                 *(int *)(*(int *)(param_1 + 0x128) + local_314)) * 4;
                    }
                    local_320 = local_320 + 1;
                    local_314 = local_314 + 4;
                    local_318 = local_318 + 4;
                  } while (local_320 < iVar42);
                  iVar36 = *(int *)(param_1 + 0x214);
                }
              }
              else {
                iVar42 = *(int *)(param_1 + 0x124);
                iVar13 = 0;
                if (0 < iVar42) {
                  iVar19 = 0;
                  iVar36 = 4;
LAB_40af3924:
                  do {
                    if (*(int *)((int)piVar29 + iVar19 + 0x18) == 1) {
                      iVar23 = *(int *)(param_1 + 0x128);
                      iVar38 = *(int *)(iVar23 + iVar19);
                      if (iVar38 < *(int *)(iVar23 + iVar36)) {
                        do {
                          if (0 < iVar46) {
                            iVar31 = piVar29[0x25];
                            iVar42 = 0;
                            piVar25 = piVar9;
                            iVar23 = 1;
                            do {
                              *piVar25 = 0;
                              iVar32 = 0;
                              iVar24 = 0;
                              do {
                                puVar5 = (undefined4 *)((int)piVar63 + iVar24);
                                piVar14 = (int *)(iVar31 + iVar42 * iVar46 * 4 + iVar24);
                                iVar24 = iVar24 + 4;
                                lVar3 = (longlong)*(int *)*puVar5 * (longlong)*piVar14;
                                iVar32 = iVar32 + ((int)((ulonglong)lVar3 >> 0x20) << 2 |
                                                  (uint)lVar3 >> 0x1e);
                                *piVar25 = iVar32;
                              } while (iVar24 != iVar46 << 2);
                              iVar24 = iVar23 + 1;
                              piVar25 = piVar25 + 1;
                              iVar42 = iVar23;
                              iVar23 = iVar24;
                            } while (iVar24 != iVar46 + 1);
                            iVar42 = 0;
                            piVar25 = piVar63;
                            do {
                              puVar5 = (undefined4 *)*piVar25;
                              uVar15 = *(undefined4 *)((int)piVar9 + iVar42);
                              iVar42 = iVar42 + 4;
                              *piVar25 = (int)(puVar5 + 1);
                              *puVar5 = uVar15;
                              piVar25 = piVar25 + 1;
                            } while (iVar42 != iVar46 << 2);
                            iVar23 = *(int *)(param_1 + 0x128);
                          }
                          iVar38 = iVar38 + 1;
                        } while (iVar38 < *(int *)(iVar23 + iVar36));
                        iVar13 = iVar13 + 1;
                        iVar42 = *(int *)(param_1 + 0x124);
                        iVar19 = iVar19 + 4;
                        iVar36 = iVar36 + 4;
                        if (iVar42 <= iVar13) break;
                        goto LAB_40af3924;
                      }
                    }
                    else if (0 < iVar46) {
                      iVar23 = 0;
                      piVar25 = piVar63;
                      do {
                        iVar23 = iVar23 + 1;
                        *piVar25 = *piVar25 +
                                   (*(int *)(*(int *)(param_1 + 0x128) + iVar36) -
                                   *(int *)(*(int *)(param_1 + 0x128) + iVar19)) * 4;
                        piVar25 = piVar25 + 1;
                      } while (iVar23 < iVar46);
                    }
                    iVar13 = iVar13 + 1;
                    iVar19 = iVar19 + 4;
                    iVar36 = iVar36 + 4;
                  } while (iVar13 < iVar42);
                  goto LAB_40af39a0;
                }
              }
            }
          }
          local_2ec = local_2ec + 1;
          local_31c = local_31c + 0x98;
          uVar15 = local_2e4;
        } while (local_2ec < iVar36);
      }
    }
  }
  else {
    local_2e4 = 0x80070057;
    uVar15 = local_2e4;
  }
  return uVar15;
}



/* 40af5ca4 FUN_40af5ca4 */

/* Boundary evidence: original MIPS .pdata 40af5ca4..40af5db3. Semantic name remains unreviewed. */

int * FUN_40af5ca4(int *param_1,int param_2)

{
  int local_10;
  uint local_c;
  
  if (param_2 < 0x12) {
    if (param_2 < 0) {
      *param_1 = ~(-param_2 >> 3) + 0x1c;
      param_1[1] = 0x62089bf;
      return param_1;
    }
    local_10 = ~(param_2 >> 3) + 0x1c;
    local_c = 0xde939b1;
  }
  else if (param_2 < 0x92) {
    local_c = *(uint *)(&DAT_40b10ff8 + (param_2 + -0x12) * 4);
    local_10 = 0x18 - (param_2 >> 3);
    FUN_40aeb0ac(&local_c,&local_10,0x3fffffff);
    *param_1 = local_10;
    param_1[1] = local_c;
    return param_1;
  }
  *param_1 = local_10;
  param_1[1] = local_c;
  return param_1;
}



/* 40af5db4 FUN_40af5db4 */

/* Boundary evidence: original MIPS .pdata 40af5db4..40af691b. Semantic name remains unreviewed. */

undefined4 FUN_40af5db4(int param_1)

{
  ushort uVar1;
  short sVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  int *piVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  int iVar20;
  int *piVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  undefined4 *puVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  short *psVar31;
  int local_30;
  
  if (2 < *(int *)(param_1 + 0x40)) {
    iVar28 = (int)*(short *)(param_1 + 0x21c);
    iVar25 = 0;
    if (iVar28 < 1) {
      return 0;
    }
    iVar12 = *(int *)(param_1 + 0x134);
    psVar31 = *(short **)(param_1 + 0x220);
    iVar22 = 0;
    iVar27 = iVar12 + *psVar31 * 0x594;
    iVar17 = (int)*(short *)(iVar27 + 0x80);
    iVar16 = (int)*(short *)(iVar27 + 0x82);
    if (iVar17 < iVar16) goto LAB_40af6444;
LAB_40af6398:
    iVar30 = 0;
    if (*(int *)(param_1 + 0x84) == 1) goto LAB_40af647c;
LAB_40af63a4:
    iVar16 = iVar16 - iVar30;
    do {
      iVar16 = -(iVar16 / 2);
      while( true ) {
        iVar30 = -(iVar17 / 2);
        if (iVar30 < iVar16) {
          piVar8 = (int *)(*(int *)(iVar27 + 0x3c) + (iVar17 / 2) * -4);
          do {
            iVar30 = iVar30 + 1;
            *piVar8 = *piVar8 >> 5;
            piVar8 = piVar8 + 1;
          } while (iVar30 < iVar16);
        }
        iVar25 = (iVar25 + 1) * 0x10000 >> 0x10;
        iVar22 = iVar22 + 2;
        if (iVar28 <= iVar25) goto LAB_40af5df0;
        iVar27 = iVar12 + *(short *)((int)psVar31 + iVar22) * 0x594;
        iVar17 = (int)*(short *)(iVar27 + 0x80);
        iVar16 = (int)*(short *)(iVar27 + 0x82);
        if (iVar16 <= iVar17) goto LAB_40af6398;
LAB_40af6444:
        iVar30 = (int)(short)((iVar16 - iVar17) / 2);
        iVar16 = (int)(short)((iVar16 + iVar17) / 2);
        if (*(int *)(param_1 + 0x84) != 1) goto LAB_40af63a4;
LAB_40af647c:
        iVar16 = iVar16 - iVar30;
        if (*(int *)(param_1 + 0x8c) != 0) break;
        iVar16 = 0;
      }
    } while( true );
  }
  iVar28 = (int)*(short *)(param_1 + 0x21c);
LAB_40af5df0:
  if (iVar28 == 2) {
    psVar31 = *(short **)(param_1 + 0x220);
    local_30 = *(int *)(param_1 + 0x134);
    iVar25 = local_30 + psVar31[1] * 0x594;
    iVar27 = local_30 + *psVar31 * 0x594;
    uVar1 = *(ushort *)(iVar27 + 0x80);
    iVar12 = (int)(short)uVar1;
    if (*(int *)(param_1 + 0x40) < 3) {
      sVar2 = *(short *)(iVar27 + 0x82);
    }
    else {
      if (iVar12 != *(short *)(iVar25 + 0x80)) goto LAB_40af5e10;
      sVar2 = *(short *)(iVar27 + 0x82);
    }
    iVar18 = (int)sVar2;
    iVar17 = *(int *)(iVar27 + 0x50);
    iVar16 = *(int *)(iVar27 + 0x54);
    iVar30 = *(int *)(iVar27 + 0x58);
    iVar22 = *(int *)(iVar27 + 0x5c);
    iVar20 = *(int *)(iVar27 + 0x60);
    if (iVar18 < iVar12) {
      iVar24 = ((uint)uVar1 + (iVar18 + iVar12) / 2) * 0x10000;
      iVar29 = (int)(((uint)uVar1 + (iVar12 - iVar18) / 2) * 0x10000) >> 0x10;
    }
    else {
      iVar24 = iVar12 << 0x11;
      iVar29 = iVar12;
    }
    if ((*(int *)(param_1 + 0x84) == 1) && (*(int *)(param_1 + 0x8c) == 0)) {
      iVar29 = (int)(short)(((iVar24 >> 0x10) + iVar29) / 2);
    }
    if (iVar18 <= iVar12) {
      iVar6 = 0;
      iVar24 = iVar18;
    }
    else {
      iVar6 = (int)(short)((iVar18 - iVar12) / 2);
      iVar24 = (int)(short)((iVar18 + iVar12) / 2);
    }
    if ((*(int *)(param_1 + 0x84) == 1) && (*(int *)(param_1 + 0x8c) == 0)) {
      iVar6 = (int)(short)((iVar24 + iVar6) / 2);
      iVar24 = iVar6;
    }
    iVar10 = iVar18 / 2;
    puVar7 = *(undefined4 **)(iVar27 + 0x3c);
    puVar26 = *(undefined4 **)(iVar25 + 0x3c);
    if (0 < iVar10) {
      puVar15 = puVar26 + iVar18 + -1;
      puVar11 = puVar7 + iVar18 + -1;
      iVar25 = 0;
      puVar9 = puVar26;
      puVar14 = puVar7;
      do {
        uVar5 = *puVar14;
        iVar25 = iVar25 + 1;
        *puVar14 = *puVar11;
        *puVar11 = uVar5;
        uVar5 = *puVar9;
        *puVar9 = *puVar15;
        puVar14 = puVar14 + 1;
        *puVar15 = uVar5;
        puVar11 = puVar11 + -1;
        puVar9 = puVar9 + 1;
        puVar15 = puVar15 + -1;
      } while (iVar25 < iVar10);
    }
    piVar19 = puVar26 + iVar10 + -1;
    piVar21 = puVar7 + iVar10 + -1;
    piVar8 = puVar26 + -(iVar12 / 2);
    piVar13 = puVar7 + -(iVar12 / 2);
    if (iVar18 <= iVar12) {
      piVar8 = piVar8 + (iVar29 - iVar12);
      piVar13 = piVar13 + (iVar29 - iVar12);
    }
    else {
      piVar19 = piVar19 + (iVar24 - iVar18);
      piVar21 = piVar21 + (iVar24 - iVar18);
    }
    iVar25 = (iVar24 - iVar6) / 2;
    if (0 < iVar25) {
      iVar27 = 0;
      do {
        iVar29 = iVar17;
        iVar18 = iVar16;
        iVar12 = *piVar13;
        iVar16 = *piVar21;
        lVar3 = (longlong)-iVar29 * (longlong)iVar16;
        lVar4 = (longlong)iVar18 * (longlong)iVar12;
        *piVar13 = (int)(((int)((ulonglong)lVar4 >> 0x20) << 2 | (uint)lVar4 >> 0x1e) +
                        ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e)) >> 5;
        piVar13 = piVar13 + 1;
        lVar3 = (longlong)iVar29 * (longlong)iVar12;
        lVar4 = (longlong)iVar18 * (longlong)iVar16;
        *piVar21 = (int)(((int)((ulonglong)lVar4 >> 0x20) << 2 | (uint)lVar4 >> 0x1e) +
                        ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e)) >> 5;
        iVar12 = *piVar8;
        piVar21 = piVar21 + -1;
        iVar16 = *piVar19;
        lVar3 = (longlong)-iVar29 * (longlong)iVar16;
        lVar4 = (longlong)iVar18 * (longlong)iVar12;
        *piVar8 = (int)(((int)((ulonglong)lVar4 >> 0x20) << 2 | (uint)lVar4 >> 0x1e) +
                       ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e)) >> 5;
        piVar8 = piVar8 + 1;
        lVar3 = (longlong)iVar29 * (longlong)iVar12;
        lVar4 = (longlong)iVar18 * (longlong)iVar16;
        *piVar19 = (int)(((int)((ulonglong)lVar4 >> 0x20) << 2 | (uint)lVar4 >> 0x1e) +
                        ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e)) >> 5;
        piVar19 = piVar19 + -1;
        lVar3 = (longlong)iVar20 * (longlong)iVar18;
        lVar4 = (longlong)iVar20 * (longlong)iVar29;
        iVar27 = iVar27 + 1;
        iVar16 = iVar22 - ((int)((ulonglong)lVar4 >> 0x20) << 2 | (uint)lVar4 >> 0x1e);
        iVar17 = ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e) + iVar30;
        iVar22 = iVar18;
        iVar30 = iVar29;
      } while (iVar27 < iVar25);
    }
  }
  else {
    if (iVar28 < 1) {
      return 0;
    }
    local_30 = *(int *)(param_1 + 0x134);
    psVar31 = *(short **)(param_1 + 0x220);
LAB_40af5e10:
    iVar25 = 0;
    iVar27 = 0;
    do {
      iVar12 = local_30 + *(short *)((int)psVar31 + iVar27) * 0x594;
      uVar1 = *(ushort *)(iVar12 + 0x80);
      iVar20 = (int)(short)uVar1;
      iVar18 = (int)*(short *)(iVar12 + 0x82);
      iVar17 = *(int *)(iVar12 + 0x50);
      iVar16 = *(int *)(iVar12 + 0x54);
      iVar22 = *(int *)(iVar12 + 0x58);
      iVar30 = *(int *)(iVar12 + 0x5c);
      iVar29 = *(int *)(iVar12 + 0x60);
      if (iVar18 < iVar20) {
        iVar10 = *(int *)(param_1 + 0x84);
        iVar6 = ((uint)uVar1 + (iVar18 + iVar20) / 2) * 0x10000;
        iVar24 = (int)(((uint)uVar1 + (iVar20 - iVar18) / 2) * 0x10000) >> 0x10;
        if (iVar10 == 1) goto LAB_40af62bc;
LAB_40af5e78:
        if (iVar18 <= iVar20) goto LAB_40af5e84;
LAB_40af62e8:
        iVar6 = (int)(short)((iVar18 - iVar20) / 2);
        iVar23 = (int)(short)((iVar18 + iVar20) / 2);
      }
      else {
        iVar10 = *(int *)(param_1 + 0x84);
        iVar6 = iVar20 << 0x11;
        iVar24 = iVar20;
        if (iVar10 != 1) goto LAB_40af5e78;
LAB_40af62bc:
        if (*(int *)(param_1 + 0x8c) != 0) goto LAB_40af5e78;
        iVar24 = (int)(short)(((iVar6 >> 0x10) + iVar24) / 2);
        if (iVar20 < iVar18) goto LAB_40af62e8;
LAB_40af5e84:
        iVar6 = 0;
        iVar23 = iVar18;
      }
      if ((iVar10 == 1) && (*(int *)(param_1 + 0x8c) == 0)) {
        iVar23 = (int)(short)((iVar23 + iVar6) / 2);
        iVar6 = iVar23;
      }
      iVar10 = iVar18 / 2;
      puVar7 = *(undefined4 **)(iVar12 + 0x3c);
      if (0 < iVar10) {
        puVar9 = puVar7 + iVar18 + -1;
        iVar12 = 0;
        puVar26 = puVar7;
        do {
          uVar5 = *puVar26;
          iVar12 = iVar12 + 1;
          *puVar26 = *puVar9;
          *puVar9 = uVar5;
          puVar26 = puVar26 + 1;
          puVar9 = puVar9 + -1;
        } while (iVar12 < iVar10);
      }
      piVar13 = puVar7 + iVar10 + -1;
      piVar8 = puVar7 + -(iVar20 / 2);
      if (iVar20 < iVar18) {
        piVar13 = piVar13 + (iVar23 - iVar18);
      }
      else {
        piVar8 = piVar8 + (iVar24 - iVar20);
      }
      iVar12 = (iVar23 - iVar6) / 2;
      if (0 < iVar12) {
        iVar18 = 0;
        do {
          iVar24 = iVar17;
          iVar20 = iVar16;
          iVar16 = *piVar8;
          iVar17 = *piVar13;
          lVar3 = (longlong)-iVar24 * (longlong)iVar17;
          lVar4 = (longlong)iVar20 * (longlong)iVar16;
          *piVar8 = (int)(((int)((ulonglong)lVar4 >> 0x20) << 2 | (uint)lVar4 >> 0x1e) +
                         ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e)) >> 5;
          piVar8 = piVar8 + 1;
          lVar3 = (longlong)iVar24 * (longlong)iVar16;
          lVar4 = (longlong)iVar20 * (longlong)iVar17;
          *piVar13 = (int)(((int)((ulonglong)lVar4 >> 0x20) << 2 | (uint)lVar4 >> 0x1e) +
                          ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e)) >> 5;
          piVar13 = piVar13 + -1;
          lVar3 = (longlong)iVar29 * (longlong)iVar20;
          lVar4 = (longlong)iVar29 * (longlong)iVar24;
          iVar18 = iVar18 + 1;
          iVar16 = iVar30 - ((int)((ulonglong)lVar4 >> 0x20) << 2 | (uint)lVar4 >> 0x1e);
          iVar17 = iVar22 + ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e);
          iVar22 = iVar24;
          iVar30 = iVar20;
        } while (iVar18 < iVar12);
      }
      iVar25 = (int)(short)((short)iVar25 + 1);
      iVar27 = iVar27 + 2;
    } while (iVar25 < iVar28);
  }
  if (0 < iVar28) {
    iVar25 = 0;
    iVar27 = 0;
    do {
      iVar12 = local_30 + *(short *)((int)psVar31 + iVar27) * 0x594;
      iVar16 = (int)*(short *)(iVar12 + 0x80);
      uVar1 = *(ushort *)(iVar12 + 0x82);
      iVar17 = (int)(short)uVar1;
      iVar22 = (int)*(short *)(iVar12 + 0x84);
      if (iVar16 < iVar17) {
        iVar18 = *(int *)(param_1 + 0x84);
        iVar30 = (int)(short)((iVar17 - iVar16) / 2);
        iVar16 = (int)(short)((iVar17 + iVar16) / 2);
        if (iVar18 == 1) goto LAB_40af6244;
LAB_40af60dc:
        iVar20 = (iVar16 - iVar30) / 2;
      }
      else {
        iVar18 = *(int *)(param_1 + 0x84);
        iVar30 = 0;
        iVar16 = iVar17;
        if (iVar18 != 1) goto LAB_40af60dc;
LAB_40af6244:
        iVar20 = 0;
        if (*(int *)(param_1 + 0x8c) != 0) goto LAB_40af60dc;
      }
      if (iVar22 < iVar17) {
        iVar16 = (int)(((uint)uVar1 + (iVar17 - iVar22) / 2) * 0x10000) >> 0x10;
        iVar22 = (int)(((uint)uVar1 + (iVar22 + iVar17) / 2) * 0x10000) >> 0x10;
        if (iVar18 == 1) goto LAB_40af61f8;
LAB_40af610c:
        iVar16 = (iVar22 - iVar16) / 2;
      }
      else {
        iVar22 = (iVar17 << 0x11) >> 0x10;
        iVar16 = iVar17;
        if (iVar18 != 1) goto LAB_40af610c;
LAB_40af61f8:
        if (*(int *)(param_1 + 0x94) != 0) goto LAB_40af610c;
        iVar16 = 0;
      }
      if (*(int *)(param_1 + 0x40) < 3) {
        iVar17 = iVar17 - iVar16;
      }
      else {
        iVar17 = iVar17 / 2;
      }
      if (iVar20 < iVar17) {
        piVar8 = (int *)(*(int *)(iVar12 + 0x3c) + iVar20 * 4);
        do {
          iVar20 = iVar20 + 1;
          *piVar8 = *piVar8 >> 5;
          piVar8 = piVar8 + 1;
        } while (iVar20 < iVar17);
      }
      iVar25 = (iVar25 + 1) * 0x10000 >> 0x10;
      iVar27 = iVar27 + 2;
    } while (iVar25 < iVar28);
  }
  return 0;
}



/* 40af691c FUN_40af691c */

void FUN_40af691c(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  if (*(int *)(param_1 + 0xa8) != 0) {
    return;
  }
  iVar10 = *(int *)(param_1 + 0x40);
  if (iVar10 < 3) {
    iVar9 = *(int *)(param_1 + 0x134);
    uVar8 = (uint)*(ushort *)(param_1 + 0x58);
    bVar2 = **(char **)(*(int *)(iVar9 + 200) + 0x10) != '\0';
    if (uVar8 != 0) {
      iVar6 = 0;
      iVar7 = iVar9;
      do {
        iVar6 = iVar6 + 1;
        if (*(int *)(iVar7 + 0x28) == 0) {
          bVar2 = false;
        }
        iVar7 = iVar7 + 0x594;
      } while (iVar6 < (int)uVar8);
    }
    if (!bVar2) goto LAB_40af6a60;
    if (uVar8 == 0) goto LAB_40af6a58;
    bVar2 = true;
    iVar7 = 0;
    do {
      iVar7 = iVar7 + 1;
      if (*(int *)(iVar9 + 0x34) != 0) {
        bVar2 = false;
      }
      iVar9 = iVar9 + 0x594;
    } while (iVar7 < (int)uVar8);
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if (iVar10 < 3) goto LAB_40af6a68;
LAB_40af69b0:
    if (*(int *)(param_1 + 0x164) == 0) {
      if (param_2 == 0) {
        if (uVar8 != 0) {
          iVar10 = *(int *)(param_1 + 0x134);
          if (*(int *)(param_1 + 0x1a4) == 0) {
            iVar7 = 0;
            iVar9 = 0;
            if (*(int *)(param_1 + 0x1a8) == 0) {
              do {
                iVar7 = iVar7 + 1;
                iVar6 = (int)**(short **)(*(int *)(iVar10 + 200) + 8);
                iVar10 = iVar10 + 0x594;
                if (iVar9 < iVar6) {
                  iVar9 = iVar6;
                }
              } while (iVar7 < (int)uVar8);
LAB_40af6b68:
              iVar10 = *(int *)(param_1 + 0x1b8);
            }
            else {
              do {
                iVar6 = (int)**(short **)(*(int *)(iVar10 + 200) + 8) <<
                        (*(uint *)(param_1 + 0x1b0) & 0x1f);
                if (iVar9 < iVar6) {
                  iVar9 = iVar6;
                }
                if ((int)uVar8 <= iVar7 + 1) goto LAB_40af6b68;
                iVar7 = iVar7 + 2;
                iVar6 = (int)**(short **)(*(int *)(iVar10 + 0x65c) + 8) <<
                        (*(uint *)(param_1 + 0x1b0) & 0x1f);
                if (iVar9 < iVar6) {
                  iVar9 = iVar6;
                }
                iVar10 = iVar10 + 0xb28;
              } while (iVar7 < (int)uVar8);
              iVar10 = *(int *)(param_1 + 0x1b8);
            }
          }
          else {
            iVar7 = 0;
            iVar9 = 0;
            do {
              piVar1 = (int *)(iVar10 + 200);
              iVar7 = iVar7 + 1;
              iVar10 = iVar10 + 0x594;
              iVar6 = (int)**(short **)(*piVar1 + 8) >> (*(uint *)(param_1 + 0x1b0) & 0x1f);
              if (iVar9 < iVar6) {
                iVar9 = iVar6;
              }
            } while (iVar7 < (int)uVar8);
            iVar10 = *(int *)(param_1 + 0x1b8);
          }
LAB_40af6b6c:
          iVar7 = 0;
          iVar6 = *(int *)(param_1 + 0x158);
          while( true ) {
            iVar4 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(int *)(iVar6 + iVar4) = (iVar9 + iVar10) / 2;
            if ((int)uVar8 <= iVar7) break;
            iVar10 = *(int *)(param_1 + 0x1b8);
          }
          iVar10 = *(int *)(param_1 + 0x48);
          goto LAB_40af6a34;
        }
      }
      else {
        iVar10 = *(int *)(param_1 + 0x1b8);
        if (uVar8 != 0) {
          iVar9 = -iVar10;
          goto LAB_40af6b6c;
        }
      }
    }
    else if (uVar8 != 0) {
      iVar9 = *(int *)(param_1 + 0x158);
      iVar10 = 0;
      do {
        while (*(int *)(param_1 + 0x1a4) != 0) {
          uVar5 = *(uint *)(param_1 + 0x168) >> (*(uint *)(param_1 + 0x1b0) & 0x1f);
LAB_40af69dc:
          iVar7 = iVar10 * 4;
          iVar10 = iVar10 + 1;
          *(uint *)(iVar9 + iVar7) = uVar5;
          if ((int)uVar8 <= iVar10) goto LAB_40af6a30;
        }
        if (*(int *)(param_1 + 0x1a8) == 0) {
          uVar5 = *(uint *)(param_1 + 0x168);
          goto LAB_40af69dc;
        }
        iVar7 = iVar10 * 4;
        iVar10 = iVar10 + 1;
        *(int *)(iVar9 + iVar7) = *(int *)(param_1 + 0x168) << (*(uint *)(param_1 + 0x1b0) & 0x1f);
      } while (iVar10 < (int)uVar8);
    }
  }
  else {
    uVar8 = (uint)*(ushort *)(param_1 + 0x58);
LAB_40af6a58:
    bVar2 = true;
LAB_40af6a60:
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if (2 < iVar10) goto LAB_40af69b0;
LAB_40af6a68:
    if (bVar2) {
      iVar10 = *(int *)(param_1 + 0x1b4);
    }
    else {
      psVar3 = *(short **)(*(int *)(*(int *)(param_1 + 0x134) + 200) + 8);
      iVar9 = (int)*psVar3;
      iVar10 = (int)psVar3[-1];
      if (*(int *)(param_1 + 0x1a4) == 0) {
        bVar2 = iVar10 < iVar9;
        if (*(int *)(param_1 + 0x1a8) != 0) {
          iVar9 = (int)(short)(iVar9 << (*(uint *)(param_1 + 0x1b0) & 0x1f));
          iVar10 = (int)(short)(iVar10 << (*(uint *)(param_1 + 0x1b0) & 0x1f));
          goto LAB_40af6a98;
        }
      }
      else {
        iVar10 = iVar10 >> (*(uint *)(param_1 + 0x1b0) & 0x1f);
        iVar9 = iVar9 >> (*(uint *)(param_1 + 0x1b0) & 0x1f);
LAB_40af6a98:
        bVar2 = iVar10 < iVar9;
      }
      if (bVar2) {
        iVar7 = (int)(short)((iVar9 - iVar10) / 2);
        iVar10 = (int)(short)((iVar9 + iVar10) / 2);
      }
      else {
        iVar7 = 0;
        iVar10 = iVar9;
      }
      if ((*(int *)(param_1 + 0x84) == 1) && (*(int *)(param_1 + 0x8c) == 0)) {
        iVar10 = (int)(short)((iVar10 + iVar7) / 2);
      }
      iVar10 = (*(int *)(param_1 + 0x1b8) / 2 - iVar9 / 2) + iVar10;
      *(undefined4 *)(param_1 + 0x4c) = 1;
    }
    iVar9 = 0;
    if (uVar8 != 0) {
      iVar7 = *(int *)(param_1 + 0x158);
      do {
        iVar6 = iVar9 * 4;
        iVar9 = iVar9 + 1;
        *(int *)(iVar7 + iVar6) = iVar10;
      } while (iVar9 < (int)uVar8);
      iVar10 = *(int *)(param_1 + 0x48);
      goto LAB_40af6a34;
    }
  }
LAB_40af6a30:
  iVar10 = *(int *)(param_1 + 0x48);
LAB_40af6a34:
  if (iVar10 != 3) {
    return;
  }
  *(undefined4 *)(param_1 + 0x48) = 1;
  return;
}



/* 40af6cec FUN_40af6cec */

undefined4 FUN_40af6cec(uint param_1)

{
  if (param_1 < 9) {
    return *(undefined4 *)(&DAT_40b139f0 + param_1 * 4);
  }
  return 0;
}



/* 40af6e70 FUN_40af6e70 */

undefined4 FUN_40af6e70(int param_1)

{
  if ((((*(ushort *)(param_1 + 2) != 0) && (*(ushort *)(param_1 + 2) < 0x21)) &&
      (*(uint *)(param_1 + 4) != 0)) &&
     ((*(uint *)(param_1 + 4) < 0x5dc01 && (*(short *)(param_1 + 0xc) != 0)))) {
    return 1;
  }
  return 0;
}



/* 40af716c FUN_40af716c */

void FUN_40af716c(undefined4 *param_1,undefined4 param_2)

{
  param_1[0xd] = 0xf;
  param_1[0xe] = param_2;
  param_1[0xf] = 1;
  param_1[0x10] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  return;
}



/* 40af71b4 FUN_40af71b4 */

void FUN_40af71b4(int param_1)

{
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



/* 40af7430 FUN_40af7430 */

undefined4 FUN_40af7430(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = *(uint *)(param_1 + 0x28);
  iVar4 = *(int *)(param_1 + 0x20);
  iVar6 = *(int *)(param_1 + 0x30);
  uVar1 = 0;
  if (uVar5 + iVar6 + iVar4 * 8 < param_2) {
    if ((uVar5 < 0x19) && (0 < iVar4)) {
      uVar2 = *(uint *)(param_1 + 0x24);
      pbVar3 = *(byte **)(param_1 + 0x1c);
      do {
        *(uint *)(param_1 + 0x24) = uVar2 << 8;
        uVar5 = uVar5 + 8;
        uVar2 = (uint)*pbVar3 | uVar2 << 8;
        iVar4 = iVar4 + -1;
        pbVar3 = pbVar3 + 1;
        *(uint *)(param_1 + 0x24) = uVar2;
        *(byte **)(param_1 + 0x1c) = pbVar3;
        *(int *)(param_1 + 0x20) = iVar4;
        *(uint *)(param_1 + 0x28) = uVar5;
        if (0x18 < uVar5) break;
      } while (0 < iVar4);
    }
    *(undefined4 *)(param_1 + 0x2c) = 0;
    if (0 < iVar4) {
      pbVar3 = *(byte **)(param_1 + 0x1c);
      uVar5 = 0;
      do {
        *(uint *)(param_1 + 0x2c) = uVar5 << 8;
        iVar4 = iVar4 + -1;
        uVar5 = (uint)*pbVar3 | uVar5 << 8;
        pbVar3 = pbVar3 + 1;
        iVar6 = iVar6 + 8;
        *(uint *)(param_1 + 0x2c) = uVar5;
        *(byte **)(param_1 + 0x1c) = pbVar3;
        *(int *)(param_1 + 0x20) = iVar4;
        *(int *)(param_1 + 0x30) = iVar6;
      } while (0 < iVar4);
    }
    uVar1 = 0x80040004;
  }
  return uVar1;
}



/* 40af75e4 FUN_40af75e4 */

undefined4 FUN_40af75e4(int param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(param_1 + 0x28);
  if (uVar6 < param_2) {
    uVar4 = *(uint *)(param_1 + 0x30);
    if (uVar4 != 0) {
      uVar2 = 0x20 - uVar6;
      if (uVar4 < 0x20 - uVar6) {
        uVar2 = uVar4;
      }
      uVar4 = uVar4 - uVar2;
      uVar6 = uVar2 + uVar6;
      *(uint *)(param_1 + 0x24) =
           *(int *)(param_1 + 0x24) << (uVar2 & 0x1f) | *(uint *)(param_1 + 0x2c) >> (uVar4 & 0x1f);
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & (1 << (uVar4 & 0x1f)) - 1U;
      *(uint *)(param_1 + 0x30) = uVar4;
      *(uint *)(param_1 + 0x28) = uVar6;
    }
    bVar1 = uVar6 < param_2;
    if ((uVar6 < 0x19) && (iVar5 = *(int *)(param_1 + 0x20), 0 < iVar5)) {
      uVar4 = *(uint *)(param_1 + 0x28);
      uVar6 = *(uint *)(param_1 + 0x24);
      pbVar3 = *(byte **)(param_1 + 0x1c);
      do {
        *(uint *)(param_1 + 0x24) = uVar6 << 8;
        uVar4 = uVar4 + 8;
        uVar6 = (uint)*pbVar3 | uVar6 << 8;
        iVar5 = iVar5 + -1;
        pbVar3 = pbVar3 + 1;
        *(uint *)(param_1 + 0x24) = uVar6;
        *(byte **)(param_1 + 0x1c) = pbVar3;
        *(int *)(param_1 + 0x20) = iVar5;
        *(uint *)(param_1 + 0x28) = uVar4;
        if (0x18 < uVar4) {
          bVar1 = uVar4 < param_2;
          break;
        }
        bVar1 = uVar4 < param_2;
      } while (0 < iVar5);
    }
    if (bVar1) {
      return 0x80040004;
    }
    uVar6 = *(uint *)(param_1 + 0x28);
  }
  *(uint *)(param_1 + 0x28) = uVar6 - param_2;
  return 0;
}



/* 40af76f8 FUN_40af76f8 */

undefined4 FUN_40af76f8(int param_1,uint param_2,int param_3)

{
  if (param_3 != 0) {
    if (((param_2 ^ *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x28)) & 7) == 0) {
      *(int *)(param_1 + 0x40) = param_3;
      *(uint *)(param_1 + 0x44) = param_2;
    }
    return 0;
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  return 0;
}



/* 40af774c FUN_40af774c */

undefined4 FUN_40af774c(int param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(param_1 + 0x28);
  if (uVar6 < param_2) {
    uVar4 = *(uint *)(param_1 + 0x30);
    if (uVar4 != 0) {
      uVar2 = 0x20 - uVar6;
      if (uVar4 < 0x20 - uVar6) {
        uVar2 = uVar4;
      }
      uVar4 = uVar4 - uVar2;
      uVar6 = uVar2 + uVar6;
      *(uint *)(param_1 + 0x24) =
           *(int *)(param_1 + 0x24) << (uVar2 & 0x1f) | *(uint *)(param_1 + 0x2c) >> (uVar4 & 0x1f);
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & (1 << (uVar4 & 0x1f)) - 1U;
      *(uint *)(param_1 + 0x30) = uVar4;
      *(uint *)(param_1 + 0x28) = uVar6;
    }
    bVar1 = uVar6 < param_2;
    if ((uVar6 < 0x19) && (iVar5 = *(int *)(param_1 + 0x20), 0 < iVar5)) {
      uVar4 = *(uint *)(param_1 + 0x28);
      uVar6 = *(uint *)(param_1 + 0x24);
      pbVar3 = *(byte **)(param_1 + 0x1c);
      do {
        *(uint *)(param_1 + 0x24) = uVar6 << 8;
        uVar4 = uVar4 + 8;
        uVar6 = (uint)*pbVar3 | uVar6 << 8;
        iVar5 = iVar5 + -1;
        pbVar3 = pbVar3 + 1;
        *(uint *)(param_1 + 0x24) = uVar6;
        *(byte **)(param_1 + 0x1c) = pbVar3;
        *(int *)(param_1 + 0x20) = iVar5;
        *(uint *)(param_1 + 0x28) = uVar4;
        if (0x18 < uVar4) {
          bVar1 = uVar4 < param_2;
          break;
        }
        bVar1 = uVar4 < param_2;
      } while (0 < iVar5);
    }
    if (bVar1) {
      return 0x80040004;
    }
    uVar6 = *(uint *)(param_1 + 0x28);
  }
  uVar4 = *(uint *)(&DAT_40b13a14 + param_2 * 4);
  *(uint *)(param_1 + 0x28) = uVar6 - param_2;
  *param_3 = *(uint *)(param_1 + 0x24) >> (uVar6 - param_2 & 0x1f) & uVar4;
  return 0;
}



/* 40af7888 FUN_40af7888 */

void FUN_40af7888(int param_1)

{
  *(undefined4 *)(param_1 + 0x3c) = 1;
  return;
}



/* 40af7894 FUN_40af7894 */

undefined4 FUN_40af7894(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



/* 40af78c4 FUN_40af78c4 */

void FUN_40af78c4(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}



/* 40af78cc FUN_40af78cc */

undefined4 FUN_40af78cc(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* 40af78d4 FUN_40af78d4 */

void FUN_40af78d4(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}



/* 40af78dc FUN_40af78dc */

undefined4 FUN_40af78dc(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* 40af78e4 FUN_40af78e4 */

void FUN_40af78e4(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}



/* 40af78ec FUN_40af78ec */

void FUN_40af78ec(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x34) = param_2;
  return;
}



/* 40af78f4 FUN_40af78f4 */

void FUN_40af78f4(int param_1)

{
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffff8;
  return;
}



/* 40af7918 FUN_40af7918 */

/* Boundary evidence: original MIPS .pdata 40af7918..40af79a7. Semantic name remains unreviewed. */

void FUN_40af7918(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  uVar2 = FUN_40aef3d4(*(int **)(param_1 + 8));
  uVar3 = uVar2 >> 3 & 0xff;
  iVar5 = *(int *)(param_1 + 0x18) - uVar3;
  pbVar4 = (byte *)(*(int *)(param_1 + 0x14) + uVar3);
  *(byte **)(param_1 + 0x1c) = pbVar4;
  *(int *)(param_1 + 0x20) = iVar5;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  bVar1 = *pbVar4;
  uVar2 = uVar2 & 7;
  *(uint *)(param_1 + 0x28) = 8 - uVar2;
  *(byte **)(param_1 + 0x1c) = pbVar4 + 1;
  *(int *)(param_1 + 0x20) = iVar5 + -1;
  *(uint *)(param_1 + 0x24) = (int)((uint)bVar1 << uVar2 & 0xff) >> uVar2 & 0xff;
  return;
}



/* 40af79a8 FUN_40af79a8 */

/* Boundary evidence: original MIPS .pdata 40af79a8..40af7c63. Semantic name remains unreviewed. */

undefined4 FUN_40af79a8(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(int *)(param_1 + 0x20) = param_3;
  if (param_3 != 0) {
    if (param_4 != 0) {
      *(undefined4 *)(param_1 + 0x14) = param_2;
      *(int *)(param_1 + 0x18) = param_3;
    }
    if (*(int *)(param_1 + 0x38) == 0) {
      if (param_4 != 0) {
        *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1U & 0x3ff;
      }
    }
    else if (param_4 != 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x10);
      pbVar2 = *(byte **)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = uVar5;
      *(uint *)(param_1 + 0x10) =
           (uint)pbVar2[3] | (uint)*pbVar2 << 0x18 | (uint)pbVar2[1] << 0x10 | (uint)pbVar2[2] << 8;
      uVar3 = FUN_40aef3d4(*(int **)(param_1 + 8));
      uVar7 = *(uint *)(param_1 + 0x10);
      uVar4 = uVar3 >> 3 & 0xff;
      *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - uVar4;
      *(uint *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + uVar4;
      iVar6 = *(int *)(param_1 + 0x34);
      *(uint *)(param_1 + 0x34) = uVar7 >> 0x1c;
      if (*(int *)(param_1 + 0x3c) == 0) {
        if (param_5 < 3) {
          uVar4 = 0;
        }
        else {
          uVar4 = uVar7 >> 0x1a & 1;
        }
        iVar6 = (uVar7 >> 0x1c) - iVar6;
        if (((iVar6 != 1) && (iVar6 != -0xf)) || (uVar4 != 0)) {
          *(uint *)(param_1 + 0x28) = 0x20 - uVar3;
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x14) + 4;
          *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x18) + -4;
          *(uint *)(param_1 + 0x24) = uVar7;
          FUN_40aef3cc(*(int *)(param_1 + 8),1);
          return 6;
        }
        FUN_40aef3cc(*(int *)(param_1 + 8),0);
      }
      else {
        *(undefined4 *)(param_1 + 0x3c) = 0;
      }
      uVar3 = uVar3 & 7;
      if (uVar3 != 0) {
        if ((*(int *)(param_1 + 0x30) != 0) ||
           (iVar6 = *(int *)(param_1 + 0x28), 0x20 < (iVar6 + 8) - uVar3)) {
          bVar1 = **(byte **)(param_1 + 0x1c);
          *(uint *)(param_1 + 0x30) = (*(int *)(param_1 + 0x30) + 8) - uVar3;
          *(byte **)(param_1 + 0x1c) = *(byte **)(param_1 + 0x1c) + 1;
          *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
          *(uint *)(param_1 + 0x2c) =
               (int)((uint)bVar1 << uVar3 & 0xff) >> uVar3 & 0xffU |
               *(int *)(param_1 + 0x2c) << (8 - uVar3 & 0x1f);
          return 0;
        }
        iVar8 = *(int *)(param_1 + 0x20);
        if (0 < iVar8) {
          pbVar2 = *(byte **)(param_1 + 0x1c);
          uVar4 = *(uint *)(param_1 + 0x24);
          do {
            iVar6 = (iVar6 + 8) - uVar3;
            uVar4 = (int)((uint)*pbVar2 << uVar3 & 0xff) >> uVar3 & 0xffU |
                    uVar4 << (8 - uVar3 & 0x1f);
            pbVar2 = pbVar2 + 1;
            iVar8 = iVar8 + -1;
            uVar3 = 0;
            *(byte **)(param_1 + 0x1c) = pbVar2;
            *(int *)(param_1 + 0x20) = iVar8;
            *(uint *)(param_1 + 0x24) = uVar4;
            *(int *)(param_1 + 0x28) = iVar6;
            if (iVar8 < 1) {
              return 0;
            }
          } while (iVar6 + 8U < 0x21);
        }
      }
    }
  }
  return 0;
}



/* 40af7ca8 FUN_40af7ca8 */

void FUN_40af7ca8(int param_1)

{
  *(undefined4 *)(param_1 + 0x124) = 0;
  return;
}



/* 40af7cb0 FUN_40af7cb0 */

/* Boundary evidence: original MIPS .pdata 40af7cb0..40af7cdf. Semantic name remains unreviewed. */

undefined4 FUN_40af7cb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  size_t sVar1;
  
  sVar1 = FUN_40aff968(s_WMAFileCBGetData_not_implemented_40b1710c);
  FUN_40aff918(sVar1,param_2,param_3,param_4);
  return 0;
}



/* 40af7ce0 FUN_40af7ce0 */

/* Boundary evidence: original MIPS .pdata 40af7ce0..40af7d13. Semantic name remains unreviewed. */

void FUN_40af7ce0(int param_1)

{
  if (*(int *)(param_1 + 0x120) != 0) {
    FUN_40af9db4((int *)(param_1 + 0x118));
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  return;
}



/* 40af7d14 FUN_40af7d14 */

/* Boundary evidence: original MIPS .pdata 40af7d14..40af7ee3. Semantic name remains unreviewed. */

undefined4
FUN_40af7d14(undefined4 *param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4,
            int param_5)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short local_40 [6];
  undefined *local_34;
  undefined *local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  
  if (*(int *)(param_5 + 0x120) != 0) {
    FUN_40af9db4((int *)(param_5 + 0x118));
    *(undefined4 *)(param_5 + 0x120) = 0;
  }
  if (param_2 == (undefined2 *)0x0) {
    *(undefined4 *)(param_5 + 0x8128) = 1;
  }
  else {
    *(undefined4 *)(param_5 + 0x8128) = 0;
  }
  *(undefined4 *)(param_5 + 0x124) = 0;
  memset((void *)(param_5 + 0x48),0,0xd0);
  *(int *)(param_5 + 0x118) = 0;
  memset((uint *)(param_5 + 4),0,0x44);
  iVar2 = FUN_40af9f10((int *)(param_5 + 0x118));
  if (iVar2 == 0) {
    if (param_2 == (undefined2 *)0x0) {
      iVar2 = FUN_40af9afc(*(uint **)(param_5 + 0x118),0);
    }
    else {
      iVar2 = FUN_40af8884(*(undefined4 **)(param_5 + 0x118),param_2,param_3,0);
    }
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iVar2 = FUN_40af941c(*(int *)(param_5 + 0x118),(uint *)(param_5 + 4));
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    local_34 = &DAT_40b19b60;
    local_30 = &DAT_40b19360;
    local_2c = &DAT_40b18b60;
    local_28 = &DAT_40b18360;
    local_24 = &DAT_40b17b60;
    local_40[4] = 0x800;
    local_40[5] = 0;
    local_40[0] = 0x800;
    local_40[1] = 0x800;
    local_40[2] = 0x800;
    local_40[3] = 0x800;
    iVar2 = FUN_40af92fc(*(int *)(param_5 + 0x118),local_40);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iVar2 = FUN_40af8380(*(int *)(param_5 + 0x118),(int *)0x0);
    if (iVar2 == 0) {
      uVar3 = *(undefined4 *)(param_5 + 8);
      uVar4 = *(undefined4 *)(param_5 + 0xc);
      sVar1 = *(short *)(param_5 + 0x2e);
      *(undefined4 *)(param_5 + 0x11c) = uVar3;
      param_1[2] = 0x4000;
      param_1[1] = uVar4;
      *param_1 = uVar3;
      param_1[3] = (int)sVar1;
      *(undefined4 *)(param_5 + 0x120) = 1;
      return 0;
    }
  }
  return 0xffffffff;
}



/* 40af7ee4 FUN_40af7ee4 */

/* Boundary evidence: original MIPS .pdata 40af7ee4..40af8083. Semantic name remains unreviewed. */

undefined4
FUN_40af7ee4(undefined4 *param_1,int *param_2,int *param_3,va_list param_4,int param_5,
            undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  size_t sVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  va_list pcVar11;
  uint uVar12;
  uint local_30 [2];
  int local_28 [3];
  
  if (param_6[0x48] == 0) {
    piVar9 = param_2;
    piVar10 = param_3;
    pcVar11 = param_4;
    sVar4 = FUN_40aff968(s_wma9stddecode_try_to_re_init_40b17130);
    FUN_40aff918(sVar4,piVar9,piVar10,pcVar11);
    FUN_40af7d14(param_1,(undefined2 *)0x0,0,3,(int)param_6);
    puVar6 = (uint *)param_6[0x46];
  }
  else {
    puVar6 = (uint *)param_6[0x46];
  }
  iVar1 = FUN_40af86a8(puVar6,local_30,param_4,param_5);
  if (iVar1 == 0) {
    uVar12 = 0;
    do {
      local_28[0] = 0;
      local_28[1] = 0;
      uVar2 = FUN_40af94f4(param_6[0x46],(int *)*param_6,(undefined2 *)0x0,0x4000,
                           local_30[0] - uVar12,local_28);
      if (uVar2 == 0) break;
      iVar8 = param_6[3];
      iVar1 = *(short *)((int)param_6 + 0x2e) * iVar8;
      uVar5 = uVar2 * iVar1 >> 3;
      uVar3 = uVar12 * iVar1 >> 3;
      if (0x8000 < uVar5 + uVar3) goto LAB_40af7fd8;
      uVar12 = uVar12 + uVar2;
      FUN_40afcef8((int *)((int)param_6 + uVar3 + 0x128),(int *)*param_6,uVar5);
    } while (uVar12 < local_30[0]);
    iVar8 = param_6[3];
LAB_40af7fd8:
    *param_3 = (uVar12 * iVar8 & 0xfffffff) << 1;
    iVar1 = param_6[0x49];
    *param_2 = (int)(param_6 + 0x4a);
    param_6[0x49] = iVar1 + 1;
    uVar7 = 0;
  }
  else if (iVar1 == 6) {
    uVar7 = 0xfffffffd;
  }
  else {
    uVar7 = 0xffffffff;
    if (iVar1 == 1) {
      uVar7 = 0xfffffffe;
    }
  }
  return uVar7;
}



/* 40af80d0 FUN_40af80d0 */

void FUN_40af80d0(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  uVar1 = *(ushort *)(param_1 + 2);
  uVar2 = *(ushort *)(param_1 + 0xe);
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = (uint)uVar1;
  uVar3 = *(undefined4 *)(param_1 + 0x10);
  param_2[4] = (int)(uVar2 + 7) >> 3;
  param_2[2] = uVar3;
  param_2[3] = (uint)uVar2;
  return;
}



/* 40af8100 FUN_40af8100 */

/* Boundary evidence: original MIPS .pdata 40af8100..40af81bb. Semantic name remains unreviewed. */

bool FUN_40af8100(short *param_1,uint param_2)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  sVar1 = *param_1;
  if (sVar1 == 0x160) {
    uVar4 = 0x18;
  }
  else if (sVar1 == 0x161) {
    uVar4 = 0x1e;
  }
  else {
    uVar4 = 0xffffffff;
    if ((ushort)(sVar1 - 0x162U) < 2) {
      uVar4 = 0x26;
    }
  }
  if ((((param_2 < 0x14) || (0x400 < param_2)) || (iVar3 = FUN_40af6e70((int)param_1), iVar3 == 0))
     || ((bVar2 = false, uVar4 != 0xffffffff &&
         (bVar2 = uVar4 <= param_2, (ushort)param_1[8] + 0x14 < uVar4)))) {
    bVar2 = false;
  }
  return bVar2;
}



/* 40af81bc FUN_40af81bc */

/* Boundary evidence: original MIPS .pdata 40af81bc..40af82af. Semantic name remains unreviewed. */

void FUN_40af81bc(short *param_1,short *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  short sVar3;
  short sVar4;
  undefined4 uVar5;
  
  sVar3 = *param_1;
  uVar5 = *(undefined4 *)(param_1 + 2);
  *param_2 = sVar3;
  sVar4 = param_1[1];
  *(undefined4 *)(param_2 + 2) = uVar5;
  uVar5 = *(undefined4 *)(param_1 + 4);
  param_2[1] = sVar4;
  sVar4 = param_1[6];
  *(undefined4 *)(param_2 + 4) = uVar5;
  param_2[6] = sVar4;
  if (sVar3 == 0x160) {
    uVar2 = *(undefined1 *)((int)param_1 + 0x17);
    uVar1 = (undefined1)param_1[0xb];
  }
  else {
    if (sVar3 != 0x161) {
      if (1 < (ushort)(sVar3 - 0x162U)) {
        return;
      }
      param_2[10] = param_1[0x11];
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0xb);
      param_2[7] = param_1[10];
      return;
    }
    uVar2 = *(undefined1 *)((int)param_1 + 0x19);
    uVar1 = (undefined1)param_1[0xc];
  }
  param_2[10] = CONCAT11(uVar2,uVar1);
  uVar5 = FUN_40af6cec((uint)(ushort)param_2[1]);
  param_2[7] = 0x10;
  *(undefined4 *)(param_2 + 8) = uVar5;
  return;
}



/* 40af8380 FUN_40af8380 */

undefined4 FUN_40af8380(int param_1,int *param_2)

{
  if (param_1 == 0) {
    return 2;
  }
  if (param_2 != (int *)0x0) {
    if (*(int *)(param_1 + 0xb8) != 0) {
      *param_2 = *(int *)(param_1 + 0xb8);
      return 0;
    }
    *param_2 = 0;
  }
  return 0;
}



/* 40af8478 FUN_40af8478 */

/* Boundary evidence: original MIPS .pdata 40af8478..40af86a7. Semantic name remains unreviewed. */

undefined4 FUN_40af8478(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
LAB_40af84c4:
  switch(param_1[0x34]) {
  case 3:
    uVar2 = param_1[1];
    if (param_1[9] < uVar2) {
      return 6;
    }
    *param_1 = uVar2;
    param_1[1] = uVar2 + param_1[3];
    iVar1 = FUN_40afa410((int *)param_1);
    if (iVar1 == 3) {
      param_1[1] = *param_1;
      return 0x12;
    }
    if (iVar1 != 0) {
      return 4;
    }
    if ((param_1[0x3b] == 0) || (param_1[0x39] == 0)) {
      param_1[0x34] = 4;
      param_1[0x56] = 0;
    }
    goto LAB_40af84c4;
  case 4:
    if (param_1[0x4a] <= param_1[0x56]) {
      param_1[0x34] = 3;
      goto LAB_40af84c4;
    }
    iVar1 = FUN_40af9fd8((int *)param_1);
    if (iVar1 == 0) {
      *(short *)(param_1 + 0x57) =
           (*(short *)((int)param_1 + 0x12e) + (short)param_1[0x4b]) -
           *(short *)((int)param_1 + 0x142);
      if ((char)param_1[0x50] == '\x01') {
        param_1[0x34] = 8;
        *(undefined1 *)((int)param_1 + 0x149) = 1;
      }
      else {
        param_1[0x34] = 5;
        *(undefined1 *)((int)param_1 + 0x149) = 0;
      }
      goto LAB_40af84c4;
    }
    break;
  case 5:
    if ((ushort)(byte)param_1[0x4c] == (ushort)param_1[0x33]) {
      uVar2 = param_1[0x58];
      param_1[0x35] = (uint)(ushort)param_1[0x57] + *param_1;
      param_1[0x37] = 1;
      param_1[0x36] = (uint)*(ushort *)((int)param_1 + 0x142) - param_1[0xd];
      param_1[0x38] = param_1[0xd];
joined_r0x40af8670:
      if (uVar2 != 0) {
        return 0xe;
      }
      param_1[0x34] = 6;
      return 0;
    }
    break;
  default:
    return 0x11;
  case 7:
    goto switchD_40af8514_caseD_7;
  case 8:
    if ((ushort)(byte)param_1[0x4c] == (ushort)param_1[0x33]) {
      uVar2 = param_1[0x58];
      param_1[0x35] = (uint)(ushort)param_1[0x57] + *param_1;
      param_1[0x38] = param_1[0xd];
      *(undefined1 *)(param_1 + 0x52) = 1;
      param_1[0x37] = 1;
      *(undefined2 *)(param_1 + 0x51) = 0;
      goto joined_r0x40af8670;
    }
  }
  param_1[0x34] = 7;
  goto LAB_40af84c4;
switchD_40af8514_caseD_7:
  param_1[0x34] = 4;
  param_1[0x56] = param_1[0x56] + 1;
  goto LAB_40af84c4;
}



/* 40af86a8 FUN_40af86a8 */

/* WARNING: Removing unreachable block (ram,0x40af8874) */
/* Boundary evidence: original MIPS .pdata 40af86a8..40af8883. Semantic name remains unreviewed. */

undefined4 FUN_40af86a8(uint *param_1,uint *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  size_t sVar2;
  uint uVar3;
  int *piVar4;
  va_list pcVar5;
  int iVar6;
  
  iVar6 = 0;
  if ((param_1 == (uint *)0x0) || (piVar4 = (int *)param_1[0x5a], piVar4 == (int *)0x0)) {
    return 2;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = 0;
  }
  if (param_1[0x34] == 6) {
    uVar3 = param_1[0x5b];
    if (uVar3 == 1) {
      param_1[0x37] = 1;
      if (param_4 == 0) {
        return 6;
      }
      pcVar5 = (va_list)0x1;
      *(int *)(*piVar4 + 0x2dc) = *(int *)(*piVar4 + 0x2dc) + 1;
      iVar6 = FUN_40aed8ec(piVar4,param_3,param_4,1,0,0,0,0,(int *)(param_1 + 0x5b),(uint *)0x0);
      if (iVar6 < 0) {
        sVar2 = FUN_40aff968(s_audecInput_failed__x_40b17150);
        FUN_40aff918(sVar2,iVar6,param_4,pcVar5);
        param_1[0x34] = 7;
        return 1;
      }
    }
    else if (uVar3 == 0) {
      iVar6 = 6;
    }
    else if ((uVar3 == 2) &&
            (iVar6 = FUN_40aee03c(piVar4,param_2,(int *)(param_1 + 0x5b)), iVar6 < 0)) {
      printf(s_audecDecode_failed__x__40b17168,iVar6);
      param_1[0x34] = 7;
      return 1;
    }
    if ((iVar6 != 5) && (param_1[0x5b] != 0)) {
      return 0;
    }
    return 6;
  }
  uVar1 = FUN_40af8478(param_1);
  return uVar1;
}



/* 40af8884 FUN_40af8884 */

/* Boundary evidence: original MIPS .pdata 40af8884..40af8b27. Semantic name remains unreviewed. */

undefined4 FUN_40af8884(undefined4 *param_1,undefined2 *param_2,undefined4 param_3,ushort param_4)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  ushort local_68;
  undefined2 local_66;
  uint local_64;
  undefined4 local_60;
  undefined2 local_5c;
  ushort local_5a;
  undefined4 local_58;
  undefined2 local_54;
  uint local_50 [3];
  uint local_44;
  uint local_40;
  uint local_38 [8];
  
  if (param_1 == (undefined4 *)0x0) {
    return 2;
  }
  iVar3 = *(int *)(param_2 + 3);
  param_1[0xb] = iVar3;
  *(undefined2 *)(param_1 + 0x11) = param_2[8];
  *(undefined2 *)((int)param_1 + 0x46) = param_2[8];
  *(undefined2 *)(param_1 + 0xe) = param_2[2];
  uVar1 = param_2[7];
  param_1[0xd] = (uint)uVar1;
  iVar4 = *(int *)(param_2 + 5);
  param_1[0xc] = iVar4;
  *(undefined2 *)((int)param_1 + 0x2a) = *param_2;
  param_1[0xf] = *(undefined4 *)(param_2 + 10);
  param_1[0x12] = *(undefined4 *)(param_2 + 0xe);
  *(short *)(param_1 + 0x10) = (short)*(undefined4 *)(param_2 + 0xc);
  if (iVar3 != 0) {
    if (*(short *)(param_1 + 0xe) == 0) {
      return 3;
    }
    if (uVar1 == 0) {
      return 3;
    }
    if (iVar4 != 0) {
      puVar2 = FUN_40aee5a0(0,0);
      param_1[0x5a] = puVar2;
      if (puVar2 != (undefined *)0x0) {
        local_5a = *(ushort *)((int)param_1 + 0x46);
        local_44 = (uint)local_5a;
        local_68 = *(ushort *)((int)param_1 + 0x2a);
        local_64 = param_1[0xb];
        local_66 = *(undefined2 *)(param_1 + 0xe);
        local_60 = param_1[0xc];
        local_58 = param_1[0x12];
        local_54 = *(undefined2 *)(param_1 + 0x10);
        local_40 = (uint)(*(ushort *)(param_1 + 0x11) >> 3);
        local_5c = (undefined2)param_1[0xd];
        local_38[0] = (uint)param_4;
        local_38[1] = 0;
        local_38[2] = 0;
        local_38[3] = 0;
        local_38[4] = 0;
        local_38[5] = 0;
        local_38[6] = 0;
        local_50[0] = local_64;
        FUN_40af80d0((int)&local_68,local_50);
        iVar3 = FUN_40aee6ac((int *)param_1[0x5a],&local_68,local_50,(ushort *)local_38,
                             param_1 + 0x5b,0);
        if (iVar3 == -0x7ffc0000) {
          return 7;
        }
        if (iVar3 == 0) {
          param_1[0x58] = 0;
          if (param_1[0x20] != 0) {
            if (*(char *)(param_1 + 0x21) != 'D') {
              return 0xc;
            }
            if (*(char *)((int)param_1 + 0x85) != 'R') {
              return 0xc;
            }
            if (*(char *)((int)param_1 + 0x86) != 'M') {
              return 0xc;
            }
            if (*(char *)((int)param_1 + 0x87) != '\0') {
              return 0xc;
            }
            param_1[0x58] = 1;
          }
          param_1[9] = param_1[8];
          if (param_1[5] != 0) {
            param_1[9] = (param_1[5] + -1) * param_1[3] + param_1[8];
          }
          param_1[0x5c] = &DAT_40b17a40;
          param_1[1] = param_1[2];
          *param_1 = param_1[2];
          param_1[0x34] = 6;
          return 0;
        }
      }
      return 1;
    }
  }
  return 3;
}



/* 40af8b28 FUN_40af8b28 */

/* Boundary evidence: original MIPS .pdata 40af8b28..40af90f3. Semantic name remains unreviewed. */

undefined4 FUN_40af8b28(uint *param_1,uint *param_2,uint *param_3,int param_4)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *local_30 [2];
  
  local_30[0] = (byte *)0x0;
  *(undefined4 *)(param_4 + 4) = 0;
  if (param_1 == (uint *)0x0) {
    if (param_2 == (uint *)0x0) goto LAB_40af8c48;
  }
  else {
    if (param_2 == (uint *)0x0) goto LAB_40af8c48;
    if (param_3 != (uint *)0x0) {
      *param_2 = 0;
      *param_3 = 0;
      if (*(char *)((int)param_1 + 0x149) == '\x01') {
LAB_40af8bd4:
LAB_40af8be4:
        do {
          bVar1 = (byte)param_1[0x52];
          if (bVar1 == 2) {
            uVar7 = param_1[0x38];
            if (uVar7 == 0) {
              if ((short)param_1[0x53] == 0) {
                *(undefined1 *)(param_1 + 0x52) = 3;
                goto LAB_40af8be4;
              }
              uVar7 = param_1[0xd];
              *(short *)(param_1 + 0x53) = (short)param_1[0x53] - (short)uVar7;
              param_1[0x37] = 1;
              param_1[0x38] = uVar7;
            }
            if (0x7f < uVar7) {
              uVar7 = 0x80;
            }
            uVar5 = FUN_40af7cb0(param_1,param_1[0x35],uVar7,(va_list)param_2);
            *param_3 = uVar5;
            if (uVar7 != uVar5) {
              return 0x80040005;
            }
            FUN_40afcef8((int *)param_1[0x5c],(int *)*param_2,uVar7);
            uVar7 = param_1[0x38];
            param_1[0x35] = param_1[0x35] + *param_3;
            uVar5 = *param_3;
            uVar6 = param_1[0x58];
            *param_2 = param_1[0x5c];
            param_1[0x38] = uVar7 - uVar5;
            if (uVar6 != 0) {
              return 3;
            }
            if (param_1[0x37] == 0) {
              return 0;
            }
            if ((uint)(ushort)param_1[0x53] == (uint)*(byte *)((int)param_1 + 0x14a) - param_1[0xd])
            {
              *(undefined4 *)(param_4 + 4) = 1;
              uVar7 = param_1[0x55];
              *(ushort *)(param_1 + 0x55) = (ushort)uVar7 + 1;
              *(ulonglong *)(param_4 + 8) =
                   (ulonglong)((uint)(ushort)uVar7 * param_1[0x54] + (param_1[0x4f] - param_1[7])) *
                   10000;
            }
            param_1[0x37] = 0;
            return 3;
          }
          if (bVar1 < 3) {
            if (bVar1 != 1) {
              return 3;
            }
            iVar4 = FUN_40af7cb0(param_1,param_1[0x35],1,(va_list)local_30);
            if (iVar4 != 1) {
              return 0x80040005;
            }
            if (local_30[0] == (byte *)0x0) {
              return 0x80040005;
            }
            param_1[0x35] = param_1[0x35] + 1;
            param_1[0x37] = 1;
            param_1[0x38] = param_1[0xd];
            *(undefined2 *)(param_1 + 0x55) = 0;
            bVar1 = *local_30[0];
            *(byte *)((int)param_1 + 0x14a) = bVar1;
            *(ushort *)(param_1 + 0x53) = (ushort)bVar1;
            if (bVar1 != 0) {
              *(ushort *)(param_1 + 0x53) = (ushort)bVar1 - (short)param_1[0xd];
            }
            uVar2 = *(ushort *)((int)param_1 + 0x146);
            bVar1 = *(byte *)((int)param_1 + 0x14a);
            if (bVar1 < uVar2) {
              *(ushort *)(param_1 + 0x51) = bVar1 + 1;
            }
            else if (uVar2 == bVar1) {
              *(ushort *)(param_1 + 0x51) = uVar2;
              *(undefined1 *)(param_1 + 0x52) = 2;
              goto LAB_40af8be4;
            }
            *(undefined1 *)(param_1 + 0x52) = 2;
            goto LAB_40af8be4;
          }
          if (bVar1 == 3) {
            if ((ushort)param_1[0x51] < *(ushort *)((int)param_1 + 0x146)) {
              iVar4 = FUN_40af7cb0(param_1,param_1[0x35],1,(va_list)local_30);
              if (iVar4 != 1) {
                return 0x80040005;
              }
              if (local_30[0] == (byte *)0x0) {
                return 0x80040005;
              }
              param_1[0x35] = param_1[0x35] + 1;
              param_1[0x37] = 1;
              param_1[0x38] = param_1[0xd];
              bVar1 = *local_30[0];
              *(byte *)((int)param_1 + 0x14a) = bVar1;
              *(ushort *)(param_1 + 0x53) = (ushort)bVar1;
              if (bVar1 != 0) {
                *(ushort *)(param_1 + 0x53) = (ushort)bVar1 - (short)param_1[0xd];
              }
              *(ushort *)(param_1 + 0x51) =
                   (short)param_1[0x51] + 1 + (ushort)*(byte *)((int)param_1 + 0x14a);
              *(undefined1 *)(param_1 + 0x52) = 2;
            }
            else {
              *(undefined1 *)(param_1 + 0x52) = 4;
            }
          }
          else {
            if (bVar1 != 4) {
              return 3;
            }
            uVar7 = param_1[0x34];
            *(undefined1 *)(param_1 + 0x52) = 0;
            param_1[0x36] = 0;
            *(undefined1 *)((int)param_1 + 0x149) = 0;
            param_1[0x34] = 7;
            iVar4 = FUN_40af8478(param_1);
            if (iVar4 == 0x12) goto LAB_40af8f0c;
            param_1[0x34] = uVar7;
            if (iVar4 != 0) {
              return 3;
            }
          }
        } while( true );
      }
      uVar7 = param_1[0x38];
      bVar3 = uVar7 < 0x80;
      if (uVar7 == 0) {
        uVar5 = param_1[0x36];
        if (uVar5 == 0) {
          uVar7 = param_1[0x34];
          param_1[0x34] = 7;
          iVar4 = FUN_40af8478(param_1);
          if (iVar4 == 0x12) {
LAB_40af8f0c:
            *param_3 = 0;
            return 0;
          }
          param_1[0x34] = uVar7;
          if (*(char *)((int)param_1 + 0x149) == '\x01') goto LAB_40af8bd4;
          if (iVar4 == 6) {
            *param_3 = 0;
            return 0x80040005;
          }
          if (iVar4 != 0) {
            return 3;
          }
          uVar7 = param_1[0x38];
          bVar3 = uVar7 < 0x80;
          if (uVar7 != 0) goto LAB_40af8cdc;
          uVar5 = param_1[0x36];
          if (uVar5 == 0) {
            return 3;
          }
        }
        uVar7 = param_1[0xd];
        param_1[0x36] = uVar5 - uVar7;
        param_1[0x37] = 1;
        param_1[0x38] = uVar7;
        bVar3 = uVar7 < 0x80;
      }
LAB_40af8cdc:
      if (!bVar3) {
        uVar7 = 0x80;
      }
      uVar5 = FUN_40af7cb0(param_1,param_1[0x35],uVar7,(va_list)param_2);
      *param_3 = uVar5;
      if (uVar7 != uVar5) {
        return 0x80040005;
      }
      FUN_40afcef8((int *)param_1[0x5c],(int *)*param_2,uVar7);
      uVar7 = param_1[0x38];
      param_1[0x35] = param_1[0x35] + *param_3;
      uVar5 = *param_3;
      uVar6 = param_1[0x58];
      *param_2 = param_1[0x5c];
      param_1[0x38] = uVar7 - uVar5;
      if (uVar6 != 0) {
        return 3;
      }
      if (param_1[0x37] == 0) {
        return 0;
      }
      param_1[0x37] = 0;
      if (param_1[0x36] == (uint)*(ushort *)((int)param_1 + 0x142) - param_1[0xd]) {
        *(undefined4 *)(param_4 + 4) = 1;
        *(ulonglong *)(param_4 + 8) = (ulonglong)(param_1[0x4f] - param_1[7]) * 10000;
        return 3;
      }
      return 3;
    }
  }
  *param_2 = 0;
LAB_40af8c48:
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  return 0x80070057;
}



/* 40af90f4 FUN_40af90f4 */

/* Boundary evidence: original MIPS .pdata 40af90f4..40af92fb. Semantic name remains unreviewed. */

int FUN_40af90f4(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_30;
  uint local_2c;
  undefined1 auStack_28 [4];
  int local_24;
  int local_20;
  int local_1c;
  
  iVar4 = 0;
  if ((param_1 == (uint *)0x0) || (piVar3 = (int *)param_1[0x5a], piVar3 == (int *)0x0)) {
    return 2;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = 0;
  }
  while (param_1[0x34] != 6) {
    iVar2 = FUN_40af8478(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    piVar3 = (int *)param_1[0x5a];
    if (*(int *)(*piVar3 + 0x2cc) == 1) {
      return 0;
    }
  }
  uVar1 = param_1[0x5b];
  if (uVar1 == 1) {
    local_30 = 0;
    local_2c = 0;
    iVar4 = FUN_40af8b28(param_1,&local_30,&local_2c,(int)auStack_28);
    iVar2 = 1;
    if ((iVar4 != -0x7ffbfffb) && (iVar2 = 0, iVar4 < 0)) {
      param_1[0x34] = 7;
      return iVar4;
    }
    if (iVar4 == 3) {
      piVar3 = (int *)param_1[0x5a];
      *(int *)(*piVar3 + 0x2dc) = *(int *)(*piVar3 + 0x2dc) + 1;
    }
    else {
      piVar3 = (int *)param_1[0x5a];
    }
    iVar4 = FUN_40aed8ec(piVar3,local_30,local_2c,(uint)(iVar4 == 3),iVar2,local_24,local_20,
                         local_1c,(int *)(param_1 + 0x5b),(uint *)0x0);
  }
  else {
    if (uVar1 == 0) {
      iVar4 = 6;
      goto LAB_40af919c;
    }
    if (uVar1 != 2) goto LAB_40af919c;
    iVar4 = FUN_40aee03c(piVar3,param_2,(int *)(param_1 + 0x5b));
  }
  if (iVar4 < 0) {
    param_1[0x34] = 7;
    return 1;
  }
LAB_40af919c:
  iVar2 = 6;
  if ((iVar4 != 5) && (param_1[0x5b] != 0)) {
    iVar2 = 0;
  }
  return iVar2;
}



/* 40af92fc FUN_40af92fc */

/* Boundary evidence: original MIPS .pdata 40af92fc..40af941b. Semantic name remains unreviewed. */

undefined4 FUN_40af92fc(int param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short *psVar6;
  
  if ((param_1 != 0) && (param_2 != (short *)0x0)) {
    psVar6 = *(short **)(param_1 + 0xb4);
    if (psVar6 == (short *)0x0) {
      param_2[0xe] = 0;
      param_2[0xf] = 0;
      param_2[0] = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
      param_2[8] = 0;
      param_2[9] = 0;
      param_2[10] = 0;
      param_2[0xb] = 0;
      param_2[0xc] = 0;
      param_2[0xd] = 0;
    }
    else {
      sVar2 = psVar6[1];
      *param_2 = *psVar6;
      sVar3 = psVar6[2];
      sVar4 = psVar6[3];
      sVar5 = psVar6[4];
      sVar1 = *psVar6;
      param_2[1] = sVar2;
      param_2[2] = sVar3;
      param_2[3] = sVar4;
      param_2[4] = sVar5;
      if (0 < sVar1) {
        FUN_40afcef8(*(int **)(param_2 + 6),*(int **)(psVar6 + 6),(int)sVar1);
      }
      if (0 < psVar6[1]) {
        FUN_40afcef8(*(int **)(param_2 + 8),*(int **)(psVar6 + 8),(int)psVar6[1]);
      }
      if (0 < psVar6[2]) {
        FUN_40afcef8(*(int **)(param_2 + 10),*(int **)(psVar6 + 10),(int)psVar6[2]);
      }
      if (0 < psVar6[3]) {
        FUN_40afcef8(*(int **)(param_2 + 0xc),*(int **)(psVar6 + 0xc),(int)psVar6[3]);
      }
      if (0 < psVar6[4]) {
        FUN_40afcef8(*(int **)(param_2 + 0xe),*(int **)(psVar6 + 0xe),(int)psVar6[4]);
      }
    }
    return 0;
  }
  return 2;
}



/* 40af941c FUN_40af941c */

/* Boundary evidence: original MIPS .pdata 40af941c..40af94f3. Semantic name remains unreviewed. */

undefined4 FUN_40af941c(int param_1,uint *param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_1 != 0) && (param_2 != (uint *)0x0)) {
    uVar1 = *(undefined2 *)(param_1 + 0x42);
    param_2[1] = *(uint *)(param_1 + 0x2c);
    uVar2 = *(ushort *)(param_1 + 0x28);
    param_2[3] = *(uint *)(param_1 + 0x18);
    uVar3 = *(ushort *)(param_1 + 0x38);
    param_2[4] = *(uint *)(param_1 + 0xc);
    uVar5 = *(uint *)(param_1 + 0x20);
    *(undefined2 *)(param_2 + 10) = uVar1;
    param_2[5] = uVar5;
    uVar1 = *(undefined2 *)(param_1 + 0x44);
    param_2[6] = *(uint *)(param_1 + 0x24);
    uVar5 = *(uint *)(param_1 + 0x160);
    *(undefined2 *)((int)param_2 + 0x2a) = uVar1;
    param_2[7] = uVar5;
    uVar1 = *(undefined2 *)(param_1 + 0x46);
    param_2[8] = *(uint *)(param_1 + 0xc4);
    iVar4 = *(int *)(param_1 + 0x30);
    *(undefined2 *)(param_2 + 0xb) = uVar1;
    param_2[9] = iVar4 << 3;
    uVar1 = *(undefined2 *)(param_1 + 0x50);
    param_2[0x10] = *(uint *)(param_1 + 0x48);
    *(undefined2 *)(param_2 + 0xd) = uVar1;
    uVar5 = *(uint *)(param_1 + 0x4c);
    uVar1 = *(undefined2 *)(param_1 + 0x52);
    *param_2 = (uint)uVar2;
    param_2[2] = (uint)uVar3;
    param_2[0xc] = uVar5;
    *(undefined2 *)((int)param_2 + 0x36) = uVar1;
    FUN_40afcef8((int *)(param_2 + 0xe),(int *)(param_1 + 0x54),8);
    return 0;
  }
  return 2;
}



/* 40af94f4 FUN_40af94f4 */

/* Boundary evidence: original MIPS .pdata 40af94f4..40af966f. Semantic name remains unreviewed. */

uint FUN_40af94f4(int param_1,int *param_2,undefined2 *param_3,uint param_4,uint param_5,
                 int *param_6)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint local_18 [2];
  
  if ((((param_1 != 0) && (piVar2 = *(int **)(param_1 + 0x168), piVar2 != (int *)0x0)) &&
      (param_2 != (int *)0x0)) && ((param_6 != (int *)0x0 && (*(int *)(param_1 + 0x16c) == 3)))) {
    if (((param_3 == (undefined2 *)0x0) || (param_3 == (undefined2 *)((int)param_2 + 2))) ||
       (*(ushort *)(param_1 + 0x38) < 2)) {
      thunk_FUN_40af051c(piVar2,param_5,local_18,param_2,param_4,(int *)0x0,param_6,
                         (int *)(param_1 + 0x16c));
      *(uint *)(param_1 + 0x164) = local_18[0];
    }
    else {
      iVar1 = thunk_FUN_40af051c(piVar2,(param_5 & 0xffff) >> 1,local_18,param_2,param_4,(int *)0x0,
                                 param_6,(int *)(param_1 + 0x16c));
      if ((iVar1 == 0) && (local_18[0] != 0)) {
        uVar3 = 0;
        piVar2 = param_2;
        do {
          *(short *)piVar2 = (short)*param_2;
          uVar3 = uVar3 + 1 & 0xffff;
          *param_3 = *(undefined2 *)((int)param_2 + 2);
          piVar2 = (int *)((int)piVar2 + 2);
          param_3 = param_3 + 1;
          param_2 = param_2 + 1;
        } while (uVar3 < local_18[0]);
        *(uint *)(param_1 + 0x164) = local_18[0];
      }
      else {
        *(uint *)(param_1 + 0x164) = local_18[0];
      }
    }
    return local_18[0];
  }
  return 0;
}



/* 40af9670 FUN_40af9670 */

/* Boundary evidence: original MIPS .pdata 40af9670..40af99fb. Semantic name remains unreviewed. */

uint FUN_40af9670(int *param_1,uint *param_2,uint *param_3,int param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = *param_2;
  uVar5 = *param_3;
  if ((param_1 == (int *)0x0) || (param_1[0x5a] == 0)) {
    return 2;
  }
  if (param_5 != 1) {
    uVar5 = 0;
    if (param_1[6] != 0) {
      uVar10 = (uint)param_1[6] / (uint)param_1[5];
      if (param_1[5] == 0) {
        trap(7);
      }
      uVar5 = 1;
      if (uVar10 != 0) {
        uVar5 = uVar9 / uVar10;
        if (uVar10 == 0) {
          trap(7);
        }
        if ((uVar5 != 0) && ((uVar5 & 0xf) == 0)) {
          uVar5 = uVar5 + 1;
        }
      }
      goto LAB_40af9740;
    }
  }
  uVar10 = 0;
LAB_40af9740:
  uVar6 = 0;
  bVar7 = false;
  bVar1 = false;
  bVar2 = false;
  bVar8 = false;
  do {
    *param_1 = uVar5 * param_1[3] + param_1[2];
    iVar3 = FUN_40afa410(param_1);
    if ((iVar3 != 0) || ((param_1[0x3b] != 0 && (param_1[0x39] != 0)))) {
LAB_40af97f0:
      uVar6 = param_1[6];
      goto LAB_40af97f4;
    }
    param_1[0x56] = 0;
    if (param_1[0x4a] != 0) {
      uVar4 = 0;
      do {
        uVar4 = uVar4 + 1;
        iVar3 = FUN_40af9fd8(param_1);
        if (iVar3 != 0) goto LAB_40af97f0;
        if ((ushort)*(byte *)(param_1 + 0x4c) == *(ushort *)(param_1 + 0x33)) {
          uVar6 = param_1[0x4f] - param_1[7];
          if (param_5 == 1) goto LAB_40af97f4;
          if (bVar8) {
            if (bVar2) {
              bVar7 = true;
            }
            if (uVar9 < uVar6) goto LAB_40af9974;
LAB_40af9934:
            uVar4 = uVar9 - uVar6;
            bVar1 = true;
            bVar8 = true;
          }
          else {
            if (uVar6 <= uVar9) goto LAB_40af9934;
LAB_40af9974:
            uVar4 = uVar6 - uVar9;
            bVar1 = false;
            bVar2 = true;
          }
          if (param_4 == 1) {
            if (((uVar4 == 0) || (bVar7)) || (uVar5 == 0)) goto LAB_40af97f4;
          }
          else {
            if (uVar4 < uVar10 * 5 >> 2) {
              bVar7 = true;
            }
            if ((uVar5 == 0) || ((bVar7 && ((uVar5 & 0xf) != 0)))) goto LAB_40af97f4;
          }
          goto LAB_40af9850;
        }
        param_1[0x56] = param_1[0x56] + 1;
      } while (uVar4 < (uint)param_1[0x4a]);
    }
    if (param_5 == 1) {
      bVar1 = false;
LAB_40af9904:
      uVar5 = uVar5 - 1;
    }
    else {
LAB_40af9850:
      if (!bVar1) goto LAB_40af9904;
      uVar5 = uVar5 + 1;
    }
    uVar4 = param_1[5];
  } while (uVar5 < uVar4);
  if (bVar7) {
LAB_40af97f4:
    iVar3 = FUN_40aedeb8((int *)param_1[0x5a]);
    uVar4 = uVar5;
  }
  else {
    uVar6 = param_1[6];
    iVar3 = FUN_40aedeb8((int *)param_1[0x5a]);
  }
  if (iVar3 == 0) {
    param_1[0x34] = 3;
    param_1[1] = uVar4 * param_1[3] + param_1[2];
    param_1[0x5b] = 1;
    *param_2 = uVar6;
    *param_3 = uVar4;
    return uVar6;
  }
  return 1;
}



/* 40af99fc FUN_40af99fc */

/* Boundary evidence: original MIPS .pdata 40af99fc..40af9a2b. Semantic name remains unreviewed. */

void FUN_40af99fc(int *param_1,uint param_2)

{
  uint local_res4 [3];
  uint local_10 [3];
  
  local_10[0] = 0;
  local_res4[0] = param_2;
  FUN_40af9670(param_1,local_res4,local_10,0,0);
  return;
}



/* 40af9a2c FUN_40af9a2c */

/* Boundary evidence: original MIPS .pdata 40af9a2c..40af9ab3. Semantic name remains unreviewed. */

bool FUN_40af9a2c(uint *param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if (param_1 != (uint *)0x0) {
    iVar1 = FUN_40afc5d4(param_1,0xffffffff);
    if (iVar1 != 0) {
      return true;
    }
    if ((((param_1[0x2f] != 0) && (param_3 != 0)) && (param_1[0x30] = param_3, -1 < (int)param_2))
       && ((int)param_2 < (int)param_1[0x2f])) {
      iVar1 = FUN_40afc5d4(param_1,param_2);
      return iVar1 != 0;
    }
  }
  return true;
}



/* 40af9ab4 FUN_40af9ab4 */

/* Boundary evidence: original MIPS .pdata 40af9ab4..40af9afb. Semantic name remains unreviewed. */

uint FUN_40af9ab4(uint *param_1)

{
  int iVar1;
  
  if ((param_1 != (uint *)0x0) && (iVar1 = FUN_40afc5d4(param_1,0xffffffff), iVar1 == 0)) {
    return param_1[0x2f];
  }
  return 0;
}



/* 40af9afc FUN_40af9afc */

/* Boundary evidence: original MIPS .pdata 40af9afc..40af9d37. Semantic name remains unreviewed. */

undefined4 FUN_40af9afc(uint *param_1,ushort param_2)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  ushort local_68;
  undefined2 local_66;
  uint local_64;
  uint local_60;
  undefined2 local_5c;
  ushort local_5a;
  uint local_58;
  undefined2 local_54;
  uint local_50 [3];
  uint local_44;
  uint local_40;
  uint local_38 [8];
  
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  uVar1 = FUN_40afc8f0(param_1,1);
  if (uVar1 != 0) {
    return 3;
  }
  if (param_1[0xb] == 0) {
    return 3;
  }
  if ((short)param_1[0xe] == 0) {
    return 3;
  }
  if (param_1[0xd] == 0) {
    return 3;
  }
  if (param_1[0xc] == 0) {
    return 3;
  }
  puVar2 = FUN_40aee5a0(0,0);
  param_1[0x5a] = (uint)puVar2;
  if (puVar2 != (undefined *)0x0) {
    local_5a = *(ushort *)((int)param_1 + 0x46);
    local_44 = (uint)local_5a;
    local_68 = *(ushort *)((int)param_1 + 0x2a);
    local_64 = param_1[0xb];
    local_66 = (undefined2)param_1[0xe];
    local_60 = param_1[0xc];
    local_58 = param_1[0x12];
    local_54 = (undefined2)param_1[0x10];
    local_40 = (uint)(ushort)((ushort)param_1[0x11] >> 3);
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    local_38[4] = 0;
    local_38[5] = 0;
    local_38[6] = 0;
    local_5c = (undefined2)param_1[0xd];
    local_38[0] = (uint)param_2;
    local_50[0] = local_64;
    FUN_40af80d0((int)&local_68,local_50);
    iVar3 = FUN_40aee6ac((int *)param_1[0x5a],&local_68,local_50,(ushort *)local_38,param_1 + 0x5b,0
                        );
    if (iVar3 == -0x7ffc0000) {
      return 7;
    }
    if (iVar3 == 0) {
      param_1[0x58] = 0;
      if (param_1[0x20] != 0) {
        if ((char)param_1[0x21] != 'D') {
          return 0xc;
        }
        if (*(char *)((int)param_1 + 0x85) != 'R') {
          return 0xc;
        }
        if (*(char *)((int)param_1 + 0x86) != 'M') {
          return 0xc;
        }
        if (*(char *)((int)param_1 + 0x87) != '\0') {
          return 0xc;
        }
        param_1[0x58] = 1;
      }
      param_1[9] = param_1[8];
      if (param_1[5] != 0) {
        param_1[9] = (param_1[5] - 1) * param_1[3] + param_1[8];
      }
      param_1[0x5c] = (uint)&DAT_40b17940;
      param_1[1] = param_1[2];
      *param_1 = param_1[2];
      param_1[0x34] = 3;
      return 0;
    }
  }
  return 1;
}



/* 40af9d38 FUN_40af9d38 */

/* Boundary evidence: original MIPS .pdata 40af9d38..40af9db3. Semantic name remains unreviewed. */

undefined4 FUN_40af9d38(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_1 != (uint *)0x0) {
    uVar1 = FUN_40afc8f0(param_1,0);
    uVar2 = 3;
    if ((((uVar1 == 0) && (uVar2 = 3, param_1[0xb] != 0)) && (uVar2 = 3, (short)param_1[0xe] != 0))
       && ((uVar2 = 3, param_1[0xd] != 0 && (uVar2 = 0, param_1[0xc] == 0)))) {
      uVar2 = 3;
    }
    return uVar2;
  }
  return 2;
}



/* 40af9db4 FUN_40af9db4 */

/* Boundary evidence: original MIPS .pdata 40af9db4..40af9f0f. Semantic name remains unreviewed. */

undefined4 FUN_40af9db4(int *param_1)

{
  short sVar1;
  short *_Memory;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *param_1;
  if (iVar5 != 0) {
    FUN_40aee588(*(int **)(iVar5 + 0x168));
    *(undefined4 *)(iVar5 + 0x168) = 0;
    if (*(void **)(iVar5 + 200) != (void *)0x0) {
      free(*(void **)(iVar5 + 200));
      *(undefined4 *)(iVar5 + 200) = 0;
    }
    pvVar2 = *(void **)(iVar5 + 0xb4);
    if (pvVar2 != (void *)0x0) {
      free(*(void **)((int)pvVar2 + 0xc));
      free(*(void **)((int)pvVar2 + 0x10));
      free(*(void **)((int)pvVar2 + 0x14));
      free(*(void **)((int)pvVar2 + 0x18));
      free(*(void **)((int)pvVar2 + 0x1c));
      free(pvVar2);
      *(undefined4 *)(iVar5 + 0xb4) = 0;
    }
    _Memory = *(short **)(iVar5 + 0xb8);
    if (_Memory != (short *)0x0) {
      uVar4 = 0;
      if (0 < *_Memory) {
        do {
          iVar3 = uVar4 * 0x10;
          uVar4 = uVar4 + 1;
          free(*(void **)(*(int *)(_Memory + 2) + iVar3 + 0xc));
          free(*(void **)(*(int *)(*(int *)(iVar5 + 0xb8) + 4) + iVar3 + 4));
          *(undefined4 *)(*(int *)(*(int *)(iVar5 + 0xb8) + 4) + iVar3 + 0xc) = 0;
          _Memory = *(short **)(iVar5 + 0xb8);
          sVar1 = *_Memory;
          pvVar2 = *(void **)(_Memory + 2);
          *(undefined4 *)((int)pvVar2 + iVar3 + 4) = 0;
        } while (uVar4 < (uint)(int)sVar1);
        free(pvVar2);
        _Memory = *(short **)(iVar5 + 0xb8);
        _Memory[2] = 0;
        _Memory[3] = 0;
      }
      free(_Memory);
      *(undefined4 *)(iVar5 + 0xb8) = 0;
    }
    *param_1 = 0;
    return 0;
  }
  return 2;
}



/* 40af9f10 FUN_40af9f10 */

/* Boundary evidence: original MIPS .pdata 40af9f10..40af9f6b. Semantic name remains unreviewed. */

undefined4 FUN_40af9f10(int *param_1)

{
  FUN_40af9db4(param_1);
  memset(&DAT_40b177c0,0,0x174);
  *param_1 = (int)&DAT_40b177c0;
  DAT_40b17890 = 1;
  return 0;
}



/* 40af9fd8 FUN_40af9fd8 */

/* Boundary evidence: original MIPS .pdata 40af9fd8..40afa40f. Semantic name remains unreviewed. */

undefined4 FUN_40af9fd8(int *param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  ushort *local_20 [3];
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  local_20[0] = (ushort *)0x0;
  iVar3 = FUN_40af7cb0(param_1,param_1[0x3a] + *param_1,2,(va_list)local_20);
  if (iVar3 != 2) {
    return 3;
  }
  iVar3 = param_1[0x3a];
  *(short *)(param_1 + 0x4b) = (short)iVar3;
  cVar1 = *(char *)((int)param_1 + 0x101);
  *(byte *)(param_1 + 0x4c) = (byte)*local_20[0] & 0x7f;
  *(byte *)((int)param_1 + 0x131) = *(byte *)((int)local_20[0] + 1);
  if (cVar1 == '\x02') {
    iVar3 = FUN_40af7cb0(param_1,*param_1 + iVar3 + 2,2,(va_list)local_20);
    if (iVar3 != 2) {
      return 3;
    }
    iVar3 = param_1[0x3a];
    param_1[0x4d] = (uint)*local_20[0];
  }
  else if (cVar1 == '\x03') {
    iVar3 = FUN_40af7cb0(param_1,*param_1 + iVar3 + 2,4,(va_list)local_20);
    if (iVar3 != 4) {
      return 3;
    }
    iVar3 = param_1[0x3a];
    param_1[0x4d] = *(int *)local_20[0];
  }
  else if (cVar1 == '\x01') {
    iVar3 = FUN_40af7cb0(param_1,*param_1 + iVar3 + 2,1,(va_list)local_20);
    if (iVar3 != 1) {
      return 3;
    }
    iVar3 = param_1[0x3a];
    param_1[0x4d] = (uint)(byte)*local_20[0];
  }
  iVar9 = *(byte *)(param_1 + 0x40) + 2;
  iVar3 = FUN_40af7cb0(param_1,iVar3 + *param_1 + iVar9,1,(va_list)local_20);
  if (iVar3 != 1) {
    return 3;
  }
  bVar2 = (byte)*local_20[0];
  uVar6 = (uint)bVar2;
  param_1[0x4f] = -1;
  *(byte *)(param_1 + 0x50) = bVar2;
  if (uVar6 == 1) {
    param_1[0x4f] = param_1[0x4d];
    *(byte *)((int)param_1 + 0x149) = bVar2;
    param_1[0x4d] = 0;
    param_1[0x4e] = 0;
    iVar3 = FUN_40af7cb0(param_1,*param_1 + param_1[0x3a] + 1 + iVar9,3,(va_list)local_20);
    if (iVar3 != 3) {
      return 3;
    }
    iVar3 = param_1[0x3f];
    param_1[0x54] = (uint)(byte)*local_20[0];
    if (iVar3 == 0) {
      uVar6 = (uint)*(byte *)(param_1 + 0x50);
      sVar8 = 0;
    }
    else {
      sVar8 = *(short *)((int)local_20[0] + 1);
      uVar6 = (uint)*(byte *)(param_1 + 0x50);
    }
  }
  else if (uVar6 < 8) {
    iVar3 = param_1[0x3f];
    sVar8 = 0;
  }
  else {
    iVar3 = FUN_40af7cb0(param_1,*param_1 + param_1[0x3a] + 1 + iVar9,8,(va_list)local_20);
    if (iVar3 != 8) {
      return 3;
    }
    uVar6 = (uint)*(byte *)(param_1 + 0x50);
    iVar3 = param_1[0x3f];
    param_1[0x4e] = *(int *)local_20[0];
    iVar9 = *(int *)(local_20[0] + 2);
    sVar8 = 0;
    *(undefined1 *)((int)param_1 + 0x149) = 0;
    param_1[0x4f] = iVar9;
  }
  iVar9 = *(byte *)(param_1 + 0x40) + 3 + uVar6;
  *(short *)((int)param_1 + 0x12e) = (short)iVar9;
  if (iVar3 == 0) {
    if (param_1[0x42] == 0) {
      uVar7 = param_1[3];
      iVar3 = param_1[0x3a];
      uVar6 = ((uVar7 - iVar3) - iVar9) - param_1[0x46] & 0xffff;
    }
    else {
      iVar3 = param_1[0x3a];
      uVar7 = param_1[3];
      uVar6 = ((param_1[0x42] - iVar3) - iVar9) - param_1[0x46] & 0xffff;
    }
  }
  else {
    cVar1 = *(char *)((int)param_1 + 0x122);
    if (cVar1 == '\x02') {
      iVar3 = FUN_40af7cb0(param_1,param_1[0x3a] + *param_1 + iVar9,2,(va_list)local_20);
      if (iVar3 != 2) {
        return 3;
      }
      iVar3 = param_1[0x3a];
    }
    else {
      if (cVar1 != '\x03') {
        if (cVar1 == '\x01') {
          iVar3 = FUN_40af7cb0(param_1,param_1[0x3a] + *param_1 + iVar9,1,(va_list)local_20);
          if (iVar3 != 1) {
            return 3;
          }
          iVar3 = param_1[0x3a];
          uVar6 = (uint)(byte)*local_20[0];
          uVar7 = param_1[3];
        }
        else {
          uVar6 = 0;
          iVar3 = param_1[0x3a];
          uVar7 = param_1[3];
        }
        goto LAB_40afa124;
      }
      iVar3 = FUN_40af7cb0(param_1,param_1[0x3a] + *param_1 + iVar9,4,(va_list)local_20);
      if (iVar3 != 4) {
        return 3;
      }
      iVar3 = param_1[0x3a];
    }
    uVar6 = (uint)*local_20[0];
    uVar7 = param_1[3];
  }
LAB_40afa124:
  if (sVar8 == 0) {
    sVar8 = (short)uVar6;
  }
  uVar4 = uVar6 + (uint)*(byte *)((int)param_1 + 0x123) + (uint)*(ushort *)((int)param_1 + 0x12e);
  uVar5 = (uVar4 & 0xffff) + iVar3;
  *(short *)((int)param_1 + 0x12e) = (short)uVar4;
  *(short *)((int)param_1 + 0x146) = sVar8;
  *(short *)((int)param_1 + 0x142) = (short)uVar6;
  param_1[0x3a] = uVar5;
  if (uVar5 <= uVar7) {
    if (uVar5 != uVar7) {
      return 0;
    }
    if (param_1[0x4a] - 1U <= (uint)param_1[0x56]) {
      return 0;
    }
  }
  return 6;
}



/* 40afa410 FUN_40afa410 */

/* Boundary evidence: original MIPS .pdata 40afa410..40afa95b. Semantic name remains unreviewed. */

undefined4 FUN_40afa410(int *param_1)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  ushort *local_18 [2];
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  local_18[0] = (ushort *)0x0;
  iVar5 = FUN_40af7cb0(param_1,*param_1,1,(va_list)local_18);
  if (iVar5 == 1) {
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    bVar1 = (byte)*local_18[0];
    uVar7 = (uint)bVar1;
    *(undefined1 *)(param_1 + 0x3c) = 0;
    param_1[0x3b] = (uint)(bVar1 >> 7);
    if (bVar1 >> 7 != 0) {
      if ((bVar1 & 0x10) != 0) {
        param_1[0x39] = 1;
        return 0;
      }
      if ((bVar1 & 0x60) != 0) {
        return 1;
      }
      *(char *)(param_1 + 0x3c) = (char)(uVar7 & 0xf);
      if ((uVar7 & 0xf) != 2) {
        return 1;
      }
      param_1[0x3a] = 3;
      iVar5 = FUN_40af7cb0(param_1,*param_1 + 3,1,(va_list)local_18);
      if (iVar5 != 1) {
        return 3;
      }
      uVar7 = (uint)(byte)*local_18[0];
    }
    uVar8 = (uVar7 & 0x60) >> 5;
    param_1[0x3d] = param_1[0x3a];
    *(char *)((int)param_1 + 0xf1) = (char)uVar8;
    if ((uVar8 != 0) && (uVar8 != 2)) {
      return 1;
    }
    uVar8 = (uVar7 & 0x18) >> 3;
    *(char *)(param_1 + 0x3e) = (char)uVar8;
    if (uVar8 == 3) {
      return 1;
    }
    iVar5 = param_1[0x3a] + 1;
    param_1[0x3f] = uVar7 & 1;
    param_1[0x3a] = iVar5;
    *(char *)((int)param_1 + 0xf9) = (char)((int)(uVar7 & 6) >> 1);
    iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,1,(va_list)local_18);
    if (iVar5 != 1) {
      return 3;
    }
    uVar7 = (uint)(byte)*local_18[0];
    *(undefined1 *)(param_1 + 0x40) = 4;
    *(undefined1 *)((int)param_1 + 0x101) = 3;
    if (uVar7 != 0x5d) {
      if ((uVar7 & 0xc0) != 0x40) {
        return 1;
      }
      if ((uVar7 & 0x30) != 0x10) {
        return 1;
      }
      uVar8 = (uVar7 & 0xc) >> 2;
      *(char *)((int)param_1 + 0x101) = (char)uVar8;
      if (uVar8 == 0) {
        return 1;
      }
      if (uVar8 != 3) {
        *(char *)(param_1 + 0x40) = (char)uVar8;
      }
      if ((uVar7 & 3) != 1) {
        return 1;
      }
    }
    cVar2 = *(char *)((int)param_1 + 0xf1);
    iVar5 = param_1[0x3a] + 1;
    param_1[0x3a] = iVar5;
    param_1[0x41] = iVar5;
    if (cVar2 == '\x02') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,2,(va_list)local_18);
      if (iVar5 != 2) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 2;
      param_1[0x42] = (uint)*local_18[0];
      param_1[0x3a] = iVar5;
    }
    else if (cVar2 == '\x03') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,4,(va_list)local_18);
      if (iVar5 != 4) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 4;
      param_1[0x42] = *(int *)local_18[0];
      param_1[0x3a] = iVar5;
    }
    else if (cVar2 == '\x01') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,1,(va_list)local_18);
      if (iVar5 != 1) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 1;
      param_1[0x42] = (uint)(byte)*local_18[0];
      param_1[0x3a] = iVar5;
    }
    cVar2 = *(char *)((int)param_1 + 0xf9);
    param_1[0x43] = iVar5;
    if (cVar2 == '\x02') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,2,(va_list)local_18);
      if (iVar5 != 2) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 2;
      param_1[0x44] = (uint)*local_18[0];
      param_1[0x3a] = iVar5;
    }
    else if (cVar2 == '\x03') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,4,(va_list)local_18);
      if (iVar5 != 4) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 4;
      param_1[0x44] = *(int *)local_18[0];
      param_1[0x3a] = iVar5;
    }
    else if (cVar2 == '\x01') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,1,(va_list)local_18);
      if (iVar5 != 1) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 1;
      param_1[0x44] = (uint)(byte)*local_18[0];
      param_1[0x3a] = iVar5;
    }
    cVar2 = (char)param_1[0x3e];
    param_1[0x45] = iVar5;
    if (cVar2 == '\x02') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,2,(va_list)local_18);
      if (iVar5 != 2) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 2;
      param_1[0x46] = (uint)*local_18[0];
      param_1[0x3a] = iVar5;
    }
    else if (cVar2 == '\x03') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,4,(va_list)local_18);
      if (iVar5 != 4) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 4;
      param_1[0x46] = *(int *)local_18[0];
      param_1[0x3a] = iVar5;
    }
    else if (cVar2 == '\x01') {
      iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,1,(va_list)local_18);
      if (iVar5 != 1) {
        return 3;
      }
      iVar5 = param_1[0x3a] + 1;
      param_1[0x46] = (uint)(byte)*local_18[0];
      param_1[0x3a] = iVar5;
    }
    iVar5 = FUN_40af7cb0(param_1,iVar5 + *param_1,6,(va_list)local_18);
    uVar6 = 3;
    if (iVar5 == 6) {
      iVar5 = param_1[0x3a];
      uVar3 = local_18[0][2];
      param_1[0x47] = *(int *)local_18[0];
      *(ushort *)(param_1 + 0x48) = uVar3;
      param_1[0x3a] = iVar5 + 6;
      param_1[0x49] = 0;
      *(undefined1 *)((int)param_1 + 0x122) = 0;
      *(undefined1 *)((int)param_1 + 0x123) = 0;
      param_1[0x4a] = 1;
      if (param_1[0x3f] != 0) {
        iVar5 = FUN_40af7cb0(param_1,iVar5 + 6 + *param_1,1,(va_list)local_18);
        if (iVar5 != 1) {
          return 3;
        }
        bVar1 = (byte)*local_18[0];
        param_1[0x49] = param_1[0x3a];
        bVar4 = bVar1 >> 6;
        *(byte *)((int)param_1 + 0x122) = bVar4;
        if (1 < (byte)(bVar4 - 1)) {
          return 1;
        }
        *(byte *)((int)param_1 + 0x123) = bVar4;
        param_1[0x4a] = bVar1 & 0x3f;
        if ((bVar1 & 0x3f) == 0) {
          return 1;
        }
        param_1[0x3a] = param_1[0x3a] + 1;
      }
      uVar6 = 0;
    }
  }
  else {
    uVar6 = 3;
  }
  return uVar6;
}



/* 40afa95c FUN_40afa95c */

/* Boundary evidence: original MIPS .pdata 40afa95c..40afaa7b. Semantic name remains unreviewed. */

undefined4 FUN_40afa95c(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_18 [3];
  
  if (param_1 == (int *)0x0) {
    uVar1 = 2;
  }
  else if (param_2 - 0x18U < 0x50) {
    uVar1 = 3;
  }
  else {
    local_18[0] = 0;
    iVar2 = FUN_40af7cb0(param_1,*param_1,0x50,(va_list)local_18);
    uVar1 = 3;
    if (iVar2 == 0x50) {
      iVar2 = *(int *)(local_18[0] + 0x44);
      iVar5 = *(int *)(local_18[0] + 0x20);
      uVar4 = *(uint *)(local_18[0] + 0x34);
      uVar3 = *(uint *)(local_18[0] + 0x30);
      iVar6 = *(int *)(local_18[0] + 0x38);
      if ((iVar2 != *(int *)(local_18[0] + 0x48)) ||
         ((iVar5 == 0 && (*(int *)(local_18[0] + 0x24) == 0)))) {
        return 1;
      }
      *param_1 = *param_1 + (param_2 - 0x18U);
      param_1[3] = iVar2;
      param_1[5] = iVar5;
      param_1[6] = uVar4 * 0x68db8 + uVar3 / 10000 + (uVar4 >> 4) * 0xc;
      param_1[7] = iVar6;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40afaa7c FUN_40afaa7c */

/* Boundary evidence: original MIPS .pdata 40afaa7c..40afabd7. Semantic name remains unreviewed. */

undefined4 FUN_40afaa7c(int *param_1,undefined4 *param_2,uint *param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *local_18 [2];
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  local_18[0] = (undefined4 *)0x0;
  iVar2 = FUN_40af7cb0(param_1,*param_1,0x18,(va_list)local_18);
  if (iVar2 != 0x18) {
    return 3;
  }
  uVar1 = *(undefined2 *)(local_18[0] + 1);
  *param_1 = *param_1 + 0x18;
  *(undefined2 *)(param_2 + 1) = uVar1;
  uVar3 = *local_18[0];
  *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)((int)local_18[0] + 6);
  *param_2 = uVar3;
  *(undefined1 *)(param_2 + 2) = *(undefined1 *)(local_18[0] + 2);
  *(undefined1 *)((int)param_2 + 9) = *(undefined1 *)((int)local_18[0] + 9);
  *(undefined1 *)((int)param_2 + 10) = *(undefined1 *)((int)local_18[0] + 10);
  *(undefined1 *)((int)param_2 + 0xb) = *(undefined1 *)((int)local_18[0] + 0xb);
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(local_18[0] + 3);
  *(undefined1 *)((int)param_2 + 0xd) = *(undefined1 *)((int)local_18[0] + 0xd);
  *(undefined1 *)((int)param_2 + 0xe) = *(undefined1 *)((int)local_18[0] + 0xe);
  *(undefined1 *)((int)param_2 + 0xf) = *(undefined1 *)((int)local_18[0] + 0xf);
  uVar4 = local_18[0][4];
  uVar3 = 4;
  param_3[1] = local_18[0][5];
  if (0x17 < uVar4) {
    uVar3 = 0;
  }
  *param_3 = uVar4;
  return uVar3;
}



/* 40afabd8 FUN_40afabd8 */

/* Boundary evidence: original MIPS .pdata 40afabd8..40afb153. Semantic name remains unreviewed. */

undefined4 FUN_40afabd8(int *param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ushort *local_48;
  undefined4 local_44;
  ushort local_40;
  ushort local_3e;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined4 local_34;
  ushort local_30;
  ushort local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  uVar8 = param_2 - 0x18;
  if (uVar8 < 0x36) {
    return 3;
  }
  local_48 = (ushort *)0x0;
  iVar5 = FUN_40af7cb0(param_1,*param_1,0x36,(va_list)&local_48);
  if (iVar5 != 0x36) {
    return 3;
  }
  local_40 = local_48[2];
  local_44 = *(undefined4 *)local_48;
  local_3e = local_48[3];
  local_3c = (undefined1)local_48[4];
  local_3b = *(undefined1 *)((int)local_48 + 9);
  local_3a = (undefined1)local_48[5];
  local_39 = *(undefined1 *)((int)local_48 + 0xb);
  local_38 = (undefined1)local_48[6];
  local_37 = *(undefined1 *)((int)local_48 + 0xd);
  local_36 = (undefined1)local_48[7];
  local_35 = *(undefined1 *)((int)local_48 + 0xf);
  local_30 = local_48[10];
  local_34 = *(undefined4 *)(local_48 + 8);
  local_2e = local_48[0xb];
  local_2c = (undefined1)local_48[0xc];
  local_2b = *(undefined1 *)((int)local_48 + 0x19);
  local_2a = (undefined1)local_48[0xd];
  local_29 = *(undefined1 *)((int)local_48 + 0x1b);
  local_28 = (undefined1)local_48[0xe];
  local_27 = *(undefined1 *)((int)local_48 + 0x1d);
  local_26 = (undefined1)local_48[0xf];
  local_25 = *(undefined1 *)((int)local_48 + 0x1f);
  uVar7 = *(uint *)(local_48 + 0x14);
  iVar10 = *(int *)(local_48 + 0x16);
  uVar1 = local_48[0x18];
  local_48 = local_48 + 0x1b;
  iVar5 = memcmp(&DAT_40b13b30,&local_44,0x10);
  if (iVar5 != 0) {
    *param_1 = *param_1 + uVar8;
    return 0;
  }
  *(ushort *)(param_1 + 0x33) = uVar1 & 0x7f;
  if (uVar7 == 0) {
    uVar9 = 0x36;
    goto LAB_40afaec4;
  }
  uVar9 = uVar7 + 0x36;
  if (uVar8 < uVar9) {
    return 3;
  }
  uVar6 = FUN_40af7cb0(param_1,*param_1 + 0x36,uVar7,(va_list)&local_48);
  if (uVar7 != uVar6) {
    return 3;
  }
  uVar1 = *local_48;
  *(ushort *)((int)param_1 + 0x2a) = uVar1;
  if (uVar1 == 0x161) {
    if (uVar7 < 0x1c) {
      return 1;
    }
    *(undefined2 *)(param_1 + 10) = 2;
    uVar1 = local_48[1];
    param_1[0xb] = *(int *)(local_48 + 2);
    uVar2 = local_48[6];
    *(ushort *)(param_1 + 0xe) = uVar1;
    *(undefined2 *)((int)param_1 + 0x42) = 1;
    iVar5 = *(int *)(local_48 + 4);
    uVar1 = local_48[7];
    param_1[0xd] = (uint)uVar2;
    param_1[0xc] = iVar5;
    *(ushort *)(param_1 + 0x17) = uVar1;
    *(ushort *)(param_1 + 0x11) = uVar1;
    *(ushort *)((int)param_1 + 0x46) = uVar1;
    uVar1 = local_48[0xb];
    sVar4 = (short)param_1[0xe];
    param_1[0xf] = *(int *)(local_48 + 9);
    *(ushort *)(param_1 + 0x10) = uVar1;
    if (sVar4 == 2) {
LAB_40afaebc:
      param_1[0x12] = 3;
      goto LAB_40afaec4;
    }
    if (sVar4 == 6) {
      param_1[0x12] = 0x3f;
      goto LAB_40afaec4;
    }
    if (sVar4 != 1) {
      return 1;
    }
  }
  else {
    if (0x161 < uVar1) {
      if (0x163 < uVar1) {
        return 1;
      }
      if (uVar7 < 0x24) {
        return 1;
      }
      *(undefined2 *)(param_1 + 10) = 3;
      uVar1 = local_48[6];
      *(ushort *)(param_1 + 0xe) = local_48[1];
      *(undefined2 *)((int)param_1 + 0x42) = 0xfffe;
      uVar2 = local_48[7];
      param_1[0xb] = *(int *)(local_48 + 2);
      param_1[0xc] = *(int *)(local_48 + 4);
      param_1[0xd] = (uint)uVar1;
      *(short *)(param_1 + 0x11) = (short)(((int)(uVar2 + 7) >> 3) << 3);
      *(ushort *)((int)param_1 + 0x46) = uVar2;
      uVar1 = local_48[0x10];
      param_1[0x12] = *(int *)(local_48 + 10);
      *(ushort *)(param_1 + 0x10) = uVar1;
      param_1[0x13] = 1;
      *(undefined2 *)((int)param_1 + 0x52) = 0x10;
      *(undefined1 *)(param_1 + 0x15) = 0x80;
      *(undefined1 *)((int)param_1 + 0x57) = 0xaa;
      *(undefined1 *)((int)param_1 + 0x59) = 0x38;
      *(undefined1 *)((int)param_1 + 0x5a) = 0x9b;
      *(undefined1 *)((int)param_1 + 0x5b) = 0x71;
      *(undefined2 *)(param_1 + 0x14) = 0;
      *(undefined1 *)((int)param_1 + 0x55) = 0;
      *(undefined1 *)((int)param_1 + 0x56) = 0;
      *(undefined1 *)(param_1 + 0x16) = 0;
      goto LAB_40afaec4;
    }
    if (uVar1 != 0x160) {
      return 1;
    }
    if (uVar7 < 0x16) {
      return 1;
    }
    *(undefined2 *)(param_1 + 10) = 1;
    uVar1 = local_48[6];
    *(ushort *)(param_1 + 0xe) = local_48[1];
    iVar5 = *(int *)(local_48 + 2);
    *(ushort *)(param_1 + 0x10) = local_48[10];
    param_1[0xb] = iVar5;
    uVar2 = local_48[9];
    iVar5 = *(int *)(local_48 + 4);
    *(undefined2 *)((int)param_1 + 0x42) = 1;
    uVar3 = local_48[7];
    param_1[0xc] = iVar5;
    param_1[0xd] = (uint)uVar1;
    param_1[0xf] = (uint)uVar2;
    *(ushort *)(param_1 + 0x17) = uVar3;
    *(ushort *)(param_1 + 0x11) = uVar3;
    *(ushort *)((int)param_1 + 0x46) = uVar3;
    if ((short)param_1[0xe] != 1) {
      if ((short)param_1[0xe] != 2) {
        return 1;
      }
      goto LAB_40afaebc;
    }
  }
  param_1[0x12] = 4;
LAB_40afaec4:
  if (iVar10 != 0) {
    iVar5 = memcmp(&DAT_40b13b20,&local_34,0x10);
    iVar10 = 9;
    if (iVar5 == 0) {
      uVar7 = uVar9 + 9;
    }
    else {
      iVar5 = memcmp(&DAT_40b13b10,&local_34,0x10);
      iVar10 = 8;
      if (iVar5 != 0) {
        return 1;
      }
      uVar7 = uVar9 + 8;
    }
    if (uVar8 < uVar7) {
      return 3;
    }
    iVar5 = FUN_40af7cb0(param_1,uVar9 + *param_1,iVar10,(va_list)&local_48);
    if (iVar10 != iVar5) {
      return 3;
    }
    iVar5 = memcmp(&DAT_40b13b20,&local_34,0x10);
    if (iVar5 == 0) {
      param_1[4] = *(int *)local_48;
    }
    else {
      iVar5 = memcmp(&DAT_40b13b10,&local_34,0x10);
      if (iVar5 != 0) {
        return 1;
      }
      param_1[4] = (uint)*(ushort *)((int)local_48 + 1) * (uint)(byte)*local_48;
      if (1 < (byte)*local_48) {
        return 1;
      }
    }
  }
  if (param_1[0xd] == 0) {
    trap(7);
  }
  *param_1 = *param_1 + uVar8;
  param_1[4] = param_1[0xf] * 2 * ((uint)param_1[4] / (uint)param_1[0xd]) *
               (uint)*(ushort *)(param_1 + 0xe);
  return 0;
}



/* 40afb154 FUN_40afb154 */

/* Boundary evidence: original MIPS .pdata 40afb154..40afb2f7. Semantic name remains unreviewed. */

undefined4 FUN_40afb154(int *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  local_30 = (undefined4 *)0x0;
  iVar3 = FUN_40af7cb0(param_1,*param_1,0x1e,(va_list)&local_30);
  uVar4 = 3;
  if (iVar3 == 0x1e) {
    local_28 = *(undefined2 *)(local_30 + 1);
    *param_1 = *param_1 + 0x1e;
    local_2c = *local_30;
    local_26 = *(undefined2 *)((int)local_30 + 6);
    local_24 = *(undefined1 *)(local_30 + 2);
    local_23 = *(undefined1 *)((int)local_30 + 9);
    local_22 = *(undefined1 *)((int)local_30 + 10);
    local_21 = *(undefined1 *)((int)local_30 + 0xb);
    local_20 = *(undefined1 *)(local_30 + 3);
    local_1f = *(undefined1 *)((int)local_30 + 0xd);
    local_1e = *(undefined1 *)((int)local_30 + 0xe);
    local_1d = *(undefined1 *)((int)local_30 + 0xf);
    iVar5 = local_30[4];
    cVar1 = *(char *)(local_30 + 7);
    cVar2 = *(char *)((int)local_30 + 0x1d);
    local_30 = (undefined4 *)((int)local_30 + 0x1e);
    iVar3 = memcmp(&DAT_40b13ab0,&local_2c,0x10);
    if (((iVar3 != 0) || (cVar1 != '\x01')) || (cVar2 != '\x02')) {
      return 4;
    }
    param_1[2] = iVar5;
    uVar4 = 0;
  }
  return uVar4;
}



/* 40afb2f8 FUN_40afb2f8 */

/* Boundary evidence: original MIPS .pdata 40afb2f8..40afb67b. Semantic name remains unreviewed. */

undefined4 FUN_40afb2f8(int *param_1,int param_2,uint param_3)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined2 *_Dst;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *local_38 [2];
  uint local_30;
  undefined2 *local_2c;
  
  if (param_1 == (int *)0x0) {
    uVar6 = 2;
  }
  else {
    uVar12 = param_2 - 0x18;
    if (uVar12 < 0x18) {
LAB_40afb340:
      uVar6 = 3;
    }
    else {
      local_38[0] = (int *)0x0;
      iVar3 = FUN_40af7cb0(param_1,*param_1,0x18,(va_list)local_38);
      uVar6 = 3;
      if (iVar3 == 0x18) {
        iVar3 = local_38[0][4];
        param_1[0x2f] = iVar3;
        if ((iVar3 != 0) && (-1 < (int)param_3)) {
          local_38[0] = local_38[0] + 6;
          if (iVar3 <= (int)param_3) {
            *param_1 = *param_1 + uVar12;
            return 3;
          }
          iVar3 = 0x18;
          local_30 = 0;
          do {
            uVar11 = iVar3 + 0x12;
            if (uVar12 < uVar11) {
              return 3;
            }
            iVar4 = FUN_40af7cb0(param_1,iVar3 + *param_1,0x12,(va_list)local_38);
            if (iVar4 != 0x12) goto LAB_40afb340;
            piVar7 = (int *)param_1[0x30];
            iVar4 = local_38[0][1];
            sVar1 = (short)local_38[0][4];
            *piVar7 = *local_38[0];
            piVar7[1] = iVar4;
            iVar4 = local_38[0][3];
            piVar7[2] = local_38[0][2];
            piVar7[3] = iVar4;
            *(short *)(piVar7 + 4) = sVar1;
            if (((uVar12 < uVar11 + (int)sVar1) ||
                (local_38[0] = (int *)((int)local_38[0] + 0x12), sVar1 < 0xc)) ||
               (iVar4 = FUN_40af7cb0(param_1,uVar11 + *param_1,0xc,(va_list)local_38), iVar4 != 0xc)
               ) goto LAB_40afb340;
            iVar9 = param_1[0x30];
            *(int *)(iVar9 + 0x14) = *local_38[0];
            *(int *)(iVar9 + 0x18) = local_38[0][1];
            iVar4 = local_38[0][2];
            *(int *)(iVar9 + 0x1c) = iVar4;
            if ((int)*(short *)(iVar9 + 0x10) < (int)((iVar4 + 6) * 2 & 0xffffU)) goto LAB_40afb340;
            local_38[0] = local_38[0] + 3;
            uVar11 = (int)*(short *)(iVar9 + 0x10) - 0xc;
            iVar3 = iVar3 + 0x1e;
            if (uVar11 != 0) {
              if (uVar11 < 0x81) {
                uVar8 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar11,(va_list)local_38);
                if (uVar11 != uVar8) {
                  return 3;
                }
                iVar4 = param_1[0x30];
                iVar3 = iVar3 + uVar11;
                if (*(int *)(iVar4 + 0x1c) != 0) {
                  uVar11 = 0;
                  do {
                    iVar9 = uVar11 + 0x10;
                    uVar8 = *(uint *)(iVar4 + 0x1c);
                    uVar11 = uVar11 + 1;
                    *(short *)(iVar4 + iVar9 * 2) = (short)*local_38[0];
                    local_38[0] = (int *)((int)local_38[0] + 2);
                    if (uVar8 <= uVar11) break;
                  } while (uVar11 != 0x40);
                }
              }
              else {
                _Dst = malloc(uVar11);
                if (_Dst == (undefined2 *)0x0) {
                  return 5;
                }
                local_2c = _Dst;
                memset(_Dst,0,uVar11);
                bVar2 = false;
                uVar8 = 0;
                do {
                  uVar10 = 0x80;
                  if (bVar2) {
                    uVar10 = uVar11;
                  }
                  uVar5 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar10,(va_list)local_38);
                  uVar11 = uVar11 - uVar10;
                  bVar2 = uVar11 < 0x81;
                  if (uVar10 != uVar5) {
                    free(local_2c);
                    return 3;
                  }
                  iVar3 = iVar3 + uVar10;
                  if ((uint)(*(int *)(param_1[0x30] + 0x1c) << 1) < uVar8 + uVar10) {
                    free(local_2c);
                    return 3;
                  }
                  FUN_40afcef8((int *)((int)local_2c + uVar8),local_38[0],uVar10);
                  uVar8 = uVar8 + uVar10;
                } while (uVar11 != 0);
                iVar4 = param_1[0x30];
                if (*(int *)(iVar4 + 0x1c) != 0) {
                  iVar9 = 0x10;
                  uVar11 = 0;
                  do {
                    uVar8 = *(uint *)(iVar4 + 0x1c);
                    uVar10 = uVar11 + 1;
                    *(undefined2 *)(iVar4 + iVar9 * 2) = *_Dst;
                    _Dst = _Dst + 1;
                    if (uVar8 <= uVar10) break;
                    iVar9 = uVar11 + 0x11;
                    uVar11 = uVar10;
                  } while (uVar10 != 0x40);
                }
                free(_Dst);
              }
            }
            local_30 = local_30 + 1;
          } while (local_30 <= param_3);
        }
        uVar6 = 0;
        *param_1 = *param_1 + uVar12;
      }
    }
  }
  return uVar6;
}



/* 40afb67c FUN_40afb67c */

/* Boundary evidence: original MIPS .pdata 40afb67c..40afb847. Semantic name remains unreviewed. */

undefined4 FUN_40afb67c(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint _Size;
  uint uVar8;
  int *local_30 [2];
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  uVar8 = param_2 - 0x18;
  if (uVar8 < 8) {
LAB_40afb6c0:
    uVar6 = 3;
  }
  else {
    local_30[0] = (int *)0x0;
    iVar2 = FUN_40af7cb0(param_1,*param_1,8,(va_list)local_30);
    if (iVar2 != 8) {
      return 3;
    }
    _Size = local_30[0][1];
    param_1[0x31] = _Size;
    if (uVar8 < _Size + 8) {
      return 7;
    }
    local_30[0] = local_30[0] + 2;
    pvVar3 = malloc(_Size);
    param_1[0x32] = (int)pvVar3;
    if (pvVar3 == (void *)0x0) {
      return 5;
    }
    if (_Size < 0x81) {
      uVar5 = FUN_40af7cb0(param_1,*param_1 + 8,_Size,(va_list)local_30);
      if (_Size != uVar5) goto LAB_40afb6c0;
      FUN_40afcef8((int *)param_1[0x32],local_30[0],_Size);
      iVar2 = *param_1;
    }
    else {
      iVar2 = 8;
      bVar1 = false;
      uVar5 = 0;
      do {
        uVar7 = 0x80;
        if (bVar1) {
          uVar7 = _Size;
        }
        uVar4 = FUN_40af7cb0(param_1,iVar2 + *param_1,uVar7,(va_list)local_30);
        iVar2 = iVar2 + uVar7;
        _Size = _Size - uVar7;
        if ((uVar7 != uVar4) || ((uint)param_1[0x31] < uVar5 + uVar7)) goto LAB_40afb6c0;
        FUN_40afcef8((int *)(param_1[0x32] + uVar5),local_30[0],uVar7);
        bVar1 = _Size < 0x81;
        uVar5 = uVar5 + uVar7;
      } while (_Size != 0);
      iVar2 = *param_1;
    }
    uVar6 = 0;
    *param_1 = iVar2 + uVar8;
  }
  return uVar6;
}



/* 40afb848 FUN_40afb848 */

/* Boundary evidence: original MIPS .pdata 40afb848..40afbc57. Semantic name remains unreviewed. */

undefined4 FUN_40afb848(int *param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  short *psVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  short *psVar9;
  short *psVar10;
  uint uVar11;
  size_t _Size;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int *local_40 [2];
  uint local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  if (param_1[0x2e] != 0) {
LAB_40afb88c:
    *param_1 = *param_1 + param_2 + -0x18;
    return 0;
  }
  local_40[0] = (int *)0x0;
  psVar3 = malloc(8);
  param_1[0x2e] = (int)psVar3;
  if (psVar3 == (short *)0x0) {
LAB_40afbbc8:
    uVar7 = 5;
  }
  else {
    iVar8 = *param_1;
    psVar3[0] = 0;
    psVar3[1] = 0;
    psVar3[2] = 0;
    psVar3[3] = 0;
    iVar8 = FUN_40af7cb0(param_1,iVar8,2,(va_list)local_40);
    if (iVar8 == 2) {
      iVar8 = *local_40[0];
      local_30 = (int)(short)iVar8;
      local_40[0] = (int *)((int)local_40[0] + 2);
      _Size = local_30 << 4;
      *psVar3 = (short)iVar8;
      pvVar4 = malloc(_Size);
      *(void **)(psVar3 + 2) = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_40afbbc8;
      memset(pvVar4,0,_Size);
      iVar8 = param_2 + -0x1a;
      if (local_30 < 1) goto LAB_40afb88c;
      local_2c = 0;
      iVar14 = 2;
      while (iVar5 = FUN_40af7cb0(param_1,iVar14 + *param_1,2,(va_list)local_40), iVar5 == 2) {
        local_34 = iVar8 - 2;
        sVar1 = (short)*local_40[0];
        iVar8 = local_2c * 0x10;
        psVar9 = (short *)(*(int *)(psVar3 + 2) + iVar8);
        *psVar9 = sVar1;
        if (local_34 < (int)sVar1 + 4U) break;
        local_40[0] = (int *)((int)local_40[0] + 2);
        psVar9[2] = 0;
        psVar9[3] = 0;
        pvVar4 = malloc((int)sVar1);
        iVar5 = *(int *)(psVar3 + 2);
        *(void **)(psVar9 + 2) = pvVar4;
        if (*(int *)((short *)(iVar5 + iVar8) + 2) == 0) goto LAB_40afbbc8;
        uVar12 = (int)*(short *)(iVar5 + iVar8) + 4;
        iVar14 = iVar14 + 2;
        if (uVar12 < 0x81) {
          uVar13 = FUN_40af7cb0(param_1,iVar14 + *param_1,uVar12,(va_list)local_40);
          if (uVar12 != uVar13) {
            return 3;
          }
          iVar14 = iVar14 + uVar12;
          FUN_40afcef8(*(int **)((short *)(*(int *)(psVar3 + 2) + iVar8) + 2),local_40[0],
                       (int)*(short *)(*(int *)(psVar3 + 2) + iVar8));
          iVar5 = *(int *)(psVar3 + 2);
        }
        else {
          bVar2 = false;
          uVar13 = 0;
          do {
            uVar11 = 0x80;
            if (bVar2) {
              uVar11 = uVar12;
            }
            uVar6 = FUN_40af7cb0(param_1,iVar14 + *param_1,uVar11,(va_list)local_40);
            uVar12 = uVar12 - uVar11;
            if (uVar11 != uVar6) goto LAB_40afb948;
            iVar14 = iVar14 + uVar11;
            if ((uint)(int)*(short *)(*(int *)(psVar3 + 2) + iVar8) < uVar13 + uVar11)
            goto LAB_40afb948;
            FUN_40afcef8((int *)(*(int *)((short *)(*(int *)(psVar3 + 2) + iVar8) + 2) + uVar13 * 2)
                         ,local_40[0],uVar11);
            bVar2 = uVar12 < 0x81;
            uVar13 = uVar13 + uVar11;
          } while (uVar12 != 0);
          iVar5 = *(int *)(psVar3 + 2);
        }
        psVar10 = (short *)(iVar5 + iVar8);
        psVar9 = (short *)((int)local_40[0] + (int)*psVar10);
        psVar10[4] = *psVar9;
        sVar1 = psVar9[1];
        local_38 = (local_34 - (int)*psVar10) - 4;
        psVar10[5] = sVar1;
        if (local_38 < (uint)(int)sVar1) break;
        psVar10[6] = 0;
        psVar10[7] = 0;
        local_40[0] = (int *)(psVar9 + 2);
        pvVar4 = malloc((int)sVar1);
        *(void **)(psVar10 + 6) = pvVar4;
        if (*(int *)(*(int *)(psVar3 + 2) + iVar8 + 0xc) == 0) {
          return 5;
        }
        uVar13 = (uint)*(short *)(*(int *)(psVar3 + 2) + iVar8 + 10);
        bVar2 = false;
        uVar12 = 0;
        if (uVar13 < 0x81) {
          uVar12 = FUN_40af7cb0(param_1,iVar14 + *param_1,uVar13,(va_list)local_40);
          if (uVar13 != uVar12) {
            return 3;
          }
          iVar14 = iVar14 + uVar13;
          FUN_40afcef8(*(int **)(*(int *)(psVar3 + 2) + iVar8 + 0xc),local_40[0],
                       (int)*(short *)(*(int *)(psVar3 + 2) + iVar8 + 10));
        }
        else {
          do {
            uVar11 = 0x80;
            if (bVar2) {
              uVar11 = uVar13;
            }
            uVar6 = FUN_40af7cb0(param_1,iVar14 + *param_1,uVar11,(va_list)local_40);
            uVar13 = uVar13 - uVar11;
            if (uVar11 != uVar6) goto LAB_40afb948;
            iVar14 = iVar14 + uVar11;
            if ((uint)(int)*(short *)(*(int *)(psVar3 + 2) + iVar8 + 10) < uVar12 + uVar11)
            goto LAB_40afb948;
            FUN_40afcef8((int *)(*(int *)(*(int *)(psVar3 + 2) + iVar8 + 0xc) + uVar12),local_40[0],
                         uVar11);
            bVar2 = uVar13 < 0x81;
            uVar12 = uVar12 + uVar11;
          } while (uVar13 != 0);
        }
        local_2c = local_2c + 1 & 0xffff;
        iVar8 = (int)*(short *)(*(int *)(psVar3 + 2) + iVar8 + 10);
        if (local_30 <= (int)local_2c) goto LAB_40afb88c;
        local_40[0] = (int *)((int)local_40[0] + iVar8);
        iVar8 = local_38 - iVar8;
      }
    }
LAB_40afb948:
    uVar7 = 3;
  }
  return uVar7;
}



/* 40afbc58 FUN_40afbc58 */

/* Boundary evidence: original MIPS .pdata 40afbc58..40afc23f. Semantic name remains unreviewed. */

undefined4 FUN_40afbc58(int *param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  short *psVar4;
  void *pvVar5;
  uint uVar6;
  int *piVar7;
  size_t sVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int *local_30 [2];
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  if (param_1[0x2d] == 0) {
    local_30[0] = (int *)0x0;
    psVar4 = malloc(0x20);
    param_1[0x2d] = (int)psVar4;
    if (psVar4 == (short *)0x0) {
      return 5;
    }
    iVar3 = *param_1;
    psVar4[0] = 0;
    psVar4[1] = 0;
    psVar4[2] = 0;
    psVar4[3] = 0;
    psVar4[4] = 0;
    psVar4[5] = 0;
    psVar4[6] = 0;
    psVar4[7] = 0;
    psVar4[8] = 0;
    psVar4[9] = 0;
    psVar4[10] = 0;
    psVar4[0xb] = 0;
    psVar4[0xc] = 0;
    psVar4[0xd] = 0;
    psVar4[0xe] = 0;
    psVar4[0xf] = 0;
    iVar3 = FUN_40af7cb0(param_1,iVar3,10,(va_list)local_30);
    if (iVar3 != 10) {
      return 3;
    }
    iVar12 = param_2 + -0x22;
    iVar3 = *local_30[0];
    piVar7 = (int *)((int)local_30[0] + 10);
    *psVar4 = (short)iVar3;
    psVar4[1] = *(short *)((int)local_30[0] + 2);
    sVar8 = (size_t)(short)iVar3;
    psVar4[2] = (short)local_30[0][1];
    psVar4[3] = *(short *)((int)local_30[0] + 6);
    psVar4[4] = (short)local_30[0][2];
    local_30[0] = piVar7;
    if ((int)sVar8 < 1) {
      iVar3 = 10;
    }
    else {
      iVar3 = 10;
      if ((int)sVar8 <= iVar12) {
        pvVar5 = malloc(sVar8);
        *(void **)(psVar4 + 6) = pvVar5;
        if (pvVar5 == (void *)0x0) {
          return 5;
        }
        memset(pvVar5,0,(int)*psVar4);
        uVar10 = (uint)*psVar4;
        if (uVar10 < 0x81) {
          uVar11 = FUN_40af7cb0(param_1,*param_1 + 10,uVar10,(va_list)local_30);
          if (uVar10 != uVar11) {
            return 3;
          }
          iVar3 = uVar10 + 10;
          FUN_40afcef8(*(int **)(psVar4 + 6),local_30[0],uVar10);
          sVar1 = *psVar4;
        }
        else {
          iVar3 = 10;
          bVar2 = false;
          uVar11 = 0;
          do {
            uVar9 = 0x80;
            if (bVar2) {
              uVar9 = uVar10;
            }
            uVar6 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar9,(va_list)local_30);
            uVar10 = uVar10 - uVar9;
            if (uVar9 != uVar6) {
              return 3;
            }
            iVar3 = iVar3 + uVar9;
            if ((uint)(int)*psVar4 < uVar11 + uVar9) {
              return 3;
            }
            FUN_40afcef8((int *)(*(int *)(psVar4 + 6) + uVar11),local_30[0],uVar9);
            bVar2 = uVar10 < 0x81;
            uVar11 = uVar11 + uVar9;
          } while (uVar10 != 0);
          sVar1 = *psVar4;
        }
        iVar12 = iVar12 - sVar1;
      }
    }
    sVar8 = (size_t)psVar4[1];
    if ((0 < (int)sVar8) && ((int)sVar8 <= iVar12)) {
      pvVar5 = malloc(sVar8);
      *(void **)(psVar4 + 8) = pvVar5;
      if (pvVar5 == (void *)0x0) {
        return 5;
      }
      memset(pvVar5,0,(int)psVar4[1]);
      uVar11 = (uint)psVar4[1];
      bVar2 = false;
      uVar10 = 0;
      if (uVar11 < 0x81) {
        uVar10 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar11,(va_list)local_30);
        if (uVar11 != uVar10) {
          return 3;
        }
        iVar3 = iVar3 + uVar11;
        FUN_40afcef8(*(int **)(psVar4 + 8),local_30[0],uVar11);
        sVar1 = psVar4[1];
      }
      else {
        do {
          uVar9 = 0x80;
          if (bVar2) {
            uVar9 = uVar11;
          }
          uVar6 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar9,(va_list)local_30);
          uVar11 = uVar11 - uVar9;
          if (uVar9 != uVar6) {
            return 3;
          }
          iVar3 = iVar3 + uVar9;
          if ((uint)(int)*psVar4 < uVar10 + uVar9) {
            return 3;
          }
          FUN_40afcef8((int *)(*(int *)(psVar4 + 8) + uVar10),local_30[0],uVar9);
          bVar2 = uVar11 < 0x81;
          uVar10 = uVar10 + uVar9;
        } while (uVar11 != 0);
        sVar1 = psVar4[1];
      }
      iVar12 = iVar12 - sVar1;
    }
    sVar8 = (size_t)psVar4[2];
    if ((0 < (int)sVar8) && ((int)sVar8 <= iVar12)) {
      pvVar5 = malloc(sVar8);
      *(void **)(psVar4 + 10) = pvVar5;
      if (pvVar5 == (void *)0x0) {
        return 5;
      }
      memset(pvVar5,0,(int)psVar4[2]);
      uVar11 = (uint)psVar4[2];
      bVar2 = false;
      uVar10 = 0;
      if (uVar11 < 0x81) {
        uVar10 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar11,(va_list)local_30);
        if (uVar11 != uVar10) {
          return 3;
        }
        iVar3 = iVar3 + uVar11;
        FUN_40afcef8(*(int **)(psVar4 + 10),local_30[0],uVar11);
        sVar1 = psVar4[2];
      }
      else {
        do {
          uVar9 = 0x80;
          if (bVar2) {
            uVar9 = uVar11;
          }
          uVar6 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar9,(va_list)local_30);
          uVar11 = uVar11 - uVar9;
          if (uVar9 != uVar6) {
            return 3;
          }
          iVar3 = iVar3 + uVar9;
          if ((uint)(int)*psVar4 < uVar10 + uVar9) {
            return 3;
          }
          FUN_40afcef8((int *)(*(int *)(psVar4 + 10) + uVar10),local_30[0],uVar9);
          bVar2 = uVar11 < 0x81;
          uVar10 = uVar10 + uVar9;
        } while (uVar11 != 0);
        sVar1 = psVar4[2];
      }
      iVar12 = iVar12 - sVar1;
    }
    sVar8 = (size_t)psVar4[3];
    if ((0 < (int)sVar8) && ((int)sVar8 <= iVar12)) {
      pvVar5 = malloc(sVar8);
      *(void **)(psVar4 + 0xc) = pvVar5;
      if (pvVar5 == (void *)0x0) {
        return 5;
      }
      memset(pvVar5,0,(int)psVar4[3]);
      uVar11 = (uint)psVar4[3];
      bVar2 = false;
      uVar10 = 0;
      if (uVar11 < 0x81) {
        uVar10 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar11,(va_list)local_30);
        if (uVar11 != uVar10) {
          return 3;
        }
        iVar3 = iVar3 + uVar11;
        FUN_40afcef8(*(int **)(psVar4 + 0xc),local_30[0],uVar11);
        sVar1 = psVar4[3];
      }
      else {
        do {
          uVar9 = 0x80;
          if (bVar2) {
            uVar9 = uVar11;
          }
          uVar6 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar9,(va_list)local_30);
          uVar11 = uVar11 - uVar9;
          if (uVar9 != uVar6) {
            return 3;
          }
          iVar3 = iVar3 + uVar9;
          if ((uint)(int)*psVar4 < uVar10 + uVar9) {
            return 3;
          }
          FUN_40afcef8((int *)(*(int *)(psVar4 + 0xc) + uVar10),local_30[0],uVar9);
          bVar2 = uVar11 < 0x81;
          uVar10 = uVar10 + uVar9;
        } while (uVar11 != 0);
        sVar1 = psVar4[3];
      }
      iVar12 = iVar12 - sVar1;
    }
    sVar8 = (size_t)psVar4[4];
    if ((0 < (int)sVar8) && ((int)sVar8 <= iVar12)) {
      pvVar5 = malloc(sVar8);
      *(void **)(psVar4 + 0xe) = pvVar5;
      if (pvVar5 == (void *)0x0) {
        return 5;
      }
      memset(pvVar5,0,(int)psVar4[4]);
      uVar11 = (uint)psVar4[4];
      uVar10 = 0;
      bVar2 = false;
      if (uVar11 < 0x81) {
        uVar10 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar11,(va_list)local_30);
        if (uVar11 != uVar10) {
          return 3;
        }
        FUN_40afcef8(*(int **)(psVar4 + 0xe),local_30[0],uVar11);
        iVar3 = *param_1;
        goto LAB_40afbca0;
      }
      do {
        uVar9 = 0x80;
        if (bVar2) {
          uVar9 = uVar11;
        }
        uVar6 = FUN_40af7cb0(param_1,iVar3 + *param_1,uVar9,(va_list)local_30);
        iVar3 = iVar3 + uVar9;
        uVar11 = uVar11 - uVar9;
        if (uVar9 != uVar6) {
          return 3;
        }
        if ((uint)(int)*psVar4 < uVar10 + uVar9) {
          return 3;
        }
        FUN_40afcef8((int *)(*(int *)(psVar4 + 0xe) + uVar10),local_30[0],uVar9);
        bVar2 = uVar11 < 0x81;
        uVar10 = uVar10 + uVar9;
      } while (uVar11 != 0);
    }
  }
  iVar3 = *param_1;
LAB_40afbca0:
  *param_1 = iVar3 + param_2 + -0x18;
  return 0;
}



/* 40afc240 FUN_40afc240 */

/* Boundary evidence: original MIPS .pdata 40afc240..40afc4ff. Semantic name remains unreviewed. */

undefined4 FUN_40afc240(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *local_28 [3];
  
  if (param_1 == (int *)0x0) {
    return 2;
  }
  uVar4 = param_2 - 0x18;
  param_1[0x20] = 0;
  if (3 < uVar4) {
    local_28[0] = (uint *)0x0;
    iVar1 = FUN_40af7cb0(param_1,*param_1,4,(va_list)local_28);
    if (iVar1 != 4) {
      return 3;
    }
    uVar3 = *local_28[0];
    param_1[0x20] = uVar3;
    if (uVar3 < 0x21) {
      local_28[0] = local_28[0] + 1;
      if (uVar3 == 0) {
        uVar5 = 4;
        uVar3 = 8;
      }
      else {
        uVar5 = uVar3 + 4;
        if (uVar4 < uVar5) {
          return 3;
        }
        uVar2 = FUN_40af7cb0(param_1,*param_1 + 4,uVar3,(va_list)local_28);
        if (uVar3 != uVar2) {
          return 3;
        }
        FUN_40afcef8((int *)((int)param_1 + 0x5e),(int *)local_28[0],uVar3);
        uVar3 = uVar3 + 8;
      }
      if (uVar4 < uVar3) {
        return 3;
      }
      iVar1 = FUN_40af7cb0(param_1,uVar5 + *param_1,4,(va_list)local_28);
      if (iVar1 == 4) {
        uVar5 = *local_28[0];
        local_28[0] = local_28[0] + 1;
        if (uVar5 != 0) {
          if (uVar4 < uVar3 + uVar5) {
            return 3;
          }
          uVar2 = FUN_40af7cb0(param_1,uVar3 + *param_1,uVar5,(va_list)local_28);
          if (uVar5 != uVar2) {
            return 3;
          }
          if (0x10 < uVar5) {
            return 3;
          }
          FUN_40afcef8(param_1 + 0x21,(int *)local_28[0],uVar5);
          uVar3 = uVar3 + uVar5;
        }
        uVar5 = uVar3 + 4;
        if (uVar4 < uVar5) {
          return 3;
        }
        iVar1 = FUN_40af7cb0(param_1,uVar3 + *param_1,4,(va_list)local_28);
        if (iVar1 == 4) {
          uVar3 = *local_28[0];
          local_28[0] = local_28[0] + 1;
          if (uVar3 != 0) {
            if (uVar4 < uVar5 + uVar3) {
              return 3;
            }
            uVar2 = FUN_40af7cb0(param_1,uVar5 + *param_1,uVar3,(va_list)local_28);
            if (uVar3 != uVar2) {
              return 3;
            }
            if (0x20 < uVar3) {
              return 3;
            }
            FUN_40afcef8(param_1 + 0x25,(int *)local_28[0],uVar3);
            uVar5 = uVar5 + uVar3;
          }
          uVar3 = uVar5 + 4;
          if (uVar4 < uVar3) {
            return 3;
          }
          iVar1 = FUN_40af7cb0(param_1,uVar5 + *param_1,4,(va_list)local_28);
          if (iVar1 == 4) {
            uVar5 = *local_28[0];
            if (uVar5 != 0) {
              local_28[0] = local_28[0] + 1;
              if (uVar4 < uVar3 + uVar5) {
                return 3;
              }
              do {
                iVar1 = FUN_40af7cb0(param_1,uVar3 + *param_1,uVar5,(va_list)local_28);
                uVar5 = uVar5 - iVar1;
                uVar3 = uVar3 + iVar1;
              } while (uVar5 != 0);
            }
            *param_1 = *param_1 + uVar4;
            return 0;
          }
          return 3;
        }
      }
    }
  }
  return 3;
}



/* 40afc500 FUN_40afc500 */

/* Boundary evidence: original MIPS .pdata 40afc500..40afc5d3. Semantic name remains unreviewed. */

int FUN_40afc500(undefined4 param_1,int param_2,uint param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *local_30 [3];
  
  if ((param_4 == (int *)0x0) || (iVar3 = 0, param_3 == 0)) {
LAB_40afc5a0:
    iVar3 = 0;
  }
  else {
    local_30[0] = (int *)0x0;
    do {
      uVar2 = 0x80;
      if (param_3 < 0x81) {
        uVar2 = param_3;
      }
      uVar1 = FUN_40af7cb0(param_1,param_2,uVar2,(va_list)local_30);
      param_2 = param_2 + uVar2;
      param_3 = param_3 - uVar2;
      if (uVar2 != uVar1) goto LAB_40afc5a0;
      iVar3 = iVar3 + uVar2;
      FUN_40afcef8(param_4,local_30[0],uVar2);
      param_4 = (int *)((int)param_4 + uVar2);
    } while (param_3 != 0);
  }
  return iVar3;
}



/* 40afc5d4 FUN_40afc5d4 */

/* Boundary evidence: original MIPS .pdata 40afc5d4..40afc8ef. Semantic name remains unreviewed. */

undefined4 FUN_40afc5d4(uint *param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined4 local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  *param_1 = 0;
  local_48 = (undefined4 *)0x0;
  iVar3 = FUN_40af7cb0(param_1,0,0x1e,(va_list)&local_48);
  if (iVar3 == 0x1e) {
    local_30 = *(undefined2 *)(local_48 + 1);
    uVar7 = *param_1 + 0x1e;
    *param_1 = uVar7;
    local_2e = *(undefined2 *)((int)local_48 + 6);
    local_34 = *local_48;
    local_2c = *(undefined1 *)(local_48 + 2);
    local_2b = *(undefined1 *)((int)local_48 + 9);
    local_2a = *(undefined1 *)((int)local_48 + 10);
    local_29 = *(undefined1 *)((int)local_48 + 0xb);
    local_28 = *(undefined1 *)(local_48 + 3);
    local_27 = *(undefined1 *)((int)local_48 + 0xd);
    local_26 = *(undefined1 *)((int)local_48 + 0xe);
    local_25 = *(undefined1 *)((int)local_48 + 0xf);
    iVar6 = local_48[4];
    cVar1 = *(char *)(local_48 + 7);
    cVar2 = *(char *)((int)local_48 + 0x1d);
    local_48 = (undefined4 *)((int)local_48 + 0x1e);
    iVar3 = memcmp(&DAT_40b13ab0,&local_34,0x10);
    if (((iVar3 != 0) || (cVar1 != '\x01')) || (uVar5 = iVar6 + 0x32, cVar2 != '\x02')) {
      return 4;
    }
    param_1[2] = uVar5;
    param_1[8] = uVar5;
    if (uVar7 < uVar5) {
      do {
        local_48 = (undefined4 *)0x0;
        iVar3 = FUN_40af7cb0(param_1,uVar7,0x18,(va_list)&local_48);
        if (iVar3 != 0x18) goto LAB_40afc62c;
        uVar7 = *param_1;
        local_40 = *(undefined2 *)(local_48 + 1);
        *param_1 = uVar7 + 0x18;
        local_3e = *(undefined2 *)((int)local_48 + 6);
        local_44 = *local_48;
        local_3c = *(undefined1 *)(local_48 + 2);
        local_3b = *(undefined1 *)((int)local_48 + 9);
        local_3a = *(undefined1 *)((int)local_48 + 10);
        local_39 = *(undefined1 *)((int)local_48 + 0xb);
        local_38 = *(undefined1 *)(local_48 + 3);
        local_37 = *(undefined1 *)((int)local_48 + 0xd);
        local_36 = *(undefined1 *)((int)local_48 + 0xe);
        local_35 = *(undefined1 *)((int)local_48 + 0xf);
        uVar5 = local_48[4];
        if (uVar5 < 0x18) {
          return 4;
        }
        local_48 = local_48 + 6;
        iVar3 = memcmp(&DAT_40b13b60,&local_44,0x10);
        uVar7 = (uVar5 + uVar7 + 0x18) - 0x18;
        if (iVar3 == 0) {
          uVar4 = FUN_40afb2f8((int *)param_1,uVar5,param_2);
          return uVar4;
        }
        *param_1 = uVar7;
      } while (uVar7 < param_1[8]);
    }
    uVar4 = 0;
  }
  else {
LAB_40afc62c:
    uVar4 = 3;
  }
  return uVar4;
}



/* 40afc8f0 FUN_40afc8f0 */

/* Boundary evidence: original MIPS .pdata 40afc8f0..40afcef7. Semantic name remains unreviewed. */

uint FUN_40afc8f0(uint *param_1,int param_2)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *local_50;
  undefined4 local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  *param_1 = 0;
  local_50 = (undefined4 *)0x0;
  iVar5 = FUN_40af7cb0(param_1,0,0x1e,(va_list)&local_50);
  if (iVar5 == 0x1e) {
    local_38 = *(undefined2 *)(local_50 + 1);
    uVar6 = *param_1 + 0x1e;
    *param_1 = uVar6;
    local_3c = *local_50;
    local_36 = *(undefined2 *)((int)local_50 + 6);
    local_34 = *(undefined1 *)(local_50 + 2);
    local_33 = *(undefined1 *)((int)local_50 + 9);
    local_32 = *(undefined1 *)((int)local_50 + 10);
    local_31 = *(undefined1 *)((int)local_50 + 0xb);
    local_30 = *(undefined1 *)(local_50 + 3);
    local_2f = *(undefined1 *)((int)local_50 + 0xd);
    local_2e = *(undefined1 *)((int)local_50 + 0xe);
    local_2d = *(undefined1 *)((int)local_50 + 0xf);
    iVar11 = local_50[4];
    cVar1 = *(char *)(local_50 + 7);
    cVar2 = *(char *)((int)local_50 + 0x1d);
    local_50 = (undefined4 *)((int)local_50 + 0x1e);
    iVar5 = memcmp(&DAT_40b13ab0,&local_3c,0x10);
    if (((iVar5 != 0) || (cVar1 != '\x01')) || (uVar7 = iVar11 + 0x32, cVar2 != '\x02')) {
      return 4;
    }
    param_1[2] = uVar7;
    param_1[8] = uVar7;
    sVar4 = 0;
    sVar3 = 0;
LAB_40afcafc:
    uVar7 = uVar7 - 0x32;
    if (uVar6 < uVar7) {
      while( true ) {
        local_50 = (undefined4 *)0x0;
        iVar5 = FUN_40af7cb0(param_1,uVar6,0x18,(va_list)&local_50);
        if (iVar5 != 0x18) {
          return 3;
        }
        local_48 = *(undefined2 *)(local_50 + 1);
        uVar6 = *param_1 + 0x18;
        *param_1 = uVar6;
        local_4c = *local_50;
        local_46 = *(undefined2 *)((int)local_50 + 6);
        local_44 = *(undefined1 *)(local_50 + 2);
        local_43 = *(undefined1 *)((int)local_50 + 9);
        local_42 = *(undefined1 *)((int)local_50 + 10);
        local_41 = *(undefined1 *)((int)local_50 + 0xb);
        local_40 = *(undefined1 *)(local_50 + 3);
        local_3f = *(undefined1 *)((int)local_50 + 0xd);
        local_3e = *(undefined1 *)((int)local_50 + 0xe);
        local_3d = *(undefined1 *)((int)local_50 + 0xf);
        uVar10 = local_50[4];
        local_50 = local_50 + 6;
        if (uVar10 < 0x18) {
          return 4;
        }
        iVar5 = memcmp(&DAT_40b13ac0,&local_4c,0x10);
        if (iVar5 == 0) {
          if (param_1[8] < (uVar6 + uVar10) - 0x18) goto LAB_40afcc74;
          local_50 = (undefined4 *)0x0;
          if (uVar10 - 0x18 < 0x50) goto LAB_40afc950;
          iVar5 = FUN_40af7cb0(param_1,uVar6,0x50,(va_list)&local_50);
          if (iVar5 != 0x50) {
            return 3;
          }
          uVar7 = local_50[0x11];
          uVar8 = local_50[8];
          uVar9 = local_50[0xe];
          if (uVar7 != local_50[0x12]) goto LAB_40afcc74;
          if ((uVar8 == 0) && (local_50[9] == 0)) {
            return 1;
          }
          uVar6 = *param_1 + (uVar10 - 0x18);
          sVar4 = sVar4 + 1;
          param_1[6] = local_50[0xd] * 0x68db8 + (uint)local_50[0xc] / 10000 +
                       ((uint)local_50[0xd] >> 4) * 0xc;
          param_1[3] = uVar7;
          param_1[5] = uVar8;
          param_1[7] = uVar9;
          *param_1 = uVar6;
          uVar7 = param_1[8];
          goto LAB_40afcafc;
        }
        iVar5 = memcmp(&DAT_40b13ad0,&local_4c,0x10);
        if ((iVar5 != 0) && (iVar5 = memcmp(&DAT_40b13b80,&local_4c,0x10), iVar5 != 0)) break;
        if (param_1[8] < (uVar10 + uVar6) - 0x18) goto LAB_40afcc74;
        uVar6 = FUN_40afabd8((int *)param_1,uVar10);
        if (uVar6 != 0) {
          return uVar6;
        }
        uVar6 = *param_1;
        sVar3 = sVar3 + 1;
        uVar7 = param_1[8] - 0x32;
        if (uVar7 <= uVar6) goto LAB_40afcce8;
      }
      iVar5 = memcmp(&DAT_40b13b40,&local_4c,0x10);
      if (iVar5 == 0) {
        if (param_1[8] < (uVar10 + uVar6) - 0x18) {
          return 1;
        }
        uVar6 = FUN_40afc240((int *)param_1,uVar10);
        if (uVar6 != 0) {
          return uVar6;
        }
        uVar6 = *param_1;
        uVar7 = param_1[8];
      }
      else {
        iVar5 = memcmp(&DAT_40b13ae0,&local_4c,0x10);
        if (iVar5 == 0) {
          if (param_1[8] < (uVar10 + uVar6) - 0x18) {
            return 1;
          }
          uVar6 = FUN_40afbc58((int *)param_1,uVar10);
          if (uVar6 != 0) {
            return uVar6;
          }
          uVar6 = *param_1;
          uVar7 = param_1[8];
        }
        else {
          iVar5 = memcmp(&DAT_40b13b50,&local_4c,0x10);
          if (iVar5 == 0) {
            uVar7 = param_1[8];
            uVar6 = (uVar10 + uVar6) - 0x18;
            if (uVar7 < uVar6) {
              return 1;
            }
            if (param_2 == 0) {
              *param_1 = uVar6;
            }
            else {
              uVar6 = FUN_40afb848((int *)param_1,uVar10);
              if (uVar6 != 0) {
                return uVar6;
              }
              uVar6 = *param_1;
              uVar7 = param_1[8];
            }
          }
          else {
            iVar5 = memcmp(&DAT_40b13b70,&local_4c,0x10);
            if (iVar5 == 0) {
              if (param_1[8] < (uVar10 + uVar6) - 0x18) {
                return 1;
              }
              uVar6 = FUN_40afb67c((int *)param_1,uVar10);
              if (uVar6 != 0) {
                return uVar6;
              }
              uVar6 = *param_1;
              uVar7 = param_1[8];
            }
            else {
              uVar6 = (uVar10 + uVar6) - 0x18;
              uVar7 = param_1[8];
              *param_1 = uVar6;
            }
          }
        }
      }
      goto LAB_40afcafc;
    }
LAB_40afcce8:
    if ((sVar4 == 1) && (sVar3 != 0)) {
      uVar6 = (uint)(uVar6 != uVar7);
    }
    else {
LAB_40afcc74:
      uVar6 = 1;
    }
  }
  else {
LAB_40afc950:
    uVar6 = 3;
  }
  return uVar6;
}



/* 40afcef8 FUN_40afcef8 */

/* WARNING: Instruction at (ram,0x40afcf30) overlaps instruction at (ram,0x40afcf2c)
    */

int * FUN_40afcef8(int *param_1,int *param_2,uint param_3)

{
  undefined1 *puVar1;
  bool bVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  prefetch(param_2,0);
  prefetch(param_1,1);
  uVar9 = (uint)param_1 & 3;
  prefetch(param_2 + 8,0);
  prefetch(param_1 + 8,1);
  uVar8 = (uint)param_2 & 3;
  piVar6 = param_1;
  if (param_3 < 4) {
LAB_40afd0e0:
    if (param_3 == 0) {
      return param_1;
    }
  }
  else {
    prefetch(param_2 + 0x10,0);
    prefetch(param_1 + 0x10,1);
    if (uVar9 == 0) {
      if (uVar8 != 0) {
LAB_40afd058:
        prefetch(param_2 + 0x18,0);
        uVar8 = param_3 & 0xf;
        if (param_3 >> 4 != 0) {
          prefetch(piVar6 + 0x18,1);
          do {
            iVar10 = *param_2;
            iVar11 = param_2[1];
            param_3 = param_3 - 0x10;
            iVar12 = param_2[2];
            iVar14 = param_2[3];
            prefetch(param_2 + 0x48,0);
            param_2 = param_2 + 4;
            *piVar6 = iVar10;
            piVar6[1] = iVar11;
            piVar6[2] = iVar12;
            piVar6[3] = iVar14;
            prefetch(piVar6 + 0x48,1);
            piVar6 = piVar6 + 4;
          } while (param_3 != uVar8);
        }
        uVar8 = param_3 & 3;
        if (param_3 == 0) {
          return param_1;
        }
        if (uVar8 == param_3) goto LAB_40afd0e8;
        do {
          iVar10 = *param_2;
          param_2 = param_2 + 1;
          param_3 = param_3 - 4;
          *piVar6 = iVar10;
          piVar6 = piVar6 + 1;
        } while (param_3 != uVar8);
        goto LAB_40afd0e0;
      }
    }
    else {
      uVar13 = 4 - uVar9;
      uVar4 = (uint)param_1 & 3;
      *(uint *)((int)param_1 - uVar4) =
           *(uint *)((int)param_1 - uVar4) & 0xffffffffU >> (4 - uVar4) * 8 | *param_2 << uVar4 * 8;
      bVar2 = param_3 == uVar13;
      param_3 = param_3 - uVar13;
      if (bVar2) {
        return param_1;
      }
      piVar6 = (int *)((int)param_1 + uVar13);
      param_2 = (int *)((int)param_2 + uVar13);
      if (uVar8 != uVar9) goto LAB_40afd058;
    }
    uVar8 = param_3 & 0x1f;
    if (param_3 >> 5 != 0) {
      prefetch(param_2 + 0x18,0);
      prefetch(piVar6 + 0x18,1);
      piVar5 = piVar6;
      piVar7 = param_2;
      do {
        iVar10 = piVar7[1];
        iVar12 = piVar7[2];
        iVar14 = piVar7[3];
        param_3 = param_3 - 0x20;
        iVar15 = piVar7[4];
        iVar16 = piVar7[5];
        *piVar5 = *piVar7;
        piVar5[1] = iVar10;
        iVar10 = piVar7[6];
        iVar11 = piVar7[7];
        param_2 = piVar7 + 8;
        piVar6 = piVar5 + 8;
        piVar5[2] = iVar12;
        piVar5[3] = iVar14;
        piVar5[4] = iVar15;
        piVar5[5] = iVar16;
        piVar5[6] = iVar10;
        piVar5[7] = iVar11;
        prefetch(piVar7 + 0x48,0);
        prefetch(piVar5 + 0x48,1);
        piVar5 = piVar6;
        piVar7 = param_2;
      } while (param_3 != uVar8);
    }
    if (param_3 == 0) {
      return param_1;
    }
    uVar8 = param_3 & 3;
    if (0xf < param_3) {
      iVar10 = *param_2;
      iVar11 = param_2[1];
      iVar12 = param_2[2];
      iVar14 = param_2[3];
      param_3 = param_3 - 0x10;
      param_2 = param_2 + 4;
      *piVar6 = iVar10;
      piVar6[1] = iVar11;
      piVar6[2] = iVar12;
      piVar6[3] = iVar14;
      piVar6 = piVar6 + 4;
      if (param_3 == 0) {
        return param_1;
      }
    }
    if (uVar8 != param_3) {
      do {
        uVar9 = param_3;
        iVar10 = *param_2;
        param_2 = param_2 + 1;
        param_3 = uVar9 - 4;
        *piVar6 = iVar10;
        piVar6 = piVar6 + 1;
      } while (uVar8 != param_3);
      if (param_3 == 0) {
        return param_1;
      }
      puVar1 = (undefined1 *)((int)piVar6 + (uVar9 - 5));
      uVar8 = (uint)puVar1 & 3;
      puVar3 = (uint *)(puVar1 + -uVar8);
      *puVar3 = *puVar3 & -1 << (uVar8 + 1) * 8 |
                (uint)(*param_2 << (param_3 * -8 + 0x20 & 0x1f)) >> (3 - uVar8) * 8;
      return param_1;
    }
  }
LAB_40afd0e8:
  *(char *)piVar6 = (char)*param_2;
  if ((param_3 != 1) &&
     (*(undefined1 *)((int)piVar6 + 1) = *(undefined1 *)((int)param_2 + 1), param_3 != 2)) {
    *(undefined1 *)((int)piVar6 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
  return param_1;
}



/* 40afd120 FUN_40afd120 */

/* Boundary evidence: original MIPS .pdata 40afd120..40afd13b. Semantic name remains unreviewed. */

void FUN_40afd120(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40afd13c FUN_40afd13c */

/* Boundary evidence: original MIPS .pdata 40afd13c..40afd157. Semantic name remains unreviewed. */

void FUN_40afd13c(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  return;
}



/* 40afd158 DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40afd158..40afd173. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0x1d158  4  DllRegisterServer */
  FUN_40b00ccc(1);
  return;
}



/* 40afd174 DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40afd174..40afd18f. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0x1d174  5  DllUnregisterServer */
  FUN_40b00ccc(0);
  return;
}



/* 40afd190 DllMain */

/* Boundary evidence: original MIPS .pdata 40afd190..40afd1ab. Semantic name remains unreviewed. */

void DllMain(HMODULE param_1,int param_2)

{
                    /* 0x1d190  3  DllMain */
  FUN_40b00dc4(param_1,param_2);
  return;
}



/* 40afd1ac FUN_40afd1ac */

/* Boundary evidence: original MIPS .pdata 40afd1ac..40afd1e7. Semantic name remains unreviewed. */

undefined4 FUN_40afd1ac(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40b00440(param_1 + 0x58);
  if (iVar1 == 0) {
    return 0;
  }
  return 0x80004005;
}



/* 40afd1e8 FUN_40afd1e8 */

/* Boundary evidence: original MIPS .pdata 40afd1e8..40afd223. Semantic name remains unreviewed. */

undefined4 FUN_40afd1e8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40b00450(param_1 + 0x58);
  if (iVar1 == 0) {
    return 0;
  }
  return 0x80004005;
}



/* 40afd224 FUN_40afd224 */

/* Boundary evidence: original MIPS .pdata 40afd224..40afd27b. Semantic name remains unreviewed. */

undefined4 FUN_40afd224(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_40b004ac((int)(param_1 + 0x16));
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x24))(param_1,0);
  }
  return uVar2;
}



/* 40afd27c FUN_40afd27c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40afd27c..40afd3d3. Semantic name remains unreviewed. */

undefined4 FUN_40afd27c(int param_1,void *param_2)

{
  int iVar1;
  void *_Buf1;
  undefined *_Buf2;
  size_t _Size;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x82c8) + 0x34))(*(int **)(param_1 + 0x82c8),0,0);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,(void *)0x0,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    iVar1 = memcmp((void *)((int)param_2 + 0x10),(void *)0x10,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    if (*(int *)((int)param_2 + 0x28) != _DAT_00000028) {
      return 0x80070057;
    }
    iVar1 = memcmp((void *)((int)param_2 + 0x2c),(void *)0x2c,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    _Size = *(size_t *)((int)param_2 + 0x40);
    if (_Size != _DAT_00000040) {
      return 0x80070057;
    }
    _Buf1 = *(void **)((int)param_2 + 0x44);
    _Buf2 = _DAT_00000044;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b1696c,0x10);
    if ((iVar1 == 0) &&
       (iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40b1696c,0x10), iVar1 == 0)) {
      return 0;
    }
    iVar1 = memcmp(param_2,&DAT_40b14c60,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    _Buf1 = (void *)((int)param_2 + 0x10);
    _Size = 0x10;
    _Buf2 = &DAT_40b14254;
  }
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  if (iVar1 != 0) {
    return 0x80070057;
  }
  return 0;
}



/* 40afd3d4 FUN_40afd3d4 */

/* Boundary evidence: original MIPS .pdata 40afd3d4..40afd5d7. Semantic name remains unreviewed. */

undefined4 FUN_40afd3d4(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  LPOLESTR local_18 [2];
  
  iVar2 = memcmp((IID *)(param_2 + 0x2c),&DAT_40b15820,0x10);
  if (iVar2 == 0) {
    psVar3 = *(short **)(param_2 + 0x44);
    memset(&DAT_40b17240,0,0x2e);
    DAT_40b17240 = *psVar3;
    DAT_40b17244 = psVar3[1];
    DAT_40b17246 = *(undefined4 *)(psVar3 + 2);
    DAT_40b1724a = *(undefined4 *)(psVar3 + 4);
    DAT_40b1724e = psVar3[6];
    *(uint *)(param_1 + 0x50) = (uint)(ushort)psVar3[6];
    DAT_40b17250 = psVar3[7];
    sVar1 = *psVar3;
    if (sVar1 == 0x160) {
      DAT_40b17258 = (uint)(ushort)psVar3[10];
    }
    else if (sVar1 == 0x161) {
      DAT_40b17258 = (uint)(ushort)psVar3[0xb];
    }
    else if ((sVar1 == 0x162) || (sVar1 == 0x163)) {
      DAT_40b17258 = (uint)(ushort)psVar3[0x10];
      DAT_40b1725c = *(undefined4 *)(psVar3 + 10);
    }
    iVar2 = FUN_40affcf0((int *)&DAT_40b17240,0x2e,param_1 + 0x58);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    StringFromCLSID((IID *)(param_2 + 0x2c),local_18);
    CoTaskMemFree(local_18[0]);
  }
  return 0x80004005;
}



/* 40afd5d8 FUN_40afd5d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40afd5d8..40afd70b. Semantic name remains unreviewed. */

undefined4 FUN_40afd5d8(int param_1,void *param_2)

{
  int iVar1;
  void *_Buf1;
  undefined4 *_Buf2;
  size_t _Size;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x82cc) + 0x34))(*(int **)(param_1 + 0x82cc),0,0);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,(void *)0x0,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    iVar1 = memcmp((void *)((int)param_2 + 0x10),(void *)0x10,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    if (*(int *)((int)param_2 + 0x28) != _DAT_00000028) {
      return 0x80070057;
    }
    iVar1 = memcmp((void *)((int)param_2 + 0x2c),(void *)0x2c,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    _Size = *(size_t *)((int)param_2 + 0x40);
    if (_Size != _DAT_00000040) {
      return 0x80070057;
    }
    _Buf1 = *(void **)((int)param_2 + 0x44);
    _Buf2 = _DAT_00000044;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b14c60,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    _Buf1 = (void *)((int)param_2 + 0x10);
    iVar1 = memcmp(_Buf1,&DAT_40b13ee4,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    _Size = 0x10;
    _Buf2 = &DAT_40b15040;
  }
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  if (iVar1 != 0) {
    return 0x80070057;
  }
  return 0;
}



/* 40afd70c FUN_40afd70c */

/* Boundary evidence: original MIPS .pdata 40afd70c..40afd857. Semantic name remains unreviewed. */

undefined4 FUN_40afd70c(int param_1,uint param_2,undefined4 *param_3,va_list param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < 2) {
    if ((param_3 == (undefined4 *)0x0) || (FUN_40b012bc((int)param_3,0x12), param_3[0x10] == 0)) {
      uVar1 = 0x80004005;
    }
    else {
      iVar2 = FUN_40afffd0((undefined1 *)param_3[0x11],0x12,param_1 + 0x58,param_4);
      if (iVar2 == 0) {
        *param_3 = 0x73647561;
        param_3[1] = 0x100000;
        param_3[2] = 0xaa000080;
        param_3[3] = 0x719b3800;
        if (param_2 == 0) {
          param_3[4] = 0x51412b85;
          param_3[5] = 0x42fddc4f;
          param_3[6] = 0x3af12187;
          uVar1 = 0x6ea80b35;
        }
        else {
          param_3[4] = 1;
          param_3[5] = 0x100000;
          param_3[6] = 0xaa000080;
          uVar1 = 0x719b3800;
        }
        param_3[7] = uVar1;
        param_3[8] = 0;
        param_3[0xb] = 0x5589f81;
        param_3[0xc] = 0x11cec356;
        param_3[0xd] = 0xaa0001bf;
        param_3[0xe] = 0x5a595500;
        param_3[0x10] = 0x12;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x40103;
  }
  return uVar1;
}



/* 40afd88c FUN_40afd88c */

/* Boundary evidence: original MIPS .pdata 40afd88c..40afd8eb. Semantic name remains unreviewed. */

void FUN_40afd88c(int param_1,int *param_2,undefined4 *param_3)

{
  undefined1 auStack_18 [16];
  
  *param_3 = *(undefined4 *)(param_1 + 0x8314);
  param_3[1] = *(undefined4 *)(param_1 + 0x8310);
  param_3[2] = 4;
  param_3[3] = 0;
  (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_18);
  return;
}



/* 40afd8ec FUN_40afd8ec */

/* Boundary evidence: original MIPS .pdata 40afd8ec..40afd9b3. Semantic name remains unreviewed. */

undefined4 *
FUN_40afd8ec(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  FUN_40b049f8(param_1,param_2,(undefined4 *)0x0,(LPCRITICAL_SECTION)(param_1 + 0x20b7),param_4);
  *param_1 = &PTR_FUN_40b142b4;
  param_1[3] = &PTR_FUN_40b14278;
  param_1[0x20b2] = 0;
  param_1[0x20b3] = 0;
  param_1[4] = &PTR_LAB_40b14264;
  param_1[0x20b4] = param_6;
  param_1[0x20b5] = param_7;
  param_1[0x20b6] = param_8;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20b7));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20bc));
  return param_1;
}



/* 40afd9b4 FUN_40afd9b4 */

/* Boundary evidence: original MIPS .pdata 40afd9b4..40afd9db. Semantic name remains unreviewed. */

void FUN_40afd9b4(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40afd9dc FUN_40afd9dc */

/* Boundary evidence: original MIPS .pdata 40afd9dc..40afda03. Semantic name remains unreviewed. */

void FUN_40afd9dc(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40afda04 FUN_40afda04 */

/* Boundary evidence: original MIPS .pdata 40afda04..40afda2b. Semantic name remains unreviewed. */

void FUN_40afda04(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40afda34 FUN_40afda34 */

/* Boundary evidence: original MIPS .pdata 40afda34..40afdb0b. Semantic name remains unreviewed. */

void FUN_40afda34(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40b142b4;
  param_1[3] = &PTR_FUN_40b14278;
  param_1[4] = &PTR_LAB_40b14264;
  piVar1 = (int *)param_1[0x20b2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
    param_1[0x20b2] = 0;
  }
  piVar1 = (int *)param_1[0x20b3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
    param_1[0x20b3] = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20bc));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20b7));
  FUN_40b0313c((int)param_1);
  return;
}



/* 40afdb0c FUN_40afdb0c */

/* Boundary evidence: original MIPS .pdata 40afdb0c..40afdb3b. Semantic name remains unreviewed. */

void FUN_40afdb0c(void)

{
  int *in_v0;
  
  FUN_40b0313c(*in_v0);
  return;
}



/* 40afdb3c FUN_40afdb3c */

/* Boundary evidence: original MIPS .pdata 40afdb3c..40afdb73. Semantic name remains unreviewed. */

void FUN_40afdb3c(void)

{
  int *in_v0;
  
  FUN_40afd120((LPCRITICAL_SECTION)(*in_v0 + 0x82dc));
  return;
}



/* 40afdb74 FUN_40afdb74 */

/* Boundary evidence: original MIPS .pdata 40afdb74..40afdbab. Semantic name remains unreviewed. */

void FUN_40afdb74(void)

{
  int *in_v0;
  
  FUN_40afd120((LPCRITICAL_SECTION)(*in_v0 + 0x82f0));
  return;
}



/* 40afdbac FUN_40afdbac */

/* Boundary evidence: original MIPS .pdata 40afdbac..40afdbc7. Semantic name remains unreviewed. */

void FUN_40afdbac(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40b0305c(param_1,param_2,param_3);
  return;
}



/* 40afdbc8 FUN_40afdbc8 */

/* Boundary evidence: original MIPS .pdata 40afdbc8..40afdc83. Semantic name remains unreviewed. */

int FUN_40afdbc8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x20bc);
  EnterCriticalSection(lpCriticalSection);
  if (param_1[5] == 0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7ffbfddd;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2);
    if (iVar1 < 0) {
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar1;
}



/* 40afdc84 FUN_40afdc84 */

/* Boundary evidence: original MIPS .pdata 40afdc84..40afdcb3. Semantic name remains unreviewed. */

void FUN_40afdc84(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40afdcb4 FUN_40afdcb4 */

/* Boundary evidence: original MIPS .pdata 40afdcb4..40afdd6f. Semantic name remains unreviewed. */

int FUN_40afdcb4(int *param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x20bc);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if ((int *)param_1[0x20b3] != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)param_1[0x20b3] + 0x4c))();
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40afdd70 FUN_40afdd70 */

/* Boundary evidence: original MIPS .pdata 40afdd70..40afdd9f. Semantic name remains unreviewed. */

void FUN_40afdd70(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40afdda0 FUN_40afdda0 */

/* Boundary evidence: original MIPS .pdata 40afdda0..40afddff. Semantic name remains unreviewed. */

void FUN_40afdda0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  if ((-1 < iVar1) && ((int *)param_1[0x20b3] != (int *)0x0)) {
    (**(code **)(*(int *)param_1[0x20b3] + 0x50))();
  }
  return;
}



/* 40afde00 FUN_40afde00 */

/* Boundary evidence: original MIPS .pdata 40afde00..40afdf6f. Semantic name remains unreviewed. */

int FUN_40afde00(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x20b4);
  EnterCriticalSection(lpCriticalSection);
  param_1[5] = param_3;
  param_1[6] = param_4;
  iVar4 = 0;
  if ((param_1[2] == 0) && (iVar4 = (**(code **)(*param_1 + 0x14))(param_1), iVar4 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (param_1[2] != 2) {
      piVar5 = param_1 + -3;
      iVar1 = (**(code **)(*piVar5 + 0x18))(piVar5);
      iVar3 = 0;
      if (0 < iVar1) {
        do {
          piVar2 = (int *)(**(code **)(*piVar5 + 0x1c))(piVar5,iVar3);
          if ((piVar2[6] != 0) && (iVar4 = (**(code **)(*piVar2 + 0x1c))(piVar2), iVar4 < 0)) {
            LeaveCriticalSection(lpCriticalSection);
            return iVar4;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
      }
    }
    param_1[2] = 2;
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar4;
}



/* 40afdf70 FUN_40afdf70 */

/* Boundary evidence: original MIPS .pdata 40afdf70..40afdf9f. Semantic name remains unreviewed. */

void FUN_40afdf70(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40afdfa0 FUN_40afdfa0 */

/* Boundary evidence: original MIPS .pdata 40afdfa0..40afe0ab. Semantic name remains unreviewed. */

int FUN_40afdfa0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x82d0);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    piVar5 = (int *)(param_1 + -0xc);
    iVar1 = (**(code **)(*piVar5 + 0x18))(piVar5);
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        piVar2 = (int *)(**(code **)(*piVar5 + 0x1c))(piVar5,iVar4);
        if ((piVar2[6] != 0) && (iVar3 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar3 < 0)) {
          LeaveCriticalSection(lpCriticalSection);
          return iVar3;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  *(undefined4 *)(param_1 + 8) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40afe0ac FUN_40afe0ac */

/* Boundary evidence: original MIPS .pdata 40afe0ac..40afe0db. Semantic name remains unreviewed. */

void FUN_40afe0ac(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40afe0dc FUN_40afe0dc */

/* Boundary evidence: original MIPS .pdata 40afe0dc..40afe1e3. Semantic name remains unreviewed. */

undefined4 FUN_40afe0dc(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x82d0);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    piVar1 = (int *)(param_1 + -0xc);
    (**(code **)(*piVar1 + 0x28))(piVar1);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x82e4));
    (**(code **)(*piVar1 + 0x2c))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x82bc) + 0x18))();
    (**(code **)(**(int **)(param_1 + 0x82c0) + 0x18))();
    *(undefined4 *)(param_1 + 8) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x82e4));
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* 40afe1e4 FUN_40afe1e4 */

/* Boundary evidence: original MIPS .pdata 40afe1e4..40afe213. Semantic name remains unreviewed. */

void FUN_40afe1e4(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40afe214 FUN_40afe214 */

/* Boundary evidence: original MIPS .pdata 40afe214..40afe243. Semantic name remains unreviewed. */

void FUN_40afe214(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40afe244 FUN_40afe244 */

/* Boundary evidence: original MIPS .pdata 40afe244..40afe25f. Semantic name remains unreviewed. */

void FUN_40afe244(int param_1)

{
  FUN_40b01cc4(param_1);
  return;
}



/* 40afe260 FUN_40afe260 */

/* Boundary evidence: original MIPS .pdata 40afe260..40afe34f. Semantic name remains unreviewed. */

undefined4 FUN_40afe260(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[6] == 0) {
    (**(code **)(*param_2 + 8))();
    return 1;
  }
  iVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
  if (iVar1 == 0) {
    (**(code **)(*param_2 + 8))(param_2);
    return 0;
  }
  if ((LPCRITICAL_SECTION)param_1[0x2b] != (LPCRITICAL_SECTION)0x0) {
    uVar2 = FUN_40b057e8((LPCRITICAL_SECTION)param_1[0x2b],param_2);
    return uVar2;
  }
  uVar2 = (**(code **)(*param_1 + 0x44))(param_1);
  (**(code **)(*param_2 + 8))(param_2);
  return uVar2;
}



/* 40afe350 FUN_40afe350 */

/* Boundary evidence: original MIPS .pdata 40afe350..40afe3a7. Semantic name remains unreviewed. */

undefined4 FUN_40afe350(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40b04d9c(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40b02534(param_1);
  return uVar1;
}



/* 40afe3a8 FUN_40afe3a8 */

/* Boundary evidence: original MIPS .pdata 40afe3a8..40afe3ff. Semantic name remains unreviewed. */

undefined4 FUN_40afe3a8(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40b05734(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40b02574(param_1);
  return uVar1;
}



/* 40afe400 FUN_40afe400 */

/* Boundary evidence: original MIPS .pdata 40afe400..40afe457. Semantic name remains unreviewed. */

undefined4 FUN_40afe400(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40b05694(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40b023dc(param_1);
  return uVar1;
}



/* 40afe458 FUN_40afe458 */

/* Boundary evidence: original MIPS .pdata 40afe458..40afe543. Semantic name remains unreviewed. */

void FUN_40afe458(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  
  iVar1 = memcmp(param_2,&DAT_40b14b80,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40b161e0,0x10), iVar1 == 0)) {
    piVar3 = param_1 + 0x28;
    if (*piVar3 == 0) {
      iVar1 = *(int *)(param_1[0x1c] + 0x82c8) + 0xc;
      if (*(int *)(param_1[0x1c] + 0x82c8) == 0) {
        iVar1 = 0;
      }
      HVar2 = FUN_40b01720((LPUNKNOWN)param_1[1],0,iVar1,piVar3);
      if (HVar2 < 0) {
        return;
      }
    }
    (*(code *)**(undefined4 **)*piVar3)((undefined4 *)*piVar3,param_2,param_3);
  }
  else {
    FUN_40b01d08(param_1,param_2,param_3);
  }
  return;
}



/* 40afe544 FUN_40afe544 */

/* Boundary evidence: original MIPS .pdata 40afe544..40afe59f. Semantic name remains unreviewed. */

int FUN_40afe544(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  
  iVar1 = FUN_40b0245c(param_1);
  if (-1 < iVar1) {
    p_Var2 = *(LPCRITICAL_SECTION *)(param_1 + 0xac);
    if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
      FUN_40b05250(p_Var2);
      operator_delete(p_Var2);
      *(undefined4 *)(param_1 + 0xac) = 0;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 40afe5a0 FUN_40afe5a0 */

/* Boundary evidence: original MIPS .pdata 40afe5a0..40afe6ab. Semantic name remains unreviewed. */

DWORD FUN_40afe5a0(int param_1)

{
  DWORD DVar1;
  LPCRITICAL_SECTION p_Var2;
  DWORD local_18;
  LPCRITICAL_SECTION local_14;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    DVar1 = 0;
  }
  else {
    DVar1 = FUN_40b0241c(param_1);
    if (-1 < (int)DVar1) {
      local_18 = 0;
      DVar1 = 0;
      if (*(int *)(param_1 + 0xa4) != 0) {
        local_14 = operator_new(0x54);
        if (local_14 == (LPCRITICAL_SECTION)0x0) {
          p_Var2 = (LPCRITICAL_SECTION)0x0;
        }
        else {
          p_Var2 = FUN_40b05864(local_14,*(undefined4 **)(param_1 + 0x18),&local_18,0,1,1,0,
                                *(undefined4 *)(param_1 + 0xa8),3);
        }
        *(LPCRITICAL_SECTION *)(param_1 + 0xac) = p_Var2;
        if (p_Var2 == (LPCRITICAL_SECTION)0x0) {
          DVar1 = 0x8007000e;
        }
        else {
          DVar1 = local_18;
          if ((int)local_18 < 0) {
            FUN_40b05250(p_Var2);
            operator_delete(p_Var2);
            *(undefined4 *)(param_1 + 0xac) = 0;
            DVar1 = local_18;
          }
        }
      }
    }
  }
  return DVar1;
}



/* 40afe6ac FUN_40afe6ac */

/* Boundary evidence: original MIPS .pdata 40afe6ac..40afe6db. Semantic name remains unreviewed. */

void FUN_40afe6ac(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x14));
  return;
}



/* 40afe6dc FUN_40afe6dc */

/* Boundary evidence: original MIPS .pdata 40afe6dc..40afe703. Semantic name remains unreviewed. */

void FUN_40afe6dc(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x3c))();
  return;
}



/* 40afe704 FUN_40afe704 */

/* Boundary evidence: original MIPS .pdata 40afe704..40afe71f. Semantic name remains unreviewed. */

void FUN_40afe704(int param_1,void *param_2)

{
  FUN_40b01e08(param_1,param_2);
  return;
}



/* 40afe720 FUN_40afe720 */

/* Boundary evidence: original MIPS .pdata 40afe720..40afe773. Semantic name remains unreviewed. */

undefined4 FUN_40afe720(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)((*(int **)(param_1 + 0x70))[0x20b2] + 0x18) != 0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x70) + 0x40))();
    return uVar1;
  }
  return 0x40103;
}



/* 40afe774 FUN_40afe774 */

/* Boundary evidence: original MIPS .pdata 40afe774..40afe7b7. Semantic name remains unreviewed. */

void FUN_40afe774(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_40b02098(param_1);
  if (-1 < iVar1) {
    (**(code **)(*(int *)param_1[0x1c] + 0x44))((int *)param_1[0x1c],param_1 + 7);
  }
  return;
}



/* 40afe7b8 FUN_40afe7b8 */

/* Boundary evidence: original MIPS .pdata 40afe7b8..40afe7df. Semantic name remains unreviewed. */

void FUN_40afe7b8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x4c))();
  return;
}



/* 40afe7e0 FUN_40afe7e0 */

/* Boundary evidence: original MIPS .pdata 40afe7e0..40afe85f. Semantic name remains unreviewed. */

undefined4 *
FUN_40afe7e0(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,wchar_t *param_5)

{
  FUN_40b0499c(param_1,param_2,param_3,param_3 + 0x82dc,param_4,param_5);
  *param_1 = &PTR_FUN_40b14600;
  param_1[3] = &PTR_FUN_40b145b8;
  param_1[4] = &PTR_LAB_40b145a4;
  param_1[0x26] = &PTR_LAB_40b14580;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  param_1[0x3b] = 0;
  return param_1;
}



/* 40afe860 FUN_40afe860 */

/* Boundary evidence: original MIPS .pdata 40afe860..40afe887. Semantic name remains unreviewed. */

void FUN_40afe860(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40afe888 FUN_40afe888 */

/* Boundary evidence: original MIPS .pdata 40afe888..40afe8af. Semantic name remains unreviewed. */

void FUN_40afe888(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40afe8b0 FUN_40afe8b0 */

/* Boundary evidence: original MIPS .pdata 40afe8b0..40afe8d7. Semantic name remains unreviewed. */

void FUN_40afe8b0(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40afe8d8 FUN_40afe8d8 */

/* Boundary evidence: original MIPS .pdata 40afe8d8..40afe8ff. Semantic name remains unreviewed. */

void FUN_40afe8d8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x34))();
  return;
}



/* 40afe900 FUN_40afe900 */

/* Boundary evidence: original MIPS .pdata 40afe900..40afe91b. Semantic name remains unreviewed. */

void FUN_40afe900(int param_1,void *param_2)

{
  FUN_40b01e08(param_1,param_2);
  return;
}



/* 40afe91c FUN_40afe91c */

/* Boundary evidence: original MIPS .pdata 40afe91c..40afe967. Semantic name remains unreviewed. */

void FUN_40afe91c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40b01e80();
  if (-1 < iVar1) {
    (**(code **)(**(int **)(param_1 + 0x70) + 0x38))(*(int **)(param_1 + 0x70),param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0xec) = 1;
  }
  return;
}



/* 40afe968 FUN_40afe968 */

/* Boundary evidence: original MIPS .pdata 40afe968..40afe9fb. Semantic name remains unreviewed. */

int FUN_40afe968(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_40b02840(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_40afdbc8(*(int **)(param_1 + -0x28),param_2,param_3,param_4);
  }
  if (iVar1 == -0x7fffbffb) {
    pcVar2 = *(code **)(*(int *)(param_1 + -0x8c) + 0x38);
    *(undefined4 *)(param_1 + -0x2c) = 1;
    (*pcVar2)();
    FUN_40b01918(*(int *)(param_1 + -0x28));
    iVar1 = -0x7ffbfe00;
  }
  return iVar1;
}



/* 40afe9fc FUN_40afe9fc */

/* Boundary evidence: original MIPS .pdata 40afe9fc..40afea8b. Semantic name remains unreviewed. */

int FUN_40afe9fc(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40b02cc4(param_1);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    iVar1 = FUN_40afdda0(*(int **)(param_1 + 100));
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40afea8c FUN_40afea8c */

/* Boundary evidence: original MIPS .pdata 40afea8c..40afeabb. Semantic name remains unreviewed. */

void FUN_40afea8c(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40afeabc FUN_40afeabc */

/* Boundary evidence: original MIPS .pdata 40afeabc..40afeb93. Semantic name remains unreviewed. */

int FUN_40afeabc(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar2;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  piVar2 = *(int **)(param_1 + 100);
  iVar1 = (**(code **)(*piVar2 + 0x2c))(piVar2);
  if (-1 < iVar1) {
    if ((int *)piVar2[0x20b3] != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)piVar2[0x20b3] + 0x54))();
    }
    if (-1 < iVar1) {
      iVar1 = FUN_40b02d0c(param_1);
      LeaveCriticalSection(lpCriticalSection);
      return iVar1;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40afeb94 FUN_40afeb94 */

/* Boundary evidence: original MIPS .pdata 40afeb94..40afebc3. Semantic name remains unreviewed. */

void FUN_40afeb94(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40afebc4 FUN_40afebc4 */

/* Boundary evidence: original MIPS .pdata 40afebc4..40afec27. Semantic name remains unreviewed. */

int FUN_40afebc4(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40afdcb4(*(int **)(param_1 + 100));
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40afec28 FUN_40afec28 */

/* Boundary evidence: original MIPS .pdata 40afec28..40afec57. Semantic name remains unreviewed. */

void FUN_40afec28(void)

{
  int in_v0;
  
  FUN_40afd13c((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40afed0c FUN_40afed0c */

/* Boundary evidence: original MIPS .pdata 40afed0c..40afed27. Semantic name remains unreviewed. */

void FUN_40afed0c(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40b0305c(param_1,param_2,param_3);
  return;
}



/* 40afed28 FUN_40afed28 */

/* Boundary evidence: original MIPS .pdata 40afed28..40afedfb. Semantic name remains unreviewed. */

undefined4 * FUN_40afed28(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  va_list pcVar3;
  
  pcVar3 = (va_list)&DAT_40b13c24;
  FUN_40afd8ec(param_1,L"CWMADecoderFilter",0,&DAT_40b13c24,param_3,0,0,5);
  *param_1 = &PTR_FUN_40b14738;
  param_1[3] = &PTR_FUN_40b146fc;
  param_1[0x20c2] = 1;
  param_1[4] = &PTR_LAB_40b146e8;
  param_1[0x20c3] = 1;
  param_1[0x20c4] = 0x10000;
  param_1[0x20c5] = 5;
  uVar2 = 0x8270;
  uVar1 = 0;
  memset(param_1 + 0x16,0,0x8270);
  FUN_40affbe0(param_1 + 0x16,uVar1,uVar2,pcVar3);
  return param_1;
}



/* 40afedfc FUN_40afedfc */

/* Boundary evidence: original MIPS .pdata 40afedfc..40afee23. Semantic name remains unreviewed. */

void FUN_40afedfc(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40afee24 FUN_40afee24 */

/* Boundary evidence: original MIPS .pdata 40afee24..40afee4b. Semantic name remains unreviewed. */

void FUN_40afee24(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40afee4c FUN_40afee4c */

/* Boundary evidence: original MIPS .pdata 40afee4c..40afee73. Semantic name remains unreviewed. */

void FUN_40afee4c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40afeeb0 FUN_40afeeb0 */

/* Boundary evidence: original MIPS .pdata 40afeeb0..40aff2df. Semantic name remains unreviewed. */

int FUN_40afeeb0(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *local_d0 [2];
  uint local_c8;
  int local_c4;
  int local_c0;
  undefined4 local_bc;
  uint local_b8;
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  undefined4 local_8c;
  uint local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_60 = 0;
  local_5c = 0;
  iVar5 = 0;
  local_d0[0] = (int *)0x0;
  local_c8 = 0;
  local_c4 = 0;
  uVar6 = 0;
  if (param_2 != (int *)0x0) {
    local_c0 = 0;
    local_bc = 0;
    local_b8 = 0;
    local_b4 = 0;
    local_b0 = 0;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    iVar5 = (**(code **)(*param_2 + 0xc))(param_2,&local_c0);
    if (iVar5 < 0) {
      return iVar5;
    }
    local_b4 = (**(code **)(*param_2 + 0x10))(param_2);
    local_b8 = (**(code **)(*param_2 + 0x2c))(param_2);
    iVar5 = (**(code **)(*param_2 + 0x14))(param_2,&local_a8,&local_60);
    if (-1 < iVar5) {
      local_b0 = local_b0 | 0x1000;
    }
    iVar2 = (**(code **)(*param_2 + 0x3c))(param_2);
    if (iVar2 == 0) {
      local_b0 = local_b0 | 0x200;
    }
    iVar2 = (**(code **)(*param_2 + 0x1c))(param_2);
    uVar6 = local_b8;
    if (iVar2 == 0) {
      local_b0 = local_b0 | 0x2000;
    }
  }
  uVar4 = *(uint *)(param_1 + 0x50);
  if (0 < (int)uVar4) {
    uVar7 = local_b8 / uVar4;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    if (0 < (int)uVar7) goto LAB_40aff030;
  }
  uVar7 = 1;
LAB_40aff030:
  local_90 = local_c0;
  local_8c = local_bc;
  local_88 = local_b8;
  local_84 = local_b4;
  local_80 = local_b0;
  local_7c = local_ac;
  local_78 = local_a8;
  iVar2 = 0;
  local_74 = local_a4;
  local_70 = local_a0;
  local_6c = local_9c;
  local_68 = local_98;
  local_64 = local_94;
  if ((int)uVar7 < 1) {
    return iVar5;
  }
  do {
    if (0 < (int)uVar6) {
      uVar4 = *(uint *)(param_1 + 0x50);
      if ((0 < (int)uVar4) && (local_88 = uVar4, 0 < iVar2)) {
        local_78 = 0;
        local_74 = 0;
        local_80 = 0;
      }
      iVar5 = FUN_40b0013c(&local_90,(undefined4 *)(param_1 + 0x58));
      if (iVar5 != 0) {
        return -0x7fffbffb;
      }
      local_90 = *(int *)(param_1 + 0x50) + local_90;
      uVar6 = uVar6 - *(int *)(param_1 + 0x50);
    }
    bVar1 = false;
    do {
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      iVar5 = *(int *)(param_1 + 0x82cc);
      if (*(int *)(iVar5 + 0x18) == 0) {
        iVar5 = 1;
      }
      else {
        piVar3 = *(int **)(iVar5 + 0x98);
        iVar5 = (**(code **)(*piVar3 + 0x1c))(piVar3,local_d0,0,0,0);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      if (local_d0[0] == (int *)0x0) {
        return iVar5;
      }
      iVar5 = (**(code **)(*local_d0[0] + 0xc))(local_d0[0],&local_58);
      if (iVar5 < 0) {
        return iVar5;
      }
      local_4c = (**(code **)(*local_d0[0] + 0x10))();
      iVar5 = FUN_40b001f0(&local_58,(int *)(param_1 + 0x58));
      if (iVar5 == 0x20000) {
        bVar1 = true;
      }
      else if (iVar5 != 0) {
        (**(code **)(*local_d0[0] + 8))();
        return -0x7fffbffb;
      }
      if (local_50 == 0) {
        iVar5 = (**(code **)(*local_d0[0] + 8))();
      }
      else {
        (**(code **)(*local_d0[0] + 0x30))();
        if ((local_48 & 0x1000) != 0) {
          local_c8 = local_40 + 1;
          local_c4 = local_3c + (uint)(local_c8 < local_40);
          (**(code **)(*local_d0[0] + 0x18))(local_d0[0],&local_40,&local_c8);
          if ((local_48 & 0x2000) != 0) {
            (**(code **)(*local_d0[0] + 0x20))(local_d0[0],1);
          }
        }
        iVar5 = FUN_40afe260(*(int **)(param_1 + 0x82cc),local_d0[0]);
      }
    } while ((iVar5 == 0) && (!bVar1));
    iVar2 = iVar2 + 1;
    if ((int)uVar7 <= iVar2) {
      return iVar5;
    }
  } while( true );
}



/* 40aff2e0 FUN_40aff2e0 */

/* Boundary evidence: original MIPS .pdata 40aff2e0..40aff32b. Semantic name remains unreviewed. */

undefined4 * FUN_40aff2e0(undefined4 *param_1,uint param_2)

{
  FUN_40afda34(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40aff32c FUN_40aff32c */

/* Boundary evidence: original MIPS .pdata 40aff32c..40aff3ab. Semantic name remains unreviewed. */

undefined4 *
FUN_40aff32c(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,wchar_t *param_5,
            undefined4 param_6,undefined4 param_7)

{
  FUN_40b04950(param_1,param_2,param_3,param_3 + 0x82dc,param_4,param_5);
  *param_1 = &PTR_FUN_40b14808;
  param_1[3] = &PTR_FUN_40b147c0;
  param_1[4] = &PTR_LAB_40b147ac;
  param_1[0x28] = 0;
  param_1[0x29] = param_6;
  param_1[0x2a] = param_7;
  param_1[0x2b] = 0;
  return param_1;
}



/* 40aff3ac FUN_40aff3ac */

/* Boundary evidence: original MIPS .pdata 40aff3ac..40aff3d3. Semantic name remains unreviewed. */

void FUN_40aff3ac(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40aff3d4 FUN_40aff3d4 */

/* Boundary evidence: original MIPS .pdata 40aff3d4..40aff3fb. Semantic name remains unreviewed. */

void FUN_40aff3d4(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40aff3fc FUN_40aff3fc */

/* Boundary evidence: original MIPS .pdata 40aff3fc..40aff423. Semantic name remains unreviewed. */

void FUN_40aff3fc(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40aff460 FUN_40aff460 */

/* Boundary evidence: original MIPS .pdata 40aff460..40aff50f. Semantic name remains unreviewed. */

void FUN_40aff460(undefined4 *param_1)

{
  LPCRITICAL_SECTION p_Var1;
  
  *param_1 = &PTR_FUN_40b14808;
  param_1[3] = &PTR_FUN_40b147c0;
  param_1[4] = &PTR_LAB_40b147ac;
  p_Var1 = (LPCRITICAL_SECTION)param_1[0x2b];
  if (p_Var1 != (LPCRITICAL_SECTION)0x0) {
    FUN_40b05250(p_Var1);
    operator_delete(p_Var1);
    param_1[0x2b] = 0;
  }
  if ((int *)param_1[0x28] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x28] + 8))();
    param_1[0x28] = 0;
  }
  FUN_40b01cc4((int)param_1);
  return;
}



/* 40aff510 FUN_40aff510 */

/* Boundary evidence: original MIPS .pdata 40aff510..40aff53f. Semantic name remains unreviewed. */

void FUN_40aff510(void)

{
  int *in_v0;
  
  FUN_40afe244(*in_v0);
  return;
}



/* 40aff540 FUN_40aff540 */

/* Boundary evidence: original MIPS .pdata 40aff540..40aff5c3. Semantic name remains unreviewed. */

undefined4 * FUN_40aff540(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40b14600;
  param_1[3] = &PTR_FUN_40b145b8;
  param_1[4] = &PTR_LAB_40b145a4;
  param_1[0x26] = &PTR_LAB_40b14580;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  FUN_40b02610((int)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40aff5c4 FUN_40aff5c4 */

/* Boundary evidence: original MIPS .pdata 40aff5c4..40aff637. Semantic name remains unreviewed. */

undefined4 * FUN_40aff5c4(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x8318);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40afed28(puVar1,param_1,param_2);
  }
  *param_2 = 0;
  return puVar1;
}



/* 40aff638 FUN_40aff638 */

/* Boundary evidence: original MIPS .pdata 40aff638..40aff667. Semantic name remains unreviewed. */

void FUN_40aff638(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40aff668 FUN_40aff668 */

/* Boundary evidence: original MIPS .pdata 40aff668..40aff6df. Semantic name remains unreviewed. */

undefined4 * FUN_40aff668(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40b14738;
  param_1[3] = &PTR_FUN_40b146fc;
  param_1[4] = &PTR_LAB_40b146e8;
  FUN_40affc9c((int)(param_1 + 0x16));
  FUN_40afda34(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40aff6e0 FUN_40aff6e0 */

/* Boundary evidence: original MIPS .pdata 40aff6e0..40aff86b. Semantic name remains unreviewed. */

int FUN_40aff6e0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_28;
  undefined4 *local_24;
  
  piVar4 = (int *)(param_1 + 0x82c8);
  local_28 = 0;
  if (*piVar4 == 0) {
    local_24 = operator_new(0xf0);
    if (local_24 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40afe7e0(local_24,0,param_1,&local_28,L"Input");
    }
    *piVar4 = (int)puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    local_24 = operator_new(0xb0);
    if (local_24 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40aff32c(local_24,0,param_1,&local_28,L"Output",*(undefined4 *)(param_1 + 0x82d4)
                            ,*(undefined4 *)(param_1 + 0x82d8));
    }
    *(undefined4 **)(param_1 + 0x82cc) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      piVar3 = (int *)*piVar4;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0xc))(piVar3,1);
      }
      *piVar4 = 0;
    }
  }
  if (param_2 == 0) {
    iVar2 = *piVar4;
  }
  else if (param_2 == 1) {
    iVar2 = *(int *)(param_1 + 0x82cc);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 40aff86c FUN_40aff86c */

/* Boundary evidence: original MIPS .pdata 40aff86c..40aff89b. Semantic name remains unreviewed. */

void FUN_40aff86c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x24));
  return;
}



/* 40aff89c FUN_40aff89c */

/* Boundary evidence: original MIPS .pdata 40aff89c..40aff8cb. Semantic name remains unreviewed. */

void FUN_40aff89c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x24));
  return;
}



/* 40aff8cc FUN_40aff8cc */

/* Boundary evidence: original MIPS .pdata 40aff8cc..40aff917. Semantic name remains unreviewed. */

undefined4 * FUN_40aff8cc(undefined4 *param_1,uint param_2)

{
  FUN_40aff460(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40aff918 FUN_40aff918 */

/* Boundary evidence: original MIPS .pdata 40aff918..40aff967. Semantic name remains unreviewed. */

void FUN_40aff918(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  wchar_t awStack_3f8 [500];
  uint local_10;
  
  local_10 = DAT_40b17224;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(awStack_3f8,param_1,(wchar_t *)&local_res4,param_4);
  OutputDebugStringW(awStack_3f8);
  FUN_40b06410(local_10);
  return;
}



/* 40aff968 FUN_40aff968 */

void FUN_40aff968(char *param_1)

{
  char cVar1;
  short *psVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = (char *)0x0;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  psVar2 = &DAT_40b17270;
  if ((int)pcVar3 - (int)param_1 != 1) {
    do {
      *psVar2 = (short)param_1[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
      psVar2 = psVar2 + 1;
      pcVar3 = param_1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    } while (pcVar4 < pcVar3 + (-1 - (int)param_1));
  }
  return;
}



/* 40aff9dc FUN_40aff9dc */

/* Boundary evidence: original MIPS .pdata 40aff9dc..40aff9f7. Semantic name remains unreviewed. */

void FUN_40aff9dc(void)

{
  __ll_div();
  return;
}



/* 40aff9f8 FUN_40aff9f8 */

/* Boundary evidence: original MIPS .pdata 40aff9f8..40affa13. Semantic name remains unreviewed. */

void FUN_40aff9f8(void)

{
  __ll_div();
  return;
}



/* 40affa14 FUN_40affa14 */

/* Boundary evidence: original MIPS .pdata 40affa14..40affbdf. Semantic name remains unreviewed. */

void FUN_40affa14(int *param_1,uint param_2,uint *param_3,undefined4 param_4,va_list param_5,
                 int param_6,undefined4 *param_7)

{
  int iVar1;
  va_list pcVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint local_30;
  int *local_2c;
  
  uVar5 = 0;
  local_30 = 0;
  iVar3 = 0;
  local_2c = (int *)0x0;
  if ((param_7[6] != 0) && (param_7[2] == 0)) {
    param_7[9] = param_2;
    while( true ) {
      if (((param_7[1] == 0) && (0x3f < iVar3)) || (param_2 - 0x4000 <= uVar5)) goto LAB_40affb94;
      piVar4 = param_7 + 0x22;
      if (iVar3 == 0) {
        pcVar2 = param_5;
        iVar1 = FUN_40af7ee4(piVar4,(int *)&local_2c,(int *)&local_30,param_5,param_6,param_7 + 0x28
                            );
      }
      else {
        pcVar2 = (va_list)0x0;
        iVar1 = FUN_40af7ee4(piVar4,(int *)&local_2c,(int *)&local_30,(va_list)0x0,0,param_7 + 0x28)
        ;
      }
      if (iVar1 < 0) break;
      if (param_7[4] != *piVar4) {
        param_7[4] = *piVar4;
        param_7[3] = 1;
      }
      if (param_7[5] != param_7[0x23]) {
        param_7[5] = param_7[0x23];
        param_7[3] = 1;
      }
      iVar3 = iVar3 + 1;
      if (0 < (int)local_30) {
        if (param_2 < uVar5 + local_30) {
          FUN_40aff918(0x40b14978,param_2 - 0x4000,uVar5 + param_2,pcVar2);
        }
        FUN_40afcef8(param_1,local_2c,local_30);
        param_1 = (int *)((int)param_1 + local_30);
        uVar5 = uVar5 + local_30;
      }
    }
    if (iVar1 == -3) {
      *param_7 = 1;
LAB_40affb94:
      *param_3 = uVar5;
      return;
    }
    if (iVar1 == -2) {
      param_7[6] = 0;
    }
  }
  *param_3 = 0;
  return;
}



/* 40affbe0 FUN_40affbe0 */

/* Boundary evidence: original MIPS .pdata 40affbe0..40affc9b. Semantic name remains unreviewed. */

undefined4 FUN_40affbe0(void *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == (void *)0x0) {
    return 0x80004005;
  }
  uVar3 = 0x8270;
  uVar2 = 0;
  memset(param_1,0,0x8270);
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  *(undefined4 *)((int)param_1 + 0xc) = 1;
  *(undefined4 *)((int)param_1 + 0x10) = 0;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  *(undefined4 *)((int)param_1 + 0x18) = 0;
  *(undefined4 *)((int)param_1 + 8) = 0;
  *(undefined4 *)((int)param_1 + 4) = 0;
  *(undefined4 *)((int)param_1 + 0x8250) = 0;
  *(undefined4 *)((int)param_1 + 0x8268) = 0;
  *(undefined4 *)((int)param_1 + 0x826c) = 0;
  FUN_40af7ca8((int)param_1 + 0xa0);
  pvVar1 = malloc(0x18000);
  *(void **)((int)param_1 + 0xa0) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    FUN_40aff918(0x40b149e0,uVar2,uVar3,param_4);
  }
  return 0;
}



/* 40affc9c FUN_40affc9c */

/* Boundary evidence: original MIPS .pdata 40affc9c..40affcef. Semantic name remains unreviewed. */

undefined4 FUN_40affc9c(int param_1)

{
  void *_Memory;
  
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(undefined4 *)(param_1 + 0x8250) = 0;
  FUN_40af7ce0(param_1 + 0xa0);
  _Memory = *(void **)(param_1 + 0xa0);
  if (_Memory != (void *)0x0) {
    free(_Memory);
  }
  return 0;
}



/* 40affcf0 FUN_40affcf0 */

/* Boundary evidence: original MIPS .pdata 40affcf0..40afffcf. Semantic name remains unreviewed. */

undefined4 FUN_40affcf0(int *param_1,uint param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  va_list pcVar6;
  
  sVar1 = (short)*param_1;
  if (sVar1 == 0x160) {
    *(undefined1 *)((int)param_1 + 3) = 0;
    *(undefined1 *)((int)param_1 + 2) = 1;
    param_1[7] = 3;
    if ((short)param_1[1] == 1) {
      param_1[7] = 1;
    }
  }
  else if (sVar1 == 0x161) {
    *(undefined1 *)((int)param_1 + 2) = 2;
    *(undefined1 *)(param_1 + 4) = 0x10;
    *(undefined1 *)((int)param_1 + 3) = 0;
    *(undefined1 *)((int)param_1 + 0x11) = 0;
    if (CONCAT11(*(undefined1 *)((int)param_1 + 5),(char)param_1[1]) == 1) {
      param_1[7] = 1;
    }
    else {
      param_1[7] = 3;
    }
  }
  else if (sVar1 == 0x162) {
    *(undefined1 *)((int)param_1 + 2) = 4;
    *(undefined1 *)((int)param_1 + 3) = 0;
    if (param_1[7] == 0x3f) {
      iVar2 = param_1[6];
joined_r0x40affe64:
      if (iVar2 == 0xe0) {
        *(undefined1 *)((int)param_1 + 0x11) = 0;
        *(undefined1 *)(param_1 + 4) = 0x10;
      }
    }
  }
  else if ((sVar1 == 0x163) && (param_1[7] == 0x3f)) {
    iVar2 = param_1[6];
    goto joined_r0x40affe64;
  }
  *(uint *)(param_3 + 0x1c) = (uint)*(ushort *)((int)param_1 + 0xe);
  if (((*(int *)(param_3 + 0x18) == 0) || (*(size_t *)(param_3 + 0x81cc) != param_2)) ||
     (iVar2 = memcmp((void *)(param_3 + 0x81d0),param_1,*(size_t *)(param_3 + 0x81cc)), iVar2 != 0))
  {
    puVar4 = (undefined4 *)(param_3 + 0x88);
    uVar5 = param_2;
    if ((short)*param_1 == 0x162) {
      pcVar6 = (va_list)0x3;
      iVar2 = FUN_40af7d14(puVar4,(undefined2 *)param_1,param_2,3,param_3 + 0xa0);
    }
    else if ((short)*param_1 == 0x163) {
      pcVar6 = (va_list)0x3;
      iVar2 = FUN_40af7d14(puVar4,(undefined2 *)param_1,param_2,3,param_3 + 0xa0);
    }
    else {
      pcVar6 = (va_list)param_1[7];
      iVar2 = FUN_40af7d14(puVar4,(undefined2 *)param_1,param_2,pcVar6,param_3 + 0xa0);
    }
    if (iVar2 == 0) {
      if (param_2 < 0x81) {
        *(uint *)(param_3 + 0x81cc) = param_2;
        FUN_40afcef8((int *)(param_3 + 0x81d0),param_1,param_2);
        *(undefined4 *)(param_3 + 0x18) = 1;
        goto LAB_40afff84;
      }
      FUN_40aff918(0x40b14a5c,param_2,0x80,pcVar6);
    }
    else {
      FUN_40aff918(0x40b14a04,iVar2,uVar5,pcVar6);
    }
    uVar3 = 0x80004005;
  }
  else {
LAB_40afff84:
    uVar3 = 0;
  }
  return uVar3;
}



/* 40afffd0 FUN_40afffd0 */

/* Boundary evidence: original MIPS .pdata 40afffd0..40b0013b. Semantic name remains unreviewed. */

undefined4 FUN_40afffd0(undefined1 *param_1,undefined4 param_2,int param_3,va_list param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(param_3 + 0x18) != 0) {
    param_1[0x11] = 0;
    *param_1 = 1;
    param_1[1] = 0;
    param_1[0x10] = 0;
    uVar1 = *(undefined1 *)(param_3 + 0x81d5);
    if (*(ushort *)(param_3 + 0x81d4) < 3) {
      param_1[2] = *(undefined1 *)(param_3 + 0x81d4);
      param_1[3] = uVar1;
    }
    else {
      param_1[2] = 2;
      param_1[3] = 0;
    }
    *(int *)(param_1 + 4) = *(int *)(param_3 + 0x81d6);
    uVar1 = *(undefined1 *)(param_3 + 0x81e1);
    uVar2 = *(ushort *)(param_3 + 0x81e0);
    param_1[0xe] = *(undefined1 *)(param_3 + 0x81e0);
    param_1[0xf] = uVar1;
    if ((uVar2 == 0) || (0x10 < uVar2)) {
      param_1[0xe] = 0x10;
      param_1[0xf] = 0;
    }
    iVar3 = (uint)*(ushort *)(param_1 + 2) * (uint)*(ushort *)(param_1 + 0xe);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 7;
    }
    uVar4 = iVar3 >> 3 & 0xffff;
    param_1[0xc] = (char)uVar4;
    param_1[0xd] = (char)(uVar4 >> 8);
    *(uint *)(param_1 + 8) = uVar4 * *(int *)(param_1 + 4);
    return 0;
  }
  FUN_40aff918(0x40b14ad4,param_2,param_3,param_4);
  return 0x80004005;
}



/* 40b0013c FUN_40b0013c */

undefined4 FUN_40b0013c(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = 0;
  param_2[1] = 0;
  if (param_2[8] != 0) {
    param_2[0x2097] = 0;
    param_2[0x2094] = 0;
    param_2[8] = 0;
  }
  if (param_2[2] == 0) {
    param_2[0x2099] = param_1[4];
    if ((param_1[4] & 0x1000) == 0) {
      param_2[0x209a] = 0;
      param_2[0x209b] = 0;
    }
    else {
      param_2[0x209a] = param_1[6];
      param_2[0x209b] = param_1[7];
    }
    param_2[0x2096] = *param_1;
    param_2[0x2097] = param_1[2];
    param_2[0x2098] = 0;
  }
  return 0;
}



/* 40b001f0 FUN_40b001f0 */

/* Boundary evidence: original MIPS .pdata 40b001f0..40b0043f. Semantic name remains unreviewed. */

undefined4 FUN_40b001f0(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1 + 2;
  *puVar4 = 0;
  if (*param_2 == 0) {
    uVar2 = param_2[7];
    if ((uint)param_2[0x2097] <= (uint)param_2[7]) {
      uVar2 = param_2[0x2097];
    }
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[4] = 0;
    FUN_40affa14((int *)*param_1,param_1[3],puVar4,param_1 + 4,
                 (va_list)(param_2[0x2098] + param_2[0x2096]),uVar2,param_2);
  }
  if (*puVar4 == 0) {
    param_1[4] = 0;
    uVar1 = 0x20000;
  }
  else {
    puVar4 = (uint *)(param_2 + 0x2099);
    if ((*puVar4 & 0x1000) != 0) {
      param_1[4] = param_1[4] | 0x1000;
      param_1[6] = param_2[0x209a];
      param_1[7] = param_2[0x209b];
    }
    if ((*puVar4 & 0x200) != 0) {
      param_1[4] = param_1[4] | 0x200;
    }
    if ((*puVar4 & 0x2000) != 0) {
      param_1[4] = param_1[4] | 0x2000;
    }
    if (param_2[3] != 0) {
      param_2[10] = 0xf;
      param_2[0xf] = 0xfff3;
      uVar2 = param_2[4];
      param_2[0xb] = 7;
      param_2[0xc] = 0xfffa;
      param_2[0xd] = 3;
      param_2[0x12] = param_2[5];
      param_2[0xe] = 0xfff4;
      param_2[0x10] = 0xffff;
      param_2[0x11] = 8;
      param_2[0x13] = 8;
      uVar3 = param_2[9];
      param_2[0x14] = uVar2 & 0xf;
      param_2[0x15] = uVar2 >> 4 & 0xf;
      param_2[0x16] = uVar2 >> 8 & 0xf;
      param_2[0x17] = uVar2 >> 0xc & 0xf;
      param_2[0x18] = uVar2 >> 0x10 & 0xf;
      param_2[0x19] = uVar2 >> 0x14 & 0xf;
      param_2[0x1a] = uVar3 & 0xf;
      param_2[0x1b] = uVar3 >> 4 & 0xf;
      param_2[0x1c] = uVar3 >> 8 & 0xf;
      param_2[0x1d] = uVar3 >> 0xc & 0xf;
      param_2[0x1e] = uVar3 >> 0x10 & 0xf;
      param_2[0x1f] = uVar3 >> 0x14 & 0xf;
      param_2[3] = 0;
      FUN_40afcef8((int *)*param_1,param_2 + 10,0x60);
    }
    param_2[0x209a] = 0;
    param_2[0x209b] = 0;
    uVar1 = 0;
  }
  *puVar4 = 0;
  return uVar1;
}



/* 40b00440 FUN_40b00440 */

undefined4 FUN_40b00440(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 1;
  return 0;
}



/* 40b00450 FUN_40b00450 */

undefined4 FUN_40b00450(int param_1)

{
  *(undefined4 *)(param_1 + 0x8250) = 0;
  *(undefined4 *)(param_1 + 0x8264) = 0;
  *(undefined4 *)(param_1 + 0x8268) = 0;
  *(undefined4 *)(param_1 + 0x826c) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x825c) = 0;
  *(undefined4 *)(param_1 + 0x8260) = 0;
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(undefined4 *)(param_1 + 8) = 0;
  return 0;
}



/* 40b004ac FUN_40b004ac */

undefined4 FUN_40b004ac(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 1;
  return 0;
}



/* 40b004bc FUN_40b004bc */

/* Boundary evidence: original MIPS .pdata 40b004bc..40b00607. Semantic name remains unreviewed. */

undefined4 FUN_40b004bc(HKEY param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  LSTATUS LVar3;
  int iVar4;
  HKEY local_238;
  DWORD local_234;
  _FILETIME _Stack_230;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_40b17224;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40b06410(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40b004bc(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40b06410(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b00608 FUN_40b00608 */

/* Boundary evidence: original MIPS .pdata 40b00608..40b00897. Semantic name remains unreviewed. */

uint FUN_40b00608(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  size_t sVar2;
  HKEY local_2a8;
  HKEY local_2a4;
  DWORD aDStack_2a0 [2];
  GUID local_298;
  OLECHAR aOStack_288 [40];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40b17224;
  local_298.Data1 = param_1;
  local_298._4_4_ = param_2;
  local_298.Data4._0_4_ = param_3;
  local_298.Data4._4_4_ = param_4;
  StringFromGUID2(&local_298,aOStack_288,0x27);
  wsprintfW(aWStack_238,L"CLSID\\%ls",aOStack_288);
  uVar1 = RegCreateKeyExW((HKEY)0x80000000,aWStack_238,0,L"",0,0,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_2a8,aDStack_2a0);
  if (uVar1 == 0) {
    wsprintfW(aWStack_238,L"%ls",param_5);
    sVar2 = wcslen(aWStack_238);
    uVar1 = RegSetValueExW(local_2a8,L"",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2);
    if (uVar1 == 0) {
      wsprintfW(aWStack_238,L"%ls",param_8);
      uVar1 = RegCreateKeyExW(local_2a8,aWStack_238,0,L"",0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_2a4,
                              aDStack_2a0);
      if (uVar1 == 0) {
        wsprintfW(aWStack_238,L"%ls",param_6);
        sVar2 = wcslen(aWStack_238);
        uVar1 = RegSetValueExW(local_2a4,L"",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2);
        if (uVar1 == 0) {
          wsprintfW(aWStack_238,L"%ls",param_7);
          sVar2 = wcslen(aWStack_238);
          uVar1 = RegSetValueExW(local_2a4,L"ThreadingModel",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2
                                );
        }
        RegCloseKey(local_2a8);
        local_2a8 = local_2a4;
      }
    }
    RegCloseKey(local_2a8);
  }
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  FUN_40b06410(local_30);
  return uVar1;
}



/* 40b00898 FUN_40b00898 */

/* Boundary evidence: original MIPS .pdata 40b00898..40b0090b. Semantic name remains unreviewed. */

undefined4 FUN_40b00898(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40b17224;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40b004bc((HKEY)0x80000000,aWStack_218);
  FUN_40b06410(local_10);
  return 0;
}



/* 40b0090c FUN_40b0090c */

/* Boundary evidence: original MIPS .pdata 40b0090c..40b00b43. Semantic name remains unreviewed. */

DWORD FUN_40b0090c(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40b17224;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40b17788,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40b17210) {
      ppuVar5 = &PTR_u_Alchemy_WMA_Decoder_Filter_40b171fc;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40b00608(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40b161d0,local_240
                                  );
          if ((int)DVar3 < 0) {
            if ((DVar3 == 0x80004002) || (DVar3 == 0x80040202)) {
              DVar3 = 0;
            }
          }
          else {
            DVar3 = (**(code **)(*local_240[0] + 0x10))();
            if (-1 < (int)DVar3) {
              DVar3 = (**(code **)(*local_240[0] + 0xc))();
            }
            (**(code **)(*local_240[0] + 8))();
          }
          CoFreeUnusedLibraries();
          CoUninitialize();
        }
        if ((int)DVar3 < 0) break;
        iVar4 = iVar4 + 1;
        ppuVar5 = ppuVar5 + 5;
      } while (iVar4 < DAT_40b17210);
    }
  }
  FUN_40b06410(local_30);
  return DVar3;
}



/* 40b00b44 FUN_40b00b44 */

/* Boundary evidence: original MIPS .pdata 40b00b44..40b00ccb. Semantic name remains unreviewed. */

int FUN_40b00b44(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40b17210 != 0) {
    iVar3 = DAT_40b17210;
    ppuVar4 = &PTR_DAT_40b17200 + DAT_40b17210 * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b161d0,local_30);
        if (HVar2 < 0) {
          if ((HVar2 == -0x7fffbffe) || (HVar2 == -0x7ffbfdfe)) {
            HVar2 = 0;
          }
        }
        else {
          HVar2 = (**(code **)(*local_30[0] + 0x10))();
          (**(code **)(*local_30[0] + 8))();
        }
        CoFreeUnusedLibraries();
        CoUninitialize();
      }
      if (HVar2 < 0) break;
      puVar1 = (ulong *)*ppuVar5;
      HVar2 = FUN_40b00898(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      if (HVar2 < 0) {
        return HVar2;
      }
      ppuVar4 = ppuVar5;
      if (iVar3 == 0) {
        return HVar2;
      }
    }
  }
  return HVar2;
}



/* 40b00ccc FUN_40b00ccc */

/* Boundary evidence: original MIPS .pdata 40b00ccc..40b00cff. Semantic name remains unreviewed. */

void FUN_40b00ccc(int param_1)

{
  if (param_1 == 0) {
    FUN_40b00b44();
  }
  else {
    FUN_40b0090c();
  }
  return;
}



/* 40b00d44 FUN_40b00d44 */

/* Boundary evidence: original MIPS .pdata 40b00d44..40b00dc3. Semantic name remains unreviewed. */

void FUN_40b00d44(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40b17210) {
    ppuVar2 = &PTR_DAT_40b17200;
    iVar1 = DAT_40b17210;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40b17210;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40b00dc4 FUN_40b00dc4 */

/* Boundary evidence: original MIPS .pdata 40b00dc4..40b00e63. Semantic name remains unreviewed. */

undefined4 FUN_40b00dc4(HMODULE param_1,int param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_2 != 1) {
      return 1;
    }
    DisableThreadLibraryCalls(param_1);
    DAT_40b17784 = 1;
    DAT_40b17670 = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40b17670);
    if (BVar1 != 0) {
      DAT_40b17784 = DAT_40b17680;
    }
    uVar2 = 1;
    DAT_40b17788 = param_1;
  }
  FUN_40b00d44(uVar2);
  return 1;
}



/* 40b00e64 FUN_40b00e64 */

undefined4 FUN_40b00e64(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  if ((((*piVar2 != *param_2) || (piVar2[1] != param_2[1])) || (piVar2[2] != param_2[2])) ||
     (uVar1 = 1, piVar2[3] != param_2[3])) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b00eb4 FUN_40b00eb4 */

/* Boundary evidence: original MIPS .pdata 40b00eb4..40b00f5f. Semantic name remains unreviewed. */

undefined4 FUN_40b00eb4(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40b1698c,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b1697c,0x10), iVar2 == 0)) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b00f60 FUN_40b00f60 */

/* Boundary evidence: original MIPS .pdata 40b00f60..40b00fb7. Semantic name remains unreviewed. */

void * FUN_40b00f60(void *param_1,uint param_2)

{
  FUN_40b04b2c();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b00fb8 FUN_40b00fb8 */

/* Boundary evidence: original MIPS .pdata 40b00fb8..40b010db. Semantic name remains unreviewed. */

int FUN_40b00fb8(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40b1698c,0x10), iVar1 == 0)) {
    local_20[0] = 0;
    piVar2 = (int *)(**(code **)(*(int *)(param_1 + 4) + 8))(param_2,local_20);
    if (piVar2 == (int *)0x0) {
      if (-1 < local_20[0]) {
        local_20[0] = -0x7ff8fff2;
      }
    }
    else if (local_20[0] < 0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
    }
    else {
      (**(code **)(*piVar2 + 4))(piVar2);
      local_20[0] = (**(code **)*piVar2)(piVar2,param_3,param_4);
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  else {
    local_20[0] = -0x7fffbffe;
  }
  return local_20[0];
}



/* 40b010dc DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x210dc  1  DllCanUnloadNow */
  if ((0 < DAT_40b1778c) || (HVar1 = 0, DAT_40b17794 != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40b01108 FUN_40b01108 */

/* Boundary evidence: original MIPS .pdata 40b01108..40b01163. Semantic name remains unreviewed. */

undefined4 * FUN_40b01108(undefined4 *param_1,undefined4 param_2)

{
  FUN_40b04afc(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40b166bc;
  param_1[2] = 0;
  return param_1;
}



/* 40b01164 FUN_40b01164 */

/* Boundary evidence: original MIPS .pdata 40b01164..40b01193. Semantic name remains unreviewed. */

int FUN_40b01164(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40b00f60(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b01194 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40b01194..40b012bb. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0x21194  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40b1698c,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40b1697c,0x10), iVar1 == 0)) {
    iVar1 = DAT_40b17210;
    iVar7 = 0;
    if (0 < DAT_40b17210) {
      ppuVar6 = &PTR_u_Alchemy_WMA_Decoder_Filter_40b171fc;
      do {
        iVar3 = FUN_40b00e64((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40b01108(puVar4,ppuVar6);
          }
          *ppv = piVar5;
          if (piVar5 == (int *)0x0) {
            return -0x7ff8fff2;
          }
          (**(code **)(*piVar5 + 4))(piVar5);
          return 0;
        }
        iVar7 = iVar7 + 1;
        ppuVar6 = ppuVar6 + 5;
      } while (iVar7 < iVar1);
    }
    HVar2 = -0x7ffbfeef;
  }
  else {
    HVar2 = -0x7fffbffe;
  }
  return HVar2;
}



/* 40b012bc FUN_40b012bc */

/* Boundary evidence: original MIPS .pdata 40b012bc..40b01357. Semantic name remains unreviewed. */

LPVOID FUN_40b012bc(int param_1,uint param_2)

{
  LPVOID pvVar1;
  
  if (*(uint *)(param_1 + 0x40) != param_2) {
    pvVar1 = CoTaskMemAlloc(param_2);
    if (pvVar1 != (LPVOID)0x0) {
      if (*(uint *)(param_1 + 0x40) != 0) {
        CoTaskMemFree(*(LPVOID *)(param_1 + 0x44));
      }
      *(uint *)(param_1 + 0x40) = param_2;
      *(LPVOID *)(param_1 + 0x44) = pvVar1;
      return pvVar1;
    }
    if (*(uint *)(param_1 + 0x40) < param_2) {
      return (LPVOID)0x0;
    }
  }
  return *(LPVOID *)(param_1 + 0x44);
}



/* 40b01358 FUN_40b01358 */

/* Boundary evidence: original MIPS .pdata 40b01358..40b01393. Semantic name remains unreviewed. */

void FUN_40b01358(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40b01394 FUN_40b01394 */

/* Boundary evidence: original MIPS .pdata 40b01394..40b01427. Semantic name remains unreviewed. */

void FUN_40b01394(void *param_1,void *param_2)

{
  LPVOID _Dst;
  
  memcpy(param_1,param_2,0x48);
  if (*(SIZE_T *)((int)param_2 + 0x40) != 0) {
    _Dst = CoTaskMemAlloc(*(SIZE_T *)((int)param_2 + 0x40));
    *(LPVOID *)((int)param_1 + 0x44) = _Dst;
    if (_Dst == (LPVOID)0x0) {
      *(undefined4 *)((int)param_1 + 0x40) = 0;
    }
    else {
      memcpy(_Dst,*(void **)((int)param_2 + 0x44),*(size_t *)((int)param_1 + 0x40));
    }
  }
  if (*(int **)((int)param_1 + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)((int)param_1 + 0x3c) + 4))();
  }
  return;
}



/* 40b01428 FUN_40b01428 */

/* Boundary evidence: original MIPS .pdata 40b01428..40b0148b. Semantic name remains unreviewed. */

void FUN_40b01428(int param_1)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    CoTaskMemFree(*(LPVOID *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(int **)(param_1 + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x3c) + 8))();
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40b0148c FUN_40b0148c */

/* Boundary evidence: original MIPS .pdata 40b0148c..40b014a7. Semantic name remains unreviewed. */

void FUN_40b0148c(int param_1)

{
  FUN_40b01428(param_1);
  return;
}



/* 40b014a8 FUN_40b014a8 */

/* Boundary evidence: original MIPS .pdata 40b014a8..40b014e7. Semantic name remains unreviewed. */

void * FUN_40b014a8(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40b014e8 FUN_40b014e8 */

/* Boundary evidence: original MIPS .pdata 40b014e8..40b01533. Semantic name remains unreviewed. */

void * FUN_40b014e8(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40b01428((int)param_1);
    FUN_40b01394(param_1,param_2);
  }
  return param_1;
}



/* 40b01534 FUN_40b01534 */

/* Boundary evidence: original MIPS .pdata 40b01534..40b0155f. Semantic name remains unreviewed. */

void * FUN_40b01534(void *param_1,void *param_2)

{
  FUN_40b014e8(param_1,param_2);
  return param_1;
}



/* 40b01560 FUN_40b01560 */

/* Boundary evidence: original MIPS .pdata 40b01560..40b015cb. Semantic name remains unreviewed. */

undefined4 FUN_40b01560(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40b1696c,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40b1696c,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b015cc FUN_40b015cc */

/* Boundary evidence: original MIPS .pdata 40b015cc..40b016df. Semantic name remains unreviewed. */

undefined4 FUN_40b015cc(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40b1696c,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40b1696c,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40b1696c,0x10);
      if ((iVar1 == 0) ||
         (((iVar1 = memcmp((void *)((int)param_1 + 0x2c),(void *)((int)param_2 + 0x2c),0x10),
           iVar1 == 0 &&
           (_Size = *(size_t *)((int)param_1 + 0x40), _Size == *(size_t *)((int)param_2 + 0x40))) &&
          ((_Size == 0 ||
           (iVar1 = memcmp(*(void **)((int)param_1 + 0x44),*(void **)((int)param_2 + 0x44),_Size),
           iVar1 == 0)))))) {
        return 1;
      }
    }
  }
  return 0;
}



/* 40b016e0 FUN_40b016e0 */

/* Boundary evidence: original MIPS .pdata 40b016e0..40b0171f. Semantic name remains unreviewed. */

void FUN_40b016e0(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40b01428((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40b01720 FUN_40b01720 */

/* Boundary evidence: original MIPS .pdata 40b01720..40b01823. Semantic name remains unreviewed. */

HRESULT FUN_40b01720(LPUNKNOWN param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  HRESULT HVar1;
  int *local_20;
  int *local_1c;
  
  *param_4 = 0;
  HVar1 = CoCreateInstance((IID *)&DAT_40b155d0,param_1,1,(IID *)&DAT_40b1698c,&local_20);
  if (-1 < HVar1) {
    HVar1 = (**(code **)*local_20)(local_20,&UNK_40b16370,&local_1c);
    if (-1 < HVar1) {
      HVar1 = (**(code **)(*local_1c + 0xc))(local_1c,param_2,param_3);
      (**(code **)(*local_1c + 8))();
      if (-1 < HVar1) {
        *param_4 = local_20;
        return 0;
      }
    }
    (**(code **)(*local_20 + 8))();
  }
  return HVar1;
}



/* 40b0188c FUN_40b0188c */

/* Boundary evidence: original MIPS .pdata 40b0188c..40b01917. Semantic name remains unreviewed. */

undefined4 FUN_40b0188c(int param_1,short *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(short **)(param_1 + 0x30) == (short *)0x0) {
      *param_2 = 0;
    }
    else {
      FUN_40b05e4c(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b01918 FUN_40b01918 */

/* Boundary evidence: original MIPS .pdata 40b01918..40b01957. Semantic name remains unreviewed. */

undefined4 FUN_40b01918(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x44) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x44) + 0xc))();
  }
  return uVar1;
}



/* 40b01960 FUN_40b01960 */

/* Boundary evidence: original MIPS .pdata 40b01960..40b019ab. Semantic name remains unreviewed. */

void FUN_40b01960(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40b166d0;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40b061a8(param_1 + 6);
  return;
}



/* 40b019ac FUN_40b019ac */

/* Boundary evidence: original MIPS .pdata 40b019ac..40b01a43. Semantic name remains unreviewed. */

undefined4 FUN_40b019ac(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b16100,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b1698c,0x10), iVar2 == 0)) {
      uVar1 = FUN_40b04b84(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b01a44 FUN_40b01a44 */

/* Boundary evidence: original MIPS .pdata 40b01a44..40b01a5f. Semantic name remains unreviewed. */

void FUN_40b01a44(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40b01a60 FUN_40b01a60 */

/* Boundary evidence: original MIPS .pdata 40b01a60..40b01abb. Semantic name remains unreviewed. */

LONG FUN_40b01a60(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40b01abc FUN_40b01abc */

/* Boundary evidence: original MIPS .pdata 40b01abc..40b01b1b. Semantic name remains unreviewed. */

undefined4 FUN_40b01abc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40b05f58((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40b01b1c FUN_40b01b1c */

/* Boundary evidence: original MIPS .pdata 40b01b1c..40b01b73. Semantic name remains unreviewed. */

undefined4 FUN_40b01b1c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40b01b74 FUN_40b01b74 */

/* Boundary evidence: original MIPS .pdata 40b01b74..40b01c0b. Semantic name remains unreviewed. */

undefined4 FUN_40b01b74(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b16110,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b1698c,0x10), iVar2 == 0)) {
      uVar1 = FUN_40b04b84(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b01c0c FUN_40b01c0c */

/* Boundary evidence: original MIPS .pdata 40b01c0c..40b01c27. Semantic name remains unreviewed. */

void FUN_40b01c0c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40b01c28 FUN_40b01c28 */

/* Boundary evidence: original MIPS .pdata 40b01c28..40b01c83. Semantic name remains unreviewed. */

LONG FUN_40b01c28(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40b01c84 FUN_40b01c84 */

/* Boundary evidence: original MIPS .pdata 40b01c84..40b01cc3. Semantic name remains unreviewed. */

undefined4 FUN_40b01c84(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40b01cc4 FUN_40b01cc4 */

/* Boundary evidence: original MIPS .pdata 40b01cc4..40b01d07. Semantic name remains unreviewed. */

void FUN_40b01cc4(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40b0148c(param_1 + 0x1c);
  FUN_40b04b2c();
  return;
}



/* 40b01d08 FUN_40b01d08 */

/* Boundary evidence: original MIPS .pdata 40b01d08..40b01daf. Semantic name remains unreviewed. */

void FUN_40b01d08(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b160f0,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b16230,0x10);
    if (iVar1 != 0) {
      FUN_40b04c20(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40b04b84(piVar2,param_3);
  return;
}



/* 40b01db0 FUN_40b01db0 */

/* Boundary evidence: original MIPS .pdata 40b01db0..40b01ddb. Semantic name remains unreviewed. */

void FUN_40b01db0(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40b01ddc FUN_40b01ddc */

/* Boundary evidence: original MIPS .pdata 40b01ddc..40b01e07. Semantic name remains unreviewed. */

void FUN_40b01ddc(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40b01e08 FUN_40b01e08 */

/* Boundary evidence: original MIPS .pdata 40b01e08..40b01e27. Semantic name remains unreviewed. */

undefined4 FUN_40b01e08(int param_1,void *param_2)

{
  FUN_40b01534((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40b01e28 FUN_40b01e28 */

/* Boundary evidence: original MIPS .pdata 40b01e28..40b01e7f. Semantic name remains unreviewed. */

undefined4 FUN_40b01e28(int param_1,int *param_2)

{
  undefined4 uVar1;
  int local_10 [2];
  
  (**(code **)(*param_2 + 0x24))(param_2,local_10);
  if (local_10[0] == *(int *)(param_1 + 100)) {
    uVar1 = 0x80040208;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b01e80 FUN_40b01e80 */

undefined4 FUN_40b01e80(void)

{
  return 0;
}



/* 40b01e88 FUN_40b01e88 */

/* Boundary evidence: original MIPS .pdata 40b01e88..40b01edb. Semantic name remains unreviewed. */

undefined4 FUN_40b01e88(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = *(int **)(param_1 + 0xc);
    *param_2 = (int)piVar2;
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x80040209;
    }
    else {
      (**(code **)(*piVar2 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b01edc FUN_40b01edc */

/* Boundary evidence: original MIPS .pdata 40b01edc..40b01f87. Semantic name remains unreviewed. */

undefined4 FUN_40b01edc(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(int *)(param_1 + 100) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 100) + 0xc;
    }
    *param_2 = iVar2;
    if (*(int *)(param_1 + 100) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 100) + 0xc) + 4))();
    }
    if (*(short **)(param_1 + 8) == (short *)0x0) {
      *(undefined2 *)(param_2 + 2) = 0;
    }
    else {
      FUN_40b05e4c((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40b01fb0 FUN_40b01fb0 */

/* Boundary evidence: original MIPS .pdata 40b01fb0..40b01ff7. Semantic name remains unreviewed. */

int FUN_40b01fb0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x20))();
    if (iVar1 < 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}



/* 40b0200c FUN_40b0200c */

/* Boundary evidence: original MIPS .pdata 40b0200c..40b0205b. Semantic name remains unreviewed. */

undefined4 FUN_40b0200c(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b02098 FUN_40b02098 */

/* Boundary evidence: original MIPS .pdata 40b02098..40b020bf. Semantic name remains unreviewed. */

void FUN_40b02098(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40b020c0 FUN_40b020c0 */

/* Boundary evidence: original MIPS .pdata 40b020c0..40b02127. Semantic name remains unreviewed. */

int FUN_40b020c0(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b01e28(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40b161c0,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b02128 FUN_40b02128 */

/* Boundary evidence: original MIPS .pdata 40b02128..40b0218b. Semantic name remains unreviewed. */

undefined4 FUN_40b02128(int param_1)

{
  if (*(int **)(param_1 + 0x98) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x98) + 8))();
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  return 0;
}



/* 40b0218c FUN_40b0218c */

/* Boundary evidence: original MIPS .pdata 40b0218c..40b021c7. Semantic name remains unreviewed. */

void FUN_40b0218c(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40b15770,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b161a0,param_2);
  return;
}



/* 40b021c8 FUN_40b021c8 */

/* Boundary evidence: original MIPS .pdata 40b021c8..40b02353. Semantic name remains unreviewed. */

int FUN_40b021c8(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined1 auStack_28 [8];
  int local_20;
  
  *param_3 = 0;
  memset(auStack_28,0,0x10);
  (**(code **)(*param_2 + 0x14))(param_2,auStack_28);
  if (local_20 == 0) {
    local_20 = 1;
  }
  iVar1 = (**(code **)(*param_2 + 0xc))(param_2,param_3);
  if (((iVar1 < 0) ||
      (iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,*param_3,auStack_28), iVar1 < 0)) ||
     (iVar1 = (**(code **)(*param_2 + 0x10))(param_2,*param_3,0), iVar1 < 0)) {
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 8))();
      *param_3 = 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x48))(param_1,param_3);
    if (((iVar1 < 0) ||
        (iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,*param_3,auStack_28), iVar1 < 0)) ||
       (iVar1 = (**(code **)(*param_2 + 0x10))(param_2,*param_3,0), iVar1 < 0)) {
      if ((int *)*param_3 == (int *)0x0) {
        return iVar1;
      }
      (**(code **)(*(int *)*param_3 + 8))();
      *param_3 = 0;
      return iVar1;
    }
  }
  return 0;
}



/* 40b02354 FUN_40b02354 */

/* Boundary evidence: original MIPS .pdata 40b02354..40b0239b. Semantic name remains unreviewed. */

undefined4 FUN_40b02354(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x98) == (int *)0x0) {
    uVar1 = 0x80004002;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x1c))();
  }
  return uVar1;
}



/* 40b0239c FUN_40b0239c */

/* Boundary evidence: original MIPS .pdata 40b0239c..40b023db. Semantic name remains unreviewed. */

undefined4 FUN_40b0239c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x9c) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x9c) + 0x18))();
  }
  return uVar1;
}



/* 40b023dc FUN_40b023dc */

/* Boundary evidence: original MIPS .pdata 40b023dc..40b0241b. Semantic name remains unreviewed. */

undefined4 FUN_40b023dc(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x38))();
  }
  return uVar1;
}



/* 40b0241c FUN_40b0241c */

/* Boundary evidence: original MIPS .pdata 40b0241c..40b0245b. Semantic name remains unreviewed. */

undefined4 FUN_40b0241c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x98) == 0) {
    uVar1 = 0x8004020a;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x14))();
  }
  return uVar1;
}



/* 40b0245c FUN_40b0245c */

/* Boundary evidence: original MIPS .pdata 40b0245c..40b0249b. Semantic name remains unreviewed. */

undefined4 FUN_40b0245c(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x6c) = 0;
  if (*(int **)(param_1 + 0x98) == (int *)0x0) {
    uVar1 = 0x8004020a;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x18))();
  }
  return uVar1;
}



/* 40b0249c FUN_40b0249c */

/* Boundary evidence: original MIPS .pdata 40b0249c..40b024e7. Semantic name remains unreviewed. */

bool FUN_40b0249c(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40b024e8 FUN_40b024e8 */

/* Boundary evidence: original MIPS .pdata 40b024e8..40b02533. Semantic name remains unreviewed. */

bool FUN_40b024e8(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40b02534 FUN_40b02534 */

/* Boundary evidence: original MIPS .pdata 40b02534..40b02573. Semantic name remains unreviewed. */

undefined4 FUN_40b02534(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x3c))();
  }
  return uVar1;
}



/* 40b02574 FUN_40b02574 */

/* Boundary evidence: original MIPS .pdata 40b02574..40b025b3. Semantic name remains unreviewed. */

undefined4 FUN_40b02574(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x40))();
  }
  return uVar1;
}



/* 40b025b4 FUN_40b025b4 */

/* Boundary evidence: original MIPS .pdata 40b025b4..40b0260f. Semantic name remains unreviewed. */

undefined4 FUN_40b025b4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x44))();
  }
  return uVar1;
}



/* 40b02610 FUN_40b02610 */

/* Boundary evidence: original MIPS .pdata 40b02610..40b02657. Semantic name remains unreviewed. */

void FUN_40b02610(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40b01cc4(param_1);
  return;
}



/* 40b02658 FUN_40b02658 */

/* Boundary evidence: original MIPS .pdata 40b02658..40b026d7. Semantic name remains unreviewed. */

void FUN_40b02658(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b161c0,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b04b84(piVar2,param_3);
  }
  else {
    FUN_40b01d08(param_1,param_2,param_3);
  }
  return;
}



/* 40b026d8 FUN_40b026d8 */

/* Boundary evidence: original MIPS .pdata 40b026d8..40b0279f. Semantic name remains unreviewed. */

HRESULT FUN_40b026d8(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40b15770,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b161a0,ppv),
       -1 < HVar1)) {
      *param_2 = *ppv;
      (**(code **)(*(int *)*ppv + 4))();
      HVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
    return HVar1;
  }
  return -0x7fffbffd;
}



/* 40b027a0 FUN_40b027a0 */

/* Boundary evidence: original MIPS .pdata 40b027a0..40b0283f. Semantic name remains unreviewed. */

undefined4 FUN_40b027a0(int param_1,int *param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    piVar2 = *(int **)(param_1 + 4);
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 4) = param_2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(undefined1 *)(param_1 + 8) = param_3;
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b02840 FUN_40b02840 */

/* Boundary evidence: original MIPS .pdata 40b02840..40b02ac7. Semantic name remains unreviewed. */

int FUN_40b02840(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *local_20 [2];
  
  if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    piVar3 = (int *)(param_1 + -0x98);
    iVar2 = (**(code **)(*piVar3 + 0x38))(piVar3);
    if (iVar2 == 0) {
      iVar2 = (**(code **)*param_2)(param_2,&UNK_40b16190,local_20);
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 0x10) = 0x30;
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x30) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
        iVar2 = (**(code **)(*param_2 + 0x3c))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 4;
        }
        iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 2;
        }
        iVar2 = (**(code **)(*param_2 + 0x1c))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1;
        }
        iVar2 = (**(code **)(*param_2 + 0x14))
                          (param_2,(undefined4 *)(param_1 + 0x20),(undefined4 *)(param_1 + 0x28));
        if (iVar2 < 0) {
          *(undefined4 *)(param_1 + 0x20) = 0;
          *(undefined4 *)(param_1 + 0x24) = 0;
          *(undefined4 *)(param_1 + 0x28) = 0;
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        else {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x110;
        }
        iVar2 = (**(code **)(*param_2 + 0x34))(param_2,param_1 + 0x34);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
        }
        (**(code **)(*param_2 + 0xc))(param_2,param_1 + 0x38);
        uVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
        *(undefined4 *)(param_1 + 0x1c) = uVar1;
        uVar1 = (**(code **)(*param_2 + 0x10))(param_2);
        *(undefined4 *)(param_1 + 0x3c) = uVar1;
      }
      else {
        iVar2 = (**(code **)(*local_20[0] + 0x4c))(local_20[0],0x30,param_1 + 0x10);
        (**(code **)(*local_20[0] + 8))();
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      if (((*(uint *)(param_1 + 0x18) & 8) == 0) ||
         (iVar2 = (**(code **)(*piVar3 + 0x20))(piVar3,*(undefined4 *)(param_1 + 0x34)), iVar2 == 0)
         ) {
        iVar2 = 0;
      }
      else {
        *(undefined4 *)(param_1 + -0x2c) = 1;
        (**(code **)(*(int *)(param_1 + -0x8c) + 0x38))();
        piVar3 = *(int **)(*(int *)(param_1 + -0x28) + 0x44);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0xc))(piVar3,3,0x8004022a,0);
        }
        iVar2 = -0x7ffbfe00;
      }
    }
  }
  return iVar2;
}



/* 40b02ac8 FUN_40b02ac8 */

/* Boundary evidence: original MIPS .pdata 40b02ac8..40b02b63. Semantic name remains unreviewed. */

int FUN_40b02ac8(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    while (iVar1 = 0, 0 < param_3) {
      param_3 = param_3 + -1;
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,*(undefined4 *)(*param_4 * 4 + param_2));
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_4 = *param_4 + 1;
    }
  }
  return iVar1;
}



/* 40b02b64 FUN_40b02b64 */

/* Boundary evidence: original MIPS .pdata 40b02b64..40b02cc3. Semantic name remains unreviewed. */

int FUN_40b02b64(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *local_30;
  int *local_2c;
  int local_28 [2];
  
  iVar1 = (**(code **)(**(int **)(param_1 + -0x28) + 0x18))();
  iVar5 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = (**(code **)(**(int **)(param_1 + -0x28) + 0x1c))(*(int **)(param_1 + -0x28),iVar4);
      piVar3 = (int *)(iVar2 + 0xc);
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,local_28);
      if (iVar2 < 0) {
        return iVar2;
      }
      if ((local_28[0] == 1) &&
         (iVar2 = (**(code **)(*piVar3 + 0x18))(piVar3,&local_30), -1 < iVar2)) {
        iVar5 = iVar5 + 1;
        iVar2 = (**(code **)*local_30)(local_30,&DAT_40b161c0,&local_2c);
        (**(code **)(*local_30 + 8))();
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = (**(code **)(*local_2c + 0x20))();
        (**(code **)(*local_2c + 8))();
        if (iVar2 != 1) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
    if (iVar5 != 0) {
      return 1;
    }
  }
  return 0;
}



/* 40b02cc4 FUN_40b02cc4 */

/* Boundary evidence: original MIPS .pdata 40b02cc4..40b02d0b. Semantic name remains unreviewed. */

undefined4 FUN_40b02cc4(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b02d0c FUN_40b02d0c */

/* Boundary evidence: original MIPS .pdata 40b02d0c..40b02d4f. Semantic name remains unreviewed. */

undefined4 FUN_40b02d0c(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b02d70 FUN_40b02d70 */

/* Boundary evidence: original MIPS .pdata 40b02d70..40b02daf. Semantic name remains unreviewed. */

undefined4 FUN_40b02d70(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x8004020a;
  }
  else {
    *(undefined1 *)(param_1 + 0xa1) = 0;
    uVar1 = (**(code **)(*piVar2 + 0x18))(piVar2);
  }
  return uVar1;
}



/* 40b02e04 FUN_40b02e04 */

/* Boundary evidence: original MIPS .pdata 40b02e04..40b0305b. Semantic name remains unreviewed. */

int FUN_40b02e04(undefined4 *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 1;
  }
  else {
    puVar2 = (undefined4 *)*param_1;
    iVar1 = (**(code **)(*param_2 + 0x1c))(param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    if (param_3 != 0) {
      puVar2 = (undefined4 *)*param_1;
      iVar1 = (**(code **)(*param_2 + 0xc))
                        (param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3],param_1[1],param_1[2]);
      if ((-1 < iVar1) && (uVar7 = 0, param_1[3] != 0)) {
        iVar6 = 0;
        while( true ) {
          puVar5 = (undefined4 *)*param_1;
          iVar1 = param_1[4] + iVar6;
          puVar2 = *(undefined4 **)(iVar1 + 0x14);
          puVar4 = (undefined4 *)(param_1[4] + iVar6);
          iVar1 = (**(code **)(*param_2 + 0x14))
                            (param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3],*puVar4,puVar4[1],
                             puVar4[2],puVar4[3],puVar4[4],*puVar2,puVar2[1],puVar2[2],puVar2[3],
                             *(undefined4 *)(iVar1 + 0x18));
          if (iVar1 < 0) break;
          iVar3 = param_1[4];
          uVar8 = 0;
          if (*(int *)(iVar6 + iVar3 + 0x1c) != 0) {
            iVar9 = 0;
            do {
              puVar5 = (undefined4 *)*param_1;
              puVar2 = (undefined4 *)(((undefined4 *)(iVar6 + iVar3))[8] + iVar9);
              puVar4 = (undefined4 *)puVar2[1];
              puVar2 = (undefined4 *)*puVar2;
              iVar1 = (**(code **)(*param_2 + 0x18))
                                (param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3],
                                 *(undefined4 *)(iVar6 + iVar3),*puVar2,puVar2[1],puVar2[2],
                                 puVar2[3],*puVar4,puVar4[1],puVar4[2],puVar4[3]);
              if (iVar1 < 0) goto LAB_40b03024;
              iVar3 = param_1[4];
              uVar8 = uVar8 + 1;
              iVar9 = iVar9 + 8;
            } while (uVar8 < *(uint *)(iVar6 + iVar3 + 0x1c));
          }
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + 0x24;
          if ((uint)param_1[3] <= uVar7) break;
        }
      }
    }
LAB_40b03024:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40b0305c FUN_40b0305c */

/* Boundary evidence: original MIPS .pdata 40b0305c..40b0313b. Semantic name remains unreviewed. */

void FUN_40b0305c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b16150,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40b16140,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40b1699c,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b161d0,0x10);
    if (iVar1 != 0) {
      FUN_40b04c20(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40b04b84(piVar2,param_3);
  return;
}



/* 40b0313c FUN_40b0313c */

/* Boundary evidence: original MIPS .pdata 40b0313c..40b03197. Semantic name remains unreviewed. */

void FUN_40b0313c(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40b04b2c();
  return;
}



/* 40b03198 FUN_40b03198 */

/* Boundary evidence: original MIPS .pdata 40b03198..40b0321b. Semantic name remains unreviewed. */

undefined4 FUN_40b03198(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  }
  *(int **)(param_1 + 0xc) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b0321c FUN_40b0321c */

/* Boundary evidence: original MIPS .pdata 40b0321c..40b0329f. Semantic name remains unreviewed. */

undefined4 FUN_40b0321c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int **)(param_1 + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 4))();
    }
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b032a0 FUN_40b032a0 */

/* Boundary evidence: original MIPS .pdata 40b032a0..40b03327. Semantic name remains unreviewed. */

int FUN_40b032a0(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar1 = -0x7ffbfded;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))(*(int **)(param_1 + 0x18),param_2);
    if (-1 < iVar1) {
      uVar2 = *(uint *)(param_1 + 0x20);
      uVar3 = *param_2;
      iVar4 = *(int *)(param_1 + 0x24);
      iVar1 = 0;
      *param_2 = uVar3 - uVar2;
      param_2[1] = (param_2[1] - iVar4) - (uint)(uVar3 < uVar2);
    }
  }
  return iVar1;
}



/* 40b03328 FUN_40b03328 */

/* Boundary evidence: original MIPS .pdata 40b03328..40b0343f. Semantic name remains unreviewed. */

undefined4 FUN_40b03328(int param_1,LPCWSTR param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar6;
  
  if (param_3 == (int *)0x0) {
    uVar4 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
    EnterCriticalSection(lpCriticalSection);
    piVar6 = (int *)(param_1 + -0xc);
    iVar1 = (**(code **)(*piVar6 + 0x18))(piVar6);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = (**(code **)(*piVar6 + 0x1c))(piVar6,iVar5);
        iVar3 = lstrcmpW(*(LPCWSTR *)(iVar2 + 0x14),param_2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar4 = 0;
          goto LAB_40b033e8;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40b033e8:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40b03440 FUN_40b03440 */

/* Boundary evidence: original MIPS .pdata 40b03440..40b0355b. Semantic name remains unreviewed. */

undefined4 FUN_40b03440(int param_1,undefined4 *param_2,wchar_t *param_3)

{
  int iVar1;
  size_t sVar2;
  void *_Dst;
  uint uVar3;
  uint uVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 **)(param_1 + 0x34) = param_2;
  if (param_2 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  else {
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40b16260,(undefined4 *)(param_1 + 0x38));
    if (-1 < iVar1) {
      (**(code **)(**(int **)(param_1 + 0x38) + 8))();
    }
  }
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (param_3 != (wchar_t *)0x0) {
    sVar2 = wcslen(param_3);
    uVar4 = sVar2 + 1;
    if (uVar4 < 0x80000000) {
      uVar3 = uVar4 * 2;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Dst = operator_new(uVar3);
    *(void **)(param_1 + 0x30) = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_3,uVar4 * 2);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b0355c FUN_40b0355c */

/* Boundary evidence: original MIPS .pdata 40b0355c..40b0362f. Semantic name remains unreviewed. */

undefined4 FUN_40b0355c(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  HRESULT HVar3;
  int *local_10 [2];
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_1 + -0x10) + 0x20))();
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 1;
  }
  else {
    CoInitializeEx((LPVOID)0x0,0);
    HVar3 = CoCreateInstance((IID *)&DAT_40b15230,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b16220,local_10);
    if (-1 < HVar3) {
      FUN_40b02e04(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b03630 FUN_40b03630 */

/* Boundary evidence: original MIPS .pdata 40b03630..40b03723. Semantic name remains unreviewed. */

int FUN_40b03630(int param_1)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  int *local_18 [2];
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_1 + -0x10) + 0x20))();
  if (puVar1 == (undefined4 *)0x0) {
    HVar2 = 1;
  }
  else {
    CoInitializeEx((LPVOID)0x0,0);
    HVar2 = CoCreateInstance((IID *)&DAT_40b15230,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b16220,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40b02e04(puVar1,local_18[0],0);
      (**(code **)(*local_18[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    if (HVar2 == -0x7ff8fffe) {
      HVar2 = 0;
    }
  }
  return HVar2;
}



/* 40b03724 FUN_40b03724 */

/* Boundary evidence: original MIPS .pdata 40b03724..40b0376f. Semantic name remains unreviewed. */

undefined4 * FUN_40b03724(undefined4 *param_1,uint param_2)

{
  FUN_40b01960(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b03770 FUN_40b03770 */

/* Boundary evidence: original MIPS .pdata 40b03770..40b03907. Semantic name remains unreviewed. */

undefined4 FUN_40b03770(int param_1,uint param_2,int *param_3,uint *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_3 == (int *)0x0) {
    uVar4 = 0x80004003;
  }
  else {
    if (param_4 == (uint *)0x0) {
      if (1 < param_2) {
        return 0x80070057;
      }
    }
    else {
      *param_4 = 0;
    }
    uVar6 = 0;
    bVar1 = FUN_40b0249c(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40b01b1c(param_1);
    }
    uVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    if ((int)param_2 <= (int)uVar5) {
      uVar5 = param_2;
    }
    if (uVar5 != 0) {
      do {
        if (*(int *)(param_1 + 8) == *(int *)(param_1 + 4)) break;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))();
        if (iVar2 == 0) {
          return 0x80040203;
        }
        iVar3 = FUN_40b05fac((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40b060ac((int *)(param_1 + 0x18),iVar2);
          uVar5 = uVar5 - 1;
        }
      } while (uVar5 != 0);
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar6;
      }
      if (param_2 == uVar6) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



/* 40b03908 FUN_40b03908 */

/* Boundary evidence: original MIPS .pdata 40b03908..40b03983. Semantic name remains unreviewed. */

undefined4 FUN_40b03908(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40b0249c(param_1);
  uVar2 = 1;
  if (CONCAT31(extraout_var,bVar1) == 1) {
    uVar2 = 0x80040203;
  }
  else if ((uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) < param_2) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 8);
  }
  else {
    *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b03984 FUN_40b03984 */

/* Boundary evidence: original MIPS .pdata 40b03984..40b039e7. Semantic name remains unreviewed. */

undefined4 * FUN_40b03984(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40b166f0;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b039e8 FUN_40b039e8 */

/* Boundary evidence: original MIPS .pdata 40b039e8..40b03b7b. Semantic name remains unreviewed. */

uint FUN_40b039e8(int param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  LPVOID _Dst;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_70 [60];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  local_28 = DAT_40b17224;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40b06410(DAT_40b17224);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40b024e8(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40b06410(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40b06410(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40b014a8(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40b03b28:
          FUN_40b0148c((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40b03b28;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40b0148c((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40b06410(local_28);
    }
  }
  return uVar3;
}



/* 40b03b7c FUN_40b03b7c */

/* Boundary evidence: original MIPS .pdata 40b03b7c..40b03c33. Semantic name remains unreviewed. */

uint FUN_40b03b7c(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40b17224;
  bVar1 = FUN_40b024e8(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40b06410(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40b014a8(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40b0148c((int)auStack_60);
    FUN_40b06410(local_18);
  }
  return uVar3;
}



/* 40b03c34 FUN_40b03c34 */

/* Boundary evidence: original MIPS .pdata 40b03c34..40b03dab. Semantic name remains unreviewed. */

int FUN_40b03c34(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2);
  if (iVar1 < 0) {
    (**(code **)(*param_1 + 0x2c))();
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x20))(param_1,param_3);
    if (iVar1 == 0) {
      param_1[6] = (int)param_2;
      (**(code **)(*param_2 + 4))(param_2);
      (**(code **)(*param_1 + 0x24))(param_1,param_3);
      iVar1 = (**(code **)(*param_2 + 0x10))(param_2,param_1 + 3,param_3);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
        (**(code **)(*param_2 + 0x14))(param_2);
      }
    }
    else if (((-1 < iVar1) || (iVar1 == -0x7fffbffb)) || (iVar1 == -0x7ff8ffa9)) {
      iVar1 = -0x7ffbfdd6;
    }
    (**(code **)(*param_1 + 0x2c))(param_1);
    if ((int *)param_1[6] != (int *)0x0) {
      (**(code **)(*(int *)param_1[6] + 8))();
      param_1[6] = 0;
    }
  }
  return iVar1;
}



/* 40b03dac FUN_40b03dac */

/* Boundary evidence: original MIPS .pdata 40b03dac..40b03f1f. Semantic name remains unreviewed. */

int FUN_40b03dac(int *param_1,int *param_2,void *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_28;
  undefined4 local_24;
  
  iVar1 = (**(code **)(*param_4 + 0x14))(param_4);
  if (-1 < iVar1) {
    iVar1 = 0;
    local_28 = (void *)0x0;
    local_24 = 0;
    iVar2 = (**(code **)(*param_4 + 0xc))(param_4,1,&local_28,&local_24);
    if (iVar2 == 0) {
      do {
        if ((((param_3 == (void *)0x0) ||
             (iVar3 = FUN_40b015cc(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40b03c34(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40b016e0(local_28);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = (**(code **)(*param_4 + 0xc))(param_4,1,&local_28,&local_24);
      } while (iVar2 == 0);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = -0x7ffbfdf9;
  }
  return iVar1;
}



/* 40b03f20 FUN_40b03f20 */

/* Boundary evidence: original MIPS .pdata 40b03f20..40b040a7. Semantic name remains unreviewed. */

int FUN_40b03f20(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40b01560(param_3), iVar1 == 0)) {
    iVar1 = FUN_40b03c34(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40b03dac(param_1,param_2,param_3,local_30[0]);
    (**(code **)(*local_30[0] + 8))();
    if (-1 < iVar2) {
      return 0;
    }
    if (((iVar2 != -0x7fffbffb) && (iVar2 != -0x7ff8ffa9)) && (iVar2 != -0x7ffbfdd6)) {
      iVar1 = iVar2;
    }
  }
  iVar2 = (**(code **)(param_1[3] + 0x30))(param_1 + 3,local_30);
  if (iVar2 < 0) {
    return iVar1;
  }
  iVar2 = FUN_40b03dac(param_1,param_2,param_3,local_30[0]);
  (**(code **)(*local_30[0] + 8))();
  if (-1 < iVar2) {
    return 0;
  }
  if (iVar2 == -0x7fffbffb) {
    return iVar1;
  }
  if (iVar2 == -0x7ff8ffa9) {
    return iVar1;
  }
  if (iVar2 != -0x7ffbfdd6) {
    return iVar2;
  }
  return iVar1;
}



/* 40b040a8 FUN_40b040a8 */

/* Boundary evidence: original MIPS .pdata 40b040a8..40b0426f. Semantic name remains unreviewed. */

int FUN_40b040a8(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if ((param_2 == (int *)0x0) || (param_3 == 0)) {
    return -0x7fffbffd;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 0xc) == 0) {
    if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
      piVar3 = (int *)(param_1 + -0xc);
      iVar2 = (**(code **)(*piVar3 + 0x28))(piVar3,param_2);
      iVar1 = *piVar3;
      if (-1 < iVar2) {
        iVar2 = (**(code **)(iVar1 + 0x20))(piVar3,param_3);
        if (iVar2 != 0) {
          (**(code **)(*piVar3 + 0x2c))(piVar3);
          if (((-1 < iVar2) || (iVar2 == -0x7fffbffb)) || (iVar2 == -0x7ff8ffa9)) {
            iVar2 = -0x7ffbfdd6;
          }
          goto LAB_40b04240;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40b04240;
        }
        (**(code **)(**(int **)(param_1 + 0xc) + 8))();
        iVar1 = *piVar3;
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
      (**(code **)(iVar1 + 0x2c))(piVar3);
    }
    else {
      iVar2 = -0x7ffbfddc;
    }
  }
  else {
    iVar2 = -0x7ffbfdfc;
  }
LAB_40b04240:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40b04270 FUN_40b04270 */

/* Boundary evidence: original MIPS .pdata 40b04270..40b0430f. Semantic name remains unreviewed. */

undefined4 FUN_40b04270(int param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      uVar1 = 1;
    }
    else {
      (**(code **)(*(int *)(param_1 + -0xc) + 0x2c))();
      (**(code **)(**(int **)(param_1 + 0xc) + 8))();
      *(undefined4 *)(param_1 + 0xc) = 0;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80040224;
  }
  LeaveCriticalSection(lpCriticalSection);
  return uVar1;
}



/* 40b04310 FUN_40b04310 */

/* Boundary evidence: original MIPS .pdata 40b04310..40b0439b. Semantic name remains unreviewed. */

undefined4 FUN_40b04310(int param_1,void *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (void *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(param_1 + 0xc) == 0) {
      FUN_40b01358(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40b01394(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40b0439c FUN_40b0439c */

/* Boundary evidence: original MIPS .pdata 40b0439c..40b043b7. Semantic name remains unreviewed. */

void FUN_40b0439c(int param_1,undefined4 *param_2)

{
  FUN_40b05e88(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40b043b8 FUN_40b043b8 */

/* Boundary evidence: original MIPS .pdata 40b043b8..40b04433. Semantic name remains unreviewed. */

int FUN_40b043b8(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40b04270(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40b04434 FUN_40b04434 */

/* Boundary evidence: original MIPS .pdata 40b04434..40b04513. Semantic name remains unreviewed. */

undefined4 * FUN_40b04434(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40b166d0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40b05f34(param_1 + 6);
  (**(code **)(*(int *)(param_1[3] + 0xc) + 4))();
  if (param_3 == 0) {
    uVar1 = (**(code **)(*(int *)param_1[3] + 0x14))();
    param_1[4] = uVar1;
    uVar1 = (**(code **)(*(int *)param_1[3] + 0x18))();
    param_1[2] = uVar1;
  }
  else {
    param_1[1] = *(undefined4 *)(param_3 + 4);
    param_1[2] = *(undefined4 *)(param_3 + 8);
    param_1[4] = *(undefined4 *)(param_3 + 0x10);
    FUN_40b06148(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40b04514 FUN_40b04514 */

/* Boundary evidence: original MIPS .pdata 40b04514..40b045bf. Semantic name remains unreviewed. */

undefined4 FUN_40b04514(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    uVar3 = 0;
    bVar1 = FUN_40b0249c(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      uVar3 = 0x80040203;
      *param_2 = 0;
    }
    else {
      puVar2 = operator_new(0x30);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40b04434(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40b045c0 FUN_40b045c0 */

/* Boundary evidence: original MIPS .pdata 40b045c0..40b0464f. Semantic name remains unreviewed. */

undefined4 * FUN_40b045c0(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40b166f0;
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[4] = 1;
  (**(code **)(*(int *)(param_2 + 0xc) + 4))();
  if (param_3 == 0) {
    uVar1 = (**(code **)(*(int *)param_1[2] + 0x10))();
    param_1[3] = uVar1;
  }
  else {
    param_1[1] = *(undefined4 *)(param_3 + 4);
    param_1[3] = *(undefined4 *)(param_3 + 0xc);
  }
  return param_1;
}



/* 40b04650 FUN_40b04650 */

/* Boundary evidence: original MIPS .pdata 40b04650..40b046fb. Semantic name remains unreviewed. */

undefined4 FUN_40b04650(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    uVar3 = 0;
    bVar1 = FUN_40b024e8(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      uVar3 = 0x80040203;
      *param_2 = 0;
    }
    else {
      puVar2 = operator_new(0x14);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40b045c0(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40b046fc FUN_40b046fc */

/* Boundary evidence: original MIPS .pdata 40b046fc..40b047ef. Semantic name remains unreviewed. */

undefined4 *
FUN_40b046fc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40b04bc4(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40b014a8(param_1 + 7);
  param_1[0x1c] = param_3;
  param_1[0x1e] = 1;
  param_1[0x19] = param_7;
  param_1[0x1a] = param_4;
  param_1[0x1b] = 0;
  param_1[0x1d] = 0;
  uVar3 = 0xffffffff;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0xffffffff;
  param_1[0x23] = 0x7fffffff;
  param_1[0x24] = 0;
  param_1[0x25] = 0x3ff00000;
  if (param_6 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_6);
    uVar2 = sVar1 + 1;
    if (uVar2 < 0x80000000) {
      uVar3 = uVar2 * 2;
    }
    _Dst = operator_new(uVar3);
    param_1[5] = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_6,uVar2 * 2);
    }
  }
  return param_1;
}



/* 40b047f0 FUN_40b047f0 */

/* Boundary evidence: original MIPS .pdata 40b047f0..40b048cf. Semantic name remains unreviewed. */

int FUN_40b047f0(int param_1,int *param_2,void *param_3)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar2;
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(param_1 + 0xc) == 0) {
      if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
        piVar2 = (int *)(param_1 + -0xc);
        iVar1 = FUN_40b03f20(piVar2,param_2,param_3);
        if (iVar1 < 0) {
          (**(code **)(*piVar2 + 0x2c))(piVar2);
        }
        else {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -0x7ffbfddc;
      }
    }
    else {
      iVar1 = -0x7ffbfdfc;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40b048d0 FUN_40b048d0 */

/* Boundary evidence: original MIPS .pdata 40b048d0..40b0494f. Semantic name remains unreviewed. */

undefined4 FUN_40b048d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puVar2 = operator_new(0x14);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40b045c0(puVar2,param_1 + -0xc,0);
    }
    *param_2 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b04950 FUN_40b04950 */

/* Boundary evidence: original MIPS .pdata 40b04950..40b0499b. Semantic name remains unreviewed. */

undefined4 *
FUN_40b04950(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40b046fc(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40b0499c FUN_40b0499c */

/* Boundary evidence: original MIPS .pdata 40b0499c..40b049f7. Semantic name remains unreviewed. */

undefined4 *
FUN_40b0499c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40b046fc(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40b049f8 FUN_40b049f8 */

/* Boundary evidence: original MIPS .pdata 40b049f8..40b04a7b. Semantic name remains unreviewed. */

undefined4 *
FUN_40b049f8(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40b04bc4(param_1,param_2,param_3);
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = *param_5;
  param_1[0xb] = param_5[1];
  param_1[0xc] = param_5[2];
  uVar1 = param_5[3];
  param_1[0xe] = param_4;
  param_1[0xd] = uVar1;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 1;
  return param_1;
}



/* 40b04a7c FUN_40b04a7c */

/* Boundary evidence: original MIPS .pdata 40b04a7c..40b04afb. Semantic name remains unreviewed. */

undefined4 FUN_40b04a7c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puVar2 = operator_new(0x30);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40b04434(puVar2,param_1 + -0xc,0);
    }
    *param_2 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b04afc FUN_40b04afc */

/* Boundary evidence: original MIPS .pdata 40b04afc..40b04b2b. Semantic name remains unreviewed. */

undefined4 FUN_40b04afc(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40b17794);
  return param_1;
}



/* 40b04b2c FUN_40b04b2c */

/* Boundary evidence: original MIPS .pdata 40b04b2c..40b04b83. Semantic name remains unreviewed. */

void FUN_40b04b2c(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40b17794);
  if ((LVar1 == 0) && (DAT_40b17790 != 0)) {
    FreeLibrary((HMODULE)DAT_40b17790);
    DAT_40b17790 = 0;
  }
  return;
}



/* 40b04b84 FUN_40b04b84 */

/* Boundary evidence: original MIPS .pdata 40b04b84..40b04bc3. Semantic name remains unreviewed. */

undefined4 FUN_40b04b84(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = param_1;
    (**(code **)(*param_1 + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b04bc4 FUN_40b04bc4 */

/* Boundary evidence: original MIPS .pdata 40b04bc4..40b04c1f. Semantic name remains unreviewed. */

undefined4 * FUN_40b04bc4(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40b1672c;
  InterlockedIncrement(&DAT_40b17794);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40b04c20 FUN_40b04c20 */

/* Boundary evidence: original MIPS .pdata 40b04c20..40b04ca3. Semantic name remains unreviewed. */

undefined4 FUN_40b04c20(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b1698c,0x10);
    if (iVar2 == 0) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar1 = 0;
    }
    else {
      *param_3 = 0;
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b04ca4 FUN_40b04ca4 */

/* Boundary evidence: original MIPS .pdata 40b04ca4..40b04cdf. Semantic name remains unreviewed. */

uint FUN_40b04ca4(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40b04ce0 FUN_40b04ce0 */

/* Boundary evidence: original MIPS .pdata 40b04ce0..40b04d57. Semantic name remains unreviewed. */

uint FUN_40b04ce0(int *param_1)

{
  LONG LVar1;
  uint uVar2;
  uint *lpAddend;
  
  lpAddend = (uint *)(param_1 + 2);
  LVar1 = InterlockedDecrement((LONG *)lpAddend);
  if (LVar1 == 0) {
    *lpAddend = *lpAddend + 1;
    (**(code **)(*param_1 + 0xc))(param_1,1);
    uVar2 = 0;
  }
  else {
    uVar2 = *lpAddend;
    if (uVar2 < 2) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 40b04d58 FUN_40b04d58 */

/* Boundary evidence: original MIPS .pdata 40b04d58..40b04d9b. Semantic name remains unreviewed. */

void FUN_40b04d58(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x28),*(int *)(param_1 + 0x3c),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40b04d9c FUN_40b04d9c */

/* Boundary evidence: original MIPS .pdata 40b04d9c..40b04e5f. Semantic name remains unreviewed. */

void FUN_40b04d9c(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
    EnterCriticalSection(param_1);
    iVar1 = param_1[3].RecursionCount;
    param_1[2].LockSemaphore = (HANDLE)0x1;
    if (iVar1 == 0) {
      param_1[3].RecursionCount = 1;
    }
  }
  else {
    EnterCriticalSection(param_1);
    iVar1 = param_1[3].RecursionCount;
    param_1[2].LockSemaphore = (HANDLE)0x1;
    if (iVar1 == 0) {
      param_1[3].RecursionCount = 1;
    }
    if (param_1[2].SpinCount == 0) {
      EventModify(param_1[1].SpinCount,2);
      FUN_40b04d58((int)param_1);
      LeaveCriticalSection(param_1);
      (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
      return;
    }
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40b04e60 FUN_40b04e60 */

/* Boundary evidence: original MIPS .pdata 40b04e60..40b04eb7. Semantic name remains unreviewed. */

void FUN_40b04e60(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_40b060ac(*(undefined4 **)(param_1 + 0x24),param_2);
  if ((puVar1 == (undefined4 *)0x0) && (param_2 < (int *)0xfffffff1)) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



/* 40b04eb8 FUN_40b04eb8 */

/* Boundary evidence: original MIPS .pdata 40b04eb8..40b05157. Semantic name remains unreviewed. */

LONG FUN_40b04eb8(LPCRITICAL_SECTION param_1,undefined4 *param_2,int param_3,int *param_4)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30 [2];
  
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      iVar3 = 0;
      iVar2 = 0;
      do {
        if (iVar2 < param_3) {
          *(undefined4 *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = *param_2;
          param_2 = param_2 + 1;
          iVar2 = iVar2 + 1;
          param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
        }
        else if ((param_1[2].RecursionCount == 0) || (param_1[3].LockCount == 0)) goto LAB_40b04f78;
        if ((param_1[2].RecursionCount == param_1[1].RecursionCount) ||
           ((param_3 == 0 && ((param_1[3].LockCount != 0 || (param_1[1].LockCount == 0)))))) {
          if (param_1[3].RecursionCount == 0) {
            LVar1 = (**(code **)(*(int *)param_1[1].DebugInfo + 0x1c))
                              (param_1[1].DebugInfo,param_1[2].LockCount,param_1[2].RecursionCount,
                               local_30);
            param_1[3].RecursionCount = LVar1;
          }
          else {
            local_30[0] = 0;
          }
          iVar3 = (param_1[2].RecursionCount - local_30[0]) + iVar3;
          iVar5 = 0;
          if (0 < param_1[2].RecursionCount) {
            iVar4 = 0;
            do {
              (**(code **)(**(int **)(iVar4 + param_1[2].LockCount) + 8))();
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 4;
            } while (iVar5 < param_1[2].RecursionCount);
          }
          param_1[2].RecursionCount = 0;
        }
      } while( true );
    }
    *param_4 = 0;
    if (0 < param_3) {
      do {
        (**(code **)(*(int *)*param_2 + 8))();
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  else {
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      iVar2 = param_3;
      if (0 < param_3) {
        do {
          FUN_40b04e60((int)param_1,(int *)*param_2);
          param_2 = param_2 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      *param_4 = param_3;
      if ((param_1[1].LockCount == 0) ||
         (param_1[1].RecursionCount <=
          param_1[2].RecursionCount + *(int *)((int)param_1[1].OwningThread + 8))) {
        FUN_40b04d58((int)param_1);
      }
      LVar1 = 0;
      goto LAB_40b05120;
    }
    *param_4 = 0;
    if (0 < param_3) {
      do {
        (**(code **)(*(int *)*param_2 + 8))();
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  goto LAB_40b04f88;
LAB_40b04f78:
  *param_4 = iVar2 - iVar3;
  if (iVar2 - iVar3 < 0) {
    *param_4 = 0;
  }
LAB_40b04f88:
  LVar1 = param_1[3].RecursionCount;
LAB_40b05120:
  LeaveCriticalSection(param_1);
  return LVar1;
}



/* 40b05158 FUN_40b05158 */

/* Boundary evidence: original MIPS .pdata 40b05158..40b0524f. Semantic name remains unreviewed. */

void FUN_40b05158(LPCRITICAL_SECTION param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  EnterCriticalSection(param_1);
  piVar2 = param_1[1].OwningThread;
  if (piVar2 != (int *)0x0) {
    while (piVar2 = (int *)FUN_40b061f0(piVar2), piVar2 != (int *)0x0) {
      if (piVar2 < (int *)0xfffffff1) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      else if (piVar2 == (int *)0xfffffffb) {
        pvVar1 = (void *)FUN_40b061f0(param_1[1].OwningThread);
        operator_delete(pvVar1);
      }
      piVar2 = param_1[1].OwningThread;
    }
  }
  iVar3 = 0;
  if (0 < param_1[2].RecursionCount) {
    iVar4 = 0;
    do {
      (**(code **)(**(int **)(iVar4 + param_1[2].LockCount) + 8))();
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 < param_1[2].RecursionCount);
  }
  param_1[2].RecursionCount = 0;
  LeaveCriticalSection(param_1);
  return;
}



/* 40b05250 FUN_40b05250 */

/* Boundary evidence: original MIPS .pdata 40b05250..40b0534b. Semantic name remains unreviewed. */

void FUN_40b05250(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  
  if (param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    (**(code **)(*(int *)param_1[1].DebugInfo + 8))();
  }
  if (param_1[2].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    FUN_40b05158(param_1);
  }
  else {
    EnterCriticalSection(param_1);
    param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1;
    param_1[3].RecursionCount = 1;
    FUN_40b04d58((int)param_1);
    LeaveCriticalSection(param_1);
    WaitForSingleObject(param_1[2].DebugInfo,0xffffffff);
    CloseHandle(param_1[2].DebugInfo);
    puVar1 = param_1[1].OwningThread;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_40b061a8(puVar1);
      operator_delete(puVar1);
    }
  }
  if (param_1[1].LockSemaphore != (HANDLE)0x0) {
    CloseHandle(param_1[1].LockSemaphore);
  }
  operator_delete((void *)param_1[2].LockCount);
  FUN_40b05da8(&param_1[1].SpinCount);
  DeleteCriticalSection(param_1);
  return;
}



/* 40b0534c FUN_40b0534c */

/* Boundary evidence: original MIPS .pdata 40b0534c..40b05623. Semantic name remains unreviewed. */

undefined4 FUN_40b0534c(LPCRITICAL_SECTION param_1)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  LONG LVar4;
  ULONG_PTR UVar5;
  void *pvVar6;
  int iVar7;
  void *local_28 [2];
  
  pvVar6 = local_28[0];
  pvVar3 = local_28[0];
LAB_40b05388:
  do {
    bVar1 = false;
    EnterCriticalSection(param_1);
    do {
      while( true ) {
        if (param_1[3].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
          FUN_40b05158(param_1);
          LeaveCriticalSection(param_1);
          return 0;
        }
        if (param_1[2].LockSemaphore != (HANDLE)0x0) {
          FUN_40b05158(param_1);
          EventModify(param_1[1].SpinCount,3);
        }
        uVar2 = FUN_40b061f0(param_1[1].OwningThread);
        if (uVar2 != 0) break;
        if ((param_1[1].LockCount != 0) || (param_1[2].RecursionCount == 0)) {
          param_1[2].OwningThread = (HANDLE)((int)param_1[2].OwningThread + 1);
          bVar1 = true;
          goto LAB_40b0549c;
        }
LAB_40b05448:
        if (uVar2 != 0xfffffffe) {
          if (uVar2 == 0xfffffffb) {
            pvVar3 = (void *)FUN_40b061f0(param_1[1].OwningThread);
          }
          goto LAB_40b05480;
        }
        if (param_1[2].RecursionCount != 0) goto LAB_40b05480;
      }
      if (0xfffffff0 < uVar2) goto LAB_40b05448;
      if (param_1[2].RecursionCount < param_1[1].RecursionCount) {
        *(uint *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = uVar2;
        param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
      }
    } while (param_1[2].RecursionCount != param_1[1].RecursionCount);
LAB_40b05480:
    pvVar6 = (void *)param_1[2].RecursionCount;
    param_1[2].RecursionCount = 0;
LAB_40b0549c:
    LeaveCriticalSection(param_1);
    if (!bVar1) {
      if (pvVar6 != (void *)0x0) {
        if (param_1[3].RecursionCount == 0) {
          LVar4 = (**(code **)(*(int *)param_1[1].DebugInfo + 0x1c))
                            (param_1[1].DebugInfo,param_1[2].LockCount,pvVar6,local_28);
          EnterCriticalSection(param_1);
          if (param_1[3].RecursionCount == 0) {
            param_1[3].RecursionCount = LVar4;
          }
          LeaveCriticalSection(param_1);
        }
        iVar7 = (int)pvVar6 << 2;
        do {
          iVar7 = iVar7 + -4;
          pvVar6 = (void *)((int)pvVar6 + -1);
          (**(code **)(**(int **)(param_1[2].LockCount + iVar7) + 8))();
        } while (pvVar6 != (void *)0x0);
      }
      if (uVar2 == 0xfffffffd) {
        if (param_1[3].RecursionCount != 0) goto LAB_40b05388;
        (**(code **)(*(int *)param_1->SpinCount + 0x38))();
      }
      if (uVar2 == 0xfffffffc) {
        UVar5 = param_1[1].SpinCount;
        param_1[3].RecursionCount = 0;
        EventModify(UVar5,3);
      }
      if (uVar2 == 0xfffffffb) {
        (**(code **)(*(int *)param_1->SpinCount + 0x44))();
        operator_delete(pvVar3);
      }
      goto LAB_40b05388;
    }
    WaitForSingleObject(param_1[1].LockSemaphore,0xffffffff);
  } while( true );
}



/* 40b05624 FUN_40b05624 */

/* Boundary evidence: original MIPS .pdata 40b05624..40b05693. Semantic name remains unreviewed. */

void FUN_40b05624(LPCRITICAL_SECTION param_1)

{
  int aiStack_10 [2];
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    param_1[3].LockCount = 1;
    FUN_40b04eb8(param_1,(undefined4 *)0x0,0,aiStack_10);
    param_1[3].LockCount = 0;
  }
  else {
    EnterCriticalSection(param_1);
    FUN_40b04e60((int)param_1,(int *)0xfffffffe);
    FUN_40b04d58((int)param_1);
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40b05694 FUN_40b05694 */

/* Boundary evidence: original MIPS .pdata 40b05694..40b05733. Semantic name remains unreviewed. */

void FUN_40b05694(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[1].LockCount != 0) {
      FUN_40b05624(param_1);
    }
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      (**(code **)(*(int *)param_1->SpinCount + 0x38))();
    }
  }
  else if (param_1[3].RecursionCount == 0) {
    param_1[2].SpinCount = 0;
    FUN_40b04e60((int)param_1,(int *)0xfffffffd);
    FUN_40b04d58((int)param_1);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40b05734 FUN_40b05734 */

/* Boundary evidence: original MIPS .pdata 40b05734..40b057e7. Semantic name remains unreviewed. */

void FUN_40b05734(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  
  EnterCriticalSection(param_1);
  if ((param_1[2].SpinCount == 0) || (param_1[1].OwningThread == (HANDLE)0x0)) {
    LeaveCriticalSection(param_1);
    if (param_1[1].OwningThread == (HANDLE)0x0) {
      FUN_40b05158(param_1);
    }
    else {
      WaitForSingleObject((HANDLE)param_1[1].SpinCount,0xffffffff);
    }
    piVar1 = (int *)param_1->SpinCount;
    param_1[2].SpinCount = 1;
    param_1[2].LockSemaphore = (HANDLE)0x0;
    (**(code **)(*piVar1 + 0x40))();
    param_1[3].RecursionCount = 0;
  }
  else {
    param_1[2].LockSemaphore = (HANDLE)0x0;
    param_1[3].RecursionCount = 0;
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40b057e8 FUN_40b057e8 */

/* Boundary evidence: original MIPS .pdata 40b057e8..40b0580f. Semantic name remains unreviewed. */

void FUN_40b057e8(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  int aiStack_10 [2];
  
  local_res4[0] = param_2;
  FUN_40b04eb8(param_1,local_res4,1,aiStack_10);
  return;
}



/* 40b05810 FUN_40b05810 */

/* Boundary evidence: original MIPS .pdata 40b05810..40b05863. Semantic name remains unreviewed. */

undefined4 FUN_40b05810(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40b05dd8();
  uVar2 = FUN_40b0534c(param_1);
  if (-1 < iVar1) {
    CoUninitialize();
  }
  return uVar2;
}



/* 40b05864 FUN_40b05864 */

/* Boundary evidence: original MIPS .pdata 40b05864..40b05aa7. Semantic name remains unreviewed. */

LPCRITICAL_SECTION
FUN_40b05864(LPCRITICAL_SECTION param_1,undefined4 *param_2,DWORD *param_3,int param_4,int param_5,
            int param_6,int param_7,undefined4 param_8,int param_9)

{
  DWORD DVar1;
  int iVar2;
  void *pvVar3;
  HANDLE pvVar4;
  undefined4 *puVar5;
  PRTL_CRITICAL_SECTION_DEBUG p_Var6;
  uint uVar7;
  LONG LVar8;
  LPCRITICAL_SECTION p_Var9;
  DWORD aDStack_28 [2];
  
  InitializeCriticalSection(param_1);
  p_Var9 = param_1 + 1;
  param_1->SpinCount = (ULONG_PTR)param_2;
  p_Var9->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  if ((param_7 == 0) || (LVar8 = 1, param_6 < 2)) {
    LVar8 = 0;
  }
  param_1[1].LockCount = LVar8;
  param_1[1].RecursionCount = param_6;
  param_1[1].OwningThread = (HANDLE)0x0;
  param_1[1].LockSemaphore = (HANDLE)0x0;
  FUN_40b05d68(&param_1[1].SpinCount,0);
  param_1[2].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[2].LockCount = 0;
  param_1[2].RecursionCount = 0;
  param_1[2].OwningThread = (HANDLE)0x0;
  param_1[2].LockSemaphore = (HANDLE)0x0;
  param_1[2].SpinCount = 1;
  param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[3].LockCount = 0;
  param_1[3].RecursionCount = 0;
  if ((int)*param_3 < 0) {
    return param_1;
  }
  DVar1 = (**(code **)*param_2)(param_2,&DAT_40b161c0,p_Var9);
  *param_3 = DVar1;
  if ((int)DVar1 < 0) {
    return param_1;
  }
  if (((param_4 != 0) && (iVar2 = (**(code **)(*(int *)p_Var9->DebugInfo + 0x20))(), -1 < iVar2)) &&
     (param_5 = 1, iVar2 != 0)) {
    param_5 = 0;
  }
  if ((uint)param_1[1].RecursionCount < 0x40000000) {
    uVar7 = param_1[1].RecursionCount << 2;
  }
  else {
    uVar7 = 0xffffffff;
  }
  pvVar3 = operator_new(uVar7);
  param_1[2].LockCount = (LONG)pvVar3;
  if (pvVar3 == (void *)0x0) {
LAB_40b059a4:
    DVar1 = 0x8007000e;
  }
  else {
    if (param_5 == 0) {
      return param_1;
    }
    pvVar4 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,0,0x7fffffff,(LPCWSTR)0x0);
    param_1[1].LockSemaphore = pvVar4;
    if (pvVar4 != (HANDLE)0x0) {
      puVar5 = operator_new(0x18);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        FUN_40b05f14(puVar5,0,param_8);
      }
      param_1[1].OwningThread = puVar5;
      if (puVar5 == (undefined4 *)0x0) goto LAB_40b059a4;
      p_Var6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40b05810,param_1,0,aDStack_28);
      param_1[2].DebugInfo = p_Var6;
      if (p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        FUN_40b05aa8(p_Var6,param_9);
        return param_1;
      }
    }
    DVar1 = GetLastError();
    if (0 < (int)DVar1) {
      DVar1 = DVar1 & 0xffff | 0x80070000;
    }
  }
  *param_3 = DVar1;
  return param_1;
}



/* 40b05aa8 FUN_40b05aa8 */

/* Boundary evidence: original MIPS .pdata 40b05aa8..40b05d67. Semantic name remains unreviewed. */

void FUN_40b05aa8(undefined4 param_1,int param_2)

{
  LSTATUS LVar1;
  uint uVar2;
  DWORD local_38;
  DWORD local_34;
  HKEY local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20 [2];
  
  if (DAT_40b17214 == 0xffffffff) {
    DAT_40b17218 = 0xfa;
    DAT_40b17214 = 0xf9;
    DAT_40b1721c = 0xfb;
    DAT_40b17220 = 0xfc;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,0,
                          &local_30);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Highest",(LPDWORD)0x0,&local_34,(LPBYTE)&local_28,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_28)) {
        local_28 = DAT_40b17214;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"AboveNormal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_2c,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_2c)) {
        local_2c = DAT_40b17218;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Normal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_24,&local_38
                              );
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_24)) {
        local_24 = DAT_40b1721c;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"BelowNormal",(LPDWORD)0x0,&local_34,(LPBYTE)local_20,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_20[0])) {
        local_20[0] = DAT_40b17220;
      }
      if (((local_28 <= local_2c) && (local_2c <= local_24)) && (local_24 <= local_20[0])) {
        DAT_40b17214 = local_28;
        DAT_40b17218 = local_2c;
        DAT_40b1721c = local_24;
        DAT_40b17220 = local_20[0];
      }
      RegCloseKey(local_30);
    }
  }
  uVar2 = DAT_40b17214;
  if (((param_2 != 1) && (uVar2 = DAT_40b17218, param_2 != 2)) &&
     (uVar2 = DAT_40b17220, param_2 != 4)) {
    uVar2 = DAT_40b1721c;
  }
  CeSetThreadPriority(param_1,uVar2);
  return;
}



/* 40b05d68 FUN_40b05d68 */

/* Boundary evidence: original MIPS .pdata 40b05d68..40b05da7. Semantic name remains unreviewed. */

undefined4 * FUN_40b05d68(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



/* 40b05da8 FUN_40b05da8 */

/* Boundary evidence: original MIPS .pdata 40b05da8..40b05dd7. Semantic name remains unreviewed. */

void FUN_40b05da8(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40b05dd8 FUN_40b05dd8 */

/* Boundary evidence: original MIPS .pdata 40b05dd8..40b05e4b. Semantic name remains unreviewed. */

undefined4 FUN_40b05dd8(void)

{
  HMODULE pHVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  uVar3 = 0x80004005;
  pHVar1 = GetModuleHandleW(L"ole32.dll");
  if ((pHVar1 != (HMODULE)0x0) &&
     (pcVar2 = (code *)GetProcAddressW(pHVar1,L"CoInitializeEx"), pcVar2 != (code *)0x0)) {
    uVar3 = (*pcVar2)(0,0);
  }
  return uVar3;
}



/* 40b05e4c FUN_40b05e4c */

short * FUN_40b05e4c(short *param_1,short *param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_1;
  if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      if (param_3 == 0) {
        *psVar2 = 0;
        return param_1;
      }
      sVar1 = *param_2;
      param_2 = param_2 + 1;
      *psVar2 = sVar1;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
  }
  return param_1;
}



/* 40b05e88 FUN_40b05e88 */

/* Boundary evidence: original MIPS .pdata 40b05e88..40b05f13. Semantic name remains unreviewed. */

undefined4 FUN_40b05e88(wchar_t *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  LPVOID _Dst;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    sVar2 = wcslen(param_1);
    sVar2 = (sVar2 + 1) * 2;
    _Dst = CoTaskMemAlloc(sVar2);
    *param_2 = _Dst;
    if (_Dst == (LPVOID)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      memcpy(_Dst,param_1,sVar2);
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b05f14 FUN_40b05f14 */

undefined4 * FUN_40b05f14(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40b05f34 FUN_40b05f34 */

undefined4 * FUN_40b05f34(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40b05f58 FUN_40b05f58 */

/* Boundary evidence: original MIPS .pdata 40b05f58..40b05fab. Semantic name remains unreviewed. */

void FUN_40b05f58(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = (void *)*param_1;
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



/* 40b05fac FUN_40b05fac */

int FUN_40b05fac(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while( true ) {
    iVar1 = iVar2;
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 8) == param_2) break;
    iVar2 = *param_1;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
    }
  }
  return iVar1;
}



/* 40b05ff0 FUN_40b05ff0 */

/* Boundary evidence: original MIPS .pdata 40b05ff0..40b060ab. Semantic name remains unreviewed. */

int FUN_40b05ff0(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    if (*param_2 == 0) {
      *param_1 = param_2[1];
    }
    else {
      *(int *)(*param_2 + 4) = param_2[1];
    }
    if ((int *)param_2[1] == (int *)0x0) {
      param_1[1] = *param_2;
    }
    else {
      *(int *)param_2[1] = *param_2;
    }
    iVar1 = param_2[2];
    if (param_1[4] < param_1[3]) {
      param_2[1] = param_1[5];
      param_1[5] = (int)param_2;
      param_1[4] = param_1[4] + 1;
    }
    else {
      operator_delete(param_2);
    }
    param_1[2] = param_1[2] + -1;
  }
  return iVar1;
}



/* 40b060ac FUN_40b060ac */

/* Boundary evidence: original MIPS .pdata 40b060ac..40b06147. Semantic name remains unreviewed. */

undefined4 * FUN_40b060ac(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40b060fc;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40b060fc:
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = param_1[1];
  if (param_1[1] == 0) {
    *param_1 = puVar1;
  }
  else {
    *(undefined4 **)(param_1[1] + 4) = puVar1;
  }
  param_1[1] = puVar1;
  param_1[2] = param_1[2] + 1;
  return puVar1;
}



/* 40b06148 FUN_40b06148 */

/* Boundary evidence: original MIPS .pdata 40b06148..40b061a7. Semantic name remains unreviewed. */

undefined4 FUN_40b06148(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *param_2;
  do {
    if (iVar2 == 0) {
      return 1;
    }
    puVar1 = (undefined4 *)(iVar2 + 8);
    iVar2 = *(int *)(iVar2 + 4);
    puVar1 = FUN_40b060ac(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40b061a8 FUN_40b061a8 */

/* Boundary evidence: original MIPS .pdata 40b061a8..40b061ef. Semantic name remains unreviewed. */

void FUN_40b061a8(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40b05f58(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40b061f0 FUN_40b061f0 */

/* Boundary evidence: original MIPS .pdata 40b061f0..40b0620b. Semantic name remains unreviewed. */

void FUN_40b061f0(int *param_1)

{
  FUN_40b05ff0(param_1,(int *)*param_1);
  return;
}



/* 40b0631c FUN_40b0631c */

/* Boundary evidence: original MIPS .pdata 40b0631c..40b0638f. Semantic name remains unreviewed. */

void FUN_40b0631c(void)

{
  uint uVar1;
  
  if ((DAT_40b17224 == 0) || (DAT_40b17224 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40b17224 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40b17224 == 0) {
      DAT_40b17224 = 0xb064;
    }
  }
  DAT_40b17228 = ~DAT_40b17224;
  return;
}



/* 40b06390 FUN_40b06390 */

/* Boundary evidence: original MIPS .pdata 40b06390..40b063e3. Semantic name remains unreviewed. */

void FUN_40b06390(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40b06410(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40b063e4 FUN_40b063e4 */

/* Boundary evidence: original MIPS .pdata 40b063e4..40b0640f. Semantic name remains unreviewed. */

undefined4 FUN_40b063e4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40b06390(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40b06410 FUN_40b06410 */

/* Boundary evidence: original MIPS .pdata 40b06410..40b06457. Semantic name remains unreviewed. */

void FUN_40b06410(uint param_1)

{
  if ((param_1 == DAT_40b17224) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40b064a8 FUN_40b064a8 */

/* Boundary evidence: original MIPS .pdata 40b064a8..40b065e3. Semantic name remains unreviewed. */

int FUN_40b064a8(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40b1b2e8 != (code *)0x0) {
      iVar2 = (*DAT_40b1b2e8)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40b06558;
    FUN_40b0681c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain(param_1,param_2);
  }
LAB_40b06558:
  if (((param_2 == 0) && (FUN_40b067a4(), iVar1 != 0)) && (DAT_40b1b2e8 != (code *)0x0)) {
    iVar1 = (*DAT_40b1b2e8)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40b065e4 FUN_40b065e4 */

/* Boundary evidence: original MIPS .pdata 40b065e4..40b0660f. Semantic name remains unreviewed. */

void FUN_40b065e4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40b06610 entry */

/* Boundary evidence: original MIPS .pdata 40b06610..40b06667. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40b0631c();
  }
  FUN_40b064a8(param_1,param_2,param_3);
  return;
}



/* 40b066b8 FUN_40b066b8 */

/* Boundary evidence: original MIPS .pdata 40b066b8..40b067a3. Semantic name remains unreviewed. */

void FUN_40b066b8(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40b177a8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40b1b2e4;
    if (DAT_40b1b2e4 != (undefined4 *)0x0) {
      while (DAT_40b1b2e0 = DAT_40b1b2e0 + -1, _Memory <= DAT_40b1b2e0) {
        if ((code *)*DAT_40b1b2e0 != (code *)0x0) {
          (*(code *)*DAT_40b1b2e0)();
          _Memory = DAT_40b1b2e4;
        }
      }
      free(_Memory);
      DAT_40b1b2e0 = (undefined4 *)0x0;
      DAT_40b1b2e4 = (undefined4 *)0x0;
    }
    FUN_40b067c8((undefined4 *)&DAT_40b07010,(undefined4 *)&DAT_40b07014);
  }
  FUN_40b067c8((undefined4 *)&DAT_40b07018,(undefined4 *)&DAT_40b0701c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40b067a4 FUN_40b067a4 */

/* Boundary evidence: original MIPS .pdata 40b067a4..40b067c7. Semantic name remains unreviewed. */

void FUN_40b067a4(void)

{
  FUN_40b066b8(0,0,1);
  return;
}



/* 40b067c8 FUN_40b067c8 */

/* Boundary evidence: original MIPS .pdata 40b067c8..40b0681b. Semantic name remains unreviewed. */

void FUN_40b067c8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40b0681c FUN_40b0681c */

/* Boundary evidence: original MIPS .pdata 40b0681c..40b06857. Semantic name remains unreviewed. */

void FUN_40b0681c(void)

{
  FUN_40b067c8((undefined4 *)&DAT_40b07008,(undefined4 *)&DAT_40b0700c);
  FUN_40b067c8((undefined4 *)&DAT_40b07000,(undefined4 *)&DAT_40b07004);
  return;
}


