/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40b51000 FUN_40b51000 */

uint FUN_40b51000(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1[2];
  if (param_2 <= uVar1) {
    return (*param_1 << (0x20 - uVar1 & 0x1f)) >> (0x20 - param_2 & 0x1f);
  }
  return param_1[1] >> (0x20 - (param_2 - uVar1) & 0x1f) |
         ((1 << (uVar1 & 0x1f)) - 1U & *param_1) << (param_2 - uVar1 & 0x1f);
}



/* 40b51064 FUN_40b51064 */

/* Boundary evidence: original MIPS .pdata 40b51064..40b510b3. Semantic name remains unreviewed. */

undefined4 FUN_40b51064(undefined1 *param_1,int param_2)

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



/* 40b510b4 FUN_40b510b4 */

/* Boundary evidence: original MIPS .pdata 40b510b4..40b5116b. Semantic name remains unreviewed. */

void FUN_40b510b4(undefined4 *param_1,int param_2)

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
    goto LAB_40b51148;
  }
  _local_8 = 0;
  _local_8 = 0;
  if (uVar2 == 1) {
LAB_40b51138:
    _local_8 = CONCAT13(*puVar1,_local_8);
  }
  else {
    if (uVar2 == 2) {
LAB_40b51130:
      _local_8 = CONCAT12(puVar1[1],local_8);
      goto LAB_40b51138;
    }
    if (uVar2 == 3) {
      _local_8 = (uint3)(byte)puVar1[2] << 8;
      goto LAB_40b51130;
    }
  }
  param_1[4] = 0;
LAB_40b51148:
  param_1[1] = _local_8;
  param_1[6] = puVar1 + 4;
  param_1[2] = (param_1[2] - param_2) + 0x20;
  return;
}



/* 40b5116c FUN_40b5116c */

/* Boundary evidence: original MIPS .pdata 40b5116c..40b511ef. Semantic name remains unreviewed. */

uint FUN_40b5116c(uint *param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_40b51000(param_1,param_2);
    if ((char)param_1[5] == '\0') {
      if (param_2 < param_1[2]) {
        param_1[2] = param_1[2] - param_2;
      }
      else {
        FUN_40b510b4(param_1,param_2);
      }
    }
  }
  return uVar1;
}



/* 40b511f0 FUN_40b511f0 */

/* Boundary evidence: original MIPS .pdata 40b511f0..40b51307. Semantic name remains unreviewed. */

void FUN_40b511f0(undefined4 *param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 local_18;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((param_3 != 0) && (param_2 != (undefined1 *)0x0)) {
      param_1[8] = param_2;
      param_1[3] = param_3;
      param_1[4] = param_3;
      if (param_3 < 4) {
        local_18 = FUN_40b51064(param_2,param_3);
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
        local_18 = FUN_40b51064(param_2 + 4,uVar1);
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



/* 40b51308 FUN_40b51308 */

/* Boundary evidence: original MIPS .pdata 40b51308..40b520bf. Semantic name remains unreviewed. */

undefined4 FUN_40b51308(undefined1 *param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  memset(param_1,0,0x1d7);
  param_1[0xb0] = 0;
  uVar1 = FUN_40b51000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b510b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  *param_1 = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,2);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 3) {
      FUN_40b510b4(param_2,2);
    }
    else {
      param_2[2] = param_2[2] - 2;
    }
  }
  param_1[1] = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b510b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[2] = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b510b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[3] = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b510b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[4] = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b510b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[5] = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,2);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 3) {
      FUN_40b510b4(param_2,2);
    }
    else {
      param_2[2] = param_2[2] - 2;
    }
  }
  param_1[6] = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,3);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 4) {
      FUN_40b510b4(param_2,3);
    }
    else {
      param_2[2] = param_2[2] - 3;
    }
  }
  param_1[7] = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b510b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[8] = (char)uVar1;
  uVar1 = FUN_40b51000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40b510b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[9] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40b51000(param_2,4);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 5) {
        FUN_40b510b4(param_2,4);
      }
      else {
        param_2[2] = param_2[2] - 4;
      }
    }
    param_1[10] = (char)uVar1;
  }
  uVar1 = FUN_40b51000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40b510b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[0xb] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40b51000(param_2,4);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 5) {
        FUN_40b510b4(param_2,4);
      }
      else {
        param_2[2] = param_2[2] - 4;
      }
    }
    param_1[0xc] = (char)uVar1;
  }
  uVar1 = FUN_40b51000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40b510b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[0xd] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40b51000(param_2,2);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 3) {
        FUN_40b510b4(param_2,2);
      }
      else {
        param_2[2] = param_2[2] - 2;
      }
    }
    param_1[0xf] = (char)uVar1;
    uVar1 = FUN_40b51000(param_2,1);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 2) {
        FUN_40b510b4(param_2,1);
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
          FUN_40b510b4(param_2,1);
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
          FUN_40b510b4(param_2,4);
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
          FUN_40b510b4(param_2,1);
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
          FUN_40b510b4(param_2,4);
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
          FUN_40b510b4(param_2,1);
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
          FUN_40b510b4(param_2,4);
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
          FUN_40b510b4(param_2,4);
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
          FUN_40b510b4(param_2,4);
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
          FUN_40b510b4(param_2,1);
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
          FUN_40b510b4(param_2,4);
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
      FUN_40b510b4(param_2,uVar4);
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
      FUN_40b510b4(param_2,8);
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
          FUN_40b510b4(param_2,8);
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



/* 40b520c0 FUN_40b520c0 */

/* Boundary evidence: original MIPS .pdata 40b520c0..40b52493. Semantic name remains unreviewed. */

void FUN_40b520c0(uint *param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5)

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
  
  local_30 = DAT_40b6bf1c;
  *param_2 = 0;
  uVar1 = FUN_40b51000(param_1,1);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
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
          FUN_40b510b4(param_1,8);
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
      FUN_40b510b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
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
      FUN_40b510b4(param_1,1);
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
      FUN_40b510b4(param_1,0x17);
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
      FUN_40b510b4(param_1,4);
    }
    else {
      param_1[2] = uVar1 - 4;
    }
  }
  for (iVar4 = uVar3 + 1; iVar4 != 0; iVar4 = iVar4 + -1) {
    if ((-1 < (int)uVar2) && ((char)param_1[5] == '\0')) {
      if (param_1[2] < 0x15) {
        FUN_40b510b4(param_1,0x14);
      }
      else {
        param_1[2] = param_1[2] - 0x14;
      }
    }
    if (uVar3 == 0) {
      FUN_40b51308(auStack_288,param_1);
      *param_3 = (uint)local_286;
      *param_5 = (uint)local_1d8;
    }
  }
  FUN_40b64a98(local_30);
  return;
}



/* 40b52494 FUN_40b52494 */

/* Boundary evidence: original MIPS .pdata 40b52494..40b525af. Semantic name remains unreviewed. */

undefined4 FUN_40b52494(undefined1 *param_1,int param_2,uint param_3)

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
  FUN_40b511f0(auStack_30,param_1,param_3);
  if (local_1c == '\0') {
    if (local_28 < 0x11) {
      FUN_40b510b4(auStack_30,0x10);
    }
    else {
      local_28 = local_28 - 0x10;
    }
    if (local_1c == '\0') {
      if (local_28 < 0x11) {
        FUN_40b510b4(auStack_30,0x10);
      }
      else {
        local_28 = local_28 - 0x10;
      }
    }
  }
  puVar3 = &local_3c;
  puVar2 = &local_34;
  puVar1 = &local_40;
  FUN_40b520c0(auStack_30,puVar1,puVar2,puVar3,&local_38);
  if (param_2 == 0) {
    FUN_40b53210(0x40b66020,puVar1,puVar2,(va_list)puVar3);
    return 0;
  }
  *(uint *)(param_2 + 8) = local_3c >> 3;
  *(char *)(param_2 + 2) = (char)(undefined2)local_38;
  *(char *)(param_2 + 3) = (char)((ushort)(undefined2)local_38 >> 8);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(&DAT_40b6b114 + local_34 * 4);
  return 0;
}



/* 40b525b0 FUN_40b525b0 */

undefined4 FUN_40b525b0(char *param_1,undefined1 *param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((*param_1 == '!') && ((param_1[1] == '\f' || (bVar2 = false, param_1[1] == -0x31)))) {
    bVar2 = true;
  }
  cVar1 = param_1[1];
  if ((!bVar2) && (cVar1 != '!')) {
    return 0xffffffff;
  }
  *param_2 = 0xff;
  param_2[1] = 0x32;
  if (cVar1 != '!') {
    *(undefined4 *)(param_2 + 8) = 0x31ce;
    *(undefined4 *)(param_2 + 4) = 0xac44;
    *param_4 = 0;
  }
  else {
    *(undefined4 *)(param_2 + 8) = 0xa41;
    *(undefined4 *)(param_2 + 4) = 24000;
    *param_4 = 1;
  }
  param_2[2] = 2;
  param_2[3] = 0;
  return 0;
}



/* 40b52680 FUN_40b52680 */

/* Boundary evidence: original MIPS .pdata 40b52680..40b52cd3. Semantic name remains unreviewed. */

undefined4 FUN_40b52680(uint *param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  *param_2 = 0;
  uVar1 = FUN_40b51000(param_1,1);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  *param_4 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 3) {
      FUN_40b510b4(param_1,2);
    }
    else {
      param_1[2] = param_1[2] - 2;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 3) {
      FUN_40b510b4(param_1,2);
    }
    else {
      param_1[2] = param_1[2] - 2;
    }
  }
  uVar1 = FUN_40b51000(param_1,4);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 5) {
      FUN_40b510b4(param_1,4);
    }
    else {
      param_1[2] = param_1[2] - 4;
    }
  }
  *param_3 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  uVar1 = FUN_40b51000(param_1,3);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 4) {
      FUN_40b510b4(param_1,3);
    }
    else {
      param_1[2] = param_1[2] - 3;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  *param_5 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b510b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  uVar1 = FUN_40b51000(param_1,0xd);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 0xe) {
      FUN_40b510b4(param_1,0xd);
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
        FUN_40b510b4(param_1,0xb);
      }
      else {
        param_1[2] = param_1[2] - 0xb;
      }
    }
    if ((char)param_1[5] == '\0') {
      if (param_1[2] < 3) {
        FUN_40b510b4(param_1,2);
      }
      else {
        param_1[2] = param_1[2] - 2;
      }
    }
    uVar1 = FUN_40b51000(param_1,3);
    if ((char)param_1[5] == '\0') {
      if (param_1[2] < 4) {
        FUN_40b510b4(param_1,3);
      }
      else {
        param_1[2] = param_1[2] - 3;
      }
    }
    if (uVar1 == 1) {
      FUN_40b5116c(param_1,4);
      uVar1 = FUN_40b5116c(param_1,1);
      if (uVar1 != 0) {
        FUN_40b5116c(param_1,1);
        uVar1 = FUN_40b5116c(param_1,2);
        FUN_40b5116c(param_1,1);
        if (uVar1 == 2) {
          uVar1 = FUN_40b5116c(param_1,4);
          uVar3 = 7;
        }
        else {
          uVar1 = FUN_40b5116c(param_1,6);
          uVar3 = 1;
        }
        FUN_40b5116c(param_1,uVar3);
        uVar3 = FUN_40b5116c(param_1,2);
        if ((uVar3 == 1) && (uVar1 != 0)) {
          uVar3 = 0;
          do {
            if ((char)param_1[5] == '\0') {
              if (param_1[2] < 2) {
                FUN_40b510b4(param_1,1);
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
            FUN_40b510b4(param_1,8);
          }
          else {
            param_1[2] = param_1[2] - 8;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 0xd) {
            FUN_40b510b4(param_1,0xc);
          }
          else {
            param_1[2] = param_1[2] - 0xc;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 9) {
            FUN_40b510b4(param_1,8);
          }
          else {
            param_1[2] = param_1[2] - 8;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 0xd) {
            FUN_40b510b4(param_1,0xc);
          }
          else {
            param_1[2] = param_1[2] - 0xc;
          }
        }
        uVar1 = FUN_40b51000(param_1,3);
        if (uVar1 == 6) {
          if ((char)param_1[5] == '\0') {
            if (param_1[2] < 4) {
              FUN_40b510b4(param_1,3);
            }
            else {
              param_1[2] = param_1[2] - 3;
            }
          }
          uVar1 = FUN_40b5116c(param_1,4);
          if (uVar1 == 0xf) {
            uVar1 = FUN_40b5116c(param_1,8);
            uVar1 = uVar1 + 0xe;
          }
          if ((uVar1 != 0) && ((uVar1 = FUN_40b51000(param_1,4), uVar1 == 0xd || (uVar1 == 0xe)))) {
            *param_2 = 1;
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b52cd4 FUN_40b52cd4 */

/* Boundary evidence: original MIPS .pdata 40b52cd4..40b52fb3. Semantic name remains unreviewed. */

undefined4
FUN_40b52cd4(char *param_1,int param_2,undefined4 *param_3,int *param_4,int param_5,int param_6)

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
        FUN_40b511f0(auStack_50,param_1,param_5 - iVar5);
        if (local_3c == '\0') {
          if (local_48 < 0xd) {
            FUN_40b510b4(auStack_50,0xc);
          }
          else {
            local_48 = local_48 - 0xc;
          }
        }
        iVar1 = FUN_40b52680(auStack_50,auStack_58,local_6c,local_6c + 1,local_6c + 2);
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
LAB_40b52e60:
        if (param_4 != (int *)0x0) {
          _Memory = realloc(_Memory,iVar6 + 4);
          *(int *)(iVar6 + (int)_Memory) = local_70 + param_6;
          local_78 = _Memory;
        }
        local_80 = local_80 + 1;
        iVar6 = iVar6 + 4;
      }
      else if (iVar3 == 0) goto LAB_40b52e60;
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
      iVar3 = *(int *)(&DAT_40b6b114 + local_6c[0] * 4);
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



/* 40b52fb4 FUN_40b52fb4 */

/* Boundary evidence: original MIPS .pdata 40b52fb4..40b5320f. Semantic name remains unreviewed. */

undefined4
FUN_40b52fb4(char *param_1,short *param_2,undefined4 *param_3,int *param_4,uint param_5,int *param_6
            )

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  undefined4 uStack_38;
  char local_34 [4];
  char local_30 [4];
  uint local_2c;
  
  local_2c = DAT_40b6bf1c;
  memset(param_2,0,0x12);
  *param_6 = 0;
  pcVar6 = "ID3";
  pcVar5 = param_1;
  do {
    cVar1 = *pcVar5;
    cVar2 = *pcVar6;
    if (cVar1 == '\0') break;
    if (cVar1 != cVar2) goto LAB_40b530a8;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (pcVar5 != param_1 + 3);
  if (cVar1 == cVar2) {
    uVar7 = (((uint)(byte)param_1[6] << 7 | (uint)(byte)param_1[7]) << 7 | (uint)(byte)param_1[8])
            << 7 | (uint)(byte)param_1[9];
    if ((int)uVar7 <= (int)param_5) {
      param_1 = param_1 + uVar7;
      param_5 = param_5 - uVar7;
      goto LAB_40b530a8;
    }
LAB_40b53088:
    FUN_40b64a98(local_2c);
    uVar3 = 1;
  }
  else {
LAB_40b530a8:
    strncpy_s(local_34,5,param_1,4);
    pcVar5 = local_34;
    local_30[0] = '\0';
    pcVar6 = "ADIF";
    do {
      cVar1 = *pcVar5;
      cVar2 = *pcVar6;
      if (cVar1 == '\0') break;
      if (cVar1 != cVar2) goto LAB_40b53118;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (pcVar5 != local_30);
    if (cVar1 == cVar2) {
      FUN_40b52494(param_1,(int)param_2,param_5);
    }
    else {
LAB_40b53118:
      iVar8 = 0;
      if (0 < (int)(param_5 - 300)) {
        do {
          if ((param_1[iVar8] == -1) && ((param_1[iVar8 + 1] & 0xf6U) == 0xf0)) {
            iVar4 = FUN_40b52cd4(param_1 + iVar8,(int)param_2,param_3,param_4,param_5 - iVar8,iVar8)
            ;
            if (iVar4 != 0) {
              *param_6 = iVar8;
              goto LAB_40b531a8;
            }
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(param_5 - 300));
      }
      iVar8 = FUN_40b525b0(param_1,(undefined1 *)param_2,param_5,&uStack_38);
      if (iVar8 != 0) goto LAB_40b53088;
      if (*param_2 != 0x32ff) {
        *(undefined1 *)param_2 = 0xff;
        *(undefined1 *)((int)param_2 + 1) = 0;
      }
    }
LAB_40b531a8:
    FUN_40b64a98(local_2c);
    uVar3 = 0;
  }
  return uVar3;
}



/* 40b53210 FUN_40b53210 */

/* Boundary evidence: original MIPS .pdata 40b53210..40b532db. Semantic name remains unreviewed. */

void FUN_40b53210(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

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
  
  local_10 = DAT_40b6bf1c;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(local_210,param_1,(wchar_t *)&local_res4,param_4);
  pwVar3 = L"PASSTHRU: ";
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
  FUN_40b64a98(local_10);
  return;
}



/* 40b532dc FUN_40b532dc */

/* Boundary evidence: original MIPS .pdata 40b532dc..40b532f7. Semantic name remains unreviewed. */

void FUN_40b532dc(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  return;
}



/* 40b532f8 FUN_40b532f8 */

/* Boundary evidence: original MIPS .pdata 40b532f8..40b5334f. Semantic name remains unreviewed. */

void FUN_40b532f8(int param_1)

{
  HANDLE hHandle;
  
  hHandle = (HANDLE)InterlockedExchange((LONG *)(param_1 + 0x14),0);
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  return;
}



/* 40b53350 FUN_40b53350 */

/* Boundary evidence: original MIPS .pdata 40b53350..40b53397. Semantic name remains unreviewed. */

undefined4 * FUN_40b53350(undefined4 *param_1)

{
  FUN_40b5ec40((int)param_1);
  *param_1 = &PTR_FUN_40b66084;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 2;
  return param_1;
}



/* 40b53398 FUN_40b53398 */

/* Boundary evidence: original MIPS .pdata 40b53398..40b53497. Semantic name remains unreviewed. */

int FUN_40b53398(LPVOID param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if ((*(int **)((int)param_1 + 0x44) == (int *)0x0) || (*(int *)((int)param_1 + 0x40) == 0)) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7fff0001;
  }
  if (*(int *)((int)param_1 + 0x14) == 0) {
    iVar2 = (**(code **)(**(int **)((int)param_1 + 0x44) + 0x14))();
    if (iVar2 < 0) {
      LeaveCriticalSection(lpCriticalSection);
      return iVar2;
    }
    bVar1 = FUN_40b5ed2c(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      LeaveCriticalSection(lpCriticalSection);
      return -0x7fffbffb;
    }
  }
  *(undefined4 *)((int)param_1 + 0x48) = 1;
  iVar2 = FUN_40b5ede0((int)param_1,1);
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40b53498 FUN_40b53498 */

/* Boundary evidence: original MIPS .pdata 40b53498..40b534c7. Semantic name remains unreviewed. */

void FUN_40b53498(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b534c8 FUN_40b534c8 */

/* Boundary evidence: original MIPS .pdata 40b534c8..40b535bb. Semantic name remains unreviewed. */

int FUN_40b534c8(int param_1)

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
      *(undefined4 *)(param_1 + 0x48) = 0;
      iVar1 = FUN_40b5ede0(param_1,0);
      (**(code **)(**(int **)(param_1 + 0x40) + 0x28))();
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar1;
}



/* 40b535bc FUN_40b535bc */

/* Boundary evidence: original MIPS .pdata 40b535bc..40b535eb. Semantic name remains unreviewed. */

void FUN_40b535bc(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b535ec FUN_40b535ec */

/* Boundary evidence: original MIPS .pdata 40b535ec..40b536ff. Semantic name remains unreviewed. */

int FUN_40b535ec(int param_1)

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
      *(undefined4 *)(param_1 + 0x48) = 2;
      FUN_40b5ede0(param_1,2);
      (**(code **)(**(int **)(param_1 + 0x40) + 0x28))();
      FUN_40b532f8(param_1);
      if (*(int **)(param_1 + 0x44) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
      }
      LeaveCriticalSection(lpCriticalSection);
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40b53700 FUN_40b53700 */

/* Boundary evidence: original MIPS .pdata 40b53700..40b5372f. Semantic name remains unreviewed. */

void FUN_40b53700(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b53730 FUN_40b53730 */

/* Boundary evidence: original MIPS .pdata 40b53730..40b5379b. Semantic name remains unreviewed. */

void FUN_40b53730(int *param_1)

{
  int iVar1;
  undefined4 auStack_10 [2];
  
  do {
    iVar1 = FUN_40b5eea4((int)param_1,auStack_10);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = (**(code **)(*param_1 + 8))(param_1,param_1[0x10]);
  } while (iVar1 == 0);
  if (iVar1 == 2) {
    (**(code **)(*param_1 + 0xc))(param_1);
  }
  return;
}



/* 40b5379c FUN_40b5379c */

/* Boundary evidence: original MIPS .pdata 40b5379c..40b5383b. Semantic name remains unreviewed. */

undefined4 FUN_40b5379c(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  FUN_40b535ec(param_1);
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x40) + 8))();
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int **)(param_1 + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x44) + 8))();
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return 0;
}



/* 40b5383c FUN_40b5383c */

/* Boundary evidence: original MIPS .pdata 40b5383c..40b5386b. Semantic name remains unreviewed. */

void FUN_40b5383c(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b5386c FUN_40b5386c */

/* Boundary evidence: original MIPS .pdata 40b5386c..40b53887. Semantic name remains unreviewed. */

void FUN_40b5386c(LPVOID param_1)

{
  FUN_40b53398(param_1);
  return;
}



/* 40b53888 FUN_40b53888 */

/* Boundary evidence: original MIPS .pdata 40b53888..40b538a7. Semantic name remains unreviewed. */

undefined4 FUN_40b53888(int param_1)

{
  FUN_40b535ec(param_1);
  return 0;
}



/* 40b538a8 FUN_40b538a8 */

/* Boundary evidence: original MIPS .pdata 40b538a8..40b53943. Semantic name remains unreviewed. */

bool FUN_40b538a8(int *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  iVar1 = param_1[0x12];
  if (iVar1 == 1) {
    (**(code **)(*param_1 + 0x14))(param_1);
    FUN_40b534c8((int)param_1);
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar1 == 1;
}



/* 40b53944 FUN_40b53944 */

/* Boundary evidence: original MIPS .pdata 40b53944..40b53973. Semantic name remains unreviewed. */

void FUN_40b53944(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b53974 FUN_40b53974 */

/* Boundary evidence: original MIPS .pdata 40b53974..40b53a0f. Semantic name remains unreviewed. */

bool FUN_40b53974(int *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  iVar1 = param_1[0x12];
  if (iVar1 == 1) {
    (**(code **)(*param_1 + 0x14))(param_1);
    FUN_40b534c8((int)param_1);
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar1 == 1;
}



/* 40b53a10 FUN_40b53a10 */

/* Boundary evidence: original MIPS .pdata 40b53a10..40b53a3f. Semantic name remains unreviewed. */

void FUN_40b53a10(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b53a40 FUN_40b53a40 */

/* Boundary evidence: original MIPS .pdata 40b53a40..40b53b0b. Semantic name remains unreviewed. */

undefined4 FUN_40b53a40(int *param_1)

{
  int iVar1;
  
  do {
    iVar1 = FUN_40b5ee6c((int)param_1);
    if (iVar1 == 0) {
      FUN_40b5ef08((int)param_1,0);
    }
    else if (iVar1 == 1) {
      FUN_40b5ef08((int)param_1,0);
      FUN_40b53730(param_1);
    }
    else if (iVar1 == 2) {
      FUN_40b5ef08((int)param_1,0);
      return 0;
    }
    if ((int *)param_1[0x10] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x10] + 0x24))();
      (**(code **)(*(int *)param_1[0x10] + 0x28))();
    }
  } while( true );
}



/* 40b53b0c FUN_40b53b0c */

/* Boundary evidence: original MIPS .pdata 40b53b0c..40b53b63. Semantic name remains unreviewed. */

void FUN_40b53b0c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40b66084;
  FUN_40b5379c((int)param_1);
  FUN_40b5ecbc((int)param_1);
  return;
}



/* 40b53b64 FUN_40b53b64 */

/* Boundary evidence: original MIPS .pdata 40b53b64..40b53b93. Semantic name remains unreviewed. */

void FUN_40b53b64(void)

{
  int *in_v0;
  
  FUN_40b5ecbc(*in_v0);
  return;
}



/* 40b53b94 FUN_40b53b94 */

/* Boundary evidence: original MIPS .pdata 40b53b94..40b53cf3. Semantic name remains unreviewed. */

int FUN_40b53b94(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar3;
  LPCRITICAL_SECTION p_Var4;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x18);
  p_Var4 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  piVar3 = (int *)(param_1 + 0x40);
  if (*piVar3 != 0) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7ffbfdfc;
  }
  iVar1 = (**(code **)*param_2)(param_2,&DAT_40b68e28,piVar3);
  if (-1 < iVar1) {
    local_28 = 3;
    piVar2 = (int *)*piVar3;
    local_24 = 0x20000;
    local_20 = 0;
    local_1c = 0;
    if ((piVar2 != (int *)0x0) &&
       (iVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,0,&local_28,param_1 + 0x44,p_Var4), iVar1 < 0))
    {
      FUN_40b5379c(param_1);
      LeaveCriticalSection(lpCriticalSection);
      return iVar1;
    }
    iVar1 = (**(code **)(*(int *)*piVar3 + 0x20))((int *)*piVar3,auStack_30,auStack_38);
    if (iVar1 < 0) {
      FUN_40b5379c(param_1);
      LeaveCriticalSection(lpCriticalSection);
      return iVar1;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b53cf4 FUN_40b53cf4 */

/* Boundary evidence: original MIPS .pdata 40b53cf4..40b53d23. Semantic name remains unreviewed. */

void FUN_40b53cf4(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x40));
  return;
}



/* 40b53d24 FUN_40b53d24 */

/* Boundary evidence: original MIPS .pdata 40b53d24..40b53d6f. Semantic name remains unreviewed. */

undefined4 * FUN_40b53d24(undefined4 *param_1,uint param_2)

{
  FUN_40b53b0c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b53d70 FUN_40b53d70 */

/* Boundary evidence: original MIPS .pdata 40b53d70..40b53fc7. Semantic name remains unreviewed. */

undefined4 FUN_40b53d70(char *param_1,int param_2,undefined4 param_3,va_list param_4)

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
LAB_40b53e24:
    *(undefined4 *)(param_2 + 4) = uVar3;
  }
  else if (bVar4 == 1) {
    *(undefined4 *)(param_2 + 4) = 0xac44;
  }
  else if (bVar4 == 2) {
    uVar3 = 32000;
    goto LAB_40b53e24;
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
    goto LAB_40b53f3c;
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
LAB_40b53f3c:
    bVar4 = bVar4 & 1;
    break;
  default:
    FUN_40b53210(0x40b666f8,param_2,param_3,param_4);
    goto LAB_40b53f5c;
  }
  if (bVar4 != 0) {
    local_18 = local_18 + 1;
  }
LAB_40b53f5c:
  iVar5 = *(int *)(uVar6 * 4 + 0x40b6b30c) * 1000;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 7;
  }
  *(char *)(param_2 + 2) = (char)(local_18 & 0xffff);
  *(int *)(param_2 + 8) = iVar5 >> 3;
  *(char *)(param_2 + 3) = (char)((local_18 & 0xffff) >> 8);
  return 1;
}



/* 40b53fc8 FUN_40b53fc8 */

int FUN_40b53fc8(int param_1,int param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = param_2 - 4;
  puVar1 = (undefined1 *)(param_1 + 4);
  while( true ) {
    if (uVar2 < 5) {
      return param_2;
    }
    if (CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3]) == 0x1b6) break;
    uVar2 = uVar2 - 1;
    puVar1 = puVar1 + 1;
  }
  return param_2 - uVar2;
}



/* 40b54034 FUN_40b54034 */

/* Boundary evidence: original MIPS .pdata 40b54034..40b540db. Semantic name remains unreviewed. */

undefined4 * FUN_40b54034(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80040216;
  }
  else {
    param_1[0xd] = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    uVar1 = (**(code **)(*(int *)param_1[0xd] + 0x20))
                      ((int *)param_1[0xd],param_1 + 0xe,param_1 + 0x10);
  }
  *param_3 = uVar1;
  return param_1;
}



/* 40b540dc FUN_40b540dc */

/* Boundary evidence: original MIPS .pdata 40b540dc..40b54123. Semantic name remains unreviewed. */

void FUN_40b540dc(int param_1)

{
  if (*(int **)(param_1 + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x34) + 8))();
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  FUN_40b5e310();
  return;
}



/* 40b54124 FUN_40b54124 */

/* Boundary evidence: original MIPS .pdata 40b54124..40b542f3. Semantic name remains unreviewed. */

undefined4 FUN_40b54124(int param_1,void *param_2,uint *param_3,uint *param_4,int *param_5)

{
  undefined1 uVar1;
  int iVar2;
  undefined3 extraout_var;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  
  uVar8 = 1;
  iVar2 = memcmp(param_2,&DAT_40b683c8,0x10);
  if (iVar2 == 0) {
    uVar1 = FUN_40b5e300();
    if (CONCAT31(extraout_var,uVar1) == 0) {
      iVar9 = *param_5;
      iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x1c))();
      if (iVar2 == 0) {
        pcVar3 = FUN_40b5e188(param_5,*param_4);
        uVar5 = *param_3;
        uVar4 = *param_5 - iVar9;
        *param_3 = uVar4 + uVar5;
        param_3[1] = ((int)uVar4 >> 0x1f) + param_3[1] + (uint)(uVar4 + uVar5 < uVar4);
        *param_4 = (uint)pcVar3;
        return 0;
      }
    }
    else {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x1c))();
      if (iVar2 == 0) {
        uVar5 = *(uint *)*param_5;
        uVar4 = *param_3;
        uVar7 = uVar4 + 4;
        uVar6 = param_3[1] + (uint)(uVar7 < uVar4);
        param_3[1] = uVar6;
        *param_3 = uVar7;
        *param_3 = uVar4 + 8;
        param_3[1] = uVar6 + (uVar4 + 8 < uVar7);
        iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x1c))();
        if (iVar2 == 0) {
          *param_4 = uVar5 & 0xfffffff;
          return 0;
        }
      }
    }
    uVar8 = 0x80004005;
  }
  return uVar8;
}



/* 40b542f4 FUN_40b542f4 */

/* Boundary evidence: original MIPS .pdata 40b542f4..40b54523. Semantic name remains unreviewed. */

uint FUN_40b542f4(uint *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  int local_24;
  
  local_30 = param_1[0xe];
  local_2c = param_1[0xf];
  local_38 = param_1[0x10];
  local_34 = param_1[0x11];
  uVar5 = *param_1;
  uVar7 = param_1[1];
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    iVar2 = (**(code **)(*(int *)param_1[0xd] + 0x20))((int *)param_1[0xd],&local_30,&local_38);
    if (-1 < iVar2) {
      bVar1 = local_30 < uVar5;
      local_30 = local_30 - uVar5;
      local_2c = (local_2c - uVar7) - (uint)bVar1;
      bVar1 = local_38 < uVar5;
      local_38 = local_38 - uVar5;
      local_34 = (local_34 - uVar7) - (uint)bVar1;
      if (((0 < (int)local_2c) || ((uVar5 = local_30, local_2c == 0 && (param_3 <= local_30)))) &&
         ((uVar5 = param_3, (int)local_34 < 1 &&
          (((local_34 != 0 || (local_38 < param_3)) &&
           ((0 < (int)local_34 || ((uVar5 = 0x20000, local_34 == 0 && (0x1ffff < local_38))))))))))
      {
        uVar5 = local_38;
      }
      pvVar3 = operator_new(uVar5);
      if (pvVar3 != (void *)0x0) {
        uVar7 = 0;
        while( true ) {
          if (((int)local_34 < 1) && ((local_34 != 0 || (local_38 < uVar5)))) {
            local_24 = local_34;
            uVar6 = local_38;
          }
          else {
            local_24 = 0;
            uVar6 = uVar5;
          }
          iVar2 = (**(code **)(*(int *)param_1[0xd] + 0x1c))();
          if (iVar2 != 0) break;
          uVar4 = *param_1;
          uVar7 = uVar6 + uVar7;
          *param_1 = uVar6 + uVar4;
          param_1[1] = param_1[1] + (uint)(uVar6 + uVar4 < uVar6);
          if (uVar5 <= uVar7) {
LAB_40b544bc:
            *param_2 = pvVar3;
            return uVar7;
          }
        }
        if ((-1 < (int)local_34) && ((local_34 != 0 || (uVar7 < local_38)))) {
          operator_delete(pvVar3);
          return 0;
        }
        goto LAB_40b544bc;
      }
    }
  }
  return 0;
}



/* 40b54524 FUN_40b54524 */

/* Boundary evidence: original MIPS .pdata 40b54524..40b545c3. Semantic name remains unreviewed. */

undefined4 FUN_40b54524(undefined4 param_1,char *param_2,uint param_3,short *param_4,int *param_5)

