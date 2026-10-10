/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0691fec TSPI_providerInit */

undefined4 TSPI_providerInit(void)

{
  undefined4 in_stack_00000018;
  
                    /* 0x1fec  2  TSPI_providerInit */
  DAT_c069d354 = in_stack_00000018;
  return 0;
}



/* c0692004 TSPI_providerShutdown */

undefined4 TSPI_providerShutdown(void)

{
                    /* 0x2004  3  TSPI_providerShutdown */
  return 0;
}



/* c069203c FUN_c069203c */

/* Boundary evidence: original MIPS .pdata c069203c..c06920d7. Semantic name remains unreviewed. */

undefined4 FUN_c069203c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0694b7c(param_2);
  if (iVar1 == 0) {
    uVar2 = 0x80000018;
  }
  else if (*(int *)(iVar1 + 0x5d0) == 2) {
    FUN_c06942cc(iVar1,5);
    FUN_c069425c(iVar1,0);
    FUN_c069509c(iVar1,4,0);
    uVar2 = FUN_c0695224(iVar1,param_1);
  }
  else {
    uVar2 = 0x8000001c;
  }
  return uVar2;
}



/* c06920d8 FUN_c06920d8 */

/* Boundary evidence: original MIPS .pdata c06920d8..c0692173. Semantic name remains unreviewed. */

uint FUN_c06920d8(int param_1,undefined4 param_2)

{
  LPVOID pvVar1;
  uint uVar2;
  
  pvVar1 = (LPVOID)FUN_c0694b7c(param_2);
  if (pvVar1 == (LPVOID)0x0) {
    uVar2 = 0x80000018;
  }
  else if ((*(int *)((int)pvVar1 + 0x5d0) == 2) || (*(int *)((int)pvVar1 + 0x5d0) == 4)) {
    uVar2 = FUN_c06973d0(pvVar1,2,param_1);
    if ((uVar2 & 0x80000000) == 0) {
      uVar2 = FUN_c0695224((int)pvVar1,param_1);
    }
  }
  else {
    uVar2 = 0x8000001c;
  }
  return uVar2;
}



/* c0692174 FUN_c0692174 */

/* Boundary evidence: original MIPS .pdata c0692174..c0692273. Semantic name remains unreviewed. */

undefined4 FUN_c0692174(undefined4 param_1,undefined4 param_2,undefined4 param_3,LPHANDLE param_4)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  pvVar1 = (LPVOID)FUN_c0694b7c(param_1);
  if (pvVar1 == (LPVOID)0x0) {
LAB_c069219c:
    uVar2 = 0x80000048;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 0x5dc));
    *(undefined4 *)((int)pvVar1 + 0x4e0) = 0;
    *(undefined4 *)((int)pvVar1 + 0x4fc) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 0x5dc));
    uVar2 = 0xffffffff;
    iVar3 = FUN_c06973d0(pvVar1,0xff,-1);
    if (iVar3 != 0) {
      FUN_c0696b00((int)pvVar1,1,uVar2,param_4);
    }
    uVar4 = 0;
    do {
      if (*(int *)((int)pvVar1 + 0x748) == 0) break;
      Sleep(100);
      uVar4 = uVar4 + 100;
    } while (uVar4 < 10000);
    if (9999 < uVar4) {
      FUN_c0696b00((int)pvVar1,1,uVar2,param_4);
    }
    iVar3 = FUN_c0694bb8((int)pvVar1);
    if (iVar3 != 0) {
      uVar2 = *(undefined4 *)((int)pvVar1 + 0x4e4);
      *(undefined4 *)((int)pvVar1 + 0x4e4) = 0;
      *(undefined4 *)((int)pvVar1 + 0x4c8) = 0;
      iVar3 = DeactivateDevice(uVar2);
      if (iVar3 == 0) goto LAB_c069219c;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c0692274 FUN_c0692274 */

/* Boundary evidence: original MIPS .pdata c0692274..c06922c3. Semantic name remains unreviewed. */

undefined4 FUN_c0692274(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x80000048;
  }
  else {
    *(uint *)(iVar1 + 0x5b8) = *(uint *)(iVar1 + 0x5b8) & 0xfffffffc;
    *(undefined4 *)(iVar1 + 0x5bc) = 0;
    *(undefined4 *)(iVar1 + 0x5d8) = 0;
    uVar2 = 0;
  }
  return uVar2;
}



/* c06922c4 FUN_c06922c4 */

/* Boundary evidence: original MIPS .pdata c06922c4..c069238f. Semantic name remains unreviewed. */

undefined4 FUN_c06922c4(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x80000048;
  }
  else if ((~*(uint *)(iVar1 + 0x4d8) & param_2) == 0) {
    if (((((~*(uint *)(iVar1 + 0x4d0) & *(uint *)(param_3 + 4)) == 0) &&
         ((*(uint *)(param_3 + 0x10) & ~*(uint *)(iVar1 + 0x4d8)) == 0)) &&
        ((*(uint *)(param_3 + 0x18) & 0xfffffffe) == 0)) &&
       ((*(int *)(param_3 + 0xb0) == 0 || (*(int *)(param_3 + 0xb0) == 1)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x80000019;
    }
  }
  else {
    uVar2 = 0x8000002f;
  }
  return uVar2;
}



/* c0692390 FUN_c0692390 */

/* Boundary evidence: original MIPS .pdata c0692390..c06924cb. Semantic name remains unreviewed. */

undefined4
FUN_c0692390(int param_1,undefined4 param_2,LPCWSTR param_3,short *param_4,undefined4 param_5,
            uint *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((param_6 == (uint *)0x0) || (param_4 == (short *)0x0)) {
    uVar3 = 0x80000035;
  }
  else if (*param_6 < 0x18) {
    uVar3 = 0x8000004d;
  }
  else if ((param_3 == (LPCWSTR)0x0) || (iVar1 = FUN_c0694d8c(param_3), iVar1 != 0)) {
    puVar2 = FUN_c06949dc(param_1);
    if (puVar2 == (undefined4 *)0x0) {
      uVar3 = 0x80000042;
    }
    else if (*(short *)(puVar2 + 0x88) == *param_4) {
      param_6[2] = 0x18;
      param_6[1] = 0x2c4;
      if (0x2c3 < *param_6) {
        param_6[3] = 4;
        param_6[4] = 0x2ac;
        param_6[5] = 0x18;
        param_6[2] = 0x2c4;
        iVar1 = FUN_c069789c(param_2,(int)puVar2,param_4,param_6 + 6);
        if (iVar1 == 0) {
          uVar3 = 0x80000048;
        }
      }
    }
    else {
      uVar3 = 0x80000032;
    }
  }
  else {
    uVar3 = 0x80000023;
  }
  return uVar3;
}



/* c06924cc FUN_c06924cc */

/* Boundary evidence: original MIPS .pdata c06924cc..c069260b. Semantic name remains unreviewed. */

int FUN_c06924cc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *param_5;
  if (uVar4 == 0) {
    return -0x7fffffb7;
  }
  if (2 < uVar4) {
    if (uVar4 != 0xed000000) {
      return -0x7fffffb7;
    }
    if (param_1 != -0x13000000) {
      return -0x7fffffb8;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c069d360);
    bVar1 = DAT_c069d378 == 0;
    if (bVar1) {
      DAT_c069d378 = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c069d360);
    if (bVar1) {
      FUN_c0698848();
    }
    return 0;
  }
  iVar2 = FUN_c0694b7c(param_2);
  if (iVar2 == 0) {
    return -0x7fffffb8;
  }
  FUN_c06942cc(iVar2,6);
  if (*param_5 == 1) {
    iVar3 = FUN_c0698060(iVar2,(int)param_5);
  }
  else {
    if (*param_5 != 2) goto LAB_c06925cc;
    iVar3 = FUN_c06982d8(iVar2,(int)param_5);
  }
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_c06925cc:
  FUN_c069425c(iVar2,0);
  iVar2 = FUN_c0695224(iVar2,param_1);
  return iVar2;
}



/* c069260c FUN_c069260c */

/* Boundary evidence: original MIPS .pdata c069260c..c06926bf. Semantic name remains unreviewed. */

uint FUN_c069260c(int param_1,undefined4 param_2,ushort *param_3)

{
  LPVOID pvVar1;
  uint uVar2;
  
  pvVar1 = (LPVOID)FUN_c0694b7c(param_2);
  if (pvVar1 == (LPVOID)0x0) {
    uVar2 = 0x8000002b;
  }
  else if (*(int *)((int)pvVar1 + 0x5f0) == 4) {
    uVar2 = FUN_c0694e14((int)pvVar1,param_3,(ushort *)((int)pvVar1 + 0x508));
    if ((uVar2 == 0) && (uVar2 = FUN_c06973d0(pvVar1,4,param_1), (uVar2 & 0x80000000) == 0)) {
      uVar2 = FUN_c0695224((int)pvVar1,param_1);
    }
  }
  else {
    uVar2 = 0x8000001c;
  }
  return uVar2;
}



/* c06926c0 FUN_c06926c0 */

/* Boundary evidence: original MIPS .pdata c06926c0..c06927eb. Semantic name remains unreviewed. */

uint FUN_c06926c0(int param_1,undefined4 param_2)

{
  LPVOID pvVar1;
  uint uVar2;
  int iVar3;
  
  pvVar1 = (LPVOID)FUN_c0694b7c(param_2);
  if (pvVar1 == (LPVOID)0x0) {
    uVar2 = 0x80000018;
  }
  else if (*(int *)((int)pvVar1 + 0x5d0) == 1) {
    uVar2 = 0x8000001c;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 0x5dc));
    iVar3 = *(int *)((int)pvVar1 + 0x5fc);
    *(uint *)((int)pvVar1 + 0x5b8) = *(uint *)((int)pvVar1 + 0x5b8) & 0xfffffffd | 8;
    if (iVar3 != 0) {
      *(undefined4 *)((int)pvVar1 + 0x5fc) = 0;
      *(undefined4 *)((int)pvVar1 + 0x5f0) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 0x5dc));
    if (iVar3 == 0) {
      uVar2 = FUN_c06973d0(pvVar1,3,param_1);
    }
    else {
      FUN_c069509c((int)pvVar1,0x4000,1);
      FUN_c069509c((int)pvVar1,1,0);
      FUN_c06942cc((int)pvVar1,3);
      uVar2 = 0;
    }
    if (((uVar2 & 0x80000000) == 0) && (uVar2 = FUN_c0695224((int)pvVar1,param_1), iVar3 != 0)) {
      FUN_c069425c((int)pvVar1,0);
    }
  }
  return uVar2;
}



/* c06927ec FUN_c06927ec */

/* Boundary evidence: original MIPS .pdata c06927ec..c0692953. Semantic name remains unreviewed. */

undefined4 FUN_c06927ec(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  FUN_c0694be4(param_5,0xe4);
  puVar1 = FUN_c06949dc(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar3 = 0x80000042;
  }
  else if (param_2 == 0) {
    param_5[10] = 0x30;
    param_5[0x10] = 0xc31f;
    param_5[0xb] = 0x40;
    param_5[0xc] = 0x40;
    param_5[0xd] = 0x40;
    param_5[0xe] = 0x40;
    param_5[0xf] = 0x40;
    param_5[3] = param_1;
    param_5[8] = 1;
    param_5[0x11] = 0x20;
    param_5[0x12] = 8;
    param_5[0x13] = 0x10;
    param_5[0x14] = 0x1861;
    param_5[0x15] = 1;
    param_5[0x1a] = 0x10000;
    iVar2 = FUN_c0694b84((int)puVar1);
    if (iVar2 == 0) {
      param_5[0x1a] = param_5[0x1a] | 0x20;
    }
    param_5[0x1b] = 0x2000c5;
    if (*param_5 - param_5[2] < 0x4a) {
      param_5[0x31] = 0;
      param_5[0x32] = 0;
    }
    else {
      memcpy((void *)(param_5[2] + (int)param_5),L"tapi/line",0x4a);
      param_5[0x32] = param_5[2];
      param_5[0x31] = 0x4a;
      param_5[2] = param_5[2] + 0x4a;
    }
    param_5[1] = param_5[1] + 0x4a;
  }
  else {
    uVar3 = 0x80000011;
  }
  return uVar3;
}



/* c0692954 FUN_c0692954 */

/* Boundary evidence: original MIPS .pdata c0692954..c0692a27. Semantic name remains unreviewed. */

undefined4 FUN_c0692954(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  FUN_c0694be4(param_3,0x40);
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    uVar3 = 0x8000002b;
  }
  else if (param_2 == 0) {
    if ((*(uint *)(iVar1 + 0x5b8) & 2) == 0) {
      param_3[3] = 0;
      param_3[4] = 0;
    }
    else {
      param_3[3] = 1;
      param_3[4] = (uint)(*(int *)(iVar1 + 0x5d0) != 1);
    }
    iVar2 = 0;
    if ((*(uint *)(iVar1 + 0x5b8) & 1) == 0) {
      iVar2 = 2;
    }
    param_3[7] = iVar2;
  }
  else {
    uVar3 = 0x80000011;
  }
  return uVar3;
}



/* c0692a28 FUN_c0692a28 */

/* Boundary evidence: original MIPS .pdata c0692a28..c0692b13. Semantic name remains unreviewed. */

undefined4 FUN_c0692a28(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_c0694be4(param_2,0x148);
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    uVar3 = 0x80000018;
  }
  else {
    uVar3 = 0;
    param_2[4] = *(int *)(iVar1 + 0xc);
    param_2[5] = 0;
    param_2[6] = *(int *)(iVar1 + 0x4d4);
    param_2[7] = *(int *)(iVar1 + 0x71c);
    param_2[8] = *(int *)(iVar1 + 0x4dc);
    param_2[9] = 0;
    iVar2 = 0xc107;
    if ((*(uint *)(iVar1 + 0x5b8) & 4) == 0) {
      iVar2 = 0xc319;
    }
    param_2[0xd] = iVar2;
    iVar2 = 0x80;
    if ((*(uint *)(iVar1 + 0x5b8) & 4) == 0) {
      iVar2 = 1;
    }
    param_2[0x14] = iVar2;
    iVar2 = 0x800;
    if ((*(uint *)(iVar1 + 0x5b8) & 4) == 0) {
      iVar2 = 1;
    }
    param_2[0x15] = iVar2;
    param_2[0x1b] = 0x40;
    param_2[0x20] = 0x40;
    param_2[0x25] = 0x40;
    param_2[0x2a] = 0x40;
    param_2[0x2f] = 0x40;
    param_2[0x51] = 1;
  }
  return uVar3;
}



/* c0692b14 FUN_c0692b14 */

/* Boundary evidence: original MIPS .pdata c0692b14..c0692c8b. Semantic name remains unreviewed. */

undefined4 FUN_c0692b14(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  FUN_c0694be4(param_2,0x38);
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    return 0x80000018;
  }
  uVar2 = *(uint *)(iVar1 + 0x5d0);
  param_2[3] = uVar2;
  param_2[4] = *(int *)(iVar1 + 0x5d4);
  if (*(int *)(iVar1 + 0x5fc) != 0) {
    return 0;
  }
  if (uVar2 < 0x101) {
    if (uVar2 == 0x100) {
      param_2[6] = 0x200080;
      return 0;
    }
    if (uVar2 == 2) {
      param_2[6] = 0x200081;
      if ((*(uint *)(iVar1 + 0x4dc) & 0x10) == 0) {
        return 0;
      }
      iVar1 = 0x200085;
    }
    else {
      if (uVar2 != 4) {
        if (uVar2 == 8) goto LAB_c0692c6c;
        if (uVar2 == 0x10) {
          param_2[6] = 0x80;
          if (*(int *)(iVar1 + 0x5f0) != 4) {
            return 0;
          }
          param_2[6] = 0xc0;
          return 0;
        }
        goto LAB_c0692c64;
      }
      param_2[6] = 0x200080;
      if ((*(uint *)(iVar1 + 0x4dc) & 0x10) == 0) {
        return 0;
      }
      iVar1 = 0x200084;
    }
    param_2[6] = iVar1;
  }
  else {
    if (((uVar2 == 0x200) || (uVar2 == 0x4000)) || (uVar2 == 0x8000)) {
LAB_c0692c6c:
      param_2[6] = 0x80;
      return 0;
    }
LAB_c0692c64:
    param_2[6] = 0;
  }
  return 0;
}



/* c0692c8c FUN_c0692c8c */

/* Boundary evidence: original MIPS .pdata c0692c8c..c0692ecf. Semantic name remains unreviewed. */

undefined4 FUN_c0692c8c(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  FUN_c0694be4((int *)param_4,0x124);
  puVar1 = FUN_c06949dc(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x80000042;
  }
  else {
    sVar3 = wcslen((wchar_t *)((int)puVar1 + 0x112));
    uVar4 = param_4[2];
    uVar6 = (sVar3 + 1) * 2;
    uVar5 = *param_4 - uVar4;
    param_4[1] = uVar4 + uVar6 + 0x60;
    if (uVar5 < 8) {
      param_4[0x39] = 0;
      param_4[0x3a] = 0;
      param_4[1] = uVar4 + uVar6 + 0x62;
    }
    else {
      uVar2 = puVar1[0x87];
      *(undefined4 *)(uVar4 + (int)param_4) = puVar1[0x86];
      ((undefined4 *)(uVar4 + (int)param_4))[1] = uVar2;
      uVar5 = uVar5 - 8;
      param_4[0x3a] = param_4[2];
      param_4[0x39] = 8;
      param_4[2] = param_4[2] + 8;
    }
    if ((int)uVar5 < (int)uVar6) {
      param_4[8] = 0;
      param_4[9] = 0;
    }
    else {
      wcscpy((wchar_t *)(param_4[2] + (int)param_4),(wchar_t *)((int)puVar1 + 0x112));
      uVar5 = uVar5 + (sVar3 + 1) * -2;
      param_4[9] = param_4[2];
      param_4[8] = uVar6;
      param_4[2] = param_4[2] + uVar6;
    }
    if ((int)uVar5 < 0x12) {
      param_4[3] = 0;
      param_4[4] = 0;
    }
    else {
      wcscpy((wchar_t *)(param_4[2] + (int)param_4),L"UNIMODEM");
      param_4[4] = param_4[2];
      uVar5 = uVar5 - 0x12;
      param_4[3] = 0x12;
      param_4[2] = param_4[2] + 0x12;
    }
    param_4[10] = 3;
    param_4[7] = 0;
    param_4[0xb] = 1;
    param_4[0xc] = 1;
    param_4[0xe] = puVar1[0x1c6];
    param_4[0xd] = puVar1[0x134];
    param_4[0xf] = puVar1[0x136];
    uVar4 = puVar1[0x1c5];
    param_4[0x20] = 0x10406ce;
    param_4[0x1c] = uVar4 | 0x60;
    param_4[0x1f] = 1;
    param_4[0x1d] = 1;
    param_4[0x3b] = 8;
    if (0x123 < *param_4) {
      param_4[0x3c] = 0;
      if ((int)uVar5 < 0x4a) {
        param_4[0x3d] = 0;
        param_4[0x3e] = 0;
      }
      else {
        memcpy((void *)(param_4[2] + (int)param_4),L"tapi/line",0x4a);
        param_4[0x3e] = param_4[2];
        param_4[0x3d] = 0x4a;
        param_4[2] = param_4[2] + 0x4a;
      }
      param_4[0x43] = 1;
      param_4[0x48] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c0692ed0 FUN_c0692ed0 */

/* Boundary evidence: original MIPS .pdata c0692ed0..c0692fb3. Semantic name remains unreviewed. */

undefined4 FUN_c0692ed0(int param_1,uint *param_2,LPCWSTR param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if ((param_3 == (LPCWSTR)0x0) || (iVar1 = FUN_c0694d8c(param_3), iVar1 != 0)) {
    if (param_2 == (uint *)0x0) {
      uVar2 = 0x80000035;
    }
    else if (*param_2 < 0x18) {
      uVar2 = 0x8000004d;
    }
    else {
      puVar3 = FUN_c06949dc(param_1);
      if (puVar3 == (undefined4 *)0x0) {
        uVar2 = 0x80000042;
      }
      else {
        param_2[1] = 0x2c4;
        param_2[2] = 0x18;
        if (0x2c3 < *param_2) {
          FUN_c06945f8((int)puVar3,(short *)(param_2 + 6));
          param_2[5] = 0x18;
          param_2[4] = 0x2ac;
          param_2[3] = 4;
          param_2[2] = param_2[2] + 0x2ac;
        }
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0x80000023;
  }
  return uVar2;
}



/* c0692fb4 FUN_c0692fb4 */

/* Boundary evidence: original MIPS .pdata c0692fb4..c0693057. Semantic name remains unreviewed. */

undefined4 FUN_c0692fb4(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  uVar3 = 0x8000004b;
  if (DAT_c069d374 == 0) {
    iVar1 = WaitForAPIReady(0x51,0);
    if ((iVar1 != 0) ||
       (pcVar2 = (code *)GetProcAddressW(DAT_c069d37c,L"LoadIconW"), pcVar2 == (code *)0x0))
    goto LAB_c0693030;
    DAT_c069d374 = (*pcVar2)(DAT_c069d340,1);
  }
  uVar3 = 0;
LAB_c0693030:
  *param_3 = DAT_c069d374;
  return uVar3;
}



/* c0693058 FUN_c0693058 */

/* Boundary evidence: original MIPS .pdata c0693058..c069332b. Semantic name remains unreviewed. */

undefined4
FUN_c0693058(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int *param_5,
            wchar_t *param_6)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  HANDLE hTargetProcessHandle;
  BOOL BVar4;
  undefined4 uVar5;
  wchar_t *_Source;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined **ppuVar9;
  HANDLE local_30 [2];
  
  local_30[0] = (HANDLE)0x0;
  uVar8 = 4;
  if (param_4 == 1) {
LAB_c06930e4:
    iVar1 = FUN_c0694b7c(param_1);
    if (iVar1 == 0) {
      return 0x8000002b;
    }
  }
  else {
    if (param_4 == 2) {
      if (param_2 != 0) {
        return 0x80000011;
      }
      goto LAB_c06930e4;
    }
    if (param_4 != 4) {
      return 0x80000048;
    }
    iVar1 = FUN_c0694b7c(param_3);
    if (iVar1 == 0) {
      return 0x80000018;
    }
  }
  ppuVar9 = &PTR_u_tapi_line_c0691088;
  iVar6 = 0;
  do {
    iVar2 = _wcsicmp(param_6,(wchar_t *)*ppuVar9);
    if (iVar2 == 0) break;
    iVar6 = iVar6 + 1;
    ppuVar9 = ppuVar9 + 2;
  } while (iVar6 < 4);
  if (iVar6 != 0) {
    if (iVar6 == 1) {
      sVar3 = wcslen((wchar_t *)(iVar1 + 0x112));
      iVar2 = sVar3 + 1;
    }
    else {
      if (iVar6 != 2) {
        if (iVar6 != 3) {
          return 0x80000048;
        }
        uVar8 = 0xc;
        goto LAB_c0693184;
      }
      sVar3 = wcslen((wchar_t *)(iVar1 + 0x112));
      iVar2 = sVar3 + 3;
    }
    uVar8 = iVar2 << 1;
  }
LAB_c0693184:
  param_5[1] = uVar8 + 0x18;
  param_5[3] = *(int *)(&UNK_c069108c + iVar6 * 8);
  if (uVar8 <= (uint)(*param_5 - param_5[2])) {
    param_5[4] = uVar8;
    param_5[5] = 0x18;
    param_5[2] = param_5[2] + uVar8;
    if (iVar6 == 0) {
      param_5[6] = *(int *)(iVar1 + 0xc);
    }
    else if (iVar6 == 1) {
      wcsncpy((wchar_t *)(param_5 + 6),(wchar_t *)(iVar1 + 0x112),uVar8 >> 1);
    }
    else {
      if (iVar6 == 2) {
        piVar7 = param_5 + 6;
        iVar6 = *(int *)(iVar1 + 0x4e8);
        *piVar7 = 0;
        if (iVar6 != -1) {
          if (*(int *)(iVar1 + 0x4ec) == 0) {
            hTargetProcessHandle = (HANDLE)GetCallerProcess();
            BVar4 = DuplicateHandle((HANDLE)0x42,*(HANDLE *)(iVar1 + 0x4e8),hTargetProcessHandle,
                                    local_30,0,0,2);
            if (BVar4 != 0) {
              CloseHandle(*(HANDLE *)(iVar1 + 0x4e8));
              uVar5 = GetCallerProcess();
              *(undefined4 *)(iVar1 + 0x4ec) = uVar5;
              *(HANDLE *)(iVar1 + 0x4e8) = local_30[0];
              *piVar7 = (int)local_30[0];
            }
          }
          else {
            iVar6 = GetCallerProcess();
            if (*(int *)(iVar1 + 0x4ec) == iVar6) {
              *piVar7 = *(int *)(iVar1 + 0x4e8);
            }
          }
        }
        _Source = (wchar_t *)(iVar1 + 0x112);
      }
      else {
        if (iVar6 != 3) {
          return 0;
        }
        if (*(int *)(iVar1 + 0x4e8) == -1) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(iVar1 + 0x4f4);
        }
        param_5[6] = iVar1;
        _Source = L"com";
      }
      wcscpy((wchar_t *)(param_5 + 7),_Source);
    }
  }
  return 0;
}



/* c069332c FUN_c069332c */

/* Boundary evidence: original MIPS .pdata c069332c..c06933d7. Semantic name remains unreviewed. */

undefined4 FUN_c069332c(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_c0694be4(param_2,0x58);
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x8000002b;
  }
  else {
    uVar2 = 0;
    if ((*(uint *)(iVar1 + 0x5b8) & 2) == 0) {
      param_2[5] = 0;
      iVar3 = 0;
      if ((*(uint *)(iVar1 + 0x5b8) & 1) == 0) {
        iVar3 = 8;
      }
      param_2[8] = iVar3;
    }
    else {
      param_2[5] = 1;
      param_2[8] = 0;
    }
    param_2[0xb] = 0xffff;
    param_2[0xc] = 0xffff;
    param_2[0xd] = 2;
    param_2[0xe] = 1;
  }
  return uVar2;
}



/* c06933d8 FUN_c06933d8 */

/* Boundary evidence: original MIPS .pdata c06933d8..c069341b. Semantic name remains unreviewed. */

undefined4 FUN_c06933d8(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x8000002b;
  }
  else {
    *param_2 = 1;
    uVar2 = 0;
  }
  return uVar2;
}



/* c069341c FUN_c069341c */

/* Boundary evidence: original MIPS .pdata c069341c..c06934b7. Semantic name remains unreviewed. */

undefined4 FUN_c069341c(int param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((param_1 == -1) || (puVar1 = FUN_c06949dc(param_1), puVar1 != (undefined4 *)0x0)) {
    if ((param_2 < 0x20001) && (0x1ffff < param_3)) {
      *param_4 = 0x20000;
      uVar2 = 0;
    }
    else {
      *param_4 = 0;
      uVar2 = 0x8000000c;
    }
  }
  else {
    uVar2 = 0x80000042;
  }
  return uVar2;
}



/* c06934b8 FUN_c06934b8 */

/* Boundary evidence: original MIPS .pdata c06934b8..c069372f. Semantic name remains unreviewed. */

undefined4
FUN_c06934b8(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  HRESULT HVar6;
  undefined4 uVar7;
  LSTATUS LVar8;
  size_t sVar9;
  HKEY local_240;
  BYTE local_23c [4];
  int local_238 [2];
  undefined1 auStack_230 [4];
  undefined2 local_22c;
  undefined2 local_22a;
  wchar_t awStack_228 [259];
  undefined2 local_22;
  uint local_20;
  
  local_20 = DAT_c069d168;
  puVar4 = FUN_c06949dc(param_1);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_c069bce8(local_20);
    return 0x80000042;
  }
  FUN_c06986a4((int)puVar4);
  iVar5 = FUN_c0694bb8((int)puVar4);
  if (iVar5 == 0) {
LAB_c06936dc:
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar4 + 0x177));
    puVar4[0x13b] = 0;
    *param_3 = puVar4;
    puVar4[0x140] = param_5;
    puVar4[0x13f] = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar4 + 0x177));
    FUN_c069bce8(local_20);
    uVar7 = 0;
  }
  else {
    local_23c[0] = '\x02';
    local_23c[1] = '\0';
    local_23c[2] = '\0';
    local_23c[3] = '\0';
    local_238[0] = *(ushort *)((int)puVar4 + 0x16) - 0x30;
    auStack_230 = (undefined1  [4])puVar4[4];
    uVar2 = *(undefined2 *)(puVar4 + 5);
    puVar1 = auStack_230 + 3;
    uVar3 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar3) =
         *(uint *)(puVar1 + -uVar3) & -1 << (uVar3 + 1) * 8 | (uint)auStack_230 >> (3 - uVar3) * 8;
    local_240 = (HKEY)0x0;
    local_22a = 0;
    local_22c = uVar2;
    HVar6 = StringCchPrintfW(awStack_228,0x104,
                             L"Software\\Microsoft\\Unimodem\\RegisteredCOMPorts\\%s%d",auStack_230,
                             local_238[0]);
    if (HVar6 == 0) {
      local_22 = 0;
      LVar8 = RegCreateKeyExW((HKEY)0x80000002,awStack_228,0,(LPWSTR)0x0,0,0,
                              (LPSECURITY_ATTRIBUTES)0x0,&local_240,(LPDWORD)0x0);
      if (LVar8 == 0) {
        sVar9 = wcslen((wchar_t *)(puVar4 + 0x10e));
        RegSetValueExW(local_240,L"Dll",0,1,(BYTE *)(puVar4 + 0x10e),(sVar9 + 1) * 2);
        sVar9 = wcslen((wchar_t *)auStack_230);
        RegSetValueExW(local_240,L"Prefix",0,1,auStack_230,(sVar9 + 1) * 2);
        RegSetValueExW(local_240,L"Index",0,4,(BYTE *)local_238,4);
        RegSetValueExW(local_240,L"Flags",0,4,local_23c,4);
        RegCloseKey(local_240);
        iVar5 = ActivateDeviceEx(awStack_228,0,0,(int)puVar4 + 0x44a);
        puVar4[0x139] = iVar5;
        puVar4[0x132] = iVar5;
        if (iVar5 != 0) goto LAB_c06936dc;
      }
    }
    else {
      SetLastError(0x57);
    }
    FUN_c069bce8(local_20);
    uVar7 = 0x80000032;
  }
  return uVar7;
}



