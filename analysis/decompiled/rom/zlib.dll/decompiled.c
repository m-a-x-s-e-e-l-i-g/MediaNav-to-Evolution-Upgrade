/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 401430c8 adler32 */

uint adler32(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
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
  uint uVar18;
  uint uVar19;
  
                    /* 0x30c8  1  adler32 */
  uVar1 = param_1 & 0xffff;
  uVar8 = param_1 >> 0x10;
  if (param_2 == (byte *)0x0) {
    uVar1 = 1;
  }
  else {
    while (param_3 != 0) {
      uVar18 = param_3;
      if (0x15af < param_3) {
        uVar18 = 0x15b0;
      }
      param_3 = param_3 - uVar18;
      if (0xf < (int)uVar18) {
        uVar19 = uVar18 >> 4;
        uVar18 = uVar18 + uVar19 * -0x10;
        do {
          iVar2 = *param_2 + uVar1;
          iVar3 = (uint)param_2[1] + iVar2;
          iVar9 = (uint)param_2[2] + iVar3;
          iVar14 = (uint)param_2[3] + iVar9;
          iVar4 = (uint)param_2[4] + iVar14;
          iVar10 = (uint)param_2[5] + iVar4;
          iVar15 = (uint)param_2[6] + iVar10;
          iVar5 = (uint)param_2[7] + iVar15;
          iVar11 = (uint)param_2[8] + iVar5;
          iVar16 = (uint)param_2[9] + iVar11;
          iVar6 = (uint)param_2[10] + iVar16;
          iVar12 = (uint)param_2[0xb] + iVar6;
          iVar17 = (uint)param_2[0xc] + iVar12;
          iVar7 = (uint)param_2[0xd] + iVar17;
          iVar13 = (uint)param_2[0xe] + iVar7;
          uVar1 = (uint)param_2[0xf] + iVar13;
          uVar8 = uVar8 + iVar2 + iVar3 + iVar9 + iVar14 + iVar4 + iVar10 + iVar15 + iVar5 + iVar11
                  + iVar16 + iVar6 + iVar12 + iVar17 + iVar7 + iVar13 + uVar1;
          uVar19 = uVar19 - 1;
          param_2 = param_2 + 0x10;
        } while (uVar19 != 0);
      }
      for (; uVar18 != 0; uVar18 = uVar18 - 1) {
        uVar1 = *param_2 + uVar1;
        param_2 = param_2 + 1;
        uVar8 = uVar8 + uVar1;
      }
      uVar1 = uVar1 % 0xfff1;
      uVar8 = uVar8 % 0xfff1;
    }
    uVar1 = uVar8 << 0x10 | uVar1;
  }
  return uVar1;
}



/* 4014322c FUN_4014322c */

void FUN_4014322c(void)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = 0;
  uVar5 = 0;
  do {
    pbVar1 = &DAT_4014103c + uVar5;
    uVar5 = uVar5 + 1;
    uVar7 = 1 << (0x1f - *pbVar1 & 0x1f) | uVar7;
  } while (uVar5 < 0xe);
  puVar4 = &DAT_4014b0c8;
  uVar5 = 0;
  do {
    iVar6 = 8;
    uVar3 = uVar5;
    do {
      uVar2 = uVar3 & 1;
      uVar3 = uVar3 >> 1;
      if (uVar2 != 0) {
        uVar3 = uVar3 ^ uVar7;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
    uVar5 = uVar5 + 1;
  } while ((int)puVar4 < 0x4014b4c8);
  DAT_4014b4c8 = 1;
  return;
}



/* 401432b8 get_crc_table */

/* Boundary evidence: original MIPS .pdata 401432b8..401432f3. Semantic name remains unreviewed. */

undefined4 * get_crc_table(void)

{
                    /* 0x32b8  8  get_crc_table */
  if (DAT_4014b4c8 == 0) {
    FUN_4014322c();
  }
  return &DAT_4014b0c8;
}



/* 401432f4 crc32 */

/* Boundary evidence: original MIPS .pdata 401432f4..401434f7. Semantic name remains unreviewed. */

uint crc32(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x32f4  2  crc32 */
  if (param_2 == (byte *)0x0) {
    uVar1 = 0;
  }
  else {
    if (DAT_4014b4c8 == 0) {
      FUN_4014322c();
    }
    uVar1 = ~param_1;
    if (7 < param_3) {
      uVar2 = param_3 >> 3;
      do {
        uVar1 = (&DAT_4014b0c8)[(*param_2 ^ uVar1) & 0xff] ^ uVar1 >> 8;
        uVar1 = (&DAT_4014b0c8)[(param_2[1] ^ uVar1) & 0xff] ^ uVar1 >> 8;
        uVar1 = (&DAT_4014b0c8)[(param_2[2] ^ uVar1) & 0xff] ^ uVar1 >> 8;
        uVar1 = (&DAT_4014b0c8)[(param_2[3] ^ uVar1) & 0xff] ^ uVar1 >> 8;
        uVar1 = (&DAT_4014b0c8)[(param_2[4] ^ uVar1) & 0xff] ^ uVar1 >> 8;
        uVar1 = (&DAT_4014b0c8)[(param_2[5] ^ uVar1) & 0xff] ^ uVar1 >> 8;
        uVar1 = (&DAT_4014b0c8)[(param_2[6] ^ uVar1) & 0xff] ^ uVar1 >> 8;
        uVar1 = (&DAT_4014b0c8)[(param_2[7] ^ uVar1) & 0xff] ^ uVar1 >> 8;
        param_2 = param_2 + 8;
        param_3 = param_3 - 8;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      uVar1 = (&DAT_4014b0c8)[(*param_2 ^ uVar1) & 0xff] ^ uVar1 >> 8;
      param_2 = param_2 + 1;
    }
    uVar1 = ~uVar1;
  }
  return uVar1;
}



/* 401434f8 FUN_401434f8 */

/* Boundary evidence: original MIPS .pdata 401434f8..401435af. Semantic name remains unreviewed. */

void FUN_401434f8(int param_1)

{
  int iVar1;
  uint _Size;
  
  _Size = *(uint *)(*(int *)(param_1 + 0x1c) + 0x14);
  if (*(uint *)(param_1 + 0x10) < _Size) {
    _Size = *(uint *)(param_1 + 0x10);
  }
  if (_Size != 0) {
    memcpy(*(void **)(param_1 + 0xc),*(void **)(*(int *)(param_1 + 0x1c) + 0x10),_Size);
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + _Size;
    *(uint *)(*(int *)(param_1 + 0x1c) + 0x10) = _Size + *(int *)(*(int *)(param_1 + 0x1c) + 0x10);
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + _Size;
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - _Size;
    *(uint *)(*(int *)(param_1 + 0x1c) + 0x14) = *(int *)(*(int *)(param_1 + 0x1c) + 0x14) - _Size;
    iVar1 = *(int *)(param_1 + 0x1c);
    if (*(int *)(iVar1 + 0x14) == 0) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
    }
  }
  return;
}



/* 401435b0 deflate */

/* Boundary evidence: original MIPS .pdata 401435b0..401439d7. Semantic name remains unreviewed. */

undefined4 deflate(int *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
                    /* 0x35b0  3  deflate */
  if ((((((param_1 == (int *)0x0) ||
         (puVar5 = (undefined4 *)param_1[7], puVar5 == (undefined4 *)0x0)) || (4 < param_2)) ||
       ((param_2 < 0 || (param_1[3] == 0)))) || ((*param_1 == 0 && (param_1[1] != 0)))) ||
     ((puVar5[1] == 0x29a && (param_2 != 4)))) {
    return 0xfffffffe;
  }
  if (param_1[4] == 0) {
    return 0xfffffffb;
  }
  iVar6 = puVar5[8];
  *puVar5 = param_1;
  puVar5[8] = param_2;
  if (puVar5[1] == 0x2a) {
    uVar3 = puVar5[0x1f] + -1 >> 1;
    if (3 < uVar3) {
      uVar3 = 3;
    }
    uVar3 = uVar3 << 6 | (puVar5[10] + -8) * 0x1000 + 0x800U;
    if (puVar5[0x19] != 0) {
      uVar3 = uVar3 | 0x20;
    }
    puVar5[1] = 0x71;
    iVar4 = (uVar3 - uVar3 % 0x1f) + 0x1f;
    *(char *)(puVar5[2] + puVar5[5]) = (char)((uint)iVar4 >> 8);
    iVar2 = puVar5[5];
    puVar5[5] = iVar2 + 1;
    *(char *)(puVar5[2] + iVar2 + 1) = (char)iVar4;
    iVar2 = puVar5[5];
    puVar5[5] = iVar2 + 1;
    if (puVar5[0x19] != 0) {
      uVar1 = *(undefined2 *)((int)param_1 + 0x32);
      *(char *)(puVar5[2] + iVar2 + 1) = (char)((ushort)uVar1 >> 8);
      iVar2 = puVar5[5];
      puVar5[5] = iVar2 + 1;
      *(char *)(puVar5[2] + iVar2 + 1) = (char)uVar1;
      iVar2 = puVar5[5];
      puVar5[5] = iVar2 + 1;
      uVar3 = param_1[0xc];
      *(char *)(puVar5[2] + iVar2 + 1) = (char)((uVar3 & 0xffff) >> 8);
      iVar2 = puVar5[5];
      puVar5[5] = iVar2 + 1;
      *(char *)(puVar5[2] + iVar2 + 1) = (char)(uVar3 & 0xffff);
      puVar5[5] = puVar5[5] + 1;
    }
    param_1[0xc] = 1;
  }
  if (puVar5[5] == 0) {
    if (((param_1[1] == 0) && (param_2 <= iVar6)) && (param_2 != 4)) {
      return 0xfffffffb;
    }
LAB_401437d0:
    if ((puVar5[1] == 0x29a) && (param_1[1] != 0)) {
      return 0xfffffffb;
    }
    if (((param_1[1] != 0) || (puVar5[0x1b] != 0)) || ((param_2 != 0 && (puVar5[1] != 0x29a)))) {
      iVar6 = (*(code *)(&PTR_FUN_40141094)[puVar5[0x1f] * 3])(puVar5,param_2);
      if ((iVar6 == 2) || (iVar6 == 3)) {
        puVar5[1] = 0x29a;
      }
      if ((iVar6 == 0) || (iVar6 == 2)) {
        if (param_1[4] != 0) {
          return 0;
        }
        puVar5[8] = 0xffffffff;
        return 0;
      }
      if (iVar6 == 1) {
        if (param_2 == 1) {
          FUN_401475ec((int)puVar5);
        }
        else {
          FUN_40147548((int)puVar5,(undefined1 *)0x0,0,0);
          if (param_2 == 3) {
            *(undefined2 *)(puVar5[0x11] * 2 + puVar5[0xf] + -2) = 0;
            memset((void *)puVar5[0xf],0,(puVar5[0x11] + -1) * 2);
          }
        }
        FUN_401434f8((int)param_1);
        if (param_1[4] == 0) goto LAB_401437a0;
      }
    }
    if (param_2 == 4) {
      if (puVar5[6] != 0) {
        return 1;
      }
      uVar1 = *(undefined2 *)((int)param_1 + 0x32);
      *(char *)(puVar5[2] + puVar5[5]) = (char)((ushort)uVar1 >> 8);
      iVar6 = puVar5[5];
      puVar5[5] = iVar6 + 1;
      *(char *)(puVar5[2] + iVar6 + 1) = (char)uVar1;
      iVar6 = puVar5[5];
      puVar5[5] = iVar6 + 1;
      uVar3 = param_1[0xc];
      *(char *)(puVar5[2] + iVar6 + 1) = (char)((uVar3 & 0xffff) >> 8);
      iVar6 = puVar5[5];
      puVar5[5] = iVar6 + 1;
      *(char *)(puVar5[2] + iVar6 + 1) = (char)(uVar3 & 0xffff);
      puVar5[5] = puVar5[5] + 1;
      FUN_401434f8((int)param_1);
      puVar5[6] = 0xffffffff;
      if (puVar5[5] == 0) {
        return 1;
      }
    }
  }
  else {
    FUN_401434f8((int)param_1);
    if (param_1[4] != 0) goto LAB_401437d0;
LAB_401437a0:
    puVar5[8] = 0xffffffff;
  }
  return 0;
}



/* 401439d8 deflateEnd */

/* Boundary evidence: original MIPS .pdata 401439d8..40143ad7. Semantic name remains unreviewed. */

undefined4 deflateEnd(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x39d8  4  deflateEnd */
  if (((param_1 == 0) || (iVar2 = *(int *)(param_1 + 0x1c), iVar2 == 0)) ||
     ((iVar3 = *(int *)(iVar2 + 4), iVar3 != 0x2a && ((iVar3 != 0x71 && (iVar3 != 0x29a)))))) {
    uVar1 = 0xfffffffe;
  }
  else {
    if (*(int *)(iVar2 + 8) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x3c) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x38) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x30) != 0) {
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    }
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if (iVar3 == 0x71) {
      uVar1 = 0xfffffffd;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40143ad8 FUN_40143ad8 */

/* Boundary evidence: original MIPS .pdata 40143ad8..40143cfb. Semantic name remains unreviewed. */

char * FUN_40143ad8(int param_1,uint param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar8;
  char cVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar7;
  
  uVar3 = *(uint *)(param_1 + 100);
  uVar10 = *(uint *)(param_1 + 0x74);
  pcVar1 = *(char **)(param_1 + 0x70);
  pcVar5 = (char *)(*(int *)(param_1 + 0x30) + uVar3);
  if (*(int *)(param_1 + 0x24) - 0x106U < uVar3) {
    uVar3 = (uVar3 - *(int *)(param_1 + 0x24)) + 0x106;
  }
  else {
    uVar3 = 0;
  }
  cVar2 = (pcVar1 + (int)pcVar5)[-1];
  cVar9 = pcVar1[(int)pcVar5];
  if (*(char **)(param_1 + 0x84) <= pcVar1) {
    uVar10 = uVar10 >> 2;
  }
  pcVar8 = *(char **)(param_1 + 0x6c);
  pcVar11 = *(char **)(param_1 + 0x88);
  if (pcVar8 < *(char **)(param_1 + 0x88)) {
    pcVar11 = pcVar8;
  }
  do {
    pcVar4 = (char *)(*(int *)(param_1 + 0x30) + param_2);
    if ((((pcVar4[(int)pcVar1] == cVar9) && ((pcVar4 + (int)pcVar1)[-1] == cVar2)) &&
        (*pcVar4 == *pcVar5)) && (pcVar4[1] == pcVar5[1])) {
      pcVar4 = pcVar4 + 2;
      pcVar7 = pcVar5 + 2;
      while (((((pcVar6 = pcVar7 + 1, *pcVar6 == pcVar4[1] &&
                (pcVar6 = pcVar7 + 2, *pcVar6 == pcVar4[2])) &&
               ((pcVar6 = pcVar7 + 3, *pcVar6 == pcVar4[3] &&
                ((pcVar6 = pcVar7 + 4, *pcVar6 == pcVar4[4] &&
                 (pcVar6 = pcVar7 + 5, *pcVar6 == pcVar4[5])))))) &&
              (pcVar6 = pcVar7 + 6, *pcVar6 == pcVar4[6])) &&
             (pcVar6 = pcVar7 + 7, *pcVar6 == pcVar4[7]))) {
        pcVar6 = pcVar7 + 8;
        pcVar4 = pcVar4 + 8;
        if ((*pcVar6 != *pcVar4) || (pcVar7 = pcVar6, pcVar5 + 0x102 <= pcVar6)) break;
      }
      pcVar6 = pcVar6 + (0x102 - (int)(pcVar5 + 0x102));
      if ((int)pcVar1 < (int)pcVar6) {
        *(uint *)(param_1 + 0x68) = param_2;
        if ((int)pcVar11 <= (int)pcVar6) {
LAB_40143cd4:
          if (pcVar8 < pcVar6) {
            pcVar6 = pcVar8;
          }
          return pcVar6;
        }
        cVar2 = (pcVar6 + (int)pcVar5)[-1];
        cVar9 = pcVar6[(int)pcVar5];
        pcVar1 = pcVar6;
      }
    }
    pcVar6 = pcVar1;
    param_2 = (uint)*(ushort *)
                     ((*(uint *)(param_1 + 0x2c) & param_2) * 2 + *(int *)(param_1 + 0x38));
    if ((param_2 <= uVar3) || (uVar10 = uVar10 - 1, pcVar1 = pcVar6, uVar10 == 0))
    goto LAB_40143cd4;
  } while( true );
}



/* 40143cfc FUN_40143cfc */

/* Boundary evidence: original MIPS .pdata 40143cfc..40143f53. Semantic name remains unreviewed. */

void FUN_40143cfc(int *param_1)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  int *piVar7;
  uint _Size;
  uint uVar8;
  uint uVar9;
  
  _Size = param_1[9];
  do {
    uVar6 = param_1[0x19];
    uVar8 = (param_1[0xd] - uVar6) - param_1[0x1b];
    if (uVar8 == 0) {
      if ((uVar6 != 0) || (uVar9 = _Size, param_1[0x1b] != 0)) {
LAB_40143d74:
        uVar9 = uVar8;
        if ((_Size + param_1[9]) - 0x106 <= uVar6) {
          memcpy((void *)param_1[0xc],(void *)(param_1[0xc] + _Size),_Size);
          iVar1 = param_1[0x11];
          param_1[0x1a] = param_1[0x1a] - _Size;
          puVar2 = (ushort *)(param_1[0xf] + iVar1 * 2);
          param_1[0x19] = param_1[0x19] - _Size;
          param_1[0x15] = param_1[0x15] - _Size;
          do {
            puVar2 = puVar2 + -1;
            uVar5 = *puVar2 - (short)_Size;
            if (*puVar2 < _Size) {
              uVar5 = 0;
            }
            iVar1 = iVar1 + -1;
            *puVar2 = uVar5;
          } while (iVar1 != 0);
          puVar2 = (ushort *)(param_1[0xe] + _Size * 2);
          uVar6 = _Size;
          do {
            puVar2 = puVar2 + -1;
            uVar5 = *puVar2 - (short)_Size;
            if (*puVar2 < _Size) {
              uVar5 = 0;
            }
            uVar6 = uVar6 - 1;
            *puVar2 = uVar5;
          } while (uVar6 != 0);
          uVar9 = uVar8 + _Size;
        }
      }
    }
    else {
      if (uVar8 != 0xffffffff) goto LAB_40143d74;
      uVar9 = 0xfffffffe;
    }
    piVar7 = (int *)*param_1;
    uVar6 = piVar7[1];
    if (uVar6 == 0) {
      return;
    }
    iVar3 = param_1[0x1b];
    iVar1 = param_1[0xc];
    iVar4 = param_1[0x19];
    uVar8 = uVar6;
    if (uVar9 < uVar6) {
      uVar8 = uVar9;
    }
    if (uVar8 == 0) {
      uVar8 = 0;
    }
    else {
      piVar7[1] = uVar6 - uVar8;
      if (*(int *)(piVar7[7] + 0x18) == 0) {
        uVar6 = adler32(piVar7[0xc],(byte *)*piVar7,uVar8);
        piVar7[0xc] = uVar6;
      }
      memcpy((void *)(iVar3 + iVar1 + iVar4),(void *)*piVar7,uVar8);
      *piVar7 = *piVar7 + uVar8;
      piVar7[2] = piVar7[2] + uVar8;
    }
    uVar8 = param_1[0x1b] + uVar8;
    param_1[0x1b] = uVar8;
    if (2 < uVar8) {
      uVar6 = (uint)*(byte *)(param_1[0xc] + param_1[0x19]);
      param_1[0x10] = uVar6;
      param_1[0x10] =
           (uVar6 << (param_1[0x14] & 0x1fU) ^ (uint)((byte *)(param_1[0xc] + param_1[0x19]))[1]) &
           param_1[0x13];
    }
    if (0x105 < uVar8) {
      return;
    }
    if (*(int *)(*param_1 + 4) == 0) {
      return;
    }
  } while( true );
}



/* 40143f54 FUN_40143f54 */

/* Boundary evidence: original MIPS .pdata 40143f54..4014413b. Semantic name remains unreviewed. */

