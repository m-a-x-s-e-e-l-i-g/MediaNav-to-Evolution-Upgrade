/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 401011cc FUN_401011cc */

/* Boundary evidence: original MIPS .pdata 401011cc..40101207. Semantic name remains unreviewed. */

undefined4 FUN_401011cc(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_4010e398 = param_1;
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 40101208 FUN_40101208 */

/* Boundary evidence: original MIPS .pdata 40101208..4010129f. Semantic name remains unreviewed. */

void FUN_40101208(int param_1,UINT param_2,UINT param_3)

{
  if (*(int *)(param_1 + 0x1140) != 0) {
    LoadStringW(DAT_4010e398,param_2,(LPWSTR)&DAT_4010e3b0,0x104);
    LoadStringW(DAT_4010e398,param_3,(LPWSTR)&DAT_4010e39c,10);
    (**(code **)(param_1 + 0x1140))(&DAT_4010e3b0,&DAT_4010e39c,0);
  }
  return;
}



/* 401012a0 FUN_401012a0 */

/* Boundary evidence: original MIPS .pdata 401012a0..401012f7. Semantic name remains unreviewed. */

undefined4 FUN_401012a0(int param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(HANDLE *)(param_1 + 0x1144) != (HANDLE)0x0) &&
     (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x1144),0), DVar1 == 0)) {
    uVar2 = 1;
    SetLastError(0x4c7);
  }
  return uVar2;
}



/* 401012f8 FUN_401012f8 */

/* Boundary evidence: original MIPS .pdata 401012f8..4010147b. Semantic name remains unreviewed. */

undefined4
FUN_401012f8(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 *param_4,
            undefined4 param_5,int param_6,int *param_7,undefined4 param_8)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  undefined3 extraout_var;
  UINT UVar4;
  uint local_20;
  undefined4 local_1c;
  
  SetLastError(0);
  if (param_4 == (undefined4 *)0x0) {
    local_1c = 1;
    local_20 = 0;
  }
  else {
    local_1c = *param_4;
    local_20 = param_4[1];
  }
  param_1[0x450] = param_6;
  param_1[0x451] = param_8;
  iVar2 = FUN_40106468(param_1,param_2,param_3,&local_20,0,param_6,param_8);
  if (iVar2 == 0) {
    UVar4 = 0xc81;
  }
  else {
    iVar2 = FUN_401069c0(param_1);
    if (iVar2 != 0) {
      param_1[6] = 1;
      iVar2 = FUN_401065c0(param_1);
      if (iVar2 != 0) {
        if (param_1[0x23] == 0) {
          if (param_7 != (int *)0x0) {
            FUN_40107b38(param_1 + 0x1b,param_7);
          }
          memcpy(param_1 + 0x43e,param_1 + 0x25,0x44);
          param_1[0x43b] = param_1[0x447];
          param_1[0x43a] = param_2;
          param_1[0x43c] = 0;
          param_1[0x43d] = 1;
          param_1[0x43c] = param_1 + 0x43e;
          bVar1 = FUN_401073dc((int)(param_1 + 0x36),param_1[5]);
          if (CONCAT31(extraout_var,bVar1) != 0) {
            return 1;
          }
        }
        UVar4 = 0xc82;
        goto LAB_4010144c;
      }
    }
    DVar3 = GetLastError();
    if (DVar3 == 0x4c7) {
      return 0;
    }
    UVar4 = 0xc81;
  }
LAB_4010144c:
  FUN_40101208((int)param_1,UVar4,0xd4b);
  return 0;
}



/* 4010147c FUN_4010147c */

/* Boundary evidence: original MIPS .pdata 4010147c..401015e3. Semantic name remains unreviewed. */

bool FUN_4010147c(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  HANDLE pvVar1;
  LPVOID lpMem;
  BOOL BVar2;
  int iVar3;
  uint uVar4;
  
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,*(SIZE_T *)(param_1 + 0x111c));
  if (lpMem != (LPVOID)0x0) {
    if (param_2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x1120) * (param_2 + -2) + *(int *)(param_1 + 0x1110);
    }
    if (*(uint *)(param_1 + 0x111c) == 0) {
      trap(0x1c00);
    }
    iVar3 = param_3 / *(uint *)(param_1 + 0x111c) + iVar3;
    BVar2 = FUN_40107c94((undefined4 *)(param_1 + 0x10e8),iVar3,lpMem,1);
    if (BVar2 != 0) {
      uVar4 = param_3 % *(uint *)(param_1 + 0x111c);
      if (*(uint *)(param_1 + 0x111c) == 0) {
        trap(0x1c00);
      }
      *(short *)((int)lpMem + uVar4 + 0x1a) = (short)param_4;
      *(short *)((int)lpMem + uVar4 + 0x14) = (short)((uint)param_4 >> 0x10);
      BVar2 = FUN_40107bfc((undefined4 *)(param_1 + 0x10e8),iVar3,lpMem,1);
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,lpMem);
      return BVar2 != 0;
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,lpMem);
  }
  return false;
}



/* 401015e4 FUN_401015e4 */

/* Boundary evidence: original MIPS .pdata 401015e4..40101823. Semantic name remains unreviewed. */

undefined4
FUN_401015e4(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            uint param_7)

{
  ushort *puVar1;
  bool bVar2;
  HANDLE pvVar3;
  char *lpMem;
  BOOL BVar4;
  undefined3 extraout_var;
  int iVar5;
  uint *puVar6;
  undefined4 uVar7;
  ushort *puVar8;
  int *piVar9;
  
  pvVar3 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar3,0,*(SIZE_T *)(param_1 + 0x1124));
  uVar7 = 0;
  if (lpMem == (char *)0x0) {
    uVar7 = 0;
  }
  else {
    BVar4 = FUN_40107d74((undefined4 *)(param_1 + 0x10e8),param_2,lpMem);
    if (BVar4 != 0) {
      if (((param_7 & 2) != 0) && ((param_7 & 4) != 0)) {
        *(short *)(lpMem + 0x1a) = (short)param_3;
        *(short *)(lpMem + 0x14) = (short)(param_3 >> 0x10);
      }
      BVar4 = FUN_40107d2c((undefined4 *)(param_1 + 0x10e8),param_3,lpMem);
      if (BVar4 != 0) {
        piVar9 = (int *)(param_1 + 0x40);
        FUN_40108830(piVar9,param_3,param_5);
        if ((param_7 & 4) == 0) {
          iVar5 = FUN_40108830(piVar9,param_4,param_3);
        }
        else {
          bVar2 = FUN_4010147c(param_1,param_4,param_6,param_3);
          iVar5 = CONCAT31(extraout_var,bVar2);
        }
        if ((iVar5 != 0) && (iVar5 = FUN_40108830(piVar9,param_2,0), iVar5 != 0)) {
          FUN_40108010((int *)(param_1 + 0x20),param_3);
          FUN_40108084((int *)(param_1 + 0x20),param_2);
          if (((param_7 & 1) != 0) && (((param_7 & 2) != 0 && (*lpMem != '\0')))) {
            puVar8 = (ushort *)(lpMem + 0x14);
            do {
              if (*(char **)(param_1 + 0x1124) <= (char *)((int)puVar8 + (-0x14 - (int)lpMem)))
              break;
              if (((((char)puVar8[-10] != '.') && ((*(byte *)((int)puVar8 + -9) & 0x1f) != 0xf)) &&
                  ((char)puVar8[-10] != -0x1b)) &&
                 (puVar6 = FUN_40107588(param_1 + 0xd8,(uint)*puVar8 * 0x10000 + (uint)puVar8[3]),
                 puVar6 != (uint *)0x0)) {
                puVar6[2] = param_3;
              }
              puVar1 = puVar8 + 6;
              puVar8 = puVar8 + 0x10;
            } while ((char)*puVar1 != '\0');
          }
          uVar7 = 1;
        }
      }
    }
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,lpMem);
  }
  return uVar7;
}



/* 40101824 FUN_40101824 */

/* Boundary evidence: original MIPS .pdata 40101824..40101977. Semantic name remains unreviewed. */

int FUN_40101824(int param_1,int *param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar5 = 0;
  iVar6 = 0;
  puVar1 = (uint *)FUN_40107304(param_2,0);
  uVar3 = *puVar1;
  uVar8 = 0;
  do {
    uVar7 = uVar3;
    iVar4 = FUN_401053d4(param_1,uVar7,6);
    if (iVar4 != 0) {
      puVar1[1] = uVar5;
      puVar1[3] = 0xffffffff;
      return iVar6;
    }
    puVar2 = puVar1;
    if ((uVar8 != 0) && (uVar7 != uVar8 + 1)) {
      puVar1[1] = uVar5;
      puVar1[3] = uVar7;
      puVar2 = (uint *)FUN_4010749c(param_1 + 0xd8);
      if (puVar2 == (uint *)0x0) {
        return -1;
      }
      puVar2[4] = 0xfffffff;
      if (param_3 != 0) {
        puVar2[4] = 0x8fffffff;
      }
      puVar2[2] = *puVar1;
      *puVar2 = uVar7;
      FUN_40107348(param_2,(int)puVar2);
      uVar5 = 0;
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 1;
    uVar3 = FUN_40108734((int *)(param_1 + 0x40),uVar7);
    puVar1 = puVar2;
    uVar8 = uVar7;
  } while (uVar3 != 0xfffffffe);
  return -1;
}



/* 40101978 FUN_40101978 */

/* Boundary evidence: original MIPS .pdata 40101978..40101c03. Semantic name remains unreviewed. */

undefined4 FUN_40101978(int param_1,uint *param_2,int param_3)

{
  byte bVar1;
  HANDLE pvVar2;
  char *lpMem;
  LPVOID lpMem_00;
  BOOL BVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  
  pvVar2 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar2,0,*(SIZE_T *)(param_1 + 0x1124));
  pvVar2 = GetProcessHeap();
  lpMem_00 = HeapAlloc(pvVar2,0,*(SIZE_T *)(param_1 + 0x111c));
  uVar4 = *param_2;
  uVar6 = 0;
  if ((lpMem == (char *)0x0) || (lpMem_00 == (LPVOID)0x0)) {
    uVar6 = 0;
  }
  else {
    do {
      uVar7 = 0;
      if (param_2[1] != 0) {
        puVar8 = (undefined4 *)(param_1 + 0x10e8);
        do {
          BVar3 = FUN_40107d74(puVar8,*param_2 + uVar7,lpMem);
          if (BVar3 == 0) goto LAB_40101b94;
          pcVar5 = lpMem;
          if (*lpMem != '\0') {
            do {
              if (*(byte **)(param_1 + 0x1124) <= pcVar5 + 0xb + (-0xb - (int)lpMem)) break;
              bVar1 = pcVar5[0xb];
              if (((((bVar1 & 0x10) != 0) && (*pcVar5 != '.')) && (*pcVar5 != -0x1b)) &&
                 ((bVar1 & 0x1f) != 0xf)) {
                iVar9 = ((uint)*(ushort *)(pcVar5 + 0x14) * 0x10000 +
                         (uint)*(ushort *)(pcVar5 + 0x1a) + -2) * *(int *)(param_1 + 0x1120) +
                        *(int *)(param_1 + 0x1110);
                BVar3 = FUN_40107c94(puVar8,iVar9,lpMem_00,1);
                if (BVar3 == 0) goto LAB_40101b94;
                if (*(char *)((int)lpMem_00 + 0x21) == '.') {
                  *(short *)((int)lpMem_00 + 0x3a) = (short)uVar4;
                  *(short *)((int)lpMem_00 + 0x34) = (short)(uVar4 >> 0x10);
                }
                BVar3 = FUN_40107bfc(puVar8,iVar9,lpMem_00,1);
                if (BVar3 == 0) goto LAB_40101b94;
              }
              pcVar5 = pcVar5 + 0x20;
            } while (*pcVar5 != '\0');
          }
        } while (((*(uint *)(param_1 + 0x1124) <= (uint)((int)pcVar5 - (int)lpMem)) ||
                 (*pcVar5 != '\0')) && (uVar7 = uVar7 + 1, uVar7 < param_2[1]));
      }
      if (param_3 == 0) {
        param_2 = (uint *)param_2[5];
      }
      else {
        param_2 = FUN_40107588(param_1 + 0xd8,param_2[3]);
      }
    } while (param_2 != (uint *)0x0);
    uVar6 = 1;
LAB_40101b94:
    pvVar2 = GetProcessHeap();
    HeapFree(pvVar2,0,lpMem);
    pvVar2 = GetProcessHeap();
    HeapFree(pvVar2,0,lpMem_00);
  }
  return uVar6;
}



/* 40101c04 FUN_40101c04 */

/* Boundary evidence: original MIPS .pdata 40101c04..40101deb. Semantic name remains unreviewed. */

undefined4 FUN_40101c04(int param_1,uint *param_2,int param_3,int param_4,uint param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar7 = 1;
  bVar1 = (param_2[4] & 0x80000000) != 0;
  iVar2 = FUN_401012a0(param_1);
  if (iVar2 == 0) {
    uVar6 = 0;
    if (param_2[1] != 0) {
      do {
        if (uVar6 == 0) {
          uVar3 = param_2[2];
        }
        else {
          uVar3 = (uVar6 + param_5) - 1;
        }
        if (uVar6 == param_2[1] - 1) {
          uVar5 = param_2[3];
        }
        else {
          uVar5 = *param_2 + uVar6 + 1;
        }
        if ((uVar6 == 0) && (param_3 != 0)) {
          uVar3 = (*(int *)(param_3 + 4) + uVar3) - 1;
        }
        uVar4 = (uint)(param_6 != 0);
        if (bVar1) {
          uVar4 = uVar4 | 2;
        }
        if ((uVar6 == 0) && ((param_2[4] & 0x7fffffff) != 0xfffffff)) {
          uVar4 = uVar4 | 4;
        }
        iVar2 = FUN_401015e4(param_1,*param_2 + uVar6,uVar6 + param_5,uVar3,uVar5,
                             param_2[4] & 0x7fffffff,uVar4);
        if (iVar2 == 0) goto LAB_40101c6c;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_2[1]);
    }
    if (param_3 != 0) {
      *(uint *)(param_3 + 0xc) = param_5;
    }
    if (param_4 != 0) {
      *(uint *)(param_4 + 8) = param_5;
    }
    *param_2 = param_5;
    if ((bVar1) && ((param_2[4] & 0x7fffffff) != 0xfffffff)) {
      FUN_40101978(param_1,param_2,param_6);
    }
  }
  else {
LAB_40101c6c:
    uVar7 = 0;
  }
  return uVar7;
}



/* 40101dec FUN_40101dec */

/* Boundary evidence: original MIPS .pdata 40101dec..40101faf. Semantic name remains unreviewed. */

undefined4 FUN_40101dec(int param_1,int *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = FUN_40108154((int *)(param_1 + 0x20),param_3);
  if (uVar1 != 0xfffffffe) {
    puVar2 = (uint *)FUN_4010749c(param_1 + 0xd8);
    if (puVar2 != (uint *)0x0) {
      uVar5 = 0;
      uVar7 = uVar1;
      if (param_2[1] != 0) {
        do {
          puVar3 = (uint *)FUN_40107304(param_2,uVar5);
          if (uVar5 == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = FUN_40107304(param_2,uVar5 - 1);
          }
          if (uVar5 < param_2[1] - 1U) {
            iVar4 = FUN_40107304(param_2,uVar5 + 1);
          }
          else {
            iVar4 = 0;
          }
          iVar6 = FUN_40101c04(param_1,puVar3,iVar6,iVar4,uVar7,param_4);
          if (iVar6 == 0) {
            return 0;
          }
          uVar5 = uVar5 + 1;
          uVar7 = puVar3[1] + uVar7;
        } while (uVar5 < (uint)param_2[1]);
      }
      iVar6 = FUN_40107304(param_2,0);
      puVar2[1] = param_3;
      *puVar2 = uVar1;
      puVar2[2] = *(uint *)(iVar6 + 8);
      puVar2[3] = 0xffffffff;
      uVar1 = *(uint *)(iVar6 + 0x10);
      puVar2[4] = uVar1;
      if ((*(uint *)(iVar6 + 0x10) & 0x80000000) != 0) {
        puVar2[4] = uVar1 | 0x80000000;
      }
      FUN_40107528(param_2,param_1 + 0xd8);
      FUN_40107348(param_2,(int)puVar2);
      return 1;
    }
  }
  return 0;
}



/* 40101fb0 FUN_40101fb0 */

/* Boundary evidence: original MIPS .pdata 40101fb0..40102077. Semantic name remains unreviewed. */

undefined4 FUN_40101fb0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_18;
  uint local_14;
  
  local_18 = 0;
  local_14 = 0;
  puVar1 = (undefined4 *)FUN_4010749c(param_1 + 0xd8);
  *puVar1 = *param_2;
  puVar1[2] = param_2[2];
  puVar1[4] = param_2[4];
  FUN_40107348(&local_18,(int)puVar1);
  uVar2 = FUN_40101824(param_1,&local_18,0);
  if (uVar2 == 0xffffffff) {
    uVar3 = 0;
  }
  else {
    if (1 < local_14) {
      FUN_40101dec(param_1,&local_18,uVar2,0);
    }
    FUN_40107648(param_1 + 0xd8,&local_18);
    uVar3 = 1;
  }
  return uVar3;
}



/* 40102078 FUN_40102078 */

/* Boundary evidence: original MIPS .pdata 40102078..4010221f. Semantic name remains unreviewed. */

undefined4 FUN_40102078(int param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int local_30;
  uint local_2c;
  
  local_30 = 0;
  local_2c = 0;
  iVar7 = 0;
  piVar1 = (int *)FUN_4010749c(param_1 + 0xd8);
  *piVar1 = *param_2;
  piVar1[2] = param_2[2];
  piVar1[4] = param_2[4] | 0x80000000;
  FUN_40107348(&local_30,(int)piVar1);
  uVar4 = 1;
  uVar2 = FUN_40101824(param_1,&local_30,1);
  if (uVar2 == 0xffffffff) {
LAB_40102110:
    uVar4 = 0;
  }
  else {
    if ((1 < local_2c) && (*param_2 != *(int *)(param_1 + 0x1130))) {
      FUN_40101dec(param_1,&local_30,uVar2,0);
    }
    uVar2 = 0;
    if (local_2c != 0) {
      do {
        piVar1 = (int *)FUN_40107304(&local_30,uVar2);
        uVar5 = 0;
        if (piVar1[1] != 0) {
          uVar3 = *(uint *)(param_1 + 0x1120);
          do {
            uVar6 = 0;
            if (uVar3 != 0) {
              do {
                if (iVar7 != 0) break;
                iVar7 = FUN_401025bc(param_1,*piVar1 + uVar5,uVar6);
                uVar3 = *(uint *)(param_1 + 0x1120);
                uVar6 = uVar6 + 1;
              } while (uVar6 < uVar3);
            }
            if (iVar7 == 2) goto LAB_40102110;
            uVar5 = uVar5 + 1;
          } while (uVar5 < (uint)piVar1[1]);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_2c);
    }
    FUN_40107648(param_1 + 0xd8,&local_30);
  }
  return uVar4;
}



/* 40102220 FUN_40102220 */

/* Boundary evidence: original MIPS .pdata 40102220..401023df. Semantic name remains unreviewed. */

undefined4 FUN_40102220(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  
  uVar6 = 2;
  uVar7 = 2;
  if (1 < *(uint *)(param_1 + 0x1104)) {
    do {
      for (; (iVar1 = FUN_401080fc((int *)(param_1 + 0x20),uVar7), iVar1 != 0 &&
             (uVar7 <= *(uint *)(param_1 + 0x1104))); uVar7 = uVar7 + 1) {
      }
      if (uVar6 <= uVar7) {
        uVar6 = uVar7 + 1;
      }
      while( true ) {
        iVar1 = FUN_401080fc((int *)(param_1 + 0x20),uVar6);
        if (*(uint *)(param_1 + 0x1104) < uVar6) {
          return 1;
        }
        if (iVar1 != 0) break;
        uVar6 = uVar6 + 1;
      }
      iVar1 = param_1 + 0xd8;
      puVar2 = FUN_401076b0(iVar1,uVar6);
      if (puVar2 == (uint *)0x0) {
        uVar6 = uVar6 + 1;
        uVar7 = uVar6;
      }
      else {
        if (puVar2[3] == 0xffffffff) {
          puVar8 = (uint *)0x0;
        }
        else {
          puVar8 = FUN_40107588(iVar1,puVar2[3]);
        }
        if ((puVar2[4] & 0x7fffffff) == 0xfffffff) {
          puVar3 = FUN_40107588(iVar1,puVar2[2]);
        }
        else {
          puVar3 = (uint *)0x0;
        }
        iVar4 = FUN_40101c04(param_1,puVar2,(int)puVar3,(int)puVar8,uVar7,1);
        if (iVar4 == 0) {
          return 0;
        }
        uVar5 = puVar2[1];
        uVar6 = uVar5 + uVar6;
        FUN_401075c4(iVar1,puVar2);
        uVar7 = uVar5 + uVar7;
      }
    } while (uVar6 <= *(uint *)(param_1 + 0x1104));
  }
  return 1;
}



/* 401023e0 FUN_401023e0 */

/* Boundary evidence: original MIPS .pdata 401023e0..401025bb. Semantic name remains unreviewed. */

void FUN_401023e0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_30 [2];
  
  uVar5 = *(uint *)(param_1 + 0x10e4);
  uVar8 = 1;
  uVar4 = uVar5 + 1;
  uVar7 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  if (*(int *)(param_1 + 0x10f8) == 0x20) {
    uVar3 = *(uint *)(param_1 + 0x1130);
    while ((puVar1 = FUN_40107588(param_1 + 0xd8,uVar3), puVar1 != (uint *)0x0 &&
           (uVar3 = puVar1[3], uVar3 != 0xffffffff))) {
      uVar7 = uVar7 + 1;
    }
  }
  do {
    if (uVar5 <= uVar7) {
      return;
    }
    if (4 < uVar8) {
      return;
    }
    if (uVar4 <= uVar5) {
      return;
    }
    iVar6 = param_1 + 0xd8;
    while (puVar1 = (uint *)FUN_401074c4(iVar6), puVar1 != (uint *)0x0) {
      iVar9 = 0;
      if ((((puVar1[4] & 0x7fffffff) != 0xfffffff) && (puVar1[3] != 0xffffffff)) &&
         (*puVar1 != *(uint *)(param_1 + 0x1130))) {
        puVar1 = FUN_401076b0(iVar6,*puVar1);
        if (puVar1 == (uint *)0x0) break;
        do {
          puVar2 = puVar1;
          if (puVar1[3] == 0xffffffff) break;
          puVar2 = FUN_401076b0(iVar6,puVar1[3]);
          iVar9 = puVar1[1] + iVar9;
          FUN_40107348(local_30,(int)puVar1);
          puVar1 = puVar2;
        } while (puVar2 != (uint *)0x0);
        if (puVar2 == (uint *)0x0) break;
        uVar4 = puVar2[1];
        FUN_40107348(local_30,(int)puVar2);
        FUN_40101dec(param_1,local_30,uVar4 + iVar9,1);
        FUN_40107648(iVar6,local_30);
      }
    }
    uVar3 = *(uint *)(param_1 + 0x10e4);
    uVar8 = uVar8 + 1;
    iVar6 = FUN_40102220(param_1);
    uVar4 = uVar5;
    uVar5 = uVar3;
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}



/* 401025bc FUN_401025bc */

/* Boundary evidence: original MIPS .pdata 401025bc..40102867. Semantic name remains unreviewed. */

undefined4 FUN_401025bc(int param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  HANDLE pvVar3;
  char *lpMem;
  BOOL BVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  int local_48 [2];
  int local_40;
  int local_38;
  undefined4 local_34;
  uint local_30;
  
  local_30 = DAT_4010e38c;
  pvVar3 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar3,0,*(SIZE_T *)(param_1 + 0x111c));
  uVar11 = *(uint *)(param_1 + 0x111c) >> 5;
  uVar9 = 0;
  uVar10 = 0;
  iVar5 = param_3;
  if (param_2 != 0) {
    iVar5 = *(int *)(param_1 + 0x1120) * (param_2 + -2) + *(int *)(param_1 + 0x1110) + param_3;
  }
  if (lpMem != (char *)0x0) {
    BVar4 = FUN_40107c94((undefined4 *)(param_1 + 0x10e8),iVar5,lpMem,1);
    if (BVar4 != 0) {
      cVar1 = *lpMem;
      iVar5 = local_48[0];
      do {
        local_48[0] = iVar5;
        if (cVar1 == '\0') {
          if ((uVar9 < uVar11) && (lpMem[uVar9 * 0x20] == '\0')) {
            uVar10 = 1;
          }
LAB_40102810:
          pvVar3 = GetProcessHeap();
          HeapFree(pvVar3,0,lpMem);
          FUN_4010d048(local_30);
          return uVar10;
        }
        if (uVar11 <= uVar9) goto LAB_40102810;
        pbVar6 = (byte *)(lpMem + uVar9 * 0x20 + 0xb);
        bVar2 = *pbVar6;
        while ((bVar2 & 0x1f) == 0xf) {
          uVar9 = uVar9 + 1;
          pbVar6 = pbVar6 + 0x20;
          if (uVar11 <= uVar9) break;
          bVar2 = *pbVar6;
        }
        iVar8 = uVar9 * 0x20;
        pcVar7 = lpMem + iVar8;
        cVar1 = *pcVar7;
        if ((cVar1 != '\0') && (uVar9 < uVar11)) {
          if (cVar1 != -0x1b) {
            local_48[0] = (uint)*(ushort *)(pcVar7 + 0x14) * 0x10000 +
                          (uint)*(ushort *)(pcVar7 + 0x1a);
            if ((pcVar7[0xb] & 0x10U) == 0) {
              if ((pcVar7[0xb] & 8U) == 0) {
                local_34 = 0;
                local_38 = param_3 * *(int *)(param_1 + 0x111c) + iVar8;
                local_40 = param_2;
                iVar8 = FUN_40101fb0(param_1,local_48);
                iVar5 = local_48[0];
                if (iVar8 == 0) {
                  uVar10 = 2;
                  goto LAB_40102810;
                }
              }
            }
            else if (cVar1 != '.') {
              local_34 = 0;
              local_38 = param_3 * *(int *)(param_1 + 0x111c) + iVar8;
              local_40 = param_2;
              iVar8 = FUN_40102078(param_1,local_48);
              iVar5 = local_48[0];
              if (iVar8 == 0) break;
            }
          }
          local_48[0] = iVar5;
          uVar9 = uVar9 + 1;
        }
        cVar1 = lpMem[uVar9 * 0x20];
        iVar5 = local_48[0];
      } while( true );
    }
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,lpMem);
  }
  FUN_4010d048(local_30);
  return 2;
}



/* 40102868 FUN_40102868 */

/* Boundary evidence: original MIPS .pdata 40102868..40102937. Semantic name remains unreviewed. */

undefined4 FUN_40102868(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_28 [2];
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = 1;
  if (*(int *)(param_1 + 0x10f8) == 0x20) {
    local_28[0] = *(int *)(param_1 + 0x1130);
    local_20 = 0;
    local_18 = 0;
    local_14 = 0;
    iVar1 = FUN_40102078(param_1,local_28);
    if (iVar1 == 0) {
LAB_401028b8:
      FUN_40101208(param_1,0xc84,0xd4b);
      uVar2 = 0;
    }
  }
  else {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x1118) != 0) {
      do {
        iVar1 = FUN_401025bc(param_1,0,*(int *)(param_1 + 0x1114) + uVar3);
        if (iVar1 == 2) goto LAB_401028b8;
      } while ((iVar1 != 1) && (uVar3 = uVar3 + 1, uVar3 < *(uint *)(param_1 + 0x1118)));
    }
  }
  return uVar2;
}



/* 40102938 FUN_40102938 */

/* Boundary evidence: original MIPS .pdata 40102938..40102b97. Semantic name remains unreviewed. */

DWORD FUN_40102938(HANDLE param_1,undefined4 *param_2,undefined *param_3,undefined *param_4,
                  undefined4 param_5,int *param_6)