{
  int iVar1;
  int local_10 [2];
  
  if (3 < param_3) {
    local_10[1] = 0;
    local_10[0] = 0;
    iVar1 = FUN_40b52fb4(param_2,param_4,local_10 + 1,local_10,param_3,param_5);
    if (iVar1 == 0) {
      if (2 < (ushort)param_4[1]) {
        *(undefined1 *)(param_4 + 1) = 2;
        *(undefined1 *)((int)param_4 + 3) = 0;
      }
      return 1;
    }
  }
  return 0;
}



/* 40b545c4 FUN_40b545c4 */

/* Boundary evidence: original MIPS .pdata 40b545c4..40b54ecb. Semantic name remains unreviewed. */

undefined4 FUN_40b545c4(int param_1,char *param_2,int param_3,undefined1 *param_4)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint3 uVar7;
  undefined4 uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  char *pcVar13;
  char cVar14;
  char *pcVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  
  if (param_3 < 0x1b) {
    return 0;
  }
  if ((((*param_2 == 'O') && (param_2[1] == 'g')) && (param_2[2] == 'g')) && (param_2[3] == 'S')) {
    iVar17 = param_3 + -4;
    pcVar13 = param_2 + 4;
    if (iVar17 < 0x1c) {
      return 0;
    }
    pcVar15 = param_2 + 6;
    iVar18 = iVar17;
    while (((pcVar13[iVar18 - iVar17] != 'O' || (pcVar15[-1] != 'g')) ||
           ((*pcVar15 != 'g' || (pcVar15[1] != 'S'))))) {
      iVar18 = iVar18 + 1;
      pcVar15 = pcVar15 + 1;
      if (iVar18 < 0x1c) {
        return 0;
      }
    }
    iVar17 = 0;
    while (((((pcVar15 = pcVar13, *pcVar13 != 'v' || (pcVar13[1] != 'o')) || (pcVar13[2] != 'r')) ||
            (((pcVar13[3] != 'b' || (pcVar13[4] != 'i')) || (pcVar13[5] != 's')))) &&
           (((*pcVar13 != 'S' || (pcVar13[1] != 'p')) ||
            ((pcVar13[2] != 'e' || ((pcVar13[3] != 'e' || (pcVar13[4] != 'x'))))))))) {
      pcVar15 = pcVar13 + 1;
      if (((*pcVar15 == 'v') &&
          ((((pcVar13[2] == 'o' && (pcVar13[3] == 'r')) && (pcVar13[4] == 'b')) &&
           ((pcVar13[5] == 'i' && (pcVar13[6] == 's')))))) ||
         ((((*pcVar15 == 'S' && ((pcVar13[2] == 'p' && (pcVar13[3] == 'e')))) && (pcVar13[4] == 'e')
           ) && (pcVar13[5] == 'x')))) break;
      pcVar15 = pcVar13 + 2;
      if (((((*pcVar15 == 'v') && (pcVar13[3] == 'o')) && (pcVar13[4] == 'r')) &&
          (((pcVar13[5] == 'b' && (pcVar13[6] == 'i')) && (pcVar13[7] == 's')))) ||
         (((*pcVar15 == 'S' && (pcVar13[3] == 'p')) &&
          ((pcVar13[4] == 'e' && ((pcVar13[5] == 'e' && (pcVar13[6] == 'x')))))))) break;
      pcVar15 = pcVar13 + 3;
      if (((*pcVar15 == 'v') &&
          ((((pcVar13[4] == 'o' && (pcVar13[5] == 'r')) && (pcVar13[6] == 'b')) &&
           ((pcVar13[7] == 'i' && (pcVar13[8] == 's')))))) ||
         (((*pcVar15 == 'S' && ((pcVar13[4] == 'p' && (pcVar13[5] == 'e')))) &&
          ((pcVar13[6] == 'e' && (pcVar13[7] == 'x')))))) break;
      pcVar15 = pcVar13 + 4;
      if ((((((*pcVar15 == 'v') && (pcVar13[5] == 'o')) && (pcVar13[6] == 'r')) &&
           ((pcVar13[7] == 'b' && (pcVar13[8] == 'i')))) && (pcVar13[9] == 's')) ||
         (((*pcVar15 == 'S' && (pcVar13[5] == 'p')) &&
          ((pcVar13[6] == 'e' && ((pcVar13[7] == 'e' && (pcVar13[8] == 'x')))))))) break;
      iVar17 = iVar17 + 5;
      pcVar13 = pcVar13 + 5;
      pcVar15 = pcVar13;
      if (199 < iVar17) break;
    }
    if ((((*pcVar15 == 'v') && (pcVar15[1] == 'o')) && (pcVar15[2] == 'r')) &&
       (((pcVar15[3] == 'b' && (pcVar15[4] == 'i')) && (pcVar15[5] == 's')))) {
      cVar14 = '\0';
      for (iVar17 = 0; cVar1 = pcVar15[iVar17 + 10], 0 < iVar17; iVar17 = iVar17 + -1) {
        cVar14 = cVar1;
      }
      iVar17 = 3;
      uVar16 = 0;
      for (iVar18 = 3; uVar16 = (uint)(byte)pcVar15[iVar18 + 0xb] | uVar16 << 8, 0 < iVar18;
          iVar18 = iVar18 + -1) {
      }
      uVar10 = 0;
      for (; uVar10 = (uint)(byte)pcVar15[iVar17 + 0x13] | uVar10 << 8, 0 < iVar17;
          iVar17 = iVar17 + -1) {
      }
      *(uint *)(param_4 + 8) = uVar10 << 3;
      param_4[3] = cVar14;
      param_4[2] = cVar1;
      *param_4 = 0x4f;
      *(uint *)(param_4 + 4) = uVar16;
      param_4[0xe] = 0x10;
      param_4[0xf] = 0;
      param_4[1] = 0x67;
      return 2;
    }
    if (((*pcVar15 == 'S') && (pcVar15[1] == 'p')) &&
       ((pcVar15[2] == 'e' && ((pcVar15[3] == 'e' && (pcVar15[4] == 'x')))))) {
      iVar17 = 3;
      uVar16 = 0;
      for (iVar18 = 3; uVar16 = (uint)(byte)pcVar15[iVar18 + 0x24] | uVar16 << 8, 0 < iVar18;
          iVar18 = iVar18 + -1) {
      }
      uVar10 = 0;
      for (iVar18 = 3; uVar10 = (uint)(byte)pcVar15[iVar18 + 0x28] | uVar10 << 8, 0 < iVar18;
          iVar18 = iVar18 + -1) {
      }
      cVar14 = '\0';
      for (iVar18 = 3; cVar1 = pcVar15[iVar18 + 0x30], 0 < iVar18; iVar18 = iVar18 + -1) {
        cVar14 = cVar1;
      }
      uVar11 = 0;
      for (; uVar11 = (uint)(byte)pcVar15[iVar17 + 0x34] | uVar11 << 8, 0 < iVar17;
          iVar17 = iVar17 + -1) {
      }
      if ((int)uVar11 < 0x3e9) {
        *(undefined4 *)(param_4 + 8) = 0xffffffff;
      }
      else {
        *(uint *)(param_4 + 8) = uVar11 << 3;
      }
      if ((int)uVar10 < 1) {
        uVar16 = uVar16 << (1 - uVar10 & 0x1f);
      }
      if (1 < (int)uVar10) {
        uVar16 = (int)uVar16 >> (uVar10 - 1 & 0x1f);
      }
      param_4[2] = cVar1;
      param_4[3] = cVar14;
      param_4[0xe] = 0x10;
      *param_4 = 9;
      *(uint *)(param_4 + 4) = uVar16;
      param_4[0xf] = 0;
      param_4[1] = 0xa1;
      return 4;
    }
    pcVar13 = param_2;
    while ((((*pcVar13 != 'f' || (pcVar13[1] != 'L')) || (pcVar13[2] != 'a')) || (pcVar13[3] != 'C')
           )) {
      pcVar13 = pcVar13 + 1;
      if (99 < (int)pcVar13 - (int)param_2) {
        return 0;
      }
    }
    pbVar12 = (byte *)(pcVar13 + 4);
    while( true ) {
      uVar16 = (uint)CONCAT21(CONCAT11(pbVar12[1],pbVar12[2]),pbVar12[3]);
      pbVar9 = pbVar12 + 4;
      if ((*pbVar12 & 0x7f) == 0) break;
      if ((char)*pbVar12 < '\0') {
        return 0;
      }
      iVar18 = (iVar18 + -4) - uVar16;
      pbVar12 = pbVar9 + uVar16;
      if (iVar18 < 0x33) {
        return 0;
      }
    }
  }
  else {
    pcVar13 = param_2;
    while (((*pcVar13 != 'f' || (pcVar13[1] != 'L')) || ((pcVar13[2] != 'a' || (pcVar13[3] != 'C')))
           )) {
      pcVar13 = pcVar13 + 1;
      if (99 < (int)pcVar13 - (int)param_2) {
        return 0;
      }
    }
    pbVar12 = (byte *)(pcVar13 + 4);
    while( true ) {
      uVar16 = (uint)CONCAT21(CONCAT11(pbVar12[1],pbVar12[2]),pbVar12[3]);
      pbVar9 = pbVar12 + 4;
      if ((*pbVar12 & 0x7f) == 0) break;
      if ((char)*pbVar12 < '\0') {
        return 0;
      }
      param_3 = (param_3 + -4) - uVar16;
      pbVar12 = pbVar9 + uVar16;
      if (param_3 < 0x33) {
        return 0;
      }
    }
  }
  uVar7 = CONCAT21(CONCAT11(pbVar9[10],pbVar9[0xb]),pbVar9[0xc]);
  bVar2 = pbVar9[0xd];
  bVar3 = pbVar9[0xe];
  uVar10 = (uint)(uVar7 >> 4);
  bVar4 = pbVar9[0xf];
  bVar5 = pbVar9[0x10];
  bVar6 = pbVar9[0x11];
  param_4[2] = ((byte)(uVar7 >> 1) & 7) + 1;
  param_4[3] = 0;
  uVar16 = ((((bVar2 & 0xf) << 4 | (uint)bVar3) << 8 | (uint)bVar4) << 8 | (uint)bVar5) << 8 |
           (uint)bVar6;
  *(uint *)(param_4 + 4) = uVar10;
  if (uVar16 == 0) {
    *(undefined4 *)(param_4 + 8) = 32000;
  }
  else {
    uVar8 = __ll_div(uVar16,0,uVar10,0);
    uVar8 = __ll_div(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),uVar8,0);
    *(undefined4 *)(param_4 + 8) = uVar8;
  }
  param_4[0xe] = 0x10;
  param_4[1] = 0x67;
  *param_4 = 0x4f;
  param_4[0xf] = 0;
  return 1;
}



/* 40b54ecc FUN_40b54ecc */

undefined4 FUN_40b54ecc(byte *param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &DAT_40b6b85c;
  while ((((puVar1[-3] != (uint)*param_1 || (puVar1[-2] != (uint)param_1[1])) ||
          (puVar1[-1] != (uint)param_1[2])) ||
         (((*puVar1 != (uint)param_1[3] || (puVar1[1] != (uint)param_1[4])) ||
          ((puVar1[2] != (uint)param_1[5] || (puVar1[3] != (uint)param_1[6]))))))) {
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 8;
    if (0x18 < iVar2) {
      return 0;
    }
  }
  return (&DAT_40b6b84c)[iVar2 * 8];
}



/* 40b54f7c FUN_40b54f7c */

/* Boundary evidence: original MIPS .pdata 40b54f7c..40b5546b. Semantic name remains unreviewed. */

undefined4 FUN_40b54f7c(undefined4 param_1,char *param_2,uint param_3,va_list param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  va_list pcVar5;
  byte *pbVar6;
  
  uVar2 = DAT_40b6bf1c;
  if (((((param_3 < 4) || (*param_2 != 'F')) || (param_2[1] != 'O')) ||
      ((param_2[2] != 'R' || (param_2[3] != 'M')))) || ((param_3 < 0xc || (param_2[8] != 'A'))))
  goto LAB_40b55210;
  pcVar5 = param_4;
  if (((param_2[9] == 'I') && (param_2[10] == 'F')) && (param_2[0xb] == 'C')) {
    pbVar6 = (byte *)(param_2 + 0xc);
    if (0xc < param_3) {
      do {
        if (((*pbVar6 == 0x43) && (pbVar6[1] == 0x4f)) &&
           ((pbVar6[2] == 0x4d && (pbVar6[3] == 0x4d)))) {
          param_2 = (char *)((uint)pbVar6[7] |
                            (uint)pbVar6[6] << 8 | (uint)pbVar6[5] << 0x10 | (uint)pbVar6[4] << 0x18
                            );
          if ((int)param_2 < 0x16) {
            FUN_40b53210(0x40b668e0,param_2,param_3,param_4);
          }
          else {
            bVar1 = pbVar6[8];
            param_4[2] = '\0';
            param_4[3] = bVar1;
            param_4[2] = pbVar6[9] | param_4[2];
            param_4[3] = bVar1;
            bVar1 = pbVar6[0xe];
            param_4[0xe] = '\0';
            param_4[0xf] = bVar1;
            param_4[0xe] = param_4[0xe] | pbVar6[0xf];
            param_4[0xf] = bVar1;
            iVar3 = FUN_40b54ecc(pbVar6 + 0x10);
            *(int *)(param_4 + 4) = iVar3;
            *(uint *)(param_4 + 8) =
                 (uint)*(ushort *)(param_4 + 0xe) * (uint)*(ushort *)(param_4 + 2) * iVar3 >> 3;
          }
          break;
        }
        pbVar6 = pbVar6 + 4 +
                 ((uint)CONCAT11(pbVar6[6],pbVar6[7]) |
                 (uint)pbVar6[5] << 0x10 | (uint)pbVar6[4] << 0x18) + 4;
      } while ((uint)((int)pbVar6 - (int)param_2) < param_3);
    }
    if (*(int *)(param_4 + 8) == 0) goto LAB_40b55200;
LAB_40b5522c:
    if (*(int *)(param_4 + 4) != 0) {
      *param_4 = '#';
      param_4[1] = '\x15';
      FUN_40b64a98(uVar2);
      return 1;
    }
    pwVar4 = L"IsAiffStream() bad nSamplesPerSec";
  }
  else {
    if (((param_2[9] != 'I') || (param_2[10] != 'F')) || (param_2[0xb] != 'F')) goto LAB_40b55210;
    pbVar6 = (byte *)(param_2 + 0xc);
    if (0xc < param_3) {
      do {
        if (((*pbVar6 == 0x43) && (pbVar6[1] == 0x4f)) &&
           ((pbVar6[2] == 0x4d && (pbVar6[3] == 0x4d)))) {
          if (0x11 < (int)((uint)pbVar6[7] |
                          (uint)pbVar6[6] << 8 | (uint)pbVar6[5] << 0x10 | (uint)pbVar6[4] << 0x18))
          {
            bVar1 = pbVar6[8];
            param_4[2] = '\0';
            param_4[3] = bVar1;
            param_4[2] = pbVar6[9] | param_4[2];
            param_4[3] = bVar1;
            bVar1 = pbVar6[0xe];
            param_4[0xe] = '\0';
            param_4[0xf] = bVar1;
            param_4[0xe] = param_4[0xe] | pbVar6[0xf];
            param_4[0xf] = bVar1;
            iVar3 = FUN_40b54ecc(pbVar6 + 0x10);
            *(int *)(param_4 + 4) = iVar3;
            *(uint *)(param_4 + 8) =
                 (uint)*(ushort *)(param_4 + 0xe) * (uint)*(ushort *)(param_4 + 2) * iVar3 >> 3;
          }
          break;
        }
        pbVar6 = pbVar6 + 4 +
                 ((uint)CONCAT11(pbVar6[6],pbVar6[7]) |
                 (uint)pbVar6[5] << 0x10 | (uint)pbVar6[4] << 0x18) + 4;
      } while ((uint)((int)pbVar6 - (int)param_2) < param_3);
    }
    if (*(int *)(param_4 + 8) != 0) goto LAB_40b5522c;
LAB_40b55200:
    pwVar4 = L"IsAiffStream() bad nAvgBytesPerSec";
  }
  FUN_40b53210((size_t)pwVar4,param_2,param_3,pcVar5);
LAB_40b55210:
  FUN_40b64a98(uVar2);
  return 0;
}



/* 40b5546c FUN_40b5546c */

/* Boundary evidence: original MIPS .pdata 40b5546c..40b5562f. Semantic name remains unreviewed. */

int FUN_40b5546c(undefined4 *param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  char local_18;
  char cStack_17;
  char cStack_16;
  
  uVar4 = *param_1;
  uVar6 = param_1[1];
  local_18 = (char)uVar4;
  iVar9 = 0;
  if (((local_18 == 'I') && (cStack_17 = (char)((uint)uVar4 >> 8), cStack_17 == 'D')) &&
     (cStack_16 = (char)((uint)uVar4 >> 0x10), cStack_16 == '3')) {
    bVar1 = (uVar6 & 0x1000) == 0;
    iVar9 = (((uVar6 >> 0x10 & 0x7f) * 0x80 + (uVar6 >> 0x18 & 0x7f)) * 0x80 +
            (*(byte *)(param_1 + 2) & 0x7f)) * 0x80 + (*(byte *)((int)param_1 + 9) & 0x7f);
    if (bVar1) {
      iVar9 = iVar9 + 10;
    }
    else {
      iVar9 = iVar9 + 0x14;
    }
    pcVar5 = (char *)(iVar9 + (int)param_1);
    if (bVar1) {
      cVar2 = *pcVar5;
      while (cVar2 == '\0') {
        pcVar5 = pcVar5 + 1;
        iVar9 = iVar9 + 1;
        if (param_2 < iVar9) goto LAB_40b555ec;
        cVar2 = *pcVar5;
      }
    }
  }
  uVar6 = *(uint *)(iVar9 + (int)param_1);
  iVar7 = 0;
  puVar8 = (uint *)(iVar9 + (int)param_1) + 1;
  do {
    if (uVar6 == 0x2043414d) {
LAB_40b55614:
      FUN_40b64a98(DAT_40b6bf1c);
      return iVar9;
    }
    if ((param_2 <= iVar9) || (0xfffff < iVar7)) {
      if (uVar6 != 0x2043414d) {
        iVar9 = -1;
      }
      goto LAB_40b55614;
    }
    uVar3 = *puVar8;
    iVar9 = iVar9 + 1;
    puVar8 = (uint *)((int)puVar8 + 1);
    uVar6 = (uint)(byte)uVar3 << 0x18 | uVar6 >> 8;
    iVar7 = iVar7 + 1;
    if (iVar9 < param_2) {
LAB_40b555ec:
      FUN_40b64a98(DAT_40b6bf1c);
      return -1;
    }
  } while( true );
}



/* 40b55630 FUN_40b55630 */

/* WARNING: Removing unreachable block (ram,0x40b55784) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40b55630..40b5580f. Semantic name remains unreviewed. */

undefined4 FUN_40b55630(uint *param_1,void *param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_v1;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  param_1[0x19] = (uint)&DAT_40b6bf64;
  DAT_40b6bf64 = 0;
  _DAT_40b6bf68 = 0;
  DAT_40b6bf6c = 0;
  DAT_40b6bf70 = 0;
  DAT_40b6bf74 = 0;
  DAT_40b6bf78 = 0;
  DAT_40b6bf7c = 0;
  DAT_40b6bf80 = 0;
  DAT_40b6bf84 = 0;
  DAT_40b6bf88 = 0;
  DAT_40b6bf8c = 0;
  DAT_40b6bf90 = 0;
  DAT_40b6bf94 = 0;
  memcpy((void *)param_1[0x19],param_2,0x34);
  uVar10 = param_1[0x19];
  iVar11 = *(int *)(uVar10 + 8);
  iVar5 = iVar11 + -0x34;
  puVar6 = (uint *)((int)param_2 + 0x34);
  if ((iVar5 == 0) ||
     (puVar6 = (uint *)((int)puVar6 + iVar11 + -0x34), (int)puVar6 - (int)param_2 <= param_3)) {
    uVar7 = *puVar6;
    uVar9 = (int)puVar6 + 0x17U & 3;
    iVar5 = *(int *)((va_list)((int)puVar6 + 0x17U) + -uVar9);
    uVar13 = puVar6[1];
    uVar14 = puVar6[2];
    uVar12 = puVar6[3];
    uVar2 = (uint)(puVar6 + 5) & 3;
    uVar3 = *(uint *)((int)(puVar6 + 5) - uVar2);
    if ((*(int *)(uVar10 + 0xc) == 0x18) ||
       ((int)((iVar11 - (int)param_2) + (int)puVar6) <= param_3)) {
      uVar1 = *(ushort *)(uVar10 + 4);
      uVar8 = puVar6[4] & 0xffff;
      uVar4 = puVar6[4] >> 0x10;
      param_1[1] = uVar7 & 0xffff;
      *param_1 = (uint)uVar1;
      param_1[2] = uVar7 >> 0x10;
      param_1[3] = uVar12;
      param_1[5] = uVar14;
      param_1[4] = uVar13;
      param_1[6] = uVar4;
      param_1[7] = (iVar5 << (3 - uVar9) * 8 | extraout_v1 & 0xffffffffU >> (uVar9 + 1) * 8) &
                   -1 << (4 - uVar2) * 8 | uVar3 >> uVar2 * 8;
      param_1[8] = uVar8;
      uVar8 = (int)uVar8 >> 3;
      uVar4 = uVar8 * uVar4;
      param_1[9] = uVar8;
      param_1[10] = uVar4;
      if (uVar12 == 0) {
        uVar14 = 0;
      }
      else {
        uVar14 = (uVar12 - 1) * uVar13 + uVar14;
      }
      param_1[0x10] = uVar14;
      uVar9 = 0x2c;
      if ((uVar7 & 0x200000) == 0) {
        uVar9 = *(uint *)(uVar10 + 0x14);
      }
      uVar4 = uVar4 * uVar14;
      param_1[0xb] = uVar9;
      uVar10 = *(uint *)(uVar10 + 0x20);
      param_1[0xd] = uVar10;
      param_1[0xc] = uVar4;
      param_1[0xe] = uVar4 + uVar9 + uVar10;
      return 0;
    }
    iVar5 = iVar11 + -0x18;
  }
  FUN_40b53210(0x40b6691c,iVar5,param_3,(va_list)puVar6);
  return 0xffffffff;
}



/* 40b55810 FUN_40b55810 */

/* Boundary evidence: original MIPS .pdata 40b55810..40b559cf. Semantic name remains unreviewed. */

undefined4 FUN_40b55810(int param_1,undefined4 *param_2,int param_3,undefined1 *param_4)

{
  bool bVar1;
  longlong lVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint auStack_90 [7];
  int local_74;
  undefined2 local_70;
  uint local_50;
  int local_40;
  undefined4 local_38;
  undefined4 local_28;
  uint local_20;
  
  local_20 = DAT_40b6bf1c;
  local_38 = 0;
  local_40 = FUN_40b5546c(param_2,param_3);
  if (-1 < local_40) {
    puVar4 = (undefined4 *)((int)param_2 + local_40);
    uVar5 = *puVar4;
    local_28._0_1_ = (char)uVar5;
    bVar1 = (char)local_28 == 'M';
    local_28 = uVar5;
    if ((((bVar1) &&
         (local_28._1_1_ = (char)((uint)uVar5 >> 8), bVar1 = local_28._1_1_ == 'A', bVar1)) &&
        (local_28._2_1_ = (char)((uint)uVar5 >> 0x10), bVar1 = local_28._2_1_ == 'C', bVar1)) &&
       ((local_28._3_1_ = (char)((uint)uVar5 >> 0x18), bVar1 = local_28._3_1_ == ' ', bVar1 &&
        (0xf8b < *(ushort *)(puVar4 + 1))))) {
      FUN_40b55630(auStack_90,puVar4,param_3 - local_40);
      iVar3 = __ll_div((int)((ulonglong)local_50 * 1000),
                       ((int)local_50 >> 0x1f) * 1000 + (int)((ulonglong)local_50 * 1000 >> 0x20),
                       local_74,local_74 >> 0x1f);
      if (iVar3 < 1) {
        iVar3 = 0;
      }
      else {
        lVar2 = (ulonglong)*(uint *)(param_1 + 0x38) * 8;
        iVar3 = __ll_div((int)lVar2,
                         ((int)*(uint *)(param_1 + 0x38) >> 0x1f) * 8 +
                         (int)((ulonglong)lVar2 >> 0x20),iVar3,iVar3 >> 0x1f);
      }
      param_4[2] = (char)(undefined2)auStack_90[6];
      param_4[3] = (char)((ushort)(undefined2)auStack_90[6] >> 8);
      param_4[0xe] = (char)local_70;
      param_4[0xf] = (char)((ushort)local_70 >> 8);
      *(int *)(param_4 + 4) = local_74;
      *param_4 = 1;
      *(int *)(param_4 + 8) = iVar3 * 1000 >> 3;
      param_4[1] = 0;
      FUN_40b64a98(local_20);
      return 1;
    }
  }
  FUN_40b64a98(local_20);
  return 0;
}



/* 40b559d0 FUN_40b559d0 */

/* Boundary evidence: original MIPS .pdata 40b559d0..40b55be7. Semantic name remains unreviewed. */

