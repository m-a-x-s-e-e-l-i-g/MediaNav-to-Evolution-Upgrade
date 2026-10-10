/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40bf1000 FUN_40bf1000 */

void FUN_40bf1000(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[3] = param_2;
  param_1[2] = param_2;
  param_1[4] = param_3;
  return;
}



/* 40bf1028 FUN_40bf1028 */

uint FUN_40bf1028(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = *param_1;
  uVar3 = param_1[1];
  uVar2 = uVar3 + param_2;
  if ((iVar5 + 4 < param_1[4]) || (uVar1 = 0xffffffff, (int)(iVar5 * 8 + uVar2) <= param_1[4] << 3))
  {
    pbVar4 = (byte *)param_1[3];
    uVar1 = (uint)(*pbVar4 >> (uVar3 & 0x1f));
    if (((8 < (int)uVar2) &&
        (((uVar1 = (uint)pbVar4[1] << (8 - uVar3 & 0x1f) | uVar1, 0x10 < (int)uVar2 &&
          (uVar1 = (uint)pbVar4[2] << (0x10 - uVar3 & 0x1f) | uVar1, 0x18 < (int)uVar2)) &&
         (uVar1 = (uint)pbVar4[3] << (0x18 - uVar3 & 0x1f) | uVar1, 0x20 < (int)uVar2)))) &&
       (uVar3 != 0)) {
      uVar1 = (uint)pbVar4[4] << (0x20 - uVar3 & 0x1f) | uVar1;
    }
    uVar1 = uVar1 & *(uint *)(&DAT_40c03020 + param_2 * 4);
  }
  uVar3 = uVar2;
  if ((int)uVar2 < 0) {
    uVar3 = uVar2 + 7;
  }
  param_1[3] = ((int)uVar3 >> 3) + param_1[3];
  *param_1 = ((int)uVar3 >> 3) + iVar5;
  param_1[1] = uVar2 & 7;
  return uVar1;
}



/* 40bf112c FUN_40bf112c */

/* Boundary evidence: original MIPS .pdata 40bf112c..40bf14af. Semantic name remains unreviewed. */

undefined4 FUN_40bf112c(int *param_1,uint *param_2,undefined4 param_3,va_list param_4)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  param_2[0xc] = 1;
  uVar1 = FUN_40bf1028(param_1,0x18);
  if (uVar1 == 0x564342) {
    uVar1 = FUN_40bf1028(param_1,0x10);
    *param_2 = uVar1;
    uVar1 = FUN_40bf1028(param_1,0x18);
    param_2[1] = uVar1;
    if (uVar1 != 0xffffffff) {
      uVar1 = FUN_40bf1028(param_1,1);
      if (uVar1 == 0) {
        pvVar2 = malloc(param_2[1] << 2);
        param_2[2] = (uint)pvVar2;
        uVar1 = FUN_40bf1028(param_1,1);
        iVar9 = 0;
        if (uVar1 == 0) {
          if (0 < (int)param_2[1]) {
            iVar3 = 0;
            do {
              uVar1 = FUN_40bf1028(param_1,5);
              if (uVar1 == 0xffffffff) goto LAB_40bf147c;
              *(uint *)(iVar3 + param_2[2]) = uVar1 + 1;
              iVar9 = iVar9 + 1;
              iVar3 = iVar3 + 4;
            } while (iVar9 < (int)param_2[1]);
          }
        }
        else if (0 < (int)param_2[1]) {
          iVar3 = 0;
          do {
            uVar1 = FUN_40bf1028(param_1,1);
            if (uVar1 == 0) {
              *(undefined4 *)(iVar3 + param_2[2]) = 0;
            }
            else {
              uVar1 = FUN_40bf1028(param_1,5);
              if (uVar1 == 0xffffffff) goto LAB_40bf147c;
              *(uint *)(iVar3 + param_2[2]) = uVar1 + 1;
            }
            iVar9 = iVar9 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar9 < (int)param_2[1]);
        }
      }
      else {
        if (uVar1 != 1) {
          return 0xffffffff;
        }
        uVar1 = FUN_40bf1028(param_1,5);
        pvVar2 = malloc(param_2[1] << 2);
        param_2[2] = (uint)pvVar2;
        iVar9 = 0;
        if (0 < (int)param_2[1]) {
          do {
            uVar1 = uVar1 + 1;
            iVar3 = FUN_40bfbca8(param_2[1] - iVar9);
            uVar4 = FUN_40bf1028(param_1,iVar3);
            if (uVar4 == 0xffffffff) goto LAB_40bf147c;
            iVar3 = 0;
            if (0 < (int)uVar4) {
              iVar8 = iVar9 << 2;
              do {
                if ((int)param_2[1] <= iVar9) break;
                iVar3 = iVar3 + 1;
                *(uint *)(iVar8 + param_2[2]) = uVar1;
                iVar9 = iVar9 + 1;
                iVar8 = iVar8 + 4;
              } while (iVar3 < (int)uVar4);
            }
          } while (iVar9 < (int)param_2[1]);
        }
      }
      uVar1 = FUN_40bf1028(param_1,4);
      param_2[3] = uVar1;
      if (uVar1 == 0) {
        return 0;
      }
      if ((0 < (int)uVar1) && ((int)uVar1 < 3)) {
        uVar1 = FUN_40bf1028(param_1,0x20);
        param_2[4] = uVar1;
        uVar1 = FUN_40bf1028(param_1,0x20);
        param_2[5] = uVar1;
        uVar1 = FUN_40bf1028(param_1,4);
        param_2[6] = uVar1 + 1;
        uVar6 = 1;
        uVar1 = FUN_40bf1028(param_1,1);
        param_2[7] = uVar1;
        uVar1 = 0;
        if (param_2[3] == 1) {
          uVar1 = FUN_40bfbcc4((int *)param_2,uVar6,param_3,param_4);
        }
        else if (param_2[3] == 2) {
          uVar1 = *param_2 * param_2[1];
        }
        pvVar2 = malloc(uVar1 * 4);
        param_2[8] = (uint)pvVar2;
        if (0 < (int)uVar1) {
          iVar9 = 0;
          uVar4 = uVar1;
          do {
            uVar5 = FUN_40bf1028(param_1,param_2[6]);
            puVar7 = (uint *)(iVar9 + param_2[8]);
            iVar9 = iVar9 + 4;
            uVar4 = uVar4 - 1;
            *puVar7 = uVar5;
          } while (uVar4 != 0);
        }
        if (uVar1 == 0) {
          return 0;
        }
        if (*(int *)(uVar1 * 4 + param_2[8] + -4) != -1) {
          return 0;
        }
      }
    }
  }
LAB_40bf147c:
  FUN_40bfbedc(param_2);
  return 0xffffffff;
}



/* 40bf14b0 FUN_40bf14b0 */

/* Boundary evidence: original MIPS .pdata 40bf14b0..40bf1787. Semantic name remains unreviewed. */

undefined4 FUN_40bf14b0(char *param_1,uint *param_2)

{
  char cVar1;
  ulonglong uVar2;
  longlong lVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  
  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  *param_2 = 0;
  pcVar4 = pcVar4 + (-1 - (int)param_1);
  param_2[1] = 0;
  uVar10 = 1;
  iVar9 = 0;
  if (0 < (int)pcVar4) {
    do {
      pcVar4 = pcVar4 + -1;
      iVar5 = (int)param_1[(int)pcVar4];
      if (iVar5 == 0x2e) {
        uVar6 = param_2[1];
        if (((0 < (int)uVar6) || (((uVar6 == 0 && (10000000 < *param_2)) || (0 < iVar9)))) ||
           ((iVar9 == 0 && (10000000 < uVar10)))) {
          return 0;
        }
        lVar3 = (ulonglong)*param_2 * 10000000;
        uVar7 = (uint)lVar3;
        uVar6 = uVar6 * 10000000 + (int)((ulonglong)lVar3 >> 0x20);
        *param_2 = uVar7;
        param_2[1] = uVar6;
        uVar11 = __ll_div(uVar7,uVar6,uVar10,iVar9);
        *(undefined8 *)param_2 = uVar11;
        iVar9 = 0;
        uVar10 = 10000000;
      }
      else if (iVar5 == 0x3a) {
        if ((iVar9 < 1) && ((iVar9 != 0 || (uVar10 < 10000000)))) {
          uVar10 = *param_2;
          iVar9 = 0;
          *param_2 = (uint)((ulonglong)uVar10 * 10000000);
          param_2[1] = param_2[1] * 10000000 + (int)((ulonglong)uVar10 * 10000000 >> 0x20);
          uVar10 = 600000000;
        }
        else if ((uVar10 == 1000000000) && (iVar9 == 0)) {
          iVar9 = 0;
          uVar10 = 600000000;
        }
        else {
          if (uVar10 != 0xf8475800) {
            return 0;
          }
          if (iVar9 != 0xd) {
            return 0;
          }
          iVar9 = 8;
          uVar10 = 0x61c46800;
        }
      }
      else {
        if (iVar5 < 0x30) {
          return 0;
        }
        if (0x39 < iVar5) {
          return 0;
        }
        uVar7 = iVar5 - 0x30;
        uVar6 = (uint)((ulonglong)uVar7 * (ulonglong)uVar10);
        uVar8 = uVar6 + *param_2;
        *param_2 = uVar8;
        param_2[1] = uVar7 * iVar9 + ((int)uVar7 >> 0x1f) * uVar10 +
                     (int)((ulonglong)uVar7 * (ulonglong)uVar10 >> 0x20) + param_2[1] +
                     (uint)(uVar8 < uVar6);
        uVar2 = (ulonglong)uVar10;
        uVar10 = (uint)(uVar2 * 10);
        iVar9 = iVar9 * 10 + (int)(uVar2 * 10 >> 0x20);
      }
    } while (0 < (int)pcVar4);
  }
  return 1;
}



/* 40bf1788 FUN_40bf1788 */

/* Boundary evidence: original MIPS .pdata 40bf1788..40bf1807. Semantic name remains unreviewed. */

void FUN_40bf1788(undefined4 *param_1,undefined4 *param_2)

{
  void *_Dst;
  
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[1] = param_2[1];
  _Dst = malloc(param_2[1]);
  *param_1 = _Dst;
  memcpy(_Dst,(void *)*param_2,param_2[1]);
  return;
}



/* 40bf1808 FUN_40bf1808 */

/* Boundary evidence: original MIPS .pdata 40bf1808..40bf19b7. Semantic name remains unreviewed. */

undefined2 FUN_40bf1808(int *param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  char *_Str1;
  int iVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined **ppuVar10;
  byte local_98 [128];
  uint local_18;
  
  local_18 = DAT_40c08174;
  _Str1 = (char *)FUN_40bf305c(param_1,"LANGUAGE",0);
  if (_Str1 != (char *)0x0) {
    iVar4 = strcmp(_Str1,"off");
    pcVar6 = _Str1;
    if (iVar4 == 0) {
      FUN_40c0209c(local_18);
      return 9;
    }
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    strcpy((char *)local_98,_Str1);
    if (('`' < (char)local_98[0]) && ((char)local_98[0] < '{')) {
      local_98[0] = local_98[0] - 0x20;
    }
    if (1 < (int)(pcVar6 + (-1 - (int)_Str1))) {
      _strlwr((char *)(local_98 + 1));
    }
    ppuVar10 = &PTR_s_Afrikaans_40c03248;
    iVar4 = 0;
    do {
      pbVar8 = *ppuVar10;
      pbVar7 = pbVar8;
      do {
        bVar2 = *pbVar7;
        pbVar7 = pbVar7 + 1;
      } while (bVar2 != 0);
      pbVar7 = pbVar7 + (-1 - (int)pbVar8);
      if ((int)pbVar7 <= (int)(pcVar6 + (-1 - (int)_Str1))) {
        pbVar9 = local_98;
        iVar5 = 0;
        if (pbVar7 != (byte *)0x0) {
          pbVar7 = pbVar8 + (int)pbVar7;
          do {
            iVar5 = (uint)*pbVar8 - (uint)*pbVar9;
            if (*pbVar8 == 0) break;
            if (iVar5 != 0) goto LAB_40bf1958;
            pbVar8 = pbVar8 + 1;
            pbVar9 = pbVar9 + 1;
          } while (pbVar8 != pbVar7);
        }
        if (iVar5 == 0) {
          uVar3 = (&DAT_40c0324c)[iVar4 * 4];
          FUN_40c0209c(local_18);
          return uVar3;
        }
      }
LAB_40bf1958:
      iVar4 = iVar4 + 1;
      ppuVar10 = ppuVar10 + 2;
    } while (iVar4 < 0x2c);
  }
  FUN_40c0209c(local_18);
  return 0;
}



/* 40bf19b8 FUN_40bf19b8 */

/* Boundary evidence: original MIPS .pdata 40bf19b8..40bf19f7. Semantic name remains unreviewed. */

void FUN_40bf19b8(void *param_1)

{
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x58);
    free(param_1);
  }
  return;
}



/* 40bf19f8 FUN_40bf19f8 */

/* Boundary evidence: original MIPS .pdata 40bf19f8..40bf1b4b. Semantic name remains unreviewed. */

uint * FUN_40bf19f8(int param_1,int *param_2)

{
  uint *_Dst;
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x20);
  _Dst = malloc(0x58);
  uVar1 = FUN_40bf1028(param_2,8);
  *_Dst = uVar1;
  uVar1 = FUN_40bf1028(param_2,0x10);
  _Dst[1] = uVar1;
  uVar1 = FUN_40bf1028(param_2,0x10);
  _Dst[2] = uVar1;
  uVar1 = FUN_40bf1028(param_2,6);
  _Dst[3] = uVar1;
  uVar1 = FUN_40bf1028(param_2,8);
  _Dst[4] = uVar1;
  uVar1 = FUN_40bf1028(param_2,4);
  uVar1 = uVar1 + 1;
  _Dst[5] = uVar1;
  if (((((int)*_Dst < 1) || ((int)_Dst[1] < 1)) || ((int)_Dst[2] < 1)) || ((int)uVar1 < 1)) {
LAB_40bf1b10:
    memset(_Dst,0,0x58);
    free(_Dst);
    _Dst = (uint *)0x0;
  }
  else {
    iVar3 = 0;
    if (0 < (int)uVar1) {
      puVar2 = _Dst + 6;
      do {
        uVar1 = FUN_40bf1028(param_2,8);
        *puVar2 = uVar1;
        if (((int)uVar1 < 0) || (*(int *)(iVar4 + 0x18) <= (int)uVar1)) goto LAB_40bf1b10;
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < (int)_Dst[5]);
    }
  }
  return _Dst;
}



/* 40bf1b4c FUN_40bf1b4c */

/* Boundary evidence: original MIPS .pdata 40bf1b4c..40bf1b8b. Semantic name remains unreviewed. */

void FUN_40bf1b4c(void *param_1)

{
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x44c);
    free(param_1);
  }
  return;
}



/* 40bf1b8c FUN_40bf1b8c */

/* Boundary evidence: original MIPS .pdata 40bf1b8c..40bf1e37. Semantic name remains unreviewed. */

uint * FUN_40bf1b8c(int param_1,int *param_2)

{
  uint *_Dst;
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 0x20);
  uVar4 = 0xffffffff;
  _Dst = calloc(1,0x44c);
  uVar1 = FUN_40bf1028(param_2,5);
  *_Dst = uVar1;
  iVar6 = 0;
  puVar2 = _Dst;
  if (0 < (int)uVar1) {
    do {
      uVar1 = FUN_40bf1028(param_2,4);
      puVar2[1] = uVar1;
      if ((int)uVar4 < (int)uVar1) {
        uVar4 = uVar1;
      }
      iVar6 = iVar6 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar6 < (int)*_Dst);
  }
  iVar6 = 0;
  if (0 < (int)(uVar4 + 1)) {
    puVar3 = _Dst + 0x50;
    puVar2 = _Dst + 0x20;
    do {
      uVar1 = FUN_40bf1028(param_2,3);
      *puVar2 = uVar1 + 1;
      uVar1 = FUN_40bf1028(param_2,2);
      puVar2[0x10] = uVar1;
      if ((int)uVar1 < 0) {
LAB_40bf1e18:
        memset(_Dst,0,0x44c);
        free(_Dst);
        return (uint *)0x0;
      }
      if (uVar1 != 0) {
        uVar1 = FUN_40bf1028(param_2,8);
        puVar2[0x20] = uVar1;
      }
      if (((int)puVar2[0x20] < 0) || (*(int *)(iVar8 + 0x18) <= (int)puVar2[0x20]))
      goto LAB_40bf1e18;
      iVar7 = 0;
      puVar5 = puVar3;
      if (0 < 1 << (puVar2[0x10] & 0x1f)) {
        do {
          uVar1 = FUN_40bf1028(param_2,8);
          uVar1 = uVar1 - 1;
          *puVar5 = uVar1;
          if (((int)uVar1 < -1) || (*(int *)(iVar8 + 0x18) <= (int)uVar1)) goto LAB_40bf1e18;
          iVar7 = iVar7 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar7 < 1 << (puVar2[0x10] & 0x1f));
      }
      iVar6 = iVar6 + 1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 8;
    } while (iVar6 < (int)(uVar4 + 1));
  }
  uVar4 = FUN_40bf1028(param_2,2);
  _Dst[0xd0] = uVar4 + 1;
  uVar4 = FUN_40bf1028(param_2,4);
  iVar8 = 0;
  iVar6 = 0;
  if (0 < (int)*_Dst) {
    iVar7 = 0;
    puVar2 = _Dst;
    do {
      puVar2 = puVar2 + 1;
      iVar7 = _Dst[*puVar2 + 0x20] + iVar7;
      if (iVar6 < iVar7) {
        puVar3 = _Dst + iVar6 + 0xd3;
        do {
          uVar1 = FUN_40bf1028(param_2,uVar4);
          *puVar3 = uVar1;
          if (((int)uVar1 < 0) ||
             ((int)(1U >> (0x20 - uVar4 & 0x1f) | 1 << (uVar4 & 0x1f)) <= (int)uVar1))
          goto LAB_40bf1e18;
          iVar6 = iVar6 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar6 < iVar7);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)*_Dst);
  }
  _Dst[0xd1] = 0;
  _Dst[0xd2] = 1 << (uVar4 & 0x1f);
  return _Dst;
}



/* 40bf1e38 FUN_40bf1e38 */

undefined8 FUN_40bf1e38(int *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*param_1 + 10);
  return CONCAT44((((uVar1 >> 0x18) << 8 | (uVar1 & 0xffffff) >> 0x10) << 8 |
                  (uVar1 << 8 & 0xffffff) >> 0x10) << 8 | (uVar1 << 8 & 0xffff) >> 8,
                  *(undefined4 *)(*param_1 + 6));
}



/* 40bf1ec4 FUN_40bf1ec4 */

undefined4 FUN_40bf1ec4(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0xe);
}



/* 40bf1ef4 FUN_40bf1ef4 */

int FUN_40bf1ef4(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = 0;
  uVar2 = (uint)*(byte *)(*param_1 + 0x1a);
  iVar3 = 0;
  if (uVar2 != 0) {
    do {
      if (*(char *)(*param_1 + 0x1b + iVar3) != -1) {
        iVar1 = iVar1 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar2);
  }
  return iVar1;
}



/* 40bf1f40 FUN_40bf1f40 */

/* Boundary evidence: original MIPS .pdata 40bf1f40..40bf1fb7. Semantic name remains unreviewed. */

undefined4 FUN_40bf1f40(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
    }
    if ((void *)param_1[4] != (void *)0x0) {
      free((void *)param_1[4]);
    }
    if ((void *)param_1[5] != (void *)0x0) {
      free((void *)param_1[5]);
    }
    memset(param_1,0,0x168);
  }
  return 0;
}



/* 40bf1fb8 FUN_40bf1fb8 */

/* Boundary evidence: original MIPS .pdata 40bf1fb8..40bf204b. Semantic name remains unreviewed. */

undefined4 FUN_40bf1fb8(undefined4 *param_1,int param_2)

{
  void *pvVar1;
  
  if ((int)param_1[1] <= param_1[2] + param_2) {
    pvVar1 = realloc((void *)*param_1,param_1[1] + param_2 + 0x400);
    if (pvVar1 == (void *)0x0) {
      FUN_40bf1f40(param_1);
      return 0xffffffff;
    }
    *param_1 = pvVar1;
    param_1[1] = param_2 + param_1[1] + 0x400;
  }
  return 0;
}



/* 40bf204c FUN_40bf204c */

/* Boundary evidence: original MIPS .pdata 40bf204c..40bf2107. Semantic name remains unreviewed. */

undefined4 FUN_40bf204c(undefined4 *param_1,int param_2)

{
  void *pvVar1;
  
  if (param_1[7] + param_2 < (int)param_1[6]) {
    return 0;
  }
  pvVar1 = realloc((void *)param_1[4],(param_1[6] + param_2 + 0x20) * 4);
  if (pvVar1 != (void *)0x0) {
    param_1[4] = pvVar1;
    pvVar1 = realloc((void *)param_1[5],(param_2 + param_1[6] + 0x20) * 8);
    if (pvVar1 != (void *)0x0) {
      param_1[5] = pvVar1;
      param_1[6] = param_2 + param_1[6] + 0x20;
      return 0;
    }
  }
  FUN_40bf1f40(param_1);
  return 0xffffffff;
}



/* 40bf2108 FUN_40bf2108 */

void FUN_40bf2108(int *param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    uVar2 = 0;
    *(undefined1 *)(*param_1 + 0x16) = 0;
    iVar3 = 0;
    *(undefined1 *)(*param_1 + 0x17) = 0;
    *(undefined1 *)(*param_1 + 0x18) = 0;
    *(undefined1 *)(*param_1 + 0x19) = 0;
    if (0 < param_1[1]) {
      do {
        pbVar1 = (byte *)(*param_1 + iVar3);
        iVar3 = iVar3 + 1;
        uVar2 = *(uint *)(&DAT_40c033b8 + ((uint)*pbVar1 ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
      } while (iVar3 < param_1[1]);
    }
    iVar3 = 0;
    if (0 < param_1[3]) {
      do {
        pbVar1 = (byte *)(param_1[2] + iVar3);
        iVar3 = iVar3 + 1;
        uVar2 = *(uint *)(&DAT_40c033b8 + ((uint)*pbVar1 ^ uVar2 >> 0x18) * 4) ^ uVar2 << 8;
      } while (iVar3 < param_1[3]);
    }
    *(char *)(*param_1 + 0x16) = (char)uVar2;
    *(char *)(*param_1 + 0x17) = (char)(uVar2 >> 8);
    *(char *)(*param_1 + 0x18) = (char)(uVar2 >> 0x10);
    *(char *)(*param_1 + 0x19) = (char)(uVar2 >> 0x18);
  }
  return;
}



/* 40bf21f0 FUN_40bf21f0 */

undefined4 FUN_40bf21f0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = 0xffffffff;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
  }
  return 0;
}



/* 40bf2228 FUN_40bf2228 */

/* Boundary evidence: original MIPS .pdata 40bf2228..40bf2287. Semantic name remains unreviewed. */

undefined4 FUN_40bf2228(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
  }
  return 0;
}



/* 40bf2288 FUN_40bf2288 */

/* Boundary evidence: original MIPS .pdata 40bf2288..40bf2363. Semantic name remains unreviewed. */

int FUN_40bf2288(int *param_1,int param_2)

{
  void *pvVar1;
  size_t sVar2;
  int iVar3;
  
  if (param_1[1] < 0) {
    return 0;
  }
  iVar3 = param_1[3];
  if (iVar3 != 0) {
    sVar2 = param_1[2] - iVar3;
    param_1[2] = sVar2;
    if (0 < (int)sVar2) {
      memmove((void *)*param_1,(void *)(*param_1 + iVar3),sVar2);
    }
    param_1[3] = 0;
  }
  if (param_1[1] - param_1[2] < param_2) {
    sVar2 = param_1[2] + param_2 + 0x1000;
    if ((void *)*param_1 == (void *)0x0) {
      pvVar1 = malloc(sVar2);
    }
    else {
      pvVar1 = realloc((void *)*param_1,sVar2);
    }
    if (pvVar1 == (void *)0x0) {
      FUN_40bf2228(param_1);
      return 0;
    }
    *param_1 = (int)pvVar1;
    param_1[1] = sVar2;
  }
  return param_1[2] + *param_1;
}



/* 40bf2364 FUN_40bf2364 */

undefined4 FUN_40bf2364(int param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < *(int *)(param_1 + 4)) &&
     (iVar1 = *(int *)(param_1 + 8) + param_2, iVar1 <= *(int *)(param_1 + 4))) {
    *(int *)(param_1 + 8) = iVar1;
    return 0;
  }
  return 0xffffffff;
}



/* 40bf239c FUN_40bf239c */

/* Boundary evidence: original MIPS .pdata 40bf239c..40bf25c7. Semantic name remains unreviewed. */

int FUN_40bf239c(int *param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  void *_Buf1;
  int iVar5;
  undefined4 *_Buf2;
  undefined4 uVar6;
  undefined4 local_38 [2];
  void *local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  _Buf1 = (void *)(param_1[3] + *param_1);
  iVar5 = param_1[2] - param_1[3];
  if (param_1[1] < 0) {
    return 0;
  }
  if (param_1[5] == 0) {
    if (iVar5 < 0x1b) {
      return 0;
    }
    iVar1 = memcmp(_Buf1,&DAT_40c037b8,4);
    if (iVar1 == 0) {
      iVar1 = *(byte *)((int)_Buf1 + 0x1a) + 0x1b;
      if (iVar5 < iVar1) {
        return 0;
      }
      iVar4 = 0;
      if (*(byte *)((int)_Buf1 + 0x1a) != 0) {
        do {
          param_1[6] = (uint)*(byte *)((int)_Buf1 + iVar4 + 0x1b) + param_1[6];
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(uint)*(byte *)((int)_Buf1 + 0x1a));
      }
      param_1[5] = iVar1;
      goto LAB_40bf246c;
    }
  }
  else {
LAB_40bf246c:
    if (iVar5 < param_1[5] + param_1[6]) {
      return 0;
    }
    _Buf2 = (undefined4 *)((int)_Buf1 + 0x16);
    uVar6 = *_Buf2;
    *(undefined1 *)_Buf2 = 0;
    *(undefined1 *)((int)_Buf1 + 0x17) = 0;
    *(undefined1 *)((int)_Buf1 + 0x18) = 0;
    *(undefined1 *)((int)_Buf1 + 0x19) = 0;
    local_2c = param_1[5];
    local_24 = param_1[6];
    local_28 = local_2c + (int)_Buf1;
    local_38[0] = uVar6;
    local_30 = _Buf1;
    FUN_40bf2108((int *)&local_30);
    iVar1 = memcmp(local_38,_Buf2,4);
    if (iVar1 == 0) {
      iVar1 = *param_1;
      iVar5 = param_1[3];
      if (param_2 != (int *)0x0) {
        *param_2 = iVar1 + iVar5;
        param_2[1] = param_1[5];
        param_2[2] = param_1[5] + iVar1 + iVar5;
        param_2[3] = param_1[6];
      }
      iVar5 = param_1[5] + param_1[6];
      iVar1 = iVar5 + param_1[3];
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      goto LAB_40bf25a0;
    }
    *_Buf2 = uVar6;
  }
  param_1[5] = 0;
  param_1[6] = 0;
  pcVar3 = (char *)((int)_Buf1 + 1);
  if (iVar5 + -1 != 0) {
    pcVar2 = pcVar3 + iVar5 + -1;
    do {
      if (*pcVar3 == 'O') goto LAB_40bf252c;
      pcVar3 = pcVar3 + 1;
    } while (pcVar3 != pcVar2);
  }
  pcVar3 = (char *)0x0;
LAB_40bf252c:
  if (pcVar3 == (char *)0x0) {
    pcVar3 = (char *)(param_1[2] + *param_1);
  }
  iVar1 = (int)pcVar3 - *param_1;
  iVar5 = (int)_Buf1 - (int)pcVar3;
LAB_40bf25a0:
  param_1[3] = iVar1;
  return iVar5;
}



/* 40bf25c8 FUN_40bf25c8 */

/* Boundary evidence: original MIPS .pdata 40bf25c8..40bf2673. Semantic name remains unreviewed. */

undefined4 FUN_40bf25c8(int *param_1,int *param_2)

{
  int iVar1;
  
  if (-1 < param_1[1]) {
    iVar1 = FUN_40bf239c(param_1,param_2);
    while( true ) {
      if (0 < iVar1) {
        return 1;
      }
      if (iVar1 == 0) break;
      if (param_1[4] == 0) {
        param_1[4] = 1;
        return 0xffffffff;
      }
      iVar1 = FUN_40bf239c(param_1,param_2);
    }
  }
  return 0;
}



/* 40bf2674 FUN_40bf2674 */

/* Boundary evidence: original MIPS .pdata 40bf2674..40bf2b03. Semantic name remains unreviewed. */

undefined4 FUN_40bf2674(int *param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *_Dst;
  size_t _Size;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint *puVar11;
  int iVar12;
  size_t _Size_00;
  void *_Src;
  int iVar13;
  byte bVar14;
  int iVar15;
  
  iVar15 = *param_2;
  bVar1 = *(byte *)(iVar15 + 5);
  cVar2 = *(char *)(iVar15 + 4);
  _Src = (void *)param_2[2];
  bVar14 = bVar1 & 2;
  uVar3 = *(uint *)(iVar15 + 10);
  uVar4 = *(undefined4 *)(iVar15 + 6);
  iVar6 = *(int *)(iVar15 + 0xe);
  iVar5 = *(int *)(iVar15 + 0x12);
  uVar7 = (uint)*(byte *)(iVar15 + 0x1a);
  _Size_00 = param_2[3];
  iVar12 = 0;
  if ((param_1 != (int *)0x0) && (_Dst = (void *)*param_1, _Dst != (void *)0x0)) {
    iVar8 = param_1[3];
    iVar13 = param_1[9];
    if (iVar8 != 0) {
      _Size = param_1[2] - iVar8;
      param_1[2] = _Size;
      if (_Size != 0) {
        memmove(_Dst,(void *)((int)_Dst + iVar8),_Size);
      }
      param_1[3] = 0;
    }
    if (iVar13 != 0) {
      if (param_1[7] - iVar13 != 0) {
        memmove((void *)param_1[4],(void *)(iVar13 * 4 + param_1[4]),(param_1[7] - iVar13) * 4);
        memmove((void *)param_1[5],(void *)(iVar13 * 8 + param_1[5]),(param_1[7] - iVar13) * 8);
      }
      param_1[7] = param_1[7] - iVar13;
      param_1[8] = param_1[8] - iVar13;
      param_1[9] = 0;
    }
    if (((iVar6 == param_1[0x54]) && (cVar2 == '\0')) &&
       (iVar6 = FUN_40bf204c(param_1,uVar7 + 1), iVar6 == 0)) {
      if (iVar5 != param_1[0x55]) {
        iVar6 = param_1[8];
        if (iVar6 < param_1[7]) {
          puVar11 = (uint *)(iVar6 * 4 + param_1[4]);
          iVar8 = iVar6;
          do {
            param_1[2] = param_1[2] - (*puVar11 & 0xff);
            iVar8 = iVar8 + 1;
            puVar11 = puVar11 + 1;
          } while (iVar8 < param_1[7]);
        }
        param_1[7] = iVar6;
        if (param_1[0x55] != -1) {
          *(undefined4 *)(iVar6 * 4 + param_1[4]) = 0x400;
          param_1[7] = param_1[7] + 1;
          param_1[8] = param_1[8] + 1;
        }
      }
      if ((((bVar1 & 1) != 0) &&
          ((param_1[7] < 1 || (*(int *)(param_1[7] * 4 + param_1[4] + -4) == 0x400)))) &&
         (bVar14 = 0, uVar7 != 0)) {
        do {
          uVar9 = (uint)*(byte *)(iVar15 + 0x1b + iVar12);
          _Src = (void *)(uVar9 + (int)_Src);
          _Size_00 = _Size_00 - uVar9;
          iVar12 = iVar12 + 1;
          if (uVar9 < 0xff) break;
        } while (iVar12 < (int)uVar7);
      }
      if (_Size_00 != 0) {
        iVar6 = FUN_40bf1fb8(param_1,_Size_00);
        if (iVar6 != 0) {
          return 0xffffffff;
        }
        memcpy((void *)(param_1[2] + *param_1),_Src,_Size_00);
        param_1[2] = param_1[2] + _Size_00;
      }
      iVar6 = -1;
      if (iVar12 < (int)uVar7) {
        do {
          uVar9 = (uint)*(byte *)(iVar15 + 0x1b + iVar12);
          *(uint *)(param_1[7] * 4 + param_1[4]) = uVar9;
          puVar10 = (undefined4 *)(param_1[7] * 8 + param_1[5]);
          *puVar10 = 0xffffffff;
          puVar10[1] = 0xffffffff;
          if (bVar14 != 0) {
            puVar11 = (uint *)(param_1[7] * 4 + param_1[4]);
            bVar14 = 0;
            *puVar11 = *puVar11 | 0x100;
          }
          if (uVar9 < 0xff) {
            iVar6 = param_1[7];
          }
          iVar8 = param_1[7];
          param_1[7] = iVar8 + 1;
          iVar12 = iVar12 + 1;
          if (uVar9 < 0xff) {
            param_1[8] = iVar8 + 1;
          }
        } while (iVar12 < (int)uVar7);
        if (iVar6 != -1) {
          puVar10 = (undefined4 *)(iVar6 * 8 + param_1[5]);
          *puVar10 = uVar4;
          puVar10[1] = (((uVar3 >> 0x18) << 8 | (uVar3 & 0xffffff) >> 0x10) << 8 |
                       (uVar3 << 8 & 0xffffff) >> 0x10) << 8 | (uVar3 << 8 & 0xffff) >> 8;
        }
      }
      if ((bVar1 & 4) != 0) {
        param_1[0x52] = 1;
        if (0 < param_1[7]) {
          iVar6 = param_1[7] * 4 + param_1[4];
          *(uint *)(iVar6 + -4) = *(uint *)(iVar6 + -4) | 0x200;
        }
      }
      param_1[0x55] = iVar5 + 1;
      return 0;
    }
  }
  return 0xffffffff;
}



/* 40bf2b04 FUN_40bf2b04 */

undefined4 FUN_40bf2b04(int param_1)

{
  if (*(int *)(param_1 + 4) < 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return 0;
}



/* 40bf2b38 FUN_40bf2b38 */

undefined4 FUN_40bf2b38(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[0x51] = 0;
    param_1[0x52] = 0;
    param_1[0x53] = 0;
    param_1[0x55] = -1;
    param_1[0x56] = 0;
    param_1[0x57] = 0;
    param_1[0x58] = 0;
    param_1[0x59] = 0;
    return 0;
  }
  return 0xffffffff;
}



/* 40bf2b98 FUN_40bf2b98 */

