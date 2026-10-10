/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40761188 FUN_40761188 */

/* Boundary evidence: original MIPS .pdata 40761188..407612eb. Semantic name remains unreviewed. */

undefined4 FUN_40761188(void)

{
  LSTATUS LVar1;
  int iVar2;
  DWORD dwIndex;
  DWORD local_430;
  HKEY local_42c;
  DWORD local_428;
  undefined4 uStack_424;
  WCHAR aWStack_420 [256];
  wchar_t local_220 [256];
  uint local_20;
  
  local_20 = DAT_40766090;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers32",0,0x20019,&local_42c);
  if (LVar1 == 0) {
    dwIndex = 0;
    while( true ) {
      local_430 = 0x100;
      local_428 = 0x100;
      LVar1 = RegEnumValueW(local_42c,dwIndex,aWStack_420,&local_430,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPBYTE)local_220,&local_428);
      if (LVar1 != 0) break;
      CharLowerBuffW(aWStack_420,local_430);
      iVar2 = memcmp(aWStack_420,L"msacm.",0xc);
      if ((iVar2 == 0) && (local_220[0] != L'*')) {
        FUN_40764cd4(&uStack_424,0,local_220,0,9,aWStack_420);
      }
      dwIndex = dwIndex + 1;
    }
    LVar1 = RegCloseKey(local_42c);
    if (LVar1 == 0) {
      FUN_407655d0(local_20);
      return 0;
    }
  }
  FUN_407655d0(local_20);
  return 1;
}



/* 407612ec FUN_407612ec */

/* Boundary evidence: original MIPS .pdata 407612ec..40761343. Semantic name remains unreviewed. */

undefined4 FUN_407612ec(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (DAT_407660a0 == 0) {
    uVar2 = 0;
  }
  else {
    puVar1 = *(undefined4 **)(DAT_407660a0 + 0x20);
    while (puVar1 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)puVar1[4];
      FUN_40764ba8(puVar1);
      puVar1 = puVar3;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 40761344 FUN_40761344 */

/* Boundary evidence: original MIPS .pdata 40761344..4076139b. Semantic name remains unreviewed. */

undefined4 FUN_40761344(void)

{
  if (DAT_407660a8 == 1) {
    FUN_407612ec();
    FUN_40765098((LPCRITICAL_SECTION)&DAT_407660c0);
    if (DAT_407660a0 != (HLOCAL)0x0) {
      LocalFree(DAT_407660a0);
    }
  }
  return 1;
}



/* 4076139c acmInitialize */

/* Boundary evidence: original MIPS .pdata 4076139c..40761423. Semantic name remains unreviewed. */

undefined4 acmInitialize(void)

{
                    /* 0x139c  7  acmInitialize */
  if (DAT_407660a8 != 1) {
    DAT_407660a0 = LocalAlloc(0x40,0x80);
    *(undefined4 *)((int)DAT_407660a0 + 8) = 1;
    *(undefined4 *)((int)DAT_407660a0 + 0x1c) = DAT_407660a4;
    *(undefined4 *)((int)DAT_407660a0 + 0xc) = 0;
    FUN_40765078((LPCRITICAL_SECTION)&DAT_407660c0);
    FUN_40761188();
    DAT_407660a8 = 1;
  }
  return 1;
}



/* 40761424 FUN_40761424 */

/* Boundary evidence: original MIPS .pdata 40761424..40761483. Semantic name remains unreviewed. */

void FUN_40761424(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_40761344();
  }
  else if (param_2 == 1) {
    DAT_407660a4 = param_1;
    DisableThreadLibraryCalls(param_1);
    acmInitialize();
  }
  return;
}



/* 40761484 acmDriverDetails */

/* Boundary evidence: original MIPS .pdata 40761484..4076158b. Semantic name remains unreviewed. */

undefined4 acmDriverDetails(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint *lp;
  BOOL BVar3;
  undefined4 uVar4;
  
                    /* 0x1484  1  acmDriverDetails */
  iVar1 = FUN_40765180(param_1,0);
  if (iVar1 != 0) {
    if (*param_1 == 2) {
      param_1 = (uint *)param_1[3];
    }
    iVar1 = FUN_40765180(param_1,1);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)MapCallerPtr(param_2,4);
      if ((((param_2 != 0) && (puVar2 != (undefined4 *)0x0)) &&
          (lp = (uint *)MapCallerPtr(param_2,*puVar2), lp != (uint *)0x0)) &&
         ((3 < *lp && (BVar3 = IsBadWritePtr(lp,*lp), BVar3 == 0)))) {
        if (param_3 != 0) {
          return 10;
        }
        uVar4 = FUN_40763d94((int)param_1,lp);
        return uVar4;
      }
      return 0xb;
    }
  }
  return 5;
}



/* 4076158c FUN_4076158c */

/* Boundary evidence: original MIPS .pdata 4076158c..40761627. Semantic name remains unreviewed. */

int FUN_4076158c(undefined4 *param_1,uint *param_2,int param_3)

{
  BOOL BVar1;
  int iVar2;
  
  BVar1 = IsBadWritePtr(param_1,4);
  if (BVar1 == 0) {
    iVar2 = FUN_40765180(param_2,1);
    if (iVar2 == 0) {
      iVar2 = 5;
    }
    else if (param_3 == 0) {
      *param_1 = 0;
      iVar2 = FUN_40764e64(param_1,param_2,0);
    }
    else {
      iVar2 = 10;
    }
  }
  else {
    iVar2 = 0xb;
  }
  return iVar2;
}



/* 40761628 FUN_40761628 */

/* Boundary evidence: original MIPS .pdata 40761628..4076168b. Semantic name remains unreviewed. */

undefined4 FUN_40761628(uint *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40765180(param_1,2);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else if (param_2 == 0) {
    uVar2 = FUN_40764798(param_1);
  }
  else {
    uVar2 = 10;
  }
  return uVar2;
}



/* 4076168c acmGetVersion */

undefined4 acmGetVersion(void)

{
                    /* 0x168c  6  acmGetVersion */
  return 0x2001997;
}



/* 40761698 FUN_40761698 */

/* Boundary evidence: original MIPS .pdata 40761698..40761783. Semantic name remains unreviewed. */

undefined4 FUN_40761698(int *param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *local_18 [2];
  
  uVar6 = 0x12;
  if (param_1 == (int *)0x0) {
    local_18[0] = (uint *)0x0;
    while (iVar1 = FUN_407645f0((uint *)local_18,local_18[0],0), iVar1 == 0) {
      uVar4 = local_18[0][0xb];
      if (uVar4 != 0) {
        puVar5 = (uint *)(local_18[0][0xc] + 4);
        do {
          if (uVar6 < *puVar5) {
            uVar6 = *puVar5;
          }
          uVar4 = uVar4 - 1;
          puVar5 = puVar5 + 2;
        } while (uVar4 != 0);
      }
    }
  }
  else {
    piVar2 = FUN_40763ca8(param_1);
    if (piVar2 == (int *)0x0) {
      return 5;
    }
    iVar1 = piVar2[0xb];
    if (iVar1 != 0) {
      puVar5 = (uint *)(piVar2[0xc] + 4);
      do {
        if (uVar6 < *puVar5) {
          uVar6 = *puVar5;
        }
        iVar1 = iVar1 + -1;
        puVar5 = puVar5 + 2;
      } while (iVar1 != 0);
    }
  }
  *param_2 = uVar6;
  uVar3 = 0x200;
  if (uVar6 != 0) {
    uVar3 = 0;
  }
  return uVar3;
}



/* 40761784 FUN_40761784 */

/* Boundary evidence: original MIPS .pdata 40761784..4076186b. Semantic name remains unreviewed. */

int FUN_40761784(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = param_3 & 0xf;
  if (uVar2 != 0) {
    if (uVar2 == 1) {
      uVar2 = 0;
      if (*(uint *)(param_1 + 0x2c) == 0) {
        return 0x200;
      }
      piVar3 = *(int **)(param_1 + 0x30);
      while (*piVar3 != *(int *)(param_2 + 8)) {
        uVar2 = uVar2 + 1;
        piVar3 = piVar3 + 2;
        if (*(uint *)(param_1 + 0x2c) <= uVar2) {
          return 0x200;
        }
      }
    }
    else if (uVar2 != 2) {
      return 0x200;
    }
  }
  iVar1 = FUN_407648a0(param_1,0x6019,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 8) == 0) {
      iVar1 = 1;
    }
    else if (*(int *)(param_2 + 8) == 1) {
      LoadStringW(*(HINSTANCE *)(DAT_407660a0 + 0x1c),300,(LPWSTR)(param_2 + 0x18),0x30);
    }
  }
  return iVar1;
}



/* 4076186c acmFormatTagDetails */

/* Boundary evidence: original MIPS .pdata 4076186c..40761ba7. Semantic name remains unreviewed. */