/* c0693730 FUN_c0693730 */

/* Boundary evidence: original MIPS .pdata c0693730..c0693823. Semantic name remains unreviewed. */

undefined4 FUN_c0693730(int param_1,short *param_2,uint param_3,LPCWSTR param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar2 = FUN_c0694d8c(param_4);
  if (iVar2 == 0) {
    uVar3 = 0x80000023;
  }
  else if (param_2 == (short *)0x0) {
    uVar3 = 0x80000035;
  }
  else {
    puVar4 = FUN_c06949dc(param_1);
    if (puVar4 == (undefined4 *)0x0) {
      uVar3 = 0x80000042;
    }
    else {
      sVar1 = *param_2;
      if ((((sVar1 == 0x10) || (sVar1 == 0x20)) || (sVar1 == 0x30)) && (param_3 < 0x2ad)) {
        if (param_3 < 0x18) {
          uVar3 = 0x8000004d;
        }
        else {
          FUN_c0694474(param_2,param_3,(short *)(puVar4 + 0x88));
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0x80000032;
      }
    }
  }
  return uVar3;
}



/* c0693824 FUN_c0693824 */

/* Boundary evidence: original MIPS .pdata c0693824..c069392f. Semantic name remains unreviewed. */

int FUN_c0693824(undefined4 param_1,uint param_2)

{
  LPVOID pvVar1;
  int iVar2;
  
  pvVar1 = (LPVOID)FUN_c0694b7c(param_1);
  if (pvVar1 == (LPVOID)0x0) {
    return -0x7fffffd5;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 0x5dc));
  if ((~(*(uint *)((int)pvVar1 + 0x4d8) & 0xfffefffb) & param_2) == 0) {
    if (*(int *)((int)pvVar1 + 0x4e0) == 0) {
      if (param_2 != 0) {
        *(uint *)((int)pvVar1 + 0x4e0) = param_2;
        iVar2 = FUN_c06973d0(pvVar1,0xfe,-1);
        if (iVar2 != 0) {
          *(undefined4 *)((int)pvVar1 + 0x4e0) = 0;
        }
        goto LAB_c069390c;
      }
    }
    else if ((param_2 == 0) &&
            ((*(int *)((int)pvVar1 + 0x5f0) == 0xb || (*(int *)((int)pvVar1 + 0x5f0) == 10)))) {
      *(undefined4 *)((int)pvVar1 + 0x4e0) = 0;
      FUN_c06973d0(pvVar1,0xff,-1);
    }
    *(uint *)((int)pvVar1 + 0x4e0) = param_2;
    iVar2 = 0;
  }
  else {
    iVar2 = -0x7fffffd1;
  }
LAB_c069390c:
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 0x5dc));
  return iVar2;
}



/* c0693930 FUN_c0693930 */

/* Boundary evidence: original MIPS .pdata c0693930..c06939bf. Semantic name remains unreviewed. */

undefined4 FUN_c0693930(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x80000018;
  }
  else if ((~*(uint *)(iVar1 + 0x4d8) & param_2) == 0) {
    uVar2 = 0;
    if (*(uint *)(iVar1 + 0x4dc) != param_2) {
      *(uint *)(iVar1 + 0x4dc) = param_2;
      FUN_c069502c(iVar1,*(undefined4 *)(iVar1 + 0x5bc),1,0x10);
    }
  }
  else {
    uVar2 = 0x8000002f;
  }
  return uVar2;
}



/* c06939c0 FUN_c06939c0 */

/* Boundary evidence: original MIPS .pdata c06939c0..c0693a03. Semantic name remains unreviewed. */

undefined4 FUN_c06939c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0694b7c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x8000002b;
  }
  else {
    uVar2 = 0;
    *(undefined4 *)(iVar1 + 0x724) = param_2;
  }
  return uVar2;
}



/* c0693a04 FUN_c0693a04 */

/* Boundary evidence: original MIPS .pdata c0693a04..c0693a3b. Semantic name remains unreviewed. */

int FUN_c0693a04(HKEY param_1,LPCWSTR param_2,wchar_t *param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = -1;
  piVar1 = FUN_c06952d8(param_1,param_2,param_3);
  if (piVar1 != (int *)0x0) {
    iVar2 = piVar1[3];
  }
  return iVar2;
}



/* c0693a3c FUN_c0693a3c */

/* Boundary evidence: original MIPS .pdata c0693a3c..c0693af7. Semantic name remains unreviewed. */

undefined4 FUN_c0693a3c(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == -1) {
    uVar2 = 0x80000002;
  }
  else {
    uVar2 = 0x80000048;
    puVar1 = FUN_c06949dc(param_1);
    if ((puVar1 != (undefined4 *)0x0) && (*(short *)((int)puVar1 + 0x21a) != 0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x177));
      puVar1[0x17c] = 0;
      puVar1[0x138] = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x177));
      FUN_c069502c((int)puVar1,0,8,0x1000088);
      RegCloseKey((HKEY)puVar1[0x85]);
      uVar2 = 0;
      *(undefined2 *)((int)puVar1 + 0x21a) = 0;
    }
  }
  return uVar2;
}



/* c0693af8 FUN_c0693af8 */

/* Boundary evidence: original MIPS .pdata c0693af8..c0693b3b. Semantic name remains unreviewed. */

undefined4 FUN_c0693af8(wchar_t *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80000048;
  puVar1 = FUN_c0694a14(param_1,(wchar_t *)0x0);
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = FUN_c0693a3c(puVar1[3]);
  }
  return uVar2;
}



/* c0693b3c FUN_c0693b3c */

/* Boundary evidence: original MIPS .pdata c0693b3c..c0693b87. Semantic name remains unreviewed. */

undefined4 FUN_c0693b3c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    FUN_c0694c38();
    DAT_c069d340 = param_1;
  }
  return 1;
}



/* c0693b88 FUN_c0693b88 */

/* Boundary evidence: original MIPS .pdata c0693b88..c0693fa7. Semantic name remains unreviewed. */

uint FUN_c0693b88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 ushort *param_5,undefined4 param_6,int param_7)

{
  bool bVar1;
  LPVOID pvVar2;
  int iVar3;
  LSTATUS LVar4;
  uint uVar5;
  uint uVar6;
  wchar_t *_Dest;
  DWORD local_78 [2];
  _DCB _Stack_70;
  wchar_t awStack_50 [16];
  uint local_30;
  
  local_30 = DAT_c069d168;
  bVar1 = false;
  pvVar2 = (LPVOID)FUN_c0694b7c(param_2);
  if (pvVar2 == (LPVOID)0x0) {
    FUN_c069bce8(local_30);
    return 0x8000002b;
  }
  if ((*(uint *)((int)pvVar2 + 0x5b8) & 1) != 0) {
    FUN_c069bce8(local_30);
    return 0x80000005;
  }
  uVar6 = *(uint *)((int)pvVar2 + 0x5f8) & 0xfffffdff;
  *(uint *)((int)pvVar2 + 0x5f8) = uVar6;
  if (param_7 == 0) {
    *(undefined4 *)((int)pvVar2 + 0x4dc) = 0x10;
    *(uint *)((int)pvVar2 + 0x4d4) = *(uint *)((int)pvVar2 + 0x4d0) & 0xffffffbf;
  }
  else {
    if ((~*(uint *)((int)pvVar2 + 0x4d8) & *(uint *)(param_7 + 0x10)) != 0) {
LAB_c0693c58:
      FUN_c069bce8(local_30);
      return 0x8000002f;
    }
    uVar5 = *(uint *)(param_7 + 4);
    if ((~*(uint *)((int)pvVar2 + 0x4d0) & uVar5) != 0) {
      FUN_c069bce8(local_30);
      return 0x80000016;
    }
    if ((uVar5 & 0x40) == 0) {
      if ((*(uint *)(param_7 + 0x10) & 0x10) == 0) goto LAB_c0693c58;
    }
    else {
      bVar1 = true;
    }
    *(uint *)((int)pvVar2 + 0x4d4) = uVar5;
    *(undefined4 *)((int)pvVar2 + 0x4dc) = *(undefined4 *)(param_7 + 0x10);
    if ((*(uint *)(param_7 + 0x14) & 2) == 0) {
      *(uint *)((int)pvVar2 + 0x5f8) = uVar6 | 0x200;
    }
    if ((*(int *)(param_7 + 0xb0) != 0) && (*(int *)(param_7 + 0xb0) != 1)) {
      FUN_c069bce8(local_30);
      return 0x80000010;
    }
    if (((*(uint *)(param_7 + 0x94) != 0) && (*(int *)(param_7 + 0x8c) != 0)) &&
       (iVar3 = FUN_c0693730(*(int *)((int)pvVar2 + 0xc),
                             (short *)(*(int *)(param_7 + 0x98) + param_7),*(uint *)(param_7 + 0x94)
                             ,(LPCWSTR)(*(int *)(param_7 + 0x90) + param_7)), iVar3 == 0)) {
      GetCommState(*(HANDLE *)((int)pvVar2 + 0x4e8),&_Stack_70);
      FUN_c06958d4((int)&_Stack_70,(int)pvVar2 + 0x220);
      SetCommState(*(HANDLE *)((int)pvVar2 + 0x4e8),&_Stack_70);
    }
  }
  if (!bVar1) {
    iVar3 = FUN_c0694b84((int)pvVar2);
    if ((iVar3 == 0) && ((*(ushort *)((int)pvVar2 + 0x230) & 4) == 0)) {
      _Dest = (wchar_t *)((int)pvVar2 + 0x508);
      uVar6 = FUN_c0694e14((int)pvVar2,param_5,(ushort *)_Dest);
      if (uVar6 != 0) goto LAB_c0693f6c;
      if (*_Dest == L'\0') {
        local_78[0] = 0x20;
        LVar4 = FUN_c0698484((int)pvVar2,L"Settings",L"DialSuffix",1,(LPBYTE)awStack_50,local_78);
        if (LVar4 != 0) {
          wcscpy(awStack_50,L";");
        }
        wcscpy(_Dest,awStack_50);
      }
    }
    else {
      *(undefined2 *)((int)pvVar2 + 0x508) = 0;
      if ((*(ushort *)((int)pvVar2 + 0x230) & 4) != 0) {
        *(uint *)((int)pvVar2 + 0x5f8) = *(uint *)((int)pvVar2 + 0x5f8) | 0x200;
      }
    }
  }
  *(undefined4 *)((int)pvVar2 + 0x5bc) = param_3;
  *(undefined4 *)((int)pvVar2 + 0x5b8) = 1;
  *param_4 = pvVar2;
  if (bVar1) {
    *(undefined4 *)((int)pvVar2 + 0x5fc) = 1;
    FUN_c06973d0(pvVar2,0xff,-1);
  }
  uVar6 = FUN_c0695b68((int)pvVar2);
  if ((uVar6 == 0) || (uVar6 == 0x80000001)) {
    FUN_c069509c((int)pvVar2,0x8000,0);
    if (bVar1) {
      if ((*(int *)((int)pvVar2 + 0x5f0) == 0) || (*(int *)((int)pvVar2 + 0x5f0) == 0xb)) {
        *(undefined4 *)((int)pvVar2 + 0x5f0) = 9;
        FUN_c06942cc((int)pvVar2,1);
        FUN_c069509c((int)pvVar2,0x100,1);
        EventModify(*(undefined4 *)((int)pvVar2 + 0x5cc),3);
        uVar6 = 0;
      }
      else {
        uVar6 = 0x80000048;
      }
    }
    else {
      *(undefined4 *)((int)pvVar2 + 0x5f0) = 6;
      uVar6 = FUN_c06973d0(pvVar2,1,param_1);
    }
  }
  if ((uVar6 >> 0x10 & 0x8000) == 0) {
    uVar6 = FUN_c0695224((int)pvVar2,param_1);
    if (bVar1) {
      FUN_c069425c((int)pvVar2,0);
    }
  }
  else {
    *(undefined4 *)((int)pvVar2 + 0x5bc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x5b8) = 0;
    *param_4 = 0;
  }
LAB_c0693f6c:
  FUN_c069bce8(local_30);
  return uVar6;
}



/* c0693fa8 TSPI_lineGetProcTable */

undefined4 TSPI_lineGetProcTable(undefined4 *param_1)

{
  undefined4 *puVar1;
  
                    /* 0x3fa8  1  TSPI_lineGetProcTable */
  puVar1 = &DAT_c069d1a0;
  if (DAT_c069d1b0 != FUN_c0692174) {
    do {
      *puVar1 = &LAB_c0692030;
      puVar1 = puVar1 + 1;
    } while (puVar1 != (undefined4 *)0xc069d334);
    DAT_c069d1a0 = FUN_c069203c;
    DAT_c069d1a8 = FUN_c06920d8;
    DAT_c069d1b0 = FUN_c0692174;
    DAT_c069d1b4 = FUN_c0692274;
    DAT_c069d1c0 = FUN_c06922c4;
    DAT_c069d1c8 = FUN_c06924cc;
    DAT_c069d1d0 = FUN_c069260c;
    DAT_c069d1d4 = FUN_c06926c0;
    DAT_c069d1e8 = FUN_c06927ec;
    DAT_c069d1f0 = FUN_c0692954;
    DAT_c069d1f8 = FUN_c0692a28;
    DAT_c069d1fc = FUN_c0692b14;
    DAT_c069d200 = FUN_c0692c8c;
    DAT_c069d204 = FUN_c0692ed0;
    DAT_c069d20c = FUN_c0692fb4;
    DAT_c069d210 = FUN_c0693058;
    DAT_c069d214 = FUN_c069332c;
    DAT_c069d218 = FUN_c06933d8;
    DAT_c069d220 = FUN_c0693b88;
    DAT_c069d234 = FUN_c069341c;
    DAT_c069d238 = FUN_c06934b8;
    DAT_c069d268 = FUN_c0693730;
    DAT_c069d270 = FUN_c0693930;
    DAT_c069d274 = FUN_c06939c0;
    DAT_c069d298 = TSPI_providerInit;
    DAT_c069d29c = TSPI_providerShutdown;
    DAT_c069d2a4 = TSPI_providerShutdown;
    DAT_c069d2a8 = &LAB_c069200c;
    DAT_c069d2b4 = FUN_c0693a04;
    DAT_c069d2b8 = FUN_c0693a3c;
    DAT_c069d2c0 = FUN_c0692390;
    DAT_c069d324 = FUN_c0693af8;
    DAT_c069d264 = FUN_c0693824;
  }
  *param_1 = &DAT_c069d1a0;
  return 0;
}



/* c0694174 FUN_c0694174 */

/* Boundary evidence: original MIPS .pdata c0694174..c06941d3. Semantic name remains unreviewed. */

void FUN_c0694174(int *param_1,int *param_2,LPCRITICAL_SECTION param_3)

{
  EnterCriticalSection(param_3);
  *param_2 = *param_1;
  param_2[1] = (int)param_1;
  *(int **)(*param_1 + 4) = param_2;
  *param_1 = (int)param_2;
  LeaveCriticalSection(param_3);
  return;
}



/* c06941d4 FUN_c06941d4 */

/* Boundary evidence: original MIPS .pdata c06941d4..c069425b. Semantic name remains unreviewed. */

void FUN_c06941d4(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = *(undefined4 *)(param_1 + 0x5ac);
  uVar3 = *(undefined4 *)(param_1 + 0x5b4);
  uVar1 = *(uint *)(param_1 + 0x5b0);
  *(undefined4 *)(param_1 + 0x5ac) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5b0) = 0;
  *(undefined4 *)(param_1 + 0x5b4) = 0;
  if ((uVar1 != 0) && (uVar1 < 7)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
    (*DAT_c069d354)(uVar2,uVar3);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  }
  return;
}



/* c069425c FUN_c069425c */

/* Boundary evidence: original MIPS .pdata c069425c..c06942cb. Semantic name remains unreviewed. */

void FUN_c069425c(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  if ((*(int *)(param_1 + 0x5b0) != 0) &&
     (*(undefined4 *)(param_1 + 0x5b4) = param_2, *(int *)(param_1 + 0x5ac) != -1)) {
    FUN_c06941d4(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  return;
}



/* c06942cc FUN_c06942cc */

/* Boundary evidence: original MIPS .pdata c06942cc..c069435b. Semantic name remains unreviewed. */

void FUN_c06942cc(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x5dc);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 0x5b0) != 0) {
    LeaveCriticalSection(lpCriticalSection);
    FUN_c069425c(param_1,0x80000048);
    EnterCriticalSection(lpCriticalSection);
  }
  *(undefined4 *)(param_1 + 0x5b0) = param_2;
  *(undefined4 *)(param_1 + 0x5b4) = 0x80000001;
  *(undefined4 *)(param_1 + 0x5ac) = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
  return;
}



/* c069435c FUN_c069435c */

/* Boundary evidence: original MIPS .pdata c069435c..c069439f. Semantic name remains unreviewed. */

undefined4 FUN_c069435c(undefined4 *param_1)

{
  (*DAT_c069d354)(*param_1,param_1[1]);
  LocalFree(param_1);
  return 0;
}



/* c06943a0 FUN_c06943a0 */

/* Boundary evidence: original MIPS .pdata c06943a0..c0694473. Semantic name remains unreviewed. */

undefined4 FUN_c06943a0(int param_1)

{
  undefined4 *lpParameter;
  HANDLE hObject;
  
  lpParameter = LocalAlloc(0x40,8);
  if (lpParameter != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
    *lpParameter = *(undefined4 *)(param_1 + 0x5ac);
    lpParameter[1] = *(undefined4 *)(param_1 + 0x5b4);
    *(undefined4 *)(param_1 + 0x5ac) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x5b0) = 0;
    *(undefined4 *)(param_1 + 0x5b4) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c069435c,lpParameter,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
      return 1;
    }
    LocalFree(lpParameter);
  }
  return 0;
}



/* c0694474 FUN_c0694474 */

/* Boundary evidence: original MIPS .pdata c0694474..c06945f7. Semantic name remains unreviewed. */

void FUN_c0694474(short *param_1,uint param_2,short *param_3)