{
  int iVar1;
  BOOL BVar2;
  DWORD dwErrCode;
  DWORD DVar3;
  DWORD aDStack_12c0 [2];
  undefined1 auStack_12b8 [24];
  undefined4 auStack_12a0 [8];
  undefined4 local_1280 [4];
  undefined4 local_1270 [4];
  undefined4 local_1260 [38];
  undefined4 auStack_11c8 [1054];
  undefined4 local_150 [72];
  uint local_30;
  uint local_28;
  
  local_28 = DAT_4010e38c;
  local_1280[0] = 0;
  local_1270[0] = 0;
  local_1260[0] = 0;
  FUN_401073ac(auStack_11c8);
  local_150[0] = 0x128;
  if ((param_2 == (undefined4 *)0x0) || ((param_2[1] & 4) == 0)) {
    iVar1 = GetPartitionInfo(param_1,local_150);
    if (iVar1 == 0) {
      FUN_401031ac(0xce5,param_4);
      DVar3 = 0x1f;
      dwErrCode = 0x1f;
    }
    else {
      if ((local_30 & 0x10) == 0) goto LAB_40102a14;
      FUN_401031ac(0xceb,param_4);
      DVar3 = 0x20;
      dwErrCode = 0x20;
    }
    SetLastError(dwErrCode);
    goto LAB_40102b48;
  }
LAB_40102a14:
  BVar2 = DeviceIoControl(param_1,1,auStack_12b8,0x18,auStack_12b8,0x18,aDStack_12c0,
                          (LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
LAB_40102a54:
    DVar3 = 0x1f;
  }
  else {
    if (param_3 != (undefined *)0x0) {
      (*(code *)param_3)(10);
    }
    iVar1 = FUN_401012f8(auStack_12a0,param_1,(int)auStack_12b8,param_2,param_3,(int)param_4,param_6
                         ,param_5);
    if (iVar1 == 0) {
LAB_40102a98:
      DVar3 = GetLastError();
      if (DVar3 == 0) goto LAB_40102a54;
    }
    else {
      if (param_3 != (undefined *)0x0) {
        (*(code *)param_3)(0x14);
      }
      iVar1 = FUN_40102868((int)auStack_12a0);
      if (iVar1 == 0) goto LAB_40102a98;
      if (param_3 != (undefined *)0x0) {
        (*(code *)param_3)(0x28);
      }
      iVar1 = FUN_40102220((int)auStack_12a0);
      if (iVar1 != 0) {
        if (param_3 != (undefined *)0x0) {
          (*(code *)param_3)(0x46);
        }
        FUN_401023e0((int)auStack_12a0);
        DVar3 = GetLastError();
        if (param_3 != (undefined *)0x0) {
          (*(code *)param_3)(100);
        }
        goto LAB_40102b48;
      }
    }
    DVar3 = GetLastError();
  }
LAB_40102b48:
  FUN_4010742c(auStack_11c8);
  FUN_40108568(local_1260);
  FUN_401081f8(local_1270);
  FUN_401081f8(local_1280);
  FUN_4010d048(local_28);
  return DVar3;
}



/* 40102b98 DefragVolume */

/* Boundary evidence: original MIPS .pdata 40102b98..40102bdb. Semantic name remains unreviewed. */

bool DefragVolume(HANDLE param_1,undefined4 param_2,undefined4 *param_3,undefined *param_4,
                 undefined *param_5)

{
  DWORD DVar1;
  
                    /* 0x2b98  1  DefragVolume */
  DVar1 = FUN_40102938(param_1,param_3,param_4,param_5,0,(int *)0x0);
  return DVar1 == 0;
}



/* 40102bdc DefragVolumeEx */

/* Boundary evidence: original MIPS .pdata 40102bdc..40102c13. Semantic name remains unreviewed. */

void DefragVolumeEx(HANDLE param_1,int param_2)

{
                    /* 0x2bdc  2  DefragVolumeEx */
  FUN_40102938(param_1,(undefined4 *)(param_2 + 4),*(undefined **)(param_2 + 0x30),
               *(undefined **)(param_2 + 0x34),*(undefined4 *)(param_2 + 0x38),
               (int *)(param_2 + 0xc));
  return;
}



/* 40102c14 FUN_40102c14 */

/* Boundary evidence: original MIPS .pdata 40102c14..40102d9b. Semantic name remains unreviewed. */

undefined4 FUN_40102c14(HWND param_1)

{
  BOOL BVar1;
  int iVar2;
  code *pcVar3;
  UINT UVar4;
  DWORD aDStack_18 [2];
  
  DAT_4010ebc8 = param_1;
  FUN_40108cdc(param_1);
  DAT_4010e6e8 = 0;
  BVar1 = DeviceIoControl(DAT_4010e5bc,1,&DAT_4010e6ec,0x18,&DAT_4010e6ec,0x18,aDStack_18,
                          (LPOVERLAPPED)0x0);
  if (BVar1 != 0) {
    DAT_4010e5c0 = 0x128;
    iVar2 = GetPartitionInfo(DAT_4010e5bc,&DAT_4010e5c0);
    if (iVar2 != 0) {
      if ((DAT_4010e6e0 & 0x10) == 0) {
        SetDlgItemTextW(param_1,0x7d3,L"1");
        DAT_4010e704 = LoadLibraryW(L"commctrl.dll");
        if (DAT_4010e704 == (HMODULE)0x0) {
          return 0;
        }
        pcVar3 = (code *)GetProcAddressW(DAT_4010e704,L"InitCommonControls");
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)();
          DAT_4010ebcc = GetDlgItem(param_1,0x3eb);
          if (DAT_4010ebcc != (HWND)0x0) {
            SendMessageW(DAT_4010ebcc,0x401,0,0x640000);
            SendMessageW(DAT_4010ebcc,0x402,0,0);
            return 1;
          }
        }
        FreeLibrary(DAT_4010e704);
        return 0;
      }
      UVar4 = 0xceb;
      goto LAB_40102c90;
    }
  }
  UVar4 = 0xce5;
LAB_40102c90:
  FUN_40108e90(UVar4,0xd4c,0);
  return 0;
}



/* 40102d9c FUN_40102d9c */

/* Boundary evidence: original MIPS .pdata 40102d9c..40102e23. Semantic name remains unreviewed. */

void FUN_40102d9c(HWND param_1)

{
  if (DAT_4010e6e8 == 0) {
    FreeLibrary(DAT_4010e704);
    EndDialog(param_1,1);
  }
  if (DAT_4010e5b8 != 0) {
    CloseHandle((HANDLE)DAT_4010e5b8);
    DAT_4010e5b8 = 0;
  }
  DAT_4010e6e8 = 1;
  return;
}



/* 40102e24 FUN_40102e24 */

/* Boundary evidence: original MIPS .pdata 40102e24..40102e7b. Semantic name remains unreviewed. */

ulong FUN_40102e24(HWND param_1)

{
  ulong uVar1;
  WCHAR aWStack_18 [4];
  uint local_10;
  
  local_10 = DAT_4010e38c;
  GetDlgItemTextW(param_1,0x7d3,aWStack_18,3);
  uVar1 = wcstoul(aWStack_18,(wchar_t **)0x0,10);
  FUN_4010d048(local_10);
  return uVar1;
}



/* 40102e7c FUN_40102e7c */

/* Boundary evidence: original MIPS .pdata 40102e7c..40102f7f. Semantic name remains unreviewed. */

undefined4 FUN_40102e7c(HWND param_1)

{
  LRESULT LVar1;
  HWND hWnd;
  int iVar2;
  UINT UVar3;
  undefined4 local_50;
  ulong local_4c;
  uint local_48;
  code *local_20;
  code *local_1c;
  HANDLE local_18;
  
  local_50 = 0x3c;
  local_4c = FUN_40102e24(param_1);
  LVar1 = SendDlgItemMessageW(param_1,0x7d2,0xf0,0,0);
  local_48 = (uint)(LVar1 != 0);
  local_20 = FUN_40108dd0;
  local_1c = FUN_40108dfc;
  DAT_4010e5b8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  local_18 = DAT_4010e5b8;
  hWnd = GetDlgItem(param_1,0x3e9);
  EnableWindow(hWnd,0);
  iVar2 = DefragVolumeEx(DAT_4010e5bc,(int)&local_50);
  if (iVar2 == 0x4c7) {
    UVar3 = 0xcec;
  }
  else {
    UVar3 = 0xce9;
  }
  FUN_40108e90(UVar3,0xd4b,0);
  FUN_40102d9c(param_1);
  return 0;
}



/* 40102f80 FUN_40102f80 */

/* Boundary evidence: original MIPS .pdata 40102f80..401030b7. Semantic name remains unreviewed. */

undefined4 FUN_40102f80(HWND param_1,int param_2,short param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0x10) {
    FUN_40102d9c(param_1);
LAB_4010309c:
    uVar2 = 1;
  }
  else {
    if (param_2 == 0x110) {
      iVar1 = param_4;
      if (param_4 == 0) {
        EndDialog(param_1,0);
        iVar1 = DAT_4010e5bc;
      }
      DAT_4010e5bc = iVar1;
      iVar1 = FUN_40102c14(param_1);
      if (iVar1 != 0) goto LAB_4010309c;
      EndDialog(param_1,0);
    }
    else if (param_2 == 0x111) {
      if (param_3 == 0x3e9) {
        CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40102e7c,param_1,0,(LPDWORD)0x0);
        goto LAB_4010309c;
      }
      if (param_3 == 0x3ea) {
        iVar1 = FUN_40108e90(0xcea,0xd4d,1);
        if (iVar1 == 0) {
          return 1;
        }
        if (DAT_4010e5b8 != 0) {
          EventModify(DAT_4010e5b8,3);
          return 1;
        }
        FUN_40102d9c(param_1);
        return 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 401030b8 DefragVolumeUI */

/* Boundary evidence: original MIPS .pdata 401030b8..40103137. Semantic name remains unreviewed. */

void DefragVolumeUI(LPARAM param_1,HWND param_2)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
                    /* 0x30b8  3  DefragVolumeUI */
  hResInfo = FindResourceW(DAT_4010e398,(LPCWSTR)0x67,(LPCWSTR)0x5);
  hDialogTemplate = LoadResource(DAT_4010e398,hResInfo);
  DialogBoxIndirectParamW(DAT_4010e398,hDialogTemplate,param_2,FUN_40102f80,param_1);
  return;
}



/* 40103138 FUN_40103138 */

/* Boundary evidence: original MIPS .pdata 40103138..401031ab. Semantic name remains unreviewed. */

void FUN_40103138(uint param_1,undefined *param_2)

{
  uint uVar1;
  
  uVar1 = __ull_div((int)((ulonglong)param_1 * 100),(int)((ulonglong)param_1 * 100 >> 0x20),
                    DAT_4010e708,0);
  if (((param_2 != (undefined *)0x0) && (uVar1 != DAT_4010e70c)) && (uVar1 < 0x65)) {
    DAT_4010e70c = uVar1;
    (*(code *)param_2)(uVar1);
  }
  return;
}



/* 401031ac FUN_401031ac */

/* Boundary evidence: original MIPS .pdata 401031ac..4010322b. Semantic name remains unreviewed. */

void FUN_401031ac(UINT param_1,undefined *param_2)

{
  WCHAR aWStack_238 [12];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_4010e38c;
  if (param_2 != (undefined *)0x0) {
    LoadStringW(DAT_4010e398,param_1,aWStack_220,0x104);
    LoadStringW(DAT_4010e398,0xd4c,aWStack_238,10);
    (*(code *)param_2)(aWStack_220,aWStack_238,0);
  }
  FUN_4010d048(local_18);
  return;
}



/* 4010322c FUN_4010322c */

undefined1 FUN_4010322c(int param_1,uint param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (param_1 == 0xc) {
    puVar3 = &DAT_4010e11c;
    iVar5 = 0;
    uVar2 = DAT_4010e11c;
    while (uVar2 < param_2) {
      puVar3 = puVar3 + 2;
      iVar5 = iVar5 + 1;
      uVar2 = *puVar3;
    }
    uVar1 = (&DAT_4010e120)[iVar5 * 8];
  }
  else {
    if (param_1 == 0x10) {
      iVar5 = 0;
      if (DAT_4010e144 < param_2) {
        puVar3 = &DAT_4010e144;
        do {
          puVar3 = puVar3 + 2;
          iVar5 = iVar5 + 1;
        } while (*puVar3 < param_2);
      }
      puVar4 = &DAT_4010e144;
    }
    else {
      iVar5 = 0;
      if (DAT_4010e184 < param_2) {
        puVar3 = &DAT_4010e184;
        do {
          puVar3 = puVar3 + 2;
          iVar5 = iVar5 + 1;
        } while (*puVar3 < param_2);
      }
      puVar4 = &DAT_4010e184;
    }
    uVar1 = *(undefined1 *)(puVar4 + iVar5 * 2 + 1);
  }
  return uVar1;
}



/* 40103318 FUN_40103318 */

/* Boundary evidence: original MIPS .pdata 40103318..401033ab. Semantic name remains unreviewed. */

undefined4 FUN_40103318(undefined4 *param_1)

{
  int *hMem;
  BOOL BVar1;
  undefined4 uVar2;
  
  hMem = LocalAlloc(0x40,param_1[1]);
  if (hMem == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    BVar1 = FUN_40107c94(param_1,0,hMem,1);
    if ((BVar1 == 0) || (*hMem != -0x5e4d3c2c)) {
      uVar2 = 0;
    }
    LocalFree(hMem);
  }
  return uVar2;
}



/* 401033ac FUN_401033ac */

/* Boundary evidence: original MIPS .pdata 401033ac..40104247. Semantic name remains unreviewed. */

undefined4
FUN_401033ac(HANDLE param_1,uint *param_2,undefined *param_3,undefined *param_4,uint *param_5)

{
  undefined1 *puVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 *_Dst;
  undefined1 *hMem;
  undefined3 extraout_var;
  BOOL BVar7;
  UINT UVar8;
  undefined2 uVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint local_200;
  uint local_1f4;
  HANDLE local_1e8;
  SIZE_T local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  uint local_1d8;
  uint *local_1d4;
  uint local_1d0;
  uint local_1cc;
  SIZE_T local_1c8;
  uint local_1c4;
  uint local_1c0;
  uint local_1b8;
  uint local_1b4;
  undefined2 local_1ac;
  undefined2 local_1a8;
  uint local_1a0;
  _SYSTEMTIME local_198;
  int local_188;
  uint *local_184;
  DWORD aDStack_180 [2];
  char local_178 [32];
  undefined4 local_158 [72];
  uint local_38;
  uint local_30;
  
  local_30 = DAT_4010e38c;
  uVar14 = 0x1f;
  local_184 = param_5;
  bVar4 = false;
  local_158[0] = 0x128;
  if ((param_2 == (uint *)0x0) || ((param_2[4] & 4) == 0)) {
    iVar6 = GetPartitionInfo(param_1,local_158);
    if (iVar6 == 0) {
      FUN_401031ac(0xce5,param_4);
      goto LAB_4010420c;
    }
    if ((local_38 & 0x10) != 0) {
      FUN_401031ac(0xceb,param_4);
      FUN_4010d048(local_30);
      return 0x20;
    }
  }
  iVar6 = FUN_40107ba4(&local_1e8,param_1,1,&local_1b8,0x18,&local_1b8,0x18,aDStack_180,
                       (LPOVERLAPPED)0x0);
  if (iVar6 == 0) goto LAB_4010420c;
  if (param_2 == (uint *)0x0) {
    uVar16 = 0;
    local_200 = 1;
    uVar15 = 0x20;
    uVar17 = 0x200;
    uVar13 = 0;
  }
  else {
    local_200 = param_2[3];
    uVar16 = *param_2;
    uVar17 = param_2[1];
    uVar15 = param_2[2];
    uVar13 = param_2[4];
  }
  local_1c8 = local_1b4 << 6;
  if ((local_1b4 & 0x3ffffff) != local_1b4) goto LAB_4010420c;
  _Dst = VirtualAlloc((LPVOID)0x0,local_1c8,0x1000,4);
  if (_Dst == (undefined4 *)0x0) {
    FUN_4010d048(local_30);
    return 0xe;
  }
  hMem = LocalAlloc(0x40,local_1b4);
  if (hMem == (undefined1 *)0x0) {
    uVar14 = 0xe;
  }
  else {
    local_1dc = 1;
    bVar3 = false;
    local_1e4 = local_1b4;
    local_1e0 = 0;
    local_1e8 = param_1;
    if (((uVar13 & 8) != 0) || (iVar6 = FUN_40103318(&local_1e8), iVar6 != 0)) {
      iVar6 = FUN_40107f04(&local_1e8,0,local_1b8);
      if (iVar6 == 0) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
    }
    if ((local_200 == 0) || (2 < local_200)) {
      local_200 = 1;
    }
    if ((uVar13 & 2) != 0) {
      local_200 = 2;
    }
    if (((uVar15 != 0xc) && (uVar15 != 0x10)) && (uVar15 != 0x20)) {
      uVar15 = 0x20;
    }
    if (DAT_4010e144 < local_1b8) {
      if ((uVar15 == 0x20) && (local_1b8 <= DAT_4010e184)) {
        uVar15 = 0x10;
        goto LAB_40103630;
      }
      if (DAT_4010e174 < local_1b8) {
        uVar15 = 0x20;
      }
      else {
        if (uVar15 == 0xc) {
          if (local_1b8 <= DAT_4010e134) goto LAB_40103630;
          uVar15 = 0x10;
        }
        if (uVar15 != 0x20) goto LAB_40103630;
      }
      uVar12 = 0x20;
      uVar17 = 0;
    }
    else {
      uVar15 = 0xc;
LAB_40103630:
      uVar12 = 1;
    }
    local_1f4 = ((uVar17 * 0x20 + local_1b4) - 1) / local_1b4;
    if (local_1b4 == 0) {
      trap(0x1c00);
    }
    hMem[0xc] = (char)((local_1b4 & 0xffff) >> 8);
    hMem[0x11] = (char)(uVar17 & 0xffff);
    hMem[0xb] = (char)(local_1b4 & 0xffff);
    hMem[0xe] = (char)uVar12;
    hMem[0xf] = 0;
    hMem[0x10] = (char)local_200;
    hMem[0x12] = (char)((uVar17 & 0xffff) >> 8);
    if ((uVar15 == 0x20) || ((local_1b8 & 0xffff0000) != 0)) {
      hMem[0x13] = 0;
      hMem[0x14] = 0;
      *(uint *)(hMem + 0x20) = local_1b8;
    }
    else {
      hMem[0x13] = (char)(local_1b8 & 0xffff);
      hMem[0x14] = (char)((local_1b8 & 0xffff) >> 8);
      *(undefined4 *)(hMem + 0x20) = 0;
    }
    hMem[0x15] = 0xf8;
    hMem[0x18] = (char)local_1a8;
    hMem[0x19] = (char)((ushort)local_1a8 >> 8);
    hMem[0x1a] = (char)local_1ac;
    hMem[0x1b] = (char)((ushort)local_1ac >> 8);
    *(undefined4 *)(hMem + 0x1c) = 0;
    if (((uVar16 == 0) || (0x8000 < uVar16)) || ((uVar16 - 1 & uVar16) != 0)) {
      uVar5 = FUN_4010322c(uVar15,local_1b8);
      uVar16 = CONCAT31(extraout_var,uVar5);
    }
    else {
      uVar16 = uVar16 / local_1b4;
      if (local_1b4 == 0) {
        trap(0x1c00);
      }
    }
    local_1c0 = uVar16;
    if (uVar16 == 0) {
      UVar8 = 0xbba;
    }
    else {
      hMem[0xd] = (char)uVar16;
      if ((uVar16 & 0xff) == 0) {
        trap(0x1c00);
      }
      uVar17 = ((((local_1b8 / (uVar16 & 0xff)) * uVar15 >> 3) + local_1b4) - 1) / local_1b4;
      if (local_1b4 == 0) {
        trap(0x1c00);
      }
      if (uVar15 == 0x20) {
        uVar9 = 0;
      }
      else {
        uVar9 = (undefined2)uVar17;
      }
      iVar6 = uVar17 * local_200;
      hMem[0x16] = (char)uVar9;
      hMem[0x17] = (char)((ushort)uVar9 >> 8);
      local_1d0 = iVar6 + local_1f4 + uVar12;
      local_1a0 = local_1b8 - local_1d0;
      uVar18 = local_1a0 / uVar16;
      if (uVar16 == 0) {
        trap(0x1c00);
      }
      local_1d8 = uVar17;
      local_188 = iVar6;
      if ((((uVar15 != 0xc) || (uVar18 < 0xff5)) &&
          ((uVar15 != 0x10 || ((0xff4 < uVar18 && (uVar18 < 0xfff5)))))) &&
         ((uVar15 != 0x20 || (0xfff4 < uVar18)))) {
        GetSystemTime(&local_198);
        iVar11 = ((uint)local_198.wSecond + (uint)local_198.wHour + (uint)local_198.wDayOfWeek +
                 (uint)local_198.wYear) * 0x10000 + (uint)local_198.wMilliseconds +
                 (uint)local_198.wMinute + (uint)local_198.wDay + (uint)local_198.wMonth;
        if (uVar15 == 0x20) {
          hMem[2] = 0x90;
          *hMem = 0xeb;
          hMem[1] = 0xfe;
          *(undefined4 *)(hMem + 3) = 0x4957534d;
          *(undefined4 *)(hMem + 7) = 0x312e344e;
          hMem[0x40] = 0x80;
          hMem[0x42] = 0x29;
          *(int *)(hMem + 0x43) = iVar11;
          memset(hMem + 0x47,0x20,0xb);
          if ((uVar13 & 2) == 0) {
            *(undefined4 *)(hMem + 0x52) = 0x33544146;
            uVar14 = 0x20202032;
          }
          else {
            *(undefined4 *)(hMem + 0x52) = 0x54414654;
            uVar14 = 0x20203233;
          }
          *(undefined4 *)(hMem + 0x56) = uVar14;
          hMem[0x29] = 0;
          hMem[0x2b] = 0;
          hMem[0x30] = 1;
          puVar1 = hMem + 0x2f;
          uVar18 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar18) =
               *(uint *)(puVar1 + -uVar18) & -1 << (uVar18 + 1) * 8 | 2U >> (3 - uVar18) * 8;
          *(uint *)(hMem + 0x24) = uVar17;
          hMem[0x28] = 0;
          hMem[0x2a] = 0;
          puVar1 = hMem + 0x2c;
          uVar17 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar17) =
               *(uint *)(puVar1 + -uVar17) & 0xffffffffU >> (4 - uVar17) * 8 | 2 << uVar17 * 8;
          hMem[0x31] = 0;
          hMem[0x32] = 0;
          hMem[0x33] = 0;
          memset(hMem + 0x34,0,0xc);
        }
        else {
          hMem[1] = 0xfe;
          hMem[2] = 0x90;
          *hMem = 0xeb;
          *(undefined4 *)(hMem + 3) = 0x4957534d;
          *(undefined4 *)(hMem + 7) = 0x312e344e;
          hMem[0x24] = 0x80;
          hMem[0x26] = 0x29;
          *(int *)(hMem + 0x27) = iVar11;
          memset(hMem + 0x2b,0x20,0xb);
          if (uVar15 == 0x10) {
            if ((uVar13 & 2) == 0) {
              puVar10 = &DAT_401010cc;
LAB_401039b4:
              *(undefined4 *)(hMem + 0x36) = *puVar10;
              *(undefined4 *)(hMem + 0x3a) = puVar10[1];
              goto LAB_40103b08;
            }
            puVar10 = &DAT_401010d8;
          }
          else {
            if ((uVar13 & 2) == 0) {
              puVar10 = &DAT_401010b4;
              goto LAB_401039b4;
            }
            puVar10 = &DAT_401010c0;
          }
          *(undefined4 *)(hMem + 0x36) = *puVar10;
          *(undefined4 *)(hMem + 0x3a) = puVar10[1];
        }
LAB_40103b08:
        uVar17 = 2;
        *(undefined2 *)(hMem + 0x1fe) = 0xaa55;
        if ((bVar3) || ((uVar13 & 1) != 0)) {
          DAT_4010e708 = local_1b8;
        }
        else if (uVar15 == 0x20) {
          DAT_4010e708 = iVar6 + uVar16 + uVar12;
        }
        else {
          DAT_4010e708 = local_1d0;
        }
        local_1d4 = &DAT_4010e708;
        memset(_Dst,0,local_1b4);
        if (bVar3) {
          *_Dst = 0xa1b2c3d4;
        }
        BVar7 = FUN_40107bfc(&local_1e8,0,_Dst,1);
        if (BVar7 == 0) {
          FUN_401031ac(0xbbc,param_4);
          bVar4 = true;
          if (bVar3) goto LAB_40103bcc;
        }
        else {
LAB_40103bcc:
          if (bVar3) {
            FUN_40107f5c(&local_1e8);
          }
          if (uVar15 == 0x20) {
            *_Dst = 0x41615252;
            _Dst[0x7f] = 0xaa550000;
            uVar18 = (uint)((int)_Dst + 0x1e7) & 3;
            puVar2 = (uint *)((undefined1 *)((int)_Dst + 0x1e7) + -uVar18);
            *puVar2 = *puVar2 & -1 << (uVar18 + 1) * 8 | 0x61417272U >> (3 - uVar18) * 8;
            uVar18 = (uint)((int)_Dst + 0x1eb) & 3;
            puVar2 = (uint *)((undefined1 *)((int)_Dst + 0x1eb) + -uVar18);
            *puVar2 = *puVar2 & -1 << (uVar18 + 1) * 8 | 0xffffffffU >> (3 - uVar18) * 8;
            uVar18 = (uint)((int)_Dst + 0x1ef) & 3;
            puVar2 = (uint *)((undefined1 *)((int)_Dst + 0x1ef) + -uVar18);
            *puVar2 = *puVar2 & -1 << (uVar18 + 1) * 8 | 0xffffffffU >> (3 - uVar18) * 8;
            uVar18 = (uint)(_Dst + 0x79) & 3;
            puVar2 = (uint *)((int)(_Dst + 0x79) - uVar18);
            *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar18) * 8 | 0x61417272 << uVar18 * 8;
            uVar18 = (uint)(_Dst + 0x7a) & 3;
            puVar2 = (uint *)((int)(_Dst + 0x7a) - uVar18);
            *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar18) * 8 | -1 << uVar18 * 8;
            uVar18 = (uint)(_Dst + 0x7b) & 3;
            puVar2 = (uint *)((int)(_Dst + 0x7b) - uVar18);
            *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar18) * 8 | -1 << uVar18 * 8;
            BVar7 = FUN_40107bfc(&local_1e8,1,_Dst,1);
            if (BVar7 == 0) {
              FUN_401031ac(0xbbc,param_4);
              bVar4 = true;
              if (!bVar3) goto LAB_401041e8;
            }
            FUN_40103138(1,param_3);
            memset(_Dst,0,local_1b4);
            if (2 < uVar12) {
              do {
                BVar7 = FUN_40107bfc(&local_1e8,uVar17,_Dst,1);
                if (BVar7 == 0) {
                  FUN_401031ac(0xbbc,param_4);
                  bVar4 = true;
                  if (!bVar3) goto LAB_401041e8;
                }
                FUN_40103138(uVar17,param_3);
                uVar17 = uVar17 + 1;
              } while (uVar17 < uVar12);
            }
          }
          local_1cc = 0;
          local_1c4 = uVar12;
          if (local_200 != 0) {
            do {
              if (local_1cc == 0) {
                memset(_Dst,0,local_1c8);
              }
              *(undefined1 *)_Dst = 0xf8;
              *(undefined1 *)((int)_Dst + 1) = 0xff;
              *(undefined1 *)((int)_Dst + 2) = 0xff;
              if (0xf < uVar15) {
                *(undefined1 *)((int)_Dst + 3) = 0xff;
              }
              if (uVar15 == 0x20) {
                _Dst[1] = 0xfffffff;
                _Dst[2] = 0xfffffff;
              }
              uVar17 = 0;
              if (local_1d8 != 0) {
                do {
                  iVar6 = 0x40;
                  if (local_1d8 < uVar17 + 0x40) {
                    iVar6 = local_1d8 - uVar17;
                  }
                  uVar18 = uVar17 + local_1c4;
                  BVar7 = FUN_40107bfc(&local_1e8,uVar18,_Dst,iVar6);
                  if (BVar7 == 0) {
                    FUN_401031ac(0xbbc,param_4);
                    bVar4 = true;
                    if (!bVar3) goto LAB_401041e8;
                  }
                  FUN_40103138(uVar18,param_3);
                  if (uVar17 == 0) {
                    memset(_Dst,0,local_1b4);
                  }
                  uVar17 = iVar6 + uVar17;
                } while (uVar17 < local_1d8);
              }
              local_1c4 = local_1c4 + local_1d8;
              local_1cc = local_1cc + 1;
            } while (local_1cc < local_200);
          }
          iVar6 = local_188 + uVar12;
          if ((uVar15 == 0x20) && (local_1f4 = uVar16, (uVar13 & 2) != 0)) {
            memset(_Dst,0,local_1b4);
            memset(local_178,0,0x20);
            builtin_strncpy(local_178,"TFAT       \b",0xc);
            memcpy(_Dst,local_178,0x20);
            iVar11 = 1;
            builtin_strncpy(local_178,"DONT_DEL000",0xb);
            uVar17 = 0x20;
            if (0x20 < local_1b4) {
              do {
                local_178[9] = (char)((iVar11 / 10) % 10) + '0';
                local_178[8] = (char)(iVar11 / 100) + '0';
                local_178[10] = (char)(iVar11 % 10) + '0';
                memcpy((undefined1 *)(uVar17 + (int)_Dst),local_178,0x20);
                uVar17 = uVar17 + 0x20;
                iVar11 = iVar11 + 1;
                uVar16 = local_1c0;
              } while (uVar17 < local_1b4);
            }
            uVar17 = 0;
            if (uVar16 != 0) {
              do {
                BVar7 = FUN_40107bfc(&local_1e8,uVar17 + iVar6,_Dst,1);
                if (BVar7 == 0) {
                  FUN_401031ac(0xbbc,param_4);
                  bVar4 = true;
                  if (!bVar3) goto LAB_401041e8;
                }
                uVar17 = uVar17 + 1;
              } while (uVar17 < uVar16);
            }
            iVar6 = iVar6 + uVar16;
            local_1f4 = 0;
          }
          memset(_Dst,0,local_1c8);
          uVar17 = 0;
          if (local_1f4 != 0) {
            do {
              if (local_1f4 < uVar17 + 0x40) {
                iVar11 = local_1f4 - uVar17;
              }
              else {
                iVar11 = 0x40;
              }
              BVar7 = FUN_40107bfc(&local_1e8,uVar17 + iVar6,_Dst,iVar11);
              if (BVar7 == 0) {
                FUN_401031ac(0xbbc,param_4);
                bVar4 = true;
                if (!bVar3) goto LAB_401041e8;
              }
              FUN_40103138(uVar17 + iVar6,param_3);
              uVar17 = iVar11 + uVar17;
              uVar16 = local_1c0;
            } while (uVar17 < local_1f4);
          }
          if ((bVar3) || ((uVar13 & 1) != 0)) {
            memset(_Dst,0xff,local_1c8);
            for (uVar13 = iVar6 + local_1f4; uVar13 < local_1b8; uVar13 = iVar6 + uVar13) {
              iVar6 = 0x40;
              if (local_1b8 < uVar13 + 0x40) {
                iVar6 = local_1b8 - uVar13;
              }
              BVar7 = FUN_40107bfc(&local_1e8,uVar13,_Dst,iVar6);
              if (BVar7 == 0) {
                FUN_401031ac(0xbbc,param_4);
                bVar4 = true;
                if (!bVar3) goto LAB_401041e8;
              }
              FUN_40103138(uVar13,param_3);
            }
            if (bVar3) {
              FUN_40107f5c(&local_1e8);
            }
          }
          BVar7 = FUN_40107bfc(&local_1e8,0,hMem,1);
          if (BVar7 == 0) {
            FUN_401031ac(0xbbc,param_4);
            bVar4 = true;
            if (!bVar3) goto LAB_401041e8;
          }
          if (local_184 != (uint *)0x0) {
            *local_184 = local_1d8;
            local_184[1] = uVar12;
            local_184[2] = uVar16;
            local_184[3] = local_1f4;
            local_184[4] = local_1b8;
            local_184[5] = local_200;
            local_184[6] = uVar15;
          }
          uVar13 = local_1d0;
          uVar17 = local_1a0;
          if (uVar15 == 0x20) {
            uVar13 = local_1d0 + uVar16;
            uVar17 = local_1a0 - uVar16;
          }
          FUN_40107e78(&local_1e8,uVar13,uVar17);
          FUN_40103138(*local_1d4,param_3);
          uVar14 = 0;
          if (!bVar4) goto LAB_401041ec;
        }