undefined4 FUN_40143f54(int *param_1,int param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0xffff;
  if (param_1[3] - 5U < 0xffff) {
    uVar5 = param_1[3] - 5U;
  }
  do {
    uVar2 = param_1[0x1b];
    if (uVar2 < 2) {
      FUN_40143cfc(param_1);
      uVar2 = param_1[0x1b];
      if (uVar2 == 0) {
        if (param_2 == 0) {
          return 0;
        }
        iVar4 = param_1[0x15];
        if (iVar4 < 0) {
          puVar1 = (undefined1 *)0x0;
        }
        else {
          puVar1 = (undefined1 *)(param_1[0xc] + iVar4);
        }
        FUN_40147860((int)param_1,puVar1,param_1[0x19] - iVar4,(uint)(param_2 == 4));
        param_1[0x15] = param_1[0x19];
        FUN_401434f8(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          if (param_2 != 4) {
            return 0;
          }
          return 2;
        }
        if (param_2 == 4) {
          return 3;
        }
        return 1;
      }
    }
    iVar4 = param_1[0x15];
    uVar2 = param_1[0x19] + uVar2;
    uVar3 = iVar4 + uVar5;
    param_1[0x19] = uVar2;
    param_1[0x1b] = 0;
    if ((uVar2 == 0) || (uVar3 <= uVar2)) {
      param_1[0x1b] = uVar2 - uVar3;
      param_1[0x19] = uVar3;
      if (iVar4 < 0) {
        puVar1 = (undefined1 *)0x0;
      }
      else {
        puVar1 = (undefined1 *)(param_1[0xc] + iVar4);
      }
      FUN_40147860((int)param_1,puVar1,uVar3 - iVar4,0);
      param_1[0x15] = param_1[0x19];
      FUN_401434f8(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
    iVar4 = param_1[0x15];
    if (param_1[9] - 0x106U <= (uint)(param_1[0x19] - iVar4)) {
      if (iVar4 < 0) {
        puVar1 = (undefined1 *)0x0;
      }
      else {
        puVar1 = (undefined1 *)(param_1[0xc] + iVar4);
      }
      FUN_40147860((int)param_1,puVar1,param_1[0x19] - iVar4,0);
      param_1[0x15] = param_1[0x19];
      FUN_401434f8(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
  } while( true );
}



/* 4014413c FUN_4014413c */

/* Boundary evidence: original MIPS .pdata 4014413c..401445f3. Semantic name remains unreviewed. */

undefined4 FUN_4014413c(int *param_1,int param_2)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  
  uVar10 = 0;
  do {
    uVar6 = param_1[0x1b];
    if (uVar6 < 0x106) {
      FUN_40143cfc(param_1);
      uVar6 = param_1[0x1b];
      if ((uVar6 < 0x106) && (param_2 == 0)) {
        return 0;
      }
      if (uVar6 == 0) {
        iVar7 = param_1[0x15];
        if (iVar7 < 0) {
          puVar5 = (undefined1 *)0x0;
        }
        else {
          puVar5 = (undefined1 *)(param_1[0xc] + iVar7);
        }
        FUN_40147860((int)param_1,puVar5,param_1[0x19] - iVar7,(uint)(param_2 == 4));
        param_1[0x15] = param_1[0x19];
        FUN_401434f8(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          if (param_2 != 4) {
            return 0;
          }
          return 2;
        }
        if (param_2 != 4) {
          return 1;
        }
        return 3;
      }
    }
    if (2 < uVar6) {
      uVar10 = (param_1[0x10] << (param_1[0x14] & 0x1fU) ^
               (uint)*(byte *)(param_1[0xc] + param_1[0x19] + 2)) & param_1[0x13];
      param_1[0x10] = uVar10;
      uVar3 = *(ushort *)(uVar10 * 2 + param_1[0xf]);
      uVar10 = (uint)uVar3;
      *(ushort *)((param_1[0xb] & param_1[0x19]) * 2 + param_1[0xe]) = uVar3;
      *(short *)(param_1[0x10] * 2 + param_1[0xf]) = (short)param_1[0x19];
    }
    if (((uVar10 != 0) && (param_1[0x19] - uVar10 <= param_1[9] - 0x106U)) && (param_1[0x20] != 2))
    {
      pcVar4 = FUN_40143ad8((int)param_1,uVar10);
      param_1[0x16] = (int)pcVar4;
    }
    if ((uint)param_1[0x16] < 3) {
      bVar2 = *(byte *)(param_1[0xc] + param_1[0x19]);
      *(undefined2 *)(param_1[0x5a7] + param_1[0x5a6] * 2) = 0;
      *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar2;
      param_1[0x5a6] = param_1[0x5a6] + 1;
      *(short *)(param_1 + bVar2 + 0x23) = (short)param_1[bVar2 + 0x23] + 1;
      bVar1 = param_1[0x5a6] == param_1[0x5a5] + -1;
      param_1[0x1b] = param_1[0x1b] + -1;
      param_1[0x19] = param_1[0x19] + 1;
    }
    else {
      uVar6 = param_1[0x16] + 0xfd;
      iVar7 = param_1[0x1a];
      iVar8 = param_1[0x19];
      *(short *)(param_1[0x5a7] + param_1[0x5a6] * 2) = (short)(iVar8 - iVar7);
      *(char *)(param_1[0x5a4] + param_1[0x5a6]) = (char)uVar6;
      param_1[0x5a6] = param_1[0x5a6] + 1;
      uVar11 = (iVar8 - iVar7) + 0xffffU & 0xffff;
      *(short *)(param_1 + (byte)(&DAT_401419bc)[uVar6 & 0xff] + 0x124) =
           (short)param_1[(byte)(&DAT_401419bc)[uVar6 & 0xff] + 0x124] + 1;
      if (uVar11 < 0x100) {
        bVar2 = (&DAT_401417bc)[uVar11];
      }
      else {
        bVar2 = (&DAT_401418bc)[uVar11 >> 7];
      }
      *(short *)(param_1 + bVar2 + 0x260) = (short)param_1[bVar2 + 0x260] + 1;
      bVar1 = param_1[0x5a6] == param_1[0x5a5] + -1;
      uVar6 = param_1[0x16];
      iVar7 = param_1[0x1b];
      param_1[0x1b] = iVar7 - uVar6;
      if (((uint)param_1[0x1e] < uVar6) || (iVar7 - uVar6 < 3)) {
        pbVar9 = (byte *)(param_1[0xc] + uVar6 + param_1[0x19]);
        param_1[0x19] = uVar6 + param_1[0x19];
        param_1[0x16] = 0;
        uVar6 = (uint)*pbVar9;
        param_1[0x10] = uVar6;
        param_1[0x10] = (uVar6 << (param_1[0x14] & 0x1fU) ^ (uint)pbVar9[1]) & param_1[0x13];
      }
      else {
        param_1[0x16] = uVar6 - 1;
        do {
          uVar6 = param_1[0x19] + 1;
          param_1[0x19] = uVar6;
          uVar10 = ((uint)*(byte *)(uVar6 + param_1[0xc] + 2) ^
                   param_1[0x10] << (param_1[0x14] & 0x1fU)) & param_1[0x13];
          param_1[0x10] = uVar10;
          uVar3 = *(ushort *)(uVar10 * 2 + param_1[0xf]);
          uVar10 = (uint)uVar3;
          *(ushort *)((uVar6 & param_1[0xb]) * 2 + param_1[0xe]) = uVar3;
          *(short *)(param_1[0x10] * 2 + param_1[0xf]) = (short)param_1[0x19];
          iVar7 = param_1[0x16];
          param_1[0x16] = iVar7 + -1;
        } while (iVar7 + -1 != 0);
        param_1[0x19] = param_1[0x19] + 1;
      }
    }
    if (bVar1) {
      iVar7 = param_1[0x15];
      if (iVar7 < 0) {
        puVar5 = (undefined1 *)0x0;
      }
      else {
        puVar5 = (undefined1 *)(iVar7 + param_1[0xc]);
      }
      FUN_40147860((int)param_1,puVar5,param_1[0x19] - iVar7,0);
      param_1[0x15] = param_1[0x19];
      FUN_401434f8(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
  } while( true );
}



/* 401445f4 FUN_401445f4 */

/* Boundary evidence: original MIPS .pdata 401445f4..40144bd7. Semantic name remains unreviewed. */

undefined4 FUN_401445f4(int *param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  uVar11 = 0;
  do {
    uVar7 = param_1[0x1b];
    if (uVar7 < 0x106) {
      FUN_40143cfc(param_1);
      uVar7 = param_1[0x1b];
      if ((uVar7 < 0x106) && (param_2 == 0)) {
        return 0;
      }
      if (uVar7 == 0) {
        if (param_1[0x18] != 0) {
          bVar1 = *(byte *)(param_1[0x19] + param_1[0xc] + -1);
          *(undefined2 *)(param_1[0x5a6] * 2 + param_1[0x5a7]) = 0;
          *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar1;
          param_1[0x5a6] = param_1[0x5a6] + 1;
          *(short *)(param_1 + bVar1 + 0x23) = (short)param_1[bVar1 + 0x23] + 1;
          param_1[0x18] = 0;
        }
        iVar5 = param_1[0x15];
        if (iVar5 < 0) {
          puVar4 = (undefined1 *)0x0;
        }
        else {
          puVar4 = (undefined1 *)(param_1[0xc] + iVar5);
        }
        FUN_40147860((int)param_1,puVar4,param_1[0x19] - iVar5,(uint)(param_2 == 4));
        param_1[0x15] = param_1[0x19];
        FUN_401434f8(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          if (param_2 != 4) {
            return 0;
          }
          return 2;
        }
        if (param_2 != 4) {
          return 1;
        }
        return 3;
      }
    }
    if (2 < uVar7) {
      uVar11 = (param_1[0x10] << (param_1[0x14] & 0x1fU) ^
               (uint)*(byte *)(param_1[0xc] + param_1[0x19] + 2)) & param_1[0x13];
      param_1[0x10] = uVar11;
      uVar2 = *(ushort *)(uVar11 * 2 + param_1[0xf]);
      uVar11 = (uint)uVar2;
      *(ushort *)((param_1[0xb] & param_1[0x19]) * 2 + param_1[0xe]) = uVar2;
      *(short *)(param_1[0x10] * 2 + param_1[0xf]) = (short)param_1[0x19];
    }
    uVar7 = param_1[0x16];
    param_1[0x1c] = uVar7;
    param_1[0x17] = param_1[0x1a];
    param_1[0x16] = 2;
    if (((uVar11 != 0) && (uVar7 < (uint)param_1[0x1e])) &&
       (param_1[0x19] - uVar11 <= param_1[9] - 0x106U)) {
      if (param_1[0x20] != 2) {
        pcVar3 = FUN_40143ad8((int)param_1,uVar11);
        param_1[0x16] = (int)pcVar3;
      }
      if (((uint)param_1[0x16] < 6) &&
         ((param_1[0x20] == 1 ||
          ((param_1[0x16] == 3 && (0x1000 < (uint)(param_1[0x19] - param_1[0x1a]))))))) {
        param_1[0x16] = 2;
      }
    }
    uVar7 = param_1[0x1c];
    if ((uVar7 < 3) || (uVar7 < (uint)param_1[0x16])) {
      if (param_1[0x18] == 0) {
        param_1[0x18] = 1;
        param_1[0x19] = param_1[0x19] + 1;
        param_1[0x1b] = param_1[0x1b] + -1;
      }
      else {
        bVar1 = *(byte *)(param_1[0xc] + param_1[0x19] + -1);
        *(undefined2 *)(param_1[0x5a6] * 2 + param_1[0x5a7]) = 0;
        *(byte *)(param_1[0x5a4] + param_1[0x5a6]) = bVar1;
        param_1[0x5a6] = param_1[0x5a6] + 1;
        *(short *)(param_1 + bVar1 + 0x23) = (short)param_1[bVar1 + 0x23] + 1;
        if (param_1[0x5a6] == param_1[0x5a5] + -1) {
          iVar5 = param_1[0x15];
          if (iVar5 < 0) {
            puVar4 = (undefined1 *)0x0;
          }
          else {
            puVar4 = (undefined1 *)(iVar5 + param_1[0xc]);
          }
          FUN_40147860((int)param_1,puVar4,param_1[0x19] - iVar5,0);
          param_1[0x15] = param_1[0x19];
          FUN_401434f8(*param_1);
        }
        param_1[0x19] = param_1[0x19] + 1;
        param_1[0x1b] = param_1[0x1b] + -1;
        if (*(int *)(*param_1 + 0x10) == 0) {
          return 0;
        }
      }
    }
    else {
      iVar9 = param_1[0x19];
      iVar5 = param_1[0x1b];
      iVar10 = iVar9 - param_1[0x17];
      *(short *)(param_1[0x5a6] * 2 + param_1[0x5a7]) = (short)iVar10 + -1;
      *(char *)(param_1[0x5a4] + param_1[0x5a6]) = (char)(uVar7 + 0xfd);
      param_1[0x5a6] = param_1[0x5a6] + 1;
      uVar12 = iVar10 + 0x1fffeU & 0xffff;
      *(short *)(param_1 + (byte)(&DAT_401419bc)[uVar7 + 0xfd & 0xff] + 0x124) =
           (short)param_1[(byte)(&DAT_401419bc)[uVar7 + 0xfd & 0xff] + 0x124] + 1;
      if (uVar12 < 0x100) {
        bVar1 = (&DAT_401417bc)[uVar12];
      }
      else {
        bVar1 = (&DAT_401418bc)[uVar12 >> 7];
      }
      *(short *)(param_1 + bVar1 + 0x260) = (short)param_1[bVar1 + 0x260] + 1;
      iVar10 = param_1[0x5a5];
      iVar8 = param_1[0x5a6];
      param_1[0x1b] = (param_1[0x1b] - param_1[0x1c]) + 1;
      param_1[0x1c] = param_1[0x1c] + -2;
      do {
        uVar7 = param_1[0x19] + 1;
        param_1[0x19] = uVar7;
        if (uVar7 <= (iVar9 + iVar5) - 3U) {
          uVar11 = (param_1[0x10] << (param_1[0x14] & 0x1fU) ^
                   (uint)*(byte *)(param_1[0xc] + uVar7 + 2)) & param_1[0x13];
          param_1[0x10] = uVar11;
          uVar2 = *(ushort *)(uVar11 * 2 + param_1[0xf]);
          uVar11 = (uint)uVar2;
          *(ushort *)((param_1[0xb] & uVar7) * 2 + param_1[0xe]) = uVar2;
          *(short *)(param_1[0x10] * 2 + param_1[0xf]) = (short)param_1[0x19];
        }
        iVar6 = param_1[0x1c];
        param_1[0x1c] = iVar6 + -1;
      } while (iVar6 + -1 != 0);
      iVar5 = param_1[0x19];
      param_1[0x18] = 0;
      param_1[0x16] = 2;
      param_1[0x19] = iVar5 + 1;
      if (iVar8 == iVar10 + -1) {
        iVar9 = param_1[0x15];
        if (iVar9 < 0) {
          puVar4 = (undefined1 *)0x0;
        }
        else {
          puVar4 = (undefined1 *)(param_1[0xc] + iVar9);
        }
        FUN_40147860((int)param_1,puVar4,(iVar5 + 1) - iVar9,0);
        param_1[0x15] = param_1[0x19];
        FUN_401434f8(*param_1);
        if (*(int *)(*param_1 + 0x10) == 0) {
          return 0;
        }
      }
    }
  } while( true );
}



/* 40144bd8 deflateReset */

/* Boundary evidence: original MIPS .pdata 40144bd8..40144d2f. Semantic name remains unreviewed. */

undefined4 deflateReset(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
                    /* 0x4bd8  7  deflateReset */
  if ((((param_1 == 0) || (iVar3 = *(int *)(param_1 + 0x1c), iVar3 == 0)) ||
      (*(int *)(param_1 + 0x20) == 0)) || (*(int *)(param_1 + 0x24) == 0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 2;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar3 + 8);
    if (*(int *)(iVar3 + 0x18) < 0) {
      *(undefined4 *)(iVar3 + 0x18) = 0;
    }
    uVar2 = 0x71;
    if (*(int *)(iVar3 + 0x18) == 0) {
      uVar2 = 0x2a;
    }
    *(undefined4 *)(iVar3 + 4) = uVar2;
    *(undefined4 *)(param_1 + 0x30) = 1;
    *(undefined4 *)(iVar3 + 0x20) = 0;
    FUN_40147124(iVar3);
    *(int *)(iVar3 + 0x34) = *(int *)(iVar3 + 0x24) << 1;
    *(undefined2 *)(*(int *)(iVar3 + 0x44) * 2 + *(int *)(iVar3 + 0x3c) + -2) = 0;
    memset(*(void **)(iVar3 + 0x3c),0,(*(int *)(iVar3 + 0x44) + -1) * 2);
    iVar1 = *(int *)(iVar3 + 0x7c) * 0xc;
    uVar2 = 0;
    *(uint *)(iVar3 + 0x78) = (uint)*(ushort *)(&DAT_4014108e + iVar1);
    *(uint *)(iVar3 + 0x84) = (uint)*(ushort *)(&DAT_4014108c + iVar1);
    *(uint *)(iVar3 + 0x88) = (uint)*(ushort *)(&DAT_40141090 + iVar1);
    *(uint *)(iVar3 + 0x74) = (uint)*(ushort *)(&DAT_40141092 + iVar1);
    *(undefined4 *)(iVar3 + 100) = 0;
    *(undefined4 *)(iVar3 + 0x54) = 0;
    *(undefined4 *)(iVar3 + 0x6c) = 0;
    *(undefined4 *)(iVar3 + 0x70) = 2;
    *(undefined4 *)(iVar3 + 0x58) = 2;
    *(undefined4 *)(iVar3 + 0x60) = 0;
    *(undefined4 *)(iVar3 + 0x40) = 0;
  }
  return uVar2;
}



/* 40144d30 deflateInit2_ */

/* Boundary evidence: original MIPS .pdata 40144d30..40144fff. Semantic name remains unreviewed. */

undefined4
deflateInit2_(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6,char *param_7
             ,int param_8)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
                    /* 0x4d30  5  deflateInit2_ */
  if (((param_7 == (char *)0x0) || (*param_7 != *PTR_s_1_1_4_4014b034)) || (param_8 != 0x38)) {
    uVar2 = 0xfffffffa;
  }
  else {
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (*(int *)(param_1 + 0x20) == 0) {
        *(code **)(param_1 + 0x20) = FUN_40145ba0;
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(code **)(param_1 + 0x24) = FUN_40145bc0;
      }
      if (param_2 == -1) {
        param_2 = 6;
      }
      bVar1 = (int)param_4 < 0;
      if (bVar1) {
        param_4 = -param_4;
      }
      if (((((0 < param_5) && (param_5 < 10)) &&
           ((param_3 == 8 && ((8 < (int)param_4 && ((int)param_4 < 0x10)))))) && (-1 < param_2)) &&
         (((param_2 < 10 && (-1 < param_6)) && (param_6 < 3)))) {
        piVar3 = (int *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x16b8);
        if (piVar3 != (int *)0x0) {
          iVar4 = 1 << (param_4 & 0x1f);
          piVar3[1] = 0x2a;
          *(int **)(param_1 + 0x1c) = piVar3;
          piVar3[0xb] = iVar4 + -1;
          piVar3[10] = param_4;
          iVar5 = 1 << (param_5 + 7U & 0x1f);
          piVar3[0x11] = iVar5;
          *piVar3 = param_1;
          piVar3[6] = (uint)bVar1;
          piVar3[9] = iVar4;
          piVar3[0x12] = param_5 + 7U;
          piVar3[0x13] = iVar5 + -1;
          piVar3[0x14] = (param_5 + 9U) / 3;
          iVar4 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),iVar4,2);
          piVar3[0xc] = iVar4;
          iVar4 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar3[9],2);
          piVar3[0xe] = iVar4;
          iVar4 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar3[0x11],2);
          iVar5 = 1 << (param_5 + 6U & 0x1f);
          piVar3[0xf] = iVar4;
          piVar3[0x5a5] = iVar5;
          iVar4 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),iVar5,4);
          uVar6 = piVar3[0x5a5];
          piVar3[2] = iVar4;
          piVar3[3] = uVar6 << 2;
          if (((piVar3[0xc] != 0) && (piVar3[0xe] != 0)) && ((piVar3[0xf] != 0 && (iVar4 != 0)))) {
            piVar3[0x5a7] = (uVar6 & 0xfffffffe) + iVar4;
            piVar3[0x1f] = param_2;
            piVar3[0x20] = param_6;
            *(undefined1 *)((int)piVar3 + 0x1d) = 8;
            piVar3[0x5a4] = uVar6 * 3 + iVar4;
            uVar2 = deflateReset(param_1);
            return uVar2;
          }
          deflateEnd(param_1);
        }
        return 0xfffffffc;
      }
    }
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}