undefined4 FUN_40b559d0(undefined4 param_1,uint param_2,char *param_3,int param_4,int *param_5)

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
    for (; 3 < param_4; param_4 = param_4 + -1) {
      uVar2 = CONCAT11(*param_3,param_3[1]);
      param_2 = (uint)uVar2 << 0x10;
      if ((uVar2 == 0xb77) || (uVar2 == 0x770b)) break;
      param_3 = param_3 + 1;
    }
  }
  do {
    if (param_4 < 0x20) {
      return 0;
    }
    uVar5 = param_2 & 0xffff0000;
    if ((uVar5 != 0xb770000) && (uVar5 != 0x770b0000)) {
      return 0xffffffff;
    }
    if (uVar5 == 0x770b0000) {
      bVar3 = true;
LAB_40b55ab4:
      bVar1 = param_3[5];
    }
    else {
      if (bVar3) goto LAB_40b55ab4;
      bVar1 = param_3[4];
    }
    bVar4 = bVar1 >> 6;
    if ((bVar4 == 3) || (uVar5 = bVar1 & 0x3f, 0x25 < uVar5)) {
      return 0xffffffff;
    }
    if (bVar4 == 0) {
      puVar7 = &DAT_40b6b534;
LAB_40b55b28:
      piVar8 = (int *)(puVar7 + uVar5 * 0xc);
LAB_40b55b3c:
      iVar9 = *piVar8 << 1;
    }
    else {
      if (bVar4 == 1) {
        puVar7 = &DAT_40b6b530;
        goto LAB_40b55b28;
      }
      if (bVar4 == 2) {
        piVar8 = (int *)(&DAT_40b6b52c + uVar5 * 0xc);
        goto LAB_40b55b3c;
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



/* 40b55be8 FUN_40b55be8 */

/* Boundary evidence: original MIPS .pdata 40b55be8..40b56317. Semantic name remains unreviewed. */

undefined4
FUN_40b55be8(uint *param_1,byte *param_2,uint param_3,va_list param_4,uint param_5,uint param_6,
            undefined1 *param_7,int param_8)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  byte *pbVar6;
  va_list pcVar7;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  byte *local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  undefined *local_34;
  uint local_30;
  
  uVar9 = 0x10000;
  uVar13 = 0;
  uVar15 = 0;
  uVar20 = 0;
  uVar17 = 0;
  local_40 = 0;
  local_30 = 0;
  local_3c = 0;
  local_48 = (byte *)0x0;
  local_38 = 0x10000;
  local_44 = 0;
  if (param_8 == 2) {
    uVar9 = 0x80000;
    local_38 = 0x80000;
  }
  uVar16 = 1;
  if (param_3 < uVar9) {
    *param_1 = param_5;
    param_1[1] = param_6;
    uVar5 = FUN_40b542f4(param_1,&local_48,uVar9);
  }
  else {
    uVar5 = uVar9;
    if (((int)param_6 < 1) && ((param_6 != 0 || (param_5 < 100)))) {
      param_2 = param_2 + param_5;
      uVar5 = uVar9 - param_5;
    }
    param_1[1] = param_6 + (uVar9 + param_5 < uVar9);
    *param_1 = uVar9 + param_5;
    local_44 = 1;
    uVar9 = param_3;
    local_48 = param_2;
  }
  if ((local_48 == (byte *)0x0) && (uVar5 == 0)) {
    FUN_40b53210(0x40b669e8,0,uVar9,param_4);
    param_1[2] = 1;
    return 0;
  }
  pbVar6 = local_48;
  if (0x1ff < (int)uVar5) {
    local_34 = &DAT_40b66760;
    pbVar12 = local_48;
    do {
      pcVar7 = (va_list)0xffe00000;
      iVar14 = 0;
      uVar9 = param_5;
      if ((int)uVar5 < 0x1000) {
        if (local_44 == 0) {
          operator_delete(pbVar6);
        }
        local_44 = 0;
        *param_1 = param_5;
        param_1[1] = param_6;
        uVar18 = local_38;
        uVar5 = FUN_40b542f4(param_1,&local_48,local_38);
        pbVar6 = local_48;
        if (uVar5 != local_38) break;
        pbVar12 = local_48;
        if ((local_48 == (byte *)0x0) && (uVar5 == 0)) {
          FUN_40b53210(0x40b66990,0,uVar18,pcVar7);
          return 0;
        }
      }
      for (; 0x1ff < (int)uVar5; uVar5 = uVar5 - 1) {
        bVar2 = pbVar12[1];
        uVar4 = CONCAT11(*pbVar12,bVar2);
        bVar3 = pbVar12[2];
        uVar13 = CONCAT31(CONCAT21(uVar4,bVar3),pbVar12[3]);
        if ((uVar4 & 0xffe0) == 0xffe0) {
          uVar15 = 4 - (uVar4 >> 1 & 3);
          if (((((bVar2 & 0x18) != 8) && (uVar15 != 4)) && (bVar3 >> 4 != 0xf)) &&
             ((bVar3 & 0xc) != 0xc)) {
            iVar14 = 0;
            break;
          }
          iVar14 = iVar14 + 1;
        }
        param_6 = param_6 + (uVar9 + 1 < uVar9);
        pbVar12 = pbVar12 + 1;
        uVar9 = uVar9 + 1;
      }
      if (((int)param_1[9] < (int)param_6) || ((param_6 == param_1[9] && (param_1[8] < uVar9))))
      break;
      param_5 = uVar9;
      if (((uVar13 & 0xffe00000) == 0xffe00000) &&
         ((((uVar13 >> 0x13 & 3) != 1 && (uVar15 = 4 - (uVar13 >> 0x11 & 3), uVar15 != 4)) &&
          ((uVar18 = uVar13 >> 0xc & 0xf, uVar18 != 0xf && (uVar11 = uVar13 >> 10 & 3, uVar11 != 3))
          )))) {
        if (uVar18 == 0) {
          param_5 = uVar9 + 1;
          param_6 = param_6 + (param_5 < uVar9);
          pbVar12 = pbVar12 + 1;
          uVar5 = uVar5 - 1;
          uVar17 = 0;
        }
        else {
          bVar1 = (uVar13 & 0x100000) == 0;
          if (bVar1) {
            uVar10 = 1;
          }
          else {
            uVar10 = (uint)((uVar13 & 0x80000) == 0);
          }
          uVar20 = (uint)(*(ushort *)(local_34 + uVar11 * 2) >> bVar1 + uVar10);
          if (param_1[0xb] == uVar18) {
            param_1[10] = param_1[10] + 1;
          }
          else {
            param_1[0xb] = uVar18;
            param_1[10] = 0;
            if (iVar14 == 0) {
              param_1[0xc] = param_1[0xc] + 1;
            }
          }
          uVar19 = (uint)*(ushort *)
                          (local_34 + ((uVar10 * 3 + uVar15) * 0xf + uVar18 + -0xf) * 2 + 8);
          uVar11 = uVar13 >> 9 & 1;
          local_3c = uVar19 + local_3c;
          local_30 = uVar13 >> 6 & 3;
          if (uVar18 != 0) {
            if (uVar15 == 1) {
              if (uVar20 == 0) {
                trap(0x1c00);
              }
              if ((uVar20 == 0xffffffff) && (uVar19 * 12000 == 0x80000000)) {
                trap(0x1800);
              }
              local_40 = ((uVar19 * 12000) / uVar20 + uVar11) * 4;
            }
            else if (uVar15 == 2) {
              if (uVar20 == 0) {
                trap(0x1c00);
              }
              if ((uVar20 == 0xffffffff) && (uVar19 * 0x23280 == -0x80000000)) {
                trap(0x1800);
              }
              local_40 = (int)(uVar19 * 0x23280) / (int)uVar20 + uVar11;
            }
            else {
              iVar14 = uVar20 << uVar10;
              if (iVar14 == 0) {
                trap(0x1c00);
              }
              if ((iVar14 == -1) && (uVar19 * 0x23280 == -0x80000000)) {
                trap(0x1800);
              }
              local_40 = (int)(uVar19 * 0x23280) / iVar14 + uVar11;
            }
          }
          uVar17 = uVar17 + 1;
          if ((int)local_40 < (int)uVar5) {
            param_5 = local_40 + uVar9;
            pbVar12 = pbVar12 + local_40;
            param_6 = ((int)local_40 >> 0x1f) + param_6 + (uint)(param_5 < local_40);
            uVar5 = uVar5 - local_40;
            uVar13 = CONCAT31(CONCAT21(CONCAT11(*pbVar12,pbVar12[1]),pbVar12[2]),pbVar12[3]);
            if ((CONCAT11(*pbVar12,pbVar12[1]) & 0xffe0) != 0xffe0) {
              if (0x14 < (int)uVar17) break;
              local_3c = 0;
              uVar17 = 0;
            }
          }
          else {
            if (0x14 < (int)uVar17) break;
            param_5 = uVar9 + 1;
            param_6 = param_6 + (param_5 < uVar9);
            pbVar12 = pbVar12 + 1;
            uVar5 = uVar5 - 1;
          }
        }
        if (((((int)(param_1[5] + 5) < (int)uVar17) && (param_8 == 0)) ||
            ((10 < (int)uVar17 && (param_8 == 1)))) ||
           (((int)param_1[5] < (int)param_1[10] && ((int)param_1[0xc] < 5)))) break;
      }
    } while (0x1ff < (int)uVar5);
    if (uVar17 != 0) {
      if (local_30 == 3) {
        uVar8 = 1;
      }
      else {
        uVar8 = 2;
      }
      param_7[2] = uVar8;
      param_7[3] = 0;
      param_7[0xe] = 0x10;
      *(uint *)(param_7 + 4) = uVar20;
      param_7[0xf] = 0;
      uVar13 = (uint)(local_3c * 0x7d) / uVar17;
      if (uVar17 == 0) {
        trap(0x1c00);
      }
      *(uint *)(param_7 + 8) = uVar13;
      if (((uVar13 != 0) && (uVar13 << 3 < 0xafc81)) && (uVar15 < 4)) {
        *param_7 = 0x50;
        param_7[1] = 0;
        goto LAB_40b562b0;
      }
      *(undefined4 *)(param_7 + 8) = 0;
    }
  }
  uVar16 = 0;
LAB_40b562b0:
  if (param_7[2] == '\0' && param_7[3] == '\0') {
    uVar16 = 0;
  }
  if (local_44 == 0) {
    operator_delete(pbVar6);
  }
  return uVar16;
}



/* 40b56318 FUN_40b56318 */

/* Boundary evidence: original MIPS .pdata 40b56318..40b5675b. Semantic name remains unreviewed. */

undefined4
FUN_40b56318(uint *param_1,byte *param_2,uint param_3,va_list param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  undefined1 uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  int local_68 [16];
  
  if ((param_1[4] == 0) && (((int)param_1[10] <= (int)param_1[5] || (4 < (int)param_1[0xc])))) {
    param_1[10] = 0;
    param_1[0xb] = 0xffffffff;
    param_1[0xc] = 0;
    if ((undefined4 *)param_5[1] == &DAT_40b6a1d8) {
      memset(param_6,0,0x12);
      uVar7 = param_1[0xf];
      uVar8 = param_1[0xe];
      if (((int)param_1[7] < (int)uVar7) || ((uVar7 == param_1[7] && (param_1[6] <= uVar8)))) {
        iVar3 = (uVar7 - param_5[7]) - (uint)(uVar8 < (uint)param_5[6]);
        uVar7 = (uint)(iVar3 >> 3) >> 0x1c;
        uVar8 = uVar7 + (uVar8 - param_5[6]);
        iVar3 = iVar3 + (uint)(uVar8 < uVar7);
        uVar8 = iVar3 * 0x10000000 | uVar8 >> 4;
        uVar7 = 0;
        piVar5 = local_68;
        do {
          lVar2 = (ulonglong)uVar7 * (ulonglong)uVar8;
          uVar6 = (uint)lVar2;
          uVar9 = uVar6 + param_5[6];
          iVar4 = FUN_40b55be8(param_1,param_2,param_3,param_4,uVar9,
                               uVar7 * (iVar3 >> 4) + ((int)uVar7 >> 0x1f) * uVar8 +
                               (int)((ulonglong)lVar2 >> 0x20) + param_5[7] + (uint)(uVar9 < uVar6),
                               (undefined1 *)param_6,1);
          if (iVar4 == 0) {
            return 0x80040240;
          }
          uVar9 = param_1[5];
          uVar6 = param_1[10];
          *piVar5 = param_6[2];
          if (((int)uVar9 < (int)uVar6) && ((int)param_1[0xc] < 5)) break;
          uVar7 = uVar7 + 1;
          piVar5 = piVar5 + 1;
        } while ((int)uVar7 < 0x10);
      }
      else {
        iVar3 = FUN_40b55be8(param_1,param_2,param_3,param_4,param_5[6],param_5[7],
                             (undefined1 *)param_6,2);
        if (iVar3 == 0) {
          return 0x80040240;
        }
        piVar5 = local_68;
        iVar3 = param_6[2];
        do {
          *piVar5 = iVar3;
          piVar5 = piVar5 + 1;
        } while (piVar5 != (int *)&stack0xffffffd8);
      }
      param_5[8] = 0;
      uVar7 = 0;
      piVar5 = local_68;
      iVar3 = 4;
      do {
        uVar7 = piVar5[3] + piVar5[2] + piVar5[1] + uVar7 + *piVar5;
        iVar3 = iVar3 + -1;
        piVar5 = piVar5 + 4;
      } while (iVar3 != 0);
      param_5[8] = uVar7;
      param_5[8] = uVar7 >> 1;
      param_6[2] = uVar7 >> 4;
      uVar7 = param_5[8];
      *param_5 = &DAT_40b692e8;
      param_5[1] = &DAT_40b6a1d8;
      param_5[9] = uVar7;
      if (uVar7 < 32000) {
        param_5[10] = 0x200;
      }
      else if (uVar7 < 64000) {
        param_5[10] = 0x400;
      }
      else {
        param_5[10] = 0x800;
      }
      param_5[0xb] = 0x40;
      uVar8 = param_1[0xe];
      param_5[2] = uVar8;
      uVar6 = param_1[0xf];
      param_5[3] = uVar6;
      if (uVar7 != 0) {
        lVar2 = (ulonglong)(uVar8 - param_5[6]) * 8000;
        uVar10 = __ll_div((int)lVar2,
                          ((uVar6 - param_5[7]) - (uint)(uVar8 < (uint)param_5[6])) * 8000 +
                          (int)((ulonglong)lVar2 >> 0x20),uVar7,0);
        *(undefined8 *)(param_5 + 4) = uVar10;
      }
      param_5[0xc] = 0x5589f81;
      param_5[0xd] = 0x11cec356;
      param_5[0xe] = 0xaa0001bf;
      param_5[0xf] = 0x5a595500;
      param_5[0x10] = 0x12;
      param_5[0x11] = param_5 + 0x12;
      param_5[0x12] = *param_6;
      param_5[0x13] = param_6[1];
      param_5[0x14] = param_6[2];
      param_5[0x15] = param_6[3];
      uVar1 = *(undefined1 *)((int)param_6 + 0x11);
      *(undefined1 *)(param_5 + 0x16) = *(undefined1 *)(param_6 + 4);
      *(undefined1 *)((int)param_5 + 0x59) = uVar1;
      *param_1 = 0;
      param_1[1] = 0;
    }
  }
  return 0;
}



/* 40b5675c FUN_40b5675c */

/* Boundary evidence: original MIPS .pdata 40b5675c..40b56bd3. Semantic name remains unreviewed. */

undefined4
FUN_40b5675c(uint *param_1,byte *param_2,uint param_3,va_list param_4,undefined4 *param_5)

{
  char cVar1;
  char cVar2;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  undefined4 uVar12;
  char cVar3;
  
  uVar6 = 0;
  uVar8 = 0;
  uVar10 = 0;
  uVar12 = 0;
  uVar9 = 0;
  uVar7 = 4;
  pbVar11 = (byte *)0x2c;
  if ((((3 < param_3) && (*param_2 == 0x52)) && (param_2[1] == 0x49)) &&
     (((param_2[2] == 0x46 && (param_2[3] == 0x46)) && (0xc < param_3)))) {
    if (((param_2[8] == 0x57) && (param_2[9] == 0x41)) &&
       ((param_2[10] == 0x56 && (param_2[0xb] == 0x45)))) {
      pbVar4 = param_2 + 0xc;
      if ((((*pbVar4 == 0x66) && (param_2[0xd] == 0x6d)) && (param_2[0xe] == 0x74)) &&
         (param_2[0xf] == 0x20)) {
        uVar6 = (uint)*(ushort *)(param_2 + 0x14);
        uVar8 = *(undefined2 *)(param_2 + 0x16);
        uVar10 = *(undefined4 *)(param_2 + 0x18);
        uVar12 = *(undefined4 *)(param_2 + 0x1c);
        uVar7 = *(undefined2 *)(param_2 + 0x20);
        uVar9 = *(undefined2 *)(param_2 + 0x22);
        pbVar4 = param_2 + 0x24;
      }
      iVar5 = 0;
      while (((*pbVar4 != 100 || (pbVar4[1] != 0x61)) ||
             ((pbVar4[2] != 0x74 || (pbVar4[3] != 0x61))))) {
        iVar5 = iVar5 + 1;
        pbVar4 = pbVar4 + 1;
        if (0xff < iVar5) {
LAB_40b569cc:
          *param_5 = pbVar11;
          cVar2 = (char)((ushort)uVar8 >> 8);
          cVar1 = (char)((ushort)uVar9 >> 8);
          cVar3 = (char)((ushort)uVar7 >> 8);
          if (((uVar6 != 1) && (uVar6 != 2)) && ((uVar6 != 6 && ((uVar6 != 7 && (uVar6 != 0x11))))))
          {
            param_1[0xb] = 0xffffffff;
            param_1[10] = 0;
            param_1[0xc] = 0;
            iVar5 = FUN_40b55be8(param_1,param_2,param_3,param_4,0x2c,0,param_4,0);
            if (iVar5 == 1) {
              *param_4 = 'U';
              param_4[1] = '\0';
              param_4[3] = cVar2;
              param_4[2] = (char)uVar8;
              *(undefined4 *)(param_4 + 4) = uVar10;
              *(undefined4 *)(param_4 + 8) = uVar12;
              param_4[0xe] = (char)uVar9;
              param_4[0xf] = cVar1;
              param_4[0xc] = (char)uVar7;
              param_4[0xd] = cVar3;
              param_1[10] = param_1[5] << 1;
              return 1;
            }
          }
          param_4[1] = (char)(uVar6 >> 8);
          param_4[3] = cVar2;
          *param_4 = (char)uVar6;
          param_4[2] = (char)uVar8;
          *(undefined4 *)(param_4 + 4) = uVar10;
          *(undefined4 *)(param_4 + 8) = uVar12;
          param_4[0xe] = (char)uVar9;
          param_4[0xf] = cVar1;
          param_4[0xc] = (char)uVar7;
          param_4[0xd] = cVar3;
          return 1;
        }
      }
      pbVar11 = pbVar4 + (8 - (int)param_2);
      goto LAB_40b569cc;
    }
    if ((((param_2[8] == 0x52) && (param_2[9] == 0x4d)) && (param_2[10] == 0x50)) &&
       (param_2[0xb] == 0x33)) {
      param_1[0xb] = 0xffffffff;
      param_1[10] = 0;
      param_1[0xc] = 0;
      iVar5 = FUN_40b55be8(param_1,param_2,param_3,param_4,0x2c,0,param_4,0);
      if (iVar5 == 1) {
        *param_4 = 'U';
        param_4[1] = '\0';
        param_4[3] = '\0';
        param_4[2] = '\0';
        param_4[4] = '\0';
        param_4[5] = '\0';
        param_4[6] = '\0';
        param_4[7] = '\0';
        param_4[8] = '\0';
        param_4[9] = '\0';
        param_4[10] = '\0';
        param_4[0xb] = '\0';
        param_4[0xe] = '\0';
        param_4[0xf] = '\0';
        param_4[0xc] = '\x04';
        param_4[0xd] = '\0';
        param_1[10] = param_1[5] << 1;
        return 1;
      }
    }
  }
  return 0;
}



/* 40b56bd4 FUN_40b56bd4 */

/* Boundary evidence: original MIPS .pdata 40b56bd4..40b56cdf. Semantic name remains unreviewed. */

undefined4 FUN_40b56bd4(undefined4 param_1,char *param_2,va_list param_3,int param_4)

{
  char *pcVar1;
  va_list pcVar2;
  va_list pcVar3;
  char *pcVar4;
  int local_20 [2];
  
  pcVar4 = param_2 + 1;
  local_20[0] = 0;
  pcVar1 = param_2;
  pcVar2 = param_3;
  FUN_40b559d0(param_1,CONCAT31(CONCAT21(CONCAT11(*param_2,*pcVar4),param_2[2]),param_2[3]),param_2,
               (int)param_3,local_20);
  if (1 < local_20[0]) {
    pcVar3 = (va_list)0x0;
    if (param_3 != (va_list)0x1) {
      do {
        if ((((pcVar4 + (int)pcVar3)[-1] == '\v') && (pcVar4[(int)pcVar3] == 'w')) ||
           (((pcVar4 + (int)pcVar3)[-1] == 'w' && (pcVar4[(int)pcVar3] == '\v')))) {
          FUN_40b53d70(pcVar3 + (int)param_2,param_4,pcVar1,pcVar2);
          return 1;
        }
        pcVar3 = pcVar3 + 1;
      } while (pcVar3 < param_3 + -1);
    }
  }
  return 0;
}



/* 40b56ce0 FUN_40b56ce0 */

/* Boundary evidence: original MIPS .pdata 40b56ce0..40b5718f. Semantic name remains unreviewed. */

int FUN_40b56ce0(uint *param_1,byte *param_2,uint param_3,uint param_4,undefined1 *param_5,
                int param_6)

{
  wchar_t wVar1;
  wchar_t wVar2;
  longlong lVar3;
  undefined1 *puVar4;
  LSTATUS LVar5;
  int iVar6;
  int iVar7;
  LPWSTR lpValueName;
  LPDWORD lpcchValueName;
  wchar_t *pwVar8;
  uint uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  DWORD dwIndex;
  HKEY local_258;
  undefined1 *local_254;
  uint local_250;
  uint local_24c;
  uint local_248;
  DWORD local_244 [3];
  byte *local_238;
  WCHAR local_230 [256];
  uint local_30;
  
  local_30 = DAT_40b6bf1c;
  param_1[3] = 1;
  param_1[4] = 1;
  lpValueName = (LPWSTR)0x0;
  param_1[6] = 0xc00000;
  lpcchValueName = (LPDWORD)0x20019;
  local_254 = param_5;
  param_1[7] = 0;
  param_1[8] = 0xffffffff;
  param_1[9] = 0x7fffffff;
  local_24c = param_4;
  local_248 = param_3;
  local_238 = param_2;
  LVar5 = RegOpenKeyExW((HKEY)0x80000000,
                        L"CLSID\\{DC4EE099-C9EA-49c8-9FA2-0A173D1522F1}\\Pins\\Input",0,0x20019,
                        &local_258);
  if (LVar5 == 0) {
    local_244[0] = 4;
    dwIndex = 0;
    do {
      lpcchValueName = local_244 + 1;
      lpValueName = local_230;
      local_244[1] = 0x100;
      LVar5 = RegEnumValueW(local_258,dwIndex,lpValueName,lpcchValueName,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPBYTE)&local_250,local_244);
      if (LVar5 != 0) break;
      pwVar10 = local_230;
      pwVar8 = L"ForceShortVbrScan";
      do {
        wVar1 = *pwVar8;
        wVar2 = *pwVar10;
        if (wVar1 == L'\0') break;
        pwVar8 = pwVar8 + 1;
        pwVar10 = pwVar10 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        param_1[4] = local_250;
      }
      pwVar10 = local_230;
      pwVar8 = L"Mp3CbrLimit";
      do {
        wVar1 = *pwVar8;
        wVar2 = *pwVar10;
        if (wVar1 == L'\0') break;
        pwVar8 = pwVar8 + 1;
        pwVar10 = pwVar10 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        param_1[5] = local_250;
      }
      pwVar10 = local_230;
      pwVar8 = L"Mp3FullFileScanSize";
      do {
        wVar1 = *pwVar8;
        wVar2 = *pwVar10;
        if (wVar1 == L'\0') break;
        pwVar8 = pwVar8 + 1;
        pwVar10 = pwVar10 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        param_1[6] = local_250;
        param_1[7] = 0;
      }
      pwVar10 = local_230;
      pwVar8 = L"Mp3FileScanWithin";
      do {
        wVar1 = *pwVar8;
        wVar2 = *pwVar10;
        if (wVar1 == L'\0') break;
        pwVar8 = pwVar8 + 1;
        pwVar10 = pwVar10 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        param_1[8] = local_250;
        param_1[9] = 0;
      }
      pwVar10 = local_230;
      pwVar8 = L"DisablePtdemuxMp3";
      do {
        wVar1 = *pwVar8;
        wVar2 = *pwVar10;
        if (wVar1 == L'\0') break;
        pwVar8 = pwVar8 + 1;
        pwVar10 = pwVar10 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        param_1[3] = local_250;
      }
      dwIndex = dwIndex + 1;
    } while ((int)dwIndex < 0xc);
    RegCloseKey(local_258);
    param_5 = local_254;
    param_2 = local_238;
    param_4 = local_24c;
    param_3 = local_248;
  }
  puVar4 = local_254;
  if (param_1[3] == 0) {
    uVar13 = param_1[0xf];
    uVar11 = param_1[0xe];
    param_1[10] = 0;
    param_1[0xb] = 0xffffffff;
    param_1[0xc] = 0;
    if (((int)uVar13 < (int)param_1[7]) ||
       (((uVar13 == param_1[7] && (uVar11 < param_1[6])) || (param_1[4] != 0)))) {
      iVar6 = FUN_40b55be8(param_1,param_2,param_3,(va_list)lpcchValueName,param_4,0,param_5,0);
      if ((param_6 != 0) && (iVar6 == 0)) {
        iVar6 = FUN_40b55be8(param_1,param_2,param_3,(va_list)lpcchValueName,param_4,0,param_5,2);
      }
      FUN_40b64a98(local_30);
    }
    else {
      uVar9 = (uint)((int)uVar13 >> 3) >> 0x1c;
      uVar12 = uVar9 + uVar11;
      local_238 = (byte *)(uVar13 << 0x1d | uVar11 >> 3);
      iVar6 = uVar13 + (uVar12 < uVar9);
      uVar13 = 0;
      uVar11 = 0;
      uVar12 = iVar6 * 0x10000000 | uVar12 >> 4;
      uVar9 = 0;
      while( true ) {
        param_1[0xc] = 0;
        param_1[10] = 0;
        lVar3 = (ulonglong)uVar9 * (ulonglong)uVar12;
        iVar7 = FUN_40b55be8(param_1,param_2,param_3,(va_list)lpcchValueName,(uint)lVar3,
                             uVar9 * (iVar6 >> 4) + ((int)uVar9 >> 0x1f) * uVar12 +
                             (int)((ulonglong)lVar3 >> 0x20),puVar4,1);
        if (iVar7 == 0) goto LAB_40b56f74;
        uVar13 = param_1[10] + uVar13;
        param_1[10] = 0;
        if (5 < (int)param_1[0xc]) {
          uVar11 = param_1[0xc] + uVar11;
        }
        param_1[0xc] = 0;
        if ((int)param_1[5] < (int)uVar13) break;
        if ((((int)uVar13 < (int)uVar11) && (10 < (int)uVar11)) ||
           (uVar9 = uVar9 + 1, 0xf < (int)uVar9)) goto LAB_40b570dc;
      }
      param_1[10] = uVar13;
      uVar11 = 0;
LAB_40b570dc:
      param_1[10] = uVar13;
      param_1[0xc] = uVar11;
      FUN_40b64a98(local_30);
      iVar6 = 1;
    }
  }
  else {
    FUN_40b53210(0x40b66a40,param_1[3],lpValueName,(va_list)lpcchValueName);
LAB_40b56f74:
    FUN_40b64a98(local_30);
    iVar6 = 0;
  }
  return iVar6;
}



/* 40b57190 FUN_40b57190 */

/* Boundary evidence: original MIPS .pdata 40b57190..40b5805b. Semantic name remains unreviewed. */

undefined4
FUN_40b57190(uint *param_1,undefined4 *param_2,byte *param_3,va_list param_4,va_list param_5,
            int param_6)

{
  longlong lVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  va_list pcVar7;
  va_list pcVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  undefined8 uVar12;
  int local_60 [2];
  uint local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined1 local_48;
  undefined1 local_47;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  
  local_60[0] = 0;
  pcVar7 = param_4;
  memset(&local_58,0,0x12);
  uVar6 = 0x17;
  uVar4 = 0;
  memset(&local_40,0,0x17);
  if ((param_3 == (byte *)0x0) && (param_4 == (va_list)0x0)) {
    FUN_40b53210(0x40b6681c,uVar4,uVar6,pcVar7);
    return 0x80004005;
  }
  if (((*param_3 == 0x46) && (param_3[1] == 0x4c)) && (param_3[2] == 0x56)) {
    return 0x80004005;
  }
  if (param_6 == 0) {
LAB_40b57438:
    puVar9 = &local_58;
    iVar2 = FUN_40b54524(param_1,(char *)param_3,(uint)param_4,(short *)puVar9,local_60);
    if (iVar2 != 0) {
      puVar3 = malloc(0x5a);
      puVar3[1] = &DAT_40b683b8;
      *puVar3 = &DAT_40b692e8;
      puVar3[7] = 0;
      puVar3[6] = param_5 + local_60[0];
      iVar2 = local_50 << 3;
      puVar3[9] = iVar2;
      puVar3[8] = iVar2;
      puVar3[10] = 0x2000;
      puVar3[0xb] = 0x40;
      puVar3[2] = param_1[0xe];
      puVar3[3] = param_1[0xf];
      if (iVar2 == 0) {
        FUN_40b53210(0x40b66c74,0,0,(va_list)puVar9);
        return 0x80040240;
      }
LAB_40b574e8:
      lVar1 = (ulonglong)(uint)(puVar3[2] - puVar3[6]) * 8000;
      uVar12 = __ll_div((int)lVar1,
                        ((puVar3[3] - puVar3[7]) - (uint)((uint)puVar3[2] < (uint)puVar3[6])) * 8000
                        + (int)((ulonglong)lVar1 >> 0x20),iVar2,0);
      *(undefined8 *)(puVar3 + 4) = uVar12;
      puVar3[0xc] = 0x5589f81;
      puVar3[0xd] = 0x11cec356;
      puVar3[0xe] = 0xaa0001bf;
      puVar3[0xf] = 0x5a595500;
      puVar3[0x10] = 0x12;
      puVar3[0x11] = puVar3 + 0x12;
      puVar3[0x12] = local_58;
      puVar3[0x13] = local_54;
      puVar3[0x14] = local_50;
      puVar3[0x15] = local_4c;
      *(undefined1 *)(puVar3 + 0x16) = local_48;
      *(undefined1 *)((int)puVar3 + 0x59) = local_47;
      goto LAB_40b5801c;
    }
    iVar2 = FUN_40b545c4((int)param_1,(char *)param_3,(int)param_4,(undefined1 *)&local_58);
    if ((iVar2 == 1) || (iVar2 == 3)) {
      puVar3 = malloc(0x5a);
      puVar3[1] = &DAT_40b68238;
      *puVar3 = &DAT_40b692e8;
      puVar3[6] = param_5;
      puVar3[7] = 0;
      uVar10 = local_50 << 3;
      puVar3[9] = uVar10;
      puVar3[8] = uVar10;
      if (uVar10 < 32000) {
        puVar3[10] = 0x200;
      }
      else if (uVar10 < 64000) {
        puVar3[10] = 0x400;
      }
      else if (uVar10 < 0x927c1) {
        puVar3[10] = 0x800;
      }
      else {
        puVar3[10] = 0x4000;
      }
      puVar3[0xb] = 0x40;
      puVar3[2] = param_1[0xe];
      puVar3[3] = param_1[0xf];
      puVar3[0xc] = 0x5589f81;
      puVar3[0xd] = 0x11cec356;
      puVar3[0xe] = 0xaa0001bf;
      puVar3[0xf] = 0x5a595500;
      puVar3[0x10] = 0x12;
      puVar3[0x11] = puVar3 + 0x12;
      puVar3[0x12] = local_58;
      puVar3[0x13] = local_54;
      puVar3[0x14] = local_50;
      puVar3[0x15] = local_4c;
      *(undefined1 *)(puVar3 + 0x16) = local_48;
      *(undefined1 *)((int)puVar3 + 0x59) = local_47;
      if (puVar3[8] == 0) {
        puVar3[4] = 10000;
        puVar3[5] = 0;
      }
      else {
        lVar1 = (ulonglong)(uint)(puVar3[2] - puVar3[6]) * 8000;
        uVar12 = __ll_div((int)lVar1,
                          ((puVar3[3] - puVar3[7]) - (uint)((uint)puVar3[2] < (uint)puVar3[6])) *
                          8000 + (int)((ulonglong)lVar1 >> 0x20),puVar3[8],0);
        *(undefined8 *)(puVar3 + 4) = uVar12;
      }
      goto LAB_40b5801c;
    }
    if (iVar2 != 2) {
      puVar9 = &local_58;
      iVar2 = FUN_40b5675c(param_1,param_3,(uint)param_4,(va_list)puVar9,local_60);
      if (iVar2 != 0) {
        puVar3 = malloc(0x5a);
        puVar3[1] = &DAT_40b69688;
        *puVar3 = &DAT_40b692e8;
        puVar3[7] = 0;
        puVar3[6] = param_5 + local_60[0];
        puVar3[9] = local_50 << 3;
        puVar3[8] = local_50 << 3;
        uVar10 = local_58 & 0xffff;
        if (uVar10 < 0x12) {
          if ((0xf < uVar10) || (uVar10 == 2)) {
            uVar4 = 0x2000;
            goto LAB_40b57778;
          }
          if ((uVar10 < 6) || (7 < uVar10)) goto LAB_40b57774;
          puVar3[10] = 0x2000;
        }
        else {
          if (uVar10 == 0x55) {
            puVar3[1] = &DAT_40b6a1d8;
          }
LAB_40b57774:
          uVar4 = 0x8000;
LAB_40b57778:
          puVar3[10] = uVar4;
        }
        puVar3[0xb] = 0x40;
        puVar3[2] = param_1[0xe];
        iVar2 = puVar3[8];
        puVar3[3] = param_1[0xf];
        if (iVar2 == 0) {
          FUN_40b53210(0x40b66c10,0,0,(va_list)puVar9);
          return 0x80040240;
        }
        goto LAB_40b574e8;
      }
      iVar2 = FUN_40b54f7c(param_1,(char *)param_3,(uint)param_4,(va_list)&local_58);
      if (iVar2 == 0) {
        iVar2 = FUN_40b55810((int)param_1,(undefined4 *)param_3,(int)param_4,(undefined1 *)&local_58
                            );
        if (iVar2 == 0) {
          pcVar7 = (va_list)&local_40;
          iVar2 = FUN_40b56bd4(param_1,(char *)param_3,param_4,(int)pcVar7);
          if (iVar2 == 0) {
            iVar2 = FUN_40b56ce0(param_1,param_3,(uint)param_4,(uint)param_5,(undefined1 *)&local_58
                                 ,0);
            if (iVar2 == 0) {
              uVar4 = 0x80040240;
              goto LAB_40b58024;
            }
            puVar3 = malloc(0x5a);
            *puVar3 = &DAT_40b692e8;
            puVar3[1] = &DAT_40b6a1d8;
            puVar3[6] = param_5;
            puVar3[7] = 0;
            FUN_40b56318(param_1,param_3,(uint)param_4,param_5,puVar3,&local_58);
            puVar3[8] = local_50 << 3;
            puVar3[10] = 0x10000;
            puVar3[0xb] = 0x40;
            puVar3[9] = local_50 << 3;
            uVar10 = param_1[0xe];
            puVar3[2] = uVar10;
            uVar11 = param_1[0xf];
            puVar3[3] = uVar11;
            lVar1 = (ulonglong)(uVar10 - puVar3[6]) * 8000;
            uVar12 = __ll_div((int)lVar1,
                              ((uVar11 - puVar3[7]) - (uint)(uVar10 < (uint)puVar3[6])) * 8000 +
                              (int)((ulonglong)lVar1 >> 0x20),puVar3[8],0);
            *(undefined8 *)(puVar3 + 4) = uVar12;
            puVar3[0xc] = 0x5589f81;
            puVar3[0xd] = 0x11cec356;
            puVar3[0xe] = 0xaa0001bf;
            puVar3[0xf] = 0x5a595500;
            puVar3[0x10] = 0x12;
            puVar3[0x11] = puVar3 + 0x12;
            puVar3[0x12] = local_58;
            puVar3[0x13] = local_54;
            puVar3[0x14] = local_50;
            puVar3[0x15] = local_4c;
            *(undefined1 *)(puVar3 + 0x16) = local_48;
            *(undefined1 *)((int)puVar3 + 0x59) = local_47;
          }
          else {
            puVar3 = malloc(0x5f);
            puVar3[1] = &DAT_40b6a1e8;
            *puVar3 = &DAT_40b692e8;
            puVar3[6] = param_5;
            puVar3[7] = 0;
            iVar2 = local_38 << 3;
            puVar3[9] = iVar2;
            puVar3[8] = iVar2;
            puVar3[10] = 0x8000;
            puVar3[0xb] = 0x40;
            puVar3[2] = param_1[0xe];
            puVar3[3] = param_1[0xf];
            if (iVar2 == 0) {
              FUN_40b53210(0x40b66bac,0,0,pcVar7);
              return 0x80040240;
            }
            lVar1 = (ulonglong)(uint)(puVar3[2] - puVar3[6]) * 8000;
            uVar12 = __ll_div((int)lVar1,
                              ((puVar3[3] - puVar3[7]) - (uint)((uint)puVar3[2] < (uint)puVar3[6]))
                              * 8000 + (int)((ulonglong)lVar1 >> 0x20),iVar2,0);
            *(undefined8 *)(puVar3 + 4) = uVar12;
            puVar3[0xc] = 0x5589f81;
            puVar3[0xd] = 0x11cec356;
            puVar3[0xe] = 0xaa0001bf;
            puVar3[0xf] = 0x5a595500;
            puVar3[0x10] = 0x17;
            puVar3[0x11] = puVar3 + 0x12;
            puVar3[0x12] = local_40;
            puVar3[0x13] = local_3c;
            puVar3[0x14] = local_38;
            puVar3[0x15] = local_34;
            puVar3[0x16] = local_30;
            *(undefined1 *)(puVar3 + 0x17) = local_2c;
            *(undefined1 *)((int)puVar3 + 0x5d) = local_2b;
            *(undefined1 *)((int)puVar3 + 0x5e) = local_2a;
          }
        }
        else {
          puVar3 = malloc(0x5a);
          puVar3[1] = &DAT_40b68328;
          *puVar3 = &DAT_40b692e8;
          puVar3[6] = 0;
          puVar3[7] = 0;
          puVar3[8] = local_50 << 3;
          puVar3[9] = local_50 << 3;
          puVar3[10] = 0x8000;
          puVar3[0xb] = 0x40;
          puVar3[2] = param_1[0xe];
          puVar3[3] = param_1[0xf];
          iVar2 = local_50 << 3;
          local_4c = (uint)CONCAT12(0x10,(undefined2)local_4c);
          puVar3[8] = iVar2;
          if (iVar2 == 0) {
            puVar3[4] = 0;
            puVar3[5] = 0;
          }
          else {
            lVar1 = (ulonglong)(uint)(puVar3[2] - puVar3[6]) * 8000;
            uVar12 = __ll_div((int)lVar1,
                              ((puVar3[3] - puVar3[7]) - (uint)((uint)puVar3[2] < (uint)puVar3[6]))
                              * 8000 + (int)((ulonglong)lVar1 >> 0x20),iVar2,0);
            *(undefined8 *)(puVar3 + 4) = uVar12;
          }
          puVar3[0xc] = 0x5589f81;
          puVar3[0xd] = 0x11cec356;
          puVar3[0xe] = 0xaa0001bf;
          puVar3[0xf] = 0x5a595500;
          puVar3[0x10] = 0x12;
          puVar3[0x11] = puVar3 + 0x12;
          puVar3[0x12] = local_58;
          puVar3[0x13] = local_54;
          puVar3[0x14] = local_50;
          puVar3[0x15] = local_4c;
          *(undefined1 *)(puVar3 + 0x16) = local_48;
          *(undefined1 *)((int)puVar3 + 0x59) = local_47;
        }
        goto LAB_40b5801c;
      }
      puVar3 = malloc(0x5a);
      *puVar3 = &DAT_40b692e8;
      puVar3[1] = &DAT_40b696a8;
      puVar3[6] = param_5;
      puVar3[7] = 0;
      puVar3[9] = local_50 << 3;
      puVar3[8] = local_50 << 3;
      switch(local_58 & 0xffff) {
      case 2:
      case 0x10:
      case 0x11:
        puVar3[10] = 0x800;
        goto LAB_40b57880;
      default:
        uVar4 = 0x4000;
        break;
      case 6:
      case 7:
        uVar4 = 0x1000;
      }
      puVar3[10] = uVar4;
LAB_40b57880:
      puVar3[0xb] = 0x40;
      uVar10 = param_1[0xe];
      puVar3[2] = uVar10;
      uVar11 = param_1[0xf];
      puVar3[3] = uVar11;
      lVar1 = (ulonglong)(uVar10 - puVar3[6]) * 8000;
      uVar12 = __ll_div((int)lVar1,
                        ((uVar11 - puVar3[7]) - (uint)(uVar10 < (uint)puVar3[6])) * 8000 +
                        (int)((ulonglong)lVar1 >> 0x20),puVar3[8],0);
      *(undefined8 *)(puVar3 + 4) = uVar12;
      puVar3[0xc] = 0x5589f81;
      puVar3[0xd] = 0x11cec356;
      puVar3[0xe] = 0xaa0001bf;
      puVar3[0xf] = 0x5a595500;
      puVar3[0x10] = 0x12;
      puVar3[0x11] = puVar3 + 0x12;
      puVar3[0x12] = local_58;
      puVar3[0x13] = local_54;
      puVar3[0x14] = local_50;
      puVar3[0x15] = local_4c;
      *(undefined1 *)(puVar3 + 0x16) = local_48;
      *(undefined1 *)((int)puVar3 + 0x59) = local_47;
      goto LAB_40b5801c;
    }
    puVar3 = malloc(0x48);
    *puVar3 = &DAT_40b692e8;
    puVar3[1] = &DAT_40b68248;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[9] = 0;
    puVar3[8] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[0xc] = 0;
    puVar3[0xd] = 0;
    puVar3[0xe] = 0;
    puVar3[0xf] = 0;
    puVar3[0x10] = 0;
    puVar3[0x11] = 0;
    *param_2 = puVar3;
  }
  else {
    pbVar5 = param_3;
    pcVar7 = param_4;
    pcVar8 = param_5;
    iVar2 = FUN_40b56ce0(param_1,param_3,(uint)param_4,(uint)param_5,(undefined1 *)&local_58,param_6
                        );
    if (iVar2 == 0) {
      if (param_1[2] != 0) {
        FUN_40b53210(0x40b66cd8,pbVar5,pcVar7,pcVar8);
        return 0x80040240;
      }
      goto LAB_40b57438;
    }
    puVar3 = malloc(0x5a);
    *puVar3 = &DAT_40b692e8;
    puVar3[1] = &DAT_40b6a1d8;
    puVar3[6] = param_5;
    puVar3[7] = 0;
    FUN_40b56318(param_1,param_3,(uint)param_4,param_5,puVar3,&local_58);
    iVar2 = local_50 << 3;
    puVar3[9] = iVar2;
    puVar3[8] = iVar2;
    if (iVar2 == 0) {
      FUN_40b53210(0x40b66d2c,0,param_4,param_5);
      return 0x80040240;
    }
    puVar3[0xb] = 0x40;
    puVar3[10] = 0x10000;
    uVar10 = param_1[0xe];
    puVar3[2] = uVar10;
    uVar11 = param_1[0xf];
    puVar3[3] = uVar11;
    lVar1 = (ulonglong)(uVar10 - puVar3[6]) * 8000;
    uVar12 = __ll_div((int)lVar1,
                      ((uVar11 - puVar3[7]) - (uint)(uVar10 < (uint)puVar3[6])) * 8000 +
                      (int)((ulonglong)lVar1 >> 0x20),puVar3[8],0);
    *(undefined8 *)(puVar3 + 4) = uVar12;
    puVar3[0xc] = 0x5589f81;
    puVar3[0xd] = 0x11cec356;
    puVar3[0xe] = 0xaa0001bf;
    puVar3[0xf] = 0x5a595500;
    puVar3[0x10] = 0x12;
    puVar3[0x11] = puVar3 + 0x12;
    puVar3[0x12] = local_58;
    puVar3[0x13] = local_54;
    puVar3[0x14] = local_50;
    puVar3[0x15] = local_4c;
    *(undefined1 *)(puVar3 + 0x16) = local_48;
    *(undefined1 *)((int)puVar3 + 0x59) = local_47;
LAB_40b5801c:
    *param_2 = puVar3;
  }
  uVar4 = 0;
LAB_40b58024:
  param_1[1] = 0;
  *param_1 = 0;
  return uVar4;
}



/* 40b5805c FUN_40b5805c */

void FUN_40b5805c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40b66d84;
  return;
}