LAB_401041e8:
        uVar14 = 0x1d;
        goto LAB_401041ec;
      }
      UVar8 = 0xbbb;
    }
    FUN_401031ac(UVar8,param_4);
  }
LAB_401041ec:
  VirtualFree(_Dst,0,0x8000);
  if (hMem != (undefined1 *)0x0) {
    LocalFree(hMem);
  }
LAB_4010420c:
  FUN_4010d048(local_30);
  return uVar14;
}



/* 40104248 FormatVolume */

/* Boundary evidence: original MIPS .pdata 40104248..4010429f. Semantic name remains unreviewed. */

void FormatVolume(HANDLE param_1,undefined4 param_2,uint *param_3,undefined *param_4,
                 undefined *param_5)

{
                    /* 0x4248  4  FormatVolume */
  if ((param_3 == (uint *)0x0) || ((param_3[4] & 0x10) == 0)) {
    FUN_401033ac(param_1,param_3,param_4,param_5,(uint *)0x0);
  }
  else {
    FUN_401097e8(param_1,param_3,param_4,param_5,(uint *)0x0);
  }
  return;
}



/* 401042a0 FormatVolumeEx */

/* Boundary evidence: original MIPS .pdata 401042a0..40104313. Semantic name remains unreviewed. */

void FormatVolumeEx(HANDLE param_1,int param_2)

{
                    /* 0x42a0  5  FormatVolumeEx */
  if (param_2 == 0) {
    FUN_401033ac(param_1,(uint *)0x0,(undefined *)0x0,(undefined *)0x0,(uint *)0x0);
  }
  else if ((*(uint *)(param_2 + 0x14) & 0x10) == 0) {
    FUN_401033ac(param_1,(uint *)(param_2 + 4),*(undefined **)(param_2 + 0x34),
                 *(undefined **)(param_2 + 0x38),(uint *)(param_2 + 0x18));
  }
  else {
    FUN_401097e8(param_1,(uint *)(param_2 + 4),*(undefined **)(param_2 + 0x34),
                 *(undefined **)(param_2 + 0x38),(uint *)(param_2 + 0x18));
  }
  return;
}



/* 40104314 FUN_40104314 */

/* Boundary evidence: original MIPS .pdata 40104314..40104357. Semantic name remains unreviewed. */

void FUN_40104314(HWND param_1)

{
  FreeLibrary(DAT_4010e714);
  EndDialog(param_1,1);
  return;
}



/* 40104358 FUN_40104358 */

/* Boundary evidence: original MIPS .pdata 40104358..40104443. Semantic name remains unreviewed. */

undefined4 FUN_40104358(HWND param_1)

{
  int iVar1;
  undefined4 uVar2;
  WCHAR aWStack_20 [10];
  uint local_c;
  
  local_c = DAT_4010e38c;
  GetDlgItemTextW(param_1,0x3f1,aWStack_20,10);
  iVar1 = wcsncmp(aWStack_20,u_eXFAT_4010e29c,10);
  if (iVar1 == 0) {
    FUN_4010d048(local_c);
    uVar2 = 0x40;
  }
  else {
    iVar1 = wcsncmp(aWStack_20,u_FAT32_4010e2a8,10);
    if (iVar1 == 0) {
      FUN_4010d048(local_c);
      uVar2 = 0x20;
    }
    else {
      iVar1 = wcsncmp(aWStack_20,u_FAT16_4010e2b4,10);
      if (iVar1 == 0) {
        FUN_4010d048(local_c);
        uVar2 = 0x10;
      }
      else {
        iVar1 = wcsncmp(aWStack_20,u_FAT12_4010e2c0,10);
        if (iVar1 == 0) {
          FUN_4010d048(local_c);
          uVar2 = 0xc;
        }
        else {
          FUN_4010d048(local_c);
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}



/* 40104444 FUN_40104444 */

/* Boundary evidence: original MIPS .pdata 40104444..4010449b. Semantic name remains unreviewed. */

ulong FUN_40104444(HWND param_1)

{
  ulong uVar1;
  WCHAR aWStack_20 [10];
  uint local_c;
  
  local_c = DAT_4010e38c;
  GetDlgItemTextW(param_1,0x3ee,aWStack_20,10);
  uVar1 = wcstoul(aWStack_20,(wchar_t **)0x0,10);
  FUN_4010d048(local_c);
  return uVar1;
}



/* 4010449c FUN_4010449c */

/* Boundary evidence: original MIPS .pdata 4010449c..40104543. Semantic name remains unreviewed. */

uint FUN_4010449c(HWND param_1)

{
  undefined4 extraout_v0;
  uint uVar1;
  undefined4 extraout_v1;
  undefined8 uVar2;
  WCHAR aWStack_20 [10];
  uint local_c;
  
  local_c = DAT_4010e38c;
  GetDlgItemTextW(param_1,0x3f4,aWStack_20,10);
  wcstod(aWStack_20,(wchar_t **)0x0);
  uVar2 = __dpmul(extraout_v0,extraout_v1,0,0x40900000);
  uVar1 = __dptoul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  if ((0x8000 < uVar1) || ((uVar1 - 1 & uVar1) != 0)) {
    FUN_40108e90(0xce6,0xd4c,0);
    uVar1 = 0;
  }
  FUN_4010d048(local_c);
  return uVar1;
}



/* 40104544 FUN_40104544 */

/* Boundary evidence: original MIPS .pdata 40104544..40104677. Semantic name remains unreviewed. */

void FUN_40104544(HWND param_1)

{
  LRESULT LVar1;
  HWND pHVar2;
  WCHAR aWStack_28 [4];
  uint local_20;
  ulong local_1c;
  int local_18;
  ulong local_14;
  uint local_10;
  
  local_20 = FUN_4010449c(param_1);
  GetDlgItemTextW(param_1,0x3f3,aWStack_28,2);
  local_14 = wcstoul(aWStack_28,(wchar_t **)0x0,10);
  local_1c = FUN_40104444(param_1);
  local_18 = FUN_40104358(param_1);
  local_10 = 0;
  if (local_18 == 0x40) {
    local_10 = 0x10;
  }
  LVar1 = SendDlgItemMessageW(param_1,0x3f2,0xf0,0,0);
  if (LVar1 == 0) {
    local_10 = local_10 | 1;
  }
  LVar1 = SendDlgItemMessageW(param_1,0x3f7,0xf0,0,0);
  if (LVar1 != 0) {
    local_10 = local_10 | 2;
  }
  pHVar2 = GetDlgItem(param_1,0x3e9);
  EnableWindow(pHVar2,0);
  pHVar2 = GetDlgItem(param_1,0x3ea);
  EnableWindow(pHVar2,0);
  FormatVolume(DAT_4010e710,&DAT_4010e840,&local_20,FUN_40108dd0,FUN_40108dfc);
  return;
}



/* 40104678 FUN_40104678 */

/* Boundary evidence: original MIPS .pdata 40104678..401047e7. Semantic name remains unreviewed. */

void FUN_40104678(HWND param_1)

{
  undefined1 uVar1;
  uint uVar2;
  HWND pHVar3;
  LRESULT LVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  wchar_t local_28;
  undefined1 auStack_26 [10];
  uint local_1c;
  
  local_1c = DAT_4010e38c;
  local_28 = L'\0';
  memset(auStack_26,0,8);
  uVar2 = FUN_40104358(param_1);
  pHVar3 = GetDlgItem(param_1,0x3ee);
  EnableWindow(pHVar3,(uint)(uVar2 < 0x20));
  uVar1 = FUN_4010322c(uVar2,DAT_4010e840);
  uVar5 = __ultodp(DAT_4010e844);
  uVar6 = __ultodp(uVar1);
  uVar5 = __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar6,
                  (int)((ulonglong)uVar6 >> 0x20));
  uVar5 = __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x3f500000);
  swprintf(&local_28,0x401010f0,(wchar_t *)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  SetDlgItemTextW(param_1,0x3f4,&local_28);
  LVar4 = SendDlgItemMessageW(param_1,0x3f7,0xf0,0,0);
  if (LVar4 == 0) {
    pHVar3 = GetDlgItem(param_1,0x3f3);
  }
  else {
    SendDlgItemMessageW(param_1,0x3f3,0x14e,1,0);
    pHVar3 = GetDlgItem(param_1,0x3f3);
  }
  EnableWindow(pHVar3,(uint)(LVar4 == 0));
  FUN_4010d048(local_1c);
  return;
}



/* 401047e8 FUN_401047e8 */

/* Boundary evidence: original MIPS .pdata 401047e8..40104bb7. Semantic name remains unreviewed. */

undefined4 FUN_401047e8(HWND param_1)

{
  undefined1 uVar1;
  BOOL BVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  code *pcVar4;
  UINT UVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  DWORD aDStack_230 [2];
  wchar_t local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_4010e38c;
  local_228 = L'\0';
  memset(auStack_226,0,0x206);
  DAT_4010ebc8 = param_1;
  FUN_40108cdc(param_1);
  BVar2 = DeviceIoControl(DAT_4010e710,1,&DAT_4010e840,0x18,&DAT_4010e840,0x18,aDStack_230,
                          (LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
LAB_40104884:
    UVar5 = 0xce5;
  }
  else {
    DAT_4010e718 = 0x128;
    iVar3 = GetPartitionInfo(DAT_4010e710,&DAT_4010e718);
    if (iVar3 == 0) goto LAB_40104884;
    if ((DAT_4010e838 & 0x10) == 0) {
      SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x4010e29c);
      uVar1 = FUN_4010322c(0x20,DAT_4010e840);
      if (CONCAT31(extraout_var,uVar1) != 0) {
        SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x4010e2a8);
      }
      uVar1 = FUN_4010322c(0x10,DAT_4010e840);
      if (CONCAT31(extraout_var_00,uVar1) != 0) {
        SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x4010e2b4);
      }
      uVar1 = FUN_4010322c(0xc,DAT_4010e840);
      if (CONCAT31(extraout_var_01,uVar1) != 0) {
        SendDlgItemMessageW(param_1,0x3f1,0x143,0,0x4010e2c0);
      }
      SendDlgItemMessageW(param_1,0x3f1,0x14e,0,0);
      SendDlgItemMessageW(param_1,0x3f2,0xf1,1,0);
      uVar7 = __ultodp(DAT_4010e844);
      uVar8 = __ultodp(DAT_4010e840);
      uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                      (int)((ulonglong)uVar8 >> 0x20));
      uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3f500000);
      uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3f500000);
      swprintf(&local_228,0x40101108,(wchar_t *)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      SetDlgItemTextW(param_1,0x3f6,&local_228);
      SendDlgItemMessageW(param_1,0x3f3,0x143,0,0x40101080);
      SendDlgItemMessageW(param_1,0x3f3,0x143,0,0x40101104);
      SendDlgItemMessageW(param_1,0x3f3,0x14e,0,0);
      uVar6 = 4;
      do {
        swprintf(&local_228,0x401010fc,(wchar_t *)(1 << (uVar6 & 0x1f)));
        SendDlgItemMessageW(param_1,0x3ee,0x143,0,(LPARAM)&local_228);
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 0xd);
      SendDlgItemMessageW(param_1,0x3ee,0x14e,5,0);
      FUN_40104678(param_1);
      DAT_4010e714 = LoadLibraryW(L"commctrl.dll");
      if (DAT_4010e714 != (HMODULE)0x0) {
        pcVar4 = (code *)GetProcAddressW(DAT_4010e714,L"InitCommonControls");
        if (pcVar4 != (code *)0x0) {
          (*pcVar4)();
          DAT_4010ebcc = GetDlgItem(param_1,0x3eb);
          if (DAT_4010ebcc != (HWND)0x0) {
            SendMessageW(DAT_4010ebcc,0x401,0,0x640000);
            SendMessageW(DAT_4010ebcc,0x402,0,0);
            FUN_4010d048(local_20);
            return 1;
          }
        }
        FreeLibrary(DAT_4010e714);
      }
      goto LAB_40104894;
    }
    UVar5 = 0xceb;
  }
  FUN_40108e90(UVar5,0xd4c,0);
LAB_40104894:
  FUN_4010d048(local_20);
  return 0;
}



/* 40104bb8 FUN_40104bb8 */

/* Boundary evidence: original MIPS .pdata 40104bb8..40104d1f. Semantic name remains unreviewed. */

undefined4 FUN_40104bb8(HWND param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 0x10) {
    FUN_40104314(param_1);
    return 1;
  }
  if (param_2 == 0x110) {
    iVar1 = param_4;
    if (param_4 == 0) {
      EndDialog(param_1,0);
      iVar1 = DAT_4010e710;
    }
    DAT_4010e710 = iVar1;
    iVar1 = FUN_401047e8(param_1);
    if (iVar1 != 0) {
      return 1;
    }
    EndDialog(param_1,0);
  }
  else {
    if (param_2 != 0x111) {
      return 0;
    }
    uVar2 = param_3 & 0xffff;
    if (uVar2 == 0x3e9) {
      iVar1 = FUN_40108e90(0xce7,0xd49,1);
      if (iVar1 == 0) {
        return 1;
      }
      FUN_40104544(param_1);
      FUN_40108e90(0xce8,0xd49,0);
LAB_40104ca4:
      FUN_40104314(param_1);
      return 1;
    }
    if (uVar2 == 0x3ea) {
      iVar1 = FUN_40108e90(0xcea,0xd4d,1);
      if (iVar1 == 0) {
        return 1;
      }
      goto LAB_40104ca4;
    }
    if (uVar2 == 0x3f1) {
      if (param_3 >> 0x10 == 1) goto LAB_40104c44;
    }
    else if (uVar2 != 0x3f7) {
      return 0;
    }
    if (param_3 >> 0x10 == 0) {
LAB_40104c44:
      FUN_40104678(param_1);
      return 1;
    }
  }
  return 0;
}



/* 40104d20 FormatVolumeUI */

/* Boundary evidence: original MIPS .pdata 40104d20..40104d9f. Semantic name remains unreviewed. */

void FormatVolumeUI(LPARAM param_1,HWND param_2)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
                    /* 0x4d20  6  FormatVolumeUI */
  hResInfo = FindResourceW(DAT_4010e398,(LPCWSTR)0x65,(LPCWSTR)0x5);
  hDialogTemplate = LoadResource(DAT_4010e398,hResInfo);
  DialogBoxIndirectParamW(DAT_4010e398,hDialogTemplate,param_2,FUN_40104bb8,param_1);
  return;
}



/* 40104da0 FUN_40104da0 */

/* Boundary evidence: original MIPS .pdata 40104da0..40104eab. Semantic name remains unreviewed. */

void FUN_40104da0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  
  pcVar3 = (code *)*param_1;
  if (pcVar3 == (code *)0x0) {
    return;
  }
  uVar4 = param_1[3];
  uVar5 = param_1[0x27];
  uVar1 = __ull_div((int)((ulonglong)uVar4 * 100),(int)((ulonglong)uVar4 * 100 >> 0x20),uVar5,0);
  if (uVar4 == 0) {
    param_1[3] = uVar5 / 10;
  }
  else {
    if ((param_1[6] == 0) && (uVar1 < 0x32)) {
      iVar2 = uVar4 + 2;
    }
    else {
      if ((param_1[6] != 1) || (99 < uVar1)) goto LAB_40104e4c;
      iVar2 = uVar4 + 1;
    }
    param_1[3] = iVar2;
  }
LAB_40104e4c:
  uVar1 = __ull_div((int)((ulonglong)(uint)param_1[3] * 100),
                    (int)((ulonglong)(uint)param_1[3] * 100 >> 0x20),uVar5,0);
  if ((uVar1 != param_1[2]) && (uVar1 < 0x65)) {
    param_1[2] = uVar1;
    (*pcVar3)(uVar1);
  }
  return;
}



/* 40104eac FUN_40104eac */

/* Boundary evidence: original MIPS .pdata 40104eac..40104f43. Semantic name remains unreviewed. */

void FUN_40104eac(int param_1,UINT param_2,UINT param_3)

{
  if (*(int *)(param_1 + 4) != 0) {
    LoadStringW(DAT_4010e398,param_2,(LPWSTR)&DAT_4010e86c,0x104);
    LoadStringW(DAT_4010e398,param_3,(LPWSTR)&DAT_4010e858,10);
    (**(code **)(param_1 + 4))(&DAT_4010e86c,&DAT_4010e858,0);
  }
  return;
}



/* 40104f44 FUN_40104f44 */

/* Boundary evidence: original MIPS .pdata 40104f44..40104f9b. Semantic name remains unreviewed. */

undefined4 FUN_40104f44(int param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(HANDLE *)(param_1 + 0x1c) != (HANDLE)0x0) &&
     (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x1c),0), DVar1 == 0)) {
    uVar2 = 1;
    SetLastError(0x4c7);
  }
  return uVar2;
}



/* 40104f9c FUN_40104f9c */

/* Boundary evidence: original MIPS .pdata 40104f9c..4010505f. Semantic name remains unreviewed. */

DWORD FUN_40104f9c(int param_1)

{
  DWORD DVar1;
  UINT UVar2;
  
  DVar1 = GetLastError();
  if (DVar1 == 0) {
    DVar1 = 0x1f;
  }
  if (DVar1 == 0x1d) {
    UVar2 = 0xc2e;
  }
  else if (DVar1 == 0x1e) {
    UVar2 = 0xc2d;
  }
  else if (DVar1 == 0x70) {
    UVar2 = 0xc30;
  }
  else if (DVar1 == 0x3ed) {
    UVar2 = 0xc2f;
  }
  else if (DVar1 == 0x4c7) {
    UVar2 = 0xc31;
  }
  else {
    UVar2 = 0xc1d;
  }
  FUN_40104eac(param_1,UVar2,0xd4a);
  return DVar1;
}



/* 40105060 FUN_40105060 */

/* Boundary evidence: original MIPS .pdata 40105060..401053d3. Semantic name remains unreviewed. */

undefined4 FUN_40105060(int param_1)

{
  byte bVar1;
  ushort uVar2;
  HANDLE pvVar3;
  LPVOID lpMem;
  BOOL BVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  pvVar3 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar3,0,*(SIZE_T *)(param_1 + 0xb8));
  uVar8 = 0;
  if (lpMem == (LPVOID)0x0) {
    return 0;
  }
  BVar4 = FUN_40107c94((undefined4 *)(param_1 + 0x5c),0,lpMem,1);
  if (BVar4 == 0) goto LAB_40105388;
  if (*(char *)((int)lpMem + 0x16) == '\0' && *(char *)((int)lpMem + 0x17) == '\0') {
    *(uint *)(param_1 + 0xa8) = (uint)*(ushort *)((int)lpMem + 0xe);
    iVar5 = memcmp((void *)((int)lpMem + 0x52),&DAT_40101118,4);
    *(uint *)(param_1 + 0xd0) = (uint)(iVar5 == 0);
    bVar1 = *(byte *)((int)lpMem + 0x10);
    *(uint *)(param_1 + 200) = (uint)bVar1;
    if (bVar1 == 0) {
      if ((iVar5 == 0) != 1) goto LAB_40105388;
      *(undefined4 *)(param_1 + 0xd0) = 2;
      *(undefined4 *)(param_1 + 200) = 2;
    }
    iVar5 = *(int *)((int)lpMem + 0x24);
    *(int *)(param_1 + 0xc4) = iVar5;
    if (iVar5 == 0) goto LAB_40105388;
    iVar5 = iVar5 * *(int *)(param_1 + 200) + (uint)*(ushort *)((int)lpMem + 0xe);
    *(int *)(param_1 + 0xac) = iVar5;
    uVar6 = *(int *)((int)lpMem + 0x20) - iVar5;
    *(uint *)(param_1 + 0x98) = uVar6;
    uVar7 = (uint)*(byte *)((int)lpMem + 0xd);
    *(uint *)(param_1 + 0xbc) = uVar7;
    if (uVar7 == 0) goto LAB_40105388;
    uVar6 = uVar6 / uVar7;
    if (uVar7 == 0) {
      trap(0x1c00);
    }
    *(uint *)(param_1 + 0x9c) = uVar6;
    *(uint *)(param_1 + 0xa0) = uVar6 + 1;
    *(undefined4 *)(param_1 + 0x94) = 0x20;
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
    iVar5 = *(int *)(param_1 + 0xbc) * *(int *)(param_1 + 0xb8);
    *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)((int)lpMem + 0x2c);
  }
  else {
    *(uint *)(param_1 + 0xa8) = (uint)*(ushort *)((int)lpMem + 0xe);
    iVar5 = memcmp((void *)((int)lpMem + 0x36),&DAT_40101118,4);
    *(uint *)(param_1 + 0xd0) = (uint)(iVar5 == 0);
    bVar1 = *(byte *)((int)lpMem + 0x10);
    *(uint *)(param_1 + 200) = (uint)bVar1;
    if (bVar1 == 0) {
      if ((iVar5 == 0) != 1) goto LAB_40105388;
      *(undefined4 *)(param_1 + 0xd0) = 2;
      *(undefined4 *)(param_1 + 200) = 2;
    }
    uVar2 = *(ushort *)((int)lpMem + 0x16);
    *(uint *)(param_1 + 0xc4) = (uint)uVar2;
    if (uVar2 == 0) goto LAB_40105388;
    *(uint *)(param_1 + 0xb0) =
         (uint)*(ushort *)((int)lpMem + 0x16) * (uint)*(byte *)((int)lpMem + 0x10) +
         (uint)*(ushort *)((int)lpMem + 0xe);
    uVar2 = *(ushort *)((int)lpMem + 0x11);
    *(uint *)(param_1 + 0xa4) = (uint)uVar2;
    uVar6 = (uint)*(ushort *)((int)lpMem + 0xb);
    uVar7 = (((uint)uVar2 * 0x20 + uVar6) - 1) / uVar6;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    iVar5 = uVar7 + *(int *)(param_1 + 0xb0);
    *(uint *)(param_1 + 0xb4) = uVar7;
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(int *)(param_1 + 0xac) = iVar5;
    if (*(ushort *)((int)lpMem + 0x13) == 0) {
      uVar6 = *(int *)((int)lpMem + 0x20) - iVar5;
    }
    else {
      uVar6 = (uint)*(ushort *)((int)lpMem + 0x13) - iVar5;
    }
    *(uint *)(param_1 + 0x98) = uVar6;
    uVar7 = (uint)*(byte *)((int)lpMem + 0xd);
    *(uint *)(param_1 + 0xbc) = uVar7;
    if (uVar7 == 0) goto LAB_40105388;
    if (uVar7 == 0) {
      trap(0x1c00);
    }
    *(uint *)(param_1 + 0x9c) = uVar6 / uVar7;
    uVar8 = 0xc;
    *(uint *)(param_1 + 0xa0) = uVar6 / uVar7 + 1;
    if (0xff4 < *(uint *)(param_1 + 0x9c)) {
      uVar8 = 0x10;
    }
    iVar5 = *(int *)(param_1 + 0xbc) * *(int *)(param_1 + 0xb8);
    *(undefined4 *)(param_1 + 0x94) = uVar8;
  }
  *(int *)(param_1 + 0xc0) = iVar5;
  uVar8 = 1;
LAB_40105388:
  pvVar3 = GetProcessHeap();
  HeapFree(pvVar3,0,lpMem);
  SetLastError(0x3ed);
  return uVar8;
}



/* 401053d4 FUN_401053d4 */

/* Boundary evidence: original MIPS .pdata 401053d4..401054e3. Semantic name remains unreviewed. */

