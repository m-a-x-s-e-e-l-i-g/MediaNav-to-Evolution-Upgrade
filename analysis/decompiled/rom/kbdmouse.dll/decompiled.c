/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c08114e8 FUN_c08114e8 */

undefined4 FUN_c08114e8(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = 0;
  if ((((*param_1 == 0x34) && ((int *)param_1[3] != (int *)0x0)) && (*(int *)param_1[3] != 0)) &&
     ((piVar2 = (int *)param_1[6], piVar2 != (int *)0x0 && (param_1[8] != 0)))) {
    for (; *piVar2 != 0; piVar2 = piVar2 + 2) {
      if (*(char *)((int)piVar2 + 5) == '\0') {
        return 0;
      }
    }
    if ((param_1[0xb] == 0) ||
       (((*(byte *)(param_1 + 10) != 0 && (*(char *)((int)param_1 + 0x29) != '\0')) &&
        (*(byte *)(param_1 + 10) < 0x11)))) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* c081158c FUN_c081158c */

undefined4 FUN_c081158c(uint param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  
  *param_4 = 0;
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      puVar1 = (uint *)*param_2;
      if ((((*puVar1 & param_1) == *puVar1) && (puVar1[1] <= param_1)) && (param_1 <= puVar1[2])) {
        uVar2 = (uint)*(byte *)((puVar1[3] - puVar1[1]) + param_1);
        *param_4 = uVar2;
        if (uVar2 == 0) {
          return 0;
        }
        return 1;
      }
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
    } while (uVar2 < param_3);
  }
  return 0;
}



/* c0811614 FUN_c0811614 */

void FUN_c0811614(int param_1,uint param_2,ushort *param_3,int *param_4)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  
  uVar2 = *param_3;
  iVar3 = *param_4;
  if ((uVar2 & 6) == 4) {
    uVar2 = uVar2 & 0xfffb;
  }
  bVar1 = *(byte *)(iVar3 + 1);
  if (((bVar1 & 8) == 0) || ((param_2 & 0x8000) == 0)) {
    if (((bVar1 & 1) == 0) || (((uVar2 & 6) != 0 || ((param_2 & 0x8000000) == 0)))) {
      if (((bVar1 & 4) != 0) && (((uVar2 & 6) == 6 && ((param_2 & 0x8000000) != 0)))) {
        uVar2 = uVar2 ^ 1;
      }
    }
    else {
      uVar2 = uVar2 ^ 1;
    }
    if ((((bVar1 & 2) != 0) && ((uVar2 & 6) == 0)) && ((param_2 & 0x8000000) != 0)) {
      iVar3 = iVar3 + param_1;
    }
  }
  *param_3 = uVar2;
  *param_4 = iVar3;
  return;
}



/* c08116ec FUN_c08116ec */

uint FUN_c08116ec(ushort *param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,uint param_6
                 )

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  if ((param_6 & 0x80) != 0) {
    *param_1 = 0;
  }
  while( true ) {
    if (*param_2 == 0) {
      if (param_5 != 0) {
        *param_4 = (uint)uVar1;
      }
      uVar2 = (uint)(param_5 != 0);
      if ((1 < param_5) && (uVar2 < param_5)) {
        param_4[uVar2] = param_3;
        uVar2 = uVar2 + 1;
      }
      return uVar2;
    }
    if (*param_2 == ((uint)uVar1 << 0x10 | param_3)) break;
    param_2 = param_2 + 2;
  }
  if ((*(ushort *)((int)param_2 + 6) & 1) != 0) {
    return 0;
  }
  if (param_5 == 0) {
    return 0;
  }
  *param_4 = (uint)(ushort)param_2[1];
  return 1;
}



/* c08117a0 FUN_c08117a0 */

/* Boundary evidence: original MIPS .pdata c08117a0..c0811903. Semantic name remains unreviewed. */

uint FUN_c08117a0(int param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5,
                 uint param_6)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  
  pbVar3 = *(byte **)(param_1 + 0x24c);
  uVar4 = 0;
  if (pbVar3 == (byte *)0x0) {
    if (param_6 == 0) {
      return 0;
    }
    *param_5 = 0;
    return 1;
  }
  while( true ) {
    if (*pbVar3 == 0) {
      return 0;
    }
    if ((*pbVar3 == param_2) && (*(ushort *)(pbVar3 + 2) == param_4)) break;
    pbVar3 = pbVar3 + *(byte *)(param_1 + 0x249);
  }
  uVar2 = (uint)*(byte *)(param_1 + 0x248);
  uVar5 = 0;
  if (uVar2 == 0) {
    return 0;
  }
  puVar6 = (ushort *)(pbVar3 + 4);
  while( true ) {
    uVar1 = (uint)*puVar6;
    if (uVar2 < uVar4) {
      return uVar4;
    }
    if (uVar1 == 0xf000) break;
    if (*(ushort *)(param_1 + 600) == 0) {
      if (uVar4 < param_6) {
        param_5[uVar4] = uVar1;
        uVar4 = uVar4 + 1;
      }
    }
    else {
      uVar1 = FUN_c08116ec((ushort *)(param_1 + 600),*(uint **)(param_1 + 0x23c),uVar1,
                           param_5 + uVar4,param_6 - uVar4,param_3);
      if (uVar1 != 0) {
        uVar4 = uVar1 + uVar4;
      }
    }
    uVar5 = uVar5 + 1;
    puVar6 = puVar6 + 1;
    if (uVar2 <= uVar5) {
      return uVar4;
    }
  }
  return uVar4;
}



/* c0811904 FUN_c0811904 */

/* Boundary evidence: original MIPS .pdata c0811904..c0811ad3. Semantic name remains unreviewed. */

uint FUN_c0811904(int param_1,int param_2,byte *param_3,uint param_4,uint param_5,uint *param_6,
                 uint param_7)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  
  if (param_4 == 0xf) {
    return 0;
  }
  if (param_4 < *(byte *)(param_2 + 4)) {
    uVar3 = (uint)*(ushort *)(param_3 + param_4 * 2 + 2);
    if (uVar3 == 0xf000) {
      return 0;
    }
    if (uVar3 == 0xf001) {
      puVar4 = (ushort *)(param_1 + 600);
      uVar1 = *(ushort *)(param_3 + (uint)*(byte *)(param_2 + 5) + param_4 * 2 + 2);
      if (*puVar4 == 0) {
        if ((param_5 & 0x80) == 0) {
          return 0;
        }
        *puVar4 = uVar1;
        return 0;
      }
      if (*(uint **)(param_1 + 0x23c) != (uint *)0x0) {
        uVar3 = FUN_c08116ec(puVar4,*(uint **)(param_1 + 0x23c),(uint)uVar1,param_6,param_7,param_5)
        ;
        return uVar3;
      }
      if (param_7 == 0) {
        return 0;
      }
      *param_6 = (uint)uVar1;
    }
    else {
      if ((*(uint **)(param_1 + 0x23c) != (uint *)0x0) && (*(ushort *)(param_1 + 600) != 0)) {
        uVar3 = FUN_c08116ec((ushort *)(param_1 + 600),*(uint **)(param_1 + 0x23c),uVar3,param_6,
                             param_7,param_5);
        return uVar3;
      }
      if (uVar3 == 0xf002) {
        uVar3 = FUN_c08117a0(param_1,(uint)*param_3,param_5,param_4,param_6,param_7);
        return uVar3;
      }
      if (param_7 == 0) {
        return 0;
      }
      *param_6 = uVar3;
    }
  }
  else {
    uVar3 = (uint)*param_3;
    uVar2 = 0;
    if ((((param_5 & 0x50000000) == 0x40000000) && (0x40 < uVar3)) && (uVar3 < 0x5b)) {
      uVar2 = uVar3 + 0xffc0 & 0xffff;
    }
    if (uVar2 == 0) {
      return 0;
    }
    if (param_7 == 0) {
      return 0;
    }
    *param_6 = uVar2;
  }
  return 1;
}



/* c0811ad4 FUN_c0811ad4 */

/* Boundary evidence: original MIPS .pdata c0811ad4..c0811c57. Semantic name remains unreviewed. */

uint FUN_c0811ad4(int param_1,uint param_2,uint param_3,uint *param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  byte *pbVar4;
  char *pcVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ushort local_20 [2];
  byte *local_1c;
  
  puVar8 = *(undefined4 **)(param_1 + 0x238);
  uVar2 = 0;
  pbVar6 = (byte *)0x0;
  local_1c = (byte *)0x0;
  puVar7 = puVar8;
  puVar9 = puVar8;
  if (param_2 != 0) {
    do {
      pbVar4 = (byte *)*puVar8;
      local_1c = pbVar6;
      puVar9 = puVar7;
      if (pbVar4 == (byte *)0x0) break;
      bVar1 = *pbVar4;
      while ((local_1c = pbVar6, puVar9 = puVar7, bVar1 != 0 &&
             (local_1c = pbVar4, puVar9 = puVar8, bVar1 != param_2))) {
        pbVar4 = pbVar4 + *(byte *)((int)puVar8 + 5);
        bVar1 = *pbVar4;
      }
      puVar8 = puVar8 + 2;
      pbVar6 = local_1c;
      puVar7 = puVar9;
    } while (local_1c == (byte *)0x0);
  }
  if (local_1c != (byte *)0x0) {
    pbVar6 = (byte *)(param_1 + 0x264);
    uVar3 = (ushort)*pbVar6;
    puVar7 = *(undefined4 **)(param_1 + 0x22c);
    local_20[0] = 0;
    if (uVar3 != 0) {
      pcVar5 = (char *)*puVar7;
      local_20[0] = 0;
      do {
        for (; *pcVar5 != '\0'; pcVar5 = pcVar5 + 2) {
          if ((((byte)pcVar5[1] & uVar3) != 0) && ((*(uint *)(pbVar6 + 4) & param_3) != 0)) {
            local_20[0] = local_20[0] | uVar3;
          }
        }
        pbVar6 = pbVar6 + 8;
        uVar3 = (ushort)*pbVar6;
        pcVar5 = (char *)*puVar7;
      } while (uVar3 != 0);
    }
    FUN_c0811614((uint)*(byte *)((int)puVar9 + 5),param_3,local_20,(int *)&local_1c);
    uVar2 = 0xf;
    if ((uint)local_20[0] <= (uint)*(ushort *)(puVar7 + 1)) {
      uVar2 = (uint)*(byte *)((int)puVar7 + local_20[0] + 6);
    }
    uVar2 = FUN_c0811904(param_1,(int)puVar9,local_1c,uVar2,param_3,param_4,param_5);
  }
  return uVar2;
}



/* c0811c58 FUN_c0811c58 */

/* Boundary evidence: original MIPS .pdata c0811c58..c0811ed3. Semantic name remains unreviewed. */