undefined4 FUN_40bf2b98(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_1[9];
  if (param_1[8] <= iVar7) {
    return 0;
  }
  puVar4 = (uint *)(iVar7 * 4 + param_1[4]);
  if ((*puVar4 & 0x400) == 0) {
    if ((param_2 != (int *)0x0) || (param_3 != 0)) {
      uVar2 = *puVar4;
      uVar1 = uVar2 & 0xff;
      uVar6 = uVar2 & 0x200;
      uVar3 = uVar1;
      while (uVar3 == 0xff) {
        puVar4 = puVar4 + 1;
        uVar3 = *puVar4 & 0xff;
        iVar7 = iVar7 + 1;
        if ((*puVar4 & 0x200) != 0) {
          uVar6 = 0x200;
        }
        uVar1 = uVar1 + uVar3;
      }
      if (param_2 != (int *)0x0) {
        param_2[2] = uVar2 & 0x100;
        param_2[3] = uVar6;
        *param_2 = param_1[3] + *param_1;
        param_2[6] = param_1[0x56];
        param_2[7] = param_1[0x57];
        piVar5 = (int *)(iVar7 * 8 + param_1[5]);
        param_2[4] = *piVar5;
        param_2[5] = piVar5[1];
        param_2[1] = uVar1;
      }
      if (param_3 != 0) {
        uVar6 = param_1[0x56];
        uVar3 = uVar6 + 1;
        param_1[3] = param_1[3] + uVar1;
        param_1[9] = iVar7 + 1;
        param_1[0x56] = uVar3;
        param_1[0x57] = param_1[0x57] + (uint)(uVar3 < uVar6);
      }
    }
    return 1;
  }
  uVar1 = param_1[0x56];
  uVar6 = uVar1 + 1;
  param_1[9] = iVar7 + 1;
  param_1[0x56] = uVar6;
  param_1[0x57] = param_1[0x57] + (uint)(uVar6 < uVar1);
  return 0xffffffff;
}



/* 40bf2ce0 FUN_40bf2ce0 */

/* Boundary evidence: original MIPS .pdata 40bf2ce0..40bf2d1f. Semantic name remains unreviewed. */

undefined4 FUN_40bf2ce0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar1 = FUN_40bf2b98(param_1,param_2,1);
    return uVar1;
  }
  return 0;
}



/* 40bf2d20 FUN_40bf2d20 */

/* Boundary evidence: original MIPS .pdata 40bf2d20..40bf2ddf. Semantic name remains unreviewed. */

undefined4 FUN_40bf2d20(int *param_1,int param_2)

{
  void *pvVar1;
  
  if (param_1 != (int *)0x0) {
    memset(param_1,0,0x168);
    param_1[1] = 0x4000;
    param_1[6] = 0x400;
    pvVar1 = malloc(0x4000);
    *param_1 = (int)pvVar1;
    pvVar1 = malloc(param_1[6] << 2);
    param_1[4] = (int)pvVar1;
    pvVar1 = malloc(param_1[6] << 3);
    param_1[5] = (int)pvVar1;
    if (((*param_1 != 0) && (param_1[4] != 0)) && (pvVar1 != (void *)0x0)) {
      param_1[0x54] = param_2;
      return 0;
    }
    FUN_40bf1f40(param_1);
  }
  return 0xffffffff;
}



/* 40bf2de0 FUN_40bf2de0 */

void FUN_40bf2de0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}



/* 40bf2df8 FUN_40bf2df8 */

/* Boundary evidence: original MIPS .pdata 40bf2df8..40bf2ee7. Semantic name remains unreviewed. */

void FUN_40bf2df8(int *param_1,char *param_2)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  
  pvVar2 = realloc((void *)*param_1,(param_1[2] + 2) * 4);
  *param_1 = (int)pvVar2;
  pvVar2 = realloc((void *)param_1[1],(param_1[2] + 2) * 4);
  param_1[1] = (int)pvVar2;
  pcVar4 = param_2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  *(char **)(param_1[2] * 4 + (int)pvVar2) = pcVar4 + (-1 - (int)param_2);
  pvVar2 = malloc(*(int *)(param_1[2] * 4 + param_1[1]) + 1);
  *(void **)(param_1[2] * 4 + *param_1) = pvVar2;
  strcpy(*(char **)(param_1[2] * 4 + *param_1),param_2);
  iVar3 = param_1[2];
  param_1[2] = iVar3 + 1;
  *(undefined4 *)((iVar3 + 1) * 4 + *param_1) = 0;
  return;
}



/* 40bf2ee8 FUN_40bf2ee8 */

/* Boundary evidence: original MIPS .pdata 40bf2ee8..40bf2fc3. Semantic name remains unreviewed. */

void FUN_40bf2ee8(int *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint *_Dest;
  uint local_20 [2];
  
  local_20[0] = DAT_40c08174;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar3 = param_3;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  _Dest = local_20 + ((int)(pcVar2 + (int)(pcVar3 + (-(int)param_3 - (int)param_2) + 7)) >> 3) * -2;
  strcpy((char *)_Dest,param_2);
  strcat((char *)_Dest,"=");
  strcat((char *)_Dest,param_3);
  FUN_40bf2df8(param_1,(char *)_Dest);
  FUN_40c0209c(local_20[0]);
  return;
}



/* 40bf2fc4 FUN_40bf2fc4 */

/* Boundary evidence: original MIPS .pdata 40bf2fc4..40bf305b. Semantic name remains unreviewed. */

undefined4 FUN_40bf2fc4(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < param_3) {
    iVar4 = param_1 - (int)param_2;
    do {
      iVar1 = toupper((int)param_2[iVar4]);
      iVar2 = toupper((int)*param_2);
      if (iVar1 != iVar2) {
        return 1;
      }
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 1;
    } while (iVar3 < param_3);
  }
  return 0;
}



/* 40bf305c FUN_40bf305c */

/* Boundary evidence: original MIPS .pdata 40bf305c..40bf319f. Semantic name remains unreviewed. */

int FUN_40bf305c(int *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *_Dest;
  uint local_30 [2];
  
  local_30[0] = DAT_40c08174;
  iVar5 = 0;
  pcVar4 = param_2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar3 = (int)pcVar4 - (int)param_2;
  _Dest = local_30 + (iVar3 + 8 >> 3) * -2;
  strcpy((char *)_Dest,param_2);
  strcat((char *)_Dest,"=");
  iVar7 = 0;
  if (0 < param_1[2]) {
    iVar6 = 0;
    do {
      iVar2 = FUN_40bf2fc4(*(int *)(*param_1 + iVar6),(char *)_Dest,iVar3);
      if (iVar2 == 0) {
        if (param_3 == iVar5) {
          iVar5 = *(int *)(iVar7 * 4 + *param_1);
          FUN_40c0209c(local_30[0]);
          return iVar5 + iVar3;
        }
        iVar5 = iVar5 + 1;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar7 < param_1[2]);
  }
  FUN_40c0209c(local_30[0]);
  return 0;
}



/* 40bf31a0 FUN_40bf31a0 */

/* Boundary evidence: original MIPS .pdata 40bf31a0..40bf3267. Semantic name remains unreviewed. */

void FUN_40bf31a0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar2 = 0;
    if (0 < param_1[2]) {
      iVar1 = 0;
      do {
        if (*(void **)(iVar1 + *param_1) != (void *)0x0) {
          free(*(void **)(iVar1 + *param_1));
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 4;
      } while (iVar2 < param_1[2]);
    }
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      free((void *)param_1[1]);
    }
    if ((void *)param_1[3] != (void *)0x0) {
      free((void *)param_1[3]);
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}



/* 40bf3268 FUN_40bf3268 */

/* Boundary evidence: original MIPS .pdata 40bf3268..40bf32bf. Semantic name remains unreviewed. */

void FUN_40bf3268(undefined4 *param_1)

{
  void *pvVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  pvVar1 = calloc(1,0xb1c);
  param_1[8] = pvVar1;
  return;
}



/* 40bf32c0 FUN_40bf32c0 */

/* Boundary evidence: original MIPS .pdata 40bf32c0..40bf347b. Semantic name remains unreviewed. */

void FUN_40bf32c0(undefined4 *param_1)

{
  void *pvVar1;
  void *_Memory;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  _Memory = (void *)param_1[8];
  if (_Memory != (void *)0x0) {
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 8)) {
      puVar2 = (undefined4 *)((int)_Memory + 0x1c);
      do {
        if ((void *)*puVar2 != (void *)0x0) {
          free((void *)*puVar2);
        }
        iVar4 = iVar4 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 8));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0xc)) {
      puVar2 = (undefined4 *)((int)_Memory + 0x21c);
      do {
        if ((void *)*puVar2 != (void *)0x0) {
          FUN_40bf4010((void *)*puVar2);
        }
        iVar4 = iVar4 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 0xc));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0x10)) {
      piVar3 = (int *)((int)_Memory + 0x31c);
      do {
        pvVar1 = (void *)piVar3[0x40];
        if (pvVar1 != (void *)0x0) {
          if (*piVar3 == 0) {
            FUN_40bf19b8(pvVar1);
          }
          else if (*piVar3 == 1) {
            FUN_40bf1b4c(pvVar1);
          }
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 0x10));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0x14)) {
      puVar2 = (undefined4 *)((int)_Memory + 0x61c);
      do {
        if ((void *)*puVar2 != (void *)0x0) {
          FUN_40bfba98((void *)*puVar2);
        }
        iVar4 = iVar4 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 0x14));
    }
    iVar4 = 0;
    if (0 < *(int *)((int)_Memory + 0x18)) {
      puVar2 = (undefined4 *)((int)_Memory + 0x71c);
      do {
        if ((undefined4 *)*puVar2 != (undefined4 *)0x0) {
          FUN_40bfbf68((undefined4 *)*puVar2);
        }
        iVar4 = iVar4 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar4 < *(int *)((int)_Memory + 0x18));
    }
    free(_Memory);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}



/* 40bf347c FUN_40bf347c */

/* Boundary evidence: original MIPS .pdata 40bf347c..40bf35cf. Semantic name remains unreviewed. */

undefined4 FUN_40bf347c(uint *param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)param_1[8];
  if (piVar4 == (int *)0x0) {
    uVar1 = 0xffffff7f;
  }
  else {
    uVar2 = FUN_40bf1028(param_2,0x20);
    *param_1 = uVar2;
    if (uVar2 == 0) {
      uVar2 = FUN_40bf1028(param_2,8);
      param_1[1] = uVar2;
      uVar2 = FUN_40bf1028(param_2,0x20);
      param_1[2] = uVar2;
      uVar2 = FUN_40bf1028(param_2,0x20);
      param_1[4] = uVar2;
      uVar2 = FUN_40bf1028(param_2,0x20);
      param_1[5] = uVar2;
      uVar2 = FUN_40bf1028(param_2,0x20);
      param_1[6] = uVar2;
      uVar2 = FUN_40bf1028(param_2,4);
      *piVar4 = 1 << (uVar2 & 0x1f);
      uVar2 = FUN_40bf1028(param_2,4);
      iVar3 = 1 << (uVar2 & 0x1f);
      piVar4[1] = iVar3;
      if (((((int)param_1[2] < 1) || ((int)param_1[1] < 1)) || (*piVar4 < 0x40)) ||
         (((iVar3 < *piVar4 || (0x2000 < iVar3)) || (uVar2 = FUN_40bf1028(param_2,1), uVar2 != 1))))
      {
        FUN_40bf32c0(param_1);
        uVar1 = 0xffffff7b;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xffffff7a;
    }
  }
  return uVar1;
}



/* 40bf35d0 FUN_40bf35d0 */

/* Boundary evidence: original MIPS .pdata 40bf35d0..40bf375f. Semantic name remains unreviewed. */

undefined4 FUN_40bf35d0(int *param_1,int *param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = FUN_40bf1028(param_2,0x20);
  if (-1 < (int)uVar1) {
    puVar2 = calloc(uVar1 + 1,1);
    param_1[3] = (int)puVar2;
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      uVar3 = FUN_40bf1028(param_2,8);
      *puVar2 = (char)uVar3;
      puVar2 = puVar2 + 1;
    }
    uVar1 = FUN_40bf1028(param_2,0x20);
    param_1[2] = uVar1;
    if (-1 < (int)uVar1) {
      pvVar4 = calloc(uVar1 + 1,4);
      *param_1 = (int)pvVar4;
      pvVar4 = calloc(param_1[2] + 1,4);
      iVar5 = 0;
      param_1[1] = (int)pvVar4;
      if (0 < param_1[2]) {
        iVar6 = 0;
        do {
          uVar1 = FUN_40bf1028(param_2,0x20);
          if ((int)uVar1 < 0) goto LAB_40bf372c;
          *(uint *)(iVar6 + param_1[1]) = uVar1;
          pvVar4 = calloc(uVar1 + 1,1);
          *(void **)(iVar6 + *param_1) = pvVar4;
          puVar2 = *(undefined1 **)(iVar6 + *param_1);
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            uVar3 = FUN_40bf1028(param_2,8);
            *puVar2 = (char)uVar3;
            puVar2 = puVar2 + 1;
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 4;
        } while (iVar5 < param_1[2]);
      }
      uVar1 = FUN_40bf1028(param_2,1);
      if (uVar1 == 1) {
        return 0;
      }
    }
  }
LAB_40bf372c:
  FUN_40bf31a0(param_1);
  return 0xffffff7b;
}



/* 40bf3760 FUN_40bf3760 */

/* Boundary evidence: original MIPS .pdata 40bf3760..40bf3ab7. Semantic name remains unreviewed. */

undefined4 FUN_40bf3760(undefined4 *param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  void *pvVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  
  iVar8 = param_1[8];
  if (iVar8 == 0) {
    uVar1 = 0xffffff7f;
  }
  else {
    uVar2 = FUN_40bf1028(param_2,8);
    *(uint *)(iVar8 + 0x18) = uVar2 + 1;
    iVar10 = 0;
    if (0 < (int)(uVar2 + 1)) {
      puVar9 = (undefined4 *)(iVar8 + 0x71c);
      do {
        puVar3 = calloc(1,0x34);
        *puVar9 = puVar3;
        iVar4 = FUN_40bf112c(param_2,puVar3,param_3,param_4);
        if (iVar4 != 0) goto LAB_40bf3a80;
        iVar10 = iVar10 + 1;
        puVar9 = puVar9 + 1;
      } while (iVar10 < *(int *)(iVar8 + 0x18));
    }
    uVar2 = FUN_40bf1028(param_2,6);
    iVar10 = 0;
    if (0 < (int)(uVar2 + 1)) {
      do {
        uVar5 = FUN_40bf1028(param_2,0x10);
        if (((int)uVar5 < 0) || (0 < (int)uVar5)) goto LAB_40bf3a80;
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)(uVar2 + 1));
    }
    uVar2 = FUN_40bf1028(param_2,6);
    *(uint *)(iVar8 + 0x10) = uVar2 + 1;
    iVar10 = 0;
    if (0 < (int)(uVar2 + 1)) {
      puVar3 = (uint *)(iVar8 + 0x31c);
      do {
        uVar2 = FUN_40bf1028(param_2,0x10);
        *puVar3 = uVar2;
        if (((int)uVar2 < 0) || (1 < (int)uVar2)) goto LAB_40bf3a80;
        if (uVar2 == 0) {
          puVar6 = FUN_40bf19f8((int)param_1,param_2);
LAB_40bf38ac:
          puVar3[0x40] = (uint)puVar6;
        }
        else if (uVar2 == 1) {
          puVar6 = FUN_40bf1b8c((int)param_1,param_2);
          goto LAB_40bf38ac;
        }
        if (puVar3[0x40] == 0) goto LAB_40bf3a80;
        iVar10 = iVar10 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar10 < *(int *)(iVar8 + 0x10));
    }
    uVar2 = FUN_40bf1028(param_2,6);
    *(uint *)(iVar8 + 0x14) = uVar2 + 1;
    iVar10 = 0;
    if (0 < (int)(uVar2 + 1)) {
      puVar3 = (uint *)(iVar8 + 0x51c);
      do {
        uVar2 = FUN_40bf1028(param_2,0x10);
        *puVar3 = uVar2;
        if (((int)uVar2 < 0) || (2 < (int)uVar2)) goto LAB_40bf3a80;
        puVar6 = FUN_40bfbad8((int)param_1,param_2);
        puVar3[0x40] = (uint)puVar6;
        if (puVar6 == (uint *)0x0) goto LAB_40bf3a80;
        iVar10 = iVar10 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar10 < *(int *)(iVar8 + 0x14));
    }
    uVar2 = FUN_40bf1028(param_2,6);
    *(uint *)(iVar8 + 0xc) = uVar2 + 1;
    iVar10 = 0;
    if (0 < (int)(uVar2 + 1)) {
      puVar3 = (uint *)(iVar8 + 0x11c);
      do {
        uVar2 = FUN_40bf1028(param_2,0x10);
        *puVar3 = uVar2;
        if (((int)uVar2 < 0) || (0 < (int)uVar2)) goto LAB_40bf3a80;
        puVar6 = FUN_40bf4050((int)param_1,param_2);
        puVar3[0x40] = (uint)puVar6;
        if (puVar6 == (uint *)0x0) goto LAB_40bf3a80;
        iVar10 = iVar10 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar10 < *(int *)(iVar8 + 0xc));
    }
    uVar2 = FUN_40bf1028(param_2,6);
    *(uint *)(iVar8 + 8) = uVar2 + 1;
    iVar10 = 0;
    if (0 < (int)(uVar2 + 1)) {
      piVar11 = (int *)(iVar8 + 0x1c);
      do {
        pvVar7 = calloc(1,0x10);
        *piVar11 = (int)pvVar7;
        uVar2 = FUN_40bf1028(param_2,1);
        *(uint *)*piVar11 = uVar2;
        uVar2 = FUN_40bf1028(param_2,0x10);
        *(uint *)(*piVar11 + 4) = uVar2;
        uVar2 = FUN_40bf1028(param_2,0x10);
        *(uint *)(*piVar11 + 8) = uVar2;
        uVar2 = FUN_40bf1028(param_2,8);
        *(uint *)(*piVar11 + 0xc) = uVar2;
        iVar4 = *piVar11;
        if (((0 < *(int *)(iVar4 + 4)) || (0 < *(int *)(iVar4 + 8))) ||
           (*(int *)(iVar8 + 0xc) <= *(int *)(iVar4 + 0xc))) goto LAB_40bf3a80;
        iVar10 = iVar10 + 1;
        piVar11 = piVar11 + 1;
      } while (iVar10 < *(int *)(iVar8 + 8));
    }
    uVar2 = FUN_40bf1028(param_2,1);
    if (uVar2 == 1) {
      uVar1 = 0;
    }
    else {
LAB_40bf3a80:
      FUN_40bf32c0(param_1);
      uVar1 = 0xffffff7b;
    }
  }
  return uVar1;
}



/* 40bf3ab8 FUN_40bf3ab8 */

/* Boundary evidence: original MIPS .pdata 40bf3ab8..40bf3c6f. Semantic name remains unreviewed. */

undefined4 FUN_40bf3ab8(uint *param_1,int *param_2,undefined4 *param_3,va_list param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int aiStack_40 [5];
  undefined1 local_2c [8];
  uint local_24;
  
  local_24 = DAT_40c08174;
  if (param_3 != (undefined4 *)0x0) {
    FUN_40bf1000(aiStack_40,*param_3,param_3[1]);
    uVar1 = FUN_40bf1028(aiStack_40,8);
    local_2c[0] = 0;
    local_2c[1] = 0;
    local_2c[2] = 0;
    local_2c[3] = 0;
    local_2c[4] = 0;
    local_2c[5] = 0;
    iVar4 = 6;
    puVar5 = local_2c;
    do {
      iVar4 = iVar4 + -1;
      uVar2 = FUN_40bf1028(aiStack_40,8);
      *puVar5 = (char)uVar2;
      puVar5 = puVar5 + 1;
    } while (iVar4 != 0);
    uVar3 = 6;
    iVar4 = memcmp(local_2c,"vorbis",6);
    if (iVar4 != 0) {
      FUN_40c0209c(local_24);
      return 0xffffff7c;
    }
    if (uVar1 == 1) {
      if ((param_3[2] != 0) && (param_1[2] == 0)) {
        uVar3 = FUN_40bf347c(param_1,aiStack_40);
LAB_40bf3c28:
        FUN_40c0209c(local_24);
        return uVar3;
      }
    }
    else if (uVar1 == 3) {
      if (param_1[2] != 0) {
        uVar3 = FUN_40bf35d0(param_2,aiStack_40);
        FUN_40c0209c(local_24);
        return uVar3;
      }
    }
    else if (((uVar1 == 5) && (param_1[2] != 0)) && (param_2[3] != 0)) {
      uVar3 = FUN_40bf3760(param_1,aiStack_40,uVar3,param_4);
      goto LAB_40bf3c28;
    }
  }
  FUN_40c0209c(local_24);
  return 0xffffff7b;
}



/* 40bf3c70 FUN_40bf3c70 */

/* Boundary evidence: original MIPS .pdata 40bf3c70..40bf3d5f. Semantic name remains unreviewed. */

void * FUN_40bf3c70(char *param_1,int param_2)

{
  void *_Dst;
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = param_1;
  do {
    if (*pcVar1 != pcVar1[(int)&UNK_40c037cc - (int)param_1]) {
      return (void *)0x0;
    }
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 1;
  } while (iVar2 < 8);
  if (0x4f < param_2) {
    _Dst = malloc(0x50);
    memcpy(_Dst,param_1,0x50);
    if ((*(int *)((int)_Dst + 0x28) < 3) && (-1 < *(int *)((int)_Dst + 0x28))) {
      if (2 < *(int *)((int)_Dst + 0x30)) {
        *(undefined4 *)((int)_Dst + 0x30) = 2;
      }
      if (*(int *)((int)_Dst + 0x30) < 1) {
        *(undefined4 *)((int)_Dst + 0x30) = 1;
      }
      return _Dst;
    }
    free(_Dst);
  }
  return (void *)0x0;
}



/* 40bf3d60 FUN_40bf3d60 */

/* Boundary evidence: original MIPS .pdata 40bf3d60..40bf3e83. Semantic name remains unreviewed. */

int * FUN_40bf3d60(undefined4 *param_1,undefined4 param_2,undefined4 param_3,va_list param_4,
                  int *param_5,undefined4 *param_6,undefined4 param_7,int *param_8,
                  undefined4 param_9,undefined4 *param_10)

{
  void *_Memory;
  wchar_t *pwVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  _Memory = FUN_40bf3c70((char *)*param_1,iVar2);
  if (_Memory == (void *)0x0) {
    FUN_40bfb888(0x40c038f8,iVar2,param_3,param_4);
  }
  else {
    iVar2 = *(int *)((int)_Memory + 0x28);
    if ((iVar2 < 3) && (-1 < iVar2)) {
      iVar2 = *(int *)((int)_Memory + 0x1c);
      if (iVar2 < 2) {
        if (*param_5 == 0) {
          *param_5 = *(int *)((int)_Memory + 0x24);
        }
        *param_6 = *(undefined4 *)((int)_Memory + 0x40);
        if (*param_8 == -1) {
          *param_8 = *(int *)((int)_Memory + 0x30);
        }
        if (*param_8 != 1) {
          *param_8 = 2;
        }
        *param_10 = *(undefined4 *)((int)_Memory + 0x44);
        free(_Memory);
        return param_8;
      }
      pwVar1 = L"This file was encoded with Speex bit-stream version %d, which we cannot decode\n";
    }
    else {
      pwVar1 = L"Mode number %d does not (yet/any longer) exist in this version\n";
    }
    FUN_40bfb888((size_t)pwVar1,iVar2,param_3,param_4);
    free(_Memory);
  }
  return (int *)0x0;
}



/* 40bf3e84 FUN_40bf3e84 */

/* Boundary evidence: original MIPS .pdata 40bf3e84..40bf3f47. Semantic name remains unreviewed. */

undefined4 FUN_40bf3e84(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int local_38;
  int local_34;
  undefined4 uStack_30;
  char acStack_2c [4];
  undefined1 auStack_28 [24];
  
  local_38 = -1;
  local_34 = 0;
  iVar1 = memcmp((void *)*param_3,"Speex",5);
  if ((iVar1 == 0) &&
     (piVar2 = FUN_40bf3d60(param_3,0,acStack_2c,acStack_2c,&local_34,(undefined4 *)acStack_2c,
                            0xffffffff,&local_38,auStack_28,&uStack_30), piVar2 != (int *)0x0)) {
    *(int *)(param_1 + 4) = local_38;
    *(int *)(param_1 + 8) = local_34;
    return 0;
  }
  return 0xffffff75;
}



/* 40bf3f48 FUN_40bf3f48 */

/* Boundary evidence: original MIPS .pdata 40bf3f48..40bf400f. Semantic name remains unreviewed. */

undefined4 FUN_40bf3f48(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int aiStack_20 [6];
  
  iVar5 = *(int *)(param_1 + 0x20);
  FUN_40bf1000(aiStack_20,*param_2,param_2[1]);
  uVar1 = FUN_40bf1028(aiStack_20,1);
  if (uVar1 != 0) {
    return 0xffffff79;
  }
  iVar2 = 0;
  for (iVar3 = *(int *)(iVar5 + 8); 1 < iVar3; iVar3 = iVar3 >> 1) {
    iVar2 = iVar2 + 1;
  }
  uVar1 = FUN_40bf1028(aiStack_20,iVar2);
  if ((uVar1 != 0xffffffff) && (piVar4 = *(int **)((uVar1 + 7) * 4 + iVar5), piVar4 != (int *)0x0))
  {
    return *(undefined4 *)(*piVar4 * 4 + iVar5);
  }
  return 0xffffff78;
}



/* 40bf4010 FUN_40bf4010 */

/* Boundary evidence: original MIPS .pdata 40bf4010..40bf404f. Semantic name remains unreviewed. */

void FUN_40bf4010(void *param_1)

{
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0xc88);
    free(param_1);
  }
  return;
}



/* 40bf4050 FUN_40bf4050 */

/* Boundary evidence: original MIPS .pdata 40bf4050..40bf42d3. Semantic name remains unreviewed. */

uint * FUN_40bf4050(int param_1,int *param_2)

{
  uint *_Dst;
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  
  _Dst = calloc(1,0xc88);
  iVar6 = *(int *)(param_1 + 0x20);
  memset(_Dst,0,0xc88);
  uVar1 = FUN_40bf1028(param_2,1);
  if (uVar1 == 0) {
    *_Dst = 1;
  }
  else {
    uVar1 = FUN_40bf1028(param_2,4);
    *_Dst = uVar1 + 1;
  }
  uVar1 = FUN_40bf1028(param_2,1);
  if (uVar1 != 0) {
    uVar1 = FUN_40bf1028(param_2,8);
    _Dst[0x121] = uVar1 + 1;
    iVar5 = 0;
    if (0 < (int)(uVar1 + 1)) {
      puVar4 = _Dst + 0x122;
      do {
        iVar2 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          for (uVar1 = *(int *)(param_1 + 4) - 1; uVar1 != 0; uVar1 = uVar1 >> 1) {
            iVar2 = iVar2 + 1;
          }
        }
        uVar1 = FUN_40bf1028(param_2,iVar2);
        *puVar4 = uVar1;
        iVar2 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          for (uVar3 = *(int *)(param_1 + 4) - 1; uVar3 != 0; uVar3 = uVar3 >> 1) {
            iVar2 = iVar2 + 1;
          }
        }
        uVar3 = FUN_40bf1028(param_2,iVar2);
        puVar4[0x100] = uVar3;
        if (((((int)uVar1 < 0) || ((int)uVar3 < 0)) || (uVar1 == uVar3)) ||
           ((*(int *)(param_1 + 4) <= (int)uVar1 || (*(int *)(param_1 + 4) <= (int)uVar3))))
        goto LAB_40bf4290;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar5 < (int)_Dst[0x121]);
    }
  }
  uVar1 = FUN_40bf1028(param_2,2);
  if ((int)uVar1 < 1) {
    if ((1 < (int)*_Dst) && (iVar5 = 0, puVar4 = _Dst, 0 < *(int *)(param_1 + 4))) {
      do {
        uVar1 = FUN_40bf1028(param_2,4);
        puVar4[1] = uVar1;
        if ((int)*_Dst <= (int)uVar1) goto LAB_40bf4290;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar5 < *(int *)(param_1 + 4));
    }
    iVar5 = 0;
    if (0 < (int)*_Dst) {
      puVar4 = _Dst + 0x101;
      do {
        FUN_40bf1028(param_2,8);
        uVar1 = FUN_40bf1028(param_2,8);
        *puVar4 = uVar1;
        if (*(int *)(iVar6 + 0x10) <= (int)uVar1) goto LAB_40bf4290;
        uVar1 = FUN_40bf1028(param_2,8);
        puVar4[0x10] = uVar1;
        if (*(int *)(iVar6 + 0x14) <= (int)uVar1) goto LAB_40bf4290;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar5 < (int)*_Dst);
    }
  }
  else {
LAB_40bf4290:
    memset(_Dst,0,0xc88);
    free(_Dst);
    _Dst = (uint *)0x0;
  }
  return _Dst;
}



/* 40bf42d4 FUN_40bf42d4 */

/* Boundary evidence: original MIPS .pdata 40bf42d4..40bf42ef. Semantic name remains unreviewed. */

