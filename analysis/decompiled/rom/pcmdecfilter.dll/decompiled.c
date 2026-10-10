/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40ac10e0 FUN_40ac10e0 */

void FUN_40ac10e0(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  
  *(undefined4 *)(param_6 + 0x15c) = 0;
  if (param_1 < 0x5dc1) {
    if (param_5 == 0) {
      iVar2 = *(int *)(param_6 + 0x13c);
      if (iVar2 == 0xfffe) {
        return;
      }
      if (iVar2 == 1) {
        return;
      }
    }
    else {
      iVar2 = *(int *)(param_6 + 0x13c);
    }
    *(undefined4 *)(param_6 + 0x158) = 1;
  }
  else {
    *(undefined4 *)(param_6 + 0x158) = 1;
    for (; 48000 < param_1; param_1 = param_1 >> 1) {
    }
    iVar2 = *(int *)(param_6 + 0x13c);
  }
  *(undefined4 *)(param_6 + 0x160) = 0x7fffffff;
  if (((iVar2 != 0x1523) && (iVar2 != 1)) && (iVar2 != 0xfffe)) {
    param_3 = param_3 << 3;
  }
  if (param_3 == 0) {
    if ((param_1 != 0) && (param_2 != 0)) {
      uVar1 = param_1 * param_2 >> 4;
      if (uVar1 == 0) {
        trap(7);
      }
      *(undefined4 *)(param_6 + 0x168) = 0;
      *(uint *)(param_6 + 0x164) = -(0x7fffffff / uVar1);
      return;
    }
    return;
  }
  uVar1 = param_1 * param_2 * param_3 >> 2;
  if (uVar1 == 0) {
    if (param_3 * -16000 == 0) {
      trap(7);
    }
    *(int *)(param_6 + 0x164) = 0x7fffffff / (param_3 * -16000);
  }
  else {
    if (uVar1 == 0) {
      trap(7);
    }
    *(uint *)(param_6 + 0x164) = -(0x7fffffff / uVar1);
  }
  if (param_4 == 0) {
    return;
  }
  *(uint *)(param_6 + 0x168) = param_4 * param_2 * param_1 >> 4;
  return;
}



/* 40ac1358 FUN_40ac1358 */

undefined4 FUN_40ac1358(undefined1 *param_1)

{
  char cVar1;
  
  *param_1 = 0x4e;
  if (((param_1[1] == 'O') && (param_1[2] == 'N')) && (param_1[3] == 'E')) {
    return 1;
  }
  *param_1 = 0x4e;
  *param_1 = 0x66;
  if (param_1[1] == 'l') {
    if (param_1[2] != '3') {
      *param_1 = 0x66;
      if ((param_1[2] == '6') && (param_1[3] == '4')) {
        return 3;
      }
      goto LAB_40ac138c;
    }
    if (param_1[3] == '2') {
      return 2;
    }
  }
  *param_1 = 0x66;
LAB_40ac138c:
  *param_1 = 0x61;
  if (((param_1[1] == 'l') && (param_1[2] == 'a')) && (param_1[3] == 'w')) {
    return 4;
  }
  *param_1 = 0x75;
  if (((param_1[1] == 'l') && (param_1[2] == 'a')) && (param_1[3] == 'w')) {
    return 5;
  }
  *param_1 = 0x41;
  if (((param_1[1] == 'L') && (param_1[2] == 'A')) && (param_1[3] == 'W')) {
    return 6;
  }
  *param_1 = 0x55;
  if (((param_1[1] == 'L') && (param_1[2] == 'A')) && (param_1[3] == 'W')) {
    return 7;
  }
  *param_1 = 0x46;
  if (((param_1[1] == 'L') && (param_1[2] == '3')) && (param_1[3] == '2')) {
    return 8;
  }
  *param_1 = 0x41;
  if (((param_1[1] == 'D') && (param_1[2] == 'P')) && (param_1[3] == '4')) {
    return 9;
  }
  *param_1 = 0x69;
  if (((param_1[1] == 'm') && (param_1[2] == 'a')) && (param_1[3] == '4')) {
    return 10;
  }
  *param_1 = 0x41;
  if ((param_1[1] == 'C') && (param_1[2] == 'E')) {
    if (param_1[3] == '2') {
      return 0xb;
    }
    *param_1 = 0x41;
    if (param_1[3] == '8') {
      return 0xc;
    }
  }
  else {
    *param_1 = 0x41;
  }
  *param_1 = 0x44;
  if (((param_1[1] == 'W') && (param_1[2] == 'V')) && (param_1[3] == 'W')) {
    return 0xd;
  }
  *param_1 = 0x4d;
  if ((param_1[1] == 'A') && (param_1[2] == 'C')) {
    if (param_1[3] == '3') {
      return 0xe;
    }
    *param_1 = 0x4d;
    if (param_1[3] == '6') {
      return 0xf;
    }
  }
  else {
    *param_1 = 0x4d;
  }
  *param_1 = 0x51;
  if (param_1[1] == 'c') {
    if ((param_1[2] == 'l') && (param_1[3] == 'p')) {
      return 0x10;
    }
    cVar1 = param_1[1];
    *param_1 = 0x51;
    *param_1 = 0x72;
  }
  else {
    if (((param_1[1] == 'D') && (param_1[2] == 'M')) && (param_1[3] == 'C')) {
      return 0x11;
    }
    cVar1 = param_1[1];
    *param_1 = 0x72;
  }
  if ((cVar1 != 't') || (param_1[2] != '2')) {
    *param_1 = 0x72;
    return 1;
  }
  if (param_1[3] == '4') {
    return 0x12;
  }
  *param_1 = 0x72;
  if (param_1[3] != '9') {
    return 1;
  }
  return 0x13;
}



/* 40ac1784 FUN_40ac1784 */

int FUN_40ac1784(undefined4 param_1,short *param_2,int *param_3,byte *param_4,int param_5,
                int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  
  iVar1 = 0xc00;
  if (param_5 < 0xc01) {
    iVar1 = param_5;
  }
  if (param_6 == 2) {
    iVar1 = (iVar1 / 2 & 0x7ffffff8U) * 2;
    if (param_7 == 0) {
      if (0 < iVar1) {
        iVar1 = (iVar1 - 1U >> 1) + 1;
        psVar3 = param_2 + iVar1;
        do {
          *param_2 = *(short *)(param_4 + 1);
          param_2 = param_2 + 1;
          param_4 = param_4 + 3;
        } while (param_2 != psVar3);
        goto LAB_40ac18fc;
      }
    }
    else if (0 < iVar1) {
      iVar1 = (iVar1 - 1U >> 1) + 1;
      psVar3 = param_2 + iVar1;
      do {
        *param_2 = CONCAT11(*param_4,param_4[1]);
        param_2 = param_2 + 1;
        param_4 = param_4 + 3;
      } while (param_2 != psVar3);
LAB_40ac18fc:
      *param_3 = iVar1 * 2;
      return iVar1 * 2;
    }
    iVar1 = 0;
    iVar2 = 0;
LAB_40ac1800:
    *param_3 = iVar2;
    return iVar1;
  }
  if (param_6 != 3) {
    if (param_6 != 1) {
      *param_3 = 0;
      return -1;
    }
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    else {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        *param_2 = (ushort)*param_4 * 0x100 + -0x8000;
        param_4 = param_4 + 1;
        param_2 = param_2 + 1;
      } while (iVar2 < iVar1);
    }
    iVar2 = iVar1 << 1;
    goto LAB_40ac1800;
  }
  iVar1 = (iVar1 / 3) * 3;
  if (param_7 == 0) {
    if (iVar1 < 1) goto LAB_40ac19b0;
    iVar1 = (iVar1 - 1U) / 3 + 1;
    psVar3 = param_2 + iVar1;
    do {
      *param_2 = *(short *)(param_4 + 1);
      param_2 = param_2 + 1;
      param_4 = param_4 + 3;
    } while (param_2 != psVar3);
  }
  else {
    if (iVar1 < 1) {
LAB_40ac19b0:
      iVar1 = 0;
      iVar2 = 0;
      goto LAB_40ac1890;
    }
    iVar1 = (iVar1 - 1U) / 3 + 1;
    psVar3 = param_2 + iVar1;
    do {
      *param_2 = CONCAT11(*param_4,param_4[1]);
      param_2 = param_2 + 1;
      param_4 = param_4 + 3;
    } while (param_2 != psVar3);
  }
  iVar2 = iVar1 * 2;
  iVar1 = iVar1 * 3;
LAB_40ac1890:
  *param_3 = iVar2;
  return iVar1;
}



/* 40ac1a00 FUN_40ac1a00 */

/* Boundary evidence: original MIPS .pdata 40ac1a00..40ac1aaf. Semantic name remains unreviewed. */

undefined4 FUN_40ac1a00(byte *param_1)

{
  uint uVar1;
  int aiStack_10 [3];
  
  uVar1 = (uint)param_1[1] << 8 | (uint)param_1[2] << 0x10 | (uint)*param_1 |
          (uint)param_1[3] << 0x18;
  if (uVar1 != 0x5453494c) {
    if (uVar1 < 0x5453494d) {
      if ((uVar1 == 0x4b4e554a) || (uVar1 == 0x4f464e49)) goto LAB_40ac1a90;
    }
    else if ((uVar1 == 0x584d505f) || (uVar1 == 0x6d796c6f)) goto LAB_40ac1a90;
    return 0;
  }
LAB_40ac1a90:
  FUN_40ac6ef0(aiStack_10,(int *)param_1,4);
  return 1;
}



/* 40ac1ab0 FUN_40ac1ab0 */

/* Boundary evidence: original MIPS .pdata 40ac1ab0..40ac2297. Semantic name remains unreviewed. */

undefined4 FUN_40ac1ab0(byte *param_1)

{
  uint uVar1;
  int aiStack_10 [3];
  
  uVar1 = (uint)param_1[1] << 8 | (uint)param_1[2] << 0x10 | (uint)*param_1 |
          (uint)param_1[3] << 0x18;
  if (uVar1 != 0x4f525049) {
    if (uVar1 < 0x4f52504a) {
      if (uVar1 != 0x46495641) {
        if (uVar1 < 0x46495642) {
          if (uVar1 != 0x41434f4c) {
            if (uVar1 < 0x41434f4d) {
              if (uVar1 != 0x34534149) {
                if (uVar1 < 0x3453414a) {
                  if (uVar1 != 0x32534149) {
                    if (uVar1 < 0x3253414a) {
                      if ((uVar1 != 0x31534149) && (uVar1 != 0x31545250)) {
                        return 0;
                      }
                    }
                    else if ((uVar1 != 0x32545250) && (uVar1 != 0x33534149)) {
                      return 0;
                    }
                  }
                }
                else if (uVar1 != 0x37534149) {
                  if (uVar1 < 0x3753414a) {
                    if ((uVar1 != 0x35534149) && (uVar1 != 0x36534149)) {
                      return 0;
                    }
                  }
                  else if ((uVar1 != 0x38534149) && (uVar1 != 0x39534149)) {
                    return 0;
                  }
                }
              }
            }
            else if (uVar1 != 0x44524349) {
              if (uVar1 < 0x4452434a) {
                if (uVar1 != 0x43525349) {
                  if (uVar1 < 0x4352534a) {
                    if ((uVar1 != 0x434e4549) && (uVar1 != 0x43524944)) {
                      return 0;
                    }
                  }
                  else if ((uVar1 != 0x44454d49) && (uVar1 != 0x444f4354)) {
                    return 0;
                  }
                }
              }
              else if (uVar1 != 0x44545349) {
                if (uVar1 < 0x4454534a) {
                  if ((uVar1 != 0x44525049) && (uVar1 != 0x44545249)) {
                    return 0;
                  }
                }
                else if (((uVar1 != 0x45504154) && (uVar1 != 0x45544152)) && (uVar1 != 0x45444f43))
                {
                  return 0;
                }
              }
            }
          }
        }
        else if (uVar1 != 0x4c524149) {
          if (uVar1 < 0x4c52414a) {
            if (uVar1 != 0x48435449) {
              if (uVar1 < 0x4843544a) {
                if (uVar1 != 0x474e4549) {
                  if (uVar1 < 0x474e454a) {
                    if ((uVar1 != 0x46525349) && (uVar1 != 0x474e414c)) {
                      return 0;
                    }
                  }
                  else if ((uVar1 != 0x474e4c49) && (uVar1 != 0x47524f54)) {
                    return 0;
                  }
                }
              }
              else if (uVar1 != 0x49534143) {
                if (uVar1 < 0x49534144) {
                  if ((uVar1 != 0x49424d49) && (uVar1 != 0x49504449)) {
                    return 0;
                  }
                }
                else if (((uVar1 != 0x4b435254) && (uVar1 != 0x4b4e554a)) && (uVar1 != 0x4a414d56))
                {
                  return 0;
                }
              }
            }
          }
          else if (uVar1 != 0x4d4d4f43) {
            if (uVar1 < 0x4d4d4f44) {
              if (uVar1 != 0x4d414e49) {
                if (uVar1 < 0x4d414e4a) {
                  if ((uVar1 != 0x4c525554) && (uVar1 != 0x4c544954)) {
                    return 0;
                  }
                }
                else if ((uVar1 != 0x4d494449) && (uVar1 != 0x4d495444)) {
                  return 0;
                }
              }
            }
            else if (uVar1 != 0x4e475349) {
              if (uVar1 < 0x4e47534a) {
                if ((uVar1 != 0x4d4e4349) && (uVar1 != 0x4e454c54)) {
                  return 0;
                }
              }
              else if (((uVar1 != 0x4f444354) && (uVar1 != 0x4f464e49)) && (uVar1 != 0x4e494d56)) {
                return 0;
              }
            }
          }
        }
      }
    }
    else if (uVar1 != 0x544d4349) {
      if (uVar1 < 0x544d434a) {
        if (uVar1 != 0x52545349) {
          if (uVar1 < 0x5254534a) {
            if (uVar1 != 0x50534944) {
              if (uVar1 < 0x50534945) {
                if (uVar1 != 0x504d5349) {
                  if (uVar1 < 0x504d534a) {
                    if ((uVar1 != 0x50485349) && (uVar1 != 0x50495249)) {
                      return 0;
                    }
                  }
                  else if ((uVar1 != 0x504f4349) && (uVar1 != 0x50524349)) {
                    return 0;
                  }
                }
              }
              else if (uVar1 != 0x52455654) {
                if (uVar1 < 0x52455655) {
                  if ((uVar1 != 0x52414559) && (uVar1 != 0x52415453)) {
                    return 0;
                  }
                }
                else if ((uVar1 != 0x524e4547) && (uVar1 != 0x524e4749)) {
                  return 0;
                }
              }
            }
          }
          else if (uVar1 != 0x53554d49) {
            if (uVar1 < 0x53554d4a) {
              if (uVar1 != 0x53445049) {
                if (uVar1 < 0x5344504a) {
                  if ((uVar1 != 0x53414349) && (uVar1 != 0x53444349)) {
                    return 0;
                  }
                }
                else if ((uVar1 != 0x53454741) && (uVar1 != 0x534d4349)) {
                  return 0;
                }
              }
            }
            else if (uVar1 != 0x54465349) {
              if (uVar1 < 0x5446534a) {
                if ((uVar1 != 0x54415453) && (uVar1 != 0x54444549)) {
                  return 0;
                }
              }
              else if (((uVar1 != 0x54494449) && (uVar1 != 0x54494d49)) && (uVar1 != 0x54474c49)) {
                return 0;
              }
            }
          }
        }
      }
      else if (uVar1 != 0x59454b49) {
        if (uVar1 < 0x59454b4a) {
          if (uVar1 != 0x55424d49) {
            if (uVar1 < 0x55424d4a) {
              if (uVar1 != 0x54524149) {
                if (uVar1 < 0x5452414a) {
                  if ((uVar1 != 0x544e4349) && (uVar1 != 0x544e4d43)) {
                    return 0;
                  }
                }
                else if ((uVar1 != 0x54534449) && (uVar1 != 0x5453494c)) {
                  return 0;
                }
              }
            }
            else if (uVar1 != 0x55494d49) {
              if (uVar1 < 0x55494d4a) {
                if ((uVar1 != 0x55474c49) && (uVar1 != 0x55494c49)) {
                  return 0;
                }
              }
              else if (((uVar1 != 0x55534249) && (uVar1 != 0x584d505f)) && (uVar1 != 0x554d5749)) {
                return 0;
              }
            }
          }
        }
        else if (uVar1 != 0x6d637565) {
          if (uVar1 < 0x6d637566) {
            if (uVar1 != 0x686c6d64) {
              if (uVar1 < 0x686c6d65) {
                if ((uVar1 != 0x61726f5a) && (uVar1 != 0x68697661)) {
                  return 0;
                }
              }
              else if ((uVar1 != 0x6c646d65) && (uVar1 != 0x6c657265)) {
                return 0;
              }
            }
          }
          else if (uVar1 != 0x72657665) {
            if (uVar1 < 0x72657666) {
              if ((uVar1 != 0x6d697465) && (uVar1 != 0x6d796c6f)) {
                return 0;
              }
            }
            else if (((uVar1 != 0x746e6d65) && (uVar1 != 0x74786562)) && (uVar1 != 0x726f6365)) {
              return 0;
            }
          }
        }
      }
    }
  }
  FUN_40ac6ef0(aiStack_10,(int *)param_1,4);
  return 1;
}



/* 40ac2298 FUN_40ac2298 */

/* Boundary evidence: original MIPS .pdata 40ac2298..40ac2e0f. Semantic name remains unreviewed. */