/* 40145000 deflateInit_ */

/* Boundary evidence: original MIPS .pdata 40145000..40145033. Semantic name remains unreviewed. */

void deflateInit_(int param_1,int param_2,char *param_3,int param_4)

{
                    /* 0x5000  6  deflateInit_ */
  deflateInit2_(param_1,param_2,8,0xf,8,0,param_3,param_4);
  return;
}



/* 40145034 inflateReset */

/* Boundary evidence: original MIPS .pdata 40145034..4014509b. Semantic name remains unreviewed. */

undefined4 inflateReset(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
                    /* 0x5034  13  inflateReset */
  if ((param_1 == 0) || (puVar1 = *(undefined4 **)(param_1 + 0x1c), puVar1 == (undefined4 *)0x0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    uVar2 = 7;
    if (puVar1[3] == 0) {
      uVar2 = 0;
    }
    *puVar1 = uVar2;
    FUN_40147ca0(*(int **)(*(int *)(param_1 + 0x1c) + 0x14),param_1,(int *)0x0);
    uVar2 = 0;
  }
  return uVar2;
}



/* 4014509c inflateEnd */

/* Boundary evidence: original MIPS .pdata 4014509c..4014510f. Semantic name remains unreviewed. */

undefined4 inflateEnd(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
                    /* 0x509c  10  inflateEnd */
  if (((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) || (*(int *)(param_1 + 0x24) == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    piVar2 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14);
    if (piVar2 != (int *)0x0) {
      FUN_40148884(piVar2,param_1);
    }
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x1c));
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return uVar1;
}



/* 40145110 inflateInit2_ */

/* Boundary evidence: original MIPS .pdata 40145110..40145283. Semantic name remains unreviewed. */

undefined4 inflateInit2_(int param_1,uint param_2,char *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 uVar4;
  
                    /* 0x5110  11  inflateInit2_ */
  if (((param_3 == (char *)0x0) || (*param_3 != '1')) || (param_4 != 0x38)) {
    uVar4 = 0xfffffffa;
  }
  else if (param_1 == 0) {
    uVar4 = 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(int *)(param_1 + 0x20) == 0) {
      *(code **)(param_1 + 0x20) = FUN_40145ba0;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(code **)(param_1 + 0x24) = FUN_40145bc0;
    }
    iVar1 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x18);
    *(int *)(param_1 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      uVar4 = 0xfffffffc;
    }
    else {
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 0;
      if ((int)param_2 < 0) {
        param_2 = -param_2;
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 1;
      }
      if (((int)param_2 < 8) || (0xf < (int)param_2)) {
        uVar4 = 0xfffffffe;
      }
      else {
        *(uint *)(*(int *)(param_1 + 0x1c) + 0x10) = param_2;
        if (*(int *)(*(int *)(param_1 + 0x1c) + 0xc) == 0) {
          pcVar3 = adler32;
        }
        else {
          pcVar3 = (code *)0x0;
        }
        piVar2 = FUN_40147d58(param_1,(int)pcVar3,1 << (param_2 & 0x1f));
        *(int **)(*(int *)(param_1 + 0x1c) + 0x14) = piVar2;
        if (*(int *)(*(int *)(param_1 + 0x1c) + 0x14) != 0) {
          inflateReset(param_1);
          return 0;
        }
        uVar4 = 0xfffffffc;
      }
      inflateEnd(param_1);
    }
  }
  return uVar4;
}



/* 40145284 inflateInit_ */

/* Boundary evidence: original MIPS .pdata 40145284..401452a7. Semantic name remains unreviewed. */

void inflateInit_(int param_1,char *param_2,int param_3)

{
                    /* 0x5284  12  inflateInit_ */
  inflateInit2_(param_1,0xf,param_2,param_3);
  return;
}



/* 401452a8 inflate */

/* Boundary evidence: original MIPS .pdata 401452a8..40145887. Semantic name remains unreviewed. */

uint inflate(int *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
                    /* 0x52a8  9  inflate */
  if (((param_1 == (int *)0x0) || ((uint *)param_1[7] == (uint *)0x0)) || (*param_1 == 0)) {
    return 0xfffffffe;
  }
  uVar4 = 0xfffffffb;
  uVar5 = 0xfffffffb;
  if (param_2 != 4) {
    uVar5 = 0;
  }
  uVar2 = *(uint *)param_1[7];
joined_r0x40145314:
  if (0xd < uVar2) {
    return 0xfffffffe;
  }
  switch(uVar2) {
  case 0:
    if (param_1[1] == 0) {
      return uVar4;
    }
    param_1[2] = param_1[2] + 1;
    param_1[1] = param_1[1] + -1;
    *(uint *)(param_1[7] + 4) = (uint)*(byte *)*param_1;
    puVar3 = (undefined4 *)param_1[7];
    uVar4 = puVar3[1];
    *param_1 = *param_1 + 1;
    if ((uVar4 & 0xf) == 8) {
      if (((uint)puVar3[1] >> 4) + 8 <= (uint)puVar3[4]) {
        *puVar3 = 1;
        uVar4 = uVar5;
        goto switchD_4014536c_caseD_1;
      }
      *puVar3 = 0xd;
      param_1[6] = (int)"invalid window size";
      goto LAB_40145694;
    }
    *puVar3 = 0xd;
    param_1[6] = (int)"unknown compression method";
    *(undefined4 *)(param_1[7] + 4) = 5;
    uVar4 = uVar5;
    break;
  case 1:
switchD_4014536c_caseD_1:
    if (param_1[1] == 0) {
      return uVar4;
    }
    param_1[1] = param_1[1] + -1;
    param_1[2] = param_1[2] + 1;
    puVar3 = (undefined4 *)param_1[7];
    bVar1 = *(byte *)*param_1;
    *param_1 = (int)((byte *)*param_1 + 1);
    if ((puVar3[1] * 0x100 + (uint)bVar1) % 0x1f == 0) {
      if ((bVar1 & 0x20) != 0) {
        *(undefined4 *)param_1[7] = 2;
        uVar4 = uVar5;
        goto switchD_4014536c_caseD_2;
      }
      *puVar3 = 7;
      uVar4 = uVar5;
      break;
    }
    *puVar3 = 0xd;
    param_1[6] = (int)"incorrect header check";
    goto LAB_40145694;
  case 2:
switchD_4014536c_caseD_2:
    if (param_1[1] == 0) {
      return uVar4;
    }
    param_1[1] = param_1[1] + -1;
    param_1[2] = param_1[2] + 1;
    *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 << 0x18;
    *param_1 = *param_1 + 1;
    *(undefined4 *)param_1[7] = 3;
    uVar4 = uVar5;
  case 3:
    if (param_1[1] == 0) {
      return uVar4;
    }
    param_1[1] = param_1[1] + -1;
    param_1[2] = param_1[2] + 1;
    *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 * 0x10000 + *(int *)(param_1[7] + 8);
    *param_1 = *param_1 + 1;
    *(undefined4 *)param_1[7] = 4;
    uVar4 = uVar5;
  case 4:
    goto switchD_4014536c_caseD_4;
  case 5:
    goto switchD_4014536c_caseD_5;
  case 6:
    *(undefined4 *)param_1[7] = 0xd;
    param_1[6] = (int)"need dictionary";
    *(undefined4 *)(param_1[7] + 4) = 0;
    return 0xfffffffe;
  case 7:
    uVar4 = FUN_40147e48(*(uint **)(param_1[7] + 0x14),param_1,uVar4);
    if (uVar4 == 0xfffffffd) {
      *(undefined4 *)param_1[7] = 0xd;
      *(undefined4 *)(param_1[7] + 4) = 0;
      uVar4 = 0xfffffffd;
    }
    else {
      if (uVar4 == 0) {
        uVar4 = uVar5;
      }
      if (uVar4 != 1) {
        return uVar4;
      }
      FUN_40147ca0(*(int **)(param_1[7] + 0x14),(int)param_1,(int *)(param_1[7] + 4));
      puVar3 = (undefined4 *)param_1[7];
      if (puVar3[3] == 0) {
        *puVar3 = 8;
        uVar4 = uVar5;
        goto switchD_4014536c_caseD_8;
      }
      *puVar3 = 0xc;
      uVar4 = uVar5;
    }
    break;
  case 8:
switchD_4014536c_caseD_8:
    if (param_1[1] == 0) {
      return uVar4;
    }
    param_1[1] = param_1[1] + -1;
    param_1[2] = param_1[2] + 1;
    *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 << 0x18;
    *param_1 = *param_1 + 1;
    *(undefined4 *)param_1[7] = 9;
    uVar4 = uVar5;
  case 9:
    if (param_1[1] == 0) {
      return uVar4;
    }
    param_1[1] = param_1[1] + -1;
    param_1[2] = param_1[2] + 1;
    *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 * 0x10000 + *(int *)(param_1[7] + 8);
    *param_1 = *param_1 + 1;
    *(undefined4 *)param_1[7] = 10;
    uVar4 = uVar5;
  case 10:
    goto switchD_4014536c_caseD_a;
  case 0xb:
    goto switchD_4014536c_caseD_b;
  case 0xc:
    goto LAB_401456b4;
  case 0xd:
    return 0xfffffffd;
  }
LAB_4014569c:
  uVar2 = *(uint *)param_1[7];
  goto joined_r0x40145314;
switchD_4014536c_caseD_a:
  if (param_1[1] == 0) {
    return uVar4;
  }
  param_1[1] = param_1[1] + -1;
  param_1[2] = param_1[2] + 1;
  *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 * 0x100 + *(int *)(param_1[7] + 8);
  *param_1 = *param_1 + 1;
  *(undefined4 *)param_1[7] = 0xb;
  uVar4 = uVar5;
switchD_4014536c_caseD_b:
  if (param_1[1] == 0) {
    return uVar4;
  }
  param_1[2] = param_1[2] + 1;
  param_1[1] = param_1[1] + -1;
  *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 + *(int *)(param_1[7] + 8);
  puVar3 = (undefined4 *)param_1[7];
  *param_1 = *param_1 + 1;
  if (puVar3[1] == puVar3[2]) {
    *(undefined4 *)param_1[7] = 0xc;
LAB_401456b4:
    return 1;
  }
  *puVar3 = 0xd;
  param_1[6] = (int)"incorrect data check";
LAB_40145694:
  *(undefined4 *)(param_1[7] + 4) = 5;
  uVar4 = uVar5;
  goto LAB_4014569c;
switchD_4014536c_caseD_4:
  if (param_1[1] == 0) {
    return uVar4;
  }
  param_1[2] = param_1[2] + 1;
  param_1[1] = param_1[1] + -1;
  *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 * 0x100 + *(int *)(param_1[7] + 8);
  *param_1 = *param_1 + 1;
  *(undefined4 *)param_1[7] = 5;
  uVar4 = uVar5;
switchD_4014536c_caseD_5:
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
    param_1[2] = param_1[2] + 1;
    *(uint *)(param_1[7] + 8) = (uint)*(byte *)*param_1 + *(int *)(param_1[7] + 8);
    *param_1 = *param_1 + 1;
    param_1[0xc] = ((undefined4 *)param_1[7])[2];
    *(undefined4 *)param_1[7] = 6;
    return 2;
  }
  return uVar4;
}



/* 40145888 inflateSetDictionary */

/* Boundary evidence: original MIPS .pdata 40145888..4014596b. Semantic name remains unreviewed. */

undefined4 inflateSetDictionary(int param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
                    /* 0x5888  14  inflateSetDictionary */
  if (((param_1 == 0) || (*(int **)(param_1 + 0x1c) == (int *)0x0)) ||
     (**(int **)(param_1 + 0x1c) != 6)) {
    uVar2 = 0xfffffffe;
  }
  else {
    uVar1 = adler32(1,param_2,param_3);
    if (uVar1 == *(uint *)(param_1 + 0x30)) {
      *(undefined4 *)(param_1 + 0x30) = 1;
      uVar3 = 1 << (*(uint *)(*(int *)(param_1 + 0x1c) + 0x10) & 0x1f);
      uVar1 = param_3;
      if (uVar3 <= param_3) {
        uVar1 = uVar3 - 1;
        param_2 = param_2 + (param_3 - uVar1);
      }
      FUN_401488f4(*(int *)(*(int *)(param_1 + 0x1c) + 0x14),param_2,uVar1);
      **(undefined4 **)(param_1 + 0x1c) = 7;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffffd;
    }
  }
  return uVar2;
}



/* 4014596c inflateSync */

/* Boundary evidence: original MIPS .pdata 4014596c..40145a9f. Semantic name remains unreviewed. */

undefined4 inflateSync(undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  char *pcVar7;
  
                    /* 0x596c  15  inflateSync */
  if ((param_1 == (undefined4 *)0x0) || (piVar2 = (int *)param_1[7], piVar2 == (int *)0x0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    if (*piVar2 != 0xd) {
      *piVar2 = 0xd;
      *(undefined4 *)(param_1[7] + 4) = 0;
    }
    iVar4 = param_1[1];
    if (iVar4 == 0) {
      uVar1 = 0xfffffffb;
    }
    else {
      pcVar7 = (char *)*param_1;
      uVar3 = *(uint *)(param_1[7] + 4);
      pcVar5 = pcVar7;
      do {
        if (3 < uVar3) break;
        if (*pcVar5 == (&DAT_40141104)[uVar3]) {
          uVar3 = uVar3 + 1;
        }
        else if (*pcVar5 == '\0') {
          uVar3 = 4 - uVar3;
        }
        else {
          uVar3 = 0;
        }
        iVar4 = iVar4 + -1;
        pcVar5 = pcVar5 + 1;
      } while (iVar4 != 0);
      *param_1 = pcVar5;
      param_1[2] = pcVar5 + (param_1[2] - (int)pcVar7);
      param_1[1] = iVar4;
      *(uint *)(param_1[7] + 4) = uVar3;
      if (uVar3 == 4) {
        uVar6 = param_1[2];
        uVar1 = param_1[5];
        inflateReset((int)param_1);
        param_1[2] = uVar6;
        param_1[5] = uVar1;
        uVar1 = 0;
        *(undefined4 *)param_1[7] = 7;
      }
      else {
        uVar1 = 0xfffffffd;
      }
    }
  }
  return uVar1;
}



/* 40145aa0 inflateSyncPoint */

/* Boundary evidence: original MIPS .pdata 40145aa0..40145ae7. Semantic name remains unreviewed. */

undefined1 inflateSyncPoint(int param_1)

{
  undefined1 uVar1;
  int *piVar2;
  
                    /* 0x5aa0  16  inflateSyncPoint */
  if (((param_1 == 0) || (*(int *)(param_1 + 0x1c) == 0)) ||
     (piVar2 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14), piVar2 == (int *)0x0)) {
    uVar1 = 0xfe;
  }
  else {
    uVar1 = FUN_4014893c(piVar2);
  }
  return uVar1;
}



/* 40145ae8 uncompress */

/* Boundary evidence: original MIPS .pdata 40145ae8..40145b93. Semantic name remains unreviewed. */

uint uncompress(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int local_48;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_28;
  undefined4 local_24;
  
                    /* 0x5ae8  17  uncompress */
  local_38 = *param_2;
  local_28 = 0;
  local_24 = 0;
  local_48 = param_3;
  local_44 = param_4;
  local_3c = param_1;
  uVar1 = inflateInit_((int)&local_48,"1.1.4",0x38);
  if (uVar1 == 0) {
    uVar1 = inflate(&local_48,4);
    if (uVar1 == 1) {
      *param_2 = local_34;
      uVar1 = inflateEnd((int)&local_48);
    }
    else {
      inflateEnd((int)&local_48);
      if (uVar1 == 0) {
        uVar1 = 0xfffffffb;
      }
    }
  }
  return uVar1;
}



/* 40145b94 zlibVersion */

char * zlibVersion(void)

{
                    /* 0x5b94  18  zlibVersion */
  return "1.1.4";
}



/* 40145ba0 FUN_40145ba0 */

/* Boundary evidence: original MIPS .pdata 40145ba0..40145bbf. Semantic name remains unreviewed. */

void FUN_40145ba0(undefined4 param_1,size_t param_2,size_t param_3)

{
  calloc(param_2,param_3);
  return;
}



/* 40145bc0 FUN_40145bc0 */

/* Boundary evidence: original MIPS .pdata 40145bc0..40145bdb. Semantic name remains unreviewed. */

void FUN_40145bc0(undefined4 param_1,void *param_2)

{
  free(param_2);
  return;
}



/* 40145bdc FUN_40145bdc */

void FUN_40145bdc(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = *(int *)(param_1 + 0x1448);
  iVar5 = param_3 << 1;
  iVar7 = *(int *)((param_3 + 0x2d5) * 4 + param_1);
  if (iVar5 <= iVar4) {
    do {
      iVar6 = iVar5;
      if (iVar5 < iVar4) {
        iVar3 = *(int *)((iVar5 + 0x2d6) * 4 + param_1);
        iVar4 = *(int *)((iVar5 + 0x2d5) * 4 + param_1);
        uVar1 = *(ushort *)(iVar3 * 4 + param_2);
        uVar2 = *(ushort *)(iVar4 * 4 + param_2);
        if ((uVar1 < uVar2) ||
           ((uVar1 == uVar2 &&
            (*(byte *)(iVar3 + param_1 + 0x1450) <= *(byte *)(iVar4 + param_1 + 0x1450))))) {
          iVar6 = iVar5 + 1;
        }
      }
      iVar4 = *(int *)((iVar6 + 0x2d5) * 4 + param_1);
      uVar1 = *(ushort *)(iVar7 * 4 + param_2);
      uVar2 = *(ushort *)(iVar4 * 4 + param_2);
      if ((uVar1 < uVar2) ||
         ((uVar1 == uVar2 &&
          (*(byte *)(iVar7 + param_1 + 0x1450) <= *(byte *)(iVar4 + param_1 + 0x1450))))) break;
      *(int *)((param_3 + 0x2d5) * 4 + param_1) = iVar4;
      iVar4 = *(int *)(param_1 + 0x1448);
      iVar5 = iVar6 << 1;
      param_3 = iVar6;
    } while (iVar5 <= iVar4);
  }
  *(int *)((param_3 + 0x2d5) * 4 + param_1) = iVar7;
  return;
}



/* 40145d18 FUN_40145d18 */

/* Boundary evidence: original MIPS .pdata 40145d18..40145fb3. Semantic name remains unreviewed. */

void FUN_40145d18(int param_1,int *param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int *piVar6;
  undefined2 *puVar7;
  short *psVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  ushort *puVar19;
  
  piVar6 = (int *)param_2[2];
  puVar7 = (undefined2 *)(param_1 + 0xb34);
  iVar14 = *param_2;
  iVar15 = param_2[1];
  iVar12 = *piVar6;
  iVar13 = piVar6[1];
  iVar11 = piVar6[2];
  uVar16 = piVar6[4];
  iVar4 = 0;
  do {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  } while (puVar7 != (undefined2 *)(param_1 + 0xb54));
  *(undefined2 *)(*(int *)((*(int *)(param_1 + 0x144c) + 0x2d5) * 4 + param_1) * 4 + iVar14 + 2) = 0
  ;
  iVar17 = *(int *)(param_1 + 0x144c) + 1;
  if (iVar17 < 0x23d) {
    iVar9 = 0x23d - iVar17;
    piVar6 = (int *)((*(int *)(param_1 + 0x144c) + 0x2d6) * 4 + param_1);
    iVar17 = iVar9 + iVar17;
    do {
      iVar3 = *piVar6;
      puVar5 = (ushort *)(iVar3 * 4 + iVar14);
      uVar10 = *(ushort *)((uint)puVar5[1] * 4 + iVar14 + 2) + 1;
      if ((int)uVar16 < (int)uVar10) {
        iVar4 = iVar4 + 1;
        uVar10 = uVar16;
      }
      puVar5[1] = (ushort)uVar10;
      if (iVar3 <= iVar15) {
        psVar8 = (short *)((uVar10 + 0x59a) * 2 + param_1);
        *psVar8 = *psVar8 + 1;
        iVar18 = 0;
        if (iVar11 <= iVar3) {
          iVar18 = *(int *)((iVar3 - iVar11) * 4 + iVar13);
        }
        uVar1 = *puVar5;
        *(uint *)(param_1 + 0x16a0) = (iVar18 + uVar10) * (uint)uVar1 + *(int *)(param_1 + 0x16a0);
        if (iVar12 != 0) {
          *(uint *)(param_1 + 0x16a4) =
               ((uint)*(ushort *)(iVar3 * 4 + iVar12 + 2) + iVar18) * (uint)uVar1 +
               *(int *)(param_1 + 0x16a4);
        }
      }
      iVar9 = iVar9 + -1;
      piVar6 = piVar6 + 1;
    } while (iVar9 != 0);
    if (iVar4 != 0) {
      puVar5 = (ushort *)((uVar16 + 0x59a) * 2 + param_1);
      do {
        psVar8 = (short *)((uVar16 + 0x599) * 2 + param_1);
        sVar2 = *psVar8;
        uVar10 = uVar16;
        while (sVar2 == 0) {
          psVar8 = psVar8 + -1;
          uVar10 = uVar10 - 1;
          sVar2 = *psVar8;
        }
        psVar8 = (short *)((uVar10 + 0x599) * 2 + param_1);
        *psVar8 = *psVar8 + -1;
        psVar8 = (short *)((uVar10 + 0x59a) * 2 + param_1);
        *psVar8 = *psVar8 + 2;
        iVar4 = iVar4 + -2;
        *puVar5 = *puVar5 - 1;
      } while (0 < iVar4);
      for (; uVar16 != 0; uVar16 = uVar16 - 1) {
        uVar10 = (uint)*puVar5;
        if (uVar10 != 0) {
          piVar6 = (int *)((iVar17 + 0x2d5) * 4 + param_1);
          do {
            piVar6 = piVar6 + -1;
            iVar17 = iVar17 + -1;
            if (*piVar6 <= iVar15) {
              puVar19 = (ushort *)(*piVar6 * 4 + iVar14);
              if (puVar19[1] != uVar16) {
                *(uint *)(param_1 + 0x16a0) =
                     (uVar16 - puVar19[1]) * (uint)*puVar19 + *(int *)(param_1 + 0x16a0);
                puVar19[1] = (ushort)uVar16;
              }
              uVar10 = uVar10 - 1;
            }
          } while (uVar10 != 0);
        }
        puVar5 = puVar5 + -1;
      }
    }
  }
  return;
}