void FUN_40bf42d4(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40bf42f0 FUN_40bf42f0 */

/* Boundary evidence: original MIPS .pdata 40bf42f0..40bf430b. Semantic name remains unreviewed. */

void FUN_40bf42f0(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  return;
}



/* 40bf430c FUN_40bf430c */

/* Boundary evidence: original MIPS .pdata 40bf430c..40bf4357. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_40bf430c(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  param_1->SpinCount = 0;
  param_1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[1].LockCount = 0;
  param_1[1].OwningThread = (HANDLE)0x80;
  param_1[1].LockSemaphore = (HANDLE)0x1400;
  param_1[1].RecursionCount = 0;
  return param_1;
}



/* 40bf4358 FUN_40bf4358 */

/* Boundary evidence: original MIPS .pdata 40bf4358..40bf43bb. Semantic name remains unreviewed. */

void FUN_40bf4358(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  while (iVar1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = *puVar2;
    operator_delete((void *)puVar2[4]);
    operator_delete((void *)puVar2[6]);
    operator_delete(puVar2);
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  return;
}



/* 40bf43bc FUN_40bf43bc */

/* Boundary evidence: original MIPS .pdata 40bf43bc..40bf4457. Semantic name remains unreviewed. */

void FUN_40bf43bc(LPCRITICAL_SECTION param_1)

{
  ULONG_PTR UVar1;
  ULONG_PTR *pUVar2;
  
  EnterCriticalSection(param_1);
  UVar1 = param_1->SpinCount;
  while (UVar1 != 0) {
    pUVar2 = (ULONG_PTR *)param_1->SpinCount;
    param_1->SpinCount = *pUVar2;
    operator_delete((void *)pUVar2[4]);
    operator_delete((void *)pUVar2[6]);
    operator_delete(pUVar2);
    UVar1 = param_1->SpinCount;
  }
  param_1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[1].RecursionCount = 0;
  FUN_40bf4358((int)param_1);
  LeaveCriticalSection(param_1);
  return;
}



/* 40bf4458 FUN_40bf4458 */

/* Boundary evidence: original MIPS .pdata 40bf4458..40bf4487. Semantic name remains unreviewed. */

void FUN_40bf4458(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40bf4488 FUN_40bf4488 */

/* Boundary evidence: original MIPS .pdata 40bf4488..40bf463b. Semantic name remains unreviewed. */

void FUN_40bf4488(LPCRITICAL_SECTION param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  _LIST_ENTRY *p_Var3;
  _LIST_ENTRY *p_Var4;
  uint uVar5;
  PRTL_CRITICAL_SECTION_DEBUG p_Var6;
  
  EnterCriticalSection(param_1);
  uVar5 = param_2[1];
  if (((int)param_1[1].OwningThread < (int)uVar5) ||
     ((int)param_1[1].LockSemaphore < (int)param_2[3])) {
    if ((int)param_1[1].OwningThread < (int)uVar5) {
      param_1[1].OwningThread = (HANDLE)((uVar5 & 0xffffff80) + 0x80);
    }
    if ((int)param_1[1].LockSemaphore < (int)param_2[3]) {
      param_1[1].LockSemaphore = (HANDLE)((param_2[3] & 0xfffffc00) + 0x400);
    }
    FUN_40bf4358((int)param_1);
  }
  else {
    p_Var6 = (PRTL_CRITICAL_SECTION_DEBUG)param_1[1].LockCount;
    if ((p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) &&
       (param_1[1].LockCount = *(LONG *)p_Var6, p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0))
    goto LAB_40bf4588;
  }
  p_Var6 = operator_new(0x28);
  *(HANDLE *)(p_Var6 + 1) = param_1[1].OwningThread;
  pvVar1 = operator_new((uint)param_1[1].OwningThread);
  p_Var6->EntryCount = (DWORD)pvVar1;
  p_Var6[1].CriticalSection = param_1[1].LockSemaphore;
  pvVar1 = operator_new((uint)param_1[1].LockSemaphore);
  p_Var6->Flags = (DWORD)pvVar1;
LAB_40bf4588:
  memcpy((void *)p_Var6->EntryCount,(void *)*param_2,param_2[1]);
  p_Var6->ContentionCount = param_2[1];
  memcpy((void *)p_Var6->Flags,(void *)param_2[2],param_2[3]);
  uVar2 = param_2[3];
  p_Var6->CreatorBackTraceIndexHigh = (short)uVar2;
  p_Var6->SpareWORD = (short)((uint)uVar2 >> 0x10);
  if (param_3 == (undefined4 *)0x0) {
    p_Var3 = (_LIST_ENTRY *)0x0;
    p_Var4 = (_LIST_ENTRY *)0x0;
  }
  else {
    p_Var3 = (_LIST_ENTRY *)*param_3;
    p_Var4 = (_LIST_ENTRY *)param_3[1];
  }
  (p_Var6->ProcessLocksList).Flink = p_Var3;
  (p_Var6->ProcessLocksList).Blink = p_Var4;
  p_Var6->Type = 0;
  p_Var6->CreatorBackTraceIndex = 0;
  if (param_1[1].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    param_1->SpinCount = (ULONG_PTR)p_Var6;
    param_1[1].DebugInfo = p_Var6;
  }
  else {
    *(PRTL_CRITICAL_SECTION_DEBUG *)param_1[1].DebugInfo = p_Var6;
    param_1[1].DebugInfo = *(PRTL_CRITICAL_SECTION_DEBUG *)param_1[1].DebugInfo;
  }
  param_1[1].RecursionCount = param_1[1].RecursionCount + 1;
  LeaveCriticalSection(param_1);
  return;
}



/* 40bf463c FUN_40bf463c */

/* Boundary evidence: original MIPS .pdata 40bf463c..40bf466b. Semantic name remains unreviewed. */

void FUN_40bf463c(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bf466c FUN_40bf466c */

/* Boundary evidence: original MIPS .pdata 40bf466c..40bf46ef. Semantic name remains unreviewed. */

ULONG_PTR * FUN_40bf466c(LPCRITICAL_SECTION param_1)

{
  ULONG_PTR UVar1;
  ULONG_PTR *pUVar2;
  
  EnterCriticalSection(param_1);
  pUVar2 = (ULONG_PTR *)param_1->SpinCount;
  if (pUVar2 == (ULONG_PTR *)0x0) {
    LeaveCriticalSection(param_1);
    return (ULONG_PTR *)0x0;
  }
  UVar1 = *pUVar2;
  param_1->SpinCount = UVar1;
  if (UVar1 == 0) {
    param_1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  }
  param_1[1].RecursionCount = param_1[1].RecursionCount + -1;
  LeaveCriticalSection(param_1);
  return pUVar2;
}



/* 40bf46f0 FUN_40bf46f0 */

/* Boundary evidence: original MIPS .pdata 40bf46f0..40bf478b. Semantic name remains unreviewed. */

void FUN_40bf46f0(LPCRITICAL_SECTION param_1,LONG *param_2)

{
  if (((int)param_1[1].OwningThread <= param_2[8]) && ((int)param_1[1].LockSemaphore <= param_2[9]))
  {
    EnterCriticalSection(param_1);
    *param_2 = param_1[1].LockCount;
    param_1[1].LockCount = (LONG)param_2;
    LeaveCriticalSection(param_1);
    return;
  }
  operator_delete((void *)param_2[4]);
  operator_delete((void *)param_2[6]);
  operator_delete(param_2);
  return;
}



/* 40bf478c FUN_40bf478c */

/* Boundary evidence: original MIPS .pdata 40bf478c..40bf47cb. Semantic name remains unreviewed. */

LONG FUN_40bf478c(LPCRITICAL_SECTION param_1)

{
  LONG LVar1;
  
  EnterCriticalSection(param_1);
  LVar1 = param_1[1].RecursionCount;
  LeaveCriticalSection(param_1);
  return LVar1;
}



/* 40bf47cc FUN_40bf47cc */

/* Boundary evidence: original MIPS .pdata 40bf47cc..40bf4813. Semantic name remains unreviewed. */

void FUN_40bf47cc(LPCRITICAL_SECTION param_1)

{
  FUN_40bf43bc(param_1);
  DeleteCriticalSection(param_1);
  return;
}



/* 40bf4814 FUN_40bf4814 */

/* Boundary evidence: original MIPS .pdata 40bf4814..40bf4843. Semantic name remains unreviewed. */

void FUN_40bf4814(void)

{
  undefined4 *in_v0;
  
  FUN_40bf42d4((LPCRITICAL_SECTION)*in_v0);
  return;
}



/* 40bf4844 FUN_40bf4844 */

/* Boundary evidence: original MIPS .pdata 40bf4844..40bf489b. Semantic name remains unreviewed. */

void FUN_40bf4844(int param_1)

{
  HANDLE hHandle;
  
  hHandle = (HANDLE)InterlockedExchange((LONG *)(param_1 + 0x14),0);
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
    CloseHandle(hHandle);
  }
  return;
}



/* 40bf489c FUN_40bf489c */

/* Boundary evidence: original MIPS .pdata 40bf489c..40bf49e7. Semantic name remains unreviewed. */

undefined4 * FUN_40bf489c(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  
  FUN_40bfd744((int)param_1);
  FUN_40bf430c((LPCRITICAL_SECTION)(param_1 + 0x10));
  *param_1 = &PTR_FUN_40c039d0;
  FUN_40bfd5e8(param_1 + 0x1c,0);
  FUN_40bfd5e8(param_1 + 0x1d,0);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1f));
  puVar1 = param_1 + 0xb8;
  FUN_40bfcfd4(puVar1);
  param_1[0x1b] = param_3;
  param_1[0xb5] = param_2;
  *(undefined1 *)(param_1 + 0xcc) = 0;
  param_1[0xcb] = 0xff;
  param_1[0xca] = 0;
  FUN_40bfad6c((undefined1 *)(param_1 + 0x24),param_2);
  param_1[0x8a] = 0;
  FUN_40bf3268(param_1 + 0xa8);
  FUN_40bf2de0(param_1 + 0x8b);
  memset(param_1 + 0x90,0,0x60);
  *(char *)(param_1 + 0xb4) = (char)param_4;
  if (param_4 != 0) {
    FUN_40bfce84(puVar1);
    FUN_40bfcd6c(puVar1,(undefined4 *)&DAT_40c04a24);
    param_1[0xb3] = 0x400;
    FUN_40bf2ee8(param_1 + 0x8b,"LANGUAGE","off");
  }
  return param_1;
}



/* 40bf49e8 FUN_40bf49e8 */

/* Boundary evidence: original MIPS .pdata 40bf49e8..40bf4a17. Semantic name remains unreviewed. */

void FUN_40bf49e8(void)

{
  int *in_v0;
  
  FUN_40bfd7c0(*in_v0);
  return;
}



/* 40bf4a18 FUN_40bf4a18 */

/* Boundary evidence: original MIPS .pdata 40bf4a18..40bf4a4b. Semantic name remains unreviewed. */

void FUN_40bf4a18(void)

{
  int *in_v0;
  
  FUN_40bf47cc((LPCRITICAL_SECTION)(*in_v0 + 0x40));
  return;
}



/* 40bf4a4c FUN_40bf4a4c */

/* Boundary evidence: original MIPS .pdata 40bf4a4c..40bf4a7f. Semantic name remains unreviewed. */

void FUN_40bf4a4c(void)

{
  int *in_v0;
  
  FUN_40bfd628((undefined4 *)(*in_v0 + 0x70));
  return;
}



/* 40bf4a80 FUN_40bf4a80 */

/* Boundary evidence: original MIPS .pdata 40bf4a80..40bf4ab3. Semantic name remains unreviewed. */

void FUN_40bf4a80(void)

{
  int *in_v0;
  
  FUN_40bfd628((undefined4 *)(*in_v0 + 0x74));
  return;
}



/* 40bf4ab4 FUN_40bf4ab4 */

/* Boundary evidence: original MIPS .pdata 40bf4ab4..40bf4ae7. Semantic name remains unreviewed. */

void FUN_40bf4ab4(void)

{
  int *in_v0;
  
  FUN_40bf42d4((LPCRITICAL_SECTION)(*in_v0 + 0x7c));
  return;
}



/* 40bf4ae8 FUN_40bf4ae8 */

/* Boundary evidence: original MIPS .pdata 40bf4ae8..40bf4b1b. Semantic name remains unreviewed. */

void FUN_40bf4ae8(void)

{
  int *in_v0;
  
  FUN_40bfcfb8(*in_v0 + 0x2e0);
  return;
}



/* 40bf4b1c FUN_40bf4b1c */

/* Boundary evidence: original MIPS .pdata 40bf4b1c..40bf4bcb. Semantic name remains unreviewed. */

void FUN_40bf4b1c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40c039d0;
  FUN_40bfad9c((undefined1 *)(param_1 + 0x24));
  FUN_40bf32c0(param_1 + 0xa8);
  FUN_40bf31a0(param_1 + 0x8b);
  if ((void *)param_1[0x8a] != (void *)0x0) {
    free((void *)param_1[0x8a]);
  }
  FUN_40bfcfb8((int)(param_1 + 0xb8));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1f));
  FUN_40bfd628(param_1 + 0x1d);
  FUN_40bfd628(param_1 + 0x1c);
  FUN_40bf47cc((LPCRITICAL_SECTION)(param_1 + 0x10));
  FUN_40bfd7c0((int)param_1);
  return;
}



/* 40bf4bcc FUN_40bf4bcc */

/* Boundary evidence: original MIPS .pdata 40bf4bcc..40bf4bfb. Semantic name remains unreviewed. */

void FUN_40bf4bcc(void)

{
  int *in_v0;
  
  FUN_40bfd7c0(*in_v0);
  return;
}



/* 40bf4bfc FUN_40bf4bfc */

/* Boundary evidence: original MIPS .pdata 40bf4bfc..40bf4c4f. Semantic name remains unreviewed. */

void FUN_40bf4bfc(void)

{
  int *in_v0;
  
  if (*in_v0 == 0) {
    in_v0[-6] = 0;
  }
  else {
    in_v0[-6] = *in_v0 + 0x40;
  }
  FUN_40bf47cc((LPCRITICAL_SECTION)in_v0[-6]);
  return;
}



/* 40bf4c50 FUN_40bf4c50 */

/* Boundary evidence: original MIPS .pdata 40bf4c50..40bf4c83. Semantic name remains unreviewed. */

void FUN_40bf4c50(void)

{
  int *in_v0;
  
  FUN_40bfd628((undefined4 *)(*in_v0 + 0x70));
  return;
}



/* 40bf4c84 FUN_40bf4c84 */

/* Boundary evidence: original MIPS .pdata 40bf4c84..40bf4cb7. Semantic name remains unreviewed. */

void FUN_40bf4c84(void)

{
  int *in_v0;
  
  FUN_40bfd628((undefined4 *)(*in_v0 + 0x74));
  return;
}



/* 40bf4cb8 FUN_40bf4cb8 */

/* Boundary evidence: original MIPS .pdata 40bf4cb8..40bf4ceb. Semantic name remains unreviewed. */

void FUN_40bf4cb8(void)

{
  int *in_v0;
  
  FUN_40bf42d4((LPCRITICAL_SECTION)(*in_v0 + 0x7c));
  return;
}



/* 40bf4cec FUN_40bf4cec */

/* Boundary evidence: original MIPS .pdata 40bf4cec..40bf4d83. Semantic name remains unreviewed. */

undefined4 FUN_40bf4cec(int param_1)

{
  ULONG_PTR *pUVar1;
  undefined4 uVar2;
  LONG LVar3;
  LPCRITICAL_SECTION p_Var4;
  
  p_Var4 = (LPCRITICAL_SECTION)(param_1 + 0x40);
  pUVar1 = FUN_40bf466c(p_Var4);
  if (pUVar1 == (ULONG_PTR *)0x0) {
    uVar2 = 0;
  }
  else {
    FUN_40bf2674((int *)(param_1 + 0xc0),(int *)(pUVar1 + 4));
    FUN_40bf46f0(p_Var4,(LONG *)pUVar1);
    LVar3 = FUN_40bf478c(p_Var4);
    if (LVar3 < *(int *)(param_1 + 0x2c8)) {
      EventModify(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x6c) + 0x58) + 0x158),3);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 40bf4d84 FUN_40bf4d84 */

/* Boundary evidence: original MIPS .pdata 40bf4d84..40bf4e2b. Semantic name remains unreviewed. */

bool FUN_40bf4d84(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  LONG LVar3;
  
  if (*(int *)(*(int *)(param_1 + 0x328) + 0x18) == 0) {
LAB_40bf4dac:
    bVar1 = false;
  }
  else {
    if (*(char *)(param_1 + 0x23c) != '\0') {
      iVar2 = FUN_40bf1ef4(param_2);
      if (iVar2 == 0) goto LAB_40bf4dac;
      *(undefined1 *)(param_1 + 0x23c) = 0;
    }
    FUN_40bf4488((LPCRITICAL_SECTION)(param_1 + 0x40),param_2,(undefined4 *)0x0);
    EventModify(*(undefined4 *)(param_1 + 0x74),3);
    LVar3 = FUN_40bf478c((LPCRITICAL_SECTION)(param_1 + 0x40));
    bVar1 = *(int *)(param_1 + 0x2c4) <= LVar3;
  }
  return bVar1;
}



/* 40bf4e2c FUN_40bf4e2c */

/* Boundary evidence: original MIPS .pdata 40bf4e2c..40bf4edf. Semantic name remains unreviewed. */

undefined4 FUN_40bf4e2c(LPVOID param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;
  int iVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  iVar3 = *(int *)((int)param_1 + 0x6c);
  lpCriticalSection = *(LPCRITICAL_SECTION *)(iVar3 + 0x40);
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(iVar3 + 0x1c);
  bVar1 = true;
  if ((iVar3 != 1) && (iVar3 != 2)) {
    bVar1 = false;
  }
  LeaveCriticalSection(lpCriticalSection);
  if (bVar1) {
    uVar2 = 1;
  }
  else {
    if (*(int *)(*(int *)((int)param_1 + 0x328) + 0x18) != 0) {
      bVar1 = FUN_40bfd830(param_1);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        return 0x80004005;
      }
      FUN_40bfd8e4((int)param_1,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bf4ee0 FUN_40bf4ee0 */

/* Boundary evidence: original MIPS .pdata 40bf4ee0..40bf4f8b. Semantic name remains unreviewed. */

undefined4 FUN_40bf4ee0(int param_1)

{
  HANDLE hHandle;
  
  if (*(LONG *)(param_1 + 0x14) != 0) {
    *(undefined1 *)(param_1 + 0x78) = 1;
    EventModify(*(undefined4 *)(param_1 + 0x74),3);
    EventModify(*(undefined4 *)(param_1 + 0x70),3);
    FUN_40bfd8e4(param_1,3);
    hHandle = (HANDLE)InterlockedExchange((LONG *)(param_1 + 0x14),0);
    if (hHandle != (HANDLE)0x0) {
      WaitForSingleObject(hHandle,0xffffffff);
      CloseHandle(hHandle);
    }
    FUN_40bf43bc((LPCRITICAL_SECTION)(param_1 + 0x40));
  }
  return 0;
}



/* 40bf4f8c FUN_40bf4f8c */

/* Boundary evidence: original MIPS .pdata 40bf4f8c..40bf4fe7. Semantic name remains unreviewed. */

undefined4 FUN_40bf4f8c(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined1 *)(param_1 + 0x78) = 1;
    EventModify(*(undefined4 *)(param_1 + 0x74),3);
    EventModify(*(undefined4 *)(param_1 + 0x70),3);
    FUN_40bfd8e4(param_1,2);
  }
  return 0;
}



/* 40bf4fe8 FUN_40bf4fe8 */

/* Boundary evidence: original MIPS .pdata 40bf4fe8..40bf502b. Semantic name remains unreviewed. */

undefined4 FUN_40bf4fe8(int param_1)

{
  FUN_40bf43bc((LPCRITICAL_SECTION)(param_1 + 0x40));
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_40bfd8e4(param_1,1);
  }
  return 0;
}



/* 40bf502c FUN_40bf502c */

/* Boundary evidence: original MIPS .pdata 40bf502c..40bf5203. Semantic name remains unreviewed. */

undefined4
FUN_40bf502c(int param_1,longlong *param_2,longlong *param_3,uint *param_4,uint *param_5,
            undefined1 *param_6,int param_7,undefined4 *param_8,int *param_9)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  do {
    pcVar2 = (char *)(param_1 + 0x90);
    if (*(int *)(param_1 + 0x32c) == 0) {
      iVar1 = FUN_40bfae3c(pcVar2,param_1 + 0x2a0,param_7,param_4,param_2,param_8,param_9);
      if (iVar1 == -0x804) {
LAB_40bf51e4:
        *(undefined4 *)param_3 = 0xffffffff;
        *(undefined4 *)((int)param_3 + 4) = 0xffffffff;
        *param_5 = 0xffffffff;
        param_5[1] = 0xffffffff;
        *param_6 = 0;
        return 1;
      }
      *(int *)param_3 = (int)*param_2;
      *(undefined4 *)((int)param_3 + 4) = *(undefined4 *)((int)param_2 + 4);
      *param_5 = *param_4;
      param_5[1] = param_4[1];
      *param_6 = 1;
joined_r0x40bf50d4:
      if (iVar1 == 1) {
        return 1;
      }
    }
    else {
      if (*(int *)(param_1 + 0x32c) == 2) {
        iVar1 = FUN_40bfb03c(pcVar2,param_1 + 0x2a0,param_7,param_4,param_2,param_8,param_9);
        if (iVar1 == -0x804) goto LAB_40bf51e4;
        *(int *)param_3 = (int)*param_2;
        *(undefined4 *)((int)param_3 + 4) = *(undefined4 *)((int)param_2 + 4);
        *param_5 = *param_4;
        param_5[1] = param_4[1];
        *param_6 = 1;
        goto joined_r0x40bf50d4;
      }
      iVar1 = FUN_40bfb580(pcVar2,*(int *)(param_1 + 0x228),param_7,param_6,param_4,param_5,param_2,
                           param_3,param_8,param_9);
      uVar3 = *param_4;
      uVar4 = param_4[1];
      uVar5 = uVar3 + *param_5;
      *param_5 = uVar5;
      param_5[1] = uVar4 + param_5[1] + (uint)(uVar5 < uVar3);
    }
    if (0 < iVar1) {
      return 1;
    }
    if ((iVar1 == 0) && (iVar1 = FUN_40bf4cec(param_1), iVar1 == 0)) {
      return 0;
    }
  } while( true );
}



/* 40bf5204 FUN_40bf5204 */

/* Boundary evidence: original MIPS .pdata 40bf5204..40bf530b. Semantic name remains unreviewed. */

void FUN_40bf5204(int param_1)

{
  int iVar1;
  int *local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 1;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x328) + 0x40))
                    (*(int **)(param_1 + 0x328),&local_20,0,0,0);
  if (-1 < iVar1) {
    (**(code **)(*local_20 + 0xc))(local_20,&local_1c);
    *local_1c = 0;
    (**(code **)(*local_20 + 0x30))(local_20,1);
    (**(code **)(*local_20 + 0x18))(local_20,&local_10,&local_18);
    (**(code **)(*local_20 + 0x28))(local_20,0);
    (**(code **)(*local_20 + 0x40))(local_20,1);
    (**(code **)(*local_20 + 0x20))(local_20,1);
    (**(code **)(**(int **)(param_1 + 0x328) + 0x44))(*(int **)(param_1 + 0x328),local_20);
    (**(code **)(*local_20 + 8))();
  }
  return;
}



/* 40bf530c FUN_40bf530c */

/* Boundary evidence: original MIPS .pdata 40bf530c..40bf5bcb. Semantic name remains unreviewed. */

int FUN_40bf530c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char local_78;
  char local_77 [3];
  int *local_74;
  int *local_70;
  int *local_6c;
  size_t local_68;
  void *local_64;
  void *local_60;
  void *local_5c;
  void *local_58;
  undefined4 uStack_54;
  uint local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38 [3];
  int local_2c;
  
  FUN_40bfadec((undefined1 *)(param_1 + 0x90));
  *(undefined1 *)(param_1 + 0x23c) = 1;
  *(undefined1 *)(param_1 + 0x78) = 0;
  EventModify(*(undefined4 *)(param_1 + 0x74),2);
  EventModify(*(undefined4 *)(param_1 + 0x70),2);
  iVar2 = *(int *)(param_1 + 0x6c);
  *(undefined1 *)(param_1 + 0x79) = 1;
  uVar4 = *(uint *)(iVar2 + 0xb0) - *(uint *)(iVar2 + 0xa8);
  uVar3 = (*(int *)(iVar2 + 0xb4) - *(int *)(iVar2 + 0xac)) -
          (uint)(*(uint *)(iVar2 + 0xb0) < *(uint *)(iVar2 + 0xa8));
  FUN_40bfda0c(param_1,0);
  if (((*(char *)(param_1 + 0x2dc) != '\0') &&
      ((**(code **)(**(int **)(param_1 + 0x328) + 0x58))(), *(int *)(param_1 + 0x32c) == 1)) &&
     (iVar2 = strcmp(*(char **)(param_1 + 0x228),"text"), iVar2 == 0)) {
    FUN_40bf5204(param_1);
  }
  do {
    iVar2 = FUN_40bf502c(param_1,(longlong *)&local_50,(longlong *)&local_48,local_38,&local_40,
                         &local_78,(int)local_77,&local_64,(int *)&local_68);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x6c) + 0xc0) != '\0') {
        if (*(char *)(param_1 + 0x2dc) == '\0') {
          return 0;
        }
        iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x4c))();
        return iVar2;
      }
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x74),0xffffffff);
    }
    else if (((local_78 == '\0') && ((local_48 & local_44) == 0xffffffff)) &&
            ((local_40 & local_3c) == 0xffffffff)) {
      if (*(char *)(param_1 + 0x2dc) == '\0') {
LAB_40bf5b8c:
        WaitForSingleObject(*(HANDLE *)(param_1 + 0x70),0xffffffff);
        *(undefined1 *)(param_1 + 0x79) = 1;
        return 0;
      }
      if (*(char *)(param_1 + 0x79) != '\0') {
        if (*(int *)(param_1 + 0x32c) == 0) {
          iVar2 = 3;
        }
        else {
          if (*(int *)(param_1 + 0x32c) != 2) goto LAB_40bf54e4;
          iVar2 = 2;
        }
        FUN_40bf9c98(*(int **)(param_1 + 0x328),param_1 + 0x240,iVar2);
      }
LAB_40bf54e4:
      uVar1 = 0;
      if (local_78 == '\0') {
        uVar1 = 2;
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x40))
                        (*(int **)(param_1 + 0x328),&local_74,0,0,uVar1);
      if (iVar2 < 0) {
        return iVar2;
      }
      (**(code **)(*local_74 + 0xc))(local_74,&local_60);
      memcpy(local_60,local_64,local_68);
      (**(code **)(*local_74 + 0x30))(local_74,local_68);
      (**(code **)(*local_74 + 0x28))(local_74,0);
      (**(code **)(*local_74 + 0x40))(local_74,*(char *)(param_1 + 0x79) != '\0');
      (**(code **)(*local_74 + 0x20))(local_74,0);
      *(undefined1 *)(param_1 + 0x79) = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_38[0] = 0;
      local_38[1] = 0;
      local_40 = 0;
      local_3c = 0;
      (**(code **)(*local_74 + 0x18))(local_74,&local_50,&local_48);
      (**(code **)(*local_74 + 0x48))(local_74,local_38,&local_40);
      iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x44))(*(int **)(param_1 + 0x328),local_74)
      ;
      (**(code **)(*local_74 + 8))();
      if (iVar2 < 0) {
        return iVar2;
      }
      FUN_40bf7d78(*(int *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x2d8),
                   *(int *)(param_1 + 0x328));
      if (local_77[0] != '\0') {
        iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x4c))();
        return iVar2;
      }
    }
    else if ((*(char *)(param_1 + 0x79) == '\0') || (local_78 != '\0')) {
      iVar2 = *(int *)(param_1 + 0x6c);
      local_4c = (local_4c - *(int *)(iVar2 + 0xac)) - (uint)(local_50 < *(uint *)(iVar2 + 0xa8));
      local_44 = (local_44 - *(int *)(iVar2 + 0xac)) - (uint)(local_48 < *(uint *)(iVar2 + 0xa8));
      local_50 = local_50 - *(uint *)(iVar2 + 0xa8);
      local_48 = local_48 - *(uint *)(iVar2 + 0xa8);
      FUN_40bf9e54(*(int *)(param_1 + 0x328),local_38 + 2);
      if (((local_4c < 0) || (local_4c < local_2c)) ||
         ((local_4c == local_2c && (local_50 <= local_38[2])))) {
        if (*(char *)(param_1 + 0x2dc) == '\0') goto LAB_40bf5b8c;
        if (*(char *)(param_1 + 0x79) != '\0') {
          if (*(int *)(param_1 + 0x32c) == 0) {
            iVar2 = 3;
          }
          else {
            if (*(int *)(param_1 + 0x32c) != 2) goto LAB_40bf59b4;
            iVar2 = 2;
          }
          FUN_40bf9c98(*(int **)(param_1 + 0x328),param_1 + 0x240,iVar2);
        }
LAB_40bf59b4:
        uVar1 = 0;
        if (local_78 == '\0') {
          uVar1 = 2;
        }
        iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x40))
                          (*(int **)(param_1 + 0x328),&local_6c,0,0,uVar1);
        if (iVar2 < 0) {
          return iVar2;
        }
        (**(code **)(*local_6c + 0xc))(local_6c,&local_58);
        memcpy(local_58,local_64,local_68);
        (**(code **)(*local_6c + 0x30))(local_6c,local_68);
        (**(code **)(*local_6c + 0x28))(local_6c,0);
        (**(code **)(*local_6c + 0x40))(local_6c,*(char *)(param_1 + 0x79) != '\0');
        (**(code **)(*local_6c + 0x20))(local_6c,0);
        *(undefined1 *)(param_1 + 0x79) = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        local_38[0] = 0;
        local_38[1] = 0;
        local_40 = 0;
        local_3c = 0;
        (**(code **)(*local_6c + 0x18))(local_6c,&local_50,&local_48);
        (**(code **)(*local_6c + 0x48))(local_6c,local_38,&local_40);
        iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x44))
                          (*(int **)(param_1 + 0x328),local_6c);
        (**(code **)(*local_6c + 8))();
        if (iVar2 < 0) {
          return iVar2;
        }
        FUN_40bf7d78(*(int *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x2d8),
                     *(int *)(param_1 + 0x328));
        if (local_77[0] != '\0') {
          iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x4c))();
          return iVar2;
        }
      }
      else if (*(char *)(param_1 + 0x2dc) == '\0') {
        WaitForSingleObject(*(HANDLE *)(param_1 + 0x70),0xffffffff);
        *(undefined1 *)(param_1 + 0x79) = 1;
        if ((int)uVar3 < (int)local_44) {
          return 0;
        }
        if ((local_44 == uVar3) && (uVar4 < local_48)) {
          return 0;
        }
      }
      else {
        if (*(char *)(param_1 + 0x79) != '\0') {
          if (*(int *)(param_1 + 0x32c) == 0) {
            iVar2 = 3;
          }
          else {
            if (*(int *)(param_1 + 0x32c) != 2) goto LAB_40bf5758;
            iVar2 = 2;
          }
          FUN_40bf9c98(*(int **)(param_1 + 0x328),param_1 + 0x240,iVar2);
        }
LAB_40bf5758:
        uVar1 = 0;
        if (local_78 == '\0') {
          uVar1 = 2;
        }
        iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x40))
                          (*(int **)(param_1 + 0x328),&local_70,0,0,uVar1);
        if (iVar2 < 0) {
          return iVar2;
        }
        (**(code **)(*local_70 + 0xc))(local_70,&local_5c);
        memcpy(local_5c,local_64,local_68);
        (**(code **)(*local_70 + 0x30))(local_70,local_68);
        (**(code **)(*local_70 + 0x18))(local_70,&local_50,&local_48);
        (**(code **)(*local_70 + 0x48))(local_70,local_38,&local_40);
        (**(code **)(*local_70 + 0x28))(local_70,0);
        (**(code **)(*local_70 + 0x40))(local_70,*(char *)(param_1 + 0x79) != '\0');
        (**(code **)(*local_70 + 0x20))(local_70,local_78 != '\0');
        *(undefined1 *)(param_1 + 0x79) = 0;
        iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x44))
                          (*(int **)(param_1 + 0x328),local_70);
        (**(code **)(*local_70 + 8))();
        if (iVar2 < 0) {
          return iVar2;
        }
        FUN_40bf7d78(*(int *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x2d8),
                     *(int *)(param_1 + 0x328));
        if (((int)uVar3 < (int)local_44) ||
           (((local_44 == uVar3 && (uVar4 < local_48)) || (local_77[0] != '\0')))) {
          iVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0x4c))();
          return iVar2;
        }
      }
    }
    iVar2 = FUN_40bfd9a8(param_1,&uStack_54);
    if (iVar2 != 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x78) != '\0') {
      return 0;
    }
  } while( true );
}



/* 40bf5bcc FUN_40bf5bcc */

/* Boundary evidence: original MIPS .pdata 40bf5bcc..40bf5f53. Semantic name remains unreviewed. */

int FUN_40bf5bcc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *local_58;
  undefined1 *local_54;
  undefined4 auStack_50 [2];
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20 [2];
  
  *(undefined1 *)(param_1 + 0x78) = 0;
  EventModify(*(undefined4 *)(param_1 + 0x70),2);
  *(undefined1 *)(param_1 + 0x79) = 1;
  FUN_40bfc224(*(int *)(param_1 + 0x6c),&local_38,&local_40);
  FUN_40bfc25c(*(int *)(param_1 + 0x6c),local_20);
  FUN_40bfda0c(param_1,0);
  if (*(char *)(param_1 + 0x2dc) != '\0') {
    (**(code **)(**(int **)(param_1 + 0x328) + 0x58))();
  }
  local_48 = 0;
  local_44 = 0;
  do {
    local_30 = local_48 + 10000000;
    local_2c = local_44 + (uint)(local_30 < local_48);
    FUN_40bf9e54(*(int *)(param_1 + 0x328),&local_28);
    if (*(char *)(param_1 + 0x2dc) == '\0') {
      if ((local_24 <= local_44) && ((local_44 != local_24 || (local_28 < local_48)))) {
        WaitForSingleObject(*(HANDLE *)(param_1 + 0x70),0xffffffff);
      }
      iVar1 = (local_3c - local_34) - (uint)(local_40 < local_38);
      *(undefined1 *)(param_1 + 0x79) = 1;
      if ((iVar1 < local_2c) ||
         (((local_2c == iVar1 && (local_40 - local_38 < local_30)) ||
          (*(char *)(*(int *)(param_1 + 0x6c) + 0xc0) != '\0')))) {
        return 0;
      }
    }
    else {
      if ((local_24 <= local_44) && ((local_44 != local_24 || (local_28 < local_48)))) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x328) + 0x40))
                          (*(int **)(param_1 + 0x328),&local_58,0,0,0);
        if (iVar1 < 0) {
          return iVar1;
        }
        (**(code **)(*local_58 + 0xc))(local_58,&local_54);
        *local_54 = 0;
        (**(code **)(*local_58 + 0x40))(local_58,*(undefined1 *)(param_1 + 0x79));
        (**(code **)(*local_58 + 0x20))(local_58,1);
        (**(code **)(*local_58 + 0x18))(local_58,&local_48,&local_30);
        if ((0 < local_44) || (uVar2 = 1, local_44 == 0)) {
          uVar2 = 0;
        }
        (**(code **)(*local_58 + 0x28))(local_58,uVar2);
        (**(code **)(*local_58 + 0x30))(local_58,1);
        iVar1 = (**(code **)(**(int **)(param_1 + 0x328) + 0x44))
                          (*(int **)(param_1 + 0x328),local_58);
        (**(code **)(*local_58 + 8))();
        if (iVar1 < 0) {
          return iVar1;
        }
        *(undefined1 *)(param_1 + 0x79) = 0;
        FUN_40bf7d78(*(int *)(param_1 + 0x6c),(uint)*(byte *)(param_1 + 0x2d8),
                     *(int *)(param_1 + 0x328));
      }
      iVar1 = (local_3c - local_34) - (uint)(local_40 < local_38);
      if ((iVar1 < local_2c) ||
         (((local_2c == iVar1 && (local_40 - local_38 < local_30)) ||
          (*(char *)(*(int *)(param_1 + 0x6c) + 0xc0) != '\0')))) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x328) + 0x4c))();
        return iVar1;
      }
    }
    local_48 = local_30;
    local_44 = local_2c;
    iVar1 = FUN_40bfd9a8(param_1,auStack_50);
    if (iVar1 != 0) {
      return 0;
    }
  } while (*(char *)(param_1 + 0x78) == '\0');
  return 0;
}



/* 40bf5f54 FUN_40bf5f54 */

void FUN_40bf5f54(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x79) = 1;
  *(undefined1 *)(param_1 + 0x2dc) = param_2;
  if (*(int *)(param_1 + 0x328) != 0) {
    *(int *)(*(int *)(param_1 + 0x328) + 0xa8) = param_1;
  }
  return;
}



/* 40bf5f74 FUN_40bf5f74 */

/* Boundary evidence: original MIPS .pdata 40bf5f74..40bf600b. Semantic name remains unreviewed. */

longlong FUN_40bf5f74(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = *(int *)(param_1 + 0x32c);
  if (iVar1 == 0xff) {
    return -1;
  }
  if ((iVar1 != 0) && (iVar1 != 2)) {
    iVar1 = *(int *)(param_1 + 0x228);
    lVar2 = FUN_40bfa974(*(uint *)(iVar1 + 0x10),*(int *)(iVar1 + 0x14),*(uint *)(iVar1 + 0x18),
                         *(int *)(iVar1 + 0x1c),param_3,param_4);
    return lVar2;
  }
  lVar2 = FUN_40bfa974(10000000,0,*(uint *)(param_1 + 0x2a8),(int)*(uint *)(param_1 + 0x2a8) >> 0x1f
                       ,param_3,param_4);
  return lVar2;
}



/* 40bf600c FUN_40bf600c */

/* Boundary evidence: original MIPS .pdata 40bf600c..40bf65df. Semantic name remains unreviewed. */

void FUN_40bf600c(undefined4 param_1,char *param_2,undefined4 *param_3,int *param_4,int *param_5)