int acmFormatTagDetails(uint *param_1,uint *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  BOOL BVar3;
  uint *puVar4;
  uint uVar5;
  uint *lp;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *local_b0;
  uint *local_ac;
  uint auStack_a8 [30];
  uint local_30;
  
                    /* 0x186c  5  acmFormatTagDetails */
  local_30 = DAT_40766090;
  bVar2 = false;
  bVar1 = ((uint)param_2 & 3) != 0;
  lp = param_2;
  local_ac = param_2;
  if (bVar1) {
    memcpy(auStack_a8,param_2,0x78);
    lp = auStack_a8;
  }
  if ((param_3 & 0xfffffff0) != 0) {
    iVar6 = 10;
    goto LAB_40761b54;
  }
  BVar3 = IsBadWritePtr(lp,4);
  if ((((BVar3 != 0) || (*lp < 0x78)) || (BVar3 = IsBadWritePtr(lp,*lp), BVar3 != 0)) ||
     (lp[4] != 0)) {
LAB_40761924:
    iVar6 = 0xb;
    goto LAB_40761b54;
  }
  uVar8 = param_3 & 0xf;
  if (uVar8 == 0) {
    iVar6 = FUN_40765180(param_1,0);
    if (iVar6 != 0) goto LAB_4076198c;
LAB_407619e4:
    iVar6 = 5;
  }
  else {
    if (uVar8 == 1) {
      if (lp[2] == 0) goto LAB_40761924;
    }
    else if (uVar8 != 2) {
      iVar6 = 8;
      goto LAB_40761b54;
    }
LAB_4076198c:
    puVar9 = (uint *)0x0;
    if (param_1 == (uint *)0x0) {
LAB_40761a0c:
      local_b0 = (uint *)0x0;
      uVar7 = 0;
      do {
        iVar6 = FUN_407645f0((uint *)&local_b0,local_b0,0);
        param_2 = local_ac;
        if (iVar6 != 0) break;
        if (uVar8 == 1) {
          uVar5 = 0;
          if (local_b0[0xb] != 0) {
            puVar4 = (uint *)local_b0[0xc];
            do {
              if (*puVar4 == lp[2]) {
                bVar2 = true;
                puVar9 = local_b0;
                break;
              }
              uVar5 = uVar5 + 1;
              puVar4 = puVar4 + 2;
            } while (uVar5 < local_b0[0xb]);
          }
        }
        else if ((uVar8 == 2) && (uVar5 = local_b0[0xb], uVar5 != 0)) {
          puVar4 = (uint *)local_b0[0xc];
          do {
            if (((lp[2] == 0) || (*puVar4 == lp[2])) && (uVar7 < puVar4[1])) {
              uVar7 = puVar4[1];
              puVar9 = local_b0;
            }
            uVar5 = uVar5 - 1;
            puVar4 = puVar4 + 2;
          } while (uVar5 != 0);
        }
      } while (!bVar2);
      if (puVar9 == (uint *)0x0) {
        if ((uVar8 == 1) && (lp[2] != 1)) {
          iVar6 = 0x200;
        }
        else {
          lp[3] = 0x10;
          lp[5] = 0x10;
          lp[1] = 0;
          lp[2] = 1;
          lp[4] = 0;
          LoadStringW(*(HINSTANCE *)(DAT_407660a0 + 0x1c),300,(LPWSTR)(lp + 6),0x30);
          iVar6 = 0;
        }
        goto LAB_40761b54;
      }
    }
    else {
      iVar6 = FUN_40765180(param_1,0);
      if (iVar6 == 0) goto LAB_407619e4;
      if (*param_1 == 1) {
        if ((param_1[9] & 0x80000000) != 0) {
          iVar6 = 3;
          goto LAB_40761b54;
        }
      }
      else {
        iVar6 = FUN_40765180(param_1,2);
        if (iVar6 == 0) goto LAB_407619e4;
        param_1 = (uint *)param_1[3];
      }
      puVar9 = param_1;
      if (param_1 == (uint *)0x0) goto LAB_40761a0c;
    }
    iVar6 = FUN_40761784((int)puVar9,(int)lp,param_3);
  }
LAB_40761b54:
  if (bVar1) {
    memcpy(param_2,auStack_a8,0x78);
  }
  FUN_407655d0(local_30);
  return iVar6;
}



/* 40761ba8 acmFormatDetails */

/* Boundary evidence: original MIPS .pdata 40761ba8..40761eeb. Semantic name remains unreviewed. */

int acmFormatDetails(uint *param_1,uint *param_2,uint param_3)

{
  undefined1 *puVar1;
  bool bVar2;
  uint uVar3;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  uint *lp;
  uint uVar7;
  uint *local_1c8 [2];
  uint local_1c0 [2];
  undefined1 auStack_1b8 [12];
  uint local_1ac;
  uint auStack_148 [70];
  uint local_30;
  
                    /* 0x1ba8  2  acmFormatDetails */
  local_30 = DAT_40766090;
  bVar2 = ((uint)param_2 & 3) != 0;
  lp = param_2;
  if (bVar2) {
    memcpy(auStack_148,param_2,0x118);
    lp = auStack_148;
  }
  if ((param_3 & 0xfffffff0) != 0) {
    iVar6 = 10;
    goto LAB_40761e9c;
  }
  BVar4 = IsBadWritePtr(lp,4);
  if (((((BVar4 == 0) && (0x117 < *lp)) && (BVar4 = IsBadWritePtr(lp,*lp), BVar4 == 0)) &&
      ((0xf < lp[5] && (BVar4 = IsBadWritePtr((LPVOID)lp[4],lp[5]), BVar4 == 0)))) && (lp[3] == 0))
  {
    uVar7 = param_3 & 0xf;
    if (uVar7 != 0) {
      if (uVar7 != 1) {
        iVar6 = 8;
        goto LAB_40761e9c;
      }
      if (lp[2] != (uint)*(ushort *)lp[4]) goto LAB_40761c50;
    }
    if (lp[2] != 0) {
      if (uVar7 == 0) {
        iVar6 = FUN_40765180(param_1,0);
        if (iVar6 != 0) {
          memset(local_1c0,0,0x78);
          auStack_1b8._0_4_ = lp[2];
          puVar1 = auStack_1b8 + 3;
          uVar3 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar3) =
               *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 |
               (uint)auStack_1b8._0_4_ >> (3 - uVar3) * 8;
          local_1c0[0] = 0x78;
          iVar6 = acmFormatTagDetails(param_1,local_1c0,1);
          if (iVar6 != 0) goto LAB_40761e9c;
          if (local_1ac <= lp[1]) goto LAB_40761c50;
          goto LAB_40761d78;
        }
        goto LAB_40761d14;
      }
LAB_40761d78:
      if (param_1 == (uint *)0x0) {
        local_1c8[0] = (uint *)0x0;
        iVar6 = 6;
        iVar5 = FUN_407645f0((uint *)local_1c8,(uint *)0x0,0);
        if (iVar5 == 0) {
          do {
            *(undefined2 *)(lp + 6) = 0;
            iVar6 = FUN_407648a0((int)local_1c8[0],0x601a,lp,param_3);
            if (iVar6 == 0) goto LAB_40761dec;
            iVar5 = FUN_407645f0((uint *)local_1c8,local_1c8[0],0);
          } while (iVar5 == 0);
        }
        else if ((uVar7 == 1) && (lp[2] == 1)) {
          lp[5] = 0x10;
          lp[1] = 0;
          lp[2] = 1;
          lp[3] = 0;
          if (0x18 < *lp) {
            *(undefined2 *)(lp + 6) = 0;
          }
          iVar6 = 0;
        }
        goto LAB_40761e9c;
      }
      *(undefined2 *)(lp + 6) = 0;
      if (*param_1 == 1) {
        iVar6 = FUN_40765180(param_1,1);
        if (iVar6 != 0) {
          iVar6 = FUN_407648a0((int)param_1,0x601a,lp,param_3);
LAB_40761de0:
          if (iVar6 == 0) {
LAB_40761dec:
            if (uVar7 == 1) {
              lp[1] = 0;
            }
          }
          goto LAB_40761e9c;
        }
      }
      else {
        iVar6 = FUN_40765180(param_1,2);
        if (iVar6 != 0) {
          iVar6 = FUN_40763cd8((int)param_1,0x601a,lp,param_3);
          goto LAB_40761de0;
        }
      }
LAB_40761d14:
      iVar6 = 5;
      goto LAB_40761e9c;
    }
  }
LAB_40761c50:
  iVar6 = 0xb;
LAB_40761e9c:
  if (bVar2) {
    memcpy(param_2,auStack_148,0x118);
  }
  FUN_407655d0(local_30);
  return iVar6;
}



/* 40761eec FUN_40761eec */

/* Boundary evidence: original MIPS .pdata 40761eec..407623d7. Semantic name remains unreviewed. */

undefined4
FUN_40761eec(uint *param_1,int param_2,uint *param_3,undefined *param_4,undefined4 param_5,
            ushort *param_6,uint param_7)