int * FUN_40ac2298(int param_1,int *param_2,int *param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar7 = *param_3 >> 1;
  iVar4 = *(int *)(param_1 + 0x80170);
  if (*(int *)(param_1 + 0x15c) == 0) {
    uVar8 = iVar7 / iVar4;
    if (iVar4 == 0) {
      trap(7);
    }
  }
  else {
    FUN_40ac6ef0((int *)(param_1 + (*(int *)(param_1 + 0x15c) + 0x200b4) * 2 + 4),param_2,iVar7 << 1
                );
    iVar4 = *(int *)(param_1 + 0x80170);
    iVar7 = iVar7 + *(int *)(param_1 + 0x15c);
    uVar8 = iVar7 / iVar4;
    if (iVar4 == 0) {
      trap(7);
    }
    *(undefined4 *)(param_1 + 0x15c) = 0;
    param_2 = (int *)(param_1 + 0x4016c);
  }
  uVar8 = uVar8 & 0xfffffc;
  switch(iVar4) {
  default:
    *(undefined4 *)(param_1 + 0x15c) = 0;
    return param_2;
  case 1:
    if (uVar8 == 0) goto LAB_40ac2408;
    iVar6 = 0;
    iVar4 = param_1;
    piVar5 = param_2;
    do {
      iVar6 = iVar6 + 1;
      *(short *)(iVar4 + 0x16c) = (short)*piVar5;
      *(short *)(iVar4 + 0x16e) = (short)*piVar5;
      piVar5 = (int *)((int)piVar5 + 2);
      iVar4 = iVar4 + 4;
    } while (iVar6 < (int)uVar8);
    break;
  case 3:
    if (uVar8 == 0) goto LAB_40ac2408;
    iVar6 = 0;
    piVar5 = param_2;
    iVar4 = param_1;
    do {
      *(ushort *)(iVar4 + 0x16c) =
           ((ushort)(((uint)(int)*(short *)((int)piVar5 + 2) >> 10) << 9) |
           (ushort)(((int)*(short *)((int)piVar5 + 2) & 0x3ffU) >> 1)) +
           ((ushort)(((uint)(int)(short)*piVar5 >> 10) << 9) |
           (ushort)(((int)(short)*piVar5 & 0x3ffU) >> 1));
      iVar6 = iVar6 + 1;
      *(ushort *)(iVar4 + 0x16e) =
           ((ushort)(((uint)(int)*(short *)((int)piVar5 + 2) >> 10) << 9) |
           (ushort)(((int)*(short *)((int)piVar5 + 2) & 0x3ffU) >> 1)) +
           ((ushort)(((uint)(int)(short)piVar5[1] >> 10) << 9) |
           (ushort)(((int)(short)piVar5[1] & 0x3ffU) >> 1));
      piVar5 = (int *)((int)piVar5 + 6);
      iVar4 = iVar4 + 4;
    } while (iVar6 < (int)uVar8);
    break;
  case 4:
    if (uVar8 == 0) goto LAB_40ac2408;
    iVar6 = 0;
    piVar5 = param_2;
    iVar4 = param_1;
    do {
      lVar1 = (ulonglong)(uint)(int)(short)piVar5[1] * 0x333333;
      lVar2 = (ulonglong)(uint)(int)(short)*piVar5 * 0x599999;
      *(ushort *)(iVar4 + 0x16c) =
           ((((short)piVar5[1] >> 0xf) * 0x3333 + (short)((ulonglong)lVar1 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar1 >> 0x10) >> 7) +
           ((((short)*piVar5 >> 0xf) * -0x6667 + (short)((ulonglong)lVar2 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar2 >> 0x10) >> 7);
      lVar1 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 6) * 0x333333;
      lVar2 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 2) * 0x599999;
      iVar6 = iVar6 + 1;
      *(ushort *)(iVar4 + 0x16e) =
           (((*(short *)((int)piVar5 + 6) >> 0xf) * 0x3333 + (short)((ulonglong)lVar1 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar1 >> 0x10) >> 7) +
           (((*(short *)((int)piVar5 + 2) >> 0xf) * -0x6667 + (short)((ulonglong)lVar2 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar2 >> 0x10) >> 7);
      piVar5 = piVar5 + 2;
      iVar4 = iVar4 + 4;
    } while (iVar6 < (int)uVar8);
    break;
  case 5:
    if (uVar8 == 0) goto LAB_40ac2408;
    iVar6 = 0;
    piVar5 = param_2;
    iVar4 = param_1;
    do {
      lVar1 = (ulonglong)(uint)(int)(short)piVar5[1] * 0x333333;
      *(ushort *)(iVar4 + 0x16c) =
           ((((short)piVar5[1] >> 0xf) * 0x3333 + (short)((ulonglong)lVar1 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar1 >> 0x10) >> 7) +
           ((ushort)(((uint)(int)(short)*piVar5 >> 10) << 9) |
           (ushort)(((int)(short)*piVar5 & 0x3ffU) >> 1)) +
           ((ushort)(((uint)(int)*(short *)((int)piVar5 + 2) >> 10) << 9) |
           (ushort)(((int)*(short *)((int)piVar5 + 2) & 0x3ffU) >> 1));
      lVar1 = (ulonglong)(uint)(int)(short)piVar5[2] * 0x333333;
      iVar6 = iVar6 + 1;
      *(ushort *)(iVar4 + 0x16e) =
           ((((short)piVar5[2] >> 0xf) * 0x3333 + (short)((ulonglong)lVar1 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar1 >> 0x10) >> 7) +
           ((ushort)(((uint)(int)(short)piVar5[1] >> 10) << 9) |
           (ushort)(((int)(short)piVar5[1] & 0x3ffU) >> 1)) +
           ((ushort)(((uint)(int)*(short *)((int)piVar5 + 2) >> 10) << 9) |
           (ushort)(((int)*(short *)((int)piVar5 + 2) & 0x3ffU) >> 1));
      piVar5 = (int *)((int)piVar5 + 10);
      iVar4 = iVar4 + 4;
    } while (iVar6 < (int)uVar8);
    break;
  case 6:
    if (uVar8 == 0) goto LAB_40ac2408;
    iVar6 = 0;
    piVar5 = param_2;
    iVar4 = param_1;
    do {
      lVar1 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 6) * 0x4ccccc;
      lVar2 = (ulonglong)(uint)(int)(short)piVar5[2] * 0x333333;
      *(ushort *)(iVar4 + 0x16c) =
           (((ushort)(((uint)(int)(short)piVar5[1] >> 10) << 9) |
            (ushort)(((int)(short)piVar5[1] & 0x3ffU) >> 1)) +
            ((ushort)(((uint)(int)(short)*piVar5 >> 10) << 9) |
            (ushort)(((int)(short)*piVar5 & 0x3ffU) >> 1)) +
           (((*(short *)((int)piVar5 + 6) >> 0xf) * -0x3334 + (short)((ulonglong)lVar1 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar1 >> 0x10) >> 7)) -
           ((((short)piVar5[2] >> 0xf) * 0x3333 + (short)((ulonglong)lVar2 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar2 >> 0x10) >> 7);
      lVar1 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 6) * 0x4ccccc;
      lVar2 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 10) * 0x333333;
      iVar6 = iVar6 + 1;
      *(ushort *)(iVar4 + 0x16e) =
           (((ushort)(((uint)(int)(short)piVar5[1] >> 10) << 9) |
            (ushort)(((int)(short)piVar5[1] & 0x3ffU) >> 1)) +
            ((ushort)(((uint)(int)*(short *)((int)piVar5 + 2) >> 10) << 9) |
            (ushort)(((int)*(short *)((int)piVar5 + 2) & 0x3ffU) >> 1)) +
           (((*(short *)((int)piVar5 + 6) >> 0xf) * -0x3334 + (short)((ulonglong)lVar1 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar1 >> 0x10) >> 7)) -
           (((*(short *)((int)piVar5 + 10) >> 0xf) * 0x3333 + (short)((ulonglong)lVar2 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar2 >> 0x10) >> 7);
      piVar5 = piVar5 + 3;
      iVar4 = iVar4 + 4;
    } while (iVar6 < (int)uVar8);
    break;
  case 7:
    if (uVar8 == 0) goto LAB_40ac2408;
    iVar6 = 0;
    piVar5 = param_2;
    iVar4 = param_1;
    do {
      lVar1 = (ulonglong)(uint)(int)(short)piVar5[1] * 0x333333;
      lVar2 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 10) * 0x199999;
      lVar3 = (ulonglong)(uint)(int)(short)piVar5[3] * 0x266666;
      *(ushort *)(iVar4 + 0x16c) =
           ((((short)piVar5[1] >> 0xf) * 0x3333 + (short)((ulonglong)lVar1 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar1 >> 0x10) >> 7) +
           ((ushort)(((uint)(int)(short)*piVar5 >> 10) << 9) |
           (ushort)(((int)(short)*piVar5 & 0x3ffU) >> 1)) +
           ((ushort)(((uint)(int)*(short *)((int)piVar5 + 2) >> 10) << 9) |
           (ushort)(((int)*(short *)((int)piVar5 + 2) & 0x3ffU) >> 1)) +
           (((*(short *)((int)piVar5 + 10) >> 0xf) * -0x6667 + (short)((ulonglong)lVar2 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar2 >> 0x10) >> 7) +
           ((((short)piVar5[3] >> 0xf) * 0x6666 + (short)((ulonglong)lVar3 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar3 >> 0x10) >> 7);
      lVar1 = (ulonglong)(uint)(int)(short)piVar5[2] * 0x333333;
      lVar2 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 10) * 0x199999;
      lVar3 = (ulonglong)(uint)(int)(short)piVar5[3] * 0x266666;
      iVar6 = iVar6 + 1;
      *(ushort *)(iVar4 + 0x16e) =
           ((((short)piVar5[2] >> 0xf) * 0x3333 + (short)((ulonglong)lVar1 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar1 >> 0x10) >> 7) +
           ((ushort)(((uint)(int)(short)piVar5[1] >> 10) << 9) |
           (ushort)(((int)(short)piVar5[1] & 0x3ffU) >> 1)) +
           ((ushort)(((uint)(int)*(short *)((int)piVar5 + 2) >> 10) << 9) |
           (ushort)(((int)*(short *)((int)piVar5 + 2) & 0x3ffU) >> 1)) +
           (((*(short *)((int)piVar5 + 10) >> 0xf) * -0x6667 + (short)((ulonglong)lVar2 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar2 >> 0x10) >> 7) +
           ((((short)piVar5[3] >> 0xf) * 0x6666 + (short)((ulonglong)lVar3 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar3 >> 0x10) >> 7);
      piVar5 = (int *)((int)piVar5 + 0xe);
      iVar4 = iVar4 + 4;
    } while (iVar6 < (int)uVar8);
    break;
  case 8:
    if (uVar8 == 0) goto LAB_40ac2408;
    iVar6 = 0;
    piVar5 = param_2;
    iVar4 = param_1;
    do {
      lVar1 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 6) * 0x199999;
      lVar2 = (ulonglong)(uint)(int)(short)piVar5[3] * 0x266666;
      lVar3 = (ulonglong)(uint)(int)(short)piVar5[2] * 0x199999;
      *(ushort *)(iVar4 + 0x16c) =
           (((ushort)(((uint)(int)(short)piVar5[1] >> 10) << 9) |
            (ushort)(((int)(short)piVar5[1] & 0x3ffU) >> 1)) +
            ((ushort)(((uint)(int)(short)*piVar5 >> 10) << 9) |
            (ushort)(((int)(short)*piVar5 & 0x3ffU) >> 1)) +
            (((*(short *)((int)piVar5 + 6) >> 0xf) * -0x6667 + (short)((ulonglong)lVar1 >> 0x20)) *
             0x200 | (ushort)((ulonglong)lVar1 >> 0x10) >> 7) +
           ((((short)piVar5[3] >> 0xf) * 0x6666 + (short)((ulonglong)lVar2 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar2 >> 0x10) >> 7)) -
           ((((short)piVar5[2] >> 0xf) * -0x6667 + (short)((ulonglong)lVar3 >> 0x20)) * 0x200 |
           (ushort)((ulonglong)lVar3 >> 0x10) >> 7);
      lVar1 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 6) * 0x199999;
      lVar2 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 0xe) * 0x266666;
      lVar3 = (ulonglong)(uint)(int)*(short *)((int)piVar5 + 10) * 0x199999;
      iVar6 = iVar6 + 1;
      *(ushort *)(iVar4 + 0x16e) =
           (((ushort)(((uint)(int)(short)piVar5[1] >> 10) << 9) |
            (ushort)(((int)(short)piVar5[1] & 0x3ffU) >> 1)) +
            ((ushort)(((uint)(int)*(short *)((int)piVar5 + 2) >> 10) << 9) |
            (ushort)(((int)*(short *)((int)piVar5 + 2) & 0x3ffU) >> 1)) +
            (((*(short *)((int)piVar5 + 6) >> 0xf) * -0x6667 + (short)((ulonglong)lVar1 >> 0x20)) *
             0x200 | (ushort)((ulonglong)lVar1 >> 0x10) >> 7) +
           (((*(short *)((int)piVar5 + 0xe) >> 0xf) * 0x6666 + (short)((ulonglong)lVar2 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar2 >> 0x10) >> 7)) -
           (((*(short *)((int)piVar5 + 10) >> 0xf) * -0x6667 + (short)((ulonglong)lVar3 >> 0x20)) *
            0x200 | (ushort)((ulonglong)lVar3 >> 0x10) >> 7);
      piVar5 = (int *)((int)piVar5 + 0xe);
      iVar4 = iVar4 + 4;
    } while (iVar6 < (int)uVar8);
  }
  iVar4 = *(int *)(param_1 + 0x80170);
LAB_40ac2408:
  iVar4 = iVar7 - iVar4 * uVar8;
  *(int *)(param_1 + 0x15c) = iVar4;
  if (0 < iVar4) {
    FUN_40ac6ef0((int *)(param_1 + 0x4016c),(int *)((int)param_2 + (iVar7 - iVar4) * 2),iVar4 * 2);
  }
  *param_3 = uVar8 << 2;
  return (int *)(param_1 + 0x16c);
}



/* 40ac2e10 FUN_40ac2e10 */

/* Boundary evidence: original MIPS .pdata 40ac2e10..40ac2e9f. Semantic name remains unreviewed. */

void FUN_40ac2e10(int *param_1,int *param_2)

{
  int *piVar1;
  
  *param_2 = param_2[0x48];
  param_2[1] = param_2[0x49];
  param_2[4] = param_2[0x4b];
  param_2[2] = param_2[0x4a];
  param_2[5] = param_2[0x4c];
  param_2[7] = param_2[0x4f];
  param_2[3] = 2;
  piVar1 = (int *)FUN_40ac992c(s_PCM_Audio_Decoder_40ad60e4);
  FUN_40ac6ef0(param_2 + 8,piVar1,4);
  FUN_40ac6ef0(param_1,param_2,0x120);
  return;
}



/* 40ac2ea0 FUN_40ac2ea0 */

/* Boundary evidence: original MIPS .pdata 40ac2ea0..40ac3153. Semantic name remains unreviewed. */

void FUN_40ac2ea0(ushort *param_1,uint *param_2,uint *param_3,va_list param_4,byte *param_5)

{
  undefined2 *puVar1;
  uint *puVar2;
  uint uVar3;
  va_list pcVar4;
  int iVar5;
  
  puVar2 = param_2;
  pcVar4 = param_4;
  if (param_3 < param_4 + -7) {
    puVar2 = param_3;
    puVar1 = FUN_40ac992c(s_PCMDEC_ERROR__input_MPEG_LPCM_Bu_40ad60f8);
    FUN_40ac98dc((size_t)puVar1,param_3,puVar2,pcVar4);
    puVar2 = param_3;
  }
  uVar3 = (uint)(param_4 + -7) & 0x7ffffffe;
  *param_2 = uVar3;
  if (param_5[6] != 0x80) {
    puVar1 = FUN_40ac992c(s_PCMDEC_MPEG_LPCM_missing_header_40ad612c);
    FUN_40ac98dc((size_t)puVar1,puVar2,uVar3,pcVar4);
    puVar1 = FUN_40ac992c(s__4x__2x__2x__2x__2x__2x__2x__2x___40ad6150);
    FUN_40ac98dc((size_t)puVar1,param_4,(uint)*param_5,(va_list)(uint)param_5[1]);
    return;
  }
  if (0x2000 < uVar3) {
    puVar1 = FUN_40ac992c(s_PCMDEC_ERROR_MPEG_LPCM_Buffer_to_40ad61d4);
    FUN_40ac98dc((size_t)puVar1,*param_2,uVar3,pcVar4);
    return;
  }
  if (uVar3 != 0) {
    FUN_40ac6ef0((int *)param_1,(int *)(param_5 + 7),uVar3);
    uVar3 = *param_2;
    iVar5 = 0;
    if (0 < (int)uVar3 >> 1) {
      do {
        iVar5 = iVar5 + 1;
        *param_1 = *param_1 << 8 | *param_1 >> 8;
        param_1 = param_1 + 1;
      } while (iVar5 < (int)uVar3 >> 1);
      return;
    }
  }
  return;
}



/* 40ac3154 FUN_40ac3154 */

/* Boundary evidence: original MIPS .pdata 40ac3154..40ac3a8f. Semantic name remains unreviewed. */

undefined4 FUN_40ac3154(int param_1,int param_2,undefined2 *param_3,va_list param_4)

{
  char *pcVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 *puVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 *puVar10;
  int iVar11;
  ushort *puVar12;
  va_list pcVar13;
  byte *pbVar14;
  int iVar15;
  short *psVar16;
  short *psVar17;
  short *psVar18;
  va_list pcVar19;
  va_list pcVar20;
  int iVar21;
  int iVar22;
  short *psVar23;
  short *psVar24;
  short *psVar25;
  ushort local_90 [4];
  int local_88;
  int local_84;
  va_list local_80;
  int local_7c;
  va_list local_78;
  short *local_74;
  short *local_70;
  short *local_6c;
  short *local_68;
  short *local_64;
  short *local_60;
  int local_5c;
  int local_58;
  short *local_54;
  short *local_50;
  int local_4c;
  int local_48;
  short *local_44;
  short *local_40;
  short *local_3c;
  short *local_38;
  short *local_34;
  int local_30;
  ushort *local_2c;
  
  if (0 < param_1) {
    puVar12 = local_90;
    iVar11 = 0;
    puVar10 = param_3;
    pcVar13 = param_4;
    do {
      *(undefined2 *)pcVar13 = *puVar10;
      pbVar14 = (byte *)(puVar10 + 1);
      uVar3 = (ushort)*pbVar14;
      iVar11 = iVar11 + 1;
      pcVar1 = (char *)((int)puVar10 + 3);
      puVar10 = puVar10 + 2;
      pcVar13 = pcVar13 + 2;
      if (0x57 < *pbVar14) {
        uVar3 = 0x58;
      }
      if (*pcVar1 != '\0') {
        puVar4 = FUN_40ac992c(s_ADPCM_3_Synchronisation_error_40ad6200);
        FUN_40ac98dc((size_t)puVar4,puVar10,iVar11,param_4);
        return 0;
      }
      *puVar12 = uVar3;
      puVar12 = puVar12 + 1;
    } while (iVar11 < param_1);
  }
  if (param_1 < param_2) {
    local_4c = param_1 * 2;
    local_3c = (short *)(param_4 + param_1 * 6);
    local_7c = param_1 * 0xc;
    local_84 = param_1 * 0xe;
    iVar15 = param_1 * 4;
    local_70 = (short *)(param_4 + param_1 * 10);
    iVar11 = param_1 * 0x10;
    local_68 = (short *)(param_4 + param_1 * 8);
    local_48 = param_1 * 9;
    local_5c = param_1 * 8;
    local_40 = (short *)(param_4 + iVar15);
    local_88 = param_1 << 4;
    local_54 = (short *)(param_4 + iVar15);
    local_80 = param_4 + param_1 * 0xe;
    local_44 = (short *)(param_4 + param_1 * 2);
    local_78 = param_4 + param_1 * 0xc;
    local_50 = (short *)(param_4 + param_1 * 6);
    local_6c = (short *)(param_4 + param_1 * 8);
    local_74 = (short *)(param_4 + param_1 * 10);
    local_58 = 0;
    local_2c = local_90 + param_1;
    do {
      if (0 < param_1) {
        psVar18 = (short *)(param_4 + local_58);
        pcVar19 = param_4 + local_4c + local_58;
        puVar12 = local_90;
        local_30 = local_7c;
        local_34 = local_74;
        local_38 = local_6c;
        local_60 = local_3c;
        local_64 = local_40;
        psVar16 = local_54;
        psVar17 = local_70;
        pcVar13 = local_78;
        pcVar20 = local_80;
        iVar21 = local_84;
        iVar22 = local_88;
        psVar23 = local_50;
        psVar24 = local_68;
        psVar25 = local_44;
        do {
          bVar2 = *(byte *)((int)param_3 + iVar15);
          iVar5 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[(short)*puVar12];
          if (iVar5 < 0) {
            iVar5 = iVar5 + 7;
          }
          iVar7 = iVar5 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar7 = -(iVar5 >> 3);
          }
          iVar7 = iVar7 + *psVar18;
          if (iVar7 < 0x8000) {
            iVar5 = -0x8000;
            if (-0x8001 < iVar7) {
              iVar5 = iVar7;
            }
            uVar9 = (undefined2)iVar5;
          }
          else {
            uVar9 = 0x7fff;
          }
          iVar5 = (int)(short)*puVar12 + *(int *)(&DAT_40ad2060 + (bVar2 & 0xf) * 4);
          *(undefined2 *)pcVar19 = uVar9;
          if (iVar5 < 0x59) {
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar5 = (int)(short)iVar5;
          }
          else {
            iVar5 = 0x58;
          }
          bVar2 = *(byte *)((int)param_3 + iVar15) >> 4;
          iVar7 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar5];
          if (iVar7 < 0) {
            iVar7 = iVar7 + 7;
          }
          iVar8 = iVar7 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar8 = -(iVar7 >> 3);
          }
          iVar8 = iVar8 + *psVar25;
          if (iVar8 < 0x8000) {
            iVar7 = -0x8000;
            if (-0x8001 < iVar8) {
              iVar7 = iVar8;
            }
            sVar6 = (short)iVar7;
          }
          else {
            sVar6 = 0x7fff;
          }
          iVar5 = iVar5 + *(int *)(&DAT_40ad2060 + (uint)bVar2 * 4);
          *psVar16 = sVar6;
          if (iVar5 < 0x59) {
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar5 = (int)(short)iVar5;
          }
          else {
            iVar5 = 0x58;
          }
          pbVar14 = (byte *)((int)param_3 + iVar15 + 1);
          bVar2 = *pbVar14;
          iVar7 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar5];
          if (iVar7 < 0) {
            iVar7 = iVar7 + 7;
          }
          iVar8 = iVar7 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar8 = -(iVar7 >> 3);
          }
          iVar8 = iVar8 + *local_64;
          if (iVar8 < 0x8000) {
            iVar7 = -0x8000;
            if (-0x8001 < iVar8) {
              iVar7 = iVar8;
            }
            sVar6 = (short)iVar7;
          }
          else {
            sVar6 = 0x7fff;
          }
          iVar5 = iVar5 + *(int *)(&DAT_40ad2060 + (bVar2 & 0xf) * 4);
          *psVar23 = sVar6;
          if (iVar5 < 0x59) {
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar5 = (int)(short)iVar5;
          }
          else {
            iVar5 = 0x58;
          }
          bVar2 = *pbVar14 >> 4;
          iVar7 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar5];
          if (iVar7 < 0) {
            iVar7 = iVar7 + 7;
          }
          iVar8 = iVar7 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar8 = -(iVar7 >> 3);
          }
          iVar8 = iVar8 + *local_60;
          if (iVar8 < 0x8000) {
            iVar7 = -0x8000;
            if (-0x8001 < iVar8) {
              iVar7 = iVar8;
            }
            sVar6 = (short)iVar7;
          }
          else {
            sVar6 = 0x7fff;
          }
          iVar5 = iVar5 + *(int *)(&DAT_40ad2060 + (uint)bVar2 * 4);
          *psVar24 = sVar6;
          if (iVar5 < 0x59) {
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar5 = (int)(short)iVar5;
          }
          else {
            iVar5 = 0x58;
          }
          pbVar14 = (byte *)((int)param_3 + iVar15 + 2);
          bVar2 = *pbVar14;
          iVar7 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar5];
          if (iVar7 < 0) {
            iVar7 = iVar7 + 7;
          }
          iVar8 = iVar7 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar8 = -(iVar7 >> 3);
          }
          iVar8 = iVar8 + *local_38;
          if (iVar8 < 0x8000) {
            iVar7 = -0x8000;
            if (-0x8001 < iVar8) {
              iVar7 = iVar8;
            }
            sVar6 = (short)iVar7;
          }
          else {
            sVar6 = 0x7fff;
          }
          iVar5 = iVar5 + *(int *)(&DAT_40ad2060 + (bVar2 & 0xf) * 4);
          *psVar17 = sVar6;
          if (iVar5 < 0x59) {
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar5 = (int)(short)iVar5;
          }
          else {
            iVar5 = 0x58;
          }
          bVar2 = *pbVar14 >> 4;
          iVar7 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar5];
          if (iVar7 < 0) {
            iVar7 = iVar7 + 7;
          }
          iVar8 = iVar7 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar8 = -(iVar7 >> 3);
          }
          iVar8 = iVar8 + *local_34;
          if (iVar8 < 0x8000) {
            iVar7 = -0x8000;
            if (-0x8001 < iVar8) {
              iVar7 = iVar8;
            }
            uVar9 = (undefined2)iVar7;
          }
          else {
            uVar9 = 0x7fff;
          }
          iVar5 = iVar5 + *(int *)(&DAT_40ad2060 + (uint)bVar2 * 4);
          *(undefined2 *)pcVar13 = uVar9;
          if (iVar5 < 0x59) {
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar5 = (int)(short)iVar5;
          }
          else {
            iVar5 = 0x58;
          }
          pbVar14 = (byte *)((int)param_3 + iVar15 + 3);
          bVar2 = *pbVar14;
          iVar7 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar5];
          if (iVar7 < 0) {
            iVar7 = iVar7 + 7;
          }
          iVar8 = iVar7 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar8 = -(iVar7 >> 3);
          }
          iVar8 = iVar8 + *(short *)(param_4 + local_30);
          if (iVar8 < 0x8000) {
            iVar7 = -0x8000;
            if (-0x8001 < iVar8) {
              iVar7 = iVar8;
            }
            uVar9 = (undefined2)iVar7;
          }
          else {
            uVar9 = 0x7fff;
          }
          iVar5 = iVar5 + *(int *)(&DAT_40ad2060 + (bVar2 & 0xf) * 4);
          *(undefined2 *)pcVar20 = uVar9;
          if (iVar5 < 0x59) {
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar5 = (int)(short)iVar5;
          }
          else {
            iVar5 = 0x58;
          }
          bVar2 = *pbVar14 >> 4;
          iVar7 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar5];
          if (iVar7 < 0) {
            iVar7 = iVar7 + 7;
          }
          iVar8 = iVar7 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar8 = -(iVar7 >> 3);
          }
          iVar8 = iVar8 + *(short *)(param_4 + iVar21);
          iVar15 = iVar15 + 4;
          if (iVar8 < 0x8000) {
            iVar7 = -0x8000;
            if (-0x8001 < iVar8) {
              iVar7 = iVar8;
            }
            uVar9 = (undefined2)iVar7;
          }
          else {
            uVar9 = 0x7fff;
          }
          iVar5 = iVar5 + *(int *)(&DAT_40ad2060 + (uint)bVar2 * 4);
          *(undefined2 *)(param_4 + iVar22) = uVar9;
          if (iVar5 < 0x59) {
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            uVar3 = (ushort)iVar5;
          }
          else {
            uVar3 = 0x58;
          }
          *puVar12 = uVar3;
          puVar12 = puVar12 + 1;
          iVar22 = iVar22 + 2;
          iVar21 = iVar21 + 2;
          pcVar20 = pcVar20 + 2;
          local_30 = local_30 + 2;
          pcVar13 = pcVar13 + 2;
          local_34 = local_34 + 1;
          psVar17 = psVar17 + 1;
          local_38 = local_38 + 1;
          psVar24 = psVar24 + 1;
          local_60 = local_60 + 1;
          psVar23 = psVar23 + 1;
          local_64 = local_64 + 1;
          psVar16 = psVar16 + 1;
          psVar25 = psVar25 + 1;
          pcVar19 = pcVar19 + 2;
          psVar18 = psVar18 + 1;
        } while (puVar12 != local_2c);
      }
      local_48 = local_48 + local_5c;
      local_58 = local_58 + iVar11;
      local_44 = local_44 + param_1 * 8;
      local_54 = local_54 + param_1 * 8;
      local_40 = local_40 + param_1 * 8;
      local_50 = local_50 + param_1 * 8;
      local_3c = local_3c + param_1 * 8;
      local_68 = local_68 + param_1 * 8;
      local_6c = local_6c + param_1 * 8;
      local_70 = local_70 + param_1 * 8;
      local_74 = local_74 + param_1 * 8;
      local_78 = local_78 + iVar11;
      local_7c = local_7c + iVar11;
      local_80 = local_80 + iVar11;
      local_84 = local_84 + iVar11;
      local_88 = local_88 + iVar11;
    } while (local_48 - local_5c < param_2);
  }
  return 1;
}



/* 40ac3a90 FUN_40ac3a90 */

/* Boundary evidence: original MIPS .pdata 40ac3a90..40ac4423. Semantic name remains unreviewed. */

undefined4 FUN_40ac3a90(int param_1,int param_2,undefined2 *param_3,va_list param_4)

{
  char *pcVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  int iVar11;
  ushort *puVar12;
  va_list pcVar13;
  byte *pbVar14;
  int iVar15;
  short *psVar16;
  short *psVar17;
  short *psVar18;
  va_list pcVar19;
  va_list pcVar20;
  int iVar21;
  int iVar22;
  short *psVar23;
  short *psVar24;
  short *psVar25;
  ushort local_90 [4];
  int local_88;
  int local_84;
  va_list local_80;
  int local_7c;
  va_list local_78;
  short *local_74;
  short *local_70;
  short *local_6c;
  short *local_68;
  short *local_64;
  short *local_60;
  int local_5c;
  int local_58;
  short *local_54;
  short *local_50;
  int local_4c;
  int local_48;
  short *local_44;
  short *local_40;
  short *local_3c;
  short *local_38;
  short *local_34;
  int local_30;
  ushort *local_2c;
  
  if ((param_2 - param_1 & 7U) != 0) {
    puVar5 = FUN_40ac992c(s_Input_not_correct_size_40ad6220);
    FUN_40ac98dc((size_t)puVar5,param_2,param_3,param_4);
    return 0;
  }
  if (0 < param_1) {
    puVar12 = local_90;
    iVar11 = 0;
    puVar5 = param_3;
    pcVar13 = param_4;
    do {
      *(undefined2 *)pcVar13 = *puVar5;
      pbVar14 = (byte *)(puVar5 + 1);
      uVar3 = (ushort)*pbVar14;
      iVar11 = iVar11 + 1;
      pcVar1 = (char *)((int)puVar5 + 3);
      puVar5 = puVar5 + 2;
      pcVar13 = pcVar13 + 2;
      if (0x57 < *pbVar14) {
        uVar3 = 0x58;
      }
      if (*pcVar1 != '\0') {
        puVar4 = FUN_40ac992c(s_ADPCM_4_Synchronisation_error_40ad6238);
        FUN_40ac98dc((size_t)puVar4,puVar5,iVar11,param_4);
        return 0;
      }
      *puVar12 = uVar3;
      puVar12 = puVar12 + 1;
    } while (iVar11 < param_1);
  }
  if (param_1 < param_2) {
    local_4c = param_1 * 2;
    local_3c = (short *)(param_4 + param_1 * 6);
    local_7c = param_1 * 0xc;
    local_84 = param_1 * 0xe;
    iVar15 = param_1 * 4;
    local_70 = (short *)(param_4 + param_1 * 10);
    iVar11 = param_1 * 0x10;
    local_68 = (short *)(param_4 + param_1 * 8);
    local_48 = param_1 * 9;
    local_5c = param_1 * 8;
    local_40 = (short *)(param_4 + iVar15);
    local_88 = param_1 << 4;
    local_54 = (short *)(param_4 + iVar15);
    local_80 = param_4 + param_1 * 0xe;
    local_44 = (short *)(param_4 + param_1 * 2);
    local_78 = param_4 + param_1 * 0xc;
    local_50 = (short *)(param_4 + param_1 * 6);
    local_6c = (short *)(param_4 + param_1 * 8);
    local_74 = (short *)(param_4 + param_1 * 10);
    local_58 = 0;
    local_2c = local_90 + param_1;
    do {
      if (0 < param_1) {
        psVar18 = (short *)(param_4 + local_58);
        pcVar19 = param_4 + local_4c + local_58;
        puVar12 = local_90;
        local_30 = local_7c;
        local_34 = local_74;
        local_38 = local_6c;
        local_60 = local_3c;
        local_64 = local_40;
        psVar16 = local_54;
        psVar17 = local_70;
        pcVar13 = local_78;
        pcVar20 = local_80;
        iVar21 = local_84;
        iVar22 = local_88;
        psVar23 = local_50;
        psVar24 = local_68;
        psVar25 = local_44;
        do {
          bVar2 = *(byte *)((int)param_3 + iVar15);
          iVar6 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[(short)*puVar12];
          if (iVar6 < 0) {
            iVar6 = iVar6 + 7;
          }
          iVar8 = iVar6 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar8 = -(iVar6 >> 3);
          }
          iVar8 = iVar8 + *psVar18;
          if (iVar8 < 0x8000) {
            iVar6 = -0x8000;
            if (-0x8001 < iVar8) {
              iVar6 = iVar8;
            }
            uVar10 = (undefined2)iVar6;
          }
          else {
            uVar10 = 0x7fff;
          }
          iVar6 = (int)(short)*puVar12 + *(int *)(&DAT_40ad6bf0 + (bVar2 & 0xf) * 4);
          *(undefined2 *)pcVar19 = uVar10;
          if (iVar6 < 0x59) {
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            iVar6 = (int)(short)iVar6;
          }
          else {
            iVar6 = 0x58;
          }
          bVar2 = *(byte *)((int)param_3 + iVar15) >> 4;
          iVar8 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar6];
          if (iVar8 < 0) {
            iVar8 = iVar8 + 7;
          }
          iVar9 = iVar8 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar9 = -(iVar8 >> 3);
          }
          iVar9 = iVar9 + *psVar25;
          if (iVar9 < 0x8000) {
            iVar8 = -0x8000;
            if (-0x8001 < iVar9) {
              iVar8 = iVar9;
            }
            sVar7 = (short)iVar8;
          }
          else {
            sVar7 = 0x7fff;
          }
          iVar6 = iVar6 + *(int *)(&DAT_40ad6bf0 + (uint)bVar2 * 4);
          *psVar16 = sVar7;
          if (iVar6 < 0x59) {
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            iVar6 = (int)(short)iVar6;
          }
          else {
            iVar6 = 0x58;
          }
          pbVar14 = (byte *)((int)param_3 + iVar15 + 1);
          bVar2 = *pbVar14;
          iVar8 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar6];
          if (iVar8 < 0) {
            iVar8 = iVar8 + 7;
          }
          iVar9 = iVar8 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar9 = -(iVar8 >> 3);
          }
          iVar9 = iVar9 + *local_64;
          if (iVar9 < 0x8000) {
            iVar8 = -0x8000;
            if (-0x8001 < iVar9) {
              iVar8 = iVar9;
            }
            sVar7 = (short)iVar8;
          }
          else {
            sVar7 = 0x7fff;
          }
          iVar6 = iVar6 + *(int *)(&DAT_40ad6bf0 + (bVar2 & 0xf) * 4);
          *psVar23 = sVar7;
          if (iVar6 < 0x59) {
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            iVar6 = (int)(short)iVar6;
          }
          else {
            iVar6 = 0x58;
          }
          bVar2 = *pbVar14 >> 4;
          iVar8 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar6];
          if (iVar8 < 0) {
            iVar8 = iVar8 + 7;
          }
          iVar9 = iVar8 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar9 = -(iVar8 >> 3);
          }
          iVar9 = iVar9 + *local_60;
          if (iVar9 < 0x8000) {
            iVar8 = -0x8000;
            if (-0x8001 < iVar9) {
              iVar8 = iVar9;
            }
            sVar7 = (short)iVar8;
          }
          else {
            sVar7 = 0x7fff;
          }
          iVar6 = iVar6 + *(int *)(&DAT_40ad6bf0 + (uint)bVar2 * 4);
          *psVar24 = sVar7;
          if (iVar6 < 0x59) {
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            iVar6 = (int)(short)iVar6;
          }
          else {
            iVar6 = 0x58;
          }
          pbVar14 = (byte *)((int)param_3 + iVar15 + 2);
          bVar2 = *pbVar14;
          iVar8 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar6];
          if (iVar8 < 0) {
            iVar8 = iVar8 + 7;
          }
          iVar9 = iVar8 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar9 = -(iVar8 >> 3);
          }
          iVar9 = iVar9 + *local_38;
          if (iVar9 < 0x8000) {
            iVar8 = -0x8000;
            if (-0x8001 < iVar9) {
              iVar8 = iVar9;
            }
            sVar7 = (short)iVar8;
          }
          else {
            sVar7 = 0x7fff;
          }
          iVar6 = iVar6 + *(int *)(&DAT_40ad6bf0 + (bVar2 & 0xf) * 4);
          *psVar17 = sVar7;
          if (iVar6 < 0x59) {
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            iVar6 = (int)(short)iVar6;
          }
          else {
            iVar6 = 0x58;
          }
          bVar2 = *pbVar14 >> 4;
          iVar8 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar6];
          if (iVar8 < 0) {
            iVar8 = iVar8 + 7;
          }
          iVar9 = iVar8 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar9 = -(iVar8 >> 3);
          }
          iVar9 = iVar9 + *local_34;
          if (iVar9 < 0x8000) {
            iVar8 = -0x8000;
            if (-0x8001 < iVar9) {
              iVar8 = iVar9;
            }
            uVar10 = (undefined2)iVar8;
          }
          else {
            uVar10 = 0x7fff;
          }
          iVar6 = iVar6 + *(int *)(&DAT_40ad6bf0 + (uint)bVar2 * 4);
          *(undefined2 *)pcVar13 = uVar10;
          if (iVar6 < 0x59) {
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            iVar6 = (int)(short)iVar6;
          }
          else {
            iVar6 = 0x58;
          }
          pbVar14 = (byte *)((int)param_3 + iVar15 + 3);
          bVar2 = *pbVar14;
          iVar8 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar6];
          if (iVar8 < 0) {
            iVar8 = iVar8 + 7;
          }
          iVar9 = iVar8 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar9 = -(iVar8 >> 3);
          }
          iVar9 = iVar9 + *(short *)(param_4 + local_30);
          if (iVar9 < 0x8000) {
            iVar8 = -0x8000;
            if (-0x8001 < iVar9) {
              iVar8 = iVar9;
            }
            uVar10 = (undefined2)iVar8;
          }
          else {
            uVar10 = 0x7fff;
          }
          iVar6 = iVar6 + *(int *)(&DAT_40ad6bf0 + (bVar2 & 0xf) * 4);
          *(undefined2 *)pcVar20 = uVar10;
          if (iVar6 < 0x59) {
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            iVar6 = (int)(short)iVar6;
          }
          else {
            iVar6 = 0x58;
          }
          bVar2 = *pbVar14 >> 4;
          iVar8 = ((bVar2 & 7) * 2 + 1) * (&DAT_40ad6a8c)[iVar6];
          if (iVar8 < 0) {
            iVar8 = iVar8 + 7;
          }
          iVar9 = iVar8 >> 3;
          if ((bVar2 & 8) != 0) {
            iVar9 = -(iVar8 >> 3);
          }
          iVar9 = iVar9 + *(short *)(param_4 + iVar21);
          iVar15 = iVar15 + 4;
          if (iVar9 < 0x8000) {
            iVar8 = -0x8000;
            if (-0x8001 < iVar9) {
              iVar8 = iVar9;
            }
            uVar10 = (undefined2)iVar8;
          }
          else {
            uVar10 = 0x7fff;
          }
          iVar6 = iVar6 + *(int *)(&DAT_40ad6bf0 + (uint)bVar2 * 4);
          *(undefined2 *)(param_4 + iVar22) = uVar10;
          if (iVar6 < 0x59) {
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            uVar3 = (ushort)iVar6;
          }
          else {
            uVar3 = 0x58;
          }
          *puVar12 = uVar3;
          puVar12 = puVar12 + 1;
          iVar22 = iVar22 + 2;
          iVar21 = iVar21 + 2;
          pcVar20 = pcVar20 + 2;
          local_30 = local_30 + 2;
          pcVar13 = pcVar13 + 2;
          local_34 = local_34 + 1;
          psVar17 = psVar17 + 1;
          local_38 = local_38 + 1;
          psVar24 = psVar24 + 1;
          local_60 = local_60 + 1;
          psVar23 = psVar23 + 1;
          local_64 = local_64 + 1;
          psVar16 = psVar16 + 1;
          psVar25 = psVar25 + 1;
          pcVar19 = pcVar19 + 2;
          psVar18 = psVar18 + 1;
        } while (puVar12 != local_2c);
      }
      local_48 = local_48 + local_5c;
      local_58 = local_58 + iVar11;
      local_44 = local_44 + param_1 * 8;
      local_54 = local_54 + param_1 * 8;
      local_40 = local_40 + param_1 * 8;
      local_50 = local_50 + param_1 * 8;
      local_3c = local_3c + param_1 * 8;
      local_68 = local_68 + param_1 * 8;
      local_6c = local_6c + param_1 * 8;
      local_70 = local_70 + param_1 * 8;
      local_74 = local_74 + param_1 * 8;
      local_78 = local_78 + iVar11;
      local_7c = local_7c + iVar11;
      local_80 = local_80 + iVar11;
      local_84 = local_84 + iVar11;
      local_88 = local_88 + iVar11;
    } while (local_48 - local_5c < param_2);
  }
  return 1;
}