{
  char cVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  LPVOID _Dst;
  undefined1 *_Dst_00;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined4 *_Buf1;
  uint _Size;
  uint uVar9;
  
  pcVar7 = "video";
  pcVar6 = param_2;
  do {
    cVar1 = *pcVar6;
    cVar2 = *pcVar7;
    if (cVar1 == '\0') break;
    if (cVar1 != cVar2) goto LAB_40bf6230;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (pcVar6 != param_2 + 5);
  if (cVar1 == cVar2) {
    FUN_40bfce84(param_3);
    FUN_40bfcd6c(param_3,&DAT_40c049e4);
    FUN_40bfcd90((int)param_3,(undefined4 *)&DAT_40c04b04);
    _Buf1 = param_3 + 4;
    *_Buf1 = *(undefined4 *)(param_2 + 8);
    iVar4 = memcmp(_Buf1,&DAT_40c04c84,0x10);
    if (((((iVar4 != 0) && (iVar4 = memcmp(_Buf1,&DAT_40c04c94,0x10), iVar4 != 0)) &&
         (iVar4 = memcmp(_Buf1,&DAT_40c04ca4,0x10), iVar4 != 0)) &&
        ((iVar4 = memcmp(_Buf1,&DAT_40c04cb4,0x10), iVar4 != 0 &&
         (iVar4 = memcmp(_Buf1,&DAT_40c04af4,0x10), iVar4 != 0)))) &&
       ((iVar4 = memcmp(_Buf1,&DAT_40c04b14,0x10), iVar4 != 0 &&
        (iVar4 = memcmp(_Buf1,&DAT_40c04b04,0x10), iVar4 != 0)))) {
      FUN_40bfcdbc((int)param_3,1);
      FUN_40bfcdb4((int)param_3);
    }
    FUN_40bfcdc4((int)param_3,(undefined4 *)&DAT_40c05594);
    _Dst = FUN_40bfcde8((int)param_3,0x58);
    memset(_Dst,0,0x58);
    *(undefined4 *)((int)_Dst + 0x28) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)((int)_Dst + 0x2c) = *(undefined4 *)(param_2 + 0x14);
    uVar3 = *(undefined2 *)(param_2 + 0x28);
    *(undefined4 *)((int)_Dst + 0x30) = 0x28;
    *(undefined2 *)((int)_Dst + 0x3e) = uVar3;
    *(undefined2 *)((int)_Dst + 0x3c) = 1;
    *(undefined4 *)((int)_Dst + 0x34) = *(undefined4 *)(param_2 + 0x2c);
    *(undefined4 *)((int)_Dst + 0x38) = *(undefined4 *)(param_2 + 0x30);
    *(undefined4 *)((int)_Dst + 0x40) = *(undefined4 *)(param_2 + 8);
    iVar4 = *(int *)(param_2 + 0x24) * 10;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    iVar8 = iVar4 >> 0xc;
    *param_4 = iVar8;
    iVar4 = iVar4 >> 0xd;
    if (iVar8 < 0) {
      iVar4 = iVar8 + 1 >> 1;
    }
    *param_5 = iVar4;
    return;
  }
LAB_40bf6230:
  pcVar7 = "audio";
  pcVar6 = param_2;
  do {
    cVar1 = *pcVar6;
    cVar2 = *pcVar7;
    if (cVar1 == '\0') break;
    if (cVar1 != cVar2) goto LAB_40bf6554;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  } while (pcVar6 != param_2 + 5);
  if (cVar1 != cVar2) {
LAB_40bf6554:
    pcVar6 = "text";
    pcVar7 = param_2 + 4;
    do {
      cVar1 = *param_2;
      cVar2 = *pcVar6;
      if (cVar1 == '\0') break;
      if (cVar1 != cVar2) {
        return;
      }
      param_2 = param_2 + 1;
      pcVar6 = pcVar6 + 1;
    } while (param_2 != pcVar7);
    if (cVar1 != cVar2) {
      return;
    }
    FUN_40bfce84(param_3);
    FUN_40bfcd6c(param_3,(undefined4 *)&DAT_40c04a24);
    *param_4 = 0x14;
    *param_5 = -1;
    return;
  }
  iVar4 = (int)param_2[8];
  uVar9 = 0;
  if ((iVar4 < 0x30) || (0x39 < iVar4)) {
    if ((0x40 < iVar4) && (iVar4 < 0x47)) {
      uVar9 = iVar4 + 0xffc9;
      goto LAB_40bf62e0;
    }
    if ((0x60 < iVar4) && (iVar4 < 0x67)) {
      uVar9 = iVar4 + 0xffa9;
      goto LAB_40bf62e0;
    }
  }
  else {
    uVar9 = iVar4 + 0xffd0;
LAB_40bf62e0:
    uVar9 = (uVar9 & 0xf) << 0xc;
  }
  iVar4 = (int)param_2[9];
  if ((iVar4 < 0x30) || (0x39 < iVar4)) {
    if ((0x40 < iVar4) && (iVar4 < 0x47)) {
      iVar4 = iVar4 + 0xffc9;
      goto LAB_40bf634c;
    }
    if ((0x60 < iVar4) && (iVar4 < 0x67)) {
      iVar4 = iVar4 + 0xffa9;
      goto LAB_40bf634c;
    }
  }
  else {
    iVar4 = iVar4 + 0xffd0;
LAB_40bf634c:
    uVar9 = iVar4 * 0x100 + uVar9 & 0xffff;
  }
  iVar4 = (int)param_2[10];
  if ((iVar4 < 0x30) || (0x39 < iVar4)) {
    if ((0x40 < iVar4) && (iVar4 < 0x47)) {
      iVar4 = iVar4 + 0xffc9;
      goto LAB_40bf63bc;
    }
    if ((0x60 < iVar4) && (iVar4 < 0x67)) {
      iVar4 = iVar4 + 0xffa9;
      goto LAB_40bf63bc;
    }
  }
  else {
    iVar4 = iVar4 + 0xffd0;
LAB_40bf63bc:
    uVar9 = iVar4 * 0x10 + uVar9 & 0xffff;
  }
  iVar4 = (int)param_2[0xb];
  if ((iVar4 < 0x30) || (0x39 < iVar4)) {
    if ((iVar4 < 0x41) || (0x46 < iVar4)) {
      if ((iVar4 < 0x61) || (0x66 < iVar4)) goto LAB_40bf643c;
      uVar9 = iVar4 + uVar9 + 0xffa9;
    }
    else {
      uVar9 = iVar4 + uVar9 + 0xffc9;
    }
  }
  else {
    uVar9 = iVar4 + uVar9 + 0xffd0;
  }
  uVar9 = uVar9 & 0xffff;
LAB_40bf643c:
  FUN_40bfce84(param_3);
  FUN_40bfcd6c(param_3,(undefined4 *)&DAT_40c049f4);
  FUN_40bfcd90((int)param_3,(undefined4 *)&DAT_40c04dd4);
  param_3[4] = uVar9;
  FUN_40bfcdc4((int)param_3,(undefined4 *)&DAT_40c055b4);
  _Size = *(int *)(param_2 + 0xc) - 0x38;
  _Dst_00 = FUN_40bfcde8((int)param_3,*(int *)(param_2 + 0xc) - 0x26);
  memset(_Dst_00,0,0x12);
  uVar5 = _Size & 0xffff;
  _Dst_00[0x10] = (char)uVar5;
  _Dst_00[0x11] = (char)(uVar5 >> 8);
  memcpy(_Dst_00 + 0x12,param_2 + 0x38,_Size);
  *(undefined4 *)(_Dst_00 + 8) = *(undefined4 *)(param_2 + 0x30);
  uVar3 = *(undefined2 *)(param_2 + 0x2e);
  _Dst_00[0xc] = (char)uVar3;
  _Dst_00[0xd] = (char)((ushort)uVar3 >> 8);
  uVar3 = *(undefined2 *)(param_2 + 0x2c);
  _Dst_00[3] = (char)((ushort)uVar3 >> 8);
  _Dst_00[2] = (char)uVar3;
  *(undefined4 *)(_Dst_00 + 4) = *(undefined4 *)(param_2 + 0x18);
  uVar3 = *(undefined2 *)(param_2 + 0x28);
  _Dst_00[0xe] = (char)uVar3;
  _Dst_00[0xf] = (char)((ushort)uVar3 >> 8);
  *_Dst_00 = (char)uVar9;
  _Dst_00[1] = (char)(uVar9 >> 8);
  iVar4 = *(int *)(param_2 + 0x24) * 10;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xfff;
  }
  iVar8 = iVar4 >> 0xc;
  *param_4 = iVar8;
  iVar4 = iVar4 >> 0xd;
  if (iVar8 < 0) {
    iVar4 = iVar8 + 1 >> 1;
  }
  *param_5 = iVar4;
  return;
}



/* 40bf65e0 FUN_40bf65e0 */

/* Boundary evidence: original MIPS .pdata 40bf65e0..40bf6723. Semantic name remains unreviewed. */

void FUN_40bf65e0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  FUN_40bfce84(param_3);
  FUN_40bfcd6c(param_3,(undefined4 *)&DAT_40c049f4);
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_40bfcd90((int)param_3,(undefined4 *)&DAT_40c060a4);
    FUN_40bfcdc4((int)param_3,(undefined4 *)&DAT_40c055b4);
    puVar2 = FUN_40bfcde8((int)param_3,0x12);
    uVar1 = *(undefined2 *)(param_2 + 4);
    puVar2[2] = (char)uVar1;
    puVar2[3] = (char)((ushort)uVar1 >> 8);
    uVar4 = *(undefined4 *)(param_2 + 8);
    puVar2[0xe] = 0x10;
    *(undefined4 *)(puVar2 + 4) = uVar4;
    puVar2[0xf] = 0;
    puVar2[0x11] = 0;
    *puVar2 = 9;
    puVar2[0x10] = 0;
    puVar2[1] = 0xa1;
    puVar2[0xc] = 0x40;
    puVar2[0xd] = 0;
    *(undefined4 *)(puVar2 + 8) = 0x40;
    return;
  }
  FUN_40bfcd90((int)param_3,(undefined4 *)&DAT_40c06034);
  FUN_40bfcdc4((int)param_3,(undefined4 *)&DAT_40c05de4);
  puVar3 = FUN_40bfcde8((int)param_3,0x18);
  *puVar3 = (short)*(undefined4 *)(param_2 + 4);
  *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(puVar3 + 4) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(puVar3 + 6) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(param_2 + 0x10);
  return;
}



/* 40bf6724 FUN_40bf6724 */

/* Boundary evidence: original MIPS .pdata 40bf6724..40bf681f. Semantic name remains unreviewed. */

undefined4 FUN_40bf6724(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  char local_20 [8];
  uint local_18;
  uint local_14;
  
  FUN_40bf2674((int *)(param_1 + 0xc0),param_2);
  iVar1 = FUN_40bfb580((char *)(param_1 + 0x90),*(int *)(param_1 + 0x228),0,local_20,(uint *)0x0,
                       (uint *)0x0,(longlong *)&local_18,(longlong *)0x0,(undefined4 *)0x0,
                       (int *)0x0);
  do {
    if (iVar1 < 1) {
      return 0;
    }
    if (local_20[0] != '\0') {
      if (((int)param_3[1] < (int)local_14) || ((local_14 == param_3[1] && (*param_3 <= local_18))))
      {
        *param_3 = local_18;
        param_3[1] = local_14;
        return 1;
      }
    }
    iVar1 = FUN_40bfb580((char *)(param_1 + 0x90),*(int *)(param_1 + 0x228),0,local_20,(uint *)0x0,
                         (uint *)0x0,(longlong *)&local_18,(longlong *)0x0,(undefined4 *)0x0,
                         (int *)0x0);
  } while( true );
}



/* 40bf6820 FUN_40bf6820 */

/* Boundary evidence: original MIPS .pdata 40bf6820..40bf6aab. Semantic name remains unreviewed. */

undefined4 FUN_40bf6820(int param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint *puVar4;
  int *piVar5;
  int *piVar6;
  byte *local_48 [8];
  
  if (*(char *)(param_1 + 0x330) == '\0') {
    piVar6 = (int *)(param_1 + 0xc0);
    FUN_40bf2674(piVar6,param_2);
    iVar1 = FUN_40bf2ce0(piVar6,(int *)local_48);
    while (0 < iVar1) {
      bVar3 = *local_48[0] & 7;
      if (bVar3 == 1) {
        piVar5 = (int *)(param_1 + 0x228);
        iVar1 = FUN_40bfb3bc(piVar5,(int *)local_48);
        if (iVar1 == 0) {
          param_4 = (int *)(param_1 + 0x2c8);
          FUN_40bf600c(param_1,(char *)*piVar5,(undefined4 *)(param_1 + 0x2e0),param_4,
                       (int *)(param_1 + 0x2c4));
          *(undefined4 *)(param_1 + 0x2cc) = *(undefined4 *)(*piVar5 + 0x24);
          *(undefined4 *)(param_1 + 0x2a8) = 1;
          *(undefined4 *)(param_1 + 0x32c) = 1;
        }
        else {
          iVar1 = FUN_40bf3ab8((uint *)(param_1 + 0x2a0),(int *)(param_1 + 0x22c),local_48,
                               (va_list)param_4);
          if (iVar1 < 0) {
            if (*(int *)(param_1 + 0x32c) != 2) {
              FUN_40bfcd6c((undefined4 *)(param_1 + 0x2e0),(undefined4 *)&DAT_40c06f08);
              *(undefined1 *)(param_1 + 0x330) = 0;
              *(undefined4 *)(param_1 + 0x32c) = 0xff;
              return 1;
            }
LAB_40bf68c4:
            puVar2 = (undefined4 *)(param_1 + 0x260);
LAB_40bf68c8:
            FUN_40bf1788(puVar2,local_48);
            *(undefined1 *)(param_1 + 0x330) = 1;
            return 0;
          }
          FUN_40bf1788((undefined4 *)(param_1 + 0x240),local_48);
          FUN_40bf65e0(param_1,param_1 + 0x2a0,(undefined4 *)(param_1 + 0x2e0));
          *(undefined4 *)(param_1 + 0x2cc) = 0x2000;
          *(undefined4 *)(param_1 + 0x2c4) = 0x20;
          *(undefined4 *)(param_1 + 0x2c8) = 0x10;
          *(undefined4 *)(param_1 + 0x32c) = 0;
        }
      }
      else if (bVar3 == 3) {
        puVar4 = (uint *)(param_1 + 0x2a0);
        iVar1 = FUN_40bf3ab8(puVar4,(int *)(param_1 + 0x22c),local_48,(va_list)param_4);
        if (iVar1 < 0) {
          iVar1 = FUN_40bf3e84((int)puVar4,(int *)(param_1 + 0x22c),local_48);
          if (iVar1 < 0) {
            return 1;
          }
          FUN_40bf1788((undefined4 *)(param_1 + 0x240),local_48);
          *(undefined4 *)(param_1 + 0x2ac) = 1;
          *(undefined4 *)(param_1 + 0x32c) = 2;
          FUN_40bf65e0(param_1,(int)puVar4,(undefined4 *)(param_1 + 0x2e0));
          *(undefined4 *)(param_1 + 0x2c4) = 0x20;
          *(undefined4 *)(param_1 + 0x2cc) = 0x2000;
          *(undefined4 *)(param_1 + 0x2c8) = 0x10;
          FUN_40bf1788((undefined4 *)(param_1 + 0x260),local_48);
        }
        else {
          FUN_40bf1788((undefined4 *)(param_1 + 0x260),local_48);
        }
      }
      else if (bVar3 == 5) {
        if (*(int *)(param_1 + 0x32c) == 0) {
          iVar1 = FUN_40bf3ab8((uint *)(param_1 + 0x2a0),(int *)(param_1 + 0x22c),local_48,
                               (va_list)param_4);
          if (iVar1 < 0) {
            return 1;
          }
          puVar2 = (undefined4 *)(param_1 + 0x280);
          goto LAB_40bf68c8;
        }
        if (*(int *)(param_1 + 0x32c) == 2) goto LAB_40bf68c4;
      }
      iVar1 = FUN_40bf2ce0(piVar6,(int *)local_48);
    }
  }
  return 0;
}



/* 40bf6aac FUN_40bf6aac */

/* Boundary evidence: original MIPS .pdata 40bf6aac..40bf6b77. Semantic name remains unreviewed. */

undefined4 FUN_40bf6aac(int param_1)

{
  int iVar1;
  
  while( true ) {
    while( true ) {
      while (iVar1 = FUN_40bfd970(param_1), iVar1 == 1) {
        if (*(char *)(param_1 + 0x2d0) == '\0') {
          FUN_40bf530c(param_1);
        }
        else {
          FUN_40bf5bcc(param_1);
        }
      }
      if (iVar1 != 2) break;
      FUN_40bfda0c(param_1,0);
    }
    if (iVar1 == 3) break;
    FUN_40bfda0c(param_1,0x80004001);
  }
  FUN_40bfda0c(param_1,0);
  return 0;
}



/* 40bf6b78 FUN_40bf6b78 */

/* Boundary evidence: original MIPS .pdata 40bf6b78..40bf6c63. Semantic name remains unreviewed. */

void FUN_40bf6b78(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40c03b5c;
  param_1[2] = &PTR_FUN_40c03b38;
  param_1[5] = &PTR_LAB_40c03afc;
  param_1[6] = &PTR_LAB_40c03ae8;
  if (param_1[0x16] != 0) {
    piVar1 = (int *)(param_1[0x16] + 0x40);
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
  }
  if ((void *)param_1[0x1c] != (void *)0x0) {
    operator_delete((void *)param_1[0x1c]);
  }
  if (DAT_40c0817c != 0) {
    CloseHandle((HANDLE)DAT_40c0817c);
    DAT_40c0817c = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1f));
  FUN_40bff25c((int)(param_1 + 2));
  return;
}



/* 40bf6c64 FUN_40bf6c64 */

/* Boundary evidence: original MIPS .pdata 40bf6c64..40bf6cb7. Semantic name remains unreviewed. */

void FUN_40bf6c64(void)

{
  int *in_v0;
  
  if (*in_v0 == 0) {
    in_v0[-8] = 0;
  }
  else {
    in_v0[-8] = *in_v0 + 8;
  }
  FUN_40bff25c(in_v0[-8]);
  return;
}



/* 40bf6cb8 FUN_40bf6cb8 */

/* Boundary evidence: original MIPS .pdata 40bf6cb8..40bf6ceb. Semantic name remains unreviewed. */

void FUN_40bf6cb8(void)

{
  int *in_v0;
  
  FUN_40bf42d4((LPCRITICAL_SECTION)(*in_v0 + 0x7c));
  return;
}



/* 40bf6cec FUN_40bf6cec */

/* Boundary evidence: original MIPS .pdata 40bf6cec..40bf6d13. Semantic name remains unreviewed. */

void FUN_40bf6cec(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))();
  return;
}



/* 40bf6d14 FUN_40bf6d14 */

/* Boundary evidence: original MIPS .pdata 40bf6d14..40bf6d3b. Semantic name remains unreviewed. */

void FUN_40bf6d14(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))();
  return;
}



/* 40bf6d3c FUN_40bf6d3c */

/* Boundary evidence: original MIPS .pdata 40bf6d3c..40bf6d63. Semantic name remains unreviewed. */

void FUN_40bf6d3c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  return;
}



/* 40bf6d64 FUN_40bf6d64 */

/* Boundary evidence: original MIPS .pdata 40bf6d64..40bf6def. Semantic name remains unreviewed. */

undefined4 FUN_40bf6d64(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c06ad0,0x10);
  if (iVar1 == 0) {
    if (param_3 == (undefined4 *)0x0) {
      uVar2 = 0x80004003;
    }
    else {
      uVar2 = FUN_40c00ca4(param_1 + -2,param_3);
    }
  }
  else {
    uVar2 = FUN_40bff17c(param_1,param_2,param_3);
  }
  return uVar2;
}



/* 40bf6df0 FUN_40bf6df0 */

/* Boundary evidence: original MIPS .pdata 40bf6df0..40bf6e37. Semantic name remains unreviewed. */

int FUN_40bf6df0(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  iVar1 = *(int *)(param_1 + 0x54);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  return iVar1 + 1;
}



/* 40bf6e38 FUN_40bf6e38 */

/* Boundary evidence: original MIPS .pdata 40bf6e38..40bf6ee3. Semantic name remains unreviewed. */

int FUN_40bf6e38(int param_1,int param_2)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x74);
  EnterCriticalSection(lpCriticalSection);
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x50) + 0x40;
    if (*(int *)(param_1 + 0x50) == 0) {
      iVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  else if ((param_2 < 1) || (*(int *)(param_1 + 0x54) < param_2)) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x58) + param_2 * 4 + -4);
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40bf6ee4 FUN_40bf6ee4 */

int FUN_40bf6ee4(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    piVar1 = *(int **)(param_1 + 0x68);
    do {
      if (*(int *)(*piVar1 + 0x2d4) == param_2) {
        return (*(int **)(param_1 + 0x68))[iVar2];
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < *(int *)(param_1 + 100));
  }
  return 0;
}



/* 40bf6f34 FUN_40bf6f34 */

/* Boundary evidence: original MIPS .pdata 40bf6f34..40bf6fc7. Semantic name remains unreviewed. */

int FUN_40bf6f34(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *(int *)(param_1 + 100);
  iVar2 = 0;
  if (0 < iVar4) {
    piVar5 = *(int **)(param_1 + 0x68);
    piVar3 = piVar5;
    do {
      iVar1 = memcmp((void *)(*piVar3 + 0x2e0),param_2,0x10);
      if (iVar1 == 0) {
        return piVar5[iVar2];
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < iVar4);
  }
  return 0;
}



/* 40bf6fc8 FUN_40bf6fc8 */

/* Boundary evidence: original MIPS .pdata 40bf6fc8..40bf70e7. Semantic name remains unreviewed. */

void FUN_40bf6fc8(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *local_20;
  LPCRITICAL_SECTION local_1c;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x7c);
  local_1c = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x5c)) {
    iVar3 = 0;
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x60) + iVar3);
      if (*(int *)(iVar2 + 0x18) != 0) {
        piVar1 = (int *)(iVar2 + 0xc);
        (**(code **)(*piVar1 + 0x18))(piVar1,&local_20);
        (**(code **)(*local_20 + 0x14))();
        (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x60) + iVar3) + 0xc) + 0x14))();
      }
      piVar1 = *(int **)(*(int *)(param_1 + 0x60) + iVar3);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0xc))(piVar1,1);
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < *(int *)(param_1 + 0x5c));
  }
  operator_delete(*(void **)(param_1 + 0x60));
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return;
}



/* 40bf70e8 FUN_40bf70e8 */

/* Boundary evidence: original MIPS .pdata 40bf70e8..40bf7117. Semantic name remains unreviewed. */

void FUN_40bf70e8(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40bf7118 FUN_40bf7118 */

/* Boundary evidence: original MIPS .pdata 40bf7118..40bf726b. Semantic name remains unreviewed. */

undefined4 FUN_40bf7118(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  void *_Dst;
  undefined4 uVar2;
  uint uVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x7c);
  EnterCriticalSection(lpCriticalSection);
  puVar1 = operator_new(0x338);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40bf489c(puVar1,param_3,param_1,param_4);
  }
  *param_2 = puVar1;
  uVar3 = *(int *)(param_1 + 100) + 1;
  if (uVar3 < 0x40000000) {
    uVar3 = uVar3 * 4;
  }
  else {
    uVar3 = 0xffffffff;
  }
  _Dst = operator_new(uVar3);
  if (_Dst == (void *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    uVar2 = 0x8007000e;
  }
  else {
    if (*(void **)(param_1 + 0x68) != (void *)0x0) {
      memcpy(_Dst,*(void **)(param_1 + 0x68),*(int *)(param_1 + 100) << 2);
      operator_delete(*(void **)(param_1 + 0x68));
    }
    *(void **)(param_1 + 0x68) = _Dst;
    *(undefined4 *)(*(int *)(param_1 + 100) * 4 + (int)_Dst) = *param_2;
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
    LeaveCriticalSection(lpCriticalSection);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bf726c FUN_40bf726c */

/* Boundary evidence: original MIPS .pdata 40bf726c..40bf729b. Semantic name remains unreviewed. */

void FUN_40bf726c(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40bf729c FUN_40bf729c */

/* Boundary evidence: original MIPS .pdata 40bf729c..40bf72cb. Semantic name remains unreviewed. */

void FUN_40bf729c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x24));
  return;
}



/* 40bf72cc FUN_40bf72cc */

/* Boundary evidence: original MIPS .pdata 40bf72cc..40bf746b. Semantic name remains unreviewed. */

undefined4 FUN_40bf72cc(int param_1,int param_2,undefined4 *param_3,int param_4,byte param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *_Dst;
  uint uVar3;
  size_t _Size;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x7c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 100) < param_2) {
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0x80004005;
  }
  else {
    puVar2 = operator_new(0x338);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40bf489c(puVar2,param_4,param_1,(uint)param_5);
    }
    *param_3 = puVar2;
    uVar3 = *(int *)(param_1 + 100) + 1;
    if (uVar3 < 0x40000000) {
      uVar3 = uVar3 * 4;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Dst = operator_new(uVar3);
    if (_Dst == (void *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      uVar1 = 0x8007000e;
    }
    else {
      if (*(void **)(param_1 + 0x68) != (void *)0x0) {
        _Size = param_2 * 4;
        memcpy(_Dst,*(void **)(param_1 + 0x68),_Size);
        memcpy((void *)((int)_Dst + _Size + 4),(void *)(*(int *)(param_1 + 0x68) + _Size),
               (*(int *)(param_1 + 100) - param_2) * 4);
        operator_delete(*(void **)(param_1 + 0x68));
      }
      *(void **)(param_1 + 0x68) = _Dst;
      *(undefined4 *)(param_2 * 4 + (int)_Dst) = *param_3;
      *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
      LeaveCriticalSection(lpCriticalSection);
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40bf746c FUN_40bf746c */

/* Boundary evidence: original MIPS .pdata 40bf746c..40bf749b. Semantic name remains unreviewed. */

void FUN_40bf746c(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40bf749c FUN_40bf749c */

/* Boundary evidence: original MIPS .pdata 40bf749c..40bf74cb. Semantic name remains unreviewed. */

void FUN_40bf749c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x24));
  return;
}



/* 40bf74cc FUN_40bf74cc */

/* Boundary evidence: original MIPS .pdata 40bf74cc..40bf76f3. Semantic name remains unreviewed. */

void FUN_40bf74cc(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack_2c;
  
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    iVar7 = 0;
    do {
      iVar3 = *(int *)(iVar7 + *(int *)(param_1 + 0x68));
      iVar8 = -1;
      *(undefined4 *)(iVar3 + 0x2d8) = 0xffffffff;
      if (0 < iVar9) {
        iVar5 = 0;
        iVar6 = iVar9;
        do {
          iVar4 = *(int *)(iVar5 + *(int *)(param_1 + 0x68));
          if (iVar8 < *(int *)(iVar4 + 0x2d8)) {
            iVar8 = *(int *)(*(int *)(iVar5 + *(int *)(param_1 + 0x68)) + 0x2d8);
          }
          iVar1 = memcmp((void *)(iVar3 + 0x2e0),(void *)(iVar4 + 0x2e0),0x10);
          if ((iVar1 == 0) &&
             (iVar4 = memcmp((void *)(iVar3 + 0x2f0),(void *)(iVar4 + 0x2f0),0x10), iVar4 == 0)) {
            *(undefined4 *)(*(int *)(iVar7 + *(int *)(param_1 + 0x68)) + 0x2d8) =
                 *(undefined4 *)(*(int *)(iVar5 + *(int *)(param_1 + 0x68)) + 0x2d8);
            FUN_40bf5f54(*(int *)(iVar7 + *(int *)(param_1 + 0x68)),*(undefined1 *)(param_1 + 0x76))
            ;
          }
          iVar6 = iVar6 + -1;
          iVar5 = iVar5 + 4;
        } while (iVar6 != 0);
      }
      iVar3 = *(int *)(iVar7 + *(int *)(param_1 + 0x68));
      if (*(int *)(iVar3 + 0x2d8) == -1) {
        iVar3 = memcmp((void *)(iVar3 + 0x2e0),&DAT_40c04a24,0x10);
        if ((iVar3 == 0) && (*(char *)(param_1 + 0x76) == '\0')) {
          FUN_40bf72cc(param_1,iVar9,&uStack_2c,0xffff,1);
          *(int *)(*(int *)(iVar7 + *(int *)(param_1 + 0x68)) + 0x2d8) = iVar8 + 1;
          FUN_40bf5f54(*(int *)(iVar7 + *(int *)(param_1 + 0x68)),1);
          iVar7 = iVar7 + 4;
          iVar9 = iVar9 + 1;
          uVar2 = 0;
          *(int *)(*(int *)(iVar7 + *(int *)(param_1 + 0x68)) + 0x2d8) = iVar8 + 1;
        }
        else {
          uVar2 = 1;
          *(int *)(*(int *)(iVar7 + *(int *)(param_1 + 0x68)) + 0x2d8) = iVar8 + 1;
        }
        FUN_40bf5f54(*(int *)(iVar7 + *(int *)(param_1 + 0x68)),uVar2);
      }
      iVar9 = iVar9 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar9 < *(int *)(param_1 + 100));
  }
  return;
}



/* 40bf76f4 FUN_40bf76f4 */

/* Boundary evidence: original MIPS .pdata 40bf76f4..40bf796b. Semantic name remains unreviewed. */

void FUN_40bf76f4(int param_1)

{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  char *_Source;
  char *_Dest;
  uint uVar4;
  int iVar5;
  int iVar6;
  char acStack_50 [32];
  uint local_30;
  
  local_30 = DAT_40c08174;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  if (*(void **)(param_1 + 0x70) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x70));
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    do {
      iVar5 = 1;
      while( true ) {
        sprintf(acStack_50,"CHAPTER%02d",iVar5);
        iVar1 = FUN_40bf305c((int *)(*(int *)(*(int *)(param_1 + 0x68) + iVar6 * 4) + 0x22c),
                             acStack_50,0);
        iVar5 = iVar5 + 1;
        if (iVar1 == 0) break;
        *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 100));
  }
  uVar4 = *(uint *)(param_1 + 0x6c);
  if (uVar4 != 0) {
    if (uVar4 < 0x38e38e4) {
      uVar4 = uVar4 * 0x48;
    }
    else {
      uVar4 = 0xffffffff;
    }
    pvVar2 = operator_new(uVar4);
    iVar6 = 0;
    *(void **)(param_1 + 0x70) = pvVar2;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    if (0 < *(int *)(param_1 + 100)) {
      do {
        iVar5 = 1;
        do {
          sprintf(acStack_50,"CHAPTER%02d",iVar5);
          pcVar3 = (char *)FUN_40bf305c((int *)(*(int *)(*(int *)(param_1 + 0x68) + iVar6 * 4) +
                                               0x22c),acStack_50,0);
          if (pcVar3 != (char *)0x0) {
            sprintf(acStack_50,"CHAPTER%02dNAME",iVar5);
            _Source = (char *)FUN_40bf305c((int *)(*(int *)(*(int *)(param_1 + 0x68) + iVar6 * 4) +
                                                  0x22c),acStack_50,0);
            _Dest = (char *)(*(int *)(param_1 + 0x6c) * 0x48 + *(int *)(param_1 + 0x70));
            if (_Source == (char *)0x0) {
              sprintf(_Dest,"Chapter %d",iVar5);
            }
            else {
              strcpy(_Dest,_Source);
            }
            iVar1 = FUN_40bf14b0(pcVar3,(uint *)(*(int *)(param_1 + 0x6c) * 0x48 +
                                                 *(int *)(param_1 + 0x70) + 0x40));
            if (iVar1 == 0) {
              iVar1 = *(int *)(param_1 + 0x6c) * 0x48 + *(int *)(param_1 + 0x70);
              *(undefined4 *)(iVar1 + 0x40) = 0;
              *(undefined4 *)(iVar1 + 0x44) = 0;
            }
            *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
          }
          iVar5 = iVar5 + 1;
        } while (pcVar3 != (char *)0x0);
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(param_1 + 100));
    }
  }
  FUN_40c0209c(local_30);
  return;
}



/* 40bf796c FUN_40bf796c */

/* Boundary evidence: original MIPS .pdata 40bf796c..40bf7d17. Semantic name remains unreviewed. */

undefined4 FUN_40bf796c(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *_Format;
  undefined *_Buf2;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_100;
  undefined *local_fc;
  LPCRITICAL_SECTION local_f8;
  undefined4 *local_f4;
  char acStack_f0 [64];
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_40c08174;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x7c);
  local_f8 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  iVar10 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    _Buf2 = &DAT_40c06f08;
    iVar9 = 0;
    local_fc = &DAT_40c06f08;
    do {
      piVar7 = (int *)(iVar9 + *(int *)(param_1 + 0x68));
      if (*(char *)(*piVar7 + 0x2dc) != '\0') {
        pvVar8 = (void *)(*piVar7 + 0x2e0);
        iVar1 = memcmp(pvVar8,_Buf2,0x10);
        _Buf2 = local_fc;
        if (iVar1 != 0) {
          local_100 = 0;
          iVar1 = memcmp(pvVar8,&DAT_40c049e4,0x10);
          if (iVar1 == 0) {
            uVar3 = *(undefined4 *)(*piVar7 + 0x2d4);
            _Format = "Video %d";
          }
          else {
            iVar1 = memcmp(pvVar8,&DAT_40c049f4,0x10);
            if (iVar1 == 0) {
              uVar3 = *(undefined4 *)(*piVar7 + 0x2d4);
              _Format = "Audio %d";
            }
            else {
              iVar1 = memcmp(pvVar8,&DAT_40c04a24,0x10);
              uVar3 = *(undefined4 *)(*piVar7 + 0x2d4);
              _Format = "Subtitle %d";
              if (iVar1 != 0) {
                _Format = "Stream %d";
              }
            }
          }
          sprintf(acStack_f0,_Format,uVar3);
          wsprintfW(aWStack_b0,L"%s",acStack_f0);
          local_f4 = operator_new(200);
          if (local_f4 == (undefined4 *)0x0) {
            puVar2 = (undefined4 *)0x0;
          }
          else {
            puVar2 = FUN_40bf9eac(local_f4,aWStack_b0,param_1,lpCriticalSection,&local_100,
                                  aWStack_b0);
          }
          if (local_100 < 0) {
            LeaveCriticalSection(lpCriticalSection);
            FUN_40c0209c(local_30);
            return 0x8007000e;
          }
          uVar4 = *(int *)(param_1 + 0x5c) + 1;
          if (uVar4 < 0x40000000) {
            uVar4 = uVar4 * 4;
          }
          else {
            uVar4 = 0xffffffff;
          }
          pvVar8 = operator_new(uVar4);
          if (pvVar8 == (void *)0x0) {
            LeaveCriticalSection(lpCriticalSection);
            FUN_40c0209c(local_30);
            return 0x8007000e;
          }
          if (*(void **)(param_1 + 0x60) != (void *)0x0) {
            memcpy(pvVar8,*(void **)(param_1 + 0x60),*(int *)(param_1 + 0x5c) << 2);
            operator_delete(*(void **)(param_1 + 0x60));
          }
          *(void **)(param_1 + 0x60) = pvVar8;
          *(undefined4 **)(*(int *)(param_1 + 0x5c) * 4 + (int)pvVar8) = puVar2;
          *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
          *(undefined4 **)(*(int *)(iVar9 + *(int *)(param_1 + 0x68)) + 0x328) = puVar2;
          puVar2[0x2a] = *(undefined4 *)(iVar9 + *(int *)(param_1 + 0x68));
          _Buf2 = local_fc;
        }
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 4;
    } while (iVar10 < *(int *)(param_1 + 100));
  }
  iVar10 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    iVar9 = 0;
    do {
      piVar7 = *(int **)(param_1 + 0x68);
      iVar1 = *(int *)(iVar9 + (int)piVar7);
      if (*(char *)(iVar1 + 0x2dc) == '\0') {
        iVar5 = 0;
        piVar6 = piVar7;
        if (0 < *(int *)(param_1 + 100)) {
          do {
            if ((*(char *)(*piVar6 + 0x2dc) != '\0') &&
               (*(int *)(*piVar6 + 0x2d8) == *(int *)(iVar1 + 0x2d8))) {
              uVar3 = *(undefined4 *)(piVar7[iVar5] + 0x328);
              goto LAB_40bf7c60;
            }
            iVar5 = iVar5 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar5 < *(int *)(param_1 + 100));
        }
        uVar3 = 0;
LAB_40bf7c60:
        *(undefined4 *)(iVar1 + 0x328) = uVar3;
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar9 + 4;
    } while (iVar10 < *(int *)(param_1 + 100));
  }
  LeaveCriticalSection(lpCriticalSection);
  FUN_40c0209c(local_30);
  return 0;
}



/* 40bf7d18 FUN_40bf7d18 */

/* Boundary evidence: original MIPS .pdata 40bf7d18..40bf7d47. Semantic name remains unreviewed. */

void FUN_40bf7d18(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0xf8));
  return;
}



/* 40bf7d48 FUN_40bf7d48 */

/* Boundary evidence: original MIPS .pdata 40bf7d48..40bf7d77. Semantic name remains unreviewed. */

void FUN_40bf7d48(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0xf4));
  return;
}



/* 40bf7d78 FUN_40bf7d78 */