{
  undefined1 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  size_t sVar5;
  uint uVar6;
  ushort *_Buf2;
  size_t _Size;
  int iVar7;
  ushort *_Buf1;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  uint local_40;
  code *local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  
  _Buf2 = (ushort *)0x0;
  _Size = local_4c;
  local_3c = (code *)param_4;
  if ((((param_7 & 0x100000) != 0) &&
      (iVar4 = FUN_40761698((int *)param_1,&local_4c), _Size = local_4c, iVar4 == 0)) &&
     (_Buf2 = LocalAlloc(0x40,local_4c), _Buf2 != (ushort *)0x0)) {
    uVar2 = *(undefined2 *)(param_2 + 8);
    *(char *)_Buf2 = (char)uVar2;
    uVar6 = 0x10000;
    *(char *)((int)_Buf2 + 1) = (char)((ushort)uVar2 >> 8);
    if ((param_7 & 0x20000) != 0) {
      uVar1 = *(undefined1 *)((int)param_6 + 3);
      uVar6 = 0x30000;
      *(char *)(_Buf2 + 1) = (char)param_6[1];
      *(undefined1 *)((int)_Buf2 + 3) = uVar1;
    }
    if ((param_7 & 0x40000) != 0) {
      uVar6 = uVar6 | 0x40000;
      *(undefined4 *)(_Buf2 + 2) = *(undefined4 *)(param_6 + 2);
    }
    if ((param_7 & 0x80000) != 0) {
      uVar6 = uVar6 | 0x80000;
      uVar1 = *(undefined1 *)((int)param_6 + 0xf);
      *(char *)(_Buf2 + 7) = (char)param_6[7];
      *(undefined1 *)((int)_Buf2 + 0xf) = uVar1;
    }
    iVar4 = acmFormatSuggest(param_1,param_6,_Buf2,local_4c,uVar6);
    if (iVar4 != 0) {
      LocalFree(_Buf2);
      return 0;
    }
    if (*_Buf2 == 1) {
      _Size = 0x10;
    }
    else {
      _Size = _Buf2[8] + 0x12;
    }
  }
  local_40 = param_1[3];
  local_44 = *(undefined4 *)(local_40 + 0x28);
  local_34 = *(int *)(param_6 + 2);
  local_38 = (uint)param_6[1];
  local_30 = (uint)param_6[7];
  local_48 = *param_3;
  _Buf1 = (ushort *)param_3[4];
  uVar6 = param_3[5];
  local_4c = 0;
  if (*(int *)(param_2 + 0x14) != 0) {
    do {
      *param_3 = local_48;
      param_3[1] = local_4c;
      param_3[2] = *(uint *)(param_2 + 8);
      param_3[3] = 0;
      param_3[4] = (uint)_Buf1;
      param_3[5] = uVar6;
      *(undefined2 *)(param_3 + 6) = 0;
      iVar4 = acmFormatDetails(param_1,param_3,0);
      if ((((iVar4 == 0) && (((param_7 & 0x20000) == 0 || (_Buf1[1] == local_38)))) &&
          (((param_7 & 0x40000) == 0 || (*(int *)(_Buf1 + 2) == local_34)))) &&
         (((param_7 & 0x80000) == 0 || (_Buf1[7] == local_30)))) {
        if ((param_7 & 0x100000) != 0) {
          iVar4 = acmStreamOpen((undefined4 *)0x0,param_1,param_6,_Buf1,(size_t *)0x0,0,0,5);
          if (iVar4 != 0) goto LAB_407622ac;
          if (_Buf2 != (ushort *)0x0) {
            if (*_Buf1 == 1) {
              sVar5 = 0x10;
            }
            else {
              sVar5 = _Buf1[8] + 0x12;
            }
            if ((sVar5 == _Size) && (iVar4 = memcmp(_Buf1,_Buf2,_Size), iVar4 == 0)) {
              LocalFree(_Buf2);
              _Buf2 = (ushort *)0x0;
            }
          }
        }
        if (((param_7 & 0x1800000) == 0) &&
           (iVar4 = (*local_3c)(local_40,param_3,param_5,local_44), iVar4 == 0)) {
          if (_Buf2 != (ushort *)0x0) {
            LocalFree(_Buf2);
            return 1;
          }
          return 1;
        }
      }
LAB_407622ac:
      local_4c = local_4c + 1;
    } while (local_4c < *(uint *)(param_2 + 0x14));
  }
  if (_Buf2 != (ushort *)0x0) {
    *param_3 = local_48;
    param_3[1] = 0;
    uVar3 = *_Buf2;
    param_3[5] = _Size;
    param_3[2] = (uint)uVar3;
    iVar7 = 1;
    param_3[3] = 0;
    param_3[4] = (uint)_Buf2;
    *(undefined2 *)(param_3 + 6) = 0;
    iVar4 = acmFormatDetails(param_1,param_3,1);
    if (iVar4 == 0) {
      if ((param_7 & 0x1800000) != 0) {
        LocalFree(_Buf2);
        param_3[5] = uVar6;
        return 0;
      }
      iVar7 = (*local_3c)(local_40,param_3,param_5,local_44);
    }
    param_3[4] = (uint)_Buf1;
    param_3[5] = uVar6;
    LocalFree(_Buf2);
    if (iVar7 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 407623d8 acmFormatEnum */

/* Boundary evidence: original MIPS .pdata 407623d8..40762867. Semantic name remains unreviewed. */

int acmFormatEnum(uint *param_1,uint *param_2,undefined *param_3,undefined4 param_4,uint param_5)

{
  uint *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  bool bVar4;
  BOOL BVar5;
  undefined3 extraout_var;
  int iVar6;
  short *psVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  SIZE_T uBytes;
  uint *lp;
  uint uVar12;
  uint uVar13;
  ushort *_Dst;
  uint *local_1e8;
  uint *local_1e4;
  uint local_1e0;
  uint local_1dc;
  uint local_1d8;
  undefined *local_1d4;
  uint *local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c0;
  uint local_1bc;
  uint auStack_148 [70];
  uint local_30;
  
                    /* 0x23d8  3  acmFormatEnum */
  local_30 = DAT_40766090;
  _Dst = (ushort *)0x0;
  local_1d4 = param_3;
  local_1d0 = param_2;
  local_1cc = param_4;
  local_1c8 = GetCallerProcess();
  bVar4 = ((uint)param_2 & 3) != 0;
  local_1d8 = 0;
  lp = param_2;
  if (bVar4) {
    memcpy(auStack_148,param_2,0x118);
    lp = auStack_148;
  }
  local_1d8 = (uint)bVar4;
  BVar5 = IsBadWritePtr(lp,4);
  if (((BVar5 == 0) && (0x117 < *lp)) && (BVar5 = IsBadWritePtr(lp,*lp), BVar5 == 0)) {
    if ((param_1 != (uint *)0x0) && (iVar11 = FUN_40765180(param_1,2), iVar11 == 0)) {
      iVar11 = 5;
      goto LAB_40762800;
    }
    bVar4 = FUN_40765268((int)param_3);
    if (CONCAT31(extraout_var,bVar4) != 0) {
      if (((param_5 & 0xfe00ffff) != 0) ||
         (((param_5 & 0x400000) != 0 && ((param_5 & 0x1800000) == 0)))) {
        iVar11 = 10;
        goto LAB_40762800;
      }
      iVar11 = FUN_40761698((int *)param_1,(uint *)&local_1e8);
      if (iVar11 != 0) goto LAB_40762800;
      if ((((local_1e8 <= (uint *)lp[5]) &&
           (BVar5 = IsBadWritePtr((LPVOID)lp[4],(UINT_PTR)lp[5]), BVar5 == 0)) && (lp[3] == 0)) &&
         (((param_5 & 0x10000) == 0 ||
          ((*(ushort *)lp[4] != 0 && (lp[2] == (uint)*(ushort *)lp[4])))))) {
        uVar13 = (uint)((param_5 & 0x100000) != 0);
        uVar12 = (uint)((param_5 & 0x200000) != 0);
        local_1e0 = uVar13;
        local_1dc = uVar12;
        if ((uVar13 == 0) && (uVar12 == 0)) {
          uBytes = 0x10;
        }
        else {
          psVar7 = (short *)lp[4];
          if (*psVar7 == 1) {
            uBytes = 0x10;
          }
          else {
            uBytes = (ushort)psVar7[8] + 0x12;
          }
          iVar11 = FUN_407650b8(psVar7);
          if ((iVar11 == 0) || (*(char *)lp[4] == '\0' && ((char *)lp[4])[1] == '\0'))
          goto LAB_40762488;
        }
        _Dst = LocalAlloc(0x40,uBytes);
        if (_Dst == (ushort *)0x0) {
          iVar11 = 7;
        }
        else {
          memcpy(_Dst,(void *)lp[4],uBytes);
          iVar11 = 0;
          local_1e4 = (uint *)0x0;
LAB_407627e0:
          do {
            do {
              iVar6 = FUN_407645f0((uint *)&local_1e4,local_1e4,0);
              puVar1 = local_1e4;
              if (iVar6 != 0) goto LAB_40762800;
              if ((uVar13 != 0) || (uVar12 != 0)) {
                uVar8 = (uint)*_Dst;
                uVar10 = 0;
                if (local_1e4[0xb] != 0) {
                  puVar9 = (uint *)local_1e4[0xc];
                  do {
                    if (uVar8 == *puVar9) {
                      uVar8 = 0;
                      break;
                    }
                    uVar10 = uVar10 + 1;
                    puVar9 = puVar9 + 2;
                  } while (uVar10 < local_1e4[0xb]);
                }
                if (uVar8 != 0) goto LAB_407627e0;
              }
              iVar11 = FUN_4076158c(&local_1e8,local_1e4,0);
              uVar3 = local_1cc;
              puVar2 = local_1d4;
            } while (iVar11 != 0);
            uVar8 = 0;
            if (puVar1[0xb] != 0) {
              do {
                local_1c0 = 0x78;
                local_1bc = uVar8;
                iVar11 = FUN_40761784((int)puVar1,(int)&local_1c0,0);
                if (iVar11 == 0) {
                  iVar11 = FUN_40761eec(local_1e8,(int)&local_1c0,lp,puVar2,uVar3,_Dst,param_5);
                }
                uVar12 = local_1dc;
                uVar13 = local_1e0;
                param_2 = local_1d0;
              } while ((iVar11 != 1) && (uVar8 = uVar8 + 1, uVar8 < puVar1[0xb]));
            }
            FUN_40761628(local_1e8,0);
          } while (iVar11 != 1);
          iVar11 = 0;
        }
        goto LAB_40762800;
      }
    }
  }
LAB_40762488:
  iVar11 = 0xb;
LAB_40762800:
  if (local_1d8 != 0) {
    memcpy(param_2,auStack_148,0x118);
  }
  if (_Dst != (ushort *)0x0) {
    LocalFree(_Dst);
  }
  FUN_407655d0(local_30);
  return iVar11;
}



/* 40762868 FUN_40762868 */

/* Boundary evidence: original MIPS .pdata 40762868..407628f7. Semantic name remains unreviewed. */

void FUN_40762868(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_28;
  
  memset(&local_40,0,0x28);
  local_40 = 0x28;
  local_28 = param_5 | 1;
  local_3c = param_2;
  local_38 = param_3;
  local_34 = param_4;
  FUN_40763cd8(param_1,0x604c,&local_40,0);
  return;
}



/* 407628f8 acmFormatSuggest */

/* Boundary evidence: original MIPS .pdata 407628f8..40762be3. Semantic name remains unreviewed. */

int acmFormatSuggest(uint *param_1,ushort *param_2,ushort *param_3,UINT_PTR param_4,uint param_5)

{
  undefined1 uVar1;
  ushort uVar2;
  BOOL BVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *local_48 [2];
  undefined4 local_40;
  uint local_3c;
  ushort *local_38;
  int local_34;
  ushort *local_30;
  UINT_PTR local_2c;
  
                    /* 0x28f8  4  acmFormatSuggest */
  if ((param_5 & 0xff00ffff) == 0) {
    iVar8 = FUN_407650b8((short *)param_2);
    if ((iVar8 == 0) || (BVar3 = IsBadWritePtr(param_3,param_4), BVar3 != 0)) {
      iVar8 = 0xb;
    }
    else {
      if (((param_1 == (uint *)0x0) && (*param_2 == 1)) && ((param_5 & 0x10000) == 0)) {
        uVar1 = *(undefined1 *)((int)param_3 + 1);
        uVar2 = *param_3;
        *(undefined1 *)param_3 = 1;
        *(undefined1 *)((int)param_3 + 1) = 0;
        iVar8 = acmFormatSuggest((uint *)0x0,param_2,param_3,param_4,param_5 | 0x10000);
        if (iVar8 == 0) {
          return 0;
        }
        *(char *)param_3 = (char)uVar2;
        *(undefined1 *)((int)param_3 + 1) = uVar1;
      }
      local_40 = 0x18;
      local_3c = param_5;
      local_34 = 0x10;
      if (*param_2 != 1) {
        local_34 = param_2[8] + 0x12;
      }
      local_38 = param_2;
      local_30 = param_3;
      local_2c = param_4;
      if (param_1 == (uint *)0x0) {
        if ((param_5 != 0) || (*param_2 != 1)) {
          iVar8 = 6;
          local_48[0] = (uint *)0x0;
LAB_40762b9c:
          do {
            do {
              iVar4 = FUN_407645f0((uint *)local_48,local_48[0],0);
              if (iVar4 != 0) {
                return iVar8;
              }
              uVar7 = local_48[0][0xb];
              uVar9 = 0;
            } while (uVar7 == 0);
            puVar6 = (uint *)local_48[0][0xc];
            puVar5 = puVar6;
            do {
              if ((uint)*param_2 == *puVar5) {
                if ((param_5 & 0x10000) == 0) goto LAB_40762b74;
                uVar9 = 0;
                goto LAB_40762b50;
              }
              uVar9 = uVar9 + 1;
              puVar5 = puVar5 + 2;
            } while (uVar9 < uVar7);
          } while( true );
        }
        memcpy(param_3,param_2,0x10);
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_40765180(param_1,2);
        if (iVar8 == 0) {
          iVar8 = 5;
        }
        else {
          iVar8 = FUN_40763cd8((int)param_1,0x601b,&local_40,0);
        }
      }
    }
  }
  else {
    iVar8 = 10;
  }
  return iVar8;
  while( true ) {
    uVar9 = uVar9 + 1;
    puVar6 = puVar6 + 2;
    if (uVar7 <= uVar9) break;
LAB_40762b50:
    if ((uint)*param_3 == *puVar6) goto LAB_40762b74;
  }
  goto LAB_40762b9c;
LAB_40762b74:
  iVar8 = FUN_407648a0((int)local_48[0],0x601b,&local_40,0);
  if (iVar8 == 0) {
    return 0;
  }
  goto LAB_40762b9c;
}



/* 40762be4 acmStreamOpen */

/* Boundary evidence: original MIPS .pdata 40762be4..4076329f. Semantic name remains unreviewed. */

int acmStreamOpen(undefined4 *param_1,uint *param_2,ushort *param_3,ushort *param_4,size_t *param_5,
                 int param_6,int param_7,uint param_8)

{
  bool bVar1;
  BOOL BVar2;
  undefined4 *hMem;
  void *pvVar3;
  size_t sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  size_t _Size;
  uint *puVar8;
  uint *puVar9;
  size_t _Size_00;
  HANDLE hHandle;
  uint *local_c8;
  uint *local_c4;
  int local_c0;
  size_t local_bc;
  uint local_b8;
  uint *local_b4;
  uint *local_b0;
  uint local_a8 [2];
  uint local_a0;
  uint local_98;
  uint local_30;
  
                    /* 0x2be4  10  acmStreamOpen */
  local_30 = DAT_40766090;
  local_c8 = param_2;
  if (param_1 == (undefined4 *)0x0) {
LAB_40762c54:
    if ((param_8 & 0xfff8fff8) != 0) {
      iVar7 = 10;
      goto LAB_40763264;
    }
    if ((param_8 & 1) == 0) {
      bVar1 = false;
      local_b4 = (uint *)0x0;
      if ((param_1 == (undefined4 *)0x0) && (BVar2 = IsBadWritePtr((LPVOID)0x0,4), BVar2 != 0))
      goto LAB_40763260;
    }
    else {
      bVar1 = true;
      local_b4 = (uint *)0x1;
      param_1 = (undefined4 *)0x0;
    }
    iVar7 = FUN_407650b8((short *)param_3);
    if ((iVar7 != 0) && (iVar7 = FUN_407650b8((short *)param_4), iVar7 != 0)) {
      hHandle = (HANDLE)0x0;
      local_bc = 0x10;
      if ((param_8 & 2) == 0) {
        local_c0 = 0;
        if ((param_6 != 0) || (param_7 != 0)) goto LAB_40763260;
        uVar6 = 0;
      }
      else {
        local_c0 = 1;
        uVar6 = 0x10;
      }
      local_c4 = (uint *)0x0;
      local_b8 = (uint)(local_c8 != (uint *)0x0);
      uVar5 = (uint)*param_3;
      if (uVar5 == *param_4) {
        uVar6 = uVar6 | 2;
      }
      else {
        uVar6 = uVar6 | 1;
        if (uVar5 == 1) {
          uVar5 = (uint)*param_4;
        }
      }
      if (local_c8 == (uint *)0x0) {
        local_c4 = (uint *)0x0;
        iVar7 = FUN_407645f0((uint *)&local_c4,(uint *)0x0,0);
        if (iVar7 == 0) {
          do {
            puVar9 = local_c4;
            local_b0 = local_c4;
            if (uVar6 == (local_c4[10] & uVar6)) {
              local_a8[0] = 0x78;
              local_98 = 0;
              local_a0 = uVar5;
              iVar7 = acmFormatTagDetails(local_c4,local_a8,1);
              if (((iVar7 == 0) && (uVar6 == (local_98 & uVar6))) &&
                 (iVar7 = FUN_40764e64(&local_c8,local_c4,0), iVar7 == 0)) {
                iVar7 = FUN_40762868((int)local_c8,param_3,param_4,param_5,param_8);
                if (iVar7 == 0) break;
                if ((local_c0 == 0) && ((puVar9[10] & 0x10) != 0)) {
                  iVar7 = FUN_40762868((int)local_c8,param_3,param_4,param_5,param_8 | 2);
                }
                if (iVar7 == 0) break;
                FUN_40764798(local_c8);
                local_c8 = (uint *)0x0;
              }
            }
            iVar7 = FUN_407645f0((uint *)&local_c4,local_c4,0);
          } while (iVar7 == 0);
        }
        else {
          local_b0 = local_b4;
        }
        if (local_c8 != (uint *)0x0) {
LAB_40762f64:
          if (local_b4 == (uint *)0x0) {
LAB_40762f78:
            if (*param_3 == 1) {
              _Size_00 = 0x10;
            }
            else {
              _Size_00 = param_3[8] + 0x12;
            }
            if (*param_4 == 1) {
              sVar4 = 0x10;
            }
            else {
              sVar4 = param_4[8] + 0x12;
              local_bc = sVar4;
            }
            if (param_5 == (size_t *)0x0) {
              _Size = 0;
            }
            else {
              _Size = *param_5;
            }
            hMem = LocalAlloc(0x40,_Size + sVar4 + _Size_00 + 0x3c);
            if (hMem == (undefined4 *)0x0) {
              iVar7 = 7;
            }
            else {
              *hMem = 3;
              hMem[1] = local_b8;
              hMem[3] = local_c8;
              hMem[5] = 0x28;
              hMem[6] = hMem + 0xf;
              hMem[7] = (int)hMem + _Size_00 + 0x3c;
              if (param_5 != (size_t *)0x0) {
                pvVar3 = (void *)((int)hMem + _Size_00 + local_bc + 0x3c);
                hMem[8] = pvVar3;
                memcpy(pvVar3,param_5,_Size);
              }
              puVar8 = hMem + 0xb;
              hMem[9] = param_6;
              pvVar3 = (void *)hMem[6];
              uVar6 = (int)hMem + 0x3bU & 3;
              puVar9 = (uint *)(((int)hMem + 0x3bU) - uVar6);
              *puVar9 = *puVar9 & -1 << (uVar6 + 1) * 8 | (uint)hMem >> (3 - uVar6) * 8;
              hMem[10] = param_7;
              *puVar8 = param_8;
              uVar6 = (uint)(hMem + 0xe) & 3;
              puVar9 = (uint *)((int)(hMem + 0xe) - uVar6);
              *puVar9 = *puVar9 & 0xffffffffU >> (4 - uVar6) * 8 | (int)hMem << uVar6 * 8;
              memcpy(pvVar3,param_3,_Size_00);
              memcpy((void *)hMem[7],param_4,local_bc);
              iVar7 = FUN_40763cd8((int)local_c8,0x604c,hMem + 5,0);
              if (iVar7 == 0) {
LAB_40763244:
                iVar7 = 0;
                hMem[2] = local_c8[2];
                local_c8[2] = (uint)hMem;
                *param_1 = hMem;
                goto LAB_40763264;
              }
              if (((local_c0 == 0) && ((local_b0[10] & 0x10) != 0)) &&
                 (hHandle = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0),
                 hHandle != (HANDLE)0x0)) {
                hMem[1] = hMem[1] | 2;
                hMem[9] = hHandle;
                *puVar8 = *puVar8 & 0xfffdffff | 0x50002;
                iVar7 = FUN_40763cd8((int)local_c8,0x604c,hMem + 5,0);
                if (iVar7 == 0) {
                  WaitForSingleObject(hHandle,0xffffffff);
                  goto LAB_407631e8;
                }
              }
              else {
LAB_407631e8:
                if (iVar7 == 0) goto LAB_40763244;
              }
              *hMem = 0x29a;
              LocalFree(hMem);
              if (hHandle != (HANDLE)0x0) {
                CloseHandle(hHandle);
              }
            }
          }
          else {
            iVar7 = 0;
          }
          if ((local_b8 & 1) == 0) {
            local_c4 = (uint *)local_c8[3];
            FUN_40764798(local_c8);
          }
          goto LAB_40763264;
        }
      }
      else {
        iVar7 = FUN_40765180(local_c8,2);
        if (iVar7 == 0) {
          iVar7 = 5;
          goto LAB_40763264;
        }
        puVar9 = (uint *)local_c8[3];
        local_b0 = puVar9;
        if (uVar6 == (puVar9[10] & uVar6)) {
          if (bVar1) {
            iVar7 = FUN_40762868((int)local_c8,param_3,param_4,param_5,param_8);
            if (iVar7 != 0) {
              if ((local_c0 == 0) && ((puVar9[10] & 0x10) != 0)) {
                iVar7 = FUN_40762868((int)local_c8,param_3,param_4,param_5,param_8 | 2);
              }
              if (iVar7 != 0) goto LAB_40763264;
            }
            goto LAB_40762f64;
          }
          goto LAB_40762f78;
        }
      }
      iVar7 = 0x200;
      goto LAB_40763264;
    }
  }
  else {
    BVar2 = IsBadWritePtr(param_1,4);
    if (BVar2 == 0) {
      *param_1 = 0;
      goto LAB_40762c54;
    }
  }
LAB_40763260:
  iVar7 = 0xb;
LAB_40763264:
  FUN_407655d0(local_30);
  return iVar7;
}



/* 407632a0 acmStreamClose */

/* Boundary evidence: original MIPS .pdata 407632a0..4076342b. Semantic name remains unreviewed. */

int acmStreamClose(uint *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  HANDLE hHandle;
  
                    /* 0x32a0  8  acmStreamClose */
  iVar1 = FUN_40765180(param_1,3);
  if (iVar1 == 0) {
    return 5;
  }
  if (param_2 != 0) {
    return 10;
  }
  if (param_1[4] != 0) {
    param_1[4] = 0;
  }
  if ((param_1[1] & 2) == 0) {
    hHandle = (HANDLE)0x0;
  }
  else {
    hHandle = (HANDLE)param_1[9];
  }
  iVar1 = FUN_40763cd8(param_1[3],0x604d,param_1 + 5,0);
  if (hHandle == (HANDLE)0x0) {
LAB_4076334c:
    if (iVar1 != 0) goto LAB_40763354;
  }
  else {
    if (iVar1 == 0) {
      WaitForSingleObject(hHandle,0xffffffff);
      goto LAB_4076334c;
    }
LAB_40763354:
    if (*(uint *)(DAT_407660a0 + 0x28) != param_1[3]) {
      return iVar1;
    }
  }
  if (hHandle != (HANDLE)0x0) {
    CloseHandle(hHandle);
  }
  puVar4 = *(uint **)(param_1[3] + 8);
  if (param_1 == puVar4) {
    uVar2 = param_1[2];
    *(uint *)(param_1[3] + 8) = uVar2;
    if ((uVar2 == 0) && ((param_1[1] & 1) == 0)) {
      FUN_40764798((undefined4 *)param_1[3]);
    }
LAB_407633f4:
    *param_1 = 0x29a;
    LocalFree(param_1);
    return iVar1;
  }
  if (puVar4 != (uint *)0x0) {
    do {
      puVar3 = (uint *)puVar4[2];
      if (param_1 == puVar3) break;
      puVar4 = puVar3;
    } while (puVar3 != (uint *)0x0);
    if (puVar4 != (uint *)0x0) {
      puVar4[2] = param_1[2];
      goto LAB_407633f4;
    }
  }
  return 5;
}



/* 4076342c acmStreamSize */

/* Boundary evidence: original MIPS .pdata 4076342c..4076356b. Semantic name remains unreviewed. */

int acmStreamSize(uint *param_1,int param_2,int *param_3,uint param_4)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_28;
  uint local_24;
  int local_20;
  int local_1c;
  
                    /* 0x342c  12  acmStreamSize */
  BVar1 = IsBadWritePtr(param_3,4);
  if (BVar1 == 0) {
    *param_3 = 0;
    iVar2 = FUN_40765180(param_1,3);
    if (iVar2 == 0) {
      return 5;
    }
    if ((param_4 & 0xfffffff0) != 0) {
      return 10;
    }
    if (param_2 != 0) {
      local_28 = 0x10;
      uVar3 = param_4 & 0xf;
      if (uVar3 == 0) {
        local_1c = 0;
        local_20 = param_2;
      }
      else {
        if (uVar3 != 1) {
          return 8;
        }
        local_20 = 0;
        local_1c = param_2;
      }
      local_24 = param_4;
      iVar2 = FUN_40763cd8(param_1[3],0x604e,param_1 + 5,&local_28);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (uVar3 == 0) {
        *param_3 = local_1c;
      }
      else if (uVar3 == 1) {
        *param_3 = local_20;
      }
      if (*param_3 != 0) {
        return 0;
      }
      return 0x200;
    }
  }
  return 0xb;
}



/* 4076356c acmStreamPrepareHeader */

/* Boundary evidence: original MIPS .pdata 4076356c..407637e7. Semantic name remains unreviewed. */

int acmStreamPrepareHeader(uint *param_1,UINT_PTR *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  UINT_PTR *lp;
  int aiStack_88 [2];
  UINT_PTR aUStack_80 [22];
  
                    /* 0x356c  11  acmStreamPrepareHeader */
  bVar1 = ((uint)param_2 & 3) != 0;
  iVar4 = 1;
  lp = param_2;
  if (bVar1) {
    memcpy(aUStack_80,param_2,0x54);
    lp = aUStack_80;
  }
  iVar2 = FUN_40765180(param_1,3);
  if (iVar2 == 0) {
    iVar4 = 5;
    goto LAB_407637a0;
  }
  BVar3 = IsBadWritePtr(lp,4);
  if (((BVar3 != 0) || (BVar3 = IsBadWritePtr(lp,*lp), BVar3 != 0)) ||
     (BVar3 = IsBadWritePtr(lp,0x54), BVar3 != 0)) {
LAB_4076360c:
    iVar4 = 0xb;
    goto LAB_407637a0;
  }
  if (*lp != 0x54) goto LAB_407637a0;
  if ((param_3 != 0) || ((lp[1] & 0xffecffff) != 0)) {
    iVar4 = 10;
    goto LAB_407637a0;
  }
  if ((lp[1] & 0x20000) != 0) {
    iVar4 = 0;
    goto LAB_407637a0;
  }
  iVar4 = acmStreamSize(param_1,lp[4],aiStack_88,0);
  if (iVar4 != 0) goto LAB_407637a0;
  BVar3 = IsBadReadPtr((void *)lp[3],lp[4]);
  if ((BVar3 != 0) || (BVar3 = IsBadWritePtr((LPVOID)lp[7],lp[8]), BVar3 != 0)) goto LAB_4076360c;
  lp[0xb] = 0;
  lp[0xc] = 0;
  lp[0xd] = 0;
  lp[0xe] = 0;
  lp[0xf] = 0;
  lp[0x10] = 0;
  lp[0x11] = 0;
  lp[0x12] = 0;
  lp[0x13] = 0;
  lp[0x14] = 0;
  iVar4 = FUN_40763cd8(param_1[3],0x6051,param_1 + 5,lp);
  if (iVar4 == 8) {
LAB_40763754:
    iVar4 = 0;
  }
  else {
    if (iVar4 != 0) goto LAB_407637a0;
    if ((*(uint *)(*(int *)(param_1[3] + 0xc) + 0x20) & 0x80000000) != 0) goto LAB_40763754;
  }
  lp[1] = lp[1] & 0x110000 | 0x20000;
  lp[0xf] = 0;
  lp[0x10] = (UINT_PTR)param_1;
  lp[0x11] = lp[3];
  lp[0x12] = lp[4];
  lp[0x13] = lp[7];
  lp[0x14] = lp[8];
  param_1[4] = param_1[4] + 1;
LAB_407637a0:
  if (bVar1) {
    memcpy(param_2,aUStack_80,0x54);
  }
  return iVar4;
}



/* 407637e8 acmStreamUnprepareHeader */

/* Boundary evidence: original MIPS .pdata 407637e8..40763a13. Semantic name remains unreviewed. */

int acmStreamUnprepareHeader(uint *param_1,UINT_PTR *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  UINT_PTR *lp;
  UINT_PTR aUStack_78 [22];
  
                    /* 0x37e8  13  acmStreamUnprepareHeader */
  bVar1 = ((uint)param_2 & 3) != 0;
  lp = param_2;
  if (bVar1) {
    memcpy(aUStack_78,param_2,0x54);
    lp = aUStack_78;
  }
  iVar3 = FUN_40765180(param_1,3);
  if (iVar3 == 0) {
LAB_40763854:
    iVar3 = 5;
    goto LAB_407639d4;
  }
  BVar4 = IsBadWritePtr(lp,4);
  if ((BVar4 == 0) && (BVar4 = IsBadWritePtr(lp,*lp), BVar4 == 0)) {
    if (param_3 != 0) {
LAB_40763898:
      iVar3 = 10;
      goto LAB_407639d4;
    }
    if (0x53 < *lp) {
      uVar5 = lp[1];
      if ((uVar5 & 0xffecffff) != 0) goto LAB_40763898;
      if ((uVar5 & 0x100000) != 0) {
        iVar3 = 0x201;
        goto LAB_407639d4;
      }
      if ((uVar5 & 0x20000) == 0) {
        iVar3 = 0x202;
        goto LAB_407639d4;
      }
      if (param_1 != (uint *)lp[0x10]) goto LAB_40763854;
      bVar2 = false;
      if (lp[3] == lp[0x11]) {
        if (lp[4] != lp[0x12]) {
          if (lp[3] != lp[0x11]) goto LAB_407639d0;
          lp[4] = lp[0x12];
          bVar2 = true;
        }
        if (lp[7] == lp[0x13]) {
          if (lp[8] != lp[0x14]) {
            if (lp[7] != lp[0x13]) goto LAB_407639d0;
            lp[8] = lp[0x14];
            bVar2 = true;
          }
          lp[0xb] = 0;
          iVar3 = FUN_40763cd8(param_1[3],0x6052,param_1 + 5,lp);
          if (iVar3 == 8) {
            iVar3 = 0;
          }
          if (iVar3 != 0) goto LAB_407639d4;
          lp[0xf] = 0;
          lp[1] = lp[1] & 0x110000;
          lp[0x10] = 0;
          lp[0x11] = 0;
          lp[0x12] = 0;
          lp[0x13] = 0;
          lp[0x14] = 0;
          param_1[4] = param_1[4] - 1;
          if (!bVar2) goto LAB_407639d4;
        }
      }
    }
  }
LAB_407639d0:
  iVar3 = 0xb;
LAB_407639d4:
  if (bVar1) {
    memcpy(param_2,aUStack_78,0x54);
  }
  return iVar3;
}



/* 40763a14 acmStreamConvert */

/* Boundary evidence: original MIPS .pdata 40763a14..40763ca7. Semantic name remains unreviewed. */

int acmStreamConvert(uint *param_1,UINT_PTR *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  BOOL BVar3;
  uint uVar4;
  UINT_PTR *lp;
  HANDLE hHandle;
  UINT_PTR aUStack_78 [22];
  
                    /* 0x3a14  9  acmStreamConvert */
  bVar1 = ((uint)param_2 & 3) != 0;
  lp = param_2;
  if (bVar1) {
    memcpy(aUStack_78,param_2,0x54);
    lp = aUStack_78;
  }
  iVar2 = FUN_40765180(param_1,3);
  if (iVar2 == 0) {
LAB_40763a80:
    iVar2 = 5;
    goto LAB_40763c68;
  }
  BVar3 = IsBadWritePtr(lp,4);
  if ((BVar3 != 0) || (BVar3 = IsBadWritePtr(lp,*lp), BVar3 != 0)) {
LAB_40763c64:
    iVar2 = 0xb;
    goto LAB_40763c68;
  }
  if ((param_3 & 0xffffffcb) != 0) {
    iVar2 = 10;
    goto LAB_40763c68;
  }
  if (*lp < 0x54) goto LAB_40763c64;
  uVar4 = lp[1];
  if ((uVar4 & 0x100000) != 0) {
    iVar2 = 0x201;
    goto LAB_40763c68;
  }
  if ((uVar4 & 0x20000) == 0) {
    iVar2 = 0x202;
    goto LAB_40763c68;
  }
  lp[5] = 0;
  lp[9] = 0;
  if (param_1 != (uint *)lp[0x10]) goto LAB_40763a80;
  if ((((lp[3] != lp[0x11]) || (lp[0x12] < lp[4])) || (lp[7] != lp[0x13])) || (lp[8] != lp[0x14]))
  goto LAB_40763c64;
  if ((param_1[1] & 2) == 0) {
    hHandle = (HANDLE)0x0;
  }
  else {
    hHandle = (HANDLE)param_1[9];
  }
  lp[0xb] = param_3;
  lp[1] = uVar4 & 0xfffeffff;
  lp[0xc] = 0;
  iVar2 = FUN_40763cd8(param_1[3],0x604f,param_1 + 5,lp);
  if (hHandle == (HANDLE)0x0) {
LAB_40763bf0:
    if (iVar2 == 0) {
      if (lp[4] < lp[5]) {
        lp[5] = lp[4];
      }
      if (lp[8] < lp[9]) {
        lp[9] = lp[8];
      }
      if ((param_1[0xb] & 2) == 0) {
        lp[1] = lp[1] | 0x10000;
      }
    }
  }
  else if (iVar2 == 0) {
    WaitForSingleObject(hHandle,0xffffffff);
    EventModify(hHandle,2);
    goto LAB_40763bf0;
  }
  lp[1] = lp[1] & 0x130000;
LAB_40763c68:
  if (bVar1) {
    memcpy(param_2,aUStack_78,0x54);
  }
  return iVar2;
}



/* 40763ca8 FUN_40763ca8 */

int * FUN_40763ca8(int *param_1)

{
  if (*param_1 != 1) {
    if (*param_1 == 2) {
      param_1 = (int *)param_1[3];
    }
    else {
      param_1 = (int *)0x0;
    }
  }
  return param_1;
}



/* 40763cd8 FUN_40763cd8 */

/* Boundary evidence: original MIPS .pdata 40763cd8..40763d93. Semantic name remains unreviewed. */

undefined4 FUN_40763cd8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  BOOL BVar2;
  FARPROC lpfn;
  
  if ((param_1 == 0) || (lpfn = *(FARPROC *)(param_1 + 0x1c), lpfn == (FARPROC)0x0)) {
    uVar1 = 5;
  }
  else {
    if (lpfn != (FARPROC)0xffffffff) {
      BVar2 = IsBadCodePtr(lpfn);
      if (BVar2 == 0) {
        uVar1 = (**(code **)(param_1 + 0x1c))
                          (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0xc),param_2,
                           param_3,param_4);
        return uVar1;
      }
      *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 40763d94 FUN_40763d94 */

/* Boundary evidence: original MIPS .pdata 40763d94..40763f0f. Semantic name remains unreviewed. */

undefined4 FUN_40763d94(int param_1,uint *param_2)

{
  uint *_Src;
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((*(uint *)(param_1 + 0x24) & 0x10000000) == 0) {
    _Src = LocalAlloc(0x40,0x708);
    if (_Src == (uint *)0x0) {
      uVar3 = 7;
    }
    else {
      uVar4 = (int)_Src + 3U & 3;
      puVar2 = (uint *)(((int)_Src + 3U) - uVar4);
      *puVar2 = *puVar2 & -1 << (uVar4 + 1) * 8 | 0x708U >> (3 - uVar4) * 8;
      uVar4 = (uint)_Src & 3;
      *(uint *)((int)_Src - uVar4) =
           *(uint *)((int)_Src - uVar4) & 0xffffffffU >> (4 - uVar4) * 8 | 0x708 << uVar4 * 8;
      iVar1 = FUN_407648a0(param_1,0x600a,_Src,0);
      if ((iVar1 == 0) && (_Src[4] != 0)) {
        uVar4 = *_Src;
        if (*param_2 <= *_Src) {
          uVar4 = *param_2;
        }
        memcpy(param_2,_Src,uVar4);
        puVar2 = param_2 + 6;
        *param_2 = uVar4;
        if ((*puVar2 & 0xffffffe0) == 0) {
          if ((*(uint *)(param_1 + 0x24) & 0x80000000) != 0) {
            *puVar2 = *puVar2 | 0x80000000;
          }
          uVar3 = 0;
          if ((*(uint *)(param_1 + 0x24) & 0x40000000) != 0) {
            *puVar2 = *puVar2 | 0x40000000;
          }
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 8;
      }
    }
    if (_Src != (uint *)0x0) {
      LocalFree(_Src);
    }
  }
  else {
    uVar3 = 8;
  }
  return uVar3;
}



/* 40763f10 FUN_40763f10 */

/* Boundary evidence: original MIPS .pdata 40763f10..40764033. Semantic name remains unreviewed. */

int FUN_40763f10(int param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 *hMem;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined1 auStack_98 [4];
  undefined1 auStack_94 [4];
  undefined4 local_90;
  undefined4 local_8c;
  uint local_20;
  
  local_20 = DAT_40766090;
  iVar3 = 1;
  if (*(HLOCAL *)(param_1 + 0x30) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    hMem = LocalAlloc(0x40,*(int *)(param_1 + 0x2c) << 3);
    if (hMem == (undefined4 *)0x0) {
      iVar3 = 7;
    }
    else {
      uVar4 = 0;
      *(undefined4 **)(param_1 + 0x30) = hMem;
      puVar5 = hMem;
      if (*(int *)(param_1 + 0x2c) != 0) {
        do {
          puVar1 = auStack_98 + 3;
          uVar2 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar2) =
               *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x78U >> (3 - uVar2) * 8;
          puVar1 = auStack_94 + 3;
          uVar2 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar2) =
               *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | uVar4 >> (3 - uVar2) * 8;
          auStack_98 = (undefined1  [4])0x78;
          auStack_94 = (undefined1  [4])uVar4;
          iVar3 = FUN_407648a0(param_1,0x6019,auStack_98,0);
          if (iVar3 != 0) goto LAB_40763f7c;
          uVar4 = uVar4 + 1;
          *puVar5 = local_90;
          puVar5[1] = local_8c;
          puVar5 = puVar5 + 2;
        } while (uVar4 < *(uint *)(param_1 + 0x2c));
        goto LAB_40763f8c;
      }
    }
LAB_40763f7c:
    if (hMem != (undefined4 *)0x0) {
      LocalFree(hMem);
    }
  }
LAB_40763f8c:
  FUN_407655d0(local_20);
  return iVar3;
}



/* 40764034 FUN_40764034 */

/* Boundary evidence: original MIPS .pdata 40764034..4076438b. Semantic name remains unreviewed. */

undefined4 FUN_40764034(int param_1)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  LPBYTE lpData;
  LPBYTE lpData_00;
  SIZE_T SVar3;
  DWORD local_40;
  DWORD local_3c;
  HKEY local_38;
  HKEY local_34;
  int local_30;
  int local_2c;
  undefined4 local_28 [2];
  
  lpData_00 = (LPBYTE)0x0;
  local_34 = (HKEY)0x0;
  lpData = (LPBYTE)0x0;
  local_38 = (HKEY)0x0;
  if ((*(uint *)(param_1 + 0x20) & 7) != 1) {
    return 8;
  }
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"AudioCompressionManager\\DriverCache",0,0x20019,&local_34
                       );
  if (LVar1 != 0) {
    local_34 = (HKEY)0x0;
    uVar2 = 7;
    goto LAB_40764330;
  }
  LVar1 = RegOpenKeyExW(local_34,(LPCWSTR)(param_1 + 0x50),0,0x20019,&local_38);
  if (LVar1 != 0) {
LAB_407640f4:
    uVar2 = 0x200;
    goto LAB_40764330;
  }
  local_40 = 4;
  LVar1 = RegQueryValueExW(local_38,L"fdwSupport",(LPDWORD)0x0,&local_3c,(LPBYTE)local_28,&local_40)
  ;
  if (((LVar1 == 0) && (local_3c == 4)) && (local_40 == 4)) {
    local_40 = 4;
    LVar1 = RegQueryValueExW(local_38,L"cFormatTags",(LPDWORD)0x0,&local_3c,(LPBYTE)&local_2c,
                             &local_40);
    if (((LVar1 != 0) || (local_3c != 4)) || (local_40 != 4)) goto LAB_407640f4;
    if (local_2c == 0) {
LAB_40764220:
      local_40 = 4;
      LVar1 = RegQueryValueExW(local_38,L"cFilterTags",(LPDWORD)0x0,&local_3c,(LPBYTE)&local_30,
                               &local_40);
      if (((LVar1 == 0) && (local_3c == 4)) && (local_40 == 4)) {
        if (local_30 != 0) {
          SVar3 = local_30 << 3;
          lpData = LocalAlloc(0x40,SVar3);
          if (lpData == (LPBYTE)0x0) goto LAB_407641cc;
          local_40 = SVar3;
          LVar1 = RegQueryValueExW(local_38,L"aFilterTagCache",(LPDWORD)0x0,&local_3c,lpData,
                                   &local_40);
          if (((LVar1 != 0) || (local_3c != 3)) || (SVar3 != local_40)) goto LAB_4076430c;
        }
        *(undefined4 *)(param_1 + 0x28) = local_28[0];
        *(int *)(param_1 + 0x2c) = local_2c;
        *(LPBYTE *)(param_1 + 0x30) = lpData_00;
        *(int *)(param_1 + 0x34) = local_30;
        *(LPBYTE *)(param_1 + 0x38) = lpData;
        uVar2 = 0;
        goto LAB_40764330;
      }
      goto LAB_4076430c;
    }
    SVar3 = local_2c << 3;
    lpData_00 = LocalAlloc(0x40,SVar3);
    if (lpData_00 != (LPBYTE)0x0) {
      local_40 = SVar3;
      LVar1 = RegQueryValueExW(local_38,L"aFormatTagCache",(LPDWORD)0x0,&local_3c,lpData_00,
                               &local_40);
      if (((LVar1 != 0) || (local_3c != 3)) || (SVar3 != local_40)) goto LAB_4076430c;
      goto LAB_40764220;
    }
LAB_407641cc:
    uVar2 = 7;
  }
  else {
LAB_4076430c:
    uVar2 = 0x200;
  }
  if (lpData_00 != (LPBYTE)0x0) {
    LocalFree(lpData_00);
  }
  if (lpData != (LPBYTE)0x0) {
    LocalFree(lpData);
  }