{
  short sVar1;
  
  sVar1 = *param_1;
  if (sVar1 == 0x10) {
    if (0x68 < param_2) {
      param_2 = 0x68;
    }
  }
  else {
    if (sVar1 == 0x20) {
      if (0xfc < param_2) {
        param_2 = 0xfc;
      }
      if (param_1 != param_3) {
        memcpy(param_3,param_1,param_2);
      }
      memset((void *)(param_2 + (int)param_3),0,0x2ac - param_2);
      if (0xfb < param_2) {
        *(undefined4 *)(param_3 + 0x154) = *(undefined4 *)(param_1 + 0x7c);
      }
      if (0xf7 < param_2) {
        memcpy(param_3 + 0x115,param_1 + 0x3d,0x7e);
      }
      if (0x79 < param_2) {
        memcpy(param_3 + 0x10c,param_1 + 0x34,0x12);
      }
      if (0x15 < param_2) {
        param_3[0x33] = 0;
      }
      goto LAB_c06945d8;
    }
    if (sVar1 != 0x30) {
      memcpy(param_3,&DAT_c06912e0,0x2ac);
      goto LAB_c06945d8;
    }
  }
  if ((param_1 != param_3) && (param_2 < 0x2ad)) {
    memcpy(param_3,param_1,param_2);
  }
  if (param_2 < 0x2ac) {
    memset((void *)(param_2 + (int)param_3),0,0x2ac - param_2);
  }
LAB_c06945d8:
  *param_3 = 0x30;
  return;
}



/* c06945f8 FUN_c06945f8 */

/* Boundary evidence: original MIPS .pdata c06945f8..c06949db. Semantic name remains unreviewed. */

void FUN_c06945f8(int param_1,short *param_2)

{
  LSTATUS LVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  int iVar6;
  DWORD local_240;
  int local_23c;
  DWORD local_238 [2];
  BYTE aBStack_230 [516];
  uint local_2c;
  
  local_2c = DAT_c069d168;
  local_238[0] = 0x2ac;
  LVar1 = FUN_c0698484(param_1,(LPCWSTR)0x0,L"DevConfig",3,(LPBYTE)param_2,local_238);
  if ((LVar1 == 0) && (0x17 < local_238[0])) {
    FUN_c0694474(param_2,local_238[0],param_2);
  }
  else {
    memcpy(param_2,&DAT_c06912e0,0x2ac);
  }
  local_240 = 4;
  LVar1 = FUN_c0698484(param_1,L"Config",L"BaudRate",4,(LPBYTE)&local_23c,&local_240);
  if (LVar1 == 0) {
    *(int *)(param_2 + 6) = local_23c;
  }
  local_240 = 4;
  LVar1 = FUN_c0698484(param_1,L"Config",L"CallSetupFailTimer",4,(LPBYTE)&local_23c,&local_240);
  if (LVar1 == 0) {
    *(int *)(param_2 + 2) = local_23c;
  }
  local_240 = 4;
  LVar1 = FUN_c0698484(param_1,L"Config",L"WaitBong",4,(LPBYTE)&local_23c,&local_240);
  if (LVar1 == 0) {
    param_2[1] = (short)local_23c;
  }
  local_240 = 4;
  LVar1 = FUN_c0698484(param_1,L"Config",L"ByteSize",4,(LPBYTE)&local_23c,&local_240);
  if (LVar1 == 0) {
    *(char *)(param_2 + 9) = (char)local_23c;
  }
  local_240 = 4;
  LVar1 = FUN_c0698484(param_1,L"Config",L"Parity",4,(LPBYTE)&local_23c,&local_240);
  if (LVar1 == 0) {
    *(char *)(param_2 + 10) = (char)local_23c;
  }
  local_240 = 4;
  LVar1 = FUN_c0698484(param_1,L"Config",L"StopBits",4,(LPBYTE)&local_23c,&local_240);
  if (LVar1 == 0) {
    *(char *)((int)param_2 + 0x13) = (char)local_23c;
  }
  puVar4 = (uint *)&DAT_c069d120;
  iVar6 = 0;
  if (DAT_c069d120 != 0) {
    iVar2 = 0;
    do {
      local_240 = 4;
      LVar1 = FUN_c0698484(param_1,L"Config",
                           *(LPCWSTR *)((int)&PTR_u_EnableAutoBaud_c069d138 + iVar2),4,
                           (LPBYTE)&local_23c,&local_240);
      if (LVar1 == 0) {
        if (local_23c == 0) {
          uVar3 = ~*puVar4 & *(uint *)(param_2 + 4);
        }
        else {
          uVar3 = *(uint *)(param_2 + 4) | *puVar4;
        }
        *(uint *)(param_2 + 4) = uVar3;
      }
      iVar6 = iVar6 + 1;
      iVar2 = iVar6 * 4;
      puVar4 = (uint *)(&DAT_c069d120 + iVar6);
    } while (*puVar4 != 0);
  }
  piVar5 = &DAT_c069d14c;
  iVar6 = 0;
  if (DAT_c069d14c != 0) {
    iVar2 = 0;
    do {
      local_240 = 4;
      LVar1 = FUN_c0698484(param_1,L"Config",*(LPCWSTR *)((int)&PTR_u_ManualDial_c069d15c + iVar2),4
                           ,(LPBYTE)&local_23c,&local_240);
      if (LVar1 == 0) {
        if (local_23c == 0) {
          param_2[8] = ~(ushort)*piVar5 & param_2[8];
        }
        else {
          param_2[8] = param_2[8] | (ushort)*piVar5;
        }
      }
      iVar6 = iVar6 + 1;
      iVar2 = iVar6 * 4;
      piVar5 = &DAT_c069d14c + iVar6;
    } while (*piVar5 != 0);
  }
  local_238[0] = 0x202;
  LVar1 = FUN_c0698484(param_1,L"Config",L"DialModifier",1,aBStack_230,local_238);
  if (LVar1 == 0) {
    memcpy(param_2 + 0xb,aBStack_230,local_238[0]);
  }
  param_2[0x10b] = 0;
  param_2[0x114] = 0;
  FUN_c069bce8(local_2c);
  return;
}



/* c06949dc FUN_c06949dc */

undefined4 * FUN_c06949dc(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_c069d358;
  while( true ) {
    if ((undefined4 **)puVar1 == &DAT_c069d358) {
      return (undefined4 *)0x0;
    }
    if (puVar1[3] == param_1) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}



/* c0694a14 FUN_c0694a14 */

/* Boundary evidence: original MIPS .pdata c0694a14..c0694adb. Semantic name remains unreviewed. */

undefined4 * FUN_c0694a14(wchar_t *param_1,wchar_t *param_2)

{
  int iVar1;
  wchar_t *_Str1;
  wchar_t *_Str2;
  undefined4 *puVar2;
  
  puVar2 = DAT_c069d358;
  do {
    if ((undefined4 **)puVar2 == &DAT_c069d358) {
      return (undefined4 *)0x0;
    }
    if (param_1 == (wchar_t *)0x0) {
      if (param_2 != (wchar_t *)0x0) {
LAB_c0694a90:
        _Str2 = (wchar_t *)((int)puVar2 + 0x112);
        _Str1 = param_2;
LAB_c0694a98:
        iVar1 = wcscmp(_Str1,_Str2);
        if (iVar1 == 0) {
          return puVar2;
        }
      }
    }
    else if (param_2 == (wchar_t *)0x0) {
      if (*(short *)((int)puVar2 + 0x21a) != 0) {
        _Str2 = (wchar_t *)(puVar2 + 4);
        _Str1 = param_1;
        goto LAB_c0694a98;
      }
    }
    else {
      iVar1 = wcscmp(param_1,(wchar_t *)(puVar2 + 4));
      if (iVar1 == 0) goto LAB_c0694a90;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* c0694adc FUN_c0694adc */

/* Boundary evidence: original MIPS .pdata c0694adc..c0694b7b. Semantic name remains unreviewed. */

undefined4 * FUN_c0694adc(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((undefined4 **)DAT_c069d358 != &DAT_c069d358) {
    sVar1 = *(short *)(param_1 + 0x218);
    puVar3 = DAT_c069d358;
    do {
      if (((*(short *)(puVar3 + 0x86) == sVar1) &&
          (iVar2 = wcscmp((wchar_t *)(puVar3 + 4),(wchar_t *)(param_1 + 0x10)), iVar2 == 0)) &&
         (iVar2 = wcscmp((wchar_t *)((int)puVar3 + 0x112),(wchar_t *)(param_1 + 0x112)), iVar2 == 0)
         ) {
        return puVar3;
      }
      puVar3 = (undefined4 *)*puVar3;
    } while ((undefined4 **)puVar3 != &DAT_c069d358);
  }
  return (undefined4 *)0x0;
}



/* c0694b7c FUN_c0694b7c */

undefined4 FUN_c0694b7c(undefined4 param_1)

{
  return param_1;
}



/* c0694b84 FUN_c0694b84 */

undefined4 FUN_c0694b84(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = *(short *)(param_1 + 0x218);
  if (((sVar1 == 0) || (sVar1 == 6)) || (uVar2 = 0, sVar1 == 8)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0694bb8 FUN_c0694bb8 */

undefined4 FUN_c0694bb8(int param_1)

{
  undefined4 uVar1;
  
  if ((*(ushort *)(param_1 + 0x218) < 7) || (uVar1 = 1, 8 < *(ushort *)(param_1 + 0x218))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0694be4 FUN_c0694be4 */

/* Boundary evidence: original MIPS .pdata c0694be4..c0694c37. Semantic name remains unreviewed. */

void FUN_c0694be4(int *param_1,int param_2)

{
  memset(param_1 + 1,0,*param_1 - 4);
  param_1[1] = param_2;
  param_1[2] = param_2;
  return;
}



/* c0694c38 FUN_c0694c38 */

/* Boundary evidence: original MIPS .pdata c0694c38..c0694d17. Semantic name remains unreviewed. */

void FUN_c0694c38(void)

{
  LSTATUS LVar1;
  DWORD local_10;
  DWORD DStack_c;
  
  DAT_c069d340 = 0;
  DAT_c069d344 = 0;
  DAT_c069d348 = 0;
  DAT_c069d350 = 0;
  DAT_c069d354 = 0;
  DAT_c069d35c = &DAT_c069d358;
  DAT_c069d358 = &DAT_c069d358;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c069d360);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\Unimodem",0,0x20019,&DAT_c069d34c);
  if (LVar1 == 0) {
    DAT_c069d190 = 0x96;
    local_10 = 4;
    RegQueryValueExW(DAT_c069d34c,L"Priority256",(LPDWORD)0x0,&DStack_c,(LPBYTE)&DAT_c069d190,
                     &local_10);
  }
  DAT_c069d37c = LoadLibraryW(L"coredll.dll");
  return;
}



/* c0694d18 FUN_c0694d18 */

/* Boundary evidence: original MIPS .pdata c0694d18..c0694d8b. Semantic name remains unreviewed. */

undefined4 FUN_c0694d18(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x4e8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x4f4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x744) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5d0) = 1;
  *(undefined4 *)(param_1 + 0x4f0) = 0;
  *(undefined4 *)(param_1 + 0x500) = 0;
  *(undefined4 *)(param_1 + 0x5f0) = 0;
  *(undefined4 *)(param_1 + 0x504) = 0;
  *(undefined2 *)(param_1 + 0x508) = 0;
  *(undefined4 *)(param_1 + 0x5c0) = 0;
  *(undefined4 *)(param_1 + 0x5b8) = 0;
  *(undefined4 *)(param_1 + 0x4dc) = 0;
  *(undefined4 *)(param_1 + 0x4e0) = 0;
  *(undefined4 *)(param_1 + 0x5fc) = 0;
  *(undefined4 *)(param_1 + 0x4d8) = *(undefined4 *)(param_1 + 0x4cc);
  *(undefined4 *)(param_1 + 0x5f8) = 0;
  *(undefined4 *)(param_1 + 0x5d8) = 0;
  if (param_2 != 0) {
    FUN_c06945f8(param_1,(short *)(param_1 + 0x220));
  }
  return 0;
}



/* c0694d8c FUN_c0694d8c */

/* Boundary evidence: original MIPS .pdata c0694d8c..c0694e13. Semantic name remains unreviewed. */

undefined4 FUN_c0694d8c(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  
  if (param_1 != (LPCWSTR)0x0) {
    uVar2 = 0;
    ppuVar3 = &PTR_u_tapi_line_c0691088;
    do {
      iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar3);
      if (iVar1 == 0) break;
      uVar2 = uVar2 + 1;
      ppuVar3 = ppuVar3 + 2;
    } while ((int)uVar2 < 4);
    if (uVar2 < 3) {
      return 1;
    }
  }
  return 0;
}



/* c0694e14 FUN_c0694e14 */

undefined4 FUN_c0694e14(int param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x750);
  iVar5 = 0x50;
  if (param_3 == (ushort *)0x0) {
    uVar3 = 0x80000032;
  }
  else {
    if ((param_2 != (ushort *)0x0) && (uVar2 = *param_2, uVar2 != 0)) {
      if (uVar2 == 0x50) {
LAB_c0694e8c:
        *(uint *)(param_1 + 0x5f8) = *(uint *)(param_1 + 0x5f8) & 0xfffffeff;
        goto LAB_c0694fdc;
      }
      if (uVar2 == 0x54) {
LAB_c0694e7c:
        *(uint *)(param_1 + 0x5f8) = *(uint *)(param_1 + 0x5f8) | 0x100;
        goto LAB_c0694fdc;
      }
      if (uVar2 == 0x70) goto LAB_c0694e8c;
      if (uVar2 == 0x74) goto LAB_c0694e7c;
      *(uint *)(param_1 + 0x5f8) = *(uint *)(param_1 + 0x5f8) | 0x100;
      while ((uVar2 = *param_2, uVar2 != 0 && (iVar5 != 0))) {
        if (uVar2 < 0x41) {
          if (uVar2 == 0x40) {
            if ((*(uint *)(param_1 + 0x714) & 0x80) == 0) {
              return 0x8000000b;
            }
            goto LAB_c0694fc8;
          }
          if (uVar2 != 0x20) {
            if (uVar2 == 0x24) {
              if ((*(uint *)(param_1 + 0x714) & 0x40) != 0) goto LAB_c0694fc8;
              iVar4 = (uint)(*(ushort *)(param_1 + 0x222) >> 1) +
                      (uint)((*(ushort *)(param_1 + 0x222) & 1) != 0);
              do {
                if (iVar4 == 0) break;
                *param_3 = 0x2c;
                param_3 = param_3 + 1;
                iVar5 = iVar5 + -1;
                iVar4 = iVar4 + -1;
              } while (iVar5 != 0);
            }
            else if (uVar2 != 0x2d) {
              if (uVar2 == 0x3f) {
                return 0x8000000a;
              }
              goto LAB_c0694fc8;
            }
          }
        }
        else {
          if (uVar2 != 0x57) {
            if (uVar2 == 0x5e) goto LAB_c0694fa8;
            if (uVar2 != 0x77) {
              if (uVar2 != 0x7c) goto LAB_c0694fc8;
              goto LAB_c0694fa8;
            }
          }
          if ((*(uint *)(param_1 + 0x714) & 0x100) == 0) {
            return 0x80000009;
          }
LAB_c0694fc8:
          if (uVar2 == uVar1) {
            *param_3 = *param_2;
            param_3 = param_3 + 1;
            goto LAB_c0694fa8;
          }
          *param_3 = uVar2;
          param_3 = param_3 + 1;
          iVar5 = iVar5 + -1;
        }
LAB_c0694fdc:
        param_2 = param_2 + 1;
      }
      if ((*param_2 != 0) && (iVar5 == 0)) {
        return 0x80000010;
      }
    }
LAB_c0694fa8:
    uVar3 = 0;
    *param_3 = 0;
  }
  return uVar3;
}



/* c069502c FUN_c069502c */

/* Boundary evidence: original MIPS .pdata c069502c..c069509b. Semantic name remains unreviewed. */

void FUN_c069502c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x4fc);
    if ((param_3 == 8) && ((*(uint *)(param_1 + 0x724) & param_4) == 0)) {
      return;
    }
  }
  (*DAT_c069d350)(uVar1);
  return;
}



/* c069509c FUN_c069509c */

/* Boundary evidence: original MIPS .pdata c069509c..c06950e3. Semantic name remains unreviewed. */

void FUN_c069509c(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x5d4) = param_3;
  *(undefined4 *)(param_1 + 0x5d0) = param_2;
  (*DAT_c069d350)(*(undefined4 *)(param_1 + 0x4fc),*(undefined4 *)(param_1 + 0x5bc),2,param_2,
                  param_3,*(undefined4 *)(param_1 + 0x4dc));
  return;
}



/* c06950e4 FUN_c06950e4 */

/* Boundary evidence: original MIPS .pdata c06950e4..c0695223. Semantic name remains unreviewed. */

bool FUN_c06950e4(int param_1,undefined4 param_2)

{
  HMODULE hLibModule;
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined1 auStack_128 [256];
  uint local_28;
  
  local_28 = DAT_c069d168;
  bVar4 = false;
  hLibModule = LoadLibraryW(L"termctrl.dll");
  if (hLibModule != (HMODULE)0x0) {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"TerminalWindow");
    bVar4 = false;
    if ((pcVar1 != (code *)0x0) &&
       (pcVar2 = (code *)GetProcAddressW(DAT_c069d37c,L"LoadStringW"), pcVar2 != (code *)0x0)) {
      (*pcVar2)(DAT_c069d340,param_2,auStack_128,0x80);
      SetThreadPriority((HANDLE)0x41,3);
      puVar5 = (undefined4 *)(param_1 + 0x5c0);
      *puVar5 = 0;
      iVar3 = (*pcVar1)(*(undefined4 *)(param_1 + 0x4e8),auStack_128,puVar5);
      bVar4 = iVar3 == 0;
      *puVar5 = 0;
      CeSetThreadPriority(0x41,DAT_c069d190);
    }
    FreeLibrary(hLibModule);
  }
  FUN_c069bce8(local_28);
  return bVar4;
}



/* c0695224 FUN_c0695224 */

/* Boundary evidence: original MIPS .pdata c0695224..c06952d7. Semantic name remains unreviewed. */

undefined4 FUN_c0695224(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x5dc);
  EnterCriticalSection(lpCriticalSection);
  uVar1 = 0x80000048;
  if ((*(int *)(param_1 + 0x5ac) == -1) &&
     (*(undefined4 *)(param_1 + 0x5ac) = param_2, uVar1 = param_2,
     *(int *)(param_1 + 0x5b4) != -0x7fffffff)) {
    LeaveCriticalSection(lpCriticalSection);
    iVar2 = FUN_c06943a0(param_1);
    if (iVar2 == 0) {
      param_2 = 0x80000048;
    }
  }
  else {
    param_2 = uVar1;
    LeaveCriticalSection(lpCriticalSection);
  }
  return param_2;
}



/* c06952d8 FUN_c06952d8 */

/* Boundary evidence: original MIPS .pdata c06952d8..c06956cb. Semantic name remains unreviewed. */

int * FUN_c06952d8(HKEY param_1,LPCWSTR param_2,wchar_t *param_3)

{
  short sVar1;
  int *hMem;
  LSTATUS LVar2;
  int *piVar3;
  HANDLE pvVar4;
  wchar_t *_Dest;
  PHKEY phkResult;
  DWORD local_140;
  int local_13c [3];
  wchar_t awStack_130 [128];
  uint local_30;
  
  local_30 = DAT_c069d168;
  hMem = LocalAlloc(0x40,0x754);
  if (hMem != (int *)0x0) {
    hMem[0x133] = 0x10;
    phkResult = (PHKEY)(hMem + 0x85);
    hMem[0x16b] = -1;
    hMem[0x1d2] = 0;
    hMem[3] = -1;
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_2,0,0x20019,phkResult);
    if (LVar2 == 0) {
      FUN_c0694d18((int)hMem,1);
      _Dest = (wchar_t *)(hMem + 4);
      if (param_3 != (wchar_t *)0x0) {
        wcscpy(_Dest,param_3);
LAB_c069543c:
        local_140 = 4;
        LVar2 = FUN_c0698484((int)hMem,(LPCWSTR)0x0,L"DeviceType",4,(LPBYTE)local_13c,&local_140);
        if (LVar2 == 0) {
          *(short *)(hMem + 0x86) = (short)local_13c[0];
        }
        else {
          *(undefined2 *)(hMem + 0x86) = 0;
        }
        hMem[0x1c5] = 0x1c0;
        local_140 = 4;
        LVar2 = FUN_c0698484((int)hMem,L"Settings",L"DialBilling",4,(LPBYTE)local_13c,&local_140);
        if ((LVar2 == 0) && (local_13c[0] == 0)) {
          hMem[0x1c5] = hMem[0x1c5] & 0xffffffbf;
        }
        FUN_c06986a4((int)hMem);
        local_140 = 0x80;
        LVar2 = FUN_c0698484((int)hMem,(LPCWSTR)0x0,L"FriendlyName",1,(LPBYTE)((int)hMem + 0x112),
                             &local_140);
        if (LVar2 != 0) {
          if ((short)hMem[0x86] == 3) {
            local_13c[1] = 1;
            local_140 = 0x80;
            LVar2 = RegQueryValueExW(param_1,L"PnpId",(LPDWORD)0x0,(LPDWORD)(local_13c + 1),
                                     (LPBYTE)awStack_130,&local_140);
            if (LVar2 == 0) {
              local_140 = wcslen(awStack_130);
              if (5 < local_140) {
                awStack_130[local_140 - 5] = L'\0';
              }
              _Dest = awStack_130;
            }
            else {
              _Dest = L"Generic Hayes PCMCIA Modem";
            }
          }
          wcsncpy((wchar_t *)((int)hMem + 0x112),_Dest,0x80);
        }
        piVar3 = FUN_c0694adc((int)hMem);
        if (piVar3 != (int *)0x0) {
          piVar3[0x85] = (int)*phkResult;
          LocalFree(hMem);
          *(undefined2 *)((int)piVar3 + 0x21a) = 1;
          FUN_c069502c((int)piVar3,0,8,0x44);
          FUN_c069bce8(local_30);
          return piVar3;
        }
        *(undefined2 *)((int)hMem + 0x21a) = 1;
        pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        hMem[0x171] = (int)pvVar4;
        pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        hMem[0x173] = (int)pvVar4;
        InitializeCriticalSection((LPCRITICAL_SECTION)(hMem + 0x177));
        sVar1 = (short)hMem[0x86];
        if (((sVar1 == 0) || (sVar1 == 6)) || (sVar1 == 8)) {
          hMem[0x134] = 0x48;
        }
        else {
          hMem[0x134] = 0x49;
        }
        FUN_c0694174(&DAT_c069d358,hMem,(LPCRITICAL_SECTION)&DAT_c069d360);
        (*DAT_c069d350)(0,0,0x13,DAT_c069d348,hMem + 3,0);
        FUN_c069bce8(local_30);
        return hMem;
      }
      local_140 = 0x80;
      LVar2 = FUN_c0698484((int)hMem,(LPCWSTR)0x0,L"Port",1,(LPBYTE)_Dest,&local_140);
      if (LVar2 == 0) goto LAB_c069543c;
      RegCloseKey(*phkResult);
    }
    LocalFree(hMem);
  }
  FUN_c069bce8(local_30);
  return (int *)0x0;
}



/* c06956cc FUN_c06956cc */

/* Boundary evidence: original MIPS .pdata c06956cc..c06957a3. Semantic name remains unreviewed. */

void FUN_c06956cc(int param_1)