/* 40b5806c FUN_40b5806c */

/* Boundary evidence: original MIPS .pdata 40b5806c..40b580af. Semantic name remains unreviewed. */

undefined4 * FUN_40b5806c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40b66d84;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b580b0 FUN_40b580b0 */

/* Boundary evidence: original MIPS .pdata 40b580b0..40b580f3. Semantic name remains unreviewed. */

undefined4 * FUN_40b580b0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40b66dbc;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b58104 FUN_40b58104 */

/* Boundary evidence: original MIPS .pdata 40b58104..40b58157. Semantic name remains unreviewed. */

void FUN_40b58104(int *param_1)

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



/* 40b58158 FUN_40b58158 */

/* Boundary evidence: original MIPS .pdata 40b58158..40b5822b. Semantic name remains unreviewed. */

undefined4 * FUN_40b58158(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  va_list pcVar3;
  
  param_1[1] = param_2;
  pcVar3 = "";
  uVar2 = 1;
  uVar1 = 8;
  *param_1 = &PTR_FUN_40b66de4;
  _eh_vector_constructor_iterator_
            (param_1 + 2,8,1,(_func_void_void_ptr *)&LAB_40b580f4,FUN_40b58104);
  param_1[6] = 0xffffffff;
  param_1[7] = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0x15] = 0xffffffff;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 1;
  param_1[0x12] = 0xfffffffc;
  FUN_40b53210(0x40b66dc0,uVar1,uVar2,pcVar3);
  return param_1;
}



/* 40b5822c FUN_40b5822c */

/* Boundary evidence: original MIPS .pdata 40b5822c..40b5825b. Semantic name remains unreviewed. */

void FUN_40b5822c(void)

{
  undefined4 *in_v0;
  
  FUN_40b5805c((undefined4 *)*in_v0);
  return;
}



/* 40b5825c FUN_40b5825c */

/* Boundary evidence: original MIPS .pdata 40b5825c..40b5829f. Semantic name remains unreviewed. */

void FUN_40b5825c(void)

{
  int *in_v0;
  
  _eh_vector_destructor_iterator_((void *)(*in_v0 + 8),8,1,FUN_40b58104);
  return;
}



/* 40b582b0 FUN_40b582b0 */

/* WARNING: Removing unreachable block (ram,0x40b58310) */
/* WARNING: Removing unreachable block (ram,0x40b58320) */
/* WARNING: Removing unreachable block (ram,0x40b58328) */
/* WARNING: Removing unreachable block (ram,0x40b58330) */
/* Boundary evidence: original MIPS .pdata 40b582b0..40b5841b. Semantic name remains unreviewed. */

undefined4 FUN_40b582b0(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_40b6a448,0x10);
  if (iVar1 == 0) {
    FUN_40b59fd8(param_1);
    iVar1 = *(int *)(param_1 + 0x1c);
    if (-1 < iVar1) {
      *param_2 = *(undefined4 *)(param_1 + 0x18);
      param_2[1] = iVar1;
      if ((0 < *(int *)(param_1 + 0x1c)) ||
         ((*(int *)(param_1 + 0x1c) == 0 && (*(int *)(param_1 + 0x18) != 0)))) {
        return 0;
      }
    }
  }
  return 0x80040261;
}



/* 40b5841c FUN_40b5841c */

/* Boundary evidence: original MIPS .pdata 40b5841c..40b58537. Semantic name remains unreviewed. */

undefined4 FUN_40b5841c(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  local_18 = DAT_40b6bf1c;
  iVar4 = param_1[5];
  local_28 = 0x7b785574;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0x11cf8c82;
  local_20 = 0xaa000cbc;
  local_1c = 0xf674ac00;
  uVar3 = 0x10;
  puVar2 = &DAT_40b69688;
  iVar1 = memcmp(*(void **)(iVar4 + 4),&DAT_40b69688,0x10);
  if ((iVar1 == 0) && (**(short **)(iVar4 + 0x44) == 0x11)) {
    FUN_40b53210(0x40b66e68,puVar2,uVar3,param_4);
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1,&local_30,&local_28);
    if (-1 < iVar1) {
      if ((0 < local_2c) || ((local_2c == 0 && (local_30 != 0)))) {
        FUN_40b64a98(local_18);
        return 1;
      }
    }
  }
  FUN_40b64a98(local_18);
  return 0;
}



/* 40b58538 FUN_40b58538 */

/* Boundary evidence: original MIPS .pdata 40b58538..40b586c3. Semantic name remains unreviewed. */

undefined4 FUN_40b58538(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 extraout_v1;
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  
  uVar2 = *(uint *)(param_1 + 0x1c);
  *(uint *)(param_1 + 0x30) = param_3;
  *(uint *)(param_1 + 0x34) = param_4;
  if (((int)uVar2 < 0) || ((uVar2 == 0 && (*(uint *)(param_1 + 0x18) == 0)))) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14);
    iVar1 = FUN_40b5e798(*(uint *)(iVar1 + 8) - *(uint *)(iVar1 + 0x18),
                         (*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 0x1c)) -
                         (uint)(*(uint *)(iVar1 + 8) < *(uint *)(iVar1 + 0x18)),param_3,param_4,
                         *(uint *)(param_1 + 0x18),uVar2,0,0);
    *(int *)(param_1 + 0x28) = iVar1;
    *(undefined4 *)(param_1 + 0x2c) = extraout_v1;
  }
  iVar1 = *(int *)(param_1 + 0x54);
  if ((((iVar1 == 0x11) || (iVar1 == 1)) || (iVar1 == 2)) &&
     (iVar1 = *(int *)(param_1 + 0x50), 4 < iVar1)) {
    uVar2 = *(uint *)(param_1 + 0x28);
    iVar6 = *(int *)(param_1 + 0x2c);
    uVar7 = __ll_rem(uVar2,iVar6,iVar1,iVar1 >> 0x1f);
    iVar1 = (iVar6 - (int)((ulonglong)uVar7 >> 0x20)) - (uint)(uVar2 < (uint)uVar7);
    iVar6 = uVar2 - (uint)uVar7;
    *(int *)(param_1 + 0x28) = iVar6;
    *(int *)(param_1 + 0x2c) = iVar1;
    uVar2 = *(uint *)(*(int *)(param_1 + 0x14) + 0x18);
    iVar3 = *(int *)(*(int *)(param_1 + 0x14) + 0x1c);
    uVar5 = uVar2 + iVar6;
    *(uint *)(param_1 + 0x28) = uVar5;
    *(uint *)(param_1 + 0x2c) = iVar3 + iVar1 + (uint)(uVar5 < uVar2);
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x48) & *(uint *)(param_1 + 0x28);
    uVar2 = *(uint *)(param_1 + 0x4c) & *(uint *)(param_1 + 0x2c);
    *(uint *)(param_1 + 0x28) = uVar5;
    *(uint *)(param_1 + 0x2c) = uVar2;
    uVar4 = *(uint *)(*(int *)(param_1 + 0x14) + 0x18);
    iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x1c);
    uVar5 = uVar4 + uVar5;
    *(uint *)(param_1 + 0x28) = uVar5;
    *(uint *)(param_1 + 0x2c) = iVar1 + uVar2 + (uint)(uVar5 < uVar4);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  return 0;
}



/* 40b586c4 FUN_40b586c4 */

/* Boundary evidence: original MIPS .pdata 40b586c4..40b586f7. Semantic name remains unreviewed. */

undefined4 FUN_40b586c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = __dptoli(param_3,param_4);
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  return 0;
}



/* 40b586f8 FUN_40b586f8 */

/* Boundary evidence: original MIPS .pdata 40b586f8..40b5875b. Semantic name remains unreviewed. */

undefined4 FUN_40b586f8(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
  *param_2 = iVar1 + iVar2;
  return 0;
}



/* 40b5875c FUN_40b5875c */

/* Boundary evidence: original MIPS .pdata 40b5875c..40b58807. Semantic name remains unreviewed. */

undefined4 FUN_40b5875c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
  if (iVar1 + iVar2 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
    if (param_2 < iVar1 + iVar2) {
      return 0x80004001;
    }
  }
  return 0x80070057;
}



/* 40b58808 FUN_40b58808 */

/* Boundary evidence: original MIPS .pdata 40b58808..40b58893. Semantic name remains unreviewed. */

bool FUN_40b58808(int param_1,int *param_2,int *param_3,va_list param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  *param_2 = *(int *)(*(int *)(param_1 + 0x14) + 0x28);
  *param_3 = *(int *)(*(int *)(param_1 + 0x14) + 0x2c);
  iVar4 = *param_2;
  piVar1 = param_2;
  piVar2 = param_3;
  if (iVar4 == 0) {
    FUN_40b53210(0x40b66f90,param_2,param_3,param_4);
    *param_2 = 0x8000;
  }
  iVar3 = *param_3;
  if (iVar3 == 0) {
    FUN_40b53210(0x40b66f0c,piVar1,piVar2,param_4);
    *param_3 = 0x40;
  }
  return iVar3 == 0 || iVar4 == 0;
}



/* 40b58894 FUN_40b58894 */

/* Boundary evidence: original MIPS .pdata 40b58894..40b5893f. Semantic name remains unreviewed. */

void FUN_40b58894(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &PTR_FUN_40b66de4;
  if ((void *)param_1[5] != (void *)0x0) {
    free((void *)param_1[5]);
    param_1[5] = 0;
  }
  pvVar1 = (void *)param_1[4];
  if (pvVar1 != (void *)0x0) {
    FUN_40b540dc((int)pvVar1);
    operator_delete(pvVar1);
    param_1[4] = 0;
  }
  _eh_vector_destructor_iterator_(param_1 + 2,8,1,FUN_40b58104);
  *param_1 = &PTR_FUN_40b66d84;
  return;
}



/* 40b58940 FUN_40b58940 */

/* Boundary evidence: original MIPS .pdata 40b58940..40b5896f. Semantic name remains unreviewed. */

void FUN_40b58940(void)

{
  undefined4 *in_v0;
  
  FUN_40b5805c((undefined4 *)*in_v0);
  return;
}



/* 40b58970 FUN_40b58970 */

/* Boundary evidence: original MIPS .pdata 40b58970..40b589b3. Semantic name remains unreviewed. */

void FUN_40b58970(void)

{
  int *in_v0;
  
  _eh_vector_destructor_iterator_((void *)(*in_v0 + 8),8,1,FUN_40b58104);
  return;
}



/* 40b589b4 FUN_40b589b4 */

/* Boundary evidence: original MIPS .pdata 40b589b4..40b58a4f. Semantic name remains unreviewed. */

undefined4 FUN_40b589b4(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_40b6a448,0x10);
  if (((iVar1 == 0) && (*(int *)(param_1 + 8) != 0)) &&
     (iVar1 = (**(code **)**(undefined4 **)(*(int *)(param_1 + 8) + 0xc))(), iVar1 != 0)) {
    *param_2 = 0;
    param_2[1] = 0;
    return 0;
  }
  return 0x80040261;
}



/* 40b58a50 FUN_40b58a50 */

/* Boundary evidence: original MIPS .pdata 40b58a50..40b58dbf. Semantic name remains unreviewed. */

int FUN_40b58a50(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  int *local_38;
  uint local_34;
  int local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  
  iVar10 = *(int *)(param_1 + 8);
  local_38 = (int *)0x0;
  local_30[0] = 0;
  local_34 = 0;
  if ((iVar10 != 0) && (iVar2 = (**(code **)**(undefined4 **)(iVar10 + 0xc))(), iVar2 != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar10 + 0xc) + 4))(*(int **)(iVar10 + 0xc),&local_38);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_38 == (int *)0x0) {
      return 0;
    }
    iVar2 = (**(code **)(*local_38 + 0xc))(local_38,local_30);
    if (iVar2 < 0) {
      FUN_40b53210(0x40b67094,iVar2,param_3,param_4);
      (**(code **)(*local_38 + 8))();
      return iVar2;
    }
    uVar3 = (**(code **)(*local_38 + 0x10))();
    iVar11 = *(int *)(param_1 + 0x14);
    local_34 = uVar3;
    iVar2 = memcmp(*(void **)(iVar11 + 4),&DAT_40b683c8,0x10);
    puVar9 = (uint *)(param_1 + 0x28);
    if (iVar2 == 0) {
      uVar7 = *(uint *)(iVar11 + 8);
      uVar8 = *puVar9;
      uVar6 = *(int *)(iVar11 + 0xc) - *(int *)(param_1 + 0x2c);
      if (((int)(uVar6 - (uVar7 < uVar8)) < 1) &&
         ((uVar6 != uVar7 < uVar8 || (uVar7 - uVar8 < uVar3)))) {
        local_34 = uVar7 - uVar8;
      }
      puVar5 = &local_34;
      puVar4 = puVar9;
      iVar2 = FUN_40b54124(*(int *)(param_1 + 0x10),*(void **)(iVar11 + 4),puVar9,puVar5,local_30);
    }
    else {
      puVar5 = *(uint **)(param_1 + 0x2c);
      puVar4 = (uint *)*puVar9;
      iVar2 = (**(code **)(*param_2 + 0x1c))(param_2);
    }
    if (iVar2 < 0) {
      FUN_40b53210(0x40b67058,iVar2,puVar4,(va_list)puVar5);
      (**(code **)(*local_38 + 8))();
      return iVar2;
    }
    if (iVar2 == 1) {
      uVar6 = local_34 + *puVar9;
      iVar11 = *(int *)(*(int *)(param_1 + 0x14) + 0xc);
      uVar3 = *(uint *)(*(int *)(param_1 + 0x14) + 8);
      iVar2 = *(int *)(param_1 + 0x2c) + (uint)(uVar6 < local_34);
      if ((iVar11 <= iVar2) && ((iVar2 != iVar11 || (uVar3 < uVar6)))) {
        local_34 = uVar3 - *puVar9;
      }
    }
    uVar3 = local_34;
    iVar2 = memcmp(*(void **)(*(int *)(param_1 + 0x14) + 4),&DAT_40b68418,0x10);
    if (iVar2 == 0) {
      uVar6 = FUN_40b53fc8(local_30[0],uVar3);
      (**(code **)(*local_38 + 0x30))(local_38,uVar6);
      uVar3 = uVar6 + *puVar9;
      bVar1 = uVar3 < uVar6;
    }
    else {
      (**(code **)(*local_38 + 0x30))();
      uVar3 = local_34 + *puVar9;
      bVar1 = uVar3 < local_34;
    }
    *puVar9 = uVar3;
    *(uint *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (uint)bVar1;
    if (*(int *)(param_1 + 0x20) == 0) {
      local_28 = 0;
      local_24 = 0;
      (**(code **)(*local_38 + 0x18))(local_38,&local_28,0);
      *(undefined4 *)(param_1 + 0x20) = 1;
    }
    (**(code **)(*local_38 + 0x40))(local_38,0);
    iVar10 = (**(code **)(**(int **)(iVar10 + 0xc) + 8))(*(int **)(iVar10 + 0xc),local_38);
    if (iVar10 != 0) {
      return iVar10;
    }
  }
  iVar10 = 0;
  iVar2 = *(int *)(*(int *)(param_1 + 0x14) + 0xc);
  if ((iVar2 <= *(int *)(param_1 + 0x2c)) &&
     ((*(int *)(param_1 + 0x2c) != iVar2 ||
      (*(uint *)(*(int *)(param_1 + 0x14) + 8) <= *(uint *)(param_1 + 0x28))))) {
    iVar10 = 2;
  }
  return iVar10;
}



/* 40b58dc0 FUN_40b58dc0 */

/* Boundary evidence: original MIPS .pdata 40b58dc0..40b58eb3. Semantic name remains unreviewed. */

undefined4 FUN_40b58dc0(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  va_list pcVar4;
  
  piVar3 = param_3;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
  pcVar4 = (va_list)(iVar1 + iVar2);
  if (pcVar4 != (va_list)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x24))(param_1);
    if (param_2 < iVar1 + iVar2) {
      if (param_3 != (int *)0x0) {
        iVar1 = *param_3;
        (**(code **)(**(int **)(param_1[2] + 0xc) + 0x10))();
        if (*param_3 == 0) {
          FUN_40b53210(0x40b67100,iVar1,piVar3,pcVar4);
          return 0x80004005;
        }
      }
      return 0;
    }
  }
  return 1;
}



/* 40b58eb4 FUN_40b58eb4 */

/* Boundary evidence: original MIPS .pdata 40b58eb4..40b58f83. Semantic name remains unreviewed. */

undefined4 FUN_40b58eb4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)((param_2 + 1) * 8 + param_1);
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *(char *)(puVar1 + 1) = (char)param_2;
    puVar3 = puVar1 + 3;
    *puVar1 = &PTR_FUN_40b66dbc;
    puVar1[2] = 0;
    *puVar3 = 0;
    puVar1[4] = 0;
    puVar1[4] = *puVar4;
    *puVar4 = puVar1;
    (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 **)(param_1 + 4),param_3,puVar3);
    (**(code **)(*(int *)*puVar3 + 0xc))((int *)*puVar3,param_4);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b58f84 FUN_40b58f84 */

/* Boundary evidence: original MIPS .pdata 40b58f84..40b58fcf. Semantic name remains unreviewed. */

undefined4 * FUN_40b58f84(undefined4 *param_1,uint param_2)

{
  FUN_40b58894(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b58fd0 FUN_40b58fd0 */

/* Boundary evidence: original MIPS .pdata 40b58fd0..40b592f3. Semantic name remains unreviewed. */

int FUN_40b58fd0(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  ushort *_Dst;
  LPVOID _Dst_00;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *_Buf1;
  undefined4 *puVar4;
  undefined4 auStack_68 [4];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_20;
  
  local_20 = DAT_40b6bf1c;
  FUN_40b5f1b8(auStack_68,(undefined4 *)&DAT_40b69298);
  _Buf1 = *(void **)(*(int *)(param_1 + 0x14) + 4);
  iVar1 = memcmp(_Buf1,&DAT_40b683b8,0x10);
  if (iVar1 == 0) {
    local_58 = 0x9ecdaae9;
    local_54 = 0x4b0ff0f5;
    local_50 = 0x4c6328a0;
    local_4c = 0x121603f4;
  }
  else {
    puVar4 = &DAT_40b68238;
    iVar1 = memcmp(_Buf1,&DAT_40b68238,0x10);
    if (iVar1 != 0) {
      iVar1 = memcmp(_Buf1,&DAT_40b69688,0x10);
      if (iVar1 == 0) {
        local_58 = 0xf46d207e;
        local_54 = 0x4f608e1b;
        local_50 = 0xb3be919a;
        local_4c = 0x63b9bd4d;
        FUN_40b5ef68((int)auStack_68,&DAT_40b69e58);
        FUN_40b5f374((int)auStack_68,*(int *)(*(int *)(param_1 + 0x14) + 0x28));
        _Dst = FUN_40b5ef8c((int)auStack_68,*(uint *)(*(int *)(param_1 + 0x14) + 0x40));
        memcpy(_Dst,*(void **)(*(int *)(param_1 + 0x14) + 0x44),
               *(size_t *)(*(int *)(param_1 + 0x14) + 0x40));
        *(uint *)(param_1 + 0x54) = (uint)*_Dst;
        *(uint *)(param_1 + 0x50) = (uint)_Dst[6];
        if (4 < _Dst[6]) {
          *(undefined4 *)(param_1 + 0x48) = 0xfffffff0;
          *(undefined4 *)(param_1 + 0x4c) = 0xffffffff;
        }
        goto LAB_40b5925c;
      }
      iVar1 = memcmp(_Buf1,&DAT_40b696a8,0x10);
      if (iVar1 == 0) {
        local_58 = 0xf46d207e;
        local_54 = 0x4f608e1b;
        local_50 = 0xb3be919a;
        local_4c = 0x63b9bd4d;
        goto LAB_40b59220;
      }
      puVar4 = &DAT_40b6a1e8;
      iVar1 = memcmp(_Buf1,&DAT_40b6a1e8,0x10);
      if (iVar1 != 0) {
        puVar4 = &DAT_40b6a1d8;
        uVar3 = 0x10;
        puVar2 = puVar4;
        iVar1 = memcmp(_Buf1,&DAT_40b6a1d8,0x10);
        if (iVar1 != 0) {
          FUN_40b53210(0x40b67138,puVar2,uVar3,param_4);
          FUN_40b5f15c((int)auStack_68);
          FUN_40b64a98(local_20);
          return -0x7fffbffb;
        }
      }
    }
    local_58 = *puVar4;
    local_54 = puVar4[1];
    local_50 = puVar4[2];
    local_4c = puVar4[3];
  }
LAB_40b59220:
  FUN_40b5ef68((int)auStack_68,&DAT_40b69e58);
  FUN_40b5f374((int)auStack_68,*(int *)(*(int *)(param_1 + 0x14) + 0x28));
  _Dst_00 = FUN_40b5ef8c((int)auStack_68,*(uint *)(*(int *)(param_1 + 0x14) + 0x40));
  memcpy(_Dst_00,*(void **)(*(int *)(param_1 + 0x14) + 0x44),
         *(size_t *)(*(int *)(param_1 + 0x14) + 0x40));
LAB_40b5925c:
  iVar1 = FUN_40b58eb4(param_1,0,L"Audio",auStack_68);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  }
  FUN_40b5f15c((int)auStack_68);
  FUN_40b64a98(local_20);
  return iVar1;
}



/* 40b592f4 FUN_40b592f4 */

/* Boundary evidence: original MIPS .pdata 40b592f4..40b59323. Semantic name remains unreviewed. */

void FUN_40b592f4(void)

{
  int in_v0;
  
  FUN_40b5f15c(in_v0 + -0x68);
  return;
}



/* 40b59324 FUN_40b59324 */

/* Boundary evidence: original MIPS .pdata 40b59324..40b5958f. Semantic name remains unreviewed. */

int FUN_40b59324(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LPVOID pvVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 *_Buf1;
  undefined4 *puVar5;
  undefined4 auStack_68 [18];
  uint local_20;
  
  local_20 = DAT_40b6bf1c;
  FUN_40b5f1b8(auStack_68,(undefined4 *)&DAT_40b69288);
  _Buf1 = *(undefined4 **)(*(int *)(param_1 + 0x14) + 4);
  iVar1 = memcmp(_Buf1,&DAT_40b68598,0x10);
  if (iVar1 == 0) {
    FUN_40b5ef44((int)auStack_68,(undefined4 *)&DAT_40b6a188);
    FUN_40b5ef68((int)auStack_68,(undefined4 *)&DAT_40b6a268);
    FUN_40b5f374((int)auStack_68,*(int *)(*(int *)(param_1 + 0x14) + 0x28));
    pvVar2 = FUN_40b5ef8c((int)auStack_68,*(uint *)(*(int *)(param_1 + 0x14) + 0x40));
    memcpy(pvVar2,*(void **)(*(int *)(param_1 + 0x14) + 0x44),
           *(size_t *)(*(int *)(param_1 + 0x14) + 0x40));
    if ((*(int *)((int)pvVar2 + 0x74) == 0) && (*(int *)((int)pvVar2 + 0x84) == 1)) {
      FUN_40b5ef44((int)auStack_68,(undefined4 *)&DAT_40b695d8);
    }
  }
  else {
    puVar5 = (undefined4 *)&DAT_40b68418;
    iVar1 = memcmp(_Buf1,&DAT_40b68418,0x10);
    if (iVar1 != 0) {
      iVar1 = memcmp(_Buf1,&DAT_40b683c8,0x10);
      if (iVar1 == 0) {
        puVar5 = (undefined4 *)&DAT_40b683c8;
      }
      else {
        iVar1 = memcmp(_Buf1,&DAT_40b68578,0x10);
        if (iVar1 == 0) {
          puVar5 = (undefined4 *)&DAT_40b68578;
        }
        else {
          uVar4 = 0x10;
          puVar3 = &DAT_40b685e8;
          iVar1 = memcmp(_Buf1,&DAT_40b685e8,0x10);
          puVar5 = _Buf1;
          if (iVar1 != 0) {
            FUN_40b53210(0x40b671f8,puVar3,uVar4,param_4);
            FUN_40b5f15c((int)auStack_68);
            FUN_40b64a98(local_20);
            return -0x7fffbffb;
          }
        }
      }
    }
    FUN_40b5ef44((int)auStack_68,puVar5);
    FUN_40b5ef68((int)auStack_68,(undefined4 *)&DAT_40b68018);
    FUN_40b5f374((int)auStack_68,*(int *)(*(int *)(param_1 + 0x14) + 0x28));
    pvVar2 = FUN_40b5ef8c((int)auStack_68,*(uint *)(*(int *)(param_1 + 0x14) + 0x40));
    memcpy(pvVar2,*(void **)(*(int *)(param_1 + 0x14) + 0x44),
           *(size_t *)(*(int *)(param_1 + 0x14) + 0x40));
  }
  iVar1 = FUN_40b58eb4(param_1,0,L"Video",auStack_68);
  if (-1 < iVar1) {
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  }
  FUN_40b5f15c((int)auStack_68);
  FUN_40b64a98(local_20);
  return iVar1;
}



/* 40b59590 FUN_40b59590 */

/* Boundary evidence: original MIPS .pdata 40b59590..40b595bf. Semantic name remains unreviewed. */

void FUN_40b59590(void)

{
  int in_v0;
  
  FUN_40b5f15c(in_v0 + -0x68);
  return;
}



/* 40b595c0 FUN_40b595c0 */

/* Boundary evidence: original MIPS .pdata 40b595c0..40b59a87. Semantic name remains unreviewed. */

int FUN_40b595c0(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  void *pvVar4;
  byte **ppbVar5;
  void **ppvVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined4 uVar9;
  byte *pbVar10;
  uint uVar11;
  va_list pcVar12;
  int iVar13;
  va_list pcVar14;
  byte *local_28;
  void *local_24;
  int local_20;
  undefined4 *local_1c;
  
  local_20 = 0;
  local_24 = (void *)0x0;
  iVar13 = 0;
  local_1c = operator_new(0x48);
  if (local_1c == (undefined4 *)0x0) {
    puVar2 = (uint *)0x0;
  }
  else {
    puVar2 = FUN_40b54034(local_1c,param_2,&local_20);
  }
  uVar9 = 0x100;
  ppbVar5 = &local_28;
  *(uint **)(param_1 + 0x10) = puVar2;
  uVar3 = FUN_40b542f4(puVar2,ppbVar5,0x100);
  if ((local_28 == (byte *)0x0) && (uVar3 == 0)) {
    FUN_40b53210(0x40b67390,ppbVar5,uVar9,param_4);
    return -0x7fffbffb;
  }
  if (((*local_28 == 0x49) && (local_28[1] == 0x44)) && (local_28[2] == 0x33)) {
    pcVar14 = (va_list)((((uint)local_28[6] << 7 | (uint)local_28[7]) << 7 | (uint)local_28[8]) << 7
                       | (uint)local_28[9]);
    operator_delete(local_28);
    puVar2 = *(uint **)(param_1 + 0x10);
    uVar11 = *puVar2;
    pcVar12 = pcVar14 + (10 - uVar3);
    *puVar2 = (uint)(pcVar12 + uVar11);
    puVar2[1] = ((int)pcVar12 >> 0x1f) + puVar2[1] + (uint)(pcVar12 + uVar11 < pcVar12);
    pcVar12 = (va_list)FUN_40b542f4(*(uint **)(param_1 + 0x10),&local_28,0x10000);
    if (pcVar12 == (va_list)0x0) {
      return -0x7fffbffb;
    }
    ppvVar6 = &local_24;
    pbVar10 = local_28;
    local_20 = FUN_40b57190(*(uint **)(param_1 + 0x10),ppvVar6,local_28,pcVar12,pcVar14,1);
  }
  else {
    if ((*local_28 == 0xff) && ((local_28[1] & 0xf0) == 0xf0)) {
      uVar3 = 0x10000;
      iVar13 = 1;
    }
    else {
      uVar3 = 0x13a000;
    }
    puVar7 = *(undefined4 **)(param_1 + 0x10);
    *puVar7 = 0;
    puVar7[1] = 0;
    operator_delete(local_28);
    pcVar12 = (va_list)FUN_40b542f4(*(uint **)(param_1 + 0x10),&local_28,uVar3);
    ppvVar6 = &local_24;
    pbVar10 = local_28;
    local_20 = FUN_40b57190(*(uint **)(param_1 + 0x10),ppvVar6,local_28,pcVar12,(va_list)0x0,iVar13)
    ;
  }
  if (*(int *)(*(int *)(param_1 + 0x10) + 8) != 0) {
    FUN_40b53210(0x40b6732c,ppvVar6,pbVar10,pcVar12);
    return -0x7ffbfdd6;
  }
  operator_delete(local_28);
  if ((local_20 < 0) || (local_24 == (void *)0x0)) {
    FUN_40b53210(0x40b672b8,local_20,pbVar10,pcVar12);
    return -0x7ffbfdd6;
  }
  pvVar4 = malloc(*(int *)((int)local_24 + 0x40) + 0x48);
  *(void **)(param_1 + 0x14) = pvVar4;
  memcpy(pvVar4,local_24,*(int *)((int)local_24 + 0x40) + 0x48);
  pvVar4 = *(void **)(*(int *)(param_1 + 0x14) + 4);
  uVar9 = 0x10;
  puVar7 = &DAT_40b683b8;
  iVar13 = memcmp(pvVar4,&DAT_40b683b8,0x10);
  if (iVar13 != 0) {
    uVar9 = 0x10;
    puVar7 = &DAT_40b68238;
    iVar13 = memcmp(pvVar4,&DAT_40b68238,0x10);
    if (iVar13 != 0) {
      uVar9 = 0x10;
      puVar7 = (undefined4 *)&DAT_40b69688;
      iVar13 = memcmp(pvVar4,&DAT_40b69688,0x10);
      if (iVar13 != 0) {
        uVar9 = 0x10;
        puVar7 = (undefined4 *)&DAT_40b696a8;
        iVar13 = memcmp(pvVar4,&DAT_40b696a8,0x10);
        if (iVar13 != 0) {
          uVar9 = 0x10;
          puVar7 = &DAT_40b6a1e8;
          iVar13 = memcmp(pvVar4,&DAT_40b6a1e8,0x10);
          if (iVar13 != 0) {
            uVar9 = 0x10;
            puVar7 = &DAT_40b6a1d8;
            iVar13 = memcmp(pvVar4,&DAT_40b6a1d8,0x10);
            if (iVar13 != 0) {
              uVar9 = 0x10;
              puVar8 = &DAT_40b68598;
              iVar13 = memcmp(pvVar4,&DAT_40b68598,0x10);
              if (iVar13 != 0) {
                uVar9 = 0x10;
                puVar8 = &DAT_40b68418;
                iVar13 = memcmp(pvVar4,&DAT_40b68418,0x10);
                if (iVar13 != 0) {
                  uVar9 = 0x10;
                  puVar8 = &DAT_40b683c8;
                  iVar13 = memcmp(pvVar4,&DAT_40b683c8,0x10);
                  if (iVar13 != 0) {
                    uVar9 = 0x10;
                    puVar8 = &DAT_40b68578;
                    iVar13 = memcmp(pvVar4,&DAT_40b68578,0x10);
                    if (iVar13 != 0) {
                      uVar9 = 0x10;
                      puVar8 = &DAT_40b685e8;
                      iVar13 = memcmp(pvVar4,&DAT_40b685e8,0x10);
                      if (iVar13 != 0) {
                        iVar13 = memcmp(pvVar4,&DAT_40b685a8,0x10);
                        if ((((iVar13 != 0) &&
                             (iVar13 = memcmp(pvVar4,&DAT_40b695f8,0x10), iVar13 != 0)) &&
                            (iVar13 = memcmp(pvVar4,&DAT_40b6a1c8,0x10), iVar13 != 0)) &&
                           (iVar13 = memcmp(pvVar4,&DAT_40b6a1b8,0x10), iVar13 != 0)) {
                          memcmp(pvVar4,&DAT_40b695b8,0x10);
                        }
                        free(local_24);
                        return -0x7ffbfdd6;
                      }
                    }
                  }
                }
              }
              FUN_40b59324(param_1,puVar8,uVar9,pcVar12);
              goto LAB_40b59a08;
            }
          }
        }
      }
    }
  }
  FUN_40b58fd0(param_1,puVar7,uVar9,pcVar12);
LAB_40b59a08:
  iVar13 = *(int *)(*(int *)(param_1 + 0x14) + 0x14);
  uVar3 = *(uint *)(*(int *)(param_1 + 0x14) + 0x10);
  *(undefined4 *)(param_1 + 0x20) = 0;
  lVar1 = (ulonglong)uVar3 * 10000;
  *(int *)(param_1 + 0x18) = (int)lVar1;
  *(int *)(param_1 + 0x1c) = iVar13 * 10000 + (int)((ulonglong)lVar1 >> 0x20);
  free(local_24);
  return local_20;
}



/* 40b59a88 FUN_40b59a88 */

/* Boundary evidence: original MIPS .pdata 40b59a88..40b59ab7. Semantic name remains unreviewed. */

void FUN_40b59a88(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x1c));
  return;
}