LAB_40764330:
  if (local_38 != (HKEY)0x0) {
    RegCloseKey(local_38);
  }
  if (local_34 != (HKEY)0x0) {
    RegCloseKey(local_34);
  }
  return uVar2;
}



/* 4076438c FUN_4076438c */

/* Boundary evidence: original MIPS .pdata 4076438c..407645ef. Semantic name remains unreviewed. */

int FUN_4076438c(int param_1)

{
  HMODULE pHVar1;
  int iVar2;
  uint uVar3;
  uint *hMem;
  
  hMem = (uint *)0x0;
  if ((*(uint *)(param_1 + 0x24) & 1) != 0) {
    return 0;
  }
  if ((*(LPCWSTR *)(param_1 + 0x1c) == (LPCWSTR)0x0) ||
     (pHVar1 = LoadLibraryW(*(LPCWSTR *)(param_1 + 0x1c)), pHVar1 == (HMODULE)0x0)) {
    iVar2 = 6;
LAB_407645c0:
    if (hMem != (uint *)0x0) {
      LocalFree(hMem);
    }
  }
  else {
    *(HMODULE *)(param_1 + 0x40) = pHVar1;
    iVar2 = GetProcAddressW(pHVar1,L"DriverProc");
    *(int *)(param_1 + 0x44) = iVar2;
    if (iVar2 != 0) {
      FUN_407648a0(param_1,2,0,0);
      iVar2 = FUN_407648a0(param_1,3,0,0);
      *(int *)(param_1 + 0x48) = iVar2;
      if (iVar2 != 0) {
        uVar3 = *(uint *)(param_1 + 0x24);
        *(uint *)(param_1 + 0x24) = uVar3 | 1;
        if ((uVar3 & 0x10000000) != 0) {
          return 0;
        }
        hMem = LocalAlloc(0x40,0x708);
        if (hMem == (uint *)0x0) {
          iVar2 = 7;
        }
        else {
          *hMem = 0x708;
          iVar2 = FUN_40763d94(param_1,hMem);
          if (iVar2 == 0) {
            if (((((*hMem == 0x708) && (hMem[1] == 0x63647561)) && (hMem[2] == 0)) &&
                ((hMem != (uint *)0xffffffd8 && (hMem != (uint *)0xffffff98)))) &&
               ((hMem != (uint *)0xfffffe98 &&
                ((hMem != (uint *)0xfffffdf8 && (hMem != (uint *)0xfffffcf8)))))) {
              *(undefined4 *)(param_1 + 8) = 0;
              *(uint *)(param_1 + 0x28) = hMem[6] & 0x7fffffff;
              *(uint *)(param_1 + 0x2c) = hMem[7];
              iVar2 = FUN_40763f10(param_1);
              if (iVar2 == 0) {
                iVar2 = FUN_407648a0(param_1,8,0,0);
                if (iVar2 != 0) {
                  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 2;
                }
                iVar2 = FUN_407648a0(param_1,0x600b,0xffffffff,0);
                if (iVar2 == 0) {
                  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 4;
                }
                iVar2 = 0;
              }
            }
            else {
              iVar2 = 1;
            }
          }
        }
        goto LAB_407645c0;
      }
    }
    iVar2 = 6;
  }
  return iVar2;
}