undefined4 FUN_c0811c58(uint param_1,uint param_2,uint *param_3,int *param_4)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  
  uVar8 = *param_3;
  bVar1 = false;
  uVar2 = 1;
  iVar6 = DAT_c0817814;
  if (param_1 == 0x12) {
    if ((param_2 & 0x80) == 0) {
      DAT_c0817810 = 0;
      if (DAT_c0817814 == 0) goto LAB_c0811eb4;
      iVar6 = 0;
      DAT_c0817814 = 0;
      if (DAT_c0817808 < 2) goto LAB_c0811eb4;
      iVar3 = 0;
      iVar9 = 0x10;
      if (DAT_c081780c == 0) {
        iVar9 = 10;
      }
      uVar4 = 0;
      if (DAT_c0817808 != 0) {
        puVar10 = &DAT_c08177f4;
        do {
          uVar5 = *puVar10;
          if ((uVar5 < 0x60) || (0x69 < uVar5)) {
            if ((DAT_c081780c == 0) || ((uVar5 < 0x41 || (0x46 < uVar5)))) break;
            iVar7 = uVar5 - 0x37;
          }
          else {
            iVar7 = uVar5 - 0x60;
          }
          uVar4 = uVar4 + 1;
          puVar10 = puVar10 + 1;
          iVar3 = iVar9 * iVar3 + iVar7;
        } while (uVar4 < DAT_c0817808);
      }
      bVar1 = true;
      *param_4 = iVar3;
    }
    else if (((param_2 & 0x40) == 0) && ((uVar8 & 0x60880000) == 0)) {
      DAT_c0817810 = 1;
      DAT_c081780c = 0;
      DAT_c0817814 = 0;
      DAT_c0817808 = 0;
      iVar6 = 0;
    }
LAB_c0811ea4:
    if (iVar6 == 0) goto LAB_c0811eb4;
  }
  else {
    if ((DAT_c0817810 == 0) || ((param_2 & 0x80) == 0)) goto LAB_c0811ea4;
    if ((param_1 < 0x60) || (0x69 < param_1)) {
      if (((DAT_c081780c == 0) || (param_1 < 0x41)) || (0x46 < param_1)) {
        if (DAT_c0817814 == 0) {
          DAT_c0817810 = 0;
        }
        else {
          if (param_1 != 0x58) goto LAB_c0811eac;
          DAT_c081780c = 1;
        }
        goto LAB_c0811ea4;
      }
      DAT_c0817814 = 1;
      iVar6 = 1;
      if (DAT_c0817808 < 5) {
        puVar10 = &DAT_c08177f4 + DAT_c0817808;
        DAT_c0817808 = DAT_c0817808 + 1;
        *puVar10 = param_1;
      }
    }
    else {
      DAT_c0817814 = 1;
      iVar6 = 1;
      if (DAT_c0817808 < 5) {
        puVar10 = &DAT_c08177f4 + DAT_c0817808;
        DAT_c0817808 = DAT_c0817808 + 1;
        *puVar10 = param_1;
      }
    }
  }
LAB_c0811eac:
  uVar8 = uVar8 | 0x10000;