{
  HANDLE pvVar1;
  wchar_t awStack_58 [32];
  uint local_18;
  
  local_18 = DAT_c069d168;
  if (*(int *)(param_1 + 0x740) != 0) {
    if (*(HANDLE *)(param_1 + 0x744) != (HANDLE)0xffffffff) {
      CloseHandle(*(HANDLE *)(param_1 + 0x744));
    }
    StringCchPrintfW(awStack_58,0x20,L"%s%d.%s",L"mdmlog",*(undefined4 *)(param_1 + 0xc),L".txt");
    pvVar1 = CreateFileW(awStack_58,0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (pvVar1 == (HANDLE)0xffffffff) {
      *(undefined4 *)(param_1 + 0x744) = 0xffffffff;
    }
    else {
      *(HANDLE *)(param_1 + 0x744) = pvVar1;
    }
  }
  FUN_c069bce8(local_18);
  return;
}



/* c06957a4 FUN_c06957a4 */

/* Boundary evidence: original MIPS .pdata c06957a4..c06958d3. Semantic name remains unreviewed. */

void FUN_c06957a4(int param_1,char *param_2,int param_3)

{
  size_t sVar1;
  size_t sVar2;
  char *_Source;
  uint uVar3;
  DWORD aDStack_128 [2];
  char acStack_120 [256];
  uint local_20;
  
  local_20 = DAT_c069d168;
  if (*(int *)(param_1 + 0x740) != 0) {
    if (param_3 == 1) {
      _Source = "Modem Response:  ";
    }
    else if (param_3 == 2) {
      _Source = "Modem Command:   ";
    }
    else if (param_3 == 3) {
      _Source = "Failed Command:  ";
    }
    else {
      _Source = "                 ";
    }
    acStack_120[0xfe] = 0;
    strcpy(acStack_120,_Source);
    sVar1 = strlen(acStack_120);
    strncat(acStack_120,param_2,0xfe - sVar1);
    sVar2 = strlen(param_2);
    uVar3 = sVar2 + sVar1;
    if (0xfe < uVar3) {
      uVar3 = 0xfe;
    }
    acStack_120[uVar3] = '\n';
    acStack_120[uVar3 + 1] = '\0';
    WriteFile(*(HANDLE *)(param_1 + 0x744),acStack_120,uVar3 + 1,aDStack_128,(LPOVERLAPPED)0x0);
  }
  FUN_c069bce8(local_20);
  return;
}



/* c06958d4 FUN_c06958d4 */

void FUN_c06958d4(int param_1,int param_2)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 0xc);
  *(undefined1 *)(param_1 + 0x12) = *(undefined1 *)(param_2 + 0x12);
  *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)(param_2 + 0x13);
  uVar1 = ((uint)(*(char *)(param_2 + 0x14) != '\0') << 1 ^ *(uint *)(param_1 + 8)) & 2 ^
          *(uint *)(param_1 + 8);
  *(uint *)(param_1 + 8) = uVar1;
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(param_2 + 0x14);
  *(uint *)(param_1 + 8) = uVar1 & 0xffffff9f | 0x10;
  if ((*(uint *)(param_2 + 8) & 0x10) == 0) {
    if ((*(uint *)(param_2 + 8) & 0x20) == 0) {
      *(uint *)(param_1 + 8) = uVar1 & 0xffffdc9b | 0x1010;
      return;
    }
    uVar1 = uVar1 & 0xffffdf9b | 0x1310;
  }
  else {
    uVar1 = uVar1 & 0xffffec9f | 0x2014;
  }
  *(uint *)(param_1 + 8) = uVar1;
  return;
}



/* c0695998 FUN_c0695998 */

/* Boundary evidence: original MIPS .pdata c0695998..c0695a5f. Semantic name remains unreviewed. */

void FUN_c0695998(int param_1)

{
  int iVar1;
  _COMMTIMEOUTS local_20;
  
  iVar1 = *(int *)(param_1 + 0x22c);
  if (iVar1 == 0x6e) {
    local_20.ReadTotalTimeoutMultiplier = 0x6d;
  }
  else if (iVar1 == 300) {
    local_20.ReadTotalTimeoutMultiplier = 0x29;
  }
  else if (iVar1 == 600) {
    local_20.ReadTotalTimeoutMultiplier = 0x15;
  }
  else if (iVar1 == 0x4b0) {
    local_20.ReadTotalTimeoutMultiplier = 10;
  }
  else if (iVar1 == 0x12c0) {
    local_20.ReadTotalTimeoutMultiplier = 6;
  }
  else if (iVar1 == 0x2580) {
    local_20.ReadTotalTimeoutMultiplier = 3;
  }
  else {
    local_20.ReadTotalTimeoutMultiplier = 1;
  }
  local_20.ReadIntervalTimeout = 0x32;
  local_20.ReadTotalTimeoutConstant = 0x32;
  local_20.WriteTotalTimeoutMultiplier = 5;
  local_20.WriteTotalTimeoutConstant = 500;
  SetCommTimeouts(*(HANDLE *)(param_1 + 0x4e8),&local_20);
  return;
}



/* c0695a60 FUN_c0695a60 */

/* Boundary evidence: original MIPS .pdata c0695a60..c0695b67. Semantic name remains unreviewed. */

undefined4 FUN_c0695a60(int param_1)

{
  HANDLE hObject;
  HANDLE pvVar1;
  _DCB _Stack_40;
  
  hObject = CreateFileW((LPCWSTR)(param_1 + 0x10),0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,
                        (HANDLE)0x0);
  if (hObject != (HANDLE)0xffffffff) {
    pvVar1 = CreateFileW((LPCWSTR)(param_1 + 0x10),0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    if (pvVar1 != (HANDLE)0xffffffff) {
      GetCommState(hObject,&_Stack_40);
      FUN_c06958d4((int)&_Stack_40,param_1 + 0x220);
      SetCommState(hObject,&_Stack_40);
      *(HANDLE *)(param_1 + 0x4e8) = hObject;
      *(HANDLE *)(param_1 + 0x4f4) = pvVar1;
      FUN_c0695998(param_1);
      return 0;
    }
    CloseHandle(hObject);
  }
  return 0x6e;
}



/* c0695b68 FUN_c0695b68 */

/* Boundary evidence: original MIPS .pdata c0695b68..c0695c17. Semantic name remains unreviewed. */

undefined4 FUN_c0695b68(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  if (*(int *)(param_1 + 0x4e8) == -1) {
    if (*(short *)(param_1 + 0x21a) == 0) {
      uVar2 = 0x80000042;
    }
    else {
      iVar1 = FUN_c0695a60(param_1);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x5f0) = 0;
        FUN_c06956cc(param_1);
        uVar2 = 0;
      }
      else {
        uVar2 = 0x8000004b;
      }
    }
  }
  else {
    uVar2 = 0x80000001;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  return uVar2;
}



/* c0695c18 FUN_c0695c18 */

/* Boundary evidence: original MIPS .pdata c0695c18..c0695db3. Semantic name remains unreviewed. */

int FUN_c0695c18(int param_1)

{
  BOOL BVar1;
  HANDLE hFile;
  int iVar2;
  
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  if ((*(HANDLE *)(param_1 + 0x4e8) != (HANDLE)0xffffffff) &&
     (BVar1 = SetCommMask(*(HANDLE *)(param_1 + 0x4e8),0), BVar1 == 0)) {
    if (*(int *)(param_1 + 0x4e8) == -1) {
      iVar2 = -0x7fffffb8;
    }
    else {
      hFile = CreateFileW((LPCWSTR)(param_1 + 0x10),0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,
                          (HANDLE)0x0);
      *(HANDLE *)(param_1 + 0x4e8) = hFile;
      iVar2 = -0x7fffffb8;
      if (hFile != (HANDLE)0xffffffff) {
        iVar2 = 0;
      }
      if (iVar2 == 0) {
        SetCommMask(hFile,0);
      }
    }
  }
  if ((*(HANDLE *)(param_1 + 0x4f4) != (HANDLE)0xffffffff) &&
     (BVar1 = SetCommMask(*(HANDLE *)(param_1 + 0x4f4),0), BVar1 == 0)) {
    iVar2 = -0x7fffffb8;
  }
  *(undefined4 *)(param_1 + 0x4f8) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  return iVar2;
}



/* c0695db4 FUN_c0695db4 */

/* Boundary evidence: original MIPS .pdata c0695db4..c0695ddb. Semantic name remains unreviewed. */

bool FUN_c0695db4(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c0695ddc FUN_c0695ddc */

/* Boundary evidence: original MIPS .pdata c0695ddc..c0695e2b. Semantic name remains unreviewed. */

void FUN_c0695ddc(int param_1)

{
  _DCB _Stack_28;
  
  GetCommState(*(HANDLE *)(param_1 + 0x4e8),&_Stack_28);
  _Stack_28._8_4_ = _Stack_28._8_4_ & 0xffffdffb | 0x1000;
  SetCommState(*(HANDLE *)(param_1 + 0x4e8),&_Stack_28);
  return;
}



/* c0695e2c FUN_c0695e2c */

/* Boundary evidence: original MIPS .pdata c0695e2c..c0695ecb. Semantic name remains unreviewed. */

void FUN_c0695e2c(int param_1,LPCWSTR param_2,char *param_3,char *param_4)

{
  LSTATUS LVar1;
  DWORD local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c069d168;
  if (param_3 != (char *)0x0) {
    local_228[0] = 0x104;
    LVar1 = FUN_c0698484(param_1,L"Settings",param_2,1,(LPBYTE)awStack_220,local_228);
    if (LVar1 == 0) {
      FUN_c0699668(awStack_220,param_3,local_228);
    }
    else {
      strcpy(param_3,param_4);
    }
  }
  FUN_c069bce8(local_18);
  return;
}



/* c0695ecc FUN_c0695ecc */

/* Boundary evidence: original MIPS .pdata c0695ecc..c0695f5b. Semantic name remains unreviewed. */

void FUN_c0695ecc(int param_1,char *param_2,char *param_3,char *param_4)

{
  FUN_c0695e2c(param_1,L"Escape",param_2,"+++");
  FUN_c0695e2c(param_1,L"Hangup",param_3,"ATH\r\n");
  FUN_c0695e2c(param_1,L"Reset",param_4,"ATZ\r\n");
  return;
}



/* c0695f5c FUN_c0695f5c */

/* Boundary evidence: original MIPS .pdata c0695f5c..c06961fb. Semantic name remains unreviewed. */

void FUN_c0695f5c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  char acStack_328 [264];
  char acStack_220 [264];
  char acStack_118 [260];
  uint local_14;
  
  local_14 = DAT_c069d168;
  if ((*(int *)(param_1 + 0x5c0) != 0) &&
     (pcVar1 = (code *)GetProcAddressW(DAT_c069d37c,L"SendMessageW",param_3,param_4,param_1),
     pcVar1 != (code *)0x0)) {
    (*pcVar1)(*(undefined4 *)(param_1 + 0x5c0),0x10,0,0);
  }
  FUN_c0695c18(param_1);
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x5cc),4000);
  if (*(HANDLE *)(param_1 + 0x4e8) != (HANDLE)0xffffffff) {
    PurgeComm(*(HANDLE *)(param_1 + 0x4e8),0xc);
    iVar2 = FUN_c0694b84(param_1);
    if (iVar2 == 0) {
      FUN_c0695ecc(param_1,acStack_328,acStack_220,acStack_118);
      FUN_c0695ddc(param_1);
      *(undefined4 *)(param_1 + 0x4f8) = 0x1f9;
      FUN_c069a118(param_1,*(int *)(param_1 + 0x738) + *(int *)(param_1 + 0x730) +
                           *(int *)(param_1 + 0x734));
      Sleep(*(DWORD *)(param_1 + 0x730));
      FUN_c0699720(param_1,acStack_328);
      EscapeCommFunction(*(HANDLE *)(param_1 + 0x4e8),6);
      Sleep(*(DWORD *)(param_1 + 0x734));
      FUN_c069988c(param_1,acStack_328,0,0);
      FUN_c069a118(param_1,*(int *)(param_1 + 0x738));
      FUN_c0699720(param_1,acStack_220);
      FUN_c069988c(param_1,acStack_220,0,0);
      FUN_c069a118(param_1,*(uint *)(param_1 + 0x738) >> 1);
      FUN_c0699720(param_1,acStack_118);
      FUN_c069988c(param_1,acStack_118,0,0);
      FUN_c069a118(param_1,0);
    }
    else {
      EscapeCommFunction(*(HANDLE *)(param_1 + 0x4e8),6);
      Sleep(400);
      EscapeCommFunction(*(HANDLE *)(param_1 + 0x4e8),5);
      Sleep(200);
    }
    if (*(int *)(param_1 + 0x5b0) == 3) {
      FUN_c069425c(param_1,0);
    }
  }
  FUN_c069bce8(local_14);
  return;
}



/* c06961fc FUN_c06961fc */

/* Boundary evidence: original MIPS .pdata c06961fc..c0696223. Semantic name remains unreviewed. */

bool FUN_c06961fc(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c0696224 FUN_c0696224 */

/* Boundary evidence: original MIPS .pdata c0696224..c069634b. Semantic name remains unreviewed. */

undefined4 FUN_c0696224(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x5dc);
  EnterCriticalSection(lpCriticalSection);
  iVar2 = *(int *)(param_1 + 0x5d0);
  *(undefined4 *)(param_1 + 0x5d8) = 0;
  if (((iVar2 == 0x4000) || (iVar2 == 1)) &&
     ((iVar1 = *(int *)(param_1 + 0x5f0), iVar1 == 0 || ((9 < iVar1 && (iVar1 < 0xc)))))) {
    *(undefined4 *)(param_1 + 0x5f0) = 0;
    LeaveCriticalSection(lpCriticalSection);
    FUN_c069425c(param_1,0);
  }
  else {
    *(uint *)(param_1 + 0x5b8) = *(uint *)(param_1 + 0x5b8) & 0xfffffffd | 8;
    if ((iVar2 == 1) && (*(int *)(param_1 + 0x5f0) == 0)) {
      FUN_c069425c(param_1,0);
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
      FUN_c0695f5c(param_1,param_2,param_3,param_4);
      EnterCriticalSection(lpCriticalSection);
    }
    if ((*(uint *)(param_1 + 0x5b8) & 1) != 0) {
      FUN_c069509c(param_1,1,0);
    }
    *(undefined4 *)(param_1 + 0x5f0) = 0;
    *(undefined4 *)(param_1 + 0x5d0) = 1;
    *(undefined4 *)(param_1 + 0x5b8) = 0;
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* c069634c FUN_c069634c */

/* Boundary evidence: original MIPS .pdata c069634c..c069638f. Semantic name remains unreviewed. */

undefined4 FUN_c069634c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c0696224(param_1,param_2,param_3,param_4);
  FUN_c069425c(param_1,0);
  return uVar1;
}



/* c0696390 FUN_c0696390 */

/* Boundary evidence: original MIPS .pdata c0696390..c069653f. Semantic name remains unreviewed. */

void FUN_c0696390(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  BOOL BVar2;
  LPDCB lpDCB;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined1 local_38 [8];
  _DCB _Stack_30;
  
  GetCommState(*(HANDLE *)(param_1 + 0x4e8),&_Stack_30);
  FUN_c06958d4((int)&_Stack_30,param_1 + 0x220);
  lpDCB = &_Stack_30;
  SetCommState(*(HANDLE *)(param_1 + 0x4e8),lpDCB);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x5dc);
  EnterCriticalSection(lpCriticalSection);
  bVar1 = *(int *)(param_1 + 0x4f8) != 0;
  if (bVar1) {
    lpDCB = (LPDCB)0x20;
    SetCommMask(*(HANDLE *)(param_1 + 0x4f4),0x20);
  }
  LeaveCriticalSection(lpCriticalSection);
  if ((bVar1) && (*(int *)(param_1 + 0x5d0) == 0x100)) {
    while ((*(uint *)(param_1 + 0x5b8) & 2) != 0) {
      param_3 = 0;
      lpDCB = (LPDCB)(local_38 + 4);
      BVar2 = WaitCommEvent(*(HANDLE *)(param_1 + 0x4f4),(LPDWORD)lpDCB,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) break;
      if ((local_38._4_4_ & 0x20) != 0) {
        lpDCB = (LPDCB)local_38;
        local_38._0_4_ = 0;
        BVar2 = GetCommModemStatus(*(HANDLE *)(param_1 + 0x4f4),(LPDWORD)lpDCB);
        if (BVar2 == 0) break;
        if ((local_38._0_4_ & 0x80) == 0) {
          FUN_c0695f5c(param_1,lpDCB,param_3,param_4);
          *(undefined4 *)(param_1 + 0x5f0) = 0;
          *(uint *)(param_1 + 0x5b8) = *(uint *)(param_1 + 0x5b8) & 0xfffffffd;
          *(undefined4 *)(param_1 + 0x5d8) = 0;
          FUN_c069509c(param_1,0x4000,1);
          param_3 = 0;
          lpDCB = (LPDCB)0x1;
          FUN_c069509c(param_1,1,0);
          break;
        }
      }
      if (((local_38._4_4_ == 0) || ((*(uint *)(param_1 + 0x5b8) & 8) != 0)) ||
         (*(int *)(param_1 + 0x5d0) != 0x100)) break;
    }
  }
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 0x4f8) = 0x1f9;
  LeaveCriticalSection(lpCriticalSection);
  FUN_c0695ddc(param_1);
  if (*(int *)(param_1 + 0x5b0) != 3) {
    FUN_c069634c(param_1,lpDCB,param_3,param_4);
  }
  return;
}



/* c0696540 FUN_c0696540 */

/* Boundary evidence: original MIPS .pdata c0696540..c069659b. Semantic name remains unreviewed. */

undefined4 FUN_c0696540(int param_1)

{
  if ((*(int *)(param_1 + 0x5f0) == 0xb) || (*(int *)(param_1 + 0x5f0) == 0xc)) {
    FUN_c069425c(param_1,0);
  }
  FUN_c069509c(param_1,0x200,0);
  return 0;
}



/* c069659c FUN_c069659c */

/* Boundary evidence: original MIPS .pdata c069659c..c069661b. Semantic name remains unreviewed. */

undefined4 FUN_c069659c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_c069a118(param_1,0);
  *(uint *)(param_1 + 0x5b8) = *(uint *)(param_1 + 0x5b8) | 2;
  if ((*(int *)(param_1 + 0x5f0) == 0xb) || (*(int *)(param_1 + 0x5f0) == 0xc)) {
    *(undefined4 *)(param_1 + 0x5f0) = 9;
    FUN_c069425c(param_1,0);
  }
  uVar2 = 0;
  uVar1 = 0x100;
  FUN_c069509c(param_1,0x100,0);
  FUN_c0696390(param_1,uVar1,uVar2,param_4);
  return 0;
}



/* c069661c FUN_c069661c */

/* Boundary evidence: original MIPS .pdata c069661c..c0696937. Semantic name remains unreviewed. */

undefined4 FUN_c069661c(int param_1,char *param_2,undefined4 param_3,LPHANDLE param_4)

{
  size_t sVar1;
  char *pcVar2;
  LSTATUS LVar3;
  HLOCAL hMem;
  char *_Source;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  DWORD local_270;
  int local_26c;
  char acStack_268 [64];
  wchar_t awStack_228 [256];
  uint local_28;
  
  local_28 = DAT_c069d168;
  uVar6 = 0;
  uVar5 = 4;
  do {
    iVar4 = *(int *)(param_1 + 0x5b0);
    if (iVar4 != 1) {
      if (iVar4 == 2) {
        if (*(HLOCAL *)(param_1 + 0x74c) != (HLOCAL)0x0) {
          LocalFree(*(HLOCAL *)(param_1 + 0x74c));
          *(undefined4 *)(param_1 + 0x74c) = 0;
        }
        local_26c = 0x19;
        local_270 = 4;
        FUN_c0698484(param_1,L"Settings",L"AnswerTimeout",4,(LPBYTE)&local_26c,&local_270);
        iVar4 = FUN_c069a118(param_1,local_26c * 1000);
        if (iVar4 != 0) {
          FUN_c069bce8(local_28);
          return 1;
        }
        *(uint *)(param_1 + 0x5b8) = *(uint *)(param_1 + 0x5b8) | 1;
        iVar4 = FUN_c0694b84(param_1);
        if (iVar4 == 0) {
          local_270 = 0x200;
          LVar3 = FUN_c0698484(param_1,L"Settings",L"Answer",1,(LPBYTE)awStack_228,&local_270);
          if (LVar3 == 0) {
            pcVar2 = FUN_c0699668(awStack_228,(char *)0x0,(size_t *)0x0);
            *(char **)(param_1 + 0x74c) = pcVar2;
          }
          else {
            pcVar2 = LocalAlloc(0x40,6);
            *(char **)(param_1 + 0x74c) = pcVar2;
            if (pcVar2 != (char *)0x0) {
              _Source = "ATA\r\n";
              goto LAB_c06968ac;
            }
          }
        }
        else {
          FUN_c0695e2c(param_1,L"DCCResponse",acStack_268,"CLIENTSERVER");
          sVar1 = strlen(acStack_268);
          if (sVar1 == 0) goto LAB_c0696724;
          sVar1 = strlen(acStack_268);
          pcVar2 = LocalAlloc(0x40,sVar1 + 1);
          *(char **)(param_1 + 0x74c) = pcVar2;
          if (pcVar2 != (char *)0x0) {
            _Source = acStack_268;
LAB_c06968ac:
            strcpy(pcVar2,_Source);
          }
        }
        if (*(int *)(param_1 + 0x74c) == 0) {
          uVar5 = 3;
        }
        else {
          FUN_c0695ddc(param_1);
          iVar4 = FUN_c0699720(param_1,*(char **)(param_1 + 0x74c));
          hMem = *(HLOCAL *)(param_1 + 0x74c);
          if (iVar4 != 0) {
            if (hMem != (HLOCAL)0x0) {
              LocalFree(hMem);
              *(undefined4 *)(param_1 + 0x74c) = 0;
            }
LAB_c0696724:
            FUN_c069bce8(local_28);
            return uVar6;
          }
          if (hMem != (HLOCAL)0x0) {
            LocalFree(hMem);
            *(undefined4 *)(param_1 + 0x74c) = 0;
          }
          uVar5 = 2;
        }
        FUN_c069425c(param_1,0x80000048);
LAB_c0696928:
        FUN_c069bce8(local_28);
        return uVar5;
      }
      if (iVar4 == 3) {
        uVar6 = FUN_c069634c(param_1,param_2,param_3,param_4);
        goto LAB_c0696724;
      }
      if (iVar4 != 4) {
        if (iVar4 != 0xfe) {
          if (iVar4 != 0xff) {
            FUN_c069bce8(local_28);
            return 5;
          }
          goto LAB_c0696928;
        }
        uVar6 = FUN_c0696224(param_1,param_2,param_3,param_4);
        goto LAB_c0696724;
      }
    }
    FUN_c069b1d4(param_1,param_2,param_3,param_4);
    if (*(int *)(param_1 + 0x5d0) == 0x10) {
      param_4 = (LPHANDLE)0x1;
      param_3 = 0;
      param_2 = "listening";
      FUN_c069988c(param_1,"listening",0,1);
    }
    else {
      if (*(int *)(param_1 + 0x5d0) != 0x100) goto LAB_c0696724;
      FUN_c0696390(param_1,param_2,param_3,param_4);
    }
  } while( true );
}



/* c0696938 FUN_c0696938 */

/* Boundary evidence: original MIPS .pdata c0696938..c0696a73. Semantic name remains unreviewed. */

undefined4 FUN_c0696938(int param_1)