/* 407645f0 FUN_407645f0 */

/* Boundary evidence: original MIPS .pdata 407645f0..40764797. Semantic name remains unreviewed. */

undefined4 FUN_407645f0(uint *param_1,uint *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_30;
  
  *param_1 = 0;
  uVar4 = 1;
  if (param_3 == 0xffffffff) {
    bVar1 = true;
    uVar4 = local_30;
    uVar5 = local_30;
    uVar6 = local_30;
  }
  else {
    bVar1 = false;
    uVar6 = (uint)((param_3 & 0x80000000) != 0);
    uVar5 = (uint)((param_3 & 0x40000000) == 0);
    local_30 = (uint)((param_3 & 0x10000000) != 0);
    if ((param_3 & 0x20000000) == 0) {
      uVar4 = 0;
    }
  }
  if (param_2 == (uint *)0x0) {
    uVar3 = *(uint *)(DAT_407660a0 + 0x20);
  }
  else {
    iVar2 = FUN_40765180(param_2,1);
    if (iVar2 == 0) {
      return 5;
    }
    uVar3 = param_2[4];
  }
  while( true ) {
    if (uVar3 == 0) {
      return 2;
    }
    if ((bVar1) ||
       (((((local_30 != 0 || ((*(uint *)(uVar3 + 0x24) & 0x10000000) == 0)) &&
          ((uVar5 != 0 || ((*(uint *)(uVar3 + 0x24) & 0x40000000) == 0)))) &&
         ((uVar6 != 0 || ((*(uint *)(uVar3 + 0x24) & 0x80000000) == 0)))) &&
        ((uVar4 != 0 || (*(int *)(uVar3 + 8) == 0)))))) break;
    uVar3 = *(uint *)(uVar3 + 0x10);
  }
  *param_1 = uVar3;
  return 0;
}



