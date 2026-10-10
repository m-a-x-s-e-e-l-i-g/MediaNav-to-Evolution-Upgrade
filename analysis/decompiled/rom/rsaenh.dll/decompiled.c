/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 100091fc FUN_100091fc */

undefined4 FUN_100091fc(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(byte *)((undefined4 *)(param_1 ^ 0xe35a172c) + 1) == param_2) {
    uVar1 = *(undefined4 *)(param_1 ^ 0xe35a172c);
  }
  return uVar1;
}



/* 10009224 FUN_10009224 */

undefined4 FUN_10009224(uint param_1,int param_2,uint param_3,undefined4 *param_4)

{
  int *piVar1;
  
  if ((*(byte *)((undefined4 *)(param_1 ^ 0xe35a172c) + 1) == param_3) &&
     (piVar1 = *(int **)(param_1 ^ 0xe35a172c), piVar1 != (int *)0x0)) {
    if ((param_3 != 2) || (piVar1[4] != 0)) {
      if (*piVar1 != param_2) {
        return 0x80090001;
      }
      *param_4 = piVar1;
      return 0;
    }
  }
  else {
    if (param_3 == 0) {
      return 0x80090001;
    }
    if (param_3 == 1) {
      return 0x80090002;
    }
    if (((int)param_3 < 2) || (4 < (int)param_3)) {
      return 0x80090020;
    }
  }
  return 0x80090003;
}



/* 100092e4 FUN_100092e4 */

/* Boundary evidence: original MIPS .pdata 100092e4..1000935b. Semantic name remains unreviewed. */

undefined4 FUN_100092e4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 8;
  puVar1 = LocalAlloc(0x40,8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_3;
    puVar1[1] = param_2;
    uVar2 = 0;
    *param_1 = (uint)puVar1 ^ 0xe35a172c;
  }
  return uVar2;
}



/* 1000935c FUN_1000935c */

/* Boundary evidence: original MIPS .pdata 1000935c..1000937f. Semantic name remains unreviewed. */

void FUN_1000935c(uint param_1)

{
  LocalFree((HLOCAL)(param_1 ^ 0xe35a172c));
  return;
}



/* 10009380 FUN_10009380 */

/* Boundary evidence: original MIPS .pdata 10009380..10009493. Semantic name remains unreviewed. */

void FUN_10009380(void *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_1 != (void *)0x0) {
    puVar1 = *(undefined1 **)((int)param_1 + 0x6c);
    if (puVar1 != (undefined1 *)0x0) {
      for (iVar2 = *(int *)((int)param_1 + 0x68); iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      }
      LocalFree(*(HLOCAL *)((int)param_1 + 0x6c));
    }
    puVar1 = *(undefined1 **)((int)param_1 + 0x74);
    if (puVar1 != (undefined1 *)0x0) {
      for (iVar2 = *(int *)((int)param_1 + 0x70); iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      }
      LocalFree(*(HLOCAL *)((int)param_1 + 0x74));
    }
    if (*(HLOCAL *)((int)param_1 + 0x84) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)((int)param_1 + 0x84));
    }
    if (*(HLOCAL *)((int)param_1 + 0xbc) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)((int)param_1 + 0xbc));
    }
    puVar1 = *(undefined1 **)((int)param_1 + 0x80);
    if (puVar1 != (undefined1 *)0x0) {
      iVar2 = 5;
      do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + 1;
      } while (iVar2 != 0);
      LocalFree(*(HLOCAL *)((int)param_1 + 0x80));
    }
    if (*(HLOCAL *)((int)param_1 + 100) != (HLOCAL)0x0) {
      FUN_1002afa8(*(HLOCAL *)((int)param_1 + 100));
    }
    FUN_1002b5e8((int)param_1 + 0x1c);
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0xa0));
    memset(param_1,0,0xc0);
    LocalFree(param_1);
  }
  return;
}



/* 10009494 FUN_10009494 */

/* Boundary evidence: original MIPS .pdata 10009494..10009663. Semantic name remains unreviewed. */

undefined4 FUN_10009494(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint *local_1d0;
  undefined4 local_1cc;
  undefined1 *local_1c8;
  undefined4 local_1c4;
  undefined1 auStack_1c0 [192];
  uint local_100 [3];
  undefined4 local_f4;
  undefined *local_f0;
  undefined1 auStack_68 [24];
  undefined1 auStack_50 [52];
  uint local_1c;
  
  local_1c = DAT_1002da44;
  uVar3 = (uint)&local_1c8 ^ 0xe35a172c;
  local_1c8 = auStack_1c0;
  local_1d0 = local_100;
  local_1c4 = 0;
  local_1cc = 2;
  uVar4 = (uint)&local_1d0 ^ 0xe35a172c;
  memset(auStack_50,0xcd,0x32);
  memset(auStack_1c0,0,0xc0);
  memset(local_100,0,0x94);
  local_f4 = 0x19;
  local_100[1] = 0x6602;
  local_f0 = &DAT_1000104c;
  local_100[0] = uVar3;
  iVar1 = FUN_1000edec(0x8004,uVar3,uVar4,auStack_50,0x32,&DAT_10001068,0x14);
  uVar2 = 0;
  if (iVar1 != 0) {
    memset(auStack_68,0xb,0x14);
    local_f0 = auStack_68;
    local_f4 = 0x14;
    iVar1 = FUN_1000edec(0x800c,uVar3,uVar4,&DAT_1000107c,8,&DAT_10001084,0x20);
    uVar2 = 0;
    if (iVar1 != 0) {
      iVar1 = FUN_1000edec(0x800d,uVar3,uVar4,&DAT_1000107c,8,&DAT_100010a4,0x30);
      uVar2 = 0;
      if (iVar1 != 0) {
        iVar1 = FUN_1000edec(0x800e,uVar3,uVar4,&DAT_1000107c,8,&DAT_100010d4,0x40);
        uVar2 = 0;
        if (iVar1 != 0) {
          uVar2 = 1;
        }
      }
    }
  }
  FUN_1002bedc(local_1c);
  return uVar2;
}



/* 10009664 FUN_10009664 */

/* Boundary evidence: original MIPS .pdata 10009664..100096bf. Semantic name remains unreviewed. */

undefined4 FUN_10009664(void)

{
  undefined4 uVar1;
  undefined4 local_118 [2];
  undefined1 auStack_110 [256];
  uint local_10;
  
  local_10 = DAT_1002da44;
  local_118[0] = 0xffffffff;
  uVar1 = FUN_10016a48(local_118,(int *)0x0,(uint *)0x0,auStack_110,0xff);
  FUN_1002bedc(local_10);
  return uVar1;
}



/* 100096c0 FUN_100096c0 */

/* Boundary evidence: original MIPS .pdata 100096c0..1000976b. Semantic name remains unreviewed. */

undefined4 FUN_100096c0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38;
  uint local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined1 auStack_20 [20];
  uint local_c;
  
  local_c = DAT_1002da44;
  local_30 = &local_2c;
  local_2c = 0x53504946;
  local_28 = 0;
  local_34 = 5;
  local_38 = 0xffffffff;
  FUN_10016a48(&local_38,(int *)&local_30,&local_34,auStack_20,0x14);
  iVar1 = memcmp(auStack_20,&DAT_10001114,0x14);
  if (iVar1 == 0) {
    FUN_1002bedc(local_c);
    uVar2 = 0;
  }
  else {
    FUN_1002bedc(local_c);
    uVar2 = 0x80090003;
  }
  return uVar2;
}



/* 1000976c FUN_1000976c */

/* Boundary evidence: original MIPS .pdata 1000976c..10009947. Semantic name remains unreviewed. */

undefined4 FUN_1000976c(void)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  size_t local_1c8 [2];
  uint auStack_1c0 [34];
  char local_138 [136];
  undefined1 auStack_b0 [136];
  uint local_28;
  
  local_28 = DAT_1002da44;
  uVar3 = 0;
  do {
    pcVar2 = local_138 + uVar3;
    uVar3 = uVar3 + 1;
    *pcVar2 = ('\x01' - (char)local_138) + (char)pcVar2;
  } while (uVar3 < 0x88);
  iVar1 = BSafeDecPrivate((int *)&DAT_1002d0d8,local_138,auStack_1c0);
  if ((iVar1 != 0) && (iVar1 = memcmp(auStack_1c0,&DAT_10001130,0x88), iVar1 == 0)) {
    local_1c8[0] = 0x88;
    iVar1 = FUN_1000a848(0,(int *)&DAT_1002d394,&DAT_1002d0d8,1,0x8004,(int)local_138,0x14,0,0,
                         auStack_b0,0x88,auStack_1c0,local_1c8);
    if ((iVar1 == 0) &&
       ((local_1c8[0] == 0x80 && (iVar1 = memcmp(auStack_1c0,&DAT_1002d4b0,0x80), iVar1 == 0)))) {
      local_1c8[0] = 0x88;
      iVar1 = FUN_1000a848(0,(int *)&DAT_1002d394,&DAT_1002d0d8,2,0x8004,(int)local_138,0x14,1,0,
                           auStack_b0,0x88,auStack_1c0,local_1c8);
      if ((iVar1 == 0) &&
         ((local_1c8[0] == 0x80 && (iVar1 = memcmp(auStack_1c0,&DAT_1002d430,0x80), iVar1 == 0)))) {
        FUN_1002bedc(local_28);
        return 0;
      }
    }
  }
  FUN_1002bedc(local_28);
  return 0x80090003;
}



/* 10009948 FUN_10009948 */

/* Boundary evidence: original MIPS .pdata 10009948..10009df7. Semantic name remains unreviewed. */

int FUN_10009948(void)

{
  int iVar1;
  
  iVar1 = FUN_100096c0();
  if (((iVar1 == 0) &&
      (iVar1 = FUN_10018068((int *)&DAT_1002d394,(int *)&DAT_1002d0d8,1), iVar1 == 0)) &&
     (iVar1 = FUN_1000976c(), iVar1 == 0)) {
    iVar1 = FUN_1000d914(0x8003,"HashThis",8,&DAT_1002d530,0x10);
    if ((((iVar1 != 0) && (iVar1 = FUN_1000d914(0x8004,"HashThis",8,&DAT_1002d540,0x14), iVar1 != 0)
         ) && ((iVar1 = FUN_10009494(), iVar1 != 0 &&
               ((iVar1 = FUN_1000d914(0x800c,&DAT_1002d6f4,3,&DAT_1002d6f8,0x20), iVar1 != 0 &&
                (iVar1 = FUN_1000d914(0x800d,&DAT_1002d718,3,&DAT_1002d71c,0x30), iVar1 != 0))))))
       && (iVar1 = FUN_1000d914(0x800e,&DAT_1002d74c,3,&DAT_1002d750,0x40), iVar1 != 0)) {
      iVar1 = FUN_100128b0(0x6801,(uint *)&DAT_1002d554,5,(uint *)&DAT_1002d55c,5,
                           (uint *)&DAT_1002d564,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6602,(uint *)&DAT_1002d574,8,(uint *)&DAT_1002d57c,8,
                           (uint *)&DAT_1002d584,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6602,(uint *)&DAT_1002d574,8,(uint *)&DAT_1002d57c,8,
                           (uint *)&DAT_1002d58c,0x1002d56c);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6601,(uint *)&DAT_1002d5b4,8,(uint *)&DAT_1002d5bc,8,
                           (uint *)&DAT_1002d5c4,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6601,(uint *)&DAT_1002d5b4,8,(uint *)&DAT_1002d5bc,8,
                           (uint *)&DAT_1002d5cc,0x1002d56c);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6603,(uint *)&DAT_1002d5d4,0x18,(uint *)&DAT_1002d5ec,8,
                           (uint *)&DAT_1002d5f4,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6603,(uint *)&DAT_1002d5d4,0x18,(uint *)&DAT_1002d5ec,8,
                           (uint *)&DAT_1002d5fc,0x1002d56c);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6609,(uint *)&DAT_1002d604,0x10,(uint *)&DAT_1002d614,8,
                           (uint *)&DAT_1002d61c,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6609,(uint *)&DAT_1002d604,0x10,(uint *)&DAT_1002d614,8,
                           (uint *)&DAT_1002d624,0x1002d56c);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x660e,(uint *)&DAT_1002d63c,0x10,(uint *)&DAT_1002d62c,0x10,
                           (uint *)&DAT_1002d64c,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x660f,(uint *)&DAT_1002d65c,0x18,(uint *)&DAT_1002d62c,0x10,
                           (uint *)&DAT_1002d674,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6610,(uint *)&DAT_1002d684,0x20,(uint *)&DAT_1002d62c,0x10,
                           (uint *)&DAT_1002d6a4,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x660e,(uint *)&DAT_1002d63c,0x10,(uint *)&DAT_1002d62c,0x10,
                           (uint *)&DAT_1002d6c4,0x1002d6b4);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x660f,(uint *)&DAT_1002d65c,0x18,(uint *)&DAT_1002d62c,0x10,
                           (uint *)&DAT_1002d6d4,0x1002d6b4);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_100128b0(0x6610,(uint *)&DAT_1002d684,0x20,(uint *)&DAT_1002d62c,0x10,
                           (uint *)&DAT_1002d6e4,0x1002d6b4);
      return iVar1;
    }
    iVar1 = -0x7ff6ffe0;
  }
  return iVar1;
}



/* 10009df8 FUN_10009df8 */

/* Boundary evidence: original MIPS .pdata 10009df8..10009ec7. Semantic name remains unreviewed. */

undefined4 FUN_10009df8(HMODULE param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  DAT_1002da4c = param_1;
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    GetModuleFileNameW(param_1,(LPWSTR)&DAT_1002da50,0x104);
    FUN_10027470();
    iVar1 = FUN_100275d0(0,(LPCWSTR)&DAT_1002da50);
    if (((iVar1 == 0) || (iVar1 = FUN_10009664(), iVar1 != 0)) ||
       (iVar1 = FUN_10009948(), iVar1 != 0)) {
      uVar2 = 0;
    }
  }
  else if (param_2 == 0) {
    FUN_10027470();
  }
  return uVar2;
}



/* 10009ec8 FUN_10009ec8 */

/* Boundary evidence: original MIPS .pdata 10009ec8..1000a28b. Semantic name remains unreviewed. */

undefined4
FUN_10009ec8(int *param_1,undefined4 param_2,int param_3,uint param_4,uint param_5,void *param_6)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1[3];
  if ((((*param_1 != 0x31415352) && (*param_1 != 0x32415352)) || (uVar4 = param_1[2], uVar4 < 0x40))
     || (((0x100000 < uVar4 || ((uint)param_1[1] <= uVar5)) ||
         ((0x1000000 < (uint)param_1[1] || ((uVar4 + 7 >> 3) - 1 != uVar5)))))) {
    return 0x80090003;
  }
  if (uVar5 - 2 < param_4) {
    return 0x80090004;
  }
  *(undefined1 *)((int)param_6 + param_1[3] + -1) = 1;
  memset(param_6,0xff,param_1[3] - 1);
  uVar4 = 0;
  if (param_4 != 0) {
    puVar2 = (undefined1 *)(param_3 + param_4);
    do {
      puVar2 = puVar2 + -1;
      puVar3 = (undefined1 *)(uVar4 + (int)param_6);
      uVar4 = uVar4 + 1;
      *puVar3 = *puVar2;
    } while (uVar4 < param_4);
  }
  uVar5 = (uVar5 - 2) - param_4;
  if ((param_5 & 1) != 0) {
switchD_1000a010_caseD_8008:
    *(undefined1 *)(param_4 + (int)param_6) = 0;
    return 0;
  }
  switch(param_2) {
  case 0x8001:
    puVar2 = (undefined1 *)(param_4 + (int)param_6);
    puVar3 = PTR_DAT_1002d790;
    for (cVar1 = *PTR_DAT_1002d790; cVar1 != '\0'; cVar1 = cVar1 + -1) {
      puVar3 = puVar3 + 1;
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
    }
    break;
  case 0x8002:
    puVar2 = (undefined1 *)(param_4 + (int)param_6);
    puVar3 = PTR_DAT_1002d79c;
    for (cVar1 = *PTR_DAT_1002d79c; cVar1 != '\0'; cVar1 = cVar1 + -1) {
      puVar3 = puVar3 + 1;
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
    }
    goto LAB_1000a0b0;
  case 0x8003:
    puVar2 = (undefined1 *)(param_4 + (int)param_6);
    puVar3 = PTR_DAT_1002d7a8;
    for (cVar1 = *PTR_DAT_1002d7a8; cVar1 != '\0'; cVar1 = cVar1 + -1) {
      puVar3 = puVar3 + 1;
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
    }
    break;
  case 0x8004:
    puVar2 = (undefined1 *)(param_4 + (int)param_6);
    puVar3 = PTR_DAT_1002d7b8;
    for (cVar1 = *PTR_DAT_1002d7b8; cVar1 != '\0'; cVar1 = cVar1 + -1) {
      puVar3 = puVar3 + 1;
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
    }
LAB_1000a0b0:
    *puVar2 = 0;
    return 0;
  default:
    return 0x80090008;
  case 0x8008:
    goto switchD_1000a010_caseD_8008;
  case 0x800c:
    uVar4 = (uint)(byte)*PTR_DAT_1002d7c4;
    puVar2 = (undefined1 *)(param_4 + (int)param_6);
    puVar3 = PTR_DAT_1002d7c4;
    if (uVar5 < uVar4) {
      return 0x80090004;
    }
    for (; uVar4 != 0; uVar4 = uVar4 + 0xff & 0xff) {
      *puVar2 = puVar3[1];
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    goto LAB_1000a240;
  case 0x800d:
    puVar2 = (undefined1 *)(param_4 + (int)param_6);
    uVar4 = (uint)(byte)*PTR_DAT_1002d7d0;
    puVar3 = PTR_DAT_1002d7d0;
    if (uVar5 < uVar4) {
      return 0x80090004;
    }
    for (; uVar4 != 0; uVar4 = uVar4 + 0xff & 0xff) {
      *puVar2 = puVar3[1];
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    break;
  case 0x800e:
    puVar2 = (undefined1 *)(param_4 + (int)param_6);
    uVar4 = (uint)(byte)*PTR_DAT_1002d7dc;
    puVar3 = PTR_DAT_1002d7dc;
    if (uVar5 < uVar4) {
      return 0x80090004;
    }
    for (; uVar4 != 0; uVar4 = uVar4 + 0xff & 0xff) {
      *puVar2 = puVar3[1];
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
LAB_1000a240:
    *puVar2 = 0;
    return 0;
  }
  *puVar2 = 0;
  return 0;
}



/* 1000a28c FUN_1000a28c */

/* Boundary evidence: original MIPS .pdata 1000a28c..1000a33f. Semantic name remains unreviewed. */

void FUN_1000a28c(int param_1,int param_2,uint param_3,int param_4,undefined1 *param_5)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  *param_5 = 0xcc;
  param_5[1] = 0x33;
  uVar3 = 0;
  if (param_3 != 0) {
    puVar2 = (undefined1 *)(param_2 + param_3);
    do {
      puVar2 = puVar2 + -1;
      iVar1 = uVar3 + 2;
      uVar3 = uVar3 + 1;
      param_5[iVar1] = *puVar2;
    } while (uVar3 < param_3);
  }
  param_5[0x16] = 0xba;
  memset(param_5 + 0x17,0xbb,param_1 - 0x18);
  if (param_4 == 0) {
    param_5[param_1 + -1] = 0x4b;
  }
  else {
    param_5[param_1 + -1] = 0x6b;
  }
  return;
}



/* 1000a340 FUN_1000a340 */

/* Boundary evidence: original MIPS .pdata 1000a340..1000a5ab. Semantic name remains unreviewed. */

undefined4
FUN_1000a340(int param_1,undefined4 param_2,int param_3,uint param_4,uint param_5,void *param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  byte *pbVar7;
  char *pcVar8;
  undefined **ppuVar9;
  undefined4 uVar10;
  undefined1 local_68 [64];
  uint local_28;
  
  local_28 = DAT_1002da44;
  switch(param_2) {
  case 0x8001:
    ppuVar9 = &PTR_DAT_1002d790;
    break;
  case 0x8002:
    ppuVar9 = &PTR_DAT_1002d79c;
    break;
  case 0x8003:
    ppuVar9 = &PTR_DAT_1002d7a8;
    break;
  case 0x8004:
    ppuVar9 = &PTR_DAT_1002d7b8;
    break;
  default:
    uVar10 = 0x80090002;
    goto LAB_1000a578;
  case 0x8008:
    ppuVar9 = (undefined **)0x0;
    break;
  case 0x800c:
    ppuVar9 = &PTR_DAT_1002d7c4;
    break;
  case 0x800d:
    ppuVar9 = &PTR_DAT_1002d7d0;
    break;
  case 0x800e:
    ppuVar9 = &PTR_DAT_1002d7dc;
  }
  uVar6 = 0;
  if (param_4 != 0) {
    puVar4 = (undefined1 *)(param_3 + param_4);
    do {
      puVar4 = puVar4 + -1;
      puVar5 = local_68 + uVar6;
      uVar6 = uVar6 + 1;
      *puVar5 = *puVar4;
    } while (uVar6 < param_4);
  }
  iVar2 = memcmp(local_68,param_6,param_4);
  if (iVar2 == 0) {
    if (((param_5 & 1) == 0) && (ppuVar9 != (undefined **)0x0)) {
      pbVar7 = *ppuVar9;
      iVar2 = 0;
      if (*pbVar7 != 0) {
        do {
          bVar1 = *pbVar7;
          iVar3 = memcmp((void *)(param_4 + (int)param_6),pbVar7 + 1,(uint)bVar1);
          if (iVar3 == 0) {
            param_4 = bVar1 + param_4;
            break;
          }
          iVar2 = iVar2 + 1;
          pbVar7 = ppuVar9[iVar2];
        } while (*pbVar7 != 0);
      }
    }
    if (*(char *)(param_4 + (int)param_6) == '\0') {
      pcVar8 = (char *)(*(int *)(param_1 + 0xc) + (int)param_6);
      if ((*pcVar8 == '\0') && (pcVar8[-1] == '\x01')) {
        do {
          param_4 = param_4 + 1;
          if (*(int *)(param_1 + 0xc) - 1U <= param_4) {
            uVar10 = 0;
            goto LAB_1000a578;
          }
        } while (*(char *)(param_4 + (int)param_6) == -1);
      }
    }
  }
  uVar10 = 0x80090006;
LAB_1000a578:
  FUN_1002bedc(local_28);
  return uVar10;
}



/* 1000a5ac FUN_1000a5ac */

/* Boundary evidence: original MIPS .pdata 1000a5ac..1000a6ff. Semantic name remains unreviewed. */

undefined4 FUN_1000a5ac(int param_1,uint param_2,int param_3,char *param_4,uint param_5)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 local_38 [36];
  uint local_14;
  
  local_14 = DAT_1002da44;
  if ((((0x17 < param_5) && (param_2 < param_5 - 2)) && (*param_4 == -0x34)) &&
     ((param_4[1] == '3' && (param_4[param_2 + 2] == -0x46)))) {
    uVar4 = 0;
    if (param_2 != 0) {
      puVar2 = (undefined1 *)(param_1 + param_2);
      do {
        puVar2 = puVar2 + -1;
        puVar3 = local_38 + uVar4;
        uVar4 = uVar4 + 1;
        *puVar3 = *puVar2;
      } while (uVar4 < param_2);
    }
    iVar1 = memcmp(local_38,param_4 + 2,param_2);
    if (iVar1 == 0) {
      uVar4 = 0x17;
      if (0x17 < param_5 - 0x18) {
        do {
          if (param_4[uVar4] != -0x45) goto LAB_1000a6bc;
          uVar4 = uVar4 + 1;
        } while (uVar4 < param_5 - 0x18);
      }
      if (param_3 == 0) {
        if (param_4[param_5 - 1] == 'K') goto LAB_1000a6f8;
      }
      else if (param_4[param_5 - 1] == 'k') {
LAB_1000a6f8:
        uVar5 = 0;
        goto LAB_1000a6c4;
      }
    }
  }
LAB_1000a6bc:
  uVar5 = 0x80090006;
LAB_1000a6c4:
  FUN_1002bedc(local_14);
  return uVar5;
}



/* 1000a700 FUN_1000a700 */

/* Boundary evidence: original MIPS .pdata 1000a700..1000a847. Semantic name remains unreviewed. */

int FUN_1000a700(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
                uint param_6,int param_7,int param_8,uint *param_9,uint param_10,uint *param_11,
                uint param_12)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7ff6fffd;
  }
  else {
    uVar2 = param_2[2] + 7U >> 3;
    if ((param_12 < (uint)param_2[1]) || (param_10 < uVar2)) {
      iVar1 = 0x54f;
    }
    else {
      memset(param_11,0,param_12);
      iVar1 = FUN_10016b18(param_1,param_2,param_9,param_11);
      if (iVar1 == 0) {
        if (param_3 == 1) {
          iVar1 = FUN_1000a340((int)param_2,param_4,param_5,param_6,(uint)(param_8 != 0),param_11);
        }
        else {
          if (param_3 != 2) {
            return -0x7ff6fff7;
          }
          iVar1 = FUN_1000a5ac(param_5,param_6,param_7,(char *)param_11,uVar2);
        }
        if (iVar1 == 0) {
          iVar1 = 0;
        }
      }
    }
  }
  return iVar1;
}



/* 1000a848 FUN_1000a848 */

/* Boundary evidence: original MIPS .pdata 1000a848..1000a9f3. Semantic name remains unreviewed. */

int FUN_1000a848(undefined4 param_1,int *param_2,void *param_3,int param_4,undefined4 param_5,
                int param_6,uint param_7,int param_8,int param_9,undefined1 *param_10,uint param_11,
                uint *param_12,size_t *param_13)

{
  int iVar1;
  uint uVar2;
  
  if ((param_2 == (int *)0x0) || (param_3 == (void *)0x0)) {
    iVar1 = -0x7ff6fffd;
  }
  else if (param_13 == (size_t *)0x0) {
    iVar1 = 0x57;
  }
  else {
    uVar2 = param_2[2] + 7U >> 3;
    if ((param_11 < uVar2) || (*param_13 < (uint)param_2[1])) {
      iVar1 = 0x54f;
    }
    else {
      if ((param_12 == (uint *)0x0) || (*param_13 < uVar2)) {
        *param_13 = uVar2;
        if (param_12 != (uint *)0x0) {
          return 0xea;
        }
      }
      else {
        memset(param_10,0,param_11);
        memset(param_12,0,*param_13);
        if (param_4 == 1) {
          iVar1 = FUN_10009ec8(param_2,param_5,param_6,param_7,(uint)(param_9 != 0),param_10);
          if (iVar1 != 0) {
            return iVar1;
          }
        }
        else {
          if (param_4 != 2) {
            return -0x7ff6fff7;
          }
          FUN_1000a28c(uVar2,param_6,param_7,param_8,param_10);
        }
        iVar1 = FUN_100171e0(param_1,param_3,param_10,param_12);
        if (iVar1 != 0) {
          return iVar1;
        }
        *param_13 = uVar2;
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 1000a9f4 FUN_1000a9f4 */

/* Boundary evidence: original MIPS .pdata 1000a9f4..1000aa3f. Semantic name remains unreviewed. */

undefined4 FUN_1000a9f4(uint param_1,uint param_2)

{
  undefined4 extraout_v0;
  undefined4 uVar1;
  
  uVar1 = (undefined4)((ulonglong)param_1 * (ulonglong)param_2);
  if ((int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20) != 0) {
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
    uVar1 = extraout_v0;
  }
  return uVar1;
}



/* 1000aa40 FUN_1000aa40 */

/* Boundary evidence: original MIPS .pdata 1000aa40..1000aa97. Semantic name remains unreviewed. */

undefined4 * FUN_1000aa40(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *extraout_v0;
  
  if ((param_4 < 1) && ((0 < param_4 || (param_4 == 0)))) {
    *param_1 = param_3;
  }
  else {
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
    param_1 = extraout_v0;
  }
  return param_1;
}



/* 1000aa98 FUN_1000aa98 */

/* Boundary evidence: original MIPS .pdata 1000aa98..1000ab0f. Semantic name remains unreviewed. */

undefined4 * FUN_1000aa98(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if ((int)param_3 < 0) {
    param_3 = 0;
    param_2 = 0;
    param_1 = (undefined4 *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  uVar1 = (undefined4)((ulonglong)param_2 * (ulonglong)param_3);
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) != 0) {
    param_1 = (undefined4 *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_1 = uVar1;
  return param_1;
}



/* 1000ab10 FUN_1000ab10 */

/* Boundary evidence: original MIPS .pdata 1000ab10..1000ab5f. Semantic name remains unreviewed. */

uint * FUN_1000ab10(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *param_1 + param_3;
  if (uVar1 < *param_1) {
    param_2 = (uint *)0x0;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_2 = uVar1;
  return param_2;
}



/* 1000ab60 FUN_1000ab60 */

/* Boundary evidence: original MIPS .pdata 1000ab60..1000ae03. Semantic name remains unreviewed. */

int FUN_1000ab60(undefined4 param_1,int *param_2,void *param_3)

{
  uint *hMem;
  SIZE_T uBytes;
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint local_48 [2];
  char local_40 [20];
  uint local_2c;
  
  local_2c = DAT_1002da44;
  uVar4 = param_2[1];
  uVar2 = (uint)((ulonglong)uVar4 * 2);
  if ((int)((ulonglong)uVar4 * 2 >> 0x20) != 0) {
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  uBytes = uVar2 + 4;
  if (uBytes < uVar2) {
    uBytes = 0;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  hMem = LocalAlloc(0x40,uBytes);
  if (hMem == (uint *)0x0) {
    iVar3 = 0xe;
  }
  else {
    puVar5 = (uint *)((param_2[1] + 4U & 0xfffffffc) + (int)hMem);
    uVar2 = 0;
    do {
      pcVar1 = local_40 + uVar2;
      uVar2 = uVar2 + 1;
      *pcVar1 = ('\x01' - (char)local_40) + (char)pcVar1;
    } while (uVar2 < 0x14);
    local_48[0] = uVar4;
    iVar3 = FUN_1000a848(param_1,param_2,param_3,2,0x8004,(int)local_40,0x14,1,0,(undefined1 *)hMem,
                         uVar4,puVar5,local_48);
    if ((((iVar3 == 0) &&
         (iVar3 = FUN_1000a700(param_1,param_2,2,0x8004,(int)local_40,0x14,1,0,puVar5,local_48[0],
                               hMem,uVar4), iVar3 == 0)) &&
        (local_48[0] = uVar4,
        iVar3 = FUN_1000a848(param_1,param_2,param_3,1,0x8004,(int)local_40,0x14,0,0,
                             (undefined1 *)hMem,uVar4,puVar5,local_48), iVar3 == 0)) &&
       (iVar3 = FUN_1000a700(param_1,param_2,1,0x8004,(int)local_40,0x14,0,0,puVar5,local_48[0],hMem
                             ,uVar4), iVar3 == 0)) {
      LocalFree(hMem);
      FUN_1002bedc(local_2c);
      return 0;
    }
    LocalFree(hMem);
  }
  FUN_1002bedc(local_2c);
  return iVar3;
}



/* 1000ae04 BSafeMakeKeyPair */

/* Boundary evidence: original MIPS .pdata 1000ae04..1000ae87. Semantic name remains unreviewed. */

undefined4 BSafeMakeKeyPair(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  
                    /* 0xae04  8  BSafeMakeKeyPair */
  iVar1 = FUN_1001a65c(param_1,param_2,param_3);
  if (((iVar1 != 0) && (iVar1 = FUN_10018068(param_1,param_2,1), iVar1 == 0)) &&
     (iVar1 = FUN_1000ab60(0,param_1,param_2), iVar1 == 0)) {
    return 1;
  }
  return 0;
}



/* 1000ae88 CPSignHash */

/* Boundary evidence: original MIPS .pdata 1000ae88..1000b367. Semantic name remains unreviewed. */

int CPSignHash(uint param_1,uint param_2,int param_3,wchar_t *param_4,uint param_5,void *param_6,
              uint *param_7)

{
  uint *puVar1;
  int iVar2;
  size_t sVar3;
  DWORD DVar4;
  SIZE_T uBytes;
  DWORD dwErrCode;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  int *piVar9;
  undefined1 *hMem;
  int iVar10;
  uint local_98;
  uint local_94;
  uint local_90;
  void *local_8c;
  uint local_88;
  uint *local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  uint auStack_70 [16];
  uint local_30;
  
                    /* 0xae88  33  CPSignHash */
  local_30 = DAT_1002da44;
  local_8c = param_6;
  local_7c = 0x40;
  local_84 = param_7;
  dwErrCode = 0x54f;
  hMem = (undefined1 *)0x0;
  local_78 = 0;
  local_94 = param_1;
  local_90 = param_2;
  if ((param_5 & 0xfffffffa) == 0) {
    puVar1 = (uint *)FUN_100091fc(param_1,0);
    if (puVar1 == (uint *)0x0) {
      dwErrCode = 0x80090001;
    }
    else {
      iVar5 = 1;
      iVar10 = 2;
      if (param_3 == 1) {
        piVar9 = (int *)puVar1[0x13];
        iVar8 = 0;
        local_98 = DAT_1002dcc0;
LAB_1000af94:
        if (piVar9 == (int *)0x0) {
LAB_1000af9c:
          dwErrCode = 0x8009000d;
        }
        else {
          uVar6 = piVar9[2] + 7U >> 3;
          if ((local_8c == (void *)0x0) || (*local_84 < uVar6)) {
            *local_84 = uVar6;
            if (local_8c != (void *)0x0) {
              dwErrCode = 0xea;
              goto LAB_1000b300;
            }
LAB_1000b2d8:
            dwErrCode = 0;
            goto LAB_1000b304;
          }
          local_80 = 4;
          iVar2 = CPGetHashParam(local_94,local_90,1,&local_88,&local_80,0);
          if (iVar2 != 0) {
            memset(local_8c,0,uVar6);
            uVar6 = local_88 - 0x8001;
            if ((((local_88 != 0x8001) && (3 < uVar6)) && (uVar6 != 7)) &&
               ((uVar6 != 0xb && (2 < local_88 - 0x800c)))) goto LAB_1000af74;
            if (param_4 != (wchar_t *)0x0) {
              sVar3 = wcslen(param_4);
              iVar2 = CPHashData(local_94,local_90,(int)param_4,sVar3 << 1,0);
              if (iVar2 == 0) goto LAB_1000b0bc;
            }
            iVar2 = CPGetHashParam(local_94,local_90,2,auStack_70,&local_7c,0);
            if (iVar2 != 0) {
              uVar6 = (uint)((ulonglong)(uint)piVar9[1] * 2);
              if ((int)((ulonglong)(uint)piVar9[1] * 2 >> 0x20) != 0) {
                RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
              }
              uBytes = uVar6 + 4;
              if (uBytes < uVar6) {
                uBytes = 0;
                RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
              }
              hMem = LocalAlloc(0x40,uBytes);
              if (hMem == (undefined1 *)0x0) {
                dwErrCode = 8;
              }
              else {
                iVar2 = piVar9[1];
                DVar4 = FUN_1000bb68(puVar1,local_98,iVar8,0);
                if (DVar4 != 0) goto LAB_1000b2f8;
                if (iVar8 == 0) {
                  pvVar7 = (void *)puVar1[0x1b];
                }
                else {
                  pvVar7 = (void *)puVar1[0x1d];
                }
                if (pvVar7 == (void *)0x0) goto LAB_1000af9c;
                if (piVar9[1] == *(int *)((int)pvVar7 + 4)) {
                  iVar8 = local_78;
                  if ((param_5 & 4) != 0) {
                    if (local_88 != 0x8004) goto LAB_1000af74;
                    local_80 = 4;
                    iVar8 = CPGetHashParam(local_94,local_90,0x11,&local_98,&local_80,0);
                    if (iVar8 == 0) goto LAB_1000b300;
                    if ((local_98 & 2) == 0) {
                      iVar8 = 0;
                    }
                    else {
                      iVar8 = 1;
                    }
                  }
                  local_98 = piVar9[1];
                  if ((param_5 & 4) == 0) {
                    iVar10 = 1;
                  }
                  iVar10 = FUN_1000a848(puVar1[0x2d],piVar9,pvVar7,iVar10,local_88,(int)auStack_70,
                                        local_7c,iVar8,(uint)((param_5 & 1) != 0),hMem,local_98,
                                        (uint *)(hMem + (iVar2 + 4U & 0xfffffffc)),&local_98);
                  uVar6 = local_98;
                  if (iVar10 == 0) {
                    memcpy(local_8c,hMem + (iVar2 + 4U & 0xfffffffc),local_98);
                    *local_84 = uVar6;
                    goto LAB_1000b2d8;
                  }
                }
                else {
                  dwErrCode = 0x8009001a;
                }
              }
              goto LAB_1000b300;
            }
          }
LAB_1000b0bc:
          DVar4 = GetLastError();
LAB_1000b2f8:
          dwErrCode = DVar4;
          if (dwErrCode == 0) goto LAB_1000b304;
        }
      }
      else {
        if (param_3 != 2) {
          DVar4 = 0x80090008;
          goto LAB_1000b2f8;
        }
        if (puVar1[1] != 0xc) {
          piVar9 = (int *)puVar1[0x10];
          iVar8 = 1;
          local_98 = DAT_1002dcec;
          goto LAB_1000af94;
        }
LAB_1000af74:
        dwErrCode = 0x80090008;
      }
    }
  }
  else {
    dwErrCode = 0x80090009;
  }
LAB_1000b300:
  iVar5 = 0;
LAB_1000b304:
  if (hMem != (undefined1 *)0x0) {
    LocalFree(hMem);
  }
  if (iVar5 == 0) {
    SetLastError(dwErrCode);
  }
  FUN_1002bedc(local_30);
  return iVar5;
}



/* 1000b368 CPVerifySignature */

/* Boundary evidence: original MIPS .pdata 1000b368..1000b7df. Semantic name remains unreviewed. */

int CPVerifySignature(uint param_1,uint param_2,void *param_3,uint param_4,uint param_5,
                     wchar_t *param_6,uint param_7)

{
  int iVar1;
  size_t sVar2;
  SIZE_T uBytes;
  uint uVar3;
  uint uVar4;
  DWORD dwErrCode;
  uint *_Dst;
  uint *hMem;
  int *piVar5;
  int iVar6;
  uint local_90 [3];
  uint local_84;
  int local_80;
  uint local_7c;
  void *local_78;
  uint auStack_70 [16];
  uint local_30;
  
                    /* 0xb368  34  CPVerifySignature */
  local_30 = DAT_1002da44;
  hMem = (uint *)0x0;
  local_90[0] = 0x40;
  local_7c = param_4;
  local_78 = param_3;
  if ((param_7 & 0xfffffffa) == 0) {
    local_90[2] = FUN_100091fc(param_1,0);
    if (local_90[2] == 0) {
      dwErrCode = 0x80090001;
    }
    else {
      local_90[1] = 4;
      iVar6 = 1;
      iVar1 = CPGetHashParam(param_1,param_2,1,&local_84,local_90 + 1,0);
      if (iVar1 == 0) {
LAB_1000b660:
        dwErrCode = GetLastError();
LAB_1000b770:
        if (dwErrCode == 0) goto LAB_1000b77c;
      }
      else if (((((local_84 == 0x8001) || (local_84 == 0x8002)) || (local_84 == 0x8003)) ||
               ((local_84 == 0x8004 || (local_84 == 0x8008)))) ||
              ((local_84 == 0x800c || ((local_84 == 0x800d || (local_84 == 0x800e)))))) {
        uVar3 = (uint)*(byte *)((param_5 ^ 0xe35a172c) + 4);
        if ((uVar3 < 3) || (4 < uVar3)) {
          dwErrCode = 0x80090003;
          goto LAB_1000b770;
        }
        dwErrCode = FUN_10009224(param_5,param_1,uVar3,&local_80);
        if (dwErrCode == 0) {
          piVar5 = *(int **)(local_80 + 0x10);
          uVar3 = piVar5[2] + 7U >> 3;
          if (local_7c == uVar3) {
            uVar4 = (uint)((ulonglong)(uint)piVar5[1] * 2);
            if ((int)((ulonglong)(uint)piVar5[1] * 2 >> 0x20) != 0) {
              RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
            }
            uBytes = uVar4 + 4;
            if (uBytes < uVar4) {
              uBytes = 0;
              RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
            }
            hMem = LocalAlloc(0x40,uBytes);
            if (hMem == (uint *)0x0) {
              dwErrCode = 8;
            }
            else {
              _Dst = (uint *)((piVar5[1] + 4U & 0xfffffffc) + (int)hMem);
              memcpy(_Dst,local_78,uVar3);
              dwErrCode = FUN_10016b18(*(undefined4 *)(local_90[2] + 0xb4),piVar5,_Dst,hMem);
              if (dwErrCode == 0) {
                if (param_6 != (wchar_t *)0x0) {
                  sVar2 = wcslen(param_6);
                  iVar1 = CPHashData(param_1,param_2,(int)param_6,sVar2 << 1,0);
                  if (iVar1 == 0) goto LAB_1000b660;
                }
                iVar1 = CPGetHashParam(param_1,param_2,2,auStack_70,local_90,0);
                if (iVar1 == 0) goto LAB_1000b660;
                if ((param_7 & 4) == 0) {
                  dwErrCode = FUN_1000a340((int)piVar5,local_84,(int)auStack_70,local_90[0],param_7,
                                           hMem);
                  if (dwErrCode == 0) goto LAB_1000b760;
                }
                else {
                  local_90[1] = 4;
                  iVar1 = CPGetHashParam(param_1,param_2,0x11,local_90 + 2,local_90 + 1,0);
                  if (iVar1 != 0) {
                    uVar3 = local_90[2] & 2;
                    if ((*hMem & 0xf) != 0xc) {
                      FUN_1001ea90((int)hMem,(int)(piVar5 + 5),hMem,piVar5[2] + 7U >> 5);
                    }
                    dwErrCode = FUN_1000a5ac((int)auStack_70,local_90[0],(uint)(uVar3 != 0),
                                             (char *)hMem,piVar5[2] + 7U >> 3);
                    if (dwErrCode != 0) goto LAB_1000b770;
LAB_1000b760:
                    dwErrCode = 0;
                    goto LAB_1000b77c;
                  }
                  dwErrCode = 0x54f;
                }
              }
            }
          }
          else {
            dwErrCode = 0x80090006;
          }
        }
        else {
          if (dwErrCode != 0x80090020) goto LAB_1000b770;
          dwErrCode = 0x80090003;
        }
      }
      else {
        dwErrCode = 0x80090002;
      }
    }
  }
  else {
    dwErrCode = 0x80090009;
  }
  iVar6 = 0;
LAB_1000b77c:
  if (hMem != (uint *)0x0) {
    LocalFree(hMem);
  }
  if (iVar6 == 0) {
    SetLastError(dwErrCode);
  }
  FUN_1002bedc(local_30);
  return iVar6;
}



/* 1000b7e0 FUN_1000b7e0 */

/* Boundary evidence: original MIPS .pdata 1000b7e0..1000b8eb. Semantic name remains unreviewed. */

DWORD FUN_1000b7e0(int param_1,wchar_t *param_2,uint param_3)

{
  DWORD DVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = param_3 & 0x20;
  piVar3 = (int *)(param_1 + 0x1c);
  DVar1 = FUN_1002b7cc(*(wchar_t **)(param_1 + 0xbc),param_2,uVar2,param_3,piVar3);
  if ((param_3 & 8) == 0) {
    if (DVar1 != 0) {
      return DVar1;
    }
    *(undefined4 *)(param_1 + 0x8c) = 2;
  }
  else {
    if (DVar1 != 0x80090016) {
      if (DVar1 != 0) {
        return DVar1;
      }
      return 0x8009000f;
    }
    DVar1 = FUN_1002acec(param_2,(int)piVar3);
    if (DVar1 != 0) {
      return DVar1;
    }
    if (*(int *)(param_1 + 0x78) == 0) {
      if ((uVar2 == 0) && (DVar1 = FUN_1002ad50(), DVar1 != 0)) {
        return DVar1;
      }
      *(undefined4 *)(param_1 + 0x8c) = 2;
      DVar1 = FUN_1002b1c8(*(wchar_t **)(param_1 + 0xbc),uVar2,piVar3);
      if (DVar1 != 0) {
        return DVar1;
      }
    }
  }
  return 0;
}



/* 1000b8ec FUN_1000b8ec */

/* Boundary evidence: original MIPS .pdata 1000b8ec..1000bb67. Semantic name remains unreviewed. */

DWORD FUN_1000b8ec(uint *param_1,uint param_2,uint param_3,int param_4)

{
  BYTE *pBVar1;
  BYTE *_Dst;
  HLOCAL _Dst_00;
  DWORD DVar2;
  SIZE_T uBytes;
  void *_Src;
  uint *puVar3;
  uint *puVar4;
  DATA_BLOB local_48;
  DATA_BLOB local_40;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  
  memset(&local_40,0,8);
  memset(&local_48,0,8);
  memset(&local_38,0,0x10);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
  if (param_4 == 0) {
    uBytes = param_1[0x1a];
    _Src = (void *)param_1[0x1b];
    puVar3 = param_1 + 0x14;
    puVar4 = param_1 + 0xd;
  }
  else {
    uBytes = param_1[0x1c];
    _Src = (void *)param_1[0x1d];
    puVar3 = param_1 + 0x11;
    puVar4 = param_1 + 0xb;
  }
  local_40.cbData = uBytes;
  _Dst = LocalAlloc(0x40,uBytes);
  DVar2 = 8;
  if (_Dst != (BYTE *)0x0) {
    memcpy(_Dst,_Src,uBytes);
    local_38 = 0x10;
    local_40.pbData = _Dst;
    if ((param_3 & 2) != 0) {
      if (param_1[0xf] != 0) {
        DVar2 = 0x80090022;
        goto LAB_1000baf0;
      }
      if (param_4 == 0) {
        param_1[8] = param_1[8] | 1;
      }
      else {
        param_1[8] = param_1[8] | 2;
      }
      local_34 = 3;
    }
    if (param_2 != 0) {
      local_30 = param_1[0x22];
      local_2c = param_1[0x25];
      if (local_2c == 0) {
        local_2c = param_2;
      }
    }
    DVar2 = 4;
    if ((*param_1 & 0x20) == 0) {
      DVar2 = 0;
    }
    DVar2 = FUN_1002ac20(&local_40,DAT_1002dd14,(DATA_BLOB *)0x0,(PVOID)0x0,&local_38,DVar2,
                         &local_48);
    if ((DVar2 == 0) &&
       (_Dst_00 = LocalAlloc(0x40,local_48.cbData), DVar2 = 8, _Dst_00 != (HLOCAL)0x0)) {
      memcpy(_Dst_00,local_48.pbData,local_48.cbData);
      if ((HLOCAL)*puVar3 != (HLOCAL)0x0) {
        LocalFree((HLOCAL)*puVar3);
      }
      *puVar4 = local_48.cbData;
      *puVar3 = (uint)_Dst_00;
      DVar2 = FUN_1002b1c8((wchar_t *)param_1[0x2f],*param_1 & 0x20,(int *)(param_1 + 7));
    }
  }
LAB_1000baf0:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
  pBVar1 = _Dst;
  if (_Dst != (BYTE *)0x0) {
    for (; uBytes != 0; uBytes = uBytes - 1) {
      *pBVar1 = '\0';
      pBVar1 = pBVar1 + 1;
    }
    LocalFree(_Dst);
  }
  if (local_48.pbData != (BYTE *)0x0) {
    LocalFree(local_48.pbData);
  }
  return DVar2;
}



/* 1000bb68 FUN_1000bb68 */

/* Boundary evidence: original MIPS .pdata 1000bb68..1000bdef. Semantic name remains unreviewed. */

DWORD FUN_1000bb68(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  HLOCAL _Dst;
  uint *puVar1;
  DWORD DVar2;
  BYTE *pBVar3;
  uint uVar4;
  uint *puVar5;
  DWORD DVar6;
  uint local_4c;
  DATA_BLOB local_48;
  DATA_BLOB local_40;
  undefined4 local_38 [2];
  uint local_30;
  undefined4 local_2c;
  
  DVar6 = 0;
  memset(&local_48,0,8);
  if (param_4 == 0) {
    puVar1 = param_1 + 0x1d;
    if (param_3 == 0) {
      puVar1 = param_1 + 0x1b;
    }
    if (*puVar1 != 0) {
      if ((*param_1 & 0xf0000000) != 0) {
        DVar2 = 0;
        goto LAB_1000bd9c;
      }
      param_4 = 1;
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
  if (param_3 == 0) {
    pBVar3 = (BYTE *)param_1[0x14];
    uVar4 = param_1[0xd];
    puVar5 = param_1 + 0x1a;
    puVar1 = param_1 + 0x1b;
  }
  else {
    pBVar3 = (BYTE *)param_1[0x11];
    uVar4 = param_1[0xb];
    puVar5 = param_1 + 0x1c;
    puVar1 = param_1 + 0x1d;
  }
  if ((*puVar1 == 0) || (param_4 != 0)) {
    memset(&local_40,0,8);
    memset(local_38,0,0x10);
    if ((*param_1 & 0x20) != 0) {
      DVar6 = 4;
    }
    local_30 = param_1[0x22];
    local_38[0] = 0x10;
    local_40.cbData = uVar4;
    local_40.pbData = pBVar3;
    local_2c = param_2;
    DVar2 = FUN_1002ac80(&local_40,(LPWSTR *)0x0,(DATA_BLOB *)0x0,(PVOID)0x0,local_38,DVar6,
                         &local_48,&local_4c);
    DVar6 = local_48.cbData;
    if (DVar2 == 0) {
      if ((((3 < local_48.cbData) && (*local_48.pbData == 'R')) && (local_48.pbData[1] == 'S')) &&
         (local_48.pbData[2] == 'A')) {
        if (*puVar1 == 0) {
          _Dst = LocalAlloc(0x40,local_48.cbData);
          if (_Dst == (HLOCAL)0x0) {
            DVar2 = 8;
            goto LAB_1000bd94;
          }
          memcpy(_Dst,local_48.pbData,local_48.cbData);
          *puVar5 = DVar6;
          *puVar1 = (uint)_Dst;
        }
        if ((local_4c & 8) != 0) {
          FUN_1000b8ec(param_1,DAT_1002dcf0,local_4c,param_3);
        }
        goto LAB_1000bd84;
      }
      DVar2 = 0x8009001a;
    }
  }
  else {
LAB_1000bd84:
    DVar2 = 0;
  }
LAB_1000bd94:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
LAB_1000bd9c:
  if (local_48.pbData != (BYTE *)0x0) {
    memset(local_48.pbData,0,local_48.cbData);
    LocalFree(local_48.pbData);
  }
  return DVar2;
}



/* 1000bdf0 FUN_1000bdf0 */

/* Boundary evidence: original MIPS .pdata 1000bdf0..1000be97. Semantic name remains unreviewed. */

HLOCAL FUN_1000bdf0(void)

{
  HLOCAL pvVar1;
  
  pvVar1 = LocalAlloc(0x40,0xc0);
  if (pvVar1 != (HLOCAL)0x0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 0xa0));
    *(undefined4 *)((int)pvVar1 + 0x14) = 0xffffffff;
    *(undefined4 *)((int)pvVar1 + 0x18) = 0xffffffff;
    *(undefined4 *)((int)pvVar1 + 0x9c) = 0xffffffff;
  }
  return pvVar1;
}



/* 1000be98 FUN_1000be98 */

/* Boundary evidence: original MIPS .pdata 1000be98..1000bebf. Semantic name remains unreviewed. */

bool FUN_1000be98(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3fffffe9;
}



/* 1000bec0 FUN_1000bec0 */

/* Boundary evidence: original MIPS .pdata 1000bec0..1000c343. Semantic name remains unreviewed. */

DWORD FUN_1000bec0(wchar_t *param_1,uint param_2,undefined4 *param_3,uint *param_4,uint param_5,
                  wchar_t *param_6)

{
  BOOL BVar1;
  size_t sVar2;
  HLOCAL pvVar3;
  int iVar4;
  LSTATUS LVar5;
  uint uBytes;
  DWORD DVar6;
  uint *puVar7;
  uint *puVar8;
  wchar_t *_Dest;
  uint uVar9;
  uint uVar10;
  SIZE_T uBytes_00;
  HKEY local_48;
  uint *local_44;
  undefined4 *local_40;
  undefined1 auStack_38 [12];
  uint local_2c;
  
  local_2c = DAT_1002da44;
  puVar8 = (uint *)0x0;
  _Dest = (wchar_t *)0x0;
  local_44 = param_4;
  local_40 = param_3;
  if ((param_2 & 0xfffff87) != 0) {
LAB_1000bf24:
    DVar6 = 0x80090009;
    goto LAB_1000c30c;
  }
  if (param_6 == (wchar_t *)0x0) {
    DVar6 = 0x54f;
    goto LAB_1000c30c;
  }
  uVar10 = param_2 & 0xf0000000;
  if (((uVar10 == 0xf0000000) && (param_1 != (wchar_t *)0x0)) && (*param_1 != L'\0'))
  goto LAB_1000bf24;
  uVar9 = 4;
  BVar1 = IsBadWritePtr(param_4,4);
  if (BVar1 != 0) {
    DVar6 = 0x57;
    goto LAB_1000c30c;
  }
  if (param_1 != (wchar_t *)0x0) {
    if (*param_1 == L'\0') goto LAB_1000bff8;
    sVar2 = wcslen(param_1);
    uBytes = (sVar2 + 1) * 2;
    if (((param_2 & 8) != 0) && (0x105 < uBytes)) {
      DVar6 = 0x8009001f;
      goto LAB_1000c30c;
    }
    _Dest = LocalAlloc(0x40,uBytes);
    if (_Dest != (wchar_t *)0x0) goto LAB_1000c024;
    goto LAB_1000c22c;
  }
  if (uVar10 != 0xf0000000) {
LAB_1000bff8:
    _Dest = LocalAlloc(0x40,0x40);
    if (_Dest == (wchar_t *)0x0) goto LAB_1000c22c;
    if ((param_2 & 0x20) == 0) {
      memcpy(_Dest,L"*Default*",0x14);
    }
    else {
      param_1 = L"DefaultKeys";
LAB_1000c024:
      wcscpy(_Dest,param_1);
    }
  }
  if (param_5 == 1) {
    iVar4 = _wcsicmp(L"Microsoft Base Cryptographic Provider v1.0",param_6);
    uVar9 = 0;
    if (iVar4 != 0) {
      uVar9 = 2;
    }
LAB_1000c0b0:
    if ((param_2 & 0x10) == 0) {
      puVar8 = FUN_1000bdf0();
      if (puVar8 != (uint *)0x0) {
        puVar8[1] = param_5;
        sVar2 = wcslen(param_6);
        uBytes_00 = (sVar2 + 1) * 2;
        pvVar3 = LocalAlloc(0x40,uBytes_00);
        if (pvVar3 != (HLOCAL)0x0) {
          memcpy(pvVar3,param_6,uBytes_00);
          puVar8[0x2f] = (uint)pvVar3;
          puVar8[0x2e] = uVar9;
          if (((param_2 & 0x40) != 0) || (uVar10 != 0)) {
            puVar8[0xf] = 1;
          }
          if ((uVar10 == 0xf0000000) ||
             (DVar6 = FUN_1000b7e0((int)puVar8,_Dest,param_2), DVar6 == 0)) {
            puVar7 = local_44;
            if ((param_2 & 0x20) != 0) {
              *puVar8 = *puVar8 | 0x20;
            }
            puVar8[4] = 0;
            DVar6 = FUN_100092e4(local_44,0,puVar8);
            if (DVar6 == 0) {
              puVar8[3] = *puVar7;
              if (((puVar8[0xc] == 0) || (puVar8[0x13] == 0)) ||
                 (iVar4 = FUN_1002b714((int *)(&PTR_DAT_1002d7f4)[puVar8[0x2e]],0xa400,
                                       *(uint *)(puVar8[0x13] + 8),(int *)0x0), iVar4 != 0)) {
                puVar7 = puVar8 + 0x16;
                if (*puVar7 == 0) {
                  pvVar3 = LocalAlloc(0x40,0x14);
                  *puVar7 = (uint)pvVar3;
                  if (pvVar3 == (HLOCAL)0x0) goto LAB_1000c22c;
                  puVar8[0xe] = 0x14;
                }
                DVar6 = FUN_10016a48(puVar8 + 0x27,(int *)puVar7,puVar8 + 0xe,auStack_38,10);
                if (DVar6 == 0) {
                  if ((puVar8[0x2e] != 1) &&
                     (LVar5 = RegOpenKeyExW((HKEY)0x80000002,
                                            L"Comm\\Security\\Crypto\\DESHashSessionKeyBackward",0,
                                            0x20019,&local_48), LVar5 == 0)) {
                    *puVar8 = *puVar8 | 4;
                    RegCloseKey(local_48);
                    local_48 = (HKEY)0x0;
                  }
                  if (uVar10 != 0) {
                    *puVar8 = *puVar8 | 0xf0000000;
                  }
                  DVar6 = 0;
                  *local_40 = puVar8;
                  puVar8 = (uint *)0x0;
                }
              }
              else {
                DVar6 = 0x8009001a;
              }
            }
          }
          goto LAB_1000c2ec;
        }
      }
LAB_1000c22c:
      DVar6 = 8;
    }
    else {
      DVar6 = FUN_1002b4fc(param_6,_Dest,param_2 & 0x20);
    }
  }
  else {
    if (param_5 == 2) goto LAB_1000c0b0;
    if (param_5 == 0xc) {
      uVar9 = 3;
      goto LAB_1000c0b0;
    }
    if (param_5 == 0x18) {
      uVar9 = 5;
      goto LAB_1000c0b0;
    }
    DVar6 = 0x80090014;
  }
LAB_1000c2ec:
  if (_Dest != (wchar_t *)0x0) {
    LocalFree(_Dest);
  }
  if (puVar8 != (uint *)0x0) {
    FUN_10009380(puVar8);
  }
LAB_1000c30c:
  FUN_1002bedc(local_2c);
  return DVar6;
}



/* 1000c344 CPAcquireContext */

/* Boundary evidence: original MIPS .pdata 1000c344..1000c3f7. Semantic name remains unreviewed. */

undefined4 CPAcquireContext(uint *param_1,wchar_t *param_2,uint param_3,uint *param_4)

{
  DWORD dwErrCode;
  wchar_t *pwVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_18 [2];
  
                    /* 0xc344  10  CPAcquireContext */
  uVar3 = 1;
  uVar2 = 1;
  pwVar1 = (wchar_t *)0x0;
  if (1 < *param_4) {
    uVar2 = param_4[3];
  }
  if (2 < *param_4) {
    pwVar1 = (wchar_t *)param_4[6];
  }
  dwErrCode = FUN_1000bec0(param_2,param_3,local_18,param_1,uVar2,pwVar1);
  if (dwErrCode == 0) {
    if ((param_3 & 0x10) == 0) {
      *(undefined4 *)(local_18[0] + 8) = 0;
    }
  }
  else {
    uVar3 = 0;
    SetLastError(dwErrCode);
  }
  return uVar3;
}



/* 1000c3f8 CPReleaseContext */

/* Boundary evidence: original MIPS .pdata 1000c3f8..1000c4ab. Semantic name remains unreviewed. */

undefined4 CPReleaseContext(uint param_1,int param_2)

{
  void *pvVar1;
  DWORD dwErrCode;
  HKEY hKey;
  
                    /* 0xc3f8  29  CPReleaseContext */
  pvVar1 = (void *)FUN_100091fc(param_1,0);
  if (pvVar1 == (void *)0x0) {
    dwErrCode = 0x80090001;
  }
  else {
    dwErrCode = 0;
    if (param_2 != 0) {
      dwErrCode = 0x80090009;
    }
    hKey = *(HKEY *)((int)pvVar1 + 0x78);
    FUN_10009380(pvVar1);
    if (hKey != (HKEY)0x0) {
      RegCloseKey(hKey);
    }
    FUN_1000935c(param_1);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 1000c4ac FUN_1000c4ac */

/* Boundary evidence: original MIPS .pdata 1000c4ac..1000c50b. Semantic name remains unreviewed. */

void FUN_1000c4ac(undefined4 *param_1,undefined4 param_2,int param_3)

{
  (**(code **)*param_1)(param_1,param_2,param_3);
  if ((param_1[4] == 0) && (param_3 != 0)) {
    param_1[3] = param_1[3] | 1;
  }
  return;
}



/* 1000c50c FUN_1000c50c */

/* Boundary evidence: original MIPS .pdata 1000c50c..1000c55b. Semantic name remains unreviewed. */

int FUN_1000c50c(int *param_1)

{
  if ((param_1[3] & 2U) == 0) {
    (**(code **)(*param_1 + 4))(param_1);
    param_1[3] = param_1[3] | 4;
  }
  return param_1[4];
}



/* 1000c55c FUN_1000c55c */

/* Boundary evidence: original MIPS .pdata 1000c55c..1000c60b. Semantic name remains unreviewed. */

undefined4 FUN_1000c55c(int *param_1,void *param_2,size_t param_3)

{
  void *_Dst;
  size_t sVar1;
  
  if (param_3 == 0xffffffff) {
    param_3 = (**(code **)(*param_1 + 0x18))();
  }
  else {
    sVar1 = (**(code **)(*param_1 + 0x18))(param_1);
    if (param_3 != sVar1) {
      return 0x80090004;
    }
  }
  _Dst = (void *)(**(code **)(*param_1 + 8))(param_1);
  memcpy(_Dst,param_2,param_3);
  param_1[3] = param_1[3] | 3;
  return 0;
}



/* 1000c60c FUN_1000c60c */

/* Boundary evidence: original MIPS .pdata 1000c60c..1000c64f. Semantic name remains unreviewed. */

undefined4 * FUN_1000c60c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000c650 FUN_1000c650 */

/* Boundary evidence: original MIPS .pdata 1000c650..1000c6cb. Semantic name remains unreviewed. */

undefined4 * FUN_1000c650(undefined4 *param_1,undefined4 param_2)

{
  param_1[2] = 0x8004;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_FUN_100013ec;
  memset(param_1 + 6,0,0x5c);
  memset(param_1 + 0x1d,0,0x14);
  A_SHAInit((int)(param_1 + 6));
  return param_1;
}



/* 1000c6cc FUN_1000c6cc */

/* Boundary evidence: original MIPS .pdata 1000c6cc..1000c6e7. Semantic name remains unreviewed. */

void FUN_1000c6cc(int param_1,void *param_2,uint param_3)

{
  A_SHAUpdate((void *)(param_1 + 0x18),param_2,param_3);
  return;
}



/* 1000c6e8 FUN_1000c6e8 */

/* Boundary evidence: original MIPS .pdata 1000c6e8..1000c707. Semantic name remains unreviewed. */

void FUN_1000c6e8(int param_1)

{
  A_SHAFinal((void *)(param_1 + 0x18),param_1 + 0x74);
  return;
}



/* 1000c718 FUN_1000c718 */

/* Boundary evidence: original MIPS .pdata 1000c718..1000c793. Semantic name remains unreviewed. */

undefined4 * FUN_1000c718(undefined4 *param_1,undefined4 param_2)

{
  param_1[2] = 0x800c;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_FUN_10001408;
  memset(param_1 + 6,0,0x68);
  memset(param_1 + 0x20,0,0x20);
  FUN_1001ed64(param_1 + 6);
  return param_1;
}



/* 1000c794 FUN_1000c794 */

/* Boundary evidence: original MIPS .pdata 1000c794..1000c7af. Semantic name remains unreviewed. */

void FUN_1000c794(int param_1,void *param_2,uint param_3)

{
  FUN_1001ff90((uint *)(param_1 + 0x18),param_2,param_3);
  return;
}



/* 1000c7b0 FUN_1000c7b0 */

/* Boundary evidence: original MIPS .pdata 1000c7b0..1000c7cf. Semantic name remains unreviewed. */

void FUN_1000c7b0(int param_1)

{
  FUN_100200ec((uint *)(param_1 + 0x18),param_1 + 0x80);
  return;
}



/* 1000c7e0 FUN_1000c7e0 */

/* Boundary evidence: original MIPS .pdata 1000c7e0..1000c86f. Semantic name remains unreviewed. */

undefined4 * FUN_1000c7e0(undefined4 *param_1,int param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[4] = *(undefined4 *)(param_2 + 0x10);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  *param_1 = &PTR_FUN_10001408;
  memcpy(param_1 + 6,(void *)(param_2 + 0x18),0x68);
  memcpy(param_1 + 0x20,(void *)(param_2 + 0x80),0x20);
  return param_1;
}



/* 1000c870 FUN_1000c870 */

/* Boundary evidence: original MIPS .pdata 1000c870..1000c8eb. Semantic name remains unreviewed. */

undefined4 * FUN_1000c870(undefined4 *param_1,undefined4 param_2)

{
  param_1[2] = 0x800d;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_FUN_10001424;
  memset(param_1 + 6,0,0xd0);
  memset(param_1 + 0x3a,0,0x30);
  FUN_10020228(param_1 + 6);
  return param_1;
}



/* 1000c8ec FUN_1000c8ec */

/* Boundary evidence: original MIPS .pdata 1000c8ec..1000c907. Semantic name remains unreviewed. */

void FUN_1000c8ec(int param_1,uint *param_2,uint param_3)

{
  FUN_10023dc8((uint *)(param_1 + 0x18),param_2,param_3);
  return;
}



/* 1000c908 FUN_1000c908 */

/* Boundary evidence: original MIPS .pdata 1000c908..1000c927. Semantic name remains unreviewed. */

void FUN_1000c908(int param_1)

{
  FUN_100241e0((uint *)(param_1 + 0x18),param_1 + 0xe8);
  return;
}



/* 1000c930 FUN_1000c930 */

/* Boundary evidence: original MIPS .pdata 1000c930..1000c9bf. Semantic name remains unreviewed. */

undefined4 * FUN_1000c930(undefined4 *param_1,int param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[4] = *(undefined4 *)(param_2 + 0x10);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  *param_1 = &PTR_FUN_10001424;
  memcpy(param_1 + 6,(void *)(param_2 + 0x18),0xd0);
  memcpy(param_1 + 0x3a,(void *)(param_2 + 0xe8),0x30);
  return param_1;
}



/* 1000c9c0 FUN_1000c9c0 */

/* Boundary evidence: original MIPS .pdata 1000c9c0..1000ca3b. Semantic name remains unreviewed. */

undefined4 * FUN_1000c9c0(undefined4 *param_1,undefined4 param_2)

{
  param_1[2] = 0x800e;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_FUN_10001440;
  memset(param_1 + 6,0,0xd0);
  memset(param_1 + 0x3a,0,0x40);
  FUN_100202fc(param_1 + 6);
  return param_1;
}



/* 1000ca3c FUN_1000ca3c */

/* Boundary evidence: original MIPS .pdata 1000ca3c..1000ca57. Semantic name remains unreviewed. */

void FUN_1000ca3c(int param_1,uint *param_2,uint param_3)

{
  FUN_10023dc8((uint *)(param_1 + 0x18),param_2,param_3);
  return;
}



/* 1000ca58 FUN_1000ca58 */

/* Boundary evidence: original MIPS .pdata 1000ca58..1000ca77. Semantic name remains unreviewed. */

void FUN_1000ca58(int param_1)

{
  FUN_10023f64((uint *)(param_1 + 0x18),param_1 + 0xe8);
  return;
}



/* 1000ca88 FUN_1000ca88 */

/* Boundary evidence: original MIPS .pdata 1000ca88..1000cb17. Semantic name remains unreviewed. */

undefined4 * FUN_1000ca88(undefined4 *param_1,int param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[4] = *(undefined4 *)(param_2 + 0x10);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  *param_1 = &PTR_FUN_10001440;
  memcpy(param_1 + 6,(void *)(param_2 + 0x18),0xd0);
  memcpy(param_1 + 0x3a,(void *)(param_2 + 0xe8),0x40);
  return param_1;
}



/* 1000cb18 FUN_1000cb18 */

/* Boundary evidence: original MIPS .pdata 1000cb18..1000cb33. Semantic name remains unreviewed. */

void FUN_1000cb18(int param_1,void *param_2,uint param_3)

{
  MD2Update((void *)(param_1 + 0x18),param_2,param_3);
  return;
}



/* 1000cb34 FUN_1000cb34 */

/* Boundary evidence: original MIPS .pdata 1000cb34..1000cb4f. Semantic name remains unreviewed. */

void FUN_1000cb34(int param_1)

{
  MD2Final((void *)(param_1 + 0x18));
  return;
}



/* 1000cb58 FUN_1000cb58 */

/* Boundary evidence: original MIPS .pdata 1000cb58..1000cba7. Semantic name remains unreviewed. */

undefined4 * FUN_1000cb58(undefined4 *param_1,undefined4 param_2)

{
  param_1[2] = 0x8002;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_FUN_10001478;
  MD4Init(param_1 + 6);
  return param_1;
}



/* 1000cba8 FUN_1000cba8 */

/* Boundary evidence: original MIPS .pdata 1000cba8..1000cbc3. Semantic name remains unreviewed. */

void FUN_1000cba8(int param_1,int *param_2,uint param_3)

{
  MD4Update((int *)(param_1 + 0x18),param_2,param_3);
  return;
}



/* 1000cbc4 FUN_1000cbc4 */

/* Boundary evidence: original MIPS .pdata 1000cbc4..1000cbdf. Semantic name remains unreviewed. */

void FUN_1000cbc4(int param_1)

{
  MD4Final((uint *)(param_1 + 0x18));
  return;
}



/* 1000cbe8 FUN_1000cbe8 */

/* Boundary evidence: original MIPS .pdata 1000cbe8..1000cc37. Semantic name remains unreviewed. */

undefined4 * FUN_1000cbe8(undefined4 *param_1,undefined4 param_2)

{
  param_1[2] = 0x8003;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_FUN_10001494;
  MD5Init(param_1 + 6);
  return param_1;
}



/* 1000cc38 FUN_1000cc38 */

/* Boundary evidence: original MIPS .pdata 1000cc38..1000cc53. Semantic name remains unreviewed. */

void FUN_1000cc38(int param_1,int *param_2,uint param_3)

{
  MD5Update((uint *)(param_1 + 0x18),param_2,param_3);
  return;
}



/* 1000cc54 FUN_1000cc54 */

/* Boundary evidence: original MIPS .pdata 1000cc54..1000cc6f. Semantic name remains unreviewed. */

void FUN_1000cc54(int param_1)

{
  MD5Final((uint *)(param_1 + 0x18));
  return;
}



/* 1000cc80 FUN_1000cc80 */

/* Boundary evidence: original MIPS .pdata 1000cc80..1000cd3f. Semantic name remains unreviewed. */

undefined4 * FUN_1000cc80(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  int local_10 [2];
  
  param_1[2] = 0x8005;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = param_3;
  *param_1 = &PTR_FUN_100014cc;
  param_1[0x11] = 0;
  if (param_3 == 0) {
    iVar1 = -0x7ff6fffd;
  }
  else {
    iVar1 = FUN_10009224(param_3,param_2,2,local_10);
    if (iVar1 == 0) {
      if (*(int *)(local_10[0] + 0x68) == 1) {
        if (*(int *)(local_10[0] + 0x8c) == 0) {
          iVar1 = FUN_10010c04(local_10[0]);
        }
      }
      else {
        iVar1 = -0x7ff6fffd;
      }
      param_1[0x11] = *(undefined4 *)(local_10[0] + 0x84);
    }
  }
  param_1[4] = iVar1;
  param_1[6] = 0;
  return param_1;
}



/* 1000cd40 FUN_1000cd40 */

/* Boundary evidence: original MIPS .pdata 1000cd40..1000cf1f. Semantic name remains unreviewed. */

void FUN_1000cd40(int param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *_Dst;
  uint *puVar4;
  uint uBytes;
  void *_Src;
  int local_30;
  size_t local_2c;
  
  puVar4 = (uint *)(param_1 + 0x18);
  _Dst = (uint *)0x0;
  if ((*(uint *)(param_1 + 0xc) & 4) == 0) {
    iVar3 = FUN_10009224(*(uint *)(param_1 + 0x14),*(int *)(param_1 + 4),2,&local_30);
    if (iVar3 == 0) {
      uVar2 = *puVar4;
      uVar1 = *(int *)(local_30 + 0x84) - uVar2;
      if (uVar1 < param_3) {
        memcpy((void *)((int)puVar4 + uVar2 + 0x10),param_2,uVar1);
        uVar1 = *puVar4;
        uVar2 = *(uint *)(local_30 + 0x84);
        uBytes = (uVar1 - uVar2) + param_3;
        *puVar4 = uVar2;
        _Src = (void *)((uVar2 - uVar1) + (int)param_2);
        iVar3 = FUN_1000f5ec(local_30,0,(uint *)(param_1 + 0x28),puVar4,0x10);
        if (iVar3 == 0) {
          *puVar4 = 0;
          uVar1 = *(uint *)(local_30 + 0x84);
          if (uVar1 == 0) {
            trap(0x1c00);
          }
          uVar2 = uBytes % uVar1;
          if (uBytes % uVar1 == 0) {
            uVar2 = uVar1;
          }
          _Dst = LocalAlloc(0x40,uBytes);
          if (_Dst == (uint *)0x0) {
            iVar3 = 8;
          }
          else {
            memcpy(_Dst,_Src,uBytes - uVar2);
            local_2c = uBytes - uVar2;
            iVar3 = FUN_1000f5ec(local_30,0,_Dst,&local_2c,uBytes);
            if (iVar3 == 0) {
              memcpy((uint *)(param_1 + 0x28),(void *)(local_2c + (int)_Src),uVar2);
              *puVar4 = uVar2;
            }
          }
        }
      }
      else {
        memcpy((void *)((int)puVar4 + uVar2 + 0x10),param_2,param_3);
        *puVar4 = *puVar4 + param_3;
        iVar3 = 0;
      }
    }
  }
  else {
    iVar3 = -0x7ff6fff4;
  }
  *(int *)(param_1 + 0x10) = iVar3;
  if (_Dst != (uint *)0x0) {
    LocalFree(_Dst);
  }
  return;
}



/* 1000cf20 FUN_1000cf20 */

/* Boundary evidence: original MIPS .pdata 1000cf20..1000d02f. Semantic name remains unreviewed. */

void FUN_1000cf20(int param_1)

{
  int iVar1;
  uint _Size;
  int local_48 [2];
  uint auStack_40 [8];
  uint local_20;
  
  local_20 = DAT_1002da44;
  iVar1 = FUN_10009224(*(uint *)(param_1 + 0x14),*(int *)(param_1 + 4),2,local_48);
  if (iVar1 != 0) goto LAB_1000d008;
  _Size = *(uint *)(param_1 + 0x18);
  if (_Size == 0) {
LAB_1000cfcc:
    if (*(uint *)(local_48[0] + 0x84) < 0x11) {
      *(uint *)(param_1 + 0x44) = *(uint *)(local_48[0] + 0x84);
      memcpy((void *)(param_1 + 0x34),(void *)(local_48[0] + 0x34),*(size_t *)(local_48[0] + 0x84));
      goto LAB_1000d008;
    }
  }
  else if (_Size < 0x21) {
    memset(auStack_40,0,0x20);
    memcpy(auStack_40,(void *)(param_1 + 0x28),_Size);
    iVar1 = FUN_1000f5ec(local_48[0],1,auStack_40,(uint *)(param_1 + 0x18),0x20);
    if (iVar1 != 0) goto LAB_1000d008;
    goto LAB_1000cfcc;
  }
  iVar1 = -0x7ff6ffe0;
LAB_1000d008:
  *(int *)(param_1 + 0x10) = iVar1;
  FUN_1002bedc(local_20);
  return;
}



/* 1000d038 FUN_1000d038 */

/* Boundary evidence: original MIPS .pdata 1000d038..1000d09b. Semantic name remains unreviewed. */

void FUN_1000d038(int *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  undefined4 auStack_18 [2];
  
  iVar1 = FUN_10009224(param_1[5],param_1[1],2,auStack_18);
  if (iVar1 == 0) {
    FUN_1000c55c(param_1,param_2,param_3);
  }
  return;
}



/* 1000d0a4 FUN_1000d0a4 */

/* Boundary evidence: original MIPS .pdata 1000d0a4..1000d14b. Semantic name remains unreviewed. */

undefined4 * FUN_1000d0a4(undefined4 *param_1,int param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[4] = *(undefined4 *)(param_2 + 0x10);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  *param_1 = &PTR_FUN_100014cc;
  memcpy(param_1 + 6,(void *)(param_2 + 0x18),0x1c);
  param_1[0xd] = *(undefined4 *)(param_2 + 0x34);
  param_1[0xe] = *(undefined4 *)(param_2 + 0x38);
  param_1[0xf] = *(undefined4 *)(param_2 + 0x3c);
  param_1[0x10] = *(undefined4 *)(param_2 + 0x40);
  param_1[0x11] = *(undefined4 *)(param_2 + 0x44);
  return param_1;
}



/* 1000d14c FUN_1000d14c */

/* Boundary evidence: original MIPS .pdata 1000d14c..1000d1cf. Semantic name remains unreviewed. */

undefined4 * FUN_1000d14c(undefined4 *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 auStack_10 [2];
  
  param_1[2] = 0x8009;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = param_3;
  *param_1 = &PTR_FUN_100014e8;
  param_1[8] = 0;
  param_1[6] = 0;
  param_1[0x49] = 0;
  param_1[7] = 0;
  param_1[0x5a] = 0;
  if (param_3 == 0) {
    uVar1 = 0x80090003;
  }
  else {
    uVar1 = FUN_10009224(param_3,param_2,2,auStack_10);
  }
  param_1[4] = uVar1;
  return param_1;
}



/* 1000d1d0 FUN_1000d1d0 */

/* Boundary evidence: original MIPS .pdata 1000d1d0..1000d21f. Semantic name remains unreviewed. */

void FUN_1000d1d0(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[7];
  *param_1 = &PTR_FUN_100014e8;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
  }
  *param_1 = &PTR_LAB_100013d0;
  return;
}



/* 1000d23c FUN_1000d23c */

/* Boundary evidence: original MIPS .pdata 1000d23c..1000d287. Semantic name remains unreviewed. */

undefined4 * FUN_1000d23c(undefined4 *param_1,uint param_2)

{
  FUN_1000d1d0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000d288 FUN_1000d288 */

/* Boundary evidence: original MIPS .pdata 1000d288..1000d34f. Semantic name remains unreviewed. */

undefined4 * FUN_1000d288(undefined4 *param_1,int param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[4] = *(undefined4 *)(param_2 + 0x10);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  *param_1 = &PTR_FUN_100014e8;
  param_1[6] = *(undefined4 *)(param_2 + 0x18);
  param_1[7] = *(undefined4 *)(param_2 + 0x1c);
  param_1[8] = *(undefined4 *)(param_2 + 0x20);
  memcpy(param_1 + 9,(void *)(param_2 + 0x24),0x80);
  memcpy(param_1 + 0x29,(void *)(param_2 + 0xa4),0x80);
  param_1[0x49] = *(undefined4 *)(param_2 + 0x124);
  memcpy(param_1 + 0x4a,(void *)(param_2 + 0x128),0x40);
  param_1[0x5a] = *(undefined4 *)(param_2 + 0x168);
  return param_1;
}



/* 1000d350 FUN_1000d350 */

undefined4 FUN_1000d350(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((*(int *)(param_1 + 4) == 0xc) && ((param_2 == 0x8001 || (param_2 == 0x8002)))) ||
     ((*(int *)(param_1 + 4) != 0x18 &&
      (((param_2 == 0x800c || (param_2 == 0x800d)) || (param_2 == 0x800e)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 1000d3bc FUN_1000d3bc */

/* Boundary evidence: original MIPS .pdata 1000d3bc..1000d423. Semantic name remains unreviewed. */

undefined4 FUN_1000d3bc(uint param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_100091fc(param_1,1);
  if (iVar1 == 0) {
    uVar2 = 0x80090002;
  }
  else if (*(int *)(iVar1 + 4) == param_2) {
    *param_3 = iVar1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80090001;
  }
  return uVar2;
}



/* 1000d424 FUN_1000d424 */

/* Boundary evidence: original MIPS .pdata 1000d424..1000d637. Semantic name remains unreviewed. */

undefined4 FUN_1000d424(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x8001) {
    uVar2 = 0x4c;
    puVar1 = operator_new(0x4c);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = param_3;
      puVar1[2] = 0x8001;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      *puVar1 = &PTR_FUN_1000145c;
      memset(puVar1 + 6,0,0x34);
      goto LAB_1000d5f4;
    }
  }
  else if (param_1 == 0x8002) {
    uVar2 = 0x80;
    puVar1 = operator_new(0x80);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = FUN_1000cb58(puVar1,param_3);
      goto LAB_1000d5f4;
    }
  }
  else if (param_1 == 0x8003) {
    uVar2 = 0x80;
    puVar1 = operator_new(0x80);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = FUN_1000cbe8(puVar1,param_3);
      goto LAB_1000d5f4;
    }
  }
  else if (param_1 == 0x8004) {
    uVar2 = 0x88;
    puVar1 = operator_new(0x88);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = FUN_1000c650(puVar1,param_3);
      goto LAB_1000d5f4;
    }
  }
  else if (param_1 == 0x800c) {
    uVar2 = 0xa0;
    puVar1 = operator_new(0xa0);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = FUN_1000c718(puVar1,param_3);
      goto LAB_1000d5f4;
    }
  }
  else if (param_1 == 0x800d) {
    uVar2 = 0x118;
    puVar1 = operator_new(0x118);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = FUN_1000c870(puVar1,param_3);
      goto LAB_1000d5f4;
    }
  }
  else {
    if (param_1 != 0x800e) {
      return 0x80090008;
    }
    uVar2 = 0x128;
    puVar1 = operator_new(0x128);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = FUN_1000c9c0(puVar1,param_3);
      goto LAB_1000d5f4;
    }
  }
  puVar1 = (undefined4 *)0x0;
LAB_1000d5f4:
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 8;
  }
  else {
    *param_2 = puVar1;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = uVar2;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 1000d638 CPCreateHash */

/* Boundary evidence: original MIPS .pdata 1000d638..1000d843. Semantic name remains unreviewed. */

undefined4 CPCreateHash(uint param_1,int param_2,uint param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  DWORD dwErrCode;
  int *local_28 [2];
  
                    /* 0xd638  11  CPCreateHash */
  piVar3 = (int *)0x0;
  local_28[0] = (int *)0x0;
  if (param_4 != 0) {
    dwErrCode = 0x80090009;
    goto LAB_1000d7f0;
  }
  iVar1 = FUN_100091fc(param_1,0);
  if (iVar1 == 0) {
    dwErrCode = 0x80090001;
    goto LAB_1000d7f0;
  }
  iVar1 = FUN_1000d350(iVar1,param_2);
  if (iVar1 == 0) {
    dwErrCode = 0x80090008;
    goto LAB_1000d7f0;
  }
  if (param_2 == 0x8005) {
    puVar2 = operator_new(0x48);
    if (puVar2 == (undefined4 *)0x0) {
LAB_1000d7a8:
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_1000cc80(puVar2,param_1,param_3);
    }
  }
  else if (param_2 == 0x8008) {
    piVar3 = operator_new(0x3c);
    if (piVar3 == (int *)0x0) goto LAB_1000d7a8;
    piVar3[1] = param_1;
    piVar3[2] = 0x8008;
    piVar3[3] = 0;
    piVar3[4] = 0;
    piVar3[5] = 0;
    *piVar3 = (int)&PTR_FUN_100014b0;
  }
  else if (param_2 == 0x8009) {
    puVar2 = operator_new(0x16c);
    if (puVar2 == (undefined4 *)0x0) goto LAB_1000d7a8;
    piVar3 = FUN_1000d14c(puVar2,param_1,param_3);
  }
  else {
    if (param_3 != 0) {
      dwErrCode = 0x80090003;
      goto LAB_1000d7f0;
    }
    dwErrCode = FUN_1000d424(param_2,local_28,param_1,(undefined4 *)0x0);
    piVar3 = local_28[0];
    if (dwErrCode != 0) goto LAB_1000d7f0;
  }
  if (piVar3 == (int *)0x0) {
    dwErrCode = 8;
  }
  else {
    dwErrCode = piVar3[4];
    if ((dwErrCode == 0) && (dwErrCode = FUN_100092e4(param_5,1,piVar3), dwErrCode == 0)) {
      return 1;
    }
  }
LAB_1000d7f0:
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0xc))(piVar3,1);
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 1000d844 FUN_1000d844 */

/* Boundary evidence: original MIPS .pdata 1000d844..1000d913. Semantic name remains unreviewed. */

undefined4 FUN_1000d844(int param_1,int *param_2,uint *param_3,uint param_4)

{
  HLOCAL _Dst;
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uBytes;
  
  *param_2 = 0;
  uBytes = *(uint *)(param_1 + 0xc);
  _Dst = LocalAlloc(0x40,uBytes);
  *param_2 = (int)_Dst;
  if (_Dst == (HLOCAL)0x0) {
    uVar1 = 8;
  }
  else {
    if ((param_4 & 1) == 0) {
      uVar4 = 0;
      if (uBytes != 0) {
        do {
          iVar2 = uBytes - uVar4;
          puVar3 = (undefined1 *)(*param_2 + uVar4);
          uVar4 = uVar4 + 1;
          *puVar3 = *(undefined1 *)(iVar2 + *(int *)(param_1 + 0x10) + -1);
        } while (uVar4 < uBytes);
      }
    }
    else {
      memcpy(_Dst,*(void **)(param_1 + 0x10),uBytes);
    }
    *param_3 = uBytes;
    uVar1 = 0;
  }
  return uVar1;
}



/* 1000d914 FUN_1000d914 */

/* Boundary evidence: original MIPS .pdata 1000d914..1000da0f. Semantic name remains unreviewed. */

undefined4 FUN_1000d914(int param_1,undefined4 param_2,int param_3,void *param_4,size_t param_5)

{
  int *piVar1;
  int iVar2;
  size_t sVar3;
  void *_Buf1;
  undefined4 uVar4;
  int *local_20 [2];
  
  local_20[0] = (int *)0x0;
  uVar4 = 0;
  iVar2 = FUN_1000d424(param_1,local_20,0,(undefined4 *)0x0);
  piVar1 = local_20[0];
  if (iVar2 == 0) {
    iVar2 = FUN_1000c4ac(local_20[0],param_2,param_3);
    if ((iVar2 == 0) && (iVar2 = FUN_1000c50c(piVar1), iVar2 == 0)) {
      sVar3 = (**(code **)(*piVar1 + 0x18))(piVar1);
      if (sVar3 == param_5) {
        _Buf1 = (void *)(**(code **)(*piVar1 + 8))(piVar1);
        iVar2 = memcmp(_Buf1,param_4,param_5);
        if (iVar2 == 0) {
          uVar4 = 1;
        }
      }
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(piVar1,1);
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



/* 1000da10 CPHashData */

/* Boundary evidence: original MIPS .pdata 1000da10..1000db23. Semantic name remains unreviewed. */

undefined4 CPHashData(uint param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  DWORD dwErrCode;
  int iVar1;
  undefined4 *local_20 [2];
  
                    /* 0xda10  26  CPHashData */
  local_20[0] = (undefined4 *)0x0;
  if ((param_5 & 0xfffffffe) == 0) {
    iVar1 = FUN_100091fc(param_1,0);
    if (iVar1 == 0) {
      dwErrCode = 0x80090001;
    }
    else {
      if (param_4 == 0) {
        return 1;
      }
      if (param_3 == 0) {
        dwErrCode = 0x80090005;
      }
      else {
        dwErrCode = FUN_1000d3bc(param_2,param_1,(int *)local_20);
        if (dwErrCode == 0) {
          if ((local_20[0][3] & 4) == 0) {
            dwErrCode = FUN_1000c4ac(local_20[0],param_3,param_4);
            if (dwErrCode == 0) {
              return 1;
            }
          }
          else {
            dwErrCode = 0x8009000c;
          }
        }
      }
    }
  }
  else {
    dwErrCode = 0x80090009;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 1000db24 CPHashSessionKey */

/* Boundary evidence: original MIPS .pdata 1000db24..1000dd47. Semantic name remains unreviewed. */

int CPHashSessionKey(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  DWORD dwErrCode;
  HLOCAL hMem;
  int iVar4;
  HLOCAL local_30;
  int local_2c;
  undefined4 *local_28 [2];
  
                    /* 0xdb24  27  CPHashSessionKey */
  hMem = (HLOCAL)0x0;
  local_30 = (HLOCAL)0x0;
  if ((param_4 & 0xfffffffe) == 0) {
    puVar2 = (uint *)FUN_100091fc(param_1,0);
    if (puVar2 == (uint *)0x0) {
      dwErrCode = 0x80090001;
    }
    else {
      dwErrCode = FUN_1000d3bc(param_2,param_1,(int *)local_28);
      puVar1 = local_28[0];
      if (dwErrCode == 0) {
        if (local_28[0][2] == 0x8005) {
          dwErrCode = 0x80090008;
        }
        else if ((local_28[0][3] & 2) == 0) {
          dwErrCode = FUN_10009224(param_3,param_1,2,&local_2c);
          if (dwErrCode == 0) {
            iVar4 = 1;
            iVar3 = FUN_10010610((int)puVar2,local_2c,1);
            if (iVar3 == 0) {
              dwErrCode = 0x80090003;
            }
            else {
              iVar3 = *(int *)(local_2c + 4);
              if ((((iVar3 == 0x6601) || (iVar3 == 0x6603)) || (iVar3 == 0x6609)) &&
                 ((puVar2[1] != 0xc && ((puVar2[0x2e] == 1 || ((*puVar2 & 4) == 0)))))) {
                FUN_1001e884(*(int *)(local_2c + 0x10),*(uint *)(local_2c + 0xc));
              }
              dwErrCode = FUN_1000d844(local_2c,(int *)&local_30,(uint *)local_28,param_4);
              hMem = local_30;
              if (dwErrCode == 0) {
                if ((puVar1[3] & 4) != 0) goto LAB_1000dbec;
                dwErrCode = FUN_1000c4ac(puVar1,local_30,(int)local_28[0]);
                if (dwErrCode == 0) goto LAB_1000dcf4;
              }
            }
          }
        }
        else {
LAB_1000dbec:
          dwErrCode = 0x8009000c;
        }
      }
    }
  }
  else {
    dwErrCode = 0x80090009;
  }
  iVar4 = 0;
LAB_1000dcf4:
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
  if (iVar4 == 0) {
    SetLastError(dwErrCode);
  }
  return iVar4;
}



/* 1000dd48 CPGetHashParam */

/* Boundary evidence: original MIPS .pdata 1000dd48..1000dfc3. Semantic name remains unreviewed. */

undefined4
CPGetHashParam(uint param_1,uint param_2,int param_3,uint *param_4,uint *param_5,int param_6)

{
  DWORD dwErrCode;
  int iVar1;
  void *_Src;
  uint uVar2;
  uint uVar3;
  uint _Size;
  int *local_20 [2];
  
                    /* 0xdd48  22  CPGetHashParam */
  if (param_6 == 0) {
    iVar1 = FUN_100091fc(param_1,0);
    if (iVar1 == 0) {
      dwErrCode = 0x80090001;
    }
    else if (param_5 == (uint *)0x0) {
      dwErrCode = 0x57;
    }
    else {
      dwErrCode = FUN_1000d3bc(param_2,param_1,(int *)local_20);
      if (dwErrCode == 0) {
        if (param_3 == 1) {
          if ((param_4 != (uint *)0x0) && (3 < *param_5)) {
            *param_4 = local_20[0][2];
            *param_5 = 4;
            return 1;
          }
          *param_5 = 4;
        }
        else {
          if (param_3 == 2) {
            _Size = (**(code **)(*local_20[0] + 0x18))(local_20[0]);
            if ((param_4 != (uint *)0x0) && (_Size <= *param_5)) {
              if ((local_20[0][2] == 0x8008) && ((local_20[0][3] & 2U) == 0)) {
                dwErrCode = 0x8009000c;
              }
              else if (((local_20[0][3] & 4U) != 0) ||
                      (dwErrCode = FUN_1000c50c(local_20[0]), dwErrCode == 0)) {
                _Src = (void *)(**(code **)(*local_20[0] + 8))(local_20[0]);
                memcpy(param_4,_Src,_Size);
                goto LAB_1000dea0;
              }
              goto LAB_1000df8c;
            }
          }
          else {
            _Size = 4;
            if (param_3 == 4) {
              if ((param_4 != (uint *)0x0) && (3 < *param_5)) {
                uVar2 = (**(code **)(*local_20[0] + 0x18))();
                *param_4 = uVar2;
LAB_1000dea0:
                *param_5 = _Size;
                return 1;
              }
            }
            else {
              if (param_3 != 0x11) {
                dwErrCode = 0x8009000a;
                goto LAB_1000df8c;
              }
              if ((param_4 != (uint *)0x0) && (3 < *param_5)) {
                uVar3 = local_20[0][3];
                uVar2 = (uint)((uVar3 & 2) != 0);
                if ((uVar3 & 1) != 0) {
                  uVar2 = uVar2 | 2;
                }
                if ((uVar3 & 4) != 0) {
                  uVar2 = uVar2 | 4;
                }
                *param_4 = uVar2;
                goto LAB_1000dea0;
              }
            }
          }
          *param_5 = _Size;
        }
        if (param_4 == (uint *)0x0) {
          return 1;
        }
        dwErrCode = 0xea;
      }
    }
  }
  else {
    dwErrCode = 0x80090009;
  }
LAB_1000df8c:
  SetLastError(dwErrCode);
  return 0;
}



/* 1000dfc4 CPDuplicateHash */

/* Boundary evidence: original MIPS .pdata 1000dfc4..1000e073. Semantic name remains unreviewed. */

undefined4 CPDuplicateHash(int param_1,uint param_2,int param_3,int param_4,uint *param_5)

{
  DWORD dwErrCode;
  int iVar1;
  int *local_10 [2];
  
                    /* 0xdfc4  16  CPDuplicateHash */
  if (param_3 == 0) {
    if (param_4 == 0) {
      dwErrCode = FUN_1000d3bc(param_2,param_1,(int *)local_10);
      if (dwErrCode == 0) {
        iVar1 = (**(code **)(*local_10[0] + 0x10))();
        if (iVar1 != 0) {
          FUN_100092e4(param_5,1,iVar1);
          return 1;
        }
        dwErrCode = 0x8009000e;
      }
    }
    else {
      dwErrCode = 0x80090009;
    }
  }
  else {
    dwErrCode = 0x57;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 1000e074 CPDestroyHash */

/* Boundary evidence: original MIPS .pdata 1000e074..1000e117. Semantic name remains unreviewed. */

undefined4 CPDestroyHash(uint param_1,uint param_2)

{
  int iVar1;
  DWORD dwErrCode;
  int *local_18 [2];
  
                    /* 0xe074  14  CPDestroyHash */
  iVar1 = FUN_100091fc(param_1,0);
  if (iVar1 == 0) {
    dwErrCode = 0x80090001;
  }
  else {
    dwErrCode = FUN_1000d3bc(param_2,param_1,(int *)local_18);
    if (dwErrCode == 0) {
      FUN_1000935c(param_2);
      if (local_18[0] == (int *)0x0) {
        return 1;
      }
      (**(code **)(*local_18[0] + 0xc))(local_18[0],1);
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 1000e118 FUN_1000e118 */

/* Boundary evidence: original MIPS .pdata 1000e118..1000e15b. Semantic name remains unreviewed. */

undefined4 * FUN_1000e118(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e15c FUN_1000e15c */

/* Boundary evidence: original MIPS .pdata 1000e15c..1000e203. Semantic name remains unreviewed. */

undefined4 * FUN_1000e15c(undefined4 *param_1,int param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  param_1[4] = *(undefined4 *)(param_2 + 0x10);
  param_1[5] = *(undefined4 *)(param_2 + 0x14);
  *param_1 = &PTR_FUN_100013ec;
  memcpy(param_1 + 6,(void *)(param_2 + 0x18),0x5c);
  param_1[0x1d] = *(undefined4 *)(param_2 + 0x74);
  param_1[0x1e] = *(undefined4 *)(param_2 + 0x78);
  param_1[0x1f] = *(undefined4 *)(param_2 + 0x7c);
  param_1[0x20] = *(undefined4 *)(param_2 + 0x80);
  param_1[0x21] = *(undefined4 *)(param_2 + 0x84);
  return param_1;
}



/* 1000e204 FUN_1000e204 */

/* Boundary evidence: original MIPS .pdata 1000e204..1000e24b. Semantic name remains unreviewed. */

undefined4 * FUN_1000e204(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xa0);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_1000c7e0(puVar1,param_1);
  }
  return puVar1;
}



/* 1000e24c FUN_1000e24c */

/* Boundary evidence: original MIPS .pdata 1000e24c..1000e28f. Semantic name remains unreviewed. */

undefined4 * FUN_1000e24c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e290 FUN_1000e290 */

/* Boundary evidence: original MIPS .pdata 1000e290..1000e2d7. Semantic name remains unreviewed. */

undefined4 * FUN_1000e290(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x118);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_1000c930(puVar1,param_1);
  }
  return puVar1;
}



/* 1000e2d8 FUN_1000e2d8 */

/* Boundary evidence: original MIPS .pdata 1000e2d8..1000e31b. Semantic name remains unreviewed. */

undefined4 * FUN_1000e2d8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e31c FUN_1000e31c */

/* Boundary evidence: original MIPS .pdata 1000e31c..1000e363. Semantic name remains unreviewed. */

undefined4 * FUN_1000e31c(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x128);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_1000ca88(puVar1,param_1);
  }
  return puVar1;
}



/* 1000e364 FUN_1000e364 */

/* Boundary evidence: original MIPS .pdata 1000e364..1000e3a7. Semantic name remains unreviewed. */

undefined4 * FUN_1000e364(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e3a8 FUN_1000e3a8 */

/* Boundary evidence: original MIPS .pdata 1000e3a8..1000e443. Semantic name remains unreviewed. */

undefined4 * FUN_1000e3a8(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x4c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_LAB_100013d0;
    puVar1[1] = *(undefined4 *)(param_1 + 4);
    puVar1[2] = *(undefined4 *)(param_1 + 8);
    puVar1[3] = *(undefined4 *)(param_1 + 0xc);
    puVar1[4] = *(undefined4 *)(param_1 + 0x10);
    puVar1[5] = *(undefined4 *)(param_1 + 0x14);
    *puVar1 = &PTR_FUN_1000145c;
    memcpy(puVar1 + 6,(void *)(param_1 + 0x18),0x34);
  }
  return puVar1;
}



/* 1000e444 FUN_1000e444 */

/* Boundary evidence: original MIPS .pdata 1000e444..1000e487. Semantic name remains unreviewed. */

undefined4 * FUN_1000e444(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e488 FUN_1000e488 */

/* Boundary evidence: original MIPS .pdata 1000e488..1000e523. Semantic name remains unreviewed. */

undefined4 * FUN_1000e488(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x80);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_LAB_100013d0;
    puVar1[1] = *(undefined4 *)(param_1 + 4);
    puVar1[2] = *(undefined4 *)(param_1 + 8);
    puVar1[3] = *(undefined4 *)(param_1 + 0xc);
    puVar1[4] = *(undefined4 *)(param_1 + 0x10);
    puVar1[5] = *(undefined4 *)(param_1 + 0x14);
    *puVar1 = &PTR_FUN_10001478;
    memcpy(puVar1 + 6,(void *)(param_1 + 0x18),0x68);
  }
  return puVar1;
}



/* 1000e524 FUN_1000e524 */

/* Boundary evidence: original MIPS .pdata 1000e524..1000e567. Semantic name remains unreviewed. */

undefined4 * FUN_1000e524(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e568 FUN_1000e568 */

/* Boundary evidence: original MIPS .pdata 1000e568..1000e603. Semantic name remains unreviewed. */

undefined4 * FUN_1000e568(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x80);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_LAB_100013d0;
    puVar1[1] = *(undefined4 *)(param_1 + 4);
    puVar1[2] = *(undefined4 *)(param_1 + 8);
    puVar1[3] = *(undefined4 *)(param_1 + 0xc);
    puVar1[4] = *(undefined4 *)(param_1 + 0x10);
    puVar1[5] = *(undefined4 *)(param_1 + 0x14);
    *puVar1 = &PTR_FUN_10001494;
    memcpy(puVar1 + 6,(void *)(param_1 + 0x18),0x68);
  }
  return puVar1;
}



/* 1000e604 FUN_1000e604 */

/* Boundary evidence: original MIPS .pdata 1000e604..1000e647. Semantic name remains unreviewed. */

undefined4 * FUN_1000e604(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e648 FUN_1000e648 */

/* Boundary evidence: original MIPS .pdata 1000e648..1000e6e3. Semantic name remains unreviewed. */

undefined4 * FUN_1000e648(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x3c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_LAB_100013d0;
    puVar1[1] = *(undefined4 *)(param_1 + 4);
    puVar1[2] = *(undefined4 *)(param_1 + 8);
    puVar1[3] = *(undefined4 *)(param_1 + 0xc);
    puVar1[4] = *(undefined4 *)(param_1 + 0x10);
    puVar1[5] = *(undefined4 *)(param_1 + 0x14);
    *puVar1 = &PTR_FUN_100014b0;
    memcpy(puVar1 + 6,(void *)(param_1 + 0x18),0x24);
  }
  return puVar1;
}



/* 1000e6e4 FUN_1000e6e4 */

/* Boundary evidence: original MIPS .pdata 1000e6e4..1000e727. Semantic name remains unreviewed. */

undefined4 * FUN_1000e6e4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e728 FUN_1000e728 */

/* Boundary evidence: original MIPS .pdata 1000e728..1000e76f. Semantic name remains unreviewed. */

undefined4 * FUN_1000e728(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x48);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_1000d0a4(puVar1,param_1);
  }
  return puVar1;
}



/* 1000e770 FUN_1000e770 */

/* Boundary evidence: original MIPS .pdata 1000e770..1000e7b3. Semantic name remains unreviewed. */

undefined4 * FUN_1000e770(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_100013d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 1000e7b4 FUN_1000e7b4 */

/* Boundary evidence: original MIPS .pdata 1000e7b4..1000e84f. Semantic name remains unreviewed. */

int * FUN_1000e7b4(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = operator_new(0x16c);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_1000d288(puVar1,param_1);
  }
  if ((piVar2 != (int *)0x0) && (*(int **)(param_1 + 0x1c) != (int *)0x0)) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x10))();
    piVar2[7] = iVar3;
    if (iVar3 == 0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
      piVar2 = (int *)0x0;
    }
  }
  return piVar2;
}



/* 1000e850 FUN_1000e850 */

/* Boundary evidence: original MIPS .pdata 1000e850..1000e987. Semantic name remains unreviewed. */

int FUN_1000e850(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  
  if (param_2 == 0x8001) {
    uVar4 = 0x10;
  }
  else {
    if (((param_2 == 0x8002) || (param_2 - 0x8002U < 3)) || (param_2 == 0x800c)) {
      *(undefined4 *)(param_1 + 0x124) = 0x40;
      goto LAB_1000e8d8;
    }
    if ((param_2 != 0x800d) && (1 < param_2 - 0x800dU)) {
      return -0x7ff6fff8;
    }
    uVar4 = 0x80;
  }
  *(undefined4 *)(param_1 + 0x124) = uVar4;
LAB_1000e8d8:
  *(int *)(param_1 + 0x18) = param_2;
  if (*(uint *)(param_1 + 0x124) < 0x81) {
    memset((void *)(param_1 + 0x24),0x36,*(uint *)(param_1 + 0x124));
    memset((void *)(param_1 + 0xa4),0x5c,*(size_t *)(param_1 + 0x124));
    piVar5 = (int *)(param_1 + 0x1c);
    piVar3 = (int *)*piVar5;
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0xc))(piVar3,1);
      *piVar5 = 0;
    }
    iVar1 = FUN_1000d424(*(int *)(param_1 + 0x18),piVar5,0,(undefined4 *)0x0);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar2 = (**(code **)(*(int *)*piVar5 + 0x18))();
    *(uint *)(param_1 + 0x168) = uVar2;
    if (uVar2 < 0x41) {
      return 0;
    }
  }
  return 0x54f;
}



/* 1000e988 FUN_1000e988 */

/* Boundary evidence: original MIPS .pdata 1000e988..1000eb9f. Semantic name remains unreviewed. */

void FUN_1000e988(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  int local_20;
  int *local_1c;
  
  if ((*(uint *)(param_1 + 0x20) & 1) == 0) {
    iVar1 = FUN_10009224(*(uint *)(param_1 + 0x14),*(int *)(param_1 + 4),2,&local_20);
    if (iVar1 != 0) goto LAB_1000eb7c;
    if (*(uint *)(local_20 + 0xc) <= *(uint *)(param_1 + 0x124)) {
      uVar2 = 0;
      if (*(uint *)(local_20 + 0xc) != 0) {
        do {
          pbVar3 = (byte *)(param_1 + 0x24 + uVar2);
          *pbVar3 = *(byte *)(*(int *)(local_20 + 0x10) + uVar2) ^ *pbVar3;
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint *)(local_20 + 0xc));
      }
LAB_1000eb24:
      iVar1 = FUN_1000c4ac(*(undefined4 **)(param_1 + 0x1c),(void *)(param_1 + 0x24),
                           *(int *)(param_1 + 0x124));
      if (iVar1 != 0) goto LAB_1000eb7c;
      memset((void *)(param_1 + 0x24),0x36,*(size_t *)(param_1 + 0x124));
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 1;
      goto LAB_1000eb60;
    }
    iVar1 = FUN_1000d424(*(int *)(param_1 + 0x18),&local_1c,0,(undefined4 *)0x0);
    if (iVar1 != 0) goto LAB_1000eb7c;
    FUN_1000c4ac(local_1c,*(undefined4 *)(local_20 + 0x10),*(int *)(local_20 + 0xc));
    iVar1 = FUN_1000c50c(local_1c);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_1c + 8))(local_1c);
      uVar2 = (**(code **)(*local_1c + 0x18))(local_1c);
      if (*(uint *)(param_1 + 0x124) < uVar2) {
        uVar2 = *(uint *)(param_1 + 0x124);
      }
      uVar5 = 0;
      if (uVar2 != 0) {
        do {
          pbVar4 = (byte *)(param_1 + 0x24 + uVar5);
          pbVar3 = (byte *)(uVar5 + iVar1);
          uVar5 = uVar5 + 1;
          *pbVar4 = *pbVar3 ^ *pbVar4;
        } while (uVar5 < uVar2);
      }
      (**(code **)(*local_1c + 0xc))(local_1c,1);
      goto LAB_1000eb24;
    }
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 0xc))(local_1c,1);
    }
  }
  else {
LAB_1000eb60:
    iVar1 = FUN_1000c4ac(*(undefined4 **)(param_1 + 0x1c),param_2,param_3);
  }
  if (iVar1 == 0) {
    return;
  }
LAB_1000eb7c:
  *(int *)(param_1 + 0x10) = iVar1;
  return;
}



/* 1000eba0 FUN_1000eba0 */

/* Boundary evidence: original MIPS .pdata 1000eba0..1000edeb. Semantic name remains unreviewed. */

void FUN_1000eba0(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  void *_Src;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  int *local_20;
  int local_1c;
  
  iVar2 = FUN_1000c50c(*(int **)(param_1 + 0x1c));
  if ((iVar2 == 0) &&
     (iVar2 = FUN_10009224(*(uint *)(param_1 + 0x14),*(int *)(param_1 + 4),2,&local_1c), iVar2 == 0)
     ) {
    if (*(uint *)(param_1 + 0x124) < *(uint *)(local_1c + 0xc)) {
      iVar2 = FUN_1000d424(*(int *)(param_1 + 0x18),&local_20,0,(undefined4 *)0x0);
      piVar1 = local_20;
      if (iVar2 != 0) goto LAB_1000edcc;
      FUN_1000c4ac(local_20,*(undefined4 *)(local_1c + 0x10),*(int *)(local_1c + 0xc));
      FUN_1000c50c(piVar1);
      iVar2 = (**(code **)(*piVar1 + 8))(piVar1);
      uVar3 = (**(code **)(*piVar1 + 0x18))(piVar1);
      if (*(uint *)(param_1 + 0x124) < uVar3) {
        uVar3 = *(uint *)(param_1 + 0x124);
      }
      uVar7 = 0;
      if (uVar3 != 0) {
        do {
          pbVar6 = (byte *)(param_1 + 0xa4 + uVar7);
          pbVar5 = (byte *)(uVar7 + iVar2);
          uVar7 = uVar7 + 1;
          *pbVar6 = *pbVar5 ^ *pbVar6;
        } while (uVar7 < uVar3);
      }
      (**(code **)(*piVar1 + 0xc))(piVar1,1);
    }
    else {
      uVar3 = 0;
      if (*(uint *)(local_1c + 0xc) != 0) {
        do {
          pbVar5 = (byte *)(param_1 + 0xa4 + uVar3);
          *pbVar5 = *(byte *)(*(int *)(local_1c + 0x10) + uVar3) ^ *pbVar5;
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(local_1c + 0xc));
      }
    }
    iVar2 = FUN_1000d424(*(int *)(param_1 + 0x18),&local_20,0,(undefined4 *)0x0);
    if (iVar2 == 0) {
      FUN_1000c4ac(local_20,(void *)(param_1 + 0xa4),*(int *)(param_1 + 0x124));
      uVar4 = (**(code **)(**(int **)(param_1 + 0x1c) + 8))();
      FUN_1000c4ac(local_20,uVar4,*(int *)(param_1 + 0x168));
      iVar2 = FUN_1000c50c(local_20);
      _Src = (void *)(**(code **)(*local_20 + 8))(local_20);
      memcpy((void *)(param_1 + 0x128),_Src,*(size_t *)(param_1 + 0x168));
      (**(code **)(*local_20 + 0xc))(local_20,1);
      memset((void *)(param_1 + 0xa4),0x5c,*(size_t *)(param_1 + 0x124));
      if (iVar2 == 0) {
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 2;
        return;
      }
    }
  }
LAB_1000edcc:
  *(int *)(param_1 + 0x10) = iVar2;
  return;
}



/* 1000edec FUN_1000edec */

/* Boundary evidence: original MIPS .pdata 1000edec..1000ef13. Semantic name remains unreviewed. */

undefined4
FUN_1000edec(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5,void *param_6,
            size_t param_7)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  size_t sVar4;
  void *_Buf1;
  undefined4 uVar5;
  
  uVar5 = 0;
  puVar1 = operator_new(0x16c);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_1000d14c(puVar1,param_2,param_3);
  }
  if (piVar2 == (int *)0x0) {
    uVar5 = 0;
  }
  else {
    iVar3 = FUN_1000e850((int)piVar2,param_1);
    if (((iVar3 == 0) && (iVar3 = FUN_1000c4ac(piVar2,param_4,param_5), iVar3 == 0)) &&
       (iVar3 = FUN_1000c50c(piVar2), iVar3 == 0)) {
      sVar4 = (**(code **)(*piVar2 + 0x18))(piVar2);
      if (sVar4 == param_7) {
        _Buf1 = (void *)(**(code **)(*piVar2 + 8))(piVar2);
        iVar3 = memcmp(_Buf1,param_6,param_7);
        if (iVar3 == 0) {
          uVar5 = 1;
        }
      }
    }
    (**(code **)(*piVar2 + 0xc))(piVar2,1);
  }
  return uVar5;
}



/* 1000ef14 CPSetHashParam */

/* Boundary evidence: original MIPS .pdata 1000ef14..1000f05b. Semantic name remains unreviewed. */

undefined4 CPSetHashParam(uint param_1,uint param_2,int param_3,int *param_4,int param_5)

{
  DWORD dwErrCode;
  int iVar1;
  int *local_20 [2];
  
                    /* 0xef14  30  CPSetHashParam */
  if (param_5 == 0) {
    iVar1 = FUN_100091fc(param_1,0);
    if (iVar1 == 0) {
      dwErrCode = 0x80090001;
    }
    else {
      dwErrCode = FUN_1000d3bc(param_2,param_1,(int *)local_20);
      if (dwErrCode == 0) {
        if (param_3 == 2) {
          (**(code **)(*local_20[0] + 0x14))(local_20[0],param_4,0xffffffff);
          return 1;
        }
        if ((param_3 == 5) && (local_20[0][2] == 0x8009)) {
          if ((((param_4[2] == 0) && (param_4[1] == 0)) && (param_4[4] == 0)) && (param_4[3] == 0))
          {
            FUN_1000e850((int)local_20[0],*param_4);
            return 1;
          }
          dwErrCode = 0x80090005;
        }
        else {
          dwErrCode = 0x8009000a;
        }
      }
    }
  }
  else {
    dwErrCode = 0x80090009;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 1000f05c FUN_1000f05c */

/* Boundary evidence: original MIPS .pdata 1000f05c..1000f0a3. Semantic name remains unreviewed. */

undefined4 * FUN_1000f05c(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x88);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_1000e15c(puVar1,param_1);
  }
  return puVar1;
}



/* 1000f0a4 FUN_1000f0a4 */

/* Boundary evidence: original MIPS .pdata 1000f0a4..1000f343. Semantic name remains unreviewed. */

undefined4
FUN_1000f0a4(undefined *param_1,int param_2,uint param_3,int param_4,uint *param_5,uint *param_6,
            uint param_7)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint auStack_50 [4];
  uint local_40 [4];
  uint local_30;
  
  local_30 = DAT_1002da44;
  uVar5 = *param_6;
  if (0x10 < param_3) {
    FUN_1002bedc(DAT_1002da44);
    return 0x54f;
  }
  if (*(int *)(param_2 + 0x44) == 0) {
    *(undefined4 *)(param_2 + 0x44) = 1;
    if ((*(int *)(param_2 + 0x68) == 1) || (*(int *)(param_2 + 0x68) == 4)) {
      memcpy((void *)(param_2 + 0x34),(void *)(param_2 + 0x24),param_3);
    }
  }
  uVar6 = uVar5 % param_3;
  if (param_3 == 0) {
    trap(0x1c00);
  }
  if (param_4 == 0) {
    if (param_5 != (uint *)0x0) {
      if (uVar6 != 0) {
        uVar4 = 0x80090005;
        *param_6 = uVar6 + uVar5;
        goto LAB_1000f1b4;
      }
      iVar3 = 0;
      goto LAB_1000f228;
    }
    *param_6 = uVar5;
  }
  else {
    iVar3 = 0;
    if (*(int *)(param_2 + 0x90) == 0) {
      iVar3 = param_3 - uVar6;
    }
    if ((param_5 == (uint *)0x0) || (param_7 < iVar3 + uVar5)) {
      *param_6 = iVar3 + uVar5;
      if (param_5 != (uint *)0x0) {
        uVar4 = 0xea;
        goto LAB_1000f1b4;
      }
    }
    else {
      *(undefined4 *)(param_2 + 0x44) = 0;
LAB_1000f228:
      if (iVar3 != 0) {
        memset((void *)((int)param_5 + uVar5),iVar3,iVar3);
      }
      uVar5 = iVar3 + uVar5;
      bVar1 = ((uint)param_5 & 3) != 0;
      *param_6 = uVar5;
      for (; uVar5 != 0; uVar5 = uVar5 - param_3) {
        memcpy(local_40,param_5,param_3);
        iVar3 = *(int *)(param_2 + 0x68);
        if (iVar3 == 1) {
          CBC(param_1,param_3,param_5,local_40,*(undefined4 *)(param_2 + 0x1c),1,
              (uint *)(param_2 + 0x34));
        }
        else if (iVar3 == 2) {
          puVar2 = param_5;
          if (bVar1) {
            puVar2 = auStack_50;
          }
          (*(code *)param_1)(puVar2,local_40,*(undefined4 *)(param_2 + 0x1c),1);
          if (bVar1) {
            memcpy(param_5,auStack_50,param_3);
          }
        }
        else {
          if (iVar3 != 4) {
            uVar4 = 0x80090008;
            goto LAB_1000f1b4;
          }
          FUN_1001ab8c(param_1,param_3,(byte *)param_5,(byte *)local_40,
                       *(undefined4 *)(param_2 + 0x1c),1,(void *)(param_2 + 0x34));
        }
        param_5 = (uint *)((int)param_5 + param_3);
      }
    }
  }
  uVar4 = 0;
LAB_1000f1b4:
  iVar3 = 0x10;
  puVar2 = local_40;
  do {
    *(undefined1 *)puVar2 = 0;
    iVar3 = iVar3 + -1;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while (iVar3 != 0);
  FUN_1002bedc(local_30);
  return uVar4;
}



/* 1000f344 FUN_1000f344 */

/* Boundary evidence: original MIPS .pdata 1000f344..1000f5eb. Semantic name remains unreviewed. */

undefined4
FUN_1000f344(undefined *param_1,int param_2,uint param_3,int param_4,uint *param_5,uint *param_6)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint auStack_50 [4];
  uint local_40 [4];
  uint local_30;
  
  local_30 = DAT_1002da44;
  uVar9 = *param_6;
  if (0x10 < param_3) {
    FUN_1002bedc(DAT_1002da44);
    return 0x54f;
  }
  uVar7 = 1;
  if (*(int *)(param_2 + 0x44) == 0) {
    *(undefined4 *)(param_2 + 0x44) = 1;
    if ((*(int *)(param_2 + 0x68) == 1) || (*(int *)(param_2 + 0x68) == 4)) {
      memcpy((void *)(param_2 + 0x34),(void *)(param_2 + 0x24),param_3);
    }
  }
  if (param_3 == 0) {
    trap(0x1c00);
  }
  if (uVar9 % param_3 == 0) {
    bVar1 = ((uint)param_5 & 3) != 0;
    if (param_3 <= uVar9) {
      puVar8 = param_5;
      do {
        memcpy(local_40,puVar8,param_3);
        iVar2 = *(int *)(param_2 + 0x68);
        if (iVar2 == 1) {
          CBC(param_1,param_3,puVar8,local_40,*(undefined4 *)(param_2 + 0x1c),0,
              (uint *)(param_2 + 0x34));
        }
        else if (iVar2 == 2) {
          puVar3 = puVar8;
          if (bVar1) {
            puVar3 = auStack_50;
          }
          (*(code *)param_1)(puVar3,local_40,*(undefined4 *)(param_2 + 0x1c),0);
          if (bVar1) {
            memcpy(puVar8,auStack_50,param_3);
          }
        }
        else {
          if (iVar2 != 4) {
            uVar6 = 0x80090008;
            goto LAB_1000f580;
          }
          FUN_1001ab8c(param_1,param_3,(byte *)puVar8,(byte *)local_40,
                       *(undefined4 *)(param_2 + 0x1c),0,(void *)(param_2 + 0x34));
        }
        puVar8 = (uint *)((int)puVar8 + param_3);
      } while ((param_3 - (int)param_5) + (int)puVar8 <= uVar9);
    }
    if ((param_4 != 0) && (*(undefined4 *)(param_2 + 0x44) = 0, *(int *)(param_2 + 0x90) == 0)) {
      uVar4 = (uint)*(byte *)((int)param_5 + (uVar9 - 1));
      if ((uVar4 == 0) || (param_3 < uVar4)) goto LAB_1000f5e0;
      if (1 < uVar4) {
        pbVar5 = (byte *)((int)param_5 + (uVar9 - 2));
        do {
          if (*pbVar5 != uVar4) goto LAB_1000f5e0;
          uVar7 = uVar7 + 1;
          pbVar5 = pbVar5 + -1;
        } while (uVar7 < uVar4);
      }
      *param_6 = *param_6 - uVar4;
    }
    uVar6 = 0;
  }
  else {
LAB_1000f5e0:
    uVar6 = 0x80090005;
  }
LAB_1000f580:
  iVar2 = 0x10;
  puVar8 = local_40;
  do {
    *(undefined1 *)puVar8 = 0;
    iVar2 = iVar2 + -1;
    puVar8 = (uint *)((int)puVar8 + 1);
  } while (iVar2 != 0);
  FUN_1002bedc(local_30);
  return uVar6;
}



/* 1000f5ec FUN_1000f5ec */

/* Boundary evidence: original MIPS .pdata 1000f5ec..1000f7bf. Semantic name remains unreviewed. */

int FUN_1000f5ec(int param_1,int param_2,uint *param_3,uint *param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 4);
  if (0x6609 < uVar2) {
    if (uVar2 == 0x660d) {
      iVar1 = FUN_1000f0a4(FUN_100246ec,param_1,8,param_2,param_3,param_4,param_5);
    }
    else {
      if (uVar2 < 0x660e) {
        return -0x7ff6fff8;
      }
      if (0x6610 < uVar2) {
        if (uVar2 != 0x6801) {
          return -0x7ff6fff8;
        }
        if (param_3 == (uint *)0x0) {
          return 0;
        }
        if (param_5 < *param_4) {
          return 0xea;
        }
        rc4(*(int *)(param_1 + 0x1c),*param_4,(byte *)param_3);
        if (param_2 == 0) {
          return 0;
        }
        *(undefined4 *)(param_1 + 0x8c) = 0;
        return 0;
      }
      iVar1 = FUN_1000f0a4(FUN_100256dc,param_1,*(uint *)(param_1 + 0x84),param_2,param_3,param_4,
                           param_5);
    }
    goto LAB_1000f7a0;
  }
  if (uVar2 != 0x6609) {
    if (uVar2 == 0x6601) {
      iVar1 = FUN_1000f0a4(des,param_1,8,param_2,param_3,param_4,param_5);
      goto LAB_1000f7a0;
    }
    if (uVar2 == 0x6602) {
      iVar1 = FUN_1000f0a4(RC2,param_1,8,param_2,param_3,param_4,param_5);
      goto LAB_1000f7a0;
    }
    if (uVar2 != 0x6603) {
      return -0x7ff6fff8;
    }
  }
  iVar1 = FUN_1000f0a4(tripledes,param_1,8,param_2,param_3,param_4,param_5);
LAB_1000f7a0:
  if (iVar1 == 0) {
    return 0;
  }
  return iVar1;
}



/* 1000f7c0 FUN_1000f7c0 */

/* Boundary evidence: original MIPS .pdata 1000f7c0..1000f967. Semantic name remains unreviewed. */

int FUN_1000f7c0(int param_1,undefined4 param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 4);
  if (0x6609 < uVar2) {
    if (uVar2 == 0x660d) {
      iVar1 = FUN_1000f344(FUN_100246ec,param_1,8,param_3,param_4,param_5);
    }
    else {
      if (uVar2 < 0x660e) {
        return -0x7ff6fff8;
      }
      if (0x6610 < uVar2) {
        if (uVar2 != 0x6801) {
          return -0x7ff6fff8;
        }
        rc4(*(int *)(param_1 + 0x1c),*param_5,(byte *)param_4);
        if (param_3 == 0) {
          return 0;
        }
        *(undefined4 *)(param_1 + 0x8c) = 0;
        return 0;
      }
      iVar1 = FUN_1000f344(FUN_100256dc,param_1,*(uint *)(param_1 + 0x84),param_3,param_4,param_5);
    }
    goto LAB_1000f948;
  }
  if (uVar2 != 0x6609) {
    if (uVar2 == 0x6601) {
      iVar1 = FUN_1000f344(des,param_1,8,param_3,param_4,param_5);
      goto LAB_1000f948;
    }
    if (uVar2 == 0x6602) {
      iVar1 = FUN_1000f344(RC2,param_1,8,param_3,param_4,param_5);
      goto LAB_1000f948;
    }
    if (uVar2 != 0x6603) {
      return -0x7ff6fff8;
    }
  }
  iVar1 = FUN_1000f344(tripledes,param_1,8,param_3,param_4,param_5);
LAB_1000f948:
  if (iVar1 == 0) {
    return 0;
  }
  return iVar1;
}



/* 1000f968 FUN_1000f968 */

/* Boundary evidence: original MIPS .pdata 1000f968..1000f9e3. Semantic name remains unreviewed. */

uint * FUN_1000f968(uint *param_1,uint param_2,uint param_3)

{
  if (param_3 == 0) {
    param_3 = 0;
    param_2 = 0;
    param_1 = (uint *)&DAT_c0000094;
    RaiseException(0xc0000094,0,0,(ULONG_PTR *)0x0);
  }
  if ((int)param_3 < 0) {
    param_3 = 0;
    param_2 = 0;
    param_1 = (uint *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  if (param_3 == 0) {
    trap(0x1c00);
  }
  *param_1 = param_2 / param_3;
  return param_1;
}



/* 1000f9e4 FUN_1000f9e4 */

/* Boundary evidence: original MIPS .pdata 1000f9e4..1000fa23. Semantic name remains unreviewed. */

undefined4 * FUN_1000f9e4(uint *param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *param_1 + param_3;
  FUN_1000aa40(param_2,param_2,uVar1,(param_3 >> 0x1f) + (uint)(uVar1 < *param_1));
  return param_2;
}



/* 1000fa24 FUN_1000fa24 */

/* Boundary evidence: original MIPS .pdata 1000fa24..1000febf. Semantic name remains unreviewed. */

DWORD FUN_1000fa24(uint *param_1,uint param_2,uint *param_3,int param_4,uint param_5,uint *param_6,
                  uint *param_7,uint param_8,int param_9)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  DWORD DVar4;
  undefined3 extraout_var;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  uint uVar8;
  HLOCAL _Src;
  uint *local_38;
  uint local_34;
  uint local_30 [2];
  
  _Src = (HLOCAL)0x0;
  if ((param_5 & 0xffffffbf) != 0) {
    return 0x80090009;
  }
  uVar8 = *param_7;
  if ((param_4 == 0) && (uVar8 == 0)) {
    return 0;
  }
  puVar2 = (uint *)FUN_100091fc((uint)param_1,0);
  if (puVar2 == (uint *)0x0) {
    return 0x80090001;
  }
  if (((param_9 != 0) && (puVar2[1] != 0xc)) && ((*puVar2 & 1) == 1)) {
    return 0x80090010;
  }
  puVar5 = param_1;
  iVar3 = FUN_10009224(param_2,(int)param_1,2,&local_38);
  if ((iVar3 != 0) &&
     (puVar5 = param_1, DVar4 = FUN_10009224(param_2,(int)param_1,4,&local_38), DVar4 != 0)) {
    if (DVar4 == 0x80090020) {
      return 0x80090003;
    }
    return DVar4;
  }
  if ((local_38[1] != 0xa400) &&
     (puVar5 = local_38, iVar3 = FUN_10010610((int)puVar2,(int)local_38,0), iVar3 == 0)) {
    return 0x80090003;
  }
  puVar6 = local_38;
  if (((param_4 == 0) && (local_38[1] != 0x6801)) && (uVar8 < local_38[0x21])) {
    *param_7 = local_38[0x21];
    return 0x80090005;
  }
  if (((puVar2[0x2e] == 0) && (DAT_1002dc68 != 0)) &&
     ((param_6 != (uint *)0x0 &&
      ((*param_7 != 0 && (puVar5 = param_6, iVar3 = memcmp(&DAT_1002dc60,param_6,8), iVar3 == 0)))))
     ) {
    return 0x80090012;
  }
  if (((puVar6[0x23] == 0) && (puVar6[1] != 0xa400)) &&
     (DVar4 = FUN_10010c04((int)puVar6), puVar6 = local_38, DVar4 != 0)) {
    return DVar4;
  }
  if ((param_3 != (uint *)0x0) && (param_6 != (uint *)0x0)) {
    local_34 = 4;
    iVar3 = CPGetHashParam((uint)param_1,(uint)param_3,1,local_30,&local_34,0);
    if (iVar3 == 0) {
LAB_1000fc8c:
      DVar4 = GetLastError();
      return DVar4;
    }
    if (local_30[0] == 0x8005) {
      return 0x80090002;
    }
    iVar3 = CPHashData((uint)param_1,(uint)param_3,(int)param_6,*param_7,0);
    puVar5 = param_3;
    puVar6 = local_38;
    if (iVar3 == 0) goto LAB_1000fc8c;
  }
  if (puVar6[1] == 0xa400) {
    piVar7 = (int *)puVar6[4];
    if (piVar7 == (int *)0x0) {
      return 0x80090003;
    }
    uVar8 = piVar7[2] + 7;
    FUN_1000aa40(local_30,puVar5,uVar8,(uint)(uVar8 < (uint)piVar7[2]));
    uVar8 = local_30[0] >> 3;
    bVar1 = FUN_10016b54(uVar8,*param_7,param_5);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0x80090004;
    }
    if ((param_6 == (uint *)0x0) || (param_8 < uVar8)) {
      *param_7 = uVar8;
      if (param_6 == (uint *)0x0) {
        return 0;
      }
      DVar4 = 0xea;
      goto LAB_1000fe7c;
    }
    _Src = LocalAlloc(0x40,uVar8);
    if (_Src == (HLOCAL)0x0) {
      DVar4 = 8;
      goto LAB_1000fe7c;
    }
    DVar4 = FUN_10017dc4((int)puVar2,piVar7,param_6,*param_7,(void *)local_38[0x1f],local_38[0x20],
                         param_5,_Src);
    if (DVar4 != 0) goto LAB_1000fe7c;
    *param_7 = uVar8;
    memcpy(param_6,_Src,uVar8);
  }
  else {
    DVar4 = FUN_1000f5ec((int)puVar6,param_4,param_6,param_7,param_8);
    if (DVar4 != 0) {
      return DVar4;
    }
  }
  if (((puVar2[0x2e] == 0) && (param_6 != (uint *)0x0)) && (7 < *param_7)) {
    DAT_1002dc60 = *param_6;
    DAT_1002dc64 = param_6[1];
    DAT_1002dc68 = 1;
  }
  else {
    DAT_1002dc68 = 0;
  }
  DVar4 = 0;
LAB_1000fe7c:
  if (_Src != (HLOCAL)0x0) {
    LocalFree(_Src);
    return DVar4;
  }
  return DVar4;
}



/* 1000fec0 CPEncrypt */

/* Boundary evidence: original MIPS .pdata 1000fec0..1000ff27. Semantic name remains unreviewed. */

bool CPEncrypt(uint *param_1,uint param_2,uint *param_3,int param_4,uint param_5,uint *param_6,
              uint *param_7,uint param_8)

{
  DWORD dwErrCode;
  
                    /* 0xfec0  18  CPEncrypt */
  dwErrCode = FUN_1000fa24(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,1);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* 1000ff28 FUN_1000ff28 */

/* Boundary evidence: original MIPS .pdata 1000ff28..10010393. Semantic name remains unreviewed. */

DWORD FUN_1000ff28(uint param_1,uint param_2,uint param_3,int param_4,uint param_5,uint *param_6,
                  uint *param_7,int param_8)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  DWORD DVar5;
  int *piVar6;
  int local_40;
  HLOCAL local_3c;
  uint local_38;
  uint local_34;
  uint local_30 [2];
  
  local_3c = (HLOCAL)0x0;
  if (((param_5 & 0xffffff9f) != 0) || (((param_5 & 0x40) != 0 && ((param_5 & 0x20) != 0)))) {
    return 0x80090009;
  }
  if (*param_7 == 0) {
    if (param_4 == 1) {
      return 0x80090004;
    }
    return 0;
  }
  puVar1 = (uint *)FUN_100091fc(param_1,0);
  if (puVar1 == (uint *)0x0) {
    DVar5 = 0x80090001;
    goto LAB_10010080;
  }
  if (((param_8 != 0) && (puVar1[1] != 0xc)) && ((*puVar1 & 1) == 1)) {
    DVar5 = 0x80090010;
    goto LAB_10010080;
  }
  iVar2 = FUN_10009224(param_2,param_1,2,&local_40);
  if ((iVar2 == 0) || (DVar5 = FUN_10009224(param_2,param_1,4,&local_40), DVar5 == 0)) {
    if ((puVar1[0x2e] == 0) &&
       ((DAT_1002dc6c != 0 && (iVar2 = memcmp(&DAT_1002dc58,param_6,8), iVar2 == 0)))) {
      DVar5 = 0x80090012;
      goto LAB_10010080;
    }
    if ((*(int *)(local_40 + 4) == 0xa400) ||
       (iVar2 = FUN_10010610((int)puVar1,local_40,1), iVar2 != 0)) {
      if (((*(int *)(local_40 + 0x8c) == 0) && (*(int *)(local_40 + 4) != 0xa400)) &&
         (DVar5 = FUN_10010c04(local_40), DVar5 != 0)) goto LAB_10010080;
      if (*(int *)(local_40 + 4) == 0xa400) {
        if ((void *)puVar1[0x13] != (void *)0x0) {
          if ((puVar1[0xc] != *(size_t *)(local_40 + 0xc)) ||
             (iVar2 = memcmp((void *)puVar1[0x13],*(void **)(local_40 + 0x10),puVar1[0xc]),
             iVar2 != 0)) goto LAB_10010078;
          uVar3 = DAT_1002dcd4;
          DVar5 = FUN_1000bb68(puVar1,DAT_1002dcd4,0,0);
          if (DVar5 != 0) goto LAB_10010080;
          piVar6 = (int *)puVar1[0x1b];
          if (piVar6 != (int *)0x0) {
            uVar4 = piVar6[2] + 7;
            FUN_1000aa40(&local_34,uVar3,uVar4,(uint)(uVar4 < (uint)piVar6[2]));
            local_38 = local_34 >> 3;
            local_3c = LocalAlloc(0x40,local_38);
            if (local_3c == (HLOCAL)0x0) {
              DVar5 = 8;
              goto LAB_10010080;
            }
            DVar5 = FUN_10017e70((int)puVar1,piVar6,param_6,*param_7,*(void **)(local_40 + 0x7c),
                                 *(uint *)(local_40 + 0x80),param_5,(int *)&local_3c,&local_38);
            if (DVar5 != 0) goto LAB_10010080;
            *param_7 = local_38;
            memcpy(param_6,local_3c,local_38);
            goto LAB_100102b0;
          }
        }
        DVar5 = 0x8009000d;
        goto LAB_10010080;
      }
      DVar5 = FUN_1000f7c0(local_40,0,param_4,param_6,param_7);
      if (DVar5 != 0) goto LAB_10010080;
LAB_100102b0:
      if (param_3 == 0) {
LAB_1001033c:
        if ((puVar1[0x2e] == 0) && (7 < *param_7)) {
          DAT_1002dc58 = *param_6;
          DAT_1002dc5c = param_6[1];
          DAT_1002dc6c = 1;
        }
        else {
          DAT_1002dc6c = 0;
        }
        DVar5 = 0;
      }
      else {
        local_34 = 4;
        iVar2 = CPGetHashParam(param_1,param_3,1,local_30,&local_34,0);
        if (iVar2 != 0) {
          if (local_30[0] == 0x8005) {
            DVar5 = 0x80090002;
            goto LAB_10010080;
          }
          iVar2 = CPHashData(param_1,param_3,(int)param_6,*param_7,0);
          if (iVar2 != 0) goto LAB_1001033c;
        }
        DVar5 = GetLastError();
      }
      goto LAB_10010080;
    }
  }
  else if (DVar5 != 0x80090020) goto LAB_10010080;
LAB_10010078:
  DVar5 = 0x80090003;
LAB_10010080:
  if (local_3c != (HLOCAL)0x0) {
    LocalFree(local_3c);
  }
  return DVar5;
}



/* 10010394 CPDecrypt */

/* Boundary evidence: original MIPS .pdata 10010394..100103f3. Semantic name remains unreviewed. */

bool CPDecrypt(uint param_1,uint param_2,uint param_3,int param_4,uint param_5,uint *param_6,
              uint *param_7)

{
  DWORD dwErrCode;
  
                    /* 0x10394  12  CPDecrypt */
  dwErrCode = FUN_1000ff28(param_1,param_2,param_3,param_4,param_5,param_6,param_7,1);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* 100103f4 FUN_100103f4 */

void FUN_100103f4(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (0x6609 < param_1) {
    if (param_1 == 0x660d) {
      uVar1 = 0x10c;
LAB_1001049c:
      *param_2 = uVar1;
      return;
    }
    if (0x660d < param_1) {
      if (param_1 < 0x6611) {
        uVar1 = 0x1e4;
        goto LAB_1001049c;
      }
      if (param_1 == 0x6801) {
        *param_2 = 0x102;
        return;
      }
    }
LAB_10010430:
    *param_2 = 0;
    return;
  }
  if (param_1 != 0x6609) {
    if (param_1 == 0x6601) {
      uVar1 = 0x80;
      goto LAB_1001049c;
    }
    if (param_1 == 0x6602) {
      uVar1 = 0x80;
      goto LAB_1001043c;
    }
    if (param_1 != 0x6603) goto LAB_10010430;
  }
  uVar1 = 0x180;
LAB_1001043c:
  *param_2 = uVar1;
  return;
}



/* 100104a8 FUN_100104a8 */

/* Boundary evidence: original MIPS .pdata 100104a8..100104f7. Semantic name remains unreviewed. */

void FUN_100104a8(HLOCAL param_1)

{
  if (*(int *)((int)param_1 + 0x20) == 0) {
    LocalFree(*(HLOCAL *)((int)param_1 + 0x1c));
  }
  if (*(int *)((int)param_1 + 0x14) == 0) {
    LocalFree(*(HLOCAL *)((int)param_1 + 0x10));
  }
  LocalFree(param_1);
  return;
}



/* 100104f8 FUN_100104f8 */

/* Boundary evidence: original MIPS .pdata 100104f8..1001060f. Semantic name remains unreviewed. */

undefined4 FUN_100104f8(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  
  *param_5 = 0;
  if (param_2 != 0x2400) {
    if (param_2 == 0x6601) {
      if (param_3 == 8) {
        return 1;
      }
      iVar1 = 7;
LAB_10010600:
      if (param_3 == iVar1) {
        return 1;
      }
      return 0;
    }
    if (param_2 == 0x6602) {
      if (param_4 != 0) {
        return 1;
      }
      param_2 = 0x6602;
      goto LAB_10010568;
    }
    if (param_2 == 0x6603) {
      if (param_3 == 0x18) {
        return 1;
      }
      iVar1 = 0x15;
      goto LAB_10010600;
    }
    if (param_2 == 0x6609) {
      if (param_3 == 0x10) {
        return 1;
      }
      if (param_3 == 0xe) {
        return 1;
      }
      return 0;
    }
    if (param_2 != 0xa400) goto LAB_10010568;
  }
  *param_5 = 1;
LAB_10010568:
  iVar1 = FUN_1002b714((int *)(&PTR_DAT_1002d7f4)[param_1],param_2,param_3 << 3,(int *)0x0);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}



/* 10010610 FUN_10010610 */

/* Boundary evidence: original MIPS .pdata 10010610..1001065f. Semantic name remains unreviewed. */

undefined4 FUN_10010610(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_10 [2];
  
  uVar2 = 0;
  if (param_2 != 0) {
    iVar1 = FUN_100104f8(*(int *)(param_1 + 0xb8),*(int *)(param_2 + 4),*(int *)(param_2 + 0xc),
                         param_3,auStack_10);
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 10010660 FUN_10010660 */

/* Boundary evidence: original MIPS .pdata 10010660..1001077b. Semantic name remains unreviewed. */

undefined4 FUN_10010660(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 0x2400) {
    return 0;
  }
  if (iVar1 == 0x6601) {
    iVar1 = 8;
LAB_10010758:
    if (*(int *)(param_2 + 0xc) != iVar1) {
      return 0;
    }
  }
  else {
    if (iVar1 == 0x6602) {
      if (param_3 != 0) {
        return 1;
      }
      iVar1 = FUN_1002b714((int *)(&PTR_DAT_1002d7f4)[*(int *)(param_1 + 0xb8)],0x6602,
                           *(int *)(param_2 + 0xc) << 3,(int *)0x0);
    }
    else {
      if (iVar1 == 0x6603) {
        if (*(int *)(param_2 + 0xc) == 0x18) {
          return 1;
        }
        return 0;
      }
      if (iVar1 == 0x6609) {
        iVar1 = 0x10;
        goto LAB_10010758;
      }
      if (iVar1 == 0xa400) {
        return 0;
      }
      iVar1 = FUN_1002b714((int *)(&PTR_DAT_1002d7f4)[*(int *)(param_1 + 0xb8)],iVar1,
                           *(int *)(param_2 + 0xc) << 3,(int *)0x0);
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



/* 1001077c FUN_1001077c */

/* Boundary evidence: original MIPS .pdata 1001077c..100107c7. Semantic name remains unreviewed. */

bool FUN_1001077c(int param_1,uint param_2)

{
  bool bVar1;
  
  if ((param_2 & 0xe000) == 0x8000) {
    bVar1 = false;
  }
  else {
    bVar1 = thunk_FUN_1002b6e4((int *)(&PTR_DAT_1002d7f4)[*(int *)(param_1 + 0xb8)],param_2,
                               (int *)0x0);
  }
  return bVar1;
}



/* 100107c8 FUN_100107c8 */

/* Boundary evidence: original MIPS .pdata 100107c8..1001085b. Semantic name remains unreviewed. */

bool FUN_100107c8(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  uint local_18 [2];
  
  *param_4 = 0;
  if ((param_2 == 0x2400) || (param_2 == 0xa400)) {
    *param_4 = 1;
  }
  iVar1 = FUN_1002b778((int *)(&PTR_DAT_1002d7f4)[*(int *)(param_1 + 0xb8)],param_2,(int *)0x0,
                       (int *)local_18);
  if (iVar1 != 0) {
    *param_3 = local_18[0] >> 3;
  }
  return iVar1 != 0;
}



/* 1001085c FUN_1001085c */

/* Boundary evidence: original MIPS .pdata 1001085c..100108ef. Semantic name remains unreviewed. */

undefined4 FUN_1001085c(int param_1,int param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  
  if (param_3 >> 0x10 == 0) {
    bVar1 = FUN_100107c8(param_1,param_2,param_4,param_5);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0x80090008;
    }
LAB_100108b8:
    uVar3 = 0;
  }
  else {
    if ((param_3 >> 0x10 & 7) == 0) {
      iVar2 = FUN_100104f8(*(int *)(param_1 + 0xb8),param_2,param_3 >> 0x13,0,param_5);
      if (iVar2 != 0) {
        *param_4 = param_3 >> 0x13;
        goto LAB_100108b8;
      }
    }
    uVar3 = 0x80090009;
  }
  return uVar3;
}



/* 100108f0 FUN_100108f0 */

/* Boundary evidence: original MIPS .pdata 100108f0..1001097f. Semantic name remains unreviewed. */

void FUN_100108f0(void *param_1,uint param_2,undefined4 *param_3)

{
  undefined1 auStack_88 [96];
  undefined4 local_28;
  undefined4 local_24;
  uint local_14;
  
  local_14 = DAT_1002da44;
  A_SHAInit((int)auStack_88);
  A_SHAUpdate(auStack_88,param_1,param_2);
  A_SHAFinal(auStack_88,(int)&local_28);
  *param_3 = local_28;
  param_3[1] = local_24;
  FUN_1002bedc(local_14);
  return;
}



/* 10010980 FUN_10010980 */

/* Boundary evidence: original MIPS .pdata 10010980..10010c03. Semantic name remains unreviewed. */

int FUN_10010980(undefined4 param_1,int param_2,uint param_3,uint *param_4)

{
  undefined4 *_Dst;
  size_t _Size;
  uint uVar1;
  uint *puVar2;
  int iVar3;
  SIZE_T uBytes;
  int iVar4;
  int local_30 [2];
  
  local_30[0] = 0;
  *param_4 = 0;
  uBytes = 0x94;
  if (0x6f < param_3) {
    puVar2 = (uint *)(param_2 + 8);
    iVar3 = *(int *)(param_2 + 0x14);
    if ((*(int *)(param_2 + 0x14) != 0) ||
       (FUN_100103f4(*puVar2,local_30), iVar3 = local_30[0], local_30[0] != 0)) {
      uBytes = iVar3 + 0x98;
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      uBytes = *(int *)(param_2 + 0x10) + uBytes + 4;
    }
    _Dst = LocalAlloc(0x40,uBytes);
    if (_Dst == (undefined4 *)0x0) {
      iVar3 = 8;
    }
    else {
      memset(_Dst,0,uBytes);
      iVar4 = 0x98;
      if (iVar3 != 0) {
        _Dst[8] = 1;
      }
      _Dst[5] = 1;
      _Dst[0x22] = uBytes;
      *_Dst = param_1;
      _Dst[1] = *puVar2;
      _Dst[2] = *(undefined4 *)(param_2 + 0xc);
      _Dst[3] = *(undefined4 *)(param_2 + 0x10);
      _Dst[6] = iVar3;
      _Dst[9] = *(undefined4 *)(param_2 + 0x18);
      _Dst[10] = *(undefined4 *)(param_2 + 0x1c);
      _Dst[0xb] = *(undefined4 *)(param_2 + 0x20);
      _Dst[0xc] = *(undefined4 *)(param_2 + 0x24);
      _Dst[0xd] = *(undefined4 *)(param_2 + 0x28);
      _Dst[0xe] = *(undefined4 *)(param_2 + 0x2c);
      _Dst[0xf] = *(undefined4 *)(param_2 + 0x30);
      _Dst[0x10] = *(undefined4 *)(param_2 + 0x34);
      _Dst[0x11] = *(undefined4 *)(param_2 + 0x38);
      _Dst[0x12] = *(undefined4 *)(param_2 + 0x3c);
      memcpy(_Dst + 0x13,(void *)(param_2 + 0x40),0x18);
      _Dst[0x19] = *(undefined4 *)(param_2 + 0x58);
      _Dst[0x1a] = *(undefined4 *)(param_2 + 0x5c);
      _Dst[0x1b] = *(undefined4 *)(param_2 + 0x60);
      _Dst[0x1c] = *(undefined4 *)(param_2 + 100);
      _Dst[0x1d] = *(undefined4 *)(param_2 + 0x68);
      _Size = _Dst[3];
      _Dst[0x21] = *(undefined4 *)(param_2 + 0x6c);
      uVar1 = _Size + 0x70;
      if (*(int *)(param_2 + 0x14) != 0) {
        uVar1 = *(int *)(param_2 + 0x14) + uVar1;
      }
      if (param_3 < uVar1) {
        iVar3 = -0x7ff6fffb;
      }
      else {
        if (_Size != 0) {
          _Dst[4] = _Dst + 0x26;
          iVar4 = (_Size + 4 & 0xfffffffc) + 0x98;
          memcpy(_Dst + 0x26,(void *)(param_2 + 0x70),_Size);
        }
        if (iVar3 != 0) {
          _Dst[7] = (void *)(iVar4 + (int)_Dst);
          if (*(int *)(param_2 + 0x14) != 0) {
            memcpy((void *)(iVar4 + (int)_Dst),(void *)((int)puVar2 + _Dst[3] + 0x68),_Dst[6]);
            _Dst[0x23] = 1;
          }
        }
        iVar3 = FUN_100092e4(param_4,2,_Dst);
        if (iVar3 == 0) {
          _Dst = (undefined4 *)0x0;
          iVar3 = 0;
        }
      }
      if (_Dst != (undefined4 *)0x0) {
        FUN_100104a8(_Dst);
      }
    }
    return iVar3;
  }
  return -0x7ff6fffb;
}



/* 10010c04 FUN_10010c04 */

/* Boundary evidence: original MIPS .pdata 10010c04..10010ecf. Semantic name remains unreviewed. */

undefined4 FUN_10010c04(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  size_t _Size;
  uint _Size_00;
  size_t _Size_01;
  undefined4 uStack_54;
  undefined1 local_50 [48];
  uint local_20;
  
  local_20 = DAT_1002da44;
  if (*(void **)(param_1 + 0x1c) == (void *)0x0) {
    FUN_1002bedc(DAT_1002da44);
    return 0x8009000a;
  }
  memset(*(void **)(param_1 + 0x1c),0,*(size_t *)(param_1 + 0x18));
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 < 0x660e) {
    if (uVar1 == 0x660d) {
      uVar1 = *(uint *)(param_1 + 0xc) + 3 & 0xfffffffc;
      if (((0x30 < uVar1) || (0x20 < *(uint *)(param_1 + 0x78))) ||
         (0x30 < *(uint *)(param_1 + 0xc))) {
LAB_10010db0:
        uVar4 = 0x80090003;
        goto LAB_10010e78;
      }
      *(undefined4 *)((int)&uStack_54 + uVar1) = 0;
      memcpy(local_50,*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0xc));
      FUN_1002445c(*(int **)(param_1 + 0x1c),(uint)local_50,uVar1,*(int *)(param_1 + 0x78));
    }
    else if (uVar1 == 0x6601) {
      deskey(*(uint **)(param_1 + 0x1c),*(uint **)(param_1 + 0x10));
    }
    else if (uVar1 == 0x6602) {
      _Size_00 = *(uint *)(param_1 + 0x48);
      uVar1 = *(uint *)(param_1 + 0xc);
      if (((0x30 < uVar1 + _Size_00) || (0x30 < uVar1)) || (0x30 < _Size_00)) goto LAB_10010db0;
      memcpy(local_50,*(void **)(param_1 + 0x10),uVar1);
      memcpy(local_50 + uVar1,(void *)(param_1 + 0x4c),_Size_00);
      RC2KeyEx(*(void **)(param_1 + 0x1c),local_50,uVar1 + _Size_00,*(int *)(param_1 + 0x74));
    }
    else if (uVar1 == 0x6603) {
      tripledes3key(*(uint **)(param_1 + 0x1c),*(uint **)(param_1 + 0x10));
    }
    else {
      if (uVar1 != 0x6609) goto LAB_10010dec;
      FUN_1001e8ec(*(uint **)(param_1 + 0x1c),*(uint **)(param_1 + 0x10));
    }
  }
  else {
    if (uVar1 == 0x660e) {
      iVar2 = 10;
    }
    else if (uVar1 == 0x660f) {
      iVar2 = 0xc;
    }
    else {
      if (uVar1 != 0x6610) {
        if (uVar1 != 0x6801) {
LAB_10010dec:
          uVar4 = 0x8009000a;
          goto LAB_10010e78;
        }
        _Size_01 = *(size_t *)(param_1 + 0x48);
        _Size = *(size_t *)(param_1 + 0xc);
        uVar1 = _Size + _Size_01;
        if (uVar1 < 0x31) {
          memcpy(local_50,*(void **)(param_1 + 0x10),_Size);
          memcpy(local_50 + _Size,(void *)(param_1 + 0x4c),_Size_01);
          rc4_key(*(int **)(param_1 + 0x1c),uVar1,(int)local_50);
          goto LAB_10010e6c;
        }
        goto LAB_10010db0;
      }
      iVar2 = 0xe;
    }
    FUN_10025728(*(int **)(param_1 + 0x1c),*(int *)(param_1 + 0x10),iVar2);
  }
LAB_10010e6c:
  *(undefined4 *)(param_1 + 0x8c) = 1;
  uVar4 = 0;
LAB_10010e78:
  iVar2 = 0x30;
  puVar3 = local_50;
  do {
    *puVar3 = 0;
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 1;
  } while (iVar2 != 0);
  FUN_1002bedc(local_20);
  return uVar4;
}



/* 10010ed0 CPDestroyKey */

/* Boundary evidence: original MIPS .pdata 10010ed0..1001104b. Semantic name remains unreviewed. */

undefined4 CPDestroyKey(uint param_1,uint param_2)

{
  int iVar1;
  DWORD dwErrCode;
  undefined1 *puVar2;
  HLOCAL local_18 [2];
  
                    /* 0x10ed0  15  CPDestroyKey */
  iVar1 = FUN_100091fc(param_1,0);
  if (iVar1 == 0) {
    dwErrCode = 0x80090001;
  }
  else {
    iVar1 = FUN_10009224(param_2,param_1,3,local_18);
    if (((iVar1 == 0) || (iVar1 = FUN_10009224(param_2,param_1,4,local_18), iVar1 == 0)) ||
       (dwErrCode = FUN_10009224(param_2,param_1,2,local_18), dwErrCode == 0)) {
      FUN_1000935c(param_2);
      puVar2 = *(undefined1 **)((int)local_18[0] + 0x10);
      if (puVar2 != (undefined1 *)0x0) {
        for (iVar1 = *(int *)((int)local_18[0] + 0xc); iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        if (*(int *)((int)local_18[0] + 0x14) == 0) {
          LocalFree(*(HLOCAL *)((int)local_18[0] + 0x10));
        }
      }
      if (*(HLOCAL *)((int)local_18[0] + 0x7c) != (HLOCAL)0x0) {
        LocalFree(*(HLOCAL *)((int)local_18[0] + 0x7c));
      }
      puVar2 = *(undefined1 **)((int)local_18[0] + 0x1c);
      if (puVar2 != (undefined1 *)0x0) {
        for (iVar1 = *(int *)((int)local_18[0] + 0x18); iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        if (*(int *)((int)local_18[0] + 0x20) == 0) {
          LocalFree(*(HLOCAL *)((int)local_18[0] + 0x1c));
        }
      }
      LocalFree(local_18[0]);
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 1001104c CPSetKeyParam */

/* Boundary evidence: original MIPS .pdata 1001104c..10011537. Semantic name remains unreviewed. */

undefined4 CPSetKeyParam(uint param_1,uint param_2,uint param_3,uint *param_4,uint param_5)

{
  DWORD dwErrCode;
  int iVar1;
  int iVar2;
  HLOCAL pvVar3;
  void *_Dst;
  size_t _Size;
  uint uVar4;
  int local_30 [2];
  
                    /* 0x1104c  31  CPSetKeyParam */
  if ((param_5 & 0xfffffbff) != 0) {
LAB_1001109c:
    dwErrCode = 0x80090009;
    goto LAB_100114f0;
  }
  iVar1 = FUN_100091fc(param_1,0);
  if (iVar1 == 0) {
    dwErrCode = 0x80090001;
    goto LAB_100114f0;
  }
  iVar2 = FUN_10009224(param_2,param_1,2,local_30);
  if (((iVar2 != 0) && (iVar2 = FUN_10009224(param_2,param_1,3,local_30), iVar2 != 0)) &&
     (dwErrCode = FUN_10009224(param_2,param_1,4,local_30), dwErrCode != 0)) goto LAB_100114f0;
  if (6 < param_3) {
    if (param_3 == 10) {
      if ((*(int *)(local_30[0] + 4) == 0x6602) || (*(int *)(local_30[0] + 4) == 0x6801)) {
        if (param_4 == (uint *)0x0) {
LAB_1001124c:
          dwErrCode = 0x57;
          goto LAB_100114f0;
        }
        if (0x18 < *param_4) goto LAB_10011218;
        *(uint *)(local_30[0] + 0x48) = *param_4;
        memcpy((void *)(local_30[0] + 0x4c),(void *)param_4[1],*(size_t *)(local_30[0] + 0x48));
        dwErrCode = FUN_10010c04(local_30[0]);
        if (dwErrCode != 0) goto LAB_100114f0;
        goto LAB_100114e4;
      }
    }
    else if (param_3 == 0x13) {
      if (*(int *)(local_30[0] + 4) == 0x6602) {
        uVar4 = *param_4;
        if (uVar4 != 0) {
          if (*(int *)(iVar1 + 0xb8) == 0) {
            if (uVar4 < 0x39) {
LAB_10011464:
              *(uint *)(local_30[0] + 0x74) = uVar4;
              goto LAB_1001146c;
            }
          }
          else if (uVar4 < 0x401) goto LAB_10011464;
        }
LAB_10011218:
        dwErrCode = 0x80090005;
        goto LAB_100114f0;
      }
    }
    else if (param_3 == 0x23) {
      if (*(int *)(local_30[0] + 4) == 0x660d) {
        if (*param_4 < 0x21) {
          *(uint *)(local_30[0] + 0x78) = *param_4;
          goto LAB_100114e4;
        }
        goto LAB_10011218;
      }
    }
    else {
      if (param_3 != 0x24) {
LAB_10011354:
        dwErrCode = 0x8009000a;
        goto LAB_100114f0;
      }
      if (*(int *)(local_30[0] + 4) == 0xa400) {
        if (param_4 != (uint *)0x0) {
          if (*(HLOCAL *)(local_30[0] + 0x7c) != (HLOCAL)0x0) {
            LocalFree(*(HLOCAL *)(local_30[0] + 0x7c));
            *(undefined4 *)(local_30[0] + 0x7c) = 0;
          }
          *(uint *)(local_30[0] + 0x80) = *param_4;
          pvVar3 = LocalAlloc(0x40,*(SIZE_T *)(local_30[0] + 0x80));
          *(HLOCAL *)(local_30[0] + 0x7c) = pvVar3;
          if (*(int *)(local_30[0] + 0x7c) == 0) {
            dwErrCode = 8;
            *(undefined4 *)(local_30[0] + 0x80) = 0;
            goto LAB_100114f0;
          }
          _Size = *(size_t *)(local_30[0] + 0x80);
          param_4 = (uint *)param_4[1];
          _Dst = *(void **)(local_30[0] + 0x7c);
          goto LAB_100112ac;
        }
        goto LAB_1001124c;
      }
    }
LAB_10011200:
    dwErrCode = 0x80090003;
    goto LAB_100114f0;
  }
  if (param_3 == 6) {
    uVar4 = *param_4;
    if ((uVar4 & 0xfffffec0) != 0) goto LAB_1001109c;
    if ((((uVar4 & 4) != 0) && ((*(uint *)(local_30[0] + 0x70) & 4) == 0)) ||
       (((uVar4 & 0x100) != 0 && ((*(uint *)(local_30[0] + 0x70) & 0x100) == 0))))
    goto LAB_10011218;
    *(uint *)(local_30[0] + 0x70) = (*(uint *)(local_30[0] + 0x70) ^ uVar4) & 0x104 ^ uVar4;
LAB_100114e4:
    dwErrCode = 0;
  }
  else {
    if (param_3 == 1) {
      _Size = *(size_t *)(local_30[0] + 0x84);
      _Dst = (void *)(local_30[0] + 0x24);
LAB_100112ac:
      memcpy(_Dst,param_4,_Size);
      goto LAB_100114e4;
    }
    if (param_3 != 2) {
      if (param_3 == 3) {
        if (*param_4 != 1) goto LAB_10011218;
      }
      else if (param_3 == 4) {
        if ((*(int *)(local_30[0] + 4) == 0x2400) || (*(int *)(local_30[0] + 4) == 0xa400))
        goto LAB_10011200;
        uVar4 = *param_4;
        if ((uVar4 & 0xffff0000) == 0x10000) {
          *(undefined4 *)(local_30[0] + 0x90) = 1;
        }
        uVar4 = uVar4 & 0xffff;
        if ((((uVar4 != 1) && (uVar4 != 2)) && (uVar4 != 4)) && (uVar4 != 3)) goto LAB_10011218;
        *(uint *)(local_30[0] + 0x68) = uVar4;
      }
      else {
        if (param_3 != 5) goto LAB_10011354;
        uVar4 = *param_4;
        if ((uVar4 == 0) || (0x40 < uVar4)) goto LAB_10011218;
        *(uint *)(local_30[0] + 0x6c) = uVar4;
      }
      goto LAB_100114e4;
    }
    if ((*(int *)(local_30[0] + 4) != 0x6602) && (*(int *)(local_30[0] + 4) != 0x6801))
    goto LAB_10011200;
    if (param_4 == (uint *)0x0) goto LAB_1001124c;
    if ((*(int *)(iVar1 + 0xb8) == 0) || (*(int *)(iVar1 + 0xb8) == 1)) {
      *(undefined4 *)(local_30[0] + 0x48) = 0xb;
    }
    else {
      *(undefined4 *)(local_30[0] + 0x48) = 0;
    }
    if (*(size_t *)(local_30[0] + 0x48) != 0) {
      memcpy((void *)(local_30[0] + 0x4c),param_4,*(size_t *)(local_30[0] + 0x48));
    }
LAB_1001146c:
    dwErrCode = FUN_10010c04(local_30[0]);
    if (dwErrCode == 0) goto LAB_100114e4;
  }
  if (dwErrCode == 0) {
    return 1;
  }
LAB_100114f0:
  SetLastError(dwErrCode);
  return 0;
}



/* 10011538 CPGetKeyParam */

/* Boundary evidence: original MIPS .pdata 10011538..10011ac3. Semantic name remains unreviewed. */

undefined4
CPGetKeyParam(uint param_1,uint param_2,uint param_3,int *param_4,uint *param_5,int param_6)

{
  char cVar1;
  DWORD dwErrCode;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_28 [2];
  
                    /* 0x11538  23  CPGetKeyParam */
  if (param_6 != 0) {
    dwErrCode = 0x80090009;
    goto LAB_10011a84;
  }
  iVar2 = FUN_100091fc(param_1,0);
  if (iVar2 == 0) {
    dwErrCode = 0x80090001;
    goto LAB_10011a84;
  }
  iVar2 = FUN_10009224(param_2,param_1,2,local_28);
  uVar4 = 1;
  if (((iVar2 != 0) && (iVar2 = FUN_10009224(param_2,param_1,3,local_28), iVar2 != 0)) &&
     (dwErrCode = FUN_10009224(param_2,param_1,4,local_28), dwErrCode != 0)) goto LAB_10011a84;
  if (param_5 == (uint *)0x0) {
    dwErrCode = 0x57;
    goto LAB_10011a84;
  }
  if (0x13 < param_3) {
    if (param_3 == 0x23) {
      if (*(int *)(local_28[0] + 4) != 0x660d) goto LAB_100116fc;
      if ((param_4 != (int *)0x0) && (3 < *param_5)) {
        *param_5 = 4;
        *param_4 = *(int *)(local_28[0] + 0x78);
        return 1;
      }
      *param_5 = 4;
      if (param_4 == (int *)0x0) {
        return 1;
      }
      dwErrCode = 0xea;
    }
    else {
switchD_10011650_default:
      dwErrCode = 0x8009000a;
    }
    goto LAB_10011a84;
  }
  if (param_3 == 0x13) {
    iVar2 = *(int *)(local_28[0] + 4);
    if (((iVar2 == 0x6602) || (iVar2 == 0x6601)) || ((iVar2 == 0x6603 || (iVar2 == 0x6609)))) {
      if ((param_4 != (int *)0x0) && (3 < *param_5)) {
        *param_5 = 4;
        iVar2 = *(int *)(local_28[0] + 4);
        if (iVar2 == 0x6601) {
          iVar2 = 0x38;
LAB_10011a14:
          *param_4 = iVar2;
          return 1;
        }
        if (iVar2 == 0x6602) {
          iVar2 = *(int *)(local_28[0] + 0x74);
        }
        else {
          if (iVar2 == 0x6603) {
            iVar2 = 0xa8;
            goto LAB_10011a14;
          }
          if (iVar2 != 0x6609) {
            return 1;
          }
          iVar2 = 0x70;
        }
        *param_4 = iVar2;
        return 1;
      }
      goto LAB_1001176c;
    }
LAB_100116fc:
    dwErrCode = 0x80090003;
    goto LAB_10011a84;
  }
  switch(param_3) {
  case 1:
    if ((param_4 != (int *)0x0) && (*(uint *)(local_28[0] + 0x84) <= *param_5)) {
      memcpy(param_4,(void *)(local_28[0] + 0x24),*(uint *)(local_28[0] + 0x84));
      uVar3 = *(uint *)(local_28[0] + 0x84);
LAB_10011698:
      *param_5 = uVar3;
      return 1;
    }
    uVar3 = *(uint *)(local_28[0] + 0x84);
    goto LAB_100116a4;
  case 2:
    iVar2 = *(int *)(local_28[0] + 4);
    if ((iVar2 != 0x6602) && (iVar2 != 0x6801)) {
      if ((iVar2 == 0x6601) || ((iVar2 == 0x6603 || (iVar2 == 0x6609)))) {
        *param_5 = 0;
        return 1;
      }
      goto LAB_100116fc;
    }
    if ((param_4 != (int *)0x0) && (*(uint *)(local_28[0] + 0x48) <= *param_5)) {
      memcpy(param_4,(void *)(local_28[0] + 0x4c),*(uint *)(local_28[0] + 0x48));
      uVar3 = *(uint *)(local_28[0] + 0x48);
      goto LAB_10011698;
    }
    uVar3 = *(uint *)(local_28[0] + 0x48);
LAB_100116a4:
    *param_5 = uVar3;
    goto LAB_100116a8;
  case 3:
    if ((param_4 != (int *)0x0) && (3 < *param_5)) {
      *param_4 = 1;
      goto LAB_10011764;
    }
    break;
  case 4:
    if ((param_4 != (int *)0x0) && (3 < *param_5)) {
      iVar2 = *(int *)(local_28[0] + 0x68);
LAB_10011794:
      *param_4 = iVar2;
LAB_10011764:
      *param_5 = 4;
      return 1;
    }
    break;
  case 5:
    if ((param_4 != (int *)0x0) && (3 < *param_5)) {
      iVar2 = *(int *)(local_28[0] + 0x6c);
      goto LAB_10011794;
    }
    break;
  case 6:
    if ((param_4 != (int *)0x0) && (3 < *param_5)) {
      iVar2 = *(int *)(local_28[0] + 0x70);
      goto LAB_10011794;
    }
    break;
  case 7:
    if ((param_4 != (int *)0x0) && (3 < *param_5)) {
      iVar2 = *(int *)(local_28[0] + 4);
      goto LAB_10011794;
    }
    break;
  case 8:
    if ((param_4 != (int *)0x0) && (3 < *param_5)) {
      cVar1 = *(char *)((param_2 ^ 0xe35a172c) + 4);
      if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
LAB_100118a0:
        if (*(int *)(local_28[0] + 0x10) == 0) {
          dwErrCode = 0x8009000d;
          goto LAB_10011a84;
        }
        iVar2 = *(int *)(*(int *)(local_28[0] + 0x10) + 8);
      }
      else {
        uVar3 = *(uint *)(local_28[0] + 4);
        if (uVar3 == 0x6601) {
LAB_10011894:
          iVar2 = 0x40;
          goto LAB_10011898;
        }
        if (uVar3 != 0x6602) {
          if ((uVar3 == 0x6603) || (uVar3 == 0x6609)) goto LAB_10011894;
          if (uVar3 != 0x660d) {
            if ((uVar3 < 0x660e) || (0x6610 < uVar3)) {
              *param_4 = 0;
              goto LAB_10011764;
            }
            iVar2 = *(int *)(local_28[0] + 0x84) << 3;
            goto LAB_10011794;
          }
        }
        iVar2 = 0x40;
      }
LAB_100118c0:
      *param_4 = iVar2;
      goto LAB_10011764;
    }
    break;
  case 9:
    if ((param_4 != (int *)0x0) && (3 < *param_5)) {
      cVar1 = *(char *)((param_2 ^ 0xe35a172c) + 4);
      if ((cVar1 == '\x03') || (cVar1 == '\x04')) goto LAB_100118a0;
      iVar2 = *(int *)(local_28[0] + 4);
      if (iVar2 == 0x6601) goto LAB_10011894;
      if (iVar2 == 0x6603) {
        iVar2 = 0xc0;
        goto LAB_100118c0;
      }
      if (iVar2 == 0x6609) {
        *param_4 = 0x80;
        goto LAB_10011764;
      }
      iVar2 = *(int *)(local_28[0] + 0xc) << 3;
LAB_10011898:
      *param_4 = iVar2;
      goto LAB_10011764;
    }
    break;
  default:
    goto switchD_10011650_default;
  }
LAB_1001176c:
  *param_5 = 4;
LAB_100116a8:
  if (param_4 != (int *)0x0) {
    dwErrCode = 0xea;
LAB_10011a84:
    uVar4 = 0;
    SetLastError(dwErrCode);
  }
  return uVar4;
}



/* 10011ac4 FUN_10011ac4 */

/* Boundary evidence: original MIPS .pdata 10011ac4..10011b83. Semantic name remains unreviewed. */

undefined4 FUN_10011ac4(int param_1,int param_2)

{
  wchar_t *lpValueName;
  wchar_t *lpValueName_00;
  wchar_t *lpValueName_01;
  
  if (param_2 == 2) {
    lpValueName_00 = L"SExport";
    lpValueName = L"SPvK";
    lpValueName_01 = L"SPbK";
  }
  else {
    if (param_2 != 1) {
      return 0x80090005;
    }
    lpValueName_00 = L"EExport";
    lpValueName = L"EPvK";
    lpValueName_01 = L"EPbK";
  }
  RegDeleteValueW(*(HKEY *)(param_1 + 0x78),lpValueName);
  RegDeleteValueW(*(HKEY *)(param_1 + 0x78),lpValueName_01);
  RegDeleteValueW(*(HKEY *)(param_1 + 0x78),lpValueName_00);
  return 0;
}



/* 10011b84 CPGetProvParam */

/* Boundary evidence: original MIPS .pdata 10011b84..1001211b. Semantic name remains unreviewed. */

undefined4 CPGetProvParam(uint param_1,undefined4 param_2,LPWSTR param_3,uint *param_4,uint param_5)

{
  uint *puVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  DWORD dwErrCode;
  wchar_t *_Str;
  uint *puVar6;
  uint local_28 [2];
  
                    /* 0x11b84  24  CPGetProvParam */
  puVar1 = (uint *)FUN_100091fc(param_1,0);
  if (puVar1 == (uint *)0x0) {
    dwErrCode = 0x80090001;
    goto LAB_100120e0;
  }
  if (param_4 == (uint *)0x0) {
    dwErrCode = 0x57;
    goto LAB_100120e0;
  }
  switch(param_2) {
  case 1:
    if ((param_5 & 0xfffffffc) == 0) {
      puVar5 = (&PTR_DAT_1002d7f4)[puVar1[0x2e]];
      if ((param_5 & 1) == 0) {
        if (puVar1[5] == 0xffffffff) break;
      }
      else {
        puVar1[5] = 0;
      }
      if (*(int *)(puVar5 + puVar1[5] * 0x94) != 0) {
        if ((param_3 != (LPWSTR)0x0) && (0x33 < *param_4)) {
          *(int *)param_3 = *(int *)(puVar5 + puVar1[5] * 0x94);
          *(undefined4 *)(param_3 + 2) = *(undefined4 *)(puVar5 + puVar1[5] * 0x94 + 4);
          *(undefined4 *)(param_3 + 4) = *(undefined4 *)(puVar5 + puVar1[5] * 0x94 + 0x14);
          memcpy(param_3 + 6,puVar5 + puVar1[5] * 0x94 + 0x18,0x28);
          *param_4 = 0x34;
          puVar1[5] = puVar1[5] + 1;
          return 1;
        }
        sVar2 = 0x34;
        goto LAB_10011d70;
      }
LAB_10011ce0:
      dwErrCode = 0x103;
      goto LAB_100120e0;
    }
    break;
  case 2:
    uVar4 = *puVar1;
    if ((param_5 & 0xfffffffc) == 0) {
      puVar6 = puVar1 + 0x19;
      if ((param_5 & 1) == 0) {
        if (*puVar6 == 0) break;
      }
      else {
        if ((HLOCAL)*puVar6 != (HLOCAL)0x0) {
          FUN_1002afa8((HLOCAL)*puVar6);
        }
        *puVar6 = 0;
        dwErrCode = FUN_1002af18(uVar4 & 0x20,(wchar_t *)puVar1[0x2f],puVar6);
        if (dwErrCode != 0) goto LAB_100120e0;
      }
      local_28[0] = *param_4 >> 1;
      dwErrCode = FUN_1002afcc((undefined4 *)*puVar6,param_3,local_28);
      if (dwErrCode == 0) {
        *param_4 = local_28[0] << 1;
        return 1;
      }
      if (dwErrCode == 0x103) {
        FUN_1002afa8((HLOCAL)*puVar6);
        *puVar6 = 0;
      }
      goto LAB_100120d8;
    }
    break;
  case 3:
    if (param_5 == 0) {
      uVar4 = 2;
LAB_10012088:
      if ((param_3 != (LPWSTR)0x0) && (3 < *param_4)) {
        *(uint *)param_3 = uVar4;
        *param_4 = 4;
        return 1;
      }
      *param_4 = 4;
LAB_10011d74:
      if (param_3 == (LPWSTR)0x0) {
        return 1;
      }
      dwErrCode = 0xea;
      goto LAB_100120e0;
    }
    break;
  case 4:
    if (param_5 == 0) {
      if ((wchar_t *)puVar1[0x2f] == (wchar_t *)0x0) {
        sVar2 = 0;
      }
      else {
        sVar2 = wcslen((wchar_t *)puVar1[0x2f]);
        sVar2 = (sVar2 + 1) * 2;
      }
      if ((param_3 != (LPWSTR)0x0) && (sVar2 <= *param_4)) {
        *param_4 = sVar2;
        _Str = (wchar_t *)puVar1[0x2f];
LAB_10011f64:
        memcpy(param_3,_Str,sVar2);
        return 1;
      }
LAB_10011d70:
      *param_4 = sVar2;
      goto LAB_10011d74;
    }
    break;
  case 5:
    if (param_5 == 0) {
      uVar4 = 0x200;
      goto LAB_10012088;
    }
    break;
  case 6:
    if (param_5 == 0) {
      _Str = (wchar_t *)puVar1[0x17];
      sVar2 = wcslen(_Str);
      sVar2 = (sVar2 + 1) * 2;
      if ((param_3 != (LPWSTR)0x0) && (sVar2 <= *param_4)) {
        *param_4 = sVar2;
        goto LAB_10011f64;
      }
      *param_4 = sVar2;
      goto LAB_10011d74;
    }
    break;
  default:
    dwErrCode = 0x8009000a;
LAB_100120d8:
    if (dwErrCode == 0) {
      return 1;
    }
    goto LAB_100120e0;
  case 0x10:
    if (param_5 == 0) {
      uVar4 = puVar1[1];
      goto LAB_10012088;
    }
    break;
  case 0x11:
    if (param_5 == 0) {
LAB_10011fe0:
      uVar4 = 0;
      goto LAB_10012088;
    }
    break;
  case 0x16:
    if ((param_5 & 0xfffffffc) == 0) {
      puVar5 = (&PTR_DAT_1002d7f4)[puVar1[0x2e]];
      if ((param_5 & 1) == 0) {
        if (puVar1[6] == 0xffffffff) break;
      }
      else {
        puVar1[6] = 0;
      }
      if (*(int *)(puVar5 + puVar1[6] * 0x94) != 0) {
        if ((param_3 != (LPWSTR)0x0) && (0x93 < *param_4)) {
          memcpy(param_3,puVar5 + puVar1[6] * 0x94,0x94);
          *param_4 = 0x94;
          puVar1[6] = puVar1[6] + 1;
          return 1;
        }
        *param_4 = 0x94;
        goto LAB_10011d74;
      }
      goto LAB_10011ce0;
    }
    break;
  case 0x1b:
    if (param_5 == 0) {
      if ((*puVar1 & 0x20) == 0) goto LAB_10011fe0;
      uVar4 = 0x20;
      goto LAB_10012088;
    }
    break;
  case 0x22:
  case 0x23:
    if (param_5 == 0) {
      uVar4 = 8;
      goto LAB_10012088;
    }
    break;
  case 0x27:
    if (param_5 == 0) {
      uVar3 = puVar1[1];
      uVar4 = 2;
      if (uVar3 != 2) {
        if (uVar3 == 1) {
          uVar4 = 3;
        }
        else if (uVar3 == 0xc) {
          uVar4 = 1;
        }
        else {
          uVar4 = local_28[0];
          if (uVar3 == 0x18) {
            param_3[0] = L'\x03';
            param_3[1] = L'\0';
          }
        }
      }
      goto LAB_10012088;
    }
    break;
  case 0x28:
    if (param_5 == 0) {
      *param_4 = 0;
      return 1;
    }
  }
  dwErrCode = 0x80090009;
LAB_100120e0:
  SetLastError(dwErrCode);
  return 0;
}



/* 1001211c FUN_1001211c */

/* Boundary evidence: original MIPS .pdata 1001211c..1001228f. Semantic name remains unreviewed. */

undefined4 FUN_1001211c(void *param_1,undefined4 *param_2)

{
  HLOCAL _Dst;
  HLOCAL pvVar1;
  int iVar2;
  uint uBytes;
  undefined4 uVar3;
  
  uBytes = 0x94;
  if (*(int *)((int)param_1 + 0xc) != 0) {
    uBytes = *(int *)((int)param_1 + 0xc) + 0x98;
  }
  if (*(int *)((int)param_1 + 0x20) != 0) {
    uBytes = *(int *)((int)param_1 + 0x18) + uBytes + 4;
  }
  if ((uBytes < 0x94) || (_Dst = LocalAlloc(0x40,uBytes), _Dst == (HLOCAL)0x0)) {
    return 8;
  }
  memset(_Dst,0,uBytes);
  memcpy(_Dst,param_1,0x94);
  *(uint *)((int)_Dst + 8) = *(uint *)((int)_Dst + 8) & 0xffffbfff;
  *(uint *)((int)_Dst + 0x70) = *(uint *)((int)_Dst + 0x70) & 0xfffffeff;
  iVar2 = 0x98;
  if (*(size_t *)((int)_Dst + 0xc) != 0) {
    *(void **)((int)_Dst + 0x10) = (void *)((int)_Dst + 0x98);
    memcpy((void *)((int)_Dst + 0x98),*(void **)((int)param_1 + 0x10),*(size_t *)((int)_Dst + 0xc));
    iVar2 = (*(int *)((int)_Dst + 0xc) + 4U & 0xfffffffc) + 0x98;
  }
  if (*(int *)((int)_Dst + 0x20) == 0) {
    if (*(SIZE_T *)((int)_Dst + 0x18) != 0) {
      pvVar1 = LocalAlloc(0x40,*(SIZE_T *)((int)_Dst + 0x18));
      *(HLOCAL *)((int)_Dst + 0x1c) = pvVar1;
      if (pvVar1 == (HLOCAL)0x0) {
        uVar3 = 8;
        goto LAB_1001223c;
      }
    }
  }
  else {
    *(int *)((int)_Dst + 0x1c) = iVar2 + (int)_Dst;
  }
  memcpy(*(void **)((int)_Dst + 0x1c),*(void **)((int)param_1 + 0x1c),*(size_t *)((int)_Dst + 0x18))
  ;
  *param_2 = _Dst;
  _Dst = (HLOCAL)0x0;
  uVar3 = 0;
LAB_1001223c:
  if (_Dst != (HLOCAL)0x0) {
    FUN_100104a8(_Dst);
  }
  return uVar3;
}



/* 10012290 CPDuplicateKey */

/* Boundary evidence: original MIPS .pdata 10012290..100123b3. Semantic name remains unreviewed. */

undefined4 CPDuplicateKey(int param_1,uint param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  DWORD dwErrCode;
  HLOCAL pvVar2;
  undefined4 uVar3;
  void *local_20;
  HLOCAL local_1c;
  
                    /* 0x12290  17  CPDuplicateKey */
  pvVar2 = (HLOCAL)0x0;
  local_1c = (HLOCAL)0x0;
  uVar3 = 2;
  if (param_3 == 0) {
    if (param_4 == 0) {
      iVar1 = FUN_10009224(param_2,param_1,2,&local_20);
      if (iVar1 != 0) {
        uVar3 = 3;
        iVar1 = FUN_10009224(param_2,param_1,3,&local_20);
        if (iVar1 != 0) {
          uVar3 = 4;
          dwErrCode = FUN_10009224(param_2,param_1,4,&local_20);
          if (dwErrCode != 0) goto LAB_100122c4;
        }
      }
      dwErrCode = FUN_1001211c(local_20,&local_1c);
      pvVar2 = local_1c;
      if ((dwErrCode == 0) && (dwErrCode = FUN_100092e4(param_5,uVar3,local_1c), dwErrCode == 0)) {
        return 1;
      }
    }
    else {
      dwErrCode = 0x80090009;
    }
  }
  else {
    dwErrCode = 0x57;
  }
LAB_100122c4:
  if (pvVar2 != (HLOCAL)0x0) {
    FUN_100104a8(pvVar2);
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 100123b4 FUN_100123b4 */

/* Boundary evidence: original MIPS .pdata 100123b4..100128af. Semantic name remains unreviewed. */

undefined4
FUN_100123b4(uint param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,uint *param_6,
            int param_7,int param_8)

{
  uint *hMem;
  int iVar1;
  uint *_Src;
  byte *pbVar2;
  uint uVar3;
  undefined4 uVar4;
  uint local_50 [4];
  uint local_40 [4];
  uint local_30;
  
  local_30 = DAT_1002da44;
  memset(local_40,0,0x10);
  memset(local_50,0,0x10);
  if (0x10 < param_5) {
    uVar4 = 0x80090004;
    goto LAB_10012874;
  }
  if (param_1 < 0x660f) {
    if (param_1 == 0x660e) {
      hMem = LocalAlloc(0x40,0x1e4);
      if (hMem != (uint *)0x0) {
        iVar1 = 10;
        goto LAB_10012620;
      }
      goto LAB_100125f4;
    }
    if (param_1 == 0x6601) {
      hMem = LocalAlloc(0x40,0x80);
      if (hMem == (uint *)0x0) goto LAB_100125f4;
      FUN_1001e884((int)param_2,param_3);
      deskey(hMem,param_2);
    }
    else if (param_1 == 0x6602) {
      hMem = LocalAlloc(0x40,0x80);
      if (hMem == (uint *)0x0) goto LAB_100125f4;
      RC2KeyEx(hMem,param_2,param_3,param_3 << 3);
    }
    else if (param_1 == 0x6603) {
      hMem = LocalAlloc(0x40,0x180);
      if (hMem == (uint *)0x0) goto LAB_100125f4;
      FUN_1001e884((int)param_2,param_3);
      tripledes3key(hMem,param_2);
    }
    else {
      if (param_1 != 0x6609) goto LAB_100125a0;
      hMem = LocalAlloc(0x40,0x180);
      if (hMem == (uint *)0x0) goto LAB_100125f4;
      FUN_1001e884((int)param_2,param_3);
      FUN_1001e8ec(hMem,param_2);
    }
LAB_1001262c:
    if ((((param_8 == 1) && (param_1 != 0x6801)) && (memcpy(local_40,param_4,param_5), param_7 != 0)
        ) && (uVar3 = 0, param_5 != 0)) {
      do {
        pbVar2 = (byte *)((int)local_40 + uVar3);
        uVar3 = uVar3 + 1;
        *pbVar2 = pbVar2[param_7 - (int)local_40] ^ *pbVar2;
      } while (uVar3 < param_5);
    }
    if (param_1 == 0x6601) {
      if (param_8 != 1) {
        des(local_50,param_6,(int)hMem,0);
        goto LAB_100127ec;
      }
      des(local_50,local_40,(int)hMem,1);
LAB_10012840:
      iVar1 = memcmp(param_6,local_50,param_5);
      if (iVar1 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0x80090020;
      }
    }
    else {
      if (param_1 == 0x6602) {
        if (param_8 != 1) {
          RC2((undefined1 *)local_50,(ushort *)param_6,(ushort *)hMem,0);
          goto LAB_100127ec;
        }
        RC2((undefined1 *)local_50,(ushort *)local_40,(ushort *)hMem,1);
        goto LAB_10012840;
      }
      if ((param_1 == 0x6603) || (param_1 == 0x6609)) {
        if (param_8 != 1) {
          tripledes(local_50,param_6,(int)hMem,0);
          goto LAB_100127ec;
        }
        tripledes(local_50,local_40,(int)hMem,1);
        goto LAB_10012840;
      }
      if (0x660d < param_1) {
        if (param_1 < 0x6611) {
          if (param_8 == 1) {
            FUN_100256dc(local_50,local_40,(int *)hMem,1);
            goto LAB_10012840;
          }
          FUN_100256dc(local_50,param_6,(int *)hMem,0);
        }
        else {
          if (param_1 != 0x6801) goto LAB_1001274c;
          _Src = param_4;
          if (param_8 != 1) {
            _Src = param_6;
          }
          memcpy(local_50,_Src,param_5);
          rc4((int)hMem,param_5,(byte *)local_50);
        }
LAB_100127ec:
        if (((param_8 != 1) && (param_6 = param_4, param_7 != 0)) && (uVar3 = 0, param_5 != 0)) {
          do {
            pbVar2 = (byte *)((int)local_50 + uVar3);
            uVar3 = uVar3 + 1;
            *pbVar2 = pbVar2[param_7 - (int)local_50] ^ *pbVar2;
          } while (uVar3 < param_5);
        }
        goto LAB_10012840;
      }
LAB_1001274c:
      uVar4 = 0x80090008;
    }
  }
  else {
    if (param_1 == 0x660f) {
      hMem = LocalAlloc(0x40,0x1e4);
      if (hMem != (uint *)0x0) {
        iVar1 = 0xc;
LAB_10012620:
        FUN_10025728((int *)hMem,(int)param_2,iVar1);
        goto LAB_1001262c;
      }
    }
    else if (param_1 == 0x6610) {
      hMem = LocalAlloc(0x40,0x1e4);
      if (hMem != (uint *)0x0) {
        iVar1 = 0xe;
        goto LAB_10012620;
      }
    }
    else {
      if (param_1 != 0x6801) {
LAB_100125a0:
        uVar4 = 0x80090008;
        goto LAB_10012874;
      }
      hMem = LocalAlloc(0x40,0x102);
      if (hMem != (uint *)0x0) {
        rc4_key((int *)hMem,param_3,(int)param_2);
        goto LAB_1001262c;
      }
    }
LAB_100125f4:
    uVar4 = 8;
  }
  if (hMem != (uint *)0x0) {
    LocalFree(hMem);
  }
LAB_10012874:
  FUN_1002bedc(local_30);
  return uVar4;
}



/* 100128b0 FUN_100128b0 */

/* Boundary evidence: original MIPS .pdata 100128b0..1001296b. Semantic name remains unreviewed. */

void FUN_100128b0(uint param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,uint *param_6,
                 int param_7)

{
  int iVar1;
  
  iVar1 = FUN_100123b4(param_1,param_2,param_3,param_4,param_5,param_6,param_7,1);
  if (iVar1 == 0) {
    FUN_100123b4(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  }
  return;
}



/* 1001296c FUN_1001296c */

/* Boundary evidence: original MIPS .pdata 1001296c..10012a1f. Semantic name remains unreviewed. */

DWORD FUN_1001296c(uint param_1,uint param_2)

{
  int iVar1;
  DWORD DVar2;
  uint local_28;
  undefined1 *local_24;
  undefined1 auStack_20 [12];
  uint local_14;
  
  local_14 = DAT_1002da44;
  memset(auStack_20,0,0xb);
  local_24 = auStack_20;
  local_28 = 0xb;
  iVar1 = CPSetKeyParam(param_1,param_2,10,&local_28,0);
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    FUN_1002bedc(local_14);
  }
  else {
    FUN_1002bedc(local_14);
    DVar2 = 0;
  }
  return DVar2;
}



/* 10012a20 FUN_10012a20 */

/* Boundary evidence: original MIPS .pdata 10012a20..10012aa7. Semantic name remains unreviewed. */

void FUN_10012a20(undefined4 *param_1,void *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1001211c(param_2,param_3);
  if (iVar1 == 0) {
    *(int *)(*param_3 + 0x48) = *(int *)(*param_3 + 0x48) + 8;
    iVar1 = *(int *)(*param_3 + 0x48) + *param_3;
    *(undefined4 *)(iVar1 + 0x44) = *param_1;
    *(undefined4 *)(iVar1 + 0x48) = param_1[1];
    FUN_10010c04(*param_3);
  }
  return;
}



/* 10012aa8 FUN_10012aa8 */

/* Boundary evidence: original MIPS .pdata 10012aa8..10012faf. Semantic name remains unreviewed. */

int FUN_10012aa8(int param_1,int param_2,void *param_3,int param_4,uint *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  size_t _Size;
  HLOCAL pvVar7;
  uint uVar8;
  uint local_a8;
  HLOCAL local_a4;
  undefined4 local_a0;
  uint local_9c;
  uint local_98 [14];
  undefined4 local_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [44];
  uint local_2c;
  
  local_2c = DAT_1002da44;
  pvVar7 = (HLOCAL)0x0;
  local_a8 = 0;
  local_a4 = (HLOCAL)0x0;
  uVar8 = 0;
  bVar1 = false;
  memset(local_98,0,0x31);
  memset(&local_60,0,0x31);
  memset(&local_a0,0,8);
  iVar3 = *(int *)(param_2 + 4);
  if (((((iVar3 != 0x6801) && (iVar3 != 0x6602)) && (iVar3 != 0x6601)) &&
      ((iVar3 != 0x6603 && (iVar3 != 0x6609)))) &&
     ((iVar3 != 0x660e && ((iVar3 != 0x660f && (iVar3 != 0x6610)))))) {
LAB_10012bdc:
    iVar3 = -0x7ff6fffd;
    goto LAB_10012f74;
  }
  iVar2 = *(int *)((int)param_3 + 4);
  if ((iVar2 == 0x6801) ||
     ((((iVar2 == 0x6602 || (iVar2 == 0x6601)) || (iVar2 == 0x6603)) || (iVar2 == 0x6609)))) {
LAB_10012be8:
    if ((((iVar2 == 0x660e) || ((iVar2 == 0x660f || (iVar2 == 0x6610)))) || (iVar3 == 0x660e)) ||
       ((iVar3 == 0x660f || (iVar3 == 0x6610)))) goto LAB_10012f54;
    iVar3 = FUN_10010610(param_1,param_2,0);
    if ((iVar3 == 0) || (iVar3 = FUN_10010610(param_1,(int)param_3,0), iVar3 == 0))
    goto LAB_10012bdc;
    if ((*(int *)((int)param_3 + 0x8c) == 0) && (iVar3 = FUN_10010c04((int)param_3), iVar3 != 0))
    goto LAB_10012f74;
    if ((*(int *)(param_2 + 4) == 0x6801) || (*(int *)(param_2 + 4) == 0x6602)) {
      iVar3 = *(int *)(param_2 + 0xc);
      uVar8 = 8 - (iVar3 + 1U & 7);
      local_a8 = local_a8 + 1;
      local_98[0]._0_1_ = (undefined1)iVar3;
      iVar3 = iVar3 + uVar8 + 0x11;
    }
    else {
      iVar3 = *(int *)(param_2 + 0xc) + 0x10;
    }
    uVar5 = local_a8;
    if (param_4 == 0) {
      *param_5 = iVar3 + 0xc;
      iVar3 = 0;
      goto LAB_10012f74;
    }
    if (*param_5 < iVar3 + 0xcU) {
      *param_5 = iVar3 + 0xcU;
      iVar3 = 0xea;
      goto LAB_10012f74;
    }
    _Size = *(size_t *)(param_2 + 0xc);
    memcpy((void *)((int)local_98 + local_a8),*(void **)(param_2 + 0x10),_Size);
    local_a8 = _Size + uVar5;
    if (uVar8 != 0) {
      iVar3 = FUN_10016a48((undefined4 *)(param_1 + 0x9c),(int *)(param_1 + 0x58),
                           (uint *)(param_1 + 0x38),(void *)((int)local_98 + local_a8),uVar8);
      if (iVar3 != 0) goto LAB_10012f74;
      local_a8 = uVar8 + local_a8;
    }
    FUN_100108f0(local_98,local_a8,(undefined4 *)((int)local_98 + local_a8));
    local_a8 = local_a8 + 8;
    iVar3 = FUN_10016a48((undefined4 *)(param_1 + 0x9c),(int *)(param_1 + 0x58),
                         (uint *)(param_1 + 0x38),&local_a0,8);
    if (iVar3 != 0) goto LAB_10012f74;
    if (*(int *)((int)param_3 + 4) == 0x6801) {
      iVar3 = FUN_10012a20(&local_a0,param_3,(int *)&local_a4);
      if (iVar3 != 0) goto LAB_10012f74;
      bVar1 = true;
    }
    else {
      *(undefined4 *)((int)param_3 + 0x24) = local_a0;
      *(uint *)((int)param_3 + 0x28) = local_9c;
      *(undefined4 *)((int)param_3 + 0x44) = 0;
      local_a4 = param_3;
    }
    pvVar7 = local_a4;
    iVar3 = FUN_1000f5ec((int)local_a4,0,local_98,&local_a8,local_a8);
    uVar8 = local_a8;
    if (iVar3 == 0) {
      puVar6 = auStack_5c + 3;
      uVar5 = (uint)puVar6 & 3;
      *(uint *)(puVar6 + -uVar5) =
           *(uint *)(puVar6 + -uVar5) & -1 << (uVar5 + 1) * 8 | local_9c >> (3 - uVar5) * 8;
      local_60 = local_a0;
      auStack_5c = (undefined1  [4])local_9c;
      memcpy(auStack_58,local_98,local_a8);
      local_a8 = uVar8 + 8;
      uVar5 = 0;
      if (local_a8 != 0) {
        puVar6 = auStack_58 + (uVar8 - 1);
        do {
          puVar4 = (undefined1 *)((int)local_98 + uVar5);
          uVar5 = uVar5 + 1;
          *puVar4 = *puVar6;
          puVar6 = puVar6 + -1;
        } while (uVar5 < local_a8);
      }
      if (*(int *)((int)param_3 + 4) == 0x6801) {
        if ((bVar1) && (pvVar7 != (HLOCAL)0x0)) {
          FUN_100104a8(pvVar7);
          local_a4 = (HLOCAL)0x0;
          bVar1 = false;
        }
        iVar3 = FUN_10012a20(&DAT_1002d7ec,param_3,(int *)&local_a4);
        pvVar7 = local_a4;
        if (iVar3 != 0) goto LAB_10012f5c;
        bVar1 = true;
      }
      else {
        *(undefined4 *)((int)param_3 + 0x24) = DAT_1002d7ec;
        *(undefined4 *)((int)param_3 + 0x28) = DAT_1002d7f0;
        *(undefined4 *)((int)param_3 + 0x44) = 0;
      }
      iVar3 = FUN_1000f5ec((int)pvVar7,0,local_98,&local_a8,local_a8);
      uVar8 = local_a8;
      if (iVar3 == 0) {
        *(undefined4 *)(param_4 + 4) = *(undefined4 *)(param_2 + 4);
        *(undefined4 *)(param_4 + 8) = *(undefined4 *)((int)param_3 + 4);
        memcpy((void *)(param_4 + 0xc),local_98,local_a8);
        iVar3 = 0;
        *param_5 = uVar8 + 0xc;
      }
    }
  }
  else {
    if (iVar2 != 0x660e) {
      if ((iVar2 != 0x660f) && (iVar2 != 0x6610)) goto LAB_10012bdc;
      goto LAB_10012be8;
    }
LAB_10012f54:
    iVar3 = -0x7ff6fffd;
  }
LAB_10012f5c:
  if ((bVar1) && (pvVar7 != (HLOCAL)0x0)) {
    FUN_100104a8(pvVar7);
  }
LAB_10012f74:
  FUN_1002bedc(local_2c);
  return iVar3;
}



/* 10012fb0 FUN_10012fb0 */

/* Boundary evidence: original MIPS .pdata 10012fb0..10012fff. Semantic name remains unreviewed. */

int * FUN_10012fb0(uint *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (uVar1 < param_3) {
    param_3 = 0;
    param_2 = (int *)0x0;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_2 = uVar1 - param_3;
  return param_2;
}



/* 10013000 FUN_10013000 */

/* Boundary evidence: original MIPS .pdata 10013000..1001304f. Semantic name remains unreviewed. */

uint * FUN_10013000(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *param_1 + param_3;
  if (uVar1 < *param_1) {
    param_2 = (uint *)0x0;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_2 = uVar1;
  return param_2;
}



/* 10013050 FUN_10013050 */

/* Boundary evidence: original MIPS .pdata 10013050..1001309f. Semantic name remains unreviewed. */

uint * FUN_10013050(uint *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *param_1 + param_2;
  if (uVar1 < *param_1) {
    param_1 = (uint *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_1 = uVar1;
  return param_1;
}



/* 100130a0 FUN_100130a0 */

/* Boundary evidence: original MIPS .pdata 100130a0..100130f3. Semantic name remains unreviewed. */

uint * FUN_100130a0(uint *param_1,uint param_2,uint param_3)

{
  if (param_3 == 0) {
    param_3 = 0;
    param_2 = 0;
    param_1 = (uint *)&DAT_c0000094;
    RaiseException(0xc0000094,0,0,(ULONG_PTR *)0x0);
  }
  if (param_3 == 0) {
    trap(0x1c00);
  }
  *param_1 = param_2 % param_3;
  return param_1;
}



/* 100130f4 FUN_100130f4 */

/* Boundary evidence: original MIPS .pdata 100130f4..1001313f. Semantic name remains unreviewed. */

uint * FUN_100130f4(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_2 + param_3;
  if (uVar1 < param_2) {
    param_1 = (uint *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_1 = uVar1;
  return param_1;
}



/* 10013140 FUN_10013140 */

/* Boundary evidence: original MIPS .pdata 10013140..1001318f. Semantic name remains unreviewed. */

uint * FUN_10013140(uint *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *param_1 + param_2;
  if (uVar1 < *param_1) {
    param_1 = (uint *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_1 = uVar1;
  return param_1;
}



/* 10013190 FUN_10013190 */

/* Boundary evidence: original MIPS .pdata 10013190..100131df. Semantic name remains unreviewed. */

uint * FUN_10013190(uint *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *param_1 + param_2;
  if (uVar1 < *param_1) {
    param_1 = (uint *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_1 = uVar1;
  return param_1;
}



/* 100131e0 FUN_100131e0 */

/* Boundary evidence: original MIPS .pdata 100131e0..100134f3. Semantic name remains unreviewed. */

undefined4 FUN_100131e0(int *param_1,int *param_2,size_t *param_3,undefined4 *param_4,uint *param_5)

{
  uint uVar1;
  int *piVar2;
  uint *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  void *_Dst;
  int *_Src;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined1 *_Size;
  uint local_40;
  int *local_3c;
  uint local_38;
  undefined1 *local_34;
  uint local_30;
  uint uStack_2c;
  
  if (*param_1 == 0x32415352) {
    local_40 = 8 - (param_1[1] + 7U >> 3 & 7);
    uVar6 = 1;
    local_3c = param_2;
    if (local_40 != 8) {
      FUN_10013140(&local_40,8);
    }
    uVar1 = local_40;
    _Size = (undefined1 *)(param_1[1] + 0xfU >> 4);
    uVar8 = ((uint)param_1[1] >> 3) + local_40 + 0x14;
    uVar5 = local_40 >> 1;
    local_38 = uVar5;
    local_34 = _Size;
    local_30 = uVar8;
    if (uVar8 < local_40) {
      RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
    }
    puVar4 = _Size + uVar5;
    if (puVar4 < _Size) {
      puVar4 = &DAT_c0000095;
      RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
    }
    local_40 = FUN_1000a9f4((uint)puVar4,10);
    puVar3 = FUN_1000ab10(&local_40,&uStack_2c,0x14);
    uVar5 = *puVar3;
    if ((param_2 == (int *)0x0) || (param_4 == (undefined4 *)0x0)) {
      *param_5 = uVar8;
    }
    else if ((*param_5 < uVar8) || (*param_3 < uVar5)) {
      *param_5 = uVar8;
      uVar6 = 0;
    }
    else {
      memset(param_4,0,*param_5);
      *param_4 = 0x31415352;
      _Src = param_1 + 3;
      param_4[2] = param_1[1];
      param_4[1] = ((uint)param_1[1] >> 3) + uVar1;
      param_4[3] = (param_1[1] + 7U >> 3) - 1;
      param_4[4] = param_1[2];
      memcpy(param_4 + 5,_Src,(uint)param_1[1] >> 3);
      piVar2 = local_3c;
      memset(local_3c,0,*param_3);
      *piVar2 = *param_1;
      piVar2[1] = param_4[1];
      piVar2[2] = param_1[1];
      piVar2[3] = param_4[3];
      piVar2[4] = param_1[2];
      memcpy(piVar2 + 5,_Src,(uint)param_1[1] >> 3);
      uVar8 = local_38;
      _Dst = (void *)(((uint)param_1[1] >> 3) + uVar1 + (int)(piVar2 + 5));
      puVar4 = (undefined1 *)(((uint)param_1[1] >> 3) + (int)_Src);
      iVar7 = 5;
      do {
        memcpy(_Dst,puVar4,(size_t)_Size);
        puVar3 = FUN_10013000((uint *)&local_34,&uStack_2c,uVar8);
        puVar4 = _Size + (int)puVar4;
        iVar7 = iVar7 + -1;
        _Dst = (void *)(*puVar3 + (int)_Dst);
      } while (iVar7 != 0);
      memcpy(_Dst,puVar4,(uint)param_1[1] >> 3);
      *param_5 = local_30;
    }
    *param_3 = uVar5;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}



/* 100134f4 FUN_100134f4 */

/* Boundary evidence: original MIPS .pdata 100134f4..1001353f. Semantic name remains unreviewed. */

uint * FUN_100134f4(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_3 + param_2;
  if (uVar1 < param_3) {
    param_1 = (uint *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_1 = uVar1;
  return param_1;
}



/* 10013540 FUN_10013540 */

/* Boundary evidence: original MIPS .pdata 10013540..10013897. Semantic name remains unreviewed. */

undefined4
FUN_10013540(uint param_1,uint param_2,size_t param_3,uint param_4,void *param_5,int param_6,
            int param_7,undefined4 *param_8)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  SIZE_T uBytes;
  uint local_30;
  uint local_2c;
  
  uBytes = 0x94;
  local_30 = 0x94;
  local_2c = 0;
  iVar1 = FUN_100091fc(param_4,0);
  if (iVar1 == 0) {
    return 0x80090001;
  }
  *param_8 = 0;
  FUN_100103f4(param_1,&local_2c);
  uVar4 = local_2c;
  if (local_2c != 0) {
    puVar2 = FUN_100134f4(&local_2c,4,local_2c);
    FUN_10013050(&local_30,*puVar2);
    uBytes = local_30;
  }
  if (param_6 == 0) {
    puVar2 = FUN_100134f4(&local_2c,4,param_3);
    FUN_10013050(&local_30,*puVar2);
    uBytes = local_30;
  }
  puVar2 = LocalAlloc(0x40,uBytes);
  if (puVar2 == (uint *)0x0) {
    uVar5 = 8;
    goto LAB_10013814;
  }
  memset(puVar2,0,uBytes);
  iVar3 = 0x98;
  if (uVar4 != 0) {
    puVar2[7] = (uint)(puVar2 + 0x26);
    puVar2[6] = uVar4;
    iVar3 = (uVar4 + 4 & 0xfffffffc) + 0x98;
    puVar2[8] = 1;
  }
  if (param_6 == 0) {
    puVar2[4] = (uint)(iVar3 + (int)puVar2);
    if (param_5 != (void *)0x0) {
      memcpy((void *)(iVar3 + (int)puVar2),param_5,param_3);
    }
    puVar2[5] = 1;
  }
  else {
    puVar2[4] = (uint)param_5;
  }
  puVar2[0x22] = uBytes;
  puVar2[1] = param_1;
  puVar2[2] = param_2;
  *puVar2 = param_4;
  puVar2[0x19] = 1;
  puVar2[0x1a] = 1;
  puVar2[0x1e] = 0;
  if (param_2 == 1) {
    puVar2[0x1c] = puVar2[0x1c] | 4;
  }
  puVar2[3] = param_3;
  puVar2[0x1c] = puVar2[0x1c] | 0x3b;
  switch(param_1) {
  case 0x6601:
    if (param_3 == 8) {
      if (param_7 == 0) {
        FUN_1001e884(puVar2[4],8);
      }
      puVar2[0x21] = 8;
      break;
    }
    goto LAB_1001380c;
  case 0x6602:
    uVar4 = 0x28;
    if (*(int *)(iVar1 + 0xb8) != 0) {
      uVar4 = param_3 << 3;
    }
    puVar2[0x1d] = uVar4;
    uVar4 = 8;
    goto LAB_10013788;
  case 0x6603:
    if (param_3 == 0x18) {
      if (param_7 == 0) {
        uVar4 = 0x18;
LAB_100137ec:
        FUN_1001e884(puVar2[4],uVar4);
      }
LAB_100137f4:
      uVar4 = 8;
      goto LAB_100137f8;
    }
    goto LAB_1001380c;
  default:
    puVar2[0x1a] = 0;
    puVar2[0x21] = 0;
    break;
  case 0x6609:
    if (param_3 == 0x10) {
      if (param_7 == 0) {
        uVar4 = 0x10;
        goto LAB_100137ec;
      }
      goto LAB_100137f4;
    }
LAB_1001380c:
    uVar5 = 0x80090009;
LAB_10013814:
    if (puVar2 == (uint *)0x0) {
      return uVar5;
    }
    LocalFree(puVar2);
    return uVar5;
  case 0x660d:
    puVar2[0x1e] = 0x10;
    puVar2[0x21] = 8;
    break;
  case 0x660e:
  case 0x6610:
    uVar4 = 0x10;
LAB_10013788:
    puVar2[0x21] = uVar4;
    break;
  case 0x660f:
    uVar4 = 0x10;
LAB_100137f8:
    puVar2[0x21] = uVar4;
  }
  *param_8 = puVar2;
  return 0;
}



/* 10013898 FUN_10013898 */

/* Boundary evidence: original MIPS .pdata 10013898..10013b4f. Semantic name remains unreviewed. */

undefined4 FUN_10013898(undefined4 *param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  uint _Size;
  uint *puVar2;
  undefined1 *_Dst;
  uint uVar3;
  undefined1 *puVar4;
  void *_Dst_00;
  undefined4 uVar5;
  SIZE_T _Size_00;
  int iVar6;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint uStack_2c;
  
  uVar3 = param_1[2] + 0xf;
  FUN_1000aa40(&local_38,param_2,uVar3,(uint)(uVar3 < (uint)param_1[2]));
  local_3c = local_38 >> 4;
  local_30 = local_3c;
  local_38 = FUN_1000a9f4(local_3c,9);
  FUN_100134f4(&local_38,0xc,local_38);
  local_40 = param_1[2];
  puVar2 = FUN_1000f9e4(&local_40,&uStack_2c,7);
  FUN_1000f968(&local_40,*puVar2,8);
  FUN_100130a0(&local_40,local_40,8);
  local_34 = 8;
  FUN_10012fb0(&local_34,(int *)&local_40,local_40);
  uVar5 = 1;
  if (local_40 != 8) {
    FUN_10013140(&local_40,8);
  }
  uVar3 = local_40;
  FUN_1000f968(&local_40,local_40,2);
  if (param_2 != (undefined4 *)0x0) {
    if (local_38 <= *param_3) {
      *param_2 = *param_1;
      param_2[1] = param_1[2];
      param_2[2] = param_1[4];
      puVar2 = FUN_10013000(&local_3c,&uStack_2c,local_40);
      FUN_1000aa98(&local_34,*puVar2,10);
      FUN_100134f4(&local_34,0x14,local_34);
      _Size_00 = local_34;
      _Dst = LocalAlloc(0x40,local_34);
      if (_Dst == (undefined1 *)0x0) {
        *param_3 = 0;
        return 0;
      }
      memcpy(_Dst,param_1,_Size_00);
      memcpy(param_2 + 3,_Dst + 0x14,(uint)param_2[1] >> 3);
      _Size = local_30;
      uVar1 = local_40;
      puVar4 = _Dst + 0x14 + ((uint)param_2[1] >> 3) + uVar3;
      _Dst_00 = (void *)(((uint)param_2[1] >> 3) + (int)(param_2 + 3));
      iVar6 = 5;
      do {
        memcpy(_Dst_00,puVar4,_Size);
        _Dst_00 = (void *)(_Size + (int)_Dst_00);
        puVar2 = FUN_10013000(&local_3c,&uStack_2c,uVar1);
        iVar6 = iVar6 + -1;
        puVar4 = puVar4 + *puVar2;
      } while (iVar6 != 0);
      memcpy(_Dst_00,puVar4,(uint)param_2[1] >> 3);
      *param_3 = local_38;
      puVar4 = _Dst;
      for (; _Size_00 != 0; _Size_00 = _Size_00 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      LocalFree(_Dst);
      return 1;
    }
    uVar5 = 0;
  }
  *param_3 = local_38;
  return uVar5;
}



/* 10013b50 CPGenKey */

/* Boundary evidence: original MIPS .pdata 10013b50..10013f0f. Semantic name remains unreviewed. */

undefined4 CPGenKey(uint param_1,uint param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  uint *puVar2;
  undefined3 extraout_var;
  uint uVar3;
  DWORD dwErrCode;
  uint uVar4;
  HLOCAL pvVar5;
  size_t sVar6;
  undefined4 uVar7;
  uint local_80;
  HLOCAL local_7c;
  size_t local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint *local_68;
  undefined1 auStack_60 [48];
  uint local_30;
  
                    /* 0x13b50  20  CPGenKey */
  local_30 = DAT_1002da44;
  pvVar5 = (HLOCAL)0x0;
  local_7c = (HLOCAL)0x0;
  local_6c = 0;
  local_74 = 0;
  local_80 = 0;
  local_70 = param_1;
  local_68 = param_4;
  if ((param_3 & 0xbfe8) == 0) {
    uVar7 = 1;
    if (param_2 == 1) {
      uVar4 = 0xa400;
    }
    else if (param_2 == 2) {
      uVar4 = 0x2400;
    }
    else {
      uVar4 = param_2;
      if ((param_3 & 0x4000) != 0) goto LAB_10013bbc;
    }
    puVar2 = (uint *)FUN_100091fc(param_1,0);
    if (puVar2 == (uint *)0x0) {
      dwErrCode = 0x80090001;
    }
    else if (((param_3 & 2) == 0) || ((*puVar2 & 0xf0000000) == 0)) {
      bVar1 = FUN_1001077c((int)puVar2,uVar4);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        dwErrCode = 0x80090008;
      }
      else {
        dwErrCode = FUN_1001085c((int)puVar2,uVar4,param_3,&local_78,&local_74);
        if (dwErrCode == 0) {
          if (local_74 == 0) {
            if (uVar4 == 0x6601) {
              sVar6 = 8;
            }
            else if (uVar4 == 0x6609) {
              sVar6 = 0x10;
            }
            else {
              sVar6 = 0x18;
              if (uVar4 != 0x6603) {
                sVar6 = local_78;
              }
            }
            dwErrCode = FUN_10016a48(puVar2 + 0x27,(int *)(puVar2 + 0x16),puVar2 + 0xe,auStack_60,
                                     sVar6);
            if (dwErrCode == 0) {
              if ((((uVar4 == 0x6601) || (uVar4 == 0x6609)) || (uVar4 == 0x6603)) &&
                 ((param_3 & 4) != 0)) goto LAB_10013bbc;
              uVar3 = 1;
              if ((param_3 & 1) == 0) {
                uVar3 = local_6c;
              }
              dwErrCode = FUN_10013540(uVar4,uVar3,sVar6,local_70,auStack_60,0,0,&local_7c);
              pvVar5 = local_7c;
              if (dwErrCode == 0) {
                if ((param_3 & 4) != 0) {
                  if ((puVar2[0x2e] == 0) || (puVar2[0x2e] == 1)) {
                    *(undefined4 *)((int)local_7c + 0x48) = 0xb;
                  }
                  else {
                    *(undefined4 *)((int)local_7c + 0x48) = 0;
                  }
                  dwErrCode = FUN_10016a48(puVar2 + 0x27,(int *)(puVar2 + 0x16),puVar2 + 0xe,
                                           (void *)((int)local_7c + 0x4c),
                                           *(uint *)((int)local_7c + 0x48));
                  if (dwErrCode != 0) goto LAB_10013eb4;
                }
                dwErrCode = FUN_100092e4(&local_80,2,pvVar5);
                if ((dwErrCode == 0) &&
                   (((sVar6 != 5 || ((param_3 & 0x10) != 0)) ||
                    (((param_3 & 4) != 0 ||
                     ((((param_2 == 0x4c01 || (param_2 == 0x4c06)) || (param_2 == 0x4c04)) ||
                      ((param_2 == 0x4c05 ||
                       (dwErrCode = FUN_1001296c(local_70,local_80), dwErrCode == 0))))))))))
                goto LAB_10013e9c;
              }
            }
          }
          else {
            dwErrCode = FUN_10018318(param_1,param_3,(uint)(uVar4 == 0xa400),&local_80,local_78 << 3
                                    );
            if (dwErrCode == 0) {
LAB_10013e9c:
              dwErrCode = 0;
              *local_68 = local_80;
            }
            if (dwErrCode == 0) goto LAB_10013ed4;
          }
        }
      }
    }
    else {
      dwErrCode = 0x80090022;
    }
  }
  else {
LAB_10013bbc:
    dwErrCode = 0x80090009;
  }
LAB_10013eb4:
  uVar7 = 0;
  if (pvVar5 != (HLOCAL)0x0) {
    FUN_100104a8(pvVar5);
  }
  SetLastError(dwErrCode);
LAB_10013ed4:
  FUN_1002bedc(local_30);
  return uVar7;
}



/* 10013f10 CPDeriveKey */

/* Boundary evidence: original MIPS .pdata 10013f10..10014453. Semantic name remains unreviewed. */

int CPDeriveKey(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  uint *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  DWORD dwErrCode;
  HLOCAL pvVar7;
  size_t _Size;
  int iVar8;
  int iVar9;
  uint local_228;
  uint local_224;
  uint local_220;
  uint local_21c;
  HLOCAL local_218;
  int local_214;
  uint local_210;
  uint local_20c;
  size_t local_208;
  uint local_204;
  uint *local_200;
  byte local_1f8 [64];
  uint auStack_1b8 [16];
  byte local_178 [64];
  uint local_138 [38];
  uint auStack_a0 [16];
  undefined1 auStack_60 [48];
  uint local_30;
  
                    /* 0x13f10  13  CPDeriveKey */
  local_30 = DAT_1002da44;
  pvVar7 = (HLOCAL)0x0;
  local_200 = param_5;
  iVar9 = 0;
  local_218 = (HLOCAL)0x0;
  local_204 = 0;
  local_228 = 0;
  local_220 = 0;
  local_214 = 0;
  if ((param_4 & 0xfbea) == 0) {
    iVar9 = FUN_100091fc(param_1,0);
    if (iVar9 == 0) {
      dwErrCode = 0x80090001;
    }
    else {
      bVar2 = FUN_1001077c(iVar9,param_2);
      if (CONCAT31(extraout_var,bVar2) == 0) {
LAB_10013fc8:
        dwErrCode = 0x80090008;
      }
      else {
        local_224 = 4;
        iVar8 = 1;
        iVar3 = CPGetHashParam(param_1,param_3,1,&local_210,&local_224,0);
        if (iVar3 == 0) goto LAB_1001428c;
        dwErrCode = FUN_1001085c(iVar9,param_2,param_4,&local_208,&local_214);
        if (dwErrCode != 0) goto LAB_100143bc;
        if (param_2 == 0x6601) {
          _Size = 8;
        }
        else if (param_2 == 0x6609) {
          _Size = 0x10;
        }
        else {
          _Size = 0x18;
          if (param_2 != 0x6603) {
            _Size = local_208;
          }
        }
        if (local_214 != 0) goto LAB_10013fc8;
        memset(local_138,0,0x98);
        local_224 = 0x98;
        iVar3 = CPGetHashParam(param_1,param_3,2,local_138,&local_224,0);
        if (iVar3 == 0) {
LAB_1001428c:
          dwErrCode = GetLastError();
        }
        else {
          if ((((local_210 != 0x800c) && (local_210 != 0x800d)) && (local_210 != 0x800e)) &&
             (((param_2 == 0x6603 || (param_2 == 0x660e)) ||
              ((param_2 == 0x660f || (param_2 == 0x6610)))))) {
            iVar3 = CPCreateHash(param_1,local_210,0,0,&local_228);
            if (iVar3 != 0) {
              iVar3 = CPCreateHash(param_1,local_210,0,0,&local_220);
              if (iVar3 != 0) {
                memset(local_1f8,0x36,0x40);
                memset(local_178,0x5c,0x40);
                uVar4 = 0;
                if (local_224 != 0) {
                  do {
                    pbVar5 = (byte *)((int)local_138 + uVar4);
                    local_1f8[uVar4] = local_1f8[uVar4] ^ *pbVar5;
                    pbVar6 = local_178 + uVar4;
                    uVar4 = uVar4 + 1;
                    *pbVar6 = *pbVar6 ^ *pbVar5;
                  } while (uVar4 < local_224);
                }
                iVar3 = CPHashData(param_1,local_228,(int)local_1f8,0x40,0);
                if (iVar3 != 0) {
                  iVar3 = CPHashData(param_1,local_220,(int)local_178,0x40,0);
                  if (iVar3 != 0) {
                    memset(auStack_1b8,0,0x40);
                    local_21c = 0x40;
                    iVar3 = CPGetHashParam(param_1,local_228,2,auStack_1b8,&local_21c,0);
                    if (iVar3 != 0) {
                      memcpy(local_138,auStack_1b8,local_21c);
                      memset(auStack_a0,0,0x40);
                      local_20c = 0x40;
                      iVar3 = CPGetHashParam(param_1,local_220,2,auStack_a0,&local_20c,0);
                      if (iVar3 != 0) {
                        memcpy((void *)((int)local_138 + local_21c),auStack_a0,local_20c);
                        goto LAB_100142bc;
                      }
                    }
                  }
                }
              }
            }
            goto LAB_1001428c;
          }
LAB_100142bc:
          memcpy(auStack_60,local_138,_Size);
          uVar4 = 1;
          if ((param_4 & 1) == 0) {
            uVar4 = local_204;
          }
          dwErrCode = FUN_10013540(param_2,uVar4,_Size,param_1,auStack_60,0,0,&local_218);
          pvVar7 = local_218;
          if (dwErrCode != 0) goto LAB_100143bc;
          if ((param_4 & 4) != 0) {
            if ((*(int *)(iVar9 + 0xb8) == 0) || (*(int *)(iVar9 + 0xb8) == 1)) {
              *(undefined4 *)((int)local_218 + 0x48) = 0xb;
            }
            else {
              *(undefined4 *)((int)local_218 + 0x48) = 0;
            }
            memcpy((void *)((int)local_218 + 0x4c),(void *)((int)local_138 + _Size),
                   *(size_t *)((int)local_218 + 0x48));
          }
          puVar1 = local_200;
          dwErrCode = FUN_100092e4(local_200,2,pvVar7);
          if ((dwErrCode != 0) ||
             ((((_Size == 5 && ((param_4 & 0x10) == 0)) && ((param_4 & 4) == 0)) &&
              (dwErrCode = FUN_1001296c(param_1,*puVar1), dwErrCode != 0)))) goto LAB_100143bc;
          dwErrCode = 0;
        }
        if (dwErrCode == 0) goto LAB_100143c0;
      }
    }
  }
  else {
    dwErrCode = 0x80090009;
  }
LAB_100143bc:
  iVar8 = 0;
LAB_100143c0:
  if (iVar9 != 0) {
    if (local_228 != 0) {
      CPDestroyHash(param_1,local_228);
    }
    if (local_220 != 0) {
      CPDestroyHash(param_1,local_220);
    }
  }
  if (iVar8 == 0) {
    if (pvVar7 != (HLOCAL)0x0) {
      FUN_100104a8(pvVar7);
    }
    SetLastError(dwErrCode);
  }
  FUN_1002bedc(local_30);
  return iVar8;
}



/* 10014454 FUN_10014454 */

/* Boundary evidence: original MIPS .pdata 10014454..100145ff. Semantic name remains unreviewed. */

undefined4 FUN_10014454(int param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 *_Dst;
  uint local_18 [2];
  
  if ((*(int *)(param_1 + 4) == 0x2400) || (*(int *)(param_1 + 4) == 0xa400)) {
    uVar2 = 0x80090003;
  }
  else {
    puVar1 = FUN_100134f4(local_18,0x70,*(uint *)(param_1 + 0xc));
    local_18[0] = *puVar1;
    if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 0x8c) != 0)) {
      FUN_10013190(local_18,*(int *)(param_1 + 0x18));
    }
    *param_3 = local_18[0];
    if (param_2 != 0) {
      _Dst = (undefined4 *)(param_2 + 8);
      memset(_Dst,0,0x68);
      *_Dst = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x30);
      *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x34);
      *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_1 + 0x38);
      *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x3c);
      *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_1 + 0x40);
      *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 0x44);
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(param_1 + 0x48);
      memcpy((void *)(param_2 + 0x40),(void *)(param_1 + 0x4c),0x18);
      *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(param_1 + 100);
      *(undefined4 *)(param_2 + 0x5c) = *(undefined4 *)(param_1 + 0x68);
      *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(param_1 + 0x6c);
      *(undefined4 *)(param_2 + 100) = *(undefined4 *)(param_1 + 0x70);
      *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 0x74);
      *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_1 + 0x84);
      if (*(void **)(param_1 + 0x10) != (void *)0x0) {
        memcpy((void *)(param_2 + 0x70),*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0xc));
        *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0xc);
      }
      if ((*(void **)(param_1 + 0x1c) != (void *)0x0) && (*(int *)(param_1 + 0x8c) != 0)) {
        memcpy((void *)((int)_Dst + *(int *)(param_2 + 0x10) + 0x68),*(void **)(param_1 + 0x1c),
               *(size_t *)(param_1 + 0x18));
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x18);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 10014600 FUN_10014600 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 10014600..10014b27. Semantic name remains unreviewed. */

DWORD FUN_10014600(uint param_1,int param_2,void *param_3,int param_4,int param_5,uint param_6,
                  uint *param_7)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  DWORD DVar7;
  size_t sVar8;
  HLOCAL pvVar9;
  HLOCAL pvVar10;
  uint local_b8;
  HLOCAL local_b4;
  HLOCAL local_b0;
  uint local_ac;
  int local_a8;
  uint local_a0 [2];
  undefined4 local_98;
  undefined4 local_94;
  uint local_90 [11];
  undefined1 auStack_61 [53];
  uint local_2c;
  
  local_2c = DAT_1002da44;
  pvVar10 = (HLOCAL)0x0;
  pvVar9 = (HLOCAL)0x0;
  local_a8 = 0;
  local_a0[0] = 0;
  local_b0 = (HLOCAL)0x0;
  bVar1 = false;
  local_b4 = (HLOCAL)0x0;
  local_ac = param_1;
  memset((void *)((int)auStack_61 + 1),0,0x31);
  memset(&local_98,0,0x31);
  local_b8 = param_5 - 0xc;
  if ((local_b8 < 0x32) && ((local_b8 & 7) == 0)) {
    iVar3 = *(int *)((int)param_3 + 4);
    if (((((iVar3 != 0x6801) && (((iVar3 != 0x6602 && (iVar3 != 0x6601)) && (iVar3 != 0x6603)))) &&
         (iVar3 != 0x6609)) && ((iVar3 == 0x660e || ((iVar3 != 0x660f && (iVar3 != 0x6610)))))) ||
       ((iVar3 == 0x660e ||
        (((iVar3 == 0x660f || (iVar3 == 0x6610)) ||
         ((iVar3 = FUN_10010610(param_2,(int)param_3,0), iVar3 == 0 ||
          (*(int *)((int)param_3 + 4) != *(int *)(param_4 + 8))))))))) {
      DVar7 = 0x80090003;
      goto LAB_10014abc;
    }
    if ((*(int *)((int)param_3 + 0x8c) == 0) && (DVar7 = FUN_10010c04((int)param_3), DVar7 != 0))
    goto LAB_10014abc;
    if (*(int *)((int)param_3 + 4) == 0x6801) {
      DVar7 = FUN_10012a20(&DAT_1002d7ec,param_3,(int *)&local_b4);
      if (DVar7 != 0) goto LAB_10014abc;
      bVar1 = true;
    }
    else {
      *(undefined4 *)((int)param_3 + 0x24) = DAT_1002d7ec;
      *(undefined4 *)((int)param_3 + 0x28) = DAT_1002d7f0;
      *(undefined4 *)((int)param_3 + 0x44) = 0;
      local_b4 = param_3;
    }
    pvVar9 = local_b4;
    memcpy((void *)((int)auStack_61 + 1),(void *)(param_4 + 0xc),local_b8);
    DVar7 = FUN_1000f7c0((int)pvVar9,0,0,(uint *)((int)auStack_61 + 1),&local_b8);
    if (DVar7 == 0) {
      uVar5 = 0;
      if (local_b8 != 0) {
        puVar6 = auStack_61 + local_b8;
        do {
          puVar4 = (undefined1 *)((int)&local_98 + uVar5);
          uVar5 = uVar5 + 1;
          *puVar4 = *puVar6;
          puVar6 = puVar6 + -1;
        } while (uVar5 < local_b8);
      }
      local_b8 = local_b8 - 8;
      if (*(int *)((int)param_3 + 4) == 0x6801) {
        if ((bVar1) && (pvVar9 != (HLOCAL)0x0)) {
          FUN_100104a8(pvVar9);
          local_b4 = (HLOCAL)0x0;
          bVar1 = false;
        }
        DVar7 = FUN_10012a20(&local_98,param_3,(int *)&local_b4);
        pvVar9 = local_b4;
        if (DVar7 != 0) goto LAB_10014aa4;
        bVar1 = true;
      }
      else {
        *(undefined4 *)((int)param_3 + 0x24) = local_98;
        *(undefined4 *)((int)param_3 + 0x28) = local_94;
        *(undefined4 *)((int)param_3 + 0x44) = 0;
      }
      DVar7 = FUN_1000f7c0((int)pvVar9,0,0,local_90,&local_b8);
      if (DVar7 == 0) {
        iVar3 = *(int *)(param_4 + 4);
        sVar8 = 8;
        if (iVar3 != 0x6601) {
          if (iVar3 == 0x6602) {
LAB_10014980:
            local_a8 = 1;
            sVar8 = (uint)(byte)local_90[0];
          }
          else if (iVar3 == 0x6603) {
            sVar8 = 0x18;
          }
          else if (iVar3 != 0x6604) {
            if (iVar3 == 0x6609) {
              sVar8 = 0x10;
            }
            else if (iVar3 != 0x660c) {
              if (iVar3 == 0x6801) goto LAB_10014980;
              bVar2 = FUN_100107c8(param_2,iVar3,local_a0,&local_b4);
              sVar8 = local_a0[0];
              if (CONCAT31(extraout_var,bVar2) == 0) {
                DVar7 = 0x80090008;
                goto LAB_10014aa4;
              }
            }
          }
        }
        local_b8 = local_b8 - 8;
        FUN_100108f0(local_90,local_b8,local_a0);
        iVar3 = memcmp(local_a0,(void *)((int)local_90 + local_b8),8);
        if (iVar3 != 0) goto LAB_10014a9c;
        DVar7 = FUN_10013540(*(uint *)(param_4 + 4),(uint)((param_6 & 1) != 0),sVar8,local_ac,
                             (void *)((int)local_90 + local_a8),0,1,&local_b0);
        pvVar10 = local_b0;
        if (DVar7 == 0) {
          iVar3 = FUN_10010610(param_2,(int)local_b0,1);
          if (iVar3 == 0) {
            DVar7 = 0x80090009;
          }
          else {
            DVar7 = FUN_100092e4(param_7,2,pvVar10);
            if ((DVar7 == 0) &&
               (((*(int *)((int)pvVar10 + 0xc) != 5 || ((param_6 & 0x10) != 0)) ||
                (DVar7 = FUN_1001296c(local_ac,*param_7), DVar7 == 0)))) {
              pvVar10 = (HLOCAL)0x0;
              DVar7 = 0;
            }
          }
        }
      }
    }
  }
  else {
LAB_10014a9c:
    DVar7 = 0x80090005;
  }
LAB_10014aa4:
  if ((bVar1) && (pvVar9 != (HLOCAL)0x0)) {
    FUN_100104a8(pvVar9);
  }
LAB_10014abc:
  memset((void *)((int)auStack_61 + 1),0,0x31);
  memset(&local_98,0,0x31);
  if (pvVar10 != (HLOCAL)0x0) {
    FUN_100104a8(pvVar10);
  }
  FUN_1002bedc(local_2c);
  return DVar7;
}



/* 10014b28 CPExportKey */

/* Boundary evidence: original MIPS .pdata 10014b28..10015393. Semantic name remains unreviewed. */

int CPExportKey(uint *param_1,uint param_2,uint param_3,int param_4,uint param_5,uint *param_6,
               uint *param_7)

{
  uint *puVar1;
  DWORD DVar2;
  uint *puVar3;
  uint *puVar4;
  void *_Buf2;
  int *piVar5;
  uint *puVar6;
  size_t _Size;
  DWORD dwErrCode;
  int iVar7;
  void *_Buf1;
  undefined4 *puVar8;
  uint *hMem;
  uint uVar9;
  uint uVar10;
  int local_68;
  uint local_64;
  uint *local_60;
  int local_5c;
  uint local_58;
  void *local_54;
  uint *local_50;
  uint local_4c;
  undefined4 local_48;
  uint local_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint local_30 [2];
  
                    /* 0x14b28  19  CPExportKey */
  local_50 = (uint *)0x0;
  hMem = (uint *)0x0;
  local_5c = 0;
  local_60 = param_1;
  local_58 = param_2;
  if ((param_5 & 0xffffffb9) == 0) {
    if (param_7 == (uint *)0x0) {
      dwErrCode = 0x57;
      goto LAB_10014b98;
    }
    dwErrCode = 8;
    if ((((param_4 == 6) || (param_4 == 9)) || (param_4 == 8)) && (param_3 != 0)) {
      dwErrCode = 0x80090015;
      goto LAB_10014b98;
    }
    puVar1 = (uint *)FUN_100091fc((uint)param_1,0);
    if (puVar1 == (uint *)0x0) {
      dwErrCode = 0x80090001;
      goto LAB_10014b98;
    }
    if (param_6 == (uint *)0x0) {
LAB_10014cd8:
      puVar6 = local_30;
    }
    else {
      hMem = param_6;
      if (((uint)param_6 & 3) != 0) {
        hMem = LocalAlloc(0x40,*param_7);
        if (hMem == (uint *)0x0) goto LAB_10014b98;
        local_5c = 1;
      }
      puVar6 = hMem;
      if (*param_7 < 9) goto LAB_10014cd8;
    }
    *(undefined1 *)((int)puVar6 + 1) = 2;
    *(char *)puVar6 = (char)param_4;
    uVar9 = param_2 ^ 0xe35a172c;
    *(undefined2 *)((int)puVar6 + 2) = 0;
    DVar2 = FUN_10009224(local_58,(int)local_60,(uint)*(byte *)(uVar9 + 4),&local_68);
    if (DVar2 == 0) {
      if ((param_4 == 6) || ((*(uint *)(local_68 + 8) & 0x4001) != 0)) {
        puVar6[1] = *(uint *)(local_68 + 4);
        puVar6 = hMem;
        if (param_4 != 1) {
          if (param_4 == 6) {
            if ((*(char *)(uVar9 + 4) != '\x03') && (*(char *)(uVar9 + 4) != '\x04'))
            goto LAB_10014e68;
            puVar1 = *(uint **)(local_68 + 0x10);
            if (puVar1 == (uint *)0x0) goto LAB_100150e4;
            uVar9 = (puVar1[2] + 7 >> 3) + 0x14;
            if ((param_6 != (uint *)0x0) && (uVar9 <= *param_7)) {
              hMem[2] = *puVar1;
              hMem[3] = puVar1[2];
              hMem[4] = puVar1[4];
              memcpy(hMem + 5,puVar1 + 5,puVar1[2] + 7 >> 3);
              goto LAB_10015350;
            }
LAB_10014ed0:
            *param_7 = uVar9;
            if (param_6 != (uint *)0x0) {
LAB_10015088:
              dwErrCode = 0xea;
              goto LAB_10014b98;
            }
          }
          else {
            if (param_4 == 7) {
              uVar10 = 0;
              local_4c = 0;
              if (*(char *)(uVar9 + 4) == '\x03') {
                _Buf1 = (void *)puVar1[0x10];
                _Size = puVar1[10];
                local_58 = 1;
                local_48 = DAT_1002dcfc;
              }
              else {
                if (*(char *)(uVar9 + 4) != '\x04') goto LAB_10014e68;
                _Buf1 = (void *)puVar1[0x13];
                _Size = puVar1[0xc];
                local_58 = 0;
                local_48 = DAT_1002dd00;
              }
              if ((_Buf1 != (void *)0x0) && (_Size == *(size_t *)(local_68 + 0xc))) {
                _Buf2 = *(void **)(local_68 + 0x10);
                iVar7 = memcmp(_Buf1,_Buf2,_Size);
                if (iVar7 == 0) {
                  local_64 = 0;
                  uVar9 = *(uint *)((int)_Buf1 + 8) + 0xf;
                  FUN_1000aa40(&local_44,_Buf2,uVar9,(uint)(uVar9 < *(uint *)((int)_Buf1 + 8)));
                  FUN_1000aa98(&local_44,local_44 >> 4,9);
                  puVar3 = FUN_100134f4(&uStack_40,0xc,local_44);
                  puVar4 = local_60;
                  local_64 = *puVar3;
                  if (param_3 != 0) {
                    local_44 = 4;
                    iVar7 = CPGetKeyParam((uint)local_60,param_3,8,(int *)&local_4c,&local_44,0);
                    if (iVar7 == 0) goto LAB_10014e68;
                    uVar10 = local_4c >> 3;
                  }
                  if (param_6 == (uint *)0x0) {
                    puVar1 = FUN_100134f4(&uStack_3c,8,local_64);
                    FUN_100130f4(&local_44,*puVar1,uVar10);
                    *param_7 = local_44;
                    goto LAB_10014ed8;
                  }
                  puVar3 = FUN_100134f4(&uStack_38,8,local_64);
                  FUN_100130f4(&local_44,*puVar3,uVar10);
                  uVar9 = local_58;
                  if (*param_7 < local_44) {
                    puVar1 = FUN_100134f4(&uStack_34,8,local_64);
                    FUN_100130f4(&local_44,*puVar1,uVar10);
                    *param_7 = local_44;
                    goto LAB_10015088;
                  }
                  if (((*puVar1 & 0xf0000000) == 0) &&
                     (DVar2 = FUN_1000bb68(puVar1,local_48,local_58,1), DVar2 != 0))
                  goto LAB_10015384;
                  if (uVar9 == 0) {
                    puVar8 = (undefined4 *)puVar1[0x1b];
                    uVar9 = puVar1[0x15];
                  }
                  else {
                    puVar8 = (undefined4 *)puVar1[0x1d];
                    uVar9 = puVar1[0x12];
                  }
                  if (puVar8 == (undefined4 *)0x0) goto LAB_100150e4;
                  if (((uVar9 != 0) || ((*(uint *)(local_68 + 8) & 0x4000) != 0)) &&
                     (iVar7 = FUN_10013898(puVar8,(undefined4 *)0x0,&local_64), iVar7 != 0)) {
                    FUN_100130f4(&local_44,local_64,uVar10);
                    uVar9 = local_44;
                    if (local_5c == 0) {
                      puVar1 = LocalAlloc(0x40,local_44);
                      local_50 = puVar1;
                      if (puVar1 == (uint *)0x0) goto LAB_10014b98;
                    }
                    else {
                      puVar1 = hMem + 2;
                    }
                    local_50 = puVar1;
                    iVar7 = FUN_10013898(puVar8,puVar1,&local_64);
                    if (iVar7 != 0) {
                      if ((param_3 == 0) ||
                         (dwErrCode = FUN_1000fa24(puVar4,param_3,(uint *)0x0,1,0,puVar1,&local_64,
                                                   uVar9,0), dwErrCode == 0)) {
                        puVar4 = FUN_100134f4(local_30,8,local_64);
                        uVar9 = *puVar4;
                        uVar10 = uVar9;
                        if (local_5c == 0) {
                          param_6 = param_6 + 2;
                          puVar6 = puVar1;
                          uVar10 = local_64;
                        }
                        goto LAB_10015368;
                      }
                      goto LAB_10014b98;
                    }
                  }
                }
              }
              goto LAB_10014e68;
            }
            if (param_4 != 8) {
              if (param_4 == 9) {
                local_4c = *param_7;
                dwErrCode = FUN_10014454(local_68,(int)hMem,&local_4c);
                if (dwErrCode == 0) {
                  uVar9 = local_4c;
                  if (((param_5 & 4) != 0) &&
                     (iVar7 = CPDestroyKey((uint)local_60,local_58), uVar9 = local_4c, iVar7 == 0))
                  {
                    DVar2 = GetLastError();
                    goto LAB_10015384;
                  }
                  goto LAB_10015350;
                }
              }
              else if (param_4 == 0xb) {
                dwErrCode = FUN_10009224(param_3,(int)local_60,(uint)*(byte *)(uVar9 + 4),&local_54)
                ;
                if ((dwErrCode == 0) &&
                   (dwErrCode = FUN_10012aa8((int)puVar1,local_68,local_54,(int)hMem,param_7),
                   dwErrCode == 0)) {
                  uVar9 = *param_7;
                  goto LAB_10015350;
                }
              }
              else {
                dwErrCode = 0x8009000a;
              }
              goto LAB_10014b98;
            }
            if ((*(char *)(uVar9 + 4) != '\x02') ||
               (iVar7 = FUN_10010610((int)puVar1,local_68,0), iVar7 == 0)) goto LAB_10014e68;
            uVar9 = *(uint *)(local_68 + 0xc) + 0xc;
            if ((param_6 == (uint *)0x0) || (*param_7 < uVar9)) goto LAB_10014ed0;
            hMem[2] = *(uint *)(local_68 + 0xc);
            memcpy(hMem + 3,*(void **)(local_68 + 0x10),*(size_t *)(local_68 + 0xc));
            *param_7 = uVar9;
LAB_10015350:
            uVar10 = uVar9;
            if (local_5c != 0) {
LAB_10015368:
              memcpy(param_6,puVar6,uVar10);
            }
            *param_7 = uVar9;
          }
LAB_10014ed8:
          dwErrCode = 0;
          goto LAB_1001538c;
        }
        if (*(char *)(uVar9 + 4) == '\x02') {
          if (param_3 == 0) {
LAB_100150e4:
            dwErrCode = 0x8009000d;
            goto LAB_10014b98;
          }
          iVar7 = FUN_10010610((int)puVar1,local_68,0);
          if (iVar7 != 0) {
            dwErrCode = FUN_10009224(param_3,(int)local_60,4,&local_54);
            if (dwErrCode == 0) {
              piVar5 = *(int **)((int)local_54 + 0x10);
              if (piVar5 == (int *)0x0) goto LAB_100150e4;
              uVar9 = (piVar5[2] + 7U >> 3) + 0xc;
              if ((param_6 == (uint *)0x0) || (*param_7 < uVar9)) {
                *param_7 = uVar9;
                if (param_6 != (uint *)0x0) {
                  DVar2 = 0xea;
                  goto LAB_10015384;
                }
                goto LAB_10014ed8;
              }
              hMem[2] = 0xa400;
              dwErrCode = FUN_10017dc4((int)puVar1,piVar5,*(void **)(local_68 + 0x10),
                                       *(size_t *)(local_68 + 0xc),*(void **)(local_68 + 0x7c),
                                       *(uint *)(local_68 + 0x80),param_5,hMem + 3);
              if (dwErrCode == 0) goto LAB_10015350;
            }
            goto LAB_10014b98;
          }
        }
LAB_10014e68:
        dwErrCode = 0x80090003;
      }
      else {
        dwErrCode = 0x8009000b;
      }
      goto LAB_10014b98;
    }
LAB_10015384:
    dwErrCode = DVar2;
    if (dwErrCode != 0) goto LAB_10014b98;
LAB_1001538c:
    iVar7 = 1;
  }
  else {
    dwErrCode = 0x80090009;
LAB_10014b98:
    iVar7 = 0;
  }
  if (local_50 == (uint *)0x0) {
LAB_10014bbc:
    if (local_5c == 0) goto LAB_10014bd0;
  }
  else if (local_5c == 0) {
    LocalFree(local_50);
    goto LAB_10014bbc;
  }
  LocalFree(hMem);
LAB_10014bd0:
  if (iVar7 == 0) {
    SetLastError(dwErrCode);
  }
  return iVar7;
}



/* 10015394 CPGetUserKey */

/* Boundary evidence: original MIPS .pdata 10015394..1001550b. Semantic name remains unreviewed. */

undefined4 CPGetUserKey(uint param_1,int param_2,uint *param_3)

{
  bool bVar1;
  int iVar2;
  DWORD dwErrCode;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  uint uVar6;
  void *pvVar7;
  undefined4 local_30 [2];
  
                    /* 0x15394  25  CPGetUserKey */
  iVar2 = FUN_100091fc(param_1,0);
  if (iVar2 == 0) {
    dwErrCode = 0x80090001;
  }
  else {
    if (param_2 == 1) {
      sVar5 = *(size_t *)(iVar2 + 0x30);
      pvVar7 = *(void **)(iVar2 + 0x4c);
      iVar3 = *(int *)(iVar2 + 0x54);
      uVar6 = 0xa400;
      uVar4 = 4;
    }
    else {
      if (param_2 != 2) {
        dwErrCode = 0x80090003;
        goto LAB_100154c8;
      }
      sVar5 = *(size_t *)(iVar2 + 0x28);
      pvVar7 = *(void **)(iVar2 + 0x40);
      iVar3 = *(int *)(iVar2 + 0x48);
      uVar6 = 0x2400;
      uVar4 = 3;
    }
    bVar1 = FUN_1001077c(iVar2,uVar6);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      dwErrCode = 0x8009000a;
    }
    else if (sVar5 == 0) {
      dwErrCode = 0x8009000d;
    }
    else {
      dwErrCode = FUN_10013540(uVar6,(uint)(iVar3 != 0),sVar5,param_1,pvVar7,0,0,local_30);
      if ((dwErrCode == 0) && (dwErrCode = FUN_100092e4(param_3,uVar4,local_30[0]), dwErrCode == 0))
      {
        return 1;
      }
    }
  }
LAB_100154c8:
  SetLastError(dwErrCode);
  return 0;
}



/* 1001550c CPSetProvParam */

/* Boundary evidence: original MIPS .pdata 1001550c..10015633. Semantic name remains unreviewed. */

undefined4 CPSetProvParam(uint param_1,int param_2,int *param_3,int param_4)

{
  uint *puVar1;
  DWORD dwErrCode;
  int iVar2;
  uint local_20 [2];
  
                    /* 0x1550c  32  CPSetProvParam */
  local_20[0] = 0;
  puVar1 = (uint *)FUN_100091fc(param_1,0);
  if (puVar1 != (uint *)0x0) {
    if (param_2 != 0x18) {
      dwErrCode = 0x8009000a;
      goto LAB_1001555c;
    }
    if (param_4 != 0) {
      dwErrCode = 0x80090009;
      goto LAB_1001555c;
    }
    if ((*puVar1 & 0xf0000000) == 0) {
      iVar2 = CPGetUserKey(param_1,*param_3,local_20);
      if ((iVar2 == 0) || (iVar2 = CPDestroyKey(param_1,local_20[0]), iVar2 == 0)) {
        dwErrCode = GetLastError();
      }
      else {
        dwErrCode = FUN_10011ac4((int)puVar1,*param_3);
      }
      if (dwErrCode == 0) {
        return 1;
      }
      goto LAB_1001555c;
    }
  }
  dwErrCode = 0x80090001;
LAB_1001555c:
  SetLastError(dwErrCode);
  return 0;
}



/* 10015634 CPImportKey */

/* Boundary evidence: original MIPS .pdata 10015634..100163cf. Semantic name remains unreviewed. */

bool CPImportKey(uint param_1,char *param_2,uint param_3,uint param_4,uint param_5,uint *param_6)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  void *pvVar4;
  bool bVar5;
  undefined3 extraout_var;
  int iVar6;
  uint *puVar7;
  HLOCAL pvVar8;
  int *piVar9;
  undefined3 extraout_var_00;
  uint uVar10;
  undefined4 uVar11;
  size_t _Size;
  undefined4 *puVar12;
  DWORD dwErrCode;
  char *pcVar13;
  uint *puVar14;
  HLOCAL pvVar15;
  int iVar16;
  uint *puVar17;
  HLOCAL local_70;
  uint *local_6c;
  uint *local_68;
  uint *local_64;
  uint local_60;
  int local_5c;
  void *local_58;
  HLOCAL local_54;
  uint *local_50;
  uint local_4c;
  uint *local_48;
  int local_44;
  size_t local_40;
  uint local_3c;
  undefined4 local_38;
  char *local_34;
  undefined4 local_30;
  uint *local_2c;
  
                    /* 0x15634  28  CPImportKey */
  local_54 = (HLOCAL)0x0;
  local_64 = (uint *)0x0;
  puVar14 = (uint *)0x0;
  pvVar15 = (HLOCAL)0x0;
  local_70 = (HLOCAL)0x0;
  local_6c = (uint *)0x0;
  local_48 = (uint *)0x0;
  local_44 = 0;
  local_58 = (void *)0x0;
  bVar3 = false;
  local_38 = 0;
  local_50 = (uint *)0x0;
  local_3c = 0;
  local_68 = (uint *)0x0;
  pcVar13 = (char *)0x0;
  local_5c = 0;
  local_30 = 0;
  local_4c = param_1;
  bVar2 = bVar3;
  if ((param_5 & 0xfffffeac) != 0) {
    dwErrCode = 0x80090009;
    goto LAB_100162f0;
  }
  local_34 = param_2;
  if (((uint)param_2 & 3) != 0) {
    pcVar13 = LocalAlloc(0x40,param_3);
    local_34 = pcVar13;
    if (pcVar13 == (char *)0x0) {
      dwErrCode = 8;
      goto LAB_100162f0;
    }
    memcpy(pcVar13,param_2,param_3);
    local_5c = 1;
    local_30 = 1;
    param_2 = pcVar13;
  }
  pcVar13 = param_2;
  if ((*param_2 == '\x06') && (param_4 != 0)) {
    dwErrCode = 0x57;
    goto LAB_100162f0;
  }
  puVar14 = (uint *)FUN_100091fc(param_1,0);
  local_2c = puVar14;
  if (puVar14 == (uint *)0x0) {
    dwErrCode = 0x80090001;
    goto LAB_100162f0;
  }
  if (param_2[1] != '\x02') {
    dwErrCode = 0x80090007;
    goto LAB_100162f0;
  }
  cVar1 = *param_2;
  if (cVar1 == '\x01') {
    bVar5 = FUN_1001077c((int)puVar14,*(uint *)(param_2 + 4));
    if (CONCAT31(extraout_var_00,bVar5) == 0) {
LAB_10016014:
      dwErrCode = 0x8009000a;
      goto LAB_100162f0;
    }
    if (*(int *)(param_2 + 8) != 0xa400) {
LAB_10016034:
      dwErrCode = 0x80090008;
      goto LAB_100162f0;
    }
    if (param_4 != 0) {
      dwErrCode = FUN_10009224(param_4,local_4c,(uint)*(byte *)((param_4 ^ 0xe35a172c) + 4),
                               &local_58);
      pvVar4 = local_58;
      if (dwErrCode != 0) goto LAB_100162f0;
      if ((puVar14[0xc] != *(size_t *)((int)local_58 + 0xc)) ||
         (iVar6 = memcmp(*(void **)((int)local_58 + 0x10),(void *)puVar14[0x13],
                         *(size_t *)((int)local_58 + 0xc)), iVar6 != 0)) {
        dwErrCode = 0x80090003;
        goto LAB_100162f0;
      }
      local_50 = *(uint **)((int)pvVar4 + 0x7c);
      local_3c = *(uint *)((int)pvVar4 + 0x80);
    }
    if (puVar14[0x13] == 0) {
LAB_100160c8:
      dwErrCode = 0x8009000d;
    }
    else {
      iVar6 = FUN_100104f8(puVar14[0x2e],0xa400,*(uint *)(puVar14[0x13] + 8) >> 3,0,&local_44);
      if (iVar6 != 0) {
        uVar11 = DAT_1002dcd4;
        dwErrCode = FUN_1000bb68(puVar14,DAT_1002dcd4,0,0);
        if (dwErrCode != 0) goto LAB_100162f0;
        piVar9 = (int *)puVar14[0x1b];
        if (piVar9 == (int *)0x0) goto LAB_100160c8;
        uVar10 = piVar9[2];
        if (uVar10 + 7 >> 3 <= param_3 - 0xc) {
          FUN_1000aa40(&local_2c,uVar11,uVar10 + 7,(uint)(uVar10 + 7 < uVar10));
          local_60 = (uint)local_2c >> 3;
          local_54 = LocalAlloc(0x40,local_60);
          if (local_54 == (HLOCAL)0x0) {
            dwErrCode = 8;
            goto LAB_100162f0;
          }
          dwErrCode = FUN_10017e70((int)puVar14,piVar9,param_2 + 0xc,param_3 - 0xc,local_50,local_3c
                                   ,param_5,(int *)&local_54,&local_60);
          param_1 = local_4c;
          if (dwErrCode != 0) goto LAB_100162f0;
          if ((param_5 & 1) != 0) {
            local_64 = (uint *)0x1;
          }
          dwErrCode = FUN_10013540(*(uint *)(param_2 + 4),(uint)local_64,local_60,local_4c,local_54,
                                   0,1,&local_70);
          pvVar15 = local_70;
          if (dwErrCode != 0) goto LAB_100162f0;
          iVar6 = FUN_10010660((int)puVar14,(int)local_70,1);
          if (iVar6 == 0) {
            dwErrCode = 0x80090009;
            goto LAB_100162f0;
          }
          dwErrCode = FUN_100092e4(param_6,2,pvVar15);
          if (dwErrCode != 0) goto LAB_100162f0;
          if (((local_60 == 5) && ((param_5 & 0x10) == 0)) && (*(int *)(param_2 + 4) != 0x4c05)) {
            uVar10 = *param_6;
            goto LAB_100162d4;
          }
LAB_100162e4:
          bVar3 = false;
          goto LAB_100162e8;
        }
      }
LAB_10015ed0:
      dwErrCode = 0x80090005;
    }
    goto LAB_100162f0;
  }
  if (cVar1 == '\x06') {
    uVar10 = *(uint *)(param_2 + 4);
    if ((uVar10 != 0xa400) && (uVar10 != 0x2400)) goto LAB_10015ed0;
    iVar6 = -(*(uint *)(param_2 + 0xc) + 7 >> 3 & 7);
    iVar16 = iVar6 + 8;
    if (iVar16 != 8) {
      iVar16 = iVar6 + 0x10;
    }
    dwErrCode = FUN_10013540(uVar10,0,(*(uint *)(param_2 + 0xc) >> 3) + iVar16 + 0x14,local_4c,
                             (void *)0x0,0,1,&local_70);
    pvVar15 = local_70;
    if (dwErrCode != 0) goto LAB_100162f0;
    puVar12 = *(undefined4 **)((int)local_70 + 0x10);
    *puVar12 = *(undefined4 *)(param_2 + 8);
    _Size = (*(uint *)(param_2 + 0xc) >> 3) + iVar16;
    puVar12[1] = _Size;
    puVar12[2] = *(undefined4 *)(param_2 + 0xc);
    puVar12[3] = (*(int *)(param_2 + 0xc) + 7U >> 3) - 1;
    puVar12[4] = *(undefined4 *)(param_2 + 0x10);
    memset(puVar12 + 5,0,_Size);
    memcpy(puVar12 + 5,param_2 + 0x14,*(int *)(param_2 + 0xc) + 7U >> 3);
    uVar11 = 4;
    if (*(int *)(param_2 + 4) != 0xa400) {
      uVar11 = 3;
    }
    dwErrCode = FUN_100092e4(param_6,uVar11,pvVar15);
LAB_10015fe4:
    bVar2 = false;
    if (dwErrCode != 0) goto LAB_100162f0;
  }
  else {
    if (cVar1 != '\a') {
      if (cVar1 == '\b') {
        bVar5 = FUN_1001077c((int)puVar14,*(uint *)(param_2 + 4));
        if (CONCAT31(extraout_var,bVar5) == 0) goto LAB_10016034;
        if ((param_5 & 1) != 0) {
          local_64 = (uint *)0x1;
        }
        local_60 = *(uint *)(param_2 + 8);
        dwErrCode = FUN_10013540(*(uint *)(param_2 + 4),(uint)local_64,local_60,param_1,
                                 param_2 + 0xc,0,1,&local_70);
        pvVar15 = local_70;
        if (dwErrCode != 0) goto LAB_100162f0;
        puVar7 = local_68;
        if ((param_5 & 0x100) != 0) {
          puVar7 = (uint *)0x1;
        }
        iVar6 = FUN_10010660((int)puVar14,(int)local_70,(int)puVar7);
        if (iVar6 == 0) goto LAB_10015ed0;
        dwErrCode = FUN_100092e4(param_6,2,pvVar15);
        if (dwErrCode != 0) goto LAB_100162f0;
        if (((local_60 != 5) || ((param_5 & 0x10) != 0)) || (*(int *)(param_2 + 4) == 0x4c05))
        goto LAB_100162e4;
        uVar10 = *param_6;
LAB_100162d4:
        dwErrCode = FUN_1001296c(param_1,uVar10);
      }
      else if (cVar1 == '\t') {
        dwErrCode = FUN_10010980(param_1,(int)param_2,param_3,param_6);
      }
      else {
        if (cVar1 != '\v') goto LAB_10016014;
        dwErrCode = FUN_10009224(param_4,param_1,(uint)*(byte *)((param_4 ^ 0xe35a172c) + 4),
                                 &local_58);
        if (dwErrCode != 0) goto LAB_100162f0;
        dwErrCode = FUN_10014600(param_1,(int)puVar14,local_58,(int)param_2,param_3,param_5,param_6)
        ;
      }
      goto LAB_10015fe4;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar14 + 0x28));
    local_38 = 1;
    if (param_3 < 9) {
      dwErrCode = 0x80090005;
      bVar2 = true;
      goto LAB_100162f0;
    }
    local_40 = param_3 - 8;
    if (local_5c == 0) {
      puVar7 = LocalAlloc(0x40,local_40);
      local_6c = puVar7;
      local_48 = puVar7;
      if (puVar7 == (uint *)0x0) {
        dwErrCode = 8;
        bVar2 = true;
        goto LAB_100162f0;
      }
      memcpy(puVar7,param_2 + 8,local_40);
    }
    else {
      puVar7 = (uint *)(param_2 + 8);
      local_6c = puVar7;
      local_48 = puVar7;
    }
    if ((param_4 != 0) &&
       (dwErrCode = FUN_1000ff28(param_1,param_4,0,1,0,puVar7,&local_40,0), dwErrCode != 0)) {
      bVar2 = true;
      goto LAB_100162f0;
    }
    iVar6 = *(int *)(param_2 + 4);
    if (iVar6 == 0xa400) {
      if (puVar14[1] == 2) {
        dwErrCode = 0x80090005;
        bVar2 = true;
        goto LAB_100162f0;
      }
      local_64 = puVar14 + 0xc;
      puVar7 = puVar14 + 0x13;
      local_68 = puVar14 + 0x1a;
      puVar17 = puVar14 + 0x1b;
      local_50 = puVar14 + 0x15;
      local_4c = 1;
      local_3c = DAT_1002dcf8;
    }
    else {
      if (iVar6 != 0x2400) {
        dwErrCode = 0x80090005;
        bVar2 = true;
        goto LAB_100162f0;
      }
      if (puVar14[1] == 0xc) {
        dwErrCode = 0x80090005;
        bVar2 = true;
        goto LAB_100162f0;
      }
      local_64 = puVar14 + 10;
      puVar7 = puVar14 + 0x10;
      local_68 = puVar14 + 0x1c;
      puVar17 = puVar14 + 0x1d;
      local_4c = 0;
      local_50 = puVar14 + 0x12;
      local_3c = DAT_1002dcf4;
    }
    iVar6 = FUN_100104f8(puVar14[0x2e],iVar6,local_6c[1] >> 3,0,&local_44);
    if (iVar6 == 0) {
      dwErrCode = 0x80090005;
      bVar2 = true;
      goto LAB_100162f0;
    }
    if (local_44 == 0) {
      dwErrCode = 0x80090005;
      bVar2 = true;
      goto LAB_100162f0;
    }
    if ((HLOCAL)*puVar7 != (HLOCAL)0x0) {
      LocalFree((HLOCAL)*puVar7);
      *puVar7 = 0;
      *local_64 = 0;
      if ((HLOCAL)*puVar17 != (HLOCAL)0x0) {
        LocalFree((HLOCAL)*puVar17);
        *puVar17 = 0;
        *local_68 = 0;
      }
    }
    iVar6 = FUN_100131e0((int *)local_6c,(int *)0x0,local_68,(undefined4 *)0x0,local_64);
    if (iVar6 == 0) {
      dwErrCode = 0x80090005;
      bVar2 = true;
      goto LAB_100162f0;
    }
    pvVar8 = LocalAlloc(0x40,*local_64);
    *puVar7 = (uint)pvVar8;
    if (pvVar8 == (HLOCAL)0x0) {
      dwErrCode = 8;
      bVar2 = true;
      goto LAB_100162f0;
    }
    piVar9 = LocalAlloc(0x40,*local_68);
    *puVar17 = (uint)piVar9;
    if (piVar9 == (int *)0x0) {
      dwErrCode = 8;
      bVar2 = true;
      goto LAB_100162f0;
    }
    iVar6 = FUN_100131e0((int *)local_6c,piVar9,local_68,(undefined4 *)*puVar7,local_64);
    if (iVar6 == 0) {
      dwErrCode = 0x80090005;
      bVar2 = true;
      goto LAB_100162f0;
    }
    if ((param_5 & 1) == 0) {
      *local_50 = 0;
    }
    else {
      *local_50 = 1;
    }
    dwErrCode = FUN_10018068((int *)*puVar7,(int *)*puVar17,0);
    uVar10 = local_4c;
    if (dwErrCode != 0) {
      bVar2 = true;
      goto LAB_100162f0;
    }
    if (((*puVar14 & 0xf0000000) == 0) &&
       (dwErrCode = FUN_1000b8ec(puVar14,local_3c,param_5,(uint)(local_4c == 0)), dwErrCode != 0)) {
      bVar2 = true;
      goto LAB_100162f0;
    }
    iVar6 = 1;
    if (uVar10 == 0) {
      iVar6 = 2;
    }
    iVar6 = CPGetUserKey(param_1,iVar6,param_6);
    if (iVar6 == 0) {
      dwErrCode = GetLastError();
      bVar2 = true;
      goto LAB_100162f0;
    }
    bVar3 = true;
  }
LAB_100162e8:
  dwErrCode = 0;
  pvVar15 = (HLOCAL)0x0;
  bVar2 = bVar3;
LAB_100162f0:
  if (bVar2) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar14 + 0x28));
  }
  if (local_54 != (HLOCAL)0x0) {
    LocalFree(local_54);
  }
  if ((local_6c != (uint *)0x0) && (local_5c == 0)) {
    LocalFree(local_6c);
  }
  if (local_5c != 0) {
    LocalFree(pcVar13);
  }
  if (pvVar15 != (HLOCAL)0x0) {
    FUN_100104a8(pvVar15);
  }
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* 100163d0 FUN_100163d0 */

/* Boundary evidence: original MIPS .pdata 100163d0..100163db. Semantic name remains unreviewed. */

undefined4 FUN_100163d0(void)

{
  return 1;
}



/* 100163dc FUN_100163dc */

/* Boundary evidence: original MIPS .pdata 100163dc..10016447. Semantic name remains unreviewed. */

bool FUN_100163dc(void *param_1)

{
  int iVar1;
  
  iVar1 = memcmp(&DAT_1002dc70,param_1,0x14);
  memcpy(&DAT_1002dc70,param_1,0x14);
  return iVar1 != 0;
}



/* 10016448 FUN_10016448 */

/* Boundary evidence: original MIPS .pdata 10016448..100164f7. Semantic name remains unreviewed. */

undefined4 FUN_10016448(void *param_1,void *param_2,size_t param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_4 == 0) || (iVar1 = memcmp(&DAT_1002dc84,param_2,0x14), iVar1 != 0)) {
    memcpy(&DAT_1002dc84,param_2,0x14);
    memcpy(param_1,param_2,param_3);
    uVar2 = 1;
  }
  else {
    memcpy(&DAT_1002dc84,param_2,0x14);
  }
  return uVar2;
}



/* 100164f8 FUN_100164f8 */

/* Boundary evidence: original MIPS .pdata 100164f8..100165b3. Semantic name remains unreviewed. */

undefined4 FUN_100164f8(undefined4 *param_1,int *param_2,void *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  int iVar4;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (int *)0x0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = *param_2;
  }
  iVar2 = CeGenRandom(param_4,param_3);
  if ((((iVar2 == 0) || (param_4 != 0x14)) ||
      (bVar1 = FUN_100163dc(param_3), CONCAT31(extraout_var,bVar1) == 0)) ||
     ((iVar4 == 0x14 && (iVar4 = memcmp((void *)*param_1,param_3,0x14), iVar4 == 0)))) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* 100165b4 FUN_100165b4 */

void FUN_100165b4(int param_1,int param_2,int *param_3,int param_4,int param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_4 != 0) {
    iVar5 = param_2 - (int)param_3;
    iVar6 = param_1 - (int)param_3;
    do {
      uVar2 = *(uint *)(iVar5 + (int)param_3);
      uVar3 = uVar2 + *param_3;
      uVar4 = uVar3 + param_5;
      param_5 = (uint)(uVar3 < uVar2) + (uint)(uVar4 < uVar3);
      puVar1 = (uint *)(iVar6 + (int)param_3);
      param_3 = param_3 + 1;
      param_4 = param_4 + -1;
      *puVar1 = uVar4;
    } while (param_4 != 0);
  }
  return;
}



/* 10016608 FUN_10016608 */

/* Boundary evidence: original MIPS .pdata 10016608..1001680f. Semantic name remains unreviewed. */

void FUN_10016608(int *param_1,void *param_2,uint param_3,uint *param_4,int *param_5,int param_6)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 auStack_c8 [64];
  undefined1 auStack_88 [31];
  undefined1 auStack_69 [20];
  undefined1 local_55 [45];
  uint local_28;
  
  local_28 = DAT_1002da44;
  if (0x3f < param_3) {
    param_3 = 0x40;
  }
  memcpy(auStack_69 + 1,param_2,param_3);
  memset(auStack_69 + param_3 + 1,0,0x40 - param_3);
  FUN_1001eae8((int)(auStack_69 + 1),(int)(auStack_69 + 1),param_1,param_3 >> 2);
  A_SHAInit((int)auStack_c8);
  puVar3 = auStack_69 + param_3;
  puVar2 = auStack_69 + 1;
  if (auStack_69 + 1 < puVar3) {
    do {
      uVar1 = *puVar2;
      *puVar2 = *puVar3;
      *puVar3 = uVar1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + -1;
    } while (puVar2 < puVar3);
  }
  A_SHAUpdate(auStack_c8,auStack_69 + 1,0x40);
  memcpy(auStack_69 + 1,auStack_88,0x14);
  puVar2 = auStack_69 + 1;
  puVar3 = local_55;
  do {
    uVar1 = *puVar2;
    *puVar2 = *puVar3;
    *puVar3 = uVar1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + -1;
  } while (puVar2 < puVar3);
  puVar2 = auStack_69 + 1;
  iVar5 = 5;
  do {
    puVar4 = puVar2 + 3;
    puVar3 = puVar2;
    if (puVar2 < puVar4) {
      do {
        uVar1 = *puVar3;
        *puVar3 = *puVar4;
        *puVar4 = uVar1;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + -1;
      } while (puVar3 < puVar4);
    }
    iVar5 = iVar5 + -1;
    puVar2 = puVar2 + 4;
  } while (iVar5 != 0);
  if ((param_4 == (uint *)0x0) ||
     (iVar5 = FUN_10025aec((int)(auStack_69 + 1),(int)param_4,5), iVar5 == -1)) {
    memcpy(param_5,auStack_69 + 1,0x14);
  }
  else {
    FUN_1001ea90((int)param_5,(int)(auStack_69 + 1),param_4,5);
  }
  if (param_6 != 0) {
    FUN_100165b4(param_6,(int)param_1,param_5,param_3 >> 2,1);
  }
  FUN_1002bedc(local_28);
  return;
}



/* 10016810 FUN_10016810 */

/* Boundary evidence: original MIPS .pdata 10016810..10016a47. Semantic name remains unreviewed. */

undefined4
FUN_10016810(undefined4 param_1,int *param_2,uint *param_3,uint *param_4,void *param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  int aiStack_78 [5];
  undefined4 local_64;
  undefined1 local_60;
  undefined1 auStack_58 [24];
  byte local_40 [20];
  uint local_2c;
  
  uVar7 = 0;
  local_2c = DAT_1002da44;
  if ((param_2 != (int *)0x0) && (param_3 != (uint *)0x0)) {
    uVar7 = *param_3;
  }
  do {
    if (param_6 == 0) {
      uVar6 = 0;
LAB_10016a00:
      FUN_1002bedc(local_2c);
      return uVar6;
    }
    local_64 = 0x53504946;
    local_60 = 0;
    if ((uVar7 != 5) || (iVar1 = strncmp((char *)*param_2,(char *)&local_64,5), iVar1 != 0)) {
      if ((param_5 != (void *)0x0) && (param_6 != 0)) {
        sVar3 = 0x14;
        if (param_6 < 0x15) {
          sVar3 = param_6;
        }
        memcpy(aiStack_78,param_5,sVar3);
      }
      iVar1 = FUN_100164f8(param_2,(int *)param_3,aiStack_78,0x14);
      if (iVar1 != 0) goto LAB_10016918;
LAB_10016a3c:
      uVar6 = 0x80090020;
      goto LAB_10016a00;
    }
    memset(aiStack_78,1,0x14);
LAB_10016918:
    if (uVar7 != 0) {
      sVar3 = 0x14;
      if (uVar7 < 0x15) {
        sVar3 = uVar7;
      }
      memcpy(auStack_58,(void *)*param_2,sVar3);
    }
    uVar2 = 0x14;
    if (uVar7 < 0x15) {
      uVar2 = uVar7;
    }
    memset(auStack_58 + uVar7,0,0x14 - uVar2);
    FUN_10016608(aiStack_78,auStack_58,0x14,param_4,(int *)local_40,0);
    uVar2 = 0;
    if (uVar7 != 0) {
      do {
        if (0x13 < uVar2) break;
        pbVar5 = (byte *)(*param_2 + uVar2);
        pbVar4 = local_40 + uVar2;
        uVar2 = uVar2 + 1;
        *pbVar5 = *pbVar4 ^ *pbVar5;
      } while (uVar2 < uVar7);
    }
    sVar3 = 0x14;
    if (param_6 < 0x15) {
      sVar3 = param_6;
    }
    iVar1 = FUN_10016448(param_5,local_40,sVar3,1);
    if (iVar1 == 0) goto LAB_10016a3c;
    param_5 = (void *)(sVar3 + (int)param_5);
    param_6 = param_6 - sVar3;
  } while( true );
}



/* 10016a48 FUN_10016a48 */

/* Boundary evidence: original MIPS .pdata 10016a48..10016a73. Semantic name remains unreviewed. */

void FUN_10016a48(undefined4 *param_1,int *param_2,uint *param_3,void *param_4,uint param_5)

{
  FUN_10016810(*param_1,param_2,param_3,(uint *)0x0,param_4,param_5);
  return;
}



/* 10016a74 CPGenRandom */

/* Boundary evidence: original MIPS .pdata 10016a74..10016afb. Semantic name remains unreviewed. */

undefined4 CPGenRandom(uint param_1,uint param_2,void *param_3)

{
  int iVar1;
  DWORD dwErrCode;
  
                    /* 0x16a74  21  CPGenRandom */
  iVar1 = FUN_100091fc(param_1,0);
  if (iVar1 == 0) {
    dwErrCode = 0x80090001;
  }
  else {
    dwErrCode = FUN_10016810(*(undefined4 *)(iVar1 + 0x9c),(int *)(iVar1 + 0x58),
                             (uint *)(iVar1 + 0x38),(uint *)0x0,param_3,param_2);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* 10016afc FUN_10016afc */

/* Boundary evidence: original MIPS .pdata 10016afc..10016b17. Semantic name remains unreviewed. */

void FUN_10016afc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  CeGenRandom(param_3);
  return;
}



/* 10016b18 FUN_10016b18 */

/* Boundary evidence: original MIPS .pdata 10016b18..10016b53. Semantic name remains unreviewed. */

undefined4 FUN_10016b18(undefined4 param_1,int *param_2,uint *param_3,uint *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = BSafeEncPublic(param_2,param_3,param_4);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = 8;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 10016b54 FUN_10016b54 */

bool FUN_10016b54(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if ((param_3 & 0x40) == 0) {
    uVar1 = param_2 + 0xb;
  }
  else {
    uVar1 = param_2 + 0x29;
  }
  return uVar1 <= param_1;
}



/* 10016b94 FUN_10016b94 */

/* Boundary evidence: original MIPS .pdata 10016b94..10016cfb. Semantic name remains unreviewed. */

undefined4 FUN_10016b94(void *param_1,uint param_2,SIZE_T param_3,undefined4 *param_4,int param_5)

{
  uint uVar1;
  HLOCAL pvVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  void *_Dst;
  uint uVar7;
  undefined4 local_a0;
  undefined1 local_9c [4];
  undefined1 auStack_98 [96];
  undefined1 auStack_38 [20];
  uint local_24;
  
  local_24 = DAT_1002da44;
  if (param_5 != 0) {
    pvVar2 = LocalAlloc(0x40,param_3);
    *param_4 = pvVar2;
    if (pvVar2 == (HLOCAL)0x0) {
      uVar6 = 8;
      goto LAB_10016ccc;
    }
  }
  uVar7 = (param_3 + 0x13) / 0x14;
  _Dst = (void *)*param_4;
  local_a0 = 0;
  if (uVar7 != 0) {
    do {
      uVar1 = local_a0;
      memset(auStack_98,0,0x5c);
      A_SHAInit((int)auStack_98);
      A_SHAUpdate(auStack_98,param_1,param_2);
      uVar3 = 0;
      puVar5 = (undefined1 *)((int)&local_a0 + 3);
      do {
        puVar4 = local_9c + uVar3;
        uVar3 = uVar3 + 1;
        *puVar4 = *puVar5;
        puVar5 = puVar5 + -1;
      } while (uVar3 < 4);
      A_SHAUpdate(auStack_98,local_9c,4);
      A_SHAFinal(auStack_98,(int)auStack_38);
      if (param_3 < 0x14) {
        memcpy(_Dst,auStack_38,param_3);
        break;
      }
      memcpy(_Dst,auStack_38,0x14);
      local_a0 = uVar1 + 1;
      param_3 = param_3 - 0x14;
      _Dst = (void *)((int)_Dst + 0x14);
    } while (local_a0 < uVar7);
  }
  uVar6 = 0;
LAB_10016ccc:
  FUN_1002bedc(local_24);
  return uVar6;
}



/* 10016cfc FUN_10016cfc */

/* Boundary evidence: original MIPS .pdata 10016cfc..10016f27. Semantic name remains unreviewed. */

int FUN_10016cfc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  HLOCAL hMem;
  uint uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  HLOCAL _Dst;
  uint uVar10;
  undefined4 local_d0;
  undefined1 local_cc [4];
  undefined1 auStack_c8 [96];
  undefined1 auStack_68 [24];
  byte local_50 [24];
  byte local_38 [20];
  uint local_24;
  
  local_24 = DAT_1002da44;
  iVar2 = FUN_10016a48((undefined4 *)(param_1 + 0x9c),(int *)(param_1 + 0x58),
                       (uint *)(param_1 + 0x38),local_50,0x14);
  if (iVar2 == 0) {
    hMem = LocalAlloc(0x40,param_3);
    if (hMem == (HLOCAL)0x0) {
      iVar2 = 8;
    }
    else {
      uVar10 = (param_3 + 0x13) / 0x14;
      local_d0 = (byte *)0x0;
      uVar9 = param_3;
      _Dst = hMem;
      if (uVar10 != 0) {
        do {
          uVar1 = (uint)local_d0;
          memset(auStack_c8,0,0x5c);
          A_SHAInit((int)auStack_c8);
          A_SHAUpdate(auStack_c8,local_50,0x14);
          uVar3 = 0;
          puVar6 = (undefined1 *)((int)&local_d0 + 3);
          do {
            puVar5 = local_cc + uVar3;
            uVar3 = uVar3 + 1;
            *puVar5 = *puVar6;
            puVar6 = puVar6 + -1;
          } while (uVar3 < 4);
          A_SHAUpdate(auStack_c8,local_cc,4);
          A_SHAFinal(auStack_c8,(int)auStack_68);
          if (uVar9 < 0x14) {
            memcpy(_Dst,auStack_68,uVar9);
            break;
          }
          memcpy(_Dst,auStack_68,0x14);
          local_d0 = (byte *)(uVar1 + 1);
          uVar9 = uVar9 - 0x14;
          _Dst = (HLOCAL)((int)_Dst + 0x14);
        } while (local_d0 < uVar10);
      }
      uVar9 = 0;
      if (param_3 != 0) {
        do {
          pbVar8 = (byte *)(param_2 + 0x15 + uVar9);
          pbVar4 = (byte *)(uVar9 + (int)hMem);
          uVar9 = uVar9 + 1;
          *pbVar8 = *pbVar4 ^ *pbVar8;
        } while (uVar9 < param_3);
      }
      local_d0 = local_38;
      iVar2 = FUN_10016b94((void *)(param_2 + 0x15),param_3,0x14,&local_d0,0);
      if (iVar2 == 0) {
        uVar9 = 0;
        do {
          pbVar4 = local_38 + uVar9;
          pbVar8 = local_50 + uVar9;
          pbVar7 = (byte *)(param_2 + 1 + uVar9);
          uVar9 = uVar9 + 1;
          *pbVar7 = *pbVar4 ^ *pbVar8;
        } while (uVar9 < 0x14);
        iVar2 = 0;
      }
    }
    if (hMem != (HLOCAL)0x0) {
      LocalFree(hMem);
    }
  }
  FUN_1002bedc(local_24);
  return iVar2;
}



/* 10016f28 FUN_10016f28 */

/* Boundary evidence: original MIPS .pdata 10016f28..1001715b. Semantic name remains unreviewed. */

int FUN_10016f28(char *param_1,int param_2)

{
  HLOCAL hMem;
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uBytes;
  HLOCAL _Dst;
  char *pcVar7;
  char *pcVar8;
  byte *pbVar9;
  undefined4 local_c0;
  undefined1 local_bc [4];
  undefined1 auStack_b8 [96];
  byte local_58 [24];
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_1002da44;
  memset(local_58,0,0x14);
  if (*param_1 == '\0') {
    uBytes = param_2 - 0x15;
    pcVar8 = param_1 + 0x15;
    local_c0 = local_58;
    iVar6 = FUN_10016b94(pcVar8,uBytes,0x14,&local_c0,0);
    if (iVar6 == 0) {
      uVar5 = 0;
      pcVar7 = param_1 + 1;
      do {
        pbVar4 = (byte *)(pcVar7 + uVar5);
        pbVar9 = local_58 + uVar5;
        uVar5 = uVar5 + 1;
        *pbVar4 = *pbVar9 ^ *pbVar4;
      } while (uVar5 < 0x14);
      hMem = LocalAlloc(0x40,uBytes);
      if (hMem == (HLOCAL)0x0) {
        iVar6 = 8;
      }
      else {
        pbVar9 = (byte *)((param_2 - 2U) / 0x14);
        local_c0 = (byte *)0x0;
        uVar5 = uBytes;
        _Dst = hMem;
        if (pbVar9 != (byte *)0x0) {
          do {
            pbVar4 = local_c0;
            memset(auStack_b8,0,0x5c);
            A_SHAInit((int)auStack_b8);
            A_SHAUpdate(auStack_b8,pcVar7,0x14);
            uVar1 = 0;
            puVar3 = (undefined1 *)((int)&local_c0 + 3);
            do {
              puVar2 = local_bc + uVar1;
              uVar1 = uVar1 + 1;
              *puVar2 = *puVar3;
              puVar3 = puVar3 + -1;
            } while (uVar1 < 4);
            A_SHAUpdate(auStack_b8,local_bc,4);
            A_SHAFinal(auStack_b8,(int)auStack_40);
            if (uVar5 < 0x14) {
              memcpy(_Dst,auStack_40,uVar5);
              break;
            }
            memcpy(_Dst,auStack_40,0x14);
            local_c0 = pbVar4 + 1;
            uVar5 = uVar5 - 0x14;
            _Dst = (HLOCAL)((int)_Dst + 0x14);
          } while (local_c0 < pbVar9);
        }
        uVar5 = 0;
        if (uBytes != 0) {
          do {
            pbVar4 = (byte *)(pcVar8 + uVar5);
            pbVar9 = (byte *)(uVar5 + (int)hMem);
            uVar5 = uVar5 + 1;
            *pbVar4 = *pbVar9 ^ *pbVar4;
          } while (uVar5 < uBytes);
        }
        iVar6 = 0;
      }
      if (hMem != (HLOCAL)0x0) {
        LocalFree(hMem);
      }
    }
  }
  else {
    iVar6 = -0x7ff6fffb;
  }
  FUN_1002bedc(local_2c);
  return iVar6;
}



/* 1001715c FUN_1001715c */

/* Boundary evidence: original MIPS .pdata 1001715c..100171df. Semantic name remains unreviewed. */

undefined4 FUN_1001715c(void *param_1,void *param_2,void *param_3,size_t param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_5 == 0) || (iVar1 = memcmp(param_1,param_3,param_4), iVar1 != 0)) &&
     (iVar1 = memcmp(param_1,param_2,param_4), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80090003;
  }
  return uVar2;
}



/* 100171e0 FUN_100171e0 */

/* Boundary evidence: original MIPS .pdata 100171e0..1001736f. Semantic name remains unreviewed. */

undefined4 FUN_100171e0(undefined4 param_1,void *param_2,void *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  int *_Dst;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint local_30;
  uint local_2c;
  uint auStack_28 [2];
  
  uVar4 = *(uint *)((int)param_2 + 8) + 7;
  FUN_1000aa40(&local_30,param_2,uVar4,(uint)(uVar4 < *(uint *)((int)param_2 + 8)));
  uVar5 = 8;
  local_2c = 8;
  FUN_10012fb0(&local_2c,(int *)&local_30,local_30 >> 3 & 7);
  if (local_30 != 8) {
    FUN_10013140(&local_30,8);
  }
  FUN_1000f968(&local_30,local_30,2);
  local_2c = *(uint *)((int)param_2 + 8);
  puVar2 = FUN_1000f9e4(&local_2c,auStack_28,0xf);
  FUN_1000f968(&local_2c,*puVar2,0x10);
  puVar2 = FUN_10013000(&local_2c,auStack_28,local_30);
  FUN_1000aa98(&local_2c,*puVar2,10);
  FUN_1000ab10(&local_2c,&local_30,0x14);
  _Dst = LocalAlloc(0x40,local_30);
  if (_Dst != (int *)0x0) {
    memcpy(_Dst,param_2,local_30);
    iVar3 = BSafeDecPrivate(_Dst,param_3,param_4);
    piVar1 = _Dst;
    if (iVar3 != 0) {
      uVar5 = 0;
    }
    for (; local_30 != 0; local_30 = local_30 - 1) {
      *(undefined1 *)piVar1 = 0;
      piVar1 = (int *)((int)piVar1 + 1);
    }
    LocalFree(_Dst);
  }
  return uVar5;
}



/* 10017370 FUN_10017370 */

/* Boundary evidence: original MIPS .pdata 10017370..100175cb. Semantic name remains unreviewed. */

int FUN_10017370(int param_1,int *param_2,void *param_3,size_t param_4,void *param_5,uint param_6,
                void *param_7)

{
  bool bVar1;
  uint *_Dst;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint *_Src;
  int iVar6;
  uint local_a8;
  uint local_a4;
  undefined1 auStack_a0 [96];
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_1002da44;
  memset(auStack_a0,0,0x5c);
  A_SHAInit((int)auStack_a0);
  if (param_6 != 0) {
    A_SHAUpdate(auStack_a0,param_5,param_6);
  }
  puVar4 = auStack_40;
  A_SHAFinal(auStack_a0,(int)puVar4);
  uVar3 = param_2[2] + 7;
  FUN_1000aa40(&local_a8,puVar4,uVar3,(uint)(uVar3 < (uint)param_2[2]));
  local_a8 = local_a8 >> 3;
  local_a4 = FUN_1000a9f4(param_2[1],2);
  FUN_10013000(&local_a4,&local_a8,local_a8);
  uVar3 = local_a8;
  _Dst = LocalAlloc(0x40,local_a8);
  if ((_Dst != (uint *)0x0) && (uVar3 != 0)) {
    _Src = (uint *)(param_2[1] + (int)_Dst);
    iVar6 = param_2[1] * 2 + (int)_Dst;
    memcpy((void *)(iVar6 + 0x15),auStack_40,0x14);
    puVar4 = (undefined1 *)(((param_2[2] + 7U >> 3) - param_4) + -1 + iVar6);
    *puVar4 = 1;
    memcpy(puVar4 + 1,param_3,param_4);
    iVar2 = FUN_10016cfc(param_1,iVar6,(param_2[2] + 7U >> 3) - 0x15);
    if (iVar2 != 0) goto LAB_1001755c;
    uVar3 = param_2[2] + 7U >> 3;
    uVar5 = 0;
    if (uVar3 != 0) {
      do {
        *(undefined1 *)(uVar5 + (int)_Dst) = *(undefined1 *)((uVar3 - uVar5) + iVar6 + -1);
        uVar5 = uVar5 + 1;
        uVar3 = param_2[2] + 7U >> 3;
      } while (uVar5 < uVar3);
    }
    bVar1 = BSafeEncPublic(param_2,_Dst,_Src);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      memcpy(param_7,_Src,param_2[2] + 7U >> 3);
      iVar2 = 0;
      goto LAB_1001755c;
    }
  }
  iVar2 = 8;
LAB_1001755c:
  if (_Dst != (uint *)0x0) {
    memset(_Dst,0,(param_2[2] + 7U >> 3) + param_2[1] * 2);
    LocalFree(_Dst);
  }
  FUN_1002bedc(local_2c);
  return iVar2;
}



/* 100175cc FUN_100175cc */

/* Boundary evidence: original MIPS .pdata 100175cc..100178b3. Semantic name remains unreviewed. */

int FUN_100175cc(int param_1,void *param_2,void *param_3,uint param_4,void *param_5,uint param_6,
                int *param_7,uint *param_8)

{
  uint *_Dst;
  HLOCAL pvVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint _Size;
  uint uBytes;
  char *pcVar7;
  uint local_b0;
  void *local_ac;
  void *local_a8;
  undefined1 auStack_a0 [96];
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_1002da44;
  local_ac = param_5;
  local_a8 = param_3;
  memset(auStack_a0,0,0x5c);
  _Size = *(int *)((int)param_2 + 8) + 7U >> 3;
  if (_Size < param_4) {
    iVar6 = -0x7ff6fffb;
    goto LAB_10017878;
  }
  uVar2 = *(uint *)((int)param_2 + 4) + 2;
  FUN_1000aa40(&local_b0,*(int *)((int)param_2 + 8),uVar2,
               (uint)(uVar2 < *(uint *)((int)param_2 + 4)));
  uVar2 = local_b0 + 4;
  if (uVar2 < local_b0) {
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  uVar2 = uVar2 & 0xfffffffc;
  FUN_1000aa98(&local_b0,uVar2,2);
  FUN_100130f4(&local_b0,local_b0,_Size);
  _Dst = LocalAlloc(0x40,local_b0);
  if (_Dst == (uint *)0x0) {
LAB_10017834:
    iVar6 = 8;
  }
  else {
    pcVar7 = (char *)(uVar2 * 2 + (int)_Dst);
    memcpy((void *)(uVar2 + (int)_Dst),local_a8,_Size);
    iVar6 = FUN_100171e0(*(undefined4 *)(param_1 + 0xb4),param_2,(void *)(uVar2 + (int)_Dst),_Dst);
    if (iVar6 == 0) {
      uVar5 = 0;
      if (_Size != 0) {
        pcVar3 = (char *)(_Size + (int)_Dst);
        do {
          pcVar3 = pcVar3 + -1;
          pcVar4 = pcVar7 + uVar5;
          uVar5 = uVar5 + 1;
          *pcVar4 = *pcVar3;
        } while (uVar5 < _Size);
      }
      iVar6 = FUN_10016f28(pcVar7,_Size);
      if (iVar6 == 0) {
        A_SHAInit((int)auStack_a0);
        if (param_6 != 0) {
          A_SHAUpdate(auStack_a0,local_ac,param_6);
        }
        A_SHAFinal(auStack_a0,(int)auStack_40);
        iVar6 = memcmp(auStack_40,pcVar7 + 0x15,0x14);
        if (iVar6 == 0) {
          uVar5 = 0x29;
          if (0x29 < _Size) {
            do {
              if (pcVar7[uVar5] == '\x01') {
                uVar5 = uVar5 + 1;
                break;
              }
              if (pcVar7[uVar5] != '\0') goto LAB_100177ec;
              uVar5 = uVar5 + 1;
            } while (uVar5 < _Size);
          }
          uBytes = _Size - uVar5;
          if (*param_7 == 0) {
            pvVar1 = LocalAlloc(0x40,uBytes);
            *param_7 = (int)pvVar1;
            if (pvVar1 == (HLOCAL)0x0) goto LAB_10017834;
          }
          else if (*param_8 < uBytes) {
            iVar6 = 0xea;
            goto LAB_10017854;
          }
          *param_8 = uBytes;
          memcpy((void *)*param_7,pcVar7 + uVar5,uBytes);
          iVar6 = 0;
        }
        else {
LAB_100177ec:
          iVar6 = -0x7ff6fffb;
        }
      }
    }
  }
LAB_10017854:
  if (_Dst != (uint *)0x0) {
    memset(_Dst,0,uVar2 * 2 + _Size);
    LocalFree(_Dst);
  }
LAB_10017878:
  FUN_1002bedc(local_2c);
  return iVar6;
}



/* 100178b4 FUN_100178b4 */

/* Boundary evidence: original MIPS .pdata 100178b4..10017b77. Semantic name remains unreviewed. */

int FUN_100178b4(int param_1,undefined4 param_2,int *param_3,int param_4,uint param_5,void *param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  SIZE_T uBytes;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint *hMem;
  int iVar7;
  char *pcVar8;
  uint *_Src;
  
  hMem = (uint *)0x0;
  if ((((*param_3 == 0x31415352) || (*param_3 == 0x32415352)) && (uVar4 = param_3[2], 0x3f < uVar4))
     && (uVar4 < 0x100001)) {
    uVar6 = param_3[1];
    if ((((uint)param_3[3] < uVar6) && (uVar6 < 0x1000001)) && ((uVar4 + 7 >> 3) - 1 == param_3[3]))
    {
      uVar4 = (uint)((ulonglong)uVar6 * 2);
      if ((int)((ulonglong)uVar6 * 2 >> 0x20) != 0) {
        RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
      }
      uBytes = uVar4 + 4;
      if (uBytes < uVar4) {
        uBytes = 0;
        RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
      }
      hMem = LocalAlloc(0x40,uBytes);
      if (hMem == (uint *)0x0) {
LAB_10017b04:
        iVar2 = 8;
      }
      else {
        iVar2 = param_3[1];
        *(undefined1 *)((int)hMem + param_3[3] + -1) = 2;
        _Src = (uint *)((iVar2 + 4U & 0xfffffffc) + (int)hMem);
        pcVar8 = (char *)((int)hMem + param_5 + 1);
        iVar2 = FUN_10016a48((undefined4 *)(param_1 + 0x9c),(int *)(param_1 + 0x58),
                             (uint *)(param_1 + 0x38),pcVar8,(param_3[3] - param_5) - 2);
        if (iVar2 == 0) {
          iVar7 = (param_3[3] - param_5) + -2;
joined_r0x10017a64:
          for (; iVar7 != 0; iVar7 = iVar7 + -1) {
            if (*pcVar8 == '\0') goto code_r0x10017a78;
            pcVar8 = pcVar8 + 1;
          }
          uVar4 = 0;
          if (param_5 != 0) {
            puVar3 = (undefined1 *)(param_4 + param_5);
            do {
              puVar3 = puVar3 + -1;
              puVar5 = (undefined1 *)(uVar4 + (int)hMem);
              uVar4 = uVar4 + 1;
              *puVar5 = *puVar3;
            } while (uVar4 < param_5);
          }
          bVar1 = BSafeEncPublic(param_3,hMem,_Src);
          if (CONCAT31(extraout_var,bVar1) != 0) {
            memcpy(param_6,_Src,param_3[2] + 7U >> 3);
            iVar2 = 0;
            goto LAB_10017b34;
          }
          goto LAB_10017b04;
        }
      }
      goto LAB_10017b34;
    }
  }
  iVar2 = -0x7ff6ffeb;
LAB_10017b34:
  if (hMem != (uint *)0x0) {
    LocalFree(hMem);
  }
  return iVar2;
code_r0x10017a78:
  iVar2 = FUN_10016a48((undefined4 *)(param_1 + 0x9c),(int *)(param_1 + 0x58),
                       (uint *)(param_1 + 0x38),pcVar8,1);
  if (iVar2 != 0) goto LAB_10017b34;
  goto joined_r0x10017a64;
}



/* 10017b78 FUN_10017b78 */

/* Boundary evidence: original MIPS .pdata 10017b78..10017dc3. Semantic name remains unreviewed. */

int FUN_10017b78(int param_1,int *param_2,undefined4 param_3,void *param_4,int *param_5,
                uint *param_6)

{
  HLOCAL pvVar1;
  SIZE_T uBytes;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 *puVar6;
  uint *hMem;
  uint uVar7;
  
  uVar4 = param_2[2];
  hMem = (uint *)0x0;
  uVar7 = uVar4 + 7 >> 3;
  if ((((*param_2 == 0x31415352) || (*param_2 == 0x32415352)) && (0x3f < uVar4)) &&
     (uVar4 < 0x100001)) {
    uVar4 = param_2[1];
    if ((((uint)param_2[3] < uVar4) && (uVar4 < 0x1000001)) && (uVar7 - 1 == param_2[3])) {
      uBytes = (SIZE_T)((ulonglong)uVar4 * 2);
      if ((int)((ulonglong)uVar4 * 2 >> 0x20) != 0) {
        uBytes = 0;
        RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
      }
      hMem = LocalAlloc(0x40,uBytes);
      if (hMem == (uint *)0x0) {
LAB_10017d30:
        iVar2 = 8;
      }
      else {
        iVar2 = param_2[1];
        memcpy((void *)(iVar2 + (int)hMem),param_4,uVar7);
        iVar2 = FUN_100171e0(*(undefined4 *)(param_1 + 0xb4),param_2,(void *)(iVar2 + (int)hMem),
                             hMem);
        if (iVar2 != 0) goto LAB_10017d88;
        pcVar5 = (char *)(param_2[3] + (int)hMem);
        if ((pcVar5[-1] != '\x02') || (*pcVar5 != '\0')) {
          iVar2 = -0x7ff6fffb;
          goto LAB_10017d88;
        }
        for (uVar4 = param_2[3] - 2; (uVar4 != 0 && (*(char *)(uVar4 + (int)hMem) != '\0'));
            uVar4 = uVar4 - 1) {
        }
        if (*param_5 == 0) {
          pvVar1 = LocalAlloc(0x40,uVar4);
          *param_5 = (int)pvVar1;
          if (pvVar1 == (HLOCAL)0x0) goto LAB_10017d30;
        }
        else if (*param_6 < uVar4) {
          iVar2 = 0xea;
          goto LAB_10017d88;
        }
        *param_6 = uVar4;
        uVar7 = 0;
        if (uVar4 != 0) {
          puVar3 = (undefined1 *)(uVar4 + (int)hMem);
          do {
            puVar3 = puVar3 + -1;
            puVar6 = (undefined1 *)(*param_5 + uVar7);
            uVar7 = uVar7 + 1;
            *puVar6 = *puVar3;
          } while (uVar7 < uVar4);
        }
        iVar2 = 0;
      }
      goto LAB_10017d88;
    }
  }
  iVar2 = -0x7ff6ffeb;
LAB_10017d88:
  if (hMem != (uint *)0x0) {
    LocalFree(hMem);
  }
  return iVar2;
}



/* 10017dc4 FUN_10017dc4 */

/* Boundary evidence: original MIPS .pdata 10017dc4..10017e6f. Semantic name remains unreviewed. */

int FUN_10017dc4(int param_1,int *param_2,void *param_3,size_t param_4,void *param_5,uint param_6,
                uint param_7,void *param_8)

{
  int iVar1;
  uint uVar2;
  
  if ((param_7 & 0x40) == 0) {
    uVar2 = param_4 + 0xb;
  }
  else {
    uVar2 = param_4 + 0x29;
  }
  if (param_2[2] + 7U >> 3 < uVar2) {
    iVar1 = -0x7ff6fffc;
  }
  else {
    if ((param_7 & 0x40) == 0) {
      iVar1 = FUN_100178b4(param_1,param_7,param_2,(int)param_3,param_4,param_8);
    }
    else {
      iVar1 = FUN_10017370(param_1,param_2,param_3,param_4,param_5,param_6,param_8);
    }
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 10017e70 FUN_10017e70 */

/* Boundary evidence: original MIPS .pdata 10017e70..10018067. Semantic name remains unreviewed. */

int FUN_10017e70(int param_1,int *param_2,void *param_3,size_t param_4,void *param_5,uint param_6,
                uint param_7,int *param_8,uint *param_9)

{
  int iVar1;
  int iVar2;
  SIZE_T uBytes;
  uint uVar3;
  HLOCAL _Dst;
  
  _Dst = (HLOCAL)0x0;
  if ((param_7 & 0x40) == 0) {
    if ((param_7 & 0x20) == 0) {
      iVar1 = FUN_10017b78(param_1,param_2,param_7,param_3,param_8,param_9);
      goto LAB_10017eec;
    }
    if (((*param_8 == 0) || (uVar3 = param_2[2] + 7U >> 3, *param_9 != uVar3)) || (param_4 != uVar3)
       ) {
      return -0x7ff6fffb;
    }
    uBytes = (SIZE_T)((ulonglong)(uint)param_2[1] * 2);
    if ((int)((ulonglong)(uint)param_2[1] * 2 >> 0x20) != 0) {
      uBytes = 0;
      RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
    }
    _Dst = LocalAlloc(0x40,uBytes);
    if (_Dst == (HLOCAL)0x0) {
      iVar1 = 8;
      goto LAB_10017efc;
    }
    memset(_Dst,0,param_2[1] << 1);
    iVar2 = param_2[1];
    memcpy(_Dst,param_3,param_4);
    iVar1 = FUN_100171e0(*(undefined4 *)(param_1 + 0xb4),param_2,_Dst,(uint *)(iVar2 + (int)_Dst));
    if (iVar1 != 0) goto LAB_10017efc;
    memcpy((void *)*param_8,(uint *)(iVar2 + (int)_Dst),*param_9);
  }
  else {
    iVar1 = FUN_100175cc(param_1,param_2,param_3,param_4,param_5,param_6,param_8,param_9);
LAB_10017eec:
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = 0;
LAB_10017efc:
  if (_Dst != (HLOCAL)0x0) {
    LocalFree(_Dst);
  }
  return iVar1;
}



/* 10018068 FUN_10018068 */

/* Boundary evidence: original MIPS .pdata 10018068..10018317. Semantic name remains unreviewed. */

int FUN_10018068(int *param_1,int *param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint *puVar2;
  SIZE_T uBytes;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *_Dst;
  uint *puVar7;
  uint *puVar8;
  
  _Dst = (uint *)0x0;
  if ((((*param_2 == 0x31415352) || (*param_2 == 0x32415352)) && (uVar4 = param_2[2], 0x3f < uVar4))
     && (uVar4 < 0x100001)) {
    uVar5 = param_2[1];
    if ((((uint)param_2[3] < uVar5) && (uVar5 < 0x1000001)) && ((uVar4 + 7 >> 3) - 1 == param_2[3]))
    {
      if (((*param_1 != 0x31415352) && (*param_1 != 0x32415352)) ||
         ((uVar3 = param_1[2], uVar3 < 0x40 || (0x100000 < uVar3)))) {
        return -0x7ff6fffd;
      }
      if ((uint)param_1[1] <= (uint)param_1[3]) {
        return -0x7ff6fffd;
      }
      if (0x1000000 < (uint)param_1[1]) {
        return -0x7ff6fffd;
      }
      if ((uVar3 + 7 >> 3) - 1 != param_1[3]) {
        return -0x7ff6fffd;
      }
      uBytes = (SIZE_T)((ulonglong)uVar5 * 3);
      uVar4 = uVar4 >> 3;
      if ((int)((ulonglong)uVar5 * 3 >> 0x20) != 0) {
        uBytes = 0;
        RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
      }
      _Dst = LocalAlloc(0x40,uBytes);
      puVar7 = (uint *)(uVar5 + (int)_Dst);
      puVar8 = (uint *)(uVar5 * 2 + (int)_Dst);
      if (_Dst == (uint *)0x0) {
        iVar6 = 8;
        goto LAB_100182d8;
      }
      if (uVar4 <= uVar5) {
        memset(_Dst,0xff,uVar4 - 1);
        iVar6 = 0x10;
        puVar2 = _Dst;
        do {
          *(char *)puVar2 = ('\x01' - (char)_Dst) + (char)puVar2;
          iVar6 = iVar6 + -1;
          puVar2 = (uint *)((int)puVar2 + 1);
        } while (iVar6 != 0);
        iVar6 = BSafeDecPrivate(param_2,_Dst,puVar7);
        if ((iVar6 != 0) &&
           (bVar1 = BSafeEncPublic(param_1,puVar7,puVar8), CONCAT31(extraout_var,bVar1) != 0)) {
          iVar6 = FUN_1001715c(_Dst,puVar8,puVar7,uVar4,param_3);
          if (iVar6 != 0) goto LAB_100182d8;
          bVar1 = BSafeEncPublic(param_1,_Dst,puVar7);
          if ((CONCAT31(extraout_var_00,bVar1) != 0) &&
             (iVar6 = BSafeDecPrivate(param_2,puVar7,puVar8), iVar6 != 0)) {
            iVar6 = FUN_1001715c(_Dst,puVar8,puVar7,uVar4,param_3);
            goto LAB_100182d8;
          }
        }
      }
    }
  }
  iVar6 = -0x7ff6fffd;
LAB_100182d8:
  if (_Dst != (uint *)0x0) {
    LocalFree(_Dst);
  }
  return iVar6;
}



/* 10018318 FUN_10018318 */

/* Boundary evidence: original MIPS .pdata 10018318..10018883. Semantic name remains unreviewed. */

DWORD FUN_10018318(uint param_1,uint param_2,int param_3,uint *param_4,uint param_5)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  uint *puVar4;
  undefined3 extraout_var;
  int iVar5;
  DWORD DVar6;
  int *hMem;
  int *hMem_00;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  uint local_6c;
  int local_68;
  uint local_64;
  undefined4 local_60;
  SIZE_T local_5c;
  uint *local_58;
  SIZE_T local_54;
  uint *local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  int *local_40;
  int *local_3c;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  uint *local_2c;
  
  hMem = (int *)0x0;
  local_40 = (int *)0x0;
  hMem_00 = (int *)0x0;
  local_3c = (int *)0x0;
  bVar1 = false;
  local_60 = 0;
  uVar9 = 0;
  local_38 = 0;
  local_68 = 0;
  local_6c = 0;
  local_44 = param_3;
  local_30 = param_2;
  puVar4 = (uint *)FUN_100091fc(param_1,0);
  local_2c = puVar4;
  if (puVar4 == (uint *)0x0) {
    DVar6 = 0x80090001;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar4 + 0x28));
    uVar9 = 1;
    local_64 = 1;
    local_38 = 1;
    local_34 = param_5;
    bVar3 = BSafeComputeKeySizes((int *)&local_54,(int *)&local_5c,&local_34);
    if (CONCAT31(extraout_var,bVar3) == 0) {
      DVar6 = 0x80090020;
    }
    else {
      hMem = LocalAlloc(0x40,local_54);
      local_40 = hMem;
      if (hMem == (int *)0x0) {
        DVar6 = 8;
      }
      else {
        bVar1 = true;
        local_60 = 1;
        hMem_00 = LocalAlloc(0x40,local_5c);
        local_3c = hMem_00;
        if (hMem_00 == (int *)0x0) {
          DVar6 = 8;
        }
        else {
          iVar5 = FUN_1001a65c(hMem,hMem_00,param_5);
          if (iVar5 == 0) {
            DVar6 = 0x80090020;
          }
          else {
            DVar6 = FUN_10018068(hMem,hMem_00,1);
            if ((DVar6 == 0) && (DVar6 = FUN_1000ab60(0,hMem,hMem_00), DVar6 == 0)) {
              if (local_44 == 0) {
                puVar8 = puVar4 + 0x10;
                puVar10 = puVar4 + 0x1d;
                local_50 = puVar4 + 10;
                local_58 = puVar4 + 0x1c;
                puVar7 = puVar4 + 0x12;
                local_4c = local_64;
                local_48 = DAT_1002dcc4;
              }
              else {
                puVar8 = puVar4 + 0x13;
                puVar10 = puVar4 + 0x1b;
                local_50 = puVar4 + 0xc;
                local_58 = puVar4 + 0x1a;
                puVar7 = puVar4 + 0x15;
                local_4c = 0;
                local_48 = DAT_1002dcc8;
              }
              if ((HLOCAL)*puVar8 != (HLOCAL)0x0) {
                LocalFree((HLOCAL)*puVar8);
                LocalFree((HLOCAL)*puVar10);
              }
              uVar2 = local_30;
              uVar9 = local_64;
              local_60 = 0;
              *local_58 = local_5c;
              *local_50 = local_54;
              *puVar10 = (uint)hMem_00;
              *puVar8 = (uint)hMem;
              if ((local_30 & 1) == 0) {
                *puVar7 = 0;
              }
              else {
                *puVar7 = local_64;
              }
              if (((*puVar4 & 0xf0000000) == 0) &&
                 (DVar6 = FUN_1000b8ec(puVar4,local_48,local_30,local_4c), DVar6 != 0)) {
                bVar1 = false;
              }
              else {
                if (local_44 == 0) {
                  iVar5 = CPGetUserKey(param_1,2,&local_6c);
                  if (iVar5 == 0) {
                    DVar6 = GetLastError();
                    bVar1 = false;
                    goto LAB_100187f8;
                  }
                  DVar6 = FUN_10009224(local_6c,param_1,3,&local_68);
                  if (DVar6 != 0) {
                    if (DVar6 == 0x80090020) {
                      DVar6 = 0x80090003;
                    }
                    bVar1 = false;
                    goto LAB_100187f8;
                  }
                }
                else {
                  iVar5 = CPGetUserKey(param_1,1,&local_6c);
                  if (iVar5 == 0) {
                    DVar6 = GetLastError();
                    bVar1 = false;
                    goto LAB_100187f8;
                  }
                  DVar6 = FUN_10009224(local_6c,param_1,4,&local_68);
                  if (DVar6 != 0) {
                    if (DVar6 == 0x80090020) {
                      DVar6 = 0x80090003;
                    }
                    bVar1 = false;
                    goto LAB_100187f8;
                  }
                }
                if ((uVar2 & 0x4000) != 0) {
                  *(uint *)(local_68 + 8) = *(uint *)(local_68 + 8) | 0x4000;
                  *(uint *)(local_68 + 0x70) = *(uint *)(local_68 + 0x70) | 0x100;
                }
                bVar1 = false;
                *param_4 = local_6c;
                DVar6 = 0;
              }
            }
          }
        }
      }
    }
  }
LAB_100187f8:
  if (uVar9 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar4 + 0x28));
  }
  if (bVar1) {
    if (hMem_00 != (int *)0x0) {
      LocalFree(hMem_00);
    }
    if (hMem != (int *)0x0) {
      LocalFree(hMem);
    }
  }
  return DVar6;
}



/* 10018884 FUN_10018884 */

/* Boundary evidence: original MIPS .pdata 10018884..1001888f. Semantic name remains unreviewed. */

undefined4 FUN_10018884(void)

{
  return 1;
}



/* 10018890 A_SHAInit */

void A_SHAInit(int param_1)

{
                    /* 0x18890  2  A_SHAInit */
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0x67452301;
  *(undefined4 *)(param_1 + 0x44) = 0xefcdab89;
  *(undefined4 *)(param_1 + 0x48) = 0x98badcfe;
  *(undefined4 *)(param_1 + 0x4c) = 0x10325476;
  *(undefined4 *)(param_1 + 0x50) = 0xc3d2e1f0;
  return;
}



/* 100188d8 FUN_100188d8 */

void FUN_100188d8(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = (uint *)(param_1 + 0x20);
  iVar2 = 0x40;
  do {
    uVar3 = puVar1[-8] ^ puVar1[5] ^ puVar1[-6] ^ *puVar1;
    puVar1[8] = uVar3 >> 0x1f | uVar3 << 1;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0);
  return;
}



/* 10018920 FUN_10018920 */

/* Boundary evidence: original MIPS .pdata 10018920..10019b1f. Semantic name remains unreviewed. */

void FUN_10018920(uint *param_1,int param_2)

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
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
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
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
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
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  uVar9 = *param_1;
  uVar7 = param_1[1];
  uVar8 = param_1[2];
  uVar6 = param_1[3];
  uVar5 = param_1[4];
  FUN_10026988(&local_160,0x10,param_2);
  FUN_100188d8((int)&local_160);
  uVar1 = uVar7 >> 2 | uVar7 << 0x1e;
  uVar5 = (uVar9 >> 0x1b | uVar9 << 5) + ((uVar6 ^ uVar8) & uVar7 ^ uVar6) + local_160 + uVar5 +
          0x5a827999;
  uVar7 = uVar9 >> 2 | uVar9 << 0x1e;
  uVar9 = (uVar5 >> 0x1b | uVar5 * 0x20) + ((uVar8 ^ uVar1) & uVar9 ^ uVar8) + local_15c + uVar6 +
          0x5a827999;
  uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar8 = (uVar9 >> 0x1b | uVar9 * 0x20) + ((uVar1 ^ uVar7) & uVar5 ^ uVar1) + local_158 + uVar8 +
          0x5a827999;
  uVar6 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar5 = (uVar8 >> 0x1b | uVar8 * 0x20) + ((uVar2 ^ uVar7) & uVar9 ^ uVar7) + local_154 + uVar1 +
          0x5a827999;
  uVar1 = (uVar5 >> 0x1b | uVar5 * 0x20) + ((uVar2 ^ uVar6) & uVar8 ^ uVar2) + local_150 + uVar7 +
          0x5a827999;
  uVar7 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar9 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar8 = (uVar1 >> 0x1b | uVar1 * 0x20) + ((uVar6 ^ uVar7) & uVar5 ^ uVar6) + local_14c + uVar2 +
          0x5a827999;
  uVar5 = (uVar8 >> 0x1b | uVar8 * 0x20) + ((uVar7 ^ uVar9) & uVar1 ^ uVar7) + local_148 + uVar6 +
          0x5a827999;
  uVar6 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar1 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar7 = (uVar5 >> 0x1b | uVar5 * 0x20) + ((uVar9 ^ uVar6) & uVar8 ^ uVar9) + local_144 + uVar7 +
          0x5a827999;
  uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar9 = (uVar7 >> 0x1b | uVar7 * 0x20) + ((uVar1 ^ uVar6) & uVar5 ^ uVar6) + local_140 + uVar9 +
          0x5a827999;
  uVar8 = uVar7 >> 2 | uVar7 * 0x40000000;
  uVar5 = (uVar9 >> 0x1b | uVar9 * 0x20) + ((uVar1 ^ uVar2) & uVar7 ^ uVar1) + local_13c + uVar6 +
          0x5a827999;
  uVar7 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar1 = (uVar5 >> 0x1b | uVar5 * 0x20) + ((uVar2 ^ uVar8) & uVar9 ^ uVar2) + local_138 + uVar1 +
          0x5a827999;
  uVar3 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar9 = (uVar1 >> 0x1b | uVar1 * 0x20) + ((uVar8 ^ uVar7) & uVar5 ^ uVar8) + local_134 + uVar2 +
          0x5a827999;
  uVar5 = (uVar9 >> 0x1b | uVar9 * 0x20) + ((uVar7 ^ uVar3) & uVar1 ^ uVar7) + local_130 + uVar8 +
          0x5a827999;
  uVar6 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar1 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar7 = (uVar5 >> 0x1b | uVar5 * 0x20) + ((uVar6 ^ uVar3) & uVar9 ^ uVar3) + local_12c + uVar7 +
          0x5a827999;
  uVar9 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar8 = (uVar7 >> 0x1b | uVar7 * 0x20) + ((uVar6 ^ uVar1) & uVar5 ^ uVar6) + local_128 + uVar3 +
          0x5a827999;
  uVar5 = (uVar8 >> 0x1b | uVar8 * 0x20) + ((uVar1 ^ uVar9) & uVar7 ^ uVar1) + local_124 + uVar6 +
          0x5a827999;
  uVar6 = uVar7 >> 2 | uVar7 * 0x40000000;
  uVar7 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar1 = (uVar5 >> 0x1b | uVar5 * 0x20) + ((uVar9 ^ uVar6) & uVar8 ^ uVar9) + local_120 + uVar1 +
          0x5a827999;
  uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar8 = (uVar1 >> 0x1b | uVar1 * 0x20) + ((uVar6 ^ uVar7) & uVar5 ^ uVar6) + local_11c + uVar9 +
          0x5a827999;
  uVar5 = (uVar8 >> 0x1b | uVar8 * 0x20) + ((uVar2 ^ uVar7) & uVar1 ^ uVar7) + local_118 + uVar6 +
          0x5a827999;
  uVar1 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar6 = (uVar5 >> 0x1b | uVar5 * 0x20) + ((uVar2 ^ uVar1) & uVar8 ^ uVar2) + local_114 + uVar7 +
          0x5a827999;
  uVar7 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar8 = (uVar6 >> 0x1b | uVar6 * 0x20) + (uVar1 ^ uVar7 ^ uVar5) + local_110 + uVar2 + 0x6ed9eba1;
  uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar5 = (uVar8 >> 0x1b | uVar8 * 0x20) + (uVar7 ^ uVar2 ^ uVar6) + local_10c + uVar1 + 0x6ed9eba1;
  uVar6 = uVar6 >> 2 | uVar6 * 0x40000000;
  uVar1 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar9 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar8 ^ uVar2 ^ uVar6) + local_108 + uVar7 + 0x6ed9eba1;
  uVar3 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar7 = (uVar9 >> 0x1b | uVar9 * 0x20) + (uVar1 ^ uVar5 ^ uVar6) + local_104 + uVar2 + 0x6ed9eba1;
  uVar8 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar5 = (uVar7 >> 0x1b | uVar7 * 0x20) + (uVar1 ^ uVar3 ^ uVar9) + local_100 + uVar6 + 0x6ed9eba1;
  uVar1 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar3 ^ uVar8 ^ uVar7) + local_fc + uVar1 + 0x6ed9eba1;
  uVar7 = uVar7 >> 2 | uVar7 * 0x40000000;
  uVar9 = (uVar1 >> 0x1b | uVar1 * 0x20) + (uVar8 ^ uVar7 ^ uVar5) + local_f8 + uVar3 + 0x6ed9eba1;
  uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar5 = (uVar9 >> 0x1b | uVar9 * 0x20) + (uVar1 ^ uVar7 ^ uVar2) + local_f4 + uVar8 + 0x6ed9eba1;
  uVar6 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar1 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar9 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar6 ^ uVar9 ^ uVar2) + local_f0 + uVar7 + 0x6ed9eba1;
  uVar3 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar7 = (uVar9 >> 0x1b | uVar9 * 0x20) + (uVar6 ^ uVar1 ^ uVar5) + local_ec + uVar2 + 0x6ed9eba1;
  uVar8 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar5 = (uVar7 >> 0x1b | uVar7 * 0x20) + (uVar1 ^ uVar3 ^ uVar9) + local_e8 + uVar6 + 0x6ed9eba1;
  uVar1 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar3 ^ uVar8 ^ uVar7) + local_e4 + uVar1 + 0x6ed9eba1;
  uVar7 = uVar7 >> 2 | uVar7 * 0x40000000;
  uVar9 = (uVar1 >> 0x1b | uVar1 * 0x20) + (uVar5 ^ uVar8 ^ uVar7) + local_e0 + uVar3 + 0x6ed9eba1;
  uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar5 = (uVar9 >> 0x1b | uVar9 * 0x20) + (uVar2 ^ uVar1 ^ uVar7) + local_dc + uVar8 + 0x6ed9eba1;
  uVar6 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar1 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar9 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar2 ^ uVar6 ^ uVar9) + local_d8 + uVar7 + 0x6ed9eba1;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar8 = (uVar9 >> 0x1b | uVar9 * 0x20) + (uVar6 ^ uVar1 ^ uVar5) + local_d4 + uVar2 + 0x6ed9eba1;
  uVar5 = (uVar8 >> 0x1b | uVar8 * 0x20) + (uVar1 ^ uVar7 ^ uVar9) + local_d0 + uVar6 + 0x6ed9eba1;
  uVar2 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar9 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar1 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar8 ^ uVar7 ^ uVar2) + local_cc + uVar1 + 0x6ed9eba1;
  uVar3 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar5 = (uVar1 >> 0x1b | uVar1 * 0x20) + (uVar9 ^ uVar5 ^ uVar2) + local_c8 + uVar7 + 0x6ed9eba1;
  uVar6 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar8 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar9 ^ uVar3 ^ uVar1) + local_c4 + uVar2 + 0x6ed9eba1;
  uVar1 = (uVar8 >> 0x1b | uVar8 * 0x20) +
          ((uVar6 | uVar5) & uVar3 | uVar6 & uVar5) + local_c0 + uVar9 + -0x70e44324;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar5 = (uVar1 >> 0x1b | uVar1 * 0x20) +
          ((uVar7 | uVar8) & uVar6 | uVar7 & uVar8) + local_bc + uVar3 + -0x70e44324;
  uVar9 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar8 = (uVar5 >> 0x1b | uVar5 * 0x20) +
          ((uVar1 | uVar9) & uVar7 | uVar1 & uVar9) + local_b8 + uVar6 + -0x70e44324;
  uVar1 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar6 = (uVar8 >> 0x1b | uVar8 * 0x20) +
          ((uVar1 | uVar5) & uVar9 | uVar1 & uVar5) + local_b4 + uVar7 + -0x70e44324;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar2 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar5 = (uVar6 >> 0x1b | uVar6 * 0x20) +
          ((uVar7 | uVar8) & uVar1 | uVar7 & uVar8) + local_b0 + uVar9 + -0x70e44324;
  uVar9 = (uVar5 >> 0x1b | uVar5 * 0x20) +
          ((uVar2 | uVar6) & uVar7 | uVar2 & uVar6) + local_ac + uVar1 + -0x70e44324;
  uVar1 = uVar6 >> 2 | uVar6 * 0x40000000;
  uVar8 = (uVar9 >> 0x1b | uVar9 * 0x20) +
          ((uVar1 | uVar5) & uVar2 | uVar1 & uVar5) + local_a8 + uVar7 + -0x70e44324;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar3 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar5 = (uVar8 >> 0x1b | uVar8 * 0x20) +
          ((uVar9 | uVar7) & uVar1 | uVar9 & uVar7) + local_a4 + uVar2 + -0x70e44324;
  uVar6 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar8 = (uVar5 >> 0x1b | uVar5 * 0x20) +
          ((uVar3 | uVar8) & uVar7 | uVar3 & uVar8) + local_a0 + uVar1 + -0x70e44324;
  uVar1 = (uVar8 >> 0x1b | uVar8 * 0x20) +
          ((uVar6 | uVar5) & uVar3 | uVar6 & uVar5) + local_9c + uVar7 + -0x70e44324;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar5 = (uVar1 >> 0x1b | uVar1 * 0x20) +
          ((uVar7 | uVar8) & uVar6 | uVar7 & uVar8) + local_98 + uVar3 + -0x70e44324;
  uVar9 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar8 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar6 = (uVar5 >> 0x1b | uVar5 * 0x20) +
          ((uVar9 | uVar1) & uVar7 | uVar9 & uVar1) + local_94 + uVar6 + -0x70e44324;
  uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar7 = (uVar6 >> 0x1b | uVar6 * 0x20) +
          ((uVar5 | uVar8) & uVar9 | uVar5 & uVar8) + local_90 + uVar7 + -0x70e44324;
  uVar5 = (uVar7 >> 0x1b | uVar7 * 0x20) +
          ((uVar1 | uVar6) & uVar8 | uVar1 & uVar6) + local_8c + uVar9 + -0x70e44324;
  uVar9 = uVar6 >> 2 | uVar6 * 0x40000000;
  uVar8 = (uVar5 >> 0x1b | uVar5 * 0x20) +
          ((uVar9 | uVar7) & uVar1 | uVar9 & uVar7) + local_88 + uVar8 + -0x70e44324;
  uVar6 = uVar7 >> 2 | uVar7 * 0x40000000;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar1 = (uVar8 >> 0x1b | uVar8 * 0x20) +
          ((uVar6 | uVar5) & uVar9 | uVar6 & uVar5) + local_84 + uVar1 + -0x70e44324;
  uVar5 = (uVar1 >> 0x1b | uVar1 * 0x20) +
          ((uVar7 | uVar8) & uVar6 | uVar7 & uVar8) + local_80 + uVar9 + -0x70e44324;
  uVar9 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar6 = (uVar5 >> 0x1b | uVar5 * 0x20) +
          ((uVar1 | uVar9) & uVar7 | uVar1 & uVar9) + local_7c + uVar6 + -0x70e44324;
  uVar1 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar8 = (uVar6 >> 0x1b | uVar6 * 0x20) +
          ((uVar1 | uVar5) & uVar9 | uVar1 & uVar5) + local_78 + uVar7 + -0x70e44324;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar2 = uVar6 >> 2 | uVar6 * 0x40000000;
  uVar5 = (uVar8 >> 0x1b | uVar8 * 0x20) +
          ((uVar7 | uVar6) & uVar1 | uVar7 & uVar6) + local_74 + uVar9 + -0x70e44324;
  uVar6 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar1 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar7 ^ uVar2 ^ uVar8) + local_70 + uVar1 + -0x359d3e2a;
  uVar9 = (uVar1 >> 0x1b | uVar1 * 0x20) + (uVar2 ^ uVar6 ^ uVar5) + local_6c + uVar7 + -0x359d3e2a;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar3 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar8 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar5 = (uVar9 >> 0x1b | uVar9 * 0x20) + (uVar1 ^ uVar6 ^ uVar7) + local_68 + uVar2 + -0x359d3e2a;
  uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar6 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar3 ^ uVar9 ^ uVar7) + local_64 + uVar6 + -0x359d3e2a;
  uVar4 = uVar6 >> 2 | uVar6 * 0x40000000;
  uVar7 = (uVar6 >> 0x1b | uVar6 * 0x20) + (uVar3 ^ uVar8 ^ uVar5) + local_60 + uVar7 + -0x359d3e2a;
  uVar5 = (uVar7 >> 0x1b | uVar7 * 0x20) + (uVar8 ^ uVar1 ^ uVar6) + local_5c + uVar3 + -0x359d3e2a;
  uVar6 = uVar7 >> 2 | uVar7 * 0x40000000;
  uVar2 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar1 ^ uVar4 ^ uVar7) + local_58 + uVar8 + -0x359d3e2a;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar9 = (uVar2 >> 0x1b | uVar2 * 0x20) + (uVar5 ^ uVar4 ^ uVar6) + local_54 + uVar1 + -0x359d3e2a;
  uVar3 = uVar2 >> 2 | uVar2 * 0x40000000;
  uVar8 = uVar9 >> 2 | uVar9 * 0x40000000;
  uVar5 = (uVar9 >> 0x1b | uVar9 * 0x20) + (uVar7 ^ uVar2 ^ uVar6) + local_50 + uVar4 + -0x359d3e2a;
  uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar6 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar7 ^ uVar3 ^ uVar9) + local_4c + uVar6 + -0x359d3e2a;
  uVar7 = (uVar6 >> 0x1b | uVar6 * 0x20) + (uVar3 ^ uVar8 ^ uVar5) + local_48 + uVar7 + -0x359d3e2a;
  uVar9 = uVar6 >> 2 | uVar6 * 0x40000000;
  uVar5 = (uVar7 >> 0x1b | uVar7 * 0x20) + (uVar8 ^ uVar1 ^ uVar6) + local_44 + uVar3 + -0x359d3e2a;
  uVar6 = uVar7 >> 2 | uVar7 * 0x40000000;
  uVar8 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar7 ^ uVar1 ^ uVar9) + local_40 + uVar8 + -0x359d3e2a;
  uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar1 = (uVar8 >> 0x1b | uVar8 * 0x20) + (uVar6 ^ uVar5 ^ uVar9) + local_3c + uVar1 + -0x359d3e2a;
  uVar5 = (uVar1 >> 0x1b | uVar1 * 0x20) + (uVar6 ^ uVar7 ^ uVar8) + local_38 + uVar9 + -0x359d3e2a;
  uVar2 = uVar8 >> 2 | uVar8 * 0x40000000;
  uVar8 = uVar1 >> 2 | uVar1 * 0x40000000;
  uVar6 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar7 ^ uVar2 ^ uVar1) + local_34 + uVar6 + -0x359d3e2a;
  uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
  uVar7 = (uVar6 >> 0x1b | uVar6 * 0x20) + (uVar2 ^ uVar8 ^ uVar5) + local_30 + uVar7 + -0x359d3e2a;
  uVar9 = uVar6 >> 2 | uVar6 * 0x40000000;
  uVar5 = (uVar7 >> 0x1b | uVar7 * 0x20) + (uVar6 ^ uVar8 ^ uVar1) + local_2c + uVar2 + -0x359d3e2a;
  uVar6 = uVar7 >> 2 | uVar7 * 0x40000000;
  uVar7 = (uVar5 >> 0x1b | uVar5 * 0x20) + (uVar9 ^ uVar7 ^ uVar1) + local_28 + uVar8 + -0x359d3e2a;
  *param_1 = *param_1 +
             (uVar7 >> 0x1b | uVar7 * 0x20) +
             (uVar9 ^ uVar6 ^ uVar5) + local_24 + uVar1 + -0x359d3e2a;
  param_1[1] = param_1[1] + uVar7;
  param_1[2] = (uVar5 >> 2 | uVar5 * 0x40000000) + param_1[2];
  param_1[3] = uVar6 + param_1[3];
  param_1[4] = param_1[4] + uVar9;
  return;
}



/* 10019b20 A_SHAUpdate */

/* Boundary evidence: original MIPS .pdata 10019b20..10019c77. Semantic name remains unreviewed. */

void A_SHAUpdate(void *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x19b20  3  A_SHAUpdate */
  uVar2 = *(uint *)((int)param_1 + 0x58) & 0x3f;
  uVar1 = *(uint *)((int)param_1 + 0x58) + param_3;
  *(uint *)((int)param_1 + 0x58) = uVar1;
  if (uVar1 < param_3) {
    *(int *)((int)param_1 + 0x54) = *(int *)((int)param_1 + 0x54) + 1;
  }
  if ((uVar2 != 0) && (0x3f < uVar2 + param_3)) {
    memcpy((void *)(uVar2 + (int)param_1),param_2,0x40 - uVar2);
    param_2 = (void *)((int)param_2 + (0x40 - uVar2));
    param_3 = (uVar2 + param_3) - 0x40;
    FUN_10018920((uint *)((int)param_1 + 0x40),(int)param_1);
    uVar2 = 0;
  }
  if (((uint)param_2 & 3) == 0) {
    if (0x3f < param_3) {
      uVar1 = param_3 >> 6;
      do {
        FUN_10018920((uint *)((int)param_1 + 0x40),(int)param_2);
        param_2 = (void *)((int)param_2 + 0x40);
        uVar1 = uVar1 - 1;
        param_3 = param_3 - 0x40;
      } while (uVar1 != 0);
    }
  }
  else if (0x3f < param_3) {
    uVar1 = param_3 >> 6;
    do {
      memcpy(param_1,param_2,0x40);
      FUN_10018920((uint *)((int)param_1 + 0x40),(int)param_1);
      param_2 = (void *)((int)param_2 + 0x40);
      uVar1 = uVar1 - 1;
      param_3 = param_3 - 0x40;
    } while (uVar1 != 0);
  }
  if (param_3 != 0) {
    memcpy((void *)(uVar2 + (int)param_1),param_2,param_3);
  }
  return;
}



/* 10019c78 A_SHAFinal */

/* Boundary evidence: original MIPS .pdata 10019c78..10019d83. Semantic name remains unreviewed. */

void A_SHAFinal(void *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_68;
  int local_64;
  undefined1 local_60 [72];
  
                    /* 0x19c78  1  A_SHAFinal */
  uVar1 = *(uint *)((int)param_1 + 0x58);
  uVar2 = -(uVar1 & 0x3f) + 0x40;
  if (uVar2 < 9) {
    uVar2 = -(uVar1 & 0x3f) + 0x80;
  }
  memset(local_60,0,uVar2 - 8);
  local_68 = *(int *)((int)param_1 + 0x54) << 3 | uVar1 >> 0x1d;
  local_60[0] = 0x80;
  local_64 = uVar1 << 3;
  FUN_10026938((int)&local_68 + uVar2,(int)&local_68,2);
  A_SHAUpdate(param_1,local_60,uVar2);
  FUN_10026938(param_2,(int)param_1 + 0x40,5);
  *(undefined4 *)((int)param_1 + 0x54) = 0;
  *(undefined4 *)((int)param_1 + 0x58) = 0;
  *(undefined4 *)((int)param_1 + 0x40) = 0x67452301;
  *(undefined4 *)((int)param_1 + 0x44) = 0xefcdab89;
  *(undefined4 *)((int)param_1 + 0x48) = 0x98badcfe;
  *(undefined4 *)((int)param_1 + 0x4c) = 0x10325476;
  *(undefined4 *)((int)param_1 + 0x50) = 0xc3d2e1f0;
  return;
}



/* 10019d84 FUN_10019d84 */

/* Boundary evidence: original MIPS .pdata 10019d84..1001a16f. Semantic name remains unreviewed. */

undefined4 FUN_10019d84(uint *param_1,int *param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  uint *_Dst;
  uint *_Buf1;
  uint uVar3;
  int iVar4;
  undefined3 extraout_var;
  uint *_Buf2;
  uint *puVar5;
  uint uVar6;
  uint *_Dst_00;
  uint *_Dst_01;
  size_t _Size;
  uint *puVar7;
  uint uVar8;
  undefined4 uVar9;
  uint local_44;
  uint local_40;
  
  uVar8 = (param_3 >> 5) + 1;
  uVar2 = param_3 & 0x1f;
  if (uVar2 == 0) {
    local_44 = 0xffffffff;
    local_40 = 0xc0000000;
  }
  else {
    local_44 = (1 << uVar2) - 1;
    local_40 = 3 << (uVar2 - 2 & 0x1f);
    uVar8 = (param_3 >> 5) + 2;
  }
  _Dst = (uint *)FUN_100269dc(0x40,uVar8 * 0x30 + param_3);
  if (_Dst == (uint *)0x0) {
    return 0;
  }
  memset(_Dst,0,uVar8 * 0x30);
  _Size = uVar8 * 4;
  _Buf1 = _Dst + uVar8 * 2;
  _Buf2 = _Buf1 + uVar8 * 2;
  puVar5 = _Buf2 + uVar8 * 2;
  _Dst_01 = puVar5 + uVar8 * 2 + uVar8 * 2;
  _Dst_00 = _Dst_01 + uVar8 * 2;
  puVar7 = param_1;
  uVar2 = uVar8;
  do {
    do {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        FUN_10016afc(0,puVar7,4);
        puVar7 = puVar7 + 1;
      }
      *param_1 = *param_1 & 0xfffffffe;
      param_1[uVar8 - 1] = 0;
      param_1[uVar8 - 2] = local_44 & param_1[uVar8 - 2] | local_40;
      memset(_Dst_00,0,param_3);
      uVar2 = 3;
      do {
        uVar6 = 0;
        do {
          uVar3 = *(uint *)((int)&DAT_1002d80c + uVar6);
          if (uVar3 < uVar2) {
            if (uVar3 == 0) {
              trap(0x1c00);
            }
            if (uVar2 % uVar3 == 0) goto LAB_10019fd4;
          }
          uVar6 = uVar6 + 4;
        } while (uVar6 < 0x14);
        iVar4 = 0;
        if (uVar8 != 0) {
          puVar7 = param_1 + uVar8;
          uVar6 = uVar8;
          do {
            puVar7 = puVar7 + -1;
            uVar6 = uVar6 - 1;
            iVar4 = __ull_rem(*puVar7,iVar4,uVar2,0);
          } while (uVar6 != 0);
        }
        uVar6 = uVar2 - iVar4;
        if ((uVar6 & 1) == 0) {
          uVar6 = uVar2 + uVar6;
        }
        for (uVar6 = uVar6 >> 1; uVar6 < param_3; uVar6 = uVar2 + uVar6) {
          *(undefined1 *)(uVar6 + (int)_Dst_00) = 1;
        }
LAB_10019fd4:
        uVar2 = uVar2 + 2;
      } while (uVar2 < 9000);
      FUN_10025798((int *)param_1,uVar8);
      uVar6 = 0;
      puVar7 = param_1;
      uVar2 = uVar8;
    } while (param_3 == 0);
    do {
      if (*(char *)(uVar6 + (int)_Dst_00) == '\0') {
        uVar2 = 0;
        do {
          FUN_100257d8(_Dst,*(uint *)((int)&DAT_1002d80c + uVar2),uVar8);
          bVar1 = FUN_10026e08(_Dst + uVar8,_Dst,(int)param_1,(int *)param_1,uVar8);
          if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_1001a128;
          iVar4 = memcmp(_Dst + uVar8,_Dst,_Size);
          if (iVar4 != 0) goto LAB_1001a0f0;
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x14);
        uVar2 = uVar8 << 1;
        FUN_100257d8(_Buf1,1,uVar2);
        memcpy(_Dst_01,param_1,_Size);
        FUN_1001ea90((int)_Dst_01,(int)_Dst_01,_Buf1,uVar2);
        iVar4 = FUN_10026678(_Buf2,puVar5,puVar5 + uVar8 * 2,param_2,_Dst_01,uVar2);
        if (iVar4 == 0) {
LAB_1001a128:
          uVar9 = 0;
LAB_1001a134:
          FUN_100269f8(_Dst);
          return uVar9;
        }
        iVar4 = memcmp(_Buf1,_Buf2,_Size);
        if (iVar4 == 0) {
          uVar9 = 1;
          goto LAB_1001a134;
        }
      }
LAB_1001a0f0:
      iVar4 = FUN_10025798((int *)param_1,uVar8);
      if (iVar4 == 0) {
        FUN_10025798((int *)param_1,uVar8);
      }
      uVar6 = uVar6 + 1;
      uVar2 = uVar8;
    } while (uVar6 < param_3);
  } while( true );
}



/* 1001a170 FUN_1001a170 */

bool FUN_1001a170(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0x32415352) {
    *param_2 = param_1 + 5;
    iVar2 = param_1[1] + (int)(param_1 + 5);
    param_2[2] = iVar2;
    iVar2 = ((uint)param_1[1] >> 1) + iVar2;
    param_2[3] = iVar2;
    iVar2 = ((uint)param_1[1] >> 1) + iVar2;
    param_2[4] = iVar2;
    iVar2 = ((uint)param_1[1] >> 1) + iVar2;
    param_2[5] = iVar2;
    iVar2 = ((uint)param_1[1] >> 1) + iVar2;
    param_2[6] = iVar2;
    iVar2 = ((uint)param_1[1] >> 1) + iVar2;
    param_2[1] = iVar2;
    iVar2 = param_1[1] + iVar2;
    param_2[7] = iVar2;
    iVar2 = param_1[1] + iVar2;
    param_2[8] = iVar2;
    param_2[9] = ((uint)param_1[1] >> 1) + iVar2;
  }
  return iVar1 == 0x32415352;
}



/* 1001a224 BSafeGetPubKeyModulus */

int * BSafeGetPubKeyModulus(int *param_1)

{
  int *piVar1;
  
                    /* 0x1a224  7  BSafeGetPubKeyModulus */
  if (*param_1 == 0x31415352) {
    piVar1 = param_1 + 5;
  }
  else {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



/* 1001a24c FUN_1001a24c */

undefined4 FUN_1001a24c(uint *param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *param_1;
  if (((uVar1 & 1) == 0) && (0x1f < uVar1)) {
    *param_1 = uVar1 >> 1;
    iVar3 = (uVar1 >> 6) + 1;
    if ((uVar1 >> 1 & 0x1f) != 0) {
      iVar3 = (uVar1 >> 6) + 2;
    }
    *param_2 = iVar3;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 1001a29c BSafeComputeKeySizes */

/* Boundary evidence: original MIPS .pdata 1001a29c..1001a30b. Semantic name remains unreviewed. */

bool BSafeComputeKeySizes(int *param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int local_18 [2];
  
                    /* 0x1a29c  4  BSafeComputeKeySizes */
  iVar1 = FUN_1001a24c(param_3,local_18);
  if (iVar1 != 0) {
    *param_2 = local_18[0] * 0x28 + 0x14;
    *param_1 = local_18[0] * 8 + 0x14;
  }
  return iVar1 != 0;
}



/* 1001a30c FUN_1001a30c */

/* Boundary evidence: original MIPS .pdata 1001a30c..1001a65b. Semantic name remains unreviewed. */

undefined4 FUN_1001a30c(undefined4 *param_1,int *param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint *_Dst;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  size_t _Size;
  uint *_Dst_00;
  undefined4 uVar6;
  uint local_res8 [2];
  uint *local_58 [2];
  void *local_50;
  undefined4 *local_4c;
  uint *local_48;
  uint *local_44;
  void *local_40;
  void *local_3c;
  void *local_38;
  
  local_res8[0] = param_3;
  iVar2 = FUN_1001a24c(local_res8,(int *)local_58);
  puVar1 = local_58[0];
  if (iVar2 == 0) {
    return 0;
  }
  _Dst = (uint *)FUN_100269dc(0x40,(int)local_58[0] << 5);
  if (_Dst == (uint *)0x0) {
    return 0;
  }
  _Dst_00 = _Dst + (int)local_58[0] * 6;
  memset(param_2 + 5,0,(int)local_58[0] * 0x28);
  _Size = (int)local_58[0] * 8;
  memset(param_1 + 5,0,_Size);
  memset(_Dst,0,(int)local_58[0] * 0x18);
  memset(_Dst_00,0,_Size);
  param_2[1] = _Size;
  *param_2 = 0x32415352;
  FUN_1001a170(param_2,&local_50);
  uVar4 = local_res8[0];
  puVar5 = _Dst + (int)local_58[0] * 2;
  local_58[0] = puVar5 + (int)local_58[0] * 3;
  *_Dst_00 = param_4;
  iVar2 = FUN_10019d84(local_48,(int *)_Dst_00,local_res8[0]);
  if (iVar2 != 0) {
    do {
      iVar2 = FUN_10019d84(local_44,(int *)_Dst_00,uVar4);
      if (iVar2 == 0) goto LAB_1001a440;
      iVar2 = FUN_10025aec((int)local_48,(int)local_44,(int)puVar1);
    } while (iVar2 == 0);
    iVar2 = FUN_10025aec((int)local_48,(int)local_44,(int)puVar1);
    if ((iVar2 != 1) && (puVar1 != (uint *)0x0)) {
      puVar3 = (uint *)0x0;
      do {
        uVar4 = local_48[(int)puVar3];
        local_48[(int)puVar3] = local_44[(int)puVar3];
        local_44[(int)puVar3] = uVar4;
        puVar3 = (uint *)((int)puVar3 + 1U & 0xffff);
      } while (puVar3 < puVar1);
    }
    FUN_10025b50(param_1 + 5,(int)local_48,(int)local_44,(int)puVar1);
    FUN_100257d8(_Dst,1,(int)puVar1);
    FUN_1001ea90((int)local_58[0],(int)local_44,_Dst,(int)puVar1);
    FUN_1001ea90((int)(puVar5 + (int)puVar1 * 2),(int)local_48,_Dst,(int)puVar1);
    FUN_10025b50(_Dst,(int)(puVar5 + (int)puVar1 * 2),(int)local_58[0],(int)puVar1);
    uVar4 = (int)puVar1 << 1;
    iVar2 = FUN_10026678(puVar5,local_4c,puVar5,(int *)_Dst_00,_Dst,uVar4);
    if (iVar2 != 0) {
      FUN_100260e8(_Dst,local_40,local_4c,puVar5 + (int)puVar1 * 2,uVar4,(uint)puVar1);
      FUN_100260e8(_Dst,local_3c,local_4c,local_58[0],uVar4,(uint)puVar1);
      iVar2 = FUN_10026678(_Dst,puVar5,local_38,(int *)local_48,local_44,(uint)puVar1);
      if (iVar2 != 0) {
        memcpy(local_50,param_1 + 5,_Size);
        iVar2 = ((local_res8[0] & 0x7fffffff) >> 2) - 1;
        param_1[1] = _Size;
        param_1[2] = local_res8[0] << 1;
        param_1[3] = iVar2;
        *param_1 = 0x31415352;
        uVar6 = 1;
        param_1[4] = *_Dst_00;
        param_2[2] = local_res8[0] << 1;
        param_2[3] = iVar2;
        param_2[4] = *_Dst_00;
        goto LAB_1001a620;
      }
    }
  }
LAB_1001a440:
  uVar6 = 0;
LAB_1001a620:
  FUN_100269f8(_Dst);
  return uVar6;
}



/* 1001a65c FUN_1001a65c */

/* Boundary evidence: original MIPS .pdata 1001a65c..1001a67b. Semantic name remains unreviewed. */

void FUN_1001a65c(undefined4 *param_1,int *param_2,uint param_3)

{
  FUN_1001a30c(param_1,param_2,param_3,0x10001);
  return;
}



/* 1001a67c BSafeDecPrivate */

/* Boundary evidence: original MIPS .pdata 1001a67c..1001a72b. Semantic name remains unreviewed. */

undefined4 BSafeDecPrivate(int *param_1,void *param_2,uint *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 auStack_38 [2];
  int *local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  
                    /* 0x1a67c  5  BSafeDecPrivate */
  if ((*param_1 == 0x32415352) &&
     (bVar1 = FUN_1001a170(param_1,auStack_38), CONCAT31(extraout_var,bVar1) != 0)) {
    uVar3 = (uint)param_1[2] >> 6;
    uVar4 = uVar3 + 1;
    if (((uint)param_1[2] >> 1 & 0x1f) != 0) {
      uVar4 = uVar3 + 2;
    }
    uVar2 = FUN_10027214(param_3,param_2,local_30,local_2c,local_28,local_24,local_20,uVar4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 1001a72c BSafeEncPublic */

/* Boundary evidence: original MIPS .pdata 1001a72c..1001a833. Semantic name remains unreviewed. */

bool BSafeEncPublic(int *param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  int iVar2;
  int *_Dst;
  uint uVar3;
  int iVar4;
  
                    /* 0x1a72c  6  BSafeEncPublic */
  if (*param_1 == 0x31415352) {
    uVar3 = (uint)param_1[2] >> 6;
    iVar4 = uVar3 + 1;
    if (((uint)param_1[2] >> 1 & 0x1f) != 0) {
      iVar4 = uVar3 + 2;
    }
    iVar2 = FUN_10025aec((int)param_2,(int)(param_1 + 5),iVar4 << 1);
    if (iVar2 < 0) {
      _Dst = (int *)FUN_100269dc(0x40,iVar4 << 3);
      if (_Dst != (int *)0x0) {
        memset(_Dst,0,iVar4 << 3);
        *_Dst = param_1[4];
        bVar1 = FUN_10026e08(param_3,param_2,(int)_Dst,param_1 + 5,iVar4 << 1);
        FUN_100269f8(_Dst);
        return bVar1;
      }
    }
  }
  return false;
}



/* 1001a834 CBC */

/* Boundary evidence: original MIPS .pdata 1001a834..1001ab8b. Semantic name remains unreviewed. */

void CBC(undefined *param_1,size_t param_2,uint *param_3,uint *param_4,undefined4 param_5,
        int param_6,uint *param_7)

{
  uint *puVar1;
  uint *puVar2;
  size_t sVar3;
  uint *_Src;
  uint *_Src_00;
  uint local_58 [4];
  uint local_48 [4];
  uint local_38 [4];
  
                    /* 0x1a834  9  CBC */
  _Src_00 = param_3;
  if (((uint)param_3 & 3) != 0) {
    _Src_00 = local_58;
    memcpy(local_58,param_3,param_2);
  }
  if ((((uint)param_4 & 3) != 0) || (puVar2 = param_4, param_4 == _Src_00)) {
    puVar2 = local_48;
    memcpy(local_48,param_4,param_2);
  }
  _Src = param_7;
  if (((uint)param_7 & 3) != 0) {
    _Src = local_38;
    memcpy(local_38,param_7,param_2);
  }
  if (param_2 == 8) {
    if (param_6 == 1) {
      *puVar2 = *_Src ^ *puVar2;
      puVar2[1] = _Src[1] ^ puVar2[1];
      (*(code *)param_1)(_Src_00,puVar2,param_5,1);
      _Src = _Src_00;
    }
    else if (param_6 == 0) {
      (*(code *)param_1)(_Src_00,puVar2,param_5,0);
      *_Src_00 = *_Src ^ *_Src_00;
      _Src_00[1] = _Src[1] ^ _Src_00[1];
      _Src = puVar2;
    }
    memcpy(param_7,_Src,8);
    if (_Src_00 == param_3) {
      return;
    }
    param_2 = 8;
  }
  else if (param_2 == 0x10) {
    if (param_6 == 1) {
      *puVar2 = *_Src ^ *puVar2;
      puVar2[1] = _Src[1] ^ puVar2[1];
      puVar2[2] = _Src[2] ^ puVar2[2];
      puVar2[3] = _Src[3] ^ puVar2[3];
      (*(code *)param_1)(_Src_00,puVar2,param_5,1);
      _Src = _Src_00;
    }
    else if (param_6 == 0) {
      (*(code *)param_1)(_Src_00,puVar2,param_5,0);
      *_Src_00 = *_Src ^ *_Src_00;
      _Src_00[1] = _Src[1] ^ _Src_00[1];
      _Src_00[2] = _Src[2] ^ _Src_00[2];
      _Src_00[3] = _Src[3] ^ _Src_00[3];
      _Src = puVar2;
    }
    memcpy(param_7,_Src,0x10);
    if (_Src_00 == param_3) {
      return;
    }
    param_2 = 0x10;
  }
  else {
    if (param_6 == 1) {
      if (param_2 != 0) {
        puVar1 = puVar2;
        sVar3 = param_2;
        do {
          *(byte *)puVar1 = *(byte *)(((int)_Src - (int)puVar2) + (int)puVar1) ^ (byte)*puVar1;
          sVar3 = sVar3 - 1;
          puVar1 = (uint *)((int)puVar1 + 1);
        } while (sVar3 != 0);
      }
      (*(code *)param_1)(_Src_00,puVar2,param_5,1);
      puVar1 = _Src_00;
    }
    else {
      puVar1 = _Src;
      if ((param_6 == 0) &&
         ((*(code *)param_1)(_Src_00,puVar2,param_5,0), puVar1 = puVar2, param_2 != 0)) {
        puVar2 = _Src_00;
        sVar3 = param_2;
        do {
          *(byte *)puVar2 = *(byte *)(((int)_Src - (int)_Src_00) + (int)puVar2) ^ (byte)*puVar2;
          sVar3 = sVar3 - 1;
          puVar2 = (uint *)((int)puVar2 + 1);
        } while (sVar3 != 0);
      }
    }
    memcpy(param_7,puVar1,param_2);
    if (_Src_00 == param_3) {
      return;
    }
  }
  memcpy(param_3,_Src_00,param_2);
  return;
}



/* 1001ab8c FUN_1001ab8c */

/* Boundary evidence: original MIPS .pdata 1001ab8c..1001acef. Semantic name remains unreviewed. */

void FUN_1001ab8c(undefined *param_1,int param_2,byte *param_3,byte *param_4,undefined4 param_5,
                 int param_6,void *param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte local_48 [32];
  
  if (param_6 == 1) {
    if (param_2 != 0) {
      iVar2 = (int)param_4 - (int)param_3;
      iVar3 = param_2;
      do {
        (*(code *)param_1)(local_48,param_7,param_5,1);
        *param_3 = param_3[iVar2] ^ local_48[0];
        memmove(param_7,(void *)((int)param_7 + 1),param_2 - 1);
        bVar1 = *param_3;
        param_3 = param_3 + 1;
        iVar3 = iVar3 + -1;
        *(byte *)((int)param_7 + param_2 + -1) = bVar1;
      } while (iVar3 != 0);
    }
  }
  else if ((param_6 == 0) && (param_2 != 0)) {
    iVar2 = (int)param_3 - (int)param_4;
    iVar3 = param_2;
    do {
      (*(code *)param_1)(local_48,param_7,param_5,1);
      param_4[iVar2] = *param_4 ^ local_48[0];
      memmove(param_7,(void *)((int)param_7 + 1),param_2 - 1);
      bVar1 = *param_4;
      param_4 = param_4 + 1;
      iVar3 = iVar3 + -1;
      *(byte *)((int)param_7 + param_2 + -1) = bVar1;
    } while (iVar3 != 0);
  }
  return;
}



/* 1001acf0 FUN_1001acf0 */

/* Boundary evidence: original MIPS .pdata 1001acf0..1001adfb. Semantic name remains unreviewed. */

void FUN_1001acf0(byte *param_1,uint *param_2)

{
  *(byte *)param_2 = *param_1 >> 1;
  *(byte *)((int)param_2 + 1) = (*param_1 & 1) << 6 | param_1[1] >> 2;
  *(byte *)((int)param_2 + 2) = (param_1[1] & 3) << 5 | param_1[2] >> 3;
  *(byte *)((int)param_2 + 3) = (param_1[2] & 7) << 4 | param_1[3] >> 4;
  *(byte *)(param_2 + 1) = (param_1[3] & 0xf) << 3 | param_1[4] >> 5;
  *(byte *)((int)param_2 + 5) = (param_1[4] & 0x1f) << 2 | param_1[5] >> 6;
  *(byte *)((int)param_2 + 6) = (param_1[5] & 0x3f) << 1 | param_1[6] >> 7;
  *(byte *)((int)param_2 + 7) = param_1[6] & 0x7f;
  param_2[1] = (param_2[1] & 0xff7f7f7f) << 1;
  *param_2 = (*param_2 & 0xff7f7f7f) << 1;
  FUN_1001e884((int)param_2,8);
  return;
}



/* 1001adfc DES_ECB_LM */

/* Boundary evidence: original MIPS .pdata 1001adfc..1001aeab. Semantic name remains unreviewed. */

undefined4 DES_ECB_LM(int param_1,byte *param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint auStack_a0 [2];
  uint auStack_98 [32];
  
                    /* 0x1adfc  35  DES_ECB_LM */
  if (param_4 != (uint *)0x0) {
    *(undefined1 *)param_4 = 0;
    *(undefined1 *)((int)param_4 + 7) = 0;
    if (param_3 != (uint *)0x0) {
      FUN_1001acf0(param_2,auStack_a0);
      deskey(auStack_98,auStack_a0);
      if (param_1 == 0) {
        iVar1 = 0;
      }
      else {
        if (param_1 != 1) {
          return 1;
        }
        iVar1 = 1;
      }
      des(param_4,param_3,(int)auStack_98,iVar1);
      return 0;
    }
  }
  return 1;
}



/* 1001aeac HMACMD5Init */

/* Boundary evidence: original MIPS .pdata 1001aeac..1001afe7. Semantic name remains unreviewed. */

void HMACMD5Init(uint *param_1,void *param_2,size_t param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  size_t _Size;
  uint local_a0 [32];
  
                    /* 0x1aeac  37  HMACMD5Init */
  MD5Init(param_1);
  MD5Init(param_1 + 0x1a);
  memset(local_a0,0,0x40);
  memset(local_a0 + 0x10,0,0x40);
  _Size = param_3;
  if (0x3f < param_3) {
    _Size = 0x40;
  }
  memcpy(local_a0,param_2,_Size);
  if (0x3f < param_3) {
    param_3 = 0x40;
  }
  memcpy(local_a0 + 0x10,param_2,param_3);
  uVar1 = 0;
  do {
    *(uint *)((int)local_a0 + uVar1) = *(uint *)((int)local_a0 + uVar1) ^ 0x36363636;
    *(uint *)((int)local_a0 + uVar1 + 4) = *(uint *)((int)local_a0 + uVar1 + 4) ^ 0x36363636;
    puVar3 = (uint *)((int)local_a0 + uVar1 + 0x40);
    uVar2 = uVar1 + 8;
    *puVar3 = *puVar3 ^ 0x5c5c5c5c;
    *(uint *)((int)local_a0 + uVar1 + 0x44) = *(uint *)((int)local_a0 + uVar1 + 0x44) ^ 0x5c5c5c5c;
    uVar1 = uVar2;
  } while (uVar2 < 0x40);
  MD5Update(param_1,(int *)local_a0,0x40);
  MD5Update(param_1 + 0x1a,(int *)(local_a0 + 0x10),0x40);
  return;
}



/* 1001afe8 HMACMD5Update */

/* Boundary evidence: original MIPS .pdata 1001afe8..1001b003. Semantic name remains unreviewed. */

void HMACMD5Update(uint *param_1,int *param_2,uint param_3)

{
                    /* 0x1afe8  38  HMACMD5Update */
  MD5Update(param_1,param_2,param_3);
  return;
}



/* 1001b004 HMACMD5Final */

/* Boundary evidence: original MIPS .pdata 1001b004..1001b06b. Semantic name remains unreviewed. */

void HMACMD5Final(uint *param_1,void *param_2)

{
                    /* 0x1b004  36  HMACMD5Final */
  MD5Final(param_1);
  MD5Update(param_1 + 0x1a,(int *)(param_1 + 0x16),0x10);
  MD5Final(param_1 + 0x1a);
  memcpy(param_2,param_1 + 0x30,0x10);
  return;
}



/* 1001b06c FUN_1001b06c */

/* Boundary evidence: original MIPS .pdata 1001b06c..1001b1ab. Semantic name remains unreviewed. */

void FUN_1001b06c(void *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  byte local_48 [48];
  
  memcpy(local_48,param_1,0x10);
  memcpy(local_48 + 0x10,param_3,0x10);
  iVar4 = 0x10;
  pbVar2 = param_3;
  do {
    pbVar6 = pbVar2 + ((int)param_1 - (int)param_3);
    bVar1 = *pbVar2;
    pbVar9 = pbVar2 + (int)(local_48 + (0x20 - (int)param_3));
    pbVar2 = pbVar2 + 1;
    iVar4 = iVar4 + -1;
    *pbVar9 = *pbVar6 ^ bVar1;
  } while (iVar4 != 0);
  uVar5 = 0;
  uVar7 = 0;
  do {
    uVar3 = 0;
    do {
      pbVar2 = local_48 + uVar3;
      bVar1 = (&DAT_1002d820)[uVar5] ^ *pbVar2;
      uVar5 = (uint)bVar1;
      uVar3 = uVar3 + 1;
      *pbVar2 = bVar1;
    } while (uVar3 < 0x30);
    uVar5 = uVar5 + uVar7;
    uVar7 = uVar7 + 1;
    uVar5 = uVar5 & 0xff;
  } while (uVar7 < 0x12);
  memcpy(param_1,local_48,0x10);
  bVar1 = param_2[0xf];
  iVar8 = (int)param_3 - (int)param_2;
  iVar4 = 0x10;
  do {
    bVar1 = (&DAT_1002d820)[param_2[iVar8] ^ bVar1] ^ *param_2;
    *param_2 = bVar1;
    iVar4 = iVar4 + -1;
    param_2 = param_2 + 1;
  } while (iVar4 != 0);
  return;
}



/* 1001b1ac MD2Update */

/* Boundary evidence: original MIPS .pdata 1001b1ac..1001b2a3. Semantic name remains unreviewed. */

undefined4 MD2Update(void *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint _Size;
  
                    /* 0x1b1ac  40  MD2Update */
  iVar1 = *(int *)((int)param_1 + 0x20);
  _Size = -iVar1 + 0x10;
  *(uint *)((int)param_1 + 0x20) = iVar1 + param_3 & 0xf;
  if (param_3 < _Size) {
    _Size = 0;
  }
  else {
    memcpy((void *)((int)param_1 + iVar1 + 0x24),param_2,_Size);
    FUN_1001b06c(param_1,(byte *)((int)param_1 + 0x10),(byte *)((int)param_1 + 0x24));
    for (uVar2 = -iVar1 + 0x1f; uVar2 < param_3; uVar2 = uVar2 + 0x10) {
      FUN_1001b06c(param_1,(byte *)((int)param_1 + 0x10),(byte *)((int)param_2 + (uVar2 - 0xf)));
      _Size = _Size + 0x10;
    }
    iVar1 = 0;
  }
  memcpy((void *)((int)param_1 + iVar1 + 0x24),(void *)(_Size + (int)param_2),param_3 - _Size);
  return 0;
}



/* 1001b2a4 MD2Final */

/* Boundary evidence: original MIPS .pdata 1001b2a4..1001b2ff. Semantic name remains unreviewed. */

undefined4 MD2Final(void *param_1)

{
  uint uVar1;
  
                    /* 0x1b2a4  39  MD2Final */
  uVar1 = 0x10 - *(int *)((int)param_1 + 0x20);
  MD2Update(param_1,*(void **)(&DAT_1002d9c0 + uVar1 * 4),uVar1);
  MD2Update(param_1,(void *)((int)param_1 + 0x10),0x10);
  return 0;
}



/* 1001b300 MD4Init */

void MD4Init(undefined4 *param_1)

{
                    /* 0x1b300  42  MD4Init */
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = 0x67452301;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  return;
}



/* 1001b33c FUN_1001b33c */

/* Boundary evidence: original MIPS .pdata 1001b33c..1001ba9b. Semantic name remains unreviewed. */

void FUN_1001b33c(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
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
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  
  uVar7 = param_1[2];
  uVar8 = param_1[3];
  uVar2 = param_1[1];
  iVar9 = *param_2;
  uVar1 = ((uVar8 ^ uVar7) & uVar2 ^ uVar8) + iVar9 + *param_1;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  iVar10 = param_2[1];
  uVar3 = ((uVar7 ^ uVar2) & uVar1 ^ uVar7) + iVar10 + uVar8;
  uVar4 = uVar3 >> 0x19 | uVar3 * 0x80;
  iVar11 = param_2[2];
  iVar21 = param_2[6];
  uVar3 = ((uVar2 ^ uVar1) & uVar4 ^ uVar2) + iVar11 + uVar7;
  uVar3 = uVar3 >> 0x15 | uVar3 * 0x800;
  iVar19 = param_2[3];
  uVar5 = ((uVar4 ^ uVar1) & uVar3 ^ uVar1) + iVar19 + uVar2;
  uVar5 = uVar5 * 0x80000 | uVar5 >> 0xd;
  uVar1 = ((uVar4 ^ uVar3) & uVar5 ^ uVar4) + param_2[4] + uVar1;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  iVar20 = param_2[5];
  iVar18 = param_2[7];
  uVar4 = ((uVar3 ^ uVar5) & uVar1 ^ uVar3) + iVar20 + uVar4;
  uVar4 = uVar4 >> 0x19 | uVar4 * 0x80;
  uVar3 = ((uVar5 ^ uVar1) & uVar4 ^ uVar5) + iVar21 + uVar3;
  uVar3 = uVar3 >> 0x15 | uVar3 * 0x800;
  uVar5 = ((uVar4 ^ uVar1) & uVar3 ^ uVar1) + iVar18 + uVar5;
  uVar5 = uVar5 * 0x80000 | uVar5 >> 0xd;
  uVar1 = ((uVar4 ^ uVar3) & uVar5 ^ uVar4) + param_2[8] + uVar1;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  iVar17 = param_2[9];
  iVar16 = param_2[10];
  uVar4 = ((uVar3 ^ uVar5) & uVar1 ^ uVar3) + iVar17 + uVar4;
  uVar4 = uVar4 >> 0x19 | uVar4 * 0x80;
  uVar3 = ((uVar5 ^ uVar1) & uVar4 ^ uVar5) + iVar16 + uVar3;
  uVar3 = uVar3 >> 0x15 | uVar3 * 0x800;
  iVar15 = param_2[0xb];
  iVar14 = param_2[0xc];
  uVar5 = ((uVar4 ^ uVar1) & uVar3 ^ uVar1) + iVar15 + uVar5;
  uVar5 = uVar5 * 0x80000 | uVar5 >> 0xd;
  uVar1 = ((uVar4 ^ uVar3) & uVar5 ^ uVar4) + iVar14 + uVar1;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  iVar13 = param_2[0xd];
  iVar12 = param_2[0xe];
  uVar4 = ((uVar3 ^ uVar5) & uVar1 ^ uVar3) + iVar13 + uVar4;
  uVar4 = uVar4 >> 0x19 | uVar4 * 0x80;
  uVar3 = ((uVar5 ^ uVar1) & uVar4 ^ uVar5) + iVar12 + uVar3;
  uVar6 = uVar3 >> 0x15 | uVar3 * 0x800;
  uVar5 = ((uVar4 ^ uVar1) & uVar6 ^ uVar1) + param_2[0xf] + uVar5;
  uVar3 = uVar5 * 0x80000 | uVar5 >> 0xd;
  uVar1 = ((uVar6 | uVar3) & uVar4 | uVar6 & uVar3) + iVar9 + uVar1 + 0x5a827999;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  uVar4 = ((uVar3 | uVar1) & uVar6 | uVar3 & uVar1) + param_2[4] + uVar4 + 0x5a827999;
  uVar4 = uVar4 >> 0x1b | uVar4 * 0x20;
  uVar5 = ((uVar4 | uVar1) & uVar3 | uVar4 & uVar1) + param_2[8] + uVar6 + 0x5a827999;
  uVar5 = uVar5 >> 0x17 | uVar5 * 0x200;
  uVar3 = ((uVar4 | uVar5) & uVar1 | uVar4 & uVar5) + iVar14 + uVar3 + 0x5a827999;
  uVar3 = uVar3 >> 0x13 | uVar3 * 0x2000;
  uVar1 = ((uVar5 | uVar3) & uVar4 | uVar5 & uVar3) + iVar10 + uVar1 + 0x5a827999;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  uVar4 = ((uVar3 | uVar1) & uVar5 | uVar3 & uVar1) + iVar20 + uVar4 + 0x5a827999;
  uVar4 = uVar4 >> 0x1b | uVar4 * 0x20;
  uVar5 = ((uVar4 | uVar1) & uVar3 | uVar4 & uVar1) + iVar17 + uVar5 + 0x5a827999;
  uVar6 = uVar5 >> 0x17 | uVar5 * 0x200;
  uVar3 = ((uVar4 | uVar6) & uVar1 | uVar4 & uVar6) + iVar13 + uVar3 + 0x5a827999;
  uVar3 = uVar3 >> 0x13 | uVar3 * 0x2000;
  uVar1 = ((uVar6 | uVar3) & uVar4 | uVar6 & uVar3) + iVar11 + uVar1 + 0x5a827999;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  uVar4 = ((uVar3 | uVar1) & uVar6 | uVar3 & uVar1) + iVar21 + uVar4 + 0x5a827999;
  uVar5 = uVar4 >> 0x1b | uVar4 * 0x20;
  uVar4 = ((uVar5 | uVar1) & uVar3 | uVar5 & uVar1) + iVar16 + uVar6 + 0x5a827999;
  uVar6 = uVar4 >> 0x17 | uVar4 * 0x200;
  uVar3 = ((uVar5 | uVar6) & uVar1 | uVar5 & uVar6) + iVar12 + uVar3 + 0x5a827999;
  uVar4 = uVar3 >> 0x13 | uVar3 * 0x2000;
  uVar1 = ((uVar6 | uVar4) & uVar5 | uVar6 & uVar4) + iVar19 + uVar1 + 0x5a827999;
  uVar3 = uVar1 >> 0x1d | uVar1 * 8;
  uVar1 = ((uVar4 | uVar3) & uVar6 | uVar4 & uVar3) + iVar18 + uVar5 + 0x5a827999;
  uVar5 = uVar1 >> 0x1b | uVar1 * 0x20;
  uVar1 = ((uVar5 | uVar3) & uVar4 | uVar5 & uVar3) + iVar15 + uVar6 + 0x5a827999;
  uVar6 = uVar1 >> 0x17 | uVar1 * 0x200;
  uVar1 = ((uVar5 | uVar6) & uVar3 | uVar5 & uVar6) + param_2[0xf] + uVar4 + 0x5a827999;
  uVar4 = uVar1 >> 0x13 | uVar1 * 0x2000;
  uVar1 = (uVar5 ^ uVar6 ^ uVar4) + iVar9 + uVar3 + 0x6ed9eba1;
  uVar3 = uVar1 >> 0x1d | uVar1 * 8;
  uVar1 = (uVar6 ^ uVar4 ^ uVar3) + param_2[8] + uVar5 + 0x6ed9eba1;
  uVar5 = uVar1 >> 0x17 | uVar1 * 0x200;
  uVar1 = (uVar5 ^ uVar4 ^ uVar3) + param_2[4] + uVar6 + 0x6ed9eba1;
  uVar1 = uVar1 >> 0x15 | uVar1 * 0x800;
  uVar4 = (uVar5 ^ uVar1 ^ uVar3) + iVar14 + uVar4 + 0x6ed9eba1;
  uVar4 = uVar4 >> 0x11 | uVar4 * 0x8000;
  uVar3 = (uVar5 ^ uVar1 ^ uVar4) + iVar11 + uVar3 + 0x6ed9eba1;
  uVar3 = uVar3 >> 0x1d | uVar3 * 8;
  uVar5 = (uVar1 ^ uVar4 ^ uVar3) + iVar16 + uVar5 + 0x6ed9eba1;
  uVar5 = uVar5 >> 0x17 | uVar5 * 0x200;
  uVar1 = (uVar5 ^ uVar4 ^ uVar3) + iVar21 + uVar1 + 0x6ed9eba1;
  uVar1 = uVar1 >> 0x15 | uVar1 * 0x800;
  uVar4 = (uVar5 ^ uVar1 ^ uVar3) + iVar12 + uVar4 + 0x6ed9eba1;
  uVar4 = uVar4 >> 0x11 | uVar4 * 0x8000;
  uVar3 = (uVar5 ^ uVar1 ^ uVar4) + iVar10 + uVar3 + 0x6ed9eba1;
  uVar3 = uVar3 >> 0x1d | uVar3 * 8;
  uVar5 = (uVar1 ^ uVar4 ^ uVar3) + iVar17 + uVar5 + 0x6ed9eba1;
  uVar6 = uVar5 >> 0x17 | uVar5 * 0x200;
  uVar1 = (uVar6 ^ uVar4 ^ uVar3) + iVar20 + uVar1 + 0x6ed9eba1;
  uVar1 = uVar1 >> 0x15 | uVar1 * 0x800;
  uVar4 = (uVar6 ^ uVar1 ^ uVar3) + iVar13 + uVar4 + 0x6ed9eba1;
  uVar5 = uVar4 >> 0x11 | uVar4 * 0x8000;
  uVar3 = (uVar6 ^ uVar1 ^ uVar5) + iVar19 + uVar3 + 0x6ed9eba1;
  uVar4 = uVar3 >> 0x1d | uVar3 * 8;
  uVar3 = (uVar1 ^ uVar5 ^ uVar4) + iVar15 + uVar6 + 0x6ed9eba1;
  uVar6 = uVar3 >> 0x17 | uVar3 * 0x200;
  uVar1 = (uVar6 ^ uVar5 ^ uVar4) + iVar18 + uVar1 + 0x6ed9eba1;
  uVar3 = uVar1 >> 0x15 | uVar1 * 0x800;
  uVar1 = (uVar6 ^ uVar3 ^ uVar4) + param_2[0xf] + uVar5 + 0x6ed9eba1;
  *param_1 = *param_1 + uVar4;
  param_1[1] = (uVar1 >> 0x11 | uVar1 * 0x8000) + uVar2;
  param_1[2] = uVar7 + uVar3;
  param_1[3] = uVar8 + uVar6;
  return;
}



/* 1001ba9c MD4Update */

/* Boundary evidence: original MIPS .pdata 1001ba9c..1001bc0f. Semantic name remains unreviewed. */

void MD4Update(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x1ba9c  43  MD4Update */
  uVar1 = param_1[4];
  uVar2 = param_3 * 8 + uVar1;
  param_1[4] = uVar2;
  uVar1 = uVar1 >> 3 & 0x3f;
  if (uVar2 < param_3 << 3) {
    param_1[5] = param_1[5] + 1;
  }
  param_1[5] = (param_3 >> 0x1d) + param_1[5];
  if ((uVar1 != 0) && (0x3f < uVar1 + param_3)) {
    memcpy((void *)((int)param_1 + uVar1 + 0x18),param_2,0x40 - uVar1);
    param_2 = (int *)((int)param_2 + (0x40 - uVar1));
    param_3 = (uVar1 + param_3) - 0x40;
    FUN_1001b33c(param_1,param_1 + 6);
    uVar1 = 0;
  }
  if (((uint)param_2 & 3) == 0) {
    if (0x3f < param_3) {
      uVar2 = param_3 >> 6;
      do {
        FUN_1001b33c(param_1,param_2);
        param_2 = param_2 + 0x10;
        uVar2 = uVar2 - 1;
        param_3 = param_3 - 0x40;
      } while (uVar2 != 0);
    }
  }
  else if (0x3f < param_3) {
    uVar2 = param_3 >> 6;
    do {
      memcpy(param_1 + 6,param_2,0x40);
      FUN_1001b33c(param_1,param_1 + 6);
      param_2 = param_2 + 0x10;
      uVar2 = uVar2 - 1;
      param_3 = param_3 - 0x40;
    } while (uVar2 != 0);
  }
  if (param_3 != 0) {
    memcpy((void *)((int)param_1 + uVar1 + 0x18),param_2,param_3);
  }
  return;
}



/* 1001bc10 MD4Final */

/* Boundary evidence: original MIPS .pdata 1001bc10..1001bcaf. Semantic name remains unreviewed. */

void MD4Final(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  
                    /* 0x1bc10  41  MD4Final */
  puVar2 = param_1 + 0x16;
  *puVar2 = param_1[4];
  uVar1 = param_1[4] >> 3 & 0x3f;
  param_1[0x17] = param_1[5];
  if (uVar1 < 0x38) {
    uVar1 = 0x38 - uVar1;
  }
  else {
    uVar1 = 0x78 - uVar1;
  }
  MD4Update((int *)param_1,(int *)&DAT_10002ab8,uVar1);
  MD4Update((int *)param_1,(int *)puVar2,8);
  *puVar2 = *param_1;
  param_1[0x17] = param_1[1];
  param_1[0x18] = param_1[2];
  param_1[0x19] = param_1[3];
  return;
}



/* 1001bcb0 MD5Init */

void MD5Init(undefined4 *param_1)

{
                    /* 0x1bcb0  45  MD5Init */
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0x67452301;
  param_1[3] = 0xefcdab89;
  param_1[4] = 0x98badcfe;
  param_1[5] = 0x10325476;
  return;
}



/* 1001bcec FUN_1001bcec */

/* Boundary evidence: original MIPS .pdata 1001bcec..1001c9f3. Semantic name remains unreviewed. */

void FUN_1001bcec(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  
  uVar8 = param_1[2];
  uVar10 = param_1[3];
  uVar1 = param_1[1];
  iVar11 = *param_2;
  uVar2 = ((uVar10 ^ uVar8) & uVar1 ^ uVar10) + iVar11 + *param_1 + 0xd76aa478;
  uVar2 = (uVar2 >> 0x19 | uVar2 * 0x80) + uVar1;
  iVar12 = param_2[1];
  uVar4 = ((uVar8 ^ uVar1) & uVar2 ^ uVar8) + iVar12 + uVar10 + 0xe8c7b756;
  iVar13 = param_2[2];
  uVar5 = (uVar4 >> 0x14 | uVar4 * 0x1000) + uVar2;
  uVar4 = ((uVar1 ^ uVar2) & uVar5 ^ uVar1) + iVar13 + uVar8 + 0x242070db;
  uVar4 = (uVar4 >> 0xf | uVar4 * 0x20000) + uVar5;
  iVar14 = param_2[3];
  uVar6 = ((uVar5 ^ uVar2) & uVar4 ^ uVar2) + iVar14 + uVar1 + 0xc1bdceee;
  iVar23 = param_2[4];
  uVar6 = (uVar6 >> 10 | uVar6 * 0x400000) + uVar4;
  uVar2 = ((uVar5 ^ uVar4) & uVar6 ^ uVar5) + iVar23 + uVar2 + 0xf57c0faf;
  uVar2 = (uVar2 >> 0x19 | uVar2 * 0x80) + uVar6;
  iVar24 = param_2[5];
  uVar5 = ((uVar4 ^ uVar6) & uVar2 ^ uVar4) + iVar24 + uVar5 + 0x4787c62a;
  uVar5 = (uVar5 >> 0x14 | uVar5 * 0x1000) + uVar2;
  iVar25 = param_2[6];
  uVar4 = ((uVar6 ^ uVar2) & uVar5 ^ uVar6) + iVar25 + uVar4 + 0xa8304613;
  uVar4 = (uVar4 >> 0xf | uVar4 * 0x20000) + uVar5;
  iVar22 = param_2[7];
  uVar6 = ((uVar5 ^ uVar2) & uVar4 ^ uVar2) + iVar22 + uVar6 + 0xfd469501;
  uVar6 = (uVar6 >> 10 | uVar6 * 0x400000) + uVar4;
  iVar21 = param_2[8];
  uVar2 = ((uVar5 ^ uVar4) & uVar6 ^ uVar5) + iVar21 + uVar2 + 0x698098d8;
  uVar2 = (uVar2 >> 0x19 | uVar2 * 0x80) + uVar6;
  iVar20 = param_2[9];
  uVar5 = ((uVar4 ^ uVar6) & uVar2 ^ uVar4) + iVar20 + uVar5 + 0x8b44f7af;
  uVar5 = (uVar5 >> 0x14 | uVar5 * 0x1000) + uVar2;
  iVar19 = param_2[10];
  uVar4 = (((uVar6 ^ uVar2) & uVar5 ^ uVar6) + iVar19 + uVar4) - 0xa44f;
  uVar4 = (uVar4 >> 0xf | uVar4 * 0x20000) + uVar5;
  iVar18 = param_2[0xb];
  uVar6 = ((uVar5 ^ uVar2) & uVar4 ^ uVar2) + iVar18 + uVar6 + 0x895cd7be;
  uVar7 = (uVar6 >> 10 | uVar6 * 0x400000) + uVar4;
  iVar17 = param_2[0xc];
  uVar2 = ((uVar5 ^ uVar4) & uVar7 ^ uVar5) + iVar17 + uVar2 + 0x6b901122;
  uVar2 = (uVar2 >> 0x19 | uVar2 * 0x80) + uVar7;
  iVar16 = param_2[0xd];
  uVar5 = ((uVar4 ^ uVar7) & uVar2 ^ uVar4) + iVar16 + uVar5 + 0xfd987193;
  iVar15 = param_2[0xe];
  uVar9 = (uVar5 >> 0x14 | uVar5 * 0x1000) + uVar2;
  uVar4 = ((uVar7 ^ uVar2) & uVar9 ^ uVar7) + iVar15 + uVar4 + 0xa679438e;
  uVar6 = (uVar4 >> 0xf | uVar4 * 0x20000) + uVar9;
  iVar3 = param_2[0xf];
  uVar4 = ((uVar9 ^ uVar2) & uVar6 ^ uVar2) + iVar3 + uVar7 + 0x49b40821;
  uVar5 = (uVar4 >> 10 | uVar4 * 0x400000) + uVar6;
  uVar2 = ((uVar6 ^ uVar5) & uVar9 ^ uVar6) + iVar12 + uVar2 + 0xf61e2562;
  uVar2 = (uVar2 >> 0x1b | uVar2 * 0x20) + uVar5;
  uVar4 = ((uVar5 ^ uVar2) & uVar6 ^ uVar5) + iVar25 + uVar9 + 0xc040b340;
  uVar4 = (uVar4 >> 0x17 | uVar4 * 0x200) + uVar2;
  uVar6 = ((uVar4 ^ uVar2) & uVar5 ^ uVar2) + iVar18 + uVar6 + 0x265e5a51;
  uVar6 = (uVar6 >> 0x12 | uVar6 * 0x4000) + uVar4;
  uVar5 = ((uVar4 ^ uVar6) & uVar2 ^ uVar4) + iVar11 + uVar5 + 0xe9b6c7aa;
  uVar5 = (uVar5 >> 0xc | uVar5 * 0x100000) + uVar6;
  uVar2 = ((uVar6 ^ uVar5) & uVar4 ^ uVar6) + iVar24 + uVar2 + 0xd62f105d;
  uVar2 = (uVar2 >> 0x1b | uVar2 * 0x20) + uVar5;
  uVar4 = ((uVar5 ^ uVar2) & uVar6 ^ uVar5) + iVar19 + uVar4 + 0x2441453;
  uVar4 = (uVar4 >> 0x17 | uVar4 * 0x200) + uVar2;
  uVar6 = ((uVar4 ^ uVar2) & uVar5 ^ uVar2) + iVar3 + uVar6 + 0xd8a1e681;
  uVar6 = (uVar6 >> 0x12 | uVar6 * 0x4000) + uVar4;
  uVar5 = ((uVar4 ^ uVar6) & uVar2 ^ uVar4) + iVar23 + uVar5 + 0xe7d3fbc8;
  uVar5 = (uVar5 >> 0xc | uVar5 * 0x100000) + uVar6;
  uVar2 = ((uVar6 ^ uVar5) & uVar4 ^ uVar6) + iVar20 + uVar2 + 0x21e1cde6;
  uVar2 = (uVar2 >> 0x1b | uVar2 * 0x20) + uVar5;
  uVar4 = ((uVar5 ^ uVar2) & uVar6 ^ uVar5) + iVar15 + uVar4 + 0xc33707d6;
  uVar4 = (uVar4 >> 0x17 | uVar4 * 0x200) + uVar2;
  uVar6 = ((uVar4 ^ uVar2) & uVar5 ^ uVar2) + iVar14 + uVar6 + 0xf4d50d87;
  uVar6 = (uVar6 >> 0x12 | uVar6 * 0x4000) + uVar4;
  uVar5 = ((uVar4 ^ uVar6) & uVar2 ^ uVar4) + iVar21 + uVar5 + 0x455a14ed;
  uVar5 = (uVar5 >> 0xc | uVar5 * 0x100000) + uVar6;
  uVar2 = ((uVar6 ^ uVar5) & uVar4 ^ uVar6) + iVar16 + uVar2 + 0xa9e3e905;
  uVar2 = (uVar2 >> 0x1b | uVar2 * 0x20) + uVar5;
  uVar4 = ((uVar5 ^ uVar2) & uVar6 ^ uVar5) + iVar13 + uVar4 + 0xfcefa3f8;
  uVar4 = (uVar4 >> 0x17 | uVar4 * 0x200) + uVar2;
  uVar6 = ((uVar4 ^ uVar2) & uVar5 ^ uVar2) + iVar22 + uVar6 + 0x676f02d9;
  uVar7 = (uVar6 >> 0x12 | uVar6 * 0x4000) + uVar4;
  uVar5 = ((uVar4 ^ uVar7) & uVar2 ^ uVar4) + iVar17 + uVar5 + 0x8d2a4c8a;
  uVar6 = (uVar5 >> 0xc | uVar5 * 0x100000) + uVar7;
  uVar2 = ((uVar4 ^ uVar7 ^ uVar6) + iVar24 + uVar2) - 0x5c6be;
  uVar2 = (uVar2 >> 0x1c | uVar2 * 0x10) + uVar6;
  uVar4 = (uVar7 ^ uVar6 ^ uVar2) + iVar21 + uVar4 + 0x8771f681;
  uVar5 = (uVar4 >> 0x15 | uVar4 * 0x800) + uVar2;
  uVar4 = (uVar5 ^ uVar6 ^ uVar2) + iVar18 + uVar7 + 0x6d9d6122;
  uVar4 = (uVar4 >> 0x10 | uVar4 * 0x10000) + uVar5;
  uVar6 = (uVar5 ^ uVar4 ^ uVar2) + iVar15 + uVar6 + 0xfde5380c;
  uVar6 = (uVar6 >> 9 | uVar6 * 0x800000) + uVar4;
  uVar2 = (uVar5 ^ uVar4 ^ uVar6) + iVar12 + uVar2 + 0xa4beea44;
  uVar2 = (uVar2 >> 0x1c | uVar2 * 0x10) + uVar6;
  uVar5 = (uVar4 ^ uVar6 ^ uVar2) + iVar23 + uVar5 + 0x4bdecfa9;
  uVar5 = (uVar5 >> 0x15 | uVar5 * 0x800) + uVar2;
  uVar4 = (uVar5 ^ uVar6 ^ uVar2) + iVar22 + uVar4 + 0xf6bb4b60;
  uVar4 = (uVar4 >> 0x10 | uVar4 * 0x10000) + uVar5;
  uVar6 = (uVar5 ^ uVar4 ^ uVar2) + iVar19 + uVar6 + 0xbebfbc70;
  uVar6 = (uVar6 >> 9 | uVar6 * 0x800000) + uVar4;
  uVar2 = (uVar5 ^ uVar4 ^ uVar6) + iVar16 + uVar2 + 0x289b7ec6;
  uVar2 = (uVar2 >> 0x1c | uVar2 * 0x10) + uVar6;
  uVar5 = (uVar4 ^ uVar6 ^ uVar2) + iVar11 + uVar5 + 0xeaa127fa;
  uVar5 = (uVar5 >> 0x15 | uVar5 * 0x800) + uVar2;
  uVar4 = (uVar5 ^ uVar6 ^ uVar2) + iVar14 + uVar4 + 0xd4ef3085;
  uVar4 = (uVar4 >> 0x10 | uVar4 * 0x10000) + uVar5;
  uVar6 = (uVar5 ^ uVar4 ^ uVar2) + iVar25 + uVar6 + 0x4881d05;
  uVar6 = (uVar6 >> 9 | uVar6 * 0x800000) + uVar4;
  uVar2 = (uVar5 ^ uVar4 ^ uVar6) + iVar20 + uVar2 + 0xd9d4d039;
  uVar2 = (uVar2 >> 0x1c | uVar2 * 0x10) + uVar6;
  uVar5 = (uVar4 ^ uVar6 ^ uVar2) + iVar17 + uVar5 + 0xe6db99e5;
  uVar5 = (uVar5 >> 0x15 | uVar5 * 0x800) + uVar2;
  uVar4 = (uVar5 ^ uVar6 ^ uVar2) + iVar3 + uVar4 + 0x1fa27cf8;
  uVar4 = (uVar4 >> 0x10 | uVar4 * 0x10000) + uVar5;
  uVar6 = (uVar5 ^ uVar4 ^ uVar2) + iVar13 + uVar6 + 0xc4ac5665;
  uVar6 = (uVar6 >> 9 | uVar6 * 0x800000) + uVar4;
  uVar2 = ((~uVar5 | uVar6) ^ uVar4) + iVar11 + uVar2 + 0xf4292244;
  uVar2 = (uVar2 >> 0x1a | uVar2 * 0x40) + uVar6;
  uVar5 = ((~uVar4 | uVar2) ^ uVar6) + iVar22 + uVar5 + 0x432aff97;
  uVar5 = (uVar5 >> 0x16 | uVar5 * 0x400) + uVar2;
  uVar4 = ((~uVar6 | uVar5) ^ uVar2) + iVar15 + uVar4 + 0xab9423a7;
  uVar4 = (uVar4 >> 0x11 | uVar4 * 0x8000) + uVar5;
  uVar6 = ((~uVar2 | uVar4) ^ uVar5) + iVar24 + uVar6 + 0xfc93a039;
  uVar6 = (uVar6 >> 0xb | uVar6 * 0x200000) + uVar4;
  uVar2 = ((~uVar5 | uVar6) ^ uVar4) + iVar17 + uVar2 + 0x655b59c3;
  uVar2 = (uVar2 >> 0x1a | uVar2 * 0x40) + uVar6;
  uVar5 = ((~uVar4 | uVar2) ^ uVar6) + iVar14 + uVar5 + 0x8f0ccc92;
  uVar5 = (uVar5 >> 0x16 | uVar5 * 0x400) + uVar2;
  uVar4 = (((~uVar6 | uVar5) ^ uVar2) + iVar19 + uVar4) - 0x100b83;
  uVar4 = (uVar4 >> 0x11 | uVar4 * 0x8000) + uVar5;
  uVar6 = ((~uVar2 | uVar4) ^ uVar5) + iVar12 + uVar6 + 0x85845dd1;
  uVar6 = (uVar6 >> 0xb | uVar6 * 0x200000) + uVar4;
  uVar2 = ((~uVar5 | uVar6) ^ uVar4) + iVar21 + uVar2 + 0x6fa87e4f;
  uVar2 = (uVar2 >> 0x1a | uVar2 * 0x40) + uVar6;
  uVar5 = ((~uVar4 | uVar2) ^ uVar6) + iVar3 + uVar5 + 0xfe2ce6e0;
  uVar5 = (uVar5 >> 0x16 | uVar5 * 0x400) + uVar2;
  uVar4 = ((~uVar6 | uVar5) ^ uVar2) + iVar25 + uVar4 + 0xa3014314;
  uVar4 = (uVar4 >> 0x11 | uVar4 * 0x8000) + uVar5;
  uVar6 = ((~uVar2 | uVar4) ^ uVar5) + iVar16 + uVar6 + 0x4e0811a1;
  uVar6 = (uVar6 >> 0xb | uVar6 * 0x200000) + uVar4;
  uVar2 = ((~uVar5 | uVar6) ^ uVar4) + iVar23 + uVar2 + 0xf7537e82;
  uVar2 = (uVar2 >> 0x1a | uVar2 * 0x40) + uVar6;
  uVar5 = ((~uVar4 | uVar2) ^ uVar6) + iVar18 + uVar5 + 0xbd3af235;
  uVar5 = (uVar5 >> 0x16 | uVar5 * 0x400) + uVar2;
  uVar4 = ((~uVar6 | uVar5) ^ uVar2) + iVar13 + uVar4 + 0x2ad7d2bb;
  uVar4 = (uVar4 >> 0x11 | uVar4 * 0x8000) + uVar5;
  uVar6 = ((~uVar2 | uVar4) ^ uVar5) + iVar20 + uVar6 + 0xeb86d391;
  *param_1 = *param_1 + uVar2;
  param_1[1] = uVar1 + (uVar6 >> 0xb | uVar6 * 0x200000) + uVar4;
  param_1[2] = uVar8 + uVar4;
  param_1[3] = uVar10 + uVar5;
  return;
}



/* 1001c9f4 MD5Update */

/* Boundary evidence: original MIPS .pdata 1001c9f4..1001cb17. Semantic name remains unreviewed. */

void MD5Update(uint *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x1c9f4  46  MD5Update */
  uVar1 = *param_1;
  uVar2 = param_3 * 8 + uVar1;
  *param_1 = uVar2;
  uVar1 = uVar1 >> 3 & 0x3f;
  if (uVar2 < param_3 << 3) {
    param_1[1] = param_1[1] + 1;
  }
  param_1[1] = (param_3 >> 0x1d) + param_1[1];
  if ((uVar1 != 0) && (0x3f < uVar1 + param_3)) {
    memcpy((void *)((int)param_1 + uVar1 + 0x18),param_2,0x40 - uVar1);
    param_2 = (int *)((int)param_2 + (0x40 - uVar1));
    param_3 = (uVar1 + param_3) - 0x40;
    FUN_1001bcec((int *)(param_1 + 2),(int *)(param_1 + 6));
    uVar1 = 0;
  }
  if (0x3f < param_3) {
    uVar2 = param_3 >> 6;
    do {
      FUN_1001bcec((int *)(param_1 + 2),param_2);
      param_2 = param_2 + 0x10;
      uVar2 = uVar2 - 1;
      param_3 = param_3 - 0x40;
    } while (uVar2 != 0);
  }
  if (param_3 != 0) {
    memcpy((void *)((int)param_1 + uVar1 + 0x18),param_2,param_3);
  }
  return;
}



/* 1001cb18 MD5Final */

/* Boundary evidence: original MIPS .pdata 1001cb18..1001cbb7. Semantic name remains unreviewed. */

void MD5Final(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  
                    /* 0x1cb18  44  MD5Final */
  puVar2 = param_1 + 0x16;
  *puVar2 = *param_1;
  uVar1 = *param_1 >> 3 & 0x3f;
  param_1[0x17] = param_1[1];
  if (uVar1 < 0x38) {
    uVar1 = 0x38 - uVar1;
  }
  else {
    uVar1 = 0x78 - uVar1;
  }
  MD5Update(param_1,(int *)&DAT_10002af8,uVar1);
  MD5Update(param_1,(int *)puVar2,8);
  *puVar2 = param_1[2];
  param_1[0x17] = param_1[3];
  param_1[0x18] = param_1[4];
  param_1[0x19] = param_1[5];
  return;
}



/* 1001cbb8 MDbegin */

void MDbegin(undefined4 *param_1)

{
                    /* 0x1cbb8  47  MDbegin */
  *param_1 = 0x67452301;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}



/* 1001cbf8 FUN_1001cbf8 */

/* Boundary evidence: original MIPS .pdata 1001cbf8..1001d41b. Semantic name remains unreviewed. */

void FUN_1001cbf8(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  uVar8 = param_1[2];
  uVar9 = param_1[3];
  uVar6 = param_1[1];
  iVar11 = *param_2;
  uVar1 = ((uVar9 ^ uVar8) & uVar6 ^ uVar9) + iVar11 + *param_1;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  uVar2 = ((uVar8 ^ uVar6) & uVar1 ^ uVar8) + uVar9 + param_2[1];
  uVar2 = uVar2 * 0x80 | uVar2 >> 0x19;
  uVar3 = ((uVar6 ^ uVar1) & uVar2 ^ uVar6) + uVar8 + param_2[2];
  uVar4 = uVar3 * 0x800 | uVar3 >> 0x15;
  uVar3 = ((uVar2 ^ uVar1) & uVar4 ^ uVar1) + uVar6 + param_2[3];
  uVar3 = uVar3 >> 0xd | uVar3 * 0x80000;
  uVar1 = ((uVar2 ^ uVar4) & uVar3 ^ uVar2) + param_2[4] + uVar1;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  uVar2 = ((uVar4 ^ uVar3) & uVar1 ^ uVar4) + uVar2 + param_2[5];
  uVar2 = uVar2 * 0x80 | uVar2 >> 0x19;
  uVar4 = ((uVar3 ^ uVar1) & uVar2 ^ uVar3) + uVar4 + param_2[6];
  uVar4 = uVar4 * 0x800 | uVar4 >> 0x15;
  uVar3 = ((uVar2 ^ uVar1) & uVar4 ^ uVar1) + uVar3 + param_2[7];
  uVar3 = uVar3 >> 0xd | uVar3 * 0x80000;
  uVar1 = ((uVar2 ^ uVar4) & uVar3 ^ uVar2) + param_2[8] + uVar1;
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  uVar2 = ((uVar4 ^ uVar3) & uVar1 ^ uVar4) + uVar2 + param_2[9];
  uVar2 = uVar2 * 0x80 | uVar2 >> 0x19;
  uVar4 = ((uVar3 ^ uVar1) & uVar2 ^ uVar3) + uVar4 + param_2[10];
  uVar4 = uVar4 * 0x800 | uVar4 >> 0x15;
  uVar3 = ((uVar2 ^ uVar1) & uVar4 ^ uVar1) + uVar3 + param_2[0xb];
  uVar3 = uVar3 >> 0xd | uVar3 * 0x80000;
  uVar1 = ((uVar2 ^ uVar4) & uVar3 ^ uVar2) + uVar1 + param_2[0xc];
  uVar1 = uVar1 >> 0x1d | uVar1 * 8;
  uVar2 = ((uVar4 ^ uVar3) & uVar1 ^ uVar4) + uVar2 + param_2[0xd];
  uVar7 = uVar2 * 0x80 | uVar2 >> 0x19;
  uVar2 = ((uVar3 ^ uVar1) & uVar7 ^ uVar3) + uVar4 + param_2[0xe];
  uVar2 = uVar2 * 0x800 | uVar2 >> 0x15;
  uVar3 = ((uVar7 ^ uVar1) & uVar2 ^ uVar1) + uVar3 + param_2[0xf];
  uVar3 = uVar3 >> 0xd | uVar3 * 0x80000;
  iVar5 = ((uVar2 | uVar3) & uVar7 | uVar2 & uVar3) + iVar11 + uVar1;
  uVar4 = (iVar5 + -0x57d8667) * 8 | iVar5 + 0x5a827999U >> 0x1d;
  iVar5 = ((uVar3 | uVar4) & uVar2 | uVar3 & uVar4) + param_2[4] + uVar7;
  uVar7 = (iVar5 + 0x2827999) * 0x20 | iVar5 + 0x5a827999U >> 0x1b;
  iVar5 = ((uVar3 | uVar4) & uVar7 | uVar3 & uVar4) + param_2[8] + uVar2;
  uVar1 = (iVar5 + 0x27999) * 0x200 | iVar5 + 0x5a827999U >> 0x17;
  iVar5 = ((uVar1 | uVar4) & uVar7 | uVar1 & uVar4) + param_2[0xc] + uVar3;
  uVar2 = iVar5 + 0x5a827999U >> 0x13 | (iVar5 + 0x27999) * 0x2000;
  iVar5 = ((uVar1 | uVar2) & uVar7 | uVar1 & uVar2) + uVar4 + param_2[1];
  uVar3 = (iVar5 + -0x57d8667) * 8 | iVar5 + 0x5a827999U >> 0x1d;
  iVar5 = ((uVar2 | uVar3) & uVar1 | uVar2 & uVar3) + uVar7 + param_2[5];
  uVar4 = (iVar5 + 0x2827999) * 0x20 | iVar5 + 0x5a827999U >> 0x1b;
  iVar5 = ((uVar2 | uVar3) & uVar4 | uVar2 & uVar3) + uVar1 + param_2[9];
  uVar1 = (iVar5 + 0x27999) * 0x200 | iVar5 + 0x5a827999U >> 0x17;
  iVar5 = ((uVar1 | uVar3) & uVar4 | uVar1 & uVar3) + uVar2 + param_2[0xd];
  uVar2 = iVar5 + 0x5a827999U >> 0x13 | (iVar5 + 0x27999) * 0x2000;
  iVar13 = param_2[2];
  iVar5 = ((uVar1 | uVar2) & uVar4 | uVar1 & uVar2) + iVar13 + uVar3;
  uVar7 = iVar5 + 0x5a827999U >> 0x1d | (iVar5 + -0x57d8667) * 8;
  iVar5 = ((uVar2 | uVar7) & uVar1 | uVar2 & uVar7) + uVar4 + param_2[6];
  uVar10 = iVar5 + 0x5a827999U >> 0x1b | (iVar5 + 0x2827999) * 0x20;
  iVar5 = ((uVar2 | uVar7) & uVar10 | uVar2 & uVar7) + uVar1 + param_2[10];
  uVar3 = iVar5 + 0x5a827999U >> 0x17 | (iVar5 + 0x27999) * 0x200;
  iVar5 = ((uVar3 | uVar7) & uVar10 | uVar3 & uVar7) + uVar2 + param_2[0xe];
  uVar4 = iVar5 + 0x5a827999U >> 0x13 | (iVar5 + 0x27999) * 0x2000;
  iVar5 = ((uVar3 | uVar4) & uVar10 | uVar3 & uVar4) + uVar7 + param_2[3];
  uVar1 = iVar5 + 0x5a827999U >> 0x1d | (iVar5 + -0x57d8667) * 8;
  iVar5 = ((uVar4 | uVar1) & uVar3 | uVar4 & uVar1) + uVar10 + param_2[7];
  uVar2 = iVar5 + 0x5a827999U >> 0x1b | (iVar5 + 0x2827999) * 0x20;
  iVar5 = ((uVar4 | uVar1) & uVar2 | uVar4 & uVar1) + uVar3 + param_2[0xb];
  uVar3 = iVar5 + 0x5a827999U >> 0x17 | (iVar5 + 0x27999) * 0x200;
  iVar5 = ((uVar3 | uVar1) & uVar2 | uVar3 & uVar1) + uVar4 + param_2[0xf];
  uVar7 = iVar5 + 0x5a827999U >> 0x13 | (iVar5 + 0x27999) * 0x2000;
  iVar5 = (uVar2 ^ uVar3 ^ uVar7) + iVar11 + uVar1;
  uVar4 = (iVar5 + 0xed9eba1) * 8 | iVar5 + 0x6ed9eba1U >> 0x1d;
  iVar5 = (uVar3 ^ uVar7 ^ uVar4) + uVar2 + param_2[8];
  uVar10 = (iVar5 + -0x26145f) * 0x200 | iVar5 + 0x6ed9eba1U >> 0x17;
  iVar5 = (uVar10 ^ uVar7 ^ uVar4) + uVar3 + param_2[4];
  uVar12 = (iVar5 + -0x6145f) * 0x800 | iVar5 + 0x6ed9eba1U >> 0x15;
  iVar5 = (uVar10 ^ uVar12 ^ uVar4) + param_2[0xc] + uVar7;
  uVar1 = (iVar5 + -0x145f) * 0x8000 | iVar5 + 0x6ed9eba1U >> 0x11;
  uVar2 = uVar10 ^ uVar12 ^ uVar1;
  uVar2 = (uVar2 + iVar13 + uVar4 + 0xed9eba1) * 8 | uVar2 + uVar4 + iVar13 + 0x6ed9eba1 >> 0x1d;
  iVar5 = (uVar12 ^ uVar1 ^ uVar2) + uVar10 + param_2[10];
  uVar3 = (iVar5 + -0x26145f) * 0x200 | iVar5 + 0x6ed9eba1U >> 0x17;
  iVar5 = (uVar3 ^ uVar1 ^ uVar2) + uVar12 + param_2[6];
  uVar4 = (iVar5 + -0x6145f) * 0x800 | iVar5 + 0x6ed9eba1U >> 0x15;
  iVar5 = (uVar3 ^ uVar4 ^ uVar2) + uVar1 + param_2[0xe];
  uVar1 = (iVar5 + -0x145f) * 0x8000 | iVar5 + 0x6ed9eba1U >> 0x11;
  iVar5 = (uVar3 ^ uVar4 ^ uVar1) + uVar2 + param_2[1];
  uVar2 = iVar5 + 0x6ed9eba1U >> 0x1d | (iVar5 + 0xed9eba1) * 8;
  iVar5 = (uVar4 ^ uVar1 ^ uVar2) + uVar3 + param_2[9];
  uVar3 = (iVar5 + -0x26145f) * 0x200 | iVar5 + 0x6ed9eba1U >> 0x17;
  iVar5 = (uVar3 ^ uVar1 ^ uVar2) + uVar4 + param_2[5];
  uVar7 = (iVar5 + -0x6145f) * 0x800 | iVar5 + 0x6ed9eba1U >> 0x15;
  iVar5 = (uVar3 ^ uVar7 ^ uVar2) + uVar1 + param_2[0xd];
  uVar4 = (iVar5 + -0x145f) * 0x8000 | iVar5 + 0x6ed9eba1U >> 0x11;
  iVar5 = (uVar3 ^ uVar7 ^ uVar4) + uVar2 + param_2[3];
  uVar2 = iVar5 + 0x6ed9eba1U >> 0x1d | (iVar5 + 0xed9eba1) * 8;
  iVar5 = (uVar7 ^ uVar4 ^ uVar2) + uVar3 + param_2[0xb];
  uVar3 = (iVar5 + -0x26145f) * 0x200 | iVar5 + 0x6ed9eba1U >> 0x17;
  iVar5 = (uVar3 ^ uVar4 ^ uVar2) + uVar7 + param_2[7];
  uVar1 = (iVar5 + -0x6145f) * 0x800 | iVar5 + 0x6ed9eba1U >> 0x15;
  iVar5 = (uVar3 ^ uVar1 ^ uVar2) + uVar4 + param_2[0xf];
  *param_1 = *param_1 + uVar2;
  param_1[1] = uVar6 + ((iVar5 + -0x145f) * 0x8000 | iVar5 + 0x6ed9eba1U >> 0x11);
  param_1[2] = uVar8 + uVar1;
  param_1[3] = uVar9 + uVar3;
  return;
}



/* 1001d41c MDupdate */

/* Boundary evidence: original MIPS .pdata 1001d41c..1001d5a3. Semantic name remains unreviewed. */

undefined4 MDupdate(int *param_1,int *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  byte local_58 [56];
  int local_20;
  int local_1c;
  
                    /* 0x1d41c  48  MDupdate */
  if ((param_3 != 0) || (param_1[6] == 0)) {
    if (param_1[6] != 0) {
      return 2;
    }
    uVar2 = param_1[4];
    uVar4 = uVar2 + param_3;
    param_1[4] = uVar4;
    if (uVar4 < uVar2) {
      param_1[5] = param_1[5] + 1;
    }
    if (param_3 == 0x200) {
      FUN_1001cbf8(param_1,param_2);
    }
    else {
      if (0x200 < (int)param_3) {
        return 1;
      }
      uVar2 = (int)param_3 >> 3;
      uVar4 = uVar2 + 1;
      memcpy(local_58,param_2,uVar4);
      if (uVar4 < 0x40) {
        pbVar3 = local_58 + uVar2 + 1;
        if (0x40 - uVar4 != 0) {
          pbVar5 = pbVar3 + (0x40 - uVar4);
          do {
            *pbVar3 = 0;
            pbVar3 = pbVar3 + 1;
          } while (pbVar3 != pbVar5);
        }
      }
      bVar1 = (byte)(1 << (7 - (param_3 & 7) & 0x1f));
      local_58[uVar2] = (local_58[uVar2] | bVar1) & ~(bVar1 - 1);
      if (0x37 < uVar2) {
        FUN_1001cbf8(param_1,(int *)local_58);
        pbVar3 = local_58;
        do {
          pbVar3[0] = 0;
          pbVar3[1] = 0;
          pbVar3[2] = 0;
          pbVar3[3] = 0;
          pbVar3 = pbVar3 + 4;
        } while (pbVar3 != (byte *)&local_20);
      }
      local_20 = param_1[4];
      local_1c = param_1[5];
      FUN_1001cbf8(param_1,(int *)local_58);
      param_1[6] = 1;
    }
  }
  return 0;
}



/* 1001d5a4 RC2Key */

/* Boundary evidence: original MIPS .pdata 1001d5a4..1001d673. Semantic name remains unreviewed. */

undefined4 RC2Key(void *param_1,void *param_2,size_t param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  
                    /* 0x1d5a4  50  RC2Key */
  memcpy(param_1,param_2,param_3);
  if ((int)param_3 < 0x80) {
    pbVar4 = (byte *)((int)param_1 + (param_3 - 1));
    iVar5 = 0x80 - param_3;
    do {
      pbVar6 = pbVar4 + (1 - param_3);
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 1;
      *pbVar4 = (&DAT_10002b38)[(uint)*pbVar6 + (uint)bVar1 & 0xff];
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  iVar5 = 0x7a;
  *(undefined *)((int)param_1 + 0x7b) = (&DAT_10002b38)[*(byte *)((int)param_1 + 0x7b)];
  do {
    iVar2 = iVar5 + 5;
    iVar3 = iVar5 + 1;
    puVar7 = (undefined1 *)(iVar5 + (int)param_1);
    iVar5 = iVar5 + -1;
    *puVar7 = (&DAT_10002b38)[*(byte *)((int)param_1 + iVar2) ^ *(byte *)((int)param_1 + iVar3)];
  } while (-1 < iVar5);
  return 0;
}



/* 1001d674 RC2KeyEx */

/* Boundary evidence: original MIPS .pdata 1001d674..1001d78b. Semantic name remains unreviewed. */

undefined4 RC2KeyEx(void *param_1,void *param_2,size_t param_3,int param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  uint uVar6;
  
                    /* 0x1d674  51  RC2KeyEx */
  uVar6 = param_4 + 7U >> 3;
  memcpy(param_1,param_2,param_3);
  if ((int)param_3 < 0x80) {
    pbVar2 = (byte *)((int)param_1 + (param_3 - 1));
    iVar3 = 0x80 - param_3;
    do {
      pbVar4 = pbVar2 + (1 - param_3);
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
      *pbVar2 = (&DAT_10002b38)[(uint)*pbVar4 + (uint)bVar1 & 0xff];
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *(undefined *)((int)param_1 + (0x80 - uVar6)) =
       (&DAT_10002b38)
       [0xff >> (uVar6 * 8 - param_4 & 0x1f) & (uint)*(byte *)((int)param_1 + (0x80 - uVar6))];
  iVar3 = 0x7f - uVar6;
  if (-1 < iVar3) {
    do {
      pbVar2 = (byte *)((int)param_1 + iVar3 + 1);
      puVar5 = (undefined1 *)(iVar3 + (int)param_1);
      iVar3 = iVar3 + -1;
      *puVar5 = (&DAT_10002b38)[pbVar2[uVar6 - 1] ^ *pbVar2];
    } while (-1 < iVar3);
  }
  return 0;
}



/* 1001d78c RC2 */

void RC2(undefined1 *param_1,ushort *param_2,ushort *param_3,int param_4)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  
                    /* 0x1d78c  49  RC2 */
  uVar6 = (uint)*param_2;
  uVar4 = (uint)param_2[1];
  uVar8 = (uint)param_2[2];
  uVar2 = (uint)param_2[3];
  if (param_4 == 0) {
    puVar1 = param_3 + 0x3c;
    iVar9 = 5;
    do {
      uVar2 = ((((uVar2 & 0x1f) << 0xb | uVar2 >> 5) - (~uVar8 & uVar6) & 0xffff) - (uVar8 & uVar4)
              & 0xffff) - (uint)puVar1[3] & 0xffff;
      uVar3 = ((((uVar8 & 7) << 0xd | uVar8 >> 3) - (~uVar4 & uVar2) & 0xffff) - (uVar6 & uVar4) &
              0xffff) - (uint)puVar1[2];
      uVar8 = uVar3 & 0xffff;
      uVar11 = ((((uVar4 & 3) << 0xe | uVar4 >> 2) - (~uVar6 & uVar8) & 0xffff) - (uVar6 & uVar2) &
               0xffff) - (uint)puVar1[1];
      uVar4 = uVar11 & 0xffff;
      uVar10 = ((((uVar6 & 1) << 0xf | uVar6 >> 1) - (~uVar2 & uVar4) & 0xffff) - (uVar8 & uVar2) &
               0xffff) - (uint)*puVar1;
      uVar6 = uVar10 & 0xffff;
      iVar9 = iVar9 + -1;
      puVar1 = puVar1 + -4;
    } while (iVar9 != 0);
    uVar5 = uVar2 - param_3[uVar3 & 0x3f] & 0xffff;
    uVar8 = uVar8 - param_3[uVar11 & 0x3f] & 0xffff;
    uVar6 = uVar6 - param_3[uVar2 - param_3[uVar3 & 0x3f] & 0x3f] & 0xffff;
    uVar2 = uVar4 - param_3[uVar10 & 0x3f] & 0xffff;
    iVar9 = 6;
    do {
      uVar5 = ((((uVar5 & 0x1f) << 0xb | uVar5 >> 5) - (~uVar8 & uVar6) & 0xffff) - (uVar8 & uVar2)
              & 0xffff) - (uint)puVar1[3] & 0xffff;
      uVar10 = ((((uVar8 & 7) << 0xd | uVar8 >> 3) - (~uVar2 & uVar5) & 0xffff) - (uVar6 & uVar2) &
               0xffff) - (uint)puVar1[2];
      uVar8 = uVar10 & 0xffff;
      uVar11 = ((((uVar2 & 3) << 0xe | uVar2 >> 2) - (~uVar6 & uVar8) & 0xffff) - (uVar6 & uVar5) &
               0xffff) - (uint)puVar1[1];
      uVar2 = uVar11 & 0xffff;
      uVar4 = ((((uVar6 & 1) << 0xf | uVar6 >> 1) - (~uVar5 & uVar2) & 0xffff) - (uVar8 & uVar5) &
              0xffff) - (uint)*puVar1;
      uVar6 = uVar4 & 0xffff;
      iVar9 = iVar9 + -1;
      puVar1 = puVar1 + -4;
    } while (iVar9 != 0);
    uVar3 = uVar5 - param_3[uVar10 & 0x3f] & 0xffff;
    uVar8 = uVar8 - param_3[uVar11 & 0x3f] & 0xffff;
    uVar2 = uVar2 - param_3[uVar4 & 0x3f] & 0xffff;
    uVar4 = uVar6 - param_3[uVar5 - param_3[uVar10 & 0x3f] & 0x3f] & 0xffff;
    iVar9 = 5;
    do {
      uVar3 = ((((uVar3 & 0x1f) << 0xb | uVar3 >> 5) - (~uVar8 & uVar4) & 0xffff) - (uVar8 & uVar2)
              & 0xffff) - (uint)puVar1[3] & 0xffff;
      uVar8 = ((((uVar8 & 7) << 0xd | uVar8 >> 3) - (~uVar2 & uVar3) & 0xffff) - (uVar4 & uVar2) &
              0xffff) - (uint)puVar1[2] & 0xffff;
      uVar2 = ((((uVar2 & 3) << 0xe | uVar2 >> 2) - (~uVar4 & uVar8) & 0xffff) - (uVar4 & uVar3) &
              0xffff) - (uint)puVar1[1] & 0xffff;
      uVar4 = ((((uVar4 & 1) << 0xf | uVar4 >> 1) - (~uVar3 & uVar2) & 0xffff) - (uVar8 & uVar3) &
              0xffff) - (uint)*puVar1 & 0xffff;
      iVar9 = iVar9 + -1;
      puVar1 = puVar1 + -4;
    } while (iVar9 != 0);
  }
  else {
    iVar9 = 5;
    puVar1 = param_3;
    do {
      uVar6 = (~uVar2 & uVar4) + (uVar8 & uVar2) + (uint)*puVar1 + uVar6;
      uVar6 = (uVar6 & 0x7fff) << 1 | (uVar6 & 0xffff) >> 0xf;
      uVar4 = (~uVar6 & uVar8) + (uVar6 & uVar2) + (uint)puVar1[1] + uVar4;
      uVar4 = (uVar4 & 0x3fff) << 2 | (uVar4 & 0xffff) >> 0xe;
      uVar8 = (~uVar4 & uVar2) + (uVar6 & uVar4) + (uint)puVar1[2] + uVar8;
      uVar8 = (uVar8 & 0x1fff) << 3 | (uVar8 & 0xffff) >> 0xd;
      uVar2 = (~uVar8 & uVar6) + (uVar8 & uVar4) + (uint)puVar1[3] + uVar2;
      uVar10 = (uVar2 & 0x7ff) << 5;
      uVar11 = (uVar2 & 0xffff) >> 0xb;
      uVar2 = uVar10 | uVar11;
      iVar9 = iVar9 + -1;
      puVar1 = puVar1 + 4;
    } while (iVar9 != 0);
    uVar3 = param_3[uVar10 & 0x3f | uVar11] + uVar6 & 0xffff;
    uVar7 = param_3[param_3[uVar10 & 0x3f | uVar11] + uVar6 & 0x3f] + uVar4 & 0xffff;
    uVar5 = param_3[param_3[param_3[uVar10 & 0x3f | uVar11] + uVar6 & 0x3f] + uVar4 & 0x3f] + uVar8
            & 0xffff;
    uVar6 = param_3[param_3[param_3[param_3[uVar10 & 0x3f | uVar11] + uVar6 & 0x3f] + uVar4 & 0x3f]
                    + uVar8 & 0x3f] + uVar2 & 0xffff;
    iVar9 = 6;
    do {
      uVar3 = (~uVar6 & uVar7) + (uVar5 & uVar6) + (uint)*puVar1 + uVar3;
      uVar3 = (uVar3 & 0x7fff) << 1 | (uVar3 & 0xffff) >> 0xf;
      uVar7 = (~uVar3 & uVar5) + (uVar3 & uVar6) + (uint)puVar1[1] + uVar7;
      uVar7 = (uVar7 & 0x3fff) << 2 | (uVar7 & 0xffff) >> 0xe;
      uVar5 = (~uVar7 & uVar6) + (uVar3 & uVar7) + (uint)puVar1[2] + uVar5;
      uVar5 = (uVar5 & 0x1fff) << 3 | (uVar5 & 0xffff) >> 0xd;
      uVar6 = (~uVar5 & uVar3) + (uVar5 & uVar7) + (uint)puVar1[3] + uVar6;
      uVar10 = (uVar6 & 0x7ff) << 5;
      uVar11 = (uVar6 & 0xffff) >> 0xb;
      uVar6 = uVar10 | uVar11;
      iVar9 = iVar9 + -1;
      puVar1 = puVar1 + 4;
    } while (iVar9 != 0);
    uVar4 = param_3[uVar10 & 0x3f | uVar11] + uVar3 & 0xffff;
    uVar2 = param_3[param_3[uVar10 & 0x3f | uVar11] + uVar3 & 0x3f] + uVar7 & 0xffff;
    uVar8 = param_3[param_3[param_3[uVar10 & 0x3f | uVar11] + uVar3 & 0x3f] + uVar7 & 0x3f] + uVar5
            & 0xffff;
    uVar3 = param_3[param_3[param_3[param_3[uVar10 & 0x3f | uVar11] + uVar3 & 0x3f] + uVar7 & 0x3f]
                    + uVar5 & 0x3f] + uVar6 & 0xffff;
    iVar9 = 5;
    do {
      uVar4 = (~uVar3 & uVar2) + (uVar8 & uVar3) + (uint)*puVar1 + uVar4;
      uVar4 = (uVar4 & 0x7fff) << 1 | (uVar4 & 0xffff) >> 0xf;
      uVar2 = (~uVar4 & uVar8) + (uVar4 & uVar3) + (uint)puVar1[1] + uVar2;
      uVar2 = (uVar2 & 0x3fff) << 2 | (uVar2 & 0xffff) >> 0xe;
      uVar8 = (~uVar2 & uVar3) + (uVar4 & uVar2) + (uint)puVar1[2] + uVar8;
      uVar8 = (uVar8 & 0x1fff) << 3 | (uVar8 & 0xffff) >> 0xd;
      uVar3 = (~uVar8 & uVar4) + (uVar8 & uVar2) + (uint)puVar1[3] + uVar3;
      uVar3 = (uVar3 & 0x7ff) << 5 | (uVar3 & 0xffff) >> 0xb;
      iVar9 = iVar9 + -1;
      puVar1 = puVar1 + 4;
    } while (iVar9 != 0);
  }
  *param_1 = (char)uVar4;
  param_1[1] = (char)(uVar4 >> 8);
  param_1[2] = (char)uVar2;
  param_1[3] = (char)(uVar2 >> 8);
  param_1[4] = (char)uVar8;
  param_1[5] = (char)(uVar8 >> 8);
  param_1[6] = (char)uVar3;
  param_1[7] = (char)(uVar3 >> 8);
  return;
}



/* 1001df58 des */

/* Boundary evidence: original MIPS .pdata 1001df58..1001e4cb. Semantic name remains unreviewed. */

void des(uint *param_1,uint *param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  
                    /* 0x1df58  52  des */
  uVar1 = *param_2 >> 0x1c | *param_2 << 4;
  uVar2 = (param_2[1] ^ uVar1) & 0xf0f0f0f0;
  uVar1 = uVar1 ^ uVar2;
  uVar2 = param_2[1] ^ uVar2;
  uVar2 = uVar2 << 0x14 | uVar2 >> 0xc;
  uVar3 = (uVar1 ^ uVar2) & 0xfff0000f;
  uVar2 = uVar3 ^ uVar2;
  uVar3 = uVar3 ^ uVar1;
  uVar1 = uVar2 >> 0x12 | uVar2 << 0xe;
  uVar2 = (uVar1 ^ uVar3) & 0x33333333;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar3 << 0x16 | uVar3 >> 10;
  uVar2 = (uVar3 ^ uVar1) & 0x3fc03fc;
  uVar3 = uVar2 ^ uVar3;
  uVar2 = uVar2 ^ uVar1;
  uVar1 = uVar3 >> 0x17 | uVar3 << 9;
  uVar3 = (uVar2 ^ uVar1) & 0xaaaaaaaa;
  uVar2 = uVar2 ^ uVar3;
  uVar2 = uVar2 >> 0x1f | uVar2 << 1;
  uVar1 = uVar1 ^ uVar3;
  iVar6 = 8;
  if (param_4 == 0) {
    puVar4 = (uint *)(param_3 + 0x70);
    do {
      uVar5 = (puVar4[3] ^ uVar1) >> 4;
      uVar3 = puVar4[2] ^ uVar1;
      uVar2 = *(uint *)(&DAT_10003348 + (((puVar4[3] ^ uVar1) << 0x1c | uVar5 & 0xfc000000) >> 0x18)
                       ) ^ *(uint *)(&DAT_10003148 + ((uVar5 & 0xfc0000) >> 0x10)) ^
              *(uint *)(&DAT_10002f48 + ((uVar5 & 0xfc00) >> 8)) ^
              *(uint *)(&DAT_10003248 + (uVar3 >> 0x18 & 0xfc)) ^
              *(uint *)(&DAT_10003048 + (uVar3 >> 0x10 & 0xfc)) ^
              *(uint *)(&DAT_10002e48 + (uVar3 >> 8 & 0xfc)) ^
              *(uint *)(&DAT_10002d48 + (uVar5 & 0xfc)) ^ *(uint *)(&DAT_10002c48 + (uVar3 & 0xfc))
              ^ uVar2;
      uVar5 = (puVar4[1] ^ uVar2) >> 4;
      uVar3 = *puVar4 ^ uVar2;
      uVar1 = *(uint *)(&DAT_10003348 + (((puVar4[1] ^ uVar2) << 0x1c | uVar5 & 0xfc000000) >> 0x18)
                       ) ^ *(uint *)(&DAT_10003148 + ((uVar5 & 0xfc0000) >> 0x10)) ^
              *(uint *)(&DAT_10002f48 + ((uVar5 & 0xfc00) >> 8)) ^
              *(uint *)(&DAT_10003248 + (uVar3 >> 0x18 & 0xfc)) ^
              *(uint *)(&DAT_10003048 + (uVar3 >> 0x10 & 0xfc)) ^
              *(uint *)(&DAT_10002e48 + (uVar3 >> 8 & 0xfc)) ^
              *(uint *)(&DAT_10002d48 + (uVar5 & 0xfc)) ^ *(uint *)(&DAT_10002c48 + (uVar3 & 0xfc))
              ^ uVar1;
      iVar6 = iVar6 + -1;
      puVar4 = puVar4 + -4;
    } while (iVar6 != 0);
  }
  else {
    puVar4 = (uint *)(param_3 + 8);
    do {
      uVar5 = (puVar4[-1] ^ uVar1) >> 4;
      uVar3 = puVar4[-2] ^ uVar1;
      uVar2 = *(uint *)(&DAT_10003348 +
                       (((puVar4[-1] ^ uVar1) << 0x1c | uVar5 & 0xfc000000) >> 0x18)) ^
              *(uint *)(&DAT_10003148 + ((uVar5 & 0xfc0000) >> 0x10)) ^
              *(uint *)(&DAT_10002f48 + ((uVar5 & 0xfc00) >> 8)) ^
              *(uint *)(&DAT_10003248 + (uVar3 >> 0x18 & 0xfc)) ^
              *(uint *)(&DAT_10003048 + (uVar3 >> 0x10 & 0xfc)) ^
              *(uint *)(&DAT_10002e48 + (uVar3 >> 8 & 0xfc)) ^
              *(uint *)(&DAT_10002d48 + (uVar5 & 0xfc)) ^ *(uint *)(&DAT_10002c48 + (uVar3 & 0xfc))
              ^ uVar2;
      uVar3 = *puVar4 ^ uVar2;
      uVar5 = (puVar4[1] ^ uVar2) >> 4;
      uVar1 = *(uint *)(&DAT_10003348 + (((puVar4[1] ^ uVar2) << 0x1c | uVar5 & 0xfc000000) >> 0x18)
                       ) ^ *(uint *)(&DAT_10003148 + ((uVar5 & 0xfc0000) >> 0x10)) ^
              *(uint *)(&DAT_10002f48 + ((uVar5 & 0xfc00) >> 8)) ^
              *(uint *)(&DAT_10003248 + (uVar3 >> 0x18 & 0xfc)) ^
              *(uint *)(&DAT_10003048 + (uVar3 >> 0x10 & 0xfc)) ^
              *(uint *)(&DAT_10002e48 + (uVar3 >> 8 & 0xfc)) ^
              *(uint *)(&DAT_10002d48 + (uVar5 & 0xfc)) ^ *(uint *)(&DAT_10002c48 + (uVar3 & 0xfc))
              ^ uVar1;
      iVar6 = iVar6 + -1;
      puVar4 = puVar4 + 4;
    } while (iVar6 != 0);
  }
  uVar1 = uVar1 << 0x1f | uVar1 >> 1;
  uVar3 = (uVar2 ^ uVar1) & 0xaaaaaaaa;
  uVar2 = uVar3 ^ uVar2;
  uVar3 = uVar3 ^ uVar1;
  uVar2 = uVar2 << 0x17 | uVar2 >> 9;
  uVar1 = (uVar2 ^ uVar3) & 0x3fc03fc;
  uVar3 = uVar3 ^ uVar1;
  uVar2 = uVar2 ^ uVar1;
  uVar1 = uVar2 >> 0x16 | uVar2 << 10;
  uVar2 = (uVar3 ^ uVar1) & 0x33333333;
  uVar3 = uVar2 ^ uVar3;
  uVar2 = uVar2 ^ uVar1;
  uVar1 = uVar3 << 0x12 | uVar3 >> 0xe;
  uVar3 = (uVar2 ^ uVar1) & 0xfff0000f;
  uVar1 = uVar1 ^ uVar3;
  uVar2 = uVar2 ^ uVar3;
  uVar1 = uVar1 >> 0x14 | uVar1 << 0xc;
  uVar3 = (uVar1 ^ uVar2) & 0xf0f0f0f0;
  *param_1 = uVar2 << 0x1c | (uVar3 ^ uVar2) >> 4;
  param_1[1] = uVar3 ^ uVar1;
  return;
}



/* 1001e4cc tripledes */

/* Boundary evidence: original MIPS .pdata 1001e4cc..1001e563. Semantic name remains unreviewed. */

void tripledes(uint *param_1,uint *param_2,int param_3,int param_4)

{
  uint auStack_20 [2];
  uint auStack_18 [2];
  
                    /* 0x1e4cc  56  tripledes */
  if (param_4 != 1) {
    des(auStack_20,param_2,param_3 + 0x100,0);
    des(auStack_18,auStack_20,param_3 + 0x80,1);
  }
  else {
    des(auStack_20,param_2,param_3,1);
    des(auStack_18,auStack_20,param_3 + 0x80,0);
    param_3 = param_3 + 0x100;
  }
  des(param_1,auStack_18,param_3,(uint)(param_4 == 1));
  return;
}



/* 1001e564 deskey */

/* Boundary evidence: original MIPS .pdata 1001e564..1001e883. Semantic name remains unreviewed. */

void deskey(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
                    /* 0x1e564  53  deskey */
  uVar5 = (param_2[1] >> 4 ^ *param_2) & 0xf0f0f0f;
  uVar1 = uVar5 ^ *param_2;
  uVar4 = (uVar1 << 0x12 ^ uVar1) & 0xcccc0000;
  uVar5 = uVar5 << 4 ^ param_2[1];
  uVar1 = uVar4 >> 0x12 ^ uVar4 ^ uVar1;
  uVar4 = (uVar5 << 0x12 ^ uVar5) & 0xcccc0000;
  uVar5 = uVar4 >> 0x12 ^ uVar4 ^ uVar5;
  uVar4 = (uVar5 >> 1 ^ uVar1) & 0x55555555;
  uVar1 = uVar4 ^ uVar1;
  uVar5 = uVar4 << 1 ^ uVar5;
  uVar4 = (uVar1 >> 8 ^ uVar5) & 0xff00ff;
  uVar5 = uVar4 ^ uVar5;
  uVar1 = uVar4 << 8 ^ uVar1;
  uVar4 = (uVar5 >> 1 ^ uVar1) & 0x55555555;
  uVar1 = uVar4 ^ uVar1;
  uVar5 = uVar4 << 1 ^ uVar5;
  uVar4 = uVar1 & 0xfffffff;
  uVar1 = (uVar5 >> 0xc & 0xff0 | uVar1 & 0xf0000000) >> 4 | (uVar5 & 0xff) << 0x10 | uVar5 & 0xff00
  ;
  uVar5 = 0;
  do {
    if ((&DAT_10002c38)[uVar5] == '\0') {
      uVar7 = uVar1 << 0x1b;
      uVar3 = uVar4 << 0x1b;
      uVar6 = uVar4 >> 1;
      uVar2 = uVar1 >> 1;
    }
    else {
      uVar7 = uVar1 << 0x1a;
      uVar3 = uVar4 << 0x1a;
      uVar6 = uVar4 >> 2;
      uVar2 = uVar1 >> 2;
    }
    uVar4 = uVar3 & 0xfffffff | uVar6;
    uVar1 = uVar7 & 0xfffffff | uVar2;
    uVar3 = *(uint *)(&DAT_10003748 +
                     ((((uVar3 & 0xfffffff | uVar6 & 0xe000000) >> 1 | uVar6 & 0xc00000) >> 1 |
                      uVar6 & 0x100000) >> 0x14) * 4) |
            *(uint *)(&DAT_10003648 + ((uVar6 & 0x1e000 | (uVar6 & 0xc0000) >> 1) >> 0xd) * 4) |
            *(uint *)(&DAT_10003548 + (((uVar6 & 0x1e00) >> 1 | uVar6 & 0xc0) >> 6) * 4) |
            *(uint *)(&DAT_10003448 + (uVar6 & 0x3f) * 4);
    uVar2 = *(uint *)(&DAT_10003948 + (((uVar2 & 0x3c00) >> 1 | uVar2 & 0x180) >> 7) * 4) |
            *(uint *)(&DAT_10003b48 +
                     (((uVar7 & 0xfffffff | uVar2 & 0xc000000) >> 1 | uVar2 & 0x1e00000) >> 0x15) *
                     4) | *(uint *)(&DAT_10003a48 + ((uVar2 & 0x1f8000) >> 0xf) * 4) |
            *(uint *)(&DAT_10003848 + (uVar2 & 0x3f) * 4);
    *param_1 = (uVar2 & 0xffff) >> 0xe | (uVar3 & 0xffff | uVar2 << 0x10) << 2;
    uVar5 = uVar5 + 1;
    param_1[1] = uVar2 >> 0x1a | (uVar3 >> 0x10 | uVar2 & 0xffff0000) << 6;
    param_1 = param_1 + 2;
  } while (uVar5 < 0x10);
  return;
}



/* 1001e884 FUN_1001e884 */

void FUN_1001e884(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      bVar1 = *(byte *)(uVar2 + param_1);
      if (((uint)(byte)(&DAT_1002da04)[bVar1 >> 4] + (uint)(byte)(&DAT_1002da04)[bVar1 & 0xf]) % 2
          == 0) {
        *(byte *)(uVar2 + param_1) = bVar1 ^ 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}



/* 1001e8ec FUN_1001e8ec */

/* Boundary evidence: original MIPS .pdata 1001e8ec..1001e93f. Semantic name remains unreviewed. */

void FUN_1001e8ec(uint *param_1,uint *param_2)

{
  deskey(param_1,param_2);
  deskey(param_1 + 0x20,param_2 + 2);
  memcpy(param_1 + 0x40,param_1,0x80);
  return;
}



/* 1001e940 tripledes3key */

/* Boundary evidence: original MIPS .pdata 1001e940..1001e98f. Semantic name remains unreviewed. */

void tripledes3key(uint *param_1,uint *param_2)

{
                    /* 0x1e940  57  tripledes3key */
  deskey(param_1,param_2);
  deskey(param_1 + 0x20,param_2 + 2);
  deskey(param_1 + 0x40,param_2 + 4);
  return;
}



/* 1001e990 rc4_key */

void rc4_key(int *param_1,uint param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
                    /* 0x1e990  55  rc4_key */
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



/* 1001ea24 rc4 */

void rc4(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
                    /* 0x1ea24  54  rc4 */
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



/* 1001ea90 FUN_1001ea90 */

void FUN_1001ea90(int param_1,int param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = 0;
  if (param_4 != 0) {
    iVar6 = param_2 - (int)param_3;
    iVar3 = param_1 - (int)param_3;
    do {
      uVar4 = *(uint *)(iVar6 + (int)param_3);
      uVar5 = uVar4 - uVar1;
      uVar2 = *param_3;
      *(uint *)(iVar3 + (int)param_3) = uVar5 - uVar2;
      uVar1 = -(-(uint)(uVar5 < uVar2) - (uint)(uVar4 < uVar1));
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return;
}



/* 1001eae8 FUN_1001eae8 */

void FUN_1001eae8(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = 0;
  if (param_4 != 0) {
    iVar6 = param_2 - (int)param_3;
    iVar3 = param_1 - (int)param_3;
    do {
      uVar4 = *(uint *)(iVar6 + (int)param_3);
      uVar5 = uVar4 + *param_3;
      uVar2 = uVar5 + iVar1;
      iVar1 = (uint)(uVar5 < uVar4) + (uint)(uVar2 < uVar5);
      *(uint *)(iVar3 + (int)param_3) = uVar2;
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return;
}



/* 1001eb40 FUN_1001eb40 */

/* Boundary evidence: original MIPS .pdata 1001eb40..1001ebe3. Semantic name remains unreviewed. */

uint FUN_1001eb40(undefined4 *param_1,uint param_2,void *param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_2 == 1) {
    memcpy(param_1,param_3,param_4 << 2);
  }
  else if (param_4 != 0) {
    iVar2 = (int)param_3 - (int)param_1;
    do {
      param_4 = param_4 + -1;
      lVar1 = (ulonglong)*(uint *)(iVar2 + (int)param_1) * (ulonglong)param_2 + (ulonglong)uVar3;
      uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
      *param_1 = (int)lVar1;
      param_1 = param_1 + 1;
    } while (param_4 != 0);
  }
  return uVar3;
}



/* 1001ebe4 FUN_1001ebe4 */

void FUN_1001ebe4(uint *param_1,uint param_2,int param_3,int param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (param_4 != 0) {
    iVar3 = param_3 - (int)param_1;
    do {
      param_4 = param_4 + -1;
      lVar1 = (ulonglong)*(uint *)(iVar3 + (int)param_1) * (ulonglong)param_2 + (ulonglong)uVar2 +
              (ulonglong)*param_1;
      *param_1 = (uint)lVar1;
      uVar2 = (uint)((ulonglong)lVar1 >> 0x20);
      param_1 = param_1 + 1;
    } while (param_4 != 0);
  }
  return;
}



/* 1001ec54 FUN_1001ec54 */

void FUN_1001ec54(uint *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  longlong lVar2;
  
  uVar3 = 0;
  if (param_4 != 0) {
    iVar6 = param_3 - (int)param_1;
    do {
      param_4 = param_4 + -1;
      lVar2 = (ulonglong)*(uint *)(iVar6 + (int)param_1) * (ulonglong)param_2;
      uVar1 = (uint)lVar2;
      uVar5 = *param_1;
      uVar4 = uVar5 - uVar1;
      *param_1 = uVar4 - uVar3;
      uVar3 = -((-(uint)(uVar5 < uVar1) - (int)((ulonglong)lVar2 >> 0x20)) - (uint)(uVar4 < uVar3));
      param_1 = param_1 + 1;
    } while (param_4 != 0);
  }
  return;
}



/* 1001eccc FUN_1001eccc */

void FUN_1001eccc(uint *param_1,uint *param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar2 = *param_2;
    param_2 = param_2 + 1;
    lVar1 = (ulonglong)uVar2 * (ulonglong)uVar2 + (ulonglong)*param_1 + (ulonglong)uVar3;
    uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
    *param_1 = (uint)lVar1;
    uVar2 = uVar3 + param_1[1];
    uVar3 = (uint)(uVar2 < uVar3);
    param_1[1] = uVar2;
    param_1 = param_1 + 2;
  }
  return;
}



/* 1001ed64 FUN_1001ed64 */

void FUN_1001ed64(undefined4 *param_1)

{
  *param_1 = 0x6a09e667;
  param_1[1] = 0xbb67ae85;
  param_1[2] = 0x3c6ef372;
  param_1[3] = 0xa54ff53a;
  param_1[4] = 0x510e527f;
  param_1[5] = 0x9b05688c;
  param_1[6] = 0x1f83d9ab;
  param_1[7] = 0x5be0cd19;
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}



/* 1001edd0 FUN_1001edd0 */

/* Boundary evidence: original MIPS .pdata 1001edd0..1001ff8f. Semantic name remains unreviewed. */

void FUN_1001edd0(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  uint local_68 [16];
  
  puVar8 = local_68;
  puVar13 = local_68;
  puVar1 = (uint *)(param_2 + 8);
  iVar2 = 4;
  do {
    uVar4 = puVar1[-2];
    uVar5 = puVar1[-1];
    uVar6 = *puVar1;
    *puVar8 = (uVar4 & 0xff0000 | uVar4 >> 0x10) >> 8 | (uVar4 << 0x10 | uVar4 & 0xff00) << 8;
    uVar4 = puVar1[1];
    puVar8[1] = (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8 | (uVar5 << 0x10 | uVar5 & 0xff00) << 8;
    puVar8[2] = (uVar6 & 0xff0000 | uVar6 >> 0x10) >> 8 | (uVar6 << 0x10 | uVar6 & 0xff00) << 8;
    puVar8[3] = (uVar4 & 0xff0000 | uVar4 >> 0x10) >> 8 | (uVar4 << 0x10 | uVar4 & 0xff00) << 8;
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + -1;
    puVar8 = puVar8 + 4;
  } while (iVar2 != 0);
  piVar18 = &DAT_10003ec8;
  uVar12 = *param_1;
  uVar10 = param_1[1];
  uVar6 = param_1[2];
  uVar5 = param_1[3];
  uVar11 = param_1[4];
  uVar3 = param_1[5];
  uVar7 = param_1[6];
  uVar9 = param_1[7];
  uVar4 = 0;
  do {
    uVar17 = uVar4;
    iVar2 = ((uVar11 << 7 | uVar11 >> 0x19) ^ (uVar11 << 0x15 | uVar11 >> 0xb) ^
            (uVar11 << 0x1a | uVar11 >> 6)) + (~uVar11 & uVar7 ^ uVar3 & uVar11) + *puVar13 +
            *piVar18 + uVar9;
    uVar5 = iVar2 + uVar5;
    uVar9 = ((uVar12 << 10 | uVar12 >> 0x16) ^ (uVar12 << 0x13 | uVar12 >> 0xd) ^
            (uVar12 << 0x1e | uVar12 >> 2)) + ((uVar10 ^ uVar12) & uVar6 ^ uVar10 & uVar12) + iVar2;
    iVar2 = ((uVar5 * 0x80 | uVar5 >> 0x19) ^ (uVar5 * 0x200000 | uVar5 >> 0xb) ^
            (uVar5 * 0x4000000 | uVar5 >> 6)) + (~uVar5 & uVar3 ^ uVar11 & uVar5) + puVar13[1] +
            piVar18[1] + uVar7;
    uVar6 = iVar2 + uVar6;
    uVar7 = ((uVar9 * 0x400 | uVar9 >> 0x16) ^ (uVar9 * 0x80000 | uVar9 >> 0xd) ^
            (uVar9 * 0x40000000 | uVar9 >> 2)) + ((uVar10 ^ uVar12) & uVar9 ^ uVar10 & uVar12) +
            iVar2;
    iVar2 = ((uVar6 * 0x80 | uVar6 >> 0x19) ^ (uVar6 * 0x200000 | uVar6 >> 0xb) ^
            (uVar6 * 0x4000000 | uVar6 >> 6)) + (~uVar6 & uVar11 ^ uVar5 & uVar6) + puVar13[2] +
            piVar18[2] + uVar3;
    uVar10 = iVar2 + uVar10;
    uVar3 = ((uVar7 * 0x400 | uVar7 >> 0x16) ^ (uVar7 * 0x80000 | uVar7 >> 0xd) ^
            (uVar7 * 0x40000000 | uVar7 >> 2)) + ((uVar7 ^ uVar12) & uVar9 ^ uVar7 & uVar12) + iVar2
    ;
    iVar2 = ((uVar10 * 0x80 | uVar10 >> 0x19) ^ (uVar10 * 0x200000 | uVar10 >> 0xb) ^
            (uVar10 * 0x4000000 | uVar10 >> 6)) + (~uVar10 & uVar5 ^ uVar6 & uVar10) + puVar13[3] +
            piVar18[3] + uVar11;
    uVar12 = iVar2 + uVar12;
    uVar11 = ((uVar3 * 0x400 | uVar3 >> 0x16) ^ (uVar3 * 0x80000 | uVar3 >> 0xd) ^
             (uVar3 * 0x40000000 | uVar3 >> 2)) + ((uVar7 ^ uVar3) & uVar9 ^ uVar7 & uVar3) + iVar2;
    iVar2 = ((uVar12 * 0x80 | uVar12 >> 0x19) ^ (uVar12 * 0x200000 | uVar12 >> 0xb) ^
            (uVar12 * 0x4000000 | uVar12 >> 6)) + (~uVar12 & uVar6 ^ uVar10 & uVar12) + puVar13[4] +
            piVar18[4] + uVar5;
    uVar9 = iVar2 + uVar9;
    uVar5 = ((uVar11 * 0x400 | uVar11 >> 0x16) ^ (uVar11 * 0x80000 | uVar11 >> 0xd) ^
            (uVar11 * 0x40000000 | uVar11 >> 2)) + ((uVar3 ^ uVar11) & uVar7 ^ uVar3 & uVar11) +
            iVar2;
    iVar2 = ((uVar9 * 0x80 | uVar9 >> 0x19) ^ (uVar9 * 0x200000 | uVar9 >> 0xb) ^
            (uVar9 * 0x4000000 | uVar9 >> 6)) + (~uVar9 & uVar10 ^ uVar9 & uVar12) + puVar13[5] +
            piVar18[5] + uVar6;
    uVar7 = iVar2 + uVar7;
    uVar6 = ((uVar5 * 0x400 | uVar5 >> 0x16) ^ (uVar5 * 0x80000 | uVar5 >> 0xd) ^
            (uVar5 * 0x40000000 | uVar5 >> 2)) + ((uVar11 ^ uVar5) & uVar3 ^ uVar11 & uVar5) + iVar2
    ;
    iVar2 = ((uVar7 * 0x80 | uVar7 >> 0x19) ^ (uVar7 * 0x200000 | uVar7 >> 0xb) ^
            (uVar7 * 0x4000000 | uVar7 >> 6)) + (~uVar7 & uVar12 ^ uVar9 & uVar7) + puVar13[6] +
            piVar18[6] + uVar10;
    uVar3 = iVar2 + uVar3;
    uVar10 = ((uVar6 * 0x400 | uVar6 >> 0x16) ^ (uVar6 * 0x80000 | uVar6 >> 0xd) ^
             (uVar6 * 0x40000000 | uVar6 >> 2)) + ((uVar5 ^ uVar6) & uVar11 ^ uVar5 & uVar6) + iVar2
    ;
    iVar2 = ((uVar3 * 0x80 | uVar3 >> 0x19) ^ (uVar3 * 0x200000 | uVar3 >> 0xb) ^
            (uVar3 * 0x4000000 | uVar3 >> 6)) + (~uVar3 & uVar9 ^ uVar7 & uVar3) + puVar13[7] +
            piVar18[7] + uVar12;
    uVar11 = iVar2 + uVar11;
    uVar4 = uVar17 + 8;
    uVar12 = ((uVar10 * 0x400 | uVar10 >> 0x16) ^ (uVar10 * 0x80000 | uVar10 >> 0xd) ^
             (uVar10 * 0x40000000 | uVar10 >> 2)) + ((uVar6 ^ uVar10) & uVar5 ^ uVar6 & uVar10) +
             iVar2;
    puVar13 = puVar13 + 8;
    piVar18 = piVar18 + 8;
  } while ((int)uVar4 < 0x10);
  if (uVar4 < 0x40) {
    uVar16 = uVar17 + 6;
    uVar19 = uVar17 + 9;
    piVar18 = &DAT_10003ec8 + uVar4;
    do {
      uVar14 = local_68[uVar19 & 0xf];
      uVar15 = local_68[uVar16 & 0xf];
      uVar14 = ((uVar15 << 0xd | uVar15 >> 0x13) ^ (uVar15 << 0xf | uVar15 >> 0x11) ^ uVar15 >> 10)
               + ((uVar14 << 0xe | uVar14 >> 0x12) ^ (uVar14 << 0x19 | uVar14 >> 7) ^ uVar14 >> 3) +
               local_68[uVar17 + 1 & 0xf] + local_68[uVar4 & 0xf];
      local_68[uVar4 & 0xf] = uVar14;
      iVar2 = ((uVar11 << 7 | uVar11 >> 0x19) ^ (uVar11 << 0x15 | uVar11 >> 0xb) ^
              (uVar11 << 0x1a | uVar11 >> 6)) + (~uVar11 & uVar7 ^ uVar3 & uVar11) + uVar14 +
              *piVar18 + uVar9;
      uVar5 = iVar2 + uVar5;
      uVar9 = ((uVar12 << 10 | uVar12 >> 0x16) ^ (uVar12 << 0x13 | uVar12 >> 0xd) ^
              (uVar12 << 0x1e | uVar12 >> 2)) + ((uVar10 ^ uVar12) & uVar6 ^ uVar10 & uVar12) +
              iVar2;
      uVar14 = local_68[uVar19 + 1 & 0xf];
      uVar15 = local_68[uVar16 + 1 & 0xf];
      uVar14 = ((uVar15 << 0xd | uVar15 >> 0x13) ^ (uVar15 << 0xf | uVar15 >> 0x11) ^ uVar15 >> 10)
               + ((uVar14 << 0xe | uVar14 >> 0x12) ^ (uVar14 << 0x19 | uVar14 >> 7) ^ uVar14 >> 3) +
               local_68[uVar17 + 2 & 0xf] + local_68[uVar4 + 1 & 0xf];
      local_68[uVar4 + 1 & 0xf] = uVar14;
      iVar2 = ((uVar5 * 0x80 | uVar5 >> 0x19) ^ (uVar5 * 0x200000 | uVar5 >> 0xb) ^
              (uVar5 * 0x4000000 | uVar5 >> 6)) + (~uVar5 & uVar3 ^ uVar11 & uVar5) + uVar14 +
              piVar18[1] + uVar7;
      uVar6 = iVar2 + uVar6;
      uVar7 = ((uVar9 * 0x400 | uVar9 >> 0x16) ^ (uVar9 * 0x80000 | uVar9 >> 0xd) ^
              (uVar9 * 0x40000000 | uVar9 >> 2)) + ((uVar10 ^ uVar12) & uVar9 ^ uVar10 & uVar12) +
              iVar2;
      uVar14 = local_68[uVar19 + 2 & 0xf];
      uVar15 = local_68[uVar16 + 2 & 0xf];
      uVar14 = ((uVar15 << 0xd | uVar15 >> 0x13) ^ (uVar15 << 0xf | uVar15 >> 0x11) ^ uVar15 >> 10)
               + ((uVar14 << 0xe | uVar14 >> 0x12) ^ (uVar14 << 0x19 | uVar14 >> 7) ^ uVar14 >> 3) +
               local_68[uVar17 + 3 & 0xf] + local_68[uVar4 + 2 & 0xf];
      local_68[uVar4 + 2 & 0xf] = uVar14;
      iVar2 = ((uVar6 * 0x80 | uVar6 >> 0x19) ^ (uVar6 * 0x200000 | uVar6 >> 0xb) ^
              (uVar6 * 0x4000000 | uVar6 >> 6)) + (~uVar6 & uVar11 ^ uVar5 & uVar6) + uVar14 +
              piVar18[2] + uVar3;
      uVar10 = iVar2 + uVar10;
      uVar3 = ((uVar7 * 0x400 | uVar7 >> 0x16) ^ (uVar7 * 0x80000 | uVar7 >> 0xd) ^
              (uVar7 * 0x40000000 | uVar7 >> 2)) + ((uVar7 ^ uVar12) & uVar9 ^ uVar7 & uVar12) +
              iVar2;
      uVar14 = local_68[uVar19 + 3 & 0xf];
      uVar15 = local_68[uVar16 + 3 & 0xf];
      uVar14 = ((uVar15 << 0xd | uVar15 >> 0x13) ^ (uVar15 << 0xf | uVar15 >> 0x11) ^ uVar15 >> 10)
               + ((uVar14 << 0xe | uVar14 >> 0x12) ^ (uVar14 << 0x19 | uVar14 >> 7) ^ uVar14 >> 3) +
               local_68[uVar17 + 4 & 0xf] + local_68[uVar4 + 3 & 0xf];
      local_68[uVar4 + 3 & 0xf] = uVar14;
      iVar2 = ((uVar10 * 0x80 | uVar10 >> 0x19) ^ (uVar10 * 0x200000 | uVar10 >> 0xb) ^
              (uVar10 * 0x4000000 | uVar10 >> 6)) + (~uVar10 & uVar5 ^ uVar6 & uVar10) + uVar14 +
              piVar18[3] + uVar11;
      uVar12 = iVar2 + uVar12;
      uVar11 = ((uVar3 * 0x400 | uVar3 >> 0x16) ^ (uVar3 * 0x80000 | uVar3 >> 0xd) ^
               (uVar3 * 0x40000000 | uVar3 >> 2)) + ((uVar7 ^ uVar3) & uVar9 ^ uVar7 & uVar3) +
               iVar2;
      uVar14 = local_68[uVar19 + 4 & 0xf];
      uVar15 = local_68[uVar16 + 4 & 0xf];
      uVar14 = ((uVar15 << 0xd | uVar15 >> 0x13) ^ (uVar15 << 0xf | uVar15 >> 0x11) ^ uVar15 >> 10)
               + ((uVar14 << 0xe | uVar14 >> 0x12) ^ (uVar14 << 0x19 | uVar14 >> 7) ^ uVar14 >> 3) +
               local_68[uVar17 + 5 & 0xf] + local_68[uVar4 + 4 & 0xf];
      local_68[uVar4 + 4 & 0xf] = uVar14;
      iVar2 = ((uVar12 * 0x80 | uVar12 >> 0x19) ^ (uVar12 * 0x200000 | uVar12 >> 0xb) ^
              (uVar12 * 0x4000000 | uVar12 >> 6)) + (~uVar12 & uVar6 ^ uVar10 & uVar12) + uVar14 +
              piVar18[4] + uVar5;
      uVar9 = iVar2 + uVar9;
      uVar5 = ((uVar11 * 0x400 | uVar11 >> 0x16) ^ (uVar11 * 0x80000 | uVar11 >> 0xd) ^
              (uVar11 * 0x40000000 | uVar11 >> 2)) + ((uVar3 ^ uVar11) & uVar7 ^ uVar3 & uVar11) +
              iVar2;
      uVar14 = local_68[uVar19 + 5 & 0xf];
      uVar15 = local_68[uVar16 + 5 & 0xf];
      uVar14 = ((uVar15 << 0xd | uVar15 >> 0x13) ^ (uVar15 << 0xf | uVar15 >> 0x11) ^ uVar15 >> 10)
               + ((uVar14 << 0xe | uVar14 >> 0x12) ^ (uVar14 << 0x19 | uVar14 >> 7) ^ uVar14 >> 3) +
               local_68[uVar17 + 6 & 0xf] + local_68[uVar4 + 5 & 0xf];
      local_68[uVar4 + 5 & 0xf] = uVar14;
      iVar2 = ((uVar9 * 0x80 | uVar9 >> 0x19) ^ (uVar9 * 0x200000 | uVar9 >> 0xb) ^
              (uVar9 * 0x4000000 | uVar9 >> 6)) + (~uVar9 & uVar10 ^ uVar9 & uVar12) + uVar14 +
              piVar18[5] + uVar6;
      uVar7 = iVar2 + uVar7;
      uVar6 = ((uVar5 * 0x400 | uVar5 >> 0x16) ^ (uVar5 * 0x80000 | uVar5 >> 0xd) ^
              (uVar5 * 0x40000000 | uVar5 >> 2)) + ((uVar11 ^ uVar5) & uVar3 ^ uVar11 & uVar5) +
              iVar2;
      uVar14 = local_68[uVar19 + 6 & 0xf];
      uVar15 = local_68[uVar16 + 6 & 0xf];
      uVar14 = ((uVar15 << 0xd | uVar15 >> 0x13) ^ (uVar15 << 0xf | uVar15 >> 0x11) ^ uVar15 >> 10)
               + ((uVar14 << 0xe | uVar14 >> 0x12) ^ (uVar14 << 0x19 | uVar14 >> 7) ^ uVar14 >> 3) +
               local_68[uVar17 + 7 & 0xf] + local_68[uVar4 + 6 & 0xf];
      local_68[uVar4 + 6 & 0xf] = uVar14;
      iVar2 = ((uVar7 * 0x80 | uVar7 >> 0x19) ^ (uVar7 * 0x200000 | uVar7 >> 0xb) ^
              (uVar7 * 0x4000000 | uVar7 >> 6)) + (~uVar7 & uVar12 ^ uVar9 & uVar7) + uVar14 +
              piVar18[6] + uVar10;
      uVar3 = iVar2 + uVar3;
      uVar10 = ((uVar6 * 0x400 | uVar6 >> 0x16) ^ (uVar6 * 0x80000 | uVar6 >> 0xd) ^
               (uVar6 * 0x40000000 | uVar6 >> 2)) + ((uVar5 ^ uVar6) & uVar11 ^ uVar5 & uVar6) +
               iVar2;
      uVar14 = local_68[uVar19 + 7 & 0xf];
      uVar15 = local_68[uVar16 + 7 & 0xf];
      uVar17 = uVar17 + 8;
      uVar14 = ((uVar15 << 0xd | uVar15 >> 0x13) ^ (uVar15 << 0xf | uVar15 >> 0x11) ^ uVar15 >> 10)
               + ((uVar14 << 0xe | uVar14 >> 0x12) ^ (uVar14 << 0x19 | uVar14 >> 7) ^ uVar14 >> 3) +
               local_68[uVar17 & 0xf] + local_68[uVar4 + 7 & 0xf];
      local_68[uVar4 + 7 & 0xf] = uVar14;
      iVar2 = ((uVar3 * 0x80 | uVar3 >> 0x19) ^ (uVar3 * 0x200000 | uVar3 >> 0xb) ^
              (uVar3 * 0x4000000 | uVar3 >> 6)) + (~uVar3 & uVar9 ^ uVar7 & uVar3) + uVar14 +
              piVar18[7] + uVar12;
      uVar4 = uVar4 + 8;
      uVar11 = iVar2 + uVar11;
      uVar12 = ((uVar10 * 0x400 | uVar10 >> 0x16) ^ (uVar10 * 0x80000 | uVar10 >> 0xd) ^
               (uVar10 * 0x40000000 | uVar10 >> 2)) + ((uVar6 ^ uVar10) & uVar5 ^ uVar6 & uVar10) +
               iVar2;
      uVar19 = uVar19 + 8;
      uVar16 = uVar16 + 8;
      piVar18 = piVar18 + 8;
    } while (uVar4 < 0x40);
  }
  param_1[6] = param_1[6] + uVar7;
  *param_1 = *param_1 + uVar12;
  param_1[1] = param_1[1] + uVar10;
  param_1[2] = param_1[2] + uVar6;
  param_1[3] = param_1[3] + uVar5;
  param_1[4] = param_1[4] + uVar11;
  param_1[5] = param_1[5] + uVar3;
  param_1[7] = param_1[7] + uVar9;
  return;
}



/* 1001ff90 FUN_1001ff90 */

/* Boundary evidence: original MIPS .pdata 1001ff90..100200eb. Semantic name remains unreviewed. */

void FUN_1001ff90(uint *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1[9] & 0x3f;
  uVar1 = param_1[9] + param_3;
  param_1[9] = uVar1;
  if (uVar1 < param_3) {
    param_1[8] = param_1[8] + 1;
  }
  if ((uVar2 != 0) && (0x3f < uVar2 + param_3)) {
    memcpy((void *)((int)param_1 + uVar2 + 0x28),param_2,0x40 - uVar2);
    param_2 = (void *)((int)param_2 + (0x40 - uVar2));
    param_3 = (uVar2 + param_3) - 0x40;
    FUN_1001edd0(param_1,(int)(param_1 + 10));
    uVar2 = 0;
  }
  if (((uint)param_2 & 3) == 0) {
    if (0x3f < param_3) {
      uVar1 = param_3 >> 6;
      do {
        FUN_1001edd0(param_1,(int)param_2);
        param_2 = (void *)((int)param_2 + 0x40);
        uVar1 = uVar1 - 1;
        param_3 = param_3 - 0x40;
      } while (uVar1 != 0);
    }
  }
  else if (0x3f < param_3) {
    uVar1 = param_3 >> 6;
    do {
      memcpy(param_1 + 10,param_2,0x40);
      FUN_1001edd0(param_1,(int)(param_1 + 10));
      param_2 = (void *)((int)param_2 + 0x40);
      uVar1 = uVar1 - 1;
      param_3 = param_3 - 0x40;
    } while (uVar1 != 0);
  }
  if (param_3 != 0) {
    memcpy((void *)((int)param_1 + uVar2 + 0x28),param_2,param_3);
  }
  return;
}



/* 100200ec FUN_100200ec */

/* Boundary evidence: original MIPS .pdata 100200ec..10020227. Semantic name remains unreviewed. */

void FUN_100200ec(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_68;
  int local_64;
  undefined1 local_60 [72];
  
  uVar1 = param_1[9];
  uVar2 = -(uVar1 & 0x3f) + 0x40;
  if (uVar2 < 9) {
    uVar2 = -(uVar1 & 0x3f) + 0x80;
  }
  memset(local_60,0,uVar2 - 8);
  local_68 = param_1[8] << 3 | uVar1 >> 0x1d;
  local_60[0] = 0x80;
  local_64 = uVar1 << 3;
  FUN_10026938((int)&local_68 + uVar2,(int)&local_68,2);
  FUN_1001ff90(param_1,local_60,uVar2);
  FUN_10026938(param_2,(int)param_1,8);
  *param_1 = 0x6a09e667;
  param_1[1] = 0xbb67ae85;
  param_1[2] = 0x3c6ef372;
  param_1[3] = 0xa54ff53a;
  param_1[4] = 0x510e527f;
  param_1[5] = 0x9b05688c;
  param_1[6] = 0x1f83d9ab;
  param_1[7] = 0x5be0cd19;
  param_1[8] = 0;
  param_1[9] = 0;
  memset(param_1 + 10,0,0x40);
  return;
}



/* 10020228 FUN_10020228 */

void FUN_10020228(undefined4 *param_1)

{
  *param_1 = 0xc1059ed8;
  param_1[1] = 0xcbbb9d5d;
  param_1[2] = 0x367cd507;
  param_1[3] = 0x629a292a;
  param_1[4] = 0x3070dd17;
  param_1[5] = 0x9159015a;
  param_1[6] = 0xf70e5939;
  param_1[7] = 0x152fecd8;
  param_1[8] = 0xffc00b31;
  param_1[9] = 0x67332667;
  param_1[10] = 0x68581511;
  param_1[0xb] = 0x8eb44a87;
  param_1[0xc] = 0x64f98fa7;
  param_1[0xd] = 0xdb0c2e0d;
  param_1[0xe] = 0xbefa4fa4;
  param_1[0xf] = 0x47b5481d;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  return;
}



/* 100202fc FUN_100202fc */

void FUN_100202fc(undefined4 *param_1)

{
  *param_1 = 0xf3bcc908;
  param_1[1] = 0x6a09e667;
  param_1[2] = 0x84caa73b;
  param_1[3] = 0xbb67ae85;
  param_1[4] = 0xfe94f82b;
  param_1[5] = 0x3c6ef372;
  param_1[6] = 0x5f1d36f1;
  param_1[7] = 0xa54ff53a;
  param_1[8] = 0xade682d1;
  param_1[9] = 0x510e527f;
  param_1[10] = 0x2b3e6c1f;
  param_1[0xb] = 0x9b05688c;
  param_1[0xc] = 0xfb41bd6b;
  param_1[0xd] = 0x1f83d9ab;
  param_1[0xe] = 0x137e2179;
  param_1[0xf] = 0x5be0cd19;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  return;
}



/* 100203d0 FUN_100203d0 */

/* Boundary evidence: original MIPS .pdata 100203d0..10023dc7. Semantic name remains unreviewed. */

void FUN_100203d0(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  uint local_154;
  int *local_150;
  uint local_144;
  uint local_128;
  uint local_124;
  uint local_120;
  uint local_11c;
  uint local_108;
  uint local_104;
  uint local_100;
  uint local_fc;
  uint local_e8;
  uint local_d0;
  uint local_c8;
  uint local_c0;
  uint local_a8 [32];
  
  local_108 = *param_1;
  local_100 = param_1[2];
  puVar5 = local_a8;
  local_c0 = param_1[4];
  local_c8 = param_1[6];
  local_120 = param_1[10];
  local_d0 = param_1[0xc];
  local_104 = param_1[1];
  local_e8 = param_1[0xe];
  local_fc = param_1[3];
  local_128 = param_1[8];
  local_124 = param_1[9];
  local_11c = param_1[0xb];
  uVar12 = param_1[5];
  uVar18 = param_1[7];
  uVar15 = param_1[0xd];
  uVar23 = param_1[0xf];
  local_144 = 0;
  local_150 = &DAT_10003c48;
  uVar1 = local_144;
  do {
    local_144 = uVar1;
    uVar1 = param_2[1];
    uVar7 = *param_2;
    uVar2 = (uVar1 >> 8 ^ uVar1 << 8) & 0xff00ff ^ uVar1 << 8;
    uVar1 = (uVar7 >> 8 ^ (uVar7 << 8 | uVar1 >> 0x18)) & 0xff00ff ^ (uVar7 << 8 | uVar1 >> 0x18);
    *puVar5 = uVar2 >> 0x10 ^ uVar2 << 0x10;
    puVar5[1] = (uVar1 ^ uVar2) >> 0x10 ^ (uVar1 << 0x10 | uVar2 >> 0x10);
    uVar26 = __ll_lshift(local_128,local_124,0x17);
    uVar27 = __ll_lshift(local_128,local_124,0x2e);
    uVar28 = __ll_lshift(local_128,local_124,0x32);
    uVar1 = ((uint)uVar26 | local_124 >> 9) ^ ((uint)uVar27 | local_124 << 0xe | local_128 >> 0x12)
            ^ ((uint)uVar28 | local_124 << 0x12 | local_128 >> 0xe);
    uVar7 = uVar1 + (~local_128 & local_d0 ^ local_120 & local_128);
    uVar2 = uVar7 + *puVar5;
    uVar3 = uVar2 + *local_150;
    local_e8 = uVar3 + local_e8;
    local_c8 = local_e8 + local_c8;
    iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
             ((uint)((ulonglong)uVar27 >> 0x20) | local_124 >> 0x12) ^
            ((uint)((ulonglong)uVar28 >> 0x20) | local_124 >> 0xe)) +
            (~local_124 & uVar15 ^ local_11c & local_124) + (uint)(uVar7 < uVar1) + puVar5[1] +
            (uint)(uVar2 < uVar7) + local_150[1] + (uint)(uVar3 < uVar2) + uVar23 +
            (uint)(local_e8 < uVar3);
    uVar3 = iVar4 + uVar18 + (uint)(local_c8 < local_e8);
    uVar26 = __ll_lshift(local_108,local_104,0x19);
    uVar27 = __ll_lshift(local_108,local_104,0x1e);
    uVar28 = __ll_lshift(local_108,local_104,0x24);
    uVar23 = ((uint)uVar26 | local_104 >> 7) ^ ((uint)uVar27 | local_104 >> 2) ^
             ((uint)uVar28 | local_104 << 4 | local_108 >> 0x1c);
    uVar1 = uVar23 + ((local_100 ^ local_108) & local_c0 ^ local_100 & local_108);
    local_e8 = uVar1 + local_e8;
    uVar2 = param_2[2];
    uVar18 = param_2[3];
    uVar7 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
            ((uint)((ulonglong)uVar28 >> 0x20) | local_104 >> 0x1c)) +
            ((local_fc ^ local_104) & uVar12 ^ local_fc & local_104) + (uint)(uVar1 < uVar23) +
            iVar4 + (uint)(local_e8 < uVar1);
    uVar1 = (uVar18 >> 8 ^ uVar18 << 8) & 0xff00ff ^ uVar18 << 8;
    uVar18 = (uVar2 >> 8 ^ (uVar2 << 8 | uVar18 >> 0x18)) & 0xff00ff ^ (uVar2 << 8 | uVar18 >> 0x18)
    ;
    puVar5[2] = uVar1 >> 0x10 ^ uVar1 << 0x10;
    puVar5[3] = (uVar18 ^ uVar1) >> 0x10 ^ (uVar18 << 0x10 | uVar1 >> 0x10);
    uVar26 = __ll_lshift(local_c8,uVar3,0x17);
    uVar27 = __ll_lshift(local_c8,uVar3,0x2e);
    uVar28 = __ll_lshift(local_c8,uVar3,0x32);
    uVar1 = ((uint)uVar26 | uVar3 >> 9) ^ ((uint)uVar27 | uVar3 * 0x4000 | local_c8 >> 0x12) ^
            ((uint)uVar28 | uVar3 * 0x40000 | local_c8 >> 0xe);
    uVar23 = uVar1 + (~local_c8 & local_120 ^ local_128 & local_c8);
    uVar18 = uVar23 + puVar5[2];
    uVar2 = uVar18 + local_150[2];
    local_d0 = uVar2 + local_d0;
    iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar3 >> 0x12)
            ^ ((uint)((ulonglong)uVar28 >> 0x20) | uVar3 >> 0xe)) +
            (~uVar3 & local_11c ^ local_124 & uVar3) + (uint)(uVar23 < uVar1) + puVar5[3] +
            (uint)(uVar18 < uVar23) + local_150[3] + (uint)(uVar2 < uVar18) + uVar15 +
            (uint)(local_d0 < uVar2);
    local_c0 = local_d0 + local_c0;
    uVar24 = iVar4 + uVar12 + (uint)(local_c0 < local_d0);
    uVar26 = __ll_lshift(local_e8,uVar7,0x19);
    uVar27 = __ll_lshift(local_e8,uVar7,0x1e);
    uVar28 = __ll_lshift(local_e8,uVar7,0x24);
    uVar15 = ((uint)uVar26 | uVar7 >> 7) ^ ((uint)uVar27 | uVar7 >> 2) ^
             ((uint)uVar28 | uVar7 * 0x10 | local_e8 >> 0x1c);
    uVar1 = uVar15 + ((local_100 ^ local_108) & local_e8 ^ local_100 & local_108);
    local_d0 = uVar1 + local_d0;
    uVar12 = param_2[5];
    uVar18 = param_2[4];
    uVar19 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
             ((uint)((ulonglong)uVar28 >> 0x20) | uVar7 >> 0x1c)) +
             ((local_fc ^ local_104) & uVar7 ^ local_fc & local_104) + (uint)(uVar1 < uVar15) +
             iVar4 + (uint)(local_d0 < uVar1);
    uVar15 = (uVar18 >> 8 ^ (uVar18 << 8 | uVar12 >> 0x18)) & 0xff00ff ^
             (uVar18 << 8 | uVar12 >> 0x18);
    uVar1 = (uVar12 >> 8 ^ uVar12 << 8) & 0xff00ff ^ uVar12 << 8;
    puVar5[4] = uVar1 >> 0x10 ^ uVar1 << 0x10;
    puVar5[5] = (uVar15 ^ uVar1) >> 0x10 ^ (uVar15 << 0x10 | uVar1 >> 0x10);
    uVar26 = __ll_lshift(local_c0,uVar24,0x17);
    uVar27 = __ll_lshift(local_c0,uVar24,0x2e);
    uVar28 = __ll_lshift(local_c0,uVar24,0x32);
    uVar1 = ((uint)uVar26 | uVar24 >> 9) ^ ((uint)uVar27 | uVar24 * 0x4000 | local_c0 >> 0x12) ^
            ((uint)uVar28 | uVar24 * 0x40000 | local_c0 >> 0xe);
    uVar15 = uVar1 + (~local_c0 & local_128 ^ local_c8 & local_c0);
    uVar12 = uVar15 + puVar5[4];
    uVar18 = uVar12 + local_150[4];
    local_120 = uVar18 + local_120;
    iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
             ((uint)((ulonglong)uVar27 >> 0x20) | uVar24 >> 0x12) ^
            ((uint)((ulonglong)uVar28 >> 0x20) | uVar24 >> 0xe)) +
            (~uVar24 & local_124 ^ uVar3 & uVar24) + (uint)(uVar15 < uVar1) + puVar5[5] +
            (uint)(uVar12 < uVar15) + local_150[5] + (uint)(uVar18 < uVar12) + local_11c +
            (uint)(local_120 < uVar18);
    local_100 = local_120 + local_100;
    uVar16 = iVar4 + local_fc + (uint)(local_100 < local_120);
    uVar26 = __ll_lshift(local_d0,uVar19,0x19);
    uVar27 = __ll_lshift(local_d0,uVar19,0x1e);
    uVar28 = __ll_lshift(local_d0,uVar19,0x24);
    uVar12 = ((uint)uVar26 | uVar19 >> 7) ^ ((uint)uVar27 | uVar19 >> 2) ^
             ((uint)uVar28 | uVar19 * 0x10 | local_d0 >> 0x1c);
    uVar1 = uVar12 + ((local_d0 ^ local_108) & local_e8 ^ local_d0 & local_108);
    local_120 = uVar1 + local_120;
    uVar13 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
             ((uint)((ulonglong)uVar28 >> 0x20) | uVar19 >> 0x1c)) +
             ((uVar19 ^ local_104) & uVar7 ^ uVar19 & local_104) + (uint)(uVar1 < uVar12) + iVar4 +
             (uint)(local_120 < uVar1);
    uVar15 = param_2[6];
    uVar1 = param_2[7];
    uVar12 = (uVar1 >> 8 ^ uVar1 << 8) & 0xff00ff ^ uVar1 << 8;
    uVar1 = (uVar15 >> 8 ^ (uVar15 << 8 | uVar1 >> 0x18)) & 0xff00ff ^ (uVar15 << 8 | uVar1 >> 0x18)
    ;
    puVar5[6] = uVar12 >> 0x10 ^ uVar12 << 0x10;
    puVar5[7] = (uVar1 ^ uVar12) >> 0x10 ^ (uVar1 << 0x10 | uVar12 >> 0x10);
    uVar26 = __ll_lshift(local_100,uVar16,0x17);
    uVar27 = __ll_lshift(local_100,uVar16,0x2e);
    uVar28 = __ll_lshift(local_100,uVar16,0x32);
    uVar1 = ((uint)uVar26 | uVar16 >> 9) ^ ((uint)uVar27 | uVar16 * 0x4000 | local_100 >> 0x12) ^
            ((uint)uVar28 | uVar16 * 0x40000 | local_100 >> 0xe);
    uVar15 = uVar1 + (~local_100 & local_c8 ^ local_c0 & local_100);
    uVar12 = uVar15 + puVar5[6];
    uVar18 = uVar12 + local_150[6];
    local_128 = uVar18 + local_128;
    iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
             ((uint)((ulonglong)uVar27 >> 0x20) | uVar16 >> 0x12) ^
            ((uint)((ulonglong)uVar28 >> 0x20) | uVar16 >> 0xe)) +
            (~uVar16 & uVar3 ^ uVar24 & uVar16) + (uint)(uVar15 < uVar1) + puVar5[7] +
            (uint)(uVar12 < uVar15) + local_150[7] + (uint)(uVar18 < uVar12) + local_124 +
            (uint)(local_128 < uVar18);
    local_108 = local_128 + local_108;
    uVar8 = iVar4 + local_104 + (uint)(local_108 < local_128);
    uVar26 = __ll_lshift(local_120,uVar13,0x19);
    uVar27 = __ll_lshift(local_120,uVar13,0x1e);
    uVar28 = __ll_lshift(local_120,uVar13,0x24);
    uVar12 = ((uint)uVar26 | uVar13 >> 7) ^ ((uint)uVar27 | uVar13 >> 2) ^
             ((uint)uVar28 | uVar13 * 0x10 | local_120 >> 0x1c);
    uVar1 = uVar12 + ((local_d0 ^ local_120) & local_e8 ^ local_d0 & local_120);
    local_128 = uVar1 + local_128;
    uVar6 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
            ((uint)((ulonglong)uVar28 >> 0x20) | uVar13 >> 0x1c)) +
            ((uVar19 ^ uVar13) & uVar7 ^ uVar19 & uVar13) + (uint)(uVar1 < uVar12) + iVar4 +
            (uint)(local_128 < uVar1);
    uVar15 = param_2[8];
    uVar1 = param_2[9];
    uVar12 = (uVar1 >> 8 ^ uVar1 << 8) & 0xff00ff ^ uVar1 << 8;
    uVar1 = (uVar15 >> 8 ^ (uVar15 << 8 | uVar1 >> 0x18)) & 0xff00ff ^ (uVar15 << 8 | uVar1 >> 0x18)
    ;
    puVar5[8] = uVar12 >> 0x10 ^ uVar12 << 0x10;
    puVar5[9] = (uVar1 ^ uVar12) >> 0x10 ^ (uVar1 << 0x10 | uVar12 >> 0x10);
    uVar26 = __ll_lshift(local_108,uVar8,0x17);
    uVar27 = __ll_lshift(local_108,uVar8,0x2e);
    uVar28 = __ll_lshift(local_108,uVar8,0x32);
    uVar1 = ((uint)uVar26 | uVar8 >> 9) ^ ((uint)uVar27 | uVar8 * 0x4000 | local_108 >> 0x12) ^
            ((uint)uVar28 | uVar8 * 0x40000 | local_108 >> 0xe);
    uVar15 = uVar1 + (~local_108 & local_c0 ^ local_100 & local_108);
    uVar12 = uVar15 + puVar5[8];
    uVar18 = uVar12 + local_150[8];
    local_c8 = uVar18 + local_c8;
    iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar8 >> 0x12)
            ^ ((uint)((ulonglong)uVar28 >> 0x20) | uVar8 >> 0xe)) +
            (~uVar8 & uVar24 ^ uVar16 & uVar8) + (uint)(uVar15 < uVar1) + puVar5[9] +
            (uint)(uVar12 < uVar15) + local_150[9] + (uint)(uVar18 < uVar12) + uVar3 +
            (uint)(local_c8 < uVar18);
    local_e8 = local_c8 + local_e8;
    uVar23 = iVar4 + uVar7 + (uint)(local_e8 < local_c8);
    uVar26 = __ll_lshift(local_128,uVar6,0x19);
    uVar27 = __ll_lshift(local_128,uVar6,0x1e);
    uVar28 = __ll_lshift(local_128,uVar6,0x24);
    uVar15 = ((uint)uVar26 | uVar6 >> 7) ^ ((uint)uVar27 | uVar6 >> 2) ^
             ((uint)uVar28 | uVar6 * 0x10 | local_128 >> 0x1c);
    uVar1 = uVar15 + ((local_120 ^ local_128) & local_d0 ^ local_120 & local_128);
    local_c8 = uVar1 + local_c8;
    uVar2 = param_2[10];
    uVar12 = param_2[0xb];
    uVar18 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
             ((uint)((ulonglong)uVar28 >> 0x20) | uVar6 >> 0x1c)) +
             ((uVar13 ^ uVar6) & uVar19 ^ uVar13 & uVar6) + (uint)(uVar1 < uVar15) + iVar4 +
             (uint)(local_c8 < uVar1);
    uVar1 = (uVar12 >> 8 ^ uVar12 << 8) & 0xff00ff ^ uVar12 << 8;
    uVar12 = (uVar2 >> 8 ^ (uVar2 << 8 | uVar12 >> 0x18)) & 0xff00ff ^ (uVar2 << 8 | uVar12 >> 0x18)
    ;
    puVar5[10] = uVar1 >> 0x10 ^ uVar1 << 0x10;
    puVar5[0xb] = (uVar12 ^ uVar1) >> 0x10 ^ (uVar12 << 0x10 | uVar1 >> 0x10);
    uVar26 = __ll_lshift(local_e8,uVar23,0x17);
    uVar27 = __ll_lshift(local_e8,uVar23,0x2e);
    uVar28 = __ll_lshift(local_e8,uVar23,0x32);
    uVar1 = ((uint)uVar26 | uVar23 >> 9) ^ ((uint)uVar27 | uVar23 * 0x4000 | local_e8 >> 0x12) ^
            ((uint)uVar28 | uVar23 * 0x40000 | local_e8 >> 0xe);
    uVar15 = uVar1 + (~local_e8 & local_100 ^ local_e8 & local_108);
    uVar12 = uVar15 + puVar5[10];
    uVar2 = uVar12 + local_150[10];
    local_c0 = uVar2 + local_c0;
    iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
             ((uint)((ulonglong)uVar27 >> 0x20) | uVar23 >> 0x12) ^
            ((uint)((ulonglong)uVar28 >> 0x20) | uVar23 >> 0xe)) +
            (~uVar23 & uVar16 ^ uVar23 & uVar8) + (uint)(uVar15 < uVar1) + puVar5[0xb] +
            (uint)(uVar12 < uVar15) + local_150[0xb] + (uint)(uVar2 < uVar12) + uVar24 +
            (uint)(local_c0 < uVar2);
    local_d0 = local_c0 + local_d0;
    uVar15 = iVar4 + uVar19 + (uint)(local_d0 < local_c0);
    uVar26 = __ll_lshift(local_c8,uVar18,0x19);
    uVar27 = __ll_lshift(local_c8,uVar18,0x1e);
    uVar28 = __ll_lshift(local_c8,uVar18,0x24);
    uVar12 = ((uint)uVar26 | uVar18 >> 7) ^ ((uint)uVar27 | uVar18 >> 2) ^
             ((uint)uVar28 | uVar18 * 0x10 | local_c8 >> 0x1c);
    uVar1 = uVar12 + ((local_128 ^ local_c8) & local_120 ^ local_128 & local_c8);
    local_c0 = uVar1 + local_c0;
    uVar7 = param_2[0xc];
    uVar2 = param_2[0xd];
    uVar12 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
             ((uint)((ulonglong)uVar28 >> 0x20) | uVar18 >> 0x1c)) +
             ((uVar6 ^ uVar18) & uVar13 ^ uVar6 & uVar18) + (uint)(uVar1 < uVar12) + iVar4 +
             (uint)(local_c0 < uVar1);
    uVar1 = (uVar2 >> 8 ^ uVar2 << 8) & 0xff00ff ^ uVar2 << 8;
    uVar2 = (uVar7 >> 8 ^ (uVar7 << 8 | uVar2 >> 0x18)) & 0xff00ff ^ (uVar7 << 8 | uVar2 >> 0x18);
    puVar5[0xc] = uVar1 >> 0x10 ^ uVar1 << 0x10;
    puVar5[0xd] = (uVar2 ^ uVar1) >> 0x10 ^ (uVar2 << 0x10 | uVar1 >> 0x10);
    uVar26 = __ll_lshift(local_d0,uVar15,0x17);
    uVar27 = __ll_lshift(local_d0,uVar15,0x2e);
    uVar28 = __ll_lshift(local_d0,uVar15,0x32);
    uVar1 = ((uint)uVar26 | uVar15 >> 9) ^ ((uint)uVar27 | uVar15 * 0x4000 | local_d0 >> 0x12) ^
            ((uint)uVar28 | uVar15 * 0x40000 | local_d0 >> 0xe);
    uVar7 = uVar1 + (~local_d0 & local_108 ^ local_e8 & local_d0);
    uVar2 = uVar7 + puVar5[0xc];
    uVar3 = uVar2 + local_150[0xc];
    local_100 = uVar3 + local_100;
    iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
             ((uint)((ulonglong)uVar27 >> 0x20) | uVar15 >> 0x12) ^
            ((uint)((ulonglong)uVar28 >> 0x20) | uVar15 >> 0xe)) +
            (~uVar15 & uVar8 ^ uVar23 & uVar15) + (uint)(uVar7 < uVar1) + puVar5[0xd] +
            (uint)(uVar2 < uVar7) + local_150[0xd] + (uint)(uVar3 < uVar2) + uVar16 +
            (uint)(local_100 < uVar3);
    local_120 = local_100 + local_120;
    local_11c = iVar4 + uVar13 + (uint)(local_120 < local_100);
    uVar26 = __ll_lshift(local_c0,uVar12,0x19);
    uVar27 = __ll_lshift(local_c0,uVar12,0x1e);
    uVar28 = __ll_lshift(local_c0,uVar12,0x24);
    uVar2 = ((uint)uVar26 | uVar12 >> 7) ^ ((uint)uVar27 | uVar12 >> 2) ^
            ((uint)uVar28 | uVar12 * 0x10 | local_c0 >> 0x1c);
    uVar1 = uVar2 + ((local_c8 ^ local_c0) & local_128 ^ local_c8 & local_c0);
    local_100 = uVar1 + local_100;
    local_fc = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
               ((uint)((ulonglong)uVar28 >> 0x20) | uVar12 >> 0x1c)) +
               ((uVar18 ^ uVar12) & uVar6 ^ uVar18 & uVar12) + (uint)(uVar1 < uVar2) + iVar4 +
               (uint)(local_100 < uVar1);
    uVar7 = param_2[0xe];
    uVar1 = param_2[0xf];
    param_2 = param_2 + 0x10;
    uVar2 = (uVar1 >> 8 ^ uVar1 << 8) & 0xff00ff ^ uVar1 << 8;
    uVar1 = (uVar7 >> 8 ^ (uVar7 << 8 | uVar1 >> 0x18)) & 0xff00ff ^ (uVar7 << 8 | uVar1 >> 0x18);
    puVar5[0xf] = (uVar1 ^ uVar2) >> 0x10 ^ (uVar1 << 0x10 | uVar2 >> 0x10);
    puVar5[0xe] = uVar2 >> 0x10 ^ uVar2 << 0x10;
    uVar26 = __ll_lshift(local_120,local_11c,0x17);
    uVar27 = __ll_lshift(local_120,local_11c,0x2e);
    uVar28 = __ll_lshift(local_120,local_11c,0x32);
    uVar1 = ((uint)uVar26 | local_11c >> 9) ^
            ((uint)uVar27 | local_11c * 0x4000 | local_120 >> 0x12) ^
            ((uint)uVar28 | local_11c * 0x40000 | local_120 >> 0xe);
    uVar7 = uVar1 + (~local_120 & local_e8 ^ local_d0 & local_120);
    uVar2 = uVar7 + puVar5[0xe];
    uVar3 = uVar2 + local_150[0xe];
    local_108 = uVar3 + local_108;
    local_128 = local_108 + local_128;
    iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
             ((uint)((ulonglong)uVar27 >> 0x20) | local_11c >> 0x12) ^
            ((uint)((ulonglong)uVar28 >> 0x20) | local_11c >> 0xe)) +
            (~local_11c & uVar23 ^ uVar15 & local_11c) + (uint)(uVar7 < uVar1) + puVar5[0xf] +
            (uint)(uVar2 < uVar7) + local_150[0xf] + (uint)(uVar3 < uVar2) + uVar8 +
            (uint)(local_108 < uVar3);
    local_124 = iVar4 + uVar6 + (uint)(local_128 < local_108);
    uVar26 = __ll_lshift(local_100,local_fc,0x19);
    uVar27 = __ll_lshift(local_100,local_fc,0x1e);
    uVar28 = __ll_lshift(local_100,local_fc,0x24);
    uVar7 = ((uint)uVar26 | local_fc >> 7) ^ ((uint)uVar27 | local_fc >> 2) ^
            ((uint)uVar28 | local_fc * 0x10 | local_100 >> 0x1c);
    uVar2 = uVar7 + ((local_c0 ^ local_100) & local_c8 ^ local_c0 & local_100);
    local_108 = uVar2 + local_108;
    uVar1 = local_144 + 8;
    local_104 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
                ((uint)((ulonglong)uVar28 >> 0x20) | local_fc >> 0x1c)) +
                ((uVar12 ^ local_fc) & uVar18 ^ uVar12 & local_fc) + (uint)(uVar2 < uVar7) + iVar4 +
                (uint)(local_108 < uVar2);
    local_150 = local_150 + 0x10;
    puVar5 = puVar5 + 0x10;
  } while ((int)uVar1 < 0x10);
  if (uVar1 < 0x50) {
    local_154 = local_144 + 1;
    uVar2 = local_144 + 6;
    local_144 = local_144 + 9;
    local_150 = &DAT_10003c48 + uVar1 * 2;
    do {
      uVar7 = local_a8[(local_144 & 0xf) * 2];
      uVar13 = local_a8[(local_144 & 0xf) * 2 + 1];
      uVar21 = uVar1 & 0xf;
      uVar3 = local_a8[(uVar2 & 0xf) * 2];
      uVar19 = local_a8[(uVar2 & 0xf) * 2 + 1];
      puVar5 = local_a8 + uVar21 * 2;
      uVar26 = __ll_lshift(uVar3,uVar19,3);
      uVar27 = __ll_lshift(uVar3,uVar19,0x2d);
      uVar24 = ((uint)uVar26 | uVar19 >> 0x1d) ^ ((uint)uVar27 | uVar19 << 0xd | uVar3 >> 0x13) ^
               (uVar19 << 0x1a | uVar3 >> 6);
      uVar28 = __ll_lshift(uVar7,uVar13,0x38);
      uVar29 = __ll_lshift(uVar7,uVar13,0x3f);
      uVar7 = uVar24 + (((uint)uVar28 | uVar13 << 0x18 | uVar7 >> 8) ^
                        ((uint)uVar29 | uVar13 << 0x1f | uVar7 >> 1) ^ (uVar13 << 0x19 | uVar7 >> 7)
                       );
      uVar6 = local_a8[(local_154 & 0xf) * 2 + 1];
      uVar3 = uVar7 + local_a8[(local_154 & 0xf) * 2];
      uVar8 = *puVar5;
      uVar16 = local_a8[uVar21 * 2 + 1];
      *puVar5 = uVar3 + uVar8;
      local_a8[uVar21 * 2 + 1] =
           ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar19 >> 0x13)
           ^ uVar19 >> 6) +
           (((uint)((ulonglong)uVar28 >> 0x20) | uVar13 >> 8) ^
            ((uint)((ulonglong)uVar29 >> 0x20) | uVar13 >> 1) ^ uVar13 >> 7) +
           (uint)(uVar7 < uVar24) + uVar6 + (uint)(uVar3 < uVar7) + uVar16 +
           (uint)(uVar3 + uVar8 < uVar3);
      uVar26 = __ll_lshift(local_128,local_124,0x17);
      uVar27 = __ll_lshift(local_128,local_124,0x2e);
      uVar28 = __ll_lshift(local_128,local_124,0x32);
      uVar7 = ((uint)uVar26 | local_124 >> 9) ^
              ((uint)uVar27 | local_124 << 0xe | local_128 >> 0x12) ^
              ((uint)uVar28 | local_124 << 0x12 | local_128 >> 0xe);
      uVar8 = uVar7 + (~local_128 & local_d0 ^ local_120 & local_128);
      uVar3 = uVar8 + *puVar5;
      local_e8 = uVar3 + local_e8;
      uVar6 = local_e8 + *local_150;
      iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
               ((uint)((ulonglong)uVar27 >> 0x20) | local_124 >> 0x12) ^
              ((uint)((ulonglong)uVar28 >> 0x20) | local_124 >> 0xe)) +
              (~local_124 & uVar15 ^ local_11c & local_124) + (uint)(uVar8 < uVar7) +
              local_a8[uVar21 * 2 + 1] + (uint)(uVar3 < uVar8) + uVar23 + (uint)(local_e8 < uVar3) +
              local_150[1] + (uint)(uVar6 < local_e8);
      local_c8 = uVar6 + local_c8;
      uVar25 = iVar4 + uVar18 + (uint)(local_c8 < uVar6);
      uVar26 = __ll_lshift(local_108,local_104,0x19);
      uVar27 = __ll_lshift(local_108,local_104,0x1e);
      uVar28 = __ll_lshift(local_108,local_104,0x24);
      uVar23 = ((uint)uVar26 | local_104 >> 7) ^ ((uint)uVar27 | local_104 >> 2) ^
               ((uint)uVar28 | local_104 << 4 | local_108 >> 0x1c);
      uVar18 = uVar23 + ((local_100 ^ local_108) & local_c0 ^ local_100 & local_108);
      uVar6 = uVar18 + uVar6;
      uVar7 = local_144 + 1 & 0xf;
      uVar16 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
               ((uint)((ulonglong)uVar28 >> 0x20) | local_104 >> 0x1c)) +
               ((local_fc ^ local_104) & uVar12 ^ local_fc & local_104) + (uint)(uVar18 < uVar23) +
               iVar4 + (uint)(uVar6 < uVar18);
      uVar18 = uVar2 + 1 & 0xf;
      uVar23 = local_a8[uVar7 * 2];
      uVar21 = local_a8[uVar7 * 2 + 1];
      uVar13 = uVar1 + 1 & 0xf;
      uVar24 = local_a8[uVar18 * 2 + 1];
      uVar18 = local_a8[uVar18 * 2];
      puVar5 = local_a8 + uVar13 * 2;
      uVar26 = __ll_lshift(uVar18,uVar24,3);
      uVar27 = __ll_lshift(uVar18,uVar24,0x2d);
      uVar7 = ((uint)uVar26 | uVar24 >> 0x1d) ^ ((uint)uVar27 | uVar24 << 0xd | uVar18 >> 0x13) ^
              (uVar24 << 0x1a | uVar18 >> 6);
      uVar28 = __ll_lshift(uVar23,uVar21,0x38);
      uVar29 = __ll_lshift(uVar23,uVar21,0x3f);
      uVar18 = uVar7 + (((uint)uVar28 | uVar21 << 0x18 | uVar23 >> 8) ^
                        ((uint)uVar29 | uVar21 << 0x1f | uVar23 >> 1) ^
                       (uVar21 << 0x19 | uVar23 >> 7));
      uVar23 = local_154 + 1 & 0xf;
      uVar19 = local_a8[uVar23 * 2 + 1];
      uVar23 = uVar18 + local_a8[uVar23 * 2];
      uVar8 = *puVar5;
      uVar3 = local_a8[uVar13 * 2 + 1];
      *puVar5 = uVar23 + uVar8;
      local_a8[uVar13 * 2 + 1] =
           ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar24 >> 0x13)
           ^ uVar24 >> 6) +
           (((uint)((ulonglong)uVar28 >> 0x20) | uVar21 >> 8) ^
            ((uint)((ulonglong)uVar29 >> 0x20) | uVar21 >> 1) ^ uVar21 >> 7) +
           (uint)(uVar18 < uVar7) + uVar19 + (uint)(uVar23 < uVar18) + uVar3 +
           (uint)(uVar23 + uVar8 < uVar23);
      uVar26 = __ll_lshift(local_c8,uVar25,0x17);
      uVar27 = __ll_lshift(local_c8,uVar25,0x2e);
      uVar28 = __ll_lshift(local_c8,uVar25,0x32);
      uVar18 = ((uint)uVar26 | uVar25 >> 9) ^ ((uint)uVar27 | uVar25 * 0x4000 | local_c8 >> 0x12) ^
               ((uint)uVar28 | uVar25 * 0x40000 | local_c8 >> 0xe);
      uVar3 = uVar18 + (~local_c8 & local_120 ^ local_128 & local_c8);
      uVar23 = uVar3 + *puVar5;
      local_d0 = uVar23 + local_d0;
      uVar7 = local_d0 + local_150[2];
      iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
               ((uint)((ulonglong)uVar27 >> 0x20) | uVar25 >> 0x12) ^
              ((uint)((ulonglong)uVar28 >> 0x20) | uVar25 >> 0xe)) +
              (~uVar25 & local_11c ^ local_124 & uVar25) + (uint)(uVar3 < uVar18) +
              local_a8[uVar13 * 2 + 1] + (uint)(uVar23 < uVar3) + uVar15 + (uint)(local_d0 < uVar23)
              + local_150[3] + (uint)(uVar7 < local_d0);
      local_c0 = uVar7 + local_c0;
      uVar17 = iVar4 + uVar12 + (uint)(local_c0 < uVar7);
      uVar26 = __ll_lshift(uVar6,uVar16,0x19);
      uVar27 = __ll_lshift(uVar6,uVar16,0x1e);
      uVar28 = __ll_lshift(uVar6,uVar16,0x24);
      uVar15 = ((uint)uVar26 | uVar16 >> 7) ^ ((uint)uVar27 | uVar16 >> 2) ^
               ((uint)uVar28 | uVar16 * 0x10 | uVar6 >> 0x1c);
      uVar12 = uVar15 + ((local_100 ^ local_108) & uVar6 ^ local_100 & local_108);
      uVar7 = uVar12 + uVar7;
      uVar18 = local_144 + 2 & 0xf;
      uVar14 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
               ((uint)((ulonglong)uVar28 >> 0x20) | uVar16 >> 0x1c)) +
               ((local_fc ^ local_104) & uVar16 ^ local_fc & local_104) + (uint)(uVar12 < uVar15) +
               iVar4 + (uint)(uVar7 < uVar12);
      uVar15 = uVar2 + 2 & 0xf;
      uVar12 = local_a8[uVar18 * 2];
      uVar24 = local_a8[uVar18 * 2 + 1];
      uVar13 = uVar1 + 2 & 0xf;
      uVar19 = local_a8[uVar15 * 2 + 1];
      uVar15 = local_a8[uVar15 * 2];
      puVar5 = local_a8 + uVar13 * 2;
      uVar26 = __ll_lshift(uVar15,uVar19,3);
      uVar27 = __ll_lshift(uVar15,uVar19,0x2d);
      uVar8 = ((uint)uVar26 | uVar19 >> 0x1d) ^ ((uint)uVar27 | uVar19 << 0xd | uVar15 >> 0x13) ^
              (uVar19 << 0x1a | uVar15 >> 6);
      uVar28 = __ll_lshift(uVar12,uVar24,0x38);
      uVar29 = __ll_lshift(uVar12,uVar24,0x3f);
      uVar12 = uVar8 + (((uint)uVar28 | uVar24 << 0x18 | uVar12 >> 8) ^
                        ((uint)uVar29 | uVar24 << 0x1f | uVar12 >> 1) ^
                       (uVar24 << 0x19 | uVar12 >> 7));
      uVar15 = local_154 + 2 & 0xf;
      uVar18 = local_a8[uVar15 * 2 + 1];
      uVar15 = uVar12 + local_a8[uVar15 * 2];
      uVar23 = *puVar5;
      uVar3 = local_a8[uVar13 * 2 + 1];
      *puVar5 = uVar15 + uVar23;
      local_a8[uVar13 * 2 + 1] =
           ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar19 >> 0x13)
           ^ uVar19 >> 6) +
           (((uint)((ulonglong)uVar28 >> 0x20) | uVar24 >> 8) ^
            ((uint)((ulonglong)uVar29 >> 0x20) | uVar24 >> 1) ^ uVar24 >> 7) +
           (uint)(uVar12 < uVar8) + uVar18 + (uint)(uVar15 < uVar12) + uVar3 +
           (uint)(uVar15 + uVar23 < uVar15);
      uVar26 = __ll_lshift(local_c0,uVar17,0x17);
      uVar27 = __ll_lshift(local_c0,uVar17,0x2e);
      uVar28 = __ll_lshift(local_c0,uVar17,0x32);
      uVar12 = ((uint)uVar26 | uVar17 >> 9) ^ ((uint)uVar27 | uVar17 * 0x4000 | local_c0 >> 0x12) ^
               ((uint)uVar28 | uVar17 * 0x40000 | local_c0 >> 0xe);
      uVar18 = uVar12 + (~local_c0 & local_128 ^ local_c8 & local_c0);
      uVar15 = uVar18 + *puVar5;
      local_120 = uVar15 + local_120;
      uVar3 = local_120 + local_150[4];
      iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
               ((uint)((ulonglong)uVar27 >> 0x20) | uVar17 >> 0x12) ^
              ((uint)((ulonglong)uVar28 >> 0x20) | uVar17 >> 0xe)) +
              (~uVar17 & local_124 ^ uVar25 & uVar17) + (uint)(uVar18 < uVar12) +
              local_a8[uVar13 * 2 + 1] + (uint)(uVar15 < uVar18) + local_11c +
              (uint)(local_120 < uVar15) + local_150[5] + (uint)(uVar3 < local_120);
      local_100 = uVar3 + local_100;
      uVar24 = iVar4 + local_fc + (uint)(local_100 < uVar3);
      uVar26 = __ll_lshift(uVar7,uVar14,0x19);
      uVar27 = __ll_lshift(uVar7,uVar14,0x1e);
      uVar28 = __ll_lshift(uVar7,uVar14,0x24);
      uVar15 = ((uint)uVar26 | uVar14 >> 7) ^ ((uint)uVar27 | uVar14 >> 2) ^
               ((uint)uVar28 | uVar14 * 0x10 | uVar7 >> 0x1c);
      uVar12 = uVar15 + ((uVar7 ^ local_108) & uVar6 ^ uVar7 & local_108);
      uVar3 = uVar12 + uVar3;
      uVar18 = local_144 + 3 & 0xf;
      uVar19 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
               ((uint)((ulonglong)uVar28 >> 0x20) | uVar14 >> 0x1c)) +
               ((uVar14 ^ local_104) & uVar16 ^ uVar14 & local_104) + (uint)(uVar12 < uVar15) +
               iVar4 + (uint)(uVar3 < uVar12);
      uVar15 = uVar2 + 3 & 0xf;
      uVar12 = local_a8[uVar18 * 2];
      uVar21 = local_a8[uVar18 * 2 + 1];
      uVar22 = uVar1 + 3 & 0xf;
      uVar13 = local_a8[uVar15 * 2 + 1];
      uVar15 = local_a8[uVar15 * 2];
      puVar5 = local_a8 + uVar22 * 2;
      uVar26 = __ll_lshift(uVar15,uVar13,3);
      uVar27 = __ll_lshift(uVar15,uVar13,0x2d);
      uVar20 = ((uint)uVar26 | uVar13 >> 0x1d) ^ ((uint)uVar27 | uVar13 << 0xd | uVar15 >> 0x13) ^
               (uVar13 << 0x1a | uVar15 >> 6);
      uVar28 = __ll_lshift(uVar12,uVar21,0x38);
      uVar29 = __ll_lshift(uVar12,uVar21,0x3f);
      uVar12 = uVar20 + (((uint)uVar28 | uVar21 << 0x18 | uVar12 >> 8) ^
                         ((uint)uVar29 | uVar21 << 0x1f | uVar12 >> 1) ^
                        (uVar21 << 0x19 | uVar12 >> 7));
      uVar15 = local_154 + 3 & 0xf;
      uVar18 = local_a8[uVar15 * 2 + 1];
      uVar15 = uVar12 + local_a8[uVar15 * 2];
      uVar23 = *puVar5;
      uVar8 = local_a8[uVar22 * 2 + 1];
      *puVar5 = uVar15 + uVar23;
      local_a8[uVar22 * 2 + 1] =
           ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar13 >> 0x13)
           ^ uVar13 >> 6) +
           (((uint)((ulonglong)uVar28 >> 0x20) | uVar21 >> 8) ^
            ((uint)((ulonglong)uVar29 >> 0x20) | uVar21 >> 1) ^ uVar21 >> 7) +
           (uint)(uVar12 < uVar20) + uVar18 + (uint)(uVar15 < uVar12) + uVar8 +
           (uint)(uVar15 + uVar23 < uVar15);
      uVar26 = __ll_lshift(local_100,uVar24,0x17);
      uVar27 = __ll_lshift(local_100,uVar24,0x2e);
      uVar28 = __ll_lshift(local_100,uVar24,0x32);
      uVar12 = ((uint)uVar26 | uVar24 >> 9) ^ ((uint)uVar27 | uVar24 * 0x4000 | local_100 >> 0x12) ^
               ((uint)uVar28 | uVar24 * 0x40000 | local_100 >> 0xe);
      uVar18 = uVar12 + (~local_100 & local_c8 ^ local_c0 & local_100);
      uVar15 = uVar18 + *puVar5;
      local_128 = uVar15 + local_128;
      uVar8 = local_128 + local_150[6];
      iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
               ((uint)((ulonglong)uVar27 >> 0x20) | uVar24 >> 0x12) ^
              ((uint)((ulonglong)uVar28 >> 0x20) | uVar24 >> 0xe)) +
              (~uVar24 & uVar25 ^ uVar17 & uVar24) + (uint)(uVar18 < uVar12) +
              local_a8[uVar22 * 2 + 1] + (uint)(uVar15 < uVar18) + local_124 +
              (uint)(local_128 < uVar15) + local_150[7] + (uint)(uVar8 < local_128);
      local_108 = uVar8 + local_108;
      uVar22 = iVar4 + local_104 + (uint)(local_108 < uVar8);
      uVar26 = __ll_lshift(uVar3,uVar19,0x19);
      uVar27 = __ll_lshift(uVar3,uVar19,0x1e);
      uVar28 = __ll_lshift(uVar3,uVar19,0x24);
      uVar15 = ((uint)uVar26 | uVar19 >> 7) ^ ((uint)uVar27 | uVar19 >> 2) ^
               ((uint)uVar28 | uVar19 * 0x10 | uVar3 >> 0x1c);
      uVar12 = uVar15 + ((uVar7 ^ uVar3) & uVar6 ^ uVar7 & uVar3);
      uVar8 = uVar12 + uVar8;
      uVar18 = local_144 + 4 & 0xf;
      uVar21 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
               ((uint)((ulonglong)uVar28 >> 0x20) | uVar19 >> 0x1c)) +
               ((uVar14 ^ uVar19) & uVar16 ^ uVar14 & uVar19) + (uint)(uVar12 < uVar15) + iVar4 +
               (uint)(uVar8 < uVar12);
      uVar12 = uVar2 + 4 & 0xf;
      uVar15 = local_a8[uVar18 * 2];
      uVar11 = local_a8[uVar18 * 2 + 1];
      uVar20 = uVar1 + 4 & 0xf;
      uVar18 = local_a8[uVar12 * 2];
      uVar10 = local_a8[uVar12 * 2 + 1];
      puVar5 = local_a8 + uVar20 * 2;
      uVar26 = __ll_lshift(uVar18,uVar10,3);
      uVar27 = __ll_lshift(uVar18,uVar10,0x2d);
      uVar18 = ((uint)uVar26 | uVar10 >> 0x1d) ^ ((uint)uVar27 | uVar10 << 0xd | uVar18 >> 0x13) ^
               (uVar10 << 0x1a | uVar18 >> 6);
      uVar28 = __ll_lshift(uVar15,uVar11,0x38);
      uVar29 = __ll_lshift(uVar15,uVar11,0x3f);
      uVar12 = uVar18 + (((uint)uVar28 | uVar11 << 0x18 | uVar15 >> 8) ^
                         ((uint)uVar29 | uVar11 << 0x1f | uVar15 >> 1) ^
                        (uVar11 << 0x19 | uVar15 >> 7));
      uVar15 = local_154 + 4 & 0xf;
      uVar9 = local_a8[uVar15 * 2 + 1];
      uVar15 = uVar12 + local_a8[uVar15 * 2];
      uVar13 = *puVar5;
      uVar23 = local_a8[uVar20 * 2 + 1];
      *puVar5 = uVar15 + uVar13;
      local_a8[uVar20 * 2 + 1] =
           ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar10 >> 0x13)
           ^ uVar10 >> 6) +
           (((uint)((ulonglong)uVar28 >> 0x20) | uVar11 >> 8) ^
            ((uint)((ulonglong)uVar29 >> 0x20) | uVar11 >> 1) ^ uVar11 >> 7) +
           (uint)(uVar12 < uVar18) + uVar9 + (uint)(uVar15 < uVar12) + uVar23 +
           (uint)(uVar15 + uVar13 < uVar15);
      uVar26 = __ll_lshift(local_108,uVar22,0x17);
      uVar27 = __ll_lshift(local_108,uVar22,0x2e);
      uVar28 = __ll_lshift(local_108,uVar22,0x32);
      uVar12 = ((uint)uVar26 | uVar22 >> 9) ^ ((uint)uVar27 | uVar22 * 0x4000 | local_108 >> 0x12) ^
               ((uint)uVar28 | uVar22 * 0x40000 | local_108 >> 0xe);
      uVar23 = uVar12 + (~local_108 & local_c0 ^ local_100 & local_108);
      uVar15 = uVar23 + *puVar5;
      local_c8 = uVar15 + local_c8;
      uVar18 = local_c8 + local_150[8];
      iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
               ((uint)((ulonglong)uVar27 >> 0x20) | uVar22 >> 0x12) ^
              ((uint)((ulonglong)uVar28 >> 0x20) | uVar22 >> 0xe)) +
              (~uVar22 & uVar17 ^ uVar24 & uVar22) + (uint)(uVar23 < uVar12) +
              local_a8[uVar20 * 2 + 1] + (uint)(uVar15 < uVar23) + uVar25 +
              (uint)(local_c8 < uVar15) + local_150[9] + (uint)(uVar18 < local_c8);
      local_e8 = uVar18 + uVar6;
      uVar23 = iVar4 + uVar16 + (uint)(local_e8 < uVar18);
      uVar26 = __ll_lshift(uVar8,uVar21,0x19);
      uVar27 = __ll_lshift(uVar8,uVar21,0x1e);
      uVar28 = __ll_lshift(uVar8,uVar21,0x24);
      uVar15 = ((uint)uVar26 | uVar21 >> 7) ^ ((uint)uVar27 | uVar21 >> 2) ^
               ((uint)uVar28 | uVar21 * 0x10 | uVar8 >> 0x1c);
      uVar12 = uVar15 + ((uVar3 ^ uVar8) & uVar7 ^ uVar3 & uVar8);
      local_c8 = uVar12 + uVar18;
      uVar6 = local_144 + 5 & 0xf;
      uVar13 = local_a8[uVar6 * 2];
      uVar18 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
               ((uint)((ulonglong)uVar28 >> 0x20) | uVar21 >> 0x1c)) +
               ((uVar19 ^ uVar21) & uVar14 ^ uVar19 & uVar21) + (uint)(uVar12 < uVar15) + iVar4 +
               (uint)(local_c8 < uVar12);
      uVar12 = uVar2 + 5 & 0xf;
      uVar20 = local_a8[uVar6 * 2 + 1];
      uVar10 = uVar1 + 5 & 0xf;
      uVar15 = local_a8[uVar12 * 2];
      uVar11 = local_a8[uVar12 * 2 + 1];
      puVar5 = local_a8 + uVar10 * 2;
      uVar26 = __ll_lshift(uVar15,uVar11,3);
      uVar27 = __ll_lshift(uVar15,uVar11,0x2d);
      uVar9 = ((uint)uVar26 | uVar11 >> 0x1d) ^ ((uint)uVar27 | uVar11 << 0xd | uVar15 >> 0x13) ^
              (uVar11 << 0x1a | uVar15 >> 6);
      uVar28 = __ll_lshift(uVar13,uVar20,0x38);
      uVar29 = __ll_lshift(uVar13,uVar20,0x3f);
      uVar12 = uVar9 + (((uint)uVar28 | uVar20 << 0x18 | uVar13 >> 8) ^
                        ((uint)uVar29 | uVar20 << 0x1f | uVar13 >> 1) ^
                       (uVar20 << 0x19 | uVar13 >> 7));
      uVar15 = local_154 + 5 & 0xf;
      uVar6 = local_a8[uVar15 * 2 + 1];
      uVar15 = uVar12 + local_a8[uVar15 * 2];
      uVar13 = *puVar5;
      uVar16 = local_a8[uVar10 * 2 + 1];
      *puVar5 = uVar15 + uVar13;
      local_a8[uVar10 * 2 + 1] =
           ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar11 >> 0x13)
           ^ uVar11 >> 6) +
           (((uint)((ulonglong)uVar28 >> 0x20) | uVar20 >> 8) ^
            ((uint)((ulonglong)uVar29 >> 0x20) | uVar20 >> 1) ^ uVar20 >> 7) +
           (uint)(uVar12 < uVar9) + uVar6 + (uint)(uVar15 < uVar12) + uVar16 +
           (uint)(uVar15 + uVar13 < uVar15);
      uVar26 = __ll_lshift(local_e8,uVar23,0x17);
      uVar27 = __ll_lshift(local_e8,uVar23,0x2e);
      uVar28 = __ll_lshift(local_e8,uVar23,0x32);
      uVar15 = ((uint)uVar26 | uVar23 >> 9) ^ ((uint)uVar27 | uVar23 * 0x4000 | local_e8 >> 0x12) ^
               ((uint)uVar28 | uVar23 * 0x40000 | local_e8 >> 0xe);
      uVar12 = uVar15 + (~local_e8 & local_100 ^ local_e8 & local_108);
      uVar6 = uVar12 + *puVar5;
      local_c0 = uVar6 + local_c0;
      uVar13 = local_c0 + local_150[10];
      iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
               ((uint)((ulonglong)uVar27 >> 0x20) | uVar23 >> 0x12) ^
              ((uint)((ulonglong)uVar28 >> 0x20) | uVar23 >> 0xe)) +
              (~uVar23 & uVar24 ^ uVar23 & uVar22) + (uint)(uVar12 < uVar15) +
              local_a8[uVar10 * 2 + 1] + (uint)(uVar6 < uVar12) + uVar17 + (uint)(local_c0 < uVar6)
              + local_150[0xb] + (uint)(uVar13 < local_c0);
      local_d0 = uVar13 + uVar7;
      uVar15 = iVar4 + uVar14 + (uint)(local_d0 < uVar13);
      uVar26 = __ll_lshift(local_c8,uVar18,0x19);
      uVar27 = __ll_lshift(local_c8,uVar18,0x1e);
      uVar28 = __ll_lshift(local_c8,uVar18,0x24);
      uVar7 = ((uint)uVar26 | uVar18 >> 7) ^ ((uint)uVar27 | uVar18 >> 2) ^
              ((uint)uVar28 | uVar18 * 0x10 | local_c8 >> 0x1c);
      uVar12 = uVar7 + ((uVar8 ^ local_c8) & uVar3 ^ uVar8 & local_c8);
      local_c0 = uVar12 + uVar13;
      uVar12 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
               ((uint)((ulonglong)uVar28 >> 0x20) | uVar18 >> 0x1c)) +
               ((uVar21 ^ uVar18) & uVar19 ^ uVar21 & uVar18) + (uint)(uVar12 < uVar7) + iVar4 +
               (uint)(local_c0 < uVar12);
      uVar7 = local_144 + 6 & 0xf;
      uVar13 = uVar2 + 6 & 0xf;
      uVar6 = local_a8[uVar7 * 2];
      uVar9 = local_a8[uVar7 * 2 + 1];
      uVar14 = uVar1 + 6 & 0xf;
      uVar7 = local_a8[uVar13 * 2];
      uVar11 = local_a8[uVar13 * 2 + 1];
      puVar5 = local_a8 + uVar14 * 2;
      uVar26 = __ll_lshift(uVar7,uVar11,3);
      uVar27 = __ll_lshift(uVar7,uVar11,0x2d);
      uVar10 = ((uint)uVar26 | uVar11 >> 0x1d) ^ ((uint)uVar27 | uVar11 << 0xd | uVar7 >> 0x13) ^
               (uVar11 << 0x1a | uVar7 >> 6);
      uVar28 = __ll_lshift(uVar6,uVar9,0x38);
      uVar29 = __ll_lshift(uVar6,uVar9,0x3f);
      uVar7 = uVar10 + (((uint)uVar28 | uVar9 << 0x18 | uVar6 >> 8) ^
                        ((uint)uVar29 | uVar9 << 0x1f | uVar6 >> 1) ^ (uVar9 << 0x19 | uVar6 >> 7));
      uVar6 = local_154 + 6 & 0xf;
      uVar13 = local_a8[uVar6 * 2 + 1];
      uVar6 = uVar7 + local_a8[uVar6 * 2];
      uVar16 = *puVar5;
      uVar20 = local_a8[uVar14 * 2 + 1];
      *puVar5 = uVar6 + uVar16;
      local_a8[uVar14 * 2 + 1] =
           ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar11 >> 0x13)
           ^ uVar11 >> 6) +
           (((uint)((ulonglong)uVar28 >> 0x20) | uVar9 >> 8) ^
            ((uint)((ulonglong)uVar29 >> 0x20) | uVar9 >> 1) ^ uVar9 >> 7) + (uint)(uVar7 < uVar10)
           + uVar13 + (uint)(uVar6 < uVar7) + uVar20 + (uint)(uVar6 + uVar16 < uVar6);
      uVar26 = __ll_lshift(local_d0,uVar15,0x17);
      uVar27 = __ll_lshift(local_d0,uVar15,0x2e);
      uVar28 = __ll_lshift(local_d0,uVar15,0x32);
      uVar7 = ((uint)uVar26 | uVar15 >> 9) ^ ((uint)uVar27 | uVar15 * 0x4000 | local_d0 >> 0x12) ^
              ((uint)uVar28 | uVar15 * 0x40000 | local_d0 >> 0xe);
      uVar16 = uVar7 + (~local_d0 & local_108 ^ local_e8 & local_d0);
      uVar6 = uVar16 + *puVar5;
      local_100 = uVar6 + local_100;
      uVar13 = local_100 + local_150[0xc];
      iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
               ((uint)((ulonglong)uVar27 >> 0x20) | uVar15 >> 0x12) ^
              ((uint)((ulonglong)uVar28 >> 0x20) | uVar15 >> 0xe)) +
              (~uVar15 & uVar22 ^ uVar23 & uVar15) + (uint)(uVar16 < uVar7) +
              local_a8[uVar14 * 2 + 1] + (uint)(uVar6 < uVar16) + uVar24 + (uint)(local_100 < uVar6)
              + local_150[0xd] + (uint)(uVar13 < local_100);
      local_120 = uVar13 + uVar3;
      local_11c = iVar4 + uVar19 + (uint)(local_120 < uVar13);
      uVar26 = __ll_lshift(local_c0,uVar12,0x19);
      uVar27 = __ll_lshift(local_c0,uVar12,0x1e);
      uVar28 = __ll_lshift(local_c0,uVar12,0x24);
      uVar3 = ((uint)uVar26 | uVar12 >> 7) ^ ((uint)uVar27 | uVar12 >> 2) ^
              ((uint)uVar28 | uVar12 * 0x10 | local_c0 >> 0x1c);
      uVar7 = uVar3 + ((local_c8 ^ local_c0) & uVar8 ^ local_c8 & local_c0);
      local_100 = uVar7 + uVar13;
      local_fc = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
                 ((uint)((ulonglong)uVar28 >> 0x20) | uVar12 >> 0x1c)) +
                 ((uVar18 ^ uVar12) & uVar21 ^ uVar18 & uVar12) + (uint)(uVar7 < uVar3) + iVar4 +
                 (uint)(local_100 < uVar7);
      uVar7 = local_144 + 7 & 0xf;
      uVar19 = local_a8[uVar7 * 2];
      uVar7 = local_a8[uVar7 * 2 + 1];
      uVar3 = uVar2 + 7 & 0xf;
      uVar16 = uVar1 + 7 & 0xf;
      uVar6 = local_a8[uVar3 * 2];
      uVar24 = local_a8[uVar3 * 2 + 1];
      puVar5 = local_a8 + uVar16 * 2;
      uVar26 = __ll_lshift(uVar6,uVar24,3);
      uVar27 = __ll_lshift(uVar6,uVar24,0x2d);
      uVar13 = ((uint)uVar26 | uVar24 >> 0x1d) ^ ((uint)uVar27 | uVar24 << 0xd | uVar6 >> 0x13) ^
               (uVar24 << 0x1a | uVar6 >> 6);
      uVar28 = __ll_lshift(uVar19,uVar7,0x38);
      uVar29 = __ll_lshift(uVar19,uVar7,0x3f);
      uVar3 = uVar13 + (((uint)uVar28 | uVar7 << 0x18 | uVar19 >> 8) ^
                        ((uint)uVar29 | uVar7 << 0x1f | uVar19 >> 1) ^ (uVar7 << 0x19 | uVar19 >> 7)
                       );
      uVar6 = local_154 + 7 & 0xf;
      uVar19 = local_a8[uVar6 * 2 + 1];
      uVar6 = uVar3 + local_a8[uVar6 * 2];
      uVar20 = *puVar5;
      uVar9 = local_a8[uVar16 * 2 + 1];
      *puVar5 = uVar6 + uVar20;
      local_a8[uVar16 * 2 + 1] =
           ((uint)((ulonglong)uVar26 >> 0x20) ^ ((uint)((ulonglong)uVar27 >> 0x20) | uVar24 >> 0x13)
           ^ uVar24 >> 6) +
           (((uint)((ulonglong)uVar28 >> 0x20) | uVar7 >> 8) ^
            ((uint)((ulonglong)uVar29 >> 0x20) | uVar7 >> 1) ^ uVar7 >> 7) + (uint)(uVar3 < uVar13)
           + uVar19 + (uint)(uVar6 < uVar3) + uVar9 + (uint)(uVar6 + uVar20 < uVar6);
      uVar26 = __ll_lshift(local_120,local_11c,0x17);
      uVar27 = __ll_lshift(local_120,local_11c,0x2e);
      uVar28 = __ll_lshift(local_120,local_11c,0x32);
      uVar7 = ((uint)uVar26 | local_11c >> 9) ^
              ((uint)uVar27 | local_11c * 0x4000 | local_120 >> 0x12) ^
              ((uint)uVar28 | local_11c * 0x40000 | local_120 >> 0xe);
      uVar13 = uVar7 + (~local_120 & local_e8 ^ local_d0 & local_120);
      uVar3 = uVar13 + *puVar5;
      local_108 = uVar3 + local_108;
      uVar6 = local_108 + local_150[0xe];
      local_128 = uVar6 + uVar8;
      iVar4 = ((uint)((ulonglong)uVar26 >> 0x20) ^
               ((uint)((ulonglong)uVar27 >> 0x20) | local_11c >> 0x12) ^
              ((uint)((ulonglong)uVar28 >> 0x20) | local_11c >> 0xe)) +
              (~local_11c & uVar23 ^ uVar15 & local_11c) + (uint)(uVar13 < uVar7) +
              local_a8[uVar16 * 2 + 1] + (uint)(uVar3 < uVar13) + uVar22 + (uint)(local_108 < uVar3)
              + local_150[0xf] + (uint)(uVar6 < local_108);
      local_124 = iVar4 + uVar21 + (uint)(local_128 < uVar6);
      uVar26 = __ll_lshift(local_100,local_fc,0x19);
      uVar27 = __ll_lshift(local_100,local_fc,0x1e);
      uVar28 = __ll_lshift(local_100,local_fc,0x24);
      uVar3 = ((uint)uVar26 | local_fc >> 7) ^ ((uint)uVar27 | local_fc >> 2) ^
              ((uint)uVar28 | local_fc * 0x10 | local_100 >> 0x1c);
      uVar7 = uVar3 + ((local_c0 ^ local_100) & local_c8 ^ local_c0 & local_100);
      local_108 = uVar7 + uVar6;
      local_104 = ((uint)((ulonglong)uVar26 >> 0x20) ^ (uint)((ulonglong)uVar27 >> 0x20) ^
                  ((uint)((ulonglong)uVar28 >> 0x20) | local_fc >> 0x1c)) +
                  ((uVar12 ^ local_fc) & uVar18 ^ uVar12 & local_fc) + (uint)(uVar7 < uVar3) + iVar4
                  + (uint)(local_108 < uVar7);
      uVar1 = uVar1 + 8;
      local_144 = local_144 + 8;
      uVar2 = uVar2 + 8;
      local_154 = local_154 + 8;
      local_150 = local_150 + 0x10;
    } while (uVar1 < 0x50);
  }
  uVar3 = *param_1;
  local_108 = uVar3 + local_108;
  *param_1 = local_108;
  uVar6 = param_1[2];
  local_100 = uVar6 + local_100;
  param_1[2] = local_100;
  uVar1 = param_1[4];
  local_c0 = uVar1 + local_c0;
  param_1[4] = local_c0;
  uVar2 = param_1[6];
  local_c8 = uVar2 + local_c8;
  param_1[6] = local_c8;
  uVar7 = param_1[8];
  param_1[1] = param_1[1] + local_104 + (uint)(local_108 < uVar3);
  local_128 = uVar7 + local_128;
  param_1[8] = local_128;
  uVar3 = param_1[10];
  param_1[3] = param_1[3] + local_fc + (uint)(local_100 < uVar6);
  local_120 = uVar3 + local_120;
  param_1[5] = param_1[5] + uVar12 + (uint)(local_c0 < uVar1);
  uVar1 = param_1[0xc];
  param_1[10] = local_120;
  local_d0 = uVar1 + local_d0;
  uVar12 = param_1[0xe];
  param_1[0xc] = local_d0;
  local_e8 = uVar12 + local_e8;
  param_1[7] = param_1[7] + uVar18 + (uint)(local_c8 < uVar2);
  param_1[9] = param_1[9] + local_124 + (uint)(local_128 < uVar7);
  param_1[0xb] = param_1[0xb] + local_11c + (uint)(local_120 < uVar3);
  param_1[0xd] = param_1[0xd] + uVar15 + (uint)(local_d0 < uVar1);
  param_1[0xe] = local_e8;
  param_1[0xf] = param_1[0xf] + uVar23 + (uint)(local_e8 < uVar12);
  return;
}



/* 10023dc8 FUN_10023dc8 */

/* Boundary evidence: original MIPS .pdata 10023dc8..10023f63. Semantic name remains unreviewed. */

void FUN_10023dc8(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1[0x12] & 0x7f;
  uVar1 = param_3 + param_1[0x12];
  uVar2 = param_1[0x13] + (uint)(uVar1 < param_3);
  param_1[0x12] = uVar1;
  param_1[0x13] = uVar2;
  if ((uVar2 == 0) && (uVar1 < param_3)) {
    uVar2 = param_1[0x10];
    uVar1 = uVar2 + 1;
    param_1[0x10] = uVar1;
    param_1[0x11] = param_1[0x11] + (uint)(uVar1 < uVar2);
  }
  if ((uVar3 != 0) && (0x7f < uVar3 + param_3)) {
    memcpy((void *)((int)param_1 + uVar3 + 0x50),param_2,0x80 - uVar3);
    param_2 = (uint *)((int)param_2 + (0x80 - uVar3));
    param_3 = (uVar3 + param_3) - 0x80;
    FUN_100203d0(param_1,param_1 + 0x14);
    uVar3 = 0;
  }
  if (((uint)param_2 & 7) == 0) {
    if (0x7f < param_3) {
      uVar1 = param_3 >> 7;
      do {
        FUN_100203d0(param_1,param_2);
        param_2 = param_2 + 0x20;
        uVar1 = uVar1 - 1;
        param_3 = param_3 - 0x80;
      } while (uVar1 != 0);
    }
  }
  else if (0x7f < param_3) {
    uVar1 = param_3 >> 7;
    do {
      memcpy(param_1 + 0x14,param_2,0x80);
      FUN_100203d0(param_1,param_1 + 0x14);
      param_2 = param_2 + 0x20;
      uVar1 = uVar1 - 1;
      param_3 = param_3 - 0x80;
    } while (uVar1 != 0);
  }
  if (param_3 != 0) {
    memcpy((void *)((int)param_1 + uVar3 + 0x50),param_2,param_3);
  }
  return;
}



/* 10023f64 FUN_10023f64 */

/* Boundary evidence: original MIPS .pdata 10023f64..100241df. Semantic name remains unreviewed. */

void FUN_10023f64(uint *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_b8 [4];
  undefined1 local_a8 [144];
  
  uVar7 = -(param_1[0x12] & 0x7f) + 0x80;
  if (uVar7 < 0x11) {
    uVar7 = -(param_1[0x12] & 0x7f) + 0x100;
  }
  memset(local_a8,0,uVar7 - 0x10);
  uVar1 = param_1[0x12];
  uVar4 = param_1[0x13];
  local_b8[2] = uVar1 << 3;
  local_a8[0] = 0x80;
  local_b8[3] = uVar4 << 3 | uVar1 >> 0x1d;
  local_b8[0] = param_1[0x10] << 3 | uVar4 << 3 | uVar1 >> 0x1d;
  local_b8[1] = param_1[0x11] << 3 | param_1[0x10] >> 0x1d | uVar4 >> 0x1d;
  puVar2 = local_b8;
  iVar5 = 2;
  do {
    uVar1 = puVar2[1];
    uVar6 = *puVar2;
    uVar4 = (uVar1 >> 8 ^ uVar1 << 8) & 0xff00ff ^ uVar1 << 8;
    uVar1 = (uVar6 >> 8 ^ (uVar6 << 8 | uVar1 >> 0x18)) & 0xff00ff ^ (uVar6 << 8 | uVar1 >> 0x18);
    *(uint *)(uVar7 + (int)puVar2) = uVar4 >> 0x10 ^ uVar4 << 0x10;
    ((uint *)(uVar7 + (int)puVar2))[1] = (uVar1 ^ uVar4) >> 0x10 ^ (uVar1 << 0x10 | uVar4 >> 0x10);
    iVar5 = iVar5 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar5 != 0);
  FUN_10023dc8(param_1,(uint *)local_a8,uVar7);
  iVar5 = 8;
  puVar2 = param_1;
  do {
    uVar7 = puVar2[1];
    uVar4 = *puVar2;
    uVar1 = (uVar7 >> 8 ^ uVar7 << 8) & 0xff00ff ^ uVar7 << 8;
    uVar7 = (uVar4 >> 8 ^ (uVar4 << 8 | uVar7 >> 0x18)) & 0xff00ff ^ (uVar4 << 8 | uVar7 >> 0x18);
    puVar3 = (uint *)((param_2 - (int)param_1) + (int)puVar2);
    *puVar3 = uVar1 >> 0x10 ^ uVar1 << 0x10;
    puVar3[1] = (uVar7 ^ uVar1) >> 0x10 ^ (uVar7 << 0x10 | uVar1 >> 0x10);
    iVar5 = iVar5 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar5 != 0);
  FUN_100202fc(param_1);
  return;
}



/* 100241e0 FUN_100241e0 */

/* Boundary evidence: original MIPS .pdata 100241e0..1002445b. Semantic name remains unreviewed. */

void FUN_100241e0(uint *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_b8 [4];
  undefined1 local_a8 [144];
  
  uVar7 = -(param_1[0x12] & 0x7f) + 0x80;
  if (uVar7 < 0x11) {
    uVar7 = -(param_1[0x12] & 0x7f) + 0x100;
  }
  memset(local_a8,0,uVar7 - 0x10);
  uVar1 = param_1[0x12];
  uVar4 = param_1[0x13];
  local_b8[2] = uVar1 << 3;
  local_a8[0] = 0x80;
  local_b8[3] = uVar4 << 3 | uVar1 >> 0x1d;
  local_b8[0] = param_1[0x10] << 3 | uVar4 << 3 | uVar1 >> 0x1d;
  local_b8[1] = param_1[0x11] << 3 | param_1[0x10] >> 0x1d | uVar4 >> 0x1d;
  puVar2 = local_b8;
  iVar5 = 2;
  do {
    uVar1 = puVar2[1];
    uVar6 = *puVar2;
    uVar4 = (uVar1 >> 8 ^ uVar1 << 8) & 0xff00ff ^ uVar1 << 8;
    uVar1 = (uVar6 >> 8 ^ (uVar6 << 8 | uVar1 >> 0x18)) & 0xff00ff ^ (uVar6 << 8 | uVar1 >> 0x18);
    *(uint *)(uVar7 + (int)puVar2) = uVar4 >> 0x10 ^ uVar4 << 0x10;
    ((uint *)(uVar7 + (int)puVar2))[1] = (uVar1 ^ uVar4) >> 0x10 ^ (uVar1 << 0x10 | uVar4 >> 0x10);
    iVar5 = iVar5 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar5 != 0);
  FUN_10023dc8(param_1,(uint *)local_a8,uVar7);
  iVar5 = 6;
  puVar2 = param_1;
  do {
    uVar7 = puVar2[1];
    uVar4 = *puVar2;
    uVar1 = (uVar7 >> 8 ^ uVar7 << 8) & 0xff00ff ^ uVar7 << 8;
    uVar7 = (uVar4 >> 8 ^ (uVar4 << 8 | uVar7 >> 0x18)) & 0xff00ff ^ (uVar4 << 8 | uVar7 >> 0x18);
    puVar3 = (uint *)((param_2 - (int)param_1) + (int)puVar2);
    *puVar3 = uVar1 >> 0x10 ^ uVar1 << 0x10;
    puVar3[1] = (uVar7 ^ uVar1) >> 0x10 ^ (uVar7 << 0x10 | uVar1 >> 0x10);
    iVar5 = iVar5 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar5 != 0);
  FUN_100202fc(param_1);
  return;
}



/* 1002445c FUN_1002445c */

undefined4 FUN_1002445c(int *param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  
  *param_1 = param_4;
  uVar9 = (param_4 + 1) * 2;
  uVar10 = param_3 + 3 >> 2;
  if (((param_2 & 3) == 0) && ((param_3 & 3) == 0)) {
    param_1[1] = -0x481eae9d;
    if (uVar9 != 1) {
      piVar2 = param_1 + 2;
      iVar4 = uVar9 - 1;
      do {
        *piVar2 = piVar2[-1] + -0x61c88647;
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 1;
      } while (iVar4 != 0);
    }
    uVar1 = uVar9;
    if ((int)uVar9 < (int)uVar10) {
      uVar1 = uVar10;
    }
    iVar4 = 0;
    uVar7 = 0;
    uVar5 = 0;
    if (0 < (int)(uVar1 * 3)) {
      do {
        if (uVar9 == 0) {
          trap(0x1c00);
        }
        if ((uVar9 == 0xffffffff) && (iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        uVar5 = param_1[iVar4 % (int)uVar9 + 1] + uVar7 + uVar5;
        uVar5 = uVar5 >> 0x1d | uVar5 * 8;
        param_1[iVar4 % (int)uVar9 + 1] = uVar5;
        uVar6 = uVar7 + uVar5 & 0x1f;
        if (uVar10 == 0) {
          trap(0x1c00);
        }
        if ((uVar10 == 0xffffffff) && (iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        puVar8 = (uint *)((iVar4 % (int)uVar10) * 4 + param_2);
        uVar7 = *puVar8 + uVar7 + uVar5;
        uVar7 = uVar7 >> (0x20 - uVar6 & 0x1f) | uVar7 << uVar6;
        iVar4 = iVar4 + 1;
        *puVar8 = uVar7;
      } while (iVar4 < (int)(uVar1 * 3));
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 100245cc FUN_100245cc */

void FUN_100245cc(int *param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = param_1[1] + *param_3;
  uVar2 = param_3[1] + param_1[2];
  piVar4 = param_1 + 3;
  for (iVar3 = *param_1; iVar3 != 0; iVar3 = iVar3 + -1) {
    uVar1 = ((uVar2 ^ uVar1) >> (0x20 - (uVar2 & 0x1f) & 0x1f) | (uVar2 ^ uVar1) << (uVar2 & 0x1f))
            + *piVar4;
    uVar2 = ((uVar2 ^ uVar1) >> (0x20 - (uVar1 & 0x1f) & 0x1f) | (uVar2 ^ uVar1) << (uVar1 & 0x1f))
            + piVar4[1];
    piVar4 = piVar4 + 2;
  }
  *param_2 = uVar1;
  param_2[1] = uVar2;
  return;
}



/* 1002465c FUN_1002465c */

void FUN_1002465c(int *param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar3 = *param_1;
  piVar4 = param_1 + iVar3 * 2 + 3;
  uVar2 = *param_3;
  uVar1 = param_3[1];
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    piVar5 = piVar4 + -1;
    piVar4 = piVar4 + -2;
    uVar1 = (uVar1 - *piVar5 << (0x20 - (uVar2 & 0x1f) & 0x1f) | uVar1 - *piVar5 >> (uVar2 & 0x1f))
            ^ uVar2;
    uVar2 = (uVar2 - *piVar4 << (0x20 - (uVar1 & 0x1f) & 0x1f) | uVar2 - *piVar4 >> (uVar1 & 0x1f))
            ^ uVar1;
  }
  iVar3 = piVar4[-1];
  *param_2 = uVar2 - piVar4[-2];
  param_2[1] = uVar1 - iVar3;
  return;
}



/* 100246ec FUN_100246ec */

/* Boundary evidence: original MIPS .pdata 100246ec..1002472f. Semantic name remains unreviewed. */

void FUN_100246ec(uint *param_1,uint *param_2,int *param_3,int param_4)

{
  if (param_4 == 1) {
    FUN_100245cc(param_3,param_1,(int *)param_2);
  }
  else {
    FUN_1002465c(param_3,(int *)param_1,param_2);
  }
  return;
}



/* 10024730 FUN_10024730 */

/* Boundary evidence: original MIPS .pdata 10024730..10024ab3. Semantic name remains unreviewed. */

void FUN_10024730(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte abStack_4c [4];
  undefined4 local_48;
  uint local_44 [2];
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  undefined4 local_38;
  uint local_34 [3];
  
  iVar9 = param_3 + -6;
  iVar1 = param_3 + -7;
  if (-1 < iVar1) {
    puVar2 = local_44 + param_3 + -8;
    do {
      iVar1 = iVar1 + -1;
      *puVar2 = *(uint *)((param_1 - (int)&local_48) + (int)puVar2);
      puVar2 = puVar2 + -1;
    } while (-1 < iVar1);
  }
  iVar11 = 0;
  iVar10 = 0;
  iVar1 = 0;
  if (0 < iVar9) {
    iVar7 = 0;
    do {
      if (param_3 + 1 <= iVar11) break;
      if (iVar1 < iVar9) {
        puVar2 = local_44 + iVar1 + -1;
        do {
          if (3 < iVar10) break;
          iVar1 = iVar1 + 1;
          *(uint *)((iVar7 + iVar10) * 4 + param_2) = *puVar2;
          puVar2 = puVar2 + 1;
          iVar10 = iVar10 + 1;
        } while (iVar1 < iVar9);
      }
      if (iVar10 == 4) {
        iVar11 = iVar11 + 1;
        iVar7 = iVar7 + 4;
        iVar10 = 0;
      }
    } while (iVar1 < iVar9);
  }
  iVar1 = param_3 + 1;
  if (iVar11 < iVar1) {
    iVar7 = iVar9 * 4;
    puVar3 = &DAT_100071c8;
    do {
      local_48._0_1_ = (&DAT_10003fc8)[abStack_4c[iVar7 + 1]] ^ (byte)local_48;
      local_48._1_1_ = (&DAT_10003fc8)[abStack_4c[iVar7 + 2]] ^ local_48._1_1_;
      local_48._2_1_ = (&DAT_10003fc8)[abStack_4c[iVar7 + 3]] ^ local_48._2_1_;
      uVar4 = *puVar3;
      local_48._3_1_ = (&DAT_10003fc8)[abStack_4c[iVar7]] ^ local_48._3_1_;
      puVar3 = puVar3 + 1;
      local_48._0_1_ = (byte)local_48 ^ (byte)uVar4;
      if (iVar9 == 8) {
        iVar8 = 3;
        puVar2 = &local_48;
        do {
          puVar5 = puVar2 + 1;
          *puVar5 = *puVar2 ^ *puVar5;
          iVar8 = iVar8 + -1;
          puVar2 = puVar5;
        } while (iVar8 != 0);
        local_38._0_1_ = (&DAT_10003fc8)[local_3c] ^ (byte)local_38;
        local_38._1_1_ = (&DAT_10003fc8)[local_3b] ^ local_38._1_1_;
        local_38._2_1_ = (&DAT_10003fc8)[local_3a] ^ local_38._2_1_;
        iVar8 = 3;
        local_38._3_1_ = (&DAT_10003fc8)[local_39] ^ local_38._3_1_;
        puVar2 = &local_38;
        do {
          puVar5 = puVar2 + 1;
          *puVar5 = *puVar2 ^ *puVar5;
          iVar8 = iVar8 + -1;
          puVar2 = puVar5;
        } while (iVar8 != 0);
      }
      else {
        puVar2 = &local_48;
        iVar8 = param_3 + -7;
        if (1 < iVar9) {
          do {
            puVar5 = puVar2 + 1;
            *puVar5 = *puVar2 ^ *puVar5;
            iVar8 = iVar8 + -1;
            puVar2 = puVar5;
          } while (iVar8 != 0);
        }
      }
      iVar8 = 0;
      if (0 < iVar9) {
        iVar6 = iVar11 << 2;
        do {
          if (iVar1 <= iVar11) {
            return;
          }
          if (iVar8 < iVar9) {
            puVar2 = local_44 + iVar8 + -1;
            do {
              if (3 < iVar10) break;
              iVar8 = iVar8 + 1;
              *(uint *)((iVar6 + iVar10) * 4 + param_2) = *puVar2;
              puVar2 = puVar2 + 1;
              iVar10 = iVar10 + 1;
            } while (iVar8 < iVar9);
          }
          if (iVar10 == 4) {
            iVar11 = iVar11 + 1;
            iVar6 = iVar6 + 4;
            iVar10 = 0;
          }
        } while (iVar8 < iVar9);
      }
    } while (iVar11 < iVar1);
  }
  return;
}



/* 10024ab4 FUN_10024ab4 */

void FUN_10024ab4(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  
  if (1 < param_2) {
    iVar2 = param_2 + -1;
    do {
      puVar1 = param_1 + 4;
      *puVar1 = *(uint *)(&DAT_10006dc8 + (uint)*(byte *)((int)param_1 + 0x13) * 4) ^
                *(uint *)(&DAT_100065c8 + (uint)*(byte *)((int)param_1 + 0x11) * 4) ^
                *(uint *)(&DAT_100061c8 + (uint)(byte)*puVar1 * 4) ^
                *(uint *)(&DAT_100069c8 + (uint)*(byte *)((int)param_1 + 0x12) * 4);
      param_1[5] = *(uint *)(&DAT_10006dc8 + (uint)*(byte *)((int)param_1 + 0x17) * 4) ^
                   *(uint *)(&DAT_100065c8 + (uint)*(byte *)((int)param_1 + 0x15) * 4) ^
                   *(uint *)(&DAT_100061c8 + (uint)(byte)param_1[5] * 4) ^
                   *(uint *)(&DAT_100069c8 + (uint)*(byte *)((int)param_1 + 0x16) * 4);
      param_1[6] = *(uint *)(&DAT_10006dc8 + (uint)*(byte *)((int)param_1 + 0x1b) * 4) ^
                   *(uint *)(&DAT_100069c8 + (uint)*(byte *)((int)param_1 + 0x1a) * 4) ^
                   *(uint *)(&DAT_100065c8 + (uint)*(byte *)((int)param_1 + 0x19) * 4) ^
                   *(uint *)(&DAT_100061c8 + (uint)(byte)param_1[6] * 4);
      param_1[7] = *(uint *)(&DAT_10006dc8 + (uint)*(byte *)((int)param_1 + 0x1f) * 4) ^
                   *(uint *)(&DAT_100069c8 + (uint)*(byte *)((int)param_1 + 0x1e) * 4) ^
                   *(uint *)(&DAT_100065c8 + (uint)*(byte *)((int)param_1 + 0x1d) * 4) ^
                   *(uint *)(&DAT_100061c8 + (uint)(byte)param_1[7] * 4);
      iVar2 = iVar2 + -1;
      param_1 = puVar1;
    } while (iVar2 != 0);
  }
  return;
}



/* 10024c48 FUN_10024c48 */

/* Boundary evidence: original MIPS .pdata 10024c48..100251cb. Semantic name remains unreviewed. */

void FUN_10024c48(uint *param_1,uint *param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1[3] ^ param_3[3];
  uVar2 = *param_1 ^ *param_3;
  uVar5 = param_1[2] ^ param_3[2];
  uVar4 = param_1[1] ^ param_3[1];
  *param_2 = *(uint *)(&DAT_10004cc8 + (uVar6 >> 0x18) * 4) ^
             *(uint *)(&DAT_100048c8 + (uVar5 >> 0x10 & 0xff) * 4) ^
             *(uint *)(&DAT_100044c8 + (uVar4 >> 8 & 0xff) * 4) ^
             *(uint *)(&DAT_100040c8 + (uVar2 & 0xff) * 4);
  param_2[1] = *(uint *)(&DAT_10004cc8 + (uVar2 >> 0x18) * 4) ^
               *(uint *)(&DAT_100048c8 + (uVar6 >> 0x10 & 0xff) * 4) ^
               *(uint *)(&DAT_100044c8 + (uVar5 >> 8 & 0xff) * 4) ^
               *(uint *)(&DAT_100040c8 + (uVar4 & 0xff) * 4);
  param_2[2] = *(uint *)(&DAT_10004cc8 + (uVar4 >> 0x18) * 4) ^
               *(uint *)(&DAT_100048c8 + (uVar2 >> 0x10 & 0xff) * 4) ^
               *(uint *)(&DAT_100044c8 + (uVar6 >> 8 & 0xff) * 4) ^
               *(uint *)(&DAT_100040c8 + (uVar5 & 0xff) * 4);
  param_2[3] = *(uint *)(&DAT_10004cc8 + (uVar5 >> 0x18) * 4) ^
               *(uint *)(&DAT_100048c8 + (uVar4 >> 0x10 & 0xff) * 4) ^
               *(uint *)(&DAT_100044c8 + (uVar2 >> 8 & 0xff) * 4) ^
               *(uint *)(&DAT_100040c8 + (uVar6 & 0xff) * 4);
  if (1 < param_4 + -1) {
    iVar3 = param_4 + -2;
    puVar1 = param_3;
    do {
      uVar4 = *param_2 ^ puVar1[4];
      uVar6 = puVar1[5] ^ param_2[1];
      uVar5 = puVar1[7] ^ param_2[3];
      uVar2 = param_2[2] ^ puVar1[6];
      *param_2 = *(uint *)(&DAT_10004cc8 + (uVar5 >> 0x18) * 4) ^
                 *(uint *)(&DAT_100048c8 + (uVar2 >> 0x10 & 0xff) * 4) ^
                 *(uint *)(&DAT_100044c8 + (uVar6 >> 8 & 0xff) * 4) ^
                 *(uint *)(&DAT_100040c8 + (uVar4 & 0xff) * 4);
      param_2[1] = *(uint *)(&DAT_10004cc8 + (uVar4 >> 0x18) * 4) ^
                   *(uint *)(&DAT_100048c8 + (uVar5 >> 0x10 & 0xff) * 4) ^
                   *(uint *)(&DAT_100044c8 + (uVar2 >> 8 & 0xff) * 4) ^
                   *(uint *)(&DAT_100040c8 + (uVar6 & 0xff) * 4);
      param_2[2] = *(uint *)(&DAT_10004cc8 + (uVar6 >> 0x18) * 4) ^
                   *(uint *)(&DAT_100048c8 + (uVar4 >> 0x10 & 0xff) * 4) ^
                   *(uint *)(&DAT_100044c8 + (uVar5 >> 8 & 0xff) * 4) ^
                   *(uint *)(&DAT_100040c8 + (uVar2 & 0xff) * 4);
      iVar3 = iVar3 + -1;
      param_2[3] = *(uint *)(&DAT_10004cc8 + (uVar2 >> 0x18) * 4) ^
                   *(uint *)(&DAT_100048c8 + (uVar6 >> 0x10 & 0xff) * 4) ^
                   *(uint *)(&DAT_100044c8 + (uVar4 >> 8 & 0xff) * 4) ^
                   *(uint *)(&DAT_100040c8 + (uVar5 & 0xff) * 4);
      puVar1 = puVar1 + 4;
    } while (iVar3 != 0);
  }
  puVar1 = param_3 + param_4 * 4;
  uVar2 = puVar1[-4] ^ *param_2;
  uVar4 = puVar1[-3] ^ param_2[1];
  uVar5 = puVar1[-2] ^ param_2[2];
  uVar6 = puVar1[-1] ^ param_2[3];
  *(undefined *)param_2 = (&DAT_100040c9)[(uVar2 & 0xff) * 4];
  *(undefined *)((int)param_2 + 1) = (&DAT_100040c9)[(uVar4 >> 8 & 0xff) * 4];
  *(undefined *)((int)param_2 + 2) = (&DAT_100040c9)[(uVar5 >> 0x10 & 0xff) * 4];
  *(undefined *)((int)param_2 + 3) = (&DAT_100040c9)[(uVar6 >> 0x18) * 4];
  *(undefined *)(param_2 + 1) = (&DAT_100040c9)[(uVar4 & 0xff) * 4];
  *(undefined *)((int)param_2 + 5) = (&DAT_100040c9)[(uVar5 >> 8 & 0xff) * 4];
  *(undefined *)((int)param_2 + 6) = (&DAT_100040c9)[(uVar6 >> 0x10 & 0xff) * 4];
  *(undefined *)((int)param_2 + 7) = (&DAT_100040c9)[(uVar2 >> 0x18) * 4];
  *(undefined *)(param_2 + 2) = (&DAT_100040c9)[(uVar5 & 0xff) * 4];
  *(undefined *)((int)param_2 + 9) = (&DAT_100040c9)[(uVar6 >> 8 & 0xff) * 4];
  *(undefined *)((int)param_2 + 10) = (&DAT_100040c9)[(uVar2 >> 0x10 & 0xff) * 4];
  *(undefined *)((int)param_2 + 0xb) = (&DAT_100040c9)[(uVar4 >> 0x18) * 4];
  *(undefined *)(param_2 + 3) = (&DAT_100040c9)[(uVar6 & 0xff) * 4];
  *(undefined *)((int)param_2 + 0xd) = (&DAT_100040c9)[(uVar2 >> 8 & 0xff) * 4];
  *(undefined *)((int)param_2 + 0xe) = (&DAT_100040c9)[(uVar4 >> 0x10 & 0xff) * 4];
  *(undefined *)((int)param_2 + 0xf) = (&DAT_100040c9)[(uVar5 >> 0x18) * 4];
  *param_2 = *param_2 ^ *puVar1;
  param_2[1] = puVar1[1] ^ param_2[1];
  param_2[2] = puVar1[2] ^ param_2[2];
  param_2[3] = puVar1[3] ^ param_2[3];
  return;
}



/* 100251cc FUN_100251cc */

/* Boundary evidence: original MIPS .pdata 100251cc..100256db. Semantic name remains unreviewed. */

void FUN_100251cc(uint *param_1,uint *param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = param_3 + param_4 * 4;
  uVar5 = puVar2[1] ^ param_1[1];
  uVar1 = puVar2[3] ^ param_1[3];
  uVar6 = puVar2[2] ^ param_1[2];
  uVar3 = *param_1 ^ *puVar2;
  *param_2 = *(uint *)(&DAT_10005cc8 + (uVar5 >> 0x18) * 4) ^
             *(uint *)(&DAT_100058c8 + (uVar6 >> 0x10 & 0xff) * 4) ^
             *(uint *)(&DAT_100054c8 + (uVar1 >> 8 & 0xff) * 4) ^
             *(uint *)(&DAT_100050c8 + (uVar3 & 0xff) * 4);
  param_2[1] = *(uint *)(&DAT_10005cc8 + (uVar6 >> 0x18) * 4) ^
               *(uint *)(&DAT_100058c8 + (uVar1 >> 0x10 & 0xff) * 4) ^
               *(uint *)(&DAT_100054c8 + (uVar3 >> 8 & 0xff) * 4) ^
               *(uint *)(&DAT_100050c8 + (uVar5 & 0xff) * 4);
  param_2[2] = *(uint *)(&DAT_10005cc8 + (uVar1 >> 0x18) * 4) ^
               *(uint *)(&DAT_100058c8 + (uVar3 >> 0x10 & 0xff) * 4) ^
               *(uint *)(&DAT_100054c8 + (uVar5 >> 8 & 0xff) * 4) ^
               *(uint *)(&DAT_100050c8 + (uVar6 & 0xff) * 4);
  param_2[3] = *(uint *)(&DAT_10005cc8 + (uVar3 >> 0x18) * 4) ^
               *(uint *)(&DAT_100058c8 + (uVar5 >> 0x10 & 0xff) * 4) ^
               *(uint *)(&DAT_100054c8 + (uVar6 >> 8 & 0xff) * 4) ^
               *(uint *)(&DAT_100050c8 + (uVar1 & 0xff) * 4);
  if (1 < param_4 + -1) {
    puVar2 = param_3 + (param_4 + -1) * 4;
    iVar4 = param_4 + -2;
    do {
      uVar3 = *puVar2 ^ *param_2;
      uVar6 = puVar2[1] ^ param_2[1];
      uVar1 = puVar2[2] ^ param_2[2];
      uVar5 = puVar2[3] ^ param_2[3];
      *param_2 = *(uint *)(&DAT_10005cc8 + (uVar6 >> 0x18) * 4) ^
                 *(uint *)(&DAT_100058c8 + (uVar1 >> 0x10 & 0xff) * 4) ^
                 *(uint *)(&DAT_100054c8 + (uVar5 >> 8 & 0xff) * 4) ^
                 *(uint *)(&DAT_100050c8 + (uVar3 & 0xff) * 4);
      param_2[1] = *(uint *)(&DAT_10005cc8 + (uVar1 >> 0x18) * 4) ^
                   *(uint *)(&DAT_100058c8 + (uVar5 >> 0x10 & 0xff) * 4) ^
                   *(uint *)(&DAT_100054c8 + (uVar3 >> 8 & 0xff) * 4) ^
                   *(uint *)(&DAT_100050c8 + (uVar6 & 0xff) * 4);
      param_2[2] = *(uint *)(&DAT_10005cc8 + (uVar5 >> 0x18) * 4) ^
                   *(uint *)(&DAT_100058c8 + (uVar3 >> 0x10 & 0xff) * 4) ^
                   *(uint *)(&DAT_100054c8 + (uVar6 >> 8 & 0xff) * 4) ^
                   *(uint *)(&DAT_100050c8 + (uVar1 & 0xff) * 4);
      puVar2 = puVar2 + -4;
      iVar4 = iVar4 + -1;
      param_2[3] = *(uint *)(&DAT_10005cc8 + (uVar3 >> 0x18) * 4) ^
                   *(uint *)(&DAT_100058c8 + (uVar6 >> 0x10 & 0xff) * 4) ^
                   *(uint *)(&DAT_100054c8 + (uVar1 >> 8 & 0xff) * 4) ^
                   *(uint *)(&DAT_100050c8 + (uVar5 & 0xff) * 4);
    } while (iVar4 != 0);
  }
  uVar5 = param_3[4] ^ *param_2;
  uVar1 = param_3[6] ^ param_2[2];
  uVar3 = param_3[7] ^ param_2[3];
  uVar6 = param_3[5] ^ param_2[1];
  *(undefined *)param_2 = (&DAT_100060c8)[uVar5 & 0xff];
  *(undefined *)((int)param_2 + 1) = (&DAT_100060c8)[uVar3 >> 8 & 0xff];
  *(undefined *)((int)param_2 + 2) = (&DAT_100060c8)[uVar1 >> 0x10 & 0xff];
  *(undefined *)((int)param_2 + 3) = (&DAT_100060c8)[uVar6 >> 0x18];
  *(undefined *)(param_2 + 1) = (&DAT_100060c8)[uVar6 & 0xff];
  *(undefined *)((int)param_2 + 5) = (&DAT_100060c8)[uVar5 >> 8 & 0xff];
  *(undefined *)((int)param_2 + 6) = (&DAT_100060c8)[uVar3 >> 0x10 & 0xff];
  *(undefined *)((int)param_2 + 7) = (&DAT_100060c8)[uVar1 >> 0x18];
  *(undefined *)(param_2 + 2) = (&DAT_100060c8)[uVar1 & 0xff];
  *(undefined *)((int)param_2 + 9) = (&DAT_100060c8)[uVar6 >> 8 & 0xff];
  *(undefined *)((int)param_2 + 10) = (&DAT_100060c8)[uVar5 >> 0x10 & 0xff];
  *(undefined *)((int)param_2 + 0xb) = (&DAT_100060c8)[uVar3 >> 0x18];
  *(undefined *)(param_2 + 3) = (&DAT_100060c8)[uVar3 & 0xff];
  *(undefined *)((int)param_2 + 0xd) = (&DAT_100060c8)[uVar1 >> 8 & 0xff];
  *(undefined *)((int)param_2 + 0xe) = (&DAT_100060c8)[uVar6 >> 0x10 & 0xff];
  *(undefined *)((int)param_2 + 0xf) = (&DAT_100060c8)[uVar5 >> 0x18];
  *param_2 = *param_2 ^ *param_3;
  param_2[1] = param_3[1] ^ param_2[1];
  param_2[2] = param_3[2] ^ param_2[2];
  param_2[3] = param_3[3] ^ param_2[3];
  return;
}



/* 100256dc FUN_100256dc */

/* Boundary evidence: original MIPS .pdata 100256dc..10025727. Semantic name remains unreviewed. */

void FUN_100256dc(uint *param_1,uint *param_2,int *param_3,int param_4)

{
  if (param_4 == 1) {
    FUN_10024c48(param_2,param_1,(uint *)(param_3 + 1),*param_3);
  }
  else {
    FUN_100251cc(param_2,param_1,(uint *)(param_3 + 0x3d),*param_3);
  }
  return;
}



/* 10025728 FUN_10025728 */

/* Boundary evidence: original MIPS .pdata 10025728..10025797. Semantic name remains unreviewed. */

void FUN_10025728(int *param_1,int param_2,int param_3)

{
  *param_1 = param_3;
  FUN_10024730(param_2,(int)(param_1 + 1),param_3);
  memcpy(param_1 + 0x3d,param_1 + 1,0xf0);
  FUN_10024ab4((uint *)(param_1 + 0x3d),param_3);
  return;
}



/* 10025798 FUN_10025798 */

undefined4 FUN_10025798(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = *param_1;
      *param_1 = iVar1 + 1;
      if (iVar1 + 1 != 0) {
        return 0;
      }
      uVar2 = uVar2 + 1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_2);
  }
  return 1;
}



/* 100257d8 FUN_100257d8 */

/* Boundary evidence: original MIPS .pdata 100257d8..1002581f. Semantic name remains unreviewed. */

void FUN_100257d8(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  *param_1 = param_2;
  if ((param_2 & 0x80000000) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffff;
  }
  memset(param_1 + 1,uVar1 & 0xff,(param_3 + -1) * 4);
  return;
}



/* 10025820 FUN_10025820 */

int FUN_10025820(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 != 0) {
    piVar1 = (int *)(param_2 * 4 + param_1);
    do {
      piVar1 = piVar1 + -1;
      if (*piVar1 != 0) {
        return param_2;
      }
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 1;
}



/* 10025860 FUN_10025860 */

int FUN_10025860(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 != 0) {
    piVar1 = (int *)(param_2 * 4 + param_1);
    do {
      piVar1 = piVar1 + -1;
      param_2 = param_2 + -1;
      if (*piVar1 != 0) goto LAB_1002588c;
    } while (param_2 != 0);
  }
  param_2 = -1;
LAB_1002588c:
  if (param_2 == -1) {
    iVar2 = 0;
  }
  else {
    iVar2 = (param_2 + 1) * 0x20;
    for (uVar3 = *(uint *)(param_2 * 4 + param_1); (uVar3 & 0x80000000) == 0; uVar3 = uVar3 << 1) {
      iVar2 = iVar2 + -1;
    }
  }
  return iVar2;
}



/* 100258e0 FUN_100258e0 */

/* Boundary evidence: original MIPS .pdata 100258e0..10025aeb. Semantic name remains unreviewed. */

void FUN_100258e0(uint *param_1,int *param_2,int *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_4 != 0) {
    piVar3 = param_3 + param_4;
    uVar1 = param_4;
    do {
      piVar3 = piVar3 + -1;
      if (*piVar3 != 0) goto LAB_10025954;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  uVar1 = 1;
LAB_10025954:
  if (uVar1 < 2) {
    if (*param_3 != 0) {
      piVar3 = param_2;
      if (*param_3 == 1) goto LAB_10025998;
      goto LAB_100259ac;
    }
LAB_1002596c:
    memset(param_1,0,param_4 << 2);
  }
  else {
LAB_100259ac:
    iVar4 = *param_2;
    if ((iVar4 == 0) || (iVar4 == 1)) {
      if (param_4 != 0) {
        piVar3 = param_2 + param_4;
        uVar2 = param_4;
        do {
          piVar3 = piVar3 + -1;
          if (*piVar3 != 0) goto LAB_100259f0;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      uVar2 = 1;
LAB_100259f0:
      if (uVar2 < 2) {
        if (iVar4 == 0) goto LAB_1002596c;
        piVar3 = param_3;
        if (iVar4 == 1) {
LAB_10025998:
          memcpy(param_1,piVar3,param_4 << 2);
          return;
        }
      }
    }
    memset(param_1,0,param_4 << 2);
    uVar7 = param_4 - uVar1;
    uVar2 = 0;
    if (uVar7 != 0) {
      puVar5 = param_1 + uVar1;
      puVar6 = param_1;
      uVar8 = uVar7;
      do {
        uVar2 = FUN_1001ebe4(puVar6,*(uint *)(((int)param_2 - (int)param_1) + (int)puVar6),
                             (int)param_3,uVar1);
        puVar6 = puVar6 + 1;
        uVar8 = uVar8 - 1;
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
        uVar2 = uVar7;
      } while (uVar8 != 0);
    }
    if (uVar2 < param_4) {
      puVar6 = param_1 + uVar2;
      do {
        FUN_1001ebe4(puVar6,*(uint *)((int)puVar6 + ((int)param_2 - (int)param_1)),(int)param_3,
                     param_4 - uVar2);
        uVar2 = uVar2 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar2 < param_4);
    }
  }
  return;
}



/* 10025aec FUN_10025aec */

undefined4 FUN_10025aec(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_3 + -1;
  if (-1 < iVar2) {
    puVar1 = (uint *)(iVar2 * 4 + param_2);
    do {
      uVar3 = *(uint *)((param_1 - param_2) + (int)puVar1);
      if (*puVar1 < uVar3) {
        return 1;
      }
      if (uVar3 < *puVar1) {
        return 0xffffffff;
      }
      iVar2 = iVar2 + -1;
      puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
  }
  return 0;
}



/* 10025b50 FUN_10025b50 */

/* Boundary evidence: original MIPS .pdata 10025b50..10025c23. Semantic name remains unreviewed. */

void FUN_10025b50(uint *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  memset(param_1,0,param_4 << 3);
  if (param_4 != 0) {
    piVar1 = (int *)(param_4 * 4 + param_3);
    iVar4 = param_4;
    do {
      piVar1 = piVar1 + -1;
      if (*piVar1 != 0) goto LAB_10025bc0;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  iVar4 = 1;
LAB_10025bc0:
  if (param_4 != 0) {
    puVar5 = param_1 + iVar4;
    iVar3 = param_2 - (int)param_1;
    do {
      uVar2 = FUN_1001ebe4(param_1,*(uint *)(iVar3 + (int)param_1),param_3,iVar4);
      param_1 = param_1 + 1;
      param_4 = param_4 + -1;
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
    } while (param_4 != 0);
  }
  return;
}



/* 10025c24 FUN_10025c24 */

/* Boundary evidence: original MIPS .pdata 10025c24..10025d27. Semantic name remains unreviewed. */

void FUN_10025c24(uint *param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  
  memset(param_1,0,param_3 << 3);
  if (param_3 != 0) {
    puVar4 = param_2 + param_3;
    do {
      puVar4 = puVar4 + -1;
      if (*puVar4 != 0) goto LAB_10025c94;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  param_3 = 1;
LAB_10025c94:
  iVar5 = param_3 + -1;
  puVar4 = param_1 + 1;
  if (iVar5 != 0) {
    iVar3 = iVar5 * 4;
    puVar1 = param_2;
    do {
      uVar2 = FUN_1001ebe4(puVar4,*puVar1,(int)(puVar1 + 1),iVar5);
      iVar5 = iVar5 + -1;
      *(undefined4 *)(iVar3 + (int)puVar4) = uVar2;
      iVar3 = iVar3 + -4;
      puVar4 = puVar4 + 2;
      puVar1 = puVar1 + 1;
    } while (iVar5 != 0);
  }
  FUN_1001eae8((int)param_1,(int)param_1,(int *)param_1,param_3 << 1);
  FUN_1001eccc(param_1,param_2,param_3);
  return;
}



/* 10025d28 FUN_10025d28 */

/* Boundary evidence: original MIPS .pdata 10025d28..10025df7. Semantic name remains unreviewed. */

uint FUN_10025d28(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_4 == 0) || (uVar3 = 0x80000000, (param_3 & 0x80000000) != 0)) {
    if (param_1 < param_3) {
      uVar3 = __ull_div(param_2,param_1,param_3,0);
      return uVar3;
    }
  }
  else if ((param_1 < param_3) || ((param_1 == param_3 && (param_2 < param_4)))) {
    uVar2 = 0;
    do {
      param_1 = param_1 << 1 | param_2 >> 0x1f;
      param_2 = param_2 * 2;
      if ((param_3 <= param_1) && ((param_1 != param_3 || (param_4 <= param_2)))) {
        bVar1 = param_2 < param_4;
        param_2 = param_2 - param_4;
        param_1 = (param_1 - param_3) - (uint)bVar1;
        uVar2 = uVar3 | uVar2;
      }
      uVar3 = uVar3 >> 1;
    } while (uVar3 != 0);
    return uVar2;
  }
  return 0xffffffff;
}



/* 10025df8 FUN_10025df8 */

/* Boundary evidence: original MIPS .pdata 10025df8..100260e7. Semantic name remains unreviewed. */

undefined4 FUN_10025df8(void *param_1,int *param_2,void *param_3,uint param_4,uint param_5)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *_Dst;
  int iVar7;
  uint *_Dst_00;
  int iVar8;
  uint *puVar9;
  size_t _Size;
  uint uVar10;
  
  if (param_4 != 0) {
    piVar1 = (int *)(param_4 * 4 + (int)param_1);
    do {
      piVar1 = piVar1 + -1;
      if (*piVar1 != 0) goto LAB_10025e68;
      param_4 = param_4 - 1;
    } while (param_4 != 0);
  }
  param_4 = 1;
LAB_10025e68:
  if (param_5 != 0) {
    piVar1 = param_2 + param_5;
    uVar10 = param_5;
    do {
      piVar1 = piVar1 + -1;
      if (*piVar1 != 0) goto LAB_10025e9c;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  uVar10 = 1;
LAB_10025e9c:
  if ((uVar10 < 2) && (*param_2 == 0)) {
LAB_10025f04:
    uVar3 = 0;
  }
  else {
    if (param_4 < uVar10) {
      memcpy(param_3,param_1,param_5 << 2);
    }
    else {
      puVar2 = (uint *)FUN_100269dc(0x40,(uVar10 * 2 + param_4 + 3) * 4);
      if (puVar2 == (uint *)0x0) goto LAB_10025f04;
      _Size = uVar10 * 4;
      _Dst = puVar2 + uVar10 + 1;
      _Dst_00 = _Dst + uVar10 + 1;
      memcpy(_Dst,param_2,_Size);
      _Dst[uVar10] = 0;
      memcpy(_Dst_00,param_1,param_4 * 4);
      iVar8 = param_4 - uVar10;
      _Dst_00[param_4] = 0;
      if (-1 < iVar8) {
        iVar7 = uVar10 + 1;
        puVar9 = _Dst_00 + iVar8;
        puVar6 = _Dst_00 + iVar8 + uVar10;
        do {
          if (uVar10 < 2) {
            uVar5 = 0;
          }
          else {
            uVar5 = param_2[uVar10 - 2];
          }
          uVar5 = FUN_10025d28(*puVar6,puVar6[-1],param_2[uVar10 - 1],uVar5);
          if (uVar5 == 0) {
            uVar5 = 1;
          }
          uVar5 = FUN_1001eb40(puVar2,uVar5,param_2,uVar10);
          puVar2[uVar10] = uVar5;
          iVar4 = FUN_10025aec((int)puVar2,(int)puVar9,iVar7);
          while (iVar4 == 1) {
            FUN_1001ea90((int)puVar2,(int)puVar2,_Dst,iVar7);
            iVar4 = FUN_10025aec((int)puVar2,(int)puVar9,iVar7);
          }
          FUN_1001ea90((int)puVar9,(int)puVar9,puVar2,iVar7);
          iVar4 = FUN_10025aec((int)puVar9,(int)_Dst,iVar7);
          if (-1 < iVar4) {
            iVar8 = iVar8 + 1;
            puVar6 = puVar6 + 1;
            puVar9 = puVar9 + 1;
          }
          iVar8 = iVar8 + -1;
          puVar6 = puVar6 + -1;
          puVar9 = puVar9 + -1;
        } while (-1 < iVar8);
      }
      memcpy(param_3,_Dst_00,_Size);
      memset((void *)(_Size + (int)param_3),0,(param_5 - uVar10) * 4);
      FUN_100269f8(puVar2);
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* 100260e8 FUN_100260e8 */

/* WARNING: Removing unreachable block (ram,0x100262dc) */
/* WARNING: Removing unreachable block (ram,0x10026478) */
/* WARNING: Removing unreachable block (ram,0x100262f4) */
/* Boundary evidence: original MIPS .pdata 100260e8..10026677. Semantic name remains unreviewed. */

undefined4
FUN_100260e8(void *param_1,void *param_2,void *param_3,void *param_4,uint param_5,uint param_6)

{
  int *_Dst;
  undefined4 uVar1;
  int *_Dst_00;
  int *_Dst_01;
  int *_Dst_02;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  size_t _Size;
  uint uVar6;
  int iVar7;
  uint *_Dst_03;
  int *_Dst_04;
  uint *puVar8;
  uint uVar9;
  uint *_Src;
  size_t _Size_00;
  int local_50;
  uint local_4c;
  
  uVar4 = param_6;
  if (param_6 <= param_5) {
    uVar4 = param_5;
  }
  uVar9 = uVar4 + 2;
  _Dst = (int *)FUN_100269dc(0x40,uVar9 * 0x24);
  if (_Dst == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    _Size_00 = uVar9 * 4;
    _Dst_00 = _Dst + uVar9;
    _Dst_04 = _Dst_00 + uVar9;
    _Dst_01 = _Dst_04 + uVar9;
    _Dst_02 = _Dst_01 + uVar9;
    puVar8 = (uint *)(_Dst_02 + uVar9 * 2);
    _Src = puVar8 + uVar9;
    memset(_Dst,0,_Size_00);
    memset(_Dst_04,0,_Size_00);
    memset(_Dst_02,0,_Size_00);
    memcpy(_Dst,param_3,param_5 << 2);
    memcpy(_Dst_00,_Dst,_Size_00);
    memcpy(_Dst_04,param_4,param_6 << 2);
    memcpy(_Dst_01,_Dst_04,_Size_00);
    iVar7 = uVar4 + 1;
    local_50 = iVar7;
    if (-1 < iVar7) {
      piVar2 = _Dst_04 + iVar7;
      do {
        if (*piVar2 != 0) {
          uVar3 = _Dst_04[local_50];
          if ((uVar3 & 0xff000000) == 0) {
            if ((uVar3 & 0xff0000) == 0) {
              iVar5 = 1;
              if ((uVar3 & 0xff00) == 0) {
                iVar5 = 0;
              }
            }
            else {
              iVar5 = 2;
            }
          }
          else {
            iVar5 = 3;
          }
          local_50 = local_50 * 4 + iVar5;
          break;
        }
        local_50 = local_50 + -1;
        piVar2 = piVar2 + -1;
      } while (-1 < local_50);
    }
    uVar3 = *(byte *)(local_50 + (int)_Dst_04) + 1;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    *puVar8 = 0x100 / uVar3;
    _Size = (uVar4 + 1) * 4;
    memset(puVar8 + 1,0,_Size);
    FUN_100258e0(_Src,(int *)puVar8,_Dst_04,uVar9);
    memcpy(_Dst_04,_Src,_Size_00);
    uVar4 = (uint)*(byte *)(local_50 + (int)_Dst_04);
    FUN_100258e0(_Src,(int *)puVar8,_Dst,uVar9);
    memcpy(_Dst,_Src,_Size_00);
    if (-1 < iVar7) {
      piVar2 = _Dst + iVar7;
      do {
        if (*piVar2 != 0) {
          uVar3 = _Dst[iVar7];
          if ((uVar3 & 0xff000000) == 0) {
            if ((uVar3 & 0xff0000) == 0) {
              iVar5 = 1;
              if ((uVar3 & 0xff00) == 0) {
                iVar5 = 0;
              }
            }
            else {
              iVar5 = 2;
            }
          }
          else {
            iVar5 = 3;
          }
          iVar7 = iVar7 * 4 + iVar5;
          break;
        }
        iVar7 = iVar7 + -1;
        piVar2 = piVar2 + -1;
      } while (-1 < iVar7);
    }
    iVar7 = iVar7 + 1;
    if (local_50 < iVar7) {
      uVar3 = (iVar7 - local_50) * 8;
      _Dst_03 = _Src + uVar9;
      do {
        uVar3 = uVar3 - 8;
        if (uVar4 == *(byte *)((int)_Dst + iVar7)) {
          local_4c = 0xff;
        }
        else {
          local_4c = CONCAT11(*(byte *)((int)_Dst + iVar7),*(undefined1 *)((int)_Dst + iVar7 + -1))
                     / uVar4;
          if (uVar4 == 0) {
            trap(0x1c00);
          }
        }
        *puVar8 = local_4c;
        memset(puVar8 + 1,0,_Size);
        FUN_100258e0(_Src,_Dst_04,(int *)puVar8,uVar9);
        memset(_Dst_03,0,_Size_00);
        _Dst_03[uVar3 >> 5] = 1 << (uVar3 & 0x1f);
        FUN_100258e0(puVar8,(int *)_Dst_03,(int *)_Src,uVar9);
        FUN_1001ea90((int)_Src,(int)_Dst,puVar8,uVar9);
        uVar6 = _Dst_03[-1];
        while ((uVar6 & 0x80000000) != 0) {
          FUN_100258e0(puVar8,(int *)_Dst_03,_Dst_04,uVar9);
          FUN_1001eae8((int)_Src,(int)_Src,(int *)puVar8,uVar9);
          local_4c = local_4c - 1;
          uVar6 = _Dst_03[-1];
        }
        memcpy(_Dst,_Src,_Size_00);
        *_Dst_03 = local_4c;
        if ((local_4c & 0x80000000) == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = 0xffff;
        }
        memset(_Dst_03 + 1,uVar6 & 0xff,_Size);
        memset(_Src,0,_Size_00);
        *_Src = 0x100;
        FUN_100258e0(puVar8,_Dst_02,(int *)_Src,uVar9);
        FUN_1001eae8((int)_Dst_02,(int)_Dst_03,(int *)puVar8,uVar9);
        iVar7 = iVar7 + -1;
      } while (local_50 < iVar7);
    }
    FUN_100258e0(puVar8,_Dst_01,_Dst_02,uVar9);
    FUN_1001ea90((int)_Src,(int)_Dst_00,puVar8,uVar9);
    memcpy(param_1,_Dst_02,param_5 << 2);
    memcpy(param_2,_Src,param_6 << 2);
    FUN_100269f8(_Dst);
    uVar1 = 1;
  }
  return uVar1;
}



/* 10026678 FUN_10026678 */

/* Boundary evidence: original MIPS .pdata 10026678..10026937. Semantic name remains unreviewed. */

undefined4
FUN_10026678(void *param_1,undefined4 *param_2,void *param_3,int *param_4,uint *param_5,uint param_6
            )

{
  int *_Dst;
  uint *_Src;
  uint uVar1;
  int *piVar2;
  uint *_Src_00;
  size_t _Size;
  uint *puVar3;
  uint *_Src_01;
  int *piVar4;
  int *_Dst_00;
  int *_Src_02;
  size_t _Size_00;
  
  _Size_00 = param_6 * 4;
  if (((param_4[param_6 - 1] != 0) || (param_5[param_6 - 1] != 0)) ||
     (_Dst = (int *)FUN_100269dc(0x40,param_6 << 5), _Dst == (int *)0x0)) {
    return 0;
  }
  _Src_02 = _Dst + param_6;
  _Dst_00 = _Src_02 + param_6;
  piVar4 = _Dst_00 + param_6;
  _Src = (uint *)(piVar4 + param_6 * 2);
  *param_2 = 1;
  _Size = (param_6 - 1) * 4;
  _Src_01 = _Src + param_6;
  puVar3 = _Src_01 + param_6;
  memset(param_2 + 1,0,_Size);
  memset(param_3,0,_Size_00);
  memcpy(param_1,param_4,_Size_00);
  memset(_Dst,0,_Size_00);
  *_Src_02 = 1;
  memset(_Src_02 + 1,0,_Size);
  _Src_00 = param_5;
  do {
    memcpy(_Dst_00,_Src_00,_Size_00);
    uVar1 = 0;
    piVar2 = _Dst_00;
    if (param_6 != 0) {
      do {
        if (*piVar2 != 0) break;
        uVar1 = uVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar1 < param_6);
    }
    if (uVar1 == param_6) {
      if ((param_2[param_6 - 1] & 0x80000000) != 0) {
        FUN_1001eae8((int)param_2,(int)param_2,(int *)param_5,param_6);
      }
      if ((*(uint *)((int)param_3 + (_Size_00 - 4)) & 0x80000000) != 0) {
        FUN_1001eae8((int)param_3,(int)param_3,param_4,param_6);
      }
      FUN_100269f8(_Dst);
      return 1;
    }
    FUN_100260e8(piVar4,piVar4 + param_6,param_1,_Dst_00,param_6,param_6);
    FUN_100258e0(_Src,_Dst,piVar4,param_6);
    FUN_100258e0(_Src_01,_Src_02,piVar4,param_6);
    FUN_100258e0(puVar3,_Dst_00,piVar4,param_6);
    FUN_1001ea90((int)_Src,(int)param_2,_Src,param_6);
    FUN_1001ea90((int)_Src_01,(int)param_3,_Src_01,param_6);
    FUN_1001ea90((int)puVar3,(int)param_1,puVar3,param_6);
    memcpy(param_2,_Dst,_Size_00);
    memcpy(param_3,_Src_02,_Size_00);
    memcpy(param_1,_Dst_00,_Size_00);
    memcpy(_Dst,_Src,_Size_00);
    memcpy(_Src_02,_Src_01,_Size_00);
    _Src_00 = puVar3;
  } while( true );
}



/* 10026938 FUN_10026938 */

void FUN_10026938(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (param_3 != 0) {
    puVar3 = (undefined1 *)(param_1 + 2);
    puVar2 = (undefined1 *)(param_2 + 2);
    do {
      param_3 = param_3 + -1;
      puVar3[-2] = puVar2[1];
      puVar3[-1] = *puVar2;
      *puVar3 = puVar2[-1];
      puVar1 = (undefined4 *)(puVar2 + -2);
      puVar2 = puVar2 + 4;
      puVar3[1] = (char)*puVar1;
      puVar3 = puVar3 + 4;
    } while (param_3 != 0);
  }
  return;
}



/* 10026988 FUN_10026988 */

void FUN_10026988(undefined4 *param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  
  if (param_2 != 0) {
    puVar1 = (undefined1 *)(param_3 + 2);
    do {
      *param_1 = CONCAT31(CONCAT21(CONCAT11(puVar1[-2],puVar1[-1]),*puVar1),puVar1[1]);
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
      puVar1 = puVar1 + 4;
    } while (param_2 != 0);
  }
  return;
}



/* 100269dc FUN_100269dc */

/* Boundary evidence: original MIPS .pdata 100269dc..100269f7. Semantic name remains unreviewed. */

void FUN_100269dc(undefined4 param_1,SIZE_T param_2)

{
  LocalAlloc(0x40,param_2);
  return;
}



/* 100269f8 FUN_100269f8 */

/* Boundary evidence: original MIPS .pdata 100269f8..10026a13. Semantic name remains unreviewed. */

void FUN_100269f8(HLOCAL param_1)

{
  LocalFree(param_1);
  return;
}



/* 10026a14 FUN_10026a14 */

/* Boundary evidence: original MIPS .pdata 10026a14..10026b83. Semantic name remains unreviewed. */

undefined4 FUN_10026a14(uint *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  HLOCAL pvVar3;
  size_t _Size;
  
  if (((param_3 != 0) && (_Size = param_3 * 4, param_2[param_3 - 1] != 0)) &&
     (uVar1 = FUN_100269dc(0x40,param_3 * 0x14 + 4), uVar1 != 0)) {
    param_1[1] = uVar1;
    param_1[2] = uVar1 + _Size;
    uVar1 = uVar1 + _Size + _Size;
    pvVar3 = (HLOCAL)(uVar1 + _Size);
    param_1[3] = uVar1;
    param_1[4] = (uint)pvVar3;
    memcpy((void *)param_1[1],param_2,_Size);
    uVar1 = *(uint *)(_Size + param_1[1] + -4);
    while ((uVar1 & 0x80000000) == 0) {
      uVar1 = param_1[1];
      FUN_1001eae8(uVar1,uVar1,(int *)uVar1,param_3);
      uVar1 = *(uint *)(_Size + param_1[1] + -4);
    }
    memset((void *)param_1[4],0,_Size + 4);
    *(undefined4 *)(param_1[4] + _Size + 4) = 1;
    iVar2 = FUN_10025df8((void *)param_1[4],param_2,(void *)param_1[2],param_3 + 2,param_3);
    if (iVar2 != 0) {
      FUN_1001ea90(param_1[3],(int)param_2,(uint *)param_1[2],param_3);
      *param_1 = param_3;
      return 1;
    }
    FUN_100269f8(pvVar3);
  }
  return 0;
}



/* 10026b84 FUN_10026b84 */

/* Boundary evidence: original MIPS .pdata 10026b84..10026d5f. Semantic name remains unreviewed. */

void FUN_10026b84(int *param_1,uint *param_2,void *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  
  iVar7 = *param_1;
  iVar6 = param_1[2];
  puVar8 = param_2 + iVar7 + -2;
  iVar4 = param_1[3];
  puVar5 = (uint *)param_1[1];
  uVar1 = 0;
  if (param_2 <= puVar8) {
    do {
      uVar2 = puVar8[iVar7 + 1];
      if (uVar2 < uVar1) {
        uVar1 = uVar1 - uVar2;
        iVar3 = iVar6;
      }
      else {
        uVar1 = uVar2 - uVar1;
        iVar3 = iVar4;
      }
      uVar1 = FUN_1001ec54(puVar8,uVar1,iVar3,iVar7);
      puVar8 = puVar8 + -1;
    } while (param_2 <= puVar8);
  }
  puVar9 = param_2 + iVar7;
  uVar2 = *puVar9;
  puVar8 = param_2 + 1;
  if (uVar2 < uVar1) {
    *puVar9 = uVar2 - uVar1;
    do {
      iVar4 = FUN_1001eae8((int)puVar8,(int)puVar8,(int *)puVar5,iVar7);
    } while (iVar4 == 0);
  }
  else {
    *puVar9 = uVar2 - uVar1;
    iVar4 = FUN_10025aec((int)puVar8,(int)puVar5,iVar7);
    if (-1 < iVar4) {
      FUN_1001ea90((int)puVar8,(int)puVar8,puVar5,iVar7);
    }
  }
  if (*puVar9 < puVar5[iVar7 + -1]) {
    uVar1 = __ull_div(puVar9[-1],*puVar9,puVar5[iVar7 + -1],0);
  }
  else {
    uVar1 = 0xffffffff;
  }
  iVar4 = FUN_1001ec54(param_2,uVar1,(int)puVar5,iVar7);
  uVar1 = *puVar9 - iVar4;
  *puVar9 = uVar1;
  while (uVar1 != 0) {
    iVar4 = FUN_1001eae8((int)param_2,(int)param_2,(int *)puVar5,iVar7);
    uVar1 = iVar4 + *puVar9;
    *puVar9 = uVar1;
  }
  memcpy(param_3,param_2,iVar7 * 4);
  return;
}



/* 10026d60 FUN_10026d60 */

/* Boundary evidence: original MIPS .pdata 10026d60..10026daf. Semantic name remains unreviewed. */

void FUN_10026d60(int *param_1,void *param_2,uint *param_3)

{
  FUN_10025c24((uint *)param_1[4],param_3,*param_1);
  FUN_10026b84(param_1,(uint *)param_1[4],param_2);
  return;
}



/* 10026db0 FUN_10026db0 */

/* Boundary evidence: original MIPS .pdata 10026db0..10026e07. Semantic name remains unreviewed. */

void FUN_10026db0(int *param_1,void *param_2,int param_3,int param_4)

{
  FUN_10025b50((uint *)param_1[4],param_3,param_4,*param_1);
  FUN_10026b84(param_1,(uint *)param_1[4],param_2);
  return;
}



/* 10026e08 FUN_10026e08 */

/* Boundary evidence: original MIPS .pdata 10026e08..10027213. Semantic name remains unreviewed. */

bool FUN_10026e08(uint *param_1,uint *param_2,int param_3,int *param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *_Dst;
  uint uVar5;
  void *_Dst_00;
  size_t _Size;
  int iVar6;
  void *pvVar7;
  void *pvVar8;
  int iVar9;
  uint local_50;
  uint uStack_40;
  HLOCAL local_3c;
  
  iVar2 = FUN_10025860(param_3,param_5);
  if (iVar2 == 0) {
    FUN_100257d8(param_1,1,param_5);
    bVar1 = true;
  }
  else {
    uVar3 = FUN_10025820((int)param_4,param_5);
    iVar4 = FUN_10026a14(&uStack_40,param_4,uVar3);
    if (iVar4 != 0) {
      if (iVar2 < 0x12) {
        local_50 = 1;
      }
      else if (iVar2 < 0x21) {
        local_50 = 2;
      }
      else if (iVar2 < 0x41) {
        local_50 = 4;
      }
      else if (iVar2 < 0x81) {
        local_50 = 8;
      }
      else if (iVar2 < 0x101) {
        local_50 = 0x10;
      }
      else {
        local_50 = 0x20;
      }
      _Dst = (void *)FUN_100269dc(0x40,(local_50 + 1) * uVar3 * 4);
      if (_Dst != (void *)0x0) {
        _Size = uVar3 * 4;
        _Dst_00 = (void *)(_Size + (int)_Dst);
        memcpy(_Dst_00,param_2,_Size);
        if ((1 < local_50) && (FUN_10026d60((int *)&uStack_40,_Dst,param_2), 1 < local_50)) {
          iVar4 = local_50 - 1;
          pvVar8 = _Dst_00;
          pvVar7 = _Dst_00;
          do {
            pvVar7 = (void *)(_Size + (int)pvVar7);
            FUN_10026db0((int *)&uStack_40,pvVar7,(int)pvVar8,(int)_Dst);
            pvVar8 = (void *)((int)pvVar8 + _Size);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        iVar2 = iVar2 + -1;
        iVar9 = 0;
        bVar1 = true;
        uVar5 = 1 << (iVar2 % 0x20 & 0x1fU);
        iVar4 = iVar2;
        for (; -1 < iVar2; iVar2 = iVar2 + -1) {
          iVar9 = iVar9 * 2;
          if ((*(uint *)((iVar2 / 0x20) * 4 + param_3) & uVar5) != 0) {
            iVar9 = iVar9 + 1;
          }
          uVar5 = uVar5 << 0x1f | uVar5 >> 1;
          if ((iVar2 == 0) || ((int)local_50 <= iVar9)) {
            iVar4 = iVar4 - iVar2;
            iVar6 = 0;
            for (; (iVar9 != 0 && (iVar9 % 2 == 0)); iVar9 = iVar9 / 2) {
              iVar4 = iVar4 + -1;
              iVar6 = iVar6 + 1;
            }
            if (bVar1) {
              memcpy(_Dst,(void *)(((int)((iVar9 + -1) * uVar3) / 2) * 4 + (int)_Dst_00),_Size);
              bVar1 = false;
            }
            else {
              for (; iVar4 != 0; iVar4 = iVar4 + -1) {
                FUN_10026d60((int *)&uStack_40,_Dst,_Dst);
              }
              if (iVar9 != 0) {
                FUN_10026db0((int *)&uStack_40,_Dst,(int)_Dst,
                             (int)(((int)((iVar9 + -1) * uVar3) / 2) * 4 + (int)_Dst_00));
              }
            }
            for (; iVar6 != 0; iVar6 = iVar6 + -1) {
              FUN_10026d60((int *)&uStack_40,_Dst,_Dst);
            }
            iVar9 = 0;
            iVar4 = iVar2;
          }
        }
        iVar2 = FUN_10025df8(_Dst,param_4,param_1,uVar3,uVar3);
        if (iVar2 != 0) {
          memset(param_1 + uVar3,0,(param_5 - uVar3) * 4);
        }
        FUN_100269f8(local_3c);
        FUN_100269f8(_Dst);
        return iVar2 != 0;
      }
      FUN_100269f8(local_3c);
    }
    bVar1 = false;
  }
  return bVar1;
}



/* 10027214 FUN_10027214 */

/* Boundary evidence: original MIPS .pdata 10027214..100273ff. Semantic name remains unreviewed. */

undefined4
FUN_10027214(uint *param_1,void *param_2,int *param_3,int *param_4,int param_5,int param_6,
            int param_7,uint param_8)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  
  puVar2 = (uint *)FUN_100269dc(0x40,param_8 << 4);
  if (puVar2 == (uint *)0x0) {
    return 0;
  }
  puVar5 = puVar2 + param_8;
  puVar6 = puVar5 + param_8 * 2;
  uVar4 = param_8 * 2 - 1;
  iVar3 = FUN_10025df8(param_2,param_3,puVar6,uVar4,param_8);
  if ((((iVar3 != 0) &&
       (bVar1 = FUN_10026e08(puVar2,puVar6,param_5,param_3,param_8),
       CONCAT31(extraout_var,bVar1) != 0)) &&
      (iVar3 = FUN_10025df8(param_2,param_4,puVar6,uVar4,param_8), iVar3 != 0)) &&
     (bVar1 = FUN_10026e08(puVar5,puVar6,param_6,param_4,param_8),
     CONCAT31(extraout_var_00,bVar1) != 0)) {
    iVar3 = FUN_1001ea90((int)puVar6,(int)puVar2,puVar5,param_8);
    if (iVar3 != 0) {
      do {
        iVar3 = FUN_1001eae8((int)puVar6,(int)puVar6,param_3,param_8);
      } while (iVar3 == 0);
    }
    FUN_10025b50(param_1,(int)puVar6,param_7,param_8);
    iVar3 = FUN_10025df8(param_1,param_3,puVar6,uVar4,param_8);
    if (iVar3 != 0) {
      FUN_10025b50(param_1,(int)puVar6,(int)param_4,param_8);
      memset(puVar5 + param_8,0,param_8 * 4);
      FUN_1001eae8((int)param_1,(int)param_1,(int *)puVar5,param_8 * 2);
      uVar7 = 1;
      goto LAB_100273c4;
    }
  }
  uVar7 = 0;
LAB_100273c4:
  FUN_100269f8(puVar2);
  return uVar7;
}



/* 10027470 FUN_10027470 */

void FUN_10027470(void)

{
  return;
}



/* 10027478 FUN_10027478 */

/* Boundary evidence: original MIPS .pdata 10027478..10027493. Semantic name remains unreviewed. */

void FUN_10027478(size_t param_1)

{
  malloc(param_1);
  return;
}



/* 10027494 FUN_10027494 */

/* Boundary evidence: original MIPS .pdata 10027494..100274af. Semantic name remains unreviewed. */

void FUN_10027494(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}



/* 100274b0 FUN_100274b0 */

/* Boundary evidence: original MIPS .pdata 100274b0..100274cb. Semantic name remains unreviewed. */

void FUN_100274b0(void *param_1)

{
  free(param_1);
  return;
}



/* 100274cc FUN_100274cc */

/* Boundary evidence: original MIPS .pdata 100274cc..100275cf. Semantic name remains unreviewed. */

undefined4 FUN_100274cc(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_1 == 0) {
    ppuVar4 = &PTR_DAT_1002da28;
    puVar2 = &DAT_10008c38;
    iVar3 = 1;
  }
  else {
    ppuVar4 = &PTR_DAT_1002da20;
    puVar2 = &DAT_10008c30;
    iVar3 = 2;
  }
  iVar6 = 0;
  if (iVar3 != 0) {
    iVar7 = (int)puVar2 - (int)ppuVar4;
    iVar5 = param_3;
    do {
      iVar1 = FUN_1002764c(*ppuVar4,*(uint *)(iVar7 + (int)ppuVar4),iVar5);
      if (iVar1 < 0) {
        return 0x54f;
      }
      iVar6 = iVar6 + 1;
      ppuVar4 = ppuVar4 + 1;
      iVar5 = iVar5 + 0x78;
    } while (iVar6 < iVar3);
  }
  memset(param_2,0,0x28);
  *param_2 = 1;
  param_2[2] = iVar3;
  param_2[3] = param_3;
  return 0;
}



/* 100275d0 FUN_100275d0 */

/* Boundary evidence: original MIPS .pdata 100275d0..1002764b. Semantic name remains unreviewed. */

undefined4 FUN_100275d0(int param_1,LPCWSTR param_2)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 auStack_128 [2];
  int aiStack_120 [10];
  undefined1 auStack_f8 [240];
  
  iVar1 = FUN_100274cc(param_1,aiStack_120,(int)auStack_f8);
  if (iVar1 == 0) {
    dwErrCode = FUN_10027ea4(1,param_2,aiStack_120,auStack_128,0,0,(undefined4 *)0x0);
    if (dwErrCode == 0) {
      return 1;
    }
    SetLastError(dwErrCode);
  }
  return 0;
}



/* 1002764c FUN_1002764c */

/* Boundary evidence: original MIPS .pdata 1002764c..100276df. Semantic name remains unreviewed. */

void FUN_1002764c(byte *param_1,uint param_2,int param_3)

{
  byte *pbVar1;
  uint local_10 [2];
  
  local_10[0] = 0x14;
  pbVar1 = FUN_100282f0(param_1,param_2,local_10,0x10008c70,0xf,param_3);
  if ((0 < (int)pbVar1) && (param_3 != 0)) {
    if (*(int *)(param_3 + 0x60) != 0) {
      *(int *)(param_3 + 100) = *(int *)(param_3 + 100) + 1;
      *(int *)(param_3 + 0x60) = *(int *)(param_3 + 0x60) + -1;
    }
    if (*(int *)(param_3 + 0x68) != 0) {
      *(int *)(param_3 + 0x6c) = *(int *)(param_3 + 0x6c) + 1;
      *(int *)(param_3 + 0x68) = *(int *)(param_3 + 0x68) + -1;
    }
  }
  return;
}



/* 100276e0 FUN_100276e0 */

/* Boundary evidence: original MIPS .pdata 100276e0..10027737. Semantic name remains unreviewed. */

byte * FUN_100276e0(uint *param_1,int param_2)

{
  byte *pbVar1;
  uint local_10 [2];
  
  local_10[0] = 3;
  pbVar1 = FUN_100282f0((byte *)param_1[1],*param_1,local_10,0x10008d60,4,param_2);
  if (0 < (int)pbVar1) {
    pbVar1 = *(byte **)(param_2 + 8);
  }
  return pbVar1;
}



/* 10027738 FUN_10027738 */

/* Boundary evidence: original MIPS .pdata 10027738..1002778f. Semantic name remains unreviewed. */

byte * FUN_10027738(uint *param_1,int param_2)

{
  byte *pbVar1;
  uint local_10 [2];
  
  local_10[0] = 3;
  pbVar1 = FUN_100282f0((byte *)param_1[1],*param_1,local_10,0x10008d84,4,param_2);
  if (0 < (int)pbVar1) {
    pbVar1 = *(byte **)(param_2 + 8);
  }
  return pbVar1;
}



/* 10027790 FUN_10027790 */

/* Boundary evidence: original MIPS .pdata 10027790..100277e7. Semantic name remains unreviewed. */

byte * FUN_10027790(uint *param_1,int param_2)

{
  byte *pbVar1;
  uint local_10 [2];
  
  local_10[0] = 3;
  pbVar1 = FUN_100282f0((byte *)param_1[1],*param_1,local_10,0x10008da8,4,param_2);
  if (0 < (int)pbVar1) {
    pbVar1 = *(byte **)(param_2 + 8);
  }
  return pbVar1;
}



/* 100277e8 FUN_100277e8 */

/* Boundary evidence: original MIPS .pdata 100277e8..10027837. Semantic name remains unreviewed. */

byte * FUN_100277e8(byte *param_1,uint param_2,int param_3)

{
  byte *pbVar1;
  uint local_10 [2];
  
  local_10[0] = 0x18;
  pbVar1 = FUN_100282f0(param_1,param_2,local_10,0x10008dfc,0x13,param_3);
  if (0 < (int)pbVar1) {
    pbVar1 = *(byte **)(param_3 + 8);
  }
  return pbVar1;
}



/* 10027838 FUN_10027838 */

/* Boundary evidence: original MIPS .pdata 10027838..1002794b. Semantic name remains unreviewed. */

byte * FUN_10027838(int *param_1,uint *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  byte *local_28;
  uint local_24;
  
  pbVar5 = (byte *)param_1[1];
  uVar6 = *param_2;
  uVar4 = 0;
  pbVar1 = (byte *)0x0;
  if (*param_1 != 0) {
    iVar2 = FUN_10028224(pbVar5,*param_1,&local_24,(int *)&local_28);
    if (iVar2 < 1) {
      pbVar1 = (byte *)0xffffffff;
    }
    else {
      uVar4 = 0;
      iVar2 = param_3;
      for (; local_24 != 0; local_24 = local_24 - iVar3) {
        if (param_3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = iVar2;
          if (uVar6 <= uVar4) break;
        }
        iVar3 = FUN_1002764c(local_28,local_24,iVar3);
        if (iVar3 < 1) {
          if (iVar3 == 0) {
            iVar3 = -1;
          }
          pbVar1 = pbVar5 + (iVar3 - (int)local_28);
          goto LAB_10027908;
        }
        local_28 = local_28 + iVar3;
        uVar4 = uVar4 + 1;
        iVar2 = iVar2 + 0x78;
      }
      pbVar1 = local_28 + -(int)pbVar5;
    }
  }
LAB_10027908:
  *param_2 = uVar4;
  return pbVar1;
}



/* 1002794c FUN_1002794c */

/* Boundary evidence: original MIPS .pdata 1002794c..10027a73. Semantic name remains unreviewed. */

byte * FUN_1002794c(int *param_1,uint *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  byte *local_30;
  uint local_2c [3];
  
  pbVar4 = (byte *)param_1[1];
  uVar5 = *param_2;
  uVar3 = 0;
  pbVar1 = (byte *)0x0;
  if (*param_1 != 0) {
    iVar2 = FUN_10028224(pbVar4,*param_1,local_2c,(int *)&local_30);
    if (iVar2 < 1) {
      pbVar1 = (byte *)0xffffffff;
    }
    else {
      for (uVar3 = 0; (local_2c[0] != 0 && (uVar3 < uVar5)); uVar3 = uVar3 + 1) {
        local_2c[1] = 4;
        pbVar1 = FUN_100282f0(local_30,local_2c[0],local_2c + 1,0x10008f1c,5,param_3);
        if ((int)pbVar1 < 1) {
          if (pbVar1 == (byte *)0x0) {
            pbVar1 = (byte *)0xffffffff;
          }
          pbVar1 = pbVar4 + ((int)pbVar1 - (int)local_30);
          goto LAB_10027a30;
        }
        local_30 = local_30 + *(int *)(param_3 + 8);
        local_2c[0] = local_2c[0] - *(int *)(param_3 + 8);
        param_3 = param_3 + 0x28;
      }
      pbVar1 = local_30 + -(int)pbVar4;
    }
  }
LAB_10027a30:
  *param_2 = uVar3;
  return pbVar1;
}



/* 10027a74 FUN_10027a74 */

/* Boundary evidence: original MIPS .pdata 10027a74..10027acb. Semantic name remains unreviewed. */

byte * FUN_10027a74(uint *param_1,int param_2)

{
  byte *pbVar1;
  uint local_10 [2];
  
  local_10[0] = 8;
  pbVar1 = FUN_100282f0((byte *)param_1[1],*param_1,local_10,0x10008fe8,6,param_2);
  if (0 < (int)pbVar1) {
    pbVar1 = *(byte **)(param_2 + 8);
  }
  return pbVar1;
}



/* 10027acc FUN_10027acc */

/* Boundary evidence: original MIPS .pdata 10027acc..10027b1f. Semantic name remains unreviewed. */

undefined4 FUN_10027acc(int *param_1,int *param_2,uint param_3)

{
  if (*param_1 == 0x8003) {
    MD5Update((uint *)param_1[1],param_2,param_3);
  }
  else {
    if (*param_1 != 0x8004) {
      return 0;
    }
    A_SHAUpdate((void *)param_1[1],param_2,param_3);
  }
  return 1;
}



/* 10027b20 FUN_10027b20 */

/* Boundary evidence: original MIPS .pdata 10027b20..10027bc7. Semantic name remains unreviewed. */

undefined4 FUN_10027b20(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  short *_Buf1;
  uint uVar3;
  
  uVar3 = *param_1;
  _Buf1 = (short *)param_1[1];
  if ((((uVar3 < 4) || (iVar2 = memcmp(_Buf1,&DAT_1000907c,2), iVar2 != 0)) || (uVar3 < 0x40)) ||
     ((*_Buf1 != 0x5a4d || (uVar3 < *(int *)(_Buf1 + 0x1e) + 0x40U)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if (*(int *)(*(int *)(_Buf1 + 0x1e) + (int)_Buf1) == 0x4550) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* 10027bc8 FUN_10027bc8 */

/* Boundary evidence: original MIPS .pdata 10027bc8..10027e97. Semantic name remains unreviewed. */

DWORD FUN_10027bc8(int param_1,LPCWSTR param_2,int param_3,void *param_4,uint *param_5)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  undefined3 extraout_var;
  uint _Size;
  DWORD local_118;
  LPCVOID local_114;
  DWORD local_110;
  uint *local_10c;
  int local_108;
  uint *local_104;
  uint auStack_100 [22];
  undefined1 auStack_a8 [16];
  uint auStack_98 [24];
  int aiStack_38 [2];
  uint local_30;
  
  local_30 = DAT_1002da44;
  local_10c = param_5;
  local_118 = 0;
  local_114 = (LPCVOID)0x0;
  DVar2 = FUN_10029898(param_1,param_2,&local_118);
  local_110 = DVar2;
  if (DVar2 == 0) {
    iVar3 = FUN_10027b20(&local_118);
    if (iVar3 == 0) {
      DVar2 = FUN_100297d0(param_3,1,(int *)&local_118,param_4,param_5);
      local_110 = DVar2;
      goto LAB_10027e24;
    }
    local_108 = param_3;
    if (param_3 == 0x8003) {
      local_104 = auStack_100;
      MD5Init(auStack_100);
LAB_10027ce4:
      bVar1 = FUN_10028b38(&local_118,0,FUN_10027acc,&local_108);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        _Size = (local_118 + 7 & 0xfffffff8) - local_118;
        if (_Size != 0) {
          memset(aiStack_38,0,_Size);
          iVar3 = FUN_10027acc(&local_108,aiStack_38,_Size);
          if (iVar3 == 0) goto LAB_10027e18;
        }
        if (param_3 == 0x8003) {
          MD5Final(auStack_100);
          memcpy(param_4,auStack_a8,0x10);
          *param_5 = 0x10;
        }
        else {
          if (param_3 != 0x8004) goto LAB_10027e08;
          A_SHAFinal(auStack_98,(int)param_4);
          *param_5 = 0x14;
        }
        DVar2 = 0;
        goto LAB_10027e24;
      }
LAB_10027e18:
      DVar2 = 0x80090002;
    }
    else {
      if (param_3 == 0x8004) {
        local_104 = auStack_98;
        A_SHAInit((int)auStack_98);
        goto LAB_10027ce4;
      }
LAB_10027e08:
      DVar2 = 0x80090008;
    }
  }
  *param_5 = 0;
LAB_10027e24:
  if ((param_1 != 3) && (local_114 != (LPCVOID)0x0)) {
    UnmapViewOfFile(local_114);
  }
  FUN_1002bedc(local_30);
  return DVar2;
}



/* 10027e98 FUN_10027e98 */

/* Boundary evidence: original MIPS .pdata 10027e98..10027ea3. Semantic name remains unreviewed. */

undefined4 FUN_10027e98(void)

{
  return 1;
}



/* 10027ea4 FUN_10027ea4 */

/* Boundary evidence: original MIPS .pdata 10027ea4..1002814b. Semantic name remains unreviewed. */

DWORD FUN_10027ea4(int param_1,LPCWSTR param_2,int *param_3,undefined4 *param_4,int param_5,
                  int param_6,undefined4 *param_7)

{
  DWORD DVar1;
  int iVar2;
  WCHAR local_68 [2];
  LPCVOID local_64;
  size_t local_60;
  uint *local_5c;
  int local_58 [2];
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [20];
  uint local_24;
  
  local_24 = DAT_1002da44;
  local_68[0] = L'\0';
  local_68[1] = L'\0';
  local_64 = (LPCVOID)0x0;
  local_5c = (uint *)0x0;
  DVar1 = FUN_10029898(param_1,param_2,(DWORD *)local_68);
  if (DVar1 == 0) {
    iVar2 = FUN_10027b20((uint *)local_68);
    if (iVar2 == 0) {
      DVar1 = 0x32;
    }
    else {
      iVar2 = FUN_10028f44((undefined4 *)local_68,0,&local_5c);
      if ((iVar2 == 0) || (*local_5c < 8)) {
        DVar1 = 0x800b0100;
      }
      else {
        DVar1 = FUN_1002a00c(local_5c,*local_5c,param_3,param_5,param_6,param_7,auStack_50,local_58,
                             param_4);
        if ((DVar1 == 0) &&
           (DVar1 = FUN_10027bc8(3,local_68,local_58[0],auStack_38,&local_60), DVar1 == 0)) {
          iVar2 = memcmp(auStack_38,auStack_50,local_60);
          if (iVar2 == 0) goto LAB_100280e4;
          DVar1 = 0x80091007;
        }
      }
    }
  }
  if (DVar1 == 0x7a) {
    DVar1 = 0x8000ffff;
  }
LAB_100280e4:
  if ((param_1 != 3) && (local_64 != (LPCVOID)0x0)) {
    UnmapViewOfFile(local_64);
  }
  FUN_1002bedc(local_24);
  return DVar1;
}



/* 1002814c FUN_1002814c */

/* Boundary evidence: original MIPS .pdata 1002814c..10028157. Semantic name remains unreviewed. */

undefined4 FUN_1002814c(void)

{
  return 1;
}



/* 10028158 FUN_10028158 */

int FUN_10028158(uint *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_3 != 0) {
    bVar1 = *param_2;
    uVar3 = (uint)bVar1;
    if (uVar3 == 0x80) {
      return -3;
    }
    if ((bVar1 & 0x80) == 0) {
      *param_1 = uVar3;
      return 1;
    }
    uVar3 = uVar3 & 0xffffff7f;
    if (4 < uVar3) {
      return -1;
    }
    if (uVar3 <= param_3 - 1U) {
      uVar4 = 0;
      uVar5 = 0;
      if ((bVar1 & 0x7f) != 0) {
        uVar6 = (uVar3 - 1) * 8;
        do {
          iVar2 = uVar5 + 1;
          uVar5 = uVar5 + 1;
          uVar4 = (uint)param_2[iVar2] << (uVar6 & 0x1f) | uVar4;
          uVar6 = uVar6 - 8;
        } while (uVar5 < uVar3);
      }
      *param_1 = uVar4;
      return uVar3 + 1;
    }
  }
  return -2;
}



/* 10028224 FUN_10028224 */

/* Boundary evidence: original MIPS .pdata 10028224..100282ef. Semantic name remains unreviewed. */

int FUN_10028224(byte *param_1,int param_2,uint *param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint local_20 [2];
  
  iVar4 = param_2 + -1;
  if (param_2 != 0) {
    pbVar5 = param_1 + 1;
    if ((*param_1 & 0x1f) == 0x1f) {
      iVar3 = 2;
      while (iVar4 != 0) {
        bVar1 = *pbVar5;
        iVar4 = iVar4 + -1;
        pbVar5 = pbVar5 + 1;
        if ((bVar1 & 0x80) == 0) goto LAB_100282b0;
        iVar3 = iVar3 + 1;
      }
    }
    else {
      iVar3 = 1;
LAB_100282b0:
      iVar2 = FUN_10028158(local_20,pbVar5,iVar4);
      if (iVar2 < 0) {
        return iVar2;
      }
      if (local_20[0] <= (uint)(iVar4 - iVar2)) {
        *param_3 = local_20[0];
        *param_4 = (int)(pbVar5 + iVar2);
        return iVar2 + iVar3;
      }
    }
  }
  return -2;
}



/* 100282f0 FUN_100282f0 */

/* Boundary evidence: original MIPS .pdata 100282f0..1002866b. Semantic name remains unreviewed. */

byte * FUN_100282f0(byte *param_1,uint param_2,uint *param_3,int param_4,uint param_5,int param_6)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint *puVar8;
  byte *pbVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *local_b0;
  int *local_ac;
  uint *local_a8;
  int local_a4;
  uint local_98;
  uint *local_94;
  byte *local_90 [2];
  int iStack_88;
  uint uStack_84;
  int aiStack_80 [22];
  
  local_94 = param_3;
  uVar4 = *param_3;
  iVar10 = 0;
  local_a4 = 0;
  uVar16 = 0;
  uVar17 = 0;
  pbVar13 = param_1;
  if (uVar4 != 0) {
    puVar5 = (undefined4 *)(param_4 + 8);
    piVar7 = aiStack_80;
    puVar8 = &uStack_84;
    piVar11 = &iStack_88;
    local_b0 = piVar7;
    local_ac = piVar11;
    local_a8 = puVar8;
    do {
      uVar14 = puVar5[-2];
      pbVar9 = (byte *)*puVar5;
      uVar15 = puVar5[-1];
      uVar12 = uVar14 & 0xff;
      if ((((uVar14 & 0xc0000000) == 0) || (param_6 == 0)) || (bVar2 = true, param_5 <= uVar15)) {
        bVar2 = false;
      }
      if (uVar12 == 5) {
        if (uVar16 != 0) {
          piVar11 = piVar11 + -3;
          puVar8 = puVar8 + -3;
          piVar7 = piVar7 + -3;
          pbVar13 = (byte *)*piVar11;
          param_2 = *puVar8;
          iVar10 = *piVar7;
          uVar16 = uVar16 - 1;
          local_b0 = piVar7;
          local_ac = piVar11;
          local_a8 = puVar8;
          local_a4 = iVar10;
          goto LAB_100284d0;
        }
        goto LAB_10028408;
      }
      if (iVar10 == 0) {
        if (param_2 == 0) {
joined_r0x100283f8:
          if ((uVar12 == 4) || (uVar12 == 2)) goto LAB_1002846c;
        }
        else {
          if (pbVar9 != (byte *)0x0) {
            bVar1 = *pbVar9;
            while ((bVar1 != 0 && (piVar7 = local_b0, bVar1 != *pbVar13))) {
              pbVar9 = pbVar9 + 1;
              bVar1 = *pbVar9;
            }
            if (bVar1 == 0) goto joined_r0x100283f8;
          }
          iVar3 = FUN_10028224(pbVar13,param_2,&local_98,(int *)local_90);
          if (0 < iVar3) {
            iVar3 = local_98 + iVar3;
            if (bVar2) {
              if ((uVar14 & 0x40000000) == 0) {
                if ((uVar14 & 0x80000000) != 0) {
                  piVar7 = (int *)(uVar15 * 8 + param_6);
                  piVar7[1] = (int)pbVar13;
                  *piVar7 = iVar3;
                }
              }
              else {
                puVar8 = (uint *)(uVar15 * 8 + param_6);
                puVar8[1] = (uint)local_90[0];
                *puVar8 = local_98;
                if ((*pbVar13 == 3) && (local_98 != 0)) {
                  puVar8[1] = (uint)(local_90[0] + 1);
                  *puVar8 = local_98 - 1;
                }
              }
            }
            if (uVar12 != 0) {
              iVar10 = local_a4;
              if (uVar12 < 3) {
                piVar7 = local_b0;
                puVar8 = local_a8;
                piVar11 = local_ac;
                pbVar13 = pbVar13 + iVar3;
                param_2 = param_2 - iVar3;
              }
              else {
                if ((4 < uVar12) || (7 < uVar16)) goto LAB_10028408;
                *local_ac = (int)(pbVar13 + iVar3);
                *local_a8 = param_2 - iVar3;
                *local_b0 = 0;
                uVar16 = uVar16 + 1;
                piVar11 = local_ac + 3;
                puVar8 = local_a8 + 3;
                piVar7 = local_b0 + 3;
                pbVar13 = local_90[0];
                param_2 = local_98;
                local_b0 = piVar7;
                local_ac = piVar11;
                local_a8 = puVar8;
              }
              goto LAB_100284d0;
            }
          }
        }
LAB_10028408:
        pbVar13 = param_1 + (-1 - (int)pbVar13);
        goto LAB_100284f4;
      }
LAB_1002846c:
      if (bVar2) {
        puVar6 = (undefined4 *)(uVar15 * 8 + param_6);
        puVar6[1] = 0;
        *puVar6 = 0;
      }
      if ((uVar12 == 3) || (uVar12 == 4)) {
        if (7 < uVar16) goto LAB_10028408;
        *piVar7 = iVar10;
        *piVar11 = (int)pbVar13;
        *puVar8 = param_2;
        uVar16 = uVar16 + 1;
        piVar11 = piVar11 + 3;
        puVar8 = puVar8 + 3;
        piVar7 = piVar7 + 3;
        iVar10 = 1;
        local_b0 = piVar7;
        local_ac = piVar11;
        local_a8 = puVar8;
        local_a4 = iVar10;
      }
LAB_100284d0:
      uVar17 = uVar17 + 1;
      puVar5 = puVar5 + 3;
    } while (uVar17 < uVar4);
  }
  pbVar13 = pbVar13 + -(int)param_1;
LAB_100284f4:
  *local_94 = uVar17;
  return pbVar13;
}



/* 1002866c FUN_1002866c */

/* Boundary evidence: original MIPS .pdata 1002866c..10028717. Semantic name remains unreviewed. */

int FUN_1002866c(size_t *param_1,uint param_2,int param_3)

{
  int iVar1;
  size_t *psVar2;
  uint uVar3;
  size_t _Size;
  void *_Buf1;
  
  _Size = *param_1;
  _Buf1 = (void *)param_1[1];
  uVar3 = 0;
  if (param_2 != 0) {
    psVar2 = (size_t *)(param_3 + 0x10);
    do {
      if ((_Size == *psVar2) && (iVar1 = memcmp(_Buf1,(void *)psVar2[1],_Size), iVar1 == 0)) {
        return uVar3 * 0x28 + param_3;
      }
      uVar3 = uVar3 + 1;
      psVar2 = psVar2 + 10;
    } while (uVar3 < param_2);
  }
  return 0;
}



/* 10028718 FUN_10028718 */

/* Boundary evidence: original MIPS .pdata 10028718..10028853. Semantic name remains unreviewed. */

void FUN_10028718(int param_1)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  
  psVar3 = *(short **)(param_1 + 8);
  if (*psVar3 == 0x5a4d) {
    if (*(int *)(psVar3 + 0x1e) == 0) {
      return;
    }
    psVar4 = (short *)(*(int *)(psVar3 + 0x1e) + (int)psVar3);
    *(short **)(param_1 + 0xc) = psVar4;
    if ((short *)(*(int *)(param_1 + 0x2c) + (int)psVar3) < psVar4 + 0x7c) {
      return;
    }
    if (psVar4 < psVar3 + 0x20) {
      return;
    }
  }
  else {
    if (*psVar3 != 0x4550) {
      return;
    }
    *(short **)(param_1 + 0xc) = psVar3;
  }
  piVar1 = *(int **)(param_1 + 0xc);
  if (((*piVar1 == 0x4550) && (*(undefined1 *)(param_1 + 0x21) = 0, (short)piVar1[5] != 0)) &&
     ((2 < *(byte *)((int)piVar1 + 0x1a) || (4 < *(byte *)((int)piVar1 + 0x1b))))) {
    iVar2 = param_1 + 0x24;
    *(int *)(param_1 + 0x28) = iVar2;
    *(int *)iVar2 = iVar2;
    iVar2 = *(int *)(param_1 + 0xc);
    *(uint *)(param_1 + 0x14) = (uint)*(ushort *)(iVar2 + 6);
    *(uint *)(param_1 + 0x18) = (uint)*(ushort *)(iVar2 + 0x14) + iVar2 + 0x18;
  }
  return;
}



/* 10028854 FUN_10028854 */

/* Boundary evidence: original MIPS .pdata 10028854..1002885f. Semantic name remains unreviewed. */

undefined4 FUN_10028854(void)

{
  return 1;
}



/* 10028860 FUN_10028860 */

/* Boundary evidence: original MIPS .pdata 10028860..100288af. Semantic name remains unreviewed. */

undefined4 FUN_10028860(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined4 *)(param_2 + 4) = 0xffffffff;
  iVar2 = param_1[1];
  *(int *)(param_2 + 8) = iVar2;
  *(undefined4 *)(param_2 + 0x2c) = *param_1;
  if ((iVar2 == 0) || (iVar2 = FUN_10028718(param_2), iVar2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 100288b0 FUN_100288b0 */

/* Boundary evidence: original MIPS .pdata 100288b0..1002890f. Semantic name remains unreviewed. */

void FUN_100288b0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    for (iVar1 = *(int *)(*(int *)(param_1 + 4) + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      LocalFree(*(HLOCAL *)(param_1 + 4));
      *(int *)(param_1 + 4) = iVar1;
    }
    LocalFree(*(HLOCAL *)(param_1 + 4));
  }
  return;
}



/* 10028910 FUN_10028910 */

/* Boundary evidence: original MIPS .pdata 10028910..1002899f. Semantic name remains unreviewed. */

bool FUN_10028910(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HLOCAL _Dst;
  
  _Dst = LocalAlloc(0x40,0xc);
  param_1[1] = _Dst;
  if (_Dst != (HLOCAL)0x0) {
    memset(_Dst,0,0xc);
    *param_1 = param_2;
    *(undefined4 *)param_1[1] = 0;
    *(undefined4 *)(param_1[1] + 4) = 0;
    param_1[2] = param_3;
    param_1[3] = param_4;
  }
  return _Dst != (HLOCAL)0x0;
}



/* 100289a0 FUN_100289a0 */

/* Boundary evidence: original MIPS .pdata 100289a0..10028a27. Semantic name remains unreviewed. */

void FUN_100289a0(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = *(uint **)(param_1 + 4);
  do {
    puVar2 = puVar1;
    if (puVar2[2] == 0) break;
    puVar1 = (uint *)puVar2[2];
  } while (*(uint *)puVar2[2] < param_2);
  puVar1 = LocalAlloc(0x40,0xc);
  if (puVar1 != (uint *)0x0) {
    puVar1[2] = puVar2[2];
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar2[2] = (uint)puVar1;
  }
  return;
}



/* 10028a28 FUN_10028a28 */

/* Boundary evidence: original MIPS .pdata 10028a28..10028b37. Semantic name remains unreviewed. */

undefined4 FUN_10028a28(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(*(int *)(param_1 + 4) + 8);
  uVar1 = 0;
  while ((puVar2 != (uint *)0x0 && (param_3 != 0))) {
    if (param_2 <= *puVar2) {
      uVar3 = *puVar2 - param_2;
      if (param_3 <= uVar3) {
        uVar3 = param_3;
      }
      if (uVar3 != 0) {
        uVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),param_2,uVar3);
        param_3 = param_3 - uVar3;
        param_2 = uVar3 + param_2;
      }
    }
    if (param_3 != 0) {
      if (param_2 <= puVar2[1] + *puVar2) {
        uVar3 = (puVar2[1] - param_2) + *puVar2;
        if (param_3 < uVar3) {
          uVar3 = param_3;
        }
        param_3 = param_3 - uVar3;
        param_2 = uVar3 + param_2;
      }
    }
    puVar2 = (uint *)puVar2[2];
  }
  if (param_3 != 0) {
    uVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  }
  return uVar1;
}



/* 10028b38 FUN_10028b38 */

/* Boundary evidence: original MIPS .pdata 10028b38..10028d9f. Semantic name remains unreviewed. */

bool FUN_10028b38(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  DWORD dwErrCode;
  uint uVar6;
  uint uVar7;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 auStack_48 [8];
  uint local_40;
  int local_3c;
  uint local_34;
  int local_30;
  uint local_1c;
  
  local_58 = 0;
  local_54 = 0;
  iVar2 = FUN_10028860(param_1,(int)auStack_48);
  if (iVar2 == 0) {
    SetLastError(0x57);
    FUN_100288b0((int)&local_58);
    return false;
  }
  dwErrCode = 0x57;
  if ((*(short *)(local_3c + 0x18) == 0x10b) || (*(short *)(local_3c + 0x18) == 0x20b)) {
    bVar1 = FUN_10028910(&local_58,auStack_48,param_3,param_4);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      dwErrCode = 8;
    }
    else {
      if (*(short *)(local_3c + 0x18) == 0x10b) {
        FUN_100289a0((int)&local_58,local_3c + 0x58U,4);
        puVar3 = (uint *)(local_3c + 0x98);
      }
      else {
        FUN_100289a0((int)&local_58,local_3c + 0x58U,4);
        puVar3 = (uint *)(local_3c + 0xa8);
      }
      uVar6 = *puVar3;
      uVar7 = puVar3[1];
      if ((uVar6 != 0) && (uVar7 != 0)) {
        if ((local_1c < uVar6) ||
           (((uVar7 + uVar6 != local_1c || (uVar7 + uVar6 < uVar6)) ||
            (uVar6 < *(uint *)(local_3c + 0x54))))) goto LAB_10028d24;
        for (uVar5 = 0; uVar5 < local_34; uVar5 = uVar5 + 1) {
          iVar2 = uVar5 * 0x28 + local_30;
          iVar4 = *(int *)(iVar2 + 0x14);
          if ((iVar4 != 0) && (uVar6 < (uint)(*(int *)(iVar2 + 0x10) + iVar4))) goto LAB_10028d24;
        }
      }
      FUN_100289a0((int)&local_58,(uint)puVar3,8);
      FUN_100289a0((int)&local_58,local_40 + uVar6,uVar7);
      FUN_10028a28((int)&local_58,local_40,local_1c);
      dwErrCode = 0;
    }
  }
LAB_10028d24:
  SetLastError(dwErrCode);
  FUN_100288b0((int)&local_58);
  return dwErrCode == 0;
}



/* 10028da0 FUN_10028da0 */

/* Boundary evidence: original MIPS .pdata 10028da0..10028dab. Semantic name remains unreviewed. */

undefined4 FUN_10028da0(void)

{
  return 1;
}



/* 10028dac FUN_10028dac */

/* Boundary evidence: original MIPS .pdata 10028dac..10028f37. Semantic name remains unreviewed. */

int FUN_10028dac(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int *local_1c;
  uint *local_14;
  
  puVar3 = (uint *)0x0;
  iVar1 = 0;
  if (*(char *)(param_1 + 0x21) != '\0') {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(short *)(iVar2 + 0x18) == 0x10b) {
    local_1c = (int *)(iVar2 + 0x98);
  }
  else {
    if (*(short *)(iVar2 + 0x18) != 0x20b) goto LAB_10028eb8;
    local_1c = (int *)(iVar2 + 0xa8);
  }
  iVar2 = *local_1c;
  if (((iVar2 != 0) && (iVar4 = local_1c[1], iVar4 != 0)) &&
     ((uint)(iVar4 + iVar2) <= *(uint *)(param_1 + 0x2c))) {
    iVar5 = 0;
    puVar3 = (uint *)(*(int *)(param_1 + 8) + iVar2);
    local_14 = (uint *)(iVar4 + (int)puVar3);
    for (; puVar3 < local_14; puVar3 = (uint *)((int)puVar3 + *puVar3 + 7 & 0xfffffff8)) {
      if (iVar5 == param_2) {
        iVar1 = 1;
        break;
      }
      iVar5 = iVar5 + 1;
    }
  }
LAB_10028eb8:
  if (iVar1 == 1) {
    if (((uint)local_1c[1] < *puVar3) || (local_14 < (uint *)(*puVar3 + (int)puVar3))) {
      iVar1 = 0;
    }
    else {
      *param_3 = puVar3;
    }
  }
  return iVar1;
}



/* 10028f38 FUN_10028f38 */

/* Boundary evidence: original MIPS .pdata 10028f38..10028f43. Semantic name remains unreviewed. */

undefined4 FUN_10028f38(void)

{
  return 1;
}



/* 10028f44 FUN_10028f44 */

/* Boundary evidence: original MIPS .pdata 10028f44..1002902f. Semantic name remains unreviewed. */

undefined4 FUN_10028f44(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 local_4c;
  undefined1 auStack_48 [48];
  
  *param_3 = 0;
  iVar1 = FUN_10028860(param_1,(int)auStack_48);
  if (iVar1 == 0) {
    SetLastError(0x57);
  }
  else {
    dwErrCode = 0x57;
    iVar1 = FUN_10028dac((int)auStack_48,param_2,&local_4c);
    if (iVar1 != 0) {
      *param_3 = local_4c;
      dwErrCode = 0;
    }
    SetLastError(dwErrCode);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  return 0;
}



/* 10029030 FUN_10029030 */

/* Boundary evidence: original MIPS .pdata 10029030..1002903b. Semantic name remains unreviewed. */

undefined4 FUN_10029030(void)

{
  return 1;
}



/* 1002903c FUN_1002903c */

/* Boundary evidence: original MIPS .pdata 1002903c..1002910f. Semantic name remains unreviewed. */

undefined4 FUN_1002903c(uint *param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_40 [16];
  size_t local_30;
  void *local_2c;
  
  pbVar1 = FUN_100276e0(param_1,(int)auStack_40);
  if (0 < (int)pbVar1) {
    iVar4 = 0;
    uVar3 = 0;
    do {
      if ((local_30 == *(size_t *)((int)&DAT_100090c8 + uVar3)) &&
         (iVar2 = memcmp(local_2c,*(void **)((int)&PTR_DAT_100090cc + uVar3),local_30), iVar2 == 0))
      {
        return (&DAT_100090d0)[iVar4 * 3];
      }
      uVar3 = uVar3 + 0xc;
      iVar4 = iVar4 + 1;
    } while (uVar3 < 0x60);
  }
  return 0;
}



/* 10029110 FUN_10029110 */

/* Boundary evidence: original MIPS .pdata 10029110..1002918f. Semantic name remains unreviewed. */

undefined4 FUN_10029110(int *param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (**(code **)(*param_1 + 8))(param_1);
  *param_4 = uVar1;
  if (param_3 < uVar1) {
    uVar2 = 0x57;
  }
  else {
    uVar2 = (**(code **)(*param_1 + 4))(param_1,param_2,param_3);
  }
  return uVar2;
}



/* 10029190 FUN_10029190 */

/* Boundary evidence: original MIPS .pdata 10029190..100291ab. Semantic name remains unreviewed. */

void FUN_10029190(int param_1,int *param_2,uint param_3)

{
  MD5Update((uint *)(param_1 + 4),param_2,param_3);
  return;
}



/* 100291ac FUN_100291ac */

/* Boundary evidence: original MIPS .pdata 100291ac..10029203. Semantic name remains unreviewed. */

undefined4 FUN_100291ac(int *param_1,void *param_2)

{
  size_t _Size;
  
  MD5Final((uint *)(param_1 + 1));
  _Size = (**(code **)(*param_1 + 8))(param_1);
  memcpy(param_2,param_1 + 0x17,_Size);
  return 0;
}



/* 10029204 FUN_10029204 */

/* Boundary evidence: original MIPS .pdata 10029204..10029277. Semantic name remains unreviewed. */

undefined4 FUN_10029204(undefined4 param_1,undefined4 *param_2,int param_3,int *param_4)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    if (*param_4 != 0) {
      (**(code **)*param_2)(param_2,param_4[1]);
    }
    param_4 = param_4 + 2;
  }
  return 0;
}



/* 10029278 FUN_10029278 */

/* Boundary evidence: original MIPS .pdata 10029278..100293d3. Semantic name remains unreviewed. */

undefined4 FUN_10029278(int param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  
  uVar3 = *(uint *)(param_1 + 0x10);
  pcVar5 = *(char **)(param_1 + 0x14);
  if ((1 < uVar3) && (*pcVar5 == '\0')) {
    pcVar5 = pcVar5 + 1;
    uVar3 = uVar3 - 1;
  }
  if (uVar3 < 0x201) {
    uVar4 = *(uint *)(param_1 + 0x18);
    pcVar6 = *(char **)(param_1 + 0x1c);
    if ((1 < uVar4) && (*pcVar6 == '\0')) {
      pcVar6 = pcVar6 + 1;
      uVar4 = uVar4 - 1;
    }
    if (((uVar4 < 5) && (uVar3 != 0)) && (uVar4 != 0)) {
      iVar7 = -(uVar3 & 7) + 8;
      if (iVar7 != 8) {
        iVar7 = -(uVar3 & 7) + 0x10;
      }
      memset(param_2,0,0x224);
      *param_2 = 0x31415352;
      param_2[1] = iVar7 + uVar3;
      param_2[2] = uVar3 << 3;
      param_2[3] = uVar3 - 1;
      pcVar2 = (char *)((int)param_2 + uVar4 + 0xf);
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + -1;
      }
      pcVar6 = (char *)((int)param_2 + uVar3 + 0x13);
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        *pcVar6 = cVar1;
        pcVar6 = pcVar6 + -1;
      }
      return 0;
    }
  }
  return 0x80090015;
}



/* 100293d4 FUN_100293d4 */

/* Boundary evidence: original MIPS .pdata 100293d4..10029597. Semantic name remains unreviewed. */

undefined4 FUN_100293d4(int param_1,int param_2,int param_3,uint param_4,void *param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  byte *pbVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined **ppuVar10;
  undefined1 local_38 [20];
  uint local_24;
  
  local_24 = DAT_1002da44;
  if (param_2 == 0x8003) {
    ppuVar10 = &PTR_DAT_1002da38;
  }
  else {
    if (param_2 != 0x8004) {
      uVar9 = 0x80090008;
      goto LAB_10029564;
    }
    ppuVar10 = &PTR_DAT_1002da2c;
  }
  uVar6 = 0;
  if (param_4 != 0) {
    puVar4 = (undefined1 *)(param_3 + param_4);
    do {
      puVar4 = puVar4 + -1;
      puVar5 = local_38 + uVar6;
      uVar6 = uVar6 + 1;
      *puVar5 = *puVar4;
    } while (uVar6 < param_4);
  }
  iVar2 = memcmp(local_38,param_5,param_4);
  if (iVar2 == 0) {
    pbVar7 = *ppuVar10;
    iVar2 = 0;
    if (*pbVar7 != 0) {
      do {
        bVar1 = *pbVar7;
        iVar3 = memcmp((void *)(param_4 + (int)param_5),pbVar7 + 1,(uint)bVar1);
        if (iVar3 == 0) {
          param_4 = bVar1 + param_4;
          break;
        }
        iVar2 = iVar2 + 1;
        pbVar7 = ppuVar10[iVar2];
      } while (*pbVar7 != 0);
    }
    if (*(char *)(param_4 + (int)param_5) == '\0') {
      pcVar8 = (char *)(*(int *)(param_1 + 0xc) + (int)param_5);
      if ((*pcVar8 == '\0') && (pcVar8[-1] == '\x01')) {
        do {
          param_4 = param_4 + 1;
          if (*(int *)(param_1 + 0xc) - 1U <= param_4) {
            uVar9 = 0;
            goto LAB_10029564;
          }
        } while (*(char *)(param_4 + (int)param_5) == -1);
      }
    }
  }
  uVar9 = 0x80090006;
LAB_10029564:
  FUN_1002bedc(local_24);
  return uVar9;
}



/* 10029598 FUN_10029598 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 10029598..100296fb. Semantic name remains unreviewed. */

int FUN_10029598(int param_1,int param_2,uint param_3,uint *param_4,uint *param_5)

{
  undefined1 uVar1;
  bool bVar2;
  byte *pbVar3;
  int iVar4;
  undefined3 extraout_var;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_6a8 [32];
  undefined1 auStack_688 [24];
  uint auStack_670 [2];
  int aiStack_668 [2];
  uint local_660;
  undefined1 auStack_441 [529];
  uint auStack_230 [132];
  uint local_20;
  
  local_20 = DAT_1002da44;
  pbVar3 = FUN_10027738(param_5,(int)auStack_688);
  if (((int)pbVar3 < 1) || (pbVar3 = FUN_10027790(auStack_670,(int)auStack_6a8), (int)pbVar3 < 1)) {
    iVar4 = -0x7ff6ffeb;
  }
  else {
    iVar4 = FUN_10029278((int)auStack_6a8,aiStack_668);
    if (iVar4 == 0) {
      uVar5 = *param_4;
      if (uVar5 == local_660 >> 3) {
        puVar7 = (undefined1 *)param_4[1];
        if (uVar5 != 0) {
          puVar8 = auStack_441 + uVar5;
          for (uVar6 = uVar5; uVar6 != 0; uVar6 = uVar6 - 1) {
            uVar1 = *puVar7;
            puVar7 = puVar7 + 1;
            *puVar8 = uVar1;
            puVar8 = puVar8 + -1;
          }
        }
        memset(auStack_441 + uVar5 + 1,0,0x210 - uVar5);
        memset(auStack_230,0,0x210);
        bVar2 = BSafeEncPublic(aiStack_668,(uint *)((int)auStack_441 + 1),auStack_230);
        if (CONCAT31(extraout_var,bVar2) != 0) {
          iVar4 = FUN_100293d4((int)aiStack_668,param_1,param_2,param_3,auStack_230);
          goto LAB_100296d0;
        }
      }
      iVar4 = -0x7ff6fffa;
    }
  }
LAB_100296d0:
  FUN_1002bedc(local_20);
  return iVar4;
}



/* 100296fc FUN_100296fc */

/* Boundary evidence: original MIPS .pdata 100296fc..10029717. Semantic name remains unreviewed. */

void FUN_100296fc(int param_1,void *param_2,uint param_3)

{
  A_SHAUpdate((void *)(param_1 + 4),param_2,param_3);
  return;
}



/* 10029718 FUN_10029718 */

/* Boundary evidence: original MIPS .pdata 10029718..10029737. Semantic name remains unreviewed. */

undefined4 FUN_10029718(int param_1,int param_2)

{
  A_SHAFinal((void *)(param_1 + 4),param_2);
  return 0;
}



/* 10029738 FUN_10029738 */

/* Boundary evidence: original MIPS .pdata 10029738..100297cf. Semantic name remains unreviewed. */

undefined4 FUN_10029738(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == 0x8003) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = &PTR_FUN_10009128;
      MD5Init(param_2 + 1);
    }
  }
  else {
    if (param_1 != 0x8004) {
      *param_3 = 0;
      return 0x80090008;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = &PTR_FUN_10009134;
      A_SHAInit((int)(param_2 + 1));
    }
  }
  *param_3 = param_2;
  return 0;
}



/* 100297d0 FUN_100297d0 */

/* Boundary evidence: original MIPS .pdata 100297d0..10029897. Semantic name remains unreviewed. */

int FUN_100297d0(int param_1,int param_2,int *param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  int *local_f8 [2];
  undefined4 auStack_f0 [50];
  uint local_28;
  
  local_28 = DAT_1002da44;
  iVar1 = FUN_10029738(param_1,auStack_f0,local_f8);
  if (iVar1 == 0) {
    iVar1 = FUN_10029204(param_1,local_f8[0],param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_10029110(local_f8[0],param_4,0x14,param_5);
    }
  }
  FUN_1002bedc(local_28);
  return iVar1;
}



/* 10029898 FUN_10029898 */

/* Boundary evidence: original MIPS .pdata 10029898..10029a6f. Semantic name remains unreviewed. */

DWORD FUN_10029898(int param_1,LPCWSTR param_2,DWORD *param_3)

{
  DWORD DVar1;
  LPCWSTR hFileMappingObject;
  LPVOID pvVar2;
  DWORD DVar3;
  DWORD local_20 [2];
  
  DVar3 = 0;
  if (param_1 == 1) {
    hFileMappingObject =
         CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (hFileMappingObject != (LPCWSTR)0xffffffff) {
      DVar3 = FUN_10029898(2,hFileMappingObject,param_3);
      if (hFileMappingObject == (LPCWSTR)0x0) {
        return DVar3;
      }
LAB_10029a40:
      CloseHandle(hFileMappingObject);
      return DVar3;
    }
    hFileMappingObject = (LPCWSTR)0xffffffff;
LAB_100299f0:
    CloseHandle(hFileMappingObject);
  }
  else {
    if (param_1 != 2) {
      if (param_1 == 3) {
        *param_3 = *(DWORD *)param_2;
        param_3[1] = *(DWORD *)(param_2 + 2);
        return 0;
      }
      DVar3 = 0x57;
      goto LAB_10029a18;
    }
    local_20[0] = 0;
    DVar1 = GetFileSize(param_2,local_20);
    if (DVar1 != 0xffffffff) {
      if (local_20[0] != 0) {
        DVar3 = 0x3ee;
        goto LAB_10029a18;
      }
      hFileMappingObject = CreateFileMappingW(param_2,(LPSECURITY_ATTRIBUTES)0x0,2,0,0,(LPCWSTR)0x0)
      ;
      if (hFileMappingObject != (LPCWSTR)0x0) {
        pvVar2 = MapViewOfFile(hFileMappingObject,4,0,0,0);
        param_3[1] = (DWORD)pvVar2;
        if (pvVar2 != (LPVOID)0x0) {
          *param_3 = DVar1;
          goto LAB_10029a40;
        }
        goto LAB_100299f0;
      }
    }
  }
  DVar3 = GetLastError();
  if (DVar3 == 0) {
    DVar3 = 0x6e;
  }
LAB_10029a18:
  param_3[1] = 0;
  *param_3 = 0;
  return DVar3;
}



/* 10029a70 FUN_10029a70 */

/* Boundary evidence: original MIPS .pdata 10029a70..10029acf. Semantic name remains unreviewed. */

undefined * FUN_10029a70(void)

{
  if ((DAT_1002dcb8 & 1) == 0) {
    DAT_1002dcb8 = DAT_1002dcb8 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1002dca4);
    FUN_1002c0ac(FUN_1002c428);
  }
  return &DAT_1002dca4;
}



/* 10029ad0 FUN_10029ad0 */

/* Boundary evidence: original MIPS .pdata 10029ad0..10029baf. Semantic name remains unreviewed. */

size_t * FUN_10029ad0(size_t *param_1,size_t *param_2,uint param_3,int param_4)

{
  int iVar1;
  size_t *psVar2;
  uint uVar3;
  size_t _Size;
  size_t _Size_00;
  void *_Buf1;
  void *_Buf1_00;
  
  _Buf1 = (void *)param_1[1];
  _Size_00 = *param_1;
  _Buf1_00 = (void *)param_2[1];
  _Size = *param_2;
  if (((_Size_00 != 0) && (_Size != 0)) && (uVar3 = 0, param_3 != 0)) {
    psVar2 = (size_t *)(param_4 + 0x30);
    do {
      if (((_Size_00 == psVar2[2]) && (_Size == *psVar2)) &&
         ((iVar1 = memcmp(_Buf1_00,(void *)psVar2[1],_Size), iVar1 == 0 &&
          (iVar1 = memcmp(_Buf1,(void *)psVar2[3],_Size_00), iVar1 == 0)))) {
        return psVar2 + -0xc;
      }
      uVar3 = uVar3 + 1;
      psVar2 = psVar2 + 0x1e;
    } while (uVar3 < param_3);
  }
  return (size_t *)0x0;
}



/* 10029bb0 FUN_10029bb0 */

/* Boundary evidence: original MIPS .pdata 10029bb0..10029cdb. Semantic name remains unreviewed. */

int FUN_10029bb0(int param_1,void *param_2,uint *param_3,int *param_4)

{
  byte *pbVar1;
  int iVar2;
  undefined1 local_1c8 [4];
  uint local_1c4;
  size_t local_1c0;
  void *local_1bc;
  int local_1b8;
  undefined1 *local_1b4;
  int local_1b0;
  int local_1ac;
  undefined1 auStack_1a8 [400];
  
  local_1c8[0] = 0x31;
  local_1c4 = 10;
  pbVar1 = FUN_1002794c(param_4,&local_1c4,(int)auStack_1a8);
  if (((((int)pbVar1 < 1) || (local_1c4 == 0)) ||
      (iVar2 = FUN_1002866c((size_t *)&DAT_10009164,local_1c4,(int)auStack_1a8), iVar2 == 0)) ||
     (iVar2 = FUN_10028224(*(byte **)(iVar2 + 0x24),*(int *)(iVar2 + 0x20),&local_1c0,
                           (int *)&local_1bc), iVar2 < 1)) {
    iVar2 = -0x7ff6effa;
  }
  else if ((*param_3 == local_1c0) && (iVar2 = memcmp(param_2,local_1bc,local_1c0), iVar2 == 0)) {
    local_1b4 = local_1c8;
    local_1b8 = 1;
    local_1ac = param_4[1] + 1;
    local_1b0 = *param_4 + -1;
    iVar2 = FUN_100297d0(param_1,2,&local_1b8,param_2,param_3);
  }
  else {
    iVar2 = -0x7ff6eff9;
  }
  return iVar2;
}



/* 10029cdc FUN_10029cdc */

/* Boundary evidence: original MIPS .pdata 10029cdc..10029f47. Semantic name remains unreviewed. */

int FUN_10029cdc(byte *param_1,uint param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  size_t *psVar4;
  int iVar5;
  uint local_590;
  uint local_58c;
  uint uStack_588;
  int iStack_584;
  undefined1 auStack_580 [16];
  int local_570;
  void *local_56c;
  int local_558;
  int local_554;
  int local_550;
  byte *local_54c;
  int aiStack_548 [6];
  int local_530;
  size_t asStack_520 [2];
  size_t asStack_518 [2];
  uint auStack_510 [2];
  int local_508;
  int local_504;
  uint auStack_4f8 [2];
  int local_4f0;
  int local_4ec;
  undefined1 auStack_4e8 [1200];
  undefined1 auStack_38 [20];
  uint local_24;
  
  local_24 = DAT_1002da44;
  memset(param_5,0,0x28);
  pbVar2 = FUN_100277e8(param_1,param_2,(int)auStack_580);
  if ((((int)pbVar2 < 1) || (local_570 != 9)) ||
     (iVar3 = memcmp(&LAB_1000914c,local_56c,9), iVar3 != 0)) {
LAB_10029f10:
    iVar3 = -0x7ff6dff3;
  }
  else {
    if ((local_558 == 0) || (local_550 == 0)) {
      iVar3 = 0xe8;
      goto LAB_10029f18;
    }
    *param_5 = local_558;
    param_5[2] = local_550;
    param_5[1] = local_554;
    param_5[3] = (int)local_54c;
    if (local_530 != 0) {
      local_590 = 10;
      pbVar2 = FUN_10027838(aiStack_548,&local_590,(int)auStack_4e8);
      uVar1 = local_590;
      if (((0 < (int)pbVar2) && (local_590 != 0)) &&
         (psVar4 = FUN_10029ad0(asStack_520,asStack_518,local_590,(int)auStack_4e8),
         psVar4 != (size_t *)0x0)) {
        param_5[4] = psVar4[2];
        param_5[5] = psVar4[3];
        param_5[6] = local_508;
        param_5[7] = local_504;
        param_5[8] = local_4f0;
        param_5[9] = local_4ec;
        iVar3 = FUN_1002a854((int)psVar4,uVar1,(int)auStack_4e8,param_3,param_4);
        if (iVar3 != 0) goto LAB_10029f18;
        iVar5 = FUN_1002903c(auStack_510);
        if (iVar5 == 0) {
          iVar3 = -0x7ff6effe;
          goto LAB_10029f18;
        }
        iVar3 = FUN_10028224(local_54c,local_550,&uStack_588,&iStack_584);
        if (0 < iVar3) {
          iVar3 = FUN_100297d0(iVar5,1,(int *)&uStack_588,auStack_38,&local_58c);
          if ((iVar3 == 0) &&
             ((local_508 == 0 ||
              (iVar3 = FUN_10029bb0(iVar5,auStack_38,&local_58c,&local_508), iVar3 == 0)))) {
            iVar3 = FUN_10029598(iVar5,(int)auStack_38,local_58c,auStack_4f8,psVar4 + 0x16);
          }
          goto LAB_10029f18;
        }
        goto LAB_10029f10;
      }
    }
    iVar3 = -0x7ff6dff2;
  }
LAB_10029f18:
  FUN_1002bedc(local_24);
  return iVar3;
}



/* 10029f48 FUN_10029f48 */

/* Boundary evidence: original MIPS .pdata 10029f48..1002a00b. Semantic name remains unreviewed. */

undefined4 FUN_10029f48(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint local_1b0 [2];
  undefined1 auStack_1a8 [400];
  
  memset(param_4,0,param_2 << 3);
  local_1b0[0] = 10;
  pbVar1 = FUN_1002794c(param_1,local_1b0,(int)auStack_1a8);
  if ((int)pbVar1 < 1) {
    local_1b0[0] = 0;
  }
  if (param_2 != 0) {
    iVar3 = param_3 - (int)param_4;
    do {
      iVar2 = FUN_1002866c((size_t *)(iVar3 + (int)param_4),local_1b0[0],(int)auStack_1a8);
      if (iVar2 != 0) {
        param_4[1] = *(undefined4 *)(iVar2 + 0x24);
        *param_4 = *(undefined4 *)(iVar2 + 0x20);
      }
      param_4 = param_4 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 0;
}



/* 1002a00c FUN_1002a00c */

/* Boundary evidence: original MIPS .pdata 1002a00c..1002a16b. Semantic name remains unreviewed. */

int FUN_1002a00c(uint *param_1,uint param_2,int *param_3,int param_4,int param_5,undefined4 *param_6
                ,void *param_7,int *param_8,undefined4 *param_9)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int local_60;
  void *local_5c;
  uint auStack_58 [4];
  int aiStack_48 [4];
  undefined1 auStack_38 [32];
  uint auStack_18 [2];
  uint local_10;
  void *local_c;
  
  if ((((param_2 < 0xc) || (uVar3 = *param_1, param_2 < uVar3)) || ((short)param_1[1] != 0x200)) ||
     ((*(short *)((int)param_1 + 6) != 2 || (uVar3 < 8)))) {
    iVar1 = -0x7ff4ff00;
  }
  else {
    iVar1 = FUN_10029cdc((byte *)(param_1 + 2),uVar3 - 8,param_3,param_9,&local_60);
    if (iVar1 == 0) {
      if (((local_60 == 10) && (iVar1 = memcmp(&DAT_10009140,local_5c,10), iVar1 == 0)) &&
         (pbVar2 = FUN_10027a74(auStack_58,(int)auStack_38), 0 < (int)pbVar2)) {
        iVar1 = FUN_1002903c(auStack_18);
        if (iVar1 == 0) {
          return -0x7ff6effe;
        }
        if (param_8 != (int *)0x0) {
          *param_8 = iVar1;
        }
        if (local_10 < 0x15) {
          memcpy(param_7,local_c,local_10);
          if (param_4 != 0) {
            iVar1 = FUN_10029f48(aiStack_48,param_4,param_5,param_6);
            return iVar1;
          }
          return 0;
        }
      }
      return -0x7ff6dff3;
    }
  }
  if (iVar1 == 0x7a) {
    iVar1 = -0x7fff0001;
  }
  return iVar1;
}



/* 1002a16c FUN_1002a16c */

/* Boundary evidence: original MIPS .pdata 1002a16c..1002a24b. Semantic name remains unreviewed. */

int FUN_1002a16c(int *param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = *(uint *)(param_2 + 8);
  uVar2 = 0;
  if (uVar4 != 0) {
    iVar6 = *param_1;
    iVar5 = 0;
    piVar3 = (int *)(*(int *)(param_2 + 0xc) + 0x50);
    do {
      if ((*piVar3 == iVar6) &&
         (iVar1 = *(int *)(param_2 + 0xc) + iVar5,
         iVar1 = memcmp(*(void **)(iVar1 + 0x54),(void *)param_1[1],*(size_t *)(iVar1 + 0x50)),
         iVar1 == 0)) {
        *param_3 = uVar2;
        return uVar2 * 0x78 + *(int *)(param_2 + 0xc) + 0x58;
      }
      uVar2 = uVar2 + 1;
      iVar5 = iVar5 + 0x78;
      piVar3 = piVar3 + 0x1e;
    } while (uVar2 < uVar4);
  }
  return 0;
}



/* 1002a24c FUN_1002a24c */

/* Boundary evidence: original MIPS .pdata 1002a24c..1002a32b. Semantic name remains unreviewed. */

int FUN_1002a24c(int *param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = *(uint *)(param_2 + 8);
  uVar2 = 0;
  if (uVar4 != 0) {
    iVar6 = *param_1;
    iVar5 = 0;
    piVar3 = (int *)(*(int *)(param_2 + 0xc) + 0x58);
    do {
      if ((*piVar3 == iVar6) &&
         (iVar1 = *(int *)(param_2 + 0xc) + iVar5,
         iVar1 = memcmp(*(void **)(iVar1 + 0x5c),(void *)param_1[1],*(size_t *)(iVar1 + 0x58)),
         iVar1 == 0)) {
        *param_3 = uVar2;
        return uVar2 * 0x78 + *(int *)(param_2 + 0xc) + 0x58;
      }
      uVar2 = uVar2 + 1;
      iVar5 = iVar5 + 0x78;
      piVar3 = piVar3 + 0x1e;
    } while (uVar2 < uVar4);
  }
  return 0;
}



/* 1002a32c FUN_1002a32c */

/* Boundary evidence: original MIPS .pdata 1002a32c..1002a3db. Semantic name remains unreviewed. */

int FUN_1002a32c(size_t *param_1,uint param_2,int param_3)

{
  int iVar1;
  size_t *psVar2;
  uint uVar3;
  size_t _Size;
  void *_Buf1;
  
  _Size = *param_1;
  _Buf1 = (void *)param_1[1];
  if ((_Size != 0) && (uVar3 = 0, param_2 != 0)) {
    psVar2 = (size_t *)(param_3 + 0x50);
    do {
      if ((_Size == *psVar2) && (iVar1 = memcmp(_Buf1,(void *)psVar2[1],_Size), iVar1 == 0)) {
        return uVar3 * 0x78 + param_3;
      }
      uVar3 = uVar3 + 1;
      psVar2 = psVar2 + 0x1e;
    } while (uVar3 < param_2);
  }
  return 0;
}



/* 1002a3dc FUN_1002a3dc */

/* Boundary evidence: original MIPS .pdata 1002a3dc..1002a5df. Semantic name remains unreviewed. */

undefined4 FUN_1002a3dc(void *param_1,uint *param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  uint local_28 [2];
  short local_20;
  short local_1e;
  short local_1a;
  short local_18;
  short local_16;
  short local_14;
  undefined2 local_12;
  
  local_28[0] = *param_2;
  pcVar3 = (char *)param_2[1];
  if (*pcVar3 != '\x17') {
    return 0xffffffff;
  }
  iVar2 = FUN_10028158(local_28,(byte *)(pcVar3 + 1),local_28[0] - 1);
  local_20 = ((byte)pcVar3[iVar2 + 1] - 0x30) * 10 + (ushort)(byte)pcVar3[iVar2 + 2];
  if ((ushort)(local_20 - 0x30U) < 0x5a) {
    local_20 = local_20 + 0x7a0;
  }
  else {
    local_20 = local_20 + 0x73c;
  }
  local_14 = 0;
  local_1e = ((byte)pcVar3[iVar2 + 3] - 0x30) * 10 + (ushort)(byte)pcVar3[iVar2 + 4] + -0x30;
  local_28[0] = local_28[0] - 10;
  local_1a = ((byte)pcVar3[iVar2 + 5] - 0x30) * 10 + (ushort)(byte)pcVar3[iVar2 + 6] + -0x30;
  local_18 = ((byte)pcVar3[iVar2 + 7] - 0x30) * 10 + (ushort)(byte)pcVar3[iVar2 + 8] + -0x30;
  local_16 = ((byte)pcVar3[iVar2 + 9] - 0x30) * 10 + (ushort)(byte)pcVar3[iVar2 + 10] + -0x30;
  if ((local_28[0] != 0) && (bVar1 = pcVar3[iVar2 + 0xb], bVar1 != 0x5a)) {
    if ((bVar1 == 0x2b) || (bVar1 == 0x2d)) {
      if (local_28[0] != 5) {
        return 0xffffffff;
      }
    }
    else {
      local_14 = (bVar1 - 0x30) * 10 + (ushort)(byte)pcVar3[iVar2 + 0xc] + -0x30;
      if ((local_28[0] == 3) && (pcVar3[iVar2 + 0xd] != 'Z')) {
        return 0xffffffff;
      }
    }
  }
  local_12 = 0;
  memcpy(param_1,&local_20,0x10);
  return 0;
}



/* 1002a5e0 FUN_1002a5e0 */

/* Boundary evidence: original MIPS .pdata 1002a5e0..1002a727. Semantic name remains unreviewed. */

undefined4 FUN_1002a5e0(int param_1,ushort *param_2)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  ushort local_30;
  ushort local_2e;
  ushort local_2a;
  ushort local_20;
  ushort local_1e;
  ushort local_1a;
  
  iVar3 = FUN_1002a3dc(&local_30,(uint *)(param_1 + 0x40));
  if (iVar3 < 0) {
    return 0x8000ffff;
  }
  iVar3 = FUN_1002a3dc(&local_20,(uint *)(param_1 + 0x48));
  if (iVar3 < 0) {
    return 0x8000ffff;
  }
  uVar1 = *param_2;
  if (uVar1 == local_30) {
    if (param_2[1] == local_2e) {
      if ((param_2[3] != local_2a) && (param_2[3] <= local_2a)) {
        return 0x800b0101;
      }
      goto LAB_1002a69c;
    }
    bVar2 = local_2e < param_2[1];
  }
  else {
    bVar2 = local_30 < uVar1;
  }
  if (!bVar2) {
    return 0x800b0101;
  }
LAB_1002a69c:
  if (uVar1 == local_20) {
    if (param_2[1] == local_1e) {
      if (param_2[3] == local_1a) {
        return 0;
      }
      if (local_1a < param_2[3]) {
        return 0x800b0101;
      }
      return 0;
    }
    bVar2 = local_1e < param_2[1];
  }
  else {
    bVar2 = local_20 < uVar1;
  }
  if (bVar2) {
    return 0x800b0101;
  }
  return 0;
}



/* 1002a728 FUN_1002a728 */

/* Boundary evidence: original MIPS .pdata 1002a728..1002a837. Semantic name remains unreviewed. */

uint FUN_1002a728(undefined4 param_1,uint param_2,uint param_3,int param_4,undefined *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (param_3 - 1) * param_4 + param_2;
  if (param_2 <= uVar4) {
    do {
      uVar3 = param_3 >> 1;
      if (uVar3 == 0) {
        if (param_3 == 0) {
          return 0;
        }
        iVar1 = (*(code *)param_5)(param_1,param_2);
        if (iVar1 != 0) {
          return 0;
        }
        return param_2;
      }
      uVar2 = uVar3;
      if ((param_3 & 1) == 0) {
        uVar2 = uVar3 - 1;
      }
      uVar2 = uVar2 * param_4 + param_2;
      iVar1 = (*(code *)param_5)(param_1,uVar2);
      if (iVar1 == 0) {
        return uVar2;
      }
      if (iVar1 < 0) {
        uVar4 = uVar2 - param_4;
        if ((param_3 & 1) == 0) {
          uVar3 = uVar3 - 1;
        }
      }
      else {
        param_2 = uVar2 + param_4;
      }
      param_3 = uVar3;
    } while (param_2 <= uVar4);
  }
  return 0;
}



/* 1002a838 FUN_1002a838 */

/* Boundary evidence: original MIPS .pdata 1002a838..1002a853. Semantic name remains unreviewed. */

void FUN_1002a838(void *param_1,void *param_2)

{
  memcmp(param_1,param_2,0x14);
  return;
}



/* 1002a854 FUN_1002a854 */

/* Boundary evidence: original MIPS .pdata 1002a854..1002ab3f. Semantic name remains unreviewed. */

int FUN_1002a854(int param_1,uint param_2,int param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  size_t *psVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_70;
  uint local_6c;
  int local_68;
  int local_64;
  uint local_60;
  int local_5c;
  undefined1 local_58;
  undefined1 auStack_57 [23];
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_1002da44;
  local_70 = 0xffffffff;
  uVar8 = 0;
  local_68 = 0;
  local_64 = param_1;
  local_60 = param_2;
  local_5c = param_3;
  if ((*param_4 == 1) && ((param_4[1] & 0xffffffeeU) == 0)) {
    do {
      iVar7 = 0;
      iVar1 = FUN_1002903c((uint *)(param_1 + 0x18));
      if (iVar1 == 0) {
        iVar2 = -0x7ff6effe;
        goto LAB_1002ab04;
      }
      iVar2 = FUN_100297d0(iVar1,1,(int *)(param_1 + 0x10),auStack_40,&local_6c);
      if (iVar2 != 0) goto LAB_1002ab04;
      uVar4 = param_4[4];
      if (uVar4 != 0) {
        uVar6 = param_4[5];
        local_58 = 0;
        memset(auStack_57,0,0x13);
        if (local_6c < 0x15) {
          memcpy(&local_58,auStack_40,local_6c);
          uVar4 = FUN_1002a728(&local_58,uVar6,uVar4,0x14,FUN_1002a838);
          if (uVar4 != 0) {
            iVar2 = -0x7ff4fef4;
            goto LAB_1002ab04;
          }
        }
      }
      uVar4 = local_6c;
      psVar5 = (size_t *)(param_1 + 0x38);
      if ((*psVar5 == *(size_t *)(param_1 + 0x50)) &&
         (iVar2 = memcmp(*(void **)(param_1 + 0x3c),*(void **)(param_1 + 0x54),*psVar5), iVar2 == 0)
         ) {
        iVar2 = FUN_1002a24c((int *)(param_1 + 0x58),(int)param_4,&local_70);
        if (iVar2 == 0) {
          iVar2 = -0x7ff4fef7;
        }
        else {
LAB_1002aad0:
          iVar2 = 0;
          param_5[1] = local_70;
          *param_5 = 0;
        }
        goto LAB_1002ab04;
      }
      if ((param_1 == local_64) &&
         (iVar2 = FUN_1002a24c((int *)(param_1 + 0x58),(int)param_4,&local_70), iVar2 != 0))
      goto LAB_1002aad0;
      puVar3 = (uint *)FUN_1002a16c((int *)psVar5,(int)param_4,&local_70);
      if (puVar3 == (uint *)0x0) {
        iVar7 = FUN_1002a32c(psVar5,local_60,local_5c);
        if (iVar7 == 0) break;
        puVar3 = (uint *)(iVar7 + 0x58);
      }
      else {
        local_68 = 1;
      }
      if ((((param_4[1] & 1U) != 0) &&
          (iVar2 = FUN_1002a5e0(param_1,(ushort *)(param_4 + 6)), uVar4 = local_6c, iVar2 != 0)) ||
         (iVar2 = FUN_10029598(iVar1,(int)auStack_40,uVar4,(uint *)(param_1 + 0x20),puVar3),
         iVar2 != 0)) goto LAB_1002ab04;
      if (local_68 != 0) goto LAB_1002aad0;
      uVar8 = uVar8 + 1;
      param_1 = iVar7;
    } while (uVar8 < 0xb);
    iVar2 = -0x7ff4fef6;
  }
  else {
    iVar2 = -0x7ff6fcfe;
  }
LAB_1002ab04:
  FUN_1002bedc(local_2c);
  return iVar2;
}



/* 1002ab40 FUN_1002ab40 */

undefined4 FUN_1002ab40(uint param_1,int param_2,int param_3,int param_4,uint *param_5)

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
  return 0x80070216;
}



/* 1002aba0 FUN_1002aba0 */

/* Boundary evidence: original MIPS .pdata 1002aba0..1002ac1f. Semantic name remains unreviewed. */

undefined4
FUN_1002aba0(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,uint *param_11)

{
  int iVar1;
  
  iVar1 = FUN_1002ab40(param_1,param_2,param_3,param_4,param_11);
  if (((-1 < iVar1) &&
      (iVar1 = FUN_1002ab40(*param_11,param_5,param_6,param_7,param_11), -1 < iVar1)) &&
     (iVar1 = FUN_1002ab40(*param_11,param_8,param_9,param_10,param_11), -1 < iVar1)) {
    return 0;
  }
  return 0x80070216;
}



/* 1002ac20 FUN_1002ac20 */

/* Boundary evidence: original MIPS .pdata 1002ac20..1002ac7f. Semantic name remains unreviewed. */

DWORD FUN_1002ac20(DATA_BLOB *param_1,LPCWSTR param_2,DATA_BLOB *param_3,PVOID param_4,
                  undefined4 param_5,DWORD param_6,DATA_BLOB *param_7)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = CryptProtectData(param_1,param_2,param_3,param_4,(CRYPTPROTECT_PROMPTSTRUCT *)0x0,param_6,
                           param_7);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  return DVar2;
}



/* 1002ac80 FUN_1002ac80 */

/* Boundary evidence: original MIPS .pdata 1002ac80..1002aceb. Semantic name remains unreviewed. */

DWORD FUN_1002ac80(DATA_BLOB *param_1,LPWSTR *param_2,DATA_BLOB *param_3,PVOID param_4,
                  undefined4 param_5,DWORD param_6,DATA_BLOB *param_7,undefined4 *param_8)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  BVar1 = CryptUnprotectData(param_1,param_2,param_3,param_4,(CRYPTPROTECT_PROMPTSTRUCT *)0x0,
                             param_6,param_7);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  return DVar2;
}



/* 1002acec FUN_1002acec */

/* Boundary evidence: original MIPS .pdata 1002acec..1002ad4f. Semantic name remains unreviewed. */

undefined4 FUN_1002acec(wchar_t *param_1,int param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  undefined4 uVar2;
  
  sVar1 = wcslen(param_1);
  _Dest = LocalAlloc(0x40,(sVar1 + 1) * 2);
  *(wchar_t **)(param_2 + 0x40) = _Dest;
  if (_Dest == (wchar_t *)0x0) {
    uVar2 = 8;
  }
  else {
    wcscpy(_Dest,param_1);
    uVar2 = 0;
  }
  return uVar2;
}



/* 1002ad50 FUN_1002ad50 */

/* Boundary evidence: original MIPS .pdata 1002ad50..1002adf3. Semantic name remains unreviewed. */

DWORD FUN_1002ad50(void)

{
  DWORD DVar1;
  BYTE local_28 [8];
  DATA_BLOB local_20;
  DATA_BLOB local_18;
  DATA_BLOB DStack_10;
  
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  memset(&local_20,0,8);
  memset(&DStack_10,0,8);
  local_20.pbData = local_28;
  local_18.pbData = "Hj1diQ6kpUx7VC4m";
  local_20.cbData = 4;
  local_18.cbData = 0x11;
  DVar1 = FUN_1002ac20(&local_20,L"Export Flag",&local_18,(PVOID)0x0,0,0,&DStack_10);
  if (DStack_10.pbData != (BYTE *)0x0) {
    LocalFree(DStack_10.pbData);
  }
  return DVar1;
}



/* 1002adf4 FUN_1002adf4 */

/* Boundary evidence: original MIPS .pdata 1002adf4..1002af17. Semantic name remains unreviewed. */

undefined4
FUN_1002adf4(int param_1,wchar_t *param_2,wchar_t *param_3,undefined4 *param_4,int *param_5,
            int param_6)

{
  size_t sVar1;
  size_t sVar2;
  HLOCAL _Dst;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 == 0) {
    *param_4 = 0x80000001;
  }
  else {
    *param_4 = 0x80000002;
  }
  sVar1 = wcslen(param_2);
  sVar1 = sVar1 * 2;
  if (param_6 == 0) {
    sVar2 = wcslen(param_3);
    iVar4 = sVar2 << 1;
  }
  _Dst = LocalAlloc(0x40,sVar1 + iVar4 + 0x42);
  *param_5 = (int)_Dst;
  if (_Dst == (HLOCAL)0x0) {
    uVar3 = 8;
  }
  else {
    memcpy(_Dst,L"Comm\\Security\\Crypto\\UserKeys",0x3c);
    *(undefined2 *)(*param_5 + 0x3a) = 0x5c;
    memcpy((void *)(*param_5 + 0x3c),param_2,sVar1);
    if (param_6 == 0) {
      *(undefined2 *)(*param_5 + sVar1 + 0x3e + -2) = 0x5c;
      wcscpy((wchar_t *)(*param_5 + sVar1 + 0x3e),param_3);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 1002af18 FUN_1002af18 */

/* Boundary evidence: original MIPS .pdata 1002af18..1002afa7. Semantic name remains unreviewed. */

undefined4 FUN_1002af18(undefined4 param_1,wchar_t *param_2,undefined4 *param_3)

{
  size_t sVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  *param_3 = 0;
  sVar1 = wcslen(param_2);
  puVar2 = LocalAlloc(0x40,(sVar1 + 9) * 2);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0x8009000e;
  }
  else {
    *puVar2 = puVar2 + 4;
    wcscpy((wchar_t *)(puVar2 + 4),param_2);
    puVar2[1] = param_1;
    *param_3 = puVar2;
    uVar3 = 0;
  }
  return uVar3;
}



/* 1002afa8 FUN_1002afa8 */

/* Boundary evidence: original MIPS .pdata 1002afa8..1002afcb. Semantic name remains unreviewed. */

void FUN_1002afa8(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    LocalFree(param_1);
  }
  return;
}



/* 1002afcc FUN_1002afcc */

/* Boundary evidence: original MIPS .pdata 1002afcc..1002b1c7. Semantic name remains unreviewed. */

int FUN_1002afcc(undefined4 *param_1,LPWSTR param_2,uint *param_3)

{
  LPCWSTR hMem;
  int iVar1;
  LPDWORD lpcbMaxSubKeyLen;
  HKEY local_48;
  LPCWSTR local_44;
  uint local_40;
  HKEY local_3c;
  DWORD DStack_38;
  DWORD DStack_34;
  DWORD DStack_30;
  DWORD DStack_2c;
  DWORD aDStack_28 [2];
  _FILETIME _Stack_20;
  
  local_48 = (HKEY)0x0;
  local_44 = (LPCWSTR)0x0;
  if (param_1 == (undefined4 *)0x0) {
    return -0x7ff6ffe0;
  }
  iVar1 = FUN_1002adf4(param_1[1],(wchar_t *)*param_1,L"",&local_3c,(int *)&local_44,1);
  hMem = local_44;
  if (iVar1 == 0) {
    iVar1 = RegOpenKeyExW(local_3c,local_44,0,0x20019,&local_48);
    LocalFree(hMem);
    if (iVar1 == 0) {
      if (param_1[2] == 0) {
        lpcbMaxSubKeyLen = param_1 + 3;
        iVar1 = RegQueryInfoKeyW(local_48,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,aDStack_28,
                                 lpcbMaxSubKeyLen,&DStack_2c,&DStack_30,&DStack_34,&DStack_38,
                                 (LPDWORD)0x0,&_Stack_20);
        if (iVar1 != 0) goto LAB_1002b188;
        *lpcbMaxSubKeyLen = *lpcbMaxSubKeyLen + 1;
      }
      if ((param_2 == (LPWSTR)0x0) || (*param_3 < (uint)param_1[3])) {
        iVar1 = 0;
        *param_3 = param_1[3];
        if (param_2 != (LPWSTR)0x0) {
          iVar1 = 0xea;
        }
      }
      else {
        local_40 = *param_3;
        iVar1 = RegEnumKeyExW(local_48,param_1[2],param_2,&local_40,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_20);
        if (iVar1 == 0) {
          *param_3 = local_40 + 1;
          param_1[2] = param_1[2] + 1;
        }
      }
    }
  }
LAB_1002b188:
  if (local_48 != (HKEY)0x0) {
    RegCloseKey(local_48);
  }
  return iVar1;
}



/* 1002b1c8 FUN_1002b1c8 */

/* Boundary evidence: original MIPS .pdata 1002b1c8..1002b4fb. Semantic name remains unreviewed. */

int FUN_1002b1c8(wchar_t *param_1,int param_2,int *param_3)

{
  LPCWSTR hMem;
  int iVar1;
  size_t sVar2;
  int iVar3;
  DWORD cbData;
  size_t _Size;
  BYTE *lpData;
  size_t _Size_00;
  uint uVar4;
  HKEY local_40;
  LPCWSTR local_3c;
  HKEY local_38 [2];
  size_t local_30;
  size_t local_2c;
  
  local_40 = (HKEY)0x0;
  local_3c = (LPCWSTR)0x0;
  lpData = (BYTE *)0x0;
  memset(&local_30,0,8);
  iVar1 = FUN_1002adf4(param_2,param_1,(wchar_t *)param_3[0x10],local_38,(int *)&local_3c,0);
  hMem = local_3c;
  if (iVar1 == 0) {
    iVar1 = RegCreateKeyExW(local_38[0],local_3c,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                            &local_40,(LPDWORD)0x0);
    if (iVar1 == 0) {
      uVar4 = param_3[3];
      if ((uVar4 == 0) || (_Size_00 = 4, param_3[4] == 0)) {
        _Size_00 = local_30;
      }
      iVar1 = param_3[5];
      if ((iVar1 == 0) || (_Size = 4, param_3[6] == 0)) {
        _Size = local_2c;
      }
      sVar2 = wcslen((wchar_t *)param_3[0x10]);
      iVar3 = (sVar2 + 1) * 2;
      param_3[2] = iVar3;
      iVar1 = FUN_1002aba0(uVar4,param_3[4],iVar1,param_3[6],_Size_00,_Size,iVar3,param_3[7],8,0x4c,
                           (uint *)local_38);
      if ((iVar1 < 0) || (lpData = LocalAlloc(0x40,(SIZE_T)local_38[0]), lpData == (BYTE *)0x0)) {
        iVar1 = 8;
      }
      else {
        *param_3 = 0x10002;
        lpData[0] = '\x02';
        lpData[1] = '\0';
        lpData[2] = '\x01';
        lpData[3] = '\0';
        memcpy(lpData + 4,param_3 + 1,0x1c);
        if (*param_3 == 0x10002) {
          *(size_t *)(lpData + 0x20) = _Size_00;
          *(size_t *)(lpData + 0x24) = _Size;
          memcpy(lpData + 0x28,(void *)param_3[0x10],param_3[2]);
          iVar1 = param_3[2];
          memcpy(lpData + iVar1 + 0x28,(void *)param_3[0xf],param_3[7]);
          cbData = iVar1 + 0x28 + param_3[7];
          if ((param_3[3] != 0) || (param_3[4] != 0)) {
            memcpy(lpData + cbData,(void *)param_3[9],param_3[3]);
            iVar1 = param_3[3];
            memcpy(lpData + cbData + iVar1,(void *)param_3[10],param_3[4]);
            iVar1 = cbData + iVar1 + param_3[4];
            memcpy(lpData + iVar1,param_3 + 0xb,_Size_00);
            cbData = iVar1 + _Size_00;
          }
          if ((param_3[5] != 0) || (param_3[6] != 0)) {
            memcpy(lpData + cbData,(void *)param_3[0xc],param_3[5]);
            iVar1 = param_3[5];
            memcpy(lpData + cbData + iVar1,(void *)param_3[0xd],param_3[6]);
            iVar1 = cbData + iVar1 + param_3[6];
            memcpy(lpData + iVar1,param_3 + 0xe,_Size);
            cbData = iVar1 + _Size;
          }
          iVar1 = RegSetValueExW(local_40,(LPCWSTR)0x0,0,3,lpData,cbData);
        }
        else {
          iVar1 = -0x7ff6ffe6;
        }
      }
    }
  }
  if (hMem != (LPCWSTR)0x0) {
    LocalFree(hMem);
  }
  if (lpData != (BYTE *)0x0) {
    LocalFree(lpData);
  }
  if (local_40 != (HKEY)0x0) {
    RegCloseKey(local_40);
  }
  return iVar1;
}



/* 1002b4fc FUN_1002b4fc */

/* Boundary evidence: original MIPS .pdata 1002b4fc..1002b5e7. Semantic name remains unreviewed. */

int FUN_1002b4fc(wchar_t *param_1,wchar_t *param_2,int param_3)

{
  LPCWSTR lpSubKey;
  int iVar1;
  LPCWSTR local_20;
  HKEY local_1c;
  HKEY local_18 [2];
  
  local_1c = (HKEY)0x0;
  local_20 = (LPCWSTR)0x0;
  iVar1 = FUN_1002adf4(param_3,param_1,param_2,local_18,(int *)&local_20,0);
  lpSubKey = local_20;
  if (iVar1 == 0) {
    iVar1 = RegOpenKeyExW(local_18[0],local_20,0,0xf003f,&local_1c);
    if (iVar1 == 2) {
      iVar1 = -0x7ff6ffea;
    }
    if (iVar1 == 0) {
      RegCloseKey(local_1c);
      iVar1 = RegDeleteKeyW(local_18[0],lpSubKey);
    }
  }
  if (lpSubKey != (LPCWSTR)0x0) {
    LocalFree(lpSubKey);
  }
  return iVar1;
}



/* 1002b5e8 FUN_1002b5e8 */

/* Boundary evidence: original MIPS .pdata 1002b5e8..1002b6cf. Semantic name remains unreviewed. */

void FUN_1002b5e8(int param_1)

{
  if (param_1 != 0) {
    if (*(HLOCAL *)(param_1 + 0x24) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if (*(void **)(param_1 + 0x28) != (void *)0x0) {
      memset(*(void **)(param_1 + 0x28),0,*(size_t *)(param_1 + 0x10));
      LocalFree(*(HLOCAL *)(param_1 + 0x28));
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(HLOCAL *)(param_1 + 0x30) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x30));
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    if (*(void **)(param_1 + 0x34) != (void *)0x0) {
      memset(*(void **)(param_1 + 0x34),0,*(size_t *)(param_1 + 0x18));
      LocalFree(*(HLOCAL *)(param_1 + 0x34));
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    if (*(HLOCAL *)(param_1 + 0x3c) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x3c));
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    if (*(HLOCAL *)(param_1 + 0x40) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x40));
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
  }
  return;
}



/* 1002b6e4 FUN_1002b6e4 */

bool FUN_1002b6e4(int *param_1,int param_2,int *param_3)

{
  for (; *param_1 != 0; param_1 = param_1 + 0x25) {
    if (*param_1 == param_2) goto LAB_1002b6f4;
  }
  param_1 = (int *)0x0;
LAB_1002b6f4:
  if (param_3 != (int *)0x0) {
    *param_3 = (int)param_1;
  }
  return param_1 != (int *)0x0;
}



/* 1002b714 FUN_1002b714 */

undefined4 FUN_1002b714(int *param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  
  if (param_4 == (int *)0x0) {
    iVar1 = *param_1;
    param_4 = param_1;
    while (iVar1 != 0) {
      if (iVar1 == param_2) goto LAB_1002b744;
      param_4 = param_4 + 0x25;
      iVar1 = *param_4;
    }
    param_4 = (int *)0x0;
LAB_1002b744:
    if (param_4 == (int *)0x0) {
      return 0;
    }
  }
  if (((uint)param_4[2] <= param_3) && (param_3 <= (uint)param_4[3])) {
    return 1;
  }
  return 0;
}



/* 1002b778 FUN_1002b778 */

undefined4 FUN_1002b778(int *param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  *param_4 = 0;
  if (param_3 == (int *)0x0) {
    iVar1 = *param_1;
    param_3 = param_1;
    while (iVar1 != 0) {
      if (iVar1 == param_2) goto LAB_1002b7a8;
      param_3 = param_3 + 0x25;
      iVar1 = *param_3;
    }
    param_3 = (int *)0x0;
LAB_1002b7a8:
    if (param_3 == (int *)0x0) {
      return 0;
    }
  }
  *param_4 = param_3[1];
  return 1;
}



/* 1002b7cc FUN_1002b7cc */

/* Boundary evidence: original MIPS .pdata 1002b7cc..1002bc27. Semantic name remains unreviewed. */

DWORD FUN_1002b7cc(wchar_t *param_1,wchar_t *param_2,int param_3,uint param_4,int *param_5)

{
  LPCWSTR hMem;
  DWORD DVar1;
  LSTATUS LVar2;
  HLOCAL pvVar3;
  int iVar4;
  int iVar5;
  DWORD DVar6;
  int *lpData;
  uint uBytes;
  int iVar7;
  int iVar8;
  HKEY local_40;
  HKEY local_3c;
  LPCWSTR local_38;
  DWORD local_34;
  HKEY local_30 [2];
  
  local_40 = (HKEY)0x0;
  local_38 = (LPCWSTR)0x0;
  DVar6 = 0x54f;
  lpData = (int *)0x0;
  DVar1 = FUN_1002adf4(param_3,param_1,param_2,local_30,(int *)&local_38,0);
  hMem = local_38;
  if (DVar1 != 0) goto LAB_1002bbac;
  DVar1 = RegOpenKeyExW(local_30[0],local_38,0,0xf003f,&local_40);
  if (DVar1 == 2) {
    DVar1 = 0x80090016;
  }
  if (DVar1 != 0) goto LAB_1002bbac;
  if ((param_4 & 8) != 0) {
    DVar1 = 0x8009000f;
    goto LAB_1002bbac;
  }
  DVar1 = RegQueryValueExW(local_40,(LPCWSTR)0x0,(LPDWORD)0x0,&local_34,(LPBYTE)0x0,
                           (LPDWORD)&local_3c);
  if (DVar1 != 0) goto LAB_1002bbac;
  lpData = LocalAlloc(0x40,(SIZE_T)local_3c);
  if (lpData == (int *)0x0) {
    DVar1 = 8;
    goto LAB_1002bbac;
  }
  LVar2 = RegQueryValueExW(local_40,(LPCWSTR)0x0,(LPDWORD)0x0,&local_34,(LPBYTE)lpData,
                           (LPDWORD)&local_3c);
  if (LVar2 != 0) {
    DVar1 = GetLastError();
    goto LAB_1002bbac;
  }
  if ((local_34 != 3) || (local_3c < (HKEY)0x24)) {
    DVar1 = 0x8009001a;
    goto LAB_1002bbac;
  }
  iVar5 = *lpData;
  *param_5 = iVar5;
  DVar1 = DVar6;
  if (iVar5 != 0x10002) goto LAB_1002bbac;
  memcpy(param_5 + 1,lpData + 1,0x1c);
  if ((param_5[8] != 0) && (param_5[1] != 0)) {
    DVar1 = 0x80090022;
    goto LAB_1002bbac;
  }
  iVar7 = lpData[8];
  iVar8 = lpData[9];
  uBytes = param_5[2];
  iVar5 = FUN_1002aba0(uBytes,param_5[7],param_5[3],param_5[4],iVar7,param_5[5],param_5[6],iVar8,
                       0x28,0,(uint *)local_30);
  if ((iVar5 < 0) || (local_3c < local_30[0])) goto LAB_1002bbac;
  pvVar3 = LocalAlloc(0x40,uBytes);
  param_5[0x10] = (int)pvVar3;
  if (pvVar3 != (HLOCAL)0x0) {
    memcpy(pvVar3,lpData + 10,param_5[2]);
    iVar5 = param_5[2];
    pvVar3 = LocalAlloc(0x40,param_5[7]);
    param_5[0xf] = (int)pvVar3;
    if (pvVar3 != (HLOCAL)0x0) {
      memcpy(pvVar3,(LPBYTE)(iVar5 + 0x28 + (int)lpData),param_5[7]);
      iVar5 = param_5[7] + iVar5 + 0x28;
      if ((param_5[3] == 0) || (param_5[4] == 0)) {
LAB_1002bb04:
        if ((param_5[5] == 0) || (param_5[6] == 0)) {
LAB_1002bb94:
          param_5 = (int *)0x0;
          DVar1 = 0;
          goto LAB_1002bbac;
        }
        pvVar3 = LocalAlloc(0x40,param_5[5]);
        param_5[0xc] = (int)pvVar3;
        if (pvVar3 != (HLOCAL)0x0) {
          memcpy(pvVar3,(LPBYTE)(iVar5 + (int)lpData),param_5[5]);
          iVar7 = param_5[5];
          pvVar3 = LocalAlloc(0x40,param_5[6]);
          param_5[0xd] = (int)pvVar3;
          if (pvVar3 != (HLOCAL)0x0) {
            memcpy(pvVar3,(LPBYTE)(iVar7 + iVar5 + (int)lpData),param_5[6]);
            if ((iVar8 == 4) && (*(LPBYTE)(param_5[6] + iVar7 + iVar5 + (int)lpData) == '\x01')) {
              param_5[0xe] = 1;
            }
            else {
              param_5[0xe] = 0;
            }
            goto LAB_1002bb94;
          }
        }
      }
      else {
        pvVar3 = LocalAlloc(0x40,param_5[3]);
        param_5[9] = (int)pvVar3;
        if (pvVar3 != (HLOCAL)0x0) {
          memcpy(pvVar3,(LPBYTE)(iVar5 + (int)lpData),param_5[3]);
          iVar4 = param_5[3];
          pvVar3 = LocalAlloc(0x40,param_5[4]);
          param_5[10] = (int)pvVar3;
          if (pvVar3 != (HLOCAL)0x0) {
            memcpy(pvVar3,(LPBYTE)(iVar4 + iVar5 + (int)lpData),param_5[4]);
            iVar5 = iVar4 + iVar5 + param_5[4];
            if ((iVar7 == 4) && (*(LPBYTE)(iVar5 + (int)lpData) == '\x01')) {
              param_5[0xb] = 1;
            }
            else {
              param_5[0xb] = 0;
            }
            iVar5 = iVar5 + iVar7;
            goto LAB_1002bb04;
          }
        }
      }
    }
  }
  DVar1 = 8;
LAB_1002bbac:
  if (hMem != (LPCWSTR)0x0) {
    LocalFree(hMem);
  }
  if (param_5 != (int *)0x0) {
    FUN_1002b5e8((int)param_5);
  }
  if (lpData != (int *)0x0) {
    LocalFree(lpData);
  }
  if (local_40 != (HKEY)0x0) {
    RegCloseKey(local_40);
  }
  return DVar1;
}



/* 1002bc28 FUN_1002bc28 */

/* Boundary evidence: original MIPS .pdata 1002bc28..1002bd63. Semantic name remains unreviewed. */

int FUN_1002bc28(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_1002dd24 != (code *)0x0) {
      iVar2 = (*DAT_1002dd24)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_1002bcd8;
    FUN_1002c240();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_10009df8(param_1,param_2);
  }
LAB_1002bcd8:
  if (((param_2 == 0) && (FUN_1002c1c8(), iVar1 != 0)) && (DAT_1002dd24 != (code *)0x0)) {
    iVar1 = (*DAT_1002dd24)(param_1,0,param_3);
  }
  return iVar1;
}



/* 1002bd64 FUN_1002bd64 */

/* Boundary evidence: original MIPS .pdata 1002bd64..1002bd8f. Semantic name remains unreviewed. */

void FUN_1002bd64(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 1002bd90 entry */

/* Boundary evidence: original MIPS .pdata 1002bd90..1002bde7. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_1002bde8();
  }
  FUN_1002bc28(param_1,param_2,param_3);
  return;
}



/* 1002bde8 FUN_1002bde8 */

/* Boundary evidence: original MIPS .pdata 1002bde8..1002be5b. Semantic name remains unreviewed. */

void FUN_1002bde8(void)

{
  uint uVar1;
  
  if ((DAT_1002da44 == 0) || (DAT_1002da44 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_1002da44 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_1002da44 == 0) {
      DAT_1002da44 = 0xb064;
    }
  }
  DAT_1002da48 = ~DAT_1002da44;
  return;
}



/* 1002be5c FUN_1002be5c */

/* Boundary evidence: original MIPS .pdata 1002be5c..1002beaf. Semantic name remains unreviewed. */

void FUN_1002be5c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_1002bedc(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 1002beb0 FUN_1002beb0 */

/* Boundary evidence: original MIPS .pdata 1002beb0..1002bedb. Semantic name remains unreviewed. */

undefined4 FUN_1002beb0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_1002be5c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 1002bedc FUN_1002bedc */

/* Boundary evidence: original MIPS .pdata 1002bedc..1002bf23. Semantic name remains unreviewed. */

void FUN_1002bedc(uint param_1)

{
  if ((param_1 == DAT_1002da44) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 1002bf24 FUN_1002bf24 */

/* Boundary evidence: original MIPS .pdata 1002bf24..1002bf9f. Semantic name remains unreviewed. */

void FUN_1002bf24(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_1002be5c(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* 1002bfa0 FUN_1002bfa0 */

/* Boundary evidence: original MIPS .pdata 1002bfa0..1002c0ab. Semantic name remains unreviewed. */

undefined4 FUN_1002bfa0(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_1002dd20;
  puVar3 = DAT_1002dd1c;
  iVar4 = (int)DAT_1002dd1c - (int)DAT_1002dd20;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_1002bfe4:
    param_1 = 0;
  }
  else {
    if (DAT_1002dd20 != (void *)0x0) {
      uVar1 = _msize(DAT_1002dd20);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_1002c058:
        if (pvVar2 == (void *)0x0) goto LAB_1002bfe4;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_1002c058;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_1002dd1c = puVar3 + 1;
    *puVar3 = param_1;
    DAT_1002dd20 = pvVar2;
  }
  return param_1;
}



/* 1002c0ac FUN_1002c0ac */

/* Boundary evidence: original MIPS .pdata 1002c0ac..1002c0db. Semantic name remains unreviewed. */

undefined4 FUN_1002c0ac(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_1002bfa0(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 1002c0dc FUN_1002c0dc */

/* Boundary evidence: original MIPS .pdata 1002c0dc..1002c1c7. Semantic name remains unreviewed. */

void FUN_1002c0dc(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_1002dd18 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_1002dd20;
    if (DAT_1002dd20 != (undefined4 *)0x0) {
      while (DAT_1002dd1c = DAT_1002dd1c + -1, _Memory <= DAT_1002dd1c) {
        if ((code *)*DAT_1002dd1c != (code *)0x0) {
          (*(code *)*DAT_1002dd1c)();
          _Memory = DAT_1002dd20;
        }
      }
      free(_Memory);
      DAT_1002dd1c = (undefined4 *)0x0;
      DAT_1002dd20 = (undefined4 *)0x0;
    }
    FUN_1002c1ec((undefined4 *)&DAT_10001014,(undefined4 *)&DAT_10001018);
  }
  FUN_1002c1ec((undefined4 *)&DAT_1000101c,(undefined4 *)&DAT_10001020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 1002c1c8 FUN_1002c1c8 */

/* Boundary evidence: original MIPS .pdata 1002c1c8..1002c1eb. Semantic name remains unreviewed. */

void FUN_1002c1c8(void)

{
  FUN_1002c0dc(0,0,1);
  return;
}



/* 1002c1ec FUN_1002c1ec */

/* Boundary evidence: original MIPS .pdata 1002c1ec..1002c23f. Semantic name remains unreviewed. */

void FUN_1002c1ec(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 1002c240 FUN_1002c240 */

/* Boundary evidence: original MIPS .pdata 1002c240..1002c27b. Semantic name remains unreviewed. */

void FUN_1002c240(void)

{
  FUN_1002c1ec((undefined4 *)&DAT_1000100c,(undefined4 *)&DAT_10001010);
  FUN_1002c1ec((undefined4 *)&DAT_10001000,(undefined4 *)&DAT_10001008);
  return;
}



/* 1002c40c FUN_1002c40c */

/* Boundary evidence: original MIPS .pdata 1002c40c..1002c427. Semantic name remains unreviewed. */

void FUN_1002c40c(void)

{
  FUN_10029a70();
  return;
}



/* 1002c428 FUN_1002c428 */

/* Boundary evidence: original MIPS .pdata 1002c428..1002c447. Semantic name remains unreviewed. */

void FUN_1002c428(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1002dca4);
  return;
}