/* 40145fb4 FUN_40145fb4 */

void FUN_40145fb4(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short *psVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  
  uVar1 = *(ushort *)(param_2 + 2);
  uVar6 = 0xffffffff;
  iVar5 = 0;
  iVar4 = 7;
  iVar3 = 4;
  if (uVar1 == 0) {
    iVar4 = 0x8a;
    iVar3 = 3;
  }
  *(undefined2 *)(param_3 * 4 + param_2 + 6) = 0xffff;
  if (-1 < param_3) {
    puVar9 = (ushort *)(param_2 + 6);
    iVar10 = param_3 + 1;
    uVar8 = (uint)uVar1;
    do {
      uVar2 = (uint)*puVar9;
      iVar5 = iVar5 + 1;
      if ((iVar4 <= iVar5) || (uVar8 != uVar2)) {
        if (iVar5 < iVar3) {
          psVar7 = (short *)((uVar8 + 0x29d) * 4 + param_1);
          *psVar7 = *psVar7 + (short)iVar5;
        }
        else if (uVar8 == 0) {
          if (iVar5 < 0xb) {
            *(short *)(param_1 + 0xab8) = *(short *)(param_1 + 0xab8) + 1;
          }
          else {
            *(short *)(param_1 + 0xabc) = *(short *)(param_1 + 0xabc) + 1;
          }
        }
        else {
          if (uVar8 != uVar6) {
            psVar7 = (short *)((uVar8 + 0x29d) * 4 + param_1);
            *psVar7 = *psVar7 + 1;
          }
          *(short *)(param_1 + 0xab4) = *(short *)(param_1 + 0xab4) + 1;
        }
        iVar5 = 0;
        uVar6 = uVar8;
        if (uVar2 == 0) {
          iVar4 = 0x8a;
        }
        else {
          if (uVar8 != uVar2) {
            iVar4 = 7;
            iVar3 = 4;
            goto LAB_401460cc;
          }
          iVar4 = 6;
        }
        iVar3 = 3;
      }
LAB_401460cc:
      iVar10 = iVar10 + -1;
      puVar9 = puVar9 + 2;
      uVar8 = uVar2;
    } while (iVar10 != 0);
  }
  return;
}



/* 401460e0 FUN_401460e0 */

/* Boundary evidence: original MIPS .pdata 401460e0..40146733. Semantic name remains unreviewed. */