/* Boundary evidence: original MIPS .pdata 40bf7d78..40bf7e2b. Semantic name remains unreviewed. */

void FUN_40bf7d78(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_40bf9dfc(param_3,(undefined4 *)&stack0x00000010);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x68) + iVar2);
      if (((*(int *)(iVar1 + 0x2d8) == param_2) || (*(int *)(iVar1 + 0x2d8) == -1)) &&
         (*(char *)(iVar1 + 0x2dc) == '\0')) {
        EventModify(*(undefined4 *)(iVar1 + 0x70),3);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < *(int *)(param_1 + 100));
  }
  return;
}



/* 40bf7e2c FUN_40bf7e2c */

/* Boundary evidence: original MIPS .pdata 40bf7e2c..40bf7f1f. Semantic name remains unreviewed. */

undefined4 FUN_40bf7e2c(int param_1)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x40);
  EnterCriticalSection(lpCriticalSection);
  (**(code **)(*(int *)(*(int *)(param_1 + 0x58) + 0x4c) + 0x3c))();
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x5c)) {
    iVar1 = 0;
    do {
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x60) + iVar1) + 0xc) + 0x3c))();
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 0x5c));
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    iVar1 = 0;
    do {
      FUN_40bf4f8c(*(int *)(*(int *)(param_1 + 0x68) + iVar1));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 100));
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bf7f20 FUN_40bf7f20 */

/* Boundary evidence: original MIPS .pdata 40bf7f20..40bf7f4f. Semantic name remains unreviewed. */

void FUN_40bf7f20(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bf7f50 FUN_40bf7f50 */

/* Boundary evidence: original MIPS .pdata 40bf7f50..40bf8047. Semantic name remains unreviewed. */

undefined4 FUN_40bf7f50(int param_1)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x40);
  EnterCriticalSection(lpCriticalSection);
  iVar2 = 0;
  *(undefined1 *)(param_1 + 0xc0) = 0;
  if (0 < *(int *)(param_1 + 0x5c)) {
    iVar1 = 0;
    do {
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x60) + iVar1) + 0xc) + 0x40))();
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 0x5c));
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    iVar1 = 0;
    do {
      FUN_40bf4fe8(*(int *)(*(int *)(param_1 + 0x68) + iVar1));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 100));
  }
  (**(code **)(*(int *)(*(int *)(param_1 + 0x58) + 0x4c) + 0x40))();
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bf8048 FUN_40bf8048 */

/* Boundary evidence: original MIPS .pdata 40bf8048..40bf8077. Semantic name remains unreviewed. */

void FUN_40bf8048(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bf8078 FUN_40bf8078 */

/* Boundary evidence: original MIPS .pdata 40bf8078..40bf8183. Semantic name remains unreviewed. */

undefined4 FUN_40bf8078(int param_1)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  *(undefined1 *)(param_1 + 0x60) = 1;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x44) + 0x40) + 0x18))();
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x50)) {
      iVar1 = 0;
      do {
        FUN_40bf4ee0(*(int *)(*(int *)(param_1 + 0x54) + iVar1));
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 4;
      } while (iVar2 < *(int *)(param_1 + 0x50));
    }
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x48)) {
      iVar1 = 0;
      do {
        (**(code **)(**(int **)(iVar1 + *(int *)(param_1 + 0x4c)) + 0x18))();
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 4;
      } while (iVar2 < *(int *)(param_1 + 0x48));
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bf8184 FUN_40bf8184 */

/* Boundary evidence: original MIPS .pdata 40bf8184..40bf81b3. Semantic name remains unreviewed. */

void FUN_40bf8184(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bf81b4 FUN_40bf81b4 */

/* Boundary evidence: original MIPS .pdata 40bf81b4..40bf82cb. Semantic name remains unreviewed. */

undefined4 FUN_40bf81b4(int param_1)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  *(undefined1 *)(param_1 + 0x60) = 1;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = 0;
    *(undefined1 *)(param_1 + 0xac) = 0;
    if (0 < *(int *)(param_1 + 0x48)) {
      iVar2 = 0;
      do {
        (**(code **)(**(int **)(iVar2 + *(int *)(param_1 + 0x4c)) + 0x14))();
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar1 < *(int *)(param_1 + 0x48));
    }
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x50)) {
      iVar2 = 0;
      do {
        FUN_40bf4e2c(*(LPVOID *)(*(int *)(param_1 + 0x54) + iVar2));
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar1 < *(int *)(param_1 + 0x50));
    }
    (**(code **)(*(int *)(*(int *)(param_1 + 0x44) + 0x40) + 0x14))();
  }
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bf82cc FUN_40bf82cc */

/* Boundary evidence: original MIPS .pdata 40bf82cc..40bf82fb. Semantic name remains unreviewed. */

void FUN_40bf82cc(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40bf82fc FUN_40bf82fc */

/* Boundary evidence: original MIPS .pdata 40bf82fc..40bf8453. Semantic name remains unreviewed. */

int FUN_40bf82fc(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[0xb];
  *(undefined1 *)(param_1 + 0x18) = 1;
  EnterCriticalSection(lpCriticalSection);
  param_1[5] = param_3;
  param_1[6] = param_4;
  if ((param_1[2] == 0) && (iVar1 = (**(code **)(*param_1 + 0x14))(param_1), iVar1 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (param_1[2] != 2) {
      (**(code **)(*(int *)(param_1[0x11] + 0x40) + 0x1c))();
      iVar1 = 0;
      if (0 < param_1[0x12]) {
        iVar2 = 0;
        do {
          if ((*(int **)(iVar2 + param_1[0x13]))[6] != 0) {
            (**(code **)(**(int **)(iVar2 + param_1[0x13]) + 0x1c))();
          }
          iVar1 = iVar1 + 1;
          iVar2 = iVar2 + 4;
        } while (iVar1 < param_1[0x12]);
      }
    }
    param_1[2] = 2;
    param_1[0x1f] = 0;
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bf8454 FUN_40bf8454 */

/* Boundary evidence: original MIPS .pdata 40bf8454..40bf8483. Semantic name remains unreviewed. */

void FUN_40bf8454(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40bf8484 FUN_40bf8484 */

void FUN_40bf8484(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = param_3;
  *(undefined4 *)(param_1 + 0xb4) = param_4;
  *(undefined4 *)(param_1 + 0xa0) = param_3;
  *(undefined4 *)(param_1 + 0xa4) = param_4;
  return;
}



/* 40bf84a0 FUN_40bf84a0 */

/* Boundary evidence: original MIPS .pdata 40bf84a0..40bf8513. Semantic name remains unreviewed. */

void FUN_40bf84a0(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0xc0) = 1;
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    iVar1 = 0;
    do {
      EventModify(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x68) + iVar1) + 0x74),3);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 100));
  }
  return;
}



/* 40bf85a0 FUN_40bf85a0 */

/* Boundary evidence: original MIPS .pdata 40bf85a0..40bf875b. Semantic name remains unreviewed. */

undefined4 * FUN_40bf85a0(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1f);
  FUN_40c00b18(param_1 + 2,0,param_2,lpCriticalSection,&DAT_40c05fc4);
  *param_1 = &PTR_FUN_40c03b5c;
  param_1[2] = &PTR_FUN_40c03b38;
  param_1[5] = &PTR_LAB_40c03afc;
  param_1[6] = &PTR_LAB_40c03ae8;
  InitializeCriticalSection(lpCriticalSection);
  param_1[0x24] = 0;
  param_1[0x28] = 0xffffffff;
  param_1[0x29] = 0x3fffffff;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0xffffffff;
  param_1[0x2d] = 0x3fffffff;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0x3ff00000;
  OutputDebugStringW(L"OGM Demux\n");
  if (-1 < *param_3) {
    puVar1 = operator_new(0x160);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40bf8aa4(puVar1,0,(int)param_1,lpCriticalSection,param_3,L"In");
    }
    if (puVar1 == (undefined4 *)0x0) {
      *param_3 = -0x7ff8fff2;
    }
    else if (*param_3 < 0) {
      (**(code **)(puVar1[0x10] + 0xc))(puVar1 + 0x10,1);
    }
    else {
      param_1[0x16] = puVar1;
    }
  }
  param_1[0x18] = 0;
  param_1[0x17] = 0;
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  param_1[0x1c] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)(param_1 + 0x1d) = 0;
  *(undefined1 *)((int)param_1 + 0x75) = 1;
  *(undefined1 *)((int)param_1 + 0x76) = *(undefined1 *)((int)param_1 + 0x77);
  return param_1;
}



/* 40bf875c FUN_40bf875c */

/* Boundary evidence: original MIPS .pdata 40bf875c..40bf878f. Semantic name remains unreviewed. */

void FUN_40bf875c(void)

{
  int *in_v0;
  
  FUN_40bff25c(*in_v0 + 8);
  return;
}



/* 40bf8790 FUN_40bf8790 */

/* Boundary evidence: original MIPS .pdata 40bf8790..40bf87c3. Semantic name remains unreviewed. */

void FUN_40bf8790(void)

{
  int *in_v0;
  
  FUN_40bf42d4((LPCRITICAL_SECTION)(*in_v0 + 0x7c));
  return;
}



/* 40bf87c4 FUN_40bf87c4 */

/* Boundary evidence: original MIPS .pdata 40bf87c4..40bf87f3. Semantic name remains unreviewed. */

void FUN_40bf87c4(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x20));
  return;
}



/* 40bf87f4 FUN_40bf87f4 */

/* Boundary evidence: original MIPS .pdata 40bf87f4..40bf883f. Semantic name remains unreviewed. */

undefined4 * FUN_40bf87f4(undefined4 *param_1,uint param_2)

{
  FUN_40bf6b78(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bf8840 FUN_40bf8840 */

/* Boundary evidence: original MIPS .pdata 40bf8840..40bf897f. Semantic name remains unreviewed. */

undefined4 * FUN_40bf8840(undefined4 *param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  DWORD DVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  undefined4 *puVar5;
  
  if (DAT_40c0817c == 0) {
    pwVar4 = L"ALCHEMYOGGDEMUXSINGLEMUTEX";
    uVar3 = 1;
    DAT_40c0817c = (int)CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,1,L"ALCHEMYOGGDEMUXSINGLEMUTEX");
    if (((HANDLE)DAT_40c0817c != (HANDLE)0x0) && (DVar1 = GetLastError(), DVar1 != 0xb7)) {
      puVar2 = operator_new(200);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40bf85a0(puVar2,param_1,param_2);
      }
      puVar5 = puVar2 + 2;
      if (puVar2 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      *param_2 = 0;
      return puVar5;
    }
    FUN_40bfb888(0x40c03f90,uVar3,pwVar4,param_4);
    if (DAT_40c0817c != 0) {
      CloseHandle((HANDLE)DAT_40c0817c);
    }
    DAT_40c0817c = 0;
    *param_2 = -0x7fffbffb;
  }
  else {
    FUN_40bfb888(0x40c04098,param_2,param_3,param_4);
    *param_2 = -0x7fffbffb;
  }
  return (undefined4 *)0x0;
}



/* 40bf8980 FUN_40bf8980 */

/* Boundary evidence: original MIPS .pdata 40bf8980..40bf89af. Semantic name remains unreviewed. */

void FUN_40bf8980(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x20));
  return;
}



/* 40bf89b0 FUN_40bf89b0 */

/* Boundary evidence: original MIPS .pdata 40bf89b0..40bf8a73. Semantic name remains unreviewed. */

void FUN_40bf89b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7c));
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    iVar2 = 0;
    do {
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x68) + iVar2);
      if (puVar1 != (undefined4 *)0x0) {
        FUN_40bf4b1c(puVar1);
        operator_delete(puVar1);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < *(int *)(param_1 + 100));
  }
  operator_delete(*(void **)(param_1 + 0x68));
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7c));
  return;
}



/* 40bf8a74 FUN_40bf8a74 */

/* Boundary evidence: original MIPS .pdata 40bf8a74..40bf8aa3. Semantic name remains unreviewed. */

void FUN_40bf8a74(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40bf8aa4 FUN_40bf8aa4 */

/* Boundary evidence: original MIPS .pdata 40bf8aa4..40bf8b9f. Semantic name remains unreviewed. */

undefined4 *
FUN_40bf8aa4(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  int iVar1;
  
  FUN_40bfd744((int)param_1);
  iVar1 = param_3 + 8;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  FUN_40c00abc(param_1 + 0x10,param_2,iVar1,param_4,param_5,param_6);
  *param_1 = &PTR_FUN_40c042cc;
  param_1[0x10] = &PTR_FUN_40c04290;
  param_1[0x13] = &PTR_FUN_40c04248;
  param_1[0x14] = &PTR_LAB_40c04234;
  param_1[0x36] = &PTR_LAB_40c04210;
  param_1[0x49] = param_3;
  param_1[0x4a] = 0;
  FUN_40bfd5e8(param_1 + 0x56,0);
  FUN_40bf21f0(param_1 + 0x4b);
  return param_1;
}



/* 40bf8ba0 FUN_40bf8ba0 */

/* Boundary evidence: original MIPS .pdata 40bf8ba0..40bf8bcf. Semantic name remains unreviewed. */

void FUN_40bf8ba0(void)

{
  int *in_v0;
  
  FUN_40bfd7c0(*in_v0);
  return;
}



/* 40bf8bd0 FUN_40bf8bd0 */

/* Boundary evidence: original MIPS .pdata 40bf8bd0..40bf8c03. Semantic name remains unreviewed. */

void FUN_40bf8bd0(void)

{
  int *in_v0;
  
  FUN_40bfe7fc(*in_v0 + 0x40);
  return;
}



/* 40bf8c10 FUN_40bf8c10 */

/* Boundary evidence: original MIPS .pdata 40bf8c10..40bf8c37. Semantic name remains unreviewed. */

void FUN_40bf8c10(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40bf8c38 FUN_40bf8c38 */

/* Boundary evidence: original MIPS .pdata 40bf8c38..40bf8c5f. Semantic name remains unreviewed. */

void FUN_40bf8c38(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40bf8c60 FUN_40bf8c60 */

/* Boundary evidence: original MIPS .pdata 40bf8c60..40bf8c87. Semantic name remains unreviewed. */

void FUN_40bf8c60(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40bf8c88 FUN_40bf8c88 */

/* Boundary evidence: original MIPS .pdata 40bf8c88..40bf8d2f. Semantic name remains unreviewed. */

void FUN_40bf8c88(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40c042cc;
  param_1[0x10] = &PTR_FUN_40c04290;
  param_1[0x13] = &PTR_FUN_40c04248;
  param_1[0x14] = &PTR_LAB_40c04234;
  param_1[0x36] = &PTR_LAB_40c04210;
  FUN_40bf2228(param_1 + 0x4b);
  FUN_40bfd628(param_1 + 0x56);
  FUN_40bfe7fc((int)(param_1 + 0x10));
  FUN_40bfd7c0((int)param_1);
  return;
}



/* 40bf8d30 FUN_40bf8d30 */

/* Boundary evidence: original MIPS .pdata 40bf8d30..40bf8d5f. Semantic name remains unreviewed. */

void FUN_40bf8d30(void)

{
  int *in_v0;
  
  FUN_40bfd7c0(*in_v0);
  return;
}



/* 40bf8d60 FUN_40bf8d60 */

/* Boundary evidence: original MIPS .pdata 40bf8d60..40bf8db3. Semantic name remains unreviewed. */

void FUN_40bf8d60(void)

{
  int *in_v0;
  
  if (*in_v0 == 0) {
    in_v0[-6] = 0;
  }
  else {
    in_v0[-6] = *in_v0 + 0x40;
  }
  FUN_40bfe7fc(in_v0[-6]);
  return;
}



/* 40bf8db4 FUN_40bf8db4 */

/* Boundary evidence: original MIPS .pdata 40bf8db4..40bf8e47. Semantic name remains unreviewed. */

undefined4 FUN_40bf8db4(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_40c04a44,0x10);
  if (iVar1 == 0) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40c06024,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40c06004,0x10), iVar1 == 0)) {
      return 0;
    }
  }
  return 0x8004022a;
}



/* 40bf8e48 FUN_40bf8e48 */

/* Boundary evidence: original MIPS .pdata 40bf8e48..40bf8eab. Semantic name remains unreviewed. */

int FUN_40bf8e48(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40bfe1e8();
  if (-1 < iVar1) {
    if (*(int **)(param_1 + 0xe8) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xe8) + 8))();
      *(undefined4 *)(param_1 + 0xe8) = 0;
    }
    FUN_40bf89b0(*(int *)(param_1 + 0xe4));
    FUN_40bf6fc8(*(int *)(param_1 + 0xe4));
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bf8eac FUN_40bf8eac */

/* Boundary evidence: original MIPS .pdata 40bf8eac..40bf8f2b. Semantic name remains unreviewed. */

int FUN_40bf8eac(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40bfe00c(param_1,param_2);
  if (-1 < iVar1) {
    iVar1 = (**(code **)*param_2)(param_2,&UNK_40c068e0,param_1 + 0xe8);
    if (iVar1 < 0) {
      return 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bf8f2c FUN_40bf8f2c */

/* WARNING: Removing unreachable block (ram,0x40bf92ac) */
/* Boundary evidence: original MIPS .pdata 40bf8f2c..40bf9387. Semantic name remains unreviewed. */

int FUN_40bf8f2c(int param_1)

{
  bool bVar1;
  longlong lVar2;
  void *_Src;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  LPCRITICAL_SECTION lpCriticalSection;
  va_list pcVar12;
  int *piVar13;
  undefined8 uVar14;
  longlong lVar15;
  int local_d8;
  int local_d4;
  int aiStack_d0 [4];
  LPCRITICAL_SECTION local_c0;
  undefined1 auStack_b8 [8];
  char acStack_b0 [126];
  undefined1 local_32;
  uint local_30;
  
  local_30 = DAT_40c08174;
  if (*(int *)(param_1 + 0xe8) == 0) {
    FUN_40c0209c(DAT_40c08174);
    iVar10 = -0x7fff0001;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x68);
    local_c0 = lpCriticalSection;
    EnterCriticalSection(lpCriticalSection);
    bVar1 = false;
    *(undefined4 *)(param_1 + 0xd8) = 0x20000;
    *(undefined4 *)(param_1 + 0xdc) = 0x20000;
    *(undefined4 *)(param_1 + 0xe0) = 0x20000;
    FUN_40bfb8d8(param_1 + -0x40);
    (**(code **)(**(int **)(param_1 + 0xe8) + 0x20))
              (*(int **)(param_1 + 0xe8),(uint *)(param_1 + 0x108),auStack_b8);
    local_d4 = *(int *)(param_1 + 0x10c);
    uVar8 = *(uint *)(param_1 + 0x108);
    if ((-1 < local_d4) && ((local_d4 != 0 || (*(uint *)(param_1 + 0xdc) < uVar8)))) {
      local_d4 = 0;
      uVar8 = *(uint *)(param_1 + 0xdc);
    }
    piVar13 = (int *)(param_1 + 0xec);
    FUN_40bf2b04((int)piVar13);
    _Src = (void *)FUN_40bf2288(piVar13,uVar8);
    piVar7 = (int *)0x0;
    uVar6 = 0;
    iVar10 = (**(code **)(**(int **)(param_1 + 0xe8) + 0x1c))();
    if (iVar10 == 0) {
      iVar10 = 0x7e;
      memcpy(acStack_b0,_Src,0x7e);
      local_32 = 0;
      iVar11 = 0;
      do {
        pcVar3 = strstr(acStack_b0 + iVar11,"FLAC");
        if ((pcVar3 != (char *)0x0) ||
           (pcVar3 = strstr(acStack_b0 + iVar11,"fLaC"), pcVar3 != (char *)0x0)) goto LAB_40bf9334;
        iVar11 = iVar11 + 1;
      } while (iVar11 < 0x7e);
      FUN_40bf2364((int)piVar13,uVar8);
      iVar11 = FUN_40bf25c8(piVar13,aiStack_d0);
      if (0 < iVar11) {
        do {
          iVar11 = FUN_40bf1ec4(aiStack_d0);
          local_d8 = FUN_40bf6ee4(*(int *)(param_1 + 0xe4),iVar11);
          if (local_d8 == 0) {
            piVar7 = (int *)0x0;
            iVar4 = FUN_40bf7118(*(int *)(param_1 + 0xe4),&local_d8,iVar11,0);
            iVar10 = iVar11;
            if (iVar4 < 0) {
              LeaveCriticalSection(lpCriticalSection);
              FUN_40c0209c(local_30);
              return iVar4;
            }
          }
          iVar11 = FUN_40bf6820(local_d8,aiStack_d0,iVar10,piVar7);
          if (iVar11 == 0) {
            bVar1 = true;
          }
          piVar5 = aiStack_d0;
          iVar11 = FUN_40bf25c8(piVar13,piVar5);
        } while (0 < iVar11);
        if (bVar1) {
          FUN_40bf76f4(*(int *)(param_1 + 0xe4));
          FUN_40bf74cc(*(int *)(param_1 + 0xe4));
          FUN_40bf796c(*(int *)(param_1 + 0xe4));
          lVar2 = 0;
          if (0 < *(int *)(*(int *)(param_1 + 0xe4) + 100)) {
            uVar9 = *(uint *)(param_1 + 0x108);
            pcVar12 = (va_list)(*(int *)(param_1 + 0x10c) -
                               (uint)(uVar9 < *(uint *)(param_1 + 0xe0)));
            uVar8 = uVar9 - *(uint *)(param_1 + 0xe0) & 0xfffffff0;
            if (((int)pcVar12 < 1) && (pcVar12 != (va_list)0x0)) {
              uVar8 = 0;
              pcVar12 = (va_list)0x0;
            }
            iVar11 = uVar9 - uVar8;
            FUN_40bf2b04((int)piVar13);
            FUN_40bf2288(piVar13,iVar11);
            iVar10 = (**(code **)(**(int **)(param_1 + 0xe8) + 0x1c))();
            if (iVar10 != 0) {
              FUN_40bfb888(0x40c04368,iVar10,uVar8,pcVar12);
            }
            FUN_40bf2364((int)piVar13,iVar11);
            piVar5 = aiStack_d0;
            iVar10 = FUN_40bf25c8(piVar13,piVar5);
            lVar2 = 0;
            while (iVar10 != 0) {
              iVar10 = FUN_40bf1ec4(aiStack_d0);
              iVar11 = FUN_40bf6ee4(*(int *)(param_1 + 0xe4),iVar10);
              if (iVar11 != 0) {
                uVar14 = FUN_40bf1e38(aiStack_d0);
                lVar15 = FUN_40bf5f74(iVar11,iVar10,(uint)uVar14,(int)((ulonglong)uVar14 >> 0x20));
                if (lVar2 < lVar15) {
                  lVar2 = lVar15;
                }
              }
              piVar5 = aiStack_d0;
              iVar10 = FUN_40bf25c8(piVar13,piVar5);
            }
          }
          *(undefined4 *)(param_1 + 0x110) = 0;
          *(undefined4 *)(param_1 + 0x114) = 0;
          FUN_40bf8484(*(int *)(param_1 + 0xe4),piVar5,(int)lVar2,(int)((ulonglong)lVar2 >> 0x20));
          LeaveCriticalSection(lpCriticalSection);
          FUN_40c0209c(local_30);
          return 0;
        }
      }
LAB_40bf9334:
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      FUN_40bfb888(0x40c043a4,iVar10,uVar6,(va_list)piVar7);
      LeaveCriticalSection(lpCriticalSection);
    }
    FUN_40c0209c(local_30);
    iVar10 = -0x7ffbfdd6;
  }
  return iVar10;
}



/* 40bf9388 FUN_40bf9388 */

/* Boundary evidence: original MIPS .pdata 40bf9388..40bf93b7. Semantic name remains unreviewed. */

void FUN_40bf9388(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0xc0));
  return;
}



/* 40bf93b8 FUN_40bf93b8 */

/* Boundary evidence: original MIPS .pdata 40bf93b8..40bf95e3. Semantic name remains unreviewed. */

undefined4 FUN_40bf93b8(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  va_list pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  undefined4 auStack_38 [2];
  int aiStack_30 [4];
  
  bVar1 = true;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  EventModify(*(undefined4 *)(param_1 + 0x158),2);
  piVar9 = (int *)(param_1 + 300);
  FUN_40bf2b04((int)piVar9);
  FUN_40bfda0c(param_1,0);
  do {
    iVar3 = FUN_40bf25c8(piVar9,aiStack_30);
    while (iVar3 < 1) {
      if (bVar1) {
        bVar1 = false;
      }
      else {
        iVar10 = *(int *)(param_1 + 0x154);
        iVar3 = *(int *)(param_1 + 0x14c);
        uVar7 = *(uint *)(param_1 + 0x150);
        uVar6 = *(uint *)(param_1 + 0x148);
        if ((iVar3 < iVar10) || ((iVar10 == iVar3 && (uVar6 <= uVar7)))) {
          FUN_40bf84a0(*(int *)(param_1 + 0x124));
          return 0;
        }
        uVar8 = (*(int *)(param_1 + 0x138) - *(int *)(param_1 + 0x134)) + *(int *)(param_1 + 0x118);
        iVar10 = ((int)uVar8 >> 0x1f) + iVar10 + (uint)(uVar8 + uVar7 < uVar8);
        if ((iVar3 <= iVar10) && ((iVar10 != iVar3 || (uVar6 < uVar8 + uVar7)))) {
          uVar8 = uVar6 - uVar7;
        }
        FUN_40bf2288(piVar9,uVar8);
        pcVar5 = *(va_list *)(param_1 + 0x154);
        uVar4 = *(undefined4 *)(param_1 + 0x150);
        iVar3 = (**(code **)(**(int **)(param_1 + 0x128) + 0x1c))();
        if (iVar3 != 0) {
          FUN_40bfb888(0x40c04470,iVar3,uVar4,pcVar5);
        }
        FUN_40bf2364((int)piVar9,uVar8);
        uVar6 = uVar8 + *(int *)(param_1 + 0x150);
        *(uint *)(param_1 + 0x150) = uVar6;
        *(uint *)(param_1 + 0x154) =
             ((int)uVar8 >> 0x1f) + *(int *)(param_1 + 0x154) + (uint)(uVar6 < uVar8);
      }
      iVar3 = FUN_40bf25c8(piVar9,aiStack_30);
    }
    iVar3 = FUN_40bf1ec4(aiStack_30);
    iVar3 = FUN_40bf6ee4(*(int *)(param_1 + 0x124),iVar3);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      bVar2 = FUN_40bf4d84(iVar3,aiStack_30);
      iVar3 = CONCAT31(extraout_var,bVar2);
    }
    if (iVar3 == 0) {
      EventModify(*(HANDLE *)(param_1 + 0x158),2);
    }
    else {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x158),0xffffffff);
    }
    iVar3 = FUN_40bfd9a8(param_1,auStack_38);
  } while ((iVar3 == 0) && (*(int *)(param_1 + 0x15c) == 0));
  return 0;
}



/* 40bf95e4 FUN_40bf95e4 */

/* Boundary evidence: original MIPS .pdata 40bf95e4..40bf96a7. Semantic name remains unreviewed. */

int FUN_40bf95e4(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  iVar2 = *(int *)(param_1 + 0xe4);
  lpCriticalSection = *(LPCRITICAL_SECTION *)(iVar2 + 0x40);
  EnterCriticalSection(lpCriticalSection);
  iVar2 = *(int *)(iVar2 + 0x1c);
  bVar1 = true;
  if ((iVar2 != 1) && (iVar2 != 2)) {
    bVar1 = false;
  }
  LeaveCriticalSection(lpCriticalSection);
  if (bVar1) {
    return 1;
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar2 = FUN_40bfe1e8();
    if (iVar2 < 0) {
      return iVar2;
    }
    bVar1 = FUN_40bfd830((LPVOID)(param_1 + -0x40));
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return -0x7fffbffb;
    }
    FUN_40bfd8e4(param_1 + -0x40,1);
  }
  return 0;
}



/* 40bf96a8 FUN_40bf96a8 */

/* Boundary evidence: original MIPS .pdata 40bf96a8..40bf974b. Semantic name remains unreviewed. */

void FUN_40bf96a8(int param_1)

{
  HANDLE hHandle;
  
  if (*(LONG *)(param_1 + -0x2c) != 0) {
    *(undefined4 *)(param_1 + 0x11c) = 1;
    EventModify(*(undefined4 *)(param_1 + 0x118),3);
    FUN_40bfd8e4(param_1 + -0x40,3);
    hHandle = (HANDLE)InterlockedExchange((LONG *)(param_1 + -0x2c),0);
    if (hHandle != (HANDLE)0x0) {
      WaitForSingleObject(hHandle,0xffffffff);
      CloseHandle(hHandle);
    }
  }
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  FUN_40bfe1f0(param_1);
  return;
}



/* 40bf974c FUN_40bf974c */

/* Boundary evidence: original MIPS .pdata 40bf974c..40bf979b. Semantic name remains unreviewed. */

undefined4 FUN_40bf974c(int param_1)

{
  if (*(int *)(param_1 + -0x38) != 0) {
    *(undefined4 *)(param_1 + 0x110) = 1;
    EventModify(*(undefined4 *)(param_1 + 0x10c),3);
    FUN_40bfd8e4(param_1 + -0x4c,2);
  }
  return 0;
}



/* 40bf979c FUN_40bf979c */

/* Boundary evidence: original MIPS .pdata 40bf979c..40bf97cb. Semantic name remains unreviewed. */

undefined4 FUN_40bf979c(int param_1)

{
  if (*(int *)(param_1 + -0x38) != 0) {
    FUN_40bfd8e4(param_1 + -0x4c,1);
  }
  return 0;
}



/* 40bf9858 FUN_40bf9858 */

/* Boundary evidence: original MIPS .pdata 40bf9858..40bf98a3. Semantic name remains unreviewed. */

undefined4 * FUN_40bf9858(undefined4 *param_1,uint param_2)

{
  FUN_40bf8c88(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bf98a4 FUN_40bf98a4 */

/* Boundary evidence: original MIPS .pdata 40bf98a4..40bf993b. Semantic name remains unreviewed. */

undefined4 FUN_40bf98a4(int param_1)

{
  int iVar1;
  
  do {
    while( true ) {
      while (iVar1 = FUN_40bfd970(param_1), iVar1 == 1) {
        FUN_40bf93b8(param_1);
      }
      if (iVar1 != 2) break;
      FUN_40bfda0c(param_1,0);
    }
  } while (iVar1 != 3);
  FUN_40bfda0c(param_1,0);
  return 0;
}



/* 40bf993c FUN_40bf993c */

/* Boundary evidence: original MIPS .pdata 40bf993c..40bf99cf. Semantic name remains unreviewed. */

undefined4 FUN_40bf993c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = memcmp(param_2,&DAT_40c067b0,0x10);
  if (iVar1 == 0) {
    if (param_3 == (undefined4 *)0x0) {
      uVar2 = 0x80004003;
    }
    else {
      piVar3 = param_1 + 0x28;
      if (param_1 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      uVar2 = FUN_40c00ca4(piVar3,param_3);
    }
  }
  else {
    uVar2 = FUN_40bfdeec(param_1,param_2,param_3);
  }
  return uVar2;
}



/* 40bf99d0 FUN_40bf99d0 */

/* Boundary evidence: original MIPS .pdata 40bf99d0..40bf9a73. Semantic name remains unreviewed. */

int FUN_40bf99d0(int param_1)

{
  bool bVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  iVar2 = *(int *)(param_1 + 0xa4);
  lpCriticalSection = *(LPCRITICAL_SECTION *)(iVar2 + 0x40);
  EnterCriticalSection(lpCriticalSection);
  iVar2 = *(int *)(iVar2 + 0x1c);
  bVar1 = true;
  if ((iVar2 != 1) && (iVar2 != 2)) {
    bVar1 = false;
  }
  LeaveCriticalSection(lpCriticalSection);
  if (bVar1) {
    iVar2 = 1;
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) {
      iVar2 = FUN_40bfe608(param_1);
      if (iVar2 < 0) {
        return iVar2;
      }
      *(undefined4 *)(param_1 + 0xc0) = 0;
      *(undefined4 *)(param_1 + 0xc4) = 0x80000000;
    }
    iVar2 = 0;
  }
  return iVar2;
}



/* 40bf9a74 FUN_40bf9a74 */

/* Boundary evidence: original MIPS .pdata 40bf9a74..40bf9a8f. Semantic name remains unreviewed. */

void FUN_40bf9a74(int param_1)

{
  FUN_40bfe648(param_1);
  return;
}



/* 40bf9a90 FUN_40bf9a90 */

/* Boundary evidence: original MIPS .pdata 40bf9a90..40bf9ab7. Semantic name remains unreviewed. */

void FUN_40bf9a90(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0xc) + 0x50))();
  return;
}



/* 40bf9ab8 FUN_40bf9ab8 */

/* Boundary evidence: original MIPS .pdata 40bf9ab8..40bf9aeb. Semantic name remains unreviewed. */

void FUN_40bf9ab8(int param_1)

{
  *(undefined4 *)(param_1 + 0xb8) = 0x80000000;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  (**(code **)(*(int *)(param_1 + -0xc) + 0x54))();
  return;
}



/* 40bf9aec FUN_40bf9aec */

/* Boundary evidence: original MIPS .pdata 40bf9aec..40bf9baf. Semantic name remains unreviewed. */

undefined4 FUN_40bf9aec(int param_1,int param_2,void *param_3)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xa4) + 0x7c);
  EnterCriticalSection(lpCriticalSection);
  if (param_2 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0x80070057;
  }
  else if (param_2 < 1) {
    FUN_40bfd060(param_3,(void *)(*(int *)(param_1 + 0xa8) + 0x2e0));
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0x40103;
  }
  return uVar1;
}



/* 40bf9bb0 FUN_40bf9bb0 */

/* Boundary evidence: original MIPS .pdata 40bf9bb0..40bf9bdf. Semantic name remains unreviewed. */

void FUN_40bf9bb0(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40bf9be0 FUN_40bf9be0 */

/* Boundary evidence: original MIPS .pdata 40bf9be0..40bf9c27. Semantic name remains unreviewed. */

undefined4 FUN_40bf9be0(int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_40bfd138(param_2,(void *)(*(int *)(param_1 + 0xa8) + 0x2e0));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return 0x80004005;
  }
  return 0;
}



/* 40bf9c28 FUN_40bf9c28 */

/* Boundary evidence: original MIPS .pdata 40bf9c28..40bf9c97. Semantic name remains unreviewed. */

void FUN_40bf9c28(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined1 auStack_18 [16];
  
  if (*param_3 < 5) {
    *param_3 = 5;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + 0x2cc);
  if (param_3[1] < iVar1) {
    param_3[1] = iVar1;
  }
  param_3[2] = 1;
  param_3[3] = 0;
  (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_18);
  return;
}



/* 40bf9c98 FUN_40bf9c98 */

/* Boundary evidence: original MIPS .pdata 40bf9c98..40bf9dfb. Semantic name remains unreviewed. */

int FUN_40bf9c98(int *param_1,int param_2,int param_3)