/* 40ac4424 FUN_40ac4424 */

/* Boundary evidence: original MIPS .pdata 40ac4424..40ac4717. Semantic name remains unreviewed. */

undefined4 FUN_40ac4424(int param_1,int param_2,byte *param_3,va_list param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 *puVar4;
  int iVar5;
  ushort uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  va_list pcVar12;
  short *psVar13;
  int iVar14;
  undefined2 uVar15;
  int iVar16;
  ushort local_28 [4];
  
  if (param_1 == 1) {
    bVar1 = *param_3;
    uVar8 = (uint)bVar1;
    local_28[2] = *(ushort *)(param_3 + 1);
    uVar9 = (uint)param_3[2];
    *(undefined2 *)(param_4 + 2) = *(undefined2 *)(param_3 + 3);
    *(undefined2 *)param_4 = *(undefined2 *)(param_3 + 5);
    if (6 < uVar8) goto LAB_40ac4500;
    local_28[0] = (ushort)bVar1;
    uVar8 = 2;
    iVar14 = 7;
  }
  else {
    bVar1 = *param_3;
    uVar8 = (uint)bVar1;
    bVar2 = param_3[1];
    uVar9 = (uint)bVar2;
    local_28[2] = *(ushort *)(param_3 + 2);
    local_28[3] = *(ushort *)(param_3 + 4);
    *(undefined2 *)(param_4 + 4) = *(undefined2 *)(param_3 + 6);
    *(undefined2 *)(param_4 + 6) = *(undefined2 *)(param_3 + 8);
    *(undefined2 *)param_4 = *(undefined2 *)(param_3 + 10);
    *(undefined2 *)(param_4 + 2) = *(undefined2 *)(param_3 + 0xc);
    if ((6 < uVar8) || (6 < uVar9)) {
LAB_40ac4500:
      puVar4 = FUN_40ac992c(s_Invalid_block_predictor_40ad6258);
      FUN_40ac98dc((size_t)puVar4,uVar8,uVar9,param_4);
      return 0;
    }
    local_28[0] = (ushort)bVar1;
    local_28[1] = (ushort)bVar2;
    uVar8 = 4;
    iVar14 = 0xe;
  }
  if ((int)uVar8 < param_2) {
    psVar13 = (short *)(param_4 + (uVar8 + param_1 * -2) * 2);
    pcVar12 = param_4 + uVar8 * 2;
    psVar10 = (short *)(param_4 + (uVar8 - param_1) * 2);
    do {
      iVar16 = (int)uVar8 % param_1;
      if (param_1 == 0) {
        trap(7);
      }
      pbVar7 = param_3 + iVar14;
      if ((uVar8 & 1) == 0) {
        uVar9 = (uint)(*pbVar7 >> 4);
      }
      else {
        iVar14 = iVar14 + 1;
        uVar9 = *pbVar7 & 0xf;
      }
      uVar11 = uVar9;
      if ((uVar9 & 8) != 0) {
        uVar11 = uVar9 - 0x10;
      }
      uVar3 = local_28[iVar16 + 2];
      uVar15 = 0x7fff;
      uVar6 = (ushort)((uint)((int)(short)uVar3 * *(int *)(&DAT_40ad6c30 + uVar9 * 4)) >> 8);
      local_28[iVar16 + 2] = uVar6;
      if ((short)uVar6 < 0x10) {
        local_28[iVar16 + 2] = 0x10;
      }
      iVar5 = uVar11 * (int)(short)uVar3 +
              ((int)*psVar10 * *(int *)(&DAT_40ad6c70 + (short)local_28[iVar16] * 4) +
               (int)*psVar13 * *(int *)(&DAT_40ad6c8c + (short)local_28[iVar16] * 4) >> 8);
      iVar16 = -0x8000;
      if (-0x8001 < iVar5) {
        iVar16 = iVar5;
      }
      if (iVar5 < 0x8000) {
        uVar15 = (undefined2)iVar16;
      }
      uVar8 = uVar8 + 1;
      *(undefined2 *)pcVar12 = uVar15;
      psVar10 = psVar10 + 1;
      pcVar12 = pcVar12 + 2;
      psVar13 = psVar13 + 1;
    } while ((int)uVar8 < param_2);
  }
  return 1;
}



/* 40ac4718 FUN_40ac4718 */

/* Boundary evidence: original MIPS .pdata 40ac4718..40ac47e3. Semantic name remains unreviewed. */

