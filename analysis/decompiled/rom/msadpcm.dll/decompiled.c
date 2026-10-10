/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 10001208 FUN_10001208 */

undefined4 FUN_10001208(short *param_1)

{
  ushort uVar1;
  uint uVar2;
  
  if (((((param_1 != (short *)0x0) && (*param_1 == 1)) &&
       ((uVar1 = param_1[7], uVar1 == 8 || (uVar1 == 0x10)))) &&
      (((uVar2 = (uint)(ushort)param_1[1], uVar2 != 0 && (uVar2 < 3)) &&
       (uVar2 = (uint)(uVar1 >> 3) << ((uVar2 & 0x3e) >> 1), uVar2 == (ushort)param_1[6])))) &&
     (*(int *)(param_1 + 2) * uVar2 == *(int *)(param_1 + 4))) {
    return 1;
  }
  return 0;
}



/* 100012ec FUN_100012ec */

undefined4 FUN_100012ec(short *param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == (short *)0x0) || (*param_1 != 2)) || (param_1[7] != 4)) ||
     ((param_1[1] == 0 || (uVar1 = 1, 2 < (ushort)param_1[1])))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 10001370 FUN_10001370 */

undefined4 FUN_10001370(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  short *psVar3;
  
  if ((*(ushort *)(param_1 + 0x10) < 0x20) || (*(short *)(param_1 + 0x14) != 7)) {
LAB_10001428:
    uVar1 = 0;
  }
  else {
    psVar3 = (short *)(param_1 + 0x18);
    uVar2 = 0;
    do {
      if (((int)psVar3[-1] != *(int *)((int)&DAT_1000116c + uVar2)) ||
         ((int)*psVar3 != *(int *)((int)&DAT_10001188 + uVar2))) goto LAB_10001428;
      uVar2 = uVar2 + 4;
      psVar3 = psVar3 + 2;
    } while (uVar2 < 0x1c);
    uVar1 = 1;
  }
  return uVar1;
}



/* 10001434 FUN_10001434 */

int FUN_10001434(int param_1)

{
  int iVar1;
  
  iVar1 = 0x100 << (*(byte *)(param_1 + 2) >> 1 & 0x1f);
  if (0x2b11 < *(uint *)(param_1 + 4)) {
    iVar1 = (*(uint *)(param_1 + 4) / 11000) * iVar1;
  }
  return iVar1;
}



/* 1000148c FUN_1000148c */

uint FUN_1000148c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)(*(byte *)(param_1 + 2) >> 1);
  uVar1 = 4 << (uVar2 & 0x1f);
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  uVar1 = (((uint)*(ushort *)(param_1 + 0xc) - (7 << (uVar2 & 0x1f))) * 8) / uVar1 + 2;
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  return (*(int *)(param_1 + 4) * (uint)*(ushort *)(param_1 + 0xc)) / uVar1;
}



/* 10001520 FUN_10001520 */

undefined4 FUN_10001520(int param_1)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 0x14) = 7;
  puVar2 = (undefined1 *)(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x15) = 0;
  uVar3 = 0;
  do {
    uVar1 = *(undefined2 *)((int)&DAT_1000116c + uVar3);
    puVar2[-2] = (char)uVar1;
    puVar2[-1] = (char)((ushort)uVar1 >> 8);
    uVar1 = *(undefined2 *)((int)&DAT_10001188 + uVar3);
    uVar3 = uVar3 + 4;
    *puVar2 = (char)uVar1;
    puVar2[1] = (char)((ushort)uVar1 >> 8);
    puVar2 = puVar2 + 4;
  } while (uVar3 < 0x1c);
  return 1;
}



/* 10001588 FUN_10001588 */

/* Boundary evidence: original MIPS .pdata 10001588..10001657. Semantic name remains unreviewed. */

undefined4 * FUN_10001588(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 4) == 0x63647561)) {
    puVar1 = LocalAlloc(0x40,0x18);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[2] = param_1;
      puVar1[3] = DAT_10004048;
      if (param_2 == 0) {
        return puVar1;
      }
      puVar1[1] = 0;
      *puVar1 = *(undefined4 *)(param_2 + 4);
      puVar1[4] = *(undefined4 *)(param_2 + 0xc);
      puVar1[5] = *(undefined4 *)(param_2 + 0x10);
      *(undefined4 *)(param_2 + 0x14) = 0;
      return puVar1;
    }
    if (param_2 != 0) {
      *(undefined4 *)(param_2 + 0x14) = 7;
    }
  }
  return (undefined4 *)0x0;
}



/* 10001658 FUN_10001658 */

/* Boundary evidence: original MIPS .pdata 10001658..10001783. Semantic name remains unreviewed. */