LAB_c0811eb4:
  *param_3 = uVar8;
  if ((iVar6 == 0) && (!bVar1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0811ed4 KeybdDriverInitStates */

/* Boundary evidence: original MIPS .pdata c0811ed4..c0811efb. Semantic name remains unreviewed. */

undefined4 KeybdDriverInitStates(undefined4 param_1,void *param_2)

{
                    /* 0x1ed4  3  KeybdDriverInitStates */
  memset(param_2,0,0x100);
  return 1;
}



/* c0811efc KeybdDriverGetInfo */

/* Boundary evidence: original MIPS .pdata c0811efc..c081208f. Semantic name remains unreviewed. */

undefined4 KeybdDriverGetInfo(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 local_20;
  
                    /* 0x1efc  2  KeybdDriverGetInfo */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  local_20 = 0;
  if (param_3 == (undefined4 *)0x0) {
LAB_c0811f40:
    SetLastError(0x57);
  }
  else {
    if (param_2 == 0) {
      *param_3 = 0;
      param_3[1] = 0x10;
    }
    else if (param_2 == 1) {
      *param_3 = DAT_c08170fc;
      param_3[1] = DAT_c0817100;
      param_3[2] = 0xffffffff;
      param_3[3] = 0xffffffff;
    }
    else {
      if (param_2 != 2) goto LAB_c0811f40;
      *param_3 = 0xfa;
      param_3[1] = 1000;
      param_3[2] = 2;
      param_3[3] = 0x1e;
    }
    local_20 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  return local_20;
}



/* c0812090 FUN_c0812090 */

/* Boundary evidence: original MIPS .pdata c0812090..c081209b. Semantic name remains unreviewed. */

undefined4 FUN_c0812090(void)

{
  return 1;
}



/* c081209c FUN_c081209c */

/* Boundary evidence: original MIPS .pdata c081209c..c08120a7. Semantic name remains unreviewed. */

undefined4 FUN_c081209c(void)

{
  return 1;
}



/* c08120a8 FUN_c08120a8 */

/* Boundary evidence: original MIPS .pdata c08120a8..c08120b3. Semantic name remains unreviewed. */

undefined4 FUN_c08120a8(void)

{
  return 1;
}



/* c08120b4 FUN_c08120b4 */

/* Boundary evidence: original MIPS .pdata c08120b4..c0812157. Semantic name remains unreviewed. */

void FUN_c08120b4(DWORD param_1,LPVOID param_2,DWORD param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(HANDLE *)((int)&DAT_c08174ec + uVar1) != (HANDLE)0x0) {
      DeviceIoControl(*(HANDLE *)((int)&DAT_c08174ec + uVar1),param_1,param_2,param_3,(LPVOID)0x0,0,
                      (LPDWORD)0x0,(LPOVERLAPPED)0x0);
    }
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x28);
  return;
}



/* c0812158 KeybdDriverSetMode */

/* Boundary evidence: original MIPS .pdata c0812158..c0812287. Semantic name remains unreviewed. */

undefined4 KeybdDriverSetMode(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int local_28;
  int local_24;
  undefined1 auStack_20 [8];
  
                    /* 0x2158  7  KeybdDriverSetMode */
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  if ((param_3 == (int *)0x0) || (param_2 != 1)) {
    SetLastError(0x57);
  }
  else {
    DAT_c08170fc = *param_3;
    if (DAT_c08170fc < 0x3e9) {
      if (DAT_c08170fc < 0xfa) {
        DAT_c08170fc = 0xfa;
      }
    }
    else {
      DAT_c08170fc = 1000;
    }
    DAT_c0817100 = param_3[1];
    if (DAT_c0817100 < 0x1f) {
      if ((DAT_c0817100 < 2) && (DAT_c0817100 != 0)) {
        DAT_c0817100 = 2;
      }
    }
    else {
      DAT_c0817100 = 0x1e;
    }
    local_28 = DAT_c08170fc;
    local_24 = DAT_c0817100;
    memset(auStack_20,0,8);
    FUN_c08120b4(0xb0008,&local_28,0x10);
    uVar1 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  return uVar1;
}



/* c0812288 KeybdDriverPowerHandler */

/* Boundary evidence: original MIPS .pdata c0812288..c081232b. Semantic name remains unreviewed. */

void KeybdDriverPowerHandler(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  
                    /* 0x2288  6  KeybdDriverPowerHandler */
  DAT_c08177f0 = 0;
  uVar5 = 0;
  if (DAT_c08174c0 != 0) {
    iVar4 = 0;
    iVar1 = DAT_c08174c8;
    uVar2 = DAT_c08174c0;
    do {
      if ((*(int *)(iVar4 + iVar1) == 1) &&
         (pcVar3 = *(code **)(((int *)(iVar4 + iVar1))[1] + 8), pcVar3 != (code *)0x0)) {
        (*pcVar3)(uVar5,param_1);
        iVar1 = DAT_c08174c8;
        uVar2 = DAT_c08174c0;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x2e4;
    } while (uVar5 < uVar2);
  }
  return;
}



/* c081232c FUN_c081232c */

/* Boundary evidence: original MIPS .pdata c081232c..c081239b. Semantic name remains unreviewed. */

void FUN_c081232c(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (*(code *)param_1)(param_2,param_3,param_4,param_5);
  return;
}



/* c081239c FUN_c081239c */

/* Boundary evidence: original MIPS .pdata c081239c..c08123a7. Semantic name remains unreviewed. */

undefined4 FUN_c081239c(void)

{
  return 1;
}



/* c08123a8 FUN_c08123a8 */

/* Boundary evidence: original MIPS .pdata c08123a8..c081254b. Semantic name remains unreviewed. */

void FUN_c08123a8(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  DWORD dwFlags;
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_38 = param_1;
  local_34 = param_2;
  local_30 = param_3;
  memset(&local_2c,0,0xc);
  uVar3 = 1;
  if ((param_1 == 0xa5) && ((DAT_c081777c & 1) != 0)) {
    uVar3 = 2;
    local_2c = local_38;
    local_28 = local_34;
    local_24 = local_30;
    local_38 = 0xa2;
    local_34 = param_2;
    local_30 = param_3;
  }
  if (*(undefined **)(param_5 + 0x26c) == (undefined *)0x0) {
    piVar1 = &local_38;
  }
  else {
    piVar1 = *(int **)(param_5 + 0x2d8);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)(param_5 + 0x274);
    }
    uVar3 = FUN_c081232c(*(undefined **)(param_5 + 0x26c),&local_38,uVar3,piVar1,
                         *(undefined4 *)(param_5 + 0x2d4));
    if (*(uint *)(param_5 + 0x2d4) < uVar3) {
      uVar3 = 0;
    }
  }
  if (uVar3 != 0) {
    puVar2 = (uint *)(piVar1 + 2);
    do {
      dwFlags = (DWORD)((puVar2[-1] & 0xffffff00) == 0xe000);
      if ((param_4 == 1) && ((puVar2[-2] & 0x2000000) != 0)) {
        dwFlags = dwFlags | 4;
      }
      if ((*puVar2 & 0x80) == 0) {
        dwFlags = dwFlags | 2;
      }
      keybd_event((BYTE)puVar2[-2],(BYTE)puVar2[-1],dwFlags,0);
      uVar3 = uVar3 - 1;
      puVar2 = puVar2 + 3;
    } while (uVar3 != 0);
  }
  return;
}



/* c081254c FUN_c081254c */

/* Boundary evidence: original MIPS .pdata c081254c..c0812857. Semantic name remains unreviewed. */

void FUN_c081254c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  DWORD DVar4;
  int iVar5;
  uint uVar6;
  DWORD dwMilliseconds;
  uint uVar7;
  int *piVar8;
  DWORD DVar9;
  uint local_30;
  uint *local_2c;
  
  DVar9 = 0;
  SetThreadPriority((HANDLE)0x41,1);
  local_2c = &DAT_c0817100;
  dwMilliseconds = 0xffffffff;
  do {
    uVar6 = *local_2c;
    if (uVar6 == 0) {
      DAT_c08177f0 = 0;
    }
    if (DAT_c08177f0 == 0) {
      dwMilliseconds = 0xffffffff;
    }
    else if (DAT_c08177f0 == 1) {
      dwMilliseconds = local_2c[-1];
    }
    else if (DAT_c08177f0 == 3) {
      DVar4 = GetTickCount();
      dwMilliseconds = (dwMilliseconds + DVar9) - DVar4;
      if ((int)dwMilliseconds < 1) {
        dwMilliseconds = 0;
      }
    }
    else {
      dwMilliseconds = 1000 / uVar6;
      if (uVar6 == 0) {
        trap(0x1c00);
      }
    }
    DVar9 = GetTickCount();
    DVar4 = WaitForSingleObject(DAT_c08174e8,dwMilliseconds);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
    iVar2 = DAT_c0817534;
    uVar6 = DAT_c0817530;
    iVar1 = DAT_c081752c;
    if (DVar4 == 0x102) {
      if (DAT_c08177f0 != 0) {
        if ((DAT_c08177f0 == 1) || (DAT_c08177f0 == 3)) {
          DAT_c08177f0 = 2;
        }
        FUN_c08123a8(DAT_c0817824,DAT_c0817818,DAT_c081781c,1,
                     DAT_c0817820 * 0x2e4 + DAT_c08174c8 + 8);
      }
    }
    else {
      EventModify(DAT_c08174cc,3);
      iVar5 = iVar1 * 0x2e4 + DAT_c08174c8;
      piVar8 = (int *)(iVar5 + 8);
      if (*piVar8 != 0) {
        iVar5 = FUN_c081158c(uVar6,*(undefined4 **)(iVar5 + 0x26c),*(uint *)(iVar5 + 0x270),
                             &local_30);
        uVar3 = local_30;
        if (iVar5 == 1) {
          if (iVar2 == 0) {
            uVar7 = DAT_c08174c4 | 0x80;
            if ((0x76 < local_30) && (local_30 < 0x7c)) {
              FUN_c08153bc(local_30 + 0xff91 & 0xffff);
            }
            if (((*piVar8 == 0x412) || (*piVar8 == 0x409)) && ((uVar3 == 0x19 || (uVar3 == 0x15))))
            goto LAB_c08127e8;
            DVar9 = GetTickCount();
            DAT_c0817824 = uVar3;
            DAT_c08177f0 = 1;
            DAT_c0817818 = uVar6;
            DAT_c0817820 = iVar1;
            DAT_c081781c = uVar7;
          }
          else {
            uVar7 = DAT_c08174c4 & 0xffffff7f;
LAB_c08127e8:
            DAT_c08177f0 = 0;
          }
          FUN_c08123a8(uVar3,uVar6,uVar7,0,(int)piVar8);
        }
        else if (((DAT_c08177f0 == 1) || (DAT_c08177f0 == 3)) || (DAT_c08177f0 == 2)) {
          DAT_c08177f0 = 3;
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  } while( true );
}



/* c0812858 FUN_c0812858 */

/* Boundary evidence: original MIPS .pdata c0812858..c0812903. Semantic name remains unreviewed. */

void FUN_c0812858(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE local_20;
  undefined4 local_1c;
  
  local_20 = DAT_c08174cc;
  local_1c = DAT_c0817528;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c08174d0);
  DAT_c081752c = param_1;
  DAT_c0817530 = param_2;
  DAT_c0817534 = param_3;
  EventModify(DAT_c08174e8,3);
  WaitForMultipleObjects(2,&local_20,0,0xffffffff);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c08174d0);
  return;
}



/* c0812904 FUN_c0812904 */

/* Boundary evidence: original MIPS .pdata c0812904..c0812c9f. Semantic name remains unreviewed. */

undefined4 FUN_c0812904(void)

{
  HANDLE hObject;
  int iVar1;
  DWORD DVar2;
  int iVar3;
  wchar_t *pwVar4;
  HANDLE pvVar5;
  uint uVar6;
  HANDLE local_120;
  undefined4 local_11c;
  undefined4 local_118 [2];
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined1 auStack_fc [4];
  undefined1 auStack_f8 [8];
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 auStack_e8 [8];
  undefined4 local_e0;
  undefined2 local_dc;
  undefined2 local_da;
  undefined1 local_d8;
  undefined1 local_d7;
  undefined1 local_d6;
  undefined1 local_d5;
  undefined1 local_d4;
  undefined1 local_d3;
  undefined1 local_d2;
  undefined1 local_d1;
  undefined1 auStack_d0 [20];
  int local_bc;
  wchar_t awStack_b4 [3];
  ushort local_ae;
  uint local_30;
  
  local_30 = DAT_c08174b8;
  local_e0 = 0xcbe6ddf2;
  local_dc = 0xf5d4;
  local_da = 0x4e16;
  local_d8 = 0x9f;
  local_d7 = 0x61;
  local_d6 = 0x4c;
  local_d5 = 0xcc;
  local_d4 = 0xb;
  local_d3 = 0x66;
  local_d2 = 0x95;
  local_d1 = 0xf3;
  memset(auStack_d0,0,0xa0);
  memset(&local_110,0,0x14);
  local_110 = 0x14;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0xa0;
  local_100 = 1;
  hObject = (HANDLE)CreateMsgQueue(0,&local_110);
  if (hObject != (HANDLE)0x0) {
    iVar1 = RequestDeviceNotifications(&local_e0,hObject,1);
    if (iVar1 != 0) {
      local_11c = DAT_c08174e4;
      local_120 = hObject;
      DVar2 = WaitForMultipleObjects(2,&local_120,0,0xffffffff);
      while (DVar2 == 0) {
        iVar3 = ReadMsgQueue(hObject,auStack_d0,0xa0,auStack_f8,0,auStack_fc);
        if (iVar3 == 0) {
          GetLastError();
          break;
        }
        pwVar4 = wcsstr(awStack_b4,L"KBD");
        if (((pwVar4 != (wchar_t *)0x0) && (uVar6 = (uint)local_ae, 0x2f < uVar6)) && (uVar6 < 0x3a)
           ) {
          if (local_bc == 1) {
            pvVar5 = CreateFileW(awStack_b4,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0)
            ;
            if (pvVar5 == (HANDLE)0xffffffff) goto LAB_c0812c18;
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
            DeviceIoControl(pvVar5,0xb0004,&DAT_c08174c4,4,(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
            local_f0 = DAT_c08170fc;
            local_ec = DAT_c0817100;
            memset(auStack_e8,0,8);
            DeviceIoControl(pvVar5,0xb0008,&local_f0,0x10,(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
            if (DAT_c0817538 != 0) {
              local_118[0] = DAT_c081777c;
              DeviceIoControl(pvVar5,0xb000c,local_118,4,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
            }
            (&DAT_c08174ec)[uVar6 - 0x30] = pvVar5;
          }
          else {
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
            pvVar5 = (HANDLE)(&DAT_c08174ec)[uVar6 - 0x30];
            if (pvVar5 != (HANDLE)0x0) {
              CloseHandle(pvVar5);
              (&DAT_c08174ec)[uVar6 - 0x30] = 0;
            }
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
        }
LAB_c0812c18:
        DVar2 = WaitForMultipleObjects(2,&local_120,0,0xffffffff);
      }
      StopDeviceNotifications(iVar1);
    }
    CloseHandle(hObject);
  }
  FUN_c0815dbc(local_30);
  return 0;
}



/* c0812ca0 FUN_c0812ca0 */

/* Boundary evidence: original MIPS .pdata c0812ca0..c0812d4f. Semantic name remains unreviewed. */

void FUN_c0812ca0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_res0 [4];
  
  uVar5 = 0;
  DAT_c08174c4 = param_1;
  local_res0[0] = param_1;
  if (DAT_c08174c0 != 0) {
    iVar4 = 0;
    iVar1 = DAT_c08174c8;
    uVar2 = DAT_c08174c0;
    do {
      if ((*(int *)(iVar4 + iVar1) == 1) &&
         (pcVar3 = *(code **)(((int *)(iVar4 + iVar1))[1] + 0xc), pcVar3 != (code *)0x0)) {
        (*pcVar3)(uVar5,param_1);
        param_1 = local_res0[0];
        iVar1 = DAT_c08174c8;
        uVar2 = DAT_c08174c0;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x2e4;
    } while (uVar5 < uVar2);
  }
  FUN_c08120b4(0xb0004,local_res0,4);
  return;
}



/* c0812d50 FUN_c0812d50 */

/* Boundary evidence: original MIPS .pdata c0812d50..c0812e4f. Semantic name remains unreviewed. */

undefined4 FUN_c0812d50(undefined4 param_1,undefined4 *param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_38;
  HKEY local_34;
  wchar_t awStack_30 [8];
  undefined2 local_20;
  uint local_1c;
  
  local_1c = DAT_c08174b8;
  uVar2 = 0;
  local_38 = (HKEY)0x0;
  local_34 = (HKEY)0x0;
  local_20 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"Keyboard Layout\\Preload",0,0,&local_38);
  if (LVar1 == 0) {
    _snwprintf(awStack_30,8,L"%u",param_1);
    LVar1 = RegOpenKeyExW(local_38,awStack_30,0,0,&local_34);
    if (LVar1 == 0) {
      uVar2 = 1;
      *param_2 = local_34;
    }
  }
  if (local_38 != (HKEY)0x0) {
    RegCloseKey(local_38);
  }
  FUN_c0815dbc(local_1c);
  return uVar2;
}



/* c0812e50 FUN_c0812e50 */

/* Boundary evidence: original MIPS .pdata c0812e50..c0812f17. Semantic name remains unreviewed. */

undefined4 FUN_c0812e50(undefined4 param_1,LPBYTE param_2)

{
  HKEY hKey;
  int iVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  HKEY local_28;
  DWORD local_24;
  DWORD local_20 [2];
  
  local_28 = (HKEY)0x0;
  local_24 = 0x12;
  uVar3 = 0;
  iVar1 = FUN_c0812d50(param_1,&local_28);
  hKey = local_28;
  if (iVar1 != 0) {
    LVar2 = RegQueryValueExW(local_28,(LPCWSTR)0x0,(LPDWORD)0x0,local_20,param_2,&local_24);
    if (((LVar2 == 0) && (local_20[0] == 1)) && (local_24 == 0x12)) {
      param_2[0x10] = '\0';
      param_2[0x11] = '\0';
      uVar3 = 1;
    }
  }
  if (hKey != (HKEY)0x0) {
    RegCloseKey(hKey);
  }
  return uVar3;
}



/* c0812f18 FUN_c0812f18 */

/* Boundary evidence: original MIPS .pdata c0812f18..c08130bf. Semantic name remains unreviewed. */

undefined4 FUN_c0812f18(LPCWSTR param_1,ulong *param_2)

{
  LSTATUS LVar1;
  ulong uVar2;
  wchar_t *pwVar3;
  wchar_t *lpValueName;
  wchar_t *_Dest;
  undefined4 uVar4;
  HKEY local_30;
  HKEY local_2c;
  wchar_t *local_28;
  DWORD local_24;
  DWORD local_20 [2];
  
  lpValueName = L"Ime File";
  local_30 = (HKEY)0x0;
  uVar4 = 0;
  local_2c = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"System\\CurrentControlSet\\Control\\Layouts",0,0,
                        &local_30);
  if (LVar1 == 0) {
    LVar1 = RegOpenKeyExW(local_30,param_1,0,0,&local_2c);
    if (LVar1 == 0) {
      _Dest = (wchar_t *)(param_2 + 1);
      wcscpy(_Dest,param_1);
      pwVar3 = _Dest;
      do {
        *pwVar3 = L'0';
        pwVar3 = pwVar3 + 1;
      } while (pwVar3 != (wchar_t *)(param_2 + 3));
      local_28 = (wchar_t *)0x0;
      uVar2 = wcstoul(_Dest,&local_28,0x10);
      *param_2 = uVar2;
      local_28 = (wchar_t *)0x0;
      uVar2 = wcstoul(param_1,&local_28,0x10);
      if ((uVar2 & 0xff000000) != 0xe0000000) {
        lpValueName = L"Layout File";
      }
      local_24 = 0x208;
      LVar1 = RegQueryValueExW(local_2c,lpValueName,(LPDWORD)0x0,local_20,
                               (LPBYTE)((int)param_2 + 0x16),&local_24);
      if ((LVar1 == 0) && (local_20[0] == 1)) {
        *(undefined2 *)(param_2 + 0x87) = 0;
        uVar4 = 1;
      }
    }
  }
  if (local_30 != (HKEY)0x0) {
    RegCloseKey(local_30);
  }
  if (local_2c != (HKEY)0x0) {
    RegCloseKey(local_2c);
  }
  return uVar4;
}



/* c08130c0 FUN_c08130c0 */

/* Boundary evidence: original MIPS .pdata c08130c0..c0813257. Semantic name remains unreviewed. */

int FUN_c08130c0(wchar_t *param_1)

{
  bool bVar1;
  LSTATUS LVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  HKEY local_58;
  DWORD local_54;
  DWORD local_50 [2];
  wchar_t local_48;
  undefined1 auStack_46 [14];
  undefined2 local_38;
  wchar_t local_30;
  undefined1 auStack_2e [18];
  uint local_1c;
  
  local_1c = DAT_c08174b8;
  iVar4 = 0;
  local_30 = L'\0';
  memset(auStack_2e,0,0x10);
  local_48 = L'\0';
  memset(auStack_46,0,0x10);
  local_58 = (HKEY)0x0;
  local_54 = 0x12;
  bVar1 = false;
  LVar2 = RegOpenKeyExW((HKEY)0x80000001,L"Keyboard Layout\\Preload",0,0,&local_58);
  if (LVar2 == 0) {
    LVar2 = RegQueryValueExW(local_58,(LPCWSTR)0x0,(LPDWORD)0x0,local_50,(LPBYTE)&local_48,&local_54
                            );
    if (((LVar2 == 0) && (local_50[0] == 1)) && (local_54 == 0x12)) {
      local_38 = 0;
      bVar1 = true;
    }
  }
  if (local_58 != (HKEY)0x0) {
    RegCloseKey(local_58);
  }
  if (bVar1) {
    uVar5 = 1;
    do {
      if (0xf < uVar5) break;
      iVar4 = FUN_c0812e50(uVar5,(LPBYTE)&local_30);
      if (iVar4 == 0) {
LAB_c081320c:
        iVar4 = 0;
      }
      else {
        iVar3 = _wcsicmp(&local_30,&local_48);
        iVar4 = 1;
        if (iVar3 != 0) goto LAB_c081320c;
      }
      uVar5 = uVar5 + 1;
    } while (iVar4 == 0);
    if (iVar4 != 0) {
      wcscpy(param_1,&local_48);
    }
  }
  FUN_c0815dbc(local_1c);
  return iVar4;
}



/* c0813258 FUN_c0813258 */

undefined4 FUN_c0813258(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  
  pcVar4 = (char *)**(undefined4 **)(param_1 + 0x22c);
  cVar2 = *pcVar4;
  iVar5 = 0;
  if (cVar2 != '\0') {
    puVar6 = (undefined4 *)(param_1 + 0x268);
    do {
      for (pcVar3 = *(char **)(param_1 + 0x25c);
          (pcVar1 = (char *)0x0, *pcVar3 != '\0' && (pcVar1 = pcVar3, *pcVar3 != cVar2));
          pcVar3 = pcVar3 + 8) {
      }
      if (pcVar1 == (char *)0x0) {
        for (pcVar3 = *(char **)(param_1 + 0x260);
            (pcVar1 = (char *)0x0, *pcVar3 != '\0' && (pcVar1 = pcVar3, *pcVar3 != cVar2));
            pcVar3 = pcVar3 + 8) {
        }
        if (pcVar1 != (char *)0x0) goto LAB_c08132ec;
      }
      else {
LAB_c08132ec:
        if (iVar5 == 6) break;
        iVar5 = iVar5 + 1;
        *(char *)(puVar6 + -1) = pcVar4[1];
        *puVar6 = *(undefined4 *)(pcVar1 + 4);
        puVar6 = puVar6 + 2;
      }
      pcVar4 = pcVar4 + 2;
      cVar2 = *pcVar4;
    } while (cVar2 != '\0');
  }
  *(undefined1 *)(iVar5 * 8 + param_1 + 0x264) = 0;
  *(undefined4 *)((iVar5 + 0x4d) * 8 + param_1) = 0;
  return 1;
}



/* c0813348 FUN_c0813348 */

/* Boundary evidence: original MIPS .pdata c0813348..c08134c3. Semantic name remains unreviewed. */

ulong FUN_c0813348(undefined4 param_1)

{
  LSTATUS LVar1;
  ulong uVar2;
  HKEY local_60;
  HKEY local_5c;
  DWORD local_58;
  DWORD local_54;
  wchar_t *local_50 [2];
  wchar_t awStack_48 [8];
  undefined2 local_38;
  wchar_t awStack_30 [8];
  undefined2 local_20;
  uint local_1c;
  
  local_1c = DAT_c08174b8;
  uVar2 = 0;
  local_5c = (HKEY)0x0;
  local_60 = (HKEY)0x0;
  local_58 = 0x12;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"System\\CurrentControlSet\\Control\\Layouts",0,0,
                        &local_5c);
  if (LVar1 == 0) {
    local_38 = 0;
    _snwprintf(awStack_48,8,L"%08X",param_1);
    LVar1 = RegOpenKeyExW(local_5c,awStack_48,0,0,&local_60);
    if (LVar1 == 0) {
      LVar1 = RegQueryValueExW(local_60,L"Keyboard Layout",(LPDWORD)0x0,&local_54,(LPBYTE)awStack_30
                               ,&local_58);
      if (((LVar1 == 0) && (local_54 == 1)) && (local_58 == 0x12)) {
        local_20 = 0;
        local_50[0] = (wchar_t *)0x0;
        uVar2 = wcstoul(awStack_30,local_50,0x10);
      }
    }
  }
  if (local_5c != (HKEY)0x0) {
    RegCloseKey(local_5c);
  }
  if (local_60 != (HKEY)0x0) {
    RegCloseKey(local_60);
  }
  FUN_c0815dbc(local_1c);
  return uVar2;
}



/* c08134c4 FUN_c08134c4 */

/* Boundary evidence: original MIPS .pdata c08134c4..c0813577. Semantic name remains unreviewed. */

int FUN_c08134c4(undefined4 param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  wchar_t *_String;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c08174b8;
  iVar1 = GetProcAddressW(param_1,param_2);
  if (iVar1 == 0) {
    StringCchCopyW(awStack_228,0x104,param_2);
    _String = wcsrchr(awStack_228,L'_');
    if (_String != (wchar_t *)0x0) {
      _wcslwr(_String);
      iVar1 = GetProcAddressW(param_1,awStack_228);
    }
  }
  FUN_c0815dbc(local_20);
  return iVar1;
}



/* c0813578 FUN_c0813578 */

/* Boundary evidence: original MIPS .pdata c0813578..c08138df. Semantic name remains unreviewed. */

undefined4 FUN_c0813578(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  code *pcVar4;
  byte bVar5;
  char *pcVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  ulong uStack_310;
  wchar_t awStack_30c [9];
  WCHAR aWStack_2fa [261];
  int local_f0 [3];
  undefined4 *local_e4;
  undefined *local_e0;
  undefined *local_dc;
  undefined1 auStack_cc [16];
  undefined4 local_bc;
  undefined *local_b4;
  undefined *local_b0;
  byte local_ac;
  uint local_a8;
  undefined1 local_a4 [48];
  HMODULE local_74;
  uint local_70;
  wchar_t awStack_6c [10];
  wchar_t awStack_58 [8];
  undefined2 local_48;
  wchar_t awStack_40 [11];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_c08174b8;
  puVar9 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  uVar1 = DAT_c08177d8;
  uVar8 = 0;
  memset(&uStack_310,0,0x2b8);
  local_f0[0] = 0x34;
  local_48 = 0;
  local_70 = param_1;
  _snwprintf(awStack_58,8,L"%08X",param_1,puVar9);
  wcscpy(awStack_6c,awStack_58);
  if ((param_1 & 0xff000000) == 0xe0000000) {
    uVar2 = FUN_c0813348(param_1);
    if (uVar2 == 0) goto LAB_c0813748;
    local_48 = 0;
    _snwprintf(awStack_58,8,L"%08X",uVar2);
  }
  iVar3 = FUN_c0812f18(awStack_58,&uStack_310);
  if ((iVar3 != 0) && (local_74 = LoadLibraryW(aWStack_2fa), local_74 != (HMODULE)0x0)) {
    wcsncpy(awStack_40,L"IL_",4);
    local_2a = 0;
    wcsncat(awStack_40,awStack_30c,9);
    pcVar4 = (code *)FUN_c08134c4(local_74,awStack_40);
    if (pcVar4 != (code *)0x0) {
      iVar3 = (*pcVar4)(local_f0);
      if ((iVar3 == 0) || (iVar3 = FUN_c08114e8(local_f0), iVar3 == 0)) {
        FreeLibrary(local_74);
      }
      else {
        local_b4 = local_e0;
        if (local_e0 == (undefined *)0x0) {
          local_b4 = &DAT_c081103c;
        }
        local_b0 = local_dc;
        if (local_dc == (undefined *)0x0) {
          local_b0 = &DAT_c081109c;
        }
        iVar3 = FUN_c0813258((int)&uStack_310);
        if (iVar3 != 0) {
          bVar5 = 0;
          if (local_ac != 0) {
            pcVar6 = (char *)*local_e4;
            puVar7 = &local_a8;
            do {
              for (; *pcVar6 != '\0'; pcVar6 = pcVar6 + 2) {
                if (((pcVar6[1] & local_ac) != 0) && ((*puVar7 & 0x10000000) != 0)) {
                  bVar5 = bVar5 | local_ac;
                }
              }
              local_ac = (byte)puVar7[1];
              pcVar6 = (char *)*local_e4;
              puVar7 = puVar7 + 2;
            } while (local_ac != 0);
          }
          uVar8 = 1;
          if (bVar5 != 0) {
            local_bc = 1;
          }
          if (DAT_c08177d4 != 0) {
            FreeLibrary((HMODULE)DAT_c08177d4);
          }
          FUN_c08120b4(0xb000c,auStack_cc,4);
          memcpy(&DAT_c0817538,&uStack_310,0x2b8);
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = uVar1;
          }
        }
      }
    }
  }
LAB_c0813748:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  FUN_c0815dbc(local_28);
  return uVar8;
}



/* c08138e0 FUN_c08138e0 */

/* Boundary evidence: original MIPS .pdata c08138e0..c08138eb. Semantic name remains unreviewed. */

undefined4 FUN_c08138e0(void)

{
  return 1;
}



/* c08138ec FUN_c08138ec */

/* Boundary evidence: original MIPS .pdata c08138ec..c0813b4f. Semantic name remains unreviewed. */

int FUN_c08138ec(undefined4 param_1,undefined4 param_2,LPCWSTR param_3,ushort param_4,
                wchar_t *param_5,int param_6)

{
  bool bVar1;
  HMODULE hLibModule;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  STRSAFE_LPCWSTR _Source;
  HMODULE hLibModule_00;
  code *local_b4;
  wchar_t *local_a0 [3];
  ushort local_94;
  wchar_t awStack_80 [39];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_c08174b8;
  iVar5 = 0;
  hLibModule_00 = (HMODULE)0x0;
  local_a0[0] = awStack_80;
  local_a0[1] = (wchar_t *)param_2;
  _snwprintf(awStack_80,0x27,L"%s_%s",param_2,param_1);
  local_32 = 0;
  local_a0[2] = (wchar_t *)0x14;
  uVar4 = 0;
  do {
    if (1 < uVar4) {
LAB_c0813af0:
      FUN_c0815dbc(local_30);
      return iVar5;
    }
    _Source = local_a0[uVar4];
    bVar1 = false;
    hLibModule = LoadLibraryW(param_3);
    if (hLibModule != (HMODULE)0x0) {
      pcVar2 = (code *)FUN_c08134c4(hLibModule,_Source);
      if (pcVar2 == (code *)0x0) {
        FreeLibrary(hLibModule);
      }
      else {
        bVar1 = true;
        hLibModule_00 = hLibModule;
        local_b4 = pcVar2;
      }
    }
    if (bVar1) {
      iVar3 = (*local_b4)(local_a0 + 2);
      if ((iVar3 != 0) && ((local_94 & param_4) != 0)) {
        iVar5 = 1;
      }
      FreeLibrary(hLibModule_00);
    }
    if (iVar5 == 1) {
      wcsncpy(param_5,_Source,param_6 - 1);
      param_5[param_6 + -1] = L'\0';
      goto LAB_c0813af0;
    }
    uVar4 = uVar4 + 1;
  } while( true );
}



/* c0813b50 FUN_c0813b50 */

/* Boundary evidence: original MIPS .pdata c0813b50..c0813b5b. Semantic name remains unreviewed. */

undefined4 FUN_c0813b50(void)

{
  return 1;
}



/* c0813b5c FUN_c0813b5c */

/* Boundary evidence: original MIPS .pdata c0813b5c..c0813dc3. Semantic name remains unreviewed. */

undefined4
FUN_c0813b5c(LPCWSTR param_1,ushort *param_2,wchar_t *param_3,size_t param_4,wchar_t *param_5,
            int param_6)

{
  size_t _MaxCount;
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD dwIndex;
  HKEY local_298;
  DWORD local_294;
  DWORD local_290;
  HKEY local_28c;
  DWORD local_288;
  ushort *local_284;
  wchar_t *local_280;
  WCHAR aWStack_278 [29];
  undefined2 local_23e;
  WCHAR aWStack_238 [259];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_c08174b8;
  local_280 = param_5;
  local_294 = 0x1e;
  local_290 = 0x208;
  uVar3 = 0;
  dwIndex = 0;
  local_28c = (HKEY)0x0;
  local_298 = (HKEY)0x0;
  local_284 = param_2;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"System\\CurrentControlSet\\Control\\Layouts",0,0,
                        &local_28c);
  if ((LVar1 == 0) && (LVar1 = RegOpenKeyExW(local_28c,param_1,0,0,&local_298), LVar1 == 0)) {
    iVar2 = RegEnumValueW(local_298,0,aWStack_278,&local_294,(LPDWORD)0x0,&local_288,
                          (LPBYTE)aWStack_238,&local_290);
    _MaxCount = local_294;
    while (local_294 = _MaxCount, iVar2 == 0) {
      local_23e = 0;
      local_32 = 0;
      if ((((local_288 == 1) && (iVar2 = wcsncmp(aWStack_278,L"Layout Text",_MaxCount), iVar2 != 0))
          && (iVar2 = wcsncmp(aWStack_278,L"Layout File",_MaxCount), iVar2 != 0)) &&
         (iVar2 = FUN_c08138ec(param_1,aWStack_278,aWStack_238,*local_284,local_280,param_6),
         iVar2 != 0)) {
        wcsncpy(param_3,aWStack_238,param_4);
        param_3[param_4 - 1] = L'\0';
        uVar3 = 1;
        break;
      }
      local_294 = 0x1e;
      local_290 = 0x208;
      dwIndex = dwIndex + 1;
      iVar2 = RegEnumValueW(local_298,dwIndex,aWStack_278,&local_294,(LPDWORD)0x0,&local_288,
                            (LPBYTE)aWStack_238,&local_290);
      _MaxCount = local_294;
    }
  }
  if (local_28c != (HKEY)0x0) {
    RegCloseKey(local_28c);
  }
  if (local_298 != (HKEY)0x0) {
    RegCloseKey(local_298);
  }
  FUN_c0815dbc(local_30);
  return uVar3;
}



/* c0813dc4 FUN_c0813dc4 */

/* Boundary evidence: original MIPS .pdata c0813dc4..c081411b. Semantic name remains unreviewed. */

undefined4 FUN_c0813dc4(ulong param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  HMODULE hLibModule;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  code *local_328;
  int local_324;
  undefined4 local_320;
  int local_31c;
  ulong local_318;
  wchar_t awStack_314 [40];
  wchar_t awStack_2c4 [260];
  int local_bc [2];
  int *local_b4;
  uint local_b0;
  undefined *local_ac;
  HMODULE local_a8;
  uint local_44;
  HLOCAL local_40;
  wchar_t awStack_38 [8];
  undefined2 local_28;
  uint local_24;
  
  local_24 = DAT_c08174b8;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  uVar6 = 0;
  local_320 = 0;
  iVar5 = param_2 * 0x2e4 + DAT_c08174c8;
  local_324 = iVar5;
  memset(&local_318,0,0x2dc);
  local_bc[0] = 0x14;
  if (((param_1 & 0xff000000) != 0xe0000000) || (param_1 = FUN_c0813348(param_1), param_1 != 0)) {
    local_28 = 0;
    _snwprintf(awStack_38,8,L"%08X",param_1);
    iVar2 = FUN_c0813b5c(awStack_38,*(ushort **)(iVar5 + 4),awStack_2c4,0x104,awStack_314,0x28);
    if (iVar2 != 0) {
      local_328 = (code *)0x0;
      local_318 = wcstoul(awStack_38,(wchar_t **)&local_328,0x10);
      bVar1 = false;
      hLibModule = LoadLibraryW(awStack_2c4);
      pcVar3 = local_328;
      if (hLibModule != (HMODULE)0x0) {
        pcVar3 = (code *)FUN_c08134c4(hLibModule,awStack_314);
        if (pcVar3 == (code *)0x0) {
          FreeLibrary(hLibModule);
          pcVar3 = local_328;
        }
        else {
          bVar1 = true;
          local_a8 = hLibModule;
        }
      }
      if (bVar1) {
        local_31c = (*pcVar3)(local_bc);
        if (local_31c != 0) {
          bVar1 = false;
          if ((local_bc[0] == 0x14) && (local_b4 != (int *)0x0)) {
            uVar4 = 0;
            if (local_b0 != 0) {
              do {
                if (*(uint *)(*local_b4 + 8) < *(uint *)(*local_b4 + 4)) goto LAB_c0814064;
                uVar4 = uVar4 + 1;
                local_b4 = local_b4 + 1;
              } while (uVar4 < local_b0);
            }
            bVar1 = true;
          }
LAB_c0814064:
          if ((bVar1) &&
             (((local_ac == (undefined *)0x0 ||
               (local_44 = FUN_c081232c(local_ac,0,2,0,0), local_44 < 9)) ||
              (local_40 = LocalAlloc(0,local_44 * 0xc), local_40 != (HLOCAL)0x0)))) {
            if (*(HMODULE *)(iVar5 + 0x278) != (HMODULE)0x0) {
              FreeLibrary(*(HMODULE *)(iVar5 + 0x278));
            }
            if (*(HLOCAL *)(iVar5 + 0x2e0) != (HLOCAL)0x0) {
              LocalFree(*(HLOCAL *)(iVar5 + 0x2e0));
            }
            memcpy((void *)(iVar5 + 8),&local_318,0x2dc);
            uVar6 = 1;
            goto LAB_c0813fbc;
          }
        }
        FreeLibrary(local_a8);
      }
    }
  }
LAB_c0813fbc:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  FUN_c0815dbc(local_24);
  return uVar6;
}



/* c081411c FUN_c081411c */

/* Boundary evidence: original MIPS .pdata c081411c..c0814127. Semantic name remains unreviewed. */

undefined4 FUN_c081411c(void)

{
  return 1;
}



/* c0814128 KeybdDriverInitializeEx */

/* Boundary evidence: original MIPS .pdata c0814128..c0814437. Semantic name remains unreviewed. */

void KeybdDriverInitializeEx(undefined *param_1)

{
  HANDLE hObject;
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  wchar_t *local_40 [2];
  wchar_t local_38;
  undefined1 auStack_36 [18];
  uint local_24;
  
                    /* 0x4128  4  KeybdDriverInitializeEx */
  local_24 = DAT_c08174b8;
  local_38 = L'\0';
  memset(auStack_36,0,0x10);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c08174d0);
  DAT_c08174e8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_c08174cc = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_c08174e4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_c0817528 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c081254c,(LPVOID)0x0,0,(LPDWORD)0x0);
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0812904,(LPVOID)0x0,0,(LPDWORD)0x0);
  CloseHandle(hObject);
  if (DAT_c08174e8 != (HANDLE)0x0) {
    if (((DAT_c08174cc != (HANDLE)0x0) && (DAT_c08174e4 != (HANDLE)0x0)) &&
       (DAT_c0817528 != (HANDLE)0x0)) {
      ppuVar5 = &PTR_FUN_c08174a0;
      ppuVar4 = ppuVar5;
      puVar3 = PTR_FUN_c08174a0;
      while (puVar3 != (undefined *)0x0) {
        ppuVar4 = ppuVar4 + 1;
        DAT_c08174c0 = DAT_c08174c0 + 1;
        puVar3 = *ppuVar4;
      }
      DAT_c08174c8 = LocalAlloc(0x40,DAT_c08174c0 * 0x2e4);
      if (DAT_c08174c8 != (HLOCAL)0x0) {
        uVar6 = 0;
        if (DAT_c08174c0 != 0) {
          iVar8 = 0;
          do {
            puVar7 = (undefined4 *)(iVar8 + (int)DAT_c08174c8);
            iVar1 = (*(code *)*ppuVar5)(uVar6,FUN_c0812858,puVar7 + 1);
            if (iVar1 == 0) {
              *puVar7 = 0;
            }
            else {
              *puVar7 = 1;
            }
            uVar6 = uVar6 + 1;
            iVar8 = iVar8 + 0x2e4;
            ppuVar5 = ppuVar5 + 1;
          } while (uVar6 < DAT_c08174c0);
        }
        iVar8 = FUN_c08130c0(&local_38);
        if (iVar8 != 0) {
          local_40[0] = (wchar_t *)0x0;
          uVar2 = wcstoul(&local_38,local_40,0x10);
          iVar8 = FUN_c0813578(uVar2,(undefined4 *)0x0);
          if ((iVar8 != 0) && (uVar6 = 0, DAT_c08174c0 != 0)) {
            do {
              FUN_c0813dc4(uVar2,uVar6);
              uVar6 = uVar6 + 1;
            } while (uVar6 < DAT_c08174c0);
          }
        }
      }
      goto LAB_c08143f0;
    }
    CloseHandle(DAT_c08174e8);
  }
  if (DAT_c08174cc != (HANDLE)0x0) {
    CloseHandle(DAT_c08174cc);
  }
  if (DAT_c08174e4 != (HANDLE)0x0) {
    CloseHandle(DAT_c08174e4);
  }
  if (DAT_c0817528 != (HANDLE)0x0) {
    CloseHandle(DAT_c0817528);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c08174d0);