undefined4 FUN_40ac4718(va_list param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  if (param_2 * (int)param_1 < 0x20001) {
    uVar1 = (int)param_1 * 2 * param_2;
    if (uVar1 < 0x40001) {
      *(undefined4 *)(param_3 + 0x15c) = 0;
      uVar2 = 0;
    }
    else {
      puVar3 = FUN_40ac992c(s_open_downmix_ERROR_MAX_DOWNMIX_I_40ad62e0);
      FUN_40ac98dc((size_t)puVar3,uVar1,0x40000,param_1);
      uVar2 = 0xffffffff;
    }
  }
  else {
    puVar3 = FUN_40ac992c(s_open_downmix_ERROR_MAX_DOWNMIX_B_40ad6274);
    FUN_40ac98dc((size_t)puVar3,param_2 * (int)param_1,0x20000,param_1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 40ac47e4 FUN_40ac47e4 */

/* Boundary evidence: original MIPS .pdata 40ac47e4..40ac4867. Semantic name remains unreviewed. */

void FUN_40ac47e4(int param_1,void *param_2)

{
  memset(param_2,0,0x80180);
  if (param_1 == 0) {
    *(undefined4 *)((int)param_2 + 0x158) = 1;
    *(undefined4 *)((int)param_2 + 0x80178) = 1;
    return;
  }
  *(undefined4 *)((int)param_2 + 0x158) = 0;
  *(undefined4 *)((int)param_2 + 0x80178) = 1;
  return;
}



/* 40ac4868 FUN_40ac4868 */

/* Boundary evidence: original MIPS .pdata 40ac4868..40ac4a3f. Semantic name remains unreviewed. */

void FUN_40ac4868(int *param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = *param_2;
  if (0 < (int)uVar6) {
    if (2 < *(int *)(param_3 + 0x80170)) {
      piVar4 = FUN_40ac2298(param_3,param_1,(int *)param_2);
      FUN_40ac6ef0(param_1,piVar4,*param_2);
      uVar6 = *param_2;
    }
    if (0 < *(int *)(param_3 + 0x158)) {
      if (*(int *)(param_3 + 0x158) == 1) {
        iVar1 = *(int *)(param_3 + 0x13c);
        if ((iVar1 == 0x1523) || (iVar1 == 1)) {
          uVar7 = 100;
        }
        else {
          uVar7 = 100;
          if (iVar1 != 0xfffe) {
            uVar7 = uVar6 >> 2;
          }
        }
        if (uVar6 >> 1 == 0) {
          iVar1 = 1;
        }
        else {
          *(undefined2 *)param_1 = 0;
          uVar3 = 0;
          piVar4 = param_1;
          do {
            uVar3 = uVar3 + 1;
            if (uVar6 >> 1 <= uVar3) break;
            *(undefined2 *)((int)piVar4 + 2) = 0;
            piVar4 = (int *)((int)piVar4 + 2);
          } while (uVar3 <= uVar7);
          iVar1 = 1;
        }
      }
      else {
        memset(param_1,0,uVar6);
        iVar1 = *(int *)(param_3 + 0x158);
      }
      *(int *)(param_3 + 0x158) = iVar1 + -1;
      uVar6 = *param_2;
    }
    if ((0 < (int)uVar6) && (iVar1 = *(int *)(param_3 + 0x160), iVar1 != 0)) {
      iVar5 = *(int *)(param_3 + 0x168);
      uVar6 = uVar6 >> 1;
      if (iVar5 == 0) {
        if (uVar6 != 0) {
          iVar5 = *(int *)(param_3 + 0x164);
          uVar7 = 0;
          do {
            iVar2 = 0x7fffffff - iVar1;
            iVar1 = iVar5 + iVar1;
            uVar7 = uVar7 + 1;
            if (iVar1 < 0) {
              iVar1 = 0;
            }
            *(short *)param_1 = (short)((iVar2 >> 0x10) * (int)(short)*param_1 >> 0xf);
            *(int *)(param_3 + 0x160) = iVar1;
            param_1 = (int *)((int)param_1 + 2);
          } while (uVar7 < uVar6);
          return;
        }
      }
      else if (uVar6 != 0) {
        uVar7 = 0;
        do {
          iVar5 = iVar5 + -1;
          uVar7 = uVar7 + 1;
          if (iVar5 < 0) {
            iVar5 = 0;
          }
          *(undefined2 *)param_1 = 0;
          *(int *)(param_3 + 0x168) = iVar5;
          param_1 = (int *)((int)param_1 + 2);
        } while (uVar7 < uVar6);
      }
    }
  }
  return;
}



/* 40ac4a40 FUN_40ac4a40 */

/* Boundary evidence: original MIPS .pdata 40ac4a40..40ac4af3. Semantic name remains unreviewed. */

void FUN_40ac4a40(undefined4 *param_1,int param_2,void *param_3)

{
  memset(param_3,0,0x80180);
  if (param_2 == 0) {
    *(undefined4 *)((int)param_3 + 0x158) = 1;
    *(undefined4 *)((int)param_3 + 0x80178) = 1;
    param_1[1] = 2;
    *param_1 = 0xac44;
    return;
  }
  *(undefined4 *)((int)param_3 + 0x80178) = 1;
  *(undefined4 *)((int)param_3 + 0x158) = 0;
  param_1[1] = 2;
  *param_1 = 0xac44;
  return;
}



/* 40ac4af4 FUN_40ac4af4 */

/* Boundary evidence: original MIPS .pdata 40ac4af4..40ac4b3b. Semantic name remains unreviewed. */

void FUN_40ac4af4(void *param_1)

{
  memset(param_1,0,0x80180);
  *(undefined4 *)((int)param_1 + 0x80178) = 1;
  *(undefined4 *)((int)param_1 + 0x158) = 1;
  return;
}



/* 40ac4bbc FUN_40ac4bbc */

/* Boundary evidence: original MIPS .pdata 40ac4bbc..40ac5acf. Semantic name remains unreviewed. */

char * FUN_40ac4bbc(char *param_1,uint *param_2,int *param_3,uint *param_4,uint *param_5,int param_6
                   ,int param_7)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  ushort uVar8;
  uint3 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined2 *puVar14;
  uint uVar15;
  char *pcVar16;
  uint *puVar17;
  undefined4 uVar18;
  byte *pbVar19;
  uint *puVar20;
  char *_Str1;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  char acStack_a0 [4];
  undefined1 local_9c;
  uint auStack_98 [16];
  uint *local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  *param_5 = 0xffffffff;
  puVar20 = param_4;
  iVar12 = strncmp(param_1,&DAT_40ad6354,4);
  if (iVar12 == 0) {
    *(undefined4 *)(param_6 + 0x80174) = 0;
    local_3c = (uint)(byte)param_1[4];
    local_44 = (uint)(byte)param_1[5];
    local_48 = (uint)(byte)param_1[6];
    local_4c = (uint)(byte)param_1[7];
    iVar12 = strncmp(param_1 + 8,&DAT_40ad635c,4);
    uVar10 = s_WAV_PCM_decoder_40ad6364._8_4_;
    uVar18 = s_WAV_PCM_decoder_40ad6364._4_4_;
    _Str1 = param_1 + 8;
    if (iVar12 == 0) {
      *(undefined4 *)(param_6 + 0x140) = s_WAV_PCM_decoder_40ad6364._0_4_;
      *(undefined4 *)(param_6 + 0x144) = uVar18;
      *(undefined4 *)(param_6 + 0x148) = uVar10;
      _Str1 = param_1 + 0xc;
      *(undefined2 *)(param_6 + 0x14c) = s_WAV_PCM_decoder_40ad6364._12_2_;
      *(char *)(param_6 + 0x14e) = s_WAV_PCM_decoder_40ad6364[0xe];
      iVar12 = 4;
      iVar13 = strncmp(_Str1,&DAT_40ad6374,4);
      if (iVar13 == 0) {
        bVar6 = param_1[0x16];
        local_50 = *(int *)(param_1 + 0x10);
        uVar8 = *(ushort *)(param_1 + 0x14);
        *param_4 = (uint)bVar6;
        uVar21 = (uint)uVar8;
        *param_4 = (uint)CONCAT11(param_1[0x17],bVar6);
        bVar6 = param_1[0x18];
        *param_5 = (uint)bVar6;
        uVar8 = CONCAT11(param_1[0x19],bVar6);
        *param_5 = (uint)uVar8;
        uVar9 = CONCAT12(param_1[0x1a],uVar8);
        *param_5 = (uint)uVar9;
        uVar23 = CONCAT13(param_1[0x1b],uVar9);
        *param_5 = uVar23;
        iVar12 = *(int *)(param_1 + 0x1c);
        puVar20 = (uint *)(uint)*(ushort *)(param_1 + 0x20);
        uVar22 = (uint)*(ushort *)(param_1 + 0x22);
        _Str1 = param_1 + 0x24;
        local_58 = puVar20;
        local_54 = iVar12;
        if (uVar21 < 8) {
          if ((uVar21 < 6) && (1 < uVar21 - 1)) goto LAB_40ac4f10;
        }
        else if ((uVar21 < 0x10) || ((0x11 < uVar21 && (uVar21 != 0xfffe)))) goto LAB_40ac4f10;
      }
      else {
        uVar22 = 0;
        local_50 = 0;
        uVar21 = 0;
        local_54 = 0;
        local_58 = (uint *)0x0;
LAB_40ac4f10:
        puVar14 = FUN_40ac992c(s_unknown_format__x_40ad637c);
        FUN_40ac98dc((size_t)puVar14,uVar21,iVar12,(va_list)puVar20);
        uVar23 = *param_5;
      }
      iVar12 = strncmp(_Str1,&DAT_40ad6390,4);
      iVar13 = 0;
      if (iVar12 == 0) {
LAB_40ac4f80:
        local_50 = *(int *)(_Str1 + 4);
        _Str1 = _Str1 + 8;
      }
      else {
        do {
          _Str1 = _Str1 + 1;
          iVar13 = iVar13 + 1;
          iVar12 = strncmp(_Str1,&DAT_40ad6390,4);
          if (iVar12 == 0) goto LAB_40ac4f80;
        } while (iVar13 != 0x416);
        local_50 = (local_44 << 8 | local_3c | local_48 << 0x10 | local_4c << 0x18) - local_50;
      }
      *(uint *)(param_6 + 0x120) = uVar23;
      *(uint *)(param_6 + 0x124) = uVar22;
      *(uint *)(param_6 + 0x128) = *param_4;
      *(uint *)(param_6 + 0x80170) = *param_4;
      *(int *)(param_6 + 300) = local_54 << 3;
      *(uint **)(param_6 + 0x130) = local_58;
      uVar23 = *param_4;
      if (uVar23 == 0) {
        trap(7);
      }
      uVar15 = *param_5;
      *(uint *)(param_6 + 0x13c) = uVar21;
      if ((int)uVar15 / 100 == 0) {
        trap(7);
      }
      if (uVar22 == 0) {
        trap(7);
      }
      *(uint *)(param_6 + 0x134) =
           (((uint)(local_50 * 0x50) / uVar23) / (uint)((int)uVar15 / 100)) / uVar22;
      goto LAB_40ac4c70;
    }
  }
  else {
    iVar12 = strncmp(param_1,&DAT_40ad6398,4);
    _Str1 = param_1;
    if (iVar12 == 0) {
      _Str1 = param_1 + 8;
      *(undefined4 *)(param_6 + 0x80174) = 1;
      iVar12 = strncmp(_Str1,&DAT_40ad63a0,4);
      uVar11 = s_AIFC_PCM_decoder_40ad63a8._12_4_;
      uVar10 = s_AIFC_PCM_decoder_40ad63a8._8_4_;
      uVar18 = s_AIFC_PCM_decoder_40ad63a8._4_4_;
      if (iVar12 == 0) {
        *(undefined4 *)(param_6 + 0x140) = s_AIFC_PCM_decoder_40ad63a8._0_4_;
        *(undefined4 *)(param_6 + 0x14c) = uVar11;
        *(undefined4 *)(param_6 + 0x144) = uVar18;
        *(undefined4 *)(param_6 + 0x148) = uVar10;
        local_34 = param_7 + -0xf;
        _Str1 = param_1 + 0xc;
        uVar22 = 0;
        local_40 = 0;
        local_38 = param_6 + 0x80000;
        do {
          uVar18 = 4;
          iVar12 = strncmp(_Str1,&DAT_40ad63bc,4);
          if (iVar12 != 0) {
            iVar12 = strncmp(_Str1,&DAT_40ad63ec,4);
            if (iVar12 == 0) {
              cVar4 = _Str1[8];
              cVar5 = _Str1[9];
              uVar23 = (uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                       (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7];
              _Str1 = _Str1 + 10;
              uVar21 = 2;
              iVar12 = (int)CONCAT11(cVar4,cVar5);
              while (iVar12 = (iVar12 + -1) * 0x10000 >> 0x10, iVar12 != -1) {
                cVar3 = *_Str1;
                pcVar1 = _Str1 + 1;
                pbVar19 = (byte *)(_Str1 + 6);
                uVar21 = uVar21 + 7;
                puVar20 = (uint *)((uint)(byte)_Str1[3] << 0x10 | (uint)(byte)_Str1[2] << 0x18 |
                                  (uint)(byte)_Str1[4] << 8);
                pbVar2 = (byte *)(_Str1 + 5);
                uVar15 = 0;
                _Str1 = _Str1 + 7;
                do {
                  uVar15 = uVar15 + 1;
                  _Str1 = _Str1 + 1;
                  uVar21 = uVar21 + 1;
                } while (uVar15 <= *pbVar19);
                auStack_98[CONCAT11(cVar3,*pcVar1)] = (uint)puVar20 | (uint)*pbVar2;
              }
              if (uVar21 != uVar23) {
                puVar14 = FUN_40ac992c(s_AIFF_MARK_chunk_parse_error___x___40ad63f4);
                FUN_40ac98dc((size_t)puVar14,uVar21,uVar23,(va_list)puVar20);
                return (char *)0x0;
              }
              if (1 < CONCAT11(cVar4,cVar5)) {
                *param_3 = auStack_98[2] - auStack_98[1];
                local_40 = auStack_98[2];
              }
              goto LAB_40ac50c0;
            }
            iVar12 = strncmp(_Str1,&DAT_40ad641c,4);
            if (iVar12 == 0) {
              _Str1 = _Str1 + ((uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                               (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7]) + 8;
              goto LAB_40ac50c0;
            }
            iVar12 = strncmp(_Str1,&DAT_40ad6424,4);
            if (iVar12 == 0) {
              _Str1 = _Str1 + ((uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                               (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7]) + 8;
              goto LAB_40ac50c0;
            }
            iVar12 = strncmp(_Str1,&DAT_40ad642c,4);
            if (iVar12 != 0) {
              uVar21 = (uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                       (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7];
              pcVar1 = _Str1 + uVar21 + 8;
              pcVar16 = _Str1 + uVar21 + 9;
              _Str1 = _Str1 + uVar21 + 8;
              if (*pcVar1 == '\0') {
                _Str1 = pcVar16;
              }
              goto LAB_40ac50c0;
            }
            uVar23 = (uint)(byte)_Str1[4];
            bVar6 = _Str1[5];
            bVar7 = _Str1[6];
            uVar21 = (uint)(byte)_Str1[7];
            if (CONCAT11(_Str1[0xe],_Str1[0xf]) != 0) {
              puVar14 = FUN_40ac992c(s_AIFC_header_specifies_nonzero_bl_40ad6434);
              FUN_40ac98dc((size_t)puVar14,uVar23,uVar21,(va_list)puVar20);
              return (char *)0x0;
            }
LAB_40ac5a48:
            uVar21 = (uint)bVar6 << 0x10 | uVar23 << 0x18 | (uint)bVar7 << 8 | uVar21;
            _Str1 = _Str1 + 0x10;
            goto LAB_40ac50d8;
          }
          uVar21 = (uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                   (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7];
          if ((int)uVar21 < 0x16) {
            puVar14 = FUN_40ac992c(s_AIFC_COMM_chunk_has_bad_size__d_<_40ad63c4);
            FUN_40ac98dc((size_t)puVar14,uVar21,uVar18,(va_list)puVar20);
            return (char *)0x0;
          }
          bVar6 = _Str1[8];
          *param_4 = (uint)bVar6 << 8;
          *param_4 = (uint)CONCAT11(bVar6,_Str1[9]);
          puVar17 = &DAT_40ad6cac;
          bVar6 = _Str1[0xe];
          puVar20 = (uint *)(uint)bVar6;
          cVar4 = _Str1[0xf];
          iVar12 = 0;
          do {
            if (((((uint)(byte)_Str1[0x10] == *puVar17) && (puVar17[1] == (uint)(byte)_Str1[0x11]))
                && ((puVar17[2] == (uint)(byte)_Str1[0x12] &&
                    (((puVar17[3] == (uint)(byte)_Str1[0x13] &&
                      (puVar17[4] == (uint)(byte)_Str1[0x14])) &&
                     (puVar17[5] == (uint)(byte)_Str1[0x15])))))) &&
               (puVar17[6] == (uint)(byte)_Str1[0x16])) {
              uVar22 = (&DAT_40ad6ca8)[iVar12 * 8];
              goto LAB_40ac5084;
            }
            iVar12 = iVar12 + 1;
            puVar17 = puVar17 + 8;
          } while (iVar12 != 0x19);
          uVar22 = 0;
LAB_40ac5084:
          *param_5 = uVar22;
          uVar22 = (uint)CONCAT11(bVar6,cVar4);
          strncpy(acStack_a0,_Str1 + 0x1a,4);
          local_9c = 0;
          uVar18 = FUN_40ac1358(acStack_a0);
          *(undefined4 *)(local_38 + 0x174) = uVar18;
          _Str1 = _Str1 + 0x1a + (uVar21 - 0x12);
LAB_40ac50c0:
        } while ((int)_Str1 - (int)param_1 < local_34);
        uVar21 = 0;
LAB_40ac50d8:
        if (local_40 == 0) {
          uVar21 = uVar21 * 0x50;
        }
        else {
          uVar21 = local_40 * 0x50 * (uVar22 >> 3);
        }
      }
      else {
        iVar12 = strncmp(_Str1,&DAT_40ad6460,4);
        uVar11 = s_AIFF_PCM_decoder_40ad6468._12_4_;
        uVar10 = s_AIFF_PCM_decoder_40ad6468._8_4_;
        uVar18 = s_AIFF_PCM_decoder_40ad6468._4_4_;
        uVar22 = 0;
        if (iVar12 == 0) {
          *(undefined4 *)(param_6 + 0x140) = s_AIFF_PCM_decoder_40ad6468._0_4_;
          *(undefined4 *)(param_6 + 0x14c) = uVar11;
          *(undefined4 *)(param_6 + 0x144) = uVar18;
          *(undefined4 *)(param_6 + 0x148) = uVar10;
          local_2c = param_7 + -0xf;
          _Str1 = param_1 + 0xc;
          local_40 = 0;
          local_30 = param_6 + 0x80000;
          do {
            uVar18 = 4;
            iVar12 = strncmp(_Str1,&DAT_40ad63bc,4);
            if (iVar12 == 0) {
              uVar21 = (uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                       (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7];
              if ((int)uVar21 < 0x12) {
                puVar14 = FUN_40ac992c(s_AIFF_COMM_chunk_has_bad_size__d_<_40ad647c);
                FUN_40ac98dc((size_t)puVar14,uVar21,uVar18,(va_list)puVar20);
                return (char *)0x0;
              }
              bVar6 = _Str1[8];
              *param_4 = (uint)bVar6 << 8;
              *param_4 = (uint)CONCAT11(bVar6,_Str1[9]);
              uVar22 = (uint)CONCAT11(_Str1[0xe],_Str1[0xf]);
              puVar20 = &DAT_40ad6cac;
              iVar12 = 0;
              do {
                if ((((((uint)(byte)_Str1[0x10] == *puVar20) &&
                      (puVar20[1] == (uint)(byte)_Str1[0x11])) &&
                     (puVar20[2] == (uint)(byte)_Str1[0x12])) &&
                    ((puVar20[3] == (uint)(byte)_Str1[0x13] &&
                     (puVar20[4] == (uint)(byte)_Str1[0x14])))) &&
                   ((puVar20[5] == (uint)(byte)_Str1[0x15] &&
                    (puVar20[6] == (uint)(byte)_Str1[0x16])))) {
                  uVar23 = (&DAT_40ad6ca8)[iVar12 * 8];
                  goto LAB_40ac5638;
                }
                iVar12 = iVar12 + 1;
                puVar20 = puVar20 + 8;
              } while (iVar12 != 0x19);
              uVar23 = 0;
LAB_40ac5638:
              *param_5 = uVar23;
              strncpy(acStack_a0,_Str1 + 0x1a,4);
              local_9c = 0;
              uVar18 = FUN_40ac1358(acStack_a0);
              *(undefined4 *)(local_30 + 0x174) = uVar18;
              _Str1 = _Str1 + 0x1a + (uVar21 - 0x12);
            }
            else {
              iVar12 = strncmp(_Str1,&DAT_40ad63ec,4);
              if (iVar12 == 0) {
                cVar4 = _Str1[8];
                cVar5 = _Str1[9];
                uVar23 = (uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                         (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7];
                _Str1 = _Str1 + 10;
                uVar21 = 2;
                iVar12 = (int)CONCAT11(cVar4,cVar5);
                while (iVar12 = (iVar12 + -1) * 0x10000 >> 0x10, iVar12 != -1) {
                  cVar3 = *_Str1;
                  pcVar1 = _Str1 + 1;
                  pbVar19 = (byte *)(_Str1 + 6);
                  uVar21 = uVar21 + 7;
                  puVar20 = (uint *)((uint)(byte)_Str1[3] << 0x10 | (uint)(byte)_Str1[2] << 0x18 |
                                    (uint)(byte)_Str1[4] << 8);
                  pbVar2 = (byte *)(_Str1 + 5);
                  uVar15 = 0;
                  _Str1 = _Str1 + 7;
                  do {
                    uVar15 = uVar15 + 1;
                    _Str1 = _Str1 + 1;
                    uVar21 = uVar21 + 1;
                  } while (uVar15 <= *pbVar19);
                  auStack_98[CONCAT11(cVar3,*pcVar1)] = (uint)puVar20 | (uint)*pbVar2;
                }
                if (uVar21 != uVar23) {
                  puVar14 = FUN_40ac992c(s_AIFF_MARK_chunk_parse_error___x___40ad63f4);
                  FUN_40ac98dc((size_t)puVar14,uVar21,uVar23,(va_list)puVar20);
                  return (char *)0x0;
                }
                if (1 < CONCAT11(cVar4,cVar5)) {
                  *param_3 = auStack_98[2] - auStack_98[1];
                  local_40 = auStack_98[2];
                }
              }
              else {
                iVar12 = strncmp(_Str1,&DAT_40ad641c,4);
                if (iVar12 == 0) {
                  _Str1 = _Str1 + ((uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                                   (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7]) + 8;
                }
                else {
                  iVar12 = strncmp(_Str1,&DAT_40ad6424,4);
                  if (iVar12 == 0) {
                    _Str1 = _Str1 + ((uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                                     (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7]) + 8;
                  }
                  else {
                    iVar12 = strncmp(_Str1,&DAT_40ad642c,4);
                    if (iVar12 == 0) {
                      uVar23 = (uint)(byte)_Str1[4];
                      bVar6 = _Str1[5];
                      bVar7 = _Str1[6];
                      uVar21 = (uint)(byte)_Str1[7];
                      if (CONCAT11(_Str1[0xe],_Str1[0xf]) != 0) {
                        puVar14 = FUN_40ac992c(s_AIFF_header_specifies_nonzero_bl_40ad64a4);
                        FUN_40ac98dc((size_t)puVar14,uVar23,uVar21,(va_list)puVar20);
                        return (char *)0x0;
                      }
                      goto LAB_40ac5a48;
                    }
                    uVar21 = (uint)(byte)_Str1[5] << 0x10 | (uint)(byte)_Str1[4] << 0x18 |
                             (uint)(byte)_Str1[6] << 8 | (uint)(byte)_Str1[7];
                    pcVar1 = _Str1 + uVar21 + 8;
                    pcVar16 = _Str1 + uVar21 + 9;
                    _Str1 = _Str1 + uVar21 + 8;
                    if (*pcVar1 == '\0') {
                      _Str1 = pcVar16;
                    }
                  }
                }
              }
            }
          } while ((int)_Str1 - (int)param_1 < local_2c);
          uVar21 = 0;
          goto LAB_40ac50d8;
        }
        uVar21 = 0;
      }
      uVar23 = *param_5;
      *(uint *)(param_6 + 0x124) = uVar22;
      *(uint *)(param_6 + 0x120) = uVar23;
      *(uint *)(param_6 + 0x128) = *param_4;
      *(uint *)(param_6 + 0x80170) = *param_4;
      uVar15 = *param_5;
      uVar23 = *param_4;
      *(undefined4 *)(param_6 + 0x130) = 0;
      *(uint *)(param_6 + 300) = uVar15 * uVar23 * uVar22;
      uVar15 = *param_4;
      uVar23 = *param_5;
      if (uVar15 == 0) {
        trap(7);
      }
      *(undefined4 *)(param_6 + 0x13c) = 0x1523;
      if ((int)uVar23 / 100 == 0) {
        trap(7);
      }
      if (uVar22 == 0) {
        trap(7);
      }
      *(uint *)(param_6 + 0x134) = ((uVar21 / uVar15) / (uint)((int)uVar23 / 100)) / uVar22;
      goto LAB_40ac4c70;
    }
  }
  uVar22 = 0;
LAB_40ac4c70:
  if (*param_2 == 0) {
    *param_2 = uVar22 >> 3;
  }
  return _Str1;
}



/* 40ac5ad0 FUN_40ac5ad0 */

/* Boundary evidence: original MIPS .pdata 40ac5ad0..40ac5bdb. Semantic name remains unreviewed. */

void FUN_40ac5ad0(int *param_1,va_list param_2,int param_3)

{
  undefined2 *puVar1;
  
  *(int *)(param_3 + 0x80170) = *param_1;
  if (2 < *param_1) {
    *param_1 = 2;
    *(undefined4 *)(param_3 + 0x8016c) = 2;
    if (*(int *)(param_3 + 0x80170) != 2) {
      if ((int)param_2 << 1 < 0x20001) {
        if ((uint)((int)param_2 << 2) < 0x40001) {
          *(undefined4 *)(param_3 + 0x15c) = 0;
        }
        else {
          puVar1 = FUN_40ac992c(s_open_downmix_ERROR_MAX_DOWNMIX_I_40ad62e0);
          FUN_40ac98dc((size_t)puVar1,(int)param_2 << 2,0x40000,param_2);
        }
      }
      else {
        puVar1 = FUN_40ac992c(s_open_downmix_ERROR_MAX_DOWNMIX_B_40ad6274);
        FUN_40ac98dc((size_t)puVar1,(int)param_2 << 1,0x20000,param_2);
      }
    }
    return;
  }
  *(int *)(param_3 + 0x8016c) = *param_1;
  return;
}



/* 40ac5bdc FUN_40ac5bdc */

/* Boundary evidence: original MIPS .pdata 40ac5bdc..40ac698f. Semantic name remains unreviewed. */

char * FUN_40ac5bdc(uint *param_1,uint *param_2,int *param_3,uint *param_4,char *param_5,int param_6
                   )

{
  byte *pbVar1;
  int iVar2;
  uint *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  undefined *puVar14;
  uint *puVar15;
  va_list pcVar16;
  char *pcVar17;
  char *_Str1;
  char *_Str1_00;
  char *pcVar18;
  
  pcVar18 = (char *)0xc00;
  if ((int)param_5 < 0xc01) {
    pcVar18 = param_5;
  }
  if ((*(int *)(param_6 + 0x80178) == 0) &&
     (puVar12 = param_4, iVar2 = strncmp(&DAT_40ad6354,(char *)param_4,4), iVar2 != 0)) {
    puVar14 = (undefined *)0x4;
    iVar2 = strncmp(&DAT_40ad6398,(char *)param_4,4);
    if (iVar2 != 0) {
      pcVar17 = (char *)0xc8;
      if ((399 < (int)param_5) || (pcVar17 = param_5 + -200, 0 < (int)pcVar17)) {
        iVar2 = 0;
        do {
          _Str1_00 = (char *)((int)param_4 + iVar2);
          puVar14 = (undefined *)0x4;
          iVar2 = iVar2 + 1;
          iVar6 = strncmp(_Str1_00,&DAT_40ad6354,4);
          if (iVar6 == 0) {
            if (_Str1_00 != (char *)0x0) {
              puVar14 = (undefined *)0x4;
              iVar2 = strncmp(_Str1_00,&DAT_40ad6354,4);
              if (iVar2 == 0) {
                puVar14 = (undefined *)0x4;
                iVar2 = strncmp(_Str1_00 + 8,&DAT_40ad635c,4);
                pcVar17 = (char *)0x0;
                if (iVar2 != 0) goto LAB_40ac5d2c;
                puVar14 = (undefined *)0x4;
                iVar2 = strncmp(_Str1_00 + 0xc,&DAT_40ad6374,4);
                if (iVar2 == 0) {
                  pcVar17 = _Str1_00 + 0x34;
                  goto LAB_40ac61f0;
                }
              }
            }
            break;
          }
        } while (iVar2 < (int)pcVar17);
      }
      goto LAB_40ac5ea8;
    }
  }
  puVar14 = &DAT_40ad76c4;
  puVar12 = param_1 + 1;
  puVar3 = (uint *)FUN_40ac4bbc((char *)param_4,(uint *)(param_6 + 0x8017c),(int *)&DAT_40ad76c4,
                                puVar12,param_1,param_6,(int)param_5);
  *(undefined4 *)(param_6 + 0x80178) = 0;
  *param_3 = 0;
  param_1[2] = 0x2000;
  *(uint *)(param_6 + 0x80170) = param_1[1];
  pcVar17 = (char *)((int)puVar3 - (int)param_4);
  if ((int)param_1[1] < 3) {
    *(uint *)(param_6 + 0x8016c) = param_1[1];
LAB_40ac5cbc:
    iVar2 = *(int *)(param_6 + 0x13c);
  }
  else {
    param_1[1] = 2;
    *(undefined4 *)(param_6 + 0x8016c) = 2;
    if (*(int *)(param_6 + 0x80170) == 2) goto LAB_40ac5cbc;
    iVar2 = *(int *)(param_6 + 0x13c);
    *(undefined4 *)(param_6 + 0x15c) = 0;
  }
  if (iVar2 != 1) {
    return pcVar17;
  }
  pcVar18 = pcVar18 + -(int)pcVar17;
  param_4 = puVar3;
  goto LAB_40ac5d2c;
  while (pcVar17 = _Str1, _Str1 != _Str1_00 + 0x44a) {
LAB_40ac61f0:
    _Str1 = pcVar17 + 1;
    puVar14 = (undefined *)0x4;
    iVar2 = strncmp(_Str1,&DAT_40ad6390,4);
    if (iVar2 == 0) {
      pcVar17 = pcVar17 + (9 - (int)param_4);
      pcVar18 = pcVar18 + -(int)pcVar17;
      param_5 = param_5 + -(int)pcVar17;
      param_4 = (uint *)((int)param_4 + (int)pcVar17);
      goto LAB_40ac5d2c;
    }
  }
LAB_40ac5ea8:
  pcVar17 = (char *)0x0;
LAB_40ac5d2c:
  if ((int)param_5 < 1) {
    puVar4 = FUN_40ac992c(s_decode_wav_audio_inbuf_size__d_40ad64d0);
    FUN_40ac98dc((size_t)puVar4,param_5,puVar14,(va_list)puVar12);
    return (char *)0x1;
  }
  iVar2 = *(int *)(param_6 + 0x13c);
  if (((iVar2 != 0x1523) && (iVar2 != 1)) && (iVar2 != 0xfffe)) {
    if ((iVar2 != 2) && (iVar2 != 0x11)) {
      if (1 < iVar2 - 6U) {
        puVar4 = FUN_40ac992c(s_pcmdecode__unsupported_format__x_40ad6668);
        FUN_40ac98dc((size_t)puVar4,*(undefined4 *)(param_6 + 0x13c),iVar2,(va_list)puVar12);
        *param_3 = 0;
        return param_5;
      }
      if (iVar2 == 6) {
        puVar4 = (undefined2 *)((int)param_2 + (int)(param_5 + -1) * 2);
        puVar12 = (uint *)((int)param_4 + (int)param_5);
        do {
          pbVar1 = (byte *)((int)puVar12 + -1);
          puVar12 = (uint *)((int)puVar12 + -1);
          *puVar4 = *(undefined2 *)(&DAT_40ad668c + (uint)*pbVar1 * 2);
          puVar4 = puVar4 + -1;
        } while (param_4 != puVar12);
      }
      else {
        puVar4 = (undefined2 *)((int)param_2 + (int)(param_5 + -1) * 2);
        puVar12 = (uint *)((int)param_4 + (int)param_5);
        do {
          pbVar1 = (byte *)((int)puVar12 + -1);
          puVar12 = (uint *)((int)puVar12 + -1);
          *puVar4 = *(undefined2 *)(&DAT_40ad688c + (uint)*pbVar1 * 2);
          puVar4 = puVar4 + -1;
        } while (param_4 != puVar12);
      }
      *param_3 = (int)param_5 << 1;
      return param_5;
    }
    puVar3 = *(uint **)(param_6 + 0x130);
    if ((param_5 + -(int)pcVar17 < puVar3) || (puVar3 < (uint *)0x11)) {
      puVar4 = FUN_40ac992c(s_decode_wav_audio_ADPCM_short_inp_40ad6640);
      FUN_40ac98dc((size_t)puVar4,param_5,iVar2,(va_list)puVar12);
      *param_3 = 0;
      return param_5;
    }
    if (iVar2 == 0x11) {
      puVar15 = (uint *)0x11;
      if (*(int *)(param_6 + 0x124) == 4) {
        iVar2 = *(int *)(param_6 + 0x128);
        if ((uint *)(iVar2 * 4) <= puVar3) {
          iVar6 = (int)puVar3 * 2 + iVar2 * -7;
          iVar2 = FUN_40ac3a90(iVar2,iVar6,(undefined2 *)param_4,(va_list)param_2);
          puVar15 = param_4;
          puVar12 = param_2;
          if (iVar2 != 0) {
            *param_3 = iVar6 * 2;
            goto LAB_40ac6434;
          }
        }
      }
      else {
        if (*(int *)(param_6 + 0x124) != 3) {
          puVar4 = FUN_40ac992c(s_pcmdecode__unsupported_adpcm_for_40ad65e8);
          FUN_40ac98dc((size_t)puVar4,*(undefined4 *)(param_6 + 0x13c),
                       *(undefined4 *)(param_6 + 0x124),(va_list)puVar12);
          *param_3 = 0;
          return param_5;
        }
        if ((uint *)(*(int *)(param_6 + 0x128) * 4) <= puVar3) {
          *param_3 = ((int)puVar3 * 2 + *(int *)(param_6 + 0x128) * -7) * 2;
LAB_40ac6434:
          return pcVar17 + *(int *)(param_6 + 0x130);
        }
      }
    }
    else {
      iVar2 = *(int *)(param_6 + 0x128);
      puVar15 = (uint *)(iVar2 * 7);
      pcVar18 = (char *)(iVar2 * -6 + (int)puVar3);
      if (puVar15 <= puVar3) {
        iVar2 = FUN_40ac4424(iVar2,(int)pcVar18 * 2,(byte *)param_4,(va_list)param_2);
        puVar15 = param_4;
        puVar12 = param_2;
        if (iVar2 != 0) {
          *param_3 = (int)pcVar18 * 4;
          goto LAB_40ac6434;
        }
      }
    }
    puVar4 = FUN_40ac992c(s_decode_wav_audio_ADPCM_error__d_40ad661c);
    FUN_40ac98dc((size_t)puVar4,0,puVar15,(va_list)puVar12);
    *param_3 = 0;
    return pcVar17 + *(int *)(param_6 + 0x130);
  }
  if (*(int *)(param_6 + 0x8017c) == 0) {
    uVar8 = *(uint *)(param_6 + 0x124);
    *(uint *)(param_6 + 0x8017c) = uVar8 >> 3;
  }
  else {
    uVar8 = *(uint *)(param_6 + 0x124);
  }
  if (uVar8 == 0xc) {
    iVar6 = *(int *)(param_6 + 0x80170);
    *(undefined4 *)(param_6 + 0x8017c) = 0x800012;
LAB_40ac5ed8:
    iVar6 = iVar6 * 3;
    if (iVar6 == 0) {
      trap(7);
    }
    uVar8 = (uint)(iVar6 * (((int)pcVar18 << 1) / iVar6)) >> 1;
    if (*(int *)(param_6 + 0x80174) == 1) {
      if (uVar8 != 0) {
        iVar2 = ((uVar8 - 1 >> 1) + 1) * 2;
        puVar12 = (uint *)((int)param_2 + iVar2);
        do {
          *(ushort *)param_2 = (ushort)(byte)*param_4 << 8 | *(byte *)((int)param_4 + 1) & 0xf0;
          param_2 = (uint *)((int)param_2 + 2);
          param_4 = (uint *)((int)param_4 + 2);
        } while (param_2 != puVar12);
        goto LAB_40ac5f6c;
      }
    }
    else if (uVar8 != 0) {
      iVar2 = ((uVar8 - 1 >> 1) + 1) * 2;
      puVar12 = (uint *)((int)param_2 + iVar2);
      do {
        *(ushort *)param_2 =
             (ushort)*(byte *)((int)param_4 + 1) << 0xc | (ushort)(byte)*param_4 << 4;
        param_2 = (uint *)((int)param_2 + 2);
        param_4 = (uint *)((int)param_4 + 2);
      } while (param_2 != puVar12);
      goto LAB_40ac5f6c;
    }
    iVar2 = 0;
LAB_40ac5f6c:
    *param_3 = iVar2;
    return pcVar17 + iVar2;
  }
  pcVar16 = (va_list)(param_6 + 0x80000);
  iVar6 = *(int *)(param_6 + 0x80170);
  iVar9 = *(int *)(param_6 + 0x8017c);
  uVar8 = iVar9 * iVar6;
  if (iVar9 == 3) {
    if (uVar8 == 0) {
      trap(7);
    }
    iVar2 = ((uint)pcVar18 / uVar8) * uVar8;
    if (*(int *)(param_6 + 0x80174) == 1) {
      if (iVar2 < 1) goto LAB_40ac68f0;
      iVar2 = (iVar2 - 1U) / 3 + 1;
      iVar6 = iVar2 * 2;
      puVar12 = param_2;
      do {
        *(ushort *)puVar12 = CONCAT11((char)*param_4,*(undefined1 *)((int)param_4 + 1));
        puVar12 = (uint *)((int)puVar12 + 2);
        param_4 = (uint *)((int)param_4 + 3);
      } while (puVar12 != (uint *)((int)param_2 + iVar6));
      iVar2 = iVar2 * 3;
    }
    else if (iVar2 < 1) {
LAB_40ac68f0:
      iVar2 = 0;
      iVar6 = 0;
    }
    else {
      iVar2 = (iVar2 - 1U) / 3 + 1;
      iVar6 = iVar2 * 2;
      puVar12 = param_2;
      do {
        *(undefined2 *)puVar12 = *(undefined2 *)((int)param_4 + 1);
        puVar12 = (uint *)((int)puVar12 + 2);
        param_4 = (uint *)((int)param_4 + 3);
      } while (puVar12 != (uint *)((int)param_2 + iVar6));
      iVar2 = iVar2 * 3;
    }
    uVar5 = (int)(short)*param_2 - (int)*(short *)((int)param_2 + 2);
    uVar8 = (int)uVar5 >> 0x1f;
    if (((uVar5 ^ uVar8) - uVar8 < 0xd000) ||
       (uVar5 = (int)*(short *)((int)param_2 + 2) - (int)(short)param_2[1],
       uVar8 = (int)uVar5 >> 0x1f, (uVar5 ^ uVar8) - uVar8 < 0xd000)) {
      *param_3 = iVar6;
      return pcVar17 + iVar2;
    }
    pcVar18 = s_24_bit_audio_error_detected__try_40ad64f0;
    goto LAB_40ac67bc;
  }
  if (3 < iVar9) {
    if (iVar9 == 8) {
      if (uVar8 == 0) {
        trap(7);
      }
      iVar2 = ((uint)pcVar18 / uVar8) * uVar8;
      if (iVar2 < 1) {
        iVar2 = 0;
      }
      else {
        uVar8 = iVar2 - 1U >> 3;
        puVar12 = (uint *)((int)param_2 + uVar8 * 2);
        while( true ) {
          uVar10 = (uint)*(byte *)((int)param_4 + 1) << 0x10;
          uVar11 = (uint)(byte)*param_4 << 0x18 | uVar10;
          uVar5 = (uint)*(byte *)((int)param_4 + 2) << 8;
          uVar13 = 0x404 - ((uVar11 & 0x7ff00000) >> 0x14);
          iVar2 = 0;
          if ((int)(uVar11 | *(byte *)((int)param_4 + 3) | uVar5) < 0) {
            iVar2 = -1;
          }
          if ((int)uVar13 < 0x20) {
            sVar7 = (short)((uVar10 & 0xfffff | (uint)*(byte *)((int)param_4 + 3) | uVar5 | 0x100000
                            ) >> (uVar13 & 0x1f));
            if (iVar2 != 0) {
              sVar7 = -sVar7;
            }
          }
          else {
            sVar7 = 0;
          }
          param_4 = param_4 + 2;
          *(short *)param_2 = sVar7;
          if (param_2 == puVar12) break;
          param_2 = (uint *)((int)param_2 + 2);
        }
        iVar2 = (uVar8 + 1) * 8;
      }
      *param_3 = iVar2 >> 2;
      return pcVar17 + iVar2;
    }
    if (iVar9 != 0x800012) {
      if (iVar9 == 4) {
        if (uVar8 == 0) {
          trap(7);
        }
        iVar2 = ((uint)pcVar18 / uVar8) * uVar8;
        if (iVar2 < 1) {
          iVar2 = 0;
        }
        else {
          uVar8 = iVar2 - 1U >> 2;
          iVar2 = (int)param_2 + 2;
          do {
            iVar6 = *(int *)(param_6 + 0x80174);
            if ((iVar6 == 2) || (iVar6 == 8)) {
              uVar11 = (uint)*(byte *)((int)param_4 + 1) << 0x10;
              uVar10 = (uint)(byte)*param_4 << 0x18 | uVar11;
              uVar5 = (uint)*(byte *)((int)param_4 + 2) << 8;
              sVar7 = (short)((uVar11 & 0x7fffff | (uint)*(byte *)((int)param_4 + 3) | uVar5 |
                              0x800000) >> (0x87 - (uVar10 >> 0x17) & 0x1f));
              if ((int)(uVar10 | *(byte *)((int)param_4 + 3) | uVar5) < 0) {
                *(short *)(iVar2 + -2) = -sVar7;
              }
              else {
                *(short *)(iVar2 + -2) = sVar7;
              }
            }
            else if (iVar6 == 1) {
              *(ushort *)(iVar2 + -2) = CONCAT11((byte)*param_4,*(byte *)((int)param_4 + 1));
            }
            else {
              *(undefined2 *)(iVar2 + -2) = *(undefined2 *)((int)param_4 + 2);
            }
            iVar2 = iVar2 + 2;
            param_4 = param_4 + 1;
          } while (iVar2 != (int)param_2 + (uVar8 + 2) * 2);
          iVar2 = (uVar8 + 1) * 4;
        }
        *param_3 = iVar2 >> 1;
        return pcVar17 + iVar2;
      }
LAB_40ac5df0:
      puVar4 = FUN_40ac992c(s_sample_size__d_not_supported_40ad65c8);
      FUN_40ac98dc((size_t)puVar4,*(undefined4 *)(param_6 + 0x8017c),iVar2,pcVar16);
      *param_3 = 0;
      return (char *)0xffffffff;
    }
    goto LAB_40ac5ed8;
  }
  if (iVar9 == 1) {
    if (uVar8 == 0) {
      trap(7);
    }
    iVar6 = ((uint)pcVar18 / uVar8) * uVar8;
    if (iVar2 == 0x1523) {
      if (0 < iVar6) {
        iVar2 = 0;
        do {
          iVar2 = iVar2 + 1;
          *(ushort *)param_2 = (ushort)(byte)*param_4 << 8;
          param_4 = (uint *)((int)param_4 + 1);
          param_2 = (uint *)((int)param_2 + 2);
        } while (iVar2 < iVar6);
        goto LAB_40ac62ac;
      }
    }
    else if (0 < iVar6) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        *(ushort *)param_2 = (ushort)(byte)*param_4 * 0x100 + -0x8000;
        param_4 = (uint *)((int)param_4 + 1);
        param_2 = (uint *)((int)param_2 + 2);
      } while (iVar2 < iVar6);
LAB_40ac62ac:
      iVar2 = iVar6 * 2;
      goto LAB_40ac62b0;
    }
    iVar6 = 0;
    iVar2 = 0;
LAB_40ac62b0:
    *param_3 = iVar2;
    return pcVar17 + iVar6;
  }
  if (iVar9 != 2) goto LAB_40ac5df0;
  if (uVar8 == 0) {
    trap(7);
  }
  iVar2 = ((uint)pcVar18 / uVar8) * uVar8;
  if (*(int *)(param_6 + 0x80174) == 1) {
    if (iVar2 < 1) goto LAB_40ac65a8;
    puVar12 = param_2;
    do {
      *(ushort *)puVar12 = CONCAT11((char)*param_4,*(undefined1 *)((int)param_4 + 1));
      puVar12 = (uint *)((int)puVar12 + 2);
      param_4 = (uint *)((int)param_4 + 2);
    } while (puVar12 != (uint *)((int)param_2 + ((iVar2 - 1U >> 1) + 1) * 2));
    uVar8 = param_1[1];
  }
  else {
    if (0 < iVar2) {
      puVar12 = param_2;
      do {
        *(short *)puVar12 = (short)*param_4;
        puVar12 = (uint *)((int)puVar12 + 2);
        param_4 = (uint *)((int)param_4 + 2);
      } while (puVar12 != (uint *)((int)param_2 + ((iVar2 - 1U >> 1) + 1) * 2));
    }
LAB_40ac65a8:
    uVar8 = param_1[1];
  }
  if (uVar8 == 1) {
    uVar5 = (int)(short)*param_2 - (int)*(short *)((int)param_2 + 2);
    uVar8 = (int)uVar5 >> 0x1f;
    if ((0xcfff < (uVar5 ^ uVar8) - uVar8) &&
       (uVar5 = (int)*(short *)((int)param_2 + 2) - (int)(short)param_2[1],
       uVar8 = (int)uVar5 >> 0x1f, 0xcfff < (uVar5 ^ uVar8) - uVar8)) {
      pcVar18 = s_16_bit_mono_audio_error_detected_40ad6534;
LAB_40ac67bc:
      puVar4 = FUN_40ac992c(pcVar18);
      FUN_40ac98dc((size_t)puVar4,(int)(short)*param_2,(int)*(short *)((int)param_2 + 2),
                   (va_list)(int)(short)param_2[1]);
      *param_3 = 0;
      return pcVar17 + 1;
    }
  }
  else if (uVar8 == 2) {
    uVar5 = (int)(short)*param_2 - (int)(short)param_2[1];
    uVar8 = (int)uVar5 >> 0x1f;
    if ((0xcfff < (uVar5 ^ uVar8) - uVar8) &&
       (uVar5 = (int)*(short *)((int)param_2 + 2) - (int)*(short *)((int)param_2 + 6),
       uVar8 = (int)uVar5 >> 0x1f, 0xcfff < (uVar5 ^ uVar8) - uVar8)) {
      puVar4 = FUN_40ac992c(s_16_bit_stereo_audio_error_detect_40ad657c);
      FUN_40ac98dc((size_t)puVar4,(int)(short)*param_2,(int)(short)param_2[1],
                   (va_list)(int)*(short *)((int)param_2 + 2));
      *param_3 = 0;
      return pcVar17 + 1;
    }
    *param_3 = iVar2;
    return pcVar17 + iVar2;
  }
  *param_3 = iVar2;
  return pcVar17 + iVar2;
}



/* 40ac6990 FUN_40ac6990 */

/* Boundary evidence: original MIPS .pdata 40ac6990..40ac6e23. Semantic name remains unreviewed. */

void FUN_40ac6990(char *param_1,int *param_2,undefined4 *param_3,int param_4,ushort *param_5,
                 int param_6)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  va_list pcVar8;
  
  if (*param_1 == -0x60) {
    param_2[1] = ((byte)param_1[5] & 7) + 1;
    bVar5 = (byte)param_1[5] >> 4 & 3;
    if (bVar5 == 2) {
      *param_2 = 0xac44;
    }
    else if (bVar5 == 3) {
      *param_2 = 32000;
    }
    else if (bVar5 == 1) {
      *param_2 = 96000;
    }
    else {
      *param_2 = 48000;
    }
    if (7 < param_2[1] - 1U) {
      param_2[1] = 2;
    }
    *(undefined4 *)(param_6 + 0x80178) = 0;
    *(undefined4 *)(param_6 + 0x80174) = 0;
    *param_3 = 1;
    param_2[2] = 0x2000;
    param_2[3] = 0x10;
    *(int *)(param_6 + 0x120) = *param_2;
    *(int *)(param_6 + 0x124) = param_2[3];
    *(int *)(param_6 + 0x130) = param_4 + -7;
    *(undefined4 *)(param_6 + 0x13c) = 1;
    *(undefined4 *)(param_6 + 0x134) = 0;
    *(undefined4 *)(param_6 + 0x138) = 0;
    iVar7 = param_2[1];
    pcVar8 = (va_list)param_2[2];
    *(int *)(param_6 + 0x80170) = iVar7;
    if (iVar7 < 3) {
      *(int *)(param_6 + 0x8016c) = iVar7;
    }
    else {
      *(undefined4 *)(param_6 + 0x8016c) = 2;
      FUN_40ac4718(pcVar8,2,param_6);
      iVar7 = 2;
    }
    param_2[1] = iVar7;
    *(int *)(param_6 + 0x128) = iVar7;
    *(int *)(param_6 + 300) = *param_2 * param_2[3] * param_2[1];
    param_2[2] = 0x2000;
    return;
  }
  uVar1 = param_5[1];
  param_2[1] = (uint)uVar1;
  *param_2 = *(int *)(param_5 + 2);
  if (7 < uVar1 - 1) {
    param_2[1] = 2;
  }
  uVar6 = (uint)param_5[7];
  *param_3 = 2;
  param_2[3] = uVar6;
  uVar1 = param_5[1];
  *(undefined4 *)(param_6 + 0x120) = *(undefined4 *)(param_5 + 2);
  *(uint *)(param_6 + 0x124) = uVar6;
  param_2[3] = uVar6;
  *(uint *)(param_6 + 0x128) = (uint)uVar1;
  uVar1 = param_5[6];
  uVar2 = *param_5;
  *(int *)(param_6 + 300) = *(int *)(param_5 + 4) << 3;
  *(uint *)(param_6 + 0x130) = (uint)uVar1;
  *(uint *)(param_6 + 0x13c) = (uint)uVar2;
  switch(*(undefined4 *)(param_6 + 0x80174)) {
  case 4:
  case 6:
    iVar7 = param_2[1];
    *param_5 = 6;
    pcVar8 = (va_list)param_2[2];
    *(int *)(param_6 + 0x80170) = iVar7;
    break;
  case 5:
  case 7:
    iVar7 = param_2[1];
    *param_5 = 7;
    pcVar8 = (va_list)param_2[2];
    *(int *)(param_6 + 0x80170) = iVar7;
    break;
  default:
    iVar7 = param_2[1];
    pcVar8 = (va_list)param_2[2];
    *(int *)(param_6 + 0x80170) = iVar7;
    break;
  case 10:
    iVar7 = param_2[1];
    *param_5 = 0x11;
    pcVar8 = (va_list)param_2[2];
    *(int *)(param_6 + 0x80170) = iVar7;
  }
  if (iVar7 < 3) {
    *(int *)(param_6 + 0x8016c) = iVar7;
LAB_40ac6a70:
    param_2[2] = 0x2000;
    param_2[1] = iVar7;
    iVar7 = *(int *)(param_6 + 0x13c);
    if (iVar7 == 2) goto LAB_40ac6b84;
LAB_40ac6a90:
    if (iVar7 == 0x11) goto LAB_40ac6b84;
    uVar6 = (uint)*param_5;
    if ((uVar6 - 6 & 0xffff) < 2) {
      *(uint *)(param_6 + 0x13c) = uVar6;
      *param_3 = 0;
      param_2[3] = 0x10;
    }
    else if (0xfffd < (uVar6 - 1 & 0xffff)) {
      *(undefined4 *)(param_6 + 0x13c) = 1;
    }
    if (uVar6 == 0x1523) goto LAB_40ac6b98;
LAB_40ac6ad0:
    *(undefined4 *)(param_6 + 0x80174) = 0;
    *(undefined4 *)(param_6 + 0x80178) = 0;
    uVar3 = 1;
    if (uVar6 != 0xa5a6) goto LAB_40ac6ae8;
  }
  else {
    *(undefined4 *)(param_6 + 0x8016c) = 2;
    if (0x20000 < (int)pcVar8 << 1) {
      puVar4 = FUN_40ac992c(s_open_downmix_ERROR_MAX_DOWNMIX_B_40ad6274);
      FUN_40ac98dc((size_t)puVar4,(int)pcVar8 << 1,0x20000,pcVar8);
      iVar7 = 2;
      goto LAB_40ac6a70;
    }
    if (0x40000 < (uint)((int)pcVar8 << 2)) {
      puVar4 = FUN_40ac992c(s_open_downmix_ERROR_MAX_DOWNMIX_I_40ad62e0);
      FUN_40ac98dc((size_t)puVar4,(int)pcVar8 << 2,0x40000,pcVar8);
      iVar7 = 2;
      goto LAB_40ac6a70;
    }
    *(undefined4 *)(param_6 + 0x15c) = 0;
    param_2[2] = 0x2000;
    param_2[1] = 2;
    iVar7 = *(int *)(param_6 + 0x13c);
    if (iVar7 != 2) goto LAB_40ac6a90;
LAB_40ac6b84:
    uVar6 = (uint)*param_5;
    param_2[3] = 0x10;
    if (uVar6 != 0x1523) goto LAB_40ac6ad0;
LAB_40ac6b98:
    *(undefined4 *)(param_6 + 0x80178) = 0;
    if (uVar6 == 0xa5a6) {
      *param_3 = 1;
      goto LAB_40ac6af0;
    }
LAB_40ac6ae8:
    uVar3 = *param_3;
  }
  *param_3 = uVar3;
LAB_40ac6af0:
  if (0x10 < param_2[3]) {
    param_2[3] = 0x10;
  }
  return;
}



/* 40ac6e24 FUN_40ac6e24 */

/* Boundary evidence: original MIPS .pdata 40ac6e24..40ac6eef. Semantic name remains unreviewed. */

void FUN_40ac6e24(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  wchar_t local_410 [256];
  wchar_t local_210 [256];
  uint local_10;
  
  local_10 = DAT_40ad707c;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(local_210,param_1,(wchar_t *)&local_res4,param_4);
  pwVar3 = L"PCMDECFILTER: ";
  pwVar2 = local_410;
  do {
    wVar1 = *pwVar3;
    pwVar3 = pwVar3 + 1;
    *pwVar2 = wVar1;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  pwVar3 = local_210;
  pwVar2 = local_410;
  do {
    pwVar4 = pwVar2;
    pwVar2 = pwVar4 + 1;
  } while (*pwVar4 != L'\0');
  do {
    wVar1 = *pwVar3;
    pwVar3 = pwVar3 + 1;
    *pwVar4 = wVar1;
    pwVar4 = pwVar4 + 1;
  } while (wVar1 != L'\0');
  pwVar3 = L"\r\n";
  pwVar2 = local_410;
  do {
    pwVar4 = pwVar2;
    pwVar2 = pwVar4 + 1;
  } while (*pwVar4 != L'\0');
  do {
    wVar1 = *pwVar3;
    pwVar3 = pwVar3 + 1;
    *pwVar4 = wVar1;
    pwVar4 = pwVar4 + 1;
  } while (wVar1 != L'\0');
  OutputDebugStringW(local_410);
  FUN_40ad0c64(local_10);
  return;
}



/* 40ac6ef0 FUN_40ac6ef0 */

/* WARNING: Instruction at (ram,0x40ac6f28) overlaps instruction at (ram,0x40ac6f24)
    */

int * FUN_40ac6ef0(int *param_1,int *param_2,uint param_3)

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
LAB_40ac70d8:
    if (param_3 == 0) {
      return param_1;
    }
  }
  else {
    prefetch(param_2 + 0x10,0);
    prefetch(param_1 + 0x10,1);
    if (uVar9 == 0) {
      if (uVar8 != 0) {
LAB_40ac7050:
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
        if (uVar8 == param_3) goto LAB_40ac70e0;
        do {
          iVar10 = *param_2;
          param_2 = param_2 + 1;
          param_3 = param_3 - 4;
          *piVar6 = iVar10;
          piVar6 = piVar6 + 1;
        } while (param_3 != uVar8);
        goto LAB_40ac70d8;
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
      if (uVar8 != uVar9) goto LAB_40ac7050;
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
LAB_40ac70e0:
  *(char *)piVar6 = (char)*param_2;
  if ((param_3 != 1) &&
     (*(undefined1 *)((int)piVar6 + 1) = *(undefined1 *)((int)param_2 + 1), param_3 != 2)) {
    *(undefined1 *)((int)piVar6 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
  return param_1;
}



/* 40ac7118 FUN_40ac7118 */

/* Boundary evidence: original MIPS .pdata 40ac7118..40ac7133. Semantic name remains unreviewed. */

void FUN_40ac7118(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40ac7134 FUN_40ac7134 */

/* Boundary evidence: original MIPS .pdata 40ac7134..40ac714f. Semantic name remains unreviewed. */

void FUN_40ac7134(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  return;
}



/* 40ac7150 DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40ac7150..40ac716b. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0x7150  4  DllRegisterServer */
  FUN_40acb554(1);
  return;
}



/* 40ac716c DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40ac716c..40ac7187. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0x716c  5  DllUnregisterServer */
  FUN_40acb554(0);
  return;
}



/* 40ac7188 DllMain */

/* Boundary evidence: original MIPS .pdata 40ac7188..40ac71a3. Semantic name remains unreviewed. */

void DllMain(HMODULE param_1,int param_2)

{
                    /* 0x7188  3  DllMain */
  FUN_40acb64c(param_1,param_2);
  return;
}



/* 40ac71a4 FUN_40ac71a4 */

/* Boundary evidence: original MIPS .pdata 40ac71a4..40ac71df. Semantic name remains unreviewed. */

undefined4 FUN_40ac71a4(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40acac40(param_1 + 0x50);
  if (iVar1 == 0) {
    return 0;
  }
  return 0x80004005;
}



/* 40ac71e0 FUN_40ac71e0 */

/* Boundary evidence: original MIPS .pdata 40ac71e0..40ac721b. Semantic name remains unreviewed. */

undefined4 FUN_40ac71e0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40acac5c(param_1 + 0x50);
  if (iVar1 == 0) {
    return 0;
  }
  return 0x80004005;
}



/* 40ac721c FUN_40ac721c */

/* Boundary evidence: original MIPS .pdata 40ac721c..40ac723b. Semantic name remains unreviewed. */

undefined4 FUN_40ac721c(int param_1)

{
  FUN_40acad28(param_1 + 0x50);
  return 0;
}



/* 40ac723c FUN_40ac723c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40ac723c..40ac73c3. Semantic name remains unreviewed. */

undefined4 FUN_40ac723c(int param_1,void *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  void *pvVar2;
  size_t _Size;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd05e0) + 0x34))(*(int **)(param_1 + 0xd05e0),0,0);
  _Size = 0x10;
  if (iVar1 == 0) {
    pvVar2 = (void *)0x0;
    iVar1 = memcmp(param_2,(void *)0x0,0x10);
    if (iVar1 == 0) {
      _Size = 0x10;
      pvVar2 = (void *)0x10;
      iVar1 = memcmp((void *)((int)param_2 + 0x10),(void *)0x10,0x10);
      if ((iVar1 == 0) && (*(int *)((int)param_2 + 0x28) == _DAT_00000028)) {
        _Size = 0x10;
        pvVar2 = (void *)0x2c;
        iVar1 = memcmp((void *)((int)param_2 + 0x2c),(void *)0x2c,0x10);
        if ((iVar1 == 0) &&
           ((_Size = *(size_t *)((int)param_2 + 0x40), _Size == _DAT_00000040 &&
            (pvVar2 = _DAT_00000044,
            iVar1 = memcmp(*(void **)((int)param_2 + 0x44),_DAT_00000044,_Size), iVar1 == 0)))) {
          return 0;
        }
      }
    }
    FUN_40ac6e24(0x40ad277c,pvVar2,_Size,param_4);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40ad3898,0x10);
    if (iVar1 == 0) {
      pvVar2 = (void *)((int)param_2 + 0x10);
      iVar1 = memcmp(pvVar2,&DAT_40ad23dc,0x10);
      if ((((iVar1 == 0) || (iVar1 = memcmp(pvVar2,&DAT_40ad242c,0x10), iVar1 == 0)) ||
          (iVar1 = memcmp(pvVar2,&DAT_40ad275c,0x10), iVar1 == 0)) ||
         (iVar1 = memcmp(pvVar2,&DAT_40ad276c,0x10), iVar1 == 0)) {
        return 0;
      }
    }
  }
  return 0x80070057;
}



/* 40ac73c4 FUN_40ac73c4 */

/* Boundary evidence: original MIPS .pdata 40ac73c4..40ac7473. Semantic name remains unreviewed. */

undefined4 FUN_40ac73c4(int param_1,int param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = -0x7fffbffb;
  iVar2 = 0x10;
  iVar1 = memcmp((void *)(param_2 + 0x2c),&DAT_40ad4458,0x10);
  if (iVar1 == 0) {
    iVar2 = param_1 + 0x50;
    iVar3 = FUN_40aca0bc(*(int **)(param_2 + 0x44),*(ushort *)(*(int **)(param_2 + 0x44) + 4) + 0x12
                         ,iVar2,param_4);
    if (iVar3 == 0) {
      return 0;
    }
  }
  FUN_40ac6e24(0x40ad27f4,iVar3,iVar2,param_4);
  return 0x80004005;
}



/* 40ac7474 FUN_40ac7474 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40ac7474..40ac75c3. Semantic name remains unreviewed. */

undefined4 FUN_40ac7474(int param_1,void *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  void *pvVar2;
  size_t _Size;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd05e4) + 0x34))(*(int **)(param_1 + 0xd05e4),0,0);
  _Size = 0x10;
  if (iVar1 == 0) {
    pvVar2 = (void *)0x0;
    iVar1 = memcmp(param_2,(void *)0x0,0x10);
    if (iVar1 == 0) {
      _Size = 0x10;
      pvVar2 = (void *)0x10;
      iVar1 = memcmp((void *)((int)param_2 + 0x10),(void *)0x10,0x10);
      if ((iVar1 == 0) && (*(int *)((int)param_2 + 0x28) == _DAT_00000028)) {
        _Size = 0x10;
        pvVar2 = (void *)0x2c;
        iVar1 = memcmp((void *)((int)param_2 + 0x2c),(void *)0x2c,0x10);
        if ((iVar1 == 0) &&
           ((_Size = *(size_t *)((int)param_2 + 0x40), _Size == _DAT_00000040 &&
            (pvVar2 = _DAT_00000044,
            iVar1 = memcmp(*(void **)((int)param_2 + 0x44),_DAT_00000044,_Size), iVar1 == 0)))) {
          return 0;
        }
      }
    }
    FUN_40ac6e24(0x40ad282c,pvVar2,_Size,param_4);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40ad3898,0x10);
    if (iVar1 == 0) {
      iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40ad23ec,0x10);
      if ((iVar1 == 0) ||
         (iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40ad3c78,0x10), iVar1 == 0)) {
        return 0;
      }
    }
  }
  return 0x80070057;
}