void FUN_401460e0(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  uVar7 = 0xffffffff;
  iVar6 = 7;
  iVar5 = 4;
  if (*(ushort *)(param_2 + 2) == 0) {
    iVar6 = 0x8a;
    iVar5 = 3;
  }
  if (-1 < param_3) {
    puVar9 = (ushort *)(param_2 + 6);
    iVar10 = param_3 + 1;
    uVar2 = (uint)*(ushort *)(param_2 + 2);
    iVar11 = 0;
    do {
      uVar4 = (uint)*puVar9;
      iVar12 = iVar11 + 1;
      if ((iVar6 <= iVar12) || (uVar2 != uVar4)) {
        if (iVar12 < iVar5) {
          puVar3 = (ushort *)((uVar2 + 0x29d) * 4 + param_1);
          do {
            uVar7 = (uint)*(ushort *)(uVar2 * 4 + param_1 + 0xa76);
            uVar8 = *(uint *)(param_1 + 0x16b4);
            if ((int)(0x10 - uVar7) < (int)uVar8) {
              uVar1 = *puVar3;
              uVar8 = (uint)uVar1 << (uVar8 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
              *(short *)(param_1 + 0x16b0) = (short)uVar8;
              *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar8;
              iVar5 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar5;
              *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f);
              *(uint *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + uVar7 + -0x10;
            }
            else {
              *(ushort *)(param_1 + 0x16b0) =
                   *puVar3 << (uVar8 & 0x1f) | *(ushort *)(param_1 + 0x16b0);
              *(uint *)(param_1 + 0x16b4) = uVar8 + uVar7;
            }
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        else {
          if (uVar2 == 0) {
            uVar7 = *(uint *)(param_1 + 0x16b4);
            if (iVar12 < 0xb) {
              uVar8 = (uint)*(ushort *)(param_1 + 0xaba);
              if ((int)(0x10 - uVar8) < (int)uVar7) {
                uVar1 = *(ushort *)(param_1 + 0xab8);
                uVar7 = (uint)uVar1 << (uVar7 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
                *(short *)(param_1 + 0x16b0) = (short)uVar7;
                *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar7;
                iVar5 = *(int *)(param_1 + 0x14) + 1;
                *(int *)(param_1 + 0x14) = iVar5;
                *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
                *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
                uVar7 = (*(int *)(param_1 + 0x16b4) + uVar8) - 0x10;
                *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f)
                ;
              }
              else {
                *(ushort *)(param_1 + 0x16b0) =
                     *(short *)(param_1 + 0xab8) << (uVar7 & 0x1f) | *(ushort *)(param_1 + 0x16b0);
                uVar7 = uVar7 + uVar8;
              }
              *(uint *)(param_1 + 0x16b4) = uVar7;
              if ((int)uVar7 < 0xe) {
                *(ushort *)(param_1 + 0x16b0) =
                     (ushort)(iVar11 + 0xfffe << (uVar7 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
                iVar5 = uVar7 + 3;
              }
              else {
                uVar7 = iVar11 - 2U << (uVar7 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
                *(short *)(param_1 + 0x16b0) = (short)uVar7;
                *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar7;
                iVar5 = *(int *)(param_1 + 0x14) + 1;
                *(int *)(param_1 + 0x14) = iVar5;
                *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
                iVar5 = *(int *)(param_1 + 0x16b4) + -0xd;
                *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
                *(short *)(param_1 + 0x16b0) =
                     (short)((iVar11 - 2U & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
              }
            }
            else {
              uVar8 = (uint)*(ushort *)(param_1 + 0xabe);
              if ((int)(0x10 - uVar8) < (int)uVar7) {
                uVar1 = *(ushort *)(param_1 + 0xabc);
                uVar7 = (uint)uVar1 << (uVar7 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
                *(short *)(param_1 + 0x16b0) = (short)uVar7;
                *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar7;
                iVar5 = *(int *)(param_1 + 0x14) + 1;
                *(int *)(param_1 + 0x14) = iVar5;
                *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
                *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
                uVar7 = (*(int *)(param_1 + 0x16b4) + uVar8) - 0x10;
                *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f)
                ;
              }
              else {
                *(ushort *)(param_1 + 0x16b0) =
                     *(short *)(param_1 + 0xabc) << (uVar7 & 0x1f) | *(ushort *)(param_1 + 0x16b0);
                uVar7 = uVar7 + uVar8;
              }
              *(uint *)(param_1 + 0x16b4) = uVar7;
              if ((int)uVar7 < 10) {
                *(ushort *)(param_1 + 0x16b0) =
                     (ushort)(iVar11 + 0xfff6 << (uVar7 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
                iVar5 = uVar7 + 7;
              }
              else {
                uVar7 = iVar11 - 10U << (uVar7 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
                *(short *)(param_1 + 0x16b0) = (short)uVar7;
                *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar7;
                iVar5 = *(int *)(param_1 + 0x14) + 1;
                *(int *)(param_1 + 0x14) = iVar5;
                *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
                iVar5 = *(int *)(param_1 + 0x16b4) + -9;
                *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
                *(short *)(param_1 + 0x16b0) =
                     (short)((iVar11 - 10U & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f))
                ;
              }
            }
          }
          else {
            if (uVar2 != uVar7) {
              uVar7 = (uint)*(ushort *)(uVar2 * 4 + param_1 + 0xa76);
              uVar8 = *(uint *)(param_1 + 0x16b4);
              iVar12 = iVar11;
              if ((int)(0x10 - uVar7) < (int)uVar8) {
                uVar1 = *(ushort *)((uVar2 + 0x29d) * 4 + param_1);
                uVar8 = (uint)uVar1 << (uVar8 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
                *(short *)(param_1 + 0x16b0) = (short)uVar8;
                *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar8;
                iVar5 = *(int *)(param_1 + 0x14) + 1;
                *(int *)(param_1 + 0x14) = iVar5;
                *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
                *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
                *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f)
                ;
                *(uint *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + uVar7 + -0x10;
              }
              else {
                *(ushort *)(param_1 + 0x16b0) =
                     *(short *)((uVar2 + 0x29d) * 4 + param_1) << (uVar8 & 0x1f) |
                     *(ushort *)(param_1 + 0x16b0);
                *(uint *)(param_1 + 0x16b4) = uVar8 + uVar7;
              }
            }
            uVar7 = (uint)*(ushort *)(param_1 + 0xab6);
            uVar8 = *(uint *)(param_1 + 0x16b4);
            if ((int)(0x10 - uVar7) < (int)uVar8) {
              uVar1 = *(ushort *)(param_1 + 0xab4);
              uVar8 = (uint)uVar1 << (uVar8 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
              *(short *)(param_1 + 0x16b0) = (short)uVar8;
              *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar8;
              iVar5 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar5;
              *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              uVar8 = (*(int *)(param_1 + 0x16b4) + uVar7) - 0x10;
              *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f);
            }
            else {
              *(ushort *)(param_1 + 0x16b0) =
                   *(short *)(param_1 + 0xab4) << (uVar8 & 0x1f) | *(ushort *)(param_1 + 0x16b0);
              uVar8 = uVar8 + uVar7;
            }
            *(uint *)(param_1 + 0x16b4) = uVar8;
            if ((int)uVar8 < 0xf) {
              *(ushort *)(param_1 + 0x16b0) =
                   (ushort)(iVar12 + 0xfffd << (uVar8 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
              iVar5 = uVar8 + 2;
            }
            else {
              uVar7 = iVar12 - 3U << (uVar8 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
              *(short *)(param_1 + 0x16b0) = (short)uVar7;
              *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar7;
              iVar5 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar5;
              *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
              iVar5 = *(int *)(param_1 + 0x16b4) + -0xe;
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(short *)(param_1 + 0x16b0) =
                   (short)((iVar12 - 3U & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
            }
          }
          *(int *)(param_1 + 0x16b4) = iVar5;
        }
        iVar12 = 0;
        uVar7 = uVar2;
        if (uVar4 == 0) {
          iVar6 = 0x8a;
        }
        else {
          if (uVar2 != uVar4) {
            iVar6 = 7;
            iVar5 = 4;
            goto LAB_40146710;
          }
          iVar6 = 6;
        }
        iVar5 = 3;
      }
LAB_40146710:
      iVar10 = iVar10 + -1;
      puVar9 = puVar9 + 2;
      uVar2 = uVar4;
      iVar11 = iVar12;
    } while (iVar10 != 0);
  }
  return;
}



/* 40146734 FUN_40146734 */

/* Boundary evidence: original MIPS .pdata 40146734..40146a1f. Semantic name remains unreviewed. */

void FUN_40146734(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = *(uint *)(param_1 + 0x16b4);
  if ((int)uVar2 < 0xc) {
    *(ushort *)(param_1 + 0x16b0) =
         (ushort)(param_2 + 0xfeff << (uVar2 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
    *(uint *)(param_1 + 0x16b4) = uVar2 + 5;
  }
  else {
    uVar2 = param_2 - 0x101U << (uVar2 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
    *(short *)(param_1 + 0x16b0) = (short)uVar2;
    *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar2;
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(short *)(param_1 + 0x16b0) =
         (short)((param_2 - 0x101U & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
    *(int *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + -0xb;
  }
  uVar2 = *(uint *)(param_1 + 0x16b4);
  if ((int)uVar2 < 0xc) {
    *(ushort *)(param_1 + 0x16b0) =
         (ushort)(param_3 + 0xffff << (uVar2 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
    uVar2 = uVar2 + 5;
  }
  else {
    uVar2 = param_3 - 1U << (uVar2 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
    *(short *)(param_1 + 0x16b0) = (short)uVar2;
    *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar2;
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    uVar2 = *(int *)(param_1 + 0x16b4) - 0xb;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(short *)(param_1 + 0x16b0) =
         (short)((param_3 - 1U & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
  }
  *(uint *)(param_1 + 0x16b4) = uVar2;
  if ((int)uVar2 < 0xd) {
    *(ushort *)(param_1 + 0x16b0) =
         (ushort)(param_4 + 0xfffc << (uVar2 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
    iVar3 = uVar2 + 4;
  }
  else {
    uVar2 = param_4 - 4U << (uVar2 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
    *(short *)(param_1 + 0x16b0) = (short)uVar2;
    *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar2;
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    iVar3 = *(int *)(param_1 + 0x16b4) + -0xc;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(short *)(param_1 + 0x16b0) =
         (short)((param_4 - 4U & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
  }
  *(int *)(param_1 + 0x16b4) = iVar3;
  iVar3 = 0;
  if (0 < param_4) {
    do {
      uVar2 = *(uint *)(param_1 + 0x16b4);
      iVar4 = (uint)(byte)(&DAT_401412b0)[iVar3] * 4 + param_1;
      if ((int)uVar2 < 0xe) {
        *(ushort *)(param_1 + 0x16b0) =
             *(short *)(iVar4 + 0xa76) << (uVar2 & 0x1f) | *(ushort *)(param_1 + 0x16b0);
        *(uint *)(param_1 + 0x16b4) = uVar2 + 3;
      }
      else {
        uVar1 = *(ushort *)(iVar4 + 0xa76);
        uVar2 = (uint)uVar1 << (uVar2 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
        *(short *)(param_1 + 0x16b0) = (short)uVar2;
        *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar2;
        iVar4 = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x14) = iVar4;
        *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(ushort *)(param_1 + 0x16b0) = uVar1 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f);
        *(int *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + -0xd;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  FUN_401460e0(param_1,param_1 + 0x8c,param_2 + -1);
  FUN_401460e0(param_1,param_1 + 0x980,param_3 + -1);
  return;
}



/* 40146a20 FUN_40146a20 */

/* Boundary evidence: original MIPS .pdata 40146a20..40146f43. Semantic name remains unreviewed. */

void FUN_40146a20(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x1698) != 0) {
    iVar13 = 0;
    do {
      uVar4 = (uint)*(ushort *)(iVar13 + *(int *)(param_1 + 0x169c));
      uVar9 = (uint)*(byte *)(uVar2 + *(int *)(param_1 + 0x1690));
      uVar2 = uVar2 + 1;
      iVar13 = iVar13 + 2;
      if (uVar4 == 0) {
        puVar7 = (ushort *)(uVar9 * 4 + param_2);
        uVar4 = (uint)puVar7[1];
        uVar10 = *(uint *)(param_1 + 0x16b4);
        if ((int)(0x10 - uVar4) < (int)uVar10) {
          uVar9 = (uint)*puVar7;
          uVar10 = uVar9 << (uVar10 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
          *(short *)(param_1 + 0x16b0) = (short)uVar10;
          *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar10;
          iVar8 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar8;
          *(undefined1 *)(iVar8 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
          iVar8 = *(int *)(param_1 + 0x14);
          iVar11 = *(int *)(param_1 + 0x16b4);
          iVar3 = iVar11 + uVar4;
LAB_40146b14:
          *(int *)(param_1 + 0x14) = iVar8 + 1;
          *(int *)(param_1 + 0x16b4) = iVar3 + -0x10;
          uVar6 = (ushort)(uVar9 >> (0x10U - iVar11 & 0x1f));
LAB_40146e5c:
          *(ushort *)(param_1 + 0x16b0) = uVar6;
        }
        else {
          *(ushort *)(param_1 + 0x16b0) = *puVar7 << (uVar10 & 0x1f) | *(ushort *)(param_1 + 0x16b0)
          ;
          *(uint *)(param_1 + 0x16b4) = uVar10 + uVar4;
        }
      }
      else {
        uVar10 = (uint)(byte)(&DAT_401419bc)[uVar9];
        uVar12 = *(uint *)(param_1 + 0x16b4);
        iVar8 = uVar10 * 4;
        uVar5 = (uint)*(ushort *)(iVar8 + param_2 + 0x406);
        if ((int)(0x10 - uVar5) < (int)uVar12) {
          uVar6 = *(ushort *)((uVar10 + 0x101) * 4 + param_2);
          uVar10 = (uint)uVar6 << (uVar12 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
          *(short *)(param_1 + 0x16b0) = (short)uVar10;
          *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar10;
          iVar3 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar3;
          *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(ushort *)(param_1 + 0x16b0) = uVar6 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f);
          *(uint *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + uVar5 + -0x10;
        }
        else {
          *(ushort *)(param_1 + 0x16b0) =
               *(short *)((uVar10 + 0x101) * 4 + param_2) << (uVar12 & 0x1f) |
               *(ushort *)(param_1 + 0x16b0);
          *(uint *)(param_1 + 0x16b4) = uVar12 + uVar5;
        }
        iVar3 = *(int *)(&DAT_40141178 + iVar8);
        if (iVar3 != 0) {
          uVar10 = *(uint *)(param_1 + 0x16b4);
          uVar9 = uVar9 - *(int *)(&DAT_40141abc + iVar8);
          if (0x10 - iVar3 < (int)uVar10) {
            uVar10 = uVar9 << (uVar10 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
            *(short *)(param_1 + 0x16b0) = (short)uVar10;
            *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar10;
            iVar8 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar8;
            *(undefined1 *)(iVar8 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            uVar6 = (ushort)((uVar9 & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
            *(int *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + iVar3 + -0x10;
          }
          else {
            uVar6 = (ushort)(uVar9 << (uVar10 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
            *(uint *)(param_1 + 0x16b4) = uVar10 + iVar3;
          }
          *(ushort *)(param_1 + 0x16b0) = uVar6;
        }
        uVar9 = uVar4 - 1;
        if (uVar9 < 0x100) {
          bVar1 = (&DAT_401417bb)[uVar4];
        }
        else {
          bVar1 = (&DAT_401418bc)[uVar9 >> 7];
        }
        iVar8 = (uint)bVar1 * 4;
        puVar7 = (ushort *)(iVar8 + param_3);
        uVar4 = (uint)puVar7[1];
        uVar10 = *(uint *)(param_1 + 0x16b4);
        if ((int)(0x10 - uVar4) < (int)uVar10) {
          uVar6 = *puVar7;
          uVar10 = (uint)uVar6 << (uVar10 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
          *(short *)(param_1 + 0x16b0) = (short)uVar10;
          *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar10;
          iVar3 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar3;
          *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(ushort *)(param_1 + 0x16b0) = uVar6 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f);
          *(uint *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + uVar4 + -0x10;
        }
        else {
          *(ushort *)(param_1 + 0x16b0) = *puVar7 << (uVar10 & 0x1f) | *(ushort *)(param_1 + 0x16b0)
          ;
          *(uint *)(param_1 + 0x16b4) = uVar10 + uVar4;
        }
        iVar3 = *(int *)(&DAT_401411ec + iVar8);
        if (iVar3 != 0) {
          iVar8 = *(int *)(&LAB_40141b30 + iVar8);
          uVar10 = *(uint *)(param_1 + 0x16b4);
          uVar4 = uVar9 - iVar8 << (uVar10 & 0x1f);
          if (0x10 - iVar3 < (int)uVar10) {
            uVar4 = uVar4 | *(ushort *)(param_1 + 0x16b0);
            *(short *)(param_1 + 0x16b0) = (short)uVar4;
            *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar4;
            iVar11 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar11;
            uVar9 = uVar9 - iVar8 & 0xffff;
            *(undefined1 *)(iVar11 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
            iVar8 = *(int *)(param_1 + 0x14);
            iVar11 = *(int *)(param_1 + 0x16b4);
            iVar3 = iVar11 + iVar3;
            goto LAB_40146b14;
          }
          uVar6 = (ushort)uVar4 | *(ushort *)(param_1 + 0x16b0);
          *(uint *)(param_1 + 0x16b4) = uVar10 + iVar3;
          goto LAB_40146e5c;
        }
      }
    } while (uVar2 < *(uint *)(param_1 + 0x1698));
  }
  uVar2 = (uint)*(ushort *)(param_2 + 0x402);
  uVar9 = *(uint *)(param_1 + 0x16b4);
  if ((int)(0x10 - uVar2) < (int)uVar9) {
    uVar6 = *(ushort *)(param_2 + 0x400);
    uVar9 = (uint)uVar6 << (uVar9 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
    *(short *)(param_1 + 0x16b0) = (short)uVar9;
    *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar9;
    iVar13 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar13;
    *(undefined1 *)(iVar13 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    iVar13 = *(int *)(param_1 + 0x16b4) + uVar2 + -0x10;
    *(ushort *)(param_1 + 0x16b0) = uVar6 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f);
  }
  else {
    *(ushort *)(param_1 + 0x16b0) =
         *(short *)(param_2 + 0x400) << (uVar9 & 0x1f) | *(ushort *)(param_1 + 0x16b0);
    iVar13 = uVar9 + uVar2;
  }
  *(int *)(param_1 + 0x16b4) = iVar13;
  *(uint *)(param_1 + 0x16ac) = (uint)*(ushort *)(param_2 + 0x402);
  return;
}



/* 40146f44 FUN_40146f44 */

void FUN_40146f44(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x16b4) == 0x10) {
    *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         (char)*(undefined2 *)(param_1 + 0x16b0);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b1);
    *(undefined2 *)(param_1 + 0x16b0) = 0;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(undefined4 *)(param_1 + 0x16b4) = 0;
  }
  else if (7 < *(int *)(param_1 + 0x16b4)) {
    *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         (char)*(undefined2 *)(param_1 + 0x16b0);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(ushort *)(param_1 + 0x16b0) = (ushort)*(byte *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + -8;
  }
  return;
}



/* 40146fe4 FUN_40146fe4 */

void FUN_40146fe4(int param_1,undefined1 *param_2,uint param_3,int param_4)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x16b4) < 9) {
    if (0 < *(int *)(param_1 + 0x16b4)) {
      *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
           (char)*(undefined2 *)(param_1 + 0x16b0);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    }
  }
  else {
    *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         (char)*(undefined2 *)(param_1 + 0x16b0);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(undefined2 *)(param_1 + 0x16b0) = 0;
  *(undefined4 *)(param_1 + 0x16b4) = 0;
  *(undefined4 *)(param_1 + 0x16ac) = 8;
  if (param_4 != 0) {
    *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)param_3;
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)(param_3 >> 8);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)~param_3;
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(char *)(*(int *)(param_1 + 8) + iVar1) = (char)(~param_3 >> 8);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = *param_2;
    param_2 = param_2 + 1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  return;
}



/* 40147124 FUN_40147124 */

void FUN_40147124(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  *(undefined ***)(param_1 + 0xb18) = &PTR_DAT_4014b038;
  puVar4 = (undefined2 *)(param_1 + 0x8c);
  puVar3 = (undefined2 *)(param_1 + 0x980);
  puVar2 = (undefined2 *)(param_1 + 0xa74);
  *(undefined ***)(param_1 + 0xb24) = &PTR_DAT_4014b04c;
  *(undefined2 **)(param_1 + 0xb10) = puVar4;
  *(undefined2 **)(param_1 + 0xb1c) = puVar3;
  *(undefined2 **)(param_1 + 0xb28) = puVar2;
  *(undefined **)(param_1 + 0xb30) = &DAT_4014b060;
  *(undefined2 *)(param_1 + 0x16b0) = 0;
  iVar1 = 0x11e;
  *(undefined4 *)(param_1 + 0x16b4) = 0;
  *(undefined4 *)(param_1 + 0x16ac) = 8;
  do {
    *puVar4 = 0;
    iVar1 = iVar1 + -1;
    puVar4 = puVar4 + 2;
  } while (iVar1 != 0);
  iVar1 = 0x1e;
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 2;
  } while (iVar1 != 0);
  iVar1 = 0x13;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar1 != 0);
  *(undefined2 *)(param_1 + 0x48c) = 1;
  *(undefined4 *)(param_1 + 0x16a4) = 0;
  *(undefined4 *)(param_1 + 0x16a0) = 0;
  *(undefined4 *)(param_1 + 0x16a8) = 0;
  *(undefined4 *)(param_1 + 0x1698) = 0;
  return;
}



/* 401471c0 FUN_401471c0 */

/* Boundary evidence: original MIPS .pdata 401471c0..40147547. Semantic name remains unreviewed. */

void FUN_401471c0(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  ushort uVar7;
  short *psVar8;
  int iVar9;
  ushort *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  ushort *puVar14;
  int iVar15;
  int iVar16;
  ushort auStack_50 [16];
  uint local_30;
  
  local_30 = DAT_4014b0c0;
  puVar14 = (ushort *)*param_2;
  iVar12 = *(int *)param_2[2];
  iVar16 = ((int *)param_2[2])[3];
  iVar15 = -1;
  iVar9 = 0;
  *(undefined4 *)(param_1 + 0x1448) = 0;
  *(undefined4 *)(param_1 + 0x144c) = 0x23d;
  puVar10 = puVar14;
  if (0 < iVar16) {
    do {
      if (*puVar10 == 0) {
        puVar10[1] = 0;
      }
      else {
        iVar15 = *(int *)(param_1 + 0x1448);
        *(int *)(param_1 + 0x1448) = iVar15 + 1;
        *(int *)((iVar15 + 0x2d6) * 4 + param_1) = iVar9;
        *(undefined1 *)(param_1 + iVar9 + 0x1450) = 0;
        iVar15 = iVar9;
      }
      iVar9 = iVar9 + 1;
      puVar10 = puVar10 + 2;
    } while (iVar9 < iVar16);
  }
  if (*(int *)(param_1 + 0x1448) < 2) {
    do {
      if (iVar15 < 2) {
        iVar9 = iVar15 + 1;
        iVar15 = iVar9;
      }
      else {
        iVar9 = 0;
      }
      iVar2 = *(int *)(param_1 + 0x1448);
      *(int *)(param_1 + 0x1448) = iVar2 + 1;
      *(int *)((iVar2 + 0x2d6) * 4 + param_1) = iVar9;
      puVar14[iVar9 * 2] = 1;
      *(undefined1 *)(param_1 + 0x1450 + iVar9) = 0;
      *(int *)(param_1 + 0x16a0) = *(int *)(param_1 + 0x16a0) + -1;
      if (iVar12 != 0) {
        *(uint *)(param_1 + 0x16a4) =
             *(int *)(param_1 + 0x16a4) - (uint)*(ushort *)(iVar9 * 4 + iVar12 + 2);
      }
    } while (*(int *)(param_1 + 0x1448) < 2);
  }
  param_2[1] = iVar15;
  iVar9 = *(int *)(param_1 + 0x1448);
  if (iVar9 < 0) {
    iVar9 = iVar9 + 1;
  }
  for (iVar9 = iVar9 >> 1; 0 < iVar9; iVar9 = iVar9 + -1) {
    FUN_40145bdc(param_1,(int)puVar14,iVar9);
  }
  iVar9 = param_1 + 0x1450;
  puVar10 = puVar14 + iVar16 * 2;
  do {
    iVar13 = *(int *)(param_1 + 0xb58);
    *(undefined4 *)(param_1 + 0xb58) =
         *(undefined4 *)((*(int *)(param_1 + 0x1448) + 0x2d5) * 4 + param_1);
    *(int *)(param_1 + 0x1448) = *(int *)(param_1 + 0x1448) + -1;
    FUN_40145bdc(param_1,(int)puVar14,1);
    iVar2 = *(int *)(param_1 + 0x144c);
    iVar12 = *(int *)(param_1 + 0xb58);
    *(int *)(param_1 + 0x144c) = iVar2 + -1;
    *(int *)((iVar2 + 0x2d4) * 4 + param_1) = iVar13;
    iVar2 = *(int *)(param_1 + 0x144c);
    *(int *)(param_1 + 0x144c) = iVar2 + -1;
    *(int *)((iVar2 + 0x2d4) * 4 + param_1) = iVar12;
    *puVar10 = puVar14[iVar13 * 2] + puVar14[iVar12 * 2];
    bVar5 = *(byte *)(iVar9 + iVar13);
    if (*(byte *)(iVar9 + iVar13) < *(byte *)(iVar9 + iVar12)) {
      bVar5 = *(byte *)(iVar9 + iVar12);
    }
    *(byte *)(iVar9 + iVar16) = bVar5 + 1;
    (puVar14 + iVar12 * 2)[1] = (ushort)iVar16;
    (puVar14 + iVar13 * 2)[1] = (ushort)iVar16;
    *(int *)(param_1 + 0xb58) = iVar16;
    iVar16 = iVar16 + 1;
    puVar10 = puVar10 + 2;
    FUN_40145bdc(param_1,(int)puVar14,1);
  } while (1 < *(int *)(param_1 + 0x1448));
  iVar9 = *(int *)(param_1 + 0x144c);
  *(int *)(param_1 + 0x144c) = iVar9 + -1;
  *(undefined4 *)((iVar9 + 0x2d4) * 4 + param_1) = *(undefined4 *)(param_1 + 0xb58);
  FUN_40145d18(param_1,param_2);
  uVar7 = 0;
  puVar10 = auStack_50;
  psVar8 = (short *)(param_1 + 0xb34);
  iVar9 = 0xf;
  do {
    puVar10 = puVar10 + 1;
    uVar7 = (*psVar8 + uVar7) * 2;
    *puVar10 = uVar7;
    psVar8 = psVar8 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (-1 < iVar15) {
    iVar15 = iVar15 + 1;
    do {
      uVar3 = (uint)puVar14[1];
      if (uVar3 != 0) {
        uVar7 = auStack_50[uVar3];
        uVar6 = (uint)uVar7;
        auStack_50[uVar3] = uVar7 + 1;
        uVar1 = 0;
        do {
          uVar11 = uVar1;
          uVar4 = uVar6 & 1;
          uVar6 = uVar6 >> 1;
          uVar3 = uVar3 - 1;
          uVar1 = (uVar4 | uVar11) << 1;
        } while (0 < (int)uVar3);
        *puVar14 = (ushort)uVar4 | (ushort)uVar11;
      }
      puVar14 = puVar14 + 2;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  FUN_4014a354(local_30);
  return;
}



/* 40147548 FUN_40147548 */

/* Boundary evidence: original MIPS .pdata 40147548..401475eb. Semantic name remains unreviewed. */

void FUN_40147548(int param_1,undefined1 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x16b4);
  uVar1 = param_4 << (uVar2 & 0x1f);
  if ((int)uVar2 < 0xe) {
    *(ushort *)(param_1 + 0x16b0) = (ushort)uVar1 | *(ushort *)(param_1 + 0x16b0);
    iVar3 = uVar2 + 3;
  }
  else {
    uVar1 = uVar1 | *(ushort *)(param_1 + 0x16b0);
    *(short *)(param_1 + 0x16b0) = (short)uVar1;
    *(char *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) = (char)uVar1;
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    *(short *)(param_1 + 0x16b0) =
         (short)((param_4 & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
    iVar3 = *(int *)(param_1 + 0x16b4) + -0xd;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(int *)(param_1 + 0x16b4) = iVar3;
  FUN_40146fe4(param_1,param_2,param_3,1);
  return;
}



/* 401475ec FUN_401475ec */

/* Boundary evidence: original MIPS .pdata 401475ec..4014785f. Semantic name remains unreviewed. */

void FUN_401475ec(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x16b4);
  if ((int)uVar2 < 0xe) {
    *(ushort *)(param_1 + 0x16b0) = (ushort)(2 << (uVar2 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
    *(uint *)(param_1 + 0x16b4) = uVar2 + 3;
  }
  else {
    uVar2 = 2 << (uVar2 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
    *(short *)(param_1 + 0x16b0) = (short)uVar2;
    *(char *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) = (char)uVar2;
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(short *)(param_1 + 0x16b0) = (short)(2 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
    *(int *)(param_1 + 0x16b4) = *(int *)(param_1 + 0x16b4) + -0xd;
  }
  uVar1 = *(undefined2 *)(param_1 + 0x16b0);
  if (*(int *)(param_1 + 0x16b4) < 10) {
    *(undefined2 *)(param_1 + 0x16b0) = uVar1;
    iVar3 = *(int *)(param_1 + 0x16b4) + 7;
  }
  else {
    *(undefined2 *)(param_1 + 0x16b0) = uVar1;
    *(char *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) = (char)uVar1;
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
    iVar3 = *(int *)(param_1 + 0x16b4) + -9;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(short *)(param_1 + 0x16b0) = (short)(0 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
  }
  *(int *)(param_1 + 0x16b4) = iVar3;
  FUN_40146f44(param_1);
  uVar2 = *(uint *)(param_1 + 0x16b4);
  if ((int)((*(int *)(param_1 + 0x16ac) - uVar2) + 0xb) < 9) {
    if ((int)uVar2 < 0xe) {
      *(ushort *)(param_1 + 0x16b0) = (ushort)(2 << (uVar2 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
      iVar3 = uVar2 + 3;
    }
    else {
      uVar2 = 2 << (uVar2 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
      *(short *)(param_1 + 0x16b0) = (short)uVar2;
      *(char *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) = (char)uVar2;
      iVar3 = *(int *)(param_1 + 0x14) + 1;
      *(int *)(param_1 + 0x14) = iVar3;
      *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
      iVar3 = *(int *)(param_1 + 0x16b4) + -0xd;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(short *)(param_1 + 0x16b0) = (short)(2 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
    }
    *(int *)(param_1 + 0x16b4) = iVar3;
    if (iVar3 < 10) {
      iVar3 = iVar3 + 7;
      *(undefined2 *)(param_1 + 0x16b0) = *(undefined2 *)(param_1 + 0x16b0);
    }
    else {
      uVar1 = *(undefined2 *)(param_1 + 0x16b0);
      *(undefined2 *)(param_1 + 0x16b0) = uVar1;
      *(char *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) = (char)uVar1;
      iVar3 = *(int *)(param_1 + 0x14) + 1;
      *(int *)(param_1 + 0x14) = iVar3;
      *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b1);
      iVar3 = *(int *)(param_1 + 0x16b4) + -9;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(short *)(param_1 + 0x16b0) = (short)(0 >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
    }
    *(int *)(param_1 + 0x16b4) = iVar3;
    FUN_40146f44(param_1);
  }
  *(undefined4 *)(param_1 + 0x16ac) = 7;
  return;
}



/* 40147860 FUN_40147860 */

/* Boundary evidence: original MIPS .pdata 40147860..40147c9f. Semantic name remains unreviewed. */

void FUN_40147860(int param_1,undefined1 *param_2,uint param_3,uint param_4)

{
  undefined *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  
  iVar8 = 0;
  puVar7 = &DAT_40141744;
  if (*(int *)(param_1 + 0x7c) < 1) {
    uVar3 = param_3 + 5;
  }
  else {
    if (*(char *)(param_1 + 0x1c) == '\x02') {
      uVar6 = 0;
      uVar3 = 0;
      puVar4 = (ushort *)(param_1 + 0x8c);
      iVar8 = 7;
      do {
        uVar3 = *puVar4 + uVar3;
        iVar8 = iVar8 + -1;
        puVar4 = puVar4 + 2;
      } while (iVar8 != 0);
      puVar4 = (ushort *)(param_1 + 0xa8);
      iVar8 = 0x79;
      do {
        uVar6 = *puVar4 + uVar6;
        iVar8 = iVar8 + -1;
        puVar4 = puVar4 + 2;
      } while (iVar8 != 0);
      puVar4 = (ushort *)(param_1 + 0x28c);
      iVar8 = 0x80;
      do {
        uVar3 = *puVar4 + uVar3;
        iVar8 = iVar8 + -1;
        puVar4 = puVar4 + 2;
      } while (iVar8 != 0);
      *(bool *)(param_1 + 0x1c) = uVar3 <= uVar6 >> 2;
    }
    FUN_401471c0(param_1,(int *)(param_1 + 0xb10));
    FUN_401471c0(param_1,(int *)(param_1 + 0xb1c));
    FUN_40145fb4(param_1,param_1 + 0x8c,*(int *)(param_1 + 0xb14));
    FUN_40145fb4(param_1,param_1 + 0x980,*(int *)(param_1 + 0xb20));
    FUN_401471c0(param_1,(int *)(param_1 + 0xb28));
    iVar8 = 0x12;
    do {
      if (*(short *)((uint)(byte)(&DAT_401412b0)[iVar8] * 4 + param_1 + 0xa76) != 0) break;
      iVar8 = iVar8 + -1;
    } while (2 < iVar8);
    iVar5 = iVar8 * 3 + *(int *)(param_1 + 0x16a0);
    *(int *)(param_1 + 0x16a0) = iVar5 + 0x11;
    uVar6 = iVar5 + 0x1bU >> 3;
    uVar3 = *(int *)(param_1 + 0x16a4) + 10U >> 3;
    if (uVar6 < uVar3) goto LAB_401479f0;
  }
  uVar6 = uVar3;
  uVar3 = uVar6;
LAB_401479f0:
  if ((uVar6 < param_3 + 4) || (param_2 == (undefined1 *)0x0)) {
    if (uVar3 == uVar6) {
      uVar3 = *(uint *)(param_1 + 0x16b4);
      if ((int)uVar3 < 0xe) {
        *(ushort *)(param_1 + 0x16b0) =
             (ushort)(param_4 + 2 << (uVar3 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
        iVar8 = uVar3 + 3;
      }
      else {
        uVar3 = param_4 + 2 << (uVar3 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
        *(short *)(param_1 + 0x16b0) = (short)uVar3;
        *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar3;
        iVar8 = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x14) = iVar8;
        *(undefined1 *)(*(int *)(param_1 + 8) + iVar8) = *(undefined1 *)(param_1 + 0x16b1);
        *(short *)(param_1 + 0x16b0) =
             (short)((param_4 + 2 & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
        iVar8 = *(int *)(param_1 + 0x16b4) + -0xd;
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      }
      *(int *)(param_1 + 0x16b4) = iVar8;
      puVar1 = &DAT_401412c4;
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x16b4);
      if ((int)uVar3 < 0xe) {
        *(ushort *)(param_1 + 0x16b0) =
             (ushort)(param_4 + 4 << (uVar3 & 0x1f)) | *(ushort *)(param_1 + 0x16b0);
        iVar5 = uVar3 + 3;
      }
      else {
        uVar3 = param_4 + 4 << (uVar3 & 0x1f) | (uint)*(ushort *)(param_1 + 0x16b0);
        *(short *)(param_1 + 0x16b0) = (short)uVar3;
        *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) = (char)uVar3;
        iVar5 = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x14) = iVar5;
        *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b1);
        *(short *)(param_1 + 0x16b0) =
             (short)((param_4 + 4 & 0xffff) >> (0x10U - *(int *)(param_1 + 0x16b4) & 0x1f));
        iVar5 = *(int *)(param_1 + 0x16b4) + -0xd;
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      }
      *(int *)(param_1 + 0x16b4) = iVar5;
      FUN_40146734(param_1,*(int *)(param_1 + 0xb14) + 1,*(int *)(param_1 + 0xb20) + 1,iVar8 + 1);
      puVar7 = (undefined *)(param_1 + 0x980);
      puVar1 = (undefined *)(param_1 + 0x8c);
    }
    FUN_40146a20(param_1,(int)puVar1,(int)puVar7);
  }
  else {
    FUN_40147548(param_1,param_2,param_3,param_4);
  }
  puVar2 = (undefined2 *)(param_1 + 0x8c);
  iVar8 = 0x11e;
  do {
    *puVar2 = 0;
    iVar8 = iVar8 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar8 != 0);
  puVar2 = (undefined2 *)(param_1 + 0x980);
  iVar8 = 0x1e;
  do {
    *puVar2 = 0;
    iVar8 = iVar8 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar8 != 0);
  puVar2 = (undefined2 *)(param_1 + 0xa74);
  iVar8 = 0x13;
  do {
    *puVar2 = 0;
    iVar8 = iVar8 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar8 != 0);
  *(undefined2 *)(param_1 + 0x48c) = 1;
  *(undefined4 *)(param_1 + 0x16a4) = 0;
  *(undefined4 *)(param_1 + 0x16a0) = 0;
  *(undefined4 *)(param_1 + 0x16a8) = 0;
  *(undefined4 *)(param_1 + 0x1698) = 0;
  if (param_4 != 0) {
    if (*(int *)(param_1 + 0x16b4) < 9) {
      if (0 < *(int *)(param_1 + 0x16b4)) {
        *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
             (char)*(undefined2 *)(param_1 + 0x16b0);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      }
    }
    else {
      *(char *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
           (char)*(undefined2 *)(param_1 + 0x16b0);
      iVar8 = *(int *)(param_1 + 0x14) + 1;
      *(int *)(param_1 + 0x14) = iVar8;
      *(undefined1 *)(*(int *)(param_1 + 8) + iVar8) = *(undefined1 *)(param_1 + 0x16b1);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    }
    *(undefined2 *)(param_1 + 0x16b0) = 0;
    *(undefined4 *)(param_1 + 0x16b4) = 0;
  }
  return;
}



/* 40147ca0 FUN_40147ca0 */

/* Boundary evidence: original MIPS .pdata 40147ca0..40147d57. Semantic name remains unreviewed. */

void FUN_40147ca0(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    *param_3 = param_1[0xf];
  }
  if ((*param_1 == 4) || (*param_1 == 5)) {
    (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1[3]);
  }
  if (*param_1 == 6) {
    FUN_40149138(param_1[1],param_2);
  }
  *param_1 = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xd] = param_1[10];
  param_1[0xc] = param_1[10];
  if ((code *)param_1[0xe] != (code *)0x0) {
    iVar1 = (*(code *)param_1[0xe])(0,0,0);
    param_1[0xf] = iVar1;
    *(int *)(param_2 + 0x30) = iVar1;
  }
  return;
}



/* 40147d58 FUN_40147d58 */

/* Boundary evidence: original MIPS .pdata 40147d58..40147e47. Semantic name remains unreviewed. */

int * FUN_40147d58(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x40);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),8,0x5a0);
    piVar1[9] = iVar2;
    uVar3 = *(undefined4 *)(param_1 + 0x28);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(param_1 + 0x20))(uVar3,1,param_3);
      piVar1[10] = iVar2;
      if (iVar2 != 0) {
        piVar1[0xb] = iVar2 + param_3;
        piVar1[0xe] = param_2;
        *piVar1 = 0;
        FUN_40147ca0(piVar1,param_1,(int *)0x0);
        return piVar1;
      }
      (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),piVar1[9]);
      uVar3 = *(undefined4 *)(param_1 + 0x28);
    }
    (**(code **)(param_1 + 0x24))(uVar3,piVar1);
  }
  return (int *)0x0;
}



/* 40147e48 FUN_40147e48 */

/* Boundary evidence: original MIPS .pdata 40147e48..40148883. Semantic name remains unreviewed. */

void FUN_40147e48(uint *param_1,int *param_2,uint param_3)

{
  void *pvVar1;
  char *pcVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *_Src;
  uint uVar10;
  void *pvVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  
  pvVar11 = (void *)param_1[0xd];
  _Src = (byte *)*param_2;
  uVar13 = param_2[1];
  uVar12 = param_1[8];
  uVar10 = param_1[7];
  if (pvVar11 < (void *)param_1[0xc]) {
    uVar14 = (int)param_1[0xc] + (-1 - (int)pvVar11);
  }
  else {
    uVar14 = param_1[0xb] - (int)pvVar11;
  }
  uVar4 = *param_1;
  while (pvVar1 = pvVar11, uVar4 < 10) {
    uVar15 = param_3;
    switch(uVar4) {
    case 0:
      for (; uVar10 < 3; uVar10 = uVar10 + 8) {
        if (uVar13 == 0) goto LAB_40148774;
        param_3 = 0;
        uVar13 = uVar13 - 1;
        uVar12 = (uint)*_Src << (uVar10 & 0x1f) | uVar12;
        _Src = _Src + 1;
      }
      uVar4 = (uVar12 & 7) >> 1;
      param_1[6] = uVar12 & 1;
      if (uVar4 == 0) {
        uVar4 = uVar10 - 3 & 7;
        *param_1 = 1;
        uVar12 = (uVar12 >> 3) >> uVar4;
        uVar10 = (uVar10 - 3) - uVar4;
      }
      else if (uVar4 == 1) {
        FUN_401499c4(&local_34,&local_38,&local_3c,&local_40);
        uVar4 = FUN_40148958((char)local_34,(char)local_38,local_3c,local_40,(int)param_2);
        param_1[1] = uVar4;
        if (uVar4 == 0) goto LAB_40148788;
        *param_1 = 6;
        uVar12 = uVar12 >> 3;
        uVar10 = uVar10 - 3;
      }
      else if (uVar4 == 2) {
        uVar12 = uVar12 >> 3;
        *param_1 = 3;
        uVar10 = uVar10 - 3;
      }
      else if (uVar4 == 3) {
        *param_1 = 9;
        param_2[6] = (int)"invalid block type";
        param_1[8] = uVar12 >> 3;
        param_1[7] = uVar10 - 3;
        param_2[1] = uVar13;
        param_3 = 0xfffffffd;
        param_2[2] = (int)(_Src + (param_2[2] - *param_2));
        goto LAB_40148730;
      }
      break;
    case 1:
      for (; uVar10 < 0x20; uVar10 = uVar10 + 8) {
        if (uVar13 == 0) goto LAB_40148774;
        param_3 = 0;
        uVar13 = uVar13 - 1;
        uVar12 = (uint)*_Src << (uVar10 & 0x1f) | uVar12;
        _Src = _Src + 1;
      }
      uVar4 = uVar12 & 0xffff;
      if (~uVar12 >> 0x10 != uVar4) {
        pcVar2 = "invalid stored block lengths";
LAB_40148798:
        *param_1 = 9;
LAB_4014879c:
        param_2[6] = (int)pcVar2;
        goto switchD_40147f0c_caseD_9;
      }
      param_1[1] = uVar4;
      uVar10 = 0;
      uVar12 = 0;
      if (uVar4 == 0) {
        if (param_1[6] == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 7;
        }
      }
      else {
        uVar4 = 2;
      }
      *param_1 = uVar4;
      break;
    case 2:
      if (uVar13 == 0) {
LAB_40148774:
        param_1[8] = uVar12;
        param_1[7] = uVar10;
        param_2[1] = 0;
        goto LAB_4014871c;
      }
      if (uVar14 == 0) {
        if (pvVar11 == (void *)param_1[0xb]) {
          pvVar3 = (void *)param_1[0xc];
          pvVar1 = (void *)param_1[10];
          if (pvVar3 != pvVar1) {
            if (pvVar1 < pvVar3) {
              uVar14 = (int)pvVar3 + (-1 - (int)pvVar1);
            }
            else {
              uVar14 = (int)param_1[0xb] - (int)pvVar1;
            }
            pvVar11 = pvVar1;
            if (uVar14 != 0) goto LAB_4014819c;
          }
        }
        param_1[0xd] = (uint)pvVar11;
        param_3 = FUN_401499f8((int)param_1,(int)param_2,param_3);
        pvVar1 = (void *)param_1[0xd];
        pvVar11 = (void *)param_1[0xc];
        if (pvVar1 < pvVar11) {
          uVar14 = (int)pvVar11 + (-1 - (int)pvVar1);
        }
        else {
          uVar14 = param_1[0xb] - (int)pvVar1;
        }
        if ((pvVar1 == (void *)param_1[0xb]) && (pvVar3 = (void *)param_1[10], pvVar11 != pvVar3)) {
          pvVar1 = pvVar3;
          if (pvVar3 < pvVar11) {
            uVar14 = (int)pvVar11 + (-1 - (int)pvVar3);
          }
          else {
            uVar14 = (int)param_1[0xb] - (int)pvVar3;
          }
        }
        if (uVar14 == 0) goto LAB_40148710;
      }
LAB_4014819c:
      local_44 = 0;
      uVar4 = param_1[1];
      if (uVar13 < param_1[1]) {
        uVar4 = uVar13;
      }
      if (uVar14 < uVar4) {
        uVar4 = uVar14;
      }
      memcpy(pvVar1,_Src,uVar4);
      uVar15 = param_1[1];
      param_1[1] = uVar15 - uVar4;
      _Src = _Src + uVar4;
      uVar13 = uVar13 - uVar4;
      pvVar11 = (void *)(uVar4 + (int)pvVar1);
      uVar14 = uVar14 - uVar4;
      param_3 = local_44;
      if (uVar15 - uVar4 == 0) {
        uVar4 = 7;
        if (param_1[6] == 0) {
          uVar4 = 0;
        }
        *param_1 = uVar4;
      }
      break;
    case 3:
      for (; uVar10 < 0xe; uVar10 = uVar10 + 8) {
        if (uVar13 == 0) goto LAB_40148774;
        param_3 = 0;
        uVar13 = uVar13 - 1;
        uVar12 = (uint)*_Src << (uVar10 & 0x1f) | uVar12;
        _Src = _Src + 1;
      }
      param_1[1] = uVar12 & 0x3fff;
      if ((0x1d < (uVar12 & 0x1f)) || (uVar14 = (uVar12 & 0x3fff) >> 5 & 0x1f, 0x1d < uVar14)) {
        pcVar2 = "too many length or distance symbols";
        goto LAB_40148798;
      }
      uVar14 = (*(code *)param_2[8])(param_2[10],uVar14 + (uVar12 & 0x1f) + 0x102,4);
      param_1[3] = uVar14;
      if (uVar14 != 0) {
        uVar12 = uVar12 >> 0xe;
        uVar10 = uVar10 - 0xe;
        param_1[2] = 0;
        *param_1 = 4;
        goto switchD_40147f0c_caseD_4;
      }
      goto LAB_40148788;
    case 4:
switchD_40147f0c_caseD_4:
      uVar15 = param_3;
      if (param_1[2] < (param_1[1] >> 10) + 4) {
        do {
          for (; uVar10 < 3; uVar10 = uVar10 + 8) {
            if (uVar13 == 0) goto LAB_40148774;
            param_3 = 0;
            uVar13 = uVar13 - 1;
            uVar12 = (uint)*_Src << (uVar10 & 0x1f) | uVar12;
            _Src = _Src + 1;
          }
          *(uint *)(*(int *)(&LAB_40141ba8 + param_1[2] * 4) * 4 + param_1[3]) = uVar12 & 7;
          uVar14 = param_1[2];
          param_1[2] = uVar14 + 1;
          uVar12 = uVar12 >> 3;
          uVar10 = uVar10 - 3;
          uVar15 = param_3;
        } while (uVar14 + 1 < (param_1[1] >> 10) + 4);
      }
      uVar14 = param_1[2];
      while (uVar14 < 0x13) {
        *(undefined4 *)(*(int *)(&LAB_40141ba8 + param_1[2] * 4) * 4 + param_1[3]) = 0;
        uVar14 = param_1[2] + 1;
        param_1[2] = uVar14;
      }
      param_1[4] = 7;
      param_3 = FUN_401496bc((int *)param_1[3],param_1 + 4,param_1 + 5,param_1[9],(int)param_2);
      if (param_3 == 0) {
        param_1[2] = 0;
        *param_1 = 5;
        goto switchD_40147f0c_caseD_5;
      }
LAB_401487c0:
      if (param_3 == 0xfffffffd) {
        (*(code *)param_2[9])(param_2[10],param_1[3]);
        *param_1 = 9;
      }
      goto LAB_40148710;
    case 5:
switchD_40147f0c_caseD_5:
      while( true ) {
        uVar14 = 7;
        iVar9 = 3;
        if ((param_1[1] >> 5 & 0x1f) + (param_1[1] & 0x1f) + 0x102 <= param_1[2]) break;
        param_3 = uVar15;
        for (; uVar10 < param_1[4]; uVar10 = uVar10 + 8) {
          if (uVar13 == 0) goto LAB_40148774;
          param_3 = 0;
          uVar13 = uVar13 - 1;
          uVar12 = (uint)*_Src << (uVar10 & 0x1f) | uVar12;
          _Src = _Src + 1;
        }
        iVar8 = (*(uint *)(&DAT_4014b07c + param_1[4] * 4) & uVar12) * 8 + param_1[5];
        uVar4 = (uint)*(byte *)(iVar8 + 1);
        uVar15 = *(uint *)(iVar8 + 4);
        if (uVar15 < 0x10) {
          *(uint *)(param_1[2] * 4 + param_1[3]) = uVar15;
          uVar12 = uVar12 >> (uVar4 & 0x1f);
          uVar10 = uVar10 - uVar4;
          param_1[2] = param_1[2] + 1;
          uVar15 = param_3;
        }
        else {
          if (uVar15 == 0x12) {
            iVar9 = 0xb;
          }
          else {
            uVar14 = uVar15 - 0xe;
          }
          for (; uVar10 < uVar14 + uVar4; uVar10 = uVar10 + 8) {
            if (uVar13 == 0) goto LAB_40148774;
            param_3 = 0;
            uVar13 = uVar13 - 1;
            uVar12 = (uint)*_Src << (uVar10 & 0x1f) | uVar12;
            _Src = _Src + 1;
          }
          uVar6 = uVar12 >> (uVar4 & 0x1f);
          uVar12 = uVar6 >> (uVar14 & 0x1f);
          uVar7 = param_1[2];
          uVar10 = (uVar10 - uVar14) - uVar4;
          iVar9 = (*(uint *)(&DAT_4014b07c + uVar14 * 4) & uVar6) + iVar9;
          if ((param_1[1] >> 5 & 0x1f) + (param_1[1] & 0x1f) + 0x102 < iVar9 + uVar7) {
LAB_401487e8:
            (*(code *)param_2[9])(param_2[10],param_1[3]);
            pcVar2 = "invalid bit length repeat";
            *param_1 = 9;
            goto LAB_4014879c;
          }
          if (uVar15 == 0x10) {
            if (uVar7 == 0) goto LAB_401487e8;
            uVar5 = *(undefined4 *)(uVar7 * 4 + param_1[3] + -4);
          }
          else {
            uVar5 = 0;
          }
          iVar8 = uVar7 << 2;
          do {
            *(undefined4 *)(param_1[3] + iVar8) = uVar5;
            uVar7 = uVar7 + 1;
            iVar9 = iVar9 + -1;
            iVar8 = iVar8 + 4;
          } while (iVar9 != 0);
          param_1[2] = uVar7;
          uVar15 = param_3;
        }
      }
      local_48 = 6;
      param_1[5] = 0;
      local_44 = 9;
      param_3 = FUN_401497cc((param_1[1] & 0x1f) + 0x101,(param_1[1] >> 5 & 0x1f) + 1,
                             (int *)param_1[3],&local_44,&local_48,&local_2c,&local_30,param_1[9],
                             (int)param_2);
      if (param_3 != 0) goto LAB_401487c0;
      uVar14 = FUN_40148958((char)local_44,(char)local_48,local_2c,local_30,(int)param_2);
      if (uVar14 != 0) {
        param_1[1] = uVar14;
        (*(code *)param_2[9])(param_2[10],param_1[3]);
        *param_1 = 6;
        goto switchD_40147f0c_caseD_6;
      }
LAB_40148788:
      param_3 = 0xfffffffc;
      goto LAB_40148710;
    case 6:
switchD_40147f0c_caseD_6:
      param_1[8] = uVar12;
      param_1[7] = uVar10;
      param_2[1] = uVar13;
      param_2[2] = (int)(_Src + (param_2[2] - *param_2));
      *param_2 = (int)_Src;
      param_1[0xd] = (uint)pvVar11;
      param_3 = FUN_401489d0((int)param_1,param_2,uVar15);
      if (param_3 != 1) goto LAB_4014873c;
      param_3 = 0;
      FUN_40149138(param_1[1],(int)param_2);
      pvVar11 = (void *)param_1[0xd];
      _Src = (byte *)*param_2;
      uVar13 = param_2[1];
      uVar12 = param_1[8];
      uVar10 = param_1[7];
      if (pvVar11 < (void *)param_1[0xc]) {
        uVar14 = (int)param_1[0xc] + (-1 - (int)pvVar11);
      }
      else {
        uVar14 = param_1[0xb] - (int)pvVar11;
      }
      if (param_1[6] != 0) {
        *param_1 = 7;
        goto switchD_40147f0c_caseD_7;
      }
      *param_1 = 0;
      break;
    case 7:
switchD_40147f0c_caseD_7:
      param_1[0xd] = (uint)pvVar11;
      param_3 = FUN_401499f8((int)param_1,(int)param_2,param_3);
      pvVar11 = (void *)param_1[0xd];
      if ((void *)param_1[0xc] == pvVar11) {
        *param_1 = 8;
        goto switchD_40147f0c_caseD_8;
      }
      param_1[8] = uVar12;
      param_1[7] = uVar10;
      param_2[1] = uVar13;
      param_2[2] = (int)(_Src + (param_2[2] - *param_2));
      goto LAB_40148730;
    case 8:
switchD_40147f0c_caseD_8:
      param_3 = 1;
      pvVar1 = pvVar11;
      goto LAB_40148710;
    case 9:
switchD_40147f0c_caseD_9:
      param_3 = 0xfffffffd;
      goto LAB_40148710;
    }
    uVar4 = *param_1;
  }
  param_3 = 0xfffffffe;
LAB_40148710:
  param_1[8] = uVar12;
  param_1[7] = uVar10;
  param_2[1] = uVar13;
  pvVar11 = pvVar1;
LAB_4014871c:
  param_2[2] = (int)(_Src + (param_2[2] - *param_2));
LAB_40148730:
  *param_2 = (int)_Src;
  param_1[0xd] = (uint)pvVar11;
LAB_4014873c:
  FUN_401499f8((int)param_1,(int)param_2,param_3);
  return;
}



/* 40148884 FUN_40148884 */

/* Boundary evidence: original MIPS .pdata 40148884..401488f3. Semantic name remains unreviewed. */

undefined4 FUN_40148884(int *param_1,int param_2)

{
  FUN_40147ca0(param_1,param_2,(int *)0x0);
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1[10]);
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1[9]);
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return 0;
}



/* 401488f4 FUN_401488f4 */

/* Boundary evidence: original MIPS .pdata 401488f4..4014893b. Semantic name remains unreviewed. */

void FUN_401488f4(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  memcpy(*(void **)(param_1 + 0x28),param_2,param_3);
  iVar1 = param_3 + *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x34) = iVar1;
  *(int *)(param_1 + 0x30) = iVar1;
  return;
}



/* 4014893c FUN_4014893c */

bool FUN_4014893c(int *param_1)

{
  return *param_1 == 1;
}



/* 40148958 FUN_40148958 */

/* Boundary evidence: original MIPS .pdata 40148958..401489cf. Semantic name remains unreviewed. */

void FUN_40148958(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(param_5 + 0x20))(*(undefined4 *)(param_5 + 0x28),1,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 4) = param_1;
    *(undefined1 *)((int)puVar1 + 0x11) = param_2;
    puVar1[5] = param_3;
    puVar1[6] = param_4;
  }
  return;
}



/* 401489d0 FUN_401489d0 */

/* Boundary evidence: original MIPS .pdata 401489d0..40149137. Semantic name remains unreviewed. */

void FUN_401489d0(int param_1,int *param_2,int param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint *puVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  
  puVar7 = *(undefined1 **)(param_1 + 0x34);
  puVar9 = *(uint **)(param_1 + 4);
  pbVar11 = (byte *)*param_2;
  uVar13 = param_2[1];
  uVar12 = *(uint *)(param_1 + 0x20);
  uVar10 = *(uint *)(param_1 + 0x1c);
  if (puVar7 < *(undefined1 **)(param_1 + 0x30)) {
    puVar8 = *(undefined1 **)(param_1 + 0x30) + (-1 - (int)puVar7);
  }
  else {
    puVar8 = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar7);
  }
  uVar6 = *puVar9;
  while (puVar3 = puVar7, uVar6 < 10) {
    switch(uVar6) {
    case 0:
      if ((puVar8 < (undefined1 *)0x102) || (uVar13 < 10)) {
LAB_40148b58:
        puVar9[3] = (uint)(byte)puVar9[4];
        puVar9[2] = puVar9[5];
        *puVar9 = 1;
        goto switchD_40148a78_caseD_1;
      }
      *(uint *)(param_1 + 0x20) = uVar12;
      *(uint *)(param_1 + 0x1c) = uVar10;
      param_2[1] = uVar13;
      param_2[2] = (int)(pbVar11 + (param_2[2] - *param_2));
      *param_2 = (int)pbVar11;
      *(undefined1 **)(param_1 + 0x34) = puVar7;
      param_3 = FUN_40149b88((uint)(byte)puVar9[4],(uint)*(byte *)((int)puVar9 + 0x11),puVar9[5],
                             puVar9[6],param_1,param_2);
      puVar7 = *(undefined1 **)(param_1 + 0x34);
      pbVar11 = (byte *)*param_2;
      uVar13 = param_2[1];
      uVar12 = *(uint *)(param_1 + 0x20);
      uVar10 = *(uint *)(param_1 + 0x1c);
      if (puVar7 < *(undefined1 **)(param_1 + 0x30)) {
        puVar8 = *(undefined1 **)(param_1 + 0x30) + (-1 - (int)puVar7);
      }
      else {
        puVar8 = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar7);
      }
      if (param_3 == 0) goto LAB_40148b58;
      if (param_3 == 1) {
        uVar6 = 7;
      }
      else {
        uVar6 = 9;
      }
      goto LAB_40148b4c;
    case 1:
switchD_40148a78_caseD_1:
      for (; uVar10 < puVar9[3]; uVar10 = uVar10 + 8) {
        if (uVar13 == 0) goto LAB_40149084;
        param_3 = 0;
        uVar13 = uVar13 - 1;
        uVar12 = (uint)*pbVar11 << (uVar10 & 0x1f) | uVar12;
        pbVar11 = pbVar11 + 1;
      }
      pbVar14 = (byte *)((*(uint *)(&DAT_4014b07c + puVar9[3] * 4) & uVar12) * 8 + puVar9[2]);
      uVar12 = uVar12 >> (pbVar14[1] & 0x1f);
      uVar10 = uVar10 - pbVar14[1];
      bVar1 = *pbVar14;
      uVar6 = (uint)bVar1;
      if (uVar6 != 0) {
        if ((bVar1 & 0x10) != 0) {
          puVar9[2] = uVar6 & 0xf;
          puVar9[1] = *(uint *)(pbVar14 + 4);
          *puVar9 = 2;
          goto LAB_4014900c;
        }
        if ((bVar1 & 0x40) != 0) {
          if ((bVar1 & 0x20) != 0) {
            *puVar9 = 7;
            goto LAB_4014900c;
          }
          pcVar5 = "invalid literal/length code";
          goto LAB_401490a0;
        }
        puVar9[3] = uVar6;
        goto LAB_40148c34;
      }
      puVar9[2] = *(uint *)(pbVar14 + 4);
      *puVar9 = 6;
      goto LAB_4014900c;
    case 2:
      uVar6 = puVar9[2];
      for (; uVar10 < uVar6; uVar10 = uVar10 + 8) {
        if (uVar13 == 0) goto LAB_40149084;
        param_3 = 0;
        uVar13 = uVar13 - 1;
        uVar12 = (uint)*pbVar11 << (uVar10 & 0x1f) | uVar12;
        pbVar11 = pbVar11 + 1;
      }
      puVar9[1] = (*(uint *)(&DAT_4014b07c + uVar6 * 4) & uVar12) + puVar9[1];
      uVar12 = uVar12 >> (uVar6 & 0x1f);
      uVar10 = uVar10 - uVar6;
      puVar9[3] = (uint)*(byte *)((int)puVar9 + 0x11);
      puVar9[2] = puVar9[6];
      *puVar9 = 3;
    case 3:
      for (; uVar10 < puVar9[3]; uVar10 = uVar10 + 8) {
        if (uVar13 == 0) goto LAB_40149084;
        param_3 = 0;
        uVar13 = uVar13 - 1;
        uVar12 = (uint)*pbVar11 << (uVar10 & 0x1f) | uVar12;
        pbVar11 = pbVar11 + 1;
      }
      pbVar14 = (byte *)((*(uint *)(&DAT_4014b07c + puVar9[3] * 4) & uVar12) * 8 + puVar9[2]);
      uVar12 = uVar12 >> (pbVar14[1] & 0x1f);
      uVar10 = uVar10 - pbVar14[1];
      bVar1 = *pbVar14;
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          pcVar5 = "invalid distance code";
LAB_401490a0:
          *puVar9 = 9;
          param_2[6] = (int)pcVar5;
switchD_40148a78_caseD_9:
          param_3 = -3;
          puVar3 = puVar7;
          goto LAB_40149020;
        }
        puVar9[3] = (uint)bVar1;
LAB_40148c34:
        puVar9[2] = (uint)(pbVar14 + *(int *)(pbVar14 + 4) * 8);
      }
      else {
        puVar9[2] = bVar1 & 0xf;
        uVar6 = 4;
        puVar9[3] = *(uint *)(pbVar14 + 4);
LAB_40148b4c:
        *puVar9 = uVar6;
      }
LAB_4014900c:
      uVar6 = *puVar9;
      break;
    case 4:
      uVar6 = puVar9[2];
      for (; uVar10 < uVar6; uVar10 = uVar10 + 8) {
        if (uVar13 == 0) goto LAB_40149084;
        param_3 = 0;
        uVar13 = uVar13 - 1;
        uVar12 = (uint)*pbVar11 << (uVar10 & 0x1f) | uVar12;
        pbVar11 = pbVar11 + 1;
      }
      puVar9[3] = (*(uint *)(&DAT_4014b07c + uVar6 * 4) & uVar12) + puVar9[3];
      uVar12 = uVar12 >> (uVar6 & 0x1f);
      *puVar9 = 5;
      uVar10 = uVar10 - uVar6;
    case 5:
      puVar3 = *(undefined1 **)(param_1 + 0x28);
      puVar4 = puVar7 + -puVar9[3];
      if (puVar4 < puVar3) {
        do {
          puVar4 = puVar4 + (*(int *)(param_1 + 0x2c) - (int)puVar3);
        } while (puVar4 < puVar3);
      }
      while (puVar9[1] != 0) {
        puVar3 = puVar7;
        if (puVar8 == (undefined1 *)0x0) {
          if (puVar7 == *(undefined1 **)(param_1 + 0x2c)) {
            puVar8 = *(undefined1 **)(param_1 + 0x30);
            puVar3 = *(undefined1 **)(param_1 + 0x28);
            if (puVar8 != puVar3) {
              if (puVar3 < puVar8) {
                puVar8 = puVar8 + (-1 - (int)puVar3);
              }
              else {
                puVar8 = *(undefined1 **)(param_1 + 0x2c) + -(int)puVar3;
              }
              puVar7 = puVar3;
              if (puVar8 != (undefined1 *)0x0) goto LAB_40148ee8;
            }
          }
          *(undefined1 **)(param_1 + 0x34) = puVar7;
          param_3 = FUN_401499f8(param_1,(int)param_2,param_3);
          puVar3 = *(undefined1 **)(param_1 + 0x34);
          puVar7 = *(undefined1 **)(param_1 + 0x30);
          if (puVar3 < puVar7) {
            puVar8 = puVar7 + (-1 - (int)puVar3);
          }
          else {
            puVar8 = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar3);
          }
          if ((puVar3 == *(undefined1 **)(param_1 + 0x2c)) &&
             (puVar2 = *(undefined1 **)(param_1 + 0x28), puVar7 != puVar2)) {
            puVar3 = puVar2;
            if (puVar2 < puVar7) {
              puVar8 = puVar7 + (-1 - (int)puVar2);
            }
            else {
              puVar8 = *(undefined1 **)(param_1 + 0x2c) + -(int)puVar2;
            }
          }
          if (puVar8 == (undefined1 *)0x0) goto LAB_40149020;
        }
LAB_40148ee8:
        param_3 = 0;
        *puVar3 = *puVar4;
        puVar7 = puVar3 + 1;
        puVar4 = puVar4 + 1;
        puVar8 = puVar8 + -1;
        if (puVar4 == *(undefined1 **)(param_1 + 0x2c)) {
          puVar4 = *(undefined1 **)(param_1 + 0x28);
        }
        puVar9[1] = puVar9[1] - 1;
      }
LAB_40149008:
      *puVar9 = 0;
      goto LAB_4014900c;
    case 6:
      if (puVar8 == (undefined1 *)0x0) {
        if (puVar7 == *(undefined1 **)(param_1 + 0x2c)) {
          puVar8 = *(undefined1 **)(param_1 + 0x30);
          puVar3 = *(undefined1 **)(param_1 + 0x28);
          if (puVar8 != puVar3) {
            if (puVar3 < puVar8) {
              puVar8 = puVar8 + (-1 - (int)puVar3);
            }
            else {
              puVar8 = *(undefined1 **)(param_1 + 0x2c) + -(int)puVar3;
            }
            puVar7 = puVar3;
            if (puVar8 != (undefined1 *)0x0) goto LAB_40148ff4;
          }
        }
        *(undefined1 **)(param_1 + 0x34) = puVar7;
        param_3 = FUN_401499f8(param_1,(int)param_2,param_3);
        puVar3 = *(undefined1 **)(param_1 + 0x34);
        puVar7 = *(undefined1 **)(param_1 + 0x30);
        if (puVar3 < puVar7) {
          puVar8 = puVar7 + (-1 - (int)puVar3);
        }
        else {
          puVar8 = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar3);
        }
        if ((puVar3 == *(undefined1 **)(param_1 + 0x2c)) &&
           (puVar4 = *(undefined1 **)(param_1 + 0x28), puVar7 != puVar4)) {
          puVar3 = puVar4;
          if (puVar4 < puVar7) {
            puVar8 = puVar7 + (-1 - (int)puVar4);
          }
          else {
            puVar8 = *(undefined1 **)(param_1 + 0x2c) + -(int)puVar4;
          }
        }
        if (puVar8 == (undefined1 *)0x0) goto LAB_40149020;
      }
LAB_40148ff4:
      param_3 = 0;
      *puVar3 = (char)puVar9[2];
      puVar7 = puVar3 + 1;
      puVar8 = puVar8 + -1;
      goto LAB_40149008;
    case 7:
      if (7 < uVar10) {
        uVar10 = uVar10 - 8;
        uVar13 = uVar13 + 1;
        pbVar11 = pbVar11 + -1;
      }
      *(undefined1 **)(param_1 + 0x34) = puVar7;
      param_3 = FUN_401499f8(param_1,(int)param_2,param_3);
      puVar7 = *(undefined1 **)(param_1 + 0x34);
      if (*(undefined1 **)(param_1 + 0x30) == puVar7) {
        *puVar9 = 8;
        goto switchD_40148a78_caseD_8;
      }
      *(uint *)(param_1 + 0x20) = uVar12;
      *(uint *)(param_1 + 0x1c) = uVar10;
      param_2[1] = uVar13;
      param_2[2] = (int)(pbVar11 + (param_2[2] - *param_2));
      goto LAB_40149040;
    case 8:
switchD_40148a78_caseD_8:
      param_3 = 1;
      puVar3 = puVar7;
      goto LAB_40149020;
    case 9:
      goto switchD_40148a78_caseD_9;
    }
  }
  param_3 = -2;
LAB_40149020:
  *(uint *)(param_1 + 0x20) = uVar12;
  *(uint *)(param_1 + 0x1c) = uVar10;
  param_2[1] = uVar13;
  puVar7 = puVar3;
LAB_4014902c:
  param_2[2] = (int)(pbVar11 + (param_2[2] - *param_2));
LAB_40149040:
  *param_2 = (int)pbVar11;
  *(undefined1 **)(param_1 + 0x34) = puVar7;
  FUN_401499f8(param_1,(int)param_2,param_3);
  return;
LAB_40149084:
  *(uint *)(param_1 + 0x20) = uVar12;
  *(uint *)(param_1 + 0x1c) = uVar10;
  param_2[1] = 0;
  goto LAB_4014902c;
}



/* 40149138 FUN_40149138 */

/* Boundary evidence: original MIPS .pdata 40149138..40149163. Semantic name remains unreviewed. */

void FUN_40149138(undefined4 param_1,int param_2)

{
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return;
}



/* 40149164 FUN_40149164 */

/* Boundary evidence: original MIPS .pdata 40149164..401496bb. Semantic name remains unreviewed. */

undefined4
FUN_40149164(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,
            uint *param_7,int param_8,uint *param_9,uint *param_10)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint *puVar23;
  int iVar24;
  uint uVar25;
  undefined4 local_100;
  uint local_fc;
  uint local_e8 [48];
  
  local_e8[0] = 0;
  local_e8[1] = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  local_e8[6] = 0;
  local_e8[7] = 0;
  local_e8[8] = 0;
  local_e8[9] = 0;
  local_e8[10] = 0;
  local_e8[0xb] = 0;
  local_e8[0xc] = 0;
  local_e8[0xd] = 0;
  local_e8[0xe] = 0;
  local_e8[0xf] = 0;
  piVar12 = param_1;
  uVar17 = param_2;
  do {
    local_e8[*piVar12] = local_e8[*piVar12] + 1;
    uVar17 = uVar17 - 1;
    piVar12 = piVar12 + 1;
  } while (uVar17 != 0);
  if (local_e8[0] == param_2) {
    *param_6 = 0;
    *param_7 = 0;
  }
  else {
    uVar17 = 1;
    puVar7 = local_e8;
    do {
      puVar7 = puVar7 + 1;
      if (*puVar7 != 0) break;
      uVar17 = uVar17 + 1;
    } while (uVar17 < 0x10);
    uVar19 = *param_7;
    if (*param_7 < uVar17) {
      uVar19 = uVar17;
    }
    uVar18 = 0xf;
    puVar7 = local_e8 + 0xf;
    do {
      if (*puVar7 != 0) break;
      uVar18 = uVar18 - 1;
      puVar7 = puVar7 + -1;
    } while (uVar18 != 0);
    if (uVar18 < uVar19) {
      uVar19 = uVar18;
    }
    *param_7 = uVar19;
    iVar13 = 1 << (uVar17 & 0x1f);
    if (uVar17 < uVar18) {
      puVar7 = local_e8 + uVar17;
      uVar8 = uVar17;
      do {
        uVar5 = *puVar7;
        if ((int)(iVar13 - uVar5) < 0) {
          return 0xfffffffd;
        }
        uVar8 = uVar8 + 1;
        puVar7 = puVar7 + 1;
        iVar13 = (iVar13 - uVar5) * 2;
      } while (uVar8 < uVar18);
    }
    uVar8 = local_e8[uVar18];
    iVar13 = iVar13 - uVar8;
    if (iVar13 < 0) {
      return 0xfffffffd;
    }
    local_e8[uVar18] = uVar8 + iVar13;
    iVar20 = 0;
    iVar10 = uVar18 - 1;
    local_e8[0x11] = 0;
    if (iVar10 != 0) {
      iVar14 = 0;
      do {
        iVar20 = *(int *)((int)local_e8 + iVar14 + 4) + iVar20;
        *(int *)((int)local_e8 + iVar14 + 0x48) = iVar20;
        iVar10 = iVar10 + -1;
        iVar14 = iVar14 + 4;
      } while (iVar10 != 0);
    }
    uVar8 = 0;
    do {
      iVar10 = *param_1;
      param_1 = param_1 + 1;
      if (iVar10 != 0) {
        uVar5 = local_e8[iVar10 + 0x10];
        param_10[uVar5] = uVar8;
        local_e8[iVar10 + 0x10] = uVar5 + 1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < param_2);
    uVar6 = local_e8[uVar18 + 0x10];
    uVar4 = 0;
    local_e8[0x10] = 0;
    iVar10 = -1;
    uVar8 = -uVar19;
    local_e8[0x20] = 0;
    uVar22 = 0;
    uVar5 = 0;
    if ((int)uVar17 <= (int)uVar18) {
      uVar25 = uVar17 - 1;
      puVar23 = local_e8 + uVar17;
      puVar7 = param_10;
      do {
        uVar9 = *puVar23;
        uVar1 = local_100;
        while (local_100 = uVar1, uVar9 != 0) {
          local_100._2_2_ = (undefined2)((uint)uVar1 >> 0x10);
          iVar20 = uVar8 + uVar19;
          uVar3 = uVar9 - 1;
          if (iVar20 < (int)uVar17) {
            uVar2 = uVar8 - uVar19;
            iVar14 = iVar10;
            do {
              uVar8 = uVar8 + uVar19;
              iVar10 = iVar14 + 1;
              uVar2 = uVar2 + uVar19;
              iVar20 = iVar20 + uVar19;
              uVar5 = uVar18 - uVar8;
              if (uVar19 < uVar18 - uVar8) {
                uVar5 = uVar19;
              }
              uVar11 = uVar17 - uVar8;
              uVar22 = 1 << (uVar11 & 0x1f);
              if ((uVar9 < uVar22) &&
                 (iVar24 = (uVar22 - uVar3) + -1, puVar16 = puVar23, uVar11 < uVar5)) {
                while (uVar11 = uVar11 + 1, uVar11 < uVar5) {
                  uVar22 = puVar16[1];
                  if ((uint)(iVar24 * 2) <= uVar22) break;
                  iVar24 = iVar24 * 2 - uVar22;
                  puVar16 = puVar16 + 1;
                }
              }
              uVar21 = *param_9;
              uVar5 = 1 << (uVar11 & 0x1f);
              if (0x5a0 < uVar21) {
                return 0xfffffffd;
              }
              if (0x5a0 < uVar5) {
                return 0xfffffffd;
              }
              if (0x5a0 < uVar21 + uVar5) {
                return 0xfffffffd;
              }
              uVar22 = uVar21 * 8 + param_8;
              local_e8[iVar14 + 0x21] = uVar22;
              *param_9 = uVar21 + uVar5;
              if (iVar10 == 0) {
                *param_6 = uVar22;
              }
              else {
                local_e8[iVar14 + 0x11] = uVar4;
                uVar21 = uVar4 >> (uVar2 & 0x1f);
                local_fc = ((int)(uVar22 - local_e8[iVar14 + 0x20]) >> 3) - uVar21;
                puVar15 = (undefined4 *)(uVar21 * 8 + local_e8[iVar14 + 0x20]);
                local_100._0_2_ = CONCAT11((char)uVar19,(char)uVar11);
                *puVar15 = local_100;
                puVar15[1] = local_fc;
              }
              iVar14 = iVar10;
            } while (iVar20 < (int)uVar17);
          }
          if (puVar7 < param_10 + uVar6) {
            local_fc = *puVar7;
            if (local_fc < param_3) {
              local_100._0_1_ = '\0';
              if (0xff < local_fc) {
                local_100._0_1_ = '`';
              }
            }
            else {
              iVar20 = (local_fc - param_3) * 4;
              local_100._0_1_ = (char)*(undefined4 *)(iVar20 + param_5) + 'P';
              local_fc = *(uint *)(iVar20 + param_4);
            }
            puVar7 = puVar7 + 1;
          }
          else {
            local_100._0_1_ = -0x40;
          }
          local_100 = CONCAT31(CONCAT21(local_100._2_2_,(char)uVar17 - (char)uVar8),(char)local_100)
          ;
          uVar9 = uVar4 >> (uVar8 & 0x1f);
          iVar20 = 1 << (uVar17 - uVar8 & 0x1f);
          if (uVar9 < uVar5) {
            puVar15 = (undefined4 *)(uVar9 * 8 + uVar22);
            do {
              uVar9 = iVar20 + uVar9;
              *puVar15 = local_100;
              puVar15[1] = local_fc;
              puVar15 = puVar15 + iVar20 * 2;
            } while (uVar9 < uVar5);
          }
          uVar9 = 1 << (uVar25 & 0x1f);
          uVar2 = uVar9 & uVar4;
          while (uVar2 != 0) {
            uVar4 = uVar9 ^ uVar4;
            uVar9 = uVar9 >> 1;
            uVar2 = uVar9 & uVar4;
          }
          uVar4 = uVar9 ^ uVar4;
          for (puVar16 = local_e8 + iVar10 + 0x10; uVar9 = uVar3, uVar1 = local_100,
              ((1 << (uVar8 & 0x1f)) - 1U & uVar4) != *puVar16; puVar16 = puVar16 + -1) {
            iVar10 = iVar10 + -1;
            uVar8 = uVar8 - uVar19;
          }
        }
        uVar17 = uVar17 + 1;
        puVar23 = puVar23 + 1;
        uVar25 = uVar25 + 1;
      } while ((int)uVar17 <= (int)uVar18);
    }
    if ((iVar13 != 0) && (uVar18 != 1)) {
      return 0xfffffffb;
    }
  }
  return 0;
}



/* 401496bc FUN_401496bc */

/* Boundary evidence: original MIPS .pdata 401496bc..401497cb. Semantic name remains unreviewed. */

int FUN_401496bc(int *param_1,uint *param_2,uint *param_3,int param_4,int param_5)

{
  uint *puVar1;
  int iVar2;
  uint local_28 [2];
  
  local_28[0] = 0;
  puVar1 = (uint *)(**(code **)(param_5 + 0x20))(*(undefined4 *)(param_5 + 0x28),0x13,4);
  if (puVar1 == (uint *)0x0) {
    iVar2 = -4;
  }
  else {
    iVar2 = FUN_40149164(param_1,0x13,0x13,0,0,param_3,param_2,param_4,local_28,puVar1);
    if (iVar2 == -3) {
      *(char **)(param_5 + 0x18) = "oversubscribed dynamic bit lengths tree";
    }
    else if ((iVar2 == -5) || (*param_2 == 0)) {
      *(char **)(param_5 + 0x18) = "incomplete dynamic bit lengths tree";
      iVar2 = -3;
    }
    (**(code **)(param_5 + 0x24))(*(undefined4 *)(param_5 + 0x28),puVar1);
  }
  return iVar2;
}



/* 401497cc FUN_401497cc */

/* Boundary evidence: original MIPS .pdata 401497cc..401499c3. Semantic name remains unreviewed. */

int FUN_401497cc(uint param_1,uint param_2,int *param_3,uint *param_4,uint *param_5,uint *param_6,
                uint *param_7,int param_8,int param_9)

{
  uint *puVar1;
  int iVar2;
  char *pcVar3;
  uint local_30 [2];
  
  local_30[0] = 0;
  puVar1 = (uint *)(**(code **)(param_9 + 0x20))(*(undefined4 *)(param_9 + 0x28),0x120,4);
  if (puVar1 == (uint *)0x0) {
    return -4;
  }
  iVar2 = FUN_40149164(param_3,param_1,0x101,0x40141ccc,0x40141d48,param_6,param_4,param_8,local_30,
                       puVar1);
  if (iVar2 == 0) {
    if (*param_4 == 0) {
LAB_40149970:
      pcVar3 = "incomplete literal/length tree";
    }
    else {
      iVar2 = FUN_40149164(param_3 + param_1,param_2,0,0x40141dc4,0x40141e3c,param_7,param_5,param_8
                           ,local_30,puVar1);
      if (iVar2 == 0) {
        if ((*param_5 != 0) || (param_1 < 0x102)) {
          (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),puVar1);
          return 0;
        }
LAB_40149944:
        pcVar3 = "empty distance tree with lengths";
      }
      else {
        if (iVar2 == -3) {
          pcVar3 = "oversubscribed distance tree";
          goto LAB_4014997c;
        }
        if (iVar2 != -5) {
          if (iVar2 == -4) goto LAB_40149980;
          goto LAB_40149944;
        }
        pcVar3 = "incomplete distance tree";
      }
    }
    iVar2 = -3;
  }
  else {
    if (iVar2 != -3) {
      if (iVar2 == -4) goto LAB_40149980;
      goto LAB_40149970;
    }
    pcVar3 = "oversubscribed literal/length tree";
  }
LAB_4014997c:
  *(char **)(param_9 + 0x18) = pcVar3;
LAB_40149980:
  (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),puVar1);
  return iVar2;
}



/* 401499c4 FUN_401499c4 */

undefined4
FUN_401499c4(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = DAT_4014b078;
  *param_1 = DAT_4014b074;
  *param_2 = uVar1;
  *param_3 = &DAT_40141eb4;
  *param_4 = &DAT_40142eb4;
  return 0;
}



/* 401499f8 FUN_401499f8 */

/* Boundary evidence: original MIPS .pdata 401499f8..40149b87. Semantic name remains unreviewed. */

int FUN_401499f8(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  void *_Src;
  void *pvVar6;
  
  _Src = *(void **)(param_1 + 0x30);
  pvVar3 = *(void **)(param_1 + 0x34);
  pvVar6 = *(void **)(param_2 + 0xc);
  if (pvVar3 < _Src) {
    pvVar3 = *(void **)(param_1 + 0x2c);
  }
  uVar4 = *(uint *)(param_2 + 0x10);
  uVar5 = (int)pvVar3 - (int)_Src;
  if (uVar4 < (uint)((int)pvVar3 - (int)_Src)) {
    uVar5 = uVar4;
  }
  if ((uVar5 != 0) && (param_3 == -5)) {
    param_3 = 0;
  }
  *(uint *)(param_2 + 0x10) = uVar4 - uVar5;
  *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar5;
  if (*(code **)(param_1 + 0x38) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x3c),_Src,uVar5);
    *(undefined4 *)(param_1 + 0x3c) = uVar1;
    *(undefined4 *)(param_2 + 0x30) = uVar1;
  }
  memcpy(pvVar6,_Src,uVar5);
  iVar2 = uVar5 + (int)_Src;
  pvVar6 = (void *)(uVar5 + (int)pvVar6);
  if (iVar2 == *(int *)(param_1 + 0x2c)) {
    pvVar3 = *(void **)(param_1 + 0x28);
    if (*(int *)(param_1 + 0x34) == *(int *)(param_1 + 0x2c)) {
      *(void **)(param_1 + 0x34) = pvVar3;
    }
    uVar4 = *(uint *)(param_2 + 0x10);
    uVar5 = *(int *)(param_1 + 0x34) - (int)pvVar3;
    if (uVar4 < uVar5) {
      uVar5 = uVar4;
    }
    if ((uVar5 != 0) && (param_3 == -5)) {
      param_3 = 0;
    }
    *(uint *)(param_2 + 0x10) = uVar4 - uVar5;
    *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar5;
    if (*(code **)(param_1 + 0x38) != (code *)0x0) {
      uVar1 = (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x3c),pvVar3,uVar5);
      *(undefined4 *)(param_1 + 0x3c) = uVar1;
      *(undefined4 *)(param_2 + 0x30) = uVar1;
    }
    memcpy(pvVar6,pvVar3,uVar5);
    pvVar6 = (void *)(uVar5 + (int)pvVar6);
    iVar2 = uVar5 + (int)pvVar3;
  }
  *(void **)(param_2 + 0xc) = pvVar6;
  *(int *)(param_1 + 0x30) = iVar2;
  return param_3;
}



/* 40149b88 FUN_40149b88 */

/* Boundary evidence: original MIPS .pdata 40149b88..4014a073. Semantic name remains unreviewed. */

undefined4 FUN_40149b88(int param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  int iVar13;
  uint uVar14;
  byte *pbVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  undefined1 *puVar19;
  
  puVar19 = *(undefined1 **)(param_5 + 0x34);
  pbVar15 = (byte *)*param_6;
  uVar6 = param_6[1];
  uVar3 = *(uint *)(param_5 + 0x20);
  uVar14 = *(uint *)(param_5 + 0x1c);
  if (puVar19 < *(undefined1 **)(param_5 + 0x30)) {
    puVar16 = *(undefined1 **)(param_5 + 0x30) + (-1 - (int)puVar19);
  }
  else {
    puVar16 = (undefined1 *)(*(int *)(param_5 + 0x2c) - (int)puVar19);
  }
  uVar17 = *(uint *)(&DAT_4014b07c + param_1 * 4);
  uVar18 = *(uint *)(&DAT_4014b07c + param_2 * 4);
  do {
    for (; uVar14 < 0x14; uVar14 = uVar14 + 8) {
      uVar6 = uVar6 - 1;
      uVar3 = (uint)*pbVar15 << (uVar14 & 0x1f) | uVar3;
      pbVar15 = pbVar15 + 1;
    }
    pbVar5 = (byte *)((uVar17 & uVar3) * 8 + param_3);
    bVar1 = *pbVar5;
    uVar10 = (uint)bVar1;
    uVar7 = (uint)pbVar5[1];
    if (uVar10 == 0) {
      uVar3 = uVar3 >> (uVar7 & 0x1f);
      uVar14 = uVar14 - uVar7;
      *puVar19 = (char)*(undefined4 *)(pbVar5 + 4);
LAB_40149c68:
      puVar19 = puVar19 + 1;
      puVar16 = puVar16 + -1;
    }
    else {
      uVar3 = uVar3 >> (uVar7 & 0x1f);
      uVar14 = uVar14 - uVar7;
      while ((bVar1 & 0x10) == 0) {
        if ((uVar10 & 0x40) != 0) {
          if ((uVar10 & 0x20) != 0) {
            uVar17 = param_6[1] - uVar6;
            if (uVar14 >> 3 < param_6[1] - uVar6) {
              uVar17 = uVar14 >> 3;
            }
            uVar4 = 1;
            goto LAB_4014a044;
          }
          param_6[6] = (int)"invalid literal/length code";
          uVar17 = param_6[1] - uVar6;
          if (uVar14 >> 3 < param_6[1] - uVar6) {
            uVar17 = uVar14 >> 3;
          }
          *(uint *)(param_5 + 0x20) = uVar3;
          *(uint *)(param_5 + 0x1c) = uVar14 + uVar17 * -8;
          iVar13 = (int)pbVar15 - uVar17;
          uVar4 = 0xfffffffd;
          param_6[2] = (param_6[2] - *param_6) + iVar13;
          goto LAB_40149f5c;
        }
        pbVar5 = pbVar5 + ((*(uint *)(&DAT_4014b07c + uVar10 * 4) & uVar3) + *(int *)(pbVar5 + 4)) *
                          8;
        bVar1 = *pbVar5;
        uVar10 = (uint)bVar1;
        uVar7 = (uint)pbVar5[1];
        if (uVar10 == 0) {
          uVar3 = uVar3 >> (uVar7 & 0x1f);
          uVar14 = uVar14 - uVar7;
          *puVar19 = (char)*(undefined4 *)(pbVar5 + 4);
          goto LAB_40149c68;
        }
        uVar3 = uVar3 >> (uVar7 & 0x1f);
        uVar14 = uVar14 - uVar7;
      }
      uVar10 = uVar10 & 0xf;
      uVar7 = (*(uint *)(&DAT_4014b07c + uVar10 * 4) & uVar3) + *(int *)(pbVar5 + 4);
      uVar3 = uVar3 >> uVar10;
      for (uVar14 = uVar14 - uVar10; uVar14 < 0xf; uVar14 = uVar14 + 8) {
        uVar6 = uVar6 - 1;
        uVar3 = (uint)*pbVar15 << (uVar14 & 0x1f) | uVar3;
        pbVar15 = pbVar15 + 1;
      }
      pbVar5 = (byte *)((uVar18 & uVar3) * 8 + param_4);
      uVar3 = uVar3 >> (pbVar5[1] & 0x1f);
      uVar14 = uVar14 - pbVar5[1];
      bVar1 = *pbVar5;
      while ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          param_6[6] = (int)"invalid distance code";
          uVar17 = param_6[1] - uVar6;
          if (uVar14 >> 3 < param_6[1] - uVar6) {
            uVar17 = uVar14 >> 3;
          }
          uVar4 = 0xfffffffd;
LAB_4014a044:
          *(uint *)(param_5 + 0x20) = uVar3;
          *(uint *)(param_5 + 0x1c) = uVar14 + uVar17 * -8;
          iVar13 = (int)pbVar15 - uVar17;
          iVar9 = uVar17 + uVar6;
          param_6[2] = (param_6[2] - *param_6) + iVar13;
          goto LAB_40149f60;
        }
        pbVar5 = pbVar5 + ((*(uint *)(&DAT_4014b07c + (uint)bVar1 * 4) & uVar3) +
                          *(int *)(pbVar5 + 4)) * 8;
        uVar3 = uVar3 >> (pbVar5[1] & 0x1f);
        uVar14 = uVar14 - pbVar5[1];
        bVar1 = *pbVar5;
      }
      uVar10 = bVar1 & 0xf;
      for (; uVar14 < uVar10; uVar14 = uVar14 + 8) {
        uVar6 = uVar6 - 1;
        uVar3 = (uint)*pbVar15 << (uVar14 & 0x1f) | uVar3;
        pbVar15 = pbVar15 + 1;
      }
      puVar8 = *(undefined1 **)(param_5 + 0x28);
      puVar11 = puVar19 + -((*(uint *)(&DAT_4014b07c + uVar10 * 4) & uVar3) + *(int *)(pbVar5 + 4));
      uVar3 = uVar3 >> uVar10;
      uVar14 = uVar14 - uVar10;
      puVar16 = puVar16 + -uVar7;
      if (puVar11 < puVar8) {
        do {
          puVar11 = puVar11 + (*(int *)(param_5 + 0x2c) - (int)puVar8);
        } while (puVar11 < puVar8);
        uVar10 = *(int *)(param_5 + 0x2c) - (int)puVar11;
        if (uVar10 < uVar7) {
          iVar13 = uVar7 - uVar10;
          do {
            uVar2 = *puVar11;
            puVar11 = puVar11 + 1;
            *puVar19 = uVar2;
            uVar10 = uVar10 - 1;
            puVar19 = puVar19 + 1;
          } while (uVar10 != 0);
          puVar8 = *(undefined1 **)(param_5 + 0x28);
          do {
            uVar2 = *puVar8;
            puVar8 = puVar8 + 1;
            *puVar19 = uVar2;
            iVar13 = iVar13 + -1;
            puVar19 = puVar19 + 1;
          } while (iVar13 != 0);
        }
        else {
          *puVar19 = *puVar11;
          puVar8 = puVar19 + 1;
          puVar19 = puVar19 + 2;
          puVar12 = puVar11 + 2;
          iVar13 = uVar7 - 2;
          *puVar8 = puVar11[1];
          do {
            uVar2 = *puVar12;
            puVar12 = puVar12 + 1;
            *puVar19 = uVar2;
            iVar13 = iVar13 + -1;
            puVar19 = puVar19 + 1;
          } while (iVar13 != 0);
        }
      }
      else {
        *puVar19 = *puVar11;
        puVar8 = puVar19 + 1;
        puVar19 = puVar19 + 2;
        puVar12 = puVar11 + 2;
        iVar13 = uVar7 - 2;
        *puVar8 = puVar11[1];
        do {
          uVar2 = *puVar12;
          puVar12 = puVar12 + 1;
          *puVar19 = uVar2;
          iVar13 = iVar13 + -1;
          puVar19 = puVar19 + 1;
        } while (iVar13 != 0);
      }
    }
  } while (((undefined1 *)0x101 < puVar16) && (9 < uVar6));
  uVar17 = param_6[1] - uVar6;
  if (uVar14 >> 3 < param_6[1] - uVar6) {
    uVar17 = uVar14 >> 3;
  }
  *(uint *)(param_5 + 0x20) = uVar3;
  *(uint *)(param_5 + 0x1c) = uVar14 + uVar17 * -8;
  iVar13 = (int)pbVar15 - uVar17;
  uVar4 = 0;
  param_6[2] = (param_6[2] - *param_6) + iVar13;
LAB_40149f5c:
  iVar9 = uVar17 + uVar6;
LAB_40149f60:
  param_6[1] = iVar9;
  *param_6 = iVar13;
  *(undefined1 **)(param_5 + 0x34) = puVar19;
  return uVar4;
}



/* 4014a074 FUN_4014a074 */

/* Boundary evidence: original MIPS .pdata 4014a074..4014a09f. Semantic name remains unreviewed. */

undefined4 FUN_4014a074(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 4014a0a0 FUN_4014a0a0 */

/* Boundary evidence: original MIPS .pdata 4014a0a0..4014a1db. Semantic name remains unreviewed. */

int FUN_4014a0a0(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_4014b4dc != (code *)0x0) {
      iVar2 = (*DAT_4014b4dc)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_4014a150;
    FUN_4014a534();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_4014a074(param_1,param_2);
  }
LAB_4014a150:
  if (((param_2 == 0) && (FUN_4014a4bc(), iVar1 != 0)) && (DAT_4014b4dc != (code *)0x0)) {
    iVar1 = (*DAT_4014b4dc)(param_1,0,param_3);
  }
  return iVar1;
}



/* 4014a1dc FUN_4014a1dc */

/* Boundary evidence: original MIPS .pdata 4014a1dc..4014a207. Semantic name remains unreviewed. */

void FUN_4014a1dc(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 4014a208 entry */

/* Boundary evidence: original MIPS .pdata 4014a208..4014a25f. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_4014a260();
  }
  FUN_4014a0a0(param_1,param_2,param_3);
  return;
}



/* 4014a260 FUN_4014a260 */

/* Boundary evidence: original MIPS .pdata 4014a260..4014a2d3. Semantic name remains unreviewed. */

void FUN_4014a260(void)

{
  uint uVar1;
  
  if ((DAT_4014b0c0 == 0) || (DAT_4014b0c0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4014b0c0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4014b0c0 == 0) {
      DAT_4014b0c0 = 0xb064;
    }
  }
  DAT_4014b0c4 = ~DAT_4014b0c0;
  return;
}



/* 4014a2d4 FUN_4014a2d4 */

/* Boundary evidence: original MIPS .pdata 4014a2d4..4014a327. Semantic name remains unreviewed. */

void FUN_4014a2d4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_4014a354(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 4014a328 FUN_4014a328 */

/* Boundary evidence: original MIPS .pdata 4014a328..4014a353. Semantic name remains unreviewed. */

undefined4 FUN_4014a328(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_4014a2d4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 4014a354 FUN_4014a354 */

/* Boundary evidence: original MIPS .pdata 4014a354..4014a39b. Semantic name remains unreviewed. */

void FUN_4014a354(uint param_1)

{
  if ((param_1 == DAT_4014b0c0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 4014a39c FUN_4014a39c */

/* Boundary evidence: original MIPS .pdata 4014a39c..4014a4bb. Semantic name remains unreviewed. */

void FUN_4014a39c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4014b4cc = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4014b4d4;
    if (DAT_4014b4d4 != (undefined4 *)0x0) {
      while (DAT_4014b4d0 = DAT_4014b4d0 + -1, _Memory <= DAT_4014b4d0) {
        if ((code *)*DAT_4014b4d0 != (code *)0x0) {
          (*(code *)*DAT_4014b4d0)();
          _Memory = DAT_4014b4d4;
        }
      }
      free(_Memory);
      DAT_4014b4d0 = (undefined4 *)0x0;
      DAT_4014b4d4 = (undefined4 *)0x0;
    }
    FUN_4014a4e0((undefined4 *)&DAT_40141010,(undefined4 *)&DAT_40141014);
  }
  FUN_4014a4e0((undefined4 *)&DAT_40141018,(undefined4 *)&DAT_4014101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4014b4d8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 4014a4bc FUN_4014a4bc */

/* Boundary evidence: original MIPS .pdata 4014a4bc..4014a4df. Semantic name remains unreviewed. */

void FUN_4014a4bc(void)

{
  FUN_4014a39c(0,0,1);
  return;
}



/* 4014a4e0 FUN_4014a4e0 */

/* Boundary evidence: original MIPS .pdata 4014a4e0..4014a533. Semantic name remains unreviewed. */

void FUN_4014a4e0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4014a534 FUN_4014a534 */

/* Boundary evidence: original MIPS .pdata 4014a534..4014a56f. Semantic name remains unreviewed. */

void FUN_4014a534(void)

{
  FUN_4014a4e0((undefined4 *)&DAT_40141008,(undefined4 *)&DAT_4014100c);
  FUN_4014a4e0((undefined4 *)&DAT_40141000,(undefined4 *)&DAT_40141004);
  return;
}