{
  LSTATUS LVar1;
  wchar_t *hMem;
  char *pcVar2;
  undefined4 uVar3;
  SIZE_T local_20 [2];
  
  if ((*(ushort *)(param_1 + 0x230) & 4) == 0) {
    uVar3 = 1;
    LVar1 = FUN_c0698484(param_1,L"Settings",L"Monitor",1,(LPBYTE)0x0,local_20);
    if (((LVar1 == 0) && (hMem = LocalAlloc(0x40,local_20[0]), hMem != (wchar_t *)0x0)) &&
       (LVar1 = FUN_c0698484(param_1,L"Settings",L"Monitor",1,(LPBYTE)hMem,local_20), LVar1 == 0)) {
      pcVar2 = FUN_c0699668(hMem,(char *)0x0,(size_t *)0x0);
      *(char **)(param_1 + 0x74c) = pcVar2;
      LocalFree(hMem);
      return 1;
    }
    pcVar2 = LocalAlloc(0x40,9);
    *(char **)(param_1 + 0x74c) = pcVar2;
    if (pcVar2 == (char *)0x0) {
      uVar3 = 0;
    }
    else {
      strcpy(pcVar2,"ATS0=0\r\n");
    }
  }
  else {
    if (*(HLOCAL *)(param_1 + 0x74c) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x74c));
      *(undefined4 *)(param_1 + 0x74c) = 0;
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* c0696a74 FUN_c0696a74 */

/* Boundary evidence: original MIPS .pdata c0696a74..c0696aff. Semantic name remains unreviewed. */

int FUN_c0696a74(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  bVar1 = FUN_c069a224(param_1);
  iVar2 = CONCAT31(extraout_var,bVar1);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  if (iVar2 == 0) {
    iVar2 = 1;
    if (*(int *)(param_1 + 0x5b0) == 1) {
      *(undefined4 *)(param_1 + 0x4f8) = 0x1f9;
      SetCommMask(*(HANDLE *)(param_1 + 0x4e8),0x1f9);
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* c0696b00 FUN_c0696b00 */

/* Boundary evidence: original MIPS .pdata c0696b00..c0696cbf. Semantic name remains unreviewed. */

undefined4 FUN_c0696b00(int param_1,int param_2,undefined4 param_3,LPHANDLE param_4)

{
  BOOL BVar1;
  HANDLE hSourceHandle;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar2;
  int iVar3;
  HANDLE local_30;
  int local_2c;
  undefined4 local_28;
  
  local_30 = (HANDLE)0x0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x5dc);
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(param_1 + 0x5d0);
  uVar2 = *(undefined4 *)(param_1 + 0x5bc);
  hSourceHandle = *(HANDLE *)(param_1 + 0x4e8);
  local_2c = iVar3;
  local_28 = uVar2;
  if (hSourceHandle != (HANDLE)0xffffffff) {
    if (*(HANDLE *)(param_1 + 0x4ec) != (HANDLE)0x0) {
      param_4 = &local_30;
      param_3 = 0x42;
      BVar1 = DuplicateHandle(*(HANDLE *)(param_1 + 0x4ec),hSourceHandle,(HANDLE)0x42,param_4,0,0,3)
      ;
      *(undefined4 *)(param_1 + 0x4ec) = 0;
      if (BVar1 != 0) {
        *(HANDLE *)(param_1 + 0x4e8) = local_30;
      }
    }
    if (param_2 != 0) {
      LeaveCriticalSection(lpCriticalSection);
      FUN_c0696224(param_1,hSourceHandle,param_3,param_4);
      EnterCriticalSection(lpCriticalSection);
    }
    CloseHandle(*(HANDLE *)(param_1 + 0x4e8));
    CloseHandle(*(HANDLE *)(param_1 + 0x4f4));
    CloseHandle(*(HANDLE *)(param_1 + 0x744));
    FUN_c0694d18(param_1,0);
  }
  *(undefined4 *)(param_1 + 0x5ac) = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  if (iVar3 != 1) {
    *(undefined4 *)(param_1 + 0x5bc) = uVar2;
    FUN_c069509c(param_1,1,0);
    *(undefined4 *)(param_1 + 0x5bc) = 0;
  }
  return 0;
}



/* c0696cc0 FUN_c0696cc0 */

/* Boundary evidence: original MIPS .pdata c0696cc0..c0696ce7. Semantic name remains unreviewed. */

bool FUN_c0696cc0(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c0696ce8 FUN_c0696ce8 */

/* Boundary evidence: original MIPS .pdata c0696ce8..c0696dcf. Semantic name remains unreviewed. */

undefined4 FUN_c0696ce8(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  LPHANDLE ppvVar3;
  
  if (*(int *)(param_1 + 0x5d8) == 0) {
    FUN_c069a118(param_1,25000);
    *(undefined4 *)(param_1 + 0x5d0) = 2;
    *(undefined4 *)(param_1 + 0x5f0) = 0xc;
    *(undefined4 *)(param_1 + 0x5b8) = 4;
    FUN_c069502c(param_1,0,500,param_1);
    *(uint *)(param_1 + 0x4dc) = *(uint *)(param_1 + 0x4cc) | 2;
    FUN_c069509c(param_1,2,0);
  }
  ppvVar3 = (LPHANDLE)0x2;
  uVar2 = 8;
  pcVar1 = (char *)0x0;
  FUN_c069502c(param_1,0,8,2);
  *(int *)(param_1 + 0x5d8) = *(int *)(param_1 + 0x5d8) + 1;
  if ((*(int *)(param_1 + 0x5b0) == 2) && ((*(uint *)(param_1 + 0x5b8) & 1) == 0)) {
    uVar2 = FUN_c069661c(param_1,pcVar1,uVar2,ppvVar3);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0696dd0 FUN_c0696dd0 */

/* Boundary evidence: original MIPS .pdata c0696dd0..c0697317. Semantic name remains unreviewed. */

undefined4 FUN_c0696dd0(int param_1,undefined4 param_2,int param_3,LPHANDLE param_4)

{
  bool bVar1;
  BOOL BVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar6;
  int local_30;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x5dc);
  EnterCriticalSection(lpCriticalSection);
  iVar5 = *(int *)(param_1 + 0x5b0);
  if ((iVar5 == 0xfe) || (bVar1 = true, iVar5 == 0)) {
    bVar1 = false;
  }
  if (*(int *)(param_1 + 0x5f0) == 0) {
    *(undefined4 *)(param_1 + 0x5f0) = 10;
  }
  if (iVar5 == 1) {
    uVar6 = *(undefined4 *)(param_1 + 0x5bc);
  }
  else {
    uVar6 = 0;
  }
  iVar5 = FUN_c0695b68(param_1);
  if ((iVar5 == 0) || (iVar5 == -0x7fffffff)) {
    if (*(HLOCAL *)(param_1 + 0x74c) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x74c));
      *(undefined4 *)(param_1 + 0x74c) = 0;
    }
    FUN_c0695ddc(param_1);
    pcVar3 = (char *)0x1f9;
    *(undefined4 *)(param_1 + 0x4f8) = 0x1f9;
    SetCommMask(*(HANDLE *)(param_1 + 0x4e8),0x1f9);
    iVar5 = FUN_c0694b84(param_1);
    if (((iVar5 == 0) && ((*(ushort *)(param_1 + 0x230) & 4) == 0)) &&
       (iVar5 = FUN_c0696a74(param_1), iVar5 == 0)) {
      if (*(int *)(param_1 + 0x5fc) == 0) {
        *(undefined4 *)(param_1 + 0x5f0) = 0;
      }
      else {
LAB_c06970f0:
        if (*(HLOCAL *)(param_1 + 0x74c) != (HLOCAL)0x0) {
          LocalFree(*(HLOCAL *)(param_1 + 0x74c));
          *(undefined4 *)(param_1 + 0x74c) = 0;
        }
        if (*(int *)(param_1 + 0x5fc) != 0) {
          *(undefined4 *)(param_1 + 0x748) = 0;
          LeaveCriticalSection(lpCriticalSection);
          return 0;
        }
        if (*(int *)(param_1 + 0x4e0) != 0) {
          LeaveCriticalSection(lpCriticalSection);
          FUN_c069634c(param_1,pcVar3,param_3,param_4);
          EnterCriticalSection(lpCriticalSection);
          pcVar3 = (char *)0x1f9;
          BVar2 = SetCommMask(*(HANDLE *)(param_1 + 0x4e8),0x1f9);
          if (BVar2 != 0) {
            *(undefined4 *)(param_1 + 0x4f8) = 0x1f9;
            *(undefined4 *)(param_1 + 0x5f0) = 0xb;
            iVar5 = FUN_c0694b84(param_1);
            if (iVar5 == 0) {
              iVar5 = FUN_c0696938(param_1);
              if (iVar5 == 0) goto LAB_c0697260;
              FUN_c0695ddc(param_1);
              *(undefined4 *)(param_1 + 0x5d8) = 0;
              if (*(int *)(param_1 + 0x5b4) == -0x7fffffff) {
                pcVar3 = (char *)0x80000048;
                FUN_c069425c(param_1,0x80000048);
              }
            }
            else {
              *(undefined4 *)(param_1 + 0x5d8) = 0;
            }
            FUN_c0695998(param_1);
LAB_c0696f7c:
            iVar5 = *(int *)(param_1 + 0x4fc);
            do {
              if ((iVar5 == 0) || (iVar5 = *(int *)(param_1 + 0x5f0), iVar5 == 0))
              goto LAB_c06970f0;
              if ((iVar5 == 0xb) || (iVar5 == 0xc)) {
                pcVar3 = *(char **)(param_1 + 0x74c);
                if ((pcVar3 != (char *)0x0) && (iVar5 = FUN_c0699720(param_1,pcVar3), iVar5 == 0))
                goto LAB_c06970f0;
                iVar5 = *(int *)(param_1 + 0x5b0);
                if (iVar5 == 1) {
                  *(undefined4 *)(param_1 + 0x5f0) = 6;
                  local_30 = 3;
                  goto LAB_c069707c;
                }
                local_30 = 2;
                if (iVar5 == 2) {
                  iVar5 = FUN_c0694b84(param_1);
                  if (iVar5 != 0) {
                    pcVar3 = (char *)0x3;
                    EventModify(*(undefined4 *)(param_1 + 0x5cc));
                    goto LAB_c069707c;
                  }
                }
                else if (iVar5 == 0xff) break;
                pcVar4 = *(char **)(param_1 + 0x74c);
                param_4 = (LPHANDLE)0x1;
                param_3 = 1;
                pcVar3 = "listening";
                if (pcVar4 == (char *)0x0) {
LAB_c0697060:
                  param_4 = (LPHANDLE)0x1;
                  local_30 = FUN_c069988c(param_1,pcVar3,param_3,1);
                }
                else {
                  local_30 = FUN_c069988c(param_1,pcVar4,1,1);
                  pcVar3 = pcVar4;
                  if ((local_30 == 0) && (*(int *)(param_1 + 0x5b0) == 0xfe)) {
                    param_3 = 0;
                    pcVar3 = *(char **)(param_1 + 0x74c);
                    goto LAB_c0697060;
                  }
                }
              }
              else {
LAB_c069707c:
                LeaveCriticalSection(lpCriticalSection);
              }
              if (*(HLOCAL *)(param_1 + 0x74c) != (HLOCAL)0x0) {
                LocalFree(*(HLOCAL *)(param_1 + 0x74c));
                *(undefined4 *)(param_1 + 0x74c) = 0;
              }
              if (local_30 == 0) {
                if ((*(int *)(param_1 + 0x5f0) == 0xb) || (*(int *)(param_1 + 0x5f0) == 0xc)) {
                  pcVar3 = (char *)0x0;
                  FUN_c069425c(param_1,0);
                }
              }
              else {
                if (local_30 != 2) {
                  if (local_30 == 3) {
                    iVar5 = FUN_c069661c(param_1,pcVar3,param_3,param_4);
LAB_c0697198:
                    if (iVar5 == 0) goto LAB_c06971f0;
                  }
                  else {
                    if (local_30 == 8) {
                      iVar5 = FUN_c0696ce8(param_1);
                      goto LAB_c0697198;
                    }
                    if (local_30 < 9) goto LAB_c06971f0;
                    if (local_30 < 0xc) {
                      FUN_c0696540(param_1);
                      goto LAB_c06971f0;
                    }
                    if (local_30 != 0xe) goto LAB_c06971f0;
                  }
                  EnterCriticalSection(lpCriticalSection);
                  goto LAB_c06970f0;
                }
                FUN_c069659c(param_1,pcVar3,param_3,param_4);
              }
LAB_c06971f0:
              local_30 = 3;
              EnterCriticalSection(lpCriticalSection);
              iVar5 = *(int *)(param_1 + 0x4fc);
            } while( true );
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x5b0) == 1) {
      *(undefined4 *)(param_1 + 0x5f0) = 6;
      LeaveCriticalSection(lpCriticalSection);
      iVar5 = FUN_c069661c(param_1,pcVar3,param_3,param_4);
      if (iVar5 == 0) {
        EnterCriticalSection(lpCriticalSection);
LAB_c0696f74:
        bVar1 = false;
        local_30 = 3;
        goto LAB_c0696f7c;
      }
      EnterCriticalSection(lpCriticalSection);
    }
    else {
      *(undefined4 *)(param_1 + 0x5f0) = 0xb;
      iVar5 = FUN_c0694b84(param_1);
      if ((iVar5 != 0) || (iVar5 = FUN_c0696938(param_1), iVar5 != 0)) goto LAB_c0696f74;
    }
  }
LAB_c0697260:
  if (*(HLOCAL *)(param_1 + 0x74c) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0x74c));
    *(undefined4 *)(param_1 + 0x74c) = 0;
  }
  FUN_c069a118(param_1,0);
  *(undefined4 *)(param_1 + 0x748) = 0;
  LeaveCriticalSection(lpCriticalSection);
  FUN_c069425c(param_1,0x80000048);
  if ((bVar1) && (*(int *)(param_1 + 0x5b0) == 1)) {
    param_3 = 0;
    *(undefined4 *)(param_1 + 0x5bc) = uVar6;
    FUN_c069509c(param_1,0x4000,0);
    *(undefined4 *)(param_1 + 0x5bc) = 0;
  }
  FUN_c0696b00(param_1,1,param_3,param_4);
  return 0;
}



/* c0697318 FUN_c0697318 */

/* Boundary evidence: original MIPS .pdata c0697318..c06973cf. Semantic name remains unreviewed. */

undefined4 FUN_c0697318(LPVOID param_1)

{
  HANDLE hObject;
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)((int)param_1 + 0x748) == 0) {
    *(undefined4 *)((int)param_1 + 0x748) = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0696dd0,param_1,0,(LPDWORD)0x0);
    if (hObject == (HANDLE)0x0) {
      NKDbgPrintfW(L"Unable to Create UnimodemControlThread\n");
      uVar1 = 0x80000048;
      *(undefined4 *)((int)param_1 + 0x748) = 0;
    }
    else {
      CeSetThreadPriority(hObject,DAT_c069d190);
      CloseHandle(hObject);
    }
  }
  return uVar1;
}



/* c06973d0 FUN_c06973d0 */

/* Boundary evidence: original MIPS .pdata c06973d0..c06974d3. Semantic name remains unreviewed. */

int FUN_c06973d0(LPVOID param_1,uint param_2,int param_3)

{
  int iVar1;
  
  FUN_c06942cc((int)param_1,param_2);
  EnterCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x5dc));
  if (*(int *)((int)param_1 + 0x748) == 0) {
    if ((param_2 != 1) && (param_2 != 0xfe)) {
      iVar1 = -0x7fffffb8;
      goto LAB_c06974ac;
    }
    iVar1 = FUN_c0697318(param_1);
  }
  else if ((param_2 == 0) || ((4 < param_2 && ((param_2 < 0xfe || (0xff < param_2)))))) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_c0695c18((int)param_1);
  }
  if (((iVar1 == 0) && (param_2 != 0)) && (param_2 < 5)) {
    iVar1 = param_3;
  }
LAB_c06974ac:
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x5dc));
  return iVar1;
}



/* c06974d4 FUN_c06974d4 */

/* Boundary evidence: original MIPS .pdata c06974d4..c069758f. Semantic name remains unreviewed. */

undefined4 FUN_c06974d4(undefined4 param_1,undefined4 param_2)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"WaitForAPIReady");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c0697590 FUN_c0697590 */

/* Boundary evidence: original MIPS .pdata c0697590..c069767f. Semantic name remains unreviewed. */

undefined4
FUN_c0697590(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"CeCallUserProc");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0697680 FUN_c0697680 */

/* Boundary evidence: original MIPS .pdata c0697680..c0697767. Semantic name remains unreviewed. */

undefined4 FUN_c0697680(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 local_248 [2];
  DWORD local_240;
  undefined4 local_23c;
  undefined1 auStack_238 [556];
  uint local_c;
  
  local_c = DAT_c069d168;
  local_248[0] = 0;
  local_240 = 0;
  local_23c = param_1;
  memcpy(auStack_238,param_2,0x22c);
  iVar1 = FUN_c06974d4(0x51,60000);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_c0697590(L"netui.dll",L"LineConfigEditExt",&local_240,0x234,&local_240,0x234,
                           local_248), iVar1 != 0)) {
    if (local_240 == 0) {
      memcpy(param_2,auStack_238,0x22c);
      FUN_c069bce8(local_c);
      return 1;
    }
    SetLastError(local_240);
  }
  FUN_c069bce8(local_c);
  return 0;
}



/* c0697768 FUN_c0697768 */

/* Boundary evidence: original MIPS .pdata c0697768..c069789b. Semantic name remains unreviewed. */

void FUN_c0697768(int param_1,DWORD *param_2,WORD *param_3,WORD *param_4)

{
  BOOL BVar1;
  HANDLE hFile;
  _COMMPROP _Stack_60;
  uint local_20;
  
  local_20 = DAT_c069d168;
  *param_2 = 0x67b72;
  *param_3 = 0xf;
  *param_4 = 0x1f07;
  if (*(HANDLE *)(param_1 + 0x4f4) == (HANDLE)0xffffffff) {
    hFile = CreateFileW((LPCWSTR)(param_1 + 0x10),0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,
                        (HANDLE)0x0);
    if (hFile == (HANDLE)0xffffffff) goto LAB_c0697874;
    BVar1 = GetCommProperties(hFile,&_Stack_60);
    if (BVar1 == 0) {
      CloseHandle(hFile);
      goto LAB_c0697874;
    }
    CloseHandle(hFile);
  }
  else {
    BVar1 = GetCommProperties(*(HANDLE *)(param_1 + 0x4f4),&_Stack_60);
    if (BVar1 == 0) goto LAB_c0697874;
  }
  *param_2 = _Stack_60.dwSettableBaud;
  *param_3 = _Stack_60.wSettableData;
  *param_4 = _Stack_60.wSettableStopParity;
LAB_c0697874:
  FUN_c069bce8(local_20);
  return;
}



/* c069789c FUN_c069789c */

/* Boundary evidence: original MIPS .pdata c069789c..c0697bcf. Semantic name remains unreviewed. */

int FUN_c069789c(undefined4 param_1,int param_2,void *param_3,void *param_4)

{
  int iVar1;
  size_t sVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 local_250;
  undefined4 local_24c;
  DWORD DStack_248;
  undefined1 local_244;
  undefined1 local_243;
  undefined1 local_242;
  WORD WStack_240;
  undefined2 local_23e;
  undefined4 local_23c;
  uint local_238;
  uint local_234;
  undefined4 local_22c;
  wchar_t awStack_228 [256];
  undefined2 local_28;
  WORD WStack_26;
  uint local_24;
  
  local_24 = DAT_c069d168;
  memcpy(param_4,param_3,0x2ac);
  memset(&local_250,0,0x22c);
  local_250 = 1;
  local_24c = *(undefined4 *)((int)param_3 + 0xc);
  FUN_c0697768(param_2,&DStack_248,&WStack_240,&WStack_26);
  local_244 = *(undefined1 *)((int)param_3 + 0x12);
  local_243 = *(undefined1 *)((int)param_3 + 0x14);
  local_242 = *(undefined1 *)((int)param_3 + 0x13);
  local_23e = *(undefined2 *)((int)param_3 + 2);
  local_23c = *(undefined4 *)((int)param_3 + 4);
  uVar4 = *(uint *)((int)param_3 + 8);
  if ((uVar4 & 0x200) != 0) {
    local_238 = local_238 | 4;
  }
  if ((uVar4 & 0x20) != 0) {
    local_238 = local_238 | 1;
  }
  if ((uVar4 & 0x10) != 0) {
    local_238 = local_238 | 2;
  }
  if ((uVar4 & 0x80) != 0) {
    local_238 = local_238 | 8;
  }
  uVar3 = *(ushort *)((int)param_3 + 0x10);
  if ((uVar3 & 1) != 0) {
    local_234 = local_234 | 2;
  }
  if ((uVar3 & 2) != 0) {
    local_234 = local_234 | 4;
  }
  if ((uVar3 & 4) != 0) {
    local_234 = local_234 | 1;
  }
  local_22c = 0x100;
  wcscpy(awStack_228,(wchar_t *)((int)param_3 + 0x16));
  iVar1 = FUN_c0697680(param_1,&local_250);
  if (iVar1 != 0) {
    *(undefined2 *)((int)param_4 + 2) = local_23e;
    *(undefined4 *)((int)param_4 + 4) = local_23c;
    uVar4 = *(uint *)((int)param_4 + 8) & 0xfffffd4f;
    *(uint *)((int)param_4 + 8) = uVar4;
    if ((local_238 & 1) != 0) {
      *(uint *)((int)param_4 + 8) = uVar4 | 0x20;
    }
    if ((local_238 & 2) != 0) {
      *(uint *)((int)param_4 + 8) = *(uint *)((int)param_4 + 8) | 0x10;
    }
    if ((local_238 & 8) != 0) {
      *(uint *)((int)param_4 + 8) = *(uint *)((int)param_4 + 8) | 0x80;
    }
    if ((local_238 & 4) != 0) {
      *(uint *)((int)param_4 + 8) = *(uint *)((int)param_4 + 8) | 0x200;
    }
    *(undefined2 *)((int)param_4 + 2) = local_23e;
    *(undefined4 *)((int)param_4 + 0xc) = local_24c;
    uVar3 = *(ushort *)((int)param_4 + 0x10) & 0xfff8;
    *(ushort *)((int)param_4 + 0x10) = uVar3;
    if ((local_234 & 1) != 0) {
      *(ushort *)((int)param_4 + 0x10) = uVar3 | 4;
    }
    if ((local_234 & 2) != 0) {
      *(ushort *)((int)param_4 + 0x10) = *(ushort *)((int)param_4 + 0x10) | 1;
    }
    if ((local_234 & 4) != 0) {
      *(ushort *)((int)param_4 + 0x10) = *(ushort *)((int)param_4 + 0x10) | 2;
    }
    *(undefined1 *)((int)param_4 + 0x12) = local_244;
    *(undefined1 *)((int)param_4 + 0x13) = local_242;
    *(undefined1 *)((int)param_4 + 0x14) = local_243;
    sVar2 = wcslen(awStack_228);
    if (0x100 < sVar2) {
      sVar2 = 0x100;
      local_28 = 0;
    }
    memcpy((void *)((int)param_4 + 0x16),awStack_228,(sVar2 + 1) * 2);
  }
  FUN_c069bce8(local_24);
  return iVar1;
}



/* c0697bd0 FUN_c0697bd0 */

/* Boundary evidence: original MIPS .pdata c0697bd0..c0697bdb. Semantic name remains unreviewed. */

undefined4 FUN_c0697bd0(void)

{
  return 1;
}



/* c0697bdc FUN_c0697bdc */

undefined4 FUN_c0697bdc(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 < 0x3841) {
    if (param_1 == 0x3840) {
      uVar1 = param_2 & 0x1000;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 0x6e) {
      uVar1 = param_2 & 2;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 300) {
      uVar1 = param_2 & 0x10;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 600) {
      uVar1 = param_2 & 0x20;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 0x4b0) {
      uVar1 = param_2 & 0x40;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 0x960) {
      uVar1 = param_2 & 0x100;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 0x12c0) {
      uVar1 = param_2 & 0x200;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 0x2580) {
      uVar1 = param_2 & 0x800;
      goto joined_r0xc0697c74;
    }
LAB_c0697cec:
    uVar1 = 0x10000000;
LAB_c0697d00:
    uVar1 = param_2 & uVar1;
  }
  else {
    if (param_1 == 0x4b00) {
      if ((param_2 & 0x2000) == 0) {
        return 0;
      }
      return 1;
    }
    if (param_1 == 0x9600) {
      uVar1 = param_2 & 0x4000;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 56000) {
      uVar1 = param_2 & 0x8000;
      goto joined_r0xc0697c74;
    }
    if (param_1 == 0xe100) {
      uVar1 = 0x40000;
    }
    else {
      if (param_1 == 0x1c200) {
        uVar1 = 0x20000;
        goto LAB_c0697d00;
      }
      if (param_1 != 0x1f400) goto LAB_c0697cec;
      uVar1 = 0x10000;
    }
    uVar1 = param_2 & uVar1;
  }
joined_r0xc0697c74:
  if (uVar1 == 0) {
    return 0;
  }
  return 1;
}



/* c0697d3c FUN_c0697d3c */