/* 40764798 FUN_40764798 */

/* Boundary evidence: original MIPS .pdata 40764798..4076489f. Semantic name remains unreviewed. */

undefined4 FUN_40764798(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = param_1[3];
  if ((param_1[2] != 0) && (*(undefined4 **)(DAT_407660a0 + 0x28) != param_1)) {
    return 0x201;
  }
  if ((((param_1[6] != 0) || (param_1[8] != 0)) &&
      (iVar1 = FUN_40763cd8((int)param_1,4,0,0), iVar1 == 0)) &&
     (*(undefined4 **)(DAT_407660a0 + 0x28) != param_1)) {
    return 1;
  }
  puVar4 = *(undefined4 **)(iVar5 + 0x14);
  if (param_1 == puVar4) {
    *(undefined4 *)(iVar5 + 0x14) = param_1[1];
LAB_4076486c:
    *param_1 = 0x29a;
    LocalFree(param_1);
    uVar2 = 0;
  }
  else {
    if (puVar4 != (undefined4 *)0x0) {
      do {
        puVar3 = (undefined4 *)puVar4[1];
        if (param_1 == puVar3) break;
        puVar4 = puVar3;
      } while (puVar3 != (undefined4 *)0x0);
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = param_1[1];
        goto LAB_4076486c;
      }
    }
    uVar2 = 5;
  }
  return uVar2;
}