/* 40b59ab8 FUN_40b59ab8 */

/* Boundary evidence: original MIPS .pdata 40b59ab8..40b59ad3. Semantic name remains unreviewed. */

void FUN_40b59ab8(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40b59ad4 FUN_40b59ad4 */

/* Boundary evidence: original MIPS .pdata 40b59ad4..40b59aff. Semantic name remains unreviewed. */

void FUN_40b59ad4(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x4c) + 0x98) + 0x18))();
  return;
}



/* 40b59b00 FUN_40b59b00 */

/* Boundary evidence: original MIPS .pdata 40b59b00..40b59b2b. Semantic name remains unreviewed. */

void FUN_40b59b00(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x4c) + 0xc) + 0x38))();
  return;
}



/* 40b59b2c FUN_40b59b2c */

/* Boundary evidence: original MIPS .pdata 40b59b2c..40b59b6f. Semantic name remains unreviewed. */

void FUN_40b59b2c(int param_1,int param_2)

{
  if ((param_2 != -0x7ffbfdd9) && (param_2 < 0)) {
    FUN_40b5f64c(*(int *)(*(int *)(param_1 + 0x4c) + 0x70));
  }
  return;
}



/* 40b59b70 FUN_40b59b70 */

/* Boundary evidence: original MIPS .pdata 40b59b70..40b59b9b. Semantic name remains unreviewed. */

void FUN_40b59b70(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x4c) + 0xc) + 0x3c))();
  return;
}



/* 40b59b9c FUN_40b59b9c */

/* Boundary evidence: original MIPS .pdata 40b59b9c..40b59bc7. Semantic name remains unreviewed. */

void FUN_40b59b9c(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x4c) + 0xc) + 0x40))();
  return;
}



/* 40b59bc8 FUN_40b59bc8 */

/* Boundary evidence: original MIPS .pdata 40b59bc8..40b59be3. Semantic name remains unreviewed. */

void FUN_40b59bc8(int param_1)

{
  FUN_40b5fa14(param_1);
  return;
}



/* 40b59be4 FUN_40b59be4 */

/* Boundary evidence: original MIPS .pdata 40b59be4..40b59bff. Semantic name remains unreviewed. */

void FUN_40b59be4(undefined4 *param_1)

{
  FUN_40b62660(param_1);
  return;
}



/* 40b59c00 FUN_40b59c00 */

/* Boundary evidence: original MIPS .pdata 40b59c00..40b59c1b. Semantic name remains unreviewed. */

void FUN_40b59c00(int param_1)

{
  FUN_40b62904(param_1);
  return;
}



/* 40b59c1c FUN_40b59c1c */

/* Boundary evidence: original MIPS .pdata 40b59c1c..40b59c37. Semantic name remains unreviewed. */

void FUN_40b59c1c(int *param_1)

{
  FUN_40b62940(param_1);
  return;
}



/* 40b59c38 FUN_40b59c38 */

/* Boundary evidence: original MIPS .pdata 40b59c38..40b59c53. Semantic name remains unreviewed. */

void FUN_40b59c38(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40b5fa58(param_1,param_2,param_3);
  return;
}



/* 40b59c54 FUN_40b59c54 */

/* Boundary evidence: original MIPS .pdata 40b59c54..40b59cbf. Semantic name remains unreviewed. */

void FUN_40b59c54(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined1 auStack_20 [16];
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x70) + 0xbc);
  (**(code **)(*piVar1 + 8))(piVar1,param_3 + 4,param_3);
  *(undefined4 *)(param_3 + 8) = 1;
  *(undefined4 *)(param_3 + 0xc) = 0;
  (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_20);
  return;
}



/* 40b59cc0 FUN_40b59cc0 */

/* Boundary evidence: original MIPS .pdata 40b59cc0..40b59d73. Semantic name remains unreviewed. */

undefined4 FUN_40b59cc0(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_40b53210(0x40b67494,*param_2,param_3,param_4);
    (**(code **)(*param_2 + 8))(param_2);
    return 1;
  }
  iVar1 = (**(code **)(*param_2 + 0x3c))(param_2);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0xa8) != 0)) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
    (**(code **)(*param_2 + 0x40))(param_2,1);
  }
  uVar2 = FUN_40b63448(*(LPCRITICAL_SECTION *)(param_1 + 0xac),param_2);
  return uVar2;
}



/* 40b59d74 FUN_40b59d74 */

/* Boundary evidence: original MIPS .pdata 40b59d74..40b59d8f. Semantic name remains unreviewed. */

void FUN_40b59d74(int param_1,int *param_2)

{
  FUN_40b5fdf8(param_1,param_2);
  return;
}



/* 40b59d90 FUN_40b59d90 */

/* Boundary evidence: original MIPS .pdata 40b59d90..40b59dab. Semantic name remains unreviewed. */

void FUN_40b59d90(int *param_1)

{
  FUN_40b5fdd0(param_1);
  return;
}



/* 40b59dac FUN_40b59dac */

/* Boundary evidence: original MIPS .pdata 40b59dac..40b59e27. Semantic name remains unreviewed. */

void FUN_40b59dac(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x98) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x18))();
    if (iVar1 < 0) {
      return;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 8))();
    if (iVar1 != 0) {
      FUN_40b53210(0x40b674d0,iVar1,param_3,param_4);
    }
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  FUN_40b5fe60(param_1);
  return;
}



/* 40b59e28 FUN_40b59e28 */

/* Boundary evidence: original MIPS .pdata 40b59e28..40b59e43. Semantic name remains unreviewed. */

void FUN_40b59e28(undefined4 *param_1)

{
  FUN_40b62660(param_1);
  return;
}



/* 40b59e44 FUN_40b59e44 */

/* Boundary evidence: original MIPS .pdata 40b59e44..40b59fa7. Semantic name remains unreviewed. */

int FUN_40b59e44(int *param_1)

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



/* 40b59fa8 FUN_40b59fa8 */

/* Boundary evidence: original MIPS .pdata 40b59fa8..40b59fd7. Semantic name remains unreviewed. */

void FUN_40b59fa8(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40b59fd8 FUN_40b59fd8 */

/* Boundary evidence: original MIPS .pdata 40b59fd8..40b5a03b. Semantic name remains unreviewed. */

undefined4 FUN_40b59fd8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  if (*(int *)(param_1 + 0x14) != 0) {
    DAT_40b6bfb4 = *(int *)(param_1 + 0x14);
  }
  if ((DAT_40b6bfb0 != (int *)0x0) && (iVar1 = (**(code **)(*DAT_40b6bfb0 + 0x10))(), -1 < iVar1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b5a03c FUN_40b5a03c */

/* Boundary evidence: original MIPS .pdata 40b5a03c..40b5a1ef. Semantic name remains unreviewed. */

int FUN_40b5a03c(int *param_1,undefined4 param_2,int *param_3,va_list param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x25);
  EnterCriticalSection(lpCriticalSection);
  if ((int *)param_1[0x3c] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x3c] + 8))();
    param_1[0x3c] = 0;
  }
  iVar3 = param_1[0x14];
  piVar4 = *(int **)(iVar3 + 0x11c);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))();
  }
  pcVar5 = *(code **)(*param_1 + 0x3c);
  param_1[0x3c] = *(int *)(iVar3 + 0x11c);
  piVar4 = (int *)(*pcVar5)(param_1,param_1 + 0x34);
  param_1[0x2f] = (int)piVar4;
  if (piVar4 == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar3 = -0x7ff8fff2;
  }
  else {
    piVar2 = (int *)param_1[0x3c];
    iVar3 = (**(code **)(*piVar4 + 4))(piVar4);
    if (-1 < iVar3) {
      param_3 = param_1 + 0x30;
      piVar2 = param_1 + 0x40;
      (**(code **)(*(int *)param_1[0x2f] + 0x14))();
    }
    if (param_1[0x3b] != 0) {
      FUN_40b53210(0x40b675a8,piVar2,param_3,param_4);
      piVar4 = (int *)param_1[0x3b];
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0xc))(piVar4,1);
      }
      param_1[0x3b] = 0;
    }
    if (param_1[0x3b] == 0) {
      puVar1 = operator_new(0x50);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_40b5e010(puVar1,param_1,(undefined4 *)param_1[1]);
      }
      param_1[0x3b] = (int)puVar1;
    }
    if (-1 < iVar3) {
      *(int *)(param_1[0x14] + 0xd8) = param_1[0x2f];
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar3;
}



/* 40b5a1f0 FUN_40b5a1f0 */

/* Boundary evidence: original MIPS .pdata 40b5a1f0..40b5a21f. Semantic name remains unreviewed. */

void FUN_40b5a1f0(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b5a220 FUN_40b5a220 */

/* Boundary evidence: original MIPS .pdata 40b5a220..40b5a24f. Semantic name remains unreviewed. */

void FUN_40b5a220(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x20));
  return;
}



/* 40b5a250 FUN_40b5a250 */

/* Boundary evidence: original MIPS .pdata 40b5a250..40b5a41f. Semantic name remains unreviewed. */

int FUN_40b5a250(int *param_1,undefined4 param_2)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *local_20;
  LPCRITICAL_SECTION local_1c;
  
  if (((DAT_40b6bfb0 == 0) && (DAT_40b6bfb4 != 0)) &&
     (iVar1 = memcmp(*(void **)(DAT_40b6bfb4 + 4),&DAT_40b6a1d8,0x10), iVar1 == 0)) {
    local_20 = (int *)0x0;
    (**(code **)(*(int *)param_1[0x10] + 0x14))((int *)param_1[0x10],&local_20);
    if (local_20 != (int *)0x0) {
      local_1c = (LPCRITICAL_SECTION)0x0;
      while ((DAT_40b6bfb0 == 0 &&
             (iVar1 = (**(code **)(*local_20 + 0xc))(local_20,1,&local_1c,0), iVar1 == 0))) {
        (**(code **)local_1c->DebugInfo)(local_1c,&DAT_40b67468,&DAT_40b6bfb0);
        (*(code *)(local_1c->DebugInfo->ProcessLocksList).Flink)();
      }
      (**(code **)(*local_20 + 8))();
    }
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x25);
  local_1c = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if (param_1[5] == 0) {
    iVar1 = -0x7fffbffc;
  }
  else {
    iVar1 = (**(code **)(*(int *)param_1[0x2f] + 0xc))((int *)param_1[0x2f],param_2);
    if ((iVar1 != 2) && (iVar1 < 0)) {
      if (iVar1 == -0x7ffbfda3) {
        LeaveCriticalSection(lpCriticalSection);
        return -0x7ffbfda3;
      }
      (**(code **)(*param_1 + 0x2c))(param_1);
      LeaveCriticalSection(lpCriticalSection);
      return 1;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40b5a420 FUN_40b5a420 */

/* Boundary evidence: original MIPS .pdata 40b5a420..40b5a44f. Semantic name remains unreviewed. */

void FUN_40b5a420(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40b5a450 FUN_40b5a450 */

/* Boundary evidence: original MIPS .pdata 40b5a450..40b5a477. Semantic name remains unreviewed. */

void FUN_40b5a450(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xbc) + 0x14))();
  return;
}



/* 40b5a478 FUN_40b5a478 */

/* Boundary evidence: original MIPS .pdata 40b5a478..40b5a49f. Semantic name remains unreviewed. */

void FUN_40b5a478(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xbc) + 0x10))();
  return;
}



/* 40b5a4a0 FUN_40b5a4a0 */

/* Boundary evidence: original MIPS .pdata 40b5a4a0..40b5a4eb. Semantic name remains unreviewed. */

undefined4 FUN_40b5a4a0(undefined4 param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_2 != (void *)0x0) {
    iVar2 = memcmp(param_2,&DAT_40b6a448,0x10);
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 40b5a4ec FUN_40b5a4ec */

undefined4 FUN_40b5a4ec(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0xc0) = *param_2;
  *(undefined4 *)(param_1 + 0xc4) = param_2[1];
  *(undefined4 *)(param_1 + 200) = param_2[2];
  *(undefined4 *)(param_1 + 0xcc) = param_2[3];
  return 0;
}



/* 40b5a514 FUN_40b5a514 */

/* Boundary evidence: original MIPS .pdata 40b5a514..40b5a59b. Semantic name remains unreviewed. */

undefined4 FUN_40b5a514(int param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xd8);
  EnterCriticalSection(lpCriticalSection);
  if (*(int **)(param_1 + 0xbc) == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0xbc) + 0x18))();
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40b5a59c FUN_40b5a59c */

/* Boundary evidence: original MIPS .pdata 40b5a59c..40b5a5cb. Semantic name remains unreviewed. */

void FUN_40b5a59c(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b5a5cc FUN_40b5a5cc */

/* Boundary evidence: original MIPS .pdata 40b5a5cc..40b5a683. Semantic name remains unreviewed. */

undefined4 * FUN_40b5a5cc(undefined4 *param_1,int param_2,undefined4 param_3)

{
  FUN_40b622c8(param_1,0,param_2,param_2 + 0x6c,param_3,L"Input");
  *param_1 = &PTR_FUN_40b67778;
  param_1[3] = &PTR_FUN_40b67730;
  param_1[4] = &PTR_LAB_40b6771c;
  param_1[0x26] = &PTR_LAB_40b676f8;
  param_1[0x36] = 0;
  FUN_40b53350(param_1 + 0x37);
  param_1[0x37] = &PTR_FUN_40b67478;
  param_1[0x4a] = param_1;
  return param_1;
}



/* 40b5a684 FUN_40b5a684 */

/* Boundary evidence: original MIPS .pdata 40b5a684..40b5a6b3. Semantic name remains unreviewed. */

void FUN_40b5a684(void)

{
  int *in_v0;
  
  FUN_40b60294(*in_v0);
  return;
}



/* 40b5a6b4 FUN_40b5a6b4 */

/* Boundary evidence: original MIPS .pdata 40b5a6b4..40b5a6db. Semantic name remains unreviewed. */

void FUN_40b5a6b4(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b5a6dc FUN_40b5a6dc */

/* Boundary evidence: original MIPS .pdata 40b5a6dc..40b5a703. Semantic name remains unreviewed. */

void FUN_40b5a6dc(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b5a704 FUN_40b5a704 */

/* Boundary evidence: original MIPS .pdata 40b5a704..40b5a72b. Semantic name remains unreviewed. */

void FUN_40b5a704(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b5a72c FUN_40b5a72c */

/* Boundary evidence: original MIPS .pdata 40b5a72c..40b5a79b. Semantic name remains unreviewed. */

undefined4 FUN_40b5a72c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b68cd8,0x10);
  if (iVar1 == 0) {
    uVar2 = 0x80004002;
  }
  else {
    uVar2 = FUN_40b602dc(param_1,param_2,param_3);
  }
  return uVar2;
}



/* 40b5a79c FUN_40b5a79c */

/* Boundary evidence: original MIPS .pdata 40b5a79c..40b5a7e7. Semantic name remains unreviewed. */

void FUN_40b5a79c(int param_1)

{
  FUN_40b53b0c((undefined4 *)(param_1 + 0xdc));
  FUN_40b60294(param_1);
  return;
}



/* 40b5a7e8 FUN_40b5a7e8 */

/* Boundary evidence: original MIPS .pdata 40b5a7e8..40b5a817. Semantic name remains unreviewed. */

void FUN_40b5a7e8(void)

{
  int *in_v0;
  
  FUN_40b60294(*in_v0);
  return;
}



/* 40b5a820 FUN_40b5a820 */

/* Boundary evidence: original MIPS .pdata 40b5a820..40b5a86b. Semantic name remains unreviewed. */

void FUN_40b5a820(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b5fb78(param_1,param_2);
  if (-1 < iVar1) {
    FUN_40b53b94(param_1 + 0xdc,param_2);
  }
  return;
}



/* 40b5a86c FUN_40b5a86c */

/* Boundary evidence: original MIPS .pdata 40b5a86c..40b5a8af. Semantic name remains unreviewed. */

void FUN_40b5a86c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x40))();
  FUN_40b5379c(param_1 + 0xdc);
  FUN_40b5fd48();
  return;
}



/* 40b5a8b0 FUN_40b5a8b0 */

/* Boundary evidence: original MIPS .pdata 40b5a8b0..40b5a953. Semantic name remains unreviewed. */

int FUN_40b5a8b0(int param_1)

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



/* 40b5a954 FUN_40b5a954 */

/* Boundary evidence: original MIPS .pdata 40b5a954..40b5a983. Semantic name remains unreviewed. */

void FUN_40b5a954(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b5a984 FUN_40b5a984 */

/* Boundary evidence: original MIPS .pdata 40b5a984..40b5a9fb. Semantic name remains unreviewed. */

undefined4 FUN_40b5a984(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  FUN_40b60560(param_1);
  (**(code **)(**(int **)(param_1 + 100) + 0x24))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b5a9fc FUN_40b5a9fc */

/* Boundary evidence: original MIPS .pdata 40b5a9fc..40b5aa2b. Semantic name remains unreviewed. */

void FUN_40b5a9fc(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b5aa2c FUN_40b5aa2c */

/* Boundary evidence: original MIPS .pdata 40b5aa2c..40b5aaa3. Semantic name remains unreviewed. */

undefined4 FUN_40b5aa2c(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  FUN_40b605a8(param_1);
  (**(code **)(**(int **)(param_1 + 100) + 0x28))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b5aaa4 FUN_40b5aaa4 */

/* Boundary evidence: original MIPS .pdata 40b5aaa4..40b5aad3. Semantic name remains unreviewed. */

void FUN_40b5aaa4(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b5aad4 FUN_40b5aad4 */

/* Boundary evidence: original MIPS .pdata 40b5aad4..40b5abc7. Semantic name remains unreviewed. */

int FUN_40b5aad4(int param_1,undefined4 param_2)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + -0x28) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*(int *)(param_1 + -0x98) + 0x38))();
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else if (iVar1 == 1) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 1;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + -0x28) + 0x30))(*(int **)(param_1 + -0x28),param_2);
    if ((iVar1 != 0) && (iVar1 < 0)) {
      FUN_40b5f64c(*(int *)(param_1 + -0x28));
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40b5abc8 FUN_40b5abc8 */

/* Boundary evidence: original MIPS .pdata 40b5abc8..40b5abf7. Semantic name remains unreviewed. */

void FUN_40b5abc8(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b5abf8 FUN_40b5abf8 */

/* Boundary evidence: original MIPS .pdata 40b5abf8..40b5ac27. Semantic name remains unreviewed. */

void FUN_40b5abf8(int param_1)

{
  FUN_40b53888(param_1 + 0xdc);
  FUN_40b6060c(param_1);
  return;
}



/* 40b5ac28 FUN_40b5ac28 */

/* Boundary evidence: original MIPS .pdata 40b5ac28..40b5ac4f. Semantic name remains unreviewed. */

void FUN_40b5ac28(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x34))();
  return;
}



/* 40b5ac50 FUN_40b5ac50 */

/* Boundary evidence: original MIPS .pdata 40b5ac50..40b5ac77. Semantic name remains unreviewed. */

void FUN_40b5ac50(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x38))();
  return;
}



/* 40b5ac78 FUN_40b5ac78 */

/* Boundary evidence: original MIPS .pdata 40b5ac78..40b5ad03. Semantic name remains unreviewed. */

undefined4 FUN_40b5ac78(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[0x1c];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  uVar3 = 0;
  bVar1 = FUN_40b538a8(param_1 + 0x37);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    uVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  return uVar3;
}



/* 40b5ad04 FUN_40b5ad04 */

/* Boundary evidence: original MIPS .pdata 40b5ad04..40b5ad33. Semantic name remains unreviewed. */

void FUN_40b5ad04(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b5ad34 FUN_40b5ad34 */

/* Boundary evidence: original MIPS .pdata 40b5ad34..40b5adbf. Semantic name remains unreviewed. */

undefined4 FUN_40b5ad34(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[0x1c];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  uVar3 = 0;
  bVar1 = FUN_40b53974(param_1 + 0x37);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    uVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  return uVar3;
}



/* 40b5adc0 FUN_40b5adc0 */

/* Boundary evidence: original MIPS .pdata 40b5adc0..40b5adef. Semantic name remains unreviewed. */

void FUN_40b5adc0(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b5ae68 FUN_40b5ae68 */

/* Boundary evidence: original MIPS .pdata 40b5ae68..40b5aeb3. Semantic name remains unreviewed. */

undefined4 * FUN_40b5ae68(undefined4 *param_1,uint param_2)

{
  FUN_40b53b0c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b5aed0 FUN_40b5aed0 */

/* Boundary evidence: original MIPS .pdata 40b5aed0..40b5aefb. Semantic name remains unreviewed. */

void FUN_40b5aed0(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x1c))();
  return;
}



/* 40b5af0c FUN_40b5af0c */

/* Boundary evidence: original MIPS .pdata 40b5af0c..40b5af33. Semantic name remains unreviewed. */

void FUN_40b5af0c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 0x4c))();
  return;
}



/* 40b5af34 FUN_40b5af34 */

/* Boundary evidence: original MIPS .pdata 40b5af34..40b5af7f. Semantic name remains unreviewed. */

int FUN_40b5af34(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(*(int *)(param_1 + 4) + 0x18) != 0) &&
     (piVar2 = *(int **)(*(int *)(param_1 + 4) + 0x98),
     iVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2,param_2,0,0,0), -1 < iVar1)) {
    return iVar1;
  }
  return 1;
}



/* 40b5af80 FUN_40b5af80 */

/* Boundary evidence: original MIPS .pdata 40b5af80..40b5af9b. Semantic name remains unreviewed. */

void FUN_40b5af80(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  FUN_40b59cc0(*(int *)(param_1 + 4),param_2,param_3,param_4);
  return;
}



/* 40b5af9c FUN_40b5af9c */

/* Boundary evidence: original MIPS .pdata 40b5af9c..40b5b03f. Semantic name remains unreviewed. */

undefined4 * FUN_40b5af9c(undefined4 *param_1,int param_2,undefined4 param_3,wchar_t *param_4)

{
  FUN_40b6227c(param_1,0,param_2,param_2 + 0x6c,param_3,param_4);
  *param_1 = &PTR_FUN_40b67a04;
  param_1[3] = &PTR_FUN_40b679bc;
  param_1[4] = &PTR_LAB_40b679a8;
  param_1[0x28] = &PTR_LAB_40b6798c;
  param_1[0x29] = param_1;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  FUN_40b623c4(param_1 + 0x2c);
  return param_1;
}



/* 40b5b040 FUN_40b5b040 */

/* Boundary evidence: original MIPS .pdata 40b5b040..40b5b06f. Semantic name remains unreviewed. */

void FUN_40b5b040(void)

{
  int *in_v0;
  
  FUN_40b59bc8(*in_v0);
  return;
}



/* 40b5b070 FUN_40b5b070 */

/* Boundary evidence: original MIPS .pdata 40b5b070..40b5b097. Semantic name remains unreviewed. */

void FUN_40b5b070(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b5b098 FUN_40b5b098 */

/* Boundary evidence: original MIPS .pdata 40b5b098..40b5b0bf. Semantic name remains unreviewed. */

void FUN_40b5b098(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b5b0c0 FUN_40b5b0c0 */

/* Boundary evidence: original MIPS .pdata 40b5b0c0..40b5b0e7. Semantic name remains unreviewed. */

void FUN_40b5b0c0(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b5b0e8 FUN_40b5b0e8 */

/* Boundary evidence: original MIPS .pdata 40b5b0e8..40b5b107. Semantic name remains unreviewed. */

undefined4 FUN_40b5b0e8(int param_1)

{
  FUN_40b632f4(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40b5b108 FUN_40b5b108 */

/* Boundary evidence: original MIPS .pdata 40b5b108..40b5b127. Semantic name remains unreviewed. */

undefined4 FUN_40b5b108(int param_1)

{
  FUN_40b629fc(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40b5b128 FUN_40b5b128 */

/* Boundary evidence: original MIPS .pdata 40b5b128..40b5b14f. Semantic name remains unreviewed. */

undefined4 FUN_40b5b128(int param_1)

{
  *(undefined4 *)(param_1 + 0xa8) = 1;
  FUN_40b63394(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40b5b18c FUN_40b5b18c */

/* Boundary evidence: original MIPS .pdata 40b5b18c..40b5b1e7. Semantic name remains unreviewed. */

int FUN_40b5b18c(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  
  iVar1 = FUN_40b60154(param_1);
  if (-1 < iVar1) {
    p_Var2 = *(LPCRITICAL_SECTION *)(param_1 + 0xac);
    if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
      FUN_40b62eb0(p_Var2);
      operator_delete(p_Var2);
    }
    *(undefined4 *)(param_1 + 0xac) = 0;
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b5b1e8 FUN_40b5b1e8 */

/* Boundary evidence: original MIPS .pdata 40b5b1e8..40b5b33f. Semantic name remains unreviewed. */

DWORD FUN_40b5b1e8(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  LPCRITICAL_SECTION p_Var3;
  DWORD local_70;
  LPCRITICAL_SECTION local_6c;
  undefined1 auStack_68 [72];
  uint local_20;
  
  uVar1 = DAT_40b6bf1c;
  local_20 = DAT_40b6bf1c;
  *(undefined4 *)(param_1 + 0xa8) = 1;
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_40b64a98(uVar1);
    DVar2 = 0;
  }
  else {
    DVar2 = FUN_40b60114(param_1);
    if ((int)DVar2 < 0) {
      FUN_40b64a98(local_20);
    }
    else {
      local_70 = 0;
      (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))((int *)(param_1 + 0xc),auStack_68);
      FUN_40b5f0f8((int)auStack_68);
      local_6c = operator_new(0x54);
      if (local_6c == (LPCRITICAL_SECTION)0x0) {
        p_Var3 = (LPCRITICAL_SECTION)0x0;
      }
      else {
        p_Var3 = FUN_40b634c4(local_6c,*(undefined4 **)(param_1 + 0x18),&local_70,0,1,1,0,200,3);
      }
      *(LPCRITICAL_SECTION *)(param_1 + 0xac) = p_Var3;
      if (p_Var3 == (LPCRITICAL_SECTION)0x0) {
        FUN_40b64a98(local_20);
        DVar2 = 0x8007000e;
      }
      else {
        if ((int)local_70 < 0) {
          FUN_40b62eb0(p_Var3);
          operator_delete(p_Var3);
          *(undefined4 *)(param_1 + 0xac) = 0;
        }
        DVar2 = local_70;
        FUN_40b64a98(local_20);
      }
    }
  }
  return DVar2;
}



/* 40b5b340 FUN_40b5b340 */

/* Boundary evidence: original MIPS .pdata 40b5b340..40b5b36f. Semantic name remains unreviewed. */

void FUN_40b5b340(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x6c));
  return;
}



/* 40b5b370 FUN_40b5b370 */

/* Boundary evidence: original MIPS .pdata 40b5b370..40b5b433. Semantic name remains unreviewed. */

void FUN_40b5b370(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &PTR_FUN_40b67a04;
  param_1[3] = &PTR_FUN_40b679bc;
  param_1[4] = &PTR_LAB_40b679a8;
  if (param_1[0x2e] != 0) {
    do {
      pvVar1 = (void *)FUN_40b626a8(param_1 + 0x2c);
      if (pvVar1 != (void *)0x0) {
        FUN_40b5f15c((int)pvVar1);
        operator_delete(pvVar1);
      }
    } while (param_1[0x2e] != 0);
  }
  FUN_40b62660(param_1 + 0x2c);
  FUN_40b5fa14((int)param_1);
  return;
}



/* 40b5b434 FUN_40b5b434 */

/* Boundary evidence: original MIPS .pdata 40b5b434..40b5b463. Semantic name remains unreviewed. */

void FUN_40b5b434(void)

{
  int *in_v0;
  
  FUN_40b59bc8(*in_v0);
  return;
}



/* 40b5b464 FUN_40b5b464 */

/* Boundary evidence: original MIPS .pdata 40b5b464..40b5b497. Semantic name remains unreviewed. */

void FUN_40b5b464(void)

{
  int *in_v0;
  
  FUN_40b59be4((undefined4 *)(*in_v0 + 0xb0));
  return;
}



/* 40b5b498 FUN_40b5b498 */

/* Boundary evidence: original MIPS .pdata 40b5b498..40b5b517. Semantic name remains unreviewed. */

undefined4 FUN_40b5b498(int param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + 0xb0);
  do {
    if (local_18[0] == 0) {
      return 1;
    }
    pvVar1 = (void *)FUN_40b6243c((int *)(param_1 + 0xb0),local_18);
    iVar2 = FUN_40b5f2c8(pvVar1,param_2);
  } while (iVar2 == 0);
  return 0;
}



/* 40b5b518 FUN_40b5b518 */

/* Boundary evidence: original MIPS .pdata 40b5b518..40b5b59b. Semantic name remains unreviewed. */

undefined4 FUN_40b5b518(int param_1,int param_2,void *param_3)

{
  bool bVar1;
  void *pvVar2;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + 0xb0);
  do {
    if (local_18[0] == 0) {
      return 0x40103;
    }
    pvVar2 = (void *)FUN_40b6243c((int *)(param_1 + 0xb0),local_18);
    bVar1 = param_2 != 0;
    param_2 = param_2 + -1;
  } while (bVar1);
  FUN_40b5f29c(param_3,pvVar2);
  return 0;
}



/* 40b5b59c FUN_40b5b59c */

/* Boundary evidence: original MIPS .pdata 40b5b59c..40b5b647. Semantic name remains unreviewed. */

undefined4 FUN_40b5b59c(int param_1,void *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  pvVar1 = operator_new(0x48);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = FUN_40b5f224(pvVar1,param_2);
  }
  if (pvVar1 != (void *)0x0) {
    puVar2 = FUN_40b62564((undefined4 *)(param_1 + 0xb0),pvVar1);
    if (puVar2 != (undefined4 *)0x0) {
      return 0;
    }
    FUN_40b5f15c((int)pvVar1);
    operator_delete(pvVar1);
  }
  return 0x8007000e;
}



/* 40b5b648 FUN_40b5b648 */

/* Boundary evidence: original MIPS .pdata 40b5b648..40b5b677. Semantic name remains unreviewed. */

void FUN_40b5b648(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40b5b678 FUN_40b5b678 */

/* Boundary evidence: original MIPS .pdata 40b5b678..40b5b78f. Semantic name remains unreviewed. */

undefined4 *
FUN_40b5b678(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  FUN_40b61cdc(param_1,param_2,param_3,(LPCRITICAL_SECTION)(param_1 + 0x1b),param_4);
  *param_1 = &PTR_FUN_40b67bd8;
  param_1[3] = &PTR_FUN_40b67b9c;
  param_1[4] = &PTR_LAB_40b67b88;
  param_1[0x14] = 0;
  FUN_40b623c4(param_1 + 0x15);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1b));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2a));
  param_1[0x2f] = 0;
  param_1[0x30] = 0x7b785574;
  param_1[0x31] = 0x11cf8c82;
  param_1[0x32] = 0xaa000cbc;
  param_1[0x33] = 0xf674ac00;
  param_1[0x34] = &PTR_FUN_40b67988;
  param_1[0x35] = param_1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 1;
  return param_1;
}