undefined4 FUN_c0697d3c(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 5) {
    if ((param_2 & 1) != 0) {
      return 1;
    }
  }
  else {
    if (param_1 == 6) {
      uVar1 = param_2 & 2;
    }
    else if (param_1 == 7) {
      uVar1 = param_2 & 4;
    }
    else if (param_1 == 8) {
      uVar1 = param_2 & 8;
    }
    else {
      if (param_1 != 0x10) {
        return 0;
      }
      uVar1 = param_2 & 0x10;
    }
    if (uVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* c0697dc8 FUN_c0697dc8 */

undefined4 FUN_c0697dc8(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = param_2 & 0x100;
  }
  else if (param_1 == 1) {
    uVar1 = param_2 & 0x200;
  }
  else if (param_1 == 2) {
    uVar1 = param_2 & 0x400;
  }
  else if (param_1 == 3) {
    uVar1 = param_2 & 0x800;
  }
  else {
    if (param_1 != 4) {
      return 0;
    }
    uVar1 = param_2 & 0x1000;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return 1;
}



/* c0697e4c FUN_c0697e4c */

undefined4 FUN_c0697e4c(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = param_2 & 1;
  }
  else if (param_1 == 1) {
    uVar1 = param_2 & 2;
  }
  else {
    if (param_1 != 2) {
      return 0;
    }
    uVar1 = param_2 & 4;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return 1;
}



/* c0697ea8 FUN_c0697ea8 */

/* Boundary evidence: original MIPS .pdata c0697ea8..c0698053. Semantic name remains unreviewed. */

int FUN_c0697ea8(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  HRESULT HVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  wchar_t awStack_60 [30];
  uint local_24;
  
  local_24 = DAT_c069d168;
  iVar3 = 0;
  HVar1 = StringCchCopyW(awStack_60,0x1e,*(STRSAFE_LPCWSTR *)(param_2 + 4));
  if (HVar1 == 0) {
    iVar2 = FUN_c0694d8c(awStack_60);
    if (iVar2 == 0) {
      iVar3 = -0x7fffffdd;
      goto LAB_c0698008;
    }
    puVar4 = *(uint **)(param_2 + 8);
    if (puVar4 != (uint *)0x0) {
      puVar5 = puVar4 + 6;
      puVar4[1] = 0x2c4;
      if (*puVar4 < 0x2c4) {
        iVar3 = -0x7fffffb3;
      }
      else {
        puVar4[2] = 0x2c4;
      }
      if (iVar3 == 0) {
        if ((short)*puVar5 == 0) {
          FUN_c06945f8(param_1,(short *)puVar5);
        }
        if (*(short *)(param_1 + 0x220) == (short)*puVar5) {
          *param_4 = puVar4;
          *param_3 = puVar5;
        }
        else {
          iVar3 = -0x7fffffce;
        }
      }
      goto LAB_c0698008;
    }
  }
  iVar3 = -0x7fffffcb;
LAB_c0698008:
  FUN_c069bce8(local_24);
  return iVar3;
}



/* c0698054 FUN_c0698054 */

/* Boundary evidence: original MIPS .pdata c0698054..c069805f. Semantic name remains unreviewed. */

undefined4 FUN_c0698054(void)

{
  return 1;
}



/* c0698060 FUN_c0698060 */

/* Boundary evidence: original MIPS .pdata c0698060..c06982d7. Semantic name remains unreviewed. */

int FUN_c0698060(int param_1,int param_2)

{
  int iVar1;
  HRESULT HVar2;
  STRSAFE_LPWSTR pszDest;
  size_t cchDest;
  uint uVar3;
  int iVar4;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  iVar1 = FUN_c0697ea8(param_1,param_2,&local_20,&local_14);
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((*(uint *)(param_2 + 0xc) != 0) && (*(uint *)(param_2 + 0xc) < 5)) {
    local_1c = 0;
    local_18 = 0;
    FUN_c0697768(param_1,&local_14,(WORD *)&local_18,(WORD *)&local_1c);
  }
  iVar1 = -0x7fffffce;
  switch(*(undefined4 *)(param_2 + 0xc)) {
  case 1:
    uVar3 = *(uint *)(param_2 + 0x10);
    iVar1 = FUN_c0697bdc(uVar3,local_14);
    if (iVar1 == 0) {
      return -0x7fffffce;
    }
    *(uint *)(local_20 + 0xc) = uVar3;
    break;
  case 2:
    iVar4 = *(int *)(param_2 + 0x10);
    iVar1 = FUN_c0697d3c(iVar4,local_18);
    if (iVar1 == 0) {
      return -0x7fffffce;
    }
    *(char *)(local_20 + 0x12) = (char)iVar4;
    break;
  case 3:
    iVar4 = *(int *)(param_2 + 0x10);
    iVar1 = FUN_c0697dc8(iVar4,local_1c);
    if (iVar1 == 0) {
      return -0x7fffffce;
    }
    *(char *)(local_20 + 0x14) = (char)iVar4;
    break;
  case 4:
    iVar4 = *(int *)(param_2 + 0x10);
    iVar1 = FUN_c0697e4c(iVar4,local_1c);
    if (iVar1 == 0) {
      return -0x7fffffce;
    }
    *(char *)(local_20 + 0x13) = (char)iVar4;
    break;
  case 5:
    *(short *)(local_20 + 2) = (short)*(undefined4 *)(param_2 + 0x10);
    break;
  case 6:
    if (0x7ff < *(uint *)(param_2 + 0x10)) {
      return -0x7fffffce;
    }
    *(uint *)(local_20 + 8) = *(uint *)(param_2 + 0x10);
    break;
  case 7:
    *(undefined4 *)(local_20 + 4) = *(undefined4 *)(param_2 + 0x10);
    break;
  case 8:
    if (*(int *)(param_2 + 0x10) == 0) {
      *(undefined2 *)(local_20 + 0x10) = 0;
    }
    else {
      *(undefined2 *)(local_20 + 0x10) = 0;
      if ((*(uint *)(param_2 + 0x10) & 1) != 0) {
        *(undefined2 *)(local_20 + 0x10) = 4;
      }
      if ((*(uint *)(param_2 + 0x10) & 2) != 0) {
        *(ushort *)(local_20 + 0x10) = *(ushort *)(local_20 + 0x10) | 1;
      }
      if ((*(uint *)(param_2 + 0x10) & 4) != 0) {
        *(ushort *)(local_20 + 0x10) = *(ushort *)(local_20 + 0x10) | 2;
      }
    }
    break;
  case 9:
    pszDest = (STRSAFE_LPWSTR)(local_20 + 0x16);
    cchDest = 0x100;
    goto LAB_c0698270;
  case 10:
    pszDest = (STRSAFE_LPWSTR)(local_20 + 0x218);
    cchDest = 8;
LAB_c0698270:
    HVar2 = StringCchCopyW(pszDest,cchDest,*(STRSAFE_LPCWSTR *)(param_2 + 0x10));
    if (HVar2 != 0) {
      return -0x7fffffcb;
    }
    break;
  case 0xb:
    iVar1 = CeSafeCopyMemory(local_20 + 0x22a,*(undefined4 *)(param_2 + 0x10),0x7e);
    if (iVar1 == 0) {
      return -0x7fffffcb;
    }
    break;
  default:
    goto switchD_c0698100_default;
  }
  iVar1 = 0;
switchD_c0698100_default:
  return iVar1;
}



/* c06982d8 FUN_c06982d8 */

/* Boundary evidence: original MIPS .pdata c06982d8..c0698483. Semantic name remains unreviewed. */

int FUN_c06982d8(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  HRESULT HVar3;
  size_t cchDest;
  STRSAFE_LPCWSTR pszSrc;
  undefined4 uVar4;
  int local_10;
  undefined4 uStack_c;
  
  iVar2 = FUN_c0697ea8(param_1,param_2,&local_10,&uStack_c);
  if (iVar2 != 0) {
    return iVar2;
  }
  switch(*(undefined4 *)(param_2 + 0xc)) {
  case 1:
    uVar4 = *(undefined4 *)(local_10 + 0xc);
    goto LAB_c0698354;
  case 2:
    bVar1 = *(byte *)(local_10 + 0x12);
    goto LAB_c0698364;
  case 3:
    *(uint *)(param_2 + 0x10) = (uint)*(byte *)(local_10 + 0x14);
    break;
  case 4:
    bVar1 = *(byte *)(local_10 + 0x13);
LAB_c0698364:
    *(uint *)(param_2 + 0x10) = (uint)bVar1;
    break;
  case 5:
    *(uint *)(param_2 + 0x10) = (uint)*(ushort *)(local_10 + 2);
    break;
  case 6:
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(local_10 + 8);
    break;
  case 7:
    uVar4 = *(undefined4 *)(local_10 + 4);
LAB_c0698354:
    *(undefined4 *)(param_2 + 0x10) = uVar4;
    break;
  case 8:
    *(undefined4 *)(param_2 + 0x10) = 0;
    if ((*(ushort *)(local_10 + 0x10) & 4) != 0) {
      *(undefined4 *)(param_2 + 0x10) = 1;
    }
    if ((*(ushort *)(local_10 + 0x10) & 1) != 0) {
      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 2;
    }
    if ((*(ushort *)(local_10 + 0x10) & 2) != 0) {
      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 4;
    }
    break;
  case 9:
    pszSrc = (STRSAFE_LPCWSTR)(local_10 + 0x16);
    cchDest = 0x100;
    goto LAB_c069841c;
  case 10:
    pszSrc = (STRSAFE_LPCWSTR)(local_10 + 0x218);
    cchDest = 8;
LAB_c069841c:
    HVar3 = StringCchCopyW(*(STRSAFE_LPWSTR *)(param_2 + 0x10),cchDest,pszSrc);
    if (HVar3 != 0) {
      return -0x7fffffcb;
    }
    break;
  case 0xb:
    iVar2 = CeSafeCopyMemory(*(undefined4 *)(param_2 + 0x10),local_10 + 0x22a,0x7e);
    if (iVar2 == 0) {
      return -0x7fffffcb;
    }
    return 0;
  default:
    return -0x7fffffce;
  }
  return 0;
}



/* c0698484 FUN_c0698484 */

/* Boundary evidence: original MIPS .pdata c0698484..c0698647. Semantic name remains unreviewed. */

LSTATUS FUN_c0698484(int param_1,LPCWSTR param_2,LPCWSTR param_3,DWORD param_4,LPBYTE param_5,
                    LPDWORD param_6)

{
  int iVar1;
  LSTATUS LVar2;
  HKEY local_30;
  DWORD local_2c;
  
  local_2c = param_4;
  if (param_2 == (LPCWSTR)0x0) {
    iVar1 = 0;
    local_30 = *(HKEY *)(param_1 + 0x214);
  }
  else {
    iVar1 = RegOpenKeyExW(*(HKEY *)(param_1 + 0x214),param_2,0,0x20019,&local_30);
  }
  if (iVar1 == 0) {
    LVar2 = RegQueryValueExW(local_30,param_3,(LPDWORD)0x0,&local_2c,param_5,param_6);
    if ((LVar2 == 0) && (local_2c != param_4)) {
      LVar2 = 0x3f0;
    }
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_30);
    }
    if (LVar2 == 0) {
      return 0;
    }
  }
  if (param_2 == (LPCWSTR)0x0) {
    LVar2 = 0;
    local_30 = DAT_c069d34c;
  }
  else {
    LVar2 = RegOpenKeyExW(DAT_c069d34c,param_2,0,0x20019,&local_30);
  }
  if (LVar2 == 0) {
    local_2c = param_4;
    LVar2 = RegQueryValueExW(local_30,param_3,(LPDWORD)0x0,&local_2c,param_5,param_6);
    if ((LVar2 == 0) && (local_2c != param_4)) {
      LVar2 = 0x3f0;
    }
    if (param_2 != (LPCWSTR)0x0) {
      RegCloseKey(local_30);
    }
  }
  return LVar2;
}



/* c0698648 FUN_c0698648 */

/* Boundary evidence: original MIPS .pdata c0698648..c06986a3. Semantic name remains unreviewed. */

undefined4 FUN_c0698648(int param_1,LPCWSTR param_2,undefined4 param_3)

{
  LSTATUS LVar1;
  DWORD local_10;
  undefined4 local_c;
  
  local_10 = 4;
  LVar1 = FUN_c0698484(param_1,L"Settings",param_2,4,(LPBYTE)&local_c,&local_10);
  if (LVar1 == 0) {
    param_3 = local_c;
  }
  return param_3;
}



/* c06986a4 FUN_c06986a4 */

/* Boundary evidence: original MIPS .pdata c06986a4..c0698847. Semantic name remains unreviewed. */

void FUN_c06986a4(int param_1)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  uint uVar4;
  DWORD local_40;
  undefined4 local_3c;
  undefined2 local_38 [16];
  uint local_18;
  
  local_18 = DAT_c069d168;
  local_40 = 4;
  LVar1 = FUN_c0698484(param_1,(LPCWSTR)0x0,L"PPPMTU",4,(LPBYTE)&local_3c,&local_40);
  if (LVar1 == 0) {
    *(undefined4 *)(param_1 + 0x21c) = local_3c;
  }
  else {
    *(undefined4 *)(param_1 + 0x21c) = 0x5dc;
  }
  uVar2 = FUN_c0698648(param_1,L"MaxCmd",0x104);
  *(undefined4 *)(param_1 + 0x728) = uVar2;
  local_40 = 4;
  LVar1 = FUN_c0698484(param_1,(LPCWSTR)0x0,L"CmdSendDelay",4,(LPBYTE)&local_3c,&local_40);
  if (LVar1 != 0) {
    uVar2 = FUN_c0698648(param_1,L"CmdSendDelay",0);
    *(undefined4 *)(param_1 + 0x72c) = uVar2;
  }
  uVar4 = *(uint *)(param_1 + 0x72c);
  if (500 < uVar4) {
    uVar4 = 500;
  }
  *(uint *)(param_1 + 0x72c) = uVar4;
  uVar2 = FUN_c0698648(param_1,L"MdmLogFile",0);
  *(undefined4 *)(param_1 + 0x740) = uVar2;
  uVar2 = FUN_c0698648(param_1,L"EscapeDelay",0);
  *(undefined4 *)(param_1 + 0x730) = uVar2;
  uVar2 = FUN_c0698648(param_1,L"EscapeWait",200);
  *(undefined4 *)(param_1 + 0x734) = uVar2;
  uVar2 = FUN_c0698648(param_1,L"HangupWait",4000);
  local_40 = 0x20;
  *(undefined4 *)(param_1 + 0x738) = uVar2;
  LVar1 = FUN_c0698484(param_1,L"Settings",L"DialSuffix",1,(LPBYTE)local_38,&local_40);
  uVar3 = 0x3b;
  if (LVar1 == 0) {
    uVar3 = local_38[0];
  }
  *(undefined2 *)(param_1 + 0x750) = uVar3;
  FUN_c069bce8(local_18);
  return;
}



/* c0698848 FUN_c0698848 */

/* Boundary evidence: original MIPS .pdata c0698848..c0698afb. Semantic name remains unreviewed. */

void FUN_c0698848(void)

{
  undefined4 *puVar1;
  LSTATUS LVar2;
  int iVar3;
  undefined4 *puVar4;
  size_t sVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *hMem;
  uint *lpData;
  DWORD dwIndex;
  wchar_t *_Source;
  DWORD local_348;
  HKEY local_344;
  HKEY local_340;
  wchar_t *local_33c;
  DWORD aDStack_338 [2];
  WCHAR aWStack_330 [128];
  wchar_t awStack_230 [256];
  uint local_30;
  
  local_30 = DAT_c069d168;
  local_33c = L"ExtModems";
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"ExtModems",0,0x20019,&local_344);
  if (LVar2 == 0) {
    dwIndex = 0;
    local_348 = 0x80;
    iVar3 = RegEnumKeyExW(local_344,0,aWStack_330,&local_348,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          (PFILETIME)0x0);
    _Source = L"ExtModems";
    hMem = (undefined4 *)0x0;
    while ((iVar3 == 0 &&
           (puVar4 = LocalAlloc(0x40,0x108), _Source = local_33c, puVar4 != (undefined4 *)0x0))) {
      wcscpy((wchar_t *)(puVar4 + 2),aWStack_330);
      lpData = puVar4 + 1;
      *lpData = 0xffffffff;
      LVar2 = RegOpenKeyExW(local_344,aWStack_330,0,0x20019,&local_340);
      if (LVar2 == 0) {
        local_348 = 4;
        RegQueryValueExW(local_340,L"Order",(LPDWORD)0x0,aDStack_338,(LPBYTE)lpData,&local_348);
        RegCloseKey(local_340);
      }
      if (hMem == (undefined4 *)0x0) {
        *puVar4 = 0;
      }
      else {
        puVar1 = hMem;
        puVar7 = hMem;
        do {
          puVar6 = puVar1;
          if (*lpData < (uint)puVar6[1]) {
            *puVar4 = puVar6;
            if (puVar6 != puVar7) goto LAB_c06989fc;
            goto LAB_c0698a00;
          }
          puVar1 = (undefined4 *)*puVar6;
          puVar7 = puVar6;
        } while ((undefined4 *)*puVar6 != (undefined4 *)0x0);
        *puVar4 = 0;
LAB_c06989fc:
        *puVar7 = puVar4;
        puVar4 = hMem;
      }
LAB_c0698a00:
      dwIndex = dwIndex + 1;
      local_348 = 0x80;
      iVar3 = RegEnumKeyExW(local_344,dwIndex,aWStack_330,&local_348,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      _Source = local_33c;
      hMem = puVar4;
    }
    RegCloseKey(local_344);
    if (hMem != (undefined4 *)0x0) {
      wcscpy(awStack_230,_Source);
      wcscat(awStack_230,L"\\");
      sVar5 = wcslen(awStack_230);
      do {
        puVar4 = (undefined4 *)*hMem;
        wcscpy(awStack_230 + sVar5,(wchar_t *)(hMem + 2));
        FUN_c06952d8((HKEY)0x0,awStack_230,(wchar_t *)0x0);
        LocalFree(hMem);
        hMem = puVar4;
      } while (puVar4 != (undefined4 *)0x0);
    }
  }
  FUN_c069bce8(local_30);
  return;
}



/* c0698afc FUN_c0698afc */

/* Boundary evidence: original MIPS .pdata c0698afc..c0698b7b. Semantic name remains unreviewed. */

void FUN_c0698afc(void)

{
  int iVar1;
  HMODULE hLibModule;
  code *pcVar2;
  
  iVar1 = WaitForAPIReady(0x51,0);
  if ((iVar1 == 0) && (hLibModule = LoadLibraryW(L"COREDLL.DLL"), hLibModule != (HMODULE)0x0)) {
    pcVar2 = (code *)GetProcAddressW(hLibModule,L"SystemIdleTimerReset");
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)();
    }
    FreeLibrary(hLibModule);
  }
  return;
}



/* c0698b7c FUN_c0698b7c */

undefined4 FUN_c0698b7c(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar1 = (int)*param_1;
    if ((0x60 < iVar1) && (iVar1 < 0x7b)) {
      iVar1 = iVar1 + -0x20;
    }
    iVar2 = (int)*param_2;
    if ((iVar2 < 0x61) || (iVar3 = iVar2 + -0x20, 0x7a < iVar2)) {
      iVar3 = iVar2;
    }
    if (iVar1 != iVar3) break;
    if (iVar2 == 0) {
      return 0;
    }
    param_1 = param_1 + 1;
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
  }
  return 1;
}



/* c0698c00 FUN_c0698c00 */

/* Boundary evidence: original MIPS .pdata c0698c00..c0698eb3. Semantic name remains unreviewed. */

undefined4 FUN_c0698c00(wchar_t *param_1,int param_2,uint param_3,wchar_t *param_4)

{
  wchar_t wVar1;
  int iVar2;
  size_t _MaxCount;
  size_t sVar3;
  undefined2 uVar4;
  short sVar5;
  wchar_t wVar6;
  short sVar7;
  uint uVar8;
  
  uVar8 = 0;
  if (param_3 != 0) {
    do {
      if (*param_1 == L'\0') break;
      if (*param_1 != L'<') goto LAB_c0698e44;
      iVar2 = _wcsnicmp(param_1,L"<cr>",4);
      if (iVar2 == 0) {
        uVar4 = 0xd;
LAB_c0698c90:
        *(undefined2 *)(uVar8 * 2 + param_2) = uVar4;
        param_1 = param_1 + 4;
LAB_c0698e58:
        uVar8 = uVar8 + 1;
      }
      else {
        iVar2 = _wcsnicmp(param_1,L"<lf>",4);
        if (iVar2 == 0) {
          uVar4 = 10;
          goto LAB_c0698c90;
        }
        if ((((param_1[1] == L'h') || (param_1[1] == L'H')) &&
            (iVar2 = _isctype((uint)(ushort)param_1[2],0x80), iVar2 != 0)) &&
           ((iVar2 = _isctype((uint)(ushort)param_1[3],0x80), iVar2 != 0 && (param_1[4] == L'>'))))
        {
          wVar1 = param_1[2];
          if (((ushort)wVar1 < 0x30) || (0x39 < (ushort)wVar1)) {
            if (((ushort)wVar1 < 0x61) || (wVar6 = wVar1 + L'￠', 0x7a < (ushort)wVar1)) {
              wVar6 = wVar1;
            }
            sVar7 = wVar6 + L'￉';
          }
          else {
            sVar7 = wVar1 + L'￐';
          }
          wVar1 = param_1[3];
          if (((ushort)wVar1 < 0x30) || (0x39 < (ushort)wVar1)) {
            if (((ushort)wVar1 < 0x61) || (wVar6 = wVar1 + L'￠', 0x7a < (ushort)wVar1)) {
              wVar6 = wVar1;
            }
            sVar5 = wVar6 + L'￉';
          }
          else {
            sVar5 = wVar1 + L'￐';
          }
          *(ushort *)(uVar8 * 2 + param_2) = sVar7 * 0x10 + sVar5 & 0xff;
          param_1 = param_1 + 5;
          goto LAB_c0698e58;
        }
        if (param_4 == (wchar_t *)0x0) {
LAB_c0698e44:
          *(wchar_t *)(uVar8 * 2 + param_2) = *param_1;
          param_1 = param_1 + 1;
          goto LAB_c0698e58;
        }
        _MaxCount = wcslen(param_4);
        iVar2 = _wcsnicmp(param_1,param_4,_MaxCount);
        if (iVar2 != 0) goto LAB_c0698e44;
        sVar3 = wcslen(param_4 + 0x100);
        if (param_3 - uVar8 <= sVar3) break;
        memcpy((void *)(uVar8 * 2 + param_2),param_4 + 0x100,sVar3 << 1);
        uVar8 = sVar3 + uVar8;
        param_1 = param_1 + _MaxCount;
      }
    } while (uVar8 < param_3);
    if (uVar8 < param_3) {
      *(undefined2 *)(uVar8 * 2 + param_2) = 0;
    }
  }
  return 1;
}



/* c0698eb4 FUN_c0698eb4 */

/* Boundary evidence: original MIPS .pdata c0698eb4..c069944b. Semantic name remains unreviewed. */

wchar_t * FUN_c0698eb4(int param_1,int *param_2)

