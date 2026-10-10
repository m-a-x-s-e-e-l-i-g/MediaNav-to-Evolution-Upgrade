/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40bc1000 FUN_40bc1000 */

uint FUN_40bc1000(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1[2];
  if (param_2 <= uVar1) {
    return (*param_1 << (0x20 - uVar1 & 0x1f)) >> (0x20 - param_2 & 0x1f);
  }
  return param_1[1] >> (0x20 - (param_2 - uVar1) & 0x1f) |
         ((1 << (uVar1 & 0x1f)) - 1U & *param_1) << (param_2 - uVar1 & 0x1f);
}



/* 40bc1064 FUN_40bc1064 */

/* Boundary evidence: original MIPS .pdata 40bc1064..40bc10b3. Semantic name remains unreviewed. */

undefined4 FUN_40bc1064(undefined1 *param_1,int param_2)

{
  undefined1 local_8 [3];
  undefined1 uStack_5;
  
  local_8 = (undefined1  [3])0x0;
  if (param_2 != 1) {
    if (param_2 != 2) {
      if (param_2 != 3) {
        return 0;
      }
      local_8 = (undefined1  [3])((uint3)(byte)param_1[2] << 8);
    }
    local_8[2] = param_1[1];
  }
  _local_8 = CONCAT13(*param_1,local_8);
  return _local_8;
}



/* 40bc10b4 FUN_40bc10b4 */

/* Boundary evidence: original MIPS .pdata 40bc10b4..40bc116b. Semantic name remains unreviewed. */

void FUN_40bc10b4(undefined4 *param_1,int param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 local_8 [2];
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  uVar2 = param_1[4];
  puVar1 = (undefined1 *)param_1[6];
  *param_1 = param_1[1];
  if (3 < uVar2) {
    local_8 = (undefined1  [2])CONCAT11(puVar1[2],puVar1[3]);
    _local_8 = CONCAT12(puVar1[1],local_8);
    _local_8 = CONCAT13(*puVar1,_local_8);
    param_1[4] = uVar2 - 4;
    goto LAB_40bc1148;
  }
  _local_8 = 0;
  _local_8 = 0;
  if (uVar2 == 1) {
LAB_40bc1138:
    _local_8 = CONCAT13(*puVar1,_local_8);
  }
  else {
    if (uVar2 == 2) {
LAB_40bc1130:
      _local_8 = CONCAT12(puVar1[1],local_8);
      goto LAB_40bc1138;
    }
    if (uVar2 == 3) {
      _local_8 = (uint3)(byte)puVar1[2] << 8;
      goto LAB_40bc1130;
    }
  }
  param_1[4] = 0;
LAB_40bc1148:
  param_1[1] = _local_8;
  param_1[6] = puVar1 + 4;
  param_1[2] = (param_1[2] - param_2) + 0x20;
  return;
}



/* 40bc116c FUN_40bc116c */

/* Boundary evidence: original MIPS .pdata 40bc116c..40bc11ef. Semantic name remains unreviewed. */

uint FUN_40bc116c(uint *param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_40bc1000(param_1,param_2);
    if ((char)param_1[5] == '\0') {
      if (param_2 < param_1[2]) {
        param_1[2] = param_1[2] - param_2;
      }
      else {
        FUN_40bc10b4(param_1,param_2);
      }
    }
  }
  return uVar1;
}



/* 40bc11f0 FUN_40bc11f0 */

/* Boundary evidence: original MIPS .pdata 40bc11f0..40bc1307. Semantic name remains unreviewed. */

void FUN_40bc11f0(undefined4 *param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 local_18;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((param_3 != 0) && (param_2 != (undefined1 *)0x0)) {
      param_1[8] = param_2;
      param_1[3] = param_3;
      param_1[4] = param_3;
      if (param_3 < 4) {
        local_18 = FUN_40bc1064(param_2,param_3);
        param_1[4] = 0;
      }
      else {
        local_18._0_2_ = CONCAT11(param_2[2],param_2[3]);
        local_18._0_3_ = CONCAT12(param_2[1],(undefined2)local_18);
        local_18 = CONCAT13(*param_2,(undefined3)local_18);
        param_1[4] = param_3 - 4;
      }
      uVar1 = param_1[4];
      *param_1 = local_18;
      if (uVar1 < 4) {
        local_18 = FUN_40bc1064(param_2 + 4,uVar1);
        param_1[4] = 0;
      }
      else {
        local_18._0_2_ = CONCAT11(param_2[6],param_2[7]);
        local_18._0_3_ = CONCAT12(param_2[5],(undefined2)local_18);
        local_18 = CONCAT13(param_2[4],(undefined3)local_18);
        param_1[4] = uVar1 - 4;
      }
      param_1[1] = local_18;
      param_1[7] = param_2;
      param_1[6] = param_2 + 8;
      param_1[2] = 0x20;
      *(undefined1 *)(param_1 + 5) = 0;
      return;
    }
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return;
}



/* 40bc1308 FUN_40bc1308 */

/* Boundary evidence: original MIPS .pdata 40bc1308..40bc20bf. Semantic name remains unreviewed. */

undefined4 FUN_40bc1308(undefined1 *param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  memset(param_1,0,0x1d7);
  param_1[0xb0] = 0;
  uVar1 = FUN_40bc1000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40bc10b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  *param_1 = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,2);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 3) {
      FUN_40bc10b4(param_2,2);
    }
    else {
      param_2[2] = param_2[2] - 2;
    }
  }
  param_1[1] = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40bc10b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[2] = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40bc10b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[3] = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40bc10b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[4] = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40bc10b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[5] = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,2);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 3) {
      FUN_40bc10b4(param_2,2);
    }
    else {
      param_2[2] = param_2[2] - 2;
    }
  }
  param_1[6] = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,3);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 4) {
      FUN_40bc10b4(param_2,3);
    }
    else {
      param_2[2] = param_2[2] - 3;
    }
  }
  param_1[7] = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40bc10b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[8] = (char)uVar1;
  uVar1 = FUN_40bc1000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40bc10b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[9] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40bc1000(param_2,4);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 5) {
        FUN_40bc10b4(param_2,4);
      }
      else {
        param_2[2] = param_2[2] - 4;
      }
    }
    param_1[10] = (char)uVar1;
  }
  uVar1 = FUN_40bc1000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40bc10b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[0xb] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40bc1000(param_2,4);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 5) {
        FUN_40bc10b4(param_2,4);
      }
      else {
        param_2[2] = param_2[2] - 4;
      }
    }
    param_1[0xc] = (char)uVar1;
  }
  uVar1 = FUN_40bc1000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40bc10b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[0xd] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40bc1000(param_2,2);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 3) {
        FUN_40bc10b4(param_2,2);
      }
      else {
        param_2[2] = param_2[2] - 2;
      }
    }
    param_1[0xf] = (char)uVar1;
    uVar1 = FUN_40bc1000(param_2,1);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 2) {
        FUN_40bc10b4(param_2,1);
      }
      else {
        param_2[2] = param_2[2] - 1;
      }
    }
    param_1[0xe] = (char)uVar1;
  }
  if (param_1[3] != '\0') {
    uVar1 = 0;
    do {
      uVar4 = param_2[2];
      if (uVar4 == 0) {
        bVar5 = (byte)(param_2[1] >> 0x18);
      }
      else {
        bVar5 = (byte)((*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x18);
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 2) {
          FUN_40bc10b4(param_2,1);
        }
        else {
          param_2[2] = uVar4 - 1;
        }
      }
      param_1[uVar1 + 0x10] = bVar5 >> 7;
      uVar4 = param_2[2];
      if (uVar4 < 4) {
        uVar6 = param_2[1] >> (0x20 - (4 - uVar4) & 0x1f) |
                ((1 << (uVar4 & 0x1f)) - 1U & *param_2) << (4 - uVar4 & 0x1f);
      }
      else {
        uVar6 = (*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x1c;
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 5) {
          FUN_40bc10b4(param_2,4);
        }
        else {
          param_2[2] = uVar4 - 4;
        }
      }
      param_1[uVar1 + 0x20] = (char)uVar6;
      if ((param_1[uVar1 + 0x10] & 1) == 0) {
        param_1[(uVar6 & 0xff) + 0x1b7] = param_1[0xb0];
        param_1[0x1b3] = param_1[0x1b3] + '\x01';
        param_1[0xb0] = param_1[0xb0] + '\x01';
      }
      else {
        param_1[(uVar6 & 0xff) + 0x1c7] = param_1[0xb0];
        param_1[0x1b3] = param_1[0x1b3] + '\x02';
        param_1[0xb0] = param_1[0xb0] + '\x02';
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < (byte)param_1[3]);
  }
  if (param_1[4] != '\0') {
    uVar1 = 0;
    do {
      uVar4 = param_2[2];
      if (uVar4 == 0) {
        bVar5 = (byte)(param_2[1] >> 0x18);
      }
      else {
        bVar5 = (byte)((*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x18);
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 2) {
          FUN_40bc10b4(param_2,1);
        }
        else {
          param_2[2] = uVar4 - 1;
        }
      }
      param_1[uVar1 + 0x30] = bVar5 >> 7;
      uVar4 = param_2[2];
      if (uVar4 < 4) {
        uVar6 = param_2[1] >> (0x20 - (4 - uVar4) & 0x1f) |
                ((1 << (uVar4 & 0x1f)) - 1U & *param_2) << (4 - uVar4 & 0x1f);
      }
      else {
        uVar6 = (*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x1c;
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 5) {
          FUN_40bc10b4(param_2,4);
        }
        else {
          param_2[2] = uVar4 - 4;
        }
      }
      param_1[uVar1 + 0x40] = (char)uVar6;
      if ((param_1[uVar1 + 0x30] & 1) == 0) {
        param_1[(uVar6 & 0xff) + 0x1b7] = param_1[0xb0];
        param_1[0x1b4] = param_1[0x1b4] + '\x01';
        param_1[0xb0] = param_1[0xb0] + '\x01';
      }
      else {
        param_1[(uVar6 & 0xff) + 0x1c7] = param_1[0xb0];
        param_1[0x1b4] = param_1[0x1b4] + '\x02';
        param_1[0xb0] = param_1[0xb0] + '\x02';
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < (byte)param_1[4]);
  }
  if (param_1[5] != '\0') {
    uVar1 = 0;
    do {
      uVar4 = param_2[2];
      if (uVar4 == 0) {
        bVar5 = (byte)(param_2[1] >> 0x18);
      }
      else {
        bVar5 = (byte)((*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x18);
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 2) {
          FUN_40bc10b4(param_2,1);
        }
        else {
          param_2[2] = uVar4 - 1;
        }
      }
      param_1[uVar1 + 0x50] = bVar5 >> 7;
      uVar4 = param_2[2];
      if (uVar4 < 4) {
        uVar6 = param_2[1] >> (0x20 - (4 - uVar4) & 0x1f) |
                ((1 << (uVar4 & 0x1f)) - 1U & *param_2) << (4 - uVar4 & 0x1f);
      }
      else {
        uVar6 = (*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x1c;
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 5) {
          FUN_40bc10b4(param_2,4);
        }
        else {
          param_2[2] = uVar4 - 4;
        }
      }
      param_1[uVar1 + 0x60] = (char)uVar6;
      if ((param_1[uVar1 + 0x50] & 1) == 0) {
        param_1[(uVar6 & 0xff) + 0x1b7] = param_1[0xb0];
        cVar3 = param_1[0xb0] + '\x01';
        param_1[0x1b5] = param_1[0x1b5] + '\x01';
      }
      else {
        param_1[(uVar6 & 0xff) + 0x1c7] = param_1[0xb0];
        cVar3 = param_1[0xb0] + '\x02';
        param_1[0x1b5] = param_1[0x1b5] + '\x02';
      }
      param_1[0xb0] = cVar3;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < (byte)param_1[5]);
  }
  if (param_1[6] != '\0') {
    uVar1 = 0;
    do {
      uVar4 = param_2[2];
      if (uVar4 < 4) {
        uVar6 = param_2[1] >> (0x20 - (4 - uVar4) & 0x1f) |
                ((1 << (uVar4 & 0x1f)) - 1U & *param_2) << (4 - uVar4 & 0x1f);
      }
      else {
        uVar6 = (*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x1c;
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 5) {
          FUN_40bc10b4(param_2,4);
        }
        else {
          param_2[2] = uVar4 - 4;
        }
      }
      param_1[uVar1 + 0x70] = (char)uVar6;
      param_1[(uVar6 & 0xff) + 0x1b7] = param_1[0xb0];
      uVar1 = uVar1 + 1 & 0xff;
      param_1[0x1b6] = param_1[0x1b6] + '\x01';
      param_1[0xb0] = param_1[0xb0] + '\x01';
    } while (uVar1 < (byte)param_1[6]);
  }
  uVar1 = 0;
  if (param_1[7] != '\0') {
    do {
      uVar4 = param_2[2];
      if (uVar4 < 4) {
        bVar5 = (byte)(param_2[1] >> (0x20 - (4 - uVar4) & 0x1f)) |
                (byte)(((1 << (uVar4 & 0x1f)) - 1U & *param_2) << (4 - uVar4 & 0x1f));
      }
      else {
        bVar5 = (byte)((*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x1c);
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 5) {
          FUN_40bc10b4(param_2,4);
        }
        else {
          param_2[2] = uVar4 - 4;
        }
      }
      param_1[uVar1 + 0x80] = bVar5;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < (byte)param_1[7]);
  }
  if (param_1[8] != '\0') {
    uVar1 = 0;
    do {
      uVar4 = param_2[2];
      if (uVar4 == 0) {
        bVar5 = (byte)(param_2[1] >> 0x18);
      }
      else {
        bVar5 = (byte)((*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x18);
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 2) {
          FUN_40bc10b4(param_2,1);
        }
        else {
          param_2[2] = uVar4 - 1;
        }
      }
      param_1[uVar1 + 0x90] = bVar5 >> 7;
      uVar4 = param_2[2];
      if (uVar4 < 4) {
        bVar5 = (byte)(param_2[1] >> (0x20 - (4 - uVar4) & 0x1f)) |
                (byte)(((1 << (uVar4 & 0x1f)) - 1U & *param_2) << (4 - uVar4 & 0x1f));
      }
      else {
        bVar5 = (byte)((*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x1c);
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 5) {
          FUN_40bc10b4(param_2,4);
        }
        else {
          param_2[2] = uVar4 - 4;
        }
      }
      param_1[uVar1 + 0xa0] = bVar5;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < (byte)param_1[8]);
  }
  uVar1 = param_2[2];
  if (((-uVar1 & 7) != 0) && (uVar4 = 8 - (-uVar1 & 7), (char)param_2[5] == '\0')) {
    if (uVar4 < uVar1) {
      param_2[2] = uVar1 - uVar4;
    }
    else {
      FUN_40bc10b4(param_2,uVar4);
    }
  }
  uVar1 = param_2[2];
  if (uVar1 < 8) {
    uVar4 = param_2[1] >> (0x20 - (8 - uVar1) & 0x1f) |
            ((1 << (uVar1 & 0x1f)) - 1U & *param_2) << (8 - uVar1 & 0x1f);
  }
  else {
    uVar4 = (*param_2 << (0x20 - uVar1 & 0x1f)) >> 0x18;
  }
  if ((char)param_2[5] == '\0') {
    if (uVar1 < 9) {
      FUN_40bc10b4(param_2,8);
    }
    else {
      param_2[2] = uVar1 - 8;
    }
  }
  param_1[0xb1] = (char)uVar4;
  uVar1 = 0;
  if ((uVar4 & 0xff) != 0) {
    uVar1 = 0;
    do {
      uVar4 = param_2[2];
      if (uVar4 < 8) {
        bVar5 = (byte)(param_2[1] >> (0x20 - (8 - uVar4) & 0x1f)) |
                (byte)(((1 << (uVar4 & 0x1f)) - 1U & *param_2) << (8 - uVar4 & 0x1f));
      }
      else {
        bVar5 = (byte)((*param_2 << (0x20 - uVar4 & 0x1f)) >> 0x18);
      }
      if ((char)param_2[5] == '\0') {
        if (uVar4 < 9) {
          FUN_40bc10b4(param_2,8);
        }
        else {
          param_2[2] = uVar4 - 8;
        }
      }
      param_1[uVar1 + 0xb2] = bVar5;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < (byte)param_1[0xb1]);
  }
  param_1[uVar1 + 0xb2] = 0;
  uVar2 = 0x16;
  if ((byte)param_1[0xb0] < 7) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bc20c0 FUN_40bc20c0 */

/* Boundary evidence: original MIPS .pdata 40bc20c0..40bc2493. Semantic name remains unreviewed. */

void FUN_40bc20c0(uint *param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  undefined1 auStack_288 [2];
  byte local_286;
  byte local_1d8;
  byte local_b0 [128];
  uint local_30;
  
  local_30 = DAT_40be0550;
  *param_2 = 0;
  uVar1 = FUN_40bc1000(param_1,1);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if (uVar1 != 0) {
    uVar1 = 0;
    do {
      uVar2 = uVar1;
      uVar1 = param_1[2];
      if (uVar1 < 8) {
        bVar5 = (byte)(param_1[1] >> (0x20 - (8 - uVar1) & 0x1f)) |
                (byte)(((1 << (uVar1 & 0x1f)) - 1U & *param_1) << (8 - uVar1 & 0x1f));
      }
      else {
        bVar5 = (byte)((*param_1 << (0x20 - uVar1 & 0x1f)) >> 0x18);
      }
      if ((char)param_1[5] == '\0') {
        if (uVar1 < 9) {
          FUN_40bc10b4(param_1,8);
        }
        else {
          param_1[2] = uVar1 - 8;
        }
      }
      local_b0[uVar2] = bVar5;
      uVar1 = uVar2 + 1;
    } while (uVar2 + 1 < 9);
    local_b0[uVar2 + 1] = 0;
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  uVar1 = param_1[2];
  if (uVar1 == 0) {
    uVar2 = param_1[1];
  }
  else {
    uVar2 = *param_1 << (0x20 - uVar1 & 0x1f);
  }
  if ((char)param_1[5] == '\0') {
    if (uVar1 < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = uVar1 - 1;
    }
  }
  uVar1 = param_1[2];
  if (uVar1 < 0x17) {
    uVar3 = param_1[1] >> (0x20 - (0x17 - uVar1) & 0x1f) |
            ((1 << (uVar1 & 0x1f)) - 1U & *param_1) << (0x17 - uVar1 & 0x1f);
  }
  else {
    uVar3 = (*param_1 << (0x20 - uVar1 & 0x1f)) >> 9;
  }
  if ((char)param_1[5] == '\0') {
    if (uVar1 < 0x18) {
      FUN_40bc10b4(param_1,0x17);
    }
    else {
      param_1[2] = uVar1 - 0x17;
    }
  }
  *param_4 = uVar3;
  uVar1 = param_1[2];
  if (uVar1 < 4) {
    uVar3 = param_1[1] >> (0x20 - (4 - uVar1) & 0x1f) |
            ((1 << (uVar1 & 0x1f)) - 1U & *param_1) << (4 - uVar1 & 0x1f);
  }
  else {
    uVar3 = (*param_1 << (0x20 - uVar1 & 0x1f)) >> 0x1c;
  }
  if ((char)param_1[5] == '\0') {
    if (uVar1 < 5) {
      FUN_40bc10b4(param_1,4);
    }
    else {
      param_1[2] = uVar1 - 4;
    }
  }
  for (iVar4 = uVar3 + 1; iVar4 != 0; iVar4 = iVar4 + -1) {
    if ((-1 < (int)uVar2) && ((char)param_1[5] == '\0')) {
      if (param_1[2] < 0x15) {
        FUN_40bc10b4(param_1,0x14);
      }
      else {
        param_1[2] = param_1[2] - 0x14;
      }
    }
    if (uVar3 == 0) {
      FUN_40bc1308(auStack_288,param_1);
      *param_3 = (uint)local_286;
      *param_5 = (uint)local_1d8;
    }
  }
  FUN_40bd8bd0(local_30);
  return;
}



/* 40bc2494 FUN_40bc2494 */

/* Boundary evidence: original MIPS .pdata 40bc2494..40bc25af. Semantic name remains unreviewed. */

undefined4 FUN_40bc2494(undefined1 *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint auStack_30 [2];
  uint local_28;
  char local_1c;
  
  local_40 = 0;
  FUN_40bc11f0(auStack_30,param_1,param_3);
  if (local_1c == '\0') {
    if (local_28 < 0x11) {
      FUN_40bc10b4(auStack_30,0x10);
    }
    else {
      local_28 = local_28 - 0x10;
    }
    if (local_1c == '\0') {
      if (local_28 < 0x11) {
        FUN_40bc10b4(auStack_30,0x10);
      }
      else {
        local_28 = local_28 - 0x10;
      }
    }
  }
  puVar3 = &local_3c;
  puVar2 = &local_34;
  puVar1 = &local_40;
  FUN_40bc20c0(auStack_30,puVar1,puVar2,puVar3,&local_38);
  if (param_2 == 0) {
    FUN_40bc3b24(0x40bda020,puVar1,puVar2,(va_list)puVar3);
    return 0;
  }
  *(uint *)(param_2 + 8) = local_3c >> 3;
  *(char *)(param_2 + 2) = (char)(undefined2)local_38;
  *(char *)(param_2 + 3) = (char)((ushort)(undefined2)local_38 >> 8);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(&DAT_40bdf120 + local_34 * 4);
  return 0;
}



/* 40bc25b0 FUN_40bc25b0 */

/* Boundary evidence: original MIPS .pdata 40bc25b0..40bc2c03. Semantic name remains unreviewed. */

undefined4 FUN_40bc25b0(uint *param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  *param_2 = 0;
  uVar1 = FUN_40bc1000(param_1,1);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  *param_4 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 3) {
      FUN_40bc10b4(param_1,2);
    }
    else {
      param_1[2] = param_1[2] - 2;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 3) {
      FUN_40bc10b4(param_1,2);
    }
    else {
      param_1[2] = param_1[2] - 2;
    }
  }
  uVar1 = FUN_40bc1000(param_1,4);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 5) {
      FUN_40bc10b4(param_1,4);
    }
    else {
      param_1[2] = param_1[2] - 4;
    }
  }
  *param_3 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  uVar1 = FUN_40bc1000(param_1,3);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 4) {
      FUN_40bc10b4(param_1,3);
    }
    else {
      param_1[2] = param_1[2] - 3;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  *param_5 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40bc10b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  uVar1 = FUN_40bc1000(param_1,0xd);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 0xe) {
      FUN_40bc10b4(param_1,0xd);
    }
    else {
      param_1[2] = param_1[2] - 0xd;
    }
  }
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else {
    if ((char)param_1[5] == '\0') {
      if (param_1[2] < 0xc) {
        FUN_40bc10b4(param_1,0xb);
      }
      else {
        param_1[2] = param_1[2] - 0xb;
      }
    }
    if ((char)param_1[5] == '\0') {
      if (param_1[2] < 3) {
        FUN_40bc10b4(param_1,2);
      }
      else {
        param_1[2] = param_1[2] - 2;
      }
    }
    uVar1 = FUN_40bc1000(param_1,3);
    if ((char)param_1[5] == '\0') {
      if (param_1[2] < 4) {
        FUN_40bc10b4(param_1,3);
      }
      else {
        param_1[2] = param_1[2] - 3;
      }
    }
    if (uVar1 == 1) {
      FUN_40bc116c(param_1,4);
      uVar1 = FUN_40bc116c(param_1,1);
      if (uVar1 != 0) {
        FUN_40bc116c(param_1,1);
        uVar1 = FUN_40bc116c(param_1,2);
        FUN_40bc116c(param_1,1);
        if (uVar1 == 2) {
          uVar1 = FUN_40bc116c(param_1,4);
          uVar3 = 7;
        }
        else {
          uVar1 = FUN_40bc116c(param_1,6);
          uVar3 = 1;
        }
        FUN_40bc116c(param_1,uVar3);
        uVar3 = FUN_40bc116c(param_1,2);
        if ((uVar3 == 1) && (uVar1 != 0)) {
          uVar3 = 0;
          do {
            if ((char)param_1[5] == '\0') {
              if (param_1[2] < 2) {
                FUN_40bc10b4(param_1,1);
              }
              else {
                param_1[2] = param_1[2] - 1;
              }
            }
            uVar3 = uVar3 + 1 & 0xff;
          } while (uVar3 < uVar1);
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 9) {
            FUN_40bc10b4(param_1,8);
          }
          else {
            param_1[2] = param_1[2] - 8;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 0xd) {
            FUN_40bc10b4(param_1,0xc);
          }
          else {
            param_1[2] = param_1[2] - 0xc;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 9) {
            FUN_40bc10b4(param_1,8);
          }
          else {
            param_1[2] = param_1[2] - 8;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 0xd) {
            FUN_40bc10b4(param_1,0xc);
          }
          else {
            param_1[2] = param_1[2] - 0xc;
          }
        }
        uVar1 = FUN_40bc1000(param_1,3);
        if (uVar1 == 6) {
          if ((char)param_1[5] == '\0') {
            if (param_1[2] < 4) {
              FUN_40bc10b4(param_1,3);
            }
            else {
              param_1[2] = param_1[2] - 3;
            }
          }
          uVar1 = FUN_40bc116c(param_1,4);
          if (uVar1 == 0xf) {
            uVar1 = FUN_40bc116c(param_1,8);
            uVar1 = uVar1 + 0xe;
          }
          if ((uVar1 != 0) && ((uVar1 = FUN_40bc1000(param_1,4), uVar1 == 0xd || (uVar1 == 0xe)))) {
            *param_2 = 1;
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bc2c04 FUN_40bc2c04 */

/* Boundary evidence: original MIPS .pdata 40bc2c04..40bc2ee3. Semantic name remains unreviewed. */

undefined4
FUN_40bc2c04(char *param_1,int param_2,undefined4 *param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *_Memory;
  int iVar7;
  int local_80;
  uint local_7c;
  void *local_78;
  int local_70;
  uint local_6c [3];
  char *local_60;
  undefined4 *local_5c;
  undefined4 auStack_58 [2];
  uint auStack_50 [2];
  uint local_48;
  char local_3c;
  
  local_70 = 0;
  _Memory = (void *)0x0;
  local_7c = 0;
  local_6c[0] = 0;
  iVar3 = 0;
  local_6c[1] = 0;
  local_80 = 0;
  iVar5 = 0;
  iVar7 = 0;
  local_78 = (void *)0x0;
  uVar4 = 0;
  if (-1 < param_5) {
    iVar6 = 0;
    local_60 = param_1;
    local_5c = param_3;
    do {
      if ((*param_1 != -1) || ((param_1[1] & 0xf6U) != 0xf0)) break;
      iVar7 = iVar7 + 1;
      if (uVar4 == 0) {
        FUN_40bc11f0(auStack_50,param_1,param_5 - iVar5);
        if (local_3c == '\0') {
          if (local_48 < 0xd) {
            FUN_40bc10b4(auStack_50,0xc);
          }
          else {
            local_48 = local_48 - 0xc;
          }
        }
        iVar1 = FUN_40bc25b0(auStack_50,auStack_58,local_6c,local_6c + 1,local_6c + 2);
        if (iVar1 != 0) {
          return 0;
        }
        if (local_6c[2] == 0) {
          return 0;
        }
        *(char *)(param_2 + 2) = (char)(local_6c[2] & 0xffff);
        *(char *)(param_2 + 3) = (char)((local_6c[2] & 0xffff) >> 8);
        _Memory = local_78;
      }
      uVar2 = (((byte)param_1[3] & 3) << 8 | (uint)(byte)param_1[4]) << 3 |
              (uint)((byte)param_1[5] >> 5);
      local_7c = uVar2 + local_7c;
      if (iVar3 == 0x2b) {
        iVar3 = 0;
LAB_40bc2d90:
        if (param_4 != (int *)0x0) {
          _Memory = realloc(_Memory,iVar6 + 4);
          *(int *)(iVar6 + (int)_Memory) = local_70 + param_6;
          local_78 = _Memory;
        }
        local_80 = local_80 + 1;
        iVar6 = iVar6 + 4;
      }
      else if (iVar3 == 0) goto LAB_40bc2d90;
      iVar5 = iVar5 + uVar2;
      param_1 = param_1 + uVar2;
      if (param_5 + -0x400 <= iVar5) break;
      local_70 = (int)param_1 - (int)local_60;
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar5 <= param_5);
    if (5 < iVar7) {
      if (param_4 != (int *)0x0) {
        *param_4 = local_80;
        *local_5c = _Memory;
      }
      iVar3 = *(int *)(&DAT_40bdf120 + local_6c[0] * 4);
      *(int *)(param_2 + 4) = iVar3;
      if (uVar4 != 0) {
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        iVar5 = (local_7c / uVar4) * iVar3;
        if (iVar5 < 0) {
          iVar5 = iVar5 + 0x7f;
        }
        iVar3 = iVar5 >> 10;
        if (iVar5 >> 7 < 0) {
          iVar3 = (iVar5 >> 7) + 7 >> 3;
        }
      }
      *(int *)(param_2 + 8) = iVar3;
      return 1;
    }
  }
  return 0;
}



/* 40bc2ee4 FUN_40bc2ee4 */

/* Boundary evidence: original MIPS .pdata 40bc2ee4..40bc314b. Semantic name remains unreviewed. */

undefined4
FUN_40bc2ee4(char *param_1,undefined1 *param_2,undefined4 *param_3,int *param_4,uint param_5,
            int *param_6)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  char local_38 [4];
  char local_34 [4];
  uint local_30;
  
  local_30 = DAT_40be0550;
  memset(param_2,0,0x12);
  *param_6 = 0;
  pcVar6 = "ID3";
  pcVar5 = param_1;
  do {
    cVar1 = *pcVar5;
    cVar2 = *pcVar6;
    if (cVar1 == '\0') break;
    if (cVar1 != cVar2) goto LAB_40bc2fc8;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (pcVar5 != param_1 + 3);
  if (cVar1 == cVar2) {
    uVar7 = (((uint)(byte)param_1[6] << 7 | (uint)(byte)param_1[7]) << 7 | (uint)(byte)param_1[8])
            << 7 | (uint)(byte)param_1[9];
    if ((int)uVar7 <= (int)param_5) {
      param_1 = param_1 + uVar7;
      param_5 = param_5 - uVar7;
      goto LAB_40bc2fc8;
    }
LAB_40bc3114:
    FUN_40bd8bd0(local_30);
    uVar3 = 1;
  }
  else {
LAB_40bc2fc8:
    strncpy_s(local_38,5,param_1,4);
    pcVar5 = local_38;
    local_34[0] = '\0';
    pcVar6 = "ADIF";
    do {
      cVar1 = *pcVar5;
      cVar2 = *pcVar6;
      if (cVar1 == '\0') break;
      if (cVar1 != cVar2) goto LAB_40bc3038;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (pcVar5 != local_34);
    if (cVar1 == cVar2) {
      FUN_40bc2494(param_1,(int)param_2,param_5);
    }
    else {
LAB_40bc3038:
      iVar8 = 0;
      if (0 < (int)(param_5 - 300)) {
        do {
          if ((param_1[iVar8] == -1) && ((param_1[iVar8 + 1] & 0xf6U) == 0xf0)) {
            iVar4 = FUN_40bc2c04(param_1 + iVar8,(int)param_2,param_3,param_4,param_5 - iVar8,iVar8)
            ;
            if (iVar4 != 0) {
              *param_6 = iVar8;
              goto LAB_40bc30d4;
            }
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(param_5 - 300));
      }
      if ((*param_1 != '!') || (param_1[1] != '\f')) goto LAB_40bc3114;
      *(undefined4 *)(param_2 + 4) = 0xac44;
      param_2[2] = 2;
      *(undefined4 *)(param_2 + 8) = 0x31ce;
      param_2[3] = 0;
      *param_2 = 0xff;
      param_2[1] = 0;
    }
LAB_40bc30d4:
    FUN_40bd8bd0(local_30);
    uVar3 = 0;
  }
  return uVar3;
}



/* 40bc314c FUN_40bc314c */

/* Boundary evidence: original MIPS .pdata 40bc314c..40bc3167. Semantic name remains unreviewed. */

void FUN_40bc314c(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  return;
}



/* 40bc3168 FUN_40bc3168 */

/* Boundary evidence: original MIPS .pdata 40bc3168..40bc31cf. Semantic name remains unreviewed. */

undefined4 * FUN_40bc3168(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_40bd507c(param_1,L"CSequential Allocator",param_2,param_3);
  *param_1 = &PTR_FUN_40bda090;
  param_1[3] = &PTR_FUN_40bda064;
  param_1[0x16] = param_1[0x1a];
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  return param_1;
}



/* 40bc31d0 FUN_40bc31d0 */

/* Boundary evidence: original MIPS .pdata 40bc31d0..40bc31f7. Semantic name remains unreviewed. */

void FUN_40bc31d0(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40bc31f8 FUN_40bc31f8 */

/* Boundary evidence: original MIPS .pdata 40bc31f8..40bc321f. Semantic name remains unreviewed. */

void FUN_40bc31f8(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40bc3220 FUN_40bc3220 */

/* Boundary evidence: original MIPS .pdata 40bc3220..40bc3247. Semantic name remains unreviewed. */

void FUN_40bc3220(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40bc3248 FUN_40bc3248 */

/* Boundary evidence: original MIPS .pdata 40bc3248..40bc32b3. Semantic name remains unreviewed. */

void FUN_40bc3248(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40bda090;
  param_1[3] = &PTR_FUN_40bda064;
  if ((void *)param_1[0x17] != (void *)0x0) {
    operator_delete((void *)param_1[0x17]);
  }
  FUN_40bd30ec(param_1);
  return;
}



/* 40bc32b4 FUN_40bc32b4 */

/* Boundary evidence: original MIPS .pdata 40bc32b4..40bc32e3. Semantic name remains unreviewed. */

void FUN_40bc32b4(void)

{
  undefined4 *in_v0;
  
  FUN_40bd30ec((undefined4 *)*in_v0);
  return;
}



/* 40bc32e4 FUN_40bc32e4 */

/* Boundary evidence: original MIPS .pdata 40bc32e4..40bc34a3. Semantic name remains unreviewed. */

undefined4 FUN_40bc32e4(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar3;
  int local_30;
  LPCRITICAL_SECTION local_2c;
  
  *param_2 = 0;
  piVar3 = (int *)0x0;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
    if (param_1 == 0xc) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    local_2c = lpCriticalSection;
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(param_1 + 0x40) == 0) {
      LeaveCriticalSection(lpCriticalSection);
      return 0x80040211;
    }
    for (piVar2 = *(int **)(param_1 + 0x18); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[7]) {
      (**(code **)(*piVar2 + 0xc))(piVar2,&local_30);
      if (local_30 == *(int *)(param_1 + 0x4c)) {
        FUN_40bd2e74((int *)(param_1 + 0x18),(int)piVar2);
        if (*(int *)(param_1 + 0x54) == 0) {
          *(int *)(param_1 + 0x58) = local_30;
        }
        iVar1 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x4c);
        *(int *)(param_1 + 0x4c) = iVar1;
        if (iVar1 == *(int *)(param_1 + 0x28) * *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x5c))
        {
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x5c);
        }
        piVar3 = piVar2;
        if (piVar2 != (int *)0x0) goto LAB_40bc3410;
        break;
      }
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_40bd2c40(param_1 + -0xc);
    }
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    piVar2 = piVar3;
LAB_40bc3410:
    LeaveCriticalSection(lpCriticalSection);
    if (piVar2 != (int *)0x0) {
      (**(code **)*piVar2)(piVar2,&DAT_40bdccf8,param_2);
      return 0;
    }
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x20),0xffffffff);
    piVar3 = piVar2;
  } while( true );
}



/* 40bc34a4 FUN_40bc34a4 */

/* Boundary evidence: original MIPS .pdata 40bc34a4..40bc34d3. Semantic name remains unreviewed. */

void FUN_40bc34a4(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x2c));
  return;
}



/* 40bc34d4 FUN_40bc34d4 */

/* Boundary evidence: original MIPS .pdata 40bc34d4..40bc3543. Semantic name remains unreviewed. */

void FUN_40bc34d4(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
  if (iVar1 != 0) {
    (**(code **)(*param_2 + 4))(param_2);
    iVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
    *(int *)(param_1 + 0x60) = iVar1 + *(int *)(param_1 + 0x60);
  }
  return;
}



/* 40bc3544 FUN_40bc3544 */

undefined4 FUN_40bc3544(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x60);
  return *(undefined4 *)(param_1 + 100);
}



/* 40bc3554 FUN_40bc3554 */

/* Boundary evidence: original MIPS .pdata 40bc3554..40bc3763. Semantic name remains unreviewed. */

int FUN_40bc3554(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_28 [8];
  
  iVar2 = *(int *)(param_1 + 0x60);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x68);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x3c);
    iVar1 = iVar3 + iVar2 + -1;
    iVar4 = iVar1 / iVar3;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    iVar1 = *(int *)(param_1 + 100) - *(int *)(param_1 + 0x68);
    iVar5 = iVar1 / iVar3;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    iVar1 = iVar1 + iVar2;
    iVar2 = iVar1 / iVar3;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar1 % iVar3 == 0) {
      iVar2 = iVar2 + -1;
    }
    iVar1 = 0;
    if (0 < iVar4) {
      do {
        iVar3 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))
                          ((int *)(param_1 + 0xc),auStack_28,0,0,0);
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar4);
    }
    memcpy((void *)((iVar4 * *(int *)(param_1 + 0x3c) - *(size_t *)(param_1 + 0x60)) +
                   *(int *)(param_1 + 0x68)),*(void **)(param_1 + 100),*(size_t *)(param_1 + 0x60));
    *(int *)(param_1 + 100) =
         (iVar4 * *(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x60)) + *(int *)(param_1 + 0x68);
    if (iVar5 <= iVar2) {
      iVar1 = iVar5 << 2;
      iVar2 = (iVar2 - iVar5) + 1;
      do {
        (**(code **)(**(int **)(iVar1 + *(int *)(param_1 + 0x5c)) + 8))();
        iVar2 = iVar2 + -1;
        iVar1 = iVar1 + 4;
      } while (iVar2 != 0);
    }
  }
  return 0;
}



/* 40bc3764 FUN_40bc3764 */

/* Boundary evidence: original MIPS .pdata 40bc3764..40bc37af. Semantic name remains unreviewed. */

undefined4 * FUN_40bc3764(undefined4 *param_1,uint param_2)

{
  FUN_40bc3248(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bc37b0 FUN_40bc37b0 */

/* Boundary evidence: original MIPS .pdata 40bc37b0..40bc395b. Semantic name remains unreviewed. */

int FUN_40bc37b0(int param_1)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  uint local_28;
  LPCRITICAL_SECTION local_24;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x10);
  if (param_1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  local_24 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if (*(void **)(param_1 + 0x5c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x5c));
  }
  uVar3 = *(uint *)(param_1 + 0x34) << 2;
  if (0x3fffffff < *(uint *)(param_1 + 0x34)) {
    uVar3 = 0xffffffff;
  }
  pvVar1 = operator_new(uVar3);
  *(void **)(param_1 + 0x5c) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar2 = -0x7ff8fff2;
  }
  else {
    iVar2 = FUN_40bd50cc(param_1);
    if (iVar2 == 0) {
      piVar6 = *(int **)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
      for (; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[7]) {
        (**(code **)(*piVar6 + 0xc))(piVar6,&local_28);
        if (local_28 < *(uint *)(param_1 + 0x68)) {
          *(uint *)(param_1 + 0x68) = local_28;
        }
      }
      for (piVar6 = *(int **)(param_1 + 0x24); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[7]) {
        (**(code **)(*piVar6 + 0xc))(piVar6,&local_28);
        iVar4 = *(int *)(param_1 + 0x3c);
        iVar5 = local_28 - *(int *)(param_1 + 0x68);
        if (iVar4 == 0) {
          trap(0x1c00);
        }
        if ((iVar4 == -1) && (iVar5 == -0x80000000)) {
          trap(0x1800);
        }
        *(int **)((iVar5 / iVar4) * 4 + *(int *)(param_1 + 0x5c)) = piVar6;
      }
    }
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x68);
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar2;
}



/* 40bc395c FUN_40bc395c */

/* Boundary evidence: original MIPS .pdata 40bc395c..40bc398b. Semantic name remains unreviewed. */

void FUN_40bc395c(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40bc398c FUN_40bc398c */

/* Boundary evidence: original MIPS .pdata 40bc398c..40bc3b07. Semantic name remains unreviewed. */

int FUN_40bc398c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_1 + 0x68);
  iVar3 = *(int *)(param_1 + 0x3c);
  iVar1 = *(int *)(param_1 + 100) - iVar4;
  iVar5 = iVar1 / iVar3;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  iVar6 = (iVar1 + param_2) / iVar3;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar1 + param_2 == -0x80000000)) {
    trap(0x1800);
  }
  iVar2 = *(int *)(param_1 + 0x60) - param_2;
  iVar1 = *(int *)(param_1 + 100) + param_2;
  *(int *)(param_1 + 0x60) = iVar2;
  *(int *)(param_1 + 100) = iVar1;
  if (iVar2 == 0) {
    iVar1 = iVar1 - iVar4;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    if (iVar1 % iVar3 != 0) {
      iVar6 = iVar6 + 1;
      *(int *)(param_1 + 100) = iVar3 * iVar6 + iVar4;
    }
  }
  if (iVar5 != iVar6) {
    iVar1 = iVar5 << 2;
    iVar6 = iVar6 - iVar5;
    do {
      (**(code **)(**(int **)(iVar1 + *(int *)(param_1 + 0x5c)) + 8))();
      iVar6 = iVar6 + -1;
      iVar1 = iVar1 + 4;
    } while (iVar6 != 0);
  }
  if (*(int *)(param_1 + 100) + *(int *)(param_1 + 0x60) ==
      *(int *)(param_1 + 0x34) * *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x68)) {
    iVar1 = FUN_40bc3554(param_1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bc3b08 FUN_40bc3b08 */

/* Boundary evidence: original MIPS .pdata 40bc3b08..40bc3b23. Semantic name remains unreviewed. */

void FUN_40bc3b08(int param_1)

{
  FUN_40bc398c(param_1,*(int *)(param_1 + 0x60));
  return;
}



/* 40bc3b24 FUN_40bc3b24 */

/* Boundary evidence: original MIPS .pdata 40bc3b24..40bc3bef. Semantic name remains unreviewed. */

void FUN_40bc3b24(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  WCHAR WVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  WCHAR *pWVar4;
  WCHAR *pWVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  WCHAR *pWVar8;
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  WCHAR local_410 [256];
  wchar_t local_210 [256];
  uint local_10;
  
  local_10 = DAT_40be0550;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(local_210,param_1,(wchar_t *)&local_res4,param_4);
  pWVar5 = L"PSDEMUX: ";
  pWVar4 = local_410;
  do {
    WVar1 = *pWVar5;
    pWVar5 = pWVar5 + 1;
    *pWVar4 = WVar1;
    pWVar4 = pWVar4 + 1;
  } while (WVar1 != L'\0');
  pwVar7 = local_210;
  pwVar3 = local_410;
  do {
    pwVar6 = pwVar3;
    pwVar3 = pwVar6 + 1;
  } while (*pwVar6 != L'\0');
  do {
    wVar2 = *pwVar7;
    pwVar7 = pwVar7 + 1;
    *pwVar6 = wVar2;
    pwVar6 = pwVar6 + 1;
  } while (wVar2 != L'\0');
  pWVar5 = L"\r\n";
  pWVar4 = local_410;
  do {
    pWVar8 = pWVar4;
    pWVar4 = pWVar8 + 1;
  } while (*pWVar8 != L'\0');
  do {
    WVar1 = *pWVar5;
    pWVar5 = pWVar5 + 1;
    *pWVar8 = WVar1;
    pWVar8 = pWVar8 + 1;
  } while (WVar1 != L'\0');
  OutputDebugStringW(local_410);
  FUN_40bd8bd0(local_10);
  return;
}



/* 40bc3bf0 FUN_40bc3bf0 */

/* Boundary evidence: original MIPS .pdata 40bc3bf0..40bc3c47. Semantic name remains unreviewed. */

void FUN_40bc3bf0(int param_1)

{
  HANDLE hHandle;
  
  hHandle = (HANDLE)InterlockedExchange((LONG *)(param_1 + 0x14),0);
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  return;
}



/* 40bc3c48 FUN_40bc3c48 */

/* Boundary evidence: original MIPS .pdata 40bc3c48..40bc3c97. Semantic name remains unreviewed. */

undefined4 * FUN_40bc3c48(undefined4 *param_1)

{
  FUN_40bd5e3c((int)param_1);
  *param_1 = &PTR_FUN_40bda1bc;
  param_1[0x10] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 1;
  param_1[0x1a] = 2;
  return param_1;
}



/* 40bc3c98 FUN_40bc3c98 */

/* Boundary evidence: original MIPS .pdata 40bc3c98..40bc3d83. Semantic name remains unreviewed. */

void FUN_40bc3c98(int param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  *(int *)(param_1 + 0x4c) = param_4 * 10000000 + (int)((ulonglong)param_3 * 10000000 >> 0x20);
  *(int *)(param_1 + 0x48) = (int)((ulonglong)param_3 * 10000000);
  uVar1 = (uint)((ulonglong)param_5 * 10000000);
  iVar3 = *(int *)(param_1 + 0x5c);
  iVar2 = param_6 * 10000000 + (int)((ulonglong)param_5 * 10000000 >> 0x20);
  *(uint *)(param_1 + 0x50) = uVar1;
  *(int *)(param_1 + 0x54) = iVar2;
  if ((iVar3 <= iVar2) && ((iVar2 != iVar3 || (*(uint *)(param_1 + 0x58) < uVar1)))) {
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x58);
    *(int *)(param_1 + 0x54) = iVar3;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return;
}



/* 40bc3d84 FUN_40bc3d84 */

/* Boundary evidence: original MIPS .pdata 40bc3d84..40bc3e83. Semantic name remains unreviewed. */

int FUN_40bc3d84(LPVOID param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if ((*(int **)((int)param_1 + 0x60) == (int *)0x0) || (*(int *)((int)param_1 + 0x40) == 0)) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7fff0001;
  }
  if (*(int *)((int)param_1 + 0x14) == 0) {
    iVar2 = (**(code **)(**(int **)((int)param_1 + 0x60) + 0x14))();
    if (iVar2 < 0) {
      LeaveCriticalSection(lpCriticalSection);
      return iVar2;
    }
    bVar1 = FUN_40bd5f28(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      LeaveCriticalSection(lpCriticalSection);
      return -0x7fffbffb;
    }
  }
  *(undefined4 *)((int)param_1 + 0x68) = 1;
  iVar2 = FUN_40bd5fdc((int)param_1,1);
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40bc3e84 FUN_40bc3e84 */

/* Boundary evidence: original MIPS .pdata 40bc3e84..40bc3eb3. Semantic name remains unreviewed. */

void FUN_40bc3e84(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bc3eb4 FUN_40bc3eb4 */

/* Boundary evidence: original MIPS .pdata 40bc3eb4..40bc3fa7. Semantic name remains unreviewed. */

int FUN_40bc3eb4(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int **)(param_1 + 0x40) == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7fff0001;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7fff0001;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0x24))();
    if (iVar1 < 0) {
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      *(undefined4 *)(param_1 + 0x68) = 0;
      iVar1 = FUN_40bd5fdc(param_1,0);
      (**(code **)(**(int **)(param_1 + 0x40) + 0x28))();
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar1;
}



/* 40bc3fa8 FUN_40bc3fa8 */

/* Boundary evidence: original MIPS .pdata 40bc3fa8..40bc3fd7. Semantic name remains unreviewed. */

void FUN_40bc3fa8(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bc3fd8 FUN_40bc3fd8 */

/* Boundary evidence: original MIPS .pdata 40bc3fd8..40bc4103. Semantic name remains unreviewed. */

int FUN_40bc3fd8(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int **)(param_1 + 0x40) == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7fff0001;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 1;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0x24))();
    if (iVar1 < 0) {
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      *(undefined4 *)(param_1 + 0x68) = 2;
      FUN_40bd5fdc(param_1,2);
      (**(code **)(**(int **)(param_1 + 0x40) + 0x28))();
      FUN_40bc3bf0(param_1);
      if ((*(int **)(param_1 + 0x60) != (int *)0x0) &&
         (iVar1 = (**(code **)(**(int **)(param_1 + 0x60) + 0x18))(), iVar1 < 0)) {
        FUN_40bc3b24(0x40bda268,iVar1,param_3,param_4);
      }
      LeaveCriticalSection(lpCriticalSection);
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40bc4104 FUN_40bc4104 */

/* Boundary evidence: original MIPS .pdata 40bc4104..40bc4133. Semantic name remains unreviewed. */

void FUN_40bc4104(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bc4134 FUN_40bc4134 */

/* Boundary evidence: original MIPS .pdata 40bc4134..40bc41ef. Semantic name remains unreviewed. */

undefined4
FUN_40bc4134(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            int param_6)

{
  undefined4 uVar1;
  uint local_20;
  int local_1c;
  undefined1 auStack_18 [8];
  
  (**(code **)(*param_2 + 0x14))(param_2,auStack_18,&local_20);
  if ((param_6 <= local_1c) && ((local_1c != param_6 || (param_5 < local_20)))) {
    local_20 = param_5;
    local_1c = param_6;
    (**(code **)(*param_2 + 0x18))(param_2,auStack_18,&local_20);
  }
  uVar1 = (**(code **)(*param_1 + 8))(param_1,param_2);
  (**(code **)(*param_2 + 8))(param_2);
  return uVar1;
}



/* 40bc41f0 FUN_40bc41f0 */

/* Boundary evidence: original MIPS .pdata 40bc41f0..40bc47d7. Semantic name remains unreviewed. */

void FUN_40bc41f0(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  int *local_58;
  uint local_54;
  int local_50;
  undefined4 uStack_4c;
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  undefined1 auStack_38 [8];
  int local_30;
  
  if ((param_1[0x13] < param_1[0x15]) ||
     ((param_1[0x15] == param_1[0x13] && ((uint)param_1[0x12] < (uint)param_1[0x14])))) {
    if (param_1[0x10] == 0) {
      FUN_40bc3b24(0x40bda328,param_2,param_3,param_4);
      return;
    }
    bVar3 = true;
    bVar4 = false;
    (**(code **)(*(int *)param_1[0x18] + 0x10))((int *)param_1[0x18],auStack_38);
    uVar12 = local_30 - 1;
    uVar13 = ~uVar12;
    uVar14 = __ll_div(param_1[0x12],param_1[0x13],10000000,0);
    local_44 = param_1[0x15];
    lVar2 = (ulonglong)((uint)uVar14 & uVar13) * 10000000;
    uVar10 = (uint)lVar2;
    local_48 = param_1[0x14];
    iVar11 = ((uint)((ulonglong)uVar14 >> 0x20) & (int)uVar13 >> 0x1f) * 10000000 +
             (int)((ulonglong)lVar2 >> 0x20);
    iVar7 = param_1[0x17];
    if ((iVar7 <= local_44) && ((local_44 != iVar7 || ((uint)param_1[0x16] < local_48)))) {
      local_48 = param_1[0x16];
      local_44 = iVar7;
    }
    local_54 = uVar10;
    local_50 = iVar11;
    local_40 = uVar10;
    local_3c = iVar11;
    uVar14 = __ll_div(local_48,local_44,10000000,0);
    uVar8 = (uint)uVar14 + uVar12;
    lVar2 = (ulonglong)(uVar8 & uVar13) * 10000000;
    uVar1 = (uint)lVar2;
    iVar7 = ((int)((ulonglong)uVar14 >> 0x20) + ((int)uVar12 >> 0x1f) + (uint)(uVar8 < (uint)uVar14)
            & (int)uVar13 >> 0x1f) * 10000000 + (int)((ulonglong)lVar2 >> 0x20);
    if ((iVar11 <= iVar7) && ((iVar11 != iVar7 || (uVar10 < uVar1)))) {
      do {
        iVar5 = FUN_40bd60a0((int)param_1,&uStack_4c);
        if (iVar5 != 0) {
          return;
        }
        iVar5 = (**(code **)(*(int *)param_1[0x18] + 0x1c))((int *)param_1[0x18],&local_58,0,0,0);
        uVar13 = (**(code **)(*local_58 + 0x10))();
        uVar12 = (uint)((ulonglong)uVar13 * 10000000);
        iVar9 = ((int)uVar13 >> 0x1f) * 10000000 + (int)((ulonglong)uVar13 * 10000000 >> 0x20);
        if (iVar5 < 0) {
          (**(code **)(*param_1 + 0x10))(param_1,iVar5);
          return;
        }
        if (bVar4) {
          local_40 = uVar10;
          local_3c = iVar11;
          if (param_1[0x19] < 0) {
            local_40 = local_48;
            local_3c = local_44;
          }
          iVar11 = -(uint)(local_40 != 0) - local_3c;
          local_48 = 0;
          local_44 = 0;
          if ((iVar11 < iVar9) || ((iVar11 == iVar9 && (-local_40 <= uVar12)))) {
            bVar4 = false;
          }
          else {
            local_48 = uVar12 + local_40;
            local_44 = iVar9 + local_3c + (uint)(local_48 < uVar12);
            bVar4 = true;
          }
          if ((iVar7 <= local_44) && ((local_44 != iVar7 || (uVar1 < local_48)))) {
            local_48 = uVar1;
            local_44 = iVar7;
          }
          (**(code **)(*local_58 + 0x18))(local_58,&local_40,&local_48);
          uVar10 = local_54;
          iVar11 = local_50;
          if (-1 < param_1[0x19]) goto LAB_40bc44a0;
        }
        else {
          iVar5 = param_1[0x19];
          if ((iVar5 < 0) || (5 < iVar5)) {
            if ((iVar5 < 0) && (uVar10 == 0 && iVar11 == 0)) {
              (**(code **)(*local_58 + 8))();
              break;
            }
            if (iVar5 < 0) {
              bVar3 = true;
              local_3c = (iVar11 - iVar9) - (uint)(uVar10 < uVar12);
              local_40 = uVar10 - uVar12;
              local_48 = uVar10;
              local_44 = iVar11;
            }
            else {
              local_48 = uVar12 + uVar10;
              local_44 = iVar9 + iVar11 + (uint)(local_48 < uVar12);
              local_3c = iVar11;
              local_40 = uVar10;
            }
            if ((local_3c < 1) && ((local_3c != 0 || (local_40 == 0)))) {
              local_40 = 0;
              local_3c = 0;
            }
            if ((iVar7 <= local_44) && ((local_44 != iVar7 || (uVar1 < local_48)))) {
              local_48 = uVar1;
              local_44 = iVar7;
            }
            (**(code **)(*local_58 + 0x18))(local_58,&local_40,&local_48);
            if (param_1[0x19] < 1) {
              local_54 = local_40;
              local_50 = local_3c;
              uVar10 = local_40;
              iVar11 = local_3c;
            }
            else {
              local_50 = local_44;
              local_54 = local_48;
              uVar10 = local_48;
              iVar11 = local_44;
            }
          }
          else {
            local_48 = uVar12 + uVar10;
            local_44 = iVar9 + iVar11 + (uint)(local_48 < uVar12);
            if ((iVar7 <= local_44) && ((local_44 != iVar7 || (uVar1 < local_48)))) {
              local_48 = uVar1;
              local_44 = iVar7;
            }
            local_40 = uVar10;
            local_3c = iVar11;
            (**(code **)(*local_58 + 0x18))(local_58,&local_40,&local_48);
LAB_40bc44a0:
            uVar10 = local_48;
            iVar11 = local_44;
          }
        }
        if (bVar3) {
          (**(code **)(*local_58 + 0x40))(local_58,1);
          bVar3 = false;
        }
        iVar5 = (**(code **)(*(int *)param_1[0x10] + 0x18))((int *)param_1[0x10],local_58);
        if (iVar5 < 0) {
          (**(code **)(*local_58 + 8))();
          (**(code **)(*param_1 + 0x10))(param_1,iVar5);
          return;
        }
        iVar5 = FUN_40bc4134(param_1,local_58,local_40,local_3c,local_48,local_44);
        if (iVar5 != 0) {
          if (-1 < iVar5) {
            return;
          }
          (**(code **)(*param_1 + 0x10))(param_1,iVar5);
          return;
        }
        if ((iVar7 <= iVar11) && ((iVar11 != iVar7 || (uVar1 <= uVar10)))) break;
      } while( true );
    }
    pcVar6 = *(code **)(*param_1 + 0xc);
  }
  else {
    pcVar6 = *(code **)(*param_1 + 0xc);
  }
  (*pcVar6)(param_1);
  return;
}



/* 40bc47d8 FUN_40bc47d8 */

/* Boundary evidence: original MIPS .pdata 40bc47d8..40bc4853. Semantic name remains unreviewed. */

void FUN_40bc47d8(int param_1,int param_2,int **param_3,va_list param_4)

{
  int iVar1;
  int *local_10;
  char acStack_c [4];
  
  iVar1 = *(int *)(param_1 + 0x40);
  while( true ) {
    if (iVar1 == 0) {
      FUN_40bc3b24(0x40bda368,param_2,param_3,param_4);
      return;
    }
    param_4 = acStack_c;
    param_3 = &local_10;
    (**(code **)(**(int **)(param_1 + 0x40) + 0x14))(*(int **)(param_1 + 0x40),0);
    if (local_10 == (int *)0x0) break;
    (**(code **)(*local_10 + 8))();
    param_2 = *(int *)(param_1 + 0x40);
    iVar1 = param_2;
  }
  return;
}



/* 40bc4854 FUN_40bc4854 */

/* Boundary evidence: original MIPS .pdata 40bc4854..40bc48f3. Semantic name remains unreviewed. */

undefined4 FUN_40bc4854(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  FUN_40bc3fd8(param_1,param_2,param_3,param_4);
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x40) + 8))();
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int **)(param_1 + 0x60) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x60) + 8))();
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return 0;
}



/* 40bc48f4 FUN_40bc48f4 */

/* Boundary evidence: original MIPS .pdata 40bc48f4..40bc4923. Semantic name remains unreviewed. */

void FUN_40bc48f4(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40bc4924 FUN_40bc4924 */

/* Boundary evidence: original MIPS .pdata 40bc4924..40bc493f. Semantic name remains unreviewed. */

void FUN_40bc4924(LPVOID param_1)

{
  FUN_40bc3d84(param_1);
  return;
}



/* 40bc4940 FUN_40bc4940 */

/* Boundary evidence: original MIPS .pdata 40bc4940..40bc495f. Semantic name remains unreviewed. */

undefined4 FUN_40bc4940(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  FUN_40bc3fd8(param_1,param_2,param_3,param_4);
  return 0;
}



/* 40bc4960 FUN_40bc4960 */

/* Boundary evidence: original MIPS .pdata 40bc4960..40bc49fb. Semantic name remains unreviewed. */

bool FUN_40bc4960(int *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  iVar1 = param_1[0x1a];
  if (iVar1 == 1) {
    (**(code **)(*param_1 + 0x14))(param_1);
    FUN_40bc3eb4((int)param_1);
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar1 == 1;
}



/* 40bc49fc FUN_40bc49fc */

/* Boundary evidence: original MIPS .pdata 40bc49fc..40bc4a2b. Semantic name remains unreviewed. */

void FUN_40bc49fc(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bc4a2c FUN_40bc4a2c */

/* Boundary evidence: original MIPS .pdata 40bc4a2c..40bc4ad7. Semantic name remains unreviewed. */

bool FUN_40bc4a2c(int *param_1,int param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  iVar1 = param_1[0x1a];
  param_1[0x19] = param_2;
  if (iVar1 == 1) {
    (**(code **)(*param_1 + 0x14))(param_1);
    FUN_40bc3eb4((int)param_1);
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar1 == 1;
}



/* 40bc4ad8 FUN_40bc4ad8 */

/* Boundary evidence: original MIPS .pdata 40bc4ad8..40bc4b07. Semantic name remains unreviewed. */

void FUN_40bc4ad8(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bc4b08 FUN_40bc4b08 */

/* Boundary evidence: original MIPS .pdata 40bc4b08..40bc4bdb. Semantic name remains unreviewed. */

undefined4 FUN_40bc4b08(int *param_1,int param_2,int **param_3,va_list param_4)

{
  int iVar1;
  
  do {
    iVar1 = FUN_40bd6068((int)param_1);
    if (iVar1 == 0) {
      param_2 = 0;
      FUN_40bd6104((int)param_1,0);
    }
    else if (iVar1 == 1) {
      param_2 = 0;
      FUN_40bd6104((int)param_1,0);
      FUN_40bc41f0(param_1,param_2,param_3,param_4);
    }
    else if (iVar1 == 2) {
      FUN_40bd6104((int)param_1,0);
      return 0;
    }
    if ((int *)param_1[0x10] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x10] + 0x24))();
      FUN_40bc47d8((int)param_1,param_2,param_3,param_4);
      (**(code **)(*(int *)param_1[0x10] + 0x28))();
    }
  } while( true );
}



/* 40bc4bdc FUN_40bc4bdc */

/* Boundary evidence: original MIPS .pdata 40bc4bdc..40bc4c33. Semantic name remains unreviewed. */

void FUN_40bc4bdc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  *param_1 = &PTR_FUN_40bda1bc;
  FUN_40bc4854((int)param_1,param_2,param_3,param_4);
  FUN_40bd5eb8((int)param_1);
  return;
}



/* 40bc4c34 FUN_40bc4c34 */

/* Boundary evidence: original MIPS .pdata 40bc4c34..40bc4c63. Semantic name remains unreviewed. */

void FUN_40bc4c34(void)

{
  int *in_v0;
  
  FUN_40bd5eb8(*in_v0);
  return;
}



/* 40bc4c64 FUN_40bc4c64 */

/* Boundary evidence: original MIPS .pdata 40bc4c64..40bc4e1f. Semantic name remains unreviewed. */

int FUN_40bc4c64(int param_1,undefined4 *param_2,undefined4 param_3,va_list param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar5;
  int *piVar6;
  uint local_40;
  int local_3c;
  undefined1 auStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  piVar6 = (int *)(param_1 + 0x40);
  if (*piVar6 == 0) {
    iVar5 = (**(code **)*param_2)(param_2,&DAT_40bdce88,piVar6);
    if (-1 < iVar5) {
      local_30 = 3;
      local_2c = 0x20000;
      local_28 = 0x200;
      local_24 = 0;
      if ((int *)*piVar6 != (int *)0x0) {
        param_4 = (va_list)(param_1 + 0x60);
        puVar3 = &local_30;
        iVar5 = (**(code **)(*(int *)*piVar6 + 0xc))();
        if (iVar5 < 0) {
          FUN_40bc4854(param_1,param_3,puVar3,param_4);
          LeaveCriticalSection(lpCriticalSection);
          return iVar5;
        }
      }
      puVar4 = auStack_38;
      puVar2 = &local_40;
      iVar5 = (**(code **)(*(int *)*piVar6 + 0x20))();
      if (iVar5 < 0) {
        FUN_40bc4854(param_1,puVar2,puVar4,param_4);
        LeaveCriticalSection(lpCriticalSection);
        return iVar5;
      }
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0x4c) = 0;
      uVar1 = (undefined4)((ulonglong)local_40 * 10000000);
      iVar5 = local_3c * 10000000 + (int)((ulonglong)local_40 * 10000000 >> 0x20);
      *(undefined4 *)(param_1 + 0x58) = uVar1;
      *(int *)(param_1 + 0x5c) = iVar5;
      *(undefined4 *)(param_1 + 0x50) = uVar1;
      *(int *)(param_1 + 0x54) = iVar5;
    }
    LeaveCriticalSection(lpCriticalSection);
    iVar5 = 0;
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    iVar5 = -0x7ffbfdfc;
  }
  return iVar5;
}



/* 40bc4e20 FUN_40bc4e20 */

/* Boundary evidence: original MIPS .pdata 40bc4e20..40bc4e4f. Semantic name remains unreviewed. */

void FUN_40bc4e20(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x48));
  return;
}



/* 40bc4e50 FUN_40bc4e50 */

/* Boundary evidence: original MIPS .pdata 40bc4e50..40bc4e9b. Semantic name remains unreviewed. */

undefined4 * FUN_40bc4e50(undefined4 *param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  FUN_40bc4bdc(param_1,param_2,param_3,param_4);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bc4e9c FUN_40bc4e9c */

/* Boundary evidence: original MIPS .pdata 40bc4e9c..40bc4fdf. Semantic name remains unreviewed. */

uint FUN_40bc4e9c(int param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  
  if (5 < param_2) {
    iVar3 = (uint)*(byte *)(param_1 + 4) * 0x100 + (uint)*(byte *)(param_1 + 5);
    uVar2 = iVar3 + 6;
    if (uVar2 < 0xc) {
      FUN_40bc3b24(0x40bdaa08,param_2,param_3,param_4);
      return 4;
    }
    if (uVar2 <= param_2) {
      if ((((*(byte *)(param_1 + 6) & 0x80) == 0) || ((*(byte *)(param_1 + 8) & 1) == 0)) ||
         ((*(byte *)(param_1 + 10) & 0x20) == 0)) {
        FUN_40bc3b24(0x40bda940,param_2,param_3,param_4);
        uVar2 = 4;
      }
      else {
        pbVar4 = (byte *)(param_1 + 0xc);
        for (uVar5 = iVar3 - 6; 2 < uVar5; uVar5 = uVar5 - 3) {
          bVar1 = *pbVar4;
          if (((bVar1 != 0xb8) && (bVar1 != 0xb9)) && (bVar1 < 0xbc)) {
            FUN_40bc3b24(0x40bda984,param_2,param_3,param_4);
            return 4;
          }
          pbVar4 = pbVar4 + 3;
        }
        if (uVar5 != 0) {
          FUN_40bc3b24(0x40bda9cc,param_2,param_3,param_4);
          return 4;
        }
      }
      return uVar2;
    }
  }
  return 0;
}



/* 40bc4fe0 FUN_40bc4fe0 */

/* Boundary evidence: original MIPS .pdata 40bc4fe0..40bc5247. Semantic name remains unreviewed. */

undefined4 FUN_40bc4fe0(void *param_1,undefined4 param_2,int param_3,va_list param_4)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  size_t _Size;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if ((*(byte *)((int)param_1 + 10) & 0x20) == 0) {
    pwVar1 = L"Sequence header invalid marker bit";
  }
  else {
    uVar6 = ((uint)*(byte *)((int)param_1 + 4) * 0x100 + (uint)*(byte *)((int)param_1 + 5)) * 0x100
            + (uint)*(byte *)((int)param_1 + 6);
    uVar7 = uVar6 >> 0xc;
    uVar6 = uVar6 & 0xfff;
    *(uint *)(param_3 + 8) = uVar7;
    *(uint *)(param_3 + 0xc) = uVar6;
    uVar3 = (uint)*(byte *)((int)param_1 + 7);
    if (8 < (uVar3 & 0xf)) {
      uVar3 = uVar3 & 0xf7;
    }
    if (((uVar3 & 0xf0) != 0) && ((uVar3 & 0xf) != 0)) {
      iVar5 = (uVar3 & 0xf) * 4;
      *(uint *)(param_3 + 0x18) = uVar3 >> 4;
      *(uint *)(param_3 + 0x14) = uVar6;
      *(uint *)(param_3 + 0x10) = uVar7;
      iVar4 = *(int *)(&DAT_40bda83c + iVar5);
      *(int *)(param_3 + 0x24) = iVar4 >> 0x1f;
      *(int *)(param_3 + 0x20) = iVar4;
      *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(&DAT_40bda87c + iVar5);
      iVar4 = MulDiv(*(int *)(param_3 + 0x20),9,1000);
      *(int *)(param_3 + 0x2c) = iVar4;
      uVar6 = ((uint)*(byte *)((int)param_1 + 8) * 0x100 + (uint)*(byte *)((int)param_1 + 9)) *
              0x100 + (uint)*(byte *)((int)param_1 + 10) >> 6;
      *(uint *)(param_3 + 0x30) = uVar6;
      if (uVar6 == 0x3ffff) {
        *(undefined4 *)(param_3 + 0x30) = 0;
      }
      else {
        *(uint *)(param_3 + 0x30) = uVar6 * 400;
      }
      *(undefined4 *)(param_3 + 0x34) = 2000;
      uVar2 = 10000;
      iVar4 = MulDiv(2000,*(int *)(&DAT_40bda8a0 + (uVar3 >> 4) * 4),10000);
      *(int *)(param_3 + 0x38) = iVar4;
      uVar3 = ((*(byte *)((int)param_1 + 10) & 0x1f) << 5 |
              (uint)(*(byte *)((int)param_1 + 0xb) >> 3)) << 0xb;
      *(uint *)(param_3 + 0x1c) = uVar3;
      if (((*(byte *)((int)param_1 + 0xb) & 4) != 0) && (0xa000 < uVar3)) {
        FUN_40bc3b24(0x40bdaad0,uVar3,uVar2,param_4);
        *(undefined4 *)(param_3 + 0x1c) = 0xa000;
      }
      if (*(int *)(param_3 + 0x1c) < 20000) {
        FUN_40bc3b24(0x40bdaa8c,*(int *)(param_3 + 0x1c),uVar2,param_4);
        *(undefined4 *)(param_3 + 0x1c) = 0xa000;
      }
      if ((*(byte *)((int)param_1 + 0xb) & 3) == 0) {
        _Size = 0xc;
      }
      else if (((*(byte *)((int)param_1 + 0xb) & 3) == 1) ||
              (_Size = 0x8c, (*(byte *)((int)param_1 + 0x4b) & 1) == 0)) {
        _Size = 0x4c;
      }
      *(size_t *)(param_3 + 0x40) = _Size;
      if (_Size != 0) {
        memcpy((void *)(param_3 + 0x44),param_1,_Size);
      }
      return 1;
    }
    pwVar1 = L"Sequence header invalid ratio/rate";
  }
  FUN_40bc3b24((size_t)pwVar1,param_2,param_3,param_4);
  return 0;
}



/* 40bc5248 FUN_40bc5248 */

undefined4 FUN_40bc5248(byte *param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)param_1[1] * 0x100 + (uint)param_1[2];
  bVar1 = *param_1;
  uVar2 = (uint)param_1[3] * 0x100 + (uint)param_1[4];
  if ((((bVar1 & 0xe0) == 0x20) && ((uVar3 & 1) == 1)) && ((uVar2 & 1) == 1)) {
    param_2[1] = (uint)((bVar1 & 8) != 0);
    *param_2 = ((bVar1 & 0xfffe) * 0x8000 + (uVar3 & 0xfffe)) * 0x4000 + (uVar2 >> 1);
    return 1;
  }
  return 0;
}



/* 40bc52e8 FUN_40bc52e8 */

bool FUN_40bc52e8(int *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  for (puVar1 = (uint *)*param_1; (4 < uVar2 && ((*puVar1 & 0xffffff) != 0x10000));
      puVar1 = (uint *)((int)puVar1 + 1)) {
    uVar2 = uVar2 - 1;
  }
  *param_1 = (int)puVar1;
  *param_2 = uVar2;
  return 3 < uVar2;
}



/* 40bc5348 FUN_40bc5348 */

/* Boundary evidence: original MIPS .pdata 40bc5348..40bc559f. Semantic name remains unreviewed. */

undefined4 FUN_40bc5348(char *param_1,int param_2,undefined4 param_3,va_list param_4)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint local_18;
  
  if ((*param_1 == 'w') && (param_1[1] == '\v')) {
    *(undefined1 *)(param_2 + 0x12) = 1;
    bVar4 = param_1[5];
    bVar1 = true;
  }
  else {
    if ((*param_1 != '\v') || (param_1[1] != 'w')) {
      return 0;
    }
    *(undefined1 *)(param_2 + 0x12) = 0;
    bVar4 = param_1[4];
    bVar1 = false;
  }
  uVar6 = bVar4 & 0x3f;
  bVar4 = bVar4 >> 6;
  if (0x25 < uVar6) {
    uVar6 = 0x25;
  }
  if (bVar4 == 0) {
    uVar3 = 48000;
LAB_40bc53fc:
    *(undefined4 *)(param_2 + 4) = uVar3;
  }
  else if (bVar4 == 1) {
    *(undefined4 *)(param_2 + 4) = 0xac44;
  }
  else if (bVar4 == 2) {
    uVar3 = 32000;
    goto LAB_40bc53fc;
  }
  if (bVar1) {
    bVar4 = param_1[7];
  }
  else {
    bVar4 = param_1[6];
  }
  bVar2 = bVar4 >> 5;
  iVar5 = 0;
  switch(bVar2) {
  case 0:
  case 2:
    local_18 = 2;
    break;
  case 1:
    local_18 = 1;
    break;
  case 3:
  case 4:
    local_18 = 3;
    break;
  case 5:
  case 6:
    local_18 = 4;
    break;
  case 7:
    local_18 = 5;
  }
  if (((bVar2 & 1) != 0) && (bVar2 != 1)) {
    iVar5 = 2;
  }
  if ((bVar2 & 4) != 0) {
    iVar5 = iVar5 + 2;
  }
  if (bVar2 == 2) {
    iVar5 = iVar5 + 2;
  }
  switch(iVar5) {
  case 0:
    bVar4 = bVar4 >> 4 & 1;
    break;
  case 2:
    bVar4 = bVar4 >> 2;
    goto LAB_40bc5514;
  case 4:
    bVar4 = bVar4 & 1;
    break;
  case 6:
    if (bVar1) {
      bVar4 = param_1[6];
    }
    else {
      bVar4 = param_1[7];
    }
    bVar4 = bVar4 >> 6;
LAB_40bc5514:
    bVar4 = bVar4 & 1;
    break;
  default:
    FUN_40bc3b24(0x40bdab68,param_2,param_3,param_4);
    goto LAB_40bc5534;
  }
  if (bVar4 != 0) {
    local_18 = local_18 + 1;
  }
LAB_40bc5534:
  iVar5 = *(int *)(uVar6 * 4 + 0x40bdf318) * 1000;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 7;
  }
  *(char *)(param_2 + 2) = (char)(local_18 & 0xffff);
  *(int *)(param_2 + 8) = iVar5 >> 3;
  *(char *)(param_2 + 3) = (char)((local_18 & 0xffff) >> 8);
  return 1;
}



/* 40bc55a0 FUN_40bc55a0 */

undefined4 FUN_40bc55a0(char *param_1,undefined1 *param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (*param_1 != -0x60) {
    return 0;
  }
  param_2[2] = (param_1[5] & 7U) + 1;
  param_2[3] = 0;
  bVar1 = (byte)param_1[5] >> 4 & 3;
  piVar3 = (int *)(param_2 + 4);
  if (bVar1 == 1) {
    iVar2 = 96000;
  }
  else {
    if (bVar1 == 2) {
      *piVar3 = 0xac44;
      goto LAB_40bc5630;
    }
    if (bVar1 != 3) {
      *piVar3 = 48000;
      goto LAB_40bc5630;
    }
    iVar2 = 32000;
  }
  *piVar3 = iVar2;
LAB_40bc5630:
  if ((8 < *(ushort *)(param_2 + 2)) || (*(ushort *)(param_2 + 2) == 0)) {
    param_2[2] = 2;
    param_2[3] = 0;
  }
  piVar4 = &DAT_40bdf510;
  do {
    iVar2 = *piVar3;
    if (*piVar4 == *piVar3) break;
    piVar4 = piVar4 + 1;
    iVar2 = 0xac44;
  } while ((int)piVar4 < 0x40bdf538);
  param_2[0xe] = 0x10;
  *param_2 = 0xa6;
  *piVar3 = iVar2;
  param_2[0xf] = 0;
  param_2[1] = 0xa5;
  return 1;
}



/* 40bc56e8 FUN_40bc56e8 */

/* Boundary evidence: original MIPS .pdata 40bc56e8..40bc5947. Semantic name remains unreviewed. */

undefined4 FUN_40bc56e8(undefined1 *param_1,undefined1 *param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uVar10;
  
  bVar2 = param_1[1];
  uVar4 = CONCAT11(*param_1,bVar2);
  bVar3 = param_1[2];
  uVar5 = 0;
  uVar7 = 0;
  uVar10 = 1;
  if ((((((uVar4 & 0xffe0) != 0xffe0) || ((bVar2 & 0x18) == 8)) || ((bVar2 & 6) == 0)) ||
      ((bVar3 >> 4 == 0xf || ((bVar3 & 0xc) == 0xc)))) ||
     (((bVar2 & 0x18) == 8 || (uVar6 = 4 - (uVar4 >> 1 & 3), uVar6 == 4)))) {
    return 0;
  }
  uVar9 = (uint3)(CONCAT21(uVar4,bVar3) >> 4) & 0xf;
  if (uVar9 == 0xf) {
    return 0;
  }
  uVar8 = (uint3)(CONCAT21(uVar4,bVar3) >> 2) & 3;
  if (uVar8 == 3) {
    return 0;
  }
  if (bVar3 >> 4 != 0) {
    bVar1 = (bVar2 & 0x10) == 0;
    if (bVar1) {
      uVar5 = 1;
    }
    else {
      uVar5 = (uint)((bVar2 & 8) == 0);
    }
    uVar7 = (uint)(*(ushort *)(&DAT_40bda780 + uVar8 * 2) >> bVar1 + uVar5);
    uVar5 = (uint)*(ushort *)(&DAT_40bda788 + ((uVar5 * 3 + uVar6) * 0xf + uVar9 + -0xf) * 2) * 1000
    ;
    if ((byte)param_1[3] >> 6 == 3) goto LAB_40bc5894;
  }
  uVar10 = 2;
LAB_40bc5894:
  param_2[3] = 0;
  uVar5 = uVar5 >> 3;
  param_2[0xe] = 0x10;
  param_2[2] = uVar10;
  *(uint *)(param_2 + 4) = uVar7;
  param_2[0xf] = 0;
  *(uint *)(param_2 + 8) = uVar5;
  if ((uVar5 != 0) && (uVar5 < 0x1312d0)) {
    if (uVar6 < 3) {
      *param_2 = 0x50;
      param_2[1] = 0;
      return 1;
    }
    if (uVar6 == 3) {
      *param_2 = 0x55;
      param_2[1] = 0;
      return 1;
    }
  }
  *(undefined4 *)(param_2 + 8) = 0;
  return 1;
}



/* 40bc5948 FUN_40bc5948 */

/* Boundary evidence: original MIPS .pdata 40bc5948..40bc5daf. Semantic name remains unreviewed. */

undefined4 FUN_40bc5948(byte *param_1,uint param_2,uint *param_3,undefined1 *param_4)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  *param_3 = 0;
  uVar5 = 0;
  uVar7 = 0;
  uVar12 = 0;
  uVar16 = 0;
  uVar14 = 0;
  uVar15 = 0;
  uVar8 = 0;
  if (0x3ff < param_2) {
    uVar13 = 2;
joined_r0x40bc59d0:
    do {
      if (0x1ff < param_2) {
        bVar2 = param_1[1];
        uVar4 = CONCAT11(*param_1,bVar2);
        bVar3 = param_1[2];
        uVar12 = CONCAT31(CONCAT21(uVar4,bVar3),param_1[3]);
        if (((((uVar4 & 0xffe0) != 0xffe0) || (uVar16 = 4 - (uVar4 >> 1 & 3), (bVar2 & 0x18) == 8))
            || (uVar16 == 4)) || ((bVar3 >> 4 == 0xf || ((bVar3 & 0xc) == 0xc)))) {
          param_2 = param_2 - 1;
          param_1 = param_1 + 1;
          goto joined_r0x40bc59d0;
        }
      }
      if ((((uVar12 & 0xffe00000) != 0xffe00000) || ((uVar12 >> 0x13 & 3) == 1)) ||
         ((uVar16 = 4 - (uVar12 >> 0x11 & 3), uVar16 == 4 ||
          ((uVar6 = uVar12 >> 0xc & 0xf, uVar6 == 0xf || (uVar9 = uVar12 >> 10 & 3, uVar9 == 3))))))
      goto LAB_40bc5c60;
      if (uVar6 == 0) {
        param_1 = param_1 + 1;
        param_2 = param_2 - 1;
LAB_40bc5d18:
        *param_3 = 0;
      }
      else {
        bVar1 = (uVar12 & 0x100000) == 0;
        if (bVar1) {
          uVar10 = 1;
        }
        else {
          uVar10 = (uint)((uVar12 & 0x80000) == 0);
        }
        uVar8 = (uint)(*(ushort *)(&DAT_40bda780 + uVar9 * 2) >> bVar1 + uVar10);
        uVar11 = (uint)*(ushort *)(&DAT_40bda788 + ((uVar10 * 3 + uVar16) * 0xf + uVar6 + -0xf) * 2)
        ;
        uVar9 = uVar12 >> 9 & 1;
        uVar14 = uVar12 >> 6 & 3;
        uVar15 = uVar11 * 1000 + uVar15;
        if (uVar6 != 0) {
          if (uVar16 == 1) {
            if (uVar8 == 0) {
              trap(0x1c00);
            }
            uVar7 = ((uVar11 * 12000) / uVar8 + uVar9) * 4;
          }
          else if (uVar16 == 2) {
            if (uVar8 == 0) {
              trap(0x1c00);
            }
            uVar7 = (uVar11 * 0x23280) / uVar8 + uVar9;
          }
          else {
            if (uVar8 << uVar10 == 0) {
              trap(0x1c00);
            }
            uVar7 = (uVar11 * 0x23280) / (uVar8 << uVar10) + uVar9;
          }
        }
        uVar6 = *param_3 + 1;
        *param_3 = uVar6;
        uVar5 = 1;
        if (10000 < (int)uVar6) goto LAB_40bc5c60;
        if (uVar7 < param_2) {
          param_1 = param_1 + uVar7;
          uVar12 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
          param_2 = param_2 - uVar7;
          if ((CONCAT11(*param_1,param_1[1]) & 0xffe0) != 0xffe0) {
            if ((int)uVar6 < 0x10) goto LAB_40bc5d18;
            goto LAB_40bc5c60;
          }
        }
        else {
          if (0xf < (int)uVar6) goto LAB_40bc5c60;
          param_1 = param_1 + 1;
          param_2 = param_2 - 1;
        }
      }
      if (param_2 < 0x400) goto LAB_40bc5c60;
    } while( true );
  }
LAB_40bc5d64:
  if (param_4[2] == '\0' && param_4[3] == '\0') {
    uVar5 = 0;
  }
  return uVar5;
LAB_40bc5c60:
  if (*param_3 != 0) {
    if (uVar14 == 3) {
      uVar13 = 1;
    }
    param_4[0xe] = 0x10;
    param_4[2] = uVar13;
    param_4[3] = 0;
    *(uint *)(param_4 + 4) = uVar8;
    param_4[0xf] = 0;
    uVar12 = (uVar15 >> 3) / *param_3;
    if (*param_3 == 0) {
      trap(0x1c00);
    }
    *(uint *)(param_4 + 8) = uVar12;
    if ((uVar12 != 0) && (uVar12 < 0x15f91)) {
      if (uVar16 < 3) {
        *param_4 = 0x50;
        param_4[1] = 0;
        uVar5 = 1;
        goto LAB_40bc5d64;
      }
      if (uVar16 == 3) {
        *param_4 = 0x55;
        param_4[1] = 0;
        uVar5 = 1;
        goto LAB_40bc5d64;
      }
    }
    uVar5 = 0;
    *(undefined4 *)(param_4 + 8) = 0;
  }
  goto LAB_40bc5d64;
}



/* 40bc5db0 FUN_40bc5db0 */

/* Boundary evidence: original MIPS .pdata 40bc5db0..40bc5e8b. Semantic name remains unreviewed. */

undefined4 FUN_40bc5db0(char *param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  int local_18 [4];
  
  if ((3 < param_2) &&
     ((((param_1[4] != 'f' || (param_1[5] != 't')) || (param_1[6] != 'y')) || (param_1[7] != 'p'))))
  {
    local_18[1] = 0;
    local_18[0] = 0;
    iVar1 = FUN_40bc2ee4(param_1,param_3,local_18 + 1,local_18,param_2,local_18 + 2);
    if (iVar1 == 0) {
      if (2 < *(ushort *)(param_3 + 2)) {
        param_3[2] = 2;
        param_3[3] = 0;
      }
      return 1;
    }
  }
  return 0;
}



/* 40bc5e8c FUN_40bc5e8c */

/* Boundary evidence: original MIPS .pdata 40bc5e8c..40bc601f. Semantic name remains unreviewed. */

uint FUN_40bc5e8c(undefined1 *param_1,uint param_2,uint *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  
  memset(param_3,0,0x18);
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  if ((param_2 < 6) ||
     (uVar5 = (uint)(byte)param_1[4] * 0x100 + (uint)(byte)param_1[5] + 6, param_2 < uVar5)) {
    uVar5 = 0;
  }
  else {
    param_3[1] = uVar5;
    uVar9 = 6;
    if (CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4) == 0xbf) {
LAB_40bc5fa0:
      *param_3 = uVar9;
    }
    else {
      if (6 < uVar5) {
        do {
          bVar8 = param_1[uVar9];
          if ((bVar8 & 0x80) == 0) {
            if ((bVar8 & 0x40) == 0) {
              pbVar7 = param_1 + uVar9;
              bVar8 = *pbVar7;
              if (bVar8 == 0xf) {
                uVar9 = uVar9 + 1;
                goto LAB_40bc5fa0;
              }
              bVar8 = bVar8 & 0xf0;
              if (bVar8 == 0x20) {
                uVar9 = uVar9 + 5;
              }
              else {
                if (bVar8 != 0x30) break;
                uVar9 = uVar9 + 10;
              }
              if ((uVar9 <= uVar5) &&
                 (iVar6 = FUN_40bc5248(pbVar7,(int *)(param_3 + 4)), iVar6 != 0)) {
                param_3[2] = 1;
                goto LAB_40bc5fa0;
              }
              break;
            }
            uVar9 = uVar9 + 2;
          }
          else {
            if (bVar8 != 0xff) break;
            uVar9 = uVar9 + 1;
          }
        } while (uVar9 < uVar5);
      }
      uVar5 = 4;
    }
  }
  return uVar5;
}



/* 40bc6020 FUN_40bc6020 */

/* Boundary evidence: original MIPS .pdata 40bc6020..40bc60f7. Semantic name remains unreviewed. */

undefined4 FUN_40bc6020(int param_1,uint param_2,int *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  
  if (param_2 < 9) {
    uVar2 = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 8);
    param_3[1] = param_2;
    *param_3 = bVar1 + 9;
    if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
      param_3[2] = 0;
      param_3[4] = 0;
      param_3[5] = 0;
    }
    else {
      param_3[2] = 1;
      iVar3 = FUN_40bc5248((byte *)(param_1 + 9),&local_18);
      if (iVar3 == 0) {
        param_3[4] = -1;
        param_3[5] = -1;
      }
      else {
        param_3[4] = local_18;
        param_3[5] = local_14;
      }
    }
    if ((*(byte *)(param_1 + 6) & 0x30) == 0x30) {
      param_3[3] = 1;
    }
    else {
      param_3[3] = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 40bc60f8 FUN_40bc60f8 */

/* Boundary evidence: original MIPS .pdata 40bc60f8..40bc61c3. Semantic name remains unreviewed. */

int FUN_40bc60f8(int param_1,undefined4 param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int local_18;
  int local_14;
  
  bVar1 = *(byte *)(param_1 + 4);
  bVar2 = *(byte *)(param_1 + 5);
  memset(param_3,0,0x18);
  *param_3 = *(byte *)(param_1 + 8) + 9;
  if ((*(byte *)(param_1 + 7) & 0x80) == 0) {
    param_3[2] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
  }
  else {
    param_3[2] = 1;
    iVar3 = FUN_40bc5248((byte *)(param_1 + 9),&local_18);
    if (iVar3 == 0) {
      param_3[4] = -1;
      param_3[5] = -1;
    }
    else {
      param_3[4] = local_18;
      param_3[5] = local_14;
    }
  }
  return (uint)bVar1 * 0x100 + (uint)bVar2 + 6;
}



/* 40bc61c4 FUN_40bc61c4 */

/* Boundary evidence: original MIPS .pdata 40bc61c4..40bc6303. Semantic name remains unreviewed. */

uint FUN_40bc61c4(int param_1,uint param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  memset(param_3,0,0x18);
  if (param_2 < 6) {
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 4);
  bVar2 = *(byte *)(param_1 + 5);
  param_3[2] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  bVar3 = *(byte *)(param_1 + 3);
  uVar6 = (uint)bVar1 * 0x100 + (uint)bVar2 + 6;
  if (bVar3 < 0xf3) {
    if (((0xef < bVar3) || (bVar3 == 0xbc)) || ((0xbd < bVar3 && (bVar3 < 0xc0)))) {
LAB_40bc626c:
      *param_3 = 6;
      param_3[1] = uVar6;
      goto LAB_40bc6278;
    }
  }
  else if ((bVar3 == 0xf8) || (bVar3 == 0xff)) goto LAB_40bc626c;
  if (param_2 < 9) {
    param_3[1] = 0;
  }
  else {
    uVar5 = *(byte *)(param_1 + 8) + 9;
    *param_3 = uVar5;
    if ((uVar5 <= param_2) && (iVar4 = FUN_40bc6020(param_1,uVar6,(int *)param_3), iVar4 == 0)) {
      return 4;
    }
  }
LAB_40bc6278:
  uVar5 = 0;
  if (uVar6 <= param_2) {
    uVar5 = uVar6;
  }
  return uVar5;
}



/* 40bc6304 FUN_40bc6304 */

/* Boundary evidence: original MIPS .pdata 40bc6304..40bc63a7. Semantic name remains unreviewed. */

int * FUN_40bc6304(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80040216;
  }
  else {
    *param_1 = (int)param_2;
    (**(code **)(*param_2 + 4))(param_2);
    uVar1 = (**(code **)(*(int *)*param_1 + 0x20))((int *)*param_1,param_1 + 2,param_1 + 4);
  }
  *param_3 = uVar1;
  return param_1;
}



/* 40bc63a8 FUN_40bc63a8 */

/* Boundary evidence: original MIPS .pdata 40bc63a8..40bc63ef. Semantic name remains unreviewed. */

void FUN_40bc63a8(int *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
    *param_1 = 0;
  }
  FUN_40bd0e7c();
  return;
}



/* 40bc63f0 FUN_40bc63f0 */

/* Boundary evidence: original MIPS .pdata 40bc63f0..40bc661f. Semantic name remains unreviewed. */

uint FUN_40bc63f0(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_24;
  
  local_30 = param_1[2];
  local_2c = param_1[3];
  local_38 = param_1[4];
  local_34 = param_1[5];
  uVar4 = param_1[6];
  iVar6 = param_1[7];
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    iVar2 = (**(code **)(*(int *)*param_1 + 0x20))((int *)*param_1,&local_30,&local_38);
    if (-1 < iVar2) {
      bVar1 = local_30 < uVar4;
      local_30 = local_30 - uVar4;
      local_2c = (local_2c - iVar6) - (uint)bVar1;
      bVar1 = local_38 < uVar4;
      local_38 = local_38 - uVar4;
      local_34 = (local_34 - iVar6) - (uint)bVar1;
      if (((0 < local_2c) || ((uVar4 = local_30, local_2c == 0 && (param_3 <= local_30)))) &&
         ((uVar4 = param_3, local_34 < 1 &&
          (((local_34 != 0 || (local_38 < param_3)) &&
           ((0 < local_34 || ((uVar4 = 0x20000, local_34 == 0 && (0x1ffff < local_38)))))))))) {
        uVar4 = local_38;
      }
      pvVar3 = operator_new(uVar4);
      if (pvVar3 != (void *)0x0) {
        uVar7 = 0;
        while( true ) {
          if ((local_34 < 1) && ((local_34 != 0 || (local_38 < uVar4)))) {
            local_24 = local_34;
            uVar5 = local_38;
          }
          else {
            local_24 = 0;
            uVar5 = uVar4;
          }
          iVar6 = (**(code **)(*(int *)*param_1 + 0x1c))();
          if (iVar6 != 0) break;
          iVar6 = param_1[6];
          uVar7 = uVar5 + uVar7;
          param_1[6] = uVar5 + iVar6;
          param_1[7] = param_1[7] + (uint)(uVar5 + iVar6 < uVar5);
          if (uVar4 <= uVar7) {
LAB_40bc65b8:
            *param_2 = pvVar3;
            return uVar7;
          }
        }
        if ((-1 < local_34) && ((local_34 != 0 || (uVar7 < local_38)))) {
          operator_delete(pvVar3);
          return 0;
        }
        goto LAB_40bc65b8;
      }
    }
  }
  return 0;
}



/* 40bc6620 FUN_40bc6620 */

/* Boundary evidence: original MIPS .pdata 40bc6620..40bc67ef. Semantic name remains unreviewed. */

undefined4 FUN_40bc6620(undefined4 param_1,undefined1 *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint auStack_40 [6];
  
  iVar3 = 0;
  while( true ) {
    if (param_3 < 5) {
      return 0;
    }
    if ((CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]) == 0x1ba) &&
       ((param_2[4] & 0xc0) == 0x40)) break;
LAB_40bc67a4:
    param_3 = param_3 - 1;
    param_2 = param_2 + 1;
  }
joined_r0x40bc66c4:
  do {
    if (param_3 < 5) goto LAB_40bc67a4;
    bVar1 = param_2[3];
    uVar2 = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),bVar1);
    if ((0x1bb < uVar2) && (uVar2 < 0x200)) {
      uVar2 = FUN_40bc61c4((int)param_2,param_3,auStack_40);
      if (4 < uVar2) {
        if ((bVar1 & 0xf0) == 0xe0) {
          iVar3 = iVar3 + 1;
        }
        if (10 < iVar3) {
          return 1;
        }
        param_3 = param_3 - uVar2;
        param_2 = param_2 + uVar2;
        goto joined_r0x40bc66c4;
      }
      if (uVar2 == 0) goto LAB_40bc67a4;
    }
    param_3 = param_3 - 1;
    param_2 = param_2 + 1;
  } while( true );
}



/* 40bc67f0 FUN_40bc67f0 */

/* Boundary evidence: original MIPS .pdata 40bc67f0..40bc69cb. Semantic name remains unreviewed. */

undefined4 FUN_40bc67f0(undefined4 param_1,undefined1 *param_2,uint param_3)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint auStack_40 [6];
  
  bVar3 = false;
  bVar2 = false;
  while( true ) {
    if (param_3 < 5) {
      return 0;
    }
    if ((CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]) == 0x1ba) &&
       ((param_2[4] & 0xf0) == 0x20)) break;
LAB_40bc69ac:
    param_3 = param_3 - 1;
    param_2 = param_2 + 1;
  }
joined_r0x40bc6894:
  do {
    if (param_3 < 5) goto LAB_40bc69ac;
    bVar1 = param_2[3];
    uVar4 = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),bVar1);
    if ((0x1bb < uVar4) && (uVar4 < 0x200)) {
      uVar4 = FUN_40bc5e8c(param_2,param_3,auStack_40);
      if (4 < uVar4) {
        if ((bVar1 & 0xf0) == 0xe0) {
          bVar2 = true;
LAB_40bc6938:
          if (bVar3) {
            return 1;
          }
        }
        else {
          if (((bVar1 & 0xe0) == 0xc0) || (bVar1 == 0xbd)) {
            bVar3 = true;
          }
          if (bVar2) goto LAB_40bc6938;
        }
        param_3 = param_3 - uVar4;
        param_2 = param_2 + uVar4;
        if (param_3 == 0) {
          return 0;
        }
        goto joined_r0x40bc6894;
      }
      if (uVar4 == 0) goto LAB_40bc69ac;
    }
    param_3 = param_3 - 1;
    param_2 = param_2 + 1;
  } while( true );
}



/* 40bc69cc FUN_40bc69cc */

/* Boundary evidence: original MIPS .pdata 40bc69cc..40bc6bc3. Semantic name remains unreviewed. */

undefined4 FUN_40bc69cc(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,va_list param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 **ppuVar5;
  undefined4 uVar6;
  undefined1 *local_20 [2];
  
  uVar6 = 0x13a000;
  ppuVar5 = local_20;
  local_20[0] = (undefined1 *)0x0;
  param_1[6] = 0;
  param_1[7] = 0;
  uVar2 = FUN_40bc63f0(param_1,ppuVar5,0x13a000);
  puVar1 = local_20[0];
  if ((local_20[0] == (undefined1 *)0x0) && (uVar2 == 0)) {
    FUN_40bc3b24(0x40bdabd0,ppuVar5,uVar6,param_4);
    uVar6 = 0x80004005;
  }
  else {
    iVar3 = FUN_40bc6620(param_1,local_20[0],uVar2);
    if (iVar3 == 0) {
      iVar3 = FUN_40bc67f0(param_1,puVar1,uVar2);
      if (iVar3 == 0) {
        param_1[6] = 0;
        param_1[7] = 0;
        operator_delete(puVar1);
        uVar6 = 0x80040240;
      }
      else {
        puVar4 = malloc(0x48);
        *puVar4 = &DAT_40bdd348;
        puVar4[1] = &DAT_40bdd618;
        puVar4[6] = 0;
        puVar4[7] = 0;
        puVar4[9] = 0;
        puVar4[8] = 0;
        puVar4[10] = 0;
        puVar4[0xb] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
        puVar4[0xc] = 0;
        puVar4[0xd] = 0;
        puVar4[0xe] = 0;
        puVar4[0xf] = 0;
        puVar4[0x10] = 0;
        puVar4[0x11] = 0;
        *param_2 = puVar4;
        param_1[6] = 0;
        param_1[7] = 0;
        operator_delete(puVar1);
        uVar6 = 0;
      }
    }
    else {
      puVar4 = malloc(0x48);
      *puVar4 = &DAT_40bdd348;
      puVar4[1] = &DAT_40bde218;
      puVar4[6] = 0;
      puVar4[7] = 0;
      puVar4[9] = 0;
      puVar4[8] = 0;
      puVar4[10] = 0;
      puVar4[0xb] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[0xc] = 0;
      puVar4[0xd] = 0;
      puVar4[0xe] = 0;
      puVar4[0xf] = 0;
      puVar4[0x10] = 0;
      puVar4[0x11] = 0;
      *param_2 = puVar4;
      param_1[6] = 0;
      param_1[7] = 0;
      operator_delete(puVar1);
      uVar6 = 0;
    }
  }
  return uVar6;
}



/* 40bc6bc4 FUN_40bc6bc4 */

void FUN_40bc6bc4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40bdac08;
  return;
}



/* 40bc6bd4 FUN_40bc6bd4 */

/* Boundary evidence: original MIPS .pdata 40bc6bd4..40bc6c17. Semantic name remains unreviewed. */

undefined4 * FUN_40bc6bd4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40bdac08;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bc6c18 FUN_40bc6c18 */

/* Boundary evidence: original MIPS .pdata 40bc6c18..40bc6c5b. Semantic name remains unreviewed. */

undefined4 * FUN_40bc6c18(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40bdac5c;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bc6c6c FUN_40bc6c6c */

/* Boundary evidence: original MIPS .pdata 40bc6c6c..40bc6cbf. Semantic name remains unreviewed. */

void FUN_40bc6c6c(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while (iVar2 != 0) {
    puVar1 = (undefined4 *)*param_1;
    *param_1 = puVar1[4];
    (**(code **)*puVar1)(puVar1,1);
    iVar2 = *param_1;
  }
  return;
}



/* 40bc6cc0 FUN_40bc6cc0 */

/* Boundary evidence: original MIPS .pdata 40bc6cc0..40bc6def. Semantic name remains unreviewed. */

undefined4 * FUN_40bc6cc0(undefined4 *param_1,undefined4 param_2)

{
  HANDLE pvVar1;
  
  param_1[1] = 0;
  param_1[2] = param_2;
  *param_1 = &PTR_FUN_40bdac60;
  _eh_vector_constructor_iterator_
            (param_1 + 3,8,2,(_func_void_void_ptr *)&LAB_40bc6c5c,FUN_40bc6c6c);
  param_1[0x32] = 0xffffffff;
  param_1[0x33] = 0xffffffff;
  param_1[0x34] = 0xffffffff;
  param_1[0x35] = 0xffffffff;
  param_1[0x36] = 0xffffffff;
  param_1[0x37] = 0xffffffff;
  param_1[0x52] = 0xffffffff;
  param_1[0x53] = 0xffffffff;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  param_1[10] = 0;
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
  param_1[0x42] = 0;
  *(undefined1 *)(param_1 + 0x46) = 0;
  *(undefined1 *)((int)param_1 + 0x11a) = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 1;
  param_1[0x4b] = 1;
  param_1[0x4c] = 0;
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
  param_1[0x43] = pvVar1;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  return param_1;
}



/* 40bc6df0 FUN_40bc6df0 */

/* Boundary evidence: original MIPS .pdata 40bc6df0..40bc6e1f. Semantic name remains unreviewed. */

void FUN_40bc6df0(void)

{
  undefined4 *in_v0;
  
  FUN_40bc6bc4((undefined4 *)*in_v0);
  return;
}



/* 40bc6e30 FUN_40bc6e30 */

/* Boundary evidence: original MIPS .pdata 40bc6e30..40bc6ed7. Semantic name remains unreviewed. */

void FUN_40bc6e30(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40bdac60;
  if ((int *)param_1[0x44] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x44] + 8))();
    param_1[0x44] = 0;
  }
  if ((int *)param_1[0x45] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x45] + 8))();
    param_1[0x45] = 0;
  }
  _eh_vector_destructor_iterator_(param_1 + 3,8,2,FUN_40bc6c6c);
  *param_1 = &PTR_FUN_40bdac08;
  return;
}



/* 40bc6ed8 FUN_40bc6ed8 */

/* Boundary evidence: original MIPS .pdata 40bc6ed8..40bc6f07. Semantic name remains unreviewed. */

void FUN_40bc6ed8(void)

{
  undefined4 *in_v0;
  
  FUN_40bc6bc4((undefined4 *)*in_v0);
  return;
}



/* 40bc6f08 FUN_40bc6f08 */

/* Boundary evidence: original MIPS .pdata 40bc6f08..40bc6f4b. Semantic name remains unreviewed. */

void FUN_40bc6f08(void)

{
  int *in_v0;
  
  _eh_vector_destructor_iterator_((void *)(*in_v0 + 0xc),8,2,FUN_40bc6c6c);
  return;
}



/* 40bc6f7c FUN_40bc6f7c */

/* Boundary evidence: original MIPS .pdata 40bc6f7c..40bc6ffb. Semantic name remains unreviewed. */

undefined4 FUN_40bc6f7c(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_40bde4a8,0x10);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0xcc);
    if (-1 < iVar1) {
      *param_2 = *(undefined4 *)(param_1 + 200);
      param_2[1] = iVar1;
      return 0;
    }
  }
  return 0x80040261;
}



/* 40bc6ffc FUN_40bc6ffc */

/* Boundary evidence: original MIPS .pdata 40bc6ffc..40bc7303. Semantic name remains unreviewed. */

undefined4
FUN_40bc6ffc(int *param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,int param_6,
            uint *param_7,uint *param_8)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint extraout_v1;
  uint extraout_v1_00;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_38;
  int local_34;
  uint local_30;
  
  uVar9 = param_1[0x30];
  uVar10 = param_1[0x31];
  if (param_1[1] == 0) {
    if ((param_3 == param_5) && (param_4 == param_6)) {
      param_8[1] = uVar10;
      *param_8 = uVar9;
      *param_7 = uVar9;
      param_7[1] = param_8[1];
      return 0;
    }
    if (-1 < param_1[0x33]) {
      if ((param_4 < 0) || ((param_4 == 0 && (param_3 < 20000000)))) {
        uVar2 = 0;
        uVar5 = 0;
      }
      else {
        uVar11 = param_3 + 0xfeced300;
        uVar12 = param_4 - (uint)(param_3 < 20000000);
        local_38 = 0;
        local_34 = 0;
        uVar2 = FUN_40bd5994(uVar9,uVar10,uVar11,uVar12,param_1[0x32],param_1[0x33],0,0);
        uVar2 = uVar2 & 0xfffffffc;
        iVar3 = (**(code **)(*param_1 + 0x38))
                          (param_1,param_2,uVar2,extraout_v1,uVar11,uVar12,&local_38);
        uVar7 = uVar11;
        uVar4 = uVar12;
        uVar5 = extraout_v1;
        for (iVar8 = 0;
            ((-1 < iVar3 &&
             (((0 < local_34 || ((local_34 == 0 && (10000000 < local_38)))) ||
              ((local_34 < 0 && ((local_34 != -1 || (local_38 < 0xff676980)))))))) && (iVar8 < 0xb))
            ; iVar8 = iVar8 + 1) {
          uVar2 = (uint)((ulonglong)local_38 * 3);
          iVar3 = local_34 * 3 + (int)((ulonglong)local_38 * 3 >> 0x20);
          uVar5 = (uint)(iVar3 >> 1) >> 0x1e;
          uVar6 = uVar5 + uVar2;
          local_30 = iVar3 * -0x80000000 | uVar2 >> 1;
          iVar3 = iVar3 + (uint)(uVar6 < uVar5);
          uVar2 = iVar3 * 0x40000000 | uVar6 >> 2;
          bVar1 = uVar7 < uVar2;
          uVar7 = uVar7 - uVar2;
          uVar4 = (uVar4 - (iVar3 >> 2)) - (uint)bVar1;
          uVar2 = FUN_40bd5994(param_1[0x30],param_1[0x31],uVar7,uVar4,param_1[0x32],param_1[0x33],0
                               ,0);
          uVar2 = uVar2 & 0xfffffffc;
          iVar3 = (**(code **)(*param_1 + 0x38))
                            (param_1,param_2,uVar2,extraout_v1_00,uVar11,uVar12,&local_38);
          uVar5 = extraout_v1_00;
        }
      }
      *param_7 = uVar2;
      param_7[1] = uVar5;
      *param_8 = uVar9;
      param_8[1] = uVar10;
      return 0;
    }
  }
  else {
    *param_8 = 0;
    param_8[1] = 0;
    *param_7 = 0;
    param_7[1] = 0;
  }
  return 1;
}



/* 40bc7304 FUN_40bc7304 */

/* Boundary evidence: original MIPS .pdata 40bc7304..40bc7693. Semantic name remains unreviewed. */

undefined4
FUN_40bc7304(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5,int param_6
            ,int *param_7)

{
  longlong lVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 **ppuVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  ulonglong uVar14;
  undefined1 *local_50;
  int *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint auStack_40 [2];
  int local_38;
  uint local_30;
  int local_2c;
  
  iVar13 = 0;
  iVar10 = 0x7fffffff;
  uVar12 = 0xffffffff;
  uVar9 = 0;
  local_4c = param_2;
  local_48 = param_4;
  local_44 = param_3;
  while( true ) {
    piVar7 = local_4c;
    local_50 = (undefined1 *)0x0;
    uVar4 = 0;
    iVar3 = iVar10;
    uVar8 = uVar12;
    if ((0 < iVar13) || ((iVar13 == 0 && (0x20000 < uVar9)))) break;
    iVar3 = (**(code **)(*local_4c + 8))(local_4c);
    if (-1 < iVar3) {
      uVar6 = 0x8000;
      ppuVar5 = &local_50;
      uVar4 = FUN_40bcd02c(param_1,ppuVar5,0x8000,piVar7);
      if ((local_50 == (undefined1 *)0x0) && (uVar4 == 0)) {
        FUN_40bc3b24(0x40bdad38,ppuVar5,uVar6,(va_list)piVar7);
        *(undefined4 *)(param_1 + 4) = 1;
        goto LAB_40bc75ac;
      }
    }
    iVar13 = iVar13 + (uint)(uVar9 + 0x8000 < uVar9);
    puVar2 = local_50;
joined_r0x40bc7400:
    iVar3 = iVar10;
    uVar8 = uVar12;
    if (4 < uVar4) {
      uVar11 = CONCAT31(CONCAT21(CONCAT11(*puVar2,puVar2[1]),puVar2[2]),puVar2[3]);
      uVar8 = uVar11 & 0xfffffff0;
      if (((uVar8 == 0x1e0) || (uVar8 == 0x1c0)) || (uVar8 == 0x1bd)) {
        if (*(undefined **)(param_1 + 0x7c) == &DAT_40bdd638) {
          uVar11 = FUN_40bc5e8c(puVar2,uVar4,auStack_40);
        }
        else {
          uVar11 = FUN_40bc60f8((int)puVar2,uVar4,(int *)auStack_40);
        }
      }
      else {
        if ((uVar11 < 0x1bc) || (0x1ff < uVar11)) {
          uVar4 = uVar4 - 1;
          puVar2 = puVar2 + 1;
          goto joined_r0x40bc7400;
        }
        if (*(undefined **)(param_1 + 0x7c) == &DAT_40bdd638) {
          uVar11 = FUN_40bc5e8c(puVar2,uVar4,auStack_40);
        }
        else {
          uVar11 = FUN_40bc61c4((int)puVar2,uVar4,auStack_40);
        }
      }
      if ((local_38 != 0) &&
         ((iVar3 = local_2c, uVar8 = local_30, local_2c < iVar10 ||
          ((local_2c == iVar10 && (local_30 < uVar12)))))) goto LAB_40bc755c;
      if (uVar11 == 0) {
        uVar4 = uVar4 - 4;
        puVar2 = puVar2 + 4;
      }
      else {
        iVar3 = iVar10;
        uVar8 = uVar12;
        if (uVar4 < uVar11) goto LAB_40bc755c;
        uVar4 = uVar4 - uVar11;
        puVar2 = puVar2 + uVar11;
      }
      goto joined_r0x40bc7400;
    }
LAB_40bc755c:
    operator_delete(local_50);
    if ((uVar8 != 0xffffffff) ||
       (iVar10 = iVar3, uVar12 = uVar8, uVar9 = uVar9 + 0x8000, iVar3 != 0x7fffffff)) break;
  }
  local_50 = (undefined1 *)0x0;
  (**(code **)(*local_4c + 8))(local_4c);
  if ((uVar8 == 0xffffffff) && (iVar3 == 0x7fffffff)) {
LAB_40bc75ac:
    uVar6 = 0x80004005;
  }
  else {
    uVar14 = __ll_div(uVar8,iVar3,0x5a,0);
    iVar10 = *(int *)(param_1 + 0xd4);
    lVar1 = (uVar14 & 0xffffffff) * 10000;
    uVar12 = (uint)lVar1;
    uVar6 = 0;
    uVar9 = *(uint *)(param_1 + 0xd0);
    uVar4 = uVar12 - uVar9;
    *param_7 = uVar4 - param_5;
    param_7[1] = (((((int)(uVar14 >> 0x20) * 10000 + (int)((ulonglong)lVar1 >> 0x20)) - iVar10) -
                  (uint)(uVar12 < uVar9)) - param_6) - (uint)(uVar4 < param_5);
  }
  return uVar6;
}



/* 40bc770c FUN_40bc770c */

/* Boundary evidence: original MIPS .pdata 40bc770c..40bc773f. Semantic name remains unreviewed. */

undefined4 FUN_40bc770c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = __dptoli(param_3,param_4);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  return 0;
}



/* 40bc7754 FUN_40bc7754 */

/* Boundary evidence: original MIPS .pdata 40bc7754..40bc77b3. Semantic name remains unreviewed. */

void FUN_40bc7754(int param_1)

{
  if (*(int **)(param_1 + 0x110) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x110) + 8))();
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  if (*(int **)(param_1 + 0x114) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x114) + 8))();
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  return;
}



/* 40bc77b4 FUN_40bc77b4 */

/* Boundary evidence: original MIPS .pdata 40bc77b4..40bc787b. Semantic name remains unreviewed. */

undefined4 FUN_40bc77b4(undefined1 *param_1,uint param_2,int *param_3)

{
  byte *pbVar1;
  bool bVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar2 = false;
  do {
    while( true ) {
      if (param_2 < 5) {
        return 0;
      }
      iVar4 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
      if (iVar4 != 0x1b3) break;
      bVar2 = true;
      *param_3 = iVar5;
LAB_40bc7818:
      iVar5 = iVar5 + 1;
      param_2 = param_2 - 1;
      param_1 = param_1 + 1;
      if (iVar4 == 0x1b7) {
        return 0;
      }
    }
    if (iVar4 != 0x100) goto LAB_40bc7818;
    puVar3 = param_1 + 4;
    pbVar1 = param_1 + 5;
    iVar5 = iVar5 + 4;
    param_2 = param_2 - 4;
    param_1 = puVar3;
    if (((*pbVar1 & 0x38) == 8) && (bVar2)) {
      return 1;
    }
  } while( true );
}



/* 40bc787c FUN_40bc787c */

/* Boundary evidence: original MIPS .pdata 40bc787c..40bc78df. Semantic name remains unreviewed. */

undefined4 FUN_40bc787c(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x44))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  *param_2 = iVar1 + iVar2;
  return 0;
}



/* 40bc78e0 FUN_40bc78e0 */

/* Boundary evidence: original MIPS .pdata 40bc78e0..40bc7987. Semantic name remains unreviewed. */

undefined4 FUN_40bc78e0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x44))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  if (iVar1 + iVar2 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x44))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
    if (param_2 < iVar1 + iVar2) {
      return 0;
    }
  }
  return 0x80004005;
}



/* 40bc7988 FUN_40bc7988 */

/* WARNING: Removing unreachable block (ram,0x40bc7c18) */
/* Boundary evidence: original MIPS .pdata 40bc7988..40bc7cd7. Semantic name remains unreviewed. */

void FUN_40bc7988(int param_1,int *param_2,uint param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 **ppuVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  undefined1 *local_58;
  int *local_54;
  int local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  uint auStack_40 [2];
  int local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  lVar11 = 0;
  uVar8 = 0;
  iVar10 = 0;
  local_54 = param_2;
  local_48 = param_4;
  local_44 = param_3;
  do {
    piVar7 = local_54;
    local_58 = (undefined1 *)0x0;
    uVar3 = 0;
    uVar9 = uVar8 + 0x8000;
    iVar10 = iVar10 + (uint)(uVar9 < uVar8);
    local_50 = iVar10;
    local_4c = uVar9;
    if ((local_48 < iVar10) ||
       ((((iVar10 == local_48 && (local_44 <= uVar9)) || (0 < iVar10)) ||
        ((iVar10 == 0 && (0x800000 < uVar9)))))) break;
    iVar2 = (**(code **)(*local_54 + 8))(local_54);
    puVar1 = local_58;
    if (-1 < iVar2) {
      uVar6 = 0x8000;
      ppuVar5 = &local_58;
      uVar3 = FUN_40bcd02c(param_1,ppuVar5,0x8000,piVar7);
      puVar1 = local_58;
      if ((local_58 == (undefined1 *)0x0) && (uVar3 == 0)) {
        FUN_40bc3b24(0x40bdad84,ppuVar5,uVar6,(va_list)piVar7);
        *(undefined4 *)(param_1 + 4) = 1;
        *(undefined4 *)(param_1 + 0xd8) = 0;
        *(undefined4 *)(param_1 + 0xdc) = 0;
        return;
      }
    }
    while (uVar8 = uVar9, 4 < uVar3) {
      uVar9 = CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3]);
      uVar8 = uVar9 & 0xfffffff0;
      if (((uVar8 == 0x1e0) || (uVar8 == 0x1c0)) || (uVar8 == 0x1bd)) {
        if (*(undefined **)(param_1 + 0x7c) == &DAT_40bdd638) {
          uVar4 = FUN_40bc5e8c(puVar1,uVar3,auStack_40);
        }
        else {
          uVar4 = FUN_40bc60f8((int)puVar1,uVar3,(int *)auStack_40);
        }
LAB_40bc7ba8:
        if (local_38 != 0) {
          lVar11 = __ll_div(local_30,local_2c,0x5a,0);
          lVar11 = lVar11 * 10000;
          if (((*(uint *)(param_1 + 0xd8) & *(uint *)(param_1 + 0xdc)) == 0xffffffff) ||
             (*(longlong *)(param_1 + 0xd8) < lVar11)) {
            *(longlong *)(param_1 + 0xd8) = lVar11;
          }
        }
        iVar10 = local_50;
        uVar9 = local_4c;
        if (uVar4 == 0) {
          uVar3 = uVar3 - 4;
          puVar1 = puVar1 + 4;
        }
        else {
          uVar8 = local_4c;
          if (uVar3 < uVar4) break;
          uVar3 = uVar3 - uVar4;
          puVar1 = puVar1 + uVar4;
        }
      }
      else {
        if ((0x1bb < uVar9) && (uVar9 < 0x200)) {
          if (*(undefined **)(param_1 + 0x7c) == &DAT_40bdd638) {
            uVar4 = FUN_40bc5e8c(puVar1,uVar3,auStack_40);
          }
          else {
            uVar4 = FUN_40bc61c4((int)puVar1,uVar3,auStack_40);
          }
          goto LAB_40bc7ba8;
        }
        uVar3 = uVar3 - 1;
        uVar9 = local_4c;
        iVar10 = local_50;
        puVar1 = puVar1 + 1;
      }
    }
    operator_delete(local_58);
  } while (lVar11 == 0);
  local_58 = (undefined1 *)0x0;
  (**(code **)(*local_54 + 8))(local_54);
  return;
}



/* 40bc7cd8 FUN_40bc7cd8 */

/* Boundary evidence: original MIPS .pdata 40bc7cd8..40bc7ef7. Semantic name remains unreviewed. */

undefined4 FUN_40bc7cd8(undefined4 param_1,uint param_2,char *param_3,int param_4,int *param_5)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  int *piVar8;
  int iVar9;
  
  iVar9 = 0;
  bVar3 = false;
  *param_5 = 0;
  if (((param_2 & 0xffff0000) != 0xb770000) && ((param_2 & 0xffff0000) != 0x770b0000)) {
    while( true ) {
      if (param_4 < 4) {
        return 0;
      }
      uVar2 = CONCAT11(*param_3,param_3[1]);
      param_2 = (uint)uVar2 << 0x10;
      if ((uVar2 == 0xb77) || (uVar2 == 0x770b)) break;
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    }
  }
  do {
    if (param_4 < 4) {
      return 0;
    }
    uVar5 = param_2 & 0xffff0000;
    if ((uVar5 != 0xb770000) && (uVar5 != 0x770b0000)) {
      return 0xffffffff;
    }
    if (uVar5 == 0x770b0000) {
      bVar3 = true;
LAB_40bc7ddc:
      bVar1 = param_3[5];
    }
    else {
      if (bVar3) goto LAB_40bc7ddc;
      bVar1 = param_3[4];
    }
    bVar4 = bVar1 >> 6;
    if ((bVar4 == 3) || (uVar5 = bVar1 & 0x3f, 0x25 < uVar5)) {
      return 0xffffffff;
    }
    if (bVar4 == 0) {
      puVar7 = &DAT_40bdf860;
LAB_40bc7e50:
      piVar8 = (int *)(puVar7 + uVar5 * 0xc);
LAB_40bc7e64:
      iVar9 = *piVar8 << 1;
    }
    else {
      if (bVar4 == 1) {
        puVar7 = &DAT_40bdf85c;
        goto LAB_40bc7e50;
      }
      if (bVar4 == 2) {
        piVar8 = (int *)(&DAT_40bdf858 + uVar5 * 0xc);
        goto LAB_40bc7e64;
      }
    }
    iVar6 = *param_5;
    *param_5 = iVar6 + 1;
    if (8 < iVar6 + 1) {
      return 0;
    }
    param_4 = param_4 - iVar9;
    if (param_4 <= iVar9) {
      return 0;
    }
    param_3 = param_3 + iVar9;
    if ((*param_3 == '\x01') && (param_3[1] == '\x10')) {
      param_3 = param_3 + 0x10;
      param_4 = param_4 + -0x10;
    }
    param_2 = (uint)CONCAT11(*param_3,param_3[1]) << 0x10;
  } while( true );
}



/* 40bc7ef8 FUN_40bc7ef8 */

/* Boundary evidence: original MIPS .pdata 40bc7ef8..40bc8033. Semantic name remains unreviewed. */

uint FUN_40bc7ef8(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  int *in_stack_0000004c;
  int *in_stack_00000050;
  undefined1 auStack_68 [72];
  uint local_20;
  
  local_20 = DAT_40be0550;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memcpy(auStack_68,&local_res4,0x48);
  uVar5 = 0x10;
  puVar3 = &DAT_40bdeb90;
  iVar1 = memcmp(auStack_68,&DAT_40bdeb90,0x10);
  if (iVar1 == 0) {
    FUN_40bc3b24(0x40bdaed4,puVar3,uVar5,param_4);
    FUN_40bd8bd0(local_20);
    uVar2 = 0x80004005;
  }
  else {
    uVar5 = 0x10;
    puVar4 = &DAT_40bdd2f8;
    iVar1 = memcmp(auStack_68,&DAT_40bdd2f8,0x10);
    if (iVar1 == 0) {
      *in_stack_0000004c = *(int *)(param_1 + 0x58);
      *in_stack_00000050 = *(int *)(param_1 + 0x5c);
    }
    else {
      *in_stack_0000004c = *(int *)(param_1 + 0xa0);
      *in_stack_00000050 = *(int *)(param_1 + 0xa4);
    }
    iVar1 = *in_stack_0000004c;
    if (iVar1 == 0) {
      FUN_40bc3b24(0x40bdae54,puVar4,uVar5,param_4);
      *in_stack_0000004c = 0x8000;
    }
    uVar2 = (uint)(iVar1 == 0);
    if (*in_stack_00000050 == 0) {
      FUN_40bc3b24(0x40bdadd0,puVar4,uVar5,param_4);
      *in_stack_00000050 = 0x40;
      uVar2 = 1;
    }
    FUN_40bd8bd0(local_20);
  }
  return uVar2;
}



/* 40bc8034 FUN_40bc8034 */

/* Boundary evidence: original MIPS .pdata 40bc8034..40bc807f. Semantic name remains unreviewed. */

undefined4 * FUN_40bc8034(undefined4 *param_1,uint param_2)

{
  FUN_40bc6e30(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bc8080 FUN_40bc8080 */

/* Boundary evidence: original MIPS .pdata 40bc8080..40bc80cf. Semantic name remains unreviewed. */

undefined4 FUN_40bc8080(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (iVar1 = (**(code **)**(undefined4 **)(*(int *)(param_1 + 0xc) + 0xc))(), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



/* 40bc80d0 FUN_40bc80d0 */

/* Boundary evidence: original MIPS .pdata 40bc80d0..40bc8223. Semantic name remains unreviewed. */

undefined4 FUN_40bc80d0(int param_1,int *param_2,void *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = memcmp(param_3,&DAT_40bde4a8,0x10);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0xc) != 0) &&
       (iVar1 = (**(code **)**(undefined4 **)(*(int *)(param_1 + 0xc) + 0xc))(), iVar1 != 0)) {
      uVar2 = *(uint *)(param_1 + 0xe0);
      uVar3 = *(uint *)(param_1 + 0xf8);
      iVar4 = *(int *)(param_1 + 0xfc);
      iVar1 = *(int *)(param_1 + 0xe4);
      uVar7 = uVar3 - uVar2;
      uVar5 = *(uint *)(param_1 + 0xd0);
      iVar6 = *(int *)(param_1 + 0xd4);
      *param_2 = uVar7 - uVar5;
      param_2[1] = (((iVar4 - iVar1) - (uint)(uVar3 < uVar2)) - iVar6) - (uint)(uVar7 < uVar5);
      return 0;
    }
    if ((*(int *)(param_1 + 0x14) != 0) &&
       (iVar1 = (**(code **)**(undefined4 **)(*(int *)(param_1 + 0x14) + 0xc))(), iVar1 != 0)) {
      uVar2 = *(uint *)(param_1 + 0xe0);
      uVar3 = *(uint *)(param_1 + 0xf0);
      iVar4 = *(int *)(param_1 + 0xf4);
      iVar1 = *(int *)(param_1 + 0xe4);
      uVar7 = uVar3 - uVar2;
      uVar5 = *(uint *)(param_1 + 0xd0);
      iVar6 = *(int *)(param_1 + 0xd4);
      *param_2 = uVar7 - uVar5;
      param_2[1] = (((iVar4 - iVar1) - (uint)(uVar3 < uVar2)) - iVar6) - (uint)(uVar7 < uVar5);
      return 0;
    }
  }
  return 0x80040261;
}



/* 40bc8224 FUN_40bc8224 */

/* Boundary evidence: original MIPS .pdata 40bc8224..40bc829b. Semantic name remains unreviewed. */

void FUN_40bc8224(int param_1)

{
  if (*(int *)(param_1 + 0x110) != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0x14) + 0xc) + 8))();
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  if (*(int *)(param_1 + 0x114) != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 0xc) + 8))();
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  return;
}



/* 40bc829c FUN_40bc829c */

/* WARNING: Removing unreachable block (ram,0x40bc8398) */
/* Boundary evidence: original MIPS .pdata 40bc829c..40bc87ab. Semantic name remains unreviewed. */

int FUN_40bc829c(int param_1,undefined1 *param_2,int *param_3,va_list param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  va_list pcVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *_Size;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  void *local_50;
  va_list local_4c;
  int aiStack_48 [2];
  int local_40 [4];
  undefined8 local_30;
  
  *(undefined4 *)(param_1 + 0x130) = 0;
  iVar8 = *(int *)(param_1 + 0xc);
  _Size = (int *)0x0;
  piVar7 = (int *)0x0;
  local_30._0_4_ = 0;
  local_30._4_4_ = 0;
  local_50 = (void *)0x0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  if ((iVar8 == 0) ||
     (piVar3 = param_3, pcVar4 = param_4, local_4c = param_4,
     iVar1 = (**(code **)**(undefined4 **)(iVar8 + 0xc))(), iVar1 == 0)) {
    iVar8 = 1;
  }
  else {
    if ((*(int *)(param_1 + 0x108) != 0) && (param_4 != (va_list)0x0)) {
      uVar5 = *(uint *)(param_1 + 0xf8) - *(uint *)(param_1 + 0xe0);
      piVar3 = *(int **)(param_1 + 0x24);
      pcVar4 = (va_list)((int)piVar3 >> 0x1f);
      lVar9 = __ll_div(uVar5 - *(uint *)(param_1 + 0xd0),
                       (((*(int *)(param_1 + 0xfc) - *(int *)(param_1 + 0xe4)) -
                        (uint)(*(uint *)(param_1 + 0xf8) < *(uint *)(param_1 + 0xe0))) -
                       *(int *)(param_1 + 0xd4)) - (uint)(uVar5 < *(uint *)(param_1 + 0xd0)));
      if (-0x4c4b41 < lVar9) {
        *(undefined4 *)(param_1 + 0x108) = 0;
        *(undefined4 *)(param_1 + 300) = 1;
      }
    }
    if ((*(int *)(param_1 + 0x108) == 0) && (*(int *)(param_1 + 0x100) == 0)) {
      if ((*(int *)(param_1 + 0x138) != 0) || (*(int *)(param_1 + 0x13c) != 0)) {
        param_5 = 1;
      }
      piVar6 = (int *)(param_1 + 0x114);
      piVar2 = (int *)*piVar6;
      if (piVar2 != (int *)0x0) {
        iVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_50);
        if (iVar1 < 0) {
          FUN_40bc3b24(0x40bdaf20,iVar1,piVar3,pcVar4);
          return iVar1;
        }
        _Size = (int *)(**(code **)(*(int *)*piVar6 + 0x10))();
        piVar7 = (int *)(**(code **)(*(int *)*piVar6 + 0x2c))();
        if ((((local_4c != (va_list)0x0) || (*(int *)(param_1 + 300) != 0)) || (param_5 != 0)) &&
           (piVar7 != (int *)0x0)) {
          local_40[0] = 0;
          local_40[1] = 0;
          local_40[2] = 0;
          local_40[3] = 0;
          piVar3 = local_40;
          (**(code **)(*(int *)*piVar6 + 0x14))((int *)*piVar6,local_40 + 2);
          (**(code **)(**(int **)(iVar8 + 0xc) + 8))(*(int **)(iVar8 + 0xc),*piVar6);
          *piVar6 = 0;
        }
      }
      if (*(int *)(param_1 + 0x100) == 0) {
        while (param_3 != (int *)0x0) {
          if (*piVar6 == 0) {
            iVar1 = (**(code **)(**(int **)(iVar8 + 0xc) + 4))(*(int **)(iVar8 + 0xc),piVar6);
            if (iVar1 < 0) {
              return iVar1;
            }
            piVar7 = (int *)*piVar6;
            if (piVar7 == (int *)0x0) {
              return iVar1;
            }
            (**(code **)(*piVar7 + 0x30))(piVar7,0);
            iVar1 = (**(code **)(*(int *)*piVar6 + 0xc))((int *)*piVar6,&local_50);
            if (iVar1 < 0) {
              FUN_40bc3b24(0x40bdaf20,iVar1,piVar3,pcVar4);
              return iVar1;
            }
            _Size = (int *)(**(code **)(*(int *)*piVar6 + 0x10))();
            piVar7 = (int *)(**(code **)(*(int *)*piVar6 + 0x2c))();
          }
          if (local_4c != (va_list)0x0) {
            uVar5 = *(uint *)(param_1 + 0xf8) - *(uint *)(param_1 + 0xe0);
            pcVar4 = (va_list)(*(int *)(param_1 + 0x24) >> 0x1f);
            uVar10 = __ll_div(uVar5 - *(uint *)(param_1 + 0xd0),
                              (((*(int *)(param_1 + 0xfc) - *(int *)(param_1 + 0xe4)) -
                               (uint)(*(uint *)(param_1 + 0xf8) < *(uint *)(param_1 + 0xe0))) -
                              *(int *)(param_1 + 0xd4)) - (uint)(uVar5 < *(uint *)(param_1 + 0xd0)))
            ;
            piVar3 = (int *)0x0;
            local_30 = uVar10;
            (**(code **)(*(int *)*piVar6 + 0x18))((int *)*piVar6,&local_30);
            local_4c = (va_list)0x0;
          }
          if ((5 < *(int *)(param_1 + 0x24)) ||
             (((*(int *)(param_1 + 0x24) < 0 && (*(int *)(param_1 + 0x138) == 0)) &&
              (*(int *)(param_1 + 0x13c) == 0)))) {
            piVar3 = aiStack_48;
            iVar1 = FUN_40bc77b4(param_2,(uint)param_3,piVar3);
            if (iVar1 == 0) break;
            *(undefined4 *)(param_1 + 300) = 1;
          }
          if (*(int *)(param_1 + 300) != 0) {
            (**(code **)(*(int *)*piVar6 + 0x40))((int *)*piVar6,1);
            *(undefined4 *)(param_1 + 300) = 0;
          }
          piVar2 = (int *)((int)piVar7 + (int)param_3);
          if (_Size < piVar2) {
            if (piVar7 == (int *)0x0) {
              if (param_3 <= _Size) goto LAB_40bc8728;
              memcpy(local_50,param_2,(size_t)_Size);
              param_2 = (undefined1 *)((int)_Size + (int)param_2);
              param_3 = (int *)((int)param_3 - (int)_Size);
              (**(code **)(*(int *)*piVar6 + 0x30))((int *)*piVar6,_Size);
              piVar7 = _Size;
            }
            local_40[0] = 0;
            local_40[1] = 0;
            local_40[2] = 0;
            local_40[3] = 0;
            piVar3 = local_40;
            (**(code **)(*(int *)*piVar6 + 0x14))((int *)*piVar6,local_40 + 2);
            (**(code **)(**(int **)(iVar8 + 0xc) + 8))(*(int **)(iVar8 + 0xc),*piVar6);
            *piVar6 = 0;
          }
          else {
            piVar3 = param_3;
            memcpy((void *)((int)piVar7 + (int)local_50),param_2,(size_t)param_3);
            param_2 = param_2 + (int)param_3;
            param_3 = (int *)0x0;
            (**(code **)(*(int *)*piVar6 + 0x30))((int *)*piVar6,piVar2);
            piVar7 = piVar2;
          }
LAB_40bc8728:
          if (*(int *)(param_1 + 0x100) != 0) {
            return 0;
          }
        }
      }
    }
    else if (*(int **)(param_1 + 0x114) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x114) + 8))();
      *(undefined4 *)(param_1 + 0x114) = 0;
    }
    iVar8 = 0;
  }
  return iVar8;
}



/* 40bc87ac FUN_40bc87ac */

/* WARNING: Removing unreachable block (ram,0x40bc88ec) */
/* Boundary evidence: original MIPS .pdata 40bc87ac..40bc8c93. Semantic name remains unreviewed. */

int FUN_40bc87ac(int param_1,void *param_2,undefined4 *param_3,va_list param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  va_list pcVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *_Size;
  undefined4 *puVar6;
  undefined4 *_Size_00;
  undefined4 *puVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  void *local_48;
  va_list local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  
  local_30._0_4_ = 0;
  local_30._4_4_ = 0;
  _Size_00 = (undefined4 *)0x0;
  local_48 = (void *)0x0;
  puVar6 = (undefined4 *)0x0;
  local_38 = 0;
  local_34 = 0;
  local_40 = 0;
  local_3c = 0;
  _Size = param_3;
  if (*(int *)(param_1 + 0x140) != 0) {
    param_2 = (void *)((int)param_2 + 4);
    _Size = param_3 + -1;
  }
  iVar8 = *(int *)(param_1 + 0x14);
  if ((iVar8 == 0) ||
     (pcVar3 = param_4, local_44 = param_4, iVar1 = (**(code **)**(undefined4 **)(iVar8 + 0xc))(),
     iVar1 == 0)) {
    iVar8 = 1;
  }
  else {
    if (*(uint *)(param_1 + 0x130) < 0x10) {
      *(uint *)(param_1 + 0x130) = *(uint *)(param_1 + 0x130) + 1;
    }
    else {
      pcVar3 = (va_list)0x0;
      param_3 = (undefined4 *)0x0;
      FUN_40bc829c(param_1,(undefined1 *)0x0,(int *)0x0,(va_list)0x0,1);
    }
    if ((*(int *)(param_1 + 0x104) != 0) && (param_4 != (va_list)0x0)) {
      uVar4 = *(uint *)(param_1 + 0xf0) - *(uint *)(param_1 + 0xe0);
      param_3 = *(undefined4 **)(param_1 + 0x24);
      pcVar3 = (va_list)((int)param_3 >> 0x1f);
      lVar9 = __ll_div(uVar4 - *(uint *)(param_1 + 0xd0),
                       (((*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xe4)) -
                        (uint)(*(uint *)(param_1 + 0xf0) < *(uint *)(param_1 + 0xe0))) -
                       *(int *)(param_1 + 0xd4)) - (uint)(uVar4 < *(uint *)(param_1 + 0xd0)));
      if (-0x7a121 < lVar9) {
        *(undefined4 *)(param_1 + 0x104) = 0;
        *(undefined4 *)(param_1 + 0x128) = 1;
      }
    }
    if (((*(int *)(param_1 + 0x104) == 0) && (*(int *)(param_1 + 0x100) == 0)) &&
       (*(int *)(param_1 + 0x24) == 1)) {
      piVar5 = (int *)(param_1 + 0x110);
      piVar2 = (int *)*piVar5;
      if (piVar2 != (int *)0x0) {
        iVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_48);
        if (iVar1 < 0) {
          FUN_40bc3b24(0x40bdafa8,iVar1,param_3,pcVar3);
          return iVar1;
        }
        _Size_00 = (undefined4 *)(**(code **)(*(int *)*piVar5 + 0x10))();
        puVar6 = (undefined4 *)(**(code **)(*(int *)*piVar5 + 0x2c))();
        if ((((param_4 != (va_list)0x0) || (*(int *)(param_1 + 0x128) != 0)) || (param_5 != 0)) &&
           (puVar6 != (undefined4 *)0x0)) {
          local_40 = 0;
          local_3c = 0;
          local_38 = 0;
          local_34 = 0;
          param_3 = &local_40;
          (**(code **)(*(int *)*piVar5 + 0x14))((int *)*piVar5,&local_38);
          (**(code **)(**(int **)(iVar8 + 0xc) + 8))(*(int **)(iVar8 + 0xc),*piVar5);
          *piVar5 = 0;
        }
      }
      iVar1 = *(int *)(param_1 + 0x100);
      while ((iVar1 == 0 && (_Size != (undefined4 *)0x0))) {
        if (*piVar5 == 0) {
          iVar1 = (**(code **)(**(int **)(iVar8 + 0xc) + 4))(*(int **)(iVar8 + 0xc),piVar5);
          if (iVar1 < 0) {
            return iVar1;
          }
          piVar2 = (int *)*piVar5;
          if (piVar2 == (int *)0x0) {
            return iVar1;
          }
          (**(code **)(*piVar2 + 0x30))(piVar2,0);
          iVar1 = (**(code **)(*(int *)*piVar5 + 0xc))((int *)*piVar5,&local_48);
          if (iVar1 < 0) {
            FUN_40bc3b24(0x40bdafa8,iVar1,param_3,pcVar3);
            return iVar1;
          }
          _Size_00 = (undefined4 *)(**(code **)(*(int *)*piVar5 + 0x10))();
          puVar6 = (undefined4 *)(**(code **)(*(int *)*piVar5 + 0x2c))();
        }
        if (param_4 != (va_list)0x0) {
          uVar4 = *(uint *)(param_1 + 0xf0) - *(uint *)(param_1 + 0xe0);
          pcVar3 = (va_list)(*(int *)(param_1 + 0x24) >> 0x1f);
          uVar10 = __ll_div(uVar4 - *(uint *)(param_1 + 0xd0),
                            (((*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xe4)) -
                             (uint)(*(uint *)(param_1 + 0xf0) < *(uint *)(param_1 + 0xe0))) -
                            *(int *)(param_1 + 0xd4)) - (uint)(uVar4 < *(uint *)(param_1 + 0xd0)));
          param_3 = (undefined4 *)0x0;
          local_30 = uVar10;
          (**(code **)(*(int *)*piVar5 + 0x18))((int *)*piVar5,&local_30);
          local_44 = (va_list)0x0;
        }
        if (*(int *)(param_1 + 0x128) != 0) {
          (**(code **)(*(int *)*piVar5 + 0x40))((int *)*piVar5,1);
          *(undefined4 *)(param_1 + 0x128) = 0;
        }
        puVar7 = (undefined4 *)((int)puVar6 + (int)_Size);
        if (_Size_00 < puVar7) {
          if (puVar6 == (undefined4 *)0x0) {
            if (_Size <= _Size_00) goto LAB_40bc8c10;
            memcpy(local_48,param_2,(size_t)_Size_00);
            param_2 = (void *)((int)_Size_00 + (int)param_2);
            _Size = (undefined4 *)((int)_Size - (int)_Size_00);
            (**(code **)(*(int *)*piVar5 + 0x30))((int *)*piVar5,_Size_00);
            puVar6 = _Size_00;
          }
          local_40 = 0;
          local_3c = 0;
          local_38 = 0;
          local_34 = 0;
          param_3 = &local_40;
          (**(code **)(*(int *)*piVar5 + 0x14))((int *)*piVar5,&local_38);
          (**(code **)(**(int **)(iVar8 + 0xc) + 8))(*(int **)(iVar8 + 0xc),*piVar5);
          *piVar5 = 0;
        }
        else {
          param_3 = _Size;
          memcpy((void *)((int)puVar6 + (int)local_48),param_2,(size_t)_Size);
          param_2 = (void *)((int)param_2 + (int)_Size);
          _Size = (undefined4 *)0x0;
          (**(code **)(*(int *)*piVar5 + 0x30))((int *)*piVar5,puVar7);
          puVar6 = puVar7;
        }
LAB_40bc8c10:
        iVar1 = *(int *)(param_1 + 0x100);
        param_4 = local_44;
      }
    }
    else if (*(int **)(param_1 + 0x110) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x110) + 8))();
      *(undefined4 *)(param_1 + 0x110) = 0;
    }
    iVar8 = 0;
  }
  return iVar8;
}



/* 40bc8c94 FUN_40bc8c94 */

/* Boundary evidence: original MIPS .pdata 40bc8c94..40bc8da3. Semantic name remains unreviewed. */

undefined4 FUN_40bc8c94(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  va_list pcVar4;
  
  piVar3 = param_3;
  iVar1 = (**(code **)(*param_1 + 0x44))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
  pcVar4 = (va_list)(iVar1 + iVar2);
  if (pcVar4 != (va_list)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x44))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
    if (param_2 < iVar1 + iVar2) {
      if (param_3 != (int *)0x0) {
        iVar1 = (**(code **)(*param_1 + 0x44))(param_1);
        iVar2 = *param_3;
        if (param_2 < iVar1) {
          iVar1 = param_1[3];
        }
        else {
          iVar1 = param_1[5];
        }
        (**(code **)(**(int **)(iVar1 + 0xc) + 0x10))();
        if (*param_3 == 0) {
          FUN_40bc3b24(0x40bdb030,iVar2,piVar3,pcVar4);
          return 0x80004005;
        }
      }
      return 0;
    }
  }
  return 0x80004005;
}



/* 40bc8da4 FUN_40bc8da4 */

/* Boundary evidence: original MIPS .pdata 40bc8da4..40bc8e6f. Semantic name remains unreviewed. */

undefined4 FUN_40bc8da4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = param_2 * 8 + param_1;
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *(char *)(puVar1 + 1) = (char)param_2;
    puVar3 = puVar1 + 3;
    *puVar1 = &PTR_FUN_40bdac5c;
    puVar1[2] = 0;
    *puVar3 = 0;
    puVar1[4] = 0;
    puVar1[4] = *(undefined4 *)(iVar4 + 0xc);
    *(undefined4 **)(iVar4 + 0xc) = puVar1;
    (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 **)(param_1 + 8),param_3,puVar3);
    (**(code **)(*(int *)*puVar3 + 0xc))((int *)*puVar3,param_4);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bc8e70 FUN_40bc8e70 */

uint FUN_40bc8e70(undefined4 *param_1,uint param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  
  puVar11 = (undefined1 *)*param_1;
  if ((undefined1 *)param_1[1] <= puVar11) {
    return 0;
  }
  uVar8 = (uint)*(byte *)(param_1 + 3);
  if (uVar8 != 0) {
    if (uVar8 < param_2) {
      uVar6 = 0xffffffff;
      uVar9 = uVar6;
      if (uVar8 != 0x20) {
        uVar9 = (1 << (uVar8 & 0x1f)) - 1;
      }
      uVar8 = param_2 - uVar8;
      uVar5 = CONCAT31(CONCAT21(CONCAT11(*puVar11,puVar11[1]),puVar11[2]),puVar11[3]);
      uVar10 = param_1[4];
      *param_1 = puVar11 + 4;
      uVar7 = 0x20 - (uVar8 & 0xff);
      param_1[4] = uVar5;
      *(undefined1 *)((int)param_1 + 0xd) = 0;
      *(undefined1 *)(param_1 + 3) = 0x20;
      if ((uVar8 & 0xff) != 0x20) {
        uVar6 = (1 << (uVar8 & 0x1f)) + -1 << (uVar7 & 0x1f);
      }
      *(char *)((int)param_1 + 0xd) = (char)uVar8;
      *(char *)(param_1 + 3) = (char)uVar7;
      return (uVar6 & uVar5) >> (uVar7 & 0x1f) | (uVar10 & uVar9) << (uVar8 & 0x1f);
    }
    uVar8 = uVar8 - param_2;
    if (param_2 == 0x20) {
      uVar9 = 0xffffffff;
    }
    else {
      uVar9 = (1 << (param_2 & 0x1f)) + -1 << (uVar8 & 0x1f);
    }
    *(char *)(param_1 + 3) = (char)uVar8;
    *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0xd) + (char)param_2;
    return (param_1[4] & uVar9) >> (uVar8 & 0x1f);
  }
  uVar1 = *puVar11;
  uVar2 = puVar11[1];
  uVar3 = puVar11[2];
  uVar4 = puVar11[3];
  *param_1 = puVar11 + 4;
  uVar9 = CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4);
  uVar8 = 0x20 - param_2;
  param_1[4] = uVar9;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  *(undefined1 *)(param_1 + 3) = 0x20;
  if (param_2 != 0x20) {
    *(char *)((int)param_1 + 0xd) = (char)param_2;
    *(char *)(param_1 + 3) = (char)uVar8;
    return ((1 << (param_2 & 0x1f)) + -1 << (uVar8 & 0x1f) & uVar9) >> (uVar8 & 0x1f);
  }
  *(undefined1 *)((int)param_1 + 0xd) = 0x20;
  *(undefined1 *)(param_1 + 3) = 0;
  return uVar9;
}



/* 40bc9044 FUN_40bc9044 */

/* Boundary evidence: original MIPS .pdata 40bc9044..40bc90ef. Semantic name remains unreviewed. */

int FUN_40bc9044(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = 0;
  iVar3 = 1;
  uVar1 = FUN_40bc8e70(&DAT_40be0578,1);
  if (uVar1 == 0) {
    do {
      uVar2 = uVar2 + 1;
      uVar1 = FUN_40bc8e70(&DAT_40be0578,1);
    } while (uVar1 == 0);
    if (uVar2 == 0) goto LAB_40bc90cc;
    uVar4 = FUN_40bc8e70(&DAT_40be0578,uVar2 & 0xff);
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    iVar3 = iVar3 << 1;
  }
LAB_40bc90cc:
  return iVar3 + uVar4 + -1;
}



/* 40bc90f0 FUN_40bc90f0 */

/* Boundary evidence: original MIPS .pdata 40bc90f0..40bc91fb. Semantic name remains unreviewed. */

uint FUN_40bc90f0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar5 = 0;
  iVar4 = 1;
  uVar1 = FUN_40bc8e70(&DAT_40be0578,1);
  if (uVar1 == 0) {
    do {
      uVar3 = uVar3 + 1;
      uVar1 = FUN_40bc8e70(&DAT_40be0578,1);
    } while (uVar1 == 0);
    if (uVar3 != 0) {
      uVar5 = FUN_40bc8e70(&DAT_40be0578,uVar3 & 0xff);
    }
  }
  if (0 < (int)uVar3) {
    do {
      uVar3 = uVar3 - 1;
      iVar4 = iVar4 << 1;
    } while (uVar3 != 0);
  }
  uVar1 = (iVar4 + uVar5) - 1;
  if ((-1 < (int)uVar1) && ((int)uVar1 < 2)) {
    return uVar1;
  }
  uVar3 = uVar1 & 1;
  iVar4 = (int)(iVar4 + uVar5) >> 1;
  if ((int)uVar1 < 0) {
    if (uVar3 == 0) goto LAB_40bc91b0;
    uVar3 = uVar3 - 2;
  }
  if (uVar3 != 0) {
    iVar2 = (int)uVar1 >> 1;
    if ((int)uVar1 < 0) {
      iVar2 = iVar4;
    }
    return iVar2 + 1;
  }
LAB_40bc91b0:
  iVar2 = (int)uVar1 >> 1;
  if ((int)uVar1 < 0) {
    iVar2 = iVar4;
  }
  return -iVar2;
}



/* 40bc91fc FUN_40bc91fc */

/* Boundary evidence: original MIPS .pdata 40bc91fc..40bc9473. Semantic name remains unreviewed. */

undefined4 FUN_40bc91fc(int param_1,int param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint *puVar5;
  uint local_428 [256];
  undefined1 local_28 [8];
  uint local_20;
  
  local_20 = DAT_40be0550;
  DAT_40be057c = param_1 + param_2;
  DAT_40be0584 = 0;
  DAT_40be0585 = 0;
  DAT_40be0578 = param_1;
  DAT_40be0580 = param_1;
  uVar1 = FUN_40bc8e70(&DAT_40be0578,8);
  uVar1 = uVar1 & 0xff;
  FUN_40bc8e70(&DAT_40be0578,1);
  FUN_40bc8e70(&DAT_40be0578,1);
  FUN_40bc8e70(&DAT_40be0578,1);
  FUN_40bc8e70(&DAT_40be0578,1);
  FUN_40bc8e70(&DAT_40be0578,4);
  FUN_40bc8e70(&DAT_40be0578,8);
  FUN_40bc9044();
  if ((((uVar1 == 100) || (uVar1 == 0x6e)) || (uVar1 == 0x7a)) || (uVar1 == 0x90)) {
    iVar2 = FUN_40bc9044();
    if (iVar2 == 3) {
      FUN_40bc8e70(&DAT_40be0578,1);
    }
    FUN_40bc9044();
    FUN_40bc9044();
    FUN_40bc8e70(&DAT_40be0578,1);
    uVar1 = FUN_40bc8e70(&DAT_40be0578,1);
    if ((uVar1 & 0xff) != 0) {
      iVar2 = 0;
      do {
        uVar1 = FUN_40bc8e70(&DAT_40be0578,1);
        puVar4 = local_28 + iVar2;
        iVar2 = iVar2 + 1;
        *puVar4 = (char)uVar1;
      } while (iVar2 < 8);
    }
  }
  FUN_40bc9044();
  iVar2 = FUN_40bc9044();
  if (iVar2 == 0) {
    FUN_40bc9044();
  }
  else if (iVar2 == 1) {
    FUN_40bc8e70(&DAT_40be0578,1);
    FUN_40bc90f0();
    FUN_40bc90f0();
    iVar2 = FUN_40bc9044();
    if (0 < iVar2) {
      puVar5 = local_428;
      do {
        uVar1 = FUN_40bc90f0();
        iVar2 = iVar2 + -1;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
      } while (iVar2 != 0);
    }
  }
  FUN_40bc9044();
  FUN_40bc8e70(&DAT_40be0578,1);
  iVar2 = FUN_40bc9044();
  iVar3 = FUN_40bc9044();
  *param_3 = (iVar2 + 1) * 0x10;
  uVar1 = FUN_40bc8e70(&DAT_40be0578,1);
  *param_4 = (2 - (uVar1 & 0xff)) * (iVar3 + 1) * 0x10;
  FUN_40bd8bd0(local_20);
  return 0;
}



/* 40bc9474 FUN_40bc9474 */

/* Boundary evidence: original MIPS .pdata 40bc9474..40bc95ff. Semantic name remains unreviewed. */

void FUN_40bc9474(int param_1,uint param_2,int *param_3,int *param_4)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int local_res0;
  uint local_res4 [3];
  int local_30;
  int local_2c;
  int local_28;
  undefined1 local_24;
  undefined1 local_23;
  
  *param_3 = 0;
  *param_4 = 0;
  piVar3 = param_3;
  piVar4 = param_4;
  do {
    if (param_2 < 4) {
      return;
    }
    local_2c = param_1 + param_2;
    local_24 = 0;
    local_23 = 0;
    local_res0 = param_1;
    local_res4[0] = param_2;
    local_30 = param_1;
    local_28 = param_1;
    FUN_40bc8e70(&local_30,1);
    FUN_40bc8e70(&local_30,2);
    uVar2 = FUN_40bc8e70(&local_30,5);
    switch(uVar2 & 0xff) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0x13:
      bVar1 = FUN_40bc52e8(&local_res0,local_res4);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        return;
      }
      param_1 = local_res0 + 3;
      param_2 = local_res4[0] - 3;
      break;
    case 7:
      piVar3 = param_3;
      piVar4 = param_4;
      FUN_40bc91fc(param_1 + 1,param_2,param_3,param_4);
      param_1 = local_res0 + 3;
      param_2 = local_res4[0] - 3;
      if ((*param_3 != 0) && (*param_4 != 0)) {
        return;
      }
      break;
    default:
      FUN_40bc3b24(0x40bdb068,uVar2 & 0xff,piVar3,(va_list)piVar4);
      return;
    }
  } while( true );
}



/* 40bc9600 FUN_40bc9600 */

/* Boundary evidence: original MIPS .pdata 40bc9600..40bc98c3. Semantic name remains unreviewed. */

void FUN_40bc9600(int param_1,int param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int local_38;
  int local_34;
  int local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  
  local_34 = param_1 + param_2;
  *param_3 = 0;
  *param_4 = 0;
  local_2c = 0;
  local_2b = 0;
  local_38 = param_1;
  local_30 = param_1;
  FUN_40bc8e70(&local_38,1);
  FUN_40bc8e70(&local_38,8);
  uVar4 = 0;
  uVar1 = FUN_40bc8e70(&local_38,1);
  if (uVar1 != 0) {
    uVar4 = FUN_40bc8e70(&local_38,4);
    FUN_40bc8e70(&local_38,3);
  }
  uVar1 = FUN_40bc8e70(&local_38,4);
  if (uVar1 == 0xf) {
    FUN_40bc8e70(&local_38,8);
    FUN_40bc8e70(&local_38,8);
  }
  uVar1 = FUN_40bc8e70(&local_38,1);
  if (uVar1 != 0) {
    FUN_40bc8e70(&local_38,2);
    FUN_40bc8e70(&local_38,1);
    uVar1 = FUN_40bc8e70(&local_38,1);
    if (uVar1 != 0) {
      FUN_40bc8e70(&local_38,0xf);
      uVar1 = FUN_40bc8e70(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
      FUN_40bc8e70(&local_38,0xf);
      uVar1 = FUN_40bc8e70(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
      FUN_40bc8e70(&local_38,0xf);
      uVar1 = FUN_40bc8e70(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
      FUN_40bc8e70(&local_38,3);
      FUN_40bc8e70(&local_38,0xb);
      uVar1 = FUN_40bc8e70(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
      FUN_40bc8e70(&local_38,0xf);
      uVar1 = FUN_40bc8e70(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
    }
  }
  uVar1 = FUN_40bc8e70(&local_38,2);
  if (((uVar1 != 3) || (uVar4 == 1)) && (uVar4 = FUN_40bc8e70(&local_38,1), uVar4 == 1)) {
    uVar4 = FUN_40bc8e70(&local_38,0x10);
    uVar2 = FUN_40bc8e70(&local_38,1);
    if (uVar2 == 1) {
      uVar2 = FUN_40bc8e70(&local_38,1);
      uVar4 = uVar4 - 1;
      uVar3 = 1;
      if (uVar4 != 0) {
        do {
          if (uVar4 == 1) break;
          uVar3 = uVar3 + 1;
          uVar4 = uVar4 >> 1;
        } while (uVar3 < 0x10);
      }
      if (uVar2 != 0) {
        FUN_40bc8e70(&local_38,uVar3 & 0xff);
      }
      if ((uVar1 == 0) && (uVar1 = FUN_40bc8e70(&local_38,1), uVar1 == 1)) {
        uVar1 = FUN_40bc8e70(&local_38,0xd);
        *param_3 = uVar1;
        uVar1 = FUN_40bc8e70(&local_38,1);
        if (uVar1 == 1) {
          uVar1 = FUN_40bc8e70(&local_38,0xd);
          *param_4 = uVar1;
        }
      }
    }
  }
  return;
}



/* 40bc98c4 FUN_40bc98c4 */

/* Boundary evidence: original MIPS .pdata 40bc98c4..40bc9c53. Semantic name remains unreviewed. */

int FUN_40bc98c4(int param_1,undefined1 *param_2,uint param_3,int *param_4)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  va_list pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  char local_50;
  uint local_40;
  int local_3c;
  va_list local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  *param_4 = 0;
  iVar9 = 0;
  bVar1 = *(undefined **)(param_1 + 0x7c) != &DAT_40bdd638;
  uVar7 = param_3;
joined_r0x40bc992c:
  do {
    if (uVar7 < 5) {
LAB_40bc9c08:
      *param_4 = param_3 - uVar7;
      return 0;
    }
    cVar2 = param_2[3];
    uVar8 = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),cVar2);
    if (uVar8 != 0x1ba) {
      if ((uVar8 < 0x1bc) || (0x1ff < uVar8)) {
        uVar7 = uVar7 - 1;
        param_2 = param_2 + 1;
      }
      else {
        if (bVar1) {
          uVar8 = FUN_40bc61c4((int)param_2,uVar7,&local_40);
        }
        else {
          uVar8 = FUN_40bc5e8c(param_2,uVar7,&local_40);
        }
        pcVar5 = local_38;
        uVar4 = local_40;
        if (uVar8 == 0) goto LAB_40bc9c08;
        if (uVar8 == 4) {
          uVar7 = uVar7 - 4;
          param_2 = param_2 + 4;
        }
        else {
          cVar3 = *(char *)(param_1 + 0x118);
          if (cVar2 == cVar3) {
            if ((*(undefined **)(param_1 + 0x34) == &DAT_40bde248) && (local_34 == 0)) {
              local_50 = param_2[local_40];
            }
            if ((cVar2 == cVar3) &&
               ((*(int *)(param_1 + 0x140) != 0 || (*(int *)(param_1 + 0x144) != 0)))) {
              local_50 = param_2[local_40];
            }
          }
          if (cVar2 == *(char *)(param_1 + 0x11a)) {
            if (local_38 != (va_list)0x0) {
              lVar10 = __ll_div(local_30,local_2c,0x5a,0);
              *(longlong *)(param_1 + 0xf8) = lVar10 * 10000;
            }
            iVar6 = FUN_40bc829c(param_1,param_2 + uVar4,(int *)(local_3c - uVar4),pcVar5,0);
            if (iVar6 < 0) {
              return iVar6;
            }
          }
          else if ((cVar2 == cVar3) &&
                  ((cVar3 != -0x43 ||
                   (((*(int *)(param_1 + 0x140) != 0 || (*(int *)(param_1 + 0x144) != 0)) &&
                    (local_50 == *(char *)(param_1 + 0x119))))))) {
            if (local_38 != (va_list)0x0) {
              lVar10 = __ll_div(local_30,local_2c,0x5a,0);
              *(longlong *)(param_1 + 0xf0) = lVar10 * 10000;
            }
            iVar9 = FUN_40bc87ac(param_1,param_2 + uVar4,(undefined4 *)(local_3c - uVar4),pcVar5,0);
          }
          if (iVar9 < 0) {
            return iVar9;
          }
          uVar7 = uVar7 - local_3c;
          param_2 = param_2 + local_3c;
        }
      }
      goto joined_r0x40bc992c;
    }
    if (bVar1) {
      if (((uVar7 < 0xe) || (uVar8 = ((byte)param_2[0xd] & 7) + 0xe, uVar7 < uVar8)) || (uVar8 == 0)
         ) goto LAB_40bc9c44;
      uVar7 = uVar7 - uVar8;
      param_2 = param_2 + uVar8;
    }
    else {
      if ((uVar7 < 0xc) || (uVar7 < 0x10)) {
LAB_40bc9c44:
        uVar7 = 0;
        goto LAB_40bc9c08;
      }
      uVar7 = uVar7 - 0xc;
      param_2 = param_2 + 0xc;
    }
  } while( true );
}



/* 40bc9c54 FUN_40bc9c54 */

/* Boundary evidence: original MIPS .pdata 40bc9c54..40bca2e7. Semantic name remains unreviewed. */

int FUN_40bc9c54(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 *_Dst;
  undefined4 uVar7;
  void *_Buf1;
  int iVar8;
  undefined *puVar9;
  undefined4 auStack_70 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_28;
  
  local_28 = DAT_40be0550;
  iVar8 = -0x7fffbffb;
  iVar4 = memcmp(*(void **)(param_1 + 0x30),&DAT_40bdd2f8,0x10);
  if (iVar4 == 0) {
    FUN_40bd63b4(auStack_70,(undefined4 *)&DAT_40bdd2f8);
    _Buf1 = *(void **)(param_1 + 0x34);
    iVar4 = memcmp(_Buf1,&DAT_40bde238,0x10);
    if (iVar4 == 0) {
      local_60 = 0xe06d802b;
      local_5c = 0x11cfdb46;
      local_58 = 0x8000d1b4;
      local_54 = 0xeabb6c5f;
      FUN_40bd6164((int)auStack_70,&DAT_40bddeb8);
      FUN_40bd6570((int)auStack_70,*(int *)(param_1 + 0x58));
      puVar5 = FUN_40bd6188((int)auStack_70,0x12);
      memset(puVar5,0,0x12);
      iVar4 = *(int *)(param_1 + 0x74);
      cVar1 = *(char *)(iVar4 + 3);
      cVar2 = *(char *)(iVar4 + 2);
      puVar5[0x10] = 0;
      if (cVar2 == '\0' && cVar1 == '\0') {
        *puVar5 = 0x50;
        puVar5[1] = 0;
        puVar5[0x11] = 0;
        puVar5[2] = 2;
        *(undefined4 *)(puVar5 + 8) = 48000;
        puVar5[3] = 0;
        *(undefined4 *)(puVar5 + 4) = 0xac44;
        puVar5[0xc] = 1;
        puVar5[0xd] = 0;
      }
      else {
        *puVar5 = 0x50;
        puVar5[0x11] = 0;
        puVar5[1] = 0;
        uVar3 = *(undefined1 *)(iVar4 + 3);
        puVar5[2] = *(undefined1 *)(iVar4 + 2);
        puVar5[3] = uVar3;
        *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(iVar4 + 4);
        *(undefined4 *)(puVar5 + 8) = *(undefined4 *)(iVar4 + 8);
        puVar5[0xd] = 0;
        puVar5[0xc] = 1;
        uVar3 = *(undefined1 *)(iVar4 + 0xf);
        puVar5[0xe] = *(undefined1 *)(iVar4 + 0xe);
        puVar5[0xf] = uVar3;
      }
    }
    else {
      iVar4 = memcmp(_Buf1,&DAT_40bde248,0x10);
      if (iVar4 == 0) {
        FUN_40bd6140((int)auStack_70,(undefined4 *)&DAT_40bde248);
        FUN_40bd6164((int)auStack_70,&DAT_40bddeb8);
        FUN_40bd6570((int)auStack_70,*(int *)(param_1 + 0x58));
        puVar5 = FUN_40bd6188((int)auStack_70,0x17);
        memset(puVar5,0,0x17);
        iVar8 = *(int *)(param_1 + 0x74);
        puVar5[0x10] = 5;
        puVar5[0x11] = 0;
        puVar5[0x12] = *(undefined1 *)(iVar8 + 0x12);
        *(int *)(puVar5 + 4) = *(int *)(iVar8 + 4);
        iVar4 = *(int *)(iVar8 + 8);
        *(int *)(puVar5 + 8) = iVar4;
        uVar6 = MulDiv(0x600,iVar4,*(int *)(puVar5 + 4));
        puVar5[0xd] = (char)((uVar6 & 0xffff) >> 8);
        puVar5[0xc] = (char)(uVar6 & 0xffff);
        uVar3 = *(undefined1 *)(iVar8 + 3);
        puVar5[2] = *(undefined1 *)(iVar8 + 2);
        puVar5[3] = uVar3;
        *puVar5 = 0;
        puVar5[1] = 0x20;
      }
      else {
        iVar4 = memcmp(_Buf1,&DAT_40bdc350,0x10);
        if (iVar4 == 0) {
          FUN_40bd6140((int)auStack_70,(undefined4 *)&DAT_40bdc350);
          FUN_40bd6164((int)auStack_70,&DAT_40bddeb8);
          FUN_40bd6570((int)auStack_70,*(int *)(param_1 + 0x58));
          puVar5 = FUN_40bd6188((int)auStack_70,0x12);
          memset(puVar5,0,0x12);
          iVar4 = *(int *)(param_1 + 0x74);
          puVar5[0x11] = 0;
          puVar5[0x10] = 0;
          uVar3 = *(undefined1 *)(iVar4 + 2);
          puVar5[3] = *(undefined1 *)(iVar4 + 3);
          puVar5[2] = uVar3;
          *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(iVar4 + 4);
          puVar5[0xe] = 0x10;
          puVar5[0xf] = 0;
          *puVar5 = 0xff;
          puVar5[1] = 0;
          *(undefined4 *)(puVar5 + 8) = *(undefined4 *)(iVar4 + 8);
        }
        else {
          iVar4 = memcmp(_Buf1,&DAT_40bdc210,0x10);
          if (iVar4 == 0) {
            FUN_40bd6140((int)auStack_70,(undefined4 *)&DAT_40bdc210);
            FUN_40bd6164((int)auStack_70,&DAT_40bddeb8);
            FUN_40bd6570((int)auStack_70,*(int *)(param_1 + 0x58));
            puVar5 = FUN_40bd6188((int)auStack_70,0x12);
            memset(puVar5,0,0x12);
            iVar4 = *(int *)(param_1 + 0x74);
            puVar5[0x11] = 0;
            puVar5[0x10] = 0;
            uVar3 = *(undefined1 *)(iVar4 + 2);
            puVar5[3] = *(undefined1 *)(iVar4 + 3);
            puVar5[2] = uVar3;
            *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(iVar4 + 4);
            puVar5[0xe] = 0x10;
            puVar5[0xf] = 0;
            *puVar5 = 0x4f;
            puVar5[1] = 0x67;
          }
          else {
            puVar9 = &DAT_40bdc290;
            uVar7 = 0x10;
            iVar4 = memcmp(_Buf1,&DAT_40bdc290,0x10);
            if (iVar4 != 0) {
              FUN_40bc3b24(0x40bdb094,puVar9,uVar7,param_4);
              FUN_40bd6358((int)auStack_70);
              FUN_40bd8bd0(local_28);
              return -0x7fffbffb;
            }
            puVar5 = *(undefined1 **)(param_1 + 0x74);
            if (puVar5[2] == '\0' && puVar5[3] == '\0') {
              FUN_40bd6358((int)auStack_70);
              FUN_40bd8bd0(local_28);
              return 0x40258;
            }
            FUN_40bd6140((int)auStack_70,(undefined4 *)&DAT_40bdc290);
            FUN_40bd6164((int)auStack_70,&DAT_40bddeb8);
            FUN_40bd6570((int)auStack_70,*(int *)(param_1 + 0x58));
            _Dst = FUN_40bd6188((int)auStack_70,0x12);
            memset(_Dst,0,0x12);
            _Dst[0x11] = 0;
            _Dst[0x10] = 0;
            uVar3 = puVar5[3];
            _Dst[2] = puVar5[2];
            _Dst[3] = uVar3;
            *(undefined4 *)(_Dst + 4) = *(undefined4 *)(puVar5 + 4);
            uVar3 = puVar5[0xf];
            _Dst[0xe] = puVar5[0xe];
            _Dst[0xf] = uVar3;
            uVar3 = puVar5[1];
            *_Dst = *puVar5;
            _Dst[1] = uVar3;
            uVar3 = puVar5[0xd];
            _Dst[0xc] = puVar5[0xc];
            _Dst[0xd] = uVar3;
          }
        }
      }
    }
    iVar8 = FUN_40bc8da4(param_1,1,L"Audio",auStack_70);
    if (-1 < iVar8) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    }
    FUN_40bd6358((int)auStack_70);
  }
  FUN_40bd8bd0(local_28);
  return iVar8;
}



/* 40bca2e8 FUN_40bca2e8 */

/* Boundary evidence: original MIPS .pdata 40bca2e8..40bca317. Semantic name remains unreviewed. */

void FUN_40bca2e8(void)

{
  int in_v0;
  
  FUN_40bd6358(in_v0 + -0x70);
  return;
}



/* 40bca318 FUN_40bca318 */

/* Boundary evidence: original MIPS .pdata 40bca318..40bca6af. Semantic name remains unreviewed. */

int FUN_40bca318(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 uVar3;
  size_t _Size;
  void *_Buf1;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 auStack_70 [18];
  uint local_28;
  
  local_28 = DAT_40be0550;
  iVar4 = -0x7fffbffb;
  iVar1 = memcmp(*(void **)(param_1 + 0x78),&DAT_40bdd2e8,0x10);
  if (iVar1 == 0) {
    FUN_40bd63b4(auStack_70,(undefined4 *)&DAT_40bdd2e8);
    _Buf1 = *(void **)(param_1 + 0x7c);
    puVar6 = (undefined4 *)&DAT_40bdd638;
    iVar1 = memcmp(_Buf1,&DAT_40bdd638,0x10);
    if ((iVar1 == 0) || (iVar1 = memcmp(_Buf1,&DAT_40bde1e8,0x10), iVar1 == 0)) {
      iVar1 = memcmp(_Buf1,&DAT_40bdd638,0x10);
      if (iVar1 != 0) {
        puVar6 = (undefined4 *)&DAT_40bde1e8;
      }
      FUN_40bd6140((int)auStack_70,puVar6);
      FUN_40bd6164((int)auStack_70,&DAT_40bde2c8);
      FUN_40bd6570((int)auStack_70,*(int *)(param_1 + 0xa0));
      iVar5 = *(int *)(param_1 + 0xbc);
      pvVar2 = FUN_40bd6188((int)auStack_70,*(int *)(iVar5 + 0x74) + 0x88);
      memset(pvVar2,0,0x88);
      iVar1 = *(int *)(iVar5 + 0x4c);
      *(int *)((int)pvVar2 + 0x4c) = iVar1;
      iVar4 = *(int *)(iVar5 + 0x50);
      *(undefined4 *)((int)pvVar2 + 0x48) = 0x28;
      *(int *)((int)pvVar2 + 0x50) = iVar4;
      *(undefined2 *)((int)pvVar2 + 0x54) = 1;
      iVar1 = iVar4 * iVar1 * 0x10;
      *(undefined2 *)((int)pvVar2 + 0x56) = 0x10;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 7;
      }
      *(int *)((int)pvVar2 + 0x5c) = iVar1 >> 3;
      _Size = *(size_t *)(iVar5 + 0x74);
      *(size_t *)((int)pvVar2 + 0x74) = _Size;
      memcpy((void *)((int)pvVar2 + 0x84),(void *)(iVar5 + 0x84),_Size);
    }
    else {
      iVar1 = memcmp(_Buf1,&DAT_40bdc3d0,0x10);
      if (iVar1 == 0) {
        FUN_40bd6140((int)auStack_70,(undefined4 *)&DAT_40bdc3d0);
        FUN_40bd6164((int)auStack_70,&DAT_40bdbfb0);
        FUN_40bd6570((int)auStack_70,*(int *)(param_1 + 0xa0));
        pvVar2 = FUN_40bd6188((int)auStack_70,0x60);
        memset(pvVar2,0,0x60);
        iVar1 = *(int *)(param_1 + 0xbc);
        *(undefined4 *)((int)pvVar2 + 0x40) = 0x5434504d;
        *(undefined4 *)((int)pvVar2 + 0x30) = 0x28;
        iVar4 = *(int *)(iVar1 + 0x38);
        *(int *)((int)pvVar2 + 0x38) = iVar4;
        iVar1 = *(int *)(iVar1 + 0x34);
        *(undefined2 *)((int)pvVar2 + 0x3c) = 1;
        *(int *)((int)pvVar2 + 0x34) = iVar1;
        *(undefined2 *)((int)pvVar2 + 0x3e) = 0x10;
        iVar1 = iVar1 * iVar4 * 0x10;
        if (iVar1 < 0) {
          iVar1 = iVar1 + 7;
        }
        *(int *)((int)pvVar2 + 0x44) = iVar1 >> 3;
        *(undefined4 *)((int)pvVar2 + 0x58) = 0x60;
      }
      else {
        puVar7 = &DAT_40bdc510;
        uVar3 = 0x10;
        iVar1 = memcmp(_Buf1,&DAT_40bdc510,0x10);
        if (iVar1 != 0) {
          FUN_40bc3b24(0x40bdb184,puVar7,uVar3,param_4);
          FUN_40bd6358((int)auStack_70);
          FUN_40bd8bd0(local_28);
          return -0x7fffbffb;
        }
        FUN_40bd6140((int)auStack_70,(undefined4 *)&DAT_40bdc510);
        FUN_40bd6164((int)auStack_70,&DAT_40bdbfb0);
        FUN_40bd6570((int)auStack_70,*(int *)(param_1 + 0xa0));
        pvVar2 = FUN_40bd6188((int)auStack_70,0x60);
        memset(pvVar2,0,0x60);
        iVar1 = *(int *)(param_1 + 0xbc);
        *(undefined4 *)((int)pvVar2 + 0x40) = 0x34363248;
        *(undefined4 *)((int)pvVar2 + 0x30) = 0x28;
        *(undefined4 *)((int)pvVar2 + 0x38) = *(undefined4 *)(iVar1 + 0x38);
        *(undefined4 *)((int)pvVar2 + 0x34) = *(undefined4 *)(iVar1 + 0x34);
        *(undefined2 *)((int)pvVar2 + 0x3c) = 1;
        *(undefined4 *)((int)pvVar2 + 0x58) = 0x60;
      }
    }
    iVar4 = FUN_40bc8da4(param_1,0,L"Video",auStack_70);
    if (-1 < iVar4) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    }
    FUN_40bd6358((int)auStack_70);
  }
  FUN_40bd8bd0(local_28);
  return iVar4;
}



/* 40bca6b0 FUN_40bca6b0 */

/* Boundary evidence: original MIPS .pdata 40bca6b0..40bca6df. Semantic name remains unreviewed. */

void FUN_40bca6b0(void)

{
  int in_v0;
  
  FUN_40bd6358(in_v0 + -0x70);
  return;
}



/* 40bca6e0 FUN_40bca6e0 */

/* WARNING: Removing unreachable block (ram,0x40bcae74) */
/* WARNING: Removing unreachable block (ram,0x40bcb6bc) */
/* Boundary evidence: original MIPS .pdata 40bca6e0..40bcc073. Semantic name remains unreviewed. */

undefined4 FUN_40bca6e0(int param_1,uint *param_2,undefined4 param_3,uint *param_4)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined3 extraout_var;
  void *_Dst;
  void *pvVar6;
  byte *pbVar7;
  byte **ppbVar8;
  uint *puVar9;
  undefined4 uVar10;
  uint *puVar11;
  undefined4 uVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  longlong lVar21;
  uint *local_218;
  byte *local_214;
  uint *local_210;
  int local_20c;
  uint local_204;
  uint local_200;
  undefined *local_1fc;
  int local_1f8;
  uint local_1f4;
  uint local_1f0;
  uint *local_1ec;
  uint local_1e8;
  uint local_1e4;
  byte *local_1e0;
  int local_1dc;
  int local_1d8;
  uint local_1d0;
  int local_1cc;
  uint *local_1c8;
  uint local_1c0;
  uint local_1bc;
  int local_1b8;
  undefined4 local_1b0;
  undefined4 local_1ac;
  uint auStack_1a8 [6];
  undefined1 auStack_190 [24];
  uint auStack_178 [2];
  int local_170;
  undefined4 local_16c;
  uint *local_138;
  uint auStack_134 [65];
  uint local_30;
  
  local_30 = DAT_40be0550;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  iVar16 = 0;
  uVar17 = 0;
  uVar15 = 0;
  iVar20 = 0;
  iVar19 = 0;
  local_1e0 = (byte *)0x0;
  local_210 = (uint *)0x0;
  local_20c = 0;
  local_1f0 = 0;
  local_1f8 = 0;
  local_1dc = 0;
  local_204 = 0;
  local_1d8 = 0;
  local_1e4 = 0;
  local_1e8 = 0;
  local_200 = 0;
  local_1f4 = 0;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = param_2;
  iVar3 = (**(code **)*param_2)(param_2,&local_1d0);
  if (-1 < iVar3) {
    param_4 = (uint *)0x0;
    iVar3 = (**(code **)(*param_2 + 8))(param_2);
    if (-1 < iVar3) {
      uVar10 = 0xc0000;
      ppbVar8 = &local_1e0;
      local_210 = (uint *)FUN_40bcd02c(param_1,ppbVar8,0xc0000,(int *)param_2);
      param_4 = param_2;
      if ((local_1e0 == (byte *)0x0) && (local_210 == (uint *)0x0)) {
        FUN_40bc3b24(0x40bdb248,ppbVar8,uVar10,(va_list)param_2);
        FUN_40bd8bd0(local_30);
        return 0x80004005;
      }
    }
  }
  local_214 = local_1e0;
  memset((void *)(param_1 + 0x30),0,0x48);
  memset((void *)(param_1 + 0x78),0,0x48);
  memset(auStack_190,0,0x17);
  memset(auStack_1a8,0,0x12);
  memset(auStack_178,0,0x148);
  local_218 = local_210;
  if ((uint *)0x4 < local_210) {
    local_1fc = &DAT_40bdc3d0;
    do {
      pbVar14 = local_214 + 1;
      param_4 = (uint *)0x10000;
      uVar18 = CONCAT31(CONCAT21(CONCAT11(*local_214,*pbVar14),local_214[2]),local_214[3]);
      puVar11 = (uint *)0x100;
      if (uVar18 == 0x1ba) {
        if ((local_214[4] & 0xc0) == 0x40) {
          *(undefined4 *)(param_1 + 0x28) = 2;
          goto joined_r0x40bcb41c;
        }
        if ((local_214[4] & 0xf0) == 0x20) {
          *(undefined4 *)(param_1 + 0x28) = 1;
          goto joined_r0x40bca914;
        }
      }
      else if (uVar18 == 0x1b3) {
        iVar3 = FUN_40bc4fe0(local_214,6,(int)auStack_178,(va_list)0x10000);
        if (iVar3 != 0) {
          local_1dc = local_1dc + 1;
        }
      }
      else if (uVar18 == 0x100) {
        local_1d8 = local_1d8 + 1;
      }
      else if (uVar18 == 0x1b5) {
        if (local_1dc == 1) {
          local_1e4 = 1;
        }
        else {
LAB_40bcab00:
          if (((iVar19 < 9) && (iVar20 < 0xf)) && (local_1f4 == 0)) {
            local_1f4 = 1;
            local_1f0 = 0;
            puVar11 = (uint *)0x2000;
            puVar9 = (uint *)0x0;
            local_1ec = (uint *)0x10000;
            pbVar13 = local_214;
            if (local_218 < (uint *)0x10000) {
              if (local_218 < (uint *)0x2000) {
                puVar11 = local_218;
              }
              uVar15 = local_200;
              uVar17 = local_204;
              local_1ec = local_218;
              if (local_218 == (uint *)0x0) goto LAB_40bca9d4;
            }
            do {
              pbVar7 = pbVar13;
              param_4 = puVar11;
              FUN_40bc7cd8(param_1,uVar18,(char *)pbVar13,(int)puVar11,(int *)&local_1f0);
              if ((int)local_1f0 < 2) {
                param_4 = auStack_1a8;
                iVar16 = FUN_40bc5948(pbVar13,(uint)puVar11,&local_1f0,(undefined1 *)param_4);
                if ((iVar16 == 1) && (2 < (int)local_1f0)) {
                  local_1e8 = 1;
                  iVar20 = local_1f0 + iVar20;
                }
              }
              else {
                iVar19 = iVar19 + local_1f0;
                if (local_200 == 0) {
                  local_200 = 1;
                  iVar16 = 0;
                  do {
                    if (((pbVar14[iVar16 + -1] == 0xb) && (pbVar14[iVar16] == 0x77)) ||
                       ((pbVar14[iVar16 + -1] == 0x77 && (pbVar14[iVar16] == 0xb)))) {
                      FUN_40bc5348((char *)(local_214 + iVar16),(int)auStack_190,pbVar7,
                                   (va_list)param_4);
                      break;
                    }
                    iVar16 = iVar16 + 1;
                  } while (iVar16 != -1);
                }
              }
              puVar9 = (uint *)((int)puVar9 + (int)puVar11);
              uVar15 = local_200;
              iVar16 = local_20c;
              uVar17 = local_204;
              if ((3 < iVar19) || (0xe < iVar20)) {
                if (iVar19 <= iVar20) {
                  iVar19 = 0;
                }
                break;
              }
              pbVar13 = (byte *)((int)puVar11 + (int)pbVar13);
            } while (puVar9 < local_1ec);
          }
        }
      }
      else if ((uVar18 == 0x1e0) || (uVar18 == 0x1e1)) {
        local_204 = uVar17 + 1;
        uVar17 = local_204;
      }
      else {
        if (uVar18 != 0x1b6) goto LAB_40bcab00;
        local_20c = iVar16 + 1;
        iVar16 = local_20c;
      }
LAB_40bca9d4:
      puVar11 = (uint *)((int)local_218 + -1);
      if ((local_1e4 != 0) && ((int)uVar17 < 6)) break;
      if ((iVar16 < 6) || (*(int *)(param_1 + 0x78) != 0)) {
        if (((((uVar15 != 0) && (iVar16 < 6)) && (local_1e4 == 0)) &&
            (((int)uVar17 < 6 && (3 < iVar19)))) ||
           (((local_1e8 != 0 &&
             ((((iVar16 < 6 && (local_1e4 == 0)) && (iVar19 == 0)) &&
              (((int)uVar17 < 6 && (0xe < iVar20)))))) &&
            ((uint *)((int)local_218 + 0x3fff) < local_210)))) break;
      }
      else {
        *(int *)(param_1 + 0x78) = (int)&DAT_40bdd2e8;
        *(undefined **)(param_1 + 0x7c) = local_1fc;
        pvVar6 = malloc(0x60);
        uVar12 = 0x60;
        uVar10 = 0;
        memset(pvVar6,0,0x60);
        *(undefined4 *)(param_1 + 0xa8) = 0x5589f90;
        *(undefined4 *)(param_1 + 0xac) = 0x11cec356;
        *(undefined4 *)(param_1 + 0xb0) = 0xaa0001bf;
        *(undefined4 *)(param_1 + 0xb8) = 0x60;
        *(undefined4 *)(param_1 + 0xa0) = 0x20000;
        *(undefined4 *)(param_1 + 0xa4) = 0x20;
        *(undefined4 *)(param_1 + 0xb4) = 0x5a595500;
        *(void **)(param_1 + 0xbc) = pvVar6;
        *(undefined4 *)((int)pvVar6 + 0x30) = 0x28;
        FUN_40bca318(param_1,uVar10,uVar12,(va_list)param_4);
      }
      local_218 = puVar11;
      local_214 = pbVar14;
      if (puVar11 < (uint *)0x5) break;
    } while( true );
  }
  goto LAB_40bcbe90;
joined_r0x40bca914:
  if (local_218 < (uint *)0x5) goto LAB_40bcbe90;
  pbVar14 = local_214 + 2;
  bVar1 = local_214[3];
  uVar15 = CONCAT31(CONCAT21(CONCAT11(*local_214,local_214[1]),*pbVar14),bVar1);
  if (uVar15 != 0x1ba) {
    if (uVar15 == 0x1bb) {
      uVar15 = FUN_40bc4e9c((int)local_214,(uint)local_218,puVar11,(va_list)param_4);
      if (4 < uVar15) {
        local_218 = (uint *)((int)local_218 - uVar15);
        local_214 = local_214 + uVar15;
        goto joined_r0x40bca914;
      }
joined_r0x40bcb3e4:
      if (uVar15 == 0) goto LAB_40bcbe90;
    }
    else if ((0x1bb < uVar15) && (uVar15 < 0x200)) {
      puVar11 = &local_1c0;
      uVar15 = FUN_40bc5e8c(local_214,(uint)local_218,puVar11);
      if (local_1b8 != 0) {
        local_1f8 = local_1f8 + 1;
        param_4 = (uint *)0x0;
        puVar11 = (uint *)0x5a;
        lVar21 = __ll_div(local_1b0,local_1ac);
        if (((*(uint *)(param_1 + 0xd0) & *(uint *)(param_1 + 0xd4)) == 0xffffffff) ||
           (lVar21 * 10000 < *(longlong *)(param_1 + 0xd0))) {
          *(longlong *)(param_1 + 0xd0) = lVar21 * 10000;
        }
      }
      if (uVar15 < 5) goto joined_r0x40bcb3e4;
      if ((bVar1 & 0xf0) == 0xe0) {
        if (*(int *)(param_1 + 0x78) == 0) {
          *(byte *)(param_1 + 0x11a) = bVar1;
          uVar17 = uVar15;
          do {
            pbVar7 = pbVar14 + -2;
            pbVar13 = pbVar14 + -1;
            bVar1 = *pbVar14;
            pbVar14 = pbVar14 + 1;
            if (CONCAT31(CONCAT21(CONCAT11(*pbVar7,*pbVar13),bVar1),*pbVar14) == 0x1b3) {
              puVar11 = auStack_178;
              iVar16 = FUN_40bc4fe0(pbVar7,uVar17,(int)puVar11,(va_list)param_4);
              if ((iVar16 != 0) && (local_170 != 0)) {
                pvVar6 = malloc((size_t)(local_138 + 0x22));
                memset(pvVar6,0,0x88);
                *(undefined **)(param_1 + 0x78) = &DAT_40bdd2e8;
                *(undefined **)(param_1 + 0x7c) = &DAT_40bdd638;
                *(undefined4 *)(param_1 + 0xa8) = 0xe06d80e3;
                *(undefined4 *)(param_1 + 0xac) = 0x11cfdb46;
                *(undefined4 *)(param_1 + 0xb0) = 0x8000d1b4;
                *(undefined4 *)(param_1 + 0xb8) = 0x88;
                *(undefined4 *)(param_1 + 0xa0) = 0x4000;
                *(undefined4 *)(param_1 + 0xa4) = 0x80;
                *(undefined4 *)(param_1 + 0xb4) = 0xeabb6c5f;
                *(void **)(param_1 + 0xbc) = pvVar6;
                *(undefined4 *)((int)pvVar6 + 0x48) = 0x28;
                *(int *)((int)pvVar6 + 0x4c) = local_170;
                *(undefined4 *)((int)pvVar6 + 0x50) = local_16c;
                puVar9 = auStack_134;
                puVar11 = local_138;
                memcpy((void *)((int)pvVar6 + 0x84),puVar9,(size_t)local_138);
                *(uint **)((int)pvVar6 + 0x74) = local_138;
                FUN_40bca318(param_1,puVar9,puVar11,(va_list)param_4);
                break;
              }
            }
            uVar17 = uVar17 - 1;
          } while (3 < uVar17);
          goto LAB_40bcb250;
        }
      }
      else {
        if ((((bVar1 & 0xe0) == 0xc0) || (bVar1 == 0xbd)) && (*(int *)(param_1 + 0x30) == 0)) {
          *(byte *)(param_1 + 0x118) = bVar1;
          pbVar14 = local_214 + local_1c0;
          *(byte *)(param_1 + 0x119) = *pbVar14;
          if (bVar1 == 0xbd) {
            if ((*pbVar14 & 0xf8) == 0x80) {
              uVar17 = 0;
              if (uVar15 != 5) {
                do {
                  if (((pbVar14[uVar17 + 4] == 0xb) && (pbVar14[uVar17 + 5] == 0x77)) ||
                     ((pbVar14[uVar17 + 4] == 0x77 && (pbVar14[uVar17 + 5] == 0xb)))) {
                    *(undefined4 *)(param_1 + 0x140) = 1;
                    puVar4 = malloc(0x17);
                    puVar11 = (uint *)0x17;
                    memset(puVar4,0,0x17);
                    puVar5 = puVar4;
                    FUN_40bc5348((char *)(pbVar14 + uVar17 + 4),(int)puVar4,puVar11,(va_list)param_4
                                );
                    *(undefined **)(param_1 + 0x34) = &DAT_40bde248;
                    *(undefined **)(param_1 + 0x30) = &DAT_40bdd2f8;
                    *(undefined4 *)(param_1 + 0x60) = 0x5589f81;
                    *(undefined4 *)(param_1 + 100) = 0x11cec356;
                    *(undefined4 *)(param_1 + 0x68) = 0xaa0001bf;
                    *(undefined4 *)(param_1 + 0x70) = 0x17;
                    *(undefined4 *)(param_1 + 0x58) = 0x800;
                    *(undefined4 *)(param_1 + 0x6c) = 0x5a595500;
                    *(undefined1 **)(param_1 + 0x74) = puVar4;
                    *(undefined4 *)(param_1 + 0x5c) = 0x40;
                    goto LAB_40bcb138;
                  }
                  uVar17 = uVar17 + 1;
                } while (uVar17 < uVar15 - 5);
              }
            }
            else if ((*pbVar14 & 0xf8) == 0xa0) {
              puVar4 = malloc(0x12);
              puVar11 = (uint *)0x12;
              memset(puVar4,0,0x12);
              puVar5 = puVar4;
              iVar16 = FUN_40bc55a0((char *)pbVar14,puVar4);
              if (iVar16 == 1) {
                *(undefined **)(param_1 + 0x30) = &DAT_40bdd2f8;
                *(undefined **)(param_1 + 0x34) = &DAT_40bdc290;
                *(undefined4 *)(param_1 + 0x60) = 0x5589f81;
                *(undefined4 *)(param_1 + 100) = 0x11cec356;
                *(undefined4 *)(param_1 + 0x68) = 0xaa0001bf;
                *(undefined4 *)(param_1 + 0x70) = 0x12;
                *(undefined4 *)(param_1 + 0x58) = 0x4000;
                *(undefined4 *)(param_1 + 0x6c) = 0x5a595500;
                *(undefined1 **)(param_1 + 0x74) = puVar4;
                *(undefined4 *)(param_1 + 0x5c) = 0x40;
                *(undefined4 *)(param_1 + 0x144) = 1;
                FUN_40bc9c54(param_1,puVar5,puVar11,(va_list)param_4);
              }
              else {
LAB_40bcb138:
                FUN_40bc9c54(param_1,puVar5,puVar11,(va_list)param_4);
              }
            }
          }
          else if (*(int *)(param_1 + 0x134) == 0) {
            puVar5 = malloc(0x12);
            puVar11 = (uint *)0x12;
            memset(puVar5,0,0x12);
            uVar17 = 0;
            if (uVar15 != 1) {
              do {
                if ((pbVar14[uVar17] == 0xff) &&
                   (puVar4 = puVar5, iVar16 = FUN_40bc56e8(pbVar14 + uVar17,puVar5), iVar16 != 0)) {
                  *(undefined4 **)(param_1 + 0x34) = &DAT_40bde238;
                  *(undefined **)(param_1 + 0x30) = &DAT_40bdd2f8;
                  *(undefined4 *)(param_1 + 0x60) = 0x5589f81;
                  *(undefined4 *)(param_1 + 100) = 0x11cec356;
                  *(undefined4 *)(param_1 + 0x68) = 0xaa0001bf;
                  *(undefined4 *)(param_1 + 0x70) = 0x12;
                  *(undefined4 *)(param_1 + 0x6c) = 0x5a595500;
                  *(undefined1 **)(param_1 + 0x74) = puVar5;
                  uVar17 = *(uint *)(puVar5 + 8);
                  if (uVar17 < 4000) {
                    uVar10 = 0x200;
                  }
                  else if (uVar17 < 8000) {
                    uVar10 = 0x400;
                  }
                  else if (uVar17 < 0x61a9) {
                    uVar10 = 0x800;
                  }
                  else {
                    uVar10 = 0xc00;
                  }
                  *(undefined4 *)(param_1 + 0x58) = uVar10;
                  *(undefined4 *)(param_1 + 0x5c) = 0x40;
                  FUN_40bc9c54(param_1,puVar4,puVar11,(va_list)param_4);
                  break;
                }
                uVar17 = uVar17 + 1;
              } while (uVar17 < uVar15 - 1);
            }
          }
          else {
            puVar9 = malloc(0x12);
            memset(puVar9,0,0x12);
            uVar17 = local_1bc;
            puVar11 = puVar9;
            iVar16 = FUN_40bc5db0((char *)pbVar14,local_1bc,(undefined1 *)puVar9);
            if (iVar16 != 0) {
              *(undefined **)(param_1 + 0x30) = &DAT_40bdd2f8;
              *(undefined **)(param_1 + 0x34) = &DAT_40bdc350;
              *(undefined4 *)(param_1 + 0x60) = 0x5589f81;
              *(undefined4 *)(param_1 + 100) = 0x11cec356;
              *(undefined4 *)(param_1 + 0x68) = 0xaa0001bf;
              *(undefined4 *)(param_1 + 0x70) = 0x12;
              *(undefined4 *)(param_1 + 0x6c) = 0x5a595500;
              *(uint **)(param_1 + 0x74) = puVar9;
              uVar15 = puVar9[2];
              if (uVar15 < 4000) {
                uVar10 = 0x200;
              }
              else {
LAB_40bcbe44:
                if (uVar15 < 8000) {
                  uVar10 = 0x400;
                }
                else if (uVar15 < 0x124f9) {
                  uVar10 = 0x800;
                }
                else {
                  uVar10 = 0x4000;
                }
              }
LAB_40bcbe78:
              *(undefined4 *)(param_1 + 0x58) = uVar10;
              *(undefined4 *)(param_1 + 0x5c) = 0x40;
              FUN_40bc9c54(param_1,uVar17,puVar11,(va_list)param_4);
              goto LAB_40bcbe90;
            }
          }
        }
LAB_40bcb250:
        if ((((*(int *)(param_1 + 0x78) == 0) && (*(int *)(param_1 + 0x30) == 0)) &&
            ((*(uint *)(param_1 + 0xd0) & *(uint *)(param_1 + 0xd4)) != 0xffffffff)) &&
           (5 < local_1f8)) goto LAB_40bcbe90;
      }
      local_214 = local_214 + uVar15;
      local_218 = (uint *)((int)local_218 - uVar15);
      goto joined_r0x40bca914;
    }
    local_218 = (uint *)((int)local_218 + -1);
    local_214 = local_214 + 1;
    goto joined_r0x40bca914;
  }
  if ((local_218 < (uint *)0xc) || (local_218 < (uint *)0x10)) goto LAB_40bcbe90;
  local_218 = local_218 + -3;
  local_214 = local_214 + 0xc;
  goto joined_r0x40bca914;
joined_r0x40bcb41c:
  if ((uint *)0x4 < local_218) {
    bVar1 = local_214[3];
    uVar15 = CONCAT31(CONCAT21(CONCAT11(*local_214,local_214[1]),local_214[2]),bVar1);
    if (uVar15 == 0x1ba) {
      if (((local_218 < (uint *)0xe) ||
          (puVar9 = (uint *)((local_214[0xd] & 7) + 0xe), local_218 < puVar9)) ||
         (puVar9 == (uint *)0x0)) goto LAB_40bcbe90;
      local_218 = (uint *)((int)local_218 - (int)puVar9);
      local_214 = (byte *)((int)puVar9 + (int)local_214);
    }
    else if (uVar15 == 0x1bb) {
      uVar15 = FUN_40bc4e9c((int)local_214,(uint)local_218,puVar11,(va_list)param_4);
      if (uVar15 < 5) {
        if (uVar15 == 0) goto LAB_40bcbe90;
LAB_40bcbe24:
        local_218 = (uint *)((int)local_218 + -1);
        local_214 = local_214 + 1;
      }
      else {
        local_218 = (uint *)((int)local_218 - uVar15);
        local_214 = local_214 + uVar15;
      }
    }
    else {
      if (uVar15 == 0x1bc) {
        if (((uint)local_214[4] * 0x100 + (uint)local_214[5] != 0) && ((char)local_214[6] < '\0')) {
          pbVar14 = local_214 + 9;
          iVar16 = (uint)local_214[8] * 0x100 + (uint)*pbVar14;
          uVar15 = (uint)pbVar14[iVar16 + 1] * 0x100 + (uint)pbVar14[iVar16 + 2];
          pbVar14 = pbVar14 + iVar16 + 3;
          if (3 < uVar15) {
            do {
              switch(*pbVar14) {
              case 0xf:
              case 0x11:
                *(undefined4 *)(param_1 + 0x134) = 1;
                break;
              case 0x10:
                *(undefined4 *)(param_1 + 0x138) = 1;
                break;
              case 0x1b:
                *(undefined4 *)(param_1 + 0x13c) = 1;
              }
              pbVar13 = pbVar14 + 2;
              pbVar7 = pbVar14 + 3;
              pbVar14 = pbVar14 + 4;
              uVar15 = ((uVar15 + (uint)*pbVar13 * -0x100) - (uint)*pbVar7) - 4;
            } while (3 < (int)uVar15);
          }
          goto LAB_40bcbe24;
        }
        goto LAB_40bcbe90;
      }
      if ((uVar15 < 0x1bc) || (0x1ff < uVar15)) goto LAB_40bcbe24;
      puVar11 = &local_1c0;
      uVar15 = FUN_40bc61c4((int)local_214,(uint)local_218,puVar11);
      if (local_1b8 != 0) {
        local_1f8 = local_1f8 + 1;
        param_4 = (uint *)0x0;
        puVar11 = (uint *)0x5a;
        lVar21 = __ll_div(local_1b0,local_1ac);
        if (((*(uint *)(param_1 + 0xd0) & *(uint *)(param_1 + 0xd4)) == 0xffffffff) ||
           (lVar21 * 10000 < *(longlong *)(param_1 + 0xd0))) {
          *(longlong *)(param_1 + 0xd0) = lVar21 * 10000;
        }
      }
      if (uVar15 < 5) {
        if (uVar15 != 0) goto LAB_40bcbe24;
        goto LAB_40bcbe90;
      }
      if ((bVar1 & 0xf0) == 0xe0) {
        if (*(int *)(param_1 + 0x78) == 0) {
          *(byte *)(param_1 + 0x11a) = bVar1;
          pbVar14 = local_214;
          uVar17 = uVar15;
          do {
            uVar18 = CONCAT31(CONCAT21(CONCAT11(*pbVar14,pbVar14[1]),pbVar14[2]),pbVar14[3]);
            if (uVar18 != 0x1b3) {
              if ((*(int *)(param_1 + 0x138) == 0) || ((uVar18 & 0xfffffff0) != 0x120)) {
                if (*(int *)(param_1 + 0x13c) == 0) goto LAB_40bcb84c;
                *(undefined **)(param_1 + 0x78) = &DAT_40bdd2e8;
                local_1f4 = 0;
                local_204 = 0;
                *(undefined **)(param_1 + 0x7c) = &DAT_40bdc510;
                pvVar6 = malloc(0x60);
                puVar11 = (uint *)&DAT_00000060;
                puVar9 = (uint *)0x0;
                memset(pvVar6,0,0x60);
                *(undefined4 *)(param_1 + 0xa8) = 0x5589f90;
                *(undefined4 *)(param_1 + 0xac) = 0x11cec356;
                local_1e4 = uVar17 - 4;
                *(undefined4 *)(param_1 + 0xb0) = 0xaa0001bf;
                *(undefined4 *)(param_1 + 0xb8) = 0x60;
                *(undefined4 *)(param_1 + 0xa0) = 0x20000;
                *(undefined4 *)(param_1 + 0xa4) = 0x20;
                *(undefined4 *)(param_1 + 0xb4) = 0x5a595500;
                *(void **)(param_1 + 0xbc) = pvVar6;
                *(undefined4 *)((int)pvVar6 + 0x30) = 0x28;
                local_1ec = (uint *)(pbVar14 + 4);
                if (4 < local_1e4) {
                  puVar9 = &local_1e4;
                  bVar2 = FUN_40bc52e8((int *)&local_1ec,puVar9);
                  if (CONCAT31(extraout_var,bVar2) != 0) {
                    puVar9 = (uint *)(local_1e4 - 3);
                    param_4 = &local_204;
                    puVar11 = &local_1f4;
                    FUN_40bc9474((int)((int)local_1ec + 3),(uint)puVar9,(int *)puVar11,
                                 (int *)param_4);
                    uVar17 = local_1f4;
                    uVar18 = local_204;
                    if (local_1f4 != 0) goto LAB_40bcbda0;
                    if (local_204 != 0) goto LAB_40bcbdb0;
                  }
                }
                *(undefined4 *)((int)pvVar6 + 0x38) = 0x120;
                *(undefined4 *)((int)pvVar6 + 0x34) = 0x160;
              }
              else {
                *(undefined **)(param_1 + 0x78) = &DAT_40bdd2e8;
                *(undefined **)(param_1 + 0x7c) = local_1fc;
                pvVar6 = malloc(0x60);
                memset(pvVar6,0,0x60);
                puVar9 = (uint *)(uVar17 - 4);
                *(undefined4 *)(param_1 + 0xa8) = 0x5589f90;
                *(undefined4 *)(param_1 + 0xac) = 0x11cec356;
                *(undefined4 *)(param_1 + 0xb0) = 0xaa0001bf;
                *(undefined4 *)(param_1 + 0xb8) = 0x60;
                param_4 = &local_1e8;
                *(undefined4 *)(param_1 + 0xa0) = 0x20000;
                *(undefined4 *)(param_1 + 0xa4) = 0x20;
                *(undefined4 *)(param_1 + 0xb4) = 0x5a595500;
                *(void **)(param_1 + 0xbc) = pvVar6;
                puVar11 = &local_200;
                *(undefined4 *)((int)pvVar6 + 0x30) = 0x28;
                FUN_40bc9600((int)(pbVar14 + 4),(int)puVar9,puVar11,param_4);
                uVar17 = local_200;
                uVar18 = local_1e8;
                if (local_200 == 0) {
                  if (local_1e8 == 0) {
                    *(undefined4 *)((int)pvVar6 + 0x38) = 0x1e0;
                    *(undefined4 *)((int)pvVar6 + 0x34) = 0x280;
                  }
                }
                else {
LAB_40bcbda0:
                  if (uVar18 != 0) {
                    *(uint *)((int)pvVar6 + 0x38) = uVar18;
                    *(uint *)((int)pvVar6 + 0x34) = uVar17;
                  }
                }
              }
LAB_40bcbdb0:
              FUN_40bca318(param_1,puVar9,puVar11,(va_list)param_4);
              break;
            }
            puVar11 = auStack_178;
            iVar16 = FUN_40bc4fe0(pbVar14,uVar17,(int)puVar11,(va_list)param_4);
            if ((iVar16 != 0) && (local_170 != 0)) {
              pvVar6 = malloc((size_t)(local_138 + 0x22));
              memset(pvVar6,0,0x88);
              *(undefined **)(param_1 + 0x78) = &DAT_40bdd2e8;
              *(undefined **)(param_1 + 0x7c) = &DAT_40bde1e8;
              *(undefined4 *)(param_1 + 0xa8) = 0xe06d80e3;
              *(undefined4 *)(param_1 + 0xac) = 0x11cfdb46;
              *(undefined4 *)(param_1 + 0xb0) = 0x8000d1b4;
              *(undefined4 *)(param_1 + 0xb8) = 0x88;
              *(undefined4 *)(param_1 + 0xa0) = 0x8000;
              *(undefined4 *)(param_1 + 0xa4) = 0x40;
              *(undefined4 *)(param_1 + 0xb4) = 0xeabb6c5f;
              *(void **)(param_1 + 0xbc) = pvVar6;
              *(undefined4 *)((int)pvVar6 + 0x48) = 0x28;
              *(int *)((int)pvVar6 + 0x4c) = local_170;
              *(undefined4 *)((int)pvVar6 + 0x50) = local_16c;
              puVar9 = auStack_134;
              puVar11 = local_138;
              memcpy((void *)((int)pvVar6 + 0x84),puVar9,(size_t)local_138);
              *(uint **)((int)pvVar6 + 0x74) = local_138;
              goto LAB_40bcbdb0;
            }
LAB_40bcb84c:
            uVar17 = uVar17 - 1;
            pbVar14 = pbVar14 + 1;
          } while (3 < uVar17);
          goto LAB_40bcbdc0;
        }
      }
      else {
        if ((((bVar1 & 0xe0) == 0xc0) || (bVar1 == 0xbd)) && (*(int *)(param_1 + 0x30) == 0)) {
          *(byte *)(param_1 + 0x118) = bVar1;
          pbVar14 = local_214 + local_1c0;
          *(byte *)(param_1 + 0x119) = *pbVar14;
          if (bVar1 == 0xbd) {
            if ((*pbVar14 & 0xf8) == 0x80) {
              uVar17 = 0;
              if (uVar15 != 5) {
                do {
                  if (((pbVar14[uVar17 + 4] == 0xb) && (pbVar14[uVar17 + 5] == 0x77)) ||
                     ((pbVar14[uVar17 + 4] == 0x77 && (pbVar14[uVar17 + 5] == 0xb)))) {
                    *(undefined4 *)(param_1 + 0x140) = 1;
                    _Dst = malloc(0x17);
                    puVar11 = (uint *)0x17;
                    memset(_Dst,0,0x17);
                    pvVar6 = _Dst;
                    FUN_40bc5348((char *)(pbVar14 + uVar17 + 4),(int)_Dst,puVar11,(va_list)param_4);
                    *(undefined **)(param_1 + 0x30) = &DAT_40bdd2f8;
                    *(undefined **)(param_1 + 0x34) = &DAT_40bde248;
                    *(undefined4 *)(param_1 + 0x60) = 0x5589f81;
                    *(undefined4 *)(param_1 + 100) = 0x11cec356;
                    *(undefined4 *)(param_1 + 0x68) = 0xaa0001bf;
                    *(undefined4 *)(param_1 + 0x70) = 0x17;
                    *(undefined4 *)(param_1 + 0x58) = 0x800;
                    *(undefined4 *)(param_1 + 0x6c) = 0x5a595500;
                    *(void **)(param_1 + 0x74) = _Dst;
                    *(undefined4 *)(param_1 + 0x5c) = 0x40;
                    FUN_40bc9c54(param_1,pvVar6,puVar11,(va_list)param_4);
                    break;
                  }
                  uVar17 = uVar17 + 1;
                } while (uVar17 < uVar15 - 5);
              }
            }
            else if ((*pbVar14 & 0xf8) == 0xa0) {
              puVar4 = malloc(0x12);
              puVar11 = (uint *)0x12;
              memset(puVar4,0,0x12);
              puVar5 = puVar4;
              iVar16 = FUN_40bc55a0((char *)pbVar14,puVar4);
              if (iVar16 == 1) {
                *(undefined **)(param_1 + 0x30) = &DAT_40bdd2f8;
                *(undefined **)(param_1 + 0x34) = &DAT_40bdc290;
                *(undefined4 *)(param_1 + 0x60) = 0x5589f81;
                *(undefined4 *)(param_1 + 100) = 0x11cec356;
                *(undefined4 *)(param_1 + 0x68) = 0xaa0001bf;
                *(undefined4 *)(param_1 + 0x70) = 0x12;
                *(undefined4 *)(param_1 + 0x58) = 0x4000;
                *(undefined4 *)(param_1 + 0x6c) = 0x5a595500;
                *(undefined1 **)(param_1 + 0x74) = puVar4;
                *(undefined4 *)(param_1 + 0x5c) = 0x40;
                *(undefined4 *)(param_1 + 0x144) = 1;
              }
              FUN_40bc9c54(param_1,puVar5,puVar11,(va_list)param_4);
            }
          }
          else if (*(int *)(param_1 + 0x134) == 0) {
            puVar5 = malloc(0x12);
            puVar11 = (uint *)0x12;
            memset(puVar5,0,0x12);
            uVar17 = 0;
            if (uVar15 != 1) {
              do {
                if ((pbVar14[uVar17] == 0xff) &&
                   (puVar4 = puVar5, iVar16 = FUN_40bc56e8(pbVar14 + uVar17,puVar5), iVar16 != 0)) {
                  *(undefined4 **)(param_1 + 0x34) = &DAT_40bde238;
                  *(undefined **)(param_1 + 0x30) = &DAT_40bdd2f8;
                  *(undefined4 *)(param_1 + 0x60) = 0x5589f81;
                  *(undefined4 *)(param_1 + 100) = 0x11cec356;
                  *(undefined4 *)(param_1 + 0x68) = 0xaa0001bf;
                  *(undefined4 *)(param_1 + 0x70) = 0x12;
                  *(undefined4 *)(param_1 + 0x6c) = 0x5a595500;
                  *(undefined1 **)(param_1 + 0x74) = puVar5;
                  uVar17 = *(uint *)(puVar5 + 8);
                  if (uVar17 < 4000) {
                    uVar10 = 0x200;
                  }
                  else if (uVar17 < 8000) {
                    uVar10 = 0x400;
                  }
                  else if (uVar17 < 0x61a9) {
                    uVar10 = 0x800;
                  }
                  else {
                    uVar10 = 0xc00;
                  }
                  *(undefined4 *)(param_1 + 0x58) = uVar10;
                  *(undefined4 *)(param_1 + 0x5c) = 0x40;
                  FUN_40bc9c54(param_1,puVar4,puVar11,(va_list)param_4);
                  break;
                }
                uVar17 = uVar17 + 1;
              } while (uVar17 < uVar15 - 1);
            }
          }
          else {
            puVar9 = malloc(0x12);
            memset(puVar9,0,0x12);
            uVar17 = local_1bc;
            puVar11 = puVar9;
            iVar16 = FUN_40bc5db0((char *)pbVar14,local_1bc,(undefined1 *)puVar9);
            if (iVar16 != 0) {
              *(undefined **)(param_1 + 0x30) = &DAT_40bdd2f8;
              *(undefined **)(param_1 + 0x34) = &DAT_40bdc350;
              *(undefined4 *)(param_1 + 0x60) = 0x5589f81;
              *(undefined4 *)(param_1 + 100) = 0x11cec356;
              *(undefined4 *)(param_1 + 0x68) = 0xaa0001bf;
              *(undefined4 *)(param_1 + 0x70) = 0x12;
              *(undefined4 *)(param_1 + 0x6c) = 0x5a595500;
              *(uint **)(param_1 + 0x74) = puVar9;
              uVar15 = puVar9[2];
              if (3999 < uVar15) goto LAB_40bcbe44;
              uVar10 = 0x200;
              goto LAB_40bcbe78;
            }
          }
        }
LAB_40bcbdc0:
        if ((((*(int *)(param_1 + 0x78) == 0) && (*(int *)(param_1 + 0x30) == 0)) &&
            ((*(uint *)(param_1 + 0xd0) & *(uint *)(param_1 + 0xd4)) != 0xffffffff)) &&
           (5 < local_1f8)) goto LAB_40bcbe90;
      }
      local_214 = local_214 + uVar15;
      local_218 = (uint *)((int)local_218 - uVar15);
    }
    goto joined_r0x40bcb41c;
  }
LAB_40bcbe90:
  if (((*(int *)(param_1 + 0x28) == 0) && (2 < local_1dc)) && (0x13 < local_1d8)) {
    pvVar6 = malloc((size_t)(local_138 + 0x22));
    puVar11 = (uint *)0x88;
    puVar9 = (uint *)0x0;
    memset(pvVar6,0,0x88);
    *(int *)(param_1 + 0x78) = (int)&DAT_40bdd2e8;
    *(undefined **)(param_1 + 0x7c) = &DAT_40bdd638;
    *(undefined4 *)(param_1 + 0xa8) = 0xe06d80e3;
    *(undefined4 *)(param_1 + 0xac) = 0x11cfdb46;
    *(undefined4 *)(param_1 + 0xb0) = 0x8000d1b4;
    *(undefined4 *)(param_1 + 0xb8) = 0x88;
    *(undefined4 *)(param_1 + 0xa0) = 0x4000;
    *(undefined4 *)(param_1 + 0xa4) = 0x80;
    *(undefined4 *)(param_1 + 0xb4) = 0xeabb6c5f;
    *(void **)(param_1 + 0xbc) = pvVar6;
    if (local_170 != 0) {
      *(int *)((int)pvVar6 + 0x4c) = local_170;
      *(undefined4 *)((int)pvVar6 + 0x50) = local_16c;
      puVar9 = auStack_134;
      puVar11 = local_138;
      memcpy((void *)((int)pvVar6 + 0x84),puVar9,(size_t)local_138);
      *(uint **)((int)pvVar6 + 0x74) = local_138;
    }
    FUN_40bca318(param_1,puVar9,puVar11,(va_list)param_4);
  }
  puVar11 = local_1c8;
  FUN_40bc7988(param_1,(int *)local_1c8,local_1d0,local_1cc);
  *(uint *)(param_1 + 200) = *(uint *)(param_1 + 0xd8) - *(uint *)(param_1 + 0xd0);
  *(uint *)(param_1 + 0xcc) =
       (*(int *)(param_1 + 0xdc) - *(int *)(param_1 + 0xd4)) -
       (uint)(*(uint *)(param_1 + 0xd8) < *(uint *)(param_1 + 0xd0));
  operator_delete(local_1e0);
  uVar15 = *puVar11;
  (**(code **)(uVar15 + 8))(puVar11,uVar15,0,0);
  if ((*(int *)(param_1 + 0x78) == 0) && (*(int *)(param_1 + 0x30) == 0)) {
    uVar10 = 0x80004005;
  }
  else {
    uVar10 = 0;
    *(uint *)(param_1 + 0xc0) = local_1d0;
    *(int *)(param_1 + 0xc4) = local_1cc;
  }
  uVar15 = *(uint *)(param_1 + 0xe0) + *(int *)(param_1 + 0xd0);
  iVar16 = *(int *)(param_1 + 0xe4) + *(int *)(param_1 + 0xd4) +
           (uint)(uVar15 < *(uint *)(param_1 + 0xe0));
  *(uint *)(param_1 + 0xf8) = uVar15;
  *(int *)(param_1 + 0xfc) = iVar16;
  *(uint *)(param_1 + 0xf0) = uVar15;
  *(int *)(param_1 + 0xf4) = iVar16;
  *(undefined4 *)(param_1 + 0x130) = 0;
  FUN_40bd8bd0(local_30);
  return uVar10;
}



/* 40bcc074 FUN_40bcc074 */

/* Boundary evidence: original MIPS .pdata 40bcc074..40bcc08f. Semantic name remains unreviewed. */

void FUN_40bcc074(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40bcc0a0 FUN_40bcc0a0 */

/* Boundary evidence: original MIPS .pdata 40bcc0a0..40bcc0cb. Semantic name remains unreviewed. */

void FUN_40bcc0a0(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0x98) + 0x18))();
  return;
}



/* 40bcc0cc FUN_40bcc0cc */

/* Boundary evidence: original MIPS .pdata 40bcc0cc..40bcc0f7. Semantic name remains unreviewed. */

void FUN_40bcc0cc(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 0x38))();
  return;
}



/* 40bcc0f8 FUN_40bcc0f8 */

/* Boundary evidence: original MIPS .pdata 40bcc0f8..40bcc123. Semantic name remains unreviewed. */

void FUN_40bcc0f8(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 0x3c))();
  return;
}



/* 40bcc124 FUN_40bcc124 */

/* Boundary evidence: original MIPS .pdata 40bcc124..40bcc14f. Semantic name remains unreviewed. */

void FUN_40bcc124(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 0x40))();
  return;
}



/* 40bcc150 FUN_40bcc150 */

/* Boundary evidence: original MIPS .pdata 40bcc150..40bcc16b. Semantic name remains unreviewed. */

void FUN_40bcc150(int param_1)

{
  FUN_40bd13bc(param_1);
  return;
}



/* 40bcc16c FUN_40bcc16c */

/* Boundary evidence: original MIPS .pdata 40bcc16c..40bcc187. Semantic name remains unreviewed. */

void FUN_40bcc16c(undefined4 *param_1)

{
  FUN_40bd6a6c(param_1);
  return;
}



/* 40bcc188 FUN_40bcc188 */

/* Boundary evidence: original MIPS .pdata 40bcc188..40bcc1a3. Semantic name remains unreviewed. */

void FUN_40bcc188(int param_1)

{
  FUN_40bd54dc(param_1);
  return;
}



/* 40bcc1a4 FUN_40bcc1a4 */

/* Boundary evidence: original MIPS .pdata 40bcc1a4..40bcc1bf. Semantic name remains unreviewed. */

void FUN_40bcc1a4(int *param_1)

{
  FUN_40bd5518(param_1);
  return;
}



/* 40bcc1c0 FUN_40bcc1c0 */

/* Boundary evidence: original MIPS .pdata 40bcc1c0..40bcc1db. Semantic name remains unreviewed. */

void FUN_40bcc1c0(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40bd1400(param_1,param_2,param_3);
  return;
}



/* 40bcc1dc FUN_40bcc1dc */

/* Boundary evidence: original MIPS .pdata 40bcc1dc..40bcc2b7. Semantic name remains unreviewed. */

undefined4 FUN_40bcc1dc(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_c0 [60];
  int local_84;
  int local_80;
  undefined1 auStack_78 [16];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 auStack_5c [60];
  uint local_20;
  
  local_20 = DAT_40be0550;
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))((int *)(param_1 + 0xc),&local_68);
  local_84 = param_3 + 4;
  piVar3 = *(int **)(*(int *)(param_1 + 0x70) + 0xa8);
  iVar2 = *piVar3;
  local_80 = param_3;
  memcpy(auStack_c0,auStack_5c,0x3c);
  (**(code **)(iVar2 + 8))(piVar3,local_68,local_64,local_60);
  FUN_40bd62f4((int)&local_68);
  *(undefined4 *)(param_3 + 8) = 1;
  *(undefined4 *)(param_3 + 0xc) = 0;
  uVar1 = (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_78);
  FUN_40bd8bd0(local_20);
  return uVar1;
}



/* 40bcc2b8 FUN_40bcc2b8 */

/* Boundary evidence: original MIPS .pdata 40bcc2b8..40bcc3ab. Semantic name remains unreviewed. */

undefined4 FUN_40bcc2b8(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_40bc3b24(0x40bdb298,*param_2,param_3,param_4);
    (**(code **)(*param_2 + 8))(param_2);
    return 1;
  }
  iVar1 = (**(code **)(*param_2 + 0x3c))(param_2);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0xa8) != 0)) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
    (**(code **)(*param_2 + 0x40))(param_2,1);
  }
  iVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
  if (iVar1 == 0) {
    (**(code **)(*param_2 + 8))(param_2);
    return 0;
  }
  uVar2 = FUN_40bd7560(*(LPCRITICAL_SECTION *)(param_1 + 0xac),param_2);
  return uVar2;
}



/* 40bcc3ac FUN_40bcc3ac */

/* Boundary evidence: original MIPS .pdata 40bcc3ac..40bcc3c7. Semantic name remains unreviewed. */

void FUN_40bcc3ac(int param_1,int *param_2)

{
  FUN_40bd17ac(param_1,param_2);
  return;
}



/* 40bcc3c8 FUN_40bcc3c8 */

/* Boundary evidence: original MIPS .pdata 40bcc3c8..40bcc3e3. Semantic name remains unreviewed. */

void FUN_40bcc3c8(int *param_1)

{
  FUN_40bd1784(param_1);
  return;
}



/* 40bcc3e4 FUN_40bcc3e4 */

/* Boundary evidence: original MIPS .pdata 40bcc3e4..40bcc45f. Semantic name remains unreviewed. */

void FUN_40bcc3e4(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x98) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x18))();
    if (iVar1 < 0) {
      return;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 8))();
    if (iVar1 != 0) {
      FUN_40bc3b24(0x40bdb2d4,iVar1,param_3,param_4);
    }
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  FUN_40bd1814(param_1);
  return;
}



/* 40bcc460 FUN_40bcc460 */

/* Boundary evidence: original MIPS .pdata 40bcc460..40bcc47b. Semantic name remains unreviewed. */

void FUN_40bcc460(undefined4 *param_1)

{
  FUN_40bd6a6c(param_1);
  return;
}



/* 40bcc47c FUN_40bcc47c */

/* Boundary evidence: original MIPS .pdata 40bcc47c..40bcc5df. Semantic name remains unreviewed. */

int FUN_40bcc47c(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if ((param_1[2] == 0) && (iVar1 = (**(code **)(*param_1 + 0x14))(param_1), iVar1 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (param_1[2] != 2) {
      piVar5 = param_1 + -3;
      iVar1 = (**(code **)(*piVar5 + 0x18))(piVar5);
      iVar4 = 0;
      if (0 < iVar1) {
        do {
          piVar2 = (int *)(**(code **)(*piVar5 + 0x1c))(piVar5,iVar4);
          if ((piVar2[6] != 0) && (iVar3 = (**(code **)(*piVar2 + 0x1c))(piVar2), iVar3 < 0)) {
            LeaveCriticalSection(lpCriticalSection);
            return iVar3;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
      }
    }
    param_1[2] = 2;
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bcc5e0 FUN_40bcc5e0 */

/* Boundary evidence: original MIPS .pdata 40bcc5e0..40bcc60f. Semantic name remains unreviewed. */

void FUN_40bcc5e0(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40bcc610 FUN_40bcc610 */

/* Boundary evidence: original MIPS .pdata 40bcc610..40bcc637. Semantic name remains unreviewed. */

void FUN_40bcc610(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xa8) + 0x24))();
  return;
}



/* 40bcc638 FUN_40bcc638 */

/* Boundary evidence: original MIPS .pdata 40bcc638..40bcc683. Semantic name remains unreviewed. */

undefined4 FUN_40bcc638(undefined4 param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_2 != (void *)0x0) {
    iVar2 = memcmp(param_2,&DAT_40bde4a8,0x10);
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 40bcc684 FUN_40bcc684 */

undefined4 FUN_40bcc684(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0xac) = *param_2;
  *(undefined4 *)(param_1 + 0xb0) = param_2[1];
  *(undefined4 *)(param_1 + 0xb4) = param_2[2];
  *(undefined4 *)(param_1 + 0xb8) = param_2[3];
  return 0;
}



/* 40bcc6ac FUN_40bcc6ac */

/* Boundary evidence: original MIPS .pdata 40bcc6ac..40bcc737. Semantic name remains unreviewed. */

undefined4 FUN_40bcc6ac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc4);
  EnterCriticalSection(lpCriticalSection);
  if ((*(int **)(param_1 + 0xa8) == (int *)0x0) ||
     (iVar1 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x28))(), iVar1 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
    uVar2 = 0;
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    uVar2 = 1;
  }
  return uVar2;
}



/* 40bcc738 FUN_40bcc738 */

/* Boundary evidence: original MIPS .pdata 40bcc738..40bcc767. Semantic name remains unreviewed. */

void FUN_40bcc738(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40bcc768 FUN_40bcc768 */

/* Boundary evidence: original MIPS .pdata 40bcc768..40bcc81f. Semantic name remains unreviewed. */

undefined4 * FUN_40bcc768(undefined4 *param_1,int param_2,undefined4 param_3)

{
  FUN_40bd4ef4(param_1,0,param_2,param_2 + 0x6c,param_3,L"Input");
  *param_1 = &PTR_FUN_40bdb460;
  param_1[3] = &PTR_FUN_40bdb418;
  param_1[4] = &PTR_LAB_40bdb404;
  param_1[0x26] = &PTR_LAB_40bdb3e0;
  param_1[0x36] = 0;
  FUN_40bc3c48(param_1 + 0x38);
  param_1[0x38] = &PTR_FUN_40bdb27c;
  param_1[0x54] = param_1;
  return param_1;
}



/* 40bcc820 FUN_40bcc820 */

/* Boundary evidence: original MIPS .pdata 40bcc820..40bcc84f. Semantic name remains unreviewed. */

void FUN_40bcc820(void)

{
  int *in_v0;
  
  FUN_40bd1c3c(*in_v0);
  return;
}



/* 40bcc850 FUN_40bcc850 */

/* Boundary evidence: original MIPS .pdata 40bcc850..40bcc877. Semantic name remains unreviewed. */

void FUN_40bcc850(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40bcc878 FUN_40bcc878 */

/* Boundary evidence: original MIPS .pdata 40bcc878..40bcc89f. Semantic name remains unreviewed. */

void FUN_40bcc878(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40bcc8a0 FUN_40bcc8a0 */

/* Boundary evidence: original MIPS .pdata 40bcc8a0..40bcc8c7. Semantic name remains unreviewed. */

void FUN_40bcc8a0(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40bcc8c8 FUN_40bcc8c8 */

/* Boundary evidence: original MIPS .pdata 40bcc8c8..40bcc937. Semantic name remains unreviewed. */

undefined4 FUN_40bcc8c8(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40bdcd38,0x10);
  if (iVar1 == 0) {
    uVar2 = 0x80004002;
  }
  else {
    uVar2 = FUN_40bd1c84(param_1,param_2,param_3);
  }
  return uVar2;
}



/* 40bcc938 FUN_40bcc938 */

/* Boundary evidence: original MIPS .pdata 40bcc938..40bcc983. Semantic name remains unreviewed. */

void FUN_40bcc938(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  FUN_40bc4bdc((undefined4 *)(param_1 + 0xe0),param_2,param_3,param_4);
  FUN_40bd1c3c(param_1);
  return;
}



/* 40bcc984 FUN_40bcc984 */

/* Boundary evidence: original MIPS .pdata 40bcc984..40bcc9b3. Semantic name remains unreviewed. */

void FUN_40bcc984(void)

{
  int *in_v0;
  
  FUN_40bd1c3c(*in_v0);
  return;
}



/* 40bcc9bc FUN_40bcc9bc */

/* Boundary evidence: original MIPS .pdata 40bcc9bc..40bcca9f. Semantic name remains unreviewed. */

int FUN_40bcc9bc(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int local_18;
  undefined4 *local_14;
  
  local_18 = FUN_40bd1520(param_1,param_2);
  if (-1 < local_18) {
    local_14 = operator_new(0x6c);
    if (local_14 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40bc3168(local_14,(undefined4 *)0x0,&local_18);
    }
    piVar2 = puVar1 + 3;
    if (puVar1 == (undefined4 *)0x0) {
      piVar2 = (int *)0x0;
    }
    *(int **)(param_1 + 0x9c) = piVar2;
    if (piVar2 == (int *)0x0) {
      local_18 = -0x7ff8fff2;
    }
    else if (-1 < local_18) {
      (**(code **)(*piVar2 + 4))();
      local_18 = FUN_40bc4c64(param_1 + 0xe0,param_2,*(undefined4 *)(param_1 + 0x9c),param_4);
    }
  }
  return local_18;
}



/* 40bccaa0 FUN_40bccaa0 */

/* Boundary evidence: original MIPS .pdata 40bccaa0..40bccacf. Semantic name remains unreviewed. */

void FUN_40bccaa0(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x14));
  return;
}



/* 40bccad0 FUN_40bccad0 */

/* Boundary evidence: original MIPS .pdata 40bccad0..40bccb33. Semantic name remains unreviewed. */

void FUN_40bccad0(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x40))();
  FUN_40bc4854(param_1 + 0xe0,param_2,param_3,param_4);
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40bd16fc();
  return;
}



/* 40bccb34 FUN_40bccb34 */

/* Boundary evidence: original MIPS .pdata 40bccb34..40bccbd7. Semantic name remains unreviewed. */

int FUN_40bccb34(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x38))();
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    (**(code **)(**(int **)(param_1 + 100) + 0x2c))();
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40bccbd8 FUN_40bccbd8 */

/* Boundary evidence: original MIPS .pdata 40bccbd8..40bccc07. Semantic name remains unreviewed. */

void FUN_40bccbd8(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bccc08 FUN_40bccc08 */

/* Boundary evidence: original MIPS .pdata 40bccc08..40bccc7f. Semantic name remains unreviewed. */

undefined4 FUN_40bccc08(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  FUN_40bd1f08(param_1);
  (**(code **)(**(int **)(param_1 + 100) + 0x24))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bccc80 FUN_40bccc80 */

/* Boundary evidence: original MIPS .pdata 40bccc80..40bcccaf. Semantic name remains unreviewed. */

void FUN_40bccc80(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40bcccb0 FUN_40bcccb0 */

/* Boundary evidence: original MIPS .pdata 40bcccb0..40bccd27. Semantic name remains unreviewed. */

undefined4 FUN_40bcccb0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  FUN_40bd1f50(param_1);
  (**(code **)(**(int **)(param_1 + 100) + 0x28))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bccd28 FUN_40bccd28 */

/* Boundary evidence: original MIPS .pdata 40bccd28..40bccd57. Semantic name remains unreviewed. */

void FUN_40bccd28(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40bccd58 FUN_40bccd58 */

/* Boundary evidence: original MIPS .pdata 40bccd58..40bccd87. Semantic name remains unreviewed. */

void FUN_40bccd58(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  FUN_40bc4940(param_1 + 0xe0,param_2,param_3,param_4);
  FUN_40bd1fb4(param_1);
  return;
}



/* 40bccd88 FUN_40bccd88 */

/* Boundary evidence: original MIPS .pdata 40bccd88..40bccdaf. Semantic name remains unreviewed. */

void FUN_40bccd88(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x34))();
  return;
}



/* 40bccdb0 FUN_40bccdb0 */

/* Boundary evidence: original MIPS .pdata 40bccdb0..40bccdd7. Semantic name remains unreviewed. */

void FUN_40bccdb0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x38))();
  return;
}



/* 40bccdd8 FUN_40bccdd8 */

/* Boundary evidence: original MIPS .pdata 40bccdd8..40bcce3f. Semantic name remains unreviewed. */

bool FUN_40bccdd8(int param_1)

{
  bool bVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0x70) + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  bVar1 = FUN_40bc4960((int *)(param_1 + 0xe0));
  LeaveCriticalSection(lpCriticalSection);
  return bVar1;
}



/* 40bcce40 FUN_40bcce40 */

/* Boundary evidence: original MIPS .pdata 40bcce40..40bcce6f. Semantic name remains unreviewed. */

void FUN_40bcce40(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40bcce70 FUN_40bcce70 */

/* Boundary evidence: original MIPS .pdata 40bcce70..40bccf2f. Semantic name remains unreviewed. */

undefined4
FUN_40bcce70(int *param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,int param_6,
            int param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1[0x1c];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x6c));
  uVar2 = 0;
  FUN_40bc3c98((int)(param_1 + 0x38),param_2,param_3,param_4,param_5,param_6);
  if (param_7 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x6c));
  return uVar2;
}



/* 40bccf30 FUN_40bccf30 */

/* Boundary evidence: original MIPS .pdata 40bccf30..40bccf5f. Semantic name remains unreviewed. */

void FUN_40bccf30(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40bccf60 FUN_40bccf60 */

/* Boundary evidence: original MIPS .pdata 40bccf60..40bccffb. Semantic name remains unreviewed. */

undefined4 FUN_40bccf60(int *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[0x1c];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  uVar3 = 0;
  bVar1 = FUN_40bc4a2c(param_1 + 0x38,param_2);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    uVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  return uVar3;
}



/* 40bccffc FUN_40bccffc */

/* Boundary evidence: original MIPS .pdata 40bccffc..40bcd02b. Semantic name remains unreviewed. */

void FUN_40bccffc(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bcd02c FUN_40bcd02c */

/* Boundary evidence: original MIPS .pdata 40bcd02c..40bcd267. Semantic name remains unreviewed. */

uint FUN_40bcd02c(undefined4 param_1,undefined4 *param_2,uint param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_24;
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    local_40 = 0;
    local_3c = 0;
    iVar2 = (**(code **)(*param_4 + 0x14))(param_4,&local_40);
    if (-1 < iVar2) {
      local_38 = 0;
      local_34 = 0;
      iVar2 = (**(code **)*param_4)(param_4,&local_38);
      if (-1 < iVar2) {
        local_30 = 0;
        local_2c = 0;
        iVar2 = (**(code **)(*param_4 + 4))(param_4,&local_30);
        if (-1 < iVar2) {
          bVar1 = local_38 < local_30;
          local_38 = local_38 - local_30;
          local_34 = (local_34 - local_2c) - (uint)bVar1;
          bVar1 = local_40 < local_30;
          local_40 = local_40 - local_30;
          local_3c = (local_3c - local_2c) - (uint)bVar1;
          if (((0 < local_34) || ((uVar4 = local_38, local_34 == 0 && (param_3 <= local_38)))) &&
             ((uVar4 = param_3, local_3c < 1 &&
              (((local_3c != 0 || (local_40 < param_3)) &&
               ((0 < local_3c || ((uVar4 = 0x20000, local_3c == 0 && (0x1ffff < local_40)))))))))) {
            uVar4 = local_40;
          }
          pvVar3 = operator_new(uVar4);
          if (pvVar3 != (void *)0x0) {
            uVar6 = 0;
            while( true ) {
              if ((local_3c < 1) && ((local_3c != 0 || (local_40 < uVar4)))) {
                local_24 = local_3c;
                uVar5 = local_40;
              }
              else {
                local_24 = 0;
                uVar5 = uVar4;
              }
              iVar2 = (**(code **)(*param_4 + 0xc))(param_4,pvVar3,uVar5);
              if (iVar2 != 0) break;
              uVar6 = uVar5 + uVar6;
              if (uVar4 <= uVar6) {
LAB_40bcd200:
                *param_2 = pvVar3;
                return uVar6;
              }
            }
            if ((-1 < local_3c) && ((local_3c != 0 || (uVar6 < local_40)))) {
              operator_delete(pvVar3);
              return 0;
            }
            goto LAB_40bcd200;
          }
        }
      }
    }
  }
  return 0;
}



/* 40bcd2e0 FUN_40bcd2e0 */

/* Boundary evidence: original MIPS .pdata 40bcd2e0..40bcd307. Semantic name remains unreviewed. */

void FUN_40bcd2e0(int param_1,undefined4 param_2)

{
  undefined1 auStack_10 [8];
  
  (**(code **)(**(int **)(param_1 + 4) + 0x20))(*(int **)(param_1 + 4),param_2,auStack_10);
  return;
}



/* 40bcd308 FUN_40bcd308 */

/* Boundary evidence: original MIPS .pdata 40bcd308..40bcd333. Semantic name remains unreviewed. */

void FUN_40bcd308(int param_1,undefined4 param_2)

{
  undefined1 auStack_10 [8];
  
  (**(code **)(**(int **)(param_1 + 4) + 0x20))(*(int **)(param_1 + 4),auStack_10,param_2);
  return;
}



/* 40bcd34c FUN_40bcd34c */

/* Boundary evidence: original MIPS .pdata 40bcd34c..40bcd3bb. Semantic name remains unreviewed. */

void FUN_40bcd34c(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x1c))
                    (*(int **)(param_1 + 4),param_2,*(undefined4 *)(param_1 + 8),
                     *(undefined4 *)(param_1 + 0xc),param_3,param_2);
  if (iVar1 == 0) {
    uVar2 = param_3 + *(int *)(param_1 + 8);
    *(uint *)(param_1 + 8) = uVar2;
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + (uint)(uVar2 < param_3);
  }
  return;
}



/* 40bcd3bc FUN_40bcd3bc */

/* Boundary evidence: original MIPS .pdata 40bcd3bc..40bcd40f. Semantic name remains unreviewed. */

undefined4 FUN_40bcd3bc(int param_1)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x20))(*(int **)(param_1 + 4),&local_18,&local_10);
  if (((-1 < iVar1) && (local_18 == local_10)) && (local_14 == local_c)) {
    return 1;
  }
  return 0;
}



/* 40bcd410 FUN_40bcd410 */

/* Boundary evidence: original MIPS .pdata 40bcd410..40bcd467. Semantic name remains unreviewed. */

void FUN_40bcd410(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 != -0x7ffbfdd9) && (param_2 < 0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x70) + 0x70);
    iVar2 = *(int *)(iVar1 + 0xa8);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 4) = 1;
    }
    FUN_40bd0ff4(iVar1);
  }
  return;
}



/* 40bcd468 FUN_40bcd468 */

/* Boundary evidence: original MIPS .pdata 40bcd468..40bcd4b3. Semantic name remains unreviewed. */

undefined4 * FUN_40bcd468(undefined4 *param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  FUN_40bc4bdc(param_1,param_2,param_3,param_4);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bcd4d0 FUN_40bcd4d0 */

/* Boundary evidence: original MIPS .pdata 40bcd4d0..40bcd4fb. Semantic name remains unreviewed. */

void FUN_40bcd4d0(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x1c))();
  return;
}



/* 40bcd50c FUN_40bcd50c */

/* Boundary evidence: original MIPS .pdata 40bcd50c..40bcd533. Semantic name remains unreviewed. */

void FUN_40bcd50c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 0x4c))();
  return;
}



/* 40bcd534 FUN_40bcd534 */

/* Boundary evidence: original MIPS .pdata 40bcd534..40bcd57f. Semantic name remains unreviewed. */

undefined4 FUN_40bcd534(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (*(int *)(*(int *)(param_1 + 4) + 0x18) == 0) {
    return 1;
  }
  piVar2 = *(int **)(*(int *)(param_1 + 4) + 0x98);
  uVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2,param_2,0,0,0);
  return uVar1;
}



/* 40bcd580 FUN_40bcd580 */

/* Boundary evidence: original MIPS .pdata 40bcd580..40bcd59b. Semantic name remains unreviewed. */

void FUN_40bcd580(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  FUN_40bcc2b8(*(int *)(param_1 + 4),param_2,param_3,param_4);
  return;
}



/* 40bcd59c FUN_40bcd59c */

/* Boundary evidence: original MIPS .pdata 40bcd59c..40bcd63f. Semantic name remains unreviewed. */

undefined4 * FUN_40bcd59c(undefined4 *param_1,int param_2,undefined4 param_3,wchar_t *param_4)

{
  FUN_40bd4ea8(param_1,0,param_2,param_2 + 0x6c,param_3,param_4);
  *param_1 = &PTR_FUN_40bdb744;
  param_1[3] = &PTR_FUN_40bdb6fc;
  param_1[4] = &PTR_LAB_40bdb6e8;
  param_1[0x28] = &PTR_LAB_40bdb6cc;
  param_1[0x29] = param_1;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  FUN_40bd67d0(param_1 + 0x2c);
  return param_1;
}



/* 40bcd640 FUN_40bcd640 */

/* Boundary evidence: original MIPS .pdata 40bcd640..40bcd66f. Semantic name remains unreviewed. */

void FUN_40bcd640(void)

{
  int *in_v0;
  
  FUN_40bcc150(*in_v0);
  return;
}



/* 40bcd670 FUN_40bcd670 */

/* Boundary evidence: original MIPS .pdata 40bcd670..40bcd697. Semantic name remains unreviewed. */

void FUN_40bcd670(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40bcd698 FUN_40bcd698 */

/* Boundary evidence: original MIPS .pdata 40bcd698..40bcd6bf. Semantic name remains unreviewed. */

void FUN_40bcd698(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40bcd6c0 FUN_40bcd6c0 */

/* Boundary evidence: original MIPS .pdata 40bcd6c0..40bcd6e7. Semantic name remains unreviewed. */

void FUN_40bcd6c0(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40bcd6e8 FUN_40bcd6e8 */

/* Boundary evidence: original MIPS .pdata 40bcd6e8..40bcd707. Semantic name remains unreviewed. */

undefined4 FUN_40bcd6e8(int param_1)

{
  FUN_40bd740c(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40bcd708 FUN_40bcd708 */

/* Boundary evidence: original MIPS .pdata 40bcd708..40bcd727. Semantic name remains unreviewed. */

undefined4 FUN_40bcd708(int param_1)

{
  FUN_40bd6b14(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40bcd728 FUN_40bcd728 */

/* Boundary evidence: original MIPS .pdata 40bcd728..40bcd74f. Semantic name remains unreviewed. */

undefined4 FUN_40bcd728(int param_1)

{
  *(undefined4 *)(param_1 + 0xa8) = 1;
  FUN_40bd74ac(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40bcd78c FUN_40bcd78c */

/* Boundary evidence: original MIPS .pdata 40bcd78c..40bcd7e7. Semantic name remains unreviewed. */

int FUN_40bcd78c(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  
  iVar1 = FUN_40bd1b08(param_1);
  if (-1 < iVar1) {
    p_Var2 = *(LPCRITICAL_SECTION *)(param_1 + 0xac);
    if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
      FUN_40bd6fc8(p_Var2);
      operator_delete(p_Var2);
    }
    *(undefined4 *)(param_1 + 0xac) = 0;
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bcd7e8 FUN_40bcd7e8 */

/* Boundary evidence: original MIPS .pdata 40bcd7e8..40bcd93f. Semantic name remains unreviewed. */

DWORD FUN_40bcd7e8(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  LPCRITICAL_SECTION p_Var3;
  DWORD local_70;
  LPCRITICAL_SECTION local_6c;
  undefined1 auStack_68 [72];
  uint local_20;
  
  uVar1 = DAT_40be0550;
  local_20 = DAT_40be0550;
  *(undefined4 *)(param_1 + 0xa8) = 1;
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_40bd8bd0(uVar1);
    DVar2 = 0;
  }
  else {
    DVar2 = FUN_40bd1ac8(param_1);
    if ((int)DVar2 < 0) {
      FUN_40bd8bd0(local_20);
    }
    else {
      local_70 = 0;
      (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))((int *)(param_1 + 0xc),auStack_68);
      FUN_40bd62f4((int)auStack_68);
      local_6c = operator_new(0x54);
      if (local_6c == (LPCRITICAL_SECTION)0x0) {
        p_Var3 = (LPCRITICAL_SECTION)0x0;
      }
      else {
        p_Var3 = FUN_40bd75dc(local_6c,*(undefined4 **)(param_1 + 0x18),&local_70,0,1,1,0,200,3);
      }
      *(LPCRITICAL_SECTION *)(param_1 + 0xac) = p_Var3;
      if (p_Var3 == (LPCRITICAL_SECTION)0x0) {
        FUN_40bd8bd0(local_20);
        DVar2 = 0x8007000e;
      }
      else {
        if ((int)local_70 < 0) {
          FUN_40bd6fc8(p_Var3);
          operator_delete(p_Var3);
          *(undefined4 *)(param_1 + 0xac) = 0;
        }
        DVar2 = local_70;
        FUN_40bd8bd0(local_20);
      }
    }
  }
  return DVar2;
}



/* 40bcd940 FUN_40bcd940 */

/* Boundary evidence: original MIPS .pdata 40bcd940..40bcd96f. Semantic name remains unreviewed. */

void FUN_40bcd940(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x6c));
  return;
}



/* 40bcd970 FUN_40bcd970 */

/* Boundary evidence: original MIPS .pdata 40bcd970..40bcda33. Semantic name remains unreviewed. */

void FUN_40bcd970(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &PTR_FUN_40bdb744;
  param_1[3] = &PTR_FUN_40bdb6fc;
  param_1[4] = &PTR_LAB_40bdb6e8;
  if (param_1[0x2e] != 0) {
    do {
      pvVar1 = (void *)FUN_40bd6ab4(param_1 + 0x2c);
      if (pvVar1 != (void *)0x0) {
        FUN_40bd6358((int)pvVar1);
        operator_delete(pvVar1);
      }
    } while (param_1[0x2e] != 0);
  }
  FUN_40bd6a6c(param_1 + 0x2c);
  FUN_40bd13bc((int)param_1);
  return;
}



/* 40bcda34 FUN_40bcda34 */

/* Boundary evidence: original MIPS .pdata 40bcda34..40bcda63. Semantic name remains unreviewed. */

void FUN_40bcda34(void)

{
  int *in_v0;
  
  FUN_40bcc150(*in_v0);
  return;
}



/* 40bcda64 FUN_40bcda64 */

/* Boundary evidence: original MIPS .pdata 40bcda64..40bcda97. Semantic name remains unreviewed. */

void FUN_40bcda64(void)

{
  int *in_v0;
  
  FUN_40bcc16c((undefined4 *)(*in_v0 + 0xb0));
  return;
}



/* 40bcda98 FUN_40bcda98 */

/* Boundary evidence: original MIPS .pdata 40bcda98..40bcdb17. Semantic name remains unreviewed. */

undefined4 FUN_40bcda98(int param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + 0xb0);
  do {
    if (local_18[0] == 0) {
      return 1;
    }
    pvVar1 = (void *)FUN_40bd6848((int *)(param_1 + 0xb0),local_18);
    iVar2 = FUN_40bd64c4(pvVar1,param_2);
  } while (iVar2 == 0);
  return 0;
}



/* 40bcdb18 FUN_40bcdb18 */

/* Boundary evidence: original MIPS .pdata 40bcdb18..40bcdb9b. Semantic name remains unreviewed. */

undefined4 FUN_40bcdb18(int param_1,int param_2,void *param_3)

{
  bool bVar1;
  void *pvVar2;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + 0xb0);
  do {
    if (local_18[0] == 0) {
      return 0x40103;
    }
    pvVar2 = (void *)FUN_40bd6848((int *)(param_1 + 0xb0),local_18);
    bVar1 = param_2 != 0;
    param_2 = param_2 + -1;
  } while (bVar1);
  FUN_40bd6498(param_3,pvVar2);
  return 0;
}



/* 40bcdb9c FUN_40bcdb9c */

/* Boundary evidence: original MIPS .pdata 40bcdb9c..40bcdc47. Semantic name remains unreviewed. */

undefined4 FUN_40bcdb9c(int param_1,void *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  pvVar1 = operator_new(0x48);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = FUN_40bd6420(pvVar1,param_2);
  }
  if (pvVar1 != (void *)0x0) {
    puVar2 = FUN_40bd6970((undefined4 *)(param_1 + 0xb0),pvVar1);
    if (puVar2 != (undefined4 *)0x0) {
      return 0;
    }
    FUN_40bd6358((int)pvVar1);
    operator_delete(pvVar1);
  }
  return 0x8007000e;
}



/* 40bcdc48 FUN_40bcdc48 */

/* Boundary evidence: original MIPS .pdata 40bcdc48..40bcdc77. Semantic name remains unreviewed. */

void FUN_40bcdc48(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40bcdc78 FUN_40bcdc78 */

/* Boundary evidence: original MIPS .pdata 40bcdc78..40bcdd83. Semantic name remains unreviewed. */

undefined4 *
FUN_40bcdc78(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  FUN_40bd4908(param_1,param_2,param_3,(LPCRITICAL_SECTION)(param_1 + 0x1b),param_4);
  *param_1 = &PTR_FUN_40bdb918;
  param_1[3] = &PTR_FUN_40bdb8dc;
  param_1[4] = &PTR_LAB_40bdb8c8;
  param_1[0x14] = 0;
  FUN_40bd67d0(param_1 + 0x15);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1b));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  param_1[0x2a] = 0;
  param_1[0x2b] = 0x7b785574;
  param_1[0x2c] = 0x11cf8c82;
  param_1[0x2d] = 0xaa000cbc;
  param_1[0x2e] = 0xf674ac00;
  param_1[0x2f] = &PTR_FUN_40bdb6c8;
  param_1[0x30] = param_1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
  param_1[0x36] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 1;
  return param_1;
}



/* 40bcdd84 FUN_40bcdd84 */

/* Boundary evidence: original MIPS .pdata 40bcdd84..40bcddb3. Semantic name remains unreviewed. */

void FUN_40bcdd84(void)

{
  int *in_v0;
  
  FUN_40bd3474(*in_v0);
  return;
}



/* 40bcddb4 FUN_40bcddb4 */

/* Boundary evidence: original MIPS .pdata 40bcddb4..40bcdddb. Semantic name remains unreviewed. */

void FUN_40bcddb4(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40bcdddc FUN_40bcdddc */

/* Boundary evidence: original MIPS .pdata 40bcdddc..40bcde03. Semantic name remains unreviewed. */

void FUN_40bcdddc(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40bcde04 FUN_40bcde04 */

/* Boundary evidence: original MIPS .pdata 40bcde04..40bcde2b. Semantic name remains unreviewed. */

void FUN_40bcde04(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40bcde68 FUN_40bcde68 */

/* Boundary evidence: original MIPS .pdata 40bcde68..40bcdf8b. Semantic name remains unreviewed. */

undefined4 FUN_40bcde68(int param_1)

{
  int *piVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int local_28;
  LPCRITICAL_SECTION local_24;
  LPCRITICAL_SECTION local_20;
  
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x60);
  local_24 = lpCriticalSection_00;
  EnterCriticalSection(lpCriticalSection_00);
  if (*(int *)(param_1 + 8) == 0) {
    local_28 = *(int *)(param_1 + 0x48);
    while (local_28 != 0) {
      piVar1 = (int *)FUN_40bd6848((int *)(param_1 + 0x48),&local_28);
      if (piVar1[6] != 0) {
        (**(code **)(*piVar1 + 0x14))(piVar1);
      }
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x74);
    local_20 = lpCriticalSection;
    EnterCriticalSection(lpCriticalSection);
    if ((*(int **)(param_1 + 0x44))[6] != 0) {
      (**(code **)(**(int **)(param_1 + 0x44) + 0x14))();
    }
    *(undefined4 *)(param_1 + 8) = 1;
    iVar2 = *(int *)(*(int *)(param_1 + 0x44) + 0x9c);
    if ((iVar2 != 0) && (iVar2 = iVar2 + -0xc, iVar2 != 0)) {
      FUN_40bc3b08(iVar2);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    *(undefined4 *)(param_1 + 8) = 1;
  }
  LeaveCriticalSection(lpCriticalSection_00);
  return 0;
}



/* 40bcdf8c FUN_40bcdf8c */

/* Boundary evidence: original MIPS .pdata 40bcdf8c..40bcdfbb. Semantic name remains unreviewed. */

void FUN_40bcdf8c(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40bcdfbc FUN_40bcdfbc */

/* Boundary evidence: original MIPS .pdata 40bcdfbc..40bcdfeb. Semantic name remains unreviewed. */

void FUN_40bcdfbc(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bcdfec FUN_40bcdfec */

/* Boundary evidence: original MIPS .pdata 40bcdfec..40bce14b. Semantic name remains unreviewed. */

undefined4 FUN_40bcdfec(int param_1)

{
  int *piVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int local_28;
  LPCRITICAL_SECTION local_24;
  LPCRITICAL_SECTION local_20;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x60);
  local_24 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (*(int **)(param_1 + 0x44) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
    }
    lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x74);
    local_20 = lpCriticalSection_00;
    EnterCriticalSection(lpCriticalSection_00);
    if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x9c) + 0x14))();
    }
    if (*(int *)(param_1 + 0xcc) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0x44))();
    }
    local_28 = *(int *)(param_1 + 0x48);
    while (local_28 != 0) {
      piVar1 = (int *)FUN_40bd6848((int *)(param_1 + 0x48),&local_28);
      if (piVar1[6] != 0) {
        (**(code **)(*piVar1 + 0x18))(piVar1);
      }
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x44) + 0x9c);
    if ((iVar2 != 0) && (iVar2 = iVar2 + -0xc, iVar2 != 0)) {
      FUN_40bc3b08(iVar2);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* 40bce14c FUN_40bce14c */

/* Boundary evidence: original MIPS .pdata 40bce14c..40bce17b. Semantic name remains unreviewed. */

void FUN_40bce14c(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40bce17c FUN_40bce17c */

/* Boundary evidence: original MIPS .pdata 40bce17c..40bce1ab. Semantic name remains unreviewed. */

void FUN_40bce17c(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bce1ac FUN_40bce1ac */

/* Boundary evidence: original MIPS .pdata 40bce1ac..40bce207. Semantic name remains unreviewed. */

int FUN_40bce1ac(int param_1)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x5c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  return (uint)(iVar1 != 0) + iVar2;
}



/* 40bce208 FUN_40bce208 */

/* Boundary evidence: original MIPS .pdata 40bce208..40bce307. Semantic name remains unreviewed. */

int FUN_40bce208(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_20;
  LPCRITICAL_SECTION local_1c;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x94);
  local_1c = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if ((param_2 == 0) && (iVar2 = *(int *)(param_1 + 0x50), iVar2 != 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (*(int *)(param_1 + 0x50) != 0) {
      param_2 = param_2 + -1;
    }
    if ((param_2 < 0) || (*(int *)(param_1 + 0x5c) <= param_2)) {
      LeaveCriticalSection(lpCriticalSection);
      iVar2 = 0;
    }
    else {
      piVar1 = (int *)(param_1 + 0x54);
      local_20 = *piVar1;
      for (; 0 < param_2; param_2 = param_2 + -1) {
        FUN_40bd6848(piVar1,&local_20);
      }
      iVar2 = FUN_40bd6848(piVar1,&local_20);
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar2;
}



/* 40bce308 FUN_40bce308 */

/* Boundary evidence: original MIPS .pdata 40bce308..40bce337. Semantic name remains unreviewed. */

void FUN_40bce308(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40bce338 FUN_40bce338 */

/* Boundary evidence: original MIPS .pdata 40bce338..40bce417. Semantic name remains unreviewed. */

bool FUN_40bce338(int param_1,int *param_2)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x94);
  EnterCriticalSection(lpCriticalSection_00);
  FUN_40bd103c(param_1);
  (**(code **)(param_2[3] + 4))();
  puVar1 = FUN_40bd6970((undefined4 *)(param_1 + 0x54),param_2);
  if (puVar1 != (undefined4 *)0x0) {
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    (**(code **)(*param_2 + 0xc))(param_2,1);
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
  }
  return puVar1 != (undefined4 *)0x0;
}



/* 40bce418 FUN_40bce418 */

/* Boundary evidence: original MIPS .pdata 40bce418..40bce447. Semantic name remains unreviewed. */

void FUN_40bce418(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bce448 FUN_40bce448 */

/* Boundary evidence: original MIPS .pdata 40bce448..40bce477. Semantic name remains unreviewed. */

void FUN_40bce448(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40bce478 FUN_40bce478 */

/* Boundary evidence: original MIPS .pdata 40bce478..40bce573. Semantic name remains unreviewed. */

void FUN_40bce478(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  iVar1 = FUN_40bd6ab4((int *)(param_1 + 0x54));
  while (iVar1 != 0) {
    FUN_40bd103c(param_1);
    if (*(int **)(iVar1 + 0x18) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x18) + 0x14))();
      (**(code **)(*(int *)(iVar1 + 0xc) + 0x14))();
    }
    (**(code **)(*(int *)(iVar1 + 0xc) + 8))();
    iVar1 = FUN_40bd6ab4((int *)(param_1 + 0x54));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return;
}



/* 40bce574 FUN_40bce574 */

/* Boundary evidence: original MIPS .pdata 40bce574..40bce5a3. Semantic name remains unreviewed. */

void FUN_40bce574(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40bce5a4 FUN_40bce5a4 */

/* Boundary evidence: original MIPS .pdata 40bce5a4..40bce5d3. Semantic name remains unreviewed. */

void FUN_40bce5a4(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40bce5d4 FUN_40bce5d4 */

/* Boundary evidence: original MIPS .pdata 40bce5d4..40bce6eb. Semantic name remains unreviewed. */

int FUN_40bce5d4(int param_1,wchar_t *param_2,int *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int local_20;
  undefined4 *local_1c;
  
  local_20 = 0;
  local_1c = operator_new(200);
  if (local_1c == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_40bcd59c(local_1c,param_1,&local_20,param_2);
  }
  if (local_20 < 0) {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
    }
  }
  else if (piVar2 == (int *)0x0) {
    local_20 = -0x7ff8fff2;
  }
  else {
    bVar1 = FUN_40bce338(param_1,piVar2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
      local_20 = -0x7ff8fff2;
    }
    else {
      *param_3 = (int)(piVar2 + 0x28);
      local_20 = 0;
    }
  }
  return local_20;
}



/* 40bce6ec FUN_40bce6ec */

/* Boundary evidence: original MIPS .pdata 40bce6ec..40bce71b. Semantic name remains unreviewed. */

void FUN_40bce6ec(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x1c));
  return;
}



/* 40bce71c FUN_40bce71c */

/* Boundary evidence: original MIPS .pdata 40bce71c..40bceaab. Semantic name remains unreviewed. */

int FUN_40bce71c(int *param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined ***pppuVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  void *_Buf1;
  int local_60;
  int local_5c;
  int *local_58;
  undefined **local_50;
  int *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [16];
  
  local_5c = 0;
  local_60 = -0x7fffbffb;
  iVar6 = param_1[0x14];
  piVar7 = *(int **)(iVar6 + 0x120);
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 4))();
  }
  piVar7 = *(int **)(iVar6 + 0x120);
  local_58 = operator_new(0x20);
  if (local_58 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    param_3 = &local_60;
    piVar1 = FUN_40bc6304(local_58,piVar7,param_3);
  }
  iVar6 = FUN_40bc69cc(piVar1,&local_5c,param_3,(va_list)param_4);
  local_60 = iVar6;
  if ((iVar6 < 0) || (local_5c == 0)) {
    if (piVar1 != (int *)0x0) {
      FUN_40bc63a8(piVar1);
      operator_delete(piVar1);
    }
    (**(code **)(*piVar7 + 8))(piVar7);
    FUN_40bc3b24(0x40bdbb50,local_60,param_3,(va_list)param_4);
    local_60 = -0x7ffbfdd6;
  }
  else {
    _Buf1 = *(void **)(local_5c + 4);
    iVar2 = memcmp(_Buf1,&DAT_40bde218,0x10);
    if ((iVar2 != 0) && (iVar2 = memcmp(_Buf1,&DAT_40bdd618,0x10), iVar2 != 0)) {
      iVar6 = -0x7ffbfdd6;
      local_60 = -0x7ffbfdd6;
    }
    if (piVar1 != (int *)0x0) {
      FUN_40bc63a8(piVar1);
      operator_delete(piVar1);
      iVar6 = local_60;
    }
    if (iVar6 < 0) {
      (**(code **)(*piVar7 + 8))(piVar7);
    }
    else {
      local_50 = &PTR_FUN_40bdb6b0;
      piVar5 = param_1 + 0x2f;
      pppuVar4 = &local_50;
      local_48 = 0;
      local_44 = 0;
      local_4c = piVar7;
      piVar1 = (int *)(**(code **)(*param_1 + 0x3c))(param_1);
      param_1[0x2a] = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        pppuVar4 = &local_50;
        local_60 = (**(code **)(*piVar1 + 4))(piVar1);
      }
      if (param_1[0x2a] == 0) {
        (**(code **)(*piVar7 + 8))(piVar7);
        local_60 = -0x7ff8fff2;
      }
      else {
        if (-1 < local_60) {
          *(int *)(param_1[0x14] + 0xd8) = param_1[0x2a];
          if (*(int *)(param_1[0x14] + 0x9c) == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = *(int *)(param_1[0x14] + 0x9c) + -0xc;
          }
          (**(code **)(*(int *)(iVar6 + 0xc) + 0x10))((int *)(iVar6 + 0xc),&local_40);
          local_40 = 3;
          local_3c = 0x20000;
          local_38 = 0x200;
          local_34 = 0;
          piVar1 = *(int **)(param_1[0x14] + 0x9c);
          if ((piVar1 == (int *)0x0) || (piVar1 == (int *)0xc)) {
            piVar1 = (int *)0x0;
          }
          (**(code **)(*piVar1 + 0xc))(piVar1,&local_40,auStack_30);
          piVar5 = param_1 + 0x2b;
          pppuVar4 = (undefined ***)(param_1 + 0x3a);
          (**(code **)(*(int *)param_1[0x2a] + 0x24))();
        }
        if (param_1[0x36] != 0) {
          FUN_40bc3b24(0x40bdbc3c,pppuVar4,piVar5,(va_list)param_4);
          piVar1 = (int *)param_1[0x36];
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0xc))(piVar1,1);
          }
          param_1[0x36] = 0;
        }
        if (param_1[0x36] == 0) {
          local_58 = operator_new(0x50);
          if (local_58 == (int *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            piVar5 = (int *)param_1[1];
            param_4 = &local_60;
            puVar3 = FUN_40bd0d04(local_58,param_1,piVar5);
          }
          param_1[0x36] = (int)puVar3;
          if (puVar3 == (undefined4 *)0x0) {
            FUN_40bc3b24(0x40bdbbe8,local_60,piVar5,(va_list)param_4);
          }
        }
        (**(code **)(*piVar7 + 8))(piVar7);
      }
    }
  }
  return local_60;
}



/* 40bceaac FUN_40bceaac */

/* Boundary evidence: original MIPS .pdata 40bceaac..40bceadb. Semantic name remains unreviewed. */

void FUN_40bceaac(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x58));
  return;
}



/* 40bceadc FUN_40bceadc */

/* Boundary evidence: original MIPS .pdata 40bceadc..40bceb0b. Semantic name remains unreviewed. */

void FUN_40bceadc(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x58));
  return;
}



/* 40bceb0c FUN_40bceb0c */

/* Boundary evidence: original MIPS .pdata 40bceb0c..40bcebcb. Semantic name remains unreviewed. */

int FUN_40bceb0c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_18;
  int local_14;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
  iVar4 = 0;
  iVar2 = iVar3 + -0xc;
  if (iVar3 == 0) {
    iVar2 = 0;
  }
  uVar1 = FUN_40bc3544(iVar2,&local_14);
  if (local_14 != 0) {
    local_18 = 0;
    iVar4 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x1c))
                      (*(int **)(param_1 + 0xa8),uVar1,local_14,&local_18,param_2);
    if (iVar4 < 0) {
      iVar4 = 1;
    }
    else if (local_18 != 0) {
      iVar3 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
      iVar2 = iVar3 + -0xc;
      if (iVar3 == 0) {
        iVar2 = 0;
      }
      FUN_40bc398c(iVar2,local_18);
    }
  }
  return iVar4;
}



/* 40bcebcc FUN_40bcebcc */

/* Boundary evidence: original MIPS .pdata 40bcebcc..40bcec73. Semantic name remains unreviewed. */

void FUN_40bcebcc(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_10 [2];
  
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xa8) + 0x18))();
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
  if ((iVar2 != 0) && (iVar2 = iVar2 + -0xc, iVar2 != 0)) {
    FUN_40bc3b08(iVar2);
  }
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40bd6848((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x4c))(piVar1);
    }
  }
  return;
}



/* 40bcec74 FUN_40bcec74 */

/* Boundary evidence: original MIPS .pdata 40bcec74..40bcecfb. Semantic name remains unreviewed. */

undefined4 FUN_40bcec74(int param_1)

{
  int *piVar1;
  int local_10 [2];
  
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xa8) + 0xc))();
  }
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40bd6848((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x50))(piVar1);
    }
  }
  return 0;
}



/* 40bcecfc FUN_40bcecfc */

/* Boundary evidence: original MIPS .pdata 40bcecfc..40bceda7. Semantic name remains unreviewed. */

undefined4 FUN_40bcecfc(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_10 [2];
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
  if ((iVar2 != 0) && (iVar2 = iVar2 + -0xc, iVar2 != 0)) {
    FUN_40bc3b08(iVar2);
  }
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xa8) + 0x10))();
  }
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40bd6848((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x54))(piVar1);
    }
  }
  return 0;
}



/* 40bceda8 FUN_40bceda8 */

/* Boundary evidence: original MIPS .pdata 40bceda8..40bcedef. Semantic name remains unreviewed. */

void FUN_40bceda8(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xa8);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  FUN_40bce478(param_1);
  return;
}



/* 40bcedf0 FUN_40bcedf0 */

/* Boundary evidence: original MIPS .pdata 40bcedf0..40bceef3. Semantic name remains unreviewed. */

undefined4 FUN_40bcedf0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int local_20 [2];
  
  piVar1 = *(int **)(param_1 + 0xa8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x34))
              (piVar1,param_2,*(undefined4 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xe4),
               *(undefined4 *)(param_1 + 0xe8),*(undefined4 *)(param_1 + 0xec));
    piVar1 = *(int **)(param_1 + 0xa8);
    iVar2 = *piVar1;
    __litodp(*(undefined4 *)(param_1 + 0xf0));
    (**(code **)(iVar2 + 0x3c))(piVar1);
  }
  local_20[0] = *(int *)(param_1 + 0x54);
  while (local_20[0] != 0) {
    piVar1 = (int *)FUN_40bd6848((int *)(param_1 + 0x54),local_20);
    if (piVar1[6] != 0) {
      iVar2 = *piVar1;
      __litodp(*(undefined4 *)(param_1 + 0xf0));
      (**(code **)(iVar2 + 0x58))(piVar1);
    }
  }
  return 0;
}



/* 40bceef4 FUN_40bceef4 */

/* Boundary evidence: original MIPS .pdata 40bceef4..40bcf06f. Semantic name remains unreviewed. */

undefined4
FUN_40bceef4(int param_1,undefined ***param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined ***pppuVar2;
  undefined4 uVar3;
  va_list pcVar4;
  int *piVar5;
  int *piVar6;
  undefined **local_30;
  int *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  piVar6 = *(int **)(param_1 + 0x50);
  if ((int *)piVar6[0x48] != (int *)0x0) {
    (**(code **)(*(int *)piVar6[0x48] + 4))();
  }
  piVar5 = (int *)piVar6[0x48];
  local_30 = &PTR_FUN_40bdb6b0;
  local_28 = 0;
  local_24 = 0;
  *(undefined4 *)(param_1 + 0xe0) = param_3;
  *(undefined4 *)(param_1 + 0xe4) = param_4;
  *(undefined4 *)(param_1 + 0xe8) = param_5;
  *(undefined4 *)(param_1 + 0xec) = param_6;
  local_2c = piVar5;
  bVar1 = FUN_40bccdd8((int)piVar6);
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    pcVar4 = *(va_list *)(param_1 + 0xe4);
    uVar3 = *(undefined4 *)(param_1 + 0xe0);
    param_2 = &local_30;
    pppuVar2 = (undefined ***)(**(code **)(**(int **)(param_1 + 0xa8) + 0x30))();
    if ((int)pppuVar2 < 0) {
      FUN_40bc3b24(0x40bdbd48,pppuVar2,uVar3,pcVar4);
      param_2 = pppuVar2;
    }
  }
  FUN_40bcce70(piVar6,param_2,0,0,0,0,CONCAT31(extraout_var,bVar1));
  (**(code **)(*piVar5 + 8))(piVar5);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  return 0;
}



/* 40bcf070 FUN_40bcf070 */

/* Boundary evidence: original MIPS .pdata 40bcf070..40bcf09f. Semantic name remains unreviewed. */

void FUN_40bcf070(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x48));
  return;
}



/* 40bcf0a0 FUN_40bcf0a0 */

/* Boundary evidence: original MIPS .pdata 40bcf0a0..40bcf137. Semantic name remains unreviewed. */

undefined4 FUN_40bcf0a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  piVar2 = *(int **)(param_1 + 0x50);
  iVar1 = __dptoli(param_3,param_4);
  *(int *)(param_1 + 0xf0) = iVar1;
  FUN_40bccf60(piVar2,iVar1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  return 0;
}



/* 40bcf138 FUN_40bcf138 */

/* Boundary evidence: original MIPS .pdata 40bcf138..40bcf167. Semantic name remains unreviewed. */

void FUN_40bcf138(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40bcf168 FUN_40bcf168 */

/* Boundary evidence: original MIPS .pdata 40bcf168..40bcf1b3. Semantic name remains unreviewed. */

void * FUN_40bcf168(void *param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  FUN_40bcc938((int)param_1,param_2,param_3,param_4);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bcf1b4 FUN_40bcf1b4 */

/* Boundary evidence: original MIPS .pdata 40bcf1b4..40bcf29f. Semantic name remains unreviewed. */

int FUN_40bcf1b4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + -0x28) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*(int *)(param_1 + -0x98) + 0x38))();
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + -0x28) + 0x30))(*(int **)(param_1 + -0x28),param_2);
    if ((iVar1 != 0) && (iVar1 < 0)) {
      iVar2 = *(int *)(param_1 + -0x28);
      iVar3 = *(int *)(iVar2 + 0xa8);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 4) = 1;
      }
      FUN_40bd0ff4(iVar2);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40bcf2a0 FUN_40bcf2a0 */

/* Boundary evidence: original MIPS .pdata 40bcf2a0..40bcf2cf. Semantic name remains unreviewed. */

void FUN_40bcf2a0(void)

{
  int in_v0;
  
  FUN_40bc314c((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bcf2d0 FUN_40bcf2d0 */

/* Boundary evidence: original MIPS .pdata 40bcf2d0..40bcf37f. Semantic name remains unreviewed. */

int FUN_40bcf2d0(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xd8) == 0) {
    return -0x7fff0001;
  }
  iVar1 = FUN_40bd16fc();
  if (iVar1 < 0) {
    FUN_40bc3b24(0x40bdbe38,param_2,param_3,param_4);
  }
  else {
    iVar1 = FUN_40bcedf0(*(int *)(param_1 + 0x70),param_2);
    if (iVar1 < 0) {
      FUN_40bc3b24(0x40bdbe8c,iVar1,param_3,param_4);
    }
    else {
      FUN_40bc4924((LPVOID)(param_1 + 0xe0));
    }
  }
  return iVar1;
}



/* 40bcf380 FUN_40bcf380 */

/* Boundary evidence: original MIPS .pdata 40bcf380..40bcf39b. Semantic name remains unreviewed. */

void FUN_40bcf380(int param_1,wchar_t *param_2,int *param_3)

{
  FUN_40bce5d4(*(int *)(param_1 + 4),param_2,param_3);
  return;
}



/* 40bcf39c FUN_40bcf39c */

/* Boundary evidence: original MIPS .pdata 40bcf39c..40bcf3b7. Semantic name remains unreviewed. */

void FUN_40bcf39c(int param_1,void *param_2)

{
  FUN_40bcdb9c(*(int *)(param_1 + 4),param_2);
  return;
}



/* 40bcf3b8 FUN_40bcf3b8 */

/* Boundary evidence: original MIPS .pdata 40bcf3b8..40bcf403. Semantic name remains unreviewed. */

undefined4 * FUN_40bcf3b8(undefined4 *param_1,uint param_2)

{
  FUN_40bcd970(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bcf404 FUN_40bcf404 */

/* Boundary evidence: original MIPS .pdata 40bcf404..40bcf4bf. Semantic name remains unreviewed. */

void FUN_40bcf404(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40bdb918;
  param_1[3] = &PTR_FUN_40bdb8dc;
  param_1[4] = &PTR_LAB_40bdb8c8;
  piVar1 = (int *)param_1[0x14];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
  }
  param_1[0x14] = 0;
  FUN_40bce478((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1b));
  FUN_40bd6a6c(param_1 + 0x15);
  FUN_40bd3474((int)param_1);
  return;
}



/* 40bcf4c0 FUN_40bcf4c0 */

/* Boundary evidence: original MIPS .pdata 40bcf4c0..40bcf4ef. Semantic name remains unreviewed. */

void FUN_40bcf4c0(void)

{
  int *in_v0;
  
  FUN_40bd3474(*in_v0);
  return;
}



/* 40bcf4f0 FUN_40bcf4f0 */

/* Boundary evidence: original MIPS .pdata 40bcf4f0..40bcf523. Semantic name remains unreviewed. */

void FUN_40bcf4f0(void)

{
  int *in_v0;
  
  FUN_40bcc460((undefined4 *)(*in_v0 + 0x54));
  return;
}



/* 40bcf524 FUN_40bcf524 */

/* Boundary evidence: original MIPS .pdata 40bcf524..40bcf557. Semantic name remains unreviewed. */

void FUN_40bcf524(void)

{
  int *in_v0;
  
  FUN_40bcc074((LPCRITICAL_SECTION)(*in_v0 + 0x6c));
  return;
}



/* 40bcf558 FUN_40bcf558 */

/* Boundary evidence: original MIPS .pdata 40bcf558..40bcf58b. Semantic name remains unreviewed. */

void FUN_40bcf558(void)

{
  int *in_v0;
  
  FUN_40bcc074((LPCRITICAL_SECTION)(*in_v0 + 0x80));
  return;
}



/* 40bcf58c FUN_40bcf58c */

/* Boundary evidence: original MIPS .pdata 40bcf58c..40bcf5bf. Semantic name remains unreviewed. */

void FUN_40bcf58c(void)

{
  int *in_v0;
  
  FUN_40bcc074((LPCRITICAL_SECTION)(*in_v0 + 0x94));
  return;
}



/* 40bcf5c0 FUN_40bcf5c0 */

/* Boundary evidence: original MIPS .pdata 40bcf5c0..40bcf5f3. Semantic name remains unreviewed. */

void FUN_40bcf5c0(void)

{
  int *in_v0;
  
  FUN_40bcc074((LPCRITICAL_SECTION)(*in_v0 + 0xc4));
  return;
}



/* 40bcf5f4 FUN_40bcf5f4 */

/* Boundary evidence: original MIPS .pdata 40bcf5f4..40bcf66f. Semantic name remains unreviewed. */

void FUN_40bcf5f4(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
  iVar1 = iVar2 + -0xc;
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  FUN_40bc34d4(iVar1,param_2);
  iVar1 = (**(code **)(*param_2 + 0x3c))(param_2);
  FUN_40bceb0c(param_1,(uint)(iVar1 == 0));
  return;
}



/* 40bcf670 FUN_40bcf670 */

/* Boundary evidence: original MIPS .pdata 40bcf670..40bcf6bb. Semantic name remains unreviewed. */

undefined4 * FUN_40bcf670(undefined4 *param_1,uint param_2)

{
  FUN_40bcf404(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bcf6bc FUN_40bcf6bc */

/* Boundary evidence: original MIPS .pdata 40bcf6bc..40bcf6d7. Semantic name remains unreviewed. */

void FUN_40bcf6bc(HMODULE param_1,int param_2)

{
  FUN_40bd78e4(param_1,param_2);
  return;
}



/* 40bcf6d8 DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40bcf6d8..40bcf6f3. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0xf6d8  3  DllRegisterServer */
  FUN_40bd85ec(1);
  return;
}



/* 40bcf6f4 DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40bcf6f4..40bcf70f. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0xf6f4  4  DllUnregisterServer */
  FUN_40bd85ec(0);
  return;
}



/* 40bcf710 FUN_40bcf710 */

/* Boundary evidence: original MIPS .pdata 40bcf710..40bcf7fb. Semantic name remains unreviewed. */

void FUN_40bcf710(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_40bdc678;
  param_1[3] = &PTR_FUN_40bdc63c;
  param_1[4] = &PTR_LAB_40bdc628;
  param_1[0x3e] = &PTR_LAB_40bdc610;
  puVar1 = (undefined4 *)param_1[0x2a];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    param_1[0x2a] = 0;
  }
  piVar2 = (int *)param_1[0x14];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,1);
    param_1[0x14] = 0;
  }
  piVar2 = (int *)param_1[0x36];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,1);
    param_1[0x36] = 0;
  }
  if (DAT_40be058c != 0) {
    DAT_40be058c = 0;
  }
  FUN_40bcf404(param_1);
  return;
}



/* 40bcf7fc FUN_40bcf7fc */

/* Boundary evidence: original MIPS .pdata 40bcf7fc..40bcf82b. Semantic name remains unreviewed. */

void FUN_40bcf7fc(void)

{
  undefined4 *in_v0;
  
  FUN_40bcf404((undefined4 *)*in_v0);
  return;
}



/* 40bcf82c FUN_40bcf82c */

/* Boundary evidence: original MIPS .pdata 40bcf82c..40bcf853. Semantic name remains unreviewed. */

void FUN_40bcf82c(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40bcf854 FUN_40bcf854 */

/* Boundary evidence: original MIPS .pdata 40bcf854..40bcf87b. Semantic name remains unreviewed. */

void FUN_40bcf854(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40bcf87c FUN_40bcf87c */

/* Boundary evidence: original MIPS .pdata 40bcf87c..40bcf8a3. Semantic name remains unreviewed. */

void FUN_40bcf87c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40bcf8a4 FUN_40bcf8a4 */

/* Boundary evidence: original MIPS .pdata 40bcf8a4..40bcf9bb. Semantic name remains unreviewed. */

void FUN_40bcf8a4(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40bdd078,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x3e;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40bd53bc(piVar2,param_3);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40bdcd58,0x10);
    if ((((iVar1 == 0) && (param_1[0x36] != 0)) ||
        ((iVar1 = memcmp(param_2,&DAT_40bde6f8,0x10), iVar1 == 0 && (param_1[0x36] != 0)))) ||
       ((iVar1 = memcmp(param_2,&DAT_40bdeba0,0x10), iVar1 == 0 && (param_1[0x36] != 0)))) {
      (*(code *)**(undefined4 **)param_1[0x36])((undefined4 *)param_1[0x36],param_2,param_3);
    }
    else {
      FUN_40bd3394(param_1,param_2,param_3);
    }
  }
  return;
}



/* 40bcf9bc FUN_40bcf9bc */

/* Boundary evidence: original MIPS .pdata 40bcf9bc..40bcfa83. Semantic name remains unreviewed. */

undefined4 FUN_40bcf9bc(undefined4 param_1,void *param_2)

{
  int iVar1;
  void *_Buf1;
  
  iVar1 = memcmp(param_2,&DAT_40bdd348,0x10);
  if (iVar1 == 0) {
    _Buf1 = (void *)((int)param_2 + 0x10);
    iVar1 = memcmp(_Buf1,&DAT_40bdd618,0x10);
    if ((((iVar1 == 0) || (iVar1 = memcmp(_Buf1,&DAT_40bdd638,0x10), iVar1 == 0)) ||
        (iVar1 = memcmp(_Buf1,&DAT_40bde218,0x10), iVar1 == 0)) ||
       (iVar1 = memcmp(_Buf1,&DAT_40bdeb90,0x10), iVar1 == 0)) {
      return 0;
    }
  }
  return 1;
}



/* 40bcfa84 FUN_40bcfa84 */

/* Boundary evidence: original MIPS .pdata 40bcfa84..40bcfac7. Semantic name remains unreviewed. */

undefined4 FUN_40bcfa84(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x50) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x50) + 0x48))();
  return uVar1;
}



/* 40bcfac8 FUN_40bcfac8 */

/* Boundary evidence: original MIPS .pdata 40bcfac8..40bcfb0b. Semantic name remains unreviewed. */

undefined4 FUN_40bcfac8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x50) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x50) + 0x4c))();
  return uVar1;
}



/* 40bcfb0c FUN_40bcfb0c */

/* Boundary evidence: original MIPS .pdata 40bcfb0c..40bcfb73. Semantic name remains unreviewed. */

undefined4 FUN_40bcfb0c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x50) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x50) + 0x50))();
  return uVar1;
}



/* 40bcfb74 FUN_40bcfb74 */

/* Boundary evidence: original MIPS .pdata 40bcfb74..40bcfb8f. Semantic name remains unreviewed. */

void FUN_40bcfb74(int param_1)

{
  FUN_40bd3894(param_1);
  return;
}



/* 40bcfb90 FUN_40bcfb90 */

/* Boundary evidence: original MIPS .pdata 40bcfb90..40bcfbab. Semantic name remains unreviewed. */

void FUN_40bcfb90(int param_1)

{
  FUN_40bd3968(param_1);
  return;
}



/* 40bcfbac FUN_40bcfbac */

/* Boundary evidence: original MIPS .pdata 40bcfbac..40bcfc0b. Semantic name remains unreviewed. */

undefined4 * FUN_40bcfbac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x150);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40bc6cc0(puVar1,param_3);
  }
  return puVar1;
}



/* 40bcfc0c FUN_40bcfc0c */

/* Boundary evidence: original MIPS .pdata 40bcfc0c..40bcfc3b. Semantic name remains unreviewed. */

void FUN_40bcfc0c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40bcfcb4 FUN_40bcfcb4 */

/* Boundary evidence: original MIPS .pdata 40bcfcb4..40bcfd83. Semantic name remains unreviewed. */

undefined4 * FUN_40bcfcb4(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  FUN_40bcdc78(param_1,L"CPSDemuxFilter",param_2,&DAT_40bdc190);
  *param_1 = &PTR_FUN_40bdc678;
  param_1[3] = &PTR_FUN_40bdc63c;
  param_1[4] = &PTR_LAB_40bdc628;
  param_1[0x3e] = &PTR_LAB_40bdc610;
  puVar1 = operator_new(0x158);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40bcc768(puVar1,(int)param_1,param_3);
  }
  param_1[0x14] = puVar1;
  return param_1;
}



/* 40bcfd84 FUN_40bcfd84 */

/* Boundary evidence: original MIPS .pdata 40bcfd84..40bcfdb3. Semantic name remains unreviewed. */

void FUN_40bcfd84(void)

{
  undefined4 *in_v0;
  
  FUN_40bcf404((undefined4 *)*in_v0);
  return;
}



/* 40bcfdb4 FUN_40bcfdb4 */

/* Boundary evidence: original MIPS .pdata 40bcfdb4..40bcfde3. Semantic name remains unreviewed. */

void FUN_40bcfdb4(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40bcfde4 FUN_40bcfde4 */

/* Boundary evidence: original MIPS .pdata 40bcfde4..40bcfe2f. Semantic name remains unreviewed. */

undefined4 * FUN_40bcfde4(undefined4 *param_1,uint param_2)

{
  FUN_40bcf710(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bcfe30 FUN_40bcfe30 */

/* Boundary evidence: original MIPS .pdata 40bcfe30..40bcfeeb. Semantic name remains unreviewed. */

undefined4 *
FUN_40bcfe30(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,va_list param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x0;
  if (DAT_40be058c == 0) {
    puVar1 = operator_new(0x100);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40bcfcb4(puVar1,param_1,param_2);
    }
    DAT_40be058c = 1;
    *param_2 = 0;
  }
  else {
    FUN_40bc3b24(0x40bdc7a0,param_2,param_3,param_4);
    *param_2 = 0x80004005;
  }
  return puVar1;
}



/* 40bcfeec FUN_40bcfeec */

/* Boundary evidence: original MIPS .pdata 40bcfeec..40bcff1b. Semantic name remains unreviewed. */

void FUN_40bcfeec(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x20));
  return;
}



/* 40bcff1c FUN_40bcff1c */

/* Boundary evidence: original MIPS .pdata 40bcff1c..40bcff53. Semantic name remains unreviewed. */

void FUN_40bcff1c(int param_1)

{
  if (param_1 != 0) {
    FUN_40bd52cc();
    return;
  }
  FUN_40bd52cc();
  return;
}



/* 40bcff54 FUN_40bcff54 */

/* Boundary evidence: original MIPS .pdata 40bcff54..40bcffc3. Semantic name remains unreviewed. */

void FUN_40bcff54(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40bdc928;
  param_1[3] = &PTR_FUN_40bdc8d8;
  param_1[4] = &PTR_LAB_40bdc8a0;
  FUN_40bd8620(param_1 + 0xf);
  FUN_40bd52cc();
  return;
}



/* 40bcffc4 FUN_40bcffc4 */

/* Boundary evidence: original MIPS .pdata 40bcffc4..40bcfff3. Semantic name remains unreviewed. */

void FUN_40bcffc4(void)

{
  int *in_v0;
  
  FUN_40bcff1c(*in_v0);
  return;
}



/* 40bcfff4 FUN_40bcfff4 */

/* Boundary evidence: original MIPS .pdata 40bcfff4..40bd001b. Semantic name remains unreviewed. */

void FUN_40bcfff4(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40bd001c FUN_40bd001c */

/* Boundary evidence: original MIPS .pdata 40bd001c..40bd0043. Semantic name remains unreviewed. */

void FUN_40bd001c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40bd0044 FUN_40bd0044 */

/* Boundary evidence: original MIPS .pdata 40bd0044..40bd006b. Semantic name remains unreviewed. */

void FUN_40bd0044(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40bd006c FUN_40bd006c */

/* Boundary evidence: original MIPS .pdata 40bd006c..40bd015b. Semantic name remains unreviewed. */

void FUN_40bd006c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40bdcd58,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40bd53bc(piVar2,param_3);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40bde6f8,0x10);
    if (iVar1 == 0) {
      piVar2 = param_1 + 4;
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      FUN_40bd53bc(piVar2,param_3);
    }
    else {
      iVar1 = memcmp(param_2,&DAT_40bdeba0,0x10);
      if (iVar1 == 0) {
        piVar2 = param_1 + 4;
        if (param_1 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        FUN_40bd53bc(piVar2,param_3);
      }
      else {
        FUN_40bd5458(param_1,param_2,param_3);
      }
    }
  }
  return;
}



/* 40bd015c FUN_40bd015c */

/* Boundary evidence: original MIPS .pdata 40bd015c..40bd01a7. Semantic name remains unreviewed. */

bool FUN_40bd015c(int *param_1,uint *param_2)

{
  uint local_10 [2];
  
  (**(code **)(*param_1 + 0xc))(param_1,local_10);
  return (~local_10[0] & *param_2) != 0;
}



/* 40bd01d0 FUN_40bd01d0 */

/* Boundary evidence: original MIPS .pdata 40bd01d0..40bd025f. Semantic name remains unreviewed. */

undefined4 FUN_40bd01d0(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 auStack_20 [16];
  uint local_10;
  
  local_10 = DAT_40be0550;
  if (param_2 == (int *)0x0) {
    param_2 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,auStack_20);
  if ((-1 < iVar1) && (iVar1 = memcmp(auStack_20,param_2,0x10), iVar1 == 0)) {
    FUN_40bd8bd0(local_10);
    return 0;
  }
  FUN_40bd8bd0(local_10);
  return 1;
}



/* 40bd0260 FUN_40bd0260 */

/* Boundary evidence: original MIPS .pdata 40bd0260..40bd02bf. Semantic name remains unreviewed. */

undefined4 FUN_40bd0260(int param_1,int *param_2)

{
  if (*(int *)(param_1 + 0x24) == 0 && *(int *)(param_1 + 0x28) == 0) {
    FUN_40bcc610(*(int *)(param_1 + 0x2c));
  }
  *param_2 = *(int *)(param_1 + 0x24);
  param_2[1] = *(int *)(param_1 + 0x28);
  return 0;
}



/* 40bd0304 FUN_40bd0304 */

/* Boundary evidence: original MIPS .pdata 40bd0304..40bd0327. Semantic name remains unreviewed. */

void FUN_40bd0304(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  FUN_40bcf0a0(*(int *)(param_1 + 0x2c),param_2,param_3,param_4);
  return;
}



/* 40bd0368 FUN_40bd0368 */

/* Boundary evidence: original MIPS .pdata 40bd0368..40bd03bb. Semantic name remains unreviewed. */

undefined4 FUN_40bd0368(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40bcc6ac(*(int *)(param_1 + 0x28));
  if (iVar1 != 0) {
    *param_2 = 1;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



/* 40bd03c8 FUN_40bd03c8 */

/* Boundary evidence: original MIPS .pdata 40bd03c8..40bd03ef. Semantic name remains unreviewed. */

void FUN_40bd03c8(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0x44))();
  return;
}



/* 40bd03f0 FUN_40bd03f0 */

/* Boundary evidence: original MIPS .pdata 40bd03f0..40bd0417. Semantic name remains unreviewed. */

void FUN_40bd03f0(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0x48))();
  return;
}



/* 40bd0418 FUN_40bd0418 */

/* Boundary evidence: original MIPS .pdata 40bd0418..40bd0433. Semantic name remains unreviewed. */

void FUN_40bd0418(int param_1,undefined4 *param_2)

{
  FUN_40bd8650(param_1 + 0x2c,param_2);
  return;
}



/* 40bd0434 FUN_40bd0434 */

/* Boundary evidence: original MIPS .pdata 40bd0434..40bd0463. Semantic name remains unreviewed. */

void FUN_40bd0434(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  FUN_40bd8678((int *)(param_1 + 0x2c),&DAT_40bdcd58,param_2,param_3,param_4);
  return;
}



/* 40bd0464 FUN_40bd0464 */

/* Boundary evidence: original MIPS .pdata 40bd0464..40bd0497. Semantic name remains unreviewed. */

void FUN_40bd0464(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_40bd8814((int *)(param_1 + 0x2c),&DAT_40bdcd58,param_3,param_4,param_5,param_6);
  return;
}



/* 40bd0498 FUN_40bd0498 */

/* Boundary evidence: original MIPS .pdata 40bd0498..40bd057f. Semantic name remains unreviewed. */

int FUN_40bd0498(int *param_1,undefined4 param_2,void *param_3,undefined4 param_4,undefined2 param_5
                ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int *piVar2;
  int *local_18 [2];
  
  iVar1 = memcmp(&DAT_40bdeb90,param_3,0x10);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1,0,param_4,local_18);
    if (-1 < iVar1) {
      piVar2 = param_1 + -1;
      if (param_1 == (int *)0x10) {
        piVar2 = (int *)0x0;
      }
      iVar1 = (**(code **)(*local_18[0] + 0x2c))
                        (local_18[0],piVar2,param_2,param_5,param_6,param_7,param_8,param_9);
      (**(code **)(*local_18[0] + 8))();
    }
  }
  else {
    iVar1 = -0x7ffdffff;
  }
  return iVar1;
}



/* 40bd05bc FUN_40bd05bc */

/* Boundary evidence: original MIPS .pdata 40bd05bc..40bd0607. Semantic name remains unreviewed. */

undefined4 * FUN_40bd05bc(undefined4 *param_1,uint param_2)

{
  FUN_40bcff54(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bd0608 FUN_40bd0608 */

/* Boundary evidence: original MIPS .pdata 40bd0608..40bd065b. Semantic name remains unreviewed. */

undefined4 FUN_40bd0608(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40bcc6ac(*(int *)(param_1 + 0x2c));
  if (iVar1 != 0) {
    *param_2 = 0x37;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



/* 40bd065c FUN_40bd065c */

/* Boundary evidence: original MIPS .pdata 40bd065c..40bd06cf. Semantic name remains unreviewed. */

undefined4 FUN_40bd065c(int param_1,void *param_2)

{
  int iVar1;
  
  if (param_2 == (void *)0x0) {
    param_2 = (void *)(param_1 + 0x34);
  }
  iVar1 = FUN_40bcc6ac(*(int *)(param_1 + 0x2c));
  if ((iVar1 != 0) && (iVar1 = FUN_40bcc638(*(undefined4 *)(param_1 + 0x2c),param_2), iVar1 == 0)) {
    return 0;
  }
  return 1;
}



/* 40bd06d0 FUN_40bd06d0 */

/* Boundary evidence: original MIPS .pdata 40bd06d0..40bd0753. Semantic name remains unreviewed. */

undefined4 FUN_40bd06d0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40bcc6ac(*(int *)(param_1 + 0x2c));
  if (iVar1 == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    uVar2 = 0;
  }
  else {
    *param_2 = 0x7b785574;
    param_2[1] = 0x11cf8c82;
    param_2[2] = 0xaa000cbc;
    uVar2 = 0xf674ac00;
  }
  param_2[3] = uVar2;
  return 0;
}



/* 40bd0754 FUN_40bd0754 */

/* Boundary evidence: original MIPS .pdata 40bd0754..40bd08ab. Semantic name remains unreviewed. */

undefined4 FUN_40bd0754(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    param_2 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,param_1 + 0xd,0x10);
    if (iVar1 != 0) {
      iVar1 = FUN_40bcc6ac(param_1[0xb]);
      if ((iVar1 == 0) || (iVar1 = FUN_40bcc684(param_1[0xb],param_2), iVar1 != 0)) {
        return 0x80004005;
      }
      (**(code **)(*param_1 + 0x34))(param_1,param_1 + 5,param_2);
      (**(code **)(*param_1 + 0x34))(param_1,param_1 + 7,param_2);
      param_1[0xd] = *param_2;
      param_1[0xe] = param_2[1];
      param_1[0xf] = param_2[2];
      param_1[0x10] = param_2[3];
      FUN_40bd16fc();
    }
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40bde458,0x10);
    if (iVar1 != 0) {
      return 0x80004001;
    }
  }
  return 0;
}



/* 40bd08ac FUN_40bd08ac */

/* Boundary evidence: original MIPS .pdata 40bd08ac..40bd0917. Semantic name remains unreviewed. */

undefined4 FUN_40bd08ac(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40bcc6ac(*(int *)(param_1 + 0x2c));
  if (iVar1 == 0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0x7fffffff;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x14);
    param_2[1] = *(undefined4 *)(param_1 + 0x18);
  }
  return 0;
}



/* 40bd0918 FUN_40bd0918 */

/* Boundary evidence: original MIPS .pdata 40bd0918..40bd0b1f. Semantic name remains unreviewed. */

undefined4
FUN_40bd0918(int *param_1,uint *param_2,int *param_3,undefined4 param_4,uint param_5,uint param_6,
            int *param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_v1;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  iVar1 = FUN_40bcc6ac(param_1[0xb]);
  if (iVar1 == 0) {
    return 1;
  }
  if (param_3 == (int *)0x0) {
    param_3 = param_1 + 0xd;
  }
  if (param_7 == (int *)0x0) {
    param_7 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_3);
  if ((iVar1 != 0) || (iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_7), iVar1 != 0)) {
    return 0x80004005;
  }
  iVar1 = memcmp(param_3,param_7,0x10);
  if (iVar1 == 0) {
    *param_2 = param_5;
    param_2[1] = param_6;
    return 0;
  }
  FUN_40bcc610(param_1[0xb]);
  FUN_40bcc610(param_1[0xb]);
  if ((param_5 != local_20) || (uVar2 = local_28, uVar3 = local_24, param_6 != local_1c)) {
    if (param_5 == 0 && param_6 == 0) {
      uVar2 = 0;
      uVar3 = 0;
      goto LAB_40bd0a44;
    }
    if (((int)local_24 < (int)local_1c) || ((local_24 == local_1c && (local_28 <= local_20)))) {
      uVar2 = 0;
      uVar3 = 0;
    }
    else {
      uVar2 = local_20 - 1;
      uVar3 = local_1c - (local_20 == 0);
    }
    uVar2 = FUN_40bd5994(param_5,param_6,local_28,local_24,local_20,local_1c,uVar2,uVar3);
    uVar3 = extraout_v1;
  }
  if (((int)uVar3 < 1) && (uVar3 != 0)) {
    *param_2 = 0;
    param_2[1] = 0;
    return 0;
  }
LAB_40bd0a44:
  if (((int)local_24 <= (int)uVar3) && ((uVar3 != local_24 || (local_28 < uVar2)))) {
    uVar2 = local_28;
    uVar3 = local_24;
  }
  *param_2 = uVar2;
  param_2[1] = uVar3;
  return 0;
}



/* 40bd0b20 FUN_40bd0b20 */

/* Boundary evidence: original MIPS .pdata 40bd0b20..40bd0c73. Semantic name remains unreviewed. */

undefined4
FUN_40bd0b20(int *param_1,undefined ***param_2,uint param_3,undefined ***param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined ***pppuVar3;
  uint uVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  int iVar7;
  
  pppuVar3 = param_2;
  iVar1 = FUN_40bcc6ac(param_1[0xb]);
  if (iVar1 != 0) {
    ppuVar5 = (undefined **)param_1[7];
    ppuVar6 = (undefined **)param_1[8];
    uVar4 = param_3 & 3;
    if (uVar4 == 1) {
      ppuVar5 = *param_2;
      ppuVar6 = param_2[1];
    }
    else {
      if (uVar4 == 2) {
        return 0x80004001;
      }
      if (uVar4 == 3) {
        return 0x80004001;
      }
    }
    iVar1 = param_1[5];
    uVar4 = param_5 & 3;
    iVar7 = param_1[6];
    if ((uVar4 == 1) || ((uVar4 != 2 && (uVar4 != 3)))) {
      if ((param_3 & 8) != 0) {
        (**(code **)(*param_1 + 0x34))(param_1,param_2,&DAT_40bde4a8);
        pppuVar3 = param_2;
      }
      if ((param_5 & 8) != 0) {
        (**(code **)(*param_1 + 0x34))(param_1,param_4,&DAT_40bde4a8);
        pppuVar3 = param_4;
      }
      uVar2 = FUN_40bceef4(param_1[0xb],pppuVar3,ppuVar5,ppuVar6,iVar1,iVar7);
      return uVar2;
    }
  }
  return 0x80004001;
}



/* 40bd0c74 FUN_40bd0c74 */

/* Boundary evidence: original MIPS .pdata 40bd0c74..40bd0d03. Semantic name remains unreviewed. */

undefined4 FUN_40bd0c74(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_40bcc6ac(param_1[0xb]);
  *param_2 = 0;
  param_2[1] = 0;
  if (iVar1 == 0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0x7fffffff;
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x28))(param_1,param_3);
  }
  return uVar2;
}



/* 40bd0d04 FUN_40bd0d04 */

/* Boundary evidence: original MIPS .pdata 40bd0d04..40bd0e17. Semantic name remains unreviewed. */

undefined4 * FUN_40bd0d04(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  FUN_40bd5360(param_1,0,param_3);
  param_1[3] = &PTR_FUN_40bdc8d8;
  param_1[4] = &PTR_LAB_40bdc8a0;
  *param_1 = &PTR_FUN_40bdc928;
  param_1[6] = 0;
  param_1[7] = 0x3ff00000;
  param_1[8] = 0xffffffff;
  param_1[9] = 0x7fffffff;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = param_2;
  param_1[0xf] = 0;
  param_1[0x10] = 0x7b785574;
  param_1[0x11] = 0x11cf8c82;
  param_1[0x12] = 0xaa000cbc;
  param_1[0x13] = 0xf674ac00;
  FUN_40bcc610(param_1[0xe]);
  iVar1 = param_1[0xc];
  if (iVar1 != 0 || param_1[0xd] != 0) {
    param_1[8] = iVar1;
    param_1[9] = param_1[0xd];
  }
  return param_1;
}



/* 40bd0e18 FUN_40bd0e18 */

/* Boundary evidence: original MIPS .pdata 40bd0e18..40bd0e47. Semantic name remains unreviewed. */

void FUN_40bd0e18(void)

{
  int *in_v0;
  
  FUN_40bcff1c(*in_v0);
  return;
}



/* 40bd0e48 FUN_40bd0e48 */

/* Boundary evidence: original MIPS .pdata 40bd0e48..40bd0e7b. Semantic name remains unreviewed. */

void FUN_40bd0e48(void)

{
  int *in_v0;
  
  FUN_40bd8620((int *)(*in_v0 + 0x3c));
  return;
}



/* 40bd0e7c FUN_40bd0e7c */

/* Boundary evidence: original MIPS .pdata 40bd0e7c..40bd0eff. Semantic name remains unreviewed. */

undefined4 FUN_40bd0e7c(void)

{
  void *_Memory;
  
  _Memory = DAT_40be0594;
  if (DAT_40be0594 != (void *)0x0) {
    if (*(void **)((int)DAT_40be0594 + 0x30) != (void *)0x0) {
      free(*(void **)((int)DAT_40be0594 + 0x30));
      *(undefined4 *)((int)_Memory + 0x30) = 0;
    }
    if (*(void **)((int)_Memory + 0x34) != (void *)0x0) {
      free(*(void **)((int)_Memory + 0x34));
      *(undefined4 *)((int)_Memory + 0x34) = 0;
    }
    free(_Memory);
    DAT_40be0594 = (void *)0x0;
    DAT_40be0590 = 0;
  }
  return 1;
}



/* 40bd0f68 FUN_40bd0f68 */

/* Boundary evidence: original MIPS .pdata 40bd0f68..40bd0ff3. Semantic name remains unreviewed. */

undefined4 FUN_40bd0f68(int param_1,short *param_2)

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
      FUN_40bd5958(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40bd0ff4 FUN_40bd0ff4 */

/* Boundary evidence: original MIPS .pdata 40bd0ff4..40bd1033. Semantic name remains unreviewed. */

undefined4 FUN_40bd0ff4(int param_1)

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



/* 40bd103c FUN_40bd103c */

/* Boundary evidence: original MIPS .pdata 40bd103c..40bd1057. Semantic name remains unreviewed. */

void FUN_40bd103c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x48));
  return;
}



/* 40bd1058 FUN_40bd1058 */

/* Boundary evidence: original MIPS .pdata 40bd1058..40bd10a3. Semantic name remains unreviewed. */

void FUN_40bd1058(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40bde788;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40bd6a6c(param_1 + 6);
  return;
}



/* 40bd10a4 FUN_40bd10a4 */

/* Boundary evidence: original MIPS .pdata 40bd10a4..40bd113b. Semantic name remains unreviewed. */

undefined4 FUN_40bd10a4(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40bdcc78,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40bdebb0,0x10), iVar2 == 0)) {
      uVar1 = FUN_40bd53bc(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40bd113c FUN_40bd113c */

/* Boundary evidence: original MIPS .pdata 40bd113c..40bd1157. Semantic name remains unreviewed. */

void FUN_40bd113c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40bd1158 FUN_40bd1158 */

/* Boundary evidence: original MIPS .pdata 40bd1158..40bd11b3. Semantic name remains unreviewed. */

LONG FUN_40bd1158(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40bd11b4 FUN_40bd11b4 */

/* Boundary evidence: original MIPS .pdata 40bd11b4..40bd1213. Semantic name remains unreviewed. */

undefined4 FUN_40bd11b4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40bd67f4((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40bd1214 FUN_40bd1214 */

/* Boundary evidence: original MIPS .pdata 40bd1214..40bd126b. Semantic name remains unreviewed. */

undefined4 FUN_40bd1214(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40bd126c FUN_40bd126c */

/* Boundary evidence: original MIPS .pdata 40bd126c..40bd1303. Semantic name remains unreviewed. */

undefined4 FUN_40bd126c(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40bdcc88,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40bdebb0,0x10), iVar2 == 0)) {
      uVar1 = FUN_40bd53bc(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40bd1304 FUN_40bd1304 */

/* Boundary evidence: original MIPS .pdata 40bd1304..40bd131f. Semantic name remains unreviewed. */

void FUN_40bd1304(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40bd1320 FUN_40bd1320 */

/* Boundary evidence: original MIPS .pdata 40bd1320..40bd137b. Semantic name remains unreviewed. */

LONG FUN_40bd1320(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40bd137c FUN_40bd137c */

/* Boundary evidence: original MIPS .pdata 40bd137c..40bd13bb. Semantic name remains unreviewed. */

undefined4 FUN_40bd137c(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40bd13bc FUN_40bd13bc */

/* Boundary evidence: original MIPS .pdata 40bd13bc..40bd13ff. Semantic name remains unreviewed. */

void FUN_40bd13bc(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40bd6358(param_1 + 0x1c);
  FUN_40bd52cc();
  return;
}



/* 40bd1400 FUN_40bd1400 */

/* Boundary evidence: original MIPS .pdata 40bd1400..40bd14a7. Semantic name remains unreviewed. */

void FUN_40bd1400(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40bdcc68,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40bdcda8,0x10);
    if (iVar1 != 0) {
      FUN_40bd5458(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40bd53bc(piVar2,param_3);
  return;
}



/* 40bd14a8 FUN_40bd14a8 */

/* Boundary evidence: original MIPS .pdata 40bd14a8..40bd14d3. Semantic name remains unreviewed. */

void FUN_40bd14a8(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40bd14d4 FUN_40bd14d4 */

/* Boundary evidence: original MIPS .pdata 40bd14d4..40bd14ff. Semantic name remains unreviewed. */

void FUN_40bd14d4(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40bd1500 FUN_40bd1500 */

/* Boundary evidence: original MIPS .pdata 40bd1500..40bd151f. Semantic name remains unreviewed. */

undefined4 FUN_40bd1500(int param_1,void *param_2)

{
  FUN_40bd6498((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40bd1520 FUN_40bd1520 */

/* Boundary evidence: original MIPS .pdata 40bd1520..40bd1577. Semantic name remains unreviewed. */

undefined4 FUN_40bd1520(int param_1,int *param_2)

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



/* 40bd1578 FUN_40bd1578 */

/* Boundary evidence: original MIPS .pdata 40bd1578..40bd15cb. Semantic name remains unreviewed. */

undefined4 FUN_40bd1578(int param_1,int *param_2)

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



/* 40bd15cc FUN_40bd15cc */

/* Boundary evidence: original MIPS .pdata 40bd15cc..40bd1677. Semantic name remains unreviewed. */

undefined4 FUN_40bd15cc(int param_1,int *param_2)

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
      FUN_40bd5958((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40bd16a0 FUN_40bd16a0 */

/* Boundary evidence: original MIPS .pdata 40bd16a0..40bd16e7. Semantic name remains unreviewed. */

int FUN_40bd16a0(int param_1,int param_2)

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



/* 40bd16fc FUN_40bd16fc */

undefined4 FUN_40bd16fc(void)

{
  return 0;
}



/* 40bd1704 FUN_40bd1704 */

/* Boundary evidence: original MIPS .pdata 40bd1704..40bd1753. Semantic name remains unreviewed. */

undefined4 FUN_40bd1704(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bd1784 FUN_40bd1784 */

/* Boundary evidence: original MIPS .pdata 40bd1784..40bd17ab. Semantic name remains unreviewed. */

void FUN_40bd1784(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40bd17ac FUN_40bd17ac */

/* Boundary evidence: original MIPS .pdata 40bd17ac..40bd1813. Semantic name remains unreviewed. */

int FUN_40bd17ac(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40bd1520(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40bdcd38,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bd1814 FUN_40bd1814 */

/* Boundary evidence: original MIPS .pdata 40bd1814..40bd1877. Semantic name remains unreviewed. */

undefined4 FUN_40bd1814(int param_1)

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



/* 40bd1878 FUN_40bd1878 */

/* Boundary evidence: original MIPS .pdata 40bd1878..40bd18b3. Semantic name remains unreviewed. */

void FUN_40bd1878(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40bdde08,(LPUNKNOWN)0x0,1,(IID *)&DAT_40bdcd18,param_2);
  return;
}



/* 40bd18b4 FUN_40bd18b4 */

/* Boundary evidence: original MIPS .pdata 40bd18b4..40bd1a3f. Semantic name remains unreviewed. */

int FUN_40bd18b4(int *param_1,int *param_2,int *param_3)

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



/* 40bd1a40 FUN_40bd1a40 */

/* Boundary evidence: original MIPS .pdata 40bd1a40..40bd1a87. Semantic name remains unreviewed. */

undefined4 FUN_40bd1a40(int param_1)

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



/* 40bd1a88 FUN_40bd1a88 */

/* Boundary evidence: original MIPS .pdata 40bd1a88..40bd1ac7. Semantic name remains unreviewed. */

undefined4 FUN_40bd1a88(int param_1)

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



/* 40bd1ac8 FUN_40bd1ac8 */

/* Boundary evidence: original MIPS .pdata 40bd1ac8..40bd1b07. Semantic name remains unreviewed. */

undefined4 FUN_40bd1ac8(int param_1)

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



/* 40bd1b08 FUN_40bd1b08 */

/* Boundary evidence: original MIPS .pdata 40bd1b08..40bd1b47. Semantic name remains unreviewed. */

undefined4 FUN_40bd1b08(int param_1)

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



/* 40bd1b48 FUN_40bd1b48 */

/* Boundary evidence: original MIPS .pdata 40bd1b48..40bd1b93. Semantic name remains unreviewed. */

bool FUN_40bd1b48(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40bd1b94 FUN_40bd1b94 */

/* Boundary evidence: original MIPS .pdata 40bd1b94..40bd1bdf. Semantic name remains unreviewed. */

bool FUN_40bd1b94(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40bd1be0 FUN_40bd1be0 */

/* Boundary evidence: original MIPS .pdata 40bd1be0..40bd1c3b. Semantic name remains unreviewed. */

undefined4 FUN_40bd1be0(int param_1)

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



/* 40bd1c3c FUN_40bd1c3c */

/* Boundary evidence: original MIPS .pdata 40bd1c3c..40bd1c83. Semantic name remains unreviewed. */

void FUN_40bd1c3c(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40bd13bc(param_1);
  return;
}



/* 40bd1c84 FUN_40bd1c84 */

/* Boundary evidence: original MIPS .pdata 40bd1c84..40bd1d03. Semantic name remains unreviewed. */

void FUN_40bd1c84(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40bdcd38,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40bd53bc(piVar2,param_3);
  }
  else {
    FUN_40bd1400(param_1,param_2,param_3);
  }
  return;
}



/* 40bd1d04 FUN_40bd1d04 */

/* Boundary evidence: original MIPS .pdata 40bd1d04..40bd1dcb. Semantic name remains unreviewed. */

HRESULT FUN_40bd1d04(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40bdde08,(LPUNKNOWN)0x0,1,(IID *)&DAT_40bdcd18,ppv),
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



/* 40bd1dcc FUN_40bd1dcc */

/* Boundary evidence: original MIPS .pdata 40bd1dcc..40bd1e6b. Semantic name remains unreviewed. */

undefined4 FUN_40bd1dcc(int param_1,int *param_2,undefined1 param_3)

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



/* 40bd1e6c FUN_40bd1e6c */

/* Boundary evidence: original MIPS .pdata 40bd1e6c..40bd1f07. Semantic name remains unreviewed. */

int FUN_40bd1e6c(int *param_1,int param_2,int param_3,int *param_4)

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



/* 40bd1f08 FUN_40bd1f08 */

/* Boundary evidence: original MIPS .pdata 40bd1f08..40bd1f4f. Semantic name remains unreviewed. */

undefined4 FUN_40bd1f08(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bd1f50 FUN_40bd1f50 */

/* Boundary evidence: original MIPS .pdata 40bd1f50..40bd1f93. Semantic name remains unreviewed. */

undefined4 FUN_40bd1f50(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bd1fb4 FUN_40bd1fb4 */

/* Boundary evidence: original MIPS .pdata 40bd1fb4..40bd1ff3. Semantic name remains unreviewed. */

undefined4 FUN_40bd1fb4(int param_1)

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



/* 40bd2048 FUN_40bd2048 */

/* Boundary evidence: original MIPS .pdata 40bd2048..40bd20eb. Semantic name remains unreviewed. */

undefined4 FUN_40bd2048(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40bdccf8,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40bdcd08,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40bdebb0,0x10), iVar1 == 0)) {
    uVar2 = FUN_40bd53bc(param_1,param_3);
  }
  else {
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 40bd20ec FUN_40bd20ec */

/* Boundary evidence: original MIPS .pdata 40bd20ec..40bd2107. Semantic name remains unreviewed. */

void FUN_40bd20ec(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x44));
  return;
}



/* 40bd2108 FUN_40bd2108 */

/* Boundary evidence: original MIPS .pdata 40bd2108..40bd21af. Semantic name remains unreviewed. */

LONG FUN_40bd2108(int *param_1)

{
  LONG LVar1;
  LONG *lpAddend;
  
  lpAddend = param_1 + 0x11;
  if (*lpAddend == 1) {
    *lpAddend = 0;
  }
  else {
    LVar1 = InterlockedDecrement(lpAddend);
    if (LVar1 != 0) {
      return LVar1;
    }
  }
  if ((param_1[1] & 8U) != 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0);
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x10] = 0;
  (**(code **)(*(int *)(param_1[6] + 0xc) + 0x20))((int *)(param_1[6] + 0xc),param_1);
  return 0;
}



/* 40bd24a0 FUN_40bd24a0 */

/* Boundary evidence: original MIPS .pdata 40bd24a0..40bd24f7. Semantic name remains unreviewed. */

undefined4 FUN_40bd24a0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
  if ((*(uint *)(param_1 + 4) & 8) == 0) {
    *param_2 = 0;
    uVar1 = 1;
  }
  else {
    pvVar2 = FUN_40bd6754(*(void **)(param_1 + 0x3c));
    *param_2 = pvVar2;
    if (pvVar2 == (LPVOID)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40bd24f8 FUN_40bd24f8 */

/* Boundary evidence: original MIPS .pdata 40bd24f8..40bd2587. Semantic name remains unreviewed. */

undefined4 FUN_40bd24f8(int param_1,void *param_2)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
  if (*(LPVOID *)(param_1 + 0x3c) != (LPVOID)0x0) {
    FUN_40bd6714(*(LPVOID *)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (param_2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    pvVar2 = FUN_40bd6754(param_2);
    *(LPVOID *)(param_1 + 0x3c) = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 8;
      return 0;
    }
    uVar1 = 0x8007000e;
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffff7;
  return uVar1;
}



/* 40bd2588 FUN_40bd2588 */

/* Boundary evidence: original MIPS .pdata 40bd2588..40bd2673. Semantic name remains unreviewed. */

undefined4 FUN_40bd2588(int param_1,size_t param_2,void *param_3)

{
  size_t local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_2 != 0) {
    if (param_3 == (void *)0x0) {
      return 0x80004003;
    }
    if (0x2f < param_2) {
      param_2 = 0x30;
    }
    local_30 = *(uint *)(param_1 + 4) & 0xffffffdf;
    local_34 = *(undefined4 *)(param_1 + 8);
    local_10 = *(undefined4 *)(param_1 + 0xc);
    local_c = *(undefined4 *)(param_1 + 0x14);
    local_2c = *(undefined4 *)(param_1 + 0x10);
    if ((*(uint *)(param_1 + 4) & 0x10) == 0) {
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
    }
    else {
      local_28 = *(undefined4 *)(param_1 + 0x20);
      local_24 = *(undefined4 *)(param_1 + 0x24);
      local_20 = *(undefined4 *)(param_1 + 0x28);
      local_1c = *(undefined4 *)(param_1 + 0x2c);
    }
    local_18 = *(undefined4 *)(param_1 + 0x40);
    if ((*(uint *)(param_1 + 4) & 8) == 0) {
      local_14 = 0;
    }
    else {
      local_14 = *(undefined4 *)(param_1 + 0x3c);
    }
    local_38 = param_2;
    memcpy(param_3,&local_38,param_2);
  }
  return 0;
}



/* 40bd2674 FUN_40bd2674 */

/* Boundary evidence: original MIPS .pdata 40bd2674..40bd28ef. Semantic name remains unreviewed. */

undefined4 FUN_40bd2674(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  LPVOID pvVar2;
  
  pvVar2 = (LPVOID)0x0;
  if (3 < param_2) {
    if (param_3 == (uint *)0x0) {
      return 0x80004003;
    }
    uVar1 = *param_3;
    if (uVar1 < param_2) {
      param_2 = uVar1;
    }
    if (((((0x30 < param_2) || (0x30 < uVar1)) ||
         ((param_2 >= 0xc &&
          (((uVar1 = param_3[2], (uVar1 & 0xfffffe20) != 0 && ((uVar1 & 0x200) == 0)) ||
           (((uVar1 & 0x10) != 0 && (((*(uint *)(param_1 + 4) & 0x10) == 0 && (param_2 < 0x20)))))))
          ))) || ((0x2b < param_2 &&
                  ((param_3[10] != 0 && (param_3[10] != *(uint *)(param_1 + 0xc))))))) ||
       ((0x2f < param_2 &&
        (((uVar1 = param_3[0xb], uVar1 != 0 && (uVar1 != *(uint *)(param_1 + 0x14))) ||
         ((0xf < param_2 && ((int)uVar1 < (int)param_3[3])))))))) {
      return 0x80070057;
    }
    if ((0x27 < param_2) && ((param_3[2] & 8) != 0)) {
      if ((void *)param_3[9] == (void *)0x0) {
        return 0x80004003;
      }
      pvVar2 = FUN_40bd6754((void *)param_3[9]);
      if (pvVar2 == (LPVOID)0x0) {
        return 0x8007000e;
      }
    }
    if (0x23 < param_2) {
      *(uint *)(param_1 + 0x40) = param_3[8];
    }
    if (param_2 < 0xc) {
      if (7 < param_2) {
        *(uint *)(param_1 + 8) = param_3[1];
      }
    }
    else {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0x20 | param_3[2];
      *(uint *)(param_1 + 8) = param_3[1];
    }
    if (0xf < param_2) {
      *(uint *)(param_1 + 0x10) = param_3[3];
    }
    if (0x1f < param_2) {
      *(uint *)(param_1 + 0x28) = param_3[6];
      *(uint *)(param_1 + 0x2c) = param_3[7];
    }
    if (0x17 < param_2) {
      *(uint *)(param_1 + 0x20) = param_3[4];
      *(uint *)(param_1 + 0x24) = param_3[5];
    }
    if ((0x27 < param_2) && ((param_3[2] & 8) != 0)) {
      if (*(LPVOID *)(param_1 + 0x3c) != (LPVOID)0x0) {
        FUN_40bd6714(*(LPVOID *)(param_1 + 0x3c));
      }
      *(LPVOID *)(param_1 + 0x3c) = pvVar2;
    }
  }
  return 0;
}



/* 40bd28f0 FUN_40bd28f0 */

/* Boundary evidence: original MIPS .pdata 40bd28f0..40bd293b. Semantic name remains unreviewed. */

void FUN_40bd28f0(int param_1)

{
  if (*(HANDLE *)(param_1 + 0x2c) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x2c));
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  FUN_40bd52cc();
  return;
}



/* 40bd293c FUN_40bd293c */

/* Boundary evidence: original MIPS .pdata 40bd293c..40bd29d7. Semantic name remains unreviewed. */

void FUN_40bd293c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40bdcd28,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40bdcd18,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40bd53bc(piVar2,param_3);
  }
  else {
    FUN_40bd5458(param_1,param_2,param_3);
  }
  return;
}



/* 40bd29d8 FUN_40bd29d8 */

/* Boundary evidence: original MIPS .pdata 40bd29d8..40bd2a5f. Semantic name remains unreviewed. */

undefined4 FUN_40bd29d8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
    if (param_1 == 0xc) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    EnterCriticalSection(lpCriticalSection);
    param_2[1] = *(undefined4 *)(param_1 + 0x30);
    *param_2 = *(undefined4 *)(param_1 + 0x28);
    param_2[2] = *(undefined4 *)(param_1 + 0x34);
    param_2[3] = *(undefined4 *)(param_1 + 0x38);
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40bd2a60 FUN_40bd2a60 */

/* Boundary evidence: original MIPS .pdata 40bd2a60..40bd2b77. Semantic name remains unreviewed. */

undefined4 FUN_40bd2a60(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  *param_2 = 0;
  while( true ) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
    if (param_1 == 0xc) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(param_1 + 0x40) == 0) {
      LeaveCriticalSection(lpCriticalSection);
      return 0x80040211;
    }
    iVar1 = *(int *)(param_1 + 0x18);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar1 + 0x1c);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    }
    LeaveCriticalSection(lpCriticalSection);
    if (iVar1 != 0) break;
    if ((param_5 & 4) != 0) {
      return 0x8004022e;
    }
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x20),0xffffffff);
  }
  *(undefined4 *)(iVar1 + 0x44) = 1;
  *param_2 = iVar1;
  return 0;
}



/* 40bd2b78 FUN_40bd2b78 */

/* Boundary evidence: original MIPS .pdata 40bd2b78..40bd2bdf. Semantic name remains unreviewed. */

undefined4 FUN_40bd2b78(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  if (param_1 == 0xc) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  EnterCriticalSection(lpCriticalSection);
  *param_2 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x1c);
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bd2be0 FUN_40bd2be0 */

/* Boundary evidence: original MIPS .pdata 40bd2be0..40bd2c3f. Semantic name remains unreviewed. */

undefined4 FUN_40bd2be0(int param_1,undefined4 *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
  if (param_1 == 0xc) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  EnterCriticalSection(lpCriticalSection);
  *param_2 = *(undefined4 *)(param_1 + 0x1c);
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bd2c40 FUN_40bd2c40 */

/* Boundary evidence: original MIPS .pdata 40bd2c40..40bd2c83. Semantic name remains unreviewed. */

void FUN_40bd2c40(int param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x2c),*(int *)(param_1 + 0x30),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  return;
}



/* 40bd2c84 FUN_40bd2c84 */

/* Boundary evidence: original MIPS .pdata 40bd2c84..40bd2d4b. Semantic name remains unreviewed. */

int FUN_40bd2c84(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
  if (param_1 == (int *)0xc) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  EnterCriticalSection(lpCriticalSection);
  if (param_1[0x10] != 0) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  param_1[0x10] = 1;
  if (param_1[0x11] == 0) {
    iVar1 = (**(code **)(param_1[-3] + 0x14))();
    if (iVar1 < 0) {
      param_1[0x10] = 0;
      goto LAB_40bd2d28;
    }
    (**(code **)(*param_1 + 4))(param_1);
  }
  else {
    param_1[0x11] = 0;
  }
  iVar1 = 0;
LAB_40bd2d28:
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40bd2d4c FUN_40bd2d4c */

/* Boundary evidence: original MIPS .pdata 40bd2d4c..40bd2e23. Semantic name remains unreviewed. */

undefined4 FUN_40bd2d4c(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
  if (param_1 == (int *)0xc) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  EnterCriticalSection(lpCriticalSection);
  if ((param_1[0x10] == 0) && (param_1[0x11] == 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    iVar3 = param_1[7];
    iVar1 = param_1[0xb];
    param_1[0x10] = 0;
    if (iVar1 <= iVar3) {
      pcVar2 = *(code **)(param_1[-3] + 0x10);
      param_1[0x11] = 0;
      (*pcVar2)();
    }
    else {
      param_1[0x11] = 1;
    }
    FUN_40bd2c40((int)(param_1 + -3));
    LeaveCriticalSection(lpCriticalSection);
    if (iVar1 <= iVar3) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  return 0;
}



/* 40bd2e24 FUN_40bd2e24 */

undefined4 FUN_40bd2e24(int param_1)

{
  undefined4 uVar1;
  
  if (((*(int *)(param_1 + 0x34) < 1) || (*(int *)(param_1 + 0x3c) < 1)) ||
     (*(int *)(param_1 + 0x40) < 1)) {
    uVar1 = 0x80040212;
  }
  else if (*(int *)(param_1 + 0x48) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40bd2e74 FUN_40bd2e74 */

void FUN_40bd2e74(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  piVar2 = param_1;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if (*piVar2 == param_2) break;
    piVar2 = (int *)(*piVar2 + 0x1c);
    iVar1 = *piVar2;
  }
  *piVar2 = *(int *)(param_2 + 0x1c);
  *(undefined4 *)(param_2 + 0x1c) = 0;
  param_1[1] = param_1[1] + -1;
  return;
}



/* 40bd2ec4 FUN_40bd2ec4 */

/* Boundary evidence: original MIPS .pdata 40bd2ec4..40bd306f. Semantic name remains unreviewed. */

undefined4 FUN_40bd2ec4(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  _SYSTEM_INFO _Stack_40;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);
    if (param_1 == 0xc) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    EnterCriticalSection(lpCriticalSection);
    memset(param_3,0,0x10);
    if (param_2[1] == 0) {
      uVar3 = 0x80070057;
    }
    else {
      GetSystemInfo(&_Stack_40);
      iVar2 = param_2[2];
      if ((iVar2 == 0) || ((iVar2 - 1U & _Stack_40.dwAllocationGranularity) != 0)) {
        LeaveCriticalSection(lpCriticalSection);
        return 0x8004020e;
      }
      if (*(int *)(param_1 + 0x40) == 1) {
        uVar3 = 0x8004020f;
      }
      else {
        if (*(int *)(param_1 + 0x2c) <= *(int *)(param_1 + 0x1c)) {
          iVar1 = param_2[3] + param_2[1];
          if (iVar2 == 0) {
            trap(0x1c00);
          }
          if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
            trap(0x1800);
          }
          if (iVar1 % iVar2 != 0) {
            iVar1 = (iVar2 - iVar1 % iVar2) + iVar1;
          }
          iVar2 = param_2[3];
          *(int *)(param_1 + 0x30) = iVar1 - iVar2;
          param_3[1] = iVar1 - iVar2;
          uVar3 = *param_2;
          *(undefined4 *)(param_1 + 0x28) = uVar3;
          *param_3 = uVar3;
          uVar3 = param_2[2];
          *(undefined4 *)(param_1 + 0x34) = uVar3;
          param_3[2] = uVar3;
          uVar3 = param_2[3];
          *(undefined4 *)(param_1 + 0x38) = uVar3;
          param_3[3] = uVar3;
          *(undefined4 *)(param_1 + 0x3c) = 1;
          LeaveCriticalSection(lpCriticalSection);
          return 0;
        }
        uVar3 = 0x80040210;
      }
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar3;
}



/* 40bd3078 FUN_40bd3078 */

/* Boundary evidence: original MIPS .pdata 40bd3078..40bd30eb. Semantic name remains unreviewed. */

void FUN_40bd3078(int param_1)

{
  int *piVar1;
  
  while (piVar1 = *(int **)(param_1 + 0x24), piVar1 != (int *)0x0) {
    *(int *)(param_1 + 0x24) = piVar1[7];
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
    (**(code **)(*piVar1 + 0x54))(piVar1,1);
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (*(LPVOID *)(param_1 + 0x54) != (LPVOID)0x0) {
    VirtualFree(*(LPVOID *)(param_1 + 0x54),0,0x8000);
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  return;
}



/* 40bd30ec FUN_40bd30ec */

/* Boundary evidence: original MIPS .pdata 40bd30ec..40bd313b. Semantic name remains unreviewed. */

void FUN_40bd30ec(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40bde84c;
  param_1[3] = &PTR_FUN_40bde820;
  FUN_40bd2d4c(param_1 + 3);
  FUN_40bd3078((int)param_1);
  FUN_40bd28f0((int)param_1);
  return;
}



/* 40bd313c FUN_40bd313c */

/* Boundary evidence: original MIPS .pdata 40bd313c..40bd3393. Semantic name remains unreviewed. */

int FUN_40bd313c(undefined4 *param_1,int *param_2,int param_3)

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
              if (iVar1 < 0) goto LAB_40bd335c;
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
LAB_40bd335c:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40bd3394 FUN_40bd3394 */

/* Boundary evidence: original MIPS .pdata 40bd3394..40bd3473. Semantic name remains unreviewed. */

void FUN_40bd3394(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40bdccc8,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40bdccb8,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40bdebc0,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40bdcd48,0x10);
    if (iVar1 != 0) {
      FUN_40bd5458(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40bd53bc(piVar2,param_3);
  return;
}



/* 40bd3474 FUN_40bd3474 */

/* Boundary evidence: original MIPS .pdata 40bd3474..40bd34cf. Semantic name remains unreviewed. */

void FUN_40bd3474(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40bd52cc();
  return;
}



/* 40bd34d0 FUN_40bd34d0 */

/* Boundary evidence: original MIPS .pdata 40bd34d0..40bd3553. Semantic name remains unreviewed. */

undefined4 FUN_40bd34d0(int param_1,int *param_2)

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



/* 40bd3554 FUN_40bd3554 */

/* Boundary evidence: original MIPS .pdata 40bd3554..40bd35d7. Semantic name remains unreviewed. */

undefined4 FUN_40bd3554(int param_1,undefined4 *param_2)

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



/* 40bd35d8 FUN_40bd35d8 */

/* Boundary evidence: original MIPS .pdata 40bd35d8..40bd365f. Semantic name remains unreviewed. */

int FUN_40bd35d8(int param_1,uint *param_2)

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



/* 40bd3660 FUN_40bd3660 */

/* Boundary evidence: original MIPS .pdata 40bd3660..40bd3777. Semantic name remains unreviewed. */

undefined4 FUN_40bd3660(int param_1,LPCWSTR param_2,int *param_3)

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
          goto LAB_40bd3720;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40bd3720:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40bd3778 FUN_40bd3778 */

/* Boundary evidence: original MIPS .pdata 40bd3778..40bd3893. Semantic name remains unreviewed. */

undefined4 FUN_40bd3778(int param_1,undefined4 *param_2,wchar_t *param_3)

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
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40bdcdd8,(undefined4 *)(param_1 + 0x38));
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



/* 40bd3894 FUN_40bd3894 */

/* Boundary evidence: original MIPS .pdata 40bd3894..40bd3967. Semantic name remains unreviewed. */

undefined4 FUN_40bd3894(int param_1)

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
    HVar3 = CoCreateInstance((IID *)&DAT_40bdd8c8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40bdcd98,local_10);
    if (-1 < HVar3) {
      FUN_40bd313c(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bd3968 FUN_40bd3968 */

/* Boundary evidence: original MIPS .pdata 40bd3968..40bd3a5b. Semantic name remains unreviewed. */

int FUN_40bd3968(int param_1)

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
    HVar2 = CoCreateInstance((IID *)&DAT_40bdd8c8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40bdcd98,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40bd313c(puVar1,local_18[0],0);
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



/* 40bd3a5c FUN_40bd3a5c */

/* Boundary evidence: original MIPS .pdata 40bd3a5c..40bd3aa7. Semantic name remains unreviewed. */

undefined4 * FUN_40bd3a5c(undefined4 *param_1,uint param_2)

{
  FUN_40bd1058(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bd3aa8 FUN_40bd3aa8 */

/* Boundary evidence: original MIPS .pdata 40bd3aa8..40bd3c3f. Semantic name remains unreviewed. */

undefined4 FUN_40bd3aa8(int param_1,uint param_2,int *param_3,uint *param_4)

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
    bVar1 = FUN_40bd1b48(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40bd1214(param_1);
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
        iVar3 = FUN_40bd6870((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40bd6970((int *)(param_1 + 0x18),iVar2);
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



/* 40bd3c40 FUN_40bd3c40 */

/* Boundary evidence: original MIPS .pdata 40bd3c40..40bd3cbb. Semantic name remains unreviewed. */

undefined4 FUN_40bd3c40(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40bd1b48(param_1);
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



/* 40bd3cbc FUN_40bd3cbc */

/* Boundary evidence: original MIPS .pdata 40bd3cbc..40bd3d1f. Semantic name remains unreviewed. */

undefined4 * FUN_40bd3cbc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40bde7a8;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bd3d20 FUN_40bd3d20 */

/* Boundary evidence: original MIPS .pdata 40bd3d20..40bd3eb3. Semantic name remains unreviewed. */

uint FUN_40bd3d20(int param_1,uint param_2,undefined4 *param_3,int *param_4)

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
  
  local_28 = DAT_40be0550;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40bd8bd0(DAT_40be0550);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40bd1b94(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40bd8bd0(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40bd8bd0(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40bd6374(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40bd3e60:
          FUN_40bd6358((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40bd3e60;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40bd6358((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40bd8bd0(local_28);
    }
  }
  return uVar3;
}



/* 40bd3eb4 FUN_40bd3eb4 */

/* Boundary evidence: original MIPS .pdata 40bd3eb4..40bd3f6b. Semantic name remains unreviewed. */

uint FUN_40bd3eb4(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40be0550;
  bVar1 = FUN_40bd1b94(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40bd8bd0(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40bd6374(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40bd6358((int)auStack_60);
    FUN_40bd8bd0(local_18);
  }
  return uVar3;
}



/* 40bd3f6c FUN_40bd3f6c */

/* Boundary evidence: original MIPS .pdata 40bd3f6c..40bd40e3. Semantic name remains unreviewed. */

int FUN_40bd3f6c(int *param_1,int *param_2,undefined4 param_3)

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



/* 40bd40e4 FUN_40bd40e4 */

/* Boundary evidence: original MIPS .pdata 40bd40e4..40bd4257. Semantic name remains unreviewed. */

int FUN_40bd40e4(int *param_1,int *param_2,void *param_3,int *param_4)

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
             (iVar3 = FUN_40bd6600(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40bd3f6c(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40bd6714(local_28);
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



/* 40bd4258 FUN_40bd4258 */

/* Boundary evidence: original MIPS .pdata 40bd4258..40bd43df. Semantic name remains unreviewed. */

int FUN_40bd4258(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40bd6594(param_3), iVar1 == 0)) {
    iVar1 = FUN_40bd3f6c(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40bd40e4(param_1,param_2,param_3,local_30[0]);
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
  iVar2 = FUN_40bd40e4(param_1,param_2,param_3,local_30[0]);
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



/* 40bd43e0 FUN_40bd43e0 */

/* Boundary evidence: original MIPS .pdata 40bd43e0..40bd45a7. Semantic name remains unreviewed. */

int FUN_40bd43e0(int param_1,int *param_2,int param_3)

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
          goto LAB_40bd4578;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40bd4578;
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
LAB_40bd4578:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40bd45a8 FUN_40bd45a8 */

/* Boundary evidence: original MIPS .pdata 40bd45a8..40bd4647. Semantic name remains unreviewed. */

undefined4 FUN_40bd45a8(int param_1)

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



/* 40bd4648 FUN_40bd4648 */

/* Boundary evidence: original MIPS .pdata 40bd4648..40bd46d3. Semantic name remains unreviewed. */

undefined4 FUN_40bd4648(int param_1,void *param_2)

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
      FUN_40bd6224(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40bd6260(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40bd46d4 FUN_40bd46d4 */

/* Boundary evidence: original MIPS .pdata 40bd46d4..40bd46ef. Semantic name remains unreviewed. */

void FUN_40bd46d4(int param_1,undefined4 *param_2)

{
  FUN_40bd5db0(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40bd46f0 FUN_40bd46f0 */

/* Boundary evidence: original MIPS .pdata 40bd46f0..40bd476b. Semantic name remains unreviewed. */

int FUN_40bd46f0(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40bd45a8(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40bd476c FUN_40bd476c */

/* Boundary evidence: original MIPS .pdata 40bd476c..40bd47cb. Semantic name remains unreviewed. */

undefined4 * FUN_40bd476c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40bde7c8;
  if ((LPVOID)param_1[0xf] != (LPVOID)0x0) {
    FUN_40bd6714((LPVOID)param_1[0xf]);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bd47cc FUN_40bd47cc */

/* Boundary evidence: original MIPS .pdata 40bd47cc..40bd48bb. Semantic name remains unreviewed. */

undefined4 FUN_40bd47cc(int *param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == 0) {
    uVar2 = 0x80004003;
  }
  else {
    bVar1 = false;
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
    if (param_1 == (int *)0xc) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    EnterCriticalSection(lpCriticalSection);
    *(int *)(param_2 + 0x1c) = param_1[6];
    param_1[6] = param_2;
    param_1[7] = param_1[7] + 1;
    if (param_1[9] != 0) {
      FUN_40bd2c40((int)(param_1 + -3));
    }
    if ((param_1[0x11] != 0) && (param_1[7] == param_1[0xb])) {
      (**(code **)(param_1[-3] + 0x10))();
      bVar1 = true;
      param_1[0x11] = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
    if (bVar1) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bd48bc FUN_40bd48bc */

/* Boundary evidence: original MIPS .pdata 40bd48bc..40bd4907. Semantic name remains unreviewed. */

undefined4 * FUN_40bd48bc(undefined4 *param_1,uint param_2)

{
  FUN_40bd30ec(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bd4908 FUN_40bd4908 */

/* Boundary evidence: original MIPS .pdata 40bd4908..40bd498b. Semantic name remains unreviewed. */

undefined4 *
FUN_40bd4908(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40bd53fc(param_1,param_2,param_3);
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



/* 40bd498c FUN_40bd498c */

/* Boundary evidence: original MIPS .pdata 40bd498c..40bd4a6b. Semantic name remains unreviewed. */

undefined4 * FUN_40bd498c(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40bde788;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40bd67d0(param_1 + 6);
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
    FUN_40bd6a0c(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40bd4a6c FUN_40bd4a6c */

/* Boundary evidence: original MIPS .pdata 40bd4a6c..40bd4b17. Semantic name remains unreviewed. */

undefined4 FUN_40bd4a6c(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40bd1b48(param_1);
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
        puVar2 = FUN_40bd498c(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40bd4b18 FUN_40bd4b18 */

/* Boundary evidence: original MIPS .pdata 40bd4b18..40bd4ba7. Semantic name remains unreviewed. */

undefined4 * FUN_40bd4b18(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40bde7a8;
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



/* 40bd4ba8 FUN_40bd4ba8 */

/* Boundary evidence: original MIPS .pdata 40bd4ba8..40bd4c53. Semantic name remains unreviewed. */

undefined4 FUN_40bd4ba8(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40bd1b94(param_1);
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
        puVar2 = FUN_40bd4b18(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40bd4c54 FUN_40bd4c54 */

/* Boundary evidence: original MIPS .pdata 40bd4c54..40bd4d47. Semantic name remains unreviewed. */

undefined4 *
FUN_40bd4c54(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40bd53fc(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40bd6374(param_1 + 7);
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



/* 40bd4d48 FUN_40bd4d48 */

/* Boundary evidence: original MIPS .pdata 40bd4d48..40bd4e27. Semantic name remains unreviewed. */

int FUN_40bd4d48(int param_1,int *param_2,void *param_3)

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
        iVar1 = FUN_40bd4258(piVar2,param_2,param_3);
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



/* 40bd4e28 FUN_40bd4e28 */

/* Boundary evidence: original MIPS .pdata 40bd4e28..40bd4ea7. Semantic name remains unreviewed. */

undefined4 FUN_40bd4e28(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40bd4b18(puVar2,param_1 + -0xc,0);
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



/* 40bd4ea8 FUN_40bd4ea8 */

/* Boundary evidence: original MIPS .pdata 40bd4ea8..40bd4ef3. Semantic name remains unreviewed. */

undefined4 *
FUN_40bd4ea8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40bd4c54(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40bd4ef4 FUN_40bd4ef4 */

/* Boundary evidence: original MIPS .pdata 40bd4ef4..40bd4f4f. Semantic name remains unreviewed. */

undefined4 *
FUN_40bd4ef4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40bd4c54(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40bd4f50 FUN_40bd4f50 */

/* Boundary evidence: original MIPS .pdata 40bd4f50..40bd4fcf. Semantic name remains unreviewed. */

undefined4 FUN_40bd4f50(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40bd498c(puVar2,param_1 + -0xc,0);
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



/* 40bd4fd0 FUN_40bd4fd0 */

/* Boundary evidence: original MIPS .pdata 40bd4fd0..40bd507b. Semantic name remains unreviewed. */

undefined4 *
FUN_40bd4fd0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
            int param_5)

{
  HANDLE pvVar1;
  
  FUN_40bd53fc(param_1,param_2,param_3);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
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
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  if (param_5 != 0) {
    pvVar1 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,0,0x7fffffff,(LPCWSTR)0x0);
    param_1[0xb] = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      *param_4 = 0x8007000e;
    }
  }
  return param_1;
}



/* 40bd507c FUN_40bd507c */

/* Boundary evidence: original MIPS .pdata 40bd507c..40bd50cb. Semantic name remains unreviewed. */

undefined4 *
FUN_40bd507c(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  FUN_40bd4fd0(param_1,param_2,param_3,param_4,1);
  *param_1 = &PTR_FUN_40bde84c;
  param_1[3] = &PTR_FUN_40bde820;
  param_1[0x15] = 0;
  return param_1;
}



/* 40bd50cc FUN_40bd50cc */

/* Boundary evidence: original MIPS .pdata 40bd50cc..40bd529b. Semantic name remains unreviewed. */

int FUN_40bd50cc(int param_1)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x10);
  if (param_1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40bd2e24(param_1);
  if (-1 < iVar1) {
    if (iVar1 != 1) {
      if (*(int *)(param_1 + 0x54) != 0) {
        FUN_40bd3078(param_1);
      }
      iVar1 = *(int *)(param_1 + 0x40);
      iVar5 = *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x44);
      if (1 < iVar1) {
        if (iVar1 == 0) {
          trap(0x1c00);
        }
        if ((iVar1 == -1) && (iVar5 == -0x80000000)) {
          trap(0x1800);
        }
        if (iVar5 % iVar1 != 0) {
          iVar5 = (iVar1 - iVar5 % iVar1) + iVar5;
        }
      }
      pvVar2 = VirtualAlloc((LPVOID)0x0,iVar5 * *(int *)(param_1 + 0x34),0x1000,4);
      *(LPVOID *)(param_1 + 0x54) = pvVar2;
      if (pvVar2 == (LPVOID)0x0) {
LAB_40bd51b4:
        iVar1 = -0x7ff8fff2;
        goto LAB_40bd5270;
      }
      if (*(int *)(param_1 + 0x38) < *(int *)(param_1 + 0x34)) {
        do {
          puVar3 = operator_new(0x48);
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            iVar1 = *(int *)(param_1 + 0x44);
            uVar4 = *(undefined4 *)(param_1 + 0x3c);
            *puVar3 = &PTR_FUN_40bde7c8;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = (int)pvVar2 + iVar1;
            puVar3[4] = uVar4;
            puVar3[5] = uVar4;
            puVar3[6] = param_1;
            puVar3[0xf] = 0;
            puVar3[0x10] = 0;
            puVar3[0x11] = 0;
          }
          if (puVar3 == (undefined4 *)0x0) goto LAB_40bd51b4;
          puVar3[7] = *(undefined4 *)(param_1 + 0x24);
          *(undefined4 **)(param_1 + 0x24) = puVar3;
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
          iVar1 = *(int *)(param_1 + 0x38) + 1;
          *(int *)(param_1 + 0x38) = iVar1;
          pvVar2 = (LPVOID)((int)pvVar2 + iVar5);
        } while (iVar1 < *(int *)(param_1 + 0x34));
      }
      *(undefined4 *)(param_1 + 0x48) = 0;
    }
    iVar1 = 0;
  }
LAB_40bd5270:
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40bd529c FUN_40bd529c */

/* Boundary evidence: original MIPS .pdata 40bd529c..40bd52cb. Semantic name remains unreviewed. */

undefined4 FUN_40bd529c(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40be059c);
  return param_1;
}



/* 40bd52cc FUN_40bd52cc */

/* Boundary evidence: original MIPS .pdata 40bd52cc..40bd5323. Semantic name remains unreviewed. */

void FUN_40bd52cc(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40be059c);
  if ((LVar1 == 0) && (DAT_40be0598 != 0)) {
    FreeLibrary((HMODULE)DAT_40be0598);
    DAT_40be0598 = 0;
  }
  return;
}



/* 40bd5324 FUN_40bd5324 */

/* Boundary evidence: original MIPS .pdata 40bd5324..40bd535f. Semantic name remains unreviewed. */

void FUN_40bd5324(void)

{
  if (DAT_40be0598 == (HMODULE)0x0) {
    DAT_40be0598 = LoadLibraryW(L"OleAut32.dll");
  }
  return;
}



/* 40bd5360 FUN_40bd5360 */

/* Boundary evidence: original MIPS .pdata 40bd5360..40bd53bb. Semantic name remains unreviewed. */

undefined4 * FUN_40bd5360(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40bde880;
  InterlockedIncrement(&DAT_40be059c);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40bd53bc FUN_40bd53bc */

/* Boundary evidence: original MIPS .pdata 40bd53bc..40bd53fb. Semantic name remains unreviewed. */

undefined4 FUN_40bd53bc(int *param_1,undefined4 *param_2)

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



/* 40bd53fc FUN_40bd53fc */

/* Boundary evidence: original MIPS .pdata 40bd53fc..40bd5457. Semantic name remains unreviewed. */

undefined4 * FUN_40bd53fc(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40bde880;
  InterlockedIncrement(&DAT_40be059c);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40bd5458 FUN_40bd5458 */

/* Boundary evidence: original MIPS .pdata 40bd5458..40bd54db. Semantic name remains unreviewed. */

undefined4 FUN_40bd5458(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40bdebb0,0x10);
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



/* 40bd54dc FUN_40bd54dc */

/* Boundary evidence: original MIPS .pdata 40bd54dc..40bd5517. Semantic name remains unreviewed. */

uint FUN_40bd54dc(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40bd5518 FUN_40bd5518 */

/* Boundary evidence: original MIPS .pdata 40bd5518..40bd558f. Semantic name remains unreviewed. */

uint FUN_40bd5518(int *param_1)

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



/* 40bd5590 FUN_40bd5590 */

/* Boundary evidence: original MIPS .pdata 40bd5590..40bd584f. Semantic name remains unreviewed. */

void FUN_40bd5590(undefined4 param_1,int param_2)

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
  
  if (DAT_40be0540 == 0xffffffff) {
    DAT_40be0544 = 0xfa;
    DAT_40be0540 = 0xf9;
    DAT_40be0548 = 0xfb;
    DAT_40be054c = 0xfc;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,0,
                          &local_30);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Highest",(LPDWORD)0x0,&local_34,(LPBYTE)&local_28,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_28)) {
        local_28 = DAT_40be0540;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"AboveNormal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_2c,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_2c)) {
        local_2c = DAT_40be0544;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Normal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_24,&local_38
                              );
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_24)) {
        local_24 = DAT_40be0548;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"BelowNormal",(LPDWORD)0x0,&local_34,(LPBYTE)local_20,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_20[0])) {
        local_20[0] = DAT_40be054c;
      }
      if (((local_28 <= local_2c) && (local_2c <= local_24)) && (local_24 <= local_20[0])) {
        DAT_40be0540 = local_28;
        DAT_40be0544 = local_2c;
        DAT_40be0548 = local_24;
        DAT_40be054c = local_20[0];
      }
      RegCloseKey(local_30);
    }
  }
  uVar2 = DAT_40be0540;
  if (((param_2 != 1) && (uVar2 = DAT_40be0544, param_2 != 2)) &&
     (uVar2 = DAT_40be054c, param_2 != 4)) {
    uVar2 = DAT_40be0548;
  }
  CeSetThreadPriority(param_1,uVar2);
  return;
}



/* 40bd5850 FUN_40bd5850 */

/* Boundary evidence: original MIPS .pdata 40bd5850..40bd588f. Semantic name remains unreviewed. */

undefined4 * FUN_40bd5850(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



/* 40bd5890 FUN_40bd5890 */

/* Boundary evidence: original MIPS .pdata 40bd5890..40bd58bf. Semantic name remains unreviewed. */

void FUN_40bd5890(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40bd58c0 FUN_40bd58c0 */

/* Boundary evidence: original MIPS .pdata 40bd58c0..40bd58e3. Semantic name remains unreviewed. */

void FUN_40bd58c0(undefined4 *param_1)

{
  (**(code **)*param_1)();
  return;
}



/* 40bd58e4 FUN_40bd58e4 */

/* Boundary evidence: original MIPS .pdata 40bd58e4..40bd5957. Semantic name remains unreviewed. */

undefined4 FUN_40bd58e4(void)

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



/* 40bd5958 FUN_40bd5958 */

short * FUN_40bd5958(short *param_1,short *param_2,int param_3)

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



/* 40bd5994 FUN_40bd5994 */

/* WARNING: Removing unreachable block (ram,0x40bd5c08) */
/* Boundary evidence: original MIPS .pdata 40bd5994..40bd5daf. Semantic name remains unreviewed. */

int FUN_40bd5994(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                uint param_7,uint param_8)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  uVar15 = param_2;
  if ((int)param_2 < 0) {
    bVar2 = param_1 != 0;
    param_1 = -param_1;
    uVar15 = -(uint)bVar2 - param_2;
  }
  uVar12 = param_4;
  if ((int)param_4 < 0) {
    bVar2 = param_3 != 0;
    param_3 = -param_3;
    uVar12 = -(uint)bVar2 - param_4;
  }
  uVar14 = param_6;
  if ((int)param_6 < 0) {
    uVar14 = -(uint)(param_5 != 0) - param_6;
    param_5 = -param_5;
  }
  if ((0 < (int)param_2) || (bVar3 = 1, param_2 == 0)) {
    bVar3 = 0;
  }
  if ((0 < (int)param_4) || (bVar4 = 1, param_4 == 0)) {
    bVar4 = 0;
  }
  uVar13 = (uint)((ulonglong)param_1 * (ulonglong)param_3);
  bVar2 = (bool)(bVar4 ^ bVar3);
  uVar5 = (ulonglong)param_1 * (ulonglong)uVar12 +
          (ulonglong)uVar15 * (ulonglong)param_3 + ((ulonglong)param_1 * (ulonglong)param_3 >> 0x20)
  ;
  uVar16 = (uint)uVar5;
  uVar5 = (ulonglong)uVar15 * (ulonglong)uVar12 + (uVar5 >> 0x20);
  iVar8 = -1;
  uVar15 = uVar13;
  if (param_7 == 0 && param_8 == 0) goto LAB_40bd5bd0;
  iVar11 = iVar8;
  if (bVar2) {
    uVar15 = -param_7;
    uVar12 = -(uint)(param_7 != 0) - param_8;
    if ((int)param_8 < 0) goto LAB_40bd5b18;
    bVar1 = param_8 == 0;
    param_8 = param_7;
    if (bVar1) goto joined_r0x40bd5b80;
  }
  else {
    uVar15 = param_7;
    uVar12 = param_8;
    if ((int)param_8 < 1) {
joined_r0x40bd5b80:
      if (param_8 != 0) goto LAB_40bd5b20;
    }
LAB_40bd5b18:
    iVar11 = 0;
  }
LAB_40bd5b20:
  uVar15 = uVar13 + uVar15;
  uVar10 = uVar12 + uVar16;
  uVar16 = uVar10 + (uVar15 < uVar13);
  uVar13 = (uint)(uVar10 < uVar12) + (uint)(uVar16 < uVar10);
  uVar12 = uVar13 + iVar11;
  lVar6 = CONCAT44(iVar11 + (uint)(uVar12 < uVar13),uVar12);
  lVar7 = uVar5 + lVar6;
  uVar5 = uVar5 + lVar6;
  if (lVar7 < 0) {
    bVar2 = !bVar2;
    uVar12 = ~uVar15;
    uVar15 = uVar12 + 1;
    uVar16 = ~uVar16 + (uint)(uVar15 < uVar12);
    uVar12 = (uint)(uVar15 == 0 && uVar16 == 0);
    uVar13 = uVar12 + ~(uint)lVar7;
    uVar5 = CONCAT44(~(uint)((ulonglong)lVar7 >> 0x20) + (uint)(uVar13 < uVar12),uVar13);
  }
LAB_40bd5bd0:
  if (((int)param_6 < 1) && (param_6 != 0)) {
    if (bVar2) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
  }
  if (uVar5 < CONCAT44(uVar14,param_5)) {
    if (uVar5 == 0) {
      iVar8 = __ull_div(uVar15,uVar16,param_5,uVar14);
    }
    else {
      if (uVar14 == 0) {
        __ull_div(uVar16,(int)uVar5,param_5,0);
        uVar9 = __ull_rem(uVar16,(int)uVar5,param_5,0);
        iVar8 = __ull_div(uVar15,uVar9,param_5,0);
        if (!bVar2) {
          return iVar8;
        }
        return -iVar8;
      }
      iVar8 = 0;
      iVar11 = 0x40;
      do {
        iVar8 = iVar8 * 2;
        uVar13 = (uint)uVar5 * 2;
        uVar12 = (int)(uVar5 >> 0x20) << 1 | (uint)uVar5 >> 0x1f;
        if ((uVar16 & 0x80000000) != 0) {
          uVar13 = uVar13 + 1;
        }
        uVar10 = uVar15 >> 0x1f;
        uVar15 = uVar15 << 1;
        uVar16 = uVar16 << 1 | uVar10;
        uVar10 = uVar13;
        if ((uVar14 <= uVar12) && ((uVar14 != uVar12 || (param_5 <= uVar13)))) {
          iVar8 = iVar8 + 1;
          uVar10 = uVar13 - param_5;
          uVar12 = (uVar12 - uVar14) - (uint)(uVar13 < param_5);
        }
        uVar5 = CONCAT44(uVar12,uVar10);
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    if (bVar2) {
      iVar8 = -iVar8;
    }
  }
  else if (bVar2) {
    iVar8 = 0;
  }
  return iVar8;
}



/* 40bd5db0 FUN_40bd5db0 */

/* Boundary evidence: original MIPS .pdata 40bd5db0..40bd5e3b. Semantic name remains unreviewed. */

undefined4 FUN_40bd5db0(wchar_t *param_1,undefined4 *param_2)

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



/* 40bd5e3c FUN_40bd5e3c */

/* Boundary evidence: original MIPS .pdata 40bd5e3c..40bd5eb7. Semantic name remains unreviewed. */

int FUN_40bd5e3c(int param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 4) = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 8) = pvVar1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}



/* 40bd5eb8 FUN_40bd5eb8 */

/* Boundary evidence: original MIPS .pdata 40bd5eb8..40bd5f27. Semantic name remains unreviewed. */

void FUN_40bd5eb8(int param_1)

{
  FUN_40bc3bf0(param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (*(HANDLE *)(param_1 + 8) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 8));
  }
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 4));
  }
  return;
}



/* 40bd5f28 FUN_40bd5f28 */

/* Boundary evidence: original MIPS .pdata 40bd5f28..40bd5fdb. Semantic name remains unreviewed. */

bool FUN_40bd5f28(LPVOID param_1)

{
  HANDLE pvVar1;
  bool bVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD aDStack_18 [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)param_1 + 0x14) == 0) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40bd58c0,param_1,0,aDStack_18);
    if (pvVar1 != (HANDLE)0x0) {
      FUN_40bd5590(pvVar1,3);
    }
    bVar2 = pvVar1 != (HANDLE)0x0;
    *(HANDLE *)((int)param_1 + 0x14) = pvVar1;
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    bVar2 = false;
  }
  return bVar2;
}



/* 40bd5fdc FUN_40bd5fdc */

/* Boundary evidence: original MIPS .pdata 40bd5fdc..40bd6067. Semantic name remains unreviewed. */

undefined4 FUN_40bd5fdc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = param_2;
    EventModify(*(undefined4 *)(param_1 + 4),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 8),0xffffffff);
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return uVar1;
}



/* 40bd6068 FUN_40bd6068 */

/* Boundary evidence: original MIPS .pdata 40bd6068..40bd609f. Semantic name remains unreviewed. */

undefined4 FUN_40bd6068(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
  return *(undefined4 *)(param_1 + 0xc);
}



/* 40bd60a0 FUN_40bd60a0 */

/* Boundary evidence: original MIPS .pdata 40bd60a0..40bd6103. Semantic name remains unreviewed. */

undefined4 FUN_40bd60a0(int param_1,undefined4 *param_2)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 4),0);
  if (DVar1 == 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0xc);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bd6104 FUN_40bd6104 */

/* Boundary evidence: original MIPS .pdata 40bd6104..40bd613f. Semantic name remains unreviewed. */

void FUN_40bd6104(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  EventModify(*(undefined4 *)(param_1 + 4),2);
  EventModify(*(undefined4 *)(param_1 + 8),3);
  return;
}



/* 40bd6140 FUN_40bd6140 */

void FUN_40bd6140(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x1c) = param_2[3];
  return;
}



/* 40bd6164 FUN_40bd6164 */

void FUN_40bd6164(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = *param_2;
  *(undefined4 *)(param_1 + 0x30) = param_2[1];
  *(undefined4 *)(param_1 + 0x34) = param_2[2];
  *(undefined4 *)(param_1 + 0x38) = param_2[3];
  return;
}



/* 40bd6188 FUN_40bd6188 */

/* Boundary evidence: original MIPS .pdata 40bd6188..40bd6223. Semantic name remains unreviewed. */

LPVOID FUN_40bd6188(int param_1,uint param_2)

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



/* 40bd6224 FUN_40bd6224 */

/* Boundary evidence: original MIPS .pdata 40bd6224..40bd625f. Semantic name remains unreviewed. */

void FUN_40bd6224(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40bd6260 FUN_40bd6260 */

/* Boundary evidence: original MIPS .pdata 40bd6260..40bd62f3. Semantic name remains unreviewed. */

void FUN_40bd6260(void *param_1,void *param_2)

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



/* 40bd62f4 FUN_40bd62f4 */

/* Boundary evidence: original MIPS .pdata 40bd62f4..40bd6357. Semantic name remains unreviewed. */

void FUN_40bd62f4(int param_1)

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



/* 40bd6358 FUN_40bd6358 */

/* Boundary evidence: original MIPS .pdata 40bd6358..40bd6373. Semantic name remains unreviewed. */

void FUN_40bd6358(int param_1)

{
  FUN_40bd62f4(param_1);
  return;
}



/* 40bd6374 FUN_40bd6374 */

/* Boundary evidence: original MIPS .pdata 40bd6374..40bd63b3. Semantic name remains unreviewed. */

void * FUN_40bd6374(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40bd63b4 FUN_40bd63b4 */

/* Boundary evidence: original MIPS .pdata 40bd63b4..40bd641f. Semantic name remains unreviewed. */

undefined4 * FUN_40bd63b4(undefined4 *param_1,undefined4 *param_2)

{
  memset(param_1,0,0x48);
  param_1[10] = 1;
  param_1[8] = 1;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return param_1;
}



/* 40bd6420 FUN_40bd6420 */

/* Boundary evidence: original MIPS .pdata 40bd6420..40bd644b. Semantic name remains unreviewed. */

void * FUN_40bd6420(void *param_1,void *param_2)

{
  FUN_40bd6260(param_1,param_2);
  return param_1;
}



/* 40bd644c FUN_40bd644c */

/* Boundary evidence: original MIPS .pdata 40bd644c..40bd6497. Semantic name remains unreviewed. */

void * FUN_40bd644c(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40bd62f4((int)param_1);
    FUN_40bd6260(param_1,param_2);
  }
  return param_1;
}



/* 40bd6498 FUN_40bd6498 */

/* Boundary evidence: original MIPS .pdata 40bd6498..40bd64c3. Semantic name remains unreviewed. */

void * FUN_40bd6498(void *param_1,void *param_2)

{
  FUN_40bd644c(param_1,param_2);
  return param_1;
}



/* 40bd64c4 FUN_40bd64c4 */

/* Boundary evidence: original MIPS .pdata 40bd64c4..40bd656f. Semantic name remains unreviewed. */

undefined4 FUN_40bd64c4(void *param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  size_t _Size;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  if ((((iVar1 == 0) &&
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) && (iVar1 = memcmp((void *)((int)param_1 + 0x2c),(void *)((int)param_2 + 0x2c),0x10),
             iVar1 == 0)) &&
     ((_Size = *(size_t *)((int)param_1 + 0x40), _Size == *(size_t *)((int)param_2 + 0x40) &&
      ((_Size == 0 ||
       (iVar1 = memcmp(*(void **)((int)param_1 + 0x44),*(void **)((int)param_2 + 0x44),_Size),
       iVar1 == 0)))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bd6570 FUN_40bd6570 */

void FUN_40bd6570(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 1;
    *(int *)(param_1 + 0x28) = param_2;
  }
  return;
}



/* 40bd6594 FUN_40bd6594 */

/* Boundary evidence: original MIPS .pdata 40bd6594..40bd65ff. Semantic name remains unreviewed. */

undefined4 FUN_40bd6594(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40bdeb90,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40bdeb90,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bd6600 FUN_40bd6600 */

/* Boundary evidence: original MIPS .pdata 40bd6600..40bd6713. Semantic name remains unreviewed. */

undefined4 FUN_40bd6600(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40bdeb90,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40bdeb90,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40bdeb90,0x10);
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



/* 40bd6714 FUN_40bd6714 */

/* Boundary evidence: original MIPS .pdata 40bd6714..40bd6753. Semantic name remains unreviewed. */

void FUN_40bd6714(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40bd62f4((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40bd6754 FUN_40bd6754 */

/* Boundary evidence: original MIPS .pdata 40bd6754..40bd67af. Semantic name remains unreviewed. */

LPVOID FUN_40bd6754(void *param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = CoTaskMemAlloc(0x48);
  if (pvVar1 == (LPVOID)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    FUN_40bd6260(pvVar1,param_1);
  }
  return pvVar1;
}



/* 40bd67b0 FUN_40bd67b0 */

undefined4 * FUN_40bd67b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40bd67d0 FUN_40bd67d0 */

undefined4 * FUN_40bd67d0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40bd67f4 FUN_40bd67f4 */

/* Boundary evidence: original MIPS .pdata 40bd67f4..40bd6847. Semantic name remains unreviewed. */

void FUN_40bd67f4(undefined4 *param_1)

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



/* 40bd6848 FUN_40bd6848 */

undefined4 FUN_40bd6848(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    *param_2 = *(int *)(iVar2 + 4);
    uVar1 = *(undefined4 *)(iVar2 + 8);
  }
  return uVar1;
}



/* 40bd6870 FUN_40bd6870 */

int FUN_40bd6870(int *param_1,int param_2)

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



/* 40bd68b4 FUN_40bd68b4 */

/* Boundary evidence: original MIPS .pdata 40bd68b4..40bd696f. Semantic name remains unreviewed. */

int FUN_40bd68b4(int *param_1,int *param_2)

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



/* 40bd6970 FUN_40bd6970 */

/* Boundary evidence: original MIPS .pdata 40bd6970..40bd6a0b. Semantic name remains unreviewed. */

undefined4 * FUN_40bd6970(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40bd69c0;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40bd69c0:
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



/* 40bd6a0c FUN_40bd6a0c */

/* Boundary evidence: original MIPS .pdata 40bd6a0c..40bd6a6b. Semantic name remains unreviewed. */

undefined4 FUN_40bd6a0c(undefined4 *param_1,int *param_2)

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
    puVar1 = FUN_40bd6970(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40bd6a6c FUN_40bd6a6c */

/* Boundary evidence: original MIPS .pdata 40bd6a6c..40bd6ab3. Semantic name remains unreviewed. */

void FUN_40bd6a6c(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40bd67f4(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40bd6ab4 FUN_40bd6ab4 */

/* Boundary evidence: original MIPS .pdata 40bd6ab4..40bd6acf. Semantic name remains unreviewed. */

void FUN_40bd6ab4(int *param_1)

{
  FUN_40bd68b4(param_1,(int *)*param_1);
  return;
}



/* 40bd6ad0 FUN_40bd6ad0 */

/* Boundary evidence: original MIPS .pdata 40bd6ad0..40bd6b13. Semantic name remains unreviewed. */

void FUN_40bd6ad0(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x28),*(int *)(param_1 + 0x3c),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40bd6b14 FUN_40bd6b14 */

/* Boundary evidence: original MIPS .pdata 40bd6b14..40bd6bd7. Semantic name remains unreviewed. */

void FUN_40bd6b14(LPCRITICAL_SECTION param_1)

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
      FUN_40bd6ad0((int)param_1);
      LeaveCriticalSection(param_1);
      (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
      return;
    }
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40bd6bd8 FUN_40bd6bd8 */

/* Boundary evidence: original MIPS .pdata 40bd6bd8..40bd6c2f. Semantic name remains unreviewed. */

void FUN_40bd6bd8(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_40bd6970(*(undefined4 **)(param_1 + 0x24),param_2);
  if ((puVar1 == (undefined4 *)0x0) && (param_2 < (int *)0xfffffff1)) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



/* 40bd6c30 FUN_40bd6c30 */

/* Boundary evidence: original MIPS .pdata 40bd6c30..40bd6ecf. Semantic name remains unreviewed. */

LONG FUN_40bd6c30(LPCRITICAL_SECTION param_1,undefined4 *param_2,int param_3,int *param_4)

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
        else if ((param_1[2].RecursionCount == 0) || (param_1[3].LockCount == 0)) goto LAB_40bd6cf0;
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
          FUN_40bd6bd8((int)param_1,(int *)*param_2);
          param_2 = param_2 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      *param_4 = param_3;
      if ((param_1[1].LockCount == 0) ||
         (param_1[1].RecursionCount <=
          param_1[2].RecursionCount + *(int *)((int)param_1[1].OwningThread + 8))) {
        FUN_40bd6ad0((int)param_1);
      }
      LVar1 = 0;
      goto LAB_40bd6e98;
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
  goto LAB_40bd6d00;
LAB_40bd6cf0:
  *param_4 = iVar2 - iVar3;
  if (iVar2 - iVar3 < 0) {
    *param_4 = 0;
  }
LAB_40bd6d00:
  LVar1 = param_1[3].RecursionCount;
LAB_40bd6e98:
  LeaveCriticalSection(param_1);
  return LVar1;
}



/* 40bd6ed0 FUN_40bd6ed0 */

/* Boundary evidence: original MIPS .pdata 40bd6ed0..40bd6fc7. Semantic name remains unreviewed. */

void FUN_40bd6ed0(LPCRITICAL_SECTION param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  EnterCriticalSection(param_1);
  piVar2 = param_1[1].OwningThread;
  if (piVar2 != (int *)0x0) {
    while (piVar2 = (int *)FUN_40bd6ab4(piVar2), piVar2 != (int *)0x0) {
      if (piVar2 < (int *)0xfffffff1) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      else if (piVar2 == (int *)0xfffffffb) {
        pvVar1 = (void *)FUN_40bd6ab4(param_1[1].OwningThread);
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



/* 40bd6fc8 FUN_40bd6fc8 */

/* Boundary evidence: original MIPS .pdata 40bd6fc8..40bd70c3. Semantic name remains unreviewed. */

void FUN_40bd6fc8(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  
  if (param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    (**(code **)(*(int *)param_1[1].DebugInfo + 8))();
  }
  if (param_1[2].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    FUN_40bd6ed0(param_1);
  }
  else {
    EnterCriticalSection(param_1);
    param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1;
    param_1[3].RecursionCount = 1;
    FUN_40bd6ad0((int)param_1);
    LeaveCriticalSection(param_1);
    WaitForSingleObject(param_1[2].DebugInfo,0xffffffff);
    CloseHandle(param_1[2].DebugInfo);
    puVar1 = param_1[1].OwningThread;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_40bd6a6c(puVar1);
      operator_delete(puVar1);
    }
  }
  if (param_1[1].LockSemaphore != (HANDLE)0x0) {
    CloseHandle(param_1[1].LockSemaphore);
  }
  operator_delete((void *)param_1[2].LockCount);
  FUN_40bd5890(&param_1[1].SpinCount);
  DeleteCriticalSection(param_1);
  return;
}



/* 40bd70c4 FUN_40bd70c4 */

/* Boundary evidence: original MIPS .pdata 40bd70c4..40bd739b. Semantic name remains unreviewed. */

undefined4 FUN_40bd70c4(LPCRITICAL_SECTION param_1)

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
LAB_40bd7100:
  do {
    bVar1 = false;
    EnterCriticalSection(param_1);
    do {
      while( true ) {
        if (param_1[3].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
          FUN_40bd6ed0(param_1);
          LeaveCriticalSection(param_1);
          return 0;
        }
        if (param_1[2].LockSemaphore != (HANDLE)0x0) {
          FUN_40bd6ed0(param_1);
          EventModify(param_1[1].SpinCount,3);
        }
        uVar2 = FUN_40bd6ab4(param_1[1].OwningThread);
        if (uVar2 != 0) break;
        if ((param_1[1].LockCount != 0) || (param_1[2].RecursionCount == 0)) {
          param_1[2].OwningThread = (HANDLE)((int)param_1[2].OwningThread + 1);
          bVar1 = true;
          goto LAB_40bd7214;
        }
LAB_40bd71c0:
        if (uVar2 != 0xfffffffe) {
          if (uVar2 == 0xfffffffb) {
            pvVar3 = (void *)FUN_40bd6ab4(param_1[1].OwningThread);
          }
          goto LAB_40bd71f8;
        }
        if (param_1[2].RecursionCount != 0) goto LAB_40bd71f8;
      }
      if (0xfffffff0 < uVar2) goto LAB_40bd71c0;
      if (param_1[2].RecursionCount < param_1[1].RecursionCount) {
        *(uint *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = uVar2;
        param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
      }
    } while (param_1[2].RecursionCount != param_1[1].RecursionCount);
LAB_40bd71f8:
    pvVar6 = (void *)param_1[2].RecursionCount;
    param_1[2].RecursionCount = 0;
LAB_40bd7214:
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
        if (param_1[3].RecursionCount != 0) goto LAB_40bd7100;
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
      goto LAB_40bd7100;
    }
    WaitForSingleObject(param_1[1].LockSemaphore,0xffffffff);
  } while( true );
}



/* 40bd739c FUN_40bd739c */

/* Boundary evidence: original MIPS .pdata 40bd739c..40bd740b. Semantic name remains unreviewed. */

void FUN_40bd739c(LPCRITICAL_SECTION param_1)

{
  int aiStack_10 [2];
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    param_1[3].LockCount = 1;
    FUN_40bd6c30(param_1,(undefined4 *)0x0,0,aiStack_10);
    param_1[3].LockCount = 0;
  }
  else {
    EnterCriticalSection(param_1);
    FUN_40bd6bd8((int)param_1,(int *)0xfffffffe);
    FUN_40bd6ad0((int)param_1);
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40bd740c FUN_40bd740c */

/* Boundary evidence: original MIPS .pdata 40bd740c..40bd74ab. Semantic name remains unreviewed. */

void FUN_40bd740c(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[1].LockCount != 0) {
      FUN_40bd739c(param_1);
    }
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      (**(code **)(*(int *)param_1->SpinCount + 0x38))();
    }
  }
  else if (param_1[3].RecursionCount == 0) {
    param_1[2].SpinCount = 0;
    FUN_40bd6bd8((int)param_1,(int *)0xfffffffd);
    FUN_40bd6ad0((int)param_1);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40bd74ac FUN_40bd74ac */

/* Boundary evidence: original MIPS .pdata 40bd74ac..40bd755f. Semantic name remains unreviewed. */

void FUN_40bd74ac(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  
  EnterCriticalSection(param_1);
  if ((param_1[2].SpinCount == 0) || (param_1[1].OwningThread == (HANDLE)0x0)) {
    LeaveCriticalSection(param_1);
    if (param_1[1].OwningThread == (HANDLE)0x0) {
      FUN_40bd6ed0(param_1);
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



/* 40bd7560 FUN_40bd7560 */

/* Boundary evidence: original MIPS .pdata 40bd7560..40bd7587. Semantic name remains unreviewed. */

void FUN_40bd7560(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  int aiStack_10 [2];
  
  local_res4[0] = param_2;
  FUN_40bd6c30(param_1,local_res4,1,aiStack_10);
  return;
}



/* 40bd7588 FUN_40bd7588 */

/* Boundary evidence: original MIPS .pdata 40bd7588..40bd75db. Semantic name remains unreviewed. */

undefined4 FUN_40bd7588(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40bd58e4();
  uVar2 = FUN_40bd70c4(param_1);
  if (-1 < iVar1) {
    CoUninitialize();
  }
  return uVar2;
}



/* 40bd75dc FUN_40bd75dc */

/* Boundary evidence: original MIPS .pdata 40bd75dc..40bd781f. Semantic name remains unreviewed. */

LPCRITICAL_SECTION
FUN_40bd75dc(LPCRITICAL_SECTION param_1,undefined4 *param_2,DWORD *param_3,int param_4,int param_5,
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
  FUN_40bd5850(&param_1[1].SpinCount,0);
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
  DVar1 = (**(code **)*param_2)(param_2,&DAT_40bdcd38,p_Var9);
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
LAB_40bd771c:
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
        FUN_40bd67b0(puVar5,0,param_8);
      }
      param_1[1].OwningThread = puVar5;
      if (puVar5 == (undefined4 *)0x0) goto LAB_40bd771c;
      p_Var6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40bd7588,param_1,0,aDStack_28);
      param_1[2].DebugInfo = p_Var6;
      if (p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        FUN_40bd5590(p_Var6,param_9);
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



/* 40bd7864 FUN_40bd7864 */

/* Boundary evidence: original MIPS .pdata 40bd7864..40bd78e3. Semantic name remains unreviewed. */

void FUN_40bd7864(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40be021c) {
    ppuVar2 = &PTR_DAT_40be020c;
    iVar1 = DAT_40be021c;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40be021c;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40bd78e4 FUN_40bd78e4 */

/* Boundary evidence: original MIPS .pdata 40bd78e4..40bd7983. Semantic name remains unreviewed. */

undefined4 FUN_40bd78e4(HMODULE param_1,int param_2)

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
    DAT_40be06c0 = 1;
    DAT_40be05ac = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40be05ac);
    if (BVar1 != 0) {
      DAT_40be06c0 = DAT_40be05bc;
    }
    uVar2 = 1;
    DAT_40be06c4 = param_1;
  }
  FUN_40bd7864(uVar2);
  return 1;
}



/* 40bd7984 FUN_40bd7984 */

undefined4 FUN_40bd7984(int param_1,int *param_2)

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



/* 40bd79d4 FUN_40bd79d4 */

/* Boundary evidence: original MIPS .pdata 40bd79d4..40bd7a7f. Semantic name remains unreviewed. */

undefined4 FUN_40bd79d4(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40bdebb0,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40bdebd0,0x10), iVar2 == 0)) {
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



/* 40bd7a80 FUN_40bd7a80 */

/* Boundary evidence: original MIPS .pdata 40bd7a80..40bd7ad7. Semantic name remains unreviewed. */

void * FUN_40bd7a80(void *param_1,uint param_2)

{
  FUN_40bd52cc();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bd7ad8 FUN_40bd7ad8 */

/* Boundary evidence: original MIPS .pdata 40bd7ad8..40bd7bfb. Semantic name remains unreviewed. */

int FUN_40bd7ad8(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40bdebb0,0x10), iVar1 == 0)) {
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



/* 40bd7bfc DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x17bfc  1  DllCanUnloadNow */
  if ((0 < DAT_40be06c8) || (HVar1 = 0, DAT_40be059c != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40bd7c28 FUN_40bd7c28 */

/* Boundary evidence: original MIPS .pdata 40bd7c28..40bd7c83. Semantic name remains unreviewed. */

undefined4 * FUN_40bd7c28(undefined4 *param_1,undefined4 param_2)

{
  FUN_40bd529c(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40bde96c;
  param_1[2] = 0;
  return param_1;
}



/* 40bd7c84 FUN_40bd7c84 */

/* Boundary evidence: original MIPS .pdata 40bd7c84..40bd7cb3. Semantic name remains unreviewed. */

int FUN_40bd7c84(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40bd7a80(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bd7cb4 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40bd7cb4..40bd7ddb. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0x17cb4  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40bdebb0,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40bdebd0,0x10), iVar1 == 0)) {
    iVar1 = DAT_40be021c;
    iVar7 = 0;
    if (0 < DAT_40be021c) {
      ppuVar6 = &PTR_u_Alchemy_Program_Stream_Demux_Fil_40be0208;
      do {
        iVar3 = FUN_40bd7984((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40bd7c28(puVar4,ppuVar6);
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



/* 40bd7ddc FUN_40bd7ddc */

/* Boundary evidence: original MIPS .pdata 40bd7ddc..40bd7f27. Semantic name remains unreviewed. */

undefined4 FUN_40bd7ddc(HKEY param_1,wchar_t *param_2)

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
  
  local_20 = DAT_40be0550;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40bd8bd0(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40bd7ddc(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40bd8bd0(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bd7f28 FUN_40bd7f28 */

/* Boundary evidence: original MIPS .pdata 40bd7f28..40bd81b7. Semantic name remains unreviewed. */

uint FUN_40bd7f28(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  
  local_30 = DAT_40be0550;
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
  FUN_40bd8bd0(local_30);
  return uVar1;
}



/* 40bd81b8 FUN_40bd81b8 */

/* Boundary evidence: original MIPS .pdata 40bd81b8..40bd822b. Semantic name remains unreviewed. */

undefined4 FUN_40bd81b8(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40be0550;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40bd7ddc((HKEY)0x80000000,aWStack_218);
  FUN_40bd8bd0(local_10);
  return 0;
}



/* 40bd822c FUN_40bd822c */

/* Boundary evidence: original MIPS .pdata 40bd822c..40bd8463. Semantic name remains unreviewed. */

DWORD FUN_40bd822c(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40be0550;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40be06c4,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40be021c) {
      ppuVar5 = &PTR_u_Alchemy_Program_Stream_Demux_Fil_40be0208;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40bd7f28(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40bdcd48,local_240
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
      } while (iVar4 < DAT_40be021c);
    }
  }
  FUN_40bd8bd0(local_30);
  return DVar3;
}



/* 40bd8464 FUN_40bd8464 */

/* Boundary evidence: original MIPS .pdata 40bd8464..40bd85eb. Semantic name remains unreviewed. */

int FUN_40bd8464(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40be021c != 0) {
    iVar3 = DAT_40be021c;
    ppuVar4 = &PTR_DAT_40be020c + DAT_40be021c * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40bdcd48,local_30);
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
      HVar2 = FUN_40bd81b8(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
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



/* 40bd85ec FUN_40bd85ec */

/* Boundary evidence: original MIPS .pdata 40bd85ec..40bd861f. Semantic name remains unreviewed. */

void FUN_40bd85ec(int param_1)

{
  if (param_1 == 0) {
    FUN_40bd8464();
  }
  else {
    FUN_40bd822c();
  }
  return;
}



/* 40bd8620 FUN_40bd8620 */

/* Boundary evidence: original MIPS .pdata 40bd8620..40bd864f. Semantic name remains unreviewed. */

void FUN_40bd8620(int *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
  }
  return;
}



/* 40bd8650 FUN_40bd8650 */

undefined4 FUN_40bd8650(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 1;
    uVar1 = 0;
  }
  return uVar1;
}



/* 40bd8678 FUN_40bd8678 */

/* Boundary evidence: original MIPS .pdata 40bd8678..40bd8813. Semantic name remains unreviewed. */

uint FUN_40bd8678(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  DWORD DVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int *local_28 [2];
  
  if (param_5 == (int *)0x0) {
    return 0x80004003;
  }
  *param_5 = 0;
  if (param_3 != 0) {
    return 0x8002802b;
  }
  if (*param_1 == 0) {
    iVar1 = FUN_40bd5324();
    if ((iVar1 == 0) ||
       (pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadRegTypeLib"), pcVar3 == (code *)0x0)) {
LAB_40bd86ec:
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        return DVar2;
      }
      return DVar2 & 0xffff | 0x80070000;
    }
    iVar4 = (*pcVar3)(&UNK_40bdd1c8,1,0,param_4,local_28);
    if (iVar4 < 0) {
      pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadTypeLib");
      if (pcVar3 == (code *)0x0) goto LAB_40bd86ec;
      uVar5 = (*pcVar3)(L"control.tlb",local_28);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
    }
    uVar5 = (**(code **)(*local_28[0] + 0x18))(local_28[0],param_2,param_1);
    (**(code **)(*local_28[0] + 8))();
    if ((int)uVar5 < 0) {
      return uVar5;
    }
  }
  *param_5 = *param_1;
  (**(code **)(*(int *)*param_1 + 4))();
  return 0;
}



/* 40bd8814 FUN_40bd8814 */

/* Boundary evidence: original MIPS .pdata 40bd8814..40bd89db. Semantic name remains unreviewed. */

DWORD FUN_40bd8814(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  DWORD DVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  undefined1 auStackX_0 [16];
  int *local_28 [2];
  
  piVar5 = (int *)0x0;
  if (auStackX_0 == (undefined1 *)0x28) {
    return 0x80004003;
  }
  if (*param_1 == 0) {
    iVar1 = FUN_40bd5324();
    if ((iVar1 == 0) ||
       (pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadRegTypeLib"), pcVar3 == (code *)0x0)) {
LAB_40bd8880:
      DVar2 = GetLastError();
      if (0 < (int)DVar2) {
        DVar2 = DVar2 & 0xffff | 0x80070000;
      }
      goto LAB_40bd8978;
    }
    iVar4 = (*pcVar3)(&UNK_40bdd1c8,1,0,param_5,local_28);
    if (iVar4 < 0) {
      pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadTypeLib");
      if (pcVar3 == (code *)0x0) goto LAB_40bd8880;
      DVar2 = (*pcVar3)(L"control.tlb",local_28);
      if ((int)DVar2 < 0) goto LAB_40bd8978;
    }
    DVar2 = (**(code **)(*local_28[0] + 0x18))(local_28[0],param_2,param_1);
    (**(code **)(*local_28[0] + 8))();
    if ((int)DVar2 < 0) goto LAB_40bd8978;
  }
  piVar5 = (int *)*param_1;
  (**(code **)(*piVar5 + 4))(piVar5);
  DVar2 = 0;
LAB_40bd8978:
  if (-1 < (int)DVar2) {
    DVar2 = (**(code **)(*piVar5 + 0x28))(piVar5,param_3,param_4,param_6);
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  return DVar2;
}



/* 40bd8adc FUN_40bd8adc */

/* Boundary evidence: original MIPS .pdata 40bd8adc..40bd8b4f. Semantic name remains unreviewed. */

void FUN_40bd8adc(void)

{
  uint uVar1;
  
  if ((DAT_40be0550 == 0) || (DAT_40be0550 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40be0550 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40be0550 == 0) {
      DAT_40be0550 = 0xb064;
    }
  }
  DAT_40be0554 = ~DAT_40be0550;
  return;
}



/* 40bd8b50 FUN_40bd8b50 */

/* Boundary evidence: original MIPS .pdata 40bd8b50..40bd8ba3. Semantic name remains unreviewed. */

void FUN_40bd8b50(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40bd8bd0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40bd8ba4 FUN_40bd8ba4 */

/* Boundary evidence: original MIPS .pdata 40bd8ba4..40bd8bcf. Semantic name remains unreviewed. */

undefined4 FUN_40bd8ba4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40bd8b50(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40bd8bd0 FUN_40bd8bd0 */

/* Boundary evidence: original MIPS .pdata 40bd8bd0..40bd8c17. Semantic name remains unreviewed. */

void FUN_40bd8bd0(uint param_1)

{
  if ((param_1 == DAT_40be0550) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40bd8cf8 FUN_40bd8cf8 */

/* Boundary evidence: original MIPS .pdata 40bd8cf8..40bd8d67. Semantic name remains unreviewed. */

void FUN_40bd8cf8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40bd8b50(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 40bd8d88 FUN_40bd8d88 */

/* Boundary evidence: original MIPS .pdata 40bd8d88..40bd8ec3. Semantic name remains unreviewed. */

int FUN_40bd8d88(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40be06dc != (code *)0x0) {
      iVar2 = (*DAT_40be06dc)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40bd8e38;
    FUN_40bd910c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40bcf6bc(param_1,param_2);
  }
LAB_40bd8e38:
  if (((param_2 == 0) && (FUN_40bd9094(), iVar1 != 0)) && (DAT_40be06dc != (code *)0x0)) {
    iVar1 = (*DAT_40be06dc)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40bd8ec4 FUN_40bd8ec4 */

/* Boundary evidence: original MIPS .pdata 40bd8ec4..40bd8eef. Semantic name remains unreviewed. */

void FUN_40bd8ec4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40bd8ef0 entry */

/* Boundary evidence: original MIPS .pdata 40bd8ef0..40bd8f47. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40bd8adc();
  }
  FUN_40bd8d88(param_1,param_2,param_3);
  return;
}



/* 40bd8fa8 FUN_40bd8fa8 */

/* Boundary evidence: original MIPS .pdata 40bd8fa8..40bd9093. Semantic name remains unreviewed. */

void FUN_40bd8fa8(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40be06d0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40be06d8;
    if (DAT_40be06d8 != (undefined4 *)0x0) {
      while (DAT_40be06d4 = DAT_40be06d4 + -1, _Memory <= DAT_40be06d4) {
        if ((code *)*DAT_40be06d4 != (code *)0x0) {
          (*(code *)*DAT_40be06d4)();
          _Memory = DAT_40be06d8;
        }
      }
      free(_Memory);
      DAT_40be06d4 = (undefined4 *)0x0;
      DAT_40be06d8 = (undefined4 *)0x0;
    }
    FUN_40bd90b8((undefined4 *)&DAT_40bda010,(undefined4 *)&DAT_40bda014);
  }
  FUN_40bd90b8((undefined4 *)&DAT_40bda018,(undefined4 *)&DAT_40bda01c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40bd9094 FUN_40bd9094 */

/* Boundary evidence: original MIPS .pdata 40bd9094..40bd90b7. Semantic name remains unreviewed. */

void FUN_40bd9094(void)

{
  FUN_40bd8fa8(0,0,1);
  return;
}



/* 40bd90b8 FUN_40bd90b8 */

/* Boundary evidence: original MIPS .pdata 40bd90b8..40bd910b. Semantic name remains unreviewed. */

void FUN_40bd90b8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40bd910c FUN_40bd910c */

/* Boundary evidence: original MIPS .pdata 40bd910c..40bd9147. Semantic name remains unreviewed. */

void FUN_40bd910c(void)

{
  FUN_40bd90b8((undefined4 *)&DAT_40bda008,(undefined4 *)&DAT_40bda00c);
  FUN_40bd90b8((undefined4 *)&DAT_40bda000,(undefined4 *)&DAT_40bda004);
  return;
}