int FUN_401053d4(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint local_10;
  
  iVar1 = 0;
  if (((param_3 & 1) != 0) && (iVar1 = 0, param_2 == 0)) {
    iVar1 = 1;
  }
  iVar2 = *(int *)(param_1 + 0x94);
  if (iVar2 == 0xc) {
    local_10 = 0xff8;
  }
  else if (iVar2 == 0x10) {
    local_10 = 0xfff8;
  }
  else if (iVar2 == 0x20) {
    local_10 = 0xffffff8;
  }
  if ((param_3 & 2) != 0) {
    if (((iVar1 == 0) && (1 < param_2)) &&
       ((param_2 <= *(uint *)(param_1 + 0xa0) || (local_10 <= param_2)))) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  if (((param_3 & 4) != 0) && ((iVar1 != 0 || (iVar1 = 0, local_10 <= param_2)))) {
    iVar1 = 1;
  }
  if ((param_3 & 8) != 0) {
    if ((iVar1 == 0) && (iVar1 = FUN_401080fc((int *)(param_1 + 0x20),param_2), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}



/* 401054e4 FUN_401054e4 */

undefined4
FUN_401054e4(undefined4 param_1,short *param_2,ushort *param_3,ushort *param_4,undefined1 *param_5)

{
  *param_3 = ((*param_2 + -0x3c) * 0x10 | param_2[1]) << 5 | param_2[3];
  if (param_4 != (ushort *)0x0) {
    *param_4 = (param_2[4] << 6 | param_2[5]) << 5 | (ushort)param_2[6] >> 1;
  }
  if (param_5 != (undefined1 *)0x0) {
    *param_5 = (char)((ushort)param_2[7] / 10);
  }
  return 1;
}



/* 40105568 FUN_40105568 */

/* Boundary evidence: original MIPS .pdata 40105568..4010584f. Semantic name remains unreviewed. */

uint FUN_40105568(int param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  HANDLE pvVar5;
  uint *lpMem;
  LPVOID lpMem_00;
  uint uVar6;
  undefined3 extraout_var;
  BOOL BVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int *piVar11;
  uint local_38;
  
  bVar1 = true;
  uVar10 = 0;
  uVar8 = 0xfffffffe;
  iVar3 = FUN_401053d4(param_1,param_2,6);
  uVar4 = param_2;
  if (iVar3 == 0) {
    do {
      uVar10 = uVar10 + 1;
      uVar4 = FUN_40108734((int *)(param_1 + 0x40),uVar4);
      if (uVar4 == 0xfffffffe) {
        return 0xfffffffe;
      }
      iVar3 = FUN_401053d4(param_1,uVar4,6);
    } while (iVar3 == 0);
  }
  iVar3 = FUN_401053d4(param_1,uVar4,2);
  if ((iVar3 == 0) && ((uVar10 & 0x3fffffff) == uVar10)) {
    pvVar5 = GetProcessHeap();
    lpMem = HeapAlloc(pvVar5,0,uVar10 << 2);
    if (lpMem != (uint *)0x0) {
      pvVar5 = GetProcessHeap();
      lpMem_00 = HeapAlloc(pvVar5,0,*(SIZE_T *)(param_1 + 0xc0));
      if (lpMem_00 == (LPVOID)0x0) {
        pvVar5 = GetProcessHeap();
        HeapFree(pvVar5,0,lpMem);
      }
      else {
        uVar4 = 0;
        if (uVar10 != 0) {
          puVar9 = lpMem;
          do {
            uVar6 = FUN_40108a40((int *)(param_1 + 0x40));
            if (uVar6 == 0xffffffff) {
              SetLastError(0x70);
              goto LAB_401057c8;
            }
            uVar4 = uVar4 + 1;
            *puVar9 = uVar6;
            puVar9 = puVar9 + 1;
          } while (uVar4 < uVar10);
        }
        piVar11 = (int *)(param_1 + 0x30);
        if ((*piVar11 == 0) &&
           (bVar2 = FUN_40107fa4(piVar11,param_1 + 0x94), CONCAT31(extraout_var,bVar2) == 0)) {
          bVar1 = false;
        }
        uVar4 = 0;
        if (uVar10 != 0) {
          puVar9 = lpMem;
          local_38 = param_2;
          do {
            uVar6 = *puVar9;
            BVar7 = FUN_40107d74((undefined4 *)(param_1 + 0x5c),local_38,lpMem_00);
            if ((BVar7 == 0) ||
               (BVar7 = FUN_40107d2c((undefined4 *)(param_1 + 0x5c),uVar6,lpMem_00), BVar7 == 0))
            goto LAB_401057c8;
            FUN_40108010((int *)(param_1 + 0x20),uVar6);
            if (bVar1) {
              FUN_40108010(piVar11,uVar6);
            }
            if (uVar4 != 0) {
              FUN_40108830((int *)(param_1 + 0x40),puVar9[-1],uVar6);
            }
            local_38 = FUN_40108734((int *)(param_1 + 0x40),local_38);
            uVar4 = uVar4 + 1;
            puVar9 = puVar9 + 1;
          } while (uVar4 < uVar10);
          if (uVar6 != 0) {
            FUN_40108830((int *)(param_1 + 0x40),uVar6,0xffffffff);
          }
        }
        uVar8 = *lpMem;
LAB_401057c8:
        pvVar5 = GetProcessHeap();
        HeapFree(pvVar5,0,lpMem);
        pvVar5 = GetProcessHeap();
        HeapFree(pvVar5,0,lpMem_00);
        *param_3 = uVar10;
      }
    }
  }
  return uVar8;
}



/* 40105850 FUN_40105850 */

/* Boundary evidence: original MIPS .pdata 40105850..40105c4f. Semantic name remains unreviewed. */

undefined4 FUN_40105850(undefined4 *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  uint uVar9;
  uint local_38;
  uint local_34;
  uint local_30;
  HANDLE local_2c;
  
  local_38 = 0;
  local_30 = 0;
  uVar7 = 4;
  local_2c = GetProcessHeap();
  uVar4 = *(uint *)(param_3 + 0x1c);
  if (uVar4 == 0) {
    uVar4 = 0x80;
LAB_401058e4:
    if (0x8000 < uVar4) {
      uVar4 = 0x8000;
    }
  }
  else {
    uVar5 = param_1[0x30];
    if (uVar5 <= uVar4) {
      if (uVar5 == 0) {
        trap(0x1c00);
      }
      uVar4 = uVar4 / uVar5 + 1;
      goto LAB_401058e4;
    }
    uVar4 = 1;
  }
  local_34 = 1;
  uVar5 = 0;
  puVar1 = HeapAlloc(local_2c,0,uVar4 << 2);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  iVar2 = FUN_401053d4((int)param_1,param_2,0xe);
  uVar9 = 1;
  if (iVar2 == 0) {
    iVar2 = 0;
    puVar8 = puVar1;
    do {
      puVar1 = puVar8;
      uVar9 = local_34;
      if (uVar4 <= uVar5) break;
      uVar5 = uVar5 + 1;
      *(uint *)(iVar2 + (int)puVar8) = param_2;
      iVar2 = iVar2 + 4;
      if ((local_30 != 0) && (param_2 != local_30 + 1)) {
        param_1[4] = param_1[4] + 1;
      }
      FUN_40104da0(param_1);
      FUN_40108010(param_1 + 8,param_2);
      local_38 = local_38 + 1;
      local_30 = param_2;
      param_2 = FUN_40108734(param_1 + 0x10,param_2);
      if (param_2 == 0xfffffffe) goto LAB_40105b7c;
      if (uVar4 <= uVar5) {
        uVar4 = (uVar4 * 3 >> 1) + 1;
        puVar1 = HeapReAlloc(local_2c,0,puVar8,uVar4 * 4);
        if (puVar1 == (uint *)0x0) goto LAB_40105b7c;
      }
      local_34 = 0;
      iVar3 = FUN_401053d4((int)param_1,param_2,0xe);
      puVar8 = puVar1;
      uVar9 = local_34;
    } while (iVar3 == 0);
  }
  puVar8 = puVar1;
  if ((param_2 != 0) && (iVar2 = FUN_401053d4((int)param_1,param_2,10), iVar2 != 0)) {
    iVar2 = FUN_401053d4((int)param_1,param_2,2);
    if ((iVar2 == 0) &&
       ((param_1[0xc] == 0 || (iVar2 = FUN_401080fc(param_1 + 0xc,param_2), iVar2 == 0)))) {
      uVar6 = 0;
      uVar4 = param_2;
      if (uVar5 != 0) {
        do {
          if (*puVar1 == param_2) {
            uVar4 = 0xffffffff;
            break;
          }
          uVar6 = uVar6 + 1;
          puVar1 = puVar1 + 1;
        } while (uVar6 < uVar5);
      }
      if (uVar4 == 0xffffffff) goto LAB_40105b28;
      iVar2 = FUN_4010775c((int)(param_1 + 0x1b),4);
      if (iVar2 != 0) {
        local_34 = 0;
        uVar4 = FUN_40105568((int)param_1,param_2,&local_34);
        if (uVar4 == 0xfffffffe) {
          param_1[0x23] = 1;
          goto LAB_40105b8c;
        }
        local_38 = local_34 + local_38;
        goto LAB_40105b38;
      }
    }
    else {
      uVar4 = 0xffffffff;
LAB_40105b28:
      iVar2 = FUN_4010775c((int)(param_1 + 0x1b),2);
LAB_40105b38:
      if (iVar2 != 0) {
        if (uVar9 == 0) {
          iVar2 = FUN_40108830(param_1 + 0x10,local_30,uVar4);
          if (iVar2 == 0) {
LAB_40105b7c:
            uVar7 = 0;
            goto LAB_40105c00;
          }
        }
        else {
          *(short *)(param_3 + 0x1a) = (short)uVar4;
          *(short *)(param_3 + 0x14) = (short)(uVar4 >> 0x10);
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = 1;
          }
        }
        goto LAB_40105ba0;
      }
    }
LAB_40105b8c:
    uVar7 = 3;
  }
LAB_40105ba0:
  uVar4 = param_1[0x30];
  if (uVar4 == 0) {
    trap(0x1c00);
  }
  if ((((uVar4 + *(int *)(param_3 + 0x1c)) - 1) / uVar4 != local_38) &&
     (((param_1[6] == 1 || (iVar2 = FUN_4010775c((int)(param_1 + 0x1b),2), iVar2 != 0)) &&
      (*(uint *)(param_3 + 0x1c) = local_38 * param_1[0x30], param_4 != (undefined4 *)0x0)))) {
    *param_4 = 1;
  }
LAB_40105c00:
  if (puVar8 != (uint *)0x0) {
    HeapFree(local_2c,0,puVar8);
  }
  return uVar7;
}



/* 40105c50 FUN_40105c50 */

/* Boundary evidence: original MIPS .pdata 40105c50..40105e73. Semantic name remains unreviewed. */

undefined4 FUN_40105c50(undefined4 *param_1,uint param_2,undefined1 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = FUN_401053d4((int)param_1,param_2,0xe);
  if (iVar1 == 0) {
    FUN_40108010(param_1 + 8,param_2);
    FUN_40104da0(param_1);
    iVar1 = FUN_401053d4((int)param_1,param_2,4);
    while (iVar1 == 0) {
      iVar3 = param_1[0x2f];
      iVar1 = param_1[0x2b];
      uVar4 = 0;
      if (iVar3 != 0) {
        do {
          iVar2 = FUN_40106744(param_1,uVar4 + (param_2 - 2) * iVar3 + iVar1);
          if (iVar2 == 0) {
            return 0;
          }
          if (iVar2 == 5) {
            return 5;
          }
        } while ((iVar2 != 2) && (uVar4 = uVar4 + 1, uVar4 < (uint)param_1[0x2f]));
      }
      uVar4 = FUN_40108734(param_1 + 0x10,param_2);
      if (uVar4 == 0xfffffffe) {
        return 0;
      }
      iVar1 = FUN_401053d4((int)param_1,uVar4,4);
      if (iVar1 != 0) {
        return 4;
      }
      iVar1 = FUN_401053d4((int)param_1,uVar4,2);
      if ((iVar1 != 0) || (iVar1 = FUN_40108010(param_1 + 8,uVar4), iVar1 == 0)) {
        iVar1 = FUN_4010775c((int)(param_1 + 0x1b),1);
        if (iVar1 == 0) {
          return 3;
        }
        iVar1 = FUN_40108830(param_1 + 0x10,param_2,0xffffffff);
        if (iVar1 != 0) {
          return 4;
        }
        return 0;
      }
      if (uVar4 != param_2 + 1) {
        param_1[4] = param_1[4] + 1;
      }
      FUN_40104da0(param_1);
      iVar1 = FUN_401053d4((int)param_1,uVar4,4);
      param_2 = uVar4;
    }
  }
  else {
    if ((param_3 == (undefined1 *)0x0) ||
       (iVar1 = FUN_4010775c((int)(param_1 + 0x1b),1), iVar1 == 0)) {
      return 3;
    }
    memset(param_3,0,0x20);
    *param_3 = 0xe5;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 1;
    }
  }
  return 4;
}



/* 40105e74 FUN_40105e74 */

/* Boundary evidence: original MIPS .pdata 40105e74..4010613b. Semantic name remains unreviewed. */

char * FUN_40105e74(int param_1,char *param_2,uint *param_3,char *param_4)

{
  uint uVar1;
  int iVar2;
  BOOL BVar3;
  HANDLE pvVar4;
  LPVOID pvVar5;
  int *piVar6;
  uint uVar7;
  
  if (*(int *)(param_1 + 0x94) == 0x20) {
    uVar7 = *(uint *)(param_1 + 0xc0);
  }
  else {
    uVar7 = *(uint *)(param_1 + 0xb8);
  }
  do {
    while( true ) {
      if ((*param_4 == -0x1b) || (*param_4 == '\0')) {
        if (*param_4 != '\0') {
          return param_4;
        }
        if (uVar7 <= (uint)((int)(param_4 + 0x20) - (int)param_2)) {
          if (*(int *)(param_1 + 0x94) != 0x20) {
            pvVar4 = GetProcessHeap();
            pvVar5 = HeapAlloc(pvVar4,8,*(SIZE_T *)(param_1 + 0xb8));
            FUN_40107bfc((undefined4 *)(param_1 + 0x5c),*param_3 + 1,pvVar5,1);
            pvVar4 = GetProcessHeap();
            HeapFree(pvVar4,0,pvVar5);
            return param_4;
          }
          return param_4;
        }
        memset(param_4 + 0x20,0,0x20);
        return param_4;
      }
      if (uVar7 - 0x20 <= (uint)((int)param_4 - (int)param_2)) break;
      param_4 = param_4 + 0x20;
    }
    if (*(int *)(param_1 + 0x94) == 0x20) {
      piVar6 = (int *)(param_1 + 0x40);
      uVar1 = FUN_40108734(piVar6,*param_3);
      if (uVar1 == 0xfffffffe) {
        return (char *)0x0;
      }
      iVar2 = FUN_401053d4(param_1,uVar1,4);
      if (iVar2 != 0) {
        uVar1 = FUN_40108a40(piVar6);
        iVar2 = FUN_401053d4(param_1,uVar1,4);
        if (iVar2 != 0) {
          return (char *)0x0;
        }
        pvVar4 = GetProcessHeap();
        pvVar5 = HeapAlloc(pvVar4,8,*(SIZE_T *)(param_1 + 0xc0));
        FUN_40108010((int *)(param_1 + 0x20),uVar1);
        iVar2 = FUN_40108830(piVar6,*param_3,uVar1);
        if (((iVar2 == 0) || (iVar2 = FUN_40108830(piVar6,uVar1,0xffffffff), iVar2 == 0)) ||
           (BVar3 = FUN_40107d2c((undefined4 *)(param_1 + 0x5c),uVar1,pvVar5), BVar3 == 0)) {
          pvVar4 = GetProcessHeap();
          HeapFree(pvVar4,0,pvVar5);
          return (char *)0x0;
        }
        pvVar4 = GetProcessHeap();
        HeapFree(pvVar4,0,pvVar5);
      }
      *param_3 = uVar1;
    }
    else {
      if ((uint)(*(int *)(param_1 + 0xb4) + *(int *)(param_1 + 0xb0)) <= *param_3) {
        return (char *)0x0;
      }
      *param_3 = *param_3 + 1;
    }
    if (*(int *)(param_1 + 0x94) == 0x20) {
      iVar2 = FUN_40107d74((undefined4 *)(param_1 + 0x5c),*param_3,param_2);
    }
    else {
      iVar2 = FUN_40107c94((undefined4 *)(param_1 + 0x5c),*param_3,param_2,1);
    }
    param_4 = param_2;
    if (iVar2 == 0) {
      return (char *)0x0;
    }
  } while( true );
}



/* 4010613c FUN_4010613c */

/* Boundary evidence: original MIPS .pdata 4010613c..4010628b. Semantic name remains unreviewed. */

undefined4 FUN_4010613c(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  ushort uVar1;
  size_t _Size;
  size_t sVar2;
  undefined4 uVar3;
  uint _Value;
  _SYSTEMTIME _Stack_38;
  char acStack_28 [8];
  uint local_20;
  
  local_20 = DAT_4010e38c;
  _Value = (DAT_4010ea74 + 1) % 10000;
  DAT_4010ea74 = _Value;
  memset(param_3,0,0x20);
  _itoa(_Value,acStack_28,10);
  *param_3 = 0x454c4946;
  builtin_strncpy((char *)(param_3 + 1),"0000",4);
  *(char *)((int)(param_3 + 2) + 0) = 'C';
  *(char *)((int)(param_3 + 2) + 1) = 'H';
  *(char *)((int)param_3 + 10) = 'K';
  _Size = strlen(acStack_28);
  sVar2 = strlen(acStack_28);
  memcpy((void *)((int)param_3 + (8 - sVar2)),acStack_28,_Size);
  *(short *)((int)param_3 + 0x1a) = (short)param_2;
  *(short *)(param_3 + 5) = (short)(param_2 >> 0x10);
  GetLocalTime(&_Stack_38);
  FUN_401054e4(param_1,(short *)&_Stack_38,(ushort *)(param_3 + 4),(ushort *)((int)param_3 + 0xe),
               (undefined1 *)((int)param_3 + 0xd));
  uVar1 = *(ushort *)(param_3 + 4);
  *(ushort *)(param_3 + 6) = uVar1;
  *(ushort *)((int)param_3 + 0x12) = uVar1;
  *(ushort *)((int)param_3 + 0x16) = *(ushort *)((int)param_3 + 0xe);
  uVar3 = FUN_40105850(param_1,param_2,(int)param_3,(undefined4 *)0x0);
  FUN_4010d048(local_20);
  return uVar3;
}



/* 4010628c FUN_4010628c */

/* Boundary evidence: original MIPS .pdata 4010628c..40106467. Semantic name remains unreviewed. */

undefined4 FUN_4010628c(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  HANDLE pvVar3;
  char *lpMem;
  char *_Dst;
  SIZE_T dwBytes;
  undefined4 *puVar4;
  uint uVar5;
  uint local_50 [2];
  undefined4 auStack_48 [8];
  uint local_28;
  
  local_28 = DAT_4010e38c;
  iVar1 = FUN_4010775c((int)(param_1 + 0x1b),0x10);
  iVar2 = FUN_4010613c(param_1,param_2,auStack_48);
  if (iVar2 != 0) {
    if (iVar2 == 3) {
      FUN_4010d048(local_28);
      return 1;
    }
    if (iVar1 == 0) {
LAB_40106438:
      FUN_4010d048(local_28);
      return 1;
    }
    if (param_1[0x25] == 0x20) {
      uVar5 = param_1[0x33];
      local_50[0] = uVar5;
      pvVar3 = GetProcessHeap();
      dwBytes = param_1[0x30];
    }
    else {
      uVar5 = param_1[0x2c];
      local_50[0] = uVar5;
      pvVar3 = GetProcessHeap();
      dwBytes = param_1[0x2e];
    }
    lpMem = HeapAlloc(pvVar3,0,dwBytes);
    if (lpMem != (char *)0x0) {
      puVar4 = param_1 + 0x17;
      if (param_1[0x25] == 0x20) {
        iVar1 = FUN_40107d74(puVar4,uVar5,lpMem);
      }
      else {
        iVar1 = FUN_40107c94(puVar4,uVar5,lpMem,1);
      }
      if ((iVar1 != 0) &&
         (_Dst = FUN_40105e74((int)param_1,lpMem,local_50,lpMem), _Dst != (char *)0x0)) {
        memcpy(_Dst,auStack_48,0x20);
        if (param_1[0x25] == 0x20) {
          iVar1 = FUN_40107d2c(puVar4,local_50[0],lpMem);
        }
        else {
          iVar1 = FUN_40107bfc(puVar4,local_50[0],lpMem,1);
        }
        if (iVar1 != 0) {
          pvVar3 = GetProcessHeap();
          HeapFree(pvVar3,0,lpMem);
          goto LAB_40106438;
        }
      }
      pvVar3 = GetProcessHeap();
      HeapFree(pvVar3,0,lpMem);
    }
  }
  FUN_4010d048(local_28);
  return 0;
}



/* 40106468 FUN_40106468 */

/* Boundary evidence: original MIPS .pdata 40106468..401065bf. Semantic name remains unreviewed. */

undefined4
FUN_40106468(undefined4 *param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5,
            int param_6,undefined4 param_7)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  SetLastError(0);
  if (param_4 == (uint *)0x0) {
    uVar4 = 0;
    uVar5 = 1;
  }
  else {
    uVar4 = *param_4;
    uVar5 = param_4[1];
  }
  *param_1 = param_5;
  param_1[1] = param_6;
  param_1[7] = param_7;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  uVar3 = *(undefined4 *)(param_3 + 4);
  param_1[0x2e] = uVar3;
  param_1[0x18] = uVar3;
  param_1[0x17] = param_2;
  param_1[0x19] = 0;
  param_1[0x1a] = 1;
  FUN_40107720(param_1 + 0x1b,(uint)((uVar4 & 1) != 0),param_6);
  iVar2 = FUN_40105060((int)param_1);
  if (iVar2 != 0) {
    puVar6 = param_1 + 0x25;
    bVar1 = FUN_40107fa4(param_1 + 8,(int)puVar6);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if ((uVar5 == 0) || ((uint)param_1[0x32] < uVar5)) {
        uVar5 = 1;
      }
      iVar2 = FUN_40108238(param_1 + 0x10,param_1 + 0x17,(int)puVar6,uVar5,0);
      if (iVar2 != 0) {
        param_1[0x19] = puVar6;
        return 1;
      }
    }
  }
  return 0;
}



/* 401065c0 FUN_401065c0 */

/* Boundary evidence: original MIPS .pdata 401065c0..40106743. Semantic name remains unreviewed. */

undefined4 FUN_401065c0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (1 < (uint)param_1[0x28]) {
    iVar3 = 0;
    do {
      iVar1 = FUN_40104f44((int)param_1);
      if (iVar1 != 0) {
        return 0;
      }
      uVar4 = iVar3 + 2;
      iVar1 = FUN_401080fc(param_1 + 8,uVar4);
      if (iVar1 == 0) {
        uVar2 = FUN_40108734(param_1 + 0x10,uVar4);
        iVar1 = FUN_401053d4((int)param_1,uVar2,1);
        if (iVar1 == 0) {
          iVar1 = FUN_401053d4((int)param_1,uVar2,2);
          if (iVar1 == 0) {
            iVar1 = FUN_4010628c(param_1,uVar4);
            if (iVar1 == 0) {
              return 0;
            }
          }
          else {
            iVar1 = FUN_4010775c((int)(param_1 + 0x1b),8);
            if (iVar1 != 0) {
              FUN_40108830(param_1 + 0x10,uVar4,0);
            }
          }
        }
        else {
          FUN_40107e78(param_1 + 0x17,iVar3 * param_1[0x2f] + param_1[0x2b],param_1[0x2f]);
          FUN_40104da0(param_1);
        }
      }
      uVar4 = iVar3 + 3;
      iVar3 = iVar3 + 1;
    } while (uVar4 <= (uint)param_1[0x28]);
  }
  uVar4 = param_1[9];
  if (uVar4 != 0) {
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    param_1[0x20] = (uint)(param_1[4] * 100) / uVar4;
  }
  return 1;
}



/* 40106744 FUN_40106744 */

/* Boundary evidence: original MIPS .pdata 40106744..401069bf. Semantic name remains unreviewed. */

int FUN_40106744(undefined4 *param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
  HANDLE pvVar3;
  LPVOID lpMem;
  BOOL BVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  int local_30;
  uint local_2c;
  
  local_2c = DAT_4010e38c;
  pvVar3 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar3,0,param_1[0x2e]);
  uVar10 = (uint)param_1[0x2e] >> 5;
  uVar9 = 0;
  iVar12 = 1;
  local_30 = 0;
  if (lpMem == (LPVOID)0x0) {
    FUN_4010d048(local_2c);
    iVar8 = 0;
  }
  else {
    BVar4 = FUN_40107c94(param_1 + 0x17,param_2,lpMem,1);
    if (BVar4 == 0) {
LAB_401069b8:
      iVar8 = 0;
    }
    else {
      iVar8 = iVar12;
      if (uVar10 != 0) {
        while (pcVar11 = (char *)(uVar9 * 0x20 + (int)lpMem), *pcVar11 != '\0') {
          iVar5 = FUN_40104f44((int)param_1);
          iVar8 = 5;
          if (iVar5 != 0) goto LAB_4010697c;
          pbVar7 = (byte *)(pcVar11 + 0xb);
          bVar1 = *pbVar7;
          while ((bVar1 & 0x1f) == 0xf) {
            uVar9 = uVar9 + 1;
            pbVar7 = pbVar7 + 0x20;
            iVar8 = iVar12;
            if (uVar10 <= uVar9) goto LAB_40106934;
            bVar1 = *pbVar7;
          }
          iVar8 = iVar12;
          if (uVar10 <= uVar9) goto LAB_40106934;
          pcVar11 = (char *)(uVar9 * 0x20 + (int)lpMem);
          cVar2 = *pcVar11;
          if (cVar2 != '\0') {
            if (cVar2 != -0x1b) {
              uVar6 = (uint)*(ushort *)(pcVar11 + 0x14) * 0x10000 +
                      (uint)*(ushort *)(pcVar11 + 0x1a);
              if ((pcVar11[0xb] & 0x10U) == 0) {
                if ((pcVar11[0xb] & 8U) == 0) {
                  iVar8 = FUN_40105850(param_1,uVar6,(int)pcVar11,&local_30);
                  if (iVar8 != 0) goto LAB_401068f4;
                  goto LAB_401069b8;
                }
              }
              else if (cVar2 != '.') {
                iVar8 = FUN_40105c50(param_1,uVar6,pcVar11,&local_30);
                if ((iVar8 == 0) || (iVar8 == 5)) goto LAB_40106964;
LAB_401068f4:
                param_1[5] = param_1[5] + 1;
              }
            }
            uVar9 = uVar9 + 1;
          }
          if (uVar10 <= uVar9) break;
        }
        iVar8 = iVar12;
        if ((uVar9 < uVar10) && (*(char *)(uVar9 * 0x20 + (int)lpMem) == '\0')) {
          iVar8 = 2;
        }
LAB_40106934:
        if ((local_30 != 0) && (BVar4 = FUN_40107bfc(param_1 + 0x17,param_2,lpMem,1), BVar4 == 0)) {
          iVar8 = 0;
        }
      }
    }
LAB_40106964:
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,lpMem);
LAB_4010697c:
    FUN_4010d048(local_2c);
  }
  return iVar8;
}



/* 401069c0 FUN_401069c0 */

/* Boundary evidence: original MIPS .pdata 401069c0..40106ac3. Semantic name remains unreviewed. */

undefined4 FUN_401069c0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1[0x34] == 0) {
    uVar1 = FUN_401082c0((int)(param_1 + 0x10));
    param_1[0x22] = uVar1;
  }
  else {
    iVar2 = FUN_40108b38(param_1 + 0x10);
    if (iVar2 == 0) {
      return 0;
    }
    param_1[0x22] = 1;
  }
  if (param_1[0x25] == 0x20) {
    iVar2 = FUN_40105c50(param_1,param_1[0x33],(undefined1 *)0x0,(undefined4 *)0x0);
    if ((iVar2 != 0) && (iVar2 != 5)) {
      return 1;
    }
  }
  else {
    uVar3 = 0;
    if (param_1[0x2d] == 0) {
      return 1;
    }
    while ((iVar2 = FUN_40106744(param_1,param_1[0x2c] + uVar3), iVar2 != 0 && (iVar2 != 5))) {
      if (iVar2 == 2) {
        return 1;
      }
      uVar3 = uVar3 + 1;
      if ((uint)param_1[0x2d] <= uVar3) {
        return 1;
      }
    }
  }
  return 0;
}



/* 40106ac4 FUN_40106ac4 */

/* Boundary evidence: original MIPS .pdata 40106ac4..40106cbb. Semantic name remains unreviewed. */

DWORD FUN_40106ac4(HANDLE param_1,uint *param_2,undefined *param_3,undefined *param_4,
                  undefined4 param_5,int *param_6)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD aDStack_248 [2];
  undefined1 auStack_240 [24];
  undefined4 auStack_228 [6];
  undefined4 local_210;
  undefined4 local_208 [4];
  undefined4 local_1f8 [4];
  undefined4 local_1e8 [11];
  int aiStack_1bc [8];
  int local_19c;
  undefined4 local_150 [72];
  uint local_30;
  uint local_28;
  
  local_28 = DAT_4010e38c;
  local_208[0] = 0;
  local_1f8[0] = 0;
  local_1e8[0] = 0;
  local_150[0] = 0x128;
  if ((param_2 == (uint *)0x0) || ((*param_2 & 4) == 0)) {
    iVar1 = GetPartitionInfo(param_1,local_150);
    if (iVar1 != 0) {
      if ((local_30 & 0x10) != 0) {
        FUN_401031ac(0xceb,param_4);
        DVar3 = 0x20;
        goto LAB_40106c74;
      }
      goto LAB_40106b78;
    }
    FUN_401031ac(0xce5,param_4);
  }
  else {
LAB_40106b78:
    BVar2 = DeviceIoControl(param_1,1,auStack_240,0x18,auStack_240,0x18,aDStack_248,
                            (LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      iVar1 = FUN_40106468(auStack_228,param_1,(int)auStack_240,param_2,param_3,(int)param_4,param_5
                          );
      if (iVar1 != 0) {
        iVar1 = FUN_401069c0(auStack_228);
        if (iVar1 != 0) {
          local_210 = 1;
          iVar1 = FUN_401065c0(auStack_228);
          if (iVar1 != 0) {
            if (local_19c != 0) {
              FUN_40104eac((int)auStack_228,0xc1e,0xd4a);
            }
            FUN_401078c4((int)aiStack_1bc);
            if (param_3 != (undefined *)0x0) {
              (*(code *)param_3)(100);
            }
            if (param_6 != (int *)0x0) {
              FUN_40107b38(aiStack_1bc,param_6);
            }
            DVar3 = 0;
            goto LAB_40106c74;
          }
        }
      }
      DVar3 = FUN_40104f9c((int)auStack_228);
      goto LAB_40106c74;
    }
  }
  DVar3 = 0x1f;
LAB_40106c74:
  FUN_40108568(local_1e8);
  FUN_401081f8(local_1f8);
  FUN_401081f8(local_208);
  FUN_4010d048(local_28);
  return DVar3;
}



/* 40106cbc ScanVolume */

/* Boundary evidence: original MIPS .pdata 40106cbc..40106d43. Semantic name remains unreviewed. */

bool ScanVolume(HANDLE param_1,undefined4 param_2,uint *param_3,undefined *param_4,
               undefined *param_5)

{
  int iVar1;
  DWORD DVar2;
  
                    /* 0x6cbc  7  ScanVolume */
  iVar1 = FUN_4010b718(param_1);
  if (iVar1 == 0) {
    DVar2 = FUN_40106ac4(param_1,param_3,param_4,param_5,0,(int *)0x0);
  }
  else {
    DVar2 = FUN_4010be74(param_1,param_3,param_4,param_5,0,(int *)0x0);
  }
  return DVar2 == 0;
}



/* 40106d44 ScanVolumeEx */

/* Boundary evidence: original MIPS .pdata 40106d44..40106e03. Semantic name remains unreviewed. */

void ScanVolumeEx(HANDLE param_1,int param_2)

{
  int iVar1;
  
                    /* 0x6d44  8  ScanVolumeEx */
  if (param_2 == 0) {
    iVar1 = FUN_4010b718(param_1);
    if (iVar1 == 0) {
      FUN_40106ac4(param_1,(uint *)0x0,(undefined *)0x0,(undefined *)0x0,0,(int *)0x0);
    }
    else {
      FUN_4010be74(param_1,(uint *)0x0,(undefined *)0x0,(undefined *)0x0,0,(int *)0x0);
    }
  }
  else {
    iVar1 = FUN_4010b718(param_1);
    if (iVar1 == 0) {
      FUN_40106ac4(param_1,(uint *)(param_2 + 4),*(undefined **)(param_2 + 0x30),
                   *(undefined **)(param_2 + 0x34),*(undefined4 *)(param_2 + 0x38),
                   (int *)(param_2 + 0xc));
    }
    else {
      FUN_4010be74(param_1,(uint *)(param_2 + 4),*(undefined **)(param_2 + 0x30),
                   *(undefined **)(param_2 + 0x34),*(undefined4 *)(param_2 + 0x38),
                   (int *)(param_2 + 0xc));
    }
  }
  return;
}



/* 40106e04 FUN_40106e04 */

/* Boundary evidence: original MIPS .pdata 40106e04..40106f8b. Semantic name remains unreviewed. */

undefined4 FUN_40106e04(HWND param_1)

{
  BOOL BVar1;
  int iVar2;
  code *pcVar3;
  UINT UVar4;
  DWORD aDStack_18 [2];
  
  DAT_4010ebc8 = param_1;
  FUN_40108cdc(param_1);
  DAT_4010eba8 = 0;
  BVar1 = DeviceIoControl(DAT_4010ea7c,1,&DAT_4010ebac,0x18,&DAT_4010ebac,0x18,aDStack_18,
                          (LPOVERLAPPED)0x0);
  if (BVar1 != 0) {
    DAT_4010ea80 = 0x128;
    iVar2 = GetPartitionInfo(DAT_4010ea7c,&DAT_4010ea80);
    if (iVar2 != 0) {
      if ((DAT_4010eba0 & 0x10) == 0) {
        SetDlgItemTextW(param_1,0x7d3,L"1");
        DAT_4010ebc4 = LoadLibraryW(L"commctrl.dll");
        if (DAT_4010ebc4 == (HMODULE)0x0) {
          return 0;
        }
        pcVar3 = (code *)GetProcAddressW(DAT_4010ebc4,L"InitCommonControls");
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)();
          DAT_4010ebcc = GetDlgItem(param_1,0x3eb);
          if (DAT_4010ebcc != (HWND)0x0) {
            SendMessageW(DAT_4010ebcc,0x401,0,0x640000);
            SendMessageW(DAT_4010ebcc,0x402,0,0);
            return 1;
          }
        }
        FreeLibrary(DAT_4010ebc4);
        return 0;
      }
      UVar4 = 0xceb;
      goto LAB_40106e80;
    }
  }
  UVar4 = 0xce5;
LAB_40106e80:
  FUN_40108e90(UVar4,0xd4c,0);
  return 0;
}



/* 40106f8c FUN_40106f8c */