{
  int iVar1;
  size_t _Size;
  size_t *psVar2;
  int iVar3;
  int *local_28;
  void *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  iVar3 = 0;
  if (0 < param_3) {
    psVar2 = (size_t *)(param_2 + 4);
    do {
      iVar1 = (**(code **)(*param_1 + 0x40))(param_1,&local_28,0,0,0);
      if (iVar1 < 0) {
        return iVar1;
      }
      (**(code **)(*local_28 + 0xc))(local_28,&local_24);
      _Size = *psVar2;
      if (0 < (int)_Size) {
        iVar1 = (**(code **)(*local_28 + 0x10))();
        if (iVar1 < (int)_Size) {
          _Size = (**(code **)(*local_28 + 0x10))();
          *psVar2 = _Size;
        }
        memcpy(local_24,(void *)psVar2[-1],_Size);
        (**(code **)(*local_28 + 0x30))(local_28,_Size);
        (**(code **)(*local_28 + 0x18))(local_28,&local_20,&local_20);
        iVar1 = (**(code **)(*param_1 + 0x44))(param_1,local_28);
        (**(code **)(*local_28 + 8))();
        if (iVar1 < 0) {
          return iVar1;
        }
      }
      iVar3 = iVar3 + 1;
      psVar2 = psVar2 + 8;
    } while (iVar3 < param_3);
  }
  return 0;
}



/* 40bf9dfc FUN_40bf9dfc */

/* Boundary evidence: original MIPS .pdata 40bf9dfc..40bf9e53. Semantic name remains unreviewed. */

void FUN_40bf9dfc(int param_1,undefined4 *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xac));
  *(undefined4 *)(param_1 + 0xc0) = *param_2;
  *(undefined4 *)(param_1 + 0xc4) = param_2[1];
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xac));
  return;
}



/* 40bf9e54 FUN_40bf9e54 */

/* Boundary evidence: original MIPS .pdata 40bf9e54..40bf9eab. Semantic name remains unreviewed. */

void FUN_40bf9e54(int param_1,undefined4 *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xac));
  *param_2 = *(undefined4 *)(param_1 + 0xc0);
  param_2[1] = *(undefined4 *)(param_1 + 0xc4);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xac));
  return;
}



/* 40bf9eac FUN_40bf9eac */

/* Boundary evidence: original MIPS .pdata 40bf9eac..40bf9f3b. Semantic name remains unreviewed. */

undefined4 *
FUN_40bf9eac(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  int iVar1;
  
  iVar1 = param_3 + 8;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  FUN_40c00a70(param_1,param_2,iVar1,param_4,param_5,param_6);
  *param_1 = &PTR_FUN_40c045a4;
  param_1[3] = &PTR_FUN_40c0455c;
  param_1[4] = &PTR_LAB_40c04548;
  param_1[0x28] = &PTR_LAB_40c044f8;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2b));
  param_1[0x29] = param_3;
  return param_1;
}



/* 40bf9f3c FUN_40bf9f3c */

/* Boundary evidence: original MIPS .pdata 40bf9f3c..40bf9f63. Semantic name remains unreviewed. */

void FUN_40bf9f3c(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40bf9f64 FUN_40bf9f64 */

/* Boundary evidence: original MIPS .pdata 40bf9f64..40bf9f8b. Semantic name remains unreviewed. */

void FUN_40bf9f64(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40bf9f8c FUN_40bf9f8c */

/* Boundary evidence: original MIPS .pdata 40bf9f8c..40bf9fb3. Semantic name remains unreviewed. */

void FUN_40bf9f8c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40bfa02c FUN_40bfa02c */

/* Boundary evidence: original MIPS .pdata 40bfa02c..40bfa07f. Semantic name remains unreviewed. */

void * FUN_40bfa02c(void *param_1,uint param_2)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0xac));
  FUN_40bfdea8((int)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bfa080 FUN_40bfa080 */

/* Boundary evidence: original MIPS .pdata 40bfa080..40bfa0eb. Semantic name remains unreviewed. */

undefined4 FUN_40bfa080(int param_1,int *param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7c));
  iVar1 = *(int *)(param_1 + 100);
  *param_2 = iVar1;
  if (*(char *)(param_1 + 0x75) != '\0') {
    *param_2 = *(int *)(param_1 + 0x6c) + iVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7c));
  return 0;
}



/* 40bfa0ec FUN_40bfa0ec */

/* Boundary evidence: original MIPS .pdata 40bfa0ec..40bfa7c3. Semantic name remains unreviewed. */

undefined4
FUN_40bfa0ec(int param_1,int param_2,int *param_3,uint *param_4,undefined4 *param_5,
            undefined4 *param_6,int *param_7,undefined4 *param_8,undefined4 *param_9)

{
  char cVar1;
  int *piVar2;
  undefined2 uVar3;
  LPVOID pvVar4;
  undefined2 extraout_var;
  char *pcVar5;
  LPWSTR pWVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  void *_Buf1;
  int *piVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *local_140 [2];
  uint local_138;
  int local_134;
  char local_130 [4];
  undefined3 local_12c;
  char cStack_129;
  undefined1 local_128;
  undefined1 local_127;
  uint local_30;
  
  local_30 = DAT_40c08174;
  local_140[0] = param_7;
  if (-1 < param_2) {
    if (param_2 < *(int *)(param_1 + 100)) {
      if (param_3 != (int *)0x0) {
        iVar10 = *(int *)(*(int *)(param_1 + 0x68) + param_2 * 4);
        pvVar4 = CoTaskMemAlloc(0x48);
        *param_3 = (int)pvVar4;
        memcpy(pvVar4,(void *)(iVar10 + 0x2e0),0x48);
        if (*(SIZE_T *)(iVar10 + 800) != 0) {
          pvVar4 = CoTaskMemAlloc(*(SIZE_T *)(iVar10 + 800));
          *(LPVOID *)(*param_3 + 0x44) = pvVar4;
          memcpy(*(void **)(*param_3 + 0x44),*(void **)(iVar10 + 0x324),*(size_t *)(iVar10 + 800));
        }
      }
      piVar2 = local_140[0];
      if (param_4 != (uint *)0x0) {
        *param_4 = (uint)(*(char *)(*(int *)(*(int *)(param_1 + 0x68) + param_2 * 4) + 0x2dc) !=
                         '\0');
      }
      if (param_5 != (undefined4 *)0x0) {
        uVar3 = FUN_40bf1808((int *)(*(int *)(*(int *)(param_1 + 0x68) + param_2 * 4) + 0x22c));
        *param_5 = CONCAT22(extraout_var,uVar3);
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x68) + param_2 * 4) + 0x2d8);
      }
      if (piVar2 != (int *)0x0) {
        piVar16 = (int *)(*(int *)(param_1 + 0x68) + param_2 * 4);
        _Buf1 = (void *)(*piVar16 + 0x2e0);
        iVar10 = memcmp(_Buf1,&DAT_40c049e4,0x10);
        if (iVar10 == 0) {
          local_130[0] = 'V';
          local_130[1] = 'i';
          local_130[2] = 'd';
          local_130[3] = 'e';
          local_12c._0_1_ = 'o';
          local_12c._1_1_ = ' ';
          local_12c._2_1_ = '\0';
        }
        else {
          iVar10 = memcmp(_Buf1,&DAT_40c049f4,0x10);
          if (iVar10 == 0) {
            local_130[0] = 'A';
            local_130[1] = 'u';
            local_130[2] = 'd';
            local_130[3] = 'i';
            local_12c._0_1_ = 'o';
            local_12c._1_1_ = ' ';
            local_12c._2_1_ = '\0';
          }
          else {
            iVar10 = memcmp(_Buf1,&DAT_40c04a24,0x10);
            if (iVar10 == 0) {
              local_130[0] = 'S';
              local_130[1] = 'u';
              local_130[2] = 'b';
              local_130[3] = 't';
              local_12c._0_1_ = 'i';
              local_12c._1_1_ = 't';
              local_12c._2_1_ = 'l';
              cStack_129 = 'e';
              local_128 = 0x20;
              local_127 = 0;
            }
            else {
              local_130[0] = 'S';
              local_130[1] = 't';
              local_130[2] = 'r';
              local_130[3] = 'e';
              local_12c._0_1_ = 'a';
              local_12c._1_1_ = 'm';
              local_12c._2_1_ = ' ';
              cStack_129 = '\0';
            }
          }
        }
        pcVar5 = (char *)FUN_40bf305c((int *)(*piVar16 + 0x22c),"LANGUAGE",0);
        if (pcVar5 == (char *)0x0) {
          pcVar5 = local_130;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          _ltoa(*(long *)(*(int *)(*(int *)(param_1 + 0x68) + param_2 * 4) + 0x2d4),
                pcVar5 + (int)&local_134 + (3 - (int)local_130),10);
        }
        else {
          strcat(local_130,pcVar5);
        }
        pcVar5 = local_130;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        pWVar6 = CoTaskMemAlloc((int)(pcVar5 + (1 - (int)local_130)) * 2);
        *piVar2 = (int)pWVar6;
        wsprintfW(pWVar6,L"%s",local_130);
      }
      if (param_8 != (undefined4 *)0x0) {
        *param_8 = 0;
      }
      if (param_9 != (undefined4 *)0x0) {
        *param_9 = 0;
      }
      FUN_40c0209c(local_30);
      return 0;
    }
    iVar10 = param_2 - *(int *)(param_1 + 100);
    if ((*(char *)(param_1 + 0x75) != '\0') && (iVar10 < *(int *)(param_1 + 0x6c))) {
      if (param_3 != (int *)0x0) {
        pvVar4 = CoTaskMemAlloc(0x48);
        *param_3 = (int)pvVar4;
        memset(pvVar4,0,0x48);
        puVar8 = (undefined4 *)*param_3;
        *puVar8 = 0x73646976;
        puVar8[1] = 0x100000;
        puVar8[2] = 0xaa000080;
        puVar8[3] = 0x719b3800;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = 0;
        iVar7 = (**(code **)**(undefined4 **)(param_1 + 0x48))
                          (*(undefined4 **)(param_1 + 0x48),&DAT_40c067b0,local_140);
        if (-1 < iVar7) {
          (**(code **)(*local_140[0] + 0x30))(local_140[0],&local_138);
          (**(code **)(*local_140[0] + 8))();
          iVar7 = iVar10 * 0x48 + *(int *)(param_1 + 0x70);
          iVar14 = *(int *)(iVar7 + 0x44);
          if ((iVar14 <= local_134) &&
             ((iVar14 != local_134 || (*(uint *)(iVar7 + 0x40) <= local_138)))) {
            *param_4 = 1;
            iVar7 = 0;
            if (0 < *(int *)(param_1 + 0x6c)) {
              iVar14 = 0;
              do {
                if (iVar7 != iVar10) {
                  iVar9 = iVar14 + *(int *)(param_1 + 0x70);
                  iVar11 = *(int *)(iVar9 + 0x44);
                  if ((iVar11 <= local_134) &&
                     ((iVar11 != local_134 || (*(uint *)(iVar9 + 0x40) <= local_138)))) {
                    iVar9 = iVar14 + *(int *)(param_1 + 0x70);
                    iVar12 = *(int *)(param_1 + 0x70) + iVar10 * 0x48;
                    iVar11 = *(int *)(iVar9 + 0x44);
                    iVar15 = *(int *)(iVar12 + 0x44);
                    if ((iVar15 <= iVar11) &&
                       ((iVar11 != iVar15 || (*(uint *)(iVar12 + 0x40) < *(uint *)(iVar9 + 0x40)))))
                    {
                      *param_4 = 0;
                    }
                  }
                }
                iVar7 = iVar7 + 1;
                iVar14 = iVar14 + 0x48;
              } while (iVar7 < *(int *)(param_1 + 0x6c));
            }
          }
        }
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 0;
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = 0xfffffff0;
      }
      if (param_7 != (int *)0x0) {
        pcVar13 = (char *)(iVar10 * 0x48 + *(int *)(param_1 + 0x70));
        pcVar5 = pcVar13;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        pWVar6 = CoTaskMemAlloc((int)(pcVar5 + (0xf - (int)pcVar13)) * 2);
        *param_7 = (int)pWVar6;
        iVar9 = iVar10 * 0x48 + *(int *)(param_1 + 0x70);
        uVar18 = *(undefined4 *)(iVar9 + 0x40);
        uVar17 = *(undefined4 *)(iVar9 + 0x44);
        iVar10 = __ll_div(uVar18,uVar17,10000,0);
        iVar7 = __ll_div(uVar18,uVar17,10000000,0);
        iVar14 = __ll_div(uVar18,uVar17,600000000,0);
        uVar17 = __ll_div(uVar18,uVar17,0x61c46800,8);
        wsprintfW(pWVar6,L"%02d:%02d:%02d.%03d %s",uVar17,iVar14 % 0x3c,iVar7 % 0x3c,iVar10 % 1000,
                  iVar9);
      }
      if (param_8 != (undefined4 *)0x0) {
        *param_8 = 0;
      }
      if (param_9 != (undefined4 *)0x0) {
        *param_9 = 0;
      }
      FUN_40c0209c(local_30);
      return 0;
    }
  }
  FUN_40c0209c(DAT_40c08174);
  return 0x80070057;
}



/* 40bfa7c4 FUN_40bfa7c4 */

/* Boundary evidence: original MIPS .pdata 40bfa7c4..40bfa973. Semantic name remains unreviewed. */

undefined4 FUN_40bfa7c4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *local_28 [2];
  
  if (param_3 == -1) {
    *(undefined1 *)(param_1 + 0x76) = 1;
  }
  else if (param_3 == 1) {
    if (-1 < param_2) {
      iVar2 = *(int *)(param_1 + 100);
      if (param_2 < iVar2) {
        iVar4 = *(int *)(*(int *)(param_2 * 4 + *(int *)(param_1 + 0x68)) + 0x2d8);
        iVar3 = 0;
        if (0 < iVar2) {
          iVar2 = 0;
          do {
            iVar1 = *(int *)(*(int *)(param_1 + 0x68) + iVar2);
            if (*(int *)(iVar1 + 0x2d8) == iVar4) {
              FUN_40bf5f54(iVar1,iVar3 == param_2);
              EventModify(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x68) + iVar2) + 0x70),3);
            }
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 4;
          } while (iVar3 < *(int *)(param_1 + 100));
        }
        return 0;
      }
      if ((*(char *)(param_1 + 0x75) != '\0') && (param_2 - iVar2 < *(int *)(param_1 + 0x6c))) {
        if (*(char *)(param_1 + 0x74) == '\0') {
          return 0;
        }
        iVar3 = (**(code **)**(undefined4 **)(param_1 + 0x48))
                          (*(undefined4 **)(param_1 + 0x48),&DAT_40c067b0,local_28);
        if (-1 < iVar3) {
          (**(code **)(*local_28[0] + 0x38))
                    (local_28[0],*(int *)(param_1 + 0x70) + (param_2 - iVar2) * 0x48 + 0x40,1,0,0);
          (**(code **)(*local_28[0] + 8))();
        }
        return 0;
      }
    }
    return 0x80070057;
  }
  return 0;
}



/* 40bfa974 FUN_40bfa974 */

/* WARNING: Removing unreachable block (ram,0x40bfaa30) */
/* Boundary evidence: original MIPS .pdata 40bfa974..40bfaa77. Semantic name remains unreviewed. */

longlong FUN_40bfa974(uint param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar1 = (undefined4)((ulonglong)param_1 * (ulonglong)param_5);
  iVar2 = param_1 * param_6 + param_2 * param_5 +
          (int)((ulonglong)param_1 * (ulonglong)param_5 >> 0x20);
  lVar3 = __ll_div(uVar1,iVar2,param_3,param_4);
  lVar4 = __ll_rem(uVar1,iVar2,param_3,param_4);
  if (CONCAT44(param_4 >> 1,param_4 << 0x1f | param_3 >> 1) < lVar4) {
    lVar3 = lVar3 + 1;
  }
  return lVar3;
}



/* 40bfaa78 FUN_40bfaa78 */

/* Boundary evidence: original MIPS .pdata 40bfaa78..40bfabb7. Semantic name remains unreviewed. */

undefined4
FUN_40bfaa78(int *param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = malloc(0x38);
  *param_1 = (int)puVar1;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[3] = 0x38;
  puVar1 = (undefined4 *)*param_1;
  *puVar1 = 0x65646976;
  *(undefined2 *)(puVar1 + 1) = 0x6f;
  *(undefined1 *)(*param_1 + 8) = *param_2;
  *(undefined1 *)(*param_1 + 9) = param_2[1];
  *(undefined1 *)(*param_1 + 10) = param_2[2];
  *(undefined1 *)(*param_1 + 0xb) = param_2[3];
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x10) = param_3;
  *(undefined4 *)(iVar2 + 0x14) = param_4;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x18) = 1;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(*param_1 + 0x20) = 1;
  *(undefined4 *)(*param_1 + 0x24) = param_8;
  *(undefined2 *)(*param_1 + 0x28) = param_7;
  *(undefined4 *)(*param_1 + 0x2c) = param_5;
  *(undefined4 *)(*param_1 + 0x30) = param_6;
  return 0;
}



/* 40bfabb8 FUN_40bfabb8 */

/* Boundary evidence: original MIPS .pdata 40bfabb8..40bfad6b. Semantic name remains unreviewed. */

undefined4
FUN_40bfabb8(int *param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4,
            undefined4 param_5,int param_6,undefined2 param_7,void *param_8,size_t param_9,
            undefined4 param_10)

{
  undefined4 *puVar1;
  int iVar2;
  char local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  uint local_28;
  
  local_28 = DAT_40c08174;
  puVar1 = malloc(param_9 + 0x38);
  *param_1 = (int)puVar1;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[3] = 0x38;
  *(size_t *)(*param_1 + 0xc) = param_9 + 0x38;
  puVar1 = (undefined4 *)*param_1;
  *puVar1 = 0x69647561;
  *(undefined2 *)(puVar1 + 1) = 0x6f;
  sprintf(&local_30,"%04x",param_2);
  *(char *)(*param_1 + 8) = local_30;
  *(undefined1 *)(*param_1 + 9) = local_2f;
  *(undefined1 *)(*param_1 + 10) = local_2e;
  *(undefined1 *)(*param_1 + 0xb) = local_2d;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x10) = 10000000;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  iVar2 = *param_1;
  *(int *)(iVar2 + 0x18) = param_6;
  *(int *)(iVar2 + 0x1c) = param_6 >> 0x1f;
  *(undefined4 *)(*param_1 + 0x20) = 1;
  *(undefined2 *)(*param_1 + 0x28) = param_7;
  *(undefined2 *)(*param_1 + 0x2c) = param_3;
  *(undefined2 *)(*param_1 + 0x2e) = param_4;
  *(undefined4 *)(*param_1 + 0x30) = param_5;
  *(undefined4 *)(*param_1 + 0x24) = param_10;
  memcpy((void *)(*param_1 + 0x38),param_8,param_9);
  FUN_40c0209c(local_28);
  return 0;
}



/* 40bfad6c FUN_40bfad6c */

/* Boundary evidence: original MIPS .pdata 40bfad6c..40bfad9b. Semantic name remains unreviewed. */

void FUN_40bfad6c(undefined1 *param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *param_1 = 1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_40bf2d20((int *)(param_1 + 0x30),param_2);
  return;
}



/* 40bfad9c FUN_40bfad9c */

/* Boundary evidence: original MIPS .pdata 40bfad9c..40bfadeb. Semantic name remains unreviewed. */

void FUN_40bfad9c(undefined1 *param_1)

{
  if (*(void **)(param_1 + 0x1c) != (void *)0x0) {
    free(*(void **)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *param_1 = 1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_40bf1f40((undefined4 *)(param_1 + 0x30));
  return;
}



/* 40bfadec FUN_40bfadec */

/* Boundary evidence: original MIPS .pdata 40bfadec..40bfae3b. Semantic name remains unreviewed. */

void FUN_40bfadec(undefined1 *param_1)

{
  if (*(void **)(param_1 + 0x1c) != (void *)0x0) {
    free(*(void **)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *param_1 = 1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_40bf2b38((int *)(param_1 + 0x30));
  return;
}



/* 40bfae3c FUN_40bfae3c */

/* Boundary evidence: original MIPS .pdata 40bfae3c..40bfb03b. Semantic name remains unreviewed. */

int FUN_40bfae3c(char *param_1,int param_2,int param_3,uint *param_4,longlong *param_5,
                undefined4 *param_6,int *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  byte *local_40;
  int local_3c;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  
  if ((param_6 == (undefined4 *)0x0) || (param_7 == (int *)0x0)) {
    return -0x800;
  }
  iVar1 = FUN_40bf2ce0((int *)(param_1 + 0x30),(int *)&local_40);
  if (iVar1 < 1) {
    return iVar1;
  }
  if (local_3c < 1) {
    return -0x801;
  }
  if ((*local_40 & 1) != 0) {
    *param_1 = '\0';
    *(uint *)(param_1 + 8) = local_28;
    *(int *)(param_1 + 0xc) = local_24;
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[0x13] = '\0';
    param_1[0x14] = '\0';
    param_1[0x15] = '\0';
    param_1[0x16] = '\0';
    param_1[0x17] = '\0';
    param_1[0x18] = '\0';
    param_1[0x19] = '\0';
    param_1[0x1a] = '\0';
    param_1[0x1b] = '\0';
    return -0x801;
  }
  if (param_3 != 0) {
    *(bool *)param_3 = local_34 != 0;
  }
  *param_6 = local_40;
  *param_7 = local_3c;
  iVar2 = FUN_40bf3f48(param_2,&local_40);
  if ((local_30 & local_2c) == 0xffffffff) {
    uVar4 = *(uint *)(param_1 + 8) + 1;
    uVar5 = local_30;
    uVar6 = local_2c;
    if (((local_28 != uVar4) ||
        (local_24 != *(int *)(param_1 + 0xc) + (uint)(uVar4 < *(uint *)(param_1 + 8)))) ||
       (*param_1 != '\0')) goto LAB_40bfafa4;
    local_30 = *(uint *)(param_1 + 0x10);
    local_2c = *(uint *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x18) != 0) {
      iVar3 = *(int *)(param_1 + 0x18) + (iVar2 >> 1);
      uVar5 = iVar3 >> 1;
      local_30 = uVar5 + local_30;
      local_2c = (iVar3 >> 0x1f) + local_2c + (uint)(local_30 < uVar5);
    }
    uVar5 = local_30;
    uVar6 = local_2c;
    if ((local_30 & local_2c) == 0xffffffff) goto LAB_40bfafa4;
  }
  *param_1 = '\0';
  uVar5 = local_30;
  uVar6 = local_2c;
LAB_40bfafa4:
  *(uint *)(param_1 + 8) = local_28;
  *(int *)(param_1 + 0xc) = local_24;
  *(uint *)(param_1 + 0x10) = uVar5;
  *(uint *)(param_1 + 0x14) = uVar6;
  *(int *)(param_1 + 0x18) = iVar2 >> 1;
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar5;
    param_4[1] = uVar6;
  }
  if (param_5 != (longlong *)0x0) {
    lVar7 = FUN_40bfa974(10000000,0,*(uint *)(param_2 + 8),(int)*(uint *)(param_2 + 8) >> 0x1f,uVar5
                         ,uVar6);
    *param_5 = lVar7;
  }
  if ((uVar5 & uVar6) == 0xffffffff) {
    return -0x804;
  }
  return iVar1;
}



/* 40bfb03c FUN_40bfb03c */

/* Boundary evidence: original MIPS .pdata 40bfb03c..40bfb23b. Semantic name remains unreviewed. */

int FUN_40bfb03c(char *param_1,int param_2,int param_3,uint *param_4,longlong *param_5,
                undefined4 *param_6,int *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  byte *local_40;
  int local_3c;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  
  if ((param_6 == (undefined4 *)0x0) || (param_7 == (int *)0x0)) {
    return -0x800;
  }
  iVar1 = FUN_40bf2ce0((int *)(param_1 + 0x30),(int *)&local_40);
  if (iVar1 < 1) {
    return iVar1;
  }
  if (local_3c < 1) {
    return -0x801;
  }
  if ((*local_40 & 1) != 0) {
    *param_1 = '\0';
    *(uint *)(param_1 + 8) = local_28;
    *(int *)(param_1 + 0xc) = local_24;
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[0x13] = '\0';
    param_1[0x14] = '\0';
    param_1[0x15] = '\0';
    param_1[0x16] = '\0';
    param_1[0x17] = '\0';
    param_1[0x18] = '\0';
    param_1[0x19] = '\0';
    param_1[0x1a] = '\0';
    param_1[0x1b] = '\0';
  }
  if (param_3 != 0) {
    *(bool *)param_3 = local_34 != 0;
  }
  *param_6 = local_40;
  *param_7 = local_3c;
  iVar2 = FUN_40bf3f48(param_2,&local_40);
  if ((local_30 & local_2c) == 0xffffffff) {
    uVar4 = *(uint *)(param_1 + 8) + 1;
    uVar5 = local_30;
    uVar6 = local_2c;
    if (((local_28 != uVar4) ||
        (local_24 != *(int *)(param_1 + 0xc) + (uint)(uVar4 < *(uint *)(param_1 + 8)))) ||
       (*param_1 != '\0')) goto LAB_40bfb1a4;
    local_30 = *(uint *)(param_1 + 0x10);
    local_2c = *(uint *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x18) != 0) {
      iVar3 = *(int *)(param_1 + 0x18) + (iVar2 >> 1);
      uVar5 = iVar3 >> 1;
      local_30 = uVar5 + local_30;
      local_2c = (iVar3 >> 0x1f) + local_2c + (uint)(local_30 < uVar5);
    }
    uVar5 = local_30;
    uVar6 = local_2c;
    if ((local_30 & local_2c) == 0xffffffff) goto LAB_40bfb1a4;
  }
  *param_1 = '\0';
  uVar5 = local_30;
  uVar6 = local_2c;
LAB_40bfb1a4:
  *(uint *)(param_1 + 8) = local_28;
  *(int *)(param_1 + 0xc) = local_24;
  *(uint *)(param_1 + 0x10) = uVar5;
  *(uint *)(param_1 + 0x14) = uVar6;
  *(int *)(param_1 + 0x18) = iVar2 >> 1;
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar5;
    param_4[1] = uVar6;
  }
  if (param_5 != (longlong *)0x0) {
    lVar7 = FUN_40bfa974(10000000,0,*(uint *)(param_2 + 8),(int)*(uint *)(param_2 + 8) >> 0x1f,uVar5
                         ,uVar6);
    *param_5 = lVar7;
  }
  if ((uVar5 & uVar6) == 0xffffffff) {
    iVar1 = -0x804;
  }
  return iVar1;
}



/* 40bfb23c FUN_40bfb23c */

uint FUN_40bfb23c(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)*param_2;
  if ((*pbVar3 & 1) != 0) {
    return 0xfffff7ff;
  }
  uVar2 = (*pbVar3 & 2) << 1 | (uint)(*pbVar3 >> 6);
  if (uVar2 == 0) {
    return *(uint *)(param_1 + 0x20);
  }
  uVar1 = 0;
  do {
    uVar1 = (uint)pbVar3[uVar2] | uVar1 << 8;
    uVar2 = (int)((uVar2 - 1) * 0x10000) >> 0x10;
  } while (uVar2 != 0);
  return uVar1;
}



/* 40bfb2c8 FUN_40bfb2c8 */

/* Boundary evidence: original MIPS .pdata 40bfb2c8..40bfb3bb. Semantic name remains unreviewed. */

undefined4 FUN_40bfb2c8(int *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)*param_2;
  if ((*pbVar1 & 7) != 1) {
    return 0xfffff7fe;
  }
  if (*(int *)(pbVar1 + 0x60) == 0x5589f80) {
    FUN_40bfaa78(param_1,pbVar1 + 0x44,*(undefined4 *)(pbVar1 + 0xa4),*(undefined4 *)(pbVar1 + 0xa8)
                 ,*(undefined4 *)(pbVar1 + 0xb0),*(undefined4 *)(pbVar1 + 0xb4),
                 *(undefined2 *)(pbVar1 + 0xb6),*(undefined4 *)(pbVar1 + 0x28));
    return 0;
  }
  if (*(int *)(pbVar1 + 0x60) == 0x5589f81) {
    FUN_40bfabb8(param_1,(int)*(short *)(pbVar1 + 0x7c),*(undefined2 *)(pbVar1 + 0x7e),
                 *(undefined2 *)(pbVar1 + 0x88),*(undefined4 *)(pbVar1 + 0x84),
                 *(int *)(pbVar1 + 0x80),*(undefined2 *)(pbVar1 + 0x8a),pbVar1 + 0x8e,
                 (int)*(short *)(pbVar1 + 0x8c),*(undefined4 *)(pbVar1 + 0x28));
    return 0;
  }
  *param_1 = 0;
  return 0xfffff7fd;
}



/* 40bfb3bc FUN_40bfb3bc */

/* Boundary evidence: original MIPS .pdata 40bfb3bc..40bfb57f. Semantic name remains unreviewed. */

undefined4 FUN_40bfb3bc(int *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  void *_Dst;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  byte *pbVar7;
  byte bVar8;
  byte *pbVar9;
  
  pbVar4 = (byte *)*param_2;
  if ((*pbVar4 & 1) == 0) {
    return 0xfffff7fe;
  }
  pbVar9 = pbVar4 + 1;
  pcVar6 = "Direct Show Samples embedded in Ogg";
  pbVar5 = pbVar9;
  do {
    bVar8 = *pbVar5;
    bVar1 = *pcVar6;
    if (bVar8 == 0) break;
    if (bVar8 != bVar1) goto LAB_40bfb44c;
    pbVar5 = pbVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (pbVar5 != pbVar4 + 0x24);
  if (bVar8 == bVar1) {
    uVar3 = FUN_40bfb2c8(param_1,param_2);
    return uVar3;
  }
LAB_40bfb44c:
  bVar8 = *pbVar4 & 7;
  if (bVar8 == 1) {
    pbVar7 = &DAT_40c03ae0;
    pbVar5 = pbVar9;
    do {
      bVar1 = *pbVar5;
      bVar2 = *pbVar7;
      if (bVar1 == 0) break;
      if (bVar1 != bVar2) goto LAB_40bfb4a0;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (pbVar5 != pbVar4 + 6);
    if (bVar1 != bVar2) {
LAB_40bfb4a0:
      pbVar7 = &DAT_40c03ad8;
      pbVar5 = pbVar9;
      do {
        bVar1 = *pbVar5;
        bVar2 = *pbVar7;
        if (bVar1 == 0) break;
        if (bVar1 != bVar2) goto LAB_40bfb4e0;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar7 + 1;
      } while (pbVar5 != pbVar4 + 6);
      if (bVar1 != bVar2) {
LAB_40bfb4e0:
        pbVar5 = &DAT_40c03ad0;
        do {
          bVar1 = *pbVar9;
          bVar2 = *pbVar5;
          if (bVar1 == 0) break;
          if (bVar1 != bVar2) goto LAB_40bfb554;
          pbVar9 = pbVar9 + 1;
          pbVar5 = pbVar5 + 1;
        } while (pbVar9 != pbVar4 + 5);
        if (bVar1 != bVar2) goto LAB_40bfb554;
      }
    }
    _Dst = malloc(*(size_t *)(pbVar4 + 0xd));
    *param_1 = (int)_Dst;
    memcpy(_Dst,(void *)(*param_2 + 1),*(size_t *)(pbVar4 + 0xd));
  }
  else {
LAB_40bfb554:
    if (bVar8 != 5) {
      *param_1 = 0;
      return 0xfffff7fd;
    }
  }
  return 0;
}



/* 40bfb580 FUN_40bfb580 */

/* Boundary evidence: original MIPS .pdata 40bfb580..40bfb833. Semantic name remains unreviewed. */

int FUN_40bfb580(char *param_1,int param_2,int param_3,undefined1 *param_4,uint *param_5,
                uint *param_6,longlong *param_7,longlong *param_8,undefined4 *param_9,int *param_10)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  longlong lVar8;
  byte *local_48;
  int local_44;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  iVar3 = FUN_40bf2ce0((int *)(param_1 + 0x30),(int *)&local_48);
  if (iVar3 < 1) {
    return iVar3;
  }
  bVar1 = *local_48;
  if ((bVar1 & 1) != 0) {
    *param_1 = '\0';
    *(uint *)(param_1 + 8) = local_30;
    *(int *)(param_1 + 0xc) = local_2c;
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[0x13] = '\0';
    param_1[0x14] = '\0';
    param_1[0x15] = '\0';
    param_1[0x16] = '\0';
    param_1[0x17] = '\0';
    param_1[0x18] = '\0';
    param_1[0x19] = '\0';
    param_1[0x1a] = '\0';
    param_1[0x1b] = '\0';
    return -0x801;
  }
  uVar6 = (bVar1 & 2) << 1 | (uint)(bVar1 >> 6);
  uVar7 = 1;
  if (param_3 != 0) {
    *(bool *)param_3 = local_3c != 0;
  }
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = local_48 + uVar6 + 1;
  }
  if (param_10 != (int *)0x0) {
    *param_10 = (local_44 - uVar6) + -1;
  }
  uVar6 = FUN_40bfb23c(param_2,&local_48);
  if ((local_38 & local_34) == 0xffffffff) {
    uVar4 = *(uint *)(param_1 + 8) + 1;
    if (((local_30 != uVar4) ||
        (local_2c != *(int *)(param_1 + 0xc) + (uint)(uVar4 < *(uint *)(param_1 + 8)))) ||
       (*param_1 != '\0')) goto LAB_40bfb70c;
    uVar4 = *(uint *)(param_1 + 0x18);
    local_38 = uVar4 + *(int *)(param_1 + 0x10);
    local_34 = ((int)uVar4 >> 0x1f) + *(int *)(param_1 + 0x14) + (uint)(local_38 < uVar4);
    if ((local_38 & local_34) == 0xffffffff) goto LAB_40bfb70c;
  }
  *param_1 = '\0';
LAB_40bfb70c:
  uVar2 = local_34;
  uVar4 = local_38;
  *(uint *)(param_1 + 8) = local_30;
  *(int *)(param_1 + 0xc) = local_2c;
  *(uint *)(param_1 + 0x10) = local_38;
  *(uint *)(param_1 + 0x14) = local_34;
  *(uint *)(param_1 + 0x18) = uVar6;
  if (param_4 != (undefined1 *)0x0) {
    if (((local_38 & local_34) == 0xffffffff) || ((*local_48 & 8) == 0)) {
      uVar7 = 0;
    }
    *param_4 = uVar7;
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = local_38;
    param_5[1] = local_34;
  }
  if (param_6 != (uint *)0x0) {
    *param_6 = uVar6;
    param_6[1] = (int)uVar6 >> 0x1f;
  }
  if (param_7 != (longlong *)0x0) {
    lVar8 = FUN_40bfa974(*(uint *)(param_2 + 0x10),*(int *)(param_2 + 0x14),
                         *(uint *)(param_2 + 0x18),*(int *)(param_2 + 0x1c),local_38,local_34);
    *param_7 = lVar8;
  }
  if (param_8 != (longlong *)0x0) {
    uVar5 = uVar6 + uVar4;
    lVar8 = FUN_40bfa974(*(uint *)(param_2 + 0x10),*(int *)(param_2 + 0x14),
                         *(uint *)(param_2 + 0x18),*(int *)(param_2 + 0x1c),uVar5,
                         ((int)uVar6 >> 0x1f) + uVar2 + (uint)(uVar5 < uVar6));
    *param_8 = lVar8;
  }
  if ((uVar4 & uVar2) == 0xffffffff) {
    iVar3 = -0x804;
  }
  return iVar3;
}