{
  wchar_t wVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  LSTATUS LVar4;
  size_t sVar5;
  size_t sVar6;
  size_t sVar7;
  int iVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  uint uVar11;
  wchar_t *pwVar12;
  wchar_t *_Dest;
  wchar_t *_Str;
  uint local_38;
  wchar_t *local_34;
  wchar_t *local_30;
  int *local_2c;
  
  _Str = (wchar_t *)(param_1 + 0x508);
  pwVar12 = (wchar_t *)0x0;
  if (_Str != (wchar_t *)0x0) {
    *param_2 = 1;
    pwVar3 = _Str;
    if (*_Str != L'\0') {
      do {
        pwVar9 = pwVar3;
        if (*(wchar_t *)(param_1 + 0x750) == *pwVar9) {
          *param_2 = 0;
        }
        pwVar3 = pwVar9 + 1;
      } while (pwVar9[1] != L'\0');
      if (*param_2 == 0) {
        *pwVar9 = L'\0';
      }
    }
    lVar2 = (ulonglong)*(uint *)(param_1 + 0x728) * 8;
    uVar11 = (uint)lVar2;
    local_2c = param_2;
    if (((int)((ulonglong)lVar2 >> 0x20) == 0) && (local_38 = uVar11 + 8, uVar11 <= local_38)) {
      pwVar3 = LocalAlloc(0x40,local_38);
    }
    else {
      pwVar3 = (wchar_t *)0x0;
    }
    if (pwVar3 != (wchar_t *)0x0) {
      iVar8 = *(int *)(param_1 + 0x728);
      local_38 = iVar8 * 2;
      pwVar10 = pwVar3 + iVar8 + 1;
      pwVar9 = pwVar10 + iVar8 + 1;
      local_30 = pwVar9 + iVar8 + 1;
      local_34 = pwVar10;
      LVar4 = FUN_c0698484(param_1,L"Settings",L"Prefix",1,(LPBYTE)pwVar3,&local_38);
      if (LVar4 == 0) {
        FUN_c0698c00(pwVar3,(int)pwVar10,*(uint *)(param_1 + 0x728),(wchar_t *)0x0);
        if (((*(uint *)(param_1 + 0x228) & 0x200) == 0) &&
           ((*(uint *)(param_1 + 0x5f8) & 0x200) == 0)) {
          DAT_c069d188 = L"Blind_Off";
        }
        else {
          DAT_c069d188 = L"Blind_On";
        }
        local_38 = *(int *)(param_1 + 0x728) << 1;
        LVar4 = FUN_c0698484(param_1,L"Settings",L"DialPrefix",1,(LPBYTE)pwVar3,&local_38);
        if (LVar4 == 0) {
          sVar5 = wcslen(pwVar10);
          FUN_c0698c00(pwVar3,(int)(pwVar10 + sVar5),*(uint *)(param_1 + 0x728),(wchar_t *)0x0);
          local_38 = *(int *)(param_1 + 0x728) << 1;
          DAT_c069d184 = L"Tone";
          if ((*(uint *)(param_1 + 0x5f8) & 0x100) == 0) {
            DAT_c069d184 = L"Pulse";
          }
          LVar4 = FUN_c0698484(param_1,L"Settings",DAT_c069d184,1,(LPBYTE)pwVar3,&local_38);
          if (LVar4 == 0) {
            sVar5 = wcslen(pwVar10);
            FUN_c0698c00(pwVar3,(int)(pwVar10 + sVar5),*(uint *)(param_1 + 0x728),(wchar_t *)0x0);
            local_38 = *(int *)(param_1 + 0x728) << 1;
            LVar4 = FUN_c0698484(param_1,L"Settings",L"DialSuffix",1,(LPBYTE)pwVar3,&local_38);
            if (LVar4 == 0) {
              FUN_c0698c00(pwVar3,(int)pwVar9,*(uint *)(param_1 + 0x728),(wchar_t *)0x0);
            }
            else {
              wcscpy(pwVar9,L"");
            }
            local_38 = *(int *)(param_1 + 0x728) << 1;
            LVar4 = FUN_c0698484(param_1,L"Settings",L"Terminator",1,(LPBYTE)pwVar3,&local_38);
            pwVar12 = local_30;
            if (LVar4 == 0) {
              FUN_c0698c00(pwVar3,(int)local_30,*(uint *)(param_1 + 0x728),(wchar_t *)0x0);
              wcscat(pwVar9,pwVar12);
            }
            sVar5 = wcslen(pwVar10);
            sVar6 = wcslen(pwVar9);
            uVar11 = *(int *)(param_1 + 0x728) - (sVar6 + sVar5);
            sVar7 = wcslen(_Str);
            if (sVar7 == 0) {
              iVar8 = 1;
            }
            else {
              if (uVar11 == 0) {
                trap(0x1c00);
              }
              if (uVar11 == 0) {
                trap(0x1c00);
              }
              iVar8 = sVar7 / uVar11 + (uint)(sVar7 % uVar11 != 0);
            }
            local_38 = ((sVar6 + sVar5 + 1) * iVar8 + sVar7 + 1) * 8;
            pwVar12 = LocalAlloc(0x40,local_38);
            if (pwVar12 != (wchar_t *)0x0) {
              local_38 = *(int *)(param_1 + 0x728) << 1;
              LVar4 = FUN_c0698484(param_1,L"Settings",L"Prefix",1,(LPBYTE)pwVar3,&local_38);
              if (LVar4 == 0) {
                FUN_c0698c00(pwVar3,(int)pwVar12,*(uint *)(param_1 + 0x728),(wchar_t *)0x0);
                local_38 = *(int *)(param_1 + 0x728) << 1;
                LVar4 = FUN_c0698484(param_1,L"Settings",DAT_c069d188,1,(LPBYTE)pwVar3,&local_38);
                if (LVar4 == 0) {
                  local_38 = wcslen(pwVar12);
                  FUN_c0698c00(pwVar3,(int)(pwVar12 + local_38),*(int *)(param_1 + 0x728) - local_38
                               ,(wchar_t *)0x0);
                  local_38 = wcslen(pwVar12);
                  FUN_c0698c00(L"<cr>",(int)(pwVar12 + local_38),
                               *(int *)(param_1 + 0x728) - local_38,(wchar_t *)0x0);
                  sVar5 = wcslen(pwVar12);
                  pwVar10 = local_34;
                  _Dest = pwVar12 + sVar5 + 1;
                  wcscpy(_Dest,local_34);
                  local_34 = (wchar_t *)((uint)local_34 & 0xffff);
                  while (wVar1 = *_Str, wVar1 != L'\0') {
                    sVar5 = wcslen(_Dest);
                    sVar6 = wcslen(pwVar9);
                    if (*(uint *)(param_1 + 0x728) < sVar6 + sVar5 + 1) {
                      wcscat(_Dest,pwVar9);
                      sVar5 = wcslen(_Dest);
                      _Dest = _Dest + sVar5 + 1;
                      wcscpy(_Dest,pwVar10);
                    }
                    else {
                      local_34 = (wchar_t *)CONCAT22(local_34._2_2_,wVar1);
                      wcscat(_Dest,(wchar_t *)&local_34);
                      _Str = _Str + 1;
                    }
                  }
                  if (*local_2c != 0) {
                    pwVar9 = local_30;
                  }
                  wcscat(_Dest,pwVar9);
                  goto LAB_c0699410;
                }
              }
              LocalFree(pwVar12);
              pwVar12 = (wchar_t *)0x0;
            }
          }
        }
      }
LAB_c0699410:
      LocalFree(pwVar3);
      return pwVar12;
    }
  }
  return (wchar_t *)0x0;
}



/* c069944c FUN_c069944c */

/* Boundary evidence: original MIPS .pdata c069944c..c069953b. Semantic name remains unreviewed. */

void FUN_c069944c(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  for (; (bVar1 = *param_2, bVar1 != 0 && ((bVar1 < 0x30 || (0x39 < bVar1)))); param_2 = param_2 + 1
      ) {
  }
  uVar2 = (uint)*param_2;
  if (uVar2 != 0) {
    do {
      if ((uVar2 < 0x30) || (0x39 < uVar2)) {
        if (uVar2 == 0x4b) {
          iVar3 = iVar3 * 1000;
        }
        else if (uVar2 != 0x2c) break;
      }
      else {
        iVar3 = iVar3 * 10 + uVar2 + -0x30;
      }
      param_2 = param_2 + 1;
      uVar2 = (uint)*param_2;
    } while (uVar2 != 0);
    if (iVar3 != 0) {
      *(int *)(param_1 + 0x71c) = iVar3;
      if (*(int *)(param_1 + 0x5bc) != 0) {
        FUN_c069502c(param_1,*(int *)(param_1 + 0x5bc),1,8);
      }
    }
  }
  return;
}



/* c069953c FUN_c069953c */

/* Boundary evidence: original MIPS .pdata c069953c..c0699667. Semantic name remains unreviewed. */

undefined2 FUN_c069953c(undefined4 param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  char *_Str;
  undefined **ppuVar5;
  
  for (; (*param_2 == '\r' || (*param_2 == '\n')); param_2 = param_2 + 1) {
  }
  uVar4 = 0xd;
  if (*param_2 != '\0') {
    for (; (*param_3 == '\r' || (*param_3 == '\n')); param_3 = param_3 + 1) {
    }
    sVar1 = strlen(param_2);
    iVar2 = FUN_c0698b7c(param_2,param_3,sVar1);
    if (iVar2 != 0) {
      ppuVar5 = &PTR_DAT_c0691ca0;
      iVar2 = 0;
      do {
        _Str = *ppuVar5;
        sVar1 = strlen(_Str);
        iVar3 = FUN_c0698b7c(param_2,_Str,sVar1);
        if (iVar3 == 0) {
          return (&DAT_c0691ca4)[iVar2 * 4];
        }
        iVar2 = iVar2 + 1;
        ppuVar5 = ppuVar5 + 2;
        uVar4 = 0xc;
      } while (iVar2 < 0x22);
    }
  }
  return uVar4;
}



/* c0699668 FUN_c0699668 */

/* Boundary evidence: original MIPS .pdata c0699668..c069971f. Semantic name remains unreviewed. */

char * FUN_c0699668(wchar_t *param_1,char *param_2,size_t *param_3)

{
  int iVar1;
  size_t sVar2;
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c069d168;
  iVar1 = FUN_c0698c00(param_1,(int)awStack_218,0x100,(wchar_t *)0x0);
  if (iVar1 != 0) {
    sVar2 = wcslen(awStack_218);
    if ((param_2 != (char *)0x0) || (param_2 = LocalAlloc(0x40,sVar2 + 1), param_2 != (char *)0x0))
    {
      sVar2 = wcstombs(param_2,awStack_218,sVar2 + 1);
      if (param_3 != (size_t *)0x0) {
        *param_3 = sVar2;
      }
      FUN_c069bce8(local_18);
      return param_2;
    }
  }
  FUN_c069bce8(local_18);
  return (char *)0x0;
}



/* c0699720 FUN_c0699720 */

/* Boundary evidence: original MIPS .pdata c0699720..c0699863. Semantic name remains unreviewed. */

int FUN_c0699720(int param_1,char *param_2)

{
  BOOL BVar1;
  size_t sVar2;
  int iVar3;
  BOOL BVar4;
  size_t local_1c;
  
  BVar4 = 0;
  if (*(int *)(param_1 + 0x4e8) != -1) {
    if (*(DWORD *)(param_1 + 0x72c) != 0) {
      Sleep(*(DWORD *)(param_1 + 0x72c));
    }
    BVar1 = PurgeComm(*(HANDLE *)(param_1 + 0x4e8),0xc);
    if (BVar1 != 0) {
      sVar2 = strlen(param_2);
      BVar4 = WriteFile(*(HANDLE *)(param_1 + 0x4e8),param_2,sVar2,&local_1c,(LPOVERLAPPED)0x0);
      if ((BVar4 == 0) || (sVar2 = strlen(param_2), local_1c != sVar2)) {
        BVar4 = 0;
      }
    }
  }
  iVar3 = 2;
  if (BVar4 == 0) {
    iVar3 = 3;
  }
  FUN_c06957a4(param_1,param_2,iVar3);
  return BVar4;
}



/* c0699864 FUN_c0699864 */

/* Boundary evidence: original MIPS .pdata c0699864..c069988b. Semantic name remains unreviewed. */

