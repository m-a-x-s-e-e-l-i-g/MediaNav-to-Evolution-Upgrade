/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40b81000 FUN_40b81000 */

uint FUN_40b81000(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1[2];
  if (param_2 <= uVar1) {
    return (*param_1 << (0x20 - uVar1 & 0x1f)) >> (0x20 - param_2 & 0x1f);
  }
  return param_1[1] >> (0x20 - (param_2 - uVar1) & 0x1f) |
         ((1 << (uVar1 & 0x1f)) - 1U & *param_1) << (param_2 - uVar1 & 0x1f);
}



/* 40b81064 FUN_40b81064 */

/* Boundary evidence: original MIPS .pdata 40b81064..40b810b3. Semantic name remains unreviewed. */

undefined4 FUN_40b81064(undefined1 *param_1,int param_2)

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



/* 40b810b4 FUN_40b810b4 */

/* Boundary evidence: original MIPS .pdata 40b810b4..40b8116b. Semantic name remains unreviewed. */

void FUN_40b810b4(undefined4 *param_1,int param_2)

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
    goto LAB_40b81148;
  }
  _local_8 = 0;
  _local_8 = 0;
  if (uVar2 == 1) {
LAB_40b81138:
    _local_8 = CONCAT13(*puVar1,_local_8);
  }
  else {
    if (uVar2 == 2) {
LAB_40b81130:
      _local_8 = CONCAT12(puVar1[1],local_8);
      goto LAB_40b81138;
    }
    if (uVar2 == 3) {
      _local_8 = (uint3)(byte)puVar1[2] << 8;
      goto LAB_40b81130;
    }
  }
  param_1[4] = 0;
LAB_40b81148:
  param_1[1] = _local_8;
  param_1[6] = puVar1 + 4;
  param_1[2] = (param_1[2] - param_2) + 0x20;
  return;
}



/* 40b8116c FUN_40b8116c */

/* Boundary evidence: original MIPS .pdata 40b8116c..40b811ef. Semantic name remains unreviewed. */

uint FUN_40b8116c(uint *param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_40b81000(param_1,param_2);
    if ((char)param_1[5] == '\0') {
      if (param_2 < param_1[2]) {
        param_1[2] = param_1[2] - param_2;
      }
      else {
        FUN_40b810b4(param_1,param_2);
      }
    }
  }
  return uVar1;
}



/* 40b811f0 FUN_40b811f0 */

/* Boundary evidence: original MIPS .pdata 40b811f0..40b81307. Semantic name remains unreviewed. */

void FUN_40b811f0(undefined4 *param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 local_18;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((param_3 != 0) && (param_2 != (undefined1 *)0x0)) {
      param_1[8] = param_2;
      param_1[3] = param_3;
      param_1[4] = param_3;
      if (param_3 < 4) {
        local_18 = FUN_40b81064(param_2,param_3);
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
        local_18 = FUN_40b81064(param_2 + 4,uVar1);
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



/* 40b81308 FUN_40b81308 */

/* Boundary evidence: original MIPS .pdata 40b81308..40b820bf. Semantic name remains unreviewed. */

undefined4 FUN_40b81308(undefined1 *param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  memset(param_1,0,0x1d7);
  param_1[0xb0] = 0;
  uVar1 = FUN_40b81000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b810b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  *param_1 = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,2);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 3) {
      FUN_40b810b4(param_2,2);
    }
    else {
      param_2[2] = param_2[2] - 2;
    }
  }
  param_1[1] = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b810b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[2] = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b810b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[3] = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b810b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[4] = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b810b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[5] = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,2);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 3) {
      FUN_40b810b4(param_2,2);
    }
    else {
      param_2[2] = param_2[2] - 2;
    }
  }
  param_1[6] = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,3);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 4) {
      FUN_40b810b4(param_2,3);
    }
    else {
      param_2[2] = param_2[2] - 3;
    }
  }
  param_1[7] = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,4);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 5) {
      FUN_40b810b4(param_2,4);
    }
    else {
      param_2[2] = param_2[2] - 4;
    }
  }
  param_1[8] = (char)uVar1;
  uVar1 = FUN_40b81000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40b810b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[9] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40b81000(param_2,4);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 5) {
        FUN_40b810b4(param_2,4);
      }
      else {
        param_2[2] = param_2[2] - 4;
      }
    }
    param_1[10] = (char)uVar1;
  }
  uVar1 = FUN_40b81000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40b810b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[0xb] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40b81000(param_2,4);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 5) {
        FUN_40b810b4(param_2,4);
      }
      else {
        param_2[2] = param_2[2] - 4;
      }
    }
    param_1[0xc] = (char)uVar1;
  }
  uVar1 = FUN_40b81000(param_2,1);
  if ((char)param_2[5] == '\0') {
    if (param_2[2] < 2) {
      FUN_40b810b4(param_2,1);
    }
    else {
      param_2[2] = param_2[2] - 1;
    }
  }
  param_1[0xd] = (char)uVar1;
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_40b81000(param_2,2);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 3) {
        FUN_40b810b4(param_2,2);
      }
      else {
        param_2[2] = param_2[2] - 2;
      }
    }
    param_1[0xf] = (char)uVar1;
    uVar1 = FUN_40b81000(param_2,1);
    if ((char)param_2[5] == '\0') {
      if (param_2[2] < 2) {
        FUN_40b810b4(param_2,1);
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
          FUN_40b810b4(param_2,1);
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
          FUN_40b810b4(param_2,4);
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
          FUN_40b810b4(param_2,1);
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
          FUN_40b810b4(param_2,4);
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
          FUN_40b810b4(param_2,1);
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
          FUN_40b810b4(param_2,4);
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
          FUN_40b810b4(param_2,4);
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
          FUN_40b810b4(param_2,4);
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
          FUN_40b810b4(param_2,1);
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
          FUN_40b810b4(param_2,4);
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
      FUN_40b810b4(param_2,uVar4);
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
      FUN_40b810b4(param_2,8);
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
          FUN_40b810b4(param_2,8);
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



/* 40b820c0 FUN_40b820c0 */

/* Boundary evidence: original MIPS .pdata 40b820c0..40b8249f. Semantic name remains unreviewed. */

void FUN_40b820c0(uint *param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5)

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
  
  local_30 = DAT_40ba9854;
  *param_2 = 0;
  uVar1 = FUN_40b81000(param_1,1);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
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
          FUN_40b810b4(param_1,8);
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
      FUN_40b810b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
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
      FUN_40b810b4(param_1,1);
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
      FUN_40b810b4(param_1,0x17);
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
      FUN_40b810b4(param_1,4);
    }
    else {
      param_1[2] = uVar1 - 4;
    }
  }
  for (iVar4 = uVar3 + 1; iVar4 != 0; iVar4 = iVar4 + -1) {
    if ((-1 < (int)uVar2) && ((char)param_1[5] == '\0')) {
      if (param_1[2] < 0x15) {
        FUN_40b810b4(param_1,0x14);
      }
      else {
        param_1[2] = param_1[2] - 0x14;
      }
    }
    if (uVar3 == 0) {
      FUN_40b81308(auStack_288,param_1);
      *param_3 = (uint)local_286;
      *param_5 = (uint)local_1d8;
      if (local_1d8 == 1) {
        *param_5 = 2;
      }
    }
  }
  FUN_40b9bea4(local_30);
  return;
}



/* 40b824a0 FUN_40b824a0 */

/* Boundary evidence: original MIPS .pdata 40b824a0..40b825cf. Semantic name remains unreviewed. */

undefined4 FUN_40b824a0(undefined1 *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint auStack_30 [2];
  uint local_28;
  char local_1c;
  
  local_40 = 0;
  FUN_40b811f0(auStack_30,param_1,param_3);
  if (local_1c == '\0') {
    if (local_28 < 0x11) {
      FUN_40b810b4(auStack_30,0x10);
    }
    else {
      local_28 = local_28 - 0x10;
    }
    if (local_1c == '\0') {
      if (local_28 < 0x11) {
        FUN_40b810b4(auStack_30,0x10);
      }
      else {
        local_28 = local_28 - 0x10;
      }
    }
  }
  puVar3 = &local_3c;
  puVar2 = &local_34;
  puVar1 = &local_40;
  FUN_40b820c0(auStack_30,puVar1,puVar2,puVar3,&local_38);
  if (param_2 == 0) {
    FUN_40b83ba4(0x40ba1028,puVar1,puVar2,(va_list)puVar3);
    return 0;
  }
  *(uint *)(param_2 + 8) = local_3c >> 3;
  *(char *)(param_2 + 2) = (char)(undefined2)local_38;
  *(char *)(param_2 + 3) = (char)((ushort)(undefined2)local_38 >> 8);
  uVar4 = *(uint *)(&DAT_40ba812c + local_34 * 4);
  *(uint *)(param_2 + 4) = uVar4;
  if (uVar4 < 0x5dc1) {
    *(uint *)(param_2 + 4) = uVar4 << 1;
  }
  return 0;
}



/* 40b825d0 FUN_40b825d0 */

/* Boundary evidence: original MIPS .pdata 40b825d0..40b82c23. Semantic name remains unreviewed. */

undefined4 FUN_40b825d0(uint *param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  *param_2 = 0;
  uVar1 = FUN_40b81000(param_1,1);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  *param_4 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 3) {
      FUN_40b810b4(param_1,2);
    }
    else {
      param_1[2] = param_1[2] - 2;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 3) {
      FUN_40b810b4(param_1,2);
    }
    else {
      param_1[2] = param_1[2] - 2;
    }
  }
  uVar1 = FUN_40b81000(param_1,4);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 5) {
      FUN_40b810b4(param_1,4);
    }
    else {
      param_1[2] = param_1[2] - 4;
    }
  }
  *param_3 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  uVar1 = FUN_40b81000(param_1,3);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 4) {
      FUN_40b810b4(param_1,3);
    }
    else {
      param_1[2] = param_1[2] - 3;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  *param_5 = uVar1;
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 2) {
      FUN_40b810b4(param_1,1);
    }
    else {
      param_1[2] = param_1[2] - 1;
    }
  }
  uVar1 = FUN_40b81000(param_1,0xd);
  if ((char)param_1[5] == '\0') {
    if (param_1[2] < 0xe) {
      FUN_40b810b4(param_1,0xd);
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
        FUN_40b810b4(param_1,0xb);
      }
      else {
        param_1[2] = param_1[2] - 0xb;
      }
    }
    if ((char)param_1[5] == '\0') {
      if (param_1[2] < 3) {
        FUN_40b810b4(param_1,2);
      }
      else {
        param_1[2] = param_1[2] - 2;
      }
    }
    uVar1 = FUN_40b81000(param_1,3);
    if ((char)param_1[5] == '\0') {
      if (param_1[2] < 4) {
        FUN_40b810b4(param_1,3);
      }
      else {
        param_1[2] = param_1[2] - 3;
      }
    }
    if (uVar1 == 1) {
      FUN_40b8116c(param_1,4);
      uVar1 = FUN_40b8116c(param_1,1);
      if (uVar1 != 0) {
        FUN_40b8116c(param_1,1);
        uVar1 = FUN_40b8116c(param_1,2);
        FUN_40b8116c(param_1,1);
        if (uVar1 == 2) {
          uVar1 = FUN_40b8116c(param_1,4);
          uVar3 = 7;
        }
        else {
          uVar1 = FUN_40b8116c(param_1,6);
          uVar3 = 1;
        }
        FUN_40b8116c(param_1,uVar3);
        uVar3 = FUN_40b8116c(param_1,2);
        if ((uVar3 == 1) && (uVar1 != 0)) {
          uVar3 = 0;
          do {
            if ((char)param_1[5] == '\0') {
              if (param_1[2] < 2) {
                FUN_40b810b4(param_1,1);
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
            FUN_40b810b4(param_1,8);
          }
          else {
            param_1[2] = param_1[2] - 8;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 0xd) {
            FUN_40b810b4(param_1,0xc);
          }
          else {
            param_1[2] = param_1[2] - 0xc;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 9) {
            FUN_40b810b4(param_1,8);
          }
          else {
            param_1[2] = param_1[2] - 8;
          }
        }
        if ((char)param_1[5] == '\0') {
          if (param_1[2] < 0xd) {
            FUN_40b810b4(param_1,0xc);
          }
          else {
            param_1[2] = param_1[2] - 0xc;
          }
        }
        uVar1 = FUN_40b81000(param_1,3);
        if (uVar1 == 6) {
          if ((char)param_1[5] == '\0') {
            if (param_1[2] < 4) {
              FUN_40b810b4(param_1,3);
            }
            else {
              param_1[2] = param_1[2] - 3;
            }
          }
          uVar1 = FUN_40b8116c(param_1,4);
          if (uVar1 == 0xf) {
            uVar1 = FUN_40b8116c(param_1,8);
            uVar1 = uVar1 + 0xe;
          }
          if ((uVar1 != 0) && ((uVar1 = FUN_40b81000(param_1,4), uVar1 == 0xd || (uVar1 == 0xe)))) {
            *param_2 = 1;
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b82c24 FUN_40b82c24 */

/* Boundary evidence: original MIPS .pdata 40b82c24..40b82f63. Semantic name remains unreviewed. */

undefined4
FUN_40b82c24(char *param_1,int param_2,undefined4 *param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  void *_Memory;
  int iVar8;
  int local_80;
  uint local_7c;
  uint local_78;
  void *local_74;
  int *local_70;
  int local_6c;
  uint local_68;
  int local_64 [2];
  char *local_5c;
  undefined4 *local_58;
  uint auStack_50 [2];
  uint local_48;
  char local_3c;
  
  _Memory = (void *)0x0;
  local_7c = 0;
  local_68 = 0;
  local_64[1] = 0;
  iVar4 = 0;
  local_64[0] = 0;
  local_80 = 0;
  iVar6 = 0;
  iVar8 = 0;
  local_74 = (void *)0x0;
  uVar5 = 0;
  local_6c = 0;
  if (-1 < param_5) {
    iVar7 = 0;
    local_70 = param_4;
    local_5c = param_1;
    local_58 = param_3;
    do {
      if ((*param_1 != -1) || ((param_1[1] & 0xf6U) != 0xf0)) break;
      iVar8 = iVar8 + 1;
      if (uVar5 == 0) {
        FUN_40b811f0(auStack_50,param_1,param_5 - iVar6);
        if (local_3c == '\0') {
          if (local_48 < 0xd) {
            FUN_40b810b4(auStack_50,0xc);
          }
          else {
            local_48 = local_48 - 0xc;
          }
        }
        iVar1 = FUN_40b825d0(auStack_50,local_64,&local_68,(uint *)(local_64 + 1),&local_78);
        if (iVar1 != 0) {
          return 0;
        }
        if (local_78 == 0) {
          return 0;
        }
        if (local_78 == 1) {
          local_78 = 2;
        }
        *(char *)(param_2 + 2) = (char)(local_78 & 0xffff);
        *(char *)(param_2 + 3) = (char)((local_78 & 0xffff) >> 8);
        param_4 = local_70;
        _Memory = local_74;
      }
      uVar3 = (((byte)param_1[3] & 3) << 8 | (uint)(byte)param_1[4]) << 3 |
              (uint)((byte)param_1[5] >> 5);
      local_7c = uVar3 + local_7c;
      if (iVar4 == 0x2b) {
        iVar4 = 0;
LAB_40b82dc8:
        if (param_4 != (int *)0x0) {
          _Memory = realloc(_Memory,iVar7 + 4);
          *(int *)(iVar7 + (int)_Memory) = local_6c + param_6;
          param_4 = local_70;
          local_74 = _Memory;
        }
        local_80 = local_80 + 1;
        iVar7 = iVar7 + 4;
      }
      else if (iVar4 == 0) goto LAB_40b82dc8;
      iVar6 = iVar6 + uVar3;
      param_1 = param_1 + uVar3;
      if (param_5 + -0x400 <= iVar6) break;
      local_6c = (int)param_1 - (int)local_5c;
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar6 <= param_5);
    if (5 < iVar8) {
      if (param_4 != (int *)0x0) {
        *param_4 = local_80;
        *local_58 = _Memory;
      }
      uVar3 = *(uint *)(&DAT_40ba812c + local_68 * 4);
      puVar2 = (uint *)(param_2 + 4);
      *puVar2 = uVar3;
      if (uVar5 != 0) {
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        iVar4 = (local_7c / uVar5) * uVar3;
        if (iVar4 < 0) {
          iVar4 = iVar4 + 0x7f;
        }
        uVar3 = iVar4 >> 10;
        if (iVar4 >> 7 < 0) {
          uVar3 = (iVar4 >> 7) + 7 >> 3;
        }
      }
      *(uint *)(param_2 + 8) = uVar3;
      if (local_64[0] == 0) {
        if (*puVar2 < 0x5dc1) {
          *puVar2 = *puVar2 << 1;
        }
        return 1;
      }
      *puVar2 = *puVar2 << 1;
      return 1;
    }
  }
  return 0;
}



/* 40b82f64 FUN_40b82f64 */

/* Boundary evidence: original MIPS .pdata 40b82f64..40b831cb. Semantic name remains unreviewed. */

undefined4
FUN_40b82f64(char *param_1,undefined1 *param_2,undefined4 *param_3,int *param_4,uint param_5,
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
  
  local_30 = DAT_40ba9854;
  memset(param_2,0,0x12);
  *param_6 = 0;
  pcVar6 = "ID3";
  pcVar5 = param_1;
  do {
    cVar1 = *pcVar5;
    cVar2 = *pcVar6;
    if (cVar1 == '\0') break;
    if (cVar1 != cVar2) goto LAB_40b83048;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (pcVar5 != param_1 + 3);
  if (cVar1 == cVar2) {
    uVar7 = (((uint)(byte)param_1[6] << 7 | (uint)(byte)param_1[7]) << 7 | (uint)(byte)param_1[8])
            << 7 | (uint)(byte)param_1[9];
    if ((int)uVar7 <= (int)param_5) {
      param_1 = param_1 + uVar7;
      param_5 = param_5 - uVar7;
      goto LAB_40b83048;
    }
LAB_40b83194:
    FUN_40b9bea4(local_30);
    uVar3 = 1;
  }
  else {
LAB_40b83048:
    strncpy_s(local_38,5,param_1,4);
    pcVar5 = local_38;
    local_34[0] = '\0';
    pcVar6 = "ADIF";
    do {
      cVar1 = *pcVar5;
      cVar2 = *pcVar6;
      if (cVar1 == '\0') break;
      if (cVar1 != cVar2) goto LAB_40b830b8;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (pcVar5 != local_34);
    if (cVar1 == cVar2) {
      FUN_40b824a0(param_1,(int)param_2,param_5);
    }
    else {
LAB_40b830b8:
      iVar8 = 0;
      if (0 < (int)(param_5 - 300)) {
        do {
          if ((param_1[iVar8] == -1) && ((param_1[iVar8 + 1] & 0xf6U) == 0xf0)) {
            iVar4 = FUN_40b82c24(param_1 + iVar8,(int)param_2,param_3,param_4,param_5 - iVar8,iVar8)
            ;
            if (iVar4 != 0) {
              *param_6 = iVar8;
              goto LAB_40b83154;
            }
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(param_5 - 300));
      }
      if ((*param_1 != '!') || (param_1[1] != '\f')) goto LAB_40b83194;
      *(undefined4 *)(param_2 + 4) = 0xac44;
      param_2[2] = 2;
      *(undefined4 *)(param_2 + 8) = 0x31ce;
      param_2[3] = 0;
      *param_2 = 0xff;
      param_2[1] = 0;
    }
LAB_40b83154:
    FUN_40b9bea4(local_30);
    uVar3 = 0;
  }
  return uVar3;
}



/* 40b831cc FUN_40b831cc */

/* Boundary evidence: original MIPS .pdata 40b831cc..40b831e7. Semantic name remains unreviewed. */

void FUN_40b831cc(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  return;
}



/* 40b831e8 FUN_40b831e8 */

/* Boundary evidence: original MIPS .pdata 40b831e8..40b8324f. Semantic name remains unreviewed. */

undefined4 * FUN_40b831e8(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_40b98350(param_1,L"CSequential Allocator",param_2,param_3);
  *param_1 = &PTR_FUN_40ba1098;
  param_1[3] = &PTR_FUN_40ba106c;
  param_1[0x16] = param_1[0x1a];
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  return param_1;
}



/* 40b83250 FUN_40b83250 */

/* Boundary evidence: original MIPS .pdata 40b83250..40b83277. Semantic name remains unreviewed. */

void FUN_40b83250(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b83278 FUN_40b83278 */

/* Boundary evidence: original MIPS .pdata 40b83278..40b8329f. Semantic name remains unreviewed. */

void FUN_40b83278(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b832a0 FUN_40b832a0 */

/* Boundary evidence: original MIPS .pdata 40b832a0..40b832c7. Semantic name remains unreviewed. */

void FUN_40b832a0(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b832c8 FUN_40b832c8 */

/* Boundary evidence: original MIPS .pdata 40b832c8..40b83333. Semantic name remains unreviewed. */

void FUN_40b832c8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40ba1098;
  param_1[3] = &PTR_FUN_40ba106c;
  if ((void *)param_1[0x17] != (void *)0x0) {
    operator_delete((void *)param_1[0x17]);
  }
  FUN_40b963c0(param_1);
  return;
}



/* 40b83334 FUN_40b83334 */

/* Boundary evidence: original MIPS .pdata 40b83334..40b83363. Semantic name remains unreviewed. */

void FUN_40b83334(void)

{
  undefined4 *in_v0;
  
  FUN_40b963c0((undefined4 *)*in_v0);
  return;
}



/* 40b83364 FUN_40b83364 */

/* Boundary evidence: original MIPS .pdata 40b83364..40b83523. Semantic name remains unreviewed. */

undefined4 FUN_40b83364(int param_1,undefined4 *param_2)

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
        FUN_40b96148((int *)(param_1 + 0x18),(int)piVar2);
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
        if (piVar2 != (int *)0x0) goto LAB_40b83490;
        break;
      }
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_40b95f14(param_1 + -0xc);
    }
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    piVar2 = piVar3;
LAB_40b83490:
    LeaveCriticalSection(lpCriticalSection);
    if (piVar2 != (int *)0x0) {
      (**(code **)*piVar2)(piVar2,&DAT_40ba50d8,param_2);
      return 0;
    }
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x20),0xffffffff);
    piVar3 = piVar2;
  } while( true );
}



/* 40b83524 FUN_40b83524 */

/* Boundary evidence: original MIPS .pdata 40b83524..40b83553. Semantic name remains unreviewed. */

void FUN_40b83524(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x2c));
  return;
}



/* 40b83554 FUN_40b83554 */

/* Boundary evidence: original MIPS .pdata 40b83554..40b835c3. Semantic name remains unreviewed. */

void FUN_40b83554(int param_1,int *param_2)

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



/* 40b835c4 FUN_40b835c4 */

undefined4 FUN_40b835c4(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x60);
  return *(undefined4 *)(param_1 + 100);
}



/* 40b835d4 FUN_40b835d4 */

/* Boundary evidence: original MIPS .pdata 40b835d4..40b837e3. Semantic name remains unreviewed. */

int FUN_40b835d4(int param_1)

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



/* 40b837e4 FUN_40b837e4 */

/* Boundary evidence: original MIPS .pdata 40b837e4..40b8382f. Semantic name remains unreviewed. */

undefined4 * FUN_40b837e4(undefined4 *param_1,uint param_2)

{
  FUN_40b832c8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b83830 FUN_40b83830 */

/* Boundary evidence: original MIPS .pdata 40b83830..40b839db. Semantic name remains unreviewed. */

int FUN_40b83830(int param_1)

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
    iVar2 = FUN_40b983a0(param_1);
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



/* 40b839dc FUN_40b839dc */

/* Boundary evidence: original MIPS .pdata 40b839dc..40b83a0b. Semantic name remains unreviewed. */

void FUN_40b839dc(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b83a0c FUN_40b83a0c */

/* Boundary evidence: original MIPS .pdata 40b83a0c..40b83b87. Semantic name remains unreviewed. */

int FUN_40b83a0c(int param_1,int param_2)

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
    iVar1 = FUN_40b835d4(param_1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b83b88 FUN_40b83b88 */

/* Boundary evidence: original MIPS .pdata 40b83b88..40b83ba3. Semantic name remains unreviewed. */

void FUN_40b83b88(int param_1)

{
  FUN_40b83a0c(param_1,*(int *)(param_1 + 0x60));
  return;
}



/* 40b83ba4 FUN_40b83ba4 */

/* Boundary evidence: original MIPS .pdata 40b83ba4..40b83c6f. Semantic name remains unreviewed. */

void FUN_40b83ba4(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

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
  
  local_10 = DAT_40ba9854;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(local_210,param_1,(wchar_t *)&local_res4,param_4);
  pWVar5 = L"TSDEMUX: ";
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
  FUN_40b9bea4(local_10);
  return;
}



/* 40b83c70 FUN_40b83c70 */

/* Boundary evidence: original MIPS .pdata 40b83c70..40b83cc7. Semantic name remains unreviewed. */

void FUN_40b83c70(int param_1)

{
  HANDLE hHandle;
  
  hHandle = (HANDLE)InterlockedExchange((LONG *)(param_1 + 0x14),0);
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  return;
}



/* 40b83cc8 FUN_40b83cc8 */

/* Boundary evidence: original MIPS .pdata 40b83cc8..40b83d17. Semantic name remains unreviewed. */

undefined4 * FUN_40b83cc8(undefined4 *param_1)

{
  FUN_40b99110((int)param_1);
  *param_1 = &PTR_FUN_40ba11c4;
  param_1[0x10] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 1;
  param_1[0x1a] = 2;
  return param_1;
}



/* 40b83d18 FUN_40b83d18 */

/* Boundary evidence: original MIPS .pdata 40b83d18..40b83e03. Semantic name remains unreviewed. */

void FUN_40b83d18(int param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,int param_6)

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



/* 40b83e04 FUN_40b83e04 */

/* Boundary evidence: original MIPS .pdata 40b83e04..40b83f03. Semantic name remains unreviewed. */

int FUN_40b83e04(LPVOID param_1)

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
    bVar1 = FUN_40b991fc(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      LeaveCriticalSection(lpCriticalSection);
      return -0x7fffbffb;
    }
  }
  *(undefined4 *)((int)param_1 + 0x68) = 1;
  iVar2 = FUN_40b992b0((int)param_1,1);
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40b83f04 FUN_40b83f04 */

/* Boundary evidence: original MIPS .pdata 40b83f04..40b83f33. Semantic name remains unreviewed. */

void FUN_40b83f04(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b83f34 FUN_40b83f34 */

/* Boundary evidence: original MIPS .pdata 40b83f34..40b84027. Semantic name remains unreviewed. */

int FUN_40b83f34(int param_1)

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
      iVar1 = FUN_40b992b0(param_1,0);
      (**(code **)(**(int **)(param_1 + 0x40) + 0x28))();
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar1;
}



/* 40b84028 FUN_40b84028 */

/* Boundary evidence: original MIPS .pdata 40b84028..40b84057. Semantic name remains unreviewed. */

void FUN_40b84028(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b84058 FUN_40b84058 */

/* Boundary evidence: original MIPS .pdata 40b84058..40b84183. Semantic name remains unreviewed. */

int FUN_40b84058(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

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
      FUN_40b992b0(param_1,2);
      (**(code **)(**(int **)(param_1 + 0x40) + 0x28))();
      FUN_40b83c70(param_1);
      if ((*(int **)(param_1 + 0x60) != (int *)0x0) &&
         (iVar1 = (**(code **)(**(int **)(param_1 + 0x60) + 0x18))(), iVar1 < 0)) {
        FUN_40b83ba4(0x40ba1270,iVar1,param_3,param_4);
      }
      LeaveCriticalSection(lpCriticalSection);
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40b84184 FUN_40b84184 */

/* Boundary evidence: original MIPS .pdata 40b84184..40b841b3. Semantic name remains unreviewed. */

void FUN_40b84184(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b841b4 FUN_40b841b4 */

/* Boundary evidence: original MIPS .pdata 40b841b4..40b8426f. Semantic name remains unreviewed. */

undefined4
FUN_40b841b4(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5,
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



/* 40b84270 FUN_40b84270 */

/* Boundary evidence: original MIPS .pdata 40b84270..40b84857. Semantic name remains unreviewed. */

void FUN_40b84270(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

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
      FUN_40b83ba4(0x40ba1330,param_2,param_3,param_4);
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
        iVar5 = FUN_40b99374((int)param_1,&uStack_4c);
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
          if (-1 < param_1[0x19]) goto LAB_40b84520;
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
LAB_40b84520:
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
        iVar5 = FUN_40b841b4(param_1,local_58,local_40,local_3c,local_48,local_44);
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



/* 40b84858 FUN_40b84858 */

/* Boundary evidence: original MIPS .pdata 40b84858..40b848d3. Semantic name remains unreviewed. */

void FUN_40b84858(int param_1,int param_2,int **param_3,va_list param_4)

{
  int iVar1;
  int *local_10;
  char acStack_c [4];
  
  iVar1 = *(int *)(param_1 + 0x40);
  while( true ) {
    if (iVar1 == 0) {
      FUN_40b83ba4(0x40ba1370,param_2,param_3,param_4);
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



/* 40b848d4 FUN_40b848d4 */

/* Boundary evidence: original MIPS .pdata 40b848d4..40b84973. Semantic name remains unreviewed. */

undefined4 FUN_40b848d4(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  FUN_40b84058(param_1,param_2,param_3,param_4);
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



/* 40b84974 FUN_40b84974 */

/* Boundary evidence: original MIPS .pdata 40b84974..40b849a3. Semantic name remains unreviewed. */

void FUN_40b84974(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b849a4 FUN_40b849a4 */

/* Boundary evidence: original MIPS .pdata 40b849a4..40b849bf. Semantic name remains unreviewed. */

void FUN_40b849a4(LPVOID param_1)

{
  FUN_40b83e04(param_1);
  return;
}



/* 40b849c0 FUN_40b849c0 */

/* Boundary evidence: original MIPS .pdata 40b849c0..40b849df. Semantic name remains unreviewed. */

undefined4 FUN_40b849c0(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  FUN_40b84058(param_1,param_2,param_3,param_4);
  return 0;
}



/* 40b849e0 FUN_40b849e0 */

/* Boundary evidence: original MIPS .pdata 40b849e0..40b84a7b. Semantic name remains unreviewed. */

bool FUN_40b849e0(int *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  iVar1 = param_1[0x1a];
  if (iVar1 == 1) {
    (**(code **)(*param_1 + 0x14))(param_1);
    FUN_40b83f34((int)param_1);
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar1 == 1;
}



/* 40b84a7c FUN_40b84a7c */

/* Boundary evidence: original MIPS .pdata 40b84a7c..40b84aab. Semantic name remains unreviewed. */

void FUN_40b84a7c(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b84aac FUN_40b84aac */

/* Boundary evidence: original MIPS .pdata 40b84aac..40b84b57. Semantic name remains unreviewed. */

bool FUN_40b84aac(int *param_1,int param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  iVar1 = param_1[0x1a];
  param_1[0x19] = param_2;
  if (iVar1 == 1) {
    (**(code **)(*param_1 + 0x14))(param_1);
    FUN_40b83f34((int)param_1);
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar1 == 1;
}



/* 40b84b58 FUN_40b84b58 */

/* Boundary evidence: original MIPS .pdata 40b84b58..40b84b87. Semantic name remains unreviewed. */

void FUN_40b84b58(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b84b88 FUN_40b84b88 */

/* Boundary evidence: original MIPS .pdata 40b84b88..40b84c5b. Semantic name remains unreviewed. */

undefined4 FUN_40b84b88(int *param_1,int param_2,int **param_3,va_list param_4)

{
  int iVar1;
  
  do {
    iVar1 = FUN_40b9933c((int)param_1);
    if (iVar1 == 0) {
      param_2 = 0;
      FUN_40b993d8((int)param_1,0);
    }
    else if (iVar1 == 1) {
      param_2 = 0;
      FUN_40b993d8((int)param_1,0);
      FUN_40b84270(param_1,param_2,param_3,param_4);
    }
    else if (iVar1 == 2) {
      FUN_40b993d8((int)param_1,0);
      return 0;
    }
    if ((int *)param_1[0x10] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x10] + 0x24))();
      FUN_40b84858((int)param_1,param_2,param_3,param_4);
      (**(code **)(*(int *)param_1[0x10] + 0x28))();
    }
  } while( true );
}



/* 40b84c5c FUN_40b84c5c */

/* Boundary evidence: original MIPS .pdata 40b84c5c..40b84cb3. Semantic name remains unreviewed. */

void FUN_40b84c5c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  *param_1 = &PTR_FUN_40ba11c4;
  FUN_40b848d4((int)param_1,param_2,param_3,param_4);
  FUN_40b9918c((int)param_1);
  return;
}



/* 40b84cb4 FUN_40b84cb4 */

/* Boundary evidence: original MIPS .pdata 40b84cb4..40b84ce3. Semantic name remains unreviewed. */

void FUN_40b84cb4(void)

{
  int *in_v0;
  
  FUN_40b9918c(*in_v0);
  return;
}



/* 40b84ce4 FUN_40b84ce4 */

/* Boundary evidence: original MIPS .pdata 40b84ce4..40b84e9f. Semantic name remains unreviewed. */

int FUN_40b84ce4(int param_1,undefined4 *param_2,undefined4 param_3,va_list param_4)

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
    iVar5 = (**(code **)*param_2)(param_2,&DAT_40ba5268,piVar6);
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
          FUN_40b848d4(param_1,param_3,puVar3,param_4);
          LeaveCriticalSection(lpCriticalSection);
          return iVar5;
        }
      }
      puVar4 = auStack_38;
      puVar2 = &local_40;
      iVar5 = (**(code **)(*(int *)*piVar6 + 0x20))();
      if (iVar5 < 0) {
        FUN_40b848d4(param_1,puVar2,puVar4,param_4);
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



/* 40b84ea0 FUN_40b84ea0 */

/* Boundary evidence: original MIPS .pdata 40b84ea0..40b84ecf. Semantic name remains unreviewed. */

void FUN_40b84ea0(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x48));
  return;
}



/* 40b84ed0 FUN_40b84ed0 */

/* Boundary evidence: original MIPS .pdata 40b84ed0..40b84f1b. Semantic name remains unreviewed. */

undefined4 * FUN_40b84ed0(undefined4 *param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  FUN_40b84c5c(param_1,param_2,param_3,param_4);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b84f1c FUN_40b84f1c */

/* Boundary evidence: original MIPS .pdata 40b84f1c..40b85183. Semantic name remains unreviewed. */

undefined4 FUN_40b84f1c(void *param_1,undefined4 param_2,int param_3,va_list param_4)

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
      iVar4 = *(int *)(&DAT_40ba1844 + iVar5);
      *(int *)(param_3 + 0x24) = iVar4 >> 0x1f;
      *(int *)(param_3 + 0x20) = iVar4;
      *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(&DAT_40ba1884 + iVar5);
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
      iVar4 = MulDiv(2000,*(int *)(&DAT_40ba18a8 + (uVar3 >> 4) * 4),10000);
      *(int *)(param_3 + 0x38) = iVar4;
      uVar3 = ((*(byte *)((int)param_1 + 10) & 0x1f) << 5 |
              (uint)(*(byte *)((int)param_1 + 0xb) >> 3)) << 0xb;
      *(uint *)(param_3 + 0x1c) = uVar3;
      if (((*(byte *)((int)param_1 + 0xb) & 4) != 0) && (0xa000 < uVar3)) {
        FUN_40b83ba4(0x40ba19d4,uVar3,uVar2,param_4);
        *(undefined4 *)(param_3 + 0x1c) = 0xa000;
      }
      if (*(int *)(param_3 + 0x1c) < 20000) {
        FUN_40b83ba4(0x40ba1990,*(int *)(param_3 + 0x1c),uVar2,param_4);
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
  FUN_40b83ba4((size_t)pwVar1,param_2,param_3,param_4);
  return 0;
}



/* 40b85184 FUN_40b85184 */

bool FUN_40b85184(int *param_1,uint *param_2)

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



/* 40b851e4 FUN_40b851e4 */

/* Boundary evidence: original MIPS .pdata 40b851e4..40b8543b. Semantic name remains unreviewed. */

undefined4 FUN_40b851e4(char *param_1,int param_2,undefined4 param_3,va_list param_4)

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
LAB_40b85298:
    *(undefined4 *)(param_2 + 4) = uVar3;
  }
  else if (bVar4 == 1) {
    *(undefined4 *)(param_2 + 4) = 0xac44;
  }
  else if (bVar4 == 2) {
    uVar3 = 32000;
    goto LAB_40b85298;
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
    goto LAB_40b853b0;
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
LAB_40b853b0:
    bVar4 = bVar4 & 1;
    break;
  default:
    FUN_40b83ba4(0x40ba1a6c,param_2,param_3,param_4);
    goto LAB_40b853d0;
  }
  if (bVar4 != 0) {
    local_18 = local_18 + 1;
  }
LAB_40b853d0:
  iVar5 = *(int *)(uVar6 * 4 + 0x40ba8324) * 1000;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 7;
  }
  *(char *)(param_2 + 2) = (char)(local_18 & 0xffff);
  *(int *)(param_2 + 8) = iVar5 >> 3;
  *(char *)(param_2 + 3) = (char)((local_18 & 0xffff) >> 8);
  return 1;
}



/* 40b8543c FUN_40b8543c */

/* Boundary evidence: original MIPS .pdata 40b8543c..40b8569b. Semantic name remains unreviewed. */

undefined4 FUN_40b8543c(undefined1 *param_1,undefined1 *param_2)

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
    uVar7 = (uint)(*(ushort *)(&DAT_40ba1788 + uVar8 * 2) >> bVar1 + uVar5);
    uVar5 = (uint)*(ushort *)(&DAT_40ba1790 + ((uVar5 * 3 + uVar6) * 0xf + uVar9 + -0xf) * 2) * 1000
    ;
    if ((byte)param_1[3] >> 6 == 3) goto LAB_40b855e8;
  }
  uVar10 = 2;
LAB_40b855e8:
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



/* 40b8569c FUN_40b8569c */

/* Boundary evidence: original MIPS .pdata 40b8569c..40b85777. Semantic name remains unreviewed. */

undefined4 FUN_40b8569c(char *param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  int local_18 [4];
  
  if ((3 < param_2) &&
     ((((param_1[4] != 'f' || (param_1[5] != 't')) || (param_1[6] != 'y')) || (param_1[7] != 'p'))))
  {
    local_18[1] = 0;
    local_18[0] = 0;
    iVar1 = FUN_40b82f64(param_1,param_3,local_18 + 1,local_18,param_2,local_18 + 2);
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



/* 40b85778 FUN_40b85778 */

uint FUN_40b85778(undefined4 *param_1,uint param_2)

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



/* 40b8594c FUN_40b8594c */

/* Boundary evidence: original MIPS .pdata 40b8594c..40b85983. Semantic name remains unreviewed. */

void FUN_40b8594c(int param_1)

{
  if (param_1 != 0) {
    FUN_40b985a0();
    return;
  }
  FUN_40b985a0();
  return;
}



/* 40b85984 FUN_40b85984 */

/* Boundary evidence: original MIPS .pdata 40b85984..40b859f3. Semantic name remains unreviewed. */

void FUN_40b85984(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40ba1c44;
  param_1[3] = &PTR_FUN_40ba1bf4;
  param_1[4] = &PTR_LAB_40ba1bbc;
  FUN_40b99a84(param_1 + 0xf);
  FUN_40b985a0();
  return;
}



/* 40b859f4 FUN_40b859f4 */

/* Boundary evidence: original MIPS .pdata 40b859f4..40b85a23. Semantic name remains unreviewed. */

void FUN_40b859f4(void)

{
  int *in_v0;
  
  FUN_40b8594c(*in_v0);
  return;
}



/* 40b85a24 FUN_40b85a24 */

/* Boundary evidence: original MIPS .pdata 40b85a24..40b85a4b. Semantic name remains unreviewed. */

void FUN_40b85a24(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b85a4c FUN_40b85a4c */

/* Boundary evidence: original MIPS .pdata 40b85a4c..40b85a73. Semantic name remains unreviewed. */

void FUN_40b85a4c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b85a74 FUN_40b85a74 */

/* Boundary evidence: original MIPS .pdata 40b85a74..40b85a9b. Semantic name remains unreviewed. */

void FUN_40b85a74(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b85a9c FUN_40b85a9c */

/* Boundary evidence: original MIPS .pdata 40b85a9c..40b85b8b. Semantic name remains unreviewed. */

void FUN_40b85a9c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ba5138,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b98690(piVar2,param_3);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40ba6ad8,0x10);
    if (iVar1 == 0) {
      piVar2 = param_1 + 4;
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      FUN_40b98690(piVar2,param_3);
    }
    else {
      iVar1 = memcmp(param_2,&DAT_40ba6f80,0x10);
      if (iVar1 == 0) {
        piVar2 = param_1 + 4;
        if (param_1 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        FUN_40b98690(piVar2,param_3);
      }
      else {
        FUN_40b9872c(param_1,param_2,param_3);
      }
    }
  }
  return;
}



/* 40b85b8c FUN_40b85b8c */

/* Boundary evidence: original MIPS .pdata 40b85b8c..40b85bd7. Semantic name remains unreviewed. */

bool FUN_40b85b8c(int *param_1,uint *param_2)

{
  uint local_10 [2];
  
  (**(code **)(*param_1 + 0xc))(param_1,local_10);
  return (~local_10[0] & *param_2) != 0;
}



/* 40b85c00 FUN_40b85c00 */

/* Boundary evidence: original MIPS .pdata 40b85c00..40b85c8f. Semantic name remains unreviewed. */

undefined4 FUN_40b85c00(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 auStack_20 [16];
  uint local_10;
  
  local_10 = DAT_40ba9854;
  if (param_2 == (int *)0x0) {
    param_2 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,auStack_20);
  if ((-1 < iVar1) && (iVar1 = memcmp(auStack_20,param_2,0x10), iVar1 == 0)) {
    FUN_40b9bea4(local_10);
    return 0;
  }
  FUN_40b9bea4(local_10);
  return 1;
}



/* 40b85c90 FUN_40b85c90 */

/* Boundary evidence: original MIPS .pdata 40b85c90..40b85cef. Semantic name remains unreviewed. */

undefined4 FUN_40b85c90(int param_1,int *param_2)

{
  if (*(int *)(param_1 + 0x24) == 0 && *(int *)(param_1 + 0x28) == 0) {
    FUN_40b901d8(*(int *)(param_1 + 0x2c));
  }
  *param_2 = *(int *)(param_1 + 0x24);
  param_2[1] = *(int *)(param_1 + 0x28);
  return 0;
}



/* 40b85d34 FUN_40b85d34 */

/* Boundary evidence: original MIPS .pdata 40b85d34..40b85d57. Semantic name remains unreviewed. */

void FUN_40b85d34(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  FUN_40b92c18(*(int *)(param_1 + 0x2c),param_2,param_3,param_4);
  return;
}



/* 40b85d98 FUN_40b85d98 */

/* Boundary evidence: original MIPS .pdata 40b85d98..40b85deb. Semantic name remains unreviewed. */

undefined4 FUN_40b85d98(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b90274(*(int *)(param_1 + 0x28));
  if (iVar1 != 0) {
    *param_2 = 1;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



/* 40b85df8 FUN_40b85df8 */

/* Boundary evidence: original MIPS .pdata 40b85df8..40b85e1f. Semantic name remains unreviewed. */

void FUN_40b85df8(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0x44))();
  return;
}



/* 40b85e20 FUN_40b85e20 */

/* Boundary evidence: original MIPS .pdata 40b85e20..40b85e47. Semantic name remains unreviewed. */

void FUN_40b85e20(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0x48))();
  return;
}



/* 40b85e48 FUN_40b85e48 */

/* Boundary evidence: original MIPS .pdata 40b85e48..40b85e63. Semantic name remains unreviewed. */

void FUN_40b85e48(int param_1,undefined4 *param_2)

{
  FUN_40b99ab4(param_1 + 0x2c,param_2);
  return;
}



/* 40b85e64 FUN_40b85e64 */

/* Boundary evidence: original MIPS .pdata 40b85e64..40b85e93. Semantic name remains unreviewed. */

void FUN_40b85e64(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  FUN_40b99adc((int *)(param_1 + 0x2c),&DAT_40ba5138,param_2,param_3,param_4);
  return;
}



/* 40b85e94 FUN_40b85e94 */

/* Boundary evidence: original MIPS .pdata 40b85e94..40b85ec7. Semantic name remains unreviewed. */

void FUN_40b85e94(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_40b99c78((int *)(param_1 + 0x2c),&DAT_40ba5138,param_3,param_4,param_5,param_6);
  return;
}



/* 40b85ec8 FUN_40b85ec8 */

/* Boundary evidence: original MIPS .pdata 40b85ec8..40b85faf. Semantic name remains unreviewed. */

int FUN_40b85ec8(int *param_1,undefined4 param_2,void *param_3,undefined4 param_4,undefined2 param_5
                ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int *piVar2;
  int *local_18 [2];
  
  iVar1 = memcmp(&DAT_40ba6f70,param_3,0x10);
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



/* 40b85fec FUN_40b85fec */

/* Boundary evidence: original MIPS .pdata 40b85fec..40b86037. Semantic name remains unreviewed. */

undefined4 * FUN_40b85fec(undefined4 *param_1,uint param_2)

{
  FUN_40b85984(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b86038 FUN_40b86038 */

/* Boundary evidence: original MIPS .pdata 40b86038..40b8608b. Semantic name remains unreviewed. */

undefined4 FUN_40b86038(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b90274(*(int *)(param_1 + 0x2c));
  if (iVar1 != 0) {
    *param_2 = 0x37;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



/* 40b8608c FUN_40b8608c */

/* Boundary evidence: original MIPS .pdata 40b8608c..40b860ff. Semantic name remains unreviewed. */

undefined4 FUN_40b8608c(int param_1,void *param_2)

{
  int iVar1;
  
  if (param_2 == (void *)0x0) {
    param_2 = (void *)(param_1 + 0x34);
  }
  iVar1 = FUN_40b90274(*(int *)(param_1 + 0x2c));
  if ((iVar1 != 0) && (iVar1 = FUN_40b90200(*(undefined4 *)(param_1 + 0x2c),param_2), iVar1 == 0)) {
    return 0;
  }
  return 1;
}



/* 40b86100 FUN_40b86100 */

/* Boundary evidence: original MIPS .pdata 40b86100..40b86183. Semantic name remains unreviewed. */

undefined4 FUN_40b86100(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40b90274(*(int *)(param_1 + 0x2c));
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



/* 40b86184 FUN_40b86184 */

/* Boundary evidence: original MIPS .pdata 40b86184..40b862db. Semantic name remains unreviewed. */

undefined4 FUN_40b86184(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    param_2 = param_1 + 0xd;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,param_1 + 0xd,0x10);
    if (iVar1 != 0) {
      iVar1 = FUN_40b90274(param_1[0xb]);
      if ((iVar1 == 0) || (iVar1 = FUN_40b9024c(param_1[0xb],param_2), iVar1 != 0)) {
        return 0x80004005;
      }
      (**(code **)(*param_1 + 0x34))(param_1,param_1 + 5,param_2);
      (**(code **)(*param_1 + 0x34))(param_1,param_1 + 7,param_2);
      param_1[0xd] = *param_2;
      param_1[0xe] = param_2[1];
      param_1[0xf] = param_2[2];
      param_1[0x10] = param_2[3];
      FUN_40b91af0();
    }
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40ba6838,0x10);
    if (iVar1 != 0) {
      return 0x80004001;
    }
  }
  return 0;
}



/* 40b862dc FUN_40b862dc */

/* Boundary evidence: original MIPS .pdata 40b862dc..40b86347. Semantic name remains unreviewed. */

undefined4 FUN_40b862dc(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b90274(*(int *)(param_1 + 0x2c));
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



/* 40b86348 FUN_40b86348 */

/* Boundary evidence: original MIPS .pdata 40b86348..40b8654f. Semantic name remains unreviewed. */

undefined4
FUN_40b86348(int *param_1,uint *param_2,int *param_3,undefined4 param_4,uint param_5,uint param_6,
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
  
  iVar1 = FUN_40b90274(param_1[0xb]);
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
  FUN_40b901d8(param_1[0xb]);
  FUN_40b901d8(param_1[0xb]);
  if ((param_5 != local_20) || (uVar2 = local_28, uVar3 = local_24, param_6 != local_1c)) {
    if (param_5 == 0 && param_6 == 0) {
      uVar2 = 0;
      uVar3 = 0;
      goto LAB_40b86474;
    }
    if (((int)local_24 < (int)local_1c) || ((local_24 == local_1c && (local_28 <= local_20)))) {
      uVar2 = 0;
      uVar3 = 0;
    }
    else {
      uVar2 = local_20 - 1;
      uVar3 = local_1c - (local_20 == 0);
    }
    uVar2 = FUN_40b98c68(param_5,param_6,local_28,local_24,local_20,local_1c,uVar2,uVar3);
    uVar3 = extraout_v1;
  }
  if (((int)uVar3 < 1) && (uVar3 != 0)) {
    *param_2 = 0;
    param_2[1] = 0;
    return 0;
  }
LAB_40b86474:
  if (((int)local_24 <= (int)uVar3) && ((uVar3 != local_24 || (local_28 < uVar2)))) {
    uVar2 = local_28;
    uVar3 = local_24;
  }
  *param_2 = uVar2;
  param_2[1] = uVar3;
  return 0;
}



/* 40b86550 FUN_40b86550 */

/* Boundary evidence: original MIPS .pdata 40b86550..40b866a3. Semantic name remains unreviewed. */

undefined4
FUN_40b86550(int *param_1,undefined ***param_2,uint param_3,undefined ***param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined ***pppuVar3;
  uint uVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  int iVar7;
  
  pppuVar3 = param_2;
  iVar1 = FUN_40b90274(param_1[0xb]);
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
        (**(code **)(*param_1 + 0x34))(param_1,param_2,&DAT_40ba6888);
        pppuVar3 = param_2;
      }
      if ((param_5 & 8) != 0) {
        (**(code **)(*param_1 + 0x34))(param_1,param_4,&DAT_40ba6888);
        pppuVar3 = param_4;
      }
      uVar2 = FUN_40b92a6c(param_1[0xb],pppuVar3,ppuVar5,ppuVar6,iVar1,iVar7);
      return uVar2;
    }
  }
  return 0x80004001;
}



/* 40b866a4 FUN_40b866a4 */

/* Boundary evidence: original MIPS .pdata 40b866a4..40b86733. Semantic name remains unreviewed. */

undefined4 FUN_40b866a4(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_40b90274(param_1[0xb]);
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



/* 40b86734 FUN_40b86734 */

/* Boundary evidence: original MIPS .pdata 40b86734..40b86847. Semantic name remains unreviewed. */

undefined4 * FUN_40b86734(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  FUN_40b98634(param_1,0,param_3);
  param_1[3] = &PTR_FUN_40ba1bf4;
  param_1[4] = &PTR_LAB_40ba1bbc;
  *param_1 = &PTR_FUN_40ba1c44;
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
  FUN_40b901d8(param_1[0xe]);
  iVar1 = param_1[0xc];
  if (iVar1 != 0 || param_1[0xd] != 0) {
    param_1[8] = iVar1;
    param_1[9] = param_1[0xd];
  }
  return param_1;
}



/* 40b86848 FUN_40b86848 */

/* Boundary evidence: original MIPS .pdata 40b86848..40b86877. Semantic name remains unreviewed. */

void FUN_40b86848(void)

{
  int *in_v0;
  
  FUN_40b8594c(*in_v0);
  return;
}



/* 40b86878 FUN_40b86878 */

/* Boundary evidence: original MIPS .pdata 40b86878..40b868ab. Semantic name remains unreviewed. */

void FUN_40b86878(void)

{
  int *in_v0;
  
  FUN_40b99a84((int *)(*in_v0 + 0x3c));
  return;
}



/* 40b868ac FUN_40b868ac */

bool FUN_40b868ac(uint *param_1)

{
  return param_1[1] <= *param_1;
}



/* 40b868cc FUN_40b868cc */

void FUN_40b868cc(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40ba1d08;
  return;
}



/* 40b868dc FUN_40b868dc */

undefined4 FUN_40b868dc(char *param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = 0xffffffff;
  if (param_1 < param_2) {
    do {
      uVar3 = (uint)*param_1;
      iVar4 = 8;
      do {
        uVar1 = uVar3 ^ uVar2;
        uVar2 = uVar2 << 1;
        if ((uVar1 & 0x80000000) != 0) {
          uVar2 = uVar2 ^ 0x4c11db7;
        }
        iVar4 = iVar4 + -1;
        uVar3 = (int)(uVar3 << 0x19) >> 0x18;
      } while (iVar4 != 0);
      param_1 = param_1 + 1;
    } while (param_1 < param_2);
    if (uVar2 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 40b8694c FUN_40b8694c */

void FUN_40b8694c(undefined4 *param_1)

{
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
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  return;
}



/* 40b869f4 FUN_40b869f4 */

void FUN_40b869f4(uint *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  pbVar2 = *(byte **)(param_2 + 0xa0);
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  pbVar5 = pbVar2;
  if (*(int *)(param_2 + 0xc) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
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
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
    bVar1 = *pbVar2;
    param_1[2] = (uint)bVar1 << 0x10;
    uVar4 = (uint)pbVar2[1] << 8 | (uint)bVar1 << 0x10;
    param_1[2] = uVar4;
    param_1[2] = pbVar2[2] | uVar4;
    *param_1 = (uint)pbVar2[3];
    pbVar5 = pbVar2 + 6;
    param_1[1] = (uint)pbVar2[4] * 0x100 + (uint)pbVar2[5];
    if (param_1[2] == 1) {
      param_1[0x20] = 1;
    }
    uVar4 = *param_1;
    if (((((uVar4 != 0xbc) && (uVar4 != 0xbe)) && (uVar4 != 0xbf)) &&
        ((uVar4 != 0xf0 && (uVar4 != 0xf1)))) &&
       ((uVar4 != 0xf2 && ((uVar4 != 0xf8 && (uVar4 != 0xff)))))) {
      bVar1 = *pbVar5;
      param_1[4] = bVar1 >> 4 & 3;
      param_1[8] = bVar1 & 1;
      param_1[5] = bVar1 >> 3 & 1;
      param_1[6] = bVar1 >> 2 & 1;
      param_1[7] = bVar1 >> 1 & 1;
      bVar1 = pbVar2[7];
      param_1[9] = (uint)(bVar1 >> 6);
      param_1[10] = bVar1 >> 5 & 1;
      param_1[0xb] = bVar1 >> 4 & 1;
      param_1[0xf] = bVar1 & 1;
      param_1[0xc] = bVar1 >> 3 & 1;
      param_1[0xd] = bVar1 >> 2 & 1;
      param_1[0xe] = bVar1 >> 1 & 1;
      pbVar5 = pbVar2 + 9;
      param_1[0x10] = (uint)pbVar2[8];
      pbVar6 = pbVar5;
      if ((param_1[9] & 2) != 0) {
        bVar1 = *pbVar5;
        param_1[0x12] = (bVar1 & 0xfffe) << 0x1d;
        param_1[0x11] = bVar1 >> 3 & 1;
        param_1[0x12] =
             ((uint)pbVar2[10] * 0x100 + (uint)pbVar2[0xb] & 0xfffe) << 0xe | param_1[0x12];
        pbVar6 = pbVar2 + 0xe;
        param_1[0x12] = (uint)pbVar2[0xc] * 0x100 + (uint)pbVar2[0xd] >> 1 | param_1[0x12];
      }
      if ((param_1[9] & 1) != 0) {
        bVar1 = *pbVar6;
        param_1[0x14] = (bVar1 & 0xfffe) << 0x1d;
        param_1[0x13] = bVar1 >> 3 & 1;
        pbVar7 = pbVar6 + 3;
        param_1[0x14] = ((uint)pbVar6[1] * 0x100 + (uint)pbVar6[2] & 0xfffe) << 0xe | param_1[0x14];
        pbVar3 = pbVar6 + 4;
        pbVar6 = pbVar6 + 5;
        param_1[0x14] = (uint)*pbVar7 * 0x100 + (uint)*pbVar3 >> 1 | param_1[0x14];
      }
      if (param_1[10] != 0) {
        pbVar6 = pbVar6 + 6;
      }
      if (param_1[0xb] != 0) {
        pbVar6 = pbVar6 + 3;
      }
      if (param_1[0xc] != 0) {
        pbVar6 = pbVar6 + 1;
      }
      if (param_1[0xd] != 0) {
        pbVar6 = pbVar6 + 1;
      }
      if (param_1[0xe] != 0) {
        pbVar6 = pbVar6 + 2;
      }
      if (param_1[0xf] == 1) {
        bVar1 = *pbVar6;
        pbVar3 = pbVar6 + 1;
        param_1[0x15] = (uint)(bVar1 >> 7);
        param_1[0x16] = bVar1 >> 6 & 1;
        param_1[0x17] = bVar1 >> 5 & 1;
        param_1[0x18] = bVar1 >> 4 & 1;
        param_1[0x19] = bVar1 & 1;
        if (bVar1 >> 7 != 0) {
          pbVar3 = pbVar6 + 0x11;
        }
        if ((bVar1 >> 6 & 1) != 0) {
          bVar1 = *pbVar3;
          param_1[0x1a] = (uint)bVar1;
          pbVar3 = pbVar3 + bVar1 + 1;
        }
        if (param_1[0x17] != 0) {
          pbVar3 = pbVar3 + 2;
        }
        if (param_1[0x18] != 0) {
          pbVar3 = pbVar3 + 2;
        }
        if (param_1[0x19] != 0) {
          param_1[0x1b] = (uint)*pbVar3;
        }
      }
      pbVar5 = pbVar5 + param_1[0x10];
    }
    param_1[0x1c] = 0;
  }
  if (param_1[2] == 1) {
    uVar4 = param_1[0x1c];
    if (uVar4 != 0) {
      if (*(uint *)(param_2 + 0x20) != (param_1[3] + 1 & 0xf)) {
        param_1[0x1d] = 1;
        if (*(uint *)(param_2 + 0x20) == param_1[3]) {
          return;
        }
        *param_1 = 0;
        param_1[1] = 0;
        param_1[3] = 0;
        param_1[4] = 0;
        param_1[5] = 0;
        param_1[6] = 0;
        param_1[7] = 0;
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
        param_1[0x13] = 0;
        param_1[0x14] = 0;
        param_1[0x15] = 0;
        param_1[0x16] = 0;
        param_1[0x17] = 0;
        param_1[0x18] = 0;
        param_1[0x19] = 0;
        param_1[0x1a] = 0;
        param_1[0x1b] = 0;
        return;
      }
      param_1[0x1d] = 0;
    }
    param_1[3] = *(uint *)(param_2 + 0x20);
    if (param_1[1] == 0) {
      pbVar6 = pbVar2 + (*(int *)(param_2 + 0x9c) - (int)pbVar5);
    }
    else {
      pbVar3 = (byte *)(param_1[1] - uVar4);
      pbVar6 = pbVar2 + (*(int *)(param_2 + 0x9c) - (int)pbVar5);
      if (pbVar3 <= pbVar2 + (*(int *)(param_2 + 0x9c) - (int)pbVar5)) {
        pbVar6 = pbVar3;
      }
    }
    param_1[0x1c] = (uint)(pbVar6 + uVar4);
    if (*param_1 != 0xbe) {
      param_1[0x1e] = (uint)pbVar5;
      param_1[0x1f] = (uint)pbVar6;
    }
  }
  return;
}



/* 40b86f5c FUN_40b86f5c */

/* Boundary evidence: original MIPS .pdata 40b86f5c..40b870ff. Semantic name remains unreviewed. */

undefined * FUN_40b86f5c(byte *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 == 4) {
    pcVar2 = &DAT_40ba9b24;
    do {
      iVar1 = tolower((uint)*param_1);
      if ((((iVar1 == pcVar2[-4]) && (iVar1 = tolower((uint)param_1[1]), iVar1 == pcVar2[-3])) &&
          (iVar1 = tolower((uint)param_1[2]), iVar1 == pcVar2[-2])) ||
         (((iVar1 = tolower((uint)*param_1), iVar1 == *pcVar2 &&
           (iVar1 = tolower((uint)param_1[1]), iVar1 == pcVar2[1])) &&
          (iVar1 = tolower((uint)param_1[2]), iVar1 == pcVar2[2])))) goto LAB_40b870d4;
      pcVar2 = pcVar2 + 0x2c;
      iVar3 = iVar3 + 1;
    } while ((int)pcVar2 < 0x40bab804);
  }
  else {
    pcVar2 = &DAT_40ba9b1c;
    do {
      iVar1 = tolower((uint)*param_1);
      if ((iVar1 == *pcVar2) && (iVar1 = tolower((uint)param_1[1]), iVar1 == pcVar2[1]))
      goto LAB_40b870d4;
      pcVar2 = pcVar2 + 0x2c;
      iVar3 = iVar3 + 1;
    } while ((int)pcVar2 < 0x40bab7fc);
  }
  wsprintfW((LPWSTR)&DAT_40ba98fc,L"%c%c",(uint)*param_1,(uint)param_1[1]);
LAB_40b8705c:
  return &DAT_40ba98fc;
LAB_40b870d4:
  mbstowcs((wchar_t *)&DAT_40ba98fc,(char *)(&DAT_40ba9afc + iVar3 * 0xb),0x20);
  goto LAB_40b8705c;
}



/* 40b87100 FUN_40b87100 */

/* Boundary evidence: original MIPS .pdata 40b87100..40b871bf. Semantic name remains unreviewed. */

undefined * FUN_40b87100(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 < 3) {
    if (param_1 == 2) {
      pwVar1 = L"hearing impaired";
      goto LAB_40b871a4;
    }
    if (param_1 == 0) {
      pwVar1 = L"";
      goto LAB_40b871a4;
    }
    if (param_1 == 1) {
      pwVar1 = L"clean effects";
      goto LAB_40b871a4;
    }
  }
  else {
    if (param_1 == 3) {
      pwVar1 = L"visual impaired commentary";
      goto LAB_40b871a4;
    }
    if (param_1 == 0x7f) {
      pwVar1 = L"user private";
      goto LAB_40b871a4;
    }
  }
  pwVar1 = L"";
LAB_40b871a4:
  wsprintfW((LPWSTR)&DAT_40ba99fc,pwVar1);
  return &DAT_40ba99fc;
}



/* 40b871c0 FUN_40b871c0 */

/* Boundary evidence: original MIPS .pdata 40b871c0..40b8735b. Semantic name remains unreviewed. */

void FUN_40b871c0(undefined4 param_1,byte *param_2,int param_3,LPWSTR param_4)

{
  byte bVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  LPWSTR pWVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  
  iVar7 = 0;
  pbVar6 = param_2;
  if (0 < param_3) {
    do {
      bVar1 = *pbVar6;
      uVar5 = (uint)pbVar6[1];
      if (bVar1 < 0x57) {
        if (bVar1 == 0x56) {
          pWVar3 = (WCHAR *)FUN_40b86f5c(pbVar6 + 2,3);
          pWVar4 = param_4 + 0x40;
          do {
            WVar2 = *pWVar3;
            pWVar3 = pWVar3 + 1;
            *pWVar4 = WVar2;
            pWVar4 = pWVar4 + 1;
          } while (WVar2 != L'\0');
        }
        else if (bVar1 == 10) {
          bVar1 = pbVar6[uVar5 + 1];
          pWVar3 = (WCHAR *)FUN_40b86f5c(pbVar6 + 2,uVar5);
          pWVar4 = param_4 + 0x40;
          do {
            WVar2 = *pWVar3;
            pWVar3 = pWVar3 + 1;
            *pWVar4 = WVar2;
            pWVar4 = pWVar4 + 1;
          } while (WVar2 != L'\0');
          pWVar3 = (WCHAR *)FUN_40b87100((uint)bVar1);
          pWVar4 = param_4 + 0x80;
          do {
            WVar2 = *pWVar3;
            pWVar3 = pWVar3 + 1;
            *pWVar4 = WVar2;
            pWVar4 = pWVar4 + 1;
          } while (WVar2 != L'\0');
        }
      }
      else if (bVar1 == 0x59) {
        pWVar3 = (WCHAR *)FUN_40b86f5c(pbVar6 + 2,3);
        pWVar4 = param_4 + 0x40;
        do {
          WVar2 = *pWVar3;
          pWVar3 = pWVar3 + 1;
          *pWVar4 = WVar2;
          pWVar4 = pWVar4 + 1;
        } while (WVar2 != L'\0');
      }
      else if (bVar1 == 0x6a) {
        wsprintfW(param_4,L"DVB AC-3");
      }
      iVar7 = uVar5 + iVar7 + 2;
      pbVar6 = param_2 + iVar7;
    } while (iVar7 < param_3);
  }
  return;
}



/* 40b8735c FUN_40b8735c */

/* Boundary evidence: original MIPS .pdata 40b8735c..40b874a3. Semantic name remains unreviewed. */

void FUN_40b8735c(undefined4 param_1,uint param_2,LPWSTR param_3)

{
  if (param_2 < 10) {
    if (param_2 == 9) {
      wsprintfW(param_3,L"H.222.1 Audio");
      return;
    }
    if (param_2 == 3) {
      wsprintfW(param_3,L"MPEG-1 Audio");
      return;
    }
    if (param_2 == 4) {
      wsprintfW(param_3,L"MPEG-2 Audio");
      return;
    }
    if (param_2 == 6) {
      wsprintfW(param_3,L"H.222.0 Audio");
      return;
    }
  }
  else {
    if (param_2 == 0xf) {
      wsprintfW(param_3,L"MPGE-2 AAC Audio");
      return;
    }
    if (param_2 == 0x11) {
      wsprintfW(param_3,L"MPEG-4 AAC Audio");
      return;
    }
    if (param_2 == 0x81) {
      wsprintfW(param_3,L"ATSC AC3 Audio");
      return;
    }
  }
  wsprintfW(param_3,L"UNKNOWN Audio");
  return;
}



/* 40b874a4 FUN_40b874a4 */

undefined4 FUN_40b874a4(int param_1)

{
  if (*(int *)(param_1 + 0x1830) != 0) {
    *(undefined4 *)(param_1 + 0x1830) = 0;
    return 1;
  }
  return 0;
}



/* 40b874c8 FUN_40b874c8 */

/* Boundary evidence: original MIPS .pdata 40b874c8..40b876a7. Semantic name remains unreviewed. */

void FUN_40b874c8(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  if (*(int *)(param_2 + 0x9c) != 0) {
    pbVar6 = *(byte **)(param_2 + 0xa0);
    if (*(int *)(param_2 + 0xc) != 0) {
      uVar4 = (uint)*pbVar6;
      param_1[2] = uVar4;
      pbVar5 = pbVar6 + 1;
      if ((uVar4 != 0) && (uVar4 != 0)) {
        pbVar5 = pbVar5 + uVar4;
      }
      param_1[3] = (uint)*pbVar5;
      uVar4 = (uint)pbVar5[1] * 0x100 + (uint)pbVar5[2];
      param_1[4] = uVar4 >> 0xf;
      param_1[5] = uVar4 & 0xfff;
      param_1[8] = (int)(pbVar5 + (3 - (int)pbVar6));
      bVar1 = pbVar5[5];
      param_1[0x609] = 0;
      param_1[6] = bVar1 >> 1 & 0x1f;
      param_1[7] = bVar1 & 1;
    }
    if ((param_1[0x609] != 0) &&
       (iVar2 = param_1[1], param_1[1] = iVar2 + 1U, (iVar2 + 1U & 0xf) != *(uint *)(param_2 + 0x20)
       )) {
      param_1[0x609] = 0;
      return;
    }
    param_1[1] = *(int *)(param_2 + 0x20);
    uVar4 = (param_1[5] - param_1[0x609]) + param_1[8];
    if (*(uint *)(param_2 + 0x9c) <= uVar4) {
      uVar4 = *(uint *)(param_2 + 0x9c);
    }
    memcpy((void *)((int)param_1 + param_1[0x609] + 0x24),*(void **)(param_2 + 0xa0),uVar4);
    iVar2 = param_1[0x609];
    param_1[0x609] = iVar2 + uVar4;
    if ((((uint)(param_1[5] + param_1[8]) <= iVar2 + uVar4) &&
        (iVar2 = FUN_40b868dc((char *)((int)param_1 + param_1[2] + 0x25),
                              (char *)((int)param_1 + param_1[5] + param_1[8] + 0x24U)), iVar2 != 0)
        ) && ((param_1[0x60a] == 0 ||
              (((param_1[7] == 1 && (param_1[6] != param_1[0x60b])) && (param_1[0x60d] != 0)))))) {
      pcVar3 = *(code **)(*param_1 + 4);
      param_1[0x60c] = 1;
      (*pcVar3)(param_1);
      (**(code **)*param_1)(param_1);
    }
  }
  return;
}



/* 40b876a8 FUN_40b876a8 */

/* Boundary evidence: original MIPS .pdata 40b876a8..40b8775f. Semantic name remains unreviewed. */

undefined4 * FUN_40b876a8(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = param_1[1];
  if (param_1[1] != 0) {
    *(undefined4 **)(param_1[1] + 4) = puVar1;
    param_1[1] = puVar1;
    param_1[2] = param_1[2] + 1;
    return puVar1;
  }
  *param_1 = puVar1;
  param_1[1] = puVar1;
  param_1[2] = param_1[2] + 1;
  return puVar1;
}



/* 40b87760 FUN_40b87760 */

/* Boundary evidence: original MIPS .pdata 40b87760..40b87817. Semantic name remains unreviewed. */

undefined4 * FUN_40b87760(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = param_1[1];
  if (param_1[1] != 0) {
    *(undefined4 **)(param_1[1] + 4) = puVar1;
    param_1[1] = puVar1;
    param_1[2] = param_1[2] + 1;
    return puVar1;
  }
  *param_1 = puVar1;
  param_1[1] = puVar1;
  param_1[2] = param_1[2] + 1;
  return puVar1;
}



/* 40b87818 FUN_40b87818 */

/* Boundary evidence: original MIPS .pdata 40b87818..40b8784b. Semantic name remains unreviewed. */

int FUN_40b87818(int param_1,int *param_2)

{
  FUN_40b874c8(param_2,param_1);
  return param_1;
}



/* 40b8784c FUN_40b8784c */

/* Boundary evidence: original MIPS .pdata 40b8784c..40b8787f. Semantic name remains unreviewed. */

int FUN_40b8784c(int param_1,int *param_2)

{
  FUN_40b874c8(param_2,param_1);
  return param_1;
}



/* 40b87880 FUN_40b87880 */

/* Boundary evidence: original MIPS .pdata 40b87880..40b878af. Semantic name remains unreviewed. */

uint * FUN_40b87880(int param_1,uint *param_2)

{
  FUN_40b869f4(param_2,param_1);
  return param_2;
}



/* 40b878b0 FUN_40b878b0 */

/* Boundary evidence: original MIPS .pdata 40b878b0..40b87f9b. Semantic name remains unreviewed. */

void FUN_40b878b0(undefined4 *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  undefined3 extraout_var;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  
  uVar12 = 0;
  do {
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
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    param_1[0x20] = 0;
    param_1[0x21] = 0;
    param_1[0x22] = 0;
    param_1[0x23] = 0;
    param_1[0x24] = 0;
    param_1[0x25] = 0;
    param_1[0x26] = 0;
    param_1[0x27] = 0;
    param_1[0x28] = 0;
    while (uVar12 != 0x47) {
      bVar5 = FUN_40b868ac(param_2);
      if ((CONCAT31(extraout_var,bVar5) != 0) ||
         (pbVar10 = (byte *)*param_2, param_2[1] - (int)pbVar10 < 0xbc)) {
        if (uVar12 != 0x47) {
          param_1[5] = 0x1fff;
          return;
        }
        break;
      }
      bVar1 = *pbVar10;
      *param_2 = (uint)(pbVar10 + 1);
      uVar12 = (uint)bVar1;
    }
    param_1[0x29] = (*param_2 - param_2[2]) + -1;
    param_1[1] = uVar12 & 0xff;
    bVar1 = *(byte *)*param_2;
    *param_2 = (uint)((byte *)*param_2 + 1);
    param_1[2] = (uint)(bVar1 >> 7);
    param_1[3] = bVar1 >> 6 & 1;
    param_1[4] = bVar1 >> 5 & 1;
    bVar2 = *(byte *)*param_2;
    *param_2 = (uint)((byte *)*param_2 + 1);
    param_1[5] = (uint)bVar1 * 0x100 + (uint)bVar2 & 0x1fff;
    bVar1 = *(byte *)*param_2;
    uVar12 = (uint)bVar1;
    *param_2 = (uint)((byte *)*param_2 + 1);
    uVar11 = bVar1 >> 4 & 3;
    param_1[6] = (uint)(bVar1 >> 6);
    param_1[7] = uVar11;
    param_1[8] = uVar12 & 0xf;
    if ((((param_1[2] != 1) && ((param_1[3] == 0 || (param_1[5] != 0x1fff)))) &&
        ((uVar11 == 1 || (param_1[5] != 0x1fff)))) && ((bVar1 >> 4 & 3) != 0)) {
      iVar8 = 0xb8;
      if ((uVar11 == 2) || (uVar11 == 3)) {
        uVar11 = (uint)*(byte *)*param_2;
        *param_2 = (uint)((byte *)*param_2 + 1);
        param_1[9] = uVar11;
        pbVar10 = (byte *)*param_2;
        uVar6 = param_2[2];
        uVar12 = 0;
        if (uVar11 != 0) {
          bVar1 = *pbVar10;
          uVar12 = (uint)bVar1;
          *param_2 = (uint)(pbVar10 + 1);
          param_1[10] = (uint)(bVar1 >> 7);
          param_1[0xb] = bVar1 >> 6 & 1;
          param_1[0xc] = bVar1 >> 5 & 1;
          param_1[0xd] = bVar1 >> 4 & 1;
          param_1[0xe] = bVar1 >> 3 & 1;
          param_1[0xf] = bVar1 >> 2 & 1;
          param_1[0x10] = bVar1 >> 1 & 1;
          param_1[0x11] = uVar12 & 1;
          if ((bVar1 >> 4 & 1) != 0) {
            pbVar13 = (byte *)*param_2;
            bVar1 = *pbVar13;
            bVar2 = pbVar13[1];
            bVar3 = pbVar13[2];
            bVar4 = pbVar13[3];
            *param_2 = (uint)(pbVar13 + 4);
            param_1[0x13] = CONCAT31(CONCAT21(CONCAT11(bVar1,bVar2),bVar3),bVar4) << 1;
            param_1[0x12] = (uint)(bVar1 >> 7);
            bVar1 = *(byte *)*param_2;
            *param_2 = (uint)((byte *)*param_2 + 1);
            param_1[0x14] = (bVar1 & 1) << 8;
            param_1[0x13] = (uint)(bVar1 >> 7) | param_1[0x13];
            uVar12 = (uint)*(byte *)*param_2;
            *param_2 = (uint)((byte *)*param_2 + 1);
            param_1[0x14] = uVar12 | param_1[0x14];
          }
          if (param_1[0xe] != 0) {
            pbVar13 = (byte *)*param_2;
            bVar1 = *pbVar13;
            bVar2 = pbVar13[1];
            bVar3 = pbVar13[2];
            bVar4 = pbVar13[3];
            *param_2 = (uint)(pbVar13 + 4);
            param_1[0x17] = CONCAT31(CONCAT21(CONCAT11(bVar1,bVar2),bVar3),bVar4) << 1;
            param_1[0x16] = (uint)(bVar1 >> 7);
            bVar1 = *(byte *)*param_2;
            *param_2 = (uint)((byte *)*param_2 + 1);
            param_1[0x18] = (bVar1 & 1) << 8;
            param_1[0x17] = (uint)(bVar1 >> 7) | param_1[0x17];
            uVar12 = (uint)*(byte *)*param_2;
            *param_2 = (uint)((byte *)*param_2 + 1);
            param_1[0x18] = uVar12 | param_1[0x18];
          }
          if (param_1[0xf] != 0) {
            uVar12 = (uint)*(byte *)*param_2;
            *param_2 = (uint)((byte *)*param_2 + 1);
            param_1[0x19] = uVar12;
          }
          if (param_1[0x10] != 0) {
            uVar12 = (uint)*(byte *)*param_2;
            *param_2 = (uint)((byte *)*param_2 + 1);
            param_1[0x1a] = uVar12;
            *param_2 = uVar12 + *param_2;
          }
          if (param_1[0x11] != 0) {
            bVar1 = *(byte *)*param_2;
            *param_2 = (uint)((byte *)*param_2 + 1);
            param_1[0x1b] = (uint)bVar1;
            pbVar13 = (byte *)*param_2;
            bVar1 = *pbVar13;
            uVar12 = (uint)bVar1;
            uVar11 = param_2[2];
            *param_2 = (uint)(pbVar13 + 1);
            param_1[0x1c] = (uint)(bVar1 >> 7);
            param_1[0x1d] = bVar1 >> 6 & 1;
            param_1[0x1e] = bVar1 >> 5 & 1;
            if (bVar1 >> 7 != 0) {
              pbVar7 = (byte *)*param_2;
              bVar1 = *pbVar7;
              *param_2 = (uint)(pbVar7 + 1);
              uVar12 = (uint)bVar1 * 0x100 + (uint)pbVar7[1];
              *param_2 = (uint)(pbVar7 + 2);
              param_1[0x1f] = uVar12 >> 0xf;
              param_1[0x20] = uVar12 & 0x7fff;
            }
            if (param_1[0x1d] != 0) {
              pbVar7 = (byte *)*param_2;
              bVar1 = *pbVar7;
              *param_2 = (uint)(pbVar7 + 1);
              bVar2 = pbVar7[1];
              *param_2 = (uint)(pbVar7 + 2);
              uVar12 = ((uint)bVar1 * 0x100 + (uint)bVar2) * 0x100 + (uint)pbVar7[2];
              *param_2 = (uint)(pbVar7 + 3);
              param_1[0x21] = uVar12 & 0x3fffff;
            }
            if (param_1[0x1e] != 0) {
              bVar1 = *(byte *)*param_2;
              *param_2 = (uint)((byte *)*param_2 + 1);
              param_1[0x22] = (uint)(bVar1 >> 4);
              param_1[0x23] = bVar1 >> 3 & 1;
              param_1[0x24] = (bVar1 & 6) << 0x1c;
              pbVar7 = (byte *)*param_2;
              bVar1 = *pbVar7;
              *param_2 = (uint)(pbVar7 + 1);
              bVar2 = pbVar7[1];
              *param_2 = (uint)(pbVar7 + 2);
              param_1[0x24] = ((uint)bVar1 * 0x100 + (uint)bVar2 & 0xfffe) << 0xd | param_1[0x24];
              pbVar7 = (byte *)*param_2;
              bVar1 = *pbVar7;
              *param_2 = (uint)(pbVar7 + 1);
              uVar12 = (uint)bVar1 * 0x100 + (uint)pbVar7[1];
              *param_2 = (uint)(pbVar7 + 2);
              param_1[0x24] = uVar12 >> 1 | param_1[0x24];
            }
            iVar8 = (((int)pbVar13 - uVar11) * 2 - *param_2) + param_2[2];
            param_1[0x25] = iVar8;
            *param_2 = *param_2 + iVar8;
          }
          uVar11 = *param_2;
          uVar9 = param_2[2];
          param_1[0x26] = pbVar10 + uVar9 + ((param_1[9] - uVar11) - uVar6);
          *param_2 = (uint)(pbVar10 + uVar9 + ((param_1[9] - uVar11) - uVar6) + *param_2);
        }
        iVar8 = 0xb7 - param_1[9];
      }
      if ((param_1[7] == 1) || (param_1[7] == 3)) {
        param_1[0x27] = iVar8;
        param_1[0x28] = *param_2;
        *param_2 = *param_2 + iVar8;
      }
      if (param_1[5] != 0x1fff) {
        *param_1 = 1;
        return;
      }
    }
  } while( true );
}



/* 40b87f9c FUN_40b87f9c */

/* Boundary evidence: original MIPS .pdata 40b87f9c..40b8813b. Semantic name remains unreviewed. */

void FUN_40b87f9c(int param_1)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  
  uVar3 = (uint)*(byte *)(param_1 + 0x24);
  pbVar6 = (byte *)(param_1 + 0x25);
  *(uint *)(param_1 + 0x1858) = uVar3;
  if (uVar3 != 0) {
    pbVar6 = pbVar6 + uVar3;
  }
  *(uint *)(param_1 + 0x1838) = (uint)*pbVar6;
  uVar3 = (uint)pbVar6[1] * 0x100 + (uint)pbVar6[2];
  *(uint *)(param_1 + 0x183c) = uVar3 >> 0xf;
  *(uint *)(param_1 + 0x1840) = uVar3 & 0xfff;
  *(uint *)(param_1 + 0x1844) = (uint)pbVar6[3] * 0x100 + (uint)pbVar6[4];
  bVar1 = pbVar6[5];
  *(uint *)(param_1 + 0x182c) = bVar1 >> 1 & 0x1f;
  *(uint *)(param_1 + 0x1848) = bVar1 & 1;
  *(uint *)(param_1 + 0x184c) = (uint)pbVar6[6];
  uVar7 = *(int *)(param_1 + 0x1840) - 9U >> 2;
  *(uint *)(param_1 + 0x1850) = (uint)pbVar6[7];
  *(uint *)(param_1 + 0x1854) = uVar7;
  pbVar6 = pbVar6 + 8;
  uVar3 = 0;
  if (uVar7 != 0) {
    do {
      puVar2 = operator_new(8);
      uVar3 = uVar3 + 1;
      pbVar4 = pbVar6 + 2;
      *puVar2 = uVar3;
      pbVar5 = pbVar6 + 3;
      pbVar6 = pbVar6 + 4;
      puVar2[1] = (uint)*pbVar4 * 0x100 + (uint)*pbVar5 & 0x1fff;
      FUN_40b876a8((undefined4 *)(param_1 + 0x185c),puVar2);
    } while (uVar3 < uVar7);
  }
  *(uint *)(param_1 + 0x1834) = CONCAT31(CONCAT21(CONCAT11(*pbVar6,pbVar6[1]),pbVar6[2]),pbVar6[3]);
  *(undefined4 *)(param_1 + 0x1828) = 1;
  return;
}



/* 40b8813c FUN_40b8813c */

undefined4 FUN_40b8813c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x1854) != 0) && (*(int *)(param_1 + 0x1828) != 0)) {
    iVar2 = 0;
    for (iVar1 = *(int *)(param_1 + 0x185c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      if (iVar2 == param_2) {
        return *(undefined4 *)(*(int *)(iVar1 + 8) + 4);
      }
      iVar2 = iVar2 + 1;
    }
  }
  return 0x1fff;
}



/* 40b88188 FUN_40b88188 */

undefined4 FUN_40b88188(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x1854) != 0) && (*(int *)(param_1 + 0x1828) != 0)) {
    iVar2 = 0;
    for (iVar1 = *(int *)(param_1 + 0x185c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      if (iVar2 == param_2) {
        return **(undefined4 **)(iVar1 + 8);
      }
      iVar2 = iVar2 + 1;
    }
  }
  return 0x1fff;
}



/* 40b881d4 FUN_40b881d4 */

/* Boundary evidence: original MIPS .pdata 40b881d4..40b8844f. Semantic name remains unreviewed. */

void FUN_40b881d4(int param_1)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  WCHAR aWStack_1a8 [192];
  uint local_28;
  
  local_28 = DAT_40ba9854;
  uVar3 = (uint)*(byte *)(param_1 + 0x24);
  pbVar4 = (byte *)(param_1 + 0x25);
  *(uint *)(param_1 + 0x1864) = uVar3;
  if ((uVar3 != 0) && (uVar3 != 0)) {
    pbVar4 = pbVar4 + uVar3;
  }
  *(uint *)(param_1 + 0x1838) = (uint)*pbVar4;
  uVar3 = (uint)pbVar4[1] * 0x100 + (uint)pbVar4[2];
  *(uint *)(param_1 + 0x183c) = uVar3 >> 0xf;
  *(uint *)(param_1 + 0x1840) = uVar3 & 0xfff;
  *(uint *)(param_1 + 0x1844) = (uint)pbVar4[3] * 0x100 + (uint)pbVar4[4];
  bVar1 = pbVar4[5];
  *(uint *)(param_1 + 0x1848) = bVar1 & 1;
  *(uint *)(param_1 + 0x182c) = bVar1 >> 1 & 0x1f;
  *(uint *)(param_1 + 0x184c) = (uint)pbVar4[6];
  *(uint *)(param_1 + 0x1850) = (uint)pbVar4[7];
  *(uint *)(param_1 + 0x1854) = (uint)pbVar4[8] * 0x100 + (uint)pbVar4[9] & 0x1fff;
  uVar3 = (uint)pbVar4[10] * 0x100 + (uint)pbVar4[0xb] & 0xfff;
  *(uint *)(param_1 + 0x1858) = uVar3;
  pbVar4 = pbVar4 + 0xc;
  if (uVar3 != 0) {
    *(byte **)(param_1 + 0x185c) = pbVar4;
    pbVar4 = pbVar4 + uVar3;
  }
  iVar7 = 0;
  pbVar6 = pbVar4;
  if (*(int *)(param_1 + 0x1840) - uVar3 != 0xd) {
    do {
      puVar2 = operator_new(0x10);
      *puVar2 = (uint)*pbVar6;
      puVar2[1] = (uint)pbVar6[1] * 0x100 + (uint)pbVar6[2] & 0x1fff;
      pbVar5 = pbVar6 + 5;
      uVar3 = (uint)pbVar6[3] * 0x100 + (uint)pbVar6[4] & 0xfff;
      puVar2[2] = uVar3;
      puVar2[3] = (uint)pbVar5;
      FUN_40b871c0(param_1,pbVar5,uVar3,aWStack_1a8);
      pbVar6 = pbVar5 + puVar2[2];
      FUN_40b87760((undefined4 *)(param_1 + 0x1868),puVar2);
      iVar7 = iVar7 + 1;
    } while ((uint)((int)pbVar6 - (int)pbVar4) <
             (*(int *)(param_1 + 0x1840) - *(int *)(param_1 + 0x1858)) - 0xdU);
  }
  *(int *)(param_1 + 0x1860) = iVar7;
  *(uint *)(param_1 + 0x1834) = CONCAT31(CONCAT21(CONCAT11(*pbVar6,pbVar6[1]),pbVar6[2]),pbVar6[3]);
  *(undefined4 *)(param_1 + 0x1828) = 1;
  FUN_40b9bea4(local_28);
  return;
}



/* 40b88450 FUN_40b88450 */

int FUN_40b88450(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x1860) != 0) && (*(int *)(param_1 + 0x1828) != 0)) {
    for (iVar2 = *(int *)(param_1 + 0x1868); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      iVar1 = **(int **)(iVar2 + 8);
      if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 0x10)) ||
         ((iVar1 == 0x1b || (iVar1 == 0x80)))) {
        return (*(int **)(iVar2 + 8))[1];
      }
    }
  }
  return 0x1fff;
}



/* 40b884d8 FUN_40b884d8 */

int * FUN_40b884d8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((*(int *)(param_1 + 0x1860) != 0) && (*(int *)(param_1 + 0x1828) != 0)) {
    for (iVar2 = *(int *)(param_1 + 0x1868); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      iVar1 = **(int **)(iVar2 + 8);
      if ((((iVar1 == 3) || (iVar1 == 4)) || (iVar1 == 6)) ||
         (((iVar1 == 9 || (iVar1 == 0xf)) || ((iVar1 == 0x11 || (iVar1 == 0x81)))))) {
        if (iVar3 == param_2) {
          return *(int **)(iVar2 + 8);
        }
        iVar3 = iVar3 + 1;
      }
    }
  }
  return (int *)0x0;
}



/* 40b8857c FUN_40b8857c */

int FUN_40b8857c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  if (((*(int *)(param_1 + 0x1860) != 0) && (*(int *)(param_1 + 0x1828) != 0)) &&
     (iVar3 = *(int *)(param_1 + 0x1868), iVar3 != 0)) {
    do {
      iVar2 = **(int **)(iVar3 + 8);
      if (((((iVar2 == 3) || (iVar2 == 4)) || ((iVar2 == 6 || ((iVar2 == 9 || (iVar2 == 0xf)))))) ||
          (iVar2 == 0x11)) || (iVar2 == 0x81)) {
        iVar1 = iVar1 + 1;
      }
      iVar3 = *(int *)(iVar3 + 4);
    } while (iVar3 != 0);
    return iVar1;
  }
  return 0;
}



/* 40b88620 FUN_40b88620 */

int FUN_40b88620(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  if ((*(int *)(param_1 + 0x1860) == 0) || (*(int *)(param_1 + 0x1828) == 0)) {
    iVar1 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x1868);
    if (iVar3 != 0) {
      while (param_2 != (*(int **)(iVar3 + 8))[1]) {
        iVar2 = **(int **)(iVar3 + 8);
        if ((((iVar2 == 3) || (iVar2 == 4)) || (iVar2 == 6)) ||
           (((iVar2 == 9 || (iVar2 == 0xf)) || ((iVar2 == 0x11 || (iVar2 == 0x81)))))) {
          iVar1 = iVar1 + 1;
        }
        iVar3 = *(int *)(iVar3 + 4);
        if (iVar3 == 0) {
          return iVar1;
        }
      }
    }
  }
  return iVar1;
}



/* 40b886d0 FUN_40b886d0 */

int FUN_40b886d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if ((*(int *)(param_1 + 0x1860) != 0) && (*(int *)(param_1 + 0x1828) != 0)) {
    for (iVar3 = *(int *)(param_1 + 0x1868); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      piVar2 = *(int **)(iVar3 + 8);
      if ((param_2 == iVar4) &&
         ((((iVar1 = *piVar2, iVar1 == 3 || (iVar1 == 4)) || (iVar1 == 6)) ||
          (((iVar1 == 9 || (iVar1 == 0xf)) || ((iVar1 == 0x11 || (iVar1 == 0x81)))))))) {
        return piVar2[1];
      }
      iVar1 = *piVar2;
      if ((((iVar1 == 3) || (iVar1 == 4)) ||
          ((iVar1 == 6 || (((iVar1 == 9 || (iVar1 == 0xf)) || (iVar1 == 0x11)))))) ||
         (iVar1 == 0x81)) {
        iVar4 = iVar4 + 1;
      }
    }
  }
  return 0x1fff;
}



/* 40b887b4 FUN_40b887b4 */

undefined4 FUN_40b887b4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x1860) != 0) && (*(int *)(param_1 + 0x1828) != 0)) {
    iVar1 = 0;
    for (iVar2 = *(int *)(param_1 + 0x1868); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      if (iVar1 == param_2) {
        return **(undefined4 **)(iVar2 + 8);
      }
      iVar1 = iVar1 + 1;
    }
  }
  return 0x1fff;
}



/* 40b88804 FUN_40b88804 */

undefined4 FUN_40b88804(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x1860) != 0) && (*(int *)(param_1 + 0x1828) != 0)) {
    iVar1 = 0;
    for (iVar2 = *(int *)(param_1 + 0x1868); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      if (iVar1 == param_2) {
        return *(undefined4 *)(*(int *)(iVar2 + 8) + 4);
      }
      iVar1 = iVar1 + 1;
    }
  }
  return 0x1fff;
}



/* 40b88854 FUN_40b88854 */

undefined4 FUN_40b88854(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1870);
}



/* 40b8885c FUN_40b8885c */

void FUN_40b8885c(int *param_1)

{
  int *piVar1;
  
  for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    if (*piVar1 == 0) {
      *param_1 = piVar1[1];
    }
    else {
      *(int *)(*piVar1 + 4) = piVar1[1];
    }
    if ((int *)piVar1[1] == (int *)0x0) {
      param_1[1] = *piVar1;
    }
    else {
      *(int *)piVar1[1] = *piVar1;
    }
    param_1[2] = param_1[2] + -1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



/* 40b888cc FUN_40b888cc */

/* Boundary evidence: original MIPS .pdata 40b888cc..40b888fb. Semantic name remains unreviewed. */

undefined4 * FUN_40b888cc(uint *param_1,undefined4 *param_2)

{
  FUN_40b878b0(param_2,param_1);
  return param_2;
}



/* 40b888fc FUN_40b888fc */

/* Boundary evidence: original MIPS .pdata 40b888fc..40b8894b. Semantic name remains unreviewed. */

void FUN_40b888fc(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x185c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    operator_delete(*(void **)(iVar1 + 8));
  }
  FUN_40b8885c((int *)(param_1 + 0x185c));
  return;
}



/* 40b8894c FUN_40b8894c */

/* Boundary evidence: original MIPS .pdata 40b8894c..40b8899b. Semantic name remains unreviewed. */

void FUN_40b8894c(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x1868); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    operator_delete(*(void **)(iVar1 + 8));
  }
  FUN_40b8885c((int *)(param_1 + 0x1868));
  return;
}



/* 40b8899c FUN_40b8899c */

/* Boundary evidence: original MIPS .pdata 40b8899c..40b889b7. Semantic name remains unreviewed. */

void FUN_40b8899c(int *param_1)

{
  FUN_40b8885c(param_1);
  return;
}



/* 40b889b8 FUN_40b889b8 */

/* Boundary evidence: original MIPS .pdata 40b889b8..40b889d3. Semantic name remains unreviewed. */

void FUN_40b889b8(int *param_1)

{
  FUN_40b8885c(param_1);
  return;
}



/* 40b889d4 FUN_40b889d4 */

undefined4 * FUN_40b889d4(undefined4 *param_1)

{
  param_1[0x60c] = 0;
  *param_1 = &PTR_FUN_40ba1ecc;
  param_1[0x617] = 0;
  param_1[0x618] = 0;
  param_1[0x619] = 0;
  param_1[0x60a] = 0;
  param_1[0x60e] = 0;
  param_1[0x60f] = 0;
  param_1[0x610] = 0;
  param_1[0x611] = 0;
  param_1[0x60b] = 0;
  param_1[0x612] = 0;
  param_1[0x613] = 0;
  param_1[0x614] = 0;
  param_1[0x615] = 0;
  param_1[0x60d] = 0;
  return param_1;
}



/* 40b88a24 FUN_40b88a24 */

undefined4 * FUN_40b88a24(undefined4 *param_1)

{
  param_1[0x60c] = 0;
  *param_1 = &PTR_FUN_40ba1ed4;
  param_1[0x61a] = 0;
  param_1[0x61b] = 0;
  param_1[0x61c] = 0;
  param_1[0x60a] = 0;
  param_1[0x60e] = 0;
  param_1[0x60f] = 0;
  param_1[0x610] = 0;
  param_1[0x611] = 0;
  param_1[0x60b] = 0;
  param_1[0x612] = 0;
  param_1[0x613] = 0;
  param_1[0x614] = 0;
  param_1[0x615] = 0;
  param_1[0x616] = 0;
  param_1[0x618] = 0;
  param_1[0x60d] = 0;
  param_1[0x617] = 0;
  return param_1;
}



/* 40b88a80 FUN_40b88a80 */

void FUN_40b88a80(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40ba2b00;
  return;
}



/* 40b88a90 FUN_40b88a90 */

/* Boundary evidence: original MIPS .pdata 40b88a90..40b88ad3. Semantic name remains unreviewed. */

undefined4 * FUN_40b88a90(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40ba2b00;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b88ad4 FUN_40b88ad4 */

/* Boundary evidence: original MIPS .pdata 40b88ad4..40b88b17. Semantic name remains unreviewed. */

undefined4 * FUN_40b88ad4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40ba2b80;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b88b28 FUN_40b88b28 */

/* Boundary evidence: original MIPS .pdata 40b88b28..40b88b7b. Semantic name remains unreviewed. */

void FUN_40b88b28(int *param_1)

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



/* 40b88b7c FUN_40b88b7c */

/* Boundary evidence: original MIPS .pdata 40b88b7c..40b88d5b. Semantic name remains unreviewed. */

undefined4 FUN_40b88b7c(int *param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  
  uVar1 = 0x80004005;
  if (((param_2 < (uint)param_1[0x7a49]) && (param_1[0x660] == 0)) && (param_1[0x7a48] != param_2))
  {
    if (((param_1[param_2 * 0x7ba + 0xc6e] == 0) ||
        (param_1[param_1[param_2 * 0x7ba + 0xc91] + param_2 * 0x7ba + 0xc82] == 0x1fff)) ||
       (param_1[param_2 * 0x7ba + 0xdb0] == 0x1fff)) {
      uVar1 = 0x80040216;
    }
    else {
      param_1[0x660] = 1;
      param_1[0x65c] = param_1[param_2 * 0x7ba + 0x662];
      param_1[0x65b] = (int)(param_1 + param_2 * 0x7ba + 0x664);
      iVar2 = (**(code **)(*param_1 + 100))(param_1,param_1[param_2 * 0x7ba + 0xc91]);
      if (iVar2 != 0) {
        FUN_40b83ba4(0x40ba2b84,iVar2,param_1[param_2 * 0x7ba + 0xc91],param_4);
        (**(code **)(*param_1 + 100))(param_1,0);
      }
      param_1[0x65e] = param_1[param_1[param_2 * 0x7ba + 0xc91] + param_2 * 0x7ba + 0xc82];
      param_1[0x65d] = param_1[param_2 * 0x7ba + 0xdb0];
      lVar3 = __ll_div(param_1[param_2 * 0x7ba + 0xe18],param_1[param_2 * 0x7ba + 0xe19],0x5a,0);
      *(longlong *)(param_1 + 0x36) = lVar3 * 10000;
      param_1[0x65f] = *(int *)(param_1[0x65b] + 0x1854);
      param_1[0x7a48] = param_2;
      param_1[0x660] = 0;
      ReleaseMutex((HANDLE)param_1[0x7a4c]);
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40b88d8c FUN_40b88d8c */

/* Boundary evidence: original MIPS .pdata 40b88d8c..40b88e0b. Semantic name remains unreviewed. */

undefined4 FUN_40b88d8c(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_40ba6888,0x10);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0xd4);
    if (-1 < iVar1) {
      *param_2 = *(undefined4 *)(param_1 + 0xd0);
      param_2[1] = iVar1;
      return 0;
    }
  }
  return 0x80040261;
}



/* 40b88e0c FUN_40b88e0c */

/* Boundary evidence: original MIPS .pdata 40b88e0c..40b89117. Semantic name remains unreviewed. */

undefined4
FUN_40b88e0c(int *param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,int param_6,
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
  
  uVar9 = param_1[0x32];
  uVar10 = param_1[0x33];
  if (param_1[1] == 0) {
    if ((param_3 == param_5) && (param_4 == param_6)) {
      param_8[1] = uVar10;
      *param_8 = uVar9;
      *param_7 = uVar9;
      param_7[1] = param_8[1];
      return 0;
    }
    if (-1 < param_1[0x35]) {
      if ((param_4 < 0) || ((param_4 == 0 && (param_3 < 20000000)))) {
        uVar2 = 0;
        uVar5 = 0;
      }
      else {
        uVar11 = param_3 + 0xfeced300;
        uVar12 = param_4 - (uint)(param_3 < 20000000);
        local_38 = 0;
        local_34 = 0;
        uVar2 = FUN_40b98c68(uVar9,uVar10,uVar11,uVar12,param_1[0x34],param_1[0x35],0,0);
        uVar2 = uVar2 & 0xfffffffc;
        iVar3 = (**(code **)(*param_1 + 0x3c))
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
          uVar2 = FUN_40b98c68(param_1[0x32],param_1[0x33],uVar7,uVar4,param_1[0x34],param_1[0x35],0
                               ,0);
          uVar2 = uVar2 & 0xfffffffc;
          iVar3 = (**(code **)(*param_1 + 0x3c))
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



/* 40b89174 FUN_40b89174 */

/* Boundary evidence: original MIPS .pdata 40b89174..40b891a7. Semantic name remains unreviewed. */

undefined4 FUN_40b89174(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = __dptoli(param_3,param_4);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  return 0;
}



/* 40b891bc FUN_40b891bc */

/* Boundary evidence: original MIPS .pdata 40b891bc..40b8923b. Semantic name remains unreviewed. */

void FUN_40b891bc(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x1e934);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
    *(int *)(param_1 + 0x1e934) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x1e938);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
    *(int *)(param_1 + 0x1e938) = 0;
  }
  return;
}



/* 40b892b8 FUN_40b892b8 */

/* Boundary evidence: original MIPS .pdata 40b892b8..40b8937f. Semantic name remains unreviewed. */

undefined4 FUN_40b892b8(undefined1 *param_1,uint param_2,int *param_3)

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
LAB_40b8931c:
      iVar5 = iVar5 + 1;
      param_2 = param_2 - 1;
      param_1 = param_1 + 1;
      if (iVar4 == 0x1b7) {
        return 0;
      }
    }
    if (iVar4 != 0x100) goto LAB_40b8931c;
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



/* 40b89380 FUN_40b89380 */

undefined4 FUN_40b89380(undefined1 *param_1,uint param_2,int *param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  
  if (param_4 == 0) {
    do {
      while( true ) {
        if (param_2 < 5) {
          return 0;
        }
        iVar2 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
        if (iVar2 != 0x100) break;
        pbVar1 = param_1 + 5;
        param_2 = param_2 - 4;
        param_1 = param_1 + 4;
        if ((*pbVar1 & 0x38) != 8) {
          return 1;
        }
      }
      *param_3 = *param_3 + 1;
      param_2 = param_2 - 1;
      param_1 = param_1 + 1;
    } while (iVar2 != 0x1b7);
  }
  return 0;
}



/* 40b89420 FUN_40b89420 */

/* Boundary evidence: original MIPS .pdata 40b89420..40b89483. Semantic name remains unreviewed. */

undefined4 FUN_40b89420(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x48))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x44))(param_1);
  *param_2 = iVar1 + iVar2;
  return 0;
}



/* 40b89484 FUN_40b89484 */

/* Boundary evidence: original MIPS .pdata 40b89484..40b8952b. Semantic name remains unreviewed. */

undefined4 FUN_40b89484(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x48))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x44))(param_1);
  if (iVar1 + iVar2 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x48))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x44))(param_1);
    if (param_2 < iVar1 + iVar2) {
      return 0;
    }
  }
  return 0x80004005;
}



/* 40b8952c FUN_40b8952c */

/* Boundary evidence: original MIPS .pdata 40b8952c..40b89b33. Semantic name remains unreviewed. */

undefined4 FUN_40b8952c(int param_1,int param_2,undefined4 param_3,va_list param_4)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 *_Dst;
  undefined4 uVar7;
  int iVar8;
  void *_Buf1;
  undefined *puVar9;
  
  iVar4 = memcmp(*(void **)(param_1 + 0x28),&DAT_40ba56d8,0x10);
  if (iVar4 == 0) {
    _Buf1 = *(void **)(param_1 + 0x2c);
    iVar4 = memcmp(_Buf1,&DAT_40ba6618,0x10);
    if (iVar4 == 0) {
      *(undefined4 *)(param_2 + 0x10) = 0xe06d802b;
      *(undefined4 *)(param_2 + 0x14) = 0x11cfdb46;
      *(undefined4 *)(param_2 + 0x18) = 0x8000d1b4;
      *(undefined4 *)(param_2 + 0x1c) = 0xeabb6c5f;
      FUN_40b99438(param_2,&DAT_40ba6298);
      FUN_40b99844(param_2,*(int *)(param_1 + 0x50));
      puVar5 = FUN_40b9945c(param_2,0x12);
      memset(puVar5,0,0x12);
      iVar4 = *(int *)(param_1 + 0x6c);
      cVar1 = *(char *)(iVar4 + 3);
      cVar2 = *(char *)(iVar4 + 2);
      puVar5[0x10] = 0;
      if (cVar2 != '\0' || cVar1 != '\0') {
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
        return 0;
      }
      *puVar5 = 0x50;
      puVar5[0x11] = 0;
      puVar5[1] = 0;
      puVar5[3] = 0;
      puVar5[2] = 2;
      *(undefined4 *)(puVar5 + 8) = 48000;
      *(undefined4 *)(puVar5 + 4) = 0xac44;
      puVar5[0xc] = 1;
      puVar5[0xd] = 0;
      return 0;
    }
    iVar4 = memcmp(_Buf1,&DAT_40ba6628,0x10);
    if (iVar4 == 0) {
      FUN_40b99414(param_2,(undefined4 *)&DAT_40ba6628);
      FUN_40b99438(param_2,&DAT_40ba6298);
      FUN_40b99844(param_2,*(int *)(param_1 + 0x50));
      puVar5 = FUN_40b9945c(param_2,0x17);
      memset(puVar5,0,0x17);
      iVar8 = *(int *)(param_1 + 0x6c);
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
      return 0;
    }
    iVar4 = memcmp(_Buf1,&DAT_40ba472c,0x10);
    if (iVar4 == 0) {
      FUN_40b99414(param_2,(undefined4 *)&DAT_40ba472c);
      FUN_40b99438(param_2,&DAT_40ba6298);
      FUN_40b99844(param_2,*(int *)(param_1 + 0x50));
      puVar5 = FUN_40b9945c(param_2,0x12);
      memset(puVar5,0,0x12);
      iVar4 = *(int *)(param_1 + 0x6c);
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
      return 0;
    }
    iVar4 = memcmp(_Buf1,&DAT_40ba45ec,0x10);
    if (iVar4 == 0) {
      FUN_40b99414(param_2,(undefined4 *)&DAT_40ba45ec);
      FUN_40b99438(param_2,&DAT_40ba6298);
      FUN_40b99844(param_2,*(int *)(param_1 + 0x50));
      puVar5 = FUN_40b9945c(param_2,0x12);
      memset(puVar5,0,0x12);
      iVar4 = *(int *)(param_1 + 0x6c);
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
      return 0;
    }
    puVar9 = &DAT_40ba466c;
    uVar7 = 0x10;
    iVar4 = memcmp(_Buf1,&DAT_40ba466c,0x10);
    if (iVar4 == 0) {
      puVar5 = *(undefined1 **)(param_1 + 0x6c);
      if (puVar5[2] != '\0' || puVar5[3] != '\0') {
        FUN_40b99414(param_2,(undefined4 *)&DAT_40ba466c);
        FUN_40b99438(param_2,&DAT_40ba6298);
        FUN_40b99844(param_2,*(int *)(param_1 + 0x50));
        _Dst = FUN_40b9945c(param_2,0x12);
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
        return 0;
      }
      return 0x40258;
    }
    FUN_40b83ba4(0x40ba2bf8,puVar9,uVar7,param_4);
  }
  return 0x80004005;
}



/* 40b89b34 FUN_40b89b34 */

/* Boundary evidence: original MIPS .pdata 40b89b34..40b89bcf. Semantic name remains unreviewed. */

undefined4 FUN_40b89b34(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x1e920) * 0x1ee8 + param_1;
  iVar2 = *(int *)(iVar1 + 0x3244);
  iVar1 = FUN_40b88620(iVar1 + 0x1990,
                       *(int *)((*(int *)(param_1 + 0x1e920) * 0x7ba + iVar2 + 0xc82) * 4 + param_1)
                      );
  *param_2 = iVar1;
  if (iVar2 != iVar1) {
    FUN_40b83ba4(0x40ba2c48,iVar2,iVar1,param_4);
  }
  return 0;
}



/* 40b89bd0 FUN_40b89bd0 */

/* Boundary evidence: original MIPS .pdata 40b89bd0..40b89e2b. Semantic name remains unreviewed. */

int FUN_40b89bd0(int param_1,int param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 auStack_78 [18];
  uint local_30;
  
  local_30 = DAT_40ba9854;
  FUN_40b99688(auStack_78,(undefined4 *)&DAT_40ba56d8);
  piVar3 = (int *)(param_1 + 0x1e920);
  iVar1 = FUN_40b886d0(*piVar3 * 0x1ee8 + param_1 + 0x1990,param_2);
  if (iVar1 == 0x1fff) {
    FUN_40b9962c((int)auStack_78);
    FUN_40b9bea4(local_30);
    iVar1 = -0x7ffbfd9b;
  }
  else if (*(int *)((*piVar3 * 0x7ba + param_2 + 0xda0) * 4 + param_1) == 0) {
    FUN_40b9962c((int)auStack_78);
    FUN_40b9bea4(local_30);
    iVar1 = -0x7ffbfd9b;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x14);
    iVar1 = (**(code **)(**(int **)(iVar2 + 0xc) + 0x14))();
    if (-1 < iVar1) {
      *(int *)(*piVar3 * 0x1ee8 + param_1 + 0x3244) = param_2;
      iVar1 = *piVar3 * 0x7ba;
      iVar4 = *piVar3 * 0x1ee8 + param_1;
      *(undefined4 *)(param_1 + 0x1978) =
           *(undefined4 *)((*(int *)(iVar4 + 0x3244) + iVar1 + 0xc82) * 4 + param_1);
      *(undefined4 *)(iVar4 + 0x36bc) = *(undefined4 *)((iVar1 + param_2 + 0xda0) * 4 + param_1);
      iVar1 = param_2 * 0x48 + *piVar3 * 0x1ee8 + param_1;
      *(char *)(param_1 + 0x1e93c) = (char)*(undefined4 *)(*piVar3 * 0x1ee8 + param_1 + 0x36bc);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar1 + 0x324c);
      *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(iVar1 + 0x328c);
      iVar1 = FUN_40b8952c(param_1,(int)auStack_78,param_3,param_4);
      if (-1 < iVar1) {
        (**(code **)(**(int **)(iVar2 + 0xc) + 0x10))(*(int **)(iVar2 + 0xc),0);
        iVar1 = (**(code **)(**(int **)(iVar2 + 0xc) + 0xc))(*(int **)(iVar2 + 0xc),auStack_78);
      }
    }
    FUN_40b9962c((int)auStack_78);
    FUN_40b9bea4(local_30);
  }
  return iVar1;
}



/* 40b89e2c FUN_40b89e2c */

/* Boundary evidence: original MIPS .pdata 40b89e2c..40b89e5b. Semantic name remains unreviewed. */

void FUN_40b89e2c(void)

{
  int in_v0;
  
  FUN_40b9962c(in_v0 + -0x78);
  return;
}



/* 40b89e5c FUN_40b89e5c */

/* Boundary evidence: original MIPS .pdata 40b89e5c..40b89eab. Semantic name remains unreviewed. */

undefined4 FUN_40b89e5c(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b8857c(*(int *)(param_1 + 0x1e920) * 0x1ee8 + param_1 + 0x1990);
  *param_2 = iVar1;
  return 0;
}



/* 40b89eac FUN_40b89eac */

/* Boundary evidence: original MIPS .pdata 40b89eac..40b8a01f. Semantic name remains unreviewed. */

undefined4 FUN_40b89eac(int param_1,int param_2,LPWSTR param_3)

{
  uint *puVar1;
  wchar_t *pwVar2;
  int iVar3;
  int *piVar4;
  WCHAR local_248 [64];
  undefined2 local_1c8 [64];
  undefined2 local_148 [64];
  WCHAR aWStack_c8 [16];
  WCHAR aWStack_a8 [64];
  uint local_28;
  
  local_28 = DAT_40ba9854;
  piVar4 = (int *)(param_1 + 0x1e920);
  puVar1 = (uint *)FUN_40b884d8(*piVar4 * 0x1ee8 + param_1 + 0x1990,param_2);
  local_248[0] = L'\0';
  local_1c8[0] = 0;
  local_148[0] = 0;
  iVar3 = *(int *)((*piVar4 * 0x7ba + param_2 + 0xda0) * 4 + param_1);
  if (iVar3 == 0) {
    iVar3 = 0;
    pwVar2 = L"no %X";
  }
  else {
    pwVar2 = L"yes %X";
  }
  wsprintfW(aWStack_c8,pwVar2,iVar3);
  FUN_40b8735c(*piVar4 * 0x1ee8 + param_1 + 0x1990,*puVar1,aWStack_a8);
  FUN_40b871c0(*piVar4 * 0x1ee8 + param_1 + 0x1990,(byte *)puVar1[3],puVar1[2],local_248);
  wsprintfW(param_3,L"%s t%x pid%x %s %s %s %s",aWStack_c8,*puVar1,puVar1[1],local_1c8,aWStack_a8,
            local_248,local_148);
  FUN_40b9bea4(local_28);
  return 0;
}



/* 40b8a03c FUN_40b8a03c */

/* Boundary evidence: original MIPS .pdata 40b8a03c..40b8a08f. Semantic name remains unreviewed. */

undefined4 FUN_40b8a03c(int *param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  undefined4 uVar1;
  
  if ((param_1[0x7a49] != 0) && (param_2 < (uint)param_1[0x7a49])) {
    uVar1 = FUN_40b88b7c(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 0x80040265;
}



/* 40b8a130 FUN_40b8a130 */

/* Boundary evidence: original MIPS .pdata 40b8a130..40b8a2d7. Semantic name remains unreviewed. */

undefined4
FUN_40b8a130(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
            uint *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((*(uint *)(param_1 + 0x1e924) == 0) || (*(uint *)(param_1 + 0x1e924) <= param_2)) {
    uVar2 = 0x80040265;
  }
  else {
    iVar1 = param_2 * 0x1ee8;
    iVar4 = iVar1 + param_1;
    if (*(int *)(iVar4 + 0x31b8) != 0) {
      iVar3 = *(int *)(iVar4 + 0x3244);
      if (*(int *)((param_2 * 0x7ba + iVar3 + 0xc82) * 4 + param_1) != 0x1fff) {
        iVar5 = *(int *)(iVar3 * 0x48 + iVar1 + param_1 + 0x328c);
        *param_3 = *(undefined4 *)((iVar3 + param_2 * 0x7ba + 0xc82) * 4 + param_1);
        iVar3 = memcmp(*(void **)(*(int *)(iVar4 + 0x3244) * 0x48 + iVar1 + param_1 + 0x324c),
                       &DAT_40ba6618,0x10);
        if (iVar3 == 0) {
          *param_4 = 0x50;
        }
        iVar1 = memcmp(*(void **)(*(int *)(iVar4 + 0x3244) * 0x48 + iVar1 + param_1 + 0x324c),
                       &DAT_40ba6628,0x10);
        if (iVar1 == 0) {
          *param_4 = 0x2000;
        }
        *param_5 = *(undefined4 *)(iVar5 + 4);
        *param_6 = (uint)*(ushort *)(iVar5 + 2);
        return 0;
      }
    }
    uVar2 = 0x80040216;
  }
  return uVar2;
}



/* 40b8a2d8 FUN_40b8a2d8 */

/* Boundary evidence: original MIPS .pdata 40b8a2d8..40b8a3ef. Semantic name remains unreviewed. */

undefined4
FUN_40b8a2d8(int param_1,uint param_2,int *param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x1e924) == 0) || (*(uint *)(param_1 + 0x1e924) <= param_2)) {
    return 0x80040265;
  }
  iVar2 = param_2 * 0x1ee8 + param_1;
  if ((*(int *)(iVar2 + 0x31b8) != 0) && (*(int *)(iVar2 + 0x36c0) != 0x1fff)) {
    *param_3 = *(int *)(iVar2 + 0x36c0);
    iVar1 = memcmp(*(void **)(iVar2 + 0x36cc),&DAT_40ba65c8,0x10);
    if (iVar1 == 0) {
      iVar2 = *(int *)(iVar2 + 0x370c);
      *param_4 = *(undefined4 *)(iVar2 + 0x4c);
      *param_5 = *(undefined4 *)(iVar2 + 0x50);
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x370c);
    *param_4 = *(undefined4 *)(iVar2 + 0x34);
    *param_5 = *(undefined4 *)(iVar2 + 0x38);
    return 0;
  }
  return 0x80040216;
}



/* 40b8a3f0 FUN_40b8a3f0 */

/* Boundary evidence: original MIPS .pdata 40b8a3f0..40b8a52b. Semantic name remains unreviewed. */

uint FUN_40b8a3f0(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  int *in_stack_0000004c;
  int *in_stack_00000050;
  undefined1 auStack_68 [72];
  uint local_20;
  
  local_20 = DAT_40ba9854;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memcpy(auStack_68,&local_res4,0x48);
  uVar4 = 0x10;
  puVar3 = &DAT_40ba6f70;
  iVar1 = memcmp(auStack_68,&DAT_40ba6f70,0x10);
  if (iVar1 == 0) {
    FUN_40b83ba4(0x40ba2e98,puVar3,uVar4,param_4);
    FUN_40b9bea4(local_20);
    uVar2 = 0x80004005;
  }
  else {
    uVar4 = 0x10;
    puVar3 = &DAT_40ba56d8;
    iVar1 = memcmp(auStack_68,&DAT_40ba56d8,0x10);
    if (iVar1 == 0) {
      *in_stack_0000004c = *(int *)(param_1 + 0x50);
      *in_stack_00000050 = *(int *)(param_1 + 0x54);
    }
    else {
      *in_stack_0000004c = *(int *)(param_1 + 0x98);
      *in_stack_00000050 = *(int *)(param_1 + 0x9c);
    }
    iVar1 = *in_stack_0000004c;
    if (iVar1 == 0) {
      FUN_40b83ba4(0x40ba2e18,puVar3,uVar4,param_4);
      *in_stack_0000004c = 0x8000;
    }
    uVar2 = (uint)(iVar1 == 0);
    if (*in_stack_00000050 == 0) {
      FUN_40b83ba4(0x40ba2d94,puVar3,uVar4,param_4);
      *in_stack_00000050 = 0x40;
      uVar2 = 1;
    }
    FUN_40b9bea4(local_20);
  }
  return uVar2;
}



/* 40b8a52c FUN_40b8a52c */

/* Boundary evidence: original MIPS .pdata 40b8a52c..40b8a57b. Semantic name remains unreviewed. */

undefined4 FUN_40b8a52c(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (iVar1 = (**(code **)**(undefined4 **)(*(int *)(param_1 + 0xc) + 0xc))(), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



/* 40b8a57c FUN_40b8a57c */

/* Boundary evidence: original MIPS .pdata 40b8a57c..40b8a66f. Semantic name remains unreviewed. */

undefined4 FUN_40b8a57c(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_40ba6888,0x10);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0xc) != 0) &&
       (iVar1 = (**(code **)**(undefined4 **)(*(int *)(param_1 + 0xc) + 0xc))(), iVar1 != 0)) {
      *param_2 = *(undefined4 *)(param_1 + 0xf8);
      param_2[1] = *(undefined4 *)(param_1 + 0xfc);
      return 0;
    }
    if ((*(int *)(param_1 + 0x14) != 0) &&
       (iVar1 = (**(code **)**(undefined4 **)(*(int *)(param_1 + 0x14) + 0xc))(), iVar1 != 0)) {
      *param_2 = *(undefined4 *)(param_1 + 0xf0);
      param_2[1] = *(undefined4 *)(param_1 + 0xf4);
      return 0;
    }
  }
  return 0x80040261;
}



/* 40b8a670 FUN_40b8a670 */

/* Boundary evidence: original MIPS .pdata 40b8a670..40b8a71f. Semantic name remains unreviewed. */

void FUN_40b8a670(int param_1)

{
  if (*(int *)(param_1 + 0x1e934) != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0x14) + 0xc) + 8))();
    *(int *)(param_1 + 0x1e934) = 0;
  }
  if (*(int *)(param_1 + 0x1e938) != 0) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 0xc) + 8))();
    *(int *)(param_1 + 0x1e938) = 0;
  }
  *(undefined4 *)(param_1 + 0x1e92c) = 0;
  *(undefined4 *)(param_1 + 0x1e928) = 0;
  return;
}



/* 40b8a720 FUN_40b8a720 */

/* WARNING: Removing unreachable block (ram,0x40b8b44c) */
/* WARNING: Removing unreachable block (ram,0x40b8ad38) */
/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40b8a720..40b8bbc7. Semantic name remains unreviewed. */

int FUN_40b8a720(int *param_1,int *param_2,int *******param_3,size_t *param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  int iVar9;
  int ***********_Size;
  int ***********pppppppppppiVar10;
  wchar_t *pwVar11;
  undefined1 *puVar12;
  int *piVar13;
  uint *puVar14;
  int ***********pppppppppppiVar15;
  int iVar16;
  longlong lVar17;
  int local_94;
  wchar_t *local_90;
  int *local_8c;
  int local_88;
  int local_84;
  int *local_80;
  int local_7c;
  int ***********local_78;
  size_t *local_74;
  int *******local_70;
  undefined8 local_68;
  undefined8 local_60;
  int **********local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int **********local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  
  local_34 = (int *)((int)param_2 + (int)param_3);
  *param_4 = 0;
  local_84 = 0;
  if (param_5 != 0) {
    param_1[0x7a53] = 1;
  }
  local_90 = L"Process GetAudioSample failed to get sample buffer pointer (%08X)";
  pwVar11 = L"Process GetAudioSample failed to get sample buffer pointer (%08X)";
  local_74 = param_4;
  local_70 = param_3;
  local_38 = param_2;
  local_30 = param_2;
LAB_40b8a894:
  do {
    do {
      do {
        do {
          do {
            if ((local_34 <= local_38) || ((uint)((int)local_34 - (int)local_38) < 0xbc)) {
              *local_74 = (int)local_38 - (int)local_30;
              if ((5 < param_1[9]) || (param_1[9] < 0)) {
                *local_74 = (size_t)local_70;
              }
              return 0;
            }
            if (param_1[0x660] != 0) {
              WaitForSingleObject((HANDLE)param_1[0x7a4c],1000);
              (**(code **)(*param_1 + 0x14))(param_1);
            }
            if (param_1[0x40] != 0) {
              piVar4 = (int *)param_1[0x7a4d];
              if (piVar4 != (int *)0x0) {
                (**(code **)(*piVar4 + 8))();
                param_1[0x7a4d] = 0;
              }
              piVar4 = (int *)param_1[0x7a4e];
              if (piVar4 != (int *)0x0) {
                (**(code **)(*piVar4 + 8))();
                param_1[0x7a4e] = 0;
              }
              return 1;
            }
            piVar4 = param_1 + 0x7a99;
            FUN_40b888cc((uint *)&local_38,piVar4);
            iVar16 = param_1[0x7a9e];
          } while (iVar16 == 0x1fff);
          if (param_1[0x7aa3] != 0) {
            param_1[0x7a53] = 1;
            param_1[0x7a52] = 1;
          }
          if (((iVar16 == param_1[0x65f]) && (param_1[0x7aa6] != 0)) && (param_1[0x660] == 0)) {
            *(ulonglong *)(param_1 + 0x7a50) =
                 (ulonglong)(uint)param_1[0x7aac] * 300 +
                 CONCAT44(param_1[0x7aab] * 300,param_1[0x7aad]);
          }
          if ((iVar16 != param_1[0x65e]) || (param_1[0x660] != 0)) {
            if ((iVar16 == param_1[0x65d]) && (param_1[0x660] == 0)) {
              FUN_40b87880((int)piVar4,(uint *)(param_1 + 0x7a78));
              if ((uint)*(byte *)((int)param_1 + 0x1e93d) == param_1[0x7a78]) {
                local_80 = param_1 + 0x7a53;
                if (*local_80 == 0) {
                  if ((param_1[0x7aa1] != (param_1[0x7ac3] + 1U & 0xf)) &&
                     (param_1[0x7aa1] != param_1[0x7ac3])) {
                    *local_80 = 1;
                  }
                }
                param_1[0x7ac3] = param_1[0x7aa1];
                puVar14 = (uint *)(param_1 + 0x7a97);
                if ((*puVar14 != 0) && (local_8c = param_1 + 0x7a96, *local_8c != 0)) {
                  bVar8 = false;
                  uVar7 = param_1[param_1[0x7a48] * 0x7ba + 0xe18];
                  iVar6 = param_1[param_1[0x7a48] * 0x7ba + 0xe19];
                  local_88 = 0;
                  uVar1 = uVar7;
                  iVar16 = iVar6;
                  if (((param_1[0x7a81] & 2U) != 0) && (param_1[0x7a9c] != 0)) {
                    iVar16 = param_1[0x7a89];
                    bVar8 = true;
                    uVar1 = param_1[0x7a8a];
                    local_88 = 1;
                  }
                  uVar2 = uVar1;
                  if ((iVar16 <= iVar6) && ((iVar16 != iVar6 || (uVar1 < uVar7)))) {
                    uVar2 = uVar1 - 1;
                    iVar16 = iVar16 + 1 + (uint)(uVar2 < uVar1);
                  }
                  iVar6 = param_1[3];
                  if (iVar6 != 0) {
                    iVar9 = 0;
                    if (bVar8) {
                      if ((param_1[0x30] == uVar2) && (param_1[0x31] == iVar16)) {
                        local_88 = 0;
                        iVar9 = 0;
                      }
                      else {
                        param_4 = (size_t *)0x0;
                        param_3 = (int *******)0x5a;
                        param_1[0x30] = uVar2;
                        param_1[0x31] = iVar16;
                        lVar17 = __ll_div();
                        *(longlong *)(param_1 + 0x3e) = lVar17 * 10000;
                        iVar9 = local_88;
                      }
                    }
                    local_60._0_4_ = 0;
                    pppppppppppiVar15 = (int ***********)0x0;
                    piVar4 = param_1 + 0x7a4b;
                    local_60._4_4_ = 0;
                    local_94 = 0;
                    local_78 = (int ***********)0x0;
                    if ((*piVar4 != 0) && (iVar9 != 0)) {
                      uVar1 = param_1[0x3e] - param_1[0x38];
                      param_3 = (int *******)param_1[9];
                      iVar16 = (((param_1[0x3f] - param_1[0x39]) -
                                (uint)((uint)param_1[0x3e] < (uint)param_1[0x38])) - param_1[0x37])
                               - (uint)(uVar1 < (uint)param_1[0x36]);
                      param_4 = (size_t *)((int)param_3 >> 0x1f);
                      lVar17 = __ll_div(uVar1 - param_1[0x36]);
                      if (-0x4c4b41 < lVar17) {
                        *piVar4 = 0;
                      }
                    }
                    if ((*piVar4 != 0) || (param_1[0x40] != 0)) {
                      piVar4 = param_1 + 0x7a4e;
                      if (*piVar4 != 0) {
                        FUN_40b83ba4(0x40ba2fb4,iVar16,param_3,(va_list)param_4);
                        (**(code **)(*(int *)*piVar4 + 8))();
                        *piVar4 = 0;
                      }
                      goto LAB_40b8a894;
                    }
                    piVar4 = param_1 + 0x7a4e;
                    if (*piVar4 == 0) {
                      iVar16 = (**(code **)(**(int **)(iVar6 + 0xc) + 4))
                                         (*(int **)(iVar6 + 0xc),piVar4);
                      pwVar11 = local_90;
                      if (iVar16 == 1) goto LAB_40b8a894;
                      if ((iVar16 < 0) || (piVar5 = (int *)*piVar4, piVar5 == (int *)0x0)) {
                        FUN_40b83ba4(0x40ba2ee4,iVar16,param_3,(va_list)param_4);
                        return iVar16;
                      }
                      (**(code **)(*piVar5 + 0x30))(piVar5,0);
                    }
                    iVar16 = (**(code **)(*(int *)*piVar4 + 0xc))((int *)*piVar4,&local_94);
                    if (iVar16 < 0) {
                      FUN_40b83ba4(0x40ba30b8,iVar16,param_3,(va_list)param_4);
                    }
                    uVar1 = (**(code **)(*(int *)*piVar4 + 0x10))();
                    uVar7 = (**(code **)(*(int *)*piVar4 + 0x2c))();
                    if (uVar1 < *puVar14 + uVar7) {
                      _Size = (int ***********)(uVar1 - uVar7);
                      param_3 = (int *******)_Size;
                      memcpy((void *)(uVar7 + local_94),(void *)*local_8c,(size_t)_Size);
                      uVar7 = uVar7 + (int)_Size;
                      (**(code **)(*(int *)*piVar4 + 0x30))((int *)*piVar4,uVar7);
                    }
                    else {
                      _Size = (int ***********)0x0;
                    }
                    if ((uVar7 == uVar1) ||
                       ((((local_88 != 0 || (*local_80 != 0)) || (local_84 != 0)) && (uVar7 != 0))))
                    {
                      local_40 = 0;
                      local_3c = 0;
                      local_48 = (int **********)0x0;
                      local_44 = 0;
                      param_3 = (int *******)&local_48;
                      (**(code **)(*(int *)*piVar4 + 0x14))((int *)*piVar4,&local_40);
                      (**(code **)(**(int **)(iVar6 + 0xc) + 8))(*(int **)(iVar6 + 0xc),*piVar4);
                      *piVar4 = 0;
                      if (local_84 != 0) {
                        *local_74 = (size_t)local_70;
                        return 0;
                      }
                    }
                    pwVar11 = local_90;
                    if (param_1[0x40] == 0) {
                      if (*piVar4 == 0) {
                        iVar16 = (**(code **)(**(int **)(iVar6 + 0xc) + 4))
                                           (*(int **)(iVar6 + 0xc),piVar4);
                        if ((iVar16 < 0) || (piVar5 = (int *)*piVar4, piVar5 == (int *)0x0)) {
                          FUN_40b83ba4(0x40ba2ee4,iVar16,param_3,(va_list)param_4);
                          return iVar16;
                        }
                        (**(code **)(*piVar5 + 0x30))(piVar5,0);
                        iVar16 = (**(code **)(*(int *)*piVar4 + 0xc))((int *)*piVar4,&local_94);
                        if (iVar16 < 0) {
                          FUN_40b83ba4(0x40ba30b8,iVar16,param_3,(va_list)param_4);
                        }
                        (**(code **)(*(int *)*piVar4 + 0x10))();
                        uVar7 = (**(code **)(*(int *)*piVar4 + 0x2c))();
                      }
                      piVar13 = local_80;
                      piVar5 = local_8c;
                      if (((*local_80 != 0) && (param_1[0x7a55] == 0)) && (param_1[0x7a56] == 0)) {
                        param_3 = (int *******)&local_78;
                        iVar16 = FUN_40b892b8((undefined1 *)*local_8c,*puVar14,(int *)param_3);
                        pwVar11 = local_90;
                        pppppppppppiVar15 = local_78;
                        if (iVar16 == 0) goto LAB_40b8a894;
                      }
                      iVar16 = param_1[9];
                      if (_Size == (int ***********)0x0) {
                        if ((5 < iVar16) || (iVar16 < 1)) {
                          local_78 = (int ***********)0x0;
                          if ((param_1[0x7a55] == 0) && (param_1[0x7a56] == 0)) {
                            param_4 = (size_t *)0x0;
                          }
                          else {
                            param_4 = (size_t *)0x1;
                          }
                          uVar1 = *puVar14;
                          puVar12 = (undefined1 *)*piVar5;
                          iVar16 = FUN_40b89380(puVar12,uVar1,(int *)&local_78,(int)param_4);
                          pppppppppppiVar10 = local_78;
                          if (iVar16 == 0) {
                            param_3 = (int *******)(uVar1 - (int)pppppppppppiVar15);
                            memcpy((void *)(uVar7 + local_94),puVar12 + (int)pppppppppppiVar15,
                                   (size_t)param_3);
                            iVar16 = (*puVar14 - (int)pppppppppppiVar15) + uVar7;
                          }
                          else {
                            param_3 = (int *******)local_78;
                            memcpy((void *)(uVar7 + local_94),puVar12,(size_t)local_78);
LAB_40b8b924:
                            iVar16 = (int)pppppppppppiVar10 + uVar7;
                            local_84 = 1;
                          }
                        }
                        else {
                          param_3 = (int *******)*puVar14;
                          memcpy((void *)(uVar7 + local_94),(void *)*piVar5,(size_t)param_3);
                          iVar16 = *puVar14 + uVar7;
                        }
                      }
                      else if ((5 < iVar16) || (iVar16 < 1)) {
                        local_78 = (int ***********)0x0;
                        if ((param_1[0x7a55] == 0) && (param_1[0x7a56] == 0)) {
                          param_4 = (size_t *)0x0;
                        }
                        else {
                          param_4 = (size_t *)0x1;
                        }
                        param_3 = (int *******)(*puVar14 - (int)_Size);
                        puVar12 = (undefined1 *)(*piVar5 + (int)_Size);
                        iVar16 = FUN_40b89380(puVar12,(uint)param_3,(int *)&local_78,(int)param_4);
                        pppppppppppiVar10 = local_78;
                        if (iVar16 != 0) {
                          param_3 = (int *******)local_78;
                          memcpy((void *)(uVar7 + local_94),puVar12,(size_t)local_78);
                          piVar13 = local_80;
                          goto LAB_40b8b924;
                        }
                        memcpy((void *)(uVar7 + local_94),puVar12,(size_t)param_3);
                        iVar16 = (*puVar14 - (int)_Size) + uVar7;
                        piVar13 = local_80;
                      }
                      else {
                        param_3 = (int *******)(*puVar14 - (int)_Size);
                        memcpy((void *)(uVar7 + local_94),(void *)(*piVar5 + (int)_Size),
                               (size_t)param_3);
                        iVar16 = (*puVar14 - (int)_Size) + uVar7;
                      }
                      (**(code **)(*(int *)*piVar4 + 0x30))((int *)*piVar4,iVar16);
                      if (local_88 != 0) {
                        uVar1 = param_1[0x3e] - param_1[0x38];
                        param_4 = (size_t *)(param_1[9] >> 0x1f);
                        local_60 = __ll_div(uVar1 - param_1[0x36],
                                            (((param_1[0x3f] - param_1[0x39]) -
                                             (uint)((uint)param_1[0x3e] < (uint)param_1[0x38])) -
                                            param_1[0x37]) - (uint)(uVar1 < (uint)param_1[0x36]));
                        param_3 = (int *******)0x0;
                        (**(code **)(*(int *)*piVar4 + 0x18))((int *)*piVar4,&local_60);
                      }
                      if (((*piVar13 != 0) || (5 < param_1[9])) ||
                         (pwVar11 = local_90, param_1[9] < 0)) {
                        (**(code **)(*(int *)*piVar4 + 0x40))((int *)*piVar4,1);
                        *piVar13 = 0;
                        pwVar11 = local_90;
                      }
                    }
                  }
                }
              }
            }
            goto LAB_40b8a894;
          }
          FUN_40b87880((int)piVar4,(uint *)(param_1 + 0x7a57));
        } while ((uint)*(byte *)(param_1 + 0x7a4f) != param_1[0x7a57]);
        piVar4 = param_1 + 0x7a52;
        if (*piVar4 == 0) {
          if ((param_1[0x7aa1] != (param_1[0x7ac4] + 1U & 0xf)) &&
             (param_1[0x7aa1] != param_1[0x7ac4])) {
            *piVar4 = 1;
          }
        }
        param_1[0x7ac4] = param_1[0x7aa1];
        piVar5 = param_1 + 0x7a76;
      } while ((*piVar5 == 0) || (param_1[0x7a75] == 0));
      bVar8 = false;
      uVar7 = param_1[param_1[0x7a48] * 0x7ba + 0xe18];
      iVar6 = param_1[param_1[0x7a48] * 0x7ba + 0xe19];
      uVar1 = uVar7;
      iVar16 = iVar6;
      if (((param_1[0x7a60] & 2U) != 0) && (param_1[0x7a9c] != 0)) {
        iVar16 = param_1[0x7a68];
        uVar1 = param_1[0x7a69];
        bVar8 = true;
      }
      uVar2 = uVar1;
      if ((iVar16 <= iVar6) && ((iVar16 != iVar6 || (uVar1 < uVar7)))) {
        if ((iVar6 <= param_1[0x2f]) && ((param_1[0x2f] != iVar6 || (uVar7 < (uint)param_1[0x2e]))))
        {
          uVar2 = uVar1 - 1;
          iVar16 = iVar16 + 1 + (uint)(uVar2 < uVar1);
        }
      }
      iVar6 = param_1[5];
    } while (iVar6 == 0);
    if (bVar8) {
      param_4 = (size_t *)0x0;
      param_3 = (int *******)0x5a;
      param_1[0x2e] = uVar2;
      param_1[0x2f] = iVar16;
      lVar17 = __ll_div();
      *(longlong *)(param_1 + 0x3c) = lVar17 * 10000;
    }
    local_68._0_4_ = 0;
    piVar13 = param_1 + 0x7a4a;
    local_68._4_4_ = 0;
    local_7c = 0;
    if ((*piVar13 != 0) && (bVar8)) {
      uVar1 = param_1[0x3c] - param_1[0x38];
      param_3 = (int *******)param_1[9];
      param_4 = (size_t *)((int)param_3 >> 0x1f);
      lVar17 = __ll_div(uVar1 - param_1[0x36],
                        (((param_1[0x3d] - param_1[0x39]) -
                         (uint)((uint)param_1[0x3c] < (uint)param_1[0x38])) - param_1[0x37]) -
                        (uint)(uVar1 < (uint)param_1[0x36]));
      if (-0x7a121 < lVar17) {
        *piVar13 = 0;
      }
    }
    if (((*piVar13 == 0) && (param_1[0x40] == 0)) && (param_1[9] == 1)) {
      piVar13 = param_1 + 0x7a4d;
      if (*piVar13 == 0) {
        iVar16 = (**(code **)(**(int **)(iVar6 + 0xc) + 4))(*(int **)(iVar6 + 0xc),piVar13);
        if (iVar16 == 1) goto LAB_40b8a894;
        if (iVar16 < 0) {
          return iVar16;
        }
        piVar3 = (int *)*piVar13;
        if (piVar3 == (int *)0x0) {
          return iVar16;
        }
        (**(code **)(*piVar3 + 0x30))(piVar3,0);
      }
      iVar16 = (**(code **)(*(int *)*piVar13 + 0xc))((int *)*piVar13,&local_7c);
      if (iVar16 < 0) {
        FUN_40b83ba4((size_t)pwVar11,iVar16,param_3,(va_list)param_4);
      }
      uVar1 = (**(code **)(*(int *)*piVar13 + 0x10))();
      iVar16 = (**(code **)(*(int *)*piVar13 + 0x2c))();
      if ((uVar1 < (uint)(*piVar5 + iVar16)) || (((bVar8 || (*piVar4 != 0)) && (iVar16 != 0)))) {
        local_50 = 0;
        local_4c = 0;
        local_58 = (int **********)0x0;
        local_54 = 0;
        param_3 = (int *******)&local_58;
        (**(code **)(*(int *)*piVar13 + 0x14))((int *)*piVar13,&local_50);
        (**(code **)(**(int **)(iVar6 + 0xc) + 8))(*(int **)(iVar6 + 0xc),*piVar13);
        *piVar13 = 0;
      }
      pwVar11 = local_90;
      if (param_1[0x40] == 0) {
        if (*piVar13 == 0) {
          iVar16 = (**(code **)(**(int **)(iVar6 + 0xc) + 4))(*(int **)(iVar6 + 0xc),piVar13);
          if ((iVar16 < 0) || (piVar3 = (int *)*piVar13, piVar3 == (int *)0x0)) {
            FUN_40b83ba4(0x40ba2f4c,iVar16,param_3,(va_list)param_4);
            return iVar16;
          }
          (**(code **)(*piVar3 + 0x30))(piVar3,0);
          iVar16 = (**(code **)(*(int *)*piVar13 + 0xc))((int *)*piVar13,&local_7c);
          if (iVar16 < 0) {
            FUN_40b83ba4((size_t)local_90,iVar16,param_3,(va_list)param_4);
          }
          (**(code **)(*(int *)*piVar13 + 0x10))();
          iVar16 = (**(code **)(*(int *)*piVar13 + 0x2c))();
        }
        param_3 = (int *******)*piVar5;
        memcpy((void *)(iVar16 + local_7c),(void *)param_1[0x7a75],(size_t)param_3);
        (**(code **)(*(int *)*piVar13 + 0x30))((int *)*piVar13,*piVar5 + iVar16);
        if (bVar8) {
          uVar1 = param_1[0x3c] - param_1[0x38];
          param_4 = (size_t *)(param_1[9] >> 0x1f);
          local_68 = __ll_div(uVar1 - param_1[0x36],
                              (((param_1[0x3d] - param_1[0x39]) -
                               (uint)((uint)param_1[0x3c] < (uint)param_1[0x38])) - param_1[0x37]) -
                              (uint)(uVar1 < (uint)param_1[0x36]));
          param_3 = (int *******)0x0;
          (**(code **)(*(int *)*piVar13 + 0x18))((int *)*piVar13,&local_68);
        }
        pwVar11 = local_90;
        if (*piVar4 != 0) {
          (**(code **)(*(int *)*piVar13 + 0x40))((int *)*piVar13,1);
          *piVar4 = 0;
        }
      }
      goto LAB_40b8a894;
    }
    piVar4 = (int *)param_1[0x7a4d];
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))();
      param_1[0x7a4d] = 0;
    }
  } while( true );
}



/* 40b8bbc8 FUN_40b8bbc8 */

/* Boundary evidence: original MIPS .pdata 40b8bbc8..40b8bcd7. Semantic name remains unreviewed. */

undefined4 FUN_40b8bbc8(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  va_list pcVar4;
  
  piVar3 = param_3;
  iVar1 = (**(code **)(*param_1 + 0x48))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x44))(param_1);
  pcVar4 = (va_list)(iVar1 + iVar2);
  if (pcVar4 != (va_list)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x48))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x44))(param_1);
    if (param_2 < iVar1 + iVar2) {
      if (param_3 != (int *)0x0) {
        iVar1 = (**(code **)(*param_1 + 0x48))(param_1);
        iVar2 = *param_3;
        if (param_2 < iVar1) {
          iVar1 = param_1[3];
        }
        else {
          iVar1 = param_1[5];
        }
        (**(code **)(**(int **)(iVar1 + 0xc) + 0x18))();
        if (*param_3 == 0) {
          FUN_40b83ba4(0x40ba313c,iVar2,piVar3,pcVar4);
          return 0x80004005;
        }
      }
      return 0;
    }
  }
  return 0x80004005;
}



/* 40b8bcd8 FUN_40b8bcd8 */

/* Boundary evidence: original MIPS .pdata 40b8bcd8..40b8bda3. Semantic name remains unreviewed. */

undefined4 FUN_40b8bcd8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

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
    *puVar1 = &PTR_FUN_40ba2b80;
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



/* 40b8bda4 FUN_40b8bda4 */

/* Boundary evidence: original MIPS .pdata 40b8bda4..40b8be4f. Semantic name remains unreviewed. */

int FUN_40b8bda4(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = 0;
  iVar3 = 1;
  uVar1 = FUN_40b85778(&DAT_40bab7dc,1);
  if (uVar1 == 0) {
    do {
      uVar2 = uVar2 + 1;
      uVar1 = FUN_40b85778(&DAT_40bab7dc,1);
    } while (uVar1 == 0);
    if (uVar2 == 0) goto LAB_40b8be2c;
    uVar4 = FUN_40b85778(&DAT_40bab7dc,uVar2 & 0xff);
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    iVar3 = iVar3 << 1;
  }
LAB_40b8be2c:
  return iVar3 + uVar4 + -1;
}



/* 40b8be50 FUN_40b8be50 */

/* Boundary evidence: original MIPS .pdata 40b8be50..40b8bf5b. Semantic name remains unreviewed. */

uint FUN_40b8be50(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar5 = 0;
  iVar4 = 1;
  uVar1 = FUN_40b85778(&DAT_40bab7dc,1);
  if (uVar1 == 0) {
    do {
      uVar3 = uVar3 + 1;
      uVar1 = FUN_40b85778(&DAT_40bab7dc,1);
    } while (uVar1 == 0);
    if (uVar3 != 0) {
      uVar5 = FUN_40b85778(&DAT_40bab7dc,uVar3 & 0xff);
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
    if (uVar3 == 0) goto LAB_40b8bf10;
    uVar3 = uVar3 - 2;
  }
  if (uVar3 != 0) {
    iVar2 = (int)uVar1 >> 1;
    if ((int)uVar1 < 0) {
      iVar2 = iVar4;
    }
    return iVar2 + 1;
  }
LAB_40b8bf10:
  iVar2 = (int)uVar1 >> 1;
  if ((int)uVar1 < 0) {
    iVar2 = iVar4;
  }
  return -iVar2;
}



/* 40b8bf5c FUN_40b8bf5c */

/* Boundary evidence: original MIPS .pdata 40b8bf5c..40b8c1d3. Semantic name remains unreviewed. */

undefined4 FUN_40b8bf5c(int param_1,int param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint *puVar5;
  uint local_428 [256];
  undefined1 local_28 [8];
  uint local_20;
  
  local_20 = DAT_40ba9854;
  DAT_40bab7e0 = param_1 + param_2;
  DAT_40bab7e8 = 0;
  DAT_40bab7e9 = 0;
  DAT_40bab7dc = param_1;
  DAT_40bab7e4 = param_1;
  uVar1 = FUN_40b85778(&DAT_40bab7dc,8);
  uVar1 = uVar1 & 0xff;
  FUN_40b85778(&DAT_40bab7dc,1);
  FUN_40b85778(&DAT_40bab7dc,1);
  FUN_40b85778(&DAT_40bab7dc,1);
  FUN_40b85778(&DAT_40bab7dc,1);
  FUN_40b85778(&DAT_40bab7dc,4);
  FUN_40b85778(&DAT_40bab7dc,8);
  FUN_40b8bda4();
  if ((((uVar1 == 100) || (uVar1 == 0x6e)) || (uVar1 == 0x7a)) || (uVar1 == 0x90)) {
    iVar2 = FUN_40b8bda4();
    if (iVar2 == 3) {
      FUN_40b85778(&DAT_40bab7dc,1);
    }
    FUN_40b8bda4();
    FUN_40b8bda4();
    FUN_40b85778(&DAT_40bab7dc,1);
    uVar1 = FUN_40b85778(&DAT_40bab7dc,1);
    if ((uVar1 & 0xff) != 0) {
      iVar2 = 0;
      do {
        uVar1 = FUN_40b85778(&DAT_40bab7dc,1);
        puVar4 = local_28 + iVar2;
        iVar2 = iVar2 + 1;
        *puVar4 = (char)uVar1;
      } while (iVar2 < 8);
    }
  }
  FUN_40b8bda4();
  iVar2 = FUN_40b8bda4();
  if (iVar2 == 0) {
    FUN_40b8bda4();
  }
  else if (iVar2 == 1) {
    FUN_40b85778(&DAT_40bab7dc,1);
    FUN_40b8be50();
    FUN_40b8be50();
    iVar2 = FUN_40b8bda4();
    if (0 < iVar2) {
      puVar5 = local_428;
      do {
        uVar1 = FUN_40b8be50();
        iVar2 = iVar2 + -1;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
      } while (iVar2 != 0);
    }
  }
  FUN_40b8bda4();
  FUN_40b85778(&DAT_40bab7dc,1);
  iVar2 = FUN_40b8bda4();
  iVar3 = FUN_40b8bda4();
  *param_3 = (iVar2 + 1) * 0x10;
  uVar1 = FUN_40b85778(&DAT_40bab7dc,1);
  *param_4 = (2 - (uVar1 & 0xff)) * (iVar3 + 1) * 0x10;
  FUN_40b9bea4(local_20);
  return 0;
}



/* 40b8c1d4 FUN_40b8c1d4 */

/* Boundary evidence: original MIPS .pdata 40b8c1d4..40b8c35f. Semantic name remains unreviewed. */

void FUN_40b8c1d4(int param_1,uint param_2,int *param_3,int *param_4)

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
    FUN_40b85778(&local_30,1);
    FUN_40b85778(&local_30,2);
    uVar2 = FUN_40b85778(&local_30,5);
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
      bVar1 = FUN_40b85184(&local_res0,local_res4);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        return;
      }
      param_1 = local_res0 + 3;
      param_2 = local_res4[0] - 3;
      break;
    case 7:
      piVar3 = param_3;
      piVar4 = param_4;
      FUN_40b8bf5c(param_1 + 1,param_2,param_3,param_4);
      param_1 = local_res0 + 3;
      param_2 = local_res4[0] - 3;
      if ((*param_3 != 0) && (*param_4 != 0)) {
        return;
      }
      break;
    default:
      FUN_40b83ba4(0x40ba1b90,uVar2 & 0xff,piVar3,(va_list)piVar4);
      return;
    }
  } while( true );
}



/* 40b8c360 FUN_40b8c360 */

/* Boundary evidence: original MIPS .pdata 40b8c360..40b8c623. Semantic name remains unreviewed. */

void FUN_40b8c360(int param_1,int param_2,uint *param_3,uint *param_4)

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
  FUN_40b85778(&local_38,1);
  FUN_40b85778(&local_38,8);
  uVar4 = 0;
  uVar1 = FUN_40b85778(&local_38,1);
  if (uVar1 != 0) {
    uVar4 = FUN_40b85778(&local_38,4);
    FUN_40b85778(&local_38,3);
  }
  uVar1 = FUN_40b85778(&local_38,4);
  if (uVar1 == 0xf) {
    FUN_40b85778(&local_38,8);
    FUN_40b85778(&local_38,8);
  }
  uVar1 = FUN_40b85778(&local_38,1);
  if (uVar1 != 0) {
    FUN_40b85778(&local_38,2);
    FUN_40b85778(&local_38,1);
    uVar1 = FUN_40b85778(&local_38,1);
    if (uVar1 != 0) {
      FUN_40b85778(&local_38,0xf);
      uVar1 = FUN_40b85778(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
      FUN_40b85778(&local_38,0xf);
      uVar1 = FUN_40b85778(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
      FUN_40b85778(&local_38,0xf);
      uVar1 = FUN_40b85778(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
      FUN_40b85778(&local_38,3);
      FUN_40b85778(&local_38,0xb);
      uVar1 = FUN_40b85778(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
      FUN_40b85778(&local_38,0xf);
      uVar1 = FUN_40b85778(&local_38,1);
      if (uVar1 != 1) {
        return;
      }
    }
  }
  uVar1 = FUN_40b85778(&local_38,2);
  if (((uVar1 != 3) || (uVar4 == 1)) && (uVar4 = FUN_40b85778(&local_38,1), uVar4 == 1)) {
    uVar4 = FUN_40b85778(&local_38,0x10);
    uVar2 = FUN_40b85778(&local_38,1);
    if (uVar2 == 1) {
      uVar2 = FUN_40b85778(&local_38,1);
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
        FUN_40b85778(&local_38,uVar3 & 0xff);
      }
      if ((uVar1 == 0) && (uVar1 = FUN_40b85778(&local_38,1), uVar1 == 1)) {
        uVar1 = FUN_40b85778(&local_38,0xd);
        *param_3 = uVar1;
        uVar1 = FUN_40b85778(&local_38,1);
        if (uVar1 == 1) {
          uVar1 = FUN_40b85778(&local_38,0xd);
          *param_4 = uVar1;
        }
      }
    }
  }
  return;
}



/* 40b8c624 FUN_40b8c624 */

/* Boundary evidence: original MIPS .pdata 40b8c624..40b8cb37. Semantic name remains unreviewed. */

undefined4
FUN_40b8c624(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5,int param_6
            ,int *param_7)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  void **ppvVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  ulonglong uVar11;
  void *local_210 [2];
  void *local_208;
  void *local_204;
  void *local_200;
  int *local_1fc;
  int local_1f8;
  uint local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  uint local_1e0 [3];
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  uint local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  uint local_19c;
  uint local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_16c;
  uint local_164;
  undefined4 local_160;
  uint local_158 [3];
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  uint local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  uint local_114;
  uint local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e4;
  uint local_dc;
  undefined4 local_d8;
  undefined4 auStack_d0 [3];
  int local_c4;
  int local_bc;
  
  local_210[0] = (void *)0x0;
  local_16c = 1;
  local_1e0[0] = 0;
  local_1e0[1] = 0;
  local_1d4 = 0;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  local_1a0 = 0;
  local_19c = 0;
  local_198 = 0;
  local_194 = 0;
  local_190 = 0;
  local_18c = 0;
  local_188 = 0;
  local_184 = 0;
  local_180 = 0;
  local_17c = 0;
  local_178 = 0;
  local_174 = 0;
  local_160 = 0;
  local_e4 = 1;
  local_158[0] = 0;
  local_158[1] = 0;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_140 = 0;
  local_13c = 0;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0;
  local_100 = 0;
  local_fc = 0;
  local_f8 = 0;
  local_f4 = 0;
  local_f0 = 0;
  local_ec = 0;
  local_d8 = 0;
  local_1fc = param_2;
  local_1e8 = param_4;
  local_1e4 = param_3;
  FUN_40b8694c(auStack_d0);
  uVar6 = 0xffffffff;
  local_1f0 = 0;
  local_1ec = 0;
  uVar9 = uVar6;
  iVar7 = 0;
  do {
    uVar8 = local_1f0;
    uVar3 = 0;
    if ((0 < iVar7) || ((iVar7 == 0 && (0x20000 < local_1f0)))) break;
    iVar2 = (**(code **)(*param_2 + 8))(param_2);
    if (-1 < iVar2) {
      uVar5 = 0x8000;
      ppvVar4 = local_210;
      uVar3 = FUN_40b90bf4(param_1,ppvVar4,0x8000,param_2);
      if ((local_210[0] == (void *)0x0) && (uVar3 == 0)) {
        FUN_40b83ba4(0x40ba3174,ppvVar4,uVar5,(va_list)param_2);
        *(undefined4 *)(param_1 + 4) = 1;
        goto LAB_40b8c808;
      }
    }
    local_1f0 = uVar3 + uVar8;
    local_1f8 = iVar7 + (uint)(local_1f0 < uVar3);
    local_204 = (void *)(uVar3 + (int)local_210[0]);
    local_208 = local_210[0];
    local_200 = local_210[0];
    while ((local_208 < local_204 && (0xbb < (uint)((int)local_204 - (int)local_208)))) {
      FUN_40b888cc((uint *)&local_208,auStack_d0);
      if (local_bc != 0x1fff) {
        piVar10 = (int *)(param_1 + 0x1e920);
        if (((((local_bc ==
                *(int *)((*(int *)(*piVar10 * 0x1ee8 + param_1 + 0x3244) + *piVar10 * 0x7ba + 0xc82)
                         * 4 + param_1)) && (FUN_40b87880((int)auStack_d0,local_1e0), 4 < local_164)
              ) && (local_c4 != 0)) &&
            (((local_1e0[0] & 0xe0) == 0xc0 || ((local_1e0[0] & 0xff) == 0xbd)))) &&
           ((local_1bc & 2) != 0)) {
          iVar7 = *piVar10 * 0x1ee8 + param_1;
          uVar8 = *(uint *)(iVar7 + 0x3864);
          uVar6 = local_198;
          uVar9 = local_19c;
          if (((int)local_19c <= (int)uVar8) &&
             ((local_19c != uVar8 || (local_198 < *(uint *)(iVar7 + 0x3860))))) {
            uVar6 = local_198 - 1;
            uVar9 = local_19c + 1 + (uint)(uVar6 < local_198);
          }
        }
        if ((((local_bc == *(int *)(*piVar10 * 0x1ee8 + param_1 + 0x36c0)) &&
             (FUN_40b87880((int)auStack_d0,local_158), 4 < local_dc)) && (local_c4 != 0)) &&
           (((local_158[0] & 0xf0) == 0xe0 && ((local_134 & 2) != 0)))) {
          iVar7 = *piVar10 * 0x1ee8 + param_1;
          uVar8 = *(uint *)(iVar7 + 0x3864);
          uVar6 = local_110;
          uVar9 = local_114;
          if (((int)local_114 <= (int)uVar8) &&
             ((local_114 != uVar8 || (local_110 < *(uint *)(iVar7 + 0x3860))))) {
            uVar6 = local_110 - 1;
            uVar9 = local_114 + 1 + (uint)(uVar6 < local_110);
          }
        }
      }
    }
    operator_delete(local_210[0]);
    local_210[0] = (void *)0x0;
    iVar7 = local_1f8;
    param_2 = local_1fc;
  } while ((uVar6 & uVar9) == 0xffffffff);
  (**(code **)(*param_2 + 8))(param_2);
  if ((uVar6 & uVar9) == 0xffffffff) {
LAB_40b8c808:
    uVar5 = 0x80004005;
  }
  else {
    uVar11 = __ll_div(uVar6,uVar9,0x5a,0);
    iVar7 = *(int *)(param_1 + 0xdc);
    lVar1 = (uVar11 & 0xffffffff) * 10000;
    uVar6 = (uint)lVar1;
    uVar9 = *(uint *)(param_1 + 0xd8);
    uVar8 = uVar6 - uVar9;
    *param_7 = uVar8 - param_5;
    param_7[1] = (((((int)(uVar11 >> 0x20) * 10000 + (int)((ulonglong)lVar1 >> 0x20)) - iVar7) -
                  (uint)(uVar6 < uVar9)) - param_6) - (uint)(uVar8 < param_5);
    uVar5 = 0;
  }
  return uVar5;
}



/* 40b8cb38 FUN_40b8cb38 */

/* Boundary evidence: original MIPS .pdata 40b8cb38..40b8cbef. Semantic name remains unreviewed. */

int FUN_40b8cb38(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  undefined4 auStack_60 [18];
  uint local_18;
  
  local_18 = DAT_40ba9854;
  FUN_40b99688(auStack_60,(undefined4 *)&DAT_40ba56d8);
  iVar1 = FUN_40b8952c(param_1,(int)auStack_60,param_3,param_4);
  if ((-1 < iVar1) && (iVar1 = FUN_40b8bcd8(param_1,1,L"Audio",auStack_60), -1 < iVar1)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  }
  FUN_40b9962c((int)auStack_60);
  FUN_40b9bea4(local_18);
  return iVar1;
}



/* 40b8cbf0 FUN_40b8cbf0 */

/* Boundary evidence: original MIPS .pdata 40b8cbf0..40b8cc1f. Semantic name remains unreviewed. */

void FUN_40b8cbf0(void)

{
  int in_v0;
  
  FUN_40b9962c(in_v0 + -0x60);
  return;
}



/* 40b8cc20 FUN_40b8cc20 */

/* Boundary evidence: original MIPS .pdata 40b8cc20..40b8d00f. Semantic name remains unreviewed. */

int FUN_40b8cc20(int param_1,int param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 uVar3;
  int iVar4;
  void *_Buf1;
  undefined *puVar5;
  undefined4 auStack_70 [18];
  uint local_28;
  
  local_28 = DAT_40ba9854;
  iVar4 = -0x7fffbffb;
  iVar1 = memcmp(*(void **)(param_1 + 0x70),&DAT_40ba56c8,0x10);
  if (iVar1 != 0) goto LAB_40b8cfac;
  FUN_40b99688(auStack_70,(undefined4 *)&DAT_40ba56c8);
  _Buf1 = *(void **)(param_1 + 0x74);
  iVar1 = memcmp(_Buf1,&DAT_40ba65c8,0x10);
  if (iVar1 == 0) {
    if ((param_2 == 0) || (*(int *)(param_2 + 0x40) == 0)) {
      FUN_40b99414((int)auStack_70,(undefined4 *)&DAT_40ba65c8);
      FUN_40b99438((int)auStack_70,(undefined4 *)&DAT_40ba6278);
      FUN_40b99844((int)auStack_70,*(int *)(param_1 + 0x98));
      pvVar2 = FUN_40b9945c((int)auStack_70,0x58);
      memset(pvVar2,0,0x58);
      *(undefined2 *)((int)pvVar2 + 0x3e) = 0x10;
      *(undefined4 *)((int)pvVar2 + 0x34) = 0x2d0;
      *(undefined4 *)((int)pvVar2 + 0x38) = 0x1e0;
      *(undefined4 *)((int)pvVar2 + 0x30) = 0x28;
      *(undefined4 *)((int)pvVar2 + 0x44) = 0xa8c00;
LAB_40b8cf68:
      *(undefined2 *)((int)pvVar2 + 0x3c) = 1;
    }
    else {
      FUN_40b99414((int)auStack_70,(undefined4 *)&DAT_40ba65c8);
      FUN_40b99438((int)auStack_70,&DAT_40ba66a8);
      FUN_40b99844((int)auStack_70,*(int *)(param_1 + 0x98));
      pvVar2 = FUN_40b9945c((int)auStack_70,*(int *)(param_2 + 0x40) + 0x88);
      memset(pvVar2,0,0x88);
      iVar1 = *(int *)(param_1 + 0xb4);
      iVar4 = *(int *)(iVar1 + 0x4c);
      *(int *)((int)pvVar2 + 0x4c) = iVar4;
      iVar1 = *(int *)(iVar1 + 0x50);
      *(undefined4 *)((int)pvVar2 + 0x48) = 0x28;
      *(int *)((int)pvVar2 + 0x50) = iVar1;
      *(undefined2 *)((int)pvVar2 + 0x54) = 1;
      *(undefined2 *)((int)pvVar2 + 0x56) = 0x10;
      iVar1 = iVar4 * iVar1 * 0x10;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 7;
      }
      *(int *)((int)pvVar2 + 0x5c) = iVar1 >> 3;
      *(undefined4 *)((int)pvVar2 + 0x74) = *(undefined4 *)(param_2 + 0x40);
      memcpy((void *)((int)pvVar2 + 0x84),(void *)(param_2 + 0x44),*(size_t *)(param_2 + 0x40));
    }
  }
  else {
    iVar1 = memcmp(_Buf1,&DAT_40ba47ac,0x10);
    if (iVar1 != 0) {
      puVar5 = &DAT_40ba48ec;
      uVar3 = 0x10;
      iVar1 = memcmp(_Buf1,&DAT_40ba48ec,0x10);
      if (iVar1 != 0) {
        FUN_40b83ba4(0x40ba3208,puVar5,uVar3,param_4);
        FUN_40b9962c((int)auStack_70);
        FUN_40b9bea4(local_28);
        return -0x7fffbffb;
      }
      FUN_40b99414((int)auStack_70,(undefined4 *)&DAT_40ba48ec);
      FUN_40b99438((int)auStack_70,&DAT_40ba438c);
      FUN_40b99844((int)auStack_70,*(int *)(param_1 + 0x98));
      pvVar2 = FUN_40b9945c((int)auStack_70,0x60);
      memset(pvVar2,0,0x60);
      iVar1 = *(int *)(param_1 + 0xb4);
      *(undefined4 *)((int)pvVar2 + 0x40) = 0x34363248;
      *(undefined4 *)((int)pvVar2 + 0x30) = 0x28;
      *(undefined4 *)((int)pvVar2 + 0x38) = *(undefined4 *)(iVar1 + 0x38);
      *(undefined4 *)((int)pvVar2 + 0x34) = *(undefined4 *)(iVar1 + 0x34);
      *(undefined4 *)((int)pvVar2 + 0x58) = 0x60;
      goto LAB_40b8cf68;
    }
    FUN_40b99414((int)auStack_70,(undefined4 *)&DAT_40ba47ac);
    FUN_40b99438((int)auStack_70,&DAT_40ba438c);
    FUN_40b99844((int)auStack_70,*(int *)(param_1 + 0x98));
    pvVar2 = FUN_40b9945c((int)auStack_70,0x60);
    memset(pvVar2,0,0x60);
    iVar1 = *(int *)(param_1 + 0xb4);
    *(undefined4 *)((int)pvVar2 + 0x40) = 0x5434504d;
    *(undefined4 *)((int)pvVar2 + 0x30) = 0x28;
    iVar4 = *(int *)(iVar1 + 0x38);
    *(int *)((int)pvVar2 + 0x38) = iVar4;
    iVar1 = *(int *)(iVar1 + 0x34);
    *(undefined2 *)((int)pvVar2 + 0x3c) = 1;
    *(int *)((int)pvVar2 + 0x34) = iVar1;
    *(undefined2 *)((int)pvVar2 + 0x3e) = 0x10;
    iVar1 = iVar4 * iVar1 * 0x10;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    *(int *)((int)pvVar2 + 0x44) = iVar1 >> 3;
    *(undefined4 *)((int)pvVar2 + 0x58) = 0x60;
  }
  iVar4 = FUN_40b8bcd8(param_1,0,L"Video",auStack_70);
  if (-1 < iVar4) {
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  FUN_40b9962c((int)auStack_70);
LAB_40b8cfac:
  FUN_40b9bea4(local_28);
  return iVar4;
}



/* 40b8d010 FUN_40b8d010 */

/* Boundary evidence: original MIPS .pdata 40b8d010..40b8d03f. Semantic name remains unreviewed. */

void FUN_40b8d010(void)

{
  int in_v0;
  
  FUN_40b9962c(in_v0 + -0x70);
  return;
}



/* 40b8d040 FUN_40b8d040 */

/* Boundary evidence: original MIPS .pdata 40b8d040..40b8d55b. Semantic name remains unreviewed. */

void FUN_40b8d040(int param_1,int *param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  void **ppvVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  void *local_210 [2];
  void *local_208;
  void *local_204;
  void *local_200;
  int local_1fc;
  uint local_1f8;
  undefined4 local_1f4;
  int *local_1f0;
  uint local_1ec;
  int local_1e8;
  uint local_1e0 [3];
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  uint local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  uint local_19c;
  uint local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_16c;
  uint local_164;
  undefined4 local_160;
  uint local_158 [3];
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  uint local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  uint local_114;
  uint local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e4;
  uint local_dc;
  undefined4 local_d8;
  undefined4 auStack_d0 [3];
  int local_c4;
  int local_bc;
  
  local_210[0] = (void *)0x0;
  local_16c = 1;
  local_1e0[0] = 0;
  local_1e0[1] = 0;
  uVar10 = 0;
  local_1d4 = 0;
  iVar9 = 0;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  local_1a0 = 0;
  local_19c = 0;
  local_198 = 0;
  local_194 = 0;
  local_190 = 0;
  local_18c = 0;
  local_188 = 0;
  local_184 = 0;
  local_180 = 0;
  local_17c = 0;
  local_178 = 0;
  local_174 = 0;
  local_160 = 0;
  local_e4 = 1;
  local_158[0] = 0;
  local_158[1] = 0;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_140 = 0;
  local_13c = 0;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0;
  local_100 = 0;
  local_fc = 0;
  local_f8 = 0;
  local_f4 = 0;
  local_f0 = 0;
  local_ec = 0;
  local_d8 = 0;
  local_1fc = param_4;
  local_1f0 = param_2;
  local_1ec = param_3;
  FUN_40b8694c(auStack_d0);
  local_1f4 = 0;
  do {
    uVar2 = 0;
    local_1f8 = uVar10 + 0x20000;
    local_1e8 = iVar9 + (uint)(local_1f8 < uVar10);
    if ((param_4 < local_1e8) ||
       ((((local_1e8 == param_4 && (param_3 <= local_1f8)) || (0 < local_1e8)) ||
        ((local_1e8 == 0 && (0x100000 < local_1f8)))))) break;
    iVar9 = (**(code **)(*param_2 + 8))(param_2);
    if (-1 < iVar9) {
      uVar4 = 0x20000;
      ppvVar3 = local_210;
      uVar2 = FUN_40b90bf4(param_1,ppvVar3,0x20000,param_2);
      if ((local_210[0] == (void *)0x0) && (uVar2 == 0)) {
        FUN_40b83ba4(0x40ba32d8,ppvVar3,uVar4,(va_list)param_2);
        *(undefined4 *)(param_1 + 4) = 1;
        return;
      }
    }
    local_204 = (void *)(uVar2 + (int)local_210[0]);
    local_208 = local_210[0];
    local_200 = local_210[0];
    while ((iVar9 = local_1e8, param_2 = local_1f0, uVar10 = local_1f8, local_208 < local_204 &&
           (0xbb < (uint)((int)local_204 - (int)local_208)))) {
      FUN_40b888cc((uint *)&local_208,auStack_d0);
      if (local_bc != 0x1fff) {
        uVar10 = 0;
        if (*(uint *)(param_1 + 0x1e924) != 0) {
          iVar9 = 0;
          piVar8 = (int *)(param_1 + 0x36c0);
          do {
            if ((((local_bc == *(int *)((piVar8[-0x11f] + iVar9 + 0xc82) * 4 + param_1)) &&
                 (FUN_40b87880((int)auStack_d0,local_1e0), 4 < local_164)) && (local_c4 != 0)) &&
               ((((local_1e0[0] & 0xe0) == 0xc0 || ((local_1e0[0] & 0xff) == 0xbd)) &&
                ((local_1bc & 2) != 0)))) {
              uVar7 = piVar8[0x68];
              uVar2 = piVar8[0x69];
              if (((((uVar7 & uVar2) == 0xffffffff) ||
                   (((int)local_19c <= (int)uVar2 && ((local_19c != uVar2 || (local_198 < uVar7)))))
                   ) && ((int)local_19c <= (int)uVar2)) &&
                 ((local_19c != uVar2 || (local_198 < uVar7)))) {
                piVar8[0x68] = local_198;
                piVar8[0x69] = local_19c;
              }
            }
            if ((((local_bc == *piVar8) && (FUN_40b87880((int)auStack_d0,local_158), 4 < local_dc))
                && (local_c4 != 0)) && (((local_158[0] & 0xf0) == 0xe0 && ((local_134 & 2) != 0))))
            {
              uVar7 = piVar8[0x68];
              uVar2 = piVar8[0x69];
              if ((((uVar7 & uVar2) == 0xffffffff) ||
                  (((int)local_114 <= (int)uVar2 && ((local_114 != uVar2 || (local_110 < uVar7))))))
                 && (((int)local_114 <= (int)uVar2 && ((local_114 != uVar2 || (local_110 < uVar7))))
                    )) {
                piVar8[0x68] = local_110;
                piVar8[0x69] = local_114;
              }
            }
            uVar10 = uVar10 + 1;
            iVar9 = iVar9 + 0x7ba;
            piVar8 = piVar8 + 0x7ba;
          } while (uVar10 < *(uint *)(param_1 + 0x1e924));
        }
      }
    }
    iVar5 = *(int *)(param_1 + 0x1e924);
    bVar1 = true;
    if (iVar5 != 0) {
      puVar6 = (uint *)(param_1 + 0x3860);
      do {
        if ((*puVar6 & puVar6[1]) != 0xffffffff) {
          bVar1 = false;
        }
        iVar5 = iVar5 + -1;
        puVar6 = puVar6 + 0x7ba;
      } while (iVar5 != 0);
    }
    operator_delete(local_210[0]);
    local_210[0] = (void *)0x0;
    param_4 = local_1fc;
    param_3 = local_1ec;
  } while (!bVar1);
  (**(code **)(*param_2 + 8))(param_2);
  return;
}



/* 40b8d55c FUN_40b8d55c */

/* Boundary evidence: original MIPS .pdata 40b8d55c..40b8dad3. Semantic name remains unreviewed. */

void FUN_40b8d55c(int param_1,int *param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  void **ppvVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  void *local_210 [2];
  void *local_208;
  void *local_204;
  void *local_200;
  int local_1fc;
  uint local_1f8;
  undefined4 local_1f4;
  int *local_1f0;
  uint local_1ec;
  int local_1e8;
  uint local_1e0 [3];
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  uint local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  uint local_19c;
  uint local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_16c;
  uint local_164;
  undefined4 local_160;
  uint local_158 [3];
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  uint local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  uint local_114;
  uint local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e4;
  uint local_dc;
  undefined4 local_d8;
  undefined4 auStack_d0 [3];
  int local_c4;
  int local_bc;
  
  local_210[0] = (void *)0x0;
  local_16c = 1;
  local_1e0[0] = 0;
  local_1e0[1] = 0;
  uVar9 = 0;
  local_1d4 = 0;
  iVar8 = 0;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  local_1a0 = 0;
  local_19c = 0;
  local_198 = 0;
  local_194 = 0;
  local_190 = 0;
  local_18c = 0;
  local_188 = 0;
  local_184 = 0;
  local_180 = 0;
  local_17c = 0;
  local_178 = 0;
  local_174 = 0;
  local_160 = 0;
  local_e4 = 1;
  local_158[0] = 0;
  local_158[1] = 0;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_140 = 0;
  local_13c = 0;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0;
  local_100 = 0;
  local_fc = 0;
  local_f8 = 0;
  local_f4 = 0;
  local_f0 = 0;
  local_ec = 0;
  local_d8 = 0;
  local_1fc = param_4;
  local_1f0 = param_2;
  local_1ec = param_3;
  FUN_40b8694c(auStack_d0);
  local_1f4 = 0;
  do {
    uVar2 = 0;
    local_1f8 = uVar9 + 0x8000;
    local_1e8 = iVar8 + (uint)(local_1f8 < uVar9);
    if ((param_4 < local_1e8) ||
       ((((local_1e8 == param_4 && (param_3 <= local_1f8)) || (0 < local_1e8)) ||
        ((local_1e8 == 0 && (0x100000 < local_1f8)))))) break;
    iVar8 = (**(code **)(*param_2 + 8))(param_2);
    if (-1 < iVar8) {
      uVar4 = 0x8000;
      ppvVar3 = local_210;
      uVar2 = FUN_40b90bf4(param_1,ppvVar3,0x8000,param_2);
      if ((local_210[0] == (void *)0x0) && (uVar2 == 0)) {
        FUN_40b83ba4(0x40ba3330,ppvVar3,uVar4,(va_list)param_2);
        *(undefined4 *)(param_1 + 4) = 1;
        return;
      }
    }
    local_204 = (void *)(uVar2 + (int)local_210[0]);
    local_208 = local_210[0];
    local_200 = local_210[0];
    while ((iVar8 = local_1e8, param_2 = local_1f0, uVar9 = local_1f8, local_208 < local_204 &&
           (0xbb < (uint)((int)local_204 - (int)local_208)))) {
      FUN_40b888cc((uint *)&local_208,auStack_d0);
      if (local_bc != 0x1fff) {
        uVar9 = 0;
        if (*(uint *)(param_1 + 0x1e924) != 0) {
          iVar8 = 0;
          piVar7 = (int *)(param_1 + 0x36c0);
          do {
            if ((((local_bc == *(int *)((piVar7[-0x11f] + iVar8 + 0xc82) * 4 + param_1)) &&
                 (FUN_40b87880((int)auStack_d0,local_1e0), 4 < local_164)) && (local_c4 != 0)) &&
               ((((local_1e0[0] & 0xe0) == 0xc0 || ((local_1e0[0] & 0xff) == 0xbd)) &&
                ((local_1bc & 2) != 0)))) {
              uVar2 = piVar7[0x6b];
              if (((piVar7[0x6a] & uVar2) == 0xffffffff) ||
                 (((int)uVar2 <= (int)local_19c &&
                  ((local_19c != uVar2 || ((uint)piVar7[0x6a] < local_198)))))) {
                if (((int)local_19c < piVar7[0x69]) ||
                   ((local_19c == piVar7[0x69] && (local_198 <= (uint)piVar7[0x68])))) {
                  piVar7[0x6a] = local_198 - 1;
                  piVar7[0x6b] = local_19c + 1 + (uint)(local_198 - 1 < local_198);
                }
                else {
                  piVar7[0x6a] = local_198;
                  piVar7[0x6b] = local_19c;
                }
              }
            }
            if ((((local_bc == *piVar7) && (FUN_40b87880((int)auStack_d0,local_158), 4 < local_dc))
                && (local_c4 != 0)) && (((local_158[0] & 0xf0) == 0xe0 && ((local_134 & 2) != 0))))
            {
              uVar2 = piVar7[0x6b];
              if (((piVar7[0x6a] & uVar2) == 0xffffffff) ||
                 (((int)uVar2 <= (int)local_114 &&
                  ((local_114 != uVar2 || ((uint)piVar7[0x6a] < local_110)))))) {
                if (((int)local_114 < piVar7[0x69]) ||
                   ((local_114 == piVar7[0x69] && (local_110 <= (uint)piVar7[0x68])))) {
                  piVar7[0x6a] = local_110 - 1;
                  piVar7[0x6b] = local_114 + 1 + (uint)(local_110 - 1 < local_110);
                }
                else {
                  piVar7[0x6a] = local_110;
                  piVar7[0x6b] = local_114;
                }
              }
            }
            uVar9 = uVar9 + 1;
            iVar8 = iVar8 + 0x7ba;
            piVar7 = piVar7 + 0x7ba;
          } while (uVar9 < *(uint *)(param_1 + 0x1e924));
        }
      }
    }
    iVar5 = *(int *)(param_1 + 0x1e924);
    bVar1 = true;
    if (iVar5 != 0) {
      puVar6 = (uint *)(param_1 + 0x3860);
      do {
        if (((*puVar6 & puVar6[1]) != 0xffffffff) && ((puVar6[2] & puVar6[3]) == 0xffffffff)) {
          bVar1 = false;
        }
        iVar5 = iVar5 + -1;
        puVar6 = puVar6 + 0x7ba;
      } while (iVar5 != 0);
    }
    operator_delete(local_210[0]);
    local_210[0] = (void *)0x0;
    param_4 = local_1fc;
    param_3 = local_1ec;
  } while (!bVar1);
  (**(code **)(*param_2 + 8))(param_2);
  return;
}



/* 40b8dad4 FUN_40b8dad4 */

/* WARNING: Removing unreachable block (ram,0x40b8e278) */
/* Boundary evidence: original MIPS .pdata 40b8dad4..40b8f2ef. Semantic name remains unreviewed. */

undefined4 FUN_40b8dad4(int param_1,uint *param_2,undefined4 param_3,uint *param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined3 extraout_var;
  void *pvVar14;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint *puVar15;
  void **ppvVar16;
  undefined4 uVar17;
  uint uVar18;
  int *piVar19;
  undefined4 *puVar20;
  int *piVar21;
  byte *pbVar22;
  uint *puVar23;
  uint uVar24;
  int iVar25;
  int *piVar26;
  int iVar27;
  undefined4 *puVar28;
  longlong lVar29;
  uint local_538;
  int local_534;
  undefined1 *local_530;
  int local_52c;
  int local_528;
  int local_524;
  int *local_520;
  void *local_51c;
  uint local_518;
  uint local_514;
  uint *local_510;
  uint local_508;
  int local_504;
  int *local_500;
  int local_4fc;
  int local_4f8;
  uint local_4f0;
  undefined4 local_4ec;
  void *local_4e8;
  void *local_4e4;
  void *local_4e0;
  int local_4dc;
  int local_4d8;
  int local_4d4;
  uint *local_4d0;
  undefined4 *local_4cc;
  int local_4c8;
  uint local_4c0;
  undefined4 local_4bc;
  undefined4 local_4b4;
  undefined4 local_4b0;
  undefined4 local_4ac;
  undefined4 local_4a8;
  undefined4 local_4a4;
  undefined4 local_4a0;
  uint local_49c;
  undefined4 local_498;
  undefined4 local_494;
  undefined4 local_490;
  undefined4 local_48c;
  undefined4 local_488;
  undefined4 local_484;
  undefined4 local_480;
  uint local_47c;
  uint local_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 local_464;
  undefined4 local_460;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_44c;
  byte *local_448;
  uint local_444;
  undefined4 local_440;
  uint local_438;
  undefined4 local_434;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined4 local_420;
  undefined4 local_41c;
  undefined4 local_418;
  uint local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  undefined4 local_3f8;
  uint local_3f4;
  uint local_3f0;
  undefined4 local_3ec;
  undefined4 local_3e8;
  undefined4 local_3e4;
  undefined4 local_3e0;
  undefined4 local_3dc;
  undefined4 local_3d8;
  undefined4 local_3d4;
  undefined4 local_3d0;
  undefined4 local_3cc;
  undefined4 local_3c4;
  undefined1 *local_3c0;
  uint local_3bc;
  undefined4 local_3b8;
  undefined4 auStack_3b0 [3];
  int local_3a4;
  int local_39c;
  int local_37c;
  int local_368;
  uint local_364;
  undefined4 local_360;
  int local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined1 auStack_2f8 [8];
  undefined4 local_2f0;
  undefined4 local_2ec;
  WCHAR aWStack_1b0 [64];
  WCHAR aWStack_130 [64];
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_40ba9854;
  uVar18 = 0;
  local_51c = (void *)0x0;
  local_44c = 1;
  local_4c0 = 0;
  local_4bc = 0;
  local_4b4 = 0;
  local_4b0 = 0;
  local_4ac = 0;
  local_4a8 = 0;
  local_4a4 = 0;
  local_4a0 = 0;
  local_49c = 0;
  local_498 = 0;
  local_494 = 0;
  local_490 = 0;
  local_48c = 0;
  local_488 = 0;
  local_484 = 0;
  local_480 = 0;
  local_47c = 0;
  local_478 = 0;
  local_474 = 0;
  local_470 = 0;
  local_46c = 0;
  local_468 = 0;
  local_464 = 0;
  local_460 = 0;
  local_45c = 0;
  local_458 = 0;
  local_454 = 0;
  local_440 = 0;
  local_3c4 = 1;
  local_438 = 0;
  local_434 = 0;
  local_42c = 0;
  local_428 = 0;
  local_424 = 0;
  local_420 = 0;
  local_41c = 0;
  local_418 = 0;
  local_414 = 0;
  local_410 = 0;
  local_40c = 0;
  local_408 = 0;
  local_404 = 0;
  local_400 = 0;
  local_3fc = 0;
  local_3f8 = 0;
  local_3f4 = 0;
  local_3f0 = 0;
  local_3ec = 0;
  local_3e8 = 0;
  local_3e4 = 0;
  local_3e0 = 0;
  local_3dc = 0;
  local_3d8 = 0;
  local_3d4 = 0;
  local_3d0 = 0;
  local_3cc = 0;
  local_3b8 = 0;
  local_534 = param_1;
  local_4d0 = param_2;
  FUN_40b8694c(auStack_3b0);
  iVar25 = 0;
  local_4d8 = 0;
  local_4c8 = 0;
  local_4f8 = 0;
  local_4dc = 0;
  bVar6 = false;
  local_528 = 0;
  bVar7 = false;
  *(undefined4 *)(param_1 + 0x1970) = 0x1fff;
  *(undefined4 *)(param_1 + 0x1978) = 0x1fff;
  *(undefined4 *)(param_1 + 0x1974) = 0x1fff;
  *(undefined4 *)(param_1 + 0x197c) = 0x1fff;
  local_4f0 = 0;
  local_4ec = 0;
  memset((void *)(param_1 + 0x28),0,0x48);
  memset((void *)(param_1 + 0x70),0,0x48);
  local_508 = 0;
  local_504 = 0;
  iVar10 = (**(code **)*param_2)(param_2,&local_508);
  if (-1 < iVar10) {
    param_4 = (uint *)0x0;
    iVar10 = (**(code **)(*param_2 + 8))(param_2);
    if (-1 < iVar10) {
      uVar17 = 0x100000;
      ppvVar16 = &local_51c;
      uVar18 = FUN_40b90bf4(param_1,ppvVar16,0x100000,(int *)param_2);
      param_4 = param_2;
      if ((local_51c == (void *)0x0) && (uVar18 == 0)) {
        FUN_40b83ba4(0x40ba33f0,ppvVar16,uVar17,(va_list)param_2);
        *(undefined4 *)(param_1 + 4) = 1;
        goto LAB_40b8f2b4;
      }
    }
  }
  lVar3 = CONCAT44(local_4c8,local_4d8);
  lVar29 = CONCAT44(local_4dc,local_4f8);
  piVar26 = &DAT_40ba66a8;
  local_4e4 = (void *)(uVar18 + (int)local_51c);
  puVar28 = &DAT_40ba438c;
  local_500 = &DAT_40ba66a8;
  local_4cc = &DAT_40ba438c;
  iVar10 = param_1;
  local_4e8 = local_51c;
  local_4e0 = local_51c;
  bVar5 = false;
  bVar8 = bVar7;
LAB_40b8dd78:
  local_4c8 = (int)((ulonglong)lVar3 >> 0x20);
  local_4d8 = (int)lVar3;
  local_4dc = (int)((ulonglong)lVar29 >> 0x20);
  local_4f8 = (int)lVar29;
  if ((local_4e8 < local_4e4) && (0xbb < (uint)((int)local_4e4 - (int)local_4e8))) {
    FUN_40b888cc((uint *)&local_4e8,auStack_3b0);
    iVar11 = local_534;
    lVar29 = CONCAT44(local_4dc,local_4f8);
    lVar3 = CONCAT44(local_4c8,local_4d8);
    if (local_39c != 0x1fff) {
      if (local_39c == 0) {
        piVar19 = (int *)(iVar10 + 0x104);
        FUN_40b87818((int)auStack_3b0,piVar19);
        if ((*(int *)(iVar10 + 0x192c) == 0) || (iVar11 = FUN_40b874a4((int)piVar19), iVar11 == 0))
        {
          lVar29 = CONCAT44(local_4dc,local_4f8);
          lVar3 = CONCAT44(local_4c8,local_4d8);
        }
        else {
          uVar18 = *(uint *)(iVar10 + 0x1958);
          if (0xf < uVar18) {
            uVar18 = 0xf;
          }
          puVar23 = (uint *)(iVar10 + 0x1e924);
          if (uVar18 != *puVar23) {
            bVar5 = false;
            iVar25 = 0;
            *puVar23 = uVar18;
            bVar6 = false;
            local_528 = 0;
            bVar7 = false;
          }
          uVar24 = 0;
          uVar18 = 0;
          if (*puVar23 != 0) {
            puVar20 = (undefined4 *)(local_534 + 0x1988);
            do {
              iVar10 = FUN_40b88188((int)piVar19,uVar18);
              if ((iVar10 != 0) && (iVar10 = FUN_40b8813c((int)piVar19,uVar18), iVar10 != 0x1fff)) {
                uVar17 = FUN_40b8813c((int)piVar19,uVar18);
                *puVar20 = uVar17;
                uVar17 = FUN_40b88188((int)piVar19,uVar18);
                uVar24 = uVar24 + 1;
                puVar20[1] = uVar17;
                puVar20 = puVar20 + 0x7ba;
              }
              uVar18 = uVar18 + 1;
              piVar26 = local_500;
              bVar5 = bVar6;
            } while (uVar18 < *puVar23);
          }
          lVar3 = CONCAT44(local_4c8,local_4d8);
          lVar29 = CONCAT44(local_4dc,local_4f8);
          *puVar23 = uVar24;
          iVar10 = local_534;
          bVar8 = bVar7;
        }
      }
      else {
        bVar8 = bVar7;
        if ((bVar5) || (*(int *)(iVar10 + 0x192c) == 0)) {
LAB_40b8e0d8:
          lVar4 = CONCAT44(local_4c8,local_4d8);
          lVar2 = CONCAT44(local_4dc,local_4f8);
          iVar11 = *(int *)(iVar10 + 0x1e920) * 0x1ee8 + iVar10;
          lVar29 = lVar2;
          lVar3 = lVar4;
          if ((local_39c == *(int *)(iVar11 + 0x1988)) && (*(int *)(iVar10 + 0x192c) != 0)) {
            if ((*(int *)(iVar10 + 0x1970) == 0x1fff) && (*(int *)(iVar11 + 0x31b8) != 0)) {
              *(int *)(iVar10 + 0x1970) = *(int *)(iVar11 + 0x1988);
              *(int *)(iVar10 + 0x196c) = iVar11 + 0x1990;
              if ((iVar11 + 0x1990 != 0) && (*(int *)(iVar11 + 0x31b8) != 0)) {
                *(undefined4 *)(iVar10 + 0x1978) =
                     *(undefined4 *)
                      ((*(int *)(iVar11 + 0x3244) + *(int *)(iVar10 + 0x1e920) * 0x7ba + 0xc82) * 4
                      + iVar10);
                *(undefined4 *)(iVar10 + 0x1974) = *(undefined4 *)(iVar11 + 0x36c0);
                *(undefined4 *)(iVar10 + 0x197c) = *(undefined4 *)(iVar11 + 0x31e4);
              }
            }
          }
          else {
            lVar29 = CONCAT44(local_4dc,local_4f8);
            lVar3 = CONCAT44(local_4c8,local_4d8);
            if (((local_39c == *(int *)(iVar10 + 0x197c)) &&
                ((lVar29 = CONCAT44(local_4dc,local_4f8), lVar3 = CONCAT44(local_4c8,local_4d8),
                 *(int *)(iVar10 + 0x196c) != 0 &&
                 (lVar29 = CONCAT44(local_4dc,local_4f8), lVar3 = CONCAT44(local_4c8,local_4d8),
                 *(int *)(*(int *)(iVar10 + 0x196c) + 0x1828) != 0)))) &&
               (lVar29 = CONCAT44(local_4dc,local_4f8), lVar3 = CONCAT44(local_4c8,local_4d8),
               local_37c != 0)) {
              lVar1 = (ulonglong)local_364 * 300 + CONCAT44(local_368 * 300,local_360);
              lVar29 = lVar1;
              lVar3 = CONCAT44(local_4c8,local_4d8);
              if (((local_4f8 != 0 || local_4dc != 0) &&
                  (lVar29 = CONCAT44(local_4dc,local_4f8), lVar3 = CONCAT44(local_4c8,local_4d8),
                  local_4d8 == 0 && local_4c8 == 0)) &&
                 (lVar29 = lVar2, lVar3 = lVar1, lVar1 < CONCAT44(local_4dc,local_4f8))) {
                lVar29 = lVar1;
                lVar3 = lVar4;
              }
            }
            if (((!bVar7) && (*(int *)(iVar10 + 0x196c) != 0)) &&
               (*(int *)(*(int *)(iVar10 + 0x196c) + 0x1828) != 0)) {
              bVar7 = true;
              local_510 = (uint *)0x0;
              if (*(int *)(iVar10 + 0x1e924) != 0) {
                iVar11 = iVar10 + 0x1990;
                piVar19 = (int *)(iVar10 + 0x3208);
                local_52c = 0;
                local_4fc = 0;
                do {
                  iVar25 = local_52c;
                  local_4c8 = (int)((ulonglong)lVar3 >> 0x20);
                  local_4d8 = (int)lVar3;
                  local_4dc = (int)((ulonglong)lVar29 >> 0x20);
                  local_4f8 = (int)lVar29;
                  iVar27 = 0;
                  local_524 = iVar11;
                  local_520 = piVar19;
                  iVar12 = FUN_40b8857c(iVar11);
                  piVar26 = piVar19;
                  if (0 < iVar12) {
                    puVar28 = (undefined4 *)(iVar11 + 0x18e0);
                    do {
                      if (((local_39c == *piVar19) &&
                          (FUN_40b87880((int)auStack_3b0,&local_4c0), uVar18 = local_444,
                          pbVar22 = local_448, 4 < local_444)) &&
                         ((local_3a4 != 0 &&
                          (((local_4c0 & 0xe0) == 0xc0 || ((local_4c0 & 0xff) == 0xbd)))))) {
                        if ((local_49c & 2) != 0) {
                          uVar24 = *(uint *)(iVar11 + 0x1ed4);
                          if (((*(uint *)(iVar11 + 0x1ed0) & uVar24) == 0xffffffff) ||
                             (((int)local_47c <= (int)uVar24 &&
                              ((local_47c != uVar24 || (local_478 < *(uint *)(iVar11 + 0x1ed0)))))))
                          {
                            *(uint *)(iVar11 + 0x1ed0) = local_478;
                            *(uint *)(iVar11 + 0x1ed4) = local_47c;
                          }
                        }
                        if (local_4c0 == 0xbd) {
                          if ((*local_448 & 0xf8) == 0x80) {
                            pbVar22 = local_448 + 4;
                            uVar18 = local_444 - 4;
                          }
                          uVar24 = 0;
                          iVar25 = local_52c;
                          if (uVar18 != 1) {
                            do {
                              if (((pbVar22[uVar24] == 0xb) && (pbVar22[uVar24 + 1] == 0x77)) ||
                                 ((pbVar22[uVar24] == 0x77 && (pbVar22[uVar24 + 1] == 0xb)))) {
                                pvVar14 = malloc(0x17);
                                uVar17 = 0x17;
                                memset(pvVar14,0,0x17);
                                FUN_40b851e4((char *)(pbVar22 + uVar24),(int)pvVar14,uVar17,
                                             (va_list)param_4);
                                puVar28[-10] = &DAT_40ba56d8;
                                puVar28[-9] = &DAT_40ba6628;
                                puVar28[2] = 0x5589f81;
                                puVar28[3] = 0x11cec356;
                                puVar28[4] = 0xaa0001bf;
                                puVar28[6] = 0x17;
                                *puVar28 = 0x800;
                                puVar28[1] = 0x40;
                                puVar28[5] = 0x5a595500;
                                puVar28[7] = pvVar14;
                                *(uint *)((local_52c + iVar27 + 0xda0) * 4 + iVar10) = local_4c0;
                                iVar11 = local_524;
                                iVar25 = local_52c;
                                break;
                              }
                              uVar24 = uVar24 + 1;
                            } while (uVar24 < uVar18 - 1);
                          }
                        }
                        else if (*(int *)(iVar10 + 0x1e950) == 0) {
                          puVar13 = malloc(0x12);
                          memset(puVar13,0,0x12);
                          uVar24 = 0;
                          if (uVar18 != 1) {
                            do {
                              if (((pbVar22[uVar24] == 0xff) && (*(int *)(puVar13 + 4) == 0)) &&
                                 (iVar25 = FUN_40b8543c(pbVar22 + uVar24,puVar13), iVar25 != 0)) {
                                puVar28[-10] = &DAT_40ba56d8;
                                puVar28[-9] = &DAT_40ba6618;
                                puVar28[2] = 0x5589f81;
                                puVar28[3] = 0x11cec356;
                                puVar28[4] = 0xaa0001bf;
                                puVar28[6] = 0x12;
                                puVar28[5] = 0x5a595500;
                                puVar28[7] = puVar13;
                                if (*(uint *)(puVar13 + 8) < 4000) {
                                  uVar17 = 0x200;
                                }
                                else {
                                  uVar17 = 0x400;
                                  if (7999 < *(uint *)(puVar13 + 8)) {
                                    uVar17 = 0x800;
                                  }
                                }
                                *puVar28 = uVar17;
                                puVar28[1] = 0x40;
                                *(uint *)((local_52c + iVar27 + 0xda0) * 4 + local_534) = local_4c0;
                                iVar11 = local_524;
                                iVar25 = local_52c;
                                iVar10 = local_534;
                                goto LAB_40b8e45c;
                              }
                              uVar24 = uVar24 + 1;
                            } while (uVar24 < uVar18 - 1);
                          }
                          free(puVar13);
                          iVar11 = local_524;
                          iVar25 = local_52c;
                          iVar10 = local_534;
                        }
                        else {
                          puVar13 = malloc(0x12);
                          memset(puVar13,0,0x12);
                          iVar11 = FUN_40b8569c((char *)local_448,local_444,puVar13);
                          if (iVar11 != 0) {
                            iVar11 = iVar27 * 0x48 + local_4fc + iVar10;
                            *(undefined **)(iVar11 + 0x3248) = &DAT_40ba56d8;
                            *(undefined **)(iVar11 + 0x324c) = &DAT_40ba472c;
                            *(undefined4 *)(iVar11 + 0x3278) = 0x5589f81;
                            *(undefined4 *)(iVar11 + 0x327c) = 0x11cec356;
                            *(undefined4 *)(iVar11 + 0x3280) = 0xaa0001bf;
                            *(undefined4 *)(iVar11 + 0x3288) = 0x12;
                            *(undefined4 *)(iVar11 + 0x3284) = 0x5a595500;
                            *(undefined1 **)(iVar11 + 0x328c) = puVar13;
                            uVar18 = *(uint *)(puVar13 + 8);
                            if (uVar18 < 4000) {
                              uVar17 = 0x200;
                            }
                            else if (uVar18 < 8000) {
                              uVar17 = 0x400;
                            }
                            else if (uVar18 < 0x124f9) {
                              uVar17 = 0x800;
                            }
                            else {
                              uVar17 = 0x4000;
                            }
                            *(undefined4 *)(iVar11 + 0x3270) = uVar17;
                            *(undefined4 *)(iVar11 + 0x3274) = 0x40;
                            *(uint *)((iVar25 + iVar27 + 0xda0) * 4 + iVar10) = local_4c0;
                            iVar11 = local_524;
                            piVar26 = local_520;
                            break;
                          }
                          free(puVar13);
                          iVar11 = local_524;
                        }
                      }
LAB_40b8e45c:
                      *(int *)(iVar11 + 0x1d2c) = *(int *)(iVar11 + 0x1cf0);
                      if ((*(int *)(iVar11 + 0x1cf0) == 0) ||
                         ((*(uint *)(iVar11 + 0x1ed0) & *(uint *)(iVar11 + 0x1ed4)) == 0xffffffff))
                      {
                        bVar7 = false;
                      }
                      iVar27 = iVar27 + 1;
                      piVar19 = piVar19 + 1;
                      puVar28 = puVar28 + 0x12;
                      iVar12 = FUN_40b8857c(iVar11);
                      piVar26 = local_520;
                    } while (iVar27 < iVar12);
                  }
                  lVar3 = CONCAT44(local_4c8,local_4d8);
                  lVar29 = CONCAT44(local_4dc,local_4f8);
                  local_4fc = local_4fc + 0x1ee8;
                  local_510 = (uint *)((int)local_510 + 1);
                  iVar11 = iVar11 + 0x1ee8;
                  local_52c = iVar25 + 0x7ba;
                  piVar19 = piVar26 + 0x7ba;
                  iVar25 = local_528;
                  piVar26 = local_500;
                  puVar28 = local_4cc;
                  local_524 = iVar11;
                  local_520 = piVar19;
                } while (local_510 < *(uint **)(iVar10 + 0x1e924));
              }
            }
            bVar5 = bVar6;
            bVar8 = bVar7;
            if (((iVar25 == 0) && (*(int *)(iVar10 + 0x196c) != 0)) &&
               (*(int *)(*(int *)(iVar10 + 0x196c) + 0x1828) != 0)) {
              iVar25 = 1;
              uVar18 = 0;
              local_528 = 1;
              if (*(uint *)(iVar10 + 0x1e924) != 0) {
                piVar19 = (int *)(iVar10 + 0x36c0);
                do {
                  local_4c8 = (int)((ulonglong)lVar3 >> 0x20);
                  local_4d8 = (int)lVar3;
                  local_4dc = (int)((ulonglong)lVar29 >> 0x20);
                  local_4f8 = (int)lVar29;
                  if ((local_39c == *piVar19) && (piVar19[0x14] == 0)) {
                    FUN_40b87880((int)auStack_3b0,&local_438);
                    local_538 = local_3bc;
                    local_530 = local_3c0;
                    lVar29 = CONCAT44(local_4dc,local_4f8);
                    lVar3 = CONCAT44(local_4c8,local_4d8);
                    if ((4 < local_3bc) &&
                       ((lVar29 = CONCAT44(local_4dc,local_4f8),
                        lVar3 = CONCAT44(local_4c8,local_4d8), local_3a4 != 0 &&
                        (lVar29 = CONCAT44(local_4dc,local_4f8),
                        lVar3 = CONCAT44(local_4c8,local_4d8), (local_438 & 0xf0) == 0xe0)))) {
                      if ((local_414 & 2) != 0) {
                        uVar24 = piVar19[0x69];
                        if (((piVar19[0x68] & uVar24) == 0xffffffff) ||
                           (((int)local_3f4 <= (int)uVar24 &&
                            ((local_3f4 != uVar24 || (local_3f0 < (uint)piVar19[0x68])))))) {
                          piVar19[0x68] = local_3f0;
                          piVar19[0x69] = local_3f4;
                        }
                      }
                      if (*(int *)(iVar10 + 0x1e954) != 0) {
                        pvVar14 = malloc(0x60);
                        memset(pvVar14,0,0x60);
                        iVar11 = uVar18 * 0x1ee8 + iVar10;
                        *(undefined **)(iVar11 + 0x36c8) = &DAT_40ba56c8;
                        *(undefined **)(iVar11 + 0x36cc) = &DAT_40ba47ac;
                        *(undefined4 *)(iVar11 + 0x36f8) = *puVar28;
                        *(undefined4 *)(iVar11 + 0x36fc) = puVar28[1];
                        *(undefined4 *)(iVar11 + 0x3700) = puVar28[2];
                        uVar17 = puVar28[3];
                        *(undefined4 *)(iVar11 + 0x3708) = 0x60;
                        *(undefined4 *)(iVar11 + 0x36f0) = 0x20000;
                        *(undefined4 *)(iVar11 + 0x36f4) = 0x20;
                        *(undefined4 *)(iVar11 + 0x3704) = uVar17;
                        *(void **)(iVar11 + 0x370c) = pvVar14;
                        *(uint *)(iVar11 + 0x3710) = local_438;
                        goto joined_r0x40b8ecd4;
                      }
                      if (*(int *)(iVar10 + 0x1e958) == 0) {
                        do {
                          bVar9 = FUN_40b85184((int *)&local_530,&local_538);
                          lVar29 = CONCAT44(local_4dc,local_4f8);
                          lVar3 = CONCAT44(local_4c8,local_4d8);
                          if (CONCAT31(extraout_var,bVar9) == 0) break;
                          if (CONCAT31(CONCAT21(CONCAT11(*local_530,local_530[1]),local_530[2]),
                                       local_530[3]) == 0x1b3) {
                            iVar11 = FUN_40b84f1c(local_530,0,(int)auStack_2f8,(va_list)param_4);
                            puVar13 = local_530;
                            if (iVar11 != 0) {
                              pvVar14 = malloc(0x88);
                              memset(pvVar14,0,0x88);
                              piVar19[2] = (int)&DAT_40ba56c8;
                              piVar19[3] = (int)&DAT_40ba65c8;
                              piVar19[0xe] = *piVar26;
                              piVar19[0xf] = piVar26[1];
                              piVar19[0x10] = piVar26[2];
                              iVar11 = piVar26[3];
                              piVar19[0x12] = 0x88;
                              piVar19[0xc] = 0x8000;
                              piVar19[0xd] = 0x40;
                              piVar19[0x11] = iVar11;
                              piVar19[0x13] = (int)pvVar14;
                              *(undefined4 *)((int)pvVar14 + 0x4c) = local_2f0;
                              *(undefined4 *)((int)pvVar14 + 0x50) = local_2ec;
                              memcpy(piVar19 + 0x16,auStack_2f8,0x148);
                              piVar19[0x14] = local_438;
                              lVar29 = CONCAT44(local_4dc,local_4f8);
                              lVar3 = CONCAT44(local_4c8,local_4d8);
                              break;
                            }
                          }
                          else {
                            puVar13 = local_530 + 1;
                            lVar29 = CONCAT44(local_4dc,local_4f8);
                            lVar3 = CONCAT44(local_4c8,local_4d8);
                            if (local_538 < 5) break;
                          }
                          local_530 = puVar13;
                          lVar3 = CONCAT44(local_4c8,local_4d8);
                          lVar29 = CONCAT44(local_4dc,local_4f8);
                        } while (4 < local_538);
                        goto LAB_40b8ead4;
                      }
                      pvVar14 = malloc(0x60);
                      memset(pvVar14,0,0x60);
                      iVar11 = uVar18 * 0x1ee8 + iVar10;
                      *(undefined **)(iVar11 + 0x36c8) = &DAT_40ba56c8;
                      *(undefined **)(iVar11 + 0x36cc) = &DAT_40ba48ec;
                      *(undefined4 *)(iVar11 + 0x36f8) = *puVar28;
                      *(undefined4 *)(iVar11 + 0x36fc) = puVar28[1];
                      *(undefined4 *)(iVar11 + 0x3700) = puVar28[2];
                      uVar17 = puVar28[3];
                      *(undefined4 *)(iVar11 + 0x3708) = 0x60;
                      *(undefined4 *)(iVar11 + 0x36f0) = 0x20000;
                      *(undefined4 *)(iVar11 + 0x36f4) = 0x20;
                      *(undefined4 *)(iVar11 + 0x3704) = uVar17;
                      *(void **)(iVar11 + 0x370c) = pvVar14;
                      *(uint *)(iVar11 + 0x3710) = local_438;
                      if ((local_538 < 5) ||
                         (bVar9 = FUN_40b85184((int *)&local_530,&local_538),
                         CONCAT31(extraout_var_00,bVar9) == 0)) {
LAB_40b8ec0c:
                        if (local_4d4 != 0) goto LAB_40b8dd3c;
                      }
                      else {
                        param_4 = &local_514;
                        FUN_40b8c1d4((int)(local_530 + 3),local_538 - 3,&local_4d4,(int *)param_4);
                        if (local_4d4 != 0) {
                          if (local_514 != 0) {
                            *(int *)((int)pvVar14 + 0x34) = local_4d4;
                            *(uint *)((int)pvVar14 + 0x38) = local_514;
                          }
                          goto LAB_40b8ec0c;
                        }
                      }
                      lVar3 = CONCAT44(local_4c8,local_4d8);
                      lVar29 = CONCAT44(local_4dc,local_4f8);
                      if (local_514 == 0) {
                        *(undefined4 *)((int)pvVar14 + 0x34) = 0x160;
                        uVar17 = 0x120;
                        goto LAB_40b8dd50;
                      }
                      break;
                    }
                  }
LAB_40b8ead4:
                  if ((piVar19[0x14] == 0) || ((piVar19[0x68] & piVar19[0x69]) == 0xffffffff)) {
                    iVar25 = 0;
                    local_528 = 0;
                  }
                  uVar18 = uVar18 + 1;
                  piVar19 = piVar19 + 0x7ba;
                } while (uVar18 < *(uint *)(iVar10 + 0x1e924));
              }
            }
          }
        }
        else {
          puVar23 = (uint *)(iVar10 + 0x1e924);
          bVar5 = true;
          bVar6 = true;
          local_520 = (int *)0x0;
          local_510 = puVar23;
          if (*puVar23 != 0) {
            piVar26 = (int *)(local_534 + 0x1990);
            do {
              piVar19 = local_520;
              if (((local_39c == piVar26[-2]) && (piVar26[0x60a] == 0)) &&
                 (FUN_40b8784c((int)auStack_3b0,piVar26), piVar26[0x60a] != 0)) {
                iVar25 = FUN_40b88854((int)piVar26);
                piVar26[0x61d] = iVar25;
                uVar18 = 0;
                if (iVar25 != 0) {
                  do {
                    uVar17 = FUN_40b887b4((int)piVar26,uVar18);
                    FUN_40b88804((int)piVar26,uVar18);
                    switch(uVar17) {
                    case 0xf:
                    case 0x11:
                      *(undefined4 *)(iVar11 + 0x1e950) = 1;
                      break;
                    case 0x10:
                      *(undefined4 *)(iVar11 + 0x1e954) = 1;
                      break;
                    case 0x1b:
                      *(undefined4 *)(iVar11 + 0x1e958) = 1;
                    }
                    uVar18 = uVar18 + 1;
                    piVar19 = local_520;
                    puVar23 = local_510;
                  } while (uVar18 < (uint)piVar26[0x61d]);
                }
                iVar25 = FUN_40b88450((int)piVar26);
                piVar26[0x74c] = iVar25;
                iVar10 = 0;
                iVar25 = FUN_40b8857c((int)piVar26);
                bVar5 = bVar6;
                if (0 < iVar25) {
                  piVar21 = piVar26 + 0x61e;
                  do {
                    iVar25 = FUN_40b886d0((int)piVar26,iVar10);
                    *piVar21 = iVar25;
                    iVar10 = iVar10 + 1;
                    piVar21 = piVar21 + 1;
                    iVar25 = FUN_40b8857c((int)piVar26);
                  } while (iVar10 < iVar25);
                }
              }
              if (piVar26[0x60a] == 0) {
                bVar5 = false;
                bVar6 = false;
              }
              local_520 = (int *)((int)piVar19 + 1);
              piVar26 = piVar26 + 0x7ba;
            } while (local_520 < (int *)*puVar23);
            iVar10 = local_534;
            iVar25 = local_528;
            piVar26 = local_500;
            puVar28 = local_4cc;
            if (!bVar5) goto LAB_40b8e0d8;
          }
          lVar3 = CONCAT44(local_4c8,local_4d8);
          lVar29 = CONCAT44(local_4dc,local_4f8);
          local_4e8 = local_4e0;
          iVar10 = local_534;
        }
      }
    }
    goto LAB_40b8dd78;
  }
  if (((!bVar8) || (iVar25 == 0)) && (0x3ff < (uint)((int)local_4e4 - (int)local_4e8)))
  goto LAB_40b8dd78;
  uVar18 = *(uint *)(iVar10 + 0x1e920);
  iVar11 = uVar18 * 0x1ee8 + iVar10;
  if ((*(int *)(iVar11 + 0x36bc) != 0) && (*(int *)(iVar11 + 0x3710) != 0)) {
    piVar26 = (int *)(iVar10 + 0x1e920);
    uVar17 = 0x48;
    memcpy((void *)(iVar10 + 0x28),
           (void *)(*(int *)(iVar10 + *piVar26 * 0x1ee8 + 0x3244) * 0x48 + iVar10 +
                    *piVar26 * 0x1ee8 + 0x3248),0x48);
    *(char *)(iVar10 + 0x1e93c) = (char)*(undefined4 *)(*piVar26 * 0x1ee8 + iVar10 + 0x36bc);
    FUN_40b8cb38(iVar10,*piVar26,uVar17,(va_list)param_4);
    uVar17 = 0x48;
    memcpy((void *)(iVar10 + 0x70),(void *)(*piVar26 * 0x1ee8 + iVar10 + 0x36c8),0x48);
    iVar25 = *piVar26 * 0x1ee8 + iVar10;
    *(char *)(iVar10 + 0x1e93d) = (char)*(undefined4 *)(iVar25 + 0x3710);
    FUN_40b8cc20(iVar10,iVar25 + 0x3718,uVar17,(va_list)param_4);
    puVar23 = local_4d0;
    FUN_40b8d040(iVar10,(int *)local_4d0,local_508,local_504);
    FUN_40b8d55c(iVar10,(int *)puVar23,local_508,local_504);
    puVar15 = (uint *)(iVar10 + 0x3860);
    iVar25 = 0xf;
    do {
      if ((*puVar15 & puVar15[1]) == 0xffffffff) {
        *puVar15 = 0;
        puVar15[1] = 0;
      }
      if ((puVar15[2] & puVar15[3]) == 0xffffffff) {
        puVar15[2] = 0;
        puVar15[3] = 0;
      }
      iVar25 = iVar25 + -1;
      puVar15 = puVar15 + 0x7ba;
    } while (iVar25 != 0);
    iVar25 = *piVar26 * 0x1ee8 + iVar10;
    lVar29 = __ll_div(*(undefined4 *)(iVar25 + 0x3860),*(undefined4 *)(iVar25 + 0x3864),0x5a,0);
    *(longlong *)(iVar10 + 0xd8) = lVar29 * 10000;
    operator_delete(local_51c);
    (**(code **)(*puVar23 + 8))(puVar23,*puVar23,0,0);
    *(uint *)(iVar10 + 200) = local_508;
    *(int *)(iVar10 + 0xcc) = local_504;
    iVar25 = *piVar26 * 0x1ee8 + iVar10;
    lVar29 = __ll_div(*(uint *)(iVar25 + 0x3868) - *(uint *)(iVar25 + 0x3860),
                      (*(int *)(iVar25 + 0x386c) - *(int *)(iVar25 + 0x3864)) -
                      (uint)(*(uint *)(iVar25 + 0x3868) < *(uint *)(iVar25 + 0x3860)),0x5a,0);
    local_4f0 = 0;
    *(longlong *)(iVar10 + 0xd0) = lVar29 * 10000;
    if (*(int *)(iVar10 + 0x1e924) != 0) {
      iVar10 = iVar10 + 0x1990;
      do {
        uVar18 = local_4f0;
        iVar11 = 0;
        iVar25 = FUN_40b8857c(iVar10);
        if (0 < iVar25) {
          puVar28 = (undefined4 *)(iVar10 + 0x18b8);
          do {
            wsprintfW(aWStack_130,L"NADA");
            wsprintfW(aWStack_b0,L"NADA");
            wsprintfW(aWStack_1b0,L"NADA");
            local_304 = puVar28[0xd];
            local_308 = puVar28[0xc];
            local_300 = puVar28[0xe];
            local_2fc = puVar28[0xf];
            puVar20 = (undefined4 *)puVar28[1];
            if ((undefined *)*puVar28 == &DAT_40ba56d8) {
              wsprintfW(aWStack_130,L"AUDIO");
            }
            if (puVar20 == &DAT_40ba6618) {
              wsprintfW(aWStack_1b0,L"MPEG2");
            }
            if (puVar20 == (undefined4 *)&DAT_40ba6628) {
              wsprintfW(aWStack_1b0,L"DOLBY_AC3");
            }
            if (puVar20 == (undefined4 *)&DAT_40ba472c) {
              wsprintfW(aWStack_1b0,L"AAC");
            }
            iVar25 = memcmp(&local_308,&DAT_40ba6298,0x10);
            if (iVar25 == 0) {
              wsprintfW(aWStack_b0,L"WAVEFORMATEX");
            }
            iVar11 = iVar11 + 1;
            puVar28 = puVar28 + 0x12;
            iVar25 = FUN_40b8857c(iVar10);
            uVar18 = local_4f0;
          } while (iVar11 < iVar25);
        }
        local_4f0 = uVar18 + 1;
        iVar10 = iVar10 + 0x1ee8;
      } while (local_4f0 < *(uint *)(local_534 + 0x1e924));
    }
    FUN_40b9bea4(local_30);
    return 0;
  }
  if (uVar18 < *(uint *)(iVar10 + 0x1e924)) {
    uVar18 = uVar18 + 1;
    local_4e8 = local_4e0;
    *(uint *)(iVar10 + 0x1e920) = uVar18;
    iVar11 = uVar18 * 0x1ee8 + iVar10;
    *(undefined4 *)(iVar10 + 0x1970) = *(undefined4 *)(iVar11 + 0x1988);
    *(int *)(iVar10 + 0x196c) = iVar11 + 0x1990;
    if ((iVar11 + 0x1990 != 0) && (*(int *)(iVar11 + 0x31b8) != 0)) {
      *(undefined4 *)(iVar10 + 0x1978) =
           *(undefined4 *)((uVar18 * 0x7ba + *(int *)(iVar11 + 0x3244) + 0xc82) * 4 + iVar10);
      *(undefined4 *)(iVar10 + 0x1974) = *(undefined4 *)(iVar11 + 0x36c0);
      *(undefined4 *)(iVar10 + 0x197c) = *(undefined4 *)(iVar11 + 0x31e4);
    }
    goto LAB_40b8dd78;
  }
  operator_delete(local_51c);
  (**(code **)(*local_4d0 + 8))(local_4d0,*local_4d0,0,0);
LAB_40b8f2b4:
  FUN_40b9bea4(local_30);
  return 0x80004005;
joined_r0x40b8ecd4:
  if ((local_538 < 5) ||
     (bVar9 = FUN_40b85184((int *)&local_530,&local_538), CONCAT31(extraout_var_01,bVar9) == 0))
  goto LAB_40b8ed5c;
  if (((uint)CONCAT12(*local_530,CONCAT11(local_530[1],local_530[2])) << 4 |
      (uint)((byte)local_530[3] >> 4)) != 0x12) {
    local_538 = local_538 - 4;
    local_530 = local_530 + 4;
    goto joined_r0x40b8ecd4;
  }
  param_4 = &local_518;
  FUN_40b8c360((int)(local_530 + 4),local_538 - 4,&local_4f0,param_4);
  if (local_4f0 == 0) goto LAB_40b8ed80;
  if (local_518 != 0) {
    *(uint *)((int)pvVar14 + 0x34) = local_4f0;
    *(uint *)((int)pvVar14 + 0x38) = local_518;
  }
LAB_40b8ed5c:
  if (local_4f0 == 0) {
LAB_40b8ed80:
    if (local_518 == 0) {
      *(undefined4 *)((int)pvVar14 + 0x34) = 0x280;
      uVar17 = 0x1e0;
LAB_40b8dd50:
      lVar3 = CONCAT44(local_4c8,local_4d8);
      lVar29 = CONCAT44(local_4dc,local_4f8);
      *(undefined4 *)((int)pvVar14 + 0x38) = uVar17;
      goto LAB_40b8dd78;
    }
  }
LAB_40b8dd3c:
  lVar29 = CONCAT44(local_4dc,local_4f8);
  lVar3 = CONCAT44(local_4c8,local_4d8);
  goto LAB_40b8dd78;
}



/* 40b8f2f0 FUN_40b8f2f0 */

/* Boundary evidence: original MIPS .pdata 40b8f2f0..40b8f34f. Semantic name remains unreviewed. */

void FUN_40b8f2f0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40ba1ecc;
  FUN_40b888fc((int)param_1);
  FUN_40b8885c(param_1 + 0x617);
  *param_1 = &PTR_LAB_40ba1d08;
  return;
}



/* 40b8f350 FUN_40b8f350 */

/* Boundary evidence: original MIPS .pdata 40b8f350..40b8f37f. Semantic name remains unreviewed. */

void FUN_40b8f350(void)

{
  undefined4 *in_v0;
  
  FUN_40b868cc((undefined4 *)*in_v0);
  return;
}



/* 40b8f380 FUN_40b8f380 */

/* Boundary evidence: original MIPS .pdata 40b8f380..40b8f3b3. Semantic name remains unreviewed. */

void FUN_40b8f380(void)

{
  int *in_v0;
  
  FUN_40b8899c((int *)(*in_v0 + 0x185c));
  return;
}



/* 40b8f3b4 FUN_40b8f3b4 */

/* Boundary evidence: original MIPS .pdata 40b8f3b4..40b8f413. Semantic name remains unreviewed. */

void FUN_40b8f3b4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40ba1ed4;
  FUN_40b8894c((int)param_1);
  FUN_40b8885c(param_1 + 0x61a);
  *param_1 = &PTR_LAB_40ba1d08;
  return;
}



/* 40b8f414 FUN_40b8f414 */

/* Boundary evidence: original MIPS .pdata 40b8f414..40b8f443. Semantic name remains unreviewed. */

void FUN_40b8f414(void)

{
  undefined4 *in_v0;
  
  FUN_40b868cc((undefined4 *)*in_v0);
  return;
}



/* 40b8f444 FUN_40b8f444 */

/* Boundary evidence: original MIPS .pdata 40b8f444..40b8f477. Semantic name remains unreviewed. */

void FUN_40b8f444(void)

{
  int *in_v0;
  
  FUN_40b889b8((int *)(*in_v0 + 0x1868));
  return;
}



/* 40b8f478 FUN_40b8f478 */

/* Boundary evidence: original MIPS .pdata 40b8f478..40b8f4a3. Semantic name remains unreviewed. */

int FUN_40b8f478(int param_1)

{
  FUN_40b88a24((undefined4 *)(param_1 + 8));
  return param_1;
}



/* 40b8f4a4 FUN_40b8f4a4 */

/* Boundary evidence: original MIPS .pdata 40b8f4a4..40b8f4bf. Semantic name remains unreviewed. */

void FUN_40b8f4a4(int param_1)

{
  FUN_40b8f3b4((undefined4 *)(param_1 + 8));
  return;
}



/* 40b8f4c0 FUN_40b8f4c0 */

/* Boundary evidence: original MIPS .pdata 40b8f4c0..40b8f5db. Semantic name remains unreviewed. */

void FUN_40b8f4c0(undefined4 *param_1)

{
  int *piVar1;
  HANDLE hObject;
  
  *param_1 = &PTR_FUN_40ba34a8;
  piVar1 = (int *)param_1[0x7a4d];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
    param_1[0x7a4d] = 0;
  }
  piVar1 = (int *)param_1[0x7a4e];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
    param_1[0x7a4e] = 0;
  }
  hObject = (HANDLE)param_1[0x7a4c];
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
    param_1[0x7a4c] = 0;
  }
  _eh_vector_destructor_iterator_(param_1 + 0x662,0x1ee8,0xf,FUN_40b8f4a4);
  FUN_40b8f2f0(param_1 + 0x41);
  _eh_vector_destructor_iterator_(param_1 + 3,8,2,FUN_40b88b28);
  *param_1 = &PTR_FUN_40ba2b00;
  return;
}



/* 40b8f5dc FUN_40b8f5dc */

/* Boundary evidence: original MIPS .pdata 40b8f5dc..40b8f60b. Semantic name remains unreviewed. */

void FUN_40b8f5dc(void)

{
  undefined4 *in_v0;
  
  FUN_40b88a80((undefined4 *)*in_v0);
  return;
}



/* 40b8f60c FUN_40b8f60c */

/* Boundary evidence: original MIPS .pdata 40b8f60c..40b8f64f. Semantic name remains unreviewed. */

void FUN_40b8f60c(void)

{
  int *in_v0;
  
  _eh_vector_destructor_iterator_((void *)(*in_v0 + 0xc),8,2,FUN_40b88b28);
  return;
}



/* 40b8f650 FUN_40b8f650 */

/* Boundary evidence: original MIPS .pdata 40b8f650..40b8f683. Semantic name remains unreviewed. */

void FUN_40b8f650(void)

{
  int *in_v0;
  
  FUN_40b8f2f0((undefined4 *)(*in_v0 + 0x104));
  return;
}



/* 40b8f684 FUN_40b8f684 */

/* Boundary evidence: original MIPS .pdata 40b8f684..40b8f6c7. Semantic name remains unreviewed. */

void FUN_40b8f684(void)

{
  int *in_v0;
  
  _eh_vector_destructor_iterator_((void *)(*in_v0 + 0x1988),0x1ee8,0xf,FUN_40b8f4a4);
  return;
}



/* 40b8f6d8 FUN_40b8f6d8 */

/* Boundary evidence: original MIPS .pdata 40b8f6d8..40b8fb03. Semantic name remains unreviewed. */

undefined4 * FUN_40b8f6d8(undefined4 *param_1,undefined4 param_2)

{
  HANDLE pvVar1;
  code *pcVar2;
  int *piVar3;
  int *piVar4;
  int *_Dst;
  int iVar5;
  int iVar6;
  
  param_1[1] = 0;
  param_1[2] = param_2;
  *param_1 = &PTR_FUN_40ba34a8;
  _eh_vector_constructor_iterator_
            (param_1 + 3,8,2,(_func_void_void_ptr *)&LAB_40b88b18,FUN_40b88b28);
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x34] = 0xffffffff;
  param_1[0x35] = 0xffffffff;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  FUN_40b889d4(param_1 + 0x41);
  param_1[0x65b] = 0;
  param_1[0x660] = 0;
  _eh_vector_constructor_iterator_(param_1 + 0x662,0x1ee8,0xf,FUN_40b8f478,FUN_40b8f4a4);
  param_1[0x7a48] = 0;
  param_1[0x7a49] = 0;
  param_1[0x7a4a] = 0;
  param_1[0x7a4b] = 0;
  *(undefined1 *)(param_1 + 0x7a4f) = 0;
  param_1[0x7a50] = 0;
  param_1[0x7a51] = 0;
  *(undefined1 *)((int)param_1 + 0x1e93d) = 0;
  param_1[0x7a52] = 1;
  param_1[0x7a53] = 1;
  param_1[0x7a74] = 1;
  param_1[0x7a57] = 0;
  param_1[0x7a58] = 0;
  param_1[0x7a5a] = 0;
  param_1[0x7a5b] = 0;
  param_1[0x7a5c] = 0;
  param_1[0x7a5d] = 0;
  param_1[0x7a5e] = 0;
  param_1[0x7a5f] = 0;
  param_1[0x7a60] = 0;
  param_1[0x7a61] = 0;
  param_1[0x7a62] = 0;
  param_1[0x7a63] = 0;
  param_1[0x7a64] = 0;
  param_1[0x7a65] = 0;
  param_1[0x7a66] = 0;
  param_1[0x7a67] = 0;
  param_1[0x7a68] = 0;
  param_1[0x7a69] = 0;
  param_1[0x7a6a] = 0;
  param_1[0x7a6b] = 0;
  param_1[0x7a6c] = 0;
  param_1[0x7a6d] = 0;
  param_1[0x7a6e] = 0;
  param_1[0x7a6f] = 0;
  param_1[0x7a70] = 0;
  param_1[0x7a71] = 0;
  param_1[0x7a72] = 0;
  param_1[0x7a77] = 0;
  param_1[0x7a95] = 1;
  param_1[0x7a78] = 0;
  param_1[0x7a79] = 0;
  param_1[0x7a7b] = 0;
  param_1[0x7a7c] = 0;
  param_1[0x7a7d] = 0;
  param_1[0x7a7e] = 0;
  param_1[0x7a7f] = 0;
  param_1[0x7a80] = 0;
  param_1[0x7a81] = 0;
  param_1[0x7a82] = 0;
  param_1[0x7a83] = 0;
  param_1[0x7a84] = 0;
  param_1[0x7a85] = 0;
  param_1[0x7a86] = 0;
  param_1[0x7a87] = 0;
  param_1[0x7a88] = 0;
  param_1[0x7a89] = 0;
  param_1[0x7a8a] = 0;
  param_1[0x7a8b] = 0;
  param_1[0x7a8c] = 0;
  param_1[0x7a8d] = 0;
  param_1[0x7a8e] = 0;
  param_1[0x7a8f] = 0;
  param_1[0x7a90] = 0;
  param_1[0x7a91] = 0;
  param_1[0x7a92] = 0;
  param_1[0x7a93] = 0;
  param_1[0x7a98] = 0;
  FUN_40b8694c(param_1 + 0x7a99);
  param_1[0x7ac3] = 0xffffffff;
  param_1[0x7ac4] = 0xffffffff;
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
  param_1[0x7a4c] = pvVar1;
  piVar3 = param_1 + 0x664;
  iVar6 = 0xf;
  do {
    pcVar2 = *(code **)(*piVar3 + 4);
    piVar3[-2] = 0x1fff;
    piVar3[-1] = 0;
    (*pcVar2)(piVar3);
    piVar4 = piVar3 + 0x73c;
    _Dst = piVar3 + 0x62e;
    iVar5 = 0xf;
    piVar3[0x61d] = 0;
    do {
      piVar4[-0x11e] = 0x1fff;
      *piVar4 = 0;
      memset(_Dst,0,0x48);
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + -1;
      _Dst = _Dst + 0x12;
    } while (iVar5 != 0);
    piVar3[0x62d] = 0;
    piVar3[0x74b] = 0;
    piVar3[0x74c] = 0x1fff;
    memset(piVar3 + 0x74e,0,0x48);
    piVar3[0x760] = 0;
    memset(piVar3 + 0x762,0,0x148);
    piVar3[0x7b4] = -1;
    piVar3[0x7b5] = -1;
    piVar3[0x7b6] = -1;
    piVar3[0x7b7] = -1;
    iVar6 = iVar6 + -1;
    piVar3 = piVar3 + 0x7ba;
  } while (iVar6 != 0);
  param_1[0x7a4d] = 0;
  param_1[0x7a4e] = 0;
  param_1[0x7a54] = 0;
  param_1[0x7a55] = 0;
  param_1[0x7a56] = 0;
  return param_1;
}



/* 40b8fb04 FUN_40b8fb04 */

/* Boundary evidence: original MIPS .pdata 40b8fb04..40b8fb33. Semantic name remains unreviewed. */

void FUN_40b8fb04(void)

{
  undefined4 *in_v0;
  
  FUN_40b88a80((undefined4 *)*in_v0);
  return;
}



/* 40b8fb34 FUN_40b8fb34 */

/* Boundary evidence: original MIPS .pdata 40b8fb34..40b8fb77. Semantic name remains unreviewed. */

void FUN_40b8fb34(void)

{
  int *in_v0;
  
  _eh_vector_destructor_iterator_((void *)(*in_v0 + 0xc),8,2,FUN_40b88b28);
  return;
}



/* 40b8fb78 FUN_40b8fb78 */

/* Boundary evidence: original MIPS .pdata 40b8fb78..40b8fbab. Semantic name remains unreviewed. */

void FUN_40b8fb78(void)

{
  int *in_v0;
  
  FUN_40b8f2f0((undefined4 *)(*in_v0 + 0x104));
  return;
}



/* 40b8fbac FUN_40b8fbac */

/* Boundary evidence: original MIPS .pdata 40b8fbac..40b8fbef. Semantic name remains unreviewed. */

void FUN_40b8fbac(void)

{
  int *in_v0;
  
  _eh_vector_destructor_iterator_((void *)(*in_v0 + 0x1988),0x1ee8,0xf,FUN_40b8f4a4);
  return;
}



/* 40b8fbf0 FUN_40b8fbf0 */

/* Boundary evidence: original MIPS .pdata 40b8fbf0..40b8fc3b. Semantic name remains unreviewed. */

undefined4 * FUN_40b8fbf0(undefined4 *param_1,uint param_2)

{
  FUN_40b8f4c0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b8fc3c FUN_40b8fc3c */

/* Boundary evidence: original MIPS .pdata 40b8fc3c..40b8fc57. Semantic name remains unreviewed. */

void FUN_40b8fc3c(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40b8fc68 FUN_40b8fc68 */

/* Boundary evidence: original MIPS .pdata 40b8fc68..40b8fc93. Semantic name remains unreviewed. */

void FUN_40b8fc68(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0x98) + 0x18))();
  return;
}



/* 40b8fc94 FUN_40b8fc94 */

/* Boundary evidence: original MIPS .pdata 40b8fc94..40b8fcbf. Semantic name remains unreviewed. */

void FUN_40b8fc94(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 0x38))();
  return;
}



/* 40b8fcc0 FUN_40b8fcc0 */

/* Boundary evidence: original MIPS .pdata 40b8fcc0..40b8fceb. Semantic name remains unreviewed. */

void FUN_40b8fcc0(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 0x3c))();
  return;
}



/* 40b8fcec FUN_40b8fcec */

/* Boundary evidence: original MIPS .pdata 40b8fcec..40b8fd17. Semantic name remains unreviewed. */

void FUN_40b8fcec(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 0x40))();
  return;
}



/* 40b8fd18 FUN_40b8fd18 */

/* Boundary evidence: original MIPS .pdata 40b8fd18..40b8fd33. Semantic name remains unreviewed. */

void FUN_40b8fd18(int param_1)

{
  FUN_40b94698(param_1);
  return;
}



/* 40b8fd34 FUN_40b8fd34 */

/* Boundary evidence: original MIPS .pdata 40b8fd34..40b8fd4f. Semantic name remains unreviewed. */

void FUN_40b8fd34(undefined4 *param_1)

{
  FUN_40b9a0fc(param_1);
  return;
}



/* 40b8fd50 FUN_40b8fd50 */

/* Boundary evidence: original MIPS .pdata 40b8fd50..40b8fd6b. Semantic name remains unreviewed. */

void FUN_40b8fd50(int param_1)

{
  FUN_40b987b0(param_1);
  return;
}



/* 40b8fd6c FUN_40b8fd6c */

/* Boundary evidence: original MIPS .pdata 40b8fd6c..40b8fd87. Semantic name remains unreviewed. */

void FUN_40b8fd6c(int *param_1)

{
  FUN_40b987ec(param_1);
  return;
}



/* 40b8fd88 FUN_40b8fd88 */

/* Boundary evidence: original MIPS .pdata 40b8fd88..40b8fda3. Semantic name remains unreviewed. */

void FUN_40b8fd88(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40b946dc(param_1,param_2,param_3);
  return;
}



/* 40b8fda4 FUN_40b8fda4 */

/* Boundary evidence: original MIPS .pdata 40b8fda4..40b8fe7f. Semantic name remains unreviewed. */

undefined4 FUN_40b8fda4(int param_1,int *param_2,int param_3)

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
  
  local_20 = DAT_40ba9854;
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))((int *)(param_1 + 0xc),&local_68);
  local_84 = param_3 + 4;
  piVar3 = *(int **)(*(int *)(param_1 + 0x70) + 0xa8);
  iVar2 = *piVar3;
  local_80 = param_3;
  memcpy(auStack_c0,auStack_5c,0x3c);
  (**(code **)(iVar2 + 8))(piVar3,local_68,local_64,local_60);
  FUN_40b995c8((int)&local_68);
  *(undefined4 *)(param_3 + 8) = 1;
  *(undefined4 *)(param_3 + 0xc) = 0;
  uVar1 = (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_78);
  FUN_40b9bea4(local_20);
  return uVar1;
}



/* 40b8fe80 FUN_40b8fe80 */

/* Boundary evidence: original MIPS .pdata 40b8fe80..40b8ff73. Semantic name remains unreviewed. */

undefined4 FUN_40b8fe80(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_40b83ba4(0x40ba3704,*param_2,param_3,param_4);
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
  uVar2 = FUN_40b9abf0(*(LPCRITICAL_SECTION *)(param_1 + 0xac),param_2);
  return uVar2;
}



/* 40b8ff74 FUN_40b8ff74 */

/* Boundary evidence: original MIPS .pdata 40b8ff74..40b8ff8f. Semantic name remains unreviewed. */

void FUN_40b8ff74(int param_1,int *param_2)

{
  FUN_40b94a74(param_1,param_2);
  return;
}



/* 40b8ff90 FUN_40b8ff90 */

/* Boundary evidence: original MIPS .pdata 40b8ff90..40b8ffab. Semantic name remains unreviewed. */

void FUN_40b8ff90(int *param_1)

{
  FUN_40b94a4c(param_1);
  return;
}



/* 40b8ffac FUN_40b8ffac */

/* Boundary evidence: original MIPS .pdata 40b8ffac..40b90027. Semantic name remains unreviewed. */

void FUN_40b8ffac(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x98) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x18))();
    if (iVar1 < 0) {
      return;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 8))();
    if (iVar1 != 0) {
      FUN_40b83ba4(0x40ba3740,iVar1,param_3,param_4);
    }
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  FUN_40b94adc(param_1);
  return;
}



/* 40b90028 FUN_40b90028 */

/* Boundary evidence: original MIPS .pdata 40b90028..40b90043. Semantic name remains unreviewed. */

void FUN_40b90028(undefined4 *param_1)

{
  FUN_40b9a0fc(param_1);
  return;
}



/* 40b90044 FUN_40b90044 */

/* Boundary evidence: original MIPS .pdata 40b90044..40b901a7. Semantic name remains unreviewed. */

int FUN_40b90044(int *param_1)

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



/* 40b901a8 FUN_40b901a8 */

/* Boundary evidence: original MIPS .pdata 40b901a8..40b901d7. Semantic name remains unreviewed. */

void FUN_40b901a8(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40b901d8 FUN_40b901d8 */

/* Boundary evidence: original MIPS .pdata 40b901d8..40b901ff. Semantic name remains unreviewed. */

void FUN_40b901d8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xa8) + 0x28))();
  return;
}



/* 40b90200 FUN_40b90200 */

/* Boundary evidence: original MIPS .pdata 40b90200..40b9024b. Semantic name remains unreviewed. */

undefined4 FUN_40b90200(undefined4 param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_2 != (void *)0x0) {
    iVar2 = memcmp(param_2,&DAT_40ba6888,0x10);
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 40b9024c FUN_40b9024c */

undefined4 FUN_40b9024c(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0xac) = *param_2;
  *(undefined4 *)(param_1 + 0xb0) = param_2[1];
  *(undefined4 *)(param_1 + 0xb4) = param_2[2];
  *(undefined4 *)(param_1 + 0xb8) = param_2[3];
  return 0;
}



/* 40b90274 FUN_40b90274 */

/* Boundary evidence: original MIPS .pdata 40b90274..40b902ff. Semantic name remains unreviewed. */

undefined4 FUN_40b90274(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc4);
  EnterCriticalSection(lpCriticalSection);
  if ((*(int **)(param_1 + 0xa8) == (int *)0x0) ||
     (iVar1 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x2c))(), iVar1 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
    uVar2 = 0;
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    uVar2 = 1;
  }
  return uVar2;
}



/* 40b90300 FUN_40b90300 */

/* Boundary evidence: original MIPS .pdata 40b90300..40b9032f. Semantic name remains unreviewed. */

void FUN_40b90300(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b90330 FUN_40b90330 */

/* Boundary evidence: original MIPS .pdata 40b90330..40b903e7. Semantic name remains unreviewed. */

undefined4 * FUN_40b90330(undefined4 *param_1,int param_2,undefined4 param_3)

{
  FUN_40b981c8(param_1,0,param_2,param_2 + 0x6c,param_3,L"Input");
  *param_1 = &PTR_FUN_40ba38d0;
  param_1[3] = &PTR_FUN_40ba3888;
  param_1[4] = &PTR_LAB_40ba3874;
  param_1[0x26] = &PTR_LAB_40ba3850;
  param_1[0x36] = 0;
  FUN_40b83cc8(param_1 + 0x38);
  param_1[0x38] = &PTR_FUN_40ba36e8;
  param_1[0x54] = param_1;
  return param_1;
}



/* 40b903e8 FUN_40b903e8 */

/* Boundary evidence: original MIPS .pdata 40b903e8..40b90417. Semantic name remains unreviewed. */

void FUN_40b903e8(void)

{
  int *in_v0;
  
  FUN_40b94f10(*in_v0);
  return;
}



/* 40b90418 FUN_40b90418 */

/* Boundary evidence: original MIPS .pdata 40b90418..40b9043f. Semantic name remains unreviewed. */

void FUN_40b90418(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b90440 FUN_40b90440 */

/* Boundary evidence: original MIPS .pdata 40b90440..40b90467. Semantic name remains unreviewed. */

void FUN_40b90440(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b90468 FUN_40b90468 */

/* Boundary evidence: original MIPS .pdata 40b90468..40b9048f. Semantic name remains unreviewed. */

void FUN_40b90468(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b90490 FUN_40b90490 */

/* Boundary evidence: original MIPS .pdata 40b90490..40b904ff. Semantic name remains unreviewed. */

undefined4 FUN_40b90490(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ba5118,0x10);
  if (iVar1 == 0) {
    uVar2 = 0x80004002;
  }
  else {
    uVar2 = FUN_40b94f58(param_1,param_2,param_3);
  }
  return uVar2;
}



/* 40b90500 FUN_40b90500 */

/* Boundary evidence: original MIPS .pdata 40b90500..40b9054b. Semantic name remains unreviewed. */

void FUN_40b90500(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  FUN_40b84c5c((undefined4 *)(param_1 + 0xe0),param_2,param_3,param_4);
  FUN_40b94f10(param_1);
  return;
}



/* 40b9054c FUN_40b9054c */

/* Boundary evidence: original MIPS .pdata 40b9054c..40b9057b. Semantic name remains unreviewed. */

void FUN_40b9054c(void)

{
  int *in_v0;
  
  FUN_40b94f10(*in_v0);
  return;
}



/* 40b90584 FUN_40b90584 */

/* Boundary evidence: original MIPS .pdata 40b90584..40b90667. Semantic name remains unreviewed. */

int FUN_40b90584(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int local_18;
  undefined4 *local_14;
  
  local_18 = FUN_40b947fc(param_1,param_2);
  if (-1 < local_18) {
    local_14 = operator_new(0x6c);
    if (local_14 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40b831e8(local_14,(undefined4 *)0x0,&local_18);
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
      local_18 = FUN_40b84ce4(param_1 + 0xe0,param_2,*(undefined4 *)(param_1 + 0x9c),param_4);
    }
  }
  return local_18;
}



/* 40b90668 FUN_40b90668 */

/* Boundary evidence: original MIPS .pdata 40b90668..40b90697. Semantic name remains unreviewed. */

void FUN_40b90668(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x14));
  return;
}



/* 40b90698 FUN_40b90698 */

/* Boundary evidence: original MIPS .pdata 40b90698..40b906fb. Semantic name remains unreviewed. */

void FUN_40b90698(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x40))();
  FUN_40b848d4(param_1 + 0xe0,param_2,param_3,param_4);
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40b91af0();
  return;
}



/* 40b906fc FUN_40b906fc */

/* Boundary evidence: original MIPS .pdata 40b906fc..40b9079f. Semantic name remains unreviewed. */

int FUN_40b906fc(int param_1)

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



/* 40b907a0 FUN_40b907a0 */

/* Boundary evidence: original MIPS .pdata 40b907a0..40b907cf. Semantic name remains unreviewed. */

void FUN_40b907a0(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b907d0 FUN_40b907d0 */

/* Boundary evidence: original MIPS .pdata 40b907d0..40b90847. Semantic name remains unreviewed. */

undefined4 FUN_40b907d0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  FUN_40b951dc(param_1);
  (**(code **)(**(int **)(param_1 + 100) + 0x24))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b90848 FUN_40b90848 */

/* Boundary evidence: original MIPS .pdata 40b90848..40b90877. Semantic name remains unreviewed. */

void FUN_40b90848(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b90878 FUN_40b90878 */

/* Boundary evidence: original MIPS .pdata 40b90878..40b908ef. Semantic name remains unreviewed. */

undefined4 FUN_40b90878(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 100) + 0x80);
  EnterCriticalSection(lpCriticalSection);
  FUN_40b95224(param_1);
  (**(code **)(**(int **)(param_1 + 100) + 0x28))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b908f0 FUN_40b908f0 */

/* Boundary evidence: original MIPS .pdata 40b908f0..40b9091f. Semantic name remains unreviewed. */

void FUN_40b908f0(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b90920 FUN_40b90920 */

/* Boundary evidence: original MIPS .pdata 40b90920..40b9094f. Semantic name remains unreviewed. */

void FUN_40b90920(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  FUN_40b849c0(param_1 + 0xe0,param_2,param_3,param_4);
  FUN_40b95288(param_1);
  return;
}



/* 40b90950 FUN_40b90950 */

/* Boundary evidence: original MIPS .pdata 40b90950..40b90977. Semantic name remains unreviewed. */

void FUN_40b90950(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x34))();
  return;
}



/* 40b90978 FUN_40b90978 */

/* Boundary evidence: original MIPS .pdata 40b90978..40b9099f. Semantic name remains unreviewed. */

void FUN_40b90978(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x38))();
  return;
}



/* 40b909a0 FUN_40b909a0 */

/* Boundary evidence: original MIPS .pdata 40b909a0..40b90a07. Semantic name remains unreviewed. */

bool FUN_40b909a0(int param_1)

{
  bool bVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0x70) + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  bVar1 = FUN_40b849e0((int *)(param_1 + 0xe0));
  LeaveCriticalSection(lpCriticalSection);
  return bVar1;
}



/* 40b90a08 FUN_40b90a08 */

/* Boundary evidence: original MIPS .pdata 40b90a08..40b90a37. Semantic name remains unreviewed. */

void FUN_40b90a08(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40b90a38 FUN_40b90a38 */

/* Boundary evidence: original MIPS .pdata 40b90a38..40b90af7. Semantic name remains unreviewed. */

undefined4
FUN_40b90a38(int *param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,int param_6,
            int param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1[0x1c];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x6c));
  uVar2 = 0;
  FUN_40b83d18((int)(param_1 + 0x38),param_2,param_3,param_4,param_5,param_6);
  if (param_7 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x6c));
  return uVar2;
}



/* 40b90af8 FUN_40b90af8 */

/* Boundary evidence: original MIPS .pdata 40b90af8..40b90b27. Semantic name remains unreviewed. */

void FUN_40b90af8(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40b90b28 FUN_40b90b28 */

/* Boundary evidence: original MIPS .pdata 40b90b28..40b90bc3. Semantic name remains unreviewed. */

undefined4 FUN_40b90b28(int *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[0x1c];
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  uVar3 = 0;
  bVar1 = FUN_40b84aac(param_1 + 0x38,param_2);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    uVar3 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x6c));
  return uVar3;
}



/* 40b90bc4 FUN_40b90bc4 */

/* Boundary evidence: original MIPS .pdata 40b90bc4..40b90bf3. Semantic name remains unreviewed. */

void FUN_40b90bc4(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b90bf4 FUN_40b90bf4 */

/* Boundary evidence: original MIPS .pdata 40b90bf4..40b90e2f. Semantic name remains unreviewed. */

uint FUN_40b90bf4(undefined4 param_1,undefined4 *param_2,uint param_3,int *param_4)

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
LAB_40b90dc8:
                *param_2 = pvVar3;
                return uVar6;
              }
            }
            if ((-1 < local_3c) && ((local_3c != 0 || (uVar6 < local_40)))) {
              operator_delete(pvVar3);
              return 0;
            }
            goto LAB_40b90dc8;
          }
        }
      }
    }
  }
  return 0;
}



/* 40b90ea8 FUN_40b90ea8 */

/* Boundary evidence: original MIPS .pdata 40b90ea8..40b90ecf. Semantic name remains unreviewed. */

void FUN_40b90ea8(int param_1,undefined4 param_2)

{
  undefined1 auStack_10 [8];
  
  (**(code **)(**(int **)(param_1 + 4) + 0x20))(*(int **)(param_1 + 4),param_2,auStack_10);
  return;
}



/* 40b90ed0 FUN_40b90ed0 */

/* Boundary evidence: original MIPS .pdata 40b90ed0..40b90efb. Semantic name remains unreviewed. */

void FUN_40b90ed0(int param_1,undefined4 param_2)

{
  undefined1 auStack_10 [8];
  
  (**(code **)(**(int **)(param_1 + 4) + 0x20))(*(int **)(param_1 + 4),auStack_10,param_2);
  return;
}



/* 40b90f14 FUN_40b90f14 */

/* Boundary evidence: original MIPS .pdata 40b90f14..40b90f83. Semantic name remains unreviewed. */

void FUN_40b90f14(int param_1,undefined4 param_2,uint param_3)

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



/* 40b90f84 FUN_40b90f84 */

/* Boundary evidence: original MIPS .pdata 40b90f84..40b90fd7. Semantic name remains unreviewed. */

undefined4 FUN_40b90f84(int param_1)

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



/* 40b90fd8 FUN_40b90fd8 */

/* Boundary evidence: original MIPS .pdata 40b90fd8..40b9102f. Semantic name remains unreviewed. */

void FUN_40b90fd8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 != -0x7ffbfdd9) && (param_2 < 0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x70) + 0x70);
    iVar2 = *(int *)(iVar1 + 0xa8);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 4) = 1;
    }
    FUN_40b942d0(iVar1);
  }
  return;
}



/* 40b91030 FUN_40b91030 */

/* Boundary evidence: original MIPS .pdata 40b91030..40b9107b. Semantic name remains unreviewed. */

undefined4 * FUN_40b91030(undefined4 *param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  FUN_40b84c5c(param_1,param_2,param_3,param_4);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b91098 FUN_40b91098 */

/* Boundary evidence: original MIPS .pdata 40b91098..40b910c3. Semantic name remains unreviewed. */

void FUN_40b91098(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x1c))();
  return;
}



/* 40b910d4 FUN_40b910d4 */

/* Boundary evidence: original MIPS .pdata 40b910d4..40b910fb. Semantic name remains unreviewed. */

void FUN_40b910d4(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 0x4c))();
  return;
}



/* 40b910fc FUN_40b910fc */

/* Boundary evidence: original MIPS .pdata 40b910fc..40b91147. Semantic name remains unreviewed. */

undefined4 FUN_40b910fc(int param_1,undefined4 param_2)

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



/* 40b91148 FUN_40b91148 */

/* Boundary evidence: original MIPS .pdata 40b91148..40b91163. Semantic name remains unreviewed. */

void FUN_40b91148(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  FUN_40b8fe80(*(int *)(param_1 + 4),param_2,param_3,param_4);
  return;
}



/* 40b9119c FUN_40b9119c */

/* Boundary evidence: original MIPS .pdata 40b9119c..40b9123f. Semantic name remains unreviewed. */

undefined4 * FUN_40b9119c(undefined4 *param_1,int param_2,undefined4 param_3,wchar_t *param_4)

{
  FUN_40b9817c(param_1,0,param_2,param_2 + 0x6c,param_3,param_4);
  *param_1 = &PTR_FUN_40ba3bbc;
  param_1[3] = &PTR_FUN_40ba3b74;
  param_1[4] = &PTR_LAB_40ba3b60;
  param_1[0x28] = &PTR_LAB_40ba3b3c;
  param_1[0x29] = param_1;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  FUN_40b99e60(param_1 + 0x2c);
  return param_1;
}



/* 40b91240 FUN_40b91240 */

/* Boundary evidence: original MIPS .pdata 40b91240..40b9126f. Semantic name remains unreviewed. */

void FUN_40b91240(void)

{
  int *in_v0;
  
  FUN_40b8fd18(*in_v0);
  return;
}



/* 40b91270 FUN_40b91270 */

/* Boundary evidence: original MIPS .pdata 40b91270..40b91297. Semantic name remains unreviewed. */

void FUN_40b91270(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b91298 FUN_40b91298 */

/* Boundary evidence: original MIPS .pdata 40b91298..40b912bf. Semantic name remains unreviewed. */

void FUN_40b91298(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b912c0 FUN_40b912c0 */

/* Boundary evidence: original MIPS .pdata 40b912c0..40b912e7. Semantic name remains unreviewed. */

void FUN_40b912c0(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b912e8 FUN_40b912e8 */

/* Boundary evidence: original MIPS .pdata 40b912e8..40b91307. Semantic name remains unreviewed. */

undefined4 FUN_40b912e8(int param_1)

{
  FUN_40b9aa9c(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40b91308 FUN_40b91308 */

/* Boundary evidence: original MIPS .pdata 40b91308..40b91327. Semantic name remains unreviewed. */

undefined4 FUN_40b91308(int param_1)

{
  FUN_40b9a1a4(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40b91328 FUN_40b91328 */

/* Boundary evidence: original MIPS .pdata 40b91328..40b9134f. Semantic name remains unreviewed. */

undefined4 FUN_40b91328(int param_1)

{
  *(undefined4 *)(param_1 + 0xa8) = 1;
  FUN_40b9ab3c(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
  return 0;
}



/* 40b9138c FUN_40b9138c */

/* Boundary evidence: original MIPS .pdata 40b9138c..40b913e7. Semantic name remains unreviewed. */

int FUN_40b9138c(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  
  iVar1 = FUN_40b94dd0(param_1);
  if (-1 < iVar1) {
    p_Var2 = *(LPCRITICAL_SECTION *)(param_1 + 0xac);
    if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
      FUN_40b9a658(p_Var2);
      operator_delete(p_Var2);
    }
    *(undefined4 *)(param_1 + 0xac) = 0;
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b913e8 FUN_40b913e8 */

/* Boundary evidence: original MIPS .pdata 40b913e8..40b9153f. Semantic name remains unreviewed. */

DWORD FUN_40b913e8(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  LPCRITICAL_SECTION p_Var3;
  DWORD local_70;
  LPCRITICAL_SECTION local_6c;
  undefined1 auStack_68 [72];
  uint local_20;
  
  uVar1 = DAT_40ba9854;
  local_20 = DAT_40ba9854;
  *(undefined4 *)(param_1 + 0xa8) = 1;
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_40b9bea4(uVar1);
    DVar2 = 0;
  }
  else {
    DVar2 = FUN_40b94d90(param_1);
    if ((int)DVar2 < 0) {
      FUN_40b9bea4(local_20);
    }
    else {
      local_70 = 0;
      (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))((int *)(param_1 + 0xc),auStack_68);
      FUN_40b995c8((int)auStack_68);
      local_6c = operator_new(0x54);
      if (local_6c == (LPCRITICAL_SECTION)0x0) {
        p_Var3 = (LPCRITICAL_SECTION)0x0;
      }
      else {
        p_Var3 = FUN_40b9ac6c(local_6c,*(undefined4 **)(param_1 + 0x18),&local_70,0,1,1,0,200,3);
      }
      *(LPCRITICAL_SECTION *)(param_1 + 0xac) = p_Var3;
      if (p_Var3 == (LPCRITICAL_SECTION)0x0) {
        FUN_40b9bea4(local_20);
        DVar2 = 0x8007000e;
      }
      else {
        if ((int)local_70 < 0) {
          FUN_40b9a658(p_Var3);
          operator_delete(p_Var3);
          *(undefined4 *)(param_1 + 0xac) = 0;
        }
        DVar2 = local_70;
        FUN_40b9bea4(local_20);
      }
    }
  }
  return DVar2;
}



/* 40b91540 FUN_40b91540 */

/* Boundary evidence: original MIPS .pdata 40b91540..40b9156f. Semantic name remains unreviewed. */

void FUN_40b91540(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x6c));
  return;
}



/* 40b91570 FUN_40b91570 */

/* Boundary evidence: original MIPS .pdata 40b91570..40b91633. Semantic name remains unreviewed. */

void FUN_40b91570(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = &PTR_FUN_40ba3bbc;
  param_1[3] = &PTR_FUN_40ba3b74;
  param_1[4] = &PTR_LAB_40ba3b60;
  if (param_1[0x2e] != 0) {
    do {
      pvVar1 = (void *)FUN_40b9a144(param_1 + 0x2c);
      if (pvVar1 != (void *)0x0) {
        FUN_40b9962c((int)pvVar1);
        operator_delete(pvVar1);
      }
    } while (param_1[0x2e] != 0);
  }
  FUN_40b9a0fc(param_1 + 0x2c);
  FUN_40b94698((int)param_1);
  return;
}



/* 40b91634 FUN_40b91634 */

/* Boundary evidence: original MIPS .pdata 40b91634..40b91663. Semantic name remains unreviewed. */

void FUN_40b91634(void)

{
  int *in_v0;
  
  FUN_40b8fd18(*in_v0);
  return;
}



/* 40b91664 FUN_40b91664 */

/* Boundary evidence: original MIPS .pdata 40b91664..40b91697. Semantic name remains unreviewed. */

void FUN_40b91664(void)

{
  int *in_v0;
  
  FUN_40b8fd34((undefined4 *)(*in_v0 + 0xb0));
  return;
}



/* 40b91698 FUN_40b91698 */

/* Boundary evidence: original MIPS .pdata 40b91698..40b91717. Semantic name remains unreviewed. */

undefined4 FUN_40b91698(int param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + 0xb0);
  do {
    if (local_18[0] == 0) {
      return 1;
    }
    pvVar1 = (void *)FUN_40b99ed8((int *)(param_1 + 0xb0),local_18);
    iVar2 = FUN_40b99798(pvVar1,param_2);
  } while (iVar2 == 0);
  return 0;
}



/* 40b91718 FUN_40b91718 */

/* Boundary evidence: original MIPS .pdata 40b91718..40b9179b. Semantic name remains unreviewed. */

undefined4 FUN_40b91718(int param_1,int param_2,void *param_3)

{
  bool bVar1;
  void *pvVar2;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + 0xb0);
  do {
    if (local_18[0] == 0) {
      return 0x40103;
    }
    pvVar2 = (void *)FUN_40b99ed8((int *)(param_1 + 0xb0),local_18);
    bVar1 = param_2 != 0;
    param_2 = param_2 + -1;
  } while (bVar1);
  FUN_40b9976c(param_3,pvVar2);
  return 0;
}



/* 40b9179c FUN_40b9179c */

/* Boundary evidence: original MIPS .pdata 40b9179c..40b91847. Semantic name remains unreviewed. */

undefined4 FUN_40b9179c(int param_1,void *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  pvVar1 = operator_new(0x48);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = FUN_40b996f4(pvVar1,param_2);
  }
  if (pvVar1 != (void *)0x0) {
    puVar2 = FUN_40b9a000((undefined4 *)(param_1 + 0xb0),pvVar1);
    if (puVar2 != (undefined4 *)0x0) {
      return 0;
    }
    FUN_40b9962c((int)pvVar1);
    operator_delete(pvVar1);
  }
  return 0x8007000e;
}



/* 40b91848 FUN_40b91848 */

/* Boundary evidence: original MIPS .pdata 40b91848..40b91877. Semantic name remains unreviewed. */

void FUN_40b91848(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40b91878 FUN_40b91878 */

/* Boundary evidence: original MIPS .pdata 40b91878..40b9193b. Semantic name remains unreviewed. */

undefined4 FUN_40b91878(int param_1,int param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0xb8) != 0) {
      do {
        pvVar1 = (void *)FUN_40b9a144((int *)(param_1 + 0xb0));
        if (pvVar1 != (void *)0x0) {
          FUN_40b9962c((int)pvVar1);
          operator_delete(pvVar1);
        }
      } while (*(int *)(param_1 + 0xb8) != 0);
    }
    uVar2 = 0;
  }
  else {
    piVar3 = (int *)FUN_40b99f00((int *)(param_1 + 0xb0),param_2);
    if (piVar3 == (int *)0x0) {
      uVar2 = 1;
    }
    else {
      pvVar1 = (void *)FUN_40b99f44((int *)(param_1 + 0xb0),piVar3);
      if (pvVar1 != (void *)0x0) {
        FUN_40b9962c((int)pvVar1);
        operator_delete(pvVar1);
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* 40b9193c FUN_40b9193c */

/* Boundary evidence: original MIPS .pdata 40b9193c..40b91a47. Semantic name remains unreviewed. */

undefined4 *
FUN_40b9193c(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  FUN_40b97bdc(param_1,param_2,param_3,(LPCRITICAL_SECTION)(param_1 + 0x1b),param_4);
  *param_1 = &PTR_FUN_40ba3d90;
  param_1[3] = &PTR_FUN_40ba3d54;
  param_1[4] = &PTR_LAB_40ba3d40;
  param_1[0x14] = 0;
  FUN_40b99e60(param_1 + 0x15);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1b));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  param_1[0x2a] = 0;
  param_1[0x2b] = 0x7b785574;
  param_1[0x2c] = 0x11cf8c82;
  param_1[0x2d] = 0xaa000cbc;
  param_1[0x2e] = 0xf674ac00;
  param_1[0x2f] = &PTR_FUN_40ba3b38;
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



/* 40b91a48 FUN_40b91a48 */

/* Boundary evidence: original MIPS .pdata 40b91a48..40b91a77. Semantic name remains unreviewed. */

void FUN_40b91a48(void)

{
  int *in_v0;
  
  FUN_40b96748(*in_v0);
  return;
}



/* 40b91a78 FUN_40b91a78 */

/* Boundary evidence: original MIPS .pdata 40b91a78..40b91a9f. Semantic name remains unreviewed. */

void FUN_40b91a78(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b91aa0 FUN_40b91aa0 */

/* Boundary evidence: original MIPS .pdata 40b91aa0..40b91ac7. Semantic name remains unreviewed. */

void FUN_40b91aa0(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b91ac8 FUN_40b91ac8 */

/* Boundary evidence: original MIPS .pdata 40b91ac8..40b91aef. Semantic name remains unreviewed. */

void FUN_40b91ac8(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b91af0 FUN_40b91af0 */

undefined4 FUN_40b91af0(void)

{
  return 0;
}



/* 40b91b34 FUN_40b91b34 */

/* Boundary evidence: original MIPS .pdata 40b91b34..40b91c57. Semantic name remains unreviewed. */

undefined4 FUN_40b91b34(int param_1)

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
      piVar1 = (int *)FUN_40b99ed8((int *)(param_1 + 0x48),&local_28);
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
      FUN_40b83b88(iVar2);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    *(undefined4 *)(param_1 + 8) = 1;
  }
  LeaveCriticalSection(lpCriticalSection_00);
  return 0;
}



/* 40b91c58 FUN_40b91c58 */

/* Boundary evidence: original MIPS .pdata 40b91c58..40b91c87. Semantic name remains unreviewed. */

void FUN_40b91c58(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b91c88 FUN_40b91c88 */

/* Boundary evidence: original MIPS .pdata 40b91c88..40b91cb7. Semantic name remains unreviewed. */

void FUN_40b91c88(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b91cb8 FUN_40b91cb8 */

/* Boundary evidence: original MIPS .pdata 40b91cb8..40b91e17. Semantic name remains unreviewed. */

undefined4 FUN_40b91cb8(int param_1)

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
      (**(code **)(**(int **)(param_1 + 0x9c) + 0x18))();
    }
    if (*(int *)(param_1 + 0xcc) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0x44))();
    }
    local_28 = *(int *)(param_1 + 0x48);
    while (local_28 != 0) {
      piVar1 = (int *)FUN_40b99ed8((int *)(param_1 + 0x48),&local_28);
      if (piVar1[6] != 0) {
        (**(code **)(*piVar1 + 0x18))(piVar1);
      }
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x44) + 0x9c);
    if ((iVar2 != 0) && (iVar2 = iVar2 + -0xc, iVar2 != 0)) {
      FUN_40b83b88(iVar2);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* 40b91e18 FUN_40b91e18 */

/* Boundary evidence: original MIPS .pdata 40b91e18..40b91e47. Semantic name remains unreviewed. */

void FUN_40b91e18(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b91e48 FUN_40b91e48 */

/* Boundary evidence: original MIPS .pdata 40b91e48..40b91e77. Semantic name remains unreviewed. */

void FUN_40b91e48(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b91e78 FUN_40b91e78 */

/* Boundary evidence: original MIPS .pdata 40b91e78..40b91ed3. Semantic name remains unreviewed. */

int FUN_40b91e78(int param_1)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x5c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  return (uint)(iVar1 != 0) + iVar2;
}



/* 40b91ed4 FUN_40b91ed4 */

/* Boundary evidence: original MIPS .pdata 40b91ed4..40b91fd3. Semantic name remains unreviewed. */

int FUN_40b91ed4(int param_1,int param_2)

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
        FUN_40b99ed8(piVar1,&local_20);
      }
      iVar2 = FUN_40b99ed8(piVar1,&local_20);
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar2;
}



/* 40b91fd4 FUN_40b91fd4 */

/* Boundary evidence: original MIPS .pdata 40b91fd4..40b92003. Semantic name remains unreviewed. */

void FUN_40b91fd4(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40b92004 FUN_40b92004 */

/* Boundary evidence: original MIPS .pdata 40b92004..40b920e3. Semantic name remains unreviewed. */

bool FUN_40b92004(int param_1,int *param_2)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x6c);
  EnterCriticalSection(lpCriticalSection);
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x94);
  EnterCriticalSection(lpCriticalSection_00);
  FUN_40b94318(param_1);
  (**(code **)(param_2[3] + 4))();
  puVar1 = FUN_40b9a000((undefined4 *)(param_1 + 0x54),param_2);
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



/* 40b920e4 FUN_40b920e4 */

/* Boundary evidence: original MIPS .pdata 40b920e4..40b92113. Semantic name remains unreviewed. */

void FUN_40b920e4(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b92114 FUN_40b92114 */

/* Boundary evidence: original MIPS .pdata 40b92114..40b92143. Semantic name remains unreviewed. */

void FUN_40b92114(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40b92144 FUN_40b92144 */

/* Boundary evidence: original MIPS .pdata 40b92144..40b9223f. Semantic name remains unreviewed. */

void FUN_40b92144(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  iVar1 = FUN_40b9a144((int *)(param_1 + 0x54));
  while (iVar1 != 0) {
    FUN_40b94318(param_1);
    if (*(int **)(iVar1 + 0x18) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x18) + 0x14))();
      (**(code **)(*(int *)(iVar1 + 0xc) + 0x14))();
    }
    (**(code **)(*(int *)(iVar1 + 0xc) + 8))();
    iVar1 = FUN_40b9a144((int *)(param_1 + 0x54));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return;
}



/* 40b92240 FUN_40b92240 */

/* Boundary evidence: original MIPS .pdata 40b92240..40b9226f. Semantic name remains unreviewed. */

void FUN_40b92240(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40b92270 FUN_40b92270 */

/* Boundary evidence: original MIPS .pdata 40b92270..40b9229f. Semantic name remains unreviewed. */

void FUN_40b92270(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x24));
  return;
}



/* 40b922a0 FUN_40b922a0 */

/* Boundary evidence: original MIPS .pdata 40b922a0..40b923b7. Semantic name remains unreviewed. */

int FUN_40b922a0(int param_1,wchar_t *param_2,int *param_3)

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
    piVar2 = FUN_40b9119c(local_1c,param_1,&local_20,param_2);
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
    bVar1 = FUN_40b92004(param_1,piVar2);
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



/* 40b923b8 FUN_40b923b8 */

/* Boundary evidence: original MIPS .pdata 40b923b8..40b923e7. Semantic name remains unreviewed. */

void FUN_40b923b8(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x1c));
  return;
}



/* 40b923e8 FUN_40b923e8 */

/* Boundary evidence: original MIPS .pdata 40b923e8..40b9262f. Semantic name remains unreviewed. */

int FUN_40b923e8(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined4 *puVar1;
  undefined ***pppuVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_48;
  undefined4 *local_44;
  undefined **local_40;
  int *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 auStack_20 [16];
  
  local_48 = -0x7fffbffb;
  iVar4 = param_1[0x14];
  piVar5 = *(int **)(iVar4 + 0x120);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
  }
  piVar6 = *(int **)(iVar4 + 0x120);
  local_40 = &PTR_FUN_40ba3b20;
  piVar3 = param_1 + 0x2f;
  pppuVar2 = &local_40;
  local_38 = 0;
  local_34 = 0;
  local_3c = piVar6;
  piVar5 = (int *)(**(code **)(*param_1 + 0x3c))(param_1);
  param_1[0x2a] = (int)piVar5;
  if (piVar5 != (int *)0x0) {
    pppuVar2 = &local_40;
    local_48 = (**(code **)(*piVar5 + 4))(piVar5);
  }
  if (param_1[0x2a] == 0) {
    (**(code **)(*piVar6 + 8))(piVar6);
    local_48 = -0x7ff8fff2;
  }
  else {
    if (-1 < local_48) {
      *(int *)(param_1[0x14] + 0xd8) = param_1[0x2a];
      if (*(int *)(param_1[0x14] + 0x9c) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(param_1[0x14] + 0x9c) + -0xc;
      }
      (**(code **)(*(int *)(iVar4 + 0xc) + 0x10))((int *)(iVar4 + 0xc),&local_30);
      local_30 = 3;
      local_2c = 0x20000;
      local_28 = 0x200;
      local_24 = 0;
      piVar5 = *(int **)(param_1[0x14] + 0x9c);
      if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xc)) {
        piVar5 = (int *)0x0;
      }
      (**(code **)(*piVar5 + 0xc))(piVar5,&local_30,auStack_20);
      piVar3 = param_1 + 0x2b;
      pppuVar2 = (undefined ***)(param_1 + 0x3a);
      (**(code **)(*(int *)param_1[0x2a] + 0x28))();
    }
    if (param_1[0x36] != 0) {
      FUN_40b83ba4(0x40ba401c,pppuVar2,piVar3,(va_list)param_4);
      piVar5 = (int *)param_1[0x36];
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0xc))(piVar5,1);
      }
      param_1[0x36] = 0;
    }
    if (param_1[0x36] == 0) {
      local_44 = operator_new(0x50);
      if (local_44 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        piVar3 = (int *)param_1[1];
        param_4 = &local_48;
        puVar1 = FUN_40b86734(local_44,param_1,piVar3);
      }
      param_1[0x36] = (int)puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        FUN_40b83ba4(0x40ba3fc8,local_48,piVar3,(va_list)param_4);
      }
    }
    (**(code **)(*piVar6 + 8))(piVar6);
  }
  return local_48;
}



/* 40b92630 FUN_40b92630 */

/* Boundary evidence: original MIPS .pdata 40b92630..40b9265f. Semantic name remains unreviewed. */

void FUN_40b92630(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x44));
  return;
}



/* 40b92660 FUN_40b92660 */

/* Boundary evidence: original MIPS .pdata 40b92660..40b9272f. Semantic name remains unreviewed. */

int FUN_40b92660(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_18;
  int local_14;
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
  iVar5 = 0;
  iVar2 = iVar4 + -0xc;
  if (iVar4 == 0) {
    iVar2 = 0;
  }
  uVar1 = FUN_40b835c4(iVar2,&local_14);
  if (local_14 != 0) {
    local_18 = 0;
    piVar3 = &local_18;
    iVar5 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x20))
                      (*(int **)(param_1 + 0xa8),uVar1,local_14,piVar3,param_2);
    if (iVar5 < 0) {
      FUN_40b83ba4(0x40ba40e0,iVar5,local_14,(va_list)piVar3);
      iVar5 = 1;
    }
    else if (local_18 != 0) {
      iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
      iVar2 = iVar4 + -0xc;
      if (iVar4 == 0) {
        iVar2 = 0;
      }
      FUN_40b83a0c(iVar2,local_18);
    }
  }
  return iVar5;
}



/* 40b92730 FUN_40b92730 */

/* Boundary evidence: original MIPS .pdata 40b92730..40b927d7. Semantic name remains unreviewed. */

void FUN_40b92730(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_10 [2];
  
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xa8) + 0x1c))();
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
  if ((iVar2 != 0) && (iVar2 = iVar2 + -0xc, iVar2 != 0)) {
    FUN_40b83b88(iVar2);
  }
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40b99ed8((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x4c))(piVar1);
    }
  }
  return;
}



/* 40b927d8 FUN_40b927d8 */

/* Boundary evidence: original MIPS .pdata 40b927d8..40b9285f. Semantic name remains unreviewed. */

undefined4 FUN_40b927d8(int param_1)

{
  int *piVar1;
  int local_10 [2];
  
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xa8) + 0xc))();
  }
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40b99ed8((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x50))(piVar1);
    }
  }
  return 0;
}



/* 40b92860 FUN_40b92860 */

/* Boundary evidence: original MIPS .pdata 40b92860..40b9290b. Semantic name remains unreviewed. */

undefined4 FUN_40b92860(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_10 [2];
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
  if ((iVar2 != 0) && (iVar2 = iVar2 + -0xc, iVar2 != 0)) {
    FUN_40b83b88(iVar2);
  }
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xa8) + 0x10))();
  }
  local_10[0] = *(int *)(param_1 + 0x54);
  while (local_10[0] != 0) {
    piVar1 = (int *)FUN_40b99ed8((int *)(param_1 + 0x54),local_10);
    if (piVar1[6] != 0) {
      (**(code **)(*piVar1 + 0x54))(piVar1);
    }
  }
  return 0;
}



/* 40b9290c FUN_40b9290c */

/* Boundary evidence: original MIPS .pdata 40b9290c..40b92953. Semantic name remains unreviewed. */

void FUN_40b9290c(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xa8);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  FUN_40b92144(param_1);
  return;
}



/* 40b92954 FUN_40b92954 */

/* Boundary evidence: original MIPS .pdata 40b92954..40b92a6b. Semantic name remains unreviewed. */

undefined4 FUN_40b92954(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int local_20 [2];
  
  piVar1 = *(int **)(param_1 + 0xa8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x38))
              (piVar1,param_2,*(undefined4 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xe4),
               *(undefined4 *)(param_1 + 0xe8),*(undefined4 *)(param_1 + 0xec));
    piVar1 = *(int **)(param_1 + 0xa8);
    iVar2 = *piVar1;
    __litodp(*(undefined4 *)(param_1 + 0xf0));
    (**(code **)(iVar2 + 0x40))(piVar1);
    (**(code **)(**(int **)(param_1 + 0xa8) + 0x14))();
  }
  local_20[0] = *(int *)(param_1 + 0x54);
  while (local_20[0] != 0) {
    piVar1 = (int *)FUN_40b99ed8((int *)(param_1 + 0x54),local_20);
    if (piVar1[6] != 0) {
      iVar2 = *piVar1;
      __litodp(*(undefined4 *)(param_1 + 0xf0));
      (**(code **)(iVar2 + 0x58))(piVar1);
    }
  }
  return 0;
}



/* 40b92a6c FUN_40b92a6c */

/* Boundary evidence: original MIPS .pdata 40b92a6c..40b92be7. Semantic name remains unreviewed. */

undefined4
FUN_40b92a6c(int param_1,undefined ***param_2,undefined4 param_3,undefined4 param_4,
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
  local_30 = &PTR_FUN_40ba3b20;
  local_28 = 0;
  local_24 = 0;
  *(undefined4 *)(param_1 + 0xe0) = param_3;
  *(undefined4 *)(param_1 + 0xe4) = param_4;
  *(undefined4 *)(param_1 + 0xe8) = param_5;
  *(undefined4 *)(param_1 + 0xec) = param_6;
  local_2c = piVar5;
  bVar1 = FUN_40b909a0((int)piVar6);
  if (*(int **)(param_1 + 0xa8) != (int *)0x0) {
    pcVar4 = *(va_list *)(param_1 + 0xe4);
    uVar3 = *(undefined4 *)(param_1 + 0xe0);
    param_2 = &local_30;
    pppuVar2 = (undefined ***)(**(code **)(**(int **)(param_1 + 0xa8) + 0x34))();
    if ((int)pppuVar2 < 0) {
      FUN_40b83ba4(0x40ba4120,pppuVar2,uVar3,pcVar4);
      param_2 = pppuVar2;
    }
  }
  FUN_40b90a38(piVar6,param_2,0,0,0,0,CONCAT31(extraout_var,bVar1));
  (**(code **)(*piVar5 + 8))(piVar5);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  return 0;
}



/* 40b92be8 FUN_40b92be8 */

/* Boundary evidence: original MIPS .pdata 40b92be8..40b92c17. Semantic name remains unreviewed. */

void FUN_40b92be8(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x48));
  return;
}



/* 40b92c18 FUN_40b92c18 */

/* Boundary evidence: original MIPS .pdata 40b92c18..40b92caf. Semantic name remains unreviewed. */

undefined4 FUN_40b92c18(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  piVar2 = *(int **)(param_1 + 0x50);
  iVar1 = __dptoli(param_3,param_4);
  *(int *)(param_1 + 0xf0) = iVar1;
  FUN_40b90b28(piVar2,iVar1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  return 0;
}



/* 40b92cb0 FUN_40b92cb0 */

/* Boundary evidence: original MIPS .pdata 40b92cb0..40b92cdf. Semantic name remains unreviewed. */

void FUN_40b92cb0(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40b92ce0 FUN_40b92ce0 */

/* Boundary evidence: original MIPS .pdata 40b92ce0..40b92d2b. Semantic name remains unreviewed. */

void * FUN_40b92ce0(void *param_1,uint param_2,undefined4 param_3,va_list param_4)

{
  FUN_40b90500((int)param_1,param_2,param_3,param_4);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b92d2c FUN_40b92d2c */

/* Boundary evidence: original MIPS .pdata 40b92d2c..40b92e17. Semantic name remains unreviewed. */

int FUN_40b92d2c(int param_1,undefined4 param_2)

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
      FUN_40b942d0(iVar2);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40b92e18 FUN_40b92e18 */

/* Boundary evidence: original MIPS .pdata 40b92e18..40b92e47. Semantic name remains unreviewed. */

void FUN_40b92e18(void)

{
  int in_v0;
  
  FUN_40b831cc((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40b92e48 FUN_40b92e48 */

/* Boundary evidence: original MIPS .pdata 40b92e48..40b92ef7. Semantic name remains unreviewed. */

int FUN_40b92e48(int param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xd8) == 0) {
    return -0x7fff0001;
  }
  iVar1 = FUN_40b91af0();
  if (iVar1 < 0) {
    FUN_40b83ba4(0x40ba4210,param_2,param_3,param_4);
  }
  else {
    iVar1 = FUN_40b92954(*(int *)(param_1 + 0x70),param_2);
    if (iVar1 < 0) {
      FUN_40b83ba4(0x40ba4264,iVar1,param_3,param_4);
    }
    else {
      FUN_40b849a4((LPVOID)(param_1 + 0xe0));
    }
  }
  return iVar1;
}



/* 40b92ef8 FUN_40b92ef8 */

/* Boundary evidence: original MIPS .pdata 40b92ef8..40b92f13. Semantic name remains unreviewed. */

void FUN_40b92ef8(int param_1,wchar_t *param_2,int *param_3)

{
  FUN_40b922a0(*(int *)(param_1 + 4),param_2,param_3);
  return;
}



/* 40b92f14 FUN_40b92f14 */

/* Boundary evidence: original MIPS .pdata 40b92f14..40b92f2f. Semantic name remains unreviewed. */

void FUN_40b92f14(int param_1,void *param_2)

{
  FUN_40b9179c(*(int *)(param_1 + 4),param_2);
  return;
}



/* 40b92f30 FUN_40b92f30 */

/* Boundary evidence: original MIPS .pdata 40b92f30..40b92f4b. Semantic name remains unreviewed. */

void FUN_40b92f30(int param_1,int param_2)

{
  FUN_40b91878(*(int *)(param_1 + 4),param_2);
  return;
}



/* 40b92f4c FUN_40b92f4c */

/* Boundary evidence: original MIPS .pdata 40b92f4c..40b92f97. Semantic name remains unreviewed. */

undefined4 * FUN_40b92f4c(undefined4 *param_1,uint param_2)

{
  FUN_40b91570(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b92f98 FUN_40b92f98 */

/* Boundary evidence: original MIPS .pdata 40b92f98..40b93053. Semantic name remains unreviewed. */

void FUN_40b92f98(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40ba3d90;
  param_1[3] = &PTR_FUN_40ba3d54;
  param_1[4] = &PTR_LAB_40ba3d40;
  piVar1 = (int *)param_1[0x14];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
  }
  param_1[0x14] = 0;
  FUN_40b92144((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1b));
  FUN_40b9a0fc(param_1 + 0x15);
  FUN_40b96748((int)param_1);
  return;
}



/* 40b93054 FUN_40b93054 */

/* Boundary evidence: original MIPS .pdata 40b93054..40b93083. Semantic name remains unreviewed. */

void FUN_40b93054(void)

{
  int *in_v0;
  
  FUN_40b96748(*in_v0);
  return;
}



/* 40b93084 FUN_40b93084 */

/* Boundary evidence: original MIPS .pdata 40b93084..40b930b7. Semantic name remains unreviewed. */

void FUN_40b93084(void)

{
  int *in_v0;
  
  FUN_40b90028((undefined4 *)(*in_v0 + 0x54));
  return;
}



/* 40b930b8 FUN_40b930b8 */

/* Boundary evidence: original MIPS .pdata 40b930b8..40b930eb. Semantic name remains unreviewed. */

void FUN_40b930b8(void)

{
  int *in_v0;
  
  FUN_40b8fc3c((LPCRITICAL_SECTION)(*in_v0 + 0x6c));
  return;
}



/* 40b930ec FUN_40b930ec */

/* Boundary evidence: original MIPS .pdata 40b930ec..40b9311f. Semantic name remains unreviewed. */

void FUN_40b930ec(void)

{
  int *in_v0;
  
  FUN_40b8fc3c((LPCRITICAL_SECTION)(*in_v0 + 0x80));
  return;
}



/* 40b93120 FUN_40b93120 */

/* Boundary evidence: original MIPS .pdata 40b93120..40b93153. Semantic name remains unreviewed. */

void FUN_40b93120(void)

{
  int *in_v0;
  
  FUN_40b8fc3c((LPCRITICAL_SECTION)(*in_v0 + 0x94));
  return;
}



/* 40b93154 FUN_40b93154 */

/* Boundary evidence: original MIPS .pdata 40b93154..40b93187. Semantic name remains unreviewed. */

void FUN_40b93154(void)

{
  int *in_v0;
  
  FUN_40b8fc3c((LPCRITICAL_SECTION)(*in_v0 + 0xc4));
  return;
}



/* 40b93188 FUN_40b93188 */

/* Boundary evidence: original MIPS .pdata 40b93188..40b93203. Semantic name remains unreviewed. */

void FUN_40b93188(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x9c);
  iVar1 = iVar2 + -0xc;
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  FUN_40b83554(iVar1,param_2);
  iVar1 = (**(code **)(*param_2 + 0x3c))(param_2);
  FUN_40b92660(param_1,(uint)(iVar1 == 0));
  return;
}



/* 40b93204 FUN_40b93204 */

/* Boundary evidence: original MIPS .pdata 40b93204..40b9324f. Semantic name remains unreviewed. */

undefined4 * FUN_40b93204(undefined4 *param_1,uint param_2)

{
  FUN_40b92f98(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b93250 FUN_40b93250 */

/* Boundary evidence: original MIPS .pdata 40b93250..40b9326b. Semantic name remains unreviewed. */

void FUN_40b93250(HMODULE param_1,int param_2)

{
  FUN_40b9af74(param_1,param_2);
  return;
}



/* 40b9326c DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40b9326c..40b93287. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0x1326c  3  DllRegisterServer */
  FUN_40b9bc7c(1);
  return;
}



/* 40b93288 DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40b93288..40b932a3. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0x13288  4  DllUnregisterServer */
  FUN_40b9bc7c(0);
  return;
}



/* 40b932a4 FUN_40b932a4 */

/* Boundary evidence: original MIPS .pdata 40b932a4..40b9339b. Semantic name remains unreviewed. */

void FUN_40b932a4(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_40ba4b44;
  param_1[3] = &PTR_FUN_40ba4b08;
  param_1[4] = &PTR_LAB_40ba4af4;
  param_1[0x3e] = &PTR_LAB_40ba4adc;
  param_1[0x3f] = &PTR_LAB_40ba4a74;
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
  if (DAT_40bab7f0 != 0) {
    DAT_40bab7f0 = 0;
  }
  FUN_40b92f98(param_1);
  return;
}



/* 40b9339c FUN_40b9339c */

/* Boundary evidence: original MIPS .pdata 40b9339c..40b933cb. Semantic name remains unreviewed. */

void FUN_40b9339c(void)

{
  undefined4 *in_v0;
  
  FUN_40b92f98((undefined4 *)*in_v0);
  return;
}



/* 40b933cc FUN_40b933cc */

/* Boundary evidence: original MIPS .pdata 40b933cc..40b933f3. Semantic name remains unreviewed. */

void FUN_40b933cc(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40b933f4 FUN_40b933f4 */

/* Boundary evidence: original MIPS .pdata 40b933f4..40b9341b. Semantic name remains unreviewed. */

void FUN_40b933f4(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40b9341c FUN_40b9341c */

/* Boundary evidence: original MIPS .pdata 40b9341c..40b93443. Semantic name remains unreviewed. */

void FUN_40b9341c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40b93444 FUN_40b93444 */

/* Boundary evidence: original MIPS .pdata 40b93444..40b93593. Semantic name remains unreviewed. */

void FUN_40b93444(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ba5458,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x3e;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b98690(piVar2,param_3);
    return;
  }
  iVar1 = memcmp(param_2,&DAT_40ba5138,0x10);
  if ((iVar1 != 0) || (param_1[0x36] == 0)) {
    iVar1 = memcmp(param_2,&DAT_40ba49ec,0x10);
    if (iVar1 == 0) {
      piVar2 = param_1 + 0x3f;
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      FUN_40b98690(piVar2,param_3);
      return;
    }
    iVar1 = memcmp(param_2,&DAT_40ba6ad8,0x10);
    if (((iVar1 != 0) || (param_1[0x36] == 0)) &&
       ((iVar1 = memcmp(param_2,&DAT_40ba6f80,0x10), iVar1 != 0 || (param_1[0x36] == 0)))) {
      FUN_40b96668(param_1,param_2,param_3);
      return;
    }
  }
  (*(code *)**(undefined4 **)param_1[0x36])((undefined4 *)param_1[0x36],param_2,param_3);
  return;
}



/* 40b93594 FUN_40b93594 */

/* Boundary evidence: original MIPS .pdata 40b93594..40b93623. Semantic name remains unreviewed. */

undefined4 FUN_40b93594(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_40ba5728,0x10);
  if (iVar1 == 0) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40ba6608,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40ba6f70,0x10), iVar1 == 0)) {
      return 0;
    }
  }
  return 1;
}



/* 40b93624 FUN_40b93624 */

/* Boundary evidence: original MIPS .pdata 40b93624..40b93667. Semantic name remains unreviewed. */

undefined4 FUN_40b93624(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x50) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x50) + 0x4c))();
  return uVar1;
}



/* 40b93668 FUN_40b93668 */

/* Boundary evidence: original MIPS .pdata 40b93668..40b936ab. Semantic name remains unreviewed. */

undefined4 FUN_40b93668(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x50) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x50) + 0x50))();
  return uVar1;
}



/* 40b936ac FUN_40b936ac */

/* Boundary evidence: original MIPS .pdata 40b936ac..40b93713. Semantic name remains unreviewed. */

undefined4 FUN_40b936ac(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x50) == 0) {
    return 0x80004005;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x50) + 0x54))();
  return uVar1;
}



/* 40b93714 FUN_40b93714 */

/* Boundary evidence: original MIPS .pdata 40b93714..40b93757. Semantic name remains unreviewed. */

undefined4 FUN_40b93714(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 100))();
  return uVar1;
}



/* 40b93758 FUN_40b93758 */

/* Boundary evidence: original MIPS .pdata 40b93758..40b9379b. Semantic name remains unreviewed. */

undefined4 FUN_40b93758(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x60))();
  return uVar1;
}



/* 40b9379c FUN_40b9379c */

/* Boundary evidence: original MIPS .pdata 40b9379c..40b937df. Semantic name remains unreviewed. */

undefined4 FUN_40b9379c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x5c))();
  return uVar1;
}



/* 40b937e0 FUN_40b937e0 */

/* Boundary evidence: original MIPS .pdata 40b937e0..40b93823. Semantic name remains unreviewed. */

undefined4 FUN_40b937e0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x58))();
  return uVar1;
}



/* 40b93830 FUN_40b93830 */

/* Boundary evidence: original MIPS .pdata 40b93830..40b93873. Semantic name remains unreviewed. */

undefined4 FUN_40b93830(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x68))();
  return uVar1;
}



/* 40b93874 FUN_40b93874 */

/* Boundary evidence: original MIPS .pdata 40b93874..40b938b7. Semantic name remains unreviewed. */

undefined4 FUN_40b93874(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x6c))();
  return uVar1;
}



/* 40b938b8 FUN_40b938b8 */

/* Boundary evidence: original MIPS .pdata 40b938b8..40b938fb. Semantic name remains unreviewed. */

undefined4 FUN_40b938b8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x70))();
  return uVar1;
}



/* 40b938fc FUN_40b938fc */

/* Boundary evidence: original MIPS .pdata 40b938fc..40b9393f. Semantic name remains unreviewed. */

undefined4 FUN_40b938fc(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x74))();
  return uVar1;
}



/* 40b93940 FUN_40b93940 */

/* Boundary evidence: original MIPS .pdata 40b93940..40b9398f. Semantic name remains unreviewed. */

undefined4 FUN_40b93940(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x78))();
  return uVar1;
}



/* 40b93990 FUN_40b93990 */

/* Boundary evidence: original MIPS .pdata 40b93990..40b939d7. Semantic name remains unreviewed. */

undefined4 FUN_40b93990(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + -0x54) == 0) {
    return 0x80040265;
  }
  uVar1 = (**(code **)(**(int **)(param_1 + -0x54) + 0x7c))();
  return uVar1;
}



/* 40b939d8 FUN_40b939d8 */

/* Boundary evidence: original MIPS .pdata 40b939d8..40b939f3. Semantic name remains unreviewed. */

void FUN_40b939d8(int param_1)

{
  FUN_40b96b68(param_1);
  return;
}



/* 40b939f4 FUN_40b939f4 */

/* Boundary evidence: original MIPS .pdata 40b939f4..40b93a0f. Semantic name remains unreviewed. */

void FUN_40b939f4(int param_1)

{
  FUN_40b96c3c(param_1);
  return;
}



/* 40b93a10 FUN_40b93a10 */

/* Boundary evidence: original MIPS .pdata 40b93a10..40b93c4b. Semantic name remains unreviewed. */

uint FUN_40b93a10(undefined4 param_1,undefined4 *param_2,uint param_3,int *param_4)

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
LAB_40b93be4:
                *param_2 = pvVar3;
                return uVar6;
              }
            }
            if ((-1 < local_3c) && ((local_3c != 0 || (uVar6 < local_40)))) {
              operator_delete(pvVar3);
              return 0;
            }
            goto LAB_40b93be4;
          }
        }
      }
    }
  }
  return 0;
}



/* 40b93c4c FUN_40b93c4c */

/* Boundary evidence: original MIPS .pdata 40b93c4c..40b93df7. Semantic name remains unreviewed. */

undefined4 FUN_40b93c4c(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  char **ppcVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  char *local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  
  pcVar7 = (char *)0x0;
  local_30[0] = (char *)0x0;
  local_28 = 0;
  uVar9 = 0;
  local_24 = 0;
  uVar6 = 0;
  bVar1 = true;
  iVar2 = (**(code **)*param_2)(param_2,&local_28);
  pcVar8 = pcVar7;
  if ((-1 < iVar2) && (iVar2 = (**(code **)(*param_2 + 8))(param_2), -1 < iVar2)) {
    uVar4 = 0x1780;
    ppcVar3 = local_30;
    uVar6 = FUN_40b93a10(param_1,ppcVar3,0x1780,param_2);
    pcVar7 = local_30[0];
    pcVar8 = local_30[0];
    if ((local_30[0] == (char *)0x0) && (uVar6 == 0)) {
      FUN_40b83ba4(0x40ba4bc8,ppcVar3,uVar4,(va_list)param_2);
      if (*(int *)(param_1 + 0xa8) != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0xa8) + 4) = 1;
      }
      return 0;
    }
  }
  do {
    if (uVar6 < 5) {
LAB_40b93dbc:
      if (pcVar8 != (char *)0x0) {
        operator_delete(pcVar8);
      }
      return uVar9;
    }
    if (*pcVar7 == 'G') {
      if (uVar6 < 0x234) {
        uVar9 = 0;
        goto LAB_40b93dbc;
      }
      uVar5 = 0x5e0;
      if (uVar6 < 0x5e1) {
        uVar5 = uVar6;
      }
      iVar2 = 0;
      if (0 < (int)uVar5) {
        do {
          bVar1 = (bool)(pcVar7[iVar2] == 'G' & bVar1);
          if (!bVar1) break;
          iVar2 = iVar2 + 0xbc;
        } while (iVar2 < (int)uVar5);
      }
      if (bVar1) {
        uVar9 = 1;
        goto LAB_40b93dbc;
      }
    }
    uVar6 = uVar6 - 1;
    pcVar7 = pcVar7 + 1;
  } while( true );
}



/* 40b93df8 FUN_40b93df8 */

/* Boundary evidence: original MIPS .pdata 40b93df8..40b93e77. Semantic name remains unreviewed. */

undefined4 * FUN_40b93df8(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_40b93c4c(param_1,param_2);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = operator_new(0x1eb18);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40b8f6d8(puVar2,param_3);
    }
  }
  return puVar2;
}



/* 40b93e78 FUN_40b93e78 */

/* Boundary evidence: original MIPS .pdata 40b93e78..40b93ea7. Semantic name remains unreviewed. */

void FUN_40b93e78(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40b93f5c FUN_40b93f5c */

/* Boundary evidence: original MIPS .pdata 40b93f5c..40b94043. Semantic name remains unreviewed. */

undefined4 * FUN_40b93f5c(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  FUN_40b9193c(param_1,L"CTSDemuxFilter",param_2,&DAT_40ba455c);
  param_1[0x3f] = &PTR_LAB_40ba4a0c;
  *param_1 = &PTR_FUN_40ba4b44;
  param_1[3] = &PTR_FUN_40ba4b08;
  param_1[4] = &PTR_LAB_40ba4af4;
  param_1[0x3e] = &PTR_LAB_40ba4adc;
  param_1[0x3f] = &PTR_LAB_40ba4a74;
  puVar1 = operator_new(0x158);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40b90330(puVar1,(int)param_1,param_3);
  }
  param_1[0x14] = puVar1;
  return param_1;
}



/* 40b94044 FUN_40b94044 */

/* Boundary evidence: original MIPS .pdata 40b94044..40b94073. Semantic name remains unreviewed. */

void FUN_40b94044(void)

{
  undefined4 *in_v0;
  
  FUN_40b92f98((undefined4 *)*in_v0);
  return;
}



/* 40b94074 FUN_40b94074 */

/* Boundary evidence: original MIPS .pdata 40b94074..40b940a3. Semantic name remains unreviewed. */

void FUN_40b94074(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40b940a4 FUN_40b940a4 */

/* Boundary evidence: original MIPS .pdata 40b940a4..40b940ef. Semantic name remains unreviewed. */

undefined4 * FUN_40b940a4(undefined4 *param_1,uint param_2)

{
  FUN_40b932a4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b940f0 FUN_40b940f0 */

/* Boundary evidence: original MIPS .pdata 40b940f0..40b941ab. Semantic name remains unreviewed. */

undefined4 *
FUN_40b940f0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,va_list param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x0;
  if (DAT_40bab7f0 == 0) {
    puVar1 = operator_new(0x100);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40b93f5c(puVar1,param_1,param_2);
    }
    DAT_40bab7f0 = 1;
    *param_2 = 0;
  }
  else {
    FUN_40b83ba4(0x40ba4cc8,param_2,param_3,param_4);
    *param_2 = 0x80004005;
  }
  return puVar1;
}



/* 40b941ac FUN_40b941ac */

/* Boundary evidence: original MIPS .pdata 40b941ac..40b941db. Semantic name remains unreviewed. */

void FUN_40b941ac(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x20));
  return;
}



/* 40b94244 FUN_40b94244 */

/* Boundary evidence: original MIPS .pdata 40b94244..40b942cf. Semantic name remains unreviewed. */

undefined4 FUN_40b94244(int param_1,short *param_2)

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
      FUN_40b98c2c(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40b942d0 FUN_40b942d0 */

/* Boundary evidence: original MIPS .pdata 40b942d0..40b9430f. Semantic name remains unreviewed. */

undefined4 FUN_40b942d0(int param_1)

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



/* 40b94318 FUN_40b94318 */

/* Boundary evidence: original MIPS .pdata 40b94318..40b94333. Semantic name remains unreviewed. */

void FUN_40b94318(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x48));
  return;
}



/* 40b94334 FUN_40b94334 */

/* Boundary evidence: original MIPS .pdata 40b94334..40b9437f. Semantic name remains unreviewed. */

void FUN_40b94334(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40ba6b68;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40b9a0fc(param_1 + 6);
  return;
}



/* 40b94380 FUN_40b94380 */

/* Boundary evidence: original MIPS .pdata 40b94380..40b94417. Semantic name remains unreviewed. */

undefined4 FUN_40b94380(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40ba5058,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40ba6f90,0x10), iVar2 == 0)) {
      uVar1 = FUN_40b98690(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b94418 FUN_40b94418 */

/* Boundary evidence: original MIPS .pdata 40b94418..40b94433. Semantic name remains unreviewed. */

void FUN_40b94418(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40b94434 FUN_40b94434 */

/* Boundary evidence: original MIPS .pdata 40b94434..40b9448f. Semantic name remains unreviewed. */

LONG FUN_40b94434(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40b94490 FUN_40b94490 */

/* Boundary evidence: original MIPS .pdata 40b94490..40b944ef. Semantic name remains unreviewed. */

undefined4 FUN_40b94490(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40b99e84((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40b944f0 FUN_40b944f0 */

/* Boundary evidence: original MIPS .pdata 40b944f0..40b94547. Semantic name remains unreviewed. */

undefined4 FUN_40b944f0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40b94548 FUN_40b94548 */

/* Boundary evidence: original MIPS .pdata 40b94548..40b945df. Semantic name remains unreviewed. */

undefined4 FUN_40b94548(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40ba5068,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40ba6f90,0x10), iVar2 == 0)) {
      uVar1 = FUN_40b98690(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40b945e0 FUN_40b945e0 */

/* Boundary evidence: original MIPS .pdata 40b945e0..40b945fb. Semantic name remains unreviewed. */

void FUN_40b945e0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40b945fc FUN_40b945fc */

/* Boundary evidence: original MIPS .pdata 40b945fc..40b94657. Semantic name remains unreviewed. */

LONG FUN_40b945fc(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40b94658 FUN_40b94658 */

/* Boundary evidence: original MIPS .pdata 40b94658..40b94697. Semantic name remains unreviewed. */

undefined4 FUN_40b94658(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40b94698 FUN_40b94698 */

/* Boundary evidence: original MIPS .pdata 40b94698..40b946db. Semantic name remains unreviewed. */

void FUN_40b94698(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40b9962c(param_1 + 0x1c);
  FUN_40b985a0();
  return;
}



/* 40b946dc FUN_40b946dc */

/* Boundary evidence: original MIPS .pdata 40b946dc..40b94783. Semantic name remains unreviewed. */

void FUN_40b946dc(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ba5048,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40ba5188,0x10);
    if (iVar1 != 0) {
      FUN_40b9872c(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40b98690(piVar2,param_3);
  return;
}



/* 40b94784 FUN_40b94784 */

/* Boundary evidence: original MIPS .pdata 40b94784..40b947af. Semantic name remains unreviewed. */

void FUN_40b94784(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40b947b0 FUN_40b947b0 */

/* Boundary evidence: original MIPS .pdata 40b947b0..40b947db. Semantic name remains unreviewed. */

void FUN_40b947b0(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40b947dc FUN_40b947dc */

/* Boundary evidence: original MIPS .pdata 40b947dc..40b947fb. Semantic name remains unreviewed. */

undefined4 FUN_40b947dc(int param_1,void *param_2)

{
  FUN_40b9976c((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40b947fc FUN_40b947fc */

/* Boundary evidence: original MIPS .pdata 40b947fc..40b94853. Semantic name remains unreviewed. */

undefined4 FUN_40b947fc(int param_1,int *param_2)

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



/* 40b94854 FUN_40b94854 */

/* Boundary evidence: original MIPS .pdata 40b94854..40b948a7. Semantic name remains unreviewed. */

undefined4 FUN_40b94854(int param_1,int *param_2)

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



/* 40b948a8 FUN_40b948a8 */

/* Boundary evidence: original MIPS .pdata 40b948a8..40b94953. Semantic name remains unreviewed. */

undefined4 FUN_40b948a8(int param_1,int *param_2)

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
      FUN_40b98c2c((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40b9497c FUN_40b9497c */

/* Boundary evidence: original MIPS .pdata 40b9497c..40b949c3. Semantic name remains unreviewed. */

int FUN_40b9497c(int param_1,int param_2)

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



/* 40b949cc FUN_40b949cc */

/* Boundary evidence: original MIPS .pdata 40b949cc..40b94a1b. Semantic name remains unreviewed. */

undefined4 FUN_40b949cc(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b94a4c FUN_40b94a4c */

/* Boundary evidence: original MIPS .pdata 40b94a4c..40b94a73. Semantic name remains unreviewed. */

void FUN_40b94a4c(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40b94a74 FUN_40b94a74 */

/* Boundary evidence: original MIPS .pdata 40b94a74..40b94adb. Semantic name remains unreviewed. */

int FUN_40b94a74(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40b947fc(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40ba5118,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b94adc FUN_40b94adc */

/* Boundary evidence: original MIPS .pdata 40b94adc..40b94b3f. Semantic name remains unreviewed. */

undefined4 FUN_40b94adc(int param_1)

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



/* 40b94b40 FUN_40b94b40 */

/* Boundary evidence: original MIPS .pdata 40b94b40..40b94b7b. Semantic name remains unreviewed. */

void FUN_40b94b40(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40ba61e8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ba50f8,param_2);
  return;
}



/* 40b94b7c FUN_40b94b7c */

/* Boundary evidence: original MIPS .pdata 40b94b7c..40b94d07. Semantic name remains unreviewed. */

int FUN_40b94b7c(int *param_1,int *param_2,int *param_3)

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



/* 40b94d08 FUN_40b94d08 */

/* Boundary evidence: original MIPS .pdata 40b94d08..40b94d4f. Semantic name remains unreviewed. */

undefined4 FUN_40b94d08(int param_1)

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



/* 40b94d50 FUN_40b94d50 */

/* Boundary evidence: original MIPS .pdata 40b94d50..40b94d8f. Semantic name remains unreviewed. */

undefined4 FUN_40b94d50(int param_1)

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



/* 40b94d90 FUN_40b94d90 */

/* Boundary evidence: original MIPS .pdata 40b94d90..40b94dcf. Semantic name remains unreviewed. */

undefined4 FUN_40b94d90(int param_1)

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



/* 40b94dd0 FUN_40b94dd0 */

/* Boundary evidence: original MIPS .pdata 40b94dd0..40b94e0f. Semantic name remains unreviewed. */

undefined4 FUN_40b94dd0(int param_1)

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



/* 40b94e10 FUN_40b94e10 */

/* Boundary evidence: original MIPS .pdata 40b94e10..40b94e5b. Semantic name remains unreviewed. */

bool FUN_40b94e10(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40b94e68 FUN_40b94e68 */

/* Boundary evidence: original MIPS .pdata 40b94e68..40b94eb3. Semantic name remains unreviewed. */

bool FUN_40b94e68(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40b94eb4 FUN_40b94eb4 */

/* Boundary evidence: original MIPS .pdata 40b94eb4..40b94f0f. Semantic name remains unreviewed. */

undefined4 FUN_40b94eb4(int param_1)

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



/* 40b94f10 FUN_40b94f10 */

/* Boundary evidence: original MIPS .pdata 40b94f10..40b94f57. Semantic name remains unreviewed. */

void FUN_40b94f10(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40b94698(param_1);
  return;
}



/* 40b94f58 FUN_40b94f58 */

/* Boundary evidence: original MIPS .pdata 40b94f58..40b94fd7. Semantic name remains unreviewed. */

void FUN_40b94f58(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ba5118,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b98690(piVar2,param_3);
  }
  else {
    FUN_40b946dc(param_1,param_2,param_3);
  }
  return;
}



/* 40b94fd8 FUN_40b94fd8 */

/* Boundary evidence: original MIPS .pdata 40b94fd8..40b9509f. Semantic name remains unreviewed. */

HRESULT FUN_40b94fd8(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40ba61e8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ba50f8,ppv),
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



/* 40b950a0 FUN_40b950a0 */

/* Boundary evidence: original MIPS .pdata 40b950a0..40b9513f. Semantic name remains unreviewed. */

undefined4 FUN_40b950a0(int param_1,int *param_2,undefined1 param_3)

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



/* 40b95140 FUN_40b95140 */

/* Boundary evidence: original MIPS .pdata 40b95140..40b951db. Semantic name remains unreviewed. */

int FUN_40b95140(int *param_1,int param_2,int param_3,int *param_4)

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



/* 40b951dc FUN_40b951dc */

/* Boundary evidence: original MIPS .pdata 40b951dc..40b95223. Semantic name remains unreviewed. */

undefined4 FUN_40b951dc(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b95224 FUN_40b95224 */

/* Boundary evidence: original MIPS .pdata 40b95224..40b95267. Semantic name remains unreviewed. */

undefined4 FUN_40b95224(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40b95288 FUN_40b95288 */

/* Boundary evidence: original MIPS .pdata 40b95288..40b952c7. Semantic name remains unreviewed. */

undefined4 FUN_40b95288(int param_1)

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



/* 40b9531c FUN_40b9531c */

/* Boundary evidence: original MIPS .pdata 40b9531c..40b953bf. Semantic name remains unreviewed. */

undefined4 FUN_40b9531c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ba50d8,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40ba50e8,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40ba6f90,0x10), iVar1 == 0)) {
    uVar2 = FUN_40b98690(param_1,param_3);
  }
  else {
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 40b953c0 FUN_40b953c0 */

/* Boundary evidence: original MIPS .pdata 40b953c0..40b953db. Semantic name remains unreviewed. */

void FUN_40b953c0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x44));
  return;
}



/* 40b953dc FUN_40b953dc */

/* Boundary evidence: original MIPS .pdata 40b953dc..40b95483. Semantic name remains unreviewed. */

LONG FUN_40b953dc(int *param_1)

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



/* 40b95774 FUN_40b95774 */

/* Boundary evidence: original MIPS .pdata 40b95774..40b957cb. Semantic name remains unreviewed. */

undefined4 FUN_40b95774(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
  if ((*(uint *)(param_1 + 4) & 8) == 0) {
    *param_2 = 0;
    uVar1 = 1;
  }
  else {
    pvVar2 = FUN_40b99a28(*(void **)(param_1 + 0x3c));
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



/* 40b957cc FUN_40b957cc */

/* Boundary evidence: original MIPS .pdata 40b957cc..40b9585b. Semantic name remains unreviewed. */

undefined4 FUN_40b957cc(int param_1,void *param_2)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
  if (*(LPVOID *)(param_1 + 0x3c) != (LPVOID)0x0) {
    FUN_40b999e8(*(LPVOID *)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (param_2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    pvVar2 = FUN_40b99a28(param_2);
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



/* 40b9585c FUN_40b9585c */

/* Boundary evidence: original MIPS .pdata 40b9585c..40b95947. Semantic name remains unreviewed. */

undefined4 FUN_40b9585c(int param_1,size_t param_2,void *param_3)

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



/* 40b95948 FUN_40b95948 */

/* Boundary evidence: original MIPS .pdata 40b95948..40b95bc3. Semantic name remains unreviewed. */

undefined4 FUN_40b95948(int param_1,uint param_2,uint *param_3)

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
      pvVar2 = FUN_40b99a28((void *)param_3[9]);
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
        FUN_40b999e8(*(LPVOID *)(param_1 + 0x3c));
      }
      *(LPVOID *)(param_1 + 0x3c) = pvVar2;
    }
  }
  return 0;
}



/* 40b95bc4 FUN_40b95bc4 */

/* Boundary evidence: original MIPS .pdata 40b95bc4..40b95c0f. Semantic name remains unreviewed. */

void FUN_40b95bc4(int param_1)

{
  if (*(HANDLE *)(param_1 + 0x2c) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x2c));
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  FUN_40b985a0();
  return;
}



/* 40b95c10 FUN_40b95c10 */

/* Boundary evidence: original MIPS .pdata 40b95c10..40b95cab. Semantic name remains unreviewed. */

void FUN_40b95c10(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ba5108,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40ba50f8,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40b98690(piVar2,param_3);
  }
  else {
    FUN_40b9872c(param_1,param_2,param_3);
  }
  return;
}



/* 40b95cac FUN_40b95cac */

/* Boundary evidence: original MIPS .pdata 40b95cac..40b95d33. Semantic name remains unreviewed. */

undefined4 FUN_40b95cac(int param_1,undefined4 *param_2)

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



/* 40b95d34 FUN_40b95d34 */

/* Boundary evidence: original MIPS .pdata 40b95d34..40b95e4b. Semantic name remains unreviewed. */

undefined4 FUN_40b95d34(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5)

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



/* 40b95e4c FUN_40b95e4c */

/* Boundary evidence: original MIPS .pdata 40b95e4c..40b95eb3. Semantic name remains unreviewed. */

undefined4 FUN_40b95e4c(int param_1,int *param_2)

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



/* 40b95eb4 FUN_40b95eb4 */

/* Boundary evidence: original MIPS .pdata 40b95eb4..40b95f13. Semantic name remains unreviewed. */

undefined4 FUN_40b95eb4(int param_1,undefined4 *param_2)

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



/* 40b95f14 FUN_40b95f14 */

/* Boundary evidence: original MIPS .pdata 40b95f14..40b95f57. Semantic name remains unreviewed. */

void FUN_40b95f14(int param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x2c),*(int *)(param_1 + 0x30),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  return;
}



/* 40b95f58 FUN_40b95f58 */

/* Boundary evidence: original MIPS .pdata 40b95f58..40b9601f. Semantic name remains unreviewed. */

int FUN_40b95f58(int *param_1)

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
      goto LAB_40b95ffc;
    }
    (**(code **)(*param_1 + 4))(param_1);
  }
  else {
    param_1[0x11] = 0;
  }
  iVar1 = 0;
LAB_40b95ffc:
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40b96020 FUN_40b96020 */

/* Boundary evidence: original MIPS .pdata 40b96020..40b960f7. Semantic name remains unreviewed. */

undefined4 FUN_40b96020(int *param_1)

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
    FUN_40b95f14((int)(param_1 + -3));
    LeaveCriticalSection(lpCriticalSection);
    if (iVar1 <= iVar3) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  return 0;
}



/* 40b960f8 FUN_40b960f8 */

undefined4 FUN_40b960f8(int param_1)

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



/* 40b96148 FUN_40b96148 */

void FUN_40b96148(int *param_1,int param_2)

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



/* 40b96198 FUN_40b96198 */

/* Boundary evidence: original MIPS .pdata 40b96198..40b96343. Semantic name remains unreviewed. */

undefined4 FUN_40b96198(int param_1,undefined4 *param_2,undefined4 *param_3)

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



/* 40b9634c FUN_40b9634c */

/* Boundary evidence: original MIPS .pdata 40b9634c..40b963bf. Semantic name remains unreviewed. */

void FUN_40b9634c(int param_1)

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



/* 40b963c0 FUN_40b963c0 */

/* Boundary evidence: original MIPS .pdata 40b963c0..40b9640f. Semantic name remains unreviewed. */

void FUN_40b963c0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40ba6c2c;
  param_1[3] = &PTR_FUN_40ba6c00;
  FUN_40b96020(param_1 + 3);
  FUN_40b9634c((int)param_1);
  FUN_40b95bc4((int)param_1);
  return;
}



/* 40b96410 FUN_40b96410 */

/* Boundary evidence: original MIPS .pdata 40b96410..40b96667. Semantic name remains unreviewed. */

int FUN_40b96410(undefined4 *param_1,int *param_2,int param_3)

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
              if (iVar1 < 0) goto LAB_40b96630;
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
LAB_40b96630:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40b96668 FUN_40b96668 */

/* Boundary evidence: original MIPS .pdata 40b96668..40b96747. Semantic name remains unreviewed. */

void FUN_40b96668(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40ba50a8,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40ba5098,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40ba6fa0,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40ba5128,0x10);
    if (iVar1 != 0) {
      FUN_40b9872c(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40b98690(piVar2,param_3);
  return;
}



/* 40b96748 FUN_40b96748 */

/* Boundary evidence: original MIPS .pdata 40b96748..40b967a3. Semantic name remains unreviewed. */

void FUN_40b96748(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40b985a0();
  return;
}



/* 40b967a4 FUN_40b967a4 */

/* Boundary evidence: original MIPS .pdata 40b967a4..40b96827. Semantic name remains unreviewed. */

undefined4 FUN_40b967a4(int param_1,int *param_2)

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



/* 40b96828 FUN_40b96828 */

/* Boundary evidence: original MIPS .pdata 40b96828..40b968ab. Semantic name remains unreviewed. */

undefined4 FUN_40b96828(int param_1,undefined4 *param_2)

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



/* 40b968ac FUN_40b968ac */

/* Boundary evidence: original MIPS .pdata 40b968ac..40b96933. Semantic name remains unreviewed. */

int FUN_40b968ac(int param_1,uint *param_2)

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



/* 40b96934 FUN_40b96934 */

/* Boundary evidence: original MIPS .pdata 40b96934..40b96a4b. Semantic name remains unreviewed. */

undefined4 FUN_40b96934(int param_1,LPCWSTR param_2,int *param_3)

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
          goto LAB_40b969f4;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40b969f4:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40b96a4c FUN_40b96a4c */

/* Boundary evidence: original MIPS .pdata 40b96a4c..40b96b67. Semantic name remains unreviewed. */

undefined4 FUN_40b96a4c(int param_1,undefined4 *param_2,wchar_t *param_3)

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
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40ba51b8,(undefined4 *)(param_1 + 0x38));
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



/* 40b96b68 FUN_40b96b68 */

/* Boundary evidence: original MIPS .pdata 40b96b68..40b96c3b. Semantic name remains unreviewed. */

undefined4 FUN_40b96b68(int param_1)

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
    HVar3 = CoCreateInstance((IID *)&DAT_40ba5ca8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ba5178,local_10);
    if (-1 < HVar3) {
      FUN_40b96410(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b96c3c FUN_40b96c3c */

/* Boundary evidence: original MIPS .pdata 40b96c3c..40b96d2f. Semantic name remains unreviewed. */

int FUN_40b96c3c(int param_1)

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
    HVar2 = CoCreateInstance((IID *)&DAT_40ba5ca8,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ba5178,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40b96410(puVar1,local_18[0],0);
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



/* 40b96d30 FUN_40b96d30 */

/* Boundary evidence: original MIPS .pdata 40b96d30..40b96d7b. Semantic name remains unreviewed. */

undefined4 * FUN_40b96d30(undefined4 *param_1,uint param_2)

{
  FUN_40b94334(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b96d7c FUN_40b96d7c */

/* Boundary evidence: original MIPS .pdata 40b96d7c..40b96f13. Semantic name remains unreviewed. */

undefined4 FUN_40b96d7c(int param_1,uint param_2,int *param_3,uint *param_4)

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
    bVar1 = FUN_40b94e10(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40b944f0(param_1);
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
        iVar3 = FUN_40b99f00((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40b9a000((int *)(param_1 + 0x18),iVar2);
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



/* 40b96f14 FUN_40b96f14 */

/* Boundary evidence: original MIPS .pdata 40b96f14..40b96f8f. Semantic name remains unreviewed. */

undefined4 FUN_40b96f14(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40b94e10(param_1);
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



/* 40b96f90 FUN_40b96f90 */

/* Boundary evidence: original MIPS .pdata 40b96f90..40b96ff3. Semantic name remains unreviewed. */

undefined4 * FUN_40b96f90(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40ba6b88;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b96ff4 FUN_40b96ff4 */

/* Boundary evidence: original MIPS .pdata 40b96ff4..40b97187. Semantic name remains unreviewed. */

uint FUN_40b96ff4(int param_1,uint param_2,undefined4 *param_3,int *param_4)

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
  
  local_28 = DAT_40ba9854;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40b9bea4(DAT_40ba9854);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40b94e68(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40b9bea4(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40b9bea4(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40b99648(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40b97134:
          FUN_40b9962c((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40b97134;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40b9962c((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40b9bea4(local_28);
    }
  }
  return uVar3;
}



/* 40b97188 FUN_40b97188 */

/* Boundary evidence: original MIPS .pdata 40b97188..40b9723f. Semantic name remains unreviewed. */

uint FUN_40b97188(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40ba9854;
  bVar1 = FUN_40b94e68(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40b9bea4(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40b99648(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40b9962c((int)auStack_60);
    FUN_40b9bea4(local_18);
  }
  return uVar3;
}



/* 40b97240 FUN_40b97240 */

/* Boundary evidence: original MIPS .pdata 40b97240..40b973b7. Semantic name remains unreviewed. */

int FUN_40b97240(int *param_1,int *param_2,undefined4 param_3)

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



/* 40b973b8 FUN_40b973b8 */

/* Boundary evidence: original MIPS .pdata 40b973b8..40b9752b. Semantic name remains unreviewed. */

int FUN_40b973b8(int *param_1,int *param_2,void *param_3,int *param_4)

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
             (iVar3 = FUN_40b998d4(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40b97240(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40b999e8(local_28);
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



/* 40b9752c FUN_40b9752c */

/* Boundary evidence: original MIPS .pdata 40b9752c..40b976b3. Semantic name remains unreviewed. */

int FUN_40b9752c(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40b99868(param_3), iVar1 == 0)) {
    iVar1 = FUN_40b97240(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40b973b8(param_1,param_2,param_3,local_30[0]);
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
  iVar2 = FUN_40b973b8(param_1,param_2,param_3,local_30[0]);
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



/* 40b976b4 FUN_40b976b4 */

/* Boundary evidence: original MIPS .pdata 40b976b4..40b9787b. Semantic name remains unreviewed. */

int FUN_40b976b4(int param_1,int *param_2,int param_3)

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
          goto LAB_40b9784c;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40b9784c;
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
LAB_40b9784c:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40b9787c FUN_40b9787c */

/* Boundary evidence: original MIPS .pdata 40b9787c..40b9791b. Semantic name remains unreviewed. */

undefined4 FUN_40b9787c(int param_1)

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



/* 40b9791c FUN_40b9791c */

/* Boundary evidence: original MIPS .pdata 40b9791c..40b979a7. Semantic name remains unreviewed. */

undefined4 FUN_40b9791c(int param_1,void *param_2)

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
      FUN_40b994f8(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40b99534(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40b979a8 FUN_40b979a8 */

/* Boundary evidence: original MIPS .pdata 40b979a8..40b979c3. Semantic name remains unreviewed. */

void FUN_40b979a8(int param_1,undefined4 *param_2)

{
  FUN_40b99084(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40b979c4 FUN_40b979c4 */

/* Boundary evidence: original MIPS .pdata 40b979c4..40b97a3f. Semantic name remains unreviewed. */

int FUN_40b979c4(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40b9787c(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40b97a40 FUN_40b97a40 */

/* Boundary evidence: original MIPS .pdata 40b97a40..40b97a9f. Semantic name remains unreviewed. */

undefined4 * FUN_40b97a40(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40ba6ba8;
  if ((LPVOID)param_1[0xf] != (LPVOID)0x0) {
    FUN_40b999e8((LPVOID)param_1[0xf]);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b97aa0 FUN_40b97aa0 */

/* Boundary evidence: original MIPS .pdata 40b97aa0..40b97b8f. Semantic name remains unreviewed. */

undefined4 FUN_40b97aa0(int *param_1,int param_2)

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
      FUN_40b95f14((int)(param_1 + -3));
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



/* 40b97b90 FUN_40b97b90 */

/* Boundary evidence: original MIPS .pdata 40b97b90..40b97bdb. Semantic name remains unreviewed. */

undefined4 * FUN_40b97b90(undefined4 *param_1,uint param_2)

{
  FUN_40b963c0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b97bdc FUN_40b97bdc */

/* Boundary evidence: original MIPS .pdata 40b97bdc..40b97c5f. Semantic name remains unreviewed. */

undefined4 *
FUN_40b97bdc(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40b986d0(param_1,param_2,param_3);
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



/* 40b97c60 FUN_40b97c60 */

/* Boundary evidence: original MIPS .pdata 40b97c60..40b97d3f. Semantic name remains unreviewed. */

undefined4 * FUN_40b97c60(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40ba6b68;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40b99e60(param_1 + 6);
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
    FUN_40b9a09c(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40b97d40 FUN_40b97d40 */

/* Boundary evidence: original MIPS .pdata 40b97d40..40b97deb. Semantic name remains unreviewed. */

undefined4 FUN_40b97d40(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40b94e10(param_1);
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
        puVar2 = FUN_40b97c60(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40b97dec FUN_40b97dec */

/* Boundary evidence: original MIPS .pdata 40b97dec..40b97e7b. Semantic name remains unreviewed. */

undefined4 * FUN_40b97dec(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40ba6b88;
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



/* 40b97e7c FUN_40b97e7c */

/* Boundary evidence: original MIPS .pdata 40b97e7c..40b97f27. Semantic name remains unreviewed. */

undefined4 FUN_40b97e7c(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40b94e68(param_1);
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
        puVar2 = FUN_40b97dec(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40b97f28 FUN_40b97f28 */

/* Boundary evidence: original MIPS .pdata 40b97f28..40b9801b. Semantic name remains unreviewed. */

undefined4 *
FUN_40b97f28(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40b986d0(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40b99648(param_1 + 7);
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



/* 40b9801c FUN_40b9801c */

/* Boundary evidence: original MIPS .pdata 40b9801c..40b980fb. Semantic name remains unreviewed. */

int FUN_40b9801c(int param_1,int *param_2,void *param_3)

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
        iVar1 = FUN_40b9752c(piVar2,param_2,param_3);
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



/* 40b980fc FUN_40b980fc */

/* Boundary evidence: original MIPS .pdata 40b980fc..40b9817b. Semantic name remains unreviewed. */

undefined4 FUN_40b980fc(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40b97dec(puVar2,param_1 + -0xc,0);
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



/* 40b9817c FUN_40b9817c */

/* Boundary evidence: original MIPS .pdata 40b9817c..40b981c7. Semantic name remains unreviewed. */

undefined4 *
FUN_40b9817c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40b97f28(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40b981c8 FUN_40b981c8 */

/* Boundary evidence: original MIPS .pdata 40b981c8..40b98223. Semantic name remains unreviewed. */

undefined4 *
FUN_40b981c8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40b97f28(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40b98224 FUN_40b98224 */

/* Boundary evidence: original MIPS .pdata 40b98224..40b982a3. Semantic name remains unreviewed. */

undefined4 FUN_40b98224(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40b97c60(puVar2,param_1 + -0xc,0);
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



/* 40b982a4 FUN_40b982a4 */

/* Boundary evidence: original MIPS .pdata 40b982a4..40b9834f. Semantic name remains unreviewed. */

undefined4 *
FUN_40b982a4(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
            int param_5)

{
  HANDLE pvVar1;
  
  FUN_40b986d0(param_1,param_2,param_3);
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



/* 40b98350 FUN_40b98350 */

/* Boundary evidence: original MIPS .pdata 40b98350..40b9839f. Semantic name remains unreviewed. */

undefined4 *
FUN_40b98350(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  FUN_40b982a4(param_1,param_2,param_3,param_4,1);
  *param_1 = &PTR_FUN_40ba6c2c;
  param_1[3] = &PTR_FUN_40ba6c00;
  param_1[0x15] = 0;
  return param_1;
}



/* 40b983a0 FUN_40b983a0 */

/* Boundary evidence: original MIPS .pdata 40b983a0..40b9856f. Semantic name remains unreviewed. */

int FUN_40b983a0(int param_1)

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
  iVar1 = FUN_40b960f8(param_1);
  if (-1 < iVar1) {
    if (iVar1 != 1) {
      if (*(int *)(param_1 + 0x54) != 0) {
        FUN_40b9634c(param_1);
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
LAB_40b98488:
        iVar1 = -0x7ff8fff2;
        goto LAB_40b98544;
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
            *puVar3 = &PTR_FUN_40ba6ba8;
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
          if (puVar3 == (undefined4 *)0x0) goto LAB_40b98488;
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
LAB_40b98544:
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40b98570 FUN_40b98570 */

/* Boundary evidence: original MIPS .pdata 40b98570..40b9859f. Semantic name remains unreviewed. */

undefined4 FUN_40b98570(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40bab800);
  return param_1;
}



/* 40b985a0 FUN_40b985a0 */

/* Boundary evidence: original MIPS .pdata 40b985a0..40b985f7. Semantic name remains unreviewed. */

void FUN_40b985a0(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40bab800);
  if ((LVar1 == 0) && (DAT_40bab7fc != 0)) {
    FreeLibrary((HMODULE)DAT_40bab7fc);
    DAT_40bab7fc = 0;
  }
  return;
}



/* 40b985f8 FUN_40b985f8 */

/* Boundary evidence: original MIPS .pdata 40b985f8..40b98633. Semantic name remains unreviewed. */

void FUN_40b985f8(void)

{
  if (DAT_40bab7fc == (HMODULE)0x0) {
    DAT_40bab7fc = LoadLibraryW(L"OleAut32.dll");
  }
  return;
}



/* 40b98634 FUN_40b98634 */

/* Boundary evidence: original MIPS .pdata 40b98634..40b9868f. Semantic name remains unreviewed. */

undefined4 * FUN_40b98634(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40ba6c60;
  InterlockedIncrement(&DAT_40bab800);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40b98690 FUN_40b98690 */

/* Boundary evidence: original MIPS .pdata 40b98690..40b986cf. Semantic name remains unreviewed. */

undefined4 FUN_40b98690(int *param_1,undefined4 *param_2)

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



/* 40b986d0 FUN_40b986d0 */

/* Boundary evidence: original MIPS .pdata 40b986d0..40b9872b. Semantic name remains unreviewed. */

undefined4 * FUN_40b986d0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40ba6c60;
  InterlockedIncrement(&DAT_40bab800);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40b9872c FUN_40b9872c */

/* Boundary evidence: original MIPS .pdata 40b9872c..40b987af. Semantic name remains unreviewed. */

undefined4 FUN_40b9872c(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40ba6f90,0x10);
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



/* 40b987b0 FUN_40b987b0 */

/* Boundary evidence: original MIPS .pdata 40b987b0..40b987eb. Semantic name remains unreviewed. */

uint FUN_40b987b0(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40b987ec FUN_40b987ec */

/* Boundary evidence: original MIPS .pdata 40b987ec..40b98863. Semantic name remains unreviewed. */

uint FUN_40b987ec(int *param_1)

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



/* 40b98864 FUN_40b98864 */

/* Boundary evidence: original MIPS .pdata 40b98864..40b98b23. Semantic name remains unreviewed. */

void FUN_40b98864(undefined4 param_1,int param_2)

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
  
  if (DAT_40ba9844 == 0xffffffff) {
    DAT_40ba9848 = 0xfa;
    DAT_40ba9844 = 0xf9;
    DAT_40ba984c = 0xfb;
    DAT_40ba9850 = 0xfc;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,0,
                          &local_30);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Highest",(LPDWORD)0x0,&local_34,(LPBYTE)&local_28,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_28)) {
        local_28 = DAT_40ba9844;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"AboveNormal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_2c,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_2c)) {
        local_2c = DAT_40ba9848;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Normal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_24,&local_38
                              );
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_24)) {
        local_24 = DAT_40ba984c;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"BelowNormal",(LPDWORD)0x0,&local_34,(LPBYTE)local_20,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_20[0])) {
        local_20[0] = DAT_40ba9850;
      }
      if (((local_28 <= local_2c) && (local_2c <= local_24)) && (local_24 <= local_20[0])) {
        DAT_40ba9844 = local_28;
        DAT_40ba9848 = local_2c;
        DAT_40ba984c = local_24;
        DAT_40ba9850 = local_20[0];
      }
      RegCloseKey(local_30);
    }
  }
  uVar2 = DAT_40ba9844;
  if (((param_2 != 1) && (uVar2 = DAT_40ba9848, param_2 != 2)) &&
     (uVar2 = DAT_40ba9850, param_2 != 4)) {
    uVar2 = DAT_40ba984c;
  }
  CeSetThreadPriority(param_1,uVar2);
  return;
}



/* 40b98b24 FUN_40b98b24 */

/* Boundary evidence: original MIPS .pdata 40b98b24..40b98b63. Semantic name remains unreviewed. */

undefined4 * FUN_40b98b24(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



/* 40b98b64 FUN_40b98b64 */

/* Boundary evidence: original MIPS .pdata 40b98b64..40b98b93. Semantic name remains unreviewed. */

void FUN_40b98b64(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40b98b94 FUN_40b98b94 */

/* Boundary evidence: original MIPS .pdata 40b98b94..40b98bb7. Semantic name remains unreviewed. */

void FUN_40b98b94(undefined4 *param_1)

{
  (**(code **)*param_1)();
  return;
}



/* 40b98bb8 FUN_40b98bb8 */

/* Boundary evidence: original MIPS .pdata 40b98bb8..40b98c2b. Semantic name remains unreviewed. */

undefined4 FUN_40b98bb8(void)

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



/* 40b98c2c FUN_40b98c2c */

short * FUN_40b98c2c(short *param_1,short *param_2,int param_3)

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



/* 40b98c68 FUN_40b98c68 */

/* WARNING: Removing unreachable block (ram,0x40b98edc) */
/* Boundary evidence: original MIPS .pdata 40b98c68..40b99083. Semantic name remains unreviewed. */

int FUN_40b98c68(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
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
  if (param_7 == 0 && param_8 == 0) goto LAB_40b98ea4;
  iVar11 = iVar8;
  if (bVar2) {
    uVar15 = -param_7;
    uVar12 = -(uint)(param_7 != 0) - param_8;
    if ((int)param_8 < 0) goto LAB_40b98dec;
    bVar1 = param_8 == 0;
    param_8 = param_7;
    if (bVar1) goto joined_r0x40b98e54;
  }
  else {
    uVar15 = param_7;
    uVar12 = param_8;
    if ((int)param_8 < 1) {
joined_r0x40b98e54:
      if (param_8 != 0) goto LAB_40b98df4;
    }
LAB_40b98dec:
    iVar11 = 0;
  }
LAB_40b98df4:
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
LAB_40b98ea4:
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



/* 40b99084 FUN_40b99084 */

/* Boundary evidence: original MIPS .pdata 40b99084..40b9910f. Semantic name remains unreviewed. */

undefined4 FUN_40b99084(wchar_t *param_1,undefined4 *param_2)

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



/* 40b99110 FUN_40b99110 */

/* Boundary evidence: original MIPS .pdata 40b99110..40b9918b. Semantic name remains unreviewed. */

int FUN_40b99110(int param_1)

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



/* 40b9918c FUN_40b9918c */

/* Boundary evidence: original MIPS .pdata 40b9918c..40b991fb. Semantic name remains unreviewed. */

void FUN_40b9918c(int param_1)

{
  FUN_40b83c70(param_1);
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



/* 40b991fc FUN_40b991fc */

/* Boundary evidence: original MIPS .pdata 40b991fc..40b992af. Semantic name remains unreviewed. */

bool FUN_40b991fc(LPVOID param_1)

{
  HANDLE pvVar1;
  bool bVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD aDStack_18 [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)param_1 + 0x14) == 0) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40b98b94,param_1,0,aDStack_18);
    if (pvVar1 != (HANDLE)0x0) {
      FUN_40b98864(pvVar1,3);
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



/* 40b992b0 FUN_40b992b0 */

/* Boundary evidence: original MIPS .pdata 40b992b0..40b9933b. Semantic name remains unreviewed. */

undefined4 FUN_40b992b0(int param_1,undefined4 param_2)

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



/* 40b9933c FUN_40b9933c */

/* Boundary evidence: original MIPS .pdata 40b9933c..40b99373. Semantic name remains unreviewed. */

undefined4 FUN_40b9933c(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
  return *(undefined4 *)(param_1 + 0xc);
}



/* 40b99374 FUN_40b99374 */

/* Boundary evidence: original MIPS .pdata 40b99374..40b993d7. Semantic name remains unreviewed. */

undefined4 FUN_40b99374(int param_1,undefined4 *param_2)

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



/* 40b993d8 FUN_40b993d8 */

/* Boundary evidence: original MIPS .pdata 40b993d8..40b99413. Semantic name remains unreviewed. */

void FUN_40b993d8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  EventModify(*(undefined4 *)(param_1 + 4),2);
  EventModify(*(undefined4 *)(param_1 + 8),3);
  return;
}



/* 40b99414 FUN_40b99414 */

void FUN_40b99414(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x1c) = param_2[3];
  return;
}



/* 40b99438 FUN_40b99438 */

void FUN_40b99438(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = *param_2;
  *(undefined4 *)(param_1 + 0x30) = param_2[1];
  *(undefined4 *)(param_1 + 0x34) = param_2[2];
  *(undefined4 *)(param_1 + 0x38) = param_2[3];
  return;
}



/* 40b9945c FUN_40b9945c */

/* Boundary evidence: original MIPS .pdata 40b9945c..40b994f7. Semantic name remains unreviewed. */

LPVOID FUN_40b9945c(int param_1,uint param_2)

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



/* 40b994f8 FUN_40b994f8 */

/* Boundary evidence: original MIPS .pdata 40b994f8..40b99533. Semantic name remains unreviewed. */

void FUN_40b994f8(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40b99534 FUN_40b99534 */

/* Boundary evidence: original MIPS .pdata 40b99534..40b995c7. Semantic name remains unreviewed. */

void FUN_40b99534(void *param_1,void *param_2)

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



/* 40b995c8 FUN_40b995c8 */

/* Boundary evidence: original MIPS .pdata 40b995c8..40b9962b. Semantic name remains unreviewed. */

void FUN_40b995c8(int param_1)

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



/* 40b9962c FUN_40b9962c */

/* Boundary evidence: original MIPS .pdata 40b9962c..40b99647. Semantic name remains unreviewed. */

void FUN_40b9962c(int param_1)

{
  FUN_40b995c8(param_1);
  return;
}



/* 40b99648 FUN_40b99648 */

/* Boundary evidence: original MIPS .pdata 40b99648..40b99687. Semantic name remains unreviewed. */

void * FUN_40b99648(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40b99688 FUN_40b99688 */

/* Boundary evidence: original MIPS .pdata 40b99688..40b996f3. Semantic name remains unreviewed. */

undefined4 * FUN_40b99688(undefined4 *param_1,undefined4 *param_2)

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



/* 40b996f4 FUN_40b996f4 */

/* Boundary evidence: original MIPS .pdata 40b996f4..40b9971f. Semantic name remains unreviewed. */

void * FUN_40b996f4(void *param_1,void *param_2)

{
  FUN_40b99534(param_1,param_2);
  return param_1;
}



/* 40b99720 FUN_40b99720 */

/* Boundary evidence: original MIPS .pdata 40b99720..40b9976b. Semantic name remains unreviewed. */

void * FUN_40b99720(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40b995c8((int)param_1);
    FUN_40b99534(param_1,param_2);
  }
  return param_1;
}



/* 40b9976c FUN_40b9976c */

/* Boundary evidence: original MIPS .pdata 40b9976c..40b99797. Semantic name remains unreviewed. */

void * FUN_40b9976c(void *param_1,void *param_2)

{
  FUN_40b99720(param_1,param_2);
  return param_1;
}



/* 40b99798 FUN_40b99798 */

/* Boundary evidence: original MIPS .pdata 40b99798..40b99843. Semantic name remains unreviewed. */

undefined4 FUN_40b99798(void *param_1,void *param_2)

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



/* 40b99844 FUN_40b99844 */

void FUN_40b99844(int param_1,int param_2)

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



/* 40b99868 FUN_40b99868 */

/* Boundary evidence: original MIPS .pdata 40b99868..40b998d3. Semantic name remains unreviewed. */

undefined4 FUN_40b99868(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40ba6f70,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40ba6f70,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b998d4 FUN_40b998d4 */

/* Boundary evidence: original MIPS .pdata 40b998d4..40b999e7. Semantic name remains unreviewed. */

undefined4 FUN_40b998d4(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40ba6f70,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40ba6f70,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40ba6f70,0x10);
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



/* 40b999e8 FUN_40b999e8 */

/* Boundary evidence: original MIPS .pdata 40b999e8..40b99a27. Semantic name remains unreviewed. */

void FUN_40b999e8(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40b995c8((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40b99a28 FUN_40b99a28 */

/* Boundary evidence: original MIPS .pdata 40b99a28..40b99a83. Semantic name remains unreviewed. */

LPVOID FUN_40b99a28(void *param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = CoTaskMemAlloc(0x48);
  if (pvVar1 == (LPVOID)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    FUN_40b99534(pvVar1,param_1);
  }
  return pvVar1;
}



/* 40b99a84 FUN_40b99a84 */

/* Boundary evidence: original MIPS .pdata 40b99a84..40b99ab3. Semantic name remains unreviewed. */

void FUN_40b99a84(int *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
  }
  return;
}



/* 40b99ab4 FUN_40b99ab4 */

undefined4 FUN_40b99ab4(undefined4 param_1,undefined4 *param_2)

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



/* 40b99adc FUN_40b99adc */

/* Boundary evidence: original MIPS .pdata 40b99adc..40b99c77. Semantic name remains unreviewed. */

uint FUN_40b99adc(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

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
    iVar1 = FUN_40b985f8();
    if ((iVar1 == 0) ||
       (pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadRegTypeLib"), pcVar3 == (code *)0x0)) {
LAB_40b99b50:
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        return DVar2;
      }
      return DVar2 & 0xffff | 0x80070000;
    }
    iVar4 = (*pcVar3)(&UNK_40ba55a8,1,0,param_4,local_28);
    if (iVar4 < 0) {
      pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadTypeLib");
      if (pcVar3 == (code *)0x0) goto LAB_40b99b50;
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



/* 40b99c78 FUN_40b99c78 */

/* Boundary evidence: original MIPS .pdata 40b99c78..40b99e3f. Semantic name remains unreviewed. */

DWORD FUN_40b99c78(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
    iVar1 = FUN_40b985f8();
    if ((iVar1 == 0) ||
       (pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadRegTypeLib"), pcVar3 == (code *)0x0)) {
LAB_40b99ce4:
      DVar2 = GetLastError();
      if (0 < (int)DVar2) {
        DVar2 = DVar2 & 0xffff | 0x80070000;
      }
      goto LAB_40b99ddc;
    }
    iVar4 = (*pcVar3)(&UNK_40ba55a8,1,0,param_5,local_28);
    if (iVar4 < 0) {
      pcVar3 = (code *)GetProcAddressW(iVar1,L"LoadTypeLib");
      if (pcVar3 == (code *)0x0) goto LAB_40b99ce4;
      DVar2 = (*pcVar3)(L"control.tlb",local_28);
      if ((int)DVar2 < 0) goto LAB_40b99ddc;
    }
    DVar2 = (**(code **)(*local_28[0] + 0x18))(local_28[0],param_2,param_1);
    (**(code **)(*local_28[0] + 8))();
    if ((int)DVar2 < 0) goto LAB_40b99ddc;
  }
  piVar5 = (int *)*param_1;
  (**(code **)(*piVar5 + 4))(piVar5);
  DVar2 = 0;
LAB_40b99ddc:
  if (-1 < (int)DVar2) {
    DVar2 = (**(code **)(*piVar5 + 0x28))(piVar5,param_3,param_4,param_6);
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  return DVar2;
}



/* 40b99e40 FUN_40b99e40 */

undefined4 * FUN_40b99e40(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40b99e60 FUN_40b99e60 */

undefined4 * FUN_40b99e60(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40b99e84 FUN_40b99e84 */

/* Boundary evidence: original MIPS .pdata 40b99e84..40b99ed7. Semantic name remains unreviewed. */

void FUN_40b99e84(undefined4 *param_1)

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



/* 40b99ed8 FUN_40b99ed8 */

undefined4 FUN_40b99ed8(undefined4 param_1,int *param_2)

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



/* 40b99f00 FUN_40b99f00 */

int FUN_40b99f00(int *param_1,int param_2)

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



/* 40b99f44 FUN_40b99f44 */

/* Boundary evidence: original MIPS .pdata 40b99f44..40b99fff. Semantic name remains unreviewed. */

int FUN_40b99f44(int *param_1,int *param_2)

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



/* 40b9a000 FUN_40b9a000 */

/* Boundary evidence: original MIPS .pdata 40b9a000..40b9a09b. Semantic name remains unreviewed. */

undefined4 * FUN_40b9a000(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40b9a050;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40b9a050:
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



/* 40b9a09c FUN_40b9a09c */

/* Boundary evidence: original MIPS .pdata 40b9a09c..40b9a0fb. Semantic name remains unreviewed. */

undefined4 FUN_40b9a09c(undefined4 *param_1,int *param_2)

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
    puVar1 = FUN_40b9a000(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40b9a0fc FUN_40b9a0fc */

/* Boundary evidence: original MIPS .pdata 40b9a0fc..40b9a143. Semantic name remains unreviewed. */

void FUN_40b9a0fc(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40b99e84(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40b9a144 FUN_40b9a144 */

/* Boundary evidence: original MIPS .pdata 40b9a144..40b9a15f. Semantic name remains unreviewed. */

void FUN_40b9a144(int *param_1)

{
  FUN_40b99f44(param_1,(int *)*param_1);
  return;
}



/* 40b9a160 FUN_40b9a160 */

/* Boundary evidence: original MIPS .pdata 40b9a160..40b9a1a3. Semantic name remains unreviewed. */

void FUN_40b9a160(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x28),*(int *)(param_1 + 0x3c),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40b9a1a4 FUN_40b9a1a4 */

/* Boundary evidence: original MIPS .pdata 40b9a1a4..40b9a267. Semantic name remains unreviewed. */

void FUN_40b9a1a4(LPCRITICAL_SECTION param_1)

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
      FUN_40b9a160((int)param_1);
      LeaveCriticalSection(param_1);
      (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
      return;
    }
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40b9a268 FUN_40b9a268 */

/* Boundary evidence: original MIPS .pdata 40b9a268..40b9a2bf. Semantic name remains unreviewed. */

void FUN_40b9a268(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_40b9a000(*(undefined4 **)(param_1 + 0x24),param_2);
  if ((puVar1 == (undefined4 *)0x0) && (param_2 < (int *)0xfffffff1)) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



/* 40b9a2c0 FUN_40b9a2c0 */

/* Boundary evidence: original MIPS .pdata 40b9a2c0..40b9a55f. Semantic name remains unreviewed. */

LONG FUN_40b9a2c0(LPCRITICAL_SECTION param_1,undefined4 *param_2,int param_3,int *param_4)

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
        else if ((param_1[2].RecursionCount == 0) || (param_1[3].LockCount == 0)) goto LAB_40b9a380;
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
          FUN_40b9a268((int)param_1,(int *)*param_2);
          param_2 = param_2 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      *param_4 = param_3;
      if ((param_1[1].LockCount == 0) ||
         (param_1[1].RecursionCount <=
          param_1[2].RecursionCount + *(int *)((int)param_1[1].OwningThread + 8))) {
        FUN_40b9a160((int)param_1);
      }
      LVar1 = 0;
      goto LAB_40b9a528;
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
  goto LAB_40b9a390;
LAB_40b9a380:
  *param_4 = iVar2 - iVar3;
  if (iVar2 - iVar3 < 0) {
    *param_4 = 0;
  }
LAB_40b9a390:
  LVar1 = param_1[3].RecursionCount;
LAB_40b9a528:
  LeaveCriticalSection(param_1);
  return LVar1;
}



/* 40b9a560 FUN_40b9a560 */

/* Boundary evidence: original MIPS .pdata 40b9a560..40b9a657. Semantic name remains unreviewed. */

void FUN_40b9a560(LPCRITICAL_SECTION param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  EnterCriticalSection(param_1);
  piVar2 = param_1[1].OwningThread;
  if (piVar2 != (int *)0x0) {
    while (piVar2 = (int *)FUN_40b9a144(piVar2), piVar2 != (int *)0x0) {
      if (piVar2 < (int *)0xfffffff1) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      else if (piVar2 == (int *)0xfffffffb) {
        pvVar1 = (void *)FUN_40b9a144(param_1[1].OwningThread);
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



/* 40b9a658 FUN_40b9a658 */

/* Boundary evidence: original MIPS .pdata 40b9a658..40b9a753. Semantic name remains unreviewed. */

void FUN_40b9a658(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  
  if (param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    (**(code **)(*(int *)param_1[1].DebugInfo + 8))();
  }
  if (param_1[2].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    FUN_40b9a560(param_1);
  }
  else {
    EnterCriticalSection(param_1);
    param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1;
    param_1[3].RecursionCount = 1;
    FUN_40b9a160((int)param_1);
    LeaveCriticalSection(param_1);
    WaitForSingleObject(param_1[2].DebugInfo,0xffffffff);
    CloseHandle(param_1[2].DebugInfo);
    puVar1 = param_1[1].OwningThread;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_40b9a0fc(puVar1);
      operator_delete(puVar1);
    }
  }
  if (param_1[1].LockSemaphore != (HANDLE)0x0) {
    CloseHandle(param_1[1].LockSemaphore);
  }
  operator_delete((void *)param_1[2].LockCount);
  FUN_40b98b64(&param_1[1].SpinCount);
  DeleteCriticalSection(param_1);
  return;
}



/* 40b9a754 FUN_40b9a754 */

/* Boundary evidence: original MIPS .pdata 40b9a754..40b9aa2b. Semantic name remains unreviewed. */

undefined4 FUN_40b9a754(LPCRITICAL_SECTION param_1)

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
LAB_40b9a790:
  do {
    bVar1 = false;
    EnterCriticalSection(param_1);
    do {
      while( true ) {
        if (param_1[3].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
          FUN_40b9a560(param_1);
          LeaveCriticalSection(param_1);
          return 0;
        }
        if (param_1[2].LockSemaphore != (HANDLE)0x0) {
          FUN_40b9a560(param_1);
          EventModify(param_1[1].SpinCount,3);
        }
        uVar2 = FUN_40b9a144(param_1[1].OwningThread);
        if (uVar2 != 0) break;
        if ((param_1[1].LockCount != 0) || (param_1[2].RecursionCount == 0)) {
          param_1[2].OwningThread = (HANDLE)((int)param_1[2].OwningThread + 1);
          bVar1 = true;
          goto LAB_40b9a8a4;
        }
LAB_40b9a850:
        if (uVar2 != 0xfffffffe) {
          if (uVar2 == 0xfffffffb) {
            pvVar3 = (void *)FUN_40b9a144(param_1[1].OwningThread);
          }
          goto LAB_40b9a888;
        }
        if (param_1[2].RecursionCount != 0) goto LAB_40b9a888;
      }
      if (0xfffffff0 < uVar2) goto LAB_40b9a850;
      if (param_1[2].RecursionCount < param_1[1].RecursionCount) {
        *(uint *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = uVar2;
        param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
      }
    } while (param_1[2].RecursionCount != param_1[1].RecursionCount);
LAB_40b9a888:
    pvVar6 = (void *)param_1[2].RecursionCount;
    param_1[2].RecursionCount = 0;
LAB_40b9a8a4:
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
        if (param_1[3].RecursionCount != 0) goto LAB_40b9a790;
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
      goto LAB_40b9a790;
    }
    WaitForSingleObject(param_1[1].LockSemaphore,0xffffffff);
  } while( true );
}



/* 40b9aa2c FUN_40b9aa2c */

/* Boundary evidence: original MIPS .pdata 40b9aa2c..40b9aa9b. Semantic name remains unreviewed. */

void FUN_40b9aa2c(LPCRITICAL_SECTION param_1)

{
  int aiStack_10 [2];
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    param_1[3].LockCount = 1;
    FUN_40b9a2c0(param_1,(undefined4 *)0x0,0,aiStack_10);
    param_1[3].LockCount = 0;
  }
  else {
    EnterCriticalSection(param_1);
    FUN_40b9a268((int)param_1,(int *)0xfffffffe);
    FUN_40b9a160((int)param_1);
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40b9aa9c FUN_40b9aa9c */

/* Boundary evidence: original MIPS .pdata 40b9aa9c..40b9ab3b. Semantic name remains unreviewed. */

void FUN_40b9aa9c(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[1].LockCount != 0) {
      FUN_40b9aa2c(param_1);
    }
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      (**(code **)(*(int *)param_1->SpinCount + 0x38))();
    }
  }
  else if (param_1[3].RecursionCount == 0) {
    param_1[2].SpinCount = 0;
    FUN_40b9a268((int)param_1,(int *)0xfffffffd);
    FUN_40b9a160((int)param_1);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40b9ab3c FUN_40b9ab3c */

/* Boundary evidence: original MIPS .pdata 40b9ab3c..40b9abef. Semantic name remains unreviewed. */

void FUN_40b9ab3c(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  
  EnterCriticalSection(param_1);
  if ((param_1[2].SpinCount == 0) || (param_1[1].OwningThread == (HANDLE)0x0)) {
    LeaveCriticalSection(param_1);
    if (param_1[1].OwningThread == (HANDLE)0x0) {
      FUN_40b9a560(param_1);
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



/* 40b9abf0 FUN_40b9abf0 */

/* Boundary evidence: original MIPS .pdata 40b9abf0..40b9ac17. Semantic name remains unreviewed. */

void FUN_40b9abf0(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  int aiStack_10 [2];
  
  local_res4[0] = param_2;
  FUN_40b9a2c0(param_1,local_res4,1,aiStack_10);
  return;
}



/* 40b9ac18 FUN_40b9ac18 */

/* Boundary evidence: original MIPS .pdata 40b9ac18..40b9ac6b. Semantic name remains unreviewed. */

undefined4 FUN_40b9ac18(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40b98bb8();
  uVar2 = FUN_40b9a754(param_1);
  if (-1 < iVar1) {
    CoUninitialize();
  }
  return uVar2;
}



/* 40b9ac6c FUN_40b9ac6c */

/* Boundary evidence: original MIPS .pdata 40b9ac6c..40b9aeaf. Semantic name remains unreviewed. */

LPCRITICAL_SECTION
FUN_40b9ac6c(LPCRITICAL_SECTION param_1,undefined4 *param_2,DWORD *param_3,int param_4,int param_5,
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
  FUN_40b98b24(&param_1[1].SpinCount,0);
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
  DVar1 = (**(code **)*param_2)(param_2,&DAT_40ba5118,p_Var9);
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
LAB_40b9adac:
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
        FUN_40b99e40(puVar5,0,param_8);
      }
      param_1[1].OwningThread = puVar5;
      if (puVar5 == (undefined4 *)0x0) goto LAB_40b9adac;
      p_Var6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40b9ac18,param_1,0,aDStack_28);
      param_1[2].DebugInfo = p_Var6;
      if (p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        FUN_40b98864(p_Var6,param_9);
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



/* 40b9aef4 FUN_40b9aef4 */

/* Boundary evidence: original MIPS .pdata 40b9aef4..40b9af73. Semantic name remains unreviewed. */

void FUN_40b9aef4(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40ba9840) {
    ppuVar2 = &PTR_DAT_40ba9830;
    iVar1 = DAT_40ba9840;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40ba9840;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40b9af74 FUN_40b9af74 */

/* Boundary evidence: original MIPS .pdata 40b9af74..40b9b013. Semantic name remains unreviewed. */

undefined4 FUN_40b9af74(HMODULE param_1,int param_2)

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
    DAT_40bab924 = 1;
    DAT_40bab810 = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40bab810);
    if (BVar1 != 0) {
      DAT_40bab924 = DAT_40bab820;
    }
    uVar2 = 1;
    DAT_40bab928 = param_1;
  }
  FUN_40b9aef4(uVar2);
  return 1;
}



/* 40b9b014 FUN_40b9b014 */

undefined4 FUN_40b9b014(int param_1,int *param_2)

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



/* 40b9b064 FUN_40b9b064 */

/* Boundary evidence: original MIPS .pdata 40b9b064..40b9b10f. Semantic name remains unreviewed. */

undefined4 FUN_40b9b064(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40ba6f90,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40ba6fb0,0x10), iVar2 == 0)) {
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



/* 40b9b110 FUN_40b9b110 */

/* Boundary evidence: original MIPS .pdata 40b9b110..40b9b167. Semantic name remains unreviewed. */

void * FUN_40b9b110(void *param_1,uint param_2)

{
  FUN_40b985a0();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40b9b168 FUN_40b9b168 */

/* Boundary evidence: original MIPS .pdata 40b9b168..40b9b28b. Semantic name remains unreviewed. */

int FUN_40b9b168(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40ba6f90,0x10), iVar1 == 0)) {
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



/* 40b9b28c DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x1b28c  1  DllCanUnloadNow */
  if ((0 < DAT_40bab92c) || (HVar1 = 0, DAT_40bab800 != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40b9b2b8 FUN_40b9b2b8 */

/* Boundary evidence: original MIPS .pdata 40b9b2b8..40b9b313. Semantic name remains unreviewed. */

undefined4 * FUN_40b9b2b8(undefined4 *param_1,undefined4 param_2)

{
  FUN_40b98570(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40ba6d9c;
  param_1[2] = 0;
  return param_1;
}



/* 40b9b314 FUN_40b9b314 */

/* Boundary evidence: original MIPS .pdata 40b9b314..40b9b343. Semantic name remains unreviewed. */

int FUN_40b9b314(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40b9b110(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40b9b344 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40b9b344..40b9b46b. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0x1b344  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40ba6f90,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40ba6fb0,0x10), iVar1 == 0)) {
    iVar1 = DAT_40ba9840;
    iVar7 = 0;
    if (0 < DAT_40ba9840) {
      ppuVar6 = &PTR_u_Alchemy_Transport_Stream_Demux_F_40ba982c;
      do {
        iVar3 = FUN_40b9b014((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40b9b2b8(puVar4,ppuVar6);
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



/* 40b9b46c FUN_40b9b46c */

/* Boundary evidence: original MIPS .pdata 40b9b46c..40b9b5b7. Semantic name remains unreviewed. */

undefined4 FUN_40b9b46c(HKEY param_1,wchar_t *param_2)

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
  
  local_20 = DAT_40ba9854;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40b9bea4(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40b9b46c(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40b9bea4(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40b9b5b8 FUN_40b9b5b8 */

/* Boundary evidence: original MIPS .pdata 40b9b5b8..40b9b847. Semantic name remains unreviewed. */

uint FUN_40b9b5b8(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  
  local_30 = DAT_40ba9854;
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
  FUN_40b9bea4(local_30);
  return uVar1;
}



/* 40b9b848 FUN_40b9b848 */

/* Boundary evidence: original MIPS .pdata 40b9b848..40b9b8bb. Semantic name remains unreviewed. */

undefined4 FUN_40b9b848(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40ba9854;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40b9b46c((HKEY)0x80000000,aWStack_218);
  FUN_40b9bea4(local_10);
  return 0;
}



/* 40b9b8bc FUN_40b9b8bc */

/* Boundary evidence: original MIPS .pdata 40b9b8bc..40b9baf3. Semantic name remains unreviewed. */

DWORD FUN_40b9b8bc(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40ba9854;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40bab928,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40ba9840) {
      ppuVar5 = &PTR_u_Alchemy_Transport_Stream_Demux_F_40ba982c;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40b9b5b8(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40ba5128,local_240
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
      } while (iVar4 < DAT_40ba9840);
    }
  }
  FUN_40b9bea4(local_30);
  return DVar3;
}



/* 40b9baf4 FUN_40b9baf4 */

/* Boundary evidence: original MIPS .pdata 40b9baf4..40b9bc7b. Semantic name remains unreviewed. */

int FUN_40b9baf4(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40ba9840 != 0) {
    iVar3 = DAT_40ba9840;
    ppuVar4 = &PTR_DAT_40ba9830 + DAT_40ba9840 * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40ba5128,local_30);
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
      HVar2 = FUN_40b9b848(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
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



/* 40b9bc7c FUN_40b9bc7c */

/* Boundary evidence: original MIPS .pdata 40b9bc7c..40b9bcaf. Semantic name remains unreviewed. */

void FUN_40b9bc7c(int param_1)

{
  if (param_1 == 0) {
    FUN_40b9baf4();
  }
  else {
    FUN_40b9b8bc();
  }
  return;
}



/* 40b9bdb0 FUN_40b9bdb0 */

/* Boundary evidence: original MIPS .pdata 40b9bdb0..40b9be23. Semantic name remains unreviewed. */

void FUN_40b9bdb0(void)

{
  uint uVar1;
  
  if ((DAT_40ba9854 == 0) || (DAT_40ba9854 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40ba9854 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40ba9854 == 0) {
      DAT_40ba9854 = 0xb064;
    }
  }
  DAT_40ba9858 = ~DAT_40ba9854;
  return;
}



/* 40b9be24 FUN_40b9be24 */

/* Boundary evidence: original MIPS .pdata 40b9be24..40b9be77. Semantic name remains unreviewed. */

void FUN_40b9be24(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40b9bea4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40b9be78 FUN_40b9be78 */

/* Boundary evidence: original MIPS .pdata 40b9be78..40b9bea3. Semantic name remains unreviewed. */

undefined4 FUN_40b9be78(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40b9be24(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40b9bea4 FUN_40b9bea4 */

/* Boundary evidence: original MIPS .pdata 40b9bea4..40b9beeb. Semantic name remains unreviewed. */

void FUN_40b9bea4(uint param_1)

{
  if ((param_1 == DAT_40ba9854) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40b9bfcc FUN_40b9bfcc */

/* Boundary evidence: original MIPS .pdata 40b9bfcc..40b9c03b. Semantic name remains unreviewed. */

void FUN_40b9bfcc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40b9be24(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 40b9c07c FUN_40b9c07c */

/* Boundary evidence: original MIPS .pdata 40b9c07c..40b9c1b7. Semantic name remains unreviewed. */

int FUN_40b9c07c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40bab940 != (code *)0x0) {
      iVar2 = (*DAT_40bab940)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40b9c12c;
    FUN_40b9c400();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40b93250(param_1,param_2);
  }
LAB_40b9c12c:
  if (((param_2 == 0) && (FUN_40b9c388(), iVar1 != 0)) && (DAT_40bab940 != (code *)0x0)) {
    iVar1 = (*DAT_40bab940)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40b9c1b8 FUN_40b9c1b8 */

/* Boundary evidence: original MIPS .pdata 40b9c1b8..40b9c1e3. Semantic name remains unreviewed. */

void FUN_40b9c1b8(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40b9c1e4 entry */

/* Boundary evidence: original MIPS .pdata 40b9c1e4..40b9c23b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40b9bdb0();
  }
  FUN_40b9c07c(param_1,param_2,param_3);
  return;
}



/* 40b9c29c FUN_40b9c29c */

/* Boundary evidence: original MIPS .pdata 40b9c29c..40b9c387. Semantic name remains unreviewed. */

void FUN_40b9c29c(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40bab934 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40bab93c;
    if (DAT_40bab93c != (undefined4 *)0x0) {
      while (DAT_40bab938 = DAT_40bab938 + -1, _Memory <= DAT_40bab938) {
        if ((code *)*DAT_40bab938 != (code *)0x0) {
          (*(code *)*DAT_40bab938)();
          _Memory = DAT_40bab93c;
        }
      }
      free(_Memory);
      DAT_40bab938 = (undefined4 *)0x0;
      DAT_40bab93c = (undefined4 *)0x0;
    }
    FUN_40b9c3ac((undefined4 *)&DAT_40ba1014,(undefined4 *)&DAT_40ba1018);
  }
  FUN_40b9c3ac((undefined4 *)&DAT_40ba101c,(undefined4 *)&DAT_40ba1020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40b9c388 FUN_40b9c388 */

/* Boundary evidence: original MIPS .pdata 40b9c388..40b9c3ab. Semantic name remains unreviewed. */

void FUN_40b9c388(void)

{
  FUN_40b9c29c(0,0,1);
  return;
}



/* 40b9c3ac FUN_40b9c3ac */

/* Boundary evidence: original MIPS .pdata 40b9c3ac..40b9c3ff. Semantic name remains unreviewed. */

void FUN_40b9c3ac(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40b9c400 FUN_40b9c400 */

/* Boundary evidence: original MIPS .pdata 40b9c400..40b9c43b. Semantic name remains unreviewed. */

void FUN_40b9c400(void)

{
  FUN_40b9c3ac((undefined4 *)&DAT_40ba100c,(undefined4 *)&DAT_40ba1010);
  FUN_40b9c3ac((undefined4 *)&DAT_40ba1000,(undefined4 *)&DAT_40ba1008);
  return;
}



/* 40b9c45c FUN_40b9c45c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40b9c45c..40ba0bf7. Semantic name remains unreviewed. */

void FUN_40b9c45c(void)

{
  DAT_40ba9afc = 0x72616641;
  DAT_40ba9b00 = 0;
  memset(&DAT_40ba9b01,0,0x1b);
  _DAT_40ba9b1c = 0x6161;
  DAT_40ba9b1e = 0;
  DAT_40ba9b1f = 0;
  _DAT_40ba9b20 = 0x726161;
  _DAT_40ba9b24 = 0x726161;
  DAT_40ba9b28._0_1_ = 'A';
  DAT_40ba9b28._1_1_ = 'b';
  DAT_40ba9b28._2_1_ = 'k';
  DAT_40ba9b28._3_1_ = 'h';
  DAT_40ba9b2c._0_1_ = 'a';
  DAT_40ba9b2c._1_1_ = 'z';
  DAT_40ba9b2c._2_1_ = 'i';
  DAT_40ba9b2c._3_1_ = 'a';
  DAT_40ba9b30._0_1_ = 'n';
  DAT_40ba9b30._1_1_ = '\0';
  DAT_40ba9b32 = 0;
  DAT_40ba9b34 = 0;
  DAT_40ba9b36 = 0;
  DAT_40ba9b38 = 0;
  DAT_40ba9b3a = 0;
  DAT_40ba9b3c = 0;
  DAT_40ba9b3e = 0;
  DAT_40ba9b40 = 0;
  DAT_40ba9b42 = 0;
  DAT_40ba9b44 = 0;
  DAT_40ba9b46 = 0;
  DAT_40ba9b48 = 0x6261;
  DAT_40ba9b4a = 0;
  DAT_40ba9b4b = 0;
  DAT_40ba9b4c = 0x6b6261;
  DAT_40ba9b50 = 0x6b6261;
  DAT_40ba9b54._0_1_ = 'A';
  DAT_40ba9b54._1_1_ = 'f';
  DAT_40ba9b54._2_1_ = 'r';
  DAT_40ba9b54._3_1_ = 'i';
  DAT_40ba9b58._0_1_ = 'k';
  DAT_40ba9b58._1_1_ = 'a';
  DAT_40ba9b58._2_1_ = 'a';
  DAT_40ba9b58._3_1_ = 'n';
  DAT_40ba9b5c._0_1_ = 's';
  DAT_40ba9b5c._1_1_ = '\0';
  DAT_40ba9b5e = 0;
  DAT_40ba9b60 = 0;
  DAT_40ba9b62 = 0;
  DAT_40ba9b64 = 0;
  DAT_40ba9b66 = 0;
  DAT_40ba9b68 = 0;
  DAT_40ba9b6a = 0;
  DAT_40ba9b6c = 0;
  DAT_40ba9b6e = 0;
  DAT_40ba9b70 = 0;
  DAT_40ba9b72 = 0;
  DAT_40ba9b74 = 0x6661;
  DAT_40ba9b76 = 0;
  DAT_40ba9b77 = 0;
  DAT_40ba9b78 = 0x726661;
  DAT_40ba9b7c = 0x726661;
  DAT_40ba9b80._0_1_ = 'A';
  DAT_40ba9b80._1_1_ = 'l';
  DAT_40ba9b80._2_1_ = 'b';
  DAT_40ba9b80._3_1_ = 'a';
  DAT_40ba9b84._0_1_ = 'n';
  DAT_40ba9b84._1_1_ = 'i';
  DAT_40ba9b84._2_1_ = 'a';
  DAT_40ba9b84._3_1_ = 'n';
  DAT_40ba9b88 = '\0';
  memset(&DAT_40ba9b89,0,0x17);
  DAT_40ba9ba0 = 0x7173;
  DAT_40ba9ba2 = 0;
  DAT_40ba9ba3 = 0;
  DAT_40ba9ba4 = 0x697173;
  DAT_40ba9ba8 = 0x626c61;
  DAT_40ba9bac._0_1_ = 'A';
  DAT_40ba9bac._1_1_ = 'm';
  DAT_40ba9bac._2_1_ = 'h';
  DAT_40ba9bac._3_1_ = 'a';
  DAT_40ba9bb0._0_1_ = 'r';
  DAT_40ba9bb0._1_1_ = 'i';
  DAT_40ba9bb0._2_1_ = 'c';
  DAT_40ba9bb0._3_1_ = '\0';
  DAT_40ba9bb4 = 0;
  DAT_40ba9bb8 = 0;
  DAT_40ba9bbc = 0;
  DAT_40ba9bc0 = 0;
  DAT_40ba9bc4 = 0;
  DAT_40ba9bc8 = 0;
  DAT_40ba9bcc = 0x6d61;
  DAT_40ba9bce = 0;
  DAT_40ba9bcf = 0;
  DAT_40ba9bd0 = 0x686d61;
  DAT_40ba9bd4 = 0x686d61;
  DAT_40ba9bd8._0_1_ = 'A';
  DAT_40ba9bd8._1_1_ = 'r';
  DAT_40ba9bd8._2_1_ = 'a';
  DAT_40ba9bd8._3_1_ = 'b';
  DAT_40ba9bdc._0_1_ = 'i';
  DAT_40ba9bdc._1_1_ = 'c';
  DAT_40ba9bde = '\0';
  memset(&DAT_40ba9bdf,0,0x19);
  DAT_40ba9bf8 = 0x7261;
  DAT_40ba9bfa = 0;
  DAT_40ba9bfb = 0;
  DAT_40ba9bfc = 0x617261;
  DAT_40ba9c00 = 0x617261;
  DAT_40ba9c04._0_1_ = 'A';
  DAT_40ba9c04._1_1_ = 'r';
  DAT_40ba9c04._2_1_ = 'm';
  DAT_40ba9c04._3_1_ = 'e';
  DAT_40ba9c08._0_1_ = 'n';
  DAT_40ba9c08._1_1_ = 'i';
  DAT_40ba9c08._2_1_ = 'a';
  DAT_40ba9c08._3_1_ = 'n';
  DAT_40ba9c0c = '\0';
  memset(&DAT_40ba9c0d,0,0x17);
  DAT_40ba9c24 = 0x7968;
  DAT_40ba9c26 = 0;
  DAT_40ba9c27 = 0;
  DAT_40ba9c28 = 0x657968;
  DAT_40ba9c2c = 0x6d7261;
  DAT_40ba9c30._0_1_ = 'A';
  DAT_40ba9c30._1_1_ = 's';
  DAT_40ba9c30._2_1_ = 's';
  DAT_40ba9c30._3_1_ = 'a';
  DAT_40ba9c34._0_1_ = 'm';
  DAT_40ba9c34._1_1_ = 'e';
  DAT_40ba9c34._2_1_ = 's';
  DAT_40ba9c34._3_1_ = 'e';
  DAT_40ba9c38 = '\0';
  memset(&DAT_40ba9c39,0,0x17);
  DAT_40ba9c50 = 0x7361;
  DAT_40ba9c52 = 0;
  DAT_40ba9c53 = 0;
  DAT_40ba9c54 = 0x6d7361;
  DAT_40ba9c58 = 0x6d7361;
  DAT_40ba9c5c._0_1_ = 'A';
  DAT_40ba9c5c._1_1_ = 'v';
  DAT_40ba9c5c._2_1_ = 'e';
  DAT_40ba9c5c._3_1_ = 's';
  DAT_40ba9c60._0_1_ = 't';
  DAT_40ba9c60._1_1_ = 'a';
  DAT_40ba9c60._2_1_ = 'n';
  DAT_40ba9c60._3_1_ = '\0';
  DAT_40ba9c64 = 0;
  DAT_40ba9c68 = 0;
  DAT_40ba9c6c = 0;
  DAT_40ba9c70 = 0;
  DAT_40ba9c74 = 0;
  DAT_40ba9c78 = 0;
  DAT_40ba9c7c = 0x6561;
  DAT_40ba9c7e = 0;
  DAT_40ba9c7f = 0;
  DAT_40ba9c80 = 0x657661;
  DAT_40ba9c84 = 0x657661;
  DAT_40ba9c88._0_1_ = 'A';
  DAT_40ba9c88._1_1_ = 'y';
  DAT_40ba9c88._2_1_ = 'm';
  DAT_40ba9c88._3_1_ = 'a';
  DAT_40ba9c8c._0_1_ = 'r';
  DAT_40ba9c8c._1_1_ = 'a';
  DAT_40ba9c8e = '\0';
  memset(&DAT_40ba9c8f,0,0x19);
  DAT_40ba9ca8 = 0x7961;
  DAT_40ba9caa = 0;
  DAT_40ba9cab = 0;
  DAT_40ba9cac = 0x6d7961;
  DAT_40ba9cb0 = 0x6d7961;
  DAT_40ba9cb4._0_1_ = 'A';
  DAT_40ba9cb4._1_1_ = 'z';
  DAT_40ba9cb4._2_1_ = 'e';
  DAT_40ba9cb4._3_1_ = 'r';
  DAT_40ba9cb8._0_1_ = 'b';
  DAT_40ba9cb8._1_1_ = 'a';
  DAT_40ba9cb8._2_1_ = 'i';
  DAT_40ba9cb8._3_1_ = 'j';
  DAT_40ba9cbc._0_1_ = 'a';
  DAT_40ba9cbc._1_1_ = 'n';
  DAT_40ba9cbc._2_1_ = 'i';
  DAT_40ba9cbc._3_1_ = '\0';
  DAT_40ba9cc0 = 0;
  DAT_40ba9cc4 = 0;
  DAT_40ba9cc8 = 0;
  DAT_40ba9ccc = 0;
  DAT_40ba9cd0 = 0;
  DAT_40ba9cd4 = 0x7a61;
  DAT_40ba9cd6 = 0;
  DAT_40ba9cd7 = 0;
  DAT_40ba9cd8 = 0x657a61;
  DAT_40ba9cdc = 0x657a61;
  DAT_40ba9ce0 = 0x68736142;
  DAT_40ba9ce4 = 0x72696b;
  DAT_40ba9ce8 = 0;
  DAT_40ba9cec = 0;
  DAT_40ba9cf0 = 0;
  DAT_40ba9cf4 = 0;
  DAT_40ba9cf8 = 0;
  DAT_40ba9cfc = 0;
  DAT_40ba9d00 = 0x6162;
  DAT_40ba9d02 = 0;
  DAT_40ba9d03 = 0;
  DAT_40ba9d04 = 0x6b6162;
  DAT_40ba9d08 = 0x6b6162;
  DAT_40ba9d0c._0_1_ = 'B';
  DAT_40ba9d0c._1_1_ = 'a';
  DAT_40ba9d0c._2_1_ = 's';
  DAT_40ba9d0c._3_1_ = 'q';
  DAT_40ba9d10._0_1_ = 'u';
  DAT_40ba9d10._1_1_ = 'e';
  DAT_40ba9d12 = '\0';
  memset(&DAT_40ba9d13,0,0x19);
  DAT_40ba9d2c = 0x7565;
  DAT_40ba9d2e = 0;
  DAT_40ba9d2f = 0;
  DAT_40ba9d30 = 0x737565;
  DAT_40ba9d34 = 0x716162;
  DAT_40ba9d38._0_1_ = 'B';
  DAT_40ba9d38._1_1_ = 'e';
  DAT_40ba9d38._2_1_ = 'l';
  DAT_40ba9d38._3_1_ = 'a';
  DAT_40ba9d3c._0_1_ = 'r';
  DAT_40ba9d3c._1_1_ = 'u';
  DAT_40ba9d3c._2_1_ = 's';
  DAT_40ba9d3c._3_1_ = 'i';
  DAT_40ba9d40._0_1_ = 'a';
  DAT_40ba9d40._1_1_ = 'n';
  DAT_40ba9d42 = '\0';
  memset(&DAT_40ba9d43,0,0x15);
  DAT_40ba9d58 = 0x6562;
  DAT_40ba9d5a = 0;
  DAT_40ba9d5b = 0;
  DAT_40ba9d5c = 0x6c6562;
  DAT_40ba9d60 = 0x6c6562;
  DAT_40ba9d64._0_1_ = 'B';
  DAT_40ba9d64._1_1_ = 'e';
  DAT_40ba9d64._2_1_ = 'n';
  DAT_40ba9d64._3_1_ = 'g';
  DAT_40ba9d68._0_1_ = 'a';
  DAT_40ba9d68._1_1_ = 'l';
  DAT_40ba9d68._2_1_ = 'i';
  DAT_40ba9d68._3_1_ = '\0';
  DAT_40ba9d6c = 0;
  DAT_40ba9d70 = 0;
  DAT_40ba9d74 = 0;
  DAT_40ba9d78 = 0;
  DAT_40ba9d7c = 0;
  DAT_40ba9d80 = 0;
  DAT_40ba9d84 = 0x6e62;
  DAT_40ba9d86 = 0;
  DAT_40ba9d87 = 0;
  DAT_40ba9d88 = 0x6e6562;
  DAT_40ba9d8c = 0x6e6562;
  DAT_40ba9d90._0_1_ = 'B';
  DAT_40ba9d90._1_1_ = 'i';
  DAT_40ba9d90._2_1_ = 'h';
  DAT_40ba9d90._3_1_ = 'a';
  DAT_40ba9d94._0_1_ = 'r';
  DAT_40ba9d94._1_1_ = 'i';
  DAT_40ba9d96 = '\0';
  memset(&DAT_40ba9d97,0,0x19);
  DAT_40ba9db0 = 0x6862;
  DAT_40ba9db2 = 0;
  DAT_40ba9db3 = 0;
  DAT_40ba9db4 = 0x686962;
  DAT_40ba9db8 = 0x686962;
  DAT_40ba9dbc._0_1_ = 'B';
  DAT_40ba9dbc._1_1_ = 'i';
  DAT_40ba9dbc._2_1_ = 's';
  DAT_40ba9dbc._3_1_ = 'l';
  DAT_40ba9dc0._0_1_ = 'a';
  DAT_40ba9dc0._1_1_ = 'm';
  DAT_40ba9dc0._2_1_ = 'a';
  DAT_40ba9dc0._3_1_ = '\0';
  DAT_40ba9dc4 = 0;
  DAT_40ba9dc8 = 0;
  DAT_40ba9dcc = 0;
  DAT_40ba9dd0 = 0;
  DAT_40ba9dd4 = 0;
  DAT_40ba9dd8 = 0;
  DAT_40ba9ddc = 0x6962;
  DAT_40ba9dde = 0;
  DAT_40ba9ddf = 0;
  DAT_40ba9de0 = 0x736962;
  DAT_40ba9de4 = 0x736962;
  DAT_40ba9de8._0_1_ = 'B';
  DAT_40ba9de8._1_1_ = 'o';
  DAT_40ba9de8._2_1_ = 's';
  DAT_40ba9de8._3_1_ = 'n';
  DAT_40ba9dec._0_1_ = 'i';
  DAT_40ba9dec._1_1_ = 'a';
  DAT_40ba9dec._2_1_ = 'n';
  DAT_40ba9dec._3_1_ = '\0';
  DAT_40ba9df0 = 0;
  DAT_40ba9df4 = 0;
  DAT_40ba9df8 = 0;
  DAT_40ba9dfc = 0;
  DAT_40ba9e00 = 0;
  DAT_40ba9e04 = 0;
  DAT_40ba9e08 = 0x7362;
  DAT_40ba9e0a = 0;
  DAT_40ba9e0b = 0;
  DAT_40ba9e0c = 0x736f62;
  DAT_40ba9e10 = 0x736f62;
  DAT_40ba9e14._0_1_ = 'B';
  DAT_40ba9e14._1_1_ = 'r';
  DAT_40ba9e14._2_1_ = 'e';
  DAT_40ba9e14._3_1_ = 't';
  DAT_40ba9e18._0_1_ = 'o';
  DAT_40ba9e18._1_1_ = 'n';
  DAT_40ba9e1a = '\0';
  memset(&DAT_40ba9e1b,0,0x19);
  DAT_40ba9e34 = 0x7262;
  DAT_40ba9e36 = 0;
  DAT_40ba9e37 = 0;
  DAT_40ba9e38 = 0x657262;
  DAT_40ba9e3c = 0x657262;
  DAT_40ba9e40._0_1_ = 'B';
  DAT_40ba9e40._1_1_ = 'u';
  DAT_40ba9e40._2_1_ = 'l';
  DAT_40ba9e40._3_1_ = 'g';
  DAT_40ba9e44._0_1_ = 'a';
  DAT_40ba9e44._1_1_ = 'r';
  DAT_40ba9e44._2_1_ = 'i';
  DAT_40ba9e44._3_1_ = 'a';
  DAT_40ba9e48._0_1_ = 'n';
  DAT_40ba9e48._1_1_ = '\0';
  DAT_40ba9e4a = 0;
  DAT_40ba9e4c = 0;
  DAT_40ba9e4e = 0;
  DAT_40ba9e50 = 0;
  DAT_40ba9e52 = 0;
  DAT_40ba9e54 = 0;
  DAT_40ba9e56 = 0;
  DAT_40ba9e58 = 0;
  DAT_40ba9e5a = 0;
  DAT_40ba9e5c = 0;
  DAT_40ba9e5e = 0;
  DAT_40ba9e60 = 0x6762;
  DAT_40ba9e62 = 0;
  DAT_40ba9e63 = 0;
  DAT_40ba9e64 = 0x6c7562;
  DAT_40ba9e68 = 0x6c7562;
  DAT_40ba9e6c._0_1_ = 'B';
  DAT_40ba9e6c._1_1_ = 'u';
  DAT_40ba9e6c._2_1_ = 'r';
  DAT_40ba9e6c._3_1_ = 'm';
  DAT_40ba9e70._0_1_ = 'e';
  DAT_40ba9e70._1_1_ = 's';
  DAT_40ba9e70._2_1_ = 'e';
  DAT_40ba9e70._3_1_ = '\0';
  DAT_40ba9e74 = 0;
  DAT_40ba9e78 = 0;
  DAT_40ba9e7c = 0;
  DAT_40ba9e80 = 0;
  DAT_40ba9e84 = 0;
  DAT_40ba9e88 = 0;
  DAT_40ba9e8c = 0x796d;
  DAT_40ba9e8e = 0;
  DAT_40ba9e8f = 0;
  DAT_40ba9e90 = 0x61796d;
  DAT_40ba9e94 = 0x727562;
  DAT_40ba9e98._0_1_ = 'C';
  DAT_40ba9e98._1_1_ = 'a';
  DAT_40ba9e98._2_1_ = 't';
  DAT_40ba9e98._3_1_ = 'a';
  DAT_40ba9e9c._0_1_ = 'l';
  DAT_40ba9e9c._1_1_ = 'a';
  DAT_40ba9e9c._2_1_ = 'n';
  DAT_40ba9e9c._3_1_ = '\0';
  DAT_40ba9ea0 = 0;
  DAT_40ba9ea4 = 0;
  DAT_40ba9ea8 = 0;
  DAT_40ba9eac = 0;
  DAT_40ba9eb0 = 0;
  DAT_40ba9eb4 = 0;
  DAT_40ba9eb8 = 0x6163;
  DAT_40ba9eba = 0;
  DAT_40ba9ebb = 0;
  DAT_40ba9ebc = 0x746163;
  DAT_40ba9ec0 = 0x746163;
  DAT_40ba9ec4._0_1_ = 'C';
  DAT_40ba9ec4._1_1_ = 'h';
  DAT_40ba9ec4._2_1_ = 'a';
  DAT_40ba9ec4._3_1_ = 'm';
  DAT_40ba9ec8._0_1_ = 'o';
  DAT_40ba9ec8._1_1_ = 'r';
  DAT_40ba9ec8._2_1_ = 'r';
  DAT_40ba9ec8._3_1_ = 'o';
  DAT_40ba9ecc = '\0';
  memset(&DAT_40ba9ecd,0,0x17);
  DAT_40ba9ee4 = 0x6863;
  DAT_40ba9ee6 = 0;
  DAT_40ba9ee7 = 0;
  DAT_40ba9ee8 = 0x616863;
  DAT_40ba9eec = 0x616863;
  DAT_40ba9ef0._0_1_ = 'C';
  DAT_40ba9ef0._1_1_ = 'h';
  DAT_40ba9ef0._2_1_ = 'e';
  DAT_40ba9ef0._3_1_ = 'c';
  DAT_40ba9ef4._0_1_ = 'h';
  DAT_40ba9ef4._1_1_ = 'e';
  DAT_40ba9ef4._2_1_ = 'n';
  DAT_40ba9ef4._3_1_ = '\0';
  DAT_40ba9ef8 = 0;
  DAT_40ba9efc = 0;
  DAT_40ba9f00 = 0;
  DAT_40ba9f04 = 0;
  DAT_40ba9f08 = 0;
  DAT_40ba9f0c = 0;
  DAT_40ba9f10 = 0x6563;
  DAT_40ba9f12 = 0;
  DAT_40ba9f13 = 0;
  DAT_40ba9f14 = 0x656863;
  DAT_40ba9f18 = 0x656863;
  DAT_40ba9f1c._0_1_ = 'C';
  DAT_40ba9f1c._1_1_ = 'h';
  DAT_40ba9f1c._2_1_ = 'i';
  DAT_40ba9f1c._3_1_ = 'n';
  DAT_40ba9f20._0_1_ = 'e';
  DAT_40ba9f20._1_1_ = 's';
  DAT_40ba9f20._2_1_ = 'e';
  DAT_40ba9f20._3_1_ = '\0';
  DAT_40ba9f24 = 0;
  DAT_40ba9f28 = 0;
  DAT_40ba9f2c = 0;
  DAT_40ba9f30 = 0;
  DAT_40ba9f34 = 0;
  DAT_40ba9f38 = 0;
  DAT_40ba9f3c = 0x687a;
  DAT_40ba9f3e = 0;
  DAT_40ba9f3f = 0;
  DAT_40ba9f40 = 0x6f687a;
  DAT_40ba9f44 = 0x696863;
  DAT_40ba9f48._0_1_ = 'C';
  DAT_40ba9f48._1_1_ = 'h';
  DAT_40ba9f48._2_1_ = 'u';
  DAT_40ba9f48._3_1_ = 'r';
  DAT_40ba9f4c._0_1_ = 'c';
  DAT_40ba9f4c._1_1_ = 'h';
  DAT_40ba9f4c._2_1_ = ' ';
  DAT_40ba9f4c._3_1_ = 'S';
  DAT_40ba9f50._0_1_ = 'l';
  DAT_40ba9f50._1_1_ = 'a';
  DAT_40ba9f50._2_1_ = 'v';
  DAT_40ba9f50._3_1_ = 'i';
  DAT_40ba9f54._0_1_ = 'c';
  DAT_40ba9f54._1_1_ = '\0';
  DAT_40ba9f56 = 0;
  DAT_40ba9f58 = 0;
  DAT_40ba9f5a = 0;
  DAT_40ba9f5c = 0;
  DAT_40ba9f5e = 0;
  DAT_40ba9f60 = 0;
  DAT_40ba9f62 = 0;
  DAT_40ba9f64 = 0;
  DAT_40ba9f66 = 0;
  DAT_40ba9f68 = 0x7563;
  DAT_40ba9f6a = 0;
  DAT_40ba9f6b = 0;
  DAT_40ba9f6c = 0x756863;
  DAT_40ba9f70 = 0x756863;
  DAT_40ba9f74 = 0x76756843;
  DAT_40ba9f78 = 0x687361;
  DAT_40ba9f7c = 0;
  DAT_40ba9f80 = 0;
  DAT_40ba9f84 = 0;
  DAT_40ba9f88 = 0;
  DAT_40ba9f8c = 0;
  DAT_40ba9f90 = 0;
  DAT_40ba9f94 = 0x7663;
  DAT_40ba9f96 = 0;
  DAT_40ba9f97 = 0;
  DAT_40ba9f98 = 0x766863;
  DAT_40ba9f9c = 0x766863;
  DAT_40ba9fa0._0_1_ = 'C';
  DAT_40ba9fa0._1_1_ = 'o';
  DAT_40ba9fa0._2_1_ = 'r';
  DAT_40ba9fa0._3_1_ = 'n';
  DAT_40ba9fa4._0_1_ = 'i';
  DAT_40ba9fa4._1_1_ = 's';
  DAT_40ba9fa4._2_1_ = 'h';
  DAT_40ba9fa4._3_1_ = '\0';
  DAT_40ba9fa8 = 0;
  DAT_40ba9fac = 0;
  DAT_40ba9fb0 = 0;
  DAT_40ba9fb4 = 0;
  DAT_40ba9fb8 = 0;
  DAT_40ba9fbc = 0;
  DAT_40ba9fc0 = 0x776b;
  DAT_40ba9fc2 = 0;
  DAT_40ba9fc3 = 0;
  DAT_40ba9fc4 = 0x726f63;
  DAT_40ba9fc8 = 0x726f63;
  DAT_40ba9fcc._0_1_ = 'C';
  DAT_40ba9fcc._1_1_ = 'o';
  DAT_40ba9fcc._2_1_ = 'r';
  DAT_40ba9fcc._3_1_ = 's';
  DAT_40ba9fd0._0_1_ = 'i';
  DAT_40ba9fd0._1_1_ = 'c';
  DAT_40ba9fd0._2_1_ = 'a';
  DAT_40ba9fd0._3_1_ = 'n';
  DAT_40ba9fd4 = '\0';
  memset(&DAT_40ba9fd5,0,0x17);
  DAT_40ba9fec = 0x6f63;
  DAT_40ba9fee = 0;
  DAT_40ba9fef = 0;
  DAT_40ba9ff0 = 0x736f63;
  DAT_40ba9ff4 = 0x736f63;
  DAT_40ba9ff8 = 0x63657a43;
  DAT_40ba9ffc = 0x68;
  DAT_40ba9ffe = 0;
  DAT_40baa000 = 0;
  DAT_40baa002 = 0;
  DAT_40baa004 = 0;
  DAT_40baa006 = 0;
  DAT_40baa008 = 0;
  DAT_40baa00a = 0;
  DAT_40baa00c = 0;
  DAT_40baa00e = 0;
  DAT_40baa010 = 0;
  DAT_40baa012 = 0;
  DAT_40baa014 = 0;
  DAT_40baa016 = 0;
  DAT_40baa018 = 0x7363;
  DAT_40baa01a = 0;
  DAT_40baa01b = 0;
  DAT_40baa01c = 0x736563;
  DAT_40baa020 = 0x657a63;
  DAT_40baa024._0_1_ = 'D';
  DAT_40baa024._1_1_ = 'a';
  DAT_40baa024._2_1_ = 'n';
  DAT_40baa024._3_1_ = 'i';
  DAT_40baa028._0_1_ = 's';
  DAT_40baa028._1_1_ = 'h';
  DAT_40baa02a = '\0';
  memset(&DAT_40baa02b,0,0x19);
  DAT_40baa044 = 0x6164;
  DAT_40baa046 = 0;
  DAT_40baa047 = 0;
  DAT_40baa048 = 0x6e6164;
  DAT_40baa04c = 0x6e6164;
  DAT_40baa050._0_1_ = 'D';
  DAT_40baa050._1_1_ = 'u';
  DAT_40baa050._2_1_ = 't';
  DAT_40baa050._3_1_ = 'c';
  DAT_40baa054._0_1_ = 'h';
  DAT_40baa054._1_1_ = '\0';
  DAT_40baa056 = 0;
  DAT_40baa058 = 0;
  DAT_40baa05a = 0;
  DAT_40baa05c = 0;
  DAT_40baa05e = 0;
  DAT_40baa060 = 0;
  DAT_40baa062 = 0;
  DAT_40baa064 = 0;
  DAT_40baa066 = 0;
  DAT_40baa068 = 0;
  DAT_40baa06a = 0;
  DAT_40baa06c = 0;
  DAT_40baa06e = 0;
  DAT_40baa070 = 0x6c6e;
  DAT_40baa072 = 0;
  DAT_40baa073 = 0;
  DAT_40baa074 = 0x646c6e;
  DAT_40baa078 = 0x747564;
  DAT_40baa07c = 0x6e6f7a44;
  DAT_40baa080 = 0x61686b67;
  DAT_40baa084 = 0;
  memset(&DAT_40baa085,0,0x17);
  DAT_40baa09c = 0x7a64;
  DAT_40baa09e = 0;
  DAT_40baa09f = 0;
  DAT_40baa0a0 = 0x6f7a64;
  DAT_40baa0a4 = 0x6f7a64;
  DAT_40baa0a8._0_1_ = 'E';
  DAT_40baa0a8._1_1_ = 'n';
  DAT_40baa0a8._2_1_ = 'g';
  DAT_40baa0a8._3_1_ = 'l';
  DAT_40baa0ac._0_1_ = 'i';
  DAT_40baa0ac._1_1_ = 's';
  DAT_40baa0ac._2_1_ = 'h';
  DAT_40baa0ac._3_1_ = '\0';
  DAT_40baa0b0 = 0;
  DAT_40baa0b4 = 0;
  DAT_40baa0b8 = 0;
  DAT_40baa0bc = 0;
  DAT_40baa0c0 = 0;
  DAT_40baa0c4 = 0;
  DAT_40baa0c8 = 0x6e65;
  DAT_40baa0ca = 0;
  DAT_40baa0cb = 0;
  DAT_40baa0cc = 0x676e65;
  DAT_40baa0d0 = 0x676e65;
  DAT_40baa0d4._0_1_ = 'E';
  DAT_40baa0d4._1_1_ = 's';
  DAT_40baa0d4._2_1_ = 'p';
  DAT_40baa0d4._3_1_ = 'e';
  DAT_40baa0d8._0_1_ = 'r';
  DAT_40baa0d8._1_1_ = 'a';
  DAT_40baa0d8._2_1_ = 'n';
  DAT_40baa0d8._3_1_ = 't';
  DAT_40baa0dc._0_1_ = 'o';
  DAT_40baa0dc._1_1_ = '\0';
  DAT_40baa0de = 0;
  DAT_40baa0e0 = 0;
  DAT_40baa0e2 = 0;
  DAT_40baa0e4 = 0;
  DAT_40baa0e6 = 0;
  DAT_40baa0e8 = 0;
  DAT_40baa0ea = 0;
  DAT_40baa0ec = 0;
  DAT_40baa0ee = 0;
  DAT_40baa0f0 = 0;
  DAT_40baa0f2 = 0;
  DAT_40baa0f4 = 0x6f65;
  DAT_40baa0f6 = 0;
  DAT_40baa0f7 = 0;
  DAT_40baa0f8 = 0x6f7065;
  DAT_40baa0fc = 0x6f7065;
  DAT_40baa100._0_1_ = 'E';
  DAT_40baa100._1_1_ = 's';
  DAT_40baa100._2_1_ = 't';
  DAT_40baa100._3_1_ = 'o';
  DAT_40baa104._0_1_ = 'n';
  DAT_40baa104._1_1_ = 'i';
  DAT_40baa104._2_1_ = 'a';
  DAT_40baa104._3_1_ = 'n';
  DAT_40baa108 = '\0';
  memset(&DAT_40baa109,0,0x17);
  DAT_40baa120 = 0x7465;
  DAT_40baa122 = 0;
  DAT_40baa123 = 0;
  DAT_40baa124 = 0x747365;
  DAT_40baa128 = 0x747365;
  DAT_40baa12c._0_1_ = 'F';
  DAT_40baa12c._1_1_ = 'a';
  DAT_40baa12c._2_1_ = 'r';
  DAT_40baa12c._3_1_ = 'o';
  DAT_40baa130._0_1_ = 'e';
  DAT_40baa130._1_1_ = 's';
  DAT_40baa130._2_1_ = 'e';
  DAT_40baa130._3_1_ = '\0';
  DAT_40baa134 = 0;
  DAT_40baa138 = 0;
  DAT_40baa13c = 0;
  DAT_40baa140 = 0;
  DAT_40baa144 = 0;
  DAT_40baa148 = 0;
  DAT_40baa14c = 0x6f66;
  DAT_40baa14e = 0;
  DAT_40baa14f = 0;
  DAT_40baa150 = 0x6f6166;
  DAT_40baa154 = 0x6f6166;
  DAT_40baa158 = 0x696a6946;
  DAT_40baa15c = 0x6e61;
  DAT_40baa15e = 0;
  memset(&DAT_40baa15f,0,0x19);
  DAT_40baa178 = 0x6a66;
  DAT_40baa17a = 0;
  DAT_40baa17b = 0;
  DAT_40baa17c = 0x6a6966;
  DAT_40baa180 = 0x6a6966;
  DAT_40baa184._0_1_ = 'F';
  DAT_40baa184._1_1_ = 'i';
  DAT_40baa184._2_1_ = 'n';
  DAT_40baa184._3_1_ = 'n';
  DAT_40baa188._0_1_ = 'i';
  DAT_40baa188._1_1_ = 's';
  DAT_40baa188._2_1_ = 'h';
  DAT_40baa188._3_1_ = '\0';
  DAT_40baa18c = 0;
  DAT_40baa190 = 0;
  DAT_40baa194 = 0;
  DAT_40baa198 = 0;
  DAT_40baa19c = 0;
  DAT_40baa1a0 = 0;
  DAT_40baa1a4 = 0x6966;
  DAT_40baa1a6 = 0;
  DAT_40baa1a7 = 0;
  DAT_40baa1a8 = 0x6e6966;
  DAT_40baa1ac = 0x6e6966;
  DAT_40baa1b0._0_1_ = 'F';
  DAT_40baa1b0._1_1_ = 'r';
  DAT_40baa1b0._2_1_ = 'e';
  DAT_40baa1b0._3_1_ = 'n';
  DAT_40baa1b4._0_1_ = 'c';
  DAT_40baa1b4._1_1_ = 'h';
  DAT_40baa1b6 = '\0';
  memset(&DAT_40baa1b7,0,0x19);
  DAT_40baa1d0 = 0x7266;
  DAT_40baa1d2 = 0;
  DAT_40baa1d3 = 0;
  DAT_40baa1d4 = 0x617266;
  DAT_40baa1d8 = 0x657266;
  DAT_40baa1dc._0_1_ = 'F';
  DAT_40baa1dc._1_1_ = 'r';
  DAT_40baa1dc._2_1_ = 'i';
  DAT_40baa1dc._3_1_ = 's';
  DAT_40baa1e0._0_1_ = 'i';
  DAT_40baa1e0._1_1_ = 'a';
  DAT_40baa1e0._2_1_ = 'n';
  DAT_40baa1e0._3_1_ = '\0';
  DAT_40baa1e4 = 0;
  DAT_40baa1e8 = 0;
  DAT_40baa1ec = 0;
  DAT_40baa1f0 = 0;
  DAT_40baa1f4 = 0;
  DAT_40baa1f8 = 0;
  DAT_40baa1fc = 0x7966;
  DAT_40baa1fe = 0;
  DAT_40baa1ff = 0;
  DAT_40baa200 = 0x797266;
  DAT_40baa204 = 0x797266;
  DAT_40baa208._0_1_ = 'G';
  DAT_40baa208._1_1_ = 'e';
  DAT_40baa208._2_1_ = 'o';
  DAT_40baa208._3_1_ = 'r';
  DAT_40baa20c._0_1_ = 'g';
  DAT_40baa20c._1_1_ = 'i';
  DAT_40baa20c._2_1_ = 'a';
  DAT_40baa20c._3_1_ = 'n';
  DAT_40baa210 = '\0';
  memset(&DAT_40baa211,0,0x17);
  DAT_40baa228 = 0x616b;
  DAT_40baa22a = 0;
  DAT_40baa22b = 0;
  DAT_40baa22c = 0x74616b;
  DAT_40baa230 = 0x6f6567;
  DAT_40baa234._0_1_ = 'G';
  DAT_40baa234._1_1_ = 'e';
  DAT_40baa234._2_1_ = 'r';
  DAT_40baa234._3_1_ = 'm';
  DAT_40baa238._0_1_ = 'a';
  DAT_40baa238._1_1_ = 'n';
  DAT_40baa23a = '\0';
  memset(&DAT_40baa23b,0,0x19);
  DAT_40baa254 = 0x6564;
  DAT_40baa256 = 0;
  DAT_40baa257 = 0;
  DAT_40baa258 = 0x756564;
  DAT_40baa25c = 0x726567;
  DAT_40baa260._0_1_ = 'G';
  DAT_40baa260._1_1_ = 'a';
  DAT_40baa260._2_1_ = 'e';
  DAT_40baa260._3_1_ = 'l';
  DAT_40baa264._0_1_ = 'i';
  DAT_40baa264._1_1_ = 'c';
  DAT_40baa266 = '\0';
  memset(&DAT_40baa267,0,0x19);
  DAT_40baa280 = 0x6467;
  DAT_40baa282 = 0;
  DAT_40baa283 = 0;
  DAT_40baa284 = 0x616c67;
  DAT_40baa288 = 0x616c67;
  DAT_40baa28c._0_1_ = 'I';
  DAT_40baa28c._1_1_ = 'r';
  DAT_40baa28c._2_1_ = 'i';
  DAT_40baa28c._3_1_ = 's';
  DAT_40baa290._0_1_ = 'h';
  DAT_40baa290._1_1_ = '\0';
  DAT_40baa292 = 0;
  DAT_40baa294 = 0;
  DAT_40baa296 = 0;
  DAT_40baa298 = 0;
  DAT_40baa29a = 0;
  DAT_40baa29c = 0;
  DAT_40baa29e = 0;
  DAT_40baa2a0 = 0;
  DAT_40baa2a2 = 0;
  DAT_40baa2a4 = 0;
  DAT_40baa2a6 = 0;
  DAT_40baa2a8 = 0;
  DAT_40baa2aa = 0;
  DAT_40baa2ac = 0x6167;
  DAT_40baa2ae = 0;
  DAT_40baa2af = 0;
  DAT_40baa2b0 = 0x656c67;
  DAT_40baa2b4 = 0x656c67;
  DAT_40baa2b8._0_1_ = 'G';
  DAT_40baa2b8._1_1_ = 'a';
  DAT_40baa2b8._2_1_ = 'l';
  DAT_40baa2b8._3_1_ = 'l';
  DAT_40baa2bc._0_1_ = 'e';
  DAT_40baa2bc._1_1_ = 'g';
  DAT_40baa2bc._2_1_ = 'a';
  DAT_40baa2bc._3_1_ = 'n';
  DAT_40baa2c0 = '\0';
  memset(&DAT_40baa2c1,0,0x17);
  DAT_40baa2d8 = 0x6c67;
  DAT_40baa2da = 0;
  DAT_40baa2db = 0;
  DAT_40baa2dc = 0x676c67;
  DAT_40baa2e0 = 0x676c67;
  DAT_40baa2e4 = 0x786e614d;
  DAT_40baa2e8 = 0;
  memset(&DAT_40baa2e9,0,0x1b);
  DAT_40baa304 = 0x7667;
  DAT_40baa306 = 0;
  DAT_40baa307 = 0;
  DAT_40baa308 = 0x766c67;
  DAT_40baa30c = 0x766c67;
  DAT_40baa310._0_1_ = 'G';
  DAT_40baa310._1_1_ = 'r';
  DAT_40baa310._2_1_ = 'e';
  DAT_40baa310._3_1_ = 'e';
  DAT_40baa314._0_1_ = 'k';
  DAT_40baa314._1_1_ = '\0';
  DAT_40baa316 = 0;
  DAT_40baa318 = 0;
  DAT_40baa31a = 0;
  DAT_40baa31c = 0;
  DAT_40baa31e = 0;
  DAT_40baa320 = 0;
  DAT_40baa322 = 0;
  DAT_40baa324 = 0;
  DAT_40baa326 = 0;
  DAT_40baa328 = 0;
  DAT_40baa32a = 0;
  DAT_40baa32c = 0;
  DAT_40baa32e = 0;
  DAT_40baa330 = 0x6c65;
  DAT_40baa332 = 0;
  DAT_40baa333 = 0;
  DAT_40baa334 = 0x657267;
  DAT_40baa338 = 0x6c6c65;
  DAT_40baa33c._0_1_ = 'G';
  DAT_40baa33c._1_1_ = 'u';
  DAT_40baa33c._2_1_ = 'a';
  DAT_40baa33c._3_1_ = 'r';
  DAT_40baa340._0_1_ = 'a';
  DAT_40baa340._1_1_ = 'n';
  DAT_40baa340._2_1_ = 'i';
  DAT_40baa340._3_1_ = '\0';
  DAT_40baa344 = 0;
  DAT_40baa348 = 0;
  DAT_40baa34c = 0;
  DAT_40baa350 = 0;
  DAT_40baa354 = 0;
  DAT_40baa358 = 0;
  DAT_40baa35c = 0x6e67;
  DAT_40baa35e = 0;
  DAT_40baa35f = 0;
  DAT_40baa360 = 0x6e7267;
  DAT_40baa364 = 0x6e7267;
  DAT_40baa368._0_1_ = 'G';
  DAT_40baa368._1_1_ = 'u';
  DAT_40baa368._2_1_ = 'j';
  DAT_40baa368._3_1_ = 'a';
  DAT_40baa36c._0_1_ = 'r';
  DAT_40baa36c._1_1_ = 'a';
  DAT_40baa36c._2_1_ = 't';
  DAT_40baa36c._3_1_ = 'i';
  DAT_40baa370 = '\0';
  memset(&DAT_40baa371,0,0x17);
  DAT_40baa388 = 0x7567;
  DAT_40baa38a = 0;
  DAT_40baa38b = 0;
  DAT_40baa38c = 0x6a7567;
  DAT_40baa390 = 0x6a7567;
  DAT_40baa394._0_1_ = 'H';
  DAT_40baa394._1_1_ = 'e';
  DAT_40baa394._2_1_ = 'b';
  DAT_40baa394._3_1_ = 'r';
  DAT_40baa398._0_1_ = 'e';
  DAT_40baa398._1_1_ = 'w';
  DAT_40baa39a = '\0';
  memset(&DAT_40baa39b,0,0x19);
  DAT_40baa3b4 = 0x6568;
  DAT_40baa3b6 = 0;
  DAT_40baa3b7 = 0;
  DAT_40baa3b8 = 0x626568;
  DAT_40baa3bc = 0x626568;
  DAT_40baa3c0._0_1_ = 'H';
  DAT_40baa3c0._1_1_ = 'e';
  DAT_40baa3c0._2_1_ = 'r';
  DAT_40baa3c0._3_1_ = 'e';
  DAT_40baa3c4._0_1_ = 'r';
  DAT_40baa3c4._1_1_ = 'o';
  DAT_40baa3c6 = '\0';
  memset(&DAT_40baa3c7,0,0x19);
  DAT_40baa3e0 = 0x7a68;
  DAT_40baa3e2 = 0;
  DAT_40baa3e3 = 0;
  DAT_40baa3e4 = 0x726568;
  DAT_40baa3e8 = 0x726568;
  DAT_40baa3ec._0_1_ = 'H';
  DAT_40baa3ec._1_1_ = 'i';
  DAT_40baa3ec._2_1_ = 'n';
  DAT_40baa3ec._3_1_ = 'd';
  DAT_40baa3f0._0_1_ = 'i';
  DAT_40baa3f0._1_1_ = '\0';
  DAT_40baa3f2 = 0;
  DAT_40baa3f4 = 0;
  DAT_40baa3f6 = 0;
  DAT_40baa3f8 = 0;
  DAT_40baa3fa = 0;
  DAT_40baa3fc = 0;
  DAT_40baa3fe = 0;
  DAT_40baa400 = 0;
  DAT_40baa402 = 0;
  DAT_40baa404 = 0;
  DAT_40baa406 = 0;
  DAT_40baa408 = 0;
  DAT_40baa40a = 0;
  DAT_40baa40c = 0x6968;
  DAT_40baa40e = 0;
  DAT_40baa40f = 0;
  DAT_40baa410 = 0x6e6968;
  DAT_40baa414 = 0x6e6968;
  DAT_40baa418._0_1_ = 'H';
  DAT_40baa418._1_1_ = 'i';
  DAT_40baa418._2_1_ = 'r';
  DAT_40baa418._3_1_ = 'i';
  DAT_40baa41c._0_1_ = ' ';
  DAT_40baa41c._1_1_ = 'M';
  DAT_40baa41c._2_1_ = 'o';
  DAT_40baa41c._3_1_ = 't';
  DAT_40baa420._0_1_ = 'u';
  DAT_40baa420._1_1_ = '\0';
  DAT_40baa422 = 0;
  DAT_40baa424 = 0;
  DAT_40baa426 = 0;
  DAT_40baa428 = 0;
  DAT_40baa42a = 0;
  DAT_40baa42c = 0;
  DAT_40baa42e = 0;
  DAT_40baa430 = 0;
  DAT_40baa432 = 0;
  DAT_40baa434 = 0;
  DAT_40baa436 = 0;
  DAT_40baa438 = 0x6f68;
  DAT_40baa43a = 0;
  DAT_40baa43b = 0;
  DAT_40baa43c = 0x6f6d68;
  DAT_40baa440 = 0x6f6d68;
  DAT_40baa444._0_1_ = 'H';
  DAT_40baa444._1_1_ = 'u';
  DAT_40baa444._2_1_ = 'n';
  DAT_40baa444._3_1_ = 'g';
  DAT_40baa448._0_1_ = 'a';
  DAT_40baa448._1_1_ = 'r';
  DAT_40baa448._2_1_ = 'i';
  DAT_40baa448._3_1_ = 'a';
  DAT_40baa44c._0_1_ = 'n';
  DAT_40baa44c._1_1_ = '\0';
  DAT_40baa44e = 0;
  DAT_40baa450 = 0;
  DAT_40baa452 = 0;
  DAT_40baa454 = 0;
  DAT_40baa456 = 0;
  DAT_40baa458 = 0;
  DAT_40baa45a = 0;
  DAT_40baa45c = 0;
  DAT_40baa45e = 0;
  DAT_40baa460 = 0;
  DAT_40baa462 = 0;
  DAT_40baa464 = 0x7568;
  DAT_40baa466 = 0;
  DAT_40baa467 = 0;
  DAT_40baa468 = 0x6e7568;
  DAT_40baa46c = 0x6e7568;
  DAT_40baa470._0_1_ = 'I';
  DAT_40baa470._1_1_ = 'c';
  DAT_40baa470._2_1_ = 'e';
  DAT_40baa470._3_1_ = 'l';
  DAT_40baa474._0_1_ = 'a';
  DAT_40baa474._1_1_ = 'n';
  DAT_40baa474._2_1_ = 'd';
  DAT_40baa474._3_1_ = 'i';
  DAT_40baa478._0_1_ = 'c';
  DAT_40baa478._1_1_ = '\0';
  DAT_40baa47a = 0;
  DAT_40baa47c = 0;
  DAT_40baa47e = 0;
  DAT_40baa480 = 0;
  DAT_40baa482 = 0;
  DAT_40baa484 = 0;
  DAT_40baa486 = 0;
  DAT_40baa488 = 0;
  DAT_40baa48a = 0;
  DAT_40baa48c = 0;
  DAT_40baa48e = 0;
  DAT_40baa490 = 0x7369;
  DAT_40baa492 = 0;
  DAT_40baa493 = 0;
  DAT_40baa494 = 0x6c7369;
  DAT_40baa498 = 0x656369;
  DAT_40baa49c._0_1_ = 'I';
  DAT_40baa49c._1_1_ = 'n';
  DAT_40baa49c._2_1_ = 'u';
  DAT_40baa49c._3_1_ = 'k';
  DAT_40baa4a0._0_1_ = 't';
  DAT_40baa4a0._1_1_ = 'i';
  DAT_40baa4a0._2_1_ = 't';
  DAT_40baa4a0._3_1_ = 'u';
  DAT_40baa4a4._0_1_ = 't';
  DAT_40baa4a4._1_1_ = '\0';
  DAT_40baa4a6 = 0;
  DAT_40baa4a8 = 0;
  DAT_40baa4aa = 0;
  DAT_40baa4ac = 0;
  DAT_40baa4ae = 0;
  DAT_40baa4b0 = 0;
  DAT_40baa4b2 = 0;
  DAT_40baa4b4 = 0;
  DAT_40baa4b6 = 0;
  DAT_40baa4b8 = 0;
  DAT_40baa4ba = 0;
  DAT_40baa4bc = 0x7569;
  DAT_40baa4be = 0;
  DAT_40baa4bf = 0;
  DAT_40baa4c0 = 0x756b69;
  DAT_40baa4c4 = 0x756b69;
  DAT_40baa4c8._0_1_ = 'I';
  DAT_40baa4c8._1_1_ = 'n';
  DAT_40baa4c8._2_1_ = 't';
  DAT_40baa4c8._3_1_ = 'e';
  DAT_40baa4cc._0_1_ = 'r';
  DAT_40baa4cc._1_1_ = 'l';
  DAT_40baa4cc._2_1_ = 'i';
  DAT_40baa4cc._3_1_ = 'n';
  DAT_40baa4d0._0_1_ = 'g';
  DAT_40baa4d0._1_1_ = 'u';
  DAT_40baa4d0._2_1_ = 'e';
  DAT_40baa4d0._3_1_ = '\0';
  DAT_40baa4d4 = 0;
  DAT_40baa4d8 = 0;
  DAT_40baa4dc = 0;
  DAT_40baa4e0 = 0;
  DAT_40baa4e4 = 0;
  DAT_40baa4e8 = 0x6569;
  DAT_40baa4ea = 0;
  DAT_40baa4eb = 0;
  DAT_40baa4ec = 0x656c69;
  DAT_40baa4f0 = 0x656c69;
  DAT_40baa4f4._0_1_ = 'I';
  DAT_40baa4f4._1_1_ = 'n';
  DAT_40baa4f4._2_1_ = 't';
  DAT_40baa4f4._3_1_ = 'e';
  DAT_40baa4f8._0_1_ = 'r';
  DAT_40baa4f8._1_1_ = 'l';
  DAT_40baa4f8._2_1_ = 'i';
  DAT_40baa4f8._3_1_ = 'n';
  DAT_40baa4fc._0_1_ = 'g';
  DAT_40baa4fc._1_1_ = 'u';
  DAT_40baa4fc._2_1_ = 'a';
  DAT_40baa4fc._3_1_ = '\0';
  DAT_40baa500 = 0;
  DAT_40baa504 = 0;
  DAT_40baa508 = 0;
  DAT_40baa50c = 0;
  DAT_40baa510 = 0;
  DAT_40baa514 = 0x6169;
  DAT_40baa516 = 0;
  DAT_40baa517 = 0;
  DAT_40baa518 = 0x616e69;
  DAT_40baa51c = 0x616e69;
  DAT_40baa520._0_1_ = 'I';
  DAT_40baa520._1_1_ = 'n';
  DAT_40baa520._2_1_ = 'd';
  DAT_40baa520._3_1_ = 'o';
  DAT_40baa524._0_1_ = 'n';
  DAT_40baa524._1_1_ = 'e';
  DAT_40baa524._2_1_ = 's';
  DAT_40baa524._3_1_ = 'i';
  DAT_40baa528._0_1_ = 'a';
  DAT_40baa528._1_1_ = 'n';
  DAT_40baa52a = '\0';
  memset(&DAT_40baa52b,0,0x15);
  DAT_40baa540 = 0x6469;
  DAT_40baa542 = 0;
  DAT_40baa543 = 0;
  DAT_40baa544 = 0x646e69;
  DAT_40baa548 = 0x646e69;
  DAT_40baa54c = 0x70756e49;
  DAT_40baa550 = 0x716169;
  DAT_40baa554 = 0;
  DAT_40baa558 = 0;
  DAT_40baa55c = 0;
  DAT_40baa560 = 0;
  DAT_40baa564 = 0;
  DAT_40baa568 = 0;
  DAT_40baa56c = 0x6b69;
  DAT_40baa56e = 0;
  DAT_40baa56f = 0;
  DAT_40baa570 = 0x6b7069;
  DAT_40baa574 = 0x6b7069;
  DAT_40baa578._0_1_ = 'I';
  DAT_40baa578._1_1_ = 't';
  DAT_40baa578._2_1_ = 'a';
  DAT_40baa578._3_1_ = 'l';
  DAT_40baa57c._0_1_ = 'i';
  DAT_40baa57c._1_1_ = 'a';
  DAT_40baa57c._2_1_ = 'n';
  DAT_40baa57c._3_1_ = '\0';
  DAT_40baa580 = 0;
  DAT_40baa584 = 0;
  DAT_40baa588 = 0;
  DAT_40baa58c = 0;
  DAT_40baa590 = 0;
  DAT_40baa594 = 0;
  DAT_40baa598 = 0x7469;
  DAT_40baa59a = 0;
  DAT_40baa59b = 0;
  DAT_40baa59c = 0x617469;
  DAT_40baa5a0 = 0x617469;
  DAT_40baa5a4._0_1_ = 'J';
  DAT_40baa5a4._1_1_ = 'a';
  DAT_40baa5a4._2_1_ = 'v';
  DAT_40baa5a4._3_1_ = 'a';
  DAT_40baa5a8._0_1_ = 'n';
  DAT_40baa5a8._1_1_ = 'e';
  DAT_40baa5a8._2_1_ = 's';
  DAT_40baa5a8._3_1_ = 'e';
  DAT_40baa5ac = '\0';
  memset(&DAT_40baa5ad,0,0x17);
  DAT_40baa5c4 = 0x766a;
  DAT_40baa5c6 = 0;
  DAT_40baa5c7 = 0;
  DAT_40baa5c8 = 0x77616a;
  DAT_40baa5cc = 0x76616a;
  DAT_40baa5d0._0_1_ = 'J';
  DAT_40baa5d0._1_1_ = 'a';
  DAT_40baa5d0._2_1_ = 'p';
  DAT_40baa5d0._3_1_ = 'a';
  DAT_40baa5d4._0_1_ = 'n';
  DAT_40baa5d4._1_1_ = 'e';
  DAT_40baa5d4._2_1_ = 's';
  DAT_40baa5d4._3_1_ = 'e';
  DAT_40baa5d8 = '\0';
  memset(&DAT_40baa5d9,0,0x17);
  DAT_40baa5f0 = 0x616a;
  DAT_40baa5f2 = 0;
  DAT_40baa5f3 = 0;
  DAT_40baa5f4 = 0x6e706a;
  DAT_40baa5f8 = 0x6e706a;
  DAT_40baa5fc._0_1_ = 'K';
  DAT_40baa5fc._1_1_ = 'a';
  DAT_40baa5fc._2_1_ = 'l';
  DAT_40baa5fc._3_1_ = 'a';
  DAT_40baa600._0_1_ = 'a';
  DAT_40baa600._1_1_ = 'l';
  DAT_40baa600._2_1_ = 'l';
  DAT_40baa600._3_1_ = 'i';
  DAT_40baa604._0_1_ = 's';
  DAT_40baa604._1_1_ = 'u';
  DAT_40baa604._2_1_ = 't';
  DAT_40baa604._3_1_ = '\0';
  DAT_40baa608 = 0;
  DAT_40baa60c = 0;
  DAT_40baa610 = 0;
  DAT_40baa614 = 0;
  DAT_40baa618 = 0;
  DAT_40baa61c = 0x6c6b;
  DAT_40baa61e = 0;
  DAT_40baa61f = 0;
  DAT_40baa620 = 0x6c616b;
  DAT_40baa624 = 0x6c616b;
  DAT_40baa628._0_1_ = 'K';
  DAT_40baa628._1_1_ = 'a';
  DAT_40baa628._2_1_ = 'n';
  DAT_40baa628._3_1_ = 'n';
  DAT_40baa62c._0_1_ = 'a';
  DAT_40baa62c._1_1_ = 'd';
  DAT_40baa62c._2_1_ = 'a';
  DAT_40baa62c._3_1_ = '\0';
  DAT_40baa630 = 0;
  DAT_40baa634 = 0;
  DAT_40baa638 = 0;
  DAT_40baa63c = 0;
  DAT_40baa640 = 0;
  DAT_40baa644 = 0;
  DAT_40baa648 = 0x6e6b;
  DAT_40baa64a = 0;
  DAT_40baa64b = 0;
  DAT_40baa64c = 0x6e616b;
  DAT_40baa650 = 0x6e616b;
  DAT_40baa654._0_1_ = 'K';
  DAT_40baa654._1_1_ = 'a';
  DAT_40baa654._2_1_ = 's';
  DAT_40baa654._3_1_ = 'h';
  DAT_40baa658._0_1_ = 'm';
  DAT_40baa658._1_1_ = 'i';
  DAT_40baa658._2_1_ = 'r';
  DAT_40baa658._3_1_ = 'i';
  DAT_40baa65c = '\0';
  memset(&DAT_40baa65d,0,0x17);
  DAT_40baa674 = 0x736b;
  DAT_40baa676 = 0;
  DAT_40baa677 = 0;
  DAT_40baa678 = 0x73616b;
  DAT_40baa67c = 0x73616b;
  DAT_40baa680 = 0x617a614b;
  DAT_40baa684 = 0x686b;
  DAT_40baa686 = 0;
  memset(&DAT_40baa687,0,0x19);
  DAT_40baa6a0 = 0x6b6b;
  DAT_40baa6a2 = 0;
  DAT_40baa6a3 = 0;
  DAT_40baa6a4 = 0x7a616b;
  DAT_40baa6a8 = 0x7a616b;
  DAT_40baa6ac._0_1_ = 'K';
  DAT_40baa6ac._1_1_ = 'h';
  DAT_40baa6ac._2_1_ = 'm';
  DAT_40baa6ac._3_1_ = 'e';
  DAT_40baa6b0._0_1_ = 'r';
  DAT_40baa6b0._1_1_ = '\0';
  DAT_40baa6b2 = 0;
  DAT_40baa6b4 = 0;
  DAT_40baa6b6 = 0;
  DAT_40baa6b8 = 0;
  DAT_40baa6ba = 0;
  DAT_40baa6bc = 0;
  DAT_40baa6be = 0;
  DAT_40baa6c0 = 0;
  DAT_40baa6c2 = 0;
  DAT_40baa6c4 = 0;
  DAT_40baa6c6 = 0;
  DAT_40baa6c8 = 0;
  DAT_40baa6ca = 0;
  DAT_40baa6cc = 0x6d6b;
  DAT_40baa6ce = 0;
  DAT_40baa6cf = 0;
  DAT_40baa6d0 = 0x6d686b;
  DAT_40baa6d4 = 0x6d686b;
  DAT_40baa6d8 = 0x756b694b;
  DAT_40baa6dc = 0x7579;
  DAT_40baa6de = 0;
  memset(&DAT_40baa6df,0,0x19);
  DAT_40baa6f8 = 0x696b;
  DAT_40baa6fa = 0;
  DAT_40baa6fb = 0;
  DAT_40baa6fc = 0x6b696b;
  DAT_40baa700 = 0x6b696b;
  DAT_40baa704._0_1_ = 'K';
  DAT_40baa704._1_1_ = 'i';
  DAT_40baa704._2_1_ = 'n';
  DAT_40baa704._3_1_ = 'y';
  DAT_40baa708._0_1_ = 'a';
  DAT_40baa708._1_1_ = 'r';
  DAT_40baa708._2_1_ = 'w';
  DAT_40baa708._3_1_ = 'a';
  DAT_40baa70c._0_1_ = 'n';
  DAT_40baa70c._1_1_ = 'd';
  DAT_40baa70c._2_1_ = 'a';
  DAT_40baa70c._3_1_ = '\0';
  DAT_40baa710 = 0;
  DAT_40baa714 = 0;
  DAT_40baa718 = 0;
  DAT_40baa71c = 0;
  DAT_40baa720 = 0;
  DAT_40baa724 = 0x7772;
  DAT_40baa726 = 0;
  DAT_40baa727 = 0;
  DAT_40baa728 = 0x6e696b;
  DAT_40baa72c = 0x6e696b;
  DAT_40baa730 = 0x6772694b;
  DAT_40baa734 = 0x7a6968;
  DAT_40baa738 = 0;
  DAT_40baa73c = 0;
  DAT_40baa740 = 0;
  DAT_40baa744 = 0;
  DAT_40baa748 = 0;
  DAT_40baa74c = 0;
  DAT_40baa750 = 0x796b;
  DAT_40baa752 = 0;
  DAT_40baa753 = 0;
  DAT_40baa754 = 0x72696b;
  DAT_40baa758 = 0x72696b;
  DAT_40baa75c = 0x696d6f4b;
  DAT_40baa760 = 0;
  memset(&DAT_40baa761,0,0x1b);
  DAT_40baa77c = 0x766b;
  DAT_40baa77e = 0;
  DAT_40baa77f = 0;
  DAT_40baa780 = 0x6d6f6b;
  DAT_40baa784 = 0x6d6f6b;
  DAT_40baa788._0_1_ = 'K';
  DAT_40baa788._1_1_ = 'o';
  DAT_40baa788._2_1_ = 'r';
  DAT_40baa788._3_1_ = 'e';
  DAT_40baa78c._0_1_ = 'a';
  DAT_40baa78c._1_1_ = 'n';
  DAT_40baa78e = '\0';
  memset(&DAT_40baa78f,0,0x19);
  DAT_40baa7a8 = 0x6f6b;
  DAT_40baa7aa = 0;
  DAT_40baa7ab = 0;
  DAT_40baa7ac = 0x726f6b;
  DAT_40baa7b0 = 0x726f6b;
  DAT_40baa7b4._0_1_ = 'K';
  DAT_40baa7b4._1_1_ = 'u';
  DAT_40baa7b4._2_1_ = 'a';
  DAT_40baa7b4._3_1_ = 'n';
  DAT_40baa7b8._0_1_ = 'y';
  DAT_40baa7b8._1_1_ = 'a';
  DAT_40baa7b8._2_1_ = 'm';
  DAT_40baa7b8._3_1_ = 'a';
  DAT_40baa7bc = '\0';
  memset(&DAT_40baa7bd,0,0x17);
  DAT_40baa7d4 = 0x6a6b;
  DAT_40baa7d6 = 0;
  DAT_40baa7d7 = 0;
  DAT_40baa7d8 = 0x61756b;
  DAT_40baa7dc = 0x61756b;
  DAT_40baa7e0._0_1_ = 'K';
  DAT_40baa7e0._1_1_ = 'u';
  DAT_40baa7e0._2_1_ = 'r';
  DAT_40baa7e0._3_1_ = 'd';
  DAT_40baa7e4._0_1_ = 'i';
  DAT_40baa7e4._1_1_ = 's';
  DAT_40baa7e4._2_1_ = 'h';
  DAT_40baa7e4._3_1_ = '\0';
  DAT_40baa7e8 = 0;
  DAT_40baa7ec = 0;
  DAT_40baa7f0 = 0;
  DAT_40baa7f4 = 0;
  DAT_40baa7f8 = 0;
  DAT_40baa7fc = 0;
  DAT_40baa800 = 0x756b;
  DAT_40baa802 = 0;
  DAT_40baa803 = 0;
  DAT_40baa804 = 0x72756b;
  DAT_40baa808 = 0x72756b;
  DAT_40baa80c = 0x6f614c;
  DAT_40baa810 = 0;
  DAT_40baa814 = 0;
  DAT_40baa818 = 0;
  DAT_40baa81c = 0;
  DAT_40baa820 = 0;
  DAT_40baa824 = 0;
  DAT_40baa828 = 0;
  DAT_40baa82c = 0x6f6c;
  DAT_40baa82e = 0;
  DAT_40baa82f = 0;
  DAT_40baa830 = 0x6f616c;
  DAT_40baa834 = 0x6f616c;
  DAT_40baa838._0_1_ = 'L';
  DAT_40baa838._1_1_ = 'a';
  DAT_40baa838._2_1_ = 't';
  DAT_40baa838._3_1_ = 'i';
  DAT_40baa83c._0_1_ = 'n';
  DAT_40baa83c._1_1_ = '\0';
  DAT_40baa83e = 0;
  DAT_40baa840 = 0;
  DAT_40baa842 = 0;
  DAT_40baa844 = 0;
  DAT_40baa846 = 0;
  DAT_40baa848 = 0;
  DAT_40baa84a = 0;
  DAT_40baa84c = 0;
  DAT_40baa84e = 0;
  DAT_40baa850 = 0;
  DAT_40baa852 = 0;
  DAT_40baa854 = 0;
  DAT_40baa856 = 0;
  DAT_40baa858 = 0x616c;
  DAT_40baa85a = 0;
  DAT_40baa85b = 0;
  DAT_40baa85c = 0x74616c;
  DAT_40baa860 = 0x74616c;
  DAT_40baa864._0_1_ = 'L';
  DAT_40baa864._1_1_ = 'a';
  DAT_40baa864._2_1_ = 't';
  DAT_40baa864._3_1_ = 'v';
  DAT_40baa868._0_1_ = 'i';
  DAT_40baa868._1_1_ = 'a';
  DAT_40baa868._2_1_ = 'n';
  DAT_40baa868._3_1_ = '\0';
  DAT_40baa86c = 0;
  DAT_40baa870 = 0;
  DAT_40baa874 = 0;
  DAT_40baa878 = 0;
  DAT_40baa87c = 0;
  DAT_40baa880 = 0;
  DAT_40baa884 = 0x766c;
  DAT_40baa886 = 0;
  DAT_40baa887 = 0;
  DAT_40baa888 = 0x76616c;
  DAT_40baa88c = 0x76616c;
  DAT_40baa890._0_1_ = 'L';
  DAT_40baa890._1_1_ = 'i';
  DAT_40baa890._2_1_ = 'n';
  DAT_40baa890._3_1_ = 'g';
  DAT_40baa894._0_1_ = 'a';
  DAT_40baa894._1_1_ = 'l';
  DAT_40baa894._2_1_ = 'a';
  DAT_40baa894._3_1_ = '\0';
  DAT_40baa898 = 0;
  DAT_40baa89c = 0;
  DAT_40baa8a0 = 0;
  DAT_40baa8a4 = 0;
  DAT_40baa8a8 = 0;
  DAT_40baa8ac = 0;
  DAT_40baa8b0 = 0x6e6c;
  DAT_40baa8b2 = 0;
  DAT_40baa8b3 = 0;
  DAT_40baa8b4 = 0x6e696c;
  DAT_40baa8b8 = 0x6e696c;
  DAT_40baa8bc._0_1_ = 'L';
  DAT_40baa8bc._1_1_ = 'i';
  DAT_40baa8bc._2_1_ = 't';
  DAT_40baa8bc._3_1_ = 'h';
  DAT_40baa8c0._0_1_ = 'u';
  DAT_40baa8c0._1_1_ = 'a';
  DAT_40baa8c0._2_1_ = 'n';
  DAT_40baa8c0._3_1_ = 'i';
  DAT_40baa8c4._0_1_ = 'a';
  DAT_40baa8c4._1_1_ = 'n';
  DAT_40baa8c6 = '\0';
  memset(&DAT_40baa8c7,0,0x15);
  DAT_40baa8dc = 0x746c;
  DAT_40baa8de = 0;
  DAT_40baa8df = 0;
  DAT_40baa8e0 = 0x74696c;
  DAT_40baa8e4 = 0x74696c;
  DAT_40baa8e8._0_1_ = 'L';
  DAT_40baa8e8._1_1_ = 'e';
  DAT_40baa8e8._2_1_ = 't';
  DAT_40baa8e8._3_1_ = 'z';
  DAT_40baa8ec._0_1_ = 'e';
  DAT_40baa8ec._1_1_ = 'b';
  DAT_40baa8ec._2_1_ = 'u';
  DAT_40baa8ec._3_1_ = 'r';
  DAT_40baa8f0._0_1_ = 'g';
  DAT_40baa8f0._1_1_ = 'e';
  DAT_40baa8f0._2_1_ = 's';
  DAT_40baa8f0._3_1_ = 'c';
  DAT_40baa8f4._0_1_ = 'h';
  DAT_40baa8f4._1_1_ = '\0';
  DAT_40baa8f6 = 0;
  DAT_40baa8f8 = 0;
  DAT_40baa8fa = 0;
  DAT_40baa8fc = 0;
  DAT_40baa8fe = 0;
  DAT_40baa900 = 0;
  DAT_40baa902 = 0;
  DAT_40baa904 = 0;
  DAT_40baa906 = 0;
  DAT_40baa908 = 0x626c;
  DAT_40baa90a = 0;
  DAT_40baa90b = 0;
  DAT_40baa90c = 0x7a746c;
  DAT_40baa910 = 0x7a746c;
  DAT_40baa914._0_1_ = 'M';
  DAT_40baa914._1_1_ = 'a';
  DAT_40baa914._2_1_ = 'c';
  DAT_40baa914._3_1_ = 'e';
  DAT_40baa918._0_1_ = 'd';
  DAT_40baa918._1_1_ = 'o';
  DAT_40baa918._2_1_ = 'n';
  DAT_40baa918._3_1_ = 'i';
  DAT_40baa91c._0_1_ = 'a';
  DAT_40baa91c._1_1_ = 'n';
  DAT_40baa91e = '\0';
  memset(&DAT_40baa91f,0,0x15);
  DAT_40baa934 = 0x6b6d;
  DAT_40baa936 = 0;
  DAT_40baa937 = 0;
  DAT_40baa938 = 0x646b6d;
  DAT_40baa93c = 0x63616d;
  DAT_40baa940._0_1_ = 'M';
  DAT_40baa940._1_1_ = 'a';
  DAT_40baa940._2_1_ = 'r';
  DAT_40baa940._3_1_ = 's';
  DAT_40baa944._0_1_ = 'h';
  DAT_40baa944._1_1_ = 'a';
  DAT_40baa944._2_1_ = 'l';
  DAT_40baa944._3_1_ = 'l';
  DAT_40baa948 = '\0';
  memset(&DAT_40baa949,0,0x17);
  DAT_40baa960 = 0x686d;
  DAT_40baa962 = 0;
  DAT_40baa963 = 0;
  DAT_40baa964 = 0x68616d;
  DAT_40baa968 = 0x68616d;
  DAT_40baa96c._0_1_ = 'M';
  DAT_40baa96c._1_1_ = 'a';
  DAT_40baa96c._2_1_ = 'l';
  DAT_40baa96c._3_1_ = 'a';
  DAT_40baa970._0_1_ = 'y';
  DAT_40baa970._1_1_ = 'a';
  DAT_40baa970._2_1_ = 'l';
  DAT_40baa970._3_1_ = 'a';
  DAT_40baa974._0_1_ = 'm';
  DAT_40baa974._1_1_ = '\0';
  DAT_40baa976 = 0;
  DAT_40baa978 = 0;
  DAT_40baa97a = 0;
  DAT_40baa97c = 0;
  DAT_40baa97e = 0;
  DAT_40baa980 = 0;
  DAT_40baa982 = 0;
  DAT_40baa984 = 0;
  DAT_40baa986 = 0;
  DAT_40baa988 = 0;
  DAT_40baa98a = 0;
  DAT_40baa98c = 0x6c6d;
  DAT_40baa98e = 0;
  DAT_40baa98f = 0;
  DAT_40baa990 = 0x6c616d;
  DAT_40baa994 = 0x6c616d;
  DAT_40baa998._0_1_ = 'M';
  DAT_40baa998._1_1_ = 'a';
  DAT_40baa998._2_1_ = 'o';
  DAT_40baa998._3_1_ = 'r';
  DAT_40baa99c._0_1_ = 'i';
  DAT_40baa99c._1_1_ = '\0';
  DAT_40baa99e = 0;
  DAT_40baa9a0 = 0;
  DAT_40baa9a2 = 0;
  DAT_40baa9a4 = 0;
  DAT_40baa9a6 = 0;
  DAT_40baa9a8 = 0;
  DAT_40baa9aa = 0;
  DAT_40baa9ac = 0;
  DAT_40baa9ae = 0;
  DAT_40baa9b0 = 0;
  DAT_40baa9b2 = 0;
  DAT_40baa9b4 = 0;
  DAT_40baa9b6 = 0;
  DAT_40baa9b8 = 0x696d;
  DAT_40baa9ba = 0;
  DAT_40baa9bb = 0;
  DAT_40baa9bc = 0x69726d;
  DAT_40baa9c0 = 0x6f616d;
  DAT_40baa9c4._0_1_ = 'M';
  DAT_40baa9c4._1_1_ = 'a';
  DAT_40baa9c4._2_1_ = 'r';
  DAT_40baa9c4._3_1_ = 'a';
  DAT_40baa9c8._0_1_ = 't';
  DAT_40baa9c8._1_1_ = 'h';
  DAT_40baa9c8._2_1_ = 'i';
  DAT_40baa9c8._3_1_ = '\0';
  DAT_40baa9cc = 0;
  DAT_40baa9d0 = 0;
  DAT_40baa9d4 = 0;
  DAT_40baa9d8 = 0;
  DAT_40baa9dc = 0;
  DAT_40baa9e0 = 0;
  DAT_40baa9e4 = 0x726d;
  DAT_40baa9e6 = 0;
  DAT_40baa9e7 = 0;
  DAT_40baa9e8 = 0x72616d;
  DAT_40baa9ec = 0x72616d;
  DAT_40baa9f0._0_1_ = 'M';
  DAT_40baa9f0._1_1_ = 'a';
  DAT_40baa9f0._2_1_ = 'l';
  DAT_40baa9f0._3_1_ = 'a';
  DAT_40baa9f4._0_1_ = 'y';
  DAT_40baa9f4._1_1_ = '\0';
  DAT_40baa9f6 = 0;
  DAT_40baa9f8 = 0;
  DAT_40baa9fa = 0;
  DAT_40baa9fc = 0;
  DAT_40baa9fe = 0;
  DAT_40baaa00 = 0;
  DAT_40baaa02 = 0;
  DAT_40baaa04 = 0;
  DAT_40baaa06 = 0;
  DAT_40baaa08 = 0;
  DAT_40baaa0a = 0;
  DAT_40baaa0c = 0;
  DAT_40baaa0e = 0;
  DAT_40baaa10 = 0x736d;
  DAT_40baaa12 = 0;
  DAT_40baaa13 = 0;
  DAT_40baaa14 = 0x61736d;
  DAT_40baaa18 = 0x79616d;
  DAT_40baaa1c._0_1_ = 'M';
  DAT_40baaa1c._1_1_ = 'a';
  DAT_40baaa1c._2_1_ = 'l';
  DAT_40baaa1c._3_1_ = 'a';
  DAT_40baaa20._0_1_ = 'g';
  DAT_40baaa20._1_1_ = 'a';
  DAT_40baaa20._2_1_ = 's';
  DAT_40baaa20._3_1_ = 'y';
  DAT_40baaa24 = '\0';
  memset(&DAT_40baaa25,0,0x17);
  DAT_40baaa3c = 0x676d;
  DAT_40baaa3e = 0;
  DAT_40baaa3f = 0;
  DAT_40baaa40 = 0x676c6d;
  DAT_40baaa44 = 0x676c6d;
  DAT_40baaa48._0_1_ = 'M';
  DAT_40baaa48._1_1_ = 'a';
  DAT_40baaa48._2_1_ = 'l';
  DAT_40baaa48._3_1_ = 't';
  DAT_40baaa4c._0_1_ = 'e';
  DAT_40baaa4c._1_1_ = 's';
  DAT_40baaa4c._2_1_ = 'e';
  DAT_40baaa4c._3_1_ = '\0';
  DAT_40baaa50 = 0;
  DAT_40baaa54 = 0;
  DAT_40baaa58 = 0;
  DAT_40baaa5c = 0;
  DAT_40baaa60 = 0;
  DAT_40baaa64 = 0;
  DAT_40baaa68 = 0x746d;
  DAT_40baaa6a = 0;
  DAT_40baaa6b = 0;
  DAT_40baaa6c = 0x746c6d;
  DAT_40baaa70 = 0x746c6d;
  DAT_40baaa74._0_1_ = 'M';
  DAT_40baaa74._1_1_ = 'o';
  DAT_40baaa74._2_1_ = 'l';
  DAT_40baaa74._3_1_ = 'd';
  DAT_40baaa78._0_1_ = 'a';
  DAT_40baaa78._1_1_ = 'v';
  DAT_40baaa78._2_1_ = 'i';
  DAT_40baaa78._3_1_ = 'a';
  DAT_40baaa7c._0_1_ = 'n';
  DAT_40baaa7c._1_1_ = '\0';
  DAT_40baaa7e = 0;
  DAT_40baaa80 = 0;
  DAT_40baaa82 = 0;
  DAT_40baaa84 = 0;
  DAT_40baaa86 = 0;
  DAT_40baaa88 = 0;
  DAT_40baaa8a = 0;
  DAT_40baaa8c = 0;
  DAT_40baaa8e = 0;
  DAT_40baaa90 = 0;
  DAT_40baaa92 = 0;
  DAT_40baaa94 = 0x6f6d;
  DAT_40baaa96 = 0;
  DAT_40baaa97 = 0;
  DAT_40baaa98 = 0x6c6f6d;
  DAT_40baaa9c = 0x6c6f6d;
  DAT_40baaaa0._0_1_ = 'M';
  DAT_40baaaa0._1_1_ = 'o';
  DAT_40baaaa0._2_1_ = 'n';
  DAT_40baaaa0._3_1_ = 'g';
  DAT_40baaaa4._0_1_ = 'o';
  DAT_40baaaa4._1_1_ = 'l';
  DAT_40baaaa4._2_1_ = 'i';
  DAT_40baaaa4._3_1_ = 'a';
  DAT_40baaaa8._0_1_ = 'n';
  DAT_40baaaa8._1_1_ = '\0';
  DAT_40baaaaa = 0;
  DAT_40baaaac = 0;
  DAT_40baaaae = 0;
  DAT_40baaab0 = 0;
  DAT_40baaab2 = 0;
  DAT_40baaab4 = 0;
  DAT_40baaab6 = 0;
  DAT_40baaab8 = 0;
  DAT_40baaaba = 0;
  DAT_40baaabc = 0;
  DAT_40baaabe = 0;
  DAT_40baaac0 = 0x6e6d;
  DAT_40baaac2 = 0;
  DAT_40baaac3 = 0;
  DAT_40baaac4 = 0x6e6f6d;
  DAT_40baaac8 = 0x6e6f6d;
  DAT_40baaacc = 0x7275614e;
  DAT_40baaad0 = 0x75;
  DAT_40baaad2 = 0;
  DAT_40baaad4 = 0;
  DAT_40baaad6 = 0;
  DAT_40baaad8 = 0;
  DAT_40baaada = 0;
  DAT_40baaadc = 0;
  DAT_40baaade = 0;
  DAT_40baaae0 = 0;
  DAT_40baaae2 = 0;
  DAT_40baaae4 = 0;
  DAT_40baaae6 = 0;
  DAT_40baaae8 = 0;
  DAT_40baaaea = 0;
  DAT_40baaaec = 0x616e;
  DAT_40baaaee = 0;
  DAT_40baaaef = 0;
  DAT_40baaaf0 = 0x75616e;
  DAT_40baaaf4 = 0x75616e;
  DAT_40baaaf8 = 0x6176614e;
  DAT_40baaafc = 0x6f6a;
  DAT_40baaafe = 0;
  memset(&DAT_40baaaff,0,0x19);
  DAT_40baab18 = 0x766e;
  DAT_40baab1a = 0;
  DAT_40baab1b = 0;
  DAT_40baab1c = 0x76616e;
  DAT_40baab20 = 0x76616e;
  DAT_40baab24._0_1_ = 'N';
  DAT_40baab24._1_1_ = 'd';
  DAT_40baab24._2_1_ = 'e';
  DAT_40baab24._3_1_ = 'b';
  DAT_40baab28._0_1_ = 'e';
  DAT_40baab28._1_1_ = 'l';
  DAT_40baab28._2_1_ = 'e';
  DAT_40baab28._3_1_ = ',';
  DAT_40baab2c._0_1_ = ' ';
  DAT_40baab2c._1_1_ = 'S';
  DAT_40baab2c._2_1_ = 'o';
  DAT_40baab2c._3_1_ = 'u';
  DAT_40baab30._0_1_ = 't';
  DAT_40baab30._1_1_ = 'h';
  DAT_40baab32 = '\0';
  memset(&DAT_40baab33,0,0x11);
  DAT_40baab44 = 0x726e;
  DAT_40baab46 = 0;
  DAT_40baab47 = 0;
  DAT_40baab48 = 0x6c626e;
  DAT_40baab4c = 0x6c626e;
  DAT_40baab50._0_1_ = 'N';
  DAT_40baab50._1_1_ = 'd';
  DAT_40baab50._2_1_ = 'e';
  DAT_40baab50._3_1_ = 'b';
  DAT_40baab54._0_1_ = 'e';
  DAT_40baab54._1_1_ = 'l';
  DAT_40baab54._2_1_ = 'e';
  DAT_40baab54._3_1_ = ',';
  DAT_40baab58._0_1_ = ' ';
  DAT_40baab58._1_1_ = 'N';
  DAT_40baab58._2_1_ = 'o';
  DAT_40baab58._3_1_ = 'r';
  DAT_40baab5c._0_1_ = 't';
  DAT_40baab5c._1_1_ = 'h';
  DAT_40baab5e = '\0';
  memset(&DAT_40baab5f,0,0x11);
  DAT_40baab70 = 0x646e;
  DAT_40baab72 = 0;
  DAT_40baab73 = 0;
  DAT_40baab74 = 0x65646e;
  DAT_40baab78 = 0x65646e;
  DAT_40baab7c = 0x6e6f644e;
  DAT_40baab80 = 0x6167;
  DAT_40baab82 = 0;
  memset(&DAT_40baab83,0,0x19);
  DAT_40baab9c = 0x676e;
  DAT_40baab9e = 0;
  DAT_40baab9f = 0;
  DAT_40baaba0 = 0x6f646e;
  DAT_40baaba4 = 0x6f646e;
  DAT_40baaba8._0_1_ = 'N';
  DAT_40baaba8._1_1_ = 'e';
  DAT_40baaba8._2_1_ = 'p';
  DAT_40baaba8._3_1_ = 'a';
  DAT_40baabac._0_1_ = 'l';
  DAT_40baabac._1_1_ = 'i';
  DAT_40baabae = '\0';
  memset(&DAT_40baabaf,0,0x19);
  DAT_40baabc8 = 0x656e;
  DAT_40baabca = 0;
  DAT_40baabcb = 0;
  DAT_40baabcc = 0x70656e;
  DAT_40baabd0 = 0x70656e;
  DAT_40baabd4._0_1_ = 'N';
  DAT_40baabd4._1_1_ = 'o';
  DAT_40baabd4._2_1_ = 'r';
  DAT_40baabd4._3_1_ = 'w';
  DAT_40baabd8._0_1_ = 'e';
  DAT_40baabd8._1_1_ = 'g';
  DAT_40baabd8._2_1_ = 'i';
  DAT_40baabd8._3_1_ = 'a';
  DAT_40baabdc._0_1_ = 'n';
  DAT_40baabdc._1_1_ = '\0';
  DAT_40baabde = 0;
  DAT_40baabe0 = 0;
  DAT_40baabe2 = 0;
  DAT_40baabe4 = 0;
  DAT_40baabe6 = 0;
  DAT_40baabe8 = 0;
  DAT_40baabea = 0;
  DAT_40baabec = 0;
  DAT_40baabee = 0;
  DAT_40baabf0 = 0;
  DAT_40baabf2 = 0;
  DAT_40baabf4 = 0x6f6e;
  DAT_40baabf6 = 0;
  DAT_40baabf7 = 0;
  DAT_40baabf8 = 0x726f6e;
  DAT_40baabfc = 0x726f6e;
  DAT_40baac00._0_1_ = 'N';
  DAT_40baac00._1_1_ = 'o';
  DAT_40baac00._2_1_ = 'r';
  DAT_40baac00._3_1_ = 'w';
  DAT_40baac04._0_1_ = 'e';
  DAT_40baac04._1_1_ = 'g';
  DAT_40baac04._2_1_ = 'i';
  DAT_40baac04._3_1_ = 'a';
  DAT_40baac08._0_1_ = 'n';
  DAT_40baac08._1_1_ = ' ';
  DAT_40baac08._2_1_ = 'N';
  DAT_40baac08._3_1_ = 'y';
  DAT_40baac0c._0_1_ = 'n';
  DAT_40baac0c._1_1_ = 'o';
  DAT_40baac0c._2_1_ = 'r';
  DAT_40baac0c._3_1_ = 's';
  DAT_40baac10._0_1_ = 'k';
  DAT_40baac10._1_1_ = '\0';
  DAT_40baac12 = 0;
  DAT_40baac14 = 0;
  DAT_40baac16 = 0;
  DAT_40baac18 = 0;
  DAT_40baac1a = 0;
  DAT_40baac1c = 0;
  DAT_40baac1e = 0;
  DAT_40baac20 = 0x6e6e;
  DAT_40baac22 = 0;
  DAT_40baac23 = 0;
  DAT_40baac24 = 0x6f6e6e;
  DAT_40baac28 = 0x6f6e6e;
  DAT_40baac2c._0_1_ = 'N';
  DAT_40baac2c._1_1_ = 'o';
  DAT_40baac2c._2_1_ = 'r';
  DAT_40baac2c._3_1_ = 'w';
  DAT_40baac30._0_1_ = 'e';
  DAT_40baac30._1_1_ = 'g';
  DAT_40baac30._2_1_ = 'i';
  DAT_40baac30._3_1_ = 'a';
  DAT_40baac34._0_1_ = 'n';
  DAT_40baac34._1_1_ = ' ';
  DAT_40baac34._2_1_ = 'B';
  DAT_40baac34._3_1_ = 'o';
  DAT_40baac38._0_1_ = 'k';
  DAT_40baac38._1_1_ = 'm';
  DAT_40baac38._2_1_ = 'a';
  DAT_40baac38._3_1_ = 'a';
  DAT_40baac3c._0_1_ = 'l';
  DAT_40baac3c._1_1_ = '\0';
  DAT_40baac3e = 0;
  DAT_40baac40 = 0;
  DAT_40baac42 = 0;
  DAT_40baac44 = 0;
  DAT_40baac46 = 0;
  DAT_40baac48 = 0;
  DAT_40baac4a = 0;
  DAT_40baac4c = 0x626e;
  DAT_40baac4e = 0;
  DAT_40baac4f = 0;
  DAT_40baac50 = 0x626f6e;
  DAT_40baac54 = 0x626f6e;
  DAT_40baac58._0_1_ = 'C';
  DAT_40baac58._1_1_ = 'h';
  DAT_40baac58._2_1_ = 'i';
  DAT_40baac58._3_1_ = 'c';
  DAT_40baac5c._0_1_ = 'h';
  DAT_40baac5c._1_1_ = 'e';
  DAT_40baac5c._2_1_ = 'w';
  DAT_40baac5c._3_1_ = 'a';
  DAT_40baac60._0_1_ = ';';
  DAT_40baac60._1_1_ = ' ';
  DAT_40baac60._2_1_ = 'N';
  DAT_40baac60._3_1_ = 'y';
  DAT_40baac64._0_1_ = 'a';
  DAT_40baac64._1_1_ = 'n';
  DAT_40baac64._2_1_ = 'j';
  DAT_40baac64._3_1_ = 'a';
  DAT_40baac68 = '\0';
  DAT_40baac69 = 0;
  DAT_40baac6a = 0;
  DAT_40baac6b = 0;
  DAT_40baac6c = 0;
  DAT_40baac6d = 0;
  DAT_40baac6e = 0;
  DAT_40baac6f = 0;
  DAT_40baac70 = 0;
  DAT_40baac71 = 0;
  DAT_40baac72 = 0;
  DAT_40baac73 = 0;
  DAT_40baac74 = 0;
  DAT_40baac75 = 0;
  DAT_40baac76 = 0;
  DAT_40baac77 = 0;
  DAT_40baac78 = 0x796e;
  DAT_40baac7a = 0;
  DAT_40baac7b = 0;
  DAT_40baac7c = 0x61796e;
  DAT_40baac80 = 0x61796e;
  DAT_40baac84._0_1_ = 'O';
  DAT_40baac84._1_1_ = 'c';
  DAT_40baac84._2_1_ = 'c';
  DAT_40baac84._3_1_ = 'i';
  DAT_40baac88._0_1_ = 't';
  DAT_40baac88._1_1_ = 'a';
  DAT_40baac88._2_1_ = 'n';
  DAT_40baac88._3_1_ = '\0';
  DAT_40baac8c = 0;
  DAT_40baac90 = 0;
  DAT_40baac94 = 0;
  DAT_40baac98 = 0;
  DAT_40baac9c = 0;
  DAT_40baaca0 = 0;
  DAT_40baaca4 = 0x636f;
  DAT_40baaca6 = 0;
  DAT_40baaca7 = 0;
  DAT_40baaca8 = 0x69636f;
  DAT_40baacac = 0x69636f;
  DAT_40baacb0 = 0x7969724f;
  DAT_40baacb4 = 0x61;
  DAT_40baacb6 = 0;
  DAT_40baacb8 = 0;
  DAT_40baacba = 0;
  DAT_40baacbc = 0;
  DAT_40baacbe = 0;
  DAT_40baacc0 = 0;
  DAT_40baacc2 = 0;
  DAT_40baacc4 = 0;
  DAT_40baacc6 = 0;
  DAT_40baacc8 = 0;
  DAT_40baacca = 0;
  DAT_40baaccc = 0;
  DAT_40baacce = 0;
  DAT_40baacd0 = 0x726f;
  DAT_40baacd2 = 0;
  DAT_40baacd3 = 0;
  DAT_40baacd4 = 0x69726f;
  DAT_40baacd8 = 0x69726f;
  DAT_40baacdc._0_1_ = 'O';
  DAT_40baacdc._1_1_ = 'r';
  DAT_40baacdc._2_1_ = 'o';
  DAT_40baacdc._3_1_ = 'm';
  DAT_40baace0._0_1_ = 'o';
  DAT_40baace0._1_1_ = '\0';
  DAT_40baace2 = 0;
  DAT_40baace4 = 0;
  DAT_40baace6 = 0;
  DAT_40baace8 = 0;
  DAT_40baacea = 0;
  DAT_40baacec = 0;
  DAT_40baacee = 0;
  DAT_40baacf0 = 0;
  DAT_40baacf2 = 0;
  DAT_40baacf4 = 0;
  DAT_40baacf6 = 0;
  DAT_40baacf8 = 0;
  DAT_40baacfa = 0;
  DAT_40baacfc = 0x6d6f;
  DAT_40baacfe = 0;
  DAT_40baacff = 0;
  DAT_40baad00 = 0x6d726f;
  DAT_40baad04 = 0x6d726f;
  DAT_40baad08._0_1_ = 'O';
  DAT_40baad08._1_1_ = 'n';
  DAT_40baad08._2_1_ = ' ';
  DAT_40baad08._3_1_ = 'S';
  DAT_40baad0c._0_1_ = 'c';
  DAT_40baad0c._1_1_ = 'r';
  DAT_40baad0c._2_1_ = 'e';
  DAT_40baad0c._3_1_ = 'e';
  DAT_40baad10._0_1_ = 'n';
  DAT_40baad10._1_1_ = ' ';
  DAT_40baad10._2_1_ = 'D';
  DAT_40baad10._3_1_ = 'i';
  DAT_40baad14._0_1_ = 's';
  DAT_40baad14._1_1_ = 'p';
  DAT_40baad14._2_1_ = 'l';
  DAT_40baad14._3_1_ = 'a';
  DAT_40baad18._0_1_ = 'y';
  DAT_40baad18._1_1_ = '\0';
  DAT_40baad1a = 0;
  DAT_40baad1c = 0;
  DAT_40baad1e = 0;
  DAT_40baad20 = 0;
  DAT_40baad22 = 0;
  DAT_40baad24 = 0;
  DAT_40baad26 = 0;
  DAT_40baad28 = 0x646f;
  DAT_40baad2a = 0;
  DAT_40baad2b = 0;
  DAT_40baad2c = 0x64736f;
  DAT_40baad30 = 0x64736f;
  DAT_40baad34._0_1_ = 'O';
  DAT_40baad34._1_1_ = 's';
  DAT_40baad34._2_1_ = 's';
  DAT_40baad34._3_1_ = 'e';
  DAT_40baad38._0_1_ = 't';
  DAT_40baad38._1_1_ = 'i';
  DAT_40baad38._2_1_ = 'a';
  DAT_40baad38._3_1_ = 'n';
  DAT_40baad3c._0_1_ = ';';
  DAT_40baad3c._1_1_ = ' ';
  DAT_40baad3c._2_1_ = 'O';
  DAT_40baad3c._3_1_ = 's';
  DAT_40baad40._0_1_ = 's';
  DAT_40baad40._1_1_ = 'e';
  DAT_40baad40._2_1_ = 't';
  DAT_40baad40._3_1_ = 'i';
  DAT_40baad44._0_1_ = 'c';
  DAT_40baad44._1_1_ = '\0';
  DAT_40baad46 = 0;
  DAT_40baad48 = 0;
  DAT_40baad4a = 0;
  DAT_40baad4c = 0;
  DAT_40baad4e = 0;
  DAT_40baad50 = 0;
  DAT_40baad52 = 0;
  DAT_40baad54 = 0x736f;
  DAT_40baad56 = 0;
  DAT_40baad57 = 0;
  DAT_40baad58 = 0x73736f;
  DAT_40baad5c = 0x73736f;
  DAT_40baad60 = 0x6a6e6150;
  DAT_40baad64 = 0x696261;
  DAT_40baad68 = 0;
  DAT_40baad6c = 0;
  DAT_40baad70 = 0;
  DAT_40baad74 = 0;
  DAT_40baad78 = 0;
  DAT_40baad7c = 0;
  DAT_40baad80 = 0x6170;
  DAT_40baad82 = 0;
  DAT_40baad83 = 0;
  DAT_40baad84 = 0x6e6170;
  DAT_40baad88 = 0x6e6170;
  DAT_40baad8c._0_1_ = 'P';
  DAT_40baad8c._1_1_ = 'e';
  DAT_40baad8c._2_1_ = 'r';
  DAT_40baad8c._3_1_ = 's';
  DAT_40baad90._0_1_ = 'i';
  DAT_40baad90._1_1_ = 'a';
  DAT_40baad90._2_1_ = 'n';
  DAT_40baad90._3_1_ = '\0';
  DAT_40baad94 = 0;
  DAT_40baad98 = 0;
  DAT_40baad9c = 0;
  DAT_40baada0 = 0;
  DAT_40baada4 = 0;
  DAT_40baada8 = 0;
  DAT_40baadac = 0x6166;
  DAT_40baadae = 0;
  DAT_40baadaf = 0;
  DAT_40baadb0 = 0x736166;
  DAT_40baadb4 = 0x726570;
  DAT_40baadb8 = 0x696c6150;
  DAT_40baadbc = 0;
  memset(&DAT_40baadbd,0,0x1b);
  DAT_40baadd8 = 0x6970;
  DAT_40baadda = 0;
  DAT_40baaddb = 0;
  DAT_40baaddc = 0x696c70;
  DAT_40baade0 = 0x696c70;
  DAT_40baade4._0_1_ = 'P';
  DAT_40baade4._1_1_ = 'o';
  DAT_40baade4._2_1_ = 'l';
  DAT_40baade4._3_1_ = 'i';
  DAT_40baade8._0_1_ = 's';
  DAT_40baade8._1_1_ = 'h';
  DAT_40baadea = '\0';
  memset(&DAT_40baadeb,0,0x19);
  DAT_40baae04 = 0x6c70;
  DAT_40baae06 = 0;
  DAT_40baae07 = 0;
  DAT_40baae08 = 0x6c6f70;
  DAT_40baae0c = 0x6c6f70;
  DAT_40baae10._0_1_ = 'P';
  DAT_40baae10._1_1_ = 'o';
  DAT_40baae10._2_1_ = 'r';
  DAT_40baae10._3_1_ = 't';
  DAT_40baae14._0_1_ = 'u';
  DAT_40baae14._1_1_ = 'g';
  DAT_40baae14._2_1_ = 'u';
  DAT_40baae14._3_1_ = 'e';
  DAT_40baae18._0_1_ = 's';
  DAT_40baae18._1_1_ = 'e';
  DAT_40baae1a = '\0';
  memset(&DAT_40baae1b,0,0x15);
  DAT_40baae30 = 0x7470;
  DAT_40baae32 = 0;
  DAT_40baae33 = 0;
  DAT_40baae34 = 0x726f70;
  DAT_40baae38 = 0x726f70;
  DAT_40baae3c = 0x68737550;
  DAT_40baae40 = 0x6f74;
  DAT_40baae42 = 0;
  memset(&DAT_40baae43,0,0x19);
  DAT_40baae5c = 0x7370;
  DAT_40baae5e = 0;
  DAT_40baae5f = 0;
  DAT_40baae60 = 0x737570;
  DAT_40baae64 = 0x737570;
  DAT_40baae68 = 0x63657551;
  DAT_40baae6c = 0x617568;
  DAT_40baae70 = 0;
  DAT_40baae74 = 0;
  DAT_40baae78 = 0;
  DAT_40baae7c = 0;
  DAT_40baae80 = 0;
  DAT_40baae84 = 0;
  DAT_40baae88 = 0x7571;
  DAT_40baae8a = 0;
  DAT_40baae8b = 0;
  DAT_40baae8c = 0x657571;
  DAT_40baae90 = 0x657571;
  DAT_40baae94._0_1_ = 'O';
  DAT_40baae94._1_1_ = 'r';
  DAT_40baae94._2_1_ = 'i';
  DAT_40baae94._3_1_ = 'g';
  DAT_40baae98._0_1_ = 'i';
  DAT_40baae98._1_1_ = 'n';
  DAT_40baae98._2_1_ = 'a';
  DAT_40baae98._3_1_ = 'l';
  DAT_40baae9c._0_1_ = ' ';
  DAT_40baae9c._1_1_ = 'a';
  DAT_40baae9c._2_1_ = 'u';
  DAT_40baae9c._3_1_ = 'd';
  DAT_40baaea0._0_1_ = 'i';
  DAT_40baaea0._1_1_ = 'o';
  DAT_40baaea2 = '\0';
  memset(&DAT_40baaea3,0,0x11);
  DAT_40baaeb4 = 0;
  DAT_40baaeb5 = 0;
  DAT_40baaeb6 = 0;
  DAT_40baaeb7 = 0;
  DAT_40baaeb8 = 0x616171;
  DAT_40baaebc = 0x616171;
  DAT_40baaec0._0_1_ = 'R';
  DAT_40baaec0._1_1_ = 'a';
  DAT_40baaec0._2_1_ = 'e';
  DAT_40baaec0._3_1_ = 't';
  DAT_40baaec4._0_1_ = 'o';
  DAT_40baaec4._1_1_ = '-';
  DAT_40baaec4._2_1_ = 'R';
  DAT_40baaec4._3_1_ = 'o';
  DAT_40baaec8._0_1_ = 'm';
  DAT_40baaec8._1_1_ = 'a';
  DAT_40baaec8._2_1_ = 'n';
  DAT_40baaec8._3_1_ = 'c';
  DAT_40baaecc._0_1_ = 'e';
  DAT_40baaecc._1_1_ = '\0';
  DAT_40baaece = 0;
  DAT_40baaed0 = 0;
  DAT_40baaed2 = 0;
  DAT_40baaed4 = 0;
  DAT_40baaed6 = 0;
  DAT_40baaed8 = 0;
  DAT_40baaeda = 0;
  DAT_40baaedc = 0;
  DAT_40baaede = 0;
  DAT_40baaee0 = 0x6d72;
  DAT_40baaee2 = 0;
  DAT_40baaee3 = 0;
  DAT_40baaee4 = 0x686f72;
  DAT_40baaee8 = 0x686f72;
  DAT_40baaeec._0_1_ = 'R';
  DAT_40baaeec._1_1_ = 'o';
  DAT_40baaeec._2_1_ = 'm';
  DAT_40baaeec._3_1_ = 'a';
  DAT_40baaef0._0_1_ = 'n';
  DAT_40baaef0._1_1_ = 'i';
  DAT_40baaef0._2_1_ = 'a';
  DAT_40baaef0._3_1_ = 'n';
  DAT_40baaef4 = '\0';
  memset(&DAT_40baaef5,0,0x17);
  DAT_40baaf0c = 0x6f72;
  DAT_40baaf0e = 0;
  DAT_40baaf0f = 0;
  DAT_40baaf10 = 0x6e6f72;
  DAT_40baaf14 = 0x6d7572;
  DAT_40baaf18._0_1_ = 'R';
  DAT_40baaf18._1_1_ = 'u';
  DAT_40baaf18._2_1_ = 'n';
  DAT_40baaf18._3_1_ = 'd';
  DAT_40baaf1c._0_1_ = 'i';
  DAT_40baaf1c._1_1_ = '\0';
  DAT_40baaf1e = 0;
  DAT_40baaf20 = 0;
  DAT_40baaf22 = 0;
  DAT_40baaf24 = 0;
  DAT_40baaf26 = 0;
  DAT_40baaf28 = 0;
  DAT_40baaf2a = 0;
  DAT_40baaf2c = 0;
  DAT_40baaf2e = 0;
  DAT_40baaf30 = 0;
  DAT_40baaf32 = 0;
  DAT_40baaf34 = 0;
  DAT_40baaf36 = 0;
  DAT_40baaf38 = 0x6e72;
  DAT_40baaf3a = 0;
  DAT_40baaf3b = 0;
  DAT_40baaf3c = 0x6e7572;
  DAT_40baaf40 = 0x6e7572;
  DAT_40baaf44._0_1_ = 'R';
  DAT_40baaf44._1_1_ = 'u';
  DAT_40baaf44._2_1_ = 's';
  DAT_40baaf44._3_1_ = 's';
  DAT_40baaf48._0_1_ = 'i';
  DAT_40baaf48._1_1_ = 'a';
  DAT_40baaf48._2_1_ = 'n';
  DAT_40baaf48._3_1_ = '\0';
  DAT_40baaf4c = 0;
  DAT_40baaf50 = 0;
  DAT_40baaf54 = 0;
  DAT_40baaf58 = 0;
  DAT_40baaf5c = 0;
  DAT_40baaf60 = 0;
  DAT_40baaf64 = 0x7572;
  DAT_40baaf66 = 0;
  DAT_40baaf67 = 0;
  DAT_40baaf68 = 0x737572;
  DAT_40baaf6c = 0x737572;
  DAT_40baaf70._0_1_ = 'S';
  DAT_40baaf70._1_1_ = 'a';
  DAT_40baaf70._2_1_ = 'n';
  DAT_40baaf70._3_1_ = 'g';
  DAT_40baaf74._0_1_ = 'o';
  DAT_40baaf74._1_1_ = '\0';
  DAT_40baaf76 = 0;
  DAT_40baaf78 = 0;
  DAT_40baaf7a = 0;
  DAT_40baaf7c = 0;
  DAT_40baaf7e = 0;
  DAT_40baaf80 = 0;
  DAT_40baaf82 = 0;
  DAT_40baaf84 = 0;
  DAT_40baaf86 = 0;
  DAT_40baaf88 = 0;
  DAT_40baaf8a = 0;
  DAT_40baaf8c = 0;
  DAT_40baaf8e = 0;
  DAT_40baaf90 = 0x6773;
  DAT_40baaf92 = 0;
  DAT_40baaf93 = 0;
  DAT_40baaf94 = 0x676173;
  DAT_40baaf98 = 0x676173;
  DAT_40baaf9c._0_1_ = 'S';
  DAT_40baaf9c._1_1_ = 'a';
  DAT_40baaf9c._2_1_ = 'n';
  DAT_40baaf9c._3_1_ = 's';
  DAT_40baafa0._0_1_ = 'k';
  DAT_40baafa0._1_1_ = 'r';
  DAT_40baafa0._2_1_ = 'i';
  DAT_40baafa0._3_1_ = 't';
  DAT_40baafa4 = '\0';
  memset(&DAT_40baafa5,0,0x17);
  DAT_40baafbc = 0x6173;
  DAT_40baafbe = 0;
  DAT_40baafbf = 0;
  DAT_40baafc0 = 0x6e6173;
  DAT_40baafc4 = 0x6e6173;
  DAT_40baafc8._0_1_ = 'S';
  DAT_40baafc8._1_1_ = 'e';
  DAT_40baafc8._2_1_ = 'r';
  DAT_40baafc8._3_1_ = 'b';
  DAT_40baafcc._0_1_ = 'i';
  DAT_40baafcc._1_1_ = 'a';
  DAT_40baafcc._2_1_ = 'n';
  DAT_40baafcc._3_1_ = '\0';
  DAT_40baafd0 = 0;
  DAT_40baafd4 = 0;
  DAT_40baafd8 = 0;
  DAT_40baafdc = 0;
  DAT_40baafe0 = 0;
  DAT_40baafe4 = 0;
  DAT_40baafe8 = 0x7273;
  DAT_40baafea = 0;
  DAT_40baafeb = 0;
  DAT_40baafec = 0x707273;
  DAT_40baaff0 = 0x636373;
  DAT_40baaff4._0_1_ = 'C';
  DAT_40baaff4._1_1_ = 'r';
  DAT_40baaff4._2_1_ = 'o';
  DAT_40baaff4._3_1_ = 'a';
  DAT_40baaff8._0_1_ = 't';
  DAT_40baaff8._1_1_ = 'i';
  DAT_40baaff8._2_1_ = 'a';
  DAT_40baaff8._3_1_ = 'n';
  DAT_40baaffc = '\0';
  memset(&DAT_40baaffd,0,0x17);
  DAT_40bab014 = 0x7268;
  DAT_40bab016 = 0;
  DAT_40bab017 = 0;
  DAT_40bab018 = 0x767268;
  DAT_40bab01c = 0x726373;
  DAT_40bab020._0_1_ = 'S';
  DAT_40bab020._1_1_ = 'i';
  DAT_40bab020._2_1_ = 'n';
  DAT_40bab020._3_1_ = 'h';
  DAT_40bab024._0_1_ = 'a';
  DAT_40bab024._1_1_ = 'l';
  DAT_40bab024._2_1_ = 'e';
  DAT_40bab024._3_1_ = 's';
  DAT_40bab028._0_1_ = 'e';
  DAT_40bab028._1_1_ = '\0';
  DAT_40bab02a = 0;
  DAT_40bab02c = 0;
  DAT_40bab02e = 0;
  DAT_40bab030 = 0;
  DAT_40bab032 = 0;
  DAT_40bab034 = 0;
  DAT_40bab036 = 0;
  DAT_40bab038 = 0;
  DAT_40bab03a = 0;
  DAT_40bab03c = 0;
  DAT_40bab03e = 0;
  DAT_40bab040 = 0x6973;
  DAT_40bab042 = 0;
  DAT_40bab043 = 0;
  DAT_40bab044 = 0x6e6973;
  DAT_40bab048 = 0x6e6973;
  DAT_40bab04c = 0x766f6c53;
  DAT_40bab050 = 0x6b61;
  DAT_40bab052 = 0;
  memset(&DAT_40bab053,0,0x19);
  DAT_40bab06c = 0x6b73;
  DAT_40bab06e = 0;
  DAT_40bab06f = 0;
  DAT_40bab070 = 0x6b6c73;
  DAT_40bab074 = 0x6f6c73;
  DAT_40bab078._0_1_ = 'S';
  DAT_40bab078._1_1_ = 'l';
  DAT_40bab078._2_1_ = 'o';
  DAT_40bab078._3_1_ = 'v';
  DAT_40bab07c._0_1_ = 'e';
  DAT_40bab07c._1_1_ = 'n';
  DAT_40bab07c._2_1_ = 'i';
  DAT_40bab07c._3_1_ = 'a';
  DAT_40bab080._0_1_ = 'n';
  DAT_40bab080._1_1_ = '\0';
  DAT_40bab082 = 0;
  DAT_40bab084 = 0;
  DAT_40bab086 = 0;
  DAT_40bab088 = 0;
  DAT_40bab08a = 0;
  DAT_40bab08c = 0;
  DAT_40bab08e = 0;
  DAT_40bab090 = 0;
  DAT_40bab092 = 0;
  DAT_40bab094 = 0;
  DAT_40bab096 = 0;
  DAT_40bab098 = 0x6c73;
  DAT_40bab09a = 0;
  DAT_40bab09b = 0;
  DAT_40bab09c = 0x766c73;
  DAT_40bab0a0 = 0x766c73;
  DAT_40bab0a4._0_1_ = 'N';
  DAT_40bab0a4._1_1_ = 'o';
  DAT_40bab0a4._2_1_ = 'r';
  DAT_40bab0a4._3_1_ = 't';
  DAT_40bab0a8._0_1_ = 'h';
  DAT_40bab0a8._1_1_ = 'e';
  DAT_40bab0a8._2_1_ = 'r';
  DAT_40bab0a8._3_1_ = 'n';
  DAT_40bab0ac._0_1_ = ' ';
  DAT_40bab0ac._1_1_ = 'S';
  DAT_40bab0ac._2_1_ = 'a';
  DAT_40bab0ac._3_1_ = 'm';
  DAT_40bab0b0._0_1_ = 'i';
  DAT_40bab0b0._1_1_ = '\0';
  DAT_40bab0b2 = 0;
  DAT_40bab0b4 = 0;
  DAT_40bab0b6 = 0;
  DAT_40bab0b8 = 0;
  DAT_40bab0ba = 0;
  DAT_40bab0bc = 0;
  DAT_40bab0be = 0;
  DAT_40bab0c0 = 0;
  DAT_40bab0c2 = 0;
  DAT_40bab0c4 = 0x6573;
  DAT_40bab0c6 = 0;
  DAT_40bab0c7 = 0;
  DAT_40bab0c8 = 0x656d73;
  DAT_40bab0cc = 0x656d73;
  DAT_40bab0d0._0_1_ = 'S';
  DAT_40bab0d0._1_1_ = 'a';
  DAT_40bab0d0._2_1_ = 'm';
  DAT_40bab0d0._3_1_ = 'o';
  DAT_40bab0d4._0_1_ = 'a';
  DAT_40bab0d4._1_1_ = 'n';
  DAT_40bab0d6 = '\0';
  memset(&DAT_40bab0d7,0,0x19);
  DAT_40bab0f0 = 0x6d73;
  DAT_40bab0f2 = 0;
  DAT_40bab0f3 = 0;
  DAT_40bab0f4 = 0x6f6d73;
  DAT_40bab0f8 = 0x6f6d73;
  DAT_40bab0fc._0_1_ = 'S';
  DAT_40bab0fc._1_1_ = 'h';
  DAT_40bab0fc._2_1_ = 'o';
  DAT_40bab0fc._3_1_ = 'n';
  DAT_40bab100._0_1_ = 'a';
  DAT_40bab100._1_1_ = '\0';
  DAT_40bab102 = 0;
  DAT_40bab104 = 0;
  DAT_40bab106 = 0;
  DAT_40bab108 = 0;
  DAT_40bab10a = 0;
  DAT_40bab10c = 0;
  DAT_40bab10e = 0;
  DAT_40bab110 = 0;
  DAT_40bab112 = 0;
  DAT_40bab114 = 0;
  DAT_40bab116 = 0;
  DAT_40bab118 = 0;
  DAT_40bab11a = 0;
  DAT_40bab11c = 0x6e73;
  DAT_40bab11e = 0;
  DAT_40bab11f = 0;
  DAT_40bab120 = 0x616e73;
  DAT_40bab124 = 0x616e73;
  DAT_40bab128._0_1_ = 'S';
  DAT_40bab128._1_1_ = 'i';
  DAT_40bab128._2_1_ = 'n';
  DAT_40bab128._3_1_ = 'd';
  DAT_40bab12c._0_1_ = 'h';
  DAT_40bab12c._1_1_ = 'i';
  DAT_40bab12e = '\0';
  memset(&DAT_40bab12f,0,0x19);
  DAT_40bab148 = 0x6473;
  DAT_40bab14a = 0;
  DAT_40bab14b = 0;
  DAT_40bab14c = 0x646e73;
  DAT_40bab150 = 0x646e73;
  DAT_40bab154._0_1_ = 'S';
  DAT_40bab154._1_1_ = 'o';
  DAT_40bab154._2_1_ = 'm';
  DAT_40bab154._3_1_ = 'a';
  DAT_40bab158._0_1_ = 'l';
  DAT_40bab158._1_1_ = 'i';
  DAT_40bab15a = '\0';
  memset(&DAT_40bab15b,0,0x19);
  DAT_40bab174 = 0x6f73;
  DAT_40bab176 = 0;
  DAT_40bab177 = 0;
  DAT_40bab178 = 0x6d6f73;
  DAT_40bab17c = 0x6d6f73;
  DAT_40bab180._0_1_ = 'S';
  DAT_40bab180._1_1_ = 'o';
  DAT_40bab180._2_1_ = 't';
  DAT_40bab180._3_1_ = 'h';
  DAT_40bab184._0_1_ = 'o';
  DAT_40bab184._1_1_ = ',';
  DAT_40bab184._2_1_ = ' ';
  DAT_40bab184._3_1_ = 'S';
  DAT_40bab188._0_1_ = 'o';
  DAT_40bab188._1_1_ = 'u';
  DAT_40bab188._2_1_ = 't';
  DAT_40bab188._3_1_ = 'h';
  DAT_40bab18c._0_1_ = 'e';
  DAT_40bab18c._1_1_ = 'r';
  DAT_40bab18c._2_1_ = 'n';
  DAT_40bab18c._3_1_ = '\0';
  DAT_40bab190 = 0;
  DAT_40bab194 = 0;
  DAT_40bab198 = 0;
  DAT_40bab19c = 0;
  DAT_40bab1a0 = 0x7473;
  DAT_40bab1a2 = 0;
  DAT_40bab1a3 = 0;
  DAT_40bab1a4 = 0x746f73;
  DAT_40bab1a8 = 0x746f73;
  DAT_40bab1ac._0_1_ = 'S';
  DAT_40bab1ac._1_1_ = 'p';
  DAT_40bab1ac._2_1_ = 'a';
  DAT_40bab1ac._3_1_ = 'n';
  DAT_40bab1b0._0_1_ = 'i';
  DAT_40bab1b0._1_1_ = 's';
  DAT_40bab1b0._2_1_ = 'h';
  DAT_40bab1b0._3_1_ = '\0';
  DAT_40bab1b4 = 0;
  DAT_40bab1b8 = 0;
  DAT_40bab1bc = 0;
  DAT_40bab1c0 = 0;
  DAT_40bab1c4 = 0;
  DAT_40bab1c8 = 0;
  DAT_40bab1cc = 0x7365;
  DAT_40bab1ce = 0;
  DAT_40bab1cf = 0;
  DAT_40bab1d0 = 0x617073;
  DAT_40bab1d4 = 0x617073;
  DAT_40bab1d8._0_1_ = 'S';
  DAT_40bab1d8._1_1_ = 'a';
  DAT_40bab1d8._2_1_ = 'r';
  DAT_40bab1d8._3_1_ = 'd';
  DAT_40bab1dc._0_1_ = 'i';
  DAT_40bab1dc._1_1_ = 'n';
  DAT_40bab1dc._2_1_ = 'i';
  DAT_40bab1dc._3_1_ = 'a';
  DAT_40bab1e0._0_1_ = 'n';
  DAT_40bab1e0._1_1_ = '\0';
  DAT_40bab1e2 = 0;
  DAT_40bab1e4 = 0;
  DAT_40bab1e6 = 0;
  DAT_40bab1e8 = 0;
  DAT_40bab1ea = 0;
  DAT_40bab1ec = 0;
  DAT_40bab1ee = 0;
  DAT_40bab1f0 = 0;
  DAT_40bab1f2 = 0;
  DAT_40bab1f4 = 0;
  DAT_40bab1f6 = 0;
  DAT_40bab1f8 = 0x6373;
  DAT_40bab1fa = 0;
  DAT_40bab1fb = 0;
  DAT_40bab1fc = 0x647273;
  DAT_40bab200 = 0x647273;
  DAT_40bab204._0_1_ = 'S';
  DAT_40bab204._1_1_ = 'w';
  DAT_40bab204._2_1_ = 'a';
  DAT_40bab204._3_1_ = 't';
  DAT_40bab208._0_1_ = 'i';
  DAT_40bab208._1_1_ = '\0';
  DAT_40bab20a = 0;
  DAT_40bab20c = 0;
  DAT_40bab20e = 0;
  DAT_40bab210 = 0;
  DAT_40bab212 = 0;
  DAT_40bab214 = 0;
  DAT_40bab216 = 0;
  DAT_40bab218 = 0;
  DAT_40bab21a = 0;
  DAT_40bab21c = 0;
  DAT_40bab21e = 0;
  DAT_40bab220 = 0;
  DAT_40bab222 = 0;
  DAT_40bab224 = 0x7373;
  DAT_40bab226 = 0;
  DAT_40bab227 = 0;
  DAT_40bab228 = 0x777373;
  DAT_40bab22c = 0x777373;
  DAT_40bab230._0_1_ = 'S';
  DAT_40bab230._1_1_ = 'u';
  DAT_40bab230._2_1_ = 'n';
  DAT_40bab230._3_1_ = 'd';
  DAT_40bab234._0_1_ = 'a';
  DAT_40bab234._1_1_ = 'n';
  DAT_40bab234._2_1_ = 'e';
  DAT_40bab234._3_1_ = 's';
  DAT_40bab238._0_1_ = 'e';
  DAT_40bab238._1_1_ = '\0';
  DAT_40bab23a = 0;
  DAT_40bab23c = 0;
  DAT_40bab23e = 0;
  DAT_40bab240 = 0;
  DAT_40bab242 = 0;
  DAT_40bab244 = 0;
  DAT_40bab246 = 0;
  DAT_40bab248 = 0;
  DAT_40bab24a = 0;
  DAT_40bab24c = 0;
  DAT_40bab24e = 0;
  DAT_40bab250 = 0x7573;
  DAT_40bab252 = 0;
  DAT_40bab253 = 0;
  DAT_40bab254 = 0x6e7573;
  DAT_40bab258 = 0x6e7573;
  DAT_40bab25c._0_1_ = 'S';
  DAT_40bab25c._1_1_ = 'w';
  DAT_40bab25c._2_1_ = 'a';
  DAT_40bab25c._3_1_ = 'h';
  DAT_40bab260._0_1_ = 'i';
  DAT_40bab260._1_1_ = 'l';
  DAT_40bab260._2_1_ = 'i';
  DAT_40bab260._3_1_ = '\0';
  DAT_40bab264 = 0;
  DAT_40bab268 = 0;
  DAT_40bab26c = 0;
  DAT_40bab270 = 0;
  DAT_40bab274 = 0;
  DAT_40bab278 = 0;
  DAT_40bab27c = 0x7773;
  DAT_40bab27e = 0;
  DAT_40bab27f = 0;
  DAT_40bab280 = 0x617773;
  DAT_40bab284 = 0x617773;
  DAT_40bab288._0_1_ = 'S';
  DAT_40bab288._1_1_ = 'w';
  DAT_40bab288._2_1_ = 'e';
  DAT_40bab288._3_1_ = 'd';
  DAT_40bab28c._0_1_ = 'i';
  DAT_40bab28c._1_1_ = 's';
  DAT_40bab28c._2_1_ = 'h';
  DAT_40bab28c._3_1_ = '\0';
  DAT_40bab290 = 0;
  DAT_40bab294 = 0;
  DAT_40bab298 = 0;
  DAT_40bab29c = 0;
  DAT_40bab2a0 = 0;
  DAT_40bab2a4 = 0;
  DAT_40bab2a8 = 0x7673;
  DAT_40bab2aa = 0;
  DAT_40bab2ab = 0;
  DAT_40bab2ac = 0x657773;
  DAT_40bab2b0 = 0x657773;
  DAT_40bab2b4._0_1_ = 'T';
  DAT_40bab2b4._1_1_ = 'a';
  DAT_40bab2b4._2_1_ = 'h';
  DAT_40bab2b4._3_1_ = 'i';
  DAT_40bab2b8._0_1_ = 't';
  DAT_40bab2b8._1_1_ = 'i';
  DAT_40bab2b8._2_1_ = 'a';
  DAT_40bab2b8._3_1_ = 'n';
  DAT_40bab2bc = '\0';
  memset(&DAT_40bab2bd,0,0x17);
  DAT_40bab2d4 = 0x7974;
  DAT_40bab2d6 = 0;
  DAT_40bab2d7 = 0;
  DAT_40bab2d8 = 0x686174;
  DAT_40bab2dc = 0x686174;
  DAT_40bab2e0._0_1_ = 'T';
  DAT_40bab2e0._1_1_ = 'a';
  DAT_40bab2e0._2_1_ = 'm';
  DAT_40bab2e0._3_1_ = 'i';
  DAT_40bab2e4._0_1_ = 'l';
  DAT_40bab2e4._1_1_ = '\0';
  DAT_40bab2e6 = 0;
  DAT_40bab2e8 = 0;
  DAT_40bab2ea = 0;
  DAT_40bab2ec = 0;
  DAT_40bab2ee = 0;
  DAT_40bab2f0 = 0;
  DAT_40bab2f2 = 0;
  DAT_40bab2f4 = 0;
  DAT_40bab2f6 = 0;
  DAT_40bab2f8 = 0;
  DAT_40bab2fa = 0;
  DAT_40bab2fc = 0;
  DAT_40bab2fe = 0;
  DAT_40bab300 = 0x6174;
  DAT_40bab302 = 0;
  DAT_40bab303 = 0;
  DAT_40bab304 = 0x6d6174;
  DAT_40bab308 = 0x6d6174;
  DAT_40bab30c._0_1_ = 'T';
  DAT_40bab30c._1_1_ = 'a';
  DAT_40bab30c._2_1_ = 't';
  DAT_40bab30c._3_1_ = 'a';
  DAT_40bab310._0_1_ = 'r';
  DAT_40bab310._1_1_ = '\0';
  DAT_40bab312 = 0;
  DAT_40bab314 = 0;
  DAT_40bab316 = 0;
  DAT_40bab318 = 0;
  DAT_40bab31a = 0;
  DAT_40bab31c = 0;
  DAT_40bab31e = 0;
  DAT_40bab320 = 0;
  DAT_40bab322 = 0;
  DAT_40bab324 = 0;
  DAT_40bab326 = 0;
  DAT_40bab328 = 0;
  DAT_40bab32a = 0;
  DAT_40bab32c = 0x7474;
  DAT_40bab32e = 0;
  DAT_40bab32f = 0;
  DAT_40bab330 = 0x746174;
  DAT_40bab334 = 0x746174;
  DAT_40bab338 = 0x756c6554;
  DAT_40bab33c = 0x7567;
  DAT_40bab33e = 0;
  memset(&DAT_40bab33f,0,0x19);
  DAT_40bab358 = 0x6574;
  DAT_40bab35a = 0;
  DAT_40bab35b = 0;
  DAT_40bab35c = 0x6c6574;
  DAT_40bab360 = 0x6c6574;
  DAT_40bab364 = 0x696a6154;
  DAT_40bab368 = 0x6b;
  DAT_40bab36a = 0;
  DAT_40bab36c = 0;
  DAT_40bab36e = 0;
  DAT_40bab370 = 0;
  DAT_40bab372 = 0;
  DAT_40bab374 = 0;
  DAT_40bab376 = 0;
  DAT_40bab378 = 0;
  DAT_40bab37a = 0;
  DAT_40bab37c = 0;
  DAT_40bab37e = 0;
  DAT_40bab380 = 0;
  DAT_40bab382 = 0;
  DAT_40bab384 = 0x6774;
  DAT_40bab386 = 0;
  DAT_40bab387 = 0;
  DAT_40bab388 = 0x6b6774;
  DAT_40bab38c = 0x6b6774;
  DAT_40bab390._0_1_ = 'T';
  DAT_40bab390._1_1_ = 'a';
  DAT_40bab390._2_1_ = 'g';
  DAT_40bab390._3_1_ = 'a';
  DAT_40bab394._0_1_ = 'l';
  DAT_40bab394._1_1_ = 'o';
  DAT_40bab394._2_1_ = 'g';
  DAT_40bab394._3_1_ = '\0';
  DAT_40bab398 = 0;
  DAT_40bab39c = 0;
  DAT_40bab3a0 = 0;
  DAT_40bab3a4 = 0;
  DAT_40bab3a8 = 0;
  DAT_40bab3ac = 0;
  DAT_40bab3b0 = 0x6c74;
  DAT_40bab3b2 = 0;
  DAT_40bab3b3 = 0;
  DAT_40bab3b4 = 0x6c6774;
  DAT_40bab3b8 = 0x6c6774;
  DAT_40bab3bc = 0x69616854;
  DAT_40bab3c0 = 0;
  memset(&DAT_40bab3c1,0,0x1b);
  DAT_40bab3dc = 0x6874;
  DAT_40bab3de = 0;
  DAT_40bab3df = 0;
  DAT_40bab3e0 = 0x616874;
  DAT_40bab3e4 = 0x616874;
  DAT_40bab3e8._0_1_ = 'T';
  DAT_40bab3e8._1_1_ = 'i';
  DAT_40bab3e8._2_1_ = 'b';
  DAT_40bab3e8._3_1_ = 'e';
  DAT_40bab3ec._0_1_ = 't';
  DAT_40bab3ec._1_1_ = 'a';
  DAT_40bab3ec._2_1_ = 'n';
  DAT_40bab3ec._3_1_ = '\0';
  DAT_40bab3f0 = 0;
  DAT_40bab3f4 = 0;
  DAT_40bab3f8 = 0;
  DAT_40bab3fc = 0;
  DAT_40bab400 = 0;
  DAT_40bab404 = 0;
  DAT_40bab408 = 0x6f62;
  DAT_40bab40a = 0;
  DAT_40bab40b = 0;
  DAT_40bab40c = 0x646f62;
  DAT_40bab410 = 0x626974;
  DAT_40bab414._0_1_ = 'T';
  DAT_40bab414._1_1_ = 'i';
  DAT_40bab414._2_1_ = 'g';
  DAT_40bab414._3_1_ = 'r';
  DAT_40bab418._0_1_ = 'i';
  DAT_40bab418._1_1_ = 'n';
  DAT_40bab418._2_1_ = 'y';
  DAT_40bab418._3_1_ = 'a';
  DAT_40bab41c = '\0';
  memset(&DAT_40bab41d,0,0x17);
  DAT_40bab434 = 0x6974;
  DAT_40bab436 = 0;
  DAT_40bab437 = 0;
  DAT_40bab438 = 0x726974;
  DAT_40bab43c = 0x726974;
  DAT_40bab440._0_1_ = 'T';
  DAT_40bab440._1_1_ = 'o';
  DAT_40bab440._2_1_ = 'n';
  DAT_40bab440._3_1_ = 'g';
  DAT_40bab444._0_1_ = 'a';
  DAT_40bab444._1_1_ = '\0';
  DAT_40bab446 = 0;
  DAT_40bab448 = 0;
  DAT_40bab44a = 0;
  DAT_40bab44c = 0;
  DAT_40bab44e = 0;
  DAT_40bab450 = 0;
  DAT_40bab452 = 0;
  DAT_40bab454 = 0;
  DAT_40bab456 = 0;
  DAT_40bab458 = 0;
  DAT_40bab45a = 0;
  DAT_40bab45c = 0;
  DAT_40bab45e = 0;
  DAT_40bab460 = 0x6f74;
  DAT_40bab462 = 0;
  DAT_40bab463 = 0;
  DAT_40bab464 = 0x6e6f74;
  DAT_40bab468 = 0x6e6f74;
  DAT_40bab46c._0_1_ = 'T';
  DAT_40bab46c._1_1_ = 's';
  DAT_40bab46c._2_1_ = 'w';
  DAT_40bab46c._3_1_ = 'a';
  DAT_40bab470._0_1_ = 'n';
  DAT_40bab470._1_1_ = 'a';
  DAT_40bab472 = '\0';
  memset(&DAT_40bab473,0,0x19);
  DAT_40bab48c = 0x6e74;
  DAT_40bab48e = 0;
  DAT_40bab48f = 0;
  DAT_40bab490 = 0x6e7374;
  DAT_40bab494 = 0x6e7374;
  DAT_40bab498._0_1_ = 'T';
  DAT_40bab498._1_1_ = 's';
  DAT_40bab498._2_1_ = 'o';
  DAT_40bab498._3_1_ = 'n';
  DAT_40bab49c._0_1_ = 'g';
  DAT_40bab49c._1_1_ = 'a';
  DAT_40bab49e = '\0';
  memset(&DAT_40bab49f,0,0x19);
  DAT_40bab4b8 = 0x7374;
  DAT_40bab4ba = 0;
  DAT_40bab4bb = 0;
  DAT_40bab4bc = 0x6f7374;
  DAT_40bab4c0 = 0x6f7374;
  DAT_40bab4c4._0_1_ = 'T';
  DAT_40bab4c4._1_1_ = 'u';
  DAT_40bab4c4._2_1_ = 'r';
  DAT_40bab4c4._3_1_ = 'k';
  DAT_40bab4c8._0_1_ = 'i';
  DAT_40bab4c8._1_1_ = 's';
  DAT_40bab4c8._2_1_ = 'h';
  DAT_40bab4c8._3_1_ = '\0';
  DAT_40bab4cc = 0;
  DAT_40bab4d0 = 0;
  DAT_40bab4d4 = 0;
  DAT_40bab4d8 = 0;
  DAT_40bab4dc = 0;
  DAT_40bab4e0 = 0;
  DAT_40bab4e4 = 0x7274;
  DAT_40bab4e6 = 0;
  DAT_40bab4e7 = 0;
  DAT_40bab4e8 = 0x727574;
  DAT_40bab4ec = 0x727574;
  DAT_40bab4f0._0_1_ = 'T';
  DAT_40bab4f0._1_1_ = 'u';
  DAT_40bab4f0._2_1_ = 'r';
  DAT_40bab4f0._3_1_ = 'k';
  DAT_40bab4f4._0_1_ = 'm';
  DAT_40bab4f4._1_1_ = 'e';
  DAT_40bab4f4._2_1_ = 'n';
  DAT_40bab4f4._3_1_ = '\0';
  DAT_40bab4f8 = 0;
  DAT_40bab4fc = 0;
  DAT_40bab500 = 0;
  DAT_40bab504 = 0;
  DAT_40bab508 = 0;
  DAT_40bab50c = 0;
  DAT_40bab510 = 0x6b74;
  DAT_40bab512 = 0;
  DAT_40bab513 = 0;
  DAT_40bab514 = 0x6b7574;
  DAT_40bab518 = 0x6b7574;
  DAT_40bab51c = 0x697754;
  DAT_40bab520 = 0;
  DAT_40bab524 = 0;
  DAT_40bab528 = 0;
  DAT_40bab52c = 0;
  DAT_40bab530 = 0;
  DAT_40bab534 = 0;
  DAT_40bab538 = 0;
  DAT_40bab53c = 0x7774;
  DAT_40bab53e = 0;
  DAT_40bab53f = 0;
  DAT_40bab540 = 0x697774;
  DAT_40bab544 = 0x697774;
  DAT_40bab548 = 0x68676955;
  DAT_40bab54c = 0x7275;
  DAT_40bab54e = 0;
  memset(&DAT_40bab54f,0,0x19);
  DAT_40bab568 = 0x6775;
  DAT_40bab56a = 0;
  DAT_40bab56b = 0;
  DAT_40bab56c = 0x676975;
  DAT_40bab570 = 0x676975;
  DAT_40bab574._0_1_ = 'U';
  DAT_40bab574._1_1_ = 'k';
  DAT_40bab574._2_1_ = 'r';
  DAT_40bab574._3_1_ = 'a';
  DAT_40bab578._0_1_ = 'i';
  DAT_40bab578._1_1_ = 'n';
  DAT_40bab578._2_1_ = 'i';
  DAT_40bab578._3_1_ = 'a';
  DAT_40bab57c._0_1_ = 'n';
  DAT_40bab57c._1_1_ = '\0';
  DAT_40bab57e = 0;
  DAT_40bab580 = 0;
  DAT_40bab582 = 0;
  DAT_40bab584 = 0;
  DAT_40bab586 = 0;
  DAT_40bab588 = 0;
  DAT_40bab58a = 0;
  DAT_40bab58c = 0;
  DAT_40bab58e = 0;
  DAT_40bab590 = 0;
  DAT_40bab592 = 0;
  DAT_40bab594 = 0x6b75;
  DAT_40bab596 = 0;
  DAT_40bab597 = 0;
  DAT_40bab598 = 0x726b75;
  DAT_40bab59c = 0x726b75;
  DAT_40bab5a0 = 0x75647255;
  DAT_40bab5a4 = 0;
  memset(&DAT_40bab5a5,0,0x1b);
  DAT_40bab5c0 = 0x7275;
  DAT_40bab5c2 = 0;
  DAT_40bab5c3 = 0;
  DAT_40bab5c4 = 0x647275;
  DAT_40bab5c8 = 0x647275;
  DAT_40bab5cc = 0x65627a55;
  DAT_40bab5d0 = 0x6b;
  DAT_40bab5d2 = 0;
  DAT_40bab5d4 = 0;
  DAT_40bab5d6 = 0;
  DAT_40bab5d8 = 0;
  DAT_40bab5da = 0;
  DAT_40bab5dc = 0;
  DAT_40bab5de = 0;
  DAT_40bab5e0 = 0;
  DAT_40bab5e2 = 0;
  DAT_40bab5e4 = 0;
  DAT_40bab5e6 = 0;
  DAT_40bab5e8 = 0;
  DAT_40bab5ea = 0;
  DAT_40bab5ec = 0x7a75;
  DAT_40bab5ee = 0;
  DAT_40bab5ef = 0;
  DAT_40bab5f0 = 0x627a75;
  DAT_40bab5f4 = 0x627a75;
  DAT_40bab5f8._0_1_ = 'V';
  DAT_40bab5f8._1_1_ = 'i';
  DAT_40bab5f8._2_1_ = 'e';
  DAT_40bab5f8._3_1_ = 't';
  DAT_40bab5fc._0_1_ = 'n';
  DAT_40bab5fc._1_1_ = 'a';
  DAT_40bab5fc._2_1_ = 'm';
  DAT_40bab5fc._3_1_ = 'e';
  DAT_40bab600._0_1_ = 's';
  DAT_40bab600._1_1_ = 'e';
  DAT_40bab602 = '\0';
  memset(&DAT_40bab603,0,0x15);
  DAT_40bab618 = 0x6976;
  DAT_40bab61a = 0;
  DAT_40bab61b = 0;
  DAT_40bab61c = 0x656976;
  DAT_40bab620 = 0x656976;
  DAT_40bab624 = 0x616c6f56;
  DAT_40bab628 = 0x6b7570;
  DAT_40bab62c = 0;
  DAT_40bab630 = 0;
  DAT_40bab634 = 0;
  DAT_40bab638 = 0;
  DAT_40bab63c = 0;
  DAT_40bab640 = 0;
  DAT_40bab644 = 0x6f76;
  DAT_40bab646 = 0;
  DAT_40bab647 = 0;
  DAT_40bab648 = 0x6c6f76;
  DAT_40bab64c = 0x6c6f76;
  DAT_40bab650 = 0x736c6557;
  DAT_40bab654 = 0x68;
  DAT_40bab656 = 0;
  DAT_40bab658 = 0;
  DAT_40bab65a = 0;
  DAT_40bab65c = 0;
  DAT_40bab65e = 0;
  DAT_40bab660 = 0;
  DAT_40bab662 = 0;
  DAT_40bab664 = 0;
  DAT_40bab666 = 0;
  DAT_40bab668 = 0;
  DAT_40bab66a = 0;
  DAT_40bab66c = 0;
  DAT_40bab66e = 0;
  DAT_40bab670 = 0x7963;
  DAT_40bab672 = 0;
  DAT_40bab673 = 0;
  DAT_40bab674 = 0x6d7963;
  DAT_40bab678 = 0x6c6577;
  DAT_40bab67c = 0x6f6c6f57;
  DAT_40bab680 = 0x66;
  DAT_40bab682 = 0;
  DAT_40bab684 = 0;
  DAT_40bab686 = 0;
  DAT_40bab688 = 0;
  DAT_40bab68a = 0;
  DAT_40bab68c = 0;
  DAT_40bab68e = 0;
  DAT_40bab690 = 0;
  DAT_40bab692 = 0;
  DAT_40bab694 = 0;
  DAT_40bab696 = 0;
  DAT_40bab698 = 0;
  DAT_40bab69a = 0;
  DAT_40bab69c = 0x6f77;
  DAT_40bab69e = 0;
  DAT_40bab69f = 0;
  DAT_40bab6a0 = 0x6c6f77;
  DAT_40bab6a4 = 0x6c6f77;
  DAT_40bab6a8 = 0x736f6858;
  DAT_40bab6ac = 0x61;
  DAT_40bab6ae = 0;
  DAT_40bab6b0 = 0;
  DAT_40bab6b2 = 0;
  DAT_40bab6b4 = 0;
  DAT_40bab6b6 = 0;
  DAT_40bab6b8 = 0;
  DAT_40bab6ba = 0;
  DAT_40bab6bc = 0;
  DAT_40bab6be = 0;
  DAT_40bab6c0 = 0;
  DAT_40bab6c2 = 0;
  DAT_40bab6c4 = 0;
  DAT_40bab6c6 = 0;
  DAT_40bab6c8 = 0x6878;
  DAT_40bab6ca = 0;
  DAT_40bab6cb = 0;
  DAT_40bab6cc = 0x6f6878;
  DAT_40bab6d0 = 0x6f6878;
  DAT_40bab6d4._0_1_ = 'Y';
  DAT_40bab6d4._1_1_ = 'i';
  DAT_40bab6d4._2_1_ = 'd';
  DAT_40bab6d4._3_1_ = 'd';
  DAT_40bab6d8._0_1_ = 'i';
  DAT_40bab6d8._1_1_ = 's';
  DAT_40bab6d8._2_1_ = 'h';
  DAT_40bab6d8._3_1_ = '\0';
  DAT_40bab6dc = 0;
  DAT_40bab6e0 = 0;
  DAT_40bab6e4 = 0;
  DAT_40bab6e8 = 0;
  DAT_40bab6ec = 0;
  DAT_40bab6f0 = 0;
  DAT_40bab6f4 = 0x6979;
  DAT_40bab6f6 = 0;
  DAT_40bab6f7 = 0;
  DAT_40bab6f8 = 0x646979;
  DAT_40bab6fc = 0x646979;
  DAT_40bab700 = 0x75726f59;
  DAT_40bab704 = 0x6162;
  DAT_40bab706 = 0;
  memset(&DAT_40bab707,0,0x19);
  DAT_40bab720 = 0x6f79;
  DAT_40bab722 = 0;
  DAT_40bab723 = 0;
  DAT_40bab724 = 0x726f79;
  DAT_40bab728 = 0x726f79;
  DAT_40bab72c = 0x6175685a;
  DAT_40bab730 = 0x676e;
  DAT_40bab732 = 0;
  memset(&DAT_40bab733,0,0x19);
  DAT_40bab74c = 0x617a;
  DAT_40bab74e = 0;
  DAT_40bab74f = 0;
  DAT_40bab750 = 0x61687a;
  DAT_40bab754 = 0x61687a;
  DAT_40bab758 = 0x756c755a;
  DAT_40bab75c = 0;
  memset(&DAT_40bab75d,0,0x1b);
  DAT_40bab778 = 0x757a;
  DAT_40bab77a = 0;
  DAT_40bab77b = 0;
  DAT_40bab77c = 0x6c757a;
  DAT_40bab780 = 0x6c757a;
  DAT_40bab784._0_1_ = '2';
  DAT_40bab784._1_1_ = ' ';
  DAT_40bab784._2_1_ = 'c';
  DAT_40bab784._3_1_ = 'h';
  DAT_40bab788._0_1_ = 'a';
  DAT_40bab788._1_1_ = 'n';
  DAT_40bab788._2_1_ = 'n';
  DAT_40bab788._3_1_ = 'e';
  DAT_40bab78c._0_1_ = 'l';
  DAT_40bab78c._1_1_ = '\0';
  DAT_40bab78e = 0;
  DAT_40bab790 = 0;
  DAT_40bab792 = 0;
  DAT_40bab794 = 0;
  DAT_40bab796 = 0;
  DAT_40bab798 = 0;
  DAT_40bab79a = 0;
  DAT_40bab79c = 0;
  DAT_40bab79e = 0;
  DAT_40bab7a0 = 0;
  DAT_40bab7a2 = 0;
  DAT_40bab7a4 = 0;
  DAT_40bab7a5 = 0;
  DAT_40bab7a6 = 0;
  DAT_40bab7a7 = 0;
  DAT_40bab7a8 = 0x686332;
  DAT_40bab7ac = 0x686332;
  DAT_40bab7b0._0_1_ = 'D';
  DAT_40bab7b0._1_1_ = 'o';
  DAT_40bab7b0._2_1_ = 'l';
  DAT_40bab7b0._3_1_ = 'b';
  DAT_40bab7b4._0_1_ = 'y';
  DAT_40bab7b4._1_1_ = 'D';
  DAT_40bab7b4._2_1_ = 'i';
  DAT_40bab7b4._3_1_ = 'g';
  DAT_40bab7b8._0_1_ = 'i';
  DAT_40bab7b8._1_1_ = 't';
  DAT_40bab7b8._2_1_ = 'a';
  DAT_40bab7b8._3_1_ = 'l';
  DAT_40bab7bc._0_1_ = ' ';
  DAT_40bab7bc._1_1_ = 'A';
  DAT_40bab7bc._2_1_ = 'C';
  DAT_40bab7bc._3_1_ = '3';
  DAT_40bab7c0 = '\0';
  DAT_40bab7c1 = 0;
  DAT_40bab7c2 = 0;
  DAT_40bab7c3 = 0;
  DAT_40bab7c4 = 0;
  DAT_40bab7c5 = 0;
  DAT_40bab7c6 = 0;
  DAT_40bab7c7 = 0;
  DAT_40bab7c8 = 0;
  DAT_40bab7c9 = 0;
  DAT_40bab7ca = 0;
  DAT_40bab7cb = 0;
  DAT_40bab7cc = 0;
  DAT_40bab7cd = 0;
  DAT_40bab7ce = 0;
  DAT_40bab7cf = 0;
  DAT_40bab7d0 = 0x6464;
  DAT_40bab7d2 = 0;
  DAT_40bab7d3 = 0;
  DAT_40bab7d4 = 0x6464;
  DAT_40bab7d8 = 0x206464;
  return;
}