/* Boundary evidence: original MIPS .pdata 40106f8c..40107013. Semantic name remains unreviewed. */

void FUN_40106f8c(HWND param_1)

{
  if (DAT_4010eba8 == 0) {
    FreeLibrary(DAT_4010ebc4);
    EndDialog(param_1,1);
  }
  if (DAT_4010ea78 != 0) {
    CloseHandle((HANDLE)DAT_4010ea78);
    DAT_4010ea78 = 0;
  }
  DAT_4010eba8 = 1;
  return;
}



/* 40107014 FUN_40107014 */

/* Boundary evidence: original MIPS .pdata 40107014..4010706b. Semantic name remains unreviewed. */

ulong FUN_40107014(HWND param_1)

{
  ulong uVar1;
  WCHAR aWStack_18 [4];
  uint local_10;
  
  local_10 = DAT_4010e38c;
  GetDlgItemTextW(param_1,0x7d3,aWStack_18,3);
  uVar1 = wcstoul(aWStack_18,(wchar_t **)0x0,10);
  FUN_4010d048(local_10);
  return uVar1;
}



/* 4010706c FUN_4010706c */

/* Boundary evidence: original MIPS .pdata 4010706c..4010714b. Semantic name remains unreviewed. */

undefined4 FUN_4010706c(HWND param_1)

{
  LRESULT LVar1;
  HWND hWnd;
  undefined4 local_50;
  uint local_4c;
  ulong local_48;
  code *local_20;
  code *local_1c;
  HANDLE local_18;
  
  local_50 = 0x3c;
  local_48 = FUN_40107014(param_1);
  LVar1 = SendDlgItemMessageW(param_1,0x7d2,0xf0,0,0);
  local_4c = (uint)(LVar1 != 0);
  local_20 = FUN_40108dd0;
  local_1c = FUN_40108dfc;
  DAT_4010ea78 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  local_18 = DAT_4010ea78;
  hWnd = GetDlgItem(param_1,0x3e9);
  EnableWindow(hWnd,0);
  ScanVolumeEx(DAT_4010ea7c,(int)&local_50);
  FUN_40106f8c(param_1);
  return 0;
}



/* 4010714c FUN_4010714c */

/* Boundary evidence: original MIPS .pdata 4010714c..40107283. Semantic name remains unreviewed. */

undefined4 FUN_4010714c(HWND param_1,int param_2,short param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0x10) {
    FUN_40106f8c(param_1);
LAB_40107268:
    uVar2 = 1;
  }
  else {
    if (param_2 == 0x110) {
      iVar1 = param_4;
      if (param_4 == 0) {
        EndDialog(param_1,0);
        iVar1 = DAT_4010ea7c;
      }
      DAT_4010ea7c = iVar1;
      iVar1 = FUN_40106e04(param_1);
      if (iVar1 != 0) goto LAB_40107268;
      EndDialog(param_1,0);
    }
    else if (param_2 == 0x111) {
      if (param_3 == 0x3e9) {
        CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_4010706c,param_1,0,(LPDWORD)0x0);
        goto LAB_40107268;
      }
      if (param_3 == 0x3ea) {
        iVar1 = FUN_40108e90(0xcea,0xd4d,1);
        if (iVar1 == 0) {
          return 1;
        }
        if (DAT_4010ea78 != 0) {
          EventModify(DAT_4010ea78,3);
          return 1;
        }
        FUN_40106f8c(param_1);
        return 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40107284 ScanVolumeUI */

/* Boundary evidence: original MIPS .pdata 40107284..40107303. Semantic name remains unreviewed. */

void ScanVolumeUI(LPARAM param_1,HWND param_2)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
                    /* 0x7284  9  ScanVolumeUI */
  hResInfo = FindResourceW(DAT_4010e398,(LPCWSTR)0x66,(LPCWSTR)0x5);
  hDialogTemplate = LoadResource(DAT_4010e398,hResInfo);
  DialogBoxIndirectParamW(DAT_4010e398,hDialogTemplate,param_2,FUN_4010714c,param_1);
  return;
}



/* 40107304 FUN_40107304 */

int FUN_40107304(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (param_2 < (uint)param_1[1]) {
    for (; param_2 != 0; param_2 = param_2 - 1) {
      iVar2 = 0;
      if (iVar1 != 0) {
        iVar2 = *(int *)(iVar1 + 0x14);
      }
      iVar1 = iVar2;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40107348 FUN_40107348 */

void FUN_40107348(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 != 0) {
    iVar1 = *param_1;
    *(undefined4 *)(param_2 + 0x14) = 0;
    if (iVar1 == 0) {
      *param_1 = param_2;
      param_1[1] = param_1[1] + 1;
    }
    else {
      piVar3 = (int *)(iVar1 + 0x14);
      iVar2 = *piVar3;
      while (iVar2 != 0) {
        iVar1 = *piVar3;
        piVar3 = (int *)(iVar1 + 0x14);
        iVar2 = *piVar3;
      }
      *(int *)(iVar1 + 0x14) = param_2;
      param_1[1] = param_1[1] + 1;
    }
  }
  return;
}



/* 401073ac FUN_401073ac */

undefined4 * FUN_401073ac(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  param_1[0x401] = 0;
  param_1[0x402] = 0;
  param_1[0x403] = 0;
  puVar1 = param_1;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x400);
  return param_1;
}



/* 401073dc FUN_401073dc */

/* Boundary evidence: original MIPS .pdata 401073dc..4010742b. Semantic name remains unreviewed. */

bool FUN_401073dc(int param_1,int param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = HeapCreate(0,param_2 * 0x18,0);
  *(HANDLE *)(param_1 + 0x1000) = pvVar1;
  return pvVar1 != (HANDLE)0x0;
}



/* 4010742c FUN_4010742c */

/* Boundary evidence: original MIPS .pdata 4010742c..4010749b. Semantic name remains unreviewed. */

void FUN_4010742c(undefined4 *param_1)

{
  LPVOID lpMem;
  LPVOID pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0x400;
  puVar2 = param_1;
  do {
    lpMem = (LPVOID)*puVar2;
    while (lpMem != (LPVOID)0x0) {
      pvVar1 = *(LPVOID *)((int)lpMem + 0x14);
      HeapFree((HANDLE)param_1[0x400],0,lpMem);
      lpMem = pvVar1;
    }
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0);
  return;
}



/* 4010749c FUN_4010749c */

/* Boundary evidence: original MIPS .pdata 4010749c..401074c3. Semantic name remains unreviewed. */

void FUN_4010749c(int param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = HeapAlloc(*(HANDLE *)(param_1 + 0x1000),0,0x18);
  *(undefined4 *)((int)pvVar1 + 0x14) = 0;
  return;
}



/* 401074c4 FUN_401074c4 */

int FUN_401074c4(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x1008);
  while( true ) {
    if (0x3fe < uVar1) {
      return 0;
    }
    if (*(int *)(param_1 + 0x1004) != 0) break;
    iVar2 = *(int *)(param_1 + 0x1008) + 1;
    *(int *)(param_1 + 0x1008) = iVar2;
    *(undefined4 *)(param_1 + 0x1004) = *(undefined4 *)(iVar2 * 4 + param_1);
    uVar1 = *(uint *)(param_1 + 0x1008);
  }
  iVar2 = *(int *)(param_1 + 0x1004);
  *(undefined4 *)(param_1 + 0x1004) = *(undefined4 *)(iVar2 + 0x14);
  return iVar2;
}



/* 40107528 FUN_40107528 */

/* Boundary evidence: original MIPS .pdata 40107528..40107587. Semantic name remains unreviewed. */

void FUN_40107528(int *param_1,int param_2)

{
  int iVar1;
  
  while (*param_1 != 0) {
    iVar1 = *(int *)(*param_1 + 0x14);
    HeapFree(*(HANDLE *)(param_2 + 0x1000),0,(LPVOID)*param_1);
    *param_1 = iVar1;
  }
  param_1[1] = 0;
  return;
}



/* 40107588 FUN_40107588 */

uint * FUN_40107588(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)((param_2 & 0x3ff) * 4 + param_1);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      return (uint *)0x0;
    }
    if (*puVar1 == param_2) break;
    puVar1 = (uint *)puVar1[5];
  }
  return puVar1;
}



/* 401075c4 FUN_401075c4 */

void FUN_401075c4(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 != (uint *)0x0) {
    piVar3 = (int *)((*param_2 & 0x3ff) * 4 + param_1);
    iVar2 = *piVar3;
    if ((param_2[4] & 0x7fffffff) == 0xfffffff) {
      *(int *)(param_1 + 0x100c) = *(int *)(param_1 + 0x100c) + 1;
    }
    param_2[5] = 0;
    if (iVar2 == 0) {
      *piVar3 = (int)param_2;
    }
    else {
      piVar3 = (int *)(iVar2 + 0x14);
      iVar1 = *piVar3;
      while (iVar1 != 0) {
        iVar2 = *piVar3;
        piVar3 = (int *)(iVar2 + 0x14);
        iVar1 = *piVar3;
      }
      *(uint **)(iVar2 + 0x14) = param_2;
    }
  }
  return;
}



/* 40107648 FUN_40107648 */

/* Boundary evidence: original MIPS .pdata 40107648..401076af. Semantic name remains unreviewed. */

void FUN_40107648(int param_1,undefined4 *param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  if (param_2[1] != 0) {
    puVar1 = (uint *)*param_2;
    while (puVar1 != (uint *)0x0) {
      puVar2 = (uint *)puVar1[5];
      FUN_401075c4(param_1,puVar1);
      puVar1 = puVar2;
    }
  }
  *param_2 = 0;
  param_2[1] = 0;
  return;
}



/* 401076b0 FUN_401076b0 */

uint * FUN_401076b0(int param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = (uint *)((param_2 & 0x3ff) * 4 + param_1);
  while( true ) {
    puVar1 = (uint *)*puVar2;
    if (puVar1 == (uint *)0x0) {
      return (uint *)0x0;
    }
    if (*puVar1 == param_2) break;
    puVar2 = puVar1 + 5;
  }
  *puVar2 = puVar1[5];
  if ((puVar1[4] & 0x7fffffff) != 0xfffffff) {
    return puVar1;
  }
  *(int *)(param_1 + 0x100c) = *(int *)(param_1 + 0x100c) + -1;
  return puVar1;
}



/* 40107720 FUN_40107720 */

void FUN_40107720(undefined4 *param_1,undefined4 param_2,int param_3)

{
  param_1[6] = param_2;
  param_1[9] = param_3;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[7] = 1;
  param_1[8] = 0;
  if (param_3 == 0) {
    param_1[6] = 0;
  }
  return;
}



/* 4010775c FUN_4010775c */

/* Boundary evidence: original MIPS .pdata 4010775c..401078c3. Semantic name remains unreviewed. */

int FUN_4010775c(int param_1,int param_2)

{
  UINT uID;
  int iVar1;
  WCHAR aWStack_240 [12];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_4010e38c;
  iVar1 = 1;
  if (param_2 == 1) {
    LoadStringW(DAT_4010e398,0xc1f,aWStack_228,0x104);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  else {
    if (param_2 == 2) {
      uID = 0xc20;
    }
    else {
      if (param_2 != 4) {
        if (param_2 == 8) {
          LoadStringW(DAT_4010e398,0xc22,aWStack_228,0x104);
          *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
        }
        else if (param_2 == 0x10) {
          LoadStringW(DAT_4010e398,0xc23,aWStack_228,0x104);
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        }
        goto LAB_40107858;
      }
      uID = 0xc21;
    }
    LoadStringW(DAT_4010e398,uID,aWStack_228,0x104);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  }
LAB_40107858:
  if (*(int *)(param_1 + 0x18) != 0) {
    LoadStringW(DAT_4010e398,0xd4a,aWStack_240,10);
    iVar1 = (**(code **)(param_1 + 0x24))(aWStack_228,aWStack_240,1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x20) = 1;
    }
  }
  FUN_4010d048(local_20);
  return iVar1;
}



/* 401078c4 FUN_401078c4 */

/* Boundary evidence: original MIPS .pdata 401078c4..40107b37. Semantic name remains unreviewed. */

void FUN_401078c4(int param_1)

{
  HANDLE pvVar1;
  STRSAFE_LPWSTR pszDest;
  int iVar2;
  HRESULT HVar3;
  UINT uID;
  wchar_t awStack_2e8 [100];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_4010e38c;
  if (*(int *)(param_1 + 0x24) != 0) {
    pvVar1 = GetProcessHeap();
    pszDest = HeapAlloc(pvVar1,0,1000);
    if (pszDest != (STRSAFE_LPWSTR)0x0) {
      LoadStringW(DAT_4010e398,0xc24,aWStack_220,0x104);
      StringCchCopyW(pszDest,500,aWStack_220);
      uID = 0xc25;
      if (*(int *)(param_1 + 0x1c) == 0) {
        uID = 0xc26;
      }
      LoadStringW(DAT_4010e398,uID,aWStack_220,0x104);
      StringCchCatW(pszDest,500,aWStack_220);
      iVar2 = LoadStringW(DAT_4010e398,0xc27,aWStack_220,0x104);
      if ((iVar2 != 0) &&
         (HVar3 = StringCbPrintfW(awStack_2e8,200,aWStack_220,*(undefined4 *)(param_1 + 0x14)),
         -1 < HVar3)) {
        StringCchCatW(pszDest,500,awStack_2e8);
      }
      iVar2 = LoadStringW(DAT_4010e398,0xc28,aWStack_220,0x104);
      if ((iVar2 != 0) &&
         (HVar3 = StringCbPrintfW(awStack_2e8,200,aWStack_220,*(undefined4 *)(param_1 + 0xc)),
         -1 < HVar3)) {
        StringCchCatW(pszDest,500,awStack_2e8);
      }
      iVar2 = LoadStringW(DAT_4010e398,0xc29,aWStack_220,0x104);
      if ((iVar2 != 0) &&
         (HVar3 = StringCbPrintfW(awStack_2e8,200,aWStack_220,*(undefined4 *)(param_1 + 0x10)),
         -1 < HVar3)) {
        StringCchCatW(pszDest,500,awStack_2e8);
      }
      iVar2 = LoadStringW(DAT_4010e398,0xc2a,aWStack_220,0x104);
      if ((iVar2 != 0) &&
         (HVar3 = StringCbPrintfW(awStack_2e8,200,aWStack_220,*(undefined4 *)(param_1 + 4)),
         -1 < HVar3)) {
        StringCchCatW(pszDest,500,awStack_2e8);
      }
      iVar2 = LoadStringW(DAT_4010e398,0xc2b,aWStack_220,0x104);
      if ((iVar2 != 0) &&
         (HVar3 = StringCbPrintfW(awStack_2e8,200,aWStack_220,*(undefined4 *)(param_1 + 8)),
         -1 < HVar3)) {
        StringCchCatW(pszDest,500,awStack_2e8);
      }
      LoadStringW(DAT_4010e398,0xc2c,aWStack_220,0x104);
      (**(code **)(param_1 + 0x24))(pszDest,aWStack_220,0);
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pszDest);
    }
  }
  FUN_4010d048(local_18);
  return;
}



/* 40107b38 FUN_40107b38 */

void FUN_40107b38(int *param_1,int *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[1] + param_1[4] + param_1[3] + *param_1 + param_1[2];
  param_2[6] = param_1[5];
  param_2[7] = param_1[7];
  param_2[8] = param_1[8];
  return;
}



/* 40107ba4 FUN_40107ba4 */

/* Boundary evidence: original MIPS .pdata 40107ba4..40107bfb. Semantic name remains unreviewed. */

void FUN_40107ba4(undefined4 param_1,HANDLE param_2,DWORD param_3,LPVOID param_4,DWORD param_5,
                 LPVOID param_6,DWORD param_7,LPDWORD param_8,LPOVERLAPPED param_9)

{
  DeviceIoControl(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



/* 40107bfc FUN_40107bfc */

/* Boundary evidence: original MIPS .pdata 40107bfc..40107c93. Semantic name remains unreviewed. */

BOOL FUN_40107bfc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  BOOL BVar1;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  local_20 = 1;
  local_10 = param_1[1] * param_4;
  local_1c = 0x32;
  local_18 = 0;
  local_28 = param_2;
  local_24 = param_4;
  local_14 = param_3;
  BVar1 = DeviceIoControl((HANDLE)*param_1,3,&local_28,0x1c,(LPVOID)0x0,0,(LPDWORD)0x0,
                          (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    SetLastError(0x1d);
  }
  return BVar1;
}



/* 40107c94 FUN_40107c94 */

/* Boundary evidence: original MIPS .pdata 40107c94..40107d2b. Semantic name remains unreviewed. */

BOOL FUN_40107c94(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  BOOL BVar1;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  local_20 = 1;
  local_10 = param_1[1] * param_4;
  local_1c = 0x32;
  local_18 = 0;
  local_28 = param_2;
  local_24 = param_4;
  local_14 = param_3;
  BVar1 = DeviceIoControl((HANDLE)*param_1,2,&local_28,0x1c,(LPVOID)0x0,0,(LPDWORD)0x0,
                          (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    SetLastError(0x1e);
  }
  return BVar1;
}



/* 40107d2c FUN_40107d2c */

/* Boundary evidence: original MIPS .pdata 40107d2c..40107d73. Semantic name remains unreviewed. */

BOOL FUN_40107d2c(undefined4 *param_1,int param_2,undefined4 param_3)

{
  BOOL BVar1;
  int iVar2;
  
  if (param_1[2] == 0) {
    BVar1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1[2] + 0x28);
    BVar1 = FUN_40107bfc(param_1,(param_2 + -2) * iVar2 + *(int *)(param_1[2] + 0x18),param_3,iVar2)
    ;
  }
  return BVar1;
}



/* 40107d74 FUN_40107d74 */

/* Boundary evidence: original MIPS .pdata 40107d74..40107dbb. Semantic name remains unreviewed. */

BOOL FUN_40107d74(undefined4 *param_1,int param_2,undefined4 param_3)

{
  BOOL BVar1;
  int iVar2;
  
  if (param_1[2] == 0) {
    BVar1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1[2] + 0x28);
    BVar1 = FUN_40107c94(param_1,(param_2 + -2) * iVar2 + *(int *)(param_1[2] + 0x18),param_3,iVar2)
    ;
  }
  return BVar1;
}



/* 40107dbc FUN_40107dbc */

/* Boundary evidence: original MIPS .pdata 40107dbc..40107e77. Semantic name remains unreviewed. */

undefined4 FUN_40107dbc(undefined4 *param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  BOOL BVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = 0;
  uVar4 = 1;
  if (param_3 != 0) {
    do {
      iVar3 = param_5;
      if (param_3 < uVar2 + param_5) {
        iVar3 = param_3 - uVar2;
      }
      BVar1 = FUN_40107bfc(param_1,uVar2 + param_2,param_4,iVar3);
      if (BVar1 == 0) {
        uVar4 = 0;
      }
      uVar2 = iVar3 + uVar2;
    } while (uVar2 < param_3);
  }
  return uVar4;
}



/* 40107e78 FUN_40107e78 */

/* Boundary evidence: original MIPS .pdata 40107e78..40107f03. Semantic name remains unreviewed. */

void FUN_40107e78(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  BOOL BVar1;
  DWORD aDStack_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0xc;
  if ((param_1[3] & 1) != 0) {
    local_14 = param_2;
    local_10 = param_3;
    BVar1 = DeviceIoControl((HANDLE)*param_1,0x71c4c,&local_18,0xc,(LPVOID)0x0,0,aDStack_20,
                            (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      param_1[3] = param_1[3] & 0xfffffffe;
    }
  }
  return;
}



/* 40107f04 FUN_40107f04 */

/* Boundary evidence: original MIPS .pdata 40107f04..40107f5b. Semantic name remains unreviewed. */

void FUN_40107f04(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  DWORD aDStack_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0xc;
  local_14 = param_2;
  local_10 = param_3;
  DeviceIoControl((HANDLE)*param_1,0x71c64,&local_18,0xc,(LPVOID)0x0,0,aDStack_20,(LPOVERLAPPED)0x0)
  ;
  return;
}



/* 40107f5c FUN_40107f5c */

/* Boundary evidence: original MIPS .pdata 40107f5c..40107fa3. Semantic name remains unreviewed. */

void FUN_40107f5c(undefined4 *param_1)

{
  DWORD aDStack_10 [2];
  
  DeviceIoControl((HANDLE)*param_1,0x71c54,(LPVOID)0x0,0,(LPVOID)0x0,0,aDStack_10,(LPOVERLAPPED)0x0)
  ;
  return;
}



/* 40107fa4 FUN_40107fa4 */

/* Boundary evidence: original MIPS .pdata 40107fa4..4010800f. Semantic name remains unreviewed. */

bool FUN_40107fa4(undefined4 *param_1,int param_2)

{
  HANDLE hHeap;
  LPVOID pvVar1;
  int iVar2;
  
  param_1[2] = param_2;
  param_1[3] = 2;
  iVar2 = *(int *)(param_2 + 8);
  hHeap = GetProcessHeap();
  pvVar1 = HeapAlloc(hHeap,8,iVar2 + 9U >> 3);
  *param_1 = pvVar1;
  param_1[1] = 0;
  return pvVar1 != (LPVOID)0x0;
}



/* 40108010 FUN_40108010 */

undefined4 FUN_40108010(int *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if ((1 < param_2) && (param_2 <= *(uint *)(param_1[2] + 0xc))) {
    puVar1 = (uint *)((param_2 >> 5) * 4 + *param_1);
    uVar2 = 1 << (param_2 & 0x1f);
    if ((*puVar1 & uVar2) == 0) {
      param_1[1] = param_1[1] + 1;
      *puVar1 = *puVar1 | uVar2;
      return 1;
    }
  }
  return 0;
}



/* 40108084 FUN_40108084 */

undefined4 FUN_40108084(int *param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  
  if ((param_2 < 2) || (*(uint *)(param_1[2] + 0xc) < param_2)) {
    uVar1 = 0;
  }
  else {
    puVar2 = (uint *)((param_2 >> 5) * 4 + *param_1);
    uVar1 = 1;
    uVar3 = 1 << (param_2 & 0x1f);
    if ((*puVar2 & uVar3) != 0) {
      param_1[1] = param_1[1] + -1;
      *puVar2 = ~uVar3 & *puVar2;
    }
  }
  return uVar1;
}



/* 401080fc FUN_401080fc */

undefined4 FUN_401080fc(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((param_2 < 2) || (*(uint *)(param_1[2] + 0xc) < param_2)) ||
     (uVar1 = 1, (1 << (param_2 & 0x1f) & *(uint *)((param_2 >> 5) * 4 + *param_1)) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40108154 FUN_40108154 */

/* Boundary evidence: original MIPS .pdata 40108154..401081f7. Semantic name remains unreviewed. */

uint FUN_40108154(int *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(param_1[2] + 0xc);
  uVar4 = 2;
  bVar1 = uVar6 < 2;
  do {
    uVar5 = 0;
    uVar3 = uVar4;
    if (bVar1) {
      return 0xfffffffe;
    }
    while (iVar2 = FUN_401080fc(param_1,uVar3), iVar2 == 0) {
      uVar5 = uVar5 + 1;
      if (param_2 <= uVar5) {
        return uVar4;
      }
      uVar3 = uVar5 + uVar4;
    }
    uVar4 = uVar5 + uVar4 + 1;
    bVar1 = uVar6 < uVar4;
  } while( true );
}



/* 401081f8 FUN_401081f8 */

/* Boundary evidence: original MIPS .pdata 401081f8..40108237. Semantic name remains unreviewed. */

void FUN_401081f8(undefined4 *param_1)

{
  HANDLE hHeap;
  LPVOID lpMem;
  
  lpMem = (LPVOID)*param_1;
  if (lpMem != (LPVOID)0x0) {
    hHeap = GetProcessHeap();
    HeapFree(hHeap,0,lpMem);
  }
  return;
}



/* 40108238 FUN_40108238 */

/* Boundary evidence: original MIPS .pdata 40108238..401082bf. Semantic name remains unreviewed. */

undefined4
FUN_40108238(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5)

{
  LPVOID pvVar1;
  uint uVar2;
  
  param_1[4] = 2;
  param_1[2] = param_3;
  param_1[1] = param_2;
  param_1[3] = param_4;
  param_1[5] = param_5;
  uVar2 = *(uint *)(param_3 + 0x24);
  if ((uVar2 & 0x3ffffff) == uVar2) {
    pvVar1 = VirtualAlloc((LPVOID)0x0,uVar2 << 6,0x1000,4);
    *param_1 = pvVar1;
    param_1[6] = 0xffffffff;
    if (pvVar1 != (LPVOID)0x0) {
      return 1;
    }
  }
  return 0;
}



/* 401082c0 FUN_401082c0 */

/* Boundary evidence: original MIPS .pdata 401082c0..40108463. Semantic name remains unreviewed. */

undefined4 FUN_401082c0(int param_1)

{
  HANDLE pvVar1;
  LPVOID _Buf1;
  LPVOID _Buf2;
  BOOL BVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar5 = 1;
  if (*(int *)(iVar3 + 0x34) != 1) {
    uVar5 = 0;
    uVar6 = 0;
    pvVar1 = GetProcessHeap();
    _Buf1 = HeapAlloc(pvVar1,0,*(SIZE_T *)(iVar3 + 0x24));
    iVar3 = *(int *)(param_1 + 8);
    pvVar1 = GetProcessHeap();
    _Buf2 = HeapAlloc(pvVar1,0,*(SIZE_T *)(iVar3 + 0x24));
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(iVar3 + 0x30) != 0) {
      do {
        BVar2 = FUN_40107c94(*(undefined4 **)(param_1 + 4),*(int *)(iVar3 + 0x14) + uVar6,_Buf1,1);
        if (BVar2 == 0) goto LAB_40108400;
        uVar4 = 2;
        if (1 < *(uint *)(*(int *)(param_1 + 8) + 0x34)) {
          do {
            BVar2 = FUN_40107c94(*(undefined4 **)(param_1 + 4),
                                 *(int *)(*(int *)(param_1 + 8) + 0x30) * (uVar4 - 1) +
                                 *(int *)(*(int *)(param_1 + 8) + 0x14) + uVar6,_Buf2,1);
            if (BVar2 == 0) goto LAB_40108400;
            iVar7 = *(int *)(param_1 + 8);
            iVar3 = memcmp(_Buf1,_Buf2,*(size_t *)(iVar7 + 0x24));
            if (iVar3 != 0) goto LAB_40108400;
            uVar4 = uVar4 + 1;
          } while (uVar4 <= *(uint *)(iVar7 + 0x34));
        }
        iVar3 = *(int *)(param_1 + 8);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(iVar3 + 0x30));
    }
    uVar5 = 1;
LAB_40108400:
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,_Buf1);
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,_Buf2);
  }
  return uVar5;
}



/* 40108464 FUN_40108464 */

/* Boundary evidence: original MIPS .pdata 40108464..40108567. Semantic name remains unreviewed. */

undefined4 FUN_40108464(int *param_1)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = param_1[2];
  iVar2 = param_1[6];
  uVar5 = iVar2 * 0x40;
  uVar7 = *(uint *)(iVar6 + 0x14);
  if (*(uint *)(iVar6 + 0x14) < uVar5) {
    uVar7 = uVar5;
  }
  uVar5 = uVar5 + 0x40;
  if ((uint)(*(int *)(param_1[2] + 0x30) + *(int *)(param_1[2] + 0x14)) <= uVar5) {
    uVar5 = *(int *)(param_1[2] + 0x30) + *(int *)(param_1[2] + 0x14);
  }
  iVar4 = *(int *)(iVar6 + 0x24);
  iVar3 = *param_1;
  uVar8 = 0;
  if (*(int *)(iVar6 + 0x34) != 0) {
    do {
      BVar1 = FUN_40107bfc((undefined4 *)param_1[1],*(int *)(iVar6 + 0x30) * uVar8 + uVar7,
                           (uVar7 + iVar2 * -0x40) * iVar4 + iVar3,uVar5 - uVar7);
      if (BVar1 == 0) {
        return 0;
      }
      iVar6 = param_1[2];
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(iVar6 + 0x34));
  }
  return 1;
}



/* 40108568 FUN_40108568 */

/* Boundary evidence: original MIPS .pdata 40108568..40108593. Semantic name remains unreviewed. */

void FUN_40108568(undefined4 *param_1)

{
  if ((LPVOID)*param_1 != (LPVOID)0x0) {
    VirtualFree((LPVOID)*param_1,0,0x8000);
  }
  return;
}



/* 40108594 FUN_40108594 */

/* Boundary evidence: original MIPS .pdata 40108594..40108733. Semantic name remains unreviewed. */

int FUN_40108594(int *param_1,uint param_2,uint *param_3,uint *param_4,uint *param_5)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = *(int *)param_1[2];
  if (iVar2 == 0xc) {
    uVar4 = (param_2 >> 1) + param_2;
  }
  else {
    uVar4 = param_2 << 1;
    if (iVar2 != 0x10) {
      uVar4 = param_2 << 2;
    }
  }
  uVar3 = ((int *)param_1[2])[9];
  uVar5 = uVar4 / uVar3;
  if (uVar3 == 0) {
    trap(0x1c00);
  }
  *param_5 = uVar5;
  *param_3 = (param_1[3] + -1) * *(int *)(param_1[2] + 0x30) + *(int *)(param_1[2] + 0x14) + uVar5;
  if (*(uint *)(param_1[2] + 0x24) == 0) {
    trap(0x1c00);
  }
  *param_4 = uVar4 % *(uint *)(param_1[2] + 0x24);
  uVar4 = *param_3 >> 6;
  if (uVar4 != param_1[6]) {
    if (param_1[5] == 0) {
      param_1[6] = uVar4;
      uVar3 = 0;
      do {
        BVar1 = FUN_40107c94((undefined4 *)param_1[1],uVar3 + uVar4 * 0x40,
                             *(int *)(param_1[2] + 0x24) * uVar3 + *param_1,1);
        if (BVar1 == 0) {
          return 0;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x40);
    }
    else {
      if (param_1[6] != 0xffffffff) {
        FUN_40108464(param_1);
      }
      param_1[6] = *param_3 >> 6;
      memset((void *)*param_1,0,*(int *)(param_1[2] + 0x24) << 6);
    }
  }
  return (*param_3 & 0x3f) * *(int *)(param_1[2] + 0x24) + *param_1;
}