LAB_c08143f0:
  (*(code *)param_1)(0x10000,0,0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  FUN_c0815dbc(local_24);
  return;
}



/* c0814438 LayoutMgrGetKeyboardType */

/* Boundary evidence: original MIPS .pdata c0814438..c08144e7. Semantic name remains unreviewed. */

uint LayoutMgrGetKeyboardType(int param_1)

{
  undefined1 auStack_48 [4];
  uint local_44;
  uint local_40;
  byte local_18;
  
                    /* 0x4438  13  LayoutMgrGetKeyboardType */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  memcpy(auStack_48,&DAT_c0817758,0x34);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  if ((param_1 != 0) && (local_44 = local_40, param_1 != 1)) {
    if (param_1 == 2) {
      local_44 = (uint)local_18;
    }
    else {
      SetLastError(0x57);
      local_44 = 0;
    }
  }
  return local_44;
}



/* c08144e8 LayoutMgrGetKeyboardLayout */

/* Boundary evidence: original MIPS .pdata c08144e8..c081454b. Semantic name remains unreviewed. */

undefined4 LayoutMgrGetKeyboardLayout(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x44e8  10  LayoutMgrGetKeyboardLayout */
  uVar1 = 0;
  if (param_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
    uVar1 = DAT_c08177d8;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  }
  else {
    SetLastError(0x57);
  }
  return uVar1;
}



