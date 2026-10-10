/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c05a1a64 FUN_c05a1a64 */

int FUN_c05a1a64(uint *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (uint *)0x0) {
    if ((*param_1 <= param_2) && (*param_1 == 0xc4)) {
      iVar1 = 0;
      if ((param_1 + 4 != (uint *)0x0) && (0x20 < param_1[4])) {
        iVar1 = 0x57;
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      if (param_1[0x1c] < 0x21) {
        return 0;
      }
    }
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c05a1acc FUN_c05a1acc */

/* Boundary evidence: original MIPS .pdata c05a1acc..c05a1bb7. Semantic name remains unreviewed. */

void FUN_c05a1acc(int *param_1,int *param_2)

{
  int iVar1;
  WCHAR aWStack_118 [130];
  uint local_14;
  
  local_14 = DAT_c05b62e4;
  iVar1 = MultiByteToWideChar(1,0,(LPCSTR)(param_1 + 1),*param_1,aWStack_118,0x80);
  aWStack_118[iVar1] = L'\0';
  FUN_c05a4158(aWStack_118,(LPBYTE)param_2);
  if ((*param_2 == 0) || (iVar1 = FUN_c05a3efc(), iVar1 == 0)) {
    param_2[3] = 0;
    param_2[4] = 0;
  }
  else {
    (*DAT_c05b64d8)(aWStack_118,param_2 + 2);
    (*DAT_c05b6488)(aWStack_118,param_2[2],param_2[4],param_2 + 3);
    FUN_c05a3fe0();
  }
  FUN_c05b4904(local_14);
  return;
}



/* c05a1bb8 FUN_c05a1bb8 */

/* Boundary evidence: original MIPS .pdata c05a1bb8..c05a1c4b. Semantic name remains unreviewed. */

undefined4 FUN_c05a1bb8(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 1;
  if ((-1 < param_2) && (0xffff < param_1)) {
    uVar4 = 0x70000000;
    if (param_3 == 0) {
      uVar4 = 0x80000000;
    }
    bVar1 = true;
    if ((uint)(param_1 + param_2) < uVar4) goto LAB_c05a1c04;
  }
  bVar1 = false;
LAB_c05a1c04:
  if (param_1 != 0) {
    iVar2 = __GetUserKData(0xc);
    iVar3 = GetCallerVMProcessId();
    if ((iVar2 != iVar3) && (!bVar1)) {
      uVar5 = 0;
    }
  }
  return uVar5;
}



/* c05a1c4c FUN_c05a1c4c */

/* Boundary evidence: original MIPS .pdata c05a1c4c..c05a2963. Semantic name remains unreviewed. */

undefined4
FUN_c05a1c4c(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
            int param_6)

{
  longlong lVar1;
  HRESULT HVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint *puVar13;
  undefined4 *puVar14;
  uint *puVar15;
  undefined4 *puVar16;
  void *_Dst;
  undefined4 *local_60;
  undefined4 *local_5c;
  int local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 *local_4c;
  int local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  
  local_54 = 0xd;
  puVar11 = (undefined4 *)0x70;
  if (param_6 == 0) {
    puVar11 = (undefined4 *)0x58;
  }
  local_58 = param_2;
  if (((((STRSAFE_PCNZWCH)*param_1 == (STRSAFE_PCNZWCH)0x0) ||
       ((((HVar2 = StringCchLengthW((STRSAFE_PCNZWCH)*param_1,0x7fffffff,(size_t *)&local_60),
          -1 < HVar2 && ((int)local_60 + 1U != 0)) &&
         (lVar1 = (ulonglong)((int)local_60 + 1U) * 2, local_60 = (undefined4 *)lVar1,
         (int)((ulonglong)lVar1 >> 0x20) == 0)) &&
        (puVar11 = (undefined4 *)((int)local_60 + (int)puVar11), local_60 <= puVar11)))) &&
      ((puVar5 = puVar11, ((uint)puVar11 & 3) == 0 ||
       (puVar5 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11), puVar11 <= puVar5)))) &&
     ((((STRSAFE_PCNZWCH)param_1[1] == (STRSAFE_PCNZWCH)0x0 ||
       (((HVar2 = StringCchLengthW((STRSAFE_PCNZWCH)param_1[1],0x7fffffff,(size_t *)&local_5c),
         -1 < HVar2 && ((int)local_5c + 1U != 0)) &&
        ((lVar1 = (ulonglong)((int)local_5c + 1U) * 2, local_5c = (undefined4 *)lVar1,
         (int)((ulonglong)lVar1 >> 0x20) == 0 &&
         (puVar5 = (undefined4 *)((int)local_5c + (int)puVar5), local_5c <= puVar5)))))) &&
      ((((((iVar3 = local_58, puVar11 = puVar5, ((uint)puVar5 & 3) == 0 ||
           (puVar11 = (undefined4 *)((4 - ((uint)puVar5 & 3)) + (int)puVar5), puVar5 <= puVar11)) &&
          (uVar6 = param_1[10] + (int)puVar11, (uint)param_1[10] <= uVar6)) &&
         ((uVar10 = uVar6, (uVar6 & 3) == 0 || (uVar10 = (4 - (uVar6 & 3)) + uVar6, uVar6 <= uVar10)
          ))) && (uVar10 = param_1[0xc] + uVar10, (uint)param_1[0xc] <= uVar10)) &&
       ((uVar6 = uVar10, (uVar10 & 3) == 0 || (uVar6 = (4 - (uVar10 & 3)) + uVar10, uVar10 <= uVar6)
        ))))))) {
    uVar10 = param_1[0xe];
    uVar6 = uVar10 + uVar6;
    if ((uVar10 <= uVar6) &&
       ((uVar9 = uVar6, (uVar6 & 3) == 0 || (uVar9 = (4 - (uVar6 & 3)) + uVar6, uVar6 <= uVar9)))) {
      uVar6 = param_1[0x10];
      uVar9 = uVar6 + uVar9;
      if ((uVar6 <= uVar9) &&
         ((((uVar7 = uVar9, (uVar9 & 3) == 0 || (uVar7 = (4 - (uVar9 & 3)) + uVar9, uVar9 <= uVar7))
           && (puVar11 = (undefined4 *)(param_1[0x12] + uVar7),
              (undefined4 *)param_1[0x12] <= puVar11)) &&
          ((puVar5 = puVar11, ((uint)puVar11 & 3) == 0 ||
           (puVar5 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11), puVar11 <= puVar5))))
         )) {
        if (uVar10 != 0) {
          uVar9 = *(uint *)param_1[0xf];
          uVar10 = 0;
          if (uVar9 != 0) {
            puVar15 = (uint *)param_1[0xf] + 0x28;
            do {
              puVar11 = (undefined4 *)((int)*puVar15 + (int)puVar5);
              if (puVar11 < (undefined4 *)*puVar15) {
                return local_54;
              }
              puVar5 = puVar11;
              if ((((uint)puVar11 & 3) != 0) &&
                 (puVar5 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                 puVar5 < puVar11)) {
                return local_54;
              }
              uVar10 = uVar10 + 1;
              puVar15 = puVar15 + 0x31;
            } while (uVar10 < uVar9);
          }
        }
        if (uVar6 != 0) {
          puVar15 = (uint *)param_1[0x11];
          uVar6 = 0;
          param_2 = local_58;
          if (*puVar15 != 0) {
            puVar13 = puVar15 + 0x28;
            do {
              puVar11 = (undefined4 *)((int)*puVar13 + (int)puVar5);
              if (puVar11 < (undefined4 *)*puVar13) {
                return local_54;
              }
              puVar5 = puVar11;
              if ((((uint)puVar11 & 3) != 0) &&
                 (puVar5 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                 puVar5 < puVar11)) {
                return local_54;
              }
              if (iVar3 == 0) {
                memset(&local_40,0,0x14);
                FUN_c05a1acc((int *)(puVar13 + -0x22),&local_40);
                if (local_40 != 0) {
                  puVar11 = (undefined4 *)((int)local_34 + (int)puVar5);
                  if (puVar11 < local_34) {
                    return local_54;
                  }
                  puVar5 = puVar11;
                  if ((((uint)puVar11 & 3) != 0) &&
                     (puVar5 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                     puVar5 < puVar11)) {
                    return local_54;
                  }
                }
              }
              else if ((puVar13[2] != 0) &&
                      (puVar5 = (undefined4 *)((int)puVar13[5] + (int)puVar5),
                      puVar5 < (undefined4 *)puVar13[5])) {
                return local_54;
              }
              uVar6 = uVar6 + 1;
              puVar13 = puVar13 + 0x31;
              param_2 = local_58;
            } while (uVar6 < *puVar15);
          }
        }
        puVar14 = local_5c;
        puVar11 = local_60;
        if ((param_6 == 0) ||
           ((uVar6 = param_1[0x17] + (int)puVar5, (uint)param_1[0x17] <= uVar6 &&
            ((((uVar10 = uVar6, (uVar6 & 3) == 0 ||
               (uVar10 = (4 - (uVar6 & 3)) + uVar6, uVar6 <= uVar10)) &&
              (puVar12 = (undefined4 *)(param_1[0x19] + uVar10),
              (undefined4 *)param_1[0x19] <= puVar12)) &&
             ((puVar5 = puVar12, ((uint)puVar12 & 3) == 0 ||
              (puVar5 = (undefined4 *)((4 - ((uint)puVar12 & 3)) + (int)puVar12), puVar12 <= puVar5)
              ))))))) {
          *param_5 = puVar5;
          if (param_4 < puVar5) {
            local_54 = 0x7a;
          }
          else {
            memset(param_3,0,(size_t)param_4);
            puVar5 = param_3 + 0x1c;
            if (param_6 == 0) {
              puVar5 = param_3 + 0x16;
            }
            puVar12 = puVar5;
            if ((((uint)puVar5 & 3) == 0) ||
               (puVar12 = (undefined4 *)((4 - ((uint)puVar5 & 3)) + (int)puVar5), puVar5 <= puVar12)
               ) {
              param_3[2] = param_1[2];
              param_3[3] = param_1[3];
              param_3[4] = param_1[4];
              param_3[5] = param_1[5];
              param_3[6] = param_1[6];
              param_3[7] = param_1[7];
              param_3[8] = param_1[8];
              param_3[9] = param_1[9];
              *param_3 = 0;
              puVar5 = (undefined4 *)((int)param_3 + (int)param_4);
              if (*param_1 != 0) {
                *param_3 = puVar12;
                if ((param_2 != 0) &&
                   (iVar3 = FUN_c05a1bb8(*param_1,(int)puVar11,0), puVar11 = local_60, iVar3 == 0))
                {
                  return local_54;
                }
                memcpy(puVar12,(void *)*param_1,(size_t)puVar11);
                memset((void *)((int)puVar12 + (int)local_60 + -2),0,2);
                puVar11 = (undefined4 *)((int)puVar12 + (int)local_60);
                if (puVar11 < local_60) {
                  return local_54;
                }
                puVar12 = puVar11;
                if ((((uint)puVar11 & 3) != 0) &&
                   (puVar12 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                   puVar12 < puVar11)) {
                  return local_54;
                }
                puVar14 = local_5c;
                if (puVar5 < puVar12) {
                  return local_54;
                }
              }
              param_3[1] = 0;
              if (param_1[1] != 0) {
                param_3[1] = puVar12;
                if ((param_2 != 0) &&
                   (iVar3 = FUN_c05a1bb8(param_1[1],(int)puVar14,0), puVar14 = local_5c, iVar3 == 0)
                   ) {
                  return local_54;
                }
                memcpy(puVar12,(void *)param_1[1],(size_t)puVar14);
                memset((void *)((int)puVar12 + (int)local_5c + -2),0,2);
                puVar11 = (undefined4 *)((int)puVar12 + (int)local_5c);
                if (puVar11 < local_5c) {
                  return local_54;
                }
                puVar12 = puVar11;
                if ((((uint)puVar11 & 3) != 0) &&
                   (puVar12 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                   puVar12 < puVar11)) {
                  return local_54;
                }
                if (puVar5 < puVar12) {
                  return local_54;
                }
              }
              puVar14 = (undefined4 *)param_1[10];
              param_3[0xb] = puVar12;
              puVar11 = (undefined4 *)((int)puVar14 + (int)puVar12);
              param_3[10] = puVar14;
              if (((puVar14 <= puVar11) &&
                  (((puVar8 = puVar11, ((uint)puVar11 & 3) == 0 ||
                    (puVar8 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                    puVar11 <= puVar8)) && (puVar8 <= puVar5)))) &&
                 ((param_2 == 0 || (iVar3 = FUN_c05a1bb8(param_1[0xb],param_1[10],0), iVar3 != 0))))
              {
                memcpy(puVar12,(void *)param_1[0xb],(size_t)puVar14);
                puVar14 = (undefined4 *)param_1[0xc];
                param_3[0xd] = puVar8;
                puVar11 = (undefined4 *)((int)puVar14 + (int)puVar8);
                param_3[0xc] = puVar14;
                if ((puVar14 <= puVar11) &&
                   (((puVar12 = puVar11, ((uint)puVar11 & 3) == 0 ||
                     (puVar12 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                     puVar11 <= puVar12)) &&
                    ((puVar12 <= puVar5 &&
                     ((param_2 == 0 ||
                      (iVar3 = FUN_c05a1bb8(param_1[0xd],param_1[0xc],0), iVar3 != 0)))))))) {
                  memcpy(puVar8,(void *)param_1[0xd],(size_t)puVar14);
                  puVar14 = (undefined4 *)param_1[0xe];
                  param_3[0xf] = puVar12;
                  puVar11 = (undefined4 *)((int)puVar14 + (int)puVar12);
                  param_3[0xe] = puVar14;
                  if (((puVar14 <= puVar11) &&
                      (((puVar8 = puVar11, ((uint)puVar11 & 3) == 0 ||
                        (puVar8 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                        puVar11 <= puVar8)) && (puVar8 <= puVar5)))) &&
                     ((param_2 == 0 ||
                      (iVar3 = FUN_c05a1bb8(param_1[0xf],param_1[0xe],0), iVar3 != 0)))) {
                    memcpy(puVar12,(void *)param_1[0xf],(size_t)puVar14);
                    puVar15 = (uint *)param_1[0xf];
                    if (puVar15 != (uint *)0x0) {
                      iVar3 = param_3[0xf];
                      local_50 = 0;
                      if (*puVar15 != 0) {
                        _Dst = (void *)(iVar3 + 0xa8);
                        puVar13 = puVar15 + 0x28;
                        puVar11 = puVar8;
                        do {
                          puVar16 = (undefined4 *)*puVar13;
                          puVar14 = (undefined4 *)((iVar3 - (int)puVar15) + (int)puVar13);
                          puVar14[1] = puVar11;
                          puVar12 = (undefined4 *)((int)puVar16 + (int)puVar11);
                          *puVar14 = puVar16;
                          if (puVar12 < puVar16) {
                            return local_54;
                          }
                          puVar8 = puVar12;
                          if ((((uint)puVar12 & 3) != 0) &&
                             (puVar8 = (undefined4 *)((4 - ((uint)puVar12 & 3)) + (int)puVar12),
                             puVar8 < puVar12)) {
                            return local_54;
                          }
                          if (puVar5 < puVar8) {
                            return local_54;
                          }
                          local_4c = puVar11;
                          if ((local_58 != 0) &&
                             (iVar4 = FUN_c05a1bb8(puVar13[1],*puVar13,0), iVar4 == 0)) {
                            return local_54;
                          }
                          memcpy(local_4c,(void *)puVar13[1],(size_t)puVar16);
                          memset(_Dst,0,0x14);
                          puVar13 = puVar13 + 0x31;
                          _Dst = (void *)((int)_Dst + 0xc4);
                          local_50 = local_50 + 1;
                          puVar11 = puVar8;
                          param_2 = local_58;
                        } while (local_50 < *puVar15);
                      }
                    }
                    puVar14 = (undefined4 *)param_1[0x10];
                    param_3[0x11] = puVar8;
                    puVar11 = (undefined4 *)((int)puVar14 + (int)puVar8);
                    param_3[0x10] = puVar14;
                    if ((puVar14 <= puVar11) &&
                       ((((puVar12 = puVar11, ((uint)puVar11 & 3) == 0 ||
                          (puVar12 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                          puVar11 <= puVar12)) && (puVar12 <= puVar5)) &&
                        ((param_2 == 0 ||
                         (iVar3 = FUN_c05a1bb8(param_1[0x11],param_1[0x10],0), iVar3 != 0)))))) {
                      memcpy(puVar8,(void *)param_1[0x11],(size_t)puVar14);
                      puVar15 = (uint *)param_1[0x11];
                      if (puVar15 != (uint *)0x0) {
                        local_50 = 0;
                        if (*puVar15 != 0) {
                          local_48 = (int)puVar15 - param_3[0x11];
                          puVar13 = puVar15 + 6;
                          puVar14 = (undefined4 *)(param_3[0x11] + 0xa0);
                          puVar11 = puVar12;
                          do {
                            puVar16 = *(undefined4 **)(local_48 + (int)puVar14);
                            puVar14[1] = puVar11;
                            puVar8 = (undefined4 *)((int)puVar16 + (int)puVar11);
                            *puVar14 = puVar16;
                            if (puVar8 < puVar16) {
                              return local_54;
                            }
                            puVar12 = puVar8;
                            if ((((uint)puVar8 & 3) != 0) &&
                               (puVar12 = (undefined4 *)((4 - ((uint)puVar8 & 3)) + (int)puVar8),
                               puVar12 < puVar8)) {
                              return local_54;
                            }
                            if (puVar5 < puVar12) {
                              return local_54;
                            }
                            local_4c = puVar11;
                            if ((local_58 != 0) &&
                               (iVar3 = FUN_c05a1bb8(puVar13[0x23],*(int *)(local_48 + (int)puVar14)
                                                     ,0), iVar3 == 0)) {
                              return local_54;
                            }
                            memcpy(local_4c,(void *)puVar13[0x23],(size_t)puVar16);
                            if (local_58 == 0) {
                              memset(&local_40,0,0x14);
                              FUN_c05a1acc((int *)puVar13,&local_40);
                              if (local_40 != 0) {
                                puVar11 = (undefined4 *)((int)local_34 + (int)puVar12);
                                if (puVar11 < local_34) {
                                  return local_54;
                                }
                                puVar8 = puVar11;
                                if ((((uint)puVar11 & 3) != 0) &&
                                   (puVar8 = (undefined4 *)
                                             ((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                                   puVar8 < puVar11)) {
                                  return local_54;
                                }
                                if (puVar5 < puVar8) {
                                  return local_54;
                                }
                                local_30 = puVar12;
                                FUN_c05a1acc((int *)puVar13,&local_40);
                                puVar12 = puVar8;
                              }
                              puVar14[2] = local_40;
                              puVar14[3] = local_3c;
                              puVar14[4] = local_38;
                              puVar14[5] = local_34;
                              puVar14[6] = local_30;
                            }
                            else if (puVar14[2] != 0) {
                              if ((puVar14[6] == 0) || (puVar14[5] == 0)) {
                                puVar14[6] = 0;
                                puVar14[5] = 0;
                              }
                              else {
                                puVar8 = (undefined4 *)puVar13[0x27];
                                puVar14[6] = puVar12;
                                puVar11 = (undefined4 *)((int)puVar8 + (int)puVar12);
                                puVar14[5] = puVar8;
                                if (puVar11 < puVar8) {
                                  return local_54;
                                }
                                puVar16 = puVar11;
                                if ((((uint)puVar11 & 3) != 0) &&
                                   (puVar16 = (undefined4 *)
                                              ((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                                   puVar16 < puVar11)) {
                                  return local_54;
                                }
                                if (puVar5 < puVar16) {
                                  return local_54;
                                }
                                local_4c = puVar12;
                                iVar3 = FUN_c05a1bb8(puVar13[0x28],puVar13[0x27],0);
                                if (iVar3 == 0) {
                                  return local_54;
                                }
                                memcpy(local_4c,(void *)puVar13[0x28],(size_t)puVar8);
                                puVar12 = puVar16;
                              }
                            }
                            local_50 = local_50 + 1;
                            puVar14 = puVar14 + 0x31;
                            puVar13 = puVar13 + 0x31;
                            puVar11 = puVar12;
                            param_2 = local_58;
                          } while (local_50 < *puVar15);
                        }
                      }
                      puVar14 = (undefined4 *)param_1[0x12];
                      param_3[0x13] = puVar12;
                      puVar11 = (undefined4 *)((int)puVar14 + (int)puVar12);
                      param_3[0x12] = puVar14;
                      if (((puVar14 <= puVar11) &&
                          (((puVar8 = puVar11, ((uint)puVar11 & 3) == 0 ||
                            (puVar8 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                            puVar11 <= puVar8)) && (puVar8 <= puVar5)))) &&
                         ((param_2 == 0 ||
                          (iVar3 = FUN_c05a1bb8(param_1[0x13],param_1[0x12],0), iVar3 != 0)))) {
                        memcpy(puVar12,(void *)param_1[0x13],(size_t)puVar14);
                        if (param_6 != 0) {
                          param_3[0x16] = param_1[0x16];
                          puVar14 = (undefined4 *)param_1[0x17];
                          param_3[0x18] = puVar8;
                          puVar11 = (undefined4 *)((int)puVar14 + (int)puVar8);
                          param_3[0x17] = puVar14;
                          if (puVar11 < puVar14) {
                            return local_54;
                          }
                          puVar12 = puVar11;
                          if ((((uint)puVar11 & 3) != 0) &&
                             (puVar12 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                             puVar12 < puVar11)) {
                            return local_54;
                          }
                          if (puVar5 < puVar12) {
                            return local_54;
                          }
                          if ((param_2 != 0) &&
                             (iVar3 = FUN_c05a1bb8(param_1[0x18],param_1[0x17],0), iVar3 == 0)) {
                            return local_54;
                          }
                          memcpy(puVar8,(void *)param_1[0x18],(size_t)puVar14);
                          param_3[0x1b] = param_1[0x1b];
                          puVar14 = (undefined4 *)param_1[0x19];
                          param_3[0x1a] = puVar12;
                          puVar11 = (undefined4 *)((int)puVar14 + (int)puVar12);
                          param_3[0x19] = puVar14;
                          if (puVar11 < puVar14) {
                            return local_54;
                          }
                          puVar8 = puVar11;
                          if ((((uint)puVar11 & 3) != 0) &&
                             (puVar8 = (undefined4 *)((4 - ((uint)puVar11 & 3)) + (int)puVar11),
                             puVar8 < puVar11)) {
                            return local_54;
                          }
                          if (puVar5 < puVar8) {
                            return local_54;
                          }
                          if ((param_2 != 0) &&
                             (iVar3 = FUN_c05a1bb8(param_1[0x1a],param_1[0x19],0), iVar3 == 0)) {
                            return local_54;
                          }
                          memcpy(puVar12,(void *)param_1[0x1a],(size_t)puVar14);
                        }
                        local_54 = 0;
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
  return local_54;
}



/* c05a2964 FUN_c05a2964 */

/* Boundary evidence: original MIPS .pdata c05a2964..c05a2dcf. Semantic name remains unreviewed. */

undefined4 FUN_c05a2964(uint *param_1,int param_2,wchar_t *param_3)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  size_t sVar4;
  DWORD dwErrCode;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  uint local_44;
  uint local_40;
  uint *local_3c;
  undefined4 local_38;
  uint local_30;
  undefined4 *local_2c;
  
  local_3c = &local_30;
  bVar2 = false;
  param_3[0] = L'\0';
  param_3[1] = L'\0';
  local_48 = param_3;
  if (param_2 == 0xc) {
    local_2c = (undefined4 *)0x0;
    InterlockedIncrement((LONG *)&DAT_c05b6354);
    local_50 = FUN_c05a5098();
    *param_1 = local_50;
    if (local_50 == 0) {
      dwErrCode = 0;
    }
    else {
      puVar3 = FUN_c05a4228(local_50 << 2);
      local_2c = puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        dwErrCode = GetLastError();
      }
      else {
        dwErrCode = FUN_c05a51c4(puVar3,&local_50);
        uVar9 = local_50;
        if ((dwErrCode == 0) && (local_50 != 0)) {
          bVar2 = true;
          local_38 = 1;
          local_30 = local_50;
          uVar5 = local_50 << 2;
          uVar11 = 0;
          if (local_50 != 0) {
            do {
              sVar4 = wcslen((wchar_t *)*puVar3);
              uVar5 = (sVar4 + 1) * 2 + uVar5;
              if ((uVar5 & 3) != 0) {
                iVar6 = -0x3fffff6b;
                uVar7 = uVar5 + (4 - (uVar5 & 3));
                bVar1 = uVar5 <= uVar7;
                uVar5 = 0xffffffff;
                if (bVar1) {
                  iVar6 = 0;
                  uVar5 = uVar7;
                }
                if (iVar6 < 0) {
                  bVar2 = true;
                  goto LAB_c05a2d20;
                }
              }
              uVar11 = uVar11 + 1;
              puVar3 = puVar3 + 1;
            } while (uVar11 < uVar9);
          }
          *(uint *)local_48 = uVar5;
          if (param_1[1] < uVar5) {
            dwErrCode = 0x7a;
            local_4c = 0x7a;
            bVar2 = true;
          }
          else {
            *param_1 = uVar9;
            iVar6 = FUN_c05a1bb8(param_1[2],param_1[1],1);
            if (iVar6 == 0) {
              dwErrCode = 0x57;
              local_4c = 0x57;
              bVar2 = true;
            }
            else {
              local_40 = param_1[2];
              uVar5 = local_40 + uVar9 * 4;
              uVar11 = param_1[1] + uVar9 * -4 + uVar5;
              for (uVar9 = 0; local_44 = uVar9, uVar9 < local_50; uVar9 = uVar9 + 1) {
                puVar10 = (uint *)(uVar9 * 4 + local_40);
                *puVar10 = uVar5;
                local_48 = (wchar_t *)local_2c[uVar9];
                sVar4 = wcslen(local_48);
                uVar7 = (sVar4 + 1) * 2;
                uVar8 = uVar7 + uVar5;
                iVar6 = -0x3fffff6b;
                uVar5 = 0xffffffff;
                if (uVar7 <= uVar8) {
                  iVar6 = 0;
                  uVar5 = uVar8;
                }
                if (iVar6 < 0) goto LAB_c05a2d20;
                if ((uVar5 & 3) != 0) {
                  uVar7 = uVar5 + (4 - (uVar5 & 3));
                  bVar1 = uVar5 <= uVar7;
                  iVar6 = -0x3fffff6b;
                  uVar5 = 0xffffffff;
                  if (bVar1) {
                    iVar6 = 0;
                    uVar5 = uVar7;
                  }
                  if (iVar6 < 0) {
                    bVar2 = true;
                    goto LAB_c05a2d20;
                  }
                }
                if (uVar11 < uVar5) {
                  bVar2 = true;
                  goto LAB_c05a2d20;
                }
                wcscpy((wchar_t *)*puVar10,local_48);
              }
              dwErrCode = 0;
              local_4c = 0;
              bVar2 = true;
            }
          }
        }
        else {
          FUN_c05a42b0(puVar3);
          local_2c = (undefined4 *)0x0;
        }
      }
    }
LAB_c05a2d20:
    InterlockedDecrement((LONG *)&DAT_c05b6354);
    uVar9 = local_30;
    puVar3 = local_2c;
    if (bVar2) {
      for (; uVar9 != 0; uVar9 = uVar9 - 1) {
        FUN_c05a42b0((HLOCAL)*puVar3);
        puVar3 = puVar3 + 1;
      }
    }
    if (local_2c != (undefined4 *)0x0) {
      FUN_c05a42b0(local_2c);
    }
    if (dwErrCode == 0) {
      return 1;
    }
  }
  else {
    dwErrCode = 0xd;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c05a2dd0 FUN_c05a2dd0 */

/* Boundary evidence: original MIPS .pdata c05a2dd0..c05a2ddb. Semantic name remains unreviewed. */

undefined4 FUN_c05a2dd0(void)

{
  return 1;
}



/* c05a2ddc FUN_c05a2ddc */

/* Boundary evidence: original MIPS .pdata c05a2ddc..c05a2f9f. Semantic name remains unreviewed. */

undefined4 FUN_c05a2ddc(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  DWORD dwErrCode;
  HLOCAL _Src;
  SIZE_T _Size;
  void *_Dst;
  undefined4 local_28 [2];
  
  _Src = (HLOCAL)0x0;
  *param_3 = 0;
  if (param_2 == 0xc) {
    iVar1 = FUN_c05a3efc();
    if (iVar1 == 0) {
      dwErrCode = 0x32;
    }
    else {
      _Size = param_1[1];
      _Dst = (void *)param_1[2];
      iVar1 = FUN_c05a1bb8((int)_Dst,_Size,1);
      if (iVar1 == 0) {
        dwErrCode = 0xd;
      }
      else if ((_Size == 0) || (_Src = FUN_c05a4228(_Size), _Src != (HLOCAL)0x0)) {
        dwErrCode = (*DAT_c05b64d4)(_Size,_Src,local_28,param_3);
        *param_1 = local_28[0];
        if (_Dst != (void *)0x0) {
          memcpy(_Dst,_Src,_Size);
        }
      }
      else {
        dwErrCode = 0xe;
      }
      FUN_c05a3fe0();
    }
    if (_Src != (HLOCAL)0x0) {
      FUN_c05a42b0(_Src);
    }
    if (dwErrCode == 0) {
      return 1;
    }
  }
  else {
    dwErrCode = 0xd;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c05a2fa0 FUN_c05a2fa0 */

/* Boundary evidence: original MIPS .pdata c05a2fa0..c05a2fab. Semantic name remains unreviewed. */

undefined4 FUN_c05a2fa0(void)

{
  return 1;
}



/* c05a2fac FUN_c05a2fac */

/* Boundary evidence: original MIPS .pdata c05a2fac..c05a3077. Semantic name remains unreviewed. */

undefined4 FUN_c05a2fac(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  DWORD dwErrCode;
  
  if (param_2 < 0x14) {
    SetLastError(0x57);
  }
  else {
    dwErrCode = FUN_c05a8834(0,param_1);
    if (dwErrCode == 0) {
      *param_3 = 0x14;
      return 1;
    }
    SetLastError(dwErrCode);
  }
  return 0;
}



/* c05a3078 FUN_c05a3078 */

/* Boundary evidence: original MIPS .pdata c05a3078..c05a3083. Semantic name remains unreviewed. */

undefined4 FUN_c05a3078(void)

{
  return 1;
}



/* c05a3084 FUN_c05a3084 */

/* Boundary evidence: original MIPS .pdata c05a3084..c05a30eb. Semantic name remains unreviewed. */

undefined4 FUN_c05a3084(int *param_1,int param_2)

{
  DWORD dwErrCode;
  
  if (param_2 == 0x14) {
    dwErrCode = FUN_c05a886c(0,param_1);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  else {
    dwErrCode = 0x57;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c05a30ec FUN_c05a30ec */

/* Boundary evidence: original MIPS .pdata c05a30ec..c05a33b3. Semantic name remains unreviewed. */

undefined4 FUN_c05a30ec(uint *param_1,uint param_2,undefined4 *param_3)

{
  bool bVar1;
  HRESULT HVar2;
  int iVar3;
  DWORD dwErrCode;
  uint local_2ac;
  uint local_2a8;
  wchar_t *local_2a0;
  HLOCAL local_29c;
  HLOCAL local_274;
  HLOCAL local_26c;
  HLOCAL local_264;
  HLOCAL local_25c;
  HLOCAL local_254;
  HLOCAL local_240;
  HLOCAL local_238;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c05b62e4;
  bVar1 = false;
  if (0x13 < param_2) {
    *param_3 = 0;
    local_2a8 = *param_1;
    local_2ac = param_1[1];
    memset(&local_2a0,0,0x70);
    InterlockedIncrement((LONG *)&DAT_c05b6354);
    HVar2 = StringCchCopyW(awStack_230,0x104,(STRSAFE_LPCWSTR)param_1[2]);
    if (HVar2 == 0) {
      local_2a0 = awStack_230;
      dwErrCode = FUN_c05a6508(local_2a8,&local_2a0,&local_2ac);
      if (dwErrCode == 0) {
        bVar1 = true;
        iVar3 = FUN_c05a1bb8(param_1[4],param_1[3],1);
        if (iVar3 == 0) {
          dwErrCode = 0x57;
        }
        else {
          dwErrCode = FUN_c05a1c4c((int *)&local_2a0,0,(undefined4 *)param_1[4],
                                   (undefined4 *)param_1[3],param_3,1);
          param_1[1] = local_2ac;
        }
      }
    }
    else {
      dwErrCode = 0x57;
    }
    InterlockedDecrement((LONG *)&DAT_c05b6354);
    if (bVar1) {
      FUN_c05a42b0(local_29c);
      FUN_c05a42b0(local_274);
      FUN_c05a42b0(local_26c);
      FUN_c05a42b0(local_264);
      FUN_c05a42b0(local_25c);
      FUN_c05a42b0(local_254);
      FUN_c05a42b0(local_240);
      FUN_c05a42b0(local_238);
    }
    if (dwErrCode == 0) {
      FUN_c05b4904(local_28);
      return 1;
    }
    SetLastError(dwErrCode);
  }
  FUN_c05b4904(local_28);
  return 0;
}



/* c05a33b4 FUN_c05a33b4 */

/* Boundary evidence: original MIPS .pdata c05a33b4..c05a33bf. Semantic name remains unreviewed. */

undefined4 FUN_c05a33b4(void)

{
  return 1;
}



/* c05a33c0 FUN_c05a33c0 */

/* Boundary evidence: original MIPS .pdata c05a33c0..c05a33cb. Semantic name remains unreviewed. */

undefined4 FUN_c05a33c0(void)

{
  return 1;
}



/* c05a33cc FUN_c05a33cc */

/* Boundary evidence: original MIPS .pdata c05a33cc..c05a33d7. Semantic name remains unreviewed. */

undefined4 FUN_c05a33cc(void)

{
  return 1;
}



/* c05a33d8 FUN_c05a33d8 */

/* Boundary evidence: original MIPS .pdata c05a33d8..c05a353b. Semantic name remains unreviewed. */

undefined4 FUN_c05a33d8(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  WCHAR aWStack_130 [130];
  uint local_2c;
  
  local_2c = DAT_c05b62e4;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x40) != 0) {
    puVar3 = *(uint **)(param_1 + 0x44);
    uVar5 = 0;
    if (*puVar3 != 0) {
      puVar2 = puVar3 + 0x2c;
      do {
        iVar1 = MultiByteToWideChar(1,0,(LPCSTR)(puVar2 + -0x25),puVar2[-0x26],aWStack_130,0x80);
        aWStack_130[iVar1] = L'\0';
        iVar1 = FUN_c05a3efc();
        if (iVar1 == 0) {
          uVar4 = 0x32;
          break;
        }
        if (puVar2[-2] == 0) {
          (*DAT_c05b6484)(aWStack_130,0);
        }
        else {
          (*DAT_c05b6484)(aWStack_130,1);
          (*DAT_c05b64a0)(aWStack_130,*puVar2);
          if (puVar2[1] != 0) {
            (*DAT_c05b6480)(aWStack_130,*puVar2,puVar2[2]);
          }
        }
        FUN_c05a3fe0();
        uVar5 = uVar5 + 1;
        puVar2 = puVar2 + 0x31;
      } while (uVar5 < *puVar3);
    }
  }
  FUN_c05b4904(local_2c);
  return uVar4;
}



/* c05a353c FUN_c05a353c */

/* Boundary evidence: original MIPS .pdata c05a353c..c05a379b. Semantic name remains unreviewed. */

undefined4 FUN_c05a353c(uint *param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  size_t _Size;
  DWORD dwErrCode;
  int *piVar3;
  undefined4 *local_a4;
  int *local_a0;
  int aiStack_98 [28];
  
  piVar3 = (int *)0x0;
  local_a0 = (int *)0x0;
  if (0xb < param_2) {
    InterlockedIncrement((LONG *)&DAT_c05b6354);
    iVar2 = FUN_c05a1bb8(param_1[2],0x58,1);
    if (iVar2 == 0) {
      dwErrCode = 0x57;
    }
    else {
      _Size = 0x70;
      if (param_3 == 0) {
        _Size = 0x58;
      }
      memcpy(aiStack_98,(void *)param_1[2],_Size);
      dwErrCode = FUN_c05a1c4c(aiStack_98,1,(undefined4 *)0x0,(undefined4 *)0x0,&local_a4,param_3);
      puVar1 = local_a4;
      if ((dwErrCode == 0x7a) && (local_a4 < (undefined4 *)0x10001)) {
        piVar3 = FUN_c05a4228((SIZE_T)local_a4);
        local_a0 = piVar3;
        if (piVar3 == (int *)0x0) {
          dwErrCode = 0xe;
        }
        else {
          dwErrCode = FUN_c05a1c4c(aiStack_98,1,piVar3,puVar1,&local_a4,param_3);
          if (dwErrCode == 0) {
            local_a4 = (undefined4 *)param_1[1];
            dwErrCode = FUN_c05a33d8((int)piVar3);
            if (dwErrCode == 0) {
              dwErrCode = FUN_c05a76b4(*param_1,piVar3,(uint *)&local_a4);
              param_1[1] = (uint)local_a4;
            }
          }
        }
      }
    }
    InterlockedDecrement((LONG *)&DAT_c05b6354);
    if (piVar3 != (int *)0x0) {
      FUN_c05a42b0(piVar3);
    }
    if (dwErrCode == 0) {
      return 1;
    }
    SetLastError(dwErrCode);
  }
  return 0;
}



/* c05a379c FUN_c05a379c */

/* Boundary evidence: original MIPS .pdata c05a379c..c05a37a7. Semantic name remains unreviewed. */

undefined4 FUN_c05a379c(void)

{
  return 1;
}



/* c05a37a8 FUN_c05a37a8 */

/* Boundary evidence: original MIPS .pdata c05a37a8..c05a3917. Semantic name remains unreviewed. */

undefined4 FUN_c05a37a8(uint *param_1,uint param_2)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  uint uVar5;
  uint local_238;
  DWORD local_234;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c05b62e4;
  InterlockedIncrement((LONG *)&DAT_c05b6354);
  if (0xb < param_2) {
    puVar3 = (undefined4 *)param_1[2];
    iVar1 = FUN_c05a1bb8((int)puVar3,0x58,1);
    if (iVar1 == 0) {
      DVar4 = 0x57;
    }
    else {
      uVar5 = *param_1;
      local_238 = param_1[1];
      HVar2 = StringCchCopyW(awStack_230,0x104,(STRSAFE_LPCWSTR)*puVar3);
      if (HVar2 == 0) {
        DVar4 = FUN_c05a6c60(uVar5,awStack_230,&local_238);
      }
      else {
        DVar4 = 0xd;
      }
      param_1[1] = local_238;
      local_234 = DVar4;
    }
    InterlockedDecrement((LONG *)&DAT_c05b6354);
    if (DVar4 == 0) {
      FUN_c05b4904(local_28);
      return 1;
    }
  }
  FUN_c05b4904(local_28);
  return 0;
}



/* c05a3918 FUN_c05a3918 */

/* Boundary evidence: original MIPS .pdata c05a3918..c05a3923. Semantic name remains unreviewed. */

undefined4 FUN_c05a3918(void)

{
  return 1;
}



/* c05a3924 ZCF_Init */

/* Boundary evidence: original MIPS .pdata c05a3924..c05a3947. Semantic name remains unreviewed. */

undefined4 ZCF_Init(void)

{
                    /* 0x3924  4  ZCF_Init */
  FUN_c05a9b54();
  return 0xbeeffeed;
}



/* c05a3948 ZCF_Close */

undefined4 ZCF_Close(void)

{
                    /* 0x3948  1  ZCF_Close
                       0x3948  2  ZCF_Deinit */
  return 1;
}



/* c05a3950 ZCF_Open */

undefined4 ZCF_Open(void)

{
                    /* 0x3950  5  ZCF_Open */
  return 0xbeeffeed;
}



/* c05a395c ZCF_Read */

undefined4 ZCF_Read(void)

{
                    /* 0x395c  6  ZCF_Read */
  return 0xc0000001;
}



/* c05a3968 ZCF_Seek */

undefined4 ZCF_Seek(void)

{
                    /* 0x3968  7  ZCF_Seek
                       0x3968  8  ZCF_Write */
  return 0xffffffff;
}



/* c05a3970 ZCF_IOControl */

/* Boundary evidence: original MIPS .pdata c05a3970..c05a3c6b. Semantic name remains unreviewed. */

undefined4
ZCF_IOControl(undefined4 param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6,
             undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint *local_2c;
  uint *local_28;
  undefined4 local_24;
  
                    /* 0x3970  3  ZCF_IOControl */
  uVar2 = 1;
  uVar3 = 1;
  local_24 = 0;
  local_2c = (uint *)0x0;
  local_28 = (uint *)0x0;
  if (((param_3 != 0) && (param_4 != 0)) &&
     (iVar1 = CeAllocAsynchronousBuffer(&local_2c,param_3,param_4,0xc,1), iVar1 != 0)) {
    uVar2 = 0;
    goto LAB_c05a3bec;
  }
  if (((param_5 != 0) && (param_6 != 0)) &&
     (iVar1 = CeAllocAsynchronousBuffer(&local_28,param_5,param_6,0xc,uVar3), iVar1 != 0)) {
    uVar2 = 0;
    goto LAB_c05a3bec;
  }
  if (param_2 < 0x120c29) {
    if (param_2 == 0x120c28) {
      uVar2 = FUN_c05a2fac(local_28,param_6,&local_24);
      uVar3 = uVar2;
    }
    else if (param_2 == 0x120c00) {
      uVar2 = FUN_c05a2964(local_28,param_6,(wchar_t *)&local_24);
      uVar3 = uVar2;
    }
    else if (param_2 == 0x120c08) {
      iVar1 = 0;
LAB_c05a3adc:
      uVar2 = FUN_c05a353c(local_2c,param_4,iVar1);
      uVar3 = uVar2;
    }
    else if (param_2 == 0x120c0c) {
      uVar2 = FUN_c05a37a8(local_2c,param_4);
      uVar3 = uVar2;
    }
    else if (param_2 == 0x120c10) {
      uVar2 = FUN_c05a2ddc(local_28,param_6,&local_24);
      uVar3 = uVar2;
    }
  }
  else if (param_2 == 0x120c2c) {
    uVar2 = FUN_c05a3084((int *)local_2c,param_4);
    uVar3 = uVar2;
  }
  else if (param_2 == 0x120c38) {
    uVar2 = FUN_c05a30ec(local_28,param_6,&local_24);
    uVar3 = uVar2;
  }
  else if (param_2 == 0x120c3c) {
    iVar1 = 1;
    goto LAB_c05a3adc;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = local_24;
  }
LAB_c05a3bec:
  if (local_2c != (uint *)0x0) {
    CeFreeAsynchronousBuffer(local_2c,param_3,param_4,0xc,uVar3);
  }
  if (local_28 != (uint *)0x0) {
    CeFreeAsynchronousBuffer(local_28,param_5,param_6,0xc,uVar3);
  }
  return uVar2;
}



/* c05a3c6c FUN_c05a3c6c */

/* Boundary evidence: original MIPS .pdata c05a3c6c..c05a3c77. Semantic name remains unreviewed. */

undefined4 FUN_c05a3c6c(void)

{
  return 1;
}



/* c05a3c78 FUN_c05a3c78 */

/* Boundary evidence: original MIPS .pdata c05a3c78..c05a3eb7. Semantic name remains unreviewed. */

undefined4 FUN_c05a3c78(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_c05b649c == 0) {
    uVar1 = CXUtilGetProcAddresses
                      (L"eapol.dll",&DAT_c05b649c,L"EolSSDelete",&DAT_c05b647c,
                       L"EolSS8021xEnableGet",&DAT_c05b651c,L"EolSS8021xEnableSet",&DAT_c05b6484,
                       L"EolSSEapTypeGet",&DAT_c05b64d8,L"EolSSEapTypeSet",&DAT_c05b64a0,
                       L"EolSSConnectionDataGet",&DAT_c05b6488,L"EolSSConnectionDataSet",
                       &DAT_c05b6480,L"EolSessionCreate",&DAT_c05b6520,L"EolSessionDestroy",
                       &DAT_c05b6530,L"EolSessionUserLogon",&DAT_c05b64e4,L"EolSessionUserLogoff",
                       &DAT_c05b64f8,L"EolSessionMediaConnect",&DAT_c05b6498,
                       L"EolSessionMediaDisconnect",&DAT_c05b652c,L"EolSessionSetMACAddresses",
                       &DAT_c05b64e8,L"EolSessionSetStationRSNIE",&DAT_c05b6528,
                       L"EolSessionMediaSpecific",&DAT_c05b6524,L"EolSessionProcessRxPacket",
                       &DAT_c05b64dc,L"EolSessionKeyMaterialSet",&DAT_c05b64f4,
                       L"EolSessionGetSendKey",&DAT_c05b64f0,L"EolSessionSetStartDelay",
                       &DAT_c05b6494,L"EolEnumExtensions",&DAT_c05b64d4,
                       L"EolSessionSetExpectedPMKID",&DAT_c05b64e0,0);
  }
  return uVar1;
}



/* c05a3eb8 FUN_c05a3eb8 */

/* Boundary evidence: original MIPS .pdata c05a3eb8..c05a3efb. Semantic name remains unreviewed. */

void FUN_c05a3eb8(void)

{
  if (DAT_c05b649c != 0) {
    FreeLibrary((HMODULE)DAT_c05b649c);
    DAT_c05b649c = 0;
  }
  return;
}



/* c05a3efc FUN_c05a3efc */

/* Boundary evidence: original MIPS .pdata c05a3efc..c05a3f83. Semantic name remains unreviewed. */

undefined4 FUN_c05a3efc(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b64c0);
  FUN_c05a3c78();
  if (DAT_c05b649c != 0) {
    if (DAT_c05b64ec == 0) {
      CTEStopTimer(&DAT_c05b6500);
    }
    DAT_c05b64ec = DAT_c05b64ec + 1;
    uVar1 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b64c0);
  return uVar1;
}



/* c05a3f84 FUN_c05a3f84 */

/* Boundary evidence: original MIPS .pdata c05a3f84..c05a3fdf. Semantic name remains unreviewed. */

void FUN_c05a3f84(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b64c0);
  if ((DAT_c05b64ec == 0) && (DAT_c05b648c == 0)) {
    FUN_c05a3eb8();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b64c0);
  return;
}



/* c05a3fe0 FUN_c05a3fe0 */

/* Boundary evidence: original MIPS .pdata c05a3fe0..c05a406b. Semantic name remains unreviewed. */

void FUN_c05a3fe0(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b64c0);
  DAT_c05b64ec = DAT_c05b64ec + -1;
  if ((DAT_c05b64ec == 0) && (DAT_c05b648c == 0)) {
    CTEStopTimer(&DAT_c05b6500);
    CTEStartTimer(&DAT_c05b6500,DAT_c05b6490,FUN_c05a3f84,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b64c0);
  return;
}



/* c05a406c FUN_c05a406c */

/* Boundary evidence: original MIPS .pdata c05a406c..c05a4157. Semantic name remains unreviewed. */

void FUN_c05a406c(void)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
  if (DAT_c05b6300 == 0) {
    DAT_c05b6300 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05b64c0);
    DAT_c05b649c = 0;
    DAT_c05b64ec = 0;
    DAT_c05b648c = 1;
    CTEInitTimer(&DAT_c05b6500);
    DAT_c05b6490 = 30000;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\BuiltIn\\ZeroConfig",0,0,local_18);
    if (LVar1 == 0) {
      GetRegDWORDValue(local_18[0],L"NeverUnloadEapol",&DAT_c05b648c);
      GetRegDWORDValue(local_18[0],L"UnloadEapolDelayMs",&DAT_c05b6490);
      RegCloseKey(local_18[0]);
    }
  }
  return;
}



/* c05a4158 FUN_c05a4158 */

/* Boundary evidence: original MIPS .pdata c05a4158..c05a4227. Semantic name remains unreviewed. */

void FUN_c05a4158(undefined4 param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  HKEY local_228;
  DWORD local_224;
  DWORD aDStack_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c05b62e4;
  param_2[0] = '\0';
  param_2[1] = '\0';
  param_2[2] = '\0';
  param_2[3] = '\0';
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,awStack_218,0,0x20019,&local_228);
  if (LVar1 == 0) {
    local_224 = 4;
    RegQueryValueExW(local_228,L"Enable8021x",(LPDWORD)0x0,aDStack_220,param_2,&local_224);
    RegCloseKey(local_228);
  }
  FUN_c05b4904(local_10);
  return;
}



/* c05a4228 FUN_c05a4228 */

/* Boundary evidence: original MIPS .pdata c05a4228..c05a42af. Semantic name remains unreviewed. */

HLOCAL FUN_c05a4228(SIZE_T param_1)

{
  HLOCAL pvVar1;
  DWORD dwErrCode;
  
  pvVar1 = (HLOCAL)0x0;
  dwErrCode = 0;
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    if (param_1 == 0) {
      pvVar1 = (HLOCAL)0x0;
    }
    else {
      pvVar1 = LocalAlloc(0x40,param_1);
    }
    if (pvVar1 == (HLOCAL)0x0) {
      dwErrCode = GetLastError();
    }
  }
  SetLastError(dwErrCode);
  return pvVar1;
}



/* c05a42b0 FUN_c05a42b0 */

/* Boundary evidence: original MIPS .pdata c05a42b0..c05a42d3. Semantic name remains unreviewed. */

void FUN_c05a42b0(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    LocalFree(param_1);
  }
  return;
}



/* c05a42d4 FUN_c05a42d4 */

/* Boundary evidence: original MIPS .pdata c05a42d4..c05a43a3. Semantic name remains unreviewed. */

uint * FUN_c05a42d4(uint *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 != (uint *)0x0) && (uVar3 = *param_1, param_3 < uVar3)) {
    uVar4 = *(uint *)(param_2 + 0x60);
    puVar2 = param_1 + param_3 * 0x31 + 2;
    do {
      if (((puVar2[0x18] == uVar4) && (puVar2[4] == *(size_t *)(param_2 + 0x10))) &&
         (iVar1 = memcmp(puVar2 + 5,(void *)(param_2 + 0x14),puVar2[4]), iVar1 == 0)) {
        return puVar2;
      }
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 0x31;
    } while (param_3 < uVar3);
  }
  return (uint *)0x0;
}



/* c05a43a4 FUN_c05a43a4 */

/* Boundary evidence: original MIPS .pdata c05a43a4..c05a44c3. Semantic name remains unreviewed. */

undefined4 FUN_c05a43a4(int param_1,int param_2,undefined4 *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = 1;
  if ((((((*(uint *)(param_1 + 4) ^ *(uint *)(param_2 + 4)) & 1) == 0) &&
       (*(int *)(param_1 + 0x34) == *(int *)(param_2 + 0x34))) &&
      (*(int *)(param_1 + 0x60) == *(int *)(param_2 + 0x60))) &&
     (*(int *)(param_1 + 0x94) == *(int *)(param_2 + 0x94))) {
    iVar3 = memcmp((void *)(param_1 + 0x10),(void *)(param_2 + 0x10),0x24);
    bVar1 = false;
    if (iVar3 != 0) goto LAB_c05a442c;
  }
  else {
LAB_c05a442c:
    bVar1 = true;
  }
  if ((*(int *)(param_1 + 0x6c) == *(int *)(param_2 + 0x6c)) &&
     (*(int *)(param_1 + 0x70) == *(int *)(param_2 + 0x70))) {
    iVar3 = memcmp((void *)(param_1 + 0x74),(void *)(param_2 + 0x74),0x20);
    bVar2 = false;
    if (iVar3 == 0) goto LAB_c05a446c;
  }
  bVar2 = true;
LAB_c05a446c:
  if (param_3 != (undefined4 *)0x0) {
    if ((bVar1) || (uVar4 = 1, !bVar2)) {
      uVar4 = 0;
    }
    *param_3 = uVar4;
  }
  if ((bVar1) || (bVar2)) {
    uVar5 = 0;
  }
  return uVar5;
}



/* c05a44c4 FUN_c05a44c4 */

/* Boundary evidence: original MIPS .pdata c05a44c4..c05a4683. Semantic name remains unreviewed. */

uint * FUN_c05a44c4(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar5 = *param_1;
  puVar4 = (uint *)param_1[1];
  puVar3 = (uint *)0x0;
  if (((3 < uVar5) && (puVar4 != (uint *)0x0)) &&
     (puVar3 = FUN_c05a4228(*puVar4 * 0xc4 + 8), puVar3 != (uint *)0x0)) {
    uVar1 = *puVar4;
    uVar5 = uVar5 - 4;
    *puVar3 = uVar1;
    uVar7 = 0;
    if (uVar1 != 0) {
      puVar6 = puVar3 + 4;
      puVar4 = puVar4 + 1;
      do {
        if (uVar5 < 5) {
          return puVar3;
        }
        uVar1 = *puVar4;
        if (uVar5 < uVar1) {
          return puVar3;
        }
        uVar2 = *puVar4;
        puVar6[-2] = 0xc4;
        *puVar6 = puVar4[1];
        uVar5 = uVar5 - uVar2;
        *(short *)(puVar6 + 1) = (short)puVar4[2];
        memcpy(puVar6 + 2,puVar4 + 3,0x24);
        puVar6[0xb] = (uint)(puVar4[0xc] == 0);
        puVar6[0xc] = puVar4[0xd];
        puVar6[0xd] = puVar4[0xe];
        memcpy(puVar6 + 0xe,puVar4 + 0xf,0x20);
        puVar6[0x16] = puVar4[0x17];
        puVar6[0x17] = puVar4[0x18];
        puVar6[0x18] = puVar4[0x19];
        if (((DAT_c05b6360 != 0) && (0x73 < *puVar4)) &&
           ((uVar2 = puVar4[0x1c], 0xb < uVar2 && (uVar2 <= *puVar4 - 0x74)))) {
          FUN_c05aa994((int)(puVar4 + 0x20),uVar2 - 0xc,(int)(puVar6 + -2),(int *)0x0);
        }
        uVar7 = uVar7 + 1;
        puVar6 = puVar6 + 0x31;
        puVar4 = (uint *)(uVar1 + (int)puVar4);
      } while (uVar7 < *puVar3);
    }
  }
  return puVar3;
}



/* c05a4684 FUN_c05a4684 */

/* Boundary evidence: original MIPS .pdata c05a4684..c05a46fb. Semantic name remains unreviewed. */

void FUN_c05a4684(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_1 != (uint *)0x0) {
    uVar2 = 0;
    if (*param_1 != 0) {
      puVar1 = param_1 + 0x29;
      do {
        if ((HLOCAL)*puVar1 != (HLOCAL)0x0) {
          LocalFree((HLOCAL)*puVar1);
        }
        uVar2 = uVar2 + 1;
        puVar1 = puVar1 + 0x31;
      } while (uVar2 < *param_1);
    }
    LocalFree(param_1);
  }
  return;
}



/* c05a46fc FUN_c05a46fc */

/* Boundary evidence: original MIPS .pdata c05a46fc..c05a4773. Semantic name remains unreviewed. */

undefined4 FUN_c05a46fc(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  param_1->SpinCount = 1;
  return 0;
}



/* c05a4774 FUN_c05a4774 */

/* Boundary evidence: original MIPS .pdata c05a4774..c05a477f. Semantic name remains unreviewed. */

undefined4 FUN_c05a4774(void)

{
  return 1;
}



/* c05a4780 FUN_c05a4780 */

/* Boundary evidence: original MIPS .pdata c05a4780..c05a479f. Semantic name remains unreviewed. */

undefined4 FUN_c05a4780(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return 0;
}



/* c05a47a0 FUN_c05a47a0 */

/* Boundary evidence: original MIPS .pdata c05a47a0..c05a486b. Semantic name remains unreviewed. */

undefined4 FUN_c05a47a0(byte *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = CeGenRandom(param_2,param_1);
  if (iVar1 == 0) {
    uVar2 = 0xd;
  }
  else if (param_2 != 0) {
    iVar1 = (param_4 - param_3) + 1;
    do {
      if (iVar1 == 0) {
        trap(0x1c00);
      }
      if ((iVar1 == -1) && (*param_1 == 0x80000000)) {
        trap(0x1800);
      }
      *param_1 = (char)((int)(uint)*param_1 % iVar1) + (char)param_3;
      param_2 = param_2 + -1;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return uVar2;
}



/* c05a486c FUN_c05a486c */

bool FUN_c05a486c(char *param_1,int param_2)

{
  for (; (param_2 != 0 && (*param_1 == '\0')); param_1 = param_1 + 1) {
    param_2 = param_2 + -1;
  }
  return param_2 == 0;
}



/* c05a48a0 FUN_c05a48a0 */

/* Boundary evidence: original MIPS .pdata c05a48a0..c05a48f7. Semantic name remains unreviewed. */

void FUN_c05a48a0(undefined4 *param_1)

{
  if ((HLOCAL)param_1[1] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
  }
  if ((HLOCAL)param_1[3] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[3]);
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}



/* c05a48f8 FUN_c05a48f8 */

/* Boundary evidence: original MIPS .pdata c05a48f8..c05a492f. Semantic name remains unreviewed. */

void FUN_c05a48f8(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_c05a48a0(param_1);
    LocalFree(param_1);
  }
  return;
}



/* c05a4930 FUN_c05a4930 */

/* Boundary evidence: original MIPS .pdata c05a4930..c05a4aa7. Semantic name remains unreviewed. */

DWORD FUN_c05a4930(DWORD *param_1,DWORD *param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  DATA_BLOB local_38;
  DATA_BLOB local_30;
  DATA_BLOB local_28;
  
  local_38.cbData = 0;
  local_38.pbData = (BYTE *)0x0;
  local_28.cbData = 0;
  local_28.pbData = (BYTE *)0x0;
  if ((param_1 == (DWORD *)0x0) || (param_2 == (DWORD *)0x0)) {
    DVar2 = 0x57;
  }
  else {
    local_30.cbData = *param_2;
    local_30.pbData = (BYTE *)(param_2 + 1);
    BVar1 = CryptProtectData(&local_30,L"",(DATA_BLOB *)0x0,(PVOID)0x0,
                             (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000004,&local_38);
    if (BVar1 != 0) {
      local_30.cbData = *param_2;
      local_30.pbData = (BYTE *)(param_2 + 9);
      BVar1 = CryptProtectData(&local_30,L"",(DATA_BLOB *)0x0,(PVOID)0x0,
                               (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000004,&local_28);
      if (BVar1 != 0) {
        *param_1 = local_38.cbData;
        param_1[1] = (DWORD)local_38.pbData;
        param_1[2] = local_28.cbData;
        param_1[3] = (DWORD)local_28.pbData;
        return 0;
      }
    }
    DVar2 = GetLastError();
  }
  if (DVar2 != 0) {
    if (local_38.pbData != (BYTE *)0x0) {
      LocalFree(local_38.pbData);
    }
    if (local_28.pbData != (BYTE *)0x0) {
      LocalFree(local_28.pbData);
    }
  }
  return DVar2;
}



/* c05a4aa8 FUN_c05a4aa8 */

/* Boundary evidence: original MIPS .pdata c05a4aa8..c05a4c0f. Semantic name remains unreviewed. */

DWORD FUN_c05a4aa8(DATA_BLOB *param_1,size_t *param_2)

{
  DWORD _Size;
  BOOL BVar1;
  DWORD DVar2;
  DATA_BLOB local_28;
  DATA_BLOB local_20;
  
  local_28.cbData = 0;
  local_28.pbData = (BYTE *)0x0;
  DVar2 = 0;
  local_20.cbData = 0;
  local_20.pbData = (BYTE *)0x0;
  if ((param_1 == (DATA_BLOB *)0x0) || (param_2 == (size_t *)0x0)) {
    DVar2 = 0x57;
    goto LAB_c05a4bc4;
  }
  BVar1 = CryptUnprotectData(param_1,(LPWSTR *)0x0,(DATA_BLOB *)0x0,(PVOID)0x0,
                             (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000004,&local_28);
  if (BVar1 == 0) {
LAB_c05a4b28:
    DVar2 = GetLastError();
  }
  else {
    if (local_28.cbData < 0x21) {
      BVar1 = CryptUnprotectData(param_1 + 1,(LPWSTR *)0x0,(DATA_BLOB *)0x0,(PVOID)0x0,
                                 (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000004,&local_20);
      _Size = local_20.cbData;
      if (BVar1 == 0) goto LAB_c05a4b28;
      if (local_20.cbData == local_28.cbData) {
        *param_2 = local_28.cbData;
        memcpy(param_2 + 1,local_28.pbData,local_28.cbData);
        memcpy(param_2 + 9,local_20.pbData,_Size);
        goto LAB_c05a4bc4;
      }
    }
    DVar2 = 0xd;
  }
LAB_c05a4bc4:
  if (local_28.pbData != (BYTE *)0x0) {
    LocalFree(local_28.pbData);
  }
  if (local_20.pbData != (BYTE *)0x0) {
    LocalFree(local_20.pbData);
  }
  return DVar2;
}



/* c05a4c10 FUN_c05a4c10 */

/* Boundary evidence: original MIPS .pdata c05a4c10..c05a4c37. Semantic name remains unreviewed. */

undefined4 FUN_c05a4c10(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x57;
  if (param_1 != 0) {
    InterlockedIncrement((LONG *)(param_1 + 0x1c));
    uVar1 = 0;
  }
  return uVar1;
}



/* c05a4c38 FUN_c05a4c38 */

/* Boundary evidence: original MIPS .pdata c05a4c38..c05a4c5f. Semantic name remains unreviewed. */

undefined4 FUN_c05a4c38(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x57;
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    uVar1 = 0;
  }
  return uVar1;
}



/* c05a4c60 FUN_c05a4c60 */

/* Boundary evidence: original MIPS .pdata c05a4c60..c05a4cfb. Semantic name remains unreviewed. */

undefined4 FUN_c05a4c60(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  DAT_c05b6320 = 1;
  DAT_c05b6338 = 0;
  DAT_c05b6340 = &DAT_c05b633c;
  DAT_c05b633c = &DAT_c05b633c;
  DAT_c05b6344 = 0;
  return 0;
}



/* c05a4cfc FUN_c05a4cfc */

/* Boundary evidence: original MIPS .pdata c05a4cfc..c05a4d07. Semantic name remains unreviewed. */

undefined4 FUN_c05a4cfc(void)

{
  return 1;
}



/* c05a4d08 FUN_c05a4d08 */

/* Boundary evidence: original MIPS .pdata c05a4d08..c05a4d4b. Semantic name remains unreviewed. */

DWORD FUN_c05a4d08(void)

{
  DWORD DVar1;
  
  DAT_c05b6348 = FUN_c05a92a8();
  if (DAT_c05b6348 == (undefined4 *)0x0) {
    DVar1 = GetLastError();
  }
  else {
    DVar1 = 0;
  }
  return DVar1;
}



/* c05a4d4c FUN_c05a4d4c */

/* Boundary evidence: original MIPS .pdata c05a4d4c..c05a4f03. Semantic name remains unreviewed. */

DWORD FUN_c05a4d4c(undefined4 *param_1,undefined4 *param_2)

{
  HLOCAL pvVar1;
  DWORD DVar2;
  int iVar3;
  wchar_t *pwVar4;
  
  *param_2 = 0;
  pvVar1 = FUN_c05a4228(0x168);
  if (pvVar1 == (HLOCAL)0x0) goto LAB_c05a4d94;
  *(HLOCAL *)((int)pvVar1 + 4) = pvVar1;
  *(HLOCAL *)pvVar1 = pvVar1;
  DVar2 = FUN_c05a46fc((LPCRITICAL_SECTION)((int)pvVar1 + 8));
  if (DVar2 != 0) goto LAB_c05a4ea0;
  *(undefined4 *)((int)pvVar1 + 0x20) = 0x8002;
  *(undefined4 *)((int)pvVar1 + 0x28) = 0;
  *(undefined4 *)((int)pvVar1 + 0x24) = 0;
  *(undefined4 *)((int)pvVar1 + 0x2c) = 0xffffffff;
  if (param_1 == (undefined4 *)0x0) {
LAB_c05a4e74:
    *(undefined4 *)((int)pvVar1 + 0x60) = 0xffffffff;
    *(undefined4 *)((int)pvVar1 + 0x74) = 0xc4;
    *(undefined4 *)((int)pvVar1 + 0xd4) = 0xffffffff;
    *(undefined4 *)((int)pvVar1 + 0x108) = 0xffffffff;
    *(undefined4 *)((int)pvVar1 + 0xa8) = 0xffffffff;
    *(undefined4 *)((int)pvVar1 + 0x150) = 0;
  }
  else {
    iVar3 = FUN_c05a93f0((undefined4 *)((int)pvVar1 + 0x2c),DAT_c05b6348,FUN_c05a8c48,pvVar1,
                         0x70000000,0x70000000);
    if (iVar3 != 0) {
      *(undefined4 *)((int)pvVar1 + 0x30) = *param_1;
      iVar3 = param_1[1];
      if ((uint)param_1[2] >> 1 != 0) {
        pwVar4 = FUN_c05a4228(((uint)param_1[2] >> 1) << 1);
        *(wchar_t **)((int)pvVar1 + 0x34) = pwVar4;
        if (pwVar4 == (wchar_t *)0x0) goto LAB_c05a4d94;
        wcscpy(pwVar4,(wchar_t *)(iVar3 + (int)param_1));
      }
      iVar3 = param_1[3];
      if (param_1[4] != 0) {
        pwVar4 = FUN_c05a4228(param_1[4]);
        *(wchar_t **)((int)pvVar1 + 0x48) = pwVar4;
        if (pwVar4 == (wchar_t *)0x0) goto LAB_c05a4d94;
        wcscpy(pwVar4,(wchar_t *)(iVar3 + (int)param_1));
      }
      goto LAB_c05a4e74;
    }
LAB_c05a4d94:
    DVar2 = GetLastError();
  }
  if (DVar2 == 0) {
    *param_2 = pvVar1;
    return 0;
  }
LAB_c05a4ea0:
  if (pvVar1 != (HLOCAL)0x0) {
    if (*(int **)((int)pvVar1 + 0x2c) != (int *)0x0) {
      FUN_c05a9594(DAT_c05b6348,*(int **)((int)pvVar1 + 0x2c),-1);
    }
    FUN_c05a42b0(*(HLOCAL *)((int)pvVar1 + 0x48));
    FUN_c05a42b0(*(HLOCAL *)((int)pvVar1 + 0x34));
  }
  FUN_c05a42b0(pvVar1);
  return DVar2;
}



/* c05a4f04 FUN_c05a4f04 */

/* Boundary evidence: original MIPS .pdata c05a4f04..c05a4fb3. Semantic name remains unreviewed. */

void FUN_c05a4f04(int param_1)

{
  size_t sVar1;
  int iVar2;
  CHAR aCStack_30 [32];
  uint local_10;
  
  local_10 = DAT_c05b62e4;
  iVar2 = *(int *)(param_1 + 0x150);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x220) != 0)) {
    WideCharToMultiByte(1,0,(LPCWSTR)(iVar2 + 0x118),-1,aCStack_30,0x20,(LPCSTR)0x0,(LPBOOL)0x0);
    sVar1 = strlen(aCStack_30);
    FUN_c05a8fbc(7,aCStack_30,sVar1,0,*(undefined4 *)(param_1 + 0xd4),*(wchar_t **)(param_1 + 0x34),
                 (undefined4 *)0x0);
  }
  FUN_c05b4904(local_10);
  return;
}



/* c05a4fb4 FUN_c05a4fb4 */

/* Boundary evidence: original MIPS .pdata c05a4fb4..c05a5097. Semantic name remains unreviewed. */

DWORD FUN_c05a4fb4(HLOCAL param_1)

{
  DWORD DVar1;
  
  if (param_1 == (HLOCAL)0x0) {
    DVar1 = 0x57;
  }
  else {
    if (*(int **)((int)param_1 + 0x2c) != (int *)0xffffffff) {
      FUN_c05a9594(DAT_c05b6348,*(int **)((int)param_1 + 0x2c),0);
    }
    DVar1 = FUN_c05aee38((int)param_1);
    if (*(int *)((int)param_1 + 0x150) != 0) {
      FUN_c05a4f04((int)param_1);
      FUN_c05aea6c(*(int *)((int)param_1 + 0x150));
      *(undefined4 *)((int)param_1 + 0x150) = 0;
    }
    FUN_c05acb68(*(LPCRITICAL_SECTION *)((int)param_1 + 0x70));
    FUN_c05a42b0(*(HLOCAL *)((int)param_1 + 0x68));
    *(undefined4 *)((int)param_1 + 0x68) = 0;
    FUN_c05a42b0(*(HLOCAL *)((int)param_1 + 0x34));
    FUN_c05a42b0(*(HLOCAL *)((int)param_1 + 0x48));
    FUN_c05a42b0(*(HLOCAL *)((int)param_1 + 0x138));
    FUN_c05a42b0(*(HLOCAL *)((int)param_1 + 0x13c));
    FUN_c05a4684(*(uint **)((int)param_1 + 0x140));
    FUN_c05a48f8(*(undefined4 **)((int)param_1 + 0x148));
    FUN_c05a4684(*(uint **)((int)param_1 + 0x144));
    FUN_c05a4780((LPCRITICAL_SECTION)((int)param_1 + 8));
    FUN_c05a42b0(param_1);
  }
  return DVar1;
}



/* c05a5098 FUN_c05a5098 */

undefined4 FUN_c05a5098(void)

{
  return DAT_c05b6344;
}



/* c05a50a8 FUN_c05a50a8 */

/* Boundary evidence: original MIPS .pdata c05a50a8..c05a511b. Semantic name remains unreviewed. */

void FUN_c05a50a8(undefined4 *param_1)

{
  DWORD DVar1;
  
  DVar1 = FUN_c05af150(DAT_c05b6338,(wchar_t *)param_1[0xd],param_1,&DAT_c05b6338);
  if (DVar1 == 0) {
    *param_1 = &DAT_c05b633c;
    param_1[1] = DAT_c05b6340;
    *DAT_c05b6340 = param_1;
    DAT_c05b6344 = DAT_c05b6344 + 1;
    DAT_c05b6340 = param_1;
  }
  return;
}



/* c05a511c FUN_c05a511c */

/* Boundary evidence: original MIPS .pdata c05a511c..c05a51c3. Semantic name remains unreviewed. */

void FUN_c05a511c(wchar_t *param_1,undefined4 *param_2)

{
  int iVar1;
  DWORD DVar2;
  int *local_18;
  int *local_14;
  
  local_18 = (int *)0x0;
  iVar1 = FUN_c05af55c((int)DAT_c05b6338,param_1,(int *)&local_14);
  if ((iVar1 == 0) &&
     (DVar2 = FUN_c05af650(DAT_c05b6338,local_14,(int *)&local_18,&DAT_c05b6338), DVar2 == 0)) {
    *(int *)local_18[1] = *local_18;
    *(int *)(*local_18 + 4) = local_18[1];
    local_18[1] = (int)local_18;
    *local_18 = (int)local_18;
    DAT_c05b6344 = DAT_c05b6344 + -1;
  }
  *param_2 = local_18;
  return;
}



/* c05a51c4 FUN_c05a51c4 */

/* Boundary evidence: original MIPS .pdata c05a51c4..c05a5313. Semantic name remains unreviewed. */

DWORD FUN_c05a51c4(undefined4 *param_1,uint *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  
  DVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  uVar2 = 0;
  puVar3 = param_1;
  puVar4 = DAT_c05b633c;
  if ((undefined4 **)DAT_c05b633c != &DAT_c05b633c) {
    do {
      if (*param_2 <= uVar2) break;
      if ((wchar_t *)puVar4[0xd] == (wchar_t *)0x0) {
        *puVar3 = 0;
      }
      else {
        sVar1 = wcslen((wchar_t *)puVar4[0xd]);
        _Dest = FUN_c05a4228((sVar1 + 1) * 2);
        *puVar3 = _Dest;
        if (_Dest == (wchar_t *)0x0) {
          DVar5 = GetLastError();
          break;
        }
        wcscpy(_Dest,(wchar_t *)puVar4[0xd]);
      }
      puVar4 = (undefined4 *)*puVar4;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while ((undefined4 **)puVar4 != &DAT_c05b633c);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  if (DVar5 == 0) {
    *param_2 = uVar2;
  }
  else {
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      if ((HLOCAL)*param_1 != (HLOCAL)0x0) {
        FUN_c05a42b0((HLOCAL)*param_1);
        *param_1 = 0;
      }
      param_1 = param_1 + 1;
    }
  }
  return DVar5;
}



/* c05a5314 FUN_c05a5314 */

/* Boundary evidence: original MIPS .pdata c05a5314..c05a5463. Semantic name remains unreviewed. */

void FUN_c05a5314(uint *param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  size_t _Size;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c05b62e4;
  iVar1 = FUN_c05a3efc();
  if (iVar1 != 0) {
    if ((param_1 != (uint *)0x0) && (uVar4 = 0, *param_1 != 0)) {
      puVar2 = param_1 + 6;
      do {
        if (param_2 != (uint *)0x0) {
          uVar6 = *param_2;
          uVar5 = 0;
          if (uVar6 != 0) {
            _Size = *puVar2;
            puVar3 = param_2 + 6;
            do {
              if ((*puVar3 == _Size) && (iVar1 = memcmp(puVar3 + 1,puVar2 + 1,_Size), iVar1 == 0))
              goto LAB_c05a5414;
              uVar5 = uVar5 + 1;
              puVar3 = puVar3 + 0x31;
            } while (uVar5 < uVar6);
          }
        }
        memset(aWStack_238,0,0x208);
        MultiByteToWideChar(1,0,(LPCSTR)(puVar2 + 1),*puVar2,aWStack_238,0x104);
        (*DAT_c05b647c)(aWStack_238);
LAB_c05a5414:
        uVar4 = uVar4 + 1;
        puVar2 = puVar2 + 0x31;
      } while (uVar4 < *param_1);
    }
    FUN_c05a3fe0();
  }
  FUN_c05b4904(local_30);
  return;
}



/* c05a5464 FUN_c05a5464 */

undefined4 FUN_c05a5464(void)

{
  return 0;
}



/* c05a546c FUN_c05a546c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c05a546c..c05a5a0f. Semantic name remains unreviewed. */

DWORD FUN_c05a546c(int param_1,int *param_2)

{
  byte bVar1;
  uint *puVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  int local_58;
  DWORD local_50;
  int local_48 [5];
  int local_34 [3];
  
  local_50 = 0;
  local_48[0] = 0;
  memset(local_48 + 1,0,0x18);
  *param_2 = 0;
  puVar12 = (uint *)0x0;
  local_58 = 0;
  if ((*(int **)(param_1 + 0x138) != (int *)0x0) && (uVar10 = 0, **(int **)(param_1 + 0x138) != 0))
  {
    iVar11 = 0;
    do {
      puVar4 = *(uint **)(param_1 + 0x138);
      iVar9 = (int)puVar4 + iVar11 + 8;
      uVar10 = uVar10 + 1;
      puVar2 = FUN_c05a42d4(puVar4,iVar9,uVar10);
      if ((((puVar2 == (uint *)0x0) && ((*(uint *)(param_1 + 0x20) & 0x4000) != 0)) &&
          ((uVar5 = *(uint *)(param_1 + 0x20) & 7, uVar5 == 2 ||
           (uVar5 == *(uint *)((int)puVar4 + iVar11 + 0x68))))) &&
         (puVar2 = FUN_c05a42d4(*(uint **)(param_1 + 0x144),iVar9,0), puVar2 == (uint *)0x0)) {
        iVar9 = *(int *)((int)puVar4 + iVar11 + 0x68);
        if (iVar9 == 1) {
          iVar7 = 1;
        }
        else {
          iVar7 = 4;
          if (iVar9 != 0) goto LAB_c05a556c;
        }
      }
      else {
LAB_c05a556c:
        iVar7 = 6;
      }
      bVar1 = *(byte *)((int)puVar4 + iVar11 + 0x17);
      *(byte *)((int)puVar4 + iVar11 + 0x17) = ((byte)(iVar7 << 2) ^ bVar1) & 0x1c ^ bVar1;
      uVar5 = **(uint **)(param_1 + 0x138);
      local_48[iVar7] = local_48[iVar7] + 1;
      iVar11 = iVar11 + 0xc4;
    } while (uVar10 < uVar5);
  }
  puVar2 = *(uint **)(param_1 + 0x140);
  if (((puVar2 != (uint *)0x0) && (puVar2[1] < *puVar2)) &&
     ((puVar2[puVar2[1] * 0x31 + 3] & 0x10000) == 0)) {
    puVar12 = FUN_c05a42d4(*(uint **)(param_1 + 0x13c),(int)(puVar2 + puVar2[1] * 0x31 + 2),0);
  }
  iVar11 = 5;
  if ((*(int **)(param_1 + 0x13c) != (int *)0x0) && (uVar10 = 0, **(int **)(param_1 + 0x13c) != 0))
  {
    iVar9 = 0;
    do {
      iVar7 = iVar9 + *(int *)(param_1 + 0x13c);
      uVar5 = *(uint *)(param_1 + 0x20) & 7;
      puVar2 = (uint *)(iVar7 + 8);
      if (((uVar5 == 2) || (uVar5 == *(uint *)(iVar7 + 0x68))) &&
         (puVar4 = FUN_c05a42d4(*(uint **)(param_1 + 0x144),(int)puVar2,0), puVar4 == (uint *)0x0))
      {
        puVar4 = FUN_c05a42d4(*(uint **)(param_1 + 0x138),(int)puVar2,0);
        if ((puVar2 == puVar12) || (puVar4 != (uint *)0x0)) {
          if (*(int *)(iVar7 + 0x68) == 1) {
            iVar8 = 0;
          }
          else {
            iVar8 = 3;
            if (*(int *)(iVar7 + 0x68) != 0) {
              iVar8 = 6;
            }
          }
          if (puVar4 != (uint *)0x0) {
            bVar1 = *(byte *)((int)puVar4 + 0xf);
            local_48[bVar1 >> 2 & 7] = local_48[bVar1 >> 2 & 7] + -1;
            *(byte *)((int)puVar4 + 0xf) = bVar1 & 0xe3 | 0x18;
            local_34[1] = local_34[1] + 1;
          }
        }
        else if (*(int *)(iVar7 + 0x68) == 1) {
          iVar8 = 2;
        }
        else if (*(int *)(iVar7 + 0x68) == 0) {
          iVar8 = 5;
        }
        else {
          iVar8 = 6;
        }
        if (*(int *)(param_1 + 0x158) != 0) {
          *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffeffff;
        }
        if ((*(uint *)(iVar7 + 0xc) & 0x10000) != 0) goto LAB_c05a5768;
      }
      else {
LAB_c05a5768:
        iVar8 = 6;
      }
      *(byte *)(iVar7 + 0x17) =
           ((byte)(iVar8 << 2) ^ *(byte *)(iVar7 + 0x17)) & 0x1c ^ *(byte *)(iVar7 + 0x17);
      uVar5 = **(uint **)(param_1 + 0x13c);
      uVar10 = uVar10 + 1;
      local_48[iVar8] = local_48[iVar8] + 1;
      iVar9 = iVar9 + 0xc4;
    } while (uVar10 < uVar5);
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    *(undefined4 *)(param_1 + 0x158) = 0;
  }
  iVar7 = 0;
  piVar3 = local_48;
  iVar9 = 6;
  do {
    iVar7 = *piVar3 + iVar7;
    iVar9 = iVar9 + -1;
    piVar3 = piVar3 + 1;
  } while (iVar9 != 0);
  if (iVar7 != 0) {
    piVar3 = FUN_c05a4228(iVar7 * 0xc4 + 8);
    *param_2 = (int)piVar3;
    if (piVar3 == (int *)0x0) {
      local_50 = GetLastError();
    }
    else {
      *piVar3 = iVar7;
      piVar3 = local_48 + 5;
      *(undefined4 *)(*param_2 + 4) = 0;
      do {
        iVar7 = iVar7 - *piVar3;
        *piVar3 = iVar7;
        iVar11 = iVar11 + -1;
        piVar3 = piVar3 + -1;
      } while (-1 < iVar11);
    }
  }
  iVar11 = 0;
  if ((*(int **)(param_1 + 0x13c) != (int *)0x0) && (uVar10 = 0, **(int **)(param_1 + 0x13c) != 0))
  {
    iVar7 = 0;
    iVar9 = 0;
    do {
      iVar11 = *(int *)(param_1 + 0x13c) + iVar9;
      uVar5 = *(byte *)(iVar11 + 0x17) >> 2 & 7;
      if ((*param_2 != 0) && (uVar5 != 6)) {
        iVar8 = *param_2 + iVar7;
        local_58 = local_58 + 1;
        iVar7 = iVar7 + 0xc4;
        memcpy((void *)(iVar8 + 8),(void *)(iVar11 + 8),0xc4);
        iVar6 = local_48[uVar5];
        *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xfffeffff;
        local_48[uVar5] = iVar6 + 1;
      }
      *(byte *)(iVar11 + 0x17) = *(byte *)(iVar11 + 0x17) & 0xe3;
      uVar10 = uVar10 + 1;
      iVar9 = iVar9 + 0xc4;
      iVar11 = local_58;
    } while (uVar10 < **(uint **)(param_1 + 0x13c));
  }
  if ((*(int **)(param_1 + 0x138) != (int *)0x0) && (uVar10 = 0, **(int **)(param_1 + 0x138) != 0))
  {
    iVar11 = iVar11 * 0xc4;
    iVar9 = 0;
    do {
      iVar7 = *(int *)(param_1 + 0x138) + iVar9;
      uVar5 = *(byte *)(iVar7 + 0x17) >> 2 & 7;
      if ((*param_2 != 0) && (uVar5 != 6)) {
        iVar8 = *param_2 + iVar11;
        iVar11 = iVar11 + 0xc4;
        memcpy((void *)(iVar8 + 8),(void *)(iVar7 + 8),0xc4);
        iVar6 = local_48[uVar5];
        *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xfffeffff;
        local_48[uVar5] = iVar6 + 1;
      }
      *(byte *)(iVar7 + 0x17) = *(byte *)(iVar7 + 0x17) & 0xe3;
      uVar10 = uVar10 + 1;
      iVar9 = iVar9 + 0xc4;
    } while (uVar10 < **(uint **)(param_1 + 0x138));
  }
  return local_50;
}



/* c05a5a10 FUN_c05a5a10 */

/* Boundary evidence: original MIPS .pdata c05a5a10..c05a5b47. Semantic name remains unreviewed. */

undefined4 FUN_c05a5a10(int param_1,uint *param_2,uint *param_3)

{
  byte bVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  
  *param_3 = 0;
  if ((*(int **)(param_1 + 0x140) != (int *)0x0) && (**(int **)(param_1 + 0x140) != 0)) {
    if (param_2 == (uint *)0x0) {
      return 1;
    }
    if (*param_2 != 0) {
      puVar3 = FUN_c05a42d4(param_2,*(int *)(*(int *)(param_1 + 0x140) + 4) * 0xc4 +
                                    *(int *)(param_1 + 0x140) + 8,0);
      if (puVar3 != (uint *)0x0) {
        bVar1 = *(byte *)((int)param_2 + 0x17) >> 2;
        bVar2 = false;
        if (((bVar1 & 7) == 0) || ((bVar1 & 7) == 3)) {
          bVar2 = true;
        }
        if (((*(uint *)(param_1 + 0x20) & 0x8000) != 0) && (*param_2 != 0)) {
          if (!bVar2) {
            return 0;
          }
          iVar4 = FUN_c05a43a4((int)puVar3,(int)(param_2 + 2),(undefined4 *)0x0);
          if (iVar4 != 0) {
            return 0;
          }
        }
      }
      *param_3 = 0;
      return 1;
    }
  }
  if ((param_2 != (uint *)0x0) && (param_2[1] < *param_2)) {
    *param_3 = param_2[1];
  }
  return 1;
}



/* c05a5b48 FUN_c05a5b48 */

/* Boundary evidence: original MIPS .pdata c05a5b48..c05a5f0b. Semantic name remains unreviewed. */

DWORD FUN_c05a5b48(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  DWORD DVar8;
  uint *lpMultiByteStr;
  uint local_1d0 [2];
  undefined4 local_1c8;
  undefined1 auStack_1c4 [16];
  uint local_1b4;
  uint local_1b0;
  uint local_1ac;
  uint local_1a0;
  uint *local_19c;
  int local_180;
  int *local_17c;
  uint local_174;
  int local_170;
  uint local_16c;
  undefined1 local_168 [4];
  undefined1 auStack_164 [20];
  byte local_150 [40];
  WCHAR aWStack_128 [130];
  uint local_24;
  
  local_24 = DAT_c05b62e4;
  DVar8 = 0;
  local_1c8 = 0;
  memset(auStack_1c4,0,0x54);
  puVar3 = *(uint **)(param_1 + 0x140);
  if ((puVar3 == (uint *)0x0) || (*puVar3 <= puVar3[1])) {
    DVar8 = 0x57;
    goto LAB_c05a5ed8;
  }
  uVar4 = puVar3[1];
  lpMultiByteStr = puVar3 + uVar4 * 0x31 + 7;
  iVar2 = MultiByteToWideChar(1,0,(LPCSTR)lpMultiByteStr,puVar3[uVar4 * 0x31 + 6],aWStack_128,0x80);
  aWStack_128[iVar2] = L'\0';
  FUN_c05a4158(aWStack_128,(LPBYTE)(param_1 + 0x160));
  if ((*(int *)(param_1 + 0x160) != 0) &&
     (DVar8 = FUN_c05aeb3c(*(int *)(param_1 + 0x150)), DVar8 != 0)) goto LAB_c05a5ed8;
  local_1b0 = puVar3[uVar4 * 0x31 + 0x27];
  local_1b4 = puVar3[uVar4 * 0x31 + 0x1a];
  local_1a0 = puVar3[uVar4 * 0x31 + 6];
  local_174 = puVar3[uVar4 * 0x31 + 0x31];
  uVar7 = 0x1600000;
  local_19c = lpMultiByteStr;
  if (((puVar3[uVar4 * 0x31 + 0xf] != 1) || (puVar3[uVar4 * 0x31 + 0x27] != 0)) &&
     (uVar5 = puVar3[uVar4 * 0x31 + 0x27], uVar5 != 3)) {
    if ((puVar3[uVar4 * 0x31 + 3] & 1) == 0) {
      if (*(int *)(param_1 + 0x5c) != 9) {
        local_1ac = 1;
        FUN_c05aee90(param_1,(int)&local_1c8,0x40800000,(uint *)0x0);
        DVar8 = FUN_c05aeec4(param_1,0x800000,(uint *)0x0);
        if (*(int *)(param_1 + 0xa8) != 1) {
          puVar1 = local_168 + 3;
          uVar7 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar7) =
               *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 5U >> (3 - uVar7) * 8;
          local_16c = 0x80000000;
          local_168 = (undefined1  [4])0x5;
          memset(auStack_164,0xff,6);
          DVar8 = FUN_c05a47a0(local_150,(int)local_168,0,0xff);
          goto LAB_c05a5d44;
        }
      }
    }
    else if ((uVar5 != 4) && (uVar5 != 7)) {
      local_16c = puVar3[uVar4 * 0x31 + 0x1d] | 0x80000000;
      local_168 = (undefined1  [4])puVar3[uVar4 * 0x31 + 0x1e];
      memset(auStack_164,0xff,6);
      memcpy(local_150,puVar3 + uVar4 * 0x31 + 0x1f,0x20);
      iVar2 = 0;
      uVar7 = 0;
      do {
        uVar5 = uVar7 % 0xd;
        pbVar6 = local_150 + iVar2;
        uVar7 = uVar7 + 7;
        iVar2 = iVar2 + 1;
        *pbVar6 = (&DAT_c05b61a8)[uVar5] ^ *pbVar6;
      } while (uVar7 < 0xe0);
LAB_c05a5d44:
      uVar7 = 0x11600000;
      local_170 = (int)local_168 + 0x20;
    }
    if (puVar3[uVar4 * 0x31 + 0xf] != *(uint *)(param_1 + 0xa8)) {
      uVar7 = uVar7 | 0x800000;
      local_1ac = puVar3[uVar4 * 0x31 + 0xf];
    }
    if ((uVar7 & 0x10000000) != 0) {
      if ((*(uint *)(param_1 + 100) & 0x100) == 0) {
        memmove(auStack_164,local_150,(size_t)local_168);
        local_170 = (int)local_168 + 0xc;
      }
      local_17c = &local_170;
      local_180 = local_170;
    }
  }
  local_1ac = puVar3[uVar4 * 0x31 + 0xf];
  local_174 = puVar3[uVar4 * 0x31 + 0x31];
  if (DVar8 == 0) {
    DVar8 = FUN_c05aee90(param_1,(int)&local_1c8,uVar7 | 0x800000,local_1d0);
    if ((uVar7 & 0x10000000) == 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffdffff;
    }
    else if ((local_1d0[0] & 0x10000000) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffdffff;
    }
  }
LAB_c05a5ed8:
  FUN_c05b4904(local_24);
  return DVar8;
}



/* c05a5f0c FUN_c05a5f0c */

/* Boundary evidence: original MIPS .pdata c05a5f0c..c05a604f. Semantic name remains unreviewed. */

DWORD FUN_c05a5f0c(int param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  uint uVar3;
  DWORD DVar4;
  int iVar5;
  uint uVar6;
  size_t local_80;
  undefined1 auStack_7c [32];
  undefined1 auStack_5c [36];
  byte local_38 [32];
  uint local_18;
  
  local_18 = DAT_c05b62e4;
  puVar2 = *(uint **)(param_1 + 0x140);
  DVar4 = 0;
  if ((((puVar2 != (uint *)0x0) && (puVar2[1] < *puVar2)) &&
      (puVar2 = puVar2 + puVar2[1] * 0x31, puVar2 != (uint *)0xfffffff8)) && ((puVar2[3] & 1) != 0))
  {
    iVar5 = 0;
    uVar3 = 0;
    do {
      uVar6 = uVar3 % 0xd;
      uVar3 = uVar3 + 7;
      local_38[iVar5] = (&DAT_c05b61a8)[uVar6] ^ *(byte *)((int)puVar2 + iVar5 + 0x7c);
      iVar5 = iVar5 + 1;
    } while (uVar3 < 0xe0);
    local_80 = puVar2[0x1e];
    memcpy(auStack_5c,local_38,local_80);
    memcpy(auStack_7c,local_38,local_80);
    FUN_c05a48f8(*(undefined4 **)(param_1 + 0x148));
    pDVar1 = FUN_c05a4228(0x10);
    *(DWORD **)(param_1 + 0x148) = pDVar1;
    if (pDVar1 == (DWORD *)0x0) {
      DVar4 = GetLastError();
    }
    else {
      DVar4 = FUN_c05a4930(pDVar1,&local_80);
    }
  }
  FUN_c05b4904(local_18);
  return DVar4;
}



/* c05a6050 FUN_c05a6050 */

/* Boundary evidence: original MIPS .pdata c05a6050..c05a62cf. Semantic name remains unreviewed. */

DWORD FUN_c05a6050(int param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  DWORD DVar7;
  uint uVar8;
  
  DVar7 = 0;
  piVar2 = *(int **)(param_1 + 0x144);
  uVar6 = 0;
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    iVar4 = *piVar2;
    pcVar3 = (char *)((int)piVar2 + 0x16);
    do {
      if (*pcVar3 != '\0') {
        uVar6 = uVar6 + 1;
      }
      iVar4 = iVar4 + -1;
      pcVar3 = pcVar3 + 0xc4;
    } while (iVar4 != 0);
  }
  piVar2 = *(int **)(param_1 + 0x140);
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    iVar4 = *piVar2;
    puVar5 = (uint *)(piVar2 + 3);
    do {
      if ((*puVar5 & 0x40000) != 0) {
        uVar6 = uVar6 + 1;
      }
      iVar4 = iVar4 + -1;
      puVar5 = puVar5 + 0x31;
    } while (iVar4 != 0);
  }
  if (uVar6 != 0) {
    if ((int)((ulonglong)uVar6 * 0xc4 >> 0x20) == 0) {
      piVar2 = FUN_c05a4228((int)((ulonglong)uVar6 * 0xc4) + 8);
      if (piVar2 == (int *)0x0) {
        DVar7 = GetLastError();
      }
      else {
        if ((*(int **)(param_1 + 0x144) != (int *)0x0) &&
           (uVar8 = 0, **(int **)(param_1 + 0x144) != 0)) {
          iVar4 = 0;
          do {
            if (uVar6 == 0) break;
            iVar1 = iVar4 + *(int *)(param_1 + 0x144);
            if (*(char *)(iVar1 + 0x16) != '\0') {
              memcpy(piVar2 + *piVar2 * 0x31 + 2,(void *)(iVar1 + 8),0xc4);
              uVar6 = uVar6 - 1;
              *(undefined4 *)(iVar1 + 0xa4) = 0;
              *(undefined4 *)(iVar1 + 0xa0) = 0;
              *piVar2 = *piVar2 + 1;
            }
            uVar8 = uVar8 + 1;
            iVar4 = iVar4 + 0xc4;
          } while (uVar8 < **(uint **)(param_1 + 0x144));
        }
        if ((*(int **)(param_1 + 0x140) != (int *)0x0) &&
           (uVar8 = 0, **(int **)(param_1 + 0x140) != 0)) {
          iVar4 = 0;
          do {
            if (uVar6 == 0) break;
            iVar1 = *(int *)(param_1 + 0x140) + iVar4;
            if ((*(uint *)(iVar1 + 0xc) & 0x40000) != 0) {
              memcpy(piVar2 + *piVar2 * 0x31 + 2,(void *)(iVar1 + 8),0xc4);
              *(undefined4 *)(iVar1 + 0xa4) = 0;
              *(undefined4 *)(iVar1 + 0xa0) = 0;
              uVar6 = uVar6 - 1;
              *(undefined1 *)((int)piVar2 + *piVar2 * 0xc4 + 0x16) = 3;
              *piVar2 = *piVar2 + 1;
            }
            uVar8 = uVar8 + 1;
            iVar4 = iVar4 + 0xc4;
          } while (uVar8 < **(uint **)(param_1 + 0x140));
        }
        DVar7 = 0;
        FUN_c05a4684(*(uint **)(param_1 + 0x144));
        *(int **)(param_1 + 0x144) = piVar2;
      }
    }
    else {
      DVar7 = 0xd;
    }
  }
  return DVar7;
}



/* c05a62d0 FUN_c05a62d0 */

/* Boundary evidence: original MIPS .pdata c05a62d0..c05a63eb. Semantic name remains unreviewed. */

undefined4 FUN_c05a62d0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  void *_Dst;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  puVar2 = *(uint **)(param_1 + 0x144);
  if ((puVar2 != (uint *)0x0) && (uVar3 = 0, *puVar2 != 0)) {
    iVar4 = 0;
    do {
      _Dst = (void *)((int)puVar2 + iVar4 + 8);
      puVar1 = FUN_c05a42d4(*(uint **)(param_1 + 0x138),(int)_Dst,0);
      if (puVar1 == (uint *)0x0) {
        *(char *)((int)puVar2 + iVar4 + 0x16) = *(char *)((int)puVar2 + iVar4 + 0x16) + -1;
      }
      else {
        *(undefined1 *)((int)puVar2 + iVar4 + 0x16) = 3;
      }
      if (*(char *)((int)puVar2 + iVar4 + 0x16) == '\0') {
        uVar5 = **(int **)(param_1 + 0x144) - 1;
        FUN_c05a42b0(*(HLOCAL *)((int)puVar2 + iVar4 + 0xa4));
        if (uVar3 != uVar5) {
          memcpy(_Dst,(void *)(uVar5 * 0xc4 + *(int *)(param_1 + 0x144) + 8),0xc4);
        }
        uVar3 = uVar3 - 1;
        iVar4 = iVar4 + -0xc4;
        **(int **)(param_1 + 0x144) = **(int **)(param_1 + 0x144) + -1;
      }
      puVar2 = *(uint **)(param_1 + 0x144);
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0xc4;
    } while (uVar3 < *puVar2);
  }
  return 0;
}



/* c05a63ec FUN_c05a63ec */

/* Boundary evidence: original MIPS .pdata c05a63ec..c05a6443. Semantic name remains unreviewed. */

undefined4 FUN_c05a63ec(HLOCAL param_1)

{
  undefined4 uVar1;
  LONG LVar2;
  
  uVar1 = 0x57;
  if (param_1 != (HLOCAL)0x0) {
    LVar2 = InterlockedDecrement((LONG *)((int)param_1 + 0x1c));
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 8));
    if (LVar2 == 0) {
      FUN_c05a4fb4(param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* c05a6444 FUN_c05a6444 */

/* Boundary evidence: original MIPS .pdata c05a6444..c05a6507. Semantic name remains unreviewed. */

undefined4 FUN_c05a6444(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 auStack_18 [2];
  
  piVar1 = *(int **)(param_1 + 0x2c);
  uVar2 = 0;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffeffff;
  if (piVar1 != (int *)0xffffffff) {
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    FUN_c05a9594(DAT_c05b6348,piVar1,-1);
  }
  if (param_2 != 0) {
    uVar2 = FUN_c05a511c(*(wchar_t **)(param_1 + 0x34),auStack_18);
  }
  if (*(int *)(param_1 + 0x150) != 0) {
    FUN_c05a4f04(param_1);
    FUN_c05aea6c(*(int *)(param_1 + 0x150));
    *(undefined4 *)(param_1 + 0x150) = 0;
  }
  if (*(LONG *)(param_1 + 0x1c) != 0) {
    InterlockedDecrement((LONG *)(param_1 + 0x1c));
  }
  return uVar2;
}



/* c05a6508 FUN_c05a6508 */

/* Boundary evidence: original MIPS .pdata c05a6508..c05a6aaf. Semantic name remains unreviewed. */

DWORD FUN_c05a6508(uint param_1,undefined4 *param_2,uint *param_3)

{
  longlong lVar1;
  DWORD DVar2;
  size_t sVar3;
  wchar_t *_Dest;
  SIZE_T *_Src;
  HLOCAL pvVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  SIZE_T _Size;
  uint *puVar9;
  uint _Size_00;
  uint *puVar10;
  int local_38;
  uint *local_34;
  uint local_30;
  
  param_2[0x16] = 1;
  uVar7 = 0;
  local_38 = 0;
  local_34 = param_3;
  local_30 = param_1;
  if (DAT_c05b6320 == 0) {
    DVar2 = 7;
    puVar6 = param_3;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
    DVar2 = FUN_c05af55c(DAT_c05b6338,(wchar_t *)*param_2,&local_38);
    puVar6 = local_34;
    if ((DVar2 == 0) && (puVar6 = *(uint **)(local_38 + 0x18), puVar6 != (uint *)0x0)) {
      InterlockedIncrement((LONG *)(puVar6 + 7));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  }
  if (DVar2 == 0) {
    if (puVar6 != (uint *)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(puVar6 + 2));
    }
    if (((param_1 & 0x10000) != 0) && ((wchar_t *)puVar6[0x12] != (wchar_t *)0x0)) {
      sVar3 = wcslen((wchar_t *)puVar6[0x12]);
      _Dest = FUN_c05a4228((sVar3 + 1) * 2);
      param_2[1] = _Dest;
      if (_Dest == (wchar_t *)0x0) {
        DVar2 = GetLastError();
      }
      else {
        wcscpy(_Dest,(wchar_t *)puVar6[0x12]);
        uVar7 = 0x10000;
      }
    }
    uVar8 = uVar7;
    if ((param_1 & 0x20000) != 0) {
      uVar8 = uVar7 | 0x20000;
      param_2[2] = puVar6[0x15];
      param_2[3] = puVar6[0x16];
      param_2[4] = puVar6[0x17];
    }
    uVar7 = param_1 & 0xffff;
    if (uVar7 != 0) {
      param_2[8] = puVar6[8] & uVar7;
      uVar8 = uVar7 | uVar8;
    }
    if ((((param_1 & 0x80000000) != 0) && (puVar6 != (uint *)0x0)) &&
       ((LPCRITICAL_SECTION)puVar6[0x1c] != (LPCRITICAL_SECTION)0x0)) {
      _Src = (SIZE_T *)FUN_c05b24bc((LPCRITICAL_SECTION)puVar6[0x1c]);
      if (_Src != (SIZE_T *)0x0) {
        param_2[0x19] = 0;
        uVar8 = uVar8 | 0x80000000;
        pvVar4 = FUN_c05a4228(*_Src);
        param_2[0x1a] = pvVar4;
        if (pvVar4 != (HLOCAL)0x0) {
          param_2[0x19] = *_Src;
          memcpy(pvVar4,_Src,*_Src);
        }
        FUN_c05b1a58(puVar6[0x1c],_Src);
      }
      uVar5 = FUN_c05b1a2c(puVar6[0x1c]);
      param_2[0x1b] = uVar5;
    }
    if ((param_1 & 0x40000) != 0) {
      param_2[0x10] = 0;
      param_2[0x11] = 0;
      if ((uint *)puVar6[0x4f] == (uint *)0x0) {
        uVar8 = uVar8 | 0x40000;
      }
      else {
        lVar1 = (ulonglong)*(uint *)puVar6[0x4f] * 0xc4;
        if (((int)((ulonglong)lVar1 >> 0x20) == 0) && (uVar7 = (int)lVar1 + 8, 7 < uVar7)) {
          pvVar4 = FUN_c05a4228(uVar7);
          param_2[0x11] = pvVar4;
          if (pvVar4 == (HLOCAL)0x0) {
            if (DVar2 == 0) {
              DVar2 = GetLastError();
            }
          }
          else {
            param_2[0x10] = uVar7;
            memcpy(pvVar4,(void *)puVar6[0x4f],uVar7);
            uVar8 = uVar8 | 0x40000;
            puVar10 = (uint *)param_2[0x11];
            uVar7 = 0;
            param_3 = local_34;
            if (*puVar10 != 0) {
              puVar9 = puVar10 + 0x1e;
              do {
                if (*puVar9 != 0) {
                  memcpy(puVar9 + 1,&DAT_c05b6188,0x20);
                }
                uVar7 = uVar7 + 1;
                puVar9 = puVar9 + 0x31;
                param_1 = local_30;
                param_3 = local_34;
              } while (uVar7 < *puVar10);
            }
          }
        }
        else {
          DVar2 = 0xa0;
        }
      }
    }
    uVar7 = uVar8;
    if ((param_1 & 0x80000) != 0) {
      param_2[9] = puVar6[0x19];
      param_2[0x17] = 0;
      param_2[0x18] = 0;
      uVar7 = uVar8 | 0x80000;
      if (puVar6[0x1a] != 0) {
        lVar1 = (ulonglong)*(uint *)(puVar6[0x1a] + 4) * 8;
        if (((int)((ulonglong)lVar1 >> 0x20) == 0) && (_Size_00 = (int)lVar1 + 8, 7 < _Size_00)) {
          pvVar4 = FUN_c05a4228(_Size_00);
          param_2[0x18] = pvVar4;
          if (pvVar4 == (HLOCAL)0x0) {
            if (DVar2 == 0) {
              DVar2 = GetLastError();
            }
          }
          else {
            param_2[0x17] = _Size_00;
            memcpy(pvVar4,(void *)puVar6[0x1a],_Size_00);
          }
        }
        else {
          param_2[9] = 0;
          DVar2 = 0xa0;
          uVar7 = uVar8;
        }
      }
    }
    if ((code *)puVar6[9] != FUN_c05b0060) {
      if ((param_1 & 0x200000) != 0) {
        uVar7 = uVar7 | 0x200000;
        param_2[5] = puVar6[0x35];
      }
      if ((param_1 & 0x400000) != 0) {
        uVar7 = uVar7 | 0x400000;
        param_2[6] = puVar6[0x42];
      }
      if ((param_1 & 0x800000) != 0) {
        uVar7 = uVar7 | 0x800000;
        param_2[7] = puVar6[0x2a];
      }
      if ((param_1 & 0x2000000) != 0) {
        param_2[0xc] = 0;
        pvVar4 = FUN_c05a4228(6);
        param_2[0xd] = pvVar4;
        if (pvVar4 == (HLOCAL)0x0) {
          if (DVar2 == 0) {
            DVar2 = GetLastError();
          }
        }
        else {
          param_2[0xc] = 6;
          memcpy(pvVar4,puVar6 + 0x1f,6);
          uVar7 = uVar7 | 0x2000000;
        }
      }
      if ((param_1 & 0x1000000) != 0) {
        param_2[10] = 0;
        param_2[0xb] = 0;
        if (puVar6[0x21] != 0) {
          pvVar4 = FUN_c05a4228(puVar6[0x21]);
          param_2[0xb] = pvVar4;
          if (pvVar4 == (HLOCAL)0x0) {
            if (DVar2 == 0) {
              DVar2 = GetLastError();
            }
          }
          else {
            param_2[10] = puVar6[0x21];
            memcpy(pvVar4,puVar6 + 0x22,puVar6[0x21]);
            uVar7 = uVar7 | 0x1000000;
          }
        }
      }
      if ((param_1 & 0x4000000) != 0) {
        FUN_c05aeec4((int)puVar6,0x4000000,(uint *)0x0);
        param_2[0xe] = 0;
        param_2[0xf] = 0;
        if ((int *)puVar6[0x4e] != (int *)0x0) {
          _Size = *(int *)puVar6[0x4e] * 0xc4 + 8;
          pvVar4 = FUN_c05a4228(_Size);
          param_2[0xf] = pvVar4;
          if (pvVar4 == (HLOCAL)0x0) {
            if (DVar2 == 0) {
              DVar2 = GetLastError();
            }
          }
          else {
            param_2[0xe] = _Size;
            memcpy(pvVar4,(void *)puVar6[0x4e],_Size);
            uVar7 = uVar7 | 0x4000000;
          }
        }
      }
    }
    FUN_c05a63ec(puVar6);
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar7;
  }
  return DVar2;
}



/* c05a6ab0 FUN_c05a6ab0 */

/* Boundary evidence: original MIPS .pdata c05a6ab0..c05a6c5f. Semantic name remains unreviewed. */

DWORD FUN_c05a6ab0(uint param_1,int param_2)

{
  HLOCAL pvVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  uint local_20 [2];
  
  local_20[0] = 0x8000000;
  DVar3 = 0;
  if ((param_1 & 0x4ffff) != 0) {
    if (*(int *)(param_2 + 0x34) == 0) {
      DVar3 = FUN_c05b3890((HKEY)0x0,param_2);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
      puVar2 = DAT_c05b633c;
      if ((undefined4 **)DAT_c05b633c != &DAT_c05b633c) {
        do {
          if (puVar2 != (undefined4 *)0x0) {
            InterlockedIncrement(puVar2 + 7);
            EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 2));
          }
          FUN_c05b3890((HKEY)0x0,(int)puVar2);
          puVar2[8] = puVar2[8] | 0x100000;
          DVar3 = FUN_c05b0b54(5,(int)puVar2,local_20);
          puVar2[8] = puVar2[8] & 0xffdfffff;
          FUN_c05a63ec(puVar2);
          puVar2 = (undefined4 *)*puVar2;
        } while ((undefined4 **)puVar2 != &DAT_c05b633c);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
    }
    else {
      if (DAT_c05b6368 != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6384);
        pvVar1 = DAT_c05b6380;
        if (DAT_c05b6380 != (HLOCAL)0x0) {
          InterlockedIncrement((LONG *)((int)DAT_c05b6380 + 0x1c));
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6384);
        if (pvVar1 != (HLOCAL)0x0) {
          EnterCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 8));
        }
        FUN_c05a63ec(pvVar1);
      }
      FUN_c05b3890((HKEY)0x0,param_2);
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100000;
      DVar3 = FUN_c05b0b54(5,param_2,local_20);
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xffdfffff;
    }
  }
  return DVar3;
}



/* c05a6c60 FUN_c05a6c60 */

/* Boundary evidence: original MIPS .pdata c05a6c60..c05a6f6b. Semantic name remains unreviewed. */

DWORD FUN_c05a6c60(uint param_1,wchar_t *param_2,uint *param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  wchar_t *_Dest;
  uint *puVar3;
  uint uVar4;
  uint local_448 [2];
  uint *local_440;
  wchar_t *local_43c;
  int local_438;
  DWORD local_434;
  wchar_t awStack_430 [6];
  int local_424;
  SIZE_T local_420;
  uint local_30;
  
  local_30 = DAT_c05b62e4;
  local_438 = 0;
  uVar4 = 0;
  local_448[0] = 0;
  local_440 = param_3;
  if (DAT_c05b6320 == 0) {
    DVar1 = 7;
    puVar3 = param_3;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
    DVar1 = FUN_c05af55c(DAT_c05b6338,param_2,&local_438);
    puVar3 = local_440;
    local_434 = DVar1;
    if ((DVar1 == 0) && (puVar3 = *(uint **)(local_438 + 0x18), puVar3 != (uint *)0x0)) {
      InterlockedIncrement((LONG *)(puVar3 + 7));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  }
  if (DVar1 == 0) {
    if (puVar3 != (uint *)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(puVar3 + 2));
    }
    if ((param_1 & 0x10000) != 0) {
      local_440 = (uint *)0x400;
      local_43c = awStack_430;
      DVar2 = FUN_c05af008((HANDLE)0xffffffff,(wchar_t *)puVar3[0xd],(size_t *)&local_440);
      FUN_c05a42b0((HLOCAL)puVar3[0x12]);
      puVar3[0x12] = 0;
      if (DVar2 == 0) {
        if (local_420 != 0) {
          _Dest = FUN_c05a4228(local_420);
          puVar3[0x12] = (uint)_Dest;
          if (puVar3[0xd] == 0) {
            DVar1 = GetLastError();
          }
          else {
            wcscpy(_Dest,(wchar_t *)((int)awStack_430 + local_424));
          }
        }
        uVar4 = 0x10000;
      }
      if (DVar1 == 0) {
        DVar1 = DVar2;
      }
    }
    if ((param_1 & 0x20000) != 0) {
      DVar2 = FUN_c05aeef8((int)puVar3);
      if (DVar2 == 0) {
        uVar4 = uVar4 | 0x20000;
      }
      if (DVar1 == 0) {
        DVar1 = DVar2;
      }
    }
    if (param_1 == 0x8000000) {
      FUN_c05aeec4((int)puVar3,0x8000000,(uint *)0x0);
    }
    else if ((param_1 & 0x7ff00000) != 0) {
      local_448[0] = param_1;
      DVar2 = FUN_c05b0b54(5,(int)puVar3,local_448);
      puVar3[8] = puVar3[8] & 0xffdfffff;
      if (DVar2 == 0) {
        uVar4 = local_448[0] | uVar4;
      }
      if (DVar1 == 0) {
        DVar1 = DVar2;
      }
    }
    FUN_c05a63ec(puVar3);
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar4;
  }
  FUN_c05b4904(local_30);
  return DVar1;
}



/* c05a6f6c FUN_c05a6f6c */

/* Boundary evidence: original MIPS .pdata c05a6f6c..c05a6f77. Semantic name remains unreviewed. */

undefined4 FUN_c05a6f6c(void)

{
  return 1;
}



/* c05a6f78 FUN_c05a6f78 */

/* Boundary evidence: original MIPS .pdata c05a6f78..c05a718b. Semantic name remains unreviewed. */

DWORD FUN_c05a6f78(int *param_1,int param_2,wchar_t *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 *local_438 [2];
  size_t local_430;
  undefined4 *local_42c;
  undefined4 auStack_428 [256];
  uint local_28;
  
  local_28 = DAT_c05b62e4;
  puVar1 = (undefined4 *)*param_1;
  DVar2 = 0;
  iVar3 = 3;
  local_438[0] = puVar1;
  if (((param_2 == 1) || (param_2 == 3)) && (puVar1 == (undefined4 *)0x0)) {
    local_42c = auStack_428;
    local_430 = 0x400;
    DVar2 = FUN_c05af008((HANDLE)0xffffffff,param_3,&local_430);
    if (DVar2 != 0) goto LAB_c05a7158;
    DVar2 = FUN_c05a4d4c(auStack_428,local_438);
    puVar1 = local_438[0];
    if (DVar2 == 0) {
      if (local_438[0] != (undefined4 *)0x0) {
        InterlockedIncrement(local_438[0] + 7);
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 2));
      }
      DVar2 = FUN_c05a50a8(puVar1);
      if ((DVar2 != 0) || (DVar2 = FUN_c05b0b54(0,(int)puVar1,(uint *)0x0), DVar2 != 0)) {
        FUN_c05a6444((int)puVar1,1);
      }
      FUN_c05a63ec(puVar1);
      if (DVar2 == 0) goto LAB_c05a7088;
    }
    puVar1 = (undefined4 *)0x0;
  }
LAB_c05a7088:
  if (((param_2 == 2) || (param_2 == 4)) && (puVar1 != (undefined4 *)0x0)) {
    InterlockedIncrement(puVar1 + 7);
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 2));
    DVar2 = FUN_c05b3890((HKEY)0x0,(int)puVar1);
    FUN_c05a6444((int)puVar1,1);
    FUN_c05a63ec(puVar1);
    puVar1 = (undefined4 *)0x0;
  }
  if (param_2 == 5) {
LAB_c05a7114:
    iVar3 = 2;
  }
  else {
    if (param_2 != 6) {
      if (param_2 == 9) goto LAB_c05a7114;
      if (param_2 != 10) goto LAB_c05a7158;
    }
    if (param_2 == 9) goto LAB_c05a7114;
  }
  if (puVar1 == (undefined4 *)0x0) {
    DVar2 = 2;
  }
  else {
    InterlockedIncrement(puVar1 + 7);
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 2));
    DVar2 = FUN_c05b0b54(iVar3,(int)puVar1,(uint *)0x0);
    FUN_c05a63ec(puVar1);
  }
LAB_c05a7158:
  *param_1 = (int)puVar1;
  FUN_c05b4904(local_28);
  return DVar2;
}



/* c05a718c FUN_c05a718c */

/* Boundary evidence: original MIPS .pdata c05a718c..c05a74df. Semantic name remains unreviewed. */

DWORD FUN_c05a718c(int param_1,int param_2,wchar_t *param_3,uint *param_4)

{
  bool bVar1;
  DWORD DVar2;
  HLOCAL pvVar3;
  uint uVar4;
  uint *puVar5;
  DWORD *pDVar6;
  HLOCAL pvVar7;
  int iVar8;
  HLOCAL *ppvVar9;
  int local_28;
  HLOCAL local_24;
  
  local_28 = 0;
  iVar8 = 7;
  if (DAT_c05b6320 == 0) {
    DVar2 = 7;
    pvVar7 = local_24;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
    DVar2 = FUN_c05af55c(DAT_c05b6338,param_3,&local_28);
    pvVar7 = local_24;
    if ((DVar2 == 0) && (pvVar7 = *(HLOCAL *)(local_28 + 0x18), pvVar7 != (HLOCAL)0x0)) {
      InterlockedIncrement((LONG *)((int)pvVar7 + 0x1c));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  }
  if (DVar2 != 0) {
    return DVar2;
  }
  if (pvVar7 != (HLOCAL)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)pvVar7 + 8));
  }
  if ((param_2 != 0) && (param_1 != *(int *)((int)pvVar7 + 0x14c))) {
    DVar2 = 6;
    goto LAB_c05a74ac;
  }
  bVar1 = false;
  local_24 = (HLOCAL)0x0;
  ppvVar9 = (HLOCAL *)0x0;
  switch(param_2) {
  case 0:
    iVar8 = 6;
    goto LAB_c05a7484;
  case 1:
    iVar8 = 5;
    ppvVar9 = &local_24;
    local_24 = (HLOCAL)0x8000000;
    break;
  case 2:
    break;
  case 3:
    iVar8 = 8;
    break;
  case 4:
    iVar8 = 9;
    break;
  default:
    iVar8 = 0;
    bVar1 = true;
    break;
  case 6:
    DVar2 = 0;
    if (param_4 != (uint *)0x0) {
      if (*(DATA_BLOB **)((int)pvVar7 + 0x148) == (DATA_BLOB *)0x0) {
        *param_4 = 0;
      }
      else if (*param_4 < 0x44) {
        *param_4 = 0x44;
        DVar2 = 0xea;
      }
      else {
        DVar2 = FUN_c05a4aa8(*(DATA_BLOB **)((int)pvVar7 + 0x148),(size_t *)param_4[1]);
      }
      goto LAB_c05a74ac;
    }
    goto LAB_c05a72e4;
  case 7:
    DVar2 = 0;
    if (param_4 == (uint *)0x0) {
      FUN_c05a48f8(*(undefined4 **)((int)pvVar7 + 0x148));
      *(undefined4 *)((int)pvVar7 + 0x148) = 0;
      goto LAB_c05a74ac;
    }
    if (*param_4 == 0x44) {
      if (*(int *)((int)pvVar7 + 0x148) == 0) {
        pvVar3 = FUN_c05a4228(0x10);
        *(HLOCAL *)((int)pvVar7 + 0x148) = pvVar3;
        if ((pvVar3 == (HLOCAL)0x0) && (DVar2 = GetLastError(), DVar2 != 0)) goto LAB_c05a74ac;
      }
      pDVar6 = (DWORD *)param_4[1];
      FUN_c05a48a0(*(undefined4 **)((int)pvVar7 + 0x148));
      DVar2 = FUN_c05a4930(*(DWORD **)((int)pvVar7 + 0x148),pDVar6);
      goto LAB_c05a74ac;
    }
LAB_c05a72e4:
    DVar2 = 0x57;
    goto LAB_c05a74ac;
  }
  puVar5 = *(uint **)((int)pvVar7 + 0x140);
  if ((puVar5 != (uint *)0x0) && (puVar5[1] < *puVar5)) {
    uVar4 = puVar5[1];
    if ((param_4 == (uint *)0x0) || (puVar5[uVar4 * 0x31 + 0x28] < *param_4)) {
      FUN_c05a42b0((HLOCAL)puVar5[uVar4 * 0x31 + 0x29]);
      puVar5[uVar4 * 0x31 + 0x29] = 0;
      puVar5[uVar4 * 0x31 + 0x28] = 0;
    }
    if (param_4 != (uint *)0x0) {
      if (puVar5[uVar4 * 0x31 + 0x28] < *param_4) {
        pvVar3 = FUN_c05a4228(*param_4);
        puVar5[uVar4 * 0x31 + 0x29] = (uint)pvVar3;
        if (pvVar3 == (HLOCAL)0x0) {
          DVar2 = GetLastError();
          return DVar2;
        }
        puVar5[uVar4 * 0x31 + 0x28] = *param_4;
      }
      if (*param_4 != 0) {
        memcpy((void *)puVar5[uVar4 * 0x31 + 0x29],(void *)param_4[1],*param_4);
      }
    }
  }
  DVar2 = 0;
  if (!bVar1) {
LAB_c05a7484:
    DVar2 = FUN_c05b0b54(iVar8,(int)pvVar7,(uint *)ppvVar9);
    *(uint *)((int)pvVar7 + 0x20) = *(uint *)((int)pvVar7 + 0x20) & 0xffdfffff;
  }
LAB_c05a74ac:
  FUN_c05a63ec(pvVar7);
  return DVar2;
}



/* c05a74e0 FUN_c05a74e0 */

/* Boundary evidence: original MIPS .pdata c05a74e0..c05a76b3. Semantic name remains unreviewed. */

DWORD FUN_c05a74e0(void)

{
  undefined4 *puVar1;
  size_t sVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  HANDLE local_30;
  undefined4 *local_2c;
  size_t local_28;
  undefined4 *local_24;
  
  local_30 = (HANDLE)0xffffffff;
  local_28 = 0;
  uVar5 = 0x400;
  local_24 = (undefined4 *)0x0;
  DVar3 = FUN_c05aab38(&local_30);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  iVar6 = 0;
  if (DVar3 != 0) {
LAB_c05a7660:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
    if (local_30 != (HANDLE)0xffffffff) {
      CloseHandle(local_30);
    }
    FUN_c05a42b0(local_24);
    return DVar3;
  }
  do {
    local_2c = (undefined4 *)0x0;
    sVar2 = local_28;
    if (local_28 < uVar5) {
      FUN_c05a42b0(local_24);
      local_24 = FUN_c05a4228(uVar5);
      sVar2 = uVar5;
      if (local_24 == (undefined4 *)0x0) {
        DVar3 = 8;
        goto LAB_c05a7660;
      }
    }
    local_28 = sVar2;
    puVar1 = local_24;
    DVar3 = FUN_c05aac48(local_30,iVar6,&local_28);
    if (DVar3 == 0x7a) {
      if (uVar5 < 0x10000) {
        uVar5 = uVar5 + 0x400;
        iVar6 = iVar6 + -1;
      }
    }
    else {
      if (DVar3 == 0x103) {
        DVar3 = 0;
        goto LAB_c05a7660;
      }
      if (DVar3 != 0) goto LAB_c05a7660;
      DVar3 = FUN_c05a4d4c(puVar1,&local_2c);
      puVar1 = local_2c;
      if (DVar3 != 0) goto LAB_c05a764c;
      if (local_2c != (undefined4 *)0x0) {
        InterlockedIncrement(local_2c + 7);
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 2));
      }
      iVar4 = FUN_c05a50a8(puVar1);
      if (iVar4 == 0) {
        DVar3 = FUN_c05b0b54(0,(int)puVar1,(uint *)0x0);
        puVar1[8] = puVar1[8] & 0xffdfffff;
        if ((DVar3 != 0) || (puVar1[0x17] == 9)) goto LAB_c05a7638;
      }
      else {
LAB_c05a7638:
        FUN_c05a6444((int)puVar1,1);
      }
      FUN_c05a63ec(puVar1);
    }
LAB_c05a764c:
    iVar6 = iVar6 + 1;
  } while( true );
}



/* c05a76b4 FUN_c05a76b4 */

/* Boundary evidence: original MIPS .pdata c05a76b4..c05a7c63. Semantic name remains unreviewed. */

DWORD FUN_c05a76b4(uint param_1,int *param_2,uint *param_3)

{
  uint *_Dst;
  DWORD DVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  byte *pbVar7;
  int iVar8;
  HLOCAL pvVar9;
  DWORD DVar10;
  int *piVar11;
  uint uVar12;
  size_t _Size;
  uint *_Buf1;
  size_t _Size_00;
  uint local_70;
  uint local_68;
  uint local_64;
  int local_60;
  int *local_5c;
  uint local_58;
  uint *local_54;
  byte local_50 [32];
  uint local_30;
  
  local_30 = DAT_c05b62e4;
  uVar12 = 0;
  DVar10 = 0;
  local_68 = 0;
  local_60 = 0;
  local_70 = 0;
  local_5c = param_2;
  local_58 = param_1;
  local_54 = param_3;
  if (*param_2 == 0) {
    if (DAT_c05b6368 == 0) {
      DVar10 = 7;
      goto LAB_c05a7c20;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6384);
    pvVar9 = DAT_c05b6380;
    if (DAT_c05b6380 != (HLOCAL)0x0) {
      InterlockedIncrement((LONG *)((int)DAT_c05b6380 + 0x1c));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6384);
  }
  else {
    if (DAT_c05b6320 == 0) {
      pvVar9 = (HLOCAL)0x0;
      DVar10 = 7;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
      DVar10 = FUN_c05af55c(DAT_c05b6338,(wchar_t *)*param_2,&local_60);
      if (DVar10 == 0) {
        pvVar9 = *(HLOCAL *)(local_60 + 0x18);
        if (pvVar9 != (HLOCAL)0x0) {
          InterlockedIncrement((LONG *)((int)pvVar9 + 0x1c));
        }
      }
      else {
        pvVar9 = (HLOCAL)0x0;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
    }
    if (DVar10 != 0) goto LAB_c05a7c20;
  }
  if (pvVar9 != (HLOCAL)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)pvVar9 + 8));
  }
  uVar12 = param_1 & 0xffff;
  if (uVar12 != 0) {
    uVar4 = *(uint *)((int)pvVar9 + 0x20);
    *(uint *)((int)pvVar9 + 0x20) = ~uVar12 & uVar4;
    uVar5 = param_2[8] & uVar12 | ~uVar12 & uVar4;
    *(uint *)((int)pvVar9 + 0x20) = uVar5 | uVar4 & 0x2000;
    local_70 = uVar12;
    if (((uVar5 & 0x8000) != 0) || ((uVar4 & 0x8000) != 0)) {
      *(undefined4 *)((int)pvVar9 + 0x164) = 0;
    }
  }
  if ((param_1 & 0x80000000) != 0) {
    FUN_c05b1a34(*(int *)((int)pvVar9 + 0x70),param_2[0x1b]);
    FUN_c05ad248(*(LPCRITICAL_SECTION *)((int)pvVar9 + 0x70),(uint)((param_2[0x1b] & 4U) != 0));
    if (((param_2[0x1b] & 0x80000000U) != 0) &&
       (*(LPCRITICAL_SECTION *)((int)pvVar9 + 0x70) != (LPCRITICAL_SECTION)0x0)) {
      FUN_c05b2484(*(LPCRITICAL_SECTION *)((int)pvVar9 + 0x70));
    }
  }
  if ((param_1 & 0x40000) == 0) {
LAB_c05a7ba8:
    if ((param_1 & 0xfffb0000) != 0) {
      if ((*(uint *)((int)pvVar9 + 0x20) & 0x8000) == 0) {
        DVar10 = 0x10e0;
      }
      else {
        DVar10 = FUN_c05aee90((int)pvVar9,(int)param_2,param_1,&local_68);
        local_70 = local_68 | local_70;
      }
    }
    *(undefined4 *)((int)pvVar9 + 0x158) = 1;
    FUN_c05a4684(*(uint **)((int)pvVar9 + 0x144));
    *(undefined4 *)((int)pvVar9 + 0x144) = 0;
    DVar1 = FUN_c05a6ab0(local_70,(int)pvVar9);
    if (DVar10 == 0) {
      DVar10 = DVar1;
    }
  }
  else {
    _Dst = FUN_c05a4228(param_2[0x10]);
    if (param_2[0x10] == 0) {
      if (_Dst != (uint *)0x0) goto LAB_c05a7900;
LAB_c05a7b7c:
      FUN_c05a5314(*(uint **)((int)pvVar9 + 0x13c),_Dst);
      FUN_c05a42b0(*(HLOCAL *)((int)pvVar9 + 0x13c));
      *(uint **)((int)pvVar9 + 0x13c) = _Dst;
      local_70 = local_70 | 0x40000;
      DVar10 = local_68;
    }
    else {
      if (_Dst != (uint *)0x0) {
LAB_c05a7900:
        memcpy(_Dst,(void *)param_2[0x11],param_2[0x10]);
        uVar12 = 0;
        if (*_Dst != 0) {
          puVar6 = _Dst + 0x28;
          do {
            if (puVar6[-0x19] < 4) {
              if (2 < puVar6[-1]) goto LAB_c05a7938;
            }
            else if (puVar6[-1] < 3) {
LAB_c05a7938:
              DVar10 = 0x57;
              goto LAB_c05a7ba0;
            }
            if (*puVar6 == 0) {
              puVar6[1] = 0;
            }
            uVar12 = uVar12 + 1;
            puVar6 = puVar6 + 0x31;
          } while (uVar12 < *_Dst);
        }
        if ((*(int *)((int)pvVar9 + 0x13c) != 0) && (local_64 = 0, *_Dst != 0)) {
          puVar6 = _Dst + 2;
          do {
            if ((puVar6[1] & 2) == 0) {
              memcpy(local_50,&DAT_c05b6188,0x20);
            }
            else {
              uVar12 = 0;
              do {
                bVar3 = (&DAT_c05b6188)[uVar12];
                if (0x39 < bVar3) {
                  if (bVar3 < 0x47) {
                    cVar2 = bVar3 - 0x37;
                  }
                  else {
                    cVar2 = bVar3 + 0xa9;
                  }
                }
                else {
                  cVar2 = bVar3 - 0x30;
                }
                pbVar7 = local_50 + uVar12;
                *pbVar7 = cVar2 << 4;
                if (0x39 < bVar3) {
                  if (bVar3 < 0x47) {
                    bVar3 = bVar3 - 0x37;
                  }
                  else {
                    bVar3 = bVar3 + 0xa9;
                  }
                }
                else {
                  bVar3 = bVar3 - 0x30;
                }
                uVar12 = uVar12 + 1;
                *pbVar7 = cVar2 << 4 | bVar3;
              } while (uVar12 < 0x20);
            }
            iVar8 = 0;
            uVar12 = 0;
            do {
              uVar4 = uVar12 % 0xd;
              uVar12 = uVar12 + 7;
              local_50[iVar8] = (&DAT_c05b6178)[uVar4] ^ local_50[iVar8];
              iVar8 = iVar8 + 1;
            } while (uVar12 < 0xe0);
            _Size_00 = puVar6[0x1c];
            if (_Size_00 != 0) {
              uVar12 = 0;
              if (**(int **)((int)pvVar9 + 0x13c) != 0) {
                _Size = puVar6[4];
                piVar11 = *(int **)((int)pvVar9 + 0x13c) + 2;
                do {
                  if ((_Size == piVar11[4]) &&
                     (iVar8 = memcmp(piVar11 + 5,puVar6 + 5,_Size), iVar8 == 0)) {
                    _Buf1 = puVar6 + 0x1d;
                    iVar8 = memcmp(_Buf1,&DAT_c05b6188,0x20);
                    if ((iVar8 == 0) || (iVar8 = memcmp(_Buf1,local_50,_Size_00), iVar8 == 0)) {
                      memcpy(_Buf1,piVar11 + 0x1d,piVar11[0x1c]);
                    }
                    break;
                  }
                  uVar12 = uVar12 + 1;
                  piVar11 = piVar11 + 0x31;
                } while (uVar12 < **(uint **)((int)pvVar9 + 0x13c));
              }
            }
            local_64 = local_64 + 1;
            puVar6 = puVar6 + 0x31;
            param_1 = local_58;
            param_2 = local_5c;
            param_3 = local_54;
          } while (local_64 < *_Dst);
        }
        goto LAB_c05a7b7c;
      }
      DVar10 = GetLastError();
    }
LAB_c05a7ba0:
    if (DVar10 == 0) goto LAB_c05a7ba8;
  }
  FUN_c05a63ec(pvVar9);
  uVar12 = local_70;
LAB_c05a7c20:
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar12;
  }
  FUN_c05b4904(local_30);
  return DVar10;
}



/* c05a7c64 FUN_c05a7c64 */

/* Boundary evidence: original MIPS .pdata c05a7c64..c05a7d13. Semantic name remains unreviewed. */

char * FUN_c05a7c64(undefined4 param_1)

{
  char *pcVar1;
  
  switch(param_1) {
  case 3:
    pcVar1 = "WZCNOTIF_ADAPTER_BIND";
    break;
  case 4:
    pcVar1 = "WZCNOTIF_ADAPTER_UNBIND";
    break;
  case 5:
    pcVar1 = "WZCNOTIF_MEDIA_CONNECT";
    break;
  case 6:
    pcVar1 = "WZCNOTIF_MEDIA_DISCONNECT";
    break;
  case 7:
    pcVar1 = "WZCNOTIF_WZC_CONNECT";
    break;
  case 8:
    pcVar1 = "WZCNOTIF_MEDIA_SPECIFIC";
    break;
  case 9:
    pcVar1 = "WZCNOTIF_MEDIA_PORTUP";
    break;
  case 10:
    pcVar1 = "WZCNOTIF_MEDIA_PORTDOWN";
    break;
  default:
    pcVar1 = "???";
  }
  return pcVar1;
}



/* c05a7d14 FUN_c05a7d14 */

/* Boundary evidence: original MIPS .pdata c05a7d14..c05a7dc7. Semantic name remains unreviewed. */

void FUN_c05a7d14(int param_1,size_t *param_2)

{
  uint uVar1;
  int iVar2;
  size_t local_18;
  size_t *local_14;
  
  iVar2 = *(int *)(param_1 + 0x140);
  if (((*(int *)(param_1 + 0x70) == 0) ||
      (uVar1 = FUN_c05b1a2c(*(int *)(param_1 + 0x70)), (uVar1 & 1) == 0)) || (iVar2 == 0)) {
    param_2 = &DAT_c05b61b8;
  }
  else if (*(int *)(*(int *)(iVar2 + 4) * 0xc4 + iVar2 + 0x9c) == 7) {
    param_2 = &DAT_c05b61b8;
  }
  local_18 = *param_2;
  local_14 = param_2;
  FUN_c05ab3c8(*(HANDLE *)(param_1 + 0x60),0xd010123,&local_18);
  return;
}



/* c05a7dc8 FUN_c05a7dc8 */

/* Boundary evidence: original MIPS .pdata c05a7dc8..c05a7e37. Semantic name remains unreviewed. */

undefined4 FUN_c05a7dc8(int param_1)

{
  size_t *psVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  psVar1 = (size_t *)FUN_c05b24bc(*(LPCRITICAL_SECTION *)(param_1 + 0x70));
  if (psVar1 == (size_t *)0x0) {
    uVar2 = 0xe;
  }
  else {
    FUN_c05a7d14(param_1,psVar1);
    FUN_c05b1a58(*(undefined4 *)(param_1 + 0x70),psVar1);
  }
  return uVar2;
}



/* c05a7e38 FUN_c05a7e38 */

/* Boundary evidence: original MIPS .pdata c05a7e38..c05a7ef3. Semantic name remains unreviewed. */

void FUN_c05a7e38(size_t *param_1,wchar_t *param_2)

{
  int iVar1;
  HLOCAL pvVar2;
  HLOCAL local_20 [2];
  
  local_20[0] = (HLOCAL)0x0;
  if (DAT_c05b6320 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
    iVar1 = FUN_c05af55c(DAT_c05b6338,param_2,(int *)local_20);
    pvVar2 = local_20[0];
    if (iVar1 == 0) {
      pvVar2 = *(HLOCAL *)((int)local_20[0] + 0x18);
      FUN_c05a4c10((int)pvVar2);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
    if (iVar1 == 0) {
      FUN_c05a4c38((int)pvVar2);
      FUN_c05a7d14((int)pvVar2,param_1);
      FUN_c05a63ec(pvVar2);
    }
  }
  return;
}



/* c05a7ef4 FUN_c05a7ef4 */

/* Boundary evidence: original MIPS .pdata c05a7ef4..c05a7f87. Semantic name remains unreviewed. */

void FUN_c05a7ef4(int param_1,int param_2,int param_3)

{
  int iVar1;
  HANDLE pvVar2;
  uint local_10 [2];
  
  if ((((7 < param_3 - 4U) && (pvVar2 = *(HANDLE *)(param_2 + 8), pvVar2 < (HANDLE)0x100000)) &&
      ((uint)((int)pvVar2 * 0xc) <= param_3 - 0xcU)) &&
     (((*(LPCRITICAL_SECTION *)(param_1 + 0x70) != (LPCRITICAL_SECTION)0x0 &&
       (iVar1 = FUN_c05ad218(*(LPCRITICAL_SECTION *)(param_1 + 0x70),pvVar2,(void *)(param_2 + 0xc),
                             local_10), iVar1 == 0)) && (local_10[0] != 0)))) {
    FUN_c05a7dc8(param_1);
  }
  return;
}



/* c05a7f88 FUN_c05a7f88 */

/* Boundary evidence: original MIPS .pdata c05a7f88..c05a833f. Semantic name remains unreviewed. */

void FUN_c05a7f88(HLOCAL param_1,int *param_2)

{
  char *pcVar1;
  size_t sVar2;
  wchar_t *_Dst;
  int iVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  int local_38;
  int local_34;
  wchar_t *local_30;
  
  local_38 = 0;
  local_34 = 0;
  pcVar6 = (code *)0x0;
  if ((DAT_c05b61e4 & 1) != 0) {
    pcVar1 = FUN_c05a7c64(*param_2);
    CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30001,"EVENT = %hs",pcVar1);
  }
  FUN_c05a42b0(param_1);
  sVar2 = wcslen((wchar_t *)(param_2 + 0x5b));
  iVar5 = *param_2;
  _Dst = FUN_c05a4228(sVar2 * 2 + 2);
  local_30 = _Dst;
  if (_Dst == (wchar_t *)0x0) {
    GetLastError();
    goto LAB_c05a82cc;
  }
  memcpy(_Dst,param_2 + 0x5b,sVar2 * 2);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  iVar3 = FUN_c05af55c(DAT_c05b6338,_Dst,&local_34);
  if (iVar3 == 0) {
    local_38 = *(int *)(local_34 + 0x18);
  }
  if (iVar5 != 8) {
    if (local_38 != 0) {
      pcVar6 = *(code **)(local_38 + 0x24);
    }
    FUN_c05a6f78(&local_38,*param_2,_Dst);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6324);
  iVar5 = *param_2;
  if (iVar5 == 5) {
LAB_c05a81ec:
    if ((local_38 != 0) && ((pcVar6 == FUN_c05af8d4 || (pcVar6 == FUN_c05afc1c)))) {
      if (*(int *)(local_38 + 0x160) == 0) {
        FUN_c05aeec4(local_38,0x2000000,(uint *)0x0);
        FUN_c05a8fbc(3,(void *)(local_38 + 0x88),*(uint *)(local_38 + 0x84),0,
                     *(undefined4 *)(local_38 + 0xd4),*(wchar_t **)(local_38 + 0x34),
                     (undefined4 *)(local_38 + 0x7c));
      }
      else {
        FUN_c05aeec4(local_38,0x2000000,(uint *)0x0);
        FUN_c05a8fbc(0xb,(void *)(local_38 + 0x88),*(uint *)(local_38 + 0x84),0,
                     *(undefined4 *)(local_38 + 0xd4),*(wchar_t **)(local_38 + 0x34),
                     (undefined4 *)(local_38 + 0x7c));
        FUN_c05ae71c(*(int *)(local_38 + 0x150));
      }
    }
  }
  else {
    if (iVar5 != 6) {
      if (iVar5 == 8) {
        if ((local_38 != 0) && (*(int *)(local_38 + 0x160) != 0)) {
          if (((uint)param_2[1] < 4) || (*(int *)param_2[2] != 2)) {
            FUN_c05ae548(*(int *)(local_38 + 0x150));
          }
          else {
            FUN_c05a7ef4(local_38,param_2[2],param_2[1]);
          }
        }
        goto LAB_c05a82cc;
      }
      if (iVar5 == 9) goto LAB_c05a81ec;
      if (iVar5 != 10) goto LAB_c05a82cc;
    }
    if ((local_38 != 0) && (*(int *)(local_38 + 0x160) != 0)) {
      FUN_c05ae56c(*(int *)(local_38 + 0x150));
    }
  }
LAB_c05a82cc:
  if (_Dst != (wchar_t *)0x0) {
    FUN_c05a42b0(_Dst);
  }
  piVar4 = (int *)param_2[2];
  if ((piVar4 != (int *)0x0) && (piVar4 != param_2 + 3)) {
    FUN_c05a42b0(piVar4);
  }
  FUN_c05a42b0(param_2);
  return;
}



/* c05a8340 FUN_c05a8340 */

/* Boundary evidence: original MIPS .pdata c05a8340..c05a834b. Semantic name remains unreviewed. */

undefined4 FUN_c05a8340(void)

{
  return 1;
}



/* c05a834c FUN_c05a834c */

/* Boundary evidence: original MIPS .pdata c05a834c..c05a85cf. Semantic name remains unreviewed. */

void FUN_c05a834c(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint local_98;
  uint local_94;
  undefined1 auStack_90 [56];
  undefined1 auStack_58 [16];
  undefined1 local_48 [32];
  uint local_28;
  
  local_28 = DAT_c05b62e4;
  if (param_2 != 0) {
    if (param_3 == 0) {
      FUN_c05aeec4(param_1,0x2000000,(uint *)0x0);
      if (((*(int *)(param_1 + 0x70) != 0) && (*(int *)(param_1 + 0x160) != 0)) &&
         (DAT_c05b64f0 != (code *)0x0)) {
        iVar5 = 0x20;
        local_98 = 0x20;
        iVar2 = (*DAT_c05b64f0)(*(undefined4 *)(*(int *)(param_1 + 0x150) + 0x220),local_48,
                                &local_98);
        if (iVar2 == 0) {
          iVar2 = FUN_c05b27e4(*(LPCRITICAL_SECTION *)(param_1 + 0x70),(int *)(param_1 + 0x7c),
                               local_48,local_98,&local_94);
          if ((iVar2 == 0) && (local_94 != 0)) {
            iVar4 = *(int *)(param_1 + 0x140);
            iVar2 = *(int *)(iVar4 + 4);
            FUN_c05a7dc8(param_1);
            bVar1 = FUN_c05b24d8(*(LPCRITICAL_SECTION *)(param_1 + 0x70),(int *)(param_1 + 0x7c),
                                 auStack_90);
            if ((CONCAT31(extraout_var,bVar1) != 0) &&
               ((DAT_c05b64e0 != (code *)0x0 && (*(int *)(iVar2 * 0xc4 + iVar4 + 0x9c) == 6)))) {
              (*DAT_c05b64e0)(*(undefined4 *)(*(int *)(param_1 + 0x150) + 0x220),auStack_58);
            }
          }
          puVar3 = local_48;
          do {
            *puVar3 = 0;
            iVar5 = iVar5 + -1;
            puVar3 = puVar3 + 1;
          } while (iVar5 != 0);
        }
      }
      if (param_2 == 2) {
        FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xffff0003,0);
        FUN_c05a8fbc(6,(void *)(param_1 + 0x88),*(uint *)(param_1 + 0x84),0,
                     *(undefined4 *)(param_1 + 0xd4),*(wchar_t **)(param_1 + 0x34),
                     (undefined4 *)(param_1 + 0x7c));
      }
    }
    else {
      if (((param_3 == 0x4c7) || (param_3 == 0x30a)) ||
         (*(int *)(*(int *)(param_1 + 0x150) + 0x230) =
               *(int *)(*(int *)(param_1 + 0x150) + 0x230) + 1,
         0xfffffffe < *(uint *)(*(int *)(param_1 + 0x150) + 0x230))) {
        FUN_c05a8fbc(8,(void *)(param_1 + 0x88),*(uint *)(param_1 + 0x84),param_3,
                     *(undefined4 *)(param_1 + 0xd4),*(wchar_t **)(param_1 + 0x34),(undefined4 *)0x0
                    );
        iVar2 = 3;
      }
      else {
        FUN_c05a8fbc(9,(void *)(param_1 + 0x88),*(uint *)(param_1 + 0x84),param_3,
                     *(undefined4 *)(param_1 + 0xd4),*(wchar_t **)(param_1 + 0x34),(undefined4 *)0x0
                    );
        iVar2 = 2;
      }
      FUN_c05a718c(*(int *)(param_1 + 0x14c),iVar2,*(wchar_t **)(param_1 + 0x34),(uint *)0x0);
    }
  }
  FUN_c05b4904(local_28);
  return;
}



/* c05a85d0 FUN_c05a85d0 */

/* Boundary evidence: original MIPS .pdata c05a85d0..c05a868f. Semantic name remains unreviewed. */

void FUN_c05a85d0(HLOCAL param_1,HLOCAL param_2)

{
  FUN_c05a42b0(param_1);
  FUN_c05a4c38((int)param_2);
  if ((((DAT_c05b6464 == 4) || (DAT_c05b6464 == 2)) && (*(int *)((int)param_2 + 0x2c) != -1)) &&
     ((*(uint *)((int)param_2 + 0x20) & 0x10000) != 0)) {
    *(uint *)((int)param_2 + 0x20) = *(uint *)((int)param_2 + 0x20) & 0xfffeffff;
    FUN_c05b0b54(4,(int)param_2,(uint *)0x0);
    *(uint *)((int)param_2 + 0x20) = *(uint *)((int)param_2 + 0x20) & 0xffdfffff;
  }
  FUN_c05a63ec(param_2);
  InterlockedDecrement((LONG *)&DAT_c05b6354);
  return;
}



/* c05a8690 FUN_c05a8690 */

/* Boundary evidence: original MIPS .pdata c05a8690..c05a8827. Semantic name remains unreviewed. */

DWORD FUN_c05a8690(uint *param_1)

{
  DWORD DVar1;
  int local_28;
  uint local_24;
  
  if (param_1[2] == 0) {
    memset(param_1 + 3,0,0x14);
    local_28 = 0;
    local_24 = 3;
    CxRegReadValues(0x80000002,L"Software\\Microsoft\\WZCSVC\\Parameters",L"DisableWPA",4,0,
                    &local_28,4,L"PowerMode",4,0,&local_24,4,0);
    *param_1 = (uint)(local_28 == 0);
    param_1[1] = 3;
    if (local_24 < 4) {
      param_1[1] = local_24;
    }
    param_1[3] = 3000;
    param_1[4] = 60000;
    param_1[5] = 2000;
    param_1[6] = 60000;
    param_1[7] = 5000;
    InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));
    param_1[2] = 1;
    DVar1 = FUN_c05a4d4c((undefined4 *)0x0,param_1 + 8);
  }
  else {
    DVar1 = 0x4df;
  }
  return DVar1;
}



/* c05a8828 FUN_c05a8828 */

/* Boundary evidence: original MIPS .pdata c05a8828..c05a8833. Semantic name remains unreviewed. */

undefined4 FUN_c05a8828(void)

{
  return 1;
}



/* c05a8834 FUN_c05a8834 */

undefined4 FUN_c05a8834(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = DAT_c05b636c;
  param_2[1] = DAT_c05b6370;
  param_2[2] = DAT_c05b6374;
  param_2[3] = DAT_c05b6378;
  param_2[4] = DAT_c05b637c;
  return 0;
}



/* c05a886c FUN_c05a886c */

/* Boundary evidence: original MIPS .pdata c05a886c..c05a89c3. Semantic name remains unreviewed. */

LSTATUS FUN_c05a886c(undefined4 param_1,int *param_2)

{
  LSTATUS LVar1;
  
  if (*param_2 == -1) {
    *param_2 = 3000;
  }
  if (param_2[1] == -1) {
    param_2[1] = 60000;
  }
  if (param_2[2] == -1) {
    param_2[2] = 2000;
  }
  if (param_2[3] == -1) {
    param_2[3] = 60000;
  }
  if (param_2[4] == -1) {
    param_2[4] = 5000;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6384);
  DAT_c05b636c = *param_2;
  DAT_c05b6370 = param_2[1];
  DAT_c05b6374 = param_2[2];
  DAT_c05b6378 = param_2[3];
  DAT_c05b637c = param_2[4];
  LVar1 = FUN_c05b2f80((HKEY)0x0,(BYTE *)&DAT_c05b636c);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6384);
  return LVar1;
}



/* c05a89c4 FUN_c05a89c4 */

/* Boundary evidence: original MIPS .pdata c05a89c4..c05a89cf. Semantic name remains unreviewed. */

undefined4 FUN_c05a89c4(void)

{
  return 1;
}



/* c05a89d0 FUN_c05a89d0 */

/* Boundary evidence: original MIPS .pdata c05a89d0..c05a8aa7. Semantic name remains unreviewed. */

void FUN_c05a89d0(void)

{
  int iVar1;
  DWORD DVar2;
  
  DAT_c05b6460 = 0x20;
  DAT_c05b6464 = 4;
  DAT_c05b6468 = 0;
  DAT_c05b6474 = 1;
  DAT_c05b6478 = 4000;
  DAT_c05b646c = 0;
  DAT_c05b6470 = 0;
  iVar1 = FUN_c05af0b4((undefined4 *)&DAT_c05b6304);
  if ((((iVar1 == 0) && (iVar1 = FUN_c05a4c60(), iVar1 == 0)) &&
      (DVar2 = FUN_c05a8690(&DAT_c05b6360), DVar2 == 0)) &&
     (iVar1 = FUN_c05b2e80(0,(LPBYTE)&DAT_c05b636c), iVar1 == 0)) {
    FUN_c05b3478((HKEY)0x0,DAT_c05b6380);
    DVar2 = FUN_c05a4d08();
    if (DVar2 == 0) {
      FUN_c05a74e0();
      FUN_c05a8db4();
    }
  }
  InterlockedDecrement((LONG *)&DAT_c05b6354);
  return;
}



/* c05a8aa8 FUN_c05a8aa8 */

/* Boundary evidence: original MIPS .pdata c05a8aa8..c05a8c47. Semantic name remains unreviewed. */

void FUN_c05a8aa8(int *param_1)

{
  bool bVar1;
  size_t sVar2;
  undefined4 *puVar3;
  HLOCAL pvVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  
  sVar2 = wcslen((wchar_t *)(param_1 + 1));
  puVar3 = FUN_c05a4228(0x374);
  if (puVar3 == (undefined4 *)0x0) {
    GetLastError();
    return;
  }
  puVar3[2] = 0;
  puVar3[1] = 0;
  iVar7 = *param_1;
  if (iVar7 == 4) {
    uVar8 = 5;
LAB_c05a8bcc:
    *puVar3 = uVar8;
  }
  else if (iVar7 == 8) {
    *puVar3 = 6;
  }
  else {
    if (iVar7 == 0x10) {
      uVar8 = 3;
      goto LAB_c05a8bcc;
    }
    if (iVar7 == 0x20) {
      *puVar3 = 4;
    }
    else {
      if (iVar7 != 0x40) {
        *puVar3 = 0;
        goto LAB_c05a8bfc;
      }
      *puVar3 = 8;
      uVar5 = param_1[0x84];
      if (uVar5 != 0) {
        if (uVar5 < 0x101) {
          puVar3[2] = puVar3 + 3;
        }
        else {
          pvVar4 = FUN_c05a4228(uVar5);
          puVar3[2] = pvVar4;
          if (pvVar4 == (HLOCAL)0x0) goto LAB_c05a8bfc;
        }
        memcpy((void *)puVar3[2],(void *)(param_1[0x83] + (int)param_1),param_1[0x84]);
        puVar3[1] = param_1[0x84];
      }
    }
  }
  memcpy(puVar3 + 0x5b,param_1 + 1,(sVar2 + 1) * 2);
  bVar1 = FUN_c05a8e8c(FUN_c05a7f88,puVar3);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    puVar3 = (undefined4 *)0x0;
  }
LAB_c05a8bfc:
  if (puVar3 != (undefined4 *)0x0) {
    puVar6 = (undefined4 *)puVar3[2];
    if ((puVar6 != (undefined4 *)0x0) && (puVar6 != puVar3 + 3)) {
      FUN_c05a42b0(puVar6);
    }
    FUN_c05a42b0(puVar3);
  }
  return;
}



/* c05a8c48 FUN_c05a8c48 */

/* Boundary evidence: original MIPS .pdata c05a8c48..c05a8caf. Semantic name remains unreviewed. */

void FUN_c05a8c48(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  InterlockedIncrement((LONG *)&DAT_c05b6354);
  FUN_c05a4c10(param_1);
  bVar1 = FUN_c05a8e8c(FUN_c05a85d0,param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    InterlockedDecrement((LONG *)(param_1 + 0x1c));
    InterlockedDecrement((LONG *)&DAT_c05b6354);
  }
  return;
}



/* c05a8cb0 FUN_c05a8cb0 */

/* Boundary evidence: original MIPS .pdata c05a8cb0..c05a8db3. Semantic name remains unreviewed. */

undefined4 FUN_c05a8cb0(void)

{
  DWORD DVar1;
  int iVar2;
  int aiStack_830 [514];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  uint local_20;
  
  local_20 = DAT_c05b62e4;
  DVar1 = WaitForSingleObject(DAT_c05b6398,0xffffffff);
  while (DVar1 == 0) {
    iVar2 = ReadMsgQueue(DAT_c05b6398,aiStack_830,0x800,auStack_24,1,auStack_28);
    while (iVar2 != 0) {
      FUN_c05a8aa8(aiStack_830);
      iVar2 = ReadMsgQueue(DAT_c05b6398,aiStack_830,0x800,auStack_24,1,auStack_28);
    }
    DVar1 = WaitForSingleObject(DAT_c05b6398,0xffffffff);
  }
  FUN_c05b4904(local_20);
  return 0;
}



/* c05a8db4 FUN_c05a8db4 */

/* Boundary evidence: original MIPS .pdata c05a8db4..c05a8e8b. Semantic name remains unreviewed. */

undefined4 FUN_c05a8db4(void)

{
  DWORD DVar1;
  BOOL BVar2;
  int local_28 [8];
  
  DVar1 = FUN_c05aab38(&DAT_c05b6440);
  if (DVar1 == 0) {
    local_28[2] = 0x14;
    local_28[3] = 0;
    local_28[4] = 4;
    local_28[5] = 0x800;
    local_28[6] = 1;
    DAT_c05b6398 = CreateMsgQueue(0,local_28 + 2);
    if (DAT_c05b6398 != 0) {
      local_28[1] = 0x70;
      local_28[0] = DAT_c05b6398;
      BVar2 = DeviceIoControl(DAT_c05b6440,0x12081c,local_28,8,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
      if (BVar2 != 0) {
        CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05a8cb0,(LPVOID)0x0,0,(LPDWORD)0x0);
      }
    }
  }
  return 0;
}



/* c05a8e8c FUN_c05a8e8c */

/* Boundary evidence: original MIPS .pdata c05a8e8c..c05a8ef7. Semantic name remains unreviewed. */

bool FUN_c05a8e8c(undefined4 param_1,undefined4 param_2)

{
  HLOCAL pvVar1;
  
  pvVar1 = FUN_c05a4228(0x20);
  if (pvVar1 != (HLOCAL)0x0) {
    CTEInitEvent(pvVar1,param_1);
    CTEScheduleEvent(pvVar1,param_2);
  }
  return pvVar1 != (HLOCAL)0x0;
}



/* c05a8ef8 FUN_c05a8ef8 */

/* Boundary evidence: original MIPS .pdata c05a8ef8..c05a8fbb. Semantic name remains unreviewed. */

void FUN_c05a8ef8(void)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_38 = 0x14;
  local_34 = 2;
  local_30 = 0x10;
  local_2c = 0x248;
  local_28 = 0;
  DAT_c05b63a0 = CreateMsgQueue(L"WzcEventLoggingQueue",&local_38);
  local_38 = 0x14;
  local_34 = 2;
  local_30 = 0x10;
  local_2c = 0x248;
  local_28 = 1;
  DAT_c05b63a4 = CreateMsgQueue(L"WzcEventLoggingQueue",&local_38);
  if (DAT_c05b63a4 == 0) {
    CloseMsgQueue(DAT_c05b63a0);
    DAT_c05b63a0 = 0;
  }
  return;
}



/* c05a8fbc FUN_c05a8fbc */

/* Boundary evidence: original MIPS .pdata c05a8fbc..c05a918b. Semantic name remains unreviewed. */

void FUN_c05a8fbc(undefined4 param_1,void *param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5,wchar_t *param_6,undefined4 *param_7)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  uint _Size;
  uint uVar4;
  undefined1 auStack_4b8 [4];
  undefined1 auStack_4b4 [4];
  undefined4 local_4b0;
  undefined4 local_4ac;
  undefined1 local_4a8 [33];
  undefined4 local_487;
  undefined1 local_483;
  undefined1 local_482;
  undefined4 local_480;
  undefined4 local_47c;
  undefined1 auStack_478 [8];
  undefined2 local_470 [259];
  undefined2 local_26a;
  undefined1 auStack_268 [584];
  uint local_20;
  
  local_20 = DAT_c05b62e4;
  uVar4 = 0;
  if (DAT_c05b63a0 != 0) {
    local_4a8[0] = 0;
    local_47c = param_5;
    local_4ac = 4;
    local_4b0 = param_1;
    local_480 = param_4;
    GetCurrentFT(auStack_478);
    if (param_2 != (void *)0x0) {
      if (0x20 < param_3) {
        param_3 = 0x20;
      }
      memcpy(local_4a8,param_2,param_3);
      local_4a8[param_3] = 0;
    }
    if (param_6 == (wchar_t *)0x0) {
      local_470[0] = 0;
    }
    else {
      sVar2 = wcslen(param_6);
      _Size = (sVar2 + 1) * 2;
      if (_Size < 0x209) {
        memcpy(local_470,param_6,_Size);
      }
      else {
        memcpy(local_470,param_6,0x208);
        local_26a = 0;
      }
    }
    if (param_7 == (undefined4 *)0x0) {
      memset(&local_487,6,0);
    }
    else {
      local_487 = *param_7;
      local_482 = *(undefined1 *)((int)param_7 + 5);
      local_483 = *(undefined1 *)(param_7 + 1);
    }
    iVar3 = WriteMsgQueue(DAT_c05b63a0,&local_4b0,0x248,0,0);
    while ((iVar3 == 0 && (bVar1 = uVar4 < 3, uVar4 = uVar4 + 1, bVar1))) {
      ReadMsgQueue(DAT_c05b63a4,auStack_268,0x248,auStack_4b8,0,auStack_4b4);
      iVar3 = WriteMsgQueue(DAT_c05b63a0,&local_4b0,0x248,0,0);
    }
  }
  FUN_c05b4904(local_20);
  return;
}



/* c05a918c FUN_c05a918c */

/* Boundary evidence: original MIPS .pdata c05a918c..c05a92a7. Semantic name remains unreviewed. */

void FUN_c05a918c(undefined4 param_1,LPVOID param_2)

{
  LONG LVar1;
  HANDLE hHeap;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_2 + 8);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)param_2 + 0x44) == 0) {
    *(undefined4 *)((int)param_2 + 0x3c) = 0;
    EventModify(*(undefined4 *)((int)param_2 + 0x40),3);
  }
  else {
    *(undefined4 *)((int)param_2 + 0x48) = 1;
    (**(code **)((int)param_2 + 0x4c))(*(undefined4 *)((int)param_2 + 0x50),1);
    iVar2 = *(int *)((int)param_2 + 0x54);
    *(undefined4 *)((int)param_2 + 0x48) = 0;
    if ((iVar2 != 0) || (iVar2 = *(int *)((int)param_2 + 0x58), iVar2 != 0)) {
      CTEStartTimer((int)param_2 + 0x20,iVar2,FUN_c05a918c,param_2);
      LeaveCriticalSection(lpCriticalSection);
      return;
    }
    *(undefined4 *)((int)param_2 + 0x44) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  LVar1 = InterlockedDecrement((LONG *)((int)param_2 + 0x1c));
  if (LVar1 == 0) {
    iVar2 = *(int *)((int)param_2 + 0x5c);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      EventModify(iVar2,3);
    }
    DeleteCriticalSection(lpCriticalSection);
    CloseHandle(*(HANDLE *)((int)param_2 + 0x40));
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,param_2);
  }
  return;
}



/* c05a92a8 FUN_c05a92a8 */

/* Boundary evidence: original MIPS .pdata c05a92a8..c05a935f. Semantic name remains unreviewed. */

undefined4 * FUN_c05a92a8(void)

{
  HANDLE hHeap;
  undefined4 *_Dst;
  undefined4 *puVar1;
  
  hHeap = GetProcessHeap();
  _Dst = HeapAlloc(hHeap,8,0x2c);
  if (_Dst == (undefined4 *)0x0) {
    _Dst = (undefined4 *)0xffffffff;
  }
  else {
    memset(_Dst,0,0x2c);
    InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 2));
    puVar1 = _Dst + 7;
    _Dst[8] = puVar1;
    *puVar1 = puVar1;
    InterlockedIncrement(_Dst + 10);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6420);
    *_Dst = DAT_c05b6438;
    _Dst[1] = &DAT_c05b6438;
    *(undefined4 **)((int)DAT_c05b6438 + 4) = _Dst;
    DAT_c05b6438 = _Dst;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6420);
  }
  return _Dst;
}



/* c05a9360 FUN_c05a9360 */

/* Boundary evidence: original MIPS .pdata c05a9360..c05a93ef. Semantic name remains unreviewed. */

undefined4 * FUN_c05a9360(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6420);
  puVar1 = DAT_c05b6438;
  if ((undefined4 **)DAT_c05b6438 != &DAT_c05b6438) {
    do {
      if (puVar1 == param_1) break;
      puVar1 = (undefined4 *)*puVar1;
    } while ((undefined4 **)puVar1 != &DAT_c05b6438);
    if ((undefined4 **)puVar1 != &DAT_c05b6438) {
      InterlockedIncrement(puVar1 + 10);
      goto LAB_c05a93cc;
    }
  }
  puVar1 = (undefined4 *)0x0;
LAB_c05a93cc:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6420);
  return puVar1;
}



/* c05a93f0 FUN_c05a93f0 */

/* Boundary evidence: original MIPS .pdata c05a93f0..c05a9593. Semantic name remains unreviewed. */

undefined4
FUN_c05a93f0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  HANDLE pvVar1;
  undefined4 *_Dst;
  undefined4 *puVar2;
  
  pvVar1 = GetProcessHeap();
  _Dst = HeapAlloc(pvVar1,8,0x60);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x60);
    _Dst[0x13] = param_3;
    _Dst[0x14] = param_4;
    _Dst[0x15] = 0;
    _Dst[0x16] = param_6;
    InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 2));
    InterlockedIncrement(_Dst + 7);
    InterlockedIncrement(_Dst + 7);
    _Dst[0xf] = 0;
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    _Dst[0x10] = pvVar1;
    if ((((param_2 != (undefined4 *)0x0) ||
         (param_2 = DAT_c05b63a8, DAT_c05b63a8 != (undefined4 *)0x0)) ||
        (param_2 = FUN_c05a92a8(), DAT_c05b63a8 = param_2, param_2 != (undefined4 *)0xffffffff)) &&
       (puVar2 = FUN_c05a9360(param_2), puVar2 != (undefined4 *)0x0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 2));
      *_Dst = puVar2 + 7;
      _Dst[1] = puVar2[8];
      *(undefined4 **)puVar2[8] = _Dst;
      puVar2[8] = _Dst;
      LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 2));
      *param_1 = _Dst;
      _Dst[0x11] = 1;
      CTEStartTimer(_Dst + 8,param_5,FUN_c05a918c,_Dst);
      return 1;
    }
    CloseHandle((HANDLE)_Dst[0x10]);
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,_Dst);
  }
  return 0;
}



/* c05a9594 FUN_c05a9594 */

/* Boundary evidence: original MIPS .pdata c05a9594..c05a9867. Semantic name remains unreviewed. */

undefined4 FUN_c05a9594(undefined4 *param_1,int *param_2,int param_3)

{
  int *lpMem;
  LONG LVar1;
  HANDLE pvVar2;
  int iVar3;
  int *lpMem_00;
  LPCRITICAL_SECTION p_Var4;
  
  if (((param_1 != (undefined4 *)0x0) || (param_1 = DAT_c05b63a8, DAT_c05b63a8 != (undefined4 *)0x0)
      ) && (lpMem = FUN_c05a9360(param_1), lpMem != (int *)0x0)) {
    p_Var4 = (LPCRITICAL_SECTION)(lpMem + 2);
    EnterCriticalSection(p_Var4);
    for (lpMem_00 = (int *)lpMem[7]; (lpMem_00 != lpMem + 7 && (lpMem_00 != param_2));
        lpMem_00 = (int *)*lpMem_00) {
    }
    if ((lpMem_00 != lpMem) && (lpMem_00 != (int *)0x0)) {
      *(int *)lpMem_00[1] = *lpMem_00;
      *(int *)(*lpMem_00 + 4) = lpMem_00[1];
      LeaveCriticalSection(p_Var4);
      LVar1 = InterlockedDecrement(lpMem + 10);
      if (LVar1 == 0) {
        DeleteCriticalSection(p_Var4);
        pvVar2 = GetProcessHeap();
        HeapFree(pvVar2,0,lpMem);
      }
      LVar1 = InterlockedDecrement(lpMem + 10);
      if (LVar1 == 0) {
        DeleteCriticalSection(p_Var4);
        pvVar2 = GetProcessHeap();
        HeapFree(pvVar2,0,lpMem);
      }
      p_Var4 = (LPCRITICAL_SECTION)(lpMem_00 + 2);
      EnterCriticalSection(p_Var4);
      lpMem_00[0x17] = param_3;
      lpMem_00[0x15] = 0;
      lpMem_00[0x16] = 0;
      if (lpMem_00[0x11] == 1) {
        lpMem_00[0x11] = 0;
        iVar3 = CTEStopTimer(lpMem_00 + 8);
        if (iVar3 == 0) {
          if ((param_3 == -1) && (lpMem_00[0x12] == 0)) {
            LeaveCriticalSection(p_Var4);
            WaitForSingleObject((HANDLE)lpMem_00[0x10],0xffffffff);
            EventModify(lpMem_00 + 0x10,2);
            EnterCriticalSection(p_Var4);
          }
        }
        else {
          LVar1 = InterlockedDecrement(lpMem_00 + 7);
          if (LVar1 == 0) {
            iVar3 = lpMem_00[0x17];
            if ((iVar3 != 0) && (iVar3 != -1)) {
              EventModify(iVar3,3);
            }
            DeleteCriticalSection(p_Var4);
            CloseHandle((HANDLE)lpMem_00[0x10]);
            pvVar2 = GetProcessHeap();
            HeapFree(pvVar2,0,lpMem_00);
          }
        }
      }
      LeaveCriticalSection(p_Var4);
      LVar1 = InterlockedDecrement(lpMem_00 + 7);
      if (LVar1 != 0) {
        return 1;
      }
      iVar3 = lpMem_00[0x17];
      if ((iVar3 != 0) && (iVar3 != -1)) {
        EventModify(iVar3,3);
      }
      DeleteCriticalSection(p_Var4);
      CloseHandle((HANDLE)lpMem_00[0x10]);
      pvVar2 = GetProcessHeap();
      HeapFree(pvVar2,0,lpMem_00);
      return 1;
    }
    LeaveCriticalSection(p_Var4);
    LVar1 = InterlockedDecrement(lpMem + 10);
    if (LVar1 == 0) {
      DeleteCriticalSection(p_Var4);
      pvVar2 = GetProcessHeap();
      HeapFree(pvVar2,0,lpMem);
    }
  }
  return 0;
}



/* c05a9868 FUN_c05a9868 */

/* Boundary evidence: original MIPS .pdata c05a9868..c05a9b53. Semantic name remains unreviewed. */

undefined4 FUN_c05a9868(undefined4 *param_1,LPVOID param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 *lpMem;
  int iVar2;
  LONG LVar3;
  HANDLE pvVar4;
  undefined4 *lpMem_00;
  LPCRITICAL_SECTION lpCriticalSection;
  LONG *lpAddend;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  bVar1 = true;
  if (((param_1 != (undefined4 *)0x0) || (param_1 = DAT_c05b63a8, DAT_c05b63a8 != (undefined4 *)0x0)
      ) && (lpMem = FUN_c05a9360(param_1), lpMem != (undefined4 *)0x0)) {
    lpCriticalSection = (LPCRITICAL_SECTION)(lpMem + 2);
    EnterCriticalSection(lpCriticalSection);
    for (lpMem_00 = (undefined4 *)lpMem[7]; (lpMem_00 != lpMem + 7 && (lpMem_00 != param_2));
        lpMem_00 = (undefined4 *)*lpMem_00) {
    }
    if ((lpMem_00 != lpMem) && (lpMem_00 != (LPVOID)0x0)) {
      lpAddend = lpMem_00 + 7;
      InterlockedIncrement(lpAddend);
      LeaveCriticalSection(lpCriticalSection);
      lpCriticalSection_00 = (LPCRITICAL_SECTION)(lpMem_00 + 2);
      EnterCriticalSection(lpCriticalSection_00);
      if (lpMem_00[0x11] == 1) {
        iVar2 = CTEStopTimer(lpMem_00 + 8);
        if (iVar2 == 0) {
          if (lpMem_00[0x12] == 0) {
            lpMem_00[0x11] = 0;
            LeaveCriticalSection(lpCriticalSection_00);
            WaitForSingleObject((HANDLE)lpMem_00[0x10],0xffffffff);
            EventModify(lpMem_00 + 0x10,2);
            EnterCriticalSection(lpCriticalSection_00);
          }
          else {
            bVar1 = false;
          }
        }
        else {
          LVar3 = InterlockedDecrement(lpAddend);
          if (LVar3 == 0) {
            iVar2 = lpMem_00[0x17];
            if ((iVar2 != 0) && (iVar2 != -1)) {
              EventModify(iVar2,3);
            }
            DeleteCriticalSection(lpCriticalSection_00);
            CloseHandle((HANDLE)lpMem_00[0x10]);
            pvVar4 = GetProcessHeap();
            HeapFree(pvVar4,0,lpMem_00);
          }
        }
      }
      if (lpMem_00[0x16] != 0) {
        lpMem_00[0x15] = param_3;
        lpMem_00[0x16] = param_4;
        if (bVar1) {
          lpMem_00[0x11] = 1;
          InterlockedIncrement(lpAddend);
          CTEStartTimer(lpMem_00 + 8,lpMem_00[0x15],FUN_c05a918c,lpMem_00);
          lpMem_00[0x15] = 0;
        }
      }
      LeaveCriticalSection(lpCriticalSection_00);
      LVar3 = InterlockedDecrement(lpAddend);
      if (LVar3 == 0) {
        iVar2 = lpMem_00[0x17];
        if ((iVar2 != 0) && (iVar2 != -1)) {
          EventModify(iVar2,3);
        }
        DeleteCriticalSection(lpCriticalSection_00);
        CloseHandle((HANDLE)lpMem_00[0x10]);
        pvVar4 = GetProcessHeap();
        HeapFree(pvVar4,0,lpMem_00);
      }
      LVar3 = InterlockedDecrement(lpMem + 10);
      if (LVar3 != 0) {
        return 1;
      }
      DeleteCriticalSection(lpCriticalSection);
      pvVar4 = GetProcessHeap();
      HeapFree(pvVar4,0,lpMem);
      return 1;
    }
    LeaveCriticalSection(lpCriticalSection);
    LVar3 = InterlockedDecrement(lpMem + 10);
    if (LVar3 == 0) {
      DeleteCriticalSection(lpCriticalSection);
      pvVar4 = GetProcessHeap();
      HeapFree(pvVar4,0,lpMem);
    }
  }
  return 0;
}



/* c05a9b54 FUN_c05a9b54 */

/* Boundary evidence: original MIPS .pdata c05a9b54..c05a9bb7. Semantic name remains unreviewed. */

void FUN_c05a9b54(void)

{
  DAT_c05b643c = &DAT_c05b6438;
  DAT_c05b6438 = &DAT_c05b6438;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6420);
  FUN_c05a406c();
  FUN_c05aede8();
  if (DAT_c05b639c == 0) {
    FUN_c05a8ef8();
    FUN_c05a89d0();
  }
  return;
}



/* c05a9bb8 FUN_c05a9bb8 */

/* Boundary evidence: original MIPS .pdata c05a9bb8..c05a9c27. Semantic name remains unreviewed. */

undefined4 FUN_c05a9bb8(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    CxLogDeregister(DAT_c05b61e8);
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    DAT_c05b61e8 = CxLogRegister(&DAT_c05a1678,&PTR_DAT_c05b61d8,3,&DAT_c05b61e4);
  }
  return 1;
}



/* c05a9c28 FUN_c05a9c28 */

undefined4 FUN_c05a9c28(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  
  uVar1 = 0;
  if (param_1 == 0) {
    return 0xe8;
  }
  if (1 < param_2) {
    if (3 < param_2 + -2) {
      uVar1 = 1;
      if (2 < param_2 + -6) {
        uVar2 = (uint)*(ushort *)(param_1 + 6);
        uVar1 = 3;
        if (uVar2 != 0) {
          if (param_2 + -8 < (int)(uVar2 * 4)) {
            return 0xd;
          }
          iVar3 = param_2 + -8 + uVar2 * -4;
          puVar4 = (ushort *)(uVar2 * 4 + param_1 + 8);
          uVar1 = 7;
          if (1 < iVar3) {
            uVar2 = (uint)*puVar4;
            iVar3 = iVar3 + -2;
            uVar1 = 0xf;
            if (uVar2 != 0) {
              if (iVar3 < (int)(uVar2 * 4)) {
                return 0xd;
              }
              iVar3 = iVar3 + uVar2 * -4;
              uVar1 = 0x1f;
              if ((1 < iVar3) && (uVar1 = 0x3f, 1 < iVar3 + -2)) {
                uVar2 = (uint)puVar4[uVar2 * 2 + 2];
                uVar1 = 0x7f;
                if (uVar2 != 0) {
                  if (iVar3 + -4 < (int)(uVar2 << 4)) {
                    return 0xd;
                  }
                  uVar1 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = uVar1;
    }
    return 0;
  }
  return 0xd;
}



/* c05a9d5c FUN_c05a9d5c */

undefined4 FUN_c05a9d5c(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((param_1 & 0xffffff) == 0xac0f00) {
    uVar2 = 0;
    uVar3 = 0;
    do {
      if (*(uint *)((int)&DAT_c05b621c + uVar3) == param_1 >> 0x18) break;
      uVar3 = uVar3 + 0xc;
      uVar2 = uVar2 + 1;
    } while (uVar3 < 0x18);
    if (uVar2 < 2) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(uVar2 * 0xc + -0x3fa49de0);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(uVar2 * 0xc + -0x3fa49ddc);
      }
    }
    else {
      uVar1 = 0x490;
    }
  }
  else {
    uVar1 = 0x32;
  }
  return uVar1;
}



/* c05a9e10 FUN_c05a9e10 */

undefined4 FUN_c05a9e10(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((param_1 & 0xffffff) == 0xac0f00) {
    uVar2 = 0;
    uVar3 = 0;
    do {
      if (*(uint *)((int)&DAT_c05b6234 + uVar3) == param_1 >> 0x18) break;
      uVar3 = uVar3 + 0xc;
      uVar2 = uVar2 + 1;
    } while (uVar3 < 0x3c);
    if (uVar2 < 5) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = (&DAT_c05b6238)[uVar2 * 3];
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = (&DAT_c05b623c)[uVar2 * 3];
      }
    }
    else {
      uVar1 = 0x490;
    }
  }
  else {
    uVar1 = 0x32;
  }
  return uVar1;
}



/* c05a9ec4 FUN_c05a9ec4 */

/* Boundary evidence: original MIPS .pdata c05a9ec4..c05aa15f. Semantic name remains unreviewed. */

int FUN_c05a9ec4(short *param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  
  iVar9 = -1;
  local_34 = -1;
  local_38 = 0;
  local_30 = 0;
  iVar8 = -1;
  iVar3 = FUN_c05a9c28((int)param_1,param_2,&local_30);
  uVar2 = local_30;
  if (iVar3 != 0) {
    return iVar3;
  }
  if (*(int *)(param_3 + 0x60) == 0) {
    return 0x32;
  }
  if (*param_1 != 1) {
    return 0xd;
  }
  if ((local_30 & 1) == 0) {
    *(undefined4 *)(param_3 + 0x34) = 6;
    *(undefined4 *)(param_3 + 0x94) = 6;
    *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 0x10;
    return 0;
  }
  iVar3 = FUN_c05a9e10(*(uint *)(param_1 + 1),&local_30,&local_34);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (((uVar2 & 2) == 0) || ((uVar2 & 4) == 0)) {
    *(undefined4 *)(param_3 + 0x34) = 6;
    *(undefined4 *)(param_3 + 0x94) = 6;
    *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 0x10;
    return 0;
  }
  uVar1 = param_1[3];
  puVar5 = (uint *)(param_1 + 4);
  uVar6 = 0;
  uVar4 = local_2c;
  if (uVar1 != 0) {
    do {
      iVar3 = FUN_c05a9e10(*puVar5,&local_2c,&local_38);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (iVar8 < local_38) {
        uVar4 = local_2c;
        iVar8 = local_38;
      }
      uVar6 = uVar6 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar6 < uVar1);
  }
  if (((uVar2 & 8) == 0) || ((uVar2 & 0x10) == 0)) {
    if (iVar8 <= local_34) {
      uVar4 = local_30;
    }
    *(undefined4 *)(param_3 + 0x94) = 6;
    *(uint *)(param_3 + 0x34) = uVar4;
    *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 0x10;
    return 0;
  }
  uVar2 = *puVar5;
  puVar5 = (uint *)((int)puVar5 + 2);
  uVar7 = 0;
  uVar6 = local_2c;
  if ((ushort)uVar2 != 0) {
    do {
      iVar3 = FUN_c05a9d5c(*puVar5,&local_2c,&local_38);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (iVar9 < local_38) {
        uVar6 = local_2c;
        iVar9 = local_38;
      }
      uVar7 = uVar7 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar7 < (ushort)uVar2);
    if (-1 < iVar9) goto LAB_c05aa0b4;
  }
  uVar6 = 6;
LAB_c05aa0b4:
  if (iVar8 <= local_34) {
    uVar4 = local_30;
  }
  *(uint *)(param_3 + 0x34) = uVar4;
  *(uint *)(param_3 + 0x94) = uVar6;
  *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) | 0x10;
  return 0;
}



/* c05aa160 FUN_c05aa160 */

undefined4 FUN_c05aa160(int *param_1,uint *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x4de;
  if (*param_2 == 0) {
    uVar1 = 0;
  }
  else if (*param_2 < 4) {
    uVar1 = 0xd;
  }
  else {
    *param_3 = *(undefined4 *)*param_1;
    *param_2 = *param_2 - 4;
    *param_1 = *param_1 + 4;
  }
  return uVar1;
}



/* c05aa1b8 FUN_c05aa1b8 */

undefined4 FUN_c05aa1b8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  uVar1 = 0;
  if (param_1 != param_2) {
    iVar4 = 0;
    iVar3 = 0;
    iVar6 = 6;
    iVar2 = 2;
    piVar5 = &DAT_c05b61ec;
    do {
      if (iVar2 < 1) break;
      if (param_1 == *piVar5) {
        iVar4 = piVar5[1];
        iVar2 = iVar2 + -1;
      }
      if (param_2 == *piVar5) {
        iVar3 = piVar5[1];
        iVar2 = iVar2 + -1;
      }
      iVar6 = iVar6 + -1;
      piVar5 = piVar5 + 2;
    } while (0 < iVar6);
    if (iVar2 == 0) {
      if (iVar4 == iVar3) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
        if (iVar4 <= iVar3) {
          uVar1 = 0xffffffff;
        }
      }
    }
  }
  return uVar1;
}



/* c05aa240 FUN_c05aa240 */

undefined4 FUN_c05aa240(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0xf25000) {
    uVar1 = 1;
    goto LAB_c05aa2b8;
  }
  if (param_1 != 0x1f25000) {
    if (param_1 == 0x2f25000) {
      uVar1 = 4;
      goto LAB_c05aa2b8;
    }
    if ((param_1 == 0x3f25000) || (param_1 == 0x4f25000)) {
      uVar1 = 6;
      goto LAB_c05aa2b8;
    }
    if (param_1 != 0x5f25000) {
      return 0xd;
    }
  }
  uVar1 = 0;
LAB_c05aa2b8:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar1;
  }
  return 0;
}



/* c05aa2cc FUN_c05aa2cc */

undefined4 FUN_c05aa2cc(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0xf25000) {
    uVar1 = 5;
  }
  else if (param_1 == 0x1f25000) {
    uVar1 = 3;
  }
  else {
    if (param_1 != 0x2f25000) {
      return 0xd;
    }
    uVar1 = 4;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar1;
  }
  return 0;
}



/* c05aa32c FUN_c05aa32c */

/* Boundary evidence: original MIPS .pdata c05aa32c..c05aa443. Semantic name remains unreviewed. */

undefined4 FUN_c05aa32c(byte *param_1,uint param_2,uint param_3,void *param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != (byte *)0x0) {
    while (1 < param_2) {
      uVar2 = (uint)param_1[1];
      if (param_2 < uVar2 + 2) {
        return 0xd;
      }
      param_2 = (param_2 - uVar2) - 2;
      if (param_3 == *param_1) {
        if ((param_3 != 0xdd) || (param_4 == (void *)0x0)) {
          *param_5 = param_1;
          return 0;
        }
        if ((3 < uVar2) && (iVar1 = memcmp(param_1 + 2,param_4,4), iVar1 == 0)) {
          *param_5 = param_1;
          return 0;
        }
      }
      param_1 = param_1 + 2 + uVar2;
    }
  }
  return 0x490;
}



/* c05aa444 FUN_c05aa444 */

/* Boundary evidence: original MIPS .pdata c05aa444..c05aa837. Semantic name remains unreviewed. */

int FUN_c05aa444(int *param_1,uint param_2,int param_3,uint *param_4)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  undefined4 uVar10;
  ushort *local_res0;
  uint local_res4 [3];
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  int local_34;
  uint *local_30;
  
  if ((param_2 < 4) || (*param_1 != 0x1f25000)) {
    return 0x65d;
  }
  if (param_3 == 0) {
LAB_c05aa800:
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(param_3 + 0x60);
    local_3c = 1;
    local_40 = 4;
    if (iVar7 == 0) {
      uVar10 = 5;
      local_38 = 0;
    }
    else {
      uVar10 = 3;
      local_38 = 0x10;
    }
    local_30 = param_4;
    if (param_2 == 4) goto LAB_c05aa7b4;
    if (param_2 != 5) {
      local_res0 = (ushort *)((int)param_1 + 6);
      local_res4[0] = param_2 - 6;
      if ((short)param_1[1] == 1) {
        iVar9 = 0;
        local_44 = uVar10;
        local_34 = param_3;
        iVar4 = FUN_c05aa160((int *)&local_res0,local_res4,&local_48);
        iVar6 = local_48;
        if (iVar4 == 0x4de) {
          iVar5 = FUN_c05aa240(local_48,&local_3c);
          if (iVar5 != 0) {
            iVar4 = 0xd;
          }
          if (iVar4 != 0x4de) goto LAB_c05aa7a4;
          if ((iVar6 != 0xf25000) &&
             (((iVar7 == 1 || ((iVar6 != 0x1f25000 && (iVar6 != 0x5f25000)))) &&
              (iVar7 = FUN_c05aa240(iVar6,&local_40), iVar9 = iVar6, iVar7 != 0))))
          goto LAB_c05aa4f0;
          if (local_res4[0] != 0) {
            if (local_res4[0] != 1) {
              uVar1 = *local_res0;
              local_res0 = local_res0 + 1;
              local_res4[0] = local_res4[0] - 2;
              uVar8 = 0;
              if (uVar1 != 0) {
                do {
                  param_3 = local_34;
                  if (iVar4 != 0x4de) break;
                  iVar4 = FUN_c05aa160((int *)&local_res0,local_res4,&local_48);
                  iVar7 = local_48;
                  if ((((iVar4 == 0x4de) && (local_48 != 0x1f25000)) && (local_48 != 0x5f25000)) &&
                     ((iVar6 = FUN_c05aa240(local_48,(undefined4 *)0x0), iVar6 == 0 &&
                      (iVar6 = FUN_c05aa1b8(iVar9,iVar7), iVar6 < 0)))) {
                    iVar9 = iVar7;
                  }
                  uVar8 = uVar8 + 1;
                  param_3 = local_34;
                } while (uVar8 < uVar1);
              }
              uVar3 = local_res4[0];
              puVar2 = local_res0;
              if ((uVar8 != uVar1) || (iVar7 = FUN_c05aa240(iVar9,&local_40), iVar7 != 0)) {
                iVar4 = 0xd;
              }
              if (iVar4 == 0x4de) {
                if (uVar3 == 0) goto LAB_c05aa7b4;
                if (uVar3 == 1) goto LAB_c05aa4f0;
                uVar1 = *puVar2;
                local_res4[0] = uVar3 - 2;
                local_res0 = puVar2 + 1;
                iVar7 = 0;
                uVar8 = 0;
                if (uVar1 != 0) {
                  do {
                    if (iVar4 != 0x4de) break;
                    iVar4 = FUN_c05aa160((int *)&local_res0,local_res4,&local_48);
                    if (((iVar4 == 0x4de) && (iVar7 != 0x1f25000)) &&
                       ((local_48 == 0x2f25000 || (local_48 == 0x1f25000)))) {
                      iVar7 = local_48;
                    }
                    uVar8 = uVar8 + 1;
                  } while (uVar8 < uVar1);
                }
                if (uVar8 == uVar1) {
                  if ((iVar7 != 0) && (*(int *)(param_3 + 0x60) == 1)) {
                    iVar4 = FUN_c05aa2cc(iVar7,&local_44);
                    uVar10 = local_44;
                  }
                }
                else {
                  iVar4 = 0xd;
                }
              }
              goto LAB_c05aa7a4;
            }
            goto LAB_c05aa4f0;
          }
        }
        else {
LAB_c05aa7a4:
          if ((iVar4 != 0) && (iVar4 != 0x4de)) {
            return iVar4;
          }
        }
LAB_c05aa7b4:
        if ((local_30 == (uint *)0x0) || ((*local_30 & 2) == 0)) {
          *(undefined4 *)(param_3 + 0x34) = local_40;
          *(undefined4 *)(param_3 + 0x94) = uVar10;
          *(undefined4 *)(param_3 + 0xbc) = local_3c;
          *(uint *)(param_3 + 4) =
               (*(uint *)(param_3 + 4) ^ local_38) & 0x10 ^ *(uint *)(param_3 + 4);
        }
        goto LAB_c05aa800;
      }
    }
LAB_c05aa4f0:
    iVar7 = 0xd;
  }
  return iVar7;
}



/* c05aa838 FUN_c05aa838 */

/* Boundary evidence: original MIPS .pdata c05aa838..c05aa993. Semantic name remains unreviewed. */

int FUN_c05aa838(int *param_1,uint *param_2,int param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  
  pcVar4 = (char *)*param_1;
  iVar1 = 0;
  if (param_5 == (uint *)0x0) {
    iVar1 = 0x57;
  }
  uVar5 = *param_2;
  if (uVar5 == 0) {
    iVar1 = 0x103;
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  if (uVar5 < 2) {
    return 0xd;
  }
  uVar3 = (uint)(byte)pcVar4[1];
  if (uVar5 < uVar3 + 2) {
    return 0xd;
  }
  if (*pcVar4 == -0x23) {
    iVar1 = FUN_c05aa444((int *)(pcVar4 + 2),uVar3,param_3,param_5);
    if (iVar1 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 1;
      }
      goto LAB_c05aa940;
    }
    if (iVar1 == 0x65d) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0;
      }
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
    if (*pcVar4 != '0') goto LAB_c05aa954;
    if (param_3 != 0) {
      iVar2 = FUN_c05a9ec4((short *)(pcVar4 + 2),uVar3,param_3);
      iVar1 = 0;
      if (iVar2 != 0) {
        return iVar2;
      }
    }
LAB_c05aa940:
    *param_5 = *param_5 | 2;
  }
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_c05aa954:
  *param_1 = *param_1 + uVar3 + 2;
  *param_2 = (*param_2 - uVar3) - 2;
  return 0;
}



/* c05aa994 FUN_c05aa994 */

/* Boundary evidence: original MIPS .pdata c05aa994..c05aaa47. Semantic name remains unreviewed. */

void FUN_c05aa994(int param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_res0;
  uint local_res4 [3];
  int local_20 [2];
  
  local_20[1] = 0;
  iVar3 = 0;
  local_res0 = param_1;
  local_res4[0] = param_2;
  do {
    iVar1 = local_res0;
    local_20[0] = 0;
    iVar2 = FUN_c05aa838(&local_res0,local_res4,param_3,local_20,(uint *)(local_20 + 1));
    if (local_20[0] != 0) {
      iVar3 = iVar1;
    }
  } while (iVar2 == 0);
  if (iVar2 == 0x103) {
    iVar2 = 0;
  }
  if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
    *param_4 = iVar3;
  }
  return;
}



/* c05aaa48 FUN_c05aaa48 */

/* Boundary evidence: original MIPS .pdata c05aaa48..c05aab37. Semantic name remains unreviewed. */

void FUN_c05aaa48(uint *param_1,size_t param_2,undefined4 param_3)

{
  uint *_Src;
  uint _Size;
  undefined1 auStack_38 [36];
  uint local_14;
  
  local_14 = DAT_c05b62e4;
  if ((param_1 != (uint *)0x0) && ((DAT_c05b61e4 & 4) != 0)) {
    _Src = param_1 + 1;
    _Size = *param_1;
    if (0x20 < *param_1) {
      _Src = param_1;
      _Size = param_2;
    }
    if (((byte)*_Src == 0) || (0x1f < (byte)*_Src)) {
      memcpy(auStack_38,_Src,_Size);
      auStack_38[_Size] = 0;
    }
    else {
      memcpy(auStack_38,"<invalid>",10);
    }
    CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30004,"%hs SSID=%hs",param_3,auStack_38);
  }
  FUN_c05b4904(local_14);
  return;
}



/* c05aab38 FUN_c05aab38 */

/* Boundary evidence: original MIPS .pdata c05aab38..c05aabcf. Semantic name remains unreviewed. */

DWORD FUN_c05aab38(undefined4 *param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  pvVar1 = CreateFileW(L"UIO1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff);
  if (pvVar1 == (HANDLE)0xffffffff) {
    DVar2 = GetLastError();
  }
  else {
    *param_1 = pvVar1;
  }
  return DVar2;
}



/* c05aabd0 FUN_c05aabd0 */

undefined4 FUN_c05aabd0(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((((param_2 < 0x14) || (uVar2 = *(uint *)(param_1 + 4), uVar2 < 0x14)) || (param_2 < uVar2)) ||
     (((uVar3 = *(uint *)(param_1 + 0xc), uVar3 < 0x14 || (param_2 < uVar3)) ||
      ((param_2 - uVar2 < *(uint *)(param_1 + 8) || (param_2 - uVar3 < *(uint *)(param_1 + 0x10)))))
     )) {
    uVar1 = 0xd;
  }
  return uVar1;
}



/* c05aac48 FUN_c05aac48 */

/* Boundary evidence: original MIPS .pdata c05aac48..c05aad63. Semantic name remains unreviewed. */

DWORD FUN_c05aac48(HANDLE param_1,undefined4 param_2,size_t *param_3)

{
  bool bVar1;
  DWORD DVar2;
  BOOL BVar3;
  undefined4 *puVar4;
  HANDLE hDevice;
  HANDLE local_res0 [4];
  uint local_20 [2];
  
  bVar1 = false;
  local_res0[0] = param_1;
  if (param_1 == (HANDLE)0xffffffff) {
    DVar2 = FUN_c05aab38(local_res0);
    bVar1 = true;
    if ((DVar2 != 0) && (bVar1 = false, hDevice = local_res0[0], DVar2 != 0)) goto LAB_c05aad28;
  }
  hDevice = local_res0[0];
  memset((void *)param_3[1],0,*param_3);
  puVar4 = (undefined4 *)param_3[1];
  *puVar4 = param_2;
  BVar3 = DeviceIoControl(hDevice,0x12080c,(LPVOID)param_3[1],*param_3,(LPVOID)param_3[1],*param_3,
                          local_20,(LPOVERLAPPED)0x0);
  if (BVar3 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = FUN_c05aabd0((int)puVar4,local_20[0]);
  }
LAB_c05aad28:
  if (bVar1) {
    CloseHandle(hDevice);
  }
  return DVar2;
}



/* c05aad64 FUN_c05aad64 */

/* Boundary evidence: original MIPS .pdata c05aad64..c05aaf0f. Semantic name remains unreviewed. */

DWORD FUN_c05aad64(HANDLE param_1,wchar_t *param_2,size_t *param_3)

{
  bool bVar1;
  HANDLE hDevice;
  BOOL BVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  int *piVar6;
  DWORD DVar7;
  int iVar8;
  wchar_t *_Str;
  HANDLE local_res0 [4];
  uint local_30 [2];
  
  DVar7 = 0;
  bVar1 = false;
  local_res0[0] = param_1;
  if (param_1 == (HANDLE)0xffffffff) {
    DVar7 = FUN_c05aab38(local_res0);
    bVar1 = true;
    if (DVar7 != 0) {
      bVar1 = false;
    }
  }
  hDevice = local_res0[0];
  iVar8 = 0;
  do {
    if (DVar7 != 0) {
LAB_c05aaec4:
      if (bVar1) {
        CloseHandle(hDevice);
      }
      return DVar7;
    }
    memset((void *)param_3[1],0,*param_3);
    piVar6 = (int *)param_3[1];
    *piVar6 = iVar8;
    BVar2 = DeviceIoControl(hDevice,0x12080c,(LPVOID)param_3[1],*param_3,(LPVOID)param_3[1],*param_3
                            ,local_30,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar7 = GetLastError();
      if (DVar7 == 0x103) {
        DVar7 = 2;
      }
    }
    else {
      DVar7 = FUN_c05aabd0((int)piVar6,local_30[0]);
    }
    if (DVar7 == 0) {
      _Str = (wchar_t *)(piVar6[1] + (int)piVar6);
      sVar3 = wcslen(_Str);
      sVar4 = wcslen(param_2);
      if (sVar3 == sVar4) {
        sVar3 = wcslen(_Str);
        iVar5 = _wcsnicmp(_Str,param_2,sVar3);
        if (iVar5 == 0) {
          DVar7 = 0;
          goto LAB_c05aaec4;
        }
      }
    }
    iVar8 = iVar8 + 1;
  } while( true );
}



/* c05aaf10 FUN_c05aaf10 */

/* Boundary evidence: original MIPS .pdata c05aaf10..c05aaf97. Semantic name remains unreviewed. */

DWORD FUN_c05aaf10(wchar_t *param_1,int *param_2)

{
  size_t sVar1;
  DWORD DVar2;
  wchar_t awStack_118 [128];
  uint local_18;
  
  local_18 = DAT_c05b62e4;
  sVar1 = wcslen(param_1);
  if (sVar1 + 1 < 0x81) {
    wcscpy(awStack_118,param_1);
    DVar2 = FUN_c05b3b44(awStack_118,param_2);
    FUN_c05b4904(local_18);
  }
  else {
    FUN_c05b4904(local_18);
    DVar2 = 8;
  }
  return DVar2;
}



/* c05aaf98 FUN_c05aaf98 */

/* Boundary evidence: original MIPS .pdata c05aaf98..c05ab043. Semantic name remains unreviewed. */

DWORD FUN_c05aaf98(int param_1)

{
  size_t sVar1;
  DWORD DVar2;
  wchar_t *_Str;
  wchar_t awStack_118 [128];
  uint local_18;
  
  local_18 = DAT_c05b62e4;
  DVar2 = 0;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x60) != -1)) {
    _Str = *(wchar_t **)(param_1 + 0x34);
    sVar1 = wcslen(_Str);
    if (0x80 < sVar1 + 1) {
      FUN_c05b4904(local_18);
      return 8;
    }
    wcscpy(awStack_118,_Str);
    DVar2 = FUN_c05b3dac(awStack_118);
    *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
  }
  FUN_c05b4904(local_18);
  return DVar2;
}



/* c05ab044 FUN_c05ab044 */

/* Boundary evidence: original MIPS .pdata c05ab044..c05ab137. Semantic name remains unreviewed. */

DWORD FUN_c05ab044(HANDLE param_1,undefined4 param_2,undefined4 *param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_30 [2];
  undefined4 local_28 [2];
  undefined4 local_20;
  uint local_1c;
  
  local_1c = DAT_c05b62e4;
  local_30[0] = 0;
  if ((param_1 == (HANDLE)0xffffffff) || (param_3 == (undefined4 *)0x0)) {
    DVar2 = 0x57;
  }
  else {
    memset(local_28,0,0xc);
    local_28[0] = param_2;
    BVar1 = DeviceIoControl(param_1,0x120804,local_28,0xc,local_28,0xc,local_30,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
      *param_3 = local_20;
    }
  }
  FUN_c05b4904(local_1c);
  return DVar2;
}



/* c05ab138 FUN_c05ab138 */

/* Boundary evidence: original MIPS .pdata c05ab138..c05ab1e3. Semantic name remains unreviewed. */

DWORD FUN_c05ab138(HANDLE param_1,undefined4 param_2,undefined4 param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_c05b62e4;
  local_20[0] = 0;
  if (param_1 == (HANDLE)0xffffffff) {
    DVar2 = 0x57;
  }
  else {
    local_14 = 0;
    local_18 = param_2;
    local_10 = param_3;
    BVar1 = DeviceIoControl(param_1,0x120814,&local_18,0xc,(LPVOID)0x0,0,local_20,(LPOVERLAPPED)0x0)
    ;
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
  }
  FUN_c05b4904(local_c);
  return DVar2;
}



/* c05ab1e4 FUN_c05ab1e4 */

/* Boundary evidence: original MIPS .pdata c05ab1e4..c05ab3c7. Semantic name remains unreviewed. */

DWORD FUN_c05ab1e4(HANDLE param_1,undefined4 param_2,size_t *param_3,uint param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  size_t _Size;
  uint nInBufferSize;
  undefined4 *lpInBuffer;
  uint local_30 [2];
  
  lpInBuffer = (undefined4 *)0x0;
  if ((param_1 == (HANDLE)0xffffffff) || (param_3 == (size_t *)0x0)) {
    DVar2 = 0x57;
LAB_c05ab37c:
    if (DVar2 == 0) {
      return 0;
    }
  }
  else {
    if (param_4 < 0x20) {
      param_4 = 0x20;
    }
    do {
      FUN_c05a42b0(lpInBuffer);
      if (0x10000 < param_4) {
        param_4 = 0x10000;
      }
      nInBufferSize = param_4 + 8;
      lpInBuffer = FUN_c05a4228(nInBufferSize);
      if (lpInBuffer == (undefined4 *)0x0) {
        DVar2 = GetLastError();
        goto LAB_c05ab37c;
      }
      *lpInBuffer = param_2;
      BVar1 = DeviceIoControl(param_1,0x120804,lpInBuffer,nInBufferSize,lpInBuffer,nInBufferSize,
                              local_30,(LPOVERLAPPED)0x0);
      if (BVar1 != 0) {
        if (local_30[0] <= nInBufferSize) {
          _Size = local_30[0] - 8;
          param_3[1] = (size_t)lpInBuffer;
          *param_3 = _Size;
          if (_Size == 0) {
            param_3[1] = 0;
            FUN_c05a42b0(lpInBuffer);
            lpInBuffer = (undefined4 *)0x0;
          }
          else {
            memmove(lpInBuffer,lpInBuffer + 2,_Size);
          }
          DVar2 = 0;
          goto LAB_c05ab37c;
        }
        DVar2 = 0x57;
        break;
      }
      DVar2 = GetLastError();
      if (((DVar2 == 0x7a) || (DVar2 == 0x6f8)) && (param_4 < 0x10000)) {
        param_4 = param_4 + 0x200;
        DVar2 = 0;
      }
    } while (DVar2 == 0);
  }
  FUN_c05a42b0(lpInBuffer);
  param_3[1] = 0;
  *param_3 = 0;
  return DVar2;
}



/* c05ab3c8 FUN_c05ab3c8 */

/* Boundary evidence: original MIPS .pdata c05ab3c8..c05ab523. Semantic name remains unreviewed. */

DWORD FUN_c05ab3c8(HANDLE param_1,int param_2,size_t *param_3)

{
  char *pcVar1;
  DWORD DVar2;
  BOOL BVar3;
  int *lpInBuffer;
  SIZE_T nInBufferSize;
  DWORD local_20 [2];
  
  lpInBuffer = (int *)0x0;
  local_20[0] = 0;
  if ((DAT_c05b61e4 & 1) != 0) {
    pcVar1 = FUN_c05ad500(param_2);
    CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30001,"Set OID %hs",pcVar1);
  }
  if ((((param_1 == (HANDLE)0xffffffff) || (param_3 == (size_t *)0x0)) || (*param_3 == 0)) ||
     (param_3[1] == 0)) {
    DVar2 = 0x57;
  }
  else {
    nInBufferSize = *param_3 + 8;
    lpInBuffer = FUN_c05a4228(nInBufferSize);
    if (lpInBuffer != (int *)0x0) {
      *lpInBuffer = param_2;
      memcpy(lpInBuffer + 2,(void *)param_3[1],*param_3);
      lpInBuffer[1] = 0;
      BVar3 = DeviceIoControl(param_1,0x120814,lpInBuffer,nInBufferSize,(LPVOID)0x0,0,local_20,
                              (LPOVERLAPPED)0x0);
      if (BVar3 != 0) {
        DVar2 = 0;
        goto LAB_c05ab4f8;
      }
    }
    DVar2 = GetLastError();
  }
LAB_c05ab4f8:
  FUN_c05a42b0(lpInBuffer);
  return DVar2;
}



/* c05ab524 FUN_c05ab524 */

/* Boundary evidence: original MIPS .pdata c05ab524..c05ab90b. Semantic name remains unreviewed. */

DWORD FUN_c05ab524(int param_1)

{
  HLOCAL pvVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  size_t local_28;
  HLOCAL local_24;
  
  local_28 = 0;
  puVar8 = (undefined4 *)0x0;
  local_24 = (HLOCAL)0x0;
  iVar9 = 0;
  DVar2 = FUN_c05ab1e4(*(HANDLE *)(param_1 + 0x60),0xd010122,&local_28,0x18);
  pvVar1 = local_24;
  if (DVar2 != 0) goto LAB_c05ab8c8;
  if (((0x17 < local_28) && (local_24 != (HLOCAL)0x0)) &&
     (iVar3 = *(int *)((int)local_24 + 0xc), (uint)((iVar3 + 2) * 8) <= local_28)) {
    if (*(int *)((int)local_24 + 4) != 2) {
      DVar2 = 0x666;
      goto LAB_c05ab8c8;
    }
    if (((2 < *(uint *)((int)local_24 + 8)) && (*(uint *)((int)local_24 + 8) < 0x11)) &&
       (iVar3 != 0)) {
      piVar7 = (int *)((int)local_24 + 0x10);
      piVar6 = piVar7;
      do {
        uVar5 = 0;
        do {
          if ((*piVar6 == *(int *)((int)&DAT_c05b6270 + uVar5)) &&
             (piVar6[1] == *(int *)((int)&DAT_c05b6274 + uVar5))) {
            iVar9 = iVar9 + 1;
            break;
          }
          uVar5 = uVar5 + 8;
        } while (uVar5 < 0x70);
        iVar3 = iVar3 + -1;
        piVar6 = piVar6 + 2;
      } while (iVar3 != 0);
      if (iVar9 != 0) {
        puVar8 = FUN_c05a4228((iVar9 + 1) * 8);
        if (puVar8 != (undefined4 *)0x0) {
          *puVar8 = *(undefined4 *)((int)pvVar1 + 8);
          puVar8[1] = iVar9;
          uVar5 = 0;
          if (*(int *)((int)pvVar1 + 0xc) != 0) {
            piVar6 = puVar8 + 2;
            do {
              uVar4 = 0;
              do {
                if ((*piVar7 == *(int *)((int)&DAT_c05b6270 + uVar4)) &&
                   (piVar7[1] == *(int *)((int)&DAT_c05b6274 + uVar4))) {
                  *piVar6 = *piVar7;
                  piVar6[1] = piVar7[1];
                  piVar6 = piVar6 + 2;
                  break;
                }
                uVar4 = uVar4 + 8;
              } while (uVar4 < 0x70);
              uVar5 = uVar5 + 1;
              piVar7 = piVar7 + 2;
            } while (uVar5 < *(uint *)((int)pvVar1 + 0xc));
          }
          *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x300;
          *(undefined4 **)(param_1 + 0x68) = puVar8;
          local_38 = 1;
          local_2c = 0;
          local_28 = 0;
          local_30 = 0;
          local_34 = 0;
          CxRegReadValues(0x80000002,L"Comm\\80211i\\PMKCache",L"Enabled",4,0,&local_38,4,
                          L"MaxEntries",4,0,&local_2c,4,L"CacheTimeoutMs",4,0,&local_28,4,
                          L"PreAuthenticationEnabled",4,0,&local_30,4,L"OpportunisticPMKEnabled",4,0
                          ,&local_34,4,0);
          if ((local_38 == 0) || (*(int *)(param_1 + 0x70) != 0)) goto LAB_c05ab8c8;
          iVar9 = FUN_c05acb48();
          *(int *)(param_1 + 0x70) = iVar9;
          if (iVar9 != 0) {
            DVar2 = FUN_c05acba8(iVar9,(undefined4 *)(param_1 + 0x4c),
                                 **(undefined4 **)(param_1 + 0x68),
                                 *(STRSAFE_LPCWSTR *)(param_1 + 0x34));
            if (DVar2 == 0) {
              uVar5 = (uint)(local_38 != 0);
              if (local_34 != 0) {
                uVar5 = uVar5 | 2;
              }
              FUN_c05b1a34(*(int *)(param_1 + 0x70),uVar5);
              FUN_c05ad248(*(LPCRITICAL_SECTION *)(param_1 + 0x70),local_30);
              if (local_2c != 0) {
                FUN_c05b1a40(*(int *)(param_1 + 0x70),local_2c);
              }
              if (local_28 != 0) {
                FUN_c05b27c8(*(LPCRITICAL_SECTION *)(param_1 + 0x70),local_28);
              }
              FUN_c05b1a48(*(int *)(param_1 + 0x70),FUN_c05a7e38,0,param_1);
              FUN_c05acc00(*(int *)(param_1 + 0x70),FUN_c05adb4c,param_1);
            }
            goto LAB_c05ab8c8;
          }
        }
        DVar2 = 8;
        goto LAB_c05ab8c8;
      }
    }
  }
  DVar2 = 0xd;
LAB_c05ab8c8:
  FUN_c05a42b0(pvVar1);
  if (DVar2 != 0) {
    FUN_c05a42b0(puVar8);
  }
  return DVar2;
}



/* c05ab90c FUN_c05ab90c */

/* Boundary evidence: original MIPS .pdata c05ab90c..c05aba3f. Semantic name remains unreviewed. */

undefined4 FUN_c05ab90c(int param_1)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_40 [4];
  int local_30 [4];
  
  local_40[0] = 6;
  local_40[1] = 4;
  local_40[2] = 0;
  local_30[0] = 7;
  local_30[1] = 5;
  iVar3 = 0;
  local_30[2] = 2;
  iVar4 = 0;
  do {
    iVar5 = *(int *)((int)local_40 + iVar4);
    DVar1 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xd01011b,iVar5);
    if (DVar1 == 0) {
      DVar1 = FUN_c05ab044(*(HANDLE *)(param_1 + 0x60),0xd01011b,(int *)(param_1 + 0xa8));
      if ((DVar1 == 0) &&
         ((iVar2 = *(int *)(param_1 + 0xa8), iVar2 == iVar5 ||
          (iVar2 == *(int *)((int)local_30 + iVar4))))) break;
    }
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar4 < 0xc);
  *(undefined1 *)(param_1 + 100) = 0;
  if (iVar3 < 3) {
    *(uint *)(param_1 + 100) = local_40[iVar3] & 0xff | *(uint *)(param_1 + 100);
  }
  else {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 3;
  }
  return 0;
}



/* c05aba40 FUN_c05aba40 */

/* Boundary evidence: original MIPS .pdata c05aba40..c05abae7. Semantic name remains unreviewed. */

undefined4 FUN_c05aba40(int param_1)

{
  DWORD DVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffeff;
  DVar1 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xd010118,3);
  if (DVar1 == 0) {
    DVar1 = FUN_c05ab044(*(HANDLE *)(param_1 + 0x60),0xd010118,(int *)(param_1 + 0x108));
    if ((DVar1 == 0) && (*(int *)(param_1 + 0x108) == 3)) {
      *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x100;
    }
  }
  return 0;
}



/* c05abae8 FUN_c05abae8 */

/* Boundary evidence: original MIPS .pdata c05abae8..c05abb53. Semantic name remains unreviewed. */

DWORD FUN_c05abae8(int param_1,size_t *param_2)

{
  DWORD DVar1;
  
  *param_2 = 0;
  param_2[1] = 0;
  DVar1 = FUN_c05ab1e4(*(HANDLE *)(param_1 + 0x60),0xd010102,param_2,0x24);
  if (DVar1 == 0) {
    FUN_c05aaa48((uint *)param_2[1],*param_2,"Query");
  }
  return DVar1;
}



/* c05abb54 FUN_c05abb54 */

/* Boundary evidence: original MIPS .pdata c05abb54..c05abbbf. Semantic name remains unreviewed. */

DWORD FUN_c05abb54(int param_1,size_t *param_2)

{
  DWORD DVar1;
  
  DVar1 = 0;
  if ((*param_2 != 0) &&
     (DVar1 = FUN_c05ab3c8(*(HANDLE *)(param_1 + 0x60),0xd010102,param_2), DVar1 == 0)) {
    FUN_c05aaa48((uint *)param_2[1],*param_2,&DAT_c05a1790);
  }
  return DVar1;
}



/* c05abbc0 FUN_c05abbc0 */

/* Boundary evidence: original MIPS .pdata c05abbc0..c05abc7f. Semantic name remains unreviewed. */

DWORD FUN_c05abbc0(int param_1)

{
  DWORD DVar1;
  size_t local_18;
  undefined4 *local_14;
  
  local_18 = 0;
  local_14 = (undefined4 *)0x0;
  DVar1 = FUN_c05aeec4(param_1,0x100000,(uint *)0x0);
  if ((DVar1 == 0) &&
     (DVar1 = FUN_c05ab1e4(*(HANDLE *)(param_1 + 0x60),0x1010102,&local_18,6), DVar1 == 0)) {
    if (local_18 == 6) {
      *(undefined4 *)(param_1 + 0x4c) = *local_14;
      *(undefined2 *)(param_1 + 0x50) = *(undefined2 *)(local_14 + 1);
    }
    else {
      DVar1 = 0xd;
    }
    FUN_c05a42b0(local_14);
  }
  return DVar1;
}



/* c05abc80 FUN_c05abc80 */

/* Boundary evidence: original MIPS .pdata c05abc80..c05ac02b. Semantic name remains unreviewed. */

DWORD FUN_c05abc80(int param_1,int param_2,uint param_3,uint *param_4)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  uint uVar6;
  uint _Size;
  size_t local_58;
  uint *local_54;
  uint local_50;
  undefined1 auStack_4c [32];
  uint local_2c;
  
  local_2c = DAT_c05b62e4;
  DVar5 = 0;
  uVar6 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    DVar5 = 0x57;
  }
  else {
    if ((param_3 & 0x200000) != 0) {
      DVar5 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xd010108,*(undefined4 *)(param_2 + 0x14));
      if (DVar5 == 0) {
        uVar6 = 0x200000;
        *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_2 + 0x14);
      }
      else {
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0xd4);
      }
    }
    if ((param_3 & 0x400000) != 0) {
      DVar1 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xd010118,*(undefined4 *)(param_2 + 0x18));
      if (DVar1 == 0) {
        uVar6 = uVar6 | 0x400000;
        *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_2 + 0x18);
      }
      else {
        *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x108);
      }
      if (DVar5 == 0) {
        DVar5 = DVar1;
      }
    }
    if ((param_3 & 0x40000000) != 0) {
      DVar1 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xd01011c,0);
      if (DVar1 == 0) {
        uVar6 = uVar6 | 0x40000000;
      }
      if (DVar5 == 0) {
        DVar5 = DVar1;
      }
    }
    if ((param_3 & 0x10000000) != 0) {
      if ((*(uint *)(param_1 + 100) & 0x100) == 0) {
        iVar3 = 0xd010113;
      }
      else {
        iVar3 = 0xd01011d;
      }
      DVar1 = FUN_c05ab3c8(*(HANDLE *)(param_1 + 0x60),iVar3,(size_t *)(param_2 + 0x48));
      if (DVar1 == 0) {
        uVar6 = uVar6 | 0x10000000;
      }
      if (DVar5 == 0) {
        DVar5 = DVar1;
      }
    }
    DVar1 = 0x57;
    if ((param_3 & 0x20000000) != 0) {
      if ((*(uint *)(param_2 + 0x48) < 0x10) || (*(int *)(param_2 + 0x4c) == 0)) {
        DVar2 = 0x57;
      }
      else {
        DVar2 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xd010114,
                             *(undefined4 *)(*(int *)(param_2 + 0x4c) + 4));
        if (DVar2 == 0) {
          uVar6 = uVar6 | 0x20000000;
        }
      }
      if (DVar5 == 0) {
        DVar5 = DVar2;
      }
    }
    if ((param_3 & 0x800000) != 0) {
      DVar2 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xd01011b,*(undefined4 *)(param_2 + 0x1c));
      if (DVar2 == 0) {
        uVar6 = uVar6 | 0x800000;
        *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0x1c);
      }
      else {
        *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0xa8);
      }
      if (DVar5 == 0) {
        DVar5 = DVar2;
      }
    }
    if ((param_3 & 0x1000000) != 0) {
      _Size = *(uint *)(param_2 + 0x28);
      if (_Size < 0x21) {
        memset(auStack_4c,0,0x20);
        local_50 = _Size;
        memcpy(auStack_4c,*(void **)(param_2 + 0x2c),_Size);
        local_58 = 0x24;
        local_54 = &local_50;
        DVar1 = FUN_c05abb54(param_1,&local_58);
        if (DVar1 == 0) {
          memcpy((void *)(param_1 + 0x84),&local_50,0x24);
          uVar6 = uVar6 | 0x1000000;
          memset((void *)(param_1 + 0x7c),0,6);
        }
      }
      if (DVar5 == 0) {
        DVar5 = DVar1;
      }
    }
    if ((param_3 & 0x2000000) != 0) {
      DVar1 = FUN_c05ab3c8(*(HANDLE *)(param_1 + 0x60),0xd010101,(size_t *)(param_2 + 0x30));
      if (DVar1 == 0) {
        puVar4 = *(undefined4 **)(param_2 + 0x34);
        uVar6 = uVar6 | 0x2000000;
        *(undefined4 *)(param_1 + 0x7c) = *puVar4;
        *(undefined2 *)(param_1 + 0x80) = *(undefined2 *)(puVar4 + 1);
      }
      if (DVar5 == 0) {
        DVar5 = DVar1;
      }
    }
    if (DAT_c05b6364 != 3) {
      FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xd010216,DAT_c05b6364);
    }
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar6;
  }
  FUN_c05b4904(local_2c);
  return DVar5;
}



/* c05ac02c FUN_c05ac02c */

/* Boundary evidence: original MIPS .pdata c05ac02c..c05ac40f. Semantic name remains unreviewed. */

DWORD FUN_c05ac02c(int param_1,uint param_2,uint *param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  uint *puVar3;
  void *_Dst;
  uint uVar4;
  uint uVar5;
  DWORD DVar6;
  uint uVar7;
  int *piVar8;
  size_t local_30;
  uint *local_2c;
  
  DVar6 = 0;
  uVar7 = 0;
  if (param_1 == 0) {
    DVar6 = 0x57;
    goto LAB_c05ac3d0;
  }
  piVar8 = (int *)(param_1 + 0x60);
  if (*piVar8 == -1) {
LAB_c05ac0ac:
    DVar6 = FUN_c05aaf10(*(wchar_t **)(param_1 + 0x34),piVar8);
    if (DVar6 != 0) goto LAB_c05ac3d0;
    if ((param_2 & 0x100000) != 0) {
      uVar7 = 0x100000;
    }
  }
  else if ((param_2 & 0x100000) != 0) {
    if (*piVar8 != -1) {
      FUN_c05aaf98(param_1);
    }
    goto LAB_c05ac0ac;
  }
  DVar2 = DVar6;
  if ((param_2 & 0x8000000) != 0) {
    DVar1 = GetTickCount();
    uVar4 = DVar1 - *(int *)(param_1 + 0x154);
    uVar5 = (int)uVar4 >> 0x1f;
    if (DAT_c05b636c < (int)((uVar4 ^ uVar5) - uVar5)) {
      DVar2 = FUN_c05ab138((HANDLE)*piVar8,0xd01011a,0);
      *(DWORD *)(param_1 + 0x154) = DVar1;
    }
    else {
      DVar2 = 0;
    }
    if (DVar2 == 0) {
      uVar7 = uVar7 | 0x8000000;
      DVar2 = DVar6;
    }
  }
  if ((param_2 & 0x400000) != 0) {
    DVar6 = FUN_c05ab044((HANDLE)*piVar8,0xd010118,(undefined4 *)(param_1 + 0x108));
    if (DVar6 == 0) {
      uVar7 = uVar7 | 0x400000;
    }
    else if (DVar2 == 0) {
      DVar2 = DVar6;
    }
  }
  if ((param_2 & 0x200000) != 0) {
    DVar6 = FUN_c05ab044((HANDLE)*piVar8,0xd010108,(undefined4 *)(param_1 + 0xd4));
    if (DVar6 == 0) {
      uVar7 = uVar7 | 0x200000;
    }
    else if (DVar2 == 0) {
      DVar2 = DVar6;
    }
  }
  if ((param_2 & 0x800000) != 0) {
    DVar6 = FUN_c05ab044((HANDLE)*piVar8,0xd01011b,(undefined4 *)(param_1 + 0xa8));
    if (DVar6 == 0) {
      uVar7 = uVar7 | 0x800000;
    }
    else if (DVar2 == 0) {
      DVar2 = DVar6;
    }
  }
  if ((param_2 & 0x2000000) != 0) {
    local_30 = 0;
    local_2c = (uint *)0x0;
    DVar6 = FUN_c05ab1e4((HANDLE)*piVar8,0xd010101,&local_30,6);
    puVar3 = local_2c;
    _Dst = (void *)(param_1 + 0x7c);
    if (DVar6 == 0) {
      if (local_30 == 6) {
        memcpy(_Dst,local_2c,6);
      }
      else {
        memset(_Dst,0,6);
        DVar6 = 0xd;
      }
    }
    else {
      memset(_Dst,0,6);
    }
    FUN_c05a42b0(puVar3);
    if (DVar6 == 0) {
      uVar7 = uVar7 | 0x2000000;
    }
    else if (DVar2 == 0) {
      DVar2 = DVar6;
    }
  }
  if ((param_2 & 0x1000000) != 0) {
    DVar6 = FUN_c05abae8(param_1,&local_30);
    puVar3 = local_2c;
    if (DVar6 == 0) {
      uVar7 = uVar7 | 0x1000000;
    }
    else if (DVar2 == 0) {
      DVar2 = DVar6;
    }
    if (local_2c != (uint *)0x0) {
      if (0x20 < *local_2c) {
        memmove(local_2c + 1,local_2c,local_30);
        *puVar3 = local_30;
      }
      memcpy((void *)(param_1 + 0x84),puVar3,0x24);
    }
    FUN_c05a42b0(puVar3);
  }
  DVar6 = DVar2;
  if ((param_2 & 0x4000000) != 0) {
    local_30 = 0;
    local_2c = (HLOCAL)0x0;
    DVar1 = FUN_c05ab1e4((HANDLE)*piVar8,0xd010217,&local_30,0x824);
    if (DVar1 == 0) {
      puVar3 = FUN_c05a44c4(&local_30);
      if ((local_2c == (HLOCAL)0x0) || (puVar3 != (uint *)0x0)) {
        FUN_c05a42b0(*(HLOCAL *)(param_1 + 0x138));
        uVar7 = uVar7 | 0x4000000;
        *(uint **)(param_1 + 0x138) = puVar3;
      }
      else {
        DVar1 = GetLastError();
      }
      FUN_c05a42b0(local_2c);
    }
    if (DVar2 == 0) {
      DVar6 = DVar1;
    }
  }
LAB_c05ac3d0:
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar7;
  }
  return DVar6;
}



/* c05ac410 FUN_c05ac410 */

/* Boundary evidence: original MIPS .pdata c05ac410..c05ac5d7. Semantic name remains unreviewed. */

int FUN_c05ac410(int param_1)

{
  undefined1 *puVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  size_t local_60;
  undefined1 *local_5c;
  undefined1 local_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [20];
  byte abStack_38 [32];
  uint local_18;
  
  local_18 = DAT_c05b62e4;
  DVar2 = FUN_c05ab524(param_1);
  if (DVar2 == 0) {
    FUN_c05b4904(local_18);
    return 0;
  }
  iVar3 = FUN_c05aba40(param_1);
  if (iVar3 == 0) {
    iVar3 = FUN_c05ab90c(param_1);
  }
  uVar4 = *(uint *)(param_1 + 100);
  if ((((uVar4 & 0x100) != 0) && ((uVar4 & 0xff) != 4)) && ((uVar4 & 0xff) != 6)) {
    *(uint *)(param_1 + 100) = uVar4 & 0xfffffeff;
  }
  if (iVar3 == 0) {
    if ((*(uint *)(param_1 + 100) & 0x100) != 0) {
      puVar1 = local_58 + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | 0x40U >> (3 - uVar4) * 8;
      puVar1 = auStack_54 + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | 0xc0000001U >> (3 - uVar4) * 8;
      puVar1 = auStack_50 + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & -1 << (uVar4 + 1) * 8 | 0x20U >> (3 - uVar4) * 8;
      local_58 = (undefined1  [4])0x40;
      auStack_54 = (undefined1  [4])0xc0000001;
      auStack_50 = (undefined1  [4])0x20;
      memset(auStack_4c,0xff,6);
      iVar3 = FUN_c05a47a0(abStack_38,0x20,0,0xff);
      if (iVar3 != 0) goto LAB_c05ac5b4;
      local_5c = local_58;
      local_60 = (size_t)local_58;
      DVar2 = FUN_c05ab3c8(*(HANDLE *)(param_1 + 0x60),0xd01011d,&local_60);
      if (DVar2 != 0x57) {
        *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffeff;
      }
      iVar3 = 0;
    }
    if ((*(uint *)(param_1 + 100) & 0x100) != 0) {
      local_60 = 0;
      local_5c = (undefined1 *)0x0;
      DVar2 = FUN_c05ab1e4(*(HANDLE *)(param_1 + 0x60),0xd01011f,&local_60,0x28);
      if (DVar2 != 0) {
        *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffeff;
      }
      iVar3 = 0;
      FUN_c05a42b0(local_5c);
    }
  }
LAB_c05ac5b4:
  FUN_c05b4904(local_18);
  return iVar3;
}



/* c05ac5e4 FUN_c05ac5e4 */

/* Boundary evidence: original MIPS .pdata c05ac5e4..c05ac61b. Semantic name remains unreviewed. */

bool FUN_c05ac5e4(undefined4 param_1,void *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,param_3,6);
  return iVar1 == 0;
}



/* c05ac61c FUN_c05ac61c */

/* Boundary evidence: original MIPS .pdata c05ac61c..c05ac6ab. Semantic name remains unreviewed. */

undefined4 FUN_c05ac61c(int *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  puVar2 = operator_new(6);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xe;
  }
  else {
    *puVar2 = *param_2;
    uVar1 = *(undefined1 *)((int)param_2 + 5);
    *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(param_2 + 1);
    *(undefined1 *)((int)puVar2 + 5) = uVar1;
    FUN_c05b3f48(param_1,(int)puVar2);
  }
  return uVar3;
}



/* c05ac6ac FUN_c05ac6ac */

/* Boundary evidence: original MIPS .pdata c05ac6ac..c05ac6c7. Semantic name remains unreviewed. */

void FUN_c05ac6ac(undefined4 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}



/* c05ac6c8 FUN_c05ac6c8 */

/* Boundary evidence: original MIPS .pdata c05ac6c8..c05ac7af. Semantic name remains unreviewed. */

undefined4 FUN_c05ac6c8(int param_1)

{
  int iVar1;
  uint uVar2;
  void *_Buf1;
  
  if (*(uint *)(param_1 + 0x2f0) < *(uint *)(param_1 + 0x21c)) {
    do {
      _Buf1 = (void *)(*(int *)(param_1 + 0x2f0) * 0xc + *(int *)(param_1 + 0x220));
      iVar1 = memcmp(_Buf1,(void *)(param_1 + 0x2fa),6);
      if ((((iVar1 != 0) && ((*(uint *)((int)_Buf1 + 8) & 1) != 0)) &&
          (iVar1 = FUN_c05b4160((int *)(param_1 + 0x304),_Buf1), iVar1 == 0)) &&
         (iVar1 = FUN_c05b146c((int *)(param_1 + 0x228),_Buf1), iVar1 == 0)) {
        return 1;
      }
      uVar2 = *(int *)(param_1 + 0x2f0) + 1;
      *(uint *)(param_1 + 0x2f0) = uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0x21c));
  }
  return 0;
}



/* c05ac7b0 FUN_c05ac7b0 */

/* Boundary evidence: original MIPS .pdata c05ac7b0..c05ac7f3. Semantic name remains unreviewed. */

void FUN_c05ac7b0(int param_1)

{
  if (*(int *)(param_1 + 0x300) != 0) {
    (*DAT_c05b6530)();
  }
  *(undefined4 *)(param_1 + 0x300) = 0;
  *(undefined1 *)(param_1 + 0x2ed) = 0;
  return;
}



/* c05ac7f4 FUN_c05ac7f4 */

/* Boundary evidence: original MIPS .pdata c05ac7f4..c05ac83b. Semantic name remains unreviewed. */

undefined4 FUN_c05ac7f4(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x2f0) = *(int *)(param_1 + 0x2f0) + 1;
  iVar1 = FUN_c05ac6c8(param_1);
  if (iVar1 != 0) {
    FUN_c05acc9c(param_1);
  }
  return 0;
}



/* c05ac83c FUN_c05ac83c */

/* Boundary evidence: original MIPS .pdata c05ac83c..c05ac89b. Semantic name remains unreviewed. */

undefined4 FUN_c05ac83c(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_c05b4160((int *)(param_1 + 0x304),param_2);
  if (iVar1 == 0) {
    uVar2 = FUN_c05ac61c((int *)(param_1 + 0x304),param_2);
  }
  return uVar2;
}



/* c05ac89c FUN_c05ac89c */

/* Boundary evidence: original MIPS .pdata c05ac89c..c05aca27. Semantic name remains unreviewed. */

void FUN_c05ac89c(LPCRITICAL_SECTION param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  int iVar2;
  char local_48 [4];
  uint local_44;
  undefined1 auStack_40 [32];
  uint local_20;
  
  local_20 = DAT_c05b62e4;
  FUN_c05b17f0(param_1);
  if (*(char *)((int)&param_1[0x1f].LockCount + 1) == '\0') goto LAB_c05ac9fc;
  if (param_2 != 0) {
    *(undefined4 *)(param_2 + -0xe) = param_1[0x1f].OwningThread;
    uVar1 = *(undefined2 *)&param_1[0x1f].LockSemaphore;
    *(char *)(param_2 + -10) = (char)uVar1;
    *(char *)(param_2 + -9) = (char)((ushort)uVar1 >> 8);
    *(ULONG_PTR *)(param_2 + -8) = param_1->SpinCount;
    uVar1 = *(undefined2 *)&param_1[1].DebugInfo;
    *(char *)(param_2 + -4) = (char)uVar1;
    *(char *)(param_2 + -3) = (char)((ushort)uVar1 >> 8);
    *(undefined1 *)(param_2 + -2) = 0x88;
    *(undefined1 *)(param_2 + -1) = 199;
    if (param_1[0x20].SpinCount != 0) {
      FUN_c05b180c(param_1);
      (*(code *)param_1[0x20].SpinCount)
                (param_1[0x21].DebugInfo,(undefined4 *)(param_2 + -0xe),param_3 + 0xe);
      FUN_c05b17f0(param_1);
    }
  }
  if (param_4 == 0) goto LAB_c05ac9fc;
  if (param_5 == 0) {
    local_44 = 0x20;
    iVar2 = (*DAT_c05b64f0)(param_1[0x20].DebugInfo,auStack_40,&local_44);
    if (iVar2 != 0) goto LAB_c05ac9e0;
    FUN_c05b2600(param_1,(int *)&param_1[0x1f].OwningThread,auStack_40,local_44,local_48);
    if (local_48[0] != '\0') {
      FUN_c05b1828(param_1);
    }
  }
  else {
LAB_c05ac9e0:
    FUN_c05ac83c((int)param_1,&param_1[0x1f].OwningThread);
  }
  FUN_c05ac7b0((int)param_1);
  FUN_c05ac7f4((int)param_1);
LAB_c05ac9fc:
  FUN_c05b180c(param_1);
  FUN_c05b4904(local_20);
  return;
}



/* c05aca28 FUN_c05aca28 */

/* Boundary evidence: original MIPS .pdata c05aca28..c05acaeb. Semantic name remains unreviewed. */

void FUN_c05aca28(LPCRITICAL_SECTION param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_c05b17f0(param_1);
    if ((param_1[0x20].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) &&
       (iVar2 = memcmp(&param_1[0x1f].OwningThread,(void *)(param_2 + 6),6), iVar2 == 0)) {
      FUN_c05b180c(param_1);
      (*DAT_c05b64dc)(param_1[0x20].DebugInfo,param_2 + 0xe,param_3 + -0xe);
      FUN_c05b17f0(param_1);
    }
    FUN_c05b180c(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return;
}



/* c05acaec FUN_c05acaec */

/* Boundary evidence: original MIPS .pdata c05acaec..c05acb47. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c05acaec(LPCRITICAL_SECTION param_1,uint param_2)

{
  FUN_c05ac7b0((int)param_1);
  FUN_c05b4248(&param_1[0x20].LockCount);
  FUN_c05b19b8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c05acb48 FUN_c05acb48 */

/* Boundary evidence: original MIPS .pdata c05acb48..c05acb67. Semantic name remains unreviewed. */

void FUN_c05acb48(void)

{
  FUN_c05b42f0(&DAT_c05b63ac);
  return;
}



/* c05acb68 FUN_c05acb68 */

/* Boundary evidence: original MIPS .pdata c05acb68..c05acba7. Semantic name remains unreviewed. */

void FUN_c05acb68(LPCRITICAL_SECTION param_1)

{
  if (param_1 != (LPCRITICAL_SECTION)0x0) {
    FUN_c05b20a8(param_1);
    FUN_c05b4500(&DAT_c05b63ac,(int)param_1);
  }
  return;
}



/* c05acba8 FUN_c05acba8 */

/* Boundary evidence: original MIPS .pdata c05acba8..c05acbe3. Semantic name remains unreviewed. */

void FUN_c05acba8(int param_1,undefined4 *param_2,undefined4 param_3,STRSAFE_LPCWSTR param_4)

{
  int iVar1;
  
  iVar1 = FUN_c05b1728(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    FUN_c05b3e88(param_1 + 0x304,0x1f);
  }
  return;
}



/* c05acbe4 FUN_c05acbe4 */

/* Boundary evidence: original MIPS .pdata c05acbe4..c05acbff. Semantic name remains unreviewed. */

void FUN_c05acbe4(LPCRITICAL_SECTION param_1,int param_2,int param_3)

{
  FUN_c05aca28(param_1,param_2,param_3);
  return;
}



/* c05acc00 FUN_c05acc00 */

void FUN_c05acc00(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x314) = param_2;
  *(undefined4 *)(param_1 + 0x318) = param_3;
  return;
}



/* c05acc0c FUN_c05acc0c */

/* Boundary evidence: original MIPS .pdata c05acc0c..c05acc9b. Semantic name remains unreviewed. */

void FUN_c05acc0c(LPCRITICAL_SECTION param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_c05ac89c(param_1,param_2,param_3,param_4,param_5);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return;
}



/* c05acc9c FUN_c05acc9c */

/* Boundary evidence: original MIPS .pdata c05acc9c..c05acd8f. Semantic name remains unreviewed. */

void FUN_c05acc9c(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((*(char *)(param_1 + 0x2ec) != '\0') && ((*(uint *)(param_1 + 0x290) & 4) != 0)) {
    iVar2 = (*DAT_c05b6520)(param_1,0,0x5dc,0xe,FUN_c05acc0c,0,0,0,2);
    *(int *)(param_1 + 0x300) = iVar2;
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 0x2ed) = 1;
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x2f0) * 0xc + *(int *)(param_1 + 0x220));
      *(undefined4 *)(param_1 + 0x2f4) = *puVar3;
      uVar1 = *(undefined2 *)(puVar3 + 1);
      *(char *)(param_1 + 0x2f8) = (char)uVar1;
      *(char *)(param_1 + 0x2f9) = (char)((ushort)uVar1 >> 8);
      (*DAT_c05b6494)(*(undefined4 *)(param_1 + 0x300),0);
      (*DAT_c05b64e4)(*(undefined4 *)(param_1 + 0x300));
      (*DAT_c05b6498)(*(undefined4 *)(param_1 + 0x300),*(undefined4 *)(param_1 + 0x2e8));
    }
  }
  return;
}



/* c05acd90 FUN_c05acd90 */

/* Boundary evidence: original MIPS .pdata c05acd90..c05ace0b. Semantic name remains unreviewed. */

void FUN_c05acd90(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x2f0) = 0;
  iVar1 = FUN_c05ac6c8(param_1);
  if (iVar1 != 0) {
    if (*(char *)(param_1 + 0x2ed) != '\0') {
      iVar1 = memcmp((void *)(param_1 + 0x2f4),
                     (void *)(*(int *)(param_1 + 0x220) + *(int *)(param_1 + 0x2f0) * 0xc),6);
      if (iVar1 == 0) {
        return;
      }
      FUN_c05ac7b0(param_1);
    }
    FUN_c05acc9c(param_1);
  }
  return;
}



/* c05ace0c FUN_c05ace0c */

/* Boundary evidence: original MIPS .pdata c05ace0c..c05acec7. Semantic name remains unreviewed. */

int FUN_c05ace0c(LPCRITICAL_SECTION param_1,HANDLE param_2,void *param_3,undefined1 *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  iVar2 = 0x57;
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = FUN_c05b1ef8(param_1,param_2,param_3,param_4);
    if (iVar2 == 0) {
      FUN_c05b17f0(param_1);
      FUN_c05acd90((int)param_1);
      FUN_c05b180c(param_1);
    }
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return iVar2;
}



/* c05acec8 FUN_c05acec8 */

/* Boundary evidence: original MIPS .pdata c05acec8..c05acfbb. Semantic name remains unreviewed. */

void FUN_c05acec8(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 *_Buf1;
  
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_c05b17f0(param_1);
    _Buf1 = (undefined4 *)((int)&param_1[0x1f].LockSemaphore + 2);
    iVar2 = memcmp(_Buf1,param_2,6);
    if (iVar2 != 0) {
      FUN_c05b4194(&param_1[0x20].LockCount);
      *_Buf1 = *param_2;
      *(undefined2 *)((int)&param_1[0x1f].SpinCount + 2) = *(undefined2 *)(param_2 + 1);
      if ((*(char *)((int)&param_1[0x1f].LockCount + 1) != '\0') &&
         (iVar2 = memcmp(param_2,&param_1[0x1f].OwningThread,6), iVar2 == 0)) {
        FUN_c05ac7b0((int)param_1);
        FUN_c05acd90((int)param_1);
      }
    }
    FUN_c05b180c(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return;
}



/* c05acfbc FUN_c05acfbc */

/* Boundary evidence: original MIPS .pdata c05acfbc..c05ad083. Semantic name remains unreviewed. */

void FUN_c05acfbc(LPCRITICAL_SECTION param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_c05b17f0(param_1);
    if (param_2 == 0) {
      param_1[0x1b].RecursionCount = param_1[0x1b].RecursionCount & 0xfffffffb;
    }
    else {
      param_1[0x1b].RecursionCount = param_1[0x1b].RecursionCount | 4;
    }
    if ((char)param_1[0x1f].LockCount != '\0') {
      if (param_2 == 0) {
        FUN_c05ac7b0((int)param_1);
      }
      else {
        FUN_c05acd90((int)param_1);
      }
    }
    FUN_c05b180c(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return;
}



/* c05ad084 FUN_c05ad084 */

/* Boundary evidence: original MIPS .pdata c05ad084..c05ad11f. Semantic name remains unreviewed. */

void FUN_c05ad084(LPCRITICAL_SECTION param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_c05b17f0(param_1);
    uVar2 = param_1[0x1b].RecursionCount;
    *(char *)&param_1[0x1f].LockCount = (char)param_2;
    if ((uVar2 & 4) != 0) {
      if (param_2 == 0) {
        FUN_c05ac7b0((int)param_1);
      }
      else {
        FUN_c05acd90((int)param_1);
      }
    }
    FUN_c05b180c(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return;
}



/* c05ad120 FUN_c05ad120 */

/* Boundary evidence: original MIPS .pdata c05ad120..c05ad19b. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c05ad120(LPCRITICAL_SECTION param_1)

{
  FUN_c05b23c0(param_1);
  FUN_c05b4228(&param_1[0x20].LockCount);
  param_1[0x20].LockCount = (LONG)&PTR_LAB_c05a1798;
  *(undefined1 *)&param_1[0x1f].LockCount = 0;
  *(undefined1 *)((int)&param_1[0x1f].LockCount + 1) = 0;
  param_1[0x1f].RecursionCount = 0;
  memset(&param_1[0x1f].OwningThread,0,6);
  memset((void *)((int)&param_1[0x1f].LockSemaphore + 2),0,6);
  param_1[0x20].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  return param_1;
}



/* c05ad19c FUN_c05ad19c */

/* Boundary evidence: original MIPS .pdata c05ad19c..c05ad1d3. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c05ad19c(void)

{
  LPCRITICAL_SECTION p_Var1;
  
  p_Var1 = operator_new(0x31c);
  if (p_Var1 == (LPCRITICAL_SECTION)0x0) {
    p_Var1 = (LPCRITICAL_SECTION)0x0;
  }
  else {
    p_Var1 = FUN_c05ad120(p_Var1);
  }
  return p_Var1;
}



/* c05ad1d4 FUN_c05ad1d4 */

/* Boundary evidence: original MIPS .pdata c05ad1d4..c05ad1fb. Semantic name remains unreviewed. */

void FUN_c05ad1d4(undefined4 param_1,LPCRITICAL_SECTION param_2)

{
  if (param_2 != (LPCRITICAL_SECTION)0x0) {
    FUN_c05acaec(param_2,1);
  }
  return;
}



/* c05ad1fc FUN_c05ad1fc */

/* Boundary evidence: original MIPS .pdata c05ad1fc..c05ad217. Semantic name remains unreviewed. */

void FUN_c05ad1fc(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  FUN_c05acec8(param_1,param_2);
  return;
}



/* c05ad218 FUN_c05ad218 */

/* Boundary evidence: original MIPS .pdata c05ad218..c05ad247. Semantic name remains unreviewed. */

void FUN_c05ad218(LPCRITICAL_SECTION param_1,HANDLE param_2,void *param_3,uint *param_4)

{
  byte local_10 [8];
  
  FUN_c05ace0c(param_1,param_2,param_3,local_10);
  *param_4 = (uint)local_10[0];
  return;
}



/* c05ad248 FUN_c05ad248 */

/* Boundary evidence: original MIPS .pdata c05ad248..c05ad277. Semantic name remains unreviewed. */

void FUN_c05ad248(LPCRITICAL_SECTION param_1,int param_2)

{
  FUN_c05acfbc(param_1,(uint)(param_2 != 0));
  return;
}



/* c05ad278 FUN_c05ad278 */

/* Boundary evidence: original MIPS .pdata c05ad278..c05ad2a7. Semantic name remains unreviewed. */

void FUN_c05ad278(LPCRITICAL_SECTION param_1,int param_2)

{
  FUN_c05ad084(param_1,(uint)(param_2 != 0));
  return;
}



/* c05ad2a8 FUN_c05ad2a8 */

/* Boundary evidence: original MIPS .pdata c05ad2a8..c05ad393. Semantic name remains unreviewed. */

undefined4 FUN_c05ad2a8(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6400);
  if (DAT_c05b63e0 < 4) {
    piVar1 = &DAT_c05b63d0;
    iVar2 = 0;
    do {
      if (param_2 == 0) {
        if (*piVar1 == param_1) {
          DAT_c05b63e0 = DAT_c05b63e0 - 1;
          (&DAT_c05b63d0)[iVar2] = 0;
          goto LAB_c05ad368;
        }
      }
      else if (*piVar1 == 0) {
        DAT_c05b63e0 = DAT_c05b63e0 + 1;
        (&DAT_c05b63d0)[iVar2] = param_1;
LAB_c05ad368:
        uVar3 = 1;
        break;
      }
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + 1;
    } while ((int)piVar1 < -0x3fa49c20);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6400);
  return uVar3;
}



/* c05ad394 FUN_c05ad394 */

/* Boundary evidence: original MIPS .pdata c05ad394..c05ad437. Semantic name remains unreviewed. */

undefined4 FUN_c05ad394(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6400);
  if (DAT_c05b63e0 < 4) {
    piVar1 = &DAT_c05b63d0;
    do {
      if (*piVar1 == param_1) {
        uVar2 = 1;
        InterlockedIncrement((LONG *)(param_1 + 0x234));
        break;
      }
      piVar1 = piVar1 + 1;
    } while ((int)piVar1 < -0x3fa49c20);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6400);
  return uVar2;
}



/* c05ad438 FUN_c05ad438 */

/* Boundary evidence: original MIPS .pdata c05ad438..c05ad4ff. Semantic name remains unreviewed. */

void FUN_c05ad438(wchar_t *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x11a));
  if (LVar1 == 0) {
    if (((*(int *)(param_1 + 0x10e) != 0) && (DAT_c05b6530 != (code *)0x0)) &&
       (*(int *)(param_1 + 0x110) != 0)) {
      (*DAT_c05b6530)();
      param_1[0x110] = L'\0';
      param_1[0x111] = L'\0';
    }
    if (*(int *)(param_1 + 0x80) != 0) {
      if (*(int *)(param_1 + 0x120) == 1) {
        FUN_c05b3dac(param_1);
      }
      param_1[0x80] = L'\0';
      param_1[0x81] = L'\0';
    }
    if (*(int *)(param_1 + 0x10e) != 0) {
      FUN_c05a3fe0();
    }
    if (*(int *)(param_1 + 0x116) != 0) {
      FUN_c05a4c38(*(int *)(param_1 + 0x116));
      FUN_c05a63ec(*(HLOCAL *)(param_1 + 0x116));
    }
    LocalFree(param_1);
  }
  return;
}



/* c05ad500 FUN_c05ad500 */

char * FUN_c05ad500(int param_1)

{
  char *pcVar1;
  
  if (param_1 == 0x1010102) {
    pcVar1 = "802_3_CURRENT_ADDRESS";
  }
  else if (param_1 == 0xd010101) {
    pcVar1 = "802_11_BSSID";
  }
  else if (param_1 == 0xd010102) {
    pcVar1 = "OID_802_11_SSID";
  }
  else if (param_1 == 0xd010113) {
    pcVar1 = "802_11_ADD_WEP";
  }
  else if (param_1 == 0xd01011d) {
    pcVar1 = "802_11_ADD_KEY";
  }
  else if (param_1 == 0xd01011f) {
    pcVar1 = "802_11_ASSOCIATION_INFORMATION";
  }
  else {
    pcVar1 = "???";
  }
  return pcVar1;
}



/* c05ad5b0 FUN_c05ad5b0 */

/* Boundary evidence: original MIPS .pdata c05ad5b0..c05ad6af. Semantic name remains unreviewed. */

BOOL FUN_c05ad5b0(HANDLE param_1,int *param_2,DWORD param_3)

{
  char *pcVar1;
  BOOL BVar2;
  DWORD aDStack_28 [2];
  
  pcVar1 = FUN_c05ad500(*param_2);
  if ((DAT_c05b61e4 & 1) != 0) {
    CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30001,"Query OID %hs",pcVar1);
  }
  BVar2 = DeviceIoControl(param_1,0x120804,param_2,param_3,param_2,param_3,aDStack_28,
                          (LPOVERLAPPED)0x0);
  if ((DAT_c05b61e4 & 2) != 0) {
    CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30002,"Done Query OID %hs",pcVar1);
  }
  return BVar2;
}



/* c05ad6b0 FUN_c05ad6b0 */

/* Boundary evidence: original MIPS .pdata c05ad6b0..c05ad7ab. Semantic name remains unreviewed. */

BOOL FUN_c05ad6b0(HANDLE param_1,int *param_2,DWORD param_3)

{
  char *pcVar1;
  BOOL BVar2;
  
  pcVar1 = FUN_c05ad500(*param_2);
  if ((DAT_c05b61e4 & 1) != 0) {
    CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30001,"Set OID %hs",pcVar1);
  }
  BVar2 = DeviceIoControl(param_1,0x120814,param_2,param_3,(LPVOID)0x0,0,(LPDWORD)0x0,
                          (LPOVERLAPPED)0x0);
  if ((DAT_c05b61e4 & 2) != 0) {
    CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30002,"Done Set OID %hs",pcVar1);
  }
  return BVar2;
}



/* c05ad7ac FUN_c05ad7ac */

/* Boundary evidence: original MIPS .pdata c05ad7ac..c05ad8db. Semantic name remains unreviewed. */

uint FUN_c05ad7ac(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  uint local_14;
  
  local_14 = DAT_c05b62e4;
  if (*(int *)(param_1 + 0x240) == 1) {
    local_28 = 0x1010102;
    local_24 = param_1;
    uVar1 = FUN_c05ad5b0(*(HANDLE *)(param_1 + 0x100),&local_28,0x12);
    uVar1 = uVar1 & 0xff;
    if (uVar1 != 0) {
      *param_2 = local_20;
      *(undefined1 *)(param_2 + 1) = local_1c;
      *(undefined1 *)((int)param_2 + 5) = local_1b;
      if ((DAT_c05b61e4 & 4) != 0) {
        CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30004,"%hs=%02X%02X%02X%02X%02X%02X","IFMAC",
                 *(undefined1 *)param_2,*(undefined1 *)((int)param_2 + 1),
                 *(undefined1 *)((int)param_2 + 2),*(undefined1 *)((int)param_2 + 3),local_1c,
                 local_1b);
      }
    }
  }
  else {
    uVar1 = 0;
  }
  FUN_c05b4904(local_14);
  return uVar1;
}



/* c05ad8dc FUN_c05ad8dc */

/* Boundary evidence: original MIPS .pdata c05ad8dc..c05ada0b. Semantic name remains unreviewed. */

uint FUN_c05ad8dc(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  uint local_14;
  
  local_14 = DAT_c05b62e4;
  if (*(int *)(param_1 + 0x240) == 1) {
    local_28 = 0xd010101;
    local_24 = param_1;
    uVar1 = FUN_c05ad5b0(*(HANDLE *)(param_1 + 0x100),&local_28,0x12);
    uVar1 = uVar1 & 0xff;
    if (uVar1 != 0) {
      *param_2 = local_20;
      *(undefined1 *)(param_2 + 1) = local_1c;
      *(undefined1 *)((int)param_2 + 5) = local_1b;
      if ((DAT_c05b61e4 & 4) != 0) {
        CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30004,"%hs=%02X%02X%02X%02X%02X%02X","APBSSID",
                 *(undefined1 *)param_2,*(undefined1 *)((int)param_2 + 1),
                 *(undefined1 *)((int)param_2 + 2),*(undefined1 *)((int)param_2 + 3),local_1c,
                 local_1b);
      }
    }
  }
  else {
    uVar1 = 0;
  }
  FUN_c05b4904(local_14);
  return uVar1;
}



/* c05ada0c FUN_c05ada0c */

/* Boundary evidence: original MIPS .pdata c05ada0c..c05ada8b. Semantic name remains unreviewed. */

undefined4 FUN_c05ada0c(int param_1)

{
  uint uVar1;
  LPCRITICAL_SECTION p_Var2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x114) == 0) {
    uVar1 = FUN_c05ad8dc(param_1,(undefined4 *)(param_1 + 0x104));
    if (uVar1 == 0) {
      uVar3 = 0x80004005;
    }
    else {
      p_Var2 = *(LPCRITICAL_SECTION *)(*(int *)(param_1 + 0x22c) + 0x70);
      *(undefined4 *)(param_1 + 0x114) = 1;
      if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
        FUN_c05ad1fc(p_Var2,(undefined4 *)(param_1 + 0x104));
      }
    }
  }
  return uVar3;
}



/* c05ada8c FUN_c05ada8c */

/* Boundary evidence: original MIPS .pdata c05ada8c..c05adb4b. Semantic name remains unreviewed. */

DWORD FUN_c05ada8c(int param_1,int param_2,int param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD aDStack_20 [2];
  
  DVar1 = FUN_c05ada0c(param_1);
  if (DVar1 == 0) {
    memcpy((void *)(param_2 + -0xe),(void *)(param_1 + 0x104),0xe);
    if (*(int *)(param_1 + 0x240) == 1) {
      BVar2 = WriteFile(*(HANDLE *)(param_1 + 0x100),(void *)(param_2 + -0xe),param_3 + 0xe,
                        aDStack_20,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        DVar1 = GetLastError();
      }
    }
    else {
      DVar1 = 0x80004005;
    }
  }
  return DVar1;
}



/* c05adb4c FUN_c05adb4c */

/* Boundary evidence: original MIPS .pdata c05adb4c..c05adb83. Semantic name remains unreviewed. */

void FUN_c05adb4c(int param_1,LPCVOID param_2,DWORD param_3)

{
  DWORD aDStack_10 [2];
  
  if (*(int *)(param_1 + 0x150) != 0) {
    WriteFile(*(HANDLE *)(*(int *)(param_1 + 0x150) + 0x100),param_2,param_3,aDStack_10,
              (LPOVERLAPPED)0x0);
  }
  return;
}



/* c05adb84 FUN_c05adb84 */

/* Boundary evidence: original MIPS .pdata c05adb84..c05adc47. Semantic name remains unreviewed. */

void FUN_c05adb84(wchar_t *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  
  iVar1 = FUN_c05ad394((int)param_1);
  if (iVar1 != 0) {
    if (param_2 != 0) {
      FUN_c05ada8c((int)param_1,param_2,param_3);
    }
    if (param_4 != 0) {
      (**(code **)(param_1 + 0x114))(*(undefined4 *)(param_1 + 0x116),param_4,param_5);
      iVar1 = *(int *)(param_1 + 0x116);
      p_Var2 = *(LPCRITICAL_SECTION *)(iVar1 + 0x70);
      if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
        FUN_c05ad278(p_Var2,(uint)(param_4 == 2));
        FUN_c05b1a74(*(int *)(iVar1 + 0x70),(undefined4 *)(param_1 + 0x82));
      }
    }
    FUN_c05ad438(param_1);
  }
  return;
}



/* c05adc48 FUN_c05adc48 */

/* Boundary evidence: original MIPS .pdata c05adc48..c05adddb. Semantic name remains unreviewed. */

DWORD FUN_c05adc48(wchar_t *param_1,void *param_2,uint param_3,uint param_4)

{
  int iVar1;
  int *hMem;
  DWORD DVar2;
  uint uVar3;
  
  DVar2 = 0;
  uVar3 = (param_4 & 0xff80) << 0x18 | param_4 & 0x7f;
  iVar1 = FUN_c05ad394((int)param_1);
  if (iVar1 == 0) {
    DVar2 = 0xa0;
  }
  else {
    if (*(int *)(param_1 + 0x120) == 1) {
      if (param_3 < 0x101) {
        hMem = LocalAlloc(0x40,0x11c);
        if (hMem == (int *)0x0) {
          DVar2 = 0xe;
        }
        else {
          *hMem = 0xd010113;
          hMem[2] = param_3 + 0xc;
          hMem[3] = uVar3;
          if ((DAT_c05b61e4 & 4) != 0) {
            CxLogMsg(DAT_c05b61e8 << 0x18 | 0x30004,"Set KeyIndex=0x%X KeyLength=%u",uVar3);
          }
          hMem[4] = param_3;
          memcpy(hMem + 5,param_2,param_3);
          uVar3 = FUN_c05ad6b0(*(HANDLE *)(param_1 + 0x80),hMem,hMem[2] + 0xc);
          if ((uVar3 & 0xff) == 0) {
            DVar2 = GetLastError();
          }
          LocalFree(hMem);
        }
      }
      else {
        DVar2 = 0xa0;
      }
    }
    else {
      DVar2 = 0x32;
    }
    FUN_c05ad438(param_1);
  }
  return DVar2;
}



/* c05adddc FUN_c05adddc */

/* Boundary evidence: original MIPS .pdata c05adddc..c05adecf. Semantic name remains unreviewed. */

undefined4 FUN_c05adddc(int param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int *hMem;
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  
  hMem = LocalAlloc(0x40,0xfd4);
  if (hMem == (int *)0x0) {
    uVar3 = 0xe;
  }
  else {
    hMem[1] = param_1;
    *hMem = 0xd01011f;
    BVar1 = FUN_c05ad5b0(*(HANDLE *)(param_1 + 0x100),hMem,0xfd4);
    if (BVar1 == 0) {
      uVar3 = 0x57;
    }
    else {
      iVar2 = FUN_c05aa32c((byte *)((int)hMem + hMem[7] + 8),hMem[6],0x30,(void *)0x0,param_3);
      if (iVar2 == 0) {
        *param_4 = *(byte *)(*param_3 + 1) + 2;
        uVar3 = 0;
        goto LAB_c05adea8;
      }
      uVar3 = 0xd;
    }
  }
  LocalFree(hMem);
  hMem = (int *)0x0;
LAB_c05adea8:
  *param_2 = hMem;
  return uVar3;
}



/* c05aded0 FUN_c05aded0 */

/* Boundary evidence: original MIPS .pdata c05aded0..c05adff3. Semantic name remains unreviewed. */

DWORD FUN_c05aded0(wchar_t *param_1,int param_2,void *param_3,uint param_4)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  int *hMem;
  uint uBytes;
  
  DVar3 = 0;
  hMem = (int *)0x0;
  iVar1 = FUN_c05ad394((int)param_1);
  if (iVar1 == 0) {
    DVar3 = 0xa0;
  }
  else {
    if (*(int *)(param_1 + 0x120) == 1) {
      uBytes = param_4 + 0xc;
      if (uBytes < param_4) {
        DVar3 = 0xa0;
      }
      else {
        hMem = LocalAlloc(0x40,uBytes);
        if (hMem == (int *)0x0) {
          DVar3 = 0xe;
        }
        else {
          *hMem = param_2;
          memcpy(hMem + 2,param_3,param_4);
          BVar2 = FUN_c05ad6b0(*(HANDLE *)(param_1 + 0x80),hMem,uBytes);
          if (BVar2 == 0) {
            DVar3 = GetLastError();
          }
        }
      }
      LocalFree(hMem);
    }
    else {
      DVar3 = 0x32;
    }
    FUN_c05ad438(param_1);
  }
  return DVar3;
}



/* c05adff4 FUN_c05adff4 */

/* Boundary evidence: original MIPS .pdata c05adff4..c05ae16f. Semantic name remains unreviewed. */

DWORD FUN_c05adff4(wchar_t *param_1,undefined4 param_2,void *param_3,uint *param_4,
                  undefined4 *param_5)

{
  int iVar1;
  undefined4 *lpInBuffer;
  BOOL BVar2;
  DWORD DVar3;
  uint uBytes;
  uint local_28 [2];
  
  DVar3 = 0;
  iVar1 = FUN_c05ad394((int)param_1);
  if (iVar1 == 0) {
    DVar3 = 0xa0;
  }
  else {
    if (*(int *)(param_1 + 0x120) == 1) {
      *param_5 = 0;
      uBytes = *param_4 + 0xc;
      if (uBytes < *param_4) {
        DVar3 = 0xa0;
      }
      else {
        lpInBuffer = LocalAlloc(0x40,uBytes);
        if (lpInBuffer == (undefined4 *)0x0) {
          DVar3 = 0xe;
        }
        else {
          *lpInBuffer = param_2;
          BVar2 = DeviceIoControl(*(HANDLE *)(param_1 + 0x80),0x120804,lpInBuffer,uBytes,lpInBuffer,
                                  uBytes,local_28,(LPOVERLAPPED)0x0);
          if (BVar2 == 0) {
            DVar3 = GetLastError();
          }
          else if (*param_4 < local_28[0]) {
            DVar3 = 0x57;
          }
          else {
            memcpy(param_3,lpInBuffer + 2,local_28[0]);
            *param_4 = local_28[0];
          }
        }
        if (lpInBuffer != (undefined4 *)0x0) {
          LocalFree(lpInBuffer);
        }
      }
    }
    else {
      DVar3 = 0x32;
    }
    FUN_c05ad438(param_1);
  }
  return DVar3;
}



/* c05ae170 FUN_c05ae170 */

/* Boundary evidence: original MIPS .pdata c05ae170..c05ae203. Semantic name remains unreviewed. */

undefined1 FUN_c05ae170(wchar_t *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  
  iVar1 = FUN_c05ad394((int)param_1);
  if (iVar1 == 0) {
    uVar3 = 0xa0;
  }
  else {
    uVar2 = FUN_c05ad7ac((int)param_1,param_2);
    if (uVar2 == 0) {
      FUN_c05ad438(param_1);
      uVar3 = 0;
    }
    else {
      uVar2 = FUN_c05ad8dc((int)param_1,param_3);
      uVar3 = uVar2 != 0;
      FUN_c05ad438(param_1);
    }
  }
  return uVar3;
}



/* c05ae204 FUN_c05ae204 */

/* Boundary evidence: original MIPS .pdata c05ae204..c05ae223. Semantic name remains unreviewed. */

void FUN_c05ae204(int param_1,uint param_2,int *param_3)

{
  FUN_c05aa994(param_1,param_2,0,param_3);
  return;
}



/* c05ae224 FUN_c05ae224 */

/* Boundary evidence: original MIPS .pdata c05ae224..c05ae23f. Semantic name remains unreviewed. */

void FUN_c05ae224(int *param_1,uint param_2,int param_3)

{
  FUN_c05aa444(param_1,param_2,param_3,(uint *)0x0);
  return;
}



/* c05ae240 FUN_c05ae240 */

/* Boundary evidence: original MIPS .pdata c05ae240..c05ae437. Semantic name remains unreviewed. */

DWORD FUN_c05ae240(wchar_t *param_1)

{
  uint uVar1;
  int iVar2;
  LPCRITICAL_SECTION p_Var3;
  uint uVar4;
  DWORD DVar5;
  int iVar6;
  uint local_a48 [2];
  int local_a40;
  wchar_t awStack_a3c [260];
  undefined4 local_834;
  undefined4 local_830;
  int local_828;
  undefined1 auStack_824 [6];
  undefined1 auStack_81e [6];
  undefined1 auStack_818 [2];
  undefined1 auStack_816 [2030];
  uint local_28;
  
  local_28 = DAT_c05b62e4;
  iVar6 = *(int *)(param_1 + 0x116);
  DVar5 = 0;
  iVar2 = ReadFile(*(HANDLE *)(param_1 + 0x80),&local_828,0x800,local_a48,(LPOVERLAPPED)0x0);
  uVar1 = local_a48[0];
  while (local_a48[0] = uVar1, iVar2 != 0) {
    if (*(int *)(param_1 + 0x11c) != 0) goto LAB_c05ae3e8;
    if (3 < uVar1) {
      if (local_828 == 0) {
        uVar4 = uVar1 - 4;
        local_a48[0] = uVar4;
        if (0xd < uVar4) {
          iVar2 = memcmp(auStack_818,&DAT_c05b62e0,2);
          if (iVar2 == 0) {
            if ((*(int *)(param_1 + 0x8a) != 0) &&
               (iVar2 = memcmp(auStack_81e,param_1 + 0x82,6), iVar2 != 0)) {
              param_1[0x8a] = L'\0';
              param_1[0x8b] = L'\0';
            }
            if (*(int *)(param_1 + 0x11e) != 0) {
              (*DAT_c05b64dc)(*(undefined4 *)(param_1 + 0x110),auStack_816,uVar1 - 0x12);
            }
          }
          else {
            p_Var3 = *(LPCRITICAL_SECTION *)(iVar6 + 0x70);
            if (p_Var3 != (LPCRITICAL_SECTION)0x0) {
              FUN_c05acbe4(p_Var3,(int)auStack_824,uVar4);
            }
          }
        }
      }
      else {
        if (local_828 == 1) {
          local_a40 = 4;
        }
        else {
          local_a40 = 8;
        }
        wcscpy(awStack_a3c,*(wchar_t **)(iVar6 + 0x34));
        local_834 = 0;
        local_830 = 0;
        FUN_c05a8aa8(&local_a40);
      }
    }
    iVar2 = ReadFile(*(HANDLE *)(param_1 + 0x80),&local_828,0x800,local_a48,(LPOVERLAPPED)0x0);
    uVar1 = local_a48[0];
  }
  DVar5 = GetLastError();
LAB_c05ae3e8:
  CloseHandle(*(HANDLE *)(param_1 + 0x112));
  param_1[0x112] = L'\0';
  param_1[0x113] = L'\0';
  FUN_c05ad438(param_1);
  FUN_c05b4904(local_28);
  return DVar5;
}



/* c05ae438 FUN_c05ae438 */

/* Boundary evidence: original MIPS .pdata c05ae438..c05ae4e3. Semantic name remains unreviewed. */

void FUN_c05ae438(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  int local_18;
  int local_14;
  HLOCAL local_10 [2];
  
  p_Var2 = *(LPCRITICAL_SECTION *)(*(int *)(param_1 + 0x22c) + 0x70);
  if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
    FUN_c05ad278(p_Var2,0);
  }
  *(undefined4 *)(param_1 + 0x114) = 0;
  FUN_c05ada0c(param_1);
  (*DAT_c05b64e8)(*(undefined4 *)(param_1 + 0x220),param_1 + 0x104,param_1 + 0x10a);
  iVar1 = FUN_c05adddc(param_1,local_10,&local_14,&local_18);
  if (iVar1 == 0) {
    (*DAT_c05b6528)(*(undefined4 *)(param_1 + 0x220),local_14,local_18);
    LocalFree(local_10[0]);
  }
  (*DAT_c05b6498)(*(undefined4 *)(param_1 + 0x220),param_1 + 0x118);
  return;
}



/* c05ae4e4 FUN_c05ae4e4 */

/* Boundary evidence: original MIPS .pdata c05ae4e4..c05ae547. Semantic name remains unreviewed. */

void FUN_c05ae4e4(int param_1)

{
  LPCRITICAL_SECTION p_Var1;
  
  p_Var1 = *(LPCRITICAL_SECTION *)(*(int *)(param_1 + 0x22c) + 0x70);
  if (p_Var1 != (LPCRITICAL_SECTION)0x0) {
    FUN_c05ad278(p_Var1,0);
  }
  if ((*(int *)(param_1 + 0x21c) != 0) && (DAT_c05b652c != (code *)0x0)) {
    (*DAT_c05b652c)(*(undefined4 *)(param_1 + 0x220));
  }
  *(undefined4 *)(param_1 + 0x114) = 0;
  return;
}



/* c05ae548 FUN_c05ae548 */

/* Boundary evidence: original MIPS .pdata c05ae548..c05ae56b. Semantic name remains unreviewed. */

void FUN_c05ae548(int param_1)

{
  (*DAT_c05b6524)(*(undefined4 *)(param_1 + 0x220));
  return;
}



/* c05ae56c FUN_c05ae56c */

/* Boundary evidence: original MIPS .pdata c05ae56c..c05ae5ff. Semantic name remains unreviewed. */

void FUN_c05ae56c(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x23c) = 0;
    FUN_c05ae4e4(param_1);
    if (*(int *)(param_1 + 0x220) != 0) {
      iVar1 = *(int *)(param_1 + 0x22c);
      FUN_c05a8fbc(4,(void *)(iVar1 + 0x88),*(uint *)(iVar1 + 0x84),0,*(undefined4 *)(iVar1 + 0xd4),
                   *(wchar_t **)(iVar1 + 0x34),(undefined4 *)0x0);
      if ((*(int *)(param_1 + 0x21c) != 0) && (DAT_c05b6530 != (code *)0x0)) {
        (*DAT_c05b6530)(*(undefined4 *)(param_1 + 0x220));
      }
      *(undefined4 *)(param_1 + 0x220) = 0;
    }
  }
  return;
}



/* c05ae600 FUN_c05ae600 */

/* Boundary evidence: original MIPS .pdata c05ae600..c05ae71b. Semantic name remains unreviewed. */

DWORD FUN_c05ae600(wchar_t *param_1,SIZE_T param_2,SIZE_T *param_3,void *param_4,uint param_5)

{
  SIZE_T *hMem;
  DWORD DVar1;
  SIZE_T uBytes;
  
  hMem = (SIZE_T *)0x0;
  if (param_5 < 0x401) {
    uBytes = param_5 + 0x20;
    hMem = LocalAlloc(0x40,uBytes);
    if (hMem == (SIZE_T *)0x0) {
      DVar1 = 0xe;
    }
    else {
      *hMem = uBytes;
      hMem[1] = param_2;
      hMem[2] = param_5;
      hMem[3] = *(SIZE_T *)(param_1 + 0x82);
      *(wchar_t *)(hMem + 4) = param_1[0x84];
      if (param_3 != (SIZE_T *)0x0) {
        hMem[6] = *param_3;
        hMem[7] = param_3[1];
      }
      memcpy(hMem + 8,param_4,param_5);
      DVar1 = FUN_c05aded0(param_1,0xd01011d,hMem,uBytes);
    }
  }
  else {
    DVar1 = 0xd;
  }
  LocalFree(hMem);
  return DVar1;
}



/* c05ae71c FUN_c05ae71c */

/* Boundary evidence: original MIPS .pdata c05ae71c..c05aea6b. Semantic name remains unreviewed. */

undefined4 FUN_c05ae71c(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  uint *puVar4;
  size_t *psVar5;
  int iVar6;
  undefined4 uVar7;
  wchar_t *_Str1;
  uint local_1d8;
  code *local_1d4;
  code *local_1d0;
  code *local_1cc;
  code *local_1c8;
  code *local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  size_t local_1b8;
  undefined1 auStack_1b4 [32];
  undefined1 auStack_194 [36];
  undefined1 auStack_170 [18];
  undefined1 auStack_15e [34];
  uint local_13c;
  WCHAR aWStack_128 [130];
  uint local_24;
  
  local_24 = DAT_c05b62e4;
  uVar7 = 0;
  if (param_1 == 0) {
    uVar7 = 0x57;
    goto LAB_c05aea3c;
  }
  iVar6 = *(int *)(param_1 + 0x22c);
  if (*(int *)(iVar6 + 0xa8) == 1) goto LAB_c05aea3c;
  iVar2 = MultiByteToWideChar(1,0,(LPCSTR)(iVar6 + 0x88),*(int *)(iVar6 + 0x84),aWStack_128,0x80);
  _Str1 = (wchar_t *)(param_1 + 0x118);
  aWStack_128[iVar2] = L'\0';
  iVar2 = wcsncmp(_Str1,aWStack_128,0x81);
  wcscpy(_Str1,aWStack_128);
  if (*(LPCRITICAL_SECTION *)(iVar6 + 0x70) != (LPCRITICAL_SECTION)0x0) {
    FUN_c05b24a0(*(LPCRITICAL_SECTION *)(iVar6 + 0x70),_Str1);
  }
  local_1d8 = (uint)(DAT_c05b6360 != 0);
  local_1d4 = FUN_c05ae204;
  local_1d0 = FUN_c05ae224;
  local_1cc = FUN_c05aded0;
  local_1c8 = FUN_c05adff4;
  local_1c4 = FUN_c05ae170;
  local_1c0 = *(undefined4 *)(iVar6 + 0xa8);
  local_1bc = *(undefined4 *)(iVar6 + 0x108);
  *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(iVar6 + 0xa8);
  if ((iVar2 != 0) && (*(int *)(param_1 + 0x220) != 0)) {
    (*DAT_c05b6530)();
    *(undefined4 *)(param_1 + 0x220) = 0;
  }
  if (*(int *)(param_1 + 0x220) == 0) {
    iVar2 = (*DAT_c05b6520)(param_1,0,0x5dc,0xe,FUN_c05adb84,FUN_c05adc48,FUN_c05ae600,&local_1d8,0)
    ;
    *(int *)(param_1 + 0x220) = iVar2;
    if (iVar2 == 0) {
      uVar7 = 0xe;
      goto LAB_c05aea3c;
    }
    (*DAT_c05b64e4)(iVar2);
  }
  puVar4 = *(uint **)(iVar6 + 0x140);
  if (((puVar4 != (uint *)0x0) && (puVar4[1] < *puVar4)) &&
     (puVar4 = puVar4 + puVar4[1] * 0x31, puVar4 != (uint *)0xfffffff8)) {
    local_1b8 = 0;
    if ((puVar4[3] & 1) == 0) {
      if ((puVar4[0x27] == 6) && (*(int *)(iVar6 + 0x70) != 0)) {
        uVar3 = FUN_c05b1a2c(*(int *)(iVar6 + 0x70));
        if ((uVar3 & 1) != 0) {
          FUN_c05ad8dc(param_1,(undefined4 *)(param_1 + 0x104));
          bVar1 = FUN_c05b24d8(*(LPCRITICAL_SECTION *)(iVar6 + 0x70),(undefined4 *)(param_1 + 0x104)
                               ,auStack_170);
          if (CONCAT31(extraout_var,bVar1) != 0) {
            local_1b8 = local_13c;
            memcpy(auStack_1b4,auStack_15e,0x20);
            memset(auStack_194,0,0x20);
          }
        }
        goto LAB_c05ae9e0;
      }
    }
    else {
      FUN_c05a4aa8(*(DATA_BLOB **)(iVar6 + 0x148),&local_1b8);
LAB_c05ae9e0:
      if (local_1b8 != 0) {
        uVar7 = (*DAT_c05b64f4)(*(undefined4 *)(param_1 + 0x220),&local_1b8);
        if (*(LPCRITICAL_SECTION *)(iVar6 + 0x70) != (LPCRITICAL_SECTION)0x0) {
          FUN_c05b2468(*(LPCRITICAL_SECTION *)(iVar6 + 0x70),auStack_1b4,local_1b8);
        }
      }
    }
    iVar6 = 0x44;
    psVar5 = &local_1b8;
    do {
      *(undefined1 *)psVar5 = 0;
      iVar6 = iVar6 + -1;
      psVar5 = (size_t *)((int)psVar5 + 1);
    } while (iVar6 != 0);
  }
  FUN_c05ae438(param_1);
  *(undefined4 *)(param_1 + 0x23c) = 1;
LAB_c05aea3c:
  FUN_c05b4904(local_24);
  return uVar7;
}



/* c05aea6c FUN_c05aea6c */

/* Boundary evidence: original MIPS .pdata c05aea6c..c05aeb3b. Semantic name remains unreviewed. */

void FUN_c05aea6c(int param_1)

{
  int iVar1;
  HANDLE hHandle;
  DWORD aDStack_18 [2];
  
  if (param_1 != 0) {
    FUN_c05ae56c(param_1);
    if (*(int *)(param_1 + 0x240) == 1) {
      *(undefined4 *)(param_1 + 0x238) = 1;
      hHandle = *(HANDLE *)(param_1 + 0x224);
      DeviceIoControl(*(HANDLE *)(param_1 + 0x100),0x120828,(LPVOID)0x0,0,(LPVOID)0x0,0,aDStack_18,
                      (LPOVERLAPPED)0x0);
      if (hHandle != (HANDLE)0x0) {
        CeSetThreadPriority(hHandle,100);
        WaitForSingleObject(hHandle,1000);
      }
    }
    iVar1 = FUN_c05ad2a8(param_1,0);
    if (iVar1 != 0) {
      FUN_c05ad438((wchar_t *)param_1);
    }
  }
  return;
}



/* c05aeb3c FUN_c05aeb3c */

/* Boundary evidence: original MIPS .pdata c05aeb3c..c05aebab. Semantic name remains unreviewed. */

undefined4 FUN_c05aeb3c(int param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  DWORD aDStack_10 [2];
  
  uVar2 = 0;
  if (param_1 != 0) {
    BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x100),0x120808,&DAT_c05b62e0,4,(LPVOID)0x0,0,
                            aDStack_10,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      uVar2 = 0x80004005;
    }
  }
  return uVar2;
}



/* c05aebac FUN_c05aebac */

/* Boundary evidence: original MIPS .pdata c05aebac..c05aede7. Semantic name remains unreviewed. */

int FUN_c05aebac(int param_1,wchar_t *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined2 uVar1;
  wchar_t *_Dest;
  DWORD DVar2;
  uint uVar3;
  HANDLE pvVar4;
  int iVar5;
  wchar_t *lpAddend;
  undefined4 local_28;
  DWORD DStack_24;
  
  _Dest = LocalAlloc(0x40,600);
  if (_Dest == (wchar_t *)0x0) {
    iVar5 = 0xe;
  }
  else {
    memset(_Dest,0,600);
    lpAddend = _Dest + 0x11a;
    lpAddend[0] = L'\x01';
    lpAddend[1] = L'\0';
    wcscpy(_Dest,param_2);
    iVar5 = FUN_c05ad2a8((int)_Dest,1);
    if (iVar5 == 0) {
      iVar5 = 0x138e;
    }
    else {
      FUN_c05a4c10(param_1);
      *(int *)(_Dest + 0x116) = param_1;
      *(undefined4 *)(_Dest + 0x114) = param_3;
      iVar5 = FUN_c05a3efc();
      *(int *)(_Dest + 0x10e) = iVar5;
      if (iVar5 == 0) {
        iVar5 = 0x32;
      }
      else {
        iVar5 = *(int *)(param_1 + 0x5c);
        *(int *)(_Dest + 0x120) = iVar5;
        if (iVar5 == 1) {
          DVar2 = FUN_c05b3b44(param_2,(int *)(_Dest + 0x80));
          if (DVar2 == 0) {
            iVar5 = FUN_c05aeb3c((int)_Dest);
            if (iVar5 == 0) goto LAB_c05aecbc;
          }
          else {
            iVar5 = -0x7fffbffb;
          }
        }
        else {
          iVar5 = -0x7fffbffb;
LAB_c05aecbc:
          uVar3 = FUN_c05ad7ac((int)_Dest,(undefined4 *)(_Dest + 0x85));
          uVar1 = DAT_c05b62e0;
          if (uVar3 == 0) {
LAB_c05aecd0:
            iVar5 = -0x7fffbffb;
          }
          else {
            *(char *)(_Dest + 0x88) = (char)DAT_c05b62e0;
            *(char *)((int)_Dest + 0x111) = (char)((ushort)uVar1 >> 8);
            _Dest[0x11e] = L'\0';
            _Dest[0x11f] = L'\0';
            if (*(int *)(_Dest + 0x120) == 1) {
              InterlockedIncrement((LONG *)lpAddend);
              _Dest[0x11c] = L'\0';
              _Dest[0x11d] = L'\0';
              pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05ae240,_Dest,0,&DStack_24);
              *(HANDLE *)(_Dest + 0x112) = pvVar4;
              if (pvVar4 == (HANDLE)0x0) {
                GetLastError();
                FUN_c05ad438(_Dest);
                goto LAB_c05aecd0;
              }
              local_28 = 200;
              CxRegReadValues(0x80000002,L"Comm\\EAPOL",L"Priority256",4,0,&local_28,4,0);
              CeSetThreadPriority(*(undefined4 *)(_Dest + 0x112),local_28);
            }
            if (iVar5 == 0) goto LAB_c05aedb8;
          }
        }
      }
    }
  }
  FUN_c05aea6c((int)_Dest);
  _Dest = (wchar_t *)0x0;
LAB_c05aedb8:
  *param_4 = _Dest;
  return iVar5;
}



/* c05aede8 FUN_c05aede8 */

/* Boundary evidence: original MIPS .pdata c05aede8..c05aee37. Semantic name remains unreviewed. */

undefined4 FUN_c05aede8(void)

{
  undefined4 *puVar1;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6400);
  puVar1 = &DAT_c05b63d0;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != &DAT_c05b63e0);
  DAT_c05b63e0 = 0;
  return 1;
}



/* c05aee38 FUN_c05aee38 */

/* Boundary evidence: original MIPS .pdata c05aee38..c05aee63. Semantic name remains unreviewed. */

DWORD FUN_c05aee38(int param_1)

{
  DWORD DVar1;
  
  DVar1 = 0x32;
  if (*(int *)(param_1 + 0x5c) == 1) {
    DVar1 = FUN_c05aaf98(param_1);
  }
  return DVar1;
}



/* c05aee64 FUN_c05aee64 */

/* Boundary evidence: original MIPS .pdata c05aee64..c05aee8f. Semantic name remains unreviewed. */

DWORD FUN_c05aee64(int param_1)

{
  DWORD DVar1;
  
  DVar1 = 0x32;
  if (*(int *)(param_1 + 0x5c) == 1) {
    DVar1 = FUN_c05abbc0(param_1);
  }
  return DVar1;
}



/* c05aee90 FUN_c05aee90 */

/* Boundary evidence: original MIPS .pdata c05aee90..c05aeec3. Semantic name remains unreviewed. */

DWORD FUN_c05aee90(int param_1,int param_2,uint param_3,uint *param_4)

{
  DWORD DVar1;
  
  if (*(int *)(param_1 + 0x5c) == 1) {
    DVar1 = FUN_c05abc80(param_1,param_2,param_3,param_4);
  }
  else {
    DVar1 = 0x32;
  }
  return DVar1;
}



/* c05aeec4 FUN_c05aeec4 */

/* Boundary evidence: original MIPS .pdata c05aeec4..c05aeef7. Semantic name remains unreviewed. */

DWORD FUN_c05aeec4(int param_1,uint param_2,uint *param_3)

{
  DWORD DVar1;
  
  if (*(int *)(param_1 + 0x5c) == 1) {
    DVar1 = FUN_c05ac02c(param_1,param_2,param_3);
  }
  else {
    DVar1 = 0x32;
  }
  return DVar1;
}



/* c05aeef8 FUN_c05aeef8 */

/* Boundary evidence: original MIPS .pdata c05aeef8..c05aefd3. Semantic name remains unreviewed. */

DWORD FUN_c05aeef8(int param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  HANDLE local_88;
  DWORD DStack_84;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  
  DVar1 = FUN_c05aab38(&local_88);
  if (DVar1 == 0) {
    local_7c = *(undefined4 *)(param_1 + 0x34);
    BVar2 = DeviceIoControl(local_88,0x120824,(LPVOID)0x0,0,auStack_80,0x70,&DStack_84,
                            (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar1 = GetLastError();
    }
    else if (local_6c == 0) {
      DVar1 = 0x15;
    }
    else {
      *(undefined4 *)(param_1 + 0x54) = local_70;
      *(undefined4 *)(param_1 + 0x58) = local_74;
      *(int *)(param_1 + 0x5c) = local_6c;
    }
    CloseHandle(local_88);
  }
  return DVar1;
}



/* c05aefd4 FUN_c05aefd4 */

/* Boundary evidence: original MIPS .pdata c05aefd4..c05af007. Semantic name remains unreviewed. */

int FUN_c05aefd4(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x5c) == 1) {
    iVar1 = FUN_c05ac410(param_1);
  }
  else {
    iVar1 = 0x32;
  }
  return iVar1;
}



/* c05af008 FUN_c05af008 */

/* Boundary evidence: original MIPS .pdata c05af008..c05af0b3. Semantic name remains unreviewed. */

DWORD FUN_c05af008(HANDLE param_1,wchar_t *param_2,size_t *param_3)

{
  DWORD DVar1;
  undefined1 auStack_188 [52];
  wchar_t *local_154;
  int local_12c;
  uint local_20;
  
  local_20 = DAT_c05b62e4;
  memset(auStack_188,0,0x168);
  local_154 = param_2;
  DVar1 = FUN_c05aeef8((int)auStack_188);
  if (DVar1 == 0) {
    if (local_12c == 1) {
      DVar1 = FUN_c05aad64(param_1,param_2,param_3);
    }
    else {
      DVar1 = 0x10db;
    }
  }
  FUN_c05b4904(local_20);
  return DVar1;
}



/* c05af0b4 FUN_c05af0b4 */

/* Boundary evidence: original MIPS .pdata c05af0b4..c05af143. Semantic name remains unreviewed. */

undefined4 FUN_c05af0b4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x57;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    *param_1 = 1;
    param_1[6] = 0;
  }
  return uVar1;
}



/* c05af144 FUN_c05af144 */

/* Boundary evidence: original MIPS .pdata c05af144..c05af14f. Semantic name remains unreviewed. */

undefined4 FUN_c05af144(void)

{
  return 1;
}



/* c05af150 FUN_c05af150 */

/* Boundary evidence: original MIPS .pdata c05af150..c05af55b. Semantic name remains unreviewed. */

DWORD FUN_c05af150(wchar_t *param_1,wchar_t *param_2,undefined4 param_3,undefined4 *param_4)

{
  DWORD DVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  int iVar6;
  wchar_t *pwVar7;
  int iVar8;
  int iVar9;
  wchar_t *local_38;
  wchar_t *local_34;
  wchar_t *local_30;
  
  if (param_1 == (wchar_t *)0x0) {
    param_1 = FUN_c05a4228(0x1c);
    if (param_1 == (wchar_t *)0x0) {
LAB_c05af1a4:
      DVar1 = GetLastError();
      return DVar1;
    }
    sVar2 = wcslen(param_2);
    pwVar3 = FUN_c05a4228((sVar2 + 1) * 2);
    *(wchar_t **)(param_1 + 10) = pwVar3;
    if (pwVar3 == (wchar_t *)0x0) {
      DVar1 = GetLastError();
      pwVar7 = param_1;
LAB_c05af1f0:
      FUN_c05a42b0(pwVar7);
      return DVar1;
    }
    wcscpy(pwVar3,param_2);
    pwVar3 = param_1 + 2;
    pwVar7 = param_1 + 6;
    *(wchar_t **)(param_1 + 4) = pwVar3;
    *(wchar_t **)pwVar3 = pwVar3;
    *(wchar_t **)(param_1 + 8) = pwVar7;
    *(wchar_t **)pwVar7 = pwVar7;
  }
  else {
    pwVar3 = *(wchar_t **)(param_1 + 10);
    wVar4 = *param_2;
    iVar9 = 0;
    if (wVar4 != L'\0') {
      pwVar7 = pwVar3;
      do {
        if (wVar4 != *pwVar7) break;
        pwVar7 = pwVar7 + 1;
        wVar4 = *(wchar_t *)(((int)param_2 - (int)pwVar3) + (int)pwVar7);
        iVar9 = iVar9 + 1;
      } while (wVar4 != L'\0');
    }
    iVar8 = iVar9 * 2;
    local_30 = param_2 + iVar9;
    wVar4 = *local_30;
    if ((wVar4 != L'\0') || (pwVar3[iVar9] != L'\0')) {
      if (wVar4 == L'\0') {
        iVar6 = 1;
      }
      else {
        iVar6 = 3;
        if (pwVar3[iVar9] == L'\0') {
          iVar6 = 2;
          for (pwVar7 = *(wchar_t **)(param_1 + 6); pwVar7 != param_1 + 6;
              pwVar7 = *(wchar_t **)pwVar7) {
            local_34 = pwVar7 + -2;
            if (wVar4 == **(wchar_t **)(pwVar7 + 8)) {
              DVar1 = FUN_c05af150(local_34,local_30,param_3,param_4);
              if (DVar1 != 0) {
                return DVar1;
              }
              goto LAB_c05af528;
            }
          }
        }
      }
      local_38 = (wchar_t *)0x0;
      pwVar7 = (wchar_t *)0x0;
      if (iVar6 != 2) {
        sVar2 = wcslen(pwVar3);
        pwVar7 = FUN_c05a4228(((sVar2 - iVar9) + 1) * 2);
        if (pwVar7 == (wchar_t *)0x0) goto LAB_c05af1a4;
        wcsncpy(pwVar7,(wchar_t *)(*(int *)(param_1 + 10) + iVar8),sVar2 - iVar9);
        *(undefined2 *)(*(int *)(param_1 + 10) + iVar8) = 0;
        DVar1 = FUN_c05af150((wchar_t *)0x0,*(wchar_t **)(param_1 + 10),0,&local_38);
        *(wchar_t *)(*(int *)(param_1 + 10) + iVar8) = *pwVar7;
        if (DVar1 != 0) goto LAB_c05af1f0;
        *(undefined4 *)local_38 = *(undefined4 *)param_1;
      }
      if (iVar6 != 1) {
        DVar1 = FUN_c05af150((wchar_t *)0x0,local_30,param_3,&local_34);
        if (DVar1 != 0) {
          FUN_c05a42b0(pwVar7);
          if (local_38 == (wchar_t *)0x0) {
            return DVar1;
          }
          FUN_c05a42b0(*(HLOCAL *)(local_38 + 10));
          pwVar7 = local_38;
          goto LAB_c05af1f0;
        }
        pwVar3 = param_1;
        if (iVar6 != 2) {
          pwVar3 = local_38;
        }
        *(wchar_t **)local_34 = pwVar3;
      }
      if (iVar6 != 2) {
        FUN_c05a42b0(*(HLOCAL *)(param_1 + 10));
        pwVar5 = param_1 + 2;
        *(wchar_t **)(param_1 + 10) = pwVar7;
        *(wchar_t **)param_1 = local_38;
        pwVar3 = local_38 + 2;
        *(undefined4 *)pwVar3 = *(undefined4 *)pwVar5;
        *(wchar_t **)(local_38 + 4) = pwVar5;
        *(wchar_t **)(*(int *)pwVar5 + 4) = pwVar3;
        *(wchar_t **)pwVar5 = pwVar3;
        **(undefined4 **)(param_1 + 4) = *(undefined4 *)pwVar5;
        *(undefined4 *)(*(int *)pwVar5 + 4) = *(undefined4 *)(param_1 + 4);
        *(wchar_t **)(param_1 + 4) = pwVar5;
        pwVar3 = local_38 + 6;
        *(wchar_t **)pwVar5 = pwVar5;
        *(undefined4 *)pwVar5 = *(undefined4 *)pwVar3;
        *(wchar_t **)(param_1 + 4) = pwVar3;
        *(wchar_t **)(*(int *)pwVar3 + 4) = pwVar5;
        *(wchar_t **)pwVar3 = pwVar5;
      }
      if (iVar6 == 1) {
        *(undefined4 *)(local_38 + 0xc) = param_3;
      }
      else {
        if (iVar6 == 2) {
          pwVar3 = local_34 + 2;
          *(wchar_t **)pwVar3 = param_1 + 6;
          *(undefined4 *)(local_34 + 4) = *(undefined4 *)(param_1 + 8);
          **(undefined4 **)(param_1 + 8) = pwVar3;
          *(wchar_t **)(param_1 + 8) = pwVar3;
          goto LAB_c05af528;
        }
        pwVar3 = local_34 + 2;
        *(wchar_t **)pwVar3 = local_38 + 6;
        *(undefined4 *)(local_34 + 4) = *(undefined4 *)(local_38 + 8);
        **(undefined4 **)(local_38 + 8) = pwVar3;
        *(wchar_t **)(local_38 + 8) = pwVar3;
      }
      if (iVar6 != 2) {
        param_1 = local_38;
      }
      goto LAB_c05af528;
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      return 0x7de;
    }
  }
  *(undefined4 *)(param_1 + 0xc) = param_3;
LAB_c05af528:
  *param_4 = param_1;
  return 0;
}



/* c05af55c FUN_c05af55c */

/* Boundary evidence: original MIPS .pdata c05af55c..c05af64f. Semantic name remains unreviewed. */

undefined4 FUN_c05af55c(int param_1,wchar_t *param_2,int *param_3)

{
  int iVar1;
  size_t sVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  
  uVar5 = 2;
  if (param_2 == (wchar_t *)0x0) {
    uVar5 = 0x57;
  }
  else if (param_1 != 0) {
    iVar1 = _wcsicmp(param_2,*(wchar_t **)(param_1 + 0x14));
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x18) != 0) {
        if (param_3 != (int *)0x0) {
          *param_3 = param_1;
        }
        uVar5 = 0;
      }
    }
    else if (0 < iVar1) {
      sVar2 = wcslen(*(wchar_t **)(param_1 + 0x14));
      piVar4 = (int *)(param_1 + 0xc);
      piVar3 = (int *)*piVar4;
      if (piVar3 != piVar4) {
        do {
          if (param_2[sVar2] == *(wchar_t *)piVar3[4]) {
            uVar5 = FUN_c05af55c((int)(piVar3 + -1),param_2 + sVar2,param_3);
            return uVar5;
          }
          piVar3 = (int *)*piVar3;
        } while (piVar3 != piVar4);
      }
    }
  }
  return uVar5;
}



/* c05af650 FUN_c05af650 */

/* Boundary evidence: original MIPS .pdata c05af650..c05af7cb. Semantic name remains unreviewed. */

DWORD FUN_c05af650(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  size_t sVar1;
  size_t sVar2;
  wchar_t *_Dest;
  int *piVar3;
  int *piVar4;
  DWORD DVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  DVar5 = 0;
  piVar6 = (int *)0x0;
  if (param_2[6] == 0) {
    DVar5 = 2;
  }
  else {
    *param_3 = param_2[6];
    param_2[6] = 0;
    do {
      piVar7 = param_1;
      if (param_2[6] != 0) break;
      piVar3 = param_2 + 3;
      piVar4 = (int *)*piVar3;
      if ((int *)*piVar4 != piVar3) break;
      piVar8 = (int *)*param_2;
      if (piVar4 != piVar3) {
        piVar6 = piVar4 + -1;
        sVar1 = wcslen((wchar_t *)param_2[5]);
        sVar2 = wcslen((wchar_t *)piVar4[4]);
        _Dest = FUN_c05a4228((sVar2 + sVar1 + 1) * 2);
        if (_Dest == (wchar_t *)0x0) {
          DVar5 = GetLastError();
          return DVar5;
        }
        wcscpy(_Dest,(wchar_t *)param_2[5]);
        wcscat(_Dest,(wchar_t *)piVar4[4]);
        FUN_c05a42b0((HLOCAL)piVar4[4]);
        piVar4[4] = (int)_Dest;
        piVar7 = param_2 + 1;
        *piVar6 = *param_2;
        *piVar4 = *piVar7;
        piVar4[1] = (int)piVar7;
        *(int **)(*piVar7 + 4) = piVar4;
        *piVar7 = (int)piVar4;
      }
      *(int *)param_2[2] = param_2[1];
      *(int *)(param_2[1] + 4) = param_2[2];
      FUN_c05a42b0((HLOCAL)param_2[5]);
      FUN_c05a42b0(param_2);
      param_2 = piVar8;
      piVar7 = piVar6;
    } while (piVar8 != (int *)0x0);
    *param_4 = piVar7;
  }
  return DVar5;
}



/* c05af7cc FUN_c05af7cc */

/* Boundary evidence: original MIPS .pdata c05af7cc..c05af88f. Semantic name remains unreviewed. */

DWORD FUN_c05af7cc(int param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  if (*(LPVOID *)(param_1 + 0x2c) == (LPVOID)0xffffffff) {
    DVar2 = 0x57;
  }
  else {
    iVar1 = FUN_c05a9868(DAT_c05b6348,*(LPVOID *)(param_1 + 0x2c),param_2,0x70000000);
    if (iVar1 == 0) {
      DVar2 = GetLastError();
    }
    else if (param_2 == 0x70000000) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffeffff;
    }
    else {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x10000;
    }
  }
  return DVar2;
}



/* c05af890 FUN_c05af890 */

/* Boundary evidence: original MIPS .pdata c05af890..c05af8d3. Semantic name remains unreviewed. */

void FUN_c05af890(int param_1)

{
  FUN_c05aeec4(param_1,0x100000,(uint *)0x0);
  FUN_c05af7cc(param_1,DAT_c05b637c);
  return;
}



/* c05af8d4 FUN_c05af8d4 */

/* Boundary evidence: original MIPS .pdata c05af8d4..c05af9d7. Semantic name remains unreviewed. */

DWORD FUN_c05af8d4(int param_1)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  uVar3 = *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x20) = uVar3 & 0xfffdffff;
  if (((uVar3 & 7) == 0) ||
     ((((piVar6 = *(int **)(param_1 + 0x13c), iVar4 = DAT_c05b6370, piVar6 != (int *)0x0 &&
        (*piVar6 != 0)) && (piVar5 = *(int **)(param_1 + 0x140), *piVar5 != 0)) &&
      (iVar1 = FUN_c05a43a4((int)(piVar6 + 2),(int)(piVar5 + piVar5[1] * 0x31 + 2),(undefined4 *)0x0
                           ), iVar4 = DAT_c05b6370, iVar1 != 0)))) {
    iVar4 = 0x70000000;
  }
  DVar2 = FUN_c05af7cc(param_1,iVar4);
  iVar4 = *(int *)(*(int *)(param_1 + 0x140) + 4) * 0xc4 + *(int *)(param_1 + 0x140);
  FUN_c05a8fbc(0xe,(void *)(iVar4 + 0x1c),*(uint *)(iVar4 + 0x18),0,*(undefined4 *)(iVar4 + 0x68),
               *(wchar_t **)(param_1 + 0x34),(undefined4 *)0x0);
  return DVar2;
}



/* c05af9d8 FUN_c05af9d8 */

/* Boundary evidence: original MIPS .pdata c05af9d8..c05afc1b. Semantic name remains unreviewed. */

DWORD FUN_c05af9d8(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  uint uVar4;
  DWORD DVar5;
  int iVar6;
  undefined1 auStack_98 [20];
  undefined4 local_84;
  undefined4 local_70;
  byte *local_6c;
  byte abStack_40 [32];
  uint local_20;
  
  local_20 = DAT_c05b62e4;
  iVar2 = *(int *)(param_1 + 0x150);
  DVar5 = 0;
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x224) == 0)) {
    FUN_c05aea6c(iVar2);
    *(undefined4 *)(param_1 + 0x150) = 0;
  }
  uVar4 = *(uint *)(param_1 + 0x20);
  if (((uVar4 & 0x2000) != 0) && ((uVar4 & 0x8000) != 0)) {
    if ((uVar4 & 0x800000) == 0) {
      *(uint *)(param_1 + 0x20) = uVar4 | 0x800000;
    }
    *(undefined4 *)(param_1 + 0x28) = 0;
    if ((*(uint *)(param_1 + 0x20) & 0x100000) != 0) {
      iVar2 = 0;
      if ((*(int **)(param_1 + 0x138) != (int *)0x0) &&
         (uVar4 = 0, **(int **)(param_1 + 0x138) != 0)) {
        iVar6 = 0;
        do {
          iVar3 = *(int *)(param_1 + 0x138) + iVar6;
          bVar1 = FUN_c05a486c((char *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x18));
          if (CONCAT31(extraout_var,bVar1) == 0) {
            iVar2 = iVar2 + 1;
          }
          uVar4 = uVar4 + 1;
          iVar6 = iVar6 + 0xc4;
        } while (uVar4 < **(uint **)(param_1 + 0x138));
        if (iVar2 != 0) {
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffefffff;
        }
      }
    }
    DVar5 = FUN_c05a6050(param_1);
  }
  if (((*(uint *)(param_1 + 0x20) & 0x8000) != 0) || (*(int *)(param_1 + 0x164) == 0)) {
    memset(abStack_40,0,0x20);
    iVar2 = FUN_c05a47a0(abStack_40,0x20,1,0x1f);
    if (iVar2 == 0) {
      memset(auStack_98,0,0x58);
      local_6c = abStack_40;
      local_70 = 0x20;
      local_84 = 1;
      FUN_c05aee90(param_1,(int)auStack_98,0x1200000,(uint *)0x0);
      memset((void *)(param_1 + 0x84),0,0x24);
    }
    *(undefined4 *)(param_1 + 0x164) = 1;
  }
  if ((*(uint *)(param_1 + 0x20) & 0x8000) == 0) {
    DVar5 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xffff0002,0);
    *(undefined4 *)(param_1 + 0x15c) = 0;
  }
  *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + 1;
  if ((*(uint *)(param_1 + 0x20) & 0x2000) != 0) {
    iVar2 = DAT_c05b6378;
    if ((*(uint *)(param_1 + 0x20) & 0x8000) == 0) {
      iVar2 = 0x70000000;
    }
    DVar5 = FUN_c05af7cc(param_1,iVar2);
  }
  FUN_c05b4904(local_20);
  return DVar5;
}



/* c05afc1c FUN_c05afc1c */

/* Boundary evidence: original MIPS .pdata c05afc1c..c05afc3f. Semantic name remains unreviewed. */

void FUN_c05afc1c(int param_1)

{
  FUN_c05af7cc(param_1,DAT_c05b6370);
  return;
}



/* c05afc40 FUN_c05afc40 */

/* Boundary evidence: original MIPS .pdata c05afc40..c05afdc3. Semantic name remains unreviewed. */

DWORD FUN_c05afc40(int param_1)

{
  DWORD DVar1;
  uint uVar2;
  uint *puVar3;
  
  *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + 1;
  if (((((*(uint *)(param_1 + 0x20) & 0x8000) == 0) ||
       (puVar3 = *(uint **)(param_1 + 0x140), puVar3 == (uint *)0x0)) || (*puVar3 <= puVar3[1])) ||
     (uVar2 = puVar3[1], (puVar3[uVar2 * 0x31 + 3] & 0x10000) != 0)) {
    *(code **)(param_1 + 0x24) = FUN_c05af9d8;
    DVar1 = 0x4de;
    FUN_c05a8fbc(10,(void *)0x0,0,0,0,*(wchar_t **)(param_1 + 0x34),(undefined4 *)0x0);
    if ((*(int **)(param_1 + 0x138) != (int *)0x0) && (**(int **)(param_1 + 0x138) != 0)) {
      FUN_c05a8fbc(0xc,(void *)0x0,0,0,0,*(wchar_t **)(param_1 + 0x34),(undefined4 *)0x0);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x28) = 0;
    FUN_c05a8fbc(1,puVar3 + uVar2 * 0x31 + 7,puVar3[uVar2 * 0x31 + 6],0,puVar3[uVar2 * 0x31 + 0x1a],
                 *(wchar_t **)(param_1 + 0x34),(undefined4 *)0x0);
    *(undefined4 *)(param_1 + 0x6c) = 0;
    DVar1 = FUN_c05a5b48(param_1);
    if (DVar1 == 0) {
      DVar1 = FUN_c05af7cc(param_1,DAT_c05b6374);
    }
    else {
      DVar1 = 0x4de;
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x40000;
      *(code **)(param_1 + 0x24) = FUN_c05b0314;
    }
  }
  return DVar1;
}



/* c05afdc4 FUN_c05afdc4 */

/* Boundary evidence: original MIPS .pdata c05afdc4..c05afeb3. Semantic name remains unreviewed. */

undefined4 FUN_c05afdc4(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x160) != 0) {
    FUN_c05ae56c(*(int *)(param_1 + 0x150));
  }
  if ((*(uint *)(param_1 + 0x20) & 0x400000) == 0) {
    puVar1 = *(uint **)(param_1 + 0x140);
    uVar3 = 0;
    uVar4 = (puVar1[1] + 1) % *puVar1;
    if (*puVar1 == 0) {
      trap(0x1c00);
    }
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      do {
        if ((puVar1[uVar4 * 0x31 + 3] & 0x10000) == 0) break;
        uVar4 = (uVar4 + 1) % uVar2;
        uVar3 = uVar3 + 1;
        if (uVar2 == 0) {
          trap(0x1c00);
        }
      } while (uVar3 < **(uint **)(param_1 + 0x140));
    }
    if (uVar3 == uVar2) {
      FUN_c05a4684(puVar1);
      *(undefined4 *)(param_1 + 0x140) = 0;
    }
    else {
      puVar1[1] = uVar4;
    }
  }
  *(code **)(param_1 + 0x24) = FUN_c05afc40;
  return 0x4de;
}



/* c05afeb4 FUN_c05afeb4 */

/* Boundary evidence: original MIPS .pdata c05afeb4..c05b005f. Semantic name remains unreviewed. */

undefined4 FUN_c05afeb4(int param_1)

{
  DWORD DVar1;
  int iVar2;
  code *pcVar3;
  uint *puVar4;
  uint *local_18;
  uint local_14;
  
  FUN_c05aeef8(param_1);
  DVar1 = FUN_c05aeec4(param_1,0x5e00000,(uint *)0x0);
  if (DVar1 == 0) {
    local_18 = (uint *)0x0;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x2000;
    FUN_c05a62d0(param_1);
    DVar1 = FUN_c05a546c(param_1,(int *)&local_18);
    if (DVar1 == 0) {
      local_14 = 0;
      iVar2 = FUN_c05a5a10(param_1,local_18,&local_14);
      if (iVar2 == 0) {
        FUN_c05a4684(local_18);
        if ((*(uint *)(param_1 + 0x20) & 0x20000) == 0) {
          *(code **)(param_1 + 0x24) = FUN_c05af8d4;
          return 0x4de;
        }
        pcVar3 = FUN_c05afc1c;
      }
      else {
        if (((*(uint *)(param_1 + 0x20) & 0x1000000) == 0) &&
           (iVar2 = FUN_c05aefd4(param_1), iVar2 == 0)) {
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x1000000;
        }
        if (*(int *)(param_1 + 0x160) != 0) {
          FUN_c05ae56c(*(int *)(param_1 + 0x150));
        }
        FUN_c05a4684(*(uint **)(param_1 + 0x140));
        puVar4 = *(uint **)(param_1 + 0x13c);
        *(uint **)(param_1 + 0x140) = local_18;
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffbfffff;
        if ((puVar4 != (uint *)0x0) && (puVar4[1] < *puVar4)) {
          puVar4[1] = *puVar4;
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x400000;
        }
        if (*(int *)(param_1 + 0x140) != 0) {
          *(uint *)(*(int *)(param_1 + 0x140) + 4) = local_14;
        }
        pcVar3 = FUN_c05afc40;
      }
      *(code **)(param_1 + 0x24) = pcVar3;
    }
  }
  else {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffefdfff;
    *(code **)(param_1 + 0x24) = FUN_c05af9d8;
  }
  return 0x4de;
}



/* c05b0060 FUN_c05b0060 */

/* Boundary evidence: original MIPS .pdata c05b0060..c05b014b. Semantic name remains unreviewed. */

DWORD FUN_c05b0060(int param_1)

{
  DWORD DVar1;
  uint uVar2;
  
  DVar1 = FUN_c05aeec4(param_1,0x8000000,(uint *)0x0);
  if ((*(int *)(param_1 + 0x15c) == 0) && ((*(uint *)(param_1 + 0x20) & 0x8000) != 0)) {
    DVar1 = FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xffff0001,0);
    *(undefined4 *)(param_1 + 0x15c) = 1;
  }
  if (DVar1 == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfff7ffff;
    DVar1 = FUN_c05af7cc(param_1,DAT_c05b636c);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x20);
    if ((uVar2 & 0x80000) == 0) {
      *(uint *)(param_1 + 0x20) = uVar2 | 0x80000;
      *(code **)(param_1 + 0x24) = FUN_c05af890;
    }
    else {
      *(uint *)(param_1 + 0x20) = uVar2 & 0xffe7ffff;
      *(code **)(param_1 + 0x24) = FUN_c05afeb4;
    }
    DVar1 = 0x4de;
  }
  return DVar1;
}



/* c05b014c FUN_c05b014c */

/* Boundary evidence: original MIPS .pdata c05b014c..c05b0313. Semantic name remains unreviewed. */

undefined4 FUN_c05b014c(int param_1)

{
  bool bVar1;
  DWORD DVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  undefined1 auStack_98 [20];
  undefined4 local_84;
  undefined4 local_70;
  byte *local_6c;
  byte abStack_40 [32];
  uint local_20;
  
  local_20 = DAT_c05b62e4;
  piVar4 = (int *)(param_1 + 0x150);
  if (*piVar4 != 0) {
    FUN_c05a4f04(param_1);
    FUN_c05ae56c(*piVar4);
  }
  memset((void *)(param_1 + 0x7c),0,6);
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + 1;
  DVar2 = FUN_c05aeec4(param_1,0x1100000,(uint *)0x0);
  if (((*(uint *)(param_1 + 0x20) & 0x8000) != 0) && (DVar2 == 0)) {
    bVar1 = FUN_c05a486c((char *)(param_1 + 0x88),*(int *)(param_1 + 0x84));
    if (CONCAT31(extraout_var,bVar1) != 0) {
      memset(abStack_40,0,0x20);
      iVar3 = FUN_c05a47a0(abStack_40,0x20,1,0x1f);
      if (iVar3 == 0) {
        memset(auStack_98,0,0x58);
        local_6c = abStack_40;
        local_70 = 0x20;
        local_84 = 1;
        FUN_c05aee90(param_1,(int)auStack_98,0x1200000,(uint *)0x0);
        memset((int *)(param_1 + 0x84),0,0x24);
      }
    }
  }
  if ((((*(uint *)(param_1 + 0x20) & 0x8000) != 0) && ((*(uint *)(param_1 + 0x20) & 0x1000000) == 0)
      ) && (iVar3 = FUN_c05aefd4(param_1), iVar3 == 0)) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x1000000;
  }
  if (*piVar4 == 0) {
    FUN_c05aebac(param_1,*(wchar_t **)(param_1 + 0x34),FUN_c05a834c,piVar4);
  }
  FUN_c05a4684(*(uint **)(param_1 + 0x140));
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(code **)(param_1 + 0x24) = FUN_c05b0060;
  FUN_c05b4904(local_20);
  return 0x4de;
}



/* c05b0314 FUN_c05b0314 */

/* Boundary evidence: original MIPS .pdata c05b0314..c05b05ff. Semantic name remains unreviewed. */

undefined4 FUN_c05b0314(int param_1)

{
  bool bVar1;
  DWORD DVar2;
  uint *puVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  
  FUN_c05ae56c(*(int *)(param_1 + 0x150));
  iVar6 = *(int *)(param_1 + 0x140);
  if (iVar6 == 0) {
    pcVar4 = FUN_c05b014c;
  }
  else {
    iVar6 = *(int *)(iVar6 + 4) * 0xc4 + iVar6;
    puVar9 = (uint *)(iVar6 + 8);
    DVar2 = FUN_c05aeef8(param_1);
    if ((*(uint *)(param_1 + 0x20) & 0x40000) == 0) {
      if (((*(uint *)(iVar6 + 0xc) & 0x20000) != 0) ||
         ((DVar2 == 0 && (*(int *)(param_1 + 0x54) == 0)))) {
        pcVar4 = FUN_c05b0600;
        goto LAB_c05b05d4;
      }
    }
    else {
      *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfffdffff | 0x40000;
    }
    if (((*(int *)(iVar6 + 0x68) == 0) && ((*(uint *)(iVar6 + 0xc) & 0x20000) == 0)) &&
       ((*(uint *)(param_1 + 0x20) & 0x40000) == 0)) {
      *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 0x20000;
    }
    puVar3 = FUN_c05a42d4(*(uint **)(param_1 + 0x13c),(int)puVar9,0);
    if (((*(uint *)(param_1 + 0x20) & 0x40000) != 0) && (puVar3 != (uint *)0x0)) {
      puVar3[1] = puVar3[1] | 0x10000;
    }
    if (*(int *)(param_1 + 0x6c) == 0) {
      FUN_c05a8fbc(2,(void *)(iVar6 + 0x1c),*(uint *)(iVar6 + 0x18),0,
                   *(undefined4 *)(param_1 + 0xd4),*(wchar_t **)(param_1 + 0x34),(undefined4 *)0x0);
    }
    if (*(int *)(param_1 + 0x160) != 0) {
      FUN_c05ae56c(*(int *)(param_1 + 0x150));
    }
    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 0x10000;
    uVar7 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar7 & 0xfffbffff;
    if ((uVar7 & 0x400000) != 0) {
      (*(int **)(param_1 + 0x140))[1] = **(int **)(param_1 + 0x140) + -1;
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffbfffff;
    }
    puVar3 = *(uint **)(param_1 + 0x140);
    uVar7 = (puVar3[1] + 1) % *puVar3;
    if (*puVar3 == 0) {
      trap(0x1c00);
    }
    uVar5 = puVar3[1];
    while ((uVar7 != uVar5 &&
           (puVar9 = puVar3 + uVar7 * 0x31 + 2, (puVar3[uVar7 * 0x31 + 3] & 0x10000) != 0))) {
      uVar7 = (uVar7 + 1) % *puVar3;
      if (*puVar3 == 0) {
        trap(0x1c00);
      }
      uVar5 = *(uint *)(*(int *)(param_1 + 0x140) + 4);
    }
    if ((puVar9[1] & 0x10000) == 0) {
      puVar3[1] = uVar7;
    }
    else {
      bVar1 = false;
      uVar7 = 0;
      if (*puVar3 != 0) {
        iVar6 = 0;
        do {
          iVar8 = *(int *)(param_1 + 0x140) + iVar6;
          uVar5 = *(uint *)(iVar8 + 0xc);
          if (((uVar5 & 0x20000) != 0) && (*(uint *)(iVar8 + 0xc) = uVar5 & 0xfffeffff, !bVar1)) {
            bVar1 = true;
            *(uint *)(*(int *)(param_1 + 0x140) + 4) = uVar7;
          }
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + 0xc4;
        } while (uVar7 < **(uint **)(param_1 + 0x140));
      }
    }
    pcVar4 = FUN_c05afc40;
  }
LAB_c05b05d4:
  *(code **)(param_1 + 0x24) = pcVar4;
  return 0x4de;
}



/* c05b0600 FUN_c05b0600 */

/* Boundary evidence: original MIPS .pdata c05b0600..c05b09af. Semantic name remains unreviewed. */

undefined4 FUN_c05b0600(int param_1)

{
  int iVar1;
  DWORD DVar2;
  size_t sVar3;
  wchar_t *_Dest;
  LSTATUS LVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  LPCSTR lpMultiByteStr;
  HKEY local_130;
  BYTE local_12c [4];
  WCHAR aWStack_128 [130];
  uint local_24;
  
  local_24 = DAT_c05b62e4;
  *(undefined4 *)(param_1 + 0x28) = 0;
  iVar6 = *(int *)(*(int *)(param_1 + 0x140) + 4) * 0xc4 + *(int *)(param_1 + 0x140);
  FUN_c05aeec4(param_1,0x2000000,(uint *)0x0);
  lpMultiByteStr = (LPCSTR)(iVar6 + 0x1c);
  iVar1 = MultiByteToWideChar(1,0,lpMultiByteStr,*(int *)(iVar6 + 0x18),aWStack_128,0x80);
  iVar7 = *(int *)(param_1 + 0x160);
  aWStack_128[iVar1] = L'\0';
  puVar8 = (undefined4 *)(param_1 + 0x7c);
  if (iVar7 == 0) {
    FUN_c05a8fbc(3,lpMultiByteStr,*(uint *)(iVar6 + 0x18),0,*(undefined4 *)(param_1 + 0xd4),
                 *(wchar_t **)(param_1 + 0x34),puVar8);
  }
  else {
    FUN_c05a8fbc(0xd,lpMultiByteStr,*(uint *)(iVar6 + 0x18),0,*(undefined4 *)(param_1 + 0xd4),
                 *(wchar_t **)(param_1 + 0x34),puVar8);
  }
  *(undefined4 *)(param_1 + 0x6c) = 1;
  DVar2 = FUN_c05aeec4(param_1,0x2000000,(uint *)0x0);
  if (DVar2 == 0) {
    FUN_c05a5f0c(param_1);
  }
  if (*(int *)(param_1 + 0x160) == 0) {
    iVar7 = *(int *)(param_1 + 0x140);
    local_130 = (HKEY)0x0;
    iVar1 = *(int *)(iVar7 + 4);
    sVar3 = wcslen(*(wchar_t **)(param_1 + 0x34));
    _Dest = FUN_c05a4228((sVar3 + 0x12) * 2);
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,L"COMM\\");
      wcscat(_Dest,*(wchar_t **)(param_1 + 0x34));
      wcscat(_Dest,L"\\Parms\\Tcpip");
      LVar4 = RegOpenKeyExW((HKEY)0x80000002,_Dest,0,0xf003f,&local_130);
      if (LVar4 == 0) {
        if (*(int *)(iVar1 * 0xc4 + iVar7 + 0x68) == 0) {
          local_12c[0] = '\x01';
          local_12c[1] = '\0';
          local_12c[2] = '\0';
          local_12c[3] = '\0';
          RegSetValueExW(local_130,L"DhcpEnableImmediateAutoIP",0,4,local_12c,4);
        }
        else {
          RegDeleteValueW(local_130,L"DhcpEnableImmediateAutoIP");
        }
        RegCloseKey(local_130);
      }
      FUN_c05a42b0(_Dest);
    }
    FUN_c05aeef8(param_1);
    if (*(int *)(param_1 + 0x54) == 0) {
      FUN_c05ab138(*(HANDLE *)(param_1 + 0x60),0xffff0003,0);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x150);
    if (iVar1 == 0) {
LAB_c05b07c0:
      FUN_c05aeec4(param_1,0x2000000,(uint *)0x0);
      FUN_c05a8fbc(5,lpMultiByteStr,*(uint *)(iVar6 + 0x18),0,*(undefined4 *)(param_1 + 0xd4),
                   *(wchar_t **)(param_1 + 0x34),puVar8);
    }
    else {
      iVar7 = wcscmp(aWStack_128,(wchar_t *)(iVar1 + 0x118));
      if (iVar7 != 0) {
        FUN_c05ae56c(iVar1);
        goto LAB_c05b07c0;
      }
      FUN_c05aeec4(param_1,0x2000000,(uint *)0x0);
      FUN_c05a8fbc(0xb,(void *)(param_1 + 0x88),*(uint *)(param_1 + 0x84),0,
                   *(undefined4 *)(param_1 + 0xd4),*(wchar_t **)(param_1 + 0x34),puVar8);
    }
    iVar1 = FUN_c05ae71c(*(int *)(param_1 + 0x150));
    if (iVar1 != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x40000;
      *(code **)(param_1 + 0x24) = FUN_c05b0314;
      goto LAB_c05b097c;
    }
  }
  uVar5 = *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x20) = uVar5 | 0x300000;
  if ((*(int *)(iVar6 + 0x3c) == 1) || ((uVar5 & 0x20000) == 0)) {
    *(code **)(param_1 + 0x24) = FUN_c05af8d4;
  }
  else {
    *(code **)(param_1 + 0x24) = FUN_c05afc1c;
  }
LAB_c05b097c:
  FUN_c05b4904(local_24);
  return 0x4de;
}



/* c05b09b0 FUN_c05b09b0 */

/* Boundary evidence: original MIPS .pdata c05b09b0..c05b0b53. Semantic name remains unreviewed. */

DWORD FUN_c05b09b0(int param_1)

{
  HLOCAL pvVar1;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  
  DVar2 = FUN_c05b3478((HKEY)0x0,param_1);
  DVar3 = 0;
  if ((DVar2 == 0) || (DVar3 = FUN_c05b2814(param_1), DVar3 == 0)) {
    if (DAT_c05b6368 != 0) {
      FUN_c05a8fbc(0xffffffff,(void *)0x0,0,0,0,*(wchar_t **)(param_1 + 0x34),(undefined4 *)0x0);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6384);
      pvVar1 = DAT_c05b6380;
      FUN_c05a4c10((int)DAT_c05b6380);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6384);
      FUN_c05a4c38((int)pvVar1);
      DVar3 = FUN_c05a5464();
      FUN_c05a63ec(pvVar1);
    }
    if (((DVar3 == 0) && (DVar3 = FUN_c05aeef8(param_1), DVar3 == 0)) &&
       (DVar3 = FUN_c05aee64(param_1), DVar3 == 0)) {
      if ((*(int *)(param_1 + 0x5c) == 1) ||
         ((*(int *)(param_1 + 0x5c) == 9 && (*(int *)(param_1 + 0x58) == 0)))) {
        DVar3 = FUN_c05aeec4(param_1,0x5e00000,(uint *)0x0);
        if (DVar3 == 0) {
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x2000;
        }
        uVar4 = *(uint *)(param_1 + 0x20);
        *(code **)(param_1 + 0x24) = FUN_c05b014c;
        *(uint *)(param_1 + 0x20) = uVar4 | 0x100000;
        if (((uVar4 & 0x8000) == 0) && ((uVar4 & 0x800000) == 0)) {
          *(uint *)(param_1 + 0x20) = uVar4 | 0x900000;
        }
        DVar3 = 0x4de;
      }
      else {
        DVar3 = 0x10db;
      }
    }
  }
  return DVar3;
}



/* c05b0b54 FUN_c05b0b54 */

/* Boundary evidence: original MIPS .pdata c05b0b54..c05b0f23. Semantic name remains unreviewed. */

DWORD FUN_c05b0b54(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  code *pcVar2;
  code *pcVar3;
  DWORD DVar4;
  
  DVar4 = 0;
  switch(param_1) {
  case 0:
    pcVar3 = FUN_c05b09b0;
    break;
  default:
    goto switchD_c05b0b98_caseD_1;
  case 2:
    DVar4 = FUN_c05aeec4(param_2,0x2000000,(uint *)0x0);
    if ((DVar4 == 0) &&
       (((pcVar3 = *(code **)(param_2 + 0x24), pcVar3 == FUN_c05af8d4 || (pcVar3 == FUN_c05afc1c))
        || ((pcVar3 == FUN_c05b0060 || (pcVar3 == FUN_c05af890)))))) {
      FUN_c05a5f0c(param_2);
    }
    pcVar3 = *(code **)(param_2 + 0x24);
    if (pcVar3 == FUN_c05afc40) {
      pcVar3 = FUN_c05b0600;
      goto LAB_c05b0c14;
    }
    if ((pcVar3 != FUN_c05af890) && (pcVar3 != FUN_c05af9d8)) {
      if (pcVar3 != FUN_c05af8d4) {
        return 0;
      }
      if (*(int *)(param_2 + 0x160) != 0) {
        return 0;
      }
      FUN_c05ab138(*(HANDLE *)(param_2 + 0x60),0xffff0003,0);
      return 0;
    }
    *(code **)(param_2 + 0x24) = FUN_c05b0060;
    goto LAB_c05b0ec4;
  case 3:
    pcVar3 = *(code **)(param_2 + 0x24);
    if ((((pcVar3 != FUN_c05b0060) && (pcVar3 != FUN_c05af890)) && (pcVar3 != FUN_c05af8d4)) &&
       (pcVar3 != FUN_c05afc1c)) {
      return 0;
    }
LAB_c05b0c0c:
    pcVar3 = FUN_c05b014c;
LAB_c05b0c14:
    *(code **)(param_2 + 0x24) = pcVar3;
    goto LAB_c05b0ec4;
  case 4:
    pcVar3 = *(code **)(param_2 + 0x24);
    if (pcVar3 != FUN_c05b0060) {
      if (pcVar3 != FUN_c05af890) {
        if (pcVar3 == FUN_c05af9d8) goto LAB_c05b0c0c;
        if (pcVar3 == FUN_c05afc40) {
          pcVar3 = FUN_c05b0314;
          goto LAB_c05b0c14;
        }
        if ((pcVar3 != FUN_c05af8d4) && (pcVar3 != FUN_c05afc1c)) {
          return 0;
        }
      }
      *(code **)(param_2 + 0x24) = FUN_c05b0060;
      goto LAB_c05b0ec4;
    }
    pcVar3 = FUN_c05afeb4;
    break;
  case 5:
    if (param_3 == (uint *)0x0) {
      return 0x57;
    }
    pcVar2 = *(code **)(param_2 + 0x24);
    pcVar3 = FUN_c05b0060;
    if (pcVar2 != FUN_c05af8d4) {
      if (((pcVar2 != FUN_c05afc1c) && (pcVar2 != FUN_c05b0060)) && (pcVar2 != FUN_c05af890)) {
        pcVar3 = FUN_c05b014c;
        goto LAB_c05b0c14;
      }
      if ((pcVar2 != FUN_c05af8d4) && (pcVar2 != FUN_c05afc1c)) {
        return 0;
      }
    }
    if ((*param_3 & 0x8000000) == 0) {
      pcVar3 = FUN_c05afeb4;
    }
    goto LAB_c05b0ec0;
  case 6:
    FUN_c05a4684(*(uint **)(param_2 + 0x144));
    pcVar3 = FUN_c05b014c;
    *(undefined4 *)(param_2 + 0x144) = 0;
    break;
  case 7:
  case 8:
    pcVar3 = *(code **)(param_2 + 0x24);
    if ((((pcVar3 != FUN_c05af8d4) && (pcVar3 != FUN_c05afc1c)) && (pcVar3 != FUN_c05b0060)) &&
       (pcVar3 != FUN_c05af890)) {
      return 0;
    }
    if (param_1 == 8) {
      uVar1 = *(uint *)(param_2 + 0x20);
      goto LAB_c05b0ebc;
    }
    pcVar3 = FUN_c05afdc4;
    break;
  case 9:
    if (*(code **)(param_2 + 0x24) != FUN_c05afc1c) {
      return 0;
    }
    uVar1 = *(uint *)(param_2 + 0x20);
LAB_c05b0ebc:
    pcVar3 = FUN_c05b0314;
    *(uint *)(param_2 + 0x20) = uVar1 | 0x40000;
LAB_c05b0ec0:
    *(code **)(param_2 + 0x24) = pcVar3;
    goto LAB_c05b0ec4;
  }
  *(code **)(param_2 + 0x24) = pcVar3;
LAB_c05b0ec4:
  DVar4 = FUN_c05af7cc(param_2,0x70000000);
  if (DVar4 == 0) {
    DVar4 = 0x4de;
  }
  while (DVar4 == 0x4de) {
    DVar4 = (**(code **)(param_2 + 0x24))(param_2);
  }
switchD_c05b0b98_caseD_1:
  return DVar4;
}



/* c05b0f24 FUN_c05b0f24 */

/* Boundary evidence: original MIPS .pdata c05b0f24..c05b114f. Semantic name remains unreviewed. */

void FUN_c05b0f24(undefined4 param_1,undefined4 param_2,void *param_3,uint param_4,
                 undefined1 *param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined1 *_Src;
  int iVar7;
  uint local_180 [16];
  uint local_140 [16];
  undefined1 local_100 [96];
  undefined1 auStack_a0 [96];
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_c05b62e4;
  _Src = auStack_40;
  if (0x13 < param_6) {
    _Src = param_5;
  }
  if (0x40 < param_4) {
    A_SHAInit(auStack_a0);
    A_SHAUpdate(auStack_a0,param_3,param_4);
    A_SHAFinal(auStack_a0,param_3);
    param_4 = 0x14;
  }
  iVar7 = 0x40;
  memset(local_140,0,0x40);
  memset(local_180,0,0x40);
  memcpy(local_140,param_3,param_4);
  memcpy(local_180,param_3,param_4);
  uVar1 = 0;
  do {
    uVar4 = *(uint *)((int)local_180 + uVar1 + 4);
    *(uint *)((int)local_140 + uVar1 + 4) = *(uint *)((int)local_140 + uVar1 + 4) ^ 0x36363636;
    *(uint *)((int)local_140 + uVar1) = *(uint *)((int)local_140 + uVar1) ^ 0x36363636;
    uVar2 = uVar1 + 8;
    *(uint *)((int)local_180 + uVar1 + 4) = uVar4 ^ 0x5c5c5c5c;
    *(uint *)((int)local_180 + uVar1) = *(uint *)((int)local_180 + uVar1) ^ 0x5c5c5c5c;
    uVar1 = uVar2;
  } while (uVar2 < 0x40);
  A_SHAInit(local_100);
  A_SHAUpdate(local_100,local_140,0x40);
  A_SHAUpdate(local_100,param_1,param_2);
  A_SHAFinal(local_100,_Src);
  A_SHAInit(local_100);
  A_SHAUpdate(local_100,local_180,0x40);
  A_SHAUpdate(local_100,_Src,0x14);
  A_SHAFinal(local_100,_Src);
  iVar3 = 0x40;
  puVar5 = local_140;
  do {
    *(undefined1 *)puVar5 = 0;
    iVar3 = iVar3 + -1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while (iVar3 != 0);
  puVar5 = local_180;
  do {
    *(undefined1 *)puVar5 = 0;
    iVar7 = iVar7 + -1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while (iVar7 != 0);
  iVar7 = 0x5c;
  puVar6 = local_100;
  do {
    *puVar6 = 0;
    iVar7 = iVar7 + -1;
    puVar6 = puVar6 + 1;
  } while (iVar7 != 0);
  if (_Src != param_5) {
    memcpy(param_5,_Src,param_6);
  }
  FUN_c05b4904(local_2c);
  return;
}



/* c05b115c FUN_c05b115c */

/* Boundary evidence: original MIPS .pdata c05b115c..c05b118f. Semantic name remains unreviewed. */

bool FUN_c05b115c(undefined4 param_1,void *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,(void *)(param_3 + 0xc),6);
  return iVar1 == 0;
}



/* c05b1190 FUN_c05b1190 */

/* Boundary evidence: original MIPS .pdata c05b1190..c05b11db. Semantic name remains unreviewed. */

void FUN_c05b1190(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0x48;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  piVar2 = param_2;
  do {
    *(undefined1 *)piVar2 = 0;
    iVar1 = iVar1 + -1;
    piVar2 = (int *)((int)piVar2 + 1);
  } while (iVar1 != 0);
  operator_delete(param_2);
  return;
}



/* c05b11dc FUN_c05b11dc */

/* Boundary evidence: original MIPS .pdata c05b11dc..c05b125b. Semantic name remains unreviewed. */

undefined4 FUN_c05b11dc(int param_1,int *param_2)

{
  undefined4 uVar1;
  DWORD DVar2;
  uint uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x10);
  uVar1 = 0;
  if (piVar4 != (int *)(param_1 + 0x10)) {
    DVar2 = GetTickCount();
    uVar3 = DVar2 - piVar4[2];
    if (uVar3 < *(uint *)(param_1 + 0x1c)) {
      *param_2 = *(uint *)(param_1 + 0x1c) - uVar3;
    }
    else {
      *param_2 = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c05b125c FUN_c05b125c */

/* Boundary evidence: original MIPS .pdata c05b125c..c05b141f. Semantic name remains unreviewed. */

undefined4 FUN_c05b125c(int *param_1,int *param_2,void *param_3,uint param_4,void *param_5)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined3 extraout_var;
  DWORD DVar5;
  int *piVar6;
  undefined4 uVar7;
  
  if (param_4 < 0x21) {
    if (param_1[6] == 0) {
      uVar7 = 0x422;
    }
    else {
      piVar2 = (int *)FUN_c05b4160(param_1,param_2);
      if (piVar2 == (int *)0x0) {
        piVar2 = operator_new(0x48);
        if (piVar2 == (int *)0x0) {
          return 0xe;
        }
        piVar2[3] = *param_2;
        *(short *)(piVar2 + 4) = (short)param_2[1];
        uVar3 = FUN_c05b4220((int)param_1);
        if ((uint)param_1[6] <= uVar3) {
          do {
            piVar6 = (int *)param_1[4];
            iVar4 = 0;
            if (piVar6 != param_1 + 4) {
              bVar1 = FUN_c05b4110(param_1,piVar6 + 3);
              iVar4 = CONCAT31(extraout_var,bVar1);
            }
            if (iVar4 == 0) {
              operator_delete(piVar2);
              return 0x490;
            }
            uVar3 = FUN_c05b4220((int)param_1);
          } while ((uint)param_1[6] <= uVar3);
        }
        FUN_c05b3f48(param_1,(int)piVar2);
      }
      else {
        *(int *)piVar2[1] = *piVar2;
        *(int *)(*piVar2 + 4) = piVar2[1];
      }
      uVar7 = 0;
      memcpy((void *)((int)piVar2 + 0x12),param_3,param_4);
      piVar2[0xd] = param_4;
      memcpy(piVar2 + 0xe,param_5,0x10);
      DVar5 = GetTickCount();
      piVar2[2] = DVar5;
      *piVar2 = (int)(param_1 + 4);
      piVar2[1] = param_1[5];
      *(int **)param_1[5] = piVar2;
      param_1[5] = (int)piVar2;
    }
  }
  else {
    uVar7 = 0x18;
  }
  return uVar7;
}



/* c05b1420 FUN_c05b1420 */

/* Boundary evidence: original MIPS .pdata c05b1420..c05b146b. Semantic name remains unreviewed. */

void FUN_c05b1420(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int *piVar3;
  
  do {
    piVar3 = (int *)param_1[4];
    iVar2 = 0;
    if (piVar3 != param_1 + 4) {
      bVar1 = FUN_c05b4110(param_1,piVar3 + 3);
      iVar2 = CONCAT31(extraout_var,bVar1);
    }
  } while (iVar2 != 0);
  return;
}



/* c05b146c FUN_c05b146c */

/* Boundary evidence: original MIPS .pdata c05b146c..c05b1487. Semantic name remains unreviewed. */

void FUN_c05b146c(int *param_1,undefined4 param_2)

{
  FUN_c05b4160(param_1,param_2);
  return;
}



/* c05b1488 FUN_c05b1488 */

/* Boundary evidence: original MIPS .pdata c05b1488..c05b1507. Semantic name remains unreviewed. */

void FUN_c05b1488(int *param_1)

{
  int *piVar1;
  DWORD DVar2;
  int *piVar3;
  
  DVar2 = GetTickCount();
  piVar1 = (int *)param_1[4];
  while ((piVar1 != param_1 + 4 && (piVar3 = (int *)*piVar1, (uint)param_1[7] <= DVar2 - piVar1[2]))
        ) {
    FUN_c05b4110(param_1,piVar1 + 3);
    piVar1 = piVar3;
  }
  return;
}



/* c05b1508 FUN_c05b1508 */

/* Boundary evidence: original MIPS .pdata c05b1508..c05b163f. Semantic name remains unreviewed. */

undefined4
FUN_c05b1508(undefined4 *param_1,undefined4 *param_2,void *param_3,uint param_4,void *param_5)

{
  char local_48 [8];
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined4 local_3a;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_30;
  undefined1 auStack_2f [19];
  uint local_1c;
  
  local_1c = DAT_c05b62e4;
  local_30 = 0;
  memset(auStack_2f,0,0x13);
  builtin_strncpy(local_48,"PMK ",4);
  local_40 = *param_1;
  local_3b = *(undefined1 *)((int)param_1 + 5);
  builtin_strncpy(local_48 + 4,"Name",4);
  local_3c = *(undefined1 *)(param_1 + 1);
  local_35 = *(undefined1 *)((int)param_2 + 5);
  local_36 = *(undefined1 *)(param_2 + 1);
  local_3a = *param_2;
  FUN_c05b0f24(local_48,0x14,param_3,param_4,&local_30,0x14);
  memcpy(param_5,&local_30,0x10);
  FUN_c05b4904(local_1c);
  return 0;
}



/* c05b1640 FUN_c05b1640 */

/* Boundary evidence: original MIPS .pdata c05b1640..c05b16cb. Semantic name remains unreviewed. */

undefined4 FUN_c05b1640(int param_1,void *param_2)

{
  int iVar1;
  void *_Buf2;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + 0x21c);
  uVar3 = 0;
  if (uVar2 != 0) {
    _Buf2 = *(void **)(param_1 + 0x220);
    do {
      iVar1 = memcmp(param_2,_Buf2,6);
      if (iVar1 == 0) {
        return 1;
      }
      uVar3 = uVar3 + 1;
      _Buf2 = (void *)((int)_Buf2 + 0xc);
    } while (uVar3 < uVar2);
  }
  return 0;
}



/* c05b16cc FUN_c05b16cc */

/* Boundary evidence: original MIPS .pdata c05b16cc..c05b1727. Semantic name remains unreviewed. */

void * FUN_c05b16cc(int param_1)

{
  void *_Dst;
  
  _Dst = (void *)0x0;
  if ((*(int *)(param_1 + 0x288) != 0) &&
     (_Dst = operator_new(*(uint *)(param_1 + 0x28c)), _Dst != (void *)0x0)) {
    memcpy(_Dst,*(void **)(param_1 + 0x288),*(size_t *)(param_1 + 0x28c));
  }
  return _Dst;
}



/* c05b1728 FUN_c05b1728 */

/* Boundary evidence: original MIPS .pdata c05b1728..c05b1797. Semantic name remains unreviewed. */

void FUN_c05b1728(int param_1,undefined4 *param_2,undefined4 param_3,STRSAFE_LPCWSTR param_4)

{
  undefined1 uVar1;
  
  *(undefined4 *)(param_1 + 0x2b8) = param_3;
  *(undefined4 *)(param_1 + 0x14) = *param_2;
  uVar1 = *(undefined1 *)((int)param_2 + 5);
  *(undefined1 *)(param_1 + 0x18) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)(param_1 + 0x19) = uVar1;
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x1a),0x101,param_4);
  FUN_c05b3e88(param_1 + 0x228,0x7f);
  return;
}



/* c05b1798 FUN_c05b1798 */

/* Boundary evidence: original MIPS .pdata c05b1798..c05b17ef. Semantic name remains unreviewed. */

void FUN_c05b1798(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined1 **)(param_1 + 0x288);
  if (puVar1 != (undefined1 *)0x0) {
    for (iVar2 = *(int *)(param_1 + 0x28c); iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    operator_delete(*(void **)(param_1 + 0x288));
    *(undefined4 *)(param_1 + 0x288) = 0;
  }
  *(undefined4 *)(param_1 + 0x28c) = 0;
  return;
}



/* c05b17f0 FUN_c05b17f0 */

/* Boundary evidence: original MIPS .pdata c05b17f0..c05b180b. Semantic name remains unreviewed. */

void FUN_c05b17f0(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  return;
}



/* c05b180c FUN_c05b180c */

/* Boundary evidence: original MIPS .pdata c05b180c..c05b1827. Semantic name remains unreviewed. */

void FUN_c05b180c(LPCRITICAL_SECTION param_1)

{
  LeaveCriticalSection(param_1);
  return;
}



/* c05b1828 FUN_c05b1828 */

/* Boundary evidence: original MIPS .pdata c05b1828..c05b1897. Semantic name remains unreviewed. */

void FUN_c05b1828(LPCRITICAL_SECTION param_1)

{
  void *pvVar1;
  code *pcVar2;
  
  pvVar1 = FUN_c05b16cc((int)param_1);
  pcVar2 = (code *)param_1[0x1e].RecursionCount;
  if ((pcVar2 != (code *)0x0) && (pvVar1 != (void *)0x0)) {
    LeaveCriticalSection(param_1);
    (*pcVar2)(pvVar1,(undefined1 *)((int)&param_1[1].DebugInfo + 2));
    EnterCriticalSection(param_1);
  }
  operator_delete(pvVar1);
  return;
}



/* c05b1898 FUN_c05b1898 */

/* Boundary evidence: original MIPS .pdata c05b1898..c05b19b7. Semantic name remains unreviewed. */

void FUN_c05b1898(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  void *_Buf1;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x284);
  uVar3 = 0;
  if (iVar4 != 0) {
    _Buf1 = (void *)(param_1 + 0x248);
    do {
      iVar2 = memcmp(_Buf1,param_2,6);
      if (iVar2 == 0) {
        iVar2 = uVar3 * 6 + param_1;
        memmove((void *)(iVar2 + 0x248),(void *)(iVar2 + 0x24e),(iVar4 - uVar3) * 6 - 6);
        *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + -1;
        break;
      }
      uVar3 = uVar3 + 1;
      _Buf1 = (void *)((int)_Buf1 + 6);
    } while (uVar3 < *(uint *)(param_1 + 0x284));
  }
  memmove((void *)(param_1 + 0x24e),(undefined4 *)(param_1 + 0x248),0x36);
  *(undefined4 *)(param_1 + 0x248) = *param_2;
  uVar1 = *(undefined1 *)((int)param_2 + 5);
  *(undefined1 *)(param_1 + 0x24c) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)(param_1 + 0x24d) = uVar1;
  *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + 1;
  return;
}



/* c05b19b8 FUN_c05b19b8 */

/* Boundary evidence: original MIPS .pdata c05b19b8..c05b1a2b. Semantic name remains unreviewed. */

void FUN_c05b19b8(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  HANDLE *ppvVar2;
  
  iVar1 = 0x20;
  ppvVar2 = &param_1[0x1b].OwningThread;
  do {
    *(undefined1 *)ppvVar2 = 0;
    iVar1 = iVar1 + -1;
    ppvVar2 = (HANDLE *)((int)ppvVar2 + 1);
  } while (iVar1 != 0);
  FUN_c05b1798((int)param_1);
  operator_delete(param_1[0x16].LockSemaphore);
  operator_delete(param_1[0x1f].DebugInfo);
  DeleteCriticalSection(param_1);
  if (param_1[0x1e].OwningThread != (code *)0x0) {
    (*param_1[0x1e].OwningThread)(param_1[0x1e].LockSemaphore);
  }
  FUN_c05b4248((int *)(param_1 + 0x17));
  return;
}



/* c05b1a2c FUN_c05b1a2c */

undefined4 FUN_c05b1a2c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x290);
}



/* c05b1a34 FUN_c05b1a34 */

void FUN_c05b1a34(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x290) = param_2 & 7;
  return;
}



/* c05b1a40 FUN_c05b1a40 */

void FUN_c05b1a40(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x240) = param_2;
  return;
}



/* c05b1a48 FUN_c05b1a48 */

void FUN_c05b1a48(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x2d8) = param_2;
  *(undefined4 *)(param_1 + 0x2dc) = param_3;
  *(undefined4 *)(param_1 + 0x2e0) = param_4;
  return;
}



/* c05b1a58 FUN_c05b1a58 */

/* Boundary evidence: original MIPS .pdata c05b1a58..c05b1a73. Semantic name remains unreviewed. */

void FUN_c05b1a58(undefined4 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}



/* c05b1a74 FUN_c05b1a74 */

/* Boundary evidence: original MIPS .pdata c05b1a74..c05b1a8f. Semantic name remains unreviewed. */

void FUN_c05b1a74(int param_1,undefined4 *param_2)

{
  FUN_c05b1898(param_1,param_2);
  return;
}



/* c05b1a90 FUN_c05b1a90 */

/* Boundary evidence: original MIPS .pdata c05b1a90..c05b1aef. Semantic name remains unreviewed. */

undefined4 * FUN_c05b1a90(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  FUN_c05b4228(param_1);
  puVar1 = param_1 + 4;
  param_1[6] = param_2;
  *param_1 = &PTR_LAB_c05a193c;
  param_1[5] = puVar1;
  param_1[7] = 28800000;
  *puVar1 = puVar1;
  return param_1;
}



/* c05b1af0 FUN_c05b1af0 */

/* Boundary evidence: original MIPS .pdata c05b1af0..c05b1c73. Semantic name remains unreviewed. */

undefined4 FUN_c05b1af0(LPCRITICAL_SECTION param_1,undefined4 *param_2,void *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  void *_Src;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_70 [18];
  undefined1 auStack_5e [34];
  uint local_3c;
  uint local_28;
  
  local_28 = DAT_c05b62e4;
  uVar4 = 0;
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    EnterCriticalSection(param_1);
    _Src = (void *)FUN_c05b4160((int *)(param_1 + 0x17),param_2);
    if (_Src == (void *)0x0) {
      if (((param_1[0x1b].RecursionCount & 2U) != 0) &&
         (iVar3 = 0x48, param_1[0x17].LockSemaphore != &param_1[0x17].LockSemaphore)) {
        memcpy(local_70,(void *)param_1[0x17].SpinCount,0x48);
        memcpy(param_3,local_70,0x48);
        *(undefined4 *)((int)param_3 + 0xc) = *param_2;
        *(undefined2 *)((int)param_3 + 0x10) = *(undefined2 *)(param_2 + 1);
        FUN_c05b1508(param_2,&param_1->SpinCount,auStack_5e,local_3c,(void *)((int)param_3 + 0x38));
        uVar4 = 1;
        puVar2 = local_70;
        do {
          *puVar2 = 0;
          iVar3 = iVar3 + -1;
          puVar2 = puVar2 + 1;
        } while (iVar3 != 0);
      }
    }
    else {
      memcpy(param_3,_Src,0x48);
      uVar4 = 1;
    }
    LeaveCriticalSection(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  FUN_c05b4904(local_28);
  return uVar4;
}



/* c05b1c74 FUN_c05b1c74 */

/* Boundary evidence: original MIPS .pdata c05b1c74..c05b1ef7. Semantic name remains unreviewed. */

undefined4 FUN_c05b1c74(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  size_t *_Buf1;
  int iVar2;
  size_t *psVar3;
  size_t _Size;
  uint uVar4;
  size_t *psVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *_Dst;
  size_t *psVar9;
  uint uVar10;
  undefined1 *local_38;
  
  *param_2 = 0;
  uVar6 = *(uint *)(param_1 + 0x2b8);
  _Buf1 = operator_new(uVar6 * 0x16 + 8);
  if (_Buf1 == (size_t *)0x0) {
    uVar7 = 0xe;
  }
  else {
    _Buf1[1] = 0;
    psVar5 = _Buf1 + 2;
    uVar10 = 0;
    uVar4 = 0;
    if (uVar6 != 0) {
      _Dst = (undefined1 *)((int)_Buf1 + 0xe);
      iVar8 = 0;
      local_38 = _Dst;
      do {
        if (uVar10 < *(uint *)(param_1 + 0x21c)) {
          psVar3 = (size_t *)(*(int *)(param_1 + 0x220) + iVar8);
          uVar10 = uVar10 + 1;
          iVar8 = iVar8 + 0xc;
        }
        else {
          if (*(uint *)(param_1 + 0x284) <= uVar4) break;
          psVar9 = (size_t *)(uVar4 * 6 + param_1 + 0x248);
          do {
            psVar3 = psVar9;
            uVar4 = uVar4 + 1;
            psVar9 = (size_t *)((int)psVar3 + 6);
            iVar2 = FUN_c05b1640(param_1,psVar3);
            _Dst = local_38;
            if (iVar2 == 0) break;
            psVar3 = (size_t *)0x0;
          } while (uVar4 < *(uint *)(param_1 + 0x284));
        }
        if (psVar3 == (size_t *)0x0) break;
        *psVar5 = *psVar3;
        uVar1 = *(undefined1 *)((int)psVar3 + 5);
        *(char *)(psVar5 + 1) = (char)psVar3[1];
        *(undefined1 *)((int)psVar5 + 5) = uVar1;
        iVar2 = FUN_c05b4160((int *)(param_1 + 0x228),psVar3);
        if (iVar2 == 0) {
          if (((*(uint *)(param_1 + 0x290) & 2) != 0) && (*(uint *)(param_1 + 0x2b4) != 0)) {
            FUN_c05b1508(psVar5,(undefined4 *)(param_1 + 0x14),(void *)(param_1 + 0x294),
                         *(uint *)(param_1 + 0x2b4),_Dst);
            goto LAB_c05b1e14;
          }
        }
        else {
          memcpy(_Dst,(void *)(iVar2 + 0x38),0x10);
LAB_c05b1e14:
          _Dst = _Dst + 0x16;
          psVar5 = (size_t *)((int)psVar5 + 0x16);
          _Buf1[1] = _Buf1[1] + 1;
          local_38 = _Dst;
        }
      } while (_Buf1[1] < uVar6);
    }
    uVar7 = 0;
    _Size = _Buf1[1] * 0x16 + 8;
    *_Buf1 = _Size;
    if ((_Size != *(size_t *)(param_1 + 0x28c)) ||
       (iVar8 = memcmp(_Buf1,*(void **)(param_1 + 0x288),_Size), iVar8 != 0)) {
      FUN_c05b1798(param_1);
      *(size_t **)(param_1 + 0x288) = _Buf1;
      *(size_t *)(param_1 + 0x28c) = _Size;
      *param_2 = 1;
      _Buf1 = (size_t *)0x0;
    }
    psVar5 = _Buf1;
    if (_Buf1 != (size_t *)0x0) {
      for (; _Size != 0; _Size = _Size - 1) {
        *(undefined1 *)psVar5 = 0;
        psVar5 = (size_t *)((int)psVar5 + 1);
      }
      operator_delete(_Buf1);
    }
  }
  return uVar7;
}



/* c05b1ef8 FUN_c05b1ef8 */

/* Boundary evidence: original MIPS .pdata c05b1ef8..c05b202b. Semantic name remains unreviewed. */

undefined4 FUN_c05b1ef8(LPCRITICAL_SECTION param_1,HANDLE param_2,void *param_3,undefined1 *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  void *pvVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((HANDLE)0xc8 < param_2) {
    param_2 = (HANDLE)0xc8;
  }
  *param_4 = 0;
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0x57;
  }
  EnterCriticalSection(param_1);
  uVar4 = 0;
  if ((HANDLE)param_1[0x16].SpinCount < param_2) {
    operator_delete(param_1[0x16].LockSemaphore);
    param_1[0x16].OwningThread = (HANDLE)0x0;
    param_1[0x16].SpinCount = 0;
    if (param_2 < (HANDLE)0x15555556) {
      uVar3 = (int)param_2 * 0xc;
    }
    else {
      uVar3 = 0xffffffff;
    }
    pvVar2 = operator_new(uVar3);
    param_1[0x16].LockSemaphore = pvVar2;
    if (pvVar2 == (void *)0x0) {
      uVar4 = 0xe;
      goto LAB_c05b1fec;
    }
    param_1[0x16].SpinCount = (ULONG_PTR)param_2;
  }
  param_1[0x16].OwningThread = param_2;
  memcpy(param_1[0x16].LockSemaphore,param_3,(int)param_2 * 0xc);
  FUN_c05b1c74((int)param_1,param_4);
LAB_c05b1fec:
  LeaveCriticalSection(param_1);
  FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  return uVar4;
}



/* c05b202c FUN_c05b202c */

/* Boundary evidence: original MIPS .pdata c05b202c..c05b20a7. Semantic name remains unreviewed. */

void * FUN_c05b202c(LPCRITICAL_SECTION param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  void *pvVar2;
  
  pvVar2 = (void *)0x0;
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    EnterCriticalSection(param_1);
    pvVar2 = FUN_c05b16cc((int)param_1);
    LeaveCriticalSection(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return pvVar2;
}



/* c05b20a8 FUN_c05b20a8 */

/* Boundary evidence: original MIPS .pdata c05b20a8..c05b2103. Semantic name remains unreviewed. */

void FUN_c05b20a8(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  
  EnterCriticalSection(param_1);
  *(undefined1 *)&param_1[0x1e].SpinCount = 1;
  iVar1 = CTEStopTimer(&param_1[0x1d].LockCount);
  if (iVar1 != 0) {
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  param_1[0x1e].RecursionCount = 0;
  LeaveCriticalSection(param_1);
  return;
}



/* c05b2104 FUN_c05b2104 */

/* Boundary evidence: original MIPS .pdata c05b2104..c05b21c7. Semantic name remains unreviewed. */

undefined4 FUN_c05b2104(LPCRITICAL_SECTION param_1,void *param_2,uint param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  HANDLE *ppvVar3;
  undefined4 uVar4;
  
  uVar4 = 0x57;
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    if (param_3 < 0x21) {
      EnterCriticalSection(param_1);
      iVar2 = 0x20;
      ppvVar3 = &param_1[0x1b].OwningThread;
      do {
        *(undefined1 *)ppvVar3 = 0;
        iVar2 = iVar2 + -1;
        ppvVar3 = (HANDLE *)((int)ppvVar3 + 1);
      } while (iVar2 != 0);
      memcpy(&param_1[0x1b].OwningThread,param_2,param_3);
      param_1[0x1c].SpinCount = param_3;
      LeaveCriticalSection(param_1);
      uVar4 = 0;
    }
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return uVar4;
}



/* c05b21c8 FUN_c05b21c8 */

/* Boundary evidence: original MIPS .pdata c05b21c8..c05b224f. Semantic name remains unreviewed. */

void FUN_c05b21c8(LPCRITICAL_SECTION param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  char local_18 [8];
  
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    EnterCriticalSection(param_1);
    FUN_c05b1420((int *)(param_1 + 0x17));
    FUN_c05b1c74((int)param_1,local_18);
    if (local_18[0] != '\0') {
      FUN_c05b1828(param_1);
    }
    LeaveCriticalSection(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return;
}



/* c05b2250 FUN_c05b2250 */

/* Boundary evidence: original MIPS .pdata c05b2250..c05b233b. Semantic name remains unreviewed. */

undefined4 FUN_c05b2250(LPCRITICAL_SECTION param_1,wchar_t *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  size_t sVar3;
  PRTL_CRITICAL_SECTION_DEBUG _Dest;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    EnterCriticalSection(param_1);
    if ((param_1[0x1f].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) ||
       (iVar2 = wcscmp(param_2,(wchar_t *)param_1[0x1f].DebugInfo), iVar2 != 0)) {
      FUN_c05b1420((int *)(param_1 + 0x17));
      param_1[0x16].OwningThread = (HANDLE)0x0;
      param_1[0x1a].SpinCount = 0;
    }
    operator_delete(param_1[0x1f].DebugInfo);
    param_1[0x1f].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
    if (param_2 != (wchar_t *)0x0) {
      sVar3 = wcslen(param_2);
      _Dest = operator_new((sVar3 + 1) * 2);
      param_1[0x1f].DebugInfo = _Dest;
      if (_Dest == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        uVar4 = 0xe;
      }
      else {
        wcscpy((wchar_t *)_Dest,param_2);
      }
    }
    LeaveCriticalSection(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return uVar4;
}



/* c05b233c FUN_c05b233c */

/* Boundary evidence: original MIPS .pdata c05b233c..c05b23bf. Semantic name remains unreviewed. */

void FUN_c05b233c(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  char local_10 [8];
  
  if ((char)param_1[0x1e].SpinCount == '\0') {
    EnterCriticalSection(param_1);
    FUN_c05b1488((int *)(param_1 + 0x17));
    iVar1 = FUN_c05b1c74((int)param_1,local_10);
    if ((iVar1 == 0) && (local_10[0] != '\0')) {
      FUN_c05b1828(param_1);
    }
    FUN_c05b25a0((int)param_1);
    LeaveCriticalSection(param_1);
  }
  FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  return;
}



/* c05b23c0 FUN_c05b23c0 */

/* Boundary evidence: original MIPS .pdata c05b23c0..c05b2467. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c05b23c0(LPCRITICAL_SECTION param_1)

{
  FUN_c05b1a90(&param_1[0x17].DebugInfo,100);
  InitializeCriticalSection(param_1);
  memset(&param_1->SpinCount,0,6);
  param_1[0x16].OwningThread = (HANDLE)0x0;
  param_1[0x16].LockSemaphore = (HANDLE)0x0;
  param_1[0x16].SpinCount = 0;
  param_1[0x1a].SpinCount = 0;
  memset(&param_1[0x18].RecursionCount,0,0x3c);
  param_1[0x1b].LockCount = 0;
  param_1[0x1b].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  memset(&param_1[0x1b].OwningThread,0,0x20);
  param_1[0x1c].SpinCount = 0;
  param_1[0x1d].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[0x1b].RecursionCount = 0;
  CTEInitTimer(&param_1[0x1d].LockCount);
  param_1[0x1e].RecursionCount = 0;
  param_1[0x1e].OwningThread = (HANDLE)0x0;
  param_1[0x1e].LockSemaphore = (HANDLE)0x0;
  *(undefined1 *)&param_1[0x1e].SpinCount = 0;
  param_1[0x1f].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  return param_1;
}



/* c05b2468 FUN_c05b2468 */

/* Boundary evidence: original MIPS .pdata c05b2468..c05b2483. Semantic name remains unreviewed. */

void FUN_c05b2468(LPCRITICAL_SECTION param_1,void *param_2,uint param_3)

{
  FUN_c05b2104(param_1,param_2,param_3);
  return;
}



/* c05b2484 FUN_c05b2484 */

/* Boundary evidence: original MIPS .pdata c05b2484..c05b249f. Semantic name remains unreviewed. */

void FUN_c05b2484(LPCRITICAL_SECTION param_1)

{
  FUN_c05b21c8(param_1);
  return;
}



/* c05b24a0 FUN_c05b24a0 */

/* Boundary evidence: original MIPS .pdata c05b24a0..c05b24bb. Semantic name remains unreviewed. */

void FUN_c05b24a0(LPCRITICAL_SECTION param_1,wchar_t *param_2)

{
  FUN_c05b2250(param_1,param_2);
  return;
}



/* c05b24bc FUN_c05b24bc */

/* Boundary evidence: original MIPS .pdata c05b24bc..c05b24d7. Semantic name remains unreviewed. */

void FUN_c05b24bc(LPCRITICAL_SECTION param_1)

{
  FUN_c05b202c(param_1);
  return;
}



/* c05b24d8 FUN_c05b24d8 */

/* Boundary evidence: original MIPS .pdata c05b24d8..c05b2507. Semantic name remains unreviewed. */

bool FUN_c05b24d8(LPCRITICAL_SECTION param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c05b1af0(param_1,param_2,param_3);
  return iVar1 != 0;
}



/* c05b2508 FUN_c05b2508 */

/* Boundary evidence: original MIPS .pdata c05b2508..c05b2523. Semantic name remains unreviewed. */

void FUN_c05b2508(undefined4 param_1,LPCRITICAL_SECTION param_2)

{
  FUN_c05b233c(param_2);
  return;
}



/* c05b2524 FUN_c05b2524 */

/* Boundary evidence: original MIPS .pdata c05b2524..c05b259f. Semantic name remains unreviewed. */

void FUN_c05b2524(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x2e4) == '\0') {
    FUN_c05b438c(-0x3fa49c54,param_1);
    iVar1 = CTEStartTimer(param_1 + 700,param_2,FUN_c05b2508,param_1);
    if (iVar1 == 0) {
      FUN_c05b4428(&DAT_c05b63ac,param_1);
    }
  }
  return;
}



/* c05b25a0 FUN_c05b25a0 */

/* Boundary evidence: original MIPS .pdata c05b25a0..c05b25ff. Semantic name remains unreviewed. */

void FUN_c05b25a0(int param_1)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = CTEStopTimer(param_1 + 700);
  if (iVar1 != 0) {
    FUN_c05b4428(&DAT_c05b63ac,param_1);
  }
  iVar1 = FUN_c05b11dc(param_1 + 0x228,local_10);
  if (iVar1 != 0) {
    FUN_c05b2524(param_1,local_10[0]);
  }
  return;
}



/* c05b2600 FUN_c05b2600 */

/* Boundary evidence: original MIPS .pdata c05b2600..c05b271b. Semantic name remains unreviewed. */

int FUN_c05b2600(LPCRITICAL_SECTION param_1,int *param_2,void *param_3,uint param_4,
                undefined1 *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined1 auStack_38 [16];
  uint local_28;
  
  local_28 = DAT_c05b62e4;
  iVar2 = 0x57;
  *param_5 = 0;
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = FUN_c05b1508(param_2,&param_1->SpinCount,param_3,param_4,auStack_38);
    if (iVar2 == 0) {
      EnterCriticalSection(param_1);
      iVar2 = FUN_c05b125c((int *)(param_1 + 0x17),param_2,param_3,param_4,auStack_38);
      if (iVar2 == 0) {
        FUN_c05b1c74((int)param_1,param_5);
      }
      FUN_c05b25a0((int)param_1);
      LeaveCriticalSection(param_1);
    }
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  FUN_c05b4904(local_28);
  return iVar2;
}



/* c05b271c FUN_c05b271c */

/* Boundary evidence: original MIPS .pdata c05b271c..c05b27c7. Semantic name remains unreviewed. */

int FUN_c05b271c(LPCRITICAL_SECTION param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  iVar2 = 0x57;
  bVar1 = FUN_c05b438c(-0x3fa49c54,(int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    EnterCriticalSection(param_1);
    if (param_2 < 0x76724400) {
      param_1[0x18].LockCount = param_2;
      FUN_c05b1488((int *)(param_1 + 0x17));
      iVar2 = 0;
    }
    if (iVar2 == 0) {
      FUN_c05b25a0((int)param_1);
    }
    LeaveCriticalSection(param_1);
    FUN_c05b4428(&DAT_c05b63ac,(int)param_1);
  }
  return iVar2;
}



/* c05b27c8 FUN_c05b27c8 */

/* Boundary evidence: original MIPS .pdata c05b27c8..c05b27e3. Semantic name remains unreviewed. */

void FUN_c05b27c8(LPCRITICAL_SECTION param_1,uint param_2)

{
  FUN_c05b271c(param_1,param_2);
  return;
}



/* c05b27e4 FUN_c05b27e4 */

/* Boundary evidence: original MIPS .pdata c05b27e4..c05b2813. Semantic name remains unreviewed. */

void FUN_c05b27e4(LPCRITICAL_SECTION param_1,int *param_2,void *param_3,uint param_4,uint *param_5)

{
  byte local_10 [8];
  
  local_10[0] = 0;
  FUN_c05b2600(param_1,param_2,param_3,param_4,local_10);
  *param_5 = (uint)local_10[0];
  return;
}



/* c05b2814 FUN_c05b2814 */

/* Boundary evidence: original MIPS .pdata c05b2814..c05b288f. Semantic name remains unreviewed. */

undefined4 FUN_c05b2814(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) = 0x8002;
  memset((undefined4 *)(param_1 + 0x74),0,0xc4);
  *(undefined4 *)(param_1 + 0x74) = 0xc4;
  *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xa8) = 0xffffffff;
  if (*(uint **)(param_1 + 0x13c) != (uint *)0x0) {
    FUN_c05a4684(*(uint **)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x13c) = 0;
  }
  return 0;
}



/* c05b2890 FUN_c05b2890 */

/* Boundary evidence: original MIPS .pdata c05b2890..c05b2c5b. Semantic name remains unreviewed. */

DWORD FUN_c05b2890(HKEY param_1,int param_2,uint param_3,LPCWSTR param_4,uint *param_5,
                  size_t *param_6)

{
  BYTE *hMem;
  DWORD DVar1;
  HLOCAL _Dst;
  BOOL BVar2;
  SIZE_T SVar3;
  uint _Size;
  BYTE *pBVar4;
  size_t sVar5;
  DWORD DVar6;
  size_t local_48;
  DWORD local_44;
  DATA_BLOB local_40;
  DATA_BLOB local_38;
  uint local_30;
  
  local_30 = DAT_c05b62e4;
  memset((void *)param_6[1],0,*param_6);
  local_48 = *param_6;
  DVar1 = RegQueryValueExW(param_1,param_4,(LPDWORD)0x0,&local_44,(LPBYTE)param_6[1],&local_48);
  if (DVar1 != 0) goto LAB_c05b2c20;
  memset(param_5,0,0xc4);
  sVar5 = local_48;
  _Size = 0xc4;
  if (param_3 == 1) {
    if ((local_44 != 3) || (local_48 != 0x98)) {
      DVar1 = 0xd;
      goto LAB_c05b2b8c;
    }
    memcpy(param_5,(void *)param_6[1],0x98);
    if (*param_5 != 0x98) {
      DVar1 = 0xd;
      goto LAB_c05b2c20;
    }
    *param_5 = 0xc4;
    param_5[0x25] = *(byte *)((int)param_5 + 0xf) & 3;
    *(undefined1 *)((int)param_5 + 0xf) = 0;
    *(undefined1 *)((int)param_5 + 0xe) = 0;
LAB_c05b2ba0:
    if (((param_5[0x18] != 0) && (param_2 != 0)) && ((param_5[0xd] == 0 || ((param_5[1] & 1) != 0)))
       ) {
      DVar1 = 1;
      goto LAB_c05b2c20;
    }
  }
  else {
    if (param_3 == 2) {
      if ((local_44 == 3) && (local_48 == 0xb4)) {
        memcpy(param_5,(void *)param_6[1],0xb4);
        if (*param_5 != 0xb4) {
          DVar1 = 0xd;
        }
        *param_5 = 0xc4;
        goto LAB_c05b2b8c;
      }
      goto LAB_c05b2ba0;
    }
    if (param_3 < 3) {
LAB_c05b2980:
      DVar1 = 0xb;
      goto LAB_c05b2c20;
    }
    if (param_3 < 6) {
      _Size = 0xb4;
      param_5[0x2f] = 0;
    }
    else if (param_3 != 6) goto LAB_c05b2980;
    DVar1 = 0xd;
    if (((local_44 != 3) || (local_48 <= _Size)) ||
       (memcpy(param_5,(void *)param_6[1],_Size), *param_5 != _Size)) goto LAB_c05b2c20;
    SVar3 = param_5[0x2d];
    *param_5 = 0xc4;
    if (SVar3 != 0) {
      if (sVar5 <= SVar3 + _Size) goto LAB_c05b2c20;
      _Dst = FUN_c05a4228(SVar3);
      param_5[0x2e] = (uint)_Dst;
      if (_Dst == (HLOCAL)0x0) {
        param_5[0x2d] = 0;
        DVar1 = GetLastError();
        goto LAB_c05b2b8c;
      }
      memcpy(_Dst,(void *)(param_6[1] + _Size),param_5[0x2d]);
      _Size = param_5[0x2d] + _Size;
      sVar5 = local_48;
    }
    local_38.cbData = sVar5 - _Size;
    local_38.pbData = (BYTE *)(param_6[1] + _Size);
    local_40.cbData = 0;
    local_40.pbData = (BYTE *)0x0;
    BVar2 = CryptUnprotectData(&local_38,(LPWSTR *)0x0,(DATA_BLOB *)0x0,(PVOID)0x0,
                               (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000004,&local_40);
    pBVar4 = local_40.pbData;
    DVar6 = local_40.cbData;
    if ((BVar2 != 0) && (local_40.cbData == 0x20)) {
      memcpy(param_5 + 0x1d,local_40.pbData,0x20);
      DVar1 = 0;
    }
    hMem = pBVar4;
    if (pBVar4 != (BYTE *)0x0) {
      for (; DVar6 != 0; DVar6 = DVar6 - 1) {
        *pBVar4 = '\0';
        pBVar4 = pBVar4 + 1;
        hMem = local_40.pbData;
      }
      LocalFree(hMem);
    }
LAB_c05b2b8c:
    if (DVar1 != 0) goto LAB_c05b2c20;
    if (param_3 < 4) goto LAB_c05b2ba0;
  }
  if (param_3 < 5) {
    if (param_5[0xd] == 1) {
      param_5[0xd] = 0;
    }
    else {
      param_5[0xd] = 1;
    }
  }
  param_5[1] = param_5[1] & 0xfffffffb;
  DVar1 = FUN_c05a1a64(param_5,*param_5);
LAB_c05b2c20:
  FUN_c05b4904(local_30);
  return DVar1;
}



/* c05b2c5c FUN_c05b2c5c */

/* Boundary evidence: original MIPS .pdata c05b2c5c..c05b2e7f. Semantic name remains unreviewed. */

DWORD FUN_c05b2c5c(HKEY param_1,LPCWSTR param_2,void *param_3,DWORD *param_4)

{
  BOOL BVar1;
  HLOCAL pvVar2;
  uint uVar3;
  uint uVar4;
  DWORD DVar5;
  DATA_BLOB local_30;
  DATA_BLOB local_28;
  
  local_28.cbData = 0x20;
  local_28.pbData = (BYTE *)((int)param_3 + 0x74);
  local_30.cbData = 0;
  local_30.pbData = (BYTE *)0x0;
  DVar5 = 0;
  BVar1 = CryptProtectData(&local_28,L"",(DATA_BLOB *)0x0,(PVOID)0x0,
                           (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000004,&local_30);
  if (BVar1 == 0) {
    DVar5 = GetLastError();
  }
  uVar3 = *(int *)((int)param_3 + 0xb4) + 0xc4;
  if ((uVar3 < 0xc4) || (uVar4 = uVar3 + local_30.cbData, uVar4 < uVar3)) {
    if (*param_4 != 0) {
      FUN_c05a42b0((HLOCAL)param_4[1]);
      param_4[1] = 0;
      *param_4 = 0;
    }
    DVar5 = 0xd;
    uVar4 = 0xffffffff;
  }
  if (DVar5 == 0) {
    if (*param_4 < uVar4) {
      FUN_c05a42b0((HLOCAL)param_4[1]);
      *param_4 = 0;
      param_4[1] = 0;
      pvVar2 = FUN_c05a4228(uVar4);
      param_4[1] = (DWORD)pvVar2;
      if (pvVar2 == (HLOCAL)0x0) {
        DVar5 = GetLastError();
      }
      else {
        *param_4 = uVar4;
      }
      if (DVar5 != 0) goto LAB_c05b2e40;
    }
    if (((void *)param_4[1] != (void *)0x0) && (local_30.cbData != 0)) {
      memcpy((void *)param_4[1],param_3,0xc4);
      memcpy((void *)(param_4[1] + 0xc4),*(void **)((int)param_3 + 0xb8),
             *(size_t *)((int)param_3 + 0xb4));
      memset((void *)(param_4[1] + 0x74),0,0x20);
      memcpy((void *)(*(int *)((int)param_3 + 0xb4) + param_4[1] + 0xc4),local_30.pbData,
             local_30.cbData);
      DVar5 = RegSetValueExW(param_1,param_2,0,3,(BYTE *)param_4[1],*param_4);
    }
  }
LAB_c05b2e40:
  if (local_30.pbData != (BYTE *)0x0) {
    LocalFree(local_30.pbData);
  }
  return DVar5;
}



/* c05b2e80 FUN_c05b2e80 */

/* Boundary evidence: original MIPS .pdata c05b2e80..c05b2f7f. Semantic name remains unreviewed. */

undefined4 FUN_c05b2e80(undefined4 param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  HKEY local_20;
  DWORD local_1c [3];
  
  local_20 = (HKEY)0x0;
  local_1c[0] = 0x14;
  local_1c[1] = 3;
  if (param_2 != (LPBYTE)0x0) {
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\WZCSVC\\Parameters",0,0x20019,
                          &local_20);
    if ((LVar1 != 0) ||
       (LVar1 = RegQueryValueExW(local_20,L"ContextSettings",(LPDWORD)0x0,local_1c + 1,param_2,
                                 local_1c), LVar1 != 0)) {
      param_2[4] = '`';
      param_2[5] = 0xea;
      param_2[6] = '\0';
      param_2[7] = '\0';
      param_2[0xc] = '`';
      param_2[0xd] = 0xea;
      param_2[0xe] = '\0';
      param_2[0xf] = '\0';
      param_2[0] = 0xb8;
      param_2[1] = '\v';
      param_2[2] = '\0';
      param_2[3] = '\0';
      param_2[8] = 0xd0;
      param_2[9] = '\a';
      param_2[10] = '\0';
      param_2[0xb] = '\0';
      param_2[0x10] = 0x88;
      param_2[0x11] = '\x13';
      param_2[0x12] = '\0';
      param_2[0x13] = '\0';
    }
    if (local_20 != (HKEY)0x0) {
      RegCloseKey(local_20);
    }
    return 0;
  }
  return 0x57;
}



/* c05b2f80 FUN_c05b2f80 */

/* Boundary evidence: original MIPS .pdata c05b2f80..c05b306f. Semantic name remains unreviewed. */

LSTATUS FUN_c05b2f80(HKEY param_1,BYTE *param_2)

{
  bool bVar1;
  LSTATUS LVar2;
  HKEY local_res0 [4];
  
  bVar1 = false;
  if (param_2 == (BYTE *)0x0) {
    return 0x57;
  }
  local_res0[0] = param_1;
  if (param_1 == (HKEY)0x0) {
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\WZCSVC\\Parameters",0,0x2001b,
                          local_res0);
    if (LVar2 == 2) {
      return 0;
    }
    if (LVar2 != 0) {
      return LVar2;
    }
    bVar1 = true;
  }
  LVar2 = RegSetValueExW(local_res0[0],L"ContextSettings",0,3,param_2,0x14);
  if (bVar1) {
    RegCloseKey(local_res0[0]);
  }
  return LVar2;
}



/* c05b3070 FUN_c05b3070 */

/* Boundary evidence: original MIPS .pdata c05b3070..c05b3267. Semantic name remains unreviewed. */

DWORD FUN_c05b3070(HKEY param_1,uint param_2,int param_3,uint param_4,size_t *param_5)

{
  uint *_Src;
  DWORD DVar1;
  wchar_t *pszDest;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  wchar_t awStack_48 [12];
  uint local_30;
  
  local_30 = DAT_c05b62e4;
  if ((int)((ulonglong)param_2 * 0xc4 >> 0x20) != 0) {
    DVar1 = 0xd;
    goto LAB_c05b322c;
  }
  _Src = FUN_c05a4228((SIZE_T)((ulonglong)param_2 * 0xc4));
  if (_Src == (uint *)0x0) {
LAB_c05b30e8:
    DVar1 = GetLastError();
  }
  else {
    wcscpy(awStack_48,L"Static#----");
    pszDest = wcschr(awStack_48,L'-');
    uVar4 = 0;
    uVar3 = 0;
    puVar2 = _Src;
    if (param_2 != 0) {
      do {
        if (param_2 <= uVar3) break;
        StringCchPrintfW(pszDest,0xc - ((int)pszDest - (int)awStack_48 >> 1),L"%04x",uVar4);
        DVar1 = FUN_c05b2890(param_1,*(int *)(param_3 + 0x34),param_4,awStack_48,puVar2,param_5);
        if (DVar1 == 0) {
          uVar3 = uVar3 + 1;
          puVar2 = puVar2 + 0x31;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_2);
    }
    DVar1 = 0;
    if (*(HLOCAL *)(param_3 + 0x13c) != (HLOCAL)0x0) {
      FUN_c05a42b0(*(HLOCAL *)(param_3 + 0x13c));
    }
    if (uVar3 != 0) {
      puVar2 = FUN_c05a4228((uVar3 - 1) * 0xc4 + 0xcc);
      *(uint **)(param_3 + 0x13c) = puVar2;
      if (puVar2 == (uint *)0x0) goto LAB_c05b30e8;
      *puVar2 = uVar3;
      *(uint *)(*(int *)(param_3 + 0x13c) + 4) = uVar3;
      memcpy((void *)(*(int *)(param_3 + 0x13c) + 8),_Src,uVar3 * 0xc4);
    }
  }
  if (_Src != (uint *)0x0) {
    FUN_c05a42b0(_Src);
  }
LAB_c05b322c:
  FUN_c05b4904(local_30);
  return DVar1;
}



/* c05b3268 FUN_c05b3268 */

/* Boundary evidence: original MIPS .pdata c05b3268..c05b3477. Semantic name remains unreviewed. */

DWORD FUN_c05b3268(HKEY param_1,int param_2,DWORD *param_3)

{
  DWORD DVar1;
  wchar_t *pszDest;
  DWORD DVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_50 [2];
  wchar_t awStack_48 [12];
  uint local_30;
  
  local_30 = DAT_c05b62e4;
  DVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (LPDWORD)0x0,local_50,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (DVar1 == 0) {
    wcscpy(awStack_48,L"Static#----");
    pszDest = wcschr(awStack_48,L'-');
    puVar3 = *(uint **)(param_2 + 0x13c);
    uVar6 = 0;
    if ((puVar3 != (uint *)0x0) && (uVar7 = 0, *puVar3 != 0)) {
      uVar5 = 0;
      do {
        if (0xc3ff3b < uVar5) break;
        if ((*(uint *)((int)puVar3 + uVar5 + 0xc) & 4) == 0) {
          iVar4 = uVar5 + *(int *)(param_2 + 0x13c);
          *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & 0xfffeffff;
          StringCchPrintfW(pszDest,0xc - ((int)pszDest - (int)awStack_48 >> 1),L"%04x",uVar6);
          uVar6 = uVar6 + 1;
          DVar2 = FUN_c05b2c5c(param_1,awStack_48,(void *)(uVar5 + *(int *)(param_2 + 0x13c) + 8),
                               param_3);
          if ((DVar1 == 0) && (DVar2 != 0)) {
            DVar1 = DVar2;
          }
        }
        puVar3 = *(uint **)(param_2 + 0x13c);
        uVar7 = uVar7 + 1;
        uVar5 = uVar5 + 0xc4;
      } while (uVar7 < *puVar3);
    }
    do {
      StringCchPrintfW(pszDest,0xc - ((int)pszDest - (int)awStack_48 >> 1),L"%04x",uVar6);
      RegDeleteValueW(param_1,awStack_48);
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_50[0]);
  }
  FUN_c05b4904(local_30);
  return DVar1;
}



/* c05b3478 FUN_c05b3478 */

/* Boundary evidence: original MIPS .pdata c05b3478..c05b388f. Semantic name remains unreviewed. */

DWORD FUN_c05b3478(HKEY param_1,int param_2)

{
  size_t sVar1;
  STRSAFE_LPWSTR pszDest;
  DWORD DVar2;
  int iVar3;
  uint *_Dst;
  HKEY local_260;
  DWORD local_25c;
  uint local_258 [2];
  DWORD local_250;
  HLOCAL local_24c;
  DWORD local_248;
  uint local_244;
  uint local_240 [2];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c05b62e4;
  iVar3 = 0;
  local_260 = (HKEY)0x0;
  local_250 = 0;
  local_24c = (HLOCAL)0x0;
  if (*(wchar_t **)(param_2 + 0x34) != (wchar_t *)0x0) {
    sVar1 = wcslen(*(wchar_t **)(param_2 + 0x34));
    iVar3 = sVar1 + 1;
  }
  if (param_1 == (HKEY)0x0) {
    pszDest = FUN_c05a4228((iVar3 + 0x30U) * 2);
    if (pszDest != (STRSAFE_LPWSTR)0x0) {
      if (iVar3 == 0) {
        StringCchPrintfW(pszDest,0x30,L"%s\\%s",L"Software\\Microsoft\\WZCSVC\\Parameters",
                         L"Interfaces");
      }
      else {
        StringCchPrintfW(pszDest,iVar3 + 0x30U & 0x7fffffff,L"%s\\%s\\%s",
                         L"Software\\Microsoft\\WZCSVC\\Parameters",L"Interfaces",
                         *(undefined4 *)(param_2 + 0x34));
      }
      param_1 = (HKEY)0x80000002;
LAB_c05b35c8:
      DVar2 = RegOpenKeyExW(param_1,pszDest,0,0x20019,&local_260);
      if (DVar2 != 0) {
        if (DVar2 == 2) {
          DVar2 = 0;
        }
        goto LAB_c05b37a4;
      }
      DVar2 = RegQueryInfoKeyW(local_260,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPDWORD)0x0,(LPDWORD)0x0,local_240,(LPDWORD)0x0,&local_250,
                               (LPDWORD)0x0,(PFILETIME)0x0);
      if ((DVar2 != 0) || (local_250 == 0)) goto LAB_c05b37a4;
      local_24c = FUN_c05a4228(local_250);
      if (local_24c != (HLOCAL)0x0) {
        local_258[0] = 6;
        local_25c = 4;
        RegQueryValueExW(local_260,L"LayoutVersion",(LPDWORD)0x0,&local_248,(LPBYTE)local_258,
                         &local_25c);
        local_25c = 4;
        local_244 = 0;
        DVar2 = RegQueryValueExW(local_260,L"ControlFlags",(LPDWORD)0x0,&local_248,
                                 (LPBYTE)&local_244,&local_25c);
        if (DVar2 == 0) {
          if ((local_248 == 4) && (local_25c == 4)) {
            *(uint *)(param_2 + 0x20) = local_244 & 0xffff;
          }
        }
        else if (DVar2 != 2) goto LAB_c05b37a4;
        _Dst = (uint *)(param_2 + 0x74);
        memset(_Dst,0,0xc4);
        *_Dst = 0xc4;
        DVar2 = FUN_c05b2890(local_260,0,local_258[0],L"ActiveSettings",_Dst,&local_250);
        if ((DVar2 == 0) || (DVar2 == 2)) {
          DVar2 = FUN_c05b3070(local_260,local_240[0],param_2,local_258[0],&local_250);
        }
        goto LAB_c05b37a4;
      }
    }
  }
  else {
    pszDest = FUN_c05a4228((iVar3 + 0xbU) * 2);
    if (pszDest != (STRSAFE_LPWSTR)0x0) {
      if (iVar3 == 0) {
        StringCchPrintfW(pszDest,0xb,L"%s",L"Interfaces");
      }
      else {
        StringCchPrintfW(pszDest,iVar3 + 0xbU & 0x7fffffff,L"%s\\%s",L"Interfaces",
                         *(undefined4 *)(param_2 + 0x34));
      }
      goto LAB_c05b35c8;
    }
  }
  DVar2 = GetLastError();
LAB_c05b37a4:
  if (((local_260 != (HKEY)0x0) && (RegCloseKey(local_260), local_260 != (HKEY)0x0)) && (DVar2 != 0)
     ) {
    StringCchPrintfW(awStack_238,0x104,L"%s\\%s",L"Software\\Microsoft\\WZCSVC\\Parameters",
                     L"Interfaces");
    DVar2 = RegOpenKeyExW(param_1,awStack_238,0,0x20019,&local_260);
    if (DVar2 == 0) {
      RegDeleteKeyW(param_1,*(LPCWSTR *)(param_2 + 0x34));
      DVar2 = 0;
      RegCloseKey(local_260);
    }
  }
  FUN_c05a42b0(pszDest);
  FUN_c05a42b0(local_24c);
  FUN_c05b4904(local_30);
  return DVar2;
}



/* c05b3890 FUN_c05b3890 */

/* Boundary evidence: original MIPS .pdata c05b3890..c05b3b43. Semantic name remains unreviewed. */

DWORD FUN_c05b3890(HKEY param_1,int param_2)

{
  size_t sVar1;
  STRSAFE_LPWSTR pszDest;
  int iVar2;
  DWORD DVar3;
  HLOCAL pvVar4;
  HKEY local_38;
  uint local_34;
  BYTE local_30 [8];
  DWORD local_28;
  HLOCAL local_24;
  
  pvVar4 = (HLOCAL)0x0;
  local_38 = (HKEY)0x0;
  local_30[0] = '\x06';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  local_28 = 0;
  local_24 = (HLOCAL)0x0;
  pszDest = (STRSAFE_LPWSTR)0x0;
  iVar2 = 0;
  if (param_2 == 0) {
    DVar3 = 0x57;
    goto LAB_c05b3b0c;
  }
  if (*(wchar_t **)(param_2 + 0x34) != (wchar_t *)0x0) {
    sVar1 = wcslen(*(wchar_t **)(param_2 + 0x34));
    iVar2 = sVar1 + 1;
  }
  if (param_1 == (HKEY)0x0) {
    pszDest = FUN_c05a4228((iVar2 + 0x30U) * 2);
    if (pszDest != (STRSAFE_LPWSTR)0x0) {
      if (iVar2 == 0) {
        StringCchPrintfW(pszDest,0x30,L"%s\\%s",L"Software\\Microsoft\\WZCSVC\\Parameters",
                         L"Interfaces");
      }
      else {
        StringCchPrintfW(pszDest,iVar2 + 0x30U & 0x7fffffff,L"%s\\%s\\%s",
                         L"Software\\Microsoft\\WZCSVC\\Parameters",L"Interfaces",
                         *(undefined4 *)(param_2 + 0x34));
      }
      param_1 = (HKEY)0x80000002;
      goto LAB_c05b3a00;
    }
LAB_c05b3920:
    DVar3 = GetLastError();
  }
  else {
    pszDest = FUN_c05a4228((iVar2 + 0xbU) * 2);
    if (pszDest == (STRSAFE_LPWSTR)0x0) goto LAB_c05b3920;
    if (iVar2 == 0) {
      StringCchPrintfW(pszDest,0xb,L"%s",L"Interfaces");
    }
    else {
      StringCchPrintfW(pszDest,iVar2 + 0xbU & 0x7fffffff,L"%s\\%s",L"Interfaces",
                       *(undefined4 *)(param_2 + 0x34));
    }
LAB_c05b3a00:
    DVar3 = RegCreateKeyExW(param_1,pszDest,0,(LPWSTR)0x0,0,0x20007,(LPSECURITY_ATTRIBUTES)0x0,
                            &local_38,(LPDWORD)0x0);
    if (DVar3 == 0) {
      RegSetValueExW(local_38,L"LayoutVersion",0,4,local_30,4);
      local_34 = *(uint *)(param_2 + 0x20);
      if ((local_34 & 0x1000) == 0) {
        local_34 = local_34 & 0xffffdfff;
        RegSetValueExW(local_38,L"ControlFlags",0,4,(BYTE *)&local_34,4);
      }
      FUN_c05b2c5c(local_38,L"ActiveSettings",(void *)(param_2 + 0x74),&local_28);
      DVar3 = FUN_c05b3268(local_38,param_2,&local_28);
      pvVar4 = local_24;
    }
  }
  if (local_38 != (HKEY)0x0) {
    RegCloseKey(local_38);
  }
LAB_c05b3b0c:
  FUN_c05a42b0(pszDest);
  FUN_c05a42b0(pvVar4);
  return DVar3;
}



/* c05b3b44 FUN_c05b3b44 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c05b3b44..c05b3dab. Semantic name remains unreviewed. */

DWORD FUN_c05b3b44(wchar_t *param_1,int *param_2)

{
  undefined4 *puVar1;
  HANDLE hDevice;
  size_t sVar2;
  BOOL BVar3;
  int *piVar4;
  DWORD DVar5;
  int local_438;
  DWORD aDStack_434 [3];
  undefined4 local_428;
  wchar_t awStack_424 [506];
  uint local_30;
  
  local_30 = DAT_c05b62e4;
  if (param_2 == (int *)0x0) {
    DVar5 = 0x57;
    goto LAB_c05b3d70;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6308);
  DVar5 = FUN_c05af55c((int)DAT_c05b631c,param_1,&local_438);
  if (DVar5 == 0) {
    piVar4 = *(int **)(local_438 + 0x18);
    *piVar4 = *piVar4 + 1;
    *param_2 = piVar4[1];
  }
  else if (DVar5 == 2) {
    DVar5 = 8;
    puVar1 = FUN_c05a4228(8);
    if (puVar1 != (undefined4 *)0x0) {
      hDevice = CreateFileW(L"UIO1:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                            (HANDLE)0xffffffff);
      if ((hDevice != (HANDLE)0xffffffff) || (DVar5 = GetLastError(), DVar5 == 0)) {
        aDStack_434[1] = 1;
        sVar2 = wcslen(param_1);
        aDStack_434[2] = sVar2 << 1;
        local_428 = 0xc;
        wcscpy(awStack_424,param_1);
        BVar3 = DeviceIoControl(hDevice,0x120830,aDStack_434 + 1,aDStack_434[2] + 0xc,(LPVOID)0x0,0,
                                aDStack_434,(LPOVERLAPPED)0x0);
        if ((BVar3 != 0) || (DVar5 = GetLastError(), DVar5 == 0)) {
          puVar1[1] = hDevice;
          *puVar1 = 1;
          DVar5 = FUN_c05af150(DAT_c05b631c,param_1,puVar1,&DAT_c05b631c);
          if ((DVar5 == 0) && (DVar5 = FUN_c05ab138(hDevice,0xffff0001,0), DVar5 == 0)) {
            *param_2 = (int)hDevice;
            goto LAB_c05b3d68;
          }
        }
        if (hDevice != (HANDLE)0xffffffff) {
          CloseHandle(hDevice);
        }
      }
    }
    FUN_c05a42b0(puVar1);
  }
LAB_c05b3d68:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6308);
LAB_c05b3d70:
  FUN_c05b4904(local_30);
  return DVar5;
}



/* c05b3dac FUN_c05b3dac */

/* Boundary evidence: original MIPS .pdata c05b3dac..c05b3e87. Semantic name remains unreviewed. */

DWORD FUN_c05b3dac(wchar_t *param_1)

{
  DWORD DVar1;
  int *local_18;
  int *local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6308);
  DVar1 = FUN_c05af55c((int)DAT_c05b631c,param_1,(int *)&local_14);
  if (DVar1 == 0) {
    local_18 = (int *)local_14[6];
    *local_18 = *local_18 + -1;
    if ((*local_18 == 0) &&
       (DVar1 = FUN_c05af650(DAT_c05b631c,local_14,(int *)&local_18,&DAT_c05b631c), DVar1 == 0)) {
      FUN_c05ab138((HANDLE)local_18[1],0xffff0002,0);
      CloseHandle((HANDLE)local_18[1]);
      FUN_c05a42b0(local_18);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05b6308);
  return DVar1;
}



/* c05b3e88 FUN_c05b3e88 */

/* Boundary evidence: original MIPS .pdata c05b3e88..c05b3f47. Semantic name remains unreviewed. */

undefined4 FUN_c05b3e88(int param_1,uint param_2)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  if (param_2 < 0x10000) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (param_2 < 0x20000000) {
      uVar2 = param_2 << 3;
    }
    else {
      uVar2 = 0xffffffff;
    }
    pvVar1 = operator_new(uVar2);
    *(void **)(param_1 + 8) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      uVar6 = 0xe;
    }
    else {
      *(uint *)(param_1 + 4) = param_2;
      if (param_2 != 0) {
        iVar5 = 0;
        do {
          iVar3 = *(int *)(param_1 + 8) + iVar5;
          *(int *)(iVar3 + 4) = iVar3;
          puVar4 = (undefined4 *)(*(int *)(param_1 + 8) + iVar5);
          param_2 = param_2 - 1;
          iVar5 = iVar5 + 8;
          *puVar4 = puVar4[1];
        } while (param_2 != 0);
      }
    }
  }
  else {
    uVar6 = 0x57;
  }
  return uVar6;
}



/* c05b3f48 FUN_c05b3f48 */

/* Boundary evidence: original MIPS .pdata c05b3f48..c05b4003. Semantic name remains unreviewed. */

undefined4 FUN_c05b3f48(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  piVar1 = operator_new(0xc);
  if (piVar1 == (int *)0x0) {
    uVar5 = 0xe;
  }
  else {
    piVar1[2] = param_2;
    uVar2 = (**(code **)(*param_1 + 4))(param_1,param_2);
    if (param_1[1] == 0) {
      trap(0x1c00);
    }
    piVar4 = (int *)((uVar2 % (uint)param_1[1]) * 8 + param_1[2]);
    iVar3 = *piVar4;
    piVar1[1] = (int)piVar4;
    *piVar1 = iVar3;
    *(int **)(*piVar4 + 4) = piVar1;
    *piVar4 = (int)piVar1;
    param_1[3] = param_1[3] + 1;
  }
  return uVar5;
}



/* c05b4004 FUN_c05b4004 */

/* Boundary evidence: original MIPS .pdata c05b4004..c05b40b3. Semantic name remains unreviewed. */

int FUN_c05b4004(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  uVar1 = (**(code **)*param_1)(param_1,param_2);
  if (param_1[1] == 0) {
    trap(0x1c00);
  }
  piVar4 = (int *)((uVar1 % (uint)param_1[1]) * 8 + param_1[2]);
  piVar3 = (int *)*piVar4;
  while( true ) {
    if (piVar3 == piVar4) {
      return 0;
    }
    iVar2 = (**(code **)(*param_1 + 8))(param_1,param_2,piVar3[2]);
    if (iVar2 != 0) break;
    piVar3 = (int *)*piVar3;
  }
  return (int)piVar3;
}



/* c05b40b4 FUN_c05b40b4 */

/* Boundary evidence: original MIPS .pdata c05b40b4..c05b410f. Semantic name remains unreviewed. */

void FUN_c05b40b4(int *param_1,int *param_2)

{
  param_1[3] = param_1[3] + -1;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  (**(code **)(*param_1 + 0xc))(param_1,param_2[2]);
  operator_delete(param_2);
  return;
}



/* c05b4110 FUN_c05b4110 */

/* Boundary evidence: original MIPS .pdata c05b4110..c05b415f. Semantic name remains unreviewed. */

bool FUN_c05b4110(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_c05b4004(param_1,param_2);
  if (piVar1 != (int *)0x0) {
    FUN_c05b40b4(param_1,piVar1);
  }
  return piVar1 != (int *)0x0;
}



/* c05b4160 FUN_c05b4160 */

/* Boundary evidence: original MIPS .pdata c05b4160..c05b4193. Semantic name remains unreviewed. */

undefined4 FUN_c05b4160(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_c05b4004(param_1,param_2);
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 8);
  }
  return uVar2;
}



/* c05b4194 FUN_c05b4194 */

/* Boundary evidence: original MIPS .pdata c05b4194..c05b421f. Semantic name remains unreviewed. */

void FUN_c05b4194(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (param_1[1] != 0) {
    iVar4 = 0;
    do {
      iVar2 = param_1[2];
      piVar1 = *(int **)(iVar2 + iVar4);
      while (piVar1 != (int *)(iVar2 + iVar4)) {
        piVar3 = (int *)*piVar1;
        FUN_c05b40b4(param_1,piVar1);
        piVar1 = piVar3;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 8;
    } while (uVar5 < (uint)param_1[1]);
  }
  return;
}



/* c05b4220 FUN_c05b4220 */

undefined4 FUN_c05b4220(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* c05b4228 FUN_c05b4228 */

undefined4 * FUN_c05b4228(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_c05a1a28;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



/* c05b4248 FUN_c05b4248 */

/* Boundary evidence: original MIPS .pdata c05b4248..c05b4283. Semantic name remains unreviewed. */

void FUN_c05b4248(int *param_1)

{
  *param_1 = (int)&PTR_LAB_c05a1a28;
  FUN_c05b4194(param_1);
  operator_delete((void *)param_1[2]);
  return;
}



/* c05b4284 FUN_c05b4284 */

/* Boundary evidence: original MIPS .pdata c05b4284..c05b42c7. Semantic name remains unreviewed. */

undefined4 * FUN_c05b4284(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 1;
  *param_1 = &PTR_LAB_c05a1a38;
  param_1[2] = puVar1;
  *puVar1 = puVar1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return param_1;
}



/* c05b42c8 FUN_c05b42c8 */

/* Boundary evidence: original MIPS .pdata c05b42c8..c05b42ef. Semantic name remains unreviewed. */

void FUN_c05b42c8(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_c05a1a38;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return;
}



/* c05b42f0 FUN_c05b42f0 */

/* Boundary evidence: original MIPS .pdata c05b42f0..c05b438b. Semantic name remains unreviewed. */

int FUN_c05b42f0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = operator_new(0x10);
  if (piVar1 != (int *)0x0) {
    iVar3 = (**(code **)*param_1)(param_1);
    if (iVar3 == 0) {
      operator_delete(piVar1);
    }
    else {
      piVar2 = param_1 + 1;
      *piVar1 = *piVar2;
      piVar1[1] = (int)piVar2;
      *(int **)(*piVar2 + 4) = piVar1;
      *piVar2 = (int)piVar1;
      piVar1[2] = 1;
      piVar1[3] = iVar3;
    }
  }
  return iVar3;
}



/* c05b438c FUN_c05b438c */

/* Boundary evidence: original MIPS .pdata c05b438c..c05b4427. Semantic name remains unreviewed. */

bool FUN_c05b438c(int param_1,int param_2)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  for (piVar1 = *(int **)(param_1 + 4); piVar1 != (int *)(param_1 + 4); piVar1 = (int *)*piVar1) {
    if (piVar1[3] == param_2) goto LAB_c05b43e8;
  }
  piVar1 = (int *)0x0;
LAB_c05b43e8:
  if (piVar1 != (int *)0x0) {
    *(int *)((int)piVar1 + 8) = *(int *)((int)piVar1 + 8) + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return piVar1 != (int *)0x0;
}



/* c05b4428 FUN_c05b4428 */

/* Boundary evidence: original MIPS .pdata c05b4428..c05b44ff. Semantic name remains unreviewed. */

void FUN_c05b4428(int *param_1,int param_2)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  for (piVar1 = (int *)param_1[1]; piVar1 != param_1 + 1; piVar1 = (int *)*piVar1) {
    if (piVar1[3] == param_2) goto LAB_c05b4480;
  }
  piVar1 = (int *)0x0;
LAB_c05b4480:
  if (piVar1 != (int *)0x0) {
    if (piVar1[2] != 0) {
      piVar1[2] = piVar1[2] + -1;
    }
    if (piVar1[2] == 0) {
      *(int *)piVar1[1] = *piVar1;
      *(int *)(*piVar1 + 4) = piVar1[1];
      (**(code **)(*param_1 + 4))(param_1,param_2);
      operator_delete(piVar1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return;
}



/* c05b4500 FUN_c05b4500 */

/* Boundary evidence: original MIPS .pdata c05b4500..c05b451b. Semantic name remains unreviewed. */

void FUN_c05b4500(int *param_1,int param_2)

{
  FUN_c05b4428(param_1,param_2);
  return;
}



/* c05b479c entry */

/* Boundary evidence: original MIPS .pdata c05b479c..c05b480f. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c05b4810();
    FUN_c05b4dd4();
  }
  uVar1 = FUN_c05a9bb8(param_1,param_2);
  if (param_2 == 0) {
    FUN_c05b4d5c();
  }
  return uVar1;
}



/* c05b4810 FUN_c05b4810 */

/* Boundary evidence: original MIPS .pdata c05b4810..c05b4883. Semantic name remains unreviewed. */

void FUN_c05b4810(void)

{
  uint uVar1;
  
  if ((DAT_c05b62e4 == 0) || (DAT_c05b62e4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c05b62e4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c05b62e4 == 0) {
      DAT_c05b62e4 = 0xb064;
    }
  }
  DAT_c05b62e8 = ~DAT_c05b62e4;
  return;
}



/* c05b4884 FUN_c05b4884 */

/* Boundary evidence: original MIPS .pdata c05b4884..c05b48d7. Semantic name remains unreviewed. */

void FUN_c05b4884(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c05b4904(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c05b48d8 FUN_c05b48d8 */

/* Boundary evidence: original MIPS .pdata c05b48d8..c05b4903. Semantic name remains unreviewed. */

undefined4 FUN_c05b48d8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c05b4884(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c05b4904 FUN_c05b4904 */

/* Boundary evidence: original MIPS .pdata c05b4904..c05b494b. Semantic name remains unreviewed. */

void FUN_c05b4904(uint param_1)

{
  if ((param_1 == DAT_c05b62e4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c05b494c FUN_c05b494c */

/* Boundary evidence: original MIPS .pdata c05b494c..c05b49c7. Semantic name remains unreviewed. */

void FUN_c05b494c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c05b4884(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c05b49c8 FUN_c05b49c8 */

/* Boundary evidence: original MIPS .pdata c05b49c8..c05b4ad3. Semantic name remains unreviewed. */

undefined4 FUN_c05b49c8(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c05b6538;
  puVar3 = DAT_c05b6534;
  iVar4 = (int)DAT_c05b6534 - (int)DAT_c05b6538;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c05b4a0c:
    param_1 = 0;
  }
  else {
    if (DAT_c05b6538 != (void *)0x0) {
      uVar1 = _msize(DAT_c05b6538);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c05b4a80:
        if (pvVar2 == (void *)0x0) goto LAB_c05b4a0c;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c05b4a80;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c05b6534 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c05b6538 = pvVar2;
  }
  return param_1;
}



/* c05b4ad4 FUN_c05b4ad4 */

/* Boundary evidence: original MIPS .pdata c05b4ad4..c05b4bbf. Semantic name remains unreviewed. */

undefined4 FUN_c05b4ad4(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c05b653c == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c05b653c,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c05b653c == (LPCRITICAL_SECTION)0x0) goto LAB_c05b4b78;
  }
  EnterCriticalSection(DAT_c05b653c);
LAB_c05b4b78:
  uVar2 = FUN_c05b49c8(param_1);
  FUN_c05b4bc0();
  return uVar2;
}



/* c05b4bc0 FUN_c05b4bc0 */

/* Boundary evidence: original MIPS .pdata c05b4bc0..c05b4c0b. Semantic name remains unreviewed. */

void FUN_c05b4bc0(void)

{
  if (DAT_c05b653c != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c05b653c);
  }
  return;
}



/* c05b4c0c FUN_c05b4c0c */

/* Boundary evidence: original MIPS .pdata c05b4c0c..c05b4c3b. Semantic name remains unreviewed. */

undefined4 FUN_c05b4c0c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c05b4ad4(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c05b4c3c FUN_c05b4c3c */

/* Boundary evidence: original MIPS .pdata c05b4c3c..c05b4d5b. Semantic name remains unreviewed. */

void FUN_c05b4c3c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c05b63cc = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c05b6538;
    if (DAT_c05b6538 != (undefined4 *)0x0) {
      while (DAT_c05b6534 = DAT_c05b6534 + -1, _Memory <= DAT_c05b6534) {
        if ((code *)*DAT_c05b6534 != (code *)0x0) {
          (*(code *)*DAT_c05b6534)();
          _Memory = DAT_c05b6538;
        }
      }
      free(_Memory);
      DAT_c05b6534 = (undefined4 *)0x0;
      DAT_c05b6538 = (undefined4 *)0x0;
    }
    FUN_c05b4d80((undefined4 *)&DAT_c05a1014,(undefined4 *)&DAT_c05a1018);
  }
  FUN_c05b4d80((undefined4 *)&DAT_c05a101c,(undefined4 *)&DAT_c05a1020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c05b653c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c05b4d5c FUN_c05b4d5c */

/* Boundary evidence: original MIPS .pdata c05b4d5c..c05b4d7f. Semantic name remains unreviewed. */

void FUN_c05b4d5c(void)

{
  FUN_c05b4c3c(0,0,1);
  return;
}



/* c05b4d80 FUN_c05b4d80 */

/* Boundary evidence: original MIPS .pdata c05b4d80..c05b4dd3. Semantic name remains unreviewed. */

void FUN_c05b4d80(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c05b4dd4 FUN_c05b4dd4 */

/* Boundary evidence: original MIPS .pdata c05b4dd4..c05b4e0f. Semantic name remains unreviewed. */

void FUN_c05b4dd4(void)

{
  FUN_c05b4d80((undefined4 *)&DAT_c05a100c,(undefined4 *)&DAT_c05a1010);
  FUN_c05b4d80((undefined4 *)&DAT_c05a1000,(undefined4 *)&DAT_c05a1008);
  return;
}



/* c05b4fc0 FUN_c05b4fc0 */

/* Boundary evidence: original MIPS .pdata c05b4fc0..c05b5003. Semantic name remains unreviewed. */

void FUN_c05b4fc0(void)

{
  FUN_c05b4284(&DAT_c05b63ac);
  DAT_c05b63ac = &PTR_FUN_c05a17a8;
  FUN_c05b4c0c(FUN_c05b5004);
  return;
}



/* c05b5004 FUN_c05b5004 */

/* Boundary evidence: original MIPS .pdata c05b5004..c05b5023. Semantic name remains unreviewed. */

void FUN_c05b5004(void)

{
  FUN_c05b42c8(&DAT_c05b63ac);
  return;
}