/* 40108734 FUN_40108734 */

/* Boundary evidence: original MIPS .pdata 40108734..4010882f. Semantic name remains unreviewed. */

uint FUN_40108734(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint local_20;
  uint local_1c;
  uint uStack_18;
  uint uStack_14;
  
  local_1c = 0;
  iVar1 = FUN_40108594(param_1,param_2,&uStack_14,&local_20,&uStack_18);
  if (iVar1 == 0) {
    local_1c = 0xfffffffe;
  }
  else {
    iVar2 = *(int *)param_1[2];
    if (iVar2 == 0xc) {
      local_1c = CONCAT22(local_1c._2_2_,*(ushort *)(local_20 + iVar1));
      if ((param_2 & 1) == 0) {
        local_1c = *(ushort *)(local_20 + iVar1) & 0xfff;
      }
      else {
        local_1c = local_1c >> 4;
      }
    }
    else if (iVar2 == 0x10) {
      local_1c = (uint)*(ushort *)(local_20 + iVar1);
    }
    else if (iVar2 == 0x20) {
      local_1c = *(uint *)(local_20 + iVar1) & 0xfffffff;
    }
    else {
      local_1c = *(uint *)(local_20 + iVar1);
    }
  }
  return local_1c;
}



/* 40108830 FUN_40108830 */

/* Boundary evidence: original MIPS .pdata 40108830..40108a3f. Semantic name remains unreviewed. */

undefined4 FUN_40108830(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  BOOL BVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  uint local_30;
  uint local_2c;
  uint auStack_28 [2];
  
  iVar1 = FUN_40108594(param_1,param_2,auStack_28,&local_30,&local_2c);
  if (iVar1 == 0) {
LAB_40108a10:
    uVar6 = 0;
  }
  else {
    iVar3 = *(int *)param_1[2];
    if (iVar3 == 0xc) {
      pbVar5 = (byte *)(local_30 + iVar1);
      if ((param_2 & 1) == 0) {
        uVar4 = param_3 & 0xfff;
        uVar7 = (pbVar5[1] & 0xf0) << 8;
      }
      else {
        uVar4 = (param_3 & 0xfff) << 4;
        uVar7 = *pbVar5 & 0xf;
      }
      *pbVar5 = (byte)(uVar7 | uVar4);
      pbVar5[1] = (byte)((uVar7 | uVar4) >> 8);
    }
    else if (iVar3 == 0x10) {
      *(short *)(local_30 + iVar1) = (short)param_3;
    }
    else if (iVar3 == 0x20) {
      uVar7 = *(uint *)(local_30 + iVar1);
      *(uint *)(local_30 + iVar1) = (uVar7 ^ param_3) & 0xfffffff ^ uVar7;
    }
    else {
      *(uint *)(local_30 + iVar1) = param_3;
    }
    uVar6 = 1;
    if ((param_1[5] == 0) && (uVar7 = 0, *(int *)(param_1[2] + 0x34) != 0)) {
      do {
        BVar2 = FUN_40107bfc((undefined4 *)param_1[1],
                             *(int *)(param_1[2] + 0x30) * uVar7 + *(int *)(param_1[2] + 0x14) +
                             local_2c,iVar1,1);
        if (BVar2 == 0) goto LAB_40108a10;
        if ((*(int *)param_1[2] == 0xc) && (local_30 == ((int *)param_1[2])[9] - 1U)) {
          iVar3 = param_1[2];
          BVar2 = FUN_40107bfc((undefined4 *)param_1[1],
                               *(int *)(iVar3 + 0x30) * uVar7 + *(int *)(iVar3 + 0x14) + local_2c +
                               1,*(int *)(iVar3 + 0x24) + iVar1,1);
          if (BVar2 == 0) goto LAB_40108a10;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(param_1[2] + 0x34));
    }
  }
  return uVar6;
}



/* 40108a40 FUN_40108a40 */

/* Boundary evidence: original MIPS .pdata 40108a40..40108aab. Semantic name remains unreviewed. */

int FUN_40108a40(int *param_1)

{
  uint uVar1;
  
  do {
    if (*(uint *)(param_1[2] + 0xc) < (uint)param_1[4]) {
      return -1;
    }
    uVar1 = param_1[4];
    param_1[4] = uVar1 + 1;
    uVar1 = FUN_40108734(param_1,uVar1);
  } while (uVar1 != 0);
  return param_1[4] + -1;
}



/* 40108aac FUN_40108aac */

/* Boundary evidence: original MIPS .pdata 40108aac..40108b37. Semantic name remains unreviewed. */

undefined4 FUN_40108aac(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_2 + param_3) - 1;
  do {
    if (uVar2 <= param_2) {
      iVar1 = FUN_40108830(param_1,uVar2,0xffffffff);
      if (iVar1 == 0) {
        return 0;
      }
      return 1;
    }
    iVar1 = FUN_40108830(param_1,param_2,param_2 + 1);
    param_2 = param_2 + 1;
  } while (iVar1 != 0);
  return 0;
}



/* 40108b38 FUN_40108b38 */

/* Boundary evidence: original MIPS .pdata 40108b38..40108cdb. Semantic name remains unreviewed. */

undefined4 FUN_40108b38(int *param_1)

{
  HANDLE pvVar1;
  LPVOID lpMem;
  uint uVar2;
  BOOL BVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar6 = param_1[2];
  uVar7 = 0;
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,*(SIZE_T *)(iVar6 + 0x24));
  if (lpMem == (LPVOID)0x0) {
    return 0;
  }
  uVar2 = FUN_40108734(param_1,1);
  if (uVar2 == 0) {
    *(undefined4 *)(param_1[2] + 0x3c) = 2;
    param_1[6] = -1;
  }
  iVar4 = param_1[2];
  iVar6 = *(int *)(iVar4 + 0x30);
  if (*(int *)(iVar4 + 0x3c) == 1) {
    iVar5 = *(int *)(iVar4 + 0x14);
    iVar4 = iVar6 + iVar5;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x14);
    iVar5 = iVar4 + iVar6;
  }
  iVar6 = iVar6 + -1;
  if (-1 < iVar6) {
    iVar8 = iVar6 + iVar4;
    do {
      BVar3 = FUN_40107c94((undefined4 *)param_1[1],(iVar5 - iVar4) + iVar8,lpMem,1);
      if ((BVar3 == 0) || (BVar3 = FUN_40107bfc((undefined4 *)param_1[1],iVar8,lpMem,1), BVar3 == 0)
         ) goto LAB_40108c94;
      iVar6 = iVar6 + -1;
      iVar8 = iVar8 + -1;
    } while (-1 < iVar6);
  }
  if (*(int *)(param_1[2] + 0x3c) == 2) {
    BVar3 = FUN_40107c94((undefined4 *)param_1[1],0,lpMem,1);
    if (BVar3 == 0) goto LAB_40108c94;
    *(undefined1 *)((int)lpMem + 0x10) = 2;
    BVar3 = FUN_40107bfc((undefined4 *)param_1[1],0,lpMem,1);
    if (BVar3 == 0) goto LAB_40108c94;
    *(undefined4 *)(param_1[2] + 0x3c) = 1;
  }
  uVar7 = 1;
LAB_40108c94:
  pvVar1 = GetProcessHeap();
  HeapFree(pvVar1,0,lpMem);
  return uVar7;
}



/* 40108cdc FUN_40108cdc */

/* Boundary evidence: original MIPS .pdata 40108cdc..40108dcf. Semantic name remains unreviewed. */

void FUN_40108cdc(HWND param_1)

{
  HDC hdc;
  int iVar1;
  int iVar2;
  tagRECT local_28;
  
  local_28.left = 0;
  memset(&local_28.top,0,0xc);
  hdc = GetDC(param_1);
  if (hdc != (HDC)0x0) {
    iVar1 = GetDeviceCaps(hdc,8);
    iVar2 = GetDeviceCaps(hdc,10);
    GetWindowRect(param_1,&local_28);
    iVar2 = (local_28.top - local_28.bottom) + iVar2;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 1;
    }
    iVar1 = (iVar1 - local_28.right) + local_28.left;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 1;
    }
    MoveWindow(param_1,iVar1 >> 1,iVar2 >> 1,local_28.right - local_28.left,
               local_28.bottom - local_28.top,1);
    ReleaseDC(param_1,hdc);
  }
  return;
}



/* 40108dd0 FUN_40108dd0 */

/* Boundary evidence: original MIPS .pdata 40108dd0..40108dfb. Semantic name remains unreviewed. */

void FUN_40108dd0(WPARAM param_1)

{
  SendMessageW(DAT_4010ebcc,0x402,param_1,0);
  return;
}



/* 40108dfc FUN_40108dfc */

/* Boundary evidence: original MIPS .pdata 40108dfc..40108e8f. Semantic name remains unreviewed. */

undefined4 FUN_40108dfc(LPCWSTR param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == 0) {
    iVar1 = MessageBoxW(DAT_4010ebc8,param_1,param_2,0);
    uVar2 = 1;
    if (iVar1 == 1) goto LAB_40108e70;
  }
  else {
    iVar1 = MessageBoxW(DAT_4010ebc8,param_1,param_2,4);
    if (iVar1 == 6) {
      uVar2 = 1;
      goto LAB_40108e70;
    }
  }
  uVar2 = 0;
LAB_40108e70:
  UpdateWindow(DAT_4010ebc8);
  return uVar2;
}



/* 40108e90 FUN_40108e90 */

/* Boundary evidence: original MIPS .pdata 40108e90..40108f1f. Semantic name remains unreviewed. */

void FUN_40108e90(UINT param_1,UINT param_2,int param_3)

{
  LoadStringW(DAT_4010e398,param_1,(LPWSTR)&DAT_4010ebe4,0x104);
  LoadStringW(DAT_4010e398,param_2,(LPWSTR)&DAT_4010ebd0,10);
  FUN_40108dfc((LPCWSTR)&DAT_4010ebe4,(LPCWSTR)&DAT_4010ebd0,param_3);
  return;
}



/* 40108f20 FUN_40108f20 */

void FUN_40108f20(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      if (((uVar2 != 0x6a) && (uVar2 != 0x6b)) && (uVar2 != 0x70)) {
        iVar3 = -0x80000000;
        if ((uVar1 & 1) == 0) {
          iVar3 = 0;
        }
        uVar1 = (uint)*(byte *)(uVar2 + param_1) + (uVar1 >> 1) + iVar3;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}



/* 40108f8c FUN_40108f8c */

undefined1 FUN_40108f8c(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  puVar2 = &DAT_4010e364;
  iVar3 = 0;
  uVar1 = DAT_4010e364;
  while (uVar1 < param_1) {
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
    uVar1 = *puVar2;
  }
  return (&DAT_4010e368)[iVar3 * 8];
}



/* 40108fd4 FUN_40108fd4 */

/* Boundary evidence: original MIPS .pdata 40108fd4..4010904b. Semantic name remains unreviewed. */

undefined4 FUN_40108fd4(wint_t *param_1,uint param_2)

{
  wint_t wVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (param_2 < 0x10000) {
    uVar2 = 0x7a;
  }
  else {
    uVar3 = 0;
    do {
      wVar1 = towupper((wint_t)uVar3);
      uVar3 = uVar3 + 1;
      *param_1 = wVar1;
      param_1 = param_1 + 1;
    } while (uVar3 < 0x10000);
  }
  return uVar2;
}



/* 4010904c FUN_4010904c */

/* Boundary evidence: original MIPS .pdata 4010904c..40109193. Semantic name remains unreviewed. */

undefined4 FUN_4010904c(ushort *param_1,uint param_2,int param_3,uint param_4,uint *param_5)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  ushort *puVar8;
  
  uVar7 = 0xffffffff;
  uVar2 = 0;
  uVar5 = 0;
  uVar3 = uVar7;
  puVar8 = param_1;
  do {
    uVar4 = uVar3;
    if ((param_2 <= uVar5) || (*puVar8 != uVar5)) {
      if (uVar3 != 0xffffffff) {
        uVar4 = uVar7;
        if (uVar5 - uVar3 < 0x20) {
          if (uVar3 < uVar5) {
            puVar1 = (ushort *)(uVar2 * 2 + param_3);
            puVar6 = param_1 + uVar3;
            do {
              if (param_4 <= uVar2) {
                return 0x7a;
              }
              uVar3 = uVar3 + 1;
              *puVar1 = *puVar6;
              uVar2 = uVar2 + 1;
              puVar1 = puVar1 + 1;
              puVar6 = puVar6 + 1;
            } while (uVar3 < uVar5);
          }
        }
        else {
          if (param_4 - 1 <= uVar2) {
            return 0x7a;
          }
          *(undefined2 *)(uVar2 * 2 + param_3) = 0xffff;
          *(short *)((uVar2 + 1) * 2 + param_3) = (short)(uVar5 - uVar3);
          uVar2 = uVar2 + 2;
        }
      }
      if (param_2 > uVar5) {
        if (param_4 <= uVar2) {
          return 0x7a;
        }
        *(ushort *)(uVar2 * 2 + param_3) = *puVar8;
        uVar2 = uVar2 + 1;
      }
    }
    else if (uVar3 == 0xffffffff) {
      uVar4 = uVar5;
    }
    uVar5 = uVar5 + 1;
    puVar8 = puVar8 + 1;
    uVar3 = uVar4;
  } while (uVar5 <= param_2);
  if (param_5 != (uint *)0x0) {
    *param_5 = uVar2;
  }
  return 0;
}



/* 40109194 FUN_40109194 */

/* Boundary evidence: original MIPS .pdata 40109194..401097e7. Semantic name remains unreviewed. */

undefined4
FUN_40109194(int param_1,undefined1 *param_2,int param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  void *pvVar2;
  BOOL BVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  void *pvVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  void *_Dst;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  wint_t *local_54;
  undefined4 local_50;
  void *local_4c;
  int local_48 [8];
  
  uVar10 = *(uint *)(param_1 + 0x24);
  local_60 = *(uint *)(param_1 + 0x28);
  uVar11 = *(uint *)(param_1 + 0x2c);
  iVar12 = *(int *)(param_1 + 0x18);
  _Dst = (void *)0x0;
  local_50 = 0;
  local_5c = param_1;
  memset(param_2,0,uVar10);
  local_48[0] = 0;
  FUN_40108238(local_48,param_4,param_1,1,1);
  uVar7 = *(int *)(param_1 + 8) + 7U >> 3;
  local_68 = ((uVar7 + uVar11) - 1) / uVar11;
  if (uVar11 == 0) {
    trap(0x1c00);
  }
  *(undefined4 *)(param_2 + 0x14) = 3;
  local_64 = local_68 + 3;
  *param_2 = 0x81;
  *(uint *)(param_2 + 0x18) = uVar7;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  puVar9 = param_2 + 0x20;
  if (*(int *)(param_1 + 0x34) == 2) {
    *(uint *)(param_2 + 0x34) = local_64;
    local_64 = local_68 + local_64;
    *puVar9 = 0x81;
    param_2[0x21] = param_2[0x21] | 1;
    *(uint *)(param_2 + 0x38) = uVar7;
    *(undefined4 *)(param_2 + 0x3c) = 0;
    puVar9 = param_2 + 0x40;
  }
  local_54 = operator_new(0x20000);
  pvVar2 = local_4c;
  if (local_54 == (wint_t *)0x0) goto LAB_4010978c;
  iVar1 = FUN_40108fd4(local_54,0x10000);
  pvVar2 = local_4c;
  if ((iVar1 == 0) && (pvVar2 = operator_new(0x20000), pvVar2 != (void *)0x0)) {
    local_6c = 0;
    iVar1 = FUN_4010904c(local_54,0x10000,(int)pvVar2,0x10000,&local_6c);
    uVar7 = local_60;
    if (iVar1 == 0) {
      local_4c = (void *)(local_6c * 2);
      local_58 = ((int)local_4c + (uVar11 - 1)) / uVar11;
      if (uVar11 == 0) {
        trap(0x1c00);
      }
      uVar11 = 0;
      pvVar8 = (void *)0x0;
      *puVar9 = 0x82;
      *(uint *)(puVar9 + 0x14) = local_64;
      *(void **)(puVar9 + 0x18) = local_4c;
      *(undefined4 *)(puVar9 + 0x1c) = 0;
      if (local_4c != (void *)0x0) {
        do {
          iVar1 = -0x80000000;
          if ((uVar11 & 1) == 0) {
            iVar1 = 0;
          }
          pbVar5 = (byte *)((int)pvVar8 + (int)pvVar2);
          pvVar8 = (void *)((int)pvVar8 + 1);
          uVar11 = (uint)*pbVar5 + (uVar11 >> 1) + iVar1;
        } while (pvVar8 < local_4c);
      }
      *(uint *)(puVar9 + 4) = uVar11;
      puVar9[0x20] = 0x83;
      puVar9[0x21] = 0;
      puVar9 = puVar9 + 0x40;
      if (*(int *)(param_1 + 0x34) == 2) {
        for (; puVar9 < param_2 + uVar10; puVar9 = puVar9 + 0x20) {
          *puVar9 = 0xa1;
        }
      }
      uVar11 = 0;
      if (local_60 != 0) {
        do {
          BVar3 = FUN_40107bfc(param_4,iVar12,param_2,1);
          if (BVar3 == 0) goto LAB_40109774;
          if ((uVar11 == 0) && (memset(param_2,0,uVar10), *(int *)(param_1 + 0x34) == 2)) {
            for (puVar9 = param_2; puVar9 < param_2 + uVar10; puVar9 = puVar9 + 0x20) {
              *puVar9 = 0xa1;
            }
          }
          uVar11 = uVar11 + 1;
          iVar12 = iVar12 + 1;
        } while (uVar11 < uVar7);
      }
      uVar7 = local_68 * *(int *)(param_1 + 0x34) + local_58 + 1;
      uVar11 = (uVar7 >> 3) / uVar10;
      if (uVar10 == 0) {
        trap(0x1c00);
      }
      local_6c = uVar10 * param_3;
      memset(param_2,0xff,local_6c);
      iVar1 = FUN_40107dbc(param_4,iVar12,uVar11,param_2,param_3);
      if (iVar1 != 0) {
        iVar12 = uVar11 + iVar12;
        uVar7 = uVar7 + uVar11 * uVar10 * -8;
        if (uVar7 == 0) {
LAB_40109574:
          uVar4 = local_68 * local_60 - uVar11;
          if (uVar7 != 0) {
            uVar4 = uVar4 - 1;
          }
          memset(param_2,0,local_6c);
          iVar1 = FUN_40107dbc(param_4,iVar12,uVar4,param_2,param_3);
          if (iVar1 != 0) {
            iVar12 = uVar4 + iVar12;
            if (*(int *)(local_5c + 0x34) == 2) {
              memset(param_2,0xff,local_6c);
              iVar1 = FUN_40107dbc(param_4,iVar12,uVar11,param_2,param_3);
              if (iVar1 != 0) {
                iVar12 = uVar11 + iVar12;
                if (uVar7 != 0) {
                  BVar3 = FUN_40107bfc(param_4,iVar12,_Dst,1);
                  if (BVar3 == 0) goto LAB_40109774;
                  iVar12 = iVar12 + 1;
                }
                memset(param_2,0,local_6c);
                iVar1 = FUN_40107dbc(param_4,iVar12,uVar4,param_2,param_3);
                if (iVar1 != 0) {
                  iVar12 = uVar4 + iVar12;
                  goto LAB_40109674;
                }
              }
            }
            else {
LAB_40109674:
              uVar7 = ((int)local_4c + (uVar10 - 1)) / uVar10;
              if (uVar10 == 0) {
                trap(0x1c00);
              }
              BVar3 = FUN_40107bfc(param_4,iVar12,pvVar2,uVar7);
              if (BVar3 != 0) {
                uVar10 = 0;
                do {
                  iVar1 = FUN_40108830(local_48,uVar10,0xffffffff);
                  uVar11 = local_68;
                  if (iVar1 == 0) goto LAB_40109774;
                  uVar10 = uVar10 + 1;
                } while (uVar10 < 3);
                iVar1 = FUN_40108aac(local_48,3,local_68);
                if (((iVar1 != 0) &&
                    (((*(int *)(local_5c + 0x34) != 2 ||
                      (iVar1 = FUN_40108aac(local_48,uVar11 + 3,uVar11), iVar1 != 0)) &&
                     (iVar1 = FUN_40108aac(local_48,local_64,local_58), iVar1 != 0)))) &&
                   (iVar1 = FUN_40108464(local_48), iVar1 != 0)) {
                  if (param_5 != (int *)0x0) {
                    *param_5 = uVar7 + iVar12;
                  }
                  local_50 = 1;
                }
              }
            }
          }
        }
        else {
          _Dst = operator_new(uVar10);
          if (_Dst != (void *)0x0) {
            memset(_Dst,0,uVar10);
            uVar4 = 0;
            if (uVar7 != 0) {
              do {
                pbVar5 = (byte *)((uVar4 >> 3) + (int)_Dst);
                uVar6 = uVar4 & 7;
                uVar4 = uVar4 + 1;
                *pbVar5 = (byte)(1 << uVar6) | *pbVar5;
              } while (uVar4 < uVar7);
            }
            BVar3 = FUN_40107bfc(param_4,iVar12,_Dst,1);
            if (BVar3 != 0) {
              iVar12 = iVar12 + 1;
              goto LAB_40109574;
            }
          }
        }
      }
    }
  }
LAB_40109774:
  operator_delete(local_54);
LAB_4010978c:
  if (pvVar2 != (void *)0x0) {
    operator_delete(pvVar2);
  }
  if (_Dst != (void *)0x0) {
    operator_delete(_Dst);
  }
  FUN_40108568(local_48);
  return local_50;
}



/* 401097e8 FUN_401097e8 */

/* Boundary evidence: original MIPS .pdata 401097e8..4010a14b. Semantic name remains unreviewed. */

undefined4
FUN_401097e8(HANDLE param_1,uint *param_2,undefined *param_3,undefined *param_4,uint *param_5)

{
  undefined1 *puVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *_Dst;
  undefined1 *_Src;
  undefined3 extraout_var;
  BOOL BVar5;
  UINT UVar6;
  char cVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_228;
  int local_224;
  uint local_220;
  uint local_21c;
  undefined *local_218;
  uint *local_214;
  uint local_210;
  HANDLE local_208;
  uint local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  int local_1f8;
  uint local_1f4;
  uint local_1f0;
  _SYSTEMTIME local_1e8;
  uint local_1d8;
  DWORD DStack_1d4;
  undefined4 local_1d0;
  uint local_1cc;
  uint local_1c8;
  int local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  int local_1b8;
  undefined4 local_1b0;
  int local_1ac;
  uint local_1a8;
  int local_1a4;
  undefined4 local_1a0;
  uint local_19c;
  undefined4 local_198;
  undefined4 local_194;
  uint local_188;
  uint local_184;
  uint local_16c;
  uint local_168;
  uint local_164;
  undefined4 local_158 [72];
  uint local_38;
  uint local_30;
  
  local_30 = DAT_4010e38c;
  uVar11 = 0x1f;
  local_224 = 0;
  local_158[0] = 0x128;
  local_218 = param_3;
  if ((param_2 == (uint *)0x0) || ((param_2[4] & 4) == 0)) {
    iVar4 = GetPartitionInfo(param_1,local_158);
    if (iVar4 == 0) {
      FUN_401031ac(0xce5,param_4);
      goto LAB_4010a110;
    }
    if ((local_38 & 0x10) != 0) {
      FUN_401031ac(0xceb,param_4);
      FUN_4010d048(local_30);
      return 0x20;
    }
  }
  iVar4 = FUN_40107ba4(&local_208,param_1,1,&local_188,0x18,&local_188,0x18,&DStack_1d4,
                       (LPOVERLAPPED)0x0);
  if (iVar4 == 0) goto LAB_4010a110;
  if (param_2 == (uint *)0x0) {
    uVar13 = 0;
    uVar14 = 0;
    local_1f4 = local_168;
  }
  else {
    local_16c = param_2[1];
    local_1f4 = param_2[2];
    local_164 = param_2[3];
    uVar13 = *param_2;
    uVar14 = param_2[4];
  }
  local_228 = local_184 << 6;
  local_220 = local_188;
  local_210 = uVar14;
  if ((local_184 & 0x3ffffff) != local_184) goto LAB_4010a110;
  _Dst = VirtualAlloc((LPVOID)0x0,local_228,0x1000,4);
  if (_Dst == (undefined4 *)0x0) {
    FUN_4010d048(local_30);
    return 0xe;
  }
  _Src = LocalAlloc(0x40,local_184);
  if (_Src == (undefined1 *)0x0) {
    uVar11 = 0xe;
  }
  else {
    local_1fc = 1;
    bVar2 = false;
    local_204 = local_184;
    local_200 = 0;
    local_208 = param_1;
    if (((uVar14 & 8) != 0) || (iVar4 = FUN_40103318(&local_208), iVar4 != 0)) {
      iVar4 = FUN_40107f04(&local_208,0,local_188);
      if (iVar4 == 0) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    _Src[1] = 0x76;
    *_Src = 0xeb;
    _Src[2] = 0x90;
    *(undefined4 *)(_Src + 3) = 0x41465845;
    cVar7 = -1;
    *(undefined4 *)(_Src + 7) = 0x20202054;
    uVar14 = local_184;
    if ((local_184 - 1 & local_184) == 0) {
      for (; uVar14 != 0; uVar14 = uVar14 >> 1) {
        cVar7 = cVar7 + '\x01';
      }
    }
    _Src[0x6c] = cVar7;
    local_214 = (uint *)(local_210 & 2);
    uVar14 = 0x100000;
    if (local_214 == (uint *)0x0) {
      uVar14 = 0x10000000;
    }
    if (((uVar13 == 0) || ((uVar13 - 1 & uVar13) != 0)) || (uVar14 < uVar13)) {
      uVar3 = FUN_40108f8c(local_220);
      uVar13 = CONCAT31(extraout_var,uVar3);
    }
    else {
      uVar13 = uVar13 / local_184;
      if (local_184 == 0) {
        trap(0x1c00);
      }
    }
    uVar14 = local_220;
    if (uVar13 == 0) {
      UVar6 = 0xbba;
    }
    else {
      if ((uVar13 - 1 & uVar13) == 0) {
        iVar4 = -1;
        uVar10 = uVar13;
        do {
          uVar10 = uVar10 >> 1;
          iVar4 = iVar4 + 1;
        } while (uVar10 != 0);
        if (iVar4 != -1) {
          *(undefined4 *)(_Src + 0x50) = 0x20;
          _Src[0x6d] = (char)iVar4;
          local_21c = 2;
          if (local_214 == (uint *)0x0) {
            local_21c = 1;
          }
          _Src[0x6e] = (char)local_21c;
          puVar1 = _Src + 0x4f;
          uVar10 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar10) =
               *(uint *)(puVar1 + -uVar10) & -1 << (uVar10 + 1) * 8 | 0U >> (3 - uVar10) * 8;
          *(undefined4 *)(_Src + 0x40) = 0;
          *(undefined4 *)(_Src + 0x44) = 0;
          *(uint *)(_Src + 0x48) = local_220;
          puVar1 = _Src + 0x4c;
          uVar10 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar10) =
               *(uint *)(puVar1 + -uVar10) & 0xffffffffU >> (4 - uVar10) * 8 | 0 << uVar10 * 8;
          if (uVar13 == 0) {
            trap(0x1c00);
          }
          uVar10 = (((local_220 / uVar13) * 4 + local_184) - 1) / local_184;
          if (local_184 == 0) {
            trap(0x1c00);
          }
          _Src[0x69] = 1;
          *(uint *)(_Src + 0x54) = uVar10;
          _Src[0x68] = 0;
          *(undefined4 *)(_Src + 0x60) = 2;
          _Src[0x6f] = 0x80;
          _Src[0x70] = 0xff;
          local_220 = uVar10;
          GetSystemTime(&local_1e8);
          _Src[0x1fe] = 0x55;
          _Src[0x1ff] = 0xaa;
          *(uint *)(_Src + 100) =
               ((uint)local_1e8.wSecond + (uint)local_1e8.wHour + (uint)local_1e8.wDayOfWeek +
               (uint)local_1e8.wYear) * 0x10000 + (uint)local_1e8.wMilliseconds +
               (uint)local_1e8.wMinute + (uint)local_1e8.wDay + (uint)local_1e8.wMonth;
          iVar4 = uVar10 * local_21c + 0x20;
          *(int *)(_Src + 0x58) = iVar4;
          if (uVar13 == 0) {
            trap(0x1c00);
          }
          *(uint *)(_Src + 0x5c) = (uVar14 - iVar4) / uVar13;
          if ((bVar2) || ((local_210 & 1) != 0)) {
            DAT_4010e708 = uVar14;
          }
          else {
            DAT_4010e708 = iVar4 + uVar13;
          }
          local_214 = &DAT_4010e708;
          memset(_Dst,0,local_184 << 6);
          if (bVar2) {
            *_Dst = 0xa1b2c3d4;
          }
          BVar5 = FUN_40107bfc(&local_208,0,_Dst,1);
          if (BVar5 == 0) {
            FUN_401031ac(0xbbc,param_4);
            local_224 = 1;
            if (bVar2) goto LAB_40109cc0;
          }
          else {
LAB_40109cc0:
            if (bVar2) {
              FUN_40107f5c(&local_208);
            }
            memcpy(_Dst,_Src,local_184);
            uVar10 = 0;
            puVar12 = _Dst;
            do {
              puVar12 = (undefined4 *)(local_184 + (int)puVar12);
              if (uVar10 == 0) {
                *puVar12 = 0x69766152;
              }
              uVar10 = uVar10 + 1;
              puVar12[0x7f] = 0xaa550000;
            } while (uVar10 < 8);
            FUN_40107c94(&local_208,9,local_184 + (int)puVar12,1);
            puVar12 = (undefined4 *)(local_184 * 2 + local_184 + (int)puVar12);
            uVar11 = FUN_40108f20((int)_Dst,local_184 * 0xb);
            uVar10 = local_184 >> 2;
            if ((uVar10 != 0) && (uVar10 != 0)) {
              puVar8 = puVar12;
              do {
                *puVar8 = uVar11;
                puVar8 = puVar8 + 1;
              } while (puVar8 != puVar12 + uVar10);
            }
            memcpy((void *)(local_184 + (int)puVar12),_Dst,local_184 * 0xc);
            BVar5 = FUN_40107bfc(&local_208,1,(int)_Dst + local_184,0x1f);
            if (BVar5 == 0) {
              FUN_401031ac(0xbbc,param_4);
              local_224 = 1;
              if (!bVar2) goto LAB_4010a0dc;
            }
            FUN_40103138(0x1f,local_218);
            uVar10 = local_228;
            iVar4 = 0x20;
            local_1f8 = 0x20;
            memset(_Dst,0,local_228);
            local_1f0 = 0;
            uVar9 = local_220;
            if (local_21c != 0) {
              do {
                uVar10 = 0;
                if (uVar9 != 0) {
                  do {
                    iVar4 = 0x40;
                    if (uVar9 < uVar10 + 0x40) {
                      iVar4 = uVar9 - uVar10;
                    }
                    local_1d8 = uVar10 + local_1f8;
                    BVar5 = FUN_40107bfc(&local_208,local_1d8,_Dst,iVar4);
                    if (BVar5 == 0) {
                      FUN_401031ac(0xbbc,param_4);
                      local_224 = 1;
                      if (!bVar2) goto LAB_4010a0dc;
                    }
                    FUN_40103138(local_1d8,local_218);
                    uVar10 = iVar4 + uVar10;
                    uVar9 = local_220;
                    iVar4 = local_1f8;
                  } while (uVar10 < local_220);
                }
                local_1f0 = local_1f0 + 1;
                iVar4 = iVar4 + uVar9;
                uVar10 = local_228;
                local_1f8 = iVar4;
              } while (local_1f0 < local_21c);
            }
            local_1d0 = 0x40;
            local_1b8 = *(int *)(_Src + 0x58);
            local_1cc = *(int *)(_Src + 0x48) - local_1b8;
            local_1a8 = 1 << ((byte)_Src[0x6d] & 0x1f);
            local_1c8 = local_1cc / local_1a8;
            if (local_1a8 == 0) {
              trap(0x1c00);
            }
            local_1c4 = local_1c8 + 1;
            local_1c0 = 0;
            local_1bc = *(undefined4 *)(_Src + 0x50);
            local_1b0 = 0;
            local_228 = 0;
            local_1ac = 1 << ((byte)_Src[0x6c] & 0x1f);
            local_1a4 = local_1ac * local_1a8;
            local_1a0 = *(undefined4 *)(_Src + 0x54);
            local_19c = (uint)(byte)_Src[0x6e];
            local_198 = *(undefined4 *)(_Src + 0x60);
            local_194 = 0;
            iVar4 = FUN_40109194((int)&local_1d0,(undefined1 *)_Dst,0x40,&local_208,
                                 (int *)&local_228);
            uVar9 = local_228;
            if ((iVar4 != 0) || (local_224 = 1, bVar2)) {
              if ((bVar2) || ((local_210 & 1) != 0)) {
                memset(_Dst,0xff,uVar10);
                for (uVar10 = uVar9; uVar10 < uVar14; uVar10 = local_228 + uVar10) {
                  local_228 = 0x40;
                  if (uVar14 < uVar10 + 0x40) {
                    local_228 = uVar14 - uVar10;
                  }
                  BVar5 = FUN_40107bfc(&local_208,uVar10,_Dst,local_228);
                  if (BVar5 == 0) {
                    FUN_401031ac(0xbbc,param_4);
                    local_224 = 1;
                    if (!bVar2) goto LAB_4010a0dc;
                  }
                  FUN_40103138(uVar10,local_218);
                }
                if (bVar2) {
                  FUN_40107f5c(&local_208);
                }
              }
              BVar5 = FUN_40107bfc(&local_208,0,_Src,1);
              iVar4 = local_224;
              if (BVar5 == 0) {
                FUN_401031ac(0xbbc,param_4);
                iVar4 = 1;
                if (!bVar2) goto LAB_4010a0dc;
              }
              if (param_5 != (uint *)0x0) {
                *param_5 = local_220;
                param_5[1] = 0x20;
                param_5[2] = uVar13;
                param_5[3] = uVar13;
                param_5[4] = uVar14;
                param_5[5] = local_21c;
                param_5[6] = local_1f4;
              }
              FUN_40107e78(&local_208,uVar9,uVar14 - uVar9);
              FUN_40103138(*local_214,local_218);
              uVar11 = 0;
              if (iVar4 == 0) goto LAB_4010a0f0;
            }
          }
LAB_4010a0dc:
          uVar11 = 0x1d;
          goto LAB_4010a0f0;
        }
      }
      UVar6 = 0xbbb;
    }
    FUN_401031ac(UVar6,param_4);
  }