undefined4 FUN_10001658(undefined4 param_1,uint *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  uint local_718 [2];
  undefined4 uStack_710;
  undefined4 uStack_70d;
  undefined1 local_709;
  undefined1 auStack_708 [4];
  undefined1 auStack_704 [4];
  undefined1 auStack_700 [4];
  undefined1 auStack_6fc [4];
  undefined1 auStack_6f8 [8];
  WCHAR aWStack_6f0 [32];
  WCHAR aWStack_6b0 [128];
  WCHAR aWStack_5b0 [80];
  WCHAR aWStack_510 [128];
  WCHAR aWStack_410 [512];
  uint local_10;
  
  local_10 = DAT_1000403c;
  local_718[0] = *param_2;
  if (0x707 < local_718[0]) {
    local_718[0] = 0x708;
  }
  local_718[1] = 0x63647561;
  uStack_70d._3_1_ = 0x21;
  uStack_70d._2_1_ = 0;
  local_709 = 0;
  uVar2 = (uint)((int)register0x00000074 + -0x70d) & 3;
  puVar3 = (uint *)((int)((int)register0x00000074 + -0x70d) - uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_708 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x4001997U >> (3 - uVar2) * 8;
  puVar1 = auStack_704 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x4000000U >> (3 - uVar2) * 8;
  puVar1 = auStack_700 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 1U >> (3 - uVar2) * 8;
  puVar1 = auStack_6fc + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 2U >> (3 - uVar2) * 8;
  puVar1 = auStack_6f8 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  uStack_710 = 0;
  uStack_70d._1_1_ = 1;
  auStack_708 = (undefined1  [4])0x4001997;
  auStack_704 = (undefined1  [4])0x4000000;
  auStack_700 = (undefined1  [4])0x1;
  auStack_6fc = (undefined1  [4])0x2;
  auStack_6f8._0_4_ = 0;
  wsprintfW(aWStack_6f0,L"MS-ADPCM");
  wsprintfW(aWStack_6b0,L"Microsoft ADPCM CODEC");
  wsprintfW(aWStack_5b0,L"Copyright (c) 1992-1995 Microsoft Corporation");
  wsprintfW(aWStack_510,L"");
  wsprintfW(aWStack_410,L"Compresses and decompresses Microsoft ADPCM audio data.");
  memcpy(param_2,local_718,local_718[0]);
  FUN_10003410(local_10);
  return 0;
}



/* 10001784 FUN_10001784 */

/* Boundary evidence: original MIPS .pdata 10001784..100019bb. Semantic name remains unreviewed. */

undefined4 FUN_10001784(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  uint uVar5;
  
  psVar4 = *(short **)(param_2 + 8);
  psVar3 = *(short **)(param_2 + 0x10);
  if (((*psVar4 == 2) && (iVar2 = FUN_100012ec(psVar4), iVar2 != 0)) &&
     (iVar2 = FUN_10001370((int)psVar4), iVar2 != 0)) {
    uVar5 = *(uint *)(param_2 + 4);
    if (((((uVar5 & 0x10000) == 0) || (*psVar3 == 1)) &&
        (((uVar5 & 0x20000) == 0 || (psVar4[1] == psVar3[1])))) &&
       (((uVar5 & 0x40000) == 0 || (*(int *)(psVar4 + 2) == *(int *)(psVar3 + 2))))) {
      *(undefined1 *)((int)psVar3 + 1) = 0;
      *(undefined1 *)psVar3 = 1;
      *(int *)(psVar3 + 2) = *(int *)(psVar4 + 2);
      uVar1 = *(undefined1 *)((int)psVar4 + 3);
      *(char *)(psVar3 + 1) = (char)psVar4[1];
      *(undefined1 *)((int)psVar3 + 3) = uVar1;
      if ((*(uint *)(param_2 + 4) & 0x80000) == 0) {
        *(undefined1 *)(psVar3 + 7) = 0x10;
        *(undefined1 *)((int)psVar3 + 0xf) = 0;
      }
      else if ((psVar3[7] != 8) && (psVar3[7] != 0x10)) {
        return 0x200;
      }
      uVar5 = (uint)((ushort)psVar3[7] >> 3) << (*(byte *)(psVar3 + 1) >> 1 & 0x1f) & 0xffff;
      *(char *)(psVar3 + 6) = (char)uVar5;
      *(char *)((int)psVar3 + 0xd) = (char)(uVar5 >> 8);
      *(uint *)(psVar3 + 4) = uVar5 * *(int *)(psVar3 + 2);
      return 0;
    }
  }
  return 0x200;
}



/* 100019bc FUN_100019bc */

/* Boundary evidence: original MIPS .pdata 100019bc..10001b4f. Semantic name remains unreviewed. */

undefined4 FUN_100019bc(LPVOID param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  IsBadWritePtr(param_2,0x78);
  IsBadWritePtr(param_1,0x18);
  uVar1 = param_3 & 0xf;
  if (uVar1 == 0) {
    if (1 < param_2[1]) {
      return 0x200;
    }
    uVar1 = *(uint *)(&DAT_1000103c + param_2[1] * 4);
joined_r0x10001a84:
    if (uVar1 == 1) {
      uVar1 = 0x10;
      param_2[1] = 0;
      param_2[2] = 1;
      param_2[5] = 0x10;
      goto LAB_10001af8;
    }
    if (uVar1 != 2) {
      return 0x200;
    }
  }
  else {
    if (uVar1 == 1) {
      uVar1 = param_2[2];
      goto joined_r0x10001a84;
    }
    if (uVar1 != 2) {
      return 8;
    }
    uVar1 = param_2[2];
    if (uVar1 != 0) goto joined_r0x10001a84;
  }
  uVar1 = 0x32;
  param_2[1] = 1;
  param_2[2] = 2;
  param_2[5] = 8;
LAB_10001af8:
  param_2[4] = 1;
  uVar2 = *param_2;
  param_2[3] = uVar1;
  *(undefined1 *)((int)param_2 + 0x19) = 0;
  *(undefined1 *)(param_2 + 6) = 0;
  if (0x77 < uVar2) {
    uVar2 = 0x78;
  }
  *param_2 = uVar2;
  return 0;
}



/* 10001b50 FUN_10001b50 */

/* Boundary evidence: original MIPS .pdata 10001b50..10001d3b. Semantic name remains unreviewed. */

undefined4 FUN_10001b50(undefined4 param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  
  psVar6 = (short *)param_2[4];
  if ((param_3 & 0xf) == 0) {
    if (param_2[2] != 2) {
      return 0x200;
    }
    uVar3 = param_2[1];
    if (7 < uVar3) {
      return 0x200;
    }
    *(undefined1 *)((int)psVar6 + 1) = 0;
    *(undefined1 *)psVar6 = 2;
    uVar5 = (uVar3 & 1) + 1;
    *(undefined4 *)(psVar6 + 2) = *(undefined4 *)(&DAT_10001044 + (uVar3 >> 1) * 4);
    *(char *)(psVar6 + 1) = (char)uVar5;
    *(undefined1 *)((int)psVar6 + 3) = 0;
    *(undefined1 *)(psVar6 + 7) = 4;
    *(undefined1 *)((int)psVar6 + 0xf) = 0;
    uVar3 = FUN_10001434((int)psVar6);
    uVar3 = uVar3 & 0xffff;
    *(char *)(psVar6 + 6) = (char)uVar3;
    *(char *)((int)psVar6 + 0xd) = (char)(uVar3 >> 8);
    uVar1 = FUN_1000148c((int)psVar6);
    uVar5 = uVar5 >> 1;
    *(undefined1 *)(psVar6 + 8) = 0x20;
    uVar4 = 4 << uVar5;
    *(uint *)(psVar6 + 4) = uVar1;
    *(undefined1 *)((int)psVar6 + 0x11) = 0;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    uVar3 = ((uVar3 - (7 << uVar5)) * 8) / uVar4 + 2 & 0xffff;
    *(char *)(psVar6 + 9) = (char)uVar3;
    *(char *)((int)psVar6 + 0x13) = (char)(uVar3 >> 8);
    FUN_10001520((int)psVar6);
  }
  else if ((param_3 & 0xf) != 1) {
    return 8;
  }
  if (((*psVar6 == 2) && (iVar2 = FUN_100012ec(psVar6), iVar2 != 0)) &&
     (iVar2 = FUN_10001370((int)psVar6), iVar2 != 0)) {
    uVar3 = *param_2;
    param_2[3] = 1;
    *(undefined1 *)(param_2 + 6) = 0;
    *(undefined1 *)((int)param_2 + 0x19) = 0;
    if (0x117 < uVar3) {
      uVar3 = 0x118;
    }
    *param_2 = uVar3;
    return 0;
  }
  return 0x200;
}



/* 10001d3c FUN_10001d3c */

/* Boundary evidence: original MIPS .pdata 10001d3c..10001df3. Semantic name remains unreviewed. */

undefined4 FUN_10001d3c(undefined4 param_1,short *param_2,short *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_100012ec(param_2);
  if ((((iVar1 == 0) || (iVar1 = FUN_10001208(param_3), iVar1 == 0)) || (param_2[1] != param_3[1]))
     || ((*(int *)(param_2 + 2) != *(int *)(param_3 + 2) ||
         (iVar1 = FUN_10001370((int)param_2), iVar1 == 0)))) {
    uVar2 = 0x200;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 10001df4 FUN_10001df4 */

/* Boundary evidence: original MIPS .pdata 10001df4..10001f3f. Semantic name remains unreviewed. */

undefined4 FUN_10001df4(undefined4 param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  short *psVar3;
  short *psVar4;
  
  psVar4 = *(short **)(param_2 + 4);
  psVar3 = *(short **)(param_2 + 8);
  iVar1 = FUN_10001d3c(param_1,psVar4,psVar3);
  if ((iVar1 != 0) || (*psVar4 != 2)) {
    return 0x200;
  }
  if (psVar3[1] == 1) {
    if (psVar3[7] != 8) {
      pcVar2 = FUN_1000274c;
      goto LAB_10001f14;
    }
    pcVar2 = FUN_100024cc;
  }
  else {
    if (psVar3[1] != 2) {
      return 0x200;
    }
    if (psVar3[7] != 8) {
      pcVar2 = FUN_10002d70;
LAB_10001f14:
      *(code **)(param_2 + 0x20) = pcVar2;
      return 0;
    }
    pcVar2 = FUN_100029f4;
  }
  *(code **)(param_2 + 0x20) = pcVar2;
  return 0;
}



/* 10001f40 FUN_10001f40 */

undefined4 FUN_10001f40(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  uint uVar5;
  
  psVar4 = *(short **)(param_1 + 4);
  uVar2 = *(uint *)(param_2 + 4) & 0xf;
  if (uVar2 == 0) {
    uVar2 = *(uint *)(param_2 + 8);
    if (*psVar4 == 2) {
      uVar3 = (uint)(ushort)psVar4[6];
      uVar5 = uVar2 / uVar3;
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      if (uVar5 == 0) {
        return 0x200;
      }
      uVar1 = (uint)*(ushort *)(*(int *)(param_1 + 8) + 0xc) * (uint)(ushort)psVar4[9];
      if (uVar1 == 0) {
        trap(0x1c00);
      }
      if (0xffffffff / uVar1 < uVar5) {
        return 0x200;
      }
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      if (uVar2 % uVar3 != 0) {
        uVar5 = uVar5 + 1;
      }
      uVar2 = uVar1 * uVar5;
    }
    *(uint *)(param_2 + 0xc) = uVar2;
  }
  else {
    if (uVar2 != 1) {
      return 8;
    }
    uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 8) + 0xc) * (uint)(ushort)psVar4[9];
    uVar5 = *(uint *)(param_2 + 0xc) / uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    if (uVar5 == 0) {
      return 0x200;
    }
    *(uint *)(param_2 + 8) = (ushort)psVar4[6] * uVar5;
  }
  return 0;
}



/* 100020fc FUN_100020fc */

/* Boundary evidence: original MIPS .pdata 100020fc..100022c3. Semantic name remains unreviewed. */

undefined4 FUN_100020fc(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 uStack_1c;
  
  uVar5 = *(uint *)(param_3 + 0x2c);
  sVar2 = **(short **)(param_2 + 8);
  local_28 = 0x10;
  uStack_1c = *(uint *)(param_3 + 0x20);
  uVar4 = (int)&uStack_1c + 3U & 3;
  puVar1 = (uint *)(((int)&uStack_1c + 3U) - uVar4);
  *puVar1 = *puVar1 & -1 << (uVar4 + 1) * 8 | uStack_1c >> (3 - uVar4) * 8;
  local_24 = 1;
  local_20 = 0;
  FUN_10001f40(param_2,(int)&local_28);
  uVar4 = *(uint *)(param_3 + 0x10);
  if (local_20 < uVar4) {
    uVar3 = 0x200;
  }
  else {
    if (sVar2 == 1) {
      iVar6 = *(int *)(param_2 + 4);
      if ((uVar5 & 4) != 0) {
        uVar5 = (uint)*(ushort *)(iVar6 + 0xc);
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        uVar4 = (uVar4 / uVar5) * uVar5;
      }
      *(uint *)(param_3 + 0x14) = uVar4;
      uVar3 = (**(code **)(param_2 + 0x20))
                        (*(undefined4 *)(param_3 + 0xc),uVar4,*(undefined4 *)(param_3 + 0x1c),
                         *(undefined2 *)(iVar6 + 0xc),*(undefined2 *)(iVar6 + 0x12),
                         *(undefined2 *)(iVar6 + 0x14),iVar6 + 0x16);
      *(undefined4 *)(param_3 + 0x24) = uVar3;
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 100022c4 DriverProc */

/* Boundary evidence: original MIPS .pdata 100022c4..1000244f. Semantic name remains unreviewed. */

undefined4 * DriverProc(LPVOID param_1,undefined4 param_2,uint param_3,uint *param_4,uint param_5)

{
  undefined4 *puVar1;
  
                    /* 0x22c4  1  DriverProc */
  if (param_3 < 0x601a) {
    if (param_3 == 0x6019) {
      puVar1 = (undefined4 *)FUN_100019bc(param_1,param_4,param_5);
      return puVar1;
    }
    if (param_3 == 1) {
      return (undefined4 *)0x1;
    }
    if (param_3 == 3) {
      puVar1 = FUN_10001588(param_2,param_5);
      return puVar1;
    }
    if (param_3 == 4) {
      if (param_1 == (LPVOID)0x0) {
        return (undefined4 *)0x1;
      }
      LocalFree(param_1);
      return (undefined4 *)0x1;
    }
    if (param_3 == 6) {
      return (undefined4 *)0x1;
    }
    if (param_3 == 0x600a) {
      puVar1 = (undefined4 *)FUN_10001658(param_1,param_4);
      return puVar1;
    }
    if (param_3 != 0x600b) {
LAB_100023d0:
      if (param_3 < 0x4000) goto LAB_100023dc;
    }
    puVar1 = (undefined4 *)0x8;
  }
  else {
    if (param_3 == 0x601a) {
      puVar1 = (undefined4 *)FUN_10001b50(param_1,param_4,param_5);
      return puVar1;
    }
    if (param_3 == 0x601b) {
      puVar1 = (undefined4 *)FUN_10001784(param_1,(int)param_4);
      return puVar1;
    }
    if (param_3 == 0x604c) {
      puVar1 = (undefined4 *)FUN_10001df4(param_1,(int)param_4);
      return puVar1;
    }
    if (param_3 != 0x604d) {
      if (param_3 == 0x604e) {
        puVar1 = (undefined4 *)FUN_10001f40((int)param_4,param_5);
        return puVar1;
      }
      if (param_3 == 0x604f) {
        puVar1 = (undefined4 *)FUN_100020fc(param_1,(int)param_4,param_5);
        return puVar1;
      }
      goto LAB_100023d0;
    }
LAB_100023dc:
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}



/* 10002450 FUN_10002450 */

int FUN_10002450(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  iVar1 = (param_1 * param_2 + param_3 * param_4 >> 8) + ((param_5 << 0x1c) >> 0x1c) * param_6;
  if (iVar1 < 0x8000) {
    if (iVar1 < -0x8000) {
      iVar1 = -0x8000;
    }
  }
  else {
    iVar1 = 0x7fff;
  }
  return iVar1;
}



/* 100024cc FUN_100024cc */

/* Boundary evidence: original MIPS .pdata 100024cc..1000274b. Semantic name remains unreviewed. */

int FUN_100024cc(byte *param_1,uint param_2,char *param_3,uint param_4,undefined4 param_5,
                uint param_6,int param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  
  pcVar9 = param_3;
  while( true ) {
    if (param_2 < 7) {
      return (int)pcVar9 - (int)param_3;
    }
    uVar8 = param_2;
    if (param_4 <= param_2) {
      uVar8 = param_4;
    }
    param_2 = param_2 - uVar8;
    iVar10 = uVar8 - 7;
    if (param_6 <= *param_1) break;
    psVar7 = (short *)((uint)*param_1 * 4 + param_7);
    iVar6 = (int)*psVar7;
    iVar4 = (int)psVar7[1];
    iVar3 = (int)*(short *)(param_1 + 1);
    iVar2 = (int)*(short *)(param_1 + 3);
    iVar5 = (int)*(short *)(param_1 + 5);
    *pcVar9 = (char)((ushort)*(short *)(param_1 + 3) >> 8) + -0x80;
    param_1 = param_1 + 7;
    while (iVar10 != 0) {
      bVar1 = *param_1;
      uVar8 = (int)(char)bVar1 >> 4;
      iVar10 = iVar10 + -1;
      param_1 = param_1 + 1;
      iVar5 = FUN_10002450(iVar2,iVar6,iVar5,iVar4,uVar8,iVar3);
      iVar3 = *(int *)(&DAT_100011a4 + (uVar8 & 0xf) * 4) * iVar3 >> 8;
      if (iVar3 < 0x10) {
        iVar3 = 0x10;
      }
      *pcVar9 = (char)((uint)iVar5 >> 8) + -0x80;
      uVar8 = (int)((uint)bVar1 << 0x1c) >> 0x1c;
      iVar2 = FUN_10002450(iVar5,iVar6,iVar2,iVar4,uVar8,iVar3);
      iVar3 = *(int *)(&DAT_100011a4 + (uVar8 & 0xf) * 4) * iVar3 >> 8;
      if (iVar3 < 0x10) {
        iVar3 = 0x10;
      }
      pcVar9[1] = (char)((uint)iVar2 >> 8) + -0x80;
      pcVar9 = pcVar9 + 2;
    }
  }
  return 0;
}



/* 1000274c FUN_1000274c */

/* Boundary evidence: original MIPS .pdata 1000274c..100029f3. Semantic name remains unreviewed. */

int FUN_1000274c(byte *param_1,uint param_2,undefined1 *param_3,uint param_4,undefined4 param_5,
                uint param_6,int param_7)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  uint uVar11;
  int iVar12;
  
  puVar4 = param_3;
  while( true ) {
    if (param_2 < 7) {
      return (int)puVar4 - (int)param_3;
    }
    uVar11 = param_2;
    if (param_4 <= param_2) {
      uVar11 = param_4;
    }
    param_2 = param_2 - uVar11;
    iVar12 = uVar11 - 7;
    if (param_6 <= *param_1) break;
    psVar10 = (short *)((uint)*param_1 * 4 + param_7);
    iVar9 = (int)*psVar10;
    iVar7 = (int)psVar10[1];
    iVar6 = (int)*(short *)(param_1 + 1);
    sVar2 = *(short *)(param_1 + 3);
    sVar3 = *(short *)(param_1 + 5);
    iVar5 = (int)sVar2;
    iVar8 = (int)sVar3;
    *puVar4 = (char)sVar3;
    puVar4[1] = (char)((ushort)sVar3 >> 8);
    puVar4[2] = (char)sVar2;
    puVar4[3] = (char)((ushort)sVar2 >> 8);
    param_1 = param_1 + 7;
    while (puVar4 = puVar4 + 4, iVar12 != 0) {
      bVar1 = *param_1;
      uVar11 = (int)(char)bVar1 >> 4;
      iVar12 = iVar12 + -1;
      param_1 = param_1 + 1;
      iVar8 = FUN_10002450(iVar5,iVar9,iVar8,iVar7,uVar11,iVar6);
      iVar6 = *(int *)(&DAT_100011a4 + (uVar11 & 0xf) * 4) * iVar6 >> 8;
      if (iVar6 < 0x10) {
        iVar6 = 0x10;
      }
      *puVar4 = (char)iVar8;
      uVar11 = (int)((uint)bVar1 << 0x1c) >> 0x1c;
      puVar4[1] = (char)((uint)iVar8 >> 8);
      iVar5 = FUN_10002450(iVar8,iVar9,iVar5,iVar7,uVar11,iVar6);
      iVar6 = *(int *)(&DAT_100011a4 + (uVar11 & 0xf) * 4) * iVar6 >> 8;
      if (iVar6 < 0x10) {
        iVar6 = 0x10;
      }
      puVar4[2] = (char)iVar5;
      puVar4[3] = (char)((uint)iVar5 >> 8);
    }
  }
  return 0;
}



/* 100029f4 FUN_100029f4 */

/* Boundary evidence: original MIPS .pdata 100029f4..10002d6f. Semantic name remains unreviewed. */

int FUN_100029f4(byte *param_1,uint param_2,char *param_3,uint param_4,undefined4 param_5,
                uint param_6,int param_7)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  short *psVar18;
  uint uVar19;
  char *pcVar20;
  int iVar21;
  
  pcVar20 = param_3;
  while( true ) {
    if (param_2 < 0xe) {
      return (int)pcVar20 - (int)param_3;
    }
    uVar19 = param_2;
    if (param_4 <= param_2) {
      uVar19 = param_4;
    }
    param_2 = param_2 - uVar19;
    iVar21 = uVar19 - 0xe;
    if (param_6 <= *param_1) break;
    psVar18 = (short *)((uint)*param_1 * 4 + param_7);
    sVar2 = *psVar18;
    sVar3 = psVar18[1];
    if (param_6 <= param_1[1]) {
      return 0;
    }
    psVar18 = (short *)((uint)param_1[1] * 4 + param_7);
    sVar4 = *psVar18;
    sVar5 = psVar18[1];
    iVar17 = (int)*(short *)(param_1 + 2);
    iVar16 = (int)*(short *)(param_1 + 4);
    sVar6 = *(short *)(param_1 + 6);
    sVar7 = *(short *)(param_1 + 8);
    sVar8 = *(short *)(param_1 + 10);
    sVar9 = *(short *)(param_1 + 0xc);
    *pcVar20 = (char)((ushort)sVar8 >> 8) + -0x80;
    pcVar20[1] = (char)((ushort)sVar9 >> 8) + -0x80;
    pcVar20[2] = (char)((ushort)sVar6 >> 8) + -0x80;
    pcVar20[3] = (char)((ushort)sVar7 >> 8) + -0x80;
    param_1 = param_1 + 0xe;
    pcVar20 = pcVar20 + 4;
    iVar14 = (int)sVar6;
    iVar15 = (int)sVar7;
    iVar12 = (int)sVar8;
    iVar13 = (int)sVar9;
    while (iVar11 = iVar15, iVar10 = iVar14, iVar21 != 0) {
      bVar1 = *param_1;
      uVar19 = (int)(char)bVar1 >> 4;
      iVar21 = iVar21 + -1;
      param_1 = param_1 + 1;
      iVar14 = FUN_10002450(iVar10,(int)sVar2,iVar12,(int)sVar3,uVar19,iVar17);
      iVar17 = *(int *)(&DAT_100011a4 + (uVar19 & 0xf) * 4) * iVar17 >> 8;
      if (iVar17 < 0x10) {
        iVar17 = 0x10;
      }
      *pcVar20 = (char)((uint)iVar14 >> 8) + -0x80;
      uVar19 = (int)((uint)bVar1 << 0x1c) >> 0x1c;
      iVar15 = FUN_10002450(iVar11,(int)sVar4,iVar13,(int)sVar5,uVar19,iVar16);
      iVar16 = *(int *)(&DAT_100011a4 + (uVar19 & 0xf) * 4) * iVar16 >> 8;
      if (iVar16 < 0x10) {
        iVar16 = 0x10;
      }
      pcVar20[1] = (char)((uint)iVar15 >> 8) + -0x80;
      pcVar20 = pcVar20 + 2;
      iVar12 = iVar10;
      iVar13 = iVar11;
    }
  }
  return 0;
}



/* 10002d70 FUN_10002d70 */

/* Boundary evidence: original MIPS .pdata 10002d70..100030ff. Semantic name remains unreviewed. */

int FUN_10002d70(byte *param_1,uint param_2,undefined1 *param_3,uint param_4,undefined4 param_5,
                uint param_6,int param_7)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  short *psVar18;
  uint uVar19;
  undefined1 *puVar20;
  int iVar21;
  
  puVar20 = param_3;
  while( true ) {
    if (param_2 < 0xe) {
      return (int)puVar20 - (int)param_3;
    }
    uVar19 = param_2;
    if (param_4 <= param_2) {
      uVar19 = param_4;
    }
    param_2 = param_2 - uVar19;
    iVar21 = uVar19 - 0xe;
    if (param_6 <= *param_1) break;
    psVar18 = (short *)((uint)*param_1 * 4 + param_7);
    sVar2 = *psVar18;
    sVar3 = psVar18[1];
    if (param_6 <= param_1[1]) {
      return 0;
    }
    psVar18 = (short *)((uint)param_1[1] * 4 + param_7);
    sVar4 = *psVar18;
    sVar5 = psVar18[1];
    iVar17 = (int)*(short *)(param_1 + 2);
    iVar16 = (int)*(short *)(param_1 + 4);
    sVar6 = *(short *)(param_1 + 6);
    sVar7 = *(short *)(param_1 + 8);
    sVar8 = *(short *)(param_1 + 10);
    sVar9 = *(short *)(param_1 + 0xc);
    puVar20[1] = (char)((ushort)sVar8 >> 8);
    *puVar20 = (char)sVar8;
    puVar20[2] = (char)sVar9;
    puVar20[3] = (char)((ushort)sVar9 >> 8);
    puVar20[4] = (char)sVar6;
    puVar20[5] = (char)((ushort)sVar6 >> 8);
    puVar20[6] = (char)sVar7;
    param_1 = param_1 + 0xe;
    puVar20[7] = (char)((ushort)sVar7 >> 8);
    puVar20 = puVar20 + 8;
    iVar14 = (int)sVar6;
    iVar15 = (int)sVar7;
    iVar12 = (int)sVar8;
    iVar13 = (int)sVar9;
    while (iVar11 = iVar15, iVar10 = iVar14, iVar21 != 0) {
      bVar1 = *param_1;
      uVar19 = (int)(char)bVar1 >> 4;
      iVar21 = iVar21 + -1;
      param_1 = param_1 + 1;
      iVar14 = FUN_10002450(iVar10,(int)sVar2,iVar12,(int)sVar3,uVar19,iVar17);
      iVar17 = *(int *)(&DAT_100011a4 + (uVar19 & 0xf) * 4) * iVar17 >> 8;
      if (iVar17 < 0x10) {
        iVar17 = 0x10;
      }
      *puVar20 = (char)iVar14;
      puVar20[1] = (char)((uint)iVar14 >> 8);
      uVar19 = (int)((uint)bVar1 << 0x1c) >> 0x1c;
      iVar15 = FUN_10002450(iVar11,(int)sVar4,iVar13,(int)sVar5,uVar19,iVar16);
      iVar16 = *(int *)(&DAT_100011a4 + (uVar19 & 0xf) * 4) * iVar16 >> 8;
      if (iVar16 < 0x10) {
        iVar16 = 0x10;
      }
      puVar20[2] = (char)iVar15;
      puVar20[3] = (char)((uint)iVar15 >> 8);
      puVar20 = puVar20 + 4;
      iVar12 = iVar10;
      iVar13 = iVar11;
    }
  }
  return 0;
}



/* 10003130 FUN_10003130 */

/* Boundary evidence: original MIPS .pdata 10003130..1000315b. Semantic name remains unreviewed. */

undefined4 FUN_10003130(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 1000315c FUN_1000315c */

/* Boundary evidence: original MIPS .pdata 1000315c..10003297. Semantic name remains unreviewed. */

int FUN_1000315c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_10004058 != (code *)0x0) {
      iVar2 = (*DAT_10004058)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_1000320c;
    FUN_100035f0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_10003130(param_1,param_2);
  }
LAB_1000320c:
  if (((param_2 == 0) && (FUN_10003578(), iVar1 != 0)) && (DAT_10004058 != (code *)0x0)) {
    iVar1 = (*DAT_10004058)(param_1,0,param_3);
  }
  return iVar1;
}



/* 10003298 FUN_10003298 */

/* Boundary evidence: original MIPS .pdata 10003298..100032c3. Semantic name remains unreviewed. */

void FUN_10003298(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 100032c4 entry */

/* Boundary evidence: original MIPS .pdata 100032c4..1000331b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_1000331c();
  }
  FUN_1000315c(param_1,param_2,param_3);
  return;
}



/* 1000331c FUN_1000331c */

/* Boundary evidence: original MIPS .pdata 1000331c..1000338f. Semantic name remains unreviewed. */

void FUN_1000331c(void)

{
  uint uVar1;
  
  if ((DAT_1000403c == 0) || (DAT_1000403c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_1000403c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_1000403c == 0) {
      DAT_1000403c = 0xb064;
    }
  }
  DAT_10004040 = ~DAT_1000403c;
  return;
}



/* 10003390 FUN_10003390 */

/* Boundary evidence: original MIPS .pdata 10003390..100033e3. Semantic name remains unreviewed. */

void FUN_10003390(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_10003410(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 100033e4 FUN_100033e4 */

/* Boundary evidence: original MIPS .pdata 100033e4..1000340f. Semantic name remains unreviewed. */

undefined4 FUN_100033e4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_10003390(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 10003410 FUN_10003410 */

/* Boundary evidence: original MIPS .pdata 10003410..10003457. Semantic name remains unreviewed. */

void FUN_10003410(uint param_1)

{
  if ((param_1 == DAT_1000403c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 10003458 FUN_10003458 */

/* Boundary evidence: original MIPS .pdata 10003458..10003577. Semantic name remains unreviewed. */

void FUN_10003458(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_10004044 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_10004050;
    if (DAT_10004050 != (undefined4 *)0x0) {
      while (DAT_1000404c = DAT_1000404c + -1, _Memory <= DAT_1000404c) {
        if ((code *)*DAT_1000404c != (code *)0x0) {
          (*(code *)*DAT_1000404c)();
          _Memory = DAT_10004050;
        }
      }
      free(_Memory);
      DAT_1000404c = (undefined4 *)0x0;
      DAT_10004050 = (undefined4 *)0x0;
    }
    FUN_1000359c((undefined4 *)&DAT_10001010,(undefined4 *)&DAT_10001014);
  }
  FUN_1000359c((undefined4 *)&DAT_10001018,(undefined4 *)&DAT_1000101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_10004054,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 10003578 FUN_10003578 */

/* Boundary evidence: original MIPS .pdata 10003578..1000359b. Semantic name remains unreviewed. */

void FUN_10003578(void)

{
  FUN_10003458(0,0,1);
  return;
}



/* 1000359c FUN_1000359c */

/* Boundary evidence: original MIPS .pdata 1000359c..100035ef. Semantic name remains unreviewed. */

void FUN_1000359c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 100035f0 FUN_100035f0 */

/* Boundary evidence: original MIPS .pdata 100035f0..1000362b. Semantic name remains unreviewed. */

void FUN_100035f0(void)

{
  FUN_1000359c((undefined4 *)&DAT_10001008,(undefined4 *)&DAT_1000100c);
  FUN_1000359c((undefined4 *)&DAT_10001000,(undefined4 *)&DAT_10001004);
  return;
}