/* 40ac75c4 FUN_40ac75c4 */

/* Boundary evidence: original MIPS .pdata 40ac75c4..40ac7733. Semantic name remains unreviewed. */

undefined4 FUN_40ac75c4(int param_1,uint param_2,undefined4 *param_3,va_list param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (param_2 < 2) {
    if (param_3 != (undefined4 *)0x0) {
      uVar1 = 0x12;
      puVar3 = param_3;
      FUN_40acbb44((int)param_3,0x12);
      if (param_3[0x10] != 0) {
        iVar4 = param_1 + 0x50;
        iVar2 = FUN_40aca278((undefined1 *)param_3[0x11],0x12,iVar4,param_4);
        if (iVar2 != 0) {
          FUN_40ac6e24(0x40ad28a8,iVar2,iVar4,param_4);
          return 0;
        }
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
        return 0;
      }
      FUN_40ac6e24(0x40ad28e0,uVar1,puVar3,param_4);
    }
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = 0x40103;
  }
  return uVar1;
}



/* 40ac7734 FUN_40ac7734 */

undefined4 FUN_40ac7734(void)

{
  return 0;
}



/* 40ac7778 FUN_40ac7778 */

/* Boundary evidence: original MIPS .pdata 40ac7778..40ac77df. Semantic name remains unreviewed. */

void FUN_40ac7778(int param_1,int *param_2,undefined4 *param_3)

{
  undefined1 auStack_18 [16];
  
  *param_3 = *(undefined4 *)(param_1 + 0xd062c);
  param_3[1] = *(undefined4 *)(param_1 + 0xd0628);
  param_3[2] = 4;
  param_3[3] = 0;
  (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_18);
  return;
}



/* 40ac77e0 FUN_40ac77e0 */

/* Boundary evidence: original MIPS .pdata 40ac77e0..40ac78c3. Semantic name remains unreviewed. */

undefined4 *
FUN_40ac77e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  FUN_40acf26c(param_1,param_2,(undefined4 *)0x0,(LPCRITICAL_SECTION)(param_1 + 0x3417d),param_4);
  *param_1 = &PTR_FUN_40ad2964;
  param_1[3] = &PTR_FUN_40ad2928;
  param_1[0x34178] = 0;
  param_1[0x34179] = 0;
  param_1[4] = &PTR_LAB_40ad2914;
  param_1[0x3417a] = param_6;
  param_1[0x3417b] = param_7;
  param_1[0x3417c] = param_8;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3417d));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34182));
  return param_1;
}



/* 40ac78c4 FUN_40ac78c4 */

/* Boundary evidence: original MIPS .pdata 40ac78c4..40ac78eb. Semantic name remains unreviewed. */

void FUN_40ac78c4(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40ac78ec FUN_40ac78ec */

/* Boundary evidence: original MIPS .pdata 40ac78ec..40ac7913. Semantic name remains unreviewed. */

void FUN_40ac78ec(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40ac7914 FUN_40ac7914 */

/* Boundary evidence: original MIPS .pdata 40ac7914..40ac793b. Semantic name remains unreviewed. */

void FUN_40ac7914(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40ac7944 FUN_40ac7944 */

/* Boundary evidence: original MIPS .pdata 40ac7944..40ac7a2b. Semantic name remains unreviewed. */

void FUN_40ac7944(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40ad2964;
  param_1[3] = &PTR_FUN_40ad2928;
  param_1[4] = &PTR_LAB_40ad2914;
  piVar1 = (int *)param_1[0x34178];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
    param_1[0x34178] = 0;
  }
  piVar1 = (int *)param_1[0x34179];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
    param_1[0x34179] = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34182));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3417d));
  FUN_40acd9b0((int)param_1);
  return;
}



/* 40ac7a2c FUN_40ac7a2c */

/* Boundary evidence: original MIPS .pdata 40ac7a2c..40ac7a5b. Semantic name remains unreviewed. */

void FUN_40ac7a2c(void)

{
  int *in_v0;
  
  FUN_40acd9b0(*in_v0);
  return;
}



/* 40ac7a5c FUN_40ac7a5c */

/* Boundary evidence: original MIPS .pdata 40ac7a5c..40ac7a97. Semantic name remains unreviewed. */

void FUN_40ac7a5c(void)

{
  int *in_v0;
  
  FUN_40ac7118((LPCRITICAL_SECTION)(*in_v0 + 0xd05f4));
  return;
}



/* 40ac7a98 FUN_40ac7a98 */

/* Boundary evidence: original MIPS .pdata 40ac7a98..40ac7ad3. Semantic name remains unreviewed. */

void FUN_40ac7a98(void)

{
  int *in_v0;
  
  FUN_40ac7118((LPCRITICAL_SECTION)(*in_v0 + 0xd0608));
  return;
}



/* 40ac7ad4 FUN_40ac7ad4 */

/* Boundary evidence: original MIPS .pdata 40ac7ad4..40ac7aef. Semantic name remains unreviewed. */

void FUN_40ac7ad4(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40acd8d0(param_1,param_2,param_3);
  return;
}



/* 40ac7af0 FUN_40ac7af0 */

/* Boundary evidence: original MIPS .pdata 40ac7af0..40ac7baf. Semantic name remains unreviewed. */

int FUN_40ac7af0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x34182);
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



/* 40ac7bb0 FUN_40ac7bb0 */

/* Boundary evidence: original MIPS .pdata 40ac7bb0..40ac7bdf. Semantic name remains unreviewed. */

void FUN_40ac7bb0(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40ac7be0 FUN_40ac7be0 */

/* Boundary evidence: original MIPS .pdata 40ac7be0..40ac7cb3. Semantic name remains unreviewed. */

int FUN_40ac7be0(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x34182);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1);
  if (iVar1 < 0) {
    FUN_40ac6e24(0x40ad2ab0,iVar1,param_3,param_4);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if ((int *)param_1[0x34179] != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)param_1[0x34179] + 0x4c))();
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40ac7cb4 FUN_40ac7cb4 */

/* Boundary evidence: original MIPS .pdata 40ac7cb4..40ac7ce3. Semantic name remains unreviewed. */

void FUN_40ac7cb4(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40ac7ce4 FUN_40ac7ce4 */

/* Boundary evidence: original MIPS .pdata 40ac7ce4..40ac7d73. Semantic name remains unreviewed. */

int FUN_40ac7ce4(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  if (iVar1 < 0) {
    FUN_40ac6e24(0x40ad2b50,iVar1,param_3,param_4);
  }
  else if ((int *)param_1[0x34179] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1[0x34179] + 0x50))();
  }
  return iVar1;
}



/* 40ac7d74 FUN_40ac7d74 */

/* Boundary evidence: original MIPS .pdata 40ac7d74..40ac7e03. Semantic name remains unreviewed. */

int FUN_40ac7d74(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))(param_1);
  if (iVar1 < 0) {
    FUN_40ac6e24(0x40ad2b84,iVar1,param_3,param_4);
  }
  else if ((int *)param_1[0x34179] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1[0x34179] + 0x54))();
  }
  return iVar1;
}



/* 40ac7e04 FUN_40ac7e04 */

/* Boundary evidence: original MIPS .pdata 40ac7e04..40ac7f77. Semantic name remains unreviewed. */

int FUN_40ac7e04(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x3417a);
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



/* 40ac7f78 FUN_40ac7f78 */

/* Boundary evidence: original MIPS .pdata 40ac7f78..40ac7fa7. Semantic name remains unreviewed. */

void FUN_40ac7f78(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40ac7fa8 FUN_40ac7fa8 */

/* Boundary evidence: original MIPS .pdata 40ac7fa8..40ac80b7. Semantic name remains unreviewed. */

int FUN_40ac7fa8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xd05e8);
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



/* 40ac80b8 FUN_40ac80b8 */

/* Boundary evidence: original MIPS .pdata 40ac80b8..40ac80e7. Semantic name remains unreviewed. */

void FUN_40ac80b8(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40ac80e8 FUN_40ac80e8 */

/* Boundary evidence: original MIPS .pdata 40ac80e8..40ac81ff. Semantic name remains unreviewed. */

undefined4 FUN_40ac80e8(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xd05e8);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    piVar1 = (int *)(param_1 + -0xc);
    (**(code **)(*piVar1 + 0x28))(piVar1);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd05fc));
    (**(code **)(*piVar1 + 0x2c))(piVar1);
    (**(code **)(**(int **)(param_1 + 0xd05d4) + 0x18))();
    (**(code **)(**(int **)(param_1 + 0xd05d8) + 0x18))();
    *(undefined4 *)(param_1 + 8) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd05fc));
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* 40ac8200 FUN_40ac8200 */

/* Boundary evidence: original MIPS .pdata 40ac8200..40ac822f. Semantic name remains unreviewed. */

void FUN_40ac8200(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40ac8230 FUN_40ac8230 */

/* Boundary evidence: original MIPS .pdata 40ac8230..40ac825f. Semantic name remains unreviewed. */

void FUN_40ac8230(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40ac8260 FUN_40ac8260 */

/* Boundary evidence: original MIPS .pdata 40ac8260..40ac827b. Semantic name remains unreviewed. */

void FUN_40ac8260(int param_1)

{
  FUN_40acc54c(param_1);
  return;
}



/* 40ac827c FUN_40ac827c */

/* Boundary evidence: original MIPS .pdata 40ac827c..40ac837b. Semantic name remains unreviewed. */

undefined4 FUN_40ac827c(int *param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[6] == 0) {
    FUN_40ac6e24(0x40ad2cf0,*param_2,param_3,param_4);
    (**(code **)(*param_2 + 8))(param_2);
    return 1;
  }
  iVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
  if (iVar1 < 0x40) {
    (**(code **)(*param_2 + 8))(param_2);
    return 0;
  }
  if ((LPCRITICAL_SECTION)param_1[0x2b] != (LPCRITICAL_SECTION)0x0) {
    uVar2 = FUN_40ad005c((LPCRITICAL_SECTION)param_1[0x2b],param_2);
    return uVar2;
  }
  uVar2 = (**(code **)(*param_1 + 0x44))(param_1);
  (**(code **)(*param_2 + 8))(param_2);
  return uVar2;
}



/* 40ac837c FUN_40ac837c */

/* Boundary evidence: original MIPS .pdata 40ac837c..40ac83d3. Semantic name remains unreviewed. */

undefined4 FUN_40ac837c(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40acf610(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40accda8(param_1);
  return uVar1;
}



/* 40ac83d4 FUN_40ac83d4 */

/* Boundary evidence: original MIPS .pdata 40ac83d4..40ac842b. Semantic name remains unreviewed. */

undefined4 FUN_40ac83d4(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40acffa8(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40accde8(param_1);
  return uVar1;
}



/* 40ac842c FUN_40ac842c */

/* Boundary evidence: original MIPS .pdata 40ac842c..40ac8483. Semantic name remains unreviewed. */

undefined4 FUN_40ac842c(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40acff08(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40accc44(param_1);
  return uVar1;
}



/* 40ac8484 FUN_40ac8484 */

/* Boundary evidence: original MIPS .pdata 40ac8484..40ac858f. Semantic name remains unreviewed. */

HRESULT FUN_40ac8484(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = memcmp(param_2,&DAT_40ad37b8,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40ad4e18,0x10), iVar1 == 0)) {
    piVar4 = param_1 + 0x28;
    if (*piVar4 == 0) {
      iVar1 = *(int *)(param_1[0x1c] + 0xd05e0) + 0xc;
      if (*(int *)(param_1[0x1c] + 0xd05e0) == 0) {
        iVar1 = 0;
      }
      piVar3 = piVar4;
      HVar2 = FUN_40acbfa8((LPUNKNOWN)param_1[1],0,iVar1,piVar4);
      if (HVar2 < 0) {
        FUN_40ac6e24(0x40ad2d2c,HVar2,iVar1,(va_list)piVar3);
        return HVar2;
      }
    }
    HVar2 = (*(code *)**(undefined4 **)*piVar4)((undefined4 *)*piVar4,param_2,param_3);
  }
  else {
    HVar2 = FUN_40acc590(param_1,param_2,param_3);
  }
  return HVar2;
}



/* 40ac8590 FUN_40ac8590 */

/* Boundary evidence: original MIPS .pdata 40ac8590..40ac85eb. Semantic name remains unreviewed. */

int FUN_40ac8590(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  
  iVar1 = FUN_40acccc4(param_1);
  if (-1 < iVar1) {
    p_Var2 = *(LPCRITICAL_SECTION *)(param_1 + 0xac);
    if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
      FUN_40acfac4(p_Var2);
      operator_delete(p_Var2);
      *(undefined4 *)(param_1 + 0xac) = 0;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 40ac85ec FUN_40ac85ec */

/* Boundary evidence: original MIPS .pdata 40ac85ec..40ac86f7. Semantic name remains unreviewed. */

DWORD FUN_40ac85ec(int param_1)

{
  DWORD DVar1;
  LPCRITICAL_SECTION p_Var2;
  DWORD local_18;
  LPCRITICAL_SECTION local_14;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    DVar1 = 0;
  }
  else {
    DVar1 = FUN_40accc84(param_1);
    if (-1 < (int)DVar1) {
      local_18 = 0;
      DVar1 = 0;
      if (*(int *)(param_1 + 0xa4) != 0) {
        local_14 = operator_new(0x54);
        if (local_14 == (LPCRITICAL_SECTION)0x0) {
          p_Var2 = (LPCRITICAL_SECTION)0x0;
        }
        else {
          p_Var2 = FUN_40ad00d8(local_14,*(undefined4 **)(param_1 + 0x18),&local_18,0,1,1,0,
                                *(undefined4 *)(param_1 + 0xa8),3);
        }
        *(LPCRITICAL_SECTION *)(param_1 + 0xac) = p_Var2;
        if (p_Var2 == (LPCRITICAL_SECTION)0x0) {
          DVar1 = 0x8007000e;
        }
        else {
          DVar1 = local_18;
          if ((int)local_18 < 0) {
            FUN_40acfac4(p_Var2);
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



/* 40ac86f8 FUN_40ac86f8 */

/* Boundary evidence: original MIPS .pdata 40ac86f8..40ac8727. Semantic name remains unreviewed. */

void FUN_40ac86f8(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x14));
  return;
}



/* 40ac8728 FUN_40ac8728 */

/* Boundary evidence: original MIPS .pdata 40ac8728..40ac874f. Semantic name remains unreviewed. */

void FUN_40ac8728(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x3c))();
  return;
}



/* 40ac8750 FUN_40ac8750 */

/* Boundary evidence: original MIPS .pdata 40ac8750..40ac876b. Semantic name remains unreviewed. */

void FUN_40ac8750(int param_1,void *param_2)

{
  FUN_40acc690(param_1,param_2);
  return;
}



/* 40ac876c FUN_40ac876c */

/* Boundary evidence: original MIPS .pdata 40ac876c..40ac87c3. Semantic name remains unreviewed. */

undefined4 FUN_40ac876c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)((*(int **)(param_1 + 0x70))[0x34178] + 0x18) != 0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x70) + 0x40))();
    return uVar1;
  }
  return 0x40103;
}



/* 40ac87c4 FUN_40ac87c4 */

/* Boundary evidence: original MIPS .pdata 40ac87c4..40ac8807. Semantic name remains unreviewed. */

void FUN_40ac87c4(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_40acc900(param_1);
  if (-1 < iVar1) {
    (**(code **)(*(int *)param_1[0x1c] + 0x44))((int *)param_1[0x1c],param_1 + 7);
  }
  return;
}



/* 40ac8808 FUN_40ac8808 */

/* Boundary evidence: original MIPS .pdata 40ac8808..40ac882f. Semantic name remains unreviewed. */

void FUN_40ac8808(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x4c))();
  return;
}



/* 40ac8830 FUN_40ac8830 */

/* Boundary evidence: original MIPS .pdata 40ac8830..40ac88b3. Semantic name remains unreviewed. */

undefined4 *
FUN_40ac8830(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,wchar_t *param_5)

{
  FUN_40acf210(param_1,param_2,param_3,param_3 + 0xd05f4,param_4,param_5);
  *param_1 = &PTR_FUN_40ad2e30;
  param_1[3] = &PTR_FUN_40ad2de8;
  param_1[4] = &PTR_LAB_40ad2dd4;
  param_1[0x26] = &PTR_LAB_40ad2db0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  param_1[0x3b] = 0;
  return param_1;
}



/* 40ac88c0 FUN_40ac88c0 */

/* Boundary evidence: original MIPS .pdata 40ac88c0..40ac88e7. Semantic name remains unreviewed. */

void FUN_40ac88c0(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40ac88e8 FUN_40ac88e8 */

/* Boundary evidence: original MIPS .pdata 40ac88e8..40ac890f. Semantic name remains unreviewed. */

void FUN_40ac88e8(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40ac8910 FUN_40ac8910 */

/* Boundary evidence: original MIPS .pdata 40ac8910..40ac8937. Semantic name remains unreviewed. */

void FUN_40ac8910(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40ac8938 FUN_40ac8938 */

/* Boundary evidence: original MIPS .pdata 40ac8938..40ac895f. Semantic name remains unreviewed. */

void FUN_40ac8938(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x34))();
  return;
}



/* 40ac8960 FUN_40ac8960 */

/* Boundary evidence: original MIPS .pdata 40ac8960..40ac897b. Semantic name remains unreviewed. */

void FUN_40ac8960(int param_1,void *param_2)

{
  FUN_40acc690(param_1,param_2);
  return;
}



/* 40ac897c FUN_40ac897c */

/* Boundary evidence: original MIPS .pdata 40ac897c..40ac89c7. Semantic name remains unreviewed. */

void FUN_40ac897c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40ac7734();
  if (-1 < iVar1) {
    (**(code **)(**(int **)(param_1 + 0x70) + 0x38))(*(int **)(param_1 + 0x70),param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0xec) = 1;
  }
  return;
}



/* 40ac89c8 FUN_40ac89c8 */

/* Boundary evidence: original MIPS .pdata 40ac89c8..40ac8a5b. Semantic name remains unreviewed. */

int FUN_40ac89c8(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_40acd0b4(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_40ac7af0(*(int **)(param_1 + -0x28),param_2,param_3,param_4);
  }
  if (iVar1 == -0x7fffbffb) {
    pcVar2 = *(code **)(*(int *)(param_1 + -0x8c) + 0x38);
    *(undefined4 *)(param_1 + -0x2c) = 1;
    (*pcVar2)();
    FUN_40acc1a0(*(int *)(param_1 + -0x28));
    iVar1 = -0x7ffbfe00;
  }
  return iVar1;
}