/* 40bfb834 DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40bfb834..40bfb84f. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0xb834  3  DllRegisterServer */
  FUN_40c01688(1);
  return;
}



/* 40bfb850 DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40bfb850..40bfb86b. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0xb850  4  DllUnregisterServer */
  FUN_40c01688(0);
  return;
}



/* 40bfb86c FUN_40bfb86c */

/* Boundary evidence: original MIPS .pdata 40bfb86c..40bfb887. Semantic name remains unreviewed. */

void FUN_40bfb86c(HMODULE param_1,int param_2)

{
  FUN_40c01780(param_1,param_2);
  return;
}



/* 40bfb888 FUN_40bfb888 */

/* Boundary evidence: original MIPS .pdata 40bfb888..40bfb8d7. Semantic name remains unreviewed. */

void FUN_40bfb888(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  wchar_t awStack_3f8 [500];
  uint local_10;
  
  local_10 = DAT_40c08174;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf(awStack_3f8,param_1,(wchar_t *)&local_res4,param_4);
  OutputDebugStringW(awStack_3f8);
  FUN_40c0209c(local_10);
  return;
}



/* 40bfb8d8 FUN_40bfb8d8 */

/* Boundary evidence: original MIPS .pdata 40bfb8d8..40bfba97. Semantic name remains unreviewed. */

undefined4 FUN_40bfb8d8(int param_1)

{
  wchar_t wVar1;
  wchar_t wVar2;
  LSTATUS LVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  DWORD dwIndex;
  HKEY local_238;
  DWORD local_234;
  undefined4 local_230;
  DWORD local_22c;
  WCHAR local_228 [256];
  uint local_28;
  
  local_28 = DAT_40c08174;
  LVar3 = RegOpenKeyExW((HKEY)0x80000000,
                        L"CLSID\\{f07e245f-5a1f-4d1e-8bff-dc31d84a55ab}\\Pins\\Input",0,0x20019,
                        &local_238);
  if (LVar3 == 0) {
    local_22c = 4;
    dwIndex = 0;
    do {
      local_234 = 0x100;
      LVar3 = RegEnumValueW(local_238,dwIndex,local_228,&local_234,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPBYTE)&local_230,&local_22c);
      if (LVar3 != 0) break;
      pwVar5 = local_228;
      pwVar4 = L"read_buffersize";
      do {
        wVar1 = *pwVar4;
        wVar2 = *pwVar5;
        if (wVar1 == L'\0') break;
        pwVar4 = pwVar4 + 1;
        pwVar5 = pwVar5 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x118) = local_230;
      }
      pwVar5 = local_228;
      pwVar4 = L"inital_startscansize";
      do {
        wVar1 = *pwVar4;
        wVar2 = *pwVar5;
        if (wVar1 == L'\0') break;
        pwVar4 = pwVar4 + 1;
        pwVar5 = pwVar5 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x11c) = local_230;
      }
      pwVar5 = local_228;
      pwVar4 = L"inital_endscansize";
      do {
        wVar1 = *pwVar4;
        wVar2 = *pwVar5;
        if (wVar1 == L'\0') break;
        pwVar4 = pwVar4 + 1;
        pwVar5 = pwVar5 + 1;
      } while (wVar1 == wVar2);
      if (wVar1 == wVar2) {
        *(undefined4 *)(param_1 + 0x120) = local_230;
      }
      dwIndex = dwIndex + 1;
    } while ((int)dwIndex < 0xc);
    RegCloseKey(local_238);
  }
  FUN_40c0209c(local_28);
  return 0;
}



/* 40bfba98 FUN_40bfba98 */

/* Boundary evidence: original MIPS .pdata 40bfba98..40bfbad7. Semantic name remains unreviewed. */

void FUN_40bfba98(void *param_1)

{
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x514);
    free(param_1);
  }
  return;
}



/* 40bfbad8 FUN_40bfbad8 */

/* Boundary evidence: original MIPS .pdata 40bfbad8..40bfbca7. Semantic name remains unreviewed. */

uint * FUN_40bfbad8(int param_1,int *param_2)

{
  uint *_Dst;
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = 0;
  _Dst = calloc(1,0x514);
  iVar7 = *(int *)(param_1 + 0x20);
  uVar1 = FUN_40bf1028(param_2,0x18);
  *_Dst = uVar1;
  uVar1 = FUN_40bf1028(param_2,0x18);
  _Dst[1] = uVar1;
  uVar1 = FUN_40bf1028(param_2,0x18);
  _Dst[2] = uVar1 + 1;
  uVar1 = FUN_40bf1028(param_2,6);
  _Dst[3] = uVar1 + 1;
  uVar1 = FUN_40bf1028(param_2,8);
  _Dst[4] = uVar1;
  iVar6 = 0;
  if (0 < (int)_Dst[3]) {
    puVar4 = _Dst + 5;
    do {
      uVar1 = FUN_40bf1028(param_2,3);
      uVar2 = FUN_40bf1028(param_2,1);
      if (uVar2 != 0) {
        uVar2 = FUN_40bf1028(param_2,5);
        uVar1 = uVar2 << 3 | uVar1;
      }
      *puVar4 = uVar1;
      iVar3 = 0;
      for (; uVar1 != 0; uVar1 = uVar1 >> 1) {
        iVar3 = (uVar1 & 1) + iVar3;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar3 + iVar5;
      puVar4 = puVar4 + 1;
    } while (iVar6 < (int)_Dst[3]);
  }
  if (0 < iVar5) {
    puVar4 = _Dst + 0x45;
    iVar6 = iVar5;
    do {
      uVar1 = FUN_40bf1028(param_2,8);
      iVar6 = iVar6 + -1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
    } while (iVar6 != 0);
  }
  iVar6 = *(int *)(iVar7 + 0x18);
  if ((int)_Dst[4] < iVar6) {
    iVar7 = 0;
    if (0 < iVar5) {
      puVar4 = _Dst + 0x45;
      do {
        if (iVar6 <= (int)*puVar4) goto LAB_40bfbc64;
        iVar7 = iVar7 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar7 < iVar5);
    }
  }
  else {
LAB_40bfbc64:
    memset(_Dst,0,0x514);
    free(_Dst);
    _Dst = (uint *)0x0;
  }
  return _Dst;
}



/* 40bfbca8 FUN_40bfbca8 */

int FUN_40bfbca8(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



/* 40bfbcc4 FUN_40bfbcc4 */

/* Boundary evidence: original MIPS .pdata 40bfbcc4..40bfbedb. Semantic name remains unreviewed. */

uint FUN_40bfbcc4(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  switch(*param_1) {
  case 1:
    uVar8 = param_1[1];
    break;
  case 2:
    uVar4 = param_1[1];
    uVar8 = 0;
    uVar2 = 0x40000000;
    do {
      uVar7 = uVar2 + uVar8;
      if (uVar7 <= uVar4) {
        uVar4 = uVar4 - uVar7;
        uVar8 = uVar7 + uVar2;
      }
      uVar2 = uVar2 >> 2;
      uVar8 = uVar8 >> 1;
    } while (uVar2 != 0);
    break;
  default:
    uVar8 = 1;
    FUN_40bfb888(0x40c0660c,*param_1,param_3,param_4);
    break;
  case 4:
    uVar2 = 0x40000000;
    uVar7 = param_1[1];
    uVar4 = 0;
    uVar8 = 0x40000000;
    do {
      uVar6 = uVar8 + uVar4;
      if (uVar6 <= uVar7) {
        uVar7 = uVar7 - uVar6;
        uVar4 = uVar6 + uVar8;
      }
      uVar8 = uVar8 >> 2;
      uVar4 = uVar4 >> 1;
    } while (uVar8 != 0);
    uVar8 = 0;
    do {
      uVar7 = uVar2 + uVar8;
      if (uVar7 <= uVar4) {
        uVar4 = uVar4 - uVar7;
        uVar8 = uVar7 + uVar2;
      }
      uVar2 = uVar2 >> 2;
      uVar8 = uVar8 >> 1;
    } while (uVar2 != 0);
    break;
  case 8:
    uVar2 = 0x40000000;
    uVar7 = param_1[1];
    uVar8 = 0;
    uVar4 = 0x40000000;
    do {
      uVar6 = uVar4 + uVar8;
      if (uVar6 <= uVar7) {
        uVar7 = uVar7 - uVar6;
        uVar8 = uVar6 + uVar4;
      }
      uVar4 = uVar4 >> 2;
      uVar8 = uVar8 >> 1;
    } while (uVar4 != 0);
    uVar4 = 0;
    uVar7 = 0x40000000;
    do {
      uVar6 = uVar7 + uVar4;
      if (uVar6 <= uVar8) {
        uVar8 = uVar8 - uVar6;
        uVar4 = uVar6 + uVar7;
      }
      uVar7 = uVar7 >> 2;
      uVar4 = uVar4 >> 1;
    } while (uVar7 != 0);
    uVar8 = 0;
    do {
      uVar7 = uVar2 + uVar8;
      if (uVar7 <= uVar4) {
        uVar4 = uVar4 - uVar7;
        uVar8 = uVar7 + uVar2;
      }
      uVar2 = uVar2 >> 2;
      uVar8 = uVar8 >> 1;
    } while (uVar2 != 0);
  }
  while( true ) {
    while( true ) {
      iVar5 = 1;
      iVar3 = 1;
      if (0 < *param_1) {
        iVar1 = *param_1;
        do {
          iVar5 = iVar5 * uVar8;
          iVar1 = iVar1 + -1;
          iVar3 = (uVar8 + 1) * iVar3;
        } while (iVar1 != 0);
      }
      if (iVar5 <= param_1[1]) break;
      uVar8 = uVar8 - 1;
    }
    if (param_1[1] < iVar3) break;
    uVar8 = uVar8 + 1;
  }
  return uVar8;
}



/* 40bfbedc FUN_40bfbedc */

/* Boundary evidence: original MIPS .pdata 40bfbedc..40bfbf67. Semantic name remains unreviewed. */

void FUN_40bfbedc(undefined4 *param_1)

{
  if (param_1[0xc] != 0) {
    if ((void *)param_1[8] != (void *)0x0) {
      free((void *)param_1[8]);
    }
    if ((void *)param_1[2] != (void *)0x0) {
      free((void *)param_1[2]);
    }
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
  }
  return;
}



/* 40bfbf68 FUN_40bfbf68 */

/* Boundary evidence: original MIPS .pdata 40bfbf68..40bfbfa3. Semantic name remains unreviewed. */

void FUN_40bfbf68(undefined4 *param_1)

{
  if (param_1[0xc] != 0) {
    FUN_40bfbedc(param_1);
    free(param_1);
  }
  return;
}



/* 40bfbfa4 FUN_40bfbfa4 */

/* Boundary evidence: original MIPS .pdata 40bfbfa4..40bfbfff. Semantic name remains unreviewed. */

undefined4 FUN_40bfbfa4(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  if (param_2 == (void *)0x0) {
    return 0x80004003;
  }
  iVar1 = memcmp(param_2,&DAT_40c05bd4,0x10);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}



/* 40bfc048 FUN_40bfc048 */

/* Boundary evidence: original MIPS .pdata 40bfc048..40bfc0a7. Semantic name remains unreviewed. */

undefined4 FUN_40bfc048(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  if (param_2 == (void *)0x0) {
    return 0x80004003;
  }
  iVar1 = memcmp(param_2,&DAT_40c05bd4,0x10);
  if (iVar1 == 0) {
    return 0;
  }
  return 0x80070057;
}



/* 40bfc0a8 FUN_40bfc0a8 */

/* Boundary evidence: original MIPS .pdata 40bfc0a8..40bfc103. Semantic name remains unreviewed. */

undefined4 FUN_40bfc0a8(undefined4 param_1,void *param_2)

{
  int iVar1;
  
  if (param_2 == (void *)0x0) {
    return 0x80004003;
  }
  iVar1 = memcmp(param_2,&DAT_40c05bd4,0x10);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}



/* 40bfc168 FUN_40bfc168 */

/* Boundary evidence: original MIPS .pdata 40bfc168..40bfc223. Semantic name remains unreviewed. */

undefined4
FUN_40bfc168(undefined4 param_1,undefined4 *param_2,void *param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,void *param_7)

{
  int iVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  if (((param_3 == (void *)0x0) || (iVar1 = memcmp(param_3,&DAT_40c05bd4,0x10), iVar1 == 0)) &&
     ((param_7 == (void *)0x0 || (iVar1 = memcmp(param_7,&DAT_40c05bd4,0x10), iVar1 == 0)))) {
    *param_2 = param_5;
    param_2[1] = param_6;
    return 0;
  }
  return 0x80070057;
}



/* 40bfc224 FUN_40bfc224 */

undefined4 FUN_40bfc224(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0xa8);
    param_2[1] = *(undefined4 *)(param_1 + 0xac);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0xb0);
    param_3[1] = *(undefined4 *)(param_1 + 0xb4);
  }
  return 0;
}



/* 40bfc25c FUN_40bfc25c */

undefined4 FUN_40bfc25c(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0xb8);
    param_2[1] = *(undefined4 *)(param_1 + 0xbc);
  }
  return 0;
}



/* 40bfc2a4 FUN_40bfc2a4 */

/* WARNING: Removing unreachable block (ram,0x40bfc620) */
/* WARNING: Removing unreachable block (ram,0x40bfc4f8) */
/* Boundary evidence: original MIPS .pdata 40bfc2a4..40bfc6e7. Semantic name remains unreviewed. */

void FUN_40bfc2a4(int param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  bool bVar1;
  longlong lVar2;
  bool bVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  longlong lVar19;
  undefined8 uVar20;
  longlong lVar21;
  int local_64;
  undefined8 local_60;
  uint local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  int aiStack_38 [4];
  
  local_54 = 0;
  lVar6 = *(longlong *)(param_1 + 0x148);
  lVar5 = 0;
  lVar2 = 0;
  local_60 = CONCAT44(param_6,param_5);
  if (param_3 == 0 && param_4 == 0) {
    *(undefined4 *)(param_1 + 0x150) = 0;
    *(undefined4 *)(param_1 + 0x154) = 0;
  }
  else if ((param_4 < param_6) || ((param_4 == param_6 && (param_3 < param_5)))) {
    uVar8 = __ll_to_f(param_3,param_4);
    piVar18 = (int *)(param_1 + 300);
    do {
      local_50 = (int)((ulonglong)lVar5 >> 0x20);
      local_58 = (uint)lVar5;
      local_64 = (int)((ulonglong)lVar6 >> 0x20);
      uVar17 = (uint)lVar6;
      local_4c = (undefined4)((ulonglong)lVar2 >> 0x20);
      uVar9 = (undefined4)lVar2;
      lVar2 = CONCAT44(local_4c,local_54);
      FUN_40bf2b04((int)piVar18);
      bVar3 = true;
      uVar9 = __ll_to_f(uVar9,local_4c);
      uVar10 = __ll_to_f(local_58,local_50);
      uVar11 = __ll_to_f(uVar17,local_64);
      uVar11 = __fpsub(uVar11,uVar10);
      uVar12 = __fpsub(uVar8,uVar9);
      uVar11 = __fpmul(uVar11,uVar12);
      uVar12 = __ll_to_f((int)local_60,(int)((ulonglong)local_60 >> 0x20));
      uVar9 = __fpsub(uVar12,uVar9);
      uVar9 = __fpdiv(uVar11,uVar9);
      uVar9 = __fpadd(uVar9,uVar10);
      lVar19 = __f_to_ll(uVar9);
      iVar13 = (int)((ulonglong)lVar19 >> 0x20);
      uVar16 = (uint)lVar19;
      uVar15 = local_64 - iVar13;
      if (((int)(uVar15 - (uVar17 < uVar16)) < 1) &&
         ((uVar15 != uVar17 < uVar16 || (uVar17 - uVar16 < 0x1000)))) {
        local_64 = local_64 - (uint)(uVar17 < 0x1000);
        lVar19 = CONCAT44(local_64,uVar17 - 0x1000);
        if ((local_64 < 1) && (lVar19 = CONCAT44(local_64,uVar17 - 0x1000), local_64 != 0)) {
          lVar19 = 0;
        }
      }
      else {
        uVar15 = iVar13 - local_50;
        if (((int)(uVar15 - (uVar16 < local_58)) < 1) &&
           ((uVar15 != uVar16 < local_58 || (uVar16 - local_58 < 0x1000)))) {
          lVar19 = lVar5 + 0x1000;
        }
      }
      bVar1 = false;
      iVar13 = FUN_40bf25c8(piVar18,aiStack_38);
      lVar7 = lVar19;
      lVar4 = lVar6;
      while ((iVar13 != 1 && (!bVar1))) {
        if (lVar7 < *(longlong *)(param_1 + 0x148)) {
          iVar13 = *(int *)(param_1 + 0x148) - (int)lVar7;
          if (0x1000 < iVar13) {
            iVar13 = 0x1000;
          }
          FUN_40bf2288(piVar18,iVar13);
          (**(code **)(**(int **)(param_1 + 0x128) + 0x1c))();
          FUN_40bf2364((int)piVar18,iVar13);
          lVar7 = lVar7 + iVar13;
        }
        else if (bVar3) {
          bVar3 = false;
        }
        else {
          bVar1 = true;
          local_60 = CONCAT44(param_6,param_5);
          lVar4 = lVar19;
        }
        iVar13 = FUN_40bf25c8(piVar18,aiStack_38);
      }
      lVar7 = local_60;
      lVar6 = lVar4;
      if (!bVar1) {
        iVar13 = FUN_40bf1ec4(aiStack_38);
        iVar14 = FUN_40bf6ee4(*(int *)(param_1 + 0x124),iVar13);
        if (iVar14 != 0) {
          uVar20 = FUN_40bf1e38(aiStack_38);
          lVar21 = FUN_40bf5f74(iVar14,iVar13,(uint)uVar20,(int)((ulonglong)uVar20 >> 0x20));
          lVar7 = lVar21;
          lVar6 = lVar19;
          if (lVar21 < CONCAT44(param_4,param_3)) {
            lVar7 = local_60;
            local_54 = (int)lVar21;
            lVar2 = lVar21;
            lVar5 = lVar19;
            lVar6 = lVar4;
          }
        }
      }
      local_60 = lVar7;
      local_64 = (int)((ulonglong)lVar6 >> 0x20);
      local_50 = (int)((ulonglong)lVar5 >> 0x20);
      local_58 = (uint)lVar5;
      uVar16 = (uint)((uint)lVar6 < local_58);
    } while ((0 < (int)((local_64 - local_50) - uVar16)) ||
            ((local_64 - local_50 == uVar16 && (0x2000 < (uint)lVar6 - local_58))));
    *(longlong *)(param_1 + 0x150) = lVar5;
  }
  else {
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x148);
    *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x14c);
  }
  return;
}



/* 40bfc6e8 FUN_40bfc6e8 */

/* Boundary evidence: original MIPS .pdata 40bfc6e8..40bfc89b. Semantic name remains unreviewed. */

void FUN_40bfc6e8(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int aiStack_38 [4];
  
  iVar1 = FUN_40bf6f34(*(int *)(param_1 + 0x124),&DAT_40c049e4);
  if (iVar1 != 0) {
    piVar5 = (int *)(param_1 + 300);
    iVar7 = *(int *)(iVar1 + 0x2d4);
    uVar4 = *(uint *)(param_1 + 0x150);
    iVar6 = *(int *)(param_1 + 0x154);
    FUN_40bf2b04((int)piVar5);
    FUN_40bfadec((undefined1 *)(iVar1 + 0x90));
    *(undefined1 *)(iVar1 + 0x23c) = 1;
    do {
      do {
        while( true ) {
          iVar2 = FUN_40bf25c8(piVar5,aiStack_38);
          if (iVar2 < 1) {
            iVar2 = FUN_40bf25c8(piVar5,aiStack_38);
          }
          if (iVar2 == 1) break;
          if (iVar2 == 0) {
            if (*(int *)(param_1 + 0x14c) < iVar6) {
              return;
            }
            if ((iVar6 == *(int *)(param_1 + 0x14c)) && (*(uint *)(param_1 + 0x148) <= uVar4)) {
              return;
            }
            uVar3 = *(uint *)(param_1 + 0x148) - uVar4;
            if (0x1000 < (int)uVar3) {
              uVar3 = 0x1000;
            }
            FUN_40bf2288(piVar5,uVar3);
            (**(code **)(**(int **)(param_1 + 0x128) + 0x1c))();
            FUN_40bf2364((int)piVar5,uVar3);
            uVar4 = uVar3 + uVar4;
            iVar6 = ((int)uVar3 >> 0x1f) + iVar6 + (uint)(uVar4 < uVar3);
          }
        }
        iVar2 = FUN_40bf1ec4(aiStack_38);
      } while (iVar2 != iVar7);
      if ((*(char *)(iVar1 + 0x23c) != '\0') && (iVar2 = FUN_40bf1ef4(aiStack_38), iVar2 != 0)) {
        *(undefined1 *)(iVar1 + 0x23c) = 0;
      }
    } while ((*(char *)(iVar1 + 0x23c) != '\0') ||
            (iVar2 = FUN_40bf6724(iVar1,aiStack_38,param_2), iVar2 == 0));
  }
  return;
}



/* 40bfc89c FUN_40bfc89c */

/* Boundary evidence: original MIPS .pdata 40bfc89c..40bfc907. Semantic name remains unreviewed. */

undefined4 FUN_40bfc89c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(iVar2 + 0x40);
    EnterCriticalSection(lpCriticalSection);
    *param_2 = *(undefined4 *)(iVar2 + 0xa0);
    param_2[1] = *(undefined4 *)(iVar2 + 0xa4);
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40bfc908 FUN_40bfc908 */

/* Boundary evidence: original MIPS .pdata 40bfc908..40bfc973. Semantic name remains unreviewed. */

undefined4 FUN_40bfc908(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(iVar2 + 0x40);
    EnterCriticalSection(lpCriticalSection);
    *param_2 = *(undefined4 *)(iVar2 + 0xb0);
    param_2[1] = *(undefined4 *)(iVar2 + 0xb4);
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40bfc974 FUN_40bfc974 */

/* Boundary evidence: original MIPS .pdata 40bfc974..40bfcc2f. Semantic name remains unreviewed. */

undefined4
FUN_40bfc974(int param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,int param_6)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  if ((*(int *)(param_1 + 0x90) != 0) && (*(int *)(param_1 + 0x90) != param_6)) {
    uVar3 = *(uint *)(param_1 + 0xac);
    if (((*param_2 == *(uint *)(param_1 + 0xa8)) && (param_2[1] == uVar3)) ||
       ((*param_2 == *(uint *)(param_1 + 0x98) && (param_2[1] == *(uint *)(param_1 + 0x9c))))) {
      *param_2 = *(uint *)(param_1 + 0xa8);
      param_2[1] = uVar3;
      return 0;
    }
  }
  *(int *)(param_1 + 0x90) = param_6;
  uVar3 = param_3 & 3;
  *(uint *)(param_1 + 0x98) = *param_2;
  uVar8 = param_5 & 3;
  *(uint *)(param_1 + 0x9c) = param_2[1];
  if (param_5 != 0) {
    if (param_4 == (uint *)0x0) {
      return 0x80004003;
    }
    if (uVar8 != param_5) {
      return 0x80070057;
    }
  }
  if (((param_3 != 0) && (uVar3 != 1)) && (uVar3 != 2)) {
    return 0x80070057;
  }
  puVar1 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7c));
  FUN_40bf7e2c(param_1);
  if (uVar3 == 1) {
    uVar3 = param_2[1];
    *(uint *)(param_1 + 0xa8) = *param_2;
    *(uint *)(param_1 + 0xac) = uVar3;
  }
  else if (uVar3 == 2) {
    uVar3 = *(uint *)(param_1 + 0xa8);
    uVar5 = param_2[1];
    uVar6 = uVar3 + *param_2;
    *(uint *)(param_1 + 0xa8) = uVar6;
    *(uint *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + uVar5 + (uint)(uVar6 < uVar3);
  }
  if (uVar8 == 1) {
    uVar3 = param_4[1];
    *(uint *)(param_1 + 0xb0) = *param_4;
    *(uint *)(param_1 + 0xb4) = uVar3;
  }
  else if (uVar8 == 3) {
    uVar3 = *param_4;
    uVar8 = param_4[1];
    uVar6 = uVar3 + *(int *)(param_1 + 0xa8);
    *(uint *)(param_1 + 0xb0) = uVar6;
    *(uint *)(param_1 + 0xb4) = uVar8 + *(int *)(param_1 + 0xac) + (uint)(uVar6 < uVar3);
  }
  else if (uVar8 == 2) {
    uVar3 = *(uint *)(param_1 + 0xb0);
    uVar6 = param_4[1];
    uVar8 = uVar3 + *param_4;
    *(uint *)(param_1 + 0xb0) = uVar8;
    *(uint *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + uVar6 + (uint)(uVar8 < uVar3);
  }
  puVar7 = (uint *)(param_1 + 0xa8);
  iVar2 = *(int *)(param_1 + 0xac);
  iVar4 = *(int *)(param_1 + 0xa4);
  uVar3 = *(uint *)(param_1 + 0xa0);
  if ((iVar2 < iVar4) || ((iVar2 == iVar4 && (*puVar7 <= uVar3)))) {
    FUN_40bfc2a4(*(int *)(param_1 + 0x58),puVar1,*puVar7,iVar2,uVar3,iVar4);
    if ((*(char *)(param_1 + 0x78) != '\0') || ((param_3 & 4) != 0)) {
      FUN_40bfc6e8(*(int *)(param_1 + 0x58),puVar7);
    }
  }
  else {
    *puVar7 = uVar3;
    *(int *)(param_1 + 0xac) = iVar4;
  }
  *param_2 = *puVar7;
  param_2[1] = *(uint *)(param_1 + 0xac);
  FUN_40bf7f50(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7c));
  return 0;
}



/* 40bfcc30 FUN_40bfcc30 */

/* Boundary evidence: original MIPS .pdata 40bfcc30..40bfcc5f. Semantic name remains unreviewed. */

void FUN_40bfcc30(void)