/* 40b5b790 FUN_40b5b790 */

/* Boundary evidence: original MIPS .pdata 40b5b790..40b5b7bf. Semantic name remains unreviewed. */

void FUN_40b5b790(void)

{
  int *in_v0;
  
  FUN_40b609e4(*in_v0);
  return;
}



/* 40b5b7c0 FUN_40b5b7c0 */

/* Boundary evidence: original MIPS .pdata 40b5b7c0..40b5b7e7. Semantic name remains unreviewed. */

void FUN_40b5b7c0(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b5b7e8 FUN_40b5b7e8 */

/* Boundary evidence: original MIPS .pdata 40b5b7e8..40b5b80f. Semantic name remains unreviewed. */

void FUN_40b5b7e8(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b5b810 FUN_40b5b810 */

/* Boundary evidence: original MIPS .pdata 40b5b810..40b5b837. Semantic name remains unreviewed. */

void FUN_40b5b810(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b5b874 FUN_40b5b874 */

/* Boundary evidence: original MIPS .pdata 40b5b874..40b5b973. Semantic name remains unreviewed. */

undefined4 FUN_40b5b874(int param_1)

{
  int *piVar1;
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
      piVar1 = (int *)FUN_40b6243c((int *)(param_1 + 0x48),&local_28);
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
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    *(undefined4 *)(param_1 + 8) = 1;
  }
  LeaveCriticalSection(lpCriticalSection_00);
  return 0;
}



/* 40b5b974 FUN_40b5b974 */

/* Boundary evidence: original MIPS .pdata 40b5b974..40b5b9a3. Semantic name remains unreviewed. */

void FUN_40b5b974(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b5b9a4 FUN_40b5b9a4 */

/* Boundary evidence: original MIPS .pdata 40b5b9a4..40b5b9d3. Semantic name remains unreviewed. */

void FUN_40b5b9a4(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b5b9d4 FUN_40b5b9d4 */

/* Boundary evidence: original MIPS .pdata 40b5b9d4..40b5bad3. Semantic name remains unreviewed. */

undefined4 FUN_40b5b9d4(int param_1)

{
  int *piVar1;
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
    local_28 = *(int *)(param_1 + 0x48);
    while (local_28 != 0) {
      piVar1 = (int *)FUN_40b6243c((int *)(param_1 + 0x48),&local_28);
      if (piVar1[6] != 0) {
        (**(code **)(*piVar1 + 0x18))(piVar1);
      }
    }
    *(undefined4 *)(param_1 + 8) = 0;
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* 40b5bad4 FUN_40b5bad4 */

/* Boundary evidence: original MIPS .pdata 40b5bad4..40b5bb03. Semantic name remains unreviewed. */

void FUN_40b5bad4(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b5bb04 FUN_40b5bb04 */

/* Boundary evidence: original MIPS .pdata 40b5bb04..40b5bb33. Semantic name remains unreviewed. */

void FUN_40b5bb04(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b5bb34 FUN_40b5bb34 */

/* Boundary evidence: original MIPS .pdata 40b5bb34..40b5bb8f. Semantic name remains unreviewed. */

int FUN_40b5bb34(int param_1)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa8));
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x5c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa8));
  return (uint)(iVar1 != 0) + iVar2;
}



/* 40b5bb90 FUN_40b5bb90 */

/* Boundary evidence: original MIPS .pdata 40b5bb90..40b5bc8f. Semantic name remains unreviewed. */

int FUN_40b5bb90(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_20;
  LPCRITICAL_SECTION local_1c;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa8);
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
        FUN_40b6243c(piVar1,&local_20);
      }
      iVar2 = FUN_40b6243c(piVar1,&local_20);
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar2;
}



/* 40b5bc90 FUN_40b5bc90 */

/* Boundary evidence: original MIPS .pdata 40b5bc90..40b5bcbf. Semantic name remains unreviewed. */

void FUN_40b5bc90(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40b5bcc0 FUN_40b5bcc0 */

/* Boundary evidence: original MIPS .pdata 40b5bcc0..40b5bd9f. Semantic name remains unreviewed. */

bool FUN_40b5bcc0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0xa8);
  EnterCriticalSection(lpCriticalSection_00);
  FUN_40b5f694(param_1);
  (**(code **)(param_2[3] + 4))();
  puVar1 = FUN_40b62564((undefined4 *)(param_1 + 0x54),param_2);
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



/* 40b5bda0 FUN_40b5bda0 */

/* Boundary evidence: original MIPS .pdata 40b5bda0..40b5bdcf. Semantic name remains unreviewed. */

void FUN_40b5bda0(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b5bdd0 FUN_40b5bdd0 */

/* Boundary evidence: original MIPS .pdata 40b5bdd0..40b5bdff. Semantic name remains unreviewed. */

void FUN_40b5bdd0(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40b5be00 FUN_40b5be00 */

/* Boundary evidence: original MIPS .pdata 40b5be00..40b5befb. Semantic name remains unreviewed. */

void FUN_40b5be00(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa8));
  iVar1 = FUN_40b626a8((int *)(param_1 + 0x54));
  while (iVar1 != 0) {
    FUN_40b5f694(param_1);
    if (*(int **)(iVar1 + 0x18) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x18) + 0x14))();
      (**(code **)(*(int *)(iVar1 + 0xc) + 0x14))();
    }
    (**(code **)(*(int *)(iVar1 + 0xc) + 8))();
    iVar1 = FUN_40b626a8((int *)(param_1 + 0x54));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa8));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return;
}



/* 40b5befc FUN_40b5befc */

/* Boundary evidence: original MIPS .pdata 40b5befc..40b5bf2b. Semantic name remains unreviewed. */

void FUN_40b5befc(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40b5bf2c FUN_40b5bf2c */

/* Boundary evidence: original MIPS .pdata 40b5bf2c..40b5bf5b. Semantic name remains unreviewed. */

void FUN_40b5bf2c(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b5bf5c FUN_40b5bf5c */

/* Boundary evidence: original MIPS .pdata 40b5bf5c..40b5c073. Semantic name remains unreviewed. */

int FUN_40b5bf5c(int param_1,wchar_t *param_2,int *param_3)

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
    piVar2 = FUN_40b5af9c(local_1c,param_1,&local_20,param_2);
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
    bVar1 = FUN_40b5bcc0(param_1,piVar2);
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



/* 40b5c074 FUN_40b5c074 */

/* Boundary evidence: original MIPS .pdata 40b5c074..40b5c0a3. Semantic name remains unreviewed. */

void FUN_40b5c074(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x1c));
  return;
}



/* 40b5c0a4 FUN_40b5c0a4 */

/* Boundary evidence: original MIPS .pdata 40b5c0a4..40b5c0bf. Semantic name remains unreviewed. */

void FUN_40b5c0a4(int *param_1,undefined4 param_2)

{
  FUN_40b5a250(param_1,param_2);
  return;
}



/* 40b5c0c0 FUN_40b5c0c0 */

/* Boundary evidence: original MIPS .pdata 40b5c0c0..40b5c11f. Semantic name remains unreviewed. */

void FUN_40b5c0c0(int param_1)

{
  int *piVar1;
  int local_10 [2];
  
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40b6243c((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x4c))(piVar1);
    }
  }
  return;
}



/* 40b5c120 FUN_40b5c120 */

/* Boundary evidence: original MIPS .pdata 40b5c120..40b5c183. Semantic name remains unreviewed. */

undefined4 FUN_40b5c120(int param_1)

{
  int *piVar1;
  int local_10 [2];
  
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40b6243c((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x50))(piVar1);
    }
  }
  return 0;
}



/* 40b5c184 FUN_40b5c184 */

/* Boundary evidence: original MIPS .pdata 40b5c184..40b5c1e7. Semantic name remains unreviewed. */

undefined4 FUN_40b5c184(int param_1)

{
  int *piVar1;
  int local_10 [2];
  
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40b6243c((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x54))(piVar1);
    }
  }
  return 0;
}



/* 40b5c1e8 FUN_40b5c1e8 */

/* Boundary evidence: original MIPS .pdata 40b5c1e8..40b5c28b. Semantic name remains unreviewed. */

void FUN_40b5c1e8(int param_1)

{
  undefined4 *puVar1;
  
  if (DAT_40b6bfb0 != (int *)0x0) {
    (**(code **)(*DAT_40b6bfb0 + 8))();
    DAT_40b6bfb0 = (int *)0x0;
    DAT_40b6bfb4 = 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0xbc);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    *(undefined4 *)(param_1 + 0xbc) = 0;
  }
  FUN_40b5be00(param_1);
  if (*(int **)(param_1 + 0xf0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xf0) + 8))();
    *(undefined4 *)(param_1 + 0xf0) = 0;
  }
  return;
}



/* 40b5c28c FUN_40b5c28c */

/* Boundary evidence: original MIPS .pdata 40b5c28c..40b5c3ff. Semantic name remains unreviewed. */

undefined4 FUN_40b5c28c(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_28;
  LPCRITICAL_SECTION local_24;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x94);
  local_24 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(param_1 + 0x50);
  piVar4 = *(int **)(iVar3 + 0x11c);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))();
  }
  local_28 = *(int *)(param_1 + 0x54);
  piVar4 = *(int **)(iVar3 + 0x11c);
  while (local_28 != 0) {
    piVar1 = (int *)FUN_40b6243c((int *)(param_1 + 0x54),&local_28);
    if (piVar1[6] != 0) {
      iVar3 = *piVar1;
      __litodp(*(undefined4 *)(param_1 + 0x108));
      (**(code **)(iVar3 + 0x58))(piVar1);
    }
  }
  (**(code **)(**(int **)(param_1 + 0xbc) + 0x1c))
            (*(int **)(param_1 + 0xbc),piVar4,*(undefined4 *)(param_1 + 0xf8),
             *(undefined4 *)(param_1 + 0xfc),*(undefined4 *)(param_1 + 0x100),
             *(undefined4 *)(param_1 + 0x104));
  piVar1 = *(int **)(param_1 + 0xbc);
  iVar3 = *piVar1;
  __litodp(*(undefined4 *)(param_1 + 0x108));
  uVar2 = (**(code **)(iVar3 + 0x20))(piVar1);
  (**(code **)(*piVar4 + 8))(piVar4);
  LeaveCriticalSection(lpCriticalSection);
  return uVar2;
}



/* 40b5c400 FUN_40b5c400 */

/* Boundary evidence: original MIPS .pdata 40b5c400..40b5c42f. Semantic name remains unreviewed. */

void FUN_40b5c400(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b5c430 FUN_40b5c430 */

/* Boundary evidence: original MIPS .pdata 40b5c430..40b5c4bf. Semantic name remains unreviewed. */

undefined4
FUN_40b5c430(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd8));
  *(undefined4 *)(param_1 + 0xf8) = param_3;
  *(undefined4 *)(param_1 + 0xfc) = param_4;
  *(undefined4 *)(param_1 + 0x100) = param_5;
  *(undefined4 *)(param_1 + 0x104) = param_6;
  FUN_40b5ac78(*(int **)(param_1 + 0x50));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd8));
  return 0;
}



/* 40b5c4c0 FUN_40b5c4c0 */

/* Boundary evidence: original MIPS .pdata 40b5c4c0..40b5c4ef. Semantic name remains unreviewed. */

void FUN_40b5c4c0(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b5c4f0 FUN_40b5c4f0 */

/* Boundary evidence: original MIPS .pdata 40b5c4f0..40b5c587. Semantic name remains unreviewed. */

undefined4 FUN_40b5c4f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd8));
  piVar2 = *(int **)(param_1 + 0x50);
  uVar1 = __dptoli(param_3,param_4);
  *(undefined4 *)(param_1 + 0x108) = uVar1;
  FUN_40b5ad34(piVar2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd8));
  return 0;
}



/* 40b5c588 FUN_40b5c588 */

/* Boundary evidence: original MIPS .pdata 40b5c588..40b5c5b7. Semantic name remains unreviewed. */

void FUN_40b5c588(void)

{
  int in_v0;
  
  FUN_40b532dc((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40b5c5b8 FUN_40b5c5b8 */

/* Boundary evidence: original MIPS .pdata 40b5c5b8..40b5c603. Semantic name remains unreviewed. */

void * FUN_40b5c5b8(void *param_1,uint param_2)

{
  FUN_40b5a79c((int)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b5c604 FUN_40b5c604 */

/* Boundary evidence: original MIPS .pdata 40b5c604..40b5c68b. Semantic name remains unreviewed. */

int FUN_40b5c604(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  iVar1 = FUN_40b5fd48();
  if (iVar1 < 0) {
    FUN_40b53210(0x40b67ea8,param_2,param_3,param_4);
  }
  else {
    iVar1 = FUN_40b5c28c(*(int *)(param_1 + 0x70));
    if (iVar1 < 0) {
      FUN_40b53210(0x40b67ef8,iVar1,param_3,param_4);
    }
    else {
      FUN_40b5386c((LPVOID)(param_1 + 0xdc));
    }
  }
  return iVar1;
}



/* 40b5c68c FUN_40b5c68c */

/* Boundary evidence: original MIPS .pdata 40b5c68c..40b5c6a7. Semantic name remains unreviewed. */

void FUN_40b5c68c(int param_1,wchar_t *param_2,int *param_3)

{
  FUN_40b5bf5c(*(int *)(param_1 + 4),param_2,param_3);
  return;
}



/* 40b5c6a8 FUN_40b5c6a8 */

/* Boundary evidence: original MIPS .pdata 40b5c6a8..40b5c6c3. Semantic name remains unreviewed. */

void FUN_40b5c6a8(int param_1,void *param_2)

{
  FUN_40b5b59c(*(int *)(param_1 + 4),param_2);
  return;
}



/* 40b5c6c4 FUN_40b5c6c4 */

/* Boundary evidence: original MIPS .pdata 40b5c6c4..40b5c70f. Semantic name remains unreviewed. */

undefined4 * FUN_40b5c6c4(undefined4 *param_1,uint param_2)

{
  FUN_40b5b370(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b5c710 FUN_40b5c710 */

/* Boundary evidence: original MIPS .pdata 40b5c710..40b5c7d3. Semantic name remains unreviewed. */

void FUN_40b5c710(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40b67bd8;
  param_1[3] = &PTR_FUN_40b67b9c;
  param_1[4] = &PTR_LAB_40b67b88;
  piVar1 = (int *)param_1[0x14];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
  }
  param_1[0x14] = 0;
  FUN_40b5be00((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2a));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1b));
  FUN_40b62660(param_1 + 0x15);
  FUN_40b609e4((int)param_1);
  return;
}



/* 40b5c7d4 FUN_40b5c7d4 */

/* Boundary evidence: original MIPS .pdata 40b5c7d4..40b5c803. Semantic name remains unreviewed. */

void FUN_40b5c7d4(void)

{
  int *in_v0;
  
  FUN_40b609e4(*in_v0);
  return;
}



/* 40b5c804 FUN_40b5c804 */

/* Boundary evidence: original MIPS .pdata 40b5c804..40b5c837. Semantic name remains unreviewed. */

void FUN_40b5c804(void)

{
  int *in_v0;
  
  FUN_40b59e28((undefined4 *)(*in_v0 + 0x54));
  return;
}



/* 40b5c838 FUN_40b5c838 */

/* Boundary evidence: original MIPS .pdata 40b5c838..40b5c86b. Semantic name remains unreviewed. */

void FUN_40b5c838(void)

{
  int *in_v0;
  
  FUN_40b59ab8((LPCRITICAL_SECTION)(*in_v0 + 0x6c));
  return;
}



/* 40b5c86c FUN_40b5c86c */

/* Boundary evidence: original MIPS .pdata 40b5c86c..40b5c89f. Semantic name remains unreviewed. */

void FUN_40b5c86c(void)

{
  int *in_v0;
  
  FUN_40b59ab8((LPCRITICAL_SECTION)(*in_v0 + 0x80));
  return;
}



/* 40b5c8a0 FUN_40b5c8a0 */

/* Boundary evidence: original MIPS .pdata 40b5c8a0..40b5c8d3. Semantic name remains unreviewed. */

void FUN_40b5c8a0(void)

{
  int *in_v0;
  
  FUN_40b59ab8((LPCRITICAL_SECTION)(*in_v0 + 0x94));
  return;
}



/* 40b5c8d4 FUN_40b5c8d4 */

/* Boundary evidence: original MIPS .pdata 40b5c8d4..40b5c907. Semantic name remains unreviewed. */

void FUN_40b5c8d4(void)

{
  int *in_v0;
  
  FUN_40b59ab8((LPCRITICAL_SECTION)(*in_v0 + 0xa8));
  return;
}



/* 40b5c908 FUN_40b5c908 */

/* Boundary evidence: original MIPS .pdata 40b5c908..40b5c93b. Semantic name remains unreviewed. */

void FUN_40b5c908(void)

{
  int *in_v0;
  
  FUN_40b59ab8((LPCRITICAL_SECTION)(*in_v0 + 0xd8));
  return;
}



/* 40b5c93c FUN_40b5c93c */

/* Boundary evidence: original MIPS .pdata 40b5c93c..40b5c987. Semantic name remains unreviewed. */

undefined4 * FUN_40b5c93c(undefined4 *param_1,uint param_2)

{
  FUN_40b5c710(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b5c988 FUN_40b5c988 */

/* Boundary evidence: original MIPS .pdata 40b5c988..40b5c9a3. Semantic name remains unreviewed. */

void FUN_40b5c988(HMODULE param_1,int param_2)

{
  FUN_40b637cc(param_1,param_2);
  return;
}



/* 40b5c9a4 DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40b5c9a4..40b5c9bf. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0xc9a4  3  DllRegisterServer */
  FUN_40b644d4(1);
  return;
}



/* 40b5c9c0 DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40b5c9c0..40b5c9db. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0xc9c0  4  DllUnregisterServer */
  FUN_40b644d4(0);
  return;
}



/* 40b5c9dc FUN_40b5c9dc */

/* Boundary evidence: original MIPS .pdata 40b5c9dc..40b5caaf. Semantic name remains unreviewed. */

void FUN_40b5c9dc(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_40b686e0;
  param_1[3] = &PTR_FUN_40b686a4;
  param_1[4] = &PTR_LAB_40b68690;
  param_1[0x44] = &PTR_LAB_40b68678;
  puVar1 = (undefined4 *)param_1[0x2f];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    param_1[0x2f] = 0;
  }
  piVar2 = (int *)param_1[0x14];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,1);
    param_1[0x14] = 0;
  }
  piVar2 = (int *)param_1[0x3b];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,1);
    param_1[0x3b] = 0;
  }
  FUN_40b5c710(param_1);
  return;
}



/* 40b5cab0 FUN_40b5cab0 */

/* Boundary evidence: original MIPS .pdata 40b5cab0..40b5cadf. Semantic name remains unreviewed. */

void FUN_40b5cab0(void)

{
  undefined4 *in_v0;
  
  FUN_40b5c710((undefined4 *)*in_v0);
  return;
}



/* 40b5cae0 FUN_40b5cae0 */

/* Boundary evidence: original MIPS .pdata 40b5cae0..40b5cb07. Semantic name remains unreviewed. */

void FUN_40b5cae0(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b5cb08 FUN_40b5cb08 */

/* Boundary evidence: original MIPS .pdata 40b5cb08..40b5cb2f. Semantic name remains unreviewed. */

void FUN_40b5cb08(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b5cb30 FUN_40b5cb30 */

/* Boundary evidence: original MIPS .pdata 40b5cb30..40b5cb57. Semantic name remains unreviewed. */

void FUN_40b5cb30(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b5cb58 FUN_40b5cb58 */

/* Boundary evidence: original MIPS .pdata 40b5cb58..40b5cc6f. Semantic name remains unreviewed. */

void FUN_40b5cb58(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b69018,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x44;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b627e4(piVar2,param_3);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b68cf8,0x10);
    if ((((iVar1 == 0) && (param_1[0x3b] != 0)) ||
        ((iVar1 = memcmp(param_2,&DAT_40b6a698,0x10), iVar1 == 0 && (param_1[0x3b] != 0)))) ||
       ((iVar1 = memcmp(param_2,&DAT_40b6aaa4,0x10), iVar1 == 0 && (param_1[0x3b] != 0)))) {
      (*(code *)**(undefined4 **)param_1[0x3b])((undefined4 *)param_1[0x3b],param_2,param_3);
    }
    else {
      FUN_40b60904(param_1,param_2,param_3);
    }
  }
  return;
}



/* 40b5cc70 FUN_40b5cc70 */

/* Boundary evidence: original MIPS .pdata 40b5cc70..40b5cdcb. Semantic name remains unreviewed. */

undefined4 FUN_40b5cc70(undefined4 param_1,void *param_2)

{
  int iVar1;
  void *_Buf1;
  
  iVar1 = memcmp(param_2,&DAT_40b6aa94,0x10);
  if ((iVar1 == 0) && (iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40b6aa94,0x10), iVar1 == 0)
     ) {
    return 0;
  }
  iVar1 = memcmp(param_2,&DAT_40b692e8,0x10);
  if (iVar1 == 0) {
    _Buf1 = (void *)((int)param_2 + 0x10);
    iVar1 = memcmp(_Buf1,&DAT_40b695e8,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40b695d8,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40b695b8,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40b68248,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40b69688,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40b696a8,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40b6aa94,0x10);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



/* 40b5cdcc FUN_40b5cdcc */

/* Boundary evidence: original MIPS .pdata 40b5cdcc..40b5ce0f. Semantic name remains unreviewed. */

undefined4 FUN_40b5cdcc(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x2c))();
  return uVar1;
}



/* 40b5ce10 FUN_40b5ce10 */

/* Boundary evidence: original MIPS .pdata 40b5ce10..40b5ce53. Semantic name remains unreviewed. */

undefined4 FUN_40b5ce10(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x30))();
  return uVar1;
}



/* 40b5ce54 FUN_40b5ce54 */

/* Boundary evidence: original MIPS .pdata 40b5ce54..40b5cebb. Semantic name remains unreviewed. */

undefined4 FUN_40b5ce54(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x34))();
  return uVar1;
}



/* 40b5cebc FUN_40b5cebc */

/* Boundary evidence: original MIPS .pdata 40b5cebc..40b5ced7. Semantic name remains unreviewed. */

void FUN_40b5cebc(int param_1)

{
  FUN_40b60e04(param_1);
  return;
}



/* 40b5ced8 FUN_40b5ced8 */

/* Boundary evidence: original MIPS .pdata 40b5ced8..40b5cef3. Semantic name remains unreviewed. */

void FUN_40b5ced8(int param_1)

{
  FUN_40b60ed8(param_1);
  return;
}



/* 40b5cef4 FUN_40b5cef4 */

/* Boundary evidence: original MIPS .pdata 40b5cef4..40b5cf53. Semantic name remains unreviewed. */

undefined4 * FUN_40b5cef4(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x58);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40b58158(puVar1,param_2);
  }
  return puVar1;
}



/* 40b5cf54 FUN_40b5cf54 */

/* Boundary evidence: original MIPS .pdata 40b5cf54..40b5cf83. Semantic name remains unreviewed. */

void FUN_40b5cf54(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40b5cffc FUN_40b5cffc */

/* Boundary evidence: original MIPS .pdata 40b5cffc..40b5d0cb. Semantic name remains unreviewed. */

undefined4 * FUN_40b5cffc(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  FUN_40b5b678(param_1,L"CPTDemuxFilter",param_2,&DAT_40b681a8);
  *param_1 = &PTR_FUN_40b686e0;
  param_1[3] = &PTR_FUN_40b686a4;
  param_1[4] = &PTR_LAB_40b68690;
  param_1[0x44] = &PTR_LAB_40b68678;
  puVar1 = operator_new(0x130);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40b5a5cc(puVar1,(int)param_1,param_3);
  }
  param_1[0x14] = puVar1;
  return param_1;
}



/* 40b5d0cc FUN_40b5d0cc */

/* Boundary evidence: original MIPS .pdata 40b5d0cc..40b5d0fb. Semantic name remains unreviewed. */

void FUN_40b5d0cc(void)

{
  undefined4 *in_v0;
  
  FUN_40b5c710((undefined4 *)*in_v0);
  return;
}



/* 40b5d0fc FUN_40b5d0fc */

/* Boundary evidence: original MIPS .pdata 40b5d0fc..40b5d12b. Semantic name remains unreviewed. */

void FUN_40b5d0fc(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40b5d12c FUN_40b5d12c */

/* Boundary evidence: original MIPS .pdata 40b5d12c..40b5d177. Semantic name remains unreviewed. */

undefined4 * FUN_40b5d12c(undefined4 *param_1,uint param_2)

{
  FUN_40b5c9dc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b5d178 FUN_40b5d178 */

/* Boundary evidence: original MIPS .pdata 40b5d178..40b5d1e7. Semantic name remains unreviewed. */

undefined4 * FUN_40b5d178(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x118);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40b5cffc(puVar1,param_1,param_2);
  }
  return puVar1;
}



/* 40b5d1e8 FUN_40b5d1e8 */

/* Boundary evidence: original MIPS .pdata 40b5d1e8..40b5d217. Semantic name remains unreviewed. */

void FUN_40b5d1e8(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40b5d218 FUN_40b5d218 */

/* Boundary evidence: original MIPS .pdata 40b5d218..40b5d24f. Semantic name remains unreviewed. */

void FUN_40b5d218(int param_1)

{
  if (param_1 != 0) {
    FUN_40b626f4();
    return;
  }
  FUN_40b626f4();
  return;
}



/* 40b5d250 FUN_40b5d250 */

/* Boundary evidence: original MIPS .pdata 40b5d250..40b5d2bf. Semantic name remains unreviewed. */

void FUN_40b5d250(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40b688c8;
  param_1[3] = &PTR_FUN_40b68878;
  param_1[4] = &PTR_LAB_40b68840;
  FUN_40b64508(param_1 + 0xf);
  FUN_40b626f4();
  return;
}



/* 40b5d2c0 FUN_40b5d2c0 */

/* Boundary evidence: original MIPS .pdata 40b5d2c0..40b5d2ef. Semantic name remains unreviewed. */

void FUN_40b5d2c0(void)

{
  int *in_v0;
  
  FUN_40b5d218(*in_v0);
  return;
}



/* 40b5d2f0 FUN_40b5d2f0 */

/* Boundary evidence: original MIPS .pdata 40b5d2f0..40b5d317. Semantic name remains unreviewed. */

void FUN_40b5d2f0(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b5d318 FUN_40b5d318 */

/* Boundary evidence: original MIPS .pdata 40b5d318..40b5d33f. Semantic name remains unreviewed. */

void FUN_40b5d318(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b5d340 FUN_40b5d340 */

/* Boundary evidence: original MIPS .pdata 40b5d340..40b5d367. Semantic name remains unreviewed. */

void FUN_40b5d340(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b5d368 FUN_40b5d368 */

/* Boundary evidence: original MIPS .pdata 40b5d368..40b5d457. Semantic name remains unreviewed. */

void FUN_40b5d368(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b68cf8,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b627e4(piVar2,param_3);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b6a698,0x10);
    if (iVar1 == 0) {
      piVar2 = param_1 + 4;
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      FUN_40b627e4(piVar2,param_3);
    }
    else {
      iVar1 = memcmp(param_2,&DAT_40b6aaa4,0x10);
      if (iVar1 == 0) {
        piVar2 = param_1 + 4;
        if (param_1 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        FUN_40b627e4(piVar2,param_3);
      }
      else {
        FUN_40b62880(param_1,param_2,param_3);
      }
    }
  }
  return;
}



/* 40b5d458 FUN_40b5d458 */

/* Boundary evidence: original MIPS .pdata 40b5d458..40b5d4a3. Semantic name remains unreviewed. */

bool FUN_40b5d458(int *param_1,uint *param_2)

{
  uint local_10 [2];
  
  (**(code **)(*param_1 + 0xc))(param_1,local_10);
  return (~local_10[0] & *param_2) != 0;
}



/* 40b5d4cc FUN_40b5d4cc */

/* Boundary evidence: original MIPS .pdata 40b5d4cc..40b5d55b. Semantic name remains unreviewed. */

undefined4 FUN_40b5d4cc(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 auStack_20 [16];
  uint local_10;
  
  local_10 = DAT_40b6bf1c;
  if (param_2 == (int *)0x0) {
    param_2 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,auStack_20);
  if ((-1 < iVar1) && (iVar1 = memcmp(auStack_20,param_2,0x10), iVar1 == 0)) {
    FUN_40b64a98(local_10);
    return 0;
  }
  FUN_40b64a98(local_10);
  return 1;
}



/* 40b5d55c FUN_40b5d55c */

/* Boundary evidence: original MIPS .pdata 40b5d55c..40b5d5bb. Semantic name remains unreviewed. */

undefined4 FUN_40b5d55c(int param_1,int *param_2)

{
  if (*(int *)(param_1 + 0x24) == 0 && *(int *)(param_1 + 0x28) == 0) {
    FUN_40b5a450(*(int *)(param_1 + 0x2c));
  }
  *param_2 = *(int *)(param_1 + 0x24);
  param_2[1] = *(int *)(param_1 + 0x28);
  return 0;
}



/* 40b5d5bc FUN_40b5d5bc */

/* Boundary evidence: original MIPS .pdata 40b5d5bc..40b5d5f3. Semantic name remains unreviewed. */

undefined4 FUN_40b5d5bc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0x80004003;
  }
  uVar1 = FUN_40b5a478(*(int *)(param_1 + 0x2c));
  return uVar1;
}



/* 40b5d61c FUN_40b5d61c */

/* Boundary evidence: original MIPS .pdata 40b5d61c..40b5d63f. Semantic name remains unreviewed. */

void FUN_40b5d61c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  FUN_40b5c4f0(*(int *)(param_1 + 0x2c),param_2,param_3,param_4);
  return;
}



/* 40b5d680 FUN_40b5d680 */

/* Boundary evidence: original MIPS .pdata 40b5d680..40b5d6d3. Semantic name remains unreviewed. */

undefined4 FUN_40b5d680(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b5a514(*(int *)(param_1 + 0x28));
  if (iVar1 != 0) {
    *param_2 = 1;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



/* 40b5d6d4 FUN_40b5d6d4 */

/* Boundary evidence: original MIPS .pdata 40b5d6d4..40b5d6fb. Semantic name remains unreviewed. */

void FUN_40b5d6d4(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0x44))();
  return;
}



/* 40b5d6fc FUN_40b5d6fc */

/* Boundary evidence: original MIPS .pdata 40b5d6fc..40b5d723. Semantic name remains unreviewed. */

void FUN_40b5d6fc(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0x48))();
  return;
}



/* 40b5d724 FUN_40b5d724 */

/* Boundary evidence: original MIPS .pdata 40b5d724..40b5d73f. Semantic name remains unreviewed. */

void FUN_40b5d724(int param_1,undefined4 *param_2)

{
  FUN_40b64538(param_1 + 0x2c,param_2);
  return;
}



/* 40b5d740 FUN_40b5d740 */

/* Boundary evidence: original MIPS .pdata 40b5d740..40b5d76f. Semantic name remains unreviewed. */

void FUN_40b5d740(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  FUN_40b64560((int *)(param_1 + 0x2c),&DAT_40b68cf8,param_2,param_3,param_4);
  return;
}



/* 40b5d770 FUN_40b5d770 */

/* Boundary evidence: original MIPS .pdata 40b5d770..40b5d7a3. Semantic name remains unreviewed. */

void FUN_40b5d770(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_40b646fc((int *)(param_1 + 0x2c),&DAT_40b68cf8,param_3,param_4,param_5,param_6);
  return;
}



/* 40b5d7a4 FUN_40b5d7a4 */

/* Boundary evidence: original MIPS .pdata 40b5d7a4..40b5d88b. Semantic name remains unreviewed. */