/* 407648a0 FUN_407648a0 */

/* Boundary evidence: original MIPS .pdata 407648a0..407649a7. Semantic name remains unreviewed. */

int FUN_407648a0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  BOOL BVar2;
  FARPROC lpfn;
  
  if (param_1 != 0) {
    if (((((*(uint *)(param_1 + 0x24) & 1) == 0) && (param_2 != 1)) && (param_2 != 2)) &&
       ((param_2 != 3 && (iVar1 = FUN_4076438c(param_1), iVar1 != 0)))) {
      return iVar1;
    }
    lpfn = *(FARPROC *)(param_1 + 0x44);
    if (lpfn != (FARPROC)0x0) {
      if (lpfn != (FARPROC)0xffffffff) {
        BVar2 = IsBadCodePtr(lpfn);
        if (BVar2 == 0) {
          iVar1 = (**(code **)(param_1 + 0x44))
                            (*(undefined4 *)(param_1 + 0x48),param_1,param_2,param_3,param_4);
          return iVar1;
        }
        *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
      }
      return 1;
    }
  }
  return 5;
}



/* 407649a8 FUN_407649a8 */

/* Boundary evidence: original MIPS .pdata 407649a8..40764ba7. Semantic name remains unreviewed. */

undefined4 FUN_407649a8(int param_1)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  FARPROC pFVar4;
  
  if ((*(uint *)(param_1 + 0x24) & 1) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    return 4;
  }
  pFVar4 = *(FARPROC *)(param_1 + 0x44);
  bVar1 = true;
  if (pFVar4 == (FARPROC)0x0) goto LAB_40764b64;
  if ((*(uint *)(param_1 + 0x24) & 0x10000000) == 0) {
    if (pFVar4 != (FARPROC)0xffffffff) {
      BVar2 = IsBadCodePtr(pFVar4);
      if (BVar2 == 0) {
        iVar3 = (**(code **)(param_1 + 0x44))(*(undefined4 *)(param_1 + 0x48),param_1,4,0,0);
        if (iVar3 == 0) {
          bVar1 = false;
          goto LAB_40764b40;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
      }
    }
    bVar1 = true;
    if (((((*(uint *)(param_1 + 0x24) & 1) != 0) || (iVar3 = FUN_4076438c(param_1), iVar3 == 0)) &&
        (pFVar4 = *(FARPROC *)(param_1 + 0x44), pFVar4 != (FARPROC)0x0)) &&
       (pFVar4 != (FARPROC)0xffffffff)) {
      BVar2 = IsBadCodePtr(pFVar4);
      if (BVar2 == 0) {
        (**(code **)(param_1 + 0x44))(*(undefined4 *)(param_1 + 0x48),param_1,5,0,0);
      }
      else {
        *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
      }
    }
    if ((((*(uint *)(param_1 + 0x24) & 1) != 0) || (iVar3 = FUN_4076438c(param_1), iVar3 == 0)) &&
       ((pFVar4 = *(FARPROC *)(param_1 + 0x44), pFVar4 != (FARPROC)0x0 &&
        (pFVar4 != (FARPROC)0xffffffff)))) {
      BVar2 = IsBadCodePtr(pFVar4);
      if (BVar2 == 0) {
        (**(code **)(param_1 + 0x44))(*(undefined4 *)(param_1 + 0x48),param_1,6,0,0);
      }
      else {
        *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
      }
    }
  }
LAB_40764b40:
  if (*(HMODULE *)(param_1 + 0x40) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0x40));
  }
  if (!bVar1) {
    return 1;
  }
LAB_40764b64:
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return 0;
}



/* 40764ba8 FUN_40764ba8 */

/* Boundary evidence: original MIPS .pdata 40764ba8..40764cd3. Semantic name remains unreviewed. */

int FUN_40764ba8(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_407660a0 = param_1[1];
  if ((((param_1[9] & 1) != 0) && (iVar1 = FUN_407649a8((int)param_1), iVar1 != 0)) &&
     (*(undefined4 **)(DAT_407660a0 + 0x24) != param_1)) {
    return iVar1;
  }
  if (param_1 == *(undefined4 **)(DAT_407660a0 + 0x20)) {
    *(undefined4 *)(DAT_407660a0 + 0x20) = param_1[4];
LAB_40764c44:
    param_1[4] = 0;
    if ((HLOCAL)param_1[0xc] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0xc]);
    }
    if ((HLOCAL)param_1[0xe] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0xe]);
    }
    if ((HLOCAL)param_1[0x5c] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0x5c]);
    }
    if ((HLOCAL)param_1[7] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[7]);
    }
    *param_1 = 0x29a;
    LocalFree(param_1);
    iVar1 = 0;
    *(int *)(DAT_407660a0 + 0x18) = *(int *)(DAT_407660a0 + 0x18) + 1;
  }
  else {
    puVar3 = *(undefined4 **)(DAT_407660a0 + 0x20);
    if (*(undefined4 **)(DAT_407660a0 + 0x20) != (undefined4 *)0x0) {
      do {
        puVar2 = (undefined4 *)puVar3[4];
        if (puVar2 == param_1) break;
        puVar3 = puVar2;
      } while (puVar2 != (undefined4 *)0x0);
      if (puVar3 != (undefined4 *)0x0) {
        puVar3[4] = param_1[4];
        goto LAB_40764c44;
      }
    }
    iVar1 = 5;
  }
  return iVar1;
}



/* 40764cd4 FUN_40764cd4 */

/* Boundary evidence: original MIPS .pdata 40764cd4..40764e63. Semantic name remains unreviewed. */

int FUN_40764cd4(undefined4 *param_1,undefined4 param_2,wchar_t *param_3,undefined4 param_4,
                undefined4 param_5,wchar_t *param_6)