LAB_4010a0f0:
  VirtualFree(_Dst,0,0x8000);
  if (_Src != (undefined1 *)0x0) {
    LocalFree(_Src);
  }
LAB_4010a110:
  FUN_4010d048(local_30);
  return uVar11;
}



/* 4010a14c FUN_4010a14c */

void FUN_4010a14c(int param_1,uint param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = 0;
  uVar4 = 0;
  if (param_2 != 0) {
    do {
      iVar3 = 0x8000;
      if ((uVar1 & 1) == 0) {
        iVar3 = 0;
      }
      pbVar2 = (byte *)(uVar4 + param_1);
      uVar4 = uVar4 + 1;
      uVar1 = (uint)*pbVar2 + (uVar1 >> 1) + iVar3 & 0xffff;
    } while (uVar4 < param_2);
  }
  return;
}



/* 4010a19c FUN_4010a19c */

uint FUN_4010a19c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if ((param_2 == 0) || ((uVar2 != 2 && (uVar2 != 3)))) {
      iVar1 = 0x8000;
      if ((param_3 & 1) == 0) {
        iVar1 = 0;
      }
      param_3 = (uint)*(byte *)(uVar2 + param_1) + (param_3 >> 1) + iVar1 & 0xffff;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x20);
  return param_3;
}



/* 4010a208 FUN_4010a208 */

/* Boundary evidence: original MIPS .pdata 4010a208..4010a313. Semantic name remains unreviewed. */

void FUN_4010a208(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  
  pcVar3 = (code *)*param_1;
  if (pcVar3 == (code *)0x0) {
    return;
  }
  uVar4 = param_1[3];
  uVar5 = param_1[0x2f];
  uVar1 = __ull_div((int)((ulonglong)uVar4 * 100),(int)((ulonglong)uVar4 * 100 >> 0x20),uVar5,0);
  if (uVar4 == 0) {
    param_1[3] = uVar5 / 10;
  }
  else {
    if ((param_1[6] == 0) && (uVar1 < 0x32)) {
      iVar2 = uVar4 + 2;
    }
    else {
      if ((param_1[6] != 1) || (99 < uVar1)) goto LAB_4010a2b4;
      iVar2 = uVar4 + 1;
    }
    param_1[3] = iVar2;
  }
LAB_4010a2b4:
  uVar1 = __ull_div((int)((ulonglong)(uint)param_1[3] * 100),
                    (int)((ulonglong)(uint)param_1[3] * 100 >> 0x20),uVar5,0);
  if ((uVar1 != param_1[2]) && (uVar1 < 0x65)) {
    param_1[2] = uVar1;
    (*pcVar3)(uVar1);
  }
  return;
}



/* 4010a314 FUN_4010a314 */

/* Boundary evidence: original MIPS .pdata 4010a314..4010a3ab. Semantic name remains unreviewed. */

void FUN_4010a314(int param_1,UINT param_2,UINT param_3)

{
  if (*(int *)(param_1 + 4) != 0) {
    LoadStringW(DAT_4010e398,param_2,(LPWSTR)&DAT_4010ee00,0x104);
    LoadStringW(DAT_4010e398,param_3,(LPWSTR)&DAT_4010edec,10);
    (**(code **)(param_1 + 4))(&DAT_4010ee00,&DAT_4010edec,0);
  }
  return;
}



/* 4010a3ac FUN_4010a3ac */

/* Boundary evidence: original MIPS .pdata 4010a3ac..4010a3f3. Semantic name remains unreviewed. */

undefined4 FUN_4010a3ac(int param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(HANDLE *)(param_1 + 0x1c) != (HANDLE)0x0) &&
     (DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x1c),0), DVar1 == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* 4010a3f4 FUN_4010a3f4 */

/* Boundary evidence: original MIPS .pdata 4010a3f4..4010a497. Semantic name remains unreviewed. */

int FUN_4010a3f4(int param_1,int param_2)

{
  UINT UVar1;
  
  if (param_2 == 0) {
    param_2 = 0x1f;
  }
  if (param_2 == 0x1d) {
    UVar1 = 0xc2e;
  }
  else if (param_2 == 0x1e) {
    UVar1 = 0xc2d;
  }
  else if (param_2 == 0x70) {
    UVar1 = 0xc30;
  }
  else if (param_2 == 0x3ed) {
    UVar1 = 0xc2f;
  }
  else if (param_2 == 0x4c7) {
    UVar1 = 0xc31;
  }
  else {
    UVar1 = 0xc1d;
  }
  FUN_4010a314(param_1,UVar1,0xd4a);
  return param_2;
}



/* 4010a498 FUN_4010a498 */

undefined4 FUN_4010a498(undefined4 param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  *param_3 = 0x40;
  uVar1 = *(uint *)(param_2 + 0x58);
  param_3[6] = uVar1;
  uVar3 = *(uint *)(param_2 + 0x48);
  if (uVar1 < uVar3) {
    param_3[1] = uVar3 - uVar1;
    uVar2 = 1 << (*(byte *)(param_2 + 0x6d) & 0x1f);
    uVar1 = (uVar3 - uVar1) / uVar2;
    param_3[10] = uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    param_3[2] = uVar1;
    param_3[3] = uVar1 + 1;
    param_3[4] = 0;
    uVar1 = *(uint *)(param_2 + 0x50);
    param_3[5] = uVar1;
    if (uVar1 <= uVar3) {
      param_3[7] = 0;
      param_3[8] = 0;
      uVar1 = 1 << (*(byte *)(param_2 + 0x6c) & 0x1f);
      param_3[9] = uVar1;
      if (0x1ff < uVar1) {
        param_3[0xb] = uVar1 * param_3[10];
        iVar4 = *(int *)(param_2 + 0x54);
        param_3[0xc] = iVar4;
        if (iVar4 != 0) {
          param_3[0xd] = (uint)*(byte *)(param_2 + 0x6e);
          uVar1 = *(uint *)(param_2 + 0x60);
          param_3[0xe] = uVar1;
          if (uVar1 <= (uint)param_3[3]) {
            if ((*(byte *)(param_2 + 0x6a) & 2) != 0) {
              param_3[0x10] = param_3[0x10] | 1;
            }
            if (param_3[0xd] == 1) {
              param_3[0xf] = 0;
              return 1;
            }
            uVar5 = 2;
            if (param_3[0xd] == 2) {
              if ((*(byte *)(param_2 + 0x6a) & 1) != 1) {
                uVar5 = 1;
              }
              param_3[0xf] = uVar5;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}



/* 4010a608 FUN_4010a608 */

/* Boundary evidence: original MIPS .pdata 4010a608..4010a703. Semantic name remains unreviewed. */

undefined4 FUN_4010a608(int param_1)

{
  HANDLE pvVar1;
  LPVOID lpMem;
  BOOL BVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,*(SIZE_T *)(param_1 + 0xd8));
  if (lpMem == (LPVOID)0x0) {
    uVar5 = 8;
  }
  else {
    BVar2 = FUN_40107c94((undefined4 *)(param_1 + 0xa4),0,lpMem,1);
    if (BVar2 == 0) {
      uVar5 = 0x1e;
    }
    else {
      uVar4 = 0;
      do {
        if (*(char *)((int)lpMem + uVar4 + 0xb) != '\0') goto LAB_4010a6c8;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 0x35);
      memset((undefined4 *)(param_1 + 0xb4),0,0x44);
      iVar3 = FUN_4010a498(param_1,(int)lpMem,(undefined4 *)(param_1 + 0xb4));
      if (iVar3 == 0) {
LAB_4010a6c8:
        uVar5 = 0x3ed;
      }
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,lpMem);
  }
  return uVar5;
}



/* 4010a704 FUN_4010a704 */

/* Boundary evidence: original MIPS .pdata 4010a704..4010a7e7. Semantic name remains unreviewed. */

undefined4 FUN_4010a704(int param_1)

{
  HANDLE pvVar1;
  LPVOID lpMem;
  BOOL BVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,*(SIZE_T *)(param_1 + 0xd8));
  if (lpMem == (LPVOID)0x0) {
    uVar3 = 8;
  }
  else {
    BVar2 = FUN_40107c94((undefined4 *)(param_1 + 0xa4),0,lpMem,1);
    if (BVar2 == 0) {
      uVar3 = 0x1e;
    }
    else {
      *(byte *)((int)lpMem + 0x6a) = *(byte *)((int)lpMem + 0x6a) & 0xfd;
      *(undefined1 *)((int)lpMem + 0x6b) = *(undefined1 *)((int)lpMem + 0x6b);
      BVar2 = FUN_40107bfc((undefined4 *)(param_1 + 0xa4),0,lpMem,1);
      if (BVar2 == 0) {
        uVar3 = 0x1d;
      }
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,lpMem);
  }
  return uVar3;
}



/* 4010a7e8 FUN_4010a7e8 */

/* Boundary evidence: original MIPS .pdata 4010a7e8..4010a8af. Semantic name remains unreviewed. */

int FUN_4010a7e8(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (((param_3 & 1) != 0) && (iVar1 = 0, param_2 == 0)) {
    iVar1 = 1;
  }
  if ((param_3 & 2) != 0) {
    if (((iVar1 == 0) && (1 < param_2)) &&
       ((param_2 <= *(uint *)(param_1 + 0xc0) || (param_2 == 0xffffffff)))) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  if (((param_3 & 4) != 0) && ((iVar1 != 0 || (iVar1 = 0, param_2 == 0xffffffff)))) {
    iVar1 = 1;
  }
  if ((param_3 & 8) != 0) {
    if ((iVar1 == 0) && (iVar1 = FUN_401080fc((int *)(param_1 + 0x20),param_2), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}



/* 4010a8b0 FUN_4010a8b0 */

undefined4 FUN_4010a8b0(undefined4 param_1,short *param_2,ushort *param_3,undefined1 *param_4)

{
  ushort uVar1;
  
  uVar1 = (param_2[3] ^ param_3[1]) & 0x1f ^ param_3[1];
  param_3[1] = uVar1;
  uVar1 = (param_2[1] << 5 ^ uVar1) & 0x1e0 ^ uVar1;
  param_3[1] = uVar1;
  param_3[1] = (*param_2 + -0x3c) * 0x200 | uVar1 & 0x1ff;
  uVar1 = ((ushort)param_2[6] >> 1 ^ *param_3) & 0x1f ^ *param_3;
  *param_3 = uVar1;
  uVar1 = (param_2[5] << 5 ^ uVar1) & 0x7e0 ^ uVar1;
  *param_3 = uVar1;
  *param_3 = param_2[4] << 0xb | uVar1 & 0x7ff;
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = (char)((ushort)param_2[7] / 10);
  }
  return 1;
}



/* 4010a974 FUN_4010a974 */

/* Boundary evidence: original MIPS .pdata 4010a974..4010ad3b. Semantic name remains unreviewed. */

int FUN_4010a974(undefined4 *param_1,int param_2,uint param_3,undefined4 *param_4)

{
  ushort uVar1;
  undefined2 extraout_var;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  local_3c = 0;
  uVar6 = 0;
  uVar1 = FUN_4010c5bc(param_2);
  if ((CONCAT22(extraout_var,uVar1) != 0) &&
     (iVar2 = FUN_4010c3c8(param_2,&local_30,&local_40,&local_34), iVar2 != 0)) {
    if ((local_40 == 0xffffffff) || ((local_40 == 0 && (local_30 != 0 || local_2c != 0)))) {
      iVar2 = 1;
      if ((param_3 & 2) == 0) {
        iVar2 = 2;
      }
      iVar3 = FUN_4010775c((int)(param_1 + 0x4c),iVar2);
      FUN_4010c53c(param_2,iVar2,0,0,0);
      if ((param_4 != (undefined4 *)0x0) && (iVar3 != 0)) {
        *param_4 = 1;
      }
    }
    uVar5 = local_40;
    iVar3 = FUN_4010a7e8((int)param_1,local_40,0xe);
    iVar2 = 0;
    if (iVar3 == 0) {
      uVar7 = uVar6;
      do {
        uVar6 = uVar5;
        local_38 = 0;
        iVar2 = FUN_4010c19c((int)(param_1 + 0x10),uVar6,&local_38);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (local_38 == 0) {
          iVar2 = FUN_4010775c((int)(param_1 + 0x4c),8);
          if (iVar2 == 0) {
            return 0xd;
          }
          iVar2 = FUN_4010c0e4((int)(param_1 + 0x10),uVar6,1);
          if (iVar2 != 0) {
            param_1[0x54] = 1;
            return iVar2;
          }
        }
        if ((uVar7 != 0) && (uVar6 != uVar7 + 1)) {
          param_1[4] = param_1[4] + 1;
        }
        FUN_4010a208(param_1);
        FUN_40108010(param_1 + 8,uVar6);
        local_3c = local_3c + 1;
        if (local_34 == 0) {
          uVar5 = FUN_40108734(param_1 + 0x22,uVar6);
          if (uVar5 == 0xfffffffe) {
            return 0x1f;
          }
        }
        else if ((local_2c == 0) && (local_30 <= (uint)(param_1[0x38] * local_3c))) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = uVar6 + 1;
        }
        iVar3 = FUN_4010a7e8((int)param_1,uVar5,0xe);
        uVar7 = uVar6;
        iVar2 = local_3c;
      } while (iVar3 == 0);
    }
    if ((local_40 != 0) && (iVar3 = FUN_4010a7e8((int)param_1,uVar5,10), iVar3 != 0)) {
      iVar3 = 1;
      if ((param_3 & 2) == 0) {
        iVar3 = 2;
      }
      iVar3 = FUN_4010775c((int)(param_1 + 0x4c),iVar3);
      if ((iVar3 != 0) && (iVar3 = FUN_40108830(param_1 + 0x22,uVar6,0xffffffff), iVar3 == 0)) {
        param_1[0x54] = 1;
        return 0x1d;
      }
    }
    local_30 = param_1[0x38] + local_30;
    iVar3 = local_2c + (uint)(local_30 < (uint)param_1[0x38]) + -1 + (uint)(local_30 - 1 < local_30)
    ;
    uVar8 = __ull_div();
    if (((int)uVar8 != iVar2) || ((int)((ulonglong)uVar8 >> 0x20) != 0)) {
      if (((param_3 & 1) == 0) && (param_1[6] != 1)) {
        iVar3 = 2;
        if ((param_3 & 2) != 0) {
          iVar3 = 1;
        }
        iVar4 = FUN_4010775c((int)(param_1 + 0x4c),iVar3);
      }
      else {
        iVar4 = 0;
      }
      local_30 = param_1[0x38] * iVar2;
      local_2c = 0;
      FUN_4010c53c(param_2,iVar3,local_30,0,local_40);
      if ((param_4 != (undefined4 *)0x0) && (iVar4 != 0)) {
        *param_4 = 1;
      }
    }
  }
  return 0;
}



/* 4010ad3c FUN_4010ad3c */

/* Boundary evidence: original MIPS .pdata 4010ad3c..4010ae23. Semantic name remains unreviewed. */

void FUN_4010ad3c(int param_1,int *param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  byte local_38 [32];
  
  bVar1 = true;
  iVar2 = FUN_4010775c(param_1 + 0x130,1);
  while (((iVar3 = FUN_4010c644(param_2,param_3,local_38,0x20), iVar3 == 0 &&
          ((local_38[0] & 0x80) != 0)) && ((bVar1 || ((local_38[0] & 0x40) != 0))))) {
    if (iVar2 != 0) {
      local_38[0] = local_38[0] & 0x7f;
      iVar3 = FUN_4010c874(param_2,param_3,local_38,0x20);
      if (iVar3 != 0) break;
    }
    param_3 = param_3 + 0x20;
    bVar1 = false;
  }
  *param_4 = param_3;
  return;
}



/* 4010ae24 FUN_4010ae24 */

/* Boundary evidence: original MIPS .pdata 4010ae24..4010af6f. Semantic name remains unreviewed. */

int FUN_4010ae24(int param_1,int *param_2,uint param_3,char *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 uStack_60;
  byte local_5f;
  undefined2 local_5e;
  undefined1 auStack_40 [32];
  
  iVar4 = 0;
  if (*param_4 == -0x40) {
    iVar1 = FUN_4010775c(param_1 + 0x130,1);
    if ((iVar1 != 0) && (iVar4 = FUN_4010c644(param_2,param_3,&uStack_60,0x20), iVar4 == 0)) {
      uVar2 = FUN_4010a19c((int)&uStack_60,1,0);
      uVar3 = FUN_4010a19c((int)param_4,0,uVar2);
      uVar5 = param_3 + 0x40;
      uVar2 = (uint)local_5f;
      while (uVar2 = uVar2 - 1, uVar2 != 0) {
        iVar4 = FUN_4010c644(param_2,uVar5,auStack_40,0x20);
        if (iVar4 != 0) {
          return iVar4;
        }
        uVar3 = FUN_4010a19c((int)auStack_40,0,uVar3);
        uVar5 = uVar5 + 0x20;
      }
      local_5e = (undefined2)uVar3;
      iVar4 = FUN_4010c874(param_2,param_3,&uStack_60,0x20);
      if (iVar4 == 0) {
        iVar4 = FUN_4010c874(param_2,param_3 + 0x20,param_4,0x20);
      }
    }
  }
  else {
    iVar4 = 0x32;
  }
  return iVar4;
}



/* 4010af70 FUN_4010af70 */

/* Boundary evidence: original MIPS .pdata 4010af70..4010b06f. Semantic name remains unreviewed. */

int FUN_4010af70(undefined4 param_1,int *param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte local_40 [32];
  
  uVar3 = 0;
  uVar4 = 0;
  uVar2 = 0;
  iVar1 = FUN_4010c644(param_2,0,local_40,0x20);
  while (iVar1 != 0x26) {
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((local_40[0] & 0x80) == 0) {
      uVar2 = uVar2 + 1;
      if (uVar2 == param_4) goto LAB_4010b040;
      if (uVar2 == 1) {
        uVar3 = uVar4;
      }
    }
    else {
      uVar2 = 0;
    }
    uVar4 = uVar4 + 0x20;
    iVar1 = FUN_4010c644(param_2,uVar4,local_40,0x20);
  }
  if (uVar2 < param_4) {
    uVar3 = uVar4;
  }
LAB_4010b040:
  *param_3 = uVar3;
  return 0;
}



/* 4010b070 FUN_4010b070 */

/* Boundary evidence: original MIPS .pdata 4010b070..4010b25f. Semantic name remains unreviewed. */

int FUN_4010b070(undefined4 *param_1,undefined4 param_2,undefined1 *param_3,undefined1 *param_4,
                undefined1 *param_5)

{
  undefined2 uVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  _SYSTEMTIME _Stack_68;
  int aiStack_58 [2];
  undefined1 auStack_50 [48];
  
  FUN_4010c2bc(aiStack_58);
  uVar5 = (DAT_4010f008 + 1) % 10000;
  DAT_4010f008 = uVar5;
  memset(param_3,0,0x20);
  *param_3 = 0x85;
  param_3[1] = 2;
  memset(param_4,0,0x20);
  *param_4 = 0xc0;
  *(undefined4 *)(param_4 + 0x14) = param_2;
  param_4[3] = 0xc;
  memset(param_5,0,0x20);
  *param_5 = 0xc1;
  HVar2 = StringCchPrintfW((STRSAFE_LPWSTR)(param_5 + 2),0xf,L"FILE%.4d.CHK",uVar5);
  if (HVar2 < 0) {
    iVar4 = 0x1f;
  }
  else {
    GetLocalTime(&_Stack_68);
    FUN_4010a8b0(param_1,(short *)&_Stack_68,(ushort *)(param_3 + 8),param_3 + 0x14);
    uVar3 = *(undefined4 *)(param_3 + 8);
    *(undefined4 *)(param_3 + 0xc) = uVar3;
    *(undefined4 *)(param_3 + 0x10) = uVar3;
    param_3[0x15] = param_3[0x14];
    uVar1 = FUN_4010a14c((int)(param_5 + 2),0x18);
    *(undefined2 *)(param_4 + 4) = uVar1;
    iVar4 = FUN_4010c334(aiStack_58,(int)(param_1 + 8),param_4,0);
    if (iVar4 == 0) {
      iVar4 = FUN_4010a974(param_1,(int)aiStack_58,0,(undefined4 *)0x0);
      memcpy(param_4,auStack_50,0x20);
      if (iVar4 == 0) {
        uVar5 = FUN_4010a19c((int)param_3,1,0);
        uVar5 = FUN_4010a19c((int)param_4,0,uVar5);
        uVar5 = FUN_4010a19c((int)param_5,0,uVar5);
        *(short *)(param_3 + 2) = (short)uVar5;
      }
    }
  }
  FUN_4010c30c((int)aiStack_58);
  return iVar4;
}



/* 4010b260 FUN_4010b260 */

/* Boundary evidence: original MIPS .pdata 4010b260..4010b38b. Semantic name remains unreviewed. */

int FUN_4010b260(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint local_88 [2];
  undefined1 auStack_80 [32];
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [32];
  uint local_20;
  
  local_20 = DAT_4010e38c;
  iVar2 = FUN_4010775c((int)(param_1 + 0x4c),0x10);
  iVar3 = FUN_4010b070(param_1,param_2,auStack_80,auStack_60,auStack_40);
  if ((iVar3 == 0) && (iVar2 != 0)) {
    piVar4 = param_1 + 0x3e;
    local_88[0] = 0;
    iVar3 = FUN_4010af70(param_1,piVar4,local_88,3);
    uVar1 = local_88[0];
    if (iVar3 == 0) {
      iVar3 = FUN_4010c874(piVar4,local_88[0],auStack_80,0x20);
      if (((iVar3 != 0) || (iVar3 = FUN_4010c874(piVar4,uVar1 + 0x20,auStack_60,0x20), iVar3 != 0))
         || (iVar3 = FUN_4010c874(piVar4,uVar1 + 0x40,auStack_40,0x20), iVar3 != 0)) {
        param_1[0x54] = 1;
      }
    }
  }
  FUN_4010d048(local_20);
  return iVar3;
}



/* 4010b38c FUN_4010b38c */

/* Boundary evidence: original MIPS .pdata 4010b38c..4010b53f. Semantic name remains unreviewed. */

int FUN_4010b38c(undefined4 *param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5
                ,int param_6,undefined4 param_7)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 local_40 [20];
  undefined4 local_2c;
  
  if (param_4 == (uint *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *param_4;
  }
  param_1[7] = param_7;
  *param_1 = param_5;
  param_1[1] = param_6;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  uVar3 = *(undefined4 *)(param_3 + 4);
  param_1[0x36] = uVar3;
  param_1[0x29] = param_2;
  param_1[0x2a] = uVar3;
  param_1[0x2b] = 0;
  param_1[0x2c] = 1;
  FUN_40107720(param_1 + 0x4c,(uint)((uVar4 & 1) != 0),param_6);
  iVar2 = FUN_4010a608((int)param_1);
  if (iVar2 == 0) {
    puVar6 = param_1 + 0x2d;
    puVar5 = param_1 + 8;
    bVar1 = FUN_40107fa4(puVar5,(int)puVar6);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      uVar3 = 1;
      if (param_1[0x3c] == 2) {
        uVar3 = 2;
      }
      iVar2 = FUN_40108238(param_1 + 0x22,param_1 + 0x29,(int)puVar6,uVar3,0);
      if (iVar2 != 0) {
        if ((param_1[0x3c] == 1) && (uVar4 = FUN_40108734(param_1 + 0x22,1), uVar4 == 0)) {
          param_1[0x25] = 2;
          param_1[0x3c] = 2;
        }
        param_1[0x2b] = puVar6;
        memset(local_40,0,0x20);
        local_2c = param_1[0x3b];
        local_40[0] = 0xc0;
        iVar2 = FUN_4010c334(param_1 + 0x3e,(int)puVar5,local_40,1);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = FUN_4010c018(param_1 + 0x10,(int)puVar5,param_1 + 0x3e);
        return iVar2;
      }
    }
    iVar2 = 8;
  }
  return iVar2;
}



/* 4010b540 FUN_4010b540 */

/* Boundary evidence: original MIPS .pdata 4010b540..4010b717. Semantic name remains unreviewed. */

int FUN_4010b540(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_28 [2];
  
  iVar3 = 0;
  if (1 < (uint)param_1[0x30]) {
    iVar5 = 0;
    do {
      iVar1 = FUN_4010a3ac((int)param_1);
      if (iVar1 != 0) {
        return 0x4c7;
      }
      uVar4 = iVar5 + 2;
      iVar1 = FUN_401080fc(param_1 + 8,uVar4);
      if (iVar1 == 0) {
        iVar3 = FUN_4010c19c((int)(param_1 + 0x10),uVar4,local_28);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = 0;
        if (local_28[0] == 0) {
          FUN_40107e78(param_1 + 0x29,iVar5 * param_1[0x37] + param_1[0x33],param_1[0x37]);
          FUN_4010a208(param_1);
        }
        else {
          uVar2 = FUN_40108734(param_1 + 0x22,uVar4);
          iVar1 = FUN_4010a7e8((int)param_1,uVar2,2);
          if (iVar1 == 0) {
            iVar3 = FUN_4010b260(param_1,uVar4);
            if (iVar3 != 0) {
              return iVar3;
            }
          }
          else {
            iVar1 = FUN_4010775c((int)(param_1 + 0x4c),8);
            if (iVar1 != 0) {
              iVar3 = FUN_4010c0e4((int)(param_1 + 0x10),uVar4,0);
              if (iVar3 != 0) {
                param_1[0x54] = 1;
                return iVar3;
              }
              iVar1 = FUN_40108830(param_1 + 0x22,uVar4,0);
              iVar3 = 0;
              if (iVar1 == 0) {
                param_1[0x54] = 1;
                return 0x1f;
              }
            }
          }
        }
      }
      uVar4 = iVar5 + 3;
      iVar5 = iVar5 + 1;
    } while (uVar4 <= (uint)param_1[0x30]);
  }
  uVar4 = param_1[9];
  if (uVar4 != 0) {
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    param_1[0x51] = (uint)(param_1[4] * 100) / uVar4;
  }
  return iVar3;
}



/* 4010b718 FUN_4010b718 */

/* Boundary evidence: original MIPS .pdata 4010b718..4010b833. Semantic name remains unreviewed. */

undefined4 FUN_4010b718(HANDLE param_1)

{
  int iVar1;
  HLOCAL hMem;
  BOOL BVar2;
  uint uVar3;
  undefined4 uVar4;
  DWORD local_48 [2];
  HANDLE local_40;
  SIZE_T local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [4];
  SIZE_T local_2c;
  
  local_48[0] = 0;
  uVar4 = 0;
  iVar1 = FUN_40107ba4(&local_40,param_1,1,auStack_30,0x18,auStack_30,0x18,local_48,
                       (LPOVERLAPPED)0x0);
  if ((iVar1 == 0) || (hMem = LocalAlloc(0x40,local_2c), hMem == (HLOCAL)0x0)) {
    return 0;
  }
  local_3c = local_2c;
  local_38 = 0;
  local_34 = 1;
  local_40 = param_1;
  BVar2 = FUN_40107c94(&local_40,0,hMem,1);
  if (BVar2 != 0) {
    uVar3 = 0;
    do {
      if (*(char *)((int)hMem + uVar3 + 0xb) != '\0') goto LAB_4010b808;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x35);
    uVar4 = 1;
    if (*(char *)((int)hMem + 0x69) != '\x01') {
      uVar4 = 0;
    }
  }
LAB_4010b808:
  LocalFree(hMem);
  return uVar4;
}



/* 4010b834 FUN_4010b834 */

/* Boundary evidence: original MIPS .pdata 4010b834..4010bce3. Semantic name remains unreviewed. */

int FUN_4010b834(undefined4 *param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  byte bVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  wchar_t *pszSrc;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  int iVar9;
  undefined2 *local_c8;
  int local_c4;
  ushort local_c0;
  undefined2 *local_b8;
  int local_b4;
  wchar_t *local_b0;
  int local_ac;
  byte local_a8;
  byte local_a7;
  undefined2 local_a6;
  ushort local_a4;
  undefined2 *local_88;
  int aiStack_80 [2];
  char acStack_78 [48];
  undefined1 auStack_48 [32];
  
  FUN_4010c2bc(aiStack_80);
  DAT_4010f00c = 0;
  iVar3 = FUN_4010a974(param_1,(int)param_2,param_3 | 2,param_4);
  if (iVar3 == 0) {
    local_b8 = (undefined2 *)0x0;
    local_b4 = 0;
    FUN_4010c3c8((int)param_2,&local_b8,(undefined4 *)0x0,(uint *)0x0);
    if ((local_b4 != 0) || (local_b8 != (undefined2 *)0x0)) {
      local_b0 = L"<Unknown>";
      puVar6 = (undefined2 *)0x0;
      do {
        pszSrc = local_b0;
        iVar3 = FUN_4010a3ac((int)param_1);
        if (iVar3 != 0) {
          iVar3 = 0x4c7;
          break;
        }
        local_ac = 0;
        local_c4 = 0;
        iVar3 = FUN_4010c644(param_2,(uint)puVar6,&local_a8,0x20);
        bVar1 = local_a8;
        if ((iVar3 != 0) || (local_a8 == 0)) break;
        if ((local_a8 & 0x80) == 0) {
          puVar7 = puVar6 + 0x10;
          goto LAB_4010bc68;
        }
        if ((local_a8 & 0x40) == 0x40) goto LAB_4010bb88;
        puVar7 = puVar6 + 0x10;
        memcpy(auStack_48,&local_a8,0x20);
        if (bVar1 == 0x81) {
          pszSrc = L"$Bitmap";
LAB_4010bbc0:
          StringCchCopyW(&DAT_4010f00c,0x104,pszSrc);
          iVar9 = 0;
LAB_4010bbe0:
          iVar3 = FUN_4010c334(aiStack_80,(int)(param_1 + 8),auStack_48,iVar9);
          if (iVar3 != 0) break;
          if (iVar9 == 0) {
            iVar3 = FUN_4010a974(param_1,(int)aiStack_80,0,&local_c4);
          }
          else {
            iVar3 = FUN_4010b834(param_1,aiStack_80,2,&local_c4);
          }
          if ((iVar3 != 0) ||
             ((param_1[5] = param_1[5] + 1, local_c4 != 0 &&
              (iVar3 = FUN_4010ae24((int)param_1,param_2,(uint)puVar6,acStack_78), iVar3 != 0))))
          break;
        }
        else {
          if (bVar1 == 0x82) {
            pszSrc = L"$UpcaseTable";
            goto LAB_4010bbc0;
          }
          if (bVar1 != 0x83) {
            if (bVar1 != 0x85) {
              if (bVar1 != 0xa1) {
                if (bVar1 == 0xa2) {
                  pszSrc = L"$AclTable";
                }
                goto LAB_4010bbc0;
              }
              goto LAB_4010bc68;
            }
            uVar4 = FUN_4010a19c((int)&local_a8,1,0);
            if ((local_a4 & 0x10) != 0) {
              local_ac = 1;
            }
            local_c0 = local_a6;
            local_88 = puVar7 + (uint)local_a7 * 0x10;
            iVar3 = FUN_4010c644(param_2,(uint)puVar7,&local_a8,0x20);
            if (iVar3 == 0) {
              if (local_a8 == 0xc0) {
                memcpy(auStack_48,&local_a8,0x20);
                uVar5 = (uint)local_a6._1_1_;
                local_c8 = &DAT_4010f00c;
                if (0x103 < uVar5) goto LAB_4010bb88;
                while( true ) {
                  uVar4 = FUN_4010a19c((int)&local_a8,0,uVar4);
                  puVar7 = puVar7 + 0x10;
                  if (uVar5 == 0) break;
                  iVar3 = FUN_4010c644(param_2,(uint)puVar7,&local_a8,0x20);
                  if (iVar3 != 0) goto LAB_4010bca8;
                  if (local_a8 != 0xc1) break;
                  uVar8 = uVar5;
                  if (0xe < uVar5) {
                    uVar8 = 0xf;
                  }
                  memcpy(local_c8,&local_a6,uVar8 * 2);
                  uVar5 = uVar5 - uVar8;
                  local_c8 = local_c8 + uVar8;
                }
                puVar2 = local_88;
                *local_c8 = 0;
                if (uVar5 != 0) goto LAB_4010bb88;
                for (; puVar7 < puVar2; puVar7 = puVar7 + 0x10) {
                  iVar3 = FUN_4010c644(param_2,(uint)puVar7,&local_a8,0x20);
                  if (iVar3 != 0) goto LAB_4010bca8;
                  if ((local_a8 & 0x40) == 0) goto LAB_4010bb88;
                  if ((local_a7 & 1) != 0) {
                    iVar3 = 0x32;
                    goto LAB_4010bca8;
                  }
                  uVar4 = FUN_4010a19c((int)&local_a8,0,uVar4);
                }
                iVar9 = local_ac;
                if (local_c0 != uVar4) goto LAB_4010bb88;
                goto LAB_4010bbe0;
              }
LAB_4010bb88:
              local_c8 = (undefined2 *)0x0;
              iVar3 = FUN_4010ad3c((int)param_1,param_2,(uint)puVar6,(uint *)&local_c8);
              puVar7 = local_c8;
              if (iVar3 == 0) goto LAB_4010bc68;
            }
            break;
          }
        }
LAB_4010bc68:
        puVar6 = puVar7;
      } while ((local_b4 != 0) || (puVar7 < local_b8));
    }
  }
LAB_4010bca8:
  FUN_4010c30c((int)aiStack_80);
  return iVar3;
}



/* 4010bce4 FUN_4010bce4 */

/* Boundary evidence: original MIPS .pdata 4010bce4..4010bddb. Semantic name remains unreviewed. */

int FUN_4010bce4(undefined4 *param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5
                ,int param_6,undefined4 param_7)

{
  int iVar1;
  int aiStack_38 [5];
  int local_24;
  int local_18;
  
  iVar1 = FUN_4010b38c(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if ((iVar1 == 0) && (iVar1 = FUN_4010b834(param_1,param_1 + 0x3e,1,(undefined4 *)0x0), iVar1 == 0)
     ) {
    param_1[6] = 1;
    iVar1 = FUN_4010b540(param_1);
    if (iVar1 == 0) {
      if ((((param_1[0x3d] & 1) != 0) && (FUN_40107b38(param_1 + 0x4c,aiStack_38), local_24 != 0))
         && (local_18 == 0)) {
        FUN_4010a704((int)param_1);
      }
      if (param_1[0x54] != 0) {
        FUN_4010a314((int)param_1,0xc1e,0xd4a);
      }
      FUN_401078c4((int)(param_1 + 0x4c));
      return 0;
    }
  }
  iVar1 = FUN_4010a3f4((int)param_1,iVar1);
  return iVar1;
}



/* 4010bddc FUN_4010bddc */

/* Boundary evidence: original MIPS .pdata 4010bddc..4010be27. Semantic name remains unreviewed. */

int FUN_4010bddc(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  FUN_4010bfe4(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x88) = 0;
  FUN_4010c2bc((undefined4 *)(param_1 + 0xf8));
  return param_1;
}



/* 4010be28 FUN_4010be28 */

/* Boundary evidence: original MIPS .pdata 4010be28..4010be73. Semantic name remains unreviewed. */

void FUN_4010be28(int param_1)

{
  FUN_4010c30c(param_1 + 0xf8);
  FUN_40108568((undefined4 *)(param_1 + 0x88));
  FUN_4010c30c(param_1 + 0x48);
  FUN_401081f8((undefined4 *)(param_1 + 0x30));
  FUN_401081f8((undefined4 *)(param_1 + 0x20));
  return;
}



/* 4010be74 FUN_4010be74 */

/* Boundary evidence: original MIPS .pdata 4010be74..4010bfe3. Semantic name remains unreviewed. */

int FUN_4010be74(HANDLE param_1,uint *param_2,undefined *param_3,undefined *param_4,
                undefined4 param_5,int *param_6)

{
  int iVar1;
  BOOL BVar2;
  DWORD aDStack_2c0 [2];
  undefined1 auStack_2b8 [24];
  undefined4 auStack_2a0 [76];
  int aiStack_170 [10];
  undefined4 local_148 [72];
  uint local_28;
  uint local_20;
  
  local_20 = DAT_4010e38c;
  FUN_4010bddc((int)auStack_2a0);
  local_148[0] = 0x128;
  if ((param_2 == (uint *)0x0) || ((*param_2 & 4) == 0)) {
    iVar1 = GetPartitionInfo(param_1,local_148);
    if (iVar1 != 0) {
      if ((local_28 & 0x10) != 0) {
        FUN_401031ac(0xceb,param_4);
        iVar1 = 0x20;
        goto LAB_4010bfb0;
      }
      goto LAB_4010bf20;
    }
    FUN_401031ac(0xce5,param_4);
  }
  else {
LAB_4010bf20:
    BVar2 = DeviceIoControl(param_1,1,auStack_2b8,0x18,auStack_2b8,0x18,aDStack_2c0,
                            (LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      iVar1 = FUN_4010bce4(auStack_2a0,param_1,(int)auStack_2b8,param_2,param_3,(int)param_4,param_5
                          );
      if (param_3 != (undefined *)0x0) {
        (*(code *)param_3)(100);
      }
      if (param_6 != (int *)0x0) {
        FUN_40107b38(aiStack_170,param_6);
      }
      goto LAB_4010bfb0;
    }
  }
  iVar1 = 0x1f;
LAB_4010bfb0:
  FUN_4010be28((int)auStack_2a0);
  FUN_4010d048(local_20);
  return iVar1;
}



/* 4010bfe4 FUN_4010bfe4 */

/* Boundary evidence: original MIPS .pdata 4010bfe4..4010c017. Semantic name remains unreviewed. */

int FUN_4010bfe4(int param_1)

{
  FUN_4010c2bc((undefined4 *)(param_1 + 8));
  *(undefined4 *)(param_1 + 0x40) = 2;
  return param_1;
}



/* 4010c018 FUN_4010c018 */

/* Boundary evidence: original MIPS .pdata 4010c018..4010c0e3. Semantic name remains unreviewed. */

void FUN_4010c018(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char local_38;
  byte local_37;
  
  *param_1 = param_2;
  param_1[0x10] = 2;
  iVar2 = *(int *)(param_2 + 0xd0);
  uVar3 = 0;
  while( true ) {
    iVar1 = FUN_4010c644(param_3,uVar3,&local_38,0x20);
    if (iVar1 != 0) {
      return;
    }
    if ((local_38 == -0x7f) && ((bool)(local_37 & 1) == (iVar2 == 2))) break;
    uVar3 = uVar3 + 0x20;
  }
  FUN_4010c334(param_1 + 2,param_2,&local_38,1);
  return;
}



/* 4010c0e4 FUN_4010c0e4 */

/* Boundary evidence: original MIPS .pdata 4010c0e4..4010c19b. Semantic name remains unreviewed. */

void FUN_4010c0e4(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte local_20 [8];
  
  uVar3 = param_2 - 2U >> 3;
  iVar2 = FUN_4010c644((int *)(param_1 + 8),uVar3,local_20,1);
  if (iVar2 == 0) {
    bVar1 = (byte)(1 << (param_2 - 2U & 7));
    if (param_3 == 0) {
      local_20[0] = ~bVar1 & local_20[0];
    }
    else {
      local_20[0] = bVar1 | local_20[0];
    }
    FUN_4010c874((int *)(param_1 + 8),uVar3,local_20,1);
  }
  return;
}



/* 4010c19c FUN_4010c19c */

/* Boundary evidence: original MIPS .pdata 4010c19c..4010c20f. Semantic name remains unreviewed. */

void FUN_4010c19c(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  byte local_18 [8];
  
  iVar1 = FUN_4010c644((int *)(param_1 + 8),param_2 - 2U >> 3,local_18,1);
  if (iVar1 == 0) {
    *param_3 = 1 << (param_2 - 2U & 7) & 0xffU & (uint)local_18[0];
  }
  return;
}



/* 4010c210 FUN_4010c210 */

/* Boundary evidence: original MIPS .pdata 4010c210..4010c2bb. Semantic name remains unreviewed. */

int FUN_4010c210(int *param_1,int *param_2)

{
  int iVar1;
  uint local_18 [2];
  
  local_18[0] = 1;
  if ((uint)param_1[0x10] <= *(uint *)(*param_1 + 0xa0)) {
    do {
      iVar1 = FUN_4010c19c((int)param_1,param_1[0x10],local_18);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (local_18[0] == 0) {
        *param_2 = param_1[0x10];
        param_1[0x10] = param_1[0x10] + 1;
        return 0;
      }
      iVar1 = param_1[0x10];
      param_1[0x10] = iVar1 + 1U;
    } while (iVar1 + 1U <= *(uint *)(*param_1 + 0xa0));
  }
  return 0x70;
}



/* 4010c2bc FUN_4010c2bc */

/* Boundary evidence: original MIPS .pdata 4010c2bc..4010c30b. Semantic name remains unreviewed. */

undefined4 * FUN_4010c2bc(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[10] = 0;
  param_1[0xb] = 0xffffffff;
  param_1[0xc] = 0xffffffff;
  param_1[0xd] = 0;
  memset(param_1 + 2,0,0x20);
  return param_1;
}



/* 4010c30c FUN_4010c30c */

/* Boundary evidence: original MIPS .pdata 4010c30c..4010c333. Semantic name remains unreviewed. */

void FUN_4010c30c(int param_1)

{
  if (*(HLOCAL *)(param_1 + 0x28) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0x28));
  }
  return;
}



/* 4010c334 FUN_4010c334 */

/* Boundary evidence: original MIPS .pdata 4010c334..4010c3c7. Semantic name remains unreviewed. */

undefined4 FUN_4010c334(int *param_1,int param_2,void *param_3,int param_4)

{
  HANDLE hHeap;
  LPVOID pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_1 = param_2;
  uVar3 = 0;
  memcpy(param_1 + 2,param_3,0x20);
  if (param_4 != 0) {
    if ((HLOCAL)param_1[10] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[10]);
    }
    iVar2 = *param_1;
    hHeap = GetProcessHeap();
    pvVar1 = HeapAlloc(hHeap,0,*(SIZE_T *)(iVar2 + 0xc0));
    param_1[10] = (int)pvVar1;
    if (pvVar1 == (LPVOID)0x0) {
      uVar3 = 8;
    }
  }
  return uVar3;
}



/* 4010c3c8 FUN_4010c3c8 */

undefined4 FUN_4010c3c8(int param_1,undefined4 *param_2,undefined4 *param_3,uint *param_4)

{
  byte bVar1;
  ushort uVar2;
  
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  bVar1 = *(byte *)(param_1 + 8);
  if ((bVar1 == 0x81) || (bVar1 == 0x82)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x20);
      param_2[1] = *(undefined4 *)(param_1 + 0x24);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0x1c);
    }
  }
  else if (bVar1 == 0xc0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x20);
      param_2[1] = *(undefined4 *)(param_1 + 0x24);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0x1c);
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = (uint)((*(byte *)(param_1 + 9) & 2) != 0);
    }
  }
  else {
    if ((bVar1 < 0xa0) || (0xbf < bVar1)) {
      if (bVar1 < 0xe0) {
        return 0;
      }
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(param_1 + 0x20);
        param_2[1] = *(undefined4 *)(param_1 + 0x24);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_1 + 0x1c);
      }
      if (param_4 == (uint *)0x0) {
        return 1;
      }
      uVar2 = (ushort)*(byte *)(param_1 + 9);
    }
    else {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(param_1 + 0x20);
        param_2[1] = *(undefined4 *)(param_1 + 0x24);
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = *(undefined4 *)(param_1 + 0x1c);
      }
      if (param_4 == (uint *)0x0) {
        return 1;
      }
      uVar2 = *(ushort *)(param_1 + 0xc);
    }
    *param_4 = (uint)((uVar2 & 2) != 0);
  }
  return 1;
}