bool FUN_c0699864(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c069988c FUN_c069988c */

/* Boundary evidence: original MIPS .pdata c069988c..c0699fcb. Semantic name remains unreviewed. */

int FUN_c069988c(int param_1,char *param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  BOOL BVar2;
  int iVar3;
  undefined2 extraout_var;
  size_t sVar4;
  uint uVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int local_2c4;
  uint local_2c0;
  int local_2bc;
  int local_2b8;
  DWORD local_2b4;
  code **local_2b0;
  int local_2ac;
  wchar_t *local_2a8;
  int local_2a4;
  char *local_2a0;
  char *local_29c;
  char *local_298;
  int local_294;
  int local_290;
  code **local_28c;
  code **local_288;
  wchar_t *local_284;
  int local_280;
  int local_27c;
  int local_278;
  int local_274;
  byte local_270 [64];
  byte local_230 [256];
  byte local_130 [256];
  uint local_30;
  
  local_30 = DAT_c069d168;
  uVar5 = 0;
  local_2ac = *(int *)(param_1 + 0x5f0);
  local_294 = *(int *)(param_1 + 0x5b0);
  local_2bc = param_4;
  local_2b8 = param_3;
  local_2a4 = param_3;
  local_29c = param_2;
  local_290 = param_1;
  local_278 = local_294;
  local_274 = local_2ac;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  if (*(int *)(param_1 + 0x4f8) != 0) {
    SetCommMask(*(HANDLE *)(param_1 + 0x4e8),0x1f9);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  local_288 = &Sleep_exref;
  local_2b0 = &ReadFile_exref;
  local_28c = &GetLastError_exref;
  local_284 = L"DCCRequest";
  local_298 = "CLIENT";
  local_2a8 = L"DCCResponse";
  local_2a0 = "CLIENTSERVER";
  local_2c4 = 0xd;
  do {
    if ((local_2c4 != 0xd) ||
       ((param_4 != 0 &&
        ((*(int *)(param_1 + 0x4fc) == 0 || (*(int *)(param_1 + 0x5f0) != local_2ac))))))
    goto LAB_c0699f50;
    local_2b4 = 0;
    iVar6 = param_3;
    if (param_3 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
      iVar6 = 0;
      local_2b8 = 0;
      local_2a4 = 0;
    }
    BVar2 = WaitCommEvent(*(HANDLE *)(param_1 + 0x4e8),&local_2b4,(LPOVERLAPPED)0x0);
    param_3 = iVar6;
    if (*(int *)(param_1 + 0x5b0) != local_294) {
      local_2c4 = 3;
      if (*(int *)(param_1 + 0x5b0) == 3) {
        local_2c4 = 0xf;
      }
LAB_c0699f50:
      lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x5dc);
      EnterCriticalSection(lpCriticalSection);
      *(undefined4 *)(param_1 + 0x4f8) = 0x1f9;
      LeaveCriticalSection(lpCriticalSection);
      if (param_3 != 0) {
        LeaveCriticalSection(lpCriticalSection);
      }
      FUN_c069bce8(local_30);
      return local_2c4;
    }
    if (*(int *)(param_1 + 0x73c) != 0) {
      *(undefined4 *)(param_1 + 0x73c) = 0;
      local_2c4 = 0xe;
      goto LAB_c0699f50;
    }
    if (BVar2 == 0) {
      local_2c0 = (**local_28c)();
      local_2c4 = 0xe;
      goto LAB_c0699f50;
    }
    if (local_2b4 == 0) {
      local_2c4 = 3;
      goto LAB_c0699f50;
    }
    if ((local_2b4 & 0x80) != 0) {
      ClearCommError(*(HANDLE *)(param_1 + 0x4e8),&local_2c0,(LPCOMSTAT)0x0);
    }
    if ((local_2b4 & 0x100) != 0) {
      local_2c4 = 8;
    }
    param_3 = local_2b8;
    if ((local_2b4 & 1) != 0) {
      if ((param_4 != 0) &&
         ((param_3 = iVar6, *(int *)(param_1 + 0x4fc) == 0 ||
          (*(int *)(param_1 + 0x5f0) != local_2ac)))) goto LAB_c0699f50;
      iVar3 = (**local_2b0)(*(undefined4 *)(param_1 + 0x4e8),local_130,0xff,&local_2c0,0);
      if (iVar3 == 0) {
        local_2c4 = 0xe;
        param_3 = iVar6;
        goto LAB_c0699f50;
      }
      if (local_2c0 < 0xf) {
        (**local_288)(0x32);
        local_130[local_2c0] = 0;
        iVar6 = (**local_2b0)(*(undefined4 *)(param_1 + 0x4e8),local_130 + local_2c0,
                              0xff - local_2c0,&local_280,0);
        if (iVar6 != 0) {
          local_2c0 = local_280 + local_2c0;
        }
      }
      local_130[local_2c0] = 0;
      FUN_c06957a4(param_1,(char *)local_130,1);
      for (iVar6 = 0; param_3 = local_2b8, param_4 = local_2bc, local_27c = iVar6,
          iVar6 < (int)local_2c0; iVar6 = iVar6 + 1) {
        pbVar7 = local_130 + iVar6;
        pbVar8 = local_230 + uVar5;
        *pbVar8 = *pbVar7;
        iVar3 = FUN_c0694b84(param_1);
        if (iVar3 == 0) {
          if ((((*pbVar7 == 0xd) || (*pbVar7 == 10)) || (iVar6 == local_2c0 - 1)) ||
             (*(int *)(param_1 + 0x728) - 1U <= uVar5)) {
            *pbVar8 = 0;
            uVar1 = FUN_c069953c(param_1,(char *)local_230,local_29c);
            local_2c4 = CONCAT22(extraout_var,uVar1);
            if (local_2c4 == 2) {
              FUN_c069944c(param_1,local_230);
              param_3 = local_2b8;
              goto LAB_c0699f50;
            }
            if (local_2c4 == 9) {
              FUN_c069944c(param_1,local_230);
LAB_c0699cf8:
              FUN_c069509c(param_1,0x200,0);
              if (iVar6 < (int)(local_2c0 - 1)) goto LAB_c0699d20;
            }
            else {
              param_3 = local_2b8;
              if (local_2c4 < 10) goto LAB_c0699f50;
              if (local_2c4 < 0xc) goto LAB_c0699cf8;
              if (0xd < local_2c4) goto LAB_c0699f50;
LAB_c0699d20:
              local_2c4 = 0xd;
            }
            uVar5 = 0;
          }
          else {
            uVar5 = uVar5 + 1 & 0xffff;
          }
        }
        else {
          local_2c4 = 3;
          if (*(int *)(param_1 + 0x5b0) == 1) {
            FUN_c0695e2c(param_1,local_2a8,(char *)local_270,local_2a0);
            iVar3 = 2;
          }
          else {
            FUN_c0695e2c(param_1,local_284,(char *)local_270,local_298);
            iVar3 = 8;
            sVar4 = strlen((char *)local_270);
            if (sVar4 == 0) {
              local_2c4 = 8;
              param_3 = local_2b8;
              goto LAB_c0699f50;
            }
          }
          sVar4 = strlen((char *)local_270);
          if (*pbVar8 == local_270[uVar5]) {
            uVar5 = uVar5 + 1 & 0xffff;
            if (sVar4 <= uVar5) {
              local_230[uVar5] = 0;
              local_2c4 = iVar3;
              param_3 = local_2b8;
              param_4 = local_2bc;
              break;
            }
          }
          else {
            uVar5 = 0;
            if (local_270[0] == *pbVar7) {
              local_230[0] = *pbVar7;
              uVar5 = 1;
            }
          }
        }
      }
    }
  } while( true );
}



/* c0699fcc FUN_c0699fcc */

/* Boundary evidence: original MIPS .pdata c0699fcc..c0699ff3. Semantic name remains unreviewed. */

bool FUN_c0699fcc(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c0699ff4 FUN_c0699ff4 */

/* Boundary evidence: original MIPS .pdata c0699ff4..c069a117. Semantic name remains unreviewed. */

void FUN_c0699ff4(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  DVar1 = param_1[1];
  iVar2 = param_1[2];
  LocalFree(param_1);
  DVar1 = WaitForSingleObject(*(HANDLE *)(iVar3 + 0x5c4),DVar1);
  if (iVar2 != *(int *)(iVar3 + 0x5c8)) {
    return;
  }
  if (DVar1 != 0x102) {
    return;
  }
  *(undefined4 *)(iVar3 + 0x73c) = 1;
  FUN_c0695c18(iVar3);
  iVar2 = *(int *)(iVar3 + 0x5b0);
  if (iVar2 == 1) {
    iVar2 = FUN_c0694b84(iVar3);
    if (iVar2 != 0) {
      return;
    }
    if (*(int *)(iVar3 + 0x5f4) == 2) {
      return;
    }
  }
  else if (iVar2 == 2) {
    FUN_c069509c(iVar3,0x4000,2);
    FUN_c069509c(iVar3,1,0);
  }
  else {
    if (iVar2 == 3) {
      EventModify(*(undefined4 *)(iVar3 + 0x5cc),3);
      return;
    }
    if (iVar2 != 4) {
      return;
    }
  }
  EventModify(*(undefined4 *)(iVar3 + 0x5cc),3);
  FUN_c069425c(iVar3,0x80000048);
  return;
}



/* c069a118 FUN_c069a118 */

/* Boundary evidence: original MIPS .pdata c069a118..c069a223. Semantic name remains unreviewed. */

undefined4 FUN_c069a118(int param_1,int param_2)

{
  int *lpParameter;
  undefined4 uVar1;
  HANDLE hObject;
  wchar_t *pwVar2;
  
  *(int *)(param_1 + 0x5c8) = *(int *)(param_1 + 0x5c8) + 1;
  *(undefined4 *)(param_1 + 0x73c) = 0;
  EventModify(*(undefined4 *)(param_1 + 0x5c4),1);
  if (param_2 == 0) {
LAB_c069a208:
    uVar1 = 0;
  }
  else {
    lpParameter = LocalAlloc(0x40,0xc);
    if (lpParameter == (int *)0x0) {
      pwVar2 = L"UNIMODEM:SetWatchDog Unable to alloc Watchdog info\n";
    }
    else {
      *lpParameter = param_1;
      lpParameter[1] = param_2;
      lpParameter[2] = *(int *)(param_1 + 0x5c8);
      hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0699ff4,lpParameter,0,(LPDWORD)0x0);
      if (hObject != (HANDLE)0x0) {
        CeSetThreadPriority(hObject,DAT_c069d190 + -1);
        CloseHandle(hObject);
        goto LAB_c069a208;
      }
      LocalFree(lpParameter);
      pwVar2 = L"UNIMODEM:SetWatchDog Unable to Create Watchdog Thread\n";
    }
    NKDbgPrintfW(pwVar2);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* c069a224 FUN_c069a224 */

/* Boundary evidence: original MIPS .pdata c069a224..c069ac77. Semantic name remains unreviewed. */

bool FUN_c069a224(int param_1)

{
  bool bVar1;
  LSTATUS LVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *_Dest;
  DWORD DVar7;
  SIZE_T uBytes;
  wchar_t *_Str;
  wchar_t *hMem;
  SIZE_T uBytes_00;
  undefined4 uVar8;
  size_t local_670;
  undefined4 local_66c;
  DWORD local_668 [5];
  int local_654;
  wchar_t *local_650;
  wchar_t *local_64c;
  char *local_648;
  undefined4 local_644;
  int local_640;
  wchar_t awStack_638 [256];
  wchar_t awStack_438 [256];
  char acStack_238 [264];
  char acStack_130 [260];
  uint local_2c;
  
  local_2c = DAT_c069d168;
  iVar6 = 3;
  local_668[3] = 0;
  hMem = (wchar_t *)0x0;
  local_650 = (wchar_t *)0x0;
  local_64c = (wchar_t *)0x0;
  _Dest = (char *)0x0;
  local_648 = (char *)0x0;
  local_668[0] = 4;
  local_668[4] = param_1;
  LVar2 = FUN_c0698484(param_1,L"Init",L"SkipInit",4,(LPBYTE)&local_670,local_668);
  if (LVar2 == 0) {
    FUN_c069bce8(local_2c);
    return true;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  bVar1 = *(int *)(param_1 + 0x5f4) != 2;
  DVar7 = local_668[4];
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x5f4) = 2;
    DVar7 = *(int *)(param_1 + 0x5f0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  if (!bVar1) {
    FUN_c069bce8(local_2c);
    return false;
  }
  local_668[2] = 1;
  local_654 = 0;
  local_66c = 1;
  local_668[1] = 1;
  iVar3 = -0x3fffff6b;
  uVar5 = *(uint *)(param_1 + 0x728) + 1;
  iVar4 = iVar3;
  uBytes_00 = 0xffffffff;
  if (*(uint *)(param_1 + 0x728) <= uVar5) {
    iVar4 = 0;
    uBytes_00 = uVar5;
  }
  if (iVar4 == 0) {
    uBytes = 0xffffffff;
    if ((int)((ulonglong)uBytes_00 * 2 >> 0x20) == 0) {
      iVar3 = 0;
      uBytes = (SIZE_T)((ulonglong)uBytes_00 * 2);
    }
    if (iVar3 == 0) {
      hMem = LocalAlloc(0x40,uBytes);
      local_650 = hMem;
      _Str = LocalAlloc(0x40,uBytes);
      local_64c = _Str;
      _Dest = LocalAlloc(0x40,uBytes_00);
      local_648 = _Dest;
      if (((hMem == (wchar_t *)0x0) || (_Str == (wchar_t *)0x0)) || (_Dest == (char *)0x0)) {
        uVar8 = 1;
      }
      else {
        FUN_c0695ecc(param_1,acStack_130,(char *)0x0,acStack_238);
        if ((*(int *)(param_1 + 0x4fc) != 0) && (*(int *)(param_1 + 0x5f0) == DVar7)) {
          EscapeCommFunction(*(HANDLE *)(param_1 + 0x4e8),6);
          Sleep(400);
        }
        if ((*(int *)(param_1 + 0x4fc) != 0) && (*(int *)(param_1 + 0x5f0) == DVar7)) {
          EscapeCommFunction(*(HANDLE *)(param_1 + 0x4e8),5);
          Sleep(200);
        }
        while (((*(int *)(param_1 + 0x4fc) != 0 && (*(int *)(param_1 + 0x5f0) == DVar7)) &&
               ((int)local_668[3] < 3))) {
          iVar4 = FUN_c069a118(param_1,4000);
          uVar8 = 1;
          if (iVar4 != 0) goto LAB_c069ab80;
          if ((*(int *)(param_1 + 0x4fc) != 0) && (*(int *)(param_1 + 0x5f0) == DVar7)) {
            iVar6 = 3;
            iVar4 = FUN_c0699720(param_1,acStack_238);
            if (iVar4 != 0) {
              iVar6 = FUN_c069988c(param_1,acStack_238,0,1);
            }
          }
          if (iVar6 == 0) {
            iVar4 = 3;
            local_66c = 3;
            local_668[1] = 3;
            goto LAB_c069a64c;
          }
          if (local_654 != 0) goto LAB_c069ab80;
          local_654 = 1;
          if ((*(int *)(param_1 + 0x4fc) != 0) && (*(int *)(param_1 + 0x5f0) == DVar7)) {
            local_66c = 1;
            local_668[1] = 1;
            Sleep(*(DWORD *)(param_1 + 0x730));
            FUN_c0699720(param_1,acStack_130);
            Sleep(*(DWORD *)(param_1 + 0x734));
          }
          local_668[3] = local_668[3] + 1;
          local_640 = local_668[3];
        }
        iVar4 = 1;
LAB_c069a64c:
        if (((iVar4 == 3) && (*(int *)(param_1 + 0x4fc) != 0)) &&
           (*(int *)(param_1 + 0x5f0) == DVar7)) {
          LVar2 = 0;
          uVar5 = 0;
          while (((uVar5 < 5 && (*(int *)(param_1 + 0x4fc) != 0)) &&
                 ((*(int *)(param_1 + 0x5f0) == DVar7 && (LVar2 == 0))))) {
            local_668[0] = *(int *)(param_1 + 0x728) << 1;
            LVar2 = FUN_c0698484(param_1,L"Init",(LPCWSTR)(&PTR_DAT_c0691c0c)[uVar5],1,(LPBYTE)hMem,
                                 local_668);
            if (LVar2 == 0) {
              FUN_c0699668(hMem,_Dest,&local_670);
              iVar4 = FUN_c069a118(param_1,4000);
              uVar8 = local_66c;
              if (iVar4 != 0) goto LAB_c069ab80;
              if ((*(int *)(param_1 + 0x4fc) != 0) && (*(int *)(param_1 + 0x5f0) == DVar7)) {
                iVar6 = 3;
                iVar4 = FUN_c0699720(param_1,_Dest);
                if ((iVar4 != 0) &&
                   ((*(int *)(param_1 + 0x4fc) != 0 && (*(int *)(param_1 + 0x5f0) == DVar7)))) {
                  iVar6 = FUN_c069988c(param_1,_Dest,0,1);
                }
              }
              uVar8 = local_66c;
              if (iVar6 != 0) goto LAB_c069ab80;
            }
            uVar5 = uVar5 + 1 & 0xffff;
          }
          if ((*(uint *)(param_1 + 0x228) & 0x10) == 0) {
            if ((*(uint *)(param_1 + 0x228) & 0x20) == 0) {
              DAT_c069d180 = L"FlowOff";
            }
            else {
              DAT_c069d180 = L"FlowSoft";
            }
          }
          else {
            DAT_c069d180 = L"FlowHard";
          }
          local_668[0] = *(int *)(param_1 + 0x728) << 1;
          LVar2 = FUN_c0698484(param_1,L"Settings",DAT_c069d180,1,(LPBYTE)hMem,local_668);
          if (LVar2 == 0) {
            FUN_c0699668(hMem,_Dest,&local_670);
            if ((*(int *)(param_1 + 0x4fc) != 0) && (*(int *)(param_1 + 0x5f0) == DVar7)) {
              iVar6 = 3;
              iVar4 = FUN_c0699720(param_1,_Dest);
              if ((iVar4 != 0) &&
                 ((*(int *)(param_1 + 0x4fc) != 0 && (*(int *)(param_1 + 0x5f0) == DVar7)))) {
                iVar6 = FUN_c069988c(param_1,_Dest,0,1);
              }
            }
            bVar1 = iVar6 != 0;
            iVar6 = 0;
            uVar8 = local_66c;
            if (bVar1) goto LAB_c069ab80;
          }
          local_668[0] = *(int *)(param_1 + 0x728) << 1;
          LVar2 = FUN_c0698484(param_1,L"Settings",L"CallSetupFailTimeout",1,(LPBYTE)hMem,local_668)
          ;
          if (LVar2 == 0) {
            uVar5 = *(uint *)(param_1 + 0x224);
            if ((0xff < uVar5) || (uVar5 == 0)) {
              uVar5 = 0xff;
            }
            wcscpy(awStack_638,L"<#>");
            StringCchPrintfW(awStack_438,0x100,L"%d",uVar5);
            FUN_c0698c00(hMem,(int)_Str,*(uint *)(param_1 + 0x728),awStack_638);
            local_670 = wcslen(_Str);
            local_670 = local_670 + 1;
            local_670 = wcstombs(_Dest,_Str,local_670);
            if ((*(int *)(param_1 + 0x4fc) != 0) && (*(int *)(param_1 + 0x5f0) == DVar7)) {
              iVar6 = 3;
              iVar4 = FUN_c0699720(param_1,_Dest);
              if ((iVar4 != 0) &&
                 ((*(int *)(param_1 + 0x4fc) != 0 && (*(int *)(param_1 + 0x5f0) == DVar7)))) {
                iVar6 = FUN_c069988c(param_1,_Dest,0,1);
              }
            }
            bVar1 = iVar6 != 0;
            iVar6 = 0;
            uVar8 = local_66c;
            if (bVar1) goto LAB_c069ab80;
          }
          local_670 = wcslen((wchar_t *)(param_1 + 0x236));
          if (local_670 != 0) {
            *_Dest = 'A';
            _Dest[1] = 'T';
            local_670 = local_670 + 1;
            local_670 = wcstombs(_Dest + 2,(wchar_t *)(param_1 + 0x236),local_670);
            strcat(_Dest,"\r");
            if ((*(int *)(param_1 + 0x4fc) != 0) && (*(int *)(param_1 + 0x5f0) == DVar7)) {
              iVar6 = 3;
              iVar4 = FUN_c0699720(param_1,_Dest);
              if ((iVar4 != 0) &&
                 ((*(int *)(param_1 + 0x4fc) != 0 && (*(int *)(param_1 + 0x5f0) == DVar7)))) {
                iVar6 = FUN_c069988c(param_1,_Dest,0,1);
              }
            }
            uVar8 = local_66c;
            if (iVar6 != 0) goto LAB_c069ab80;
          }
        }
        local_668[2] = 0;
        local_644 = 0;
        uVar8 = local_66c;
      }
      goto LAB_c069ab80;
    }
  }
  _Str = (wchar_t *)0x0;
  uVar8 = 1;
LAB_c069ab80:
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  if (local_668[2] == 0) {
    *(undefined4 *)(param_1 + 0x5f4) = uVar8;
  }
  else {
    *(undefined4 *)(param_1 + 0x5f4) = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x5dc));
  *(int *)(param_1 + 0x5c8) = *(int *)(param_1 + 0x5c8) + 1;
  *(undefined4 *)(param_1 + 0x73c) = 0;
  EventModify(*(undefined4 *)(param_1 + 0x5c4),1);
  if (hMem != (wchar_t *)0x0) {
    LocalFree(hMem);
  }
  if (_Dest != (char *)0x0) {
    LocalFree(_Dest);
  }
  if (_Str != (wchar_t *)0x0) {
    LocalFree(_Str);
  }
  iVar6 = *(int *)(param_1 + 0x5f4);
  FUN_c069bce8(local_2c);
  return iVar6 != 1;
}



/* c069ac78 FUN_c069ac78 */

/* Boundary evidence: original MIPS .pdata c069ac78..c069ac9f. Semantic name remains unreviewed. */

bool FUN_c069ac78(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c069aca0 FUN_c069aca0 */

undefined4 FUN_c069aca0(uint param_1)

{
  if (param_1 < 0xdac1) {
    if (param_1 == 56000) {
      return 0x1f400;
    }
    if (param_1 == 0x2580) {
      return 0x3840;
    }
    if (param_1 == 0x3840) {
      return 0x4b00;
    }
    if (param_1 == 0x4b00) {
      return 0xe100;
    }
    if (param_1 == 0x9600) {
      return 56000;
    }
  }
  else {
    if (param_1 == 0xe100) {
      return 0x1c200;
    }
    if (param_1 == 0x1c200) {
      return 0x9600;
    }
    if (param_1 == 0x1f400) {
      return 0x3e800;
    }
    if (param_1 == 0x3e800) {
      return 0x2580;
    }
  }
  return 0x4b00;
}



/* c069ad84 FUN_c069ad84 */

/* Boundary evidence: original MIPS .pdata c069ad84..c069ae7b. Semantic name remains unreviewed. */

undefined4 FUN_c069ad84(int param_1,DWORD param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  uint uVar3;
  _DCB _Stack_38;
  
  BVar1 = GetCommState(*(HANDLE *)(param_1 + 0x4e8),&_Stack_38);
  if (BVar1 == 0) {
    GetLastError();
  }
  else {
    uVar3 = 0;
    if (param_2 != 0) goto LAB_c069ade8;
    do {
      param_2 = FUN_c069aca0(*(uint *)(param_1 + 0x71c));
LAB_c069ade8:
      *(DWORD *)(param_1 + 0x71c) = param_2;
      _Stack_38.BaudRate = param_2;
      BVar1 = PurgeComm(*(HANDLE *)(param_1 + 0x4e8),0xc);
      if (BVar1 == 0) {
        GetLastError();
      }
      BVar1 = SetCommState(*(HANDLE *)(param_1 + 0x4e8),&_Stack_38);
      if (BVar1 != 0) {
        FUN_c0695998(param_1);
        return 1;
      }
      DVar2 = GetLastError();
    } while ((DVar2 == 0x57) && (uVar3 = uVar3 + 1, uVar3 < 9));
  }
  return 0;
}



/* c069ae7c FUN_c069ae7c */

/* Boundary evidence: original MIPS .pdata c069ae7c..c069af33. Semantic name remains unreviewed. */

undefined4 FUN_c069ae7c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  BOOL BVar3;
  uint local_10 [2];
  
  if (((*(int *)(param_1 + 0x4fc) == 0) || (*(int *)(param_1 + 0x5bc) == 0)) ||
     ((iVar2 = FUN_c0694b84(param_1), iVar2 != 0 &&
      ((BVar3 = GetCommModemStatus(*(HANDLE *)(param_1 + 0x4f4),local_10), BVar3 == 0 ||
       ((local_10[0] & 0x80) == 0)))))) {
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x5d0);
    if (((iVar2 == 8) || (((iVar2 == 0x10 || (iVar2 == 0x100)) || (iVar2 == 0x200)))) ||
       (uVar1 = 0, iVar2 == 0x8000)) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* c069af34 FUN_c069af34 */

/* Boundary evidence: original MIPS .pdata c069af34..c069b1d3. Semantic name remains unreviewed. */

undefined4 FUN_c069af34(int param_1,int param_2)

{
  size_t sVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_78;
  DWORD local_74;
  char acStack_70 [64];
  uint local_30;
  
  local_30 = DAT_c069d168;
  local_74 = 4;
  local_78 = 3;
  FUN_c0698484(param_1,L"Settings",L"DCCRetries",4,(LPBYTE)&local_78,&local_74);
  FUN_c0695e2c(param_1,L"DCCRequest",acStack_70,"CLIENT");
  sVar1 = strlen(acStack_70);
  if ((*(uint *)(param_1 + 0x228) & 0x80) == 0) {
    uVar7 = 1;
    *(undefined4 *)(param_1 + 0x720) = 0;
  }
  else {
    uVar7 = 9;
  }
  DVar3 = *(DWORD *)(param_1 + 0x720);
  if (DVar3 == 0) {
    DVar3 = *(DWORD *)(param_1 + 0x22c);
  }
  iVar2 = FUN_c069ad84(param_1,DVar3);
  if ((iVar2 != 0) && (uVar5 = 0, uVar7 != 0)) {
    do {
      uVar6 = 0;
      do {
        iVar2 = 3;
        if (sVar1 == 0) {
LAB_c069b170:
          *(undefined4 *)(param_1 + 0x720) = *(undefined4 *)(param_1 + 0x71c);
          *(uint *)(param_1 + 0x5b8) = *(uint *)(param_1 + 0x5b8) | 2;
          FUN_c069bce8(local_30);
          return 1;
        }
        iVar4 = param_2 * 1000;
        if ((uVar6 == 0) && (*(short *)(param_1 + 0x218) != 6)) {
          iVar4 = 1000;
        }
        iVar4 = FUN_c069a118(param_1,iVar4);
        if (iVar4 != 0) goto LAB_c069b194;
        FUN_c069509c(param_1,0x10,0);
        iVar4 = FUN_c0699720(param_1,acStack_70);
        while (((iVar4 != 0 && (iVar2 = FUN_c069988c(param_1,acStack_70,0,1), iVar2 != 3)) &&
               (iVar2 != 0xe))) {
          if (iVar2 == 2) goto LAB_c069b170;
          iVar4 = FUN_c069ae7c(param_1);
        }
        if (iVar2 == 2) goto LAB_c069b170;
        *(int *)(param_1 + 0x5c8) = *(int *)(param_1 + 0x5c8) + 1;
        *(undefined4 *)(param_1 + 0x73c) = 0;
        EventModify(*(undefined4 *)(param_1 + 0x5c4),1);
        if ((*(int *)(param_1 + 0x5b0) != 1) || (iVar2 = FUN_c069ae7c(param_1), iVar2 == 0))
        goto LAB_c069b194;
        uVar6 = uVar6 + 1;
      } while (uVar6 <= local_78);
      if (uVar5 == 0) {
        *(undefined4 *)(param_1 + 0x71c) = 0x4b00;
      }
      iVar2 = FUN_c069ad84(param_1,0);
    } while ((iVar2 != 0) && (uVar5 = uVar5 + 1, uVar5 < uVar7));
  }
LAB_c069b194:
  *(undefined4 *)(param_1 + 0x720) = 0;
  FUN_c069bce8(local_30);
  return 0;
}



/* c069b1d4 FUN_c069b1d4 */

/* Boundary evidence: original MIPS .pdata c069b1d4..c069b9b7. Semantic name remains unreviewed. */

void FUN_c069b1d4(int param_1,undefined4 param_2,undefined4 param_3,LPHANDLE param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  size_t sVar4;
  SIZE_T uBytes;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  char *_Dest;
  wchar_t *hMem;
  wchar_t *_Str;
  int local_4c;
  wchar_t *local_3c;
  wchar_t *local_38;
  char *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  hMem = (wchar_t *)0x0;
  local_38 = (wchar_t *)0x0;
  _Dest = (char *)0x0;
  local_34 = (char *)0x0;
  uVar8 = *(uint *)(param_1 + 0x224);
  uVar6 = 1;
  local_4c = -0x7fffffb8;
  iVar7 = -0x7fffffb8;
  bVar1 = true;
  local_30 = 0;
  if ((uVar8 == 0) || (0x200 < uVar8)) {
    uVar8 = 0x200;
  }
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x5cc),0);
  FUN_c0698afc();
  if (*(int *)(param_1 + 0x5b0) == 4) {
LAB_c069b3d0:
    hMem = FUN_c0698eb4(param_1,(int *)&local_3c);
    local_38 = hMem;
    if (hMem != (wchar_t *)0x0) {
      iVar3 = -0x3fffff6b;
      uVar5 = *(uint *)(param_1 + 0x728) + 4;
      uBytes = 0xffffffff;
      if (*(uint *)(param_1 + 0x728) <= uVar5) {
        iVar3 = 0;
        uBytes = uVar5;
      }
      if ((iVar3 == 0) && (_Dest = LocalAlloc(0x40,uBytes), local_34 = _Dest, _Dest != (char *)0x0))
      {
        iVar3 = FUN_c069a118(param_1,uVar8 * 1000);
        _Str = hMem;
        if (iVar3 == 0) {
          while ((iVar3 = FUN_c069ae7c(param_1), iVar7 = local_4c, iVar3 != 0 && (*_Str != L'\0')))
          {
            sVar4 = wcslen(_Str);
            wcstombs(_Dest,_Str,sVar4 + 1);
            sVar4 = wcslen(_Str);
            local_3c = _Str + sVar4 + 1;
            FUN_c069509c(param_1,0x10,0);
            FUN_c0699720(param_1,_Dest);
            bVar2 = true;
            while ((iVar7 = FUN_c069ae7c(param_1), _Str = local_3c, iVar7 != 0 && (bVar2))) {
              param_4 = (LPHANDLE)0x1;
              iVar3 = FUN_c069988c(param_1,_Dest,0,1);
              bVar2 = false;
              if ((*(int *)(param_1 + 0x5b0) != 4) && (bVar1)) {
                bVar1 = false;
                local_2c = 0;
                if (((iVar3 == 0) || (iVar3 == 2)) || ((8 < iVar3 && (iVar3 < 0xc)))) {
                  FUN_c069509c(param_1,8,0x20);
                }
              }
              iVar7 = -0x7fffffb8;
              local_4c = -0x7fffffb8;
              switch(iVar3) {
              case 0:
                if ((*local_3c == L'\0') && (iVar7 = strncmp("ATDT",_Dest,4), iVar7 == 0)) {
                  bVar2 = true;
                }
              case 9:
              case 0xb:
                local_4c = 1;
                break;
              default:
                bVar2 = true;
                break;
              case 2:
                *(uint *)(param_1 + 0x5b8) = *(uint *)(param_1 + 0x5b8) | 2;
                local_4c = 0;
                break;
              case 3:
              case 0xe:
                uVar6 = 2;
                goto LAB_c069b850;
              case 4:
                uVar6 = 1;
                goto LAB_c069b850;
              case 5:
                uVar6 = 0x1000;
                goto LAB_c069b850;
              case 6:
                FUN_c069509c(param_1,0x40,0x20);
                uVar6 = 0x20;
                goto LAB_c069b850;
              case 7:
                uVar6 = 0x40;
                goto LAB_c069b850;
              case 0xf:
                uVar6 = 2;
                iVar7 = 2;
                goto LAB_c069b850;
              }
            }
          }
          goto LAB_c069b7b0;
        }
        uVar6 = 2;
      }
    }
  }
  else {
    iVar3 = FUN_c0694b84(param_1);
    if (iVar3 == 0) {
      if ((*(ushort *)(param_1 + 0x230) & 4) == 0) {
        bVar2 = FUN_c069a224(param_1);
        if ((CONCAT31(extraout_var_00,bVar2) == 0) || (*(int *)(param_1 + 0x5f4) == 1)) {
          uVar6 = 0x800;
        }
        else if ((((*(ushort *)(param_1 + 0x230) & 1) == 0) ||
                 (iVar3 = FUN_c069ae7c(param_1), iVar3 == 0)) ||
                (bVar2 = FUN_c06950e4(param_1,0x12e), CONCAT31(extraout_var_01,bVar2) != 0))
        goto LAB_c069b3d0;
      }
      else {
        bVar1 = FUN_c06950e4(param_1,0x12d);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          *(uint *)(param_1 + 0x5b8) = *(uint *)(param_1 + 0x5b8) | 2;
          goto LAB_c069b2e4;
        }
      }
    }
    else {
      iVar7 = FUN_c069af34(param_1,uVar8);
      if (iVar7 == 0) {
        uVar6 = 2;
        iVar7 = local_4c;
      }
      else {
LAB_c069b2e4:
        iVar7 = 0;
LAB_c069b7b0:
        *(int *)(param_1 + 0x5c8) = *(int *)(param_1 + 0x5c8) + 1;
        *(undefined4 *)(param_1 + 0x73c) = 0;
        EventModify(*(undefined4 *)(param_1 + 0x5c4),1);
        if (((*(ushort *)(param_1 + 0x230) & 2) != 0) && (iVar3 = FUN_c069ae7c(param_1), iVar3 != 0)
           ) {
          FUN_c06950e4(param_1,0x12f);
        }
      }
    }
  }
LAB_c069b850:
  uVar9 = 0x10;
  if (iVar7 == 0) {
    *(undefined4 *)(param_1 + 0x5f0) = 9;
    uVar9 = 0x100;
  }
  else {
    if (iVar7 != 1) {
      bVar1 = iVar7 == 2;
      if (bVar1) {
        *(undefined4 *)(param_1 + 0x5d0) = 0x8000;
      }
      *(undefined4 *)(param_1 + 0x5f0) = 0;
      uVar9 = 0x4000;
      goto LAB_c069b8b0;
    }
    *(undefined4 *)(param_1 + 0x5f0) = 4;
  }
  bVar1 = false;
  uVar6 = 0;
LAB_c069b8b0:
  *(int *)(param_1 + 0x5c8) = *(int *)(param_1 + 0x5c8) + 1;
  *(undefined4 *)(param_1 + 0x73c) = 0;
  EventModify(*(undefined4 *)(param_1 + 0x5c4),1);
  if ((*(int *)(param_1 + 0x5b0) == 1) || (*(int *)(param_1 + 0x5b0) == 4)) {
    if (iVar7 == 1) {
      iVar7 = 0;
    }
    FUN_c069425c(param_1,iVar7);
  }
  FUN_c069509c(param_1,uVar9,uVar6);
  iVar7 = FUN_c069ae7c(param_1);
  if (iVar7 == 0) {
    bVar1 = true;
  }
  if (_Dest != (char *)0x0) {
    LocalFree(_Dest);
  }
  if (hMem != (wchar_t *)0x0) {
    LocalFree(hMem);
  }
  EventModify(*(undefined4 *)(param_1 + 0x5cc),3);
  if (bVar1) {
    FUN_c0696b00(param_1,1,uVar6,param_4);
  }
  return;
}



/* c069b9b8 FUN_c069b9b8 */

/* Boundary evidence: original MIPS .pdata c069b9b8..c069b9df. Semantic name remains unreviewed. */

bool FUN_c069b9b8(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c069bb80 entry */

/* Boundary evidence: original MIPS .pdata c069bb80..c069bbf3. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c069bbf4();
    FUN_c069bf44();
  }
  uVar1 = FUN_c0693b3c(param_1,param_2);
  if (param_2 == 0) {
    FUN_c069becc();
  }
  return uVar1;
}



/* c069bbf4 FUN_c069bbf4 */

/* Boundary evidence: original MIPS .pdata c069bbf4..c069bc67. Semantic name remains unreviewed. */

void FUN_c069bbf4(void)

{
  uint uVar1;
  
  if ((DAT_c069d168 == 0) || (DAT_c069d168 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c069d168 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c069d168 == 0) {
      DAT_c069d168 = 0xb064;
    }
  }
  DAT_c069d16c = ~DAT_c069d168;
  return;
}



/* c069bc68 FUN_c069bc68 */

/* Boundary evidence: original MIPS .pdata c069bc68..c069bcbb. Semantic name remains unreviewed. */

void FUN_c069bc68(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c069bce8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c069bcbc FUN_c069bcbc */

/* Boundary evidence: original MIPS .pdata c069bcbc..c069bce7. Semantic name remains unreviewed. */

undefined4 FUN_c069bcbc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c069bc68(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c069bce8 FUN_c069bce8 */

/* Boundary evidence: original MIPS .pdata c069bce8..c069bd2f. Semantic name remains unreviewed. */

void FUN_c069bce8(uint param_1)

{
  if ((param_1 == DAT_c069d168) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c069bd30 FUN_c069bd30 */

/* Boundary evidence: original MIPS .pdata c069bd30..c069bdab. Semantic name remains unreviewed. */

void FUN_c069bd30(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c069bc68(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c069bdac FUN_c069bdac */

/* Boundary evidence: original MIPS .pdata c069bdac..c069becb. Semantic name remains unreviewed. */

void FUN_c069bdac(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c069d18c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c069d384;
    if (DAT_c069d384 != (undefined4 *)0x0) {
      while (DAT_c069d380 = DAT_c069d380 + -1, _Memory <= DAT_c069d380) {
        if ((code *)*DAT_c069d380 != (code *)0x0) {
          (*(code *)*DAT_c069d380)();
          _Memory = DAT_c069d384;
        }
      }
      free(_Memory);
      DAT_c069d380 = (undefined4 *)0x0;
      DAT_c069d384 = (undefined4 *)0x0;
    }
    FUN_c069bef0((undefined4 *)&DAT_c0691010,(undefined4 *)&DAT_c0691014);
  }
  FUN_c069bef0((undefined4 *)&DAT_c0691018,(undefined4 *)&DAT_c069101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c069d388,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c069becc FUN_c069becc */

/* Boundary evidence: original MIPS .pdata c069becc..c069beef. Semantic name remains unreviewed. */

void FUN_c069becc(void)

{
  FUN_c069bdac(0,0,1);
  return;
}



/* c069bef0 FUN_c069bef0 */

/* Boundary evidence: original MIPS .pdata c069bef0..c069bf43. Semantic name remains unreviewed. */

void FUN_c069bef0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c069bf44 FUN_c069bf44 */

/* Boundary evidence: original MIPS .pdata c069bf44..c069bf7f. Semantic name remains unreviewed. */

void FUN_c069bf44(void)

{
  FUN_c069bef0((undefined4 *)&DAT_c0691008,(undefined4 *)&DAT_c069100c);
  FUN_c069bef0((undefined4 *)&DAT_c0691000,(undefined4 *)&DAT_c0691004);
  return;
}