int FUN_40b5d7a4(int *param_1,undefined4 param_2,void *param_3,undefined4 param_4,undefined2 param_5
                ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int *piVar2;
  int *local_18 [2];
  
  iVar1 = memcmp(&DAT_40b6aa94,param_3,0x10);
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



/* 40b5d8c8 FUN_40b5d8c8 */

/* Boundary evidence: original MIPS .pdata 40b5d8c8..40b5d913. Semantic name remains unreviewed. */

undefined4 * FUN_40b5d8c8(undefined4 *param_1,uint param_2)

{
  FUN_40b5d250(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b5d914 FUN_40b5d914 */

/* Boundary evidence: original MIPS .pdata 40b5d914..40b5d967. Semantic name remains unreviewed. */

undefined4 FUN_40b5d914(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b5a514(*(int *)(param_1 + 0x2c));
  if (iVar1 != 0) {
    *param_2 = 0x37;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



/* 40b5d968 FUN_40b5d968 */

/* Boundary evidence: original MIPS .pdata 40b5d968..40b5d9db. Semantic name remains unreviewed. */

undefined4 FUN_40b5d968(int param_1,void *param_2)

{
  int iVar1;
  
  if (param_2 == (void *)0x0) {
    param_2 = (void *)(param_1 + 0x34);
  }
  iVar1 = FUN_40b5a514(*(int *)(param_1 + 0x2c));
  if ((iVar1 != 0) && (iVar1 = FUN_40b5a4a0(*(undefined4 *)(param_1 + 0x2c),param_2), iVar1 == 0)) {
    return 0;
  }
  return 1;
}



/* 40b5d9dc FUN_40b5d9dc */

/* Boundary evidence: original MIPS .pdata 40b5d9dc..40b5da5f. Semantic name remains unreviewed. */

undefined4 FUN_40b5d9dc(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40b5a514(*(int *)(param_1 + 0x2c));
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



/* 40b5da60 FUN_40b5da60 */

/* Boundary evidence: original MIPS .pdata 40b5da60..40b5dbb7. Semantic name remains unreviewed. */

undefined4 FUN_40b5da60(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    param_2 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,param_1 + 0xd,0x10);
    if (iVar1 != 0) {
      iVar1 = FUN_40b5a514(param_1[0xb]);
      if ((iVar1 == 0) || (iVar1 = FUN_40b5a4ec(param_1[0xb],param_2), iVar1 != 0)) {
        return 0x80004005;
      }
      (**(code **)(*param_1 + 0x34))(param_1,param_1 + 5,param_2);
      (**(code **)(*param_1 + 0x34))(param_1,param_1 + 7,param_2);
      param_1[0xd] = *param_2;
      param_1[0xe] = param_2[1];
      param_1[0xf] = param_2[2];
      param_1[0x10] = param_2[3];
      FUN_40b5fd48();
    }
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b6a3f8,0x10);
    if (iVar1 != 0) {
      return 0x80004001;
    }
  }
  return 0;
}



/* 40b5dbb8 FUN_40b5dbb8 */

/* Boundary evidence: original MIPS .pdata 40b5dbb8..40b5dc23. Semantic name remains unreviewed. */

undefined4 FUN_40b5dbb8(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b5a514(*(int *)(param_1 + 0x2c));
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



/* 40b5dc24 FUN_40b5dc24 */

/* Boundary evidence: original MIPS .pdata 40b5dc24..40b5de2b. Semantic name remains unreviewed. */

undefined4
FUN_40b5dc24(int *param_1,uint *param_2,int *param_3,undefined4 param_4,uint param_5,uint param_6,
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
  
  iVar1 = FUN_40b5a514(param_1[0xb]);
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
  FUN_40b5a450(param_1[0xb]);
  FUN_40b5a450(param_1[0xb]);
  if ((param_5 != local_20) || (uVar2 = local_28, uVar3 = local_24, param_6 != local_1c)) {
    if (param_5 == 0 && param_6 == 0) {
      uVar2 = 0;
      uVar3 = 0;
      goto LAB_40b5dd50;
    }
    if (((int)local_24 < (int)local_1c) || ((local_24 == local_1c && (local_28 <= local_20)))) {
      uVar2 = 0;
      uVar3 = 0;
    }
    else {
      uVar2 = local_20 - 1;
      uVar3 = local_1c - (local_20 == 0);
    }
    uVar2 = FUN_40b5e798(param_5,param_6,local_28,local_24,local_20,local_1c,uVar2,uVar3);
    uVar3 = extraout_v1;
  }
  if (((int)uVar3 < 1) && (uVar3 != 0)) {
    *param_2 = 0;
    param_2[1] = 0;
    return 0;
  }
LAB_40b5dd50:
  if (((int)local_24 <= (int)uVar3) && ((uVar3 != local_24 || (local_28 < uVar2)))) {
    uVar2 = local_28;
    uVar3 = local_24;
  }
  *param_2 = uVar2;
  param_2[1] = uVar3;
  return 0;
}



/* 40b5de2c FUN_40b5de2c */

/* Boundary evidence: original MIPS .pdata 40b5de2c..40b5df7f. Semantic name remains unreviewed. */

undefined4 FUN_40b5de2c(int *param_1,int *param_2,uint param_3,int *param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar3 = param_2;
  iVar1 = FUN_40b5a514(param_1[0xb]);
  if (iVar1 != 0) {
    iVar1 = param_1[7];
    iVar5 = param_1[8];
    uVar4 = param_3 & 3;
    if (uVar4 == 1) {
      iVar1 = *param_2;
      iVar5 = param_2[1];
    }
    else {
      if (uVar4 == 2) {
        return 0x80004001;
      }
      if (uVar4 == 3) {
        return 0x80004001;
      }
    }
    iVar6 = param_1[5];
    uVar4 = param_5 & 3;
    iVar7 = param_1[6];
    if ((uVar4 == 1) || ((uVar4 != 2 && (uVar4 != 3)))) {
      if ((param_3 & 8) != 0) {
        (**(code **)(*param_1 + 0x34))(param_1,param_2,&DAT_40b6a448);
        piVar3 = param_2;
      }
      if ((param_5 & 8) != 0) {
        (**(code **)(*param_1 + 0x34))(param_1,param_4,&DAT_40b6a448);
        piVar3 = param_4;
      }
      uVar2 = FUN_40b5c430(param_1[0xb],piVar3,iVar1,iVar5,iVar6,iVar7);
      return uVar2;
    }
  }
  return 0x80004001;
}



/* 40b5df80 FUN_40b5df80 */

/* Boundary evidence: original MIPS .pdata 40b5df80..40b5e00f. Semantic name remains unreviewed. */

undefined4 FUN_40b5df80(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_40b5a514(param_1[0xb]);
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



/* 40b5e010 FUN_40b5e010 */

/* Boundary evidence: original MIPS .pdata 40b5e010..40b5e123. Semantic name remains unreviewed. */

undefined4 * FUN_40b5e010(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  FUN_40b62788(param_1,0,param_3);
  param_1[3] = &PTR_FUN_40b68878;
  param_1[4] = &PTR_LAB_40b68840;
  *param_1 = &PTR_FUN_40b688c8;
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
  FUN_40b5a450(param_1[0xe]);
  iVar1 = param_1[0xc];
  if (iVar1 != 0 || param_1[0xd] != 0) {
    param_1[8] = iVar1;
    param_1[9] = param_1[0xd];
  }
  return param_1;
}



/* 40b5e124 FUN_40b5e124 */

/* Boundary evidence: original MIPS .pdata 40b5e124..40b5e153. Semantic name remains unreviewed. */

void FUN_40b5e124(void)

{
  int *in_v0;
  
  FUN_40b5d218(*in_v0);
  return;
}



/* 40b5e154 FUN_40b5e154 */

/* Boundary evidence: original MIPS .pdata 40b5e154..40b5e187. Semantic name remains unreviewed. */

void FUN_40b5e154(void)

{
  int *in_v0;
  
  FUN_40b64508((int *)(*in_v0 + 0x3c));
  return;
}



/* 40b5e188 FUN_40b5e188 */

/* Boundary evidence: original MIPS .pdata 40b5e188..40b5e2ff. Semantic name remains unreviewed. */

char * FUN_40b5e188(int *param_1,uint param_2)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  
  pcVar8 = (char *)*param_1;
  bVar3 = false;
  pcVar5 = pcVar8;
  if (param_2 != 0) {
    do {
      if (*pcVar5 != '\0') break;
      pcVar5 = pcVar5 + 1;
    } while ((uint)((int)pcVar5 - *param_1) < param_2);
  }
  uVar7 = (int)pcVar5 - (int)pcVar8;
  if ((((int)uVar7 < 2) || (param_2 < uVar7 + 2)) || (*pcVar5 != '\x01')) {
    return (char *)0xffffffff;
  }
  pcVar1 = pcVar5 + 1;
  pcVar4 = pcVar5 + -2;
  do {
    pcVar5 = pcVar5 + 2;
    iVar6 = 0;
    do {
      if ((1 < iVar6) && (*pcVar5 == '\x01')) goto LAB_40b5e254;
      iVar6 = iVar6 + 1;
      if (*pcVar5 != '\0') {
        iVar6 = 0;
      }
      pcVar5 = pcVar5 + 1;
    } while (uVar7 < param_2);
    bVar3 = true;
LAB_40b5e254:
    if (((bVar3) || (cVar2 = pcVar5[1], *pcVar1 != '\r')) ||
       ((cVar2 == '\r' || (((cVar2 == '\x0f' || (cVar2 == '\x0e')) || (cVar2 == '\n')))))) {
      if (param_2 <= (uint)((int)pcVar5 - (int)pcVar8)) {
        do {
          pcVar5 = pcVar5 + -1;
        } while (*pcVar5 == '\0');
        *param_1 = (int)pcVar4;
        return pcVar5 + (1 - (int)pcVar8);
      }
      do {
        pcVar5 = pcVar5 + -1;
      } while (*pcVar5 == '\0');
      *param_1 = (int)pcVar4;
      return pcVar5 + (1 - (int)pcVar8);
    }
  } while( true );
}



/* 40b5e300 FUN_40b5e300 */

undefined1 FUN_40b5e300(void)

{
  return DAT_40b6bfb8;
}



/* 40b5e310 FUN_40b5e310 */

/* Boundary evidence: original MIPS .pdata 40b5e310..40b5e393. Semantic name remains unreviewed. */

undefined4 FUN_40b5e310(void)

{
  void *_Memory;
  
  _Memory = DAT_40b6bfbc;
  if (DAT_40b6bfbc != (void *)0x0) {
    if (*(void **)((int)DAT_40b6bfbc + 0x30) != (void *)0x0) {
      free(*(void **)((int)DAT_40b6bfbc + 0x30));
      *(undefined4 *)((int)_Memory + 0x30) = 0;
    }
    if (*(void **)((int)_Memory + 0x34) != (void *)0x0) {
      free(*(void **)((int)_Memory + 0x34));
      *(undefined4 *)((int)_Memory + 0x34) = 0;
    }
    free(_Memory);
    DAT_40b6bfbc = (void *)0x0;
    DAT_40b6bfb8 = 0;
  }
  return 1;
}



/* 40b5e394 FUN_40b5e394 */

/* Boundary evidence: original MIPS .pdata 40b5e394..40b5e653. Semantic name remains unreviewed. */

void FUN_40b5e394(undefined4 param_1,int param_2)

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
  
  if (DAT_40b6bf0c == 0xffffffff) {
    DAT_40b6bf10 = 0xfa;
    DAT_40b6bf0c = 0xf9;
    DAT_40b6bf14 = 0xfb;
    DAT_40b6bf18 = 0xfc;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,0,
                          &local_30);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Highest",(LPDWORD)0x0,&local_34,(LPBYTE)&local_28,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_28)) {
        local_28 = DAT_40b6bf0c;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"AboveNormal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_2c,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_2c)) {
        local_2c = DAT_40b6bf10;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Normal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_24,&local_38
                              );
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_24)) {
        local_24 = DAT_40b6bf14;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"BelowNormal",(LPDWORD)0x0,&local_34,(LPBYTE)local_20,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_20[0])) {
        local_20[0] = DAT_40b6bf18;
      }
      if (((local_28 <= local_2c) && (local_2c <= local_24)) && (local_24 <= local_20[0])) {
        DAT_40b6bf0c = local_28;
        DAT_40b6bf10 = local_2c;
        DAT_40b6bf14 = local_24;
        DAT_40b6bf18 = local_20[0];
      }
      RegCloseKey(local_30);
    }
  }
  uVar2 = DAT_40b6bf0c;
  if (((param_2 != 1) && (uVar2 = DAT_40b6bf10, param_2 != 2)) &&
     (uVar2 = DAT_40b6bf18, param_2 != 4)) {
    uVar2 = DAT_40b6bf14;
  }
  CeSetThreadPriority(param_1,uVar2);
  return;
}



/* 40b5e654 FUN_40b5e654 */

/* Boundary evidence: original MIPS .pdata 40b5e654..40b5e693. Semantic name remains unreviewed. */