/* 40ac8a5c FUN_40ac8a5c */

/* Boundary evidence: original MIPS .pdata 40ac8a5c..40ac8aeb. Semantic name remains unreviewed. */

int FUN_40ac8a5c(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40acd538(param_1);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    iVar1 = FUN_40ac7ce4(*(int **)(param_1 + 100),param_2,param_3,param_4);
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40ac8aec FUN_40ac8aec */

/* Boundary evidence: original MIPS .pdata 40ac8aec..40ac8b1b. Semantic name remains unreviewed. */

void FUN_40ac8aec(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40ac8b1c FUN_40ac8b1c */

/* Boundary evidence: original MIPS .pdata 40ac8b1c..40ac8bab. Semantic name remains unreviewed. */

int FUN_40ac8b1c(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40ac7d74(*(int **)(param_1 + 100),param_2,param_3,param_4);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    iVar1 = FUN_40acd580(param_1);
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40ac8bac FUN_40ac8bac */

/* Boundary evidence: original MIPS .pdata 40ac8bac..40ac8bdb. Semantic name remains unreviewed. */

void FUN_40ac8bac(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40ac8bdc FUN_40ac8bdc */

/* Boundary evidence: original MIPS .pdata 40ac8bdc..40ac8c3f. Semantic name remains unreviewed. */

int FUN_40ac8bdc(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40ac7be0(*(int **)(param_1 + 100),param_2,param_3,param_4);
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40ac8c40 FUN_40ac8c40 */

/* Boundary evidence: original MIPS .pdata 40ac8c40..40ac8c6f. Semantic name remains unreviewed. */

void FUN_40ac8c40(void)

{
  int in_v0;
  
  FUN_40ac7134((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40ac8d24 FUN_40ac8d24 */

/* Boundary evidence: original MIPS .pdata 40ac8d24..40ac8d3f. Semantic name remains unreviewed. */

void FUN_40ac8d24(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40acd8d0(param_1,param_2,param_3);
  return;
}



/* 40ac8d40 FUN_40ac8d40 */

/* Boundary evidence: original MIPS .pdata 40ac8d40..40ac8e13. Semantic name remains unreviewed. */

undefined4 * FUN_40ac8d40(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_40ac77e0(param_1,L"CPCMDecoderFilter",0,&DAT_40ad21cc,param_3,0,0,5);
  *param_1 = &PTR_FUN_40ad2f68;
  param_1[3] = &PTR_FUN_40ad2f2c;
  param_1[4] = &PTR_LAB_40ad2f18;
  param_1[0x34188] = 0x800;
  param_1[0x34189] = 1;
  param_1[0x3418a] = 0x10000;
  param_1[0x3418b] = 5;
  FUN_40ac9f84(param_1 + 0x14);
  return param_1;
}



/* 40ac8e14 FUN_40ac8e14 */

/* Boundary evidence: original MIPS .pdata 40ac8e14..40ac8e3b. Semantic name remains unreviewed. */

void FUN_40ac8e14(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40ac8e3c FUN_40ac8e3c */

/* Boundary evidence: original MIPS .pdata 40ac8e3c..40ac8e63. Semantic name remains unreviewed. */

void FUN_40ac8e3c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40ac8e64 FUN_40ac8e64 */

/* Boundary evidence: original MIPS .pdata 40ac8e64..40ac8e8b. Semantic name remains unreviewed. */

void FUN_40ac8e64(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40ac8ec8 FUN_40ac8ec8 */

/* Boundary evidence: original MIPS .pdata 40ac8ec8..40ac928b. Semantic name remains unreviewed. */

int FUN_40ac8ec8(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int *local_98 [2];
  uint local_90;
  int local_8c;
  uint local_88 [26];
  
  local_88[0] = 0;
  local_88[1] = 0;
  local_98[0] = (int *)0x0;
  bVar1 = false;
  local_90 = 0;
  local_8c = 0;
  if (param_2 == (int *)0x0) {
LAB_40ac9264:
    iVar2 = 0;
  }
  else {
    local_88[2] = 0;
    local_88[3] = 0;
    local_88[4] = 0;
    local_88[5] = 0;
    local_88[6] = 0;
    local_88[7] = 0;
    local_88[8] = 0;
    local_88[9] = 0;
    local_88[10] = 0;
    local_88[0xb] = 0;
    local_88[0xc] = 0;
    local_88[0xd] = 0;
    iVar2 = (**(code **)(*param_2 + 0xc))(param_2,local_88 + 2);
    if (iVar2 < 0) {
      FUN_40ac6e24(0x40ad31ac,iVar2,param_3,param_4);
    }
    else {
      local_88[5] = (**(code **)(*param_2 + 0x10))(param_2);
      local_88[4] = (**(code **)(*param_2 + 0x2c))(param_2);
      puVar4 = local_88;
      iVar2 = (**(code **)(*param_2 + 0x14))(param_2,local_88 + 8);
      if (-1 < iVar2) {
        local_88[6] = local_88[6] | 0x1000;
      }
      iVar2 = (**(code **)(*param_2 + 0x3c))(param_2);
      if (iVar2 == 0) {
        local_88[6] = local_88[6] | 0x200;
      }
      iVar2 = (**(code **)(*param_2 + 0x1c))(param_2);
      if (iVar2 == 0) {
        local_88[6] = local_88[6] | 0x2000;
      }
      iVar2 = FUN_40aca3a0(local_88 + 2,param_1 + 0x50);
      if (iVar2 == 0) {
        while( true ) {
          local_88[0xe] = 0;
          local_88[0xf] = 0;
          local_88[0x10] = 0;
          local_88[0x11] = 0;
          local_88[0x12] = 0;
          local_88[0x13] = 0;
          local_88[0x14] = 0;
          local_88[0x15] = 0;
          local_88[0x16] = 0;
          local_88[0x17] = 0;
          local_88[0x18] = 0;
          local_88[0x19] = 0;
          iVar2 = *(int *)(param_1 + 0xd05e4);
          if (*(int *)(iVar2 + 0x18) != 0) {
            piVar3 = *(int **)(iVar2 + 0x98);
            param_4 = (va_list)0x0;
            puVar4 = (uint *)0x0;
            iVar2 = (**(code **)(*piVar3 + 0x1c))(piVar3,local_98,0,0,0);
            if (iVar2 < 0) goto LAB_40ac9264;
          }
          if (local_98[0] == (int *)0x0) goto LAB_40ac9264;
          iVar2 = (**(code **)(*local_98[0] + 0xc))(local_98[0],local_88 + 0xe);
          if (iVar2 < 0) break;
          local_88[0x11] = (**(code **)(*local_98[0] + 0x10))();
          iVar2 = FUN_40aca634(local_88 + 0xe,(void *)(param_1 + 0x50));
          if (iVar2 == 0x20000) {
            bVar1 = true;
          }
          else if (iVar2 != 0) {
            (**(code **)(*local_98[0] + 8))();
            FUN_40ac6e24(0x40ad3050,iVar2,puVar4,param_4);
            return -0x7fffbffb;
          }
          if (local_88[0x10] == 0) {
LAB_40ac9174:
            iVar2 = (**(code **)(*local_98[0] + 8))();
          }
          else {
            iVar2 = (**(code **)(*local_98[0] + 0x30))();
            if (iVar2 != 0) {
              FUN_40ac6e24(0x40ad30c0,local_88[0x10],puVar4,param_4);
              bVar1 = true;
              goto LAB_40ac9174;
            }
            if ((local_88[0x12] & 0x1000) != 0) {
              local_90 = local_88[0x14] + 1;
              local_8c = local_88[0x15] + (local_90 < local_88[0x14]);
              puVar4 = &local_90;
              (**(code **)(*local_98[0] + 0x18))(local_98[0],local_88 + 0x14);
              if ((local_88[0x12] & 0x2000) != 0) {
                (**(code **)(*local_98[0] + 0x20))(local_98[0],1);
              }
            }
            iVar2 = FUN_40ac827c(*(int **)(param_1 + 0xd05e4),local_98[0],puVar4,param_4);
          }
          if (iVar2 != 0) {
            return iVar2;
          }
          if (bVar1) {
            return 0;
          }
        }
        FUN_40ac6e24(0x40ad2fdc,iVar2,puVar4,param_4);
      }
      else {
        FUN_40ac6e24(0x40ad3140,iVar2,puVar4,param_4);
        iVar2 = -0x7fffbffb;
      }
    }
  }
  return iVar2;
}



/* 40ac928c FUN_40ac928c */

/* Boundary evidence: original MIPS .pdata 40ac928c..40ac92d7. Semantic name remains unreviewed. */

undefined4 * FUN_40ac928c(undefined4 *param_1,uint param_2)

{
  FUN_40ac7944(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40ac92d8 FUN_40ac92d8 */

/* Boundary evidence: original MIPS .pdata 40ac92d8..40ac935b. Semantic name remains unreviewed. */

undefined4 *
FUN_40ac92d8(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,wchar_t *param_5,
            undefined4 param_6,undefined4 param_7)

{
  FUN_40acf1c4(param_1,param_2,param_3,param_3 + 0xd05f4,param_4,param_5);
  *param_1 = &PTR_FUN_40ad3278;
  param_1[3] = &PTR_FUN_40ad3230;
  param_1[4] = &PTR_LAB_40ad321c;
  param_1[0x28] = 0;
  param_1[0x29] = param_6;
  param_1[0x2a] = param_7;
  param_1[0x2b] = 0;
  return param_1;
}



/* 40ac935c FUN_40ac935c */

/* Boundary evidence: original MIPS .pdata 40ac935c..40ac9383. Semantic name remains unreviewed. */

void FUN_40ac935c(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40ac9384 FUN_40ac9384 */

/* Boundary evidence: original MIPS .pdata 40ac9384..40ac93ab. Semantic name remains unreviewed. */

void FUN_40ac9384(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40ac93ac FUN_40ac93ac */

/* Boundary evidence: original MIPS .pdata 40ac93ac..40ac93d3. Semantic name remains unreviewed. */

void FUN_40ac93ac(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40ac9410 FUN_40ac9410 */

/* Boundary evidence: original MIPS .pdata 40ac9410..40ac94bf. Semantic name remains unreviewed. */

void FUN_40ac9410(undefined4 *param_1)

{
  LPCRITICAL_SECTION p_Var1;
  
  *param_1 = &PTR_FUN_40ad3278;
  param_1[3] = &PTR_FUN_40ad3230;
  param_1[4] = &PTR_LAB_40ad321c;
  p_Var1 = (LPCRITICAL_SECTION)param_1[0x2b];
  if (p_Var1 != (LPCRITICAL_SECTION)0x0) {
    FUN_40acfac4(p_Var1);
    operator_delete(p_Var1);
    param_1[0x2b] = 0;
  }
  if ((int *)param_1[0x28] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x28] + 8))();
    param_1[0x28] = 0;
  }
  FUN_40acc54c((int)param_1);
  return;
}



/* 40ac94c0 FUN_40ac94c0 */

/* Boundary evidence: original MIPS .pdata 40ac94c0..40ac94ef. Semantic name remains unreviewed. */

void FUN_40ac94c0(void)

{
  int *in_v0;
  
  FUN_40ac8260(*in_v0);
  return;
}



/* 40ac94f0 FUN_40ac94f0 */

/* Boundary evidence: original MIPS .pdata 40ac94f0..40ac9573. Semantic name remains unreviewed. */

undefined4 * FUN_40ac94f0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40ad2e30;
  param_1[3] = &PTR_FUN_40ad2de8;
  param_1[4] = &PTR_LAB_40ad2dd4;
  param_1[0x26] = &PTR_LAB_40ad2db0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  FUN_40acce84((int)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40ac9574 FUN_40ac9574 */

/* Boundary evidence: original MIPS .pdata 40ac9574..40ac95eb. Semantic name remains unreviewed. */

undefined4 * FUN_40ac9574(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xd0630);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40ac8d40(puVar1,param_1,param_2);
  }
  *param_2 = 0;
  return puVar1;
}



/* 40ac95ec FUN_40ac95ec */

/* Boundary evidence: original MIPS .pdata 40ac95ec..40ac961b. Semantic name remains unreviewed. */

void FUN_40ac95ec(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40ac961c FUN_40ac961c */

/* Boundary evidence: original MIPS .pdata 40ac961c..40ac9693. Semantic name remains unreviewed. */

undefined4 * FUN_40ac961c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40ad2f68;
  param_1[3] = &PTR_FUN_40ad2f2c;
  param_1[4] = &PTR_LAB_40ad2f18;
  FUN_40aca05c(param_1 + 0x14);
  FUN_40ac7944(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40ac9694 FUN_40ac9694 */

/* Boundary evidence: original MIPS .pdata 40ac9694..40ac982f. Semantic name remains unreviewed. */

int FUN_40ac9694(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_28;
  undefined4 *local_24;
  
  piVar4 = (int *)(param_1 + 0xd05e0);
  local_28 = 0;
  if (*piVar4 == 0) {
    local_24 = operator_new(0xf0);
    if (local_24 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40ac8830(local_24,0,param_1,&local_28,L"Input");
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
      puVar1 = FUN_40ac92d8(local_24,0,param_1,&local_28,L"Output",
                            *(undefined4 *)(param_1 + 0xd05ec),*(undefined4 *)(param_1 + 0xd05f0));
    }
    *(undefined4 **)(param_1 + 0xd05e4) = puVar1;
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
    iVar2 = *(int *)(param_1 + 0xd05e4);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 40ac9830 FUN_40ac9830 */

/* Boundary evidence: original MIPS .pdata 40ac9830..40ac985f. Semantic name remains unreviewed. */

void FUN_40ac9830(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x24));
  return;
}



/* 40ac9860 FUN_40ac9860 */

/* Boundary evidence: original MIPS .pdata 40ac9860..40ac988f. Semantic name remains unreviewed. */

void FUN_40ac9860(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x24));
  return;
}



/* 40ac9890 FUN_40ac9890 */

/* Boundary evidence: original MIPS .pdata 40ac9890..40ac98db. Semantic name remains unreviewed. */

undefined4 * FUN_40ac9890(undefined4 *param_1,uint param_2)

{
  FUN_40ac9410(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40ac98dc FUN_40ac98dc */

/* Boundary evidence: original MIPS .pdata 40ac98dc..40ac992b. Semantic name remains unreviewed. */

void FUN_40ac98dc(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  wchar_t awStack_3f8 [500];
  uint local_10;
  
  local_10 = DAT_40ad707c;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(awStack_3f8,param_1,(wchar_t *)&local_res4,param_4);
  OutputDebugStringW(awStack_3f8);
  FUN_40ad0c64(local_10);
  return;
}



/* 40ac992c FUN_40ac992c */

/* Boundary evidence: original MIPS .pdata 40ac992c..40ac99d7. Semantic name remains unreviewed. */

undefined2 * FUN_40ac992c(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  short *psVar4;
  
  psVar4 = &DAT_40ad7184;
  memset(&DAT_40ad7184,0,0x1ff);
  pcVar2 = (char *)0x0;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((int)pcVar3 - (int)param_1 != 1) {
    do {
      *psVar4 = (short)param_1[(int)pcVar2];
      pcVar2 = pcVar2 + 1;
      psVar4 = psVar4 + 1;
      pcVar3 = param_1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    } while (pcVar2 < pcVar3 + (-1 - (int)param_1));
  }
  return &DAT_40ad7184;
}



/* 40ac99d8 FUN_40ac99d8 */

/* Boundary evidence: original MIPS .pdata 40ac99d8..40ac9afb. Semantic name remains unreviewed. */

void FUN_40ac99d8(void *param_1)

{
  *(undefined4 *)((int)param_1 + 0x804e0) = 0;
  *(undefined4 *)((int)param_1 + 0x80180) = 0;
  *(undefined4 *)((int)param_1 + 0x804dc) = 0;
  *(undefined4 *)((int)param_1 + 0x804d8) = 0;
  *(undefined4 *)((int)param_1 + 0x804d4) = 1;
  *(undefined4 *)((int)param_1 + 0x80564) = 0;
  FUN_40ac4a40((undefined4 *)((int)param_1 + 0x804e4),*(int *)((int)param_1 + 0x80568),param_1);
  *(undefined4 *)((int)param_1 + 0x804b0) = 0;
  if (*(short *)((int)param_1 + 0x802b8) == 4) {
    FUN_40ac6ef0((int *)((int)param_1 + 0x80174),(int *)((int)param_1 + 0x802ba),4);
    return;
  }
  *(undefined4 *)((int)param_1 + 0x80174) = 0;
  return;
}



/* 40ac9afc FUN_40ac9afc */

/* Boundary evidence: original MIPS .pdata 40ac9afc..40ac9f83. Semantic name remains unreviewed. */

void FUN_40ac9afc(uint *param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5,
                 void *param_6)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  int *piVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint local_2c;
  
  puVar11 = (uint *)0x0;
  if (*(int *)((int)param_6 + 0x804ac) == 0) {
    *(uint **)((int)param_6 + 0x804fc) = param_4;
    puVar4 = param_4;
    if (*(int *)((int)param_6 + 0x804b0) != 0) {
      FUN_40ac99d8(param_6);
      puVar4 = param_2;
      FUN_40ac6990((char *)param_1,(int *)((int)param_6 + 0x804e4),
                   (undefined4 *)((int)param_6 + 0x80180),(int)param_2,
                   (ushort *)((int)param_6 + 0x802a8),(int)param_6);
      *(int *)((int)param_6 + 0x804d8) = *(int *)((int)param_6 + 0x804e4);
      *(undefined4 *)((int)param_6 + 0x804dc) = *(undefined4 *)((int)param_6 + 0x804e8);
      *(undefined4 *)((int)param_6 + 0x804d4) = 1;
    }
    piVar5 = (int *)((int)param_6 + 0x80180);
    if (*piVar5 == 1) {
      FUN_40ac2ea0((ushort *)param_3,param_5,param_4,(va_list)param_2,(byte *)param_1);
    }
    else {
      puVar9 = (uint *)((int)param_6 + 0x804e0);
      uVar2 = *puVar9;
      puVar7 = param_2;
      puVar10 = param_1;
      if (uVar2 != 0) {
        if (uVar2 + (int)param_2 < 0x30001) {
          puVar10 = (uint *)((int)param_6 + 0x8058c);
          FUN_40ac6ef0((int *)puVar10,(int *)((int)param_6 + 0xb058c),uVar2);
          puVar7 = (uint *)*puVar9;
          if (*piVar5 == 1) {
            FUN_40ac6ef0((int *)((int)puVar7 + (int)param_6 + 0x8058c),(int *)((int)param_1 + 7),
                         (int)param_2 - 7);
            puVar7 = (uint *)((int)param_2 + (*puVar9 - 7));
          }
          else if (param_2 != (uint *)0x0) {
            FUN_40ac6ef0((int *)((int)puVar7 + (int)param_6 + 0x8058c),(int *)param_1,(uint)param_2)
            ;
            puVar7 = (uint *)((int)param_2 + *puVar9);
          }
        }
        else {
          FUN_40ac98dc(0x40ad356c,uVar2 + (int)param_2,0x30000,(va_list)puVar4);
        }
        *puVar9 = 0;
      }
      piVar8 = (int *)((int)param_6 + 0x804b8);
      if (*piVar8 <= (int)puVar7) {
        do {
          if (param_4 + -0x800 <= puVar11) break;
          puVar6 = (uint *)((int)param_6 + 0x804e4);
          puVar3 = &local_2c;
          puVar4 = puVar10;
          if (*piVar5 == 1) {
            puVar1 = (uint *)FUN_40ac1784(puVar6,(short *)param_3,(int *)puVar3,(byte *)puVar10,
                                          (int)puVar7,*(int *)((int)param_6 + 0x804f0) >> 3,1);
          }
          else {
            puVar1 = (uint *)FUN_40ac5bdc(puVar6,param_3,(int *)puVar3,puVar10,(char *)puVar7,
                                          (int)param_6);
          }
          if ((int)puVar1 < 0) {
            FUN_40ac98dc(0x40ad342c,puVar1,puVar3,(va_list)puVar4);
            return;
          }
          if (0 < (int)local_2c) {
            if (*(uint *)((int)param_6 + 0x804d8) != *puVar6) {
              *(uint *)((int)param_6 + 0x804d8) = *puVar6;
              *(undefined4 *)((int)param_6 + 0x804d4) = 1;
            }
            if (*(int *)((int)param_6 + 0x804dc) != *(int *)((int)param_6 + 0x804e8)) {
              *(int *)((int)param_6 + 0x804dc) = *(int *)((int)param_6 + 0x804e8);
              *(undefined4 *)((int)param_6 + 0x804d4) = 1;
            }
            param_3 = (uint *)(local_2c + (int)param_3);
            puVar11 = (uint *)(local_2c + (int)puVar11);
          }
          if ((int)puVar7 < (int)puVar1) {
            puVar3 = puVar7;
            FUN_40ac98dc(0x40ad34e8,puVar1,puVar7,(va_list)puVar4);
            puVar1 = puVar7;
          }
          puVar7 = (uint *)((int)puVar7 - (int)puVar1);
          puVar10 = (uint *)((int)puVar1 + (int)puVar10);
          if ((int)puVar7 < 0) {
            FUN_40ac98dc(0x40ad3498,puVar7,puVar3,(va_list)puVar4);
          }
          if (*(int *)((int)param_6 + 0x804a8) != 0) {
            *piVar8 = *piVar8 >> 1;
          }
          *(int *)((int)param_6 + 0x80588) = *(int *)((int)param_6 + 0x80588) + 1;
        } while (*piVar8 <= (int)puVar7);
      }
      if ((int)puVar7 < 1) {
        puVar7 = (uint *)0x0;
      }
      *puVar9 = (uint)puVar7;
      if (puVar7 != (uint *)0x0) {
        if (puVar7 < (uint *)0x20001) {
          FUN_40ac6ef0((int *)((int)param_6 + 0xb058c),(int *)puVar10,(uint)puVar7);
        }
        else {
          FUN_40ac98dc(0x40ad33e8,puVar7,0x20000,(va_list)puVar4);
        }
      }
      *param_5 = (uint)puVar11;
    }
  }
  else {
    *param_5 = 0;
  }
  return;
}



/* 40ac9f84 FUN_40ac9f84 */

/* Boundary evidence: original MIPS .pdata 40ac9f84..40aca05b. Semantic name remains unreviewed. */

undefined4 FUN_40ac9f84(void *param_1)

{
  memset(param_1,0,0xd0590);
  FUN_40ac47e4(*(int *)((int)param_1 + 0x80568),param_1);
  *(undefined4 *)((int)param_1 + 0x804b0) = 1;
  *(undefined4 *)((int)param_1 + 0x804d4) = 1;
  *(undefined4 *)((int)param_1 + 0x804d8) = 0;
  *(undefined4 *)((int)param_1 + 0x804b4) = 0;
  *(undefined4 *)((int)param_1 + 0x804dc) = 0;
  *(undefined4 *)((int)param_1 + 0x804ac) = 0;
  *(undefined4 *)((int)param_1 + 0x804c8) = 0;
  *(undefined4 *)((int)param_1 + 0x804cc) = 0;
  *(undefined4 *)((int)param_1 + 0x804a8) = 0;
  return 0;
}



/* 40aca05c FUN_40aca05c */

/* Boundary evidence: original MIPS .pdata 40aca05c..40aca0bb. Semantic name remains unreviewed. */

undefined4 FUN_40aca05c(void *param_1)

{
  *(undefined4 *)((int)param_1 + 0x804b4) = 0;
  *(undefined4 *)((int)param_1 + 0x804b0) = 1;
  *(undefined4 *)((int)param_1 + 0x804d8) = 0;
  *(undefined4 *)((int)param_1 + 0x804dc) = 0;
  FUN_40ac4af4(param_1);
  return 0;
}



/* 40aca0bc FUN_40aca0bc */

/* Boundary evidence: original MIPS .pdata 40aca0bc..40aca277. Semantic name remains unreviewed. */

undefined4 FUN_40aca0bc(int *param_1,uint param_2,int param_3,va_list param_4)

{
  short sVar1;
  int iVar2;
  uint *puVar3;
  
  if (((*(int *)(param_3 + 0x804b4) == 0) || (*(size_t *)(param_3 + 0x802a4) != param_2)) ||
     (iVar2 = memcmp((void *)(param_3 + 0x802a8),param_1,*(size_t *)(param_3 + 0x802a4)), iVar2 != 0
     )) {
    puVar3 = (uint *)(param_3 + 0x802a4);
    *puVar3 = param_2;
    if (0x200 < param_2) {
      FUN_40ac98dc(0x40ad36a8,param_2,0x200,param_4);
      *puVar3 = 0x200;
    }
    FUN_40ac6ef0((int *)(param_3 + 0x802a8),param_1,*puVar3);
    *(int *)(param_3 + 0x804b4) = 1;
    *(undefined4 *)(param_3 + 0x804b0) = 1;
    sVar1 = *(short *)(param_3 + 0x802a8);
    if ((sVar1 == 0x11) && (*(ushort *)(param_3 + 0x802b6) != 4)) {
      FUN_40ac98dc(0x40ad35e8,(uint)*(ushort *)(param_3 + 0x802b6),
                   (uint)*(ushort *)(param_3 + 0x802b4),(va_list)0x11);
      return 0x80004005;
    }
    if ((*(uint *)(param_3 + 0x802ac) < 0x5dc1) && (sVar1 == 1)) {
      *(undefined4 *)(param_3 + 0x80568) = 1;
    }
    else {
      *(undefined4 *)(param_3 + 0x80568) = 0;
    }
  }
  return 0;
}



/* 40aca278 FUN_40aca278 */

/* WARNING: Removing unreachable block (ram,0x40aca340) */
/* Boundary evidence: original MIPS .pdata 40aca278..40aca39f. Semantic name remains unreviewed. */

undefined4 FUN_40aca278(undefined1 *param_1,undefined4 param_2,int param_3,va_list param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  
  if (*(int *)(param_3 + 0x804b4) == 0) {
    FUN_40ac98dc(0x40ad3708,param_2,param_3,param_4);
    return 0x80004005;
  }
  param_1[1] = 0;
  param_1[0x11] = 0;
  *param_1 = 1;
  param_1[0x10] = 0;
  uVar1 = *(undefined1 *)(param_3 + 0x802ab);
  uVar2 = *(ushort *)(param_3 + 0x802aa);
  param_1[2] = *(undefined1 *)(param_3 + 0x802aa);
  param_1[3] = uVar1;
  if (2 < uVar2) {
    param_1[2] = 2;
    param_1[3] = 0;
  }
  *(int *)(param_1 + 4) = *(int *)(param_3 + 0x802ac);
  param_1[0xe] = 0x10;
  param_1[0xf] = 0;
  uVar3 = (int)((uint)CONCAT11(param_1[3],param_1[2]) * 0x10) >> 3 & 0xffff;
  param_1[0xc] = (char)uVar3;
  param_1[0xd] = (char)(uVar3 >> 8);
  *(uint *)(param_1 + 8) = uVar3 * *(int *)(param_1 + 4);
  return 0;
}



/* 40aca3a0 FUN_40aca3a0 */

/* Boundary evidence: original MIPS .pdata 40aca3a0..40aca633. Semantic name remains unreviewed. */

undefined4 FUN_40aca3a0(undefined4 *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)(param_2 + 0x80574);
  *(undefined4 *)(param_2 + 0x804a8) = 0;
  puVar5 = (undefined4 *)(param_2 + 0x80580);
  *(undefined4 *)(param_2 + 0x804c8) = 0;
  *(undefined4 *)(param_2 + 0x804cc) = 0;
  *(undefined4 *)(param_2 + 0x804c0) = 0;
  *puVar7 = 0;
  *(undefined4 *)(param_2 + 0x80578) = 0;
  *puVar5 = 0;
  *(undefined4 *)(param_2 + 0x80584) = 0;
  if (*(int *)(param_2 + 0x804ac) == 0) {
    if (*(uint *)(param_2 + 0x804bc) < (uint)param_1[2]) {
      *(uint *)(param_2 + 0x804bc) = param_1[2];
    }
    piVar6 = (int *)(param_2 + 0x80564);
    if (*piVar6 < 1) {
      if ((0x14 < (uint)param_1[2]) &&
         ((((sVar1 = *(short *)(param_2 + 0x802a8), sVar1 == 7 || (sVar1 == 6)) || (sVar1 == 1)) ||
          (sVar1 == 2)))) {
        pbVar3 = (byte *)*param_1;
        uVar4 = 0;
        if (param_1[2] != 6) {
          do {
            iVar2 = FUN_40ac1a00(pbVar3);
            if (iVar2 != 0) {
              param_1[2] = uVar4 - 1;
              *piVar6 = 10;
              uVar4 = param_1[2];
LAB_40aca5b0:
              param_1[2] = uVar4 & 0xfffffff0;
              break;
            }
            iVar2 = FUN_40ac1ab0(pbVar3);
            if (iVar2 != 0) {
              uVar4 = uVar4 - 1;
              goto LAB_40aca5b0;
            }
            uVar4 = uVar4 + 1;
            pbVar3 = pbVar3 + 1;
          } while (uVar4 < param_1[2] - 6);
        }
      }
      *(undefined4 *)(param_2 + 0x80578) = param_1[4];
      if ((param_1[4] & 0x1000) == 0) {
        *puVar5 = 0;
        *(undefined4 *)(param_2 + 0x80584) = 0;
      }
      else {
        *puVar5 = param_1[6];
        *(undefined4 *)(param_2 + 0x80584) = param_1[7];
      }
      *(undefined4 *)(param_2 + 0x80570) = *param_1;
      *puVar7 = param_1[2];
    }
    else {
      *piVar6 = *piVar6 + -1;
      *(undefined4 *)(param_2 + 0x80570) = *param_1;
      *puVar7 = 0;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x804e0) = 0;
  }
  return 0;
}



/* 40aca634 FUN_40aca634 */

/* Boundary evidence: original MIPS .pdata 40aca634..40acac3f. Semantic name remains unreviewed. */

undefined4 FUN_40aca634(undefined4 *param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  
  piVar6 = (int *)((int)param_2 + 0x804a8);
  iVar1 = *piVar6;
  iVar2 = 0;
  if (*(int *)((int)param_2 + 0x804ac) == 0) {
    *piVar6 = 0;
    if ((*(int *)((int)param_2 + 0x80568) == 0) && (iVar1 == 0)) {
      *(undefined4 *)((int)param_2 + 0x804b8) = 0x800;
    }
    else {
      *(undefined4 *)((int)param_2 + 0x804b8) = 0x100;
    }
    puVar4 = param_1 + 2;
    piVar5 = (int *)((int)param_2 + 0x80574);
    *puVar4 = 0;
    if (((*piVar5 != 0) || (0x800 < *(uint *)((int)param_2 + 0x804e0))) || (iVar1 != 0)) {
      param_1[6] = 0;
      param_1[7] = 0;
      if ((*(uint *)((int)param_2 + 0x804e0) < 0x801) &&
         ((*(uint *)((int)param_2 + 0x804e0) == 0 || (iVar1 == 0)))) {
        if ((uint *)*piVar5 != (uint *)0x0) {
          FUN_40ac9afc(*(uint **)((int)param_2 + 0x80570),(uint *)*piVar5,(uint *)*param_1,
                       (uint *)param_1[3],puVar4,param_2);
          uVar3 = *(uint *)((int)param_2 + 0x80578);
          *piVar5 = 0;
          if ((uVar3 & 0x1000) != 0) {
            *(undefined4 *)((int)param_2 + 0x804c8) = *(undefined4 *)((int)param_2 + 0x80580);
            *(undefined4 *)((int)param_2 + 0x804cc) = *(undefined4 *)((int)param_2 + 0x80584);
            *(uint *)((int)param_2 + 0x804c0) = *(uint *)((int)param_2 + 0x804c0) | 0x1000;
          }
          if ((uVar3 & 0x200) != 0) {
            *(uint *)((int)param_2 + 0x804c0) = *(uint *)((int)param_2 + 0x804c0) | 0x200;
          }
          if ((uVar3 & 0x2000) != 0) {
            *(uint *)((int)param_2 + 0x804c0) = *(uint *)((int)param_2 + 0x804c0) | 0x2000;
          }
          iVar2 = 2;
        }
      }
      else {
        FUN_40ac9afc((uint *)0x0,(uint *)0x0,(uint *)*param_1,(uint *)param_1[3],puVar4,param_2);
        iVar2 = 1;
        *piVar5 = 0;
      }
    }
    if (*(int *)((int)param_2 + 0x804ac) == 0) {
      if ((iVar2 != 0) && (*puVar4 != 0)) {
        *(undefined4 *)((int)param_2 + 0x80578) = 0;
        *(undefined4 *)((int)param_2 + 0x80580) = 0;
        *(undefined4 *)((int)param_2 + 0x80584) = 0;
        FUN_40ac4868((int *)*param_1,puVar4,(int)param_2);
        puVar4 = (uint *)((int)param_2 + 0x804c0);
        if ((*puVar4 & 0x1000) != 0) {
          param_1[4] = param_1[4] | 0x1000;
          param_1[6] = *(undefined4 *)((int)param_2 + 0x804c8);
          param_1[7] = *(undefined4 *)((int)param_2 + 0x804cc);
        }
        if ((*puVar4 & 0x200) != 0) {
          param_1[4] = param_1[4] | 0x200;
        }
        if ((*puVar4 & 0x2000) != 0) {
          param_1[4] = param_1[4] | 0x2000;
        }
        if (*(int *)((int)param_2 + 0x804d4) != 0) {
          *(undefined4 *)((int)param_2 + 0x80504) = 7;
          *(int *)((int)param_2 + 0x80500) = 0xf;
          *(undefined4 *)((int)param_2 + 0x80508) = 0xfffa;
          *(undefined4 *)((int)param_2 + 0x80510) = 0xfff4;
          *(undefined4 *)((int)param_2 + 0x8050c) = 3;
          *(undefined4 *)((int)param_2 + 0x80514) = 0xfff3;
          *(undefined4 *)((int)param_2 + 0x8051c) = 8;
          *(undefined4 *)((int)param_2 + 0x80518) = 0xffff;
          *(undefined4 *)((int)param_2 + 0x80524) = 8;
          uVar3 = *(uint *)((int)param_2 + 0x804d8);
          *(undefined4 *)((int)param_2 + 0x80520) = *(undefined4 *)((int)param_2 + 0x804dc);
          *(uint *)((int)param_2 + 0x80528) = uVar3 & 0xf;
          *(uint *)((int)param_2 + 0x8052c) = uVar3 >> 4 & 0xf;
          *(uint *)((int)param_2 + 0x80530) = uVar3 >> 8 & 0xf;
          *(uint *)((int)param_2 + 0x80534) = uVar3 >> 0xc & 0xf;
          uVar7 = *(uint *)((int)param_2 + 0x804fc);
          *(uint *)((int)param_2 + 0x80538) = uVar3 >> 0x10 & 0xf;
          *(uint *)((int)param_2 + 0x8053c) = uVar3 >> 0x14 & 0xf;
          *(uint *)((int)param_2 + 0x80540) = uVar7 & 0xf;
          *(uint *)((int)param_2 + 0x80544) = uVar7 >> 4 & 0xf;
          *(uint *)((int)param_2 + 0x80548) = uVar7 >> 8 & 0xf;
          *(uint *)((int)param_2 + 0x8054c) = uVar7 >> 0xc & 0xf;
          *(uint *)((int)param_2 + 0x80550) = uVar7 >> 0x10 & 0xf;
          *(uint *)((int)param_2 + 0x80554) = uVar7 >> 0x14 & 0xf;
          *(int *)((int)param_2 + 0x804d4) = 0;
          FUN_40ac6ef0((int *)*param_1,(int *)((int)param_2 + 0x80500),0x60);
        }
        *(undefined4 *)((int)param_2 + 0x804c8) = 0;
        *(undefined4 *)((int)param_2 + 0x804cc) = 0;
        *puVar4 = 0;
        if ((*(uint *)((int)param_2 + 0x804e0) < 0x801) && (*piVar6 == 0)) {
          return 0x20000;
        }
        return 0;
      }
    }
    else {
      *piVar5 = 0;
      *(undefined4 *)((int)param_2 + 0x80578) = 0;
      *(undefined4 *)((int)param_2 + 0x80580) = 0;
      *(undefined4 *)((int)param_2 + 0x80584) = 0;
      *(undefined4 *)((int)param_2 + 0x804c0) = 0;
      *(undefined4 *)((int)param_2 + 0x804c8) = 0;
      *(undefined4 *)((int)param_2 + 0x804cc) = 0;
      *(uint *)((int)param_2 + 0x804e0) = 0;
    }
    *puVar4 = 0;
  }
  else {
    *(undefined4 *)((int)param_2 + 0x80574) = 0;
    *(undefined4 *)((int)param_2 + 0x80578) = 0;
    *(undefined4 *)((int)param_2 + 0x80580) = 0;
    *(undefined4 *)((int)param_2 + 0x80584) = 0;
    *(undefined4 *)((int)param_2 + 0x804c8) = 0;
    *(undefined4 *)((int)param_2 + 0x804cc) = 0;
    *(undefined4 *)((int)param_2 + 0x804c0) = 0;
    *(undefined4 *)((int)param_2 + 0x804e0) = 0;
    param_1[2] = 0;
  }
  return 0x20000;
}



/* 40acac40 FUN_40acac40 */

undefined4 FUN_40acac40(int param_1)

{
  *(undefined4 *)(param_1 + 0x804ac) = 1;
  return 0;
}



/* 40acac5c FUN_40acac5c */

/* Boundary evidence: original MIPS .pdata 40acac5c..40acad27. Semantic name remains unreviewed. */

undefined4 FUN_40acac5c(int param_1)

{
  *(undefined4 *)(param_1 + 0x804e0) = 0;
  FUN_40ac10e0(*(uint *)(param_1 + 0x804d8),*(int *)(param_1 + 0x804dc),1,2,0,param_1);
  *(undefined4 *)(param_1 + 0x804d4) = 0;
  *(undefined4 *)(param_1 + 0x804c0) = 0;
  *(undefined4 *)(param_1 + 0x804c8) = 0;
  *(undefined4 *)(param_1 + 0x804cc) = 0;
  *(undefined4 *)(param_1 + 0x804a8) = 0;
  *(undefined4 *)(param_1 + 0x804ac) = 0;
  *(undefined4 *)(param_1 + 0x80564) = 0;
  return 0;
}



/* 40acad28 FUN_40acad28 */

undefined4 FUN_40acad28(int param_1)

{
  *(undefined4 *)(param_1 + 0x804a8) = 1;
  return 0;
}



/* 40acad44 FUN_40acad44 */

/* Boundary evidence: original MIPS .pdata 40acad44..40acae8f. Semantic name remains unreviewed. */

undefined4 FUN_40acad44(HKEY param_1,wchar_t *param_2)

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
  
  local_20 = DAT_40ad707c;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40ad0c64(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40acad44(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40ad0c64(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40acae90 FUN_40acae90 */

/* Boundary evidence: original MIPS .pdata 40acae90..40acb11f. Semantic name remains unreviewed. */

uint FUN_40acae90(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  
  local_30 = DAT_40ad707c;
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
  FUN_40ad0c64(local_30);
  return uVar1;
}



/* 40acb120 FUN_40acb120 */

/* Boundary evidence: original MIPS .pdata 40acb120..40acb193. Semantic name remains unreviewed. */

undefined4 FUN_40acb120(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40ad707c;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40acad44((HKEY)0x80000000,aWStack_218);
  FUN_40ad0c64(local_10);
  return 0;
}



/* 40acb194 FUN_40acb194 */

/* Boundary evidence: original MIPS .pdata 40acb194..40acb3cb. Semantic name remains unreviewed. */

DWORD FUN_40acb194(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40ad707c;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40ad76a0,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40ad7068) {
      ppuVar5 = &PTR_u_Alchemy_PCM_Decoder_Filter_40ad7054;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40acae90(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40ad4e08,local_240
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
      } while (iVar4 < DAT_40ad7068);
    }
  }
  FUN_40ad0c64(local_30);
  return DVar3;
}



/* 40acb3cc FUN_40acb3cc */

/* Boundary evidence: original MIPS .pdata 40acb3cc..40acb553. Semantic name remains unreviewed. */

int FUN_40acb3cc(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40ad7068 != 0) {
    iVar3 = DAT_40ad7068;
    ppuVar4 = &PTR_DAT_40ad7058 + DAT_40ad7068 * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ad4e08,local_30);
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
      HVar2 = FUN_40acb120(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
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



/* 40acb554 FUN_40acb554 */

/* Boundary evidence: original MIPS .pdata 40acb554..40acb587. Semantic name remains unreviewed. */

void FUN_40acb554(int param_1)

{
  if (param_1 == 0) {
    FUN_40acb3cc();
  }
  else {
    FUN_40acb194();
  }
  return;
}



/* 40acb5cc FUN_40acb5cc */

/* Boundary evidence: original MIPS .pdata 40acb5cc..40acb64b. Semantic name remains unreviewed. */

void FUN_40acb5cc(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40ad7068) {
    ppuVar2 = &PTR_DAT_40ad7058;
    iVar1 = DAT_40ad7068;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40ad7068;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40acb64c FUN_40acb64c */

/* Boundary evidence: original MIPS .pdata 40acb64c..40acb6eb. Semantic name remains unreviewed. */

undefined4 FUN_40acb64c(HMODULE param_1,int param_2)

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
    DAT_40ad769c = 1;
    DAT_40ad7588 = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40ad7588);
    if (BVar1 != 0) {
      DAT_40ad769c = DAT_40ad7598;
    }
    uVar2 = 1;
    DAT_40ad76a0 = param_1;
  }
  FUN_40acb5cc(uVar2);
  return 1;
}



/* 40acb6ec FUN_40acb6ec */

undefined4 FUN_40acb6ec(int param_1,int *param_2)

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



/* 40acb73c FUN_40acb73c */

/* Boundary evidence: original MIPS .pdata 40acb73c..40acb7e7. Semantic name remains unreviewed. */

undefined4 FUN_40acb73c(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40ad55c4,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40ad55b4,0x10), iVar2 == 0)) {
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



/* 40acb7e8 FUN_40acb7e8 */

/* Boundary evidence: original MIPS .pdata 40acb7e8..40acb83f. Semantic name remains unreviewed. */

void * FUN_40acb7e8(void *param_1,uint param_2)

{
  FUN_40acf3a0();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40acb840 FUN_40acb840 */

/* Boundary evidence: original MIPS .pdata 40acb840..40acb963. Semantic name remains unreviewed. */

int FUN_40acb840(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40ad55c4,0x10), iVar1 == 0)) {
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



/* 40acb964 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0xb964  1  DllCanUnloadNow */
  if ((0 < DAT_40ad76a4) || (HVar1 = 0, DAT_40ad76ac != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40acb990 FUN_40acb990 */

/* Boundary evidence: original MIPS .pdata 40acb990..40acb9eb. Semantic name remains unreviewed. */

undefined4 * FUN_40acb990(undefined4 *param_1,undefined4 param_2)

{
  FUN_40acf370(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40ad52f4;
  param_1[2] = 0;
  return param_1;
}



/* 40acb9ec FUN_40acb9ec */

/* Boundary evidence: original MIPS .pdata 40acb9ec..40acba1b. Semantic name remains unreviewed. */

int FUN_40acb9ec(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40acb7e8(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40acba1c DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40acba1c..40acbb43. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0xba1c  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40ad55c4,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40ad55b4,0x10), iVar1 == 0)) {
    iVar1 = DAT_40ad7068;
    iVar7 = 0;
    if (0 < DAT_40ad7068) {
      ppuVar6 = &PTR_u_Alchemy_PCM_Decoder_Filter_40ad7054;
      do {
        iVar3 = FUN_40acb6ec((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40acb990(puVar4,ppuVar6);
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



/* 40acbb44 FUN_40acbb44 */

/* Boundary evidence: original MIPS .pdata 40acbb44..40acbbdf. Semantic name remains unreviewed. */

LPVOID FUN_40acbb44(int param_1,uint param_2)

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



/* 40acbbe0 FUN_40acbbe0 */

/* Boundary evidence: original MIPS .pdata 40acbbe0..40acbc1b. Semantic name remains unreviewed. */

void FUN_40acbbe0(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40acbc1c FUN_40acbc1c */

/* Boundary evidence: original MIPS .pdata 40acbc1c..40acbcaf. Semantic name remains unreviewed. */

void FUN_40acbc1c(void *param_1,void *param_2)

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



/* 40acbcb0 FUN_40acbcb0 */

/* Boundary evidence: original MIPS .pdata 40acbcb0..40acbd13. Semantic name remains unreviewed. */

void FUN_40acbcb0(int param_1)

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



/* 40acbd14 FUN_40acbd14 */

/* Boundary evidence: original MIPS .pdata 40acbd14..40acbd2f. Semantic name remains unreviewed. */

void FUN_40acbd14(int param_1)

{
  FUN_40acbcb0(param_1);
  return;
}



/* 40acbd30 FUN_40acbd30 */

/* Boundary evidence: original MIPS .pdata 40acbd30..40acbd6f. Semantic name remains unreviewed. */

void * FUN_40acbd30(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40acbd70 FUN_40acbd70 */

/* Boundary evidence: original MIPS .pdata 40acbd70..40acbdbb. Semantic name remains unreviewed. */

void * FUN_40acbd70(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40acbcb0((int)param_1);
    FUN_40acbc1c(param_1,param_2);
  }
  return param_1;
}



/* 40acbdbc FUN_40acbdbc */

/* Boundary evidence: original MIPS .pdata 40acbdbc..40acbde7. Semantic name remains unreviewed. */

void * FUN_40acbdbc(void *param_1,void *param_2)

{
  FUN_40acbd70(param_1,param_2);
  return param_1;
}



/* 40acbde8 FUN_40acbde8 */

/* Boundary evidence: original MIPS .pdata 40acbde8..40acbe53. Semantic name remains unreviewed. */

undefined4 FUN_40acbde8(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40ad55a4,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40ad55a4,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40acbe54 FUN_40acbe54 */

/* Boundary evidence: original MIPS .pdata 40acbe54..40acbf67. Semantic name remains unreviewed. */

undefined4 FUN_40acbe54(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40ad55a4,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40ad55a4,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40ad55a4,0x10);
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



/* 40acbf68 FUN_40acbf68 */

/* Boundary evidence: original MIPS .pdata 40acbf68..40acbfa7. Semantic name remains unreviewed. */

void FUN_40acbf68(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40acbcb0((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40acbfa8 FUN_40acbfa8 */

/* Boundary evidence: original MIPS .pdata 40acbfa8..40acc0ab. Semantic name remains unreviewed. */

HRESULT FUN_40acbfa8(LPUNKNOWN param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  HRESULT HVar1;
  int *local_20;
  int *local_1c;
  
  *param_4 = 0;
  HVar1 = CoCreateInstance((IID *)&DAT_40ad4208,param_1,1,(IID *)&DAT_40ad55c4,&local_20);
  if (-1 < HVar1) {
    HVar1 = (**(code **)*local_20)(local_20,&UNK_40ad4fa8,&local_1c);
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



/* 40acc114 FUN_40acc114 */

/* Boundary evidence: original MIPS .pdata 40acc114..40acc19f. Semantic name remains unreviewed. */

undefined4 FUN_40acc114(int param_1,short *param_2)

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
      FUN_40ad06c0(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40acc1a0 FUN_40acc1a0 */

/* Boundary evidence: original MIPS .pdata 40acc1a0..40acc1df. Semantic name remains unreviewed. */

undefined4 FUN_40acc1a0(int param_1)

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



/* 40acc1e8 FUN_40acc1e8 */

/* Boundary evidence: original MIPS .pdata 40acc1e8..40acc233. Semantic name remains unreviewed. */

void FUN_40acc1e8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40ad5308;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40ad0a1c(param_1 + 6);
  return;
}



/* 40acc234 FUN_40acc234 */

/* Boundary evidence: original MIPS .pdata 40acc234..40acc2cb. Semantic name remains unreviewed. */

undefined4 FUN_40acc234(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40ad4d38,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40ad55c4,0x10), iVar2 == 0)) {
      uVar1 = FUN_40acf3f8(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40acc2cc FUN_40acc2cc */

/* Boundary evidence: original MIPS .pdata 40acc2cc..40acc2e7. Semantic name remains unreviewed. */

void FUN_40acc2cc(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40acc2e8 FUN_40acc2e8 */

/* Boundary evidence: original MIPS .pdata 40acc2e8..40acc343. Semantic name remains unreviewed. */

LONG FUN_40acc2e8(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40acc344 FUN_40acc344 */

/* Boundary evidence: original MIPS .pdata 40acc344..40acc3a3. Semantic name remains unreviewed. */

undefined4 FUN_40acc344(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40ad07cc((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40acc3a4 FUN_40acc3a4 */

/* Boundary evidence: original MIPS .pdata 40acc3a4..40acc3fb. Semantic name remains unreviewed. */

undefined4 FUN_40acc3a4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40acc3fc FUN_40acc3fc */

/* Boundary evidence: original MIPS .pdata 40acc3fc..40acc493. Semantic name remains unreviewed. */

undefined4 FUN_40acc3fc(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40ad4d48,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40ad55c4,0x10), iVar2 == 0)) {
      uVar1 = FUN_40acf3f8(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40acc494 FUN_40acc494 */

/* Boundary evidence: original MIPS .pdata 40acc494..40acc4af. Semantic name remains unreviewed. */

void FUN_40acc494(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40acc4b0 FUN_40acc4b0 */

/* Boundary evidence: original MIPS .pdata 40acc4b0..40acc50b. Semantic name remains unreviewed. */

LONG FUN_40acc4b0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40acc50c FUN_40acc50c */

/* Boundary evidence: original MIPS .pdata 40acc50c..40acc54b. Semantic name remains unreviewed. */

undefined4 FUN_40acc50c(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40acc54c FUN_40acc54c */

/* Boundary evidence: original MIPS .pdata 40acc54c..40acc58f. Semantic name remains unreviewed. */

void FUN_40acc54c(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40acbd14(param_1 + 0x1c);
  FUN_40acf3a0();
  return;
}



/* 40acc590 FUN_40acc590 */

/* Boundary evidence: original MIPS .pdata 40acc590..40acc637. Semantic name remains unreviewed. */

void FUN_40acc590(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ad4d28,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40ad4e68,0x10);
    if (iVar1 != 0) {
      FUN_40acf494(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40acf3f8(piVar2,param_3);
  return;
}



/* 40acc638 FUN_40acc638 */

/* Boundary evidence: original MIPS .pdata 40acc638..40acc663. Semantic name remains unreviewed. */

void FUN_40acc638(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40acc664 FUN_40acc664 */

/* Boundary evidence: original MIPS .pdata 40acc664..40acc68f. Semantic name remains unreviewed. */

void FUN_40acc664(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40acc690 FUN_40acc690 */

/* Boundary evidence: original MIPS .pdata 40acc690..40acc6af. Semantic name remains unreviewed. */

undefined4 FUN_40acc690(int param_1,void *param_2)

{
  FUN_40acbdbc((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40acc6b0 FUN_40acc6b0 */

/* Boundary evidence: original MIPS .pdata 40acc6b0..40acc707. Semantic name remains unreviewed. */

undefined4 FUN_40acc6b0(int param_1,int *param_2)

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



/* 40acc708 FUN_40acc708 */

/* Boundary evidence: original MIPS .pdata 40acc708..40acc75b. Semantic name remains unreviewed. */

undefined4 FUN_40acc708(int param_1,int *param_2)

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



/* 40acc75c FUN_40acc75c */

/* Boundary evidence: original MIPS .pdata 40acc75c..40acc807. Semantic name remains unreviewed. */

undefined4 FUN_40acc75c(int param_1,int *param_2)

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
      FUN_40ad06c0((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40acc830 FUN_40acc830 */

/* Boundary evidence: original MIPS .pdata 40acc830..40acc877. Semantic name remains unreviewed. */

int FUN_40acc830(int param_1,int param_2)

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



/* 40acc880 FUN_40acc880 */

/* Boundary evidence: original MIPS .pdata 40acc880..40acc8cf. Semantic name remains unreviewed. */

undefined4 FUN_40acc880(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40acc900 FUN_40acc900 */

/* Boundary evidence: original MIPS .pdata 40acc900..40acc927. Semantic name remains unreviewed. */

void FUN_40acc900(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40acc928 FUN_40acc928 */

/* Boundary evidence: original MIPS .pdata 40acc928..40acc98f. Semantic name remains unreviewed. */

int FUN_40acc928(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40acc6b0(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40ad4df8,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40acc990 FUN_40acc990 */

/* Boundary evidence: original MIPS .pdata 40acc990..40acc9f3. Semantic name remains unreviewed. */

undefined4 FUN_40acc990(int param_1)

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



/* 40acc9f4 FUN_40acc9f4 */

/* Boundary evidence: original MIPS .pdata 40acc9f4..40acca2f. Semantic name remains unreviewed. */

void FUN_40acc9f4(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40ad43a8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ad4dd8,param_2);
  return;
}



/* 40acca30 FUN_40acca30 */

/* Boundary evidence: original MIPS .pdata 40acca30..40accbbb. Semantic name remains unreviewed. */

int FUN_40acca30(int *param_1,int *param_2,int *param_3)

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



/* 40accbbc FUN_40accbbc */

/* Boundary evidence: original MIPS .pdata 40accbbc..40accc03. Semantic name remains unreviewed. */

undefined4 FUN_40accbbc(int param_1)

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



/* 40accc04 FUN_40accc04 */

/* Boundary evidence: original MIPS .pdata 40accc04..40accc43. Semantic name remains unreviewed. */

undefined4 FUN_40accc04(int param_1)

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



/* 40accc44 FUN_40accc44 */

/* Boundary evidence: original MIPS .pdata 40accc44..40accc83. Semantic name remains unreviewed. */

undefined4 FUN_40accc44(int param_1)

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



/* 40accc84 FUN_40accc84 */

/* Boundary evidence: original MIPS .pdata 40accc84..40acccc3. Semantic name remains unreviewed. */

undefined4 FUN_40accc84(int param_1)

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



/* 40acccc4 FUN_40acccc4 */

/* Boundary evidence: original MIPS .pdata 40acccc4..40accd03. Semantic name remains unreviewed. */

undefined4 FUN_40acccc4(int param_1)

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



/* 40accd10 FUN_40accd10 */

/* Boundary evidence: original MIPS .pdata 40accd10..40accd5b. Semantic name remains unreviewed. */

bool FUN_40accd10(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40accd5c FUN_40accd5c */

/* Boundary evidence: original MIPS .pdata 40accd5c..40accda7. Semantic name remains unreviewed. */

bool FUN_40accd5c(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40accda8 FUN_40accda8 */

/* Boundary evidence: original MIPS .pdata 40accda8..40accde7. Semantic name remains unreviewed. */

undefined4 FUN_40accda8(int param_1)

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



/* 40accde8 FUN_40accde8 */

/* Boundary evidence: original MIPS .pdata 40accde8..40acce27. Semantic name remains unreviewed. */

undefined4 FUN_40accde8(int param_1)

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



/* 40acce28 FUN_40acce28 */

/* Boundary evidence: original MIPS .pdata 40acce28..40acce83. Semantic name remains unreviewed. */

undefined4 FUN_40acce28(int param_1)

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



/* 40acce84 FUN_40acce84 */

/* Boundary evidence: original MIPS .pdata 40acce84..40accecb. Semantic name remains unreviewed. */

void FUN_40acce84(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40acc54c(param_1);
  return;
}



/* 40accecc FUN_40accecc */

/* Boundary evidence: original MIPS .pdata 40accecc..40accf4b. Semantic name remains unreviewed. */

void FUN_40accecc(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ad4df8,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40acf3f8(piVar2,param_3);
  }
  else {
    FUN_40acc590(param_1,param_2,param_3);
  }
  return;
}



/* 40accf4c FUN_40accf4c */

/* Boundary evidence: original MIPS .pdata 40accf4c..40acd013. Semantic name remains unreviewed. */

HRESULT FUN_40accf4c(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40ad43a8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ad4dd8,ppv),
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



/* 40acd014 FUN_40acd014 */

/* Boundary evidence: original MIPS .pdata 40acd014..40acd0b3. Semantic name remains unreviewed. */

undefined4 FUN_40acd014(int param_1,int *param_2,undefined1 param_3)

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



/* 40acd0b4 FUN_40acd0b4 */

/* Boundary evidence: original MIPS .pdata 40acd0b4..40acd33b. Semantic name remains unreviewed. */

int FUN_40acd0b4(int param_1,int *param_2)

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
      iVar2 = (**(code **)*param_2)(param_2,&UNK_40ad4dc8,local_20);
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



/* 40acd33c FUN_40acd33c */

/* Boundary evidence: original MIPS .pdata 40acd33c..40acd3d7. Semantic name remains unreviewed. */

int FUN_40acd33c(int *param_1,int param_2,int param_3,int *param_4)

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



/* 40acd3d8 FUN_40acd3d8 */

/* Boundary evidence: original MIPS .pdata 40acd3d8..40acd537. Semantic name remains unreviewed. */

int FUN_40acd3d8(int param_1)

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
        iVar2 = (**(code **)*local_30)(local_30,&DAT_40ad4df8,&local_2c);
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



/* 40acd538 FUN_40acd538 */

/* Boundary evidence: original MIPS .pdata 40acd538..40acd57f. Semantic name remains unreviewed. */

undefined4 FUN_40acd538(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40acd580 FUN_40acd580 */

/* Boundary evidence: original MIPS .pdata 40acd580..40acd5c3. Semantic name remains unreviewed. */

undefined4 FUN_40acd580(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40acd5e4 FUN_40acd5e4 */

/* Boundary evidence: original MIPS .pdata 40acd5e4..40acd623. Semantic name remains unreviewed. */

undefined4 FUN_40acd5e4(int param_1)

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



/* 40acd678 FUN_40acd678 */

/* Boundary evidence: original MIPS .pdata 40acd678..40acd8cf. Semantic name remains unreviewed. */

int FUN_40acd678(undefined4 *param_1,int *param_2,int param_3)

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
              if (iVar1 < 0) goto LAB_40acd898;
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
LAB_40acd898:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40acd8d0 FUN_40acd8d0 */

/* Boundary evidence: original MIPS .pdata 40acd8d0..40acd9af. Semantic name remains unreviewed. */

void FUN_40acd8d0(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ad4d88,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40ad4d78,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40ad55d4,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40ad4e08,0x10);
    if (iVar1 != 0) {
      FUN_40acf494(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40acf3f8(piVar2,param_3);
  return;
}



/* 40acd9b0 FUN_40acd9b0 */

/* Boundary evidence: original MIPS .pdata 40acd9b0..40acda0b. Semantic name remains unreviewed. */

void FUN_40acd9b0(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40acf3a0();
  return;
}



/* 40acda0c FUN_40acda0c */

/* Boundary evidence: original MIPS .pdata 40acda0c..40acda8f. Semantic name remains unreviewed. */

undefined4 FUN_40acda0c(int param_1,int *param_2)

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



/* 40acda90 FUN_40acda90 */

/* Boundary evidence: original MIPS .pdata 40acda90..40acdb13. Semantic name remains unreviewed. */

undefined4 FUN_40acda90(int param_1,undefined4 *param_2)

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



/* 40acdb14 FUN_40acdb14 */

/* Boundary evidence: original MIPS .pdata 40acdb14..40acdb9b. Semantic name remains unreviewed. */

int FUN_40acdb14(int param_1,uint *param_2)

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



/* 40acdb9c FUN_40acdb9c */

/* Boundary evidence: original MIPS .pdata 40acdb9c..40acdcb3. Semantic name remains unreviewed. */

undefined4 FUN_40acdb9c(int param_1,LPCWSTR param_2,int *param_3)

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
          goto LAB_40acdc5c;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40acdc5c:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40acdcb4 FUN_40acdcb4 */

/* Boundary evidence: original MIPS .pdata 40acdcb4..40acddcf. Semantic name remains unreviewed. */

undefined4 FUN_40acdcb4(int param_1,undefined4 *param_2,wchar_t *param_3)

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
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40ad4e98,(undefined4 *)(param_1 + 0x38));
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



/* 40acddd0 FUN_40acddd0 */

/* Boundary evidence: original MIPS .pdata 40acddd0..40acdea3. Semantic name remains unreviewed. */

undefined4 FUN_40acddd0(int param_1)

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
    HVar3 = CoCreateInstance((IID *)&DAT_40ad3e68,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ad4e58,local_10);
    if (-1 < HVar3) {
      FUN_40acd678(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40acdea4 FUN_40acdea4 */

/* Boundary evidence: original MIPS .pdata 40acdea4..40acdf97. Semantic name remains unreviewed. */

int FUN_40acdea4(int param_1)

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
    HVar2 = CoCreateInstance((IID *)&DAT_40ad3e68,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ad4e58,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40acd678(puVar1,local_18[0],0);
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



/* 40acdf98 FUN_40acdf98 */

/* Boundary evidence: original MIPS .pdata 40acdf98..40acdfe3. Semantic name remains unreviewed. */

undefined4 * FUN_40acdf98(undefined4 *param_1,uint param_2)

{
  FUN_40acc1e8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40acdfe4 FUN_40acdfe4 */

/* Boundary evidence: original MIPS .pdata 40acdfe4..40ace17b. Semantic name remains unreviewed. */

undefined4 FUN_40acdfe4(int param_1,uint param_2,int *param_3,uint *param_4)

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
    bVar1 = FUN_40accd10(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40acc3a4(param_1);
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
        iVar3 = FUN_40ad0820((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40ad0920((int *)(param_1 + 0x18),iVar2);
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



/* 40ace17c FUN_40ace17c */

/* Boundary evidence: original MIPS .pdata 40ace17c..40ace1f7. Semantic name remains unreviewed. */

undefined4 FUN_40ace17c(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40accd10(param_1);
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



/* 40ace1f8 FUN_40ace1f8 */

/* Boundary evidence: original MIPS .pdata 40ace1f8..40ace25b. Semantic name remains unreviewed. */

undefined4 * FUN_40ace1f8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40ad5328;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40ace25c FUN_40ace25c */

/* Boundary evidence: original MIPS .pdata 40ace25c..40ace3ef. Semantic name remains unreviewed. */

uint FUN_40ace25c(int param_1,uint param_2,undefined4 *param_3,int *param_4)

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
  
  local_28 = DAT_40ad707c;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40ad0c64(DAT_40ad707c);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40accd5c(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40ad0c64(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40ad0c64(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40acbd30(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40ace39c:
          FUN_40acbd14((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40ace39c;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40acbd14((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40ad0c64(local_28);
    }
  }
  return uVar3;
}



/* 40ace3f0 FUN_40ace3f0 */

/* Boundary evidence: original MIPS .pdata 40ace3f0..40ace4a7. Semantic name remains unreviewed. */

uint FUN_40ace3f0(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40ad707c;
  bVar1 = FUN_40accd5c(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40ad0c64(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40acbd30(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40acbd14((int)auStack_60);
    FUN_40ad0c64(local_18);
  }
  return uVar3;
}



/* 40ace4a8 FUN_40ace4a8 */

/* Boundary evidence: original MIPS .pdata 40ace4a8..40ace61f. Semantic name remains unreviewed. */

int FUN_40ace4a8(int *param_1,int *param_2,undefined4 param_3)

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



/* 40ace620 FUN_40ace620 */

/* Boundary evidence: original MIPS .pdata 40ace620..40ace793. Semantic name remains unreviewed. */

int FUN_40ace620(int *param_1,int *param_2,void *param_3,int *param_4)

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
             (iVar3 = FUN_40acbe54(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40ace4a8(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40acbf68(local_28);
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



/* 40ace794 FUN_40ace794 */

/* Boundary evidence: original MIPS .pdata 40ace794..40ace91b. Semantic name remains unreviewed. */

int FUN_40ace794(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40acbde8(param_3), iVar1 == 0)) {
    iVar1 = FUN_40ace4a8(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40ace620(param_1,param_2,param_3,local_30[0]);
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
  iVar2 = FUN_40ace620(param_1,param_2,param_3,local_30[0]);
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



/* 40ace91c FUN_40ace91c */

/* Boundary evidence: original MIPS .pdata 40ace91c..40aceae3. Semantic name remains unreviewed. */

int FUN_40ace91c(int param_1,int *param_2,int param_3)

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
          goto LAB_40aceab4;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40aceab4;
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
LAB_40aceab4:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40aceae4 FUN_40aceae4 */

/* Boundary evidence: original MIPS .pdata 40aceae4..40aceb83. Semantic name remains unreviewed. */

undefined4 FUN_40aceae4(int param_1)

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



/* 40aceb84 FUN_40aceb84 */

/* Boundary evidence: original MIPS .pdata 40aceb84..40acec0f. Semantic name remains unreviewed. */

undefined4 FUN_40aceb84(int param_1,void *param_2)

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
      FUN_40acbbe0(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40acbc1c(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40acec10 FUN_40acec10 */

/* Boundary evidence: original MIPS .pdata 40acec10..40acec2b. Semantic name remains unreviewed. */

void FUN_40acec10(int param_1,undefined4 *param_2)

{
  FUN_40ad06fc(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40acec2c FUN_40acec2c */

/* Boundary evidence: original MIPS .pdata 40acec2c..40aceca7. Semantic name remains unreviewed. */

int FUN_40acec2c(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40aceae4(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40aceca8 FUN_40aceca8 */

/* Boundary evidence: original MIPS .pdata 40aceca8..40aced87. Semantic name remains unreviewed. */

undefined4 * FUN_40aceca8(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40ad5308;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40ad07a8(param_1 + 6);
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
    FUN_40ad09bc(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40aced88 FUN_40aced88 */

/* Boundary evidence: original MIPS .pdata 40aced88..40acee33. Semantic name remains unreviewed. */

undefined4 FUN_40aced88(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40accd10(param_1);
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
        puVar2 = FUN_40aceca8(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40acee34 FUN_40acee34 */

/* Boundary evidence: original MIPS .pdata 40acee34..40aceec3. Semantic name remains unreviewed. */

undefined4 * FUN_40acee34(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40ad5328;
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



/* 40aceec4 FUN_40aceec4 */

/* Boundary evidence: original MIPS .pdata 40aceec4..40acef6f. Semantic name remains unreviewed. */

undefined4 FUN_40aceec4(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40accd5c(param_1);
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
        puVar2 = FUN_40acee34(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40acef70 FUN_40acef70 */

/* Boundary evidence: original MIPS .pdata 40acef70..40acf063. Semantic name remains unreviewed. */

undefined4 *
FUN_40acef70(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40acf438(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40acbd30(param_1 + 7);
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



/* 40acf064 FUN_40acf064 */

/* Boundary evidence: original MIPS .pdata 40acf064..40acf143. Semantic name remains unreviewed. */

int FUN_40acf064(int param_1,int *param_2,void *param_3)

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
        iVar1 = FUN_40ace794(piVar2,param_2,param_3);
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



/* 40acf144 FUN_40acf144 */

/* Boundary evidence: original MIPS .pdata 40acf144..40acf1c3. Semantic name remains unreviewed. */

undefined4 FUN_40acf144(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40acee34(puVar2,param_1 + -0xc,0);
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



/* 40acf1c4 FUN_40acf1c4 */

/* Boundary evidence: original MIPS .pdata 40acf1c4..40acf20f. Semantic name remains unreviewed. */

undefined4 *
FUN_40acf1c4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40acef70(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40acf210 FUN_40acf210 */

/* Boundary evidence: original MIPS .pdata 40acf210..40acf26b. Semantic name remains unreviewed. */

undefined4 *
FUN_40acf210(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40acef70(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40acf26c FUN_40acf26c */

/* Boundary evidence: original MIPS .pdata 40acf26c..40acf2ef. Semantic name remains unreviewed. */

undefined4 *
FUN_40acf26c(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40acf438(param_1,param_2,param_3);
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



/* 40acf2f0 FUN_40acf2f0 */

/* Boundary evidence: original MIPS .pdata 40acf2f0..40acf36f. Semantic name remains unreviewed. */

undefined4 FUN_40acf2f0(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40aceca8(puVar2,param_1 + -0xc,0);
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



/* 40acf370 FUN_40acf370 */

/* Boundary evidence: original MIPS .pdata 40acf370..40acf39f. Semantic name remains unreviewed. */

undefined4 FUN_40acf370(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40ad76ac);
  return param_1;
}



/* 40acf3a0 FUN_40acf3a0 */

/* Boundary evidence: original MIPS .pdata 40acf3a0..40acf3f7. Semantic name remains unreviewed. */

void FUN_40acf3a0(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40ad76ac);
  if ((LVar1 == 0) && (DAT_40ad76a8 != 0)) {
    FreeLibrary((HMODULE)DAT_40ad76a8);
    DAT_40ad76a8 = 0;
  }
  return;
}



/* 40acf3f8 FUN_40acf3f8 */

/* Boundary evidence: original MIPS .pdata 40acf3f8..40acf437. Semantic name remains unreviewed. */

undefined4 FUN_40acf3f8(int *param_1,undefined4 *param_2)

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



/* 40acf438 FUN_40acf438 */

/* Boundary evidence: original MIPS .pdata 40acf438..40acf493. Semantic name remains unreviewed. */

undefined4 * FUN_40acf438(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40ad5364;
  InterlockedIncrement(&DAT_40ad76ac);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40acf494 FUN_40acf494 */

/* Boundary evidence: original MIPS .pdata 40acf494..40acf517. Semantic name remains unreviewed. */

undefined4 FUN_40acf494(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40ad55c4,0x10);
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



/* 40acf518 FUN_40acf518 */

/* Boundary evidence: original MIPS .pdata 40acf518..40acf553. Semantic name remains unreviewed. */

uint FUN_40acf518(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40acf554 FUN_40acf554 */

/* Boundary evidence: original MIPS .pdata 40acf554..40acf5cb. Semantic name remains unreviewed. */

uint FUN_40acf554(int *param_1)

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



/* 40acf5cc FUN_40acf5cc */

/* Boundary evidence: original MIPS .pdata 40acf5cc..40acf60f. Semantic name remains unreviewed. */

void FUN_40acf5cc(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x28),*(int *)(param_1 + 0x3c),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40acf610 FUN_40acf610 */

/* Boundary evidence: original MIPS .pdata 40acf610..40acf6d3. Semantic name remains unreviewed. */

void FUN_40acf610(LPCRITICAL_SECTION param_1)

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
      FUN_40acf5cc((int)param_1);
      LeaveCriticalSection(param_1);
      (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
      return;
    }
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40acf6d4 FUN_40acf6d4 */

/* Boundary evidence: original MIPS .pdata 40acf6d4..40acf72b. Semantic name remains unreviewed. */

void FUN_40acf6d4(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_40ad0920(*(undefined4 **)(param_1 + 0x24),param_2);
  if ((puVar1 == (undefined4 *)0x0) && (param_2 < (int *)0xfffffff1)) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



/* 40acf72c FUN_40acf72c */

/* Boundary evidence: original MIPS .pdata 40acf72c..40acf9cb. Semantic name remains unreviewed. */

LONG FUN_40acf72c(LPCRITICAL_SECTION param_1,undefined4 *param_2,int param_3,int *param_4)

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
        else if ((param_1[2].RecursionCount == 0) || (param_1[3].LockCount == 0)) goto LAB_40acf7ec;
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
          FUN_40acf6d4((int)param_1,(int *)*param_2);
          param_2 = param_2 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      *param_4 = param_3;
      if ((param_1[1].LockCount == 0) ||
         (param_1[1].RecursionCount <=
          param_1[2].RecursionCount + *(int *)((int)param_1[1].OwningThread + 8))) {
        FUN_40acf5cc((int)param_1);
      }
      LVar1 = 0;
      goto LAB_40acf994;
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
  goto LAB_40acf7fc;
LAB_40acf7ec:
  *param_4 = iVar2 - iVar3;
  if (iVar2 - iVar3 < 0) {
    *param_4 = 0;
  }
LAB_40acf7fc:
  LVar1 = param_1[3].RecursionCount;
LAB_40acf994:
  LeaveCriticalSection(param_1);
  return LVar1;
}



/* 40acf9cc FUN_40acf9cc */

/* Boundary evidence: original MIPS .pdata 40acf9cc..40acfac3. Semantic name remains unreviewed. */

void FUN_40acf9cc(LPCRITICAL_SECTION param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  EnterCriticalSection(param_1);
  piVar2 = param_1[1].OwningThread;
  if (piVar2 != (int *)0x0) {
    while (piVar2 = (int *)FUN_40ad0a64(piVar2), piVar2 != (int *)0x0) {
      if (piVar2 < (int *)0xfffffff1) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      else if (piVar2 == (int *)0xfffffffb) {
        pvVar1 = (void *)FUN_40ad0a64(param_1[1].OwningThread);
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



/* 40acfac4 FUN_40acfac4 */

/* Boundary evidence: original MIPS .pdata 40acfac4..40acfbbf. Semantic name remains unreviewed. */

void FUN_40acfac4(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  
  if (param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    (**(code **)(*(int *)param_1[1].DebugInfo + 8))();
  }
  if (param_1[2].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    FUN_40acf9cc(param_1);
  }
  else {
    EnterCriticalSection(param_1);
    param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1;
    param_1[3].RecursionCount = 1;
    FUN_40acf5cc((int)param_1);
    LeaveCriticalSection(param_1);
    WaitForSingleObject(param_1[2].DebugInfo,0xffffffff);
    CloseHandle(param_1[2].DebugInfo);
    puVar1 = param_1[1].OwningThread;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_40ad0a1c(puVar1);
      operator_delete(puVar1);
    }
  }
  if (param_1[1].LockSemaphore != (HANDLE)0x0) {
    CloseHandle(param_1[1].LockSemaphore);
  }
  operator_delete((void *)param_1[2].LockCount);
  FUN_40ad061c(&param_1[1].SpinCount);
  DeleteCriticalSection(param_1);
  return;
}



/* 40acfbc0 FUN_40acfbc0 */

/* Boundary evidence: original MIPS .pdata 40acfbc0..40acfe97. Semantic name remains unreviewed. */

undefined4 FUN_40acfbc0(LPCRITICAL_SECTION param_1)

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
LAB_40acfbfc:
  do {
    bVar1 = false;
    EnterCriticalSection(param_1);
    do {
      while( true ) {
        if (param_1[3].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
          FUN_40acf9cc(param_1);
          LeaveCriticalSection(param_1);
          return 0;
        }
        if (param_1[2].LockSemaphore != (HANDLE)0x0) {
          FUN_40acf9cc(param_1);
          EventModify(param_1[1].SpinCount,3);
        }
        uVar2 = FUN_40ad0a64(param_1[1].OwningThread);
        if (uVar2 != 0) break;
        if ((param_1[1].LockCount != 0) || (param_1[2].RecursionCount == 0)) {
          param_1[2].OwningThread = (HANDLE)((int)param_1[2].OwningThread + 1);
          bVar1 = true;
          goto LAB_40acfd10;
        }
LAB_40acfcbc:
        if (uVar2 != 0xfffffffe) {
          if (uVar2 == 0xfffffffb) {
            pvVar3 = (void *)FUN_40ad0a64(param_1[1].OwningThread);
          }
          goto LAB_40acfcf4;
        }
        if (param_1[2].RecursionCount != 0) goto LAB_40acfcf4;
      }
      if (0xfffffff0 < uVar2) goto LAB_40acfcbc;
      if (param_1[2].RecursionCount < param_1[1].RecursionCount) {
        *(uint *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = uVar2;
        param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
      }
    } while (param_1[2].RecursionCount != param_1[1].RecursionCount);
LAB_40acfcf4:
    pvVar6 = (void *)param_1[2].RecursionCount;
    param_1[2].RecursionCount = 0;
LAB_40acfd10:
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
        if (param_1[3].RecursionCount != 0) goto LAB_40acfbfc;
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
      goto LAB_40acfbfc;
    }
    WaitForSingleObject(param_1[1].LockSemaphore,0xffffffff);
  } while( true );
}



/* 40acfe98 FUN_40acfe98 */

/* Boundary evidence: original MIPS .pdata 40acfe98..40acff07. Semantic name remains unreviewed. */

void FUN_40acfe98(LPCRITICAL_SECTION param_1)

{
  int aiStack_10 [2];
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    param_1[3].LockCount = 1;
    FUN_40acf72c(param_1,(undefined4 *)0x0,0,aiStack_10);
    param_1[3].LockCount = 0;
  }
  else {
    EnterCriticalSection(param_1);
    FUN_40acf6d4((int)param_1,(int *)0xfffffffe);
    FUN_40acf5cc((int)param_1);
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40acff08 FUN_40acff08 */

/* Boundary evidence: original MIPS .pdata 40acff08..40acffa7. Semantic name remains unreviewed. */

void FUN_40acff08(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[1].LockCount != 0) {
      FUN_40acfe98(param_1);
    }
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      (**(code **)(*(int *)param_1->SpinCount + 0x38))();
    }
  }
  else if (param_1[3].RecursionCount == 0) {
    param_1[2].SpinCount = 0;
    FUN_40acf6d4((int)param_1,(int *)0xfffffffd);
    FUN_40acf5cc((int)param_1);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40acffa8 FUN_40acffa8 */

/* Boundary evidence: original MIPS .pdata 40acffa8..40ad005b. Semantic name remains unreviewed. */

void FUN_40acffa8(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  
  EnterCriticalSection(param_1);
  if ((param_1[2].SpinCount == 0) || (param_1[1].OwningThread == (HANDLE)0x0)) {
    LeaveCriticalSection(param_1);
    if (param_1[1].OwningThread == (HANDLE)0x0) {
      FUN_40acf9cc(param_1);
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



/* 40ad005c FUN_40ad005c */

/* Boundary evidence: original MIPS .pdata 40ad005c..40ad0083. Semantic name remains unreviewed. */

void FUN_40ad005c(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  int aiStack_10 [2];
  
  local_res4[0] = param_2;
  FUN_40acf72c(param_1,local_res4,1,aiStack_10);
  return;
}



/* 40ad0084 FUN_40ad0084 */

/* Boundary evidence: original MIPS .pdata 40ad0084..40ad00d7. Semantic name remains unreviewed. */

undefined4 FUN_40ad0084(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40ad064c();
  uVar2 = FUN_40acfbc0(param_1);
  if (-1 < iVar1) {
    CoUninitialize();
  }
  return uVar2;
}



/* 40ad00d8 FUN_40ad00d8 */

/* Boundary evidence: original MIPS .pdata 40ad00d8..40ad031b. Semantic name remains unreviewed. */

LPCRITICAL_SECTION
FUN_40ad00d8(LPCRITICAL_SECTION param_1,undefined4 *param_2,DWORD *param_3,int param_4,int param_5,
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
  FUN_40ad05dc(&param_1[1].SpinCount,0);
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
  DVar1 = (**(code **)*param_2)(param_2,&DAT_40ad4df8,p_Var9);
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
LAB_40ad0218:
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
        FUN_40ad0788(puVar5,0,param_8);
      }
      param_1[1].OwningThread = puVar5;
      if (puVar5 == (undefined4 *)0x0) goto LAB_40ad0218;
      p_Var6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40ad0084,param_1,0,aDStack_28);
      param_1[2].DebugInfo = p_Var6;
      if (p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        FUN_40ad031c(p_Var6,param_9);
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



/* 40ad031c FUN_40ad031c */

/* Boundary evidence: original MIPS .pdata 40ad031c..40ad05db. Semantic name remains unreviewed. */

void FUN_40ad031c(undefined4 param_1,int param_2)

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
  
  if (DAT_40ad706c == 0xffffffff) {
    DAT_40ad7070 = 0xfa;
    DAT_40ad706c = 0xf9;
    DAT_40ad7074 = 0xfb;
    DAT_40ad7078 = 0xfc;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,0,
                          &local_30);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Highest",(LPDWORD)0x0,&local_34,(LPBYTE)&local_28,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_28)) {
        local_28 = DAT_40ad706c;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"AboveNormal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_2c,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_2c)) {
        local_2c = DAT_40ad7070;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Normal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_24,&local_38
                              );
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_24)) {
        local_24 = DAT_40ad7074;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"BelowNormal",(LPDWORD)0x0,&local_34,(LPBYTE)local_20,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_20[0])) {
        local_20[0] = DAT_40ad7078;
      }
      if (((local_28 <= local_2c) && (local_2c <= local_24)) && (local_24 <= local_20[0])) {
        DAT_40ad706c = local_28;
        DAT_40ad7070 = local_2c;
        DAT_40ad7074 = local_24;
        DAT_40ad7078 = local_20[0];
      }
      RegCloseKey(local_30);
    }
  }
  uVar2 = DAT_40ad706c;
  if (((param_2 != 1) && (uVar2 = DAT_40ad7070, param_2 != 2)) &&
     (uVar2 = DAT_40ad7078, param_2 != 4)) {
    uVar2 = DAT_40ad7074;
  }
  CeSetThreadPriority(param_1,uVar2);
  return;
}



/* 40ad05dc FUN_40ad05dc */

/* Boundary evidence: original MIPS .pdata 40ad05dc..40ad061b. Semantic name remains unreviewed. */

undefined4 * FUN_40ad05dc(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



/* 40ad061c FUN_40ad061c */

/* Boundary evidence: original MIPS .pdata 40ad061c..40ad064b. Semantic name remains unreviewed. */

void FUN_40ad061c(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40ad064c FUN_40ad064c */

/* Boundary evidence: original MIPS .pdata 40ad064c..40ad06bf. Semantic name remains unreviewed. */

undefined4 FUN_40ad064c(void)

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



/* 40ad06c0 FUN_40ad06c0 */

short * FUN_40ad06c0(short *param_1,short *param_2,int param_3)

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



/* 40ad06fc FUN_40ad06fc */

/* Boundary evidence: original MIPS .pdata 40ad06fc..40ad0787. Semantic name remains unreviewed. */

undefined4 FUN_40ad06fc(wchar_t *param_1,undefined4 *param_2)

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



/* 40ad0788 FUN_40ad0788 */

undefined4 * FUN_40ad0788(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40ad07a8 FUN_40ad07a8 */

undefined4 * FUN_40ad07a8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40ad07cc FUN_40ad07cc */

/* Boundary evidence: original MIPS .pdata 40ad07cc..40ad081f. Semantic name remains unreviewed. */

void FUN_40ad07cc(undefined4 *param_1)

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



/* 40ad0820 FUN_40ad0820 */

int FUN_40ad0820(int *param_1,int param_2)

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



/* 40ad0864 FUN_40ad0864 */

/* Boundary evidence: original MIPS .pdata 40ad0864..40ad091f. Semantic name remains unreviewed. */

int FUN_40ad0864(int *param_1,int *param_2)

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



/* 40ad0920 FUN_40ad0920 */

/* Boundary evidence: original MIPS .pdata 40ad0920..40ad09bb. Semantic name remains unreviewed. */

undefined4 * FUN_40ad0920(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40ad0970;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40ad0970:
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



/* 40ad09bc FUN_40ad09bc */

/* Boundary evidence: original MIPS .pdata 40ad09bc..40ad0a1b. Semantic name remains unreviewed. */

undefined4 FUN_40ad09bc(undefined4 *param_1,int *param_2)

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
    puVar1 = FUN_40ad0920(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40ad0a1c FUN_40ad0a1c */

/* Boundary evidence: original MIPS .pdata 40ad0a1c..40ad0a63. Semantic name remains unreviewed. */

void FUN_40ad0a1c(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40ad07cc(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40ad0a64 FUN_40ad0a64 */

/* Boundary evidence: original MIPS .pdata 40ad0a64..40ad0a7f. Semantic name remains unreviewed. */

void FUN_40ad0a64(int *param_1)

{
  FUN_40ad0864(param_1,(int *)*param_1);
  return;
}



/* 40ad0b70 FUN_40ad0b70 */

/* Boundary evidence: original MIPS .pdata 40ad0b70..40ad0be3. Semantic name remains unreviewed. */

void FUN_40ad0b70(void)

{
  uint uVar1;
  
  if ((DAT_40ad707c == 0) || (DAT_40ad707c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40ad707c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40ad707c == 0) {
      DAT_40ad707c = 0xb064;
    }
  }
  DAT_40ad7080 = ~DAT_40ad707c;
  return;
}



/* 40ad0be4 FUN_40ad0be4 */

/* Boundary evidence: original MIPS .pdata 40ad0be4..40ad0c37. Semantic name remains unreviewed. */

void FUN_40ad0be4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40ad0c64(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40ad0c38 FUN_40ad0c38 */

/* Boundary evidence: original MIPS .pdata 40ad0c38..40ad0c63. Semantic name remains unreviewed. */

undefined4 FUN_40ad0c38(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40ad0be4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40ad0c64 FUN_40ad0c64 */

/* Boundary evidence: original MIPS .pdata 40ad0c64..40ad0cab. Semantic name remains unreviewed. */

void FUN_40ad0c64(uint param_1)

{
  if ((param_1 == DAT_40ad707c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40ad0cfc FUN_40ad0cfc */

/* Boundary evidence: original MIPS .pdata 40ad0cfc..40ad0e37. Semantic name remains unreviewed. */

int FUN_40ad0cfc(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40ad76d0 != (code *)0x0) {
      iVar2 = (*DAT_40ad76d0)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40ad0dac;
    FUN_40ad1070();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain(param_1,param_2);
  }
LAB_40ad0dac:
  if (((param_2 == 0) && (FUN_40ad0ff8(), iVar1 != 0)) && (DAT_40ad76d0 != (code *)0x0)) {
    iVar1 = (*DAT_40ad76d0)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40ad0e38 FUN_40ad0e38 */

/* Boundary evidence: original MIPS .pdata 40ad0e38..40ad0e63. Semantic name remains unreviewed. */

void FUN_40ad0e38(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40ad0e64 entry */

/* Boundary evidence: original MIPS .pdata 40ad0e64..40ad0ebb. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40ad0b70();
  }
  FUN_40ad0cfc(param_1,param_2,param_3);
  return;
}



/* 40ad0f0c FUN_40ad0f0c */

/* Boundary evidence: original MIPS .pdata 40ad0f0c..40ad0ff7. Semantic name remains unreviewed. */

void FUN_40ad0f0c(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40ad76c0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40ad76cc;
    if (DAT_40ad76cc != (undefined4 *)0x0) {
      while (DAT_40ad76c8 = DAT_40ad76c8 + -1, _Memory <= DAT_40ad76c8) {
        if ((code *)*DAT_40ad76c8 != (code *)0x0) {
          (*(code *)*DAT_40ad76c8)();
          _Memory = DAT_40ad76cc;
        }
      }
      free(_Memory);
      DAT_40ad76c8 = (undefined4 *)0x0;
      DAT_40ad76cc = (undefined4 *)0x0;
    }
    FUN_40ad101c((undefined4 *)&DAT_40ad2010,(undefined4 *)&DAT_40ad2014);
  }
  FUN_40ad101c((undefined4 *)&DAT_40ad2018,(undefined4 *)&DAT_40ad201c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40ad0ff8 FUN_40ad0ff8 */

/* Boundary evidence: original MIPS .pdata 40ad0ff8..40ad101b. Semantic name remains unreviewed. */

void FUN_40ad0ff8(void)

{
  FUN_40ad0f0c(0,0,1);
  return;
}



/* 40ad101c FUN_40ad101c */

/* Boundary evidence: original MIPS .pdata 40ad101c..40ad106f. Semantic name remains unreviewed. */

void FUN_40ad101c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40ad1070 FUN_40ad1070 */

/* Boundary evidence: original MIPS .pdata 40ad1070..40ad10ab. Semantic name remains unreviewed. */

void FUN_40ad1070(void)

{
  FUN_40ad101c((undefined4 *)&DAT_40ad2008,(undefined4 *)&DAT_40ad200c);
  FUN_40ad101c((undefined4 *)&DAT_40ad2000,(undefined4 *)&DAT_40ad2004);
  return;
}


