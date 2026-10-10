/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c02619a8 FUN_c02619a8 */

/* Boundary evidence: original MIPS .pdata c02619a8..c02619cf. Semantic name remains unreviewed. */

void FUN_c02619a8(void)

{
  EngAllocMem(0,4,0x64667454);
  return;
}



/* c02619d0 FUN_c02619d0 */

/* Boundary evidence: original MIPS .pdata c02619d0..c02619eb. Semantic name remains unreviewed. */

void FUN_c02619d0(void)

{
  EngFreeMem();
  return;
}



/* c02619ec FUN_c02619ec */

void FUN_c02619ec(void)

{
  return;
}



/* c02619f4 FUN_c02619f4 */

void FUN_c02619f4(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 1;
  return;
}



/* c0261a10 FUN_c0261a10 */

/* Boundary evidence: original MIPS .pdata c0261a10..c0261ab7. Semantic name remains unreviewed. */

void FUN_c0261a10(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  if (param_2 == -0x3ffffffa) {
    uVar3 = 0;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    if (*(int *)(param_1 + 0xc) != 0) {
      piVar2 = (int *)(param_1 + 0x24);
      do {
        iVar1 = *piVar2;
        if (*(int *)(iVar1 + 0xc) != 0) {
          EngFreeMem();
          *(undefined4 *)(iVar1 + 0xc) = 0;
        }
        if (*(int *)(iVar1 + 0x14) != 0) {
          EngFreeMem();
          *(undefined4 *)(iVar1 + 0x14) = 0;
        }
        uVar3 = uVar3 + 1;
        piVar2 = piVar2 + 3;
      } while (uVar3 < *(uint *)(param_1 + 0xc));
    }
  }
  return;
}



/* c0261ab8 FntDrvLoadFontFile */

/* Boundary evidence: original MIPS .pdata c0261ab8..c0261ba7. Semantic name remains unreviewed. */

int FntDrvLoadFontFile(int param_1,undefined4 *param_2,undefined4 *param_3,uint *param_4,int param_5
                      ,uint param_6,int param_7)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int local_28 [4];
  
                    /* 0x1ab8  2  FntDrvLoadFontFile */
  local_28[0] = 0;
  if ((param_1 == 1) && (param_5 == 0)) {
    uVar1 = *param_2;
    piVar2 = (int *)*param_3;
    uVar3 = *param_4;
    EngAcquireSemaphore(DAT_c029b620);
    FUN_c026e150(uVar1,piVar2,uVar3,param_6,param_7,local_28);
    EngReleaseSemaphore(DAT_c029b620);
  }
  else {
    local_28[0] = 0;
  }
  return local_28[0];
}



/* c0261ba8 FUN_c0261ba8 */

/* Boundary evidence: original MIPS .pdata c0261ba8..c0261c0f. Semantic name remains unreviewed. */

undefined4 FUN_c0261ba8(undefined4 *param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x24) = *(undefined4 *)*param_1;
  if ((*(int *)(in_v0 + -0x24) == -0x3ffffffa) || (*(int *)(in_v0 + -0x24) == -0x7ffffffe)) {
    *(undefined4 *)(in_v0 + -0x20) = 1;
  }
  else {
    *(undefined4 *)(in_v0 + -0x20) = 0;
  }
  return *(undefined4 *)(in_v0 + -0x20);
}



/* c0261c10 FntDrvUnloadFontFile */

/* Boundary evidence: original MIPS .pdata c0261c10..c0261ca7. Semantic name remains unreviewed. */

undefined4 FntDrvUnloadFontFile(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x1c10  7  FntDrvUnloadFontFile */
  EngAcquireSemaphore(DAT_c029b620);
  uVar1 = FUN_c026a6dc(param_1);
  EngReleaseSemaphore(DAT_c029b620);
  return uVar1;
}



/* c0261ca8 FUN_c0261ca8 */

/* Boundary evidence: original MIPS .pdata c0261ca8..c0261cb3. Semantic name remains unreviewed. */

undefined4 FUN_c0261ca8(void)

{
  return 1;
}



/* c0261cb4 FUN_c0261cb4 */

/* Boundary evidence: original MIPS .pdata c0261cb4..c0261de3. Semantic name remains unreviewed. */

int FUN_c0261cb4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 == 1) {
    iVar1 = *(int *)(param_1 + 0x14);
    iVar2 = *(int *)(iVar1 + 0x18);
    if (iVar2 == 0) {
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = EngMapFontFileFD(*(undefined4 *)(*(int *)(iVar1 + 0x24) + 0x1c),iVar1 + 0x10,
                                 iVar1 + 0x14,param_4,0);
      }
      if (iVar1 != 0) {
        EngAcquireSemaphore(DAT_c029b620);
        iVar2 = FUN_c0263a30(param_1);
        EngReleaseSemaphore(DAT_c029b620);
        EngUnmapFontFileFD(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x14) + 0x24) + 0x1c));
      }
    }
  }
  return iVar2;
}



/* c0261de4 FUN_c0261de4 */

/* Boundary evidence: original MIPS .pdata c0261de4..c0261def. Semantic name remains unreviewed. */

undefined4 FUN_c0261de4(void)

{
  return 1;
}



/* c0261df0 FntDrvQueryFontData */

/* Boundary evidence: original MIPS .pdata c0261df0..c0261f3b. Semantic name remains unreviewed. */

uint FntDrvQueryFontData(undefined4 param_1,int param_2,uint param_3,uint param_4,int *param_5,
                        uint *param_6,size_t param_7)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x1df0  4  FntDrvQueryFontData */
  uVar2 = 0xffffffff;
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = EngMapFontFileFD(*(undefined4 *)(*(int *)(iVar1 + 0x24) + 0x1c),iVar1 + 0x10,
                             iVar1 + 0x14);
  }
  if (iVar1 != 0) {
    EngAcquireSemaphore(DAT_c029b620);
    uVar2 = FUN_c0266a1c(param_2,param_3,param_4,param_5,param_6,param_7);
    EngReleaseSemaphore(DAT_c029b620);
    EngUnmapFontFileFD(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x24) + 0x1c));
  }
  return uVar2;
}



/* c0261f3c FUN_c0261f3c */

/* Boundary evidence: original MIPS .pdata c0261f3c..c0261f47. Semantic name remains unreviewed. */

undefined4 FUN_c0261f3c(void)

{
  return 1;
}



/* c0261f48 FUN_c0261f48 */

/* Boundary evidence: original MIPS .pdata c0261f48..c0261f9b. Semantic name remains unreviewed. */

void FUN_c0261f48(undefined4 param_1,int *param_2)

{
  EngAcquireSemaphore(DAT_c029b620);
  FUN_c026ea90(param_1,param_2);
  EngReleaseSemaphore(DAT_c029b620);
  return;
}



/* c0261f9c FntDrvDestroyFont */

/* Boundary evidence: original MIPS .pdata c0261f9c..c0261fdf. Semantic name remains unreviewed. */

void FntDrvDestroyFont(int param_1)

{
                    /* 0x1f9c  1  FntDrvDestroyFont */
  EngAcquireSemaphore(DAT_c029b620);
  FUN_c026ea58(param_1);
  EngReleaseSemaphore(DAT_c029b620);
  return;
}



/* c0261fe0 FUN_c0261fe0 */

/* Boundary evidence: original MIPS .pdata c0261fe0..c026212b. Semantic name remains unreviewed. */

int FUN_c0261fe0(undefined4 param_1,int param_2,uint param_3,uint param_4,undefined4 *param_5,
                int param_6,int *param_7)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = EngMapFontFileFD(*(undefined4 *)(*(int *)(iVar1 + 0x24) + 0x1c),iVar1 + 0x10,
                             iVar1 + 0x14);
  }
  if (iVar1 != 0) {
    EngAcquireSemaphore(DAT_c029b620);
    iVar2 = FUN_c0271824(param_2,param_3,param_4,param_5,param_6,param_7);
    EngReleaseSemaphore(DAT_c029b620);
    EngUnmapFontFileFD(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x24) + 0x1c));
  }
  return iVar2;
}



/* c026212c FUN_c026212c */

/* Boundary evidence: original MIPS .pdata c026212c..c0262137. Semantic name remains unreviewed. */

undefined4 FUN_c026212c(void)

{
  return 1;
}



/* c0262138 FUN_c0262138 */

/* Boundary evidence: original MIPS .pdata c0262138..c026227b. Semantic name remains unreviewed. */

undefined4
FUN_c0262138(undefined4 param_1,int param_2,uint param_3,uint *param_4,ushort *param_5,uint param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = EngMapFontFileFD(*(undefined4 *)(*(int *)(iVar1 + 0x24) + 0x1c),iVar1 + 0x10,
                             iVar1 + 0x14);
  }
  if (iVar1 != 0) {
    EngAcquireSemaphore(DAT_c029b620);
    uVar2 = FUN_c026486c(param_2,param_3,param_4,param_5,param_6);
    EngReleaseSemaphore(DAT_c029b620);
    EngUnmapFontFileFD(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x24) + 0x1c));
  }
  return uVar2;
}



/* c026227c FUN_c026227c */

/* Boundary evidence: original MIPS .pdata c026227c..c0262287. Semantic name remains unreviewed. */

undefined4 FUN_c026227c(void)

{
  return 1;
}



/* c0262288 FntDrvQueryTrueTypeTable */

/* Boundary evidence: original MIPS .pdata c0262288..c02623d7. Semantic name remains unreviewed. */

undefined4
FntDrvQueryTrueTypeTable
          (int param_1,int param_2,int param_3,int param_4,uint param_5,void *param_6,int *param_7,
          size_t *param_8)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x2288  6  FntDrvQueryTrueTypeTable */
  uVar2 = 0xffffffff;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = EngMapFontFileFD(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x1c),param_1 + 0x10,
                             param_1 + 0x14);
  }
  if (iVar1 != 0) {
    EngAcquireSemaphore(DAT_c029b620);
    uVar2 = FUN_c02639a0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    EngReleaseSemaphore(DAT_c029b620);
    EngUnmapFontFileFD(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x1c));
  }
  return uVar2;
}



/* c02623d8 FUN_c02623d8 */

/* Boundary evidence: original MIPS .pdata c02623d8..c02623e3. Semantic name remains unreviewed. */

undefined4 FUN_c02623d8(void)

{
  return 1;
}



/* c02623e4 FUN_c02623e4 */

/* Boundary evidence: original MIPS .pdata c02623e4..c02625cf. Semantic name remains unreviewed. */

int * FUN_c02623e4(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *_Dst;
  ushort *puVar6;
  undefined2 *puVar7;
  int *piVar8;
  
  piVar3 = (int *)0x0;
  iVar1 = EngComputeGlyphSet(0,0,0x100);
  if (iVar1 != 0) {
    iVar4 = *(int *)(iVar1 + 0xc);
    iVar5 = (iVar4 + 0xf3) * 8;
    piVar3 = (int *)EngAllocMem(0,iVar5,0x64667454);
    if (piVar3 != (int *)0x0) {
      piVar3[2] = 0x1e0;
      piVar3[1] = 4;
      *piVar3 = iVar5;
      piVar3[3] = iVar4 + 1;
      _Dst = piVar3 + (iVar4 + 3) * 2;
      iVar5 = 0;
      if (0 < iVar4) {
        piVar8 = piVar3 + 5;
        puVar6 = (ushort *)(iVar1 + 0x10);
        do {
          if (0xefff < *puVar6) break;
          *(ushort *)(((int)piVar3 - iVar1) + (int)puVar6) = *puVar6;
          *(ushort *)((int)piVar8 + -2) = puVar6[1];
          *piVar8 = (int)_Dst;
          memcpy(_Dst,*(void **)(puVar6 + 2),(uint)puVar6[1] << 2);
          iVar5 = iVar5 + 1;
          _Dst = _Dst + puVar6[1];
          puVar6 = puVar6 + 4;
          piVar8 = piVar8 + 2;
        } while (iVar5 < iVar4);
      }
      *(undefined2 *)(piVar3 + (iVar5 + 2) * 2) = 0xf020;
      *(undefined2 *)((int)piVar3 + iVar5 * 8 + 0x12) = 0xe0;
      piVar3[iVar5 * 2 + 5] = (int)_Dst;
      iVar2 = 0x20;
      do {
        *_Dst = iVar2;
        iVar2 = iVar2 + 1;
        _Dst = _Dst + 1;
      } while (iVar2 < 0x100);
      if (iVar5 < iVar4) {
        piVar8 = piVar3 + (iVar5 + 3) * 2;
        puVar7 = (undefined2 *)((iVar5 + 2) * 8 + iVar1);
        iVar4 = iVar4 - iVar5;
        do {
          *(undefined2 *)piVar8 = *puVar7;
          *(undefined2 *)((int)piVar8 + 2) = puVar7[1];
          piVar8[1] = (int)_Dst;
          memcpy(_Dst,*(void **)(puVar7 + 2),(uint)(ushort)puVar7[1] << 2);
          _Dst = _Dst + (ushort)puVar7[1];
          puVar7 = puVar7 + 4;
          iVar4 = iVar4 + -1;
          piVar8 = piVar8 + 2;
        } while (iVar4 != 0);
      }
    }
    EngFreeMem(iVar1);
  }
  return piVar3;
}



/* c02625d0 FUN_c02625d0 */

/* Boundary evidence: original MIPS .pdata c02625d0..c0262697. Semantic name remains unreviewed. */

int FUN_c02625d0(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = EngMapFontFileFD(*(undefined4 *)(*(int *)(param_2 + 0x24) + 0x1c),param_2 + 0x10,
                             param_2 + 0x14);
  }
  if (iVar1 != 0) {
    EngAcquireSemaphore(DAT_c029b620);
    iVar2 = FUN_c0263130(param_1,param_2,param_3,param_4,param_5);
    EngReleaseSemaphore(DAT_c029b620);
    EngUnmapFontFileFD(*(undefined4 *)(*(int *)(param_2 + 0x24) + 0x1c));
  }
  return iVar2;
}



/* c0262698 FUN_c0262698 */

/* Boundary evidence: original MIPS .pdata c0262698..c02626e3. Semantic name remains unreviewed. */

void FUN_c0262698(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_c0272b94(param_1,param_2);
  if (iVar1 != 0) {
    FUN_c0272b78(param_1,param_2);
  }
  return;
}



/* c02626e4 FUN_c02626e4 */

void FUN_c02626e4(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  uVar1 = *param_2;
  *param_1 = uVar2 + uVar1;
  param_1[1] = param_2[1] + param_1[1] + (uint)(uVar2 + uVar1 < *param_2);
  uVar2 = param_1[2];
  uVar1 = param_2[2];
  param_1[2] = uVar2 + uVar1;
  param_1[3] = param_2[3] + (uint)(uVar2 + uVar1 < param_2[2]) + param_1[3];
  return;
}



/* c026275c FUN_c026275c */

/* Boundary evidence: original MIPS .pdata c026275c..c026282b. Semantic name remains unreviewed. */

void FUN_c026275c(uint param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = UseSurrogateFonts();
  if ((((iVar1 == 0) || (param_1 >> 0x10 < 0xd800)) || (0xdbff < param_1 >> 0x10)) ||
     (((param_1 & 0xffff) < 0xdc00 || (0xdfff < (param_1 & 0xffff))))) {
    if (param_1 >> 0x10 == 0xffff) {
      *(undefined2 *)(param_2 + 0x38) = 0xffff;
      *(short *)(param_2 + 0x3a) = (short)param_1;
    }
    else {
      *(short *)(param_2 + 0x38) =
           (short)*(undefined4 *)(*(int *)(param_3 + 4) + 0x10c) + (short)param_1;
      *(undefined2 *)(param_2 + 0x3a) = 0;
    }
  }
  else {
    *(undefined2 *)(param_2 + 0x38) = 0xffff;
  }
  *(undefined4 *)(param_2 + 0x3c) = 0;
  *(undefined4 *)(param_2 + 0x40) = 0;
  return;
}



/* c026282c FUN_c026282c */

/* Boundary evidence: original MIPS .pdata c026282c..c026287f. Semantic name remains unreviewed. */

uint FUN_c026282c(uint param_1,void *param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  if (1 < param_1) {
    param_1 = 2;
  }
  local_10 = 2;
  local_c = 3;
  memcpy(param_2,&local_10,param_1 << 2);
  return param_1;
}



/* c0262880 FntDrvQueryFont */

int FntDrvQueryFont(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x2880  3  FntDrvQueryFont */
  iVar3 = *(int *)((param_3 + 2) * 0xc + param_2);
  iVar2 = *(int *)(param_3 * 0xc + param_2 + 0x14);
  *param_4 = 0;
  iVar1 = iVar3 + 0x128;
  if (iVar2 != 1) {
    iVar1 = *(int *)(iVar3 + 8);
  }
  return iVar1;
}



/* c02628cc FUN_c02628cc */

/* Boundary evidence: original MIPS .pdata c02628cc..c0262c07. Semantic name remains unreviewed. */

undefined4 FUN_c02628cc(int param_1,ushort *param_2,uint param_3,int param_4)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint *puVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  ushort *puVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  byte local_18 [8];
  
  iVar13 = *(int *)(param_1 + 0xfc) + *(int *)(param_1 + 0x20);
  if (*(short *)(param_1 + 0x102) == 0x100) {
    for (pbVar6 = (byte *)(iVar13 + 0x105); (byte *)(iVar13 + 6) <= pbVar6; pbVar6 = pbVar6 + -1) {
      if ((uint)*pbVar6 == (param_3 & 0xff)) {
        local_18[0] = (char)pbVar6 - (char)(byte *)(iVar13 + 6);
        FUN_c02743d0((uint)*(ushort *)(param_1 + 0x106),param_2,local_18,1);
        return 1;
      }
    }
  }
  else if ((*(short *)(param_1 + 0x102) == 0x300) &&
          ((*(int *)(param_1 + 0x108) == 6 || (*(int *)(param_1 + 0x108) == 5)))) {
    if (param_4 == 0) {
      iVar13 = *(int *)(param_1 + 0x2c);
    }
    else {
      iVar13 = *(int *)(param_1 + 0x30);
    }
    uVar9 = 0;
    if (*(uint *)(iVar13 + 0xc) != 0) {
      puVar8 = (undefined4 *)(iVar13 + 0x14);
      do {
        puVar5 = (uint *)*puVar8;
        uVar11 = 0;
        if (*(ushort *)((int)puVar8 + -2) != 0) {
          do {
            if (*puVar5 == param_3) {
              *param_2 = *(short *)((uVar9 + 2) * 8 + iVar13) + (short)uVar11;
              return 1;
            }
            uVar11 = uVar11 + 1;
            puVar5 = puVar5 + 1;
          } while (uVar11 < *(ushort *)((int)puVar8 + -2));
        }
        uVar9 = uVar9 + 1;
        puVar8 = puVar8 + 2;
      } while (uVar9 < *(uint *)(iVar13 + 0xc));
    }
  }
  else {
    iVar7 = ((int)((uint)*(byte *)(iVar13 + 6) << 8) >> 1 | (uint)(*(byte *)(iVar13 + 7) >> 1)) * 2;
    puVar15 = (undefined1 *)(iVar13 + 0xe);
    puVar14 = puVar15 + iVar7 + -2;
    puVar4 = puVar14 + iVar7 + 2;
    puVar3 = puVar4 + iVar7;
    puVar2 = puVar3 + iVar7;
    if (CONCAT11(*puVar14,puVar15[iVar7 + -1]) != -1) {
      iVar7 = 0;
      for (; (puVar15 <= puVar14 && (CONCAT11(*puVar14,puVar14[1]) != -1)); puVar14 = puVar14 + -2)
      {
        iVar7 = iVar7 + 1;
      }
      puVar4 = puVar4 + iVar7 * -2;
      puVar3 = puVar3 + iVar7 * -2;
      puVar2 = puVar2 + iVar7 * -2;
    }
    for (; puVar15 <= puVar14; puVar14 = puVar14 + -2) {
      uVar1 = CONCAT11(*puVar4,puVar4[1]);
      uVar9 = param_3 - CONCAT11(*puVar3,puVar3[1]);
      uVar11 = uVar9 & 0xffff;
      if (CONCAT11(*puVar2,puVar2[1]) == 0) {
        if ((uVar1 <= uVar11) && (uVar11 <= CONCAT11(*puVar14,puVar14[1]))) {
          *param_2 = (ushort)uVar9;
          return 1;
        }
      }
      else {
        puVar12 = (ushort *)(puVar2 + (uint)(ushort)(CONCAT11(*puVar2,puVar2[1]) >> 1) * 2);
        if (puVar12 <=
            (ushort *)
            ((uint)CONCAT11(*(undefined1 *)(iVar13 + 2),*(undefined1 *)(iVar13 + 3)) + iVar13)) {
          for (puVar10 = puVar12 + ((uint)CONCAT11(*puVar14,puVar14[1]) - (uint)uVar1);
              puVar12 <= puVar10; puVar10 = puVar10 + -1) {
            if (((uVar9 & 0xff) << 8 | uVar11 >> 8) == (uint)*puVar10) {
              *param_2 = (short)((int)puVar10 - (int)puVar12 >> 1) + uVar1;
              return 1;
            }
          }
        }
      }
      puVar4 = puVar4 + -2;
      puVar3 = puVar3 + -2;
      puVar2 = puVar2 + -2;
    }
  }
  return 0;
}



/* c0262c08 FUN_c0262c08 */

/* Boundary evidence: original MIPS .pdata c0262c08..c0262ca3. Semantic name remains unreviewed. */

void FUN_c0262c08(int param_1,ushort *param_2,uint param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_c02628cc(param_1,param_2,param_3,param_4);
  if ((iVar1 != 0) && ((*(uint *)(param_1 + 0xf8) & 0x30) != 0)) {
    if ((*param_2 == 0xa0) && ((*(uint *)(param_1 + 0xf8) & 0x10) != 0)) {
      *param_2 = 0x20;
    }
    if ((*param_2 == 0xad) && ((*(uint *)(param_1 + 0xf8) & 0x20) != 0)) {
      *param_2 = 0x2d;
    }
  }
  return;
}



/* c0262ca4 FUN_c0262ca4 */

/* Boundary evidence: original MIPS .pdata c0262ca4..c0262e3b. Semantic name remains unreviewed. */

uint FUN_c0262ca4(int param_1,uint param_2,ushort *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  
  if (*(int *)(param_1 + 0x94) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x94);
  }
  if (iVar1 != 0) {
    uVar2 = (uint)CONCAT11(*(undefined1 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 3));
    iVar1 = iVar1 + 4;
    if (uVar2 != 0) {
      do {
        if (*(char *)(iVar1 + 4) == '\0') break;
        uVar2 = uVar2 - 1;
        iVar1 = (uint)CONCAT11(*(undefined1 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 3)) + iVar1;
      } while (uVar2 != 0);
      if (uVar2 != 0) {
        uVar2 = (uint)CONCAT11(*(undefined1 *)(iVar1 + 6),*(undefined1 *)(iVar1 + 7));
        if (param_3 == (ushort *)0x0) {
          if (param_2 == 0) {
            return uVar2;
          }
        }
        else {
          if (param_2 <= uVar2) {
            uVar2 = param_2;
          }
          puVar4 = param_3 + uVar2 * 3;
          puVar3 = (undefined1 *)(iVar1 + 0xe);
          while( true ) {
            if (puVar4 <= param_3) {
              return uVar2;
            }
            iVar1 = FUN_c0262c08(param_1,param_3,(uint)CONCAT11(*puVar3,puVar3[1]),param_4);
            if ((iVar1 == 0) ||
               (iVar1 = FUN_c0262c08(param_1,param_3 + 1,(uint)CONCAT11(puVar3[2],puVar3[3]),param_4
                                    ), iVar1 == 0)) break;
            param_3[2] = CONCAT11(puVar3[4],puVar3[5]);
            param_3 = param_3 + 3;
            puVar3 = puVar3 + 6;
          }
        }
        return 0xffffffff;
      }
    }
  }
  return 0;
}



/* c0262e3c FUN_c0262e3c */

/* Boundary evidence: original MIPS .pdata c0262e3c..c026312f. Semantic name remains unreviewed. */

int FUN_c0262e3c(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  short local_590;
  short local_58e [3];
  undefined1 auStack_588 [4];
  undefined1 *local_584;
  undefined4 local_580;
  undefined4 local_57c;
  int local_560;
  undefined1 *local_55c;
  code *local_558;
  int *local_554;
  undefined2 local_550;
  undefined2 local_54e;
  int aiStack_518 [50];
  undefined1 auStack_450 [1072];
  
  *param_2 = 0;
  if (param_1[10] == 0) {
    if (param_1[6] == 0) {
      param_1[8] = *(int *)(*param_1 + 0x10);
      param_1[9] = *(int *)(*param_1 + 0x14);
    }
    uVar1 = FUN_c0262ca4((int)param_1,0,(ushort *)0x0,param_3);
    if (uVar1 != 0xffffffff) {
      if (((uVar1 != 0) && (*(short *)((int)param_1 + 0x102) == 0x300)) &&
         ((short)param_1[0x41] == 0x100)) {
        puVar5 = (undefined1 *)param_1[3];
        if (param_1[6] == 0) {
          iVar2 = FUN_c0271bc0((int)auStack_588,aiStack_518);
          if (iVar2 == 0) {
            local_584 = auStack_450;
            local_580 = 0;
            local_57c = 0;
            iVar2 = FUN_c0271c34((int)auStack_588,aiStack_518);
            if (iVar2 == 0) {
              local_560 = param_1[8];
              local_55c = &LAB_c0266ff0;
              local_558 = FUN_c02619ec;
              local_550 = CONCAT11(*(undefined1 *)((int)param_1 + 0x102),
                                   *(undefined1 *)((int)param_1 + 0x103));
              local_54e = CONCAT11((char)param_1[0x41],*(undefined1 *)((int)param_1 + 0x105));
              local_554 = param_1;
              iVar2 = FUN_c0271cc4((int)auStack_588,(int)aiStack_518);
              if (iVar2 == 0) {
                puVar5 = auStack_588;
                goto LAB_c0262f98;
              }
            }
          }
          goto LAB_c0262ec0;
        }
LAB_c0262f98:
        iVar2 = FUN_c0274268((int)puVar5,1,0x20,(short *)0x0,&local_590);
        if (iVar2 == 0) {
          iVar2 = FUN_c0274268((int)puVar5,1,0xa0,(short *)0x0,local_58e);
          if ((iVar2 == 0) && ((local_590 != 0 || (local_58e[0] != 0)))) {
            param_1[0x3e] = param_1[0x3e] | 0x10;
          }
        }
        iVar2 = FUN_c0274268((int)puVar5,1,0x2d,(short *)0x0,&local_590);
        if (iVar2 == 0) {
          iVar2 = FUN_c0274268((int)puVar5,1,0xad,(short *)0x0,local_58e);
          if ((iVar2 == 0) && ((local_590 != 0 || (local_58e[0] != 0)))) {
            param_1[0x3e] = param_1[0x3e] | 0x20;
          }
        }
      }
      puVar3 = (undefined4 *)EngAllocMem(0,uVar1 * 6 + 0xe,0x64667454);
      if (puVar3 != (undefined4 *)0x0) {
        param_1[10] = (int)(puVar3 + 2);
        puVar3[1] = param_1;
        *puVar3 = 0;
        *param_2 = (int)puVar3;
        uVar1 = FUN_c0262ca4((int)param_1,uVar1,(ushort *)param_1[10],param_3);
        if (uVar1 != 0xffffffff) {
          puVar4 = (undefined2 *)(uVar1 * 6 + param_1[10]);
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
          goto LAB_c0263104;
        }
        EngFreeMem(puVar3);
        param_1[10] = 0;
      }
    }
LAB_c0262ec0:
    iVar2 = 0;
  }
  else {
    *param_2 = param_1[10] + -8;
LAB_c0263104:
    iVar2 = param_1[10];
  }
  return iVar2;
}



/* c0263130 FUN_c0263130 */

/* Boundary evidence: original MIPS .pdata c0263130..c02632df. Semantic name remains unreviewed. */

int FUN_c0263130(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = *(int **)((param_3 + 2) * 0xc + param_2);
  iVar4 = *(int *)(param_3 * 0xc + param_2 + 0x14);
  if (param_4 == 1) {
    *param_5 = 0;
  }
  else if (param_4 == 2) {
    iVar2 = 0;
    iVar1 = FUN_c026b49c(piVar3,iVar4);
    if (iVar1 != 0) {
      if ((*(uint *)(param_2 + 4) & 1) == 0) {
        iVar2 = FUN_c0262e3c(piVar3,param_5,(uint)(iVar4 != 1));
      }
      FUN_c0268d2c((int)piVar3,iVar4);
      return iVar2;
    }
  }
  else if (param_4 == 3) {
    *param_5 = 0;
    iVar1 = FUN_c026b49c(piVar3,iVar4);
    if (iVar1 != 0) {
      if (iVar4 == 1) {
        return piVar3[0xb];
      }
      return piVar3[0xc];
    }
  }
  return 0;
}



/* c02632e0 FUN_c02632e0 */

/* Boundary evidence: original MIPS .pdata c02632e0..c02632eb. Semantic name remains unreviewed. */

undefined4 FUN_c02632e0(void)

{
  return 1;
}



/* c02632ec FUN_c02632ec */

/* Boundary evidence: original MIPS .pdata c02632ec..c026344b. Semantic name remains unreviewed. */

undefined4 FUN_c02632ec(int param_1,uint param_2,uint *param_3,uint param_4,int *param_5)

{
  int iVar1;
  
  FUN_c02619f4((undefined4 *)(param_1 + 8));
  FUN_c026275c(param_2,*(int *)(param_1 + 0x98),param_1);
  iVar1 = FUN_c0272434(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
  *param_5 = iVar1;
  if (iVar1 == 0) {
    *param_3 = (uint)*(ushort *)(*(int *)(param_1 + 0x9c) + 0x24);
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x38) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x3c) = 0;
    if ((((*(uint *)(param_1 + 0x18) & 0x10000) == 0) &&
        (*(short *)(*(int *)(param_1 + 0x9c) + 0x88) != 0)) && ((param_4 & 1) != 0)) {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x40) = 1;
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x40) = 0;
    }
    if ((((param_4 & 1) != 0) && ((*(uint *)(param_1 + 0x18) & 0x10000) != 0)) &&
       (((*(uint *)(param_1 + 0x68) & 1) != 0 &&
        (((*(uint *)(param_1 + 0x68) & 2) != 0 && (*(int *)(*(int *)(param_1 + 0x98) + 0x68) == 1)))
        ))) {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x40) = 1;
    }
    if ((param_4 & 2) == 0) {
      iVar1 = FUN_c0262698(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
    }
    else {
      iVar1 = FUN_c0272b78(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
    }
    *param_5 = iVar1;
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c026344c FUN_c026344c */

/* Boundary evidence: original MIPS .pdata c026344c..c0263483. Semantic name remains unreviewed. */

void FUN_c026344c(uint param_1,uint param_2)

{
  uint local_10;
  int local_c;
  
  FUN_c02746b4(param_1,(int *)&local_10);
  FUN_c0274bb8(local_10,local_c,param_2);
  return;
}



/* c0263484 FUN_c0263484 */

/* Boundary evidence: original MIPS .pdata c0263484..c02636af. Semantic name remains unreviewed. */

undefined4 FUN_c0263484(int param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint local_50;
  int local_4c;
  int local_40 [5];
  int local_2c;
  
  uVar9 = *(uint *)(param_2 + 0xc);
  uVar10 = 1;
  FUN_c02746b4(*(uint *)(param_1 + 0xbc),(int *)&local_50);
  iVar1 = FUN_c0274bb8(local_50,local_4c,uVar9);
  uVar9 = *(uint *)(param_2 + 0xc);
  FUN_c02746b4(*(uint *)(param_1 + 0xc0),(int *)&local_50);
  iVar2 = FUN_c0274bb8(local_50,local_4c,uVar9);
  uVar9 = *(uint *)(param_2 + 0x10);
  FUN_c02746b4(*(uint *)(param_1 + 0xbc),(int *)&local_50);
  iVar3 = FUN_c0274bb8(local_50,local_4c,uVar9);
  uVar9 = *(uint *)(param_2 + 0x10);
  FUN_c02746b4(*(uint *)(param_1 + 0xc0),(int *)&local_50);
  iVar4 = FUN_c0274bb8(local_50,local_4c,uVar9);
  iVar7 = *(int *)(param_1 + 0x110) + iVar1;
  iVar8 = *(int *)(param_1 + 0x114) + iVar2;
  local_40[0] = *(int *)(param_1 + 0x110) + iVar3;
  local_40[1] = *(int *)(param_1 + 0x114) + iVar4;
  piVar5 = local_40;
  iVar6 = 3;
  local_40[2] = *(int *)(param_1 + 0x118) + iVar3;
  local_40[3] = *(int *)(param_1 + 0x11c) + iVar4;
  local_40[4] = *(int *)(param_1 + 0x118) + iVar1;
  local_2c = *(int *)(param_1 + 0x11c) + iVar2;
  iVar1 = iVar7;
  iVar2 = iVar8;
  do {
    iVar3 = *piVar5;
    if (iVar3 < iVar1) {
      iVar1 = iVar3;
    }
    if (iVar7 < iVar3) {
      iVar7 = iVar3;
    }
    iVar3 = piVar5[1];
    if (iVar3 < iVar2) {
      iVar2 = iVar3;
    }
    if (iVar8 < iVar3) {
      iVar8 = iVar3;
    }
    iVar6 = iVar6 + -1;
    piVar5 = piVar5 + 2;
  } while (iVar6 != 0);
  iVar3 = (iVar1 >> 4) + -1;
  iVar1 = (iVar2 >> 4) + -1;
  if (*param_3 < iVar3) {
    *param_3 = iVar3;
  }
  if (param_3[1] < iVar1) {
    param_3[1] = iVar1;
  }
  if (((iVar7 + 0xf >> 4) + 1 < *param_3 + param_4) ||
     ((iVar8 + 0xf >> 4) + 1 < param_3[1] + param_5)) {
    uVar10 = 0;
  }
  return uVar10;
}



/* c02636b0 FUN_c02636b0 */

/* Boundary evidence: original MIPS .pdata c02636b0..c026373b. Semantic name remains unreviewed. */

undefined4 FUN_c02636b0(int param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint local_18 [2];
  
  iVar1 = FUN_c02632ec(param_1,param_2,local_18,param_3,param_4);
  if (iVar1 != 0) {
    iVar1 = FUN_c0272bb0(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
    if (iVar1 == 0) {
      *(uint *)(param_1 + 8) = param_2;
      *(uint *)(param_1 + 0xc) = local_18[0];
      return 1;
    }
    *param_4 = iVar1;
  }
  return 0;
}



/* c026373c FUN_c026373c */

/* Boundary evidence: original MIPS .pdata c026373c..c0263883. Semantic name remains unreviewed. */

void FUN_c026373c(int param_1,uint param_2,int param_3,int *param_4,int *param_5)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  
  uVar4 = (uint)*(ushort *)(*(int *)(param_1 + 4) + 0xe4);
  if ((uVar4 == 0) ||
     (bVar3 = FUN_c0269f14(*(uint *)(*(int *)(param_1 + 0xa0) + 0x8c),param_2,uVar4),
     CONCAT31(extraout_var,bVar3) == 0)) {
    iVar5 = (int)*(short *)(*(int *)(param_1 + 4) + 0x164);
    iVar7 = (param_3 + iVar5) * 0x10000 >> 0x10;
    iVar5 = (*(short *)(*(int *)(param_1 + 4) + 0x166) + iVar5) * 0x10000 >> 0x10;
    if (iVar7 < 0) {
      iVar7 = 0;
    }
  }
  else {
    iVar5 = *(int *)(*(int *)(param_1 + 4) + 0xc4) + *(int *)(*(int *)(param_1 + 4) + 0x20);
    if (param_2 < uVar4) {
      puVar6 = (undefined1 *)(param_2 * 4 + iVar5);
      sVar1 = CONCAT11(*puVar6,puVar6[1]);
      sVar2 = CONCAT11(puVar6[2],puVar6[3]);
    }
    else {
      iVar5 = uVar4 * 4 + iVar5;
      puVar6 = (undefined1 *)((param_2 - uVar4) * 2 + iVar5);
      sVar1 = CONCAT11(*(undefined1 *)(iVar5 + -4),*(undefined1 *)(iVar5 + -3));
      sVar2 = CONCAT11(*puVar6,puVar6[1]);
    }
    iVar5 = (int)sVar1;
    iVar7 = (int)sVar2;
  }
  *param_4 = iVar5;
  *param_5 = iVar7;
  return;
}



/* c0263884 FUN_c0263884 */

/* Boundary evidence: original MIPS .pdata c0263884..c026399f. Semantic name remains unreviewed. */

size_t FUN_c0263884(int param_1,int param_2,int param_3,int param_4,uint param_5,void *param_6,
                   int *param_7,size_t *param_8)

{
  int iVar1;
  int iVar2;
  uint _Size;
  size_t local_10 [2];
  
  if ((-1 < param_4) && ((*(uint *)(param_1 + 4) & 1) == 0)) {
    iVar2 = *(int *)((param_2 + 2) * 0xc + param_1);
    if (param_3 == 0x66637474) {
      if (*(int *)(iVar2 + 0xdc) == 0) {
        return 0xffffffff;
      }
      iVar1 = *(int *)(iVar2 + 0x20);
      local_10[0] = *(size_t *)(iVar2 + 0x24);
    }
    else if (param_3 == 0) {
      iVar1 = *(int *)(iVar2 + 0x20) + *(int *)(iVar2 + 0xdc);
      local_10[0] = *(int *)(iVar2 + 0x24) - *(int *)(iVar2 + 0xdc);
    }
    else {
      iVar1 = FUN_c0267064(param_3,iVar2,(int *)local_10);
      if (iVar1 == 0) {
        return 0xffffffff;
      }
    }
    if (param_7 != (int *)0x0) {
      *param_7 = iVar1;
    }
    if (param_8 != (size_t *)0x0) {
      *param_8 = local_10[0];
    }
    _Size = local_10[0] - param_4;
    if (0 < (int)_Size) {
      if (param_6 == (void *)0x0) {
        return _Size;
      }
      if (param_5 != 0) {
        if (param_5 < _Size) {
          _Size = param_5;
        }
        local_10[0] = _Size;
        memcpy(param_6,(void *)(iVar1 + param_4),_Size);
        return _Size;
      }
      return _Size;
    }
  }
  return 0xffffffff;
}



/* c02639a0 FUN_c02639a0 */

/* Boundary evidence: original MIPS .pdata c02639a0..c0263a0b. Semantic name remains unreviewed. */

void FUN_c02639a0(int param_1,int param_2,int param_3,int param_4,uint param_5,void *param_6,
                 int *param_7,size_t *param_8)

{
  int iVar1;
  
  iVar1 = *(int *)((param_2 + 2) * 0xc + param_1);
  if (*(int *)(iVar1 + 0x18) == 0) {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
  }
  FUN_c0263884(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c0263a30 FUN_c0263a30 */

/* Boundary evidence: original MIPS .pdata c0263a30..c0263a93. Semantic name remains unreviewed. */

undefined4 FUN_c0263a30(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(uint *)(*(int *)(param_1 + 0x14) + 4) & 1) == 0) {
    iVar2 = *(int *)(param_1 + 0x28);
    if (iVar2 == 0) {
      iVar2 = FUN_c0270860(param_1);
      *(int *)(param_1 + 0x28) = iVar2;
      if (iVar2 == 0) goto LAB_c0263a54;
    }
    uVar1 = *(undefined4 *)(**(int **)(iVar2 + 4) + 0x18);
  }
  else {
LAB_c0263a54:
    uVar1 = 0;
  }
  return uVar1;
}



/* c0263a94 FntDrvQueryFontFile */

/* Boundary evidence: original MIPS .pdata c0263a94..c0263beb. Semantic name remains unreviewed. */

int FntDrvQueryFontFile(int param_1,int param_2,uint param_3,STRSAFE_LPWSTR param_4)

{
  HRESULT HVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  size_t cchDest;
  uint uVar5;
  uint uVar6;
  
                    /* 0x3a94  5  FntDrvQueryFontFile */
  if (param_2 == 1) {
    iVar3 = 0;
    cchDest = param_3 >> 1;
    uVar5 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      puVar4 = (uint *)(param_1 + 0x20);
      do {
        if ((*puVar4 & 1) != 0) {
          uVar2 = puVar4[1];
          uVar6 = (uint)(*(int *)(uVar2 + 0x134) - *(int *)(uVar2 + 0x138)) >> 1;
          if (uVar5 != 0) {
            if (param_4 != (STRSAFE_LPWSTR)0x0) {
              HVar1 = StringCchCopyW(param_4,cchDest,L" & ");
              if (HVar1 < 0) {
                return iVar3;
              }
              param_4 = param_4 + 3;
              cchDest = cchDest - 3;
            }
            iVar3 = iVar3 + 6;
          }
          if (param_4 != (STRSAFE_LPWSTR)0x0) {
            HVar1 = StringCchCopyW(param_4,cchDest,
                                   (STRSAFE_LPCWSTR)(*(int *)(uVar2 + 0x138) + uVar2 + 0x128));
            if (HVar1 < 0) {
              return iVar3;
            }
            param_4 = param_4 + (uVar6 - 2);
            cchDest = (cchDest - uVar6) + 2;
          }
          iVar3 = uVar6 * 2 + iVar3;
        }
        uVar5 = uVar5 + 1;
        puVar4 = puVar4 + 3;
      } while (uVar5 < *(uint *)(param_1 + 0xc));
    }
  }
  else if (param_2 == 2) {
    iVar3 = *(int *)(param_1 + 0xc);
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}



/* c0263bec FUN_c0263bec */

/* Boundary evidence: original MIPS .pdata c0263bec..c0263e2b. Semantic name remains unreviewed. */

void FUN_c0263bec(int param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  byte *_Dst;
  byte *pbVar9;
  void *_Src;
  uint uVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  
  bVar1 = (&DAT_c026103c)[param_4[4] & 7];
  iVar6 = 8;
  if ((*(uint *)(param_1 + 0x18) & 0x10000) == 0) {
    iVar6 = 1;
  }
  iVar4 = param_4[2];
  iVar5 = param_4[3];
  iVar7 = param_4[4];
  *(int *)(param_2 + 8) = iVar7;
  uVar10 = iVar7 + 7U >> 3;
  uVar12 = iVar7 + 7U >> 3;
  *(int *)(param_2 + 0xc) = param_4[5];
  iVar11 = uVar12 - 1;
  iVar6 = ((iVar5 + iVar4 + iVar7) * iVar6 + 0x1fU >> 5) * 4;
  if (*param_4 != 0) {
    param_3 = *param_4 * iVar6 + param_3;
  }
  iVar4 = param_4[5];
  _Dst = (byte *)(param_2 + 0x14);
  pbVar9 = _Dst + iVar4 * uVar10;
  if (param_5 < (uint)((int)pbVar9 - (int)_Dst)) {
    pbVar9 = _Dst + param_5;
  }
  if ((param_4[2] & 7U) == 0) {
    _Src = (void *)(((uint)param_4[2] >> 3) + param_3);
    for (; _Dst < pbVar9; _Dst = _Dst + uVar10) {
      memcpy(_Dst,_Src,uVar12);
      _Dst[iVar11] = _Dst[iVar11] & bVar1;
      _Src = (void *)(iVar6 + (int)_Src);
    }
  }
  else {
    uVar12 = param_4[2] & 7;
    pbVar13 = (byte *)(((uint)param_4[2] >> 3) + param_3);
    if (_Dst < pbVar9) {
      pbVar8 = _Dst + iVar11;
      pbVar3 = _Dst;
      pbVar14 = pbVar13;
      do {
        for (; pbVar3 < pbVar8; pbVar3 = pbVar3 + 1) {
          bVar2 = *pbVar13;
          pbVar13 = pbVar13 + 1;
          *pbVar3 = bVar2 << uVar12;
          *pbVar3 = *pbVar13 >> (8 - uVar12 & 0x1f) | *pbVar3;
        }
        *pbVar3 = *pbVar13 << uVar12;
        if (pbVar13 + 1 < (byte *)(iVar4 * iVar6 + param_3)) {
          *pbVar3 = pbVar13[1] >> (8 - uVar12 & 0x1f) | *pbVar3;
        }
        _Dst = _Dst + uVar10;
        *pbVar3 = *pbVar3 & bVar1;
        pbVar8 = pbVar8 + uVar10;
        pbVar13 = pbVar14 + iVar6;
        pbVar3 = _Dst;
        pbVar14 = pbVar13;
      } while (_Dst < pbVar9);
    }
  }
  return;
}



/* c0263e2c FUN_c0263e2c */

/* Boundary evidence: original MIPS .pdata c0263e2c..c0264047. Semantic name remains unreviewed. */

void FUN_c0263e2c(int param_1,uint param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  
  iVar5 = *(int *)(param_1 + 0xa0);
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x20);
  iVar4 = *(int *)(iVar5 + 0x18) + iVar6;
  iVar9 = *(int *)(iVar5 + 8) + iVar6;
  iVar2 = *(int *)(iVar5 + 0x20) + iVar6;
  iVar7 = *(int *)(iVar5 + 0x28) + iVar6;
  uVar3 = (uint)CONCAT11(*(undefined1 *)(iVar4 + 0x22),*(undefined1 *)(iVar4 + 0x23));
  sVar1 = *(short *)(*(int *)(iVar5 + 0x10) + iVar6 + 0x32);
  if (sVar1 == 0) {
    puVar8 = (undefined1 *)(param_2 * 2 + iVar7);
    iVar9 = (uint)CONCAT11(*puVar8,puVar8[1]) * 2 + iVar9;
  }
  else if (sVar1 == 0x100) {
    puVar8 = (undefined1 *)(param_2 * 4 + iVar7);
    iVar9 = CONCAT31(CONCAT21(CONCAT11(*puVar8,puVar8[1]),puVar8[2]),puVar8[3]) + iVar9;
  }
  *param_3 = CONCAT11(*(undefined1 *)(iVar9 + 2),*(undefined1 *)(iVar9 + 3));
  param_3[1] = CONCAT11(*(undefined1 *)(iVar9 + 6),*(undefined1 *)(iVar9 + 7));
  param_3[2] = -CONCAT11(*(undefined1 *)(iVar9 + 8),*(undefined1 *)(iVar9 + 9));
  param_3[3] = -CONCAT11(*(undefined1 *)(iVar9 + 4),*(undefined1 *)(iVar9 + 5));
  if (param_2 < uVar3) {
    puVar8 = (undefined1 *)(param_2 * 4 + iVar2);
    param_3[5] = CONCAT11(*puVar8,puVar8[1]);
    param_3[4] = CONCAT11(puVar8[2],puVar8[3]);
  }
  else {
    iVar2 = uVar3 * 4 + iVar2;
    puVar8 = (undefined1 *)((param_2 - uVar3) * 2 + iVar2);
    param_3[5] = CONCAT11(*(undefined1 *)(iVar2 + -4),*(undefined1 *)(iVar2 + -3));
    param_3[4] = CONCAT11(*puVar8,puVar8[1]);
  }
  param_3[1] = (param_3[4] - *param_3) + param_3[1];
  *param_3 = param_3[4];
  if ((*(uint *)(param_1 + 0x18) & 0x4000) != 0) {
    iVar2 = FUN_c0274f80((int)param_3[3],0x5700);
    param_3[4] = param_3[4] - (short)iVar2;
    iVar2 = FUN_c0274f80((int)param_3[2],0x5700);
    param_3[1] = param_3[1] - (short)iVar2;
  }
  return;
}



/* c0264048 FUN_c0264048 */

/* Boundary evidence: original MIPS .pdata c0264048..c026470f. Semantic name remains unreviewed. */

undefined4 FUN_c0264048(int param_1,undefined4 param_2,undefined4 *param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  byte bVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  uint local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x20);
  if (*(int *)(*(int *)(param_1 + 4) + 0x7c) == 0) {
    iVar12 = 0;
  }
  else {
    iVar12 = *(int *)(*(int *)(param_1 + 4) + 0x7c) + iVar8;
  }
  iVar14 = *(int *)(param_1 + 0x40);
  if (iVar14 < 0) {
    iVar14 = -iVar14;
  }
  iVar8 = *(int *)(*(int *)(param_1 + 0xa0) + 0x10) + iVar8;
  param_3[1] = *(undefined4 *)(param_1 + 0xbc);
  param_3[2] = *(undefined4 *)(param_1 + 0xc0);
  param_3[3] = *(undefined4 *)(param_1 + 0xf0);
  param_3[4] = *(undefined4 *)(param_1 + 0xf4);
  param_3[0x10] = *(undefined4 *)(param_1 + 0x90);
  param_3[6] = *(int *)(param_1 + 0x78) << 4;
  param_3[7] = *(int *)(param_1 + 0x7c) << 4;
  iVar10 = *(int *)(param_1 + 4);
  sVar1 = *(short *)(iVar10 + 400);
  sVar2 = *(short *)(iVar10 + 0x18c);
  sVar3 = *(short *)(iVar10 + 0x192);
  sVar4 = *(short *)(iVar10 + 0x18e);
  *param_3 = 0;
  param_3[5] = 0;
  if ((*(uint *)(param_1 + 100) & 0x40) == 0) {
    param_3[0x1b] = (int)*(short *)(*(int *)(param_1 + 4) + 0x114);
    param_3[0x1c] = (int)*(short *)(*(int *)(param_1 + 4) + 0x116);
  }
  else {
    param_3[0x1b] = 0;
    param_3[0x1c] = 0;
  }
  if ((*(uint *)(param_1 + 0x18) & 0x4000) != 0) {
    if ((iVar12 == 0) || ((*(uint *)(param_1 + 100) & 3) == 0)) {
      uVar11 = (int)((uint)*(byte *)(iVar8 + 0x2a) << 0x18) >> 0x10 | (uint)*(byte *)(iVar8 + 0x2b);
      uVar5 = -((int)((uint)*(byte *)(iVar8 + 0x26) << 0x18) >> 0x10 | (uint)*(byte *)(iVar8 + 0x27)
               );
    }
    else {
      uVar11 = (int)((uint)*(byte *)(iVar12 + 0x4a) << 0x18) >> 0x10 |
               (uint)*(byte *)(iVar12 + 0x4b);
      uVar5 = (int)((uint)*(byte *)(iVar12 + 0x4c) << 0x18) >> 0x10 | (uint)*(byte *)(iVar12 + 0x4d)
      ;
    }
    iVar8 = FUN_c0274f80(uVar5,0x5700);
    param_3[0x1b] = param_3[0x1b] - iVar8;
    iVar8 = FUN_c0274f80(-uVar11,0x5700);
    param_3[0x1c] = iVar8 + param_3[0x1c];
  }
  param_3[0x1d] = (uint)*(ushort *)(*(int *)(param_1 + 4) + 0x110);
  if ((*(uint *)(param_1 + 100) & 1) == 0) {
    local_5c = -(int)sVar3;
    local_4c = -(int)sVar4;
    param_3[5] = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_64 = (int)sVar1;
    local_54 = (int)sVar2;
    FUN_c02762e4((uint *)(param_1 + 0x28),&local_48,&local_68,4);
    iVar8 = ((int)local_48 >> 3) + 1 >> 1;
    param_3[0xf] = (local_44 >> 3) + 1 >> 1;
    param_3[0xb] = (local_3c >> 3) + 1 >> 1;
    iVar12 = (local_38 >> 3) + 1 >> 1;
    param_3[0xd] = (local_34 >> 3) + 1 >> 1;
    param_3[10] = (local_40 >> 3) + 1 >> 1;
    param_3[0xe] = iVar8;
    param_3[0xc] = iVar12;
    param_3[8] = (local_30 >> 3) + 1 >> 1;
    param_3[9] = (local_2c >> 3) + 1 >> 1;
    if (((*(uint *)(param_1 + 100) & 2) != 0) && ((iVar8 == 0 || (iVar12 == 0)))) {
      iVar10 = *(int *)(param_1 + 0x4c);
      uVar9 = 0xffffffff;
      if (iVar8 == 0) {
        uVar6 = 0xffffffff;
        if (iVar10 < 1) {
          uVar6 = 1;
        }
        param_3[0xe] = uVar6;
      }
      if (iVar12 == 0) {
        if (iVar10 < 1) {
          uVar9 = 1;
        }
        param_3[0xc] = uVar9;
      }
    }
    puVar13 = (uint *)(param_1 + 0xc4);
    iVar8 = FUN_c0276570(puVar13,param_3[0x1b]);
    param_3[0x1b] = (iVar8 >> 3) + 1 >> 1;
    iVar8 = FUN_c0276570(puVar13,param_3[0x1c]);
    param_3[0x1c] = (iVar8 >> 3) + 1 >> 1;
    iVar8 = FUN_c0276570(puVar13,param_3[0x1d]);
    param_3[0x1d] = (iVar8 >> 3) + 1 >> 1;
  }
  else {
    iVar8 = *(int *)(param_1 + 0x50);
    iVar12 = (iVar8 * sVar2 >> 0xf) + 1 >> 1;
    if ((iVar12 == 0) && (iVar12 = 1, iVar8 < 1)) {
      iVar12 = -1;
    }
    param_3[0xc] = 0;
    iVar10 = (iVar8 * sVar1 >> 0xf) + 1 >> 1;
    param_3[0xd] = iVar12;
    if ((iVar10 == 0) && (iVar10 = 1, iVar8 < 1)) {
      iVar10 = -1;
    }
    param_3[0xf] = iVar10;
    param_3[0xe] = 0;
    param_3[8] = 0;
    param_3[10] = 0;
    param_3[0xb] = -((iVar8 * sVar3 >> 0xf) + 1 >> 1);
    param_3[9] = -((iVar8 * sVar4 >> 0xf) + 1 >> 1);
    param_3[0x1b] = (param_3[0x1b] * iVar14 >> 0xf) + 1 >> 1;
    param_3[0x1c] = (param_3[0x1c] * iVar14 >> 0xf) + 1 >> 1;
    param_3[0x1d] = (param_3[0x1d] * iVar14 >> 0xf) + 1 >> 1;
  }
  if ((*(uint *)(param_1 + 100) & 0x21) != 0) {
    uVar5 = FUN_c026f228(*(uint *)(param_1 + 0x40));
    param_3[0x13] = uVar5;
    uVar5 = FUN_c026f228(*(uint *)(param_1 + 0x50));
    param_3[0x16] = uVar5;
    if ((*(uint *)(param_1 + 100) & 1) == 0) {
      uVar5 = FUN_c026f228(-*(int *)(param_1 + 0x44));
      param_3[0x14] = uVar5;
      uVar5 = FUN_c026f228(-*(int *)(param_1 + 0x4c));
      param_3[0x15] = uVar5;
    }
  }
  if ((*(uint *)(*(int *)(param_1 + 4) + 0xf8) & 2) != 0) {
    iVar8 = (*(int *)(param_1 + 0x78) - *(int *)(param_1 + 0x6c)) + *(int *)(param_1 + 0x7c);
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    bVar7 = *(byte *)(*(int *)(param_1 + 4) + 0x155) & 0xf0;
    if (bVar7 == 0x10) {
      iVar10 = *(int *)(param_1 + 0x20) + 0x12;
      iVar12 = iVar10 >> 5;
      if (iVar10 < 0) {
        iVar12 = *(int *)(param_1 + 0x20) + 0x31 >> 5;
      }
    }
    else if (bVar7 == 0x20) {
      if ((*(int *)(param_1 + 0x70) >> 0xf) + 1 >> 1 < 0xe) {
        iVar12 = (*(int *)(param_1 + 0x20) + 0xc) / 0x18;
      }
      else {
        iVar12 = (*(int *)(param_1 + 0x20) + 9) / 0x12;
      }
    }
    else {
      iVar12 = (*(int *)(param_1 + 0x6c) * 0xc4) / 1000;
    }
    iVar8 = (iVar12 - iVar8) * 0x10;
    param_3[0x17] = iVar8;
    if (iVar8 < 0) {
      param_3[0x17] = 0;
    }
  }
  if ((*(uint *)(param_1 + 0x18) & 0x2000) != 0) {
    if ((*(uint *)(param_1 + 100) & 1) == 0) {
      iVar8 = FUN_c0276570((uint *)(param_1 + 0xc4),(int)*(short *)(*(int *)(param_1 + 4) + 0x176));
      param_3[0x19] = iVar8 + 0x10;
      iVar8 = FUN_c0276570((uint *)(param_1 + 0xc4),(int)*(short *)(*(int *)(param_1 + 4) + 0x174));
      param_3[0x1a] = iVar8 + 0x10;
    }
    else {
      param_3[0x19] = (*(short *)(*(int *)(param_1 + 4) + 0x176) * iVar14 >> 0xc) + 0x10;
      param_3[0x1a] = (*(short *)(*(int *)(param_1 + 4) + 0x174) * iVar14 >> 0xc) + 0x10;
    }
  }
  if ((*(uint *)(param_1 + 100) & 8) == 0) {
    param_3[0x11] = *(int *)(param_1 + 0x8c) - *(int *)(param_1 + 0x88);
    param_3[0x12] = *(undefined4 *)(param_1 + 0x94);
  }
  else {
    param_3[0x11] = 1;
    param_3[0x12] = 0x18;
  }
  return 0x7c;
}



/* c0264710 FUN_c0264710 */

/* Boundary evidence: original MIPS .pdata c0264710..c026486b. Semantic name remains unreviewed. */

int FUN_c0264710(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int local_28;
  
  uVar4 = *(int *)(param_1 + 0x14) + 7U & 0xfffffff8;
  iVar5 = (*(int *)(param_1 + 0x18) + 7U & 0xfffffff8) + uVar4;
  iVar1 = (*(int *)(param_1 + 0x1c) + 7U & 0xfffffff8) + iVar5;
  iVar2 = iVar1;
  if (param_3 != 0) {
    iVar2 = (*(int *)(param_1 + 0x20) + 7U & 0xfffffff8) + iVar1;
    local_28 = iVar1;
  }
  if (iVar2 == 0) {
    iVar2 = 4;
  }
  iVar2 = EngAllocMem(0,iVar2,0x64667454);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)(param_2 + 0x18);
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    } while (puVar3 != (undefined4 *)(param_2 + 0x24));
    iVar2 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x14) == 0) {
      *(undefined4 *)(param_2 + 0x18) = 0;
    }
    else {
      *(int *)(param_2 + 0x18) = iVar2;
    }
    if (*(int *)(param_1 + 0x18) == 0) {
      *(undefined4 *)(param_2 + 0x1c) = 0;
    }
    else {
      *(uint *)(param_2 + 0x1c) = iVar2 + uVar4;
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = 0;
    }
    else {
      *(int *)(param_2 + 0x20) = iVar2 + iVar5;
    }
    if ((param_3 == 0) || (*(int *)(param_1 + 0x20) == 0)) {
      *(undefined4 *)(param_2 + 0x24) = 0;
    }
    else {
      *(int *)(param_2 + 0x24) = iVar2 + local_28;
    }
  }
  return iVar2;
}



/* c026486c FUN_c026486c */

/* Boundary evidence: original MIPS .pdata c026486c..c0264ed3. Semantic name remains unreviewed. */

undefined4 FUN_c026486c(int param_1,uint param_2,uint *param_3,ushort *param_4,uint param_5)

{
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  short sVar4;
  ushort uVar5;
  int iVar6;
  undefined1 *puVar7;
  ushort *puVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  
  if ((*(uint *)(*(int *)(param_1 + 0x14) + 4) & 1) == 0) {
    piVar10 = *(int **)(param_1 + 0x28);
    if (piVar10 == (int *)0x0) {
      piVar10 = (int *)FUN_c0270860(param_1);
      *(int **)(param_1 + 0x28) = piVar10;
    }
    else {
      piVar10[6] = *(uint *)(param_1 + 0xc) | piVar10[6] & 0x80000000U;
    }
    if (piVar10 == (int *)0x0) {
      return 0xffffffff;
    }
    *piVar10 = param_1;
    if (((piVar10[6] & 0x42000000U) == 0x40000000) &&
       ((*(uint *)(piVar10[1] + 0x158) & 0x10000000) == 0)) {
      if ((param_5 != 0) && (param_5 != 0)) {
        puVar8 = param_4 + param_5;
        do {
          *param_4 = 0xffff;
          param_4 = param_4 + 1;
        } while (param_4 != puVar8);
      }
    }
    else {
      iVar9 = piVar10[0x1d];
      if (param_2 < 2) {
        if (iVar9 != 0) {
          sVar4 = 0x10;
          if ((piVar10[6] & 0x2000U) == 0) {
            sVar4 = 0;
          }
          puVar8 = param_4 + 4;
LAB_c0264998:
          switch(param_5) {
          case 0:
            goto switchD_c02649bc_caseD_0;
          case 1:
            goto switchD_c02649bc_caseD_1;
          default:
            bVar3 = *(byte *)(param_3[7] + iVar9 + 2);
            if (bVar3 == 0) {
              puVar8[3] = 0;
            }
            else {
              puVar8[3] = (ushort)bVar3 * 0x10 + sVar4;
            }
          case 7:
            bVar3 = *(byte *)(param_3[6] + iVar9 + 2);
            if (bVar3 == 0) {
              puVar8[2] = 0;
            }
            else {
              puVar8[2] = (ushort)bVar3 * 0x10 + sVar4;
            }
          case 6:
            bVar3 = *(byte *)(param_3[5] + iVar9 + 2);
            if (bVar3 == 0) {
              puVar8[1] = 0;
            }
            else {
              puVar8[1] = (ushort)bVar3 * 0x10 + sVar4;
            }
          case 5:
            bVar3 = *(byte *)(param_3[4] + iVar9 + 2);
            if (bVar3 == 0) {
              *puVar8 = 0;
            }
            else {
              *puVar8 = (ushort)bVar3 * 0x10 + sVar4;
            }
          case 4:
            bVar3 = *(byte *)(param_3[3] + iVar9 + 2);
            if (bVar3 == 0) {
              puVar8[-1] = 0;
            }
            else {
              puVar8[-1] = (ushort)bVar3 * 0x10 + sVar4;
            }
          case 3:
            bVar3 = *(byte *)(param_3[2] + iVar9 + 2);
            if (bVar3 == 0) {
              puVar8[-2] = 0;
            }
            else {
              puVar8[-2] = (ushort)bVar3 * 0x10 + sVar4;
            }
          case 2:
            bVar3 = *(byte *)(param_3[1] + iVar9 + 2);
            if (bVar3 == 0) {
              puVar8[-3] = 0;
            }
            else {
              puVar8[-3] = (ushort)bVar3 * 0x10 + sVar4;
            }
            goto switchD_c02649bc_caseD_1;
          }
        }
        iVar6 = piVar10[0x28];
        iVar11 = *(int *)(piVar10[1] + 0x20);
        iVar9 = *(int *)(iVar6 + 0x10);
        iVar14 = *(int *)(iVar6 + 0x20) + iVar11;
        iVar13 = *(int *)(iVar6 + 0x18) + iVar11;
        if ((*(int *)(iVar6 + 0x60) == 0) ||
           (bVar2 = FUN_c0269ff8(piVar10[1],*(uint *)(iVar6 + 100)),
           CONCAT31(extraout_var,bVar2) == 0)) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(piVar10[0x28] + 0x60) + iVar11;
        }
        uVar15 = (uint)CONCAT11(*(undefined1 *)(iVar13 + 0x22),*(undefined1 *)(iVar13 + 0x23));
        iVar13 = uVar15 * 4 + iVar14;
        uVar1 = CONCAT11(*(undefined1 *)(iVar13 + -4),*(undefined1 *)(iVar13 + -3));
        if ((piVar10[0x19] & 1U) == 0) {
          sVar4 = 0x10;
          if ((piVar10[6] & 0x2000U) == 0) {
            sVar4 = 0;
          }
          for (; param_5 != 0; param_5 = param_5 - 1) {
            uVar5 = uVar1;
            if (*param_3 < uVar15) {
              puVar7 = (undefined1 *)(*param_3 * 4 + iVar14);
              uVar5 = CONCAT11(*puVar7,puVar7[1]);
            }
            if (uVar5 == 0) {
              uVar12 = FUN_c0274bb8(piVar10[0x31],piVar10[0x32],0);
              *param_4 = (ushort)uVar12;
            }
            else {
              uVar12 = FUN_c0274bb8(piVar10[0x31],piVar10[0x32],(uint)uVar5);
              *param_4 = (short)uVar12 + sVar4;
            }
            param_3 = param_3 + 1;
            param_4 = param_4 + 1;
          }
          return 1;
        }
        iVar13 = piVar10[0x1b];
        uVar12 = 1;
        bVar2 = true;
        sVar4 = 0x10;
        if ((piVar10[6] & 0x2000U) == 0) {
          sVar4 = 0;
        }
        if ((((piVar10[0x19] & 0x10U) == 0) || ((*(byte *)(iVar9 + iVar11 + 0x11) & 0x14) == 0)) ||
           ((*(uint *)(piVar10[1] + 0x158) & 0x10000000) != 0)) {
          bVar2 = false;
        }
        iVar9 = piVar10[0x10];
        if (iVar9 < 0) {
          iVar9 = -iVar9;
        }
        do {
          if (param_5 == 0) {
            return uVar12;
          }
          if ((((piVar10[6] & 0x42000000U) == 0x40000000) &&
              (bVar3 = FUN_c0276b64((int *)piVar10[1],*param_3),
              CONCAT31(extraout_var_00,bVar3) == 0)) ||
             ((bVar2 && ((iVar6 == 0 || (iVar13 < (int)(uint)*(byte *)(*param_3 + iVar6 + 4))))))) {
            *param_4 = 0xffff;
            uVar12 = 0;
          }
          else {
            uVar5 = uVar1;
            if (*param_3 < uVar15) {
              puVar7 = (undefined1 *)(*param_3 * 4 + iVar14);
              uVar5 = CONCAT11(*puVar7,puVar7[1]);
            }
            *param_4 = (ushort)((int)((uint)uVar5 * iVar9 + 0x8000) >> 0xc) & 0xfff0;
            if (((DAT_c029ac80 == 0) && ((((int *)piVar10[1])[0x56] & 0x10000000U) != 0)) &&
               (bVar3 = FUN_c0276b64((int *)piVar10[1],*param_3),
               CONCAT31(extraout_var_01,bVar3) != 0)) {
              if (piVar10[0x10] < 1) {
                if ((uint)*param_4 != piVar10[0x61] * -0x10) {
                  uVar5 = (short)piVar10[0x61] * -0x20;
                  goto LAB_c0264dc0;
                }
              }
              else if ((uint)*param_4 != piVar10[0x61] << 4) {
                uVar5 = (ushort)(piVar10[0x61] << 5);
LAB_c0264dc0:
                *param_4 = uVar5;
              }
            }
            if (*param_4 != 0) {
              *param_4 = sVar4 + *param_4;
            }
          }
          param_5 = param_5 - 1;
          param_3 = param_3 + 1;
          param_4 = param_4 + 1;
        } while( true );
      }
    }
  }
  return 0;
switchD_c02649bc_caseD_1:
  bVar3 = *(byte *)(*param_3 + iVar9 + 2);
  if (bVar3 == 0) {
    puVar8[-4] = 0;
  }
  else {
    puVar8[-4] = (ushort)bVar3 * 0x10 + sVar4;
  }
switchD_c02649bc_caseD_0:
  if (param_5 < 9) {
    return 1;
  }
  puVar8 = puVar8 + 8;
  param_3 = param_3 + 8;
  param_5 = param_5 - 8;
  goto LAB_c0264998;
}



/* c0264ed4 FUN_c0264ed4 */

/* Boundary evidence: original MIPS .pdata c0264ed4..c0265187. Semantic name remains unreviewed. */

undefined4 FUN_c0264ed4(int param_1,uint param_2,uint *param_3)

{
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  bool bVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  iVar7 = *(int *)(param_1 + 0x74);
  bVar2 = true;
  if (((*(uint *)(param_1 + 0x18) & 0x42000000) == 0x40000000) &&
     ((((*(int **)(param_1 + 4))[0x56] & 0x10000000U) == 0 ||
      (bVar3 = FUN_c0276b64(*(int **)(param_1 + 4),param_2), CONCAT31(extraout_var,bVar3) == 0)))) {
    *param_3 = 0xffffffff;
  }
  else {
    if (iVar7 != 0) {
      *param_3 = (uint)*(byte *)(iVar7 + param_2 + 2) << 4;
      return 1;
    }
    iVar6 = *(int *)(param_1 + 0xa0);
    iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x20);
    iVar7 = *(int *)(iVar6 + 0x10);
    iVar11 = *(int *)(iVar6 + 0x20) + iVar8;
    iVar9 = *(int *)(iVar6 + 0x18) + iVar8;
    if ((*(int *)(iVar6 + 0x60) == 0) ||
       (bVar4 = FUN_c0269ff8(*(int *)(param_1 + 4),*(uint *)(iVar6 + 100)),
       CONCAT31(extraout_var_00,bVar4) == 0)) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(*(int *)(param_1 + 0xa0) + 0x60) + iVar8;
    }
    uVar10 = (uint)CONCAT11(*(undefined1 *)(iVar9 + 0x22),*(undefined1 *)(iVar9 + 0x23));
    iVar9 = uVar10 * 4 + iVar11;
    uVar1 = CONCAT11(*(undefined1 *)(iVar9 + -4),*(undefined1 *)(iVar9 + -3));
    if ((((*(uint *)(param_1 + 100) & 0x10) == 0) || ((*(byte *)(iVar7 + iVar8 + 0x11) & 0x14) == 0)
        ) || ((((*(int **)(param_1 + 4))[0x56] & 0x10000000U) != 0 &&
              (bVar3 = FUN_c0276b64(*(int **)(param_1 + 4),param_2),
              CONCAT31(extraout_var_01,bVar3) != 0)))) {
      bVar2 = false;
    }
    if ((!bVar2) ||
       ((iVar6 != 0 && ((int)(uint)*(byte *)(iVar6 + param_2 + 4) <= *(int *)(param_1 + 0x6c))))) {
      if (param_2 < uVar10) {
        puVar5 = (undefined1 *)(param_2 * 4 + iVar11);
        uVar1 = CONCAT11(*puVar5,puVar5[1]);
      }
      iVar7 = *(int *)(param_1 + 0x40) * (uint)uVar1;
      if (*(int *)(param_1 + 0x40) < 1) {
        *param_3 = -(0x8000 - iVar7 >> 0xc & 0xfffffff0U);
      }
      else {
        *param_3 = iVar7 + 0x8000 >> 0xc & 0xfffffff0;
      }
      if (((*(int **)(param_1 + 4))[0x56] & 0x10000000U) == 0) {
        return 1;
      }
      bVar3 = FUN_c0276b64(*(int **)(param_1 + 4),param_2);
      if (CONCAT31(extraout_var_02,bVar3) == 0) {
        return 1;
      }
      if (DAT_c029ac80 != 0) {
        return 1;
      }
      if (*param_3 == 0) {
        return 1;
      }
      if (*param_3 == *(int *)(param_1 + 0x184) << 4) {
        return 1;
      }
      *param_3 = *(int *)(param_1 + 0x184) << 5;
      return 1;
    }
    *param_3 = 0xffffffff;
  }
  return 0;
}



/* c0265188 FUN_c0265188 */

/* Boundary evidence: original MIPS .pdata c0265188..c026538f. Semantic name remains unreviewed. */

void FUN_c0265188(undefined4 param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  short sStack_30;
  short local_2e;
  short local_28;
  short local_26;
  
  param_4[1] = param_1;
  *param_4 = 0;
  param_4[7] = 0;
  param_4[8] = 0;
  param_4[9] = 0;
  param_4[10] = 0;
  param_4[5] = 0;
  param_4[6] = 0;
  FUN_c0263e2c(param_3,param_2,&sStack_30);
  if ((*(uint *)(param_3 + 100) & 1) == 0) {
    puVar4 = (uint *)(param_3 + 0xc4);
    uVar2 = FUN_c0276570(puVar4,(int)local_26);
    param_4[2] = uVar2;
    uVar2 = FUN_c0276570(puVar4,(int)local_28);
    param_4[3] = uVar2;
    uVar2 = FUN_c0276570(puVar4,(int)local_2e);
    param_4[4] = uVar2;
    FUN_c0276504((int)local_26,(uint *)(param_3 + 0xac),(longlong *)(param_4 + 0xc));
  }
  else {
    uVar3 = *(uint *)(param_3 + 0x40);
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    puVar4 = param_4 + 2;
    iVar1 = FUN_c0264ed4(param_3,param_2,puVar4);
    if (iVar1 == 0) {
      iVar1 = FUN_c0274f80((int)local_26,*(uint *)(param_3 + 0x40));
      *puVar4 = iVar1 << 4;
    }
    param_4[0xd] = *puVar4;
    param_4[0xc] = 0;
    if (*(int *)(param_3 + 0x40) < 0) {
      *puVar4 = -*puVar4;
    }
    param_4[0xf] = 0;
    param_4[0xe] = 0;
    iVar1 = FUN_c0274f80(uVar3,(int)local_28);
    param_4[3] = iVar1 << 4;
    iVar1 = FUN_c0274f80(uVar3,(int)local_2e);
    param_4[4] = iVar1 << 4;
  }
  piVar5 = param_4 + 2;
  if ((*(uint *)(param_3 + 0x18) & 0x2000) != 0) {
    if (*piVar5 != 0) {
      *piVar5 = *piVar5 + 0x10;
    }
    if ((*(uint *)(param_3 + 100) & 1) == 0) {
      if ((param_4[0xd] != 0) || (param_4[0xf] != 0)) {
        FUN_c02626e4(param_4 + 0xc,(uint *)(param_3 + 0xd0));
      }
    }
    else {
      param_4[0xd] = *piVar5;
      if (*(int *)(param_3 + 0x40) < 0) {
        param_4[0xd] = -*piVar5;
      }
    }
  }
  return;
}



/* c0265390 FUN_c0265390 */

/* Boundary evidence: original MIPS .pdata c0265390..c026545b. Semantic name remains unreviewed. */

undefined4 FUN_c0265390(int param_1,uint param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int local_58 [16];
  
  if (param_3 == (int *)0x0) {
    if (param_4 == (undefined4 *)0x0) {
      return 0x18;
    }
    param_3 = local_58;
  }
  FUN_c026275c(param_2,*(int *)(param_1 + 0x98),param_1);
  iVar1 = FUN_c0272434(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
  if (iVar1 == 0) {
    FUN_c0265188(param_2,(uint)*(ushort *)(*(int *)(param_1 + 0x9c) + 0x24),param_1,param_3);
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(param_1 + 0xa4);
      param_4[1] = *(undefined4 *)(param_1 + 0xa8);
      param_4[2] = 1;
      param_4[3] = 1;
      *(undefined1 *)(param_4 + 5) = 0;
      *param_3 = (int)param_4;
    }
    return 0x18;
  }
  return 0xffffffff;
}



/* c026545c FUN_c026545c */

void FUN_c026545c(int param_1,int param_2,int param_3,int *param_4,int param_5,uint param_6)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  iVar4 = 8;
  if ((*(uint *)(param_1 + 0x18) & 0x10000) == 0) {
    iVar4 = 1;
  }
  iVar7 = param_4[4];
  uVar2 = iVar7 + 1U >> 1;
  iVar4 = ((param_4[3] + param_4[2] + iVar7) * iVar4 + 0x1fU >> 5) * 4;
  if (*param_4 != 0) {
    param_3 = *param_4 * iVar4 + param_3;
  }
  pbVar1 = (byte *)(param_4[2] + param_3);
  pcVar6 = (char *)(param_2 + 0x14);
  if (param_5 == 0) {
    *(int *)(param_2 + 8) = iVar7;
    *(int *)(param_2 + 0xc) = param_4[5];
  }
  else {
    pcVar6 = pcVar6 + uVar2 * param_5;
  }
  pcVar10 = pcVar6 + param_4[5] * uVar2;
  pcVar9 = pcVar6;
  if (param_6 < (uint)((int)pcVar10 - (int)pcVar6)) {
    pcVar10 = pcVar6 + param_6;
  }
  for (; pcVar6 < pcVar10; pcVar6 = pcVar6 + uVar2) {
    pcVar9 = pcVar9 + uVar2;
    pbVar5 = pbVar1;
    pcVar8 = pcVar6;
    if (pcVar6 < pcVar6 + ((uint)param_4[4] >> 1)) {
      do {
        *pcVar8 = (&DAT_c026104c)[*pbVar5] << 4;
        *pcVar8 = (&DAT_c026104c)[pbVar5[1]] + *pcVar8;
        pcVar8 = pcVar8 + 1;
        pbVar5 = pbVar5 + 2;
      } while (pcVar8 < pcVar6 + ((uint)param_4[4] >> 1));
    }
    if ((param_4[4] & 1U) != 0) {
      *pcVar8 = (&DAT_c026104c)[*pbVar5] << 4;
      pcVar8 = pcVar8 + 1;
    }
    if ((pcVar8 < pcVar9) && ((int)pcVar9 - (int)pcVar8 != 0)) {
      pcVar3 = pcVar8 + ((int)pcVar9 - (int)pcVar8);
      do {
        *pcVar8 = '\0';
        pcVar8 = pcVar8 + 1;
      } while (pcVar8 != pcVar3);
    }
    pbVar1 = pbVar1 + iVar4;
  }
  return;
}



/* c02655fc FUN_c02655fc */

/* Boundary evidence: original MIPS .pdata c02655fc..c026561f. Semantic name remains unreviewed. */

void FUN_c02655fc(int param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  FUN_c026545c(param_1,param_2,param_3,param_4,0,param_5);
  return;
}



/* c0265620 FUN_c0265620 */

void FUN_c0265620(int param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  
  iVar3 = 8;
  if ((*(uint *)(param_1 + 0x18) & 0x10000) == 0) {
    iVar3 = 1;
  }
  iVar6 = param_4[2];
  iVar1 = param_4[4];
  iVar3 = ((param_4[3] + iVar6 + iVar1) * iVar3 + 0x1fU >> 5) * 4;
  if (*param_4 != 0) {
    param_3 = *param_4 * iVar3 + param_3;
  }
  puVar4 = (undefined1 *)(param_2 + 0x14);
  *(int *)(param_2 + 8) = param_4[4];
  iVar6 = iVar6 + param_3;
  *(int *)(param_2 + 0xc) = param_4[5];
  puVar7 = puVar4 + param_4[5] * iVar1;
  if (param_5 < (uint)((int)puVar7 - (int)puVar4)) {
    puVar7 = puVar4 + param_5;
  }
  if (puVar4 < puVar7) {
    iVar2 = param_4[4];
    do {
      if (puVar4 < puVar4 + iVar2) {
        puVar5 = puVar4;
        do {
          *puVar5 = puVar5[iVar6 - (int)puVar4];
          iVar2 = param_4[4];
          puVar5 = puVar5 + 1;
        } while (puVar5 < puVar4 + iVar2);
      }
      puVar4 = puVar4 + iVar1;
      iVar6 = iVar6 + iVar3;
    } while (puVar4 < puVar7);
  }
  return;
}



/* c0265714 FUN_c0265714 */

/* Boundary evidence: original MIPS .pdata c0265714..c02657fb. Semantic name remains unreviewed. */

void FUN_c0265714(undefined4 param_1,uint param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  short sStack_28;
  short local_26;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  
  param_4[1] = param_1;
  *param_4 = 0;
  param_4[7] = 0;
  param_4[8] = 0;
  param_4[9] = 0;
  param_4[10] = 0;
  FUN_c0263e2c(param_3,param_2,&sStack_28);
  puVar3 = (uint *)(param_3 + 0xc4);
  uVar1 = FUN_c0276570(puVar3,(int)local_1e);
  param_4[2] = uVar1;
  uVar1 = FUN_c0276570(puVar3,(int)local_20);
  param_4[3] = uVar1;
  uVar1 = FUN_c0276570(puVar3,(int)local_26);
  param_4[4] = uVar1;
  iVar2 = FUN_c0276570((uint *)(param_3 + 0xf8),(int)local_24);
  param_4[5] = -iVar2;
  iVar2 = FUN_c0276570((uint *)(param_3 + 0xf8),(int)local_22);
  param_4[6] = -iVar2;
  FUN_c0276504((int)local_1e,(uint *)(param_3 + 0xac),(longlong *)(param_4 + 0xc));
  return;
}



/* c02657fc FUN_c02657fc */

/* Boundary evidence: original MIPS .pdata c02657fc..c02658c3. Semantic name remains unreviewed. */

undefined4 FUN_c02657fc(int param_1,uint param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_c026275c(param_2,*(int *)(param_1 + 0x98),param_1);
  iVar1 = FUN_c0272434(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
  if (iVar1 == 0) {
    if (param_3 != (int *)0x0) {
      FUN_c0265714(param_2,(uint)*(ushort *)(*(int *)(param_1 + 0x9c) + 0x24),param_1,param_3);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(param_1 + 0xa4);
      param_4[1] = *(undefined4 *)(param_1 + 0xa8);
      param_4[2] = 1;
      param_4[3] = 1;
      param_4[5] = 0;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = (int)param_4;
    }
    uVar2 = 0x18;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* c02658c4 FUN_c02658c4 */

/* Boundary evidence: original MIPS .pdata c02658c4..c0266233. Semantic name remains unreviewed. */

void FUN_c02658c4(undefined4 param_1,uint param_2,int param_3,int param_4,undefined4 *param_5,
                 int *param_6,uint *param_7)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint local_50;
  uint local_4c;
  int local_48;
  uint local_40;
  uint local_3c;
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  short local_30;
  short local_2e;
  
  if ((*(int *)(param_3 + 0x124) == 0) || (bVar3 = true, (*(uint *)(param_3 + 0x120) & 2) == 0)) {
    bVar3 = false;
  }
  iVar16 = (int)*(short *)(param_4 + 100) - (int)*(short *)(param_4 + 0x60);
  sVar1 = *(short *)(param_4 + 0x5e);
  sVar2 = *(short *)(param_4 + 0x62);
  *param_5 = 0;
  param_5[1] = param_1;
  iVar6 = (int)sVar2 - (int)sVar1;
  local_48 = iVar6;
  if ((((*(int *)(param_3 + 0x84) < (int)*(short *)(param_4 + 0x60)) ||
       ((int)*(short *)(param_4 + 100) < *(int *)(param_3 + 0x80))) ||
      (*(int *)(param_3 + 0x8c) < -(int)*(short *)(param_4 + 0x62))) ||
     (bVar4 = false, -(int)*(short *)(param_4 + 0x5e) < *(int *)(param_3 + 0x88))) {
    bVar4 = true;
  }
  while (((iVar16 != 0 && (iVar6 != 0)) && (!bVar4))) {
    iVar7 = (int)*(short *)(param_4 + 0x60);
    param_5[10] = -(int)*(short *)(param_4 + 0x5e);
    sVar1 = *(short *)(param_4 + 0x62);
    iVar10 = -(int)sVar1;
    iVar17 = iVar7 + iVar16;
    param_5[8] = iVar10;
    if (param_6 == (int *)0x0) {
LAB_c0265b60:
      param_5[7] = iVar7;
      param_5[9] = iVar17;
      goto LAB_c0265b14;
    }
    iVar12 = *(int *)(param_3 + 0x88) + (int)sVar1;
    if (*(int *)(param_3 + 0x88) <= iVar10) {
      iVar12 = 0;
    }
    iVar9 = param_5[10];
    iVar11 = iVar9 - *(int *)(param_3 + 0x8c);
    if (iVar9 <= *(int *)(param_3 + 0x8c)) {
      iVar11 = 0;
    }
    if ((iVar12 == 0) && (iVar11 == 0)) {
LAB_c0265a5c:
      iVar10 = 0;
      iVar9 = 0;
      if (iVar7 < *(int *)(param_3 + 0x80)) {
        iVar9 = *(int *)(param_3 + 0x80) - iVar7;
      }
      if (*(int *)(param_3 + 0x84) < iVar17) {
        iVar10 = iVar17 - *(int *)(param_3 + 0x84);
      }
      if ((iVar9 != 0) || (iVar10 != 0)) {
        uVar13 = *(uint *)(param_3 + 0x90) >> 2;
        iVar16 = (iVar16 - iVar10) - iVar9;
        iVar7 = iVar9 + iVar7;
        iVar17 = iVar17 - iVar10;
        if (uVar13 < 0xb) {
          uVar13 = 10;
        }
        if (((int)uVar13 < iVar9) || ((int)uVar13 < iVar10)) goto LAB_c0265ad4;
      }
      *param_6 = iVar12;
      param_6[1] = iVar11;
      param_6[2] = iVar9;
      param_6[3] = iVar10;
      param_6[4] = iVar16;
      param_6[5] = iVar6;
      goto LAB_c0265b60;
    }
    param_5[8] = iVar10 + iVar12;
    param_5[10] = iVar9 - iVar11;
    iVar10 = *(int *)(param_3 + 0x6c);
    iVar6 = (iVar6 - iVar11) - iVar12;
    if (iVar10 < 0xb) {
      iVar10 = 10;
    }
    local_48 = iVar6;
    if ((iVar12 <= iVar10) && (iVar11 <= iVar10)) goto LAB_c0265a5c;
LAB_c0265ad4:
    bVar4 = true;
  }
  iVar6 = *(int *)(param_3 + 0xa4);
  param_5[7] = iVar6;
  iVar10 = *(int *)(param_3 + 0xa8);
  param_5[8] = iVar10;
  param_5[9] = iVar6 + 1;
  param_5[10] = iVar10 + 1;
  if (param_6 != (int *)0x0) {
    param_6[4] = 0;
    param_6[5] = 0;
  }
LAB_c0265b14:
  local_4c = param_2;
  if ((*(uint *)(param_3 + 100) & 1) == 0) {
    uVar8 = 0x10;
    if ((*(uint *)(param_3 + 0x18) & 0x2000) == 0) {
      uVar8 = 0;
    }
    local_50 = CONCAT22(local_50._2_2_,uVar8);
    FUN_c0263e2c(param_3,param_2,&local_38);
    puVar14 = (uint *)(param_3 + 0xc4);
    local_40 = (uint)local_2e;
    uVar13 = FUN_c0276570(puVar14,local_40);
    param_5[2] = uVar13;
    if ((*(uint *)(param_3 + 100) & 2) == 0) {
      if (bVar3) {
        FUN_c026373c(param_3,local_4c,(int)local_34,(int *)&local_4c,(int *)&local_50);
        uVar13 = local_4c;
        FUN_c0276504(local_4c,(uint *)(param_3 + 0xac),(longlong *)(param_5 + 0xc));
        uVar5 = FUN_c0276570((uint *)(param_3 + 0xc4),uVar13);
        uVar15 = local_50;
        param_5[2] = uVar5;
        local_4c = (*(int *)(param_4 + 0x50) >> 0xf) + 1 >> 1;
        uVar13 = -((*(int *)(param_4 + 0x54) >> 0xf) + 1 >> 1);
        local_40 = local_4c;
        local_3c = uVar13;
        uVar5 = FUN_c0276570((uint *)(param_3 + 0xc4),local_50);
        param_5[3] = uVar5;
        uVar5 = FUN_c0276570((uint *)(param_3 + 0xc4),((int)local_32 - (int)local_34) + uVar15);
        param_5[4] = uVar5;
        iVar6 = FUN_c0276570((uint *)(param_3 + 0xf8),(int)local_36);
        param_5[5] = -iVar6;
        iVar6 = FUN_c0276570((uint *)(param_3 + 0xf8),(int)local_38);
        param_5[6] = -iVar6;
        uVar15 = local_4c;
      }
      else {
        FUN_c0276504(local_40,(uint *)(param_3 + 0xac),(longlong *)(param_5 + 0xc));
        uVar15 = (*(int *)(param_4 + 0x50) >> 0xf) + 1 >> 1;
        uVar13 = -((*(int *)(param_4 + 0x54) >> 0xf) + 1 >> 1);
        local_40 = uVar15;
        local_3c = uVar13;
        uVar5 = FUN_c0276570(puVar14,(int)local_30);
        param_5[3] = uVar5;
        uVar5 = FUN_c0276570(puVar14,(int)local_36);
        param_5[4] = uVar5;
        iVar6 = FUN_c0276570((uint *)(param_3 + 0xf8),(int)local_34);
        param_5[5] = -iVar6;
        iVar6 = FUN_c0276570((uint *)(param_3 + 0xf8),(int)local_32);
        param_5[6] = -iVar6;
      }
      if ((*(uint *)(param_3 + 0x18) & 0x2000) != 0) {
        if ((param_5[0xd] != 0) || (param_5[0xf] != 0)) {
          FUN_c02626e4(param_5 + 0xc,(uint *)(param_3 + 0xd0));
          param_5[2] = param_5[2] + 0x10;
        }
        param_5[4] = (uint)*(ushort *)(param_3 + 0x180) * 0x10 + param_5[4];
      }
      param_5[3] = param_5[3] & 0xfffffff0;
      param_5[4] = param_5[4] + 0xf & 0xfffffff0;
      param_5[5] = param_5[5] + 0xf & 0xfffffff0;
      param_5[6] = param_5[6] & 0xfffffff0;
      if (((param_6 != (int *)0x0) && (param_6[4] != 0)) && (param_6[5] != 0)) {
        iVar6 = 0;
        iVar10 = FUN_c0263484(param_3,(int)param_5,(int *)&local_40,param_6[4],param_6[5]);
        uVar15 = local_40;
        uVar13 = local_3c;
        while ((iVar10 == 0 && (bVar3 = iVar6 < 2000, iVar6 = iVar6 + 1, bVar3))) {
          param_5[3] = param_5[3] + -0x10;
          param_5[4] = param_5[4] + 0x10;
          if (param_5[5] + 0x10 < *(int *)(param_3 + 0x78) << 4) {
            param_5[5] = param_5[5] + 0x10;
          }
          if (*(int *)(param_3 + 0x7c) * -0x10 < param_5[6] + -0x10) {
            param_5[5] = param_5[5] + -0x10;
          }
          local_40 = uVar15;
          local_3c = uVar13;
          iVar10 = FUN_c0263484(param_3,(int)param_5,(int *)&local_40,param_6[4],param_6[5]);
          uVar15 = local_40;
          uVar13 = local_3c;
        }
      }
      if (param_7 != (uint *)0x0) {
        *param_7 = uVar15;
        param_7[1] = uVar13;
      }
    }
    else {
      if (bVar3) {
        iVar10 = (*(int *)(param_4 + 0xac) >> 0xf) + 1 >> 1;
        iVar6 = (*(int *)(param_4 + 0xb8) >> 0xf) + 1 >> 1;
        iVar7 = param_5[10] - param_5[8];
        if (*(int *)(param_3 + 0x44) < 0) {
          iVar6 = -iVar6;
          param_5[8] = iVar6;
          param_5[10] = iVar7 + iVar6;
        }
        else {
          iVar6 = -(iVar6 - iVar7);
          param_5[10] = iVar6;
          param_5[8] = iVar6 - iVar7;
          iVar10 = -iVar10;
        }
        param_5[2] = iVar10 << 4;
        param_5[0xc] = 0;
        param_5[0xd] = 0;
        param_5[0xe] = 0;
      }
      else {
        uVar13 = (uVar13 & 0xfffffff8) + 8 & 0xfffffff0;
        param_5[2] = uVar13;
        param_5[0xc] = 0;
        param_5[0xd] = 0;
        param_5[0xe] = 0;
        if (uVar13 != 0) {
          param_5[2] = (local_50 & 0xffff) + uVar13;
        }
      }
      iVar6 = __lts(*(undefined4 *)(param_3 + 0xc0),0);
      if (iVar6 == 0) {
        param_5[3] = param_5[8] << 4;
        param_5[4] = param_5[10] * 0x10;
        param_5[0xf] = param_5[2];
      }
      else {
        param_5[3] = param_5[10] * -0x10;
        param_5[4] = param_5[8] * -0x10;
        param_5[0xf] = -param_5[2];
      }
      iVar6 = __lts(*(undefined4 *)(param_3 + 0xf0),0);
      if (iVar6 == 0) {
        param_5[5] = param_5[9] << 4;
        param_5[6] = param_5[7] << 4;
      }
      else {
        param_5[5] = param_5[7] * -0x10;
        param_5[6] = param_5[9] * -0x10;
      }
    }
    goto LAB_c02661b0;
  }
  puVar14 = param_5 + 2;
  if (bVar3) {
    *puVar14 = ((*(int *)(param_4 + 0xb0) >> 0xf) + 1 >> 1) << 4;
  }
  else {
    iVar6 = FUN_c0264ed4(param_3,param_2,puVar14);
    if (iVar6 == 0) {
      uVar13 = (*(int *)(param_4 + 0x48) >> 0xc & 0xfffffff8U) + 8 & 0xfffffff0;
LAB_c0265be4:
      *puVar14 = uVar13;
    }
    else {
      iVar6 = 0x10;
      if ((*(uint *)(param_3 + 0x18) & 0x2000) == 0) {
        iVar6 = 0;
      }
      uVar13 = *puVar14;
      if (uVar13 != 0) {
        if (-1 < *(int *)(param_3 + 0x40)) {
          uVar13 = iVar6 + uVar13;
          goto LAB_c0265be4;
        }
        *puVar14 = uVar13 - iVar6;
      }
    }
  }
  param_5[0xd] = *puVar14;
  param_5[0xc] = 0;
  if (*(int *)(param_3 + 0x40) < 0) {
    *puVar14 = -*puVar14;
  }
  param_5[0xf] = 0;
  param_5[0xe] = 0;
  if (bVar3) {
    iVar7 = param_5[9] - param_5[7];
    iVar6 = (*(int *)(param_4 + 0xb4) >> 0xf) + 1 >> 1;
    iVar10 = iVar6 + iVar7;
    if (*(int *)(param_3 + 0x40) < 0) {
      iVar6 = -iVar10;
      param_5[9] = iVar10;
      param_5[7] = iVar10 - iVar7;
    }
    else {
      param_5[7] = iVar6;
      param_5[9] = iVar10;
    }
    iVar6 = iVar6 * 0x10;
    iVar10 = iVar7 * 0x10 + iVar6;
LAB_c0265c9c:
    param_5[4] = iVar10;
    param_5[3] = iVar6;
  }
  else {
    param_5[3] = param_5[7] * 0x10;
    param_5[4] = param_5[9] * 0x10;
    if (*(int *)(param_3 + 0x40) < 0) {
      iVar6 = param_5[9] * -0x10;
      iVar10 = param_5[7] * -0x10;
      goto LAB_c0265c9c;
    }
  }
  param_5[5] = param_5[8] * -0x10;
  param_5[6] = param_5[10] * -0x10;
  if (*(int *)(param_3 + 0x50) < 0) {
    param_5[5] = param_5[10] * 0x10;
    param_5[6] = param_5[8] * 0x10;
  }
LAB_c02661b0:
  if (((iVar16 == 0) || (local_48 == 0)) ||
     ((param_6 != (int *)0x0 && ((param_6[4] == 0 || (param_6[5] == 0)))))) {
    param_5[3] = 0;
    param_5[4] = 0x10;
    param_5[5] = 0;
    param_5[6] = 0x10;
    param_5[7] = 0;
    param_5[8] = 0;
    param_5[9] = 1;
    param_5[10] = 1;
  }
  return;
}



/* c0266234 FUN_c0266234 */

/* Boundary evidence: original MIPS .pdata c0266234..c02664d7. Semantic name remains unreviewed. */

uint FUN_c0266234(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4,size_t param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t _Size;
  undefined1 *puVar5;
  int iVar6;
  uint local_120;
  uint local_118 [2];
  undefined4 *local_110;
  undefined4 *local_10c;
  int aiStack_108 [6];
  undefined1 auStack_f0 [200];
  
  iVar4 = *(int *)(param_1 + 0x98);
  iVar6 = *(int *)(param_1 + 0x9c);
  sVar1 = *(short *)(param_1 + 0x182);
  local_110 = (undefined4 *)(param_1 + 8);
  iVar3 = 0;
  local_10c = param_3;
  FUN_c02619f4(local_110);
  FUN_c026275c(param_2,iVar4,param_1);
  iVar2 = FUN_c0272434(iVar4,iVar6);
  if (iVar2 == 0) {
    local_118[0] = (uint)*(ushort *)(*(int *)(param_1 + 0x9c) + 0x24);
    *(undefined4 *)(iVar4 + 0x38) = 0;
    *(undefined4 *)(iVar4 + 0x3c) = 0;
    *(undefined4 *)(iVar4 + 0x40) = 0;
    iVar2 = FUN_c0262698(iVar4,iVar6);
    if ((iVar2 != 0) || (iVar2 = FUN_c0272bb0(iVar4,iVar6), iVar2 != 0)) goto LAB_c0266304;
    if (param_3 != (undefined4 *)0x0) {
      if ((*(int *)(param_1 + 0x124) == 0) || ((*(uint *)(param_1 + 0x120) & 2) == 0)) {
        puVar5 = *(undefined1 **)(param_1 + 0x9c);
        local_120 = param_2;
      }
      else {
        local_120 = *(uint *)(param_1 + 0x128);
        puVar5 = auStack_f0;
        FUN_c0276fa4(param_1,(int)auStack_f0,*(int *)(param_1 + 0x9c));
      }
      FUN_c02658c4(local_120,local_118[0],param_1,(int)puVar5,local_10c,aiStack_108,local_118);
    }
    if (param_4 == (undefined1 *)0x0) {
      if (param_5 == 0) {
        iVar2 = *(int *)(param_1 + 0x9c);
        _Size = ((int)*(short *)(iVar2 + 0x62) - (int)*(short *)(iVar2 + 0x5e)) *
                (int)*(short *)(iVar2 + 0x5c);
        goto LAB_c0266450;
      }
LAB_c026639c:
      iVar3 = 0x57;
    }
    else {
      if (param_5 == 0) goto LAB_c026639c;
      if ((*(uint *)(param_1 + 100) & 8) != 0) {
        *param_4 = 0;
        _Size = local_118[0];
        goto LAB_c0266450;
      }
      iVar2 = FUN_c0264710(*(int *)(param_1 + 0x9c),iVar4,(uint)(sVar1 != 0));
      *(int *)(param_1 + 0x10) = iVar2;
      if (iVar2 == 0) {
        iVar3 = 8;
      }
      else {
        iVar2 = FUN_c0273964(iVar4,iVar6);
        _Size = local_118[0];
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0x9c);
          _Size = ((int)*(short *)(iVar2 + 0x62) - (int)*(short *)(iVar2 + 0x5e)) *
                  (int)*(short *)(iVar2 + 0x5c);
          if ((int)param_5 < (int)_Size) {
            _Size = param_5;
          }
          if (*(void **)(iVar2 + 0x58) == (void *)0x0) goto LAB_c0266430;
          memcpy(param_4,*(void **)(iVar2 + 0x58),_Size);
        }
        else {
LAB_c0266430:
          iVar3 = 0x3eb;
        }
        EngFreeMem(*(undefined4 *)(param_1 + 0x10));
        *(undefined4 *)(param_1 + 0x10) = 0;
        if (iVar3 == 0) goto LAB_c0266450;
      }
    }
  }
  else {
LAB_c0266304:
    iVar3 = 0x3eb;
  }
  EngSetLastError(iVar3);
  _Size = 0xffffffff;
LAB_c0266450:
  FUN_c02619f4(local_110);
  return _Size;
}



/* c02664d8 FUN_c02664d8 */

/* Boundary evidence: original MIPS .pdata c02664d8..c0266817. Semantic name remains unreviewed. */

uint FUN_c02664d8(int param_1,uint param_2,int *param_3,uint *param_4,int *param_5,
                 undefined4 param_6)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  uint local_150;
  uint local_14c;
  int aiStack_148 [4];
  int local_138;
  int local_134;
  int local_130 [16];
  undefined1 auStack_f0 [200];
  
  *param_5 = 0;
  bVar1 = false;
  if ((*(uint *)(param_1 + 8) == param_2) ||
     (iVar2 = FUN_c02636b0(param_1,param_2,1,param_5), iVar2 != 0)) {
    iVar2 = *(int *)(param_1 + 0x9c);
    uVar3 = (int)*(short *)(iVar2 + 100) - (int)*(short *)(iVar2 + 0x60);
    iVar5 = (int)*(short *)(iVar2 + 0x62) - (int)*(short *)(iVar2 + 0x5e);
    if ((uVar3 == 0) || (iVar5 == 0)) {
      bVar1 = true;
      uVar3 = 0x18;
    }
    else {
      if ((*(uint *)(param_1 + 0x18) & 0x10000) == 0) {
        uVar3 = uVar3 + 7 >> 3;
      }
      else if ((*(uint *)(param_1 + 0x18) & 0x10000000) == 0) {
        uVar3 = uVar3 + 1 >> 1;
      }
      uVar3 = (uVar3 * iVar5 + 3 & 0xfffffffc) + 0x14;
      if (*(uint *)(param_1 + 0x94) < uVar3) {
        uVar3 = *(uint *)(param_1 + 0x94);
      }
    }
    if (param_3 == (int *)0x0) {
      if (param_4 == (uint *)0x0) {
        return uVar3;
      }
      param_3 = local_130;
    }
    if ((*(int *)(param_1 + 0x124) == 0) || ((*(uint *)(param_1 + 0x120) & 2) == 0)) {
      FUN_c02658c4(param_2,*(uint *)(param_1 + 0xc),param_1,iVar2,param_3,aiStack_148,&local_150);
    }
    else {
      FUN_c0276fa4(param_1,(int)auStack_f0,iVar2);
      FUN_c02658c4(*(undefined4 *)(param_1 + 0x128),*(uint *)(param_1 + 0xc),param_1,(int)auStack_f0
                   ,param_3,aiStack_148,&local_150);
    }
    if (param_4 == (uint *)0x0) {
      return uVar3;
    }
    iVar2 = FUN_c0264710(*(int *)(param_1 + 0x9c),*(int *)(param_1 + 0x98),
                         *(uint *)(param_1 + 0x18) & 0x10000);
    *(int *)(param_1 + 0x10) = iVar2;
    if (iVar2 != 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x38) =
           *(undefined2 *)(*(int *)(param_1 + 0x9c) + 0x5e);
      *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x3a) =
           *(undefined2 *)(*(int *)(param_1 + 0x9c) + 0x62);
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x3c) = 0;
      iVar2 = FUN_c0273964(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
      *param_5 = iVar2;
      *(undefined4 *)(param_1 + 8) = 0xffffffff;
      if (*param_5 == 0) {
        if (((bVar1) || (local_138 == 0)) || (local_134 == 0)) {
          *param_4 = *(uint *)(param_1 + 0xa4);
          param_4[1] = *(uint *)(param_1 + 0xa8);
          param_4[2] = 1;
          param_4[3] = 1;
          *(undefined1 *)(param_4 + 5) = 0;
        }
        else {
          if ((*(uint *)(param_1 + 0x18) & 0x10000) == 0) {
            pcVar4 = FUN_c0263bec;
          }
          else if ((*(uint *)(param_1 + 0x18) & 0x10000000) == 0) {
            pcVar4 = FUN_c02655fc;
          }
          else {
            pcVar4 = FUN_c0265620;
          }
          (*pcVar4)(param_1,param_4,*(undefined4 *)(*(int *)(param_1 + 0x9c) + 0x58),aiStack_148,
                    param_6);
          if ((*(uint *)(param_1 + 100) & 3) == 0) {
            *param_4 = local_150;
            param_4[1] = local_14c;
          }
          else {
            *param_4 = param_3[7];
            param_4[1] = param_3[8];
          }
        }
        *param_3 = (int)param_4;
        EngFreeMem(*(undefined4 *)(param_1 + 0x10));
      }
      else {
        EngFreeMem(*(undefined4 *)(param_1 + 0x10));
        uVar3 = 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
      return uVar3;
    }
  }
  return 0xffffffff;
}



/* c0266818 FUN_c0266818 */

/* Boundary evidence: original MIPS .pdata c0266818..c0266927. Semantic name remains unreviewed. */

uint FUN_c0266818(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4,size_t param_5)

{
  byte bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0xffffffff) {
    EngSetLastError(0x57);
  }
  else {
    if ((*(int *)(param_1 + 0x124) != 0) &&
       (bVar1 = FUN_c0276b64(*(int **)(param_1 + 4),param_2), CONCAT31(extraout_var,bVar1) != 0)) {
      iVar2 = FUN_c0276e58(param_1,1);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      *(uint *)(param_1 + 0x128) = param_2;
      *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) | 2;
    }
    uVar3 = FUN_c0266234(param_1,param_2,param_3,param_4,param_5);
    if ((*(uint *)(param_1 + 0x120) & 2) == 0) {
      return uVar3;
    }
    *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) & 0xfffffffd;
    iVar2 = FUN_c0276e58(param_1,0);
    if (iVar2 != 0) {
      return uVar3;
    }
  }
  return 0xffffffff;
}



/* c0266928 FUN_c0266928 */

/* Boundary evidence: original MIPS .pdata c0266928..c0266a1b. Semantic name remains unreviewed. */

uint FUN_c0266928(int param_1,uint param_2,int *param_3,uint *param_4,int *param_5,
                 undefined4 param_6)

{
  byte bVar1;
  undefined3 extraout_var;
  uint uVar2;
  int iVar3;
  
  bVar1 = FUN_c0276b64(*(int **)(param_1 + 4),param_2);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = FUN_c02664d8(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar3 = FUN_c0276e58(param_1,1);
    if (iVar3 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) | 2;
      *(uint *)(param_1 + 0x128) = param_2;
      uVar2 = FUN_c02664d8(param_1,param_2,param_3,param_4,param_5,param_6);
      FUN_c0276e58(param_1,0);
      *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) & 0xfffffffd;
    }
  }
  return uVar2;
}



/* c0266a1c FUN_c0266a1c */

/* Boundary evidence: original MIPS .pdata c0266a1c..c0266e13. Semantic name remains unreviewed. */

uint FUN_c0266a1c(int param_1,uint param_2,uint param_3,int *param_4,uint *param_5,size_t param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int local_28 [2];
  
  if ((*(uint *)(*(int *)(param_1 + 0x14) + 4) & 1) != 0) {
    return 0xffffffff;
  }
  piVar6 = *(int **)(param_1 + 0x28);
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)FUN_c0270860(param_1);
    *(int **)(param_1 + 0x28) = piVar6;
  }
  else {
    piVar6[6] = *(uint *)(param_1 + 0xc) | piVar6[6] & 0x80000000U;
  }
  if (piVar6 == (int *)0x0) {
    return 0xffffffff;
  }
  *piVar6 = param_1;
  if (param_2 == 5) {
LAB_c0266b10:
    uVar1 = 0;
  }
  else {
    if (param_2 == 6) {
      uVar1 = 2;
      goto LAB_c0266b14;
    }
    uVar1 = 8;
    if (param_2 != 8) {
      if (param_2 == 9) goto LAB_c0266b14;
      if (((piVar6[6] & 0x10000U) == 0) || ((piVar6[6] & 0x10000000U) != 0)) goto LAB_c0266b10;
    }
    uVar1 = 4;
  }
LAB_c0266b14:
  uVar5 = piVar6[6];
  iVar3 = 0;
  uVar2 = 0;
  if ((((uVar5 & 0x2000) != 0) && ((piVar6[0x19] & 3U) != 0)) && (param_2 != 2)) {
    uVar2 = 1;
  }
  if ((param_2 < 5) || ((6 < param_2 && ((param_2 < 8 || (9 < param_2)))))) {
    if (((uVar5 & 0x10000000) == 0x10000000) && (iVar3 = -1, (uVar5 & 0x40000000) != 0x40000000)) {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 0;
  }
  iVar4 = 0;
  if (((param_2 == 1) || (param_2 == 4)) && ((piVar6[0x1a] & 2U) != 0)) {
    iVar4 = 1;
  }
  iVar3 = FUN_c026f458((int)piVar6,uVar1,uVar2,iVar3,iVar4);
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  switch(param_2) {
  case 1:
  case 4:
    if ((piVar6[0x19] & 8U) != 0) {
      uVar1 = FUN_c02657fc((int)piVar6,param_3,param_4,param_5);
      return uVar1;
    }
    local_28[0] = 0;
    if (piVar6[0x49] == 0) {
      uVar1 = FUN_c02664d8((int)piVar6,param_3,param_4,param_5,local_28,param_6);
    }
    else {
      uVar1 = FUN_c0266928((int)piVar6,param_3,param_4,param_5,local_28,param_6);
    }
    if (uVar1 == 0xffffffff) {
      if (local_28[0] == 0x1201) {
        uVar1 = FUN_c0265390((int)piVar6,param_3,param_4,param_5);
        return uVar1;
      }
      return 0xffffffff;
    }
    return uVar1;
  case 2:
    iVar3 = FUN_c027195c((int)piVar6,param_3,param_4,(int)param_5);
    if (iVar3 != 0) {
      return 0x40;
    }
    return 0xffffffff;
  case 3:
    uVar1 = FUN_c0264048((int)piVar6,0x7c,param_5);
    return uVar1;
  case 5:
  case 6:
  case 8:
  case 9:
    uVar1 = FUN_c0266818((int)piVar6,param_3,param_4,(undefined1 *)param_5,param_6);
    return uVar1;
  default:
    return 0xffffffff;
  case 0xd:
    break;
  }
  if ((piVar6[0x19] & 8U) == 0) {
    local_28[0] = 0;
    if (piVar6[0x49] == 0) {
      uVar1 = FUN_c02664d8((int)piVar6,param_3,(int *)0x0,param_5,local_28,param_6);
    }
    else {
      uVar1 = FUN_c0266928((int)piVar6,param_3,(int *)0x0,param_5,local_28,param_6);
    }
    if (uVar1 != 0xffffffff) goto LAB_c0266dac;
    if (local_28[0] != 0x1201) {
      return 0xffffffff;
    }
    uVar1 = FUN_c0265390((int)piVar6,param_3,(int *)0x0,param_5);
  }
  else {
    uVar1 = FUN_c02657fc((int)piVar6,param_3,(int *)0x0,param_5);
  }
  if (uVar1 == 0xffffffff) {
    return 0xffffffff;
  }
LAB_c0266dac:
  if ((*(short *)(piVar6[0x27] + 0x24) == 0) && (param_3 != 0)) {
    *param_4 = 1;
    return 0;
  }
  *param_4 = 0;
  return uVar1;
}



/* c0266e14 FUN_c0266e14 */

/* Boundary evidence: original MIPS .pdata c0266e14..c0266e7b. Semantic name remains unreviewed. */

undefined4 FUN_c0266e14(void)

{
  undefined4 uVar1;
  short local_10;
  undefined1 auStack_e [6];
  
  EngGetCurrentCodePage(auStack_e,&local_10);
  if ((((local_10 == 0x3a4) || (local_10 == 0x3b5)) || (local_10 == 0x551)) ||
     ((local_10 == 0x3a8 || (uVar1 = 0, local_10 == 0x3b6)))) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c0266e7c FUN_c0266e7c */

/* Boundary evidence: original MIPS .pdata c0266e7c..c0266efb. Semantic name remains unreviewed. */

undefined2 FUN_c0266e7c(int param_1)

{
  undefined2 local_10;
  undefined1 auStack_e [6];
  
  EngGetCurrentCodePage(auStack_e,&local_10);
  if (param_1 == 0x200) {
    local_10 = 0x3a4;
  }
  else if (param_1 == 0x300) {
    local_10 = 0x3a8;
  }
  else if (param_1 == 0x400) {
    local_10 = 0x3b6;
  }
  else if (param_1 == 0x500) {
    local_10 = 0x3b5;
  }
  return local_10;
}



/* c0266efc FUN_c0266efc */

ushort FUN_c0266efc(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x40) + param_1;
  if (*(int *)(param_2 + 0x40) == 0) {
    iVar3 = 0;
  }
  if (iVar3 == 0) {
    bVar1 = *(byte *)(*(int *)(param_2 + 0x10) + param_1 + 0x2d);
    uVar2 = 0;
    if ((bVar1 & 1) != 0) {
      uVar2 = 0x20;
    }
    if ((bVar1 & 2) != 0) {
      uVar2 = uVar2 | 1;
    }
  }
  else {
    uVar2 = CONCAT11(*(undefined1 *)(iVar3 + 0x3e),*(undefined1 *)(iVar3 + 0x3f));
  }
  return uVar2;
}



/* c0266f70 FUN_c0266f70 */

/* Boundary evidence: original MIPS .pdata c0266f70..c0266fef. Semantic name remains unreviewed. */

undefined4 FUN_c0266f70(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x2c) != 0) {
      EngFreeMem();
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      EngFreeMem();
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    if (*(int *)(param_1 + 8) != 0) {
      EngFreeMem();
    }
    EngFreeMem(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c0267064 FUN_c0267064 */

int FUN_c0267064(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_2 + 0xdc) + *(int *)(param_2 + 0x20);
  piVar2 = (int *)(iVar1 + 0xc);
  while( true ) {
    if ((int *)(((int)((uint)*(byte *)(iVar1 + 4) << 0x18) >> 0x10 | (uint)*(byte *)(iVar1 + 5)) *
                0x10 + iVar1 + 0xc) <= piVar2) {
      return 0;
    }
    if (param_1 == *piVar2) break;
    piVar2 = piVar2 + 4;
  }
  uVar3 = CONCAT31(CONCAT21(CONCAT11((char)piVar2[2],*(undefined1 *)((int)piVar2 + 9)),
                            *(undefined1 *)((int)piVar2 + 10)),*(undefined1 *)((int)piVar2 + 0xb));
  iVar1 = CONCAT31(CONCAT21(CONCAT11((char)piVar2[3],*(undefined1 *)((int)piVar2 + 0xd)),
                            *(undefined1 *)((int)piVar2 + 0xe)),*(undefined1 *)((int)piVar2 + 0xf));
  if (iVar1 == 0) {
    return 0;
  }
  if (-iVar1 - 1U < uVar3) {
    return 0;
  }
  if (*(uint *)(param_2 + 0x24) < iVar1 + uVar3) {
    return 0;
  }
  *param_3 = iVar1;
  return *(int *)(param_2 + 0x20) + uVar3;
}



/* c0267164 FUN_c0267164 */

undefined4 FUN_c0267164(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_3 = 0;
  if (param_1 < 0x68686562) {
    if (param_1 != 0x68686561) {
      if (param_1 < 0x636d6171) {
        if (param_1 != 0x636d6170) {
          if (param_1 == 0x45424c43) {
            uVar1 = 0xb;
          }
          else {
            if (param_1 == 0x47535542) {
              uVar1 = 8;
              goto LAB_c0267220;
            }
            if (param_1 != 0x4c545348) {
              if (param_1 == 0x4f532f32) {
                *param_2 = 0;
                return 1;
              }
              if (param_1 == 0x56444d58) {
                *param_2 = 2;
                return 1;
              }
              return 0;
            }
            uVar1 = 4;
          }
          goto LAB_c0267328;
        }
        *param_2 = 0;
        goto LAB_c02673ac;
      }
      if (param_1 == 0x67617370) {
        uVar1 = 6;
        goto LAB_c0267328;
      }
      if (param_1 == 0x676c7966) {
        *param_2 = 1;
        goto LAB_c02673ac;
      }
      if (param_1 == 0x68646d78) {
        *param_2 = 1;
        return 1;
      }
      if (param_1 != 0x68656164) {
        return 0;
      }
      uVar1 = 2;
LAB_c026727c:
      *param_2 = uVar1;
      goto LAB_c02673ac;
    }
    uVar1 = 3;
  }
  else if (param_1 < 0x6d6f7275) {
    if (param_1 == 0x6d6f7274) {
      uVar1 = 7;
LAB_c0267328:
      *param_2 = uVar1;
      return 1;
    }
    if (param_1 != 0x686d7478) {
      if (param_1 == 0x6b65726e) {
        uVar1 = 3;
        goto LAB_c0267328;
      }
      if (param_1 != 0x6c6f6361) {
        if (param_1 != 0x6d617870) {
          return 0;
        }
        *param_2 = 6;
        goto LAB_c02673ac;
      }
      uVar1 = 5;
      goto LAB_c026727c;
    }
    uVar1 = 4;
  }
  else {
    if (param_1 != 0x6e616d65) {
      if (param_1 == 0x706f7374) {
        uVar1 = 5;
      }
      else {
        if (param_1 == 0x76686561) {
          uVar1 = 10;
LAB_c0267220:
          *param_2 = uVar1;
          return 1;
        }
        if (param_1 != 0x766d7478) {
          return 0;
        }
        uVar1 = 9;
      }
      goto LAB_c0267328;
    }
    uVar1 = 7;
  }
  *param_2 = uVar1;
LAB_c02673ac:
  *param_3 = 1;
  return 1;
}



/* c02673b8 FUN_c02673b8 */

undefined4 FUN_c02673b8(int param_1)

{
  if (param_1 != 0x404) {
    if (param_1 == 0x408) {
      return 0x3a8;
    }
    if (param_1 != 0x40c) {
      if (param_1 == 0x410) {
        return 0x3a8;
      }
      if (param_1 != 0x414) {
        return 0;
      }
    }
  }
  return 0x3b6;
}



/* c026740c FUN_c026740c */

/* Boundary evidence: original MIPS .pdata c026740c..c026756b. Semantic name remains unreviewed. */

undefined4 FUN_c026740c(int param_1,int *param_2,int param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char local_318 [256];
  undefined1 auStack_218 [512];
  uint local_18;
  
  local_18 = DAT_c029ac78;
  uVar1 = 0;
  if ((param_4 & 1) == 0) {
    uVar3 = 0;
    if (param_4 >> 1 != 0) {
      iVar2 = 0;
      do {
        if (*(char *)(iVar2 + param_3) == '\0') {
          if (0xfe < uVar1) goto LAB_c026743c;
          local_318[uVar1] = *(char *)(iVar2 + param_3 + 1);
          uVar1 = uVar1 + 1;
        }
        else {
          if (0xfd < uVar1) goto LAB_c026743c;
          local_318[uVar1] = *(char *)(iVar2 + param_3);
          local_318[uVar1 + 1] = *(char *)(iVar2 + param_3 + 1);
          uVar1 = uVar1 + 2;
        }
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 2;
      } while (uVar3 < param_4 >> 1);
    }
    iVar2 = *param_2;
    local_318[uVar1] = '\0';
    if (iVar2 == 0) {
      iVar2 = EngMultiByteToWideChar(param_5,auStack_218,0x200,local_318,uVar1 + 1);
      if (iVar2 != -1) {
        *param_2 = iVar2;
LAB_c026754c:
        FUN_c029919c(local_18);
        return 1;
      }
    }
    else {
      iVar2 = EngMultiByteToWideChar(param_5,param_1,iVar2,local_318,uVar1 + 1);
      if (((iVar2 != -1) && (iVar2 == *param_2)) && (*(char *)(param_1 + iVar2 + -1) == '\0'))
      goto LAB_c026754c;
    }
  }
LAB_c026743c:
  FUN_c029919c(local_18);
  return 0;
}



/* c026756c FUN_c026756c */

/* Boundary evidence: original MIPS .pdata c026756c..c0267903. Semantic name remains unreviewed. */

undefined4 FUN_c026756c(int param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  int iVar3;
  uint uVar4;
  undefined4 uVar2;
  
  if (*(short *)(param_2 + 0x60) == 0x300) {
    uVar4 = (uint)*(ushort *)(param_2 + 0x62);
    if (((uVar4 == 0x400) || (uVar4 == 0x500)) || (uVar4 == 0x300)) {
      uVar1 = FUN_c0266e7c(uVar4);
      uVar2 = CONCAT22(extraout_var,uVar1);
      iVar3 = FUN_c026740c(*(int *)(param_2 + 0x38) + param_1,(int *)(param_2 + 0x4c),
                           *(int *)(param_2 + 8),*(uint *)(param_2 + 0xc),uVar2);
      if (iVar3 == 0) {
        return 0;
      }
      if (*(int *)(param_2 + 0x10) != 0) {
        iVar3 = FUN_c026740c(*(int *)(param_2 + 0x3c) + param_1,(int *)(param_2 + 0x50),
                             *(int *)(param_2 + 0x10),*(uint *)(param_2 + 0x14),uVar2);
        if (iVar3 == 0) {
          return 0;
        }
        if (param_1 != 0) {
          *(undefined2 *)(*(int *)(param_2 + 0x3c) + *(int *)(param_2 + 0x50) + param_1) = 0;
        }
      }
      iVar3 = FUN_c026740c(*(int *)(param_2 + 0x48) + param_1,(int *)(param_2 + 0x5c),
                           *(int *)(param_2 + 0x28),*(uint *)(param_2 + 0x2c),uVar2);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = FUN_c026740c(*(int *)(param_2 + 0x44) + param_1,(int *)(param_2 + 0x58),
                           *(int *)(param_2 + 0x20),*(uint *)(param_2 + 0x24),uVar2);
      if (iVar3 == 0) {
        return 0;
      }
      if ((*(short *)(param_2 + 0x62) != 0x500) && (*(short *)(param_2 + 0x62) != 0x400)) {
        iVar3 = FUN_c026740c(*(int *)(param_2 + 0x40) + param_1,(int *)(param_2 + 0x54),
                             *(int *)(param_2 + 0x18),*(uint *)(param_2 + 0x1c),uVar2);
        if (iVar3 == 0) {
          return 0;
        }
        return 1;
      }
    }
    else {
      if (*(uint *)(param_2 + 0x4c) == 0) {
        *(uint *)(param_2 + 0x4c) = ((*(uint *)(param_2 + 0xc) >> 1) + 1) * 2;
      }
      else {
        FUN_c027438c((undefined2 *)(*(int *)(param_2 + 0x38) + param_1),
                     *(undefined1 **)(param_2 + 8),*(uint *)(param_2 + 0x4c) >> 1);
      }
      if (*(undefined1 **)(param_2 + 0x10) != (undefined1 *)0x0) {
        if (*(uint *)(param_2 + 0x50) == 0) {
          *(uint *)(param_2 + 0x50) = ((*(uint *)(param_2 + 0x14) >> 1) + 1) * 2;
        }
        else {
          FUN_c027438c((undefined2 *)(*(int *)(param_2 + 0x3c) + param_1),
                       *(undefined1 **)(param_2 + 0x10),*(uint *)(param_2 + 0x50) >> 1);
        }
        if (param_1 != 0) {
          *(undefined2 *)(*(int *)(param_2 + 0x3c) + *(int *)(param_2 + 0x50) + param_1) = 0;
        }
      }
      if (*(uint *)(param_2 + 0x5c) == 0) {
        *(uint *)(param_2 + 0x5c) = ((*(uint *)(param_2 + 0x2c) >> 1) + 1) * 2;
      }
      else {
        FUN_c027438c((undefined2 *)(*(int *)(param_2 + 0x48) + param_1),
                     *(undefined1 **)(param_2 + 0x28),*(uint *)(param_2 + 0x5c) >> 1);
      }
      if (*(uint *)(param_2 + 0x58) == 0) {
        *(uint *)(param_2 + 0x58) = ((*(uint *)(param_2 + 0x24) >> 1) + 1) * 2;
      }
      else {
        FUN_c027438c((undefined2 *)(*(int *)(param_2 + 0x44) + param_1),
                     *(undefined1 **)(param_2 + 0x20),*(uint *)(param_2 + 0x58) >> 1);
      }
    }
    if (*(uint *)(param_2 + 0x54) == 0) {
      *(uint *)(param_2 + 0x54) = ((*(uint *)(param_2 + 0x1c) >> 1) + 1) * 2;
    }
    else {
      FUN_c027438c((undefined2 *)(*(int *)(param_2 + 0x40) + param_1),
                   *(undefined1 **)(param_2 + 0x18),*(uint *)(param_2 + 0x54) >> 1);
    }
  }
  else {
    if (*(uint *)(param_2 + 0x4c) == 0) {
      *(int *)(param_2 + 0x4c) = (*(int *)(param_2 + 0xc) + 1) * 2;
    }
    else {
      FUN_c02743fc(param_3,(ushort *)(*(int *)(param_2 + 0x38) + param_1),*(byte **)(param_2 + 8),
                   *(uint *)(param_2 + 0x4c) >> 1);
    }
    if (*(uint *)(param_2 + 0x5c) == 0) {
      *(int *)(param_2 + 0x5c) = (*(int *)(param_2 + 0x2c) + 1) * 2;
    }
    else {
      FUN_c02743fc(param_3,(ushort *)(*(int *)(param_2 + 0x48) + param_1),*(byte **)(param_2 + 0x28)
                   ,*(uint *)(param_2 + 0x5c) >> 1);
    }
    if (*(uint *)(param_2 + 0x58) == 0) {
      *(int *)(param_2 + 0x58) = (*(int *)(param_2 + 0x24) + 1) * 2;
    }
    else {
      FUN_c02743fc(param_3,(ushort *)(*(int *)(param_2 + 0x44) + param_1),*(byte **)(param_2 + 0x20)
                   ,*(uint *)(param_2 + 0x58) >> 1);
    }
    if (*(uint *)(param_2 + 0x54) == 0) {
      *(int *)(param_2 + 0x54) = (*(int *)(param_2 + 0x1c) + 1) * 2;
    }
    else {
      FUN_c02743fc(param_3,(ushort *)(*(int *)(param_2 + 0x40) + param_1),*(byte **)(param_2 + 0x18)
                   ,*(uint *)(param_2 + 0x54) >> 1);
    }
  }
  return 1;
}



/* c0267904 FUN_c0267904 */

undefined4 FUN_c0267904(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    if ((uint)(param_4 << 1) <= *(uint *)(param_3 + 0x2c)) {
      uVar2 = 0;
      if (param_4 + -1 < 1) {
        return 1;
      }
      do {
        puVar1 = (undefined1 *)(uVar2 * 2 + *(int *)(param_3 + 0x28) + param_2);
        if (CONCAT11(puVar1[2],puVar1[3]) < CONCAT11(*puVar1,puVar1[1])) {
          return 0;
        }
        uVar2 = uVar2 + 1 & 0xffff;
      } while ((int)uVar2 < param_4 + -1);
      return 1;
    }
  }
  else if ((uint)(param_4 << 2) <= *(uint *)(param_3 + 0x2c)) {
    if (0 < param_4 + -1) {
      uVar2 = 0;
      do {
        puVar1 = (undefined1 *)(uVar2 * 4 + *(int *)(param_3 + 0x28) + param_2);
        if (CONCAT31(CONCAT21(CONCAT11(puVar1[4],puVar1[5]),puVar1[6]),puVar1[7]) <
            CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3])) {
          return 0;
        }
        uVar2 = uVar2 + 1 & 0xffff;
      } while ((int)uVar2 < param_4 + -1);
    }
    return 1;
  }
  return 0;
}



/* c0267a48 FUN_c0267a48 */

undefined4 FUN_c0267a48(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((7 < param_2) &&
     (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5)),
                        *(undefined1 *)(param_1 + 6)),*(undefined1 *)(param_1 + 7)) *
      (uint)CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3)) + 8 <= param_2)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c0267ab4 FUN_c0267ab4 */

/* Boundary evidence: original MIPS .pdata c0267ab4..c0267b6b. Semantic name remains unreviewed. */

void FUN_c0267ab4(int param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = EngLpkInstalled();
  if ((((iVar1 != 0) && (param_1 != 0)) && (uVar2 = param_2 & 0xff00, 0xefff < uVar2)) &&
     (((uVar2 < 0xf300 && (0xb0 < *(byte *)(param_1 + 0x3e))) && (*(byte *)(param_1 + 0x3e) < 0xb6))
     )) {
    *param_3 = 7;
    *param_4 = uVar2;
  }
  return;
}



/* c0267b6c FUN_c0267b6c */

/* Boundary evidence: original MIPS .pdata c0267b6c..c0267cb3. Semantic name remains unreviewed. */

undefined4 FUN_c0267b6c(int param_1,ushort *param_2,short *param_3,int *param_4,int *param_5)

{
  int iVar1;
  
  if (*param_2 == 0x5c) {
    *param_2 = 0x5d;
    *(short *)*param_4 = *(short *)*param_4 + 1;
    *(short *)(*param_4 + 2) = *(short *)(*param_4 + 2) + -1;
  }
  else if (*param_3 == 0x5c) {
    *param_3 = 0x5b;
    *(short *)(*param_4 + 2) = *(short *)(*param_4 + 2) + -1;
  }
  else {
    ((short *)*param_4)[1] = 0x5c - *(short *)*param_4;
    iVar1 = FUN_c02742d8(param_1,*(ushort *)(*param_4 + 2),*param_2,0,(int *)0x0,(uint *)*param_5);
    if (iVar1 != 0) {
      return 0;
    }
    *param_5 = (uint)*(ushort *)(*param_4 + 2) * 4 + *param_5;
    *param_4 = *param_4 + 8;
    *param_2 = 0x5d;
    *(undefined2 *)*param_4 = 0x5d;
    *(ushort *)(*param_4 + 2) = (*param_3 - *param_2) + 1;
    *(int *)(*param_4 + 4) = *param_5;
  }
  return 1;
}



/* c0267cb4 FUN_c0267cb4 */

/* Boundary evidence: original MIPS .pdata c0267cb4..c0268043. Semantic name remains unreviewed. */

int FUN_c0267cb4(int param_1,int param_2,int *param_3,uint *param_4)

{
  uint *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  ushort uVar10;
  ushort *puVar11;
  ushort local_50;
  ushort local_4e;
  ushort local_4c;
  uint *local_48;
  ushort *local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  
  puVar11 = (ushort *)0x0;
  puVar9 = (ushort *)0x0;
  uVar10 = 0;
  uVar8 = (uint)((*param_4 & 4) != 0);
  iVar7 = ((uVar8 + param_4[1] + 2) * 2 + param_4[3]) * 4;
  if (param_3 != (int *)0x0) {
    local_40 = (uint)((*param_4 & 3) == 3);
    local_38 = (int)((uint)*(byte *)(param_1 + 6) << 8) >> 1 | (uint)(*(byte *)(param_1 + 7) >> 1);
    local_34 = param_1 + 0xe;
    local_30 = local_38 * 2 + local_34 + 2;
    if ((*(short *)(local_38 * 2 + local_30 + -2) == -1) && (1 < local_38)) {
      local_38 = local_38 + 0xffff & 0xffff;
    }
    local_44 = (ushort *)(param_3 + 4);
    local_48 = (uint *)(param_3 + (uVar8 + param_4[1] + 2) * 2);
    uVar4 = 0;
    local_4c = 0;
    local_3c = param_2;
    if (local_38 != 0) {
      do {
        puVar5 = (undefined1 *)(uVar4 * 2 + local_30);
        puVar6 = (undefined1 *)(uVar4 * 2 + local_34);
        local_4e = CONCAT11(*puVar5,puVar5[1]);
        local_50 = CONCAT11(*puVar6,puVar6[1]);
        if (local_40 != 0) {
          if ((uVar10 < 0xb7) && (0xb7 < local_4e)) {
            *local_44 = 0xb7;
            local_44[1] = 1;
            *(uint **)(local_44 + 2) = local_48;
            local_48 = local_48 + 1;
            puVar11 = local_44;
            local_44 = local_44 + 4;
          }
          if ((local_4e < 0x221a) && (0x2218 < local_50)) {
            puVar9 = local_44;
          }
        }
        local_44[1] = (local_50 - local_4e) + 1;
        *local_44 = local_4e;
        *(uint **)(local_44 + 2) = local_48;
        if (((uVar8 == 0) || (0x5c < local_4e)) || (local_50 < 0x5c)) {
LAB_c0267f14:
          puVar2 = local_44;
          puVar1 = local_48;
          uVar10 = local_50;
          if ((local_4e != 0xffff) &&
             (iVar3 = FUN_c02742d8(local_3c,local_44[1],local_4e,0,(int *)0x0,local_48), iVar3 != 0)
             ) {
            return 0;
          }
          local_48 = puVar1 + puVar2[1];
          local_44 = puVar2 + 4;
        }
        else {
          iVar3 = FUN_c0267b6c(local_3c,&local_4e,(short *)&local_50,(int *)&local_44,
                               (int *)&local_48);
          if (iVar3 == 0) {
            return 0;
          }
          param_4[3] = param_4[3] - 1;
          uVar8 = 0;
          uVar10 = local_50;
          if (local_44[1] != 0) goto LAB_c0267f14;
        }
        local_4c = local_4c + 1;
        uVar4 = (uint)local_4c;
      } while (uVar4 < local_38);
    }
    if (((local_40 != 0) && (puVar11 != (ushort *)0x0)) && (puVar9 != (ushort *)0x0)) {
      *(undefined4 *)((0xb7 - (uint)*puVar11) * 4 + *(int *)(puVar11 + 2)) =
           *(undefined4 *)((0x2219 - (uint)*puVar9) * 4 + *(int *)(puVar9 + 2));
    }
    *param_3 = iVar7;
    param_3[1] = 4;
    param_3[2] = param_4[3];
    param_3[3] = (int)local_44 - (int)(param_3 + 4) >> 3;
  }
  return iVar7;
}



/* c0268044 FUN_c0268044 */

/* Boundary evidence: original MIPS .pdata c0268044..c02681d3. Semantic name remains unreviewed. */

undefined4 FUN_c0268044(uint param_1,int param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0;
  iVar6 = param_1 * 6 + param_3 + 0x10;
  if ((((param_1 == 0) || (0x1ffffffd < param_1)) || (param_1 * -8 - 0x11 < param_3)) ||
     (param_4 < param_1 * 2 + iVar6)) {
LAB_c0268074:
    uVar1 = 0;
  }
  else {
    puVar4 = (undefined1 *)((param_1 + 8) * 2 + param_2 + param_3);
    puVar2 = (undefined1 *)(param_2 + param_3 + 0xe);
    puVar3 = (undefined1 *)(param_1 * 6 + param_2 + param_3 + 0x10);
    if ((*(short *)(puVar4 + param_1 * 2 + -2) == -1) && (1 < param_1)) {
      param_1 = param_1 + 0xffff & 0xffff;
    }
    uVar7 = 0;
    if (param_1 != 0) {
      do {
        uVar5 = (uint)CONCAT11(*puVar4,puVar4[1]);
        if (uVar5 < uVar8) {
          uVar5 = uVar8 + 1;
        }
        uVar8 = (uint)CONCAT11(*puVar2,puVar2[1]);
        if ((CONCAT11(*puVar3,puVar3[1]) != 0) &&
           (param_4 < ((uVar7 - uVar5) + uVar8 + 1) * 2 + (uint)CONCAT11(*puVar3,puVar3[1]) + iVar6)
           ) goto LAB_c0268074;
        uVar7 = uVar7 + 1 & 0xffff;
        puVar4 = puVar4 + 2;
        puVar2 = puVar2 + 2;
        puVar3 = puVar3 + 2;
      } while (uVar7 < param_1);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c02681d4 FUN_c02681d4 */

/* Boundary evidence: original MIPS .pdata c02681d4..c02684af. Semantic name remains unreviewed. */

undefined4
FUN_c02681d4(short *param_1,undefined4 *param_2,uint *param_3,uint *param_4,short param_5,
            uint *param_6,uint param_7,uint param_8,int param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  
  if (param_7 - param_8 < 0xe) {
    return 0;
  }
  if (*param_1 != 0x400) {
    return 0;
  }
  if ((*(byte *)((int)param_1 + 7) & 1) != 0) {
    return 0;
  }
  uVar2 = (uint)(ushort)(CONCAT11((char)param_1[3],*(byte *)((int)param_1 + 7)) >> 1);
  if (param_7 - param_8 < (uVar2 + 2) * 8) {
    return 0;
  }
  psVar7 = param_1 + 7;
  psVar6 = psVar7 + uVar2;
  if (psVar6[-1] != -1) {
    return 0;
  }
  iVar1 = FUN_c0268044(uVar2,param_9,param_8,param_7);
  if (iVar1 == 0) {
    return 0;
  }
  psVar8 = psVar6 + 1;
  *param_2 = 3;
  uVar4 = (uint)CONCAT11((char)*psVar8,*(undefined1 *)((int)psVar6 + 3));
  *param_3 = uVar4;
  *param_6 = uVar4;
  if (param_5 == 0x100) {
    if ((*param_3 & 0xff00) != 0xf000) {
LAB_c0268350:
      *param_3 = 0;
      goto LAB_c0268354;
    }
  }
  else {
    uVar4 = *param_3 & 0xff00;
    if ((uVar4 == 0) || (uVar4 == 0xe000)) goto LAB_c0268350;
    if (uVar4 != 0xf000) {
      *param_3 = *param_3 - 0x20;
      goto LAB_c0268354;
    }
  }
  *param_3 = 0xf000;
LAB_c0268354:
  if ((psVar8[uVar2 - 1] == -1) && (1 < uVar2)) {
    uVar2 = uVar2 + 0xffff & 0xffff;
    psVar6 = psVar6 + -1;
  }
  *param_4 = 0;
  param_4[1] = uVar2;
  param_4[3] = 0;
  uVar4 = 0;
  while( true ) {
    if (psVar6 <= psVar7) {
      if ((*param_4 & 3) == 3) {
        param_4[1] = uVar2 + 1;
        param_4[3] = param_4[3] + 1;
      }
      return 1;
    }
    uVar5 = (uint)CONCAT11((char)*psVar8,*(undefined1 *)((int)psVar8 + 1));
    uVar3 = (uint)CONCAT11((char)*psVar7,*(undefined1 *)((int)psVar7 + 1));
    if ((uVar3 < uVar5) || (uVar5 < uVar4)) break;
    param_4[3] = (param_4[3] - uVar5) + uVar3 + 1;
    if ((uVar4 < 0xb7) && (0xb7 < uVar5)) {
      *param_4 = *param_4 | 2;
    }
    if ((uVar5 < 0x221a) && (0x2218 < uVar3)) {
      *param_4 = *param_4 | 1;
    }
    psVar8 = psVar8 + 1;
    psVar7 = psVar7 + 1;
    uVar4 = uVar3;
  }
  return 0;
}



/* c02684b0 FUN_c02684b0 */

undefined4 FUN_c02684b0(char *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_2 < param_3 + 0x106U) || (*param_1 != '\0' || param_1[1] != '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if (CONCAT11(param_1[2],param_1[3]) < 0x109) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* c026850c FUN_c026850c */

undefined4 FUN_c026850c(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_1 == 0x66637474) &&
     (0xffff < CONCAT31(CONCAT21(CONCAT11((char)param_1[1],*(undefined1 *)((int)param_1 + 5)),
                                 *(undefined1 *)((int)param_1 + 6)),
                        *(undefined1 *)((int)param_1 + 7)))) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c0268564 FUN_c0268564 */

/* WARNING: Removing unreachable block (ram,0xc0268878) */
/* Boundary evidence: original MIPS .pdata c0268564..c02688bf. Semantic name remains unreviewed. */

void FUN_c0268564(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  size_t *_Src;
  uint uVar11;
  uint uVar12;
  undefined4 *local_40;
  int local_3c;
  
  if (param_2 != 0) {
    uVar5 = 0;
    uVar11 = 0;
    iVar6 = -0x7ff8fdea;
    uVar12 = 0xffffffff;
    if (*(uint *)(param_1 + 0xc) != 0) {
      piVar7 = (int *)(param_1 + 0x20);
      do {
        if (*piVar7 == 1) {
          uVar4 = uVar5 + (*(int *)(piVar7[1] + 0x128) + 7U & 0xfffffff8) + 0xf0;
          bVar1 = uVar5 <= uVar4;
          iVar2 = iVar6;
          uVar5 = uVar12;
          if (bVar1) {
            iVar2 = 0;
            uVar5 = uVar4;
          }
          if (iVar2 < 0) {
            return;
          }
        }
        uVar11 = uVar11 + 1;
        piVar7 = piVar7 + 3;
      } while (uVar11 < *(uint *)(param_1 + 0xc));
    }
    uVar10 = *(int *)(param_1 + 8) * 4 + 0x13U & 0xfffffff8;
    uVar4 = uVar5 + uVar10;
    uVar11 = uVar12;
    iVar2 = iVar6;
    if (uVar5 <= uVar4) {
      iVar2 = 0;
      uVar11 = uVar4;
    }
    if (-1 < iVar2) {
      uVar5 = uVar11;
      uVar4 = 0;
      if ((*(uint *)(*(int *)(param_1 + 0x24) + 0xf8) & 0x100) != 0) {
        uVar4 = uVar11 + (**(int **)(param_1 + 0x18) + 7U & 0xfffffff8);
        uVar5 = uVar12;
        if (uVar11 <= uVar4) {
          iVar6 = 0;
          uVar5 = uVar4;
        }
        uVar4 = uVar11;
        if (iVar6 < 0) {
          return;
        }
      }
      puVar3 = (undefined4 *)EngFntCacheAlloc(param_2,uVar5);
      if (puVar3 != (undefined4 *)0x0) {
        iVar6 = 0;
        local_3c = 0;
        *puVar3 = param_3;
        puVar3[1] = *(undefined4 *)(param_1 + 8);
        puVar3[2] = uVar4;
        local_40 = (undefined4 *)((int)puVar3 + uVar10);
        puVar8 = local_40;
        for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0xc); uVar5 = uVar5 + 1) {
          iVar2 = *(int *)((uVar5 + 3) * 0xc + param_1);
          puVar9 = puVar8;
          if (*(int *)(uVar5 * 0xc + param_1 + 0x20) == 1) {
            puVar3[iVar6 + 3] = (int)puVar8 - (int)puVar3;
            memcpy(puVar8 + 1,(void *)(iVar2 + 0x3c),0xec);
            _Src = (size_t *)(iVar2 + 0x128);
            memcpy(local_40 + 0x3c,_Src,*_Src);
            puVar9 = (undefined4 *)((int)local_40 + (*_Src + 7 & 0xfffffff8) + 0xf0);
            if (*(int *)(iVar2 + 0xe8) == 2) {
              if (*(undefined1 **)(iVar2 + 4) == &LAB_c0276880) {
                *puVar8 = 2;
              }
              else {
                if (*(undefined1 **)(iVar2 + 4) != &LAB_c02768fc) goto LAB_c0268820;
                *puVar8 = 1;
              }
            }
            else {
LAB_c0268820:
              *puVar8 = 0;
            }
            iVar6 = local_3c + 1;
            local_40 = puVar9;
            local_3c = iVar6;
          }
          puVar8 = puVar9;
        }
        if (puVar3[2] != 0) {
          memcpy((void *)(puVar3[2] + (int)puVar3),*(size_t **)(param_1 + 0x18),
                 **(size_t **)(param_1 + 0x18));
        }
      }
    }
  }
  return;
}



/* c02688c0 FUN_c02688c0 */

/* Boundary evidence: original MIPS .pdata c02688c0..c02688cb. Semantic name remains unreviewed. */

undefined4 FUN_c02688c0(void)

{
  return 1;
}



/* c02688cc FUN_c02688cc */

/* Boundary evidence: original MIPS .pdata c02688cc..c02689bf. Semantic name remains unreviewed. */

void FUN_c02688cc(size_t *param_1,void *param_2)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  
  memcpy(param_2,param_1,*param_1);
  psVar1 = (short *)(*(int *)((int)param_2 + 0x10) + (int)param_2);
  psVar2 = (short *)(param_1[4] + (int)param_1);
  *psVar1 = 0x40;
  while( true ) {
    psVar1 = psVar1 + 1;
    if (*psVar2 == 0) break;
    *psVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  }
  *psVar1 = 0;
  psVar1 = (short *)(*(int *)((int)param_2 + 8) + (int)param_2);
  psVar2 = (short *)(param_1[2] + (int)param_1);
  *psVar1 = 0x40;
  while( true ) {
    psVar3 = psVar1 + 1;
    if (*psVar2 == 0) break;
    *psVar3 = *psVar2;
    psVar2 = psVar2 + 1;
    psVar1 = psVar3;
  }
  *psVar3 = 0;
  if ((*(uint *)((int)param_2 + 0x30) & 0x8000000) != 0) {
    psVar1[2] = 0x40;
    psVar1 = psVar1 + 3;
    while( true ) {
      psVar2 = psVar2 + 1;
      if (*psVar2 == 0) break;
      *psVar1 = *psVar2;
      psVar1 = psVar1 + 1;
    }
    *psVar1 = 0;
    psVar1[1] = 0;
  }
  return;
}



/* c02689c0 FUN_c02689c0 */

/* WARNING: Removing unreachable block (ram,0xc0268bac) */
/* WARNING: Removing unreachable block (ram,0xc0268be4) */
/* Boundary evidence: original MIPS .pdata c02689c0..c0268c37. Semantic name remains unreviewed. */

undefined4
FUN_c02689c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,int *param_5,
            undefined4 param_6)

{
  void *_Dst;
  undefined1 *puVar1;
  void *pvVar2;
  size_t *_Src;
  
  pvVar2 = (void *)0x0;
  *param_4 = 0;
  if ((param_5[0x3c] + 0x128U < 0x128) ||
     (_Dst = (void *)EngAllocMem(0,param_5[0x3c] + 0x128U,0x64667454,param_4,0), _Dst == (void *)0x0
     )) {
    return 0;
  }
  *param_4 = (int)_Dst;
  memset(_Dst,0,0x128);
  *(undefined4 *)((int)_Dst + 0x14) = 0;
  *(undefined4 *)((int)_Dst + 0x18) = 0;
  *(undefined4 *)((int)_Dst + 0x1c) = param_1;
  *(undefined4 *)((int)_Dst + 0x20) = param_2;
  *(undefined4 *)((int)_Dst + 0x24) = param_3;
  *(undefined4 *)((int)_Dst + 0x28) = 0;
  *(undefined4 *)((int)_Dst + 0xc) = 0;
  *(undefined4 *)((int)_Dst + 0x10) = 0;
  *(undefined4 *)((int)_Dst + 8) = 0;
  *(undefined4 *)((int)_Dst + 0x30) = 0;
  *(undefined4 *)((int)_Dst + 0x2c) = 0;
  _Src = (size_t *)(param_5 + 0x3c);
  if ((param_5[0x2c] == 2) &&
     (pvVar2 = (void *)EngAllocMem(0,*_Src + 7 & 0xfffffff8,0x64667454), pvVar2 == (void *)0x0)) {
    if (*param_4 == 0) {
      return 0;
    }
    EngFreeMem();
    *param_4 = 0;
    return 0;
  }
  memcpy((void *)((int)_Dst + 0x3c),param_5 + 1,0xec);
  memcpy((size_t *)((int)_Dst + 0x128),_Src,*_Src);
  if (pvVar2 != (void *)0x0) {
    FUN_c02688cc((size_t *)((int)_Dst + 0x128),pvVar2);
    *(void **)((int)_Dst + 8) = pvVar2;
    if (*param_5 == 1) {
      puVar1 = &LAB_c02768fc;
    }
    else {
      if (*param_5 == 2) {
        *(undefined1 **)((int)_Dst + 4) = &LAB_c0276880;
        goto LAB_c0268b88;
      }
      puVar1 = &LAB_c028c3e8;
    }
    *(undefined1 **)((int)_Dst + 4) = puVar1;
  }
LAB_c0268b88:
  *(undefined4 *)((int)_Dst + 0x34) = 0;
  *(undefined4 *)((int)_Dst + 0x38) = 0;
  return 1;
}



/* c0268c38 FUN_c0268c38 */

/* Boundary evidence: original MIPS .pdata c0268c38..c0268c43. Semantic name remains unreviewed. */

undefined4 FUN_c0268c38(void)

{
  return 1;
}



/* c0268c44 FUN_c0268c44 */

/* Boundary evidence: original MIPS .pdata c0268c44..c0268d2b. Semantic name remains unreviewed. */

void FUN_c0268c44(int param_1,int param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  short sVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  
  puVar4 = (ushort *)(*(int *)(param_2 + 0x30) + 0x10);
  puVar5 = puVar4 + *(int *)(*(int *)(param_2 + 0x30) + 0xc) * 4;
  for (; puVar4 < puVar5; puVar4 = puVar4 + 4) {
    uVar2 = *puVar4;
    sVar3 = puVar4[1] + uVar2;
    puVar6 = (undefined4 *)((*(int *)(puVar4 + 2) - param_1) + *(int *)(param_2 + 0x30));
    *(undefined4 **)(puVar4 + 2) = puVar6;
    for (; uVar2 <= (ushort)(sVar3 - 1U); uVar2 = uVar2 + 1) {
      uVar1 = (**(code **)(param_2 + 4))(param_2,*puVar6);
      *puVar6 = uVar1;
      puVar6 = puVar6 + 1;
    }
  }
  return;
}



/* c0268d2c FUN_c0268d2c */

/* Boundary evidence: original MIPS .pdata c0268d2c..c0268d8f. Semantic name remains unreviewed. */

void FUN_c0268d2c(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    iVar1 = *(int *)(param_1 + 0x34) + -1;
    *(int *)(param_1 + 0x34) = iVar1;
    if (iVar1 == 0) {
      EngFreeMem(*(undefined4 *)(param_1 + 0x2c));
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x38) + -1;
    *(int *)(param_1 + 0x38) = iVar1;
    if (iVar1 == 0) {
      EngFreeMem(*(undefined4 *)(param_1 + 0x30));
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  return;
}



/* c0268d90 FUN_c0268d90 */

/* Boundary evidence: original MIPS .pdata c0268d90..c0268f37. Semantic name remains unreviewed. */

undefined4
FUN_c0268d90(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4,uint param_5,
            int param_6)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  if ((((param_4 == 0x200) || (param_4 == 0x300)) || (param_4 == 0x400)) || (param_4 == 0x500)) {
    *param_2 = 5;
    *param_3 = 0;
    param_3[1] = 0;
    param_3[3] = 0;
    if (0x20d < param_5 - param_6) {
      uVar3 = 0;
      do {
        puVar1 = (undefined1 *)(uVar3 * 2 + param_1 + 6);
        uVar2 = (uint)CONCAT11(*puVar1,puVar1[1]);
        if (uVar4 < uVar2) {
          uVar4 = uVar2;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < 0x100);
      if (uVar4 <= (param_5 - param_6) - 0x20e) {
        uVar4 = 0;
        while( true ) {
          puVar1 = (undefined1 *)(uVar4 * 2 + param_1 + 6);
          uVar3 = (uint)CONCAT11(*puVar1,puVar1[1]);
          puVar1 = (undefined1 *)(uVar3 + param_1 + 0x206);
          if (uVar3 == 0) {
            if (uVar4 < CONCAT11(*puVar1,puVar1[1])) {
              return 0;
            }
            uVar2 = (uVar4 - CONCAT11(*puVar1,puVar1[1])) + 1;
          }
          else {
            uVar2 = (uint)CONCAT11(puVar1[2],puVar1[3]);
          }
          if (param_5 < uVar2 * 2 + (uint)CONCAT11(puVar1[6],puVar1[7]) + uVar3 + param_6 + 0x20c)
          break;
          uVar4 = uVar4 + 1 & 0xffff;
          if (0xff < uVar4) {
            return 1;
          }
        }
        return 0;
      }
    }
  }
  return 0;
}



/* c0268f38 FUN_c0268f38 */

/* Boundary evidence: original MIPS .pdata c0268f38..c02690b7. Semantic name remains unreviewed. */

undefined4
FUN_c0268f38(short *param_1,undefined4 *param_2,undefined4 *param_3,int param_4,uint param_5,
            uint param_6,int param_7)

{
  ushort uVar1;
  ushort uVar2;
  short *psVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  short *psVar7;
  short *psVar8;
  
  if (((((param_4 == 0x200) || (param_4 == 0x300)) || (param_4 == 0x400)) || (param_4 == 0x500)) &&
     (((*param_1 == 0x400 && (7 < param_5)) && ((*(byte *)((int)param_1 + 7) & 1) == 0)))) {
    uVar6 = (uint)(ushort)(CONCAT11((char)param_1[3],*(byte *)((int)param_1 + 7)) >> 1);
    iVar5 = FUN_c0268044(uVar6,param_7,param_6,param_5);
    if (iVar5 != 0) {
      psVar7 = param_1 + 7;
      psVar8 = psVar7 + uVar6;
      if (psVar8[-1] == -1) {
        *param_2 = 6;
        *param_3 = 0;
        param_3[1] = 0;
        param_3[3] = 0;
        psVar3 = psVar8;
        uVar4 = 0;
        while( true ) {
          if (psVar8 <= psVar7) {
            return 1;
          }
          uVar1 = CONCAT11((char)psVar3[1],*(undefined1 *)((int)psVar3 + 3));
          uVar2 = CONCAT11((char)*psVar7,*(undefined1 *)((int)psVar7 + 1));
          if ((uVar2 < uVar1) || (uVar1 < uVar4)) break;
          psVar7 = psVar7 + 1;
          psVar3 = psVar3 + 1;
          uVar4 = uVar2;
        }
      }
    }
  }
  return 0;
}



/* c02690b8 FUN_c02690b8 */

/* Boundary evidence: original MIPS .pdata c02690b8..c02693a7. Semantic name remains unreviewed. */

size_t FUN_c02690b8(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  bool bVar1;
  undefined2 uVar2;
  int *_Dst;
  int iVar3;
  size_t *_Dst_00;
  int *piVar4;
  size_t *psVar5;
  size_t *psVar6;
  size_t _Size;
  uint uVar7;
  uint uVar8;
  int iVar9;
  size_t sVar10;
  ushort local_30 [4];
  
  bVar1 = false;
  _Dst = (int *)EngAllocMem(0,0xbfff4,0x64667454);
  if (_Dst == (int *)0x0) {
LAB_c0269120:
    if (param_4 == (undefined4 *)0x0) {
      return 0;
    }
  }
  else {
    memset(_Dst,0,0xbfff4);
    uVar2 = FUN_c0266e7c((uint)*(ushort *)(param_1 + 8));
    uVar7 = 0;
    if (param_3 != 0) {
      do {
        iVar9 = uVar7 * 8 + param_2;
        iVar3 = EngMultiByteToWideChar(uVar2,local_30,4,iVar9,2);
        if (iVar3 == -1) {
          EngFreeMem(_Dst);
          goto LAB_c0269120;
        }
        if (_Dst[(uint)local_30[0] * 3] == 0) {
          _Dst[(uint)local_30[0] * 3] = 1;
          *(ushort *)(_Dst + (uint)local_30[0] * 3 + 1) = local_30[0];
          _Dst[(uint)local_30[0] * 3 + 2] = *(int *)(iVar9 + 4);
        }
        uVar7 = uVar7 + 1 & 0xffff;
      } while (uVar7 < param_3);
    }
    uVar8 = 0;
    sVar10 = 0;
    uVar7 = 0;
    do {
      if (_Dst[uVar7 * 3] == 0) {
        if (bVar1) {
          bVar1 = false;
          uVar8 = uVar8 + 1;
        }
      }
      else {
        bVar1 = true;
        sVar10 = sVar10 + 1;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 0xffff);
    if (bVar1) {
      uVar8 = uVar8 + 1;
    }
    _Size = ((uVar8 + 2) * 2 + sVar10) * 4;
    if (param_4 == (undefined4 *)0x0) {
      return _Size;
    }
    _Dst_00 = (size_t *)EngAllocMem(0,_Size,0x64667454);
    if (_Dst_00 != (size_t *)0x0) {
      memset(_Dst_00,0,_Size);
      *_Dst_00 = _Size;
      _Dst_00[1] = 0;
      _Dst_00[3] = uVar8;
      _Dst_00[2] = sVar10;
      psVar5 = _Dst_00 + 4;
      psVar6 = _Dst_00 + (uVar8 + 2) * 2;
      if (uVar8 != 0) {
        iVar3 = *_Dst;
        uVar7 = 0;
        piVar4 = _Dst;
        do {
          while (iVar3 == 0) {
            iVar3 = piVar4[3];
            piVar4 = piVar4 + 3;
          }
          *(short *)psVar5 = (short)piVar4[1];
          *(undefined2 *)((int)psVar5 + 2) = 0;
          psVar5[1] = (size_t)psVar6;
          for (; *piVar4 != 0; piVar4 = piVar4 + 3) {
            *(short *)((int)psVar5 + 2) = *(short *)((int)psVar5 + 2) + 1;
            *psVar6 = piVar4[2];
            psVar6 = psVar6 + 1;
          }
          uVar7 = uVar7 + 1 & 0xffff;
          psVar5 = psVar5 + 2;
          iVar3 = 0;
        } while (uVar7 < uVar8);
      }
      EngFreeMem(_Dst);
      *param_4 = _Dst_00;
      return _Size;
    }
    EngFreeMem(_Dst);
  }
  *param_4 = 0;
  return 0;
}



/* c02693a8 FUN_c02693a8 */

/* Boundary evidence: original MIPS .pdata c02693a8..c026967b. Semantic name remains unreviewed. */

size_t FUN_c02693a8(int param_1,undefined4 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  size_t sVar16;
  int iVar17;
  
  iVar17 = param_1 + 6;
  puVar15 = (undefined1 *)(param_1 + 0x206);
  uVar14 = (uint)CONCAT11(*(undefined1 *)(param_1 + 0x208),*(undefined1 *)(param_1 + 0x209));
  uVar13 = 0;
  do {
    puVar8 = (undefined1 *)(uVar13 * 2 + iVar17);
    uVar11 = (uint)CONCAT11(*puVar8,puVar8[1]);
    if (uVar11 != 0) {
      uVar14 = CONCAT11(puVar15[uVar11 + 2],puVar15[uVar11 + 3]) + uVar14;
    }
    uVar13 = uVar13 + 1 & 0xffff;
  } while (uVar13 < 0x100);
  iVar7 = EngAllocMem(0,uVar14 << 3,0x64667454);
  if (iVar7 == 0) {
    *param_2 = 0;
    sVar16 = 0;
  }
  else {
    uVar13 = 0;
    uVar14 = 0;
    do {
      puVar8 = (undefined1 *)(uVar14 * 2 + iVar17);
      if ((CONCAT11(*puVar8,puVar8[1]) == 0) &&
         (uVar11 = (uint)CONCAT11(puVar15[(uVar14 - CONCAT11(*puVar15,*(undefined1 *)
                                                                       (param_1 + 0x207))) * 2 +
                                          CONCAT11(*(undefined1 *)(param_1 + 0x20c),
                                                   *(undefined1 *)(param_1 + 0x20d)) + 6],
                                  (puVar15 +
                                  (uVar14 - CONCAT11(*puVar15,*(undefined1 *)(param_1 + 0x207))) * 2
                                  + CONCAT11(*(undefined1 *)(param_1 + 0x20c),
                                             *(undefined1 *)(param_1 + 0x20d)) + 6)[1]), uVar11 != 0
         )) {
        puVar8 = (undefined1 *)(uVar13 * 8 + iVar7);
        *puVar8 = (char)uVar14;
        puVar8[1] = 0;
        *(uint *)(puVar8 + 4) = uVar11;
        uVar13 = uVar13 + 1 & 0xffff;
      }
      uVar14 = uVar14 + 1 & 0xffff;
    } while (uVar14 < 0x100);
    uVar14 = 0;
    do {
      puVar8 = (undefined1 *)(uVar14 * 2 + iVar17);
      uVar11 = (uint)CONCAT11(*puVar8,puVar8[1]);
      if (uVar11 != 0) {
        puVar8 = puVar15 + uVar11;
        uVar1 = puVar8[2];
        uVar2 = puVar8[3];
        uVar9 = (uint)CONCAT11(*puVar8,puVar8[1]);
        uVar3 = puVar8[4];
        uVar4 = puVar8[6];
        uVar5 = puVar8[5];
        uVar6 = puVar8[7];
        for (uVar11 = uVar9; uVar11 < CONCAT11(uVar1,uVar2) + uVar9; uVar11 = uVar11 + 1 & 0xffff) {
          uVar12 = (uint)CONCAT11(puVar8[(uVar11 - uVar9) * 2 + CONCAT11(uVar4,uVar6) + 6],
                                  (puVar8 + (uVar11 - uVar9) * 2 + CONCAT11(uVar4,uVar6) + 6)[1]);
          if (uVar12 != 0) {
            puVar10 = (undefined1 *)(uVar13 * 8 + iVar7);
            *puVar10 = (char)uVar14;
            puVar10[1] = (char)uVar11;
            puVar10[2] = 0;
            *(uint *)(puVar10 + 4) = CONCAT11(uVar3,uVar5) + uVar12;
            uVar13 = uVar13 + 1 & 0xffff;
          }
        }
      }
      uVar14 = uVar14 + 1 & 0xffff;
    } while (uVar14 < 0x100);
    sVar16 = FUN_c02690b8(param_3,iVar7,uVar13,param_2);
    EngFreeMem(iVar7);
  }
  return sVar16;
}



/* c026967c FUN_c026967c */

/* WARNING: Removing unreachable block (ram,0xc02696cc) */
/* WARNING: Removing unreachable block (ram,0xc02698e8) */
/* Boundary evidence: original MIPS .pdata c026967c..c02699d7. Semantic name remains unreviewed. */

size_t FUN_c026967c(int param_1,uint param_2,undefined4 *param_3,int param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  size_t sVar12;
  short *psVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  ushort *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  
  uVar9 = (int)(uint)CONCAT11(*(undefined1 *)(param_1 + 6),*(undefined1 *)(param_1 + 7)) >> 1;
  iVar6 = uVar9 * 2;
  puVar14 = (undefined1 *)(param_1 + 0xe);
  puVar17 = puVar14 + iVar6 + 2;
  uVar7 = uVar9;
  if (*(short *)(puVar14 + iVar6 + -2) != -1) {
    uVar7 = uVar9 + 0xfffe;
    while (uVar7 = uVar7 & 0xffff, *(short *)(puVar14 + uVar7 * 2) != -1) {
      uVar7 = uVar7 + 0xffff;
    }
    uVar7 = uVar7 + 1 & 0xffff;
  }
  iVar11 = uVar7 - 1;
  uVar4 = 0;
  uVar7 = 0;
  puVar15 = puVar14;
  puVar18 = puVar17;
  if (0 < iVar11) {
    do {
      uVar8 = (uint)CONCAT11(*puVar18,puVar18[1]);
      if ((uVar8 <= CONCAT11(*puVar15,puVar15[1])) && (uVar8 != 0xffff)) {
        uVar4 = (CONCAT11(*puVar15,puVar15[1]) - uVar8) + uVar4 + 1 & 0xffff;
      }
      uVar7 = uVar7 + 1 & 0xffff;
      puVar15 = puVar15 + 2;
      puVar18 = puVar18 + 2;
    } while ((int)uVar7 < iVar11);
  }
  iVar3 = EngAllocMem(0,uVar4 << 3,0x64667454);
  if (iVar3 == 0) {
    *param_3 = 0;
    sVar12 = 0;
  }
  else {
    uVar7 = 0;
    if (0 < iVar11) {
      uVar4 = 0;
      puVar18 = (undefined1 *)(param_1 + 0xf);
      puVar15 = puVar17;
      do {
        uVar1 = puVar15[(int)puVar14 - (int)puVar17];
        uVar2 = *puVar18;
        uVar8 = (uint)CONCAT11(*puVar15,puVar15[1]);
        if ((uVar8 <= CONCAT11(uVar1,uVar2)) && (uVar8 != 0xffff)) {
          psVar13 = (short *)(puVar17 + uVar4 * 2 + uVar9 * 4);
          puVar5 = puVar17 + uVar4 * 2 + iVar6;
          uVar10 = uVar8;
          do {
            puVar16 = (ushort *)(uVar7 * 8 + iVar3);
            puVar16[0] = 0;
            puVar16[1] = 0;
            if (uVar8 < 0x100) {
              *puVar16 = (ushort)uVar10;
            }
            else {
              *puVar16 = (ushort)(uVar10 << 8) | (ushort)(uVar10 >> 8);
            }
            if (*psVar13 == 0) {
              *(uint *)(puVar16 + 2) = CONCAT11(*puVar5,puVar5[1]) + uVar10 & 0xffff;
            }
            else {
              *(uint *)(puVar16 + 2) =
                   (uint)CONCAT11(puVar17[((((int)(uint)CONCAT11((char)*psVar13,
                                                                 *(undefined1 *)((int)psVar13 + 1))
                                            >> 1) - uVar8) + uVar10 + uVar4) * 2 + uVar9 * 4],
                                  (puVar17 +
                                  ((((int)(uint)CONCAT11((char)*psVar13,
                                                         *(undefined1 *)((int)psVar13 + 1)) >> 1) -
                                   uVar8) + uVar10 + uVar4) * 2 + uVar9 * 4)[1]) +
                   (uint)CONCAT11(*puVar5,puVar5[1]) & 0xffff;
            }
            if (param_2 <= *(uint *)(puVar16 + 2)) {
              puVar16[2] = 0;
              puVar16[3] = 0;
            }
            uVar10 = uVar10 + 1 & 0xffff;
            uVar7 = uVar7 + 1 & 0xffff;
          } while (uVar10 <= CONCAT11(uVar1,uVar2));
        }
        uVar4 = uVar4 + 1 & 0xffff;
        puVar15 = puVar15 + 2;
        puVar18 = puVar18 + 2;
      } while ((int)uVar4 < iVar11);
    }
    sVar12 = FUN_c02690b8(param_4,iVar3,uVar7,param_3);
    EngFreeMem(iVar3);
  }
  return sVar12;
}



/* c02699d8 FUN_c02699d8 */

/* Boundary evidence: original MIPS .pdata c02699d8..c0269aef. Semantic name remains unreviewed. */

int FUN_c02699d8(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  
  *param_2 = 0;
  if (param_4 == 1) {
    uVar3 = 10000;
  }
  else {
    if (param_4 != 2) {
      if (param_4 != 4) {
        return 0;
      }
      piVar1 = FUN_c02623e4();
      goto LAB_c0269a58;
    }
    uVar3 = 0;
  }
  piVar1 = (int *)EngComputeGlyphSet(uVar3,0,0x100);
LAB_c0269a58:
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uVar5 = 0;
  piVar1[1] = 4;
  if (piVar1[3] != 0) {
    piVar4 = piVar1 + 5;
    do {
      iVar2 = FUN_c02742d8(param_1,*(ushort *)((int)piVar4 + -2),0,param_3,(int *)*piVar4,
                           (uint *)*piVar4);
      if (iVar2 != 0) {
        EngFreeMem(piVar1);
        return 0;
      }
      uVar5 = uVar5 + 1;
      piVar4 = piVar4 + 2;
    } while (uVar5 < (uint)piVar1[3]);
  }
  *param_2 = piVar1;
  return *piVar1;
}



/* c0269af0 FUN_c0269af0 */

/* Boundary evidence: original MIPS .pdata c0269af0..c0269dc3. Semantic name remains unreviewed. */

int FUN_c0269af0(int param_1,int *param_2,ushort param_3)

{
  short sVar1;
  int *piVar2;
  ushort uVar3;
  undefined2 *puVar4;
  int iVar5;
  uint *puVar6;
  undefined2 *puVar7;
  int *piVar8;
  int iVar9;
  ushort *puVar10;
  int iVar11;
  ushort local_40 [2];
  int local_3c;
  int local_38;
  uint *local_34;
  int *local_30;
  
  *param_2 = 0;
  iVar5 = 0;
  iVar9 = 0;
  uVar3 = param_3 & 0xff00;
  if (uVar3 == 0xf000) {
    puVar7 = (undefined2 *)&UNK_c0261320;
  }
  else if (uVar3 == 0xf100) {
    puVar7 = (undefined2 *)&UNK_c026110c;
  }
  else {
    if (uVar3 != 0xf200) {
      return 0;
    }
    puVar7 = &DAT_c0261218;
  }
  sVar1 = puVar7[1];
  puVar4 = puVar7;
  while (sVar1 != 0) {
    iVar5 = (uint)(ushort)puVar4[1] + iVar5;
    puVar4 = puVar4 + (ushort)puVar4[1] + 2;
    iVar9 = iVar9 + 1;
    sVar1 = puVar4[1];
  }
  iVar11 = ((iVar9 + 3) * 2 + iVar5 + 0x100) * 4;
  local_38 = param_1;
  local_30 = param_2;
  piVar2 = (int *)EngAllocMem(0,iVar11,0x64667454);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  piVar2[1] = 4;
  puVar6 = (uint *)(piVar2 + (iVar9 + 3) * 2);
  piVar2[3] = iVar9 + 1;
  local_34 = puVar6 + iVar5;
  *piVar2 = iVar11;
  piVar2[2] = iVar5 + 0x100;
  memset(local_34,0,0x400);
  local_3c = 0;
  if (0 < iVar9) {
    piVar8 = piVar2 + 4;
    do {
      *(undefined2 *)piVar8 = *puVar7;
      *(undefined2 *)((int)piVar8 + 2) = puVar7[1];
      piVar8[1] = (int)puVar6;
      iVar5 = 0;
      if (puVar7[1] != 0) {
        puVar10 = puVar7 + 2;
        do {
          iVar11 = FUN_c0274268(local_38,1,*puVar10 + param_3,(short *)0x0,local_40);
          if (iVar11 != 0) goto LAB_c0269db4;
          iVar5 = iVar5 + 1;
          *puVar6 = (uint)local_40[0];
          local_34[*puVar10] = (uint)local_40[0];
          puVar6 = puVar6 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar5 < (int)(uint)(ushort)puVar7[1]);
      }
      local_3c = local_3c + 1;
      puVar7 = puVar7 + (ushort)puVar7[1] + 2;
      piVar8 = piVar8 + 2;
    } while (local_3c < iVar9);
  }
  *(ushort *)(piVar2 + (iVar9 + 2) * 2) = param_3;
  *(undefined2 *)((int)piVar2 + iVar9 * 8 + 0x12) = 0x100;
  piVar2[iVar9 * 2 + 5] = (int)puVar6;
  iVar5 = 0;
  do {
    if (*puVar6 == 0) {
      iVar9 = FUN_c0274268(local_38,1,(short)iVar5 + param_3,(short *)0x0,local_40);
      if (iVar9 != 0) {
LAB_c0269db4:
        EngFreeMem(piVar2);
        return 0;
      }
      *puVar6 = (uint)local_40[0];
    }
    iVar5 = iVar5 + 1;
    puVar6 = puVar6 + 1;
    if (0xff < iVar5) {
      iVar5 = *piVar2;
      *local_30 = (int)piVar2;
      return iVar5;
    }
  } while( true );
}



/* c0269dc4 FUN_c0269dc4 */

undefined4 FUN_c0269dc4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  puVar4 = (ushort *)(param_2 + 0x10);
  puVar5 = (ushort *)((*(int *)(param_2 + 0xc) + 1) * 8 + param_2);
  do {
    iVar2 = (int)puVar5 - (int)puVar4 >> 3;
    iVar1 = (int)puVar5 - (int)puVar4 >> 4;
    if (iVar2 < 0) {
      iVar1 = iVar2 + 1 >> 1;
    }
    puVar3 = puVar4 + iVar1 * 4;
    if ((int)(param_1 - (uint)*puVar3) < 0) {
      puVar5 = puVar3 + -4;
    }
    else {
      if ((int)(param_1 - (uint)*puVar3) < (int)(uint)puVar3[1]) {
        if (*(int *)(puVar3 + 2) == 0) {
          return 0;
        }
        return 1;
      }
      puVar4 = puVar3 + 4;
    }
  } while (puVar4 <= puVar5);
  return 0;
}



/* c0269e54 FUN_c0269e54 */

undefined4 FUN_c0269e54(undefined1 *param_1,int param_2,uint param_3,uint *param_4,uint *param_5)

{
  byte bVar1;
  uint uVar2;
  
  if ((3 < param_3) && (CONCAT11(*param_1,param_1[1]) == 0)) {
    *param_4 = (uint)CONCAT11(param_1[2],param_1[3]);
    bVar1 = param_1[7];
    uVar2 = CONCAT31(CONCAT21(CONCAT11(param_1[4],param_1[5]),param_1[6]),bVar1);
    *param_5 = uVar2;
    if ((*(int *)(param_2 + 0x1e8) + 2U <= uVar2) && (((bVar1 & 3) == 0 && (uVar2 != 0)))) {
      if (uVar2 == 0) {
        trap(0x1c00);
      }
      if (*param_4 <= (param_3 - 4) / uVar2) {
        return 1;
      }
    }
  }
  return 0;
}



/* c0269f14 FUN_c0269f14 */

bool FUN_c0269f14(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (param_2 < param_3) {
    uVar1 = (param_2 + 1) * 4;
  }
  else {
    uVar1 = (param_2 + param_3 + 1) * 2;
  }
  return uVar1 <= param_1;
}



/* c0269f50 FUN_c0269f50 */

bool FUN_c0269f50(uint param_1)

{
  return 0x23 < param_1;
}



/* c0269f68 FUN_c0269f68 */

undefined4 FUN_c0269f68(int param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((5 < param_2) &&
     (uVar1 = CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5)), *param_3 = uVar1,
     (uVar1 + 1) * 6 <= param_2)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0269fb0 FUN_c0269fb0 */

bool FUN_c0269fb0(uint param_1,int param_2)

{
  return param_2 + 4U <= param_1;
}



/* c0269fcc FUN_c0269fcc */

bool FUN_c0269fcc(uint param_1,int param_2,int param_3)

{
  return param_3 * 6 + param_2 + 4U <= param_1;
}



/* c0269ff8 FUN_c0269ff8 */

bool FUN_c0269ff8(int param_1,uint param_2)

{
  return *(int *)(param_1 + 0x1e8) + 4U <= param_2;
}



/* c026a018 FUN_c026a018 */

undefined4 FUN_c026a018(int param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((3 < param_2) &&
     (uVar1 = CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3)), *param_3 = uVar1,
     (uVar1 + 1) * 4 <= param_2)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* c026a058 FUN_c026a058 */

undefined4 FUN_c026a058(int param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((7 < param_2) &&
     (uVar2 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5)),
                                *(undefined1 *)(param_1 + 6)),*(undefined1 *)(param_1 + 7)),
     *param_3 = uVar2, uVar2 <= (param_2 - 8) / 0x30)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c026a0b4 FUN_c026a0b4 */

undefined4 FUN_c026a0b4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((0x4b < *(uint *)(param_1 + 0xb8)) &&
     (iVar2 = *(int *)(param_1 + 0xb4) + *(int *)(param_1 + 0x20),
     (CONCAT11(*(undefined1 *)(iVar2 + 0x44),*(undefined1 *)(iVar2 + 0x45)) + 0x13) * 4 <=
     *(uint *)(param_1 + 0xb8))) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c026a104 FUN_c026a104 */

/* Boundary evidence: original MIPS .pdata c026a104..c026a47b. Semantic name remains unreviewed. */

undefined4 FUN_c026a104(int param_1,uint *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar12 = *(uint *)(param_1 + 0xc0);
  *param_2 = 0;
  iVar5 = *(int *)(param_1 + 0xbc);
  iVar3 = *(int *)(param_1 + 0x20) + iVar5;
  if (9 < uVar12) {
    uVar11 = (uint)CONCAT11(*(undefined1 *)(iVar3 + 6),*(undefined1 *)(iVar3 + 7));
    uVar10 = (uint)CONCAT11(*(undefined1 *)(iVar3 + 8),*(undefined1 *)(iVar3 + 9));
    puVar4 = (undefined1 *)(uVar11 + iVar3);
    puVar6 = (undefined1 *)(uVar10 + iVar3);
    if ((((CONCAT11(*(undefined1 *)(iVar3 + 4),*(undefined1 *)(iVar3 + 5)) + 10 <= uVar12) &&
         (uVar11 + 8 <= uVar12)) && (uVar10 + 4 <= uVar12)) &&
       ((uVar7 = (uint)CONCAT11(*puVar4,puVar4[1]), uVar7 * 6 + uVar11 + 2 <= uVar12 &&
        (iVar9 = 0, uVar7 != 0)))) {
      piVar8 = (int *)(puVar4 + 2);
      do {
        if (*piVar8 == 0x74726576) {
          if (CONCAT11(puVar4[iVar9 * 6 + 6],puVar4[iVar9 * 6 + 7]) == 0) {
            return 0;
          }
          iVar9 = uVar11 + CONCAT11(puVar4[iVar9 * 6 + 6],puVar4[iVar9 * 6 + 7]);
          if (uVar12 < iVar9 + 6U) {
            return 0;
          }
          iVar3 = iVar3 + iVar9;
          if (CONCAT11(*(undefined1 *)(iVar3 + 2),*(undefined1 *)(iVar3 + 3)) != 1) {
            return 0;
          }
          uVar11 = (uint)CONCAT11(*(undefined1 *)(iVar3 + 4),*(undefined1 *)(iVar3 + 5));
          if (CONCAT11(*puVar6,puVar6[1]) < uVar11) {
            return 0;
          }
          if (uVar12 < (uVar11 + 2) * 2 + uVar10) {
            return 0;
          }
          uVar11 = (uint)CONCAT11(puVar6[uVar11 * 2 + 2],puVar6[uVar11 * 2 + 3]);
          if (-uVar11 - 1 < uVar10) {
            return 0;
          }
          if (0xfffffff7 < uVar10 + uVar11) {
            return 0;
          }
          if (uVar12 < uVar10 + uVar11 + 8) {
            return 0;
          }
          puVar6 = puVar6 + uVar11;
          if (CONCAT11(*puVar6,puVar6[1]) != 1) {
            return 0;
          }
          if (CONCAT11(puVar6[4],puVar6[5]) != 1) {
            return 0;
          }
          uVar1 = puVar6[6];
          uVar2 = puVar6[7];
          uVar11 = CONCAT11(uVar1,uVar2) + uVar11;
          *param_2 = 0xffffffff;
          if (uVar11 < CONCAT11(uVar1,uVar2)) {
            return 0;
          }
          uVar10 = uVar11 + uVar10;
          *param_2 = uVar11;
          *param_2 = 0xffffffff;
          if (uVar10 < uVar11) {
            return 0;
          }
          *param_2 = uVar10;
          if (0xfffffff9 < uVar10) {
            return 0;
          }
          if (uVar12 < uVar10 + 6) {
            return 0;
          }
          puVar4 = (undefined1 *)(*(int *)(param_1 + 0x20) + uVar10 + iVar5);
          if (CONCAT11(*puVar4,puVar4[1]) != 2) {
            return 0;
          }
          uVar11 = (uint)CONCAT11(puVar4[2],puVar4[3]);
          if (-uVar11 - 1 < uVar10) {
            return 0;
          }
          if (0xfffffffb < uVar10 + uVar11) {
            return 0;
          }
          if (uVar12 < uVar10 + uVar11 + 4) {
            return 0;
          }
          puVar4 = puVar4 + CONCAT11(puVar4[2],puVar4[3]);
          if (CONCAT11(*puVar4,puVar4[1]) != 1) {
            return 0;
          }
          if (uVar12 < (CONCAT11(puVar4[2],puVar4[3]) + 2) * 2 + uVar10 + uVar11) {
            return 0;
          }
          if (uVar12 < (CONCAT11(puVar4[2],puVar4[3]) + 3) * 2 + uVar10) {
            return 0;
          }
          *param_2 = uVar10 + iVar5;
          return 1;
        }
        iVar9 = iVar9 + 1;
        piVar8 = (int *)((int)piVar8 + 6);
      } while (iVar9 < (int)uVar7);
    }
  }
  return 0;
}



/* c026a47c FUN_c026a47c */

undefined4 FUN_c026a47c(int param_1,uint param_2,uint *param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 4;
  *param_3 = 0;
  if (3 < param_2) {
    iVar2 = param_1 + 4;
    for (sVar1 = CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3)); sVar1 != 0;
        sVar1 = sVar1 + -1) {
      if (param_2 < iVar4 + 4U) {
        sVar1 = 0;
        break;
      }
      if (*(char *)(iVar2 + 4) == '\0') break;
      uVar3 = (uint)CONCAT11(*(undefined1 *)(iVar2 + 2),*(undefined1 *)(iVar2 + 3));
      iVar2 = uVar3 + iVar2;
      iVar4 = uVar3 + iVar4;
    }
    if (((sVar1 != 0) && (iVar4 + 0xeU <= param_2)) &&
       (uVar3 = (uint)CONCAT11(*(undefined1 *)(iVar2 + 6),*(undefined1 *)(iVar2 + 7)),
       *param_3 = uVar3, (uVar3 + 4) * 4 + iVar4 <= param_2)) {
      return 1;
    }
  }
  return 0;
}



/* c026a554 FUN_c026a554 */

undefined4 FUN_c026a554(undefined1 *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x4e) {
    uVar1 = 0;
  }
  else if ((CONCAT11(*param_1,param_1[1]) == 0) || (uVar1 = 0, 0x55 < param_2)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c026a59c FUN_c026a59c */

/* Boundary evidence: original MIPS .pdata c026a59c..c026a6db. Semantic name remains unreviewed. */

undefined4 FUN_c026a59c(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  wchar_t *_Str1;
  
  if (((param_1 & 0x20000) == 0) && (*(short *)(param_2 + 0x104) == 0x200)) {
    iVar3 = *(int *)(param_2 + 0x2c);
    iVar1 = FUN_c0269dc4(0xff71,iVar3);
    if (((iVar1 == 0) ||
        (((iVar1 = FUN_c0269dc4(0xff72,iVar3), iVar1 == 0 ||
          (iVar1 = FUN_c0269dc4(0xff73,iVar3), iVar1 == 0)) ||
         (iVar1 = FUN_c0269dc4(0xff74,iVar3), iVar1 == 0)))) ||
       (iVar1 = FUN_c0269dc4(0xff75,iVar3), iVar1 == 0)) goto LAB_c026a644;
LAB_c026a63c:
    uVar2 = 1;
  }
  else {
LAB_c026a644:
    if ((param_1 & 0x40000) != 0) {
      _Str1 = (wchar_t *)(*(int *)(param_2 + 0x13c) + param_2 + 0x128);
      iVar1 = _wcsicmp(_Str1,L"Microsoft:MS Mincho:1995");
      if (((iVar1 == 0) || (iVar1 = _wcsicmp(_Str1,L"Microsoft:MS PMincho:1995"), iVar1 == 0)) ||
         ((iVar1 = _wcsicmp(_Str1,L"Microsoft:MS Gothic:1995"), iVar1 == 0 ||
          (iVar1 = _wcsicmp(_Str1,L"Microsoft:MS PGothic:1995"), iVar1 == 0)))) goto LAB_c026a63c;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c026a6dc FUN_c026a6dc */

/* Boundary evidence: original MIPS .pdata c026a6dc..c026a787. Semantic name remains unreviewed. */

undefined4 FUN_c026a6dc(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 1;
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    piVar2 = (int *)(param_1 + 0x20);
    do {
      if ((*piVar2 == 1) && (iVar1 = FUN_c0266f70(piVar2[1]), iVar1 == 0)) {
        uVar3 = 0;
      }
      uVar4 = uVar4 + 1;
      piVar2 = piVar2 + 3;
    } while (uVar4 < *(uint *)(param_1 + 0xc));
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    EngFreeMem();
  }
  EngFreeMem(param_1);
  return uVar3;
}



/* c026a788 FUN_c026a788 */

/* Boundary evidence: original MIPS .pdata c026a788..c026a9b3. Semantic name remains unreviewed. */

undefined4 FUN_c026a788(int *param_1,uint param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int local_28;
  int local_24;
  
  if ((((param_1 <= param_3) && (piVar2 = param_3 + 3, param_3 <= piVar2)) &&
      (piVar2 <= (int *)((int)param_1 + param_2))) && ((*param_3 == 0x100 || (*param_3 == 0x200))))
  {
    memset(param_4,0,0xa0);
    piVar3 = param_3 + ((int)((uint)*(byte *)(param_3 + 1) << 0x18) >> 0x10 |
                       (uint)*(byte *)((int)param_3 + 5)) * 4 + 3;
    if ((piVar2 <= piVar3) && (piVar3 <= (int *)((int)param_1 + param_2))) {
      for (; piVar2 < piVar3; piVar2 = piVar2 + 4) {
        uVar5 = CONCAT31(CONCAT21(CONCAT11((char)piVar2[2],*(undefined1 *)((int)piVar2 + 9)),
                                  *(undefined1 *)((int)piVar2 + 10)),
                         *(undefined1 *)((int)piVar2 + 0xb));
        uVar4 = CONCAT31(CONCAT21(CONCAT11((char)piVar2[3],*(undefined1 *)((int)piVar2 + 0xd)),
                                  *(undefined1 *)((int)piVar2 + 0xe)),
                         *(undefined1 *)((int)piVar2 + 0xf));
        if (param_2 < uVar5) {
          return 0;
        }
        if (param_2 - uVar5 < uVar4) {
          return 0;
        }
        iVar1 = FUN_c0267164(CONCAT31(CONCAT21(CONCAT11((char)*piVar2,
                                                        *(undefined1 *)((int)piVar2 + 1)),
                                               *(undefined1 *)((int)piVar2 + 2)),
                                      *(undefined1 *)((int)piVar2 + 3)),&local_28,&local_24);
        if (iVar1 != 0) {
          if (local_24 == 0) {
            param_4[(local_28 + 8) * 2] = uVar5;
            param_4[local_28 * 2 + 0x11] = uVar4;
            if (uVar4 == 0) {
              param_4[(local_28 + 8) * 2] = 0;
            }
          }
          else {
            param_4[local_28 * 2] = uVar5;
            (param_4 + local_28 * 2)[1] = uVar4;
          }
        }
      }
      iVar1 = 0;
      while ((*param_4 != 0 && (param_4[1] != 0))) {
        iVar1 = iVar1 + 1;
        param_4 = param_4 + 2;
        if (7 < iVar1) {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* c026a9b4 FUN_c026a9b4 */

/* Boundary evidence: original MIPS .pdata c026a9b4..c026b243. Semantic name remains unreviewed. */

undefined4
FUN_c026a9b4(uint param_1,int param_2,uint param_3,short param_4,ushort param_5,uint *param_6,
            uint *param_7,undefined4 *param_8)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  short sVar6;
  ushort uVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  uint uVar14;
  undefined1 *puVar15;
  uint uVar16;
  uint uVar17;
  undefined1 *puVar18;
  uint uVar19;
  undefined1 *puVar20;
  ushort local_60;
  short local_5e;
  undefined1 auStack_5c [4];
  char *local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  undefined1 *local_48;
  uint local_44;
  ushort *local_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  int local_34;
  uint local_30;
  
  uVar16 = *(uint *)(param_2 + 0x3c);
  puVar13 = (undefined1 *)(*(int *)(param_2 + 0x38) + param_1);
  puVar15 = puVar13 + uVar16;
  local_58 = (char *)0x0;
  local_40 = (ushort *)0x0;
  if ((uVar16 < 6) || ((param_3 != 0x300 && (param_3 != 0x100)))) {
    return 0;
  }
  local_5e = param_4;
  local_4c = param_3;
  local_34 = param_2;
  local_30 = param_1;
  memset(param_6,0,100);
  puVar20 = puVar13 + 6;
  *(short *)(param_6 + 0x18) = (short)param_3;
  *(short *)((int)param_6 + 0x62) = param_4;
  if (puVar20 < puVar13) {
    return 0;
  }
  if (puVar15 < puVar20) {
    return 0;
  }
  local_3c = puVar13 + CONCAT11(puVar13[4],puVar13[5]);
  puVar18 = puVar20 + (uint)CONCAT11(puVar13[2],puVar13[3]) * 0xc;
  if (puVar18 < puVar20) {
    return 0;
  }
  if (local_3c < puVar18) {
    return 0;
  }
  if (puVar15 < local_3c) {
    return 0;
  }
  local_44 = (int)puVar15 - (int)local_3c;
  bVar4 = false;
  bVar5 = false;
  local_48 = puVar18;
  local_38 = puVar20;
  EngGetCurrentCodePage(auStack_5c,&local_60);
  if (uVar16 < (uint)CONCAT11(puVar13[2],puVar13[3]) * 0xc + 6) {
    return 0;
  }
  local_54 = 0;
  local_50 = local_30;
  uVar16 = local_30;
  do {
    puVar13 = local_3c;
    if (bVar5) break;
    iVar8 = local_54;
    if (puVar20 < puVar18) {
      puVar15 = puVar20 + 8;
      do {
        puVar20 = local_38;
        if (bVar5) break;
        uVar19 = (uint)CONCAT11(puVar15[2],puVar15[3]);
        uVar17 = (uint)CONCAT11(*puVar15,puVar15[1]);
        if ((uVar17 != 0) && (uVar17 + uVar19 <= local_44)) {
          if (iVar8 == 0) {
            if (*(ushort *)(puVar15 + -4) != param_5) goto LAB_c026ac14;
LAB_c026ad80:
            uVar16 = 1;
          }
          else {
            if (iVar8 == 1) {
              if ((param_5 & 0xff00) == 0x400) {
                uVar14 = (uint)*(ushort *)(puVar15 + -4);
                uVar16 = FUN_c02673b8(uVar14);
                if (uVar16 == local_60) goto LAB_c026ac00;
LAB_c026accc:
                if ((uVar14 & 0xff00) != 0x900) goto LAB_c026ac14;
              }
              else if ((ushort)((ushort)(byte)puVar15[-3] << 8) != (param_5 & 0xff00)) {
LAB_c026ac14:
                uVar16 = 0;
                goto LAB_c026ac18;
              }
              goto LAB_c026ad80;
            }
            if (iVar8 == 2) {
              if ((param_5 & 0xff00) == 0x400) {
                uVar14 = (uint)*(ushort *)(puVar15 + -4);
                uVar16 = FUN_c02673b8(uVar14);
                if (uVar16 == local_60) goto LAB_c026accc;
LAB_c026ac00:
                if ((uVar14 & 0xff00) != 0x400) goto LAB_c026ac14;
              }
              else if (puVar15[-3] != '\t') goto LAB_c026ac14;
              goto LAB_c026ad80;
            }
            if (iVar8 == 3) goto LAB_c026ad80;
          }
LAB_c026ac18:
          if (((*(ushort *)(puVar15 + -8) == local_4c) && (*(short *)(puVar15 + -6) == local_5e)) &&
             (uVar16 != 0)) {
            sVar6 = *(short *)(puVar15 + -2);
            if (sVar6 == 0x100) {
              if (param_6[2] == 0) {
                param_6[2] = (uint)(puVar13 + uVar19);
                param_6[3] = uVar17;
                local_40 = (ushort *)(puVar15 + -8);
              }
            }
            else if (sVar6 == 0x200) {
              if (param_6[6] == 0) {
                param_6[6] = (uint)(puVar13 + uVar19);
                param_6[7] = uVar17;
              }
            }
            else if (sVar6 == 0x300) {
              if (param_6[8] == 0) {
                param_6[8] = (uint)(puVar13 + uVar19);
                param_6[9] = uVar17;
              }
            }
            else if (sVar6 == 0x400) {
              if (param_6[10] == 0) {
                param_6[10] = (uint)(puVar13 + uVar19);
                param_6[0xb] = uVar17;
              }
            }
            else if ((sVar6 == 0x500) && (local_58 == (char *)0x0)) {
              local_58 = puVar13 + uVar19;
              local_50 = uVar17;
            }
          }
          iVar8 = local_54;
          if (((param_6[2] == 0) || (param_6[6] == 0)) || ((param_6[8] == 0 || (param_6[10] == 0))))
          {
            bVar4 = false;
          }
          else {
            bVar4 = true;
            if (local_58 != (char *)0x0) {
              bVar5 = true;
              goto LAB_c026ae58;
            }
          }
          bVar5 = false;
        }
LAB_c026ae58:
        puVar9 = puVar15 + 4;
        puVar15 = puVar15 + 0xc;
        puVar18 = local_48;
        puVar20 = local_38;
      } while (puVar9 < local_48);
    }
    local_54 = iVar8 + 1;
  } while (local_54 < 4);
  uVar16 = local_4c;
  if (!bVar4) {
    return 0;
  }
  if ((local_4c == 0x300) && (puVar20 < local_48)) {
    puVar13 = puVar20 + 8;
    do {
      uVar1 = puVar13[2];
      uVar2 = puVar13[3];
      uVar17 = (uint)CONCAT11(*puVar13,puVar13[1]);
      if (((((uVar17 != 0) && (uVar17 + CONCAT11(uVar1,uVar2) <= local_44)) &&
           (*(short *)(puVar13 + -8) == 0x300)) &&
          ((*(short *)(puVar13 + -6) == local_5e && (*(short *)(puVar13 + -2) == 0x100)))) &&
         (local_40 != (ushort *)(puVar13 + -8))) {
        param_6[5] = uVar17;
        param_6[4] = (uint)(local_3c + CONCAT11(uVar1,uVar2));
        break;
      }
      puVar15 = puVar13 + 4;
      puVar13 = puVar13 + 0xc;
    } while (puVar15 < local_48);
  }
  iVar8 = FUN_c026756c(0,(int)param_6,0);
  if (iVar8 == 0) {
    return 0;
  }
  param_6[0xe] = 0xc4;
  uVar17 = param_6[0x13] + 0xc4;
  if (param_6[4] != 0) {
    param_6[0xf] = uVar17;
    uVar17 = param_6[0x14] + uVar17 + 4;
  }
  uVar19 = param_6[0x16] + uVar17 + 2;
  param_6[0x11] = uVar17 + 2;
  param_6[0x12] = uVar19;
  uVar17 = param_6[0x17] + uVar19 + 2;
  param_6[0x10] = uVar17;
  uVar17 = param_6[0x15] + uVar17 + 3 & 0xfffffffc;
  *param_7 = 0;
  if (local_58 != (char *)0x0) {
    if (uVar16 == 0x300) {
      uVar16 = local_50;
      if (0x48 < local_50) {
        uVar16 = 0x48;
      }
      iVar8 = memcmp(local_58,&DAT_c026108c,uVar16 - 2);
    }
    else {
      uVar16 = local_50;
      if (0x24 < local_50) {
        uVar16 = 0x24;
      }
      iVar8 = strncmp(local_58,"Converter: Windows Type 1 Installer",uVar16 - 1);
    }
    *param_7 = (uint)(iVar8 == 0);
  }
  uVar16 = local_30;
  iVar8 = local_34;
  uVar7 = FUN_c0266efc(local_30,local_34);
  if ((uVar7 & 0x21) == 0) {
    iVar10 = 3;
LAB_c026b0d4:
    param_6[1] = uVar17;
    uVar17 = iVar10 * 0x14 + uVar17 + 0xc;
  }
  else {
    if (((uVar7 & 0x21) == 1) || ((uVar7 & 0x21) == 0x20)) {
      iVar10 = 1;
      goto LAB_c026b0d4;
    }
    param_6[1] = 0;
  }
  uVar12 = 3;
  param_6[0xc] = uVar17;
  uVar19 = uVar17 + 0x10;
  if (*(int *)(iVar8 + 0x40) == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)(iVar8 + 0x40) + uVar16;
  }
  if (iVar8 != 0) {
    param_6[0xd] = uVar19;
    uVar19 = uVar17 + 0x28;
  }
  *param_8 = 0;
  uVar16 = param_6[9];
  if (uVar16 == 0x38) {
    pcVar11 = "Microsoft Sans Serif Regular";
    uVar16 = param_6[8];
    uVar17 = 0;
    do {
      cVar3 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      if (*(char *)(uVar16 + 1) != cVar3) goto LAB_c026b1f8;
      uVar17 = uVar17 + 1;
      uVar16 = uVar16 + 2;
    } while (uVar17 < 0x1c);
    *param_8 = 1;
  }
  else {
    if (uVar16 == 0x30) {
      pcVar11 = "Microsoft Tahoma Regular";
      uVar16 = param_6[8];
      uVar17 = 0;
      do {
        cVar3 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        if (*(char *)(uVar16 + 1) != cVar3) goto LAB_c026b1f8;
        uVar17 = uVar17 + 1;
        uVar16 = uVar16 + 2;
      } while (uVar17 < 0x18);
      uVar12 = 2;
    }
    else {
      if (uVar16 != 0x2a) goto LAB_c026b1f8;
      pcVar11 = "Microsoft Tahoma Bold";
      uVar16 = param_6[8];
      uVar17 = 0;
      do {
        cVar3 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        if (*(char *)(uVar16 + 1) != cVar3) goto LAB_c026b1f8;
        uVar17 = uVar17 + 1;
        uVar16 = uVar16 + 2;
      } while (uVar17 < 0x15);
    }
    *param_8 = uVar12;
  }
LAB_c026b1f8:
  *param_6 = uVar19 + 7 & 0xfffffff8;
  return 1;
}



/* c026b244 FUN_c026b244 */

/* Boundary evidence: original MIPS .pdata c026b244..c026b2fb. Semantic name remains unreviewed. */

size_t FUN_c026b244(short *param_1,uint *param_2)

{
  short sVar1;
  size_t sVar2;
  
  sVar1 = *param_1;
  if (sVar1 == 0) {
    sVar2 = 0x14;
  }
  else if ((sVar1 == 0x200) || (sVar1 != 0x400)) {
    sVar2 = 0;
  }
  else {
    sVar1 = (short)param_2[2];
    if ((sVar1 == 0x200) || (((sVar1 == 0x300 || (sVar1 == 0x400)) || (sVar1 == 0x500)))) {
      sVar2 = FUN_c026967c((int)param_1,0,(undefined4 *)0x0,(int)param_2);
    }
    else {
      sVar2 = FUN_c0267cb4((int)param_1,0,(int *)0x0,param_2);
    }
  }
  return sVar2;
}



/* c026b2fc FUN_c026b2fc */

/* Boundary evidence: original MIPS .pdata c026b2fc..c026b49b. Semantic name remains unreviewed. */

undefined4 FUN_c026b2fc(int param_1,short *param_2,int param_3,uint *param_4,int *param_5)

{
  size_t sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x6c);
  iVar3 = *(int *)(param_1 + 0x20);
  *param_5 = 0;
  iVar5 = *(int *)(param_1 + 0x108);
  iVar4 = iVar4 + iVar3;
  if (iVar5 == 1) {
    iVar3 = 1;
LAB_c026b458:
    iVar4 = 0;
  }
  else {
    if (iVar5 == 2) {
      iVar3 = 2;
      goto LAB_c026b458;
    }
    if (iVar5 == 3) {
      sVar1 = FUN_c026b244(param_2,param_4);
      piVar2 = (int *)EngAllocMem(0,sVar1,0x64667454);
      *param_5 = (int)piVar2;
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      iVar3 = FUN_c0267cb4((int)param_2,param_3,piVar2,param_4);
      if (iVar3 == 0) {
        EngFreeMem(*param_5);
        *param_5 = 0;
      }
      goto LAB_c026b468;
    }
    if (iVar5 != 4) {
      if (iVar5 == 5) {
        FUN_c02693a8((int)param_2,param_5,(int)param_4);
      }
      else if (iVar5 == 6) {
        FUN_c026967c((int)param_2,
                     (uint)CONCAT11(*(undefined1 *)(iVar4 + 4),*(undefined1 *)(iVar4 + 5)),param_5,
                     (int)param_4);
      }
      else {
        if (iVar5 != 7) {
          *param_5 = 0;
          return 0;
        }
        FUN_c0269af0(param_3,param_5,(ushort)*(undefined4 *)(param_1 + 0x10c));
      }
      goto LAB_c026b468;
    }
    iVar4 = *(int *)(param_1 + 0x10c);
    iVar3 = 4;
  }
  FUN_c02699d8(param_3,param_5,iVar4,iVar3);
LAB_c026b468:
  if (*param_5 == 0) {
    return 0;
  }
  return 1;
}



/* c026b49c FUN_c026b49c */

/* WARNING: Removing unreachable block (ram,0xc026b5c0) */
/* Boundary evidence: original MIPS .pdata c026b49c..c026b827. Semantic name remains unreviewed. */

int FUN_c026b49c(int *param_1,int param_2)

{
  void *_Dst;
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  uint local_598;
  int local_594;
  int local_590;
  int local_58c;
  undefined1 auStack_580 [4];
  undefined1 *local_57c;
  undefined4 local_578;
  undefined4 local_574;
  int local_558;
  undefined1 *local_554;
  code *local_550;
  int *local_54c;
  undefined2 local_548;
  undefined2 local_546;
  int aiStack_510 [50];
  undefined1 auStack_448 [1072];
  
  if (param_2 == 1) {
    if (param_1[0xd] != 0) {
      param_1[0xd] = param_1[0xd] + 1;
      return 1;
    }
  }
  else if (param_1[0xe] != 0) {
    param_1[0xe] = param_1[0xe] + 1;
    return 1;
  }
  if ((param_2 == 1) || ((undefined4 *)param_1[0xb] == (undefined4 *)0x0)) {
    if (param_1[6] != 0) {
      puVar3 = (undefined1 *)param_1[3];
LAB_c026b6ec:
      local_598 = param_1[0x46];
      local_594 = param_1[0x47];
      local_590 = param_1[0x48];
      local_58c = param_1[0x49];
      iVar1 = 0;
      piVar4 = param_1 + 0xb;
      if (param_2 != 1) {
        piVar4 = param_1 + 0xc;
      }
      iVar2 = FUN_c026b2fc((int)param_1,(short *)(param_1[0x3f] + param_1[8]),(int)puVar3,&local_598
                           ,piVar4);
      if (iVar2 != 0) {
        if (param_2 != 1) {
          FUN_c0268c44(param_1[0xc],(int)param_1);
        }
        iVar1 = 1;
      }
      if (iVar1 != 0) {
        if (param_2 != 1) {
          param_1[0xe] = 1;
          return iVar1;
        }
        param_1[0xd] = 1;
        return iVar1;
      }
      if (param_2 == 1) {
        if (param_1[0xb] == 0) {
          return 0;
        }
        EngFreeMem();
        param_1[0xb] = 0;
        return 0;
      }
      if (param_1[0xc] == 0) {
        return 0;
      }
      EngFreeMem();
      param_1[0xc] = 0;
      return 0;
    }
    param_1[8] = *(int *)(*param_1 + 0x10);
    param_1[9] = *(int *)(*param_1 + 0x14);
    iVar1 = FUN_c0271bc0((int)auStack_580,aiStack_510);
    if (iVar1 == 0) {
      local_57c = auStack_448;
      local_578 = 0;
      local_574 = 0;
      iVar1 = FUN_c0271c34((int)auStack_580,aiStack_510);
      if (iVar1 == 0) {
        local_558 = param_1[8];
        local_554 = &LAB_c0266ff0;
        local_550 = FUN_c02619ec;
        local_548 = CONCAT11(*(undefined1 *)((int)param_1 + 0x102),
                             *(undefined1 *)((int)param_1 + 0x103));
        local_546 = CONCAT11((char)param_1[0x41],*(undefined1 *)((int)param_1 + 0x105));
        local_54c = param_1;
        iVar1 = FUN_c0271cc4((int)auStack_580,(int)aiStack_510);
        if (iVar1 == 0) {
          puVar3 = auStack_580;
          goto LAB_c026b6ec;
        }
      }
    }
  }
  else {
    if (param_1[6] == 0) {
      param_1[8] = *(int *)(*param_1 + 0x10);
      param_1[9] = *(int *)(*param_1 + 0x14);
    }
    _Dst = (void *)EngAllocMem(0,*(undefined4 *)param_1[0xb],0x64667454);
    param_1[0xc] = (int)_Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,(size_t *)param_1[0xb],*(size_t *)param_1[0xb]);
      FUN_c0268c44(param_1[0xb],(int)param_1);
      param_1[0xe] = 1;
    }
    if (param_1[0xc] != 0) {
      return 1;
    }
  }
  return 0;
}



/* c026b828 FUN_c026b828 */

/* Boundary evidence: original MIPS .pdata c026b828..c026b833. Semantic name remains unreviewed. */

undefined4 FUN_c026b828(void)

{
  return 1;
}



/* c026b834 FUN_c026b834 */

/* Boundary evidence: original MIPS .pdata c026b834..c026b83f. Semantic name remains unreviewed. */

undefined4 FUN_c026b834(void)

{
  return 1;
}



/* c026b840 FUN_c026b840 */

/* Boundary evidence: original MIPS .pdata c026b840..c026b84b. Semantic name remains unreviewed. */

undefined4 FUN_c026b840(void)

{
  return 1;
}



/* c026b84c FUN_c026b84c */

undefined4 FUN_c026b84c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  
  if (param_3 == 0x100) {
    if ((*(int *)(param_2 + 0x68) == 0) ||
       (puVar3 = (undefined1 *)(*(int *)(param_2 + 0x68) + param_1),
       *(uint *)(param_2 + 0x6c) < 0x10)) {
      puVar3 = (undefined1 *)0x0;
    }
    if (puVar3 == (undefined1 *)0x0) {
      return 1;
    }
    if (CONCAT31(CONCAT21(CONCAT11(*puVar3,puVar3[1]),puVar3[2]),puVar3[3]) != 0x20000) {
      return 1;
    }
    if (*(uint *)(param_2 + 0x6c) < 0x22) {
      return 1;
    }
    uVar1 = (uint)CONCAT11(puVar3[0x20],puVar3[0x21]);
    if (*(uint *)(param_2 + 0x6c) < (uVar1 + 0x11) * 2) {
      return 1;
    }
    iVar2 = 0;
    if (uVar1 != 0) {
      pcVar4 = puVar3 + 0x22;
      do {
        if ((*pcVar4 != '\0') && ('\x01' < pcVar4[1])) break;
        iVar2 = iVar2 + 1;
        pcVar4 = pcVar4 + 2;
      } while (iVar2 < (int)uVar1);
    }
    if ((int)uVar1 <= iVar2) {
      return 1;
    }
  }
  return 0;
}



/* c026b964 FUN_c026b964 */

/* Boundary evidence: original MIPS .pdata c026b964..c026c07b. Semantic name remains unreviewed. */

void FUN_c026b964(int param_1,int param_2,undefined1 *param_3,int param_4,short *param_5,int param_6
                 )

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 *puVar6;
  ushort uVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  short local_30;
  ushort local_2e [3];
  
  iVar5 = *(int *)(param_1 + 0xfc);
  uVar12 = 0;
  if (param_5 == (short *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = CONCAT11((char)param_5[0x20],*(undefined1 *)((int)param_5 + 0x41));
  }
  cVar1 = *(char *)(param_2 + 0x2c);
  if ((((cVar1 == -0x80) || (cVar1 == -0x7f)) || (cVar1 == -0x78)) || (cVar1 == -0x7a)) {
    bVar2 = true;
    if (param_5 == (short *)0x0) goto LAB_c026bc60;
    if ((*param_5 != 0) &&
       (iVar3 = FUN_c026a59c(CONCAT31(CONCAT21(CONCAT11((char)param_5[0x27],
                                                        *(undefined1 *)((int)param_5 + 0x4f)),
                                               (char)param_5[0x28]),
                                      *(undefined1 *)((int)param_5 + 0x51)),param_1), iVar3 == 0))
    goto LAB_c026ba60;
    uVar12 = 1;
    *param_3 = *(undefined1 *)(param_2 + 0x2c);
  }
  else {
    bVar2 = false;
LAB_c026ba60:
    if ((param_5 == (short *)0x0) || ((char)*param_5 == '\0' && *(char *)((int)param_5 + 1) == '\0')
       ) {
LAB_c026bc60:
      if ((*(char *)(param_2 + 0xac) == '\x05') || (0xff < uVar7)) {
        if ((uVar7 < 0xf000) || ((*(ushort *)(param_2 + 0x34) & 0xff00) == 0)) {
          uVar4 = *(undefined1 *)(param_2 + 0x2c);
LAB_c026bff4:
          *param_3 = uVar4;
        }
        else {
          uVar7 = *(ushort *)(param_2 + 0x34) >> 8;
          uVar4 = 0xb1;
          if (uVar7 != 0xb1) {
            if (0xb1 < uVar7) {
              if (uVar7 < 0xb5) goto LAB_c026bcbc;
              if (uVar7 == 0xb5) goto LAB_c026bfd0;
            }
            goto LAB_c026bffc;
          }
LAB_c026bfd0:
          iVar5 = EngLpkInstalled();
          if (iVar5 == 0) {
            uVar4 = 2;
          }
          *(undefined1 *)(param_2 + 0x2c) = uVar4;
          *param_3 = uVar4;
        }
LAB_c026bff8:
        uVar12 = 1;
      }
      else if (iVar5 + param_4 != -6) {
        uVar7 = *(ushort *)(param_2 + 0x34);
        if ((uVar7 & 0xff00) != 0) {
          if ((0xb1 < uVar7 >> 8) && (uVar7 >> 8 < 0xb5)) {
LAB_c026bcbc:
            iVar5 = EngLpkInstalled();
            uVar4 = 0xb2;
            if (iVar5 == 0) {
              uVar4 = 2;
            }
            *(undefined1 *)(param_2 + 0x2c) = uVar4;
            goto LAB_c026bff4;
          }
          *param_3 = (char)(uVar7 >> 8);
          goto LAB_c026bff8;
        }
        *param_3 = 0;
        uVar12 = 1;
        iVar5 = FUN_c0274268(param_6,1,0x2206,(short *)0x0,&local_30);
        if ((iVar5 == 0) && (local_30 != 0)) {
          param_3[1] = 0x4d;
          uVar12 = 2;
        }
        local_30 = 0;
        FUN_c0274268(param_6,1,0x3cb,(short *)0x0,&local_30);
        iVar5 = FUN_c0274268(param_6,1,0x3a9,(short *)0x0,local_2e);
        if ((iVar5 == 0) && ((local_30 != 0 || (local_2e[0] != 0)))) {
          param_3[uVar12] = 0xa1;
          uVar12 = uVar12 + 1;
        }
        iVar5 = FUN_c0274268(param_6,1,0x130,(short *)0x0,&local_30);
        if ((iVar5 == 0) && (local_30 != 0)) {
          param_3[uVar12] = 0xa2;
          uVar12 = uVar12 + 1;
        }
        iVar5 = FUN_c0274268(param_6,1,0x5d0,(short *)0x0,&local_30);
        if ((iVar5 == 0) && (local_30 != 0)) {
          param_3[uVar12] = 0xb1;
          uVar12 = uVar12 + 1;
        }
        local_30 = 0;
        FUN_c0274268(param_6,1,0x451,(short *)0x0,&local_30);
        iVar5 = FUN_c0274268(param_6,1,0x42f,(short *)0x0,local_2e);
        if ((iVar5 == 0) && ((local_30 != 0 || (local_2e[0] != 0)))) {
          param_3[uVar12] = 0xcc;
          uVar12 = uVar12 + 1;
        }
        local_30 = 0;
        FUN_c0274268(param_6,1,0x148,(short *)0x0,&local_30);
        iVar5 = FUN_c0274268(param_6,1,0x10c,(short *)0x0,local_2e);
        if ((iVar5 == 0) && ((local_30 != 0 || (local_2e[0] != 0)))) {
          param_3[uVar12] = 0xee;
          uVar12 = uVar12 + 1;
        }
        iVar5 = FUN_c0274268(param_6,1,0x173,(short *)0x0,&local_30);
        if ((iVar5 == 0) && (local_30 != 0)) {
          param_3[uVar12] = 0xba;
          uVar12 = uVar12 + 1;
        }
        iVar5 = FUN_c0274268(param_6,1,0x2592,(short *)0x0,&local_30);
        if ((iVar5 == 0) && (local_30 != 0)) {
          param_3[uVar12] = 0xff;
          uVar12 = uVar12 + 1;
        }
      }
    }
    else {
      uVar13 = CONCAT31(CONCAT21(CONCAT11((char)param_5[0x27],*(undefined1 *)((int)param_5 + 0x4f)),
                                 (char)param_5[0x28]),*(undefined1 *)((int)param_5 + 0x51));
      if (((DAT_c029ac8c & uVar13) != 0) && ((DAT_c029ac8c & 0x10060) == 0)) {
        uVar12 = 1;
        *param_3 = DAT_c029ac88;
      }
      uVar11 = 0;
      if (DAT_c029a1c8 != 0) {
        iVar5 = 0;
        uVar9 = DAT_c029a1c8;
        uVar10 = DAT_c029ac8c;
        do {
          if ((((*(uint *)((int)&DAT_c029a20c + iVar5) != uVar10) || ((uVar10 & 0x10060) != 0)) &&
              ((*(uint *)((int)&DAT_c029a20c + iVar5) & uVar13) != 0)) && (uVar12 < 0x10)) {
            param_3[uVar12] = (char)*(undefined4 *)((int)&DAT_c029a1cc + iVar5);
            uVar12 = uVar12 + 1;
            uVar9 = DAT_c029a1c8;
            uVar10 = DAT_c029ac8c;
          }
          uVar11 = uVar11 + 1;
          iVar5 = iVar5 + 4;
        } while (uVar11 < uVar9);
      }
      uVar13 = CONCAT31(CONCAT21(CONCAT11((char)param_5[0x29],*(undefined1 *)((int)param_5 + 0x53)),
                                 (char)param_5[0x2a]),*(undefined1 *)((int)param_5 + 0x55));
      if (uVar13 != 0) {
        EngGetCurrentCodePage(local_2e,&local_30);
        uVar9 = 0;
        uVar11 = 0x80000000;
        do {
          if ((uint)local_2e[0] == *(uint *)((int)&DAT_c026144c + uVar9)) {
            if (((uVar11 & uVar13) != 0) && (uVar12 < 0x10)) {
              param_3[uVar12] = 0xff;
              uVar12 = uVar12 + 1;
            }
            break;
          }
          uVar9 = uVar9 + 4;
          uVar11 = uVar11 >> 1;
        } while (uVar9 < 0x40);
      }
      uVar13 = 0;
      if (uVar12 != 0) {
        do {
          if (param_3[uVar13] == *(char *)(param_2 + 0x2c)) break;
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar12);
      }
      if (uVar13 == uVar12) {
        if (uVar12 == 0) {
          *(undefined1 *)(param_2 + 0x2c) = 1;
        }
        else {
          *(undefined1 *)(param_2 + 0x2c) = *param_3;
        }
      }
    }
LAB_c026bffc:
    if (!bVar2) goto LAB_c026c020;
    if (0xf < uVar12) {
      return;
    }
  }
  param_3[uVar12] = 0xfe;
  uVar12 = uVar12 + 1;
LAB_c026c020:
  if (uVar12 < 0x10) {
    puVar8 = param_3 + uVar12;
    if (0x10 - uVar12 != 0) {
      puVar6 = puVar8 + (0x10 - uVar12);
      do {
        *puVar8 = 1;
        puVar8 = puVar8 + 1;
      } while (puVar8 != puVar6);
    }
  }
  return;
}



/* c026c07c FUN_c026c07c */

/* Boundary evidence: original MIPS .pdata c026c07c..c026c51b. Semantic name remains unreviewed. */

undefined4
FUN_c026c07c(int param_1,int *param_2,ushort *param_3,short *param_4,undefined4 *param_5,
            undefined4 *param_6,uint *param_7,uint *param_8)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  bool bVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  short *psVar8;
  short *psVar9;
  uint uVar10;
  undefined1 *puVar11;
  short *psVar12;
  uint uVar13;
  short *psVar14;
  uint local_40;
  int local_3c;
  ushort *local_38;
  short *local_34;
  short *local_30;
  
  uVar13 = param_2[1];
  puVar11 = (undefined1 *)(*param_2 + param_1);
  local_40 = 0;
  if (5 < uVar13) {
    uVar10 = (uint)CONCAT11(puVar11[2],puVar11[3]);
    uVar1 = *puVar11;
    uVar2 = puVar11[1];
    if (uVar10 <= uVar13 - 4 >> 3) {
      psVar12 = (short *)(puVar11 + 4);
      psVar8 = psVar12 + uVar10 * 4;
      *param_5 = 0;
      psVar14 = (short *)0x0;
      *param_7 = 0;
      if (((CONCAT11(uVar1,uVar2) == 0) && (uVar10 < 0x1f)) &&
         (local_3c = param_1, local_38 = param_3, local_34 = psVar8, local_30 = param_4,
         psVar12 < psVar8)) {
        do {
          uVar3 = CONCAT11((char)psVar12[1],*(undefined1 *)((int)psVar12 + 3));
          if (CONCAT11((char)*psVar12,*(undefined1 *)((int)psVar12 + 1)) == 3) {
            sVar5 = psVar12[2];
            uVar1 = *(undefined1 *)((int)psVar12 + 5);
            sVar6 = psVar12[3];
            uVar2 = *(undefined1 *)((int)psVar12 + 7);
            *param_3 = 0x300;
            uVar10 = CONCAT31(CONCAT21(CONCAT11((char)sVar5,uVar1),(char)sVar6),uVar2);
            *param_4 = psVar12[1];
            if (uVar10 <= uVar13 - 6) {
              psVar9 = (short *)(puVar11 + uVar10);
              *param_5 = psVar9;
              sVar5 = CONCAT11((char)*psVar9,*(undefined1 *)((int)psVar9 + 1));
              if (sVar5 == 2) {
                iVar7 = FUN_c0268d90((int)psVar9,param_6,param_8,(uint)(ushort)psVar12[1],uVar13,
                                     uVar10);
LAB_c026c2d0:
                param_3 = local_38;
                psVar8 = local_34;
                param_4 = local_30;
                if (iVar7 != 0) {
                  *(short *)(param_8 + 2) = psVar12[1];
                  if ((char)psVar12[1] == '\0' && *(char *)((int)psVar12 + 3) == '\0') {
                    if (param_2[0x10] == 0) {
                      iVar7 = 0;
                    }
                    else {
                      iVar7 = param_2[0x10] + local_3c;
                    }
                    bVar4 = false;
                    if (((iVar7 != 0) && (*(char *)(iVar7 + 0x3e) == '\0')) &&
                       (*(char *)(iVar7 + 0x20) == '\x05')) {
                      bVar4 = true;
                    }
                    if ((*param_7 == 0) && (!bVar4)) goto LAB_c026c4d4;
                  }
                  else {
                    if (psVar12[1] != 0x100) {
                      return 1;
                    }
                    if (*param_7 == 0) {
                      return 1;
                    }
                    if (param_2[0x10] == 0) {
                      iVar7 = 0;
                    }
                    else {
                      iVar7 = param_2[0x10] + local_3c;
                    }
                  }
                  *param_6 = 4;
LAB_c026c4d4:
                  FUN_c0267ab4(iVar7,local_40,param_6,param_7);
                  return 1;
                }
              }
              else if (sVar5 == 4) {
                if ((uVar3 < 2) || (5 < uVar3)) {
                  iVar7 = FUN_c02681d4(psVar9,param_6,param_7,param_8,psVar12[1],&local_40,uVar13,
                                       uVar10,(int)puVar11);
                }
                else {
                  iVar7 = FUN_c0268f38(psVar9,param_6,param_8,(uint)(ushort)psVar12[1],uVar13,uVar10
                                       ,(int)puVar11);
                }
                goto LAB_c026c2d0;
              }
              *param_5 = 0;
            }
          }
          else if ((*psVar12 == 0x100) &&
                  ((char)psVar12[1] == '\0' && *(char *)((int)psVar12 + 3) == '\0')) {
            psVar14 = psVar12;
          }
          psVar12 = psVar12 + 4;
        } while (psVar12 < psVar8);
        if (psVar14 != (short *)0x0) {
          uVar10 = CONCAT31(CONCAT21(CONCAT11((char)psVar14[2],*(undefined1 *)((int)psVar14 + 5)),
                                     (char)psVar14[3]),*(undefined1 *)((int)psVar14 + 7));
          *param_3 = 0x100;
          *param_4 = 0;
          if (uVar10 <= uVar13) {
            *param_5 = puVar11 + uVar10;
            iVar7 = FUN_c02684b0(puVar11 + uVar10,uVar13,uVar10);
            if (iVar7 != 0) {
              iVar7 = FUN_c026b84c(local_3c,(int)param_2,(uint)*local_38);
              if (iVar7 != 0) {
                *param_6 = 1;
                return 1;
              }
              *param_6 = 2;
              return 1;
            }
            *param_5 = 0;
          }
        }
      }
    }
  }
  return 0;
}



/* c026c51c FUN_c026c51c */

/* Boundary evidence: original MIPS .pdata c026c51c..c026d9db. Semantic name remains unreviewed. */

void FUN_c026c51c(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined2 extraout_var;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  ushort uVar9;
  int iVar10;
  short *psVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  undefined1 *puVar15;
  int *piVar16;
  short *psVar17;
  int iVar18;
  undefined4 *puVar19;
  byte bVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  short sVar24;
  ushort local_58 [2];
  int local_54;
  undefined4 *local_50;
  int local_4c;
  int local_48;
  int local_40;
  uint local_3c;
  int local_38;
  
  iVar21 = *(int *)(param_1 + 0x20);
  iVar18 = *(int *)(param_1 + 0x4c) + iVar21;
  iVar10 = *(int *)(param_1 + 0x6c) + iVar21;
  iVar23 = *(int *)(param_1 + 0x54) + iVar21;
  if ((*(int *)(param_1 + 0xa4) == 0) ||
     (iVar22 = *(int *)(param_1 + 0xa4) + iVar21, *(uint *)(param_1 + 0xa8) < 0x10)) {
    iVar22 = 0;
  }
  psVar17 = (short *)(*(int *)(param_1 + 0x7c) + iVar21);
  if (*(int *)(param_1 + 0x7c) == 0) {
    psVar17 = (short *)0x0;
  }
  *param_2 = *param_3;
  param_2[1] = 0xc;
  param_2[0x2e] = 0;
  param_2[0x30] = (uint)CONCAT11(*(undefined1 *)(iVar10 + 4),*(undefined1 *)(iVar10 + 5));
  local_50 = param_3;
  local_4c = iVar21;
  local_48 = param_4;
  FUN_c026756c((int)param_2,(int)param_3,(uint)*(ushort *)(param_1 + 0x106));
  param_2[2] = local_50[0xe];
  param_2[5] = local_50[0x11];
  param_2[4] = local_50[0x12];
  param_2[3] = local_50[0x10];
  param_2[0xc] = 0xa8071;
  if (*(int *)(param_1 + 0xdc) == 0) {
    iVar10 = FUN_c0267064(0x47495344,param_1,&local_54);
    if ((iVar10 != 0) && (local_54 != 0)) {
      param_2[0xc] = 0xe8071;
    }
  }
  else {
    iVar10 = *(int *)(param_1 + 0x20);
    puVar15 = (undefined1 *)
              (iVar10 + (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar10 + 8),
                                                    *(undefined1 *)(iVar10 + 9)),
                                           *(undefined1 *)(iVar10 + 10)),
                                  *(undefined1 *)(iVar10 + 0xb)) + 3) * 4);
    if (CONCAT31(CONCAT21(CONCAT11(*puVar15,puVar15[1]),puVar15[2]),puVar15[3]) == 0x44534947) {
      param_2[0xc] = 0xe8071;
    }
  }
  if (local_50[4] != 0) {
    param_2[0xc] = param_2[0xc] | 0x8000000;
  }
  if ((iVar22 != 0) &&
     (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar22 + 0xc),*(undefined1 *)(iVar22 + 0xd)),
                        *(undefined1 *)(iVar22 + 0xe)),*(undefined1 *)(iVar22 + 0xf)) != 0)) {
    uVar5 = param_2[0xc];
    param_2[0xc] = uVar5 | 0x400000;
    if ((-1 < (int)((int)((uint)*(byte *)(iVar18 + 0x24) << 0x18) >> 0x10 |
                   (uint)*(byte *)(iVar18 + 0x25))) &&
       (iVar10 = (uint)CONCAT11(*(undefined1 *)(iVar23 + 0x22),*(undefined1 *)(iVar23 + 0x23)) * 4 +
                 *(int *)(param_1 + 0x5c) + iVar21,
       (int)((int)((uint)*(byte *)(iVar18 + 0x28) << 0x18) >> 0x10 | (uint)*(byte *)(iVar18 + 0x29))
       <= (int)((int)((uint)*(byte *)(iVar10 + -4) << 0x18) >> 0x10 | (uint)*(byte *)(iVar10 + -3)))
       ) {
      param_2[0xc] = uVar5 | 0x20400000;
    }
  }
  param_2[10] = 0;
  param_2[7] = 0;
  uVar3 = FUN_c0266efc(iVar21,param_1 + 0x3c);
  uVar5 = CONCAT22(extraout_var,uVar3) >> 8;
  *(ushort *)(param_2 + 0xd) = uVar3;
  if (psVar17 == (short *)0x0) {
    uVar9 = 0;
  }
  else {
    uVar9 = *(byte *)((int)psVar17 + 9) & 0xe;
  }
  *(ushort *)((int)param_2 + 0x36) = uVar9;
  *(ushort *)(param_2 + 0xe) =
       CONCAT11(*(undefined1 *)(iVar18 + 0x12),*(undefined1 *)(iVar18 + 0x13));
  *(ushort *)((int)param_2 + 0x3a) =
       CONCAT11(*(undefined1 *)(iVar18 + 0x2e),*(undefined1 *)(iVar18 + 0x2f));
  *(ushort *)(param_2 + 0x10) = CONCAT11(*(undefined1 *)(iVar23 + 4),*(undefined1 *)(iVar23 + 5));
  *(ushort *)((int)param_2 + 0x42) =
       CONCAT11(*(undefined1 *)(iVar23 + 6),*(undefined1 *)(iVar23 + 7));
  *(ushort *)(param_2 + 0x11) = CONCAT11(*(undefined1 *)(iVar23 + 8),*(undefined1 *)(iVar23 + 9));
  if (psVar17 == (short *)0x0) {
    *(short *)((int)param_2 + 0x3e) = -*(short *)((int)param_2 + 0x42);
    *(undefined2 *)(param_2 + 0xf) = *(undefined2 *)(param_2 + 0x10);
    *(undefined2 *)((int)param_2 + 0x46) = *(undefined2 *)(param_2 + 0x10);
    *(short *)(param_2 + 0x12) = *(short *)((int)param_2 + 0x42);
    *(undefined2 *)((int)param_2 + 0x4a) = *(undefined2 *)(param_2 + 0x11);
  }
  else {
    *(ushort *)(param_2 + 0xf) = CONCAT11((char)psVar17[0x25],*(undefined1 *)((int)psVar17 + 0x4b));
    *(ushort *)((int)param_2 + 0x3e) =
         CONCAT11((char)psVar17[0x26],*(undefined1 *)((int)psVar17 + 0x4d));
    *(ushort *)((int)param_2 + 0x46) =
         CONCAT11((char)psVar17[0x22],*(undefined1 *)((int)psVar17 + 0x45));
    *(ushort *)(param_2 + 0x12) = CONCAT11((char)psVar17[0x23],*(undefined1 *)((int)psVar17 + 0x47))
    ;
    *(ushort *)((int)param_2 + 0x4a) =
         CONCAT11((char)psVar17[0x24],*(undefined1 *)((int)psVar17 + 0x49));
  }
  param_2[0x24] =
       (int)((uint)*(byte *)(iVar18 + 0x24) << 0x18) >> 0x10 | (uint)*(byte *)(iVar18 + 0x25);
  param_2[0x25] =
       (int)((uint)*(byte *)(iVar18 + 0x2a) << 0x18) >> 0x10 | (uint)*(byte *)(iVar18 + 0x2b);
  uVar12 = (int)((uint)*(byte *)(iVar18 + 0x28) << 0x18) >> 0x10 | (uint)*(byte *)(iVar18 + 0x29);
  param_2[0x26] = uVar12;
  iVar10 = (uVar12 - param_2[0x24]) * 0x10000;
  iVar21 = iVar10 >> 0x10;
  param_2[0x27] =
       (int)((uint)*(byte *)(iVar18 + 0x26) << 0x18) >> 0x10 | (uint)*(byte *)(iVar18 + 0x27);
  sVar24 = (short)((uint)iVar10 >> 0x10);
  *(short *)((int)param_2 + 0x4e) = sVar24;
  if (psVar17 == (short *)0x0) {
    sVar24 = (short)((iVar21 << 1) / 3);
LAB_c026c9c0:
    *(short *)(param_2 + 0x13) = sVar24;
  }
  else {
    sVar2 = CONCAT11((char)psVar17[1],*(undefined1 *)((int)psVar17 + 3));
    *(short *)(param_2 + 0x13) = sVar2;
    if (sVar2 == 0) {
      sVar24 = sVar24 >> 1;
      if (iVar21 < 0) {
        sVar24 = (short)(iVar21 + 1 >> 1);
      }
      goto LAB_c026c9c0;
    }
  }
  iVar10 = (int)*(short *)(param_2 + 0xe);
  uVar8 = (undefined2)(iVar10 >> 1);
  if (iVar10 < 0) {
    uVar8 = (undefined2)(iVar10 + 1 >> 1);
  }
  *(undefined2 *)(param_2 + 0x14) = uVar8;
  uVar8 = (undefined2)(iVar10 >> 2);
  if (iVar10 < 0) {
    uVar8 = (undefined2)(iVar10 + 3 >> 2);
  }
  *(undefined2 *)((int)param_2 + 0x52) = uVar8;
  if (iVar22 == 0) {
    *(short *)(param_2 + 0x19) = (short)((iVar10 + 7) / 0xe);
    *(short *)((int)param_2 + 0x66) = (short)((iVar10 + 5) / -10);
  }
  else {
    *(ushort *)(param_2 + 0x19) =
         CONCAT11(*(undefined1 *)(iVar22 + 10),*(undefined1 *)(iVar22 + 0xb));
    *(ushort *)((int)param_2 + 0x66) =
         CONCAT11(*(undefined1 *)(iVar22 + 8),*(undefined1 *)(iVar22 + 9));
  }
  if (psVar17 == (short *)0x0) {
    *(undefined2 *)(param_2 + 0x15) = 0;
    *(undefined2 *)((int)param_2 + 0x56) = 0;
    *(undefined2 *)(param_2 + 0x16) = 0;
    *(undefined2 *)((int)param_2 + 0x5a) = 0;
    *(undefined2 *)(param_2 + 0x17) = 0;
    *(undefined2 *)((int)param_2 + 0x5e) = 0;
    *(undefined2 *)(param_2 + 0x18) = 0;
    *(undefined2 *)((int)param_2 + 0x62) = 0;
    *(undefined2 *)(param_2 + 0x1a) = *(undefined2 *)(param_2 + 0x19);
    *(short *)((int)param_2 + 0x6a) = *(short *)(param_2 + 0x10) / 3;
  }
  else {
    *(ushort *)(param_2 + 0x15) = CONCAT11((char)psVar17[5],*(undefined1 *)((int)psVar17 + 0xb));
    *(ushort *)((int)param_2 + 0x56) =
         CONCAT11((char)psVar17[6],*(undefined1 *)((int)psVar17 + 0xd));
    *(ushort *)(param_2 + 0x16) = CONCAT11((char)psVar17[7],*(undefined1 *)((int)psVar17 + 0xf));
    *(ushort *)((int)param_2 + 0x5a) =
         CONCAT11((char)psVar17[8],*(undefined1 *)((int)psVar17 + 0x11));
    *(ushort *)(param_2 + 0x17) = CONCAT11((char)psVar17[9],*(undefined1 *)((int)psVar17 + 0x13));
    *(ushort *)((int)param_2 + 0x5e) =
         CONCAT11((char)psVar17[10],*(undefined1 *)((int)psVar17 + 0x15));
    *(ushort *)(param_2 + 0x18) = CONCAT11((char)psVar17[0xb],*(undefined1 *)((int)psVar17 + 0x17));
    *(ushort *)((int)param_2 + 0x62) =
         CONCAT11((char)psVar17[0xc],*(undefined1 *)((int)psVar17 + 0x19));
    *(ushort *)(param_2 + 0x1a) = CONCAT11((char)psVar17[0xd],*(undefined1 *)((int)psVar17 + 0x1b));
    *(ushort *)((int)param_2 + 0x6a) =
         CONCAT11((char)psVar17[0xe],*(undefined1 *)((int)psVar17 + 0x1d));
  }
  param_2[0x2a] = 0;
  iVar10 = 5;
  if (psVar17 == (short *)0x0) {
    *(undefined1 *)(param_2 + 0x2b) = 2;
    *(undefined1 *)((int)param_2 + 0xad) = 0;
    if ((*(byte *)(iVar18 + 0x2d) & 1) != 0) {
      iVar10 = 8;
    }
    uVar7 = 9;
    *(char *)((int)param_2 + 0xae) = (char)iVar10;
    if ((param_2[0xc] & 0x400000) == 0) {
      uVar7 = 0;
    }
    *(undefined1 *)((int)param_2 + 0xaf) = uVar7;
    *(undefined1 *)(param_2 + 0x2c) = 0;
    *(undefined1 *)((int)param_2 + 0xb1) = 0;
    *(undefined1 *)((int)param_2 + 0xb2) = 0;
    *(undefined1 *)((int)param_2 + 0xb3) = 0;
    *(undefined1 *)(param_2 + 0x2d) = 0;
    *(undefined1 *)((int)param_2 + 0xb5) = 0;
    *(undefined2 *)((int)param_2 + 0x2e) = *(undefined2 *)(&DAT_c02610d8 + iVar10 * 2);
  }
  else {
    uVar9 = CONCAT11((char)psVar17[2],*(undefined1 *)((int)psVar17 + 5));
    *(ushort *)((int)param_2 + 0x2e) = uVar9;
    if (uVar9 < 10) {
      *(undefined2 *)((int)param_2 + 0x2e) = *(undefined2 *)(&DAT_c02610d8 + (uint)uVar9 * 2);
    }
    memcpy(param_2 + 0x2b,psVar17 + 0x10,10);
  }
  param_2[9] = 0;
  if ((*(uint *)(param_1 + 0xf8) & 2) == 0) {
    uVar7 = (undefined1)(uVar3 >> 8);
    if (((psVar17 == (short *)0x0) ||
        ((char)*psVar17 == '\0' && *(char *)((int)psVar17 + 1) == '\0')) ||
       ((uVar12 = CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x27],
                                             *(undefined1 *)((int)psVar17 + 0x4f)),
                                    (char)psVar17[0x28]),*(undefined1 *)((int)psVar17 + 0x51)),
        uVar12 == 0 || (iVar10 = FUN_c026a59c(uVar12,param_1), iVar10 != 0)))) {
      if (*(int *)(param_1 + 0x108) == 5) {
        sVar24 = *(short *)(param_1 + 0x104);
        if (sVar24 == 0x200) {
          *(undefined1 *)(param_2 + 0xb) = 0x80;
          uVar4 = 0x3a4;
LAB_c026cf80:
          *(undefined4 *)(param_1 + 0xec) = uVar4;
        }
        else if (sVar24 == 0x300) {
          *(undefined1 *)(param_2 + 0xb) = 0x86;
          uVar4 = 0x3a8;
LAB_c026ce98:
          *(undefined4 *)(param_1 + 0xec) = uVar4;
        }
        else {
          if (sVar24 == 0x400) {
            *(undefined1 *)(param_2 + 0xb) = 0x88;
            uVar4 = 0x3b6;
            goto LAB_c026cf80;
          }
          if (sVar24 == 0x500) {
            *(undefined1 *)(param_2 + 0xb) = 0x81;
            *(undefined4 *)(param_1 + 0xec) = 0x3b5;
          }
          else {
            *(undefined1 *)(param_2 + 0xb) = 0;
            *(undefined4 *)(param_1 + 0xec) = 0x4e4;
          }
        }
      }
      else {
        iVar18 = *(int *)(param_1 + 0x2c);
        iVar10 = FUN_c0269dc4(0xff71,iVar18);
        if (((iVar10 == 0) || (iVar10 = FUN_c0269dc4(0xff72,iVar18), iVar10 == 0)) ||
           ((iVar10 = FUN_c0269dc4(0xff73,iVar18), iVar10 == 0 ||
            ((iVar10 = FUN_c0269dc4(0xff74,iVar18), iVar10 == 0 ||
             (iVar10 = FUN_c0269dc4(0xff75,iVar18), iVar10 == 0)))))) {
          iVar10 = FUN_c0269dc4(0x61d4,iVar18);
          if ((iVar10 == 0) || (iVar10 = FUN_c0269dc4(0x9ee2,iVar18), iVar10 == 0)) {
            iVar10 = FUN_c0269dc4(0x9f98,iVar18);
            if ((iVar10 == 0) || (iVar10 = FUN_c0269dc4(0x9f79,iVar18), iVar10 == 0)) {
              iVar10 = FUN_c0269dc4(0xac00,iVar18);
              if ((iVar10 == 0) || (iVar10 = FUN_c0269dc4(0xd558,iVar18), iVar10 == 0)) {
                iVar10 = FUN_c0269dc4(0xe000,iVar18);
                if ((iVar10 == 0) || (iVar10 = FUN_c0266e14(), iVar10 == 0)) {
                  *(undefined1 *)(param_2 + 0xb) = uVar7;
                  if (uVar5 == 0) {
                    cVar1 = *(char *)(param_2 + 0x2b);
                    goto LAB_c026ceac;
                  }
                  goto LAB_c026ced4;
                }
                EngGetCurrentCodePage(&local_54,local_58);
                uVar5 = (uint)local_58[0];
                if (uVar5 == 0x3a4) {
                  *(undefined1 *)(param_2 + 0xb) = 0x80;
                }
                else if (uVar5 == 0x3a8) {
                  *(undefined1 *)(param_2 + 0xb) = 0x86;
                }
                else if (uVar5 == 0x3b5) {
                  *(undefined1 *)(param_2 + 0xb) = 0x81;
                }
                else if (uVar5 == 0x3b6) {
                  *(undefined1 *)(param_2 + 0xb) = 0x88;
                }
                else if (uVar5 == 0x551) {
                  *(undefined1 *)(param_2 + 0xb) = 0x82;
                }
                *(uint *)(param_1 + 0xec) = uVar5;
              }
              else {
                *(undefined1 *)(param_2 + 0xb) = 0x81;
                *(undefined4 *)(param_1 + 0xec) = 0x3b5;
              }
            }
            else {
              *(undefined1 *)(param_2 + 0xb) = 0x88;
              *(undefined4 *)(param_1 + 0xec) = 0x3b6;
            }
          }
          else {
            *(undefined1 *)(param_2 + 0xb) = 0x86;
            *(undefined4 *)(param_1 + 0xec) = 0x3a8;
          }
        }
        else {
LAB_c026cdec:
          *(undefined1 *)(param_2 + 0xb) = 0x80;
          *(undefined4 *)(param_1 + 0xec) = 0x3a4;
        }
      }
    }
    else {
      bVar20 = *(byte *)((int)psVar17 + 0x4f);
      if ((bVar20 & 0x1e) == 0) {
        *(undefined1 *)(param_2 + 0xb) = uVar7;
        if (uVar5 == 0) {
          cVar1 = *(char *)(param_2 + 0x2b);
LAB_c026ceac:
          if ((cVar1 == '\x05') && (*(int *)(param_1 + 0x108) == 4)) {
            *(undefined1 *)(param_2 + 0xb) = 2;
          }
        }
LAB_c026ced4:
        *(undefined4 *)(param_1 + 0xec) = 0x4e4;
      }
      else if ((DAT_c029ac8c &
               CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x27],bVar20),(char)psVar17[0x28]),
                        *(byte *)((int)psVar17 + 0x51))) == 0) {
        if ((bVar20 & 2) != 0) goto LAB_c026cdec;
        if ((bVar20 & 0x10) == 0) {
          if ((bVar20 & 4) == 0) {
            if ((bVar20 & 8) == 0) {
              if ((*(byte *)((int)psVar17 + 0x51) & 1) != 0) {
                *(undefined1 *)(param_2 + 0xb) = 0;
                uVar4 = 0x4e4;
                goto LAB_c026ce98;
              }
            }
            else {
              *(undefined1 *)(param_2 + 0xb) = 0x81;
              *(undefined4 *)(param_1 + 0xec) = 0x3b5;
            }
          }
          else {
            *(undefined1 *)(param_2 + 0xb) = 0x86;
            *(undefined4 *)(param_1 + 0xec) = 0x3a8;
          }
        }
        else {
          *(undefined1 *)(param_2 + 0xb) = 0x88;
          *(undefined4 *)(param_1 + 0xec) = 0x3b6;
        }
      }
      else {
        EngGetCurrentCodePage(&local_54,local_58);
        *(undefined1 *)(param_2 + 0xb) = DAT_c029ac88;
        *(uint *)(param_1 + 0xec) = (uint)local_58[0];
      }
    }
    if ((*(short *)(param_1 + 0x102) == 0x300) && (psVar17 != (short *)0x0)) {
      uVar7 = *(undefined1 *)((int)psVar17 + 0x41);
      uVar5 = (uint)CONCAT11((char)psVar17[0x21],*(undefined1 *)((int)psVar17 + 0x43));
      uVar12 = (uint)CONCAT11((char)psVar17[0x20],uVar7);
      if (uVar5 < 0x100) {
        *(undefined1 *)((int)param_2 + 0x6d) = *(undefined1 *)((int)psVar17 + 0x43);
LAB_c026d1b0:
        *(undefined1 *)(param_2 + 0x1b) = uVar7;
      }
      else {
        if (uVar12 < 0x100) {
          *(undefined1 *)((int)param_2 + 0x6d) = 0xff;
          goto LAB_c026d1b0;
        }
        iVar10 = (uVar5 - uVar12) + 0x20;
        param_2[9] = uVar12 - 0x20;
        *(undefined1 *)(param_2 + 0xb) = 2;
        *(undefined1 *)(param_2 + 0x1b) = 0x20;
        if (0xff < iVar10) {
          iVar10 = 0xff;
        }
        *(char *)((int)param_2 + 0x6d) = (char)iVar10;
      }
      if (1 < *(byte *)(param_2 + 0x1b)) {
        *(byte *)(param_2 + 0x1b) = *(byte *)(param_2 + 0x1b) - 2;
      }
      cVar1 = *(char *)(param_2 + 0xb);
      if (cVar1 == -0x80) {
        *(undefined1 *)((int)param_2 + 0x6e) = 0xa5;
        *(char *)((int)param_2 + 0x6f) = *(char *)(param_2 + 0x1b) + '\x02';
      }
      else {
        if ((cVar1 == -0x78) || (cVar1 == -0x7a)) {
          cVar1 = *(char *)(param_2 + 0x1b);
          *(undefined1 *)((int)param_2 + 0x6e) = 0x20;
        }
        else {
          if (cVar1 == -0x7f) {
            *(undefined1 *)((int)param_2 + 0x6e) = 0x7f;
            *(undefined1 *)((int)param_2 + 0x6f) = 0x1f;
            goto LAB_c026d248;
          }
          cVar1 = *(char *)(param_2 + 0x1b);
          *(char *)((int)param_2 + 0x6e) = cVar1 + '\x01';
        }
        *(char *)((int)param_2 + 0x6f) = cVar1 + '\x02';
      }
LAB_c026d248:
      cVar1 = *(char *)(param_2 + 0xb);
      if (cVar1 == -0x80) {
        *(undefined2 *)(param_2 + 0x1d) = 0xff65;
      }
      else {
        if (((cVar1 != -0x7f) && (cVar1 != -0x78)) && (cVar1 != -0x7a)) {
          *(ushort *)(param_2 + 0x1d) = (ushort)*(byte *)((int)param_2 + 0x6e);
          *(ushort *)((int)param_2 + 0x76) = (ushort)*(byte *)((int)param_2 + 0x6f);
          goto LAB_c026d3cc;
        }
        *(undefined2 *)(param_2 + 0x1d) = 0x25a1;
      }
      *(ushort *)((int)param_2 + 0x76) = (ushort)*(byte *)((int)param_2 + 0x6f);
    }
    else {
      cVar1 = *(char *)(param_2 + 0xb);
      *(undefined1 *)(param_2 + 0x1b) = 0x1e;
      *(undefined1 *)((int)param_2 + 0x6d) = 0xff;
      if (cVar1 == -0x80) {
        *(undefined1 *)((int)param_2 + 0x6e) = 0xa5;
      }
      else if ((cVar1 == -0x78) || (cVar1 == -0x7a)) {
        *(undefined1 *)((int)param_2 + 0x6e) = 0x20;
      }
      else {
        *(undefined1 *)((int)param_2 + 0x6e) = 0x1f;
      }
      cVar1 = *(char *)(param_2 + 0xb);
      *(undefined1 *)((int)param_2 + 0x6f) = 0x20;
      if (cVar1 == -0x80) {
        *(undefined2 *)((int)param_2 + 0x76) = 0x20;
        *(undefined2 *)(param_2 + 0x1d) = 0xff65;
      }
      else if ((cVar1 == -0x78) || (cVar1 == -0x7a)) {
        *(undefined2 *)((int)param_2 + 0x76) = 0x20;
        *(undefined2 *)(param_2 + 0x1d) = 0x25a1;
      }
      else {
        *(undefined2 *)((int)param_2 + 0x76) = 0x20;
        *(undefined2 *)(param_2 + 0x1d) = 0x1f;
      }
    }
  }
  else {
    cVar1 = *(char *)(iVar23 + 0x16);
    *(char *)(param_2 + 0x1b) = cVar1;
    *(undefined1 *)((int)param_2 + 0x6d) = *(undefined1 *)(iVar23 + 0x18);
    *(undefined1 *)((int)param_2 + 0x6e) = 0x95;
    *(char *)((int)param_2 + 0x6f) = *(char *)(iVar23 + 0x1c) + cVar1;
    cVar1 = *(char *)(iVar23 + 0x1e);
    *(char *)(param_2 + 0xb) = cVar1;
    if (cVar1 == -0x38) {
      *(undefined1 *)(param_2 + 0xb) = 0;
    }
    iVar10 = _wcsicmp((wchar_t *)(param_2[2] + (int)param_2),L"ZapfDingbats");
    if (((iVar10 == 0) ||
        (iVar10 = _wcsicmp((wchar_t *)(param_2[2] + (int)param_2),L"Symbol"), iVar10 == 0)) &&
       (*(char *)(param_2 + 0xb) == '\0')) {
      *(undefined1 *)(param_2 + 0xb) = 2;
    }
  }
LAB_c026d3cc:
  iVar10 = local_4c;
  iVar18 = *(int *)(param_1 + 0x2c);
  bVar20 = 1;
  psVar11 = (short *)((*(int *)(iVar18 + 0xc) + 1) * 8 + iVar18);
  *(undefined2 *)(param_2 + 0x1c) = *(undefined2 *)(iVar18 + 0x10);
  sVar24 = psVar11[1];
  sVar2 = *psVar11;
  param_2[0x1e] = 1;
  *(short *)((int)param_2 + 0x72) = sVar24 + sVar2 + -1;
  param_2[0x1f] = 0;
  param_2[0x20] = 1;
  param_2[0x21] = 1;
  param_2[0x22] =
       (int)((uint)*(byte *)(iVar23 + 0x14) << 0x18) >> 0x10 | (uint)*(byte *)(iVar23 + 0x15);
  param_2[0x23] =
       (int)((uint)*(byte *)(iVar23 + 0x12) << 0x18) >> 0x10 | (uint)*(byte *)(iVar23 + 0x13);
  if (iVar22 == 0) {
    param_2[8] = 0;
  }
  else {
    param_2[8] = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar22 + 4),*(undefined1 *)(iVar22 + 5))
                                   ,*(undefined1 *)(iVar22 + 6)),*(undefined1 *)(iVar22 + 7)) * 10
                 >> 0x10;
  }
  if (psVar17 == (short *)0x0) {
    *(undefined1 *)(param_2 + 0x28) = 0x55;
    *(undefined1 *)((int)param_2 + 0xa1) = 0x6e;
    *(undefined1 *)((int)param_2 + 0xa2) = 0x6b;
    *(undefined1 *)((int)param_2 + 0xa3) = 0x6e;
  }
  else {
    *(char *)(param_2 + 0x28) = (char)psVar17[0x1d];
    *(undefined1 *)((int)param_2 + 0xa1) = *(undefined1 *)((int)psVar17 + 0x3b);
    *(char *)((int)param_2 + 0xa2) = (char)psVar17[0x1e];
    *(undefined1 *)((int)param_2 + 0xa3) = *(undefined1 *)((int)psVar17 + 0x3d);
  }
  iVar18 = *(int *)(param_1 + 0x94) + local_4c;
  if (*(int *)(param_1 + 0x94) == 0) {
    iVar18 = 0;
  }
  if (iVar18 == 0) {
    param_2[0x29] = 0;
  }
  else {
    iVar18 = FUN_c026a47c(iVar18,*(uint *)(param_1 + 0x98),param_2 + 0x29);
    if (iVar18 == 0) {
      *(undefined4 *)(param_1 + 0x94) = 0;
      *(undefined4 *)(param_1 + 0x98) = 0;
    }
  }
  puVar19 = local_50;
  if ((*(char *)(param_2 + 0xb) == -0x80) || (*(char *)(param_2 + 0xb) == -0x7f)) {
    if (*(char *)(param_2 + 0x2b) == '\x03') {
      uVar7 = 0x40;
LAB_c026d5f8:
      *(undefined1 *)((int)param_2 + 0x2d) = uVar7;
    }
    else {
      if (*(byte *)((int)param_2 + 0xad) < 0x10) {
        uVar7 = (&DAT_c02610fc)[*(byte *)((int)param_2 + 0xad)];
        goto LAB_c026d5f8;
      }
      *(undefined1 *)((int)param_2 + 0x2d) = 0;
    }
    if (*(char *)((int)param_2 + 0xaf) == '\t') {
      param_2[0xc] = param_2[0xc] | 0x10400000;
    }
  }
  else if (*(char *)(param_2 + 0x2b) == '\x03') {
    *(undefined1 *)((int)param_2 + 0x2d) = 0x40;
  }
  else if (*(char *)(param_2 + 0x2b) == '\x04') {
    *(undefined1 *)((int)param_2 + 0x2d) = 0x50;
  }
  else {
    if (*(char *)((int)param_2 + 0xaf) == '\t') {
      uVar7 = 0x30;
    }
    else {
      if (0xf < *(byte *)((int)param_2 + 0xad)) {
        *(undefined1 *)((int)param_2 + 0x2d) = 0;
        goto LAB_c026d618;
      }
      uVar7 = (&DAT_c02610ec)[*(byte *)((int)param_2 + 0xad)];
    }
    *(undefined1 *)((int)param_2 + 0x2d) = uVar7;
  }
LAB_c026d618:
  iVar18 = local_50[1];
  param_2[6] = iVar18;
  if (iVar18 == 0) goto LAB_c026d7ac;
  puVar6 = (undefined4 *)(iVar18 + (int)param_2);
  piVar14 = (int *)0x0;
  piVar16 = (int *)0x0;
  uVar3 = *(ushort *)(param_2 + 0xd) & 0x21;
  piVar13 = (int *)0x0;
  if ((*(ushort *)(param_2 + 0xd) & 0x21) == 0) {
    *puVar6 = 0xc;
    puVar6[1] = 0x20;
    uVar4 = 0x34;
    piVar14 = puVar6 + 3;
    piVar16 = puVar6 + 8;
    piVar13 = puVar6 + 0xd;
LAB_c026d68c:
    puVar6[2] = uVar4;
  }
  else if ((uVar3 == 1) || (uVar3 == 0x20)) {
    *puVar6 = 0;
    uVar4 = 0xc;
    puVar6[1] = 0;
    piVar13 = puVar6 + 3;
    goto LAB_c026d68c;
  }
  local_38 = param_2[0x13];
  local_40 = (uint)*(byte *)((int)param_2 + 0xae) << 0x18;
  local_3c = CONCAT22(*(undefined2 *)(param_2 + 0xd),*(undefined2 *)((int)param_2 + 0x2e)) &
             0xffbfffff;
  iVar18 = param_2[0x22];
  iVar21 = param_2[0x23];
  if (piVar14 != (int *)0x0) {
    piVar14[2] = local_38;
    piVar14[1] = local_3c;
    *piVar14 = local_40;
    piVar14[3] = iVar18;
    piVar14[4] = iVar21;
    *(undefined1 *)((int)piVar13 + 3) = 8;
    *(ushort *)((int)piVar14 + 6) = *(ushort *)((int)piVar14 + 6) | 0x20;
    *(undefined2 *)(piVar14 + 1) = 700;
    *(short *)(piVar14 + 2) = (short)piVar14[2] + 1;
    *(short *)((int)piVar14 + 10) = *(short *)((int)piVar14 + 10) + 1;
  }
  if (piVar16 != (int *)0x0) {
    piVar16[1] = local_3c;
    piVar16[3] = iVar18;
    piVar16[4] = iVar21;
    *piVar16 = local_40;
    piVar16[2] = local_38;
    *(ushort *)((int)piVar16 + 6) = *(ushort *)((int)piVar16 + 6) | 1;
    piVar16[3] = 7;
    piVar16[4] = 0x21;
  }
  if (piVar13 != (int *)0x0) {
    piVar13[1] = local_3c;
    piVar13[3] = iVar18;
    piVar13[2] = local_38;
    piVar13[3] = 7;
    piVar13[4] = iVar21;
    *(ushort *)((int)piVar13 + 6) = *(ushort *)((int)piVar13 + 6) | 0x21;
    piVar13[4] = 0x21;
    *piVar13 = local_40;
    *(undefined1 *)((int)piVar13 + 3) = 8;
    *(undefined2 *)(piVar13 + 1) = 700;
    *(short *)(piVar13 + 2) = (short)piVar13[2] + 1;
    *(short *)((int)piVar13 + 10) = *(short *)((int)piVar13 + 10) + 1;
  }
LAB_c026d7ac:
  iVar18 = local_50[0xc];
  param_2[10] = iVar18;
  FUN_c026b964(param_1,(int)param_2,(undefined1 *)(iVar18 + (int)param_2),iVar10,psVar17,local_48);
  iVar10 = puVar19[0xd];
  param_2[0x2f] = iVar10;
  if (iVar10 != 0) {
    puVar19 = (undefined4 *)(iVar10 + (int)param_2);
    *puVar19 = CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x15],*(undefined1 *)((int)psVar17 + 0x2b)),
                                 (char)psVar17[0x16]),*(undefined1 *)((int)psVar17 + 0x2d));
    puVar19[1] = CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x17],*(undefined1 *)((int)psVar17 + 0x2f)
                                           ),(char)psVar17[0x18]),
                          *(undefined1 *)((int)psVar17 + 0x31));
    puVar19[2] = CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x19],*(undefined1 *)((int)psVar17 + 0x33)
                                           ),(char)psVar17[0x1a]),
                          *(undefined1 *)((int)psVar17 + 0x35));
    puVar19[3] = CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x1b],*(undefined1 *)((int)psVar17 + 0x37)
                                           ),(char)psVar17[0x1c]),
                          *(undefined1 *)((int)psVar17 + 0x39));
    if ((char)*psVar17 == '\0' && *(char *)((int)psVar17 + 1) == '\0') {
      puVar19[4] = 0;
      puVar19[5] = 0;
    }
    else {
      iVar10 = FUN_c026a59c(CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x27],
                                                       *(undefined1 *)((int)psVar17 + 0x4f)),
                                              (char)psVar17[0x28]),
                                     *(undefined1 *)((int)psVar17 + 0x51)),param_1);
      if (iVar10 == 0) {
        uVar4 = CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x27],*(undefined1 *)((int)psVar17 + 0x4f))
                                  ,(char)psVar17[0x28]),*(undefined1 *)((int)psVar17 + 0x51));
      }
      else {
        uVar4 = 0x20000;
      }
      puVar19[4] = uVar4;
      puVar19[5] = CONCAT31(CONCAT21(CONCAT11((char)psVar17[0x29],
                                              *(undefined1 *)((int)psVar17 + 0x53)),
                                     (char)psVar17[0x2a]),*(undefined1 *)((int)psVar17 + 0x55));
    }
  }
  iVar10 = FUN_c027739c(param_1 + 0x128);
  if ((iVar10 != 0) &&
     (*(uint *)(param_1 + 0xf8) = *(uint *)(param_1 + 0xf8) | 0x100,
     *(char *)((int)param_2 + 0xaf) == '\t')) {
    param_2[0xc] = param_2[0xc] | 0x10400000;
  }
  if ((param_2[0xc] & 0x400000) == 0) {
    bVar20 = 2;
  }
  *(byte *)((int)param_2 + 0x2d) = *(byte *)((int)param_2 + 0x2d) | bVar20;
  return;
}



/* c026d9dc FUN_c026d9dc */

/* Boundary evidence: original MIPS .pdata c026d9dc..c026dc4b. Semantic name remains unreviewed. */

undefined4
FUN_c026d9dc(int *param_1,uint param_2,int *param_3,ushort param_4,int *param_5,uint *param_6,
            ushort *param_7,short *param_8,undefined4 *param_9,undefined4 *param_10,uint *param_11,
            uint *param_12,uint *param_13,undefined4 *param_14)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined2 local_30;
  
  iVar1 = FUN_c026a788(param_1,param_2,param_3,param_5);
  if (iVar1 != 0) {
    iVar1 = param_5[4];
    iVar4 = param_5[0xc];
    iVar5 = param_5[0x12] + (int)param_1;
    if (param_5[0x12] == 0) {
      iVar5 = 0;
    }
    puVar3 = (undefined1 *)(param_5[0x10] + (int)param_1);
    if (param_5[0x10] == 0) {
      puVar3 = (undefined1 *)0x0;
    }
    if ((((0x35 < (uint)param_5[5]) && (0x23 < (uint)param_5[7])) && (0x1f < (uint)param_5[0xd])) &&
       ((uint)CONCAT11(*(undefined1 *)((int)param_1 + param_5[6] + 0x22),
                       *(undefined1 *)((int)param_1 + param_5[6] + 0x23)) << 2 <= (uint)param_5[9]))
    {
      if ((puVar3 != (undefined1 *)0x0) && (iVar2 = FUN_c026a554(puVar3,param_5[0x11]), iVar2 == 0))
      {
        param_5[0x11] = 0;
        param_5[0x10] = 0;
      }
      if ((CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)param_1 + iVar1 + 0xc),
                                      *(undefined1 *)((int)param_1 + iVar1 + 0xd)),
                             *(undefined1 *)((int)param_1 + iVar1 + 0xe)),
                    *(undefined1 *)((int)param_1 + iVar1 + 0xf)) == 0x5f0f3cf5) &&
         (iVar2 = FUN_c026c07c((int)param_1,param_5,param_7,param_8,param_9,param_10,param_11,
                               param_12), iVar2 != 0)) {
        local_30 = param_4;
        if (*param_7 != 0x300) {
          local_30 = FUN_c0274438((uint)param_4);
        }
        iVar2 = FUN_c026a9b4((uint)param_1,(int)param_5,(uint)*param_7,*param_8,
                             CONCAT11((undefined1)local_30,local_30._1_1_),param_6,param_13,param_14
                            );
        if ((iVar2 != 0) &&
           (iVar1 = FUN_c0267904((int)CONCAT11(*(undefined1 *)((int)param_1 + iVar1 + 0x32),
                                               *(undefined1 *)((int)param_1 + iVar1 + 0x33)),
                                 (int)param_1,(int)param_5,
                                 (uint)CONCAT11(*(undefined1 *)((int)param_1 + iVar4 + 4),
                                                *(undefined1 *)((int)param_1 + iVar4 + 5))),
           iVar1 != 0)) {
          if ((iVar5 != 0) && (iVar1 = FUN_c0267a48(iVar5,param_5[0x13]), iVar1 == 0)) {
            param_5[0x13] = 0;
            param_5[0x12] = 0;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}



/* c026dc4c FUN_c026dc4c */

/* Boundary evidence: original MIPS .pdata c026dc4c..c026e14f. Semantic name remains unreviewed. */

undefined4
FUN_c026dc4c(undefined4 param_1,int *param_2,uint param_3,int param_4,uint param_5,int *param_6,
            int *param_7,undefined4 param_8)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  void *_Dst;
  undefined2 extraout_var;
  void *pvVar7;
  void *_Dst_00;
  uint uVar8;
  int *piVar9;
  undefined4 local_6c8;
  short local_6c4;
  ushort local_6c2;
  short local_6c0 [2];
  uint local_6bc;
  uint local_6b8;
  undefined4 local_6b4;
  short *local_6b0;
  int local_6ac;
  uint local_6a8;
  undefined4 local_6a4;
  undefined4 local_6a0;
  undefined4 local_69c;
  undefined1 auStack_698 [4];
  undefined1 *local_694;
  undefined4 local_690;
  undefined4 local_68c;
  undefined4 local_670;
  undefined1 *local_66c;
  code *local_668;
  void *local_664;
  undefined2 local_660;
  undefined2 local_65e;
  uint local_628 [26];
  int aiStack_5c0 [3];
  int local_5b4;
  int local_5b0;
  int aiStack_4f8 [4];
  int local_4e8;
  int local_4e0;
  undefined1 auStack_458 [1072];
  
  local_6bc = 0;
  local_6c8 = 0;
  *param_6 = 0;
  local_6ac = param_4;
  if (param_7 != (int *)0x0) {
    uVar5 = FUN_c02689c0(param_1,param_2,param_3,param_6,param_7,param_8);
    return uVar5;
  }
  iVar6 = FUN_c026d9dc(param_2,param_3,(int *)((int)param_2 + param_4),(ushort)param_5,aiStack_4f8,
                       local_628,&local_6c2,&local_6c4,&local_6b0,&local_6b4,&local_6b8,&local_6a8,
                       &local_6bc,&local_6c8);
  uVar2 = local_6c8;
  if (iVar6 == 0) {
    return 0;
  }
  uVar8 = local_628[0] + 0x128;
  if (uVar8 < local_628[0]) {
    return 0;
  }
  if ((local_6c8 != 0) &&
     ((EngGetCurrentCodePage(&local_6c8,local_6c0), local_6c0[0] == 0x3a4 || (local_6c0[0] == 0x3b5)
      ))) {
    local_6a8 = local_6a8 | 4;
  }
  uVar3 = local_6a8;
  _Dst = (void *)EngAllocMem(0,uVar8,0x64667454);
  if (_Dst == (void *)0x0) {
    return 0;
  }
  *param_6 = (int)_Dst;
  memset(_Dst,0,0x128);
  *(undefined4 *)((int)_Dst + 0x1c) = param_1;
  *(int **)((int)_Dst + 0x20) = param_2;
  *(uint *)((int)_Dst + 0x24) = param_3;
  uVar1 = CONCAT11(*(undefined1 *)((int)param_2 + local_4e8 + 0x12),
                   *(undefined1 *)((int)param_2 + local_4e8 + 0x13));
  *(ushort *)((int)_Dst + 0x100) = uVar1;
  if ((0xf < uVar1) && (uVar1 < 0x4001)) {
    *(short *)((int)_Dst + 0x104) = local_6c4;
    *(undefined2 *)((int)_Dst + 0x112) = 0xffff;
    *(ushort *)((int)_Dst + 0x102) = local_6c2;
    *(undefined2 *)((int)_Dst + 0x110) = 0;
    *(ushort *)((int)_Dst + 0x114) =
         CONCAT11(*(undefined1 *)((int)param_2 + local_4e0 + 0xc),
                  *(undefined1 *)((int)param_2 + local_4e0 + 0xd));
    uVar8 = 2;
    *(ushort *)((int)_Dst + 0x116) =
         CONCAT11(*(undefined1 *)((int)param_2 + local_4e0 + 0xe),
                  *(undefined1 *)((int)param_2 + local_4e0 + 0xf));
    if (local_6bc == 0) {
      uVar8 = 0;
    }
    *(uint *)((int)_Dst + 0xf8) = uVar8;
    if ((uVar2 & 1) != 0) {
      *(uint *)((int)_Dst + 0xf8) = uVar8 | 0x40;
    }
    *(undefined4 *)((int)_Dst + 0x14) = 0;
    local_6c8 = param_5;
    if (local_6c2 != 0x300) {
      uVar4 = FUN_c0274438(param_5 & 0xffff);
      local_6c8 = CONCAT22(extraout_var,uVar4);
    }
    *(ushort *)((int)_Dst + 0x106) = CONCAT11((undefined1)local_6c8,local_6c8._1_1_);
    *(int *)((int)_Dst + 0xfc) = (int)local_6b0 - (int)param_2;
    *(undefined4 *)((int)_Dst + 0x18) = 0;
    memcpy((void *)((int)_Dst + 0x3c),aiStack_4f8,0xa0);
    *(int *)((int)_Dst + 0xdc) = local_6ac;
    *(undefined4 *)((int)_Dst + 0x28) = 0;
    *(uint *)((int)_Dst + 0x118) = uVar3;
    *(undefined4 *)((int)_Dst + 0x11c) = local_6a4;
    *(undefined4 *)((int)_Dst + 0x120) = local_6a0;
    *(undefined4 *)((int)_Dst + 0x124) = local_69c;
    *(uint *)((int)_Dst + 0x10c) = local_6b8;
    iVar6 = FUN_c0271bc0((int)auStack_698,aiStack_5c0);
    if (iVar6 == 0) {
      local_694 = auStack_458;
      local_690 = 0;
      local_68c = 0;
      iVar6 = FUN_c0271c34((int)auStack_698,aiStack_5c0);
      if (iVar6 == 0) {
        local_670 = *(undefined4 *)((int)_Dst + 0x20);
        local_66c = &LAB_c0266ff0;
        local_668 = FUN_c02619ec;
        local_660 = CONCAT11(*(undefined1 *)((int)_Dst + 0x102),*(undefined1 *)((int)_Dst + 0x103));
        local_65e = CONCAT11(*(undefined1 *)((int)_Dst + 0x104),*(undefined1 *)((int)_Dst + 0x105));
        local_664 = _Dst;
        iVar6 = FUN_c0271cc4((int)auStack_698,(int)aiStack_5c0);
        if (iVar6 == 0) {
          *(undefined4 *)((int)_Dst + 0xc) = 0;
          *(undefined4 *)((int)_Dst + 0x10) = 0;
          *(uint *)((int)_Dst + 0xf0) = local_5b4 + 7U & 0xfffffff8;
          piVar9 = (int *)((int)_Dst + 0x2c);
          *(uint *)((int)_Dst + 0xf4) = local_5b0 + 7U & 0xfffffff8;
          *(undefined4 *)((int)_Dst + 0xe8) = 1;
          *(undefined4 *)((int)_Dst + 8) = 0;
          *(undefined4 *)((int)_Dst + 0x30) = 0;
          *(undefined4 *)((int)_Dst + 0x108) = local_6b4;
          iVar6 = FUN_c026b2fc((int)_Dst,local_6b0,(int)auStack_698,&local_6a8,piVar9);
          if (iVar6 != 0) {
            FUN_c026c51c((int)_Dst,(size_t *)((int)_Dst + 0x128),local_628,(int)auStack_698);
            if (((*(uint *)((int)_Dst + 0xf8) & 0x100) == 0) ||
               (iVar6 = FUN_c027725c((int)_Dst), iVar6 == 0)) {
LAB_c026e0c0:
              *(undefined4 *)((int)_Dst + 0x34) = 0;
              *(undefined4 *)((int)_Dst + 0x38) = 0;
              return 1;
            }
            pvVar7 = (void *)EngAllocMem(0,local_628[0] + 7 & 0xfffffff8,0x64667454);
            _Dst_00 = (void *)EngAllocMem(0,*(undefined4 *)*piVar9,0x64667454);
            if (pvVar7 != (void *)0x0) {
              if (_Dst_00 != (void *)0x0) {
                FUN_c02688cc((size_t *)((int)_Dst + 0x128),pvVar7);
                *(void **)((int)_Dst + 8) = pvVar7;
                *(undefined4 *)((int)_Dst + 0xe8) = 2;
                memcpy(_Dst_00,(size_t *)*piVar9,*(size_t *)*piVar9);
                *(void **)((int)_Dst + 0x30) = _Dst_00;
                FUN_c0268c44(*piVar9,(int)_Dst);
                goto LAB_c026e0c0;
              }
              EngFreeMem(pvVar7);
            }
            if (*piVar9 != 0) {
              EngFreeMem();
            }
            if (_Dst_00 != (void *)0x0) {
              EngFreeMem(_Dst_00);
            }
            iVar6 = *param_6;
            if (iVar6 == 0) {
              return 0;
            }
            goto LAB_c026e110;
          }
        }
      }
    }
  }
  iVar6 = *param_6;
LAB_c026e110:
  EngFreeMem(iVar6);
  *param_6 = 0;
  return 0;
}



/* c026e150 FUN_c026e150 */

/* Boundary evidence: original MIPS .pdata c026e150..c026e7e7. Semantic name remains unreviewed. */

undefined4
FUN_c026e150(undefined4 param_1,int *param_2,uint param_3,uint param_4,int param_5,int *param_6)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  void *_Dst;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  int *piVar13;
  size_t *_Src;
  uint uVar14;
  int iVar15;
  undefined4 *local_74;
  undefined4 *local_68;
  int *local_64;
  uint local_50;
  int local_4c;
  int local_30 [2];
  
  *param_6 = 0;
  piVar13 = (int *)0x0;
  bVar2 = false;
  if (param_3 < 0x1c) {
    return 0;
  }
  if ((param_5 == 0) ||
     (piVar13 = (int *)EngFntCacheLookUp(param_5,local_30), piVar13 == (int *)0x0)) {
    bVar1 = false;
    iVar3 = local_30[0];
  }
  else {
    bVar1 = true;
    bVar2 = true;
    iVar3 = *piVar13;
  }
  if (!bVar1) {
    iVar3 = FUN_c026850c(param_2);
    bVar1 = bVar2;
  }
  if (iVar3 == 0) {
    puVar4 = (undefined4 *)EngAllocMem(1,0x34,0x64667454);
    *param_6 = (int)puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      return 0;
    }
    puVar4[8] = 1;
    puVar4[7] = 0;
    if (bVar2) {
      piVar8 = (int *)(piVar13[3] + (int)piVar13);
    }
    else {
      piVar8 = (int *)0x0;
    }
    iVar15 = FUN_c026dc4c(param_1,param_2,param_3,0,param_4,puVar4 + 9,piVar8,param_5);
    if (iVar15 == 0) goto LAB_c026e53c;
    puVar11 = (undefined4 *)puVar4[9];
    *puVar11 = puVar4;
    puVar4[2] = 1;
    uVar12 = 2;
    if (puVar11[0x3a] != 2) {
      uVar12 = 1;
    }
    puVar4[3] = uVar12;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[6] = 0;
    if (puVar11[0x3a] == 2) {
      puVar4[0xc] = puVar11;
      puVar4[0xb] = 2;
      puVar4[10] = 0;
    }
  }
  else {
    if (bVar1) {
      uVar14 = piVar13[1];
    }
    else {
      uVar14 = CONCAT31(CONCAT21(CONCAT11((char)param_2[2],*(undefined1 *)((int)param_2 + 9)),
                                 *(undefined1 *)((int)param_2 + 10)),
                        *(undefined1 *)((int)param_2 + 0xb));
    }
    if (((uVar14 == 0) || (0xaaaaaa8 < uVar14)) || (param_3 - 0xc >> 2 < uVar14)) {
      return 0;
    }
    puVar4 = (undefined4 *)EngAllocMem(1,uVar14 * 0x18 + 0x1c,0x64667454);
    *param_6 = (int)puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      return 0;
    }
    iVar15 = 0;
    local_50 = 0;
    if (uVar14 != 0) {
      local_4c = 0xc;
      local_64 = puVar4 + 10;
      local_68 = puVar4 + 0xb;
      local_74 = puVar4 + 0xc;
      piVar7 = puVar4 + 9;
      piVar8 = puVar4 + 7;
      puVar11 = puVar4 + 8;
      do {
        if (bVar2) {
          piVar6 = (int *)(*(int *)((int)piVar13 + local_4c) + (int)piVar13);
          iVar9 = piVar6[0x29];
        }
        else {
          piVar6 = (int *)0x0;
          iVar9 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_4c + (int)param_2),
                                             *(undefined1 *)((int)param_2 + local_4c + 1)),
                                    *(undefined1 *)((int)param_2 + local_4c + 2)),
                           *(undefined1 *)((int)param_2 + local_4c + 3));
        }
        *puVar11 = 1;
        *piVar8 = iVar9;
        iVar5 = FUN_c026dc4c(param_1,param_2,param_3,iVar9,param_4,piVar7,piVar6,param_5);
        if (iVar5 == 0) {
          bVar1 = false;
          goto LAB_c026e4d0;
        }
        puVar10 = (undefined4 *)*piVar7;
        *puVar10 = puVar4;
        if (puVar10[0x3a] == 2) {
          *local_74 = puVar10;
          *local_68 = 2;
          *local_64 = iVar9;
          iVar15 = iVar15 + 2;
          piVar7 = piVar7 + 6;
          local_74 = local_74 + 6;
          puVar11 = puVar11 + 6;
          piVar8 = piVar8 + 6;
          local_68 = local_68 + 6;
          local_64 = local_64 + 6;
        }
        else {
          iVar15 = iVar15 + 1;
          piVar7 = piVar7 + 3;
          local_74 = local_74 + 3;
          puVar11 = puVar11 + 3;
          piVar8 = piVar8 + 3;
          local_68 = local_68 + 3;
          local_64 = local_64 + 3;
        }
        local_50 = local_50 + 1;
        local_4c = local_4c + 4;
      } while (local_50 < uVar14);
    }
    bVar1 = true;
LAB_c026e4d0:
    if (!bVar1) {
      if (iVar15 != 0) {
        piVar13 = puVar4 + 8;
        do {
          if (*piVar13 == 1) {
            FUN_c0266f70(piVar13[1]);
          }
          piVar13 = piVar13 + 3;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
LAB_c026e53c:
      EngFreeMem(*param_6);
      goto LAB_c026e548;
    }
    puVar4[2] = uVar14;
    puVar4[3] = iVar15;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[6] = 0;
  }
  if (bVar2) {
    if (piVar13[2] == 0) {
LAB_c026e6dc:
      uVar14 = 0;
      if (puVar4[3] != 0) {
        piVar13 = puVar4 + 8;
        do {
          iVar3 = piVar13[1];
          if (*piVar13 == 1) {
            if (*(int *)(iVar3 + 0x2c) != 0) {
              EngFreeMem();
              *(undefined4 *)(iVar3 + 0x2c) = 0;
            }
            if (*(int *)(iVar3 + 0x30) != 0) {
              EngFreeMem();
              *(undefined4 *)(iVar3 + 0x30) = 0;
            }
          }
          uVar14 = uVar14 + 1;
          piVar13 = piVar13 + 3;
        } while (uVar14 < (uint)puVar4[3]);
        return 1;
      }
      return 1;
    }
    _Src = (size_t *)(piVar13[2] + (int)piVar13);
    _Dst = (void *)EngAllocMem(0,*_Src,0x64667454);
    puVar4[6] = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,_Src,*_Src);
      goto LAB_c026e6dc;
    }
  }
  else if (((*(uint *)(puVar4[9] + 0xf8) & 0x100) == 0) ||
          (iVar15 = FUN_c0276bb0((int)puVar4,puVar4[9]), iVar15 != 0)) {
    if (param_5 != 0) {
      FUN_c0268564((int)puVar4,param_5,iVar3);
    }
    goto LAB_c026e6dc;
  }
  FUN_c026a6dc(*param_6);
LAB_c026e548:
  *param_6 = 0;
  return 0;
}



/* c026e7e8 FUN_c026e7e8 */

/* Boundary evidence: original MIPS .pdata c026e7e8..c026e7f3. Semantic name remains unreviewed. */

undefined4 FUN_c026e7e8(void)

{
  return 1;
}



/* c026e7f4 FUN_c026e7f4 */

/* Boundary evidence: original MIPS .pdata c026e7f4..c026e8eb. Semantic name remains unreviewed. */

undefined4 FUN_c026e7f4(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  piVar3 = (int *)(iVar2 + 0x70);
  iVar1 = FUN_c0271bc0(iVar2,piVar3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(iVar2 + 8) = 0;
    *(int *)(iVar2 + 4) = iVar1 + 0x138;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    iVar1 = FUN_c0271c34(iVar2,piVar3);
    if (iVar1 == 0) {
      *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(param_1 + 0x20);
      *(int *)(iVar2 + 0x34) = param_1;
      *(undefined1 **)(iVar2 + 0x2c) = &LAB_c0266ff0;
      *(code **)(iVar2 + 0x30) = FUN_c02619ec;
      *(ushort *)(iVar2 + 0x38) =
           CONCAT11(*(undefined1 *)(param_1 + 0x102),*(undefined1 *)(param_1 + 0x103));
      *(ushort *)(iVar2 + 0x3a) =
           CONCAT11(*(undefined1 *)(param_1 + 0x104),*(undefined1 *)(param_1 + 0x105));
      iVar1 = FUN_c0271cc4(iVar2,(int)piVar3);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 0xc) + 0x568;
        *(int *)(iVar2 + 0x10) = iVar1;
        *(int *)(iVar2 + 0x14) = *(int *)(param_1 + 0xf0) + iVar1;
        return 1;
      }
    }
  }
  return 0;
}



/* c026e8ec FUN_c026e8ec */

void FUN_c026e8ec(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  uint uVar8;
  
  iVar3 = *(int *)(param_1 + 0x54) + *(int *)(param_1 + 0x20);
  puVar6 = (undefined1 *)(*(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x20));
  uVar8 = 0;
  uVar7 = 0;
  uVar5 = 0xffff;
  uVar2 = (uint)CONCAT11(*(undefined1 *)(iVar3 + 0x22),*(undefined1 *)(iVar3 + 0x23));
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      uVar1 = CONCAT11(*puVar6,puVar6[1]);
      if ((uVar1 < uVar5) && (uVar1 != 0)) {
        uVar8 = uVar4;
        uVar5 = uVar1;
      }
      uVar7 = (undefined2)uVar8;
      uVar4 = uVar4 + 1;
      puVar6 = puVar6 + 4;
    } while (uVar4 < uVar2);
  }
  *(ushort *)(param_1 + 0x110) = uVar5;
  *(undefined2 *)(param_1 + 0x112) = uVar7;
  return;
}



/* c026e974 FUN_c026e974 */

/* Boundary evidence: original MIPS .pdata c026e974..c026ea57. Semantic name remains unreviewed. */

undefined4 FUN_c026e974(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 4);
    piVar3 = (int *)*puVar2;
    puVar2[6] = puVar2[6] + -1;
    *piVar3 = *piVar3 + -1;
    if (puVar2[4] == param_1) {
      puVar2[4] = 0;
    }
    if (((piVar3[1] & 1U) != 0) && (*(int *)(param_1 + 0x10) != 0)) {
      EngFreeMem();
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    if ((puVar2[6] == 0) && ((piVar3[1] & 1U) == 0)) {
      EngFreeMem(puVar2[3]);
      puVar2[3] = 0;
    }
    if (*piVar3 == 0) {
      EngUnmapFontFileFD(*(undefined4 *)(piVar3[9] + 0x1c));
    }
    EngFreeMem(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c026ea58 FUN_c026ea58 */

/* Boundary evidence: original MIPS .pdata c026ea58..c026ea8f. Semantic name remains unreviewed. */

void FUN_c026ea58(int param_1)

{
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_c026e974(*(int *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}



/* c026ea90 FUN_c026ea90 */

/* Boundary evidence: original MIPS .pdata c026ea90..c026eac7. Semantic name remains unreviewed. */

void FUN_c026ea90(undefined4 param_1,int *param_2)

{
  if ((param_2 != (int *)0x0) && (*param_2 == 0)) {
    *(undefined4 *)(param_2[1] + 0x28) = 0;
    EngFreeMem(param_2);
  }
  return;
}



/* c026eac8 FUN_c026eac8 */

/* Boundary evidence: original MIPS .pdata c026eac8..c026f06b. Semantic name remains unreviewed. */

undefined4 FUN_c026eac8(int param_1,int param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_50;
  uint local_4c;
  uint local_44;
  uint local_40;
  
  memcpy(&local_50,(int *)(param_1 + 0x40),0x24);
  FUN_c02619f4((undefined4 *)(param_1 + 8));
  if (0x7fff < *(uint *)(param_1 + 0x24)) {
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  *(short *)(*(int *)(param_1 + 0x98) + 0x3c) = (short)*(undefined4 *)(param_1 + 0x1c);
  *(short *)(*(int *)(param_1 + 0x98) + 0x3e) = (short)*(undefined4 *)(param_1 + 0x20);
  if ((*(uint *)(param_1 + 100) & 8) == 0) {
    if ((*(uint *)(param_1 + 100) & 1) == 0) {
      iVar3 = *(int *)(param_1 + 0x24);
      if (iVar3 == 0) {
        iVar3 = (*(int *)(param_1 + 0x70) >> 0xf) + 1 >> 1;
        *(int *)(*(int *)(param_1 + 0x98) + 0x38) = *(int *)(param_1 + 0x70);
      }
      else {
        *(int *)(*(int *)(param_1 + 0x98) + 0x38) = iVar3 << 0x10;
      }
      if ((((*(uint *)(param_1 + 100) & 2) == 0) ||
          (*(int *)(param_1 + 0x4c) != -*(int *)(param_1 + 0x44))) ||
         (*(int *)(param_1 + 0x20) != *(int *)(param_1 + 0x1c))) {
        if ((iVar3 + 1) * *(int *)(param_1 + 0x1c) < 0x8001) {
          uVar2 = 0x480000;
          iVar4 = *(int *)(*(int *)(param_1 + 0x98) + 0x38);
          uVar1 = *(ushort *)(*(int *)(param_1 + 4) + 0x100);
        }
        else {
          uVar2 = 0x48;
          uVar1 = *(ushort *)(*(int *)(param_1 + 4) + 0x100);
          iVar4 = iVar3;
        }
        uVar2 = FUN_c0274d38((uint)uVar1 << 0x10,uVar2,*(int *)(param_1 + 0x1c) * iVar4);
        local_50 = FUN_c0274f80(local_50,uVar2);
        local_44 = FUN_c0274f80(local_44,uVar2);
        iVar4 = *(int *)(param_1 + 0x20);
        if (iVar4 != *(int *)(param_1 + 0x1c)) {
          if ((iVar3 + 1) * iVar4 < 0x8001) {
            uVar2 = 0x480000;
            iVar3 = *(int *)(*(int *)(param_1 + 0x98) + 0x38);
            uVar1 = *(ushort *)(*(int *)(param_1 + 4) + 0x100);
          }
          else {
            uVar1 = *(ushort *)(*(int *)(param_1 + 4) + 0x100);
            uVar2 = 0x48;
          }
          uVar2 = FUN_c0274d38((uint)uVar1 << 0x10,uVar2,iVar4 * iVar3);
        }
        local_40 = FUN_c0274f80(local_40,uVar2);
        local_4c = FUN_c0274f80(local_4c,uVar2);
        uVar2 = local_50;
      }
      else {
        local_4c = 0x10000;
        if (*(int *)(param_1 + 0x44) < 1) {
          local_4c = 0xffff0000;
        }
        local_44 = -local_4c;
        local_50 = 0;
        local_40 = 0;
        uVar2 = local_50;
      }
    }
    else if (*(int *)(param_1 + 0x24) == 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x38) = *(undefined4 *)(param_1 + 0x70);
      local_40 = 0x10000;
      if (*(int *)(param_1 + 0x50) < 1) {
        local_40 = 0xffff0000;
      }
      if ((*(int *)(param_1 + 0x50) != *(int *)(param_1 + 0x40)) ||
         (uVar2 = local_40, *(int *)(param_1 + 0x20) != *(int *)(param_1 + 0x1c))) {
        uVar2 = FUN_c0274d38((uint)*(ushort *)(*(int *)(param_1 + 4) + 0x100) << 0x10,
                             *(uint *)(param_1 + 0x20),
                             *(int *)(param_1 + 0x6c) * *(int *)(param_1 + 0x1c));
        uVar2 = FUN_c0274f80(local_50,uVar2);
      }
    }
    else {
      *(int *)(*(int *)(param_1 + 0x98) + 0x38) = *(int *)(param_1 + 0x24) << 0x10;
      uVar2 = FUN_c0274d38((uint)*(ushort *)(*(int *)(param_1 + 4) + 0x100) << 0x10,0x48,
                           *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x1c));
      local_50 = FUN_c0274f80(local_50,uVar2);
      if (*(int *)(param_1 + 0x20) != *(int *)(param_1 + 0x1c)) {
        uVar2 = FUN_c0274d38((uint)*(ushort *)(*(int *)(param_1 + 4) + 0x100) << 0x10,0x48,
                             *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x20));
      }
      local_40 = FUN_c0274f80(local_40,uVar2);
      uVar2 = local_50;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x38) = 0xc0000;
    local_50 = 0x10000;
    local_44 = 0;
    local_40 = 0x10000;
    local_4c = 0;
    uVar2 = local_50;
  }
  local_50 = uVar2;
  if ((*(uint *)(param_1 + 0x18) & 0x4000) != 0) {
    iVar3 = FUN_c0274f80(local_50,0x5700);
    local_44 = iVar3 + local_44;
    iVar3 = FUN_c0274f80(local_4c,0x5700);
    local_40 = iVar3 + local_40;
  }
  *(uint **)(*(int *)(param_1 + 0x98) + 0x44) = &local_50;
  if (*(int *)(param_1 + 0x124) != 0) {
    memcpy((void *)(param_1 + 0x154),&local_50,0x24);
    *(undefined4 *)(param_1 + 300) = *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x38);
    FUN_c02769d8(param_1);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x40) = 0x16a0a;
  uVar5 = 1;
  *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x4c) = *(undefined2 *)(param_1 + 0x182);
  if (param_3 == -1) {
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x5c) = 1;
  }
  else if (param_3 == 1) {
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x5c) = 3;
  }
  else {
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x5c) = 0;
  }
  if ((*(uint *)(param_1 + 0x68) & 1) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x68) = 0;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x68) = param_4;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x48) = 0;
  if ((*(uint *)(param_1 + 0x18) & 0x2000) == 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x4e) = 0;
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x50) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x54) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x58) = 0;
  }
  else {
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x4e) = 0x14;
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x50) = 0x14;
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x54) = *(undefined4 *)(param_1 + 0x7c);
    *(int *)(*(int *)(param_1 + 0x98) + 0x58) = param_2;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x60) = 0;
  if ((*(uint *)(param_1 + 0x68) & 4) != 0) {
    if ((((*(uint *)(param_1 + 0x68) & 8) == 0) ||
        (iVar3 = *(int *)(param_1 + 0x98), (*(ushort *)(iVar3 + 0x5c) & 1) == 0)) ||
       (*(int *)(iVar3 + 0x58) == 0)) {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 100) = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 100) = 1;
    }
  }
  iVar3 = FUN_c0274370(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
  if ((iVar3 == 0) ||
     (iVar3 = FUN_c0274354(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c)), iVar3 == 0)) {
    if ((param_2 == 0) || ((*(uint *)(param_1 + 0x18) & 0x2000) == 0)) {
      *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xffffff7f;
    }
    else {
      *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x80;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



/* c026f06c FUN_c026f06c */

int FUN_c026f06c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0;
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  iVar3 = param_2;
  if ((param_1 != 0) && (iVar3 = param_1, param_2 != 0)) {
    for (; (0x8000 < param_1 || (0x8000 < param_2)); param_2 = param_2 >> 1) {
      param_1 = param_1 >> 1;
      uVar2 = uVar2 + 1 & 0xffff;
    }
    if (param_2 < param_1) {
      uVar4 = param_2 * param_2;
    }
    else {
      uVar4 = param_1 * param_1;
      param_1 = param_2;
    }
    uVar1 = 0;
    if (uVar4 != 0) {
      iVar3 = param_1 << 1;
      do {
        uVar1 = iVar3 + uVar1 + 1;
        param_1 = param_1 + 1;
        iVar3 = iVar3 + 2;
      } while (uVar1 < uVar4);
    }
    iVar3 = param_1 << (uVar2 & 0x1f);
  }
  return iVar3;
}



/* c026f120 FUN_c026f120 */

undefined4 FUN_c026f120(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (int)param_1 >> 0x17 & 0xff;
  iVar2 = uVar1 - 0x6f;
  if (iVar2 < 0) {
    *param_2 = 0;
  }
  else {
    if (iVar2 < 0x17) {
      if ((param_1 & 0x80000000) == 0) {
        iVar2 = ((int)(param_1 & 0x7fffff | 0x800000) >> (0x16U - iVar2 & 0x1f)) + 1 >> 1;
      }
      else {
        iVar2 = -(((int)(param_1 & 0x7fffff | 0x800000) >> (0x16U - iVar2 & 0x1f)) + 1 >> 1);
      }
    }
    else {
      if (0x1e < iVar2) {
        return 0;
      }
      if ((param_1 & 0x80000000) == 0) {
        iVar2 = (param_1 & 0x7fffff | 0x800000) << (uVar1 - 0x86 & 0x1f);
      }
      else {
        iVar2 = -((param_1 & 0x7fffff | 0x800000) << (uVar1 - 0x86 & 0x1f));
      }
    }
    *param_2 = iVar2;
  }
  return 1;
}



/* c026f228 FUN_c026f228 */

uint FUN_c026f228(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = param_1;
    if ((int)param_1 < 0) {
      uVar1 = -param_1;
    }
    iVar2 = 0;
    if (uVar1 < 0x10000) {
      uVar1 = uVar1 << 0x10;
      iVar2 = 0x10;
    }
    if (uVar1 < 0x1000000) {
      uVar1 = uVar1 << 8;
      iVar2 = iVar2 + 8;
    }
    if (uVar1 < 0x10000000) {
      uVar1 = uVar1 << 4;
      iVar2 = iVar2 + 4;
    }
    if (uVar1 < 0x40000000) {
      uVar1 = uVar1 << 2;
      iVar2 = iVar2 + 2;
    }
    if (uVar1 < 0x80000000) {
      uVar1 = uVar1 << 1;
      iVar2 = iVar2 + 1;
    }
    uVar1 = (0xff8eU - iVar2 & 0xff) << 0x17 | uVar1 + 0x80 >> 8 & 0x7fffff;
    if ((int)param_1 < 0) {
      uVar1 = uVar1 | 0x80000000;
    }
  }
  return uVar1;
}



/* c026f2f0 FUN_c026f2f0 */

/* Boundary evidence: original MIPS .pdata c026f2f0..c026f363. Semantic name remains unreviewed. */

void FUN_c026f2f0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (uint)*(ushort *)(*(int *)(param_1 + 4) + 0x100) * 0x48;
  iVar2 = FUN_c0274d38(uVar1,*(uint *)(param_1 + 0x4c),*(uint *)(param_1 + 0x1c));
  iVar3 = FUN_c0274d38(uVar1,*(uint *)(param_1 + 0x50),*(uint *)(param_1 + 0x20));
  FUN_c026f06c(iVar2,iVar3);
  return;
}



/* c026f364 FUN_c026f364 */

/* Boundary evidence: original MIPS .pdata c026f364..c026f457. Semantic name remains unreviewed. */

void FUN_c026f364(int param_1)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint local_18;
  uint local_14;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + 0x48);
  if (iVar1 == 0) {
    puVar4 = (undefined1 *)0x0;
  }
  else {
    puVar4 = (undefined1 *)(*(int *)(*(int *)(param_1 + 4) + 0x20) + iVar1);
  }
  uVar5 = *(uint *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 0x74) = 0;
  if (((puVar4 != (undefined1 *)0x0) &&
      (iVar1 = FUN_c0269e54(puVar4,*(int *)(param_1 + 4),*(uint *)(*(int *)(param_1 + 0xa0) + 0x4c),
                            &local_14,&local_18), iVar1 != 0)) && ((int)uVar5 < 0x100)) {
    pbVar2 = puVar4 + 8;
    pbVar3 = pbVar2 + local_14 * local_18;
    if (pbVar2 < pbVar3) {
      uVar5 = uVar5 & 0xff;
      do {
        if (uVar5 <= *pbVar2) {
          if (uVar5 != *pbVar2) {
            return;
          }
          *(byte **)(param_1 + 0x74) = pbVar2;
          return;
        }
        pbVar2 = pbVar2 + local_18;
      } while (pbVar2 < pbVar3);
    }
  }
  return;
}



/* c026f458 FUN_c026f458 */

/* Boundary evidence: original MIPS .pdata c026f458..c026f5e3. Semantic name remains unreviewed. */

int FUN_c026f458(int param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = *(ushort *)(*(int *)(param_1 + 0x98) + 0x5c) & 3;
  iVar5 = 1;
  if (uVar2 == 1) {
    iVar3 = -1;
  }
  else {
    iVar3 = 1;
    if (uVar2 != 3) {
      iVar3 = 0;
    }
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x98) + 0x68);
  if ((((*(int *)(*(int *)(param_1 + 4) + 0x10) != param_1) ||
       (*(ushort *)(param_1 + 0x182) != param_2)) || (iVar3 != param_4)) ||
     ((param_3 != ((*(uint *)(param_1 + 100) & 0x80) != 0) || (iVar4 != param_5)))) {
    *(short *)(param_1 + 0x182) = (short)param_2;
    iVar5 = FUN_c026eac8(param_1,param_3,param_4,param_5);
    if (iVar5 == 0) {
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      if (iVar1 != 0) {
        FUN_c026eac8(iVar1,(uint)((*(uint *)(iVar1 + 100) & 0x80) != 0),iVar3,iVar4);
      }
    }
    else {
      iVar3 = *(int *)(param_1 + 4);
      if ((*(int *)(iVar3 + 0x10) != param_1) && ((*(uint *)(iVar3 + 0x158) & 0x10000000) != 0)) {
        iVar4 = (int)*(short *)(iVar3 + 0x174) * *(int *)(param_1 + 0x40);
        if (*(int *)(param_1 + 0x40) < 1) {
          *(int *)(param_1 + 0x184) = -((-iVar4 >> 0xf) + 1 >> 1);
        }
        else {
          *(int *)(param_1 + 0x184) = (iVar4 >> 0xf) + 1 >> 1;
        }
      }
      *(int *)(iVar3 + 0x10) = param_1;
    }
  }
  return iVar5;
}



/* c026f5e4 FUN_c026f5e4 */

void FUN_c026f5e4(int *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  
  uVar3 = param_1[6];
  param_1[0x1a] = 5;
  bVar1 = false;
  bVar2 = true;
  if (((uVar3 & 0x2000) != 0) && ((param_1[0x19] & 3U) != 0)) {
    bVar1 = true;
  }
  if ((((param_1[0x11] != 0) || (param_1[0x13] != 0)) || (param_1[0x10] < 1)) || (param_1[0x14] < 1)
     ) {
    bVar2 = false;
  }
  if (0x32 < param_1[0x1b]) {
    bVar2 = false;
  }
  if ((bVar1) && (bVar2)) {
    if ((*(uint *)(param_1[1] + 0xf8) & 0x100) != 0) {
      if ((uVar3 & 0x2000000) != 0) {
        param_1[6] = uVar3 | 0x10000;
        param_1[0x1a] = 7;
      }
      if ((param_1[6] & 0x20000U) != 0) {
        param_1[6] = param_1[6] & 0xfffdffffU | 0x10000;
        param_1[0x1a] = param_1[0x1a] | 2;
      }
      *(int *)(*param_1 + 0xc) = param_1[6];
    }
    if ((((param_1[0x1a] & 4U) != 0) && ((*(uint *)(param_1[1] + 0xf8) & 0x100) != 0)) &&
       ((param_1[6] & 0x10000000U) != 0)) {
      param_1[0x1a] = param_1[0x1a] | 8;
    }
  }
  return;
}



/* c026f728 FUN_c026f728 */

/* Boundary evidence: original MIPS .pdata c026f728..c026f8db. Semantic name remains unreviewed. */

void FUN_c026f728(int *param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  ushort local_18 [4];
  
  uVar2 = param_1[6];
  param_1[6] = uVar2 | 0x80000000;
  if ((uVar2 & 0x10000) == 0) {
    return;
  }
  param_1[6] = uVar2 & 0xfffeffff | 0x80000000;
  if ((uVar2 & 0x80000) != 0) {
    param_1[6] = uVar2 & 0xfffeffff | 0x80010000;
    goto LAB_c026f8a0;
  }
  iVar3 = *(int *)(param_1[0x28] + 0x70);
  puVar4 = (undefined *)(*(int *)(param_1[1] + 0x20) + iVar3);
  if ((iVar3 == 0) ||
     (iVar3 = FUN_c026a018((int)puVar4,*(uint *)(param_1[0x28] + 0x74),local_18), iVar3 == 0)) {
    puVar4 = PTR_DAT_c029a144;
    if ((*(ushort *)(param_1[1] + 0x15c) & 1) == 0) {
      if ((*(ushort *)(param_1[1] + 0x15c) & 0x20) != 0) {
        puVar4 = &UNK_c02615ec;
        uVar2 = 2;
        goto LAB_c026f810;
      }
      puVar4 = &DAT_c02615dc;
    }
    uVar2 = 3;
  }
  else {
    uVar2 = (uint)local_18[0];
  }
LAB_c026f810:
  iVar3 = param_1[0x1b];
  if (iVar3 < 0x10000) {
    puVar4 = puVar4 + 4;
    if (8 < uVar2) {
      uVar2 = 8;
    }
    puVar5 = puVar4 + uVar2 * 4;
    uVar2 = 0xffffffff;
    for (; puVar4 < puVar5; puVar4 = puVar4 + 4) {
      bVar1 = (int)uVar2 < iVar3;
      uVar2 = (uint)CONCAT11(*puVar4,puVar4[1]);
      if ((bVar1) && (iVar3 <= (int)uVar2)) {
        if ((puVar4[3] & 2) != 0) {
          param_1[6] = param_1[6] | 0x10000;
        }
        break;
      }
    }
  }
LAB_c026f8a0:
  if ((param_1[6] & 0x10000U) == 0) {
    uVar2 = param_1[6] | 0x20000;
    param_1[6] = uVar2;
    *(uint *)(*param_1 + 0xc) = uVar2;
  }
  return;
}



/* c026f8dc FUN_c026f8dc */

/* Boundary evidence: original MIPS .pdata c026f8dc..c026f97b. Semantic name remains unreviewed. */

undefined4 FUN_c026f8dc(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint local_18 [2];
  
  iVar2 = 8;
  iVar1 = FUN_c026a058(param_1,param_3,local_18);
  if ((iVar1 != 0) && (local_18[0] != 0)) {
    do {
      if ((param_2 == *(byte *)(param_1 + 0x2c + iVar2)) &&
         (param_2 == *(byte *)(iVar2 + param_1 + 0x2d))) {
        return 1;
      }
      local_18[0] = local_18[0] - 1;
      iVar2 = iVar2 + 0x30;
    } while (local_18[0] != 0);
  }
  return 0;
}



/* c026f97c FUN_c026f97c */

/* Boundary evidence: original MIPS .pdata c026f97c..c026facf. Semantic name remains unreviewed. */

void FUN_c026f97c(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  param_1[6] = param_1[6] | 0x80000000;
  if (((*(uint *)(param_1[1] + 0xf8) & 0x100) != 0) && ((param_1[0x19] & 3U) != 0)) {
    if ((param_1[0x10] == param_1[0x14]) || (param_1[0x10] == -param_1[0x14])) {
      if ((param_1[0x11] == param_1[0x13]) || (param_1[0x11] == -param_1[0x13])) {
        iVar2 = *(int *)(param_1[0x28] + 0x98);
        if ((iVar2 != 0) &&
           (iVar2 = FUN_c026f8dc(*(int *)(param_1[1] + 0x20) + iVar2,
                                 (uint)*(ushort *)(param_1 + 0x1b),*(uint *)(param_1[0x28] + 0x9c)),
           iVar2 != 0)) {
          uVar1 = param_1[6] & 0xeffeffffU | 0x2000000;
          param_1[6] = uVar1;
          *(uint *)(*param_1 + 0xc) = uVar1;
        }
      }
    }
  }
  iVar2 = param_1[1];
  if ((*(uint *)(iVar2 + 0xf8) & 2) == 0) {
    iVar2 = _wcsicmp((wchar_t *)(*(int *)(iVar2 + 0x130) + iVar2 + 0x128),L"Marlett");
    if (iVar2 == 0) {
      uVar1 = param_1[6] & 0xeffeffffU | 0x2000000;
      param_1[6] = uVar1;
      *(uint *)(*param_1 + 0xc) = uVar1;
    }
  }
  else {
    uVar1 = param_1[6] & 0xeffeffffU | 0x2000000;
    param_1[6] = uVar1;
    *(uint *)(*param_1 + 0xc) = uVar1;
  }
  return;
}



/* c026fad0 FUN_c026fad0 */

/* Boundary evidence: original MIPS .pdata c026fad0..c02702b7. Semantic name remains unreviewed. */

undefined4 FUN_c026fad0(int *param_1)

{
  int iVar1;
  longlong *plVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40 [6];
  
  iVar3 = *(int *)(param_1[0x28] + 0x40);
  iVar7 = *(int *)(param_1[0x28] + 0x10) + *(int *)(param_1[1] + 0x20);
  iVar15 = iVar3 + *(int *)(param_1[1] + 0x20);
  if (iVar3 == 0) {
    iVar15 = 0;
  }
  if ((iVar15 == 0) || ((param_1[0x19] & 3U) == 0)) {
    uVar6 = (int)((uint)*(byte *)(iVar7 + 0x2a) << 0x18) >> 0x10 | (uint)*(byte *)(iVar7 + 0x2b);
    uVar12 = -((int)((uint)*(byte *)(iVar7 + 0x26) << 0x18) >> 0x10 | (uint)*(byte *)(iVar7 + 0x27))
    ;
  }
  else {
    uVar6 = (int)((uint)*(byte *)(iVar15 + 0x4a) << 0x18) >> 0x10 | (uint)*(byte *)(iVar15 + 0x4b);
    uVar12 = (int)((uint)*(byte *)(iVar15 + 0x4c) << 0x18) >> 0x10 | (uint)*(byte *)(iVar15 + 0x4d);
  }
  uVar6 = -uVar6;
  if ((int)uVar6 < (int)uVar12) {
    uVar8 = (int)((uint)*(byte *)(iVar7 + 0x24) << 0x18) >> 0x10 | (uint)*(byte *)(iVar7 + 0x25);
    uVar10 = (int)((uint)*(byte *)(iVar7 + 0x28) << 0x18) >> 0x10 | (uint)*(byte *)(iVar7 + 0x29);
    if ((param_1[6] & 0x4000U) != 0) {
      iVar3 = FUN_c0274f80(uVar12,0x5700);
      uVar8 = uVar8 - iVar3;
      iVar3 = FUN_c0274f80(uVar6,0x5700);
      uVar10 = uVar10 - iVar3;
    }
    if ((int)uVar8 < (int)uVar10) {
      param_1[0x1b] = 0;
      param_1[0x1c] = 0;
      param_1[0x61] = 0;
      param_1[0x1d] = 0;
      if (((param_1[0x19] & 1U) == 0) || ((param_1[0x19] & 8U) != 0)) {
        uVar11 = (uint)(*(ushort *)(param_1[1] + 0x100) >> 6);
        puVar9 = (uint *)(param_1 + 10);
        uVar12 = uVar11 + uVar12;
        uVar6 = uVar6 - uVar11;
        local_68 = uVar8;
        local_64 = uVar6;
        local_60 = uVar10;
        local_5c = uVar6;
        local_58 = uVar8;
        local_54 = uVar12;
        local_50 = uVar10;
        local_4c = uVar12;
        iVar3 = FUN_c02762e4(puVar9,&local_48,&local_68,4);
        if (iVar3 == 0) {
          return 0;
        }
        puVar4 = local_40;
        iVar3 = 3;
        uVar8 = local_48;
        uVar10 = local_44;
        do {
          uVar11 = *puVar4;
          if ((int)uVar11 < (int)local_48) {
            local_48 = uVar11;
          }
          if ((int)uVar8 < (int)uVar11) {
            uVar8 = uVar11;
          }
          uVar11 = puVar4[1];
          if ((int)uVar11 < (int)local_44) {
            local_44 = uVar11;
          }
          if ((int)uVar10 < (int)uVar11) {
            uVar10 = uVar11;
          }
          iVar3 = iVar3 + -1;
          puVar4 = puVar4 + 2;
        } while (iVar3 != 0);
        iVar7 = (int)(uVar8 + 0xf) >> 4;
        iVar3 = (int)(uVar10 + 0xf) >> 4;
        iVar15 = iVar7 - ((int)local_48 >> 4);
        uVar11 = iVar3 - ((int)local_44 >> 4);
        local_5c = 0xffffffff;
        local_68 = 1;
        local_64 = 0;
        local_60 = 0;
        plVar2 = (longlong *)(param_1 + 0x34);
        if ((param_1[6] & 0x2000U) == 0) {
          plVar2 = (longlong *)0x0;
        }
        uVar8 = FUN_c02765d4((int *)&local_68,puVar9,(uint *)(param_1 + 0x2b),
                             (uint *)(param_1 + 0x2f),plVar2,(uint *)(param_1 + 0x31));
        plVar2 = (longlong *)(param_1 + 0x40);
        if ((param_1[6] & 0x2000U) == 0) {
          plVar2 = (longlong *)0x0;
        }
        puVar4 = (uint *)(param_1 + 0x3e);
        uVar10 = FUN_c02765d4((int *)&local_60,puVar9,(uint *)(param_1 + 0x38),
                              (uint *)(param_1 + 0x3c),plVar2,puVar4);
        if ((uVar10 & uVar8) == 0) {
          return 0;
        }
        iVar1 = FUN_c0276570(puVar4,uVar6);
        param_1[0x1e] = -iVar1;
        iVar1 = FUN_c0276570(puVar4,uVar12);
        iVar5 = param_1[0x1e] + 0xf >> 4;
        param_1[0x1e] = iVar5;
        param_1[0x1f] = iVar1 + 0xf >> 4;
        iVar1 = FUN_c026344c(param_1[0x3c],iVar5 << 4);
        param_1[0x44] = iVar1;
        iVar1 = FUN_c026344c(param_1[0x3d],param_1[0x1e] << 4);
        param_1[0x45] = iVar1;
        iVar1 = FUN_c026344c(param_1[0x3c],param_1[0x1f] * -0x10);
        param_1[0x46] = iVar1;
        iVar1 = FUN_c026344c(param_1[0x3d],param_1[0x1f] * -0x10);
        param_1[0x47] = iVar1;
        if ((((int)uVar6 < 0) && (0 < (int)uVar12)) && (2 < param_1[0x1f] + param_1[0x1e])) {
          param_1[0x29] = 0;
          param_1[0x2a] = 0;
        }
        else {
          uVar12 = (int)((1 - uVar12) - uVar6) >> 1;
          iVar1 = FUN_c0276570((uint *)(param_1 + 0x38),uVar12);
          param_1[0x29] = (iVar1 >> 3) + 1 >> 1;
          iVar1 = FUN_c0276570((uint *)(param_1 + 0x3a),uVar12);
          param_1[0x2a] = (iVar1 >> 3) + 1 >> 1;
        }
        param_1[0x20] = (int)local_48 >> 4;
        param_1[0x21] = iVar7;
        param_1[0x22] = (int)local_44 >> 4;
        param_1[0x23] = iVar3;
        uVar12 = FUN_c026f2f0((int)param_1);
        param_1[0x1c] = uVar12;
        iVar3 = FUN_c0274d38(uVar12,param_1[8],0x48);
        param_1[0x1b] = iVar3 + 0x8000 >> 0x10 & 0xffff;
      }
      else {
        uVar13 = param_1[0x14];
        uVar14 = param_1[0x10];
        iVar3 = FUN_c0274f80(uVar13,uVar6);
        iVar7 = FUN_c0274f80(uVar13,uVar12);
        if ((int)uVar13 < 1) {
          param_1[0x1e] = iVar3;
          param_1[0x1f] = -iVar7;
          param_1[0x22] = iVar7;
          param_1[0x23] = iVar3;
        }
        else {
          FUN_c0277788((int)param_1);
          if ((param_1[0x19] & 4U) == 0) {
            param_1[0x22] = iVar3;
            param_1[0x23] = iVar7;
          }
          param_1[0x1e] = -param_1[0x22];
          param_1[0x1f] = param_1[0x23];
        }
        if (param_1[0x1b] == 0) {
          iVar3 = FUN_c0274f80(uVar13,(int)*(short *)(param_1[1] + 0x160));
          param_1[0x1b] = iVar3;
          if (iVar3 < 0) {
            param_1[0x1b] = -iVar3;
          }
        }
        iVar3 = FUN_c0274d38(param_1[0x1b] << 0x10,0x48,param_1[8]);
        uVar11 = param_1[0x23] - param_1[0x22];
        param_1[0x1c] = iVar3;
        if ((param_1[0x10] == param_1[0x14]) && (0 < param_1[0x14])) {
          param_1[0x19] = param_1[0x19] | 0x10;
          FUN_c026f364((int)param_1);
        }
        iVar7 = FUN_c0274f80(uVar8 << 4,uVar14);
        iVar15 = FUN_c0274f80(uVar10 << 4,uVar14);
        iVar3 = iVar15;
        if ((int)uVar14 < 0) {
          iVar3 = iVar7;
          iVar7 = iVar15;
        }
        iVar7 = (iVar7 >> 4) + -2;
        iVar15 = (iVar3 + 0xf >> 4) + 1;
        param_1[0x20] = iVar7;
        param_1[0x21] = iVar15;
        iVar15 = iVar15 - iVar7;
        uVar6 = 0xffffffff;
        uVar12 = 1;
        if ((int)uVar14 < 1) {
          uVar12 = 0xffffffff;
        }
        FUN_c0276598((uint *)(param_1 + 0x2f),uVar12);
        FUN_c0276598((uint *)(param_1 + 0x30),0);
        FUN_c0276598((uint *)(param_1 + 0x3c),0);
        if ((int)uVar13 < 1) {
          uVar6 = 1;
        }
        FUN_c0276598((uint *)(param_1 + 0x3d),uVar6);
        iVar3 = param_1[0x1e];
        param_1[0x29] = 0;
        if ((iVar3 < 1) || (param_1[0x1f] < 1)) {
          if (param_1[0x14] < 1) {
            param_1[0x2a] = iVar3 - param_1[0x1f] >> 1;
          }
          else {
            param_1[0x2a] = param_1[0x1f] - iVar3 >> 1;
          }
        }
        else {
          param_1[0x2a] = 0;
        }
      }
      uVar12 = param_1[6] & 0x2000;
      if (uVar12 == 0) {
        *(undefined2 *)(param_1 + 0x60) = 0;
      }
      else {
        *(short *)(param_1 + 0x60) = (short)((param_1[0x1b] * 2 + -1) / 100) + 1;
      }
      if ((iVar15 != 0) && (uVar11 != 0)) {
        if (uVar12 != 0) {
          iVar15 = (uint)*(ushort *)(param_1 + 0x60) + iVar15;
          uVar11 = *(ushort *)(param_1 + 0x60) + uVar11;
        }
        uVar6 = iVar15 + 7U & 0xfffffff8;
        uVar12 = uVar6 + 0x1f & 0xffffffe0;
        param_1[0x24] = uVar6;
        if ((int)uVar12 < 0) {
          uVar12 = uVar12 + 7;
        }
        if ((int)((ulonglong)(uint)((int)uVar12 >> 3) * (ulonglong)uVar11 >> 0x20) == 0) {
          if ((param_1[6] & 0x10000000U) == 0) {
            FUN_c026f728(param_1);
          }
          else {
            FUN_c026f97c(param_1);
          }
          FUN_c026f5e4(param_1);
          if ((param_1[6] & 0x10000U) == 0) {
            iVar3 = uVar6 + 7;
            if (iVar3 < 0) {
              iVar3 = uVar6 + 0xe;
            }
            uVar6 = iVar3 >> 3;
          }
          else if ((param_1[6] & 0x10000000U) == 0) {
            iVar3 = uVar6 + 1;
            if (iVar3 < 0) {
              iVar3 = uVar6 + 2;
            }
            uVar6 = iVar3 >> 1;
          }
          param_1[0x25] = (uVar6 * uVar11 + 3 & 0xfffffffc) + 0x14;
          if ((*(uint *)(param_1[1] + 0xf8) & 0x40) != 0) {
            if ((param_1[0x19] & 0x11U) == 0x11) {
              param_1[0x19] = param_1[0x19] | 0x40;
              return 1;
            }
            return 1;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}



/* c02702b8 FUN_c02702b8 */

/* Boundary evidence: original MIPS .pdata c02702b8..c02704af. Semantic name remains unreviewed. */

void FUN_c02702b8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 4) + 0x100) << 0x10;
  uVar1 = FUN_c026f06c(*(int *)(param_1 + 0x50),*(int *)(param_1 + 0x4c));
  uVar1 = FUN_c0274f80(uVar1,uVar7);
  if ((int)(((int)uVar1 >> 0xf) + 1U & 0xfffffffe) < 4) {
    uVar3 = *(uint *)(param_1 + 100);
    *(uint *)(param_1 + 100) = uVar3 | 0x20;
    if ((uVar3 & 1) == 0) {
      uVar1 = FUN_c0275080(0x20000,uVar1);
      iVar4 = FUN_c0274f80(*(uint *)(param_1 + 0x40),uVar1);
      *(int *)(param_1 + 0x40) = iVar4;
      iVar4 = FUN_c0274f80(*(uint *)(param_1 + 0x44),uVar1);
      *(int *)(param_1 + 0x44) = iVar4;
      iVar4 = FUN_c0274f80(*(uint *)(param_1 + 0x4c),uVar1);
      *(int *)(param_1 + 0x4c) = iVar4;
      uVar1 = FUN_c0274f80(*(uint *)(param_1 + 0x50),uVar1);
      *(uint *)(param_1 + 0x50) = uVar1;
      uVar3 = FUN_c026f228(*(uint *)(param_1 + 0x40));
      *(uint *)(param_1 + 0x28) = uVar3;
      uVar1 = FUN_c026f228(uVar1);
      *(uint *)(param_1 + 0x34) = uVar1;
      uVar1 = FUN_c026f228(-*(int *)(param_1 + 0x44));
      *(uint *)(param_1 + 0x2c) = uVar1;
      uVar1 = FUN_c026f228(-*(int *)(param_1 + 0x4c));
      *(uint *)(param_1 + 0x30) = uVar1;
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x50);
      uVar1 = -uVar3;
      if (-1 < (int)uVar3) {
        uVar1 = uVar3;
      }
      uVar2 = *(uint *)(param_1 + 0x40);
      uVar5 = -uVar2;
      if (-1 < (int)uVar2) {
        uVar5 = uVar2;
      }
      iVar4 = 1;
      iVar6 = 1;
      if ((int)uVar3 < 0) {
        iVar6 = -1;
      }
      if ((int)uVar2 < 0) {
        iVar4 = -1;
      }
      uVar3 = FUN_c0275080(2,(uint)*(ushort *)(*(int *)(param_1 + 4) + 0x100));
      *(uint *)(param_1 + 0x50) = uVar3;
      if (uVar5 != uVar1) {
        uVar3 = FUN_c0274d38(uVar3,uVar5,uVar1);
      }
      *(uint *)(param_1 + 0x40) = uVar3;
      if (iVar6 < 0) {
        *(int *)(param_1 + 0x50) = -*(int *)(param_1 + 0x50);
      }
      if (iVar4 < 0) {
        *(int *)(param_1 + 0x40) = -*(int *)(param_1 + 0x40);
      }
    }
  }
  uVar1 = FUN_c026f06c(*(int *)(param_1 + 0x40),*(int *)(param_1 + 0x44));
  iVar4 = FUN_c0274f80(uVar1,uVar7);
  if (iVar4 < 0x8001) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 8;
  }
  return;
}



/* c02704b0 FUN_c02704b0 */

/* Boundary evidence: original MIPS .pdata c02704b0..c0270603. Semantic name remains unreviewed. */

undefined4 FUN_c02704b0(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  uVar1 = FONTOBJ_pxoGetXform();
  XFORMOBJ_iGetXform(uVar1,param_2 + 10);
  iVar2 = FUN_c026f120(param_2[10],&local_20);
  if ((((iVar2 != 0) && (iVar2 = FUN_c026f120(param_2[0xd],&local_1c), iVar2 != 0)) &&
      (iVar2 = FUN_c026f120(param_2[0xb],&local_18), iVar2 != 0)) &&
     (iVar2 = FUN_c026f120(param_2[0xc],&local_14), iVar2 != 0)) {
    param_2[0x10] = local_20;
    param_2[0x14] = local_1c;
    param_2[0x11] = -local_18;
    param_2[0x13] = -local_14;
    if (((local_18 != 0 || local_20 != 0) && (local_14 != 0 || local_20 != 0)) &&
       ((local_14 != 0 || local_1c != 0 && (local_18 != 0 || local_1c != 0)))) {
      param_2[0x18] = 0x40000000;
      param_2[0x12] = 0;
      param_2[0x15] = 0;
      param_2[0x16] = 0;
      param_2[0x17] = 0;
      param_2[0x19] = 0;
      if ((local_18 == 0) && (local_14 == 0)) {
        param_2[0x19] = 1;
      }
      if ((local_20 == 0) && (local_1c == 0)) {
        param_2[0x19] = param_2[0x19] | 2;
      }
      FUN_c02702b8((int)param_2);
      FUN_c02619f4(param_2 + 2);
      param_2[4] = 0;
      uVar1 = FUN_c026fad0(param_2);
      return uVar1;
    }
  }
  return 0;
}



/* c0270604 FUN_c0270604 */

/* Boundary evidence: original MIPS .pdata c0270604..c027085f. Semantic name remains unreviewed. */

int * FUN_c0270604(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  
  piVar5 = *(int **)(param_1 + 0x14);
  iVar7 = *(int *)(param_1 + 4);
  if (piVar5 == (int *)0x0) {
    return (int *)0x0;
  }
  uVar6 = *(undefined4 *)(piVar5[9] + 0x1c);
  if ((*piVar5 == 0) && (iVar1 = EngMapFontFileFD(uVar6,piVar5 + 4,piVar5 + 5), iVar1 == 0)) {
    return (int *)0x0;
  }
  iVar1 = piVar5[(iVar7 + 2) * 3];
  if (*(int *)(iVar1 + 0x18) == 0) {
    *(int *)(iVar1 + 0x20) = piVar5[4];
    uVar4 = *(uint *)(iVar1 + 0xf0) + *(int *)(iVar1 + 0xf4);
    *(int *)(iVar1 + 0x24) = piVar5[5];
    if ((*(uint *)(iVar1 + 0xf0) <= uVar4) && (uVar4 <= uVar4 + 0x568)) {
      iVar2 = EngAllocMem(0,uVar4 + 0x568,0x64667454);
      *(int *)(iVar1 + 0xc) = iVar2;
      if (iVar2 != 0) {
        iVar2 = FUN_c026e7f4(iVar1);
        if (iVar2 != 0) {
          if (*(short *)(iVar1 + 0x110) == 0) {
            FUN_c026e8ec(iVar1);
          }
          goto LAB_c0270720;
        }
        if (*piVar5 == 0) {
          EngUnmapFontFileFD(uVar6);
        }
        goto LAB_c02706fc;
      }
    }
    if (*piVar5 == 0) {
      EngUnmapFontFileFD(uVar6);
    }
  }
  else {
LAB_c0270720:
    piVar3 = (int *)EngAllocMem(0,0x188,0x64667454);
    *(int **)(iVar1 + 0x14) = piVar3;
    if (piVar3 != (int *)0x0) {
      piVar3[0x28] = iVar1 + 0x3c;
      *piVar3 = param_1;
      piVar3[1] = iVar1;
      piVar3[6] = *(int *)(param_1 + 0xc);
      piVar3[7] = *(int *)(param_1 + 0x18);
      piVar3[8] = *(int *)(param_1 + 0x1c);
      piVar3[9] = *(int *)(param_1 + 0x20);
      piVar3[0x26] = *(int *)(iVar1 + 0xc);
      piVar3[0x27] = *(int *)(iVar1 + 0xc) + 0x70;
      piVar3[0x49] = (uint)((piVar5[iVar7 * 3 + 5] & 1U) == 0);
      iVar7 = FUN_c02704b0(param_1,piVar3);
      if (iVar7 != 0) {
        piVar3[0x48] = 0;
        *(undefined2 *)((int)piVar3 + 0x182) = 0xffff;
        *(undefined4 *)(iVar1 + 0x14) = 0;
        *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
        *piVar5 = *piVar5 + 1;
        return piVar3;
      }
      EngFreeMem(piVar3);
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
    if (*piVar5 == 0) {
      EngUnmapFontFileFD(uVar6);
    }
    if (*(int *)(iVar1 + 0x18) != 0) {
      return (int *)0x0;
    }
LAB_c02706fc:
    EngFreeMem(*(undefined4 *)(iVar1 + 0xc));
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  return (int *)0x0;
}



/* c0270860 FUN_c0270860 */

/* Boundary evidence: original MIPS .pdata c0270860..c0270913. Semantic name remains unreviewed. */

void FUN_c0270860(int param_1)

{
  FUN_c0270604(param_1);
  return;
}



/* c0270914 FUN_c0270914 */

/* Boundary evidence: original MIPS .pdata c0270914..c027091f. Semantic name remains unreviewed. */

undefined4 FUN_c0270914(void)

{
  return 1;
}



/* c0270974 FUN_c0270974 */

/* Boundary evidence: original MIPS .pdata c0270974..c0270e33. Semantic name remains unreviewed. */

int FUN_c0270974(int param_1,int param_2,int *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  code *pcVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  byte bVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  ushort local_68;
  int *local_64;
  int *local_60;
  int *local_44;
  
  if ((param_3 == (int *)0x0) || (bVar1 = false, param_4 == 0)) {
    bVar1 = true;
  }
  iVar6 = *(int *)(param_1 + 0x9c);
  iVar2 = *(int *)(iVar6 + 0x80);
  iVar3 = *(int *)(iVar6 + 0x78);
  iVar4 = *(int *)(iVar6 + 0x7c);
  uVar11 = (uint)*(ushort *)(iVar6 + 0x6e);
  if (bVar1) {
    param_4 = -1;
  }
  if (*(short *)(*(int *)(param_1 + 0x9c) + 0x6c) == 0) {
    iVar2 = 0;
  }
  else {
    if (bVar1) {
      pcVar12 = FUN_c02619ec;
    }
    else if (param_2 == 0) {
      pcVar12 = (code *)&LAB_c0270948;
    }
    else {
      pcVar12 = (code *)&LAB_c0270920;
    }
    iVar9 = ((*(short *)(uVar11 * 2 + iVar4 + -2) + 1) * 0x10000 >> 0x10) * 4;
    uVar18 = *(undefined4 *)(iVar9 + *(int *)(iVar6 + 0x74));
    uVar17 = *(undefined4 *)(iVar9 + *(int *)(iVar6 + 0x70));
    uVar7 = 0;
    local_68 = 0;
    piVar13 = param_3;
    piVar15 = param_3;
    local_44 = param_3;
    if (uVar11 != 0) {
      do {
        iVar6 = (int)*(short *)(uVar7 * 2 + iVar3);
        iVar9 = (int)*(short *)(uVar7 * 2 + iVar4);
        if (iVar6 != iVar9) {
          local_64 = (int *)(*(int *)(*(int *)(param_1 + 0x9c) + 0x70) + iVar6 * 4);
          local_60 = (int *)(*(int *)(*(int *)(param_1 + 0x9c) + 0x74) + iVar6 * 4);
          if (!bVar1) {
            piVar13[1] = 0x18;
            piVar15 = piVar13 + 2;
            local_44 = piVar13;
          }
          piVar10 = piVar13 + 4;
          if ((*(byte *)(iVar6 + iVar2) & 1) == 0) {
            iVar8 = iVar9 - iVar6;
            if ((*(byte *)(iVar9 + iVar2) & 1) == 0) {
              (*pcVar12)(piVar15,local_64[iVar8] + *local_64 >> 1,local_60[iVar8] + *local_60 >> 1,
                         uVar17,uVar18);
            }
            else {
              (*pcVar12)(piVar15,local_64[iVar8],local_60[iVar8],uVar17,uVar18);
            }
          }
          else {
            (*pcVar12)(piVar15,*local_64,*local_60,uVar17,uVar18);
            local_64 = local_64 + 1;
            local_60 = local_60 + 1;
            iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
          }
          while (piVar13 = piVar10, iVar6 <= iVar9) {
            piVar14 = piVar13 + 1;
            bVar16 = ~*(byte *)(iVar6 + iVar2) & 1;
            if (!bVar1) {
              uVar5 = 1;
              if (bVar16 != 0) {
                uVar5 = 2;
              }
              *(undefined2 *)piVar13 = uVar5;
            }
            if (iVar6 <= iVar9) {
              piVar10 = piVar13 + 3;
              do {
                if ((*(byte *)(iVar6 + iVar2) & 1) == bVar16) break;
                if ((int *)(param_4 + (int)param_3) < piVar10) {
                  return -1;
                }
                (*pcVar12)(piVar14,*local_64,*local_60,uVar17,uVar18);
                iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
                piVar10 = piVar10 + 2;
                local_64 = local_64 + 1;
                local_60 = local_60 + 1;
                piVar14 = piVar14 + 2;
              } while (iVar6 <= iVar9);
            }
            piVar10 = piVar14;
            if (bVar16 == 1) {
              piVar10 = piVar14 + 2;
              if ((int *)(param_4 + (int)param_3) < piVar10) {
                return -1;
              }
              if (iVar9 < iVar6) {
                if (!bVar1) {
                  *piVar14 = *piVar15;
                  piVar14[1] = piVar15[1];
                }
              }
              else {
                (*pcVar12)(piVar14,*local_64,*local_60,uVar17,uVar18);
                local_64 = local_64 + 1;
                local_60 = local_60 + 1;
                iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
              }
            }
            if (!bVar1) {
              *(short *)((int)piVar13 + 2) = (short)((int)piVar10 + (-4 - (int)piVar13) >> 3);
            }
          }
          if (!bVar1) {
            *local_44 = (int)piVar13 - (int)local_44;
          }
        }
        local_68 = local_68 + 1;
        uVar7 = (uint)local_68;
      } while (uVar7 < uVar11);
    }
    iVar2 = (int)piVar13 - (int)param_3;
  }
  return iVar2;
}



/* c0270e34 FUN_c0270e34 */

/* Boundary evidence: original MIPS .pdata c0270e34..c0270eb7. Semantic name remains unreviewed. */

undefined4 FUN_c0270e34(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  
  FUN_c026275c(param_2,*(int *)(param_1 + 0x98),param_1);
  iVar1 = FUN_c0272434(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
  if ((iVar1 == 0) && (param_3 != (undefined4 *)0x0)) {
    FUN_c0265714(param_2,(uint)*(ushort *)(*(int *)(param_1 + 0x9c) + 0x24),param_1,param_3);
  }
  return 0;
}



/* c0270eb8 FUN_c0270eb8 */

/* Boundary evidence: original MIPS .pdata c0270eb8..c027113b. Semantic name remains unreviewed. */

int FUN_c0270eb8(int param_1,int param_2,uint param_3,uint param_4,int param_5,undefined4 *param_6,
                int param_7,int *param_8)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint local_f8;
  int local_f4;
  undefined1 auStack_f0 [200];
  
  local_f8 = *(uint *)(param_1 + 0xc);
  if ((*(uint *)(param_1 + 100) & 8) != 0) {
    iVar1 = FUN_c0270e34(param_1,param_3,param_6);
    return iVar1;
  }
  puVar3 = (uint *)(param_1 + 8);
  if (*puVar3 == param_3) {
    if (param_5 != 0) goto LAB_c0270f4c;
    if (*(int *)(param_1 + 0x14) != 0) goto LAB_c0270f44;
  }
  else {
LAB_c0270f44:
    if (param_5 == 0) {
      uVar2 = 0;
    }
    else {
LAB_c0270f4c:
      uVar2 = 2;
    }
    iVar1 = FUN_c02632ec(param_1,param_3,&local_f8,uVar2,&local_f4);
    if (iVar1 == 0) {
      return -1;
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if ((param_4 & 1) == 0) {
    iVar1 = FUN_c0270974(param_1,param_2,param_8,param_7);
    if (iVar1 == -1) {
      return -1;
    }
    if ((((iVar1 == 0) || (param_8 == (int *)0x0)) || (*(int *)(param_1 + 0x124) == 0)) ||
       ((*(uint *)(param_1 + 0x120) & 2) == 0)) goto LAB_c0271038;
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    *(uint *)(param_1 + 0xc) = local_f8;
    *(undefined4 *)(param_1 + 0x14) = 1;
    local_f4 = FUN_c0272bb0(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
    if (local_f4 == 0) {
      FUN_c02770a4(param_1,param_2,param_8,iVar1);
      *(undefined4 *)(param_1 + 0xc) = uVar4;
      goto LAB_c0271038;
    }
LAB_c027100c:
    EngSetLastError(0x3eb);
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
LAB_c0271038:
    if (param_6 != (undefined4 *)0x0) {
      if (*(int *)(param_1 + 0x14) == 0) {
        *(undefined4 *)(param_1 + 0x14) = 1;
        local_f4 = FUN_c0272bb0(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
        if (local_f4 != 0) goto LAB_c027100c;
      }
      if ((*(int *)(param_1 + 0x124) == 0) || ((*(uint *)(param_1 + 0x120) & 2) == 0)) {
        FUN_c02658c4(param_3,local_f8,param_1,*(int *)(param_1 + 0x9c),param_6,(int *)0x0,
                     (uint *)0x0);
      }
      else {
        FUN_c0276fa4(param_1,(int)auStack_f0,*(int *)(param_1 + 0x9c));
        FUN_c02658c4(*(undefined4 *)(param_1 + 0x128),local_f8,param_1,(int)auStack_f0,param_6,
                     (int *)0x0,(uint *)0x0);
      }
    }
    if (param_5 == 0) {
      *puVar3 = param_3;
      *(uint *)(param_1 + 0xc) = local_f8;
    }
    else {
      FUN_c02619f4(puVar3);
    }
  }
  return iVar1;
}



/* c027113c FUN_c027113c */

/* Boundary evidence: original MIPS .pdata c027113c..c027124f. Semantic name remains unreviewed. */

int FUN_c027113c(int param_1,int param_2,uint param_3,uint param_4,int param_5,undefined4 *param_6,
                int param_7,int *param_8)

{
  byte bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  bVar1 = FUN_c0276b64(*(int **)(param_1 + 4),param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = FUN_c0270eb8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    iVar2 = FUN_c0276e58(param_1,1);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) | 2;
      *(uint *)(param_1 + 0x128) = param_3;
      iVar2 = FUN_c0270eb8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      FUN_c0276e58(param_1,0);
      *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) & 0xfffffffd;
    }
  }
  return iVar2;
}



/* c0271250 FUN_c0271250 */

/* Boundary evidence: original MIPS .pdata c0271250..c027138f. Semantic name remains unreviewed. */

int FUN_c0271250(int param_1,uint param_2,uint param_3,undefined4 *param_4,int param_5,int *param_6)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = (uint)((param_3 & 4) != 0);
  if ((*(uint *)(*(int *)(param_1 + 0x14) + 4) & 1) == 0) {
    piVar2 = *(int **)(param_1 + 0x28);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)FUN_c0270860(param_1);
      *(int **)(param_1 + 0x28) = piVar2;
    }
    else {
      piVar2[6] = piVar2[6] & 0x80000000U | *(uint *)(param_1 + 0xc);
    }
    if (piVar2 != (int *)0x0) {
      *piVar2 = param_1;
      iVar1 = FUN_c026f458((int)piVar2,0,0,0,0);
      if (iVar1 != 0) {
        if (piVar2[0x49] != 0) {
          iVar1 = FUN_c027113c((int)piVar2,1,param_2,param_3 & 0xfffffffb,uVar3,param_4,param_5,
                               param_6);
          return iVar1;
        }
        iVar1 = FUN_c0270eb8((int)piVar2,1,param_2,param_3 & 0xfffffffb,uVar3,param_4,param_5,
                             param_6);
        return iVar1;
      }
    }
  }
  return -1;
}



/* c0271390 FUN_c0271390 */

void FUN_c0271390(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2;
  iVar1 = param_2[1];
  while (param_1 = param_1 + -1, param_1 != 0) {
    *param_4 = ((*param_3 + 1) * 2 + iVar2) / 3;
    param_4[1] = ((param_3[1] + 1) * 2 + iVar1) / 3;
    iVar1 = param_3[2] + *param_3;
    iVar2 = iVar1 + 1;
    if (iVar2 < 0) {
      iVar2 = iVar1 + 2;
    }
    iVar2 = iVar2 >> 1;
    iVar1 = param_3[3] + param_3[1] + 1;
    if (iVar1 < 0) {
      iVar1 = param_3[3] + param_3[1] + 2;
    }
    iVar1 = iVar1 >> 1;
    param_4[2] = ((*param_3 + 1) * 2 + iVar2) / 3;
    param_4[3] = ((param_3[1] + 1) * 2 + iVar1) / 3;
    param_4[4] = iVar2;
    param_4[5] = iVar1;
    param_3 = param_3 + 2;
    param_4 = param_4 + 6;
  }
  *param_4 = ((*param_3 + 1) * 2 + iVar2) / 3;
  param_4[1] = ((param_3[1] + 1) * 2 + iVar1) / 3;
  iVar1 = param_3[2];
  iVar2 = param_3[3];
  param_4[2] = ((*param_3 + 1) * 2 + iVar1) / 3;
  param_4[3] = ((param_3[1] + 1) * 2 + iVar2) / 3;
  param_4[4] = iVar1;
  param_4[5] = iVar2;
  return;
}



/* c02714fc FUN_c02714fc */

/* Boundary evidence: original MIPS .pdata c02714fc..c0271823. Semantic name remains unreviewed. */

undefined4 FUN_c02714fc(int param_1,int *param_2,int param_3,int *param_4,int *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *_Src;
  uint uVar4;
  size_t _Size;
  uint uVar5;
  int *piVar6;
  int *_Dst;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *_Src_00;
  int local_e0;
  int aiStack_b8 [36];
  
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  piVar7 = (int *)0x0;
  if (param_5 != (int *)0x0) {
    piVar7 = param_5;
  }
  piVar9 = (int *)((int)param_2 + param_3);
  do {
    if (piVar9 <= param_2) {
      return 1;
    }
    if ((param_1 != 0) && (iVar2 = PATHOBJ_bMoveTo(param_1,param_2[2],param_2[3]), iVar2 == 0)) {
      return 0;
    }
    iVar2 = *param_2;
    piVar8 = param_2 + 2;
    _Dst = piVar7 + 4;
    local_e0 = 0x10;
    piVar6 = piVar8;
    for (_Src_00 = param_2 + 4; _Src_00 < (int *)((int)param_2 + iVar2);
        _Src_00 = _Src_00 + uVar4 * 2 + 1) {
      uVar4 = (uint)*(ushort *)((int)_Src_00 + 2);
      _Size = uVar4 * 8 + 4;
      if ((short)*_Src_00 == 1) {
        if ((param_1 != 0) && (iVar3 = PATHOBJ_bPolyLineTo(param_1,_Src_00 + 1,uVar4), iVar3 == 0))
        {
          return 0;
        }
        if (param_5 != (int *)0x0) {
          memcpy(_Dst,_Src_00,_Size);
        }
      }
      else {
        uVar5 = uVar4 - 1;
        if (6 < uVar5) {
          _Src = (int *)EngAllocMem(0,uVar5 * 0x18,0x64667454);
          if (_Src == (int *)0x0) {
            return 0;
          }
        }
        else {
          _Src = aiStack_b8;
        }
        FUN_c0271390(uVar5,piVar6,_Src_00 + 1,_Src);
        if ((param_1 == 0) || (iVar3 = PATHOBJ_bPolyBezierTo(param_1,_Src,uVar5 * 3), iVar3 != 0)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        _Size = uVar5 * 0x18 + 4;
        if (param_5 != (int *)0x0) {
          *(undefined2 *)_Dst = 3;
          *(short *)((int)_Dst + 2) = (short)(uVar5 * 3);
          memcpy(_Dst + 1,_Src,uVar5 * 0x18);
        }
        if (6 < uVar5) {
          EngFreeMem(_Src);
        }
        if (!bVar1) {
          return 0;
        }
      }
      piVar6 = _Src_00 + (uint)*(ushort *)((int)_Src_00 + 2) * 2 + -1;
      _Dst = (int *)(_Size + (int)_Dst);
      local_e0 = _Size + local_e0;
    }
    if (param_1 != 0) {
      iVar2 = PATHOBJ_bPolyLineTo(param_1,piVar8,1);
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = PATHOBJ_bCloseFigure(param_1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if (param_4 != (int *)0x0) {
      *param_4 = *param_4 + local_e0;
    }
    if (param_5 != (int *)0x0) {
      piVar7[1] = 0x18;
      *piVar7 = local_e0;
      piVar7[2] = *piVar8;
      piVar7[3] = param_2[3];
    }
    param_2 = (int *)((int)param_2 + *param_2);
    piVar7 = (int *)((int)piVar7 + local_e0);
  } while( true );
}



/* c0271824 FUN_c0271824 */

/* Boundary evidence: original MIPS .pdata c0271824..c027195b. Semantic name remains unreviewed. */

int FUN_c0271824(int param_1,uint param_2,uint param_3,undefined4 *param_4,int param_5,int *param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_28 [2];
  
  iVar4 = -1;
  if ((param_3 & 2) == 0) {
    iVar4 = FUN_c0271250(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar1 = FUN_c0271250(param_1,param_2,param_3 & 4,param_4,0,(int *)0x0);
    if (((iVar1 != 0) && (iVar1 != -1)) &&
       (piVar2 = (int *)EngAllocMem(0,iVar1,0x64667454), piVar2 != (int *)0x0)) {
      iVar3 = FUN_c0271250(param_1,param_2,param_3 & 4,param_4,iVar1,piVar2);
      if ((iVar3 != 0) && (iVar3 != -1)) {
        iVar1 = FUN_c02714fc(0,piVar2,iVar1,local_28,param_6);
        if (iVar1 != 0) {
          iVar4 = local_28[0];
        }
      }
      EngFreeMem(piVar2);
    }
  }
  return iVar4;
}



/* c027195c FUN_c027195c */

/* Boundary evidence: original MIPS .pdata c027195c..c0271b33. Semantic name remains unreviewed. */

undefined4 FUN_c027195c(int param_1,uint param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_4 == 0) {
    if (*(int *)(param_1 + 0x124) == 0) {
      iVar1 = FUN_c0270eb8(param_1,0,param_2,1,0,param_3,0,(int *)0x0);
    }
    else {
      iVar1 = FUN_c027113c(param_1,0,param_2,1,0,param_3,0,(int *)0x0);
    }
    if (iVar1 == 0) {
      return 1;
    }
  }
  else {
    if (*(int *)(param_1 + 0x124) == 0) {
      iVar1 = FUN_c0270eb8(param_1,0,param_2,0,0,(undefined4 *)0x0,0,(int *)0x0);
    }
    else {
      iVar1 = FUN_c027113c(param_1,0,param_2,0,0,(undefined4 *)0x0,0,(int *)0x0);
    }
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      else {
        iVar2 = EngAllocMem(0,iVar1,0x64667454);
        *(int *)(param_1 + 0x10) = iVar2;
        if (iVar2 == 0) {
          return 0;
        }
      }
      if (*(int *)(param_1 + 0x124) == 0) {
        iVar2 = FUN_c0270eb8(param_1,0,param_2,0,0,param_3,iVar1,*(int **)(param_1 + 0x10));
      }
      else {
        iVar2 = FUN_c027113c(param_1,0,param_2,0,0,param_3,iVar1,*(int **)(param_1 + 0x10));
      }
      if (iVar2 != -1) {
        uVar3 = FUN_c02714fc(param_4,*(int **)(param_1 + 0x10),iVar1,(int *)0x0,(int *)0x0);
        if (*(int *)(param_1 + 0x10) != 0) {
          EngFreeMem();
          *(undefined4 *)(param_1 + 0x10) = 0;
          return uVar3;
        }
        return uVar3;
      }
      if (*(int *)(param_1 + 0x10) != 0) {
        EngFreeMem();
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
    }
  }
  return 0;
}



/* c0271b34 FUN_c0271b34 */

undefined4 * FUN_c0271b34(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar2 = (int *)(param_1 + 4);
  puVar1 = (undefined4 *)*piVar2;
  if (puVar1 == (undefined4 *)0x0) {
    uVar4 = 0x1001;
  }
  else {
    puVar1[0x39] = piVar2;
    if (piVar2 == (int *)0x0) {
      uVar4 = 0x1003;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x2c);
      puVar1[1] = iVar3;
      if (iVar3 != 0) {
        iVar3 = *(int *)(param_1 + 0x30);
        puVar1[2] = iVar3;
        if (iVar3 == 0) {
          puVar1[2] = FUN_c02619ec;
        }
        if ((puVar1[0x5e] & param_2) != param_2) {
          *param_3 = 0x1005;
          return (undefined4 *)0x0;
        }
        *puVar1 = *(undefined4 *)(param_1 + 0x34);
        *param_3 = 0;
        return puVar1;
      }
      uVar4 = 0x1008;
    }
  }
  *param_3 = uVar4;
  return (undefined4 *)0x0;
}



/* c0271bc0 FUN_c0271bc0 */

undefined4 FUN_c0271bc0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x1009;
  }
  else {
    *param_2 = 0x430;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    if (param_1 == 0) {
      uVar1 = 0x1002;
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0;
      uVar1 = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  return uVar1;
}



/* c0271c34 FUN_c0271c34 */

/* Boundary evidence: original MIPS .pdata c0271c34..c0271cc3. Semantic name remains unreviewed. */

undefined4 FUN_c0271c34(int param_1,int *param_2)

{
  void *_Dst;
  
  _Dst = *(void **)(param_1 + 4);
  *(undefined4 *)((int)_Dst + *param_2 + -4) = 0x73666e74;
  memset(_Dst,0,0x42c);
  memcpy((void *)((int)_Dst + 0x114),&DAT_c0261608,0x24);
  memcpy((void *)((int)_Dst + 0x3e0),&DAT_c0261608,0x24);
  *(undefined4 **)((int)_Dst + 0xe4) = (undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)_Dst + 0x178) = 0;
  FUN_c0277bf8();
  return 0;
}



/* c0271cc4 FUN_c0271cc4 */

/* Boundary evidence: original MIPS .pdata c0271cc4..c0271dbf. Semantic name remains unreviewed. */

int FUN_c0271cc4(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_20 [2];
  
  if (*(int *)(param_1 + 4) == 0) {
    local_20[0] = 0x1003;
  }
  else {
    puVar1 = FUN_c0271b34(param_1,0,local_20);
    if ((puVar1 != (undefined4 *)0x0) && (local_20[0] = FUN_c0279a6c(puVar1), local_20[0] == 0)) {
      puVar3 = puVar1 + 0x56;
      local_20[0] = FUN_c027d134(puVar1,(ushort *)(puVar1 + 0x44),puVar1 + 0x50,puVar3);
      if (local_20[0] == 0) {
        iVar2 = FUN_c0280e6c((int)puVar1,(int)puVar3,puVar1 + 0x7d);
        *(int *)(param_2 + 0x10) = iVar2 + 4;
        iVar2 = FUN_c0280fdc((int)puVar3,puVar1 + 0x67,puVar1 + 0xd5);
        *(int *)(param_2 + 0xc) = iVar2 + 4;
        local_20[0] = FUN_c027cc8c(puVar1,(uint)*(ushort *)(param_1 + 0x38),
                                   (uint)*(ushort *)(param_1 + 0x3a));
        if (local_20[0] == 0) {
          puVar1[0x5e] = 2;
          puVar1[0x60] = 1;
          local_20[0] = 0;
        }
      }
    }
  }
  return local_20[0];
}



/* c0271dc0 FUN_c0271dc0 */

/* Boundary evidence: original MIPS .pdata c0271dc0..c0272433. Semantic name remains unreviewed. */

int FUN_c0271dc0(int param_1,int param_2,int param_3)

{
  short sVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  ushort *puVar9;
  int *piVar10;
  ushort uVar11;
  short *psVar12;
  short local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined4 *local_38;
  void *local_34;
  undefined4 *local_30 [2];
  
  if (((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (*(int *)(param_1 + 0x14) == 0)) {
    return 0x1003;
  }
  *(undefined4 *)(*(int *)(param_2 + 0xc) + *(int *)(param_1 + 0x10) + -4) = 0x73666e74;
  *(undefined4 *)(*(int *)(param_2 + 0x10) + *(int *)(param_1 + 0x14) + -4) = 0x73666e74;
  piVar3 = FUN_c0271b34(param_1,2,&local_38);
  if (piVar3 == (int *)0x0) {
    return (int)local_38;
  }
  piVar3[0xf3] = param_3;
  piVar10 = piVar3 + 0x61;
  FUN_c027db94(*(int *)(piVar3[0x39] + 0xc),piVar3 + 0x67,piVar10);
  FUN_c027dbe0((int)(piVar3 + 0x67),(int)piVar10);
  iVar4 = FUN_c027ddd0(piVar10);
  piVar10 = piVar3 + 0x7d;
  FUN_c027da38(piVar3,(int)(piVar3 + 0x56),*(int *)(piVar3[0x39] + 0x10),piVar10,iVar4,
               (int *)local_30,(int *)&local_34);
  puVar5 = (undefined4 *)FUN_c027dc7c(*(int *)(piVar3[0x39] + 0x10),(int)piVar10);
  local_38 = (undefined4 *)FUN_c027dc94(*(int *)(piVar3[0x39] + 0x10),(int)piVar10);
  memcpy(piVar3 + 0x3a,(void *)piVar3[0x39],0x24);
  piVar3[0x5f] = (uint)(*(int *)(param_1 + 0x48) == 0);
  if (piVar3[0xf3] == 0) {
    piVar3[0x5f] = 1;
    piVar3[0x60] = 0;
  }
  if ((piVar3[0x60] != 0) && (iVar4 = FUN_c027a520(piVar3,local_30[0],local_34), iVar4 != 0)) {
    return iVar4;
  }
  memcpy(piVar3 + 0x45,*(void **)(param_1 + 0x44),0x24);
  piVar3[0x51] = *(int *)(param_1 + 0x40);
  *(undefined2 *)(piVar3 + 0xb9) = *(undefined2 *)(param_1 + 0x4c);
  if (*(int *)(param_1 + 0x68) == 0) {
    *(undefined2 *)(piVar3 + 0x10a) = 0;
  }
  else {
    if (((*(short *)(param_1 + 0x4c) != 4) || (*(int *)(param_1 + 0x58) == 0)) ||
       (((*(ushort *)(param_1 + 0x5c) & 1) != 0 || (*(int *)(param_1 + 100) != 0)))) {
      return 0x1b01;
    }
    *(undefined2 *)(piVar3 + 0xb9) = 0;
    *(undefined2 *)(piVar3 + 0x10a) = *(undefined2 *)(param_1 + 0x4c);
  }
  piVar3[0x109] = *(int *)(param_1 + 0x68);
  sVar1 = *(short *)(param_1 + 0x3c);
  *(undefined2 *)(piVar3 + 0xf6) = 0;
  if ((*(ushort *)(param_1 + 0x5c) & 1) != 0) {
    *(undefined2 *)(piVar3 + 0xf6) = 1;
  }
  if (((*(ushort *)(param_1 + 0x5c) & 2) != 0) && (piVar3[0x46] == 0)) {
    *(ushort *)(piVar3 + 0xf6) = *(ushort *)(piVar3 + 0xf6) | 2;
  }
  if ((*(ushort *)(param_1 + 0x5c) & 4) != 0) {
    *(ushort *)(piVar3 + 0xf6) = *(ushort *)(piVar3 + 0xf6) | 4;
  }
  if (((*(ushort *)(param_1 + 0x5c) & 1) != 0) && (piVar3[0x45] == 0)) {
    *(ushort *)(piVar3 + 0xf6) = *(ushort *)(piVar3 + 0xf6) ^ 4;
  }
  if ((*(ushort *)(param_1 + 0x5c) & 8) != 0) {
    *(ushort *)(piVar3 + 0xf6) = *(ushort *)(piVar3 + 0xf6) | 8;
  }
  uVar2 = *(ushort *)(piVar3 + 0xf6);
  if (((uVar2 & 1) != 0) && ((short)piVar3[0xb9] != 0)) {
    return 0x1701;
  }
  puVar6 = local_30[0];
  puVar7 = local_30[0];
  if ((((uVar2 & 2) == 0) && ((uVar2 & 4) == 0)) && ((uVar2 & 8) == 0)) {
    uVar11 = 0;
    if ((uVar2 & 1) == 0) goto LAB_c0272134;
  }
  else if ((uVar2 & 1) == 0) {
    return 0x1701;
  }
  uVar11 = uVar2;
  if ((uVar2 & 2) != 0) {
    puVar6 = (undefined4 *)FUN_c027dc88(*(int *)(piVar3[0x39] + 0x10),(int)piVar10);
    puVar7 = (undefined4 *)FUN_c027dd38(*(int *)(piVar3[0x39] + 0x10),(int)piVar10);
    memcpy(piVar3 + 0xf7,piVar3 + 0x44,0x44);
    uVar11 = 0;
  }
LAB_c0272134:
  uVar8 = (uint)*(ushort *)(piVar3 + 0xb9);
  if ((((uVar8 != 0) && ((1 << (uVar8 - 1 & 0x1f) & 0x8bU) == 0)) || (0x1f < uVar8)) ||
     ((*(int *)(param_1 + 0x68) != 0 &&
      (((1 << (*(ushort *)(piVar3 + 0x10a) - 1 & 0x1f) & 0x8bU) == 0 ||
       (0x1f < *(ushort *)(piVar3 + 0x10a))))))) {
    return 0x1701;
  }
  piVar3[0xba] = (uint)(uVar8 != 0);
  FUN_c027e358((int)puVar5,(uint)(uVar8 != 0),uVar11);
  puVar9 = (ushort *)(piVar3 + 0x44);
  psVar12 = (short *)((int)piVar3 + 0x3d6);
  piVar10 = piVar3 + 0xf5;
  iVar4 = FUN_c027e208(puVar9,(int)puVar5,*(uint *)(param_1 + 0x38),sVar1,*(short *)(param_1 + 0x3e)
                       ,*(int *)(param_1 + 0x60),*(ushort *)(param_1 + 0x4e),
                       *(ushort *)(param_1 + 0x50),(short)piVar3[0x38],*(int *)(param_1 + 0x54),
                       (short *)piVar10,psVar12);
  if ((*(ushort *)(piVar3 + 0xf6) & 2) != 0) {
    FUN_c027e358((int)puVar6,piVar3[0xba],*(ushort *)(piVar3 + 0xf6));
    iVar4 = FUN_c027e208((ushort *)(piVar3 + 0xf7),(int)puVar6,*(uint *)(param_1 + 0x38),sVar1,
                         *(short *)(param_1 + 0x3e),*(int *)(param_1 + 0x60),
                         *(ushort *)(param_1 + 0x4e),*(ushort *)(param_1 + 0x50),(short)piVar3[0x38]
                         ,*(int *)(param_1 + 0x54),(short *)piVar10,psVar12);
  }
  piVar3[0xf4] = *(int *)(param_1 + 0x58);
  if ((*(int *)(param_1 + 100) != 0) &&
     (((*(ushort *)(param_1 + 0x5c) & 1) == 0 || (*(int *)(param_1 + 0x58) == 0)))) {
    return 0x1b02;
  }
  piVar3[0x108] = *(int *)(param_1 + 100);
  if (iVar4 != 0) {
    return iVar4;
  }
  if (piVar3[0x60] != 0) {
    iVar4 = FUN_c027e374(puVar5,(int)(piVar3 + 0x61),local_38,*(int *)(param_1 + 0x48));
    if (iVar4 != 0) {
      return iVar4;
    }
    piVar3[0x60] = 0;
  }
  if ((*(ushort *)(piVar3 + 0xf6) & 2) != 0) {
    FUN_c0280d38((int)puVar5,(int)puVar6);
  }
  if ((piVar3[0x5f] == 0) &&
     ((iVar4 = FUN_c027e3d4(piVar3,(int)(piVar3 + 0x56),(int)puVar9,puVar5,(int)(piVar3 + 0x61),
                            local_38,*(int *)(param_1 + 0x48)), iVar4 != 0 ||
      (((*(ushort *)(piVar3 + 0xf6) & 2) != 0 &&
       (iVar4 = FUN_c027e3d4(piVar3,(int)(piVar3 + 0x56),(int)(piVar3 + 0xf7),puVar6,
                             (int)(piVar3 + 0x61),puVar7,*(int *)(param_1 + 0x48)), iVar4 != 0))))))
  {
    piVar3[0xf3] = 0;
    return iVar4;
  }
  FUN_c027e0e4(*(int *)(piVar3[0x39] + 0x10),(int)(piVar3 + 0x7d),(int *)(param_2 + 0x84));
  FUN_c027df3c((int)puVar5,(int)puVar9,&local_3a,&local_3c,&local_3e);
  iVar4 = FUN_c02831d8((int)(piVar3 + 0xda),*puVar9,(int)(short)*piVar10,(int)*psVar12,local_3a,
                       local_3c,local_3e);
  if (iVar4 == 0) {
    piVar3[0x5e] = 6;
    return 0;
  }
  return iVar4;
}



/* c0272434 FUN_c0272434 */

/* Boundary evidence: original MIPS .pdata c0272434..c02725ef. Semantic name remains unreviewed. */

int FUN_c0272434(int param_1,int param_2)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 uVar4;
  ushort *puVar5;
  undefined2 auStack_18 [2];
  int local_14;
  
  if (((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (*(int *)(param_1 + 0x14) == 0)) {
    local_14 = 0x1003;
  }
  else {
    puVar2 = FUN_c0271b34(param_1,6,&local_14);
    if (puVar2 != (undefined4 *)0x0) {
      if (*(ushort *)(param_1 + 0x38) == 0xffff) {
        *(undefined2 *)(puVar2 + 0x35) = *(undefined2 *)(param_1 + 0x3a);
        uVar4 = *(undefined2 *)(param_1 + 0x3a);
        *(undefined2 *)(param_2 + 0x26) = 0;
      }
      else {
        iVar3 = FUN_c0279e00(puVar2,(uint)*(ushort *)(param_1 + 0x38));
        if (iVar3 != 0) {
          return iVar3;
        }
        *(undefined2 *)(param_2 + 0x26) = 2;
        uVar4 = *(undefined2 *)(puVar2 + 0x35);
      }
      *(undefined2 *)(param_2 + 0x24) = uVar4;
      if ((int)(*(ushort *)(puVar2 + 0x57) - 1) < (int)(uint)*(ushort *)(puVar2 + 0x35)) {
        local_14 = 0x100a;
      }
      else {
        FUN_c027dc7c(*(int *)(puVar2[0x39] + 0x10),(int)(puVar2 + 0x7d));
        puVar2[0xbc] = (uint)(*(int *)(param_1 + 0x40) == 0);
        puVar2[0xbb] = *(undefined4 *)(param_1 + 0x3c);
        puVar5 = (ushort *)(param_2 + 0x88);
        if (*(int *)(param_1 + 0x40) == 0) {
          iVar3 = FUN_c0283244(puVar2 + 0xda,puVar2,(uint)*(ushort *)(puVar2 + 0x35),
                               *(short *)(puVar2 + 0xb9),auStack_18,puVar5);
          if (iVar3 != 0) {
            return iVar3;
          }
        }
        else {
          *puVar5 = 0;
        }
        sVar1 = *(short *)(puVar2 + 0xb9);
        if (sVar1 == 0) {
          *(undefined2 *)(param_2 + 0xbc) = 0;
          if (puVar2[0x109] != 0) {
            *(short *)(param_2 + 0xbc) = *(short *)(puVar2 + 0x10a) * *(short *)(puVar2 + 0x10a) + 1
            ;
          }
        }
        else {
          *(short *)(param_2 + 0xbc) = sVar1 * sVar1 + 1;
        }
        puVar2[0xbc] = (uint)*puVar5;
        if ((*(ushort *)(puVar2 + 0xf6) & 1) != 0) {
          *puVar5 = 0;
        }
        puVar2[0x5e] = 0xe;
        local_14 = 0;
      }
    }
  }
  return local_14;
}



/* c02725f0 FUN_c02725f0 */

/* Boundary evidence: original MIPS .pdata c02725f0..c0272b77. Semantic name remains unreviewed. */

undefined4 * FUN_c02725f0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  undefined4 *local_58;
  undefined4 *local_54;
  undefined4 *local_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 *local_40 [2];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar8 = 0;
  if (((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (*(int *)(param_1 + 0x14) == 0)) {
    local_50 = (undefined4 *)0x1003;
  }
  else {
    piVar1 = FUN_c0271b34(param_1,0xe,&local_50);
    if (piVar1 != (int *)0x0) {
      iVar5 = piVar1[0x39];
      if ((piVar1[0x3d] != *(int *)(iVar5 + 0xc)) || (piVar1[0x3e] != *(int *)(iVar5 + 0x10))) {
        FUN_c027db94(*(int *)(iVar5 + 0xc),piVar1 + 0x67,piVar1 + 0x61);
        iVar5 = FUN_c027ddd0(piVar1 + 0x61);
        FUN_c027da38(piVar1,(int)(piVar1 + 0x56),*(int *)(piVar1[0x39] + 0x10),piVar1 + 0x7d,iVar5,
                     (int *)local_40,&iStack_44);
        memcpy(piVar1 + 0x3a,(void *)piVar1[0x39],0x24);
      }
      piVar6 = piVar1 + 0x61;
      FUN_c027dbe0((int)(piVar1 + 0x67),(int)piVar6);
      piVar9 = piVar1 + 0x7d;
      local_58 = (undefined4 *)FUN_c027dc7c(*(int *)(piVar1[0x39] + 0x10),(int)piVar9);
      if ((*(ushort *)(piVar1 + 0xf6) & 2) == 0) {
        local_54 = local_40[0];
        local_50 = local_40[0];
      }
      else {
        local_54 = (undefined4 *)FUN_c027dc88(*(int *)(piVar1[0x39] + 0x10),(int)piVar9);
        local_50 = (undefined4 *)FUN_c027dd38(*(int *)(piVar1[0x39] + 0x10),(int)piVar9);
      }
      if (((*(ushort *)(piVar1 + 0xf6) & 1) != 0) && ((*(ushort *)(piVar1 + 0xf6) & 2) == 0)) {
        iVar8 = 1;
      }
      puVar2 = (undefined4 *)FUN_c027dc94(*(int *)(piVar1[0x39] + 0x10),(int)piVar9);
      if (piVar1[0xf3] == 0) {
        piVar1[0x5f] = 0;
        param_3 = 0;
      }
      if (piVar1[0x5f] != 0) {
        piVar1[0x5f] = 0;
        puVar3 = (undefined4 *)
                 FUN_c027e3d4(piVar1,(int)(piVar1 + 0x56),(int)(piVar1 + 0x44),local_58,(int)piVar6,
                              puVar2,0);
        if ((puVar3 != (undefined4 *)0x0) ||
           (((*(ushort *)(piVar1 + 0xf6) & 2) != 0 &&
            (puVar3 = (undefined4 *)
                      FUN_c027e3d4(piVar1,(int)(piVar1 + 0x56),(int)(piVar1 + 0xf7),local_54,
                                   (int)piVar6,local_50,0), puVar3 != (undefined4 *)0x0)))) {
          piVar1[0xf3] = 0;
          return puVar3;
        }
      }
      puVar3 = local_58;
      if (((*(int *)(param_1 + 0x40) == 0) || (piVar1[0xbc] == 0)) ||
         ((*(ushort *)(piVar1 + 0xf6) & 1) != 0)) {
        piVar1[0xd8] = 0;
        piVar7 = piVar1 + 0x55;
        puVar2 = (undefined4 *)
                 FUN_c0283068(piVar1,(int)(piVar1 + 0x56),(ushort *)(piVar1 + 0x44),local_58,
                              (int)piVar6,puVar2,*(int *)(param_1 + 0x3c),param_3,
                              (undefined2 *)(piVar1 + 0x43),(uint *)(piVar1 + 0xd7),(short *)piVar7,
                              piVar1[0xf4],iVar8);
        if (puVar2 != (undefined4 *)0x0) {
          return puVar2;
        }
        if ((*(ushort *)(piVar1 + 0xf6) & 1) != 0) {
          if ((*(ushort *)(piVar1 + 0xf6) & 2) != 0) {
            if (piVar1[0xbc] == 0) {
              FUN_c0280e50((int)piVar6,(int *)&local_58,&iStack_48,&iStack_4c);
            }
            else {
              puVar2 = (undefined4 *)
                       FUN_c028635c((int)(piVar1 + 0xda),piVar1,(int *)&local_58,&iStack_48,
                                    &iStack_4c);
              if (puVar2 != (undefined4 *)0x0) {
                return puVar2;
              }
            }
            if (((short)*piVar7 == 0) || (local_58 == (undefined4 *)0x0)) {
              iVar8 = 0x10000;
            }
            else {
              uVar4 = (*(code *)puVar3[0x29])(puVar3 + 0x38,(short)*piVar7);
              iVar8 = FUN_c0275080((int)local_58,uVar4);
              if (iVar8 < 0) {
                iVar8 = -iVar8;
              }
            }
            local_54[0x60] = iVar8;
            puVar2 = (undefined4 *)
                     FUN_c0283068(piVar1,(int)(piVar1 + 0x56),(ushort *)(piVar1 + 0xf7),local_54,
                                  (int)piVar6,local_50,*(int *)(param_1 + 0x3c),param_3,
                                  (undefined2 *)(piVar1 + 0x43),(uint *)(piVar1 + 0xd7),
                                  (short *)piVar7,piVar1[0xf4],*(ushort *)(piVar1 + 0xf6) & 1);
            if (puVar2 != (undefined4 *)0x0) {
              return puVar2;
            }
          }
          FUN_c0280e18((int)piVar6,0x60000);
          if ((param_3 != 0) && ((*(ushort *)(piVar1 + 0xf6) & 2) != 0)) {
            FUN_c0280e34((int)piVar6,0,(int)local_58 * 6);
          }
        }
        FUN_c027df94((int)piVar6,*(ushort *)(piVar1 + 0xf6) & 1,(int *)(param_2 + 0x70),
                     (int *)(param_2 + 0x74),(int *)(param_2 + 0x78),(int *)(param_2 + 0x7c),
                     (int *)(param_2 + 0x80),(int *)(param_2 + 0xc0),(undefined2 *)(param_2 + 0x6e))
        ;
        FUN_c027e0ac((int)piVar6,&local_38);
        FUN_c027e0c8((int)piVar6,&local_30);
      }
      else {
        piVar1[0xd8] = 1;
        puVar2 = (undefined4 *)FUN_c028621c((int)(piVar1 + 0xda),piVar1,&local_38);
        if (puVar2 != (undefined4 *)0x0) {
          return puVar2;
        }
        puVar2 = (undefined4 *)FUN_c0286508((int)(piVar1 + 0xda),piVar1,&local_30);
        if (puVar2 != (undefined4 *)0x0) {
          return puVar2;
        }
      }
      *(int *)(param_2 + 0x4c) = local_34 << 10;
      *(int *)(param_2 + 0x48) = local_38 * 0x400;
      *(int *)(param_2 + 0xac) = local_30 * 0x400;
      *(int *)(param_2 + 0xb0) = local_2c << 10;
      if ((*(ushort *)(piVar1 + 0xf6) & 1) != 0) {
        *(int *)(param_2 + 0x48) = (local_38 * 0x400 + 3) / 6;
        *(int *)(param_2 + 0xac) = (local_30 * 0x400 + 3) / 6;
      }
      *(short *)(param_2 + 0x6c) = (short)piVar1[0xd7];
      FUN_c027e0e4(*(int *)(piVar1[0x39] + 0x10),(int)piVar9,(int *)(param_2 + 0x84));
      local_50 = (undefined4 *)0x0;
      piVar1[0x5e] = 0x1e;
    }
  }
  return local_50;
}



/* c0272b78 FUN_c0272b78 */

/* Boundary evidence: original MIPS .pdata c0272b78..c0272b93. Semantic name remains unreviewed. */

void FUN_c0272b78(int param_1,int param_2)

{
  FUN_c02725f0(param_1,param_2,0);
  return;
}



/* c0272b94 FUN_c0272b94 */

/* Boundary evidence: original MIPS .pdata c0272b94..c0272baf. Semantic name remains unreviewed. */

void FUN_c0272b94(int param_1,int param_2)

{
  FUN_c02725f0(param_1,param_2,1);
  return;
}



/* c0272bb0 FUN_c0272bb0 */

/* Boundary evidence: original MIPS .pdata c0272bb0..c027363b. Semantic name remains unreviewed. */

int FUN_c0272bb0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  ushort *puVar7;
  short sVar8;
  short *psVar9;
  ushort *_Src;
  int *piVar10;
  undefined2 local_b0;
  short sStack_ae;
  undefined2 auStack_ac [2];
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
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
  ushort auStack_48 [2];
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int aiStack_30 [2];
  
  if (((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (*(int *)(param_1 + 0x14) == 0)) {
    local_a8 = 0x1003;
  }
  else {
    puVar1 = FUN_c0271b34(param_1,0x1e,&local_a8);
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[0x3d] != *(int *)(puVar1[0x39] + 0xc)) {
        FUN_c027db94(*(int *)(puVar1[0x39] + 0xc),puVar1 + 0x67,puVar1 + 0x61);
        FUN_c027dbe0((int)(puVar1 + 0x67),(int)(puVar1 + 0x61));
        memcpy(puVar1 + 0x3a,(void *)puVar1[0x39],0x24);
      }
      iVar2 = FUN_c027dc7c(*(int *)(puVar1[0x39] + 0x10),(int)(puVar1 + 0x7d));
      psVar9 = (short *)((int)puVar1 + 0x26e);
      local_a8 = iVar2;
      if ((puVar1[0xbc] == 0) || ((*(ushort *)(puVar1 + 0xf6) & 1) != 0)) {
        if (puVar1[0x4e] != 0) {
          FUN_c027e0f4((int)(puVar1 + 0x61));
        }
        FUN_c027df94((int)(puVar1 + 0x61),0,&iStack_3c,&iStack_38,&iStack_44,&iStack_40,&iStack_34,
                     aiStack_30,auStack_48);
        iVar2 = FUN_c0277c14(auStack_48);
        if (iVar2 != 0) {
          return iVar2;
        }
        _Src = (ushort *)(puVar1 + 0x9a);
        sVar4 = 1;
        puVar7 = _Src;
        if (puVar1[0xba] != 0) {
          iVar2 = FUN_c02780fc(auStack_48,(uint)*(ushort *)(puVar1 + 0xb9));
          if (iVar2 != 0) {
            return iVar2;
          }
          sVar4 = *(short *)(puVar1 + 0xb9);
          puVar7 = (ushort *)(puVar1 + 0xae);
        }
        FUN_c027df2c(*(int *)(puVar1[0x39] + 0xc),(int)(puVar1 + 0x67),puVar1 + 0xab);
        piVar10 = puVar1 + 0xa5;
        *piVar10 = puVar1[0xd5];
        if (puVar1[0xf4] == 0) {
          sVar6 = 0;
          sVar8 = 0;
        }
        else if (puVar1[0xba] == 0) {
          sVar8 = *(short *)((int)puVar1 + 0x3d6);
          if ((*(ushort *)(puVar1 + 0xf6) & 1) == 0) {
            sVar6 = *(short *)(puVar1 + 0xf5);
          }
          else {
            sVar6 = *(short *)(puVar1 + 0xf5) * 6;
          }
        }
        else {
          sVar6 = *(short *)(puVar1 + 0xf5) * *(short *)(puVar1 + 0xb9);
          sVar8 = *(short *)((int)puVar1 + 0x3d6) * *(short *)(puVar1 + 0xb9);
        }
        iVar2 = FUN_c0278958(auStack_48,puVar7,piVar10,(uint)*(ushort *)(puVar1 + 0x43),sVar4,sVar6,
                             sVar8);
        if (iVar2 == 0x1305) {
          uVar5 = *(ushort *)(puVar1 + 0x43);
          *(short *)(puVar1 + 0x43) = (short)(uVar5 & 0xfffb);
          iVar2 = FUN_c0278958(auStack_48,puVar7,piVar10,uVar5 & 0xfffb,sVar4,sVar6,sVar8);
        }
        if (iVar2 != 0) {
          return iVar2;
        }
        if (puVar1[0xba] != 0) {
          iVar2 = (int)*(short *)(puVar1 + 0xb9);
          if (puVar1[0xbb] == 0) {
            iVar3 = FUN_c02762c0((int)*(short *)(puVar1 + 0xb0),iVar2);
            *(short *)(puVar1 + 0x9c) = (short)iVar3;
            iVar3 = FUN_c02762c0((*(short *)(puVar1 + 0xb1) + iVar2 + -1) * 0x10000 >> 0x10,iVar2);
            *(short *)(puVar1 + 0x9d) = (short)iVar3;
            iVar3 = FUN_c02762c0((int)*(short *)((int)puVar1 + 0x2c2),iVar2);
            *(short *)((int)puVar1 + 0x272) = (short)iVar3;
            iVar2 = FUN_c02762c0((*(short *)((int)puVar1 + 0x2be) + iVar2 + -1) * 0x10000 >> 0x10,
                                 iVar2);
            *psVar9 = (short)iVar2;
          }
          else {
            iVar3 = FUN_c02761b0(puVar1[0xb3],iVar2);
            *(short *)(puVar1 + 0x9c) = (short)(iVar3 + 0x1f >> 6);
            iVar3 = FUN_c02761b0(puVar1[0xb4],iVar2);
            *(short *)(puVar1 + 0x9d) = (short)(iVar3 + 0x20 >> 6);
            iVar3 = FUN_c02761b0(puVar1[0xb5],iVar2);
            *(short *)((int)puVar1 + 0x272) = (short)(iVar3 + 0x1f >> 6);
            iVar2 = FUN_c02761b0(puVar1[0xb6],iVar2);
            sVar4 = (short)(iVar2 + 0x20 >> 6);
            *psVar9 = sVar4;
            if (*(short *)(puVar1 + 0x9c) == *(short *)(puVar1 + 0x9d)) {
              *(short *)(puVar1 + 0x9d) = *(short *)(puVar1 + 0x9d) + 1;
            }
            if (*(short *)((int)puVar1 + 0x272) == sVar4) {
              *psVar9 = sVar4 + 1;
            }
          }
        }
        FUN_c027e190((int)(puVar1 + 0x61),(int)*(short *)(puVar1 + 0x9c) << 6,(int)*psVar9 << 6,
                     &local_98,&local_90,&local_88,&local_68,&local_60);
        *(int *)(param_2 + 0x48) = local_98 << 10;
        *(int *)(param_2 + 0x54) = local_8c << 10;
        *(int *)(param_2 + 0x4c) = local_94 << 10;
        *(int *)(param_2 + 0x50) = local_90 << 10;
        *(int *)(param_2 + 0x40) = local_68 << 10;
        *(int *)(param_2 + 0x30) = local_88 << 10;
        *(int *)(param_2 + 0x34) = local_84 << 10;
        *(int *)(param_2 + 0x3c) = local_5c << 10;
        *(int *)(param_2 + 0x44) = local_64 << 10;
        *(int *)(param_2 + 0x38) = local_60 << 10;
        FUN_c027e1cc((int)(puVar1 + 0x61),(int)*(short *)(puVar1 + 0x9c) << 6,(int)*psVar9 << 6,
                     &local_80,&local_78,&local_70,&local_58,&local_50);
        iVar2 = local_a8;
        *(int *)(param_2 + 0xac) = local_80 << 10;
        *(int *)(param_2 + 0xb0) = local_7c << 10;
        *(int *)(param_2 + 0xb4) = local_78 << 10;
        *(int *)(param_2 + 0xb8) = local_74 << 10;
        *(int *)(param_2 + 0x94) = local_70 << 10;
        *(int *)(param_2 + 0x98) = local_6c << 10;
        *(int *)(param_2 + 0xa4) = local_58 << 10;
        *(int *)(param_2 + 0xa8) = local_54 << 10;
        *(int *)(param_2 + 0x9c) = local_50 << 10;
        *(int *)(param_2 + 0xa0) = local_4c << 10;
        FUN_c027e110((short *)(puVar1 + 0x44),local_a8,*(short *)(puVar1 + 0x55),
                     (uint *)(param_2 + 0x28));
        FUN_c027e150((short *)(puVar1 + 0x44),iVar2,*(short *)((int)puVar1 + 0x156),
                     (uint *)(param_2 + 0x8c));
        memcpy(puVar1 + 0xbd,(uint *)(param_2 + 0x28),0x30);
        memcpy(puVar1 + 0xc9,(uint *)(param_2 + 0x8c),0x30);
        *(undefined2 *)(param_2 + 0x5e) = *(undefined2 *)((int)puVar1 + 0x272);
        *(short *)(param_2 + 0x62) = *psVar9;
        *(undefined4 *)(param_2 + 0x58) = 0;
        if ((*(ushort *)(puVar1 + 0xf6) & 1) == 0) {
          *(undefined2 *)(param_2 + 0x60) = *(undefined2 *)(puVar1 + 0x9c);
          *(undefined2 *)(param_2 + 100) = *(undefined2 *)(puVar1 + 0x9d);
          *(ushort *)(param_2 + 0x5c) = *_Src;
        }
        else {
          *(int *)(param_2 + 0x48) = (*(int *)(param_2 + 0x48) + 3) / 6;
          *(int *)(param_2 + 0x50) = (*(int *)(param_2 + 0x50) + 3) / 6;
          *(int *)(param_2 + 0x30) = (*(int *)(param_2 + 0x30) + 3) / 6;
          *(int *)(param_2 + 0x40) = (*(int *)(param_2 + 0x40) + 3) / 6;
          *(int *)(param_2 + 0x38) = (*(int *)(param_2 + 0x38) + 3) / 6;
          *(int *)(param_2 + 0xac) = (*(int *)(param_2 + 0xac) + 3) / 6;
          *(int *)(param_2 + 0xb4) = (*(int *)(param_2 + 0xb4) + 3) / 6;
          *(int *)(param_2 + 0x94) = (*(int *)(param_2 + 0x94) + 3) / 6;
          *(int *)(param_2 + 0xa4) = (*(int *)(param_2 + 0xa4) + 3) / 6;
          *(int *)(param_2 + 0x9c) = (*(int *)(param_2 + 0x9c) + 3) / 6;
          sVar4 = *(short *)(puVar1 + 0x9c);
          if (sVar4 < 0) {
            sVar4 = (short)((5 - sVar4) / -6);
          }
          else {
            sVar4 = sVar4 / 6;
          }
          *(short *)(param_2 + 0x60) = sVar4;
          iVar3 = *(short *)(puVar1 + 0x9d) + 5;
          iVar2 = (int)*(short *)(puVar1 + 0x9d);
          if (-1 < iVar3) {
            iVar2 = iVar3;
          }
          sVar8 = (short)(iVar2 / 6);
          *(short *)(param_2 + 100) = sVar8;
          puVar7 = (ushort *)(param_2 + 0x5c);
          *puVar7 = (sVar8 - sVar4) + 3U & 0xfffc;
          memcpy(puVar1 + 0xae,_Src,0x2c);
          *_Src = *puVar7;
          *(short *)(puVar1 + 0x9c) = *(short *)(param_2 + 0x60);
          *(short *)(puVar1 + 0x9d) = *(short *)(param_2 + 100);
          puVar1[0xa3] = ((int)*psVar9 - (int)*(short *)((int)puVar1 + 0x272)) * (int)(short)*puVar7
          ;
          *(undefined4 *)(param_2 + 0x20) = puVar1[0xb7];
        }
        if (puVar1[0xba] != 0) {
          uVar5 = (*(short *)(puVar1 + 0x9d) - *(short *)(puVar1 + 0x9c)) + 3U & 0xfffc;
          *(ushort *)(param_2 + 0x5c) = uVar5;
          puVar1[0xa3] = ((int)*psVar9 - (int)*(short *)((int)puVar1 + 0x272)) * (int)(short)uVar5;
          *(undefined4 *)(param_2 + 0x20) = puVar1[0xb7];
        }
        *_Src = *(ushort *)(param_2 + 0x5c);
        *(undefined4 *)(param_2 + 0x14) = puVar1[0xa3];
        *(undefined4 *)(param_2 + 0x18) = puVar1[0xa6];
        *(undefined4 *)(param_2 + 0x1c) = puVar1[0xa7];
      }
      else {
        iVar3 = FUN_c02867bc((int)(puVar1 + 0xda),puVar1,&local_98,&local_90,&local_88,&local_80,
                             &local_78,&local_70,psVar9,&local_b0,&local_a4,local_a0);
        if (iVar3 != 0) {
          return iVar3;
        }
        *(int *)(param_2 + 0x48) = local_98 << 10;
        *(int *)(param_2 + 0x4c) = local_94 << 10;
        *(int *)(param_2 + 0xac) = local_80 << 10;
        *(int *)(param_2 + 0xb0) = local_7c << 10;
        *(int *)(param_2 + 0x50) = local_90 << 10;
        *(int *)(param_2 + 0x54) = local_8c << 10;
        *(int *)(param_2 + 0x30) = local_88 << 10;
        *(int *)(param_2 + 0x34) = local_84 << 10;
        *(int *)(param_2 + 0xb4) = local_78 << 10;
        *(int *)(param_2 + 0xb8) = local_74 << 10;
        *(int *)(param_2 + 0x94) = local_70 << 10;
        *(int *)(param_2 + 0x98) = local_6c << 10;
        *(int *)(param_2 + 0x40) = local_90 << 10;
        *(int *)(param_2 + 0x44) = local_8c << 10;
        *(int *)(param_2 + 0x38) = local_88 << 10;
        *(int *)(param_2 + 0x3c) = local_84 << 10;
        *(int *)(param_2 + 0xa4) = local_78 << 10;
        *(int *)(param_2 + 0xa8) = local_74 << 10;
        *(int *)(param_2 + 0x9c) = local_70 << 10;
        *(int *)(param_2 + 0xa0) = local_6c << 10;
        iVar3 = FUN_c027d6f0(puVar1,(uint)*(ushort *)(puVar1 + 0x35),(undefined2 *)(puVar1 + 0x55),
                             (short *)((int)puVar1 + 0x156),auStack_ac,&sStack_ae);
        if (iVar3 != 0) {
          return iVar3;
        }
        FUN_c027e110((short *)(puVar1 + 0x44),iVar2,*(short *)(puVar1 + 0x55),
                     (uint *)(param_2 + 0x28));
        FUN_c027e150((short *)(puVar1 + 0x44),iVar2,*(short *)((int)puVar1 + 0x156),
                     (uint *)(param_2 + 0x8c));
        *(undefined2 *)(param_2 + 0x60) = *(undefined2 *)(puVar1 + 0x9c);
        *(undefined2 *)(param_2 + 100) = *(undefined2 *)(puVar1 + 0x9d);
        *(undefined2 *)(param_2 + 0x5e) = *(undefined2 *)((int)puVar1 + 0x272);
        *(short *)(param_2 + 0x62) = *psVar9;
        *(undefined2 *)(param_2 + 0x5c) = local_b0;
        *(undefined4 *)(param_2 + 0x58) = 0;
        *(undefined4 *)(param_2 + 0x14) = local_a4;
        *(undefined4 *)(param_2 + 0x18) = local_a0[0];
        *(undefined4 *)(param_2 + 0x1c) = 0;
        *(undefined4 *)(param_2 + 0x20) = 0;
      }
      if (puVar1[0x109] != 0) {
        uVar5 = (*(short *)(param_2 + 100) - *(short *)(param_2 + 0x60)) + 3U & 0xfffc;
        *(ushort *)(param_2 + 0x5c) = uVar5;
        *(int *)(param_2 + 0x14) =
             ((int)*(short *)(param_2 + 0x62) - (int)*(short *)(param_2 + 0x5e)) * (int)(short)uVar5
        ;
      }
      FUN_c027ddd8((int)(puVar1 + 0x67),puVar1[0xd5],puVar1[0xa5],(int *)(param_2 + 0x18),
                   (int *)(param_2 + 0x1c));
      local_a8 = 0;
      *(undefined2 *)(puVar1 + 0x99) = 0;
      *(undefined2 *)((int)puVar1 + 0x266) = 0;
      puVar1[0xd6] = 0;
      puVar1[0x5e] = 0x3e;
    }
  }
  return local_a8;
}



/* c027363c FUN_c027363c */

undefined4 FUN_c027363c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  
  if (param_2 == 2) {
    uVar1 = ((int)*(short *)(param_1 + 0x62) - (int)*(short *)(param_1 + 0x5e)) *
            (int)*(short *)(param_1 + 0x5c);
    if (param_3 == 2) {
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a148)[(int)*pcVar2 & 3];
        } while (uVar3 < uVar1);
      }
    }
    else if (param_3 == 4) {
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a14c)[(int)*pcVar2 & 0xf];
        } while (uVar3 < uVar1);
      }
    }
    else {
      if (param_3 != 8) {
        return 0x1701;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a14c)[(int)*pcVar2 >> 4 & 0xffff];
        } while (uVar3 < uVar1);
      }
    }
  }
  else if (param_2 == 4) {
    uVar1 = ((int)*(short *)(param_1 + 0x62) - (int)*(short *)(param_1 + 0x5e)) *
            (int)*(short *)(param_1 + 0x5c);
    if (param_3 == 2) {
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a15c)[(int)*pcVar2 & 3];
        } while (uVar3 < uVar1);
      }
    }
    else if (param_3 == 4) {
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a160)[(int)*pcVar2 & 0xf];
        } while (uVar3 < uVar1);
      }
    }
    else {
      if (param_3 != 8) {
        return 0x1701;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a160)[(int)*pcVar2 >> 4 & 0xffff];
        } while (uVar3 < uVar1);
      }
    }
  }
  else {
    if (param_2 != 8) {
      return 0x1701;
    }
    uVar1 = ((int)*(short *)(param_1 + 0x62) - (int)*(short *)(param_1 + 0x5e)) *
            (int)*(short *)(param_1 + 0x5c);
    if (param_3 == 2) {
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a170)[(int)*pcVar2 & 3];
        } while (uVar3 < uVar1);
      }
    }
    else if (param_3 == 4) {
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a174)[(int)*pcVar2 & 0xf];
        } while (uVar3 < uVar1);
      }
    }
    else {
      if (param_3 != 8) {
        return 0x1701;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          pcVar2 = (char *)(uVar3 + *(int *)(param_1 + 0x58));
          uVar3 = uVar3 + 1;
          *pcVar2 = (&DAT_c029a174)[(int)*pcVar2 >> 4 & 0xffff];
        } while (uVar3 < uVar1);
      }
    }
  }
  return 0;
}



/* c0273964 FUN_c0273964 */

/* Boundary evidence: original MIPS .pdata c0273964..c0274267. Semantic name remains unreviewed. */

int FUN_c0273964(int param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  ushort *puVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  int iVar10;
  ushort *puVar11;
  int *local_58;
  byte *local_54;
  int local_50;
  int local_4c;
  ushort auStack_48 [2];
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int aiStack_30 [2];
  
  puVar3 = FUN_c0271b34(param_1,0x3e,&local_4c);
  if (puVar3 == (undefined4 *)0x0) {
    return local_4c;
  }
  iVar10 = 0;
  if (puVar3[0x109] != 0) {
    iVar10 = 1;
    if ((*(short *)(puVar3 + 0xf5) != 1) || (*(short *)((int)puVar3 + 0x3d6) != 0)) {
      iVar10 = -1;
    }
    if ((puVar3[0xbc] != 0) && (*(short *)((int)puVar3 + 0x38e) != 0)) {
      iVar10 = -1;
    }
    if ((*(short *)(param_1 + 0x38) < *(short *)(param_1 + 0x3a)) &&
       ((*(short *)(param_1 + 0x3a) < *(short *)((int)puVar3 + 0x26e) ||
        (*(short *)((int)puVar3 + 0x272) < *(short *)(param_1 + 0x38))))) {
      iVar10 = -1;
    }
  }
  if (puVar3[0xd6] == 0) {
    iVar6 = puVar3[0x39];
    if (puVar3[0x3d] != *(int *)(iVar6 + 0xc)) {
      FUN_c027db94(*(int *)(iVar6 + 0xc),puVar3 + 0x67,puVar3 + 0x61);
      FUN_c027dbe0((int)(puVar3 + 0x67),(int)(puVar3 + 0x61));
      iVar6 = puVar3[0x39];
      puVar3[0x3d] = *(undefined4 *)(iVar6 + 0xc);
    }
    FUN_c027dedc(*(int *)(iVar6 + 0xc),(int)(puVar3 + 0x67),*(int *)(iVar6 + 0x18),
                 *(int *)(iVar6 + 0x1c),(int *)&local_54,&local_50);
    if ((puVar3[0xbc] != 0) && ((*(ushort *)(puVar3 + 0xf6) & 1) == 0)) {
      if ((*(short *)(param_1 + 0x38) < *(short *)(param_1 + 0x3a)) &&
         ((*(short *)(param_1 + 0x3a) < *(short *)((int)puVar3 + 0x26e) ||
          (*(short *)((int)puVar3 + 0x272) < *(short *)(param_1 + 0x38))))) {
        return 0x1803;
      }
      if (iVar10 == 1) {
        uVar8 = *(undefined2 *)(puVar3 + 0xf2);
        uVar9 = *(undefined2 *)((int)puVar3 + 0x3ca);
        *(undefined2 *)(puVar3 + 0xf2) = 0;
        *(undefined2 *)((int)puVar3 + 0x3ca) = 0;
      }
      else {
        uVar8 = local_58._0_2_;
        uVar9 = local_58._0_2_;
      }
      iVar6 = FUN_c0285ca4(puVar3 + 0xda,puVar3,*(byte **)(param_1 + 0x18),local_54);
      if (iVar6 == 0) {
        if (iVar10 == 1) {
          *(undefined2 *)(puVar3 + 0xf2) = uVar8;
          *(undefined2 *)((int)puVar3 + 0x3ca) = uVar9;
        }
        if (iVar10 != 0) {
          FUN_c0284334(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18),
                       (int)*(short *)(puVar3 + 0x9d) - (int)*(short *)(puVar3 + 0x9c) & 0xffff,
                       (int)*(short *)((int)puVar3 + 0x26e) - (int)*(short *)((int)puVar3 + 0x272) &
                       0xffff,*(short *)(puVar3 + 0x10a));
        }
        if ((iVar10 == 1) && (*(short *)(puVar3 + 0xe1) != 3)) {
          FUN_c02848f0(*(int *)(param_1 + 0x18),
                       (int)*(short *)(puVar3 + 0x9d) - (int)*(short *)(puVar3 + 0x9c) & 0xffff,
                       (int)*(short *)((int)puVar3 + 0x26e) - (int)*(short *)((int)puVar3 + 0x272) &
                       0xffff);
        }
        *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(puVar3[0x39] + 0x14);
        if (puVar3[0xba] == 0) {
          return 0;
        }
        iVar10 = FUN_c027363c(param_2,(uint)*(ushort *)(puVar3 + 0xb9),
                              (uint)*(ushort *)((int)puVar3 + 0x3c6));
        if (iVar10 == 0) {
          return 0;
        }
        return iVar10;
      }
      return iVar6;
    }
    FUN_c027df2c(*(int *)(puVar3[0x39] + 0xc),(int)(puVar3 + 0x67),puVar3 + 0xab);
    FUN_c027df94((int)(puVar3 + 0x61),0,&iStack_3c,&iStack_38,&iStack_44,&iStack_40,&iStack_34,
                 aiStack_30,auStack_48);
  }
  else {
    if (**(int **)(param_1 + 0x3c) != 0x2d0cbbad) {
      return 0x1600;
    }
    local_58 = *(int **)(param_1 + 0x3c) + 0x43;
    puVar3[0xab] = local_58;
    local_58 = (int *)(puVar3[0xa5] + (int)local_58);
    FUN_c027e020((int *)&local_58,&iStack_3c,&iStack_38,&iStack_44,&iStack_40,&iStack_34,aiStack_30,
                 auStack_48);
    if (*local_58 != 0xa5) {
      return 0x1600;
    }
    local_54 = *(byte **)(puVar3[0x39] + 0x18);
    local_50 = *(int *)(puVar3[0x39] + 0x1c);
  }
  if (local_50 == 0) {
    *(undefined2 *)(puVar3 + 0x43) = 2;
  }
  puVar3[0xa4] = *(undefined4 *)(param_1 + 0x18);
  sVar5 = *(short *)(param_1 + 0x3a);
  *(short *)((int)puVar3 + 0x26a) = sVar5;
  sVar1 = *(short *)(param_1 + 0x38);
  *(short *)(puVar3 + 0x9b) = sVar1;
  if (sVar5 <= sVar1) {
    *(undefined2 *)((int)puVar3 + 0x26a) = *(undefined2 *)((int)puVar3 + 0x26e);
    *(undefined2 *)(puVar3 + 0x9b) = *(undefined2 *)((int)puVar3 + 0x272);
  }
  sVar5 = *(short *)((int)puVar3 + 0x26e);
  if (sVar5 < *(short *)((int)puVar3 + 0x26a)) {
    *(short *)((int)puVar3 + 0x26a) = sVar5;
  }
  sVar1 = *(short *)((int)puVar3 + 0x272);
  if (*(short *)(puVar3 + 0x9b) < sVar1) {
    *(short *)(puVar3 + 0x9b) = sVar1;
  }
  if ((*(short *)(puVar3 + 0x99) == 3) &&
     (((byte *)puVar3[0x40] != local_54 || (puVar3[0x41] != local_50)))) {
    *(undefined2 *)(puVar3 + 0x99) = 2;
  }
  uVar4 = (uint)*(ushort *)(puVar3 + 0x99);
  if (uVar4 == 0) {
    if ((*(short *)((int)puVar3 + 0x26a) == sVar5) && (*(short *)(puVar3 + 0x9b) == sVar1))
    goto LAB_c0273e60;
    if (puVar3[0xba] != 0) {
      return 0x1703;
    }
  }
  else {
    if (uVar4 != 1) goto LAB_c0273e60;
    iVar6 = (int)*(short *)((int)puVar3 + 0x26a) - (int)*(short *)(puVar3 + 0x9b);
    if (puVar3[0xba] == 0) {
      bVar2 = *(short *)((int)puVar3 + 0x266) < iVar6;
    }
    else {
      bVar2 = (int)*(short *)((int)puVar3 + 0x266) < (int)(iVar6 * (uint)*(ushort *)(puVar3 + 0xb9))
      ;
    }
    if (bVar2) {
      return 0x100b;
    }
  }
  *(undefined2 *)(puVar3 + 0x43) = 2;
LAB_c0273e60:
  puVar11 = (ushort *)(puVar3 + 0x9a);
  puVar7 = puVar11;
  if (puVar3[0xba] != 0) {
    puVar7 = (ushort *)(puVar3 + 0xae);
    if (*(short *)((int)puVar3 + 0x26a) == sVar5) {
      *(undefined2 *)((int)puVar3 + 0x2ba) = *(undefined2 *)((int)puVar3 + 0x2be);
    }
    else {
      sVar5 = *(short *)(puVar3 + 0xb9) * *(short *)((int)puVar3 + 0x26a);
      *(short *)((int)puVar3 + 0x2ba) = sVar5;
      if (*(short *)((int)puVar3 + 0x2be) < sVar5) {
        *(short *)((int)puVar3 + 0x2ba) = *(short *)((int)puVar3 + 0x2be);
      }
    }
    if (*(short *)(puVar3 + 0x9b) == sVar1) {
      *(undefined2 *)(puVar3 + 0xaf) = *(undefined2 *)((int)puVar3 + 0x2c2);
    }
    else {
      sVar5 = *(short *)(puVar3 + 0xb9) * *(short *)(puVar3 + 0x9b);
      *(short *)(puVar3 + 0xaf) = sVar5;
      if (sVar5 < *(short *)((int)puVar3 + 0x2c2)) {
        *(short *)(puVar3 + 0xaf) = *(short *)((int)puVar3 + 0x2c2);
      }
    }
    puVar3[0xb8] = *(undefined4 *)(param_1 + 0x24);
  }
  if ((*(ushort *)(puVar3 + 0xf6) & 1) != 0) {
    puVar7 = (ushort *)(puVar3 + 0xae);
    puVar3[0xb8] = *(undefined4 *)(param_1 + 0x24);
    *(undefined2 *)((int)puVar3 + 0x2ba) = *(undefined2 *)((int)puVar3 + 0x2be);
    *(undefined2 *)(puVar3 + 0xaf) = *(undefined2 *)((int)puVar3 + 0x2c2);
  }
  puVar3[0xac] = local_54;
  puVar3[0xad] = local_50;
  iVar6 = FUN_c027919c(auStack_48,(short *)puVar7,(int)(puVar3 + 0xa5),uVar4,
                       *(ushort *)(puVar3 + 0x43));
  if (iVar6 == 0) {
    if ((puVar3[0xba] != 0) &&
       (iVar6 = FUN_c0278254((short *)(puVar3 + 0xae),(short *)puVar11,
                             (uint)*(ushort *)(puVar3 + 0xb9)), iVar6 != 0)) {
      return iVar6;
    }
    iVar6 = puVar3[0x108];
    if (iVar6 != 0) {
      if (((((puVar3[0xf4] == 0) || ((*(ushort *)(puVar3 + 0xf6) & 1) == 0)) || (puVar3[0xbc] != 0))
          || ((*(short *)(puVar3 + 0xf5) != 1 || (*(short *)((int)puVar3 + 0x3d6) != 0)))) ||
         ((*(ushort *)(puVar3 + 0xf6) & 8) != 0)) {
        iVar6 = 0;
      }
      if ((*(short *)(param_1 + 0x38) < *(short *)(param_1 + 0x3a)) &&
         ((*(short *)(param_1 + 0x3a) < *(short *)((int)puVar3 + 0x26e) ||
          (*(short *)((int)puVar3 + 0x272) < *(short *)(param_1 + 0x38))))) {
        iVar6 = 0;
      }
    }
    if (((*(ushort *)(puVar3 + 0xf6) & 1) != 0) && (iVar6 == 0)) {
      FUN_c0286e08((short *)(puVar3 + 0xae),(uint)((*(ushort *)(puVar3 + 0xf6) & 8) != 0),
                   (short *)puVar11);
    }
    if (puVar3[0xf4] != 0) {
      if (puVar3[0xba] == 0) {
        if ((*(ushort *)(puVar3 + 0xf6) & 1) == 0) {
          if (iVar10 != 1) {
            FUN_c02833a4(*(byte **)(puVar7 + 0x14),
                         (int)(short)puVar7[6] - (int)(short)puVar7[4] & 0xffff,
                         (int)(short)puVar7[1] - (int)(short)puVar7[2] & 0xffff,(uint)*puVar7,
                         *(short *)(puVar3 + 0xf5),*(short *)((int)puVar3 + 0x3d6));
          }
          if (iVar10 != 0) {
            FUN_c0284334(*(int *)(puVar7 + 0x14),*(int *)(puVar7 + 0x14),
                         (int)(short)puVar7[6] - (int)(short)puVar7[4] & 0xffff,
                         (int)(short)puVar7[1] - (int)(short)puVar7[2] & 0xffff,
                         *(short *)(puVar3 + 0x10a));
          }
          if (iVar10 == 1) {
            FUN_c02848f0(*(int *)(puVar7 + 0x14),
                         (int)(short)puVar7[6] - (int)(short)puVar7[4] & 0xffff,
                         (int)(short)puVar7[1] - (int)(short)puVar7[2] & 0xffff);
          }
        }
        else if (iVar6 == 0) {
          FUN_c0283ddc((byte *)puVar3[0xa4],
                       (int)*(short *)(puVar3 + 0x9d) - (int)*(short *)(puVar3 + 0x9c) & 0xffff,
                       (int)*(short *)((int)puVar3 + 0x26a) - (int)*(short *)(puVar3 + 0x9b) &
                       0xffff,(uint)*puVar11,*(short *)(puVar3 + 0xf5),
                       *(short *)((int)puVar3 + 0x3d6));
        }
        else {
          FUN_c02873f0((uint)*(ushort *)(puVar3 + 0xe2),(ushort *)(puVar3 + 0xae),puVar11);
          FUN_c0286e08((short *)(puVar3 + 0xae),0,(short *)puVar11);
        }
      }
      else {
        FUN_c0283994((byte *)puVar3[0xa4],
                     (int)*(short *)(puVar3 + 0x9d) - (int)*(short *)(puVar3 + 0x9c) & 0xffff,
                     (int)*(short *)((int)puVar3 + 0x26a) - (int)*(short *)(puVar3 + 0x9b) & 0xffff,
                     (uint)*puVar11,*(short *)(puVar3 + 0xb9) * *(short *)(puVar3 + 0xb9) + 1,
                     *(short *)(puVar3 + 0xf5),*(short *)((int)puVar3 + 0x3d6));
      }
    }
    if (*(short *)(puVar3 + 0x99) == 2) {
      *(undefined2 *)(puVar3 + 0x99) = 3;
      puVar3[0x40] = local_54;
      puVar3[0x41] = local_50;
    }
    *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(puVar3[0x39] + 0x14);
    return 0;
  }
  return iVar6;
}



/* c0274268 FUN_c0274268 */

/* Boundary evidence: original MIPS .pdata c0274268..c02742d7. Semantic name remains unreviewed. */

int FUN_c0274268(int param_1,uint param_2,ushort param_3,short *param_4,undefined2 *param_5)

{
  undefined4 *puVar1;
  int local_18 [2];
  
  puVar1 = FUN_c0271b34(param_1,2,local_18);
  if (puVar1 != (undefined4 *)0x0) {
    local_18[0] = FUN_c027cf14(puVar1,param_2,param_3,param_4,param_5);
  }
  return local_18[0];
}



/* c02742d8 FUN_c02742d8 */

/* Boundary evidence: original MIPS .pdata c02742d8..c0274353. Semantic name remains unreviewed. */

int FUN_c02742d8(int param_1,ushort param_2,ushort param_3,int param_4,int *param_5,uint *param_6)

{
  undefined4 *puVar1;
  int local_18 [2];
  
  puVar1 = FUN_c0271b34(param_1,2,local_18);
  if (puVar1 != (undefined4 *)0x0) {
    local_18[0] = FUN_c027d01c(puVar1,(uint)*(ushort *)(puVar1 + 0x57),param_2,param_3,param_4,
                               param_5,param_6);
  }
  return local_18[0];
}



/* c0274354 FUN_c0274354 */

/* Boundary evidence: original MIPS .pdata c0274354..c027436f. Semantic name remains unreviewed. */

void FUN_c0274354(int param_1,int param_2)

{
  FUN_c0271dc0(param_1,param_2,0);
  return;
}



/* c0274370 FUN_c0274370 */

/* Boundary evidence: original MIPS .pdata c0274370..c027438b. Semantic name remains unreviewed. */

void FUN_c0274370(int param_1,int param_2)

{
  FUN_c0271dc0(param_1,param_2,1);
  return;
}



/* c027438c FUN_c027438c */

void FUN_c027438c(undefined2 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_2 + param_3 * 2 + -2;
  for (; param_2 < puVar1; param_2 = param_2 + 2) {
    *param_1 = CONCAT11(*param_2,param_2[1]);
    param_1 = param_1 + 1;
  }
  *param_1 = 0;
  return;
}



/* c02743d0 FUN_c02743d0 */

void FUN_c02743d0(undefined4 param_1,ushort *param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  
  pbVar1 = param_3 + param_4;
  for (; param_3 < pbVar1; param_3 = param_3 + 1) {
    *param_2 = (ushort)*param_3;
    param_2 = param_2 + 1;
  }
  return;
}



/* c02743fc FUN_c02743fc */

void FUN_c02743fc(undefined4 param_1,ushort *param_2,byte *param_3,int param_4)

{
  ushort *puVar1;
  byte *pbVar2;
  
  pbVar2 = param_3 + param_4 + -1;
  puVar1 = param_2;
  for (; param_3 < pbVar2; param_3 = param_3 + 1) {
    *puVar1 = (ushort)*param_3;
    puVar1 = puVar1 + 1;
  }
  param_2[param_4 + -1] = 0;
  return;
}



/* c0274438 FUN_c0274438 */

undefined2 FUN_c0274438(uint param_1)

{
  return *(undefined2 *)(&DAT_c026162c + (param_1 & 0x1f) * 2);
}



/* c0274454 FUN_c0274454 */

undefined4 FUN_c0274454(uint param_1,int *param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = 0xffffffff;
  uVar1 = 1;
  if ((param_1 & 0x80000000) == 0) {
    uVar3 = 0;
  }
  uVar4 = (uVar3 ^ param_1) - uVar3;
  if (uVar4 == 0) {
    uVar1 = 0;
  }
  else if (uVar4 == 0x80000000) {
    *param_2 = 0x40000000;
    *param_3 = 0xffffffff;
  }
  else {
    uVar6 = 0x40000000;
    uVar5 = 0;
    uVar2 = uVar4 & 0x40000000;
    while (uVar2 == 0) {
      uVar6 = uVar6 >> 1;
      uVar5 = uVar5 + 1;
      uVar2 = uVar6 & uVar4;
    }
    *param_2 = (uVar4 << (uVar5 & 0x1f) ^ uVar3) - uVar3;
    *param_3 = uVar5;
  }
  return uVar1;
}



/* c02744e0 FUN_c02744e0 */

undefined4 FUN_c02744e0(uint *param_1,uint *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  uVar1 = 1;
  if ((uVar2 & 0x80000000) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  uVar4 = param_1[1];
  if ((int)uVar4 < 1) {
    *param_2 = 0;
  }
  else if ((int)uVar4 < 0x21) {
    if (uVar4 == 0x20) {
      *param_2 = uVar2;
    }
    else {
      uVar2 = (uVar2 ^ uVar3) - uVar3 >> (0x1f - uVar4 & 0x1f);
      uVar4 = uVar2 + (param_3 != 0);
      if (uVar4 < uVar2) {
        *param_2 = 0x40000000;
      }
      else {
        *param_2 = (int)uVar4 >> 1;
      }
      *param_2 = (*param_2 ^ uVar3) - uVar3;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c027459c FUN_c027459c */

/* Boundary evidence: original MIPS .pdata c027459c..c02745cf. Semantic name remains unreviewed. */

void FUN_c027459c(uint *param_1,uint *param_2)

{
  uint local_10;
  int local_c;
  
  local_10 = *param_1;
  local_c = param_1[1] + 4;
  FUN_c02744e0(&local_10,param_2,1);
  return;
}



/* c02745d0 FUN_c02745d0 */

uint FUN_c02745d0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  uVar1 = 0;
  if (uVar2 != 0) {
    uVar3 = param_1[1];
    uVar4 = uVar2 & 0x80000000;
    if (uVar4 != 0) {
      uVar2 = -uVar2;
    }
    uVar1 = (uVar2 >> 6 & 1) + (uVar2 >> 7 & 0x7fffff);
    uVar2 = uVar3;
    if (uVar1 == 0x800000) {
      uVar2 = uVar3 + 1;
      uVar1 = 0;
    }
    if ((int)(uVar2 + 0x7d) < (int)uVar3) {
      uVar1 = 0x7fffffff;
    }
    else {
      uVar1 = (uVar2 + 0x7d) * 0x800000 | uVar4 | uVar1;
    }
  }
  return uVar1;
}



/* c0274654 FUN_c0274654 */

/* Boundary evidence: original MIPS .pdata c0274654..c02746b3. Semantic name remains unreviewed. */

void FUN_c0274654(uint param_1,int *param_2)

{
  int iVar1;
  int local_10;
  uint local_c;
  
  local_c = 0;
  local_10 = 0;
  iVar1 = FUN_c0274454(param_1,&local_10,&local_c);
  if (iVar1 == 0) {
    *param_2 = 0;
    param_2[1] = 0;
  }
  else {
    *param_2 = local_10;
    param_2[1] = 0x20 - local_c;
  }
  return;
}



/* c02746b4 FUN_c02746b4 */

void FUN_c02746b4(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (int)param_1 >> 0x17 & 0xff;
  if (uVar3 == 0) {
    *param_2 = 0;
    param_2[1] = 0;
  }
  else {
    uVar1 = param_1 & 0x7fffff | 0x800000;
    iVar2 = uVar1 * 0x80;
    if ((param_1 & 0x80000000) != 0) {
      iVar2 = uVar1 * -0x80;
    }
    *param_2 = iVar2;
    param_2[1] = uVar3 - 0x7d;
  }
  return;
}



/* c027470c FUN_c027470c */

/* Boundary evidence: original MIPS .pdata c027470c..c02747ef. Semantic name remains unreviewed. */

int * FUN_c027470c(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  uint local_18 [2];
  
  if (*param_2 == 0) {
    *param_1 = *param_3;
    iVar2 = param_3[1];
  }
  else if (*param_3 == 0) {
    *param_1 = *param_2;
    iVar2 = param_2[1];
  }
  else {
    piVar1 = param_3;
    if (param_2[1] < param_3[1]) {
      piVar1 = param_2;
      param_2 = param_3;
    }
    if (0x1e < param_2[1] - piVar1[1]) {
      *param_1 = *param_2;
      param_1[1] = param_2[1];
      return param_1;
    }
    local_18[0] = 0;
    FUN_c0274454(((*piVar1 >> 1) >> (param_2[1] - piVar1[1] & 0x1fU)) + (*param_2 >> 1),param_1,
                 local_18);
    iVar2 = (param_2[1] - local_18[0]) + 1;
  }
  param_1[1] = iVar2;
  return param_1;
}



/* c02747f0 FUN_c02747f0 */

/* Boundary evidence: original MIPS .pdata c02747f0..c027497f. Semantic name remains unreviewed. */

uint * FUN_c02747f0(uint *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar4 = *param_3;
  uVar5 = *param_2;
  uVar3 = param_2[1];
  uVar2 = param_3[1];
  iVar1 = (int)((ulonglong)uVar5 * (ulonglong)uVar4);
  uVar4 = uVar5 * ((int)uVar4 >> 0x1f) + ((int)uVar5 >> 0x1f) * uVar4 +
          (int)((ulonglong)uVar5 * (ulonglong)uVar4 >> 0x20);
  if (uVar4 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else if ((uVar4 & 0x80000000) == 0) {
    uVar5 = (uint)(byte)(&DAT_c029a184)[uVar4 >> 0x1c];
    uVar6 = __ll_lshift(iVar1,uVar4,uVar5);
    uVar4 = (uint)(uVar6 >> 0x20);
    *param_1 = uVar4;
    if ((uVar6 & 0x80000000) != 0) {
      *param_1 = uVar4 + 1;
    }
    if ((*param_1 & 0x80000000) != 0) {
      *param_1 = (int)*param_1 >> 1;
      uVar5 = uVar5 - 1;
    }
    param_1[1] = (uVar3 + uVar2) - uVar5;
  }
  else {
    uVar4 = -(uint)(iVar1 != 0) - uVar4;
    uVar5 = (uint)(byte)(&DAT_c029a184)[uVar4 >> 0x1c];
    uVar6 = __ll_lshift(-iVar1,uVar4,uVar5);
    uVar4 = (uint)(uVar6 >> 0x20);
    *param_1 = uVar4;
    if ((uVar6 & 0x80000000) != 0) {
      *param_1 = uVar4 + 1;
    }
    if ((*param_1 & 0x80000000) != 0) {
      *param_1 = (int)*param_1 >> 1;
      uVar5 = uVar5 - 1;
    }
    *param_1 = -*param_1;
    param_1[1] = (uVar3 + uVar2) - uVar5;
  }
  return param_1;
}



/* c0274980 FUN_c0274980 */

/* Boundary evidence: original MIPS .pdata c0274980..c0274ac3. Semantic name remains unreviewed. */

int * FUN_c0274980(int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = *param_2;
  if (uVar2 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    uVar3 = *param_3;
    if (((uVar3 ^ uVar2) & 0x80000000) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0xffffffff;
    }
    if ((uVar2 & 0x80000000) != 0) {
      uVar2 = -uVar2;
    }
    if ((uVar3 & 0x80000000) != 0) {
      uVar3 = -uVar3;
    }
    uVar1 = __ull_div(0,uVar2,uVar3 << 1,0);
    iVar5 = (param_2[1] - param_3[1]) + 1;
    if ((uVar1 & 0x80000000) == 0) {
      uVar2 = __ull_rem(0,uVar2,uVar3 << 1,0);
      if (uVar3 <= uVar2) {
        uVar1 = uVar1 + 1;
      }
    }
    else {
      iVar5 = (param_2[1] - param_3[1]) + 2;
      uVar1 = (uVar1 >> 1) + (uVar1 & 1);
    }
    *param_1 = (uVar1 ^ uVar4) - uVar4;
    param_1[1] = iVar5;
  }
  return param_1;
}



/* c0274ac4 FUN_c0274ac4 */

/* Boundary evidence: original MIPS .pdata c0274ac4..c0274b4b. Semantic name remains unreviewed. */

int * FUN_c0274ac4(int *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2;
  if ((int)uVar1 < 1) {
    if (uVar1 == 0) {
      *param_1 = 0;
      param_1[1] = 0;
    }
  }
  else if ((param_2[1] == 2) && (uVar1 == 0x40000000)) {
    *param_1 = 0x40000000;
    param_1[1] = 2;
  }
  else {
    uVar1 = FUN_c02745d0(param_2);
    uVar1 = sqrtf(uVar1);
    FUN_c02746b4(uVar1,param_1);
  }
  return param_1;
}



/* c0274b4c FUN_c0274b4c */

/* Boundary evidence: original MIPS .pdata c0274b4c..c0274bb7. Semantic name remains unreviewed. */

void FUN_c0274b4c(int *param_1,longlong *param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  lVar3 = (longlong)iVar1;
  if (iVar2 < 1) {
    if (iVar2 < 0) {
      lVar3 = __ll_rshift(iVar1,iVar1 >> 0x1f,-iVar2);
    }
  }
  else {
    lVar3 = __ll_lshift(iVar1,iVar1 >> 0x1f,iVar2);
  }
  *param_2 = lVar3;
  return;
}



/* c0274bb8 FUN_c0274bb8 */

/* Boundary evidence: original MIPS .pdata c0274bb8..c0274c4b. Semantic name remains unreviewed. */

undefined4 FUN_c0274bb8(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0x20 - param_2;
  uVar1 = (undefined4)((ulonglong)param_1 * (ulonglong)param_3);
  if ((iVar3 < 1) || (0x3e < iVar3)) {
    uVar2 = 0;
    if (iVar3 == 0) {
      uVar2 = uVar1;
    }
  }
  else {
    uVar2 = __ll_rshift(uVar1,param_1 * ((int)param_3 >> 0x1f) + ((int)param_1 >> 0x1f) * param_3 +
                              (int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20),iVar3);
  }
  return uVar2;
}



/* c0274c4c FUN_c0274c4c */

/* Boundary evidence: original MIPS .pdata c0274c4c..c0274d37. Semantic name remains unreviewed. */

int FUN_c0274c4c(uint param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint local_18 [2];
  
  uVar2 = param_4 ^ param_1;
  if (param_1 != 0) {
    if ((int)param_1 < 0) {
      param_1 = -param_1;
    }
    if ((int)param_4 < 0) {
      param_3 = -param_3;
      if (param_3 == 0) {
        param_4 = -param_4;
      }
      else {
        param_4 = ~param_4;
      }
    }
    if ((param_4 < param_1) &&
       ((local_18[0] = param_4, iVar1 = FUN_c0277340(param_3,param_4,param_1,(int *)local_18),
        local_18[0] < param_1 >> 1 || (iVar1 = iVar1 + 1, iVar1 != 0)))) {
      if (-1 < (int)uVar2) {
        if (iVar1 < 0) {
          return 0x7fffffff;
        }
        return iVar1;
      }
      if ((iVar1 < 0) && (iVar1 != -0x80000000)) {
        return -0x80000000;
      }
      return -iVar1;
    }
  }
  if (-1 < (int)uVar2) {
    return 0x7fffffff;
  }
  return -0x80000000;
}



/* c0274d38 FUN_c0274d38 */

/* Boundary evidence: original MIPS .pdata c0274d38..c0274d97. Semantic name remains unreviewed. */

void FUN_c0274d38(uint param_1,uint param_2,uint param_3)

{
  FUN_c0274c4c(param_3,param_2,(int)((ulonglong)param_1 * (ulonglong)param_2),
               param_1 * ((int)param_2 >> 0x1f) + ((int)param_1 >> 0x1f) * param_2 +
               (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20));
  return;
}



/* c0274d98 FUN_c0274d98 */

int FUN_c0274d98(uint param_1,uint param_2)

{
  return (((uint)((ulonglong)param_2 * (ulonglong)param_1) >> 0xd) + 1 >> 1) +
         (param_2 * ((int)param_1 >> 0x1f) + ((int)param_2 >> 0x1f) * param_1 +
         (int)((ulonglong)param_2 * (ulonglong)param_1 >> 0x20)) * 0x40000;
}



/* c0274df0 FUN_c0274df0 */

int FUN_c0274df0(int param_1,int param_2)

{
  return (int)(short)(param_1 * param_2 + 0x2000 >> 0xe);
}



/* c0274e0c FUN_c0274e0c */

/* Boundary evidence: original MIPS .pdata c0274e0c..c0274e27. Semantic name remains unreviewed. */

void FUN_c0274e0c(uint param_1,uint param_2,uint param_3)

{
  FUN_c0274d38(param_1,param_2,param_3);
  return;
}



/* c0274e28 FUN_c0274e28 */

uint FUN_c0274e28(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (((((int)param_1 < 0xb505) && ((int)param_2 < 0xb505)) && (-0xb505 < (int)param_1)) &&
     (-0xb505 < (int)param_2)) {
    uVar2 = (int)(param_1 * param_2 + 0x20) >> 6;
  }
  else {
    bVar1 = (int)param_1 < 0;
    if (bVar1) {
      param_1 = -param_1;
    }
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      bVar1 = !bVar1;
    }
    uVar2 = (param_1 & 0xffff) * (param_2 >> 0x10) + (param_1 >> 0x10) * (param_2 & 0xffff);
    uVar3 = uVar2 * 0x10000 + 0x20;
    uVar4 = (param_1 & 0xffff) * (param_2 & 0xffff) + uVar3;
    uVar2 = ((uint)(uVar4 < uVar3) + (uVar2 >> 0x10) + (param_2 >> 0x10) * (param_1 >> 0x10)) *
            0x4000000 | uVar4 >> 6;
    if (bVar1) {
      uVar2 = -uVar2;
    }
  }
  return uVar2;
}



/* c0274f40 FUN_c0274f40 */

int FUN_c0274f40(int param_1,int param_2)

{
  if (param_2 == 0) {
    trap(0x1c00);
  }
  if ((param_2 == -1) && (param_1 << 0xe == -0x80000000)) {
    trap(0x1800);
  }
  return (int)(short)((param_1 << 0xe) / param_2);
}



/* c0274f80 FUN_c0274f80 */

int FUN_c0274f80(uint param_1,uint param_2)

{
  ulonglong uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  bVar2 = false;
  if ((param_1 == 0) || (iVar4 = 1, param_2 == 0)) {
    return 0;
  }
  if (((0 < (int)param_1) && ((int)param_2 < 0)) || (((int)param_1 < 0 && (0 < (int)param_2)))) {
    bVar2 = true;
  }
  uVar1 = (ulonglong)param_1 * (ulonglong)param_2;
  uVar5 = param_1 * ((int)param_2 >> 0x1f) + ((int)param_1 >> 0x1f) * param_2 + (int)(uVar1 >> 0x20)
  ;
  if ((uVar1 & 0x8000) != 0) {
    uVar3 = (uint)uVar1 & 0x7fff;
    if (!bVar2) {
      uVar3 = 1;
    }
    if (uVar3 != 0) goto LAB_c0275014;
  }
  iVar4 = 0;
LAB_c0275014:
  iVar4 = ((uint)uVar1 >> 0x10 | uVar5 * 0x10000) + iVar4;
  if ((uVar5 & 0xffff0000) == 0) {
    if (-1 < iVar4) {
      return iVar4;
    }
  }
  else {
    if ((uVar5 & 0xffff0000) == 0xffff0000) {
      if (iVar4 < 1) {
        return iVar4;
      }
      return -0x80000000;
    }
    if ((uVar5 & 0x80000000) == 0) {
      return -0x80000000;
    }
  }
  return 0x7fffffff;
}



/* c0275080 FUN_c0275080 */

/* Boundary evidence: original MIPS .pdata c0275080..c02750a3. Semantic name remains unreviewed. */

void FUN_c0275080(int param_1,uint param_2)

{
  FUN_c0274c4c(param_2,param_2,param_1 << 0x10,param_1 >> 0x10);
  return;
}



/* c02750a4 FUN_c02750a4 */

/* Boundary evidence: original MIPS .pdata c02750a4..c02750c7. Semantic name remains unreviewed. */

void FUN_c02750a4(int param_1,uint param_2)

{
  FUN_c0274c4c(param_2,param_2,param_1 << 0x10,param_1 >> 0xf);
  return;
}



/* c02750c8 FUN_c02750c8 */

int FUN_c02750c8(uint param_1,uint param_2)

{
  ulonglong uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  bVar2 = false;
  if ((param_1 == 0) || (iVar4 = 1, param_2 == 0)) {
    return 0;
  }
  if (((0 < (int)param_1) && ((int)param_2 < 0)) || (((int)param_1 < 0 && (0 < (int)param_2)))) {
    bVar2 = true;
  }
  uVar1 = (ulonglong)param_1 * (ulonglong)param_2;
  uVar5 = param_1 * ((int)param_2 >> 0x1f) + ((int)param_1 >> 0x1f) * param_2 + (int)(uVar1 >> 0x20)
  ;
  if ((uVar1 & 0x20000000) != 0) {
    if (bVar2) {
      uVar3 = (uint)uVar1 & 0x1fffffff;
    }
    else {
      uVar3 = 1;
    }
    if (uVar3 != 0) goto LAB_c027516c;
  }
  iVar4 = 0;
LAB_c027516c:
  iVar4 = ((uint)uVar1 >> 0x1e | uVar5 * 4) + iVar4;
  if ((uVar5 & 0xc0000000) == 0) {
    if (-1 < iVar4) {
      return iVar4;
    }
  }
  else {
    if ((uVar5 & 0xc0000000) == 0xc0000000) {
      if (iVar4 < 1) {
        return iVar4;
      }
      return -0x80000000;
    }
    if ((uVar5 & 0x80000000) == 0) {
      return -0x80000000;
    }
  }
  return 0x7fffffff;
}



/* c02751d8 FUN_c02751d8 */

/* Boundary evidence: original MIPS .pdata c02751d8..c02751fb. Semantic name remains unreviewed. */

void FUN_c02751d8(int param_1,uint param_2)

{
  FUN_c0274c4c(param_2,param_2,param_1 << 0x1e,param_1 >> 2);
  return;
}



/* c02751fc FUN_c02751fc */

int FUN_c02751fc(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  if ((int)param_1 < 0) {
    iVar1 = -0x80000000;
  }
  else {
    if (0x3fffffff < param_1) {
      param_1 = param_1 + 0xc0000000;
      uVar4 = 0x40000000;
    }
    uVar3 = 0x10000000;
    do {
      uVar2 = param_1;
      if (uVar3 + uVar4 <= param_1) {
        uVar2 = param_1 - (uVar3 + uVar4);
        uVar4 = uVar3 * 2 + uVar4;
      }
      uVar3 = uVar3 >> 1;
      param_1 = uVar2 * 2;
    } while (uVar3 != 0);
    if (uVar4 < param_1) {
      uVar2 = (param_1 - uVar4) * 2 - 1;
      uVar4 = uVar4 + 1;
    }
    else {
      uVar2 = uVar2 << 2;
    }
    iVar1 = (uVar4 < uVar2) + uVar4;
  }
  return iVar1;
}



/* c0275290 FUN_c0275290 */

/* Boundary evidence: original MIPS .pdata c0275290..c02753cb. Semantic name remains unreviewed. */

void FUN_c0275290(uint *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *param_2;
  uVar4 = *param_1;
  uVar3 = *param_3;
  iVar1 = FUN_c0274f80(param_3[3],uVar5);
  iVar2 = FUN_c0274f80(uVar3,uVar4);
  *param_1 = iVar1 + iVar2;
  uVar3 = param_3[1];
  iVar1 = FUN_c0274f80(param_3[4],uVar5);
  iVar2 = FUN_c0274f80(uVar3,uVar4);
  *param_2 = iVar1 + iVar2;
  if ((param_3[2] != 0) || (param_3[5] != 0)) {
    iVar1 = FUN_c02750c8(param_3[2],uVar4);
    iVar2 = FUN_c02750c8(param_3[5],uVar5);
    uVar3 = iVar1 + iVar2 + param_3[8];
    if ((uVar3 != 0) && (uVar3 != 0x10000)) {
      uVar4 = FUN_c0274c4c(uVar3,uVar5,*param_1 << 0x10,(int)*param_1 >> 0x10);
      *param_1 = uVar4;
      uVar5 = FUN_c0274c4c(uVar3,uVar5,*param_2 << 0x10,(int)*param_2 >> 0x10);
      *param_2 = uVar5;
    }
  }
  return;
}



/* c02753cc FUN_c02753cc */

/* Boundary evidence: original MIPS .pdata c02753cc..c02754bb. Semantic name remains unreviewed. */

void FUN_c02753cc(uint *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int local_40 [6];
  
  piVar5 = local_40;
  iVar4 = 2;
  do {
    uVar7 = param_1[1];
    uVar8 = *param_1;
    iVar6 = 3;
    puVar3 = param_2;
    do {
      iVar1 = FUN_c0274f80(uVar7,puVar3[3]);
      iVar2 = FUN_c0274f80(uVar8,*puVar3);
      *piVar5 = iVar1 + iVar2;
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
      puVar3 = puVar3 + 1;
    } while (iVar6 != 0);
    param_1 = param_1 + 3;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar3 = param_2 + 6;
  iVar4 = 5;
  iVar6 = (int)piVar5 - (int)puVar3;
  do {
    puVar3 = puVar3 + -1;
    iVar4 = (iVar4 + -1) * 0x10000 >> 0x10;
    *puVar3 = *(uint *)(iVar6 + (int)puVar3);
  } while (-1 < iVar4);
  return;
}



/* c02754bc FUN_c02754bc */

bool FUN_c02754bc(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  iVar1 = param_1;
  if (param_1 < param_2) {
    iVar1 = param_2;
    param_2 = param_1;
  }
  return iVar1 - param_2 < 0x22;
}



/* c0275508 FUN_c0275508 */

/* Boundary evidence: original MIPS .pdata c0275508..c0275563. Semantic name remains unreviewed. */

uint FUN_c0275508(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 2;
  do {
    bVar1 = FUN_c02754bc(*param_1,param_1[1]);
    uVar2 = CONCAT31(extraout_var,bVar1) | uVar2;
    iVar3 = iVar3 + -1;
    param_1 = param_1 + 3;
  } while (iVar3 != 0);
  return uVar2;
}



/* c0275564 FUN_c0275564 */

undefined4 FUN_c0275564(int *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 != param_1[4]) || (param_1[1] != 0)) || (param_1[3] != 0)) ||
     (uVar1 = 1, param_1[4] < 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c02755a0 FUN_c02755a0 */

undefined4 FUN_c02755a0(int *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 != param_1[4]) || (param_1[1] != 0)) || (param_1[3] != 0)) ||
     (uVar1 = 1, *param_1 != 0x10000)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c02755e0 FUN_c02755e0 */

undefined4 FUN_c02755e0(int *param_1)

{
  undefined4 uVar1;
  
  if ((((param_1[1] != 0) || (param_1[3] != 0)) || (*param_1 < 0)) || (uVar1 = 1, param_1[4] < 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c027561c FUN_c027561c */

undefined4 FUN_c027561c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1[1] == 0) && (param_1[3] == 0)) {
    iVar2 = *param_1;
    iVar3 = iVar2;
    if (iVar2 < 0) {
      iVar3 = -iVar2;
    }
    iVar1 = param_1[4];
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar3 == iVar1) {
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (iVar2 == 0x10000) {
        return 1;
      }
    }
  }
  return 0;
}



/* c0275680 FUN_c0275680 */

bool FUN_c0275680(int param_1,int param_2)

{
  return param_1 == param_2;
}



/* c0275694 FUN_c0275694 */

undefined4 FUN_c0275694(int *param_1)

{
  undefined4 uVar1;
  
  if (((*param_1 == 0) && (param_1[4] == 0)) || ((param_1[3] == 0 && (param_1[1] == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c02756d8 FUN_c02756d8 */

undefined4 FUN_c02756d8(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3];
  if ((iVar1 == 0) && (param_1[1] == 0)) {
    if ((0 < *param_1) && (0 < param_1[4])) {
      return 0;
    }
    if ((*param_1 < 0) && (param_1[4] < 0)) {
      return 2;
    }
  }
  else if ((*param_1 == 0) && (param_1[4] == 0)) {
    if ((iVar1 < 0) && (0 < param_1[1])) {
      return 1;
    }
    if ((0 < iVar1) && (param_1[1] < 0)) {
      return 3;
    }
  }
  return 4;
}



/* c0275780 FUN_c0275780 */

undefined4 FUN_c0275780(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3];
  if ((iVar1 == 0) && (param_1[1] == 0)) {
    if (0 < *param_1) {
      if (0 < param_1[4]) {
        return 0;
      }
      return 4;
    }
    if (*param_1 < 0) {
      if (param_1[4] < 0) {
        return 2;
      }
      return 6;
    }
  }
  else if ((*param_1 == 0) && (param_1[4] == 0)) {
    if (iVar1 < 0) {
      if (0 < param_1[1]) {
        return 1;
      }
      return 7;
    }
    if (0 < iVar1) {
      if (param_1[1] < 0) {
        return 3;
      }
      return 5;
    }
  }
  return 8;
}



/* c0275850 FUN_c0275850 */

undefined4 FUN_c0275850(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  if ((0 < iVar2) &&
     ((((param_1[1] == 0 && (0 < param_1[3])) && (0 < param_1[4])) ||
      (((param_1[1] < 0 && (param_1[3] == 0)) && (0 < param_1[4])))))) {
    return 0;
  }
  if ((((iVar2 == 0) && (0 < param_1[1])) && ((param_1[3] < 0 && (0 < param_1[4])))) ||
     ((((0 < iVar2 && (0 < param_1[1])) && (param_1[3] < 0)) && (param_1[4] == 0)))) {
    return 1;
  }
  if ((iVar2 < 0) &&
     ((((param_1[1] == 0 && (param_1[3] < 0)) && (param_1[4] < 0)) ||
      (((0 < param_1[1] && (param_1[3] == 0)) && (param_1[4] < 0)))))) {
    return 2;
  }
  if (((((iVar2 == 0) && (param_1[1] < 0)) && (0 < param_1[3])) && (param_1[4] < 0)) ||
     (((iVar2 < 0 && (param_1[1] < 0)) && ((0 < param_1[3] && (param_1[4] == 0)))))) {
    return 3;
  }
  if ((0 < iVar2) &&
     ((((param_1[1] == 0 && (0 < param_1[3])) && (param_1[4] < 0)) ||
      (((0 < param_1[1] && (param_1[3] == 0)) && (param_1[4] < 0)))))) {
    return 4;
  }
  if (((iVar2 == 0) && (0 < param_1[1])) && ((0 < param_1[3] && (0 < param_1[4])))) {
LAB_c0275a68:
    uVar1 = 5;
  }
  else {
    if (iVar2 < 0) {
      iVar3 = param_1[1];
      if (((0 < iVar3) && (0 < param_1[3])) && (param_1[4] == 0)) goto LAB_c0275a68;
      if ((((iVar3 == 0) && (param_1[3] < 0)) && (0 < param_1[4])) ||
         (((iVar3 < 0 && (param_1[3] == 0)) && (0 < param_1[4])))) {
        return 6;
      }
    }
    if ((((iVar2 == 0) && (param_1[1] < 0)) && ((param_1[3] < 0 && (param_1[4] < 0)))) ||
       ((((0 < iVar2 && (param_1[1] < 0)) && (param_1[3] < 0)) && (param_1[4] == 0)))) {
      uVar1 = 7;
    }
    else {
      uVar1 = 8;
    }
  }
  return uVar1;
}



/* c0275b24 FUN_c0275b24 */

/* Boundary evidence: original MIPS .pdata c0275b24..c0275caf. Semantic name remains unreviewed. */

void FUN_c0275b24(uint *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar9 = param_1[4];
  uVar7 = param_1[1];
  uVar8 = *param_1;
  uVar5 = param_1[3];
  iVar1 = FUN_c0274f80(uVar7,uVar9);
  iVar2 = FUN_c0274f80(uVar8,uVar5);
  uVar6 = 1;
  if (iVar1 + iVar2 == 0) {
    if (((uVar8 == 0) && (uVar9 == 0)) || ((uVar7 == 0 && (uVar5 == 0)))) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
    *param_2 = iVar1;
    iVar1 = FUN_c0274f80(uVar9,uVar9);
    iVar2 = FUN_c0274f80(uVar5,uVar5);
    iVar3 = FUN_c0274f80(uVar7,uVar7);
    iVar4 = FUN_c0274f80(uVar8,uVar8);
    if (iVar3 + iVar4 != iVar1 + iVar2) goto LAB_c0275c80;
  }
  else {
    uVar6 = 1;
    if ((uVar8 == 0) || (iVar1 = 1, uVar7 == 0)) {
      iVar1 = 0;
    }
    *param_2 = iVar1;
    if (iVar1 != 0) goto LAB_c0275c80;
    iVar1 = FUN_c0274f80(uVar7,uVar7);
    iVar2 = FUN_c0274f80(uVar8,uVar8);
    if (iVar1 + iVar2 != 0x10000) goto LAB_c0275c80;
    iVar1 = FUN_c0274f80(uVar8,uVar9);
    iVar2 = FUN_c0274f80(uVar7,uVar5);
    if (iVar1 - iVar2 != 0x10000) goto LAB_c0275c80;
  }
  uVar6 = 0;
LAB_c0275c80:
  *param_3 = uVar6;
  return;
}



/* c0275cb0 FUN_c0275cb0 */

int FUN_c0275cb0(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



/* c0275cd4 FUN_c0275cd4 */

int FUN_c0275cd4(int param_1,int param_2)

{
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  if (param_1 <= param_2) {
    param_1 = param_2;
  }
  return param_1;
}



/* c0275d04 FUN_c0275d04 */

/* Boundary evidence: original MIPS .pdata c0275d04..c0275dcf. Semantic name remains unreviewed. */

void FUN_c0275d04(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1[2];
  uVar2 = param_1[8];
  if (uVar3 != 0) {
    iVar1 = FUN_c0274d38(uVar3,param_1[6],uVar2);
    *param_1 = *param_1 - iVar1;
    iVar1 = FUN_c0274d38(uVar3,param_1[7],uVar2);
    param_1[1] = param_1[1] - iVar1;
  }
  uVar3 = param_1[5];
  if (uVar3 != 0) {
    iVar1 = FUN_c0274d38(uVar3,param_1[6],uVar2);
    param_1[3] = param_1[3] - iVar1;
    iVar1 = FUN_c0274d38(uVar3,param_1[7],uVar2);
    param_1[4] = param_1[4] - iVar1;
  }
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[8] = (int)(uVar2 + 2) >> 0xe;
  return;
}



/* c0275dd0 FUN_c0275dd0 */

/* Boundary evidence: original MIPS .pdata c0275dd0..c0275f77. Semantic name remains unreviewed. */

void FUN_c0275dd0(int param_1,uint *param_2,uint *param_3,uint *param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  
  if ((param_5 == 0) || (param_6 == 0)) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      *param_3 = 0;
      *param_2 = 0;
      param_3 = param_3 + 1;
      param_2 = param_2 + 1;
    }
  }
  else {
    puVar7 = param_2;
    if (param_5 == 0x10000) {
      uVar1 = *param_4;
      uVar2 = param_4[1];
    }
    else {
      uVar1 = FUN_c0274c4c(param_5,param_2,*param_4 << 0x10,(int)*param_4 >> 0x10);
      uVar2 = FUN_c0274c4c(param_5,puVar7,param_4[1] << 0x10,(int)param_4[1] >> 0x10);
    }
    if (param_6 == 0x10000) {
      uVar3 = param_4[3];
      uVar4 = param_4[4];
    }
    else {
      uVar3 = FUN_c0274c4c(param_6,puVar7,param_4[3] << 0x10,(int)param_4[3] >> 0x10);
      uVar4 = FUN_c0274c4c(param_6,puVar7,param_4[4] << 0x10,(int)param_4[4] >> 0x10);
    }
    while (param_1 = param_1 + -1, -1 < param_1) {
      uVar8 = *param_3;
      uVar9 = *param_2;
      iVar5 = FUN_c0274f80(uVar3,uVar8);
      iVar6 = FUN_c0274f80(uVar1,uVar9);
      *param_2 = iVar5 + iVar6;
      param_2 = param_2 + 1;
      iVar5 = FUN_c0274f80(uVar4,uVar8);
      iVar6 = FUN_c0274f80(uVar2,uVar9);
      *param_3 = iVar5 + iVar6;
      param_3 = param_3 + 1;
    }
  }
  return;
}



/* c0275f78 FUN_c0275f78 */

/* Boundary evidence: original MIPS .pdata c0275f78..c0276043. Semantic name remains unreviewed. */

void FUN_c0275f78(uint param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_c0274d38(param_1,param_3,0x48);
  uVar2 = FUN_c0274f80(param_4[1],uVar1);
  param_4[1] = uVar2;
  uVar2 = FUN_c0274f80(param_4[4],uVar1);
  param_4[4] = uVar2;
  uVar1 = FUN_c0274f80(param_4[7],uVar1);
  param_4[7] = uVar1;
  uVar1 = FUN_c0274d38(param_1,param_2,0x48);
  uVar2 = FUN_c0274f80(*param_4,uVar1);
  *param_4 = uVar2;
  uVar2 = FUN_c0274f80(param_4[3],uVar1);
  param_4[3] = uVar2;
  uVar1 = FUN_c0274f80(param_4[6],uVar1);
  param_4[6] = uVar1;
  return;
}



/* c0276044 FUN_c0276044 */

int FUN_c0276044(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  if (param_1 < 0x10000) {
    if (param_1 < 0x100) {
      if (param_1 < 0x10) {
        iVar1 = *(int *)(&DAT_c026166c + param_1 * 4);
      }
      else {
        iVar1 = *(int *)(&DAT_c026166c + (param_1 >> 4) * 4) + 4;
      }
    }
    else if (param_1 < 0x1000) {
      iVar1 = *(int *)(&DAT_c026166c + (param_1 >> 8) * 4) + 8;
    }
    else {
      iVar1 = *(int *)(&DAT_c026166c + (param_1 >> 0xc) * 4) + 0xc;
    }
  }
  else if (param_1 < 0x1000000) {
    if (param_1 < 0x100000) {
      iVar1 = *(int *)(&DAT_c026166c + (param_1 >> 0x10) * 4) + 0x10;
    }
    else {
      iVar1 = *(int *)(&DAT_c026166c + (param_1 >> 0x14) * 4) + 0x14;
    }
  }
  else if (param_1 < 0x10000000) {
    iVar1 = *(int *)(&DAT_c026166c + (param_1 >> 0x18) * 4) + 0x18;
  }
  else {
    iVar1 = *(int *)(&DAT_c026166c + (param_1 >> 0x1c) * 4) + 0x1c;
  }
  return iVar1;
}



/* c02761b0 FUN_c02761b0 */

int FUN_c02761b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (-1 < param_2) {
    if (param_2 < 2) {
      return param_1;
    }
    if (param_2 == 2) {
      return param_1 >> 1;
    }
    if (param_2 == 4) {
      return param_1 >> 2;
    }
    if (param_2 == 8) {
      return param_1 >> 3;
    }
  }
  if (param_1 < 0) {
    iVar1 = (param_1 - param_2) + 1;
    iVar2 = iVar1 / param_2;
    if (param_2 == 0) {
      trap(0x1c00);
    }
    if ((param_2 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
  }
  else {
    iVar2 = param_1 / param_2;
    if (param_2 == 0) {
      trap(0x1c00);
    }
    if ((param_2 == -1) && (param_1 == -0x80000000)) {
      trap(0x1800);
    }
  }
  return iVar2;
}



/* c0276278 FUN_c0276278 */

int FUN_c0276278(uint param_1)

{
  int iVar1;
  
  if (((param_1 - 1 & param_1) == 0) && (param_1 != 0)) {
    iVar1 = 0;
    for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
      iVar1 = iVar1 + 1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



/* c02762c0 FUN_c02762c0 */

/* Boundary evidence: original MIPS .pdata c02762c0..c02762e3. Semantic name remains unreviewed. */

int FUN_c02762c0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_c02761b0(param_1,param_2);
  return (int)(short)iVar1;
}



/* c02762e4 FUN_c02762e4 */

/* Boundary evidence: original MIPS .pdata c02762e4..c0276503. Semantic name remains unreviewed. */

undefined4 FUN_c02762e4(uint *param_1,uint *param_2,uint *param_3,int param_4)

{
  int iVar1;
  uint local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  uint auStack_50 [2];
  uint local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  uint auStack_28 [2];
  uint auStack_20 [2];
  
  FUN_c02746b4(*param_1,(int *)auStack_28);
  FUN_c02746b4(param_1[1],(int *)&local_30);
  FUN_c02746b4(param_1[2],(int *)&local_38);
  FUN_c02746b4(param_1[3],(int *)auStack_20);
  if ((((local_30 == 0) && (local_2c == 0)) && (local_38 == 0)) && (local_34 == 0)) {
    for (; param_4 != 0; param_4 = param_4 + -1) {
      FUN_c0274654(*param_3,(int *)auStack_50);
      FUN_c02747f0(auStack_50,auStack_50,auStack_28);
      iVar1 = FUN_c027459c(auStack_50,param_2);
      if (iVar1 == 0) {
        return 1;
      }
      FUN_c0274654(param_3[1],(int *)auStack_50);
      FUN_c02747f0(auStack_50,auStack_50,auStack_20);
      iVar1 = FUN_c027459c(auStack_50,param_2 + 1);
      if (iVar1 == 0) {
        return 1;
      }
      param_2 = param_2 + 2;
      param_3 = param_3 + 2;
    }
  }
  else {
    for (; param_4 != 0; param_4 = param_4 + -1) {
      FUN_c0274654(*param_3,(int *)&local_48);
      FUN_c0274654(param_3[1],(int *)&local_40);
      local_58 = local_48;
      local_54 = local_44;
      FUN_c02747f0(&local_58,&local_58,auStack_28);
      local_60 = local_40;
      local_5c = local_3c;
      FUN_c02747f0(&local_60,&local_60,&local_38);
      FUN_c027470c((int *)&local_60,(int *)&local_60,(int *)&local_58);
      iVar1 = FUN_c027459c(&local_60,param_2);
      if (iVar1 == 0) {
        return 1;
      }
      local_58 = local_48;
      local_54 = local_44;
      FUN_c02747f0(&local_58,&local_58,&local_30);
      local_60 = local_40;
      local_5c = local_3c;
      FUN_c02747f0(&local_60,&local_60,auStack_20);
      FUN_c027470c((int *)&local_60,(int *)&local_60,(int *)&local_58);
      iVar1 = FUN_c027459c(&local_60,param_2 + 1);
      if (iVar1 == 0) {
        return 1;
      }
      param_2 = param_2 + 2;
      param_3 = param_3 + 2;
    }
  }
  return 1;
}



/* c0276504 FUN_c0276504 */

/* Boundary evidence: original MIPS .pdata c0276504..c027656f. Semantic name remains unreviewed. */

void FUN_c0276504(uint param_1,uint *param_2,longlong *param_3)

{
  uint auStack_28 [2];
  uint auStack_20 [2];
  uint auStack_18 [2];
  
  FUN_c0274654(param_1,(int *)auStack_28);
  FUN_c02747f0(auStack_20,param_2,auStack_28);
  FUN_c02747f0(auStack_18,param_2 + 2,auStack_28);
  FUN_c0274b4c((int *)auStack_20,param_3);
  FUN_c0274b4c((int *)auStack_18,param_3 + 1);
  return;
}



/* c0276570 FUN_c0276570 */

/* Boundary evidence: original MIPS .pdata c0276570..c0276597. Semantic name remains unreviewed. */

void FUN_c0276570(uint *param_1,uint param_2)

{
  FUN_c0274bb8(*param_1,param_1[1],param_2);
  return;
}



/* c0276598 FUN_c0276598 */

/* Boundary evidence: original MIPS .pdata c0276598..c02765d3. Semantic name remains unreviewed. */

void FUN_c0276598(uint *param_1,uint param_2)

{
  uint uVar1;
  uint auStack_10 [2];
  
  FUN_c0274654(param_2,(int *)auStack_10);
  uVar1 = FUN_c02745d0(auStack_10);
  *param_1 = uVar1;
  return;
}



/* c02765d4 FUN_c02765d4 */

/* Boundary evidence: original MIPS .pdata c02765d4..c027687f. Semantic name remains unreviewed. */

undefined4
FUN_c02765d4(int *param_1,uint *param_2,uint *param_3,uint *param_4,longlong *param_5,uint *param_6)

{
  uint uVar1;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint auStack_38 [2];
  uint auStack_30 [2];
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  
  FUN_c0274654(*param_1 << 4,(int *)&local_58);
  FUN_c0274654(param_1[1] << 4,(int *)&local_50);
  FUN_c02746b4(*param_2,(int *)auStack_38);
  FUN_c02746b4(param_2[1],(int *)&local_40);
  FUN_c02746b4(param_2[2],(int *)&local_48);
  FUN_c02746b4(param_2[3],(int *)auStack_30);
  if ((((local_40 == 0) && (local_3c == 0)) && (local_48 == 0)) && (local_44 == 0)) {
    local_70 = local_58;
    local_6c = local_54;
    FUN_c02747f0(&local_70,&local_70,auStack_38);
    local_68 = local_50;
    local_64 = local_4c;
    FUN_c02747f0(&local_68,&local_68,auStack_30);
  }
  else {
    local_70 = local_58;
    local_6c = local_54;
    FUN_c02747f0(&local_70,&local_70,auStack_38);
    local_60 = local_50;
    local_5c = local_4c;
    FUN_c02747f0(&local_60,&local_60,&local_48);
    FUN_c027470c((int *)&local_70,(int *)&local_70,(int *)&local_60);
    local_60 = local_58;
    local_5c = local_54;
    FUN_c02747f0(&local_60,&local_60,&local_40);
    local_68 = local_50;
    local_64 = local_4c;
    FUN_c02747f0(&local_68,&local_68,auStack_30);
    FUN_c027470c((int *)&local_68,(int *)&local_68,(int *)&local_60);
  }
  *param_3 = local_70;
  param_3[1] = local_6c;
  param_3[2] = local_68;
  param_3[3] = local_64;
  FUN_c02747f0(&local_70,&local_70,&local_70);
  FUN_c02747f0(&local_68,&local_68,&local_68);
  FUN_c027470c((int *)&local_70,(int *)&local_70,(int *)&local_68);
  FUN_c0274ac4((int *)&local_70,&local_70);
  *param_6 = local_70;
  param_6[1] = local_6c;
  FUN_c0274980((int *)&local_28,param_3,param_6);
  FUN_c0274980((int *)&local_20,param_3 + 2,param_6);
  uVar1 = FUN_c02745d0(&local_28);
  *param_4 = uVar1;
  uVar1 = FUN_c02745d0(&local_20);
  param_4[1] = uVar1;
  if (param_5 != (longlong *)0x0) {
    if (local_28 != 0) {
      local_24 = local_24 + 4;
    }
    if (local_20 != 0) {
      local_1c = local_1c + 4;
    }
    FUN_c0274b4c((int *)&local_28,param_5);
    FUN_c0274b4c((int *)&local_20,param_5 + 1);
  }
  return 1;
}



/* c02769d8 FUN_c02769d8 */

/* Boundary evidence: original MIPS .pdata c02769d8..c0276ab3. Semantic name remains unreviewed. */

void FUN_c02769d8(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  sVar1 = *(short *)(*(int *)(param_1 + 4) + 0x16e);
  sVar2 = *(short *)(*(int *)(param_1 + 4) + 0x170);
  *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(param_1 + 0x160);
  uVar5 = (int)sVar2 << 0x10;
  uVar6 = (int)sVar1 << 0x10;
  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x164);
  *(int *)(param_1 + 0x13c) = -*(int *)(param_1 + 0x154);
  *(int *)(param_1 + 0x140) = -*(int *)(param_1 + 0x158);
  *(undefined4 *)(param_1 + 0x150) = 0x40000000;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  iVar3 = FUN_c0274f80(*(uint *)(param_1 + 0x4c),uVar5);
  iVar4 = FUN_c0274f80(*(uint *)(param_1 + 0x40),uVar6);
  *(int *)(param_1 + 0x178) = iVar3 + iVar4;
  iVar3 = FUN_c0274f80(*(uint *)(param_1 + 0x50),uVar5);
  iVar4 = FUN_c0274f80(*(uint *)(param_1 + 0x44),uVar6);
  *(int *)(param_1 + 0x17c) = iVar3 + iVar4;
  return;
}



/* c0276ab4 FUN_c0276ab4 */

/* Boundary evidence: original MIPS .pdata c0276ab4..c0276b63. Semantic name remains unreviewed. */

bool FUN_c0276ab4(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 local_res4 [6];
  undefined1 auStack_10 [8];
  
  local_res4[0] = (undefined2)param_2;
  if ((DAT_c029a188 <= param_2) && (param_2 <= DAT_c029a1be)) {
    uVar2 = 0;
    do {
      if ((*(ushort *)((int)&DAT_c029a188 + uVar2) <= param_2) &&
         (param_2 <= *(ushort *)((int)&DAT_c029a18a + uVar2))) {
        return true;
      }
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x38);
  }
  iVar1 = EngWideCharToMultiByte(param_1,local_res4,2,auStack_10,2);
  return 1 < iVar1;
}



/* c0276b64 FUN_c0276b64 */

byte FUN_c0276b64(int *param_1,uint param_2)

{
  byte bVar1;
  
  if (param_2 < *(uint *)(*(int *)(*param_1 + 0x18) + 4)) {
    bVar1 = *(byte *)((param_2 >> 3) + *(int *)(*param_1 + 0x18) + 0xc) &
            (&DAT_c029a1c0)[param_2 & 7];
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}



/* c0276bb0 FUN_c0276bb0 */

/* Boundary evidence: original MIPS .pdata c0276bb0..c0276e57. Semantic name remains unreviewed. */

undefined4 FUN_c0276bb0(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  size_t *_Dst;
  undefined3 extraout_var;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  size_t _Size;
  undefined4 uVar8;
  uint *puVar9;
  ushort *puVar10;
  uint *puVar11;
  int *piVar12;
  int *piVar13;
  uint local_44;
  
  iVar3 = *(int *)(param_1 + 0x24);
  _Size = (*(int *)(iVar3 + 0x1e8) + 7U >> 3) + 0xc;
  _Dst = (size_t *)EngAllocMem(0,_Size,0x64667454);
  if (_Dst == (size_t *)0x0) {
    uVar8 = 0;
  }
  else {
    memset(_Dst,0,_Size);
    *_Dst = _Size;
    _Dst[1] = *(size_t *)(iVar3 + 0x1e8);
    _Dst[2] = 1;
    local_44 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      piVar12 = (int *)(param_1 + 0x20);
      do {
        if (*piVar12 == 1) {
          iVar3 = *(int *)(piVar12[1] + 0x2c);
          puVar10 = (ushort *)(iVar3 + 0x10);
          puVar4 = puVar10 + *(int *)(iVar3 + 0xc) * 4;
          iVar6 = *(int *)(piVar12[1] + 0x30);
          iVar3 = 0;
          bVar1 = iVar6 != 0;
          if (bVar1) {
            iVar3 = iVar6 + 0x10;
          }
          if (puVar10 < puVar4) {
            puVar9 = (uint *)0x0;
            piVar13 = (int *)(iVar3 + 4);
            do {
              uVar7 = (uint)*puVar10;
              iVar3 = puVar10[1] + uVar7;
              puVar11 = *(uint **)(puVar10 + 2);
              if (bVar1) {
                puVar9 = (uint *)*piVar13;
              }
              if (uVar7 < 0xffff) {
                for (; uVar7 <= (iVar3 + 0xffffU & 0xffff); uVar7 = uVar7 + 1 & 0xffff) {
                  bVar2 = FUN_c0276ab4(*(undefined4 *)(param_2 + 0xec),uVar7);
                  if ((((CONCAT31(extraout_var,bVar2) != 0) && (uVar5 = *puVar11, uVar5 < _Dst[1]))
                      && (*(byte *)((int)_Dst + (uVar5 >> 3) + 0xc) =
                               (&DAT_c029a1c0)[uVar5 & 7] |
                               *(byte *)((int)_Dst + (uVar5 >> 3) + 0xc), bVar1)) &&
                     ((uVar5 = *puVar9, *puVar11 != uVar5 && (uVar5 < _Dst[1])))) {
                    *(byte *)((int)_Dst + (uVar5 >> 3) + 0xc) =
                         (&DAT_c029a1c0)[uVar5 & 7] | *(byte *)((int)_Dst + (uVar5 >> 3) + 0xc);
                  }
                  puVar11 = puVar11 + 1;
                  puVar9 = puVar9 + 1;
                }
              }
              puVar10 = puVar10 + 4;
              piVar13 = piVar13 + 2;
            } while (puVar10 < puVar4);
          }
        }
        local_44 = local_44 + 1;
        piVar12 = piVar12 + 3;
      } while (local_44 < *(uint *)(param_1 + 0xc));
    }
    uVar8 = 1;
    *(size_t **)(param_1 + 0x18) = _Dst;
  }
  return uVar8;
}



/* c0276e58 FUN_c0276e58 */

/* Boundary evidence: original MIPS .pdata c0276e58..c0276fa3. Semantic name remains unreviewed. */

undefined4 FUN_c0276e58(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_c02619f4((undefined4 *)(param_1 + 8));
  if (param_2 == 0) {
    *(int *)(*(int *)(param_1 + 0x98) + 0x44) = param_1 + 0x154;
  }
  else {
    *(int *)(*(int *)(param_1 + 0x98) + 0x44) = param_1 + 0x130;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x38) = *(undefined4 *)(param_1 + 300);
  *(short *)(*(int *)(param_1 + 0x98) + 0x3c) = (short)*(undefined4 *)(param_1 + 0x1c);
  *(short *)(*(int *)(param_1 + 0x98) + 0x3e) = (short)*(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x40) = 0x16a0a;
  *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x4c) = *(undefined2 *)(param_1 + 0x182);
  *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x48) = 0;
  uVar2 = 1;
  if ((*(uint *)(param_1 + 0x18) & 0x2000) == 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x4e) = 0;
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x50) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x54) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x58) = 0;
  }
  else {
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x4e) = 0x14;
    *(undefined2 *)(*(int *)(param_1 + 0x98) + 0x50) = 0x14;
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x54) = *(undefined4 *)(param_1 + 0x7c);
    if ((*(uint *)(param_1 + 100) & 0x80) == 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x58) = 0;
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x58) = 1;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x60) = 0;
  iVar1 = FUN_c0274370(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c));
  if ((iVar1 != 0) &&
     (iVar1 = FUN_c0274354(*(int *)(param_1 + 0x98),*(int *)(param_1 + 0x9c)), iVar1 != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0276fa4 FUN_c0276fa4 */

void FUN_c0276fa4(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x17c);
  sVar1 = (short)((*(int *)(param_1 + 0x178) >> 0xf) + 1 >> 1);
  *(short *)(param_2 + 100) = *(short *)(param_3 + 100) + sVar1;
  *(short *)(param_2 + 0x60) = *(short *)(param_3 + 0x60) + sVar1;
  sVar1 = (short)((iVar2 >> 0xf) + 1 >> 1);
  *(short *)(param_2 + 0x5e) = *(short *)(param_3 + 0x5e) + sVar1;
  *(short *)(param_2 + 0x62) = *(short *)(param_3 + 0x62) + sVar1;
  *(int *)(param_2 + 0x50) = *(int *)(param_3 + 0x50) + *(int *)(param_1 + 0x178);
  *(int *)(param_2 + 0x54) = *(int *)(param_3 + 0x54) + *(int *)(param_1 + 0x17c);
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(param_3 + 0x4c);
  *(int *)(param_2 + 0x4c) = -*(int *)(param_3 + 0x48);
  *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_3 + 0xb0);
  *(int *)(param_2 + 0xb0) = -*(int *)(param_3 + 0xac);
  *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(param_3 + 0xb4);
  *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(param_3 + 0xb8);
  return;
}



/* c027705c FUN_c027705c */

void FUN_c027705c(short *param_1,short *param_2)

{
  *param_1 = *param_1 + *param_2;
  param_1[1] = param_2[1] + param_1[1];
  return;
}



/* c0277080 FUN_c0277080 */

void FUN_c0277080(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (param_3 != 0) {
    iVar1 = -iVar1;
  }
  *param_1 = (iVar1 >> 0xc) + *param_1;
  return;
}



/* c02770a4 FUN_c02770a4 */

/* Boundary evidence: original MIPS .pdata c02770a4..c027725b. Semantic name remains unreviewed. */

void FUN_c02770a4(int param_1,int param_2,int *param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  int *piVar7;
  int local_138;
  int local_134;
  undefined4 auStack_130 [7];
  int local_114;
  int local_110;
  undefined1 auStack_f0 [200];
  
  iVar4 = *(int *)(param_1 + 0x9c);
  FUN_c0276fa4(param_1,(int)auStack_f0,iVar4);
  FUN_c02658c4(*(undefined4 *)(param_1 + 0x128),*(uint *)(param_1 + 0xc),param_1,(int)auStack_f0,
               auStack_130,(int *)0x0,(uint *)0x0);
  local_138 = local_114 * 0x10000 - (*(int *)(iVar4 + 0x50) + 0x8000U & 0xffff0000);
  local_134 = -(*(short *)(iVar4 + 0x62) * 0x10000 + local_110 * 0x10000);
  bVar1 = param_2 == 0;
  if (bVar1) {
    pcVar5 = FUN_c0277080;
  }
  else {
    pcVar5 = FUN_c027705c;
  }
  piVar7 = (int *)((int)param_3 + param_4);
  for (; param_3 < piVar7; param_3 = (int *)(*param_3 + (int)param_3)) {
    (*pcVar5)(param_3 + 2,&local_138,0);
    (*pcVar5)(param_3 + 3,&local_134,bVar1);
    iVar4 = *param_3;
    for (piVar3 = param_3 + 4; piVar3 < (int *)(iVar4 + (int)param_3);
        piVar3 = piVar3 + (uint)*(ushort *)((int)piVar3 + 2) * 2 + 1) {
      piVar6 = piVar3 + 1;
      for (uVar2 = (uint)*(ushort *)((int)piVar3 + 2); uVar2 != 0; uVar2 = uVar2 - 1) {
        (*pcVar5)(piVar6,&local_138,0);
        (*pcVar5)(piVar6 + 1,&local_134,bVar1);
        piVar6 = piVar6 + 2;
      }
    }
  }
  return;
}



/* c027725c FUN_c027725c */

/* Boundary evidence: original MIPS .pdata c027725c..c027733f. Semantic name remains unreviewed. */

undefined4 FUN_c027725c(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined1 *puVar2;
  int iVar3;
  
  if (((*(int *)(param_1 + 0xcc) == 0) ||
      (bVar1 = FUN_c0269f50(*(uint *)(param_1 + 0xd0)), CONCAT31(extraout_var,bVar1) == 0)) ||
     (*(int *)(param_1 + 0xc4) == 0)) {
    *(undefined2 *)(param_1 + 0xe4) = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0xcc);
    *(ushort *)(param_1 + 0xe4) =
         CONCAT11(*(undefined1 *)(iVar3 + 0x22),*(undefined1 *)(iVar3 + 0x23));
  }
  if ((*(int *)(param_1 + 0xbc) == 0) ||
     (iVar3 = FUN_c026a104(param_1,(uint *)(param_1 + 0xe0)), iVar3 == 0)) {
    if ((*(int *)(param_1 + 0xb4) != 0) && (iVar3 = FUN_c026a0b4(param_1), iVar3 != 0)) {
      *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xb4);
      *(undefined1 **)(param_1 + 4) = &LAB_c0276880;
      return 1;
    }
    puVar2 = &LAB_c028c3e8;
    *(undefined4 *)(param_1 + 0xe0) = 0;
  }
  else {
    puVar2 = &LAB_c02768fc;
  }
  *(undefined1 **)(param_1 + 4) = puVar2;
  return 1;
}



/* c0277340 FUN_c0277340 */

/* Boundary evidence: original MIPS .pdata c0277340..c027739b. Semantic name remains unreviewed. */

void FUN_c0277340(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = __ull_div(param_1,param_2,param_3,0);
  *param_4 = param_1 - iVar1 * param_3;
  return;
}



/* c027739c FUN_c027739c */

undefined4 FUN_c027739c(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  
  cVar1 = *(char *)(param_1 + 0x2c);
  if ((((cVar1 == -0x80) || (cVar1 == -0x7f)) || (cVar1 == -0x78)) || (cVar1 == -0x7a)) {
    uVar2 = 1;
  }
  else {
    if (*(int *)(param_1 + 0x28) != 0) {
      pcVar3 = (char *)(*(int *)(param_1 + 0x28) + param_1);
      pcVar4 = pcVar3 + 0x10;
      for (; pcVar3 < pcVar4; pcVar3 = pcVar3 + 1) {
        cVar1 = *pcVar3;
        if (cVar1 == -0x80) {
          return 1;
        }
        if (cVar1 == -0x7f) {
          return 1;
        }
        if (cVar1 == -0x78) {
          return 1;
        }
        if (cVar1 == -0x7a) {
          return 1;
        }
        if (cVar1 == '\x01') break;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c027744c FUN_c027744c */

/* Boundary evidence: original MIPS .pdata c027744c..c0277787. Semantic name remains unreviewed. */

undefined4
FUN_c027744c(int param_1,int param_2,int param_3,uint param_4,ushort *param_5,int param_6)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  bool bVar5;
  int iVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  ushort local_28 [4];
  
  uVar11 = *(uint *)(*(int *)(param_6 + 0xa0) + 0x54);
  iVar6 = FUN_c0269f68(param_1,uVar11,local_28);
  if (((iVar6 != 0) && ((int)param_4 < 0xff)) && (-0xff < (int)param_4)) {
    uVar7 = (uint)local_28[0];
    uVar9 = 0;
    if (uVar7 != 0) {
      pbVar8 = (byte *)(param_1 + 8);
      do {
        if ((pbVar8[-2] == 1) &&
           ((pbVar8[-1] == 0 ||
            ((iVar6 = (uint)pbVar8[-1] * param_3, (int)((uint)*pbVar8 * param_2) <= iVar6 &&
             (iVar6 <= (int)((uint)pbVar8[1] * param_2))))))) break;
        uVar9 = uVar9 + 1;
        pbVar8 = pbVar8 + 4;
      } while (uVar9 < uVar7);
    }
    if (uVar9 != uVar7) {
      pbVar8 = (byte *)((uVar7 * 2 + uVar9) * 2 + param_1 + 6);
      uVar7 = (int)((uint)*pbVar8 << 0x18) >> 0x10 | (uint)pbVar8[1];
      puVar10 = (undefined1 *)(uVar7 + param_1);
      bVar5 = FUN_c0269fb0(uVar11,uVar7);
      if (CONCAT31(extraout_var,bVar5) != 0) {
        uVar9 = param_4;
        if ((int)param_4 < 0) {
          uVar9 = -param_4;
        }
        if ((0 < (int)param_4) ||
           (((uint)(byte)puVar10[2] <= (uVar9 & 0xff) && ((uVar9 & 0xff) <= (uint)(byte)puVar10[3]))
           )) {
          uVar9 = (uint)CONCAT11(*puVar10,puVar10[1]);
          bVar5 = FUN_c0269fcc(uVar11,uVar7,uVar9);
          if (CONCAT31(extraout_var_00,bVar5) != 0) {
            if ((int)param_4 < 1) {
              uVar11 = 0;
              if (uVar9 != 0) {
                puVar10 = puVar10 + 8;
                do {
                  uVar1 = puVar10[-3];
                  *(undefined1 *)((int)param_5 + 1) = puVar10[-4];
                  *(undefined1 *)param_5 = uVar1;
                  uVar1 = puVar10[-2];
                  *(undefined1 *)(param_5 + 1) = puVar10[-1];
                  *(undefined1 *)((int)param_5 + 3) = uVar1;
                  uVar1 = *puVar10;
                  *(undefined1 *)(param_5 + 2) = puVar10[1];
                  *(undefined1 *)((int)param_5 + 5) = uVar1;
                  if ((uint)*param_5 == -param_4) {
                    return 1;
                  }
                  if ((int)-param_4 < (int)(uint)*param_5) {
                    return 0;
                  }
                  uVar11 = uVar11 + 1;
                  puVar10 = puVar10 + 6;
                } while (uVar11 < uVar9);
              }
            }
            else {
              uVar11 = 0;
              if (uVar9 != 0) {
                puVar10 = puVar10 + 8;
                do {
                  uVar1 = puVar10[-4];
                  *(undefined1 *)param_5 = puVar10[-3];
                  *(undefined1 *)((int)param_5 + 1) = uVar1;
                  cVar2 = puVar10[-2];
                  uVar1 = puVar10[-1];
                  *(undefined1 *)(param_5 + 1) = uVar1;
                  *(char *)((int)param_5 + 3) = cVar2;
                  uVar3 = *puVar10;
                  uVar4 = puVar10[1];
                  *(undefined1 *)(param_5 + 2) = uVar4;
                  uVar7 = ((int)CONCAT11(cVar2,uVar1) & 0xffU | (int)cVar2 << 8) -
                          (int)CONCAT11(uVar3,uVar4);
                  *(undefined1 *)((int)param_5 + 5) = uVar3;
                  if (uVar7 == param_4) {
                    return 1;
                  }
                  if ((int)param_4 < (int)uVar7) {
                    return 0;
                  }
                  uVar11 = uVar11 + 1;
                  puVar10 = puVar10 + 6;
                } while (uVar11 < uVar9);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



/* c0277788 FUN_c0277788 */

/* Boundary evidence: original MIPS .pdata c0277788..c0277bf7. Semantic name remains unreviewed. */

void FUN_c0277788(int param_1)

{
  undefined1 *puVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  short local_58;
  int local_48;
  undefined4 local_3c;
  undefined2 local_38;
  undefined1 local_34 [12];
  
  iVar12 = *(int *)(param_1 + 4);
  iVar11 = *(int *)(param_1 + 0xa0);
  iVar10 = *(int *)(iVar12 + 0x20);
  uVar13 = *(uint *)(param_1 + 0x50);
  iVar16 = *(int *)(iVar11 + 0x50) + iVar10;
  if (*(int *)(iVar11 + 0x50) == 0) {
    iVar16 = 0;
  }
  iVar14 = *(int *)(iVar11 + 0x10) + iVar10;
  iVar10 = *(int *)(iVar11 + 0x40) + iVar10;
  if (*(int *)(iVar11 + 0x40) == 0) {
    iVar10 = 0;
  }
  uVar8 = (uint)*(short *)(iVar12 + 0x160);
  if ((((*(uint *)(param_1 + 100) & 1) != 0) && (0 < (int)uVar13)) && (iVar16 != 0)) {
    if ((*(uint *)(param_1 + 0x18) & 0x8000) == 0) {
      uVar4 = (int)*(short *)(iVar12 + 0x166) + (int)*(short *)(iVar12 + 0x164);
    }
    else {
      uVar4 = -uVar8;
    }
    uVar4 = FUN_c0274f80(uVar13,uVar4);
    iVar11 = FUN_c027744c(iVar16,*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x20),uVar4,
                          (ushort *)&local_3c,param_1);
    if (iVar11 == 0) {
      if (iVar10 == 0) {
        uVar9 = ((int)((uint)*(byte *)(iVar14 + 0x2a) << 0x18) >> 0x10 |
                (uint)*(byte *)(iVar14 + 0x2b)) -
                ((int)((uint)*(byte *)(iVar14 + 0x26) << 0x18) >> 0x10 |
                (uint)*(byte *)(iVar14 + 0x27));
      }
      else {
        uVar9 = ((int)((uint)*(byte *)(iVar10 + 0x4c) << 0x18) >> 0x10 |
                (uint)*(byte *)(iVar10 + 0x4d)) +
                ((int)((uint)*(byte *)(iVar10 + 0x4a) << 0x18) >> 0x10 |
                (uint)*(byte *)(iVar10 + 0x4b));
      }
      if ((int)uVar4 < 0) {
        *(uint *)(param_1 + 0x6c) = -uVar4;
      }
      else {
        uVar5 = FUN_c0274f80(uVar13,uVar8);
        local_58 = 0;
        local_38 = 0;
        local_3c = 0;
        puVar1 = local_34 + 3;
        uVar18 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar18) =
             *(uint *)(puVar1 + -uVar18) & -1 << (uVar18 + 1) * 8 | 0U >> (3 - uVar18) * 8;
        uVar19 = 0;
        uVar18 = -uVar5;
        bVar2 = false;
        bVar3 = false;
        local_48 = 0;
        do {
          local_34._0_4_ = local_3c;
          iVar10 = FUN_c027744c(iVar16,*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x20),uVar18,
                                (ushort *)&local_3c,param_1);
          uVar15 = (uint)(byte)local_38 | ((int)local_38._1_1_ << 0x18) >> 0x10;
          uVar17 = local_3c >> 0x10 & 0xff | ((int)local_3c._3_1_ << 0x18) >> 0x10;
          if (iVar10 == 0) {
            uVar6 = FUN_c0274d38(uVar5,uVar9,uVar8);
            if (uVar6 == uVar4) break;
          }
          else {
            uVar6 = uVar17 - uVar15;
            if (uVar6 == uVar4) {
              *(uint *)(param_1 + 0x8c) = -uVar15;
              *(uint *)(param_1 + 0x88) = -uVar17;
              *(uint *)(param_1 + 0x6c) = local_3c & 0xffff;
              *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 4;
              break;
            }
          }
          if ((int)uVar6 < (int)uVar4) {
            if (bVar2) {
              if (iVar10 != 0) {
                *(uint *)(param_1 + 0x8c) = -uVar15;
                *(uint *)(param_1 + 0x88) = -uVar17;
                *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 4;
              }
              break;
            }
            bVar3 = true;
            uVar5 = uVar5 + 1;
            uVar18 = uVar18 - 1;
          }
          else {
            uVar5 = uVar5 - 1;
            uVar18 = uVar18 + 1;
            if (bVar3) {
              if (local_48 != 0) {
                *(int *)(param_1 + 0x8c) = -(int)local_58;
                *(int *)(param_1 + 0x88) = -(int)(short)local_34._2_2_;
                *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 4;
              }
              break;
            }
            bVar2 = true;
          }
          uVar19 = uVar19 + 1;
          local_34._0_4_ = local_3c;
          local_58 = (short)uVar15;
          local_48 = iVar10;
        } while (uVar19 < 0x100);
        if (0xff < uVar19) {
          return;
        }
        *(uint *)(param_1 + 0x6c) = uVar5;
      }
    }
    else {
      *(int *)(param_1 + 0x8c) = -(int)local_38;
      *(int *)(param_1 + 0x88) = -(int)local_3c._2_2_;
      *(uint *)(param_1 + 0x6c) = local_3c & 0xffff;
      *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 4;
    }
    iVar10 = FUN_c0275080(*(int *)(param_1 + 0x6c),uVar8);
    *(int *)(param_1 + 0x50) = iVar10;
    if ((*(uint *)(param_1 + 0x40) == uVar13) ||
       (iVar10 = FUN_c0274f80(*(uint *)(param_1 + 0x40) - iVar10,
                              (int)*(short *)(*(int *)(param_1 + 4) + 0x174)), iVar10 == 0)) {
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x50);
    }
    else {
      uVar7 = FUN_c0274d38(*(uint *)(param_1 + 0x40),*(uint *)(param_1 + 0x50),uVar13);
      *(undefined4 *)(param_1 + 0x40) = uVar7;
    }
  }
  return;
}



/* c0277bf8 FUN_c0277bf8 */

/* Boundary evidence: original MIPS .pdata c0277bf8..c0277c13. Semantic name remains unreviewed. */

void FUN_c0277bf8(void)

{
  FUN_c0287990();
  return;
}



/* c0277c14 FUN_c0277c14 */

undefined4 FUN_c0277c14(ushort *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  
  if (*param_1 != 0) {
    uVar10 = 0;
    do {
      iVar2 = uVar10 * 2;
      iVar7 = (int)*(short *)(iVar2 + *(int *)(param_1 + 2));
      iVar6 = (int)*(short *)(*(int *)(param_1 + 4) + iVar2);
      piVar1 = (int *)(*(int *)(param_1 + 6) + iVar7 * 4);
      piVar9 = (int *)(*(int *)(param_1 + 8) + iVar7 * 4);
      iVar8 = iVar7;
      for (; iVar7 < iVar6; iVar7 = (iVar7 + 1) * 0x10000 >> 0x10) {
        iVar3 = *piVar1;
        piVar1 = piVar1 + 1;
        iVar4 = *piVar9;
        piVar9 = piVar9 + 1;
        if ((*piVar1 == iVar3) && (iVar3 = iVar7, *piVar9 == iVar4)) {
          for (; iVar8 < iVar3; iVar3 = (iVar3 + -1) * 0x10000 >> 0x10) {
            puVar5 = (undefined4 *)(*(int *)(param_1 + 6) + iVar3 * 4);
            *puVar5 = puVar5[-1];
            puVar5 = (undefined4 *)(*(int *)(param_1 + 8) + iVar3 * 4);
            *puVar5 = puVar5[-1];
            *(undefined1 *)(iVar3 + *(int *)(param_1 + 10)) =
                 ((undefined1 *)(iVar3 + *(int *)(param_1 + 10)))[-1];
          }
          iVar3 = (iVar8 + 1) * 0x10000;
          iVar8 = iVar3 >> 0x10;
          *(short *)(iVar2 + *(int *)(param_1 + 2)) = (short)((uint)iVar3 >> 0x10);
          *(byte *)(*(int *)(param_1 + 10) + iVar7 + 1) =
               *(byte *)(*(int *)(param_1 + 10) + iVar7 + 1) | 1;
        }
      }
      if (((iVar8 != iVar6) && (*piVar1 == *(int *)(*(int *)(param_1 + 6) + iVar8 * 4))) &&
         (*piVar9 == *(int *)(*(int *)(param_1 + 8) + iVar8 * 4))) {
        *(short *)(iVar2 + *(int *)(param_1 + 2)) = *(short *)(iVar2 + *(int *)(param_1 + 2)) + 1;
        *(byte *)(*(int *)(param_1 + 10) + iVar6) = *(byte *)(*(int *)(param_1 + 10) + iVar6) | 1;
      }
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < *param_1);
  }
  return 0;
}



/* c0277dbc FUN_c0277dbc */

/* Boundary evidence: original MIPS .pdata c0277dbc..c0277e9f. Semantic name remains unreviewed. */

int FUN_c0277dbc(int *param_1,int param_2,int param_3,short *param_4,undefined2 *param_5,
                short *param_6)

{
  int iVar1;
  
  if (*param_4 == 0) {
    if (param_2 < param_3) {
      *param_4 = 1;
      *param_5 = 1;
    }
    else if (param_3 < param_2) {
      *param_4 = -1;
      *param_5 = 0xffff;
    }
    else {
      *param_6 = *param_6 + 1;
    }
  }
  else if (*param_4 == 1) {
    if (param_3 <= param_2) {
      iVar1 = FUN_c0288648(param_1,param_2,1);
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_4 = -1;
    }
  }
  else if (param_2 <= param_3) {
    iVar1 = FUN_c0288648(param_1,param_2,-1);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_4 = 1;
  }
  return 0;
}



/* c0277ea0 FUN_c0277ea0 */

/* Boundary evidence: original MIPS .pdata c0277ea0..c02780fb. Semantic name remains unreviewed. */

int FUN_c0277ea0(int *param_1,short *param_2,undefined2 *param_3,short *param_4,int param_5,
                int param_6,int param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  do {
    while( true ) {
      uVar4 = param_7 - param_5;
      uVar5 = param_9 - param_7;
      uVar7 = param_8 - param_6;
      uVar6 = param_10 - param_8;
      if ((((int)uVar7 < 1) || (-1 < (int)uVar6)) && ((-1 < (int)uVar7 || ((int)uVar6 < 1)))) break;
      uVar6 = uVar7 - uVar6;
      if (uVar6 == 0) {
        return 0x1306;
      }
      iVar1 = FUN_c0274d38(uVar4,uVar7,uVar6);
      iVar1 = iVar1 + param_5;
      iVar2 = FUN_c0274d38(uVar5,uVar7,uVar6);
      param_7 = iVar2 + param_7;
      iVar2 = FUN_c0274d38(param_7 - iVar1,uVar7,uVar6);
      iVar3 = FUN_c0274d38(uVar7,uVar7,uVar6);
      param_8 = iVar3 + param_6;
      iVar3 = FUN_c0277ea0(param_1,param_2,param_3,param_4,param_5,param_6,iVar1,param_8,
                           iVar2 + iVar1,param_8);
      param_6 = param_8;
      param_5 = iVar2 + iVar1;
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((((int)uVar4 < 1) || (-1 < (int)uVar5)) && ((-1 < (int)uVar4 || ((int)uVar5 < 1)))) {
      iVar1 = FUN_c0277dbc(param_1,param_6,param_10,param_2,param_3,param_4);
      return iVar1;
    }
    uVar5 = uVar4 - uVar5;
    if (uVar5 == 0) {
      return 0x1306;
    }
    iVar1 = FUN_c0274d38(uVar7,uVar4,uVar5);
    iVar1 = iVar1 + param_6;
    iVar2 = FUN_c0274d38(uVar6,uVar4,uVar5);
    param_8 = iVar2 + param_8;
    iVar2 = FUN_c0274d38(param_8 - iVar1,uVar4,uVar5);
    iVar3 = FUN_c0274d38(uVar4,uVar4,uVar5);
    param_7 = iVar3 + param_5;
    iVar3 = FUN_c0277ea0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,iVar1,param_7,
                         iVar2 + iVar1);
    param_6 = iVar2 + iVar1;
    param_5 = param_7;
  } while (iVar3 == 0);
  return iVar3;
}



/* c02780fc FUN_c02780fc */

undefined4 FUN_c02780fc(ushort *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (param_2 == 1) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
    if (param_2 == 2) {
      uVar3 = 1;
    }
    else if (param_2 != 4) {
      if (param_2 == 8) {
        uVar3 = 3;
      }
      else {
        uVar3 = 0xffffffff;
      }
    }
  }
  if (*param_1 != 0) {
    uVar5 = 0;
    do {
      iVar4 = (int)*(short *)(uVar5 * 2 + *(int *)(param_1 + 2));
      iVar6 = (int)*(short *)(*(int *)(param_1 + 4) + uVar5 * 2);
      piVar2 = (int *)(*(int *)(param_1 + 6) + iVar4 * 4);
      piVar1 = (int *)(*(int *)(param_1 + 8) + iVar4 * 4);
      if ((int)uVar3 < 0) {
        for (; iVar4 <= iVar6; iVar4 = (iVar4 + 1) * 0x10000 >> 0x10) {
          *piVar2 = *piVar2 * param_2;
          piVar2 = piVar2 + 1;
          *piVar1 = param_2 * *piVar1;
          piVar1 = piVar1 + 1;
        }
      }
      else {
        for (; iVar4 <= iVar6; iVar4 = (iVar4 + 1) * 0x10000 >> 0x10) {
          *piVar2 = *piVar2 << (uVar3 & 0x1f);
          *piVar1 = *piVar1 << (uVar3 & 0x1f);
          piVar2 = piVar2 + 1;
          piVar1 = piVar1 + 1;
        }
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < *param_1);
  }
  return 0;
}



/* c0278254 FUN_c0278254 */

/* Boundary evidence: original MIPS .pdata c0278254..c027846b. Semantic name remains unreviewed. */

int FUN_c0278254(short *param_1,short *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_48;
  int local_44;
  undefined2 local_40;
  undefined2 local_3e;
  short local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  FUN_c0288610((uint)(((int)param_2[1] - (int)param_2[2]) * (int)*param_2) >> 2,
               *(void **)(param_2 + 0x14));
  local_30 = *(int *)(param_2 + 0x14);
  local_2c = *(int *)(param_2 + 0x12) + local_30;
  local_38 = *(int *)(param_1 + 0x14);
  local_34 = *(int *)(param_1 + 0x12) + local_38;
  iVar5 = ((int)param_1[1] - (int)param_1[2]) * 0x10000 >> 0x10;
  local_3e = (undefined2)param_3;
  iVar3 = (int)(((int)param_1[1] - param_3 * (int)param_2[1]) * 0x10000) >> 0x10;
  if (iVar3 < 0) {
    uVar6 = iVar3 + param_3 & 0xffff;
    iVar3 = local_38;
  }
  else {
    iVar5 = (iVar5 - iVar3) * 0x10000 >> 0x10;
    iVar3 = *param_1 * iVar3 + local_38;
    uVar6 = param_3;
  }
  iVar4 = ((int)param_2[6] * param_3 - (int)param_1[4]) * 0x10000;
  iVar3 = ((iVar4 >> 0x10) + -1 >> 3) + iVar3;
  local_3c = 7 - ((short)((uint)iVar4 >> 0x10) - 1U & 7);
  iVar4 = ((int)param_2[6] - (int)param_2[4]) * 0x10000;
  iVar2 = (param_2[1] + -1) * 0x10000 >> 0x10;
  local_40 = (undefined2)((uint)iVar4 >> 0x10);
  local_44 = (iVar4 >> 0x10) + *(int *)(param_2 + 0x14) + -1;
  iVar4 = local_44;
  if (param_2[2] <= iVar2) {
    do {
      for (; (uVar6 != 0 && (0 < iVar5)); iVar5 = (iVar5 + -1) * 0x10000 >> 0x10) {
        local_48 = iVar3;
        iVar1 = FUN_c028862c(&local_48);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar3 = *param_1 + iVar3;
        uVar6 = uVar6 + 0xffff & 0xffff;
      }
      iVar2 = (iVar2 + -1) * 0x10000 >> 0x10;
      local_44 = *param_2 + iVar4;
      uVar6 = param_3;
      iVar4 = local_44;
    } while (param_2[2] <= iVar2);
  }
  return 0;
}



/* c027846c FUN_c027846c */

/* Boundary evidence: original MIPS .pdata c027846c..c0278663. Semantic name remains unreviewed. */

undefined4 FUN_c027846c(ushort *param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  
  iVar7 = 0;
  iVar8 = 0;
  iVar9 = 0;
  iVar10 = 0;
  bVar1 = true;
  uVar3 = 0;
  if (*param_1 != 0) {
    do {
      iVar6 = (int)*(short *)(*(int *)(param_1 + 2) + uVar3 * 2);
      iVar4 = (int)*(short *)(*(int *)(param_1 + 4) + uVar3 * 2);
      if (iVar6 != iVar4) {
        piVar11 = (int *)(*(int *)(param_1 + 6) + iVar6 * 4);
        if (bVar1) {
          iVar7 = *piVar11;
          iVar9 = *(int *)(*(int *)(param_1 + 8) + iVar6 * 4);
          bVar1 = false;
          iVar8 = iVar7;
          iVar10 = iVar9;
        }
        if (iVar6 <= iVar4) {
          do {
            iVar5 = *piVar11;
            if (iVar7 < iVar5) {
              iVar7 = iVar5;
            }
            if (iVar5 < iVar8) {
              iVar8 = iVar5;
            }
            iVar5 = *(int *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 6)) + (int)piVar11);
            if (iVar9 < iVar5) {
              iVar9 = iVar5;
            }
            if (iVar5 < iVar10) {
              iVar10 = iVar5;
            }
            iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
            piVar11 = piVar11 + 1;
          } while (iVar6 <= iVar4);
        }
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < *param_1);
  }
  *(int *)(param_2 + 0x14) = iVar8;
  iVar6 = iVar8 + 0x1f >> 6;
  *(int *)(param_2 + 0x20) = iVar9;
  *(int *)(param_2 + 0x18) = iVar7;
  *(int *)(param_2 + 0x1c) = iVar10;
  iVar10 = iVar10 + 0x1f >> 6;
  iVar8 = iVar7 + 0x20 >> 6;
  iVar7 = iVar9 + 0x20 >> 6;
  if (((((short)iVar6 == iVar6) && ((short)iVar10 == iVar10)) && ((short)iVar8 == iVar8)) &&
     ((short)iVar7 == iVar7)) {
    *(undefined4 *)(param_2 + 0x10) = 0;
    if (!bVar1) {
      if (iVar6 == iVar8) {
        iVar8 = iVar8 + 1;
        *(undefined4 *)(param_2 + 0x10) = 1;
      }
      if (iVar10 == iVar7) {
        iVar7 = iVar7 + 1;
        *(undefined4 *)(param_2 + 0x10) = 1;
      }
    }
    *(short *)(param_2 + 8) = (short)iVar6;
    uVar2 = 0;
    *(short *)(param_2 + 0xc) = (short)iVar8;
    *(short *)(param_2 + 10) = (short)iVar10;
    *(short *)(param_2 + 6) = (short)iVar7;
  }
  else {
    uVar2 = 0x1201;
  }
  return uVar2;
}



/* c0278664 FUN_c0278664 */

/* Boundary evidence: original MIPS .pdata c0278664..c0278957. Semantic name remains unreviewed. */

void FUN_c0278664(int param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6,
                 ushort param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
LAB_c02786ac:
  do {
    uVar3 = param_4 - param_2;
    uVar6 = param_3 - param_1;
    iVar5 = param_5 - param_3;
    iVar2 = param_6 - param_4;
    if ((((int)uVar3 < 1) || (-1 < iVar2)) && ((-1 < (int)uVar3 || (iVar2 < 1)))) {
      if (((0 < (int)uVar6) && (iVar5 < 0)) || (((int)uVar6 < 0 && (0 < iVar5)))) {
        uVar4 = uVar6 - iVar5;
        iVar2 = FUN_c0274d38(uVar3,uVar6,uVar4);
        iVar2 = iVar2 + param_2;
        iVar5 = FUN_c0274d38(param_6 - param_4,uVar6,uVar4);
        param_4 = iVar5 + param_4;
        iVar5 = FUN_c0274d38(param_4 - iVar2,uVar6,uVar4);
        iVar1 = FUN_c0274d38(uVar6,uVar6,uVar4);
        param_3 = iVar1 + param_1;
        iVar1 = FUN_c0278664(param_1,param_2,param_3,iVar2,param_3,iVar5 + iVar2,param_7);
        param_2 = iVar5 + iVar2;
        param_1 = param_3;
        if (iVar1 != 0) {
          return;
        }
        goto LAB_c02786ac;
      }
      iVar2 = param_5 - param_1;
      iVar1 = param_6 - param_2;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if ((iVar2 < 0xc81) && (iVar1 < 0xc81)) {
        iVar2 = FUN_c028a95c(param_5,param_6,(uint)param_7);
        if (iVar2 != 0) {
          return;
        }
        if ((param_6 - param_4) * uVar6 == (param_4 - param_2) * iVar5) {
          FUN_c0289f84(param_1,param_2,param_5,param_6,param_7);
          return;
        }
        FUN_c02894b8(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        return;
      }
      iVar2 = param_1 + param_3 >> 1;
      iVar5 = param_2 + param_4 >> 1;
      param_3 = (int)(param_3 + param_5) >> 1;
      param_4 = (int)(param_4 + param_6) >> 1;
      uVar6 = param_3 + iVar2 >> 1;
      uVar3 = param_4 + iVar5 >> 1;
      iVar2 = FUN_c0278664(param_1,param_2,iVar2,iVar5,uVar6,uVar3,param_7);
    }
    else {
      uVar4 = uVar3 - iVar2;
      iVar2 = FUN_c0274d38(uVar6,uVar3,uVar4);
      iVar2 = iVar2 + param_1;
      iVar5 = FUN_c0274d38(param_5 - param_3,uVar3,uVar4);
      param_3 = iVar5 + param_3;
      iVar5 = FUN_c0274d38(param_3 - iVar2,uVar3,uVar4);
      uVar6 = iVar5 + iVar2;
      iVar5 = FUN_c0274d38(uVar3,uVar3,uVar4);
      param_4 = iVar5 + param_2;
      iVar2 = FUN_c0278664(param_1,param_2,iVar2,param_4,uVar6,param_4,param_7);
      uVar3 = param_4;
    }
    param_2 = uVar3;
    param_1 = uVar6;
    if (iVar2 != 0) {
      return;
    }
  } while( true );
}



/* c0278958 FUN_c0278958 */

/* Boundary evidence: original MIPS .pdata c0278958..c027919b. Semantic name remains unreviewed. */

int FUN_c0278958(ushort *param_1,ushort *param_2,int *param_3,uint param_4,short param_5,
                short param_6,short param_7)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  ushort uVar13;
  int iVar14;
  int iVar15;
  ushort uVar16;
  int iVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  int *piVar21;
  byte *pbVar22;
  byte *pbVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  byte local_60;
  short local_5e;
  short local_5c;
  short local_5a;
  short local_58;
  ushort local_56;
  ushort local_54;
  short local_52;
  int local_50;
  ushort *local_4c;
  int *local_48;
  int local_44;
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  local_54 = (ushort)param_4;
  local_4c = param_1;
  iVar6 = FUN_c027846c(param_1,(int)param_2);
  if (iVar6 == 0) {
    uVar13 = -param_5 & param_2[4];
    param_2[4] = uVar13;
    if ((param_2[3] != param_2[5]) && (uVar13 != param_2[6])) {
      if (param_6 < 1) {
        param_2[4] = uVar13 + param_6;
      }
      else {
        param_2[6] = param_6 + param_2[6];
      }
      if (param_7 < 1) {
        param_2[3] = param_2[3] - param_7;
      }
      else {
        param_2[5] = param_2[5] - param_7;
      }
    }
    piVar7 = FUN_c02879ac((undefined4 *)param_3[6],*param_3);
    iVar6 = 0;
    uVar10 = 0;
    local_44 = 0;
    local_56 = 0;
    local_48 = piVar7;
    if (*param_1 != 0) {
      do {
        local_58 = *(short *)(uVar10 * 2 + *(int *)(param_1 + 2));
        local_30 = (int)local_58;
        local_52 = *(short *)(*(int *)(param_1 + 4) + uVar10 * 2);
        local_3c = (int)local_52;
        if (local_30 != local_3c) {
          local_38 = local_30 * 4;
          piVar18 = (int *)(*(int *)(param_1 + 6) + local_38);
          piVar20 = (int *)(*(int *)(param_1 + 8) + local_38);
          pbVar22 = (byte *)(*(int *)(param_1 + 10) + local_30);
          local_34 = local_3c * 4;
          local_40 = (int *)(local_34 + *(int *)(param_1 + 6));
          if ((*(byte *)(*(int *)(param_1 + 10) + local_3c) & 1) == 0) {
            iVar24 = ((int *)(local_34 + *(int *)(param_1 + 8)))[-1];
            iVar25 = *(int *)(local_34 + *(int *)(param_1 + 8));
            local_50 = *(int *)(local_34 + *(int *)(param_1 + 6));
            iVar17 = ((int *)(local_34 + *(int *)(param_1 + 6)))[-1];
            if ((*(byte *)(local_3c + *(int *)(local_4c + 10) + -1) & 1) == 0) {
              iVar17 = local_50 + iVar17 + 1 >> 1;
              iVar24 = iVar25 + iVar24 + 1 >> 1;
            }
            local_60 = 0;
            piVar18 = piVar18 + -1;
            piVar20 = piVar20 + -1;
            pbVar22 = pbVar22 + -1;
          }
          else {
            iVar25 = *piVar20;
            iVar17 = *(int *)(local_34 + *(int *)(param_1 + 6));
            local_50 = *piVar18;
            local_40 = local_40 + 1;
            iVar24 = *(int *)(local_34 + *(int *)(param_1 + 8));
            local_60 = *pbVar22;
          }
          iVar8 = 0;
          local_5e = 0;
          local_5c = 0;
          local_5a = 1;
          iVar14 = iVar24;
          if (piVar18 < local_40) {
            do {
              if ((local_60 & 1) == 0) {
                pbVar23 = pbVar22 + 1;
                piVar19 = piVar18 + 1;
                piVar21 = piVar20 + 1;
                iVar6 = *piVar19;
                iVar24 = *piVar21;
                if ((*pbVar23 & 1) == 0) {
                  iVar6 = iVar6 + local_50 + 1 >> 1;
                  iVar24 = iVar24 + iVar25 + 1 >> 1;
                }
                else {
                  piVar19 = piVar18 + 2;
                  piVar21 = piVar20 + 2;
                  pbVar23 = pbVar22 + 2;
                }
                iVar17 = FUN_c0277ea0(local_48,&local_5e,&local_5a,&local_5c,iVar17,iVar14,local_50,
                                      iVar25,iVar6,iVar24);
                piVar7 = local_48;
                if (iVar17 != 0) {
                  return iVar17;
                }
              }
              else {
                iVar6 = FUN_c0277dbc(piVar7,iVar14,iVar25,&local_5e,&local_5a,&local_5c);
                if (iVar6 != 0) {
                  return iVar6;
                }
                piVar19 = piVar18 + 1;
                piVar21 = piVar20 + 1;
                pbVar23 = pbVar22 + 1;
                iVar6 = local_50;
                iVar24 = iVar25;
              }
              if (piVar19 != local_40) {
                local_50 = *piVar19;
                local_60 = *pbVar23;
                iVar25 = *piVar21;
              }
              iVar17 = iVar6;
              piVar18 = piVar19;
              piVar20 = piVar21;
              pbVar22 = pbVar23;
              iVar14 = iVar24;
            } while (piVar19 < local_40);
            iVar8 = (int)local_5e;
            iVar6 = local_44;
          }
          if (0 < local_5c) {
            do {
              if (iVar8 == 0) {
                iVar8 = 1;
                local_5e = 1;
              }
              iVar17 = FUN_c0288648(piVar7,iVar24,iVar8);
              if (iVar17 != 0) {
                return iVar17;
              }
              local_5e = -local_5e;
              iVar17 = (local_5c + -1) * 0x10000;
              iVar8 = (int)local_5e;
              local_5c = (short)((uint)iVar17 >> 0x10);
            } while (0 < iVar17 >> 0x10);
          }
          if ((local_5a != iVar8) && (iVar17 = FUN_c0288648(piVar7,iVar24,iVar8), iVar17 != 0)) {
            return iVar17;
          }
          piVar18 = local_48;
          uVar13 = local_54;
          param_1 = local_4c;
          if ((local_54 & 2) == 0) {
            iVar17 = 0;
            iVar14 = (int)local_58;
            piVar7 = (int *)(*(int *)(local_4c + 6) + local_38);
            iVar24 = 0;
            local_5e = 0;
            local_5c = 0;
            iVar25 = *(int *)(*(int *)(local_4c + 6) + local_34);
            do {
              iVar8 = iVar25;
              if (local_3c < iVar14) break;
              iVar8 = *piVar7;
              piVar7 = piVar7 + 1;
              if (iVar25 < iVar8) {
                iVar17 = 1;
LAB_c0278dbc:
                local_5e = (short)iVar17;
              }
              else {
                if (iVar8 < iVar25) {
                  iVar17 = -1;
                  goto LAB_c0278dbc;
                }
                iVar25 = (iVar24 + 1) * 0x10000;
                iVar24 = iVar25 >> 0x10;
                local_5c = (short)((uint)iVar25 >> 0x10);
              }
              iVar14 = (iVar14 + 1) * 0x10000 >> 0x10;
              iVar25 = iVar8;
            } while (iVar17 == 0);
            local_5a = (short)iVar17;
            iVar26 = iVar8;
            iVar25 = local_3c;
            if (iVar14 <= local_3c) {
              do {
                iVar8 = *piVar7;
                piVar7 = piVar7 + 1;
                if (iVar17 == 1) {
                  if (iVar8 <= iVar26) {
                    iVar17 = FUN_c028869c((int)piVar18,iVar26,1);
                    if (iVar17 != 0) {
                      return iVar17;
                    }
                    iVar17 = -1;
LAB_c0278e60:
                    local_5e = (short)iVar17;
                  }
                }
                else if (iVar26 <= iVar8) {
                  iVar17 = FUN_c028869c((int)piVar18,iVar26,-1);
                  if (iVar17 != 0) {
                    return iVar17;
                  }
                  iVar17 = 1;
                  goto LAB_c0278e60;
                }
                iVar14 = (iVar14 + 1) * 0x10000 >> 0x10;
                iVar26 = iVar8;
              } while (iVar14 <= local_3c);
              iVar24 = (int)local_5c;
              iVar25 = local_3c;
            }
            for (; iVar14 = local_3c, local_3c = iVar25, 0 < iVar24; iVar24 = iVar24 >> 0x10) {
              if (iVar17 == 0) {
                iVar17 = 1;
                local_5e = 1;
                local_5a = 1;
              }
              iVar17 = FUN_c028869c((int)piVar18,iVar8,iVar17);
              if (iVar17 != 0) {
                return iVar17;
              }
              local_5e = -local_5e;
              iVar24 = (local_5c + -1) * 0x10000;
              iVar17 = (int)local_5e;
              local_5c = (short)((uint)iVar24 >> 0x10);
              iVar25 = local_3c;
              local_3c = iVar14;
            }
            if ((local_5a != iVar17) &&
               (iVar17 = FUN_c028869c((int)piVar18,iVar8,iVar17), iVar17 != 0)) {
              return iVar17;
            }
            param_1 = local_4c;
            piVar7 = piVar18;
            if ((uVar13 & 4) != 0) {
              piVar18 = (int *)(*(int *)(local_4c + 6) + local_38);
              piVar20 = (int *)(*(int *)(local_4c + 8) + local_38);
              iVar6 = ((int)local_52 - (int)local_58) + iVar6 + 2;
              pbVar22 = (byte *)(*(int *)(local_4c + 10) + local_30);
              iVar17 = *(int *)(*(int *)(local_4c + 8) + iVar14 * 4);
              iVar24 = *(int *)(*(int *)(local_4c + 6) + iVar14 * 4);
              bVar5 = *(byte *)(*(int *)(local_4c + 10) + iVar14);
              for (iVar25 = local_30; local_44 = iVar6, iVar25 <= iVar14;
                  iVar25 = (iVar25 + 1) * 0x10000 >> 0x10) {
                bVar1 = *pbVar22;
                iVar8 = *piVar18;
                iVar26 = *piVar20;
                piVar18 = piVar18 + 1;
                piVar20 = piVar20 + 1;
                pbVar22 = pbVar22 + 1;
                if ((bVar1 & bVar5 & 1) == 0) {
                  if (((bVar1 | bVar5) & 1) == 0) {
                    iVar6 = iVar6 + 1;
                  }
                  iVar15 = iVar8 - iVar24;
                  iVar12 = iVar15;
                  if (iVar15 < 0) {
                    iVar12 = iVar24 - iVar8;
                  }
                  iVar11 = iVar26 - iVar17;
                  iVar9 = iVar11;
                  if (iVar11 < 0) {
                    iVar9 = iVar17 - iVar26;
                  }
                  if (iVar9 < iVar12) {
                    iVar11 = iVar15;
                    if (iVar15 < 0) {
                      iVar11 = iVar24 - iVar8;
                    }
                  }
                  else if (iVar11 < 0) {
                    iVar11 = iVar17 - iVar26;
                  }
                  iVar17 = 0;
                  for (; 0x640 < iVar11; iVar11 = iVar11 >> 1) {
                    iVar17 = (iVar17 + 1) * 2;
                  }
                  iVar6 = iVar17 + iVar6;
                }
                iVar17 = iVar26;
                iVar24 = iVar8;
                bVar5 = bVar1;
              }
            }
          }
        }
        local_56 = local_56 + 1;
        uVar10 = (uint)local_56;
      } while (uVar10 < *param_1);
      param_4 = (uint)local_54;
    }
    if (((param_4 & 2) == 0) && ((param_4 & 4) != 0)) {
      iVar17 = FUN_c0287a50((int)piVar7);
      iVar6 = iVar17 * 2 + iVar6;
      if (0x3fff < iVar6) {
        return 0x1305;
      }
    }
    uVar13 = param_2[4];
    uVar2 = param_2[6];
    uVar3 = param_2[3];
    uVar4 = param_2[5];
    uVar16 = (ushort)(((int)(short)uVar2 - (int)(short)uVar13) + 0x1f >> 3) & 0xfffc;
    *param_2 = uVar16;
    *(int *)(param_2 + 0x12) = (int)(short)uVar16 * ((int)(short)uVar3 - (int)(short)uVar4);
    iVar17 = FUN_c02886f0(piVar7);
    iVar24 = FUN_c0287b60(param_4,(int)(short)uVar3 - (int)(short)uVar4,iVar17);
    param_3[1] = iVar24;
    if ((param_4 & 2) == 0) {
      iVar24 = FUN_c028872c(piVar7);
      iVar25 = FUN_c0287bb4(param_4,(int)(short)uVar2 - (int)(short)uVar13,iVar24,iVar6);
      param_3[2] = iVar25;
    }
    else {
      param_3[2] = 0;
      iVar24 = 0;
    }
    param_3[3] = iVar17;
    param_3[4] = iVar24;
    param_3[5] = iVar6;
    iVar6 = FUN_c0287aa8((int)piVar7);
    *param_3 = iVar6;
    iVar6 = 0;
  }
  return iVar6;
}



/* c027919c FUN_c027919c */

/* Boundary evidence: original MIPS .pdata c027919c..c02797db. Semantic name remains unreviewed. */

int FUN_c027919c(ushort *param_1,short *param_2,int param_3,int param_4,ushort param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  uint *puVar16;
  uint *puVar17;
  short *psVar18;
  byte *pbVar19;
  byte *pbVar20;
  uint *puVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  byte local_58;
  ushort local_56;
  int local_50;
  
  psVar18 = param_2 + 3;
  iVar2 = (int)param_2[5];
  iVar3 = (int)*psVar18;
  if (iVar2 < iVar3) {
    if (*(int *)(param_2 + 8) == 0) {
      uVar15 = (uint)param_5;
    }
    else {
      uVar15 = param_5 & 0xfffe;
    }
    iVar4 = (int)param_2[2];
    local_50 = iVar4;
    if ((uVar15 & 2) == 0) {
      local_50 = iVar4 + -1;
    }
    iVar7 = (int)param_2[1];
    if (iVar3 < param_2[1]) {
      iVar7 = iVar3;
    }
    if (local_50 < iVar2) {
      local_50 = iVar2;
    }
    bVar1 = true;
    iVar9 = local_50;
    iVar12 = iVar7;
    if (param_4 == 2) {
      iVar9 = iVar2;
      iVar12 = iVar3;
    }
    uVar14 = (ushort)uVar15;
    if (param_4 != 3) {
      FUN_c028ab24(*(int *)(param_3 + 0x1c),*(int *)(param_3 + 4),*(int *)(param_3 + 0x20),
                   *(int *)(param_3 + 8));
      FUN_c028a47c();
      FUN_c0289f58();
      FUN_c028a678();
      if ((*psVar18 <= iVar12) && (iVar9 <= param_2[5])) {
        bVar1 = false;
      }
      iVar5 = iVar9 * 0x40 + 0x20;
      iVar3 = iVar12 * 0x40 + -0x20;
      iVar2 = FUN_c0288768(psVar18,uVar15,iVar12,iVar9,(uint)(param_4 == 2),(int)*param_2,
                           *(int *)(param_3 + 0xc),*(int *)(param_3 + 0x10),
                           *(uint *)(param_3 + 0x14),*(int **)(param_3 + 0x18));
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar6 = 0;
      local_56 = 0;
      if (*param_1 != 0) {
        do {
          iVar9 = (int)*(short *)(*(int *)(param_1 + 2) + uVar6 * 2);
          iVar2 = (int)*(short *)(uVar6 * 2 + *(int *)(param_1 + 4));
          if (iVar9 != iVar2) {
            puVar10 = (uint *)(*(int *)(param_1 + 6) + iVar9 * 4);
            puVar16 = (uint *)(*(int *)(param_1 + 8) + iVar9 * 4);
            pbVar19 = (byte *)(*(int *)(param_1 + 10) + iVar9);
            iVar9 = iVar2 * 4;
            puVar21 = (uint *)(iVar9 + *(int *)(param_1 + 6));
            if ((*(byte *)(*(int *)(param_1 + 10) + iVar2) & 1) == 0) {
              uVar13 = ((uint *)(*(int *)(param_1 + 8) + iVar9))[-1];
              uVar6 = *(uint *)(*(int *)(param_1 + 8) + iVar9);
              uVar24 = ((uint *)(*(int *)(param_1 + 6) + iVar9))[-1];
              uVar23 = *(uint *)(*(int *)(param_1 + 6) + iVar9);
              if ((*(byte *)(*(int *)(param_1 + 10) + iVar2 + -1) & 1) == 0) {
                uVar24 = (int)(uVar23 + uVar24 + 1) >> 1;
                uVar13 = (int)(uVar6 + uVar13 + 1) >> 1;
              }
              local_58 = 0;
              puVar10 = puVar10 + -1;
              puVar16 = puVar16 + -1;
              pbVar19 = pbVar19 + -1;
            }
            else {
              puVar21 = puVar21 + 1;
              uVar13 = *(uint *)(iVar9 + *(int *)(param_1 + 8));
              uVar24 = *(uint *)(*(int *)(param_1 + 6) + iVar9);
              uVar23 = *puVar10;
              uVar6 = *puVar16;
              local_58 = *pbVar19;
            }
            FUN_c028a4a8(uVar24,uVar13);
            iVar2 = FUN_c0287c38(uVar15,uVar24,uVar13);
            if (iVar2 != 0) {
              return iVar2;
            }
            if (bVar1) {
              while (puVar10 < puVar21) {
                if ((local_58 & 1) == 0) {
                  puVar11 = puVar10 + 1;
                  pbVar20 = pbVar19 + 1;
                  uVar8 = *puVar11;
                  puVar17 = puVar16 + 1;
                  uVar22 = *puVar17;
                  if ((*pbVar20 & 1) == 0) {
                    uVar8 = (int)(uVar8 + uVar23 + 1) >> 1;
                    uVar22 = (int)(uVar22 + uVar6 + 1) >> 1;
                  }
                  else {
                    puVar11 = puVar10 + 2;
                    puVar17 = puVar16 + 2;
                    pbVar20 = pbVar19 + 2;
                  }
                  if ((((iVar3 < (int)uVar13) && (iVar3 < (int)uVar6)) && (iVar3 < (int)uVar22)) ||
                     ((((int)uVar13 < iVar5 && ((int)uVar6 < iVar5)) && ((int)uVar22 < iVar5)))) {
                    iVar2 = FUN_c028a95c(uVar8,uVar22,uVar15);
                  }
                  else {
                    iVar2 = FUN_c0278664(uVar24,uVar13,uVar23,uVar6,uVar8,uVar22,uVar14);
                  }
                  if (iVar2 != 0) {
                    return iVar2;
                  }
                }
                else {
                  iVar2 = FUN_c028a95c(uVar23,uVar6,uVar15);
                  if (iVar2 != 0) {
                    return iVar2;
                  }
                  if ((((int)uVar13 <= iVar3) || ((int)uVar6 <= iVar3)) &&
                     (((iVar5 <= (int)uVar13 || (iVar5 <= (int)uVar6)) &&
                      (iVar2 = FUN_c0289f84(uVar24,uVar13,uVar23,uVar6,uVar14), iVar2 != 0)))) {
                    return iVar2;
                  }
                  puVar11 = puVar10 + 1;
                  puVar17 = puVar16 + 1;
                  pbVar20 = pbVar19 + 1;
                  uVar22 = uVar6;
                  uVar8 = uVar23;
                }
                puVar10 = puVar11;
                uVar13 = uVar22;
                puVar16 = puVar17;
                pbVar19 = pbVar20;
                uVar24 = uVar8;
                if (puVar11 != puVar21) {
                  local_58 = *pbVar20;
                  uVar23 = *puVar11;
                  uVar6 = *puVar17;
                }
              }
            }
            else {
              while (puVar10 < puVar21) {
                if ((local_58 & 1) == 0) {
                  puVar17 = puVar16 + 1;
                  pbVar20 = pbVar19 + 1;
                  uVar22 = *puVar17;
                  puVar11 = puVar10 + 1;
                  uVar8 = *puVar11;
                  if ((*pbVar20 & 1) == 0) {
                    uVar22 = (int)(uVar22 + uVar6 + 1) >> 1;
                    uVar8 = (int)(uVar8 + uVar23 + 1) >> 1;
                  }
                  else {
                    puVar11 = puVar10 + 2;
                    puVar17 = puVar16 + 2;
                    pbVar20 = pbVar19 + 2;
                  }
                  iVar2 = FUN_c0278664(uVar24,uVar13,uVar23,uVar6,uVar8,uVar22,uVar14);
                  if (iVar2 != 0) {
                    return iVar2;
                  }
                }
                else {
                  iVar2 = FUN_c028a95c(uVar23,uVar6,uVar15);
                  if (iVar2 != 0) {
                    return iVar2;
                  }
                  iVar2 = FUN_c0289f84(uVar24,uVar13,uVar23,uVar6,uVar14);
                  if (iVar2 != 0) {
                    return iVar2;
                  }
                  puVar11 = puVar10 + 1;
                  puVar17 = puVar16 + 1;
                  pbVar20 = pbVar19 + 1;
                  uVar22 = uVar6;
                  uVar8 = uVar23;
                }
                puVar10 = puVar11;
                uVar13 = uVar22;
                puVar16 = puVar17;
                pbVar19 = pbVar20;
                uVar24 = uVar8;
                if (puVar11 != puVar21) {
                  local_58 = *pbVar20;
                  uVar23 = *puVar11;
                  uVar6 = *puVar17;
                }
              }
            }
            iVar2 = FUN_c028aa8c(uVar15);
            if (iVar2 != 0) {
              return iVar2;
            }
          }
          local_56 = local_56 + 1;
          uVar6 = (uint)local_56;
        } while (uVar6 < *param_1);
      }
    }
    iVar2 = FUN_c02892c0(*(void **)(param_2 + 0x14),iVar7,local_50,(int)*param_2,iVar4,uVar14);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* c02797dc FUN_c02797dc */

void FUN_c02797dc(int param_1,undefined1 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]);
  if (uVar2 < 0x676c7967) {
    if (uVar2 == 0x676c7966) {
      iVar1 = 6;
    }
    else if (uVar2 < 0x4f532f33) {
      if (uVar2 == 0x4f532f32) {
        iVar1 = 0xe;
      }
      else if (uVar2 == 0x45424454) {
        iVar1 = 0x10;
      }
      else if (uVar2 == 0x45424c43) {
        iVar1 = 0x11;
      }
      else if (uVar2 == 0x45425343) {
        iVar1 = 0x12;
      }
      else {
        if (uVar2 != 0x4c545348) {
          return;
        }
        iVar1 = 0xc;
      }
    }
    else if (uVar2 == 0x636d6170) {
      iVar1 = 8;
    }
    else if (uVar2 == 0x63767420) {
      iVar1 = 4;
    }
    else if (uVar2 == 0x6670676d) {
      iVar1 = 9;
    }
    else {
      if (uVar2 != 0x67646972) {
        return;
      }
      iVar1 = 0xf;
    }
  }
  else if (uVar2 < 0x6c6f6362) {
    if (uVar2 == 0x6c6f6361) {
      iVar1 = 2;
    }
    else if (uVar2 == 0x68646d78) {
      iVar1 = 0xb;
    }
    else if (uVar2 == 0x68656164) {
      iVar1 = 0;
    }
    else if (uVar2 == 0x68686561) {
      iVar1 = 1;
    }
    else {
      if (uVar2 != 0x686d7478) {
        return;
      }
      iVar1 = 7;
    }
  }
  else if (uVar2 == 0x6d617870) {
    iVar1 = 3;
  }
  else if (uVar2 == 0x70726570) {
    iVar1 = 5;
  }
  else if (uVar2 == 0x76686561) {
    iVar1 = 0x13;
  }
  else {
    if (uVar2 != 0x766d7478) {
      return;
    }
    iVar1 = 0x14;
  }
  puVar3 = (undefined4 *)(iVar1 * 8 + param_1);
  *puVar3 = CONCAT31(CONCAT21(CONCAT11(param_2[8],param_2[9]),param_2[10]),param_2[0xb]);
  puVar3[1] = CONCAT31(CONCAT21(CONCAT11(param_2[0xc],param_2[0xd]),param_2[0xe]),param_2[0xf]);
  return;
}



/* c0279a6c FUN_c0279a6c */

/* Boundary evidence: original MIPS .pdata c0279a6c..c0279b87. Semantic name remains unreviewed. */

undefined4 FUN_c0279a6c(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  int local_20 [2];
  
  local_20[0] = 0xc;
  iVar1 = (*(code *)param_1[1])(*param_1,0,local_20);
  if (iVar1 == 0) {
    uVar2 = 0x1007;
  }
  else {
    uVar3 = (int)((uint)*(byte *)(iVar1 + 4) << 0x18) >> 0x10 | (uint)*(byte *)(iVar1 + 5);
    (*(code *)param_1[2])(iVar1);
    local_20[0] = uVar3 * 0x10 + 0xc;
    iVar1 = (*(code *)param_1[1])(*param_1,0,local_20);
    if (iVar1 == 0) {
      uVar2 = 0x1408;
    }
    else {
      memset(param_1 + 5,0,0xb0);
      puVar4 = (undefined1 *)(iVar1 + 0xc);
      if (0 < (int)uVar3) {
        do {
          FUN_c02797dc((int)(param_1 + 5),puVar4);
          uVar3 = uVar3 - 1;
          puVar4 = puVar4 + 0x10;
        } while (uVar3 != 0);
      }
      param_1[0x2f] = 0;
      param_1[0x30] = 0xffffffff;
      (*(code *)param_1[2])(iVar1);
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* c0279b88 FUN_c0279b88 */

/* Boundary evidence: original MIPS .pdata c0279b88..c0279c23. Semantic name remains unreviewed. */

undefined4
FUN_c0279b88(undefined4 *param_1,int param_2,int *param_3,int param_4,int param_5,int *param_6)

{
  int iVar1;
  
  if (param_1[(param_4 + 3) * 2] == 0) {
    *param_6 = 0;
    if (param_5 != 0) {
      return 0x1409;
    }
  }
  else {
    if (*param_3 == -1) {
      *param_3 = param_1[(param_4 + 3) * 2];
    }
    iVar1 = (*(code *)param_1[1])(*param_1,param_1[param_4 * 2 + 5] + param_2);
    *param_6 = iVar1;
    if ((iVar1 == 0) && (param_5 != 0)) {
      return 0x1408;
    }
  }
  return 0;
}



/* c0279c54 FUN_c0279c54 */

/* Boundary evidence: original MIPS .pdata c0279c54..c0279d33. Semantic name remains unreviewed. */

short FUN_c0279c54(int param_1,uint param_2)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_8;
  undefined1 uStack_7;
  
  uVar4 = param_2 >> 8 & 0xffff;
  psVar2 = (short *)(uVar4 * 2 + param_1);
  if (*psVar2 != 0) {
    uVar4 = param_2 & 0xff;
  }
  iVar3 = (uint)CONCAT11((char)*psVar2,*(undefined1 *)((int)psVar2 + 1)) + param_1;
  uVar4 = uVar4 - CONCAT11(*(undefined1 *)(iVar3 + 0x200),*(undefined1 *)(iVar3 + 0x201)) & 0xffff;
  if ((uVar4 < CONCAT11(*(undefined1 *)(iVar3 + 0x202),*(undefined1 *)(iVar3 + 0x203))) &&
     (sVar1 = *(short *)((undefined1 *)(iVar3 + 0x200) +
                        (uint)CONCAT11(*(undefined1 *)(iVar3 + 0x206),*(undefined1 *)(iVar3 + 0x207)
                                      ) + (uVar4 + 3) * 2), sVar1 != 0)) {
    local_8 = (undefined1)sVar1;
    uStack_7 = (undefined1)((ushort)sVar1 >> 8);
    sVar1 = CONCAT11(*(undefined1 *)(iVar3 + 0x204),*(undefined1 *)(iVar3 + 0x205)) +
            CONCAT11(local_8,uStack_7);
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}



/* c0279da4 FUN_c0279da4 */

void FUN_c0279da4(int param_1,undefined2 *param_2,short *param_3,short *param_4)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  
  sVar3 = 0;
  uVar2 = 1;
  if (1 < param_1) {
    do {
      uVar1 = uVar2 & 0x7fff;
      uVar2 = uVar1 << 1;
      sVar3 = sVar3 + 1;
    } while ((int)(uVar1 << 2) <= param_1);
  }
  *param_2 = (short)(uVar2 << 1);
  *param_3 = sVar3;
  *param_4 = (short)param_1 * 2 + (short)uVar2 * -2;
  return;
}



/* c0279e00 FUN_c0279e00 */

/* Boundary evidence: original MIPS .pdata c0279e00..c0279e9b. Semantic name remains unreviewed. */

int FUN_c0279e00(undefined4 *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int local_18;
  int local_14;
  
  local_18 = -1;
  iVar2 = FUN_c0279b88(param_1,0,&local_18,8,1,&local_14);
  if (iVar2 == 0) {
    uVar1 = (*(code *)param_1[0x34])(param_1[4] + local_14,param_2,param_1);
    *(undefined2 *)(param_1 + 0x35) = uVar1;
    (*(code *)param_1[2])(local_14);
    iVar2 = 0;
  }
  return iVar2;
}



/* c0279e9c FUN_c0279e9c */

/* Boundary evidence: original MIPS .pdata c0279e9c..c0279fb3. Semantic name remains unreviewed. */

undefined4
FUN_c0279e9c(undefined *param_1,undefined4 param_2,undefined4 param_3,uint param_4,ushort param_5,
            short *param_6,undefined2 *param_7)

{
  undefined2 uVar1;
  uint uVar2;
  
  if (param_6 == (short *)0x0) {
    uVar2 = (uint)param_5;
    if (0xffff < uVar2 + param_4) {
      return 0x100c;
    }
    for (; param_4 != 0; param_4 = param_4 + 0xffff & 0xffff) {
      uVar1 = (*(code *)param_1)(param_2,uVar2,param_3);
      *param_7 = uVar1;
      param_7 = param_7 + 1;
      uVar2 = uVar2 + 1 & 0xffff;
    }
  }
  else {
    for (; param_4 != 0; param_4 = param_4 + 0xffff & 0xffff) {
      if (*param_6 == -1) {
        return 0x100c;
      }
      uVar1 = (*(code *)param_1)(param_2,*param_6,param_3);
      *param_7 = uVar1;
      param_7 = param_7 + 1;
      param_6 = param_6 + 1;
    }
  }
  return 0;
}



/* c0279fb4 FUN_c0279fb4 */

/* Boundary evidence: original MIPS .pdata c0279fb4..c027a113. Semantic name remains unreviewed. */

undefined4
FUN_c0279fb4(undefined *param_1,undefined4 param_2,undefined4 param_3,uint param_4,ushort param_5,
            ushort param_6,int param_7,int *param_8,uint *param_9)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)param_5;
  if (param_8 == (int *)0x0) {
    uVar3 = (uint)param_6;
    if (0xffff < uVar3 + uVar2) {
      return 0x100c;
    }
    for (; uVar2 != 0; uVar2 = uVar2 + 0xffff & 0xffff) {
      uVar1 = (*(code *)param_1)(param_2,uVar3,param_3);
      *param_9 = uVar1;
      if (param_4 <= uVar1) {
        *param_9 = 0;
      }
      param_9 = param_9 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    }
  }
  else {
    for (; uVar2 != 0; uVar2 = uVar2 + 0xffff & 0xffff) {
      if (0xffff < (uint)(*param_8 + param_7)) {
        return 0x100c;
      }
      uVar3 = (*(code *)param_1)(param_2,*param_8 + param_7 & 0xffff,param_3);
      *param_9 = uVar3;
      if (param_4 <= uVar3) {
        *param_9 = 0;
      }
      param_9 = param_9 + 1;
      param_8 = param_8 + 1;
    }
  }
  return 0;
}



/* c027a114 FUN_c027a114 */

/* Boundary evidence: original MIPS .pdata c027a114..c027a22b. Semantic name remains unreviewed. */

int FUN_c027a114(undefined4 *param_1,uint param_2,undefined2 *param_3,undefined2 *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  int local_20 [2];
  
  uVar3 = (uint)*(ushort *)(param_1 + 0x31);
  local_20[1] = 0xffffffff;
  iVar1 = FUN_c0279b88(param_1,0,local_20 + 1,7,1,local_20);
  if (iVar1 == 0) {
    if (param_2 < uVar3) {
      puVar2 = (undefined1 *)(param_2 * 4 + local_20[0]);
      *param_3 = CONCAT11(*puVar2,puVar2[1]);
      *param_4 = CONCAT11(puVar2[2],puVar2[3]);
    }
    else {
      local_20[0] = uVar3 * 4 + local_20[0];
      *param_3 = CONCAT11(*(undefined1 *)(local_20[0] + -4),*(undefined1 *)(local_20[0] + -3));
      puVar2 = (undefined1 *)((param_2 - uVar3) * 2 + local_20[0]);
      *param_4 = CONCAT11(*puVar2,puVar2[1]);
    }
    (*(code *)param_1[2])();
    iVar1 = 0;
  }
  return iVar1;
}



/* c027a22c FUN_c027a22c */

/* Boundary evidence: original MIPS .pdata c027a22c..c027a2cf. Semantic name remains unreviewed. */

int FUN_c027a22c(undefined4 *param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  int local_18;
  int local_14;
  
  *param_3 = 0;
  local_18 = 0x24;
  iVar1 = FUN_c0279b88(param_1,0,&local_18,0x13,0,&local_14);
  if (iVar1 == 0) {
    if (local_14 != 0) {
      *param_2 = CONCAT11(*(undefined1 *)(local_14 + 0x22),*(undefined1 *)(local_14 + 0x23));
      *param_3 = 1;
      (*(code *)param_1[2])();
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c027a2d0 FUN_c027a2d0 */

/* Boundary evidence: original MIPS .pdata c027a2d0..c027a51f. Semantic name remains unreviewed. */

int FUN_c027a2d0(undefined4 *param_1,int param_2,uint *param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  int local_30;
  int local_2c;
  int local_28 [2];
  
  local_28[0] = (param_2 + 1) * 6;
  iVar1 = FUN_c0279b88(param_1,0,local_28,0xf,0,&local_30);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_30 == 0) {
    if (*(short *)(param_1 + 3) == 0) {
      local_2c = (param_2 + 2) * 2;
    }
    else {
      local_2c = (param_2 + 2) * 4;
    }
    iVar1 = FUN_c0279b88(param_1,0,&local_2c,2,1,&local_30);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(short *)(param_1 + 3) == 0) {
      puVar3 = (undefined1 *)(param_2 * 2 + local_30);
      *param_3 = (uint)CONCAT11(*puVar3,puVar3[1]) << 1;
      uVar2 = (uint)CONCAT11(puVar3[2],puVar3[3]) << 1;
    }
    else {
      puVar3 = (undefined1 *)(param_2 * 4 + local_30);
      *param_3 = CONCAT31(CONCAT21(CONCAT11(*puVar3,puVar3[1]),puVar3[2]),puVar3[3]);
      uVar2 = CONCAT31(CONCAT21(CONCAT11(puVar3[4],puVar3[5]),puVar3[6]),puVar3[7]);
    }
    if (uVar2 < *param_3) {
      return 0x1411;
    }
    *param_4 = uVar2 - *param_3;
    *param_5 = 6;
    (*(code *)param_1[2])();
  }
  else {
    puVar3 = (undefined1 *)(param_2 * 6 + local_30);
    uVar2 = CONCAT31(CONCAT21(CONCAT11(*puVar3,puVar3[1]),puVar3[2]),puVar3[3]);
    *param_3 = uVar2;
    if (uVar2 == 0) {
      *param_4 = 0;
    }
    else {
      *param_4 = (uint)CONCAT11(puVar3[4],puVar3[5]);
    }
    *param_5 = 0x15;
    (*(code *)param_1[2])();
  }
  return 0;
}



/* c027a520 FUN_c027a520 */

/* Boundary evidence: original MIPS .pdata c027a520..c027a633. Semantic name remains unreviewed. */

int FUN_c027a520(undefined4 *param_1,void *param_2,void *param_3)

{
  void *pvVar1;
  int iVar2;
  int local_20;
  void *local_1c;
  
  local_20 = -1;
  iVar2 = FUN_c0279b88(param_1,0,&local_20,9,0,(int *)&local_1c);
  pvVar1 = local_1c;
  if (iVar2 != 0) {
    return iVar2;
  }
  if (param_1[0x18] == 0) {
LAB_c027a5b4:
    local_20 = -1;
    iVar2 = FUN_c0279b88(param_1,0,&local_20,5,0,(int *)&local_1c);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1[0x10] != 0) {
      if (local_1c == (void *)0x0) goto LAB_c027a594;
      memcpy(param_3,local_1c,param_1[0x10]);
      (*(code *)param_1[2])(local_1c);
    }
    iVar2 = 0;
  }
  else {
    if (local_1c != (void *)0x0) {
      memcpy(param_2,local_1c,param_1[0x18]);
      (*(code *)param_1[2])(pvVar1);
      goto LAB_c027a5b4;
    }
LAB_c027a594:
    iVar2 = 0x1400;
  }
  return iVar2;
}



/* c027a634 FUN_c027a634 */

/* Boundary evidence: original MIPS .pdata c027a634..c027a6ff. Semantic name remains unreviewed. */

int FUN_c027a634(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  int local_18;
  byte *local_14;
  
  local_18 = -1;
  iVar1 = FUN_c0279b88(param_1,0,&local_18,4,0,(int *)&local_14);
  if (iVar1 == 0) {
    iVar1 = param_1[0xe];
    if (iVar1 != 0) {
      if (iVar1 < 0) {
        iVar1 = iVar1 + 1;
      }
      iVar1 = iVar1 >> 1;
      if (0 < iVar1) {
        do {
          iVar1 = iVar1 + -1;
          *param_2 = (int)((uint)*local_14 << 0x18) >> 0x10 | (uint)local_14[1];
          local_14 = local_14 + 2;
          param_2 = param_2 + 1;
        } while (iVar1 != 0);
      }
      (*(code *)param_1[2])();
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c027a700 FUN_c027a700 */

/* Boundary evidence: original MIPS .pdata c027a700..c027a8df. Semantic name remains unreviewed. */

int FUN_c027a700(undefined4 *param_1,int param_2,int *param_3,undefined4 *param_4,
                undefined4 *param_5,short *param_6,short *param_7)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  short sVar5;
  int iVar6;
  undefined1 *puVar7;
  uint local_28;
  int local_24;
  uint local_20 [2];
  
  *param_3 = 0;
  param_3[1] = 0;
  iVar6 = FUN_c027a2d0(param_1,param_2,local_20,&local_28,&local_24);
  if (iVar6 != 0) {
    return iVar6;
  }
  if (local_28 == 0) {
    *param_6 = 1;
    memset(param_7,0,8);
    *param_5 = 0;
    *param_4 = 0;
  }
  else {
    if (local_28 < 10) {
      return 0x140d;
    }
    iVar6 = FUN_c0279b88(param_1,local_20[0],(int *)&local_28,local_24,1,param_3);
    if (iVar6 != 0) {
      return iVar6;
    }
    puVar7 = (undefined1 *)*param_3;
    param_3[2] = (int)(puVar7 + local_28);
    sVar5 = CONCAT11(*puVar7,puVar7[1]);
    *param_6 = sVar5;
    if (sVar5 < -1) {
      return 0x1407;
    }
    if (sVar5 == -1) {
      *param_4 = 1;
      *param_6 = 0;
      *param_5 = 0;
    }
    else {
      *param_4 = 0;
      *param_5 = 1;
    }
    *param_7 = CONCAT11(puVar7[2],puVar7[3]);
    param_7[1] = CONCAT11(puVar7[4],puVar7[5]);
    uVar1 = puVar7[6];
    uVar2 = puVar7[7];
    param_7[2] = CONCAT11(uVar1,uVar2);
    uVar3 = puVar7[8];
    uVar4 = puVar7[9];
    param_7[3] = CONCAT11(uVar3,uVar4);
    if ((CONCAT11(uVar1,uVar2) < *param_7) || (CONCAT11(uVar3,uVar4) < param_7[1])) {
      return 0x1400;
    }
    param_3[1] = (int)(puVar7 + 10);
  }
  return 0;
}



/* c027a8e0 FUN_c027a8e0 */

/* Boundary evidence: original MIPS .pdata c027a8e0..c027aa0f. Semantic name remains unreviewed. */

int FUN_c027a8e0(undefined4 *param_1,int param_2,short *param_3)

{
  int iVar1;
  uint local_20;
  int local_1c;
  uint local_18 [2];
  
  iVar1 = FUN_c027a2d0(param_1,param_2,local_18,&local_20,&local_1c);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_20 == 0) {
    memset(param_3,0,8);
  }
  else {
    iVar1 = FUN_c0279b88(param_1,local_18[0],(int *)&local_20,local_1c,1,(int *)local_18);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_3 = CONCAT11(*(undefined1 *)(local_18[0] + 2),*(undefined1 *)(local_18[0] + 3));
    param_3[1] = CONCAT11(*(undefined1 *)(local_18[0] + 4),*(undefined1 *)(local_18[0] + 5));
    param_3[2] = CONCAT11(*(undefined1 *)(local_18[0] + 6),*(undefined1 *)(local_18[0] + 7));
    param_3[3] = CONCAT11(*(undefined1 *)(local_18[0] + 8),*(undefined1 *)(local_18[0] + 9));
    (*(code *)param_1[2])();
    if ((param_3[2] < *param_3) || (param_3[3] < param_3[1])) {
      return 0x1400;
    }
  }
  return 0;
}



/* c027aa10 FUN_c027aa10 */

/* Boundary evidence: original MIPS .pdata c027aa10..c027adfb. Semantic name remains unreviewed. */

undefined4
FUN_c027aa10(byte *param_1,int *param_2,int *param_3,int param_4,int param_5,int param_6,
            short param_7,undefined2 *param_8,short *param_9,ushort *param_10,undefined4 *param_11,
            uint *param_12,uint *param_13)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  
  *param_8 = 0;
  iVar5 = 1;
  *param_9 = 0;
  *param_1 = 1;
  *param_3 = 0;
  *param_2 = 0;
  *param_11 = 0;
  *param_10 = 0;
  if (param_6 == 0) {
    return 0;
  }
  iVar12 = (int)param_7;
  if ((iVar12 < 1) || (*(short *)(param_5 + 8) < iVar12)) {
LAB_c027ade4:
    uVar3 = 0x1403;
  }
  else {
    puVar10 = *(undefined1 **)(param_4 + 4);
    puVar9 = puVar10 + iVar12 * 2;
    if (puVar9 <= *(undefined1 **)(param_4 + 8)) {
      *param_10 = CONCAT11(*puVar9,puVar9[1]);
      *param_11 = puVar9 + 2;
      pbVar11 = puVar9 + 2 + *param_10;
      if (pbVar11 <= *(byte **)(param_4 + 8)) {
        uVar6 = *param_13;
        *param_13 = iVar12 + uVar6;
        uVar7 = (uint)*(ushort *)(param_5 + 8);
        if ((uint)*(ushort *)(param_5 + 8) <= (uint)*(ushort *)(param_5 + 0xc)) {
          uVar7 = (uint)*(ushort *)(param_5 + 0xc);
        }
        if (uVar7 < iVar12 + uVar6) goto LAB_c027ade4;
        *param_8 = 0;
        iVar13 = CONCAT11(*puVar10,puVar10[1]) + 1;
        *param_9 = CONCAT11(*puVar10,puVar10[1]);
        if (1 < iVar12) {
          puVar9 = puVar10;
          do {
            puVar4 = puVar9 + 2;
            *(short *)(puVar4 + ((int)param_8 - (int)puVar10)) =
                 *(short *)((int)(puVar4 + ((int)param_9 - (int)puVar10)) + -2) + 1;
            sVar2 = CONCAT11(*puVar4,puVar9[3]);
            *(short *)(puVar4 + ((int)param_9 - (int)puVar10)) = sVar2;
            if (sVar2 < iVar13) {
              return 0x1401;
            }
            if ((int)(uint)*(ushort *)(param_5 + 6) < iVar13) {
              return 0x1401;
            }
            if (iVar13 < 1) {
              return 0x1401;
            }
            iVar5 = iVar5 + 1;
            iVar13 = sVar2 + 1;
            puVar9 = puVar4;
          } while (iVar5 < iVar12);
        }
        if (iVar13 < 1) {
          return 0x1401;
        }
        uVar6 = *param_12;
        *param_12 = uVar6 + iVar13;
        uVar7 = (uint)*(ushort *)(param_5 + 6);
        if ((uint)*(ushort *)(param_5 + 6) <= (uint)*(ushort *)(param_5 + 10)) {
          uVar7 = (uint)*(ushort *)(param_5 + 10);
        }
        if (uVar7 < uVar6 + iVar13) {
          return 0x1401;
        }
        uVar7 = 0;
        pbVar8 = param_1;
        iVar5 = iVar13;
        do {
          if (uVar7 == 0) {
            bVar1 = *pbVar11;
            *pbVar8 = bVar1;
            if ((bVar1 & 8) != 0) {
              pbVar11 = pbVar11 + 1;
              uVar7 = (uint)*pbVar11;
            }
            pbVar11 = pbVar11 + 1;
            pbVar8 = pbVar8 + 1;
            iVar5 = iVar5 + -1;
          }
          else {
            iVar5 = iVar5 - uVar7;
            bVar1 = pbVar8[-1];
            if (iVar5 < 0) goto LAB_c027aaa8;
            for (; uVar7 != 0; uVar7 = uVar7 + 0xffff & 0xffff) {
              *pbVar8 = bVar1;
              pbVar8 = pbVar8 + 1;
            }
          }
        } while (0 < iVar5);
        if (uVar7 != 0) {
          return 0x1401;
        }
        if (pbVar11 <= *(byte **)(param_4 + 8)) {
          iVar12 = 0;
          pbVar8 = param_1;
          iVar5 = iVar13;
          if (0 < iVar13) {
            do {
              bVar1 = *pbVar8;
              if ((bVar1 & 2) == 0) {
                if ((bVar1 & 0x10) == 0) {
                  uVar7 = (uint)CONCAT11(*pbVar11,pbVar11[1]);
                  pbVar11 = pbVar11 + 2;
                  goto LAB_c027ad0c;
                }
              }
              else {
                if ((bVar1 & 0x10) == 0) {
                  uVar7 = -(uint)*pbVar11;
                }
                else {
                  uVar7 = (uint)*pbVar11;
                }
                pbVar11 = pbVar11 + 1;
LAB_c027ad0c:
                iVar12 = (int)((uVar7 + iVar12) * 0x10000) >> 0x10;
              }
              *param_3 = iVar12;
              param_3 = param_3 + 1;
              iVar5 = iVar5 + -1;
              pbVar8 = pbVar8 + 1;
            } while (iVar5 != 0);
          }
          if (pbVar11 <= *(byte **)(param_4 + 8)) {
            iVar5 = 0;
            if (0 < iVar13) {
              do {
                bVar1 = *param_1;
                if ((bVar1 & 4) == 0) {
                  if ((bVar1 & 0x20) == 0) {
                    uVar7 = (uint)CONCAT11(*pbVar11,pbVar11[1]);
                    pbVar11 = pbVar11 + 2;
                    goto LAB_c027ada4;
                  }
                }
                else {
                  if ((bVar1 & 0x20) == 0) {
                    uVar7 = -(uint)*pbVar11;
                  }
                  else {
                    uVar7 = (uint)*pbVar11;
                  }
                  pbVar11 = pbVar11 + 1;
LAB_c027ada4:
                  iVar5 = (int)((uVar7 + iVar5) * 0x10000) >> 0x10;
                }
                *param_2 = iVar5;
                iVar13 = iVar13 + -1;
                *param_1 = *param_1 & 1;
                param_2 = param_2 + 1;
                param_1 = param_1 + 1;
              } while (iVar13 != 0);
            }
            if (pbVar11 <= *(byte **)(param_4 + 8)) {
              *(byte **)(param_4 + 4) = pbVar11;
              return 0;
            }
          }
        }
      }
    }
LAB_c027aaa8:
    uVar3 = 0x140d;
  }
  return uVar3;
}



/* c027adfc FUN_c027adfc */

/* Boundary evidence: original MIPS .pdata c027adfc..c027b153. Semantic name remains unreviewed. */

undefined4
FUN_c027adfc(int param_1,undefined4 *param_2,uint *param_3,uint *param_4,undefined4 *param_5,
            uint *param_6,undefined2 *param_7,short *param_8,short *param_9,ushort *param_10,
            ushort *param_11,int *param_12,undefined4 *param_13,uint *param_14)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_1 + 4);
  memcpy(param_12,&DAT_c02616ac,0x24);
  *param_8 = 0;
  *param_9 = 0;
  *param_10 = 0;
  *param_11 = 0;
  *param_13 = 0;
  bVar1 = *pbVar6;
  bVar2 = pbVar6[1];
  *param_6 = (uint)((bVar1 & 1) == 1);
  *param_4 = (uint)((bVar1 & 2) == 2);
  *param_3 = (uint)((bVar2 & 4) == 4);
  if ((bVar1 & 8) == 8) {
    *param_5 = 1;
  }
  if ((bVar1 & 0x10) == 0x10) {
    *param_5 = 0;
  }
  pbVar4 = pbVar6 + 4;
  *param_7 = CONCAT11(pbVar6[2],pbVar6[3]);
  if ((bVar2 & 2) == 0) {
    *param_2 = 0;
  }
  else {
    *param_2 = 1;
  }
  if ((bVar2 & 1) == 0) {
    if ((bVar2 & 2) == 0) {
      *param_10 = (ushort)*pbVar4;
      *param_11 = (ushort)pbVar6[5];
    }
    else {
      *param_8 = (short)(char)*pbVar4;
      *param_9 = (short)(char)pbVar6[5];
    }
  }
  else {
    if ((bVar2 & 2) != 0) {
      *param_8 = CONCAT11(*pbVar4,pbVar6[5]);
      *param_9 = CONCAT11(pbVar6[6],pbVar6[7]);
      pbVar6 = pbVar6 + 8;
      goto LAB_c027aff0;
    }
    bVar1 = *pbVar4;
    pbVar4 = pbVar6 + 6;
    *param_10 = CONCAT11(bVar1,pbVar6[5]);
    *param_11 = CONCAT11(*pbVar4,pbVar6[7]);
  }
  pbVar6 = pbVar4 + 2;
LAB_c027aff0:
  pbVar4 = pbVar6;
  if ((bVar2 & 200) != 0) {
    *param_13 = 1;
    if ((bVar2 & 0x80) == 0) {
      param_12[1] = 0;
      param_12[3] = 0;
      iVar5 = ((int)((uint)*pbVar6 << 0x18) >> 0x10 | (uint)pbVar6[1]) << 2;
      pbVar4 = pbVar6 + 2;
      *param_12 = iVar5;
      if ((bVar2 & 0x40) == 0) {
        param_12[4] = iVar5;
      }
      else {
        param_12[4] = ((int)((uint)*pbVar4 << 0x18) >> 0x10 | (uint)pbVar6[3]) << 2;
        pbVar4 = pbVar6 + 4;
      }
    }
    else {
      *param_12 = ((int)((uint)*pbVar6 << 0x18) >> 0x10 | (uint)pbVar6[1]) << 2;
      param_12[1] = ((int)((uint)pbVar6[2] << 0x18) >> 0x10 | (uint)pbVar6[3]) << 2;
      param_12[3] = ((int)((uint)pbVar6[4] << 0x18) >> 0x10 | (uint)pbVar6[5]) << 2;
      param_12[4] = ((int)((uint)pbVar6[6] << 0x18) >> 0x10 | (uint)pbVar6[7]) << 2;
      pbVar4 = pbVar6 + 8;
    }
  }
  uVar3 = 0x140d;
  *param_14 = (uint)((bVar2 & 0x20) != 0x20);
  *(byte **)(param_1 + 4) = pbVar4;
  if (pbVar4 <= *(byte **)(param_1 + 8)) {
    uVar3 = 0;
  }
  return uVar3;
}



/* c027b154 FUN_c027b154 */

undefined4 FUN_c027b154(int param_1,undefined4 *param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar3 = *(undefined1 **)(param_1 + 4);
  uVar2 = 0x140d;
  puVar4 = puVar3 + 2;
  *param_3 = CONCAT11(*puVar3,puVar3[1]);
  *param_2 = puVar4;
  uVar1 = *param_3;
  *(undefined1 **)(param_1 + 4) = puVar4 + uVar1;
  if (puVar4 + uVar1 <= *(undefined1 **)(param_1 + 8)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c027b19c FUN_c027b19c */

/* Boundary evidence: original MIPS .pdata c027b19c..c027b1df. Semantic name remains unreviewed. */

undefined4 FUN_c027b19c(int param_1,undefined4 *param_2)

{
  if (param_2[1] != 0) {
    (**(code **)(param_1 + 8))(*param_2);
    param_2[1] = 0;
    *param_2 = 0;
  }
  return 0;
}



/* c027b1e0 FUN_c027b1e0 */

/* Boundary evidence: original MIPS .pdata c027b1e0..c027b3cb. Semantic name remains unreviewed. */

undefined4
FUN_c027b1e0(int param_1,uint param_2,uint param_3,uint param_4,short param_5,undefined2 *param_6,
            int *param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (7 < param_2) {
    uVar5 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5)),
                              *(undefined1 *)(param_1 + 6)),*(undefined1 *)(param_1 + 7));
    iVar7 = 8;
    if (uVar5 <= (param_2 - 8) / 0x30) {
      uVar3 = 0;
      if (param_5 == 0) {
        uVar2 = 1;
        uVar6 = 2;
      }
      else {
        uVar2 = 2;
        if ((param_5 != 2) && (uVar2 = 4, param_5 != 4)) {
          uVar2 = 8;
        }
        uVar6 = 0x114;
      }
      if (uVar5 != 0) {
        do {
          if ((((param_3 == *(byte *)(param_1 + 0x2c + iVar7)) &&
               (param_4 == *(byte *)(iVar7 + param_1 + 0x2d))) &&
              (uVar4 = (uint)*(byte *)(iVar7 + param_1 + 0x2e), (1 << (uVar4 & 0x1f) & uVar6) != 0))
             && (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar7 + param_1 + 0xc),
                                            *(undefined1 *)(iVar7 + param_1 + 0xd)),
                                   *(undefined1 *)(iVar7 + param_1 + 0xe)),
                          *(undefined1 *)(iVar7 + param_1 + 0xf)) == 0)) {
            if (uVar4 == uVar2) {
              *param_7 = iVar7;
              *param_6 = (short)uVar2;
              return 1;
            }
            if (uVar2 < uVar4) {
              uVar1 = uVar2;
              if (uVar3 <= uVar4) {
joined_r0xc027b36c:
                if (uVar1 <= uVar3) goto LAB_c027b37c;
              }
              *param_7 = iVar7;
              uVar3 = uVar4;
            }
            else {
              uVar1 = uVar4;
              if (uVar3 < uVar2) goto joined_r0xc027b36c;
            }
          }
LAB_c027b37c:
          uVar5 = uVar5 - 1;
          iVar7 = iVar7 + 0x30;
        } while (uVar5 != 0);
      }
      if (uVar3 != 0) {
        *param_6 = (short)uVar3;
        return 1;
      }
    }
  }
  return 0;
}



/* c027b3cc FUN_c027b3cc */

undefined4 FUN_c027b3cc(int param_1,uint param_2,uint param_3,uint param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  if (7 < param_2) {
    iVar2 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5)),
                              *(undefined1 *)(param_1 + 6)),*(undefined1 *)(param_1 + 7));
    iVar1 = 8;
    if ((iVar2 * 0x1c + 8U <= param_2) && (iVar2 != 0)) {
      do {
        if ((param_3 == *(byte *)(param_1 + 0x18 + iVar1)) &&
           (param_4 == *(byte *)(iVar1 + param_1 + 0x19))) {
          *param_5 = iVar1;
          return 1;
        }
        iVar2 = iVar2 + -1;
        iVar1 = iVar1 + 0x1c;
      } while (iVar2 != 0);
    }
  }
  return 0;
}



/* c027b474 FUN_c027b474 */

/* Boundary evidence: original MIPS .pdata c027b474..c027bccf. Semantic name remains unreviewed. */

int FUN_c027b474(undefined4 *param_1,uint param_2,int param_3,int *param_4,undefined2 *param_5,
                undefined2 *param_6,uint *param_7,ushort *param_8,uint *param_9,int *param_10)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint local_34;
  int local_30;
  int local_2c;
  
  local_34 = param_1[0x28];
  *param_4 = 0;
  iVar8 = FUN_c0279b88(param_1,0,(int *)&local_34,0x11,1,&local_30);
  if (iVar8 != 0) {
    return iVar8;
  }
  puVar10 = (undefined1 *)(local_30 + param_3);
  iVar8 = local_30;
  if ((param_2 < CONCAT11(puVar10[0x28],puVar10[0x29])) ||
     (CONCAT11(puVar10[0x2a],puVar10[0x2b]) < param_2)) {
LAB_c027bc90:
    local_30 = iVar8;
    (*(code *)param_1[2])();
    return 0;
  }
  iVar8 = CONCAT31(CONCAT21(CONCAT11(puVar10[8],puVar10[9]),puVar10[10]),puVar10[0xb]);
  local_2c = CONCAT31(CONCAT21(CONCAT11(*puVar10,puVar10[1]),puVar10[2]),puVar10[3]);
  iVar7 = local_2c;
  if (local_34 < (uint)(iVar8 * 8 + local_2c)) {
    local_30 = iVar8;
    (*(code *)param_1[2])();
    return 0;
  }
joined_r0xc027b5b8:
  if ((iVar8 == 0) || (*param_4 != 0)) goto LAB_c027bc90;
  iVar9 = local_30 + 1;
  uVar13 = (uint)CONCAT11(*(undefined1 *)(iVar7 + local_30),*(undefined1 *)(iVar9 + iVar7));
  if (param_2 < uVar13) goto LAB_c027bc7c;
  iVar16 = local_30 + 2;
  iVar21 = local_30 + 3;
  if (CONCAT11(*(undefined1 *)(iVar16 + iVar7),*(undefined1 *)(iVar21 + iVar7)) < param_2)
  goto LAB_c027bc7c;
  uVar18 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_30 + 4 + iVar7),
                                      *(undefined1 *)(local_30 + 5 + iVar7)),
                             *(undefined1 *)(local_30 + 6 + iVar7)),
                    *(undefined1 *)(local_30 + 7 + iVar7)) + local_2c;
  if (((local_34 < uVar18 + 8) || (local_34 < uVar18)) || (local_34 < 8)) goto LAB_c027bc90;
  uVar5 = CONCAT11(*(undefined1 *)(iVar16 + uVar18),*(undefined1 *)(iVar21 + uVar18));
  iVar15 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_30 + 4 + uVar18),
                                      *(undefined1 *)(local_30 + 5 + uVar18)),
                             *(undefined1 *)(local_30 + 6 + uVar18)),
                    *(undefined1 *)(local_30 + 7 + uVar18));
  sVar6 = CONCAT11(*(undefined1 *)(uVar18 + local_30),*(undefined1 *)(iVar9 + uVar18));
  if (sVar6 == 1) {
    iVar12 = ((param_2 - uVar13) + 2) * 4 + uVar18;
    if (local_34 < iVar12 + 8U) goto LAB_c027bc90;
    iVar20 = iVar12 + 4;
    iVar12 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar12 + local_30),
                                        *(undefined1 *)(iVar9 + iVar12)),
                               *(undefined1 *)(iVar16 + iVar12)),*(undefined1 *)(iVar21 + iVar12));
    iVar16 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar20 + local_30),
                                        *(undefined1 *)(iVar9 + iVar20)),
                               *(undefined1 *)(iVar16 + iVar20)),*(undefined1 *)(iVar21 + iVar20)) -
             iVar12;
    if (iVar16 == 0) goto LAB_c027bc90;
    uVar13 = iVar12 + iVar15;
LAB_c027bba8:
    *param_7 = uVar13;
    *param_6 = 2;
  }
  else {
    if (sVar6 != 2) {
      if (sVar6 != 3) {
        if (sVar6 == 4) {
          uVar13 = uVar18 + 0xc;
          if (uVar13 <= local_34) {
            uVar17 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar18 + local_30 + 8),
                                                *(undefined1 *)(uVar18 + local_30 + 9)),
                                       *(undefined1 *)(uVar18 + local_30 + 10)),
                              *(undefined1 *)(uVar18 + local_30 + 0xb));
            uVar18 = 0;
            uVar19 = uVar17 - 1;
            if (uVar17 <= (local_34 - uVar13 >> 2) - 1) {
              uVar17 = uVar13;
              if (CONCAT11(*(undefined1 *)(uVar13 + local_30),*(undefined1 *)(iVar9 + uVar13)) !=
                  param_2) {
                iVar12 = uVar19 * 4;
                uVar11 = uVar19;
                while( true ) {
                  uVar17 = iVar12 + uVar13;
                  uVar14 = (uint)CONCAT11(*(undefined1 *)(uVar17 + local_30),
                                          *(undefined1 *)(iVar9 + uVar17));
                  if (uVar14 == param_2) break;
                  uVar17 = uVar19;
                  if (uVar14 < param_2) {
                    uVar17 = uVar11;
                    uVar18 = uVar19;
                  }
                  if (uVar17 - uVar18 < 2) goto LAB_c027bc90;
                  uVar19 = uVar17 + uVar18 >> 1;
                  iVar12 = uVar19 << 2;
                  uVar11 = uVar17;
                }
              }
              uVar13 = (uint)CONCAT11(*(undefined1 *)(iVar16 + uVar17),
                                      *(undefined1 *)(iVar21 + uVar17));
              iVar16 = CONCAT11(*(undefined1 *)(local_30 + 6 + uVar17),
                                *(undefined1 *)(local_30 + 7 + uVar17)) - uVar13;
              uVar13 = uVar13 + iVar15;
              goto LAB_c027bba8;
            }
          }
        }
        else if ((sVar6 == 5) && (uVar13 = uVar18 + 0x18, uVar13 <= local_34)) {
          uVar1 = *(undefined1 *)(uVar18 + local_30 + 8);
          uVar2 = *(undefined1 *)(uVar18 + local_30 + 9);
          uVar3 = *(undefined1 *)(uVar18 + local_30 + 10);
          uVar4 = *(undefined1 *)(uVar18 + local_30 + 0xb);
          *param_7 = uVar18 + 0xc;
          *param_6 = 1;
          *param_5 = 3;
          iVar16 = CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4);
          uVar11 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar18 + local_30 + 0x14),
                                              *(undefined1 *)(uVar18 + local_30 + 0x15)),
                                     *(undefined1 *)(uVar18 + local_30 + 0x16)),
                            *(undefined1 *)(uVar18 + local_30 + 0x17));
          uVar17 = uVar11 - 1;
          uVar18 = 0;
          uVar19 = 0;
          if (uVar11 <= (local_34 - uVar13) - 0x18 >> 1) {
            if (CONCAT11(*(undefined1 *)(uVar13 + local_30),*(undefined1 *)(iVar9 + uVar13)) !=
                param_2) {
              iVar21 = uVar17 * 2;
              uVar19 = uVar17;
              while (uVar11 = (uint)CONCAT11(*(undefined1 *)(iVar21 + uVar13 + local_30),
                                             *(undefined1 *)(iVar9 + iVar21 + uVar13)),
                    uVar11 != param_2) {
                if (uVar11 < param_2) {
                  uVar18 = uVar19;
                  uVar19 = uVar17;
                }
                if (uVar19 - uVar18 < 2) goto LAB_c027bc90;
                uVar11 = uVar19 + uVar18 >> 1;
                iVar21 = uVar11 << 1;
                uVar17 = uVar19;
                uVar19 = uVar11;
              }
            }
            uVar13 = uVar19 * iVar16 + iVar15;
            *param_9 = uVar13;
            goto LAB_c027bbc8;
          }
        }
        goto LAB_c027bc90;
      }
      iVar16 = ((param_2 - uVar13) + 4) * 2 + uVar18;
      if (local_34 < iVar16 + 4U) goto LAB_c027bc90;
      uVar13 = (uint)CONCAT11(*(undefined1 *)(iVar16 + local_30),*(undefined1 *)(iVar9 + iVar16));
      iVar16 = CONCAT11(*(undefined1 *)(iVar16 + 2 + local_30),*(undefined1 *)(iVar9 + iVar16 + 2))
               - uVar13;
      if (iVar16 == 0) goto LAB_c027bc90;
      uVar13 = uVar13 + iVar15;
      goto LAB_c027bba8;
    }
    if (local_34 < uVar18 + 0xc) goto LAB_c027bc90;
    iVar16 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar18 + local_30 + 8),
                                        *(undefined1 *)(uVar18 + local_30 + 9)),
                               *(undefined1 *)(uVar18 + local_30 + 10)),
                      *(undefined1 *)(uVar18 + local_30 + 0xb));
    uVar13 = (param_2 - uVar13) * iVar16 + iVar15;
    *param_9 = uVar13;
    *param_7 = uVar18 + 0xc;
    *param_6 = 1;
    *param_5 = 3;
  }
LAB_c027bbc8:
  *param_10 = iVar16;
  *param_8 = uVar5;
  if (uVar5 != 0) {
    if (uVar5 < 3) {
      if (puVar10[0x2f] == '\x01') {
        *param_5 = 1;
      }
      else {
        *param_5 = 2;
      }
      uVar13 = uVar13 + 5;
LAB_c027bc74:
      *param_9 = uVar13;
    }
    else if (uVar5 != 5) {
      if (uVar5 < 6) goto LAB_c027bc7c;
      if (7 < uVar5) {
        if (uVar5 == 8) {
          if (puVar10[0x2f] == '\x01') {
            *param_5 = 1;
          }
          else {
            *param_5 = 2;
          }
          uVar13 = uVar13 + 6;
          goto LAB_c027bc74;
        }
        if (uVar5 != 9) goto LAB_c027bc7c;
      }
      *param_5 = 3;
      *param_9 = uVar13 + 8;
    }
    *param_4 = 1;
  }
LAB_c027bc7c:
  iVar8 = iVar8 + -1;
  iVar7 = iVar7 + 8;
  goto joined_r0xc027b5b8;
}



/* c027bcd0 FUN_c027bcd0 */

/* Boundary evidence: original MIPS .pdata c027bcd0..c027be5b. Semantic name remains unreviewed. */

int FUN_c027bcd0(undefined4 *param_1,int param_2,int param_3,int param_4,ushort *param_5,
                ushort *param_6,short *param_7,short *param_8,short *param_9,short *param_10,
                ushort *param_11,ushort *param_12,undefined4 *param_13,undefined4 *param_14)

{
  int iVar1;
  int local_28;
  byte *local_24;
  
  *param_13 = 0;
  iVar1 = 0x10;
  *param_14 = 0;
  if (param_3 != 2) {
    iVar1 = 0x11;
  }
  if (param_2 == 3) {
    local_28 = 8;
  }
  else {
    local_28 = 5;
  }
  iVar1 = FUN_c0279b88(param_1,param_4,&local_28,iVar1,1,(int *)&local_24);
  if (iVar1 != 0) {
    return iVar1;
  }
  *param_5 = (ushort)*local_24;
  *param_6 = (ushort)local_24[1];
  if (param_2 == 3) {
    *param_7 = (short)(char)local_24[2];
    *param_8 = (short)(char)local_24[3];
    *param_11 = (ushort)local_24[4];
    *param_9 = (short)(char)local_24[5];
    *param_10 = (short)(char)local_24[6];
    *param_12 = (ushort)local_24[7];
    *param_13 = 1;
  }
  else {
    if (param_2 == 1) {
      *param_7 = (short)(char)local_24[2];
      *param_8 = (short)(char)local_24[3];
      *param_11 = (ushort)local_24[4];
      *param_13 = 1;
      goto LAB_c027be28;
    }
    *param_9 = (short)(char)local_24[2];
    *param_10 = (short)(char)local_24[3];
    *param_12 = (ushort)local_24[4];
  }
  *param_14 = 1;
LAB_c027be28:
  (*(code *)param_1[2])();
  return 0;
}



/* c027be5c FUN_c027be5c */

/* Boundary evidence: original MIPS .pdata c027be5c..c027c2f7. Semantic name remains unreviewed. */

int FUN_c027be5c(undefined4 *param_1,int param_2,int param_3,int param_4,ushort param_5,
                short *param_6,ushort *param_7,ushort *param_8,short *param_9,short *param_10,
                short *param_11,short *param_12,short *param_13,short *param_14,short *param_15)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  short sVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  short sVar14;
  short sVar15;
  ushort uVar16;
  int local_resc;
  byte *local_6c;
  short *local_68;
  short *local_64;
  ushort *local_60;
  short *local_5c;
  short *local_58;
  short *local_54;
  short *local_50;
  short *local_4c;
  short *local_48;
  byte local_40 [16];
  uint local_30;
  
  local_30 = DAT_c029ac78;
  *param_8 = 0;
  *param_9 = 0;
  local_58 = param_6;
  local_68 = param_12;
  *param_10 = 0;
  local_60 = param_8;
  local_50 = param_9;
  local_64 = param_10;
  local_5c = param_11;
  local_54 = param_13;
  local_48 = param_14;
  local_4c = param_15;
  *param_11 = 0;
  local_resc = param_4;
  if (param_2 == 5) {
    uVar16 = *param_7;
    if (((((int)((uint)uVar16 * (uint)param_5) < 0x81) && (memset(local_40,0,0x10), param_4 != 0))
        && (uVar16 != 0)) && (*param_6 != 0)) {
      uVar11 = 1;
      iVar1 = FUN_c0279b88(param_1,param_3,&local_resc,0x10,1,(int *)&local_6c);
      if (iVar1 != 0) {
        FUN_c029919c(local_30);
        return iVar1;
      }
      sVar3 = *param_6;
      uVar4 = 0;
      uVar7 = 0;
      bVar5 = false;
      sVar10 = 0;
      sVar14 = 0;
      if (sVar3 != 0) {
        uVar16 = *param_7;
        iVar1 = local_resc;
        pbVar12 = local_6c;
        sVar15 = sVar3;
        sVar14 = 0;
        do {
          pbVar9 = local_40;
          uVar2 = 8;
          uVar13 = 0;
          for (uVar6 = (uint)uVar16 * (uint)param_5; uVar6 = uVar6 & 0xffff, uVar6 != 0;
              uVar6 = uVar6 - uVar2) {
            if (uVar7 < 8) {
              uVar4 = (uVar4 & 0xff) << 8;
              if (iVar1 != 0) {
                iVar1 = iVar1 + -1;
                uVar4 = *pbVar12 | uVar4;
                pbVar12 = pbVar12 + 1;
                local_resc = iVar1;
              }
              uVar7 = uVar7 + 8 & 0xffff;
            }
            if (uVar6 < uVar2) {
              uVar2 = uVar6;
            }
            uVar8 = uVar4 >> (uVar7 + 0xfff8 & 0x1f) & (uint)(byte)(&DAT_c02616d8)[uVar2];
            uVar13 = uVar13 | uVar8;
            *pbVar9 = *pbVar9 | (byte)uVar8;
            pbVar9 = pbVar9 + 1;
            uVar7 = uVar7 - uVar2 & 0xffff;
          }
          if (uVar13 != 0) {
            sVar14 = sVar15 + -1;
            bVar5 = true;
          }
          if (!bVar5) {
            sVar10 = sVar10 + 1;
          }
          sVar15 = sVar15 + -1;
          param_6 = local_58;
        } while (sVar15 != 0);
      }
      uVar4 = (uint)param_5;
      if (sVar10 == sVar3) {
        sVar10 = 0;
        sVar14 = 0;
      }
      (*(code *)param_1[2])(local_6c);
      pbVar12 = local_40;
      if (uVar4 == 1) {
        uVar7 = 0x80;
      }
      else if (uVar4 == 2) {
        uVar7 = 0xc0;
        uVar11 = 3;
      }
      else if (uVar4 == 4) {
        uVar7 = 0xf0;
        uVar11 = 0xf;
      }
      else {
        uVar7 = 0xff;
        uVar11 = 0xff;
      }
      uVar16 = 0;
      if ((local_40[0] & uVar7) == 0) {
        uVar16 = 0;
        uVar6 = uVar7;
        do {
          uVar16 = uVar16 + 1;
          if (uVar16 == *param_7) goto LAB_c027c2b8;
          uVar6 = uVar6 >> (uVar4 & 0x1f) & 0xff;
          if (uVar6 == 0) {
            pbVar12 = pbVar12 + 1;
            uVar6 = uVar7;
          }
        } while ((*pbVar12 & uVar6) == 0);
      }
      uVar6 = (*param_7 + 0xffff) * uVar4;
      sVar3 = 0;
      pbVar12 = local_40 + ((uVar6 & 0xffff) >> 3);
      uVar6 = uVar7 >> (uVar6 & 7);
      while ((*pbVar12 & uVar6) == 0) {
        sVar3 = sVar3 + 1;
        if (uVar6 == uVar7) {
          pbVar12 = pbVar12 + -1;
          uVar6 = uVar11;
        }
        else {
          uVar6 = uVar6 << (uVar4 & 0x1f) & 0xff;
        }
      }
      *local_60 = uVar16;
      *local_50 = sVar3;
      *param_7 = (*param_7 - sVar3) - uVar16;
      *local_68 = *local_68 + uVar16;
      *local_48 = *local_48 + uVar16;
      *local_64 = sVar10;
      *local_5c = sVar14;
      *param_6 = (*param_6 - sVar14) - sVar10;
      *local_54 = *local_54 - sVar10;
      *local_4c = *local_4c - sVar10;
    }
  }
LAB_c027c2b8:
  FUN_c029919c(local_30);
  return 0;
}



/* c027c2f8 FUN_c027c2f8 */

/* Boundary evidence: original MIPS .pdata c027c2f8..c027c783. Semantic name remains unreviewed. */

int FUN_c027c2f8(undefined4 *param_1,int param_2,int param_3,int param_4,short param_5,
                ushort param_6,ushort param_7,ushort param_8,short param_9,undefined4 param_10,
                ushort param_11,ushort param_12,ushort param_13,ushort param_14,int param_15,
                undefined2 *param_16)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  short sVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int local_resc;
  byte *local_3c;
  undefined *local_38;
  int local_34;
  undefined4 *local_30;
  
  local_resc = param_4;
  local_30 = param_1;
  iVar2 = FUN_c0279b88(param_1,param_3,&local_resc,0x10,1,(int *)&local_3c);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar7 = (uint)param_13;
  uVar11 = (uint)param_14;
  iVar2 = param_12 * uVar7 + param_15;
  uVar15 = (int)(param_11 * uVar11) >> 3 & 0xffff;
  uVar14 = param_11 * uVar11 & 7;
  *param_16 = 0;
  if (param_2 == 1) {
LAB_c027c614:
    iVar16 = param_6 * uVar11 + 7;
    if (iVar16 < 0) {
      iVar16 = param_6 * uVar11 + 0xe;
    }
    uVar11 = iVar16 >> 3 & 0xffff;
    pbVar5 = local_3c;
    if (uVar14 == 0) {
      for (; param_5 != 0; param_5 = param_5 + -1) {
        pbVar8 = (byte *)(uVar15 + iVar2);
        if (uVar11 != 0) {
          uVar14 = 0;
          do {
            uVar14 = uVar14 + 1 & 0xffff;
            *pbVar8 = *pbVar5 | *pbVar8;
            pbVar5 = pbVar5 + 1;
            pbVar8 = pbVar8 + 1;
          } while (uVar14 < uVar11);
        }
        iVar2 = uVar7 + iVar2;
      }
    }
    else {
      for (; param_5 != 0; param_5 = param_5 + -1) {
        pbVar8 = (byte *)(uVar15 + iVar2);
        uVar3 = 0;
        if (uVar11 != 0) {
          uVar10 = 0;
          do {
            bVar1 = *pbVar5;
            uVar10 = uVar10 + 1 & 0xffff;
            *pbVar8 = (byte)((bVar1 | uVar3) >> uVar14) | *pbVar8;
            pbVar5 = pbVar5 + 1;
            pbVar8 = pbVar8 + 1;
            uVar3 = (uint)bVar1 << 8;
          } while (uVar10 < uVar11);
        }
        *pbVar8 = (byte)(uVar3 >> uVar14) | *pbVar8;
        iVar2 = uVar7 + iVar2;
      }
    }
  }
  else {
    if ((param_2 != 2) && (param_2 != 5)) {
      if (param_2 == 6) goto LAB_c027c614;
      if (param_2 != 7) {
        if ((7 < param_2) && (param_2 < 10)) {
          *param_16 = CONCAT11(*local_3c,local_3c[1]);
        }
        goto LAB_c027c744;
      }
    }
    sVar6 = param_5 + param_9;
    uVar3 = 0;
    iVar16 = 0;
    if (sVar6 != 0) {
      local_38 = &DAT_c02616d0;
      local_34 = param_7 * uVar11;
      pbVar5 = local_3c;
      iVar12 = local_resc;
      do {
        pbVar8 = (byte *)(uVar15 + iVar2);
        iVar16 = iVar16 - local_34;
        uVar13 = 8;
        uVar10 = uVar14;
        uVar9 = param_6 * uVar11;
        while( true ) {
          uVar9 = uVar9 & 0xffff;
          iVar4 = iVar16 * 0x10000 >> 0x10;
          if (uVar9 == 0) break;
          for (; iVar4 < 8; iVar4 = (iVar4 + 8) * 0x10000 >> 0x10) {
            uVar3 = (uVar3 & 0xff) << 8;
            if (iVar12 != 0) {
              iVar12 = iVar12 + -1;
              uVar3 = *pbVar5 | uVar3;
              pbVar5 = pbVar5 + 1;
              local_resc = iVar12;
            }
          }
          if (uVar9 + uVar10 < uVar13) {
            uVar13 = uVar10 + uVar9 & 0xffff;
          }
          iVar16 = (uVar10 - uVar13) + iVar4;
          uVar9 = (uVar10 + uVar9) - uVar13;
          *pbVar8 = (byte)(uVar3 >> (iVar4 + uVar10 + 0xfff8 & 0x1f)) & (&DAT_c02616d8)[uVar13] &
                    (&DAT_c02616d0)[uVar10] | *pbVar8;
          pbVar8 = pbVar8 + 1;
          uVar10 = 0;
        }
        iVar16 = (int)((iVar4 - param_8 * uVar11) * 0x10000) >> 0x10;
        if (param_9 == 0) {
          iVar2 = uVar7 + iVar2;
        }
        else {
          param_9 = param_9 + -1;
        }
        sVar6 = sVar6 + -1;
        param_1 = local_30;
      } while (sVar6 != 0);
    }
  }
LAB_c027c744:
  (*(code *)param_1[2])(local_3c);
  return 0;
}



/* c027c784 FUN_c027c784 */

/* Boundary evidence: original MIPS .pdata c027c784..c027c82f. Semantic name remains unreviewed. */

int FUN_c027c784(undefined4 *param_1,int param_2,int param_3,int param_4,undefined2 *param_5,
                ushort *param_6,ushort *param_7)

{
  int iVar1;
  int local_resc;
  int local_18 [2];
  
  local_resc = param_4;
  iVar1 = FUN_c0279b88(param_1,param_3,&local_resc,0x10,1,local_18);
  if (iVar1 == 0) {
    local_18[0] = param_2 * 4 + local_18[0];
    *param_5 = CONCAT11(*(undefined1 *)(local_18[0] + 2),*(undefined1 *)(local_18[0] + 3));
    *param_6 = (ushort)*(byte *)(local_18[0] + 4);
    *param_7 = (ushort)*(byte *)(local_18[0] + 5);
    (*(code *)param_1[2])();
    iVar1 = 0;
  }
  return iVar1;
}



/* c027c830 FUN_c027c830 */

/* Boundary evidence: original MIPS .pdata c027c830..c027cc8b. Semantic name remains unreviewed. */

uint FUN_c027c830(undefined1 *param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  ushort local_20;
  short local_1e;
  ushort local_1c [2];
  
  uVar2 = (uint)CONCAT11(*param_1,param_1[1]);
  puVar6 = param_1 + 8;
  if ((0xf < uVar2) && (0xff < param_2)) {
    if (param_3 == 0) {
      FUN_c0279da4((uint)(ushort)(CONCAT11(*param_1,param_1[1]) >> 1),local_1c,&local_1e,
                   (short *)&local_20);
    }
    else {
      local_1c[0] = *(ushort *)(param_3 + 0xd6);
      local_20 = *(ushort *)(param_3 + 0xda);
      local_1e = *(short *)(param_3 + 0xd8);
    }
    uVar3 = (uint)local_1c[0];
    if (CONCAT11(puVar6[uVar3],(puVar6 + uVar3)[1]) <= param_2) {
      puVar6 = puVar6 + local_20;
    }
    switch(local_1e) {
    case 0xf:
      uVar3 = (uint)(local_1c[0] >> 1);
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 0xe:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 0xd:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 0xc:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 0xb:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 10:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 9:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 8:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 7:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 6:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 5:
      uVar3 = uVar3 >> 1;
      puVar4 = puVar6 + uVar3;
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    case 4:
      puVar4 = puVar6 + (uVar3 >> 1);
      if (CONCAT11(*puVar4,puVar4[1]) < param_2) {
        puVar6 = puVar4;
      }
    }
  }
  uVar1 = *puVar6;
  while (CONCAT11(uVar1,puVar6[1]) < param_2) {
    puVar6 = puVar6 + 2;
    uVar1 = *puVar6;
  }
  uVar1 = puVar6[uVar2 + 2];
  if (CONCAT11(uVar1,puVar6[uVar2 + 3]) <= param_2) {
    puVar5 = puVar6 + uVar2 + 2 + uVar2;
    puVar4 = puVar5 + uVar2;
    if (CONCAT11(*puVar4,puVar4[1]) == 0) {
      return CONCAT11(*puVar5,puVar5[1]) + param_2 & 0xffff;
    }
    uVar2 = (uint)CONCAT11(puVar4[(uint)CONCAT11(*puVar4,puVar4[1]) +
                                  (param_2 - CONCAT11(uVar1,puVar6[uVar2 + 3]) & 0x7fff) * 2],
                           (puVar4 + (uint)CONCAT11(*puVar4,puVar4[1]) +
                                     (param_2 - CONCAT11(uVar1,puVar6[uVar2 + 3]) & 0x7fff) * 2)[1])
    ;
    if (uVar2 != 0) {
      return CONCAT11(*puVar5,puVar5[1]) + uVar2 & 0xffff;
    }
  }
  return 0;
}



/* c027cc8c FUN_c027cc8c */

/* Boundary evidence: original MIPS .pdata c027cc8c..c027cf13. Semantic name remains unreviewed. */

int FUN_c027cc8c(undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  code *pcVar4;
  byte *pbVar5;
  int iVar6;
  undefined1 *puVar7;
  int local_28;
  int local_24;
  
  bVar1 = false;
  if (param_2 == 0xffff) {
LAB_c027cccc:
    param_1[0x34] = &LAB_c0279c24;
    return 0;
  }
  local_28 = -1;
  iVar3 = FUN_c0279b88(param_1,0,&local_28,8,0,&local_24);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (local_24 == 0) goto LAB_c027cccc;
  puVar7 = (undefined1 *)(local_24 + 4);
  if (puVar7 < (undefined1 *)
               ((uint)CONCAT11(*(undefined1 *)(local_24 + 2),*(undefined1 *)(local_24 + 3)) * 8 +
                local_24 + 4)) {
    do {
      if (bVar1) goto LAB_c027ce00;
      if ((CONCAT11(*puVar7,puVar7[1]) == param_2) && (CONCAT11(puVar7[2],puVar7[3]) == param_3)) {
        bVar1 = true;
        param_1[4] = CONCAT31(CONCAT21(CONCAT11(puVar7[4],puVar7[5]),puVar7[6]),puVar7[7]);
      }
      puVar7 = puVar7 + 8;
    } while (puVar7 < (undefined1 *)
                      ((uint)CONCAT11(*(undefined1 *)(local_24 + 2),*(undefined1 *)(local_24 + 3)) *
                       8 + local_24 + 4));
    if (!bVar1) goto LAB_c027cecc;
LAB_c027ce00:
    iVar6 = param_1[4] + 6;
    puVar7 = (undefined1 *)(param_1[4] + local_24);
    param_1[4] = iVar6;
    sVar2 = CONCAT11(*puVar7,puVar7[1]);
    *(short *)(param_1 + 0x33) = sVar2;
    iVar3 = 0;
    if (sVar2 == 0) {
      puVar7 = &LAB_c0279c2c;
LAB_c027cec4:
      param_1[0x34] = puVar7;
      goto LAB_c027cee0;
    }
    if (sVar2 == 2) {
      pcVar4 = FUN_c0279c54;
    }
    else {
      if (sVar2 == 4) {
        pbVar5 = (byte *)(iVar6 + local_24);
        param_1[0x34] = FUN_c027c830;
        FUN_c0279da4((uint)(pbVar5[1] >> 1) | (uint)*pbVar5 << 7,(undefined2 *)((int)param_1 + 0xd6)
                     ,(short *)(param_1 + 0x36),(short *)((int)param_1 + 0xda));
        goto LAB_c027cee0;
      }
      if (sVar2 == 6) {
        puVar7 = &LAB_c0279d34;
        goto LAB_c027cec4;
      }
      pcVar4 = (code *)&LAB_c0279c24;
      iVar3 = 0x140a;
    }
  }
  else {
LAB_c027cecc:
    pcVar4 = (code *)&LAB_c0279c24;
    param_1[4] = 0;
    iVar3 = 0x1406;
  }
  param_1[0x34] = pcVar4;
LAB_c027cee0:
  (*(code *)param_1[2])(local_24);
  return iVar3;
}



/* c027cf14 FUN_c027cf14 */

/* Boundary evidence: original MIPS .pdata c027cf14..c027d01b. Semantic name remains unreviewed. */

int FUN_c027cf14(undefined4 *param_1,uint param_2,ushort param_3,short *param_4,undefined2 *param_5)

{
  short sVar1;
  int iVar2;
  int local_28;
  int local_24;
  
  sVar1 = *(short *)(param_1 + 0x33);
  if ((((sVar1 == 0) || (sVar1 == 2)) || (sVar1 == 4)) || (sVar1 == 6)) {
    local_28 = -1;
    iVar2 = FUN_c0279b88(param_1,0,&local_28,8,1,&local_24);
    if (iVar2 == 0) {
      iVar2 = FUN_c0279e9c((undefined *)param_1[0x34],param_1[4] + local_24,param_1,param_2,param_3,
                           param_4,param_5);
      (*(code *)param_1[2])(local_24);
    }
  }
  else {
    iVar2 = 0x140a;
  }
  return iVar2;
}



/* c027d01c FUN_c027d01c */

/* Boundary evidence: original MIPS .pdata c027d01c..c027d133. Semantic name remains unreviewed. */

int FUN_c027d01c(undefined4 *param_1,uint param_2,ushort param_3,ushort param_4,int param_5,
                int *param_6,uint *param_7)

{
  short sVar1;
  int iVar2;
  int local_28;
  int local_24;
  
  sVar1 = *(short *)(param_1 + 0x33);
  if ((((sVar1 == 0) || (sVar1 == 2)) || (sVar1 == 4)) || (sVar1 == 6)) {
    local_28 = -1;
    iVar2 = FUN_c0279b88(param_1,0,&local_28,8,1,&local_24);
    if (iVar2 == 0) {
      iVar2 = FUN_c0279fb4((undefined *)param_1[0x34],param_1[4] + local_24,param_1,param_2,param_3,
                           param_4,param_5,param_6,param_7);
      (*(code *)param_1[2])(local_24);
    }
  }
  else {
    iVar2 = 0x140a;
  }
  return iVar2;
}



/* c027d134 FUN_c027d134 */

/* Boundary evidence: original MIPS .pdata c027d134..c027d54f. Semantic name remains unreviewed. */

int FUN_c027d134(undefined4 *param_1,ushort *param_2,uint *param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  ushort uVar5;
  int local_30;
  int local_2c;
  undefined1 *local_28 [2];
  
  local_30 = -1;
  iVar4 = FUN_c0279b88(param_1,0,&local_30,0,1,&local_2c);
  if (iVar4 == 0) {
    local_30 = -1;
    iVar4 = FUN_c0279b88(param_1,0,&local_30,1,1,(int *)local_28);
    puVar3 = local_28[0];
    if (iVar4 == 0) {
      if (CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(local_2c + 0xc),*(undefined1 *)(local_2c + 0xd)
                                    ),*(undefined1 *)(local_2c + 0xe)),
                   *(undefined1 *)(local_2c + 0xf)) == 0x5f0f3cf5) {
        uVar5 = CONCAT11(*(undefined1 *)(local_2c + 0x12),*(undefined1 *)(local_2c + 0x13));
        *param_2 = uVar5;
        if ((uVar5 < 0x10) || (0x4000 < uVar5)) {
          iVar4 = 0x140e;
        }
        else {
          *param_3 = (uint)((*(byte *)(local_2c + 0x11) & 8) == 8);
          uVar1 = local_28[0][0x22];
          uVar2 = local_28[0][0x23];
          *(short *)(param_1 + 0x31) = CONCAT11(uVar1,uVar2);
          if (CONCAT11(uVar1,uVar2) == 0) {
            iVar4 = 0x140f;
          }
          else {
            *(ushort *)(param_1 + 3) =
                 CONCAT11(*(undefined1 *)(local_2c + 0x32),*(undefined1 *)(local_2c + 0x33));
            local_30 = 0x4e;
            iVar4 = FUN_c0279b88(param_1,0,&local_30,0xe,0,(int *)local_28);
            if (iVar4 == 0) {
              if (local_28[0] == (undefined1 *)0x0) {
                *(ushort *)(param_1 + 0x37) = CONCAT11(puVar3[4],puVar3[5]);
                *(ushort *)((int)param_1 + 0xde) = CONCAT11(puVar3[6],puVar3[7]);
              }
              else {
                *(ushort *)(param_1 + 0x37) = CONCAT11(local_28[0][0x44],local_28[0][0x45]);
                *(ushort *)((int)param_1 + 0xde) = CONCAT11(local_28[0][0x46],local_28[0][0x47]);
                (*(code *)param_1[2])();
              }
              *(ushort *)(param_1 + 0x38) = CONCAT11(puVar3[6],puVar3[7]);
              (*(code *)param_1[2])(puVar3);
              (*(code *)param_1[2])(local_2c);
              local_30 = -1;
              iVar4 = FUN_c0279b88(param_1,0,&local_30,3,1,(int *)local_28);
              if (iVar4 == 0) {
                *param_4 = CONCAT31(CONCAT21(CONCAT11(*local_28[0],local_28[0][1]),local_28[0][2]),
                                    local_28[0][3]);
                *(ushort *)(param_4 + 1) = CONCAT11(local_28[0][4],local_28[0][5]);
                *(ushort *)((int)param_4 + 6) = CONCAT11(local_28[0][6],local_28[0][7]);
                *(ushort *)(param_4 + 2) = CONCAT11(local_28[0][8],local_28[0][9]);
                *(ushort *)((int)param_4 + 10) = CONCAT11(local_28[0][10],local_28[0][0xb]);
                *(ushort *)(param_4 + 3) = CONCAT11(local_28[0][0xc],local_28[0][0xd]);
                *(ushort *)((int)param_4 + 0xe) = CONCAT11(local_28[0][0xe],local_28[0][0xf]);
                *(ushort *)(param_4 + 4) = CONCAT11(local_28[0][0x10],local_28[0][0x11]);
                *(ushort *)((int)param_4 + 0x12) = CONCAT11(local_28[0][0x12],local_28[0][0x13]);
                *(ushort *)(param_4 + 5) = CONCAT11(local_28[0][0x14],local_28[0][0x15]);
                *(ushort *)((int)param_4 + 0x16) = CONCAT11(local_28[0][0x16],local_28[0][0x17]);
                *(ushort *)(param_4 + 6) = CONCAT11(local_28[0][0x18],local_28[0][0x19]);
                *(ushort *)((int)param_4 + 0x1a) = CONCAT11(local_28[0][0x1a],local_28[0][0x1b]);
                *(ushort *)(param_4 + 7) = CONCAT11(local_28[0][0x1c],local_28[0][0x1d]);
                *(ushort *)((int)param_4 + 0x1e) = CONCAT11(local_28[0][0x1e],local_28[0][0x1f]);
                (*(code *)param_1[2])();
                uVar5 = *(ushort *)((int)param_4 + 6);
                if (*(ushort *)((int)param_4 + 6) <= *(ushort *)((int)param_4 + 10)) {
                  uVar5 = *(ushort *)((int)param_4 + 10);
                }
                if (uVar5 < 0xfff7) {
                  iVar4 = FUN_c027a22c(param_1,(undefined2 *)((int)param_1 + 0xc6),param_1 + 0x32);
                }
                else {
                  iVar4 = 0x140b;
                }
              }
            }
          }
        }
      }
      else {
        iVar4 = 0x1405;
      }
    }
  }
  return iVar4;
}



/* c027d550 FUN_c027d550 */

/* Boundary evidence: original MIPS .pdata c027d550..c027d6ef. Semantic name remains unreviewed. */

int FUN_c027d550(undefined4 *param_1,uint param_2,short *param_3,short *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  int local_30 [2];
  int local_28;
  short local_22;
  
  uVar3 = (uint)*(ushort *)((int)param_1 + 0xc6);
  if (uVar3 <= param_2) {
    local_30[0] = (param_2 + uVar3 + 1) * 2;
  }
  else {
    local_30[0] = (param_2 + 1) * 4;
  }
  if ((param_1[0x32] != 0) &&
     (iVar1 = FUN_c0279b88(param_1,0,local_30,0x14,0,&local_28), iVar1 != 0)) {
    return iVar1;
  }
  if ((param_1[0x32] == 0) || (local_28 == 0)) {
    iVar1 = FUN_c027a8e0(param_1,(uint)*(ushort *)(param_1 + 0x35),(short *)&local_28);
    if (iVar1 != 0) {
      return iVar1;
    }
    *param_3 = *(short *)(param_1 + 0x37) - *(short *)((int)param_1 + 0xde);
    *param_4 = *(short *)(param_1 + 0x37) - local_22;
  }
  else {
    if (uVar3 <= param_2) {
      iVar1 = uVar3 * 4 + local_28;
      puVar2 = (undefined1 *)((param_2 - uVar3) * 2 + iVar1);
      *param_3 = CONCAT11(*(undefined1 *)(iVar1 + -4),*(undefined1 *)(iVar1 + -3));
      *param_4 = CONCAT11(*puVar2,puVar2[1]);
    }
    else {
      puVar2 = (undefined1 *)(param_2 * 4 + local_28);
      *param_3 = CONCAT11(*puVar2,puVar2[1]);
      *param_4 = CONCAT11(puVar2[2],puVar2[3]);
    }
    (*(code *)param_1[2])();
  }
  return 0;
}



/* c027d6f0 FUN_c027d6f0 */

/* Boundary evidence: original MIPS .pdata c027d6f0..c027d753. Semantic name remains unreviewed. */

void FUN_c027d6f0(undefined4 *param_1,uint param_2,undefined2 *param_3,short *param_4,
                 undefined2 *param_5,short *param_6)

{
  int iVar1;
  
  iVar1 = FUN_c027a114(param_1,param_2,param_3,param_5);
  if (iVar1 == 0) {
    FUN_c027d550(param_1,param_2,param_4,param_6);
  }
  return;
}



/* c027d754 FUN_c027d754 */

/* Boundary evidence: original MIPS .pdata c027d754..c027d923. Semantic name remains unreviewed. */

int FUN_c027d754(undefined4 *param_1,uint param_2,uint param_3,short param_4,undefined2 *param_5,
                undefined2 *param_6,ushort *param_7,ushort *param_8,int *param_9)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint local_38;
  uint local_34;
  int local_30 [2];
  
  local_38 = param_1[0x28];
  local_34 = param_1[0x2a];
  *param_6 = 1;
  *param_9 = 0;
  *param_7 = 0;
  *param_8 = 0;
  iVar3 = FUN_c0279b88(param_1,0,(int *)&local_38,0x11,0,local_30);
  iVar2 = local_30[0];
  if (iVar3 == 0) {
    if (local_30[0] != 0) {
      iVar3 = FUN_c027b1e0(local_30[0],local_38,param_2,param_3,param_4,param_5,param_9);
      if (iVar3 == 0) {
        iVar3 = FUN_c0279b88(param_1,0,(int *)&local_34,0x12,0,local_30);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (local_30[0] != 0) {
          iVar3 = FUN_c027b3cc(local_30[0],local_34,param_2,param_3,param_9);
          if (iVar3 != 0) {
            *param_7 = (ushort)*(byte *)(*param_9 + local_30[0] + 0x1a);
            bVar1 = *(byte *)(*param_9 + local_30[0] + 0x1b);
            *param_8 = (ushort)bVar1;
            iVar3 = FUN_c027b1e0(iVar2,local_38,(uint)*param_7,(uint)bVar1,param_4,param_5,param_9);
            if (iVar3 != 0) {
              *param_6 = 3;
            }
          }
          (*(code *)param_1[2])(local_30[0]);
        }
      }
      else {
        *param_6 = 2;
      }
      (*(code *)param_1[2])(iVar2);
    }
    iVar3 = 0;
  }
  return iVar3;
}



/* c027d924 FUN_c027d924 */

void FUN_c027d924(int param_1,int param_2,uint *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 + 1U & 0xfffffffe;
  param_3[6] = 0;
  *param_4 = uVar1;
  param_3[7] = uVar1;
  uVar1 = *param_4 + param_2 * 2;
  *param_4 = uVar1;
  param_3[8] = uVar1;
  uVar1 = *param_4 + param_2 * 2;
  *param_4 = uVar1;
  param_3[10] = uVar1;
  uVar1 = *param_4 + param_2 + 3 & 0xfffffffc;
  *param_4 = uVar1;
  *param_3 = uVar1;
  uVar1 = *param_4;
  iVar2 = param_1 * 4;
  *param_4 = uVar1 + iVar2;
  param_3[1] = uVar1 + iVar2;
  uVar1 = *param_4;
  *param_4 = uVar1 + iVar2;
  param_3[2] = uVar1 + iVar2;
  uVar1 = *param_4;
  *param_4 = uVar1 + iVar2;
  *param_5 = uVar1 + iVar2 + 3 & 0xfffffffc;
  param_3[3] = *param_4;
  uVar1 = *param_4;
  *param_4 = uVar1 + iVar2;
  param_3[4] = uVar1 + iVar2;
  uVar1 = *param_4;
  *param_4 = uVar1 + iVar2;
  param_3[5] = uVar1 + iVar2;
  uVar1 = *param_4;
  *param_4 = uVar1 + iVar2;
  param_3[9] = uVar1 + iVar2;
  uVar1 = *param_4 + param_1 + 3 & 0xfffffffc;
  *param_4 = uVar1;
  param_3[0xb] = uVar1;
  *param_4 = param_1 * 0xc + *param_4;
  return;
}



/* c027da38 FUN_c027da38 */

/* Boundary evidence: original MIPS .pdata c027da38..c027db93. Semantic name remains unreviewed. */

void FUN_c027da38(int *param_1,int param_2,int param_3,int *param_4,int param_5,int *param_6,
                 int *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = param_4[1];
  iVar1 = param_4[3];
  iVar4 = *param_4;
  iVar2 = param_4[2];
  iVar5 = param_4[4];
  *param_6 = param_4[5] + param_3;
  iVar3 = param_4[6];
  iVar8 = param_1[0x18];
  *param_7 = iVar3 + param_3;
  iVar7 = param_1[0x10];
  FUN_c028b8a8((int *)(iVar5 + param_3),iVar1 + param_3,iVar4 + param_3,iVar6 + param_3,
               iVar2 + param_3,param_5,param_2,(short)((uint)param_1[0xe] >> 1),iVar8,*param_6,iVar7
               ,iVar3 + param_3,*param_1);
  FUN_c028b8a8((int *)(param_4[0x19] + param_3),param_4[0x18] + param_3,param_4[0x15] + param_3,
               param_4[0x16] + param_3,param_4[0x17] + param_3,param_5,param_2,
               (short)((uint)param_1[0xe] >> 1),iVar8,*param_6,iVar7,*param_7,*param_1);
  return;
}



/* c027db94 FUN_c027db94 */

void FUN_c027db94(int param_1,int *param_2,int *param_3)

{
  *param_3 = *param_2 + param_1;
  param_3[1] = param_2[1] + param_1;
  param_3[2] = param_2[2] + param_1;
  param_3[3] = param_2[3] + param_1;
  param_3[4] = param_2[4] + param_1;
  param_3[5] = param_2[0x11] + param_1;
  return;
}



/* c027dbe0 FUN_c027dbe0 */

void FUN_c027dbe0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 4);
  piVar1 = *(int **)(param_2 + 8);
  *piVar1 = *(int *)(param_1 + 0x14) + iVar2;
  piVar1[1] = *(int *)(param_1 + 0x18) + iVar2;
  piVar1[2] = *(int *)(param_1 + 0x1c) + iVar2;
  piVar1[3] = *(int *)(param_1 + 0x20) + iVar2;
  piVar1[4] = *(int *)(param_1 + 0x24) + iVar2;
  piVar1[5] = *(int *)(param_1 + 0x28) + iVar2;
  piVar1[7] = *(int *)(param_1 + 0x30) + iVar2;
  piVar1[8] = *(int *)(param_1 + 0x34) + iVar2;
  piVar1[6] = *(int *)(param_1 + 0x2c) + iVar2;
  piVar1[9] = *(int *)(param_1 + 0x38) + iVar2;
  piVar1[0xb] = *(int *)(param_1 + 0x3c) + iVar2;
  piVar1[0xd] = *(int *)(param_1 + 0x40) + iVar2;
  return;
}



/* c027dc7c FUN_c027dc7c */

int FUN_c027dc7c(int param_1,int param_2)

{
  return *(int *)(param_2 + 0x10) + param_1;
}



/* c027dc88 FUN_c027dc88 */

int FUN_c027dc88(int param_1,int param_2)

{
  return *(int *)(param_2 + 100) + param_1;
}



/* c027dc94 FUN_c027dc94 */

void FUN_c027dc94(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x20) + param_1;
  piVar1 = (int *)(*(int *)(param_2 + 0x1c) + param_1);
  *piVar1 = *(int *)(param_2 + 0x24) + iVar2;
  piVar1[1] = *(int *)(param_2 + 0x28) + iVar2;
  piVar1[2] = *(int *)(param_2 + 0x2c) + iVar2;
  piVar1[3] = *(int *)(param_2 + 0x30) + iVar2;
  piVar1[4] = *(int *)(param_2 + 0x34) + iVar2;
  piVar1[5] = *(int *)(param_2 + 0x38) + iVar2;
  piVar1[7] = *(int *)(param_2 + 0x40) + iVar2;
  piVar1[8] = *(int *)(param_2 + 0x44) + iVar2;
  piVar1[6] = *(int *)(param_2 + 0x3c) + iVar2;
  piVar1[9] = *(int *)(param_2 + 0x48) + iVar2;
  piVar1[0xb] = *(int *)(param_2 + 0x4c) + iVar2;
  piVar1[0xd] = *(int *)(param_2 + 0x50) + iVar2;
  return;
}



/* c027dd38 FUN_c027dd38 */

void FUN_c027dd38(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x6c) + param_1;
  piVar1 = (int *)(*(int *)(param_2 + 0x68) + param_1);
  *piVar1 = *(int *)(param_2 + 0x24) + iVar2;
  piVar1[1] = *(int *)(param_2 + 0x28) + iVar2;
  piVar1[2] = *(int *)(param_2 + 0x2c) + iVar2;
  piVar1[3] = *(int *)(param_2 + 0x30) + iVar2;
  piVar1[4] = *(int *)(param_2 + 0x34) + iVar2;
  piVar1[5] = *(int *)(param_2 + 0x38) + iVar2;
  piVar1[7] = *(int *)(param_2 + 0x40) + iVar2;
  piVar1[8] = *(int *)(param_2 + 0x44) + iVar2;
  piVar1[6] = *(int *)(param_2 + 0x3c) + iVar2;
  piVar1[9] = *(int *)(param_2 + 0x48) + iVar2;
  piVar1[0xd] = *(int *)(param_2 + 0x50) + iVar2;
  return;
}



/* c027ddd0 FUN_c027ddd0 */

undefined4 FUN_c027ddd0(undefined4 *param_1)

{
  return *param_1;
}



/* c027ddd8 FUN_c027ddd8 */

void FUN_c027ddd8(int param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  iVar2 = *(int *)(param_1 + 0x44) + param_3;
  *(int *)(param_1 + 0x50) = *param_4;
  *(int *)(param_1 + 0x54) = *param_5;
  iVar4 = *param_4;
  iVar3 = *param_5;
  iVar1 = param_2 - param_3;
  if (iVar3 < iVar4) {
    if (iVar1 < iVar4) {
      if (iVar1 < iVar3) {
        return;
      }
      if (iVar3 < 1) {
        return;
      }
      *(int *)(param_1 + 0x4c) = iVar2;
LAB_c027deb0:
      *param_5 = 0;
      return;
    }
    *(int *)(param_1 + 0x48) = iVar2;
    if ((*param_5 <= iVar1 - *param_4) && (0 < *param_5)) {
      *(int *)(param_1 + 0x4c) = *param_4 + iVar2;
      *param_5 = 0;
    }
  }
  else {
    if ((iVar3 <= iVar1) && (0 < iVar3)) {
      *(int *)(param_1 + 0x4c) = iVar2;
      if ((*param_4 <= iVar1 - *param_5) && (0 < *param_4)) {
        *(int *)(param_1 + 0x48) = *param_5 + iVar2;
        *param_4 = 0;
      }
      goto LAB_c027deb0;
    }
    if (iVar1 < iVar4) {
      return;
    }
    if (iVar4 < 1) {
      return;
    }
    *(int *)(param_1 + 0x48) = iVar2;
  }
  *param_4 = 0;
  return;
}



/* c027dedc FUN_c027dedc */

void FUN_c027dedc(int param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6)

{
  if (*(int *)(param_2 + 0x48) == 0) {
    *param_5 = param_3;
  }
  else {
    *param_5 = *(int *)(param_2 + 0x48) + param_1;
  }
  if (*(int *)(param_2 + 0x4c) == 0) {
    *param_6 = param_4;
  }
  else {
    *param_6 = *(int *)(param_2 + 0x4c) + param_1;
  }
  return;
}



/* c027df2c FUN_c027df2c */

void FUN_c027df2c(int param_1,int param_2,int *param_3)

{
  *param_3 = *(int *)(param_2 + 0x44) + param_1;
  return;
}



/* c027df3c FUN_c027df3c */

/* Boundary evidence: original MIPS .pdata c027df3c..c027df93. Semantic name remains unreviewed. */

void FUN_c027df3c(int param_1,int param_2,undefined2 *param_3,undefined2 *param_4,
                 undefined2 *param_5)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c02756d8((int *)(param_2 + 4));
  *param_5 = (short)uVar1;
  FUN_c029770c(param_1,param_3,param_4);
  return;
}



/* c027df94 FUN_c027df94 */

/* Boundary evidence: original MIPS .pdata c027df94..c027e01f. Semantic name remains unreviewed. */

void FUN_c027df94(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                 int *param_7,int *param_8,undefined2 *param_9)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  *param_3 = *piVar1;
  *param_4 = piVar1[1];
  *param_5 = piVar1[7];
  *param_6 = piVar1[8];
  *param_7 = piVar1[6];
  *param_8 = piVar1[0xb];
  *param_9 = (short)piVar1[10];
  if (param_2 != 0) {
    FUN_c029799c(piVar1);
    *param_3 = piVar1[2];
  }
  return;
}



/* c027e020 FUN_c027e020 */

/* Boundary evidence: original MIPS .pdata c027e020..c027e0ab. Semantic name remains unreviewed. */

void FUN_c027e020(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined2 *param_8)

{
  int local_48;
  undefined4 local_44;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined2 local_20;
  undefined4 local_1c;
  
  FUN_c0297344(&local_48,param_1);
  *param_2 = local_48;
  *param_3 = local_44;
  *param_4 = local_2c;
  *param_5 = local_28;
  *param_6 = local_30;
  *param_7 = local_1c;
  *param_8 = local_20;
  return;
}



/* c027e0ac FUN_c027e0ac */

/* Boundary evidence: original MIPS .pdata c027e0ac..c027e0c7. Semantic name remains unreviewed. */

void FUN_c027e0ac(int param_1,int *param_2)

{
  FUN_c0297574(*(int **)(param_1 + 8),param_2);
  return;
}



/* c027e0c8 FUN_c027e0c8 */

/* Boundary evidence: original MIPS .pdata c027e0c8..c027e0e3. Semantic name remains unreviewed. */

void FUN_c027e0c8(int param_1,int *param_2)

{
  FUN_c0297640(*(int **)(param_1 + 8),param_2);
  return;
}



/* c027e0e4 FUN_c027e0e4 */

void FUN_c027e0e4(int param_1,int param_2,int *param_3)

{
  *param_3 = *(int *)(param_2 + 0xc) + param_1;
  return;
}



/* c027e0f4 FUN_c027e0f4 */

/* Boundary evidence: original MIPS .pdata c027e0f4..c027e10f. Semantic name remains unreviewed. */

void FUN_c027e0f4(int param_1)

{
  FUN_c0297734(*(int **)(param_1 + 8));
  return;
}



/* c027e110 FUN_c027e110 */

/* Boundary evidence: original MIPS .pdata c027e110..c027e14f. Semantic name remains unreviewed. */

void FUN_c027e110(short *param_1,int param_2,short param_3,uint *param_4)

{
  param_4[1] = 0;
  FUN_c02973e4(param_2,param_4,param_3,*(int *)(param_1 + 0x16),*param_1,(uint *)(param_1 + 2));
  return;
}



/* c027e150 FUN_c027e150 */

/* Boundary evidence: original MIPS .pdata c027e150..c027e18f. Semantic name remains unreviewed. */

void FUN_c027e150(short *param_1,int param_2,short param_3,uint *param_4)

{
  *param_4 = 0;
  FUN_c02974ec(param_2,param_4,param_3,*(int *)(param_1 + 0x16),*param_1,(uint *)(param_1 + 2));
  return;
}



/* c027e190 FUN_c027e190 */

/* Boundary evidence: original MIPS .pdata c027e190..c027e1cb. Semantic name remains unreviewed. */

void FUN_c027e190(int param_1,int param_2,int param_3,int *param_4,int *param_5,int *param_6,
                 int *param_7,int *param_8)

{
  FUN_c0298544(*(int **)(param_1 + 8),param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c027e1cc FUN_c027e1cc */

/* Boundary evidence: original MIPS .pdata c027e1cc..c027e207. Semantic name remains unreviewed. */

void FUN_c027e1cc(int param_1,int param_2,int param_3,int *param_4,int *param_5,int *param_6,
                 int *param_7,int *param_8)

{
  FUN_c02986ec(*(int **)(param_1 + 8),param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c027e208 FUN_c027e208 */

/* Boundary evidence: original MIPS .pdata c027e208..c027e357. Semantic name remains unreviewed. */

int FUN_c027e208(ushort *param_1,int param_2,uint param_3,short param_4,short param_5,int param_6,
                ushort param_7,ushort param_8,short param_9,int param_10,short *param_11,
                short *param_12)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint local_20 [2];
  
  puVar4 = (uint *)(param_1 + 2);
  iVar1 = FUN_c0297c8c(param_2,*(int *)(param_1 + 0x18),puVar4,*param_1,param_3,param_4,param_5,
                       param_7,param_8,param_9,param_10,param_11,param_12,param_6,(int *)local_20);
  if (iVar1 == 0) {
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    if (local_20[0] < 0x100) {
      *(uint *)(param_1 + 0x1c) = local_20[0];
    }
    else {
      param_1[0x1c] = 0xff;
      param_1[0x1d] = 0;
    }
    uVar2 = FUN_c0275564((int *)puVar4);
    *(undefined4 *)(param_1 + 0x16) = uVar2;
    iVar1 = FUN_c02755e0((int *)puVar4);
    if (iVar1 == 0) {
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x2000;
    }
    if (*(int *)(param_1 + 0x16) == 0) {
      iVar1 = FUN_c0275694((int *)puVar4);
      if (iVar1 != 0) {
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400;
      }
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x1000;
      uVar3 = FUN_c0275508((int *)puVar4);
      *(uint *)(param_1 + 0x14) = uVar3;
    }
    if ((param_7 != 0) || (uVar2 = 0, param_8 != 0)) {
      uVar2 = 1;
    }
    *(undefined4 *)(param_1 + 0x1e) = uVar2;
    iVar1 = 0;
  }
  return iVar1;
}



/* c027e358 FUN_c027e358 */

/* Boundary evidence: original MIPS .pdata c027e358..c027e373. Semantic name remains unreviewed. */

void FUN_c027e358(int param_1,undefined4 param_2,undefined2 param_3)

{
  FUN_c029597c(param_1,param_2,param_3);
  return;
}



/* c027e374 FUN_c027e374 */

/* Boundary evidence: original MIPS .pdata c027e374..c027e3d3. Semantic name remains unreviewed. */

void FUN_c027e374(undefined4 *param_1,int param_2,void *param_3,int param_4)

{
  FUN_c028ba04((int)param_1);
  FUN_c0295414(param_3,*(void **)(param_2 + 8),param_1,param_4);
  return;
}



/* c027e3d4 FUN_c027e3d4 */

/* Boundary evidence: original MIPS .pdata c027e3d4..c027e49b. Semantic name remains unreviewed. */

void FUN_c027e3d4(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4,int param_5,
                 undefined4 *param_6,int param_7)

{
  int iVar1;
  uint *local_20 [2];
  
  FUN_c028ba04((int)param_4);
  iVar1 = FUN_c028ba14((int)param_4,*(int *)(param_3 + 0x34));
  if (iVar1 == 0) {
    FUN_c02965b4((int)param_4,local_20);
    iVar1 = FUN_c027a634(param_1,local_20[0]);
    if (iVar1 == 0) {
      FUN_c0296578((int)param_4,(int *)local_20[0]);
      FUN_c0297058((int)param_6,*(short *)(param_2 + 0x10),1);
      FUN_c0297074(param_6,(uint)*(ushort *)(param_2 + 0x10),1);
      FUN_c02954d4(param_6,*(void **)(param_5 + 8),param_4,param_7);
    }
  }
  return;
}



/* c027e49c FUN_c027e49c */

/* Boundary evidence: original MIPS .pdata c027e49c..c027e6d3. Semantic name remains unreviewed. */

int FUN_c027e49c(undefined4 *param_1,void *param_2,int *param_3,int param_4,int param_5,
                short param_6,ushort param_7,ushort param_8,short param_9,short param_10,
                int param_11,int param_12,int param_13,undefined4 param_14,int param_15,int param_16
                )

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  short *in_stack_00000050;
  ushort in_stack_00000054;
  int in_stack_00000058;
  undefined2 *in_stack_0000005c;
  undefined2 *in_stack_00000060;
  uint *in_stack_00000064;
  
  FUN_c028b9b8((int)param_1,0);
  FUN_c028b9a4((int)param_1,in_stack_0000005c,in_stack_00000060);
  *in_stack_00000064 = 0;
  FUN_c02965c0((int)param_3,in_stack_00000050,(int)param_9,(int)param_10,param_7,param_8);
  bVar1 = FUN_c028b988((int)param_1);
  if ((CONCAT31(extraout_var,bVar1) == 0) || (param_4 == 0)) {
    if (param_11 == 0) {
      FUN_c0296448(param_3);
      FUN_c02964e8(param_3);
    }
    else {
      FUN_c0295ef0((int)param_3,(int)param_1);
      FUN_c02960f8((int)param_3,(int)param_1);
      FUN_c0296938(param_3);
      FUN_c02969b0(param_3);
    }
  }
  else {
    FUN_c028b9d8((int)param_1,(char)param_11);
    if (param_11 == 0) {
      FUN_c0298344((int)param_1,param_12,param_13,param_14,param_15,param_16);
    }
    FUN_c0295ef0((int)param_3,(int)param_1);
    FUN_c02960f8((int)param_3,(int)param_1);
    FUN_c02983e8((int)param_3,(int)param_1);
    FUN_c0298490((int)param_3,(int)param_1);
    FUN_c0296938(param_3);
    FUN_c02969b0(param_3);
    FUN_c0296a28(param_3,(int)param_1,param_6);
    if (in_stack_00000054 != 0) {
      FUN_c029715c((int)param_3);
      iVar2 = FUN_c02955a0(param_2,param_3,in_stack_00000058,
                           (uint)in_stack_00000054 + in_stack_00000058,param_1,param_5,
                           in_stack_0000005c,in_stack_00000060,in_stack_00000064);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    if (param_11 == 0) {
      FUN_c0296270(param_3,(int)param_1);
      FUN_c0296374(param_3,(int)param_1);
    }
  }
  return 0;
}



/* c027e6d4 FUN_c027e6d4 */

/* Boundary evidence: original MIPS .pdata c027e6d4..c027e8e3. Semantic name remains unreviewed. */

int FUN_c027e6d4(undefined4 *param_1,void *param_2,int *param_3,int param_4,int param_5,
                short param_6,ushort param_7,ushort param_8,short param_9,short param_10,
                int param_11,int param_12,int param_13,undefined4 param_14,int param_15,int param_16
                )

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  short *in_stack_00000050;
  ushort in_stack_00000054;
  int in_stack_00000058;
  undefined2 *in_stack_0000005c;
  undefined2 *in_stack_00000060;
  uint *in_stack_00000064;
  
  FUN_c028b9b8((int)param_1,1);
  FUN_c028b9a4((int)param_1,in_stack_0000005c,in_stack_00000060);
  *in_stack_00000064 = 0;
  FUN_c02965c0((int)param_3,in_stack_00000050,(int)param_9,(int)param_10,param_7,param_8);
  FUN_c02968c0(param_3);
  bVar1 = FUN_c028b988((int)param_1);
  if ((CONCAT31(extraout_var,bVar1) == 0) || (param_4 == 0)) {
    if (param_11 == 0) {
      FUN_c02964e8(param_3);
    }
    else {
      FUN_c02960f8((int)param_3,(int)param_1);
      FUN_c02969b0(param_3);
    }
  }
  else {
    FUN_c028b9d8((int)param_1,(char)param_11);
    if (param_11 == 0) {
      FUN_c0298344((int)param_1,param_12,param_13,param_14,param_15,param_16);
      FUN_c0295ff4(param_3,(int)param_1);
    }
    FUN_c02960f8((int)param_3,(int)param_1);
    FUN_c02967f4((int)param_3,(int)param_1);
    FUN_c02969b0(param_3);
    FUN_c0296a28(param_3,(int)param_1,param_6);
    if (in_stack_00000054 != 0) {
      FUN_c029715c((int)param_3);
      iVar2 = FUN_c02955a0(param_2,param_3,in_stack_00000058,
                           (uint)in_stack_00000054 + in_stack_00000058,param_1,param_5,
                           in_stack_0000005c,in_stack_00000060,in_stack_00000064);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    if (param_11 == 0) {
      FUN_c0296270(param_3,(int)param_1);
      FUN_c0296374(param_3,(int)param_1);
    }
  }
  return 0;
}



/* c027e8e4 FUN_c027e8e4 */

undefined4 FUN_c027e8e4(int *param_1)

{
  undefined4 uVar1;
  
  if ((param_1[1] == 0) && (param_1[3] == 0)) {
    uVar1 = 0;
  }
  else if ((*param_1 != 0) || (uVar1 = 1, param_1[4] != 0)) {
    uVar1 = 2;
  }
  return uVar1;
}



/* c027e928 FUN_c027e928 */

/* Boundary evidence: original MIPS .pdata c027e928..c027e9ab. Semantic name remains unreviewed. */

void FUN_c027e928(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 == 0) {
    *(int *)(param_1 + 8) = param_2;
  }
  else {
    piVar3 = (int *)(iVar2 + 4);
    iVar1 = *piVar3;
    while (iVar1 != param_1) {
      iVar2 = *piVar3;
      piVar3 = (int *)(iVar2 + 4);
      iVar1 = *piVar3;
    }
    *(int *)(iVar2 + 4) = param_2;
  }
  *(int *)(param_2 + 4) = param_1;
  *(int *)(param_2 + 0xc) = param_1;
  memcpy((void *)(param_2 + 0x90),(void *)(param_1 + 0x90),0x24);
  *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  return;
}



/* c027e9ac FUN_c027e9ac */

/* Boundary evidence: original MIPS .pdata c027e9ac..c027e9f3. Semantic name remains unreviewed. */

void FUN_c027e9ac(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c02755a0((int *)(param_1 + 0x44));
  if (iVar1 == 0) {
    FUN_c029794c(*(undefined4 **)(param_1 + 0x8c),(uint *)(param_1 + 0x44));
  }
  return;
}



/* c027e9f4 FUN_c027e9f4 */

undefined4 FUN_c027e9f4(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((((param_1 & 0x100) == 0) ||
       (((param_1 & 0xff) < (param_2 & 0xff) &&
        (((param_1 & 0x100) == 0 || ((param_1 & 0xff) != 0xff)))))) &&
      (((param_1 & 0x200) == 0 || ((param_2 & 0x400) == 0)))) &&
     (((param_1 & 0x400) == 0 || ((param_2 & 0x1000) == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c027eac0 FUN_c027eac0 */

undefined4 FUN_c027eac0(uint param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_2 + 0xc);
  iVar2 = *piVar5;
  piVar4 = piVar5;
  for (uVar3 = 0; (iVar2 == 0 && (uVar3 < param_1)); uVar3 = uVar3 + 1) {
    piVar4 = piVar4 + 1;
    iVar2 = *piVar4;
  }
  if (uVar3 == param_1) {
    uVar1 = 0x140c;
  }
  else {
    piVar5[uVar3] = 0;
    uVar1 = 0;
    *param_3 = uVar3 * 0xb8 + *(int *)(param_2 + 0x10);
  }
  return uVar1;
}



/* c027eb30 FUN_c027eb30 */

/* Boundary evidence: original MIPS .pdata c027eb30..c027ec57. Semantic name remains unreviewed. */

void FUN_c027eb30(undefined1 *param_1,int param_2,undefined2 param_3,int param_4)

{
  int iVar1;
  
  *param_1 = 0x47;
  *(undefined2 *)(param_1 + 0x22) = 0x7fff;
  *(undefined2 *)(param_1 + 0x24) = 0x7fff;
  *(undefined4 *)(param_1 + 0x34) = 2;
  param_1[1] = 0x44;
  *(undefined2 *)(param_1 + 0x20) = param_3;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 3;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(short *)(param_1 + 0x32) = (short)param_4;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined2 *)(param_1 + 0x26) = 0x8000;
  *(undefined2 *)(param_1 + 0x28) = 0x8000;
  *(undefined2 *)(param_1 + 0x86) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined2 *)(param_1 + 0x2a) = 0;
  *(undefined2 *)(param_1 + 0x2e) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined2 *)(param_1 + 0x3c) = 0;
  *(undefined2 *)(param_1 + 0x3e) = 0;
  *(undefined2 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x42) = 0;
  memcpy(param_1 + 0x44,&DAT_c02616e4,0x24);
  *(undefined2 *)(param_1 + 0x84) = 0xffff;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  iVar1 = param_4 * 0x38 + *(int *)(param_2 + 8);
  *(int *)(param_1 + 0x8c) = iVar1;
  *(undefined2 *)(iVar1 + 0x28) = 0;
  memcpy(param_1 + 0x90,&DAT_c02616e4,0x24);
  *(undefined4 *)(param_1 + 0xb4) = 1;
  return;
}



/* c027ec58 FUN_c027ec58 */

/* Boundary evidence: original MIPS .pdata c027ec58..c027ec9f. Semantic name remains unreviewed. */

void FUN_c027ec58(uint *param_1)

{
  short local_10;
  short local_e;
  
  FUN_c028bad8(*param_1,param_1[1],&local_10);
  *param_1 = (int)local_10 >> 8;
  param_1[1] = (int)local_e >> 8;
  return;
}



/* c027eca0 FUN_c027eca0 */

/* Boundary evidence: original MIPS .pdata c027eca0..c027ee73. Semantic name remains unreviewed. */

void FUN_c027eca0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int *param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = param_3 - param_1;
  uVar4 = param_4 - param_2;
  uVar6 = param_7 - param_5;
  uVar7 = param_8 - param_6;
  if (uVar4 == 0) {
    if (uVar6 == 0) {
      *param_9 = param_5;
      param_9[1] = param_2;
      return;
    }
    uVar5 = param_6 - param_2;
    uVar3 = -uVar7;
  }
  else if (uVar3 == 0) {
    if (uVar7 == 0) {
      *param_9 = param_1;
      param_9[1] = param_6;
      return;
    }
    uVar5 = param_5 - param_1;
    uVar3 = -uVar6;
  }
  else {
    uVar5 = -uVar3;
    if (-1 < (int)uVar3) {
      uVar5 = uVar3;
    }
    uVar2 = -uVar4;
    if (-1 < (int)uVar4) {
      uVar2 = uVar4;
    }
    if ((int)uVar5 < (int)uVar2) {
      iVar1 = FUN_c0274d38(param_6 - param_2,uVar3,uVar4);
      uVar5 = iVar1 + (param_1 - param_5);
      iVar1 = FUN_c0274d38(uVar7,uVar3,uVar4);
      uVar3 = uVar6 - iVar1;
    }
    else {
      iVar1 = FUN_c0274d38(param_5 - param_1,uVar4,uVar3);
      uVar5 = (param_6 - param_2) - iVar1;
      iVar1 = FUN_c0274d38(uVar6,uVar4,uVar3);
      uVar3 = iVar1 - uVar7;
    }
  }
  uVar4 = -uVar3;
  if (-1 < (int)uVar3) {
    uVar4 = uVar3;
  }
  if ((int)uVar4 < 0x11) {
    *param_9 = param_5 + param_3 >> 1;
    param_9[1] = param_6 + param_4 >> 1;
  }
  else {
    iVar1 = FUN_c0274d38(uVar6,uVar5,uVar3);
    *param_9 = iVar1 + param_5;
    iVar1 = FUN_c0274d38(uVar7,uVar5,uVar3);
    param_9[1] = iVar1 + param_6;
  }
  return;
}



/* c027ee74 FUN_c027ee74 */

/* Boundary evidence: original MIPS .pdata c027ee74..c027f1c7. Semantic name remains unreviewed. */

void FUN_c027ee74(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                 int param_7,int param_8,int param_9,int param_10,uint param_11,uint param_12,
                 uint param_13,uint param_14,int param_15,int *param_16)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint local_40;
  uint local_3c;
  int local_38;
  uint local_30;
  uint local_2c;
  
  local_3c = param_7 - param_5;
  local_2c = param_9 - param_7;
  local_40 = -(param_8 - param_6);
  local_30 = -(param_10 - param_8);
  if (param_4 != 0) {
    local_3c = -local_3c;
    local_2c = -local_2c;
    local_40 = param_8 - param_6;
    local_30 = param_10 - param_8;
  }
  local_38 = param_2;
  if (param_3 == 0) {
    FUN_c027ec58(&local_40);
    FUN_c027ec58(&local_30);
    uVar5 = param_11;
    if ((int)local_40 < 1) {
      uVar5 = param_12;
    }
    uVar1 = FUN_c0274e28(local_40,uVar5);
    uVar5 = param_14;
    if (-1 < (int)local_3c) {
      uVar5 = param_13;
    }
    uVar5 = FUN_c0274e28(local_3c,uVar5);
    iVar6 = uVar1 + param_7;
    param_5 = uVar1 + param_5;
    local_40 = uVar5 + param_6;
    iVar2 = param_8 + uVar5;
    uVar5 = param_11;
    if ((int)local_30 < 1) {
      uVar5 = param_12;
    }
    uVar1 = FUN_c0274e28(local_30,uVar5);
    uVar5 = param_14;
    if (-1 < (int)local_2c) {
      uVar5 = param_13;
    }
    uVar5 = FUN_c0274e28(local_2c,uVar5);
    param_7 = uVar1 + param_7;
    param_9 = uVar1 + param_9;
    param_10 = uVar5 + param_10;
    param_8 = uVar5 + param_8;
    param_6 = local_40;
  }
  else {
    iVar6 = param_7;
    if (0 < (int)local_40) {
      iVar6 = param_7 + param_11;
    }
    iVar2 = param_8;
    if (0 < (int)local_30) {
      param_7 = param_7 + param_11;
    }
  }
  if ((iVar6 == param_7) && (iVar2 == param_8)) {
    *(int *)(param_1 * 4 + *param_16) = param_7;
    *(int *)(param_16[1] + param_1 * 4) = param_8;
  }
  else {
    FUN_c027eca0(param_5,param_6,iVar6,iVar2,param_7,param_8,param_9,param_10,(int *)&local_30);
    iVar4 = param_1 * 4;
    uVar5 = *(uint *)(iVar4 + *param_16);
    iVar2 = *(int *)(param_16[1] + iVar4);
    iVar6 = local_30 - uVar5;
    iVar7 = local_2c - iVar2;
    if ((int)param_11 < iVar6) {
      local_30 = uVar5 + param_11;
    }
    if (iVar6 < (int)-param_12) {
      local_30 = uVar5 - param_12;
    }
    if (iVar7 < (int)-param_14) {
      local_2c = iVar2 - param_14;
    }
    if ((int)param_13 < iVar7) {
      local_2c = iVar2 + param_14;
    }
    *(uint *)(iVar4 + *param_16) = local_30;
    *(uint *)(param_16[1] + iVar4) = local_2c;
  }
  iVar6 = param_1 * 4;
  *(int *)(iVar6 + *param_16) = *(int *)(iVar6 + *param_16) + param_12;
  *(int *)(param_16[1] + iVar6) = *(int *)(param_16[1] + iVar6) + param_14;
  if (*(int *)(param_16[1] + iVar6) < param_15) {
    *(int *)(param_16[1] + iVar6) = param_15;
  }
  if ((param_1 != local_38) && (iVar2 = param_1 + 1, iVar2 <= local_38)) {
    iVar4 = iVar2 * 4;
    iVar2 = (local_38 - iVar2) + 1;
    do {
      *(undefined4 *)(iVar4 + *param_16) = *(undefined4 *)(*param_16 + iVar6);
      puVar3 = (undefined4 *)(iVar4 + param_16[1]);
      iVar4 = iVar4 + 4;
      iVar2 = iVar2 + -1;
      *puVar3 = *(undefined4 *)(param_16[1] + iVar6);
    } while (iVar2 != 0);
  }
  return;
}



/* c027f1c8 FUN_c027f1c8 */

/* Boundary evidence: original MIPS .pdata c027f1c8..c027f62b. Semantic name remains unreviewed. */

void FUN_c027f1c8(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  uint uVar20;
  uint local_54;
  int local_34;
  int local_30;
  
  piVar14 = *(int **)(param_1 + 8);
  uVar20 = (uint)(*(ushort *)(param_2 + 0x16a) == 1);
  if ((param_5 != 0) && (uVar20 = 1, 1 < *(ushort *)(param_2 + 0x16a))) {
    uVar20 = 0;
  }
  iVar12 = (int)*(short *)((short)piVar14[10] * 2 + piVar14[8] + -2);
  iVar18 = *piVar14;
  if (*(int *)((iVar12 + 2U & 0xffff) * 4 + iVar18) != *(int *)((iVar12 + 1U & 0xffff) * 4 + iVar18)
     ) {
    if (param_5 == 0) {
      piVar19 = (int *)(((int)*(short *)((short)piVar14[10] * 2 + piVar14[8] + -2) + 2U & 0xffff) *
                        4 + iVar18);
      iVar12 = *piVar19;
    }
    else {
      piVar19 = (int *)(((int)*(short *)((short)piVar14[10] * 2 + piVar14[8] + -2) + 2U & 0xffff) *
                        4 + iVar18);
      iVar12 = *piVar19;
    }
    *piVar19 = iVar12 + 0x40;
  }
  iVar12 = (int)*(short *)((short)piVar14[10] * 2 + piVar14[8] + -2);
  if (*(int *)((iVar12 + 4U & 0xffff) * 4 + piVar14[1]) !=
      *(int *)((iVar12 + 3U & 0xffff) * 4 + piVar14[1])) {
    piVar19 = (int *)(((int)*(short *)((short)piVar14[10] * 2 + piVar14[8] + -2) + 4U & 0xffff) * 4
                     + piVar14[1]);
    *piVar19 = *piVar19 + -0x40;
  }
  if (param_4 == 0) {
    if (param_3 == 0) {
      uVar10 = (uint)*(ushort *)(param_2 + 0x16a) << 5;
      uVar6 = (uint)*(ushort *)(param_2 + 0x168) << 5;
      uVar11 = uVar6;
      local_54 = uVar10;
    }
    else {
      if (param_5 == 0) {
        uVar10 = (uint)(*(ushort *)(param_2 + 0x16a) >> 1);
        iVar12 = *(ushort *)(param_2 + 0x16a) - uVar10;
      }
      else {
        uVar10 = (uint)(*(ushort *)(param_2 + 0x16a) >> 1);
        iVar12 = *(ushort *)(param_2 + 0x16a) - uVar10;
      }
      uVar10 = uVar10 << 6;
      uVar11 = (uint)(*(ushort *)(param_2 + 0x168) >> 1);
      uVar6 = uVar11 << 6;
      uVar11 = (*(ushort *)(param_2 + 0x168) - uVar11) * 0x40;
      local_54 = iVar12 << 6;
    }
    local_34 = 0;
    if (0 < (short)piVar14[10]) {
      local_30 = 0;
      do {
        iVar12 = (int)*(short *)(piVar14[7] + local_30);
        iVar18 = (int)*(short *)(local_30 + piVar14[8]);
        if (1 < iVar18 - iVar12) {
          bVar1 = *(byte *)(piVar14[0xb] + local_34);
          iVar9 = piVar14[1];
          iVar13 = iVar12 * 4;
          piVar19 = (int *)(iVar13 + *piVar14);
          uVar7 = *(uint *)(iVar13 + iVar9);
          iVar8 = *piVar19;
          uVar5 = uVar7;
          iVar16 = iVar8;
          uVar3 = *(uint *)(iVar9 + iVar18 * 4);
          iVar4 = *(int *)(iVar18 * 4 + *piVar14);
          iVar15 = piVar19[1];
          uVar17 = *(uint *)(iVar9 + iVar13 + 4);
          while (iVar9 = iVar16, uVar2 = uVar5, iVar12 <= iVar18) {
            iVar16 = iVar12;
            if (iVar15 == iVar9) {
              iVar13 = iVar12 << 2;
              do {
                if ((uVar17 != uVar2) || (iVar18 <= iVar16)) break;
                iVar16 = iVar16 + 1;
                iVar13 = iVar13 + 4;
                iVar15 = iVar8;
                uVar17 = uVar7;
                if (iVar16 < iVar18) {
                  iVar15 = *(int *)(*piVar14 + iVar13 + 4);
                  uVar17 = *(uint *)(piVar14[1] + iVar13 + 4);
                }
              } while (iVar15 == iVar9);
            }
            FUN_c027ee74(iVar12,iVar16,uVar20,(uint)((bVar1 & 1) != 0),iVar4,uVar3,iVar9,uVar2,
                         iVar15,uVar17,local_54,uVar10,uVar6,uVar11,*(int *)(param_2 + 0x16c),
                         piVar14);
            iVar12 = iVar16 + 1;
            uVar5 = uVar17;
            iVar16 = iVar15;
            uVar3 = uVar2;
            iVar4 = iVar9;
            iVar15 = iVar8;
            uVar17 = uVar7;
            if (iVar12 < iVar18) {
              iVar15 = *(int *)(*piVar14 + iVar12 * 4 + 4);
              uVar17 = *(uint *)(iVar12 * 4 + piVar14[1] + 4);
            }
          }
        }
        local_34 = local_34 + 1;
        local_30 = local_30 + 2;
      } while (local_34 < (short)piVar14[10]);
    }
  }
  return;
}



/* c027f62c FUN_c027f62c */

/* Boundary evidence: original MIPS .pdata c027f62c..c027f833. Semantic name remains unreviewed. */

int FUN_c027f62c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((0 < (int)param_2) || (iVar4 = 1, param_2 == 0)) {
    iVar4 = 0;
  }
  if ((0 < (int)param_4) || (iVar3 = 1, param_4 == 0)) {
    iVar3 = 0;
  }
  if (iVar4 == iVar3) {
    uVar2 = param_1;
    if (((int)param_2 < 1) && (param_2 != 0)) {
      uVar2 = -param_1;
      param_2 = -(uint)(param_1 != 0) - param_2;
      bVar1 = param_3 != 0;
      param_3 = -param_3;
      param_4 = -(uint)bVar1 - param_4;
    }
    if (((int)param_4 < (int)param_2) || ((param_2 == param_4 && (param_3 <= uVar2)))) {
      uVar5 = param_4 << 0x10 | param_3 >> 0x10;
      if (((int)param_2 < (int)uVar5) || ((param_2 == uVar5 && (uVar2 <= param_3 << 0x10)))) {
        uVar5 = param_4 << 0x1f | param_3 >> 1;
        uVar2 = uVar5 + uVar2;
        iVar4 = __ll_div(uVar2,((int)param_4 >> 1) + param_2 + (uint)(uVar2 < uVar5));
      }
      else {
        iVar4 = 0x10001;
      }
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if (((int)param_2 < 1) && (param_2 != 0)) {
      param_2 = -(uint)(param_1 != 0) - param_2;
      param_1 = -param_1;
      uVar2 = param_3;
    }
    else {
      uVar2 = -param_3;
      param_4 = -(uint)(param_3 != 0) - param_4;
    }
    if (((int)param_4 < (int)param_2) || ((param_2 == param_4 && (uVar2 <= param_1)))) {
      uVar5 = param_4 << 0x10 | uVar2 >> 0x10;
      if (((int)param_2 < (int)uVar5) || ((param_2 == uVar5 && (param_1 <= uVar2 << 0x10)))) {
        uVar5 = param_4 << 0x1f | uVar2 >> 1;
        uVar2 = uVar5 + param_1;
        iVar4 = __ll_div(uVar2,((int)param_4 >> 1) + param_2 + (uint)(uVar2 < uVar5));
        iVar4 = -iVar4;
      }
      else {
        iVar4 = -0x10001;
      }
    }
    else {
      iVar4 = -1;
    }
  }
  return iVar4;
}



/* c027f834 FUN_c027f834 */

void FUN_c027f834(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = 0;
  uVar6 = 0x40000000;
  uVar2 = 0;
  uVar7 = 0;
  do {
    uVar4 = uVar7 + uVar1;
    uVar5 = uVar6 + uVar2 + (uint)(uVar4 < uVar7);
    uVar3 = param_1;
    if ((uVar5 <= param_2) && ((uVar5 != param_2 || (uVar4 <= param_1)))) {
      uVar3 = param_1 - uVar4;
      param_2 = (param_2 - uVar5) - (uint)(param_1 < uVar4);
      uVar1 = uVar7 << 1 | uVar1;
      uVar2 = uVar6 << 1 | uVar7 >> 0x1f | uVar2;
    }
    param_2 = param_2 << 1 | uVar3 >> 0x1f;
    uVar4 = uVar6 << 0x1f;
    param_1 = uVar3 << 1;
    uVar6 = uVar6 >> 1;
    uVar7 = uVar4 | uVar7 >> 1;
  } while ((uVar6 != 0) || (0x7fff < uVar7));
  return;
}



/* c027f8e4 FUN_c027f8e4 */

/* Boundary evidence: original MIPS .pdata c027f8e4..c027fb37. Semantic name remains unreviewed. */

void FUN_c027f8e4(uint param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                 undefined4 *param_7,int *param_8,int *param_9)

{
  ulonglong uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int extraout_v1;
  int extraout_v1_00;
  int extraout_v1_01;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  
  *param_7 = 0;
  if (param_1 == 0 && param_2 == 0) {
    bVar2 = param_3 == 0;
    bVar3 = param_4 == 0;
    uVar6 = param_3;
    uVar10 = param_4;
    param_3 = param_5;
    param_4 = param_6;
    if (bVar2 && bVar3) {
      return;
    }
  }
  else {
    uVar1 = (ulonglong)param_1 * 2;
    uVar6 = (uint)uVar1;
    uVar10 = param_2 * 2 + (int)(uVar1 >> 0x20);
    uVar5 = (uint)((ulonglong)param_3 * (ulonglong)param_3);
    uVar1 = (uVar1 & 0xffffffff) * (ulonglong)param_5;
    lVar11 = (uVar1 & 0xffffffff) * 2;
    uVar9 = (uint)lVar11;
    uVar7 = ((param_3 * param_4 + param_4 * param_3 +
             (int)((ulonglong)param_3 * (ulonglong)param_3 >> 0x20)) -
            ((uVar6 * param_6 + uVar10 * param_5 + (int)(uVar1 >> 0x20)) * 2 +
            (int)((ulonglong)lVar11 >> 0x20))) - (uint)(uVar5 < uVar9);
    uVar5 = uVar5 - uVar9;
    if ((-1 < (int)uVar7) && ((uVar7 != 0 || (uVar5 != 0)))) {
      *param_7 = 2;
      lVar11 = FUN_c027f834(uVar5,uVar7);
      iVar8 = (int)((ulonglong)(lVar11 + 0x8000) >> 0x20);
      iVar4 = iVar8 >> 0x10;
      uVar7 = iVar8 * 0x10000 | (uint)(lVar11 + 0x8000) >> 0x10;
      uVar9 = param_4 << 0x10 | param_3 >> 0x10;
      iVar8 = FUN_c027f62c(uVar7 + param_3 * -0x10000,
                           (iVar4 - uVar9) - (uint)(uVar7 < param_3 * 0x10000),uVar6,uVar10);
      uVar5 = uVar7 + param_3 * 0x10000;
      *param_8 = iVar8;
      param_8[1] = extraout_v1;
      iVar4 = FUN_c027f62c(-uVar5,-(uint)(uVar5 != 0) - (iVar4 + uVar9 + (uint)(uVar5 < uVar7)),
                           uVar6,uVar10);
      iVar8 = extraout_v1_00;
      param_8 = param_9;
      goto LAB_c027fb0c;
    }
    if (uVar5 != 0 || uVar7 != 0) {
      return;
    }
  }
  *param_7 = 1;
  iVar4 = FUN_c027f62c(param_3 * -0x10000,
                       -(uint)((param_3 & 0xffff) != 0) - (param_4 << 0x10 | param_3 >> 0x10),uVar6,
                       uVar10);
  iVar8 = extraout_v1_01;
LAB_c027fb0c:
  *param_8 = iVar4;
  param_8[1] = iVar8;
  return;
}



/* c027fb38 FUN_c027fb38 */

/* Boundary evidence: original MIPS .pdata c027fb38..c027fea3. Semantic name remains unreviewed. */

undefined4
FUN_c027fb38(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  longlong lVar1;
  int extraout_v1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar8 = param_7 - param_5;
  uVar7 = param_4 - param_2;
  uVar9 = param_8 - param_6;
  uVar6 = param_3 - param_1;
  uVar2 = uVar6 * uVar9 - uVar7 * uVar8;
  if (uVar2 == 0) {
    return 0;
  }
  iVar5 = ((param_1 * uVar7 - param_2 * uVar6) - uVar7 * param_5) + uVar6 * param_6;
  uVar2 = FUN_c027f62c(iVar5 * -0x10000,
                       (-(uint)(iVar5 != 0) - (iVar5 >> 0x1f)) * 0x10000 | (uint)-iVar5 >> 0x10,
                       uVar2,(int)uVar2 >> 0x1f);
  if (extraout_v1 + -1 + (uint)(uVar2 - 1 < uVar2) != 0) {
    return 0;
  }
  if (0xffff < uVar2 - 1) {
    return 0;
  }
  uVar10 = -uVar6;
  if (-1 < (int)uVar6) {
    uVar10 = uVar6;
  }
  uVar3 = -uVar7;
  if (-1 < (int)uVar7) {
    uVar3 = uVar7;
  }
  if ((int)uVar3 < (int)uVar10) {
    lVar1 = (ulonglong)(uint)(param_5 - param_1) * 0x10000;
    uVar7 = (uint)lVar1;
    uVar10 = uVar7 + (int)((ulonglong)uVar8 * (ulonglong)uVar2);
    iVar5 = (param_5 - param_1 >> 0x1f) * 0x10000 + (int)((ulonglong)lVar1 >> 0x20) +
            uVar8 * extraout_v1 + ((int)uVar8 >> 0x1f) * uVar2 +
            (int)((ulonglong)uVar8 * (ulonglong)uVar2 >> 0x20) + (uint)(uVar10 < uVar7);
  }
  else {
    lVar1 = (ulonglong)(uint)(param_6 - param_2) * 0x10000;
    uVar6 = (uint)lVar1;
    uVar10 = uVar6 + (int)((ulonglong)uVar9 * (ulonglong)uVar2);
    iVar5 = (param_6 - param_2 >> 0x1f) * 0x10000 + (int)((ulonglong)lVar1 >> 0x20) +
            uVar9 * extraout_v1 + ((int)uVar9 >> 0x1f) * uVar2 +
            (int)((ulonglong)uVar9 * (ulonglong)uVar2 >> 0x20) + (uint)(uVar10 < uVar6);
    uVar6 = uVar7;
  }
  if ((int)uVar6 < 0) {
    iVar4 = ((int)uVar6 >> 0x1f) * 0x10000 + (int)((ulonglong)uVar6 * 0x10000 >> 0x20);
    if (iVar5 < iVar4) {
      return 0;
    }
    if ((iVar4 == iVar5) && (uVar10 < (uint)((ulonglong)uVar6 * 0x10000))) {
      return 0;
    }
    if (0 < iVar5) {
      return 0;
    }
    if (iVar5 == 0) {
      return 0;
    }
  }
  else {
    if (iVar5 < 0) {
      return 0;
    }
    if ((iVar5 == 0) && (uVar10 == 0)) {
      return 0;
    }
    iVar4 = ((int)uVar6 >> 0x1f) * 0x10000 + (int)((ulonglong)uVar6 * 0x10000 >> 0x20);
    if (iVar4 < iVar5) {
      return 0;
    }
    if ((iVar5 == iVar4) && ((uint)((ulonglong)uVar6 * 0x10000) < uVar10)) {
      return 0;
    }
  }
  return 1;
}



/* c027fea4 FUN_c027fea4 */

/* Boundary evidence: original MIPS .pdata c027fea4..c02802bf. Semantic name remains unreviewed. */

int FUN_c027fea4(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
                ,int param_8,int param_9,int param_10)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int local_40;
  int local_3c;
  uint local_38 [4];
  
  iVar10 = param_3 - param_1;
  uVar12 = param_9 + param_5 + param_7 * -2;
  uVar13 = param_6 + param_8 * -2 + param_10;
  iVar11 = param_4 - param_2;
  uVar14 = (param_7 - param_5) * 2;
  uVar15 = (param_8 - param_6) * 2;
  uVar8 = ((param_1 * iVar11 - param_2 * iVar10) - iVar11 * param_5) + iVar10 * param_6;
  uVar5 = iVar10 * uVar15 - iVar11 * uVar14;
  uVar4 = iVar10 * uVar13 - iVar11 * uVar12;
  local_3c = param_1;
  FUN_c027f8e4(uVar4,(int)uVar4 >> 0x1f,uVar5,(int)uVar5 >> 0x1f,uVar8,(int)uVar8 >> 0x1f,&local_40,
               (int *)local_38,(int *)(local_38 + 2));
  iVar2 = 0;
  if (0 < local_40) {
    puVar3 = local_38;
    do {
      uVar4 = puVar3[1];
      uVar5 = *puVar3;
      if (((-1 < (int)uVar4) && (((uVar4 != 0 || (uVar5 != 0)) && ((int)uVar4 < 1)))) &&
         ((uVar4 != 0 || (uVar5 < 0x10001)))) {
        iVar6 = -iVar10;
        if (-1 < iVar10) {
          iVar6 = iVar10;
        }
        iVar7 = -iVar11;
        if (-1 < iVar11) {
          iVar7 = iVar11;
        }
        if (iVar7 < iVar6) {
          uVar8 = (uint)((ulonglong)uVar12 * (ulonglong)uVar5);
          uVar9 = uVar8 + (int)((ulonglong)uVar14 * 0x10000);
          iVar6 = (int)((ulonglong)uVar9 * (ulonglong)uVar5);
          iVar7 = uVar9 * uVar4 +
                  (uVar12 * uVar4 + ((int)uVar12 >> 0x1f) * uVar5 +
                   (int)((ulonglong)uVar12 * (ulonglong)uVar5 >> 0x20) +
                   ((int)uVar14 >> 0x1f) * 0x10000 + (int)((ulonglong)uVar14 * 0x10000 >> 0x20) +
                  (uint)(uVar9 < uVar8)) * uVar5 +
                  (int)((ulonglong)uVar9 * (ulonglong)uVar5 >> 0x20) + (param_5 - local_3c);
          if (iVar10 < 0) {
            bVar1 = iVar7 < iVar10;
LAB_c0280264:
            if (((bVar1) || (0 < iVar7)) || (iVar7 == 0)) goto LAB_c0280280;
          }
          else {
            if (((iVar7 < 0) || ((iVar7 == 0 && (iVar6 == 0)))) || (iVar10 < iVar7))
            goto LAB_c0280280;
            if (iVar7 == iVar10) {
LAB_c028014c:
              if (iVar6 != 0) goto LAB_c0280280;
            }
          }
LAB_c028027c:
          iVar2 = iVar2 + 1;
        }
        else {
          uVar8 = (uint)((ulonglong)uVar13 * (ulonglong)uVar5);
          uVar9 = uVar8 + (int)((ulonglong)uVar15 * 0x10000);
          iVar6 = (int)((ulonglong)uVar9 * (ulonglong)uVar5);
          iVar7 = uVar9 * uVar4 +
                  (uVar13 * uVar4 + ((int)uVar13 >> 0x1f) * uVar5 +
                   (int)((ulonglong)uVar13 * (ulonglong)uVar5 >> 0x20) +
                   ((int)uVar15 >> 0x1f) * 0x10000 + (int)((ulonglong)uVar15 * 0x10000 >> 0x20) +
                  (uint)(uVar9 < uVar8)) * uVar5 +
                  (int)((ulonglong)uVar9 * (ulonglong)uVar5 >> 0x20) + (param_6 - param_2);
          if (iVar11 < 0) {
            bVar1 = iVar7 < iVar11;
            goto LAB_c0280264;
          }
          if (((-1 < iVar7) && ((iVar7 != 0 || (iVar6 != 0)))) && (iVar7 <= iVar11)) {
            if (iVar7 == iVar11) goto LAB_c028014c;
            goto LAB_c028027c;
          }
        }
      }
LAB_c0280280:
      local_40 = local_40 + -1;
      puVar3 = puVar3 + 2;
    } while (local_40 != 0);
  }
  return iVar2;
}



/* c02802c0 FUN_c02802c0 */

/* Boundary evidence: original MIPS .pdata c02802c0..c028070b. Semantic name remains unreviewed. */

void FUN_c02802c0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int *param_10,int *param_11)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
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
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  
  if (param_4 == 0) {
    uVar14 = param_2 + param_5;
    uVar9 = param_3 + param_6;
  }
  else {
    uVar14 = param_2 << 1;
    uVar9 = param_3 << 1;
  }
  if (param_9 == 0) {
    uVar10 = param_5 + param_7;
    uVar18 = param_6 + param_8;
  }
  else {
    uVar10 = param_7 << 1;
    uVar18 = param_8 << 1;
  }
  uVar16 = param_5 * 4;
  uVar12 = uVar14 + param_5 * -4 + uVar10;
  if (uVar12 == 0) {
    *param_10 = param_5 * 2;
    *param_11 = param_6 << 1;
  }
  else {
    uVar11 = uVar14 + param_5 * -2;
    uVar7 = uVar10 + param_5 * -2;
    iVar6 = (int)uVar11 >> 0x1f;
    iVar20 = (int)uVar7 >> 0x1f;
    uVar2 = (uint)((ulonglong)uVar12 * (ulonglong)uVar12);
    iVar17 = uVar12 * ((int)uVar12 >> 0x1f) + ((int)uVar12 >> 0x1f) * uVar12 +
             (int)((ulonglong)uVar12 * (ulonglong)uVar12 >> 0x20);
    uVar12 = (uint)((ulonglong)uVar16 * (ulonglong)uVar11);
    uVar15 = uVar12 + (int)((ulonglong)uVar14 * (ulonglong)uVar7);
    uVar3 = (uint)((ulonglong)uVar15 * (ulonglong)uVar7);
    uVar4 = (ulonglong)uVar10 * (ulonglong)uVar11;
    lVar5 = (uVar4 & 0xffffffff) * (ulonglong)uVar11;
    uVar13 = param_6 * 4;
    uVar8 = uVar3 + (int)lVar5;
    iVar19 = uVar15 * iVar20 +
             (uVar16 * iVar6 + ((int)uVar16 >> 0x1f) * uVar11 +
              (int)((ulonglong)uVar16 * (ulonglong)uVar11 >> 0x20) +
              uVar14 * iVar20 + ((int)uVar14 >> 0x1f) * uVar7 +
              (int)((ulonglong)uVar14 * (ulonglong)uVar7 >> 0x20) + (uint)(uVar15 < uVar12)) * uVar7
             + (int)((ulonglong)uVar15 * (ulonglong)uVar7 >> 0x20) +
             (int)uVar4 * iVar6 +
             (uVar10 * iVar6 + ((int)uVar10 >> 0x1f) * uVar11 + (int)(uVar4 >> 0x20)) * uVar11 +
             (int)((ulonglong)lVar5 >> 0x20) + (uint)(uVar8 < uVar3);
    uVar14 = (uint)((ulonglong)uVar13 * (ulonglong)uVar11);
    uVar12 = uVar14 + (int)((ulonglong)uVar9 * (ulonglong)uVar7);
    uVar10 = (uint)((ulonglong)uVar12 * (ulonglong)uVar7);
    uVar4 = (ulonglong)uVar18 * (ulonglong)uVar11;
    lVar5 = (uVar4 & 0xffffffff) * (ulonglong)uVar11;
    uVar16 = uVar10 + (int)lVar5;
    iVar6 = uVar12 * iVar20 +
            (uVar13 * iVar6 + ((int)uVar13 >> 0x1f) * uVar11 +
             (int)((ulonglong)uVar13 * (ulonglong)uVar11 >> 0x20) +
             uVar9 * iVar20 + ((int)uVar9 >> 0x1f) * uVar7 +
             (int)((ulonglong)uVar9 * (ulonglong)uVar7 >> 0x20) + (uint)(uVar12 < uVar14)) * uVar7 +
            (int)((ulonglong)uVar12 * (ulonglong)uVar7 >> 0x20) +
            (int)uVar4 * iVar6 +
            (uVar18 * iVar6 + ((int)uVar18 >> 0x1f) * uVar11 + (int)(uVar4 >> 0x20)) * uVar11 +
            (int)((ulonglong)lVar5 >> 0x20) + (uint)(uVar16 < uVar10);
    if (param_1 == 0) {
      uVar9 = uVar8 + uVar2;
      bVar1 = uVar9 < uVar8;
      uVar8 = uVar9 - 1;
      iVar19 = (iVar19 + iVar17 + (uint)bVar1) - (uint)(uVar9 == 0);
    }
    iVar19 = __ll_div(uVar8,iVar19,uVar2,iVar17);
    *param_10 = iVar19;
    if (iVar6 < 0) {
      iVar6 = __ll_div(uVar2 - uVar16,(iVar17 - iVar6) - (uint)(uVar2 < uVar16),uVar2,iVar17);
      iVar6 = -iVar6;
    }
    else {
      iVar6 = __ll_div(uVar16 + uVar2,iVar6 + iVar17 + (uint)(uVar16 + uVar2 < uVar16),uVar2,iVar17)
      ;
    }
    *param_11 = iVar6;
  }
  return;
}



/* c028070c FUN_c028070c */

/* Boundary evidence: original MIPS .pdata c028070c..c0280b5b. Semantic name remains unreviewed. */

void FUN_c028070c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9,int *param_10,int *param_11)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  
  if (param_4 == 0) {
    uVar19 = param_2 + param_5;
    uVar8 = param_3 + param_6;
  }
  else {
    uVar19 = param_2 << 1;
    uVar8 = param_3 << 1;
  }
  if (param_9 == 0) {
    uVar7 = param_5 + param_7;
    uVar9 = param_6 + param_8;
  }
  else {
    uVar7 = param_7 << 1;
    uVar9 = param_8 << 1;
  }
  uVar18 = param_6 * 4;
  uVar12 = uVar8 + param_6 * -4 + uVar9;
  if (uVar12 == 0) {
    *param_10 = param_5 << 1;
    *param_11 = param_6 * 2;
  }
  else {
    uVar10 = uVar8 + param_6 * -2;
    uVar11 = param_5 * 4;
    iVar5 = (int)uVar10 >> 0x1f;
    uVar6 = uVar9 + param_6 * -2;
    iVar20 = (int)uVar6 >> 0x1f;
    uVar2 = (uint)((ulonglong)uVar12 * (ulonglong)uVar12);
    iVar15 = uVar12 * ((int)uVar12 >> 0x1f) + ((int)uVar12 >> 0x1f) * uVar12 +
             (int)((ulonglong)uVar12 * (ulonglong)uVar12 >> 0x20);
    uVar12 = (uint)((ulonglong)uVar11 * (ulonglong)uVar10);
    uVar13 = uVar12 + (int)((ulonglong)uVar19 * (ulonglong)uVar6);
    uVar14 = (uint)((ulonglong)uVar13 * (ulonglong)uVar6);
    uVar3 = (ulonglong)uVar7 * (ulonglong)uVar10;
    lVar4 = (uVar3 & 0xffffffff) * (ulonglong)uVar10;
    uVar16 = uVar14 + (int)lVar4;
    iVar17 = uVar13 * iVar20 +
             (uVar11 * iVar5 + ((int)uVar11 >> 0x1f) * uVar10 +
              (int)((ulonglong)uVar11 * (ulonglong)uVar10 >> 0x20) +
              uVar19 * iVar20 + ((int)uVar19 >> 0x1f) * uVar6 +
              (int)((ulonglong)uVar19 * (ulonglong)uVar6 >> 0x20) + (uint)(uVar13 < uVar12)) * uVar6
             + (int)((ulonglong)uVar13 * (ulonglong)uVar6 >> 0x20) +
             (int)uVar3 * iVar5 +
             (uVar7 * iVar5 + ((int)uVar7 >> 0x1f) * uVar10 + (int)(uVar3 >> 0x20)) * uVar10 +
             (int)((ulonglong)lVar4 >> 0x20) + (uint)(uVar16 < uVar14);
    uVar19 = (uint)((ulonglong)uVar18 * (ulonglong)uVar10);
    uVar14 = uVar19 + (int)((ulonglong)uVar8 * (ulonglong)uVar6);
    uVar7 = (uint)((ulonglong)uVar14 * (ulonglong)uVar6);
    uVar3 = (ulonglong)uVar9 * (ulonglong)uVar10;
    lVar4 = (uVar3 & 0xffffffff) * (ulonglong)uVar10;
    uVar12 = uVar7 + (int)lVar4;
    iVar5 = uVar14 * iVar20 +
            (uVar18 * iVar5 + ((int)uVar18 >> 0x1f) * uVar10 +
             (int)((ulonglong)uVar18 * (ulonglong)uVar10 >> 0x20) +
             uVar8 * iVar20 + ((int)uVar8 >> 0x1f) * uVar6 +
             (int)((ulonglong)uVar8 * (ulonglong)uVar6 >> 0x20) + (uint)(uVar14 < uVar19)) * uVar6 +
            (int)((ulonglong)uVar14 * (ulonglong)uVar6 >> 0x20) +
            (int)uVar3 * iVar5 +
            (uVar9 * iVar5 + ((int)uVar9 >> 0x1f) * uVar10 + (int)(uVar3 >> 0x20)) * uVar10 +
            (int)((ulonglong)lVar4 >> 0x20) + (uint)(uVar12 < uVar7);
    if (param_1 == 0) {
      uVar8 = uVar12 + uVar2;
      bVar1 = uVar8 < uVar12;
      uVar12 = uVar8 - 1;
      iVar5 = (iVar5 + iVar15 + (uint)bVar1) - (uint)(uVar8 == 0);
    }
    iVar5 = __ll_div(uVar12,iVar5,uVar2,iVar15);
    *param_11 = iVar5;
    if (iVar17 < 0) {
      iVar5 = __ll_div(uVar2 - uVar16,(iVar15 - iVar17) - (uint)(uVar2 < uVar16),uVar2,iVar15);
      iVar5 = -iVar5;
    }
    else {
      iVar5 = __ll_div(uVar16 + uVar2,iVar17 + iVar15 + (uint)(uVar16 + uVar2 < uVar16),uVar2,iVar15
                      );
    }
    *param_10 = iVar5;
  }
  return;
}



/* c0280b5c FUN_c0280b5c */

void FUN_c0280b5c(int param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    param_4[1] = param_3;
    *param_4 = param_2 + 1;
    *param_5 = -0x8000;
    param_5[1] = param_4[1] + -1;
  }
  else if (param_1 == 1) {
    *param_4 = param_2 + -1;
    param_4[1] = param_3;
    *param_5 = 0x7fff;
    param_5[1] = param_4[1] + -1;
  }
  else {
    if (param_1 == 2) {
      iVar1 = param_3 + 1;
      iVar2 = -0x8000;
    }
    else {
      if (param_1 != 3) {
        return;
      }
      iVar1 = param_3 + -1;
      iVar2 = 0x7fff;
    }
    *param_4 = param_2;
    param_4[1] = iVar1;
    *param_5 = param_2 + -1;
    param_5[1] = iVar2;
  }
  return;
}



/* c0280c10 FUN_c0280c10 */

void FUN_c0280c10(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int *param_7,int *param_8)

{
  *param_7 = param_1;
  param_7[1] = param_2;
  if (param_3 < param_1) {
    *param_7 = param_3;
  }
  if (param_5 < *param_7) {
    *param_7 = param_5;
  }
  if (param_4 < param_7[1]) {
    param_7[1] = param_4;
  }
  if (param_6 < param_7[1]) {
    param_7[1] = param_6;
  }
  *param_8 = param_1;
  param_8[1] = param_2;
  if (param_1 < param_3) {
    *param_8 = param_3;
  }
  if (*param_8 < param_5) {
    *param_8 = param_5;
  }
  if (param_8[1] < param_4) {
    param_8[1] = param_4;
  }
  if (param_8[1] < param_6) {
    param_8[1] = param_6;
  }
  return;
}



/* c0280cd0 FUN_c0280cd0 */

void FUN_c0280cd0(int param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6)

{
  *param_5 = param_1;
  param_5[1] = param_2;
  if (param_3 < param_1) {
    *param_5 = param_3;
  }
  if (param_4 < param_5[1]) {
    param_5[1] = param_4;
  }
  *param_6 = param_1;
  param_6[1] = param_2;
  if (param_1 < param_3) {
    *param_6 = param_3;
  }
  if (param_6[1] < param_4) {
    param_6[1] = param_4;
  }
  return;
}



/* c0280d38 FUN_c0280d38 */

void FUN_c0280d38(int param_1,int param_2)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  if (*(short *)(*(int *)(param_1 + 0x130) + 0x14) != 0) {
    iVar5 = 0;
    do {
      puVar2 = (undefined4 *)(iVar5 + *(int *)(param_1 + 0x94));
      puVar3 = (undefined4 *)(*(int *)(param_2 + 0x94) + iVar5);
      *puVar3 = *puVar2;
      iVar6 = iVar6 + 1;
      puVar3[1] = puVar2[1];
      iVar5 = iVar5 + 8;
    } while (iVar6 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x130) + 0x14));
  }
  *(undefined4 *)(param_2 + 0x128) = *(undefined4 *)(param_1 + 0x128);
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x128)) {
    iVar5 = 0;
    do {
      puVar2 = (undefined4 *)(iVar5 + *(int *)(param_1 + 0x98));
      puVar3 = (undefined4 *)(iVar5 + *(int *)(param_2 + 0x98));
      *puVar3 = *puVar2;
      iVar6 = iVar6 + 1;
      puVar3[1] = puVar2[1];
      iVar5 = iVar5 + 8;
    } while (iVar6 < *(int *)(param_1 + 0x128));
  }
  iVar6 = 0;
  *(undefined2 *)(param_2 + 0x172) = *(undefined2 *)(param_1 + 0x172);
  sVar1 = *(short *)(param_1 + 0x174);
  *(short *)(param_2 + 0x174) = sVar1;
  if (sVar1 != 0) {
    puVar4 = (undefined2 *)(param_2 + 0x176);
    do {
      iVar6 = iVar6 + 1;
      *puVar4 = *(undefined2 *)((param_1 - param_2) + (int)puVar4);
      puVar4 = puVar4 + 1;
    } while (iVar6 < (int)(uint)*(ushort *)(param_2 + 0x174));
  }
  return;
}



/* c0280e18 FUN_c0280e18 */

/* Boundary evidence: original MIPS .pdata c0280e18..c0280e33. Semantic name remains unreviewed. */

void FUN_c0280e18(int param_1,uint param_2)

{
  FUN_c0297a20(*(int **)(param_1 + 8),param_2);
  return;
}



/* c0280e34 FUN_c0280e34 */

/* Boundary evidence: original MIPS .pdata c0280e34..c0280e4f. Semantic name remains unreviewed. */

void FUN_c0280e34(int param_1,int param_2,int param_3)

{
  FUN_c0297ad0(*(int **)(param_1 + 8),param_2,param_3);
  return;
}



/* c0280e50 FUN_c0280e50 */

/* Boundary evidence: original MIPS .pdata c0280e50..c0280e6b. Semantic name remains unreviewed. */

void FUN_c0280e50(int param_1,int *param_2,int *param_3,int *param_4)

{
  FUN_c0297b84(*(int **)(param_1 + 8),param_2,param_3,param_4);
  return;
}



/* c0280e6c FUN_c0280e6c */

/* Boundary evidence: original MIPS .pdata c0280e6c..c0280fdb. Semantic name remains unreviewed. */

int FUN_c0280e6c(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint local_18;
  uint uStack_14;
  
  *param_3 = 0;
  iVar1 = (uint)*(ushort *)(param_2 + 0x12) * 4;
  param_3[1] = iVar1;
  iVar1 = (uint)*(ushort *)(param_2 + 0x14) * 8 + iVar1;
  param_3[2] = iVar1;
  iVar1 = (uint)*(ushort *)(param_2 + 0x16) * 8 + iVar1;
  param_3[3] = iVar1;
  iVar1 = (*(uint *)(param_1 + 0x38) >> 1) * 4 + iVar1;
  iVar3 = iVar1 + 0x188;
  param_3[4] = iVar1;
  param_3[0x15] = iVar3;
  iVar3 = (uint)*(ushort *)(param_2 + 0x12) * 4 + iVar3;
  param_3[0x16] = iVar3;
  iVar3 = (uint)*(ushort *)(param_2 + 0x14) * 8 + iVar3;
  param_3[0x17] = iVar3;
  iVar3 = (uint)*(ushort *)(param_2 + 0x16) * 8 + iVar3;
  param_3[0x18] = iVar3;
  iVar3 = (*(uint *)(param_1 + 0x38) >> 1) * 4 + iVar3;
  iVar1 = iVar3 + 0x188;
  param_3[0x19] = iVar3;
  param_3[5] = iVar1;
  iVar1 = *(int *)(param_1 + 0x60) + iVar1;
  param_3[6] = iVar1;
  uVar2 = *(int *)(param_1 + 0x40) + iVar1 + 3U & 0xfffffffc;
  param_3[7] = uVar2;
  param_3[0x1a] = uVar2 + 0x38;
  param_3[8] = uVar2 + 0x70;
  FUN_c027d924((uint)*(ushort *)(param_2 + 0x10),1,(uint *)(param_3 + 9),&local_18,&uStack_14);
  uVar2 = param_3[8] + local_18 + 3 & 0xfffffffc;
  param_3[0x1b] = uVar2;
  if ((uVar2 - param_3[3]) + local_18 < 0x400) {
    local_18 = (param_3[3] - uVar2) + 0x400;
  }
  return (uVar2 - *param_3) + local_18;
}



/* c0280fdc FUN_c0280fdc */

/* Boundary evidence: original MIPS .pdata c0280fdc..c02811b7. Semantic name remains unreviewed. */

void FUN_c0280fdc(int param_1,int *param_2,int *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint local_20 [2];
  
  param_2[2] = 0;
  uVar3 = (uint)*(ushort *)(param_1 + 0x1e);
  if (uVar3 < 2) {
    uVar3 = 1;
  }
  iVar10 = uVar3 * 0x38 + 0x38;
  param_2[1] = iVar10;
  uVar7 = (uint)*(ushort *)(param_1 + 8);
  uVar5 = (uint)*(ushort *)(param_1 + 0xc);
  uVar3 = uVar7;
  if (uVar7 <= uVar5) {
    uVar3 = uVar5;
  }
  if (uVar3 < 2) {
    uVar5 = 1;
  }
  else if (uVar7 > uVar5) {
    uVar5 = uVar7;
  }
  uVar1 = *(ushort *)(param_1 + 6);
  uVar6 = *(ushort *)(param_1 + 10);
  uVar2 = uVar1;
  if (uVar1 <= uVar6) {
    uVar2 = uVar6;
  }
  if (uVar2 < 2) {
    uVar6 = 1;
  }
  else if (uVar1 > uVar6) {
    uVar6 = uVar1;
  }
  puVar9 = (uint *)(param_2 + 0x11);
  FUN_c027d924((uint)(ushort)(uVar6 + 8),uVar5,(uint *)(param_2 + 5),local_20,puVar9);
  uVar3 = *puVar9;
  uVar7 = local_20[0] + iVar10 + 3 & 0xfffffffc;
  *puVar9 = uVar3 + param_2[1];
  param_2[3] = uVar7;
  uVar5 = (uint)*(ushort *)(param_1 + 0x1e);
  if (uVar5 < 2) {
    uVar5 = 1;
  }
  uVar4 = (uint)*(ushort *)(param_1 + 0x1c);
  if (uVar4 < 4) {
    uVar4 = 3;
  }
  iVar8 = uVar4 + uVar5 + 1;
  iVar10 = iVar8 * 4 + uVar7;
  param_2[4] = iVar10;
  iVar10 = iVar8 * 0xb8 + iVar10;
  *param_2 = iVar10;
  uVar5 = (uint)*(ushort *)(param_1 + 0x18);
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  *param_3 = (uVar5 * 4 + iVar10) - (uVar3 + param_2[1]);
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  return;
}



/* c02811b8 FUN_c02811b8 */

void FUN_c02811b8(int param_1,undefined1 *param_2,int *param_3)

{
  if (*(int *)(param_2 + 8) == 0) {
    *param_3 = *(int *)(param_2 + 4);
    *param_2 = 0;
    param_2[1] = 0;
    *(undefined4 *)
     ((((int)param_2 - *(int *)(param_1 + 0x10)) / 0xb8) * 4 + *(int *)(param_1 + 0xc)) = 1;
  }
  else {
    *param_3 = *(int *)(param_2 + 8);
    *(undefined4 *)(param_2 + 8) = 0;
  }
  return;
}



/* c0281210 FUN_c0281210 */

/* Boundary evidence: original MIPS .pdata c0281210..c028147b. Semantic name remains unreviewed. */

undefined4 FUN_c0281210(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int in_stack_ffffffa0;
  int in_stack_ffffffa4;
  undefined4 in_stack_ffffffa8;
  int in_stack_ffffffac;
  int in_stack_ffffffb0;
  int local_30;
  int local_2c;
  
  iVar3 = *(int *)(param_2 + 0xc);
  piVar2 = *(int **)(param_2 + 0x8c);
  piVar4 = *(int **)(iVar3 + 0x8c);
  FUN_c027e9ac(param_2);
  if ((*(int *)(param_2 + 0xb4) == 0) && (*(int *)(*(int *)(param_2 + 0xc) + 0xb4) != 0)) {
    FUN_c028b9d8(param_1,'\x01');
    FUN_c0295ff4(piVar2,param_1);
    FUN_c02961d8(piVar2,param_1);
    *(undefined4 *)(param_2 + 0xb4) = 1;
  }
  FUN_c027e8e4((int *)(iVar3 + 0x90));
  if (*(int *)(param_2 + 0x34) == 1) {
    iVar1 = *(int *)(param_2 + 0xc);
    if (*(int *)(iVar1 + 0xb4) == 0) {
      in_stack_ffffffa0 = *(int *)(iVar1 + 0xa4);
      in_stack_ffffffa4 = *(int *)(iVar1 + 0xa8);
      in_stack_ffffffa8 = *(undefined4 *)(iVar1 + 0xac);
      in_stack_ffffffac = *(int *)(iVar1 + 0xb0);
      in_stack_ffffffb0 = CONCAT22((short)((uint)in_stack_ffffffb0 >> 0x10),param_3);
      FUN_c0298344(param_1,*(int *)(iVar1 + 0x90),*(int *)(iVar1 + 0x94),
                   *(undefined4 *)(iVar1 + 0x98),*(int *)(iVar1 + 0x9c),*(int *)(iVar1 + 0xa0));
    }
    memcpy(&stack0xffffffa0,(void *)(param_2 + 0x44),0x24);
    FUN_c0296d24(param_1,(int)*(short *)(param_2 + 0x3c),(int)*(short *)(param_2 + 0x3e),
                 *(int *)(param_2 + 0x38),*(int *)(param_2 + 0xb4),*(int *)(param_2 + 0x70),
                 in_stack_ffffffa0,in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,
                 in_stack_ffffffb0);
  }
  else {
    if ((((short)piVar4[10] == 0) ||
        (*(short *)((short)piVar4[10] * 2 + piVar4[8] + -2) + 8 <
         (int)(uint)*(ushort *)(param_2 + 0x40))) ||
       (*(short *)((short)piVar2[10] * 2 + piVar2[8] + -2) + 8 <
        (int)(uint)*(ushort *)(param_2 + 0x42))) {
      return 0x1401;
    }
    FUN_c0296f24(piVar4,(uint)*(ushort *)(param_2 + 0x40),piVar2,(uint)*(ushort *)(param_2 + 0x42),
                 &local_2c,&local_30);
  }
  FUN_c0296c3c(piVar2,local_2c,local_30);
  if (*(int *)(param_2 + 0x6c) != 0) {
    *(undefined4 *)(iVar3 + 0x68) = 1;
    FUN_c0296fe8(piVar2,(undefined4 *)(iVar3 + 0x74),(undefined4 *)(iVar3 + 0x7c));
  }
  if (*(ushort *)(iVar3 + 0x84) == 0xffff) {
    *(undefined2 *)(iVar3 + 0x84) = *(undefined2 *)(param_2 + 0x84);
  }
  else {
    *(ushort *)(iVar3 + 0x84) = (*(ushort *)(param_2 + 0x84) & 3 | 4) & *(ushort *)(iVar3 + 0x84);
  }
  FUN_c02972a4((int)piVar2,(int)piVar4);
  *(undefined2 *)(piVar2 + 10) = 0;
  return 0;
}



/* c028147c FUN_c028147c */

/* Boundary evidence: original MIPS .pdata c028147c..c02815d3. Semantic name remains unreviewed. */

undefined4
FUN_c028147c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,short param_9)

{
  bool bVar1;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  FUN_c0280c10(param_3,param_4,param_5,param_6,param_7,param_8,&local_18,&local_20);
  if (param_9 == 0) {
    if (param_2 < local_14) {
      return 0;
    }
    if (local_1c < param_2) {
      return 0;
    }
    bVar1 = param_1 < local_18;
  }
  else if (param_9 == 1) {
    if (param_2 < local_14) {
      return 0;
    }
    if (local_1c < param_2) {
      return 0;
    }
    bVar1 = local_20 < param_1;
  }
  else if (param_9 == 2) {
    if (param_1 < local_18) {
      return 0;
    }
    if (local_20 < param_1) {
      return 0;
    }
    bVar1 = param_2 < local_14;
  }
  else {
    if (param_9 != 3) {
      return 1;
    }
    if (param_1 < local_18) {
      return 0;
    }
    if (local_20 < param_1) {
      return 0;
    }
    bVar1 = local_1c < param_2;
  }
  if (bVar1) {
    return 0;
  }
  return 1;
}



/* c02815d4 FUN_c02815d4 */

/* Boundary evidence: original MIPS .pdata c02815d4..c028171b. Semantic name remains unreviewed. */

undefined4
FUN_c02815d4(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,short param_7)

{
  bool bVar1;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  FUN_c0280cd0(param_3,param_4,param_5,param_6,&local_18,&local_20);
  if (param_7 == 0) {
    if (param_2 < local_14) {
      return 0;
    }
    if (local_1c < param_2) {
      return 0;
    }
    bVar1 = param_1 < local_18;
  }
  else if (param_7 == 1) {
    if (param_2 < local_14) {
      return 0;
    }
    if (local_1c < param_2) {
      return 0;
    }
    bVar1 = local_20 < param_1;
  }
  else if (param_7 == 2) {
    if (param_1 < local_18) {
      return 0;
    }
    if (local_20 < param_1) {
      return 0;
    }
    bVar1 = param_2 < local_14;
  }
  else {
    if (param_7 != 3) {
      return 1;
    }
    if (param_1 < local_18) {
      return 0;
    }
    if (local_20 < param_1) {
      return 0;
    }
    bVar1 = local_1c < param_2;
  }
  if (bVar1) {
    return 0;
  }
  return 1;
}



/* c028171c FUN_c028171c */

/* Boundary evidence: original MIPS .pdata c028171c..c0281d1b. Semantic name remains unreviewed. */

bool FUN_c028171c(int param_1,short param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar7;
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
  short sVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int local_68;
  int local_64;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  iVar22 = *(int *)(param_6 + 0x1c);
  iVar17 = (int)*(short *)(iVar22 + param_1 * 2);
  sVar18 = 0;
  iVar16 = ((*(short *)(*(int *)(param_6 + 0x20) + param_1 * 2) - iVar17) + 1) * 0x10000 >> 0x10;
  FUN_c0280b5c((int)param_2,param_4,param_5,&local_40,&local_38);
  iVar3 = (param_3 - iVar17) * 0x10000 >> 0x10;
  iVar10 = iVar16 + iVar3 + -1;
  local_64 = 0;
  if (iVar16 == 0) {
    trap(0x1c00);
  }
  if ((iVar16 == -1) && (iVar10 == -0x80000000)) {
    trap(0x1800);
  }
  iVar11 = ((short)(iVar10 % iVar16) + iVar17) * 4;
  iVar13 = (iVar3 + iVar17) * 4;
  iVar10 = *(int *)(iVar13 + *(int *)(param_6 + 0x10));
  iVar13 = *(int *)(*(int *)(param_6 + 0x14) + iVar13);
  iVar5 = iVar10 - *(int *)(*(int *)(param_6 + 0x10) + iVar11);
  iVar15 = 0;
  iVar11 = iVar13 - *(int *)(*(int *)(param_6 + 0x14) + iVar11);
  if (0 < iVar16) {
    do {
      if (sVar18 != 0) break;
      iVar23 = (iVar3 + 1) % iVar16;
      if (iVar16 == 0) {
        trap(0x1c00);
      }
      if ((iVar16 == -1) && (iVar3 + 1 == -0x80000000)) {
        trap(0x1800);
      }
      iVar3 = (iVar23 + iVar17) * 4;
      iVar14 = *(int *)(iVar3 + *(int *)(param_6 + 0x10));
      iVar3 = *(int *)(iVar3 + *(int *)(param_6 + 0x14));
      if ((iVar10 != iVar14) || (iVar12 = iVar11, iVar13 != iVar3)) {
        iVar12 = iVar3 - iVar13;
        iVar9 = iVar12 * iVar5;
        iVar5 = iVar14 - iVar10;
        iVar9 = iVar9 - iVar5 * iVar11;
        iVar10 = iVar14;
        iVar13 = iVar3;
        if (iVar9 < 0) {
          sVar18 = -1;
        }
        else if (iVar9 < 1) {
          sVar18 = 0;
        }
        else {
          sVar18 = 1;
        }
      }
      iVar15 = (iVar15 + 1) * 0x10000 >> 0x10;
      iVar3 = (int)(short)iVar23;
      iVar11 = iVar12;
    } while (iVar15 < iVar16);
  }
  if ((iVar15 < iVar16) && (0 < sVar18)) {
    local_64 = 2;
  }
  sVar18 = *(short *)(param_6 + 0x28);
  uVar21 = 0;
  if (0 < sVar18) {
    local_68 = 0;
    iVar3 = local_3c;
    iVar10 = local_40;
    iVar16 = local_3c;
    iVar17 = local_40;
    do {
      iVar11 = iVar16;
      iVar13 = iVar17;
      if (local_68 != param_1) {
        sVar2 = *(short *)(local_68 * 2 + iVar22);
        iVar15 = (int)sVar2;
        iVar5 = (int)*(short *)(local_68 * 2 + *(int *)(param_6 + 0x20));
        if (2 < ((iVar5 - iVar15) + 1) * 0x10000 >> 0x10) {
          iVar4 = *(int *)(param_6 + 0x10);
          iVar9 = *(int *)(param_6 + 0x14);
          iVar6 = *(int *)(param_6 + 0x18);
          iVar23 = *(int *)(iVar15 * 4 + iVar4) * 2;
          uVar8 = (uint)*(byte *)(iVar6 + iVar15);
          iVar14 = *(int *)(iVar15 * 4 + iVar9) * 2;
          iVar12 = iVar15;
          if (uVar8 == 0) {
            iVar17 = *(int *)(iVar5 * 4 + iVar4) * 2;
            iVar16 = *(int *)(iVar5 * 4 + iVar9) * 2;
            if (*(char *)(iVar6 + iVar5) == '\0') {
              iVar17 = iVar17 + iVar23 >> 1;
              iVar16 = iVar16 + iVar14 >> 1;
            }
          }
          do {
            sVar7 = sVar2;
            if (iVar12 != iVar5) {
              sVar7 = (short)iVar12 + 1;
            }
            iVar12 = (int)sVar7;
            bVar1 = *(byte *)(iVar6 + iVar12);
            iVar19 = *(int *)(iVar12 * 4 + iVar4) * 2;
            iVar20 = *(int *)(iVar12 * 4 + iVar9) * 2;
            uVar8 = uVar8 << 1 | (uint)bVar1;
            if (uVar8 == 0) {
              iVar13 = iVar19 + iVar23 >> 1;
              iVar11 = iVar20 + iVar14 >> 1;
              if (((iVar17 != iVar13) || (iVar16 != iVar11)) &&
                 (iVar3 = FUN_c028147c(iVar10,iVar3,iVar17,iVar16,iVar23,iVar14,iVar13,iVar11,
                                       param_2), iVar3 != 0)) {
                iVar3 = FUN_c027fea4(local_40,local_3c,local_38,local_34,iVar17,iVar16,iVar23,iVar14
                                     ,iVar13,iVar11);
                uVar21 = iVar3 + uVar21;
              }
            }
            else {
              iVar11 = iVar16;
              iVar13 = iVar17;
              if (uVar8 == 1) {
                if (((iVar17 != iVar19) || (iVar16 != iVar20)) &&
                   (iVar3 = FUN_c028147c(iVar10,iVar3,iVar17,iVar16,iVar23,iVar14,iVar19,iVar20,
                                         param_2), iVar3 != 0)) {
                  iVar3 = FUN_c027fea4(local_40,local_3c,local_38,local_34,iVar17,iVar16,iVar23,
                                       iVar14,iVar19,iVar20);
                  goto LAB_c0281b24;
                }
              }
              else {
                iVar11 = iVar14;
                iVar13 = iVar23;
                if (((uVar8 != 2) && (iVar11 = iVar16, iVar13 = iVar17, uVar8 == 3)) &&
                   (((iVar23 != iVar19 || (iVar14 != iVar20)) &&
                    (iVar3 = FUN_c02815d4(iVar10,iVar3,iVar23,iVar14,iVar19,iVar20,param_2),
                    iVar3 != 0)))) {
                  iVar3 = FUN_c027fb38(local_40,local_3c,local_38,local_34,iVar23,iVar14,iVar19,
                                       iVar20);
LAB_c0281b24:
                  uVar21 = iVar3 + uVar21;
                  iVar11 = iVar16;
                  iVar13 = iVar17;
                }
              }
            }
            uVar8 = (uint)bVar1;
            iVar3 = local_3c;
            iVar10 = local_40;
            iVar23 = iVar19;
            iVar14 = iVar20;
            iVar16 = iVar11;
            iVar17 = iVar13;
          } while (iVar12 != iVar15);
        }
      }
      local_68 = (local_68 + 1) * 0x10000 >> 0x10;
      iVar16 = iVar11;
      iVar17 = iVar13;
    } while (local_68 < sVar18);
  }
  iVar3 = 2;
  if ((uVar21 & 1) != 0) {
    iVar3 = 0;
  }
  return iVar3 == local_64;
}



/* c0281d1c FUN_c0281d1c */

/* Boundary evidence: original MIPS .pdata c0281d1c..c0282803. Semantic name remains unreviewed. */

void FUN_c0281d1c(int param_1)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  byte *pbVar10;
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
  short local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60 [10];
  short local_38 [4];
  uint local_30;
  
  local_30 = DAT_c029ac78;
  local_6c = 0;
  if (0 < *(short *)(param_1 + 0x28)) {
    do {
      *(undefined1 *)(*(int *)(param_1 + 0x2c) + local_6c) = 0;
      sVar1 = *(short *)(*(int *)(param_1 + 0x1c) + local_6c * 2);
      iVar13 = (int)sVar1;
      sVar2 = *(short *)(local_6c * 2 + *(int *)(param_1 + 0x20));
      iVar11 = (int)sVar2;
      local_60[8] = ((iVar11 - iVar13) + 1) * 0x10000 >> 0x10;
      if (2 < local_60[8]) {
        iVar12 = 0;
        do {
          local_38[iVar12] = -1;
          iVar12 = (iVar12 + 1) * 0x10000 >> 0x10;
        } while (iVar12 < 4);
        iVar20 = (int)local_38[2];
        iVar12 = (int)local_38[1];
        local_68 = 0x7fffffff;
        local_64 = 0x7fffffff;
        local_70 = -0x80000000;
        local_74 = -0x80000000;
        sVar6 = local_38[0];
        local_78 = local_38[3];
        if (0 < local_60[8]) {
          iVar15 = (int)local_38[0];
          iVar4 = *(int *)(param_1 + 0x10);
          iVar5 = *(int *)(param_1 + 0x14);
          iVar17 = 0;
          do {
            iVar18 = (iVar17 + iVar13) * 4;
            iVar14 = *(int *)(iVar4 + iVar18);
            if ((iVar14 < local_64) ||
               ((iVar14 == local_64 &&
                ((iVar9 = *(int *)(param_1 + 0x18), *(char *)(iVar9 + iVar15) == '\0' ||
                 ((((iVar14 == local_64 && (*(char *)(iVar9 + iVar15) != '\0')) &&
                   (*(char *)(iVar9 + iVar17 + iVar13) != '\0')) &&
                  (*(int *)(*(int *)(param_1 + 0x14) + iVar18) <
                   *(int *)(iVar15 * 4 + *(int *)(param_1 + 0x14)))))))))) {
              iVar16 = (iVar17 + iVar13) * 0x10000;
              iVar15 = iVar16 >> 0x10;
              iVar9 = iVar15 * 4;
              local_64 = *(int *)(iVar9 + iVar4);
              local_38[0] = (short)((uint)iVar16 >> 0x10);
              if (*(char *)(iVar15 + *(int *)(param_1 + 0x18)) == '\0') {
                sVar6 = sVar2;
                if (iVar15 != iVar13) {
                  sVar6 = local_38[0] + -1;
                }
                sVar8 = sVar1;
                if (iVar15 != iVar11) {
                  sVar8 = local_38[0] + 1;
                }
                iVar5 = sVar8 * 4;
                iVar19 = *(int *)(param_1 + 0x10);
                iVar4 = *(int *)(param_1 + 0x14);
                iVar16 = sVar6 * 4;
                FUN_c02802c0(1,*(int *)(iVar16 + iVar19),*(int *)(iVar16 + iVar4),
                             *(byte *)((int)sVar6 + *(int *)(param_1 + 0x18)) & 1,
                             *(int *)(iVar19 + iVar9),*(int *)(iVar4 + iVar9),
                             *(int *)(iVar19 + iVar5),*(int *)(iVar4 + iVar5),
                             *(byte *)(*(int *)(param_1 + 0x18) + (int)sVar8) & 1,local_60,
                             local_60 + 1);
                iVar4 = *(int *)(param_1 + 0x10);
                iVar5 = *(int *)(param_1 + 0x14);
              }
              else {
                local_60[0] = local_64 << 1;
                local_60[1] = *(int *)(iVar5 + iVar9) << 1;
              }
            }
            if ((local_74 < iVar14) ||
               ((iVar14 == local_74 &&
                ((iVar9 = *(int *)(param_1 + 0x18), *(char *)(iVar9 + iVar12) == '\0' ||
                 (((iVar14 == local_74 && (*(char *)(iVar12 + iVar9) != '\0')) &&
                  ((*(char *)(iVar9 + iVar17 + iVar13) != '\0' &&
                   (*(int *)(iVar12 * 4 + *(int *)(param_1 + 0x14)) <
                    *(int *)(*(int *)(param_1 + 0x14) + iVar18))))))))))) {
              iVar9 = (iVar17 + iVar13) * 0x10000;
              iVar12 = iVar9 >> 0x10;
              iVar14 = iVar12 * 4;
              local_74 = *(int *)(iVar14 + iVar4);
              if (*(char *)(iVar12 + *(int *)(param_1 + 0x18)) == '\0') {
                sVar6 = (short)((uint)iVar9 >> 0x10);
                sVar8 = sVar2;
                if (iVar12 != iVar13) {
                  sVar8 = sVar6 + -1;
                }
                sVar7 = sVar1;
                if (iVar12 != iVar11) {
                  sVar7 = sVar6 + 1;
                }
                iVar5 = sVar7 * 4;
                iVar16 = *(int *)(param_1 + 0x10);
                iVar4 = *(int *)(param_1 + 0x14);
                iVar9 = sVar8 * 4;
                FUN_c02802c0(0,*(int *)(iVar16 + iVar9),*(int *)(iVar4 + iVar9),
                             *(byte *)(*(int *)(param_1 + 0x18) + (int)sVar8) & 1,
                             *(int *)(iVar16 + iVar14),*(int *)(iVar4 + iVar14),
                             *(int *)(iVar16 + iVar5),*(int *)(iVar4 + iVar5),
                             *(byte *)(*(int *)(param_1 + 0x18) + (int)sVar7) & 1,local_60 + 2,
                             local_60 + 3);
              }
              else {
                local_60[2] = local_74 << 1;
                local_60[3] = *(int *)(iVar14 + iVar5) << 1;
              }
            }
            iVar4 = *(int *)(*(int *)(param_1 + 0x14) + iVar18);
            if ((iVar4 < local_68) ||
               ((iVar4 == local_68 &&
                ((iVar5 = *(int *)(param_1 + 0x18), *(char *)(iVar5 + iVar20) == '\0' ||
                 (((iVar4 == local_68 && (*(char *)(iVar20 + iVar5) != '\0')) &&
                  ((*(char *)(iVar5 + iVar17 + iVar13) != '\0' &&
                   (*(int *)(iVar20 * 4 + *(int *)(param_1 + 0x10)) <
                    *(int *)(*(int *)(param_1 + 0x10) + iVar18))))))))))) {
              iVar14 = (iVar17 + iVar13) * 0x10000;
              iVar20 = iVar14 >> 0x10;
              iVar5 = iVar20 * 4;
              local_68 = *(int *)(iVar5 + *(int *)(param_1 + 0x14));
              if (*(char *)(iVar20 + *(int *)(param_1 + 0x18)) == '\0') {
                sVar6 = (short)((uint)iVar14 >> 0x10);
                sVar8 = sVar2;
                if (iVar20 != iVar13) {
                  sVar8 = sVar6 + -1;
                }
                sVar7 = sVar1;
                if (iVar20 != iVar11) {
                  sVar7 = sVar6 + 1;
                }
                iVar9 = sVar7 * 4;
                iVar19 = *(int *)(param_1 + 0x10);
                iVar14 = *(int *)(param_1 + 0x14);
                iVar16 = sVar8 * 4;
                FUN_c028070c(1,*(int *)(iVar19 + iVar16),*(int *)(iVar14 + iVar16),
                             *(byte *)(*(int *)(param_1 + 0x18) + (int)sVar8) & 1,
                             *(int *)(iVar19 + iVar5),*(int *)(iVar14 + iVar5),
                             *(int *)(iVar19 + iVar9),*(int *)(iVar14 + iVar9),
                             *(byte *)(*(int *)(param_1 + 0x18) + (int)sVar7) & 1,local_60 + 4,
                             local_60 + 5);
                goto LAB_c02822e4;
              }
              iVar14 = *(int *)(param_1 + 0x10);
              local_60[4] = *(int *)(iVar5 + iVar14) << 1;
              local_60[5] = local_68 << 1;
            }
            else {
LAB_c02822e4:
              iVar14 = *(int *)(param_1 + 0x10);
            }
            if ((local_70 < iVar4) ||
               ((iVar5 = (int)local_78, iVar4 == local_70 &&
                ((iVar9 = *(int *)(param_1 + 0x18), *(char *)(iVar9 + iVar5) == '\0' ||
                 ((((iVar4 == local_70 && (*(char *)(iVar5 + iVar9) != '\0')) &&
                   (*(char *)(iVar9 + iVar17 + iVar13) != '\0')) &&
                  (*(int *)(*(int *)(param_1 + 0x10) + iVar18) <
                   *(int *)(iVar5 * 4 + *(int *)(param_1 + 0x10)))))))))) {
              iVar4 = (iVar17 + iVar13) * 0x10000;
              iVar18 = iVar4 >> 0x10;
              local_78 = (short)((uint)iVar4 >> 0x10);
              iVar5 = *(int *)(param_1 + 0x14);
              iVar4 = iVar18 * 4;
              local_70 = *(int *)(iVar4 + iVar5);
              local_38[3] = local_78;
              if (*(char *)(iVar18 + *(int *)(param_1 + 0x18)) == '\0') {
                sVar6 = sVar2;
                if (iVar18 != iVar13) {
                  sVar6 = local_78 + -1;
                }
                sVar8 = sVar1;
                if (iVar18 != iVar11) {
                  sVar8 = local_78 + 1;
                }
                iVar14 = sVar8 * 4;
                iVar9 = *(int *)(param_1 + 0x10);
                iVar5 = *(int *)(param_1 + 0x14);
                iVar18 = sVar6 * 4;
                FUN_c028070c(0,*(int *)(iVar9 + iVar18),*(int *)(iVar5 + iVar18),
                             *(byte *)(*(int *)(param_1 + 0x18) + (int)sVar6) & 1,
                             *(int *)(iVar9 + iVar4),*(int *)(iVar5 + iVar4),
                             *(int *)(iVar9 + iVar14),*(int *)(iVar5 + iVar14),
                             *(byte *)(*(int *)(param_1 + 0x18) + (int)sVar8) & 1,local_60 + 6,
                             local_60 + 7);
                goto LAB_c0282478;
              }
              local_60[6] = *(int *)(iVar4 + iVar14) << 1;
              local_60[7] = local_70 << 1;
            }
            else {
LAB_c0282478:
              iVar5 = *(int *)(param_1 + 0x14);
            }
            iVar17 = (iVar17 + 1) * 0x10000 >> 0x10;
            iVar4 = *(int *)(param_1 + 0x10);
          } while (iVar17 < local_60[8]);
          local_38[1] = (short)iVar12;
          local_38[2] = (short)iVar20;
          sVar6 = (short)iVar15;
        }
        iVar12 = iVar12 * 4;
        iVar11 = sVar6 * 4;
        if (*(int *)(*(int *)(param_1 + 0x10) + iVar12) -
            *(int *)(*(int *)(param_1 + 0x10) + iVar11) < 0) {
          iVar13 = *(int *)(*(int *)(param_1 + 0x10) + iVar11) -
                   *(int *)(*(int *)(param_1 + 0x10) + iVar12);
        }
        else {
          iVar13 = *(int *)(*(int *)(param_1 + 0x10) + iVar12) -
                   *(int *)(*(int *)(param_1 + 0x10) + iVar11);
        }
        iVar4 = *(int *)(param_1 + 0x14);
        if (*(int *)(iVar4 + iVar12) - *(int *)(iVar4 + iVar11) < 0) {
          iVar12 = *(int *)(iVar4 + iVar11) - *(int *)(iVar4 + iVar12);
        }
        else {
          iVar12 = *(int *)(iVar4 + iVar12) - *(int *)(iVar4 + iVar11);
        }
        iVar20 = iVar20 * 4;
        if (*(int *)(*(int *)(param_1 + 0x10) + iVar20) -
            *(int *)(*(int *)(param_1 + 0x10) + iVar11) < 0) {
          iVar4 = *(int *)(*(int *)(param_1 + 0x10) + iVar11) -
                  *(int *)(*(int *)(param_1 + 0x10) + iVar20);
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 0x10) + iVar20) -
                  *(int *)(*(int *)(param_1 + 0x10) + iVar11);
        }
        iVar5 = *(int *)(param_1 + 0x14);
        if (*(int *)(*(int *)(param_1 + 0x14) + iVar20) -
            *(int *)(*(int *)(param_1 + 0x14) + iVar11) < 0) {
          iVar20 = *(int *)(iVar5 + iVar11) - *(int *)(iVar5 + iVar20);
        }
        else {
          iVar20 = *(int *)(iVar20 + iVar5) - *(int *)(iVar11 + iVar5);
        }
        iVar5 = local_78 * 4;
        if (*(int *)(iVar5 + *(int *)(param_1 + 0x10)) - *(int *)(iVar11 + *(int *)(param_1 + 0x10))
            < 0) {
          iVar17 = *(int *)(iVar11 + *(int *)(param_1 + 0x10)) -
                   *(int *)(iVar5 + *(int *)(param_1 + 0x10));
        }
        else {
          iVar17 = *(int *)(iVar5 + *(int *)(param_1 + 0x10)) -
                   *(int *)(iVar11 + *(int *)(param_1 + 0x10));
        }
        iVar15 = *(int *)(param_1 + 0x14);
        if (*(int *)(iVar5 + *(int *)(param_1 + 0x14)) - *(int *)(iVar11 + *(int *)(param_1 + 0x14))
            < 0) {
          iVar11 = *(int *)(iVar11 + iVar15) - *(int *)(iVar5 + iVar15);
        }
        else {
          iVar11 = *(int *)(iVar5 + iVar15) - *(int *)(iVar11 + iVar15);
        }
        if (iVar11 + iVar17 < iVar20 + iVar4) {
          iVar5 = 2;
          if (iVar12 + iVar13 < iVar11 + iVar17) {
            iVar11 = 3;
          }
          else {
LAB_c02826ec:
            iVar11 = 1;
          }
        }
        else {
          iVar5 = 3;
          iVar11 = 2;
          if (iVar20 + iVar4 <= iVar12 + iVar13) goto LAB_c02826ec;
        }
        bVar3 = FUN_c028171c(local_6c,0,(int)sVar6,local_60[0],local_60[1],param_1);
        iVar13 = CONCAT31(extraout_var,bVar3);
        bVar3 = FUN_c028171c(local_6c,(short)iVar5,(int)local_38[iVar5],local_60[iVar5 * 2],
                             local_60[iVar5 * 2 + 1],param_1);
        if (iVar13 != CONCAT31(extraout_var_00,bVar3)) {
          bVar3 = FUN_c028171c(local_6c,(short)iVar11,(int)local_38[iVar11],local_60[iVar11 * 2],
                               local_60[iVar11 * 2 + 1],param_1);
          iVar13 = CONCAT31(extraout_var_01,bVar3);
        }
        if (iVar13 != 0) {
          pbVar10 = (byte *)(*(int *)(param_1 + 0x2c) + local_6c);
          *pbVar10 = *pbVar10 | 1;
        }
      }
      local_6c = local_6c + 1;
    } while (local_6c < *(short *)(param_1 + 0x28));
  }
  FUN_c029919c(local_30);
  return;
}



/* c0282804 FUN_c0282804 */

/* Boundary evidence: original MIPS .pdata c0282804..c0282e97. Semantic name remains unreviewed. */

int FUN_c0282804(undefined4 *param_1,int param_2,short *param_3,uint param_4,undefined4 *param_5,
                int param_6,int param_7,void *param_8,int param_9,int param_10,int *param_11,
                uint *param_12,uint *param_13,int param_14)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  byte *pbVar6;
  ushort uVar7;
  uint uVar8;
  ushort uVar9;
  uint *puVar10;
  int in_stack_ffffff7c;
  int in_stack_ffffff80;
  undefined4 in_stack_ffffff84;
  int in_stack_ffffff88;
  int in_stack_ffffff8c;
  ushort local_48;
  undefined2 local_46;
  int local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  undefined1 *local_30;
  int local_2c;
  
  *param_11 = 0;
  if (*(int *)(param_6 + 0x1c) == 3) {
    if (*(int *)(param_6 + 0xc) == 0) {
      memcpy((void *)(param_6 + 0x90),param_3 + 2,0x24);
    }
    else {
      FUN_c029719c(*(int **)(param_6 + 0x8c),*(int **)(*(int *)(param_6 + 0xc) + 0x8c));
    }
    iVar2 = FUN_c027a700(param_1,(uint)*(ushort *)(param_6 + 0x20),(int *)(param_6 + 0x10),&local_34
                         ,param_11,(short *)(*(int *)(param_6 + 0x8c) + 0x28),
                         (short *)(param_6 + 0x22));
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_c027d6f0(param_1,(uint)*(ushort *)(param_6 + 0x20),(undefined2 *)(param_6 + 0x2a),
                         (short *)(param_6 + 0x2c),(undefined2 *)(param_6 + 0x2e),
                         (short *)(param_6 + 0x30));
    if (iVar2 != 0) {
      return iVar2;
    }
    if (local_34 == 0) {
      *(undefined4 *)(param_6 + 0x1c) = 0;
    }
    else {
      *(undefined4 *)(param_6 + 0x1c) = 1;
    }
  }
  iVar2 = *(int *)(param_6 + 0x1c);
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_6 + 0x8c);
    iVar2 = FUN_c027aa10(*(byte **)(iVar2 + 0x18),*(int **)(iVar2 + 0x14),*(int **)(iVar2 + 0x10),
                         param_6 + 0x10,param_2,*param_11,*(short *)(iVar2 + 0x28),
                         *(undefined2 **)(iVar2 + 0x1c),*(short **)(iVar2 + 0x20),
                         (ushort *)(param_6 + 0x86),(undefined4 *)(param_6 + 0x88),param_12,param_13
                        );
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((*(int *)(param_3 + 0x1e) == 0) && (param_14 == 0)) {
      iVar2 = 0;
      if (0 < *(short *)(*(int *)(param_6 + 0x8c) + 0x28)) {
        do {
          *(undefined1 *)(*(int *)(*(int *)(param_6 + 0x8c) + 0x2c) + iVar2) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(short *)(*(int *)(param_6 + 0x8c) + 0x28));
      }
    }
    else {
      FUN_c0281d1c(*(int *)(param_6 + 0x8c));
    }
    memcpy(&stack0xffffff7c,(void *)(param_6 + 0x90),0x24);
    iVar2 = FUN_c027e49c(param_5,param_8,*(int **)(param_6 + 0x8c),param_10,param_9,*param_3,
                         *(ushort *)(param_6 + 0x2a),*(ushort *)(param_6 + 0x2c),
                         *(short *)(param_6 + 0x2e),*(short *)(param_6 + 0x30),
                         *(int *)(param_6 + 0xb4),(int)param_12,(int)param_13,in_stack_ffffff84,
                         in_stack_ffffff88,in_stack_ffffff8c);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_c027e9f4((uint)local_48,*(uint *)(param_3 + 0x1c));
    uVar4 = 2;
    if (iVar2 != 0) {
      uVar4 = local_46;
    }
    *(undefined2 *)(param_6 + 0x84) = uVar4;
    iVar2 = FUN_c0274f80(*(uint *)(param_6 + 0x44),*(uint *)(param_6 + 0x54));
    iVar3 = FUN_c0274f80(*(uint *)(param_6 + 0x48),*(uint *)(param_6 + 0x50));
    if ((iVar2 - iVar3 < 0) && (uVar8 = 0, 0 < *(short *)(*(int *)(param_6 + 0x8c) + 0x28))) {
      do {
        pbVar6 = (byte *)(*(int *)(*(int *)(param_6 + 0x8c) + 0x2c) + uVar8);
        *pbVar6 = *pbVar6 ^ 1;
        uVar8 = uVar8 + 1 & 0xffff;
      } while ((int)uVar8 < (int)*(short *)(*(int *)(param_6 + 0x8c) + 0x28));
    }
    if ((*(int *)(param_6 + 0xc) != 0) &&
       (iVar2 = FUN_c0281210((int)param_5,param_6,*param_3), iVar2 != 0)) {
      return iVar2;
    }
    iVar2 = FUN_c027b19c((int)param_1,(undefined4 *)(param_6 + 0x10));
    if (iVar2 != 0) {
      return iVar2;
    }
    *(undefined4 *)(param_6 + 0x88) = 0;
    *(ushort *)(param_6 + 0x86) = 0;
  }
  else if (iVar2 == 2) {
    memcpy(&stack0xffffff7c,(void *)(param_6 + 0x90),0x24);
    iVar2 = FUN_c027e6d4(param_5,param_8,*(int **)(param_6 + 0x8c),param_10,param_9,*param_3,
                         *(ushort *)(param_6 + 0x2a),*(ushort *)(param_6 + 0x2c),
                         *(short *)(param_6 + 0x2e),*(short *)(param_6 + 0x30),
                         *(int *)(param_6 + 0xb4),in_stack_ffffff7c,in_stack_ffffff80,
                         in_stack_ffffff84,in_stack_ffffff88,in_stack_ffffff8c);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (*(int *)(param_6 + 0x68) != 0) {
      FUN_c0296f78(*(int **)(param_6 + 0x8c),(undefined4 *)(param_6 + 0x74),
                   (undefined4 *)(param_6 + 0x7c));
    }
    if (local_40 != 0) {
      iVar2 = FUN_c027e9f4((uint)local_48,*(uint *)(param_3 + 0x1c));
      if (iVar2 == 0) {
        *(undefined2 *)(param_6 + 0x84) = 2;
      }
      else {
        *(undefined2 *)(param_6 + 0x84) = local_46;
      }
    }
    if ((*(int *)(param_6 + 0xc) != 0) &&
       (iVar2 = FUN_c0281210((int)param_5,param_6,*param_3), iVar2 != 0)) {
      return iVar2;
    }
    iVar2 = FUN_c027b19c((int)param_1,(undefined4 *)(param_6 + 0x10));
    if (iVar2 != 0) {
      return iVar2;
    }
    *(undefined4 *)(param_6 + 0x88) = 0;
    *(undefined2 *)(param_6 + 0x86) = 0;
  }
  else if (iVar2 == 1) {
    uVar8 = 0;
    uVar9 = 0;
    local_38 = 0;
    local_3c = 0;
    *(undefined4 *)(param_6 + 0x1c) = 2;
    do {
      uVar5 = (uint)*(ushort *)(param_2 + 0x1e);
      if (uVar5 < 2) {
        uVar5 = 1;
      }
      if (uVar5 < *(ushort *)(param_6 + 0x32) + 1) {
        return 0x140b;
      }
      uVar7 = *(ushort *)(param_2 + 0x1c);
      uVar9 = uVar9 + 1;
      if (uVar7 < 4) {
        uVar7 = 3;
      }
      if (uVar7 < uVar9) {
        return 0x140b;
      }
      iVar2 = FUN_c027eac0(param_4,param_7,(int *)&local_30);
      puVar1 = local_30;
      if (iVar2 != 0) {
        return iVar2;
      }
      FUN_c027eb30(local_30,param_7,0,*(ushort *)(param_6 + 0x32) + 1 & 0xffff);
      FUN_c027e928(param_6,(int)puVar1);
      puVar10 = (uint *)(puVar1 + 0x44);
      iVar2 = FUN_c027adfc(param_6 + 0x10,(undefined4 *)(puVar1 + 0x34),(uint *)(puVar1 + 0x38),
                           (uint *)(puVar1 + 0x6c),(undefined4 *)(puVar1 + 0x70),&local_3c,
                           (undefined2 *)(puVar1 + 0x20),(short *)(puVar1 + 0x3c),
                           (short *)(puVar1 + 0x3e),(ushort *)(puVar1 + 0x40),
                           (ushort *)(puVar1 + 0x42),(int *)puVar10,&local_2c,&local_38);
      if (*(ushort *)(param_2 + 4) <= *(ushort *)(puVar1 + 0x20)) {
        return 0x1410;
      }
      if (local_2c != 0) {
        FUN_c02753cc(puVar10,(uint *)(puVar1 + 0x90));
        iVar3 = FUN_c027561c((int *)puVar10);
        if (iVar3 == 0) {
          *(undefined4 *)(puVar1 + 0xb4) = 0;
        }
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar8 = uVar8 | local_3c;
    } while (local_38 == 0);
    if ((uVar8 != 0) &&
       (iVar2 = FUN_c027b154(param_6 + 0x10,(undefined4 *)(param_6 + 0x88),
                             (ushort *)(param_6 + 0x86)), iVar2 != 0)) {
      return iVar2;
    }
  }
  return 0;
}



/* c0282e98 FUN_c0282e98 */

/* Boundary evidence: original MIPS .pdata c0282e98..c0283067. Semantic name remains unreviewed. */

int FUN_c0282e98(undefined4 *param_1,int param_2,short *param_3,undefined4 *param_4,int param_5,
                void *param_6,int param_7,int param_8,undefined2 *param_9,uint *param_10,
                undefined2 *param_11,int param_12)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint local_40;
  undefined1 *local_3c;
  uint local_38;
  uint local_34;
  short *local_30;
  undefined4 *local_2c;
  
  *param_10 = 0;
  uVar3 = (uint)*(ushort *)(param_2 + 0x1e);
  local_34 = 0;
  local_38 = 0;
  local_40 = 0;
  if (uVar3 < 2) {
    uVar3 = 1;
  }
  uVar4 = (uint)*(ushort *)(param_2 + 0x1c);
  if (uVar4 < 4) {
    uVar4 = 3;
  }
  uVar3 = uVar4 + uVar3 + 1;
  puVar5 = *(undefined4 **)(param_5 + 0xc);
  if (uVar3 != 0) {
    puVar6 = puVar5 + uVar3;
    do {
      *puVar5 = 1;
      puVar5 = puVar5 + 1;
    } while (puVar5 != puVar6);
  }
  local_30 = param_3;
  local_2c = param_1;
  iVar2 = FUN_c027eac0(uVar3,param_5,(int *)&local_3c);
  puVar1 = local_3c;
  if (iVar2 == 0) {
    FUN_c027eb30(local_3c,param_5,*(undefined2 *)(param_1 + 0x35),0);
    FUN_c028ba04((int)param_4);
    while (puVar1 != (undefined1 *)0x0) {
      iVar2 = FUN_c0282804(local_2c,param_2,local_30,uVar3,param_4,(int)puVar1,param_5,param_6,
                           param_7,param_8,(int *)&local_40,&local_34,&local_38,param_12);
      if (iVar2 != 0) {
        return iVar2;
      }
      *param_10 = *param_10 | local_40;
      *param_9 = *(undefined2 *)(puVar1 + 0x84);
      FUN_c02811b8(param_5,puVar1,(int *)&local_3c);
      *param_11 = *(undefined2 *)(puVar1 + 0x2a);
      puVar1 = local_3c;
    }
    iVar2 = 0;
  }
  return iVar2;
}



/* c0283068 FUN_c0283068 */

/* Boundary evidence: original MIPS .pdata c0283068..c02831d7. Semantic name remains unreviewed. */

int FUN_c0283068(undefined4 *param_1,int param_2,ushort *param_3,undefined4 *param_4,int param_5,
                void *param_6,int param_7,int param_8,undefined2 *param_9,uint *param_10,
                short *param_11,int param_12,int param_13)

{
  int iVar1;
  
  FUN_c0297058((int)param_6,*(short *)(param_2 + 0x10),1);
  iVar1 = FUN_c0282e98(param_1,param_2,(short *)param_3,param_4,param_5,param_6,param_7,param_8,
                       param_9,param_10,param_11,param_13);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x1e) != 0) {
      FUN_c027f1c8(param_5,(int)param_4,param_8,param_12,param_13);
      if (*param_11 != 0) {
        *param_11 = (short)((int)((uint)*param_3 * 2 + -1) / 100) + *param_11;
      }
    }
    if (((*(uint *)(param_3 + 0x1c) & 0x2000) != 0) || (param_4[0x61] != 0)) {
      FUN_c0297780((int)param_4,*(undefined4 **)(param_5 + 8),(uint *)(param_3 + 2));
    }
    FUN_c029781c(*(int **)(param_5 + 8),(int)(param_3 + 2),param_8,param_4[0x61],param_13);
  }
  return iVar1;
}



/* c02831d8 FUN_c02831d8 */

undefined4
FUN_c02831d8(int param_1,undefined2 param_2,int param_3,int param_4,undefined2 param_5,
            undefined2 param_6,short param_7)

{
  *(undefined2 *)(param_1 + 0x1e) = param_5;
  *(undefined2 *)(param_1 + 0x20) = param_6;
  *(short *)(param_1 + 0x26) = param_7;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined2 *)(param_1 + 0x1c) = 0;
  *(undefined2 *)(param_1 + 0x5c) = param_2;
  if (param_3 < 0) {
    param_3 = -param_3;
  }
  *(short *)(param_1 + 0x60) = (short)param_3;
  if (param_4 < 0) {
    param_4 = -param_4;
  }
  *(short *)(param_1 + 0x62) = (short)param_4;
  if ((param_7 == 1) || (param_7 == 3)) {
    *(short *)(param_1 + 0x60) = (short)param_4;
    *(short *)(param_1 + 0x62) = (short)param_3;
  }
  return 0;
}



/* c0283244 FUN_c0283244 */

/* Boundary evidence: original MIPS .pdata c0283244..c02833a3. Semantic name remains unreviewed. */

int FUN_c0283244(int *param_1,undefined4 *param_2,uint param_3,short param_4,undefined2 *param_5,
                undefined2 *param_6)

{
  int iVar1;
  int *piVar2;
  
  *param_6 = 0;
  if (*(ushort *)((int)param_1 + 0x26) < 4) {
    piVar2 = param_1 + 7;
    if (((short)*piVar2 == 0) &&
       (iVar1 = FUN_c027d754(param_2,(uint)*(ushort *)((int)param_1 + 0x1e),
                             (uint)*(ushort *)(param_1 + 8),param_4,
                             (undefined2 *)((int)param_1 + 0x5e),(undefined2 *)piVar2,
                             (ushort *)((int)param_1 + 0x22),(ushort *)(param_1 + 9),param_1),
       iVar1 != 0)) {
      return iVar1;
    }
    *param_5 = *(undefined2 *)((int)param_1 + 0x5e);
    if (((short)*piVar2 == 2) || ((short)*piVar2 == 3)) {
      iVar1 = FUN_c027b474(param_2,param_3,*param_1,param_1 + 0x15,(undefined2 *)(param_1 + 10),
                           (undefined2 *)((int)param_1 + 0x2a),(uint *)(param_1 + 1),
                           (ushort *)(param_1 + 0xb),(uint *)(param_1 + 2),param_1 + 3);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (param_1[0x15] != 0) {
        if ((short)*piVar2 == 2) {
          *param_6 = 1;
        }
        else {
          *param_6 = 2;
        }
        param_1[0x16] = 0;
      }
    }
  }
  return 0;
}



/* c02833a4 FUN_c02833a4 */

/* Boundary evidence: original MIPS .pdata c02833a4..c0283993. Semantic name remains unreviewed. */

void FUN_c02833a4(byte *param_1,uint param_2,int param_3,uint param_4,short param_5,short param_6)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  byte *pbVar14;
  byte bVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  byte *pbVar19;
  byte bVar20;
  byte *pbVar21;
  
  if (param_3 == 0) {
    return;
  }
  if (param_1 == (byte *)0x0) {
    return;
  }
  iVar4 = param_2 + 7;
  if (iVar4 < 0) {
    iVar4 = param_2 + 0xe;
  }
  iVar4 = iVar4 >> 3;
  iVar5 = (int)param_5;
  if (iVar5 < 0) {
    uVar11 = iVar5 + param_2;
    iVar8 = uVar11 + 7;
    if (iVar8 < 0) {
      iVar8 = uVar11 + 0xe;
    }
  }
  else {
    uVar11 = param_2 - iVar5;
    iVar8 = uVar11 + 7;
    if (iVar8 < 0) {
      iVar8 = uVar11 + 0xe;
    }
  }
  iVar6 = (int)param_6;
  if (iVar6 < 0) {
    pbVar10 = param_1 + -(param_4 * iVar6);
    pbVar3 = param_1 + (param_3 + -1) * param_4;
    pbVar9 = pbVar3;
  }
  else {
    pbVar3 = param_1 + (param_3 + -1) * param_4;
    pbVar10 = param_1;
    pbVar9 = param_1 + ((param_3 - iVar6) + -1) * param_4;
  }
  uVar16 = param_4;
  if (iVar5 < 1) {
    if (-1 < iVar5) goto LAB_c02837d4;
    bVar20 = (&DAT_c029a25c)[iVar5];
    bVar15 = (&DAT_c029a24c)[param_2 & 7];
    if (pbVar9 < pbVar10) goto LAB_c02837d4;
    pbVar21 = pbVar10 + iVar4 + -1;
    pbVar19 = pbVar10;
    do {
      pbVar19 = pbVar19 + param_4;
      pbVar12 = pbVar21 + (1 - iVar4);
      *pbVar12 = *pbVar12 & bVar20;
      pbVar14 = pbVar21 + 1;
      *pbVar21 = *pbVar21 & bVar15;
      if ((pbVar14 < pbVar19) && ((int)pbVar19 - (int)pbVar14 != 0)) {
        pbVar7 = pbVar14 + ((int)pbVar19 - (int)pbVar14);
        do {
          *pbVar14 = 0;
          pbVar14 = pbVar14 + 1;
        } while (pbVar14 != pbVar7);
      }
      if (pbVar12 <= pbVar21) {
        iVar8 = -iVar5 + 7;
        if (iVar8 < 0) {
          iVar8 = -iVar5 + 0xe;
        }
        do {
          bVar1 = *pbVar12;
          uVar16 = (uint)bVar1;
          uVar11 = 1;
          if (0 < -iVar5) {
            uVar2 = 0xffffffff;
            do {
              iVar17 = 0;
              uVar13 = uVar11;
              pbVar14 = pbVar12;
              uVar18 = uVar2;
              if (-1 < iVar8 >> 3) {
                do {
                  if (pbVar21 < pbVar14) break;
                  if ((int)uVar13 < 0) {
                    if (-8 < (int)uVar13) {
                      uVar16 = *pbVar14 >> (uVar18 & 0x1f) | uVar16;
                    }
                  }
                  else if ((int)uVar13 < 8) {
                    uVar16 = (uint)*pbVar14 << (uVar13 & 0x1f) & 0xff | uVar16;
                  }
                  iVar17 = iVar17 + 1;
                  uVar13 = uVar13 - 8;
                  pbVar14 = pbVar14 + 1;
                  uVar18 = uVar18 + 8;
                } while (iVar17 <= iVar8 >> 3);
              }
              bVar1 = (byte)uVar16;
              uVar11 = uVar11 + 1;
              uVar2 = uVar2 - 1;
            } while ((int)uVar11 <= -iVar5);
          }
          *pbVar12 = bVar1;
          pbVar12 = pbVar12 + 1;
        } while (pbVar12 <= pbVar21);
      }
      pbVar21 = pbVar21 + param_4;
    } while (pbVar21 + (1 - iVar4) <= pbVar9);
  }
  else {
    bVar20 = (&DAT_c029a24c)[uVar11 & 7];
    if (pbVar9 < pbVar10) goto LAB_c02837d4;
    pbVar14 = pbVar10 + (iVar8 >> 3);
    pbVar21 = pbVar10;
    pbVar19 = pbVar10;
    do {
      pbVar19 = pbVar19 + param_4;
      pbVar14[-1] = pbVar14[-1] & bVar20;
      if ((pbVar14 < pbVar19) && ((int)pbVar19 - (int)pbVar14 != 0)) {
        pbVar12 = pbVar14;
        do {
          *pbVar12 = 0;
          pbVar12 = pbVar12 + 1;
        } while (pbVar12 != pbVar14 + ((int)pbVar19 - (int)pbVar14));
      }
      pbVar12 = pbVar21 + iVar4 + -1;
      if (pbVar21 <= pbVar12) {
        iVar8 = iVar5 + 7;
        if (iVar8 < 0) {
          iVar8 = iVar5 + 0xe;
        }
        do {
          bVar15 = *pbVar12;
          uVar16 = (uint)bVar15;
          uVar11 = 1;
          if (0 < iVar5) {
            uVar2 = 0xffffffff;
            do {
              iVar17 = 0;
              pbVar7 = pbVar12;
              uVar13 = uVar11;
              uVar18 = uVar2;
              if (-1 < iVar8 >> 3) {
                do {
                  if (pbVar12 + -iVar17 < pbVar21) break;
                  if ((int)uVar13 < 0) {
                    if (-8 < (int)uVar13) {
                      uVar16 = (uint)*pbVar7 << (uVar18 & 0x1f) & 0xff | uVar16;
                    }
                  }
                  else if ((int)uVar13 < 8) {
                    uVar16 = *pbVar7 >> (uVar13 & 0x1f) | uVar16;
                  }
                  iVar17 = iVar17 + 1;
                  pbVar7 = pbVar7 + -1;
                  uVar13 = uVar13 - 8;
                  uVar18 = uVar18 + 8;
                } while (iVar17 <= iVar8 >> 3);
              }
              bVar15 = (byte)uVar16;
              uVar11 = uVar11 + 1;
              uVar2 = uVar2 - 1;
            } while ((int)uVar11 <= iVar5);
          }
          *pbVar12 = bVar15;
          pbVar12 = pbVar12 + -1;
        } while (pbVar21 <= pbVar12);
      }
      pbVar21 = pbVar21 + param_4;
      pbVar14 = pbVar14 + param_4;
    } while (pbVar21 <= pbVar9);
  }
  uVar16 = param_4 & 0xffff;
LAB_c02837d4:
  if (iVar6 < 1) {
    if (iVar6 < 0) {
      for (pbVar10 = pbVar10 + -param_4; param_1 <= pbVar10; pbVar10 = pbVar10 + -param_4) {
        if ((0 < (int)param_4) && (param_4 != 0)) {
          pbVar3 = pbVar10;
          do {
            *pbVar3 = 0;
            pbVar3 = pbVar3 + 1;
          } while (pbVar3 != pbVar10 + param_4);
        }
      }
      for (; param_1 < pbVar9; param_1 = param_1 + param_4) {
        if (0 < iVar4) {
          pbVar10 = param_1;
          iVar5 = iVar4;
          do {
            bVar20 = *pbVar10;
            iVar8 = 1;
            if (0 < -iVar6) {
              pbVar3 = pbVar10;
              do {
                pbVar3 = pbVar3 + param_4;
                if (pbVar9 + uVar16 <= pbVar3) break;
                iVar8 = iVar8 + 1;
                bVar20 = *pbVar3 | bVar20;
              } while (iVar8 <= -iVar6);
            }
            *pbVar10 = bVar20;
            iVar5 = iVar5 + -1;
            pbVar10 = pbVar10 + 1;
          } while (iVar5 != 0);
        }
      }
    }
  }
  else {
    while (pbVar9 = pbVar9 + param_4, pbVar9 <= pbVar3) {
      if ((0 < (int)param_4) && (param_4 != 0)) {
        pbVar19 = pbVar9;
        do {
          *pbVar19 = 0;
          pbVar19 = pbVar19 + 1;
        } while (pbVar19 != pbVar9 + param_4);
      }
    }
    if (pbVar10 < pbVar3) {
      pbVar9 = pbVar3 + -param_4;
      do {
        if (0 < iVar4) {
          pbVar19 = pbVar3;
          pbVar21 = pbVar9;
          iVar5 = iVar4;
          do {
            bVar20 = *pbVar19;
            iVar8 = 1;
            if (0 < iVar6) {
              pbVar14 = pbVar21;
              do {
                if (pbVar14 < pbVar10) break;
                iVar8 = iVar8 + 1;
                bVar20 = *pbVar14 | bVar20;
                pbVar14 = pbVar14 + -param_4;
              } while (iVar8 <= iVar6);
            }
            *pbVar19 = bVar20;
            pbVar19 = pbVar19 + 1;
            iVar5 = iVar5 + -1;
            pbVar21 = pbVar21 + 1;
          } while (iVar5 != 0);
        }
        pbVar3 = pbVar3 + -param_4;
        pbVar9 = pbVar9 + -param_4;
      } while (pbVar10 < pbVar3);
    }
  }
  return;
}



/* c0283994 FUN_c0283994 */

/* Boundary evidence: original MIPS .pdata c0283994..c0283ddb. Semantic name remains unreviewed. */

void FUN_c0283994(byte *param_1,int param_2,int param_3,int param_4,ushort param_5,short param_6,
                 short param_7)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  ushort uVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  
  if ((param_3 != 0) && (param_1 != (byte *)0x0)) {
    iVar2 = (int)param_7;
    if (iVar2 < 0) {
      pbVar5 = param_1 + -(param_4 * iVar2);
      pbVar1 = param_1 + (param_3 + -1) * param_4;
      pbVar11 = pbVar1;
    }
    else {
      pbVar1 = param_1 + ((param_3 - iVar2) + -1) * param_4;
      pbVar5 = param_1;
      pbVar11 = param_1 + (param_3 + -1) * param_4;
    }
    iVar3 = (int)param_6;
    if (iVar3 < 1) {
      if ((iVar3 < 0) && (pbVar5 <= pbVar1)) {
        iVar3 = -iVar3;
        pbVar10 = pbVar5 + param_2;
        pbVar12 = pbVar5;
        do {
          if ((0 < iVar3) && (iVar3 != 0)) {
            pbVar9 = pbVar12;
            do {
              *pbVar9 = 0;
              pbVar9 = pbVar9 + 1;
            } while (pbVar9 != pbVar12 + iVar3);
          }
          if (pbVar12 < pbVar10) {
            pbVar9 = pbVar12;
            do {
              bVar6 = *pbVar9;
              uVar7 = (ushort)bVar6;
              iVar4 = 1;
              pbVar8 = pbVar9;
              if (0 < iVar3) {
                do {
                  pbVar8 = pbVar8 + 1;
                  if ((pbVar8 < pbVar10) && (uVar7 = *pbVar8 + uVar7 & 0xff, param_5 <= uVar7)) {
                    bVar6 = (char)param_5 - 1;
                    break;
                  }
                  bVar6 = (byte)uVar7;
                  iVar4 = iVar4 + 1;
                } while (iVar4 <= iVar3);
              }
              *pbVar9 = bVar6;
              pbVar9 = pbVar9 + 1;
            } while (pbVar9 < pbVar10);
          }
          pbVar12 = pbVar12 + param_4;
          pbVar10 = pbVar10 + param_4;
        } while (pbVar12 <= pbVar1);
      }
    }
    else if (pbVar5 <= pbVar1) {
      pbVar10 = pbVar5 + param_2 + -1;
      pbVar12 = pbVar5;
      do {
        iVar4 = iVar3;
        pbVar9 = pbVar10;
        if (0 < iVar3) {
          do {
            *pbVar9 = 0;
            iVar4 = iVar4 + -1;
            pbVar9 = pbVar9 + -1;
          } while (iVar4 != 0);
        }
        if (pbVar12 < pbVar10) {
          pbVar9 = pbVar10;
          do {
            bVar6 = *pbVar9;
            uVar7 = (ushort)bVar6;
            iVar4 = 1;
            pbVar8 = pbVar9;
            if (0 < iVar3) {
              do {
                if ((pbVar12 <= pbVar9 + -iVar4) &&
                   (uVar7 = uVar7 + pbVar8[-1] & 0xff, param_5 <= uVar7)) {
                  bVar6 = (char)param_5 - 1;
                  break;
                }
                bVar6 = (byte)uVar7;
                iVar4 = iVar4 + 1;
                pbVar8 = pbVar8 + -1;
              } while (iVar4 <= iVar3);
            }
            *pbVar9 = bVar6;
            pbVar9 = pbVar9 + -1;
          } while (pbVar12 < pbVar9);
        }
        pbVar12 = pbVar12 + param_4;
        pbVar10 = pbVar10 + param_4;
      } while (pbVar12 <= pbVar1);
    }
    if (iVar2 < 1) {
      if (iVar2 < 0) {
        for (pbVar5 = pbVar5 + -param_4; param_1 <= pbVar5; pbVar5 = pbVar5 + -param_4) {
          if ((0 < param_2) && (param_2 != 0)) {
            pbVar11 = pbVar5;
            do {
              *pbVar11 = 0;
              pbVar11 = pbVar11 + 1;
            } while (pbVar11 != pbVar5 + param_2);
          }
        }
        for (; param_1 < pbVar1; param_1 = param_1 + param_4) {
          if (0 < param_2) {
            pbVar5 = param_1;
            iVar3 = param_2;
            do {
              uVar7 = (ushort)*pbVar5;
              iVar4 = 1;
              if (0 < -iVar2) {
                pbVar11 = pbVar5;
                do {
                  pbVar11 = pbVar11 + param_4;
                  if (pbVar1 + param_4 <= pbVar11) break;
                  uVar7 = *pbVar11 + uVar7 & 0xff;
                  if (param_5 <= uVar7) {
                    uVar7 = param_5 + 0xff & 0xff;
                    break;
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar4 <= -iVar2);
              }
              *pbVar5 = (byte)uVar7;
              iVar3 = iVar3 + -1;
              pbVar5 = pbVar5 + 1;
            } while (iVar3 != 0);
          }
        }
      }
    }
    else {
      while (pbVar1 = pbVar1 + param_4, pbVar1 <= pbVar11) {
        if ((0 < param_2) && (param_2 != 0)) {
          pbVar12 = pbVar1;
          do {
            *pbVar12 = 0;
            pbVar12 = pbVar12 + 1;
          } while (pbVar12 != pbVar1 + param_2);
        }
      }
      if (pbVar5 < pbVar11) {
        pbVar1 = pbVar11 + -param_4;
        do {
          if (0 < param_2) {
            iVar3 = param_2;
            pbVar12 = pbVar11;
            pbVar10 = pbVar1;
            do {
              uVar7 = (ushort)*pbVar12;
              iVar4 = 1;
              if (0 < iVar2) {
                pbVar9 = pbVar10;
                do {
                  if (pbVar9 < pbVar5) break;
                  uVar7 = uVar7 + *pbVar9 & 0xff;
                  if (param_5 <= uVar7) {
                    uVar7 = param_5 + 0xff & 0xff;
                    break;
                  }
                  iVar4 = iVar4 + 1;
                  pbVar9 = pbVar9 + -param_4;
                } while (iVar4 <= iVar2);
              }
              *pbVar12 = (byte)uVar7;
              pbVar12 = pbVar12 + 1;
              iVar3 = iVar3 + -1;
              pbVar10 = pbVar10 + 1;
            } while (iVar3 != 0);
          }
          pbVar11 = pbVar11 + -param_4;
          pbVar1 = pbVar1 + -param_4;
        } while (pbVar5 < pbVar11);
      }
    }
  }
  return;
}



/* c0283ddc FUN_c0283ddc */

/* Boundary evidence: original MIPS .pdata c0283ddc..c0284333. Semantic name remains unreviewed. */

void FUN_c0283ddc(byte *param_1,int param_2,int param_3,int param_4,short param_5,short param_6)

{
  bool bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte bVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  
  if ((param_3 != 0) && (param_1 != (byte *)0x0)) {
    iVar4 = (int)param_6;
    if (iVar4 < 0) {
      pbVar12 = param_1 + -(param_4 * iVar4);
      pbVar3 = param_1 + (param_3 + -1) * param_4;
      pbVar14 = pbVar3;
    }
    else {
      pbVar3 = param_1 + ((param_3 - iVar4) + -1) * param_4;
      pbVar12 = param_1;
      pbVar14 = param_1 + (param_3 + -1) * param_4;
    }
    iVar5 = (int)param_5;
    if (iVar5 < 1) {
      if ((iVar5 < 0) && (pbVar12 <= pbVar3)) {
        iVar5 = -iVar5;
        pbVar13 = pbVar12 + param_2;
        pbVar11 = pbVar12;
        do {
          if ((0 < iVar5) && (iVar5 != 0)) {
            pbVar8 = pbVar11;
            do {
              *pbVar8 = 0;
              pbVar8 = pbVar8 + 1;
            } while (pbVar8 != pbVar11 + iVar5);
          }
          if (pbVar11 < pbVar13) {
            pbVar8 = pbVar11;
            do {
              bVar10 = *pbVar8;
              iVar6 = 1;
              pbVar9 = pbVar8;
              if (0 < iVar5) {
                do {
                  pbVar9 = pbVar9 + 1;
                  if (((pbVar9 < pbVar13) && (*pbVar9 != 0)) &&
                     (bVar1 = bVar10 != 0, bVar10 = *pbVar9, bVar1)) {
                    bVar10 = 0x2a;
                    break;
                  }
                  iVar6 = iVar6 + 1;
                } while (iVar6 <= iVar5);
              }
              *pbVar8 = bVar10;
              pbVar8 = pbVar8 + 1;
            } while (pbVar8 < pbVar13);
          }
          pbVar11 = pbVar11 + param_4;
          pbVar13 = pbVar13 + param_4;
        } while (pbVar11 <= pbVar3);
      }
    }
    else if (pbVar12 <= pbVar3) {
      pbVar13 = pbVar12 + param_2 + -1;
      pbVar11 = pbVar12;
      do {
        iVar6 = iVar5;
        pbVar8 = pbVar13;
        if (0 < iVar5) {
          do {
            *pbVar8 = 0;
            iVar6 = iVar6 + -1;
            pbVar8 = pbVar8 + -1;
          } while (iVar6 != 0);
        }
        if (pbVar11 < pbVar13) {
          pbVar8 = pbVar13;
          do {
            bVar10 = *pbVar8;
            iVar6 = 1;
            pbVar9 = pbVar8;
            if (0 < iVar5) {
              do {
                if (((pbVar11 <= pbVar8 + -iVar6) && (bVar7 = pbVar9[-1], bVar7 != 0)) &&
                   (bVar1 = bVar10 != 0, bVar10 = bVar7, bVar1)) {
                  bVar10 = 0x2a;
                  break;
                }
                iVar6 = iVar6 + 1;
                pbVar9 = pbVar9 + -1;
              } while (iVar6 <= iVar5);
            }
            *pbVar8 = bVar10;
            pbVar8 = pbVar8 + -1;
          } while (pbVar11 < pbVar8);
        }
        pbVar11 = pbVar11 + param_4;
        pbVar13 = pbVar13 + param_4;
      } while (pbVar11 <= pbVar3);
    }
    if (iVar4 < 1) {
      if (iVar4 < 0) {
        for (pbVar12 = pbVar12 + -param_4; pbVar11 = param_1, param_1 <= pbVar12;
            pbVar12 = pbVar12 + -param_4) {
          if ((0 < param_2) && (param_2 != 0)) {
            pbVar11 = pbVar12;
            do {
              *pbVar11 = 0;
              pbVar11 = pbVar11 + 1;
            } while (pbVar11 != pbVar12 + param_2);
          }
        }
        for (; pbVar11 < pbVar3; pbVar11 = pbVar11 + param_4) {
          if (0 < param_2) {
            iVar5 = param_2;
            pbVar12 = pbVar11;
            do {
              iVar6 = 1;
              bVar10 = *pbVar12;
              if (0 < -iVar4) {
                pbVar13 = pbVar12;
                bVar7 = *pbVar12;
                while (pbVar13 = pbVar13 + param_4, bVar10 = bVar7, pbVar13 < pbVar3 + param_4) {
                  bVar2 = *pbVar13;
                  if (bVar2 != 0) {
                    if (bVar7 != 0) {
                      bVar10 = *pbVar13;
                      if (*pbVar13 <= bVar7) {
                        bVar10 = bVar7;
                      }
                      break;
                    }
                    if (bVar2 != 0) {
                      bVar10 = bVar2;
                    }
                  }
                  iVar6 = iVar6 + 1;
                  bVar7 = bVar10;
                  if (-iVar4 < iVar6) break;
                }
              }
              *pbVar12 = bVar10;
              iVar5 = iVar5 + -1;
              pbVar12 = pbVar12 + 1;
            } while (iVar5 != 0);
          }
        }
      }
    }
    else {
      while (pbVar3 = pbVar3 + param_4, pbVar3 <= pbVar14) {
        if ((0 < param_2) && (param_2 != 0)) {
          pbVar11 = pbVar3;
          do {
            *pbVar11 = 0;
            pbVar11 = pbVar11 + 1;
          } while (pbVar11 != pbVar3 + param_2);
        }
      }
      if (pbVar12 < pbVar14) {
        pbVar11 = pbVar14 + -param_4;
        pbVar3 = pbVar14;
        do {
          if (0 < param_2) {
            iVar5 = param_2;
            pbVar13 = pbVar11;
            pbVar8 = pbVar3;
            do {
              iVar6 = 1;
              bVar10 = *pbVar8;
              if (0 < iVar4) {
                pbVar9 = pbVar13;
                bVar7 = *pbVar8;
                while (bVar10 = bVar7, pbVar12 <= pbVar9) {
                  bVar2 = *pbVar9;
                  if (bVar2 != 0) {
                    if (bVar7 != 0) {
                      bVar10 = *pbVar9;
                      if (*pbVar9 <= bVar7) {
                        bVar10 = bVar7;
                      }
                      break;
                    }
                    if (bVar2 != 0) {
                      bVar10 = bVar2;
                    }
                  }
                  iVar6 = iVar6 + 1;
                  pbVar9 = pbVar9 + -param_4;
                  bVar7 = bVar10;
                  if (iVar4 < iVar6) break;
                }
              }
              *pbVar8 = bVar10;
              pbVar8 = pbVar8 + 1;
              iVar5 = iVar5 + -1;
              pbVar13 = pbVar13 + 1;
            } while (iVar5 != 0);
          }
          pbVar3 = pbVar3 + -param_4;
          pbVar11 = pbVar11 + -param_4;
        } while (pbVar12 < pbVar3);
      }
    }
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if ((1 < iVar4) && (pbVar12 = param_1 + param_4, pbVar12 < pbVar14)) {
      pbVar8 = pbVar12 + param_2 + -1;
      pbVar3 = pbVar12 + (1 - param_4);
      pbVar11 = pbVar3;
      pbVar13 = pbVar12;
      do {
        while (pbVar12 = pbVar12 + 1, pbVar12 < pbVar8) {
          if (((((*pbVar12 != 0) && (*pbVar12 < 0x2a)) && (pbVar12[-1] != 0)) &&
              ((pbVar12[1] != 0 && (*pbVar3 != 0)))) && (pbVar12[param_4] != 0)) {
            *pbVar12 = 0x2a;
          }
          pbVar3 = pbVar3 + 1;
        }
        pbVar12 = pbVar13 + param_4;
        pbVar8 = pbVar8 + param_4;
        pbVar3 = pbVar11 + param_4;
        pbVar11 = pbVar3;
        pbVar13 = pbVar12;
      } while (pbVar12 < pbVar14);
    }
  }
  return;
}



/* c0284334 FUN_c0284334 */

/* Boundary evidence: original MIPS .pdata c0284334..c02844f3. Semantic name remains unreviewed. */

void FUN_c0284334(int param_1,int param_2,int param_3,int param_4,short param_5)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ushort local_18;
  
  if ((((param_3 != 0) && (param_4 != 0)) && (param_1 != 0)) && (param_2 != 0)) {
    uVar10 = param_3 + 0x1f >> 3 & 0xfffc;
    uVar12 = (param_3 + 3) * 8 >> 3 & 0xfffc;
    if (param_5 == 1) {
      uVar9 = 0;
    }
    else {
      uVar9 = 2;
      if ((param_5 != 2) && (uVar9 = 4, param_5 != 4)) {
        if (param_5 == 8) {
          uVar9 = 6;
        }
        else {
          uVar9 = (uint)local_18;
        }
      }
    }
    iVar7 = param_4 + -1;
    pbVar6 = (byte *)(uVar10 * iVar7 + param_1);
    iVar11 = uVar12 * iVar7 + param_2;
    iVar7 = iVar7 * 0x10000 >> 0x10;
    if (-1 < iVar7) {
      pbVar5 = pbVar6 + (param_3 + -1 >> 3 & 0xffff);
      puVar3 = (undefined1 *)(uVar12 + iVar11 + -1);
      puVar2 = (undefined1 *)(param_3 + iVar11 + -1);
      puVar4 = puVar3;
      do {
        for (; uVar8 = param_3 - 1U & 7, pbVar1 = pbVar5, puVar2 < puVar3; puVar3 = puVar3 + -1) {
          *puVar3 = 0;
        }
        for (; pbVar6 <= pbVar1; pbVar1 = pbVar1 + -1) {
          do {
            *puVar3 = (char)((*pbVar1 >> (7 - uVar8 & 0x1f) & 1) << (uVar9 & 0x1f));
            uVar8 = (int)((uVar8 - 1) * 0x10000) >> 0x10;
            puVar3 = puVar3 + -1;
          } while (-1 < (int)uVar8);
          uVar8 = 7;
        }
        iVar7 = (iVar7 + -1) * 0x10000 >> 0x10;
        pbVar6 = pbVar6 + -uVar10;
        pbVar5 = pbVar5 + -uVar10;
        puVar3 = puVar4 + -uVar12;
        puVar2 = puVar2 + -uVar12;
        puVar4 = puVar3;
      } while (-1 < iVar7);
    }
  }
  return;
}



/* c02844f4 FUN_c02844f4 */

/* Boundary evidence: original MIPS .pdata c02844f4..c02848ef. Semantic name remains unreviewed. */

void FUN_c02844f4(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  short sVar10;
  ushort uVar11;
  uint uVar12;
  ushort uVar13;
  undefined1 *puVar14;
  char *pcVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  
  if (((param_3 != 0) && (param_2 != 0)) &&
     (uVar12 = (param_2 + 3) * 8 >> 3 & 0xfffc, 1 < param_2 + -1)) {
    iVar19 = param_3 + -1;
    iVar18 = 1;
    pcVar7 = (char *)(uint)(1 < iVar19);
    do {
      uVar16 = 1;
      if ((char *)(uint)(1 < iVar19) != (char *)0x0) {
        do {
          pcVar15 = (char *)((uVar16 & 0xffff) * uVar12 + iVar18 + param_1);
          uVar9 = 0xffffffff;
          if (((pcVar15[-1] == '\x10') && (pcVar15[1] == '\x10')) &&
             (pcVar3 = pcVar15, uVar6 = uVar16, *pcVar15 == '\0')) {
            while( true ) {
              uVar9 = uVar6;
              pcVar7 = pcVar3 + uVar12;
              if ((iVar19 <= (int)(uVar9 + 1)) || (pcVar7[-1] != '\x10')) break;
              if ((pcVar7[1] != '\x10') || (pcVar3 = pcVar7, uVar6 = uVar9 + 1, *pcVar7 != '\0'))
              break;
            }
          }
          iVar8 = (uVar9 - uVar16) + 1;
          if ((iVar8 == 1) || (iVar8 == 2)) {
            bVar1 = pcVar15[-uVar12] == '\x10';
            if (((bVar1) && (*pcVar7 != '\x10')) || ((*pcVar7 == '\x10' && (!bVar1)))) {
              bVar2 = true;
              sVar10 = 1;
              if (!bVar1) {
                sVar10 = -1;
              }
              uVar13 = 1;
              if (iVar8 != 1) {
                uVar13 = 2;
              }
              uVar11 = 0;
              uVar6 = uVar9;
              if (sVar10 < 1) {
                uVar6 = uVar16;
              }
              uVar6 = (uint)(short)uVar6;
              iVar4 = (iVar18 + -1) * 0x10000 >> 0x10;
              iVar20 = (iVar18 + 1) * 0x10000 >> 0x10;
              if (uVar13 != 0) {
                do {
                  if (!bVar2) goto LAB_c0284880;
                  uVar6 = (int)((uVar6 + (int)sVar10) * 0x10000) >> 0x10;
                  if (((int)uVar6 < 0) || (param_3 <= (int)uVar6)) {
                    bVar2 = false;
                  }
                  iVar5 = iVar4;
                  iVar21 = iVar20;
                  if (bVar2) {
                    uVar11 = uVar11 + 1;
                    iVar17 = (uVar6 & 0xffff) * uVar12 + param_1;
                    if ((*(char *)(iVar4 + iVar17 + 1) == '\x10') ||
                       (*(char *)(iVar20 + iVar17 + -1) == '\x10')) {
                      bVar2 = false;
                    }
                    if (bVar2) {
                      if (((*(char *)(iVar4 + iVar17) != '\x10') && (iVar5 = -1, -1 < iVar4 + -1))
                         && (((char *)(iVar4 + iVar17))[-1] == '\x10')) {
                        iVar5 = (iVar4 + -1) * 0x10000 >> 0x10;
                      }
                      if (((*(char *)(iVar20 + iVar17) != '\x10') &&
                          (iVar21 = -1, iVar20 + 1 < param_2)) &&
                         (((char *)(iVar20 + iVar17))[1] == '\x10')) {
                        iVar21 = (iVar20 + 1) * 0x10000 >> 0x10;
                      }
                      if ((iVar5 < 0) || (iVar21 < 0)) {
                        bVar2 = false;
                      }
                      else {
                        bVar2 = true;
                        if (uVar11 == 1) {
                          if (iVar20 - iVar4 < iVar21 - iVar5) {
                            bVar2 = true;
                          }
                          else {
                            bVar2 = false;
                          }
                        }
                      }
                    }
                  }
                  iVar4 = iVar5;
                  iVar20 = iVar21;
                } while (uVar11 < uVar13);
                if (!bVar2) goto LAB_c0284880;
              }
              if ((int)uVar16 <= (int)uVar9) {
                puVar14 = (undefined1 *)(uVar12 * uVar16 + iVar18 + param_1);
                do {
                  iVar8 = iVar8 + -1;
                  *puVar14 = 0x10;
                  puVar14 = puVar14 + uVar12;
                } while (iVar8 != 0);
              }
            }
          }
LAB_c0284880:
          if (0 < (int)uVar9) {
            uVar16 = uVar9;
          }
          uVar16 = uVar16 + 1;
        } while ((int)uVar16 < iVar19);
      }
      iVar18 = (iVar18 + 1) * 0x10000 >> 0x10;
    } while (iVar18 < param_2 + -1);
  }
  return;
}



/* c02848f0 FUN_c02848f0 */

/* Boundary evidence: original MIPS .pdata c02848f0..c0284b73. Semantic name remains unreviewed. */

void FUN_c02848f0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  uint local_28;
  
  if (((param_2 != 0) && (param_3 != 0)) && (param_1 != 0)) {
    FUN_c02844f4(param_1,param_2,param_3);
    uVar5 = param_2 + 0xffffU & 0xffff;
    uVar9 = (param_2 + 3) * 8 >> 3 & 0xfffc;
    if (uVar5 != 0) {
      uVar1 = local_28 & 0xffff;
      do {
        pcVar11 = (char *)(uVar5 + param_1);
        uVar7 = 0xffffffff;
        uVar8 = 0xffffffff;
        if (0 < param_3) {
          uVar10 = 0;
          do {
            if (pcVar11[-1] == '\0') {
              if ((-1 < (int)uVar7) && ((int)uVar8 < 0)) {
                uVar8 = (int)((uVar10 - 1) * 0x10000) >> 0x10;
              }
            }
            else {
              if ((int)uVar7 < 0) {
                local_28 = 0;
                uVar1 = 0;
                uVar7 = uVar10;
              }
              if (((uVar10 == param_3 - 1U) && (-1 < (int)uVar7)) && ((int)uVar8 < 0)) {
                uVar8 = uVar10;
              }
              if (*pcVar11 == '\0') {
                uVar1 = uVar1 + 1 & 0xffff;
                if (uVar5 == param_2 - 1U) {
                  uVar3 = 0;
                }
                else {
                  uVar3 = (uint)(byte)pcVar11[1];
                }
                if (uVar3 != 0) {
                  if (uVar10 == 0) {
                    uVar2 = 0;
                  }
                  else {
                    uVar2 = (uint)(byte)pcVar11[-uVar9];
                  }
                  if (uVar10 == param_3 - 1U) {
                    uVar4 = 0;
                  }
                  else {
                    uVar4 = (uint)(byte)pcVar11[uVar9];
                  }
                  local_28 = (uVar4 + uVar2) * 3 + uVar3 * 4 + local_28;
                }
              }
            }
            if ((-1 < (int)uVar7) && (-1 < (int)uVar8)) {
              if (uVar1 != 0) {
                if (uVar1 == 0) {
                  trap(0x1c00);
                }
                pcVar6 = (char *)((uVar7 & 0xffff) * uVar9 + uVar5 + param_1);
                for (; (int)uVar7 <= (int)uVar8; uVar7 = (int)((uVar7 + 1) * 0x10000) >> 0x10) {
                  if (*pcVar6 == '\0') {
                    *pcVar6 = '\x10' - (char)((local_28 >> 4) / uVar1);
                  }
                  pcVar6 = pcVar6 + uVar9;
                }
              }
              uVar7 = 0xffffffff;
              uVar8 = 0xffffffff;
            }
            uVar10 = (int)((uVar10 + 1) * 0x10000) >> 0x10;
            pcVar11 = pcVar11 + uVar9;
          } while ((int)uVar10 < param_3);
        }
        uVar5 = uVar5 + 0xffff & 0xffff;
      } while (uVar5 != 0);
    }
  }
  return;
}



/* c0284b74 FUN_c0284b74 */

/* Boundary evidence: original MIPS .pdata c0284b74..c0284d9f. Semantic name remains unreviewed. */

void FUN_c0284b74(uint param_1,uint param_2,int param_3,int param_4,ushort param_5,int param_6,
                 int param_7)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  
  uVar8 = (uint)param_5;
  uVar9 = (1 << (uVar8 & 0x1f)) + 0xffffU & 0xffff;
  iVar6 = 2;
  if (uVar8 == 2) {
    uVar3 = 3;
    uVar4 = (param_2 - 1 & 3) << 1;
  }
  else if (uVar8 == 4) {
    iVar6 = 1;
    uVar3 = 0xf;
    uVar4 = (param_2 - 1 & 1) << 2;
  }
  else {
    if (uVar8 != 8) {
      return;
    }
    uVar3 = 0xff;
    iVar6 = 0;
    uVar4 = 0;
  }
  if (param_1 != 0) {
    pbVar11 = (byte *)(((int)(param_2 - 1) >> iVar6) + param_3 * (param_1 - 1) + param_6);
    pbVar2 = (byte *)(param_2 + param_4 * (param_1 - 1) + param_7 + -1);
    do {
      *pbVar11 = *pbVar11 >> ((8 - uVar8) - uVar4 & 0x1f);
      uVar1 = uVar4;
      pbVar10 = pbVar2;
      pbVar7 = pbVar11;
      for (uVar5 = param_2; uVar5 != 0; uVar5 = uVar5 + 0xffff & 0xffff) {
        if (*pbVar10 == 0) {
          *pbVar10 = *pbVar7 & (byte)uVar3;
        }
        else {
          iVar6 = (uVar9 - *pbVar7 & uVar3) * (uVar9 - *pbVar10);
          if (uVar9 == 0) {
            trap(0x1c00);
          }
          if ((uVar9 == 0xffffffff) && (iVar6 == -0x80000000)) {
            trap(0x1800);
          }
          *pbVar10 = (char)uVar9 - (char)(iVar6 / (int)uVar9);
        }
        *pbVar7 = *pbVar7 >> (param_5 & 0x1f);
        pbVar10 = pbVar10 + -1;
        if (uVar1 == 0) {
          uVar1 = 8;
          pbVar7 = pbVar7 + -1;
        }
        uVar1 = uVar1 - uVar8 & 0xffff;
      }
      param_1 = param_1 + 0xffff & 0xffff;
      pbVar2 = pbVar2 + -param_4;
      pbVar11 = pbVar11 + -param_3;
    } while (param_1 != 0);
  }
  return;
}



/* c0284da0 FUN_c0284da0 */

/* Boundary evidence: original MIPS .pdata c0284da0..c0285193. Semantic name remains unreviewed. */

int FUN_c0284da0(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,ushort param_6,
                ushort param_7,ushort param_8,ushort param_9,short param_10,undefined2 param_11,
                ushort param_12,ushort param_13,ushort param_14,ushort param_15,ushort param_16,
                void *param_17,int param_18)

{
  int iVar1;
  uint uVar2;
  undefined4 in_stack_ffffff6c;
  ushort local_70;
  ushort local_6e;
  ushort local_6c;
  ushort local_6a;
  ushort local_68;
  ushort local_66;
  ushort local_64 [14];
  int local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_3c = 0;
  local_44 = 0;
  local_48 = 0;
  local_70 = 0;
  local_68 = 0;
  local_64[8] = 0;
  local_64[6] = 0;
  local_64[0] = 0;
  local_66 = 0;
  local_6a = 0;
  local_6c = 0;
  local_6e = 0;
  local_64[7] = 0;
  local_64[10] = 0;
  local_64[5] = 0;
  local_64[9] = 0;
  local_64[0xc] = 0;
  local_64[0xb] = 0;
  local_64[4] = 0;
  local_64[3] = 0;
  local_64[2] = 0;
  local_64[1] = 0;
  local_40 = 0;
  local_2c = 0;
  local_30 = 0;
  local_38 = param_2;
  local_34 = param_4;
  iVar1 = FUN_c027c2f8(param_1,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                       CONCAT22((short)((uint)in_stack_ffffff6c >> 0x10),param_11),param_12,param_13
                       ,param_14,param_16,(int)param_17,&local_70);
  if (iVar1 == 0) {
    if ((param_16 != 1) && (local_70 == 0)) {
      FUN_c0284b74((uint)param_6,(uint)param_7,(uint)param_14,(uint)param_15,param_16,(int)param_17,
                   param_18);
    }
    if ((local_70 != 0) && (uVar2 = 0, local_70 != 0)) {
      do {
        if (param_16 != 1) {
          memset(param_17,0,(uint)param_6 * (uint)param_14);
        }
        iVar1 = FUN_c027c784(param_1,uVar2,local_34,param_5,&local_68,local_64 + 8,local_64 + 6);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_c027b474(param_1,(uint)local_68,local_38,&local_40,local_64,&local_66,&local_3c,
                             &local_6a,&local_44,&local_48);
        if (iVar1 != 0) {
          return iVar1;
        }
        if (local_40 == 0) {
          return 0x1801;
        }
        iVar1 = FUN_c027bcd0(param_1,(uint)local_64[0],(uint)local_66,local_3c,&local_6c,&local_6e,
                             (short *)(local_64 + 4),(short *)(local_64 + 3),(short *)(local_64 + 2)
                             ,(short *)(local_64 + 1),local_64 + 0xc,local_64 + 0xb,&local_2c,
                             &local_30);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_c027be5c(param_1,(uint)local_6a,local_44,local_48,param_16,(short *)&local_6c,
                             &local_6e,local_64 + 7,(short *)(local_64 + 10),(short *)(local_64 + 5)
                             ,(short *)(local_64 + 9),(short *)(local_64 + 4),
                             (short *)(local_64 + 3),(short *)(local_64 + 2),(short *)(local_64 + 1)
                            );
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_c0284da0(param_1,local_38,(uint)local_6a,local_44,local_48,local_6c,local_6e,
                             local_64[7],local_64[10],local_64[5],local_64[9],
                             local_64[7] + local_64[8] + param_12,
                             local_64[5] + local_64[6] + param_13,param_14,param_15,param_16,
                             param_17,param_18);
        if (iVar1 != 0) {
          return iVar1;
        }
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < local_70);
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c0285194 FUN_c0285194 */

uint FUN_c0285194(int param_1,uint param_2)

{
  uint uVar1;
  
  if (*(short *)(param_1 + 0x1c) == 3) {
    uVar1 = (uint)*(ushort *)(param_1 + 0x22);
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    param_2 = ((uint)*(ushort *)(param_1 + 0x1e) * 2 * param_2 + uVar1) / (uVar1 << 1) & 0xffff;
  }
  if ((*(short *)(param_1 + 0x60) != 0) && (param_2 != 0)) {
    param_2 = param_2 + 1 & 0xffff;
  }
  return param_2;
}



/* c0285200 FUN_c0285200 */

uint FUN_c0285200(int param_1,uint param_2)

{
  uint uVar1;
  
  if (*(short *)(param_1 + 0x1c) == 3) {
    uVar1 = (uint)*(ushort *)(param_1 + 0x24);
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    param_2 = ((uint)*(ushort *)(param_1 + 0x20) * 2 * param_2 + uVar1) / (uVar1 << 1) & 0xffff;
  }
  return param_2;
}



/* c028524c FUN_c028524c */

/* Boundary evidence: original MIPS .pdata c028524c..c02852a3. Semantic name remains unreviewed. */

uint FUN_c028524c(int param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x1c) == 3) {
    if ((int)param_2 < 0) {
      uVar2 = FUN_c0285194(param_1,-param_2 & 0xffff);
      sVar1 = -(short)uVar2;
    }
    else {
      uVar2 = FUN_c0285194(param_1,param_2 & 0xffff);
      sVar1 = (short)uVar2;
    }
    param_2 = (uint)sVar1;
  }
  return param_2;
}



/* c02852a4 FUN_c02852a4 */

/* Boundary evidence: original MIPS .pdata c02852a4..c02852fb. Semantic name remains unreviewed. */

uint FUN_c02852a4(int param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x1c) == 3) {
    if ((int)param_2 < 0) {
      uVar2 = FUN_c0285200(param_1,-param_2 & 0xffff);
      sVar1 = -(short)uVar2;
    }
    else {
      uVar2 = FUN_c0285200(param_1,param_2 & 0xffff);
      sVar1 = (short)uVar2;
    }
    param_2 = (uint)sVar1;
  }
  return param_2;
}



/* c02852fc FUN_c02852fc */

uint FUN_c02852fc(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x1c) == 3) {
    uVar1 = *(ushort *)(param_1 + 0x22);
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x1e);
  }
  uVar2 = (uint)*(ushort *)(param_1 + 0x5c);
  if (uVar2 == 0) {
    trap(0x1c00);
  }
  uVar2 = ((uint)uVar1 * 2 * param_2 + uVar2) / (uVar2 << 1) & 0xffff;
  if ((*(short *)(param_1 + 0x60) != 0) && (uVar2 != 0)) {
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return uVar2;
}



/* c028536c FUN_c028536c */

uint FUN_c028536c(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x1c) == 3) {
    uVar1 = *(ushort *)(param_1 + 0x24);
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x20);
  }
  uVar2 = (uint)*(ushort *)(param_1 + 0x5c);
  if (uVar2 == 0) {
    trap(0x1c00);
  }
  return ((uint)uVar1 * 2 * param_2 + uVar2) / (uVar2 << 1) & 0xffff;
}



/* c02853bc FUN_c02853bc */

/* Boundary evidence: original MIPS .pdata c02853bc..c0285563. Semantic name remains unreviewed. */

void FUN_c02853bc(void *param_1,size_t param_2,uint param_3,uint param_4)

{
  void *pvVar1;
  uint uVar2;
  void *_Dst;
  uint uVar3;
  
  uVar2 = param_3 >> 1 & 0xffff;
  if (param_4 < param_3) {
    pvVar1 = param_1;
    if (param_4 != 0) {
      uVar3 = 0;
      do {
        for (; param_4 <= uVar2; uVar2 = uVar2 - param_4 & 0xffff) {
          param_1 = (void *)(param_2 + (int)param_1);
        }
        if (param_1 != pvVar1) {
          memcpy(pvVar1,param_1,param_2);
        }
        uVar3 = uVar3 + 1 & 0xffff;
        pvVar1 = (void *)(param_2 + (int)pvVar1);
        uVar2 = uVar2 + param_3 & 0xffff;
      } while (uVar3 < param_4);
    }
    do {
      memset(pvVar1,0,param_2);
      param_4 = param_4 + 1 & 0xffff;
      pvVar1 = (void *)(param_2 + (int)pvVar1);
    } while (param_4 < param_3);
  }
  else if (param_3 < param_4) {
    pvVar1 = (void *)((param_3 - 1) * param_2 + (int)param_1);
    _Dst = (void *)((param_4 - 1) * param_2 + (int)param_1);
    if (param_3 != 0) {
      uVar3 = 0;
      do {
        for (uVar2 = uVar2 + param_4; uVar2 = uVar2 & 0xffff, param_3 <= uVar2;
            uVar2 = uVar2 - param_3) {
          if (pvVar1 != _Dst) {
            memcpy(_Dst,pvVar1,param_2);
          }
          _Dst = (void *)((int)_Dst - param_2);
        }
        uVar3 = uVar3 + 1 & 0xffff;
        pvVar1 = (void *)((int)pvVar1 - param_2);
      } while (uVar3 < param_3);
    }
  }
  return;
}



/* c0285564 FUN_c0285564 */

void FUN_c0285564(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  if (param_2 < param_3) {
    uVar1 = param_4 + 0xffff & 0xffff;
    uVar5 = param_3 - param_2 & 0xffff;
    puVar4 = (undefined1 *)(param_3 * uVar1 + param_1);
    if (param_4 != 0) {
      puVar3 = (undefined1 *)(param_2 + param_2 * uVar1 + param_1 + -1);
      do {
        puVar2 = puVar4 + (param_3 - 1);
        puVar6 = puVar3;
        if (uVar5 != 0) {
          uVar1 = 0;
          do {
            uVar1 = uVar1 + 1 & 0xffff;
            *puVar2 = 0;
            puVar2 = puVar2 + -1;
          } while (uVar1 < uVar5);
        }
        for (; puVar4 <= puVar2; puVar2 = puVar2 + -1) {
          *puVar2 = *puVar6;
          puVar6 = puVar6 + -1;
        }
        param_4 = param_4 + 0xffff & 0xffff;
        puVar3 = puVar3 + -param_2;
        puVar4 = puVar4 + -param_3;
      } while (param_4 != 0);
    }
  }
  return;
}



/* c0285640 FUN_c0285640 */

/* Boundary evidence: original MIPS .pdata c0285640..c0285b8b. Semantic name remains unreviewed. */

void FUN_c0285640(byte *param_1,int param_2,uint param_3,int param_4,ushort param_5,ushort param_6,
                 ushort param_7)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  byte local_30;
  
  if (param_4 == 1) {
    uVar8 = (uint)param_5;
    uVar7 = (uint)param_6;
    if (uVar7 < uVar8) {
      uVar5 = (int)(uVar7 + 7) >> 3;
      if (param_7 != 0) {
        uVar13 = (uint)local_30;
        pbVar11 = param_1;
        do {
          iVar14 = 0;
          iVar3 = 0;
          uVar1 = 0;
          uVar6 = 0;
          pbVar2 = param_1;
          pbVar9 = pbVar11;
          uVar12 = (uint)(param_5 >> 1);
          if (uVar5 != 0) {
            do {
              for (; uVar7 <= uVar12; uVar12 = uVar12 - uVar7 & 0xffff) {
                iVar14 = (iVar14 + -1) * 0x10000 >> 0x10;
              }
              for (; iVar14 < 1; iVar14 = (iVar14 + 8) * 0x10000 >> 0x10) {
                uVar13 = (uint)*pbVar2;
                pbVar2 = pbVar2 + 1;
              }
              iVar3 = (iVar3 + 1) * 0x10000 >> 0x10;
              uVar6 = uVar13 >> (iVar14 + 0xffU & 0x1f) & 1 | (uVar6 & 0x7f) << 1;
              if (iVar3 == 8) {
                *pbVar9 = (byte)uVar6;
                pbVar9 = pbVar9 + 1;
                iVar3 = 0;
                uVar1 = uVar1 + 1 & 0xffff;
              }
              uVar12 = uVar12 + uVar8 & 0xffff;
            } while (uVar1 < uVar5);
          }
          for (; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
            *pbVar9 = 0;
            pbVar9 = pbVar9 + 1;
          }
          param_7 = param_7 - 1;
          param_1 = param_1 + param_2;
          pbVar11 = pbVar11 + param_3;
        } while (param_7 != 0);
      }
    }
    else if (uVar8 < uVar7) {
      uVar5 = (uint)param_7;
      uVar13 = (int)(uVar7 + 7) >> 3;
      if (uVar5 != 0) {
        uVar12 = (uint)local_30;
        pbVar11 = param_1 + uVar13 + (uVar5 - 1) * param_3 + -1;
        pbVar2 = param_1 + ((int)(uVar8 + 7) >> 3) + (uVar5 - 1) * param_2 + -1;
        do {
          uVar10 = 0;
          uVar6 = 0;
          pbVar9 = pbVar2;
          pbVar4 = pbVar11;
          uVar1 = (uint)(param_5 >> 1);
          iVar3 = (int)((7 - (uVar7 - 1 & 7)) * 0x10000) >> 0x10;
          iVar14 = (uVar8 - 1 & 7) - 7;
          if (uVar13 != 0) {
            do {
              iVar14 = iVar14 * 0x10000 >> 0x10;
              if (iVar14 < 1) {
                uVar12 = (uint)*pbVar9;
                pbVar9 = pbVar9 + -1;
                iVar14 = (iVar14 + 8) * 0x10000 >> 0x10;
              }
              uVar1 = uVar1 + uVar7 & 0xffff;
              if (uVar8 <= uVar1) {
                do {
                  iVar3 = (iVar3 + 1) * 0x10000 >> 0x10;
                  uVar6 = uVar6 >> 1 | uVar12 << (iVar14 - 1U & 0x1f) & 0x80;
                  if (iVar3 == 8) {
                    *pbVar4 = (byte)uVar6;
                    pbVar4 = pbVar4 + -1;
                    iVar3 = 0;
                    uVar10 = uVar10 + 1 & 0xffff;
                  }
                  uVar1 = uVar1 - uVar8 & 0xffff;
                } while (uVar8 <= uVar1);
              }
              iVar14 = iVar14 + -1;
            } while (uVar10 < uVar13);
          }
          uVar5 = uVar5 + 0xffff & 0xffff;
          pbVar2 = pbVar2 + -param_2;
          pbVar11 = pbVar11 + -param_3;
        } while (uVar5 != 0);
      }
    }
  }
  else {
    uVar8 = (uint)param_5;
    uVar7 = (uint)param_6;
    if (uVar7 < uVar8) {
      if (param_7 != 0) {
        pbVar11 = param_1;
        do {
          uVar5 = 0;
          pbVar2 = pbVar11;
          if (uVar7 != 0) {
            uVar5 = 0;
            uVar13 = (uint)(param_5 >> 1);
            pbVar9 = param_1;
            do {
              for (; uVar7 <= uVar13; uVar13 = uVar13 - uVar7 & 0xffff) {
                pbVar9 = pbVar9 + 1;
              }
              uVar5 = uVar5 + 1 & 0xffff;
              *pbVar2 = *pbVar9;
              pbVar2 = pbVar2 + 1;
              uVar13 = uVar13 + uVar8 & 0xffff;
            } while (uVar5 < uVar7);
          }
          for (; uVar5 < param_3; uVar5 = uVar5 + 1 & 0xffff) {
            *pbVar2 = 0;
            pbVar2 = pbVar2 + 1;
          }
          param_7 = param_7 - 1;
          param_1 = param_1 + param_2;
          pbVar11 = pbVar11 + param_3;
        } while (param_7 != 0);
      }
    }
    else if (uVar8 < uVar7) {
      uVar5 = (uint)param_7;
      if (uVar5 != 0) {
        pbVar11 = param_1 + param_3 + (uVar5 - 1) * param_3 + -1;
        pbVar9 = param_1 + uVar8 + (uVar5 - 1) * param_2 + -1;
        uVar13 = param_3;
        pbVar2 = pbVar11;
        do {
          for (; uVar12 = (uint)(param_5 >> 1), pbVar4 = pbVar9, uVar7 < uVar13;
              uVar13 = uVar13 + 0xffff & 0xffff) {
            *pbVar11 = 0;
            pbVar11 = pbVar11 + -1;
          }
          while (uVar13 != 0) {
            for (uVar12 = uVar12 + uVar7; uVar12 = uVar12 & 0xffff, uVar8 <= uVar12;
                uVar12 = uVar12 - uVar8) {
              *pbVar11 = *pbVar4;
              pbVar11 = pbVar11 + -1;
              uVar13 = uVar13 + 0xffff & 0xffff;
            }
            pbVar4 = pbVar4 + -1;
          }
          uVar5 = uVar5 + 0xffff & 0xffff;
          pbVar9 = pbVar9 + -param_2;
          pbVar11 = pbVar2 + -param_3;
          uVar13 = param_3;
          pbVar2 = pbVar11;
        } while (uVar5 != 0);
      }
    }
  }
  return;
}



/* c0285b8c FUN_c0285b8c */

void FUN_c0285b8c(int *param_1)

{
  byte *pbVar1;
  
  if ((short)param_1[5] == 1) {
    if (((ushort)*(byte *)(((uint)*(ushort *)((int)param_1 + 0xe) * (uint)*(ushort *)(param_1 + 2) +
                            (uint)(*(ushort *)(param_1 + 3) >> 3) & 0xffff) + *param_1) &
        *(ushort *)(&DAT_c029a25c + (*(ushort *)(param_1 + 3) & 7) * 2)) != 0) {
      pbVar1 = (byte *)(param_1[1] +
                       ((uint)*(ushort *)((int)param_1 + 0x12) *
                        (uint)*(ushort *)((int)param_1 + 10) + (uint)(*(ushort *)(param_1 + 4) >> 3)
                       & 0xffff));
      *pbVar1 = (byte)*(undefined2 *)(&DAT_c029a25c + (*(ushort *)(param_1 + 4) & 7) * 2) | *pbVar1;
    }
  }
  else {
    *(undefined1 *)
     (((uint)*(ushort *)((int)param_1 + 0x12) * (uint)*(ushort *)((int)param_1 + 10) +
       (uint)*(ushort *)(param_1 + 4) & 0xffff) + param_1[1]) =
         *(undefined1 *)
          (((uint)*(ushort *)((int)param_1 + 0xe) * (uint)*(ushort *)(param_1 + 2) +
            (uint)*(ushort *)(param_1 + 3) & 0xffff) + *param_1);
  }
  return;
}



/* c0285ca4 FUN_c0285ca4 */

/* Boundary evidence: original MIPS .pdata c0285ca4..c02860ef. Semantic name remains unreviewed. */

int FUN_c0285ca4(int *param_1,undefined4 *param_2,byte *param_3,byte *param_4)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  byte *_Src;
  byte *pbVar7;
  byte *local_38;
  byte *local_34;
  undefined2 local_30;
  undefined2 local_2e;
  ushort local_2c;
  ushort local_2a;
  ushort local_28;
  ushort local_26;
  undefined2 local_24;
  
  memset(param_3,0,param_1[4]);
  if ((*(short *)((int)param_1 + 0x26) == 0) && ((short)param_1[7] != 3)) {
    if (*(short *)((int)param_1 + 0x5e) == 1) {
      _Src = (byte *)0x0;
      param_4 = param_3;
    }
    else {
      memset(param_4,0,param_1[5]);
      _Src = param_3;
    }
  }
  else {
    memset(param_4,0,param_1[5]);
    _Src = param_4;
    if (*(short *)((int)param_1 + 0x5e) != 1) {
      _Src = param_4 + param_1[6];
    }
  }
  iVar6 = FUN_c0284da0(param_2,*param_1,(uint)*(ushort *)(param_1 + 0xb),param_1[2],param_1[3],
                       *(ushort *)((int)param_1 + 0x2e),*(ushort *)(param_1 + 0xc),
                       *(ushort *)((int)param_1 + 0x42),*(ushort *)(param_1 + 0x11),
                       *(short *)((int)param_1 + 0x46),(short)param_1[0x12],0,0,
                       *(ushort *)((int)param_1 + 0x36),*(ushort *)(param_1 + 0xe),
                       *(ushort *)((int)param_1 + 0x5e),param_4,(int)_Src);
  if (iVar6 == 0) {
    if ((short)param_1[7] == 3) {
      FUN_c02853bc(_Src,(uint)*(ushort *)(param_1 + 0xe),(uint)*(ushort *)((int)param_1 + 0x2e),
                   (uint)*(ushort *)((int)param_1 + 0x3a));
      FUN_c0285640(_Src,(uint)*(ushort *)(param_1 + 0xe),(uint)*(ushort *)((int)param_1 + 0x3e),
                   (uint)*(ushort *)((int)param_1 + 0x5e),*(ushort *)(param_1 + 0xc),
                   *(ushort *)(param_1 + 0xf),*(ushort *)((int)param_1 + 0x3a));
      if (*(short *)((int)param_1 + 0x26) == 0) {
        memcpy(param_3,_Src,param_1[4]);
      }
    }
    else if (((short)param_1[0x18] != 0) || (*(short *)((int)param_1 + 0x62) != 0)) {
      pbVar7 = param_3;
      if (*(short *)((int)param_1 + 0x26) != 0) {
        pbVar7 = _Src;
      }
      uVar2 = *(ushort *)((int)param_1 + 0x5e);
      if (uVar2 == 1) {
        FUN_c02833a4(pbVar7,(uint)*(ushort *)(param_1 + 0xf),(uint)*(ushort *)((int)param_1 + 0x3a),
                     (uint)*(ushort *)((int)param_1 + 0x3e),(short)param_1[0x18],
                     *(short *)((int)param_1 + 0x62));
      }
      else {
        if ((uint)*(ushort *)(param_1 + 0xe) < (uint)*(ushort *)((int)param_1 + 0x3e)) {
          FUN_c0285564((int)pbVar7,(uint)*(ushort *)(param_1 + 0xe),
                       (uint)*(ushort *)((int)param_1 + 0x3e),(uint)*(ushort *)((int)param_1 + 0x3a)
                      );
        }
        FUN_c0283994(pbVar7,(uint)*(ushort *)(param_1 + 0xf),(uint)*(ushort *)((int)param_1 + 0x3a),
                     (uint)*(ushort *)((int)param_1 + 0x3e),(ushort)(1 << (uVar2 & 0x1f)),
                     (short)param_1[0x18],*(short *)((int)param_1 + 0x62));
      }
    }
    sVar1 = *(short *)((int)param_1 + 0x26);
    if (sVar1 != 0) {
      local_30 = *(undefined2 *)((int)param_1 + 0x3e);
      local_2e = (undefined2)param_1[0x10];
      local_24 = 1;
      if (*(short *)((int)param_1 + 0x5e) != 1) {
        local_24 = 8;
      }
      uVar2 = *(ushort *)(param_1 + 0xf);
      uVar3 = *(ushort *)((int)param_1 + 0x3a);
      local_38 = _Src;
      local_34 = param_3;
      if (sVar1 == 1) {
        local_2a = 0;
        if (uVar3 != 0) {
          do {
            uVar5 = local_2a;
            local_2c = 0;
            local_28 = local_2a;
            if (uVar2 != 0) {
              do {
                uVar4 = local_2c;
                local_26 = (uVar2 - local_2c) + -1;
                FUN_c0285b8c((int *)&local_38);
                local_2c = uVar4 + 1;
              } while (local_2c < uVar2);
            }
            local_2a = uVar5 + 1;
          } while (local_2a < uVar3);
        }
      }
      else if (sVar1 == 2) {
        local_2a = 0;
        if (uVar3 != 0) {
          do {
            uVar5 = local_2a;
            local_26 = (uVar3 - local_2a) + -1;
            local_2c = 0;
            if (uVar2 != 0) {
              do {
                uVar4 = local_2c;
                local_28 = (uVar2 - local_2c) + -1;
                FUN_c0285b8c((int *)&local_38);
                local_2c = uVar4 + 1;
              } while (local_2c < uVar2);
            }
            local_2a = uVar5 + 1;
          } while (local_2a < uVar3);
        }
      }
      else {
        if (sVar1 != 3) {
          return 0x1802;
        }
        local_2a = 0;
        if (uVar3 != 0) {
          do {
            uVar5 = local_2a;
            local_28 = (uVar3 - local_2a) + -1;
            local_2c = 0;
            if (uVar2 != 0) {
              do {
                uVar4 = local_2c;
                local_26 = local_2c;
                FUN_c0285b8c((int *)&local_38);
                local_2c = uVar4 + 1;
              } while (local_2c < uVar2);
            }
            local_2a = uVar5 + 1;
          } while (local_2a < uVar3);
        }
      }
    }
    iVar6 = 0;
  }
  return iVar6;
}



/* c02860f0 FUN_c02860f0 */

/* Boundary evidence: original MIPS .pdata c02860f0..c0286187. Semantic name remains unreviewed. */

int FUN_c02860f0(int param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  ushort local_10;
  ushort local_e [3];
  
  iVar2 = FUN_c027d550(param_2,(uint)*(ushort *)(param_2 + 0x35),(short *)&local_10,(short *)local_e
                      );
  if (iVar2 == 0) {
    uVar3 = FUN_c028536c(param_1,(uint)local_10);
    *(short *)(param_1 + 0x34) = (short)uVar3;
    *(undefined2 *)(param_1 + 0x4e) = *(undefined2 *)(param_1 + 0x4a);
    if ((short)local_e[0] < 0) {
      uVar3 = FUN_c028536c(param_1,-(int)(short)local_e[0] & 0xffff);
      sVar1 = -(short)uVar3;
    }
    else {
      uVar3 = FUN_c028536c(param_1,(uint)local_e[0]);
      sVar1 = (short)uVar3;
    }
    *(short *)(param_1 + 0x50) = -sVar1;
    iVar2 = 0;
  }
  return iVar2;
}



/* c0286188 FUN_c0286188 */

/* Boundary evidence: original MIPS .pdata c0286188..c028621b. Semantic name remains unreviewed. */

int FUN_c0286188(int param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  ushort local_10;
  ushort local_e [3];
  
  iVar2 = FUN_c027a114(param_2,(uint)*(ushort *)(param_2 + 0x35),&local_10,local_e);
  if (iVar2 == 0) {
    uVar3 = FUN_c02852fc(param_1,(uint)local_10);
    *(short *)(param_1 + 0x32) = (short)uVar3;
    *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(param_1 + 0x4e);
    if ((short)local_e[0] < 0) {
      uVar3 = FUN_c028536c(param_1,-(int)(short)local_e[0] & 0xffff);
      sVar1 = -(short)uVar3;
    }
    else {
      uVar3 = FUN_c028536c(param_1,(uint)local_e[0]);
      sVar1 = (short)uVar3;
    }
    *(short *)(param_1 + 0x4c) = sVar1;
    iVar2 = 0;
  }
  return iVar2;
}



/* c028621c FUN_c028621c */

/* Boundary evidence: original MIPS .pdata c028621c..c028635b. Semantic name remains unreviewed. */

int FUN_c028621c(int param_1,undefined4 *param_2,int *param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int local_20;
  undefined4 uStack_1c;
  
  iVar2 = FUN_c027bcd0(param_2,(uint)*(ushort *)(param_1 + 0x28),(uint)*(ushort *)(param_1 + 0x2a),
                       *(int *)(param_1 + 4),(ushort *)(param_1 + 0x2e),(ushort *)(param_1 + 0x30),
                       (short *)(param_1 + 0x4a),(short *)(param_1 + 0x4c),(short *)(param_1 + 0x4e)
                       ,(short *)(param_1 + 0x50),(ushort *)(param_1 + 0x32),
                       (ushort *)(param_1 + 0x34),&local_20,&uStack_1c);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((local_20 == 0) && (iVar2 = FUN_c0286188(param_1,param_2), iVar2 != 0)) {
    return iVar2;
  }
  uVar3 = FUN_c0285194(param_1,(uint)*(ushort *)(param_1 + 0x32));
  sVar1 = *(short *)(param_1 + 0x26);
  iVar2 = uVar3 * 0x40;
  if (sVar1 != 0) {
    if (sVar1 == 1) {
      *param_3 = 0;
      param_3[1] = iVar2;
      return 0;
    }
    if (sVar1 != 2) {
      if (sVar1 == 3) {
        *param_3 = 0;
        param_3[1] = uVar3 * -0x40;
        return 0;
      }
      return 0x1802;
    }
    iVar2 = uVar3 * -0x40;
  }
  param_3[1] = 0;
  *param_3 = iVar2;
  return 0;
}



/* c028635c FUN_c028635c */

/* Boundary evidence: original MIPS .pdata c028635c..c0286507. Semantic name remains unreviewed. */

int FUN_c028635c(int param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  int local_28;
  undefined4 uStack_24;
  
  puVar5 = (ushort *)(param_1 + 0x32);
  puVar6 = (ushort *)(param_1 + 0x4a);
  puVar7 = (ushort *)(param_1 + 0x30);
  iVar1 = FUN_c027bcd0(param_2,(uint)*(ushort *)(param_1 + 0x28),(uint)*(ushort *)(param_1 + 0x2a),
                       *(int *)(param_1 + 4),(ushort *)(param_1 + 0x2e),puVar7,(short *)puVar6,
                       (short *)(param_1 + 0x4c),(short *)(param_1 + 0x4e),(short *)(param_1 + 0x50)
                       ,puVar5,(ushort *)(param_1 + 0x34),&local_28,&uStack_24);
  if ((iVar1 == 0) && ((local_28 != 0 || (iVar1 = FUN_c0286188(param_1,param_2), iVar1 == 0)))) {
    if (*(short *)(param_1 + 0x26) == 0) {
      uVar2 = FUN_c0285194(param_1,(uint)*puVar5);
      *param_3 = uVar2 << 6;
      uVar2 = FUN_c0285194(param_1,(uint)*puVar6);
      *param_4 = uVar2 * 0x40;
      uVar3 = FUN_c0285194(param_1,(uint)*puVar7);
      iVar4 = *param_3 + uVar3 * -0x40 + uVar2 * -0x40;
    }
    else {
      if (*(short *)(param_1 + 0x26) != 2) {
        return 0x1802;
      }
      uVar2 = FUN_c0285194(param_1,(uint)*puVar5);
      *param_3 = uVar2 * -0x40;
      uVar2 = FUN_c0285194(param_1,(uint)*puVar6);
      *param_4 = uVar2 * -0x40;
      uVar3 = FUN_c0285194(param_1,(uint)*puVar7);
      iVar4 = uVar3 * 0x40 + uVar2 * 0x40 + *param_3;
    }
    iVar1 = 0;
    *param_5 = iVar4;
  }
  return iVar1;
}



/* c0286508 FUN_c0286508 */

/* Boundary evidence: original MIPS .pdata c0286508..c0286643. Semantic name remains unreviewed. */

int FUN_c0286508(int param_1,undefined4 *param_2,int *param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int local_20;
  undefined4 uStack_1c;
  
  iVar2 = FUN_c027bcd0(param_2,(uint)*(ushort *)(param_1 + 0x28),(uint)*(ushort *)(param_1 + 0x2a),
                       *(int *)(param_1 + 4),(ushort *)(param_1 + 0x2e),(ushort *)(param_1 + 0x30),
                       (short *)(param_1 + 0x4a),(short *)(param_1 + 0x4c),(short *)(param_1 + 0x4e)
                       ,(short *)(param_1 + 0x50),(ushort *)(param_1 + 0x32),
                       (ushort *)(param_1 + 0x34),&uStack_1c,&local_20);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((local_20 == 0) && (iVar2 = FUN_c02860f0(param_1,param_2), iVar2 != 0)) {
    return iVar2;
  }
  uVar3 = FUN_c0285200(param_1,(uint)*(ushort *)(param_1 + 0x34));
  sVar1 = *(short *)(param_1 + 0x26);
  iVar2 = uVar3 * 0x40;
  if (sVar1 == 0) {
    param_3[1] = iVar2;
LAB_c0286620:
    *param_3 = 0;
  }
  else {
    if (sVar1 == 1) {
      iVar2 = uVar3 * -0x40;
    }
    else {
      if (sVar1 == 2) {
        param_3[1] = uVar3 * -0x40;
        goto LAB_c0286620;
      }
      if (sVar1 != 3) {
        return 0x1802;
      }
    }
    *param_3 = iVar2;
    param_3[1] = 0;
  }
  return 0;
}



/* c0286644 FUN_c0286644 */

/* Boundary evidence: original MIPS .pdata c0286644..c02867bb. Semantic name remains unreviewed. */

int FUN_c0286644(int param_1,undefined4 *param_2)

{
  int iVar1;
  int local_30;
  int local_2c;
  
  if (*(int *)(param_1 + 0x58) == 0) {
    iVar1 = FUN_c027bcd0(param_2,(uint)*(ushort *)(param_1 + 0x28),(uint)*(ushort *)(param_1 + 0x2a)
                         ,*(int *)(param_1 + 4),(ushort *)(param_1 + 0x2e),
                         (ushort *)(param_1 + 0x30),(short *)(param_1 + 0x4a),
                         (short *)(param_1 + 0x4c),(short *)(param_1 + 0x4e),
                         (short *)(param_1 + 0x50),(ushort *)(param_1 + 0x32),
                         (ushort *)(param_1 + 0x34),&local_30,&local_2c);
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((local_30 == 0) && (iVar1 = FUN_c0286188(param_1,param_2), iVar1 != 0)) {
      return iVar1;
    }
    if ((local_2c == 0) && (iVar1 = FUN_c02860f0(param_1,param_2), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = FUN_c027be5c(param_2,(uint)*(ushort *)(param_1 + 0x2c),*(int *)(param_1 + 8),
                         *(int *)(param_1 + 0xc),*(ushort *)(param_1 + 0x5e),
                         (short *)(param_1 + 0x2e),(ushort *)(param_1 + 0x30),
                         (ushort *)(param_1 + 0x42),(short *)(param_1 + 0x44),
                         (short *)(param_1 + 0x46),(short *)(param_1 + 0x48),
                         (short *)(param_1 + 0x4a),(short *)(param_1 + 0x4c),
                         (short *)(param_1 + 0x4e),(short *)(param_1 + 0x50));
    if (iVar1 != 0) {
      return iVar1;
    }
    *(undefined4 *)(param_1 + 0x58) = 1;
  }
  return 0;
}



/* c02867bc FUN_c02867bc */

/* Boundary evidence: original MIPS .pdata c02867bc..c0286e07. Semantic name remains unreviewed. */

int FUN_c02867bc(int param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5,int *param_6
                ,int *param_7,int *param_8,short *param_9,undefined2 *param_10,undefined4 *param_11,
                undefined4 *param_12)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  ushort local_38;
  
  if (*(short *)(param_1 + 0x5e) == 1) {
    local_38 = 1;
  }
  else {
    local_38 = 8;
  }
  iVar3 = FUN_c0286644(param_1,param_2);
  if (iVar3 != 0) {
    return iVar3;
  }
  uVar22 = (uint)*(ushort *)(param_1 + 0x30);
  uVar4 = FUN_c0285194(param_1,uVar22);
  uVar23 = (uint)*(ushort *)(param_1 + 0x2e);
  *(short *)(param_1 + 0x3c) = (short)uVar4;
  uVar5 = FUN_c0285200(param_1,uVar23);
  sVar1 = *(short *)(param_1 + 0x4c);
  *(short *)(param_1 + 0x3a) = (short)uVar5;
  uVar6 = FUN_c02852a4(param_1,(int)sVar1);
  sVar2 = *(short *)(param_1 + 0x4a);
  sVar14 = (short)uVar6;
  uVar6 = FUN_c028524c(param_1,(int)sVar2);
  sVar15 = sVar14 - (short)uVar5;
  sVar17 = (short)uVar6;
  sVar16 = sVar17 + (short)uVar4;
  uVar7 = FUN_c0285194(param_1,(uint)*(ushort *)(param_1 + 0x32));
  uVar8 = FUN_c0285200(param_1,(uint)*(ushort *)(param_1 + 0x34));
  uVar9 = FUN_c028524c(param_1,(int)sVar2);
  iVar20 = uVar9 * 0x40;
  uVar10 = FUN_c02852a4(param_1,(int)sVar1);
  uVar11 = FUN_c028524c(param_1,(int)*(short *)(param_1 + 0x4e));
  iVar21 = uVar11 * 0x40;
  uVar12 = FUN_c02852a4(param_1,(int)*(short *)(param_1 + 0x50));
  uVar18 = (uint)local_38;
  *(undefined4 *)(param_1 + 0x18) = 0;
  iVar13 = uVar12 * 0x40;
  uVar19 = (int)(*(ushort *)(param_1 + 0x5e) * uVar22 + 0x1f) >> 3 & 0xfffc;
  *(short *)(param_1 + 0x36) = (short)uVar19;
  uVar6 = (int)(uVar18 * uVar22 + 0x1f) >> 3 & 0xfffc;
  *(short *)(param_1 + 0x38) = (short)uVar6;
  uVar4 = (int)(uVar18 * uVar4 + 0x1f) >> 3 & 0xfffc;
  *(short *)(param_1 + 0x3e) = (short)uVar4;
  iVar3 = uVar19 * uVar23;
  uVar6 = uVar6 * uVar23;
  uVar4 = uVar4 * uVar5;
  if (uVar6 < uVar4) {
    uVar6 = uVar4;
  }
  sVar1 = *(short *)(param_1 + 0x26);
  if (sVar1 == 0) {
    param_9[2] = sVar15;
    *param_9 = sVar14;
    param_9[1] = sVar17;
    param_9[3] = sVar16;
    *param_3 = uVar7 * 0x40;
    param_3[1] = 0;
    param_4[1] = uVar10 * 0x40;
    *param_4 = iVar20;
    param_5[1] = (int)sVar14 << 6;
    *param_5 = iVar20;
    param_6[1] = uVar8 * 0x40;
    *param_6 = 0;
    *param_7 = iVar21;
    param_7[1] = iVar13;
    *param_8 = iVar21;
    param_8[1] = iVar13;
    uVar4 = (int)(*(ushort *)(param_1 + 0x3c) * uVar18 + 0x1f) >> 3 & 0xfffc;
    *(short *)(param_1 + 0x40) = (short)uVar4;
    *(uint *)(param_1 + 0x10) = uVar4 * *(ushort *)(param_1 + 0x3a);
    if ((*(short *)(param_1 + 0x1c) != 3) && (*(short *)(param_1 + 0x5e) == 1)) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      goto LAB_c0286db0;
    }
    *(uint *)(param_1 + 0x14) = uVar6;
    if (*(short *)(param_1 + 0x5e) == 1) goto LAB_c0286db0;
    *(uint *)(param_1 + 0x14) = uVar6 + iVar3;
  }
  else if (sVar1 == 1) {
    *param_9 = sVar16;
    param_9[2] = sVar17;
    param_9[3] = -sVar15;
    param_9[1] = -sVar14;
    param_3[1] = uVar7 * 0x40;
    *param_3 = 0;
    *param_4 = uVar10 * -0x40;
    iVar13 = ((int)sVar16 - (int)sVar17) * 0x40;
    param_4[1] = iVar13 + iVar20;
    param_5[1] = sVar16 * 0x40 + uVar9 * -0x40;
    *param_5 = 0;
    *param_6 = uVar8 * -0x40;
    param_6[1] = 0;
    param_7[1] = iVar13 + iVar21;
    *param_7 = uVar12 * -0x40;
    *param_8 = uVar12 * -0x40 + sVar14 * -0x40;
    param_8[1] = 0;
    *(uint *)(param_1 + 0x14) = uVar6;
    uVar4 = (int)(*(ushort *)(param_1 + 0x3a) * uVar18 + 0x1f) >> 3 & 0xfffc;
    *(short *)(param_1 + 0x40) = (short)uVar4;
    *(uint *)(param_1 + 0x10) = uVar4 * *(ushort *)(param_1 + 0x3c);
    if (*(short *)(param_1 + 0x5e) == 1) goto LAB_c0286db0;
    *(uint *)(param_1 + 0x14) = uVar6 + iVar3;
  }
  else {
    if (sVar1 == 2) {
      param_9[3] = -sVar17;
      param_9[2] = -sVar14;
      iVar13 = ((int)sVar14 - (int)sVar15) * 0x40;
      *param_9 = -sVar15;
      param_9[1] = -sVar16;
      *param_3 = uVar7 * -0x40;
      iVar20 = ((int)sVar17 - (int)sVar16) * 0x40;
      param_3[1] = 0;
      *param_4 = iVar20 + uVar9 * -0x40;
      param_4[1] = iVar13 + uVar10 * -0x40;
      *param_5 = uVar9 * -0x40;
      param_5[1] = sVar15 * -0x40;
      param_6[1] = uVar8 * -0x40;
      *param_6 = 0;
      param_7[1] = iVar13 + uVar12 * -0x40;
      *param_7 = iVar20 + uVar11 * -0x40;
      *param_8 = sVar16 * -0x40;
      param_8[1] = uVar12 * -0x40;
      uVar4 = (int)(*(ushort *)(param_1 + 0x3c) * uVar18 + 0x1f) >> 3 & 0xfffc;
      iVar13 = uVar4 * *(ushort *)(param_1 + 0x3a);
      *(short *)(param_1 + 0x40) = (short)uVar4;
    }
    else {
      if (sVar1 != 3) {
        return 0x1802;
      }
      *param_9 = -sVar17;
      param_9[2] = -sVar16;
      param_9[3] = sVar14;
      param_9[1] = sVar15;
      iVar21 = ((int)sVar15 - (int)sVar14) * 0x40;
      param_3[1] = uVar7 * -0x40;
      *param_3 = 0;
      param_4[1] = uVar9 * -0x40;
      *param_4 = iVar21 + uVar10 * 0x40;
      param_5[1] = iVar20 + sVar17 * -0x40;
      *param_5 = 0;
      *param_6 = uVar8 * 0x40;
      param_6[1] = 0;
      *param_7 = iVar21 + iVar13;
      param_7[1] = uVar11 * -0x40;
      *param_8 = ((int)sVar15 + sVar14 * -2) * 0x40 + iVar13;
      param_8[1] = 0;
      uVar4 = (int)(*(ushort *)(param_1 + 0x3a) * uVar18 + 0x1f) >> 3 & 0xfffc;
      iVar13 = uVar4 * *(ushort *)(param_1 + 0x3c);
      *(short *)(param_1 + 0x40) = (short)uVar4;
    }
    *(int *)(param_1 + 0x10) = iVar13;
    *(uint *)(param_1 + 0x14) = uVar6;
    if (*(short *)(param_1 + 0x5e) == 1) goto LAB_c0286db0;
    *(uint *)(param_1 + 0x14) = uVar6 + iVar3;
  }
  *(int *)(param_1 + 0x18) = iVar3;
LAB_c0286db0:
  *param_10 = *(undefined2 *)(param_1 + 0x40);
  *param_11 = *(undefined4 *)(param_1 + 0x10);
  *param_12 = *(undefined4 *)(param_1 + 0x14);
  return 0;
}



/* c0286e08 FUN_c0286e08 */

/* Boundary evidence: original MIPS .pdata c0286e08..c0287003. Semantic name remains unreviewed. */

void FUN_c0286e08(short *param_1,undefined4 param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  
  iVar6 = (int)(param_1[4] % 6);
  if (iVar6 < 0) {
    iVar6 = (iVar6 + 6) * 0x10000 >> 0x10;
  }
  sVar1 = param_3[6];
  sVar2 = param_3[4];
  uVar10 = 0;
  if (param_3[1] != param_3[2]) {
    do {
      pbVar3 = (byte *)((int)*param_1 * uVar10 + *(int *)(param_1 + 0x14));
      pbVar11 = pbVar3 + *param_1;
      puVar8 = (undefined1 *)((int)*param_3 * uVar10 + *(int *)(param_3 + 0x14));
      *puVar8 = (&DAT_c029a26c)[*pbVar3 >> (iVar6 + 2U & 0x1f)];
      if (1 < (uint)((int)sVar1 - (int)sVar2)) {
        pbVar13 = pbVar3 + 1;
        iVar12 = ((int)sVar1 - (int)sVar2) - 1;
        uVar9 = (0xe - iVar6) % 8 & 0xffff;
        do {
          puVar8 = puVar8 + 1;
          iVar4 = (2 - uVar9) * 0x10000;
          uVar5 = iVar4 >> 0x10;
          uVar7 = 0;
          if ((int)uVar5 < 0) {
            uVar7 = (uint)(short)-(short)((uint)iVar4 >> 0x10);
            uVar5 = 0;
          }
          uVar5 = (uint)(byte)(((&DAT_c029a2ac)[uVar9] & *pbVar3) >> (uVar5 & 0x1f)) <<
                  (uVar7 & 0x1f) & 0xffff;
          if (pbVar13 < pbVar11) {
            uVar5 = (*pbVar13 >> (10 - uVar9 & 0x1f)) + uVar5 & 0xffff;
          }
          uVar9 = uVar9 + 6 & 0xffff;
          *puVar8 = (&DAT_c029a26c)[uVar5];
          if (7 < uVar9) {
            uVar9 = uVar9 % 8;
            pbVar3 = pbVar3 + 1;
            pbVar13 = pbVar13 + 1;
          }
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)((int)param_3[1] - (int)param_3[2]));
  }
  return;
}



/* c0287004 FUN_c0287004 */

/* Boundary evidence: original MIPS .pdata c0287004..c0287277. Semantic name remains unreviewed. */

undefined4
FUN_c0287004(int param_1,int param_2,int param_3,byte *param_4,byte *param_5,byte param_6,
            undefined4 *param_7,byte *param_8)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte local_18 [8];
  
  pbVar2 = local_18;
  pbVar7 = local_18;
  pbVar4 = local_18;
  local_18[0] = 0;
  if (param_3 < param_1 + -1) {
    pbVar11 = param_5 + param_2;
    if (param_5 != param_4 + param_2 + -1) {
      pbVar2 = pbVar11 + 1;
    }
    uVar3 = (uint)param_6;
    bVar8 = *pbVar11;
    uVar9 = uVar3 + 1;
    uVar10 = (uint)(*pbVar2 >> (7 - uVar3 & 0x1f)) | (uint)bVar8 << (uVar9 & 0x1f) & 0xff;
    uVar6 = DAT_c029a6cc & uVar10;
    if (((&DAT_c029a6cc)[uVar3] & bVar8) == 0) {
      if (uVar6 != 0) goto LAB_c02870cc;
      pbVar2 = local_18;
      if ((param_5 != param_4) && (pbVar4 = param_5 + -1, pbVar2 = local_18, param_5 != param_4)) {
        pbVar2 = pbVar11 + -1;
      }
      iVar5 = (int)(char)(&DAT_c029a2b4)
                         [(uint)*pbVar2 << (uVar9 & 0x1f) & 0xff |
                          (uint)(bVar8 >> (7 - uVar3 & 0x1f))];
      if (((7 < iVar5) || (iVar5 < 2)) ||
         ((((uint)(*param_5 >> (7 - uVar3 & 0x1f)) | (uint)*pbVar4 << (uVar9 & 0x1f) & 0xff) &
          (uint)(byte)(&DAT_c029a6c1)[iVar5]) != (uint)(byte)(&DAT_c029a6c1)[iVar5]))
      goto LAB_c028725c;
      iVar5 = (iVar5 + uVar3 + -7) * 0x1000000;
      bVar8 = (byte)((uint)iVar5 >> 0x18);
      if (iVar5 >> 0x18 < 0) {
        *param_8 = bVar8 + 8;
        *param_7 = pbVar2;
      }
      else {
        *param_8 = bVar8;
        *param_7 = pbVar11;
      }
    }
    else if (uVar6 == 0) {
      *param_8 = param_6;
      *param_7 = pbVar11;
    }
    else {
LAB_c02870cc:
      if (param_5 != param_4 + param_2 + -1) {
        pbVar7 = param_5 + 1;
      }
      iVar5 = (int)(char)(&DAT_c029a3b4)[uVar10];
      if (((iVar5 == 8) || (4 < iVar5)) ||
         ((((uint)(*pbVar7 >> (7 - uVar3 & 0x1f)) | (uint)*param_5 << (uVar9 & 0x1f) & 0xff) &
          (uint)(byte)(&DAT_c029a6b5)[iVar5]) != 0)) goto LAB_c028725c;
      iVar5 = (iVar5 + uVar3 + 1) * 0x1000000;
      bVar8 = (byte)((uint)iVar5 >> 0x18);
      if (iVar5 >> 0x18 < 8) {
        *param_8 = bVar8;
        *param_7 = pbVar11;
      }
      else {
        *param_8 = bVar8 - 8;
        *param_7 = pbVar2;
      }
    }
    uVar1 = 1;
  }
  else {
LAB_c028725c:
    uVar1 = 0;
  }
  return uVar1;
}



/* c0287278 FUN_c0287278 */

/* Boundary evidence: original MIPS .pdata c0287278..c02873ef. Semantic name remains unreviewed. */

void FUN_c0287278(ushort *param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  ushort uVar10;
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar9 = (uint)*param_1;
  pbVar7 = *(byte **)(param_1 + 0x14);
  pbVar6 = pbVar7 + (uVar9 - 1);
  if (uVar2 != uVar3) {
    uVar10 = 0;
    pbVar5 = pbVar6;
    do {
      while (pbVar4 = pbVar5, pbVar7 < pbVar4) {
        pbVar5 = pbVar4 + -1;
        bVar1 = *pbVar4;
        uVar8 = (uint)*pbVar5;
        if ((bVar1 != 0) || (uVar8 != 0)) {
          *pbVar4 = (byte)((((((uVar8 << 1 | uVar8) << 1 | uVar8) << 1 | uVar8) << 1 | uVar8) << 1 |
                           uVar8) << 2) |
                    (byte)((byte)((byte)((byte)((byte)(bVar1 >> 1 | bVar1) >> 1 | bVar1) >> 1 |
                                        bVar1) >> 1 | bVar1) >> 1 | bVar1) >> 1 | bVar1;
        }
      }
      bVar1 = *pbVar4;
      uVar10 = uVar10 + 1;
      *pbVar4 = (byte)((byte)((byte)((byte)((byte)(bVar1 >> 1 | bVar1) >> 1 | bVar1) >> 1 | bVar1)
                              >> 1 | bVar1) >> 1 | bVar1) >> 1 | bVar1;
      pbVar7 = pbVar7 + uVar9;
      pbVar6 = pbVar6 + uVar9;
      pbVar5 = pbVar6;
    } while (uVar10 < (ushort)(uVar2 - uVar3));
  }
  return;
}



/* c02873f0 FUN_c02873f0 */

/* Boundary evidence: original MIPS .pdata c02873f0..c028798f. Semantic name remains unreviewed. */

void FUN_c02873f0(uint param_1,ushort *param_2,ushort *param_3)

{
  undefined1 uVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  byte *pbVar16;
  uint uVar17;
  int iVar18;
  byte *pbVar19;
  byte local_158 [2];
  ushort local_156;
  byte local_154 [2];
  ushort local_152;
  ushort local_150;
  int local_14c;
  byte *local_148;
  byte *local_144;
  uint local_140;
  byte *local_13c;
  uint local_138;
  byte *local_134;
  byte *local_130;
  uint local_12c;
  ushort *local_128;
  int local_120 [48];
  byte local_60 [48];
  uint local_30;
  
  local_128 = param_3;
  local_30 = DAT_c029ac78;
  uVar5 = (uint)(ushort)(param_2[1] - param_2[2]);
  local_152 = param_2[1] - param_2[2];
  if ((param_1 < 0x19) && (local_12c = uVar5, uVar5 < 0x31)) {
    uVar4 = (uint)*param_2;
    iVar10 = *(int *)(param_3 + 0x14);
    local_150 = *param_2;
    if (uVar5 != 0) {
      uVar11 = 0;
      puVar9 = *(undefined1 **)(param_2 + 0x14);
      do {
        puVar8 = puVar9 + uVar4;
        if (puVar9 < puVar8) {
          iVar18 = iVar10 - (int)puVar9;
          do {
            uVar1 = *puVar9;
            puVar7 = puVar9 + iVar18;
            puVar9 = puVar9 + 1;
            *puVar7 = uVar1;
          } while (puVar9 < puVar8);
        }
        uVar11 = uVar11 + 1 & 0xffff;
        iVar10 = uVar4 + iVar10;
        puVar9 = puVar8;
      } while (uVar11 < uVar5);
    }
    pbVar12 = *(byte **)(param_3 + 0x14);
    local_154[0] = 0;
    local_14c = *(int *)(param_2 + 0x14);
    local_144 = pbVar12;
    local_156 = 0;
    uVar11 = 0;
    if (uVar5 != 0) {
      uVar11 = (uint)DAT_c029a6d3;
      local_140 = 0;
      do {
        local_130 = (byte *)((uVar4 - 1) + local_14c);
        local_148 = local_154;
        if (pbVar12 <= pbVar12 + (uVar4 - 1)) {
          pbVar16 = pbVar12 + ((int)local_130 - local_14c);
          local_134 = pbVar16;
          uVar13 = local_140;
          pbVar19 = local_130;
          local_144 = pbVar12;
LAB_c028752c:
          uVar5 = (uint)*pbVar16;
          if ((uVar5 == 0) || ((uVar5 == 0xff && ((byte)-((char)*local_148 >> 7) == 1)))) {
            uVar5 = 8;
          }
          else {
            uVar5 = (uint)(byte)(&DAT_c029a4b4)
                                [((~(uint)*pbVar19 & ~uVar5 & 0x7f) << 1 |
                                 (byte)~-((char)*local_148 >> 7) & uVar11) & uVar5];
            uVar13 = (uint)local_156;
          }
          local_138 = uVar5;
          pbVar14 = pbVar19;
          if (uVar5 != 8) {
            uVar11 = (uint)local_152;
            uVar17 = (uint)local_150;
            iVar10 = 0;
            uVar15 = 0;
            local_158[0] = (byte)uVar5;
            local_13c = pbVar16;
            do {
              local_120[uVar15] = (int)local_13c;
              local_60[uVar15] = (byte)uVar5;
              bVar2 = false;
              iVar18 = (int)((-1 - uVar5) * 0x10000) >> 0x10;
              uVar6 = (uint)((&DAT_c029a6c1)[uVar5] & *local_13c);
              pbVar19 = local_13c;
              do {
                if (9 < iVar18) break;
                if (pbVar12 + (uVar4 - 1) < local_13c) {
                  iVar18 = 10;
                }
                else {
                  pbVar16 = &DAT_c029a5b4 + uVar6;
                  bVar2 = *pbVar16 < 8;
                  pbVar19 = pbVar19 + 1;
                  uVar6 = (uint)*pbVar19;
                  iVar18 = (int)(((uint)*pbVar16 + iVar18) * 0x10000) >> 0x10;
                }
              } while (!bVar2);
              if (iVar18 < 5) {
                uVar6 = 0;
              }
              else if (iVar18 < 10) {
                uVar6 = iVar18 - 4;
              }
              else {
                uVar6 = 6;
              }
              iVar10 = (uVar6 & 0xffff) + iVar10;
              uVar15 = uVar15 + 1 & 0xffff;
              iVar18 = FUN_c0287004(uVar11,uVar17,uVar13,pbVar12,local_13c,(byte)uVar5,&local_13c,
                                    local_158);
              uVar13 = uVar13 + 1 & 0xffff;
              pbVar12 = pbVar12 + uVar4;
              if (iVar18 == 0) goto LAB_c0287718;
              uVar5 = (uint)local_158[0];
            } while( true );
          }
          goto LAB_c0287890;
        }
LAB_c02878d0:
        local_14c = uVar4 + local_14c;
        uVar13 = local_140 + 1 & 0xffff;
        pbVar12 = pbVar12 + uVar4;
        local_144 = pbVar12;
        local_156 = (ushort)(local_140 + 1);
        local_140 = uVar13;
      } while (uVar13 < uVar5);
      uVar11 = (uint)local_152;
    }
    puVar9 = *(undefined1 **)(local_128 + 0x14);
    if ((puVar9 < puVar9 + *local_128 * uVar11) &&
       (iVar10 = (int)(puVar9 + *local_128 * uVar11) - (int)puVar9, iVar10 != 0)) {
      puVar8 = puVar9 + iVar10;
      do {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      } while (puVar9 != puVar8);
    }
  }
  else {
    FUN_c0287278(param_2);
  }
  FUN_c029919c(local_30);
  return;
LAB_c0287718:
  if (uVar15 == 0) {
    trap(0x1c00);
  }
  uVar5 = ((uVar15 >> 1) + iVar10) / uVar15 & 0xff;
  if (uVar5 < 2) {
    uVar5 = 2;
  }
  pbVar12 = local_144 + (uVar4 - 1);
  uVar11 = 0;
  if (uVar15 != 0) {
    pbVar19 = local_130;
    do {
      uVar13 = (uint)local_60[uVar11];
      pbVar16 = (byte *)local_120[uVar11];
      bVar3 = (byte)(&DAT_c029a6b4)[uVar5] >> (uVar13 + 1 & 0x1f);
      uVar17 = (uint)(byte)(&DAT_c029a6b4)[uVar5] << (7 - uVar13 & 0x1f);
      uVar6 = 8;
      if (bVar3 != 0) {
        uVar6 = (uint)(byte)(&DAT_c029a5b4)[(&DAT_c029a6c1)[uVar13] & *pbVar19];
        *pbVar19 = (&DAT_c029a6b4)[uVar6] & bVar3 | *pbVar19;
      }
      if ((((uVar17 & 0xff) != 0) && (uVar6 == 8)) && (pbVar16 < pbVar12)) {
        pbVar19[1] = (&DAT_c029a6b4)[(byte)(&DAT_c029a5b4)[pbVar19[1]]] & (byte)uVar17 | pbVar19[1];
      }
      if ((int)uVar11 < (int)(uVar15 - 1)) {
        pbVar19 = pbVar19 + (local_120[uVar11 + 1] - (int)pbVar16);
      }
      uVar11 = uVar11 + 1 & 0xffff;
      pbVar12 = pbVar12 + uVar4;
    } while (uVar11 < uVar15);
  }
  uVar11 = (uint)DAT_c029a6d3;
  pbVar12 = local_144;
  pbVar14 = local_130;
  pbVar16 = local_134;
LAB_c0287890:
  uVar13 = (uint)local_156;
  pbVar19 = pbVar14;
  if (local_138 != 8) goto LAB_c028752c;
  pbVar16 = pbVar16 + -1;
  pbVar19 = pbVar14 + -1;
  local_148 = pbVar14;
  local_130 = pbVar19;
  local_134 = pbVar16;
  uVar5 = local_12c;
  if (pbVar16 < pbVar12) goto LAB_c02878d0;
  goto LAB_c028752c;
}



/* c0287990 FUN_c0287990 */

/* Boundary evidence: original MIPS .pdata c0287990..c02879ab. Semantic name remains unreviewed. */

void FUN_c0287990(void)

{
  FUN_c0298894();
  return;
}



/* c02879ac FUN_c02879ac */

undefined4 * FUN_c02879ac(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 5;
  *param_1 = puVar1;
  param_1[1] = puVar1;
  *(undefined2 *)puVar1 = 0x7fff;
  *(undefined2 *)((int)param_1 + 0x16) = 0;
  param_1[6] = 0;
  param_1[2] = param_1 + 7;
  param_1[3] = (int)param_1 + param_2;
  param_1[4] = param_1;
  return param_1;
}



/* c02879e4 FUN_c02879e4 */

void FUN_c02879e4(int *param_1,short *param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  
  sVar2 = (short)((param_4 >> 1) + param_3 + 0x20 >> 6);
  sVar1 = *(short *)*param_1;
  while (sVar1 < sVar2) {
    param_1 = (int *)(*param_1 + 4);
    sVar1 = *(short *)*param_1;
  }
  *param_2 = sVar2;
  param_2[1] = -(short)param_4;
  *(int *)(param_2 + 2) = *param_1;
  *param_1 = (int)param_2;
  return;
}



/* c0287a50 FUN_c0287a50 */

int FUN_c0287a50(int param_1)

{
  return (*(int *)(param_1 + 8) - param_1) + -0x1c >> 3;
}



/* c0287a64 FUN_c0287a64 */

int FUN_c0287a64(short *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (; iVar2 = (int)*param_1, iVar2 < 0x7fff; param_1 = *(short **)(param_1 + 2)) {
    if (param_1[1] == 1) {
      iVar2 = -iVar2;
    }
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}



/* c0287aa8 FUN_c0287aa8 */

int FUN_c0287aa8(int param_1)

{
  return *(int *)(param_1 + 8) - param_1;
}



/* c0287ab4 FUN_c0287ab4 */

void FUN_c0287ab4(int *param_1)

{
  short sVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  
  iVar4 = param_1[4];
  psVar3 = (short *)((*param_1 - iVar4) + (int)param_1);
  param_1[1] = (param_1[1] - iVar4) + (int)param_1;
  *param_1 = (int)psVar3;
  param_1[2] = (int)param_1 + (param_1[2] - iVar4);
  param_1[3] = (param_1[3] - iVar4) + (int)param_1;
  while (*psVar3 < 0x7fff) {
    piVar2 = (int *)(psVar3 + 2);
    psVar3 = (short *)((*piVar2 - iVar4) + (int)param_1);
    *piVar2 = (int)psVar3;
  }
  psVar3 = (short *)param_1[1];
  sVar1 = *psVar3;
  while (sVar1 < 0x7fff) {
    piVar2 = (int *)(psVar3 + 2);
    psVar3 = (short *)((*piVar2 - iVar4) + (int)param_1);
    *piVar2 = (int)psVar3;
    sVar1 = *psVar3;
  }
  param_1[4] = (int)param_1;
  return;
}



/* c0287b60 FUN_c0287b60 */

int FUN_c0287b60(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_2 + 3U & 0xfffffffc;
  uVar3 = param_3 + 3U & 0xfffffffc;
  if ((param_1 & 4) == 0) {
    iVar1 = (uVar2 * 5 + uVar3) * 4;
  }
  else {
    iVar1 = uVar2 * 0x14 + uVar3 * 8;
  }
  return iVar1;
}



/* c0287bb4 FUN_c0287bb4 */

int FUN_c0287bb4(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 + 3U & 0xfffffffc;
  uVar2 = param_3 + 3U & 0xfffffffc;
  if ((param_1 & 4) == 0) {
    iVar1 = (uVar3 * 5 + uVar2) * 4;
  }
  else {
    iVar1 = ((param_4 + 3U & 0xfffffffc) + uVar2) * 8 + uVar3 * 0x14;
  }
  return iVar1;
}



/* c0287c10 FUN_c0287c10 */

void FUN_c0287c10(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(&DAT_c029ad1c + param_1 * 4) = param_2;
  *(undefined4 *)(&DAT_c029ad28 + param_1 * 4) = param_3;
  return;
}



/* c0287c38 FUN_c0287c38 */

undefined4 FUN_c0287c38(uint param_1,undefined4 param_2,undefined4 param_3)

{
  if (((param_1 & 2) == 0) && ((param_1 & 4) != 0)) {
    *(undefined4 *)(DAT_c029ad40 * 4 + DAT_c029ad34) = param_2;
    *(undefined4 *)(DAT_c029ad40 * 4 + DAT_c029ad38) = param_3;
    DAT_c029ad40 = DAT_c029ad40 + 1;
    if (DAT_c029ad3c < DAT_c029ad40) {
      return 0x1a00;
    }
  }
  return 0;
}



/* c0287cac FUN_c0287cac */

undefined4
FUN_c0287cac(uint param_1,int param_2,ushort param_3,int param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  
  *param_7 = DAT_c029ad14;
  *param_8 = DAT_c029ad18;
  if ((param_2 == 1) || (param_2 == 2)) {
    DAT_c029ace8 = DAT_c029acd4;
    DAT_c029acec = DAT_c029acdc;
    DAT_c029acf0 = DAT_c029acd8;
  }
  else {
    DAT_c029ace8 = DAT_c029acd8;
    DAT_c029acec = DAT_c029ace0;
    DAT_c029acf0 = DAT_c029ace4;
  }
  if ((param_1 & 2) == 0) {
    if ((param_2 == 2) || (param_2 == 3)) {
      DAT_c029ad08 = DAT_c029acf4;
      DAT_c029ad0c = DAT_c029acfc;
      DAT_c029ad10 = DAT_c029acf8;
    }
    else {
      DAT_c029ad08 = DAT_c029acf8;
      DAT_c029ad0c = DAT_c029ad00;
      DAT_c029ad10 = DAT_c029ad04;
    }
    if ((param_1 & 4) != 0) {
      if (0x3fff < DAT_c029ad40 + -1) {
        return 0x1305;
      }
      DAT_c029ad44 = ((short)DAT_c029ad40 + -1) * 4 | param_3;
      while (0 < param_4) {
        uVar1 = *param_5;
        param_5 = param_5 + 1;
        *(undefined4 *)(DAT_c029ad40 * 4 + DAT_c029ad34) = uVar1;
        *(undefined4 *)(DAT_c029ad40 * 4 + DAT_c029ad38) = *param_6;
        DAT_c029ad40 = DAT_c029ad40 + 1;
        param_6 = param_6 + 1;
        param_4 = param_4 + -1;
        if (DAT_c029ad3c < DAT_c029ad40) {
          return 0x1a00;
        }
      }
    }
  }
  return 0;
}



/* c028835c FUN_c028835c */

int FUN_c028835c(short param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  
  if ((param_2 < DAT_c029acc0) || (DAT_c029acbc <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar2 = (param_2 - DAT_c029acc0) * 4;
    psVar3 = *(short **)(iVar2 + DAT_c029acd4);
    psVar4 = *(short **)(iVar2 + DAT_c029acd8);
    iVar1 = 0;
    if (psVar3 < *(short **)(iVar2 + DAT_c029acdc)) {
      do {
        if (*psVar3 == param_1) {
          iVar1 = iVar1 + 1;
        }
        psVar3 = psVar3 + DAT_c029ad46;
        if (*psVar4 == param_1) {
          iVar1 = iVar1 + 1;
        }
        psVar4 = psVar4 + DAT_c029ad46;
      } while (psVar3 < *(short **)(iVar2 + DAT_c029acdc));
    }
  }
  return iVar1;
}



/* c0288410 FUN_c0288410 */

int FUN_c0288410(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  
  if ((param_1 < DAT_c029aca8) || (DAT_c029acac <= param_1)) {
    iVar1 = 0;
  }
  else {
    iVar2 = (param_1 - DAT_c029aca8) * 4;
    psVar3 = *(short **)(iVar2 + DAT_c029acf4);
    psVar4 = *(short **)(iVar2 + DAT_c029acf8);
    iVar1 = 0;
    if (psVar3 < *(short **)(iVar2 + DAT_c029acfc)) {
      do {
        if (*psVar3 == param_2) {
          iVar1 = iVar1 + 1;
        }
        psVar3 = psVar3 + DAT_c029ad46;
        if (*psVar4 == param_2) {
          iVar1 = iVar1 + 1;
        }
        psVar4 = psVar4 + DAT_c029ad46;
      } while (psVar3 < *(short **)(iVar2 + DAT_c029acfc));
    }
  }
  return iVar1;
}



/* c02884c4 FUN_c02884c4 */

/* Boundary evidence: original MIPS .pdata c02884c4..c0288583. Semantic name remains unreviewed. */

uint FUN_c02884c4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((((param_2 < DAT_c029aca8) || (DAT_c029acac <= param_2)) || (param_3 < DAT_c029acb4)) ||
     (DAT_c029acb0 <= param_3)) {
LAB_c0288574:
    uVar1 = 0;
  }
  else {
    if ((param_3 < DAT_c029acc4) && (DAT_c029acc8 <= param_3)) {
      iVar2 = ((DAT_c029acc4 - param_3) + -1) * DAT_c029acb8 + param_1;
    }
    else {
      iVar2 = DAT_c029acd0;
      if (param_3 != DAT_c029accc) goto LAB_c0288574;
    }
    uVar1 = FUN_c0298a90(param_2 - DAT_c029aca8,iVar2);
  }
  return uVar1;
}



/* c0288584 FUN_c0288584 */

/* Boundary evidence: original MIPS .pdata c0288584..c028860f. Semantic name remains unreviewed. */

undefined4 FUN_c0288584(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((((param_2 < DAT_c029aca8) || (DAT_c029acac <= param_2)) || (param_3 < DAT_c029acc8)) ||
     (DAT_c029acc4 <= param_3)) {
    uVar1 = 0x1302;
  }
  else {
    uVar1 = FUN_c0298ac0(param_2 - DAT_c029aca8,
                         ((DAT_c029acc4 - param_3) + -1) * DAT_c029acb8 + param_1);
  }
  return uVar1;
}



/* c0288610 FUN_c0288610 */

/* Boundary evidence: original MIPS .pdata c0288610..c028862b. Semantic name remains unreviewed. */

void FUN_c0288610(int param_1,void *param_2)

{
  FUN_c02989a8(param_1,param_2);
  return;
}



/* c028862c FUN_c028862c */

/* Boundary evidence: original MIPS .pdata c028862c..c0288647. Semantic name remains unreviewed. */

void FUN_c028862c(undefined4 *param_1)

{
  FUN_c0298af8(param_1);
  return;
}



/* c0288648 FUN_c0288648 */

/* Boundary evidence: original MIPS .pdata c0288648..c028869b. Semantic name remains unreviewed. */

undefined4 FUN_c0288648(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_c02879e4(param_1,(short *)param_1[2],param_2,param_3);
  iVar2 = param_1[2];
  param_1[2] = iVar2 + 8U;
  uVar1 = 0x1a00;
  if (iVar2 + 8U <= (uint)param_1[3]) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c028869c FUN_c028869c */

/* Boundary evidence: original MIPS .pdata c028869c..c02886ef. Semantic name remains unreviewed. */

undefined4 FUN_c028869c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  FUN_c02879e4((int *)(param_1 + 4),*(short **)(param_1 + 8),param_2,param_3);
  uVar2 = *(int *)(param_1 + 8) + 8;
  *(uint *)(param_1 + 8) = uVar2;
  uVar1 = 0x1a00;
  if (uVar2 <= *(uint *)(param_1 + 0xc)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c02886f0 FUN_c02886f0 */

/* Boundary evidence: original MIPS .pdata c02886f0..c028872b. Semantic name remains unreviewed. */

void FUN_c02886f0(int *param_1)

{
  if (param_1 != (int *)param_1[4]) {
    FUN_c0287ab4(param_1);
  }
  FUN_c0287a64((short *)*param_1);
  return;
}



/* c028872c FUN_c028872c */

/* Boundary evidence: original MIPS .pdata c028872c..c0288767. Semantic name remains unreviewed. */

void FUN_c028872c(int *param_1)

{
  if (param_1 != (int *)param_1[4]) {
    FUN_c0287ab4(param_1);
  }
  FUN_c0287a64((short *)param_1[1]);
  return;
}



/* c0288768 FUN_c0288768 */

/* Boundary evidence: original MIPS .pdata c0288768..c0288bdf. Semantic name remains unreviewed. */

undefined4
FUN_c0288768(short *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,int param_7
            ,int param_8,uint param_9,int *param_10)

{
  short *psVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  
  DAT_c029acb0 = (int)*param_1;
  DAT_c029acb4 = (int)param_1[2];
  DAT_c029aca8 = (int)param_1[1];
  DAT_c029acac = (int)param_1[3];
  if (((param_2 & 2) == 0) && ((param_2 & 4) != 0)) {
    DAT_c029ad46 = 2;
    DAT_c029ad48 = 1;
    if ((param_3 == DAT_c029acb0) && (param_4 == DAT_c029acb4)) {
      DAT_c029ad14 = &LAB_c0287fc8;
    }
    else {
      DAT_c029ad14 = &LAB_c0288274;
    }
    DAT_c029ad18 = &LAB_c02880b0;
  }
  else {
    DAT_c029ad46 = 1;
    DAT_c029ad48 = 0;
    if ((param_3 == DAT_c029acb0) && (param_4 == DAT_c029acb4)) {
      DAT_c029ad14 = &LAB_c0287e10;
    }
    else {
      DAT_c029ad14 = &LAB_c0288198;
    }
    DAT_c029ad18 = &LAB_c0287eec;
  }
  iVar9 = (param_3 - param_4) * 4;
  DAT_c029acbc = param_3;
  DAT_c029acc0 = param_4;
  DAT_c029acd4 = (int *)FUN_c028ab48(iVar9);
  if ((((DAT_c029acd4 != (int *)0x0) &&
       (DAT_c029acd8 = (int *)FUN_c028ab48(iVar9), DAT_c029acd8 != (int *)0x0)) &&
      (DAT_c029acdc = (int *)FUN_c028ab48(iVar9), DAT_c029acdc != (int *)0x0)) &&
     ((DAT_c029ace0 = (int *)FUN_c028ab48(iVar9), DAT_c029ace0 != (int *)0x0 &&
      (DAT_c029ace4 = (int *)FUN_c028ab48(iVar9), DAT_c029ace4 != (int *)0x0)))) {
    DAT_c029ad40 = 0;
    DAT_c029ad3c = param_9;
    if ((-1 < param_7) &&
       ((param_7 < 0x8000000 &&
        (iVar9 = FUN_c028ab48(param_7 << ((int)DAT_c029ad48 + 2U & 0x1f)), iVar9 != 0)))) {
      if (param_10 != (int *)param_10[4]) {
        FUN_c0287ab4(param_10);
      }
      iVar6 = (int)(short)DAT_c029acc0;
      psVar8 = (short *)*param_10;
      iVar10 = 0;
      piVar2 = DAT_c029acd8;
      piVar3 = DAT_c029acdc;
      piVar4 = DAT_c029ace4;
      piVar5 = DAT_c029ace0;
      piVar11 = DAT_c029acd4;
      if (iVar6 < (short)DAT_c029acbc) {
        do {
          if (*psVar8 <= iVar6) {
            do {
              psVar1 = psVar8 + 1;
              psVar8 = *(short **)(psVar8 + 2);
              iVar10 = (((int)*psVar1 << ((int)DAT_c029ad48 & 0x1fU)) + iVar10) * 0x10000 >> 0x10;
            } while (*psVar8 <= iVar6);
          }
          *piVar11 = iVar9;
          iVar7 = iVar10 * 2 + iVar9;
          *piVar3 = iVar9;
          *piVar2 = iVar7;
          iVar9 = iVar10 * 2 + iVar7;
          *piVar5 = iVar7;
          *piVar4 = iVar9;
          iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
          piVar11 = piVar11 + 1;
          piVar3 = piVar3 + 1;
          piVar2 = piVar2 + 1;
          piVar5 = piVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar6 < (short)DAT_c029acbc);
      }
      if ((param_2 & 2) != 0) {
        return 0;
      }
      iVar9 = ((int)param_1[3] - (int)param_1[1]) * 4;
      DAT_c029acf4 = (int *)FUN_c028ab84(iVar9);
      if ((((DAT_c029acf4 != (int *)0x0) &&
           (DAT_c029acf8 = (int *)FUN_c028ab84(iVar9), DAT_c029acf8 != (int *)0x0)) &&
          (DAT_c029acfc = (int *)FUN_c028ab84(iVar9), DAT_c029acfc != (int *)0x0)) &&
         ((DAT_c029ad00 = (int *)FUN_c028ab84(iVar9), DAT_c029ad00 != (int *)0x0 &&
          (DAT_c029ad04 = (int *)FUN_c028ab84(iVar9), DAT_c029ad04 != (int *)0x0)))) {
        if (param_5 != 0) {
          DAT_c029acd0 = FUN_c028ab84(param_6);
          DAT_c029accc = 0x7fffffff;
        }
        if (((-1 < param_8) && (param_8 < 0x8000000)) &&
           (iVar9 = FUN_c028ab84(param_8 << ((int)DAT_c029ad48 + 2U & 0x1f)), iVar9 != 0)) {
          iVar6 = (int)param_1[1];
          psVar8 = (short *)param_10[1];
          iVar10 = 0;
          piVar2 = DAT_c029acfc;
          piVar3 = DAT_c029ad04;
          piVar4 = DAT_c029ad00;
          piVar5 = DAT_c029acf8;
          piVar11 = DAT_c029acf4;
          if (iVar6 < param_1[3]) {
            do {
              if (*psVar8 <= iVar6) {
                do {
                  psVar1 = psVar8 + 1;
                  psVar8 = *(short **)(psVar8 + 2);
                  iVar10 = (((int)*psVar1 << ((int)DAT_c029ad48 & 0x1fU)) + iVar10) * 0x10000 >>
                           0x10;
                } while (*psVar8 <= iVar6);
              }
              *piVar11 = iVar9;
              iVar7 = iVar10 * 2 + iVar9;
              *piVar2 = iVar9;
              *piVar5 = iVar7;
              iVar9 = iVar10 * 2 + iVar7;
              *piVar4 = iVar7;
              iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
              *piVar3 = iVar9;
              piVar11 = piVar11 + 1;
              piVar2 = piVar2 + 1;
              piVar5 = piVar5 + 1;
              piVar4 = piVar4 + 1;
              piVar3 = piVar3 + 1;
            } while (iVar6 < param_1[3]);
          }
          if ((param_2 & 4) == 0) {
            return 0;
          }
          if ((-1 < (int)param_9) && (param_9 < 0x10000000)) {
            DAT_c029ad34 = FUN_c028ab84(param_9 << 2);
            if ((DAT_c029ad34 != 0) &&
               (DAT_c029ad38 = FUN_c028ab84(param_9 << 2), DAT_c029ad38 != 0)) {
              return 0;
            }
          }
        }
      }
    }
  }
  return 0x1a01;
}



/* c0288be0 FUN_c0288be0 */

/* Boundary evidence: original MIPS .pdata c0288be0..c0288e1f. Semantic name remains unreviewed. */

undefined4 FUN_c0288be0(short *param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  short sVar7;
  int iVar8;
  
  sVar1 = *param_1;
  iVar8 = (int)sVar1;
  if ((param_5 & 1) != 0) {
    sVar7 = (short)(param_3 + 1);
    iVar2 = FUN_c0288410(iVar8 + -1,sVar7);
    iVar3 = FUN_c0288410(iVar8,sVar7);
    iVar4 = FUN_c028835c(sVar1,param_3 + 1);
    if (iVar2 + iVar3 + iVar4 < 2) {
      return 0;
    }
    iVar2 = FUN_c028835c(sVar1,param_3 + -1);
    iVar3 = FUN_c0288410(iVar8 + -1,(short)param_3);
    iVar4 = FUN_c0288410(iVar8,(short)param_3);
    if (iVar2 + iVar3 + iVar4 < 2) {
      return 0;
    }
  }
  if (((iVar8 <= DAT_c029aca8) || (uVar5 = FUN_c02884c4(param_4,iVar8 + -1,param_3), uVar5 == 0)) &&
     ((DAT_c029acac <= iVar8 || (uVar5 = FUN_c02884c4(param_4,iVar8,param_3), uVar5 == 0)))) {
    if ((param_5 & 4) == 0) {
      iVar8 = iVar8 + -1;
    }
    else {
      iVar8 = (uint)((ushort)param_1[1] >> 2) * 4;
      iVar8 = (**(code **)(&DAT_c029ad1c + ((ushort)param_1[1] & 3) * 4))
                        (param_3,iVar8 + DAT_c029ad34,iVar8 + DAT_c029ad38);
      iVar2 = (uint)(*(ushort *)(param_2 + 2) >> 2) * 4;
      iVar2 = (**(code **)(&DAT_c029ad1c + (*(ushort *)(param_2 + 2) & 3) * 4))
                        (param_3,iVar2 + DAT_c029ad34,iVar2 + DAT_c029ad38);
      iVar8 = iVar2 + iVar8 + -1 >> 7;
    }
    if (iVar8 < DAT_c029aca8) {
      iVar8 = DAT_c029aca8;
    }
    if (DAT_c029acac <= iVar8) {
      iVar8 = DAT_c029acac + -1;
    }
    uVar6 = FUN_c0288584(param_4,iVar8,param_3);
    return uVar6;
  }
  return 0;
}



/* c0288e20 FUN_c0288e20 */

/* Boundary evidence: original MIPS .pdata c0288e20..c02890c3. Semantic name remains unreviewed. */

undefined4 FUN_c0288e20(short *param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = DAT_c029acc8;
  iVar9 = DAT_c029acc4;
  sVar1 = *param_1;
  iVar8 = (int)sVar1;
  if (iVar8 < DAT_c029acc8) {
    return 0;
  }
  if (DAT_c029acc4 < iVar8) {
    return 0;
  }
  if ((param_5 & 1) != 0) {
    iVar2 = FUN_c0288410(param_3 + -1,sVar1);
    iVar3 = FUN_c028835c((short)param_3,iVar8 + -1);
    iVar4 = FUN_c028835c((short)param_3,iVar8);
    if (iVar2 + iVar3 + iVar4 < 2) {
      return 0;
    }
    sVar7 = (short)(param_3 + 1);
    iVar2 = FUN_c028835c(sVar7,iVar8 + -1);
    iVar3 = FUN_c028835c(sVar7,iVar8);
    iVar4 = FUN_c0288410(param_3 + 1,sVar1);
    if (iVar2 + iVar3 + iVar4 < 2) {
      return 0;
    }
  }
  if (((iVar8 <= DAT_c029acb4) ||
      (uVar5 = FUN_c02884c4(param_4,param_3,iVar8 + -1), iVar9 = DAT_c029acc4, iVar10 = DAT_c029acc8
      , uVar5 == 0)) &&
     ((DAT_c029acb0 <= iVar8 ||
      (uVar5 = FUN_c02884c4(param_4,param_3,iVar8), iVar9 = DAT_c029acc4, iVar10 = DAT_c029acc8,
      uVar5 == 0)))) {
    if ((param_5 & 4) == 0) {
      iVar8 = iVar8 + -1;
    }
    else {
      iVar9 = (uint)((ushort)param_1[1] >> 2) * 4;
      iVar9 = (**(code **)(&DAT_c029ad28 + ((ushort)param_1[1] & 3) * 4))
                        (param_3,iVar9 + DAT_c029ad34,iVar9 + DAT_c029ad38);
      iVar10 = (uint)(*(ushort *)(param_2 + 2) >> 2) * 4;
      iVar10 = (**(code **)(&DAT_c029ad28 + (*(ushort *)(param_2 + 2) & 3) * 4))
                         (param_3,iVar10 + DAT_c029ad34,iVar10 + DAT_c029ad38);
      iVar8 = iVar10 + iVar9 + -1 >> 7;
      iVar9 = DAT_c029acc4;
      iVar10 = DAT_c029acc8;
    }
    if (iVar8 < DAT_c029acb4) {
      iVar8 = DAT_c029acb4;
    }
    if (DAT_c029acb0 <= iVar8) {
      iVar8 = DAT_c029acb0 + -1;
    }
    if ((iVar10 <= iVar8) && (iVar8 < iVar9)) {
      uVar6 = FUN_c0288584(param_4,param_3,iVar8);
      return uVar6;
    }
  }
  return 0;
}



/* c02890c4 FUN_c02890c4 */

/* Boundary evidence: original MIPS .pdata c02890c4..c02892bf. Semantic name remains unreviewed. */

int FUN_c02890c4(int param_1,ushort param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  
  iVar13 = DAT_c029acc4 - DAT_c029acc8;
  iVar3 = ((DAT_c029acc4 - DAT_c029acc0) + -1) * 4;
  iVar2 = (int)DAT_c029ad46;
  puVar9 = (undefined4 *)(iVar3 + DAT_c029acd8);
  puVar11 = (undefined4 *)(iVar3 + DAT_c029acdc);
  iVar6 = 0;
  iVar1 = DAT_c029acc4;
  puVar8 = (undefined4 *)(iVar3 + DAT_c029acd4);
  if (0 < iVar13) {
    do {
      psVar5 = (short *)*puVar9;
      psVar7 = (short *)*puVar11;
      puVar9 = puVar9 + -1;
      puVar11 = puVar11 + -1;
      for (psVar4 = (short *)*puVar8; psVar4 < psVar7; psVar4 = psVar4 + iVar2) {
        if (*psVar4 == *psVar5) {
          iVar1 = FUN_c0288be0(psVar4,(int)psVar5,(iVar1 - iVar6) + -1,param_1,param_2);
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar2 = (int)DAT_c029ad46;
          iVar1 = DAT_c029acc4;
        }
        psVar5 = psVar5 + iVar2;
      }
      iVar6 = iVar6 + 1;
      puVar8 = puVar8 + -1;
    } while (iVar6 < iVar13);
  }
  iVar6 = DAT_c029acac - DAT_c029aca8;
  iVar3 = 0;
  iVar1 = DAT_c029aca8;
  puVar8 = DAT_c029acf4;
  piVar10 = DAT_c029acfc;
  piVar12 = DAT_c029ad00;
  if (0 < iVar6) {
    do {
      iVar13 = *piVar10;
      psVar7 = (short *)*puVar8;
      puVar8 = puVar8 + 1;
      piVar10 = piVar10 + 1;
      psVar5 = (short *)(*piVar12 + iVar2 * -2);
      piVar12 = piVar12 + 1;
      for (psVar4 = (short *)(iVar13 + iVar2 * -2); psVar7 <= psVar4; psVar4 = psVar4 + -iVar2) {
        if (*psVar4 == *psVar5) {
          iVar1 = FUN_c0288e20(psVar4,(int)psVar5,iVar1 + iVar3,param_1,param_2);
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar2 = (int)DAT_c029ad46;
          iVar1 = DAT_c029aca8;
        }
        psVar5 = psVar5 + -iVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar6);
  }
  return 0;
}



/* c02892c0 FUN_c02892c0 */

/* Boundary evidence: original MIPS .pdata c02892c0..c02894b7. Semantic name remains unreviewed. */

int FUN_c02892c0(void *param_1,int param_2,int param_3,int param_4,int param_5,ushort param_6)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  void *pvVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  short *psVar15;
  short *psVar16;
  
  iVar13 = param_2 - param_3;
  iVar12 = param_4 >> 2;
  DAT_c029acb8 = param_4;
  DAT_c029acc4 = param_2;
  DAT_c029acc8 = param_3;
  iVar3 = FUN_c02989a8(iVar12 * iVar13,param_1);
  sVar2 = (short)DAT_c029aca8;
  if (iVar3 == 0) {
    iVar3 = ((DAT_c029acc4 - DAT_c029acc0) + -1) * 4;
    puVar8 = (undefined4 *)(iVar3 + DAT_c029acd4);
    puVar6 = (undefined4 *)(iVar3 + DAT_c029acd8);
    puVar7 = (undefined4 *)(iVar3 + DAT_c029acdc);
    iVar3 = 0;
    pvVar11 = param_1;
    if (0 < iVar13) {
      iVar10 = (int)DAT_c029ad46;
      do {
        psVar16 = (short *)*puVar6;
        psVar14 = (short *)*puVar8;
        psVar15 = (short *)*puVar7;
        puVar6 = puVar6 + -1;
        puVar8 = puVar8 + -1;
        puVar7 = puVar7 + -1;
        while (psVar14 < psVar15) {
          iVar9 = (int)*psVar14 - (int)sVar2;
          iVar4 = (int)*psVar16 - (int)sVar2;
          psVar14 = psVar14 + iVar10;
          psVar16 = psVar16 + iVar10;
          iVar5 = iVar9;
          if ((iVar9 < iVar4) || (bVar1 = iVar4 < iVar9, iVar5 = iVar4, iVar4 = iVar9, bVar1)) {
            iVar10 = FUN_c02989d4(iVar5,iVar4 + -1,(int)pvVar11);
            if (iVar10 != 0) {
              return iVar10;
            }
            iVar10 = (int)DAT_c029ad46;
          }
        }
        iVar3 = iVar3 + 1;
        pvVar11 = (void *)(iVar12 * 4 + (int)pvVar11);
      } while (iVar3 < iVar13);
    }
    if ((param_6 & 2) == 0) {
      iVar3 = FUN_c02890c4((int)param_1,param_6);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (param_5 != DAT_c029acc0) {
        iVar3 = FUN_c0298a68((undefined4 *)((int)pvVar11 + iVar12 * -8),DAT_c029acd0,iVar12);
        if (iVar3 != 0) {
          return iVar3;
        }
        DAT_c029accc = DAT_c029acc8 + 1;
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}



/* c02894b8 FUN_c02894b8 */

/* Boundary evidence: original MIPS .pdata c02894b8..c0289daf. Semantic name remains unreviewed. */

int FUN_c02894b8(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                ushort param_7)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
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
  code *local_68;
  int local_64;
  int local_60;
  uint local_5c;
  int local_58;
  uint local_54;
  code *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  bVar1 = param_6 <= param_2;
  local_64 = -1;
  if (bVar1) {
    iVar3 = (param_2 - 0x21U & 0xffffffc0) + 0x20;
    local_48 = param_2 - iVar3;
    local_60 = param_2 - param_4;
    iVar8 = 4;
    iVar13 = (param_6 + 0x20 >> 6) + -1;
    iVar15 = -1;
    local_44 = param_2 - param_6;
  }
  else {
    iVar3 = (param_2 + 0x20U & 0xffffffc0) + 0x20;
    local_48 = iVar3 - param_2;
    iVar13 = (param_6 + -0x21 >> 6) + 1;
    local_60 = param_4 - param_2;
    iVar8 = 1;
    iVar15 = 1;
    local_44 = param_6 - param_2;
  }
  local_5c = (uint)bVar1;
  local_54 = (uint)bVar1;
  iVar3 = iVar3 >> 6;
  if (param_1 < param_5) {
    iVar5 = (param_1 + 0x20U & 0xffffffc0) + 0x20;
    local_4c = iVar5 - param_1;
    local_64 = 1;
    iVar14 = (param_5 + -0x21 >> 6) + 1;
    iVar11 = 0;
    local_40 = param_3 - param_1;
    iVar17 = param_5 - param_1;
  }
  else {
    local_54 = 1 - local_54;
    if (iVar8 == 1) {
      iVar8 = 2;
    }
    else {
      iVar8 = 3;
    }
    iVar5 = (param_1 - 0x21U & 0xffffffc0) + 0x20;
    local_4c = param_1 - iVar5;
    iVar14 = (param_5 + 0x20 >> 6) + -1;
    iVar11 = 1;
    local_40 = param_1 - param_3;
    iVar17 = param_1 - param_5;
  }
  iVar5 = iVar5 >> 6;
  local_2c = param_5;
  local_34 = param_6;
  local_58 = iVar11;
  local_38 = param_4;
  local_30 = param_3;
  FUN_c0287cac((uint)param_7,iVar8,1,2,&local_30,&local_38,&local_68,&local_50);
  iVar12 = local_40;
  iVar9 = local_44;
  iVar8 = local_64;
  local_3c = param_7 & 2;
  if ((param_7 & 2) == 0) {
    if (iVar5 == iVar14) {
      while( true ) {
        if (iVar3 == iVar13) {
          return 0;
        }
        iVar8 = (*local_68)(iVar11 + iVar5,iVar3);
        if (iVar8 != 0) break;
        iVar3 = iVar15 + iVar3;
      }
      return iVar8;
    }
    if (iVar3 == iVar13) {
      iVar3 = local_5c + iVar3;
      do {
        iVar13 = (*local_50)(iVar5,iVar3);
        if (iVar13 != 0) {
          return iVar13;
        }
        iVar5 = iVar8 + iVar5;
      } while (iVar5 != iVar14);
      return 0;
    }
  }
  else {
    if (iVar3 == iVar13) {
      return 0;
    }
    if (iVar5 == iVar14) {
      do {
        iVar8 = (*local_68)(iVar11 + iVar5,iVar3);
        if (iVar8 != 0) {
          return iVar8;
        }
        iVar3 = iVar15 + iVar3;
      } while (iVar3 != iVar13);
      return 0;
    }
  }
  local_44 = (local_40 * local_44 - iVar17 * local_60) * 2;
  local_40 = FUN_c0276044(local_44);
  iVar8 = iVar17;
  if (iVar17 <= iVar9) {
    iVar8 = iVar9;
  }
  iVar8 = FUN_c0276044(iVar8);
  if ((iVar8 < 0xd) && (local_40 < 0x1a)) {
    uVar7 = *(uint *)(&DAT_c0261708 + (iVar8 + local_40) * 4);
    uVar2 = -uVar7 + 6;
    iVar11 = local_4c;
    if (0 < (int)uVar7) {
      iVar11 = 1 << (uVar7 - 1 & 0x1f);
      iVar12 = iVar11 + iVar12 >> (uVar7 & 0x1f);
      iVar9 = iVar11 + iVar9 >> (uVar7 & 0x1f);
      iVar17 = iVar11 + iVar17 >> (uVar7 & 0x1f);
      local_60 = iVar11 + local_60 >> (uVar7 & 0x1f);
      local_44 = (iVar12 * iVar9 - iVar17 * local_60) * 2;
      local_48 = iVar11 + local_48 >> (uVar7 & 0x1f);
      iVar11 = iVar11 + local_4c >> (uVar7 & 0x1f);
    }
    iVar6 = local_44 * iVar17;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (iVar6 < 0x23000000) {
      iVar6 = local_44 * iVar9;
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 0x23000000) {
        iVar9 = iVar9 + local_60 * -2;
        iVar6 = iVar9 * iVar9;
        iVar17 = iVar17 + iVar12 * -2;
        iVar10 = 1 << (uVar2 & 0x1f);
        iVar4 = iVar17 * iVar17;
        iVar18 = -(iVar9 * iVar17);
        local_60 = local_44 * local_60;
        iVar16 = -(local_44 * iVar12);
        if (iVar8 < 8) {
          iVar16 = iVar9 * iVar17 * -2;
          iVar9 = local_44 * iVar12 * -2;
          iVar8 = (iVar6 * iVar11 + local_60 * 2 + iVar16 * local_48) * iVar11 +
                  (iVar4 * local_48 + iVar9) * local_48;
          uVar7 = uVar2 * 2;
          iVar18 = iVar16 << (uVar7 & 0x1f);
          iVar17 = (iVar11 * 2 + iVar10) * iVar6 + local_60 * 2 + iVar16 * local_48 <<
                   (uVar2 & 0x1f);
          iVar16 = (local_48 * 2 + iVar10) * iVar4 + iVar16 * iVar11 + iVar9 << (uVar2 & 0x1f);
        }
        else {
          iVar8 = ((iVar6 >> 1) * iVar11 + iVar18 * local_48 + local_60 >> (uVar2 & 0x1f)) * iVar11
                  + ((iVar4 >> 1) * local_48 + iVar16 >> (uVar2 & 0x1f)) * local_48;
          iVar17 = ((iVar10 >> 1) + iVar11) * iVar6 + iVar18 * local_48 + local_60;
          uVar7 = -uVar7 + 5;
          iVar16 = ((iVar10 >> 1) + local_48) * iVar4 + iVar18 * iVar11 + iVar16;
          iVar18 = iVar18 << (uVar2 & 0x1f);
        }
        iVar8 = iVar8 + local_54;
        iVar6 = iVar6 << (uVar7 & 0x1f);
        iVar4 = iVar4 << (uVar7 & 0x1f);
        uVar2 = iVar6 << 1;
        local_60 = iVar4;
        local_54 = uVar2;
        local_48 = iVar6;
        if (local_3c == 0) {
          if (local_44 < 1) {
            do {
              if (iVar3 == iVar13) goto LAB_c0289c70;
              if ((iVar8 < 0) || (local_48 < iVar17)) {
                iVar11 = (*local_68)(local_58 + iVar5,iVar3);
                if (iVar11 != 0) {
                  return iVar11;
                }
                iVar11 = local_60 * 2;
                iVar3 = iVar15 + iVar3;
                uVar2 = iVar18;
                iVar9 = iVar16;
              }
              else {
                iVar11 = (*local_50)(iVar5,local_5c + iVar3);
                if (iVar11 != 0) {
                  return iVar11;
                }
                iVar5 = local_64 + iVar5;
                uVar2 = local_54;
                iVar11 = iVar18;
                iVar9 = iVar17;
              }
              iVar8 = iVar9 + iVar8;
              iVar16 = iVar11 + iVar16;
              iVar17 = uVar2 + iVar17;
            } while (iVar5 != iVar14);
          }
          else {
            do {
              if (iVar3 == iVar13) break;
              if ((iVar8 < 0) || (local_60 < iVar16)) {
                iVar11 = (*local_50)(iVar5,local_5c + iVar3);
                if (iVar11 != 0) {
                  return iVar11;
                }
                iVar5 = local_64 + iVar5;
                uVar2 = local_54;
                iVar11 = iVar18;
                iVar9 = iVar17;
              }
              else {
                iVar11 = (*local_68)(local_58 + iVar5,iVar3);
                if (iVar11 != 0) {
                  return iVar11;
                }
                iVar3 = iVar15 + iVar3;
                uVar2 = iVar18;
                iVar11 = local_60 * 2;
                iVar9 = iVar16;
              }
              iVar8 = iVar9 + iVar8;
              iVar16 = iVar11 + iVar16;
              iVar17 = uVar2 + iVar17;
            } while (iVar5 != iVar14);
LAB_c0289c70:
            if (iVar5 != iVar14) {
              iVar8 = local_5c + iVar3;
              do {
                iVar17 = (*local_50)(iVar5,iVar8);
                if (iVar17 != 0) {
                  return iVar17;
                }
                iVar5 = local_64 + iVar5;
              } while (iVar5 != iVar14);
            }
          }
          if (iVar3 != iVar13) {
            iVar5 = local_58 + iVar5;
            do {
              iVar8 = (*local_68)(iVar5,iVar3);
              if (iVar8 != 0) {
                return iVar8;
              }
              iVar3 = iVar15 + iVar3;
            } while (iVar3 != iVar13);
          }
        }
        else {
          iVar5 = local_58 + iVar5;
          iVar14 = local_58 + iVar14;
          if (iVar5 != iVar14) {
            if (local_44 < 1) {
              do {
                if (iVar3 == iVar13) {
                  return 0;
                }
                if ((iVar8 < 0) || (iVar6 < iVar17)) {
                  iVar11 = (*local_68)(iVar5,iVar3);
                  if (iVar11 != 0) {
                    return iVar11;
                  }
                  iVar9 = local_60 * 2;
                  iVar3 = iVar15 + iVar3;
                  uVar2 = local_54;
                  iVar6 = local_48;
                  iVar11 = iVar18;
                  iVar12 = iVar16;
                }
                else {
                  iVar5 = local_64 + iVar5;
                  iVar11 = uVar2;
                  iVar9 = iVar18;
                  iVar12 = iVar17;
                }
                iVar8 = iVar12 + iVar8;
                iVar16 = iVar9 + iVar16;
                iVar17 = iVar11 + iVar17;
              } while (iVar5 != iVar14);
            }
            else {
              do {
                if (iVar3 == iVar13) {
                  return 0;
                }
                if ((iVar8 < 0) || (iVar4 < iVar16)) {
                  iVar5 = local_64 + iVar5;
                  iVar11 = uVar2;
                  iVar9 = iVar18;
                  iVar12 = iVar17;
                }
                else {
                  iVar11 = (*local_68)(iVar5,iVar3);
                  if (iVar11 != 0) {
                    return iVar11;
                  }
                  iVar3 = iVar15 + iVar3;
                  uVar2 = local_54;
                  iVar4 = local_60;
                  iVar11 = iVar18;
                  iVar9 = local_60 * 2;
                  iVar12 = iVar16;
                }
                iVar8 = iVar12 + iVar8;
                iVar16 = iVar9 + iVar16;
                iVar17 = iVar11 + iVar17;
              } while (iVar5 != iVar14);
            }
          }
          for (; iVar3 != iVar13; iVar3 = iVar15 + iVar3) {
            iVar8 = (*local_68)(iVar5,iVar3);
            if (iVar8 != 0) {
              return iVar8;
            }
          }
        }
        return 0;
      }
    }
  }
  return 0x1306;
}



/* c0289db0 FUN_c0289db0 */

/* Boundary evidence: original MIPS .pdata c0289db0..c0289e83. Semantic name remains unreviewed. */

int FUN_c0289db0(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = *param_3;
  iVar8 = param_3[2];
  iVar2 = param_1 * 0x40 + 0x20;
  iVar6 = param_2[1];
  iVar7 = param_3[1];
  if (iVar4 < iVar8) {
    iVar9 = *param_2;
    iVar3 = param_2[2];
    iVar1 = iVar4;
    iVar4 = iVar8;
  }
  else {
    iVar9 = param_2[2];
    iVar3 = *param_2;
    iVar1 = iVar8;
  }
  do {
    iVar5 = iVar7 * 2 + iVar4 + iVar1 + 1 >> 2;
    iVar8 = iVar6 * 2 + iVar3 + iVar9 + 1 >> 2;
    if (iVar2 < iVar5) {
      iVar6 = iVar9 + iVar6 >> 1;
      iVar7 = iVar1 + iVar7 >> 1;
      iVar3 = iVar8;
      iVar4 = iVar5;
    }
    else if (iVar5 < iVar2) {
      iVar6 = iVar3 + iVar6 >> 1;
      iVar7 = iVar4 + iVar7 >> 1;
      iVar1 = iVar5;
      iVar9 = iVar8;
    }
  } while (iVar5 != iVar2);
  return iVar8;
}



/* c0289e84 FUN_c0289e84 */

/* Boundary evidence: original MIPS .pdata c0289e84..c0289f57. Semantic name remains unreviewed. */

void FUN_c0289e84(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *param_2;
  iVar4 = param_2[2];
  iVar1 = param_1 * 0x40 + 0x20;
  iVar3 = param_2[1];
  iVar5 = iVar2;
  if (iVar2 < iVar4) {
    iVar5 = iVar4;
    iVar4 = iVar2;
  }
  do {
    iVar2 = iVar3 * 2 + iVar5 + iVar4 + 1 >> 2;
    if (iVar1 < iVar2) {
      iVar3 = iVar4 + iVar3 >> 1;
      iVar5 = iVar2;
    }
    else if (iVar2 < iVar1) {
      iVar3 = iVar5 + iVar3 >> 1;
      iVar4 = iVar2;
    }
  } while (iVar2 != iVar1);
  return;
}



/* c0289f58 FUN_c0289f58 */

/* Boundary evidence: original MIPS .pdata c0289f58..c0289f83. Semantic name remains unreviewed. */

void FUN_c0289f58(void)

{
  FUN_c0287c10(1,FUN_c0289db0,FUN_c0289e84);
  return;
}



/* c0289f84 FUN_c0289f84 */

/* Boundary evidence: original MIPS .pdata c0289f84..c028a3db. Semantic name remains unreviewed. */

int FUN_c0289f84(int param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_res8;
  int local_resc;
  uint local_50;
  int local_4c;
  code *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  code *local_2c;
  
  local_4c = -1;
  bVar1 = param_4 < param_2;
  iVar11 = 1;
  if (bVar1) {
    iVar6 = (param_2 - 0x21U & 0xffffffc0) + 0x20;
    local_38 = param_2 - iVar6;
    iVar6 = iVar6 >> 6;
    iVar5 = iVar6 - (param_4 + 0x20 >> 6);
    iVar4 = 4;
    iVar12 = -1;
    local_40 = param_2 - param_4;
  }
  else {
    iVar6 = (param_2 + 0x20U & 0xffffffc0) + 0x20;
    local_38 = iVar6 - param_2;
    iVar6 = iVar6 >> 6;
    iVar5 = (param_4 + -0x21 >> 6) - iVar6;
    iVar4 = 1;
    iVar12 = 1;
    local_40 = param_4 - param_2;
  }
  local_30 = (uint)bVar1;
  iVar5 = iVar5 + 1;
  local_50 = (uint)bVar1;
  if (param_4 == param_2) {
    if ((param_5 & 2) != 0) {
      return 0;
    }
    iVar5 = param_2 + -1;
    if (param_1 <= param_3) {
      iVar5 = param_2;
    }
    iVar6 = iVar5 + 0x20 >> 6;
    iVar5 = 0;
  }
  if (param_3 < param_1) {
    local_50 = 1 - local_50;
    if (iVar4 == 1) {
      iVar4 = 2;
    }
    else {
      iVar4 = 3;
    }
    iVar8 = (param_1 - 0x21U & 0xffffffc0) + 0x20;
    local_44 = param_1 - iVar8;
    iVar8 = iVar8 >> 6;
    iVar7 = iVar8 - (param_3 + 0x20 >> 6);
    local_3c = param_1 - param_3;
  }
  else {
    local_44 = (param_1 + 0x20U & 0xffffffc0) + 0x20;
    iVar8 = local_44 >> 6;
    iVar7 = (param_3 + -0x21 >> 6) - iVar8;
    local_44 = local_44 - param_1;
    local_4c = 1;
    iVar11 = 0;
    local_3c = param_3 - param_1;
  }
  iVar7 = iVar7 + 1;
  if (param_3 == param_1) {
    iVar7 = param_1 + -1;
    if (param_4 <= param_2) {
      iVar7 = param_1;
    }
    iVar8 = iVar7 + 0x20 >> 6;
    iVar7 = 0;
  }
  local_res8 = param_3;
  local_resc = param_4;
  local_34 = iVar12;
  FUN_c0287cac((uint)param_5,iVar4,0,1,&local_res8,&local_resc,&local_48,&local_2c);
  iVar10 = local_34;
  iVar4 = local_3c;
  if ((param_5 & 2) == 0) {
    if (param_2 == local_resc) {
      iVar11 = 0;
      if (0 < iVar7) {
        do {
          iVar4 = (*local_2c)(iVar8,iVar6);
          if (iVar4 != 0) {
            return iVar4;
          }
          iVar11 = iVar11 + 1;
          iVar8 = local_4c + iVar8;
        } while (iVar11 < iVar7);
      }
    }
    else if (param_1 == local_res8) {
      iVar11 = 0;
      if (0 < iVar5) {
        do {
          iVar4 = (*local_48)(iVar8,iVar6);
          if (iVar4 != 0) {
            return iVar4;
          }
          iVar11 = iVar11 + 1;
          iVar6 = iVar12 + iVar6;
        } while (iVar11 < iVar5);
      }
    }
    else {
      iVar2 = local_3c * 0x40;
      iVar9 = 0;
      iVar10 = (local_3c * local_38 - local_44 * local_40) + local_50;
      iVar4 = local_40 * -0x40;
      local_34 = iVar4;
      if (0 < iVar7 + iVar5) {
        do {
          if (iVar10 < 1) {
            iVar3 = (*local_48)(iVar11 + iVar8,iVar6);
            if (iVar3 != 0) {
              return iVar3;
            }
            iVar6 = iVar12 + iVar6;
            iVar3 = iVar2;
          }
          else {
            iVar3 = (*local_2c)(iVar8,local_30 + iVar6);
            if (iVar3 != 0) {
              return iVar3;
            }
            iVar8 = local_4c + iVar8;
            iVar3 = iVar4;
          }
          iVar10 = iVar3 + iVar10;
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar7 + iVar5);
      }
    }
  }
  else if (param_1 == local_res8) {
    iVar11 = 0;
    if (0 < iVar5) {
      do {
        iVar4 = (*local_48)(iVar8,iVar6);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar11 = iVar11 + 1;
        iVar6 = iVar12 + iVar6;
      } while (iVar11 < iVar5);
    }
  }
  else {
    iVar11 = iVar11 + iVar8;
    iVar8 = 0;
    iVar9 = (local_3c * local_38 - local_44 * local_40) + local_50;
    iVar12 = -local_40;
    if (0 < iVar7 + iVar5) {
      do {
        if (iVar9 < 1) {
          iVar2 = (*local_48)(iVar11,iVar6);
          if (iVar2 != 0) {
            return iVar2;
          }
          iVar6 = iVar10 + iVar6;
          iVar2 = iVar4;
        }
        else {
          iVar11 = local_4c + iVar11;
          iVar2 = iVar12;
        }
        iVar9 = iVar2 * 0x40 + iVar9;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar7 + iVar5);
    }
  }
  return 0;
}



/* c028a3dc FUN_c028a3dc */

/* Boundary evidence: original MIPS .pdata c028a3dc..c028a42b. Semantic name remains unreviewed. */

int FUN_c028a3dc(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c0274d38(param_2[1] - *param_2,(param_1 * 0x40 - *param_3) + 0x20,
                       param_3[1] - *param_3);
  return iVar1 + *param_2;
}



/* c028a42c FUN_c028a42c */

/* Boundary evidence: original MIPS .pdata c028a42c..c028a47b. Semantic name remains unreviewed. */

int FUN_c028a42c(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c0274d38(param_3[1] - *param_3,(param_1 * 0x40 - *param_2) + 0x20,
                       param_2[1] - *param_2);
  return iVar1 + *param_3;
}



/* c028a47c FUN_c028a47c */

/* Boundary evidence: original MIPS .pdata c028a47c..c028a4a7. Semantic name remains unreviewed. */

void FUN_c028a47c(void)

{
  FUN_c0287c10(0,FUN_c028a3dc,FUN_c028a42c);
  return;
}



/* c028a4a8 FUN_c028a4a8 */

void FUN_c028a4a8(undefined4 param_1,undefined4 param_2)

{
  DAT_c029ac98 = param_1;
  DAT_c029ac9c = param_2;
  DAT_c029ac90 = 0x7fffffff;
  return;
}



/* c028a4c8 FUN_c028a4c8 */

/* Boundary evidence: original MIPS .pdata c028a4c8..c028a52f. Semantic name remains unreviewed. */

void FUN_c028a4c8(uint param_1)

{
  int iVar1;
  code *local_10;
  undefined4 uStack_c;
  
  iVar1 = FUN_c0287cac(param_1,1,2,0,(undefined4 *)0x0,(undefined4 *)0x0,&local_10,&uStack_c);
  if (iVar1 == 0) {
    (*local_10)(DAT_c029ac98 + 0x1f >> 6,DAT_c029ac9c >> 6);
  }
  return;
}



/* c028a530 FUN_c028a530 */

/* Boundary evidence: original MIPS .pdata c028a530..c028a597. Semantic name remains unreviewed. */

void FUN_c028a530(uint param_1)

{
  int iVar1;
  code *local_10;
  undefined4 uStack_c;
  
  iVar1 = FUN_c0287cac(param_1,4,2,0,(undefined4 *)0x0,(undefined4 *)0x0,&local_10,&uStack_c);
  if (iVar1 == 0) {
    (*local_10)(DAT_c029ac98 + 0x20 >> 6,DAT_c029ac9c >> 6);
  }
  return;
}



/* c028a598 FUN_c028a598 */

/* Boundary evidence: original MIPS .pdata c028a598..c028a5ff. Semantic name remains unreviewed. */

void FUN_c028a598(uint param_1)

{
  int iVar1;
  code *local_10;
  undefined4 uStack_c;
  
  iVar1 = FUN_c0287cac(param_1,2,2,0,(undefined4 *)0x0,(undefined4 *)0x0,&uStack_c,&local_10);
  if (iVar1 == 0) {
    (*local_10)(DAT_c029ac98 >> 6,DAT_c029ac9c + 0x1f >> 6);
  }
  return;
}



/* c028a600 FUN_c028a600 */

/* Boundary evidence: original MIPS .pdata c028a600..c028a667. Semantic name remains unreviewed. */

void FUN_c028a600(uint param_1)

{
  int iVar1;
  code *local_10;
  undefined4 uStack_c;
  
  iVar1 = FUN_c0287cac(param_1,1,2,0,(undefined4 *)0x0,(undefined4 *)0x0,&uStack_c,&local_10);
  if (iVar1 == 0) {
    (*local_10)(DAT_c029ac98 >> 6,DAT_c029ac9c + 0x20 >> 6);
  }
  return;
}



/* c028a678 FUN_c028a678 */

/* Boundary evidence: original MIPS .pdata c028a678..c028a6a3. Semantic name remains unreviewed. */

void FUN_c028a678(void)

{
  FUN_c0287c10(2,&LAB_c028a668,&LAB_c028a670);
  return;
}



/* c028a6a4 FUN_c028a6a4 */

/* Boundary evidence: original MIPS .pdata c028a6a4..c028a7ff. Semantic name remains unreviewed. */

int FUN_c028a6a4(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (DAT_c029ac9c < param_2) {
    if (DAT_c029ac94 < DAT_c029ac9c) goto LAB_c028a7e8;
    param_1 = DAT_c029ac90;
    if (DAT_c029ac94 <= DAT_c029ac9c) goto joined_r0xc028a7e0;
  }
  else {
    if (DAT_c029ac9c <= param_2) {
      if (DAT_c029ac9c <= DAT_c029ac94) {
        if (DAT_c029ac9c < DAT_c029ac94) goto joined_r0xc028a790;
        if ((DAT_c029ac90 < DAT_c029ac98) && (param_1 < DAT_c029ac98)) goto LAB_c028a7c0;
        if (DAT_c029ac90 <= DAT_c029ac98) {
          return 0;
        }
      }
joined_r0xc028a7e0:
      if (param_1 <= DAT_c029ac98) {
        return 0;
      }
LAB_c028a7e8:
      iVar1 = FUN_c028a4c8(param_3);
      return iVar1;
    }
    if (DAT_c029ac9c <= DAT_c029ac94) {
      param_1 = DAT_c029ac90;
      if (DAT_c029ac9c < DAT_c029ac94) goto LAB_c028a7c0;
joined_r0xc028a790:
      if (DAT_c029ac98 <= param_1) {
        return 0;
      }
      goto LAB_c028a7c0;
    }
  }
  iVar1 = FUN_c028a4c8(param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_c028a7c0:
  iVar1 = FUN_c028a530(param_3);
  return iVar1;
}



/* c028a800 FUN_c028a800 */

/* Boundary evidence: original MIPS .pdata c028a800..c028a95b. Semantic name remains unreviewed. */

int FUN_c028a800(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (param_1 < DAT_c029ac98) {
    if (DAT_c029ac98 < DAT_c029ac90) goto LAB_c028a944;
    param_2 = DAT_c029ac94;
    if (DAT_c029ac98 <= DAT_c029ac90) goto joined_r0xc028a93c;
  }
  else {
    if (param_1 <= DAT_c029ac98) {
      if (DAT_c029ac90 <= DAT_c029ac98) {
        if (DAT_c029ac90 < DAT_c029ac98) goto joined_r0xc028a8ec;
        if ((DAT_c029ac94 < DAT_c029ac9c) && (param_2 < DAT_c029ac9c)) goto LAB_c028a91c;
        if (DAT_c029ac94 <= DAT_c029ac9c) {
          return 0;
        }
      }
joined_r0xc028a93c:
      if (param_2 <= DAT_c029ac9c) {
        return 0;
      }
LAB_c028a944:
      iVar1 = FUN_c028a598(param_3);
      return iVar1;
    }
    if (DAT_c029ac90 <= DAT_c029ac98) {
      param_2 = DAT_c029ac94;
      if (DAT_c029ac90 < DAT_c029ac98) goto LAB_c028a91c;
joined_r0xc028a8ec:
      if (DAT_c029ac9c <= param_2) {
        return 0;
      }
      goto LAB_c028a91c;
    }
  }
  iVar1 = FUN_c028a598(param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_c028a91c:
  iVar1 = FUN_c028a600(param_3);
  return iVar1;
}



/* c028a95c FUN_c028a95c */

/* Boundary evidence: original MIPS .pdata c028a95c..c028aa8b. Semantic name remains unreviewed. */

int FUN_c028a95c(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = DAT_c029aca0;
  uVar2 = DAT_c029aca4;
  if ((DAT_c029ac9c & 0x3f) == 0x20) {
    if ((DAT_c029ac98 == param_1) && (DAT_c029ac9c == param_2)) {
      return 0;
    }
    uVar1 = param_1;
    uVar2 = param_2;
    if ((DAT_c029ac90 != 0x7fffffff) &&
       (iVar7 = FUN_c028a6a4(param_1,param_2,param_3), uVar1 = DAT_c029aca0, uVar2 = DAT_c029aca4,
       iVar7 != 0)) {
      return iVar7;
    }
  }
  DAT_c029aca4 = uVar2;
  DAT_c029aca0 = uVar1;
  uVar1 = DAT_c029ac98;
  uVar2 = DAT_c029ac9c;
  uVar3 = param_1;
  uVar4 = param_2;
  uVar5 = DAT_c029aca0;
  uVar6 = DAT_c029aca4;
  if (((((param_3 & 2) == 0) &&
       (uVar1 = DAT_c029ac98, uVar2 = DAT_c029ac9c, uVar3 = param_1, uVar4 = param_2,
       (DAT_c029ac98 & 0x3f) == 0x20)) &&
      ((DAT_c029ac98 != param_1 ||
       (uVar1 = DAT_c029ac90, uVar2 = DAT_c029ac94, uVar3 = DAT_c029ac98, uVar4 = DAT_c029ac9c,
       DAT_c029ac9c != param_2)))) &&
     ((uVar1 = DAT_c029ac98, uVar2 = DAT_c029ac9c, uVar3 = param_1, uVar4 = param_2, uVar5 = param_1
      , uVar6 = param_2, DAT_c029ac90 != 0x7fffffff &&
      (iVar7 = FUN_c028a800(param_1,param_2,param_3), uVar1 = DAT_c029ac98, uVar2 = DAT_c029ac9c,
      uVar3 = param_1, uVar4 = param_2, uVar5 = DAT_c029aca0, uVar6 = DAT_c029aca4, iVar7 != 0)))) {
    return iVar7;
  }
  DAT_c029aca4 = uVar6;
  DAT_c029aca0 = uVar5;
  DAT_c029ac9c = uVar4;
  DAT_c029ac98 = uVar3;
  DAT_c029ac94 = uVar2;
  DAT_c029ac90 = uVar1;
  return 0;
}



/* c028aa8c FUN_c028aa8c */

/* Boundary evidence: original MIPS .pdata c028aa8c..c028ab23. Semantic name remains unreviewed. */

int FUN_c028aa8c(uint param_1)

{
  int iVar1;
  
  if ((((DAT_c029ac9c & 0x3f) != 0x20) ||
      (iVar1 = FUN_c028a6a4(DAT_c029aca0,DAT_c029aca4,param_1), iVar1 == 0)) &&
     (((param_1 & 2) != 0 ||
      (((DAT_c029ac98 & 0x3f) != 0x20 ||
       (iVar1 = FUN_c028a800(DAT_c029aca0,DAT_c029aca4,param_1), iVar1 == 0)))))) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c028ab24 FUN_c028ab24 */

void FUN_c028ab24(int param_1,int param_2,int param_3,int param_4)

{
  DAT_c029ad4c = param_1;
  DAT_c029ad54 = param_1 + param_2;
  DAT_c029ad50 = param_3;
  DAT_c029ad58 = param_3 + param_4;
  return;
}



/* c028ab48 FUN_c028ab48 */

int FUN_c028ab48(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_c029ad4c;
  DAT_c029ad4c = (param_1 + 3U & 0xfffffffc) + DAT_c029ad4c;
  if (DAT_c029ad54 < DAT_c029ad4c) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c028ab84 FUN_c028ab84 */

int FUN_c028ab84(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_c029ad50;
  DAT_c029ad50 = (param_1 + 3U & 0xfffffffc) + DAT_c029ad50;
  if (DAT_c029ad58 < DAT_c029ad50) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c028abc0 FUN_c028abc0 */

void FUN_c028abc0(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 5) {
    iVar2 = 0;
    do {
      puVar1 = (undefined2 *)(iVar2 + *(int *)(param_1 + 0x34));
      puVar1[2] = 0xffff;
      puVar1[1] = 0xffff;
      *puVar1 = 0xffff;
      puVar1[3] = 0;
      *(undefined4 *)(puVar1 + 4) = 0;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar3 < *(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 5)
    ;
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}



/* c028ac34 FUN_c028ac34 */

/* Boundary evidence: original MIPS .pdata c028ac34..c028ad0b. Semantic name remains unreviewed. */

undefined4 FUN_c028ac34(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  short *psVar2;
  
  if (-1 < param_4 + -1) {
    psVar2 = (short *)(*(int *)(param_1 + 0x34) + param_2 * 0xc);
    iVar1 = (int)*psVar2;
    if (iVar1 == -1) {
      return 0;
    }
    if (iVar1 != param_3) {
      if (psVar2[1] != -1) {
        if (psVar2[1] == param_3) {
          return 1;
        }
        iVar1 = FUN_c028ac34(param_1,iVar1,param_3,param_4 + -2);
        if (iVar1 != 0) {
          return 1;
        }
        iVar1 = (int)psVar2[1];
      }
      iVar1 = FUN_c028ac34(param_1,iVar1,param_3,param_4 + -2);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}



/* c028ad0c FUN_c028ad0c */

/* Boundary evidence: original MIPS .pdata c028ad0c..c028aed3. Semantic name remains unreviewed. */

void FUN_c028ad0c(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  if ((((-1 < param_3) &&
       (iVar4 = *(short *)(*(short *)(param_2 + 0x28) * 2 + *(int *)(param_2 + 0x20) + -2) + 5,
       param_3 < iVar4)) && (-1 < param_4)) && ((param_4 < iVar4 && (param_3 != param_4)))) {
    iVar1 = FUN_c028ac34(param_2,param_3,param_4,100);
    iVar4 = param_4 * 0xc;
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_2 + 0x34);
      if (*(short *)(iVar1 + iVar4) == -1) {
        iVar2 = (int)*(short *)(param_3 * 0xc + iVar1);
        if (iVar2 != -1) {
          do {
            iVar5 = iVar2;
            if (*(int *)(param_3 * 4 + *(int *)(param_2 + 0x10)) !=
                *(int *)(iVar5 * 4 + *(int *)(param_2 + 0x10))) break;
            iVar2 = (int)*(short *)(iVar5 * 0xc + iVar1);
            param_3 = iVar5;
          } while (iVar2 != -1);
        }
        *(short *)(*(int *)(param_2 + 0x34) + iVar4) = (short)param_3;
        *(undefined2 *)(*(int *)(param_2 + 0x34) + iVar4 + 2) = 0xffff;
      }
    }
    else {
      iVar1 = *(int *)(param_2 + 0x34) + iVar4;
      *(ushort *)(iVar1 + 6) = *(ushort *)(iVar1 + 6) | 1;
    }
    if (param_5 == 1) {
      iVar1 = *(int *)(param_2 + 0x34);
      psVar3 = (short *)(param_3 * 0xc + iVar1);
      if ((psVar3[2] == -1) && (*(short *)(iVar1 + iVar4 + 4) != param_3)) {
        if ((*psVar3 == -1) || (*(short *)(*psVar3 * 0xc + iVar1 + 4) != param_3)) {
          psVar3[2] = (short)param_4;
        }
        else {
          *(ushort *)(iVar1 + iVar4 + 6) = *(ushort *)(iVar1 + iVar4 + 6) | 1;
        }
      }
    }
  }
  return;
}



/* c028aed4 FUN_c028aed4 */

/* Boundary evidence: original MIPS .pdata c028aed4..c028b01f. Semantic name remains unreviewed. */

void FUN_c028aed4(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  short *psVar1;
  int iVar2;
  
  if ((((((-1 < param_3) &&
         (iVar2 = *(short *)(*(short *)(param_2 + 0x28) * 2 + *(int *)(param_2 + 0x20) + -2) + 5,
         param_3 < iVar2)) && (-1 < param_5)) && ((param_5 < iVar2 && (-1 < param_4)))) &&
      ((param_4 < iVar2 && ((param_3 != param_4 && (param_5 != param_4)))))) && (param_3 != param_5)
     ) {
    iVar2 = FUN_c028ac34(param_2,param_3,param_4,100);
    if ((iVar2 == 0) && (iVar2 = FUN_c028ac34(param_2,param_5,param_4,100), iVar2 == 0)) {
      iVar2 = param_4 * 0xc;
      psVar1 = (short *)(iVar2 + *(int *)(param_2 + 0x34));
      if ((*psVar1 == -1) && (psVar1[1] == -1)) {
        *(short *)(iVar2 + *(int *)(param_2 + 0x34)) = (short)param_3;
        *(short *)(iVar2 + *(int *)(param_2 + 0x34) + 2) = (short)param_5;
      }
    }
    else {
      iVar2 = *(int *)(param_2 + 0x34) + param_4 * 0xc;
      *(ushort *)(iVar2 + 6) = *(ushort *)(iVar2 + 6) | 1;
    }
  }
  return;
}



/* c028b020 FUN_c028b020 */

int FUN_c028b020(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_5 != param_6) {
    iVar3 = param_4 * 4;
    iVar1 = param_2 * 4;
    if (*(int *)(*(int *)(param_1 + 8) + iVar1) < *(int *)(iVar3 + *(int *)(param_1 + 8))) {
      iVar4 = *(int *)(*(int *)(param_1 + 8) + iVar1);
      iVar3 = *(int *)(*(int *)(param_1 + 8) + iVar3);
      iVar1 = param_6;
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 8) + iVar3);
      iVar3 = *(int *)(*(int *)(param_1 + 8) + iVar1);
      iVar1 = param_5;
      param_5 = param_6;
    }
    iVar2 = *(int *)(param_3 * 4 + *(int *)(param_1 + 8));
    if (iVar4 == iVar3) {
      iVar1 = iVar1 + param_5;
      param_5 = iVar1 >> 1;
      if (iVar1 < 0) {
        param_5 = iVar1 + 1 >> 1;
      }
    }
    else {
      iVar1 = (iVar3 - iVar2) * param_5 + (iVar2 - iVar4) * iVar1;
      iVar3 = iVar3 - iVar4;
      param_5 = iVar1 / iVar3;
      if (iVar3 == 0) {
        trap(0x1c00);
      }
      if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
    }
  }
  return param_5;
}



/* c028b118 FUN_c028b118 */

/* Boundary evidence: original MIPS .pdata c028b118..c028b443. Semantic name remains unreviewed. */

undefined4 FUN_c028b118(int param_1,int *param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  short *psVar7;
  
  if (param_4 == -1) {
    return 0;
  }
  psVar7 = (short *)(param_4 * 0xc + param_2[0xd]);
  uVar1 = psVar7[3];
  if ((uVar1 & 4) != 0) {
    return 0;
  }
  psVar7[3] = uVar1 | 4;
  if ((uVar1 & 2) != 0) goto LAB_c028b404;
  if (*(short *)((short)param_2[10] * 2 + param_2[8] + -2) < param_4) {
    uVar3 = *(uint *)(param_4 * 4 + *param_2);
LAB_c028b1d0:
    iVar2 = FUN_c0274d38(uVar3,*(int *)(*(int *)(param_1 + 0x24) + 0x180) - 0x10000,0x10000);
  }
  else if (*psVar7 == -1) {
    if (param_3 != 0) {
      uVar3 = *(uint *)(param_4 * 4 + *param_2);
      goto LAB_c028b1d0;
    }
    iVar2 = 0;
  }
  else if (psVar7[1] == -1) {
    iVar2 = FUN_c028b118(param_1,param_2,param_3,(int)*psVar7);
  }
  else {
    iVar2 = FUN_c028b118(param_1,param_2,param_3,(int)psVar7[1]);
    iVar4 = FUN_c028b118(param_1,param_2,param_3,(int)*psVar7);
    iVar2 = FUN_c028b020((int)param_2,(int)*psVar7,param_4,(int)psVar7[1],iVar4,iVar2);
  }
  if ((psVar7[3] & 2U) == 0) {
    iVar4 = (int)psVar7[2];
    if ((iVar4 == -1) || (iVar6 = iVar4 * 0xc + param_2[0xd], (*(ushort *)(iVar6 + 6) & 2) != 0)) {
      if (((param_3 != 0) && (psVar7[1] == -1)) &&
         ((*psVar7 == -1 ||
          (*(int *)(param_4 * 4 + param_2[2]) != *(int *)(*psVar7 * 4 + param_2[2]))))) {
        iVar2 = FUN_c0274d38(*(uint *)(param_4 * 4 + *param_2),
                             *(int *)(*(int *)(param_1 + 0x24) + 0x180) - 0x10000,0x10000);
      }
      if (*psVar7 != -1) {
        piVar5 = (int *)(param_4 * 4 + *param_2);
        *piVar5 = *piVar5 + iVar2;
      }
    }
    else {
      if ((*psVar7 == -1) || (psVar7[1] == -1)) {
        iVar2 = FUN_c0274d38(*(int *)(iVar4 * 4 + *param_2) + *(int *)(param_4 * 4 + *param_2),
                             *(int *)(*(int *)(param_1 + 0x24) + 0x180) - 0x10000,0x20000);
      }
      piVar5 = (int *)(param_4 * 4 + *param_2);
      *piVar5 = *piVar5 + iVar2;
      piVar5 = (int *)(psVar7[2] * 4 + *param_2);
      *piVar5 = iVar2 + *piVar5;
      *(int *)(iVar6 + 8) = iVar2;
      *(ushort *)(iVar6 + 6) = *(ushort *)(iVar6 + 6) | 2;
    }
    *(int *)(psVar7 + 4) = iVar2;
    psVar7[3] = psVar7[3] | 2;
  }
LAB_c028b404:
  psVar7[3] = psVar7[3] & 0xfffb;
  return *(undefined4 *)(psVar7 + 4);
}



/* c028b444 FUN_c028b444 */

/* Boundary evidence: original MIPS .pdata c028b444..c028b51f. Semantic name remains unreviewed. */

void FUN_c028b444(int param_1,int *param_2)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(short *)((short)param_2[10] * 2 + param_2[8] + -2) + 5;
  iVar3 = 0;
  if (0 < iVar4) {
    puVar2 = (ushort *)(param_2[0xd] + 6);
    do {
      if ((*puVar2 & 1) != 0) break;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 6;
    } while (iVar3 < iVar4);
    iVar1 = 1;
    if (iVar3 < iVar4) goto LAB_c028b4c8;
  }
  iVar1 = 0;
LAB_c028b4c8:
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      FUN_c028b118(param_1,param_2,iVar1,iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  param_2[0xc] = 1;
  return;
}



/* c028b520 FUN_c028b520 */

int FUN_c028b520(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = (int)*(short *)(param_1 + 0x28);
  iVar1 = 0;
  if (0 < iVar2) {
    psVar3 = *(short **)(param_1 + 0x20);
    do {
      if (param_2 <= *psVar3) break;
      iVar1 = iVar1 + 1;
      psVar3 = psVar3 + 1;
    } while (iVar1 < iVar2);
  }
  if (iVar2 <= iVar1) {
    iVar1 = -1;
  }
  return iVar1;
}



/* c028b56c FUN_c028b56c */

/* Boundary evidence: original MIPS .pdata c028b56c..c028b83f. Semantic name remains unreviewed. */

undefined4 FUN_c028b56c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar2 = FUN_c028b520(param_1,param_2);
  if ((-1 < iVar2) && (iVar3 = FUN_c028b520(param_1,param_3), -1 < iVar3)) {
    if (iVar2 != iVar3) {
      return param_4;
    }
    iVar6 = (int)*(short *)(*(int *)(param_1 + 0x1c) + iVar2 * 2);
    iVar7 = (int)*(short *)(*(int *)(param_1 + 0x20) + iVar2 * 2);
    iVar3 = iVar6;
    if (param_2 != iVar7) {
      iVar3 = param_2 + 1;
    }
    iVar5 = iVar7;
    if (param_2 != iVar6) {
      iVar5 = param_2 + -1;
    }
    if ((param_3 != iVar3) && (param_3 != iVar5)) {
      return param_4;
    }
    iVar8 = iVar6;
    if (param_3 != iVar7) {
      iVar8 = param_3 + 1;
    }
    if (param_3 != iVar6) {
      iVar7 = param_3 + -1;
    }
    iVar4 = *(int *)(param_1 + 0x10);
    iVar6 = param_2 * 4;
    iVar9 = *(int *)(param_1 + 0x14);
    bVar1 = (*(int *)(iVar6 + iVar4) - *(int *)(iVar4 + iVar5 * 4)) *
            (*(int *)(iVar9 + iVar3 * 4) - *(int *)(iVar9 + iVar6)) <
            (*(int *)(iVar9 + iVar6) - *(int *)(iVar9 + iVar5 * 4)) *
            (*(int *)(iVar3 * 4 + iVar4) - *(int *)(iVar6 + iVar4));
    iVar5 = *(int *)(param_1 + 0x10);
    iVar3 = param_3 * 4;
    iVar4 = *(int *)(param_1 + 0x14);
    if (bVar1 == (*(int *)(iVar3 + iVar5) - *(int *)(iVar5 + iVar7 * 4)) *
                 (*(int *)(iVar4 + iVar8 * 4) - *(int *)(iVar4 + iVar3)) <
                 (*(int *)(iVar4 + iVar3) - *(int *)(iVar4 + iVar7 * 4)) *
                 (*(int *)(iVar8 * 4 + iVar5) - *(int *)(iVar3 + iVar5))) {
      if (*(int *)(*(int *)(param_1 + 0x10) + iVar3) - *(int *)(*(int *)(param_1 + 0x10) + iVar6) <
          0) {
        iVar7 = *(int *)(*(int *)(param_1 + 0x10) + iVar6) -
                *(int *)(*(int *)(param_1 + 0x10) + iVar3);
      }
      else {
        iVar7 = *(int *)(*(int *)(param_1 + 0x10) + iVar3) -
                *(int *)(*(int *)(param_1 + 0x10) + iVar6);
      }
      iVar5 = *(int *)(param_1 + 0x14);
      if (*(int *)(*(int *)(param_1 + 0x14) + iVar3) - *(int *)(*(int *)(param_1 + 0x14) + iVar6) <
          0) {
        iVar3 = *(int *)(iVar5 + iVar6) - *(int *)(iVar5 + iVar3);
      }
      else {
        iVar3 = *(int *)(iVar5 + iVar3) - *(int *)(iVar5 + iVar6);
      }
      if (iVar3 <= iVar7 << 1) {
        if (((*(byte *)(*(int *)(param_1 + 0x2c) + iVar2) & 1) == 0) == bVar1) {
          return 1;
        }
        return 2;
      }
    }
  }
  return 0;
}



/* c028b840 FUN_c028b840 */

undefined4 FUN_c028b840(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_2 * 4 + *(int *)(param_1 + 0x10));
  iVar2 = *(int *)(param_4 * 4 + *(int *)(param_1 + 0x10));
  iVar3 = iVar2;
  if (iVar2 < iVar4) {
    iVar3 = iVar4;
    iVar4 = iVar2;
  }
  iVar2 = *(int *)(param_3 * 4 + *(int *)(param_1 + 0x10));
  if ((iVar2 < iVar4) || (uVar1 = 1, iVar3 < iVar2)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c028b8a8 FUN_c028b8a8 */

void FUN_c028b8a8(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined2 param_8,int param_9,int param_10,int param_11,int param_12,
                 int param_13)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(param_7 + 0x18);
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  *param_1 = param_6;
  param_1[0x26] = param_5;
  param_1[0x57] = param_13;
  param_1[2] = param_2;
  param_1[1] = param_3;
  param_1[0x25] = param_4;
  param_1[0x58] = uVar1 * 4 + param_6;
  uVar1 = (uint)*(ushort *)(param_7 + 6);
  if ((uint)*(ushort *)(param_7 + 6) <= (uint)*(ushort *)(param_7 + 10)) {
    uVar1 = (uint)*(ushort *)(param_7 + 10);
  }
  param_1[0x59] = uVar1 + 4;
  if (param_9 == 0) {
    param_1[0x2f] = 0;
    param_1[0x2e] = 0;
  }
  else {
    param_1[0x2f] = param_9;
    param_1[0x2e] = param_10;
  }
  if (param_11 == 0) {
    param_1[0x2d] = 0;
    param_1[0x2c] = 0;
  }
  else {
    param_1[0x2d] = param_11;
    param_1[0x2c] = param_12;
  }
  *(undefined2 *)(param_1 + 0x4d) = param_8;
  param_1[0x4c] = param_7;
  *(undefined1 *)((int)param_1 + 0x12d) = 0;
  *(undefined1 *)(param_1 + 0x53) = 1;
  *(undefined1 *)((int)param_1 + 0x14d) = 0;
  param_1[0x54] = 10000;
  param_1[0x55] = 100;
  param_1[0x56] = 10000000;
  return;
}



/* c028b988 FUN_c028b988 */

bool FUN_c028b988(int param_1)

{
  return (*(uint *)(param_1 + 0x6c) & 1) == 0;
}



/* c028b9a4 FUN_c028b9a4 */

void FUN_c028b9a4(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  *param_2 = *(undefined2 *)(param_1 + 0x6a);
  *param_3 = (short)*(undefined4 *)(param_1 + 0x68);
  return;
}



/* c028b9b8 FUN_c028b9b8 */

void FUN_c028b9b8(int param_1,int param_2)

{
  undefined1 uVar1;
  
  *(char *)(param_1 + 0x12d) = (char)param_2;
  if ((param_2 != 0) || (uVar1 = 0, *(char *)(param_1 + 0x14c) == '\0')) {
    uVar1 = 1;
  }
  *(undefined1 *)(param_1 + 0x14d) = uVar1;
  return;
}



/* c028b9d8 FUN_c028b9d8 */

void FUN_c028b9d8(int param_1,char param_2)

{
  undefined1 uVar1;
  
  *(char *)(param_1 + 0x14c) = param_2;
  if ((*(char *)(param_1 + 0x12d) == '\0') && (param_2 != '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *(undefined1 *)(param_1 + 0x14d) = uVar1;
  return;
}



/* c028ba04 FUN_c028ba04 */

void FUN_c028ba04(int param_1)

{
  *(undefined4 *)(param_1 + 0x158) = 10000000;
  return;
}



/* c028ba14 FUN_c028ba14 */

undefined4 FUN_c028ba14(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  
  *(undefined2 *)(param_1 + 0x40) = 3;
  if (((*(ushort *)(param_1 + 0x170) & 1) == 0) || (iVar2 = 1, (*(uint *)(param_1 + 0x6c) & 4) == 0)
     ) {
    iVar2 = 0;
  }
  puVar1 = (&PTR_FUN_c02617ac)[iVar2 * 8];
  *(undefined2 *)(param_1 + 0x50) = 9;
  *(undefined **)(param_1 + 0x3c) = puVar1;
  *(undefined2 *)(param_1 + 0x54) = 0x80;
  iVar2 = 0x16c0a - param_2 >> 10;
  *(undefined4 *)(param_1 + 0x38) = 0x40;
  *(undefined4 *)(param_1 + 0x24) = 0x44;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined2 *)(param_1 + 0x56) = 0;
  *(undefined1 *)(param_1 + 0x58) = 1;
  *(undefined2 *)(param_1 + 0x52) = 3;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(int *)(param_1 + 0x18) = iVar2;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(int *)(param_1 + 0x1c) = -iVar2;
  return 0;
}



/* c028bad8 FUN_c028bad8 */

/* Boundary evidence: original MIPS .pdata c028bad8..c028bc57. Semantic name remains unreviewed. */

void FUN_c028bad8(uint param_1,uint param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    if (param_2 == 0) {
      *param_3 = 0x4000;
      param_3[1] = 0;
      return;
    }
LAB_c028bb30:
    if (((int)param_2 < 0x7fff) && (-0x8000 < (int)param_2)) {
      uVar4 = 0xf;
      for (uVar3 = param_1 * param_1 + param_2 * param_2; (int)uVar3 < 0x20000000;
          uVar3 = uVar3 << 2) {
        uVar4 = uVar4 + 1;
      }
      param_1 = param_1 << (uVar4 & 0x1f);
      param_2 = param_2 << (uVar4 & 0x1f);
      goto LAB_c028bbfc;
    }
  }
  else if (((int)param_1 < 0x7fff) && (-0x8000 < (int)param_1)) goto LAB_c028bb30;
  for (; ((int)param_1 < 0x20000000 &&
         (((-0x20000000 < (int)param_1 && ((int)param_2 < 0x20000000)) &&
          (-0x20000000 < (int)param_2)))); param_2 = param_2 << 1) {
    param_1 = param_1 << 1;
  }
  iVar2 = FUN_c02750c8(param_1,param_1);
  iVar1 = FUN_c02750c8(param_2,param_2);
  uVar3 = iVar2 + iVar1;
LAB_c028bbfc:
  uVar3 = FUN_c02751fc(uVar3);
  iVar2 = FUN_c02751d8(param_1,uVar3);
  *param_3 = (short)((uint)(iVar2 + 0x8000) >> 0x10);
  iVar2 = FUN_c02751d8(param_2,uVar3);
  param_3[1] = (short)((uint)(iVar2 + 0x8000) >> 0x10);
  return;
}



/* c028bd08 FUN_c028bd08 */

uint FUN_c028bd08(uint param_1,int param_2)

{
  uint uVar1;
  
  if ((int)param_1 < 0) {
    uVar1 = -(param_2 - param_1 & 0xffffffc0);
  }
  else {
    uVar1 = param_1 + param_2 & 0xffffffc0;
  }
  if (((int)(uVar1 ^ param_1) < 0) && (param_1 != 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c028be00 FUN_c028be00 */

uint FUN_c028be00(uint param_1,int param_2)

{
  uint uVar1;
  
  if ((int)param_1 < 0) {
    uVar1 = -((param_2 - param_1) + 0x20 & 0xffffffc0);
  }
  else {
    uVar1 = param_1 + param_2 + 0x20 & 0xffffffc0;
  }
  if (((int)(uVar1 ^ param_1) < 0) && (param_1 != 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c028c060 FUN_c028c060 */

/* Boundary evidence: original MIPS .pdata c028c060..c028c13f. Semantic name remains unreviewed. */

uint FUN_c028c060(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = DAT_c029ad80;
  if ((int)param_1 < 0) {
    uVar2 = FUN_c0274f40((int)(((((int)*(short *)(DAT_c029ad80 + 0x86) -
                                 (int)*(short *)(DAT_c029ad80 + 0x84)) - param_1) + param_2) *
                              0x10000) >> 0x10,(int)*(short *)(DAT_c029ad80 + 0x80));
    iVar3 = FUN_c0274d98(uVar2 & 0xffffffc0,(int)*(short *)(iVar1 + 0x80));
    uVar4 = (uint)*(short *)(iVar1 + 0x84);
    uVar2 = -(uVar4 + iVar3);
  }
  else {
    uVar2 = FUN_c0274f40((int)((((int)*(short *)(DAT_c029ad80 + 0x86) -
                                (int)*(short *)(DAT_c029ad80 + 0x84)) + param_1 + param_2) * 0x10000
                              ) >> 0x10,(int)*(short *)(DAT_c029ad80 + 0x80));
    iVar3 = FUN_c0274d98(uVar2 & 0xffffffc0,(int)*(short *)(iVar1 + 0x80));
    uVar4 = (uint)*(short *)(iVar1 + 0x84);
    uVar2 = uVar4 + iVar3;
  }
  if ((((int)(uVar2 ^ param_1) < 0) && (param_1 != 0)) && (uVar2 = uVar4, (int)param_1 < 1)) {
    uVar2 = -uVar4;
  }
  return uVar2;
}



/* c028c140 FUN_c028c140 */

/* Boundary evidence: original MIPS .pdata c028c140..c028c2cf. Semantic name remains unreviewed. */

void FUN_c028c140(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  
  uVar3 = (uint)DAT_c029ada0;
  uVar2 = (uint)(short)DAT_c029ad6c;
  uVar5 = (uint)DAT_c029ad6c._2_2_;
  if (uVar3 == 0x4000) {
    if (uVar2 != 0) {
      piVar4 = (int *)(param_2 * 4 + *param_1);
      iVar1 = FUN_c0274d98(param_3,uVar2);
      *piVar4 = iVar1 + *piVar4;
      *(byte *)(param_1[9] + param_2) = *(byte *)(param_1[9] + param_2) | 1;
    }
    if (uVar5 == 0) {
      return;
    }
    piVar4 = (int *)(param_1[1] + param_2 * 4);
    iVar1 = FUN_c0274d98(param_3,uVar5);
  }
  else {
    if (uVar2 != 0) {
      if (uVar3 == uVar2) {
        piVar4 = (int *)(param_2 * 4 + *param_1);
        *piVar4 = param_3 + *piVar4;
      }
      else {
        piVar4 = (int *)(param_2 * 4 + *param_1);
        iVar1 = FUN_c0274d38(param_3,uVar2,uVar3);
        *piVar4 = iVar1 + *piVar4;
      }
      *(byte *)(param_1[9] + param_2) = *(byte *)(param_1[9] + param_2) | 1;
    }
    if (uVar5 == 0) {
      return;
    }
    if (uVar3 == uVar5) {
      piVar4 = (int *)(param_1[1] + param_2 * 4);
      *piVar4 = *piVar4 + param_3;
      goto LAB_c028c298;
    }
    piVar4 = (int *)(param_1[1] + param_2 * 4);
    iVar1 = FUN_c0274d38(param_3,uVar5,uVar3);
  }
  *piVar4 = iVar1 + *piVar4;
LAB_c028c298:
  *(byte *)(param_1[9] + param_2) = *(byte *)(param_1[9] + param_2) | 2;
  return;
}



/* c028c330 FUN_c028c330 */

/* Boundary evidence: original MIPS .pdata c028c330..c028c38b. Semantic name remains unreviewed. */

int FUN_c028c330(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_c0274d98(param_2,(int)DAT_c029ad68._2_2_);
  iVar2 = FUN_c0274d98(param_1,(int)(short)DAT_c029ad68);
  return iVar1 + iVar2;
}



/* c028c38c FUN_c028c38c */

/* Boundary evidence: original MIPS .pdata c028c38c..c028c3e7. Semantic name remains unreviewed. */

int FUN_c028c38c(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_c0274d98(param_2,(int)DAT_c029ad72);
  iVar2 = FUN_c0274d98(param_1,(int)DAT_c029ad70);
  return iVar1 + iVar2;
}



/* c028c3f0 FUN_c028c3f0 */

/* Boundary evidence: original MIPS .pdata c028c3f0..c028c4ef. Semantic name remains unreviewed. */

int FUN_c028c3f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = DAT_c029ad80;
  iVar3 = (int)DAT_c029ad68._2_2_;
  iVar6 = (int)(short)DAT_c029ad68;
  if (iVar3 == 0) {
    iVar2 = *(int *)(DAT_c029ad80 + 0x110);
  }
  else if (iVar6 == 0) {
    iVar2 = *(int *)(DAT_c029ad80 + 0x114);
  }
  else {
    iVar2 = DAT_c029adc0;
    if (DAT_c029adc0 == 0) {
      iVar3 = FUN_c0274df0(iVar3,iVar3);
      iVar6 = FUN_c0274df0(iVar6,iVar6);
      uVar4 = *(uint *)(iVar1 + 0x114);
      uVar4 = FUN_c0274f80(uVar4,uVar4);
      uVar5 = *(uint *)(iVar1 + 0x110);
      uVar5 = FUN_c0274f80(uVar5,uVar5);
      iVar1 = FUN_c0274f80(iVar6 << 2,uVar5);
      iVar3 = FUN_c0274f80(iVar3 << 2,uVar4);
      if (iVar1 + iVar3 < 0x10001) {
        iVar1 = FUN_c02751fc((iVar1 + iVar3) * 0x4000);
        iVar2 = iVar1 + 0x2000 >> 0xe;
        DAT_c029adc0 = iVar2;
      }
      else {
        iVar2 = 0x10000;
      }
    }
  }
  return iVar2;
}



/* c028c510 FUN_c028c510 */

/* Boundary evidence: original MIPS .pdata c028c510..c028c557. Semantic name remains unreviewed. */

void FUN_c028c510(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_c028c3f0();
  FUN_c0274f80(*(uint *)(*(int *)(DAT_c029ad80 + 8) + param_1 * 4),uVar1);
  return;
}



/* c028c56c FUN_c028c56c */

/* Boundary evidence: original MIPS .pdata c028c56c..c028c59f. Semantic name remains unreviewed. */

void FUN_c028c56c(void)

{
  uint uVar1;
  
  uVar1 = FUN_c028c3f0();
  FUN_c0274f80(*(uint *)(DAT_c029ad80 + 100),uVar1);
  return;
}



/* c028c5c8 FUN_c028c5c8 */

/* Boundary evidence: original MIPS .pdata c028c5c8..c028c627. Semantic name remains unreviewed. */

void FUN_c028c5c8(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = FUN_c028c3f0();
  iVar2 = FUN_c0275080(param_3,uVar1);
  piVar3 = (int *)(*(int *)(DAT_c029ad80 + 8) + param_2 * 4);
  *piVar3 = iVar2 + *piVar3;
  return;
}



/* c028c628 FUN_c028c628 */

/* Boundary evidence: original MIPS .pdata c028c628..c028c703. Semantic name remains unreviewed. */

void FUN_c028c628(byte *param_1,byte *param_2)

{
  DAT_c029add0 = param_1;
  DAT_c029adcc = param_2;
  while( true ) {
    if (param_2 <= param_1) {
      return;
    }
    if (DAT_c029ad84 == (code *)0x0) {
      return;
    }
    DAT_c029ad9c = *param_1;
    DAT_c029ad78 = param_1;
    (*DAT_c029ad84)(&DAT_c029ad5c,param_2);
    if (DAT_c029ad84 == (code *)0x0) {
      return;
    }
    DAT_c029addc = DAT_c029addc + -1;
    if (DAT_c029addc == 0) break;
    param_1 = (byte *)(*(code *)(&PTR_LAB_c029a6d4)[*param_1])(param_1 + 1);
  }
  DAT_c029adc8 = 0x110e;
  return;
}



/* c028c704 FUN_c028c704 */

/* Boundary evidence: original MIPS .pdata c028c704..c028c79f. Semantic name remains unreviewed. */

void FUN_c028c704(byte *param_1,byte *param_2)

{
  DAT_c029add0 = param_1;
  DAT_c029adcc = param_2;
  while( true ) {
    if (param_2 <= param_1) {
      return;
    }
    DAT_c029addc = DAT_c029addc + -1;
    if (DAT_c029addc == 0) break;
    param_1 = (byte *)(*(code *)(&PTR_LAB_c029a6d4)[*param_1])(param_1 + 1);
  }
  DAT_c029adc8 = 0x110e;
  return;
}



/* c028c7a0 FUN_c028c7a0 */

/* Boundary evidence: original MIPS .pdata c028c7a0..c028cb4b. Semantic name remains unreviewed. */

undefined4
FUN_c028c7a0(void *param_1,void *param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
            int param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_88 [56];
  undefined1 auStack_50 [56];
  
  memcpy(auStack_88,param_1,0x38);
  memcpy(auStack_50,param_2,0x38);
  DAT_c029ad7c = auStack_88;
  DAT_c029ad80 = param_5;
  DAT_c029ad88 = 0;
  DAT_c029ad8c = 0;
  DAT_c029ad90 = 0;
  DAT_c029ad5c = auStack_50;
  DAT_c029ad60 = auStack_50;
  DAT_c029ad64 = auStack_50;
  DAT_c029ad6c._0_2_ = 0x4000;
  DAT_c029ad68._0_2_ = 0x4000;
  DAT_c029ad70 = 0x4000;
  DAT_c029ad6c._2_2_ = 0;
  DAT_c029ad68._2_2_ = 0;
  DAT_c029ad72 = 0;
  DAT_c029ada0 = 0x4000;
  DAT_c029ada4 = &LAB_c028c2d0;
  DAT_c029ada8 = &LAB_c0292fdc;
  DAT_c029adac = &LAB_c0292fdc;
  DAT_c029ad98 = 0;
  DAT_c029add4 = param_5[0x54];
  DAT_c029add8 = param_5[0x55];
  DAT_c029addc = param_5[0x56];
  iVar3 = 1;
  DAT_c029adc4 = (ushort)(param_5[6] == 0);
  if (*(char *)((int)param_5 + 0x125) == '\x01') {
    DAT_c029adb4 = (code *)&LAB_c028c4f0;
    DAT_c029adb8 = (code *)&LAB_c028c558;
    DAT_c029adbc = (code *)&LAB_c028c5a0;
    goto LAB_c028ca54;
  }
  *(ushort *)((int)param_5 + 0x172) = *(ushort *)((int)param_5 + 0x172) & 0xffe4;
  if ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) == 0) {
LAB_c028c934:
    DAT_c029ade0 = 0;
  }
  else {
    if ((*(ushort *)(DAT_c029ad80 + 0x5c) & 4) == 0) {
      if ((DAT_c029ad68._2_2_ == 0x4000) && ((short)DAT_c029ad68 == 0)) goto LAB_c028c9c0;
LAB_c028c924:
      bVar1 = true;
    }
    else {
      if (((short)DAT_c029ad68 != 0x4000) || (DAT_c029ad68._2_2_ != 0)) goto LAB_c028c924;
LAB_c028c9c0:
      bVar1 = false;
    }
    DAT_c029ade0 = 1;
    if (!bVar1) goto LAB_c028c934;
  }
  if ((DAT_c029ade0 == 0) ||
     (((DAT_c029ad80[0x1b] & 4) == 0 && (*(char *)((int)DAT_c029ad80 + 0x125) == '\0')))) {
    iVar3 = 0;
  }
  DAT_c029ad80[0x1d] = (&PTR_LAB_c02617a0)[(uint)*(ushort *)(DAT_c029ad80 + 0x1e) + iVar3 * 8];
  DAT_c029ade4 = 0xffff;
  DAT_c029ade2 = 0xffff;
  if (*(ushort *)(param_5 + 3) < 2) {
    DAT_c029ade2 = 0xffff;
    DAT_c029ade4 = 0xffff;
    return 0;
  }
  if (*(char *)(param_5 + 0x4b) == '\0') {
    DAT_c029adb4 = FUN_c028c510;
    DAT_c029adb8 = FUN_c028c56c;
    DAT_c029adbc = FUN_c028c5c8;
    DAT_c029adc4 = 0;
  }
  else {
    DAT_c029adb4 = (code *)&LAB_c028c4f0;
    DAT_c029adb8 = (code *)&LAB_c028c558;
    DAT_c029adbc = (code *)&LAB_c028c5a0;
  }
  if (*(short *)((int)param_5 + 0x8e) != 0) {
    uVar2 = (*(code *)param_5[0x2b])(param_5 + 0x40);
    param_5[0x19] = uVar2;
    DAT_c029adc4 = 0;
  }
LAB_c028ca54:
  DAT_c029ad74 = *param_5;
  DAT_c029ad84 = param_6;
  DAT_c029adc8 = 0;
  if (param_6 == 0) {
    DAT_c029adb0 = FUN_c028c704;
  }
  else {
    DAT_c029adb0 = FUN_c028c628;
  }
  if (((*(char *)((int)param_5 + 0x125) == '\x02') && ((*(ushort *)(param_5 + 0x5c) & 1) != 0)) &&
     ((*(ushort *)(param_5 + 0x5c) & 2) != 0)) {
    FUN_c028abc0((int)(DAT_c029ad7c + 0x38));
  }
  (*DAT_c029adb0)(param_3,param_4);
  if (((*(char *)((int)DAT_c029ad80 + 0x125) == '\x02') &&
      ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) != 0)) &&
     (((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0 && (*(int *)(DAT_c029ad7c + 0x68) == 0)))) {
    FUN_c028b444(-0x3fd652a4,(int *)(DAT_c029ad7c + 0x38));
  }
  param_5[0x56] = DAT_c029addc;
  return DAT_c029adc8;
}



/* c028cb4c FUN_c028cb4c */

void FUN_c028cb4c(void)

{
  if ((-0x400 < DAT_c029ada0) && (DAT_c029ada0 < 0x400)) {
    if (DAT_c029ada0 < 0) {
      DAT_c029ada0 = -0x4000;
    }
    else {
      DAT_c029ada0 = 0x4000;
    }
  }
  return;
}



/* c028cb94 FUN_c028cb94 */

/* Boundary evidence: original MIPS .pdata c028cb94..c028cc23. Semantic name remains unreviewed. */

void FUN_c028cb94(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  iVar1 = FUN_c0274df0((int)DAT_c029ad68._2_2_,(int)DAT_c029ad6c._2_2_);
  iVar2 = FUN_c0274df0((int)(short)DAT_c029ad68,(int)(short)DAT_c029ad6c);
  iVar1 = (iVar2 + iVar1) * 0x10000 >> 0x10;
  if ((-0x400 < iVar1) && (iVar1 < 0x400)) {
    sVar3 = -0x4000;
    if (-1 < iVar1) {
      sVar3 = 0x4000;
    }
    iVar1 = (int)sVar3;
  }
  DAT_c029ada0 = (short)iVar1;
  DAT_c029adc0 = 0;
  return;
}



/* c028ce00 FUN_c028ce00 */

/* Boundary evidence: original MIPS .pdata c028ce00..c028cf03. Semantic name remains unreviewed. */

undefined4 FUN_c028ce00(undefined4 param_1)

{
  int iVar1;
  
  DAT_c029ad68._0_2_ = 0;
  DAT_c029ad68._2_2_ = 0x4000;
  DAT_c029ada8 = &LAB_c028c3e8;
  iVar1 = 1;
  if (((*(ushort *)(DAT_c029ad80 + 0x170) & 1) == 0) ||
     (DAT_c029ade0 = 1, (*(ushort *)(DAT_c029ad80 + 0x170) & 4) == 0)) {
    DAT_c029ade0 = 0;
  }
  if ((DAT_c029ade0 == 0) ||
     (((*(uint *)(DAT_c029ad80 + 0x6c) & 4) == 0 && (*(char *)(DAT_c029ad80 + 0x125) == '\0')))) {
    iVar1 = 0;
  }
  *(undefined **)(DAT_c029ad80 + 0x74) =
       (&PTR_LAB_c02617a0)[(uint)*(ushort *)(DAT_c029ad80 + 0x78) + iVar1 * 8];
  DAT_c029ade4 = 0xffff;
  DAT_c029ade2 = 0xffff;
  DAT_c029ada0 = DAT_c029ad6c._2_2_;
  FUN_c028cb4c();
  DAT_c029ada4 = FUN_c028c140;
  DAT_c029adac = DAT_c029ada8;
  DAT_c029adc4 = 0;
  return param_1;
}



/* c028cf04 FUN_c028cf04 */

/* Boundary evidence: original MIPS .pdata c028cf04..c028d007. Semantic name remains unreviewed. */

undefined4 FUN_c028cf04(undefined4 param_1)

{
  int iVar1;
  
  DAT_c029ad68._0_2_ = 0x4000;
  DAT_c029ad68._2_2_ = 0;
  DAT_c029ada8 = &LAB_c0292fdc;
  iVar1 = 1;
  if (((*(ushort *)(DAT_c029ad80 + 0x170) & 1) == 0) ||
     (DAT_c029ade0 = 1, (*(ushort *)(DAT_c029ad80 + 0x170) & 4) != 0)) {
    DAT_c029ade0 = 0;
  }
  if ((DAT_c029ade0 == 0) ||
     (((*(uint *)(DAT_c029ad80 + 0x6c) & 4) == 0 && (*(char *)(DAT_c029ad80 + 0x125) == '\0')))) {
    iVar1 = 0;
  }
  *(undefined **)(DAT_c029ad80 + 0x74) =
       (&PTR_LAB_c02617a0)[(uint)*(ushort *)(DAT_c029ad80 + 0x78) + iVar1 * 8];
  DAT_c029ade4 = 0xffff;
  DAT_c029ade2 = 0xffff;
  DAT_c029ada0 = (undefined2)DAT_c029ad6c;
  FUN_c028cb4c();
  DAT_c029ada4 = FUN_c028c140;
  DAT_c029adac = DAT_c029ada8;
  DAT_c029adc4 = 0;
  return param_1;
}



/* c028d008 FUN_c028d008 */

/* Boundary evidence: original MIPS .pdata c028d008..c028d06b. Semantic name remains unreviewed. */

undefined4 FUN_c028d008(undefined4 param_1)

{
  DAT_c029ad6c._0_2_ = 0;
  DAT_c029ad6c._2_2_ = 0x4000;
  DAT_c029ada0 = DAT_c029ad68._2_2_;
  FUN_c028cb4c();
  DAT_c029ada4 = FUN_c028c140;
  DAT_c029adc4 = 0;
  return param_1;
}



/* c028d06c FUN_c028d06c */

/* Boundary evidence: original MIPS .pdata c028d06c..c028d0cf. Semantic name remains unreviewed. */

undefined4 FUN_c028d06c(undefined4 param_1)

{
  DAT_c029ad6c._0_2_ = 0x4000;
  DAT_c029ad6c._2_2_ = 0;
  DAT_c029ada0 = (undefined2)DAT_c029ad68;
  FUN_c028cb4c();
  DAT_c029ada4 = FUN_c028c140;
  DAT_c029adc4 = 0;
  return param_1;
}



/* c028d0d0 FUN_c028d0d0 */

/* Boundary evidence: original MIPS .pdata c028d0d0..c028d35b. Semantic name remains unreviewed. */

undefined4 FUN_c028d0d0(undefined4 param_1,uint param_2)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  iVar4 = *(int *)((int)DAT_c029ad74 + -4);
  DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -8);
  iVar3 = *DAT_c029ad74;
  if (DAT_c029ad7c == DAT_c029ad64) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar4) || (iVar4 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar4) || (iVar4 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  if (DAT_c029ad7c == DAT_c029ad60) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar3) || (iVar3 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar3) || (iVar3 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  DAT_c029ade2 = (undefined2)iVar4;
  DAT_c029ade4 = (undefined2)iVar3;
  FUN_c028bad8(*(int *)(*DAT_c029ad60 + iVar3 * 4) - *(int *)(*DAT_c029ad64 + iVar4 * 4),
               *(int *)(DAT_c029ad60[1] + iVar3 * 4) - *(int *)(DAT_c029ad64[1] + iVar4 * 4),
               (undefined2 *)&DAT_c029ad68);
  if ((param_2 & 1) != 0) {
    sVar2 = -DAT_c029ad68._2_2_;
    DAT_c029ad68._2_2_ = (short)DAT_c029ad68;
    DAT_c029ad68._0_2_ = sVar2;
  }
  FUN_c028cb94();
  DAT_c029ada4 = FUN_c028c140;
  DAT_c029ada8 = FUN_c028c330;
  iVar3 = 1;
  if ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) != 0) {
    if ((*(ushort *)(DAT_c029ad80 + 0x5c) & 4) == 0) {
      sVar2 = (short)DAT_c029ad68;
      if (DAT_c029ad68._2_2_ != 0x4000) goto LAB_c028d2b4;
LAB_c028d2ac:
      bVar1 = false;
      if (sVar2 != 0) goto LAB_c028d2b4;
    }
    else {
      sVar2 = DAT_c029ad68._2_2_;
      if ((short)DAT_c029ad68 == 0x4000) goto LAB_c028d2ac;
LAB_c028d2b4:
      bVar1 = true;
    }
    DAT_c029ade0 = 1;
    if (bVar1) goto LAB_c028d2c8;
  }
  DAT_c029ade0 = 0;
LAB_c028d2c8:
  if ((DAT_c029ade0 == 0) ||
     (((DAT_c029ad80[0x1b] & 4U) == 0 && (*(char *)((int)DAT_c029ad80 + 0x125) == '\0')))) {
    iVar3 = 0;
  }
  DAT_c029ad80[0x1d] = (int)(&PTR_LAB_c02617a0)[(uint)*(ushort *)(DAT_c029ad80 + 0x1e) + iVar3 * 8];
  DAT_c029adc4 = 0;
  DAT_c029adac = DAT_c029ada8;
  return param_1;
}



/* c028d35c FUN_c028d35c */

/* Boundary evidence: original MIPS .pdata c028d35c..c028d657. Semantic name remains unreviewed. */

undefined4 FUN_c028d35c(undefined4 param_1,uint param_2)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  iVar5 = *(int *)((int)DAT_c029ad74 + -4);
  DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -8);
  iVar4 = *DAT_c029ad74;
  if (DAT_c029ad7c == DAT_c029ad64) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar5) || (iVar5 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar5) || (iVar5 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  if (DAT_c029ad7c == DAT_c029ad60) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar4) || (iVar4 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar4) || (iVar4 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  DAT_c029ade2 = (undefined2)iVar5;
  DAT_c029ade4 = (undefined2)iVar4;
  iVar4 = iVar4 * 4;
  iVar5 = iVar5 * 4;
  FUN_c028bad8(*(int *)(*DAT_c029ad60 + iVar4) - *(int *)(*DAT_c029ad64 + iVar5),
               *(int *)(DAT_c029ad60[1] + iVar4) - *(int *)(DAT_c029ad64[1] + iVar5),
               (undefined2 *)&DAT_c029ad68);
  FUN_c028bad8(*(int *)(DAT_c029ad60[2] + iVar4) - *(int *)(DAT_c029ad64[2] + iVar5),
               *(int *)(DAT_c029ad60[3] + iVar4) - *(int *)(DAT_c029ad64[3] + iVar5),&DAT_c029ad70);
  if ((param_2 & 1) != 0) {
    sVar2 = -DAT_c029ad68._2_2_;
    DAT_c029ad68._2_2_ = (short)DAT_c029ad68;
    sVar3 = -DAT_c029ad72;
    DAT_c029ad72 = DAT_c029ad70;
    DAT_c029ad68._0_2_ = sVar2;
    DAT_c029ad70 = sVar3;
  }
  FUN_c028cb94();
  DAT_c029ada4 = FUN_c028c140;
  DAT_c029ada8 = FUN_c028c330;
  iVar4 = 1;
  if ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) != 0) {
    if ((*(ushort *)(DAT_c029ad80 + 0x5c) & 4) == 0) {
      sVar2 = (short)DAT_c029ad68;
      if (DAT_c029ad68._2_2_ != 0x4000) goto LAB_c028d5a4;
LAB_c028d59c:
      bVar1 = false;
      if (sVar2 != 0) goto LAB_c028d5a4;
    }
    else {
      sVar2 = DAT_c029ad68._2_2_;
      if ((short)DAT_c029ad68 == 0x4000) goto LAB_c028d59c;
LAB_c028d5a4:
      bVar1 = true;
    }
    DAT_c029ade0 = 1;
    if (bVar1) goto LAB_c028d5b8;
  }
  DAT_c029ade0 = 0;
LAB_c028d5b8:
  if ((DAT_c029ade0 == 0) ||
     (((DAT_c029ad80[0x1b] & 4U) == 0 && (*(char *)((int)DAT_c029ad80 + 0x125) == '\0')))) {
    iVar4 = 0;
  }
  DAT_c029ad80[0x1d] = (int)(&PTR_LAB_c02617a0)[(uint)*(ushort *)(DAT_c029ad80 + 0x1e) + iVar4 * 8];
  DAT_c029adac = FUN_c028c38c;
  DAT_c029adc4 = 0;
  return param_1;
}



/* c028d658 FUN_c028d658 */

/* Boundary evidence: original MIPS .pdata c028d658..c028d80f. Semantic name remains unreviewed. */

undefined4 FUN_c028d658(undefined4 param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    iVar3 = DAT_c029ad74[-1];
    DAT_c029ad74 = DAT_c029ad74 + -2;
    iVar2 = *DAT_c029ad74;
    if (DAT_c029ad7c == DAT_c029ad64) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar3) || (iVar3 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
    }
    else if ((DAT_c029ad80[0x59] <= iVar3) || (iVar3 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (DAT_c029ad7c == DAT_c029ad60) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar2) || (iVar2 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
    }
    else if ((DAT_c029ad80[0x59] <= iVar2) || (iVar2 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    FUN_c028bad8(*(int *)(*DAT_c029ad60 + iVar2 * 4) - *(int *)(*DAT_c029ad64 + iVar3 * 4),
                 *(int *)(DAT_c029ad60[1] + iVar2 * 4) - *(int *)(DAT_c029ad64[1] + iVar3 * 4),
                 (undefined2 *)&DAT_c029ad6c);
    if ((param_2 & 1) != 0) {
      sVar1 = -DAT_c029ad6c._2_2_;
      DAT_c029ad6c._2_2_ = (short)DAT_c029ad6c;
      DAT_c029ad6c._0_2_ = sVar1;
    }
    FUN_c028cb94();
    DAT_c029ada4 = FUN_c028c140;
    DAT_c029adc4 = 0;
  }
  return param_1;
}



/* c028d810 FUN_c028d810 */

/* Boundary evidence: original MIPS .pdata c028d810..c028d97f. Semantic name remains unreviewed. */

undefined4 FUN_c028d810(undefined4 param_1)

{
  bool bVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  puVar3 = (undefined4 *)((int)DAT_c029ad74 + -4);
  DAT_c029ad74 = (undefined4 *)((int)DAT_c029ad74 + -8);
  DAT_c029ad68._2_2_ = (short)*puVar3;
  DAT_c029ad68._0_2_ = (short)*DAT_c029ad74;
  DAT_c029ade4 = 0xffff;
  DAT_c029ade2 = 0xffff;
  FUN_c028cb94();
  DAT_c029ada4 = FUN_c028c140;
  DAT_c029ada8 = FUN_c028c330;
  iVar4 = 1;
  if ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) != 0) {
    if ((*(ushort *)(DAT_c029ad80 + 0x5c) & 4) == 0) {
      sVar2 = (short)DAT_c029ad68;
      if (DAT_c029ad68._2_2_ != 0x4000) goto LAB_c028d8f8;
LAB_c028d8f0:
      bVar1 = false;
      if (sVar2 != 0) goto LAB_c028d8f8;
    }
    else {
      sVar2 = DAT_c029ad68._2_2_;
      if ((short)DAT_c029ad68 == 0x4000) goto LAB_c028d8f0;
LAB_c028d8f8:
      bVar1 = true;
    }
    DAT_c029ade0 = 1;
    if (bVar1) goto LAB_c028d90c;
  }
  DAT_c029ade0 = 0;
LAB_c028d90c:
  if ((DAT_c029ade0 == 0) ||
     (((DAT_c029ad80[0x1b] & 4U) == 0 && (*(char *)((int)DAT_c029ad80 + 0x125) == '\0')))) {
    iVar4 = 0;
  }
  DAT_c029ad80[0x1d] = (int)(&PTR_LAB_c02617a0)[(uint)*(ushort *)(DAT_c029ad80 + 0x1e) + iVar4 * 8];
  DAT_c029adc4 = 0;
  DAT_c029adac = DAT_c029ada8;
  return param_1;
}



/* c028d980 FUN_c028d980 */

/* Boundary evidence: original MIPS .pdata c028d980..c028da17. Semantic name remains unreviewed. */

undefined4 FUN_c028d980(undefined4 param_1)

{
  undefined4 *puVar1;
  
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    puVar1 = DAT_c029ad74 + -1;
    DAT_c029ad74 = DAT_c029ad74 + -2;
    DAT_c029ad6c._2_2_ = (undefined2)*puVar1;
    DAT_c029ad6c._0_2_ = (undefined2)*DAT_c029ad74;
    FUN_c028cb94();
    DAT_c029ada4 = FUN_c028c140;
    DAT_c029adc4 = 0;
  }
  return param_1;
}



/* c028db1c FUN_c028db1c */

/* Boundary evidence: original MIPS .pdata c028db1c..c028e0df. Semantic name remains unreviewed. */

undefined4 FUN_c028db1c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int local_30;
  
  iVar10 = (int)DAT_c029ad74;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 5) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  iVar13 = *(int *)((int)DAT_c029ad74 + -4);
  iVar12 = *(int *)((int)DAT_c029ad74 + -8);
  if (DAT_c029ad7c == DAT_c029ad5c) {
    if ((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar13) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (iVar13 < 0) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else {
    if (DAT_c029ad80[0x59] <= iVar13) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (iVar13 < 0) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  if (DAT_c029ad7c == DAT_c029ad5c) {
    if ((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar12) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (iVar12 < 0) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else {
    if (DAT_c029ad80[0x59] <= iVar12) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (iVar12 < 0) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  iVar3 = *(int *)(*DAT_c029ad5c + iVar12 * 4);
  uVar11 = *(int *)(iVar13 * 4 + *DAT_c029ad5c) - iVar3;
  iVar4 = *(int *)(DAT_c029ad5c[1] + iVar12 * 4);
  uVar14 = *(int *)(DAT_c029ad5c[1] + iVar13 * 4) - iVar4;
  if ((*(char *)((int)DAT_c029ad80 + 0x125) != '\x02') ||
     ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) == 0)) {
    iVar12 = local_30;
    iVar13 = local_30;
  }
  iVar7 = *(int *)((int)DAT_c029ad74 + -0xc);
  iVar9 = *(int *)((int)DAT_c029ad74 + -0x10);
  if (DAT_c029ad7c == DAT_c029ad60) {
    if ((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar7) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (iVar7 < 0) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else {
    if (DAT_c029ad80[0x59] <= iVar7) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (iVar7 < 0) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  if (DAT_c029ad7c == DAT_c029ad60) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar9) || (iVar9 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar9) || (iVar9 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  iVar5 = *(int *)(*DAT_c029ad60 + iVar9 * 4);
  uVar16 = *(int *)(iVar7 * 4 + *DAT_c029ad60) - iVar5;
  iVar6 = *(int *)(DAT_c029ad60[1] + iVar9 * 4);
  uVar15 = *(int *)(DAT_c029ad60[1] + iVar7 * 4) - iVar6;
  if ((*(char *)((int)DAT_c029ad80 + 0x125) == '\x02') &&
     ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)) {
    uVar1 = FUN_c0274e28(uVar15,uVar11);
    if ((int)uVar1 < 0) {
      uVar1 = FUN_c0274e28(uVar15,uVar11);
      uVar1 = -uVar1;
    }
    else {
      uVar1 = FUN_c0274e28(uVar15,uVar11);
    }
    uVar2 = FUN_c0274e28(uVar16,uVar14);
    if ((int)uVar2 < 0) {
      uVar2 = FUN_c0274e28(uVar16,uVar14);
      uVar2 = -uVar2;
    }
    else {
      uVar2 = FUN_c0274e28(uVar16,uVar14);
    }
    if ((int)uVar2 < (int)uVar1) {
      iVar12 = iVar9;
      iVar13 = iVar7;
    }
  }
  piVar8 = (int *)(iVar10 + -0x14);
  iVar10 = *piVar8;
  if (DAT_c029ad7c == DAT_c029ad64) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar10) || (iVar10 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar10) || (iVar10 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  DAT_c029ad74 = piVar8;
  if (((DAT_c029ad64 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
     ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)) {
    FUN_c028aed4(&DAT_c029ad5c,(int)DAT_c029ad64,iVar12,iVar10,iVar13);
  }
  *(byte *)(DAT_c029ad64[9] + iVar10) = *(byte *)(DAT_c029ad64[9] + iVar10) | 3;
  iVar12 = *DAT_c029ad64;
  iVar13 = DAT_c029ad64[1];
  if (uVar14 == 0) {
    if (uVar16 == 0) {
      *(int *)(iVar10 * 4 + iVar12) = iVar5;
      *(int *)(iVar10 * 4 + iVar13) = iVar4;
      return param_1;
    }
    uVar2 = iVar6 - iVar4;
    uVar1 = -uVar15;
  }
  else if (uVar11 == 0) {
    if (uVar15 == 0) {
      *(int *)(iVar10 * 4 + iVar12) = iVar3;
      *(int *)(iVar10 * 4 + iVar13) = iVar6;
      return param_1;
    }
    uVar2 = iVar5 - iVar3;
    uVar1 = -uVar16;
  }
  else {
    uVar1 = -uVar11;
    if (-1 < (int)uVar11) {
      uVar1 = uVar11;
    }
    uVar2 = -uVar14;
    if (-1 < (int)uVar14) {
      uVar2 = uVar14;
    }
    if ((int)uVar1 < (int)uVar2) {
      iVar7 = FUN_c0274d38(iVar6 - iVar4,uVar11,uVar14);
      uVar2 = iVar7 + (iVar3 - iVar5);
      iVar7 = FUN_c0274d38(uVar15,uVar11,uVar14);
      uVar1 = uVar16 - iVar7;
    }
    else {
      iVar7 = FUN_c0274d38(iVar5 - iVar3,uVar14,uVar11);
      uVar2 = (iVar6 - iVar4) - iVar7;
      iVar7 = FUN_c0274d38(uVar16,uVar14,uVar11);
      uVar1 = iVar7 - uVar15;
    }
  }
  if (uVar1 == 0) {
    *(int *)(iVar10 * 4 + iVar12) = ((int)uVar16 >> 1) + ((int)uVar11 >> 1) + iVar5 + iVar3 >> 1;
    *(int *)(iVar10 * 4 + iVar13) = ((int)uVar15 >> 1) + ((int)uVar14 >> 1) + iVar6 + iVar4 >> 1;
    return param_1;
  }
  iVar3 = FUN_c0274d38(uVar16,uVar2,uVar1);
  *(int *)(iVar10 * 4 + iVar12) = iVar3 + iVar5;
  iVar12 = FUN_c0274d38(uVar15,uVar2,uVar1);
  *(int *)(iVar10 * 4 + iVar13) = iVar12 + iVar6;
  return param_1;
}



/* c028e1d8 FUN_c028e1d8 */

/* Boundary evidence: original MIPS .pdata c028e1d8..c028e263. Semantic name remains unreviewed. */

undefined4 FUN_c028e1d8(undefined4 param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = DAT_c029ad80;
  DAT_c029adc4 = 0;
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -2;
    sVar1 = *DAT_c029ad74;
    piVar4 = DAT_c029ad80 + 0x40;
    *(short *)((int)DAT_c029ad80 + 0x8e) = sVar1;
    iVar3 = (*(code *)piVar2[0x2b])(piVar4,(int)sVar1);
    piVar2[0x19] = iVar3;
  }
  return param_1;
}



/* c028e778 FUN_c028e778 */

void FUN_c028e778(uint param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  
  iVar1 = DAT_c029ad80;
  uVar3 = param_1 & 0xc0;
  if (param_2 == 0) {
    *(undefined2 *)(DAT_c029ad80 + 0x80) = 0x2d47;
    if (uVar3 == 0) {
      *(undefined2 *)(iVar1 + 0x80) = 0x16a3;
    }
    else if (uVar3 != 0x40) {
      if (uVar3 == 0x80) {
        *(undefined2 *)(iVar1 + 0x80) = 0x5a8e;
      }
      else {
        *(undefined2 *)(iVar1 + 0x80) = 999;
      }
    }
    *(short *)(iVar1 + 0x82) = (short)((uint)(*(short *)(iVar1 + 0x80) + 0x80) >> 8);
    goto LAB_c028e834;
  }
  if (uVar3 == 0) {
    *(undefined2 *)(DAT_c029ad80 + 0x82) = 0x20;
  }
  else {
    uVar2 = 0x40;
    if (uVar3 != 0x40) {
      if (uVar3 == 0x80) {
        *(undefined2 *)(DAT_c029ad80 + 0x82) = 0x80;
        goto LAB_c028e7cc;
      }
      uVar2 = 999;
    }
    *(undefined2 *)(DAT_c029ad80 + 0x82) = uVar2;
  }
LAB_c028e7cc:
  *(uint *)(iVar1 + 0x7c) = ~((int)*(short *)(iVar1 + 0x82) - 1U);
LAB_c028e834:
  uVar3 = param_1 & 0x30;
  if (uVar3 == 0) {
    *(undefined2 *)(iVar1 + 0x84) = 0;
  }
  else if (uVar3 == 0x10) {
    *(short *)(iVar1 + 0x84) = (short)(*(short *)(iVar1 + 0x82) + 2 >> 2);
  }
  else if (uVar3 == 0x20) {
    *(short *)(iVar1 + 0x84) = (short)(*(short *)(iVar1 + 0x82) + 1 >> 1);
  }
  else if (uVar3 == 0x30) {
    *(short *)(iVar1 + 0x84) = (short)(*(short *)(iVar1 + 0x82) * 3 + 2 >> 2);
  }
  if ((param_1 & 0xf) == 0) {
    *(short *)(iVar1 + 0x86) = *(short *)(iVar1 + 0x82) + -1;
  }
  else {
    *(short *)(iVar1 + 0x86) =
         (short)((int)(((param_1 & 0xf) - 4) * (int)*(short *)(iVar1 + 0x82) + 4) >> 3);
  }
  return;
}



/* c028ec70 FUN_c028ec70 */

/* Boundary evidence: original MIPS .pdata c028ec70..c028edc3. Semantic name remains unreviewed. */

undefined4 FUN_c028ec70(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = DAT_c029ad80;
  piVar1 = DAT_c029ad5c;
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    iVar5 = *DAT_c029ad74;
    if (DAT_c029ad7c == DAT_c029ad5c) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar5) || (iVar5 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
    }
    else if ((DAT_c029ad80[0x59] <= iVar5) || (iVar5 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    DAT_c029ad88 = iVar5;
    DAT_c029ad8c = iVar5;
    if ((param_2 & 1) == 0) {
      iVar4 = 0;
    }
    else {
      iVar3 = (*DAT_c029ada8)(*(undefined4 *)(*DAT_c029ad5c + iVar5 * 4),
                              *(undefined4 *)(DAT_c029ad5c[1] + iVar5 * 4));
      iVar4 = (*(code *)piVar2[0x1d])(iVar3,DAT_c029ad80[5]);
      iVar4 = iVar4 - iVar3;
    }
    (*DAT_c029ada4)(piVar1,iVar5,iVar4);
  }
  return param_1;
}



/* c028edc4 FUN_c028edc4 */

/* Boundary evidence: original MIPS .pdata c028edc4..c028eff3. Semantic name remains unreviewed. */

undefined4 FUN_c028edc4(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  piVar2 = DAT_c029ad80;
  piVar1 = DAT_c029ad5c;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    if ((*DAT_c029ad74 < (int)(uint)*(ushort *)(DAT_c029ad80 + 0x4d)) && (-1 < *DAT_c029ad74)) {
      uVar3 = (*DAT_c029adb4)();
      DAT_c029ad74 = DAT_c029ad74 + -1;
      iVar7 = *DAT_c029ad74;
      if (DAT_c029ad7c == piVar1) {
        if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar7) || (iVar7 < 0)) {
          DAT_c029adc8 = 0x1112;
          return DAT_c029adcc;
        }
      }
      else if ((DAT_c029ad80[0x59] <= iVar7) || (iVar7 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
      DAT_c029ad88 = iVar7;
      DAT_c029ad8c = iVar7;
      if (piVar1 == DAT_c029ad7c) {
        iVar6 = iVar7 * 4;
        iVar4 = FUN_c0274d98(uVar3,(int)(short)DAT_c029ad68);
        *(int *)(*piVar1 + iVar6) = iVar4;
        *(undefined4 *)(piVar1[2] + iVar6) = *(undefined4 *)(*piVar1 + iVar6);
        iVar4 = FUN_c0274d98(uVar3,(int)DAT_c029ad68._2_2_);
        *(int *)(piVar1[1] + iVar6) = iVar4;
        *(undefined4 *)(piVar1[3] + iVar6) = *(undefined4 *)(piVar1[1] + iVar6);
      }
      uVar5 = (*DAT_c029ada8)(*(undefined4 *)(*piVar1 + iVar7 * 4),
                              *(undefined4 *)(piVar1[1] + iVar7 * 4));
      if ((param_2 & 1) != 0) {
        iVar4 = uVar3 - uVar5;
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        if (piVar2[0x17] < iVar4) {
          uVar3 = uVar5;
        }
        uVar3 = (*(code *)piVar2[0x1d])(uVar3,DAT_c029ad80[5]);
      }
      (*DAT_c029ada4)(piVar1,iVar7,uVar3 - uVar5);
    }
    else {
      DAT_c029adc8 = 0x111b;
      param_1 = DAT_c029adcc;
    }
  }
  return param_1;
}



/* c028eff4 FUN_c028eff4 */

/* Boundary evidence: original MIPS .pdata c028eff4..c028f5cf. Semantic name remains unreviewed. */

undefined4 FUN_c028eff4(undefined4 param_1,ushort param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int *piVar24;
  int iVar25;
  int *piVar26;
  int local_54;
  int local_50;
  
  piVar2 = DAT_c029ad64;
  if (*(char *)(DAT_c029ad80 + 0x125) == '\x02') {
    if ((((DAT_c029ad64 != DAT_c029ad7c) &&
         (uVar7 = *(ushort *)(DAT_c029ad80 + 0x170), (uVar7 & 1) != 0)) && ((uVar7 & 2) != 0)) &&
       (((uVar7 & 4) != (param_2 & 1) && (DAT_c029ad64[0xc] == 0)))) {
      FUN_c028b444(-0x3fd652a4,DAT_c029ad64);
    }
  }
  else if ((*(char *)(DAT_c029ad80 + 0x125) != '\0') || (DAT_c029ad7c != DAT_c029ad64)) {
    DAT_c029adc8 = 0x111c;
    return DAT_c029adcc;
  }
  iVar25 = piVar2[9];
  if ((param_2 & 1) == 0) {
    iVar3 = piVar2[3];
    iVar21 = piVar2[1];
    iVar22 = iVar3;
    if (*(char *)(DAT_c029ad80 + 0x14d) == '\0') {
      iVar22 = piVar2[5];
    }
    bVar6 = 2;
  }
  else {
    iVar3 = piVar2[2];
    iVar21 = *piVar2;
    iVar22 = iVar3;
    if (*(char *)(DAT_c029ad80 + 0x14d) == '\0') {
      iVar22 = piVar2[4];
    }
    bVar6 = 1;
  }
  local_54 = 0;
  if ((short)piVar2[10] < 1) {
LAB_c028f544:
    uVar7 = 1;
    if ((param_2 & 1) == 0) {
      uVar7 = 2;
    }
    *(ushort *)(DAT_c029ad80 + 0x172) = *(ushort *)(DAT_c029ad80 + 0x172) | uVar7;
    return param_1;
  }
  local_50 = 0;
LAB_c028f154:
  iVar12 = (int)*(short *)(local_50 + piVar2[8]);
  iVar8 = (int)*(short *)(local_50 + piVar2[7]);
  for (iVar17 = iVar8; iVar17 <= iVar12; iVar17 = iVar17 + 1) {
    iVar10 = iVar17;
    if ((*(byte *)(iVar17 + iVar25) & bVar6) != 0) goto LAB_c028f1bc;
  }
  goto LAB_c028f514;
LAB_c028f1bc:
  do {
    do {
      iVar14 = iVar10;
      iVar10 = iVar14 + 1;
      if (iVar12 < iVar14 + 1) {
        iVar10 = iVar8;
      }
    } while (((*(byte *)(iVar10 + iVar25) & bVar6) != 0) && (iVar10 != iVar17));
    iVar11 = iVar10;
    if (iVar10 == iVar17) break;
    do {
      iVar18 = iVar11 + 1;
      if (iVar12 < iVar11 + 1) {
        iVar18 = iVar8;
      }
      iVar11 = iVar18;
    } while ((*(byte *)(iVar18 + iVar25) & bVar6) == 0);
    piVar26 = (int *)(iVar18 * 4 + iVar22);
    iVar13 = *(int *)(iVar14 * 4 + iVar22);
    iVar11 = *piVar26;
    if (iVar13 < iVar11) {
      uVar4 = iVar11 - iVar13;
      iVar11 = iVar13;
      iVar13 = iVar14;
      iVar14 = iVar18;
    }
    else {
      uVar4 = iVar13 - iVar11;
      iVar13 = iVar18;
    }
    iVar5 = *(int *)(iVar13 * 4 + iVar21);
    iVar19 = *(int *)(iVar13 * 4 + iVar3);
    iVar13 = iVar5 - iVar19;
    if (uVar4 == 0) {
      while (iVar10 != iVar18) {
        piVar26 = (int *)(iVar10 * 4 + iVar21);
        *piVar26 = *piVar26 + iVar13;
        bVar1 = iVar12 <= iVar10;
        iVar10 = iVar10 + 1;
        if (bVar1) {
          iVar10 = iVar8;
        }
      }
    }
    else {
      iVar9 = *(int *)(iVar14 * 4 + iVar21);
      iVar23 = *(int *)(iVar14 * 4 + iVar3);
      iVar14 = iVar9 - iVar23;
      iVar9 = iVar9 - iVar5;
      if (((int)uVar4 < 0x8000) && (iVar9 < 0x8000)) {
        iVar10 = iVar10 * 4;
        piVar24 = (int *)(iVar10 + iVar3);
        piVar15 = (int *)(iVar10 + iVar21);
        for (piVar16 = (int *)(iVar10 + iVar22); piVar16 < piVar26; piVar16 = piVar16 + 1) {
          iVar10 = *piVar24;
          if (iVar19 < iVar10) {
            if (iVar10 < iVar23) {
              iVar10 = (*piVar16 - iVar11) * iVar9 + ((int)uVar4 >> 1);
              if (uVar4 == 0) {
                trap(0x1c00);
              }
              if ((uVar4 == 0xffffffff) && (iVar10 == -0x80000000)) {
                trap(0x1800);
              }
              *piVar15 = iVar10 / (int)uVar4 + iVar5;
            }
            else {
LAB_c028f35c:
              *piVar15 = iVar10 + iVar14;
            }
          }
          else {
            if (iVar23 <= iVar10) goto LAB_c028f35c;
            *piVar15 = iVar10 + iVar13;
          }
          piVar24 = piVar24 + 1;
          piVar15 = piVar15 + 1;
        }
        while (iVar10 = iVar18, piVar16 != piVar26) {
          iVar10 = *piVar24;
          if (iVar19 < iVar10) {
            if (iVar10 < iVar23) {
              iVar10 = (*piVar16 - iVar11) * iVar9 + ((int)uVar4 >> 1);
              if (uVar4 == 0) {
                trap(0x1c00);
              }
              if ((uVar4 == 0xffffffff) && (iVar10 == -0x80000000)) {
                trap(0x1800);
              }
              *piVar15 = iVar10 / (int)uVar4 + iVar5;
            }
            else {
LAB_c028f408:
              *piVar15 = iVar10 + iVar14;
            }
          }
          else {
            if (iVar23 <= iVar10) goto LAB_c028f408;
            *piVar15 = iVar10 + iVar13;
          }
          piVar16 = piVar16 + 1;
          piVar24 = piVar24 + 1;
          piVar15 = piVar15 + 1;
          if ((int *)(iVar12 * 4 + iVar22) < piVar16) {
            iVar10 = iVar8 * 4;
            piVar16 = (int *)(iVar10 + iVar22);
            piVar24 = (int *)(iVar10 + iVar3);
            piVar15 = (int *)(iVar10 + iVar21);
          }
        }
      }
      else {
        uVar4 = FUN_c0275080(iVar9,uVar4);
        while (iVar10 != iVar18) {
          iVar20 = iVar10 * 4;
          iVar9 = *(int *)(iVar20 + iVar3);
          if (iVar19 < iVar9) {
            if (iVar9 < iVar23) {
              iVar9 = FUN_c0274f80(*(int *)(iVar20 + iVar22) - iVar11,uVar4);
              iVar9 = iVar9 + iVar5;
            }
            else {
              iVar9 = iVar9 + iVar14;
            }
          }
          else {
            iVar9 = iVar9 + iVar13;
          }
          bVar1 = iVar12 <= iVar10;
          *(int *)(iVar20 + iVar21) = iVar9;
          iVar10 = iVar10 + 1;
          if (bVar1) {
            iVar10 = iVar8;
          }
        }
      }
    }
  } while (iVar10 != iVar17);
LAB_c028f514:
  local_54 = local_54 + 1;
  local_50 = local_50 + 2;
  if ((short)piVar2[10] <= local_54) goto LAB_c028f544;
  goto LAB_c028f154;
}



/* c028f5d0 FUN_c028f5d0 */

/* Boundary evidence: original MIPS .pdata c028f5d0..c028f72f. Semantic name remains unreviewed. */

int * FUN_c028f5d0(int *param_1,int *param_2,int *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = DAT_c029ad60;
  iVar5 = DAT_c029ad90;
  if ((param_4 & 1) != 0) {
    piVar4 = DAT_c029ad5c;
    iVar5 = DAT_c029ad8c;
  }
  iVar3 = iVar5 * 4;
  uVar1 = (*DAT_c029ada8)(*(int *)(*piVar4 + iVar3) - *(int *)(piVar4[2] + iVar3),
                          *(int *)(piVar4[1] + iVar3) - *(int *)(piVar4[3] + iVar3));
  *param_2 = 0;
  *param_1 = 0;
  uVar2 = (uint)DAT_c029ada0;
  if (uVar2 == 0x4000) {
    if ((int)(short)DAT_c029ad6c != 0) {
      iVar3 = FUN_c0274d98(uVar1,(int)(short)DAT_c029ad6c);
      *param_1 = iVar3;
    }
    if ((int)DAT_c029ad6c._2_2_ == 0) goto LAB_c028f700;
    iVar3 = FUN_c0274d98(uVar1,(int)DAT_c029ad6c._2_2_);
  }
  else {
    if ((int)(short)DAT_c029ad6c != 0) {
      iVar3 = FUN_c0274d38(uVar1,(int)(short)DAT_c029ad6c,uVar2);
      *param_1 = iVar3;
      uVar2 = (uint)DAT_c029ada0;
    }
    if ((int)DAT_c029ad6c._2_2_ == 0) goto LAB_c028f700;
    iVar3 = FUN_c0274d38(uVar1,(int)DAT_c029ad6c._2_2_,uVar2);
  }
  *param_2 = iVar3;
LAB_c028f700:
  *param_3 = iVar5;
  return piVar4;
}



/* c028f730 FUN_c028f730 */

/* Boundary evidence: original MIPS .pdata c028f730..c028fa23. Semantic name remains unreviewed. */

undefined4 FUN_c028f730(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  int *piVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  short sVar14;
  
  piVar2 = DAT_c029ad64;
  iVar13 = DAT_c029ad98 + 1;
  piVar9 = DAT_c029ad64;
  sVar5 = DAT_c029ade0;
  iVar11 = DAT_c029ad80;
  piVar3 = DAT_c029ad7c;
  sVar7 = DAT_c029ad6c._2_2_;
  sVar6 = (short)DAT_c029ad6c;
  sVar14 = DAT_c029ad68._2_2_;
  sVar4 = (short)DAT_c029ad68;
  do {
    if (iVar13 == 0) {
      DAT_c029ad98 = 0;
      return param_1;
    }
    DAT_c029ad74 = DAT_c029ad74 + -1;
    iVar12 = *DAT_c029ad74;
    if (piVar3 == piVar9) {
      uVar8 = (uint)*(ushort *)(*(int *)(iVar11 + 0x130) + 0x10);
    }
    else {
      uVar8 = *(uint *)(iVar11 + 0x164);
    }
    if (((int)uVar8 <= iVar12) || (iVar12 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if ((((piVar2 != piVar3) && (*(char *)(iVar11 + 0x125) == '\x02')) && (sVar5 != 0)) &&
       ((*(ushort *)(iVar11 + 0x170) & 2) != 0)) {
      FUN_c028ad0c(&DAT_c029ad5c,(int)piVar2,param_2,iVar12,3);
      piVar3 = DAT_c029ad7c;
      iVar11 = DAT_c029ad80;
      piVar9 = DAT_c029ad64;
      sVar7 = DAT_c029ad6c._2_2_;
      sVar6 = (short)DAT_c029ad6c;
      sVar14 = DAT_c029ad68._2_2_;
      sVar4 = (short)DAT_c029ad68;
      sVar5 = DAT_c029ade0;
    }
    if ((param_3 == 0) || (uVar10 = *(ushort *)(iVar11 + 0x172), (uVar10 & 0x10) == 0)) {
LAB_c028f92c:
      if (sVar6 != 0) {
        piVar9 = (int *)(iVar12 * 4 + *piVar2);
        *piVar9 = *piVar9 + param_4;
        *(byte *)(piVar2[9] + iVar12) = *(byte *)(piVar2[9] + iVar12) | 1;
        piVar3 = DAT_c029ad7c;
        iVar11 = DAT_c029ad80;
        piVar9 = DAT_c029ad64;
        sVar7 = DAT_c029ad6c._2_2_;
        sVar6 = (short)DAT_c029ad6c;
        sVar14 = DAT_c029ad68._2_2_;
        sVar4 = (short)DAT_c029ad68;
        sVar5 = DAT_c029ade0;
      }
      if (sVar7 != 0) {
        piVar9 = (int *)(iVar12 * 4 + piVar2[1]);
        *piVar9 = *piVar9 + param_5;
        *(byte *)(piVar2[9] + iVar12) = *(byte *)(piVar2[9] + iVar12) | 2;
        piVar3 = DAT_c029ad7c;
        iVar11 = DAT_c029ad80;
        piVar9 = DAT_c029ad64;
        sVar7 = DAT_c029ad6c._2_2_;
        sVar6 = (short)DAT_c029ad6c;
        sVar4 = (short)DAT_c029ad68;
        sVar14 = DAT_c029ad68._2_2_;
        sVar5 = DAT_c029ade0;
      }
    }
    else {
      if ((*(ushort *)(iVar11 + 0x170) & 4) == 0) {
        if ((sVar14 != 0x4000) || (sVar4 != 0)) goto LAB_c028f920;
        if (*(char *)(iVar11 + 0x12d) == '\0') {
          if ((*(byte *)(piVar9[9] + iVar12) & 2) != 0) {
            uVar10 = uVar10 & 2;
LAB_c028f910:
            if (uVar10 == 0) goto LAB_c028f918;
          }
          goto LAB_c028f920;
        }
LAB_c028f918:
        bVar1 = true;
      }
      else {
        if ((sVar4 == 0x4000) && (sVar14 == 0)) {
          if (*(char *)(iVar11 + 0x12d) != '\0') goto LAB_c028f918;
          if ((*(byte *)(piVar9[9] + iVar12) & 1) != 0) {
            uVar10 = uVar10 & 1;
            goto LAB_c028f910;
          }
        }
LAB_c028f920:
        bVar1 = false;
      }
      if (bVar1) goto LAB_c028f92c;
    }
    iVar13 = iVar13 + -1;
  } while( true );
}



/* c028fa24 FUN_c028fa24 */

/* Boundary evidence: original MIPS .pdata c028fa24..c028fb6f. Semantic name remains unreviewed. */

undefined4 FUN_c028fa24(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18 [2];
  
  if ((param_2 & 1) == 0) {
    if (DAT_c029ad7c == DAT_c029ad60) {
      iVar2 = DAT_c029ad80[0x4c];
      iVar3 = DAT_c029ad90;
      goto LAB_c028fa60;
    }
    if ((DAT_c029ad90 < DAT_c029ad80[0x59]) && (-1 < DAT_c029ad90)) goto LAB_c028fb08;
LAB_c028fa78:
    DAT_c029adc8 = 0x1112;
    uVar1 = DAT_c029adcc;
  }
  else {
    if (DAT_c029ad7c == DAT_c029ad5c) {
      iVar2 = DAT_c029ad80[0x4c];
      iVar3 = DAT_c029ad8c;
LAB_c028fa60:
      if (((int)(uint)*(ushort *)(iVar2 + 0x10) <= iVar3) || (iVar3 < 0)) goto LAB_c028fa78;
    }
    else if ((DAT_c029ad80[0x59] <= DAT_c029ad8c) || (DAT_c029ad8c < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
LAB_c028fb08:
    FUN_c028f5d0(&local_1c,&local_20,local_18,param_2);
    if ((uint)(DAT_c029ad74 - *DAT_c029ad80 >> 2) < DAT_c029ad98 + 1U) {
      DAT_c029adc8 = 0x1110;
      uVar1 = DAT_c029adcc;
    }
    else {
      uVar1 = FUN_c028f730(param_1,local_18[0],0,local_1c,local_20);
    }
  }
  return uVar1;
}



/* c028fb70 FUN_c028fb70 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c028fb70..c028feab. Semantic name remains unreviewed. */

undefined4 FUN_c028fb70(undefined4 param_1,uint param_2)

{
  ushort uVar1;
  int *piVar2;
  short sVar3;
  short sVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_30;
  int local_2c;
  int local_28 [2];
  
  if ((param_2 & 1) == 0) {
    iVar8 = DAT_c029ad90;
    if (DAT_c029ad7c == DAT_c029ad60) {
      iVar7 = DAT_c029ad80[0x4c];
      goto LAB_c028fbc0;
    }
    if (DAT_c029ad80[0x59] <= DAT_c029ad90) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else {
    if (DAT_c029ad7c != DAT_c029ad5c) {
      if (DAT_c029ad80[0x59] <= DAT_c029ad8c) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
      if (DAT_c029ad8c < 0) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
      goto LAB_c028fc80;
    }
    iVar7 = DAT_c029ad80[0x4c];
    iVar8 = DAT_c029ad8c;
LAB_c028fbc0:
    if ((int)(uint)*(ushort *)(iVar7 + 0x10) <= iVar8) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  if (iVar8 < 0) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
LAB_c028fc80:
  piVar5 = FUN_c028f5d0(&local_30,local_28,&local_2c,param_2);
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -4);
  iVar8 = *DAT_c029ad74;
  if (((((piVar5 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
       (uVar1 = *(ushort *)(DAT_c029ad80 + 0x5c), (uVar1 & 1) != 0)) &&
      (((uVar1 & 2) != 0 && ((uVar1 & 4) == 0)))) && (piVar5[0xc] == 0)) {
    FUN_c028b444(-0x3fd652a4,piVar5);
    local_30 = *(int *)(piVar5[0xd] + local_2c * 0xc + 8) + local_30;
  }
  sVar4 = DAT_c029ad6c._2_2_;
  sVar3 = (short)DAT_c029ad6c;
  piVar2 = DAT_c029ad64;
  if ((*(char *)((int)DAT_c029ad80 + 0x125) != '\x02') &&
     ((*(char *)((int)DAT_c029ad80 + 0x125) != '\0' || (DAT_c029ad7c != DAT_c029ad64)))) {
    DAT_c029adc8 = 0x111c;
    return DAT_c029adcc;
  }
  if ((iVar8 < 0) || ((short)DAT_c029ad64[10] <= iVar8)) {
    DAT_c029adc8 = 0x111a;
    return DAT_c029adcc;
  }
  iVar7 = (int)*(short *)(DAT_c029ad64[7] + iVar8 * 2);
  iVar8 = *(short *)(DAT_c029ad64[8] + iVar8 * 2) - iVar7;
  if (DAT_c029ad7c == DAT_c029ad64) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar8 + iVar7) || (iVar8 + iVar7 < 0))
    {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar8 + iVar7) || (iVar8 + iVar7 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  if (-1 < iVar8) {
    iVar6 = iVar7 << 2;
    do {
      if ((iVar7 != local_2c) || (piVar5 != piVar2)) {
        if (sVar3 != 0) {
          *(int *)(*piVar2 + iVar6) = *(int *)(*piVar2 + iVar6) + local_30;
          *(byte *)(piVar2[9] + iVar7) = *(byte *)(piVar2[9] + iVar7) | 1;
        }
        if (sVar4 != 0) {
          *(int *)(piVar2[1] + iVar6) = *(int *)(piVar2[1] + iVar6) + local_28[0];
          *(byte *)(piVar2[9] + iVar7) = *(byte *)(piVar2[9] + iVar7) | 2;
        }
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + -1;
      iVar6 = iVar6 + 4;
    } while (-1 < iVar8);
    return param_1;
  }
  return param_1;
}



/* c028feac FUN_c028feac */

/* Boundary evidence: original MIPS .pdata c028feac..c02901f7. Semantic name remains unreviewed. */

undefined4 FUN_c028feac(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int local_20;
  int local_1c;
  int local_18 [2];
  
  if ((param_2 & 1) == 0) {
    if (DAT_c029ad7c != DAT_c029ad60) {
      if (DAT_c029ad80[0x59] <= DAT_c029ad90) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
      if (DAT_c029ad90 < 0) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
      goto LAB_c028ff7c;
    }
    iVar4 = DAT_c029ad80[0x4c];
    iVar6 = DAT_c029ad90;
  }
  else {
    if (DAT_c029ad7c != DAT_c029ad5c) {
      if ((DAT_c029ad80[0x59] <= DAT_c029ad8c) || (DAT_c029ad8c < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
      goto LAB_c028ff7c;
    }
    iVar4 = DAT_c029ad80[0x4c];
    iVar6 = DAT_c029ad8c;
  }
  if ((int)(uint)*(ushort *)(iVar4 + 0x10) <= iVar6) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  if (iVar6 < 0) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
LAB_c028ff7c:
  piVar1 = FUN_c028f5d0(&local_1c,local_18,&local_20,param_2);
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -4);
  iVar6 = *DAT_c029ad74;
  if ((1 < iVar6) || (iVar6 < 0)) {
    DAT_c029adc8 = 0x1116;
    return DAT_c029adcc;
  }
  if ((*(char *)((int)DAT_c029ad80 + 0x125) != '\x02') &&
     ((*(char *)((int)DAT_c029ad80 + 0x125) != '\0' || (DAT_c029ad7c != DAT_c029ad7c + iVar6 * 0xe))
     )) {
    DAT_c029adc8 = 0x111c;
    return DAT_c029adcc;
  }
  piVar9 = DAT_c029ad7c + iVar6 * 0xe;
  iVar4 = (int)*(short *)((short)piVar9[10] * 2 + piVar9[8] + -2);
  if (DAT_c029ad7c == piVar9) {
    uVar5 = (uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10);
  }
  else {
    uVar5 = DAT_c029ad80[0x59];
  }
  if ((iVar4 < (int)uVar5) && (-1 < iVar4)) {
    iVar8 = (int)*(short *)piVar9[7];
    if (DAT_c029ad7c == piVar9) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar8) || (iVar8 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
    }
    else if ((DAT_c029ad80[0x59] <= iVar8) || (iVar8 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    iVar2 = local_18[0];
    iVar3 = local_18[0];
    if (piVar1 == piVar9) {
      iVar2 = *(int *)(piVar9[1] + local_20 * 4);
      iVar3 = *(int *)(local_20 * 4 + *piVar9);
    }
    if ((short)DAT_c029ad6c != 0) {
      iVar7 = *piVar9;
      for (piVar9 = (int *)(iVar8 * 4 + iVar7); piVar9 <= (int *)(iVar4 * 4 + iVar7);
          piVar9 = piVar9 + 1) {
        *piVar9 = *piVar9 + local_1c;
      }
    }
    if (DAT_c029ad6c._2_2_ != 0) {
      iVar7 = DAT_c029ad7c[iVar6 * 0xe + 1];
      for (piVar9 = (int *)(iVar8 * 4 + iVar7); piVar9 <= (int *)(iVar4 * 4 + iVar7);
          piVar9 = piVar9 + 1) {
        *piVar9 = *piVar9 + local_18[0];
      }
    }
    if (piVar1 == DAT_c029ad7c + iVar6 * 0xe) {
      *(int *)(local_20 * 4 + DAT_c029ad7c[iVar6 * 0xe]) = iVar3;
      *(int *)(DAT_c029ad7c[iVar6 * 0xe + 1] + local_20 * 4) = iVar2;
      return param_1;
    }
    return param_1;
  }
  DAT_c029adc8 = 0x1112;
  return DAT_c029adcc;
}



/* c02901f8 FUN_c02901f8 */

/* Boundary evidence: original MIPS .pdata c02901f8..c02902cb. Semantic name remains unreviewed. */

undefined4 FUN_c02901f8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < DAT_c029ad98 + 2U) {
    DAT_c029adc8 = 0x1110;
    uVar3 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    uVar4 = *DAT_c029ad74;
    if ((int)(short)DAT_c029ad6c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_c0274d98(uVar4,(int)(short)DAT_c029ad6c);
    }
    if ((int)DAT_c029ad6c._2_2_ == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_c0274d98(uVar4,(int)DAT_c029ad6c._2_2_);
    }
    uVar3 = FUN_c028f730(param_1,-1,1,iVar1,iVar2);
  }
  return uVar3;
}



/* c02902cc FUN_c02902cc */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c02902cc..c0290a43. Semantic name remains unreviewed. */

undefined4 FUN_c02902cc(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int local_44;
  
  pcVar6 = DAT_c029ada8;
  pcVar5 = DAT_c029ada4;
  iVar4 = DAT_c029ad90;
  iVar3 = DAT_c029ad8c;
  piVar15 = DAT_c029ad74;
  piVar2 = DAT_c029ad64;
  piVar1 = DAT_c029ad60;
  uVar19 = DAT_c029ad98 + 1;
  if (DAT_c029ad7c == DAT_c029ad5c) {
    if ((DAT_c029ad8c < (int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10)) && (-1 < DAT_c029ad8c))
    goto LAB_c0290370;
LAB_c029034c:
    DAT_c029adc8 = 0x1112;
    param_1 = DAT_c029adcc;
  }
  else {
    if ((DAT_c029ad80[0x59] <= DAT_c029ad8c) || (DAT_c029ad8c < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
LAB_c0290370:
    if (DAT_c029ad7c == DAT_c029ad60) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= DAT_c029ad90) || (DAT_c029ad90 < 0))
      goto LAB_c029034c;
    }
    else if ((DAT_c029ad80[0x59] <= DAT_c029ad90) || (DAT_c029ad90 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < uVar19) {
      DAT_c029adc8 = 0x1110;
      param_1 = DAT_c029adcc;
    }
    else {
      if ((((DAT_c029ad5c == DAT_c029ad7c) || (DAT_c029ad60 == DAT_c029ad7c)) ||
          (DAT_c029ad64 == DAT_c029ad7c)) || (*(char *)((int)DAT_c029ad80 + 0x14d) != '\0')) {
        local_44 = DAT_c029ad64[2];
        iVar17 = *(int *)(DAT_c029ad5c[2] + DAT_c029ad8c * 4);
        iVar18 = *(int *)(DAT_c029ad5c[3] + DAT_c029ad8c * 4);
        iVar13 = DAT_c029ad60[2];
        iVar14 = DAT_c029ad60[3];
        iVar8 = DAT_c029ad64[3];
      }
      else {
        iVar18 = *(int *)(DAT_c029ad5c[5] + DAT_c029ad8c * 4);
        local_44 = DAT_c029ad64[4];
        iVar17 = *(int *)(DAT_c029ad5c[4] + DAT_c029ad8c * 4);
        iVar13 = DAT_c029ad60[4];
        iVar14 = DAT_c029ad60[5];
        iVar8 = DAT_c029ad64[5];
      }
      iVar9 = *(int *)(DAT_c029ad8c * 4 + *DAT_c029ad5c);
      iVar10 = *(int *)(DAT_c029ad5c[1] + DAT_c029ad8c * 4);
      iVar16 = DAT_c029ad90 * 4;
      uVar7 = (*DAT_c029adac)(*(int *)(iVar16 + iVar13) - iVar17,*(int *)(iVar16 + iVar14) - iVar18)
      ;
      if (uVar7 == 0) {
        for (; uVar19 != 0; uVar19 = uVar19 - 1) {
          piVar15 = piVar15 + -1;
          iVar13 = *piVar15;
          if (DAT_c029ad7c == piVar2) {
            uVar7 = (uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10);
          }
          else {
            uVar7 = DAT_c029ad80[0x59];
          }
          if ((int)uVar7 <= iVar13) {
            DAT_c029adc8 = 0x1112;
            return DAT_c029adcc;
          }
          if (iVar13 < 0) {
            DAT_c029adc8 = 0x1112;
            return DAT_c029adcc;
          }
          if (((piVar2 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
             ((DAT_c029ade0 != 0 && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)))) {
            FUN_c028aed4(&DAT_c029ad5c,(int)piVar2,iVar3,iVar13,iVar4);
          }
          iVar16 = iVar13 * 4;
          iVar14 = (*pcVar6)(*(int *)(iVar16 + local_44) - iVar17,*(int *)(iVar16 + iVar8) - iVar18)
          ;
          iVar16 = (*pcVar6)(*(int *)(*piVar2 + iVar16) - iVar9,
                             *(int *)(piVar2[1] + iVar16) - iVar10);
          (*pcVar5)(piVar2,iVar13,iVar14 - iVar16);
        }
      }
      else if (pcVar5 == (code *)&LAB_c028c2d0) {
        iVar8 = *(int *)(iVar16 + *piVar1);
        for (; uVar19 != 0; uVar19 = uVar19 - 1) {
          piVar15 = piVar15 + -1;
          iVar13 = *piVar15;
          if (DAT_c029ad7c == piVar2) {
            uVar11 = (uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10);
          }
          else {
            uVar11 = DAT_c029ad80[0x59];
          }
          if ((int)uVar11 <= iVar13) {
            DAT_c029adc8 = 0x1112;
            return DAT_c029adcc;
          }
          if (iVar13 < 0) {
            DAT_c029adc8 = 0x1112;
            return DAT_c029adcc;
          }
          if (((piVar2 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
             ((DAT_c029ade0 != 0 && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)))) {
            FUN_c028aed4(&DAT_c029ad5c,(int)piVar2,iVar3,iVar13,iVar4);
          }
          iVar14 = FUN_c0274d38(iVar8 - iVar9,*(int *)(iVar13 * 4 + local_44) - iVar17,uVar7);
          *(int *)(*piVar2 + iVar13 * 4) = iVar14 + iVar9;
          *(byte *)(piVar2[9] + iVar13) = *(byte *)(piVar2[9] + iVar13) | 1;
        }
      }
      else if (pcVar5 == (code *)&LAB_c028c300) {
        iVar13 = *(int *)(piVar1[1] + iVar16);
        for (; uVar19 != 0; uVar19 = uVar19 - 1) {
          piVar15 = piVar15 + -1;
          iVar14 = *piVar15;
          if (DAT_c029ad7c == piVar2) {
            uVar11 = (uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10);
          }
          else {
            uVar11 = DAT_c029ad80[0x59];
          }
          if ((int)uVar11 <= iVar14) {
            DAT_c029adc8 = 0x1112;
            return DAT_c029adcc;
          }
          if (iVar14 < 0) {
            DAT_c029adc8 = 0x1112;
            return DAT_c029adcc;
          }
          if ((((piVar2 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
              (DAT_c029ade0 != 0)) && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)) {
            FUN_c028aed4(&DAT_c029ad5c,(int)piVar2,iVar3,iVar14,iVar4);
          }
          iVar17 = FUN_c0274d38(iVar13 - iVar10,*(int *)(iVar14 * 4 + iVar8) - iVar18,uVar7);
          *(int *)(piVar2[1] + iVar14 * 4) = iVar17 + iVar10;
          *(byte *)(piVar2[9] + iVar14) = *(byte *)(piVar2[9] + iVar14) | 2;
        }
      }
      else {
        uVar11 = (*pcVar6)(*(int *)(iVar16 + *piVar1) - iVar9,*(int *)(piVar1[1] + iVar16) - iVar10)
        ;
        for (; uVar19 != 0; uVar19 = uVar19 - 1) {
          piVar15 = piVar15 + -1;
          iVar13 = *piVar15;
          if (DAT_c029ad7c == piVar2) {
            uVar12 = (uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10);
          }
          else {
            uVar12 = DAT_c029ad80[0x59];
          }
          if ((int)uVar12 <= iVar13) {
            DAT_c029adc8 = 0x1112;
            return DAT_c029adcc;
          }
          if (iVar13 < 0) {
            DAT_c029adc8 = 0x1112;
            return DAT_c029adcc;
          }
          if (((piVar2 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
             ((DAT_c029ade0 != 0 && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)))) {
            FUN_c028aed4(&DAT_c029ad5c,(int)piVar2,iVar3,iVar13,iVar4);
          }
          iVar16 = iVar13 * 4;
          uVar12 = (*pcVar6)(*(int *)(iVar16 + local_44) - iVar17,*(int *)(iVar16 + iVar8) - iVar18)
          ;
          iVar14 = FUN_c0274d38(uVar11,uVar12,uVar7);
          iVar16 = (*pcVar6)(*(int *)(*piVar2 + iVar16) - iVar9,
                             *(int *)(piVar2[1] + iVar16) - iVar10);
          (*pcVar5)(piVar2,iVar13,iVar14 - iVar16);
        }
      }
      DAT_c029ad98 = 0;
      DAT_c029ad74 = piVar15;
    }
  }
  return param_1;
}



/* c0290a44 FUN_c0290a44 */

/* Boundary evidence: original MIPS .pdata c0290a44..c0290db7. Semantic name remains unreviewed. */

undefined4 FUN_c0290a44(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar3 = DAT_c029ad88;
  piVar2 = DAT_c029ad60;
  piVar1 = DAT_c029ad5c;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  uVar8 = *(uint *)((int)DAT_c029ad74 + -4);
  DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -8);
  iVar7 = *DAT_c029ad74;
  if (DAT_c029ad7c == DAT_c029ad5c) {
    if ((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= DAT_c029ad88) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (DAT_c029ad88 < 0) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= DAT_c029ad88) || (DAT_c029ad88 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  if (DAT_c029ad7c == DAT_c029ad60) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar7) || (iVar7 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar7) || (iVar7 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  if (DAT_c029ad60 != DAT_c029ad7c) {
    if (((*(char *)((int)DAT_c029ad80 + 0x125) == '\x02') && (DAT_c029ade0 != 0)) &&
       ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)) {
      iVar4 = FUN_c028b56c((int)DAT_c029ad60,DAT_c029ad88,iVar7,1);
      FUN_c028ad0c(&DAT_c029ad5c,(int)piVar2,iVar3,iVar7,iVar4);
    }
    if (piVar2 != DAT_c029ad7c) goto LAB_c0290c60;
  }
  iVar6 = iVar7 * 4;
  iVar4 = FUN_c0274d98(uVar8,(int)(short)DAT_c029ad68);
  *(int *)(piVar2[2] + iVar6) = iVar4 + *(int *)(piVar1[2] + iVar3 * 4);
  iVar4 = FUN_c0274d98(uVar8,(int)DAT_c029ad68._2_2_);
  *(int *)(piVar2[3] + iVar6) = iVar4 + *(int *)(piVar1[3] + iVar3 * 4);
  *(undefined4 *)(*piVar2 + iVar6) = *(undefined4 *)(piVar2[2] + iVar6);
  *(undefined4 *)(piVar2[1] + iVar6) = *(undefined4 *)(piVar2[3] + iVar6);
LAB_c0290c60:
  if ((((DAT_c029ad80[0x1b] & 4U) == 0) && (DAT_c029ade0 != 0)) &&
     (uVar5 = (*DAT_c029adac)(*(int *)(piVar2[2] + iVar7 * 4) - *(int *)(piVar1[2] + iVar3 * 4),
                              *(int *)(piVar2[3] + iVar7 * 4) - *(int *)(piVar1[3] + iVar3 * 4)),
     uVar5 != 0)) {
    iVar4 = (uVar8 - uVar5) * 0x10;
    if ((DAT_c029ad80[0x17] < iVar4) || (iVar4 < -DAT_c029ad80[0x17])) {
      uVar8 = uVar5;
    }
  }
  iVar4 = (*DAT_c029ada8)(*(int *)(*piVar2 + iVar7 * 4) - *(int *)(iVar3 * 4 + *piVar1),
                          *(int *)(piVar2[1] + iVar7 * 4) - *(int *)(piVar1[1] + iVar3 * 4));
  (*DAT_c029ada4)(piVar2,iVar7,uVar8 - iVar4);
  DAT_c029ad8c = iVar3;
  if ((param_2 & 1) != 0) {
    DAT_c029ad88 = iVar7;
  }
  DAT_c029ad90 = iVar7;
  return param_1;
}



/* c0290db8 FUN_c0290db8 */

/* Boundary evidence: original MIPS .pdata c0290db8..c029103f. Semantic name remains unreviewed. */

undefined4 FUN_c0290db8(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  piVar1 = DAT_c029ad60;
  if (DAT_c029ad7c == DAT_c029ad5c) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= DAT_c029ad88) || (DAT_c029ad88 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= DAT_c029ad88) || (DAT_c029ad88 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  iVar8 = *(int *)(*DAT_c029ad5c + DAT_c029ad88 * 4);
  iVar9 = *(int *)(DAT_c029ad5c[1] + DAT_c029ad88 * 4);
  iVar3 = DAT_c029ad88;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < DAT_c029ad98 + 1U) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    for (; DAT_c029ad88 = iVar3, -1 < DAT_c029ad98; DAT_c029ad98 = DAT_c029ad98 + -1) {
      DAT_c029ad74 = DAT_c029ad74 + -1;
      iVar7 = *DAT_c029ad74;
      if (DAT_c029ad7c == piVar1) {
        uVar5 = (uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10);
      }
      else {
        uVar5 = DAT_c029ad80[0x59];
      }
      if ((int)uVar5 <= iVar7) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
      if (iVar7 < 0) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
      if ((((piVar1 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
          (DAT_c029ade0 != 0)) && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)) {
        iVar6 = (int)DAT_c029ade2;
        if (((iVar6 == -1) || (iVar4 = (int)DAT_c029ade4, iVar4 == -1)) ||
           (iVar2 = FUN_c028b840((int)DAT_c029ad60,iVar6,iVar7,iVar4), iVar2 == 0)) {
          FUN_c028ad0c(&DAT_c029ad5c,(int)piVar1,iVar3,iVar7,3);
        }
        else {
          FUN_c028aed4(&DAT_c029ad5c,(int)piVar1,iVar6,iVar7,iVar4);
        }
      }
      iVar3 = (*DAT_c029ada8)(*(int *)(*piVar1 + iVar7 * 4) - iVar8,
                              *(int *)(piVar1[1] + iVar7 * 4) - iVar9);
      (*DAT_c029ada4)(piVar1,iVar7,-iVar3);
      iVar3 = DAT_c029ad88;
    }
    DAT_c029ad98 = 0;
  }
  return param_1;
}



/* c0291040 FUN_c0291040 */

/* Boundary evidence: original MIPS .pdata c0291040..c029122b. Semantic name remains unreviewed. */

undefined4 FUN_c0291040(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    iVar3 = DAT_c029ad74[-1];
    DAT_c029ad74 = DAT_c029ad74 + -2;
    iVar2 = *DAT_c029ad74;
    if (DAT_c029ad7c == DAT_c029ad60) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar3) || (iVar3 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
    }
    else if ((DAT_c029ad80[0x59] <= iVar3) || (iVar3 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (DAT_c029ad7c == DAT_c029ad5c) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar2) || (iVar2 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
    }
    else if ((DAT_c029ad80[0x59] <= iVar2) || (iVar2 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    iVar4 = *(int *)(*DAT_c029ad60 + iVar3 * 4) - *(int *)(*DAT_c029ad5c + iVar2 * 4);
    iVar1 = iVar4;
    if ((DAT_c029ada8 != (code *)&LAB_c0292fdc) &&
       (iVar1 = *(int *)(DAT_c029ad60[1] + iVar3 * 4) - *(int *)(DAT_c029ad5c[1] + iVar2 * 4),
       DAT_c029ada8 != (code *)&LAB_c028c3e8)) {
      iVar1 = (*DAT_c029ada8)(iVar4);
    }
    (*DAT_c029ada4)(DAT_c029ad5c,iVar2,iVar1 >> 1);
    (*DAT_c029ada4)(DAT_c029ad60,iVar3,(iVar1 >> 1) - iVar1);
  }
  return param_1;
}



/* c029171c FUN_c029171c */

byte * FUN_c029171c(uint param_1,byte *param_2)

{
  byte bVar1;
  
  if ((uint)(*(int *)(DAT_c029ad80 + 0x160) - (int)DAT_c029ad74 >> 2) < param_1) {
    DAT_c029adc8 = 0x1111;
    param_2 = DAT_c029adcc;
  }
  else {
    for (; param_1 != 0; param_1 = param_1 - 1) {
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      *DAT_c029ad74 = (uint)bVar1;
      DAT_c029ad74 = DAT_c029ad74 + 1;
    }
  }
  return param_2;
}



/* c0291780 FUN_c0291780 */

byte * FUN_c0291780(uint param_1,byte *param_2)

{
  if ((uint)(*(int *)(DAT_c029ad80 + 0x160) - (int)DAT_c029ad74 >> 2) < param_1) {
    DAT_c029adc8 = 0x1111;
    param_2 = DAT_c029adcc;
  }
  else {
    for (; param_1 != 0; param_1 = param_1 - 1) {
      *DAT_c029ad74 = (int)(((uint)*param_2 * 0x100 + (uint)param_2[1]) * 0x10000) >> 0x10;
      DAT_c029ad74 = DAT_c029ad74 + 1;
      param_2 = param_2 + 2;
    }
  }
  return param_2;
}



/* c0291858 FUN_c0291858 */

/* Boundary evidence: original MIPS .pdata c0291858..c029187b. Semantic name remains unreviewed. */

void FUN_c0291858(byte *param_1,int param_2)

{
  FUN_c029171c(param_2 - 0xaf,param_1);
  return;
}



/* c029187c FUN_c029187c */

/* Boundary evidence: original MIPS .pdata c029187c..c02918a3. Semantic name remains unreviewed. */

void FUN_c029187c(byte *param_1)

{
  FUN_c029171c((uint)*param_1,param_1 + 1);
  return;
}



/* c0291918 FUN_c0291918 */

/* Boundary evidence: original MIPS .pdata c0291918..c029193b. Semantic name remains unreviewed. */

void FUN_c0291918(byte *param_1,int param_2)

{
  FUN_c0291780(param_2 - 0xb7,param_1);
  return;
}



/* c029193c FUN_c029193c */

/* Boundary evidence: original MIPS .pdata c029193c..c0291963. Semantic name remains unreviewed. */

void FUN_c029193c(byte *param_1)

{
  FUN_c0291780((uint)*param_1,param_1 + 1);
  return;
}



/* c0291ae4 FUN_c0291ae4 */

/* Boundary evidence: original MIPS .pdata c0291ae4..c0291bd7. Semantic name remains unreviewed. */

undefined4 FUN_c0291ae4(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    iVar2 = DAT_c029ad74[-1];
    DAT_c029ad74 = DAT_c029ad74 + -2;
    iVar3 = *DAT_c029ad74;
    if ((iVar3 < (int)(uint)*(ushort *)(DAT_c029ad80 + 0x4d)) && (-1 < iVar3)) {
      if ((iVar2 != 0) && (DAT_c029adb4 != &LAB_c028c4f0)) {
        uVar1 = FUN_c028c3f0();
        iVar2 = FUN_c0275080(iVar2,uVar1);
      }
      *(int *)(DAT_c029ad80[2] + iVar3 * 4) = iVar2;
    }
    else {
      DAT_c029adc8 = 0x111b;
      param_1 = DAT_c029adcc;
    }
  }
  return param_1;
}



/* c0291bd8 FUN_c0291bd8 */

/* Boundary evidence: original MIPS .pdata c0291bd8..c0291c97. Semantic name remains unreviewed. */

undefined4 FUN_c0291bd8(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = DAT_c029ad80;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    piVar3 = DAT_c029ad74 + -1;
    DAT_c029ad74 = DAT_c029ad74 + -2;
    iVar4 = *DAT_c029ad74;
    if ((iVar4 < (int)(uint)*(ushort *)(DAT_c029ad80 + 0x4d)) && (-1 < iVar4)) {
      uVar2 = (*(code *)DAT_c029ad80[0x2b])(DAT_c029ad80 + 0x40,*piVar3);
      *(undefined4 *)(iVar4 * 4 + piVar1[2]) = uVar2;
    }
    else {
      DAT_c029adc8 = 0x111b;
      param_1 = DAT_c029adcc;
    }
  }
  return param_1;
}



/* c0291c98 FUN_c0291c98 */

/* Boundary evidence: original MIPS .pdata c0291c98..c0291d53. Semantic name remains unreviewed. */

undefined4 FUN_c0291c98(undefined4 param_1)

{
  int iVar1;
  
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    iVar1 = *DAT_c029ad74;
    if (((iVar1 < (int)(uint)*(ushort *)(DAT_c029ad80 + 0x4d)) || (iVar1 < 0x100)) && (-1 < iVar1))
    {
      iVar1 = (*DAT_c029adb4)();
      *DAT_c029ad74 = iVar1;
      DAT_c029ad74 = DAT_c029ad74 + 1;
    }
    else {
      DAT_c029adc8 = 0x111b;
      param_1 = DAT_c029adcc;
    }
  }
  return param_1;
}



/* c0291d54 FUN_c0291d54 */

/* Boundary evidence: original MIPS .pdata c0291d54..c0291e87. Semantic name remains unreviewed. */

undefined4 FUN_c0291d54(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    iVar4 = *DAT_c029ad74;
    if (DAT_c029ad7c == DAT_c029ad64) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar4) || (iVar4 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
    }
    else if ((DAT_c029ad80[0x59] <= iVar4) || (iVar4 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if ((param_2 & 1) == 0) {
      uVar2 = *(undefined4 *)(DAT_c029ad64[1] + iVar4 * 4);
      uVar1 = *(undefined4 *)(*DAT_c029ad64 + iVar4 * 4);
      pcVar3 = DAT_c029ada8;
    }
    else {
      uVar2 = *(undefined4 *)(DAT_c029ad64[3] + iVar4 * 4);
      uVar1 = *(undefined4 *)(DAT_c029ad64[2] + iVar4 * 4);
      pcVar3 = DAT_c029adac;
    }
    iVar4 = (*pcVar3)(uVar1,uVar2);
    *DAT_c029ad74 = iVar4;
    DAT_c029ad74 = DAT_c029ad74 + 1;
  }
  return param_1;
}



/* c0291e88 FUN_c0291e88 */

/* Boundary evidence: original MIPS .pdata c0291e88..c0291fef. Semantic name remains unreviewed. */

undefined4 FUN_c0291e88(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_c029ad64;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    iVar5 = DAT_c029ad74[-1];
    DAT_c029ad74 = DAT_c029ad74 + -2;
    iVar3 = *DAT_c029ad74;
    if (DAT_c029ad7c == DAT_c029ad64) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar3) || (iVar3 < 0)) {
        DAT_c029adc8 = 0x1112;
        return DAT_c029adcc;
      }
    }
    else if ((DAT_c029ad80[0x59] <= iVar3) || (iVar3 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    iVar4 = iVar3 * 4;
    iVar2 = (*DAT_c029ada8)(*(undefined4 *)(*DAT_c029ad64 + iVar4),
                            *(undefined4 *)(DAT_c029ad64[1] + iVar4));
    (*DAT_c029ada4)(piVar1,iVar3,iVar5 - iVar2);
    if (piVar1 == DAT_c029ad7c) {
      *(undefined4 *)(piVar1[2] + iVar4) = *(undefined4 *)(*piVar1 + iVar4);
      *(undefined4 *)(piVar1[3] + iVar4) = *(undefined4 *)(piVar1[1] + iVar4);
    }
  }
  return param_1;
}



/* c0291ff0 FUN_c0291ff0 */

/* Boundary evidence: original MIPS .pdata c0291ff0..c029230b. Semantic name remains unreviewed. */

undefined4 FUN_c0291ff0(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  piVar2 = DAT_c029ad80;
  iVar1 = DAT_c029ad74;
  if ((uint)(DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  piVar8 = (int *)(DAT_c029ad74 + -8);
  iVar7 = *(int *)(DAT_c029ad74 + -4);
  iVar6 = *piVar8;
  if (DAT_c029ad7c == DAT_c029ad5c) {
    if ((iVar6 < (int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10)) && (-1 < iVar6))
    goto LAB_c02920a4;
LAB_c0292080:
    DAT_c029adc8 = 0x1112;
    param_1 = DAT_c029adcc;
  }
  else {
    if ((DAT_c029ad80[0x59] <= iVar6) || (iVar6 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
LAB_c02920a4:
    if (DAT_c029ad7c == DAT_c029ad60) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar7) || (iVar7 < 0))
      goto LAB_c0292080;
    }
    else if ((DAT_c029ad80[0x59] <= iVar7) || (iVar7 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if ((param_2 - 1U & 1) == 0) {
      iVar6 = (*DAT_c029ada8)(*(int *)(*DAT_c029ad5c + iVar6 * 4) -
                              *(int *)(*DAT_c029ad60 + iVar7 * 4),
                              *(int *)(DAT_c029ad5c[1] + iVar6 * 4) -
                              *(int *)(DAT_c029ad60[1] + iVar7 * 4));
      if (((*(ushort *)((int)DAT_c029ad80 + 0x172) & 0xb) == 0xb) && (iVar6 == 0x40)) {
        iVar6 = 0x41;
      }
    }
    else if (((DAT_c029ad5c == DAT_c029ad7c) || (DAT_c029ad60 == DAT_c029ad7c)) ||
            (*(char *)((int)DAT_c029ad80 + 0x14d) != '\0')) {
      iVar6 = (*DAT_c029adac)(*(int *)(DAT_c029ad60[2] + iVar6 * 4) -
                              *(int *)(DAT_c029ad5c[2] + iVar7 * 4),
                              *(int *)(DAT_c029ad60[3] + iVar6 * 4) -
                              *(int *)(DAT_c029ad5c[3] + iVar7 * 4));
    }
    else {
      if ((char)DAT_c029ad80[0x4b] == '\0') {
        uVar3 = (*(code *)DAT_c029ad80[0x2a])
                          (DAT_c029ad80 + 0x3c,
                           *(int *)(DAT_c029ad60[5] + iVar6 * 4) -
                           *(int *)(DAT_c029ad5c[5] + iVar7 * 4));
        piVar4 = (int *)(*(code *)piVar2[0x29])
                                  (piVar2 + 0x38,
                                   *(int *)(DAT_c029ad60[4] + iVar6 * 4) -
                                   *(int *)(DAT_c029ad5c[4] + iVar7 * 4));
        pcVar5 = DAT_c029adac;
      }
      else {
        uVar3 = (*DAT_c029adac)(*(int *)(DAT_c029ad60[4] + iVar6 * 4) -
                                *(int *)(DAT_c029ad5c[4] + iVar7 * 4),
                                *(int *)(DAT_c029ad60[5] + iVar6 * 4) -
                                *(int *)(DAT_c029ad5c[5] + iVar7 * 4));
        piVar4 = piVar2 + 0x40;
        pcVar5 = (code *)piVar2[0x2b];
      }
      iVar6 = (*pcVar5)(piVar4,uVar3);
    }
    DAT_c029ad74 = iVar1 + -4;
    *piVar8 = iVar6;
  }
  return param_1;
}



/* c029230c FUN_c029230c */

/* Boundary evidence: original MIPS .pdata c029230c..c02923af. Semantic name remains unreviewed. */

undefined4 FUN_c029230c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(DAT_c029ad80 + 0xc);
  if (*(char *)(DAT_c029ad80 + 300) == '\0') {
    uVar1 = FUN_c028c3f0();
    uVar2 = FUN_c0274f80(uVar2,uVar1);
    uVar2 = uVar2 & 0xffff;
  }
  if (*(int *)(DAT_c029ad80 + 0x160) - (int)DAT_c029ad74 >> 2 == 0) {
    DAT_c029adc8 = 0x1111;
    param_1 = DAT_c029adcc;
  }
  else {
    *DAT_c029ad74 = uVar2;
    DAT_c029ad74 = DAT_c029ad74 + 1;
  }
  return param_1;
}



/* c0292954 FUN_c0292954 */

/* Boundary evidence: original MIPS .pdata c0292954..c02929cb. Semantic name remains unreviewed. */

undefined4 FUN_c0292954(undefined4 param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar2 = DAT_c029ad74;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    puVar4 = DAT_c029ad74 + -1;
    puVar1 = DAT_c029ad74 + -2;
    DAT_c029ad74 = puVar4;
    uVar3 = FUN_c0274e28(*puVar1,*puVar4);
    puVar2[-2] = uVar3;
  }
  return param_1;
}



/* c0292b24 FUN_c0292b24 */

/* Boundary evidence: original MIPS .pdata c0292b24..c0292b9b. Semantic name remains unreviewed. */

undefined4 FUN_c0292b24(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_c029ad74;
  if (DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    uVar2 = FUN_c028be00(*(uint *)(DAT_c029ad74 + -4),0);
    *(uint *)(iVar1 + -4) = (int)uVar2 >> 6 & 1;
  }
  return param_1;
}



/* c0292b9c FUN_c0292b9c */

/* Boundary evidence: original MIPS .pdata c0292b9c..c0292c17. Semantic name remains unreviewed. */

undefined4 FUN_c0292b9c(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_c029ad74;
  if (DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    uVar2 = FUN_c028be00(*(uint *)(DAT_c029ad74 + -4),0);
    *(uint *)(iVar1 + -4) = ((int)uVar2 >> 6) - 1U & 1;
  }
  return param_1;
}



/* c0292db0 FUN_c0292db0 */

byte * FUN_c0292db0(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_c02617e0)[param_1[-1]];
  if (uVar1 != 0) {
    if (uVar1 == 0x15) {
      uVar1 = *param_1 + 1;
    }
    else if (uVar1 == 0x16) {
      uVar1 = (uint)*param_1 * 2 + 1;
    }
    param_1 = param_1 + uVar1;
  }
  return param_1;
}



/* c0292f34 FUN_c0292f34 */

/* Boundary evidence: original MIPS .pdata c0292f34..c0292fdb. Semantic name remains unreviewed. */

byte * FUN_c0292f34(byte *param_1)

{
  byte bVar1;
  short sVar2;
  byte *pbVar3;
  short sVar4;
  
  pbVar3 = DAT_c029adcc;
  sVar4 = 1;
  do {
    if (pbVar3 <= param_1) break;
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    if (bVar1 == 0x59) {
      sVar2 = -1;
LAB_c0292f90:
      sVar4 = sVar4 + sVar2;
    }
    else {
      if (bVar1 == 0x58) {
        sVar2 = 1;
        goto LAB_c0292f90;
      }
      param_1 = FUN_c0292db0(param_1);
    }
  } while (sVar4 != 0);
  if (sVar4 != 0) {
    DAT_c029adc8 = 0x1105;
  }
  return param_1;
}



/* c029319c FUN_c029319c */

/* Boundary evidence: original MIPS .pdata c029319c..c0293233. Semantic name remains unreviewed. */

undefined4 FUN_c029319c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    uVar1 = (*(code *)DAT_c029ad80[0x1d])(*DAT_c029ad74,DAT_c029ad80[param_2 + -99]);
    *DAT_c029ad74 = uVar1;
    DAT_c029ad74 = DAT_c029ad74 + 1;
  }
  return param_1;
}



/* c02932c8 FUN_c02932c8 */

/* Boundary evidence: original MIPS .pdata c02932c8..c0293363. Semantic name remains unreviewed. */

int FUN_c02932c8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_c029ad80;
  iVar2 = (*DAT_c029adb8)();
  if (param_1 < 0) {
    iVar3 = -param_1 - iVar2;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    iVar4 = -param_1;
    if (iVar3 < *(int *)(iVar1 + 0x60)) {
      iVar4 = iVar2;
    }
    param_1 = -iVar4;
  }
  else {
    iVar3 = param_1 - iVar2;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < *(int *)(iVar1 + 0x60)) {
      param_1 = iVar2;
    }
  }
  return param_1;
}



/* c0293364 FUN_c0293364 */

/* Boundary evidence: original MIPS .pdata c0293364..c029380f. Semantic name remains unreviewed. */

undefined4 FUN_c0293364(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  
  iVar4 = DAT_c029ad88;
  piVar3 = DAT_c029ad80;
  piVar2 = DAT_c029ad60;
  piVar1 = DAT_c029ad5c;
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -4);
  iVar14 = *DAT_c029ad74;
  if (DAT_c029ad7c == DAT_c029ad5c) {
    if ((DAT_c029ad88 < (int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10)) && (-1 < DAT_c029ad88))
    goto LAB_c0293428;
LAB_c0293408:
    DAT_c029adc8 = 0x1112;
    param_1 = DAT_c029adcc;
  }
  else {
    if ((DAT_c029ad80[0x59] <= DAT_c029ad88) || (DAT_c029ad88 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
LAB_c0293428:
    if (DAT_c029ad7c == DAT_c029ad60) {
      if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar14) || (iVar14 < 0))
      goto LAB_c0293408;
    }
    else if ((DAT_c029ad80[0x59] <= iVar14) || (iVar14 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if ((((DAT_c029ad60 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
        (DAT_c029ade0 != 0)) && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)) {
      iVar12 = (int)DAT_c029ade2;
      if (((iVar12 == -1) || (iVar10 = (int)DAT_c029ade4, iVar10 == -1)) ||
         (iVar5 = FUN_c028b840((int)DAT_c029ad60,iVar12,iVar14,iVar10), iVar5 == 0)) {
        FUN_c028ad0c(&DAT_c029ad5c,(int)piVar2,iVar4,iVar14,3);
      }
      else {
        FUN_c028aed4(&DAT_c029ad5c,(int)piVar2,iVar12,iVar14,iVar10);
      }
    }
    if (((piVar1 == DAT_c029ad7c) || (piVar2 == DAT_c029ad7c)) ||
       (*(char *)((int)DAT_c029ad80 + 0x14d) != '\0')) {
      uVar7 = (*DAT_c029adac)(*(int *)(piVar2[2] + iVar14 * 4) - *(int *)(piVar1[2] + iVar4 * 4),
                              *(int *)(piVar2[3] + iVar14 * 4) - *(int *)(piVar1[3] + iVar4 * 4));
    }
    else {
      if ((char)piVar3[0x4b] == '\0') {
        uVar6 = (*(code *)piVar3[0x2a])
                          (piVar3 + 0x3c,
                           *(int *)(piVar2[5] + iVar14 * 4) - *(int *)(piVar1[5] + iVar4 * 4));
        piVar8 = (int *)(*(code *)piVar3[0x29])
                                  (piVar3 + 0x38,
                                   *(int *)(piVar2[4] + iVar14 * 4) -
                                   *(int *)(piVar1[4] + iVar4 * 4));
        pcVar11 = DAT_c029adac;
      }
      else {
        uVar6 = (*DAT_c029adac)(*(int *)(piVar2[4] + iVar14 * 4) - *(int *)(piVar1[4] + iVar4 * 4),
                                *(int *)(piVar2[5] + iVar14 * 4) - *(int *)(piVar1[5] + iVar4 * 4));
        piVar8 = piVar3 + 0x40;
        pcVar11 = (code *)piVar3[0x2b];
      }
      uVar7 = (*pcVar11)(piVar8,uVar6);
    }
    if (piVar3[0x18] != 0) {
      uVar7 = FUN_c02932c8(uVar7);
    }
    if ((param_2 & 4) == 0) {
      iVar12 = piVar3[(param_2 & 3) + 5];
      if ((int)uVar7 < 0) {
        iVar12 = -iVar12;
      }
      uVar9 = iVar12 + uVar7;
      if (((int)(uVar9 ^ uVar7) < 0) && (uVar7 != 0)) {
        uVar9 = 0;
      }
    }
    else {
      uVar9 = (*(code *)piVar3[0x1d])(uVar7,piVar3[(param_2 & 3) + 5]);
    }
    if ((param_2 & 8) != 0) {
      uVar13 = piVar3[0x1c];
      if (DAT_c029ade0 != 0) {
        if ((int)uVar13 < 0) {
          uVar13 = uVar13 + 1;
        }
        uVar13 = (int)uVar13 >> 1;
      }
      if ((int)uVar7 < 0) {
        if ((int)-uVar13 < (int)uVar9) {
          uVar9 = -uVar13;
        }
      }
      else if ((int)uVar9 < (int)uVar13) {
        uVar9 = uVar13;
      }
    }
    iVar12 = (*DAT_c029ada8)(*(int *)(*piVar2 + iVar14 * 4) - *(int *)(iVar4 * 4 + *piVar1),
                             *(int *)(piVar2[1] + iVar14 * 4) - *(int *)(piVar1[1] + iVar4 * 4));
    (*DAT_c029ada4)(piVar2,iVar14,uVar9 - iVar12);
    DAT_c029ad8c = iVar4;
    DAT_c029ad90 = iVar14;
    if ((param_2 & 0x10) != 0) {
      DAT_c029ad88 = iVar14;
    }
  }
  return param_1;
}



/* c0293810 FUN_c0293810 */

/* Boundary evidence: original MIPS .pdata c0293810..c02941e7. Semantic name remains unreviewed. */

undefined4 FUN_c0293810(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int local_34;
  
  local_34 = DAT_c029ad88;
  piVar3 = DAT_c029ad80;
  piVar2 = DAT_c029ad60;
  piVar1 = DAT_c029ad5c;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  iVar10 = *(int *)((int)DAT_c029ad74 + -4);
  if (((int)(uint)*(ushort *)(DAT_c029ad80 + 0x4d) <= iVar10) || (iVar10 < 0)) {
    DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -4);
    DAT_c029adc8 = 0x111b;
    return DAT_c029adcc;
  }
  DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -8);
  iVar12 = *DAT_c029ad74;
  if (DAT_c029ad7c == DAT_c029ad60) {
    if ((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= iVar12) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
    if (iVar12 < 0) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= iVar12) || (iVar12 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  if (DAT_c029ad7c == DAT_c029ad5c) {
    if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x10) <= DAT_c029ad88) || (DAT_c029ad88 < 0)) {
      DAT_c029adc8 = 0x1112;
      return DAT_c029adcc;
    }
  }
  else if ((DAT_c029ad80[0x59] <= DAT_c029ad88) || (DAT_c029ad88 < 0)) {
    DAT_c029adc8 = 0x1112;
    return DAT_c029adcc;
  }
  DAT_c029ad8c = DAT_c029ad88;
  DAT_c029ad90 = iVar12;
  if ((((DAT_c029ad60 != DAT_c029ad7c) && (*(char *)((int)DAT_c029ad80 + 0x125) == '\x02')) &&
      (DAT_c029ade0 != 0)) && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 2) != 0)) {
    iVar4 = FUN_c028b56c((int)DAT_c029ad60,DAT_c029ad88,iVar12,param_2 & 3);
    FUN_c028ad0c(&DAT_c029ad5c,(int)piVar2,local_34,iVar12,iVar4);
  }
  if (DAT_c029adc4 != 0) {
    iVar4 = iVar12 * 4;
    local_34 = local_34 * 4;
    if (DAT_c029adc4 == 1) {
      uVar5 = *(uint *)(iVar10 * 4 + piVar3[2]);
      uVar11 = *(int *)(piVar2[2] + iVar4) - *(int *)(piVar1[2] + local_34);
      if (((int)(uVar11 ^ uVar5) < 0) && ((char)piVar3[0x24] != '\0')) {
        uVar5 = -uVar5;
      }
      if (DAT_c029ade0 == 0) {
        if ((param_2 & 4) != 0) {
          if ((piVar3[0x17] < (int)(uVar5 - uVar11)) || ((int)(uVar5 - uVar11) < -piVar3[0x17])) {
            uVar5 = uVar11;
          }
          if (-1 < (int)uVar5) {
            uVar5 = uVar5 + 0x20;
            uVar6 = 0xffffffc0;
            goto LAB_c0293ef4;
          }
          uVar5 = 0x20 - uVar5 & 0xffffffc0;
LAB_c0293f0c:
          uVar5 = -uVar5;
        }
      }
      else {
        if ((*(ushort *)(piVar3 + 0x1b) & 4) == 0) {
          iVar10 = (uVar5 - uVar11) * 0x10;
          if ((piVar3[0x17] < iVar10) || (iVar10 < -piVar3[0x17])) {
            uVar5 = uVar11;
          }
        }
        if ((param_2 & 4) != 0) {
          if ((*(ushort *)(piVar3 + 0x1b) & 4) != 0) {
            iVar10 = (uVar5 - uVar11) * 0x10;
            if ((piVar3[0x17] < iVar10) || (iVar10 < -piVar3[0x17])) {
              uVar5 = uVar11;
            }
          }
          if ((int)uVar5 < 0) {
            uVar5 = 2 - uVar5 & 0xfffffffc;
            goto LAB_c0293f0c;
          }
          uVar5 = uVar5 + 2;
          uVar6 = 0xfffffffc;
LAB_c0293ef4:
          uVar5 = uVar5 & uVar6;
        }
      }
      if ((param_2 & 8) != 0) {
        uVar6 = piVar3[0x1c];
        if (DAT_c029ade0 != 0) {
          if ((int)uVar6 < 0) {
            uVar6 = uVar6 + 1;
          }
          uVar6 = (int)uVar6 >> 1;
        }
        if ((int)uVar11 < 0) {
          if ((int)-uVar6 < (int)uVar5) {
            uVar5 = -uVar6;
          }
        }
        else if ((int)uVar5 < (int)uVar6) {
          uVar5 = uVar6;
        }
      }
      *(uint *)(iVar4 + *piVar2) = *(int *)(local_34 + *piVar1) + uVar5;
      pbVar9 = (byte *)(piVar2[9] + iVar12);
      bVar7 = *pbVar9 | 1;
    }
    else {
      uVar5 = *(uint *)(iVar10 * 4 + piVar3[2]);
      uVar11 = *(int *)(piVar2[3] + iVar4) - *(int *)(piVar1[3] + local_34);
      if (((int)(uVar11 ^ uVar5) < 0) && ((char)piVar3[0x24] != '\0')) {
        uVar5 = -uVar5;
      }
      if (DAT_c029ade0 == 0) {
        if ((param_2 & 4) != 0) {
          if ((piVar3[0x17] < (int)(uVar5 - uVar11)) || ((int)(uVar5 - uVar11) < -piVar3[0x17])) {
            uVar5 = uVar11;
          }
          if (-1 < (int)uVar5) {
            uVar5 = uVar5 + 0x20;
            uVar6 = 0xffffffc0;
            goto LAB_c02940d4;
          }
          uVar5 = 0x20 - uVar5 & 0xffffffc0;
LAB_c02940ec:
          uVar5 = -uVar5;
        }
      }
      else {
        if ((*(ushort *)(piVar3 + 0x1b) & 4) == 0) {
          iVar10 = (uVar5 - uVar11) * 0x10;
          if ((piVar3[0x17] < iVar10) || (iVar10 < -piVar3[0x17])) {
            uVar5 = uVar11;
          }
        }
        if ((param_2 & 4) != 0) {
          if ((*(ushort *)(piVar3 + 0x1b) & 4) != 0) {
            iVar10 = (uVar5 - uVar11) * 0x10;
            if ((piVar3[0x17] < iVar10) || (iVar10 < -piVar3[0x17])) {
              uVar5 = uVar11;
            }
          }
          if ((int)uVar5 < 0) {
            uVar5 = 2 - uVar5 & 0xfffffffc;
            goto LAB_c02940ec;
          }
          uVar5 = uVar5 + 2;
          uVar6 = 0xfffffffc;
LAB_c02940d4:
          uVar5 = uVar5 & uVar6;
        }
      }
      if ((param_2 & 8) != 0) {
        uVar6 = piVar3[0x1c];
        if (DAT_c029ade0 != 0) {
          if ((int)uVar6 < 0) {
            uVar6 = uVar6 + 1;
          }
          uVar6 = (int)uVar6 >> 1;
        }
        if ((int)uVar11 < 0) {
          if ((int)-uVar6 < (int)uVar5) {
            uVar5 = -uVar6;
          }
        }
        else if ((int)uVar5 < (int)uVar6) {
          uVar5 = uVar6;
        }
      }
      *(uint *)(piVar2[1] + iVar4) = *(int *)(piVar1[1] + local_34) + uVar5;
      pbVar9 = (byte *)(piVar2[9] + iVar12);
      bVar7 = *pbVar9 | 2;
    }
    *pbVar9 = bVar7;
    goto LAB_c0294178;
  }
  uVar5 = (*DAT_c029adb4)(iVar10);
  if (piVar3[0x18] != 0) {
    uVar5 = FUN_c02932c8(uVar5);
  }
  if (piVar2 == DAT_c029ad7c) {
    iVar4 = iVar12 * 4;
    iVar10 = FUN_c0274d98(uVar5,(int)(short)DAT_c029ad68);
    *(int *)(iVar4 + piVar2[2]) = iVar10 + *(int *)(piVar1[2] + local_34 * 4);
    *(undefined4 *)(iVar4 + *piVar2) = *(undefined4 *)(iVar4 + piVar2[2]);
    iVar10 = FUN_c0274d98(uVar5,(int)DAT_c029ad68._2_2_);
    *(int *)(iVar4 + piVar2[3]) = iVar10 + *(int *)(piVar1[3] + local_34 * 4);
    *(undefined4 *)(piVar2[1] + iVar4) = *(undefined4 *)(iVar4 + piVar2[3]);
  }
  if (DAT_c029adac == (code *)&LAB_c0292fdc) {
    uVar11 = *(int *)(piVar2[2] + iVar12 * 4) - *(int *)(piVar1[2] + local_34 * 4);
LAB_c0293b3c:
    iVar10 = iVar12 << 2;
  }
  else {
    if (DAT_c029adac != (code *)&LAB_c028c3e8) {
      uVar11 = (*DAT_c029adac)(*(int *)(piVar2[2] + iVar12 * 4) - *(int *)(piVar1[2] + local_34 * 4)
                               ,*(int *)(piVar2[3] + iVar12 * 4) -
                                *(int *)(piVar1[3] + local_34 * 4));
      goto LAB_c0293b3c;
    }
    iVar10 = iVar12 * 4;
    uVar11 = *(int *)(piVar2[3] + iVar10) - *(int *)(piVar1[3] + local_34 * 4);
  }
  local_34 = local_34 * 4;
  if (((int)(uVar11 ^ uVar5) < 0) && ((char)piVar3[0x24] != '\0')) {
    uVar5 = -uVar5;
  }
  iVar4 = piVar3[(param_2 & 3) + 5];
  if (DAT_c029ade0 == 0) {
    if ((param_2 & 4) == 0) {
      uVar6 = iVar4 + uVar5;
      if ((int)uVar5 < 0) {
        uVar6 = uVar5 - iVar4;
      }
      goto LAB_c0293c78;
    }
    if ((piVar3[0x17] < (int)(uVar5 - uVar11)) || ((int)(uVar5 - uVar11) < -piVar3[0x17])) {
LAB_c0293c4c:
      uVar5 = uVar11;
    }
LAB_c0293c50:
    uVar6 = (*(code *)piVar3[0x1d])(uVar5,iVar4);
  }
  else {
    if ((*(ushort *)(piVar3 + 0x1b) & 4) == 0) {
      iVar8 = (uVar5 - uVar11) * 0x10;
      if ((piVar3[0x17] < iVar8) || (iVar8 < -piVar3[0x17])) {
        uVar5 = uVar11;
      }
    }
    if ((param_2 & 4) != 0) {
      if ((*(ushort *)(piVar3 + 0x1b) & 4) != 0) {
        iVar8 = (uVar5 - uVar11) * 0x10;
        if ((piVar3[0x17] < iVar8) || (iVar8 < -piVar3[0x17])) goto LAB_c0293c4c;
      }
      goto LAB_c0293c50;
    }
    if (iVar4 < 0) {
      iVar4 = iVar4 + 1;
    }
    uVar6 = (iVar4 >> 1) + uVar5;
    if ((int)uVar5 < 0) {
      uVar6 = uVar5 - (iVar4 >> 1);
    }
LAB_c0293c78:
    if (((int)(uVar6 ^ uVar5) < 0) && (uVar5 != 0)) {
      uVar6 = 0;
    }
  }
  if ((param_2 & 8) != 0) {
    uVar5 = piVar3[0x1c];
    if (DAT_c029ade0 != 0) {
      if ((int)uVar5 < 0) {
        uVar5 = uVar5 + 1;
      }
      uVar5 = (int)uVar5 >> 1;
    }
    if ((int)uVar11 < 0) {
      if ((int)-uVar5 < (int)uVar6) {
        uVar6 = -uVar5;
      }
    }
    else if ((int)uVar6 < (int)uVar5) {
      uVar6 = uVar5;
    }
  }
  if (DAT_c029ada8 == (code *)&LAB_c0292fdc) {
    iVar4 = *piVar2;
    iVar8 = *piVar1;
LAB_c0293d38:
    iVar10 = *(int *)(iVar10 + iVar4) - *(int *)(local_34 + iVar8);
  }
  else {
    if (DAT_c029ada8 == (code *)&LAB_c028c3e8) {
      iVar4 = piVar2[1];
      iVar8 = piVar1[1];
      goto LAB_c0293d38;
    }
    iVar10 = (*DAT_c029ada8)(*(int *)(iVar10 + *piVar2) - *(int *)(local_34 + *piVar1),
                             *(int *)(piVar2[1] + iVar10) - *(int *)(piVar1[1] + local_34));
  }
  (*DAT_c029ada4)(piVar2,iVar12,uVar6 - iVar10);
LAB_c0294178:
  if ((param_2 & 0x10) != 0) {
    DAT_c029ad88 = iVar12;
  }
  return param_1;
}



/* c02941e8 FUN_c02941e8 */

/* Boundary evidence: original MIPS .pdata c02941e8..c0294583. Semantic name remains unreviewed. */

undefined4 FUN_c02941e8(undefined4 param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  
  uVar6 = DAT_c029add0;
  uVar5 = DAT_c029adcc;
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  iVar15 = 0;
  bVar1 = false;
  uVar14 = uVar5;
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    DAT_c029adcc = uVar5;
    DAT_c029add0 = uVar6;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    uVar11 = *DAT_c029ad74;
    if (((int)uVar11 < (int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x14)) && (-1 < (int)uVar11)) {
      piVar7 = (int *)(DAT_c029ad80[0x25] + uVar11 * 8);
      if (*(ushort *)((int)piVar7 + 6) < 2) {
        iVar10 = DAT_c029ad80[(*(ushort *)((int)piVar7 + 6) + 0x16) * 2];
        iVar9 = *piVar7;
        uVar14 = param_1;
        if ((((0x3f < (int)uVar11) && ((int)uVar11 < 0x43)) &&
            ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) != 0)) &&
           (((DAT_c029ad80[0x1b] & 4U) == 0 &&
            ((*(ushort *)((int)DAT_c029ad80 + 0x172) & 0x100) != 0)))) {
          uVar14 = *(undefined4 *)(DAT_c029ad80[1] + 0x58);
          *(undefined4 *)(DAT_c029ad80[1] + 0x58) = 0;
          bVar4 = true;
        }
        uVar13 = param_1;
        if (((((-1 < (int)uVar11) && ((int)uVar11 < 3)) ||
             ((uVar11 == 4 || ((6 < (int)uVar11 && ((int)uVar11 < 9)))))) &&
            ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) != 0)) &&
           (((DAT_c029ad80[0x1b] & 4U) == 0 &&
            ((*(ushort *)((int)DAT_c029ad80 + 0x172) & 0x200) != 0)))) {
          uVar13 = *(undefined4 *)(DAT_c029ad80[1] + 0x60);
          *(undefined4 *)(DAT_c029ad80[1] + 0x60) = 0;
          bVar3 = true;
        }
        if ((((uVar11 == 0x3a) && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) != 0)) &&
            ((DAT_c029ad80[0x1b] & 4U) == 0)) &&
           ((*(ushort *)((int)DAT_c029ad80 + 0x172) & 0x800) != 0)) {
          iVar15 = DAT_c029ad80[0x17];
          DAT_c029ad80[0x17] = 0x7fffffff;
          bVar2 = true;
        }
        uVar8 = (uint)*(ushort *)(DAT_c029ad80 + 0x5d);
        uVar12 = 0;
        if (uVar8 != 0) {
          do {
            if ((uint)*(ushort *)((uVar12 + 0xbb) * 2 + (int)DAT_c029ad80) == (uVar11 & 0xffff))
            break;
            uVar12 = uVar12 + 1 & 0xffff;
          } while (uVar12 < uVar8);
        }
        if (((uVar12 < uVar8) && ((*(ushort *)(DAT_c029ad80 + 0x5c) & 1) != 0)) &&
           ((DAT_c029ad80[0x1b] & 4U) == 0)) {
          *(ushort *)((int)DAT_c029ad80 + 0x172) = *(ushort *)((int)DAT_c029ad80 + 0x172) | 0x10;
          bVar1 = true;
        }
        DAT_c029add8 = DAT_c029add8 + -1;
        if (DAT_c029add8 == 0) {
          DAT_c029adc8 = 0x1106;
          DAT_c029add8 = 0;
          uVar14 = DAT_c029adcc;
        }
        else {
          (*DAT_c029adb0)(iVar10 + iVar9,(uint)*(ushort *)(piVar7 + 1) + iVar10 + iVar9);
          DAT_c029add8 = DAT_c029add8 + 1;
          if (bVar1) {
            *(ushort *)((int)DAT_c029ad80 + 0x172) = *(ushort *)((int)DAT_c029ad80 + 0x172) & 0xffef
            ;
          }
          if (bVar2) {
            DAT_c029ad80[0x17] = iVar15;
          }
          if (bVar3) {
            *(undefined4 *)(DAT_c029ad80[1] + 0x60) = uVar13;
          }
          if (bVar4) {
            *(undefined4 *)(DAT_c029ad80[1] + 0x58) = uVar14;
          }
          uVar14 = param_1;
          DAT_c029adcc = uVar5;
          DAT_c029add0 = uVar6;
          if (DAT_c029adc8 != 0) {
            uVar14 = uVar5;
          }
        }
      }
      else {
        DAT_c029adc8 = 0x1115;
        DAT_c029adcc = uVar5;
        DAT_c029add0 = uVar6;
      }
    }
    else {
      DAT_c029adc8 = 0x1114;
      DAT_c029adcc = uVar5;
      DAT_c029add0 = uVar6;
    }
  }
  return uVar14;
}



/* c0294584 FUN_c0294584 */

/* Boundary evidence: original MIPS .pdata c0294584..c029487f. Semantic name remains unreviewed. */

byte * FUN_c0294584(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    return DAT_c029adcc;
  }
  DAT_c029ad74 = (int *)((int)DAT_c029ad74 + -4);
  iVar7 = *DAT_c029ad74;
  if (((int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x14) <= iVar7) || (iVar7 < 0)) {
    DAT_c029adc8 = 0x1114;
    return DAT_c029adcc;
  }
  bVar1 = *(byte *)((int)DAT_c029ad80 + 0x125);
  if (1 < bVar1) {
    DAT_c029adc8 = 0x1108;
    return DAT_c029adcc;
  }
  piVar8 = (int *)(DAT_c029ad80[0x25] + iVar7 * 8);
  piVar6 = DAT_c029ad80 + (bVar1 + 0x16) * 2;
  *(ushort *)((int)piVar8 + 6) = (ushort)bVar1;
  *piVar8 = (int)param_1 - *piVar6;
  if (((0x3f < iVar7) && (iVar7 < 0x43)) && (iVar3 = memcmp(param_1,&DAT_c02618f0,4), iVar3 == 0)) {
    *(ushort *)((int)DAT_c029ad80 + 0x172) = *(ushort *)((int)DAT_c029ad80 + 0x172) | 0x100;
  }
  if ((((-1 < iVar7) && (iVar7 < 3)) || ((iVar7 == 4 || ((6 < iVar7 && (iVar7 < 9)))))) &&
     ((iVar3 = memcmp(param_1,&DAT_c0261900,5), iVar3 == 0 ||
      (iVar3 = memcmp(param_1,&DAT_c0261910,6), iVar3 == 0)))) {
    *(ushort *)((int)DAT_c029ad80 + 0x172) = *(ushort *)((int)DAT_c029ad80 + 0x172) | 0x200;
  }
  if (iVar7 == 0) {
    iVar3 = memcmp(param_1,&DAT_c0261920,7);
    if (iVar3 != 0) goto LAB_c029476c;
    *(ushort *)((int)DAT_c029ad80 + 0x172) = *(ushort *)((int)DAT_c029ad80 + 0x172) | 0x400;
  }
  if ((iVar7 == 0x3a) && (iVar3 = memcmp(param_1,&DAT_c0261930,10), iVar3 == 0)) {
    *(ushort *)((int)DAT_c029ad80 + 0x172) = *(ushort *)((int)DAT_c029ad80 + 0x172) | 0x800;
  }
LAB_c029476c:
  if ((*param_1 == 0x4b) &&
     (((iVar3 = memcmp(param_1,&DAT_c0261950,9), iVar3 == 0 ||
       (iVar3 = memcmp(param_1,&DAT_c0261940,0xd), iVar3 == 0)) &&
      (*(ushort *)(DAT_c029ad80 + 0x5d) < 4)))) {
    *(short *)((*(ushort *)(DAT_c029ad80 + 0x5d) + 0xbb) * 2 + (int)DAT_c029ad80) = (short)iVar7;
    *(short *)(DAT_c029ad80 + 0x5d) = (short)DAT_c029ad80[0x5d] + 1;
  }
  pbVar2 = DAT_c029adcc;
  bVar1 = *param_1;
  pbVar4 = param_1;
  while ((bVar1 != 0x2d && (pbVar4 + 1 < pbVar2))) {
    pbVar4 = FUN_c0292db0(pbVar4 + 1);
    bVar1 = *pbVar4;
  }
  pbVar5 = pbVar4 + 1;
  if ((pbVar5 == pbVar2) && (*pbVar4 != 0x2d)) {
    DAT_c029adc8 = 0x1104;
  }
  *(short *)(piVar8 + 1) = ((short)pbVar5 - (short)param_1) + -1;
  return pbVar5;
}



/* c0294880 FUN_c0294880 */

/* Boundary evidence: original MIPS .pdata c0294880..c0294a1b. Semantic name remains unreviewed. */

undefined4 FUN_c0294880(undefined4 param_1)

{
  ushort uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  
  uVar4 = DAT_c029add0;
  uVar3 = DAT_c029adcc;
  pcVar2 = DAT_c029adb0;
  uVar10 = uVar3;
  if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < 2) {
    DAT_c029adc8 = 0x1110;
  }
  else {
    piVar8 = DAT_c029ad74 + -1;
    iVar5 = *piVar8;
    if ((iVar5 < (int)(uint)*(ushort *)(DAT_c029ad80[0x4c] + 0x14)) && (-1 < iVar5)) {
      piVar9 = (int *)(DAT_c029ad80[0x25] + iVar5 * 8);
      if (*(ushort *)((int)piVar9 + 6) < 2) {
        iVar7 = DAT_c029ad80[(*(ushort *)((int)piVar9 + 6) + 0x16) * 2];
        iVar6 = *piVar9;
        uVar1 = *(ushort *)(piVar9 + 1);
        DAT_c029ad74 = DAT_c029ad74 + -2;
        iVar5 = *DAT_c029ad74;
        DAT_c029add8 = DAT_c029add8 + -1;
        if (DAT_c029add8 == 0) {
          DAT_c029adc8 = 0x1106;
          DAT_c029add8 = 0;
        }
        else {
          while ((iVar5 = iVar5 + -1, -1 < iVar5 && (DAT_c029adc8 == 0))) {
            (*pcVar2)(iVar6 + iVar7,(uint)uVar1 + iVar6 + iVar7);
          }
          DAT_c029add8 = DAT_c029add8 + 1;
          if (DAT_c029adc8 == 0) {
            uVar10 = param_1;
          }
        }
      }
      else {
        DAT_c029adc8 = 0x1115;
        DAT_c029ad74 = piVar8;
      }
    }
    else {
      DAT_c029adc8 = 0x1114;
      DAT_c029ad74 = piVar8;
    }
  }
  DAT_c029adcc = uVar3;
  DAT_c029add0 = uVar4;
  return uVar10;
}



/* c0294a1c FUN_c0294a1c */

int FUN_c0294a1c(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_c029ad80 + 0x128);
  iVar1 = *(int *)(DAT_c029ad80 + 0x98);
  while( true ) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      return 0;
    }
    if (*(byte *)(iVar1 + 7) == param_1) break;
    iVar1 = iVar1 + 8;
  }
  return iVar1;
}



/* c0294a60 FUN_c0294a60 */

/* Boundary evidence: original MIPS .pdata c0294a60..c0294b4f. Semantic name remains unreviewed. */

undefined4 FUN_c0294a60(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = DAT_c029add0;
  uVar4 = DAT_c029adcc;
  piVar2 = (int *)FUN_c0294a1c(param_2 & 0xff);
  if (piVar2 == (int *)0x0) {
    DAT_c029adc8 = 0x1101;
  }
  else if (*(byte *)((int)piVar2 + 6) < 2) {
    DAT_c029add8 = DAT_c029add8 + -1;
    iVar3 = *(int *)((*(byte *)((int)piVar2 + 6) + 0x16) * 8 + DAT_c029ad80) + *piVar2;
    if (DAT_c029add8 == 0) {
      DAT_c029adc8 = 0x1106;
      DAT_c029add8 = 0;
    }
    else {
      (*DAT_c029adb0)(iVar3,(uint)*(ushort *)(piVar2 + 1) + iVar3);
      DAT_c029add8 = DAT_c029add8 + 1;
      DAT_c029adcc = uVar4;
      DAT_c029add0 = uVar1;
      if (DAT_c029adc8 == 0) {
        uVar4 = param_1;
      }
    }
  }
  else {
    DAT_c029adc8 = 0x1115;
  }
  return uVar4;
}



/* c0294b50 FUN_c0294b50 */

/* Boundary evidence: original MIPS .pdata c0294b50..c0294cff. Semantic name remains unreviewed. */

byte * FUN_c0294b50(byte *param_1)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  int *piVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  
  piVar2 = DAT_c029ad80;
  bVar1 = *(byte *)((int)DAT_c029ad80 + 0x125);
  pbVar6 = DAT_c029adcc;
  if (bVar1 < 2) {
    iVar8 = DAT_c029ad80[(bVar1 + 0x16) * 2];
    if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
      DAT_c029adc8 = 0x1110;
    }
    else {
      DAT_c029ad74 = DAT_c029ad74 + -1;
      uVar7 = *DAT_c029ad74;
      if ((uVar7 & 0xffffff00) == 0) {
        piVar4 = (int *)FUN_c0294a1c(uVar7 & 0xff);
        if (piVar4 == (int *)0x0) {
          if ((int)(uint)*(ushort *)(piVar2[0x4c] + 0x16) <= piVar2[0x4a]) {
            DAT_c029adc8 = 0x1118;
            return DAT_c029adcc;
          }
          piVar4 = (int *)(piVar2[0x4a] * 8 + piVar2[0x26]);
          piVar2[0x4a] = piVar2[0x4a] + 1;
        }
        *(byte *)((int)piVar4 + 6) = bVar1;
        *(char *)((int)piVar4 + 7) = (char)uVar7;
        *piVar4 = (int)param_1 - iVar8;
        pbVar3 = DAT_c029adcc;
        bVar1 = *param_1;
        pbVar5 = param_1;
        while ((bVar1 != 0x2d && (pbVar5 + 1 < pbVar3))) {
          pbVar5 = FUN_c0292db0(pbVar5 + 1);
          bVar1 = *pbVar5;
        }
        pbVar6 = pbVar5 + 1;
        if ((pbVar6 == pbVar3) && (*pbVar5 != 0x2d)) {
          DAT_c029adc8 = 0x1104;
        }
        *(short *)(piVar4 + 1) = ((short)pbVar6 - (short)param_1) + -1;
      }
      else {
        DAT_c029adc8 = 0x1117;
      }
    }
  }
  else {
    DAT_c029adc8 = 0x1109;
  }
  return pbVar6;
}



/* c0294e80 FUN_c0294e80 */

/* Boundary evidence: original MIPS .pdata c0294e80..c029521f. Semantic name remains unreviewed. */

undefined4 FUN_c0294e80(undefined4 param_1,undefined *param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  ushort uVar11;
  int *piVar12;
  short sVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  short sVar17;
  
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    uVar14 = *DAT_c029ad74 << 1;
    if ((uint)((int)DAT_c029ad74 - *DAT_c029ad80 >> 2) < uVar14) {
      DAT_c029adc8 = 0x1110;
      param_1 = DAT_c029adcc;
    }
    else {
      DAT_c029ad74 = DAT_c029ad74 + *DAT_c029ad74 * -2;
      uVar7 = (uint)*(ushort *)(DAT_c029ad80 + 3);
      if ((char)DAT_c029ad80[0x4b] == '\0') {
        uVar2 = FUN_c028c3f0();
        uVar7 = FUN_c0274f80(uVar7,uVar2);
      }
      iVar8 = uVar7 - param_3;
      if ((iVar8 < 0x10) && (-1 < iVar8)) {
        uVar2 = iVar8 * 0x10;
        iVar8 = 0;
        uVar7 = uVar14;
        while (uVar7 = (int)uVar7 >> 1 & 0xfffffffe, 2 < (int)uVar7) {
          if ((int)(DAT_c029ad74[iVar8 + uVar7] & 0xfffffff0U) < (int)uVar2) {
            iVar8 = iVar8 + uVar7;
          }
        }
        if (iVar8 < (int)uVar14) {
          iVar15 = iVar8 << 2;
          iVar3 = DAT_c029ad7c;
          puVar4 = DAT_c029adbc;
          iVar5 = DAT_c029ad5c;
          puVar6 = DAT_c029ada4;
          piVar12 = DAT_c029ad80;
          piVar16 = DAT_c029ad74;
          sVar13 = DAT_c029ad68._2_2_;
          sVar17 = (short)DAT_c029ad68;
          do {
            uVar9 = *(uint *)(iVar15 + (int)piVar16);
            uVar7 = uVar9 & 0xfffffff0;
            if (uVar7 == uVar2) {
              uVar9 = uVar9 & 0xf;
              iVar10 = 7;
              if (uVar9 < 8) {
                iVar10 = 8;
              }
              uVar7 = ((uint *)(iVar15 + (int)piVar16))[1];
              if (param_2 == puVar6) {
                if (iVar3 == iVar5) {
                  if (((int)(uint)*(ushort *)(piVar12[0x4c] + 0x10) <= (int)uVar7) ||
                     ((int)uVar7 < 0)) {
                    DAT_c029adc8 = 0x1112;
                    return DAT_c029adcc;
                  }
                }
                else if ((piVar12[0x59] <= (int)uVar7) || ((int)uVar7 < 0)) {
                  DAT_c029adc8 = 0x1112;
                  return DAT_c029adcc;
                }
              }
              else if (((int)(uint)*(ushort *)(piVar12 + 0x4d) <= (int)uVar7) || ((int)uVar7 < 0)) {
                DAT_c029adc8 = 0x111b;
                return DAT_c029adcc;
              }
              if (((param_2 != puVar4) && ((*(ushort *)(piVar12 + 0x5c) & 1) != 0)) &&
                 ((piVar12[0x1b] & 4U) == 0)) {
                if ((*(ushort *)(piVar12 + 0x5c) & 4) == 0) {
                  if ((sVar13 != 0x4000) || (sVar17 != 0)) goto LAB_c029517c;
                  if (*(char *)((int)piVar12 + 0x12d) == '\0') {
                    if ((*(byte *)(*(int *)(iVar5 + 0x24) + (int)(short)uVar7) & 2) != 0) {
                      uVar11 = *(ushort *)((int)piVar12 + 0x172) & 2;
LAB_c029516c:
                      if (uVar11 == 0) goto LAB_c0295174;
                    }
                    goto LAB_c029517c;
                  }
LAB_c0295174:
                  bVar1 = true;
                }
                else {
                  if ((sVar17 == 0x4000) && (sVar13 == 0)) {
                    if (*(char *)((int)piVar12 + 0x12d) != '\0') goto LAB_c0295174;
                    if ((*(byte *)(*(int *)(iVar5 + 0x24) + (int)(short)uVar7) & 1) != 0) {
                      uVar11 = *(ushort *)((int)piVar12 + 0x172) & 1;
                      goto LAB_c029516c;
                    }
                  }
LAB_c029517c:
                  bVar1 = false;
                }
                if (!bVar1) goto LAB_c02951b4;
              }
              (*(code *)param_2)(iVar5,uVar7,(int)((uVar9 - iVar10) * 0x40) >> (param_4 & 0x1f));
              iVar3 = DAT_c029ad7c;
              puVar4 = DAT_c029adbc;
              iVar5 = DAT_c029ad5c;
              puVar6 = DAT_c029ada4;
              piVar12 = DAT_c029ad80;
              piVar16 = DAT_c029ad74;
              sVar17 = (short)DAT_c029ad68;
              sVar13 = DAT_c029ad68._2_2_;
            }
            else if ((int)uVar2 < (int)uVar7) {
              return param_1;
            }
LAB_c02951b4:
            iVar8 = iVar8 + 2;
            iVar15 = iVar15 + 8;
          } while (iVar8 < (int)uVar14);
        }
      }
    }
  }
  return param_1;
}



/* c0295220 FUN_c0295220 */

/* Boundary evidence: original MIPS .pdata c0295220..c029524f. Semantic name remains unreviewed. */

void FUN_c0295220(undefined4 param_1)

{
  FUN_c0294e80(param_1,DAT_c029ada4,(int)*(short *)(DAT_c029ad80 + 0x88),
               (int)*(short *)(DAT_c029ad80 + 0x8a));
  return;
}



/* c0295250 FUN_c0295250 */

/* Boundary evidence: original MIPS .pdata c0295250..c029528b. Semantic name remains unreviewed. */

void FUN_c0295250(undefined4 param_1)

{
  FUN_c0294e80(param_1,DAT_c029ada4,(*(short *)(DAT_c029ad80 + 0x88) + 0x10) * 0x10000 >> 0x10,
               (int)*(short *)(DAT_c029ad80 + 0x8a));
  return;
}



/* c029528c FUN_c029528c */

/* Boundary evidence: original MIPS .pdata c029528c..c02952c7. Semantic name remains unreviewed. */

void FUN_c029528c(undefined4 param_1)

{
  FUN_c0294e80(param_1,DAT_c029ada4,(*(short *)(DAT_c029ad80 + 0x88) + 0x20) * 0x10000 >> 0x10,
               (int)*(short *)(DAT_c029ad80 + 0x8a));
  return;
}



/* c02952c8 FUN_c02952c8 */

/* Boundary evidence: original MIPS .pdata c02952c8..c02952f7. Semantic name remains unreviewed. */

void FUN_c02952c8(undefined4 param_1)

{
  FUN_c0294e80(param_1,DAT_c029adbc,(int)*(short *)(DAT_c029ad80 + 0x88),
               (int)*(short *)(DAT_c029ad80 + 0x8a));
  return;
}



/* c02952f8 FUN_c02952f8 */

/* Boundary evidence: original MIPS .pdata c02952f8..c0295333. Semantic name remains unreviewed. */

void FUN_c02952f8(undefined4 param_1)

{
  FUN_c0294e80(param_1,DAT_c029adbc,(*(short *)(DAT_c029ad80 + 0x88) + 0x10) * 0x10000 >> 0x10,
               (int)*(short *)(DAT_c029ad80 + 0x8a));
  return;
}



/* c0295334 FUN_c0295334 */

/* Boundary evidence: original MIPS .pdata c0295334..c029536f. Semantic name remains unreviewed. */

void FUN_c0295334(undefined4 param_1)

{
  FUN_c0294e80(param_1,DAT_c029adbc,(*(short *)(DAT_c029ad80 + 0x88) + 0x20) * 0x10000 >> 0x10,
               (int)*(short *)(DAT_c029ad80 + 0x8a));
  return;
}



/* c0295370 FUN_c0295370 */

/* Boundary evidence: original MIPS .pdata c0295370..c0295413. Semantic name remains unreviewed. */

uint FUN_c0295370(uint param_1,int param_2)

{
  uint uVar1;
  
  if (((*(uint *)(DAT_c029ad80 + 0x6c) & 4) == 0) && (DAT_c029adac == FUN_c028c330)) {
    uVar1 = FUN_c028bd08(param_1,param_2);
  }
  else {
    if (param_2 < 0) {
      param_2 = param_2 + 1;
    }
    if ((int)param_1 < 0) {
      uVar1 = -((param_2 >> 1) - param_1 & 0xfffffffc);
    }
    else {
      uVar1 = param_1 + (param_2 >> 1) & 0xfffffffc;
    }
    if (((int)(uVar1 ^ param_1) < 0) && (param_1 != 0)) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* c0295414 FUN_c0295414 */

/* Boundary evidence: original MIPS .pdata c0295414..c02954d3. Semantic name remains unreviewed. */

undefined4 FUN_c0295414(void *param_1,void *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  *(undefined1 *)(param_3 + 0x49) = 1;
  *(undefined1 *)((int)param_3 + 0x125) = 1;
  *(undefined2 *)(param_3 + 0x1e) = 3;
  param_3[0x1d] = FUN_c028be00;
  param_3[0x4a] = 0;
  param_3[8] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  *(undefined2 *)((int)param_3 + 0x172) = 0;
  *(undefined2 *)(param_3 + 0x5d) = 0;
  iVar3 = 0;
  if (*(short *)(param_3[0x4c] + 0x14) != 0) {
    iVar2 = 0;
    do {
      *(undefined2 *)(param_3[0x25] + iVar2 + 6) = 2;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 8;
    } while (iVar3 < (int)(uint)*(ushort *)(param_3[0x4c] + 0x14));
  }
  iVar3 = param_3[0x2e];
  if (iVar3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c028c7a0(param_1,param_2,iVar3,param_3[0x2f] + iVar3,param_3,param_4);
  }
  return uVar1;
}



/* c02954d4 FUN_c02954d4 */

/* Boundary evidence: original MIPS .pdata c02954d4..c029559f. Semantic name remains unreviewed. */

undefined4 FUN_c02954d4(void *param_1,void *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined1 *)(param_3 + 0x49) = 1;
  memcpy(param_3 + 0x17,param_3 + 9,0x38);
  iVar2 = param_3[0x2c];
  *(undefined1 *)((int)param_3 + 0x125) = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c028c7a0(param_1,param_2,iVar2,param_3[0x2d] + iVar2,param_3,param_4);
  }
  if ((param_3[0x1b] & 2) == 0) {
    memcpy(param_3 + 9,param_3 + 0x17,0x38);
  }
  return uVar1;
}



/* c02955a0 FUN_c02955a0 */

/* Boundary evidence: original MIPS .pdata c02955a0..c0295683. Semantic name remains unreviewed. */

undefined4
FUN_c02955a0(void *param_1,void *param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
            int param_6,undefined2 *param_7,undefined2 *param_8,uint *param_9)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_5 + 0x49) = 0;
  *(undefined1 *)((int)param_5 + 0x125) = 2;
  uVar1 = 0;
  memcpy(param_5 + 0x17,param_5 + 9,0x38);
  if ((param_5[0x1b] & 1) == 0) {
    uVar1 = FUN_c028c7a0(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  *param_9 = (uint)(param_5[0x1a] != param_5[0xc]);
  *param_8 = (short)param_5[0x1a];
  *param_7 = *(undefined2 *)((int)param_5 + 0x6a);
  return uVar1;
}



/* c0295684 FUN_c0295684 */

/* Boundary evidence: original MIPS .pdata c0295684..c0295763. Semantic name remains unreviewed. */

undefined4 FUN_c0295684(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    iVar2 = 1;
    FUN_c028e778(*DAT_c029ad74,1);
    piVar1 = DAT_c029ad80;
    *(undefined2 *)(DAT_c029ad80 + 0x1e) = 6;
    if ((DAT_c029ade0 == 0) ||
       (((DAT_c029ad80[0x1b] & 4U) == 0 && (*(char *)((int)DAT_c029ad80 + 0x125) == '\0')))) {
      iVar2 = 0;
    }
    piVar1[0x1d] = (int)(&PTR_LAB_c02617b8)[iVar2 * 8];
    DAT_c029adc4 = 0;
  }
  return param_1;
}



/* c0295764 FUN_c0295764 */

/* Boundary evidence: original MIPS .pdata c0295764..c029583f. Semantic name remains unreviewed. */

undefined4 FUN_c0295764(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((int)DAT_c029ad74 - *DAT_c029ad80 >> 2 == 0) {
    DAT_c029adc8 = 0x1110;
    param_1 = DAT_c029adcc;
  }
  else {
    DAT_c029ad74 = DAT_c029ad74 + -1;
    FUN_c028e778(*DAT_c029ad74,0);
    piVar1 = DAT_c029ad80;
    *(undefined2 *)(DAT_c029ad80 + 0x1e) = 7;
    if ((DAT_c029ade0 == 0) ||
       (((DAT_c029ad80[0x1b] & 4U) == 0 && (*(char *)((int)DAT_c029ad80 + 0x125) == '\0')))) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
    piVar1[0x1d] = (int)(&PTR_FUN_c02617bc)[iVar2 * 8];
    DAT_c029adc4 = 0;
  }
  return param_1;
}



/* c0295840 FUN_c0295840 */

void FUN_c0295840(uint param_1,uint param_2,int *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  
  *param_3 = (param_2 >> 0x10) * (param_1 >> 0x10);
  uVar1 = (param_2 & 0xffff) * (param_1 >> 0x10);
  *param_4 = (param_2 & 0xffff) * (param_1 & 0xffff);
  uVar2 = (param_2 >> 0x10) * (param_1 & 0xffff);
  *param_3 = (uVar2 >> 0x10) + (uVar1 >> 0x10) + *param_3;
  *param_4 = (uVar2 + uVar1) * 0x10000 + *param_4;
  return;
}



/* c02958c0 FUN_c02958c0 */

/* Boundary evidence: original MIPS .pdata c02958c0..c029597b. Semantic name remains unreviewed. */

void FUN_c02958c0(uint *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int local_28;
  int iStack_24;
  
  iVar5 = 2;
  do {
    iVar6 = 2;
    puVar4 = param_1;
    do {
      uVar3 = *puVar4;
      bVar1 = (int)uVar3 < 0;
      if ((int)uVar3 < 0) {
        uVar3 = -uVar3;
      }
      FUN_c0295840(uVar3,0x51e,&local_28,&iStack_24);
      iVar2 = local_28 * 0x10000;
      uVar3 = uVar3 + local_28 * -0x10000;
      if (bVar1) {
        uVar3 = -uVar3;
      }
      *puVar4 = uVar3;
      iVar6 = iVar6 + -1;
      puVar4 = puVar4 + 1;
      local_28 = iVar2;
    } while (iVar6 != 0);
    param_1 = param_1 + 3;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}



/* c029597c FUN_c029597c */

void FUN_c029597c(int param_1,undefined4 param_2,undefined2 param_3)

{
  *(undefined4 *)(param_1 + 0x148) = param_2;
  *(undefined2 *)(param_1 + 0x170) = param_3;
  return;
}



/* c0295a34 FUN_c0295a34 */

/* Boundary evidence: original MIPS .pdata c0295a34..c0295a57. Semantic name remains unreviewed. */

void FUN_c0295a34(uint *param_1,uint param_2)

{
  FUN_c0274f80(param_2,*param_1);
  return;
}



/* c0295a58 FUN_c0295a58 */

/* Boundary evidence: original MIPS .pdata c0295a58..c0295b1b. Semantic name remains unreviewed. */

undefined * FUN_c0295a58(undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  
  iVar1 = FUN_c0275cb0(param_2 | param_3);
  uVar4 = iVar1 - 1;
  if (0 < (int)uVar4) {
    param_2 = (int)param_2 >> (uVar4 & 0x1f);
    param_3 = (int)param_3 >> (uVar4 & 0x1f);
  }
  if ((int)param_2 < 0x2000000) {
    param_2 = param_2 << 6;
  }
  else {
    param_3 = (int)param_3 >> 6;
  }
  uVar2 = FUN_c0275080(param_2,param_3);
  *param_1 = uVar2;
  if ((int)param_2 < 0x8000) {
    iVar1 = FUN_c0276278(param_3);
    param_1[2] = param_2;
    param_1[1] = param_3;
    if (iVar1 < 0) {
      pcVar3 = (code *)&LAB_c02959ac;
    }
    else {
      param_1[3] = iVar1;
      pcVar3 = (code *)&LAB_c0295988;
    }
  }
  else {
    pcVar3 = FUN_c0295a34;
  }
  return pcVar3;
}



/* c0295b1c FUN_c0295b1c */

/* Boundary evidence: original MIPS .pdata c0295b1c..c0295cc3. Semantic name remains unreviewed. */

void FUN_c0295b1c(uint *param_1,undefined1 *param_2,int *param_3,int *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 == &LAB_c0295988) {
    if (0 < param_5) {
      piVar1 = param_4;
      do {
        param_5 = param_5 + -1;
        *piVar1 = (int)(*(int *)(((int)param_3 - (int)param_4) + (int)piVar1) * param_1[2] +
                       ((int)param_1[1] >> 1)) >> (param_1[3] & 0x1f);
        piVar1 = piVar1 + 1;
      } while (param_5 != 0);
    }
  }
  else if (param_2 == &LAB_c02959ac) {
    if (0 < param_5) {
      iVar4 = (int)param_4 - (int)param_3;
      do {
        iVar2 = *param_3 * param_1[2];
        if (*param_3 < 0) {
          uVar3 = param_1[1];
          iVar2 = ((int)uVar3 >> 1) - iVar2;
          if (uVar3 == 0) {
            trap(0x1c00);
          }
          if ((uVar3 == 0xffffffff) && (iVar2 == -0x80000000)) {
            trap(0x1800);
          }
          iVar5 = -(iVar2 / (int)uVar3);
        }
        else {
          uVar3 = param_1[1];
          iVar2 = iVar2 + ((int)uVar3 >> 1);
          iVar5 = iVar2 / (int)uVar3;
          if (uVar3 == 0) {
            trap(0x1c00);
          }
          if ((uVar3 == 0xffffffff) && (iVar2 == -0x80000000)) {
            trap(0x1800);
          }
        }
        piVar1 = (int *)(iVar4 + (int)param_3);
        param_3 = param_3 + 1;
        param_5 = param_5 + -1;
        *piVar1 = iVar5;
      } while (param_5 != 0);
    }
  }
  else if (0 < param_5) {
    piVar1 = param_4;
    do {
      iVar4 = FUN_c0274f80(*(uint *)((int)piVar1 + ((int)param_3 - (int)param_4)),*param_1);
      param_5 = param_5 + -1;
      *piVar1 = iVar4;
      piVar1 = piVar1 + 1;
    } while (param_5 != 0);
  }
  return;
}



/* c0295cc4 FUN_c0295cc4 */

/* Boundary evidence: original MIPS .pdata c0295cc4..c0295e7b. Semantic name remains unreviewed. */

void FUN_c0295cc4(int *param_1,undefined1 *param_2,int *param_3,int *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((param_2 == &LAB_c0295988) && (param_1[2] < 0x1ff)) {
    iVar2 = param_1[3];
    if (0 < param_5) {
      piVar1 = param_4;
      do {
        param_5 = param_5 + -1;
        *piVar1 = *(int *)(((int)param_3 - (int)param_4) + (int)piVar1) * param_1[2] +
                  (param_1[1] >> 1) >> (iVar2 + 6U & 0x1f);
        piVar1 = piVar1 + 1;
      } while (param_5 != 0);
    }
  }
  else if (param_2 == &LAB_c02959ac) {
    iVar2 = param_1[2];
    if (0 < param_5) {
      iVar6 = (int)param_4 - (int)param_3;
      do {
        iVar3 = *param_3 * (iVar2 >> 6);
        if (*param_3 < 0) {
          iVar4 = param_1[1];
          iVar3 = (iVar4 >> 1) - iVar3;
          if (iVar4 == 0) {
            trap(0x1c00);
          }
          if ((iVar4 == -1) && (iVar3 == -0x80000000)) {
            trap(0x1800);
          }
          iVar4 = -(iVar3 / iVar4);
        }
        else {
          iVar5 = param_1[1];
          iVar3 = iVar3 + (iVar5 >> 1);
          iVar4 = iVar3 / iVar5;
          if (iVar5 == 0) {
            trap(0x1c00);
          }
          if ((iVar5 == -1) && (iVar3 == -0x80000000)) {
            trap(0x1800);
          }
        }
        piVar1 = (int *)(iVar6 + (int)param_3);
        param_3 = param_3 + 1;
        param_5 = param_5 + -1;
        *piVar1 = iVar4;
      } while (param_5 != 0);
    }
  }
  else {
    iVar2 = *param_1;
    if (0 < param_5) {
      piVar1 = param_4;
      do {
        iVar6 = FUN_c0274f80(*(uint *)((int)piVar1 + ((int)param_3 - (int)param_4)),iVar2 >> 6);
        param_5 = param_5 + -1;
        *piVar1 = iVar6;
        piVar1 = piVar1 + 1;
      } while (param_5 != 0);
    }
  }
  return;
}



/* c0295e7c FUN_c0295e7c */

/* Boundary evidence: original MIPS .pdata c0295e7c..c0295eef. Semantic name remains unreviewed. */

void FUN_c0295e7c(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *param_1;
  if (0 < param_5) {
    puVar3 = param_4;
    do {
      uVar1 = FUN_c0275080(*(int *)((param_3 - (int)param_4) + (int)puVar3),iVar2 >> 6);
      param_5 = param_5 + -1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    } while (param_5 != 0);
  }
  return;
}



/* c0295ef0 FUN_c0295ef0 */

/* Boundary evidence: original MIPS .pdata c0295ef0..c0295ff3. Semantic name remains unreviewed. */

void FUN_c0295ef0(int param_1,int param_2)

{
  if (*(char *)(param_2 + 0x14c) == '\0') {
    FUN_c0295b1c((uint *)(param_2 + 0xc0),*(undefined1 **)(param_2 + 0x9c),*(int **)(param_1 + 0x10)
                 ,*(int **)(param_1 + 8),
                 (int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) +
                 1U & 0xffff);
    FUN_c0295b1c((uint *)(param_2 + 0xd0),*(undefined1 **)(param_2 + 0xa0),*(int **)(param_1 + 0x14)
                 ,*(int **)(param_1 + 0xc),
                 (int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) +
                 1U & 0xffff);
  }
  else {
    FUN_c0295b1c((uint *)(param_2 + 0xe0),*(undefined1 **)(param_2 + 0xa4),*(int **)(param_1 + 0x10)
                 ,*(int **)(param_1 + 8),
                 (int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) +
                 1U & 0xffff);
    FUN_c0295b1c((uint *)(param_2 + 0xf0),*(undefined1 **)(param_2 + 0xa8),*(int **)(param_1 + 0x14)
                 ,*(int **)(param_1 + 0xc),
                 (int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) +
                 1U & 0xffff);
  }
  return;
}



/* c0295ff4 FUN_c0295ff4 */

/* Boundary evidence: original MIPS .pdata c0295ff4..c02960f7. Semantic name remains unreviewed. */

void FUN_c0295ff4(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (*(char *)(param_2 + 0x14c) == '\0') {
    FUN_c0295cc4((int *)(param_2 + 0xc0),*(undefined1 **)(param_2 + 0x9c),piVar1,piVar1,
                 (int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff);
    FUN_c0295cc4((int *)(param_2 + 0xd0),*(undefined1 **)(param_2 + 0xa0),(int *)param_1[1],
                 (int *)param_1[1],
                 (int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff);
  }
  else {
    FUN_c0295cc4((int *)(param_2 + 0xe0),*(undefined1 **)(param_2 + 0xa4),piVar1,piVar1,
                 (int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff);
    FUN_c0295cc4((int *)(param_2 + 0xf0),*(undefined1 **)(param_2 + 0xa8),(int *)param_1[1],
                 (int *)param_1[1],
                 (int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff);
  }
  return;
}



/* c02960f8 FUN_c02960f8 */

/* Boundary evidence: original MIPS .pdata c02960f8..c02961d7. Semantic name remains unreviewed. */

void FUN_c02960f8(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = ((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 1U &
          0xffff) * 4;
  piVar2 = (int *)(*(int *)(param_1 + 8) + iVar3);
  piVar1 = (int *)(*(int *)(param_1 + 0x10) + iVar3);
  if (*(char *)(param_2 + 0x14c) == '\0') {
    FUN_c0295b1c((uint *)(param_2 + 0xc0),*(undefined1 **)(param_2 + 0x9c),piVar1,piVar2,8);
    FUN_c0295b1c((uint *)(param_2 + 0xd0),*(undefined1 **)(param_2 + 0xa0),
                 (int *)(*(int *)(param_1 + 0x14) + iVar3),(int *)(*(int *)(param_1 + 0xc) + iVar3),
                 8);
  }
  else {
    FUN_c0295b1c((uint *)(param_2 + 0xe0),*(undefined1 **)(param_2 + 0xa4),piVar1,piVar2,8);
    FUN_c0295b1c((uint *)(param_2 + 0xf0),*(undefined1 **)(param_2 + 0xa8),
                 (int *)(*(int *)(param_1 + 0x14) + iVar3),(int *)(*(int *)(param_1 + 0xc) + iVar3),
                 8);
  }
  return;
}



/* c02961d8 FUN_c02961d8 */

/* Boundary evidence: original MIPS .pdata c02961d8..c029626f. Semantic name remains unreviewed. */

void FUN_c02961d8(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = ((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff) * 4;
  piVar1 = (int *)(*param_1 + iVar2);
  FUN_c0295cc4((int *)(param_2 + 0xe0),*(undefined1 **)(param_2 + 0xa4),piVar1,piVar1,8);
  piVar1 = (int *)(param_1[1] + iVar2);
  FUN_c0295cc4((int *)(param_2 + 0xf0),*(undefined1 **)(param_2 + 0xa8),piVar1,piVar1,8);
  return;
}



/* c0296270 FUN_c0296270 */

/* Boundary evidence: original MIPS .pdata c0296270..c0296373. Semantic name remains unreviewed. */

void FUN_c0296270(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(char *)(param_2 + 0x14c) == '\0') {
    FUN_c0295e7c((int *)(param_2 + 0xc0),*(undefined4 *)(param_2 + 0x9c),iVar1,(undefined4 *)iVar1,
                 (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff);
    FUN_c0295e7c((int *)(param_2 + 0xd0),*(undefined4 *)(param_2 + 0xa0),param_1[1],
                 (undefined4 *)param_1[1],
                 (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff);
  }
  else {
    FUN_c0295e7c((int *)(param_2 + 0xe0),*(undefined4 *)(param_2 + 0xa4),iVar1,(undefined4 *)iVar1,
                 (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff);
    FUN_c0295e7c((int *)(param_2 + 0xf0),*(undefined4 *)(param_2 + 0xa8),param_1[1],
                 (undefined4 *)param_1[1],
                 (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff);
  }
  return;
}



/* c0296374 FUN_c0296374 */

/* Boundary evidence: original MIPS .pdata c0296374..c0296447. Semantic name remains unreviewed. */

void FUN_c0296374(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff) * 4;
  iVar1 = *param_1 + iVar2;
  if (*(char *)(param_2 + 0x14c) == '\0') {
    FUN_c0295e7c((int *)(param_2 + 0xc0),*(undefined4 *)(param_2 + 0x9c),iVar1,(undefined4 *)iVar1,8
                );
    FUN_c0295e7c((int *)(param_2 + 0xd0),*(undefined4 *)(param_2 + 0xa0),param_1[1] + iVar2,
                 (undefined4 *)(param_1[1] + iVar2),8);
  }
  else {
    FUN_c0295e7c((int *)(param_2 + 0xe0),*(undefined4 *)(param_2 + 0xa4),iVar1,(undefined4 *)iVar1,8
                );
    FUN_c0295e7c((int *)(param_2 + 0xf0),*(undefined4 *)(param_2 + 0xa8),param_1[1] + iVar2,
                 (undefined4 *)(param_1[1] + iVar2),8);
  }
  return;
}



/* c0296448 FUN_c0296448 */

void FUN_c0296448(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff;
  piVar1 = (int *)*param_1;
  if (uVar2 != 0) {
    iVar3 = param_1[4] - (int)piVar1;
    do {
      *piVar1 = *(int *)(iVar3 + (int)piVar1) << 6;
      uVar2 = uVar2 - 1;
      piVar1 = piVar1 + 1;
    } while (uVar2 != 0);
  }
  uVar2 = (int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff;
  piVar1 = (int *)param_1[1];
  if (uVar2 != 0) {
    iVar3 = param_1[5] - (int)piVar1;
    do {
      *piVar1 = *(int *)(iVar3 + (int)piVar1) << 6;
      uVar2 = uVar2 - 1;
      piVar1 = piVar1 + 1;
    } while (uVar2 != 0);
  }
  return;
}



/* c02964e8 FUN_c02964e8 */

void FUN_c02964e8(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = ((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff) * 4;
  piVar1 = (int *)(iVar4 + *param_1);
  iVar2 = 8;
  iVar5 = (param_1[4] + iVar4) - (int)piVar1;
  iVar3 = 8;
  do {
    *piVar1 = *(int *)(iVar5 + (int)piVar1) << 6;
    iVar3 = iVar3 + -1;
    piVar1 = piVar1 + 1;
  } while (iVar3 != 0);
  piVar1 = (int *)(param_1[1] + iVar4);
  iVar3 = (param_1[5] + iVar4) - (int)piVar1;
  do {
    *piVar1 = *(int *)(iVar3 + (int)piVar1) << 6;
    iVar2 = iVar2 + -1;
    piVar1 = piVar1 + 1;
  } while (iVar2 != 0);
  return;
}



/* c0296578 FUN_c0296578 */

/* Boundary evidence: original MIPS .pdata c0296578..c02965b3. Semantic name remains unreviewed. */

void FUN_c0296578(int param_1,int *param_2)

{
  if (*(ushort *)(param_1 + 0x134) != 0) {
    FUN_c0295b1c((uint *)(param_1 + 0x100),*(undefined1 **)(param_1 + 0xac),param_2,
                 *(int **)(param_1 + 8),(uint)*(ushort *)(param_1 + 0x134));
  }
  return;
}



/* c02965b4 FUN_c02965b4 */

void FUN_c02965b4(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 8);
  return;
}



/* c02965c0 FUN_c02965c0 */

/* Boundary evidence: original MIPS .pdata c02965c0..c02967f3. Semantic name remains unreviewed. */

void FUN_c02965c0(int param_1,short *param_2,int param_3,int param_4,ushort param_5,ushort param_6)

{
  int iVar1;
  
  memset((void *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) +
                   1U & 0xffff) * 4 + *(int *)(param_1 + 0x14)),0,0x20);
  memset((void *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) +
                   1U & 0xffff) * 4 + *(int *)(param_1 + 0x10)),0,0x20);
  iVar1 = *param_2 - param_3;
  *(int *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 1U &
           0xffff) * 4 + *(int *)(param_1 + 0x10)) = iVar1;
  *(uint *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 2U &
            0xffff) * 4 + *(int *)(param_1 + 0x10)) = (uint)param_5 + iVar1;
  *(int *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 5U &
           0xffff) * 4 + *(int *)(param_1 + 0x10)) = iVar1;
  *(int *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 6U &
           0xffff) * 4 + *(int *)(param_1 + 0x10)) = (int)*param_2;
  iVar1 = param_2[3] + param_4;
  *(int *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 3U &
           0xffff) * 4 + *(int *)(param_1 + 0x14)) = iVar1;
  *(uint *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 4U &
            0xffff) * 4 + *(int *)(param_1 + 0x14)) = iVar1 - (uint)param_6;
  *(int *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 7U &
           0xffff) * 4 + *(int *)(param_1 + 0x14)) = iVar1;
  *(int *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 8U &
           0xffff) * 4 + *(int *)(param_1 + 0x14)) = (int)param_2[3];
  return;
}



/* c02967f4 FUN_c02967f4 */

void FUN_c02967f4(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2)
                    + 1U & 0xffff) * 4 + *(int *)(param_1 + 8));
  if (((*(ushort *)(param_2 + 0x170) & 1) == 0) || ((*(ushort *)(param_2 + 0x170) & 4) != 0)) {
    uVar1 = iVar2 + 0x20U & 0xffffffc0;
  }
  else {
    uVar1 = iVar2 + 2U & 0xfffffffc;
  }
  *(uint *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 1U &
            0xffff) * 4 + *(int *)(param_1 + 8)) = uVar1;
  piVar3 = (int *)(((int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2)
                    + 2U & 0xffff) * 4 + *(int *)(param_1 + 8));
  *piVar3 = (*piVar3 - iVar2) + uVar1;
  return;
}



/* c02968c0 FUN_c02968c0 */

/* Boundary evidence: original MIPS .pdata c02968c0..c0296937. Semantic name remains unreviewed. */

void FUN_c02968c0(undefined4 *param_1)

{
  memcpy((void *)param_1[2],(void *)*param_1,
         ((int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff) << 2);
  memcpy((void *)param_1[3],(void *)param_1[1],
         ((int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff) << 2);
  return;
}



/* c0296938 FUN_c0296938 */

/* Boundary evidence: original MIPS .pdata c0296938..c02969af. Semantic name remains unreviewed. */

void FUN_c0296938(undefined4 *param_1)

{
  memcpy((void *)*param_1,(void *)param_1[2],
         ((int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff) << 2);
  memcpy((void *)param_1[1],(void *)param_1[3],
         ((int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 1U & 0xffff) << 2);
  return;
}



/* c02969b0 FUN_c02969b0 */

/* Boundary evidence: original MIPS .pdata c02969b0..c0296a27. Semantic name remains unreviewed. */

void FUN_c02969b0(int *param_1)

{
  int iVar1;
  
  iVar1 = ((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff) * 4;
  memcpy((void *)(iVar1 + *param_1),(void *)(param_1[2] + iVar1),0x20);
  memcpy((void *)(param_1[1] + iVar1),(void *)(param_1[3] + iVar1),0x20);
  return;
}



/* c0296a28 FUN_c0296a28 */

/* Boundary evidence: original MIPS .pdata c0296a28..c0296c3b. Semantic name remains unreviewed. */

void FUN_c0296a28(int *param_1,int param_2,short param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  iVar1 = (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2);
  iVar1 = FUN_c0274e0c(*(uint *)(param_2 + 0x138),
                       (*(int *)((iVar1 + 2U & 0xffff) * 4 + param_1[4]) -
                       *(int *)((iVar1 + 1U & 0xffff) * 4 + param_1[4])) * 0x10000 >> 0x10,
                       (int)param_3);
  iVar1 = iVar1 + 0x200 >> 10;
  if (((*(ushort *)(param_2 + 0x170) & 1) == 0) || ((*(ushort *)(param_2 + 0x170) & 4) != 0)) {
    uVar3 = iVar1 + 0x20U & 0xffffffc0;
  }
  else {
    uVar3 = iVar1 + 2U & 0xfffffffc;
  }
  iVar1 = (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2);
  *(uint *)((iVar1 + 2U & 0xffff) * 4 + *param_1) =
       *(int *)((iVar1 + 1U & 0xffff) * 4 + *param_1) + uVar3;
  iVar1 = (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2);
  iVar1 = FUN_c0274e0c(*(uint *)(param_2 + 0x13c),
                       (*(int *)((iVar1 + 4U & 0xffff) * 4 + param_1[5]) -
                       *(int *)((iVar1 + 3U & 0xffff) * 4 + param_1[5])) * 0x10000 >> 0x10,
                       (int)param_3);
  puVar4 = (uint *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 3U & 0xffff) * 4 +
                   param_1[1]);
  *puVar4 = *puVar4 + 0x20 & 0xffffffc0;
  iVar2 = (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2);
  *(uint *)((iVar2 + 4U & 0xffff) * 4 + param_1[1]) =
       *(int *)((iVar2 + 3U & 0xffff) * 4 + param_1[1]) + (iVar1 + 0x200 >> 10) + 0x20U & 0xffffffc0
  ;
  return;
}



/* c0296c3c FUN_c0296c3c */

void FUN_c0296c3c(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_2 != 0) && (uVar2 = 0, *(short *)((short)param_1[10] * 2 + param_1[8] + -2) != -1)) {
    iVar1 = 0;
    do {
      *(int *)(*param_1 + iVar1) = param_2 + *(int *)(*param_1 + iVar1);
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar2 < ((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff));
  }
  if ((param_3 != 0) && (uVar2 = 0, *(short *)((short)param_1[10] * 2 + param_1[8] + -2) != -1)) {
    iVar1 = 0;
    do {
      *(int *)(param_1[1] + iVar1) = param_3 + *(int *)(param_1[1] + iVar1);
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar2 < ((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff));
  }
  return;
}



/* c0296d24 FUN_c0296d24 */

/* Boundary evidence: original MIPS .pdata c0296d24..c0296f23. Semantic name remains unreviewed. */

void FUN_c0296d24(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,int param_7,int param_8,undefined4 param_9,int param_10,int param_11)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int in_stack_0000003c;
  uint *in_stack_00000040;
  uint *in_stack_00000044;
  
  if (param_5 == 0) {
    uVar1 = (**(code **)(param_1 + 0x9c))(param_1 + 0xc0);
    iVar3 = param_1 + 0xd0;
    *in_stack_00000040 = uVar1;
    pcVar4 = *(code **)(param_1 + 0xa0);
  }
  else {
    uVar1 = (**(code **)(param_1 + 0xa4))(param_1 + 0xe0);
    *in_stack_00000040 = uVar1;
    pcVar4 = *(code **)(param_1 + 0xa8);
    iVar3 = param_1 + 0xf0;
  }
  uVar1 = (*pcVar4)(iVar3,param_3);
  *in_stack_00000044 = uVar1;
  if (param_6 != 0) {
    uVar1 = FUN_c0275cd4(param_7,param_8);
    uVar2 = FUN_c0275cd4(param_10,param_11);
    if ((uVar1 != 0x10000) || (uVar2 != 0x10000)) {
      uVar1 = FUN_c0274f80(*in_stack_00000040,uVar1);
      *in_stack_00000040 = uVar1;
      uVar1 = FUN_c0274f80(*in_stack_00000044,uVar2);
      *in_stack_00000044 = uVar1;
    }
  }
  if (param_4 != 0) {
    if (((*(ushort *)(param_1 + 0x170) & 1) == 0) ||
       ((in_stack_0000003c != 2 &&
        ((ushort)(in_stack_0000003c == 0) == (*(ushort *)(param_1 + 0x170) & 4))))) {
      *in_stack_00000040 = *in_stack_00000040 + 0x20 & 0xffffffc0;
    }
    else {
      *in_stack_00000040 = *in_stack_00000040 + 2 & 0xfffffffc;
    }
    if (((*(ushort *)(param_1 + 0x170) & 1) == 0) ||
       ((in_stack_0000003c != 2 &&
        ((ushort)(in_stack_0000003c == 0) != (*(ushort *)(param_1 + 0x170) & 4))))) {
      *in_stack_00000044 = *in_stack_00000044 + 0x20 & 0xffffffc0;
    }
    else {
      *in_stack_00000044 = *in_stack_00000044 + 2 & 0xfffffffc;
    }
  }
  if (param_5 == 0) {
    FUN_c0295e7c((int *)(param_1 + 0xc0),*(undefined4 *)(param_1 + 0x9c),(int)in_stack_00000040,
                 in_stack_00000040,1);
    FUN_c0295e7c((int *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xa0),(int)in_stack_00000044,
                 in_stack_00000044,1);
  }
  return;
}



/* c0296f24 FUN_c0296f24 */

void FUN_c0296f24(int *param_1,int param_2,int *param_3,int param_4,int *param_5,int *param_6)

{
  *param_5 = *(int *)(*param_1 + param_2 * 4) - *(int *)(*param_3 + param_4 * 4);
  *param_6 = *(int *)(param_1[1] + param_2 * 4) - *(int *)(param_3[1] + param_4 * 4);
  return;
}



/* c0296f78 FUN_c0296f78 */

void FUN_c0296f78(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff;
  iVar1 = uVar2 * 4;
  *(undefined4 *)(*param_1 + iVar1) = *param_2;
  *(undefined4 *)(iVar1 + param_1[1]) = param_2[1];
  iVar1 = (uVar2 + 1 & 0xffff) * 4;
  *(undefined4 *)(*param_1 + iVar1) = *param_3;
  *(undefined4 *)(iVar1 + param_1[1]) = param_3[1];
  return;
}



/* c0296fe8 FUN_c0296fe8 */

void FUN_c0296fe8(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff;
  iVar1 = uVar2 * 4;
  *param_2 = *(undefined4 *)(*param_1 + iVar1);
  param_2[1] = *(undefined4 *)(param_1[1] + iVar1);
  iVar1 = (uVar2 + 1 & 0xffff) * 4;
  *param_3 = *(undefined4 *)(*param_1 + iVar1);
  param_3[1] = *(undefined4 *)(param_1[1] + iVar1);
  return;
}



/* c0297058 FUN_c0297058 */

void FUN_c0297058(int param_1,short param_2,undefined2 param_3)

{
  **(undefined2 **)(param_1 + 0x1c) = 0;
  **(short **)(param_1 + 0x20) = param_2 + -1;
  *(undefined2 *)(param_1 + 0x28) = param_3;
  return;
}



/* c0297074 FUN_c0297074 */

/* Boundary evidence: original MIPS .pdata c0297074..c029715b. Semantic name remains unreviewed. */

void FUN_c0297074(undefined4 *param_1,size_t param_2,int param_3)

{
  size_t _Size;
  
  _Size = param_2 << 2;
  memset((void *)*param_1,0,_Size);
  memset((void *)param_1[2],0,_Size);
  memset((void *)param_1[4],0,_Size);
  memset((void *)param_1[1],0,_Size);
  memset((void *)param_1[3],0,_Size);
  memset((void *)param_1[5],0,_Size);
  memset((void *)param_1[6],0,param_2);
  memset((void *)param_1[9],0,param_2);
  memset((void *)param_1[7],0,param_3 << 1);
  memset((void *)param_1[8],0,param_3 << 1);
  return;
}



/* c029715c FUN_c029715c */

/* Boundary evidence: original MIPS .pdata c029715c..c029719b. Semantic name remains unreviewed. */

void FUN_c029715c(int param_1)

{
  memset(*(void **)(param_1 + 0x24),0,
         (int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 9U &
         0xffff);
  return;
}



/* c029719c FUN_c029719c */

/* Boundary evidence: original MIPS .pdata c029719c..c02972a3. Semantic name remains unreviewed. */

void FUN_c029719c(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((short)param_2[10] == 0) {
    memcpy(param_1,param_2,0x38);
  }
  else {
    uVar1 = (int)*(short *)((short)param_2[10] * 2 + param_2[8] + -2) + 1U & 0xffff;
    iVar2 = uVar1 * 4;
    *param_1 = iVar2 + *param_2;
    param_1[1] = param_2[1] + iVar2;
    param_1[2] = param_2[2] + iVar2;
    param_1[3] = param_2[3] + iVar2;
    param_1[4] = param_2[4] + iVar2;
    param_1[5] = param_2[5] + iVar2;
    param_1[6] = param_2[6] + uVar1;
    param_1[9] = param_2[9] + uVar1;
    param_1[0xb] = param_2[0xb] + (int)(short)param_2[10];
    param_1[0xd] = uVar1 * 0xc + param_2[0xd];
    param_1[7] = (short)param_2[10] * 2 + param_2[7];
    param_1[8] = (short)param_2[10] * 2 + param_2[8];
    *(undefined2 *)(param_1 + 10) = 0;
  }
  return;
}



/* c02972a4 FUN_c02972a4 */

void FUN_c02972a4(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_2 + 0x28);
  if ((short)uVar1 != 0) {
    uVar4 = (uint)uVar1;
    sVar2 = *(short *)((short)uVar1 * 2 + *(int *)(param_2 + 0x20) + -2) + 1;
    if (uVar4 < *(ushort *)(param_1 + 0x28) + uVar4) {
      iVar5 = uVar4 << 1;
      do {
        psVar3 = (short *)(*(int *)(param_2 + 0x1c) + iVar5);
        *psVar3 = *psVar3 + sVar2;
        psVar3 = (short *)(*(int *)(param_2 + 0x20) + iVar5);
        *psVar3 = *psVar3 + sVar2;
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 2;
      } while (uVar4 < (uint)*(ushort *)(param_1 + 0x28) + (uint)*(ushort *)(param_2 + 0x28));
    }
  }
  *(short *)(param_2 + 0x28) = *(short *)(param_1 + 0x28) + *(short *)(param_2 + 0x28);
  return;
}



/* c0297344 FUN_c0297344 */

void FUN_c0297344(int *param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)*param_2;
  iVar2 = *param_2;
  *param_2 = iVar2 + 2;
  param_1[7] = iVar2 + 2;
  iVar2 = (short)param_1[10] * 2 + *param_2;
  *param_2 = iVar2;
  param_1[8] = iVar2;
  iVar2 = (short)param_1[10] * 2 + *param_2;
  *param_2 = iVar2;
  sVar1 = *(short *)((short)param_1[10] * 2 + param_1[8] + -2);
  *param_1 = iVar2;
  uVar3 = (int)sVar1 + 1U & 0xffff;
  iVar4 = uVar3 * 4;
  iVar2 = iVar4 + *param_2;
  *param_2 = iVar2;
  param_1[1] = iVar2;
  iVar4 = iVar4 + *param_2;
  *param_2 = iVar4;
  param_1[6] = iVar4;
  *param_2 = uVar3 + *param_2;
  return;
}



/* c02973e4 FUN_c02973e4 */

/* Boundary evidence: original MIPS .pdata c02973e4..c02974eb. Semantic name remains unreviewed. */

void FUN_c02973e4(int param_1,uint *param_2,short param_3,int param_4,short param_5,uint *param_6)

{
  uint uVar1;
  
  if (param_4 == 0) {
    uVar1 = FUN_c02750a4((int)param_3,(int)param_5);
    *param_2 = uVar1;
    if ((*(uint *)(param_1 + 0x140) == 0x10000) || (*(short *)(param_1 + 0x16a) == 0)) {
      if ((uVar1 != 0) && (*(short *)(param_1 + 0x16a) != 0)) {
        *param_2 = uVar1 + 0x10000;
      }
    }
    else {
      uVar1 = FUN_c0274f80(uVar1,*(uint *)(param_1 + 0x140));
      *param_2 = uVar1;
      if ((uVar1 != 0) && (*(short *)(param_1 + 0x16a) != 0)) {
        *param_2 = uVar1 + 0x10000;
      }
      uVar1 = FUN_c0275080(*param_2,*(uint *)(param_1 + 0x140));
      *param_2 = uVar1;
    }
    FUN_c0275290(param_2,param_2 + 1,param_6);
  }
  else {
    uVar1 = FUN_c0274e0c(*(uint *)(param_1 + 0x140),(int)param_3,(int)param_5);
    *param_2 = uVar1;
    if ((uVar1 != 0) && (*(short *)(param_1 + 0x16a) != 0)) {
      *param_2 = uVar1 + 0x10000;
    }
  }
  return;
}



/* c02974ec FUN_c02974ec */

/* Boundary evidence: original MIPS .pdata c02974ec..c0297573. Semantic name remains unreviewed. */

void FUN_c02974ec(int param_1,uint *param_2,short param_3,int param_4,short param_5,uint *param_6)

{
  uint uVar1;
  uint *puVar2;
  
  if (param_4 == 0) {
    uVar1 = FUN_c02750a4((int)param_3,(int)param_5);
    puVar2 = param_2 + 1;
    *puVar2 = uVar1;
    if (uVar1 != 0) {
      *puVar2 = uVar1 + 0x10000;
    }
    FUN_c0275290(param_2,puVar2,param_6);
  }
  else {
    uVar1 = FUN_c0274e0c(*(uint *)(param_1 + 0x144),(int)param_3,(int)param_5);
    param_2[1] = uVar1;
    if (uVar1 != 0) {
      param_2[1] = uVar1 + 0x10000;
    }
  }
  return;
}



/* c0297574 FUN_c0297574 */

void FUN_c0297574(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 2U & 0xffff) * 4 +
                  *param_1);
  *param_2 = iVar1;
  *param_2 = iVar1 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U &
                              0xffff) * 4 + *param_1);
  iVar1 = *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 2U & 0xffff) * 4 +
                  param_1[1]);
  param_2[1] = iVar1;
  param_2[1] = iVar1 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U &
                                0xffff) * 4 + param_1[1]);
  return;
}



/* c0297640 FUN_c0297640 */

void FUN_c0297640(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 3U & 0xffff) * 4 +
                  *param_1);
  *param_2 = iVar1;
  *param_2 = iVar1 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 4U &
                              0xffff) * 4 + *param_1);
  iVar1 = *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 3U & 0xffff) * 4 +
                  param_1[1]);
  param_2[1] = iVar1;
  param_2[1] = iVar1 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 4U &
                                0xffff) * 4 + param_1[1]);
  return;
}



/* c029770c FUN_c029770c */

void FUN_c029770c(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  *param_2 = (short)((uint)(*(int *)(param_1 + 0x138) + 0x8000) >> 0x10);
  *param_3 = (short)((uint)(*(int *)(param_1 + 0x13c) + 0x8000) >> 0x10);
  return;
}



/* c0297734 FUN_c0297734 */

void FUN_c0297734(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  for (iVar1 = (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2); -1 < iVar1;
      iVar1 = (iVar1 + -1) * 0x10000 >> 0x10) {
    *piVar2 = *piVar2 + 1;
    piVar2 = piVar2 + 1;
  }
  return;
}



/* c0297780 FUN_c0297780 */

/* Boundary evidence: original MIPS .pdata c0297780..c029781b. Semantic name remains unreviewed. */

void FUN_c0297780(int param_1,undefined4 *param_2,uint *param_3)

{
  if (*(int *)(param_1 + 0x184) == 0) {
    FUN_c0275dd0((int)*(short *)(*(short *)(param_2 + 10) * 2 + param_2[8] + -2) + 9U & 0xffff,
                 (uint *)*param_2,(uint *)param_2[1],param_3,*(uint *)(param_1 + 0x140),
                 *(uint *)(param_1 + 0x144));
  }
  else {
    FUN_c0275dd0((int)*(short *)(*(short *)(param_2 + 10) * 2 + param_2[8] + -2) + 9U & 0xffff,
                 (uint *)*param_2,(uint *)param_2[1],param_3,*(uint *)(param_1 + 0x138),
                 *(uint *)(param_1 + 0x13c));
  }
  return;
}



/* c029781c FUN_c029781c */

void FUN_c029781c(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_2 + 8) + 0x200 >> 10;
  if (param_5 != 0) {
    iVar3 = iVar3 * 6;
  }
  iVar1 = ((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff) * 4;
  uVar4 = iVar3 - *(int *)(*param_1 + iVar1);
  iVar3 = (*(int *)(param_2 + 0x14) + 0x200 >> 10) - *(int *)(param_1[1] + iVar1);
  if ((param_3 != 0) && (param_4 == 0)) {
    if (param_5 == 0) {
      uVar4 = uVar4 + 0x20 & 0xffffffc0;
    }
    else {
      uVar4 = uVar4 + 2 & 0xfffffffc;
    }
  }
  if (((uVar4 != 0) || (iVar3 != 0)) &&
     (iVar1 = 0, *(short *)((short)param_1[10] * 2 + param_1[8] + -2) != -9)) {
    iVar2 = 0;
    do {
      *(int *)(*param_1 + iVar2) = uVar4 + *(int *)(*param_1 + iVar2);
      *(int *)(param_1[1] + iVar2) = iVar3 + *(int *)(param_1[1] + iVar2);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar1 < (int)((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 9U & 0xffff))
    ;
  }
  return;
}



/* c029794c FUN_c029794c */

/* Boundary evidence: original MIPS .pdata c029794c..c029799b. Semantic name remains unreviewed. */

void FUN_c029794c(undefined4 *param_1,uint *param_2)

{
  FUN_c0275dd0((int)*(short *)(*(short *)(param_1 + 10) * 2 + param_1[8] + -2) + 9U & 0xffff,
               (uint *)*param_1,(uint *)param_1[1],param_2,0x10000,0x10000);
  return;
}



/* c029799c FUN_c029799c */

void FUN_c029799c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(short *)((short)param_1[10] * 2 + param_1[8] + -2) != -9) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      *(int *)(param_1[2] + iVar1) = (*(int *)(iVar1 + *param_1) + 3) / 6;
      iVar1 = iVar1 + 4;
    } while (iVar2 < (int)((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 9U & 0xffff))
    ;
  }
  return;
}



/* c0297a20 FUN_c0297a20 */

/* Boundary evidence: original MIPS .pdata c0297a20..c0297acf. Semantic name remains unreviewed. */

void FUN_c0297a20(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*(short *)((short)param_1[10] * 2 + param_1[8] + -2) != -9) {
    iVar2 = 0;
    do {
      iVar1 = FUN_c0274f80(*(uint *)(*param_1 + iVar2),param_2);
      *(int *)(*param_1 + iVar2) = iVar1;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < (int)((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 9U & 0xffff))
    ;
  }
  return;
}



/* c0297ad0 FUN_c0297ad0 */

void FUN_c0297ad0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(short *)((short)param_1[10] * 2 + param_1[8] + -2) != -1) {
    iVar1 = 0;
    do {
      *(int *)(*param_1 + iVar1) = *(int *)(*param_1 + iVar1) + param_2;
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < (int)((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff))
    ;
  }
  iVar2 = (int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2);
  *(int *)((iVar2 + 2U & 0xffff) * 4 + *param_1) =
       *(int *)((iVar2 + 1U & 0xffff) * 4 + *param_1) + param_3;
  return;
}



/* c0297b84 FUN_c0297b84 */

void FUN_c0297b84(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = -0x80000000;
  *param_3 = 0x7fffffff;
  iVar3 = *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 2U & 0xffff) * 4 +
                  *param_1);
  *param_2 = iVar3;
  *param_2 = iVar3 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U &
                              0xffff) * 4 + *param_1);
  iVar3 = 0;
  if (*(short *)((short)param_1[10] * 2 + param_1[8] + -2) != -1) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(*param_1 + iVar2);
      if (iVar4 < iVar1) {
        iVar4 = iVar1;
      }
      if (iVar1 < *param_3) {
        *param_3 = iVar1;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < (int)((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U & 0xffff))
    ;
  }
  *param_4 = *param_2 - iVar4;
  return;
}



/* c0297c8c FUN_c0297c8c */

/* Boundary evidence: original MIPS .pdata c0297c8c..c0298343. Semantic name remains unreviewed. */

undefined4
FUN_c0297c8c(int param_1,int param_2,uint *param_3,ushort param_4,uint param_5,short param_6,
            short param_7,ushort param_8,ushort param_9,short param_10,int param_11,short *param_12,
            short *param_13,int param_14,int *param_15)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint local_90;
  uint local_8c;
  uint local_88;
  int local_84;
  int local_80 [2];
  uint local_78;
  uint local_74;
  uint local_6c;
  uint local_68;
  uint uStack_50;
  int local_4c;
  int local_44;
  
  local_90 = CONCAT22(local_90._2_2_,param_4);
  memcpy(&local_78,param_3,0x24);
  uVar12 = (uint)param_7;
  FUN_c0275f78(param_5,(int)param_6,uVar12,param_3);
  uVar10 = (uint)param_9;
  if (((param_8 != 0) || (uVar10 != 0)) &&
     (iVar2 = FUN_c0274e0c(param_5,uVar12,0x48), 0x32 < (iVar2 + 0x8000 >> 0x10 & 0xffffU))) {
    FUN_c02958c0(param_3);
  }
  FUN_c0275d04((int *)param_3);
  uVar9 = (uint)param_4 << 0x10;
  *(int *)(param_1 + 0x184) = param_14;
  if (param_14 == 0) {
    iVar2 = FUN_c0275cd4(*param_3,param_3[1]);
    *(int *)(param_1 + 0x138) = iVar2;
    iVar2 = FUN_c0275cd4(param_3[3],param_3[4]);
    *(int *)(param_1 + 0x13c) = iVar2;
    *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x138);
    *(int *)(param_1 + 0x144) = iVar2;
    if (param_2 != 0) {
      *(uint *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 0x8000U & 0xffff0000;
      *(uint *)(param_1 + 0x13c) = iVar2 + 0x8000U & 0xffff0000;
    }
  }
  else {
    *(uint *)(param_1 + 0x138) = uVar9;
    *(uint *)(param_1 + 0x13c) = uVar9;
    iVar2 = FUN_c0275cd4(*param_3,param_3[1]);
    *(int *)(param_1 + 0x140) = iVar2;
    iVar2 = FUN_c0275cd4(param_3[3],param_3[4]);
    *(int *)(param_1 + 0x144) = iVar2;
  }
  puVar3 = FUN_c0295a58((undefined4 *)(param_1 + 0xe0),*(uint *)(param_1 + 0x138),uVar9);
  puVar11 = (uint *)(param_1 + 0xf0);
  *(undefined **)(param_1 + 0xa4) = puVar3;
  puVar3 = FUN_c0295a58(puVar11,*(uint *)(param_1 + 0x13c),uVar9);
  uVar9 = *(uint *)(param_1 + 0x138);
  uVar7 = *(uint *)(param_1 + 0x13c);
  *(undefined **)(param_1 + 0xa8) = puVar3;
  if ((int)uVar9 < (int)uVar7) {
    *(undefined **)(param_1 + 0xac) = puVar3;
    *(uint *)(param_1 + 0x100) = *puVar11;
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xf4);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0xf8);
    *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0xfc);
    uVar4 = FUN_c0275080(uVar9,uVar7);
    iVar2 = *(int *)(param_1 + 0x13c);
    *(undefined4 *)(param_1 + 0x110) = uVar4;
    *(undefined4 *)(param_1 + 0x114) = 0x10000;
  }
  else {
    *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa4);
    *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xe0);
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xe4);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0xe8);
    *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0xec);
    *(undefined4 *)(param_1 + 0x110) = 0x10000;
    uVar4 = FUN_c0275080(uVar7,uVar9);
    iVar2 = *(int *)(param_1 + 0x138);
    *(undefined4 *)(param_1 + 0x114) = uVar4;
  }
  *param_15 = *(int *)(param_1 + 0x13c) + 0x8000 >> 0x10;
  bVar1 = FUN_c0275680(*(int *)(param_1 + 0x138),*(int *)(param_1 + 0x13c));
  *(short *)(param_1 + 0xc) = (short)((uint)(iVar2 + 0x8000) >> 0x10);
  *(bool *)(param_1 + 300) = bVar1;
  *(short *)(param_1 + 0xe) = (short)(param_5 + 0x8000 >> 0x10);
  *(int *)(param_1 + 0x10) = iVar2;
  uVar4 = FUN_c0275564((int *)param_3);
  *(char *)(param_1 + 0x118) = (char)uVar4;
  FUN_c0275b24(&local_78,&local_84,local_80);
  *(undefined1 *)(param_1 + 0x119) = 0;
  if (local_84 != 0) {
    *(undefined1 *)(param_1 + 0x119) = 1;
  }
  if (local_80[0] != 0) {
    *(byte *)(param_1 + 0x119) = *(byte *)(param_1 + 0x119) | 2;
  }
  *param_12 = 0;
  *param_13 = 0;
  if ((param_8 == 0) && (uVar10 == 0)) {
    *(undefined2 *)(param_1 + 0x16a) = 0;
    *(undefined2 *)(param_1 + 0x168) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
    return 0;
  }
  iVar2 = FUN_c0274e0c(param_5,uVar12,0x48);
  uVar9 = iVar2 + 0x8000 >> 0x10 & 0xffff;
  iVar2 = FUN_c0275780((int *)param_3);
  if (iVar2 == 8) {
    iVar2 = FUN_c0275850((int *)param_3);
  }
  if (param_14 != 0) {
    iVar5 = uVar9 * uVar10;
    uVar9 = local_90 & 0xffff;
    *param_13 = (short)((iVar5 + -10) / 1000);
  }
  sVar6 = (short)((int)(uVar10 * uVar9 + -10) / 1000);
  *(short *)(param_1 + 0x168) = sVar6;
  *(short *)(param_1 + 0x16a) = (short)((int)(param_8 * uVar9 + -10) / 1000) + 1;
  if (param_14 == 0) {
    *param_13 = sVar6;
  }
  switch(iVar2) {
  case 0:
    *param_12 = *param_13 + 1;
    *param_13 = -*param_13;
    break;
  case 1:
    *param_12 = -*param_13;
    *param_13 = -1 - *param_13;
    break;
  case 2:
    *param_12 = -1 - *param_13;
    break;
  case 3:
    *param_12 = *param_13;
    sVar6 = *param_13 + 1;
    goto LAB_c02980b4;
  case 4:
    *param_12 = *param_13 + 1;
    break;
  case 5:
    *param_12 = *param_13;
    sVar6 = -1 - *param_13;
    goto LAB_c02980b4;
  case 6:
    *param_12 = -1 - *param_13;
    sVar6 = -*param_13;
    goto LAB_c02980b4;
  case 7:
    *param_12 = -*param_13;
    sVar6 = *param_13 + 1;
LAB_c02980b4:
    *param_13 = sVar6;
    break;
  default:
    *param_12 = 0;
    *param_13 = 0;
  }
  if (param_14 == 0) {
    if (uVar12 != (int)param_6) {
      local_8c = (uint)*(ushort *)(param_1 + 0x16a) << 0x10;
      local_88 = (uint)*(ushort *)(param_1 + 0x168) << 0x10;
      iVar2 = FUN_c0274f80(local_74,local_6c);
      iVar5 = FUN_c0274f80(local_78,local_68);
      if (iVar5 - iVar2 < 0) {
        iVar2 = FUN_c0274f80(local_74,local_6c);
        iVar5 = FUN_c0274f80(local_78,local_68);
        uVar10 = iVar2 - iVar5;
      }
      else {
        iVar2 = FUN_c0274f80(local_74,local_6c);
        iVar5 = FUN_c0274f80(local_78,local_68);
        uVar10 = iVar5 - iVar2;
      }
      if (uVar10 == 0) {
        *(undefined2 *)(param_1 + 0x16a) = 0;
        *(undefined2 *)(param_1 + 0x168) = 0;
      }
      else {
        local_78 = FUN_c0275080(local_78,uVar10);
        local_74 = FUN_c0275080(local_74,uVar10);
        local_6c = FUN_c0275080(local_6c,uVar10);
        local_68 = FUN_c0275080(local_68,uVar10);
        memcpy(&uStack_50,&local_78,0x24);
        local_4c = -local_74;
        local_44 = -local_44;
        FUN_c0275dd0(1,&local_8c,&local_88,&local_78,0x10000,0x10000);
        local_8c = FUN_c0274e0c(local_8c,(int)param_6,uVar12);
        FUN_c0275dd0(1,&local_8c,&local_88,&uStack_50,0x10000,0x10000);
        uVar10 = local_8c;
        if ((int)local_8c < 0) {
          uVar10 = -local_8c;
        }
        *(short *)(param_1 + 0x16a) = (short)(uVar10 + 0x8000 >> 0x10);
        uVar10 = local_88;
        if ((int)local_88 < 0) {
          uVar10 = -local_88;
        }
        *(short *)(param_1 + 0x168) = (short)(uVar10 + 0x8000 >> 0x10);
      }
    }
    if ((*(byte *)(param_1 + 0x119) & 1) == 0) {
      *(int *)(param_1 + 0x16c) = param_11 * -0x40;
      return 0;
    }
  }
  local_90 = (uint)param_10;
  puVar8 = (uint *)(param_1 + 0x16c);
  FUN_c0295b1c(puVar11,*(undefined1 **)(param_1 + 0xa8),(int *)&local_90,(int *)puVar8,1);
  *puVar8 = *puVar8 & 0xffffffc0;
  return 0;
}



/* c0298344 FUN_c0298344 */

/* Boundary evidence: original MIPS .pdata c0298344..c02983e7. Semantic name remains unreviewed. */

void FUN_c0298344(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  ushort in_stack_00000028;
  
  uVar4 = (uint)in_stack_00000028 << 0x10;
  uVar1 = uVar4;
  uVar2 = uVar4;
  if (*(int *)(param_1 + 0x184) == 0) {
    uVar1 = FUN_c0275cd4(param_2,param_3);
    uVar2 = FUN_c0275cd4(param_5,param_6);
  }
  puVar3 = FUN_c0295a58((undefined4 *)(param_1 + 0xc0),uVar1,uVar4);
  *(undefined **)(param_1 + 0x9c) = puVar3;
  puVar3 = FUN_c0295a58((undefined4 *)(param_1 + 0xd0),uVar2,uVar4);
  *(undefined **)(param_1 + 0xa0) = puVar3;
  return;
}



/* c02983e8 FUN_c02983e8 */

void FUN_c02983e8(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 1U &
          0xffff;
  iVar4 = *(int *)(uVar5 * 4 + *(int *)(param_1 + 8));
  if (((*(ushort *)(param_2 + 0x170) & 1) == 0) || ((*(ushort *)(param_2 + 0x170) & 4) != 0)) {
    uVar1 = iVar4 + 0x20U & 0xffffffc0;
  }
  else {
    uVar1 = iVar4 + 2U & 0xfffffffc;
  }
  if ((uVar1 - iVar4 != 0) && (uVar5 != 0)) {
    iVar3 = 0;
    do {
      piVar2 = (int *)(iVar3 + *(int *)(param_1 + 8));
      *piVar2 = (uVar1 - iVar4) + *piVar2;
      uVar5 = uVar5 - 1;
      iVar3 = iVar3 + 4;
    } while (uVar5 != 0);
  }
  return;
}



/* c0298490 FUN_c0298490 */

void FUN_c0298490(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = (int)*(short *)(*(short *)(param_1 + 0x28) * 2 + *(int *)(param_1 + 0x20) + -2) + 1U &
          0xffff;
  iVar5 = *(int *)(uVar6 * 4 + *(int *)(param_1 + 8));
  if (((*(ushort *)(param_2 + 0x170) & 1) == 0) || ((*(ushort *)(param_2 + 0x170) & 4) != 0)) {
    uVar1 = iVar5 + 0x20U & 0xffffffc0;
  }
  else {
    uVar1 = iVar5 + 2U & 0xfffffffc;
  }
  if ((uVar1 - iVar5 != 0) && (uVar6 < uVar6 + 8)) {
    iVar3 = uVar6 << 2;
    iVar4 = (uVar6 + 8) - uVar6;
    do {
      piVar2 = (int *)(iVar3 + *(int *)(param_1 + 8));
      *piVar2 = *piVar2 + (uVar1 - iVar5);
      iVar4 = iVar4 + -1;
      iVar3 = iVar3 + 4;
    } while (iVar4 != 0);
  }
  return;
}



/* c0298544 FUN_c0298544 */

/* Boundary evidence: original MIPS .pdata c0298544..c02986eb. Semantic name remains unreviewed. */

void FUN_c0298544(int *param_1,int param_2,int param_3,int *param_4,int *param_5,int *param_6,
                 int *param_7,int *param_8)

{
  int iVar1;
  
  FUN_c0297574(param_1,param_4);
  *param_5 = param_2 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U &
                                0xffff) * 4 + *param_1);
  param_5[1] = param_3 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 1U &
                                  0xffff) * 4 + param_1[1]);
  iVar1 = *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 6U & 0xffff) * 4 +
                  *param_1);
  *param_6 = iVar1;
  *param_6 = iVar1 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 5U &
                              0xffff) * 4 + *param_1);
  iVar1 = param_3 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 6U &
                             0xffff) * 4 + param_1[1]);
  param_6[1] = iVar1;
  param_6[1] = iVar1 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 5U &
                                0xffff) * 4 + param_1[1]);
  *param_7 = *param_5;
  param_7[1] = param_5[1];
  *param_8 = *param_6;
  param_8[1] = param_6[1];
  return;
}



/* c02986ec FUN_c02986ec */

/* Boundary evidence: original MIPS .pdata c02986ec..c0298893. Semantic name remains unreviewed. */

void FUN_c02986ec(int *param_1,int param_2,int param_3,int *param_4,int *param_5,int *param_6,
                 int *param_7,int *param_8)

{
  int iVar1;
  
  FUN_c0297640(param_1,param_4);
  *param_5 = param_2 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 3U &
                                0xffff) * 4 + *param_1);
  param_5[1] = param_3 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 3U &
                                  0xffff) * 4 + param_1[1]);
  iVar1 = param_2 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 8U &
                             0xffff) * 4 + *param_1);
  *param_6 = iVar1;
  *param_6 = iVar1 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 7U &
                              0xffff) * 4 + *param_1);
  iVar1 = *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 8U & 0xffff) * 4 +
                  param_1[1]);
  param_6[1] = iVar1;
  param_6[1] = iVar1 - *(int *)(((int)*(short *)((short)param_1[10] * 2 + param_1[8] + -2) + 7U &
                                0xffff) * 4 + param_1[1]);
  *param_7 = *param_5;
  param_7[1] = param_5[1];
  *param_8 = *param_6;
  param_8[1] = param_6[1];
  return;
}



/* c0298894 FUN_c0298894 */

/* Boundary evidence: original MIPS .pdata c0298894..c02989a7. Semantic name remains unreviewed. */

void FUN_c0298894(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = 0;
  iVar1 = 0;
  local_18 = 0xffffffff;
  local_14 = -1;
  local_10 = 0x80000000;
  do {
    *(uint *)((int)&DAT_c029b4a0 + iVar2) =
         CONCAT31(CONCAT21(CONCAT11((undefined1)local_18,local_18._1_1_),local_18._2_1_),
                  local_18._3_1_);
    *(uint *)((int)&DAT_c029b61c + iVar1) =
         CONCAT31(CONCAT21(CONCAT11((undefined1)local_14,local_14._1_1_),local_14._2_1_),
                  local_14._3_1_);
    uVar3 = CONCAT31(CONCAT21(CONCAT11((undefined1)local_10,local_10._1_1_),local_10._2_1_),
                     local_10._3_1_);
    local_18 = local_18 >> 1;
    local_14 = local_14 << 1;
    local_10 = local_10 >> 1;
    iVar1 = iVar1 + -4;
    *(undefined4 *)((int)&DAT_c029b520 + iVar2) = uVar3;
    iVar2 = iVar2 + 4;
  } while (-0x80 < iVar1);
  return;
}



/* c02989a8 FUN_c02989a8 */

/* Boundary evidence: original MIPS .pdata c02989a8..c02989d3. Semantic name remains unreviewed. */

undefined4 FUN_c02989a8(int param_1,void *param_2)

{
  memset(param_2,0,param_1 << 2);
  return 0;
}



/* c02989d4 FUN_c02989d4 */

undefined4 FUN_c02989d4(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  iVar1 = param_1 >> 5;
  puVar4 = (uint *)(iVar1 * 4 + param_3);
  uVar3 = param_2 + iVar1 * -0x20;
  iVar1 = param_1 + iVar1 * -0x20;
  if (0x1f < (int)uVar3) {
    uVar2 = uVar3 >> 5;
    uVar3 = uVar3 + uVar2 * -0x20;
    do {
      *puVar4 = (&DAT_c029b4a0)[iVar1] | *puVar4;
      puVar4 = puVar4 + 1;
      uVar2 = uVar2 - 1;
      iVar1 = 0;
    } while (uVar2 != 0);
  }
  *puVar4 = (&DAT_c029b4a0)[iVar1] & *(uint *)(&DAT_c029b5a0 + uVar3 * 4) | *puVar4;
  return 0;
}



/* c0298a68 FUN_c0298a68 */

undefined4 FUN_c0298a68(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return 0;
}



/* c0298a90 FUN_c0298a90 */

uint FUN_c0298a90(uint param_1,int param_2)

{
  return (&DAT_c029b520)[param_1 & 0x1f] & *(uint *)(((int)param_1 >> 5) * 4 + param_2);
}



/* c0298ac0 FUN_c0298ac0 */

undefined4 FUN_c0298ac0(uint param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(((int)param_1 >> 5) * 4 + param_2);
  *puVar1 = (&DAT_c029b520)[param_1 & 0x1f] | *puVar1;
  return 0;
}



/* c0298af8 FUN_c0298af8 */

undefined4 FUN_c0298af8(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  
  pcVar6 = (char *)*param_1;
  uVar1 = 0xff >> (8 - *(ushort *)((int)param_1 + 10) & 0x1f);
  uVar2 = ((int)*pcVar6 & 0xffffU) >> (*(ushort *)(param_1 + 3) & 0x1f);
  uVar5 = 8 - *(ushort *)(param_1 + 3) & 0xffff;
  pcVar4 = (char *)param_1[1];
  iVar3 = (int)*(short *)(param_1 + 2);
  *pcVar4 = (&DAT_c029aad4)[uVar2 & uVar1] + *pcVar4;
  while (iVar3 = (iVar3 + -1) * 0x10000 >> 0x10, 0 < iVar3) {
    pcVar4 = pcVar4 + -1;
    uVar5 = uVar5 - *(ushort *)((int)param_1 + 10) & 0xffff;
    if (uVar5 == 0) {
      pcVar6 = pcVar6 + -1;
      uVar2 = (uint)*pcVar6;
      uVar5 = 8;
    }
    else {
      uVar2 = uVar2 >> (*(ushort *)((int)param_1 + 10) & 0x1f);
    }
    uVar2 = uVar2 & 0xffff;
    *pcVar4 = (&DAT_c029aad4)[uVar2 & uVar1] + *pcVar4;
  }
  return 0;
}



/* c0298bdc FUN_c0298bdc */

/* Boundary evidence: original MIPS .pdata c0298bdc..c0298c23. Semantic name remains unreviewed. */

bool FUN_c0298bdc(void)

{
  DAT_c029ade8 = FUN_c0298ce0(&LAB_c0299488,&LAB_c0299498,free);
  return DAT_c029ade8 != (undefined4 *)0x0;
}



/* c0298c24 FUN_c0298c24 */

/* Boundary evidence: original MIPS .pdata c0298c24..c0298c8f. Semantic name remains unreviewed. */

undefined4 FUN_c0298c24(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 == 0) {
    FUN_c0298c90(DAT_c029ade8);
    FUN_c0298d50((int)DAT_c029ade8);
    DAT_c029ade8 = (int *)0x0;
  }
  else if ((param_2 == 1) && (bVar1 = FUN_c0298bdc(), CONCAT31(extraout_var,bVar1) == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0298c90 FUN_c0298c90 */

/* Boundary evidence: original MIPS .pdata c0298c90..c0298cdf. Semantic name remains unreviewed. */

void FUN_c0298c90(int *param_1)

{
  if (param_1[2] != 0) {
    param_1[7] = 0x3ec;
  }
  if (*param_1 != 0) {
    (*(code *)param_1[6])();
  }
  *param_1 = 0;
  return;
}



/* c0298ce0 FUN_c0298ce0 */

/* Boundary evidence: original MIPS .pdata c0298ce0..c0298d4f. Semantic name remains unreviewed. */

undefined4 * FUN_c0298ce0(undefined *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)param_1)(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = param_1;
    puVar1[5] = param_2;
    puVar1[6] = param_3;
    puVar1[7] = 0;
  }
  return puVar1;
}



/* c0298d50 FUN_c0298d50 */

/* Boundary evidence: original MIPS .pdata c0298d50..c0298d77. Semantic name remains unreviewed. */

void FUN_c0298d50(int param_1)

{
  (**(code **)(param_1 + 0x18))(param_1);
  return;
}



/* c0298ee8 FUN_c0298ee8 */

/* Boundary evidence: original MIPS .pdata c0298ee8..c0299023. Semantic name remains unreviewed. */

int FUN_c0298ee8(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c029b630 != (code *)0x0) {
      iVar2 = (*DAT_c029b630)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0298f98;
    FUN_c029937c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0298c24(param_1,param_2);
  }
LAB_c0298f98:
  if (((param_2 == 0) && (FUN_c0299304(), iVar1 != 0)) && (DAT_c029b630 != (code *)0x0)) {
    iVar1 = (*DAT_c029b630)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0299024 FUN_c0299024 */

/* Boundary evidence: original MIPS .pdata c0299024..c029904f. Semantic name remains unreviewed. */

void FUN_c0299024(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0299050 entry */

/* Boundary evidence: original MIPS .pdata c0299050..c02990a7. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c02990a8();
  }
  FUN_c0298ee8(param_1,param_2,param_3);
  return;
}



/* c02990a8 FUN_c02990a8 */

/* Boundary evidence: original MIPS .pdata c02990a8..c029911b. Semantic name remains unreviewed. */

void FUN_c02990a8(void)

{
  uint uVar1;
  
  if ((DAT_c029ac78 == 0) || (DAT_c029ac78 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c029ac78 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c029ac78 == 0) {
      DAT_c029ac78 = 0xb064;
    }
  }
  DAT_c029ac7c = ~DAT_c029ac78;
  return;
}



/* c029911c FUN_c029911c */

/* Boundary evidence: original MIPS .pdata c029911c..c029916f. Semantic name remains unreviewed. */

void FUN_c029911c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c029919c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0299170 FUN_c0299170 */

/* Boundary evidence: original MIPS .pdata c0299170..c029919b. Semantic name remains unreviewed. */

undefined4 FUN_c0299170(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c029911c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c029919c FUN_c029919c */

/* Boundary evidence: original MIPS .pdata c029919c..c02991e3. Semantic name remains unreviewed. */

void FUN_c029919c(uint param_1)

{
  if ((param_1 == DAT_c029ac78) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c02991e4 FUN_c02991e4 */

/* Boundary evidence: original MIPS .pdata c02991e4..c0299303. Semantic name remains unreviewed. */

void FUN_c02991e4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c029b499 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c029b628;
    if (DAT_c029b628 != (undefined4 *)0x0) {
      while (DAT_c029b624 = DAT_c029b624 + -1, _Memory <= DAT_c029b624) {
        if ((code *)*DAT_c029b624 != (code *)0x0) {
          (*(code *)*DAT_c029b624)();
          _Memory = DAT_c029b628;
        }
      }
      free(_Memory);
      DAT_c029b624 = (undefined4 *)0x0;
      DAT_c029b628 = (undefined4 *)0x0;
    }
    FUN_c0299328((undefined4 *)&DAT_c0261010,(undefined4 *)&DAT_c0261014);
  }
  FUN_c0299328((undefined4 *)&DAT_c0261018,(undefined4 *)&DAT_c026101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c029b62c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0299304 FUN_c0299304 */

/* Boundary evidence: original MIPS .pdata c0299304..c0299327. Semantic name remains unreviewed. */

void FUN_c0299304(void)

{
  FUN_c02991e4(0,0,1);
  return;
}



/* c0299328 FUN_c0299328 */

/* Boundary evidence: original MIPS .pdata c0299328..c029937b. Semantic name remains unreviewed. */

void FUN_c0299328(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c029937c FUN_c029937c */

/* Boundary evidence: original MIPS .pdata c029937c..c02993b7. Semantic name remains unreviewed. */

void FUN_c029937c(void)

{
  FUN_c0299328((undefined4 *)&DAT_c0261008,(undefined4 *)&DAT_c026100c);
  FUN_c0299328((undefined4 *)&DAT_c0261000,(undefined4 *)&DAT_c0261004);
  return;
}