undefined4 * FUN_40b5e654(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



/* 40b5e694 FUN_40b5e694 */

/* Boundary evidence: original MIPS .pdata 40b5e694..40b5e6c3. Semantic name remains unreviewed. */

void FUN_40b5e694(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40b5e6c4 FUN_40b5e6c4 */

/* Boundary evidence: original MIPS .pdata 40b5e6c4..40b5e6e7. Semantic name remains unreviewed. */

void FUN_40b5e6c4(undefined4 *param_1)

{
  (**(code **)*param_1)();
  return;
}



/* 40b5e6e8 FUN_40b5e6e8 */

/* Boundary evidence: original MIPS .pdata 40b5e6e8..40b5e75b. Semantic name remains unreviewed. */

undefined4 FUN_40b5e6e8(void)

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



/* 40b5e75c FUN_40b5e75c */

short * FUN_40b5e75c(short *param_1,short *param_2,int param_3)

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



/* 40b5e798 FUN_40b5e798 */

/* WARNING: Removing unreachable block (ram,0x40b5ea0c) */
/* Boundary evidence: original MIPS .pdata 40b5e798..40b5ebb3. Semantic name remains unreviewed. */

int FUN_40b5e798(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
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
  if (param_7 == 0 && param_8 == 0) goto LAB_40b5e9d4;
  iVar11 = iVar8;
  if (bVar2) {
    uVar15 = -param_7;
    uVar12 = -(uint)(param_7 != 0) - param_8;
    if ((int)param_8 < 0) goto LAB_40b5e91c;
    bVar1 = param_8 == 0;
    param_8 = param_7;
    if (bVar1) goto joined_r0x40b5e984;
  }
  else {
    uVar15 = param_7;
    uVar12 = param_8;
    if ((int)param_8 < 1) {
joined_r0x40b5e984:
      if (param_8 != 0) goto LAB_40b5e924;
    }
LAB_40b5e91c:
    iVar11 = 0;
  }
LAB_40b5e924:
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
LAB_40b5e9d4:
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



/* 40b5ebb4 FUN_40b5ebb4 */

/* Boundary evidence: original MIPS .pdata 40b5ebb4..40b5ec3f. Semantic name remains unreviewed. */

undefined4 FUN_40b5ebb4(wchar_t *param_1,undefined4 *param_2)

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



/* 40b5ec40 FUN_40b5ec40 */

/* Boundary evidence: original MIPS .pdata 40b5ec40..40b5ecbb. Semantic name remains unreviewed. */

int FUN_40b5ec40(int param_1)

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



/* 40b5ecbc FUN_40b5ecbc */

/* Boundary evidence: original MIPS .pdata 40b5ecbc..40b5ed2b. Semantic name remains unreviewed. */

void FUN_40b5ecbc(int param_1)

{
  FUN_40b532f8(param_1);
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



/* 40b5ed2c FUN_40b5ed2c */

/* Boundary evidence: original MIPS .pdata 40b5ed2c..40b5eddf. Semantic name remains unreviewed. */

bool FUN_40b5ed2c(LPVOID param_1)

{
  HANDLE pvVar1;
  bool bVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD aDStack_18 [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)param_1 + 0x14) == 0) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40b5e6c4,param_1,0,aDStack_18);
    if (pvVar1 != (HANDLE)0x0) {
      FUN_40b5e394(pvVar1,3);
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



/* 40b5ede0 FUN_40b5ede0 */

/* Boundary evidence: original MIPS .pdata 40b5ede0..40b5ee6b. Semantic name remains unreviewed. */

undefined4 FUN_40b5ede0(int param_1,undefined4 param_2)

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



/* 40b5ee6c FUN_40b5ee6c */

/* Boundary evidence: original MIPS .pdata 40b5ee6c..40b5eea3. Semantic name remains unreviewed. */

undefined4 FUN_40b5ee6c(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
  return *(undefined4 *)(param_1 + 0xc);
}



/* 40b5eea4 FUN_40b5eea4 */

/* Boundary evidence: original MIPS .pdata 40b5eea4..40b5ef07. Semantic name remains unreviewed. */

undefined4 FUN_40b5eea4(int param_1,undefined4 *param_2)

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



/* 40b5ef08 FUN_40b5ef08 */

/* Boundary evidence: original MIPS .pdata 40b5ef08..40b5ef43. Semantic name remains unreviewed. */

void FUN_40b5ef08(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  EventModify(*(undefined4 *)(param_1 + 4),2);
  EventModify(*(undefined4 *)(param_1 + 8),3);
  return;
}



/* 40b5ef44 FUN_40b5ef44 */

void FUN_40b5ef44(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x1c) = param_2[3];
  return;
}



/* 40b5ef68 FUN_40b5ef68 */

void FUN_40b5ef68(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = *param_2;
  *(undefined4 *)(param_1 + 0x30) = param_2[1];
  *(undefined4 *)(param_1 + 0x34) = param_2[2];
  *(undefined4 *)(param_1 + 0x38) = param_2[3];
  return;
}



/* 40b5ef8c FUN_40b5ef8c */

/* Boundary evidence: original MIPS .pdata 40b5ef8c..40b5f027. Semantic name remains unreviewed. */

LPVOID FUN_40b5ef8c(int param_1,uint param_2)

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



/* 40b5f028 FUN_40b5f028 */

/* Boundary evidence: original MIPS .pdata 40b5f028..40b5f063. Semantic name remains unreviewed. */

void FUN_40b5f028(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40b5f064 FUN_40b5f064 */

/* Boundary evidence: original MIPS .pdata 40b5f064..40b5f0f7. Semantic name remains unreviewed. */

void FUN_40b5f064(void *param_1,void *param_2)

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



/* 40b5f0f8 FUN_40b5f0f8 */

/* Boundary evidence: original MIPS .pdata 40b5f0f8..40b5f15b. Semantic name remains unreviewed. */

void FUN_40b5f0f8(int param_1)

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



/* 40b5f15c FUN_40b5f15c */

/* Boundary evidence: original MIPS .pdata 40b5f15c..40b5f177. Semantic name remains unreviewed. */

void FUN_40b5f15c(int param_1)

{
  FUN_40b5f0f8(param_1);
  return;
}



/* 40b5f178 FUN_40b5f178 */

/* Boundary evidence: original MIPS .pdata 40b5f178..40b5f1b7. Semantic name remains unreviewed. */

void * FUN_40b5f178(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40b5f1b8 FUN_40b5f1b8 */

/* Boundary evidence: original MIPS .pdata 40b5f1b8..40b5f223. Semantic name remains unreviewed. */

undefined4 * FUN_40b5f1b8(undefined4 *param_1,undefined4 *param_2)

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



/* 40b5f224 FUN_40b5f224 */

/* Boundary evidence: original MIPS .pdata 40b5f224..40b5f24f. Semantic name remains unreviewed. */

void * FUN_40b5f224(void *param_1,void *param_2)

{
  FUN_40b5f064(param_1,param_2);
  return param_1;
}



/* 40b5f250 FUN_40b5f250 */

/* Boundary evidence: original MIPS .pdata 40b5f250..40b5f29b. Semantic name remains unreviewed. */

void * FUN_40b5f250(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40b5f0f8((int)param_1);
    FUN_40b5f064(param_1,param_2);
  }
  return param_1;
}



/* 40b5f29c FUN_40b5f29c */

/* Boundary evidence: original MIPS .pdata 40b5f29c..40b5f2c7. Semantic name remains unreviewed. */

void * FUN_40b5f29c(void *param_1,void *param_2)

{
  FUN_40b5f250(param_1,param_2);
  return param_1;
}



/* 40b5f2c8 FUN_40b5f2c8 */

/* Boundary evidence: original MIPS .pdata 40b5f2c8..40b5f373. Semantic name remains unreviewed. */

undefined4 FUN_40b5f2c8(void *param_1,void *param_2)

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



/* 40b5f374 FUN_40b5f374 */

void FUN_40b5f374(int param_1,int param_2)

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



/* 40b5f398 FUN_40b5f398 */

/* Boundary evidence: original MIPS .pdata 40b5f398..40b5f403. Semantic name remains unreviewed. */

undefined4 FUN_40b5f398(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40b6aa94,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40b6aa94,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b5f404 FUN_40b5f404 */

/* Boundary evidence: original MIPS .pdata 40b5f404..40b5f517. Semantic name remains unreviewed. */

undefined4 FUN_40b5f404(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40b6aa94,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40b6aa94,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40b6aa94,0x10);
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



/* 40b5f518 FUN_40b5f518 */

/* Boundary evidence: original MIPS .pdata 40b5f518..40b5f557. Semantic name remains unreviewed. */

void FUN_40b5f518(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40b5f0f8((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40b5f5c0 FUN_40b5f5c0 */

/* Boundary evidence: original MIPS .pdata 40b5f5c0..40b5f64b. Semantic name remains unreviewed. */

undefined4 FUN_40b5f5c0(int param_1,short *param_2)

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
      FUN_40b5e75c(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b5f64c FUN_40b5f64c */

/* Boundary evidence: original MIPS .pdata 40b5f64c..40b5f68b. Semantic name remains unreviewed. */

undefined4 FUN_40b5f64c(int param_1)

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



/* 40b5f694 FUN_40b5f694 */

/* Boundary evidence: original MIPS .pdata 40b5f694..40b5f6af. Semantic name remains unreviewed. */

void FUN_40b5f694(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x48));
  return;
}



/* 40b5f6b0 FUN_40b5f6b0 */

/* Boundary evidence: original MIPS .pdata 40b5f6b0..40b5f6fb. Semantic name remains unreviewed. */

void FUN_40b5f6b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40b6a808;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40b62660(param_1 + 6);
  return;
}



/* 40b5f6fc FUN_40b5f6fc */

/* Boundary evidence: original MIPS .pdata 40b5f6fc..40b5f793. Semantic name remains unreviewed. */

undefined4 FUN_40b5f6fc(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b68c18,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b6aab4,0x10), iVar2 == 0)) {
      uVar1 = FUN_40b627e4(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b5f794 FUN_40b5f794 */

/* Boundary evidence: original MIPS .pdata 40b5f794..40b5f7af. Semantic name remains unreviewed. */

void FUN_40b5f794(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40b5f7b0 FUN_40b5f7b0 */

/* Boundary evidence: original MIPS .pdata 40b5f7b0..40b5f80b. Semantic name remains unreviewed. */

LONG FUN_40b5f7b0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40b5f80c FUN_40b5f80c */

/* Boundary evidence: original MIPS .pdata 40b5f80c..40b5f86b. Semantic name remains unreviewed. */

undefined4 FUN_40b5f80c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40b623e8((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40b5f86c FUN_40b5f86c */

/* Boundary evidence: original MIPS .pdata 40b5f86c..40b5f8c3. Semantic name remains unreviewed. */

undefined4 FUN_40b5f86c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40b5f8c4 FUN_40b5f8c4 */

/* Boundary evidence: original MIPS .pdata 40b5f8c4..40b5f95b. Semantic name remains unreviewed. */

undefined4 FUN_40b5f8c4(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b68c28,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b6aab4,0x10), iVar2 == 0)) {
      uVar1 = FUN_40b627e4(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b5f95c FUN_40b5f95c */

/* Boundary evidence: original MIPS .pdata 40b5f95c..40b5f977. Semantic name remains unreviewed. */

void FUN_40b5f95c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40b5f978 FUN_40b5f978 */

/* Boundary evidence: original MIPS .pdata 40b5f978..40b5f9d3. Semantic name remains unreviewed. */

LONG FUN_40b5f978(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40b5f9d4 FUN_40b5f9d4 */

/* Boundary evidence: original MIPS .pdata 40b5f9d4..40b5fa13. Semantic name remains unreviewed. */

undefined4 FUN_40b5f9d4(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40b5fa14 FUN_40b5fa14 */

/* Boundary evidence: original MIPS .pdata 40b5fa14..40b5fa57. Semantic name remains unreviewed. */

void FUN_40b5fa14(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40b5f15c(param_1 + 0x1c);
  FUN_40b626f4();
  return;
}



/* 40b5fa58 FUN_40b5fa58 */

/* Boundary evidence: original MIPS .pdata 40b5fa58..40b5faff. Semantic name remains unreviewed. */

void FUN_40b5fa58(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b68c08,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b68d48,0x10);
    if (iVar1 != 0) {
      FUN_40b62880(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40b627e4(piVar2,param_3);
  return;
}



/* 40b5fb00 FUN_40b5fb00 */

/* Boundary evidence: original MIPS .pdata 40b5fb00..40b5fb2b. Semantic name remains unreviewed. */

void FUN_40b5fb00(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40b5fb2c FUN_40b5fb2c */

/* Boundary evidence: original MIPS .pdata 40b5fb2c..40b5fb57. Semantic name remains unreviewed. */

void FUN_40b5fb2c(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40b5fb58 FUN_40b5fb58 */

/* Boundary evidence: original MIPS .pdata 40b5fb58..40b5fb77. Semantic name remains unreviewed. */

undefined4 FUN_40b5fb58(int param_1,void *param_2)

{
  FUN_40b5f29c((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40b5fb78 FUN_40b5fb78 */

/* Boundary evidence: original MIPS .pdata 40b5fb78..40b5fbcf. Semantic name remains unreviewed. */

undefined4 FUN_40b5fb78(int param_1,int *param_2)

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



/* 40b5fbd0 FUN_40b5fbd0 */

/* Boundary evidence: original MIPS .pdata 40b5fbd0..40b5fc23. Semantic name remains unreviewed. */

undefined4 FUN_40b5fbd0(int param_1,int *param_2)

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



/* 40b5fc24 FUN_40b5fc24 */

/* Boundary evidence: original MIPS .pdata 40b5fc24..40b5fccf. Semantic name remains unreviewed. */

undefined4 FUN_40b5fc24(int param_1,int *param_2)

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
      FUN_40b5e75c((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40b5fcf8 FUN_40b5fcf8 */

/* Boundary evidence: original MIPS .pdata 40b5fcf8..40b5fd3f. Semantic name remains unreviewed. */

int FUN_40b5fcf8(int param_1,int param_2)

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



/* 40b5fd48 FUN_40b5fd48 */

undefined4 FUN_40b5fd48(void)

{
  return 0;
}



/* 40b5fd50 FUN_40b5fd50 */

/* Boundary evidence: original MIPS .pdata 40b5fd50..40b5fd9f. Semantic name remains unreviewed. */

undefined4 FUN_40b5fd50(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b5fdd0 FUN_40b5fdd0 */

/* Boundary evidence: original MIPS .pdata 40b5fdd0..40b5fdf7. Semantic name remains unreviewed. */

void FUN_40b5fdd0(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40b5fdf8 FUN_40b5fdf8 */

/* Boundary evidence: original MIPS .pdata 40b5fdf8..40b5fe5f. Semantic name remains unreviewed. */

int FUN_40b5fdf8(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b5fb78(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40b68cd8,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b5fe60 FUN_40b5fe60 */

/* Boundary evidence: original MIPS .pdata 40b5fe60..40b5fec3. Semantic name remains unreviewed. */

undefined4 FUN_40b5fe60(int param_1)

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



/* 40b5fec4 FUN_40b5fec4 */

/* Boundary evidence: original MIPS .pdata 40b5fec4..40b5feff. Semantic name remains unreviewed. */

void FUN_40b5fec4(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40b69da8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b68cb8,param_2);
  return;
}



/* 40b5ff00 FUN_40b5ff00 */

/* Boundary evidence: original MIPS .pdata 40b5ff00..40b6008b. Semantic name remains unreviewed. */

int FUN_40b5ff00(int *param_1,int *param_2,int *param_3)

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



/* 40b6008c FUN_40b6008c */

/* Boundary evidence: original MIPS .pdata 40b6008c..40b600d3. Semantic name remains unreviewed. */

undefined4 FUN_40b6008c(int param_1)

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



/* 40b600d4 FUN_40b600d4 */

/* Boundary evidence: original MIPS .pdata 40b600d4..40b60113. Semantic name remains unreviewed. */

undefined4 FUN_40b600d4(int param_1)

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



/* 40b60114 FUN_40b60114 */

/* Boundary evidence: original MIPS .pdata 40b60114..40b60153. Semantic name remains unreviewed. */

undefined4 FUN_40b60114(int param_1)

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



/* 40b60154 FUN_40b60154 */

/* Boundary evidence: original MIPS .pdata 40b60154..40b60193. Semantic name remains unreviewed. */

undefined4 FUN_40b60154(int param_1)

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



/* 40b601a0 FUN_40b601a0 */

/* Boundary evidence: original MIPS .pdata 40b601a0..40b601eb. Semantic name remains unreviewed. */

bool FUN_40b601a0(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40b601ec FUN_40b601ec */

/* Boundary evidence: original MIPS .pdata 40b601ec..40b60237. Semantic name remains unreviewed. */

bool FUN_40b601ec(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40b60238 FUN_40b60238 */

/* Boundary evidence: original MIPS .pdata 40b60238..40b60293. Semantic name remains unreviewed. */

undefined4 FUN_40b60238(int param_1)

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



/* 40b60294 FUN_40b60294 */

/* Boundary evidence: original MIPS .pdata 40b60294..40b602db. Semantic name remains unreviewed. */

void FUN_40b60294(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40b5fa14(param_1);
  return;
}



/* 40b602dc FUN_40b602dc */

/* Boundary evidence: original MIPS .pdata 40b602dc..40b6035b. Semantic name remains unreviewed. */

void FUN_40b602dc(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b68cd8,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b627e4(piVar2,param_3);
  }
  else {
    FUN_40b5fa58(param_1,param_2,param_3);
  }
  return;
}



/* 40b6035c FUN_40b6035c */

/* Boundary evidence: original MIPS .pdata 40b6035c..40b60423. Semantic name remains unreviewed. */

HRESULT FUN_40b6035c(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40b69da8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b68cb8,ppv),
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



/* 40b60424 FUN_40b60424 */

/* Boundary evidence: original MIPS .pdata 40b60424..40b604c3. Semantic name remains unreviewed. */

undefined4 FUN_40b60424(int param_1,int *param_2,undefined1 param_3)

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



/* 40b604c4 FUN_40b604c4 */

/* Boundary evidence: original MIPS .pdata 40b604c4..40b6055f. Semantic name remains unreviewed. */

int FUN_40b604c4(int *param_1,int param_2,int param_3,int *param_4)

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



/* 40b60560 FUN_40b60560 */

/* Boundary evidence: original MIPS .pdata 40b60560..40b605a7. Semantic name remains unreviewed. */

undefined4 FUN_40b60560(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b605a8 FUN_40b605a8 */

/* Boundary evidence: original MIPS .pdata 40b605a8..40b605eb. Semantic name remains unreviewed. */

undefined4 FUN_40b605a8(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b6060c FUN_40b6060c */

/* Boundary evidence: original MIPS .pdata 40b6060c..40b6064b. Semantic name remains unreviewed. */

undefined4 FUN_40b6060c(int param_1)

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



/* 40b606ac FUN_40b606ac */

/* Boundary evidence: original MIPS .pdata 40b606ac..40b60903. Semantic name remains unreviewed. */

int FUN_40b606ac(undefined4 *param_1,int *param_2,int param_3)

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
              if (iVar1 < 0) goto LAB_40b608cc;
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
LAB_40b608cc:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40b60904 FUN_40b60904 */

/* Boundary evidence: original MIPS .pdata 40b60904..40b609e3. Semantic name remains unreviewed. */

void FUN_40b60904(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40b68c68,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40b68c58,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40b6aac4,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40b68ce8,0x10);
    if (iVar1 != 0) {
      FUN_40b62880(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40b627e4(piVar2,param_3);
  return;
}



/* 40b609e4 FUN_40b609e4 */

/* Boundary evidence: original MIPS .pdata 40b609e4..40b60a3f. Semantic name remains unreviewed. */

void FUN_40b609e4(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40b626f4();
  return;
}



/* 40b60a40 FUN_40b60a40 */

/* Boundary evidence: original MIPS .pdata 40b60a40..40b60ac3. Semantic name remains unreviewed. */

undefined4 FUN_40b60a40(int param_1,int *param_2)

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



/* 40b60ac4 FUN_40b60ac4 */

/* Boundary evidence: original MIPS .pdata 40b60ac4..40b60b47. Semantic name remains unreviewed. */

undefined4 FUN_40b60ac4(int param_1,undefined4 *param_2)

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



/* 40b60b48 FUN_40b60b48 */

/* Boundary evidence: original MIPS .pdata 40b60b48..40b60bcf. Semantic name remains unreviewed. */

int FUN_40b60b48(int param_1,uint *param_2)

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



/* 40b60bd0 FUN_40b60bd0 */

/* Boundary evidence: original MIPS .pdata 40b60bd0..40b60ce7. Semantic name remains unreviewed. */

undefined4 FUN_40b60bd0(int param_1,LPCWSTR param_2,int *param_3)

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
          goto LAB_40b60c90;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40b60c90:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40b60ce8 FUN_40b60ce8 */

/* Boundary evidence: original MIPS .pdata 40b60ce8..40b60e03. Semantic name remains unreviewed. */

undefined4 FUN_40b60ce8(int param_1,undefined4 *param_2,wchar_t *param_3)

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
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40b68d78,(undefined4 *)(param_1 + 0x38));
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



/* 40b60e04 FUN_40b60e04 */

/* Boundary evidence: original MIPS .pdata 40b60e04..40b60ed7. Semantic name remains unreviewed. */

undefined4 FUN_40b60e04(int param_1)

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
    HVar3 = CoCreateInstance((IID *)&DAT_40b69868,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b68d38,local_10);
    if (-1 < HVar3) {
      FUN_40b606ac(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b60ed8 FUN_40b60ed8 */

/* Boundary evidence: original MIPS .pdata 40b60ed8..40b60fcb. Semantic name remains unreviewed. */

int FUN_40b60ed8(int param_1)

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
    HVar2 = CoCreateInstance((IID *)&DAT_40b69868,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b68d38,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40b606ac(puVar1,local_18[0],0);
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



/* 40b60fcc FUN_40b60fcc */

/* Boundary evidence: original MIPS .pdata 40b60fcc..40b61017. Semantic name remains unreviewed. */

undefined4 * FUN_40b60fcc(undefined4 *param_1,uint param_2)

{
  FUN_40b5f6b0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b61018 FUN_40b61018 */

/* Boundary evidence: original MIPS .pdata 40b61018..40b611af. Semantic name remains unreviewed. */

undefined4 FUN_40b61018(int param_1,uint param_2,int *param_3,uint *param_4)

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
    bVar1 = FUN_40b601a0(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40b5f86c(param_1);
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
        iVar3 = FUN_40b62464((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40b62564((int *)(param_1 + 0x18),iVar2);
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



/* 40b611b0 FUN_40b611b0 */

/* Boundary evidence: original MIPS .pdata 40b611b0..40b6122b. Semantic name remains unreviewed. */

undefined4 FUN_40b611b0(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40b601a0(param_1);
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



/* 40b6122c FUN_40b6122c */

/* Boundary evidence: original MIPS .pdata 40b6122c..40b6128f. Semantic name remains unreviewed. */

undefined4 * FUN_40b6122c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40b6a828;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b61290 FUN_40b61290 */

/* Boundary evidence: original MIPS .pdata 40b61290..40b61423. Semantic name remains unreviewed. */

uint FUN_40b61290(int param_1,uint param_2,undefined4 *param_3,int *param_4)

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
  
  local_28 = DAT_40b6bf1c;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40b64a98(DAT_40b6bf1c);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40b601ec(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40b64a98(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40b64a98(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40b5f178(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40b613d0:
          FUN_40b5f15c((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40b613d0;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40b5f15c((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40b64a98(local_28);
    }
  }
  return uVar3;
}



/* 40b61424 FUN_40b61424 */

/* Boundary evidence: original MIPS .pdata 40b61424..40b614db. Semantic name remains unreviewed. */

uint FUN_40b61424(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40b6bf1c;
  bVar1 = FUN_40b601ec(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40b64a98(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40b5f178(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40b5f15c((int)auStack_60);
    FUN_40b64a98(local_18);
  }
  return uVar3;
}



/* 40b614dc FUN_40b614dc */

/* Boundary evidence: original MIPS .pdata 40b614dc..40b61653. Semantic name remains unreviewed. */

int FUN_40b614dc(int *param_1,int *param_2,undefined4 param_3)

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



/* 40b61654 FUN_40b61654 */

/* Boundary evidence: original MIPS .pdata 40b61654..40b617c7. Semantic name remains unreviewed. */

int FUN_40b61654(int *param_1,int *param_2,void *param_3,int *param_4)

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
             (iVar3 = FUN_40b5f404(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40b614dc(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40b5f518(local_28);
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



/* 40b617c8 FUN_40b617c8 */

/* Boundary evidence: original MIPS .pdata 40b617c8..40b6194f. Semantic name remains unreviewed. */

int FUN_40b617c8(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40b5f398(param_3), iVar1 == 0)) {
    iVar1 = FUN_40b614dc(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40b61654(param_1,param_2,param_3,local_30[0]);
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
  iVar2 = FUN_40b61654(param_1,param_2,param_3,local_30[0]);
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



/* 40b61950 FUN_40b61950 */

/* Boundary evidence: original MIPS .pdata 40b61950..40b61b17. Semantic name remains unreviewed. */

int FUN_40b61950(int param_1,int *param_2,int param_3)

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
          goto LAB_40b61ae8;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40b61ae8;
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
LAB_40b61ae8:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40b61b18 FUN_40b61b18 */

/* Boundary evidence: original MIPS .pdata 40b61b18..40b61bb7. Semantic name remains unreviewed. */

undefined4 FUN_40b61b18(int param_1)

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



/* 40b61bb8 FUN_40b61bb8 */

/* Boundary evidence: original MIPS .pdata 40b61bb8..40b61c43. Semantic name remains unreviewed. */

undefined4 FUN_40b61bb8(int param_1,void *param_2)

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
      FUN_40b5f028(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40b5f064(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40b61c44 FUN_40b61c44 */

/* Boundary evidence: original MIPS .pdata 40b61c44..40b61c5f. Semantic name remains unreviewed. */

void FUN_40b61c44(int param_1,undefined4 *param_2)

{
  FUN_40b5ebb4(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40b61c60 FUN_40b61c60 */

/* Boundary evidence: original MIPS .pdata 40b61c60..40b61cdb. Semantic name remains unreviewed. */

int FUN_40b61c60(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40b61b18(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40b61cdc FUN_40b61cdc */

/* Boundary evidence: original MIPS .pdata 40b61cdc..40b61d5f. Semantic name remains unreviewed. */

undefined4 *
FUN_40b61cdc(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40b62824(param_1,param_2,param_3);
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



/* 40b61d60 FUN_40b61d60 */

/* Boundary evidence: original MIPS .pdata 40b61d60..40b61e3f. Semantic name remains unreviewed. */

undefined4 * FUN_40b61d60(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40b6a808;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40b623c4(param_1 + 6);
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
    FUN_40b62600(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40b61e40 FUN_40b61e40 */

/* Boundary evidence: original MIPS .pdata 40b61e40..40b61eeb. Semantic name remains unreviewed. */

undefined4 FUN_40b61e40(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40b601a0(param_1);
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
        puVar2 = FUN_40b61d60(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40b61eec FUN_40b61eec */

/* Boundary evidence: original MIPS .pdata 40b61eec..40b61f7b. Semantic name remains unreviewed. */

undefined4 * FUN_40b61eec(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40b6a828;
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



/* 40b61f7c FUN_40b61f7c */

/* Boundary evidence: original MIPS .pdata 40b61f7c..40b62027. Semantic name remains unreviewed. */

undefined4 FUN_40b61f7c(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40b601ec(param_1);
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
        puVar2 = FUN_40b61eec(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40b62028 FUN_40b62028 */

/* Boundary evidence: original MIPS .pdata 40b62028..40b6211b. Semantic name remains unreviewed. */

undefined4 *
FUN_40b62028(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40b62824(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40b5f178(param_1 + 7);
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



/* 40b6211c FUN_40b6211c */

/* Boundary evidence: original MIPS .pdata 40b6211c..40b621fb. Semantic name remains unreviewed. */

int FUN_40b6211c(int param_1,int *param_2,void *param_3)

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
        iVar1 = FUN_40b617c8(piVar2,param_2,param_3);
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



/* 40b621fc FUN_40b621fc */

/* Boundary evidence: original MIPS .pdata 40b621fc..40b6227b. Semantic name remains unreviewed. */

undefined4 FUN_40b621fc(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40b61eec(puVar2,param_1 + -0xc,0);
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



/* 40b6227c FUN_40b6227c */

/* Boundary evidence: original MIPS .pdata 40b6227c..40b622c7. Semantic name remains unreviewed. */

undefined4 *
FUN_40b6227c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40b62028(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40b622c8 FUN_40b622c8 */

/* Boundary evidence: original MIPS .pdata 40b622c8..40b62323. Semantic name remains unreviewed. */

undefined4 *
FUN_40b622c8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40b62028(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40b62324 FUN_40b62324 */

/* Boundary evidence: original MIPS .pdata 40b62324..40b623a3. Semantic name remains unreviewed. */

undefined4 FUN_40b62324(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40b61d60(puVar2,param_1 + -0xc,0);
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



/* 40b623a4 FUN_40b623a4 */

undefined4 * FUN_40b623a4(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40b623c4 FUN_40b623c4 */

undefined4 * FUN_40b623c4(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40b623e8 FUN_40b623e8 */

/* Boundary evidence: original MIPS .pdata 40b623e8..40b6243b. Semantic name remains unreviewed. */

void FUN_40b623e8(undefined4 *param_1)

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



/* 40b6243c FUN_40b6243c */

undefined4 FUN_40b6243c(undefined4 param_1,int *param_2)

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



/* 40b62464 FUN_40b62464 */

int FUN_40b62464(int *param_1,int param_2)

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



/* 40b624a8 FUN_40b624a8 */

/* Boundary evidence: original MIPS .pdata 40b624a8..40b62563. Semantic name remains unreviewed. */

int FUN_40b624a8(int *param_1,int *param_2)

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



/* 40b62564 FUN_40b62564 */

/* Boundary evidence: original MIPS .pdata 40b62564..40b625ff. Semantic name remains unreviewed. */

undefined4 * FUN_40b62564(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40b625b4;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40b625b4:
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



/* 40b62600 FUN_40b62600 */

/* Boundary evidence: original MIPS .pdata 40b62600..40b6265f. Semantic name remains unreviewed. */

undefined4 FUN_40b62600(undefined4 *param_1,int *param_2)

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
    puVar1 = FUN_40b62564(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40b62660 FUN_40b62660 */

/* Boundary evidence: original MIPS .pdata 40b62660..40b626a7. Semantic name remains unreviewed. */

void FUN_40b62660(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40b623e8(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40b626a8 FUN_40b626a8 */

/* Boundary evidence: original MIPS .pdata 40b626a8..40b626c3. Semantic name remains unreviewed. */

void FUN_40b626a8(int *param_1)

{
  FUN_40b624a8(param_1,(int *)*param_1);
  return;
}



/* 40b626c4 FUN_40b626c4 */

/* Boundary evidence: original MIPS .pdata 40b626c4..40b626f3. Semantic name remains unreviewed. */

undefined4 FUN_40b626c4(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40b6bfd0);
  return param_1;
}



/* 40b626f4 FUN_40b626f4 */

/* Boundary evidence: original MIPS .pdata 40b626f4..40b6274b. Semantic name remains unreviewed. */

void FUN_40b626f4(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40b6bfd0);
  if ((LVar1 == 0) && (DAT_40b6bfcc != 0)) {
    FreeLibrary((HMODULE)DAT_40b6bfcc);
    DAT_40b6bfcc = 0;
  }
  return;
}



/* 40b6274c FUN_40b6274c */

/* Boundary evidence: original MIPS .pdata 40b6274c..40b62787. Semantic name remains unreviewed. */

void FUN_40b6274c(void)

{
  if (DAT_40b6bfcc == (HMODULE)0x0) {
    DAT_40b6bfcc = LoadLibraryW(L"OleAut32.dll");
  }
  return;
}



/* 40b62788 FUN_40b62788 */

/* Boundary evidence: original MIPS .pdata 40b62788..40b627e3. Semantic name remains unreviewed. */

undefined4 * FUN_40b62788(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40b6a864;
  InterlockedIncrement(&DAT_40b6bfd0);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40b627e4 FUN_40b627e4 */

/* Boundary evidence: original MIPS .pdata 40b627e4..40b62823. Semantic name remains unreviewed. */

undefined4 FUN_40b627e4(int *param_1,undefined4 *param_2)

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



/* 40b62824 FUN_40b62824 */

/* Boundary evidence: original MIPS .pdata 40b62824..40b6287f. Semantic name remains unreviewed. */

undefined4 * FUN_40b62824(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40b6a864;
  InterlockedIncrement(&DAT_40b6bfd0);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40b62880 FUN_40b62880 */

/* Boundary evidence: original MIPS .pdata 40b62880..40b62903. Semantic name remains unreviewed. */

undefined4 FUN_40b62880(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40b6aab4,0x10);
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



/* 40b62904 FUN_40b62904 */

/* Boundary evidence: original MIPS .pdata 40b62904..40b6293f. Semantic name remains unreviewed. */

uint FUN_40b62904(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40b62940 FUN_40b62940 */

/* Boundary evidence: original MIPS .pdata 40b62940..40b629b7. Semantic name remains unreviewed. */

uint FUN_40b62940(int *param_1)

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



/* 40b629b8 FUN_40b629b8 */

/* Boundary evidence: original MIPS .pdata 40b629b8..40b629fb. Semantic name remains unreviewed. */

void FUN_40b629b8(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x28),*(int *)(param_1 + 0x3c),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40b629fc FUN_40b629fc */

/* Boundary evidence: original MIPS .pdata 40b629fc..40b62abf. Semantic name remains unreviewed. */

void FUN_40b629fc(LPCRITICAL_SECTION param_1)

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
      FUN_40b629b8((int)param_1);
      LeaveCriticalSection(param_1);
      (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
      return;
    }
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40b62ac0 FUN_40b62ac0 */

/* Boundary evidence: original MIPS .pdata 40b62ac0..40b62b17. Semantic name remains unreviewed. */

void FUN_40b62ac0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_40b62564(*(undefined4 **)(param_1 + 0x24),param_2);
  if ((puVar1 == (undefined4 *)0x0) && (param_2 < (int *)0xfffffff1)) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



/* 40b62b18 FUN_40b62b18 */

/* Boundary evidence: original MIPS .pdata 40b62b18..40b62db7. Semantic name remains unreviewed. */

LONG FUN_40b62b18(LPCRITICAL_SECTION param_1,undefined4 *param_2,int param_3,int *param_4)

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
        else if ((param_1[2].RecursionCount == 0) || (param_1[3].LockCount == 0)) goto LAB_40b62bd8;
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
          FUN_40b62ac0((int)param_1,(int *)*param_2);
          param_2 = param_2 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      *param_4 = param_3;
      if ((param_1[1].LockCount == 0) ||
         (param_1[1].RecursionCount <=
          param_1[2].RecursionCount + *(int *)((int)param_1[1].OwningThread + 8))) {
        FUN_40b629b8((int)param_1);
      }
      LVar1 = 0;
      goto LAB_40b62d80;
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
  goto LAB_40b62be8;
LAB_40b62bd8:
  *param_4 = iVar2 - iVar3;
  if (iVar2 - iVar3 < 0) {
    *param_4 = 0;
  }
LAB_40b62be8:
  LVar1 = param_1[3].RecursionCount;
LAB_40b62d80:
  LeaveCriticalSection(param_1);
  return LVar1;
}



/* 40b62db8 FUN_40b62db8 */

/* Boundary evidence: original MIPS .pdata 40b62db8..40b62eaf. Semantic name remains unreviewed. */

void FUN_40b62db8(LPCRITICAL_SECTION param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  EnterCriticalSection(param_1);
  piVar2 = param_1[1].OwningThread;
  if (piVar2 != (int *)0x0) {
    while (piVar2 = (int *)FUN_40b626a8(piVar2), piVar2 != (int *)0x0) {
      if (piVar2 < (int *)0xfffffff1) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      else if (piVar2 == (int *)0xfffffffb) {
        pvVar1 = (void *)FUN_40b626a8(param_1[1].OwningThread);
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



/* 40b62eb0 FUN_40b62eb0 */

/* Boundary evidence: original MIPS .pdata 40b62eb0..40b62fab. Semantic name remains unreviewed. */

void FUN_40b62eb0(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  
  if (param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    (**(code **)(*(int *)param_1[1].DebugInfo + 8))();
  }
  if (param_1[2].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    FUN_40b62db8(param_1);
  }
  else {
    EnterCriticalSection(param_1);
    param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1;
    param_1[3].RecursionCount = 1;
    FUN_40b629b8((int)param_1);
    LeaveCriticalSection(param_1);
    WaitForSingleObject(param_1[2].DebugInfo,0xffffffff);
    CloseHandle(param_1[2].DebugInfo);
    puVar1 = param_1[1].OwningThread;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_40b62660(puVar1);
      operator_delete(puVar1);
    }
  }
  if (param_1[1].LockSemaphore != (HANDLE)0x0) {
    CloseHandle(param_1[1].LockSemaphore);
  }
  operator_delete((void *)param_1[2].LockCount);
  FUN_40b5e694(&param_1[1].SpinCount);
  DeleteCriticalSection(param_1);
  return;
}



/* 40b62fac FUN_40b62fac */

/* Boundary evidence: original MIPS .pdata 40b62fac..40b63283. Semantic name remains unreviewed. */

undefined4 FUN_40b62fac(LPCRITICAL_SECTION param_1)

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
LAB_40b62fe8:
  do {
    bVar1 = false;
    EnterCriticalSection(param_1);
    do {
      while( true ) {
        if (param_1[3].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
          FUN_40b62db8(param_1);
          LeaveCriticalSection(param_1);
          return 0;
        }
        if (param_1[2].LockSemaphore != (HANDLE)0x0) {
          FUN_40b62db8(param_1);
          EventModify(param_1[1].SpinCount,3);
        }
        uVar2 = FUN_40b626a8(param_1[1].OwningThread);
        if (uVar2 != 0) break;
        if ((param_1[1].LockCount != 0) || (param_1[2].RecursionCount == 0)) {
          param_1[2].OwningThread = (HANDLE)((int)param_1[2].OwningThread + 1);
          bVar1 = true;
          goto LAB_40b630fc;
        }
LAB_40b630a8:
        if (uVar2 != 0xfffffffe) {
          if (uVar2 == 0xfffffffb) {
            pvVar3 = (void *)FUN_40b626a8(param_1[1].OwningThread);
          }
          goto LAB_40b630e0;
        }
        if (param_1[2].RecursionCount != 0) goto LAB_40b630e0;
      }
      if (0xfffffff0 < uVar2) goto LAB_40b630a8;
      if (param_1[2].RecursionCount < param_1[1].RecursionCount) {
        *(uint *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = uVar2;
        param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
      }
    } while (param_1[2].RecursionCount != param_1[1].RecursionCount);
LAB_40b630e0:
    pvVar6 = (void *)param_1[2].RecursionCount;
    param_1[2].RecursionCount = 0;
LAB_40b630fc:
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
        if (param_1[3].RecursionCount != 0) goto LAB_40b62fe8;
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
      goto LAB_40b62fe8;
    }
    WaitForSingleObject(param_1[1].LockSemaphore,0xffffffff);
  } while( true );
}



/* 40b63284 FUN_40b63284 */

/* Boundary evidence: original MIPS .pdata 40b63284..40b632f3. Semantic name remains unreviewed. */

void FUN_40b63284(LPCRITICAL_SECTION param_1)

{
  int aiStack_10 [2];
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    param_1[3].LockCount = 1;
    FUN_40b62b18(param_1,(undefined4 *)0x0,0,aiStack_10);
    param_1[3].LockCount = 0;
  }
  else {
    EnterCriticalSection(param_1);
    FUN_40b62ac0((int)param_1,(int *)0xfffffffe);
    FUN_40b629b8((int)param_1);
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40b632f4 FUN_40b632f4 */

/* Boundary evidence: original MIPS .pdata 40b632f4..40b63393. Semantic name remains unreviewed. */

void FUN_40b632f4(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[1].LockCount != 0) {
      FUN_40b63284(param_1);
    }
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      (**(code **)(*(int *)param_1->SpinCount + 0x38))();
    }
  }
  else if (param_1[3].RecursionCount == 0) {
    param_1[2].SpinCount = 0;
    FUN_40b62ac0((int)param_1,(int *)0xfffffffd);
    FUN_40b629b8((int)param_1);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40b63394 FUN_40b63394 */

/* Boundary evidence: original MIPS .pdata 40b63394..40b63447. Semantic name remains unreviewed. */

void FUN_40b63394(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  
  EnterCriticalSection(param_1);
  if ((param_1[2].SpinCount == 0) || (param_1[1].OwningThread == (HANDLE)0x0)) {
    LeaveCriticalSection(param_1);
    if (param_1[1].OwningThread == (HANDLE)0x0) {
      FUN_40b62db8(param_1);
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



/* 40b63448 FUN_40b63448 */

/* Boundary evidence: original MIPS .pdata 40b63448..40b6346f. Semantic name remains unreviewed. */

void FUN_40b63448(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  int aiStack_10 [2];
  
  local_res4[0] = param_2;
  FUN_40b62b18(param_1,local_res4,1,aiStack_10);
  return;
}



/* 40b63470 FUN_40b63470 */

/* Boundary evidence: original MIPS .pdata 40b63470..40b634c3. Semantic name remains unreviewed. */

undefined4 FUN_40b63470(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40b5e6e8();
  uVar2 = FUN_40b62fac(param_1);
  if (-1 < iVar1) {
    CoUninitialize();
  }
  return uVar2;
}



/* 40b634c4 FUN_40b634c4 */

/* Boundary evidence: original MIPS .pdata 40b634c4..40b63707. Semantic name remains unreviewed. */

LPCRITICAL_SECTION
FUN_40b634c4(LPCRITICAL_SECTION param_1,undefined4 *param_2,DWORD *param_3,int param_4,int param_5,
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
  FUN_40b5e654(&param_1[1].SpinCount,0);
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
  DVar1 = (**(code **)*param_2)(param_2,&DAT_40b68cd8,p_Var9);
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
LAB_40b63604:
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
        FUN_40b623a4(puVar5,0,param_8);
      }
      param_1[1].OwningThread = puVar5;
      if (puVar5 == (undefined4 *)0x0) goto LAB_40b63604;
      p_Var6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40b63470,param_1,0,aDStack_28);
      param_1[2].DebugInfo = p_Var6;
      if (p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        FUN_40b5e394(p_Var6,param_9);
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



/* 40b6374c FUN_40b6374c */

/* Boundary evidence: original MIPS .pdata 40b6374c..40b637cb. Semantic name remains unreviewed. */

void FUN_40b6374c(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40b6bf08) {
    ppuVar2 = &PTR_DAT_40b6bef8;
    iVar1 = DAT_40b6bf08;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40b6bf08;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40b637cc FUN_40b637cc */

/* Boundary evidence: original MIPS .pdata 40b637cc..40b6386b. Semantic name remains unreviewed. */

undefined4 FUN_40b637cc(HMODULE param_1,int param_2)

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
    DAT_40b6c0e8 = 1;
    DAT_40b6bfd4 = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40b6bfd4);
    if (BVar1 != 0) {
      DAT_40b6c0e8 = DAT_40b6bfe4;
    }
    uVar2 = 1;
    DAT_40b6c0ec = param_1;
  }
  FUN_40b6374c(uVar2);
  return 1;
}



/* 40b6386c FUN_40b6386c */

undefined4 FUN_40b6386c(int param_1,int *param_2)

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



/* 40b638bc FUN_40b638bc */

/* Boundary evidence: original MIPS .pdata 40b638bc..40b63967. Semantic name remains unreviewed. */

undefined4 FUN_40b638bc(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40b6aab4,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40b6aad4,0x10), iVar2 == 0)) {
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



/* 40b63968 FUN_40b63968 */

/* Boundary evidence: original MIPS .pdata 40b63968..40b639bf. Semantic name remains unreviewed. */

void * FUN_40b63968(void *param_1,uint param_2)

{
  FUN_40b626f4();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b639c0 FUN_40b639c0 */

/* Boundary evidence: original MIPS .pdata 40b639c0..40b63ae3. Semantic name remains unreviewed. */

int FUN_40b639c0(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40b6aab4,0x10), iVar1 == 0)) {
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



/* 40b63ae4 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x13ae4  1  DllCanUnloadNow */
  if ((0 < DAT_40b6c0f0) || (HVar1 = 0, DAT_40b6bfd0 != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40b63b10 FUN_40b63b10 */

/* Boundary evidence: original MIPS .pdata 40b63b10..40b63b6b. Semantic name remains unreviewed. */

undefined4 * FUN_40b63b10(undefined4 *param_1,undefined4 param_2)

{
  FUN_40b626c4(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40b6a870;
  param_1[2] = 0;
  return param_1;
}



/* 40b63b6c FUN_40b63b6c */

/* Boundary evidence: original MIPS .pdata 40b63b6c..40b63b9b. Semantic name remains unreviewed. */

int FUN_40b63b6c(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40b63968(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b63b9c DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40b63b9c..40b63cc3. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0x13b9c  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40b6aab4,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40b6aad4,0x10), iVar1 == 0)) {
    iVar1 = DAT_40b6bf08;
    iVar7 = 0;
    if (0 < DAT_40b6bf08) {
      ppuVar6 = &PTR_u_Alchemy_Pass_Thru_Demux_Filter_40b6bef4;
      do {
        iVar3 = FUN_40b6386c((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40b63b10(puVar4,ppuVar6);
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



/* 40b63cc4 FUN_40b63cc4 */

/* Boundary evidence: original MIPS .pdata 40b63cc4..40b63e0f. Semantic name remains unreviewed. */

undefined4 FUN_40b63cc4(HKEY param_1,wchar_t *param_2)

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
  
  local_20 = DAT_40b6bf1c;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40b64a98(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40b63cc4(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40b64a98(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b63e10 FUN_40b63e10 */

/* Boundary evidence: original MIPS .pdata 40b63e10..40b6409f. Semantic name remains unreviewed. */

uint FUN_40b63e10(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  
  local_30 = DAT_40b6bf1c;
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
  FUN_40b64a98(local_30);
  return uVar1;
}



/* 40b640a0 FUN_40b640a0 */

/* Boundary evidence: original MIPS .pdata 40b640a0..40b64113. Semantic name remains unreviewed. */

undefined4 FUN_40b640a0(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40b6bf1c;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40b63cc4((HKEY)0x80000000,aWStack_218);
  FUN_40b64a98(local_10);
  return 0;
}



/* 40b64114 FUN_40b64114 */

/* Boundary evidence: original MIPS .pdata 40b64114..40b6434b. Semantic name remains unreviewed. */

DWORD FUN_40b64114(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40b6bf1c;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40b6c0ec,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40b6bf08) {
      ppuVar5 = &PTR_u_Alchemy_Pass_Thru_Demux_Filter_40b6bef4;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40b63e10(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40b68ce8,local_240
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
      } while (iVar4 < DAT_40b6bf08);
    }
  }
  FUN_40b64a98(local_30);
  return DVar3;
}



/* 40b6434c FUN_40b6434c */

/* Boundary evidence: original MIPS .pdata 40b6434c..40b644d3. Semantic name remains unreviewed. */

int FUN_40b6434c(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40b6bf08 != 0) {
    iVar3 = DAT_40b6bf08;
    ppuVar4 = &PTR_DAT_40b6bef8 + DAT_40b6bf08 * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40b68ce8,local_30);
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
      HVar2 = FUN_40b640a0(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
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



/* 40b644d4 FUN_40b644d4 */

/* Boundary evidence: original MIPS .pdata 40b644d4..40b64507. Semantic name remains unreviewed. */

void FUN_40b644d4(int param_1)

{
  if (param_1 == 0) {
    FUN_40b6434c();
  }
  else {
    FUN_40b64114();
  }
  return;
}



/* 40b64508 FUN_40b64508 */

/* Boundary evidence: original MIPS .pdata 40b64508..40b64537. Semantic name remains unreviewed. */

void FUN_40b64508(int *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
  }
  return;
}



/* 40b64538 FUN_40b64538 */

undefined4 FUN_40b64538(undefined4 param_1,undefined4 *param_2)

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



/* 40b64560 FUN_40b64560 */

/* Boundary evidence: original MIPS .pdata 40b64560..40b646fb. Semantic name remains unreviewed. */

uint FUN_40b64560(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

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
    iVar1 = FUN_40b6274c();
    if ((iVar1 == 0) ||
       (pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadRegTypeLib"), pcVar3 == (code *)0x0)) {
LAB_40b645d4:
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        return DVar2;
      }
      return DVar2 & 0xffff | 0x80070000;
    }
    iVar4 = (*pcVar3)(&UNK_40b69168,1,0,param_4,local_28);
    if (iVar4 < 0) {
      pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadTypeLib");
      if (pcVar3 == (code *)0x0) goto LAB_40b645d4;
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



/* 40b646fc FUN_40b646fc */

/* Boundary evidence: original MIPS .pdata 40b646fc..40b648c3. Semantic name remains unreviewed. */

DWORD FUN_40b646fc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
    iVar1 = FUN_40b6274c();
    if ((iVar1 == 0) ||
       (pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadRegTypeLib"), pcVar3 == (code *)0x0)) {
LAB_40b64768:
      DVar2 = GetLastError();
      if (0 < (int)DVar2) {
        DVar2 = DVar2 & 0xffff | 0x80070000;
      }
      goto LAB_40b64860;
    }
    iVar4 = (*pcVar3)(&UNK_40b69168,1,0,param_5,local_28);
    if (iVar4 < 0) {
      pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadTypeLib");
      if (pcVar3 == (code *)0x0) goto LAB_40b64768;
      DVar2 = (*pcVar3)(L"control.tlb",local_28);
      if ((int)DVar2 < 0) goto LAB_40b64860;
    }
    DVar2 = (**(code **)(*local_28[0] + 0x18))(local_28[0],param_2,param_1);
    (**(code **)(*local_28[0] + 8))();
    if ((int)DVar2 < 0) goto LAB_40b64860;
  }
  piVar5 = (int *)*param_1;
  (**(code **)(*piVar5 + 4))(piVar5);
  DVar2 = 0;
LAB_40b64860:
  if (-1 < (int)DVar2) {
    DVar2 = (**(code **)(*piVar5 + 0x28))(piVar5,param_3,param_4,param_6);
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  return DVar2;
}



/* 40b649a4 FUN_40b649a4 */

/* Boundary evidence: original MIPS .pdata 40b649a4..40b64a17. Semantic name remains unreviewed. */

void FUN_40b649a4(void)

{
  uint uVar1;
  
  if ((DAT_40b6bf1c == 0) || (DAT_40b6bf1c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40b6bf1c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40b6bf1c == 0) {
      DAT_40b6bf1c = 0xb064;
    }
  }
  DAT_40b6bf20 = ~DAT_40b6bf1c;
  return;
}



/* 40b64a18 FUN_40b64a18 */

/* Boundary evidence: original MIPS .pdata 40b64a18..40b64a6b. Semantic name remains unreviewed. */

void FUN_40b64a18(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40b64a98(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40b64a6c FUN_40b64a6c */

/* Boundary evidence: original MIPS .pdata 40b64a6c..40b64a97. Semantic name remains unreviewed. */

undefined4 FUN_40b64a6c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40b64a18(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40b64a98 FUN_40b64a98 */

/* Boundary evidence: original MIPS .pdata 40b64a98..40b64adf. Semantic name remains unreviewed. */

void FUN_40b64a98(uint param_1)

{
  if ((param_1 == DAT_40b6bf1c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40b64be0 FUN_40b64be0 */

/* Boundary evidence: original MIPS .pdata 40b64be0..40b64c4f. Semantic name remains unreviewed. */

void FUN_40b64be0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40b64a18(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 40b64c60 FUN_40b64c60 */

/* Boundary evidence: original MIPS .pdata 40b64c60..40b64d9b. Semantic name remains unreviewed. */

int FUN_40b64c60(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40b6c104 != (code *)0x0) {
      iVar2 = (*DAT_40b6c104)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40b64d10;
    FUN_40b64fe4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40b5c988(param_1,param_2);
  }
LAB_40b64d10:
  if (((param_2 == 0) && (FUN_40b64f6c(), iVar1 != 0)) && (DAT_40b6c104 != (code *)0x0)) {
    iVar1 = (*DAT_40b6c104)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40b64d9c FUN_40b64d9c */

/* Boundary evidence: original MIPS .pdata 40b64d9c..40b64dc7. Semantic name remains unreviewed. */

void FUN_40b64d9c(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40b64dc8 entry */

/* Boundary evidence: original MIPS .pdata 40b64dc8..40b64e1f. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40b649a4();
  }
  FUN_40b64c60(param_1,param_2,param_3);
  return;
}



/* 40b64e80 FUN_40b64e80 */

/* Boundary evidence: original MIPS .pdata 40b64e80..40b64f6b. Semantic name remains unreviewed. */

void FUN_40b64e80(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40b6c0f8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40b6c100;
    if (DAT_40b6c100 != (undefined4 *)0x0) {
      while (DAT_40b6c0fc = DAT_40b6c0fc + -1, _Memory <= DAT_40b6c0fc) {
        if ((code *)*DAT_40b6c0fc != (code *)0x0) {
          (*(code *)*DAT_40b6c0fc)();
          _Memory = DAT_40b6c100;
        }
      }
      free(_Memory);
      DAT_40b6c0fc = (undefined4 *)0x0;
      DAT_40b6c100 = (undefined4 *)0x0;
    }
    FUN_40b64f90((undefined4 *)&DAT_40b66010,(undefined4 *)&DAT_40b66014);
  }
  FUN_40b64f90((undefined4 *)&DAT_40b66018,(undefined4 *)&DAT_40b6601c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40b64f6c FUN_40b64f6c */

/* Boundary evidence: original MIPS .pdata 40b64f6c..40b64f8f. Semantic name remains unreviewed. */

void FUN_40b64f6c(void)

{
  FUN_40b64e80(0,0,1);
  return;
}



/* 40b64f90 FUN_40b64f90 */

/* Boundary evidence: original MIPS .pdata 40b64f90..40b64fe3. Semantic name remains unreviewed. */

void FUN_40b64f90(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40b64fe4 FUN_40b64fe4 */

/* Boundary evidence: original MIPS .pdata 40b64fe4..40b6501f. Semantic name remains unreviewed. */

void FUN_40b64fe4(void)

{
  FUN_40b64f90((undefined4 *)&DAT_40b66008,(undefined4 *)&DAT_40b6600c);
  FUN_40b64f90((undefined4 *)&DAT_40b66000,(undefined4 *)&DAT_40b66004);
  return;
}