/* 4010c53c FUN_4010c53c */

void FUN_4010c53c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 8);
  if ((bVar1 != 0x81) && (bVar1 != 0x82)) {
    if (bVar1 == 0xc0) {
      *(undefined4 *)(param_1 + 0x10) = param_3;
      *(undefined4 *)(param_1 + 0x14) = param_4;
    }
    else if (((bVar1 < 0xa0) || (0xbf < bVar1)) && (bVar1 < 0xe0)) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x20) = param_3;
  *(undefined4 *)(param_1 + 0x24) = param_4;
  *(undefined4 *)(param_1 + 0x1c) = param_5;
  return;
}



/* 4010c5bc FUN_4010c5bc */

ushort FUN_4010c5bc(int param_1)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = *(byte *)(param_1 + 8);
  if (((bVar1 == 0x81) || (bVar1 == 0x82)) || (bVar1 == 0xc0)) {
    uVar2 = 1;
  }
  else if ((bVar1 < 0xa0) || (0xbf < bVar1)) {
    if (bVar1 < 0xe0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(byte *)(param_1 + 9) & 1;
    }
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0xc) & 1;
  }
  return uVar2;
}



/* 4010c644 FUN_4010c644 */

/* Boundary evidence: original MIPS .pdata 4010c644..4010c873. Semantic name remains unreviewed. */

undefined4 FUN_4010c644(int *param_1,uint param_2,void *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  BOOL BVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_40;
  uint local_3c;
  void *local_38;
  uint local_30;
  int local_2c;
  
  local_30 = 0;
  local_2c = 0;
  local_3c = 0;
  local_40 = 0;
  uVar5 = 0;
  local_38 = param_3;
  iVar2 = FUN_4010c3c8((int)param_1,&local_30,&local_3c,&local_40);
  uVar1 = local_3c;
  if (iVar2 == 0) {
    uVar5 = 0x32;
  }
  else if (((local_40 == 0) || (local_2c != 0)) || (param_2 < local_30)) {
    uVar6 = *(uint *)(*param_1 + 0xc0);
    uVar8 = param_2 / uVar6;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if (((uVar6 < param_4) || (uVar4 = param_2 % uVar6 + param_4, uVar6 < uVar4)) ||
       (uVar4 < param_4)) {
      uVar5 = 0x57;
    }
    else {
      if (((param_1[0xb] != local_3c) || (param_2 < (uint)param_1[0xd])) ||
         (param_1[0xd] + uVar6 <= param_2)) {
        if (local_40 == 0) {
          uVar7 = 0;
          uVar4 = local_3c;
          param_3 = local_38;
          if (uVar8 != 0) {
            do {
              uVar4 = FUN_40108734((int *)(*param_1 + 0x68),uVar4);
              if (uVar4 == 0xfffffffe) {
                return 0x1f;
              }
              if (uVar4 == 0xffffffff) goto LAB_4010c7f4;
              uVar7 = uVar7 + 1;
              param_3 = local_38;
            } while (uVar7 < uVar8);
          }
        }
        else {
          uVar4 = uVar8 + local_3c;
        }
        BVar3 = FUN_40107d74((undefined4 *)(*param_1 + 0x84),uVar4,param_1[10]);
        if (BVar3 == 0) {
          return 0x1e;
        }
        param_1[0xb] = uVar1;
        param_1[0xc] = uVar4;
        param_1[0xd] = uVar8 * uVar6;
      }
      if (param_3 != (void *)0x0) {
        memcpy(param_3,(void *)(param_1[10] + param_2 % uVar6),param_4);
      }
    }
  }
  else {
LAB_4010c7f4:
    uVar5 = 0x26;
  }
  return uVar5;
}



/* 4010c874 FUN_4010c874 */

/* Boundary evidence: original MIPS .pdata 4010c874..4010cb63. Semantic name remains unreviewed. */

int FUN_4010c874(int *param_1,uint param_2,void *param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  uint _Size;
  uint uVar6;
  uint uVar7;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  void *local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_3c = 0;
  local_40 = 0;
  local_30 = param_3;
  iVar3 = FUN_4010c3c8((int)param_1,&local_38,&local_3c,&local_40);
  uVar2 = local_3c;
  if (iVar3 == 0) {
    return 0x32;
  }
  if (((local_40 != 0) && (local_34 == 0)) && (local_38 <= param_2)) {
    return 0x26;
  }
  bVar1 = false;
  _Size = *(uint *)(*param_1 + 0xc0);
  uVar7 = param_2 / _Size;
  if (_Size == 0) {
    trap(0x1c00);
  }
  local_38 = param_2 % _Size;
  if (_Size == 0) {
    trap(0x1c00);
  }
  if (((_Size < param_4) || (_Size < local_38 + param_4)) || (local_38 + param_4 < param_4)) {
    return 0x57;
  }
  if ((((param_1[0xb] == local_3c) && ((uint)param_1[0xd] <= param_2)) &&
      (param_2 < param_1[0xd] + _Size)) || ((local_38 == 0 && (param_4 == _Size))))
  goto LAB_4010caec;
  if (local_40 == 0) {
    uVar6 = 0;
    uVar5 = local_3c;
    if (uVar7 == 0) goto LAB_4010c9c8;
    do {
      local_40 = FUN_40108734((int *)(*param_1 + 0x68),uVar5);
      if (local_40 == 0xfffffffe) {
        return 0x1f;
      }
      if (local_40 == 0xffffffff) {
        iVar3 = FUN_4010c210((int *)(*param_1 + 0x20),(int *)&local_40);
        if (iVar3 != 0) {
          return iVar3;
        }
        FUN_40108010((int *)*param_1,local_40);
        iVar3 = FUN_40108830((int *)(*param_1 + 0x68),uVar5,local_40);
        if (iVar3 == 0) {
          return 0x1f;
        }
        iVar3 = FUN_40108830((int *)(*param_1 + 0x68),local_40,0xffffffff);
        if (iVar3 == 0) {
          return 0x1f;
        }
        iVar3 = FUN_4010c0e4(*param_1 + 0x20,local_40,1);
        if (iVar3 != 0) {
          return iVar3;
        }
        bVar1 = true;
      }
      uVar5 = local_40;
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar7);
    if (!bVar1) goto LAB_4010c9c8;
    memset((void *)param_1[10],0,_Size);
  }
  else {
    uVar5 = uVar7 + local_3c;
LAB_4010c9c8:
    BVar4 = FUN_40107d74((undefined4 *)(*param_1 + 0x84),uVar5,param_1[10]);
    if (BVar4 == 0) {
      return 0x1e;
    }
  }
  param_1[0xb] = uVar2;
  param_1[0xc] = uVar5;
  param_1[0xd] = uVar7 * _Size;
LAB_4010caec:
  iVar3 = 0;
  memcpy((void *)(param_1[10] + local_38),local_30,param_4);
  BVar4 = FUN_40107d2c((undefined4 *)(*param_1 + 0x84),param_1[0xc],param_1[10]);
  if (BVar4 == 0) {
    iVar3 = 0x1d;
  }
  return iVar3;
}



/* 4010cd94 FUN_4010cd94 */

/* Boundary evidence: original MIPS .pdata 4010cd94..4010cecf. Semantic name remains unreviewed. */

int FUN_4010cd94(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_4010f224 != (code *)0x0) {
      iVar2 = (*DAT_4010f224)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_4010ce44;
    FUN_4010d228();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_401011cc(param_1,param_2);
  }
LAB_4010ce44:
  if (((param_2 == 0) && (FUN_4010d1b0(), iVar1 != 0)) && (DAT_4010f224 != (code *)0x0)) {
    iVar1 = (*DAT_4010f224)(param_1,0,param_3);
  }
  return iVar1;
}



/* 4010ced0 FUN_4010ced0 */

/* Boundary evidence: original MIPS .pdata 4010ced0..4010cefb. Semantic name remains unreviewed. */

void FUN_4010ced0(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 4010cefc entry */

/* Boundary evidence: original MIPS .pdata 4010cefc..4010cf53. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_4010cf54();
  }
  FUN_4010cd94(param_1,param_2,param_3);
  return;
}



/* 4010cf54 FUN_4010cf54 */

/* Boundary evidence: original MIPS .pdata 4010cf54..4010cfc7. Semantic name remains unreviewed. */

void FUN_4010cf54(void)

{
  uint uVar1;
  
  if ((DAT_4010e38c == 0) || (DAT_4010e38c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4010e38c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4010e38c == 0) {
      DAT_4010e38c = 0xb064;
    }
  }
  DAT_4010e390 = ~DAT_4010e38c;
  return;
}



/* 4010cfc8 FUN_4010cfc8 */

/* Boundary evidence: original MIPS .pdata 4010cfc8..4010d01b. Semantic name remains unreviewed. */

void FUN_4010cfc8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_4010d048(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 4010d01c FUN_4010d01c */

/* Boundary evidence: original MIPS .pdata 4010d01c..4010d047. Semantic name remains unreviewed. */

undefined4 FUN_4010d01c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_4010cfc8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 4010d048 FUN_4010d048 */

/* Boundary evidence: original MIPS .pdata 4010d048..4010d08f. Semantic name remains unreviewed. */

void FUN_4010d048(uint param_1)

{
  if ((param_1 == DAT_4010e38c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 4010d090 FUN_4010d090 */

/* Boundary evidence: original MIPS .pdata 4010d090..4010d1af. Semantic name remains unreviewed. */

void FUN_4010d090(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4010f214 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4010f21c;
    if (DAT_4010f21c != (undefined4 *)0x0) {
      while (DAT_4010f218 = DAT_4010f218 + -1, _Memory <= DAT_4010f218) {
        if ((code *)*DAT_4010f218 != (code *)0x0) {
          (*(code *)*DAT_4010f218)();
          _Memory = DAT_4010f21c;
        }
      }
      free(_Memory);
      DAT_4010f218 = (undefined4 *)0x0;
      DAT_4010f21c = (undefined4 *)0x0;
    }
    FUN_4010d1d4((undefined4 *)&DAT_40101010,(undefined4 *)&DAT_40101014);
  }
  FUN_4010d1d4((undefined4 *)&DAT_40101018,(undefined4 *)&DAT_4010101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4010f220,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 4010d1b0 FUN_4010d1b0 */

/* Boundary evidence: original MIPS .pdata 4010d1b0..4010d1d3. Semantic name remains unreviewed. */

void FUN_4010d1b0(void)

{
  FUN_4010d090(0,0,1);
  return;
}



/* 4010d1d4 FUN_4010d1d4 */

/* Boundary evidence: original MIPS .pdata 4010d1d4..4010d227. Semantic name remains unreviewed. */

void FUN_4010d1d4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4010d228 FUN_4010d228 */

/* Boundary evidence: original MIPS .pdata 4010d228..4010d263. Semantic name remains unreviewed. */

void FUN_4010d228(void)

{
  FUN_4010d1d4((undefined4 *)&DAT_40101008,(undefined4 *)&DAT_4010100c);
  FUN_4010d1d4((undefined4 *)&DAT_40101000,(undefined4 *)&DAT_40101004);
  return;
}