{
  int in_v0;
  
  FUN_40bf42f0((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40bfccd0 FUN_40bfccd0 */

/* Boundary evidence: original MIPS .pdata 40bfccd0..40bfcd3f. Semantic name remains unreviewed. */

undefined4 FUN_40bfccd0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    param_2[1] = 0;
  }
  if (param_3 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(iVar1 + 0x40);
    EnterCriticalSection(lpCriticalSection);
    *param_3 = *(undefined4 *)(iVar1 + 0xa0);
    param_3[1] = *(undefined4 *)(iVar1 + 0xa4);
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* 40bfcd40 FUN_40bfcd40 */

/* Boundary evidence: original MIPS .pdata 40bfcd40..40bfcd6b. Semantic name remains unreviewed. */

void FUN_40bfcd40(int param_1,uint *param_2,uint param_3,uint *param_4,uint param_5)

{
  FUN_40bfc974(*(int *)(param_1 + 4),param_2,param_3,param_4,param_5,param_1 + -0xa0);
  return;
}



/* 40bfcd6c FUN_40bfcd6c */

void FUN_40bfcd6c(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}



/* 40bfcd90 FUN_40bfcd90 */

void FUN_40bfcd90(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x1c) = param_2[3];
  return;
}



/* 40bfcdb4 FUN_40bfcdb4 */

void FUN_40bfcdb4(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



/* 40bfcdbc FUN_40bfcdbc */

void FUN_40bfcdbc(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}



/* 40bfcdc4 FUN_40bfcdc4 */

void FUN_40bfcdc4(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = *param_2;
  *(undefined4 *)(param_1 + 0x30) = param_2[1];
  *(undefined4 *)(param_1 + 0x34) = param_2[2];
  *(undefined4 *)(param_1 + 0x38) = param_2[3];
  return;
}



/* 40bfcde8 FUN_40bfcde8 */

/* Boundary evidence: original MIPS .pdata 40bfcde8..40bfce83. Semantic name remains unreviewed. */

LPVOID FUN_40bfcde8(int param_1,uint param_2)

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



/* 40bfce84 FUN_40bfce84 */

/* Boundary evidence: original MIPS .pdata 40bfce84..40bfcebf. Semantic name remains unreviewed. */

void FUN_40bfce84(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40bfcec0 FUN_40bfcec0 */

/* Boundary evidence: original MIPS .pdata 40bfcec0..40bfcf53. Semantic name remains unreviewed. */

void FUN_40bfcec0(void *param_1,void *param_2)

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



/* 40bfcf54 FUN_40bfcf54 */

/* Boundary evidence: original MIPS .pdata 40bfcf54..40bfcfb7. Semantic name remains unreviewed. */

void FUN_40bfcf54(int param_1)

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



/* 40bfcfb8 FUN_40bfcfb8 */

/* Boundary evidence: original MIPS .pdata 40bfcfb8..40bfcfd3. Semantic name remains unreviewed. */

void FUN_40bfcfb8(int param_1)

{
  FUN_40bfcf54(param_1);
  return;
}



/* 40bfcfd4 FUN_40bfcfd4 */

/* Boundary evidence: original MIPS .pdata 40bfcfd4..40bfd013. Semantic name remains unreviewed. */

void * FUN_40bfcfd4(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40bfd014 FUN_40bfd014 */

/* Boundary evidence: original MIPS .pdata 40bfd014..40bfd05f. Semantic name remains unreviewed. */

void * FUN_40bfd014(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40bfcf54((int)param_1);
    FUN_40bfcec0(param_1,param_2);
  }
  return param_1;
}



/* 40bfd060 FUN_40bfd060 */

/* Boundary evidence: original MIPS .pdata 40bfd060..40bfd08b. Semantic name remains unreviewed. */

void * FUN_40bfd060(void *param_1,void *param_2)

{
  FUN_40bfd014(param_1,param_2);
  return param_1;
}



/* 40bfd08c FUN_40bfd08c */

/* Boundary evidence: original MIPS .pdata 40bfd08c..40bfd137. Semantic name remains unreviewed. */

undefined4 FUN_40bfd08c(void *param_1,void *param_2)

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



/* 40bfd138 FUN_40bfd138 */

/* Boundary evidence: original MIPS .pdata 40bfd138..40bfd167. Semantic name remains unreviewed. */

bool FUN_40bfd138(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40bfd08c(param_1,param_2);
  return iVar1 == 0;
}



/* 40bfd168 FUN_40bfd168 */

/* Boundary evidence: original MIPS .pdata 40bfd168..40bfd1d3. Semantic name remains unreviewed. */

undefined4 FUN_40bfd168(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40c06f08,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40c06f08,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bfd1d4 FUN_40bfd1d4 */

/* Boundary evidence: original MIPS .pdata 40bfd1d4..40bfd2e7. Semantic name remains unreviewed. */

undefined4 FUN_40bfd1d4(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40c06f08,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40c06f08,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40c06f08,0x10);
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



/* 40bfd2e8 FUN_40bfd2e8 */

/* Boundary evidence: original MIPS .pdata 40bfd2e8..40bfd327. Semantic name remains unreviewed. */

void FUN_40bfd2e8(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40bfcf54((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40bfd328 FUN_40bfd328 */

/* Boundary evidence: original MIPS .pdata 40bfd328..40bfd5e7. Semantic name remains unreviewed. */

void FUN_40bfd328(undefined4 param_1,int param_2)

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
  
  if (DAT_40c08164 == 0xffffffff) {
    DAT_40c08168 = 0xfa;
    DAT_40c08164 = 0xf9;
    DAT_40c0816c = 0xfb;
    DAT_40c08170 = 0xfc;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,0,
                          &local_30);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Highest",(LPDWORD)0x0,&local_34,(LPBYTE)&local_28,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_28)) {
        local_28 = DAT_40c08164;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"AboveNormal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_2c,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_2c)) {
        local_2c = DAT_40c08168;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Normal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_24,&local_38
                              );
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_24)) {
        local_24 = DAT_40c0816c;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"BelowNormal",(LPDWORD)0x0,&local_34,(LPBYTE)local_20,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_20[0])) {
        local_20[0] = DAT_40c08170;
      }
      if (((local_28 <= local_2c) && (local_2c <= local_24)) && (local_24 <= local_20[0])) {
        DAT_40c08164 = local_28;
        DAT_40c08168 = local_2c;
        DAT_40c0816c = local_24;
        DAT_40c08170 = local_20[0];
      }
      RegCloseKey(local_30);
    }
  }
  uVar2 = DAT_40c08164;
  if (((param_2 != 1) && (uVar2 = DAT_40c08168, param_2 != 2)) &&
     (uVar2 = DAT_40c08170, param_2 != 4)) {
    uVar2 = DAT_40c0816c;
  }
  CeSetThreadPriority(param_1,uVar2);
  return;
}



/* 40bfd5e8 FUN_40bfd5e8 */

/* Boundary evidence: original MIPS .pdata 40bfd5e8..40bfd627. Semantic name remains unreviewed. */

undefined4 * FUN_40bfd5e8(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



/* 40bfd628 FUN_40bfd628 */

/* Boundary evidence: original MIPS .pdata 40bfd628..40bfd657. Semantic name remains unreviewed. */

void FUN_40bfd628(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40bfd658 FUN_40bfd658 */

/* Boundary evidence: original MIPS .pdata 40bfd658..40bfd67b. Semantic name remains unreviewed. */

void FUN_40bfd658(undefined4 *param_1)

{
  (**(code **)*param_1)();
  return;
}



/* 40bfd67c FUN_40bfd67c */

short * FUN_40bfd67c(short *param_1,short *param_2,int param_3)

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



/* 40bfd6b8 FUN_40bfd6b8 */

/* Boundary evidence: original MIPS .pdata 40bfd6b8..40bfd743. Semantic name remains unreviewed. */

undefined4 FUN_40bfd6b8(wchar_t *param_1,undefined4 *param_2)

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



/* 40bfd744 FUN_40bfd744 */

/* Boundary evidence: original MIPS .pdata 40bfd744..40bfd7bf. Semantic name remains unreviewed. */

int FUN_40bfd744(int param_1)

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



/* 40bfd7c0 FUN_40bfd7c0 */

/* Boundary evidence: original MIPS .pdata 40bfd7c0..40bfd82f. Semantic name remains unreviewed. */

void FUN_40bfd7c0(int param_1)

{
  FUN_40bf4844(param_1);
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



/* 40bfd830 FUN_40bfd830 */

/* Boundary evidence: original MIPS .pdata 40bfd830..40bfd8e3. Semantic name remains unreviewed. */

bool FUN_40bfd830(LPVOID param_1)

{
  HANDLE pvVar1;
  bool bVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD aDStack_18 [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x18);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)param_1 + 0x14) == 0) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40bfd658,param_1,0,aDStack_18);
    if (pvVar1 != (HANDLE)0x0) {
      FUN_40bfd328(pvVar1,3);
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



/* 40bfd8e4 FUN_40bfd8e4 */

/* Boundary evidence: original MIPS .pdata 40bfd8e4..40bfd96f. Semantic name remains unreviewed. */

undefined4 FUN_40bfd8e4(int param_1,undefined4 param_2)

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



/* 40bfd970 FUN_40bfd970 */

/* Boundary evidence: original MIPS .pdata 40bfd970..40bfd9a7. Semantic name remains unreviewed. */

undefined4 FUN_40bfd970(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
  return *(undefined4 *)(param_1 + 0xc);
}



/* 40bfd9a8 FUN_40bfd9a8 */

/* Boundary evidence: original MIPS .pdata 40bfd9a8..40bfda0b. Semantic name remains unreviewed. */

undefined4 FUN_40bfd9a8(int param_1,undefined4 *param_2)

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



/* 40bfda0c FUN_40bfda0c */

/* Boundary evidence: original MIPS .pdata 40bfda0c..40bfda47. Semantic name remains unreviewed. */

void FUN_40bfda0c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  EventModify(*(undefined4 *)(param_1 + 4),2);
  EventModify(*(undefined4 *)(param_1 + 8),3);
  return;
}



/* 40bfdab0 FUN_40bfdab0 */

/* Boundary evidence: original MIPS .pdata 40bfdab0..40bfdb3b. Semantic name remains unreviewed. */

undefined4 FUN_40bfdab0(int param_1,short *param_2)

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
      FUN_40bfd67c(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40bfdb44 FUN_40bfdb44 */

/* Boundary evidence: original MIPS .pdata 40bfdb44..40bfdb8f. Semantic name remains unreviewed. */

void FUN_40bfdb44(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40c06ccc;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40c01e30(param_1 + 6);
  return;
}



/* 40bfdb90 FUN_40bfdb90 */

/* Boundary evidence: original MIPS .pdata 40bfdb90..40bfdc27. Semantic name remains unreviewed. */

undefined4 FUN_40bfdb90(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40c066d0,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40c06f18,0x10), iVar2 == 0)) {
      uVar1 = FUN_40c00ca4(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40bfdc28 FUN_40bfdc28 */

/* Boundary evidence: original MIPS .pdata 40bfdc28..40bfdc43. Semantic name remains unreviewed. */

void FUN_40bfdc28(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40bfdc44 FUN_40bfdc44 */

/* Boundary evidence: original MIPS .pdata 40bfdc44..40bfdc9f. Semantic name remains unreviewed. */

LONG FUN_40bfdc44(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40bfdca0 FUN_40bfdca0 */

/* Boundary evidence: original MIPS .pdata 40bfdca0..40bfdcff. Semantic name remains unreviewed. */

undefined4 FUN_40bfdca0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40c01c9c((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40bfdd00 FUN_40bfdd00 */

/* Boundary evidence: original MIPS .pdata 40bfdd00..40bfdd57. Semantic name remains unreviewed. */

undefined4 FUN_40bfdd00(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40bfdd58 FUN_40bfdd58 */

/* Boundary evidence: original MIPS .pdata 40bfdd58..40bfddef. Semantic name remains unreviewed. */

undefined4 FUN_40bfdd58(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40c066e0,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40c06f18,0x10), iVar2 == 0)) {
      uVar1 = FUN_40c00ca4(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40bfddf0 FUN_40bfddf0 */

/* Boundary evidence: original MIPS .pdata 40bfddf0..40bfde0b. Semantic name remains unreviewed. */

void FUN_40bfddf0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40bfde0c FUN_40bfde0c */

/* Boundary evidence: original MIPS .pdata 40bfde0c..40bfde67. Semantic name remains unreviewed. */

LONG FUN_40bfde0c(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40bfde68 FUN_40bfde68 */

/* Boundary evidence: original MIPS .pdata 40bfde68..40bfdea7. Semantic name remains unreviewed. */

undefined4 FUN_40bfde68(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40bfdea8 FUN_40bfdea8 */

/* Boundary evidence: original MIPS .pdata 40bfdea8..40bfdeeb. Semantic name remains unreviewed. */

void FUN_40bfdea8(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40bfcfb8(param_1 + 0x1c);
  FUN_40c00c4c();
  return;
}



/* 40bfdeec FUN_40bfdeec */

/* Boundary evidence: original MIPS .pdata 40bfdeec..40bfdf93. Semantic name remains unreviewed. */

void FUN_40bfdeec(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c066c0,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40c06800,0x10);
    if (iVar1 != 0) {
      FUN_40c00d40(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40c00ca4(piVar2,param_3);
  return;
}



/* 40bfdf94 FUN_40bfdf94 */

/* Boundary evidence: original MIPS .pdata 40bfdf94..40bfdfbf. Semantic name remains unreviewed. */

void FUN_40bfdf94(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40bfdfc0 FUN_40bfdfc0 */

/* Boundary evidence: original MIPS .pdata 40bfdfc0..40bfdfeb. Semantic name remains unreviewed. */

void FUN_40bfdfc0(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40bfdfec FUN_40bfdfec */

/* Boundary evidence: original MIPS .pdata 40bfdfec..40bfe00b. Semantic name remains unreviewed. */

undefined4 FUN_40bfdfec(int param_1,void *param_2)

{
  FUN_40bfd060((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40bfe00c FUN_40bfe00c */

/* Boundary evidence: original MIPS .pdata 40bfe00c..40bfe063. Semantic name remains unreviewed. */

undefined4 FUN_40bfe00c(int param_1,int *param_2)

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



/* 40bfe064 FUN_40bfe064 */

/* Boundary evidence: original MIPS .pdata 40bfe064..40bfe0b7. Semantic name remains unreviewed. */

undefined4 FUN_40bfe064(int param_1,int *param_2)

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



/* 40bfe0b8 FUN_40bfe0b8 */

/* Boundary evidence: original MIPS .pdata 40bfe0b8..40bfe163. Semantic name remains unreviewed. */

undefined4 FUN_40bfe0b8(int param_1,int *param_2)

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
      FUN_40bfd67c((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40bfe18c FUN_40bfe18c */

/* Boundary evidence: original MIPS .pdata 40bfe18c..40bfe1d3. Semantic name remains unreviewed. */

int FUN_40bfe18c(int param_1,int param_2)

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



/* 40bfe1e8 FUN_40bfe1e8 */

undefined4 FUN_40bfe1e8(void)

{
  return 0;
}



/* 40bfe1f0 FUN_40bfe1f0 */

undefined4 FUN_40bfe1f0(int param_1)

{
  *(undefined4 *)(param_1 + 0x6c) = 0;
  return 0;
}



/* 40bfe204 FUN_40bfe204 */

/* Boundary evidence: original MIPS .pdata 40bfe204..40bfe253. Semantic name remains unreviewed. */

undefined4 FUN_40bfe204(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40bfe284 FUN_40bfe284 */

/* Boundary evidence: original MIPS .pdata 40bfe284..40bfe2ab. Semantic name remains unreviewed. */

void FUN_40bfe284(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40bfe2ac FUN_40bfe2ac */

/* Boundary evidence: original MIPS .pdata 40bfe2ac..40bfe313. Semantic name remains unreviewed. */

int FUN_40bfe2ac(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40bfe00c(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40c06790,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40bfe314 FUN_40bfe314 */

/* Boundary evidence: original MIPS .pdata 40bfe314..40bfe377. Semantic name remains unreviewed. */

undefined4 FUN_40bfe314(int param_1)

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



/* 40bfe378 FUN_40bfe378 */

/* Boundary evidence: original MIPS .pdata 40bfe378..40bfe3b3. Semantic name remains unreviewed. */

void FUN_40bfe378(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40c05504,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c06770,param_2);
  return;
}



/* 40bfe3b4 FUN_40bfe3b4 */

/* Boundary evidence: original MIPS .pdata 40bfe3b4..40bfe53f. Semantic name remains unreviewed. */

int FUN_40bfe3b4(int *param_1,int *param_2,int *param_3)

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



/* 40bfe540 FUN_40bfe540 */

/* Boundary evidence: original MIPS .pdata 40bfe540..40bfe587. Semantic name remains unreviewed. */

undefined4 FUN_40bfe540(int param_1)

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



/* 40bfe588 FUN_40bfe588 */

/* Boundary evidence: original MIPS .pdata 40bfe588..40bfe5c7. Semantic name remains unreviewed. */

undefined4 FUN_40bfe588(int param_1)

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



/* 40bfe5c8 FUN_40bfe5c8 */

/* Boundary evidence: original MIPS .pdata 40bfe5c8..40bfe607. Semantic name remains unreviewed. */

undefined4 FUN_40bfe5c8(int param_1)

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



/* 40bfe608 FUN_40bfe608 */

/* Boundary evidence: original MIPS .pdata 40bfe608..40bfe647. Semantic name remains unreviewed. */

undefined4 FUN_40bfe608(int param_1)

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



/* 40bfe648 FUN_40bfe648 */

/* Boundary evidence: original MIPS .pdata 40bfe648..40bfe687. Semantic name remains unreviewed. */

undefined4 FUN_40bfe648(int param_1)

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



/* 40bfe688 FUN_40bfe688 */

/* Boundary evidence: original MIPS .pdata 40bfe688..40bfe6d3. Semantic name remains unreviewed. */

bool FUN_40bfe688(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40bfe6d4 FUN_40bfe6d4 */

/* Boundary evidence: original MIPS .pdata 40bfe6d4..40bfe71f. Semantic name remains unreviewed. */

bool FUN_40bfe6d4(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40bfe720 FUN_40bfe720 */

/* Boundary evidence: original MIPS .pdata 40bfe720..40bfe75f. Semantic name remains unreviewed. */

undefined4 FUN_40bfe720(int param_1)

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



/* 40bfe760 FUN_40bfe760 */

/* Boundary evidence: original MIPS .pdata 40bfe760..40bfe79f. Semantic name remains unreviewed. */

undefined4 FUN_40bfe760(int param_1)

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



/* 40bfe7a0 FUN_40bfe7a0 */

/* Boundary evidence: original MIPS .pdata 40bfe7a0..40bfe7fb. Semantic name remains unreviewed. */

undefined4 FUN_40bfe7a0(int param_1)

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



/* 40bfe7fc FUN_40bfe7fc */

/* Boundary evidence: original MIPS .pdata 40bfe7fc..40bfe843. Semantic name remains unreviewed. */

void FUN_40bfe7fc(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40bfdea8(param_1);
  return;
}



/* 40bfe844 FUN_40bfe844 */

/* Boundary evidence: original MIPS .pdata 40bfe844..40bfe8c3. Semantic name remains unreviewed. */

void FUN_40bfe844(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c06790,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40c00ca4(piVar2,param_3);
  }
  else {
    FUN_40bfdeec(param_1,param_2,param_3);
  }
  return;
}



/* 40bfe8c4 FUN_40bfe8c4 */

/* Boundary evidence: original MIPS .pdata 40bfe8c4..40bfe98b. Semantic name remains unreviewed. */

HRESULT FUN_40bfe8c4(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40c05504,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c06770,ppv),
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



/* 40bfe98c FUN_40bfe98c */

/* Boundary evidence: original MIPS .pdata 40bfe98c..40bfea2b. Semantic name remains unreviewed. */

undefined4 FUN_40bfe98c(int param_1,int *param_2,undefined1 param_3)

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



/* 40bfea2c FUN_40bfea2c */

/* Boundary evidence: original MIPS .pdata 40bfea2c..40bfecb3. Semantic name remains unreviewed. */

int FUN_40bfea2c(int param_1,int *param_2)

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
      iVar2 = (**(code **)*param_2)(param_2,&UNK_40c06760,local_20);
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



/* 40bfecb4 FUN_40bfecb4 */

/* Boundary evidence: original MIPS .pdata 40bfecb4..40bfed4f. Semantic name remains unreviewed. */

int FUN_40bfecb4(int *param_1,int param_2,int param_3,int *param_4)

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



/* 40bfed50 FUN_40bfed50 */

/* Boundary evidence: original MIPS .pdata 40bfed50..40bfeeaf. Semantic name remains unreviewed. */

int FUN_40bfed50(int param_1)

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
        iVar2 = (**(code **)*local_30)(local_30,&DAT_40c06790,&local_2c);
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



/* 40bfef24 FUN_40bfef24 */

/* Boundary evidence: original MIPS .pdata 40bfef24..40bff17b. Semantic name remains unreviewed. */

int FUN_40bfef24(undefined4 *param_1,int *param_2,int param_3)

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
              if (iVar1 < 0) goto LAB_40bff144;
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
LAB_40bff144:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40bff17c FUN_40bff17c */

/* Boundary evidence: original MIPS .pdata 40bff17c..40bff25b. Semantic name remains unreviewed. */

void FUN_40bff17c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40c06720,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40c06710,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40c06f28,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40c067a0,0x10);
    if (iVar1 != 0) {
      FUN_40c00d40(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40c00ca4(piVar2,param_3);
  return;
}



/* 40bff25c FUN_40bff25c */

/* Boundary evidence: original MIPS .pdata 40bff25c..40bff2b7. Semantic name remains unreviewed. */

void FUN_40bff25c(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40c00c4c();
  return;
}



/* 40bff2b8 FUN_40bff2b8 */

/* Boundary evidence: original MIPS .pdata 40bff2b8..40bff33b. Semantic name remains unreviewed. */

undefined4 FUN_40bff2b8(int param_1,int *param_2)

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



/* 40bff33c FUN_40bff33c */

/* Boundary evidence: original MIPS .pdata 40bff33c..40bff3bf. Semantic name remains unreviewed. */

undefined4 FUN_40bff33c(int param_1,undefined4 *param_2)

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



/* 40bff3c0 FUN_40bff3c0 */

/* Boundary evidence: original MIPS .pdata 40bff3c0..40bff447. Semantic name remains unreviewed. */

int FUN_40bff3c0(int param_1,uint *param_2)

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



/* 40bff448 FUN_40bff448 */

/* Boundary evidence: original MIPS .pdata 40bff448..40bff55f. Semantic name remains unreviewed. */

undefined4 FUN_40bff448(int param_1,LPCWSTR param_2,int *param_3)

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
          goto LAB_40bff508;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40bff508:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40bff560 FUN_40bff560 */

/* Boundary evidence: original MIPS .pdata 40bff560..40bff67b. Semantic name remains unreviewed. */

undefined4 FUN_40bff560(int param_1,undefined4 *param_2,wchar_t *param_3)

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
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40c06830,(undefined4 *)(param_1 + 0x38));
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



/* 40bff67c FUN_40bff67c */

/* Boundary evidence: original MIPS .pdata 40bff67c..40bff74f. Semantic name remains unreviewed. */

undefined4 FUN_40bff67c(int param_1)

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
    HVar3 = CoCreateInstance((IID *)&DAT_40c04fc4,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c067f0,local_10);
    if (-1 < HVar3) {
      FUN_40bfef24(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40bff750 FUN_40bff750 */

/* Boundary evidence: original MIPS .pdata 40bff750..40bff843. Semantic name remains unreviewed. */

int FUN_40bff750(int param_1)

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
    HVar2 = CoCreateInstance((IID *)&DAT_40c04fc4,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c067f0,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40bfef24(puVar1,local_18[0],0);
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



/* 40bff844 FUN_40bff844 */

/* Boundary evidence: original MIPS .pdata 40bff844..40bff88f. Semantic name remains unreviewed. */

undefined4 * FUN_40bff844(undefined4 *param_1,uint param_2)

{
  FUN_40bfdb44(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bff890 FUN_40bff890 */

/* Boundary evidence: original MIPS .pdata 40bff890..40bffa27. Semantic name remains unreviewed. */

undefined4 FUN_40bff890(int param_1,uint param_2,int *param_3,uint *param_4)

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
    bVar1 = FUN_40bfe688(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40bfdd00(param_1);
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
        iVar3 = FUN_40c01cf0((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40c01d34((int *)(param_1 + 0x18),iVar2);
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



/* 40bffa28 FUN_40bffa28 */

/* Boundary evidence: original MIPS .pdata 40bffa28..40bffaa3. Semantic name remains unreviewed. */

undefined4 FUN_40bffa28(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40bfe688(param_1);
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



/* 40bffaa4 FUN_40bffaa4 */

/* Boundary evidence: original MIPS .pdata 40bffaa4..40bffb07. Semantic name remains unreviewed. */

undefined4 * FUN_40bffaa4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40c06cec;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40bffb08 FUN_40bffb08 */

/* Boundary evidence: original MIPS .pdata 40bffb08..40bffc9b. Semantic name remains unreviewed. */

uint FUN_40bffb08(int param_1,uint param_2,undefined4 *param_3,int *param_4)

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
  
  local_28 = DAT_40c08174;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40c0209c(DAT_40c08174);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40bfe6d4(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40c0209c(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40c0209c(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40bfcfd4(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40bffc48:
          FUN_40bfcfb8((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40bffc48;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40bfcfb8((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40c0209c(local_28);
    }
  }
  return uVar3;
}



/* 40bffc9c FUN_40bffc9c */

/* Boundary evidence: original MIPS .pdata 40bffc9c..40bffd53. Semantic name remains unreviewed. */

uint FUN_40bffc9c(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40c08174;
  bVar1 = FUN_40bfe6d4(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40c0209c(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40bfcfd4(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40bfcfb8((int)auStack_60);
    FUN_40c0209c(local_18);
  }
  return uVar3;
}



/* 40bffd54 FUN_40bffd54 */

/* Boundary evidence: original MIPS .pdata 40bffd54..40bffecb. Semantic name remains unreviewed. */

int FUN_40bffd54(int *param_1,int *param_2,undefined4 param_3)

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



/* 40bffecc FUN_40bffecc */

/* Boundary evidence: original MIPS .pdata 40bffecc..40c0003f. Semantic name remains unreviewed. */

int FUN_40bffecc(int *param_1,int *param_2,void *param_3,int *param_4)

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
             (iVar3 = FUN_40bfd1d4(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40bffd54(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40bfd2e8(local_28);
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



/* 40c00040 FUN_40c00040 */

/* Boundary evidence: original MIPS .pdata 40c00040..40c001c7. Semantic name remains unreviewed. */

int FUN_40c00040(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40bfd168(param_3), iVar1 == 0)) {
    iVar1 = FUN_40bffd54(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40bffecc(param_1,param_2,param_3,local_30[0]);
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
  iVar2 = FUN_40bffecc(param_1,param_2,param_3,local_30[0]);
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



/* 40c001c8 FUN_40c001c8 */

/* Boundary evidence: original MIPS .pdata 40c001c8..40c0038f. Semantic name remains unreviewed. */

int FUN_40c001c8(int param_1,int *param_2,int param_3)

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
          goto LAB_40c00360;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40c00360;
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
LAB_40c00360:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40c00390 FUN_40c00390 */

/* Boundary evidence: original MIPS .pdata 40c00390..40c0042f. Semantic name remains unreviewed. */

undefined4 FUN_40c00390(int param_1)

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



/* 40c00430 FUN_40c00430 */

/* Boundary evidence: original MIPS .pdata 40c00430..40c004bb. Semantic name remains unreviewed. */

undefined4 FUN_40c00430(int param_1,void *param_2)

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
      FUN_40bfce84(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40bfcec0(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40c004bc FUN_40c004bc */

/* Boundary evidence: original MIPS .pdata 40c004bc..40c004d7. Semantic name remains unreviewed. */

void FUN_40c004bc(int param_1,undefined4 *param_2)

{
  FUN_40bfd6b8(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40c004d8 FUN_40c004d8 */

/* Boundary evidence: original MIPS .pdata 40c004d8..40c00553. Semantic name remains unreviewed. */

int FUN_40c004d8(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40c00390(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40c00554 FUN_40c00554 */

/* Boundary evidence: original MIPS .pdata 40c00554..40c00633. Semantic name remains unreviewed. */

undefined4 * FUN_40c00554(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40c06ccc;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40c01c78(param_1 + 6);
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
    FUN_40c01dd0(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40c00634 FUN_40c00634 */

/* Boundary evidence: original MIPS .pdata 40c00634..40c006df. Semantic name remains unreviewed. */

undefined4 FUN_40c00634(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40bfe688(param_1);
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
        puVar2 = FUN_40c00554(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40c006e0 FUN_40c006e0 */

/* Boundary evidence: original MIPS .pdata 40c006e0..40c0076f. Semantic name remains unreviewed. */

undefined4 * FUN_40c006e0(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40c06cec;
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



/* 40c00770 FUN_40c00770 */

/* Boundary evidence: original MIPS .pdata 40c00770..40c0081b. Semantic name remains unreviewed. */

undefined4 FUN_40c00770(int param_1,undefined4 *param_2)

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
    bVar1 = FUN_40bfe6d4(param_1);
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
        puVar2 = FUN_40c006e0(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40c0081c FUN_40c0081c */

/* Boundary evidence: original MIPS .pdata 40c0081c..40c0090f. Semantic name remains unreviewed. */

undefined4 *
FUN_40c0081c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40c00ce4(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40bfcfd4(param_1 + 7);
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



/* 40c00910 FUN_40c00910 */

/* Boundary evidence: original MIPS .pdata 40c00910..40c009ef. Semantic name remains unreviewed. */

int FUN_40c00910(int param_1,int *param_2,void *param_3)

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
        iVar1 = FUN_40c00040(piVar2,param_2,param_3);
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



/* 40c009f0 FUN_40c009f0 */

/* Boundary evidence: original MIPS .pdata 40c009f0..40c00a6f. Semantic name remains unreviewed. */

undefined4 FUN_40c009f0(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40c006e0(puVar2,param_1 + -0xc,0);
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



/* 40c00a70 FUN_40c00a70 */

/* Boundary evidence: original MIPS .pdata 40c00a70..40c00abb. Semantic name remains unreviewed. */

undefined4 *
FUN_40c00a70(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40c0081c(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40c00abc FUN_40c00abc */

/* Boundary evidence: original MIPS .pdata 40c00abc..40c00b17. Semantic name remains unreviewed. */

undefined4 *
FUN_40c00abc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40c0081c(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40c00b18 FUN_40c00b18 */

/* Boundary evidence: original MIPS .pdata 40c00b18..40c00b9b. Semantic name remains unreviewed. */

undefined4 *
FUN_40c00b18(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40c00ce4(param_1,param_2,param_3);
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



/* 40c00b9c FUN_40c00b9c */

/* Boundary evidence: original MIPS .pdata 40c00b9c..40c00c1b. Semantic name remains unreviewed. */

undefined4 FUN_40c00b9c(int param_1,undefined4 *param_2)

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
      puVar2 = FUN_40c00554(puVar2,param_1 + -0xc,0);
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



/* 40c00c1c FUN_40c00c1c */

/* Boundary evidence: original MIPS .pdata 40c00c1c..40c00c4b. Semantic name remains unreviewed. */

undefined4 FUN_40c00c1c(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40c08190);
  return param_1;
}



/* 40c00c4c FUN_40c00c4c */

/* Boundary evidence: original MIPS .pdata 40c00c4c..40c00ca3. Semantic name remains unreviewed. */

void FUN_40c00c4c(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40c08190);
  if ((LVar1 == 0) && (DAT_40c0818c != 0)) {
    FreeLibrary((HMODULE)DAT_40c0818c);
    DAT_40c0818c = 0;
  }
  return;
}



/* 40c00ca4 FUN_40c00ca4 */

/* Boundary evidence: original MIPS .pdata 40c00ca4..40c00ce3. Semantic name remains unreviewed. */

undefined4 FUN_40c00ca4(int *param_1,undefined4 *param_2)

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



/* 40c00ce4 FUN_40c00ce4 */

/* Boundary evidence: original MIPS .pdata 40c00ce4..40c00d3f. Semantic name remains unreviewed. */

undefined4 * FUN_40c00ce4(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40c06d28;
  InterlockedIncrement(&DAT_40c08190);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40c00d40 FUN_40c00d40 */

/* Boundary evidence: original MIPS .pdata 40c00d40..40c00dc3. Semantic name remains unreviewed. */

undefined4 FUN_40c00d40(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40c06f18,0x10);
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



/* 40c00dc4 FUN_40c00dc4 */

/* Boundary evidence: original MIPS .pdata 40c00dc4..40c00dff. Semantic name remains unreviewed. */

uint FUN_40c00dc4(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40c00e00 FUN_40c00e00 */

/* Boundary evidence: original MIPS .pdata 40c00e00..40c00e77. Semantic name remains unreviewed. */

uint FUN_40c00e00(int *param_1)

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



/* 40c00e78 FUN_40c00e78 */

/* Boundary evidence: original MIPS .pdata 40c00e78..40c00fc3. Semantic name remains unreviewed. */

undefined4 FUN_40c00e78(HKEY param_1,wchar_t *param_2)

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
  
  local_20 = DAT_40c08174;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40c0209c(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40c00e78(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40c0209c(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40c00fc4 FUN_40c00fc4 */

/* Boundary evidence: original MIPS .pdata 40c00fc4..40c01253. Semantic name remains unreviewed. */

uint FUN_40c00fc4(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  
  local_30 = DAT_40c08174;
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
  FUN_40c0209c(local_30);
  return uVar1;
}



/* 40c01254 FUN_40c01254 */

/* Boundary evidence: original MIPS .pdata 40c01254..40c012c7. Semantic name remains unreviewed. */

undefined4 FUN_40c01254(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40c08174;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40c00e78((HKEY)0x80000000,aWStack_218);
  FUN_40c0209c(local_10);
  return 0;
}



/* 40c012c8 FUN_40c012c8 */

/* Boundary evidence: original MIPS .pdata 40c012c8..40c014ff. Semantic name remains unreviewed. */

DWORD FUN_40c012c8(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40c08174;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40c082ac,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40c08160) {
      ppuVar5 = &PTR_DAT_40c0814c;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40c00fc4(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40c067a0,local_240
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
      } while (iVar4 < DAT_40c08160);
    }
  }
  FUN_40c0209c(local_30);
  return DVar3;
}



/* 40c01500 FUN_40c01500 */

/* Boundary evidence: original MIPS .pdata 40c01500..40c01687. Semantic name remains unreviewed. */

int FUN_40c01500(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40c08160 != 0) {
    iVar3 = DAT_40c08160;
    ppuVar4 = &PTR_DAT_40c08150 + DAT_40c08160 * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40c067a0,local_30);
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
      HVar2 = FUN_40c01254(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
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



/* 40c01688 FUN_40c01688 */

/* Boundary evidence: original MIPS .pdata 40c01688..40c016bb. Semantic name remains unreviewed. */

void FUN_40c01688(int param_1)

{
  if (param_1 == 0) {
    FUN_40c01500();
  }
  else {
    FUN_40c012c8();
  }
  return;
}



/* 40c01700 FUN_40c01700 */

/* Boundary evidence: original MIPS .pdata 40c01700..40c0177f. Semantic name remains unreviewed. */

void FUN_40c01700(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40c08160) {
    ppuVar2 = &PTR_DAT_40c08150;
    iVar1 = DAT_40c08160;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40c08160;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40c01780 FUN_40c01780 */

/* Boundary evidence: original MIPS .pdata 40c01780..40c0181f. Semantic name remains unreviewed. */

undefined4 FUN_40c01780(HMODULE param_1,int param_2)

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
    DAT_40c082a8 = 1;
    DAT_40c08194 = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40c08194);
    if (BVar1 != 0) {
      DAT_40c082a8 = DAT_40c081a4;
    }
    uVar2 = 1;
    DAT_40c082ac = param_1;
  }
  FUN_40c01700(uVar2);
  return 1;
}



/* 40c01820 FUN_40c01820 */

undefined4 FUN_40c01820(int param_1,int *param_2)

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



/* 40c01870 FUN_40c01870 */

/* Boundary evidence: original MIPS .pdata 40c01870..40c0191b. Semantic name remains unreviewed. */

undefined4 FUN_40c01870(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40c06f18,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40c06f38,0x10), iVar2 == 0)) {
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



/* 40c0191c FUN_40c0191c */

/* Boundary evidence: original MIPS .pdata 40c0191c..40c01973. Semantic name remains unreviewed. */

void * FUN_40c0191c(void *param_1,uint param_2)

{
  FUN_40c00c4c();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40c01974 FUN_40c01974 */

/* Boundary evidence: original MIPS .pdata 40c01974..40c01a97. Semantic name remains unreviewed. */

int FUN_40c01974(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40c06f18,0x10), iVar1 == 0)) {
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



/* 40c01a98 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x11a98  1  DllCanUnloadNow */
  if ((0 < DAT_40c082b0) || (HVar1 = 0, DAT_40c08190 != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40c01ac4 FUN_40c01ac4 */

/* Boundary evidence: original MIPS .pdata 40c01ac4..40c01b1f. Semantic name remains unreviewed. */

undefined4 * FUN_40c01ac4(undefined4 *param_1,undefined4 param_2)

{
  FUN_40c00c1c(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40c06da0;
  param_1[2] = 0;
  return param_1;
}



/* 40c01b20 FUN_40c01b20 */

/* Boundary evidence: original MIPS .pdata 40c01b20..40c01b4f. Semantic name remains unreviewed. */

int FUN_40c01b20(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40c0191c(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40c01b50 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40c01b50..40c01c77. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0x11b50  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40c06f18,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40c06f38,0x10), iVar1 == 0)) {
    iVar1 = DAT_40c08160;
    iVar7 = 0;
    if (0 < DAT_40c08160) {
      ppuVar6 = &PTR_DAT_40c0814c;
      do {
        iVar3 = FUN_40c01820((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40c01ac4(puVar4,ppuVar6);
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



/* 40c01c78 FUN_40c01c78 */

undefined4 * FUN_40c01c78(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40c01c9c FUN_40c01c9c */

/* Boundary evidence: original MIPS .pdata 40c01c9c..40c01cef. Semantic name remains unreviewed. */

void FUN_40c01c9c(undefined4 *param_1)

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



/* 40c01cf0 FUN_40c01cf0 */

int FUN_40c01cf0(int *param_1,int param_2)

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



/* 40c01d34 FUN_40c01d34 */

/* Boundary evidence: original MIPS .pdata 40c01d34..40c01dcf. Semantic name remains unreviewed. */

undefined4 * FUN_40c01d34(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40c01d84;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40c01d84:
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



/* 40c01dd0 FUN_40c01dd0 */

/* Boundary evidence: original MIPS .pdata 40c01dd0..40c01e2f. Semantic name remains unreviewed. */

undefined4 FUN_40c01dd0(undefined4 *param_1,int *param_2)

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
    puVar1 = FUN_40c01d34(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40c01e30 FUN_40c01e30 */

/* Boundary evidence: original MIPS .pdata 40c01e30..40c01e77. Semantic name remains unreviewed. */

void FUN_40c01e30(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40c01c9c(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40c01f88 FUN_40c01f88 */

/* Boundary evidence: original MIPS .pdata 40c01f88..40c01ffb. Semantic name remains unreviewed. */

void FUN_40c01f88(void)

{
  uint uVar1;
  
  if ((DAT_40c08174 == 0) || (DAT_40c08174 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40c08174 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40c08174 == 0) {
      DAT_40c08174 = 0xb064;
    }
  }
  DAT_40c08178 = ~DAT_40c08174;
  return;
}



/* 40c01ffc FUN_40c01ffc */

/* Boundary evidence: original MIPS .pdata 40c01ffc..40c0204f. Semantic name remains unreviewed. */

void FUN_40c01ffc(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40c0209c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40c02050 FUN_40c02050 */

/* Boundary evidence: original MIPS .pdata 40c02050..40c0207b. Semantic name remains unreviewed. */

undefined4 FUN_40c02050(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40c01ffc(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40c0209c FUN_40c0209c */

/* Boundary evidence: original MIPS .pdata 40c0209c..40c020e3. Semantic name remains unreviewed. */

void FUN_40c0209c(uint param_1)

{
  if ((param_1 == DAT_40c08174) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40c02194 FUN_40c02194 */

/* Boundary evidence: original MIPS .pdata 40c02194..40c02203. Semantic name remains unreviewed. */

void FUN_40c02194(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40c01ffc(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 40c022a4 FUN_40c022a4 */

/* Boundary evidence: original MIPS .pdata 40c022a4..40c023df. Semantic name remains unreviewed. */

int FUN_40c022a4(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40c082c4 != (code *)0x0) {
      iVar2 = (*DAT_40c082c4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40c02354;
    FUN_40c02618();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40bfb86c(param_1,param_2);
  }
LAB_40c02354:
  if (((param_2 == 0) && (FUN_40c025a0(), iVar1 != 0)) && (DAT_40c082c4 != (code *)0x0)) {
    iVar1 = (*DAT_40c082c4)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40c023e0 FUN_40c023e0 */

/* Boundary evidence: original MIPS .pdata 40c023e0..40c0240b. Semantic name remains unreviewed. */

void FUN_40c023e0(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40c0240c entry */

/* Boundary evidence: original MIPS .pdata 40c0240c..40c02463. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40c01f88();
  }
  FUN_40c022a4(param_1,param_2,param_3);
  return;
}



/* 40c024b4 FUN_40c024b4 */

/* Boundary evidence: original MIPS .pdata 40c024b4..40c0259f. Semantic name remains unreviewed. */

void FUN_40c024b4(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40c082b8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40c082c0;
    if (DAT_40c082c0 != (undefined4 *)0x0) {
      while (DAT_40c082bc = DAT_40c082bc + -1, _Memory <= DAT_40c082bc) {
        if ((code *)*DAT_40c082bc != (code *)0x0) {
          (*(code *)*DAT_40c082bc)();
          _Memory = DAT_40c082c0;
        }
      }
      free(_Memory);
      DAT_40c082bc = (undefined4 *)0x0;
      DAT_40c082c0 = (undefined4 *)0x0;
    }
    FUN_40c025c4((undefined4 *)&DAT_40c03010,(undefined4 *)&DAT_40c03014);
  }
  FUN_40c025c4((undefined4 *)&DAT_40c03018,(undefined4 *)&DAT_40c0301c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40c025a0 FUN_40c025a0 */

/* Boundary evidence: original MIPS .pdata 40c025a0..40c025c3. Semantic name remains unreviewed. */

void FUN_40c025a0(void)

{
  FUN_40c024b4(0,0,1);
  return;
}



/* 40c025c4 FUN_40c025c4 */

/* Boundary evidence: original MIPS .pdata 40c025c4..40c02617. Semantic name remains unreviewed. */

void FUN_40c025c4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40c02618 FUN_40c02618 */

/* Boundary evidence: original MIPS .pdata 40c02618..40c02653. Semantic name remains unreviewed. */

void FUN_40c02618(void)

{
  FUN_40c025c4((undefined4 *)&DAT_40c03008,(undefined4 *)&DAT_40c0300c);
  FUN_40c025c4((undefined4 *)&DAT_40c03000,(undefined4 *)&DAT_40c03004);
  return;
}