{
  BOOL BVar1;
  undefined4 *puVar2;
  size_t sVar3;
  wchar_t *_Dest;
  int iVar4;
  int iVar5;
  
  BVar1 = IsBadWritePtr(param_1,4);
  if (BVar1 != 0) {
    return 0xb;
  }
  *param_1 = 0;
  puVar2 = LocalAlloc(0x40,0x178);
  if (puVar2 == (undefined4 *)0x0) {
    return 7;
  }
  puVar2[1] = DAT_407660a0;
  *puVar2 = 1;
  puVar2[3] = 0;
  puVar2[8] = param_5;
  puVar2[6] = 0;
  if (param_3 != (wchar_t *)0x0) {
    sVar3 = wcslen(param_3);
    _Dest = LocalAlloc(0,(sVar3 + 2) * 2);
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,param_3);
    }
    puVar2[7] = _Dest;
  }
  if (param_6 != (wchar_t *)0x0) {
    wcscpy((wchar_t *)(puVar2 + 0x14),param_6);
  }
  iVar4 = *(int *)(DAT_407660a0 + 0x20);
  if (*(int *)(DAT_407660a0 + 0x20) != 0) {
    do {
      iVar5 = *(int *)(iVar4 + 0x10);
      if (iVar5 == 0) break;
      iVar4 = iVar5;
    } while (iVar5 != 0);
    if (iVar4 != 0) {
      *(undefined4 **)(iVar4 + 0x10) = puVar2;
      goto LAB_40764dec;
    }
  }
  *(undefined4 **)(DAT_407660a0 + 0x20) = puVar2;
LAB_40764dec:
  iVar4 = FUN_40764034((int)puVar2);
  if ((iVar4 == 0) || (iVar4 = FUN_4076438c((int)puVar2), iVar4 == 0)) {
    *param_1 = puVar2;
    iVar4 = 0;
    *(int *)(DAT_407660a0 + 0x18) = *(int *)(DAT_407660a0 + 0x18) + 1;
  }
  else {
    FUN_40764ba8(puVar2);
  }
  return iVar4;
}



/* 40764e64 FUN_40764e64 */

/* Boundary evidence: original MIPS .pdata 40764e64..40765077. Semantic name remains unreviewed. */

int FUN_40764e64(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  BOOL BVar6;
  FARPROC lpfn;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  undefined1 auStack_38 [4];
  undefined4 local_34;
  undefined1 auStack_30 [4];
  undefined1 local_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [8];
  
  *param_1 = 0;
  if (((param_2[9] & 1) == 0) && (iVar3 = FUN_4076438c((int)param_2), iVar3 != 0)) {
    FUN_40764ba8(param_2);
    return iVar3;
  }
  if ((param_2[9] & 0x10000000) != 0) {
    return 5;
  }
  if ((param_2[9] & 0x80000000) != 0) {
    return 3;
  }
  puVar4 = LocalAlloc(0x40,0x24);
  if (puVar4 == (undefined4 *)0x0) {
    return 7;
  }
  *puVar4 = 2;
  puVar4[2] = 0;
  puVar4[3] = param_2;
  uVar5 = GetCallerProcess();
  puVar4[4] = uVar5;
  puVar4[5] = param_3;
  puVar4[1] = param_2[5];
  local_34 = 0x2001997;
  uVar7 = param_2[0x13];
  uVar9 = param_2[0x5d];
  local_3c = 0x63647561;
  puVar8 = param_2 + 0x14;
  puVar1 = auStack_40 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x24U >> (3 - uVar2) * 8;
  puVar1 = auStack_38 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_30 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_3 >> (3 - uVar2) * 8;
  puVar1 = local_2c + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_28 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | uVar7 >> (3 - uVar2) * 8;
  puVar1 = auStack_24 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)puVar8 >> (3 - uVar2) * 8;
  puVar1 = auStack_20 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | uVar9 >> (3 - uVar2) * 8;
  lpfn = (FARPROC)param_2[0x11];
  param_2[5] = puVar4;
  auStack_40 = (undefined1  [4])0x24;
  auStack_38 = (undefined1  [4])0x0;
  local_2c = (undefined1  [4])0x0;
  auStack_30 = (undefined1  [4])param_3;
  auStack_28 = (undefined1  [4])uVar7;
  auStack_24 = (undefined1  [4])puVar8;
  auStack_20._0_4_ = uVar9;
  if (lpfn == (FARPROC)0x0) {
    iVar3 = 5;
LAB_4076504c:
    if (iVar3 == 0) {
      FUN_40764798(puVar4);
      if (local_2c != (undefined1  [4])0x0) {
        return (int)local_2c;
      }
      return 1;
    }
  }
  else {
    if (lpfn != (FARPROC)0xffffffff) {
      BVar6 = IsBadCodePtr(lpfn);
      if (BVar6 == 0) {
        iVar3 = (*(code *)param_2[0x11])(param_2[0x12],param_2,3,0,auStack_40);
        goto LAB_4076504c;
      }
      param_2[0x11] = 0xffffffff;
    }
    iVar3 = 1;
  }
  puVar4[8] = iVar3;
  puVar4[7] = param_2[0x11];
  *param_1 = puVar4;
  return 0;
}



/* 40765078 FUN_40765078 */

/* Boundary evidence: original MIPS .pdata 40765078..40765097. Semantic name remains unreviewed. */

undefined4 FUN_40765078(LPCRITICAL_SECTION param_1)

{
  InitializeCriticalSection(param_1);
  return 1;
}



/* 40765098 FUN_40765098 */

/* Boundary evidence: original MIPS .pdata 40765098..407650b7. Semantic name remains unreviewed. */

undefined4 FUN_40765098(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return 1;
}



/* 407650b8 FUN_407650b8 */

/* Boundary evidence: original MIPS .pdata 407650b8..4076517f. Semantic name remains unreviewed. */

undefined4 FUN_407650b8(short *param_1)

{
  BOOL BVar1;
  ushort *lp;
  
  BVar1 = IsBadReadPtr(param_1,0x10);
  if (BVar1 == 0) {
    if (*param_1 == 1) {
      return 1;
    }
    lp = (ushort *)(param_1 + 8);
    BVar1 = IsBadReadPtr(lp,2);
    if (BVar1 == 0) {
      if (*lp == 0) {
        return 1;
      }
      BVar1 = IsBadReadPtr(lp,*lp + 2);
      if (BVar1 == 0) {
        return 1;
      }
    }
  }
  return 0;
}



/* 40765180 FUN_40765180 */

/* Boundary evidence: original MIPS .pdata 40765180..4076525b. Semantic name remains unreviewed. */

undefined4 FUN_40765180(uint *param_1,uint param_2)

{
  BOOL BVar1;
  uint uVar2;
  
  BVar1 = IsBadReadPtr(param_1,4);
  if (BVar1 != 0) {
    return 0;
  }
  uVar2 = *param_1;
  if (param_2 == 0) {
    if ((uVar2 != 0) && (uVar2 < 4)) {
      return 1;
    }
  }
  else if (param_2 == uVar2) {
    return 1;
  }
  return 0;
}



/* 4076525c FUN_4076525c */

/* Boundary evidence: original MIPS .pdata 4076525c..40765267. Semantic name remains unreviewed. */

undefined4 FUN_4076525c(void)

{
  return 1;
}



/* 40765268 FUN_40765268 */

bool FUN_40765268(int param_1)

{
  return param_1 != 0;
}



/* 4076531c FUN_4076531c */

/* Boundary evidence: original MIPS .pdata 4076531c..40765457. Semantic name remains unreviewed. */

int FUN_4076531c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_407660e8 != (code *)0x0) {
      iVar2 = (*DAT_407660e8)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_407653cc;
    FUN_407657b0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40761424(param_1,param_2);
  }
LAB_407653cc:
  if (((param_2 == 0) && (FUN_40765738(), iVar1 != 0)) && (DAT_407660e8 != (code *)0x0)) {
    iVar1 = (*DAT_407660e8)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40765458 FUN_40765458 */

/* Boundary evidence: original MIPS .pdata 40765458..40765483. Semantic name remains unreviewed. */

void FUN_40765458(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40765484 entry */

/* Boundary evidence: original MIPS .pdata 40765484..407654db. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_407654dc();
  }
  FUN_4076531c(param_1,param_2,param_3);
  return;
}



/* 407654dc FUN_407654dc */

/* Boundary evidence: original MIPS .pdata 407654dc..4076554f. Semantic name remains unreviewed. */

void FUN_407654dc(void)

{
  uint uVar1;
  
  if ((DAT_40766090 == 0) || (DAT_40766090 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40766090 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40766090 == 0) {
      DAT_40766090 = 0xb064;
    }
  }
  DAT_40766094 = ~DAT_40766090;
  return;
}



/* 40765550 FUN_40765550 */

/* Boundary evidence: original MIPS .pdata 40765550..407655a3. Semantic name remains unreviewed. */

void FUN_40765550(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_407655d0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 407655a4 FUN_407655a4 */

/* Boundary evidence: original MIPS .pdata 407655a4..407655cf. Semantic name remains unreviewed. */

undefined4 FUN_407655a4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40765550(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 407655d0 FUN_407655d0 */

/* Boundary evidence: original MIPS .pdata 407655d0..40765617. Semantic name remains unreviewed. */

void FUN_407655d0(uint param_1)

{
  if ((param_1 == DAT_40766090) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40765618 FUN_40765618 */

/* Boundary evidence: original MIPS .pdata 40765618..40765737. Semantic name remains unreviewed. */

void FUN_40765618(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_407660ac = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_407660e0;
    if (DAT_407660e0 != (undefined4 *)0x0) {
      while (DAT_407660dc = DAT_407660dc + -1, _Memory <= DAT_407660dc) {
        if ((code *)*DAT_407660dc != (code *)0x0) {
          (*(code *)*DAT_407660dc)();
          _Memory = DAT_407660e0;
        }
      }
      free(_Memory);
      DAT_407660dc = (undefined4 *)0x0;
      DAT_407660e0 = (undefined4 *)0x0;
    }
    FUN_4076575c((undefined4 *)&DAT_40761010,(undefined4 *)&DAT_40761014);
  }
  FUN_4076575c((undefined4 *)&DAT_40761018,(undefined4 *)&DAT_4076101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_407660e4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40765738 FUN_40765738 */

/* Boundary evidence: original MIPS .pdata 40765738..4076575b. Semantic name remains unreviewed. */

void FUN_40765738(void)

{
  FUN_40765618(0,0,1);
  return;
}



/* 4076575c FUN_4076575c */

/* Boundary evidence: original MIPS .pdata 4076575c..407657af. Semantic name remains unreviewed. */

void FUN_4076575c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 407657b0 FUN_407657b0 */

/* Boundary evidence: original MIPS .pdata 407657b0..407657eb. Semantic name remains unreviewed. */

void FUN_407657b0(void)

{
  FUN_4076575c((undefined4 *)&DAT_40761008,(undefined4 *)&DAT_4076100c);
  FUN_4076575c((undefined4 *)&DAT_40761000,(undefined4 *)&DAT_40761004);
  return;
}