/* c081454c LayoutMgrGetKeyboardLayoutName */

/* Boundary evidence: original MIPS .pdata c081454c..c08145e3. Semantic name remains unreviewed. */

bool LayoutMgrGetKeyboardLayoutName(int param_1)

{
  int iVar1;
  bool bVar2;
  
                    /* 0x454c  12  LayoutMgrGetKeyboardLayoutName */
  if (param_1 == 0) {
    SetLastError(0x57);
    bVar2 = false;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
    iVar1 = CeSafeCopyMemory(param_1,&DAT_c08177dc,0x12);
    bVar2 = iVar1 != 0;
    if (!bVar2) {
      SetLastError(0x6f8);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  }
  return bVar2;
}



/* c08145e4 LayoutMgrGetKeyboardLayoutList */

/* Boundary evidence: original MIPS .pdata c08145e4..c081474f. Semantic name remains unreviewed. */

uint LayoutMgrGetKeyboardLayoutList(uint param_1,ulong *param_2)

{
  int iVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  wchar_t *local_88 [2];
  ulong local_80 [16];
  wchar_t awStack_40 [10];
  uint local_2c;
  
                    /* 0x45e4  11  LayoutMgrGetKeyboardLayoutList */
  local_2c = DAT_c08174b8;
  uVar5 = 0;
  if (((param_2 == (ulong *)0x0) && (param_1 != 0)) || ((int)param_1 < 0)) {
    SetLastError(0x57);
    uVar5 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
    uVar6 = 1;
    puVar3 = local_80;
    do {
      iVar1 = FUN_c0812e50(uVar6,(LPBYTE)awStack_40);
      if (iVar1 == 1) {
        local_88[0] = (wchar_t *)0x0;
        uVar2 = wcstoul(awStack_40,local_88,0x10);
        uVar5 = uVar5 + 1;
        *puVar3 = uVar2;
        puVar3 = puVar3 + 1;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x10);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
    if (param_1 != 0) {
      if (param_1 < uVar5) {
        SetLastError(0x7a);
        uVar5 = 0;
      }
      else if ((uVar5 != 0) && (puVar3 = local_80, uVar5 != 0)) {
        puVar4 = param_2 + uVar5;
        do {
          *param_2 = *puVar3;
          param_2 = param_2 + 1;
          puVar3 = puVar3 + 1;
        } while (param_2 != puVar4);
      }
    }
  }
  FUN_c0815dbc(local_2c);
  return uVar5;
}



/* c0814750 FUN_c0814750 */

/* Boundary evidence: original MIPS .pdata c0814750..c08148df. Semantic name remains unreviewed. */

undefined4 FUN_c0814750(wchar_t *param_1)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  wchar_t *local_c8 [2];
  ulong local_c0 [16];
  ulong local_80 [16];
  wchar_t awStack_40 [10];
  uint local_2c;
  
  local_2c = DAT_c08174b8;
  uVar9 = 0;
  local_c8[0] = (wchar_t *)0x0;
  uVar1 = wcstoul(param_1,local_c8,0x10);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  uVar7 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  uVar8 = 1;
  puVar4 = local_80;
  do {
    iVar2 = FUN_c0812e50(uVar8,(LPBYTE)awStack_40);
    if (iVar2 == 1) {
      local_c8[0] = (wchar_t *)0x0;
      uVar3 = wcstoul(awStack_40,local_c8,0x10);
      uVar7 = uVar7 + 1;
      *puVar4 = uVar3;
      puVar4 = puVar4 + 1;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x10);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  if (uVar7 < 0x10) {
    if (uVar7 != 0) {
      puVar5 = local_80;
      puVar4 = local_c0;
      if (uVar7 != 0) {
        puVar6 = puVar4 + uVar7;
        do {
          *puVar4 = *puVar5;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (puVar4 != puVar6);
      }
    }
  }
  else {
    SetLastError(0x7a);
    uVar7 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  uVar8 = 0;
  if (uVar7 != 0) {
    puVar4 = local_c0;
    do {
      if (uVar1 == *puVar4) {
        uVar9 = 1;
        break;
      }
      uVar8 = uVar8 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar8 < uVar7);
  }
  FUN_c0815dbc(local_2c);
  return uVar9;
}



/* c08148e0 LayoutMgrLoadKeyboardLayout */

/* Boundary evidence: original MIPS .pdata c08148e0..c0814b97. Semantic name remains unreviewed. */

ulong LayoutMgrLoadKeyboardLayout(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  LSTATUS LVar5;
  uint uVar6;
  ulong uVar7;
  HKEY local_308;
  HKEY local_304;
  HKEY local_300;
  size_t local_2fc;
  DWORD aDStack_2f8 [2];
  ulong auStack_2f0 [174];
  wchar_t awStack_38 [8];
  undefined2 local_28;
  uint local_24;
  
                    /* 0x48e0  14  LayoutMgrLoadKeyboardLayout */
  local_24 = DAT_c08174b8;
  uVar7 = 0;
  local_28 = 0;
  local_304 = (HKEY)0x0;
  local_308 = (HKEY)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  HVar1 = StringCchLengthW(param_1,9,&local_2fc);
  if ((-1 < HVar1) && (local_2fc == 8)) {
    local_300 = (HKEY)0x0;
    uVar2 = wcstoul(param_1,(wchar_t **)&local_300,0x10);
    if (uVar2 != 0) {
      if ((uVar2 & 0xff000000) == 0xe0000000) {
        uVar3 = FUN_c0813348(uVar2);
        if (uVar3 != 0) {
          local_28 = 0;
          _snwprintf(awStack_38,8,L"%08X",uVar3);
          iVar4 = FUN_c0812f18(awStack_38,auStack_2f0);
          if (iVar4 != 0) goto LAB_c08149cc;
        }
      }
      else {
LAB_c08149cc:
        iVar4 = FUN_c0812f18(param_1,auStack_2f0);
        if (iVar4 != 0) {
          iVar4 = FUN_c0814750(param_1);
          uVar6 = 1;
          uVar3 = uVar2;
          if (iVar4 != 1) {
            do {
              iVar4 = FUN_c0812d50(uVar6,&local_300);
              if (iVar4 == 0) {
                _snwprintf(awStack_38,8,L"%u",uVar6);
                local_28 = 0;
                LVar5 = RegOpenKeyExW((HKEY)0x80000001,L"Keyboard Layout\\Preload",0,0,&local_304);
                uVar3 = uVar7;
                if (((LVar5 == 0) &&
                    (LVar5 = RegCreateKeyExW(local_304,awStack_38,0,(LPWSTR)0x0,0,0,
                                             (LPSECURITY_ATTRIBUTES)0x0,&local_308,aDStack_2f8),
                    LVar5 == 0)) &&
                   (LVar5 = RegSetValueExW(local_308,(LPCWSTR)0x0,0,1,(BYTE *)param_1,0x12),
                   uVar3 = uVar2, LVar5 != 0)) {
                  RegCloseKey(local_308);
                  local_308 = (HKEY)0x0;
                  RegDeleteKeyW(local_304,awStack_38);
                  uVar3 = uVar7;
                }
                break;
              }
              RegCloseKey(local_300);
              uVar6 = uVar6 + 1;
              uVar3 = uVar7;
            } while (uVar6 < 0x10);
          }
          goto LAB_c0814b30;
        }
      }
    }
  }
  SetLastError(0x57);
  uVar3 = uVar7;
LAB_c0814b30:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  if (local_304 != (HKEY)0x0) {
    RegCloseKey(local_304);
  }
  if (local_308 != (HKEY)0x0) {
    RegCloseKey(local_308);
  }
  FUN_c0815dbc(local_24);
  return uVar3;
}



/* c0814b98 LayoutMgrActivateKeyboardLayout */

/* Boundary evidence: original MIPS .pdata c0814b98..c0814c27. Semantic name remains unreviewed. */

undefined4 LayoutMgrActivateKeyboardLayout(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18 [2];
  
                    /* 0x4b98  9  LayoutMgrActivateKeyboardLayout */
  local_18[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  iVar1 = FUN_c0813578(param_1,local_18);
  if ((iVar1 != 0) && (uVar2 = 0, DAT_c08174c0 != 0)) {
    do {
      FUN_c0813dc4(param_1,uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_c08174c0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  return local_18[0];
}



/* c0814c28 FUN_c0814c28 */

/* Boundary evidence: original MIPS .pdata c0814c28..c0814c5b. Semantic name remains unreviewed. */

undefined4 FUN_c0814c28(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0814c5c KeybdDriverVKeyToUnicode */

/* Boundary evidence: original MIPS .pdata c0814c5c..c0814fef. Semantic name remains unreviewed. */

DWORD KeybdDriverVKeyToUnicode
                (uint param_1,uint param_2,int param_3,undefined4 param_4,int param_5,uint *param_6,
                uint *param_7,uint *param_8)

{
  wint_t wVar1;
  undefined2 extraout_var;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  byte bVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  DWORD dwErrCode;
  uint uVar9;
  uint uVar10;
  uint local_30;
  uint local_2c;
  
  local_2c = param_2;
                    /* 0x4c5c  8  KeybdDriverVKeyToUnicode */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  if (DAT_c0817538 == 0) {
    dwErrCode = 0x64a;
    goto LAB_c0814fa0;
  }
  uVar9 = param_1 & 0xff;
  if (param_8 == (uint *)0x0) {
LAB_c0814f9c:
    dwErrCode = 0x57;
    goto LAB_c0814fa0;
  }
  if (param_3 == 0) {
    uVar9 = FUN_c0811ad4(-0x3f7e8ac8,uVar9,0,param_8,1);
    if (uVar9 == 0) {
      *param_8 = 0;
    }
    else {
      wVar1 = towlower((wint_t)*param_8);
      *param_8 = CONCAT22(extraout_var,wVar1);
    }
  }
  else {
    if (((param_5 != 0x10) || (param_7 == (uint *)0x0)) || (param_6 == (uint *)0x0))
    goto LAB_c0814f9c;
    bVar5 = *(byte *)(uVar9 + param_3);
    uVar10 = param_2 & 0x80;
    bVar3 = bVar5 | 0x40;
    if ((bVar5 & 0x80) == 0) {
      bVar3 = bVar5 & 0xbf;
    }
    bVar5 = bVar3 | 0x82;
    if (uVar10 == 0) {
      bVar5 = bVar3 & 0x7f;
    }
    if (((bVar5 & 0x80) != 0) && ((bVar5 & 0x40) == 0)) {
      bVar5 = bVar5 ^ 1;
    }
    *(byte *)(uVar9 + param_3) = bVar5;
    if ((uVar9 == 0xa2) || (uVar9 == 0xa3)) {
      uVar6 = 0x11;
LAB_c0814de8:
      if (uVar6 != uVar9) {
        bVar5 = *(byte *)(uVar6 + param_3);
        if ((bVar5 & 0x80) == 0) {
          bVar5 = bVar5 & 0xbf;
        }
        else {
          bVar5 = bVar5 | 0x40;
        }
        if (uVar10 == 0) {
          bVar5 = bVar5 & 0x7f;
        }
        else {
          bVar5 = bVar5 | 0x82;
        }
        if (((bVar5 & 0x80) != 0) && ((bVar5 & 0x40) == 0)) {
          bVar5 = bVar5 ^ 1;
        }
        *(byte *)(uVar6 + param_3) = bVar5;
        uVar9 = uVar6;
      }
    }
    else {
      if ((uVar9 == 0xa4) || (uVar9 == 0xa5)) {
        uVar6 = 0x12;
        goto LAB_c0814de8;
      }
      if ((uVar9 == 0xa0) || (uVar9 == 0xa1)) {
        uVar6 = 0x10;
        goto LAB_c0814de8;
      }
    }
    uVar6 = 0;
    for (pbVar8 = DAT_c0817794; pbVar7 = DAT_c0817798, *pbVar8 != 0; pbVar8 = pbVar8 + 8) {
      if ((*(byte *)((uint)*pbVar8 + param_3) & 0x80) != 0) {
        uVar6 = *(uint *)(pbVar8 + 4) | uVar6;
      }
    }
    for (; *pbVar7 != 0; pbVar7 = pbVar7 + 8) {
      if ((*(byte *)((uint)*pbVar7 + param_3) & 1) != 0) {
        uVar6 = *(uint *)(pbVar7 + 4) | uVar6;
      }
    }
    uVar6 = *(byte *)(uVar9 + param_3) | uVar6;
    local_30 = uVar6;
    if ((uVar10 != 0) && (((uVar9 == 0x14 || (uVar9 == 0x90)) || (uVar9 == 0x91)))) {
      FUN_c0812ca0(uVar6);
    }
    *param_6 = 1;
    if ((DAT_c081778c != 1) ||
       (iVar2 = FUN_c0811c58(uVar9,local_2c,&local_30,(int *)param_8), uVar6 = local_30, iVar2 == 0)
       ) {
      if ((uVar10 == 0) || (uVar9 = FUN_c0811ad4(-0x3f7e8ac8,uVar9,uVar6,param_8,0x10), uVar9 == 0))
      {
        uVar6 = uVar6 | 0x10000;
      }
      else {
        *param_6 = uVar9;
        if ((uVar9 != 0) && (uVar9 != 0)) {
          puVar4 = param_7;
          do {
            *puVar4 = uVar6;
            puVar4 = puVar4 + 1;
          } while (puVar4 != param_7 + uVar9);
        }
      }
    }
    *param_7 = uVar6;
  }
  dwErrCode = 0;
LAB_c0814fa0:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode;
}



/* c0814ff0 KeybdDriverMapVirtualKey */

/* Boundary evidence: original MIPS .pdata c0814ff0..c0815237. Semantic name remains unreviewed. */

uint KeybdDriverMapVirtualKey(uint param_1,int param_2)

{
  uint uVar1;
  ushort *puVar2;
  DWORD dwErrCode;
  uint local_20 [2];
  
                    /* 0x4ff0  5  KeybdDriverMapVirtualKey */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  local_20[0] = 0;
  dwErrCode = 0;
  uVar1 = 0;
  if ((DAT_c0817538 == 0) || (*(int *)(DAT_c08174c8 + 8) == 0)) {
    dwErrCode = 0x64a;
  }
  else if (param_2 == 0) {
    if (param_1 == 0x10) {
      param_1 = 0xa0;
    }
    else if (param_1 == 0x11) {
      param_1 = 0xa2;
    }
    else if (param_1 == 0x12) {
      param_1 = 0xa4;
    }
    puVar2 = (ushort *)((param_1 & 0xff) * 2 + DAT_c0817778);
    uVar1 = (uint)*(byte *)((int)puVar2 + 1);
    local_20[0] = (uint)*puVar2;
    if ((char)*puVar2 == '\x01') {
      uVar1 = uVar1 | 0xe000;
    }
    else if ((char)*puVar2 == '\x02') {
      uVar1 = uVar1 | 0xe11d00;
    }
  }
  else if (param_2 == 1) {
    FUN_c081158c(param_1,*(undefined4 **)(DAT_c08174c8 + 0x26c),*(uint *)(DAT_c08174c8 + 0x270),
                 local_20);
    uVar1 = local_20[0];
    if (local_20[0] != 0) {
      if ((local_20[0] == 0xa2) || (local_20[0] == 0xa3)) {
        uVar1 = 0x11;
      }
      else if ((local_20[0] == 0xa4) || (local_20[0] == 0xa5)) {
        uVar1 = 0x12;
      }
      else if ((local_20[0] == 0xa0) || (local_20[0] == 0xa1)) {
        uVar1 = 0x10;
      }
    }
  }
  else if (param_2 == 2) {
    KeybdDriverVKeyToUnicode(param_1,0,0,0,0,(uint *)0x0,(uint *)0x0,local_20);
    uVar1 = local_20[0];
  }
  else if (param_2 == 3) {
    FUN_c081158c(param_1,*(undefined4 **)(DAT_c08174c8 + 0x26c),*(uint *)(DAT_c08174c8 + 0x270),
                 local_20);
    uVar1 = local_20[0];
  }
  else {
    dwErrCode = 0x57;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0817514);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return uVar1;
}



/* c0815238 IL_00000409 */

/* Boundary evidence: original MIPS .pdata c0815238..c081526f. Semantic name remains unreviewed. */

bool IL_00000409(int *param_1)

{
  int iVar1;
  
                    /* 0x5238  1  IL_00000409 */
  iVar1 = *param_1;
  if (iVar1 == 0x34) {
    memcpy(param_1,&DAT_c0817304,0x34);
  }
  return iVar1 == 0x34;
}



/* c0815270 FUN_c0815270 */

/* Boundary evidence: original MIPS .pdata c0815270..c081536f. Semantic name remains unreviewed. */

void FUN_c0815270(int param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == (uint *)0x0) {
    FUN_c0815868(param_1,param_2,0,0);
  }
  else {
    for (uVar1 = FUN_c0815868(param_1,param_2,(int)param_3,param_4); uVar1 != 0; uVar1 = uVar1 - 1)
    {
      if ((param_3[2] & 0x80) != 0) {
        uVar2 = *param_3 & 0xff;
        if ((((((uVar2 == 0xa0) || (uVar2 == 0xa1)) || (uVar2 == 0xa2)) ||
             ((uVar2 == 0xa3 || (uVar2 == 0xa4)))) ||
            ((uVar2 == 0xa5 || ((uVar2 == 0x5b || (uVar2 == 0x5c)))))) ||
           ((uVar2 == 0x14 || (uVar2 == 0x90)))) {
          *param_3 = *param_3 | 0x2000000;
        }
      }
      param_3 = param_3 + 3;
    }
  }
  return;
}



/* c0815370 PS2_AT_00000409 */

bool PS2_AT_00000409(int *param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  
  puVar4 = PTR_FUN_c0817494;
  iVar3 = DAT_c0817490;
  puVar2 = PTR_PTR_c081748c;
  iVar1 = DAT_c0817488;
                    /* 0x5370  15  PS2_AT_00000409 */
  iVar5 = *param_1;
  if (iVar5 == 0x14) {
    *param_1 = DAT_c0817484;
    param_1[1] = iVar1;
    param_1[2] = (int)puVar2;
    param_1[3] = iVar3;
    param_1[4] = (int)puVar4;
  }
  return iVar5 == 0x14;
}



/* c08153bc FUN_c08153bc */

/* Boundary evidence: original MIPS .pdata c08153bc..c08154d7. Semantic name remains unreviewed. */

undefined4 FUN_c08153bc(int param_1)

{
  wchar_t *pwVar1;
  uint uVar2;
  
  if (param_1 == 8) {
    if (DAT_c081749c == 4) {
      DAT_c081749c = 0;
      DAT_c0817498 = 1000;
      pwVar1 = L"Kernel Profiler mode: Unbuffered\r\n";
    }
    else if (DAT_c081749c == 0) {
      DAT_c081749c = 0x40;
      pwVar1 = L"Kernel Profiler mode: CeLog\r\n";
      DAT_c0817498 = 200;
    }
    else {
      DAT_c081749c = 4;
      DAT_c0817498 = 200;
      pwVar1 = L"Kernel Profiler mode: Buffered\r\n";
    }
    NKDbgPrintfW(pwVar1);
  }
  else {
    uVar2 = DAT_c081749c;
    if (param_1 != 9) {
      if (param_1 == 10) {
        uVar2 = DAT_c081749c | 2;
      }
      else {
        if (param_1 != 0xb) {
          if (param_1 != 0xc) {
            return 1;
          }
          ProfileStop();
          return 1;
        }
        uVar2 = DAT_c081749c | 1;
      }
    }
    ProfileStart(DAT_c0817498,uVar2);
  }
  return 1;
}



/* c08154d8 FUN_c08154d8 */

/* Boundary evidence: original MIPS .pdata c08154d8..c08156a3. Semantic name remains unreviewed. */

int FUN_c08154d8(uint param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  uVar5 = param_1 & 0xff;
  uVar6 = 0;
  iVar7 = 0;
  iVar9 = 0;
  uVar1 = 0;
  uVar8 = 0;
  uVar2 = uVar5;
  if (uVar5 == 0xa0) {
    DAT_c0817834 = 1;
    DAT_c0817838 = 1;
    DAT_c081782c = param_2;
    goto LAB_c0815668;
  }
  if (uVar5 == 0xa1) {
    DAT_c0817878 = 1;
    DAT_c0817828 = 1;
    DAT_c0817830 = param_2;
    goto LAB_c0815668;
  }
  if ((uVar5 < 0x60) || (0x6e < uVar5)) goto LAB_c0815668;
  uVar2 = (&DAT_c081783c)[uVar5 - 0x60];
  if (uVar2 == 0) {
    if ((param_3 & 0x1000) != 0) {
      if (DAT_c0817834 == 0) {
        uVar2 = uVar5;
        if (DAT_c0817878 == 0) goto LAB_c081562c;
      }
      else if (DAT_c0817838 != 0) {
        iVar7 = 0xa0;
        DAT_c0817838 = 0;
        uVar1 = DAT_c081782c;
      }
      if ((DAT_c0817878 != 0) && (DAT_c0817828 != 0)) {
        iVar9 = 0xa1;
        DAT_c0817828 = 0;
        uVar8 = DAT_c0817830;
      }
    }
    uVar2 = (uint)*(byte *)((int)L"Kernel Profiler mode: CeLog\r\n" + uVar5 + 0x24);
  }
LAB_c081562c:
  (&DAT_c081783c)[uVar5 - 0x60] = uVar2;
  if (iVar7 != 0) {
    *param_4 = iVar7;
    param_4[1] = uVar1;
    param_4[2] = 0;
  }
  uVar1 = (uint)(iVar7 != 0);
  uVar6 = uVar1;
  if (iVar9 != 0) {
    uVar6 = uVar1 + 1;
    piVar3 = param_4 + uVar1 * 3;
    *piVar3 = iVar9;
    piVar3[1] = uVar8;
    piVar3[2] = 0;
  }
LAB_c0815668:
  puVar4 = (uint *)(param_4 + uVar6 * 3);
  *puVar4 = uVar2 | param_1 & 0xffffff00;
  puVar4[1] = param_2;
  puVar4[2] = 0x80;
  return uVar6 + 1;
}



/* c08156a4 FUN_c08156a4 */

/* Boundary evidence: original MIPS .pdata c08156a4..c0815867. Semantic name remains unreviewed. */

int FUN_c08156a4(uint param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar8 = param_1 & 0xff;
  iVar2 = 0;
  bVar1 = true;
  uVar10 = 0;
  uVar5 = 0;
  uVar9 = 0;
  uVar4 = 0;
  if (uVar8 == 0xa0) {
    bVar1 = DAT_c0817838 != 0;
    DAT_c0817834 = 0;
    DAT_c0817838 = 0;
LAB_c08157ec:
    if (!bVar1) goto LAB_c0815808;
  }
  else {
    if (uVar8 == 0xa1) {
      bVar1 = DAT_c0817828 != 0;
      DAT_c0817878 = 0;
      DAT_c0817828 = 0;
      goto LAB_c08157ec;
    }
    if ((0x5f < uVar8) && (uVar8 < 0x6f)) {
      iVar3 = uVar8 - 0x60;
      uVar8 = (&DAT_c081783c)[iVar3];
      (&DAT_c081783c)[iVar3] = 0;
      piVar7 = &DAT_c081783c;
      do {
        if (*piVar7 != 0) goto LAB_c08157f4;
        piVar7 = piVar7 + 1;
      } while ((int)piVar7 < -0x3f7e8788);
      if ((DAT_c0817834 != 0) && (DAT_c0817838 == 0)) {
        uVar10 = 0xa0;
        DAT_c0817838 = 1;
        uVar5 = DAT_c081782c;
      }
      if ((DAT_c0817878 != 0) && (DAT_c0817828 == 0)) {
        uVar9 = 0xa1;
        DAT_c0817828 = 1;
        uVar4 = DAT_c0817830;
        goto LAB_c08157ec;
      }
    }
  }
LAB_c08157f4:
  *param_4 = uVar8 | param_1 & 0xffffff00;
  param_4[1] = param_2;
  iVar2 = 1;
  param_4[2] = 0;
LAB_c0815808:
  iVar3 = iVar2;
  if (uVar10 != 0) {
    iVar3 = iVar2 + 1;
    puVar6 = param_4 + iVar2 * 3;
    *puVar6 = uVar10;
    puVar6[1] = uVar5;
    puVar6[2] = 0x80;
  }
  iVar2 = iVar3;
  if (uVar9 != 0) {
    iVar2 = iVar3 + 1;
    puVar6 = param_4 + iVar3 * 3;
    *puVar6 = uVar9;
    puVar6[1] = uVar4;
    puVar6[2] = 0x80;
  }
  return iVar2;
}



/* c0815868 FUN_c0815868 */

/* Boundary evidence: original MIPS .pdata c0815868..c0815993. Semantic name remains unreviewed. */

uint FUN_c0815868(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  short extraout_var;
  short extraout_var_00;
  code *pcVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar1 = param_2 * 3;
  uVar5 = 0;
  if (param_3 == 0) {
    iVar2 = IsAPIReady(0x51);
    uVar5 = uVar1;
    if (iVar2 != 0) {
      GetAsyncKeyState(0xa0);
      if (extraout_var < 0) {
        DAT_c0817834 = 1;
        DAT_c0817838 = 1;
      }
      GetAsyncKeyState(0xa1);
      if (extraout_var_00 < 0) {
        DAT_c0817878 = 1;
        DAT_c0817828 = 1;
      }
    }
  }
  else if (param_4 < uVar1) {
    uVar5 = 0;
  }
  else if (param_2 != 0) {
    puVar4 = (uint *)(param_1 + 8);
    do {
      pcVar3 = FUN_c08154d8;
      if ((*puVar4 & 0x80) == 0) {
        pcVar3 = FUN_c08156a4;
      }
      iVar2 = (*pcVar3)(puVar4[-2],puVar4[-1],*puVar4,param_3);
      param_2 = param_2 + -1;
      uVar5 = iVar2 + uVar5;
      puVar4 = puVar4 + 3;
      param_3 = iVar2 * 0xc + param_3;
    } while (param_2 != 0);
  }
  return uVar5;
}



/* c0815994 FUN_c0815994 */

undefined4 FUN_c0815994(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = &DAT_c08174a8;
  return 1;
}



/* c0815b08 FUN_c0815b08 */

/* Boundary evidence: original MIPS .pdata c0815b08..c0815c43. Semantic name remains unreviewed. */

int FUN_c0815b08(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c081788c != (code *)0x0) {
      iVar2 = (*DAT_c081788c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0815bb8;
    FUN_c0816018();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0814c28(param_1,param_2);
  }
LAB_c0815bb8:
  if (((param_2 == 0) && (FUN_c0815fa0(), iVar1 != 0)) && (DAT_c081788c != (code *)0x0)) {
    iVar1 = (*DAT_c081788c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0815c44 FUN_c0815c44 */

/* Boundary evidence: original MIPS .pdata c0815c44..c0815c6f. Semantic name remains unreviewed. */

void FUN_c0815c44(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0815c70 entry */

/* Boundary evidence: original MIPS .pdata c0815c70..c0815cc7. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c0815cc8();
  }
  FUN_c0815b08(param_1,param_2,param_3);
  return;
}



/* c0815cc8 FUN_c0815cc8 */

/* Boundary evidence: original MIPS .pdata c0815cc8..c0815d3b. Semantic name remains unreviewed. */

void FUN_c0815cc8(void)

{
  uint uVar1;
  
  if ((DAT_c08174b8 == 0) || (DAT_c08174b8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c08174b8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c08174b8 == 0) {
      DAT_c08174b8 = 0xb064;
    }
  }
  DAT_c08174bc = ~DAT_c08174b8;
  return;
}



/* c0815d3c FUN_c0815d3c */

/* Boundary evidence: original MIPS .pdata c0815d3c..c0815d8f. Semantic name remains unreviewed. */

void FUN_c0815d3c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0815dbc(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0815d90 FUN_c0815d90 */

/* Boundary evidence: original MIPS .pdata c0815d90..c0815dbb. Semantic name remains unreviewed. */

undefined4 FUN_c0815d90(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0815d3c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0815dbc FUN_c0815dbc */

/* Boundary evidence: original MIPS .pdata c0815dbc..c0815e03. Semantic name remains unreviewed. */

void FUN_c0815dbc(uint param_1)

{
  if ((param_1 == DAT_c08174b8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0815e04 FUN_c0815e04 */

/* Boundary evidence: original MIPS .pdata c0815e04..c0815e7f. Semantic name remains unreviewed. */

void FUN_c0815e04(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0815d3c(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c0815e80 FUN_c0815e80 */

/* Boundary evidence: original MIPS .pdata c0815e80..c0815f9f. Semantic name remains unreviewed. */

void FUN_c0815e80(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c081787c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0817884;
    if (DAT_c0817884 != (undefined4 *)0x0) {
      while (DAT_c0817880 = DAT_c0817880 + -1, _Memory <= DAT_c0817880) {
        if ((code *)*DAT_c0817880 != (code *)0x0) {
          (*(code *)*DAT_c0817880)();
          _Memory = DAT_c0817884;
        }
      }
      free(_Memory);
      DAT_c0817880 = (undefined4 *)0x0;
      DAT_c0817884 = (undefined4 *)0x0;
    }
    FUN_c0815fc4((undefined4 *)&DAT_c0811010,(undefined4 *)&DAT_c0811014);
  }
  FUN_c0815fc4((undefined4 *)&DAT_c0811018,(undefined4 *)&DAT_c081101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0817888,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0815fa0 FUN_c0815fa0 */

/* Boundary evidence: original MIPS .pdata c0815fa0..c0815fc3. Semantic name remains unreviewed. */

void FUN_c0815fa0(void)

{
  FUN_c0815e80(0,0,1);
  return;
}



/* c0815fc4 FUN_c0815fc4 */

/* Boundary evidence: original MIPS .pdata c0815fc4..c0816017. Semantic name remains unreviewed. */

void FUN_c0815fc4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0816018 FUN_c0816018 */

/* Boundary evidence: original MIPS .pdata c0816018..c0816053. Semantic name remains unreviewed. */

void FUN_c0816018(void)

{
  FUN_c0815fc4((undefined4 *)&DAT_c0811008,(undefined4 *)&DAT_c081100c);
  FUN_c0815fc4((undefined4 *)&DAT_c0811000,(undefined4 *)&DAT_c0811004);
  return;
}


