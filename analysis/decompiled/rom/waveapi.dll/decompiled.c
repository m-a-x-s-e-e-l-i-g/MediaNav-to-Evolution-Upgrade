/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c03f1000 FUN_c03f1000 */

/* Boundary evidence: original MIPS .pdata c03f1000..c03f106f. Semantic name remains unreviewed. */

int FUN_c03f1000(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_1c = *(undefined4 *)(param_1 + 0x24);
  local_10 = param_5;
  local_20 = param_2;
  local_18 = param_3;
  local_14 = param_4;
  iVar1 = WriteMsgQueue(*(undefined4 *)(param_1 + 0x20),&local_20,0x14,0,0);
  if (iVar1 == 0) {
    GetLastError();
  }
  return iVar1;
}



/* c03f1070 FUN_c03f1070 */

undefined4 FUN_c03f1070(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 1;
  iVar2 = DAT_c0401214;
  if (((param_2 != 1) && (iVar2 = DAT_c04011f0, param_2 != 2)) || (param_1 != iVar2)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c03f10b0 FUN_c03f10b0 */

/* Boundary evidence: original MIPS .pdata c03f10b0..c03f1173. Semantic name remains unreviewed. */

void FUN_c03f10b0(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0x3bd) {
    iVar2 = 2;
  }
  else {
    if (param_2 != 0x3c0) {
      return;
    }
    iVar2 = 1;
  }
  iVar3 = DAT_c0401214;
  if ((((iVar2 != 1) && (iVar3 = DAT_c04011f0, iVar2 != 2)) || (*(int *)(param_1 + 0x34) != iVar3))
     && (LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x58)), LVar1 == 0)) {
    *(undefined4 *)(param_1 + 0x60) = 1;
  }
  FUN_c03f1000(param_1,param_2,*(undefined4 *)(param_4 + 0x24),param_5,*(undefined4 *)(param_4 + 8))
  ;
  return;
}



/* c03f28a8 FUN_c03f28a8 */

/* Boundary evidence: original MIPS .pdata c03f28a8..c03f290f. Semantic name remains unreviewed. */

undefined4 FUN_c03f28a8(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x800700b7;
  if (param_1[1] != 0) {
    if (*param_1 != 0) {
      CeFreeAsynchronousBuffer(*param_1,param_1[1],param_1[3],param_1[4]);
    }
    uVar1 = CeCloseCallerBuffer(param_1[1],param_1[2],param_1[3],param_1[4]);
    param_1[1] = 0;
    *param_1 = 0;
    param_1[3] = 0;
  }
  return uVar1;
}



/* c03f2910 FUN_c03f2910 */

/* Boundary evidence: original MIPS .pdata c03f2910..c03f292b. Semantic name remains unreviewed. */

void FUN_c03f2910(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



/* c03f292c FUN_c03f292c */

/* Boundary evidence: original MIPS .pdata c03f292c..c03f2987. Semantic name remains unreviewed. */

LONG FUN_c03f292c(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* c03f2988 FUN_c03f2988 */

undefined4 FUN_c03f2988(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



/* c03f2998 FUN_c03f2998 */

/* Boundary evidence: original MIPS .pdata c03f2998..c03f29c7. Semantic name remains unreviewed. */

void FUN_c03f2998(undefined4 param_1,uint param_2,uint *param_3,LPDWORD param_4,uint param_5)

{
  FUN_c03f53e0(param_2,param_3,param_4,param_5);
  return;
}



/* c03f29c8 FUN_c03f29c8 */

/* Boundary evidence: original MIPS .pdata c03f29c8..c03f29f7. Semantic name remains unreviewed. */

void FUN_c03f29c8(undefined4 param_1,uint param_2,uint *param_3,uint *param_4,uint param_5)

{
  FUN_c03f57cc(param_2,param_3,param_4,param_5);
  return;
}



/* c03f29f8 FUN_c03f29f8 */

/* Boundary evidence: original MIPS .pdata c03f29f8..c03f2a7b. Semantic name remains unreviewed. */

void FUN_c03f29f8(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  int local_10 [2];
  
  if (((((param_2 & 2) != 0) && (param_3 == 1)) &&
      (iVar1 = (**(code **)*param_1)(param_1,3,local_10), -1 < iVar1)) && (local_10[0] == 0)) {
    (**(code **)(*param_1 + 4))(param_1,0x11,0,DAT_c040125c,0);
  }
  return;
}



/* c03f2a7c FUN_c03f2a7c */

undefined4 FUN_c03f2a7c(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_1 != 0xffffffff) && (0x10 < param_1)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c03f2aa4 FUN_c03f2aa4 */

/* Boundary evidence: original MIPS .pdata c03f2aa4..c03f2b3b. Semantic name remains unreviewed. */

int * FUN_c03f2aa4(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = FUN_c03f8000(-0x3fbfec94,param_2[7],param_1,5,0);
  if ((((piVar1 == (int *)0x0) || (piVar1[9] != param_3)) || ((uint)piVar1[0xb] < (uint)param_2[1]))
     || (piVar1[10] != *param_2)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



/* c03f2b3c FUN_c03f2b3c */

/* Boundary evidence: original MIPS .pdata c03f2b3c..c03f2e83. Semantic name remains unreviewed. */

undefined4
FUN_c03f2b3c(int param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  void *_Buf2;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  puVar7 = param_4 + 6;
  *(undefined4 *)*puVar7 = 0;
  _Buf2 = (void *)*param_4;
  iVar1 = memcmp(&DAT_c03f204c,_Buf2,0x10);
  if (iVar1 == 0) {
    if (param_4[1] == 1) {
      if (((param_2 == 2) && (3 < (uint)param_4[3])) && (7 < (uint)param_4[5])) {
        if (0xf < *(uint *)param_4[2]) {
          *param_5 = 0xb;
          return 1;
        }
        FUN_c03faff4(DAT_c04011f8,*(uint *)param_4[2],(undefined4 *)param_4[4]);
LAB_c03f2d00:
        *(undefined4 *)*puVar7 = 8;
LAB_c03f2e1c:
        *param_5 = 0;
        return 1;
      }
LAB_c03f2c44:
      uVar3 = 0xb;
LAB_c03f2c48:
      *param_5 = uVar3;
      return 1;
    }
  }
  else {
    iVar1 = memcmp(&DAT_c03f205c,_Buf2,0x10);
    if (iVar1 == 0) {
      if (param_4[1] == 1) {
        if ((param_2 == 2) && (7 < (uint)param_4[5])) {
          piVar5 = (int *)param_4[4];
          piVar2 = FUN_c03fa760(param_1,2,param_3);
          if (piVar2 == (int *)0x0) {
LAB_c03f2cd8:
            uVar3 = 5;
            goto LAB_c03f2c48;
          }
          *piVar5 = piVar2[0x12];
          piVar5[1] = piVar2[0x15];
          FUN_c03fa830(piVar2);
          goto LAB_c03f2d00;
        }
        goto LAB_c03f2c44;
      }
    }
    else {
      iVar1 = memcmp(&DAT_c03f206c,_Buf2,0x10);
      if (iVar1 != 0) {
        uVar3 = 8;
        uVar4 = 0;
        goto LAB_c03f2e50;
      }
      if (param_4[1] != 1) {
        *param_5 = 0xb;
        return 1;
      }
      if ((3 < (uint)param_4[3]) && (0xf < (uint)param_4[5])) {
        puVar6 = (undefined4 *)param_4[4];
        uVar8 = *(uint *)param_4[2];
        puVar6[2] = 0;
        puVar6[3] = 0;
        if ((uVar8 & 1) == 0) {
          puVar6[1] = 0;
          *puVar6 = 0;
        }
        else {
          piVar2 = FUN_c03fa760(param_1,2,param_3);
          if (piVar2 == (int *)0x0) goto LAB_c03f2cd8;
          puVar6[1] = piVar2[0x17];
          *puVar6 = 1;
          FUN_c03fa830(piVar2);
        }
        *(undefined4 *)*puVar7 = 0x10;
        if (((uVar8 & 2) != 0) || ((uVar8 & 4) != 0)) {
          *param_5 = 0;
          return 0;
        }
        goto LAB_c03f2e1c;
      }
    }
  }
  uVar4 = 1;
  uVar3 = 0xb;
LAB_c03f2e50:
  *param_5 = uVar3;
  return uVar4;
}



/* c03f2e84 FUN_c03f2e84 */

/* Boundary evidence: original MIPS .pdata c03f2e84..c03f31db. Semantic name remains unreviewed. */

undefined4
FUN_c03f2e84(int param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  void *_Buf2;
  int *piVar7;
  int local_50 [2];
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  uint local_28;
  
  local_28 = DAT_c04011e8;
  local_44 = 0x8498;
  local_48 = 0xe7e569a5;
  local_3d = 0xd1;
  local_42 = 0x43fe;
  local_40 = 0x80;
  local_3f = 0x75;
  local_3e = 0x33;
  local_3c = 0xfd;
  local_3b = 0xab;
  local_3a = 0x15;
  local_39 = 0xef;
  local_38 = 0x40e953ae;
  _Buf2 = (void *)*param_4;
  local_34 = 0xee3e;
  local_32 = 0x493a;
  local_30 = 0x93;
  local_2f = 0xee;
  local_2e = 0xda;
  local_2d = 0x3e;
  local_2c = 0x30;
  local_2b = 0x76;
  local_2a = 0x43;
  local_29 = 0x90;
  iVar2 = memcmp(&local_48,_Buf2,0x10);
  if (iVar2 == 0) {
    if ((((param_4[1] == 1) && (param_2 == 2)) && (3 < (uint)param_4[3])) && (7 < (uint)param_4[5]))
    {
      if (0xf < *(uint *)param_4[2]) {
        *param_5 = 0xb;
        goto LAB_c03f305c;
      }
      uVar5 = *(uint *)param_4[4];
      if ((1 < uVar5) && (uVar5 < 7)) {
        FUN_c03fb858(DAT_c04011f8,*(uint *)param_4[2],(int *)param_4[4]);
        goto LAB_c03f3190;
      }
    }
LAB_c03f3054:
    uVar4 = 0xb;
  }
  else {
    iVar2 = memcmp(&local_38,_Buf2,0x10);
    if (iVar2 != 0) {
      *param_5 = 8;
      FUN_c0400008(local_28);
      return 0;
    }
    if (((param_4[1] != 1) || (param_2 != 2)) || ((uint)param_4[5] < 8)) goto LAB_c03f3054;
    piVar7 = (int *)param_4[4];
    piVar3 = FUN_c03fa760(param_1,2,param_3);
    if (piVar3 != (int *)0x0) {
      puVar6 = (uint *)(piVar7 + 1);
      if (((*puVar6 & 1) == 0) || (bVar1 = true, (piVar3[0x15] & 1U) != 0)) {
        bVar1 = false;
      }
      piVar3[0x12] = *piVar7;
      uVar5 = *puVar6;
      piVar3[0x15] = uVar5;
      if ((((uVar5 & 2) == 0) && (FUN_c03fb924(DAT_c04011f8,(int)piVar3,local_50), bVar1)) &&
         ((local_50[0] == 0 && (piVar3[0x14] != 0)))) {
        FUN_c03f1000((int)piVar3,0x3d8,piVar3[0x14],0,0);
      }
      FUN_c03fa830(piVar3);
LAB_c03f3190:
      FUN_c03fb204(DAT_c04011f8);
      *param_5 = 0;
      goto LAB_c03f305c;
    }
    uVar4 = 5;
  }
  *param_5 = uVar4;
LAB_c03f305c:
  FUN_c0400008(local_28);
  return 1;
}



/* c03f31dc FUN_c03f31dc */

/* Boundary evidence: original MIPS .pdata c03f31dc..c03f3217. Semantic name remains unreviewed. */

undefined4 FUN_c03f31dc(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_c040120c = param_1;
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c03f3218 FUN_c03f3218 */

/* Boundary evidence: original MIPS .pdata c03f3218..c03f3317. Semantic name remains unreviewed. */

HKEY FUN_c03f3218(LPCWSTR param_1)

{
  LSTATUS LVar1;
  HKEY local_228;
  HKEY local_224;
  DWORD local_220;
  DWORD DStack_21c;
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c04011e8;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_224);
  if (LVar1 == 0) {
    local_220 = 0x200;
    local_228 = (HKEY)0x0;
    LVar1 = RegQueryValueExW(local_224,L"Key",(LPDWORD)0x0,&DStack_21c,(LPBYTE)aWStack_218,
                             &local_220);
    if (LVar1 == 0) {
      LVar1 = RegOpenKeyExW((HKEY)0x80000002,aWStack_218,0,0,&local_228);
      if (LVar1 != 0) {
        local_228 = (HKEY)0x0;
      }
    }
    RegCloseKey(local_224);
    FUN_c0400008(local_18);
  }
  else {
    FUN_c0400008(local_18);
    local_228 = (HKEY)0x0;
  }
  return local_228;
}



/* c03f3318 WAM_Open */

/* Boundary evidence: original MIPS .pdata c03f3318..c03f335b. Semantic name remains unreviewed. */

undefined4 * WAM_Open(void)

{
  undefined4 *puVar1;
  
                    /* 0x3318  5  WAM_Open */
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_c03f207c;
    puVar1[1] = 0;
    puVar1[2] = 1;
  }
  return puVar1;
}



/* c03f335c WAM_Close */

/* Boundary evidence: original MIPS .pdata c03f335c..c03f3397. Semantic name remains unreviewed. */

undefined4 WAM_Close(int *param_1)

{
                    /* 0x335c  1  WAM_Close */
  FUN_c03fa8dc((int)param_1);
  (**(code **)(*param_1 + 8))(param_1);
  return 1;
}



/* c03f3398 WAM_Deinit */

/* Boundary evidence: original MIPS .pdata c03f3398..c03f340f. Semantic name remains unreviewed. */

undefined4 WAM_Deinit(void)

{
                    /* 0x3398  2  WAM_Deinit */
  if (DAT_c0401200 != 0) {
    FreeLibrary((HMODULE)DAT_c0401200);
  }
  FUN_c03f640c();
  FUN_c03ffd4c();
  if (DAT_c04011f0 != (void *)0x0) {
    operator_delete(DAT_c04011f0);
  }
  if (DAT_c0401214 != (void *)0x0) {
    operator_delete(DAT_c0401214);
  }
  return 1;
}



/* c03f3410 WAM_IOControl */

/* Boundary evidence: original MIPS .pdata c03f3410..c03f4593. Semantic name remains unreviewed. */

undefined4 WAM_IOControl(int param_1,uint param_2,void *param_3,uint param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_50 [4];
  undefined4 local_40;
  wchar_t *local_38;
  HMODULE local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  undefined4 *local_1c;
  
                    /* 0x3410  3  WAM_IOControl */
  if (0x20 < param_4) {
    SetLastError(0x57);
    return 0;
  }
  if ((param_3 != (void *)0x0) && (param_4 != 0)) {
    memcpy(&local_38,param_3,param_4);
  }
  if (param_2 < 0x1d0341) {
    if (param_2 == 0x1d0340) {
      iVar1 = FUN_c03fc9bc(param_1,(uint)local_38,(int)local_34,local_30);
    }
    else if (param_2 < 0x1d0215) {
      if (param_2 == 0x1d0214) {
        iVar1 = FUN_c03ffd4c();
      }
      else if (param_2 < 0x1d01d5) {
        if (param_2 == 0x1d01d4) {
          iVar1 = FUN_c03ffd4c();
        }
        else if (param_2 < 0x1d01c1) {
          if (param_2 == 0x1d01c0) {
            iVar1 = FUN_c03ffd4c();
          }
          else if (param_2 == 0x1d0004) {
            iVar1 = FUN_c03f721c(local_38,(uint)local_34);
          }
          else if (param_2 == 0x1d0008) {
            iVar1 = FUN_c03f6ee4(local_38,local_34,local_30);
          }
          else {
            if (param_2 == 0x1d0010) {
              local_50[0] = 0x14;
              local_40 = 0;
              uVar2 = GetDirectCallerProcessId();
              iVar1 = OpenMsgQueue(uVar2,local_38,local_50);
              if (iVar1 != 0) {
                *(int *)(param_1 + 4) = iVar1;
                return 1;
              }
              SetLastError(0x57);
              return 0;
            }
            if (param_2 == 0x1d01b8) {
              iVar1 = FUN_c03ffd4c();
            }
            else {
              if (param_2 != 0x1d01bc) {
                return 0;
              }
              iVar1 = FUN_c03ffd4c();
            }
          }
        }
        else if (param_2 == 0x1d01c4) {
          iVar1 = FUN_c03ffd4c();
        }
        else if (param_2 == 0x1d01c8) {
          iVar1 = FUN_c03ffd4c();
        }
        else if (param_2 == 0x1d01cc) {
          iVar1 = FUN_c03ffd4c();
        }
        else {
          if (param_2 != 0x1d01d0) {
            return 0;
          }
          iVar1 = FUN_c03ffd4c();
        }
      }
      else {
        switch(param_2) {
        case 0x1d01d8:
          iVar1 = FUN_c03ffd4c();
          break;
        default:
LAB_c03f456c:
          return 0;
        case 0x1d01e0:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d01e4:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d01e8:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d01ec:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d01f0:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d0208:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d020c:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d0210:
          iVar1 = FUN_c03ffd4c();
        }
      }
    }
    else if (param_2 < 0x1d0259) {
      if (param_2 == 0x1d0258) {
        iVar1 = FUN_c03ffd4c();
      }
      else {
        switch(param_2) {
        case 0x1d0218:
          iVar1 = FUN_c03ffd4c();
          break;
        default:
          goto LAB_c03f456c;
        case 0x1d021c:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d0230:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d0234:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d0238:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d023c:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d0240:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d0244:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d0248:
          iVar1 = FUN_c03ffd4c();
          break;
        case 0x1d024c:
          iVar1 = FUN_c03ffd4c();
        }
      }
    }
    else if (param_2 < 0x1d032d) {
      if (param_2 == 0x1d032c) {
        iVar1 = FUN_c03fc664(param_1,(uint)local_38,(int)local_34,local_30);
      }
      else if (param_2 == 0x1d025c) {
        iVar1 = FUN_c03ffd4c();
      }
      else if (param_2 == 0x1d0320) {
        iVar1 = FUN_c03fc584(param_1,(uint)local_38,(int)local_34,local_30);
      }
      else if (param_2 == 0x1d0324) {
        iVar1 = FUN_c03f8c8c(param_1,3,(uint)local_38,(int)local_34,local_30);
      }
      else {
        if (param_2 != 0x1d0328) {
          return 0;
        }
        iVar1 = FUN_c03fbe10(param_1,(uint)local_38,(int)local_34,local_30);
      }
    }
    else if (param_2 == 0x1d0330) {
      iVar1 = FUN_c03fbf30(param_1,(uint)local_38,(int)local_34,local_30);
    }
    else if (param_2 == 0x1d0334) {
      iVar1 = audmGetNumMixerDevices();
    }
    else if (param_2 == 0x1d0338) {
      iVar1 = FUN_c03f8a58(param_1,3,(uint)local_38,(uint)local_34,local_30,local_2c);
    }
    else {
      if (param_2 != 0x1d033c) {
        return 0;
      }
      iVar1 = FUN_c03fc0c8(param_1,(int)local_38,(uint)local_34,local_30,local_2c,local_28);
    }
    goto LAB_c03f4108;
  }
  if (param_2 < 0x260011) {
    if (param_2 == 0x260010) {
      iVar1 = FUN_c03f8ef8(param_1,2,(uint)local_38,(int)local_34,local_30);
      goto LAB_c03f4108;
    }
    if (param_2 < 0x250029) {
      if (param_2 == 0x250028) {
        iVar1 = FUN_c03f97f0(param_1,1,(uint)local_38,(int)local_34,local_30);
        goto LAB_c03f4108;
      }
      if (0x250014 < param_2) {
        if (param_2 == 0x250018) {
          iVar1 = audmGetNumInputDevices();
        }
        else if (param_2 == 0x25001c) {
          iVar1 = FUN_c03f91c4(param_1,1,(uint)local_38,(int)local_34,local_30);
        }
        else if (param_2 == 0x250020) {
          iVar1 = FUN_c03f8a58(param_1,1,(uint)local_38,(uint)local_34,local_30,local_2c);
        }
        else {
          if (param_2 != 0x250024) {
            return 0;
          }
          iVar1 = FUN_c03f9428(param_1,1,(int)local_38,(uint)local_34,local_30,local_2c,local_28);
        }
        goto LAB_c03f4108;
      }
      if (param_2 == 0x250014) {
        uVar3 = 1;
        goto LAB_c03f4264;
      }
      if (param_2 == 0x1d0344) {
        uVar3 = 3;
      }
      else {
        if (param_2 == 0x250004) {
          iVar1 = FUN_c03fa2f0(param_1,1,(uint)local_38,(int)local_34,local_30);
          goto LAB_c03f4108;
        }
        if (param_2 != 0x250008) {
          if (param_2 == 0x25000c) {
            iVar1 = FUN_c03f8c8c(param_1,1,(uint)local_38,(int)local_34,local_30);
          }
          else {
            if (param_2 != 0x250010) {
              return 0;
            }
            iVar1 = FUN_c03f8ef8(param_1,1,(uint)local_38,(int)local_34,local_30);
          }
          goto LAB_c03f4108;
        }
        uVar3 = 1;
      }
    }
    else {
      if (param_2 < 0x25003d) {
        if (param_2 == 0x25003c) {
          iVar1 = FUN_c03f9ca8(param_1,1,(uint)local_38,(int)local_34,local_30,local_2c,local_28,
                               local_24,local_20,(undefined4 *)0x0,0);
          goto LAB_c03f4108;
        }
        if (param_2 != 0x25002c) {
          if (param_2 == 0x250030) {
            iVar1 = FUN_c03fba30(param_1,(uint)local_38);
          }
          else if (param_2 == 0x250034) {
            iVar1 = FUN_c03fbaa4(param_1,(uint)local_38);
          }
          else {
            if (param_2 != 0x250038) {
              return 0;
            }
            iVar1 = FUN_c03fa128(param_1,1,(uint)local_38,(int)local_34,local_30);
          }
          goto LAB_c03f4108;
        }
        uVar3 = 1;
        goto LAB_c03f43b8;
      }
      if (param_2 == 0x250040) {
        iVar1 = FUN_c03f9ca8(param_1,1,(uint)local_38,(int)local_34,local_30,local_2c,local_28,
                             local_24,local_20,local_1c,1);
        goto LAB_c03f4108;
      }
      if (param_2 == 0x260004) {
        iVar1 = FUN_c03fac9c(param_1,(uint)local_38);
        goto LAB_c03f4108;
      }
      if (param_2 != 0x260008) {
        if (param_2 != 0x26000c) {
          return 0;
        }
        iVar1 = FUN_c03f8c8c(param_1,2,(uint)local_38,(int)local_34,local_30);
        goto LAB_c03f4108;
      }
      uVar3 = 2;
    }
    iVar1 = FUN_c03f88d4(param_1,uVar3,(uint)local_38);
  }
  else {
    switch(param_2) {
    case 0x260014:
      uVar3 = 2;
LAB_c03f4264:
      iVar1 = FUN_c03f9064(param_1,uVar3,(uint)local_38,(int)local_34);
      break;
    default:
      goto LAB_c03f456c;
    case 0x260018:
      iVar1 = audmGetNumOutputDevices();
      break;
    case 0x26001c:
      iVar1 = FUN_c03fb314(param_1,(uint)local_38,(int)local_34);
      break;
    case 0x260020:
      iVar1 = FUN_c03fb460(param_1,(uint)local_38,(int)local_34);
      break;
    case 0x260024:
      iVar1 = FUN_c03f91c4(param_1,2,(uint)local_38,(int)local_34,local_30);
      break;
    case 0x260028:
      iVar1 = FUN_c03fb5ac(param_1,(uint)local_38,(int)local_34);
      break;
    case 0x26002c:
      iVar1 = FUN_c03f8a58(param_1,2,(uint)local_38,(uint)local_34,local_30,local_2c);
      break;
    case 0x260030:
      iVar1 = FUN_c03f9428(param_1,2,(int)local_38,(uint)local_34,local_30,local_2c,local_28);
      break;
    case 0x260034:
      iVar1 = FUN_c03fad10(param_1,(uint)local_38);
      break;
    case 0x260038:
      iVar1 = FUN_c03f97f0(param_1,2,(uint)local_38,(int)local_34,local_30);
      break;
    case 0x26003c:
      uVar3 = 2;
LAB_c03f43b8:
      iVar1 = FUN_c03f8c0c(param_1,uVar3,(uint)local_38);
      break;
    case 0x260040:
      iVar1 = FUN_c03fad84(param_1,(uint)local_38);
      break;
    case 0x260044:
      iVar1 = FUN_c03fadf8(param_1,(uint)local_38,local_34);
      break;
    case 0x260048:
      iVar1 = FUN_c03fae70(param_1,(uint)local_38,local_34);
      break;
    case 0x26004c:
      iVar1 = FUN_c03fb764(param_1,(uint)local_38,(int)local_34);
      break;
    case 0x260050:
      iVar1 = FUN_c03fa128(param_1,2,(uint)local_38,(int)local_34,local_30);
      break;
    case 0x260054:
      iVar1 = FUN_c03fa2f0(param_1,2,(uint)local_38,(int)local_34,local_30);
      break;
    case 0x260058:
      iVar1 = FUN_c03f9ca8(param_1,2,(uint)local_38,(int)local_34,local_30,local_2c,local_28,
                           local_24,local_20,(undefined4 *)0x0,0);
      break;
    case 0x26005c:
      iVar1 = FUN_c03f9ca8(param_1,2,(uint)local_38,(int)local_34,local_30,local_2c,local_28,
                           local_24,local_20,local_1c,1);
    }
  }
LAB_c03f4108:
  *param_5 = iVar1;
  return 1;
}



/* c03f4594 FUN_c03f4594 */

/* Boundary evidence: original MIPS .pdata c03f4594..c03f459f. Semantic name remains unreviewed. */

undefined4 FUN_c03f4594(void)

{
  return 1;
}



/* c03f45a0 FUN_c03f45a0 */

/* Boundary evidence: original MIPS .pdata c03f45a0..c03f464b. Semantic name remains unreviewed. */

int FUN_c03f45a0(int param_1,int param_2)

{
  int iVar1;
  int local_10 [2];
  
  if (param_1 == 1) {
    iVar1 = DAT_c0401214;
    if (param_2 == -1) {
LAB_c03f45cc:
      local_10[0] = iVar1;
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + iVar1 + 4) + 4))();
      return local_10[0];
    }
    iVar1 = audmGetInputDevice(param_2,local_10);
  }
  else {
    iVar1 = DAT_c04011f0;
    if (param_2 == -1) goto LAB_c03f45cc;
    iVar1 = audmGetOutputDevice(param_2,local_10);
  }
  if (iVar1 < 0) {
    local_10[0] = 0;
  }
  return local_10[0];
}



/* c03f464c FUN_c03f464c */

undefined4 * FUN_c03f464c(undefined4 *param_1,int param_2)

{
  if (param_2 != 0) {
    param_1[1] = &DAT_c03f20ec;
    param_1[7] = &DAT_c03f20e4;
    param_1[6] = &PTR_LAB_c03f2094;
    *(undefined ***)((int)(param_1 + 6) + *(int *)(param_1[7] + 4) + 4) = &PTR_LAB_c03f2088;
  }
  *param_1 = &PTR_FUN_c03f20e0;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c03f20d4;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c03f20c4;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xc;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x14;
  param_1[2] = 1;
  return param_1;
}



/* c03f4708 FUN_c03f4708 */

void FUN_c03f4708(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03f20e0;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c03f20d4;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c03f20c4;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xc;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x14;
  return;
}



/* c03f4780 FUN_c03f4780 */

/* Boundary evidence: original MIPS .pdata c03f4780..c03f479b. Semantic name remains unreviewed. */

void FUN_c03f4780(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + -8));
  return;
}



/* c03f47a8 FUN_c03f47a8 */

/* Boundary evidence: original MIPS .pdata c03f47a8..c03f4803. Semantic name remains unreviewed. */

LONG FUN_c03f47a8(int param_1)

{
  LONG LVar1;
  undefined4 *puVar2;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + -8));
  if ((LVar1 == 0) && (puVar2 = (undefined4 *)(param_1 + -0x10), puVar2 != (undefined4 *)0x0)) {
    (**(code **)*puVar2)(puVar2,1);
  }
  return LVar1;
}



/* c03f48c0 FUN_c03f48c0 */

/* Boundary evidence: original MIPS .pdata c03f48c0..c03f4993. Semantic name remains unreviewed. */

int FUN_c03f48c0(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 1;
  iVar1 = -0x7ff8ff49;
  if (*piVar2 == 0) {
    iVar1 = CeOpenCallerBuffer(piVar2,param_2,param_3,param_4,param_5);
    if (-1 < iVar1) {
      *param_1 = 0;
      param_1[2] = param_2;
      param_1[3] = param_3;
      param_1[4] = param_4;
      if ((param_6 != 0) &&
         (iVar1 = CeAllocAsynchronousBuffer(param_1,*piVar2,param_3,param_4), iVar1 < 0)) {
        FUN_c03f28a8(param_1);
      }
    }
  }
  return iVar1;
}



/* c03f4994 FUN_c03f4994 */

/* Boundary evidence: original MIPS .pdata c03f4994..c03f49f3. Semantic name remains unreviewed. */

undefined4 * FUN_c03f4994(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c03f207c;
  if (param_1[1] != 0) {
    CloseMsgQueue();
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03f49f4 FUN_c03f49f4 */

/* Boundary evidence: original MIPS .pdata c03f49f4..c03f4adb. Semantic name remains unreviewed. */

int * FUN_c03f49f4(int *param_1,int param_2)

{
  if (param_2 != 0) {
    *param_1 = (int)&DAT_c03f212c;
    param_1[7] = (int)&DAT_c03f2118;
    param_1[5] = (int)&DAT_c03f2124;
    param_1[4] = (int)&PTR_LAB_c03f2094;
    *(undefined ***)((int)(param_1 + 4) + *(int *)(param_1[5] + 4) + 4) = &PTR_LAB_c03f2088;
    FUN_c03f464c(param_1 + 6,0);
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &PTR_LAB_c03f210c;
  *(undefined ***)(*(int *)(*param_1 + 8) + (int)param_1) = &PTR_LAB_c03f20fc;
  *(undefined ***)(*(int *)(*param_1 + 0xc) + (int)param_1) = &PTR_FUN_c03f20f8;
  *(undefined4 *)((int)param_1 + *(int *)(*param_1 + 4) + -4) = 0;
  *(undefined4 *)((int)param_1 + *(int *)(*param_1 + 8) + -4) = 0;
  return param_1;
}



/* c03f4be4 FUN_c03f4be4 */

/* Boundary evidence: original MIPS .pdata c03f4be4..c03f4ccb. Semantic name remains unreviewed. */

int * FUN_c03f4be4(int *param_1,int param_2)

{
  if (param_2 != 0) {
    *param_1 = (int)&DAT_c03f2170;
    param_1[7] = (int)&DAT_c03f215c;
    param_1[5] = (int)&DAT_c03f2168;
    param_1[4] = (int)&PTR_LAB_c03f2094;
    *(undefined ***)((int)(param_1 + 4) + *(int *)(param_1[5] + 4) + 4) = &PTR_LAB_c03f2088;
    FUN_c03f464c(param_1 + 6,0);
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &PTR_LAB_c03f2150;
  *(undefined ***)(*(int *)(*param_1 + 8) + (int)param_1) = &PTR_LAB_c03f2140;
  *(undefined ***)(*(int *)(*param_1 + 0xc) + (int)param_1) = &PTR_FUN_c03f213c;
  *(undefined4 *)((int)param_1 + *(int *)(*param_1 + 4) + -4) = 0;
  *(undefined4 *)((int)param_1 + *(int *)(*param_1 + 8) + -4) = 0;
  return param_1;
}



/* c03f4ce4 FUN_c03f4ce4 */

/* Boundary evidence: original MIPS .pdata c03f4ce4..c03f4eb3. Semantic name remains unreviewed. */

HLOCAL FUN_c03f4ce4(int param_1)

{
  short *psVar1;
  HLOCAL _Dst;
  ushort uVar2;
  size_t _Size;
  SIZE_T uBytes;
  short *local_38;
  short *local_34;
  undefined4 local_2c;
  
  _Dst = (HLOCAL)0x0;
  local_34 = (short *)0x0;
  local_38 = (short *)0x0;
  local_2c = 0;
  FUN_c03f48c0((int *)&local_38,param_1,0x12,4,0,0);
  psVar1 = local_38;
  if ((local_38 != (short *)0x0) || (psVar1 = local_34, local_34 != (short *)0x0)) {
    if (*psVar1 == 1) {
      uVar2 = 0;
      _Size = 0x10;
      uBytes = 0x12;
    }
    else {
      uVar2 = psVar1[8];
      _Size = uVar2 + 0x12;
      uBytes = _Size;
    }
    FUN_c03f28a8((int *)&local_38);
    FUN_c03f48c0((int *)&local_38,param_1,_Size,4,0,0);
    psVar1 = local_38;
    if (((local_38 != (short *)0x0) || (psVar1 = local_34, local_34 != (short *)0x0)) &&
       (_Dst = LocalAlloc(0,uBytes), _Dst != (HLOCAL)0x0)) {
      memcpy(_Dst,psVar1,_Size);
      *(char *)((int)_Dst + 0x10) = (char)uVar2;
      *(char *)((int)_Dst + 0x11) = (char)(uVar2 >> 8);
    }
  }
  FUN_c03f28a8((int *)&local_38);
  return _Dst;
}



/* c03f4eb4 FUN_c03f4eb4 */

/* Boundary evidence: original MIPS .pdata c03f4eb4..c03f4ebf. Semantic name remains unreviewed. */

undefined4 FUN_c03f4eb4(void)

{
  return 1;
}



/* c03f4ec0 FUN_c03f4ec0 */

/* Boundary evidence: original MIPS .pdata c03f4ec0..c03f4f5b. Semantic name remains unreviewed. */

undefined4 * FUN_c03f4ec0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c03f20e0;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c03f20d4;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c03f20c4;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xc;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x14;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03f4f5c FUN_c03f4f5c */

/* Boundary evidence: original MIPS .pdata c03f4f5c..c03f5077. Semantic name remains unreviewed. */

undefined4 FUN_c03f4f5c(void)

{
  int iVar1;
  int *piVar2;
  LPCRITICAL_SECTION p_Var3;
  
  iVar1 = FUN_c03ffd4c();
  if (iVar1 != 0) {
    piVar2 = operator_new(0x24);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = FUN_c03f49f4(piVar2,1);
    }
    if (piVar2 == (int *)0x0) {
      DAT_c04011f0 = 0;
    }
    else {
      DAT_c04011f0 = *(int *)(*piVar2 + 8) + (int)piVar2;
      if (DAT_c04011f0 != 0) {
        piVar2 = operator_new(0x24);
        if (piVar2 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_c03f4be4(piVar2,1);
        }
        if (piVar2 == (int *)0x0) {
          DAT_c0401214 = 0;
        }
        else {
          DAT_c0401214 = *(int *)(*piVar2 + 8) + (int)piVar2;
          if (DAT_c0401214 != 0) {
            p_Var3 = operator_new(0xa0);
            if (p_Var3 == (LPCRITICAL_SECTION)0x0) {
              DAT_c04011f8 = (LPCRITICAL_SECTION)0x0;
            }
            else {
              DAT_c04011f8 = FUN_c03faee8(p_Var3);
            }
            if (DAT_c04011f8 != (LPCRITICAL_SECTION)0x0) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}



/* c03f5078 FUN_c03f5078 */

/* Boundary evidence: original MIPS .pdata c03f5078..c03f5113. Semantic name remains unreviewed. */

undefined4 * FUN_c03f5078(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c03f20e0;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c03f20d4;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c03f20c4;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xc;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x14;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1 + -6);
  }
  return param_1 + -6;
}



/* c03f5114 FUN_c03f5114 */

/* Boundary evidence: original MIPS .pdata c03f5114..c03f51af. Semantic name remains unreviewed. */

undefined4 * FUN_c03f5114(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c03f20e0;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c03f20d4;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 8) + 4) = &PTR_LAB_c03f20c4;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xc;
  *(int *)(*(int *)(param_1[1] + 8) + (int)param_1) = *(int *)(param_1[1] + 8) + -0x14;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1 + -6);
  }
  return param_1 + -6;
}



/* c03f51b0 WAM_Init */

/* Boundary evidence: original MIPS .pdata c03f51b0..c03f53df. Semantic name remains unreviewed. */

undefined4 WAM_Init(LPCWSTR param_1)

{
  HKEY pHVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 local_88;
  DWORD local_84;
  DWORD local_80 [4];
  WCHAR aWStack_70 [40];
  uint local_20;
  
                    /* 0x51b0  4  WAM_Init */
  local_20 = DAT_c04011e8;
  FUN_c03f4f5c();
  DAT_c0401208 = 0;
  DAT_c0401218 = 0;
  local_88 = 0xfa;
  pHVar1 = (HKEY)OpenDeviceKey(param_1);
  if (pHVar1 != (HKEY)0x0) {
    local_80[1] = 4;
    RegQueryValueExW(pHVar1,L"Priority256",(LPDWORD)0x0,local_80 + 2,(LPBYTE)&local_88,local_80 + 1)
    ;
    RegCloseKey(pHVar1);
  }
  DAT_c0401204 = local_88;
  iVar2 = FUN_c03f7ad8();
  if (iVar2 != 0) {
    DAT_c0401250 = 1;
    FUN_c03f727c();
    DAT_c0401250 = 0;
    iVar2 = audmInitialize(FUN_c03f29f8);
    if (-1 < iVar2) {
      FUN_c03ffd4c();
      FUN_c03fcc68(DAT_c040120c);
      pHVar1 = FUN_c03f3218(param_1);
      if (pHVar1 != (HKEY)0x0) {
        local_84 = 0x50;
        LVar3 = RegQueryValueExW(pHVar1,L"PlaySoundHookDll",(LPDWORD)0x0,local_80,(LPBYTE)aWStack_70
                                 ,&local_84);
        if ((LVar3 == 0) && (local_80[0] == 1)) {
          DAT_c0401200 = LoadLibraryW(aWStack_70);
          if (DAT_c0401200 == (HMODULE)0x0) {
            DAT_c04011fc = 0;
            DAT_c0401210 = 0;
            DAT_c04011f4 = 0;
          }
          else {
            DAT_c04011fc = GetProcAddressW(DAT_c0401200,L"PlaySoundHookStart");
            DAT_c0401210 = GetProcAddressW(DAT_c0401200,L"PlaySoundHookStop");
            DAT_c04011f4 = GetProcAddressW(DAT_c0401200,L"PlaySoundHookUpdate");
          }
        }
        RegCloseKey(pHVar1);
      }
      FUN_c0400008(local_20);
      return 1;
    }
  }
  FUN_c0400008(local_20);
  return 0;
}



/* c03f53e0 FUN_c03f53e0 */

/* Boundary evidence: original MIPS .pdata c03f53e0..c03f5627. Semantic name remains unreviewed. */

uint FUN_c03f53e0(uint param_1,uint *param_2,LPDWORD param_3,uint param_4)

{
  uint uVar1;
  HWAVEOUT pHVar2;
  
  if (param_1 < 0x2016) {
    if (param_1 == 0x2015) {
      uVar1 = FUN_c03fe294(0,param_3);
      return uVar1;
    }
    switch(param_1) {
    case 3:
      uVar1 = 1;
      break;
    case 4:
      uVar1 = FUN_c03fcaf0(0,param_3,param_4);
      break;
    case 5:
      uVar1 = FUN_c03fd940(0,param_2,param_3,param_4);
      break;
    case 6:
      uVar1 = FUN_c03fd8e0(param_2);
      break;
    case 7:
      uVar1 = FUN_c03fdd20((int)param_2,param_3);
      break;
    case 8:
      uVar1 = FUN_c03fdfa8((int)param_2,(int)param_3);
      break;
    case 9:
      uVar1 = FUN_c03fe0c0((int)param_2,param_3);
      break;
    case 10:
      uVar1 = waveOutPause((HWAVEOUT)param_2[0x11]);
      break;
    case 0xb:
      uVar1 = waveOutRestart((HWAVEOUT)param_2[0x11]);
      break;
    case 0xc:
      uVar1 = waveOutReset((HWAVEOUT)param_2[0x11]);
      break;
    case 0xd:
      uVar1 = FUN_c03fcd60((int)param_2,(int *)param_3,param_4);
      break;
    case 0xe:
      uVar1 = waveOutGetPitch((HWAVEOUT)param_2[0x11],param_3);
      break;
    case 0xf:
      uVar1 = waveOutSetPitch((HWAVEOUT)param_2[0x11],(DWORD)param_3);
      break;
    case 0x10:
      pHVar2 = (HWAVEOUT)0x0;
      if (param_2 != (uint *)0x0) {
        pHVar2 = (HWAVEOUT)param_2[0x11];
      }
      uVar1 = waveOutGetVolume(pHVar2,param_3);
      break;
    case 0x11:
      pHVar2 = (HWAVEOUT)0x0;
      if (param_2 != (uint *)0x0) {
        pHVar2 = (HWAVEOUT)param_2[0x11];
      }
      uVar1 = waveOutSetVolume(pHVar2,(DWORD)param_3);
      break;
    case 0x12:
      uVar1 = waveOutGetPlaybackRate((HWAVEOUT)param_2[0x11],param_3);
      break;
    case 0x13:
      uVar1 = waveOutSetPlaybackRate((HWAVEOUT)param_2[0x11],(DWORD)param_3);
      break;
    case 0x14:
      uVar1 = waveOutBreakLoop((HWAVEOUT)param_2[0x11]);
      break;
    default:
      goto switchD_c03f542c_default;
    }
  }
  else {
    if (param_1 == 0x2016) {
      uVar1 = audmSetOutputDeviceId(param_3,param_4);
      return uVar1;
    }
switchD_c03f542c_default:
    if ((param_2 == (uint *)0x0) || ((HWAVEOUT)param_2[0x11] == (HWAVEOUT)0x0)) {
      uVar1 = 8;
    }
    else {
      uVar1 = waveOutMessage((HWAVEOUT)param_2[0x11],param_1,(DWORD_PTR)param_3,param_4);
    }
  }
  return uVar1;
}



/* c03f5628 FUN_c03f5628 */

/* Boundary evidence: original MIPS .pdata c03f5628..c03f56f7. Semantic name remains unreviewed. */

uint FUN_c03f5628(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1[8];
  uVar1 = FUN_c03fd7b4(param_1);
  if (uVar1 == 0) {
    if ((uVar2 & 1) == 0) {
      uVar1 = FUN_c03ffd4c();
      if (uVar1 != 0) {
        (*(code *)param_1[0x13])(param_1[0x11]);
        FUN_c03ffd4c();
        if (uVar1 < 0x20) {
          return uVar1;
        }
        return 0x20;
      }
    }
    else {
      FUN_c03ffd4c();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* c03f56f8 FUN_c03f56f8 */

/* Boundary evidence: original MIPS .pdata c03f56f8..c03f57cb. Semantic name remains unreviewed. */

undefined4 FUN_c03f56f8(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)param_1[3];
  iVar1 = puVar3[7];
  puVar2 = (undefined4 *)(iVar1 + 0x24);
  iVar4 = *(int *)(iVar1 + 8);
  *puVar2 = 0;
  if (param_1[2] != 0) {
    *(undefined4 *)(iVar1 + 0xc) = *param_1;
    *(undefined4 *)(iVar1 + 0x10) = param_1[2];
    *(undefined4 *)(iVar1 + 0x1c) = *puVar3;
    iVar1 = FUN_c03ffd4c();
    if (iVar1 != 0) {
      *puVar2 = 0;
    }
  }
  puVar3[2] = *puVar2;
  puVar3[4] = puVar3[4] & 0xffffffef | 1;
  FUN_c03fcc84(iVar4,0x3c0,puVar3,0);
  return 0;
}



/* c03f57cc FUN_c03f57cc */

/* Boundary evidence: original MIPS .pdata c03f57cc..c03f596f. Semantic name remains unreviewed. */

uint FUN_c03f57cc(uint param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  
  if (param_1 < 0x2016) {
    if (param_1 == 0x2015) {
      uVar1 = FUN_c03fe294(1,param_3);
      return uVar1;
    }
    switch(param_1) {
    case 0x32:
      uVar1 = 1;
      break;
    case 0x33:
      uVar1 = FUN_c03fcaf0(1,param_3,param_4);
      break;
    case 0x34:
      uVar1 = FUN_c03fd940(1,param_2,param_3,param_4);
      break;
    case 0x35:
      uVar1 = FUN_c03fd8e0(param_2);
      break;
    case 0x36:
      uVar1 = FUN_c03fdd20((int)param_2,param_3);
      break;
    case 0x37:
      uVar1 = FUN_c03fdfa8((int)param_2,(int)param_3);
      break;
    case 0x38:
      uVar1 = FUN_c03fe0c0((int)param_2,param_3);
      break;
    case 0x39:
      uVar1 = waveInStart((HWAVEIN)param_2[0x11]);
      break;
    case 0x3a:
      uVar1 = waveInStop((HWAVEIN)param_2[0x11]);
      break;
    case 0x3b:
      uVar1 = waveInReset((HWAVEIN)param_2[0x11]);
      break;
    case 0x3c:
      uVar1 = FUN_c03fcd60((int)param_2,(int *)param_3,param_4);
      break;
    default:
      goto switchD_c03f5818_default;
    }
  }
  else {
    if (param_1 == 0x2016) {
      uVar1 = audmSetInputDeviceId(param_3,param_4);
      return uVar1;
    }
switchD_c03f5818_default:
    if ((param_2 == (uint *)0x0) || ((HWAVEIN)param_2[0x11] == (HWAVEIN)0x0)) {
      uVar1 = 8;
    }
    else {
      uVar1 = waveInMessage((HWAVEIN)param_2[0x11],param_1,(DWORD_PTR)param_3,param_4);
    }
  }
  return uVar1;
}



/* c03f5970 FUN_c03f5970 */

/* Boundary evidence: original MIPS .pdata c03f5970..c03f59db. Semantic name remains unreviewed. */

void FUN_c03f5970(void)

{
  DWORD DVar1;
  DWORD dwMilliseconds;
  uint uVar2;
  
  uVar2 = (DAT_c0401364 + 0x32) * 2;
  DVar1 = GetTickCount();
  dwMilliseconds = uVar2 - (DVar1 - DAT_c0401368);
  if (uVar2 <= DVar1 - DAT_c0401368) {
    dwMilliseconds = 0;
  }
  WaitForSingleObject(DAT_c0401354,dwMilliseconds);
  return;
}



/* c03f59dc FUN_c03f59dc */

undefined4 FUN_c03f59dc(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if (param_1 != 4) {
    if (param_1 == 6) {
      return 0x7d1;
    }
    if (param_1 == 7) {
      return 8;
    }
    if ((param_1 == 8) || (param_1 == 0x20)) {
      return 0xb;
    }
    if (param_1 != 0x21) {
      return 0x1f;
    }
  }
  return 0xaa;
}



/* c03f5a60 FUN_c03f5a60 */

void FUN_c03f5a60(int param_1)

{
  DAT_c0401248 = (uint)(param_1 != 1);
  return;
}



/* c03f5a8c FUN_c03f5a8c */

/* Boundary evidence: original MIPS .pdata c03f5a8c..c03f5af7. Semantic name remains unreviewed. */

bool FUN_c03f5a8c(LPCWSTR param_1)

{
  HANDLE hObject;
  
  hObject = CreateFileW(param_1,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hObject != (HANDLE)0xffffffff) {
    CloseHandle(hObject);
  }
  return hObject != (HANDLE)0xffffffff;
}



/* c03f5af8 FUN_c03f5af8 */

/* Boundary evidence: original MIPS .pdata c03f5af8..c03f5c1f. Semantic name remains unreviewed. */

undefined4 FUN_c03f5af8(wchar_t *param_1,STRSAFE_LPWSTR param_2,size_t param_3,int *param_4)

{
  wchar_t wVar1;
  int iVar2;
  HRESULT HVar3;
  undefined **ppuVar4;
  int iVar5;
  
  if ((param_2 != (STRSAFE_LPWSTR)0x0) && (param_3 != 0)) {
    ppuVar4 = &PTR_u_SystemAsterisk_c03f2518;
    *param_2 = L'\0';
    iVar5 = 0;
    do {
      iVar2 = wcscmp((wchar_t *)*ppuVar4,param_1);
      if (iVar2 == 0) {
        iVar2 = (&DAT_c04012b4)[iVar5];
        if (iVar2 != 0) {
          *param_4 = iVar2;
          InterlockedIncrement((LONG *)((&DAT_c04012b4)[iVar5] + 0xc));
          return 3;
        }
        wVar1 = *(STRSAFE_LPCWSTR)(&DAT_c0401260)[iVar5];
        if ((wVar1 != L'\0') && (wVar1 != L' ')) {
          HVar3 = StringCchCopyW(param_2,param_3,(STRSAFE_LPCWSTR)(&DAT_c0401260)[iVar5]);
          if (HVar3 < 0) {
            return 0;
          }
          return 2;
        }
        return 1;
      }
      ppuVar4 = ppuVar4 + 1;
      iVar5 = iVar5 + 1;
    } while ((int)ppuVar4 < -0x3fc0da94);
  }
  return 0;
}



/* c03f5c20 FUN_c03f5c20 */

/* Boundary evidence: original MIPS .pdata c03f5c20..c03f5de3. Semantic name remains unreviewed. */

undefined4
FUN_c03f5c20(wchar_t *param_1,STRSAFE_LPWSTR param_2,size_t param_3,uint *param_4,int *param_5)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  HRESULT HVar3;
  undefined3 extraout_var_00;
  uint uVar4;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c04011e8;
  if ((*param_4 & 0x20000) == 0) {
    iVar2 = FUN_c03f5af8(param_1,param_2,param_3,param_5);
    if (iVar2 == 0) {
      if ((*param_4 & 0x10000) != 0) goto LAB_c03f5db4;
      *param_4 = *param_4 | 0x1000000;
      iVar2 = StringCchCopyW(param_2,param_3,param_1);
      goto joined_r0xc03f5d38;
    }
    if (iVar2 == 1) goto LAB_c03f5db4;
    if (iVar2 == 2) {
      *param_4 = *param_4 | 0x2000000;
    }
    else if (iVar2 == 3) {
      *param_4 = *param_4 | 0x2000000;
      goto LAB_c03f5cb8;
    }
  }
  else {
    *param_4 = *param_4 | 0x1000000;
    iVar2 = StringCchCopyW(param_2,param_3,param_1);
joined_r0xc03f5d38:
    if (iVar2 < 0) goto LAB_c03f5db4;
  }
  bVar1 = FUN_c03f5a8c(param_2);
  if (CONCAT31(extraout_var,bVar1) != 0) {
LAB_c03f5cb8:
    FUN_c0400008(local_20);
    return 1;
  }
  HVar3 = StringCchCopyW(awStack_228,0x104,param_2);
  if (-1 < HVar3) {
    uVar4 = 0;
    do {
      HVar3 = StringCchPrintfW(param_2,param_3,
                               *(STRSAFE_LPCWSTR *)((int)&PTR_u__s_wav_c04011c0 + uVar4),awStack_228
                              );
      if ((-1 < HVar3) && (bVar1 = FUN_c03f5a8c(param_2), CONCAT31(extraout_var_00,bVar1) != 0))
      goto LAB_c03f5cb8;
      uVar4 = uVar4 + 8;
    } while (uVar4 < 0x28);
  }
LAB_c03f5db4:
  FUN_c0400008(local_20);
  return 0;
}



/* c03f5de4 FUN_c03f5de4 */

/* Boundary evidence: original MIPS .pdata c03f5de4..c03f5ebf. Semantic name remains unreviewed. */

undefined4 FUN_c03f5de4(int *param_1,int param_2,int *param_3,uint *param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int local_20;
  int local_1c;
  
  if (*param_4 < param_5) {
    while (iVar1 = (**(code **)*param_1)(param_1,&local_20,8), iVar1 != 0) {
      *param_4 = *param_4 + 8;
      if (local_20 == param_2) {
        *param_3 = local_1c;
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 4))(param_1,local_1c);
      if (iVar1 == 0) {
        return 0xd;
      }
      uVar2 = *param_4;
      *param_4 = uVar2 + local_1c;
      if (param_5 <= uVar2 + local_1c) {
        return 0xd;
      }
    }
  }
  return 0xd;
}



/* c03f5ec0 FUN_c03f5ec0 */

/* Boundary evidence: original MIPS .pdata c03f5ec0..c03f5f73. Semantic name remains unreviewed. */

undefined4 FUN_c03f5ec0(undefined4 *param_1,undefined4 *param_2,uint param_3,int *param_4)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  if ((param_3 < 0x1000001) && (pvVar2 = operator_new(param_3), pvVar2 != (void *)0x0)) {
    iVar3 = (**(code **)*param_1)(param_1,pvVar2,param_3);
    if (iVar3 == 0) {
      uVar1 = 0xd;
    }
    else {
      *param_4 = *param_4 + param_3;
      uVar1 = 0;
      *param_2 = pvVar2;
    }
  }
  else {
    uVar1 = 0xe;
  }
  return uVar1;
}



/* c03f5f74 FUN_c03f5f74 */

/* Boundary evidence: original MIPS .pdata c03f5f74..c03f60f7. Semantic name remains unreviewed. */

int FUN_c03f5f74(undefined4 *param_1,int *param_2)

{
  int iVar1;
  uint local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  int local_20;
  
  iVar1 = (**(code **)*param_2)(param_2,&local_28,0xc);
  if (((iVar1 != 0) && (local_28 == 0x46464952)) && (local_20 == 0x45564157)) {
    local_30 = 0xc;
    iVar1 = FUN_c03f5de4(param_2,0x20746d66,(int *)&local_2c,&local_30,local_24);
    if (iVar1 == 0) {
      iVar1 = FUN_c03f5ec0(param_2,param_1,local_2c,(int *)&local_30);
      if (iVar1 != 0) {
        return iVar1;
      }
      if ((0xd < local_2c) &&
         ((*(short *)*param_1 == 1 ||
          ((0x11 < local_2c && ((ushort)((short *)*param_1)[8] + 0x12 <= local_2c)))))) {
        iVar1 = FUN_c03f5de4(param_2,0x61746164,param_1 + 2,&local_30,local_24);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_c03f5ec0(param_2,param_1 + 1,param_1[2],(int *)&local_30);
        return iVar1;
      }
    }
  }
  return 0xd;
}



/* c03f60f8 FUN_c03f60f8 */

/* Boundary evidence: original MIPS .pdata c03f60f8..c03f614b. Semantic name remains unreviewed. */

void FUN_c03f60f8(HMODULE param_1,LPCWSTR param_2)

{
  HRSRC hResInfo;
  
  hResInfo = FindResourceW(param_1,(LPCWSTR)((uint)param_2 & 0xffff),L"WAVE");
  LoadResource(param_1,hResInfo);
  return;
}



/* c03f614c FUN_c03f614c */

/* Boundary evidence: original MIPS .pdata c03f614c..c03f640b. Semantic name remains unreviewed. */

void FUN_c03f614c(HKEY param_1)

{
  LSTATUS LVar1;
  LPCWSTR pWVar2;
  DWORD local_38;
  LPCWSTR local_34;
  DWORD local_30 [2];
  
  local_30[0] = 4;
  if (DAT_c0401258 == 0) {
    DAT_c0401254 = 0;
  }
  else {
    if (DAT_c0401258 == 1) {
      LVar1 = RegQueryValueExW(param_1,L"KeySoft",(LPDWORD)0x0,&local_38,(LPBYTE)&local_34,local_30)
      ;
      if ((LVar1 == 0) && (local_38 == 4)) {
        DAT_c0401244 = local_34;
        DAT_c0401254 = FUN_c03f60f8(DAT_c040130c,local_34);
        if (DAT_c0401254 != 0) goto LAB_c03f62b8;
        DAT_c0401254 = 0;
      }
      else {
        DAT_c0401244 = (LPCWSTR)0x0;
      }
      pWVar2 = (LPCWSTR)0x65;
    }
    else {
      if (DAT_c0401258 != 2) goto LAB_c03f62b8;
      LVar1 = RegQueryValueExW(param_1,L"KeyLoud",(LPDWORD)0x0,&local_38,(LPBYTE)&local_34,local_30)
      ;
      if ((LVar1 == 0) && (local_38 == 4)) {
        DAT_c0401244 = local_34;
        DAT_c0401254 = FUN_c03f60f8(DAT_c040130c,local_34);
        if (DAT_c0401254 != 0) goto LAB_c03f62b8;
        DAT_c0401254 = 0;
      }
      else {
        DAT_c0401244 = (LPCWSTR)0x0;
      }
      pWVar2 = (LPCWSTR)0x64;
    }
    DAT_c0401254 = FUN_c03f60f8(DAT_c040120c,pWVar2);
  }
LAB_c03f62b8:
  local_30[0] = 4;
  if (DAT_c040123c == 0) {
    DAT_c0401240 = 0;
  }
  else {
    if (DAT_c040123c == 1) {
      LVar1 = RegQueryValueExW(param_1,L"TouchSoft",(LPDWORD)0x0,&local_38,(LPBYTE)&local_34,
                               local_30);
      if ((LVar1 == 0) && (local_38 == 4)) {
        DAT_c0401234 = local_34;
        DAT_c0401240 = FUN_c03f60f8(DAT_c040130c,local_34);
        if (DAT_c0401240 != 0) {
          return;
        }
        DAT_c0401240 = 0;
      }
      else {
        DAT_c0401234 = (LPCWSTR)0x0;
      }
      pWVar2 = (LPCWSTR)0x67;
    }
    else {
      if (DAT_c040123c != 2) {
        return;
      }
      LVar1 = RegQueryValueExW(param_1,L"TouchLoud",(LPDWORD)0x0,&local_38,(LPBYTE)&local_34,
                               local_30);
      if ((LVar1 == 0) && (local_38 == 4)) {
        DAT_c0401234 = local_34;
        DAT_c0401240 = FUN_c03f60f8(DAT_c040130c,local_34);
        if (DAT_c0401240 != 0) {
          return;
        }
        DAT_c0401240 = 0;
      }
      else {
        DAT_c0401234 = (LPCWSTR)0x0;
      }
      pWVar2 = (LPCWSTR)0x66;
    }
    DAT_c0401240 = FUN_c03f60f8(DAT_c040120c,pWVar2);
  }
  return;
}



/* c03f640c FUN_c03f640c */

/* Boundary evidence: original MIPS .pdata c03f640c..c03f642f. Semantic name remains unreviewed. */

undefined4 FUN_c03f640c(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
  return 1;
}



/* c03f6444 FUN_c03f6444 */

/* Boundary evidence: original MIPS .pdata c03f6444..c03f64b3. Semantic name remains unreviewed. */

bool FUN_c03f6444(int param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateFileW(param_2,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *(HANDLE *)(param_1 + 4) = pvVar1;
  return pvVar1 != (HANDLE)0xffffffff;
}



/* c03f64b4 FUN_c03f64b4 */

/* Boundary evidence: original MIPS .pdata c03f64b4..c03f6507. Semantic name remains unreviewed. */

undefined4 FUN_c03f64b4(int param_1,LPVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  DWORD local_10 [2];
  
  BVar1 = ReadFile(*(HANDLE *)(param_1 + 4),param_2,param_3,local_10,(LPOVERLAPPED)0x0);
  if ((BVar1 == 0) || (uVar2 = 1, local_10[0] != param_3)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03f6508 FUN_c03f6508 */

/* Boundary evidence: original MIPS .pdata c03f6508..c03f6557. Semantic name remains unreviewed. */

bool FUN_c03f6508(int param_1,LONG param_2)

{
  DWORD DVar1;
  
  DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 4),param_2,(PLONG)0x0,1);
  return DVar1 != 0xffffffff;
}



/* c03f6558 FUN_c03f6558 */

/* Boundary evidence: original MIPS .pdata c03f6558..c03f659b. Semantic name remains unreviewed. */

void FUN_c03f6558(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03f26e0;
  if ((HANDLE)param_1[1] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[1]);
  }
  return;
}



/* c03f659c FUN_c03f659c */

/* Boundary evidence: original MIPS .pdata c03f659c..c03f65e3. Semantic name remains unreviewed. */

void FUN_c03f659c(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
  }
  return;
}



/* c03f65e4 FUN_c03f65e4 */

/* Boundary evidence: original MIPS .pdata c03f65e4..c03f6693. Semantic name remains unreviewed. */

int FUN_c03f65e4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int local_28;
  int local_24;
  undefined4 local_1c;
  
  local_24 = 0;
  local_28 = 0;
  local_1c = 0;
  FUN_c03f48c0(&local_28,*(int *)(param_1 + 4),param_3,4,0,0);
  iVar1 = local_28;
  if ((local_28 == 0) && (iVar1 = local_24, local_24 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = CeSafeCopyMemory(param_2,iVar1,param_3);
    if (iVar1 != 0) {
      *(int *)(param_1 + 4) = param_3 + *(int *)(param_1 + 4);
    }
  }
  FUN_c03f28a8(&local_28);
  return iVar1;
}



/* c03f6694 FUN_c03f6694 */

/* Boundary evidence: original MIPS .pdata c03f6694..c03f66eb. Semantic name remains unreviewed. */

LONG FUN_c03f6694(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_c03f659c(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* c03f66ec FUN_c03f66ec */

/* Boundary evidence: original MIPS .pdata c03f66ec..c03f67e3. Semantic name remains unreviewed. */

void FUN_c03f66ec(void)

{
  MMRESULT MVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
  if (DAT_c0401210 != (code *)0x0) {
    (*DAT_c0401210)();
  }
  iVar2 = 0;
  do {
    MVar1 = waveOutUnprepareHeader(DAT_c0401348,(LPWAVEHDR)&DAT_c0401328,0x20);
    if (MVar1 != 0) {
      waveOutReset(DAT_c0401348);
      WaitForSingleObject(DAT_c0401350,0);
    }
    MVar1 = waveOutClose(DAT_c0401348);
    if (MVar1 == 0) break;
    Sleep(10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  if (DAT_c040134c != (undefined4 *)0x0) {
    FUN_c03f6694(DAT_c040134c);
  }
  DAT_c040134c = (undefined4 *)0x0;
  DAT_c0401348 = (HWAVEOUT)0x0;
  DAT_c0401324 = 0;
  EventModify(DAT_c0401354,3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
  return;
}



/* c03f67e4 FUN_c03f67e4 */

/* Boundary evidence: original MIPS .pdata c03f67e4..c03f6a03. Semantic name remains unreviewed. */

int FUN_c03f67e4(wchar_t *param_1,uint *param_2,int *param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined **local_230;
  undefined4 local_22c;
  undefined **local_228;
  wchar_t *local_224;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c04011e8;
  *param_3 = 0;
  if ((*param_2 & 4) == 0) {
    iVar3 = FUN_c03f5c20(param_1,awStack_220,0x104,param_2,param_3);
    if (iVar3 == 0) {
      if ((*param_2 & 2) != 0) {
LAB_c03f6918:
        FUN_c0400008(local_18);
        return 2;
      }
      *param_2 = *param_2 & 0xfffdffff | 0x10000;
      iVar3 = FUN_c03f5c20(L"SystemDefault",awStack_220,0x104,param_2,param_3);
      if (iVar3 == 0) goto LAB_c03f6918;
    }
    if (*param_3 != 0) {
      FUN_c0400008(local_18);
      return 0;
    }
    local_230 = &PTR_FUN_c03f26e0;
    local_22c = 0xffffffff;
    bVar1 = FUN_c03f6444((int)&local_230,awStack_220);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar3 = 2;
    }
    else {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[3] = 1;
      }
      if (puVar2 == (undefined4 *)0x0) {
        iVar3 = 0xe;
      }
      else {
        iVar3 = FUN_c03f5f74(puVar2,(int *)&local_230);
        if (iVar3 == 0) {
          *param_3 = (int)puVar2;
        }
        else {
          FUN_c03f6694(puVar2);
        }
      }
    }
    FUN_c03f6558(&local_230);
  }
  else {
    *param_2 = *param_2 | 0x1000000;
    local_228 = &PTR_FUN_c03f26e8;
    local_224 = param_1;
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[3] = 1;
    }
    if (puVar2 == (undefined4 *)0x0) {
      FUN_c0400008(local_18);
      return 0xe;
    }
    iVar3 = FUN_c03f5f74(puVar2,(int *)&local_228);
    if (iVar3 == 0) {
      *param_3 = (int)puVar2;
    }
    else {
      FUN_c03f6694(puVar2);
    }
  }
  FUN_c0400008(local_18);
  return iVar3;
}



/* c03f6a04 FUN_c03f6a04 */

/* Boundary evidence: original MIPS .pdata c03f6a04..c03f6ee3. Semantic name remains unreviewed. */

undefined4 FUN_c03f6a04(wchar_t *param_1,uint param_2)

{
  undefined2 uVar1;
  uint uVar2;
  HWAVEOUT hwo;
  undefined4 *puVar3;
  DWORD dwErrCode;
  int iVar4;
  MMRESULT MVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  LPCWAVEFORMATEX pwfx;
  uint local_res4 [3];
  HWAVEOUT local_50;
  undefined4 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  
  local_4c = (undefined4 *)0x0;
  uVar7 = 0;
  local_res4[0] = param_2;
  if (param_1 == (wchar_t *)0x0) {
    if (param_2 == 0x80000000) {
      if (DAT_c0401238 != (code *)0x0) {
        uVar6 = 0;
        uVar7 = DAT_c0401234;
        uVar1 = (undefined2)DAT_c040123c;
LAB_c03f6a78:
        uVar7 = (*DAT_c0401238)(uVar6,uVar1,uVar7);
        return uVar7;
      }
      if (DAT_c0401240 == (wchar_t *)0x0) {
        return 1;
      }
      local_res4[0] = 0x80000000;
      param_1 = DAT_c0401240;
    }
    else {
      if (param_2 != 0x40000000) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
        if (DAT_c0401348 == (HWAVEOUT)0x0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
        }
        else {
          waveOutReset(DAT_c0401348);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
          if ((param_2 & 1) == 0) {
            FUN_c03f5970();
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
        SetLastError(0);
        return 1;
      }
      if (DAT_c0401238 != (code *)0x0) {
        uVar6 = 1;
        uVar7 = DAT_c0401244;
        uVar1 = (undefined2)DAT_c0401258;
        goto LAB_c03f6a78;
      }
      if (DAT_c0401254 == (wchar_t *)0x0) {
        return 1;
      }
      local_res4[0] = 0x40000000;
      param_1 = DAT_c0401254;
    }
    local_res4[0] = local_res4[0] | 0x15;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
  dwErrCode = FUN_c03f67e4(param_1,local_res4,(int *)&local_4c);
  puVar3 = local_4c;
  if (dwErrCode == 0) {
    memset(&local_48,0,0x20);
    uVar2 = local_res4[0];
    local_48 = puVar3[1];
    local_44 = puVar3[2];
    pwfx = (LPCWAVEFORMATEX)*puVar3;
    if (((((local_res4[0] & 0x1000000) != 0) && ((local_res4[0] & 0xc0000000) == 0)) &&
        ((DAT_c0401230 & 2) == 0)) ||
       (((local_res4[0] & 0x2000000) != 0 && ((DAT_c0401230 & 4) == 0)))) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
      uVar7 = 1;
      goto LAB_c03f6e4c;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
    if (DAT_c0401348 != (HWAVEOUT)0x0) {
      if (((uVar2 & 0x10) != 0) && ((DAT_c0401324 & 0xc0000000) == 0)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
        goto LAB_c03f6e44;
      }
      waveOutReset(DAT_c0401348);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
    iVar4 = FUN_c03f5970();
    if (iVar4 == 0) {
      memcpy(&DAT_c0401328,&local_48,0x20);
      MVar5 = waveOutOpen(&local_50,0,pwfx,DAT_c0401350,0,0x50000);
      if ((MVar5 != 0) &&
         (MVar5 = waveOutOpen(&local_50,0xffffffff,pwfx,DAT_c0401350,0,0x50000), MVar5 != 0)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
        dwErrCode = FUN_c03f59dc(MVar5);
        goto LAB_c03f6e4c;
      }
      waveOutSetVolume(local_50,DAT_c040124c);
      MVar5 = waveOutPrepareHeader(local_50,(LPWAVEHDR)&DAT_c0401328,0x20);
      if (MVar5 == 0) {
        if ((uVar2 & 8) != 0) {
          DAT_c0401338 = DAT_c0401338 | 0xc;
          DAT_c040133c = 0xffffffff;
        }
        if ((DAT_c04011fc == (code *)0x0) || (iVar4 = (*DAT_c04011fc)(param_1,uVar2), iVar4 != 0)) {
          EventModify(DAT_c0401354,2);
          hwo = local_50;
          DAT_c040134c = puVar3;
          DAT_c0401324 = uVar2;
          DAT_c0401348 = local_50;
          if (pwfx->wFormatTag == 1) {
            DAT_c0401364 = __ll_div((int)((ulonglong)(uint)puVar3[2] * 1000),
                                    (int)((ulonglong)(uint)puVar3[2] * 1000 >> 0x20),
                                    pwfx->nAvgBytesPerSec,0);
          }
          else {
            DAT_c0401364 = 60000;
          }
          MVar5 = waveOutWrite(hwo,(LPWAVEHDR)&DAT_c0401328,0x20);
          if (MVar5 == 0) {
            DAT_c0401368 = GetTickCount();
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
            AccessibilitySoundSentryEvent();
            if ((uVar2 & 1) == 0) {
              FUN_c03f5970();
            }
            return 1;
          }
          EventModify(DAT_c0401354,3);
          goto LAB_c03f6e24;
        }
        uVar7 = 1;
      }
      else {
LAB_c03f6e24:
        dwErrCode = FUN_c03f59dc(0);
      }
      DAT_c040134c = (undefined4 *)0x0;
      DAT_c0401348 = (HWAVEOUT)0x0;
      DAT_c0401324 = 0;
      waveOutClose(local_50);
    }
  }
LAB_c03f6e44:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
LAB_c03f6e4c:
  if (puVar3 != (undefined4 *)0x0) {
    FUN_c03f6694(puVar3);
  }
  SetLastError(dwErrCode);
  return uVar7;
}



/* c03f6ee4 FUN_c03f6ee4 */

/* Boundary evidence: original MIPS .pdata c03f6ee4..c03f720f. Semantic name remains unreviewed. */

undefined4 FUN_c03f6ee4(wchar_t *param_1,HMODULE param_2,uint param_3)

{
  HRESULT HVar1;
  HRSRC hResInfo;
  STRSAFE_LPCWSTR pwVar2;
  undefined4 uVar3;
  STRSAFE_LPCWSTR local_258;
  STRSAFE_LPCWSTR local_254;
  undefined4 local_24c;
  STRSAFE_LPCWSTR local_240;
  STRSAFE_LPCWSTR local_23c;
  undefined4 local_234;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c04011e8;
  uVar3 = 0;
  if (DAT_c0401248 != 0) {
    SetLastError(0xe);
    goto LAB_c03f71cc;
  }
  if ((param_3 & 0x40004) == 0x40004) {
    if (((uint)param_1 & 0xffff0000) != 0) {
      local_254 = (STRSAFE_LPCWSTR)0x0;
      local_258 = (STRSAFE_LPCWSTR)0x0;
      local_24c = 0;
      FUN_c03f48c0((int *)&local_258,(int)param_1,0,5,0,0);
      pwVar2 = local_258;
      if ((local_258 == (STRSAFE_LPCWSTR)0x0) &&
         (pwVar2 = local_254, local_254 == (STRSAFE_LPCWSTR)0x0)) {
        SetLastError(0x57);
        FUN_c03f28a8((int *)&local_258);
        goto LAB_c03f71cc;
      }
      HVar1 = StringCchCopyW(awStack_228,0x104,pwVar2);
      if (HVar1 < 0) {
        SetLastError(0x57);
        FUN_c03f28a8((int *)&local_258);
        goto LAB_c03f71cc;
      }
      param_1 = awStack_228;
      FUN_c03f28a8((int *)&local_258);
    }
    hResInfo = FindResourceW(param_2,param_1,L"WAVE");
    if (hResInfo == (HRSRC)0x0) {
      SetLastError(0x714);
      goto LAB_c03f71cc;
    }
    param_1 = LoadResource(param_2,hResInfo);
    if (param_1 == (wchar_t *)0x0) {
      SetLastError(0x714);
      goto LAB_c03f71cc;
    }
  }
  else if ((param_1 != (wchar_t *)0x0) && ((param_3 & 0x40004) != 4)) {
    local_23c = (STRSAFE_LPCWSTR)0x0;
    local_240 = (STRSAFE_LPCWSTR)0x0;
    local_234 = 0;
    FUN_c03f48c0((int *)&local_240,(int)param_1,0,5,0,0);
    pwVar2 = local_240;
    if ((local_240 == (STRSAFE_LPCWSTR)0x0) &&
       (pwVar2 = local_23c, local_23c == (STRSAFE_LPCWSTR)0x0)) {
      SetLastError(0x57);
      FUN_c03f28a8((int *)&local_240);
      goto LAB_c03f71cc;
    }
    HVar1 = StringCchCopyW(awStack_228,0x104,pwVar2);
    if (HVar1 < 0) {
      SetLastError(0x57);
      FUN_c03f28a8((int *)&local_240);
      goto LAB_c03f71cc;
    }
    param_1 = awStack_228;
    FUN_c03f28a8((int *)&local_240);
  }
  if ((param_3 & 0x2000) != 0) {
    param_3 = param_3 | 0x10;
  }
  uVar3 = FUN_c03f6a04(param_1,param_3);
LAB_c03f71cc:
  FUN_c0400008(local_20);
  return uVar3;
}



/* c03f7210 FUN_c03f7210 */

/* Boundary evidence: original MIPS .pdata c03f7210..c03f721b. Semantic name remains unreviewed. */

undefined4 FUN_c03f7210(void)

{
  return 1;
}



/* c03f721c FUN_c03f721c */

/* Boundary evidence: original MIPS .pdata c03f721c..c03f727b. Semantic name remains unreviewed. */

undefined4 FUN_c03f721c(wchar_t *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((param_2 & 0x40004) == 0x40004) || ((param_2 & 0x2000) == 0x2000)) {
    SetLastError(0x57);
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c03f6ee4(param_1,(HMODULE)0x0,param_2);
  }
  return uVar1;
}



/* c03f727c FUN_c03f727c */

/* Boundary evidence: original MIPS .pdata c03f727c..c03f7a93. Semantic name remains unreviewed. */

void FUN_c03f727c(void)

{
  HMODULE hLibModule;
  LSTATUS LVar1;
  int iVar2;
  size_t sVar3;
  LPCWSTR pWVar4;
  wchar_t **ppwVar5;
  undefined4 *puVar6;
  undefined **ppuVar7;
  wchar_t *_Str;
  uint uVar8;
  uint uVar9;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD local_2e0;
  DWORD local_2dc;
  uint local_2d8;
  HKEY local_2d4;
  HKEY local_2d0;
  HKEY local_2cc;
  uint local_2c8;
  int local_2c4;
  LPCRITICAL_SECTION local_2c0;
  uint local_2bc;
  wchar_t awStack_2b8 [64];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c04011e8;
  lpCriticalSection = (LPCRITICAL_SECTION)&DAT_c040121c;
  local_2d0 = (HKEY)0x0;
  local_2c0 = (LPCRITICAL_SECTION)&DAT_c040121c;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
  if (DAT_c04011f4 != (code *)0x0) {
    (*DAT_c04011f4)();
  }
  hLibModule = DAT_c040130c;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Volume",0,0,&local_2d4);
  if (LVar1 == 0) {
    local_2e0 = 4;
    LVar1 = RegQueryValueExW(local_2d4,L"PlaySound",(LPDWORD)0x0,&local_2dc,(LPBYTE)&local_2d8,
                             &local_2e0);
    if ((LVar1 == 0) && (local_2dc == 4)) {
      DAT_c040124c = local_2d8;
    }
    local_2e0 = 4;
    LVar1 = RegQueryValueExW(local_2d4,L"Key",(LPDWORD)0x0,&local_2dc,(LPBYTE)&local_2d8,&local_2e0)
    ;
    local_2d8 = local_2d8 & 0xffff;
    if (((LVar1 != 0) || (local_2dc != 4)) || (DAT_c0401258 = local_2d8, 2 < local_2d8)) {
      DAT_c0401258 = 0;
    }
    local_2e0 = 4;
    LVar1 = RegQueryValueExW(local_2d4,L"Screen",(LPDWORD)0x0,&local_2dc,(LPBYTE)&local_2d8,
                             &local_2e0);
    local_2d8 = local_2d8 & 0xffff;
    if (((LVar1 != 0) || (local_2dc != 4)) || (DAT_c040123c = local_2d8, 2 < local_2d8)) {
      DAT_c040123c = 0;
    }
    local_2e0 = 4;
    LVar1 = RegQueryValueExW(local_2d4,L"Mute",(LPDWORD)0x0,&local_2dc,(LPBYTE)&local_2d8,&local_2e0
                            );
    if (((LVar1 == 0) && (local_2dc == 4)) && (local_2d8 < 8)) {
      DAT_c0401230 = local_2d8;
    }
    else {
      DAT_c0401230 = 7;
    }
    if (DAT_c0401250 != 0) {
      local_2e0 = 4;
      LVar1 = RegQueryValueExW(local_2d4,L"Volume",(LPDWORD)0x0,&local_2dc,(LPBYTE)&local_2d8,
                               &local_2e0);
      if ((LVar1 == 0) && (local_2dc == 4)) {
        DAT_c040125c = local_2d8;
      }
      else {
        DAT_c040125c = 0x9fff9fff;
      }
    }
    RegCloseKey(local_2d4);
  }
  else {
    DAT_c0401258 = 0;
    DAT_c040123c = 0;
    DAT_c0401230 = 7;
    DAT_c040125c = 0x9fff9fff;
  }
  if (DAT_c0401250 == 0) {
    if (DAT_c0401308 != (wchar_t *)0x0) {
      LocalFree(DAT_c0401308);
      DAT_c0401308 = (wchar_t *)0x0;
    }
    uVar8 = 0;
    do {
      puVar6 = *(undefined4 **)((int)&DAT_c04012b4 + uVar8);
      if (puVar6 != (undefined4 *)0x0) {
        FUN_c03f6694(puVar6);
        *(undefined4 *)((int)&DAT_c04012b4 + uVar8) = 0;
      }
      uVar8 = uVar8 + 4;
    } while (uVar8 < 0x54);
  }
  else {
    ppwVar5 = (wchar_t **)&DAT_c04012b4;
    DAT_c0401308 = (wchar_t *)0x0;
    do {
      *ppwVar5 = (wchar_t *)0x0;
      ppwVar5 = ppwVar5 + 1;
    } while (ppwVar5 != &DAT_c0401308);
  }
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Snd\\Event",0,0,&local_2d0);
  if (LVar1 == 0) {
    local_2e0 = 0x80;
    local_2dc = 1;
    LVar1 = RegQueryValueExW(local_2d0,L".Scheme",(LPDWORD)0x0,&local_2dc,(LPBYTE)awStack_2b8,
                             &local_2e0);
    if (LVar1 != 0) goto LAB_c03f7798;
    iVar2 = wcscmp(awStack_2b8,L".Default");
    if (iVar2 == 0) {
      puVar6 = &DAT_c0401260;
      ppuVar7 = &PTR_u_Asterisk_c03f256c;
      do {
        *puVar6 = *ppuVar7;
        puVar6 = puVar6 + 1;
        ppuVar7 = ppuVar7 + 1;
      } while (puVar6 != &DAT_c04012b4);
    }
    else {
      iVar2 = wcscmp(awStack_2b8,L".None");
      if (iVar2 != 0) {
        local_2dc = 7;
        LVar1 = RegQueryValueExW(local_2d0,awStack_2b8,(LPDWORD)0x0,&local_2dc,(LPBYTE)0x0,
                                 &local_2e0);
        if ((LVar1 == 0) &&
           (DAT_c0401308 = LocalAlloc(0,local_2e0 + 2), DAT_c0401308 != (wchar_t *)0x0)) {
          LVar1 = RegQueryValueExW(local_2d0,awStack_2b8,(LPDWORD)0x0,&local_2dc,
                                   (LPBYTE)DAT_c0401308,&local_2e0);
          if (LVar1 == 0) {
            uVar8 = 0;
            _Str = DAT_c0401308;
            do {
              *(wchar_t **)((int)&DAT_c0401260 + uVar8) = _Str;
              sVar3 = wcslen(_Str);
              uVar8 = uVar8 + 4;
              _Str = _Str + sVar3 + 1;
            } while (uVar8 < 0x54);
            goto LAB_c03f77b8;
          }
          LocalFree(DAT_c0401308);
          DAT_c0401308 = (wchar_t *)0x0;
        }
        goto LAB_c03f7798;
      }
      puVar6 = &DAT_c0401260;
      ppuVar7 = &PTR_DAT_c03f25c0;
      do {
        *puVar6 = *ppuVar7;
        puVar6 = puVar6 + 1;
        ppuVar7 = ppuVar7 + 1;
      } while (puVar6 != &DAT_c04012b4);
    }
  }
  else {
LAB_c03f7798:
    puVar6 = &DAT_c0401260;
    ppuVar7 = &PTR_u_Asterisk_c03f256c;
    do {
      *puVar6 = *ppuVar7;
      puVar6 = puVar6 + 1;
      ppuVar7 = ppuVar7 + 1;
    } while (puVar6 != &DAT_c04012b4);
  }
LAB_c03f77b8:
  if (local_2d0 != (HKEY)0x0) {
    local_2e0 = 4;
    local_2dc = 4;
    LVar1 = RegQueryValueExW(local_2d0,L"EventCache",(LPDWORD)0x0,&local_2dc,(LPBYTE)&local_2c8,
                             &local_2e0);
    if (LVar1 == 0) {
      uVar9 = 0;
      uVar8 = 0;
      do {
        if ((local_2c8 >> (uVar9 & 0x1f) & 1) != 0) {
          local_2bc = 2;
          iVar2 = FUN_c03f67e4(*(wchar_t **)((int)&PTR_u_SystemAsterisk_c03f2518 + uVar8),&local_2bc
                               ,&local_2c4);
          if (iVar2 == 0) {
            *(int *)((int)&DAT_c04012b4 + uVar8) = local_2c4;
          }
        }
        uVar8 = uVar8 + 4;
        uVar9 = uVar9 + 1;
        lpCriticalSection = local_2c0;
      } while (uVar8 < 0x54);
    }
    else {
      local_2c8 = 0;
    }
    if (local_2d0 != (HKEY)0x0) {
      RegCloseKey(local_2d0);
    }
  }
  DAT_c040130c = (HMODULE)0x0;
  DAT_c0401238 = 0;
  DAT_c0401254 = 0;
  DAT_c0401240 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\BuiltIn\\WAPIMAN\\Clicks",0,0,&local_2cc);
  if (LVar1 == 0) {
    local_2e0 = 0x208;
    LVar1 = RegQueryValueExW(local_2cc,L"ClickDLL",(LPDWORD)0x0,&local_2dc,(LPBYTE)aWStack_238,
                             &local_2e0);
    if (((LVar1 == 0) && (local_2dc == 1)) &&
       (DAT_c040130c = LoadLibraryW(aWStack_238), DAT_c040130c != (HMODULE)0x0)) {
      DAT_c0401238 = GetProcAddressW(DAT_c040130c,L"WC_PlayClick");
    }
    FUN_c03f614c(local_2cc);
    RegCloseKey(local_2cc);
    goto LAB_c03f7a40;
  }
  if (DAT_c0401258 == 0) {
    DAT_c0401254 = 0;
  }
  else {
    if (DAT_c0401258 == 1) {
      pWVar4 = (LPCWSTR)0x65;
    }
    else {
      if (DAT_c0401258 != 2) goto LAB_c03f7a00;
      pWVar4 = (LPCWSTR)0x64;
    }
    DAT_c0401254 = FUN_c03f60f8(DAT_c040120c,pWVar4);
  }
LAB_c03f7a00:
  if (DAT_c040123c == 0) {
    DAT_c0401240 = 0;
  }
  else {
    if (DAT_c040123c == 1) {
      pWVar4 = (LPCWSTR)0x67;
    }
    else {
      if (DAT_c040123c != 2) goto LAB_c03f7a40;
      pWVar4 = (LPCWSTR)0x66;
    }
    DAT_c0401240 = FUN_c03f60f8(DAT_c040120c,pWVar4);
  }
LAB_c03f7a40:
  if (hLibModule != (HMODULE)0x0) {
    FreeLibrary(hLibModule);
  }
  LeaveCriticalSection(lpCriticalSection);
  FUN_c0400008(local_30);
  return;
}



/* c03f7a94 FUN_c03f7a94 */

/* Boundary evidence: original MIPS .pdata c03f7a94..c03f7ad7. Semantic name remains unreviewed. */

void FUN_c03f7a94(void)

{
  DWORD DVar1;
  
  do {
    do {
      DVar1 = WaitForSingleObject(DAT_c0401350,0xffffffff);
    } while (DVar1 != 0);
    FUN_c03f66ec();
  } while( true );
}



/* c03f7ad8 FUN_c03f7ad8 */

/* Boundary evidence: original MIPS .pdata c03f7ad8..c03f7bef. Semantic name remains unreviewed. */

undefined4 FUN_c03f7ad8(void)

{
  HANDLE hObject;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c040121c);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0401310);
  DAT_c040124c = 0xffffffff;
  DAT_c0401354 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  if (((DAT_c0401354 != (HANDLE)0x0) &&
      (DAT_c0401350 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0),
      DAT_c0401350 != (HANDLE)0x0)) &&
     (hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c03f7a94,(LPVOID)0x0,0,(LPDWORD)0x0),
     hObject != (HANDLE)0x0)) {
    CeSetThreadPriority(hObject,DAT_c0401204);
    CloseHandle(hObject);
    DAT_c0401324 = 0;
    DAT_c0401348 = 0;
    DAT_c040134c = 0;
    return 1;
  }
  return 0;
}



/* c03f7bf0 FUN_c03f7bf0 */

/* Boundary evidence: original MIPS .pdata c03f7bf0..c03f7c5f. Semantic name remains unreviewed. */

undefined4 * FUN_c03f7bf0(undefined4 *param_1,undefined2 param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  *param_1 = &PTR_FUN_c03f27c8;
  *(undefined2 *)(param_1 + 1) = param_2;
  uVar2 = 0xfffe;
  if (param_3 < 0xfffe) {
    uVar2 = param_3;
  }
  *(short *)((int)param_1 + 6) = (short)uVar2;
  *(undefined2 *)(param_1 + 2) = 0;
  param_1[3] = 0;
  *(undefined2 *)(param_1 + 4) = 0xffff;
  *(undefined2 *)((int)param_1 + 0x12) = 0xffff;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  puVar1 = param_1 + 5;
  param_1[6] = puVar1;
  *puVar1 = puVar1;
  return param_1;
}



/* c03f7c60 FUN_c03f7c60 */

/* Boundary evidence: original MIPS .pdata c03f7c60..c03f7c9b. Semantic name remains unreviewed. */

void FUN_c03f7c60(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03f27c8;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  LocalFree((HLOCAL)param_1[3]);
  return;
}



/* c03f7c9c FUN_c03f7c9c */

void FUN_c03f7c9c(int param_1,ushort *param_2,ushort *param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  if (param_2 != (ushort *)0x0) {
    iVar3 = param_4 * 0x10 + *(int *)(param_1 + 0xc);
    uVar1 = *(ushort *)(iVar3 + 8);
    uVar2 = *(ushort *)(iVar3 + 10);
    if (uVar1 != 0xffff) {
      *(ushort *)((uint)uVar1 * 0x10 + *(int *)(param_1 + 0xc) + 10) = uVar2;
    }
    if (uVar2 == 0xffff) {
      *param_2 = uVar1;
    }
    else {
      *(ushort *)((uint)uVar2 * 0x10 + *(int *)(param_1 + 0xc) + 8) = uVar1;
    }
  }
  if (param_3 != (ushort *)0x0) {
    uVar1 = *param_3;
    *(ushort *)(*(int *)(param_1 + 0xc) + param_4 * 0x10 + 8) = uVar1;
    *(undefined2 *)(*(int *)(param_1 + 0xc) + param_4 * 0x10 + 10) = 0xffff;
    *param_3 = (ushort)param_4;
    if (uVar1 != 0xffff) {
      *(ushort *)((uint)uVar1 * 0x10 + *(int *)(param_1 + 0xc) + 10) = (ushort)param_4;
    }
  }
  return;
}



/* c03f7d30 FUN_c03f7d30 */

/* Boundary evidence: original MIPS .pdata c03f7d30..c03f7e33. Semantic name remains unreviewed. */

undefined4 FUN_c03f7d30(int param_1)

{
  ushort uVar1;
  void *pvVar2;
  ushort uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar3 = *(short *)(param_1 + 4) + *(short *)(param_1 + 8);
  uVar9 = (uint)uVar3;
  uVar8 = 0;
  if ((uVar9 <= *(ushort *)(param_1 + 6)) &&
     (pvVar2 = realloc(*(void **)(param_1 + 0xc),uVar9 << 4), pvVar2 != (void *)0x0)) {
    uVar6 = (uint)*(ushort *)(param_1 + 8);
    *(void **)(param_1 + 0xc) = pvVar2;
    if (uVar6 < uVar9) {
      puVar7 = (ushort *)(param_1 + 0x10);
      do {
        iVar5 = uVar6 * 0x10;
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar5);
        *puVar4 = 0;
        puVar4[1] = 0;
        *(undefined1 *)(puVar4 + 3) = 0;
        *(undefined1 *)((int)puVar4 + 0xd) = 0;
        if (puVar7 != (ushort *)0x0) {
          uVar1 = *puVar7;
          *(ushort *)(*(int *)(param_1 + 0xc) + iVar5 + 8) = uVar1;
          *(undefined2 *)(*(int *)(param_1 + 0xc) + iVar5 + 10) = 0xffff;
          *puVar7 = (ushort)uVar6;
          if (uVar1 != 0xffff) {
            *(ushort *)((uint)uVar1 * 0x10 + *(int *)(param_1 + 0xc) + 10) = (ushort)uVar6;
          }
        }
        uVar6 = uVar6 + 1 & 0xffff;
      } while (uVar6 < uVar9);
    }
    *(ushort *)(param_1 + 8) = uVar3;
    uVar8 = 1;
  }
  return uVar8;
}



/* c03f7e34 FUN_c03f7e34 */

int FUN_c03f7e34(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (((((param_2 & 0xffff) < (uint)*(ushort *)(param_1 + 8)) &&
       ((iVar2 = (param_2 & 0xffff) * 0x10 + *(int *)(param_1 + 0xc), param_3 == 0 ||
        (param_3 == *(int *)(iVar2 + 4))))) &&
      ((param_4 == 0 || (param_4 == *(byte *)(iVar2 + 0xd))))) &&
     (((param_2 >> 0x18 != 0 && (param_2 >> 0x18 == (uint)*(byte *)(iVar2 + 0xd))) &&
      ((param_2 >> 0x10 & 0xff) == (uint)*(byte *)(iVar2 + 0xc))))) {
    iVar1 = iVar2;
  }
  return iVar1;
}



/* c03f7eb8 FUN_c03f7eb8 */

/* Boundary evidence: original MIPS .pdata c03f7eb8..c03f7fff. Semantic name remains unreviewed. */

uint FUN_c03f7eb8(int param_1,int *param_2,undefined4 param_3,uint param_4,int param_5)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  
  uVar6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  if ((param_4 != 0) && (param_4 < 0x100)) {
    puVar5 = (ushort *)(param_1 + 0x10);
    uVar4 = (uint)*puVar5;
    if ((uVar4 != 0xffff) ||
       ((iVar2 = FUN_c03f7d30(param_1), iVar2 != 0 && (uVar4 = (uint)*puVar5, uVar4 != 0xffff)))) {
      FUN_c03f7c9c(param_1,puVar5,(ushort *)(param_1 + 0x12),uVar4);
      puVar3 = (undefined4 *)(uVar4 * 0x10 + *(int *)(param_1 + 0xc));
      puVar3[1] = param_3;
      cVar1 = *(char *)(puVar3 + 3);
      *puVar3 = param_2;
      *(byte *)(puVar3 + 3) = cVar1 + 1U;
      *(char *)((int)puVar3 + 0xd) = (char)param_4;
      uVar6 = (param_4 << 8 | (uint)(byte)(cVar1 + 1U)) << 0x10 | uVar4;
      if (param_5 != 0) {
        (**(code **)(*param_2 + 4))(param_2);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return uVar6;
}



/* c03f8000 FUN_c03f8000 */

/* Boundary evidence: original MIPS .pdata c03f8000..c03f80b3. Semantic name remains unreviewed. */

int * FUN_c03f8000(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  puVar1 = (undefined4 *)FUN_c03f7e34(param_1,param_2,param_3,param_4);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)*puVar1;
  }
  if ((piVar2 != (int *)0x0) && (param_5 != 0)) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return piVar2;
}



/* c03f80b4 FUN_c03f80b4 */

/* Boundary evidence: original MIPS .pdata c03f80b4..c03f81cb. Semantic name remains unreviewed. */

undefined4 FUN_c03f80b4(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  puVar1 = (undefined4 *)FUN_c03f7e34(param_1,param_2,param_3,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    for (piVar2 = *(int **)(param_1 + 0x14); piVar2 != (int *)(param_1 + 0x14);
        piVar2 = (int *)*piVar2) {
      if ((uint)*(ushort *)(piVar2 + 2) == (param_2 & 0xffff)) {
        *(undefined2 *)(piVar2 + 2) = *(undefined2 *)(puVar1 + 2);
      }
    }
    if (param_5 != 0) {
      (**(code **)(*(int *)*puVar1 + 8))();
    }
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined1 *)((int)puVar1 + 0xd) = 0;
    FUN_c03f7c9c(param_1,(ushort *)(param_1 + 0x12),(ushort *)(param_1 + 0x10),param_2 & 0xffff);
    uVar3 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return uVar3;
}



/* c03f81cc FUN_c03f81cc */

/* Boundary evidence: original MIPS .pdata c03f81cc..c03f823f. Semantic name remains unreviewed. */

void FUN_c03f81cc(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_c03f27cc;
  if (param_1[2] != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1[1] + 0x1c));
    piVar1 = (int *)param_1[2];
    *(int *)piVar1[1] = *piVar1;
    *(int *)(*piVar1 + 4) = piVar1[1];
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[1] + 0x1c));
    operator_delete((void *)param_1[2]);
  }
  return;
}



/* c03f8240 FUN_c03f8240 */

/* Boundary evidence: original MIPS .pdata c03f8240..c03f829f. Semantic name remains unreviewed. */

bool FUN_c03f8240(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 8) != 0;
  if (bVar1) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 4) + 0x1c));
    *(undefined2 *)(*(int *)(param_1 + 8) + 8) = *(undefined2 *)(*(int *)(param_1 + 4) + 0x12);
    LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 4) + 0x1c));
  }
  return bVar1;
}



/* c03f82a0 FUN_c03f82a0 */

/* Boundary evidence: original MIPS .pdata c03f82a0..c03f83ef. Semantic name remains unreviewed. */

undefined4
FUN_c03f82a0(int param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined1 *param_7,int param_8)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 4) + 0x1c));
    do {
      uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 8);
      if (uVar1 == 0xffff) goto LAB_c03f83c0;
      puVar2 = (undefined4 *)((uint)uVar1 * 0x10 + *(int *)(*(int *)(param_1 + 4) + 0xc));
      *(undefined2 *)(*(int *)(param_1 + 8) + 8) = *(undefined2 *)(puVar2 + 2);
    } while (((param_3 != 0) && (param_3 != *(byte *)((int)puVar2 + 0xd))) ||
            ((param_2 != 0 && (param_2 != puVar2[1]))));
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = CONCAT22(*(undefined2 *)(puVar2 + 3),uVar1);
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = puVar2[1];
    }
    if (param_7 != (undefined1 *)0x0) {
      *param_7 = *(undefined1 *)((int)puVar2 + 0xd);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *puVar2;
    }
    if (param_8 != 0) {
      (**(code **)(*(int *)*puVar2 + 4))();
    }
    uVar3 = 1;
LAB_c03f83c0:
    LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 4) + 0x1c));
  }
  return uVar3;
}



/* c03f83f0 FUN_c03f83f0 */

/* Boundary evidence: original MIPS .pdata c03f83f0..c03f844f. Semantic name remains unreviewed. */

undefined4 * FUN_c03f83f0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c03f27c8;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  LocalFree((HLOCAL)param_1[3]);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03f8450 FUN_c03f8450 */

/* Boundary evidence: original MIPS .pdata c03f8450..c03f84df. Semantic name remains unreviewed. */

undefined4 * FUN_c03f8450(undefined4 *param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *param_1 = &PTR_FUN_c03f27cc;
  param_1[1] = param_2;
  pvVar1 = operator_new(0xc);
  param_1[2] = pvVar1;
  if (pvVar1 != (void *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1[1] + 0x1c));
    FUN_c03f8240((int)param_1);
    iVar2 = param_1[1];
    puVar3 = *(undefined4 **)(iVar2 + 0x18);
    *(int *)param_1[2] = iVar2 + 0x14;
    *(undefined4 **)(param_1[2] + 4) = puVar3;
    *puVar3 = param_1[2];
    *(undefined4 *)(iVar2 + 0x18) = param_1[2];
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[1] + 0x1c));
  }
  return param_1;
}



/* c03f84e0 FUN_c03f84e0 */

/* Boundary evidence: original MIPS .pdata c03f84e0..c03f852b. Semantic name remains unreviewed. */

undefined4 * FUN_c03f84e0(undefined4 *param_1,uint param_2)

{
  FUN_c03f81cc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03f852c FUN_c03f852c */

/* Boundary evidence: original MIPS .pdata c03f852c..c03f85bb. Semantic name remains unreviewed. */

void FUN_c03f852c(int param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  
  if (param_2 != 0) {
    FUN_c03f80b4(-0x3fbfec94,param_2,param_1,5,0);
  }
  if (param_3 != (int *)0x0) {
    if (*param_3 != 0) {
      if (param_4 == 2) {
        uVar1 = 4;
      }
      else {
        uVar1 = 8;
      }
      CeFreeAsynchronousBuffer(*param_3,param_3[10],param_3[0xb],uVar1 | 0x80000000);
    }
    operator_delete(param_3);
  }
  return;
}



/* c03f85bc FUN_c03f85bc */

/* Boundary evidence: original MIPS .pdata c03f85bc..c03f86bb. Semantic name remains unreviewed. */

int FUN_c03f85bc(uint param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2[4] & 0x10U) != 0) {
    if (param_6 == 0) {
      return 0x21;
    }
    param_2[4] = param_2[4] & 0xffffffef;
  }
  if ((param_2[4] & 2U) == 0) {
    iVar2 = 0xb;
  }
  else {
    uVar1 = 8;
    if (param_4 != 2) {
      uVar1 = 0x37;
    }
    iVar2 = (**(code **)(**(int **)(param_3 + 0x34) + 4))
                      (*(int **)(param_3 + 0x34),uVar1,*(undefined4 *)(param_3 + 0x2c),param_2,0x20)
    ;
    if (iVar2 == 8) {
      iVar2 = 0;
    }
    param_2[4] = param_2[4] & 0xfffffffd;
    FUN_c03f852c(param_5,param_1,param_2,param_4);
  }
  return iVar2;
}



/* c03f86bc FUN_c03f86bc */

/* Boundary evidence: original MIPS .pdata c03f86bc..c03f88d3. Semantic name remains unreviewed. */

undefined4 FUN_c03f86bc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *local_38;
  int *local_34;
  uint local_30 [2];
  undefined4 auStack_28 [4];
  
  FUN_c03f8450(auStack_28,&DAT_c040136c);
  uVar2 = 0;
  iVar1 = FUN_c03f82a0((int)auStack_28,param_3,5,&local_38,(undefined4 *)0x0,(undefined4 *)0x0,
                       (undefined1 *)0x0,0);
  while (iVar1 != 0) {
    if (local_38[8] == param_1) {
      if ((local_38[4] & 0x10U) != 0) {
        FUN_c03f8240((int)auStack_28);
        iVar1 = FUN_c03f82a0((int)auStack_28,param_3,5,&local_34,(undefined4 *)0x0,(undefined4 *)0x0
                             ,(undefined1 *)0x0,0);
        if (iVar1 != 0) goto LAB_c03f8870;
        goto LAB_c03f8810;
      }
      local_38[4] = local_38[4] | 0x10;
    }
    iVar1 = FUN_c03f82a0((int)auStack_28,param_3,5,&local_38,(undefined4 *)0x0,(undefined4 *)0x0,
                         (undefined1 *)0x0,0);
  }
  FUN_c03f8240((int)auStack_28);
  iVar1 = FUN_c03f82a0((int)auStack_28,param_3,5,&local_38,local_30,(undefined4 *)0x0,
                       (undefined1 *)0x0,0);
  uVar2 = 1;
  while (iVar1 != 0) {
    if (local_38[8] == param_1) {
      FUN_c03f85bc(local_30[0],local_38,param_2,param_4,param_3,1);
    }
    iVar1 = FUN_c03f82a0((int)auStack_28,param_3,5,&local_38,local_30,(undefined4 *)0x0,
                         (undefined1 *)0x0,0);
  }
  goto LAB_c03f8810;
  while( true ) {
    if (local_34[8] == param_1) {
      local_34[4] = local_34[4] & 0xffffffef;
    }
    iVar1 = FUN_c03f82a0((int)auStack_28,param_3,5,&local_34,(undefined4 *)0x0,(undefined4 *)0x0,
                         (undefined1 *)0x0,0);
    if (iVar1 == 0) break;
LAB_c03f8870:
    if (local_34 == local_38) break;
  }
LAB_c03f8810:
  FUN_c03f81cc(auStack_28);
  return uVar2;
}



/* c03f88d4 FUN_c03f88d4 */

/* Boundary evidence: original MIPS .pdata c03f88d4..c03f8a57. Semantic name remains unreviewed. */

int FUN_c03f88d4(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_28;
  
  piVar1 = FUN_c03fa760(param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    return 5;
  }
  if ((param_2 != 3) && (iVar2 = FUN_c03f86bc(param_3,(int)piVar1,param_1,param_2), iVar2 == 0)) {
    iVar2 = 0x21;
    goto LAB_c03f8a18;
  }
  if (param_2 == 1) {
    local_28 = 0x35;
LAB_c03f89d0:
    uVar3 = 0;
LAB_c03f89d4:
    iVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],local_28,piVar1[0xb],0,uVar3);
  }
  else {
    if (param_2 == 2) {
      local_28 = 6;
      if (*(short *)piVar1[0x11] != 1) goto LAB_c03f89d0;
      uVar3 = 0x40000000;
      goto LAB_c03f89d4;
    }
    if (param_2 != 3) goto LAB_c03f89d0;
    iVar2 = (**(code **)(*(int *)piVar1[0xd] + 8))((int *)piVar1[0xd],4,piVar1[0xb],0,0);
  }
  if (iVar2 == 0) {
    FUN_c03fb9c0(DAT_c04011f8,piVar1);
    FUN_c03fa7c0(param_1,piVar1);
    piVar1 = (int *)0x0;
  }
LAB_c03f8a18:
  if (piVar1 != (int *)0x0) {
    FUN_c03fa830(piVar1);
  }
  FUN_c03fb204(DAT_c04011f8);
  return iVar2;
}



/* c03f8a58 FUN_c03f8a58 */

/* Boundary evidence: original MIPS .pdata c03f8a58..c03f8c0b. Semantic name remains unreviewed. */

undefined4
FUN_c03f8a58(int param_1,uint param_2,uint param_3,uint param_4,int param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_3 == 0xfffffffe) {
    if (param_4 == 1) {
      FUN_c03f727c();
    }
    else if (param_4 == 2) {
      FUN_c03f5a60(param_5);
    }
    uVar3 = 5;
  }
  else if (((param_4 < 3) || (0x15 < param_4)) && ((param_4 < 0x32 || (0x3c < param_4)))) {
    piVar1 = FUN_c03fa760(param_1,param_2,param_3);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)FUN_c03f45a0(param_2,param_3);
      if (piVar1 == (int *)0x0) {
        uVar3 = 2;
      }
      else {
        if (param_2 == 3) {
          uVar3 = (**(code **)(*piVar1 + 8))();
        }
        else {
          uVar3 = (**(code **)(*piVar1 + 4))(piVar1,param_4,0,param_5,param_6);
        }
        (**(code **)(*(int *)((int)piVar1 + *(int *)(piVar1[1] + 4) + 4) + 8))();
      }
    }
    else {
      iVar2 = *(int *)piVar1[0xd];
      if (param_2 == 3) {
        uVar3 = (**(code **)(iVar2 + 8))();
      }
      else {
        uVar3 = (**(code **)(iVar2 + 4))((int *)piVar1[0xd],param_4,piVar1[0xb],param_5,param_6);
      }
      FUN_c03fa830(piVar1);
    }
  }
  else {
    uVar3 = 0xb;
  }
  return uVar3;
}



/* c03f8c0c FUN_c03f8c0c */

/* Boundary evidence: original MIPS .pdata c03f8c0c..c03f8c8b. Semantic name remains unreviewed. */

undefined4 FUN_c03f8c0c(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc;
  if (param_2 != 2) {
    uVar2 = 0x3b;
  }
  piVar1 = FUN_c03fa760(param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],uVar2,piVar1[0xb],0,0);
    FUN_c03fa830(piVar1);
  }
  return uVar2;
}



/* c03f8c8c FUN_c03f8c8c */

/* Boundary evidence: original MIPS .pdata c03f8c8c..c03f8ef7. Semantic name remains unreviewed. */

int FUN_c03f8c8c(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int local_b8;
  int local_b4;
  undefined4 local_ac;
  uint local_a4;
  undefined2 local_a0;
  undefined1 auStack_9e [130];
  uint local_1c;
  
  local_1c = DAT_c04011e8;
  iVar1 = FUN_c03f2a7c(param_3);
  if (iVar1 == 0) {
    piVar3 = FUN_c03fa760(param_1,param_2,param_3);
    if (piVar3 == (int *)0x0) {
      FUN_c0400008(local_1c);
      return 5;
    }
    piVar2 = (int *)piVar3[0xd];
    (**(code **)(*(int *)((int)piVar2 + *(int *)(piVar2[1] + 4) + 4) + 4))();
    FUN_c03fa830(piVar3);
  }
  else {
    piVar2 = (int *)FUN_c03f45a0(param_2,param_3);
    if (piVar2 == (int *)0x0) {
      FUN_c0400008(local_1c);
      return 2;
    }
  }
  local_a0 = 0;
  memset(auStack_9e,0,0x82);
  if (param_2 == 1) {
    uVar5 = 0x80;
    iVar1 = (**(code **)(*piVar2 + 4))(piVar2,0x33,0,&local_a0,0x80);
  }
  else if (param_2 == 2) {
    uVar5 = 0x84;
    iVar1 = (**(code **)(*piVar2 + 4))(piVar2,4,0,&local_a0,0x84);
  }
  else if (param_2 == 3) {
    uVar5 = 0x80;
    iVar1 = (**(code **)(*piVar2 + 8))(piVar2,2,0,&local_a0,0x80);
  }
  else {
    iVar1 = 0xb;
    uVar5 = local_a4;
  }
  (**(code **)(*(int *)((int)piVar2 + *(int *)(piVar2[1] + 4) + 4) + 8))();
  if ((iVar1 == 0) && (param_5 != 0)) {
    if (uVar5 < param_5) {
      param_5 = uVar5;
    }
    local_b4 = 0;
    local_b8 = 0;
    local_ac = 0;
    FUN_c03f48c0(&local_b8,param_4,param_5,8,0,0);
    iVar4 = local_b8;
    if ((((local_b8 == 0) && (iVar4 = local_b4, local_b4 == 0)) ||
        (iVar4 = CeSafeCopyMemory(iVar4,&local_a0,param_5), iVar4 == 0)) ||
       (iVar4 = FUN_c03f28a8(&local_b8), iVar4 < 0)) {
      iVar1 = 0xb;
    }
    FUN_c03f28a8(&local_b8);
  }
  FUN_c0400008(local_1c);
  return iVar1;
}



/* c03f8ef8 FUN_c03f8ef8 */

/* Boundary evidence: original MIPS .pdata c03f8ef8..c03f9057. Semantic name remains unreviewed. */

undefined4 FUN_c03f8ef8(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  LPWSTR lpBuffer;
  undefined4 uVar2;
  LPWSTR local_30;
  LPWSTR local_2c;
  undefined4 local_24;
  
  uVar2 = 0;
  if ((param_3 < 0x15) || ((param_3 < 0x24 && (0x1f < param_3)))) {
    if (param_5 == 0) {
      uVar2 = 0;
    }
    else {
      if ((int)((ulonglong)param_5 * 2 >> 0x20) == 0) {
        local_2c = (LPWSTR)0x0;
        local_30 = (LPWSTR)0x0;
        local_24 = 0;
        FUN_c03f48c0((int *)&local_30,param_4,(int)((ulonglong)param_5 * 2),8,0,0);
        lpBuffer = local_30;
        if ((local_30 != (LPWSTR)0x0) || (lpBuffer = local_2c, local_2c != (LPWSTR)0x0)) {
          LoadStringW(DAT_c040120c,param_3,lpBuffer,param_5);
          iVar1 = FUN_c03f28a8((int *)&local_30);
          if (iVar1 < 0) {
            uVar2 = 0xb;
          }
          FUN_c03f28a8((int *)&local_30);
          return uVar2;
        }
        FUN_c03f28a8((int *)&local_30);
      }
      uVar2 = 0xb;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}



/* c03f9058 FUN_c03f9058 */

/* Boundary evidence: original MIPS .pdata c03f9058..c03f9063. Semantic name remains unreviewed. */

undefined4 FUN_c03f9058(void)

{
  return 1;
}



/* c03f9064 FUN_c03f9064 */

/* Boundary evidence: original MIPS .pdata c03f9064..c03f91b7. Semantic name remains unreviewed. */

undefined4 FUN_c03f9064(int param_1,uint param_2,uint param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_38 [2];
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 local_24;
  
  piVar1 = FUN_c03fa760(param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    uVar3 = 5;
  }
  else {
    local_2c = (undefined4 *)0x0;
    local_30 = (undefined4 *)0x0;
    local_24 = 0;
    FUN_c03f48c0((int *)&local_30,param_4,4,8,0,0);
    puVar4 = local_30;
    if ((local_30 == (undefined4 *)0x0) && (puVar4 = local_2c, local_2c == (undefined4 *)0x0)) {
      FUN_c03f28a8((int *)&local_30);
      uVar3 = 0xb;
    }
    else {
      local_38[0] = 0xfffffffe;
      uVar3 = 0;
      iVar2 = (*(code *)**(undefined4 **)piVar1[0xd])((undefined4 *)piVar1[0xd],3,local_38);
      if (iVar2 < 0) {
        local_38[0] = 0xfffffffe;
      }
      FUN_c03fa830(piVar1);
      *puVar4 = local_38[0];
      iVar2 = FUN_c03f28a8((int *)&local_30);
      if (iVar2 < 0) {
        uVar3 = 0xb;
      }
      FUN_c03f28a8((int *)&local_30);
    }
  }
  return uVar3;
}



/* c03f91b8 FUN_c03f91b8 */

/* Boundary evidence: original MIPS .pdata c03f91b8..c03f91c3. Semantic name remains unreviewed. */

undefined4 FUN_c03f91b8(void)

{
  return 1;
}



/* c03f91c4 FUN_c03f91c4 */

/* Boundary evidence: original MIPS .pdata c03f91c4..c03f940f. Semantic name remains unreviewed. */

undefined4 FUN_c03f91c4(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  void *_Src;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  void *pvVar7;
  void *local_50;
  void *local_4c;
  undefined4 local_44;
  int local_38 [3];
  uint local_2c;
  
  local_2c = DAT_c04011e8;
  uVar3 = 0xd;
  if (param_2 != 2) {
    uVar3 = 0x3c;
  }
  if (param_5 < 0xc) {
    FUN_c0400008(DAT_c04011e8);
    return 0xb;
  }
  local_4c = (void *)0x0;
  local_50 = (void *)0x0;
  local_44 = 0;
  uVar4 = 0;
  uVar6 = uVar3;
  FUN_c03f48c0((int *)&local_50,param_4,0xc,0xc,0,0);
  _Src = local_50;
  if (local_50 == (void *)0x0) {
    _Src = local_4c;
  }
  if (_Src != (void *)0x0) {
    pvVar7 = _Src;
    piVar1 = FUN_c03fa760(param_1,param_2,param_3);
    if (piVar1 == (int *)0x0) {
      uVar3 = 5;
      goto LAB_c03f92d0;
    }
    piVar5 = piVar1;
    memcpy(local_38,_Src,0xc);
    if (((local_38[0] == 0x10) || (local_38[0] == 8)) || (local_38[0] == 0x20)) {
      local_38[0] = 4;
    }
    uVar3 = (**(code **)(*(int *)piVar1[0xd] + 4))
                      ((int *)piVar1[0xd],uVar3,piVar1[0xb],local_38,0xc,uVar4,piVar5,uVar6,pvVar7);
    memcpy(_Src,local_38,0xc);
    FUN_c03fa830(piVar1);
    iVar2 = FUN_c03f28a8((int *)&local_50);
    if (-1 < iVar2) goto LAB_c03f92d0;
  }
  uVar3 = 0xb;
LAB_c03f92d0:
  FUN_c03f28a8((int *)&local_50);
  FUN_c0400008(local_2c);
  return uVar3;
}



/* c03f9410 FUN_c03f9410 */

/* Boundary evidence: original MIPS .pdata c03f9410..c03f941b. Semantic name remains unreviewed. */

undefined4 FUN_c03f9410(void)

{
  return 1;
}



/* c03f941c FUN_c03f941c */

/* Boundary evidence: original MIPS .pdata c03f941c..c03f9427. Semantic name remains unreviewed. */

undefined4 FUN_c03f941c(void)

{
  return 1;
}



/* c03f9428 FUN_c03f9428 */

/* Boundary evidence: original MIPS .pdata c03f9428..c03f97ef. Semantic name remains unreviewed. */

int FUN_c03f9428(int param_1,uint param_2,int param_3,uint param_4,int param_5,int param_6,
                uint param_7)

{
  undefined1 *puVar1;
  short *hMem;
  int iVar2;
  int **ppiVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *local_70;
  int *local_6c;
  undefined4 local_68;
  int local_64;
  uint local_60;
  int iStack_5c;
  int *local_58;
  short *local_54;
  code *local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [8];
  int local_40;
  int local_3c;
  undefined4 local_34;
  
  uVar5 = 5;
  if (param_2 != 2) {
    uVar5 = 0x34;
  }
  uVar8 = param_7 & 0xffffff7f;
  local_50 = FUN_c03f10b0;
  puVar1 = auStack_48 + 3;
  uVar7 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar7) =
       *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | param_4 >> (3 - uVar7) * 8;
  puVar1 = auStack_4c + 3;
  uVar7 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar7) =
       *(uint *)(puVar1 + -uVar7) & -1 << (uVar7 + 1) * 8 | 0U >> (3 - uVar7) * 8;
  auStack_4c = (undefined1  [4])0x0;
  uVar7 = param_4;
  if ((param_7 & 4) != 0) {
    if (param_4 == 0xffffffff) {
      return 10;
    }
    uVar7 = 0xffffffff;
  }
  local_68 = uVar5;
  local_64 = param_3;
  auStack_48._0_4_ = param_4;
  local_70 = (int *)FUN_c03f45a0(param_2,uVar7);
  if (local_70 == (int *)0x0) {
    return 2;
  }
  hMem = FUN_c03f4ce4(param_5);
  if (hMem == (short *)0x0) {
LAB_c03f94f8:
    iVar6 = 0xb;
  }
  else {
    local_60 = param_7 & 1;
    if (local_60 == 0) {
      if (local_64 != 0) {
        iVar6 = FUN_c03f2988(param_1);
        if (iVar6 != 0) {
          piVar4 = FUN_c03fab64(param_1,(int)local_70,param_2,iVar6,param_6,uVar8);
          if (piVar4 != (int *)0x0) {
            local_6c = piVar4 + 0xb;
            piVar4[0x11] = (int)hMem;
            uVar8 = param_7 & 0xfffbff7f | 0x30000;
            local_58 = piVar4;
            if (*hMem == 1) {
              uVar8 = param_7 & 0xfffbff7f | 0x40030000;
            }
            goto LAB_c03f95d8;
          }
          iVar6 = 7;
          goto LAB_c03f9784;
        }
        goto LAB_c03f94f8;
      }
      iVar6 = 0xb;
    }
    else {
      local_6c = &iStack_5c;
      local_58 = (int *)0x0;
LAB_c03f95d8:
      piVar4 = local_58;
      local_54 = hMem;
      iVar6 = (**(code **)(*local_70 + 4))(local_70,uVar5,local_6c,&local_58,uVar8);
      if (param_2 == 1) {
        if ((iVar6 == 0x21) || (iVar6 == 4)) {
          sndPlaySoundW((LPCWSTR)0x0,0);
          iVar2 = (**(code **)(*local_70 + 4))(local_70,local_68,local_6c,&local_58,uVar8);
LAB_c03f96a0:
          iVar6 = iVar2;
        }
      }
      else if ((iVar6 != 0) && (uVar7 != 0xffffffff)) {
        ppiVar3 = (int **)(piVar4 + 0xd);
        if (piVar4 == (int *)0x0) {
          ppiVar3 = &local_70;
        }
        iVar2 = FUN_c03ff468((int *)ppiVar3,local_6c,&local_58,uVar8);
        if ((iVar2 == 0) || (iVar2 == 0x20)) goto LAB_c03f96a0;
      }
      if (local_60 == 0) {
        if (iVar6 == 0) {
          local_3c = 0;
          local_40 = 0;
          local_34 = 0;
          FUN_c03f48c0(&local_40,local_64,4,8,0,0);
          iVar2 = local_40;
          if ((((local_40 != 0) || (iVar2 = local_3c, local_3c != 0)) &&
              (iVar2 = CeSafeCopyMemory(iVar2,piVar4 + 7,4), iVar2 != 0)) &&
             (iVar2 = FUN_c03f28a8(&local_40), -1 < iVar2)) {
            FUN_c03f28a8(&local_40);
            if (param_2 == 2) {
              FUN_c03fb068(DAT_c04011f8,(int)piVar4);
            }
            FUN_c03fa830(piVar4);
            goto LAB_c03f9798;
          }
          FUN_c03f88d4(param_1,param_2,piVar4[7]);
          piVar4 = (int *)0x0;
          iVar6 = 0xb;
          FUN_c03f28a8(&local_40);
        }
LAB_c03f9784:
        if (piVar4 != (int *)0x0) {
          FUN_c03fa7c0(param_1,piVar4);
        }
      }
      else {
        LocalFree(hMem);
      }
    }
LAB_c03f9798:
    (**(code **)(*(int *)((int)local_70 + *(int *)(local_70[1] + 4) + 4) + 8))();
  }
  return iVar6;
}



/* c03f97f0 FUN_c03f97f0 */

/* Boundary evidence: original MIPS .pdata c03f97f0..c03f9c9b. Semantic name remains unreviewed. */

int FUN_c03f97f0(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int *local_40;
  int *local_3c;
  undefined4 local_34;
  
  piVar6 = (int *)0x0;
  uVar7 = 0;
  piVar1 = FUN_c03fa760(param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    iVar4 = 5;
  }
  else {
    local_3c = (int *)0x0;
    local_40 = (int *)0x0;
    local_34 = 0;
    FUN_c03f48c0((int *)&local_40,param_4,0x20,0xc,0,0);
    piVar5 = local_40;
    if (local_40 == (int *)0x0) {
      piVar5 = local_3c;
    }
    if ((piVar5 == (int *)0x0) || (param_5 < 0x20)) {
      iVar4 = 0xb;
    }
    else {
      puVar8 = (uint *)(piVar5 + 4);
      if ((*puVar8 & 0x10) == 0) {
        if ((*puVar8 & 2) == 0) {
          piVar6 = operator_new(0x30);
          if (piVar6 == (int *)0x0) {
            iVar4 = 7;
          }
          else {
            piVar6[9] = param_4;
            piVar6[8] = param_3;
            *piVar6 = 0;
            piVar6[1] = piVar5[1];
            piVar6[2] = 0;
            piVar6[3] = piVar5[3];
            piVar6[4] = *puVar8;
            piVar6[5] = piVar5[5];
            piVar6[10] = *piVar5;
            uVar10 = piVar5[1];
            piVar6[0xb] = uVar10;
            uVar9 = ~(uint)*(byte *)((short *)piVar1[0x11] + 6) & 3;
            if (((*(short *)piVar1[0x11] == 1) && (uVar9 != 2)) && ((piVar6[10] & uVar9) != 0)) {
              iVar4 = 0xb;
            }
            else {
              uVar9 = (uint)*(ushort *)(piVar1[0x11] + 0xc);
              if (uVar9 == 0) {
                iVar4 = 0xb;
              }
              else {
                if (uVar9 == 0) {
                  trap(0x1c00);
                }
                if (uVar10 % uVar9 == 0) {
                  uVar9 = piVar6[4] & 0xc;
                  uVar10 = 4;
                  if (uVar9 == 4) {
                    piVar6[4] = piVar6[4] | 8;
                  }
                  else if (uVar9 == 8) {
                    piVar6[4] = piVar6[4] & 0xfffffff7;
                  }
                  if (param_2 != 2) {
                    uVar10 = 8;
                  }
                  iVar4 = CeAllocAsynchronousBuffer
                                    (piVar6,piVar6[10],piVar6[0xb],uVar10 | 0x80000000);
                  if (iVar4 < 0) {
                    iVar4 = 0xb;
                  }
                  else {
                    uVar7 = FUN_c03f7eb8(-0x3fbfec94,piVar6,param_1,5,0);
                    if (uVar7 == 0) {
                      iVar4 = 7;
                    }
                    else {
                      piVar5[7] = uVar7;
                      uVar3 = 7;
                      if (param_2 != 2) {
                        uVar3 = 0x36;
                      }
                      iVar4 = (**(code **)(*(int *)piVar1[0xd] + 4))
                                        ((int *)piVar1[0xd],uVar3,piVar1[0xb],piVar6,0);
                      if ((iVar4 == 8) || (iVar4 == 0)) {
                        uVar9 = piVar6[4];
                        piVar6[4] = uVar9 | 2;
                        *puVar8 = uVar9 | 2;
                        iVar4 = 0;
                        iVar2 = FUN_c03f28a8((int *)&local_40);
                        if (iVar2 < 0) {
                          iVar4 = 0xb;
                        }
                      }
                    }
                  }
                }
                else {
                  iVar4 = 0xb;
                }
              }
            }
          }
        }
        else {
          iVar4 = 0xb;
        }
      }
      else {
        iVar4 = 0xb;
      }
    }
    if (iVar4 != 0) {
      FUN_c03f852c(param_1,uVar7,piVar6,param_2);
    }
    FUN_c03fa830(piVar1);
    FUN_c03f28a8((int *)&local_40);
  }
  return iVar4;
}



/* c03f9c9c FUN_c03f9c9c */

/* Boundary evidence: original MIPS .pdata c03f9c9c..c03f9ca7. Semantic name remains unreviewed. */

undefined4 FUN_c03f9c9c(void)

{
  return 1;
}



/* c03f9ca8 FUN_c03f9ca8 */

/* Boundary evidence: original MIPS .pdata c03f9ca8..c03fa127. Semantic name remains unreviewed. */

int FUN_c03f9ca8(int param_1,uint param_2,uint param_3,int param_4,uint param_5,int param_6,
                uint param_7,int param_8,uint param_9,undefined4 *param_10,int param_11)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  uint *puVar9;
  void *_Buf2;
  int local_b8;
  int local_b4;
  undefined4 local_b0 [2];
  undefined4 *local_a8;
  undefined4 *local_a4;
  undefined4 local_9c;
  uint *local_90;
  uint *local_8c;
  undefined4 local_84;
  uint local_78;
  uint local_74;
  undefined4 local_6c;
  void *local_60;
  void *local_5c;
  undefined4 local_54;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 local_38 [4];
  undefined1 auStack_34 [4];
  undefined4 *local_30;
  
  local_b8 = 0;
  local_b0[0] = 0;
  local_5c = (void *)0x0;
  local_60 = (void *)0x0;
  local_54 = 0;
  local_74 = 0;
  local_78 = 0;
  piVar7 = (int *)0x0;
  local_6c = 0;
  local_8c = (uint *)0x0;
  local_90 = (uint *)0x0;
  local_84 = 0;
  local_a4 = (undefined4 *)0x0;
  local_a8 = (undefined4 *)0x0;
  local_9c = 0;
  local_b4 = param_1;
  FUN_c03f48c0((int *)&local_60,param_4,0x10,4,1,0);
  _Buf2 = local_60;
  if (local_60 == (void *)0x0) {
    _Buf2 = local_5c;
  }
  if (_Buf2 == (void *)0x0) {
LAB_c03f9d58:
    local_b8 = 0xb;
LAB_c03fa06c:
    if (param_11 != 0) {
      iVar5 = FUN_c03f28a8((int *)&local_90);
      if (iVar5 < 0) {
        local_b8 = 0xb;
      }
      if (param_10 != (undefined4 *)0x0) {
        *param_10 = local_b0[0];
        iVar5 = FUN_c03f28a8((int *)&local_a8);
        if (iVar5 < 0) {
          local_b8 = 0xb;
        }
      }
    }
  }
  else {
    if (param_6 == 0) {
      uVar8 = 0;
      if (param_7 == 0) goto LAB_c03f9dbc;
      goto LAB_c03f9d58;
    }
    FUN_c03f48c0((int *)&local_78,param_6,param_7,4,1,0);
    uVar8 = local_78;
    if ((local_78 == 0) && (uVar8 = local_74, local_74 == 0)) goto LAB_c03f9d58;
LAB_c03f9dbc:
    FUN_c03f48c0((int *)&local_90,param_8,param_9,0xc,1,0);
    puVar9 = local_90;
    if (((local_90 == (uint *)0x0) && (puVar9 = local_8c, local_8c == (uint *)0x0)) ||
       (((param_10 != (undefined4 *)0x0 &&
         (FUN_c03f48c0((int *)&local_a8,(int)param_10,4,8,1,0), param_10 = local_a8,
         local_a8 == (undefined4 *)0x0)) && (param_10 = local_a4, local_a4 == (undefined4 *)0x0))))
    goto LAB_c03f9d58;
    puVar1 = local_48 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)_Buf2 >> (3 - uVar2) * 8;
    puVar1 = local_44 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_5 >> (3 - uVar2) * 8;
    puVar1 = auStack_40 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | uVar8 >> (3 - uVar2) * 8;
    puVar1 = auStack_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_7 >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)puVar9 >> (3 - uVar2) * 8;
    puVar1 = auStack_34 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_9 >> (3 - uVar2) * 8;
    local_44 = (undefined1  [4])param_5;
    auStack_3c = (undefined1  [4])param_7;
    auStack_34 = (undefined1  [4])param_9;
    local_48 = (undefined1  [4])_Buf2;
    auStack_40 = (undefined1  [4])uVar8;
    local_38 = (undefined1  [4])puVar9;
    iVar5 = memcmp(&DAT_c03f204c,_Buf2,0x10);
    if (((iVar5 == 0) && (param_5 == 1)) && (param_3 != 0)) {
      FUN_c03f28a8((int *)&local_a8);
      FUN_c03f28a8((int *)&local_90);
      FUN_c03f28a8((int *)&local_78);
      FUN_c03f28a8((int *)&local_60);
      return 2;
    }
    iVar3 = FUN_c03f2a7c(param_3);
    iVar5 = local_b4;
    if (iVar3 == 0) {
      piVar4 = FUN_c03fa760(local_b4,param_2,param_3);
      if (piVar4 == (int *)0x0) {
        iVar5 = 5;
        goto LAB_c03fa0d8;
      }
      piVar7 = (int *)piVar4[0xd];
      (**(code **)(*(int *)((int)piVar7 + *(int *)(piVar7[1] + 4) + 4) + 4))();
      iVar3 = piVar4[0xb];
      FUN_c03fa830(piVar4);
    }
    else {
      piVar7 = (int *)FUN_c03f45a0(param_2,param_3);
      if (piVar7 == (int *)0x0) {
        iVar5 = 2;
        goto LAB_c03fa0d8;
      }
      iVar3 = 0;
      iVar5 = local_b4;
    }
    if (param_11 != 0) {
      local_30 = local_b0;
      iVar5 = FUN_c03f2b3c(iVar5,param_2,param_3,(undefined4 *)local_48,&local_b8);
      if (iVar5 == 0) {
        if (param_2 == 2) {
          uVar6 = 0x17;
        }
        else {
          uVar6 = 0x3d;
        }
        goto LAB_c03f9fec;
      }
      goto LAB_c03fa06c;
    }
    local_30 = (undefined4 *)0x0;
    iVar5 = FUN_c03f2e84(iVar5,param_2,param_3,(undefined4 *)local_48,&local_b8);
    if (iVar5 == 0) {
      uVar6 = 0x18;
      if (param_2 != 2) {
        uVar6 = 0x3e;
      }
LAB_c03f9fec:
      local_b8 = (**(code **)(*piVar7 + 4))(piVar7,uVar6,iVar3,local_48,0);
      if (((local_b8 == 8) && (iVar5 = memcmp(&DAT_c03f206c,(void *)local_48,0x10), iVar5 == 0)) &&
         ((local_44 == (undefined1  [4])0x1 && ((*(uint *)local_38 & 1) != 0)))) {
        local_b8 = 0;
      }
      goto LAB_c03fa06c;
    }
  }
  iVar5 = local_b8;
  if (piVar7 != (int *)0x0) {
    (**(code **)(*(int *)((int)piVar7 + *(int *)(piVar7[1] + 4) + 4) + 8))();
    iVar5 = local_b8;
  }
LAB_c03fa0d8:
  FUN_c03f28a8((int *)&local_a8);
  FUN_c03f28a8((int *)&local_90);
  FUN_c03f28a8((int *)&local_78);
  FUN_c03f28a8((int *)&local_60);
  return iVar5;
}



/* c03fa128 FUN_c03fa128 */

/* Boundary evidence: original MIPS .pdata c03fa128..c03fa2e3. Semantic name remains unreviewed. */

int FUN_c03fa128(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *local_38;
  int *local_34;
  undefined4 local_2c;
  
  piVar1 = FUN_c03fa760(param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    iVar3 = 5;
  }
  else {
    local_34 = (int *)0x0;
    local_38 = (int *)0x0;
    local_2c = 0;
    FUN_c03f48c0((int *)&local_38,param_4,0x20,0xc,0,0);
    piVar4 = local_38;
    if (local_38 == (int *)0x0) {
      piVar4 = local_34;
    }
    if ((piVar4 == (int *)0x0) || (param_5 < 0x20)) {
      iVar3 = 0xb;
    }
    else {
      piVar2 = FUN_c03f2aa4(param_1,piVar4,param_4);
      if (piVar2 == (int *)0x0) {
        iVar3 = 0xb;
      }
      else {
        iVar3 = FUN_c03f85bc(piVar4[7],piVar2,(int)piVar1,param_2,param_1,0);
        if (iVar3 == 0) {
          piVar4[4] = piVar4[4] & 0xfffffffd;
          piVar4[7] = 0;
        }
      }
    }
    FUN_c03fa830(piVar1);
    FUN_c03f28a8((int *)&local_38);
  }
  return iVar3;
}



/* c03fa2e4 FUN_c03fa2e4 */

/* Boundary evidence: original MIPS .pdata c03fa2e4..c03fa2ef. Semantic name remains unreviewed. */

undefined4 FUN_c03fa2e4(void)

{
  return 1;
}



/* c03fa2f0 FUN_c03fa2f0 */

/* Boundary evidence: original MIPS .pdata c03fa2f0..c03fa5ef. Semantic name remains unreviewed. */

int FUN_c03fa2f0(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int *piVar1;
  int *piVar2;
  LONG LVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  int *local_40;
  int *local_3c;
  undefined4 local_34;
  
  uVar9 = 9;
  if (param_2 != 2) {
    uVar9 = 0x38;
  }
  piVar1 = FUN_c03fa760(param_1,param_2,param_3);
  if (piVar1 == (int *)0x0) {
    return 5;
  }
  local_3c = (int *)0x0;
  local_40 = (int *)0x0;
  local_34 = 0;
  FUN_c03f48c0((int *)&local_40,param_4,0x20,0xc,0,0);
  piVar6 = local_40;
  if (local_40 == (int *)0x0) {
    piVar6 = local_3c;
  }
  if ((piVar6 == (int *)0x0) || (param_5 < 0x20)) {
    iVar7 = 0xb;
  }
  else {
    puVar8 = (uint *)(piVar6 + 4);
    uVar5 = *puVar8;
    if ((uVar5 & 2) == 0) {
      iVar7 = 0x22;
    }
    else if ((uVar5 & 0x10) == 0) {
      *puVar8 = uVar5 | 0x10;
      piVar2 = FUN_c03f2aa4(param_1,piVar6,param_4);
      if (piVar2 == (int *)0x0) {
        iVar7 = 0xb;
      }
      else {
        piVar2[8] = param_3;
        piVar2[5] = piVar6[5];
        piVar2[4] = (piVar2[4] ^ *puVar8) & 0xc ^ piVar2[4];
        *puVar8 = *puVar8 & 0xfffffffe;
        piVar2[4] = piVar2[4] & 0xfffffffe;
        piVar2[1] = piVar6[1];
        iVar7 = FUN_c03f1070(piVar1[0xd],param_2);
        if (((iVar7 == 0) && (LVar3 = InterlockedExchangeAdd(piVar1 + 0x16,1), LVar3 == 0)) &&
           (piVar1[0x18] != 0)) {
          piVar1[0x18] = 0;
          piVar1[0x17] = piVar1[0x17] + 1;
        }
        iVar7 = (**(code **)(*(int *)piVar1[0xd] + 4))
                          ((int *)piVar1[0xd],uVar9,piVar1[0xb],piVar2,0);
        if (iVar7 == 0) goto LAB_c03fa57c;
        iVar4 = FUN_c03f1070(piVar1[0xd],param_2);
        if (iVar4 == 0) {
          InterlockedDecrement(piVar1 + 0x16);
        }
      }
      *puVar8 = *puVar8 & 0xffffffef;
    }
    else {
      iVar7 = 0x21;
    }
  }
LAB_c03fa57c:
  FUN_c03fa830(piVar1);
  FUN_c03f28a8((int *)&local_40);
  return iVar7;
}



/* c03fa5f0 FUN_c03fa5f0 */

/* Boundary evidence: original MIPS .pdata c03fa5f0..c03fa5fb. Semantic name remains unreviewed. */

undefined4 FUN_c03fa5f0(void)

{
  return 1;
}



/* c03fa608 FUN_c03fa608 */

/* Boundary evidence: original MIPS .pdata c03fa608..c03fa623. Semantic name remains unreviewed. */

void FUN_c03fa608(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* c03fa624 FUN_c03fa624 */

/* Boundary evidence: original MIPS .pdata c03fa624..c03fa67f. Semantic name remains unreviewed. */

LONG FUN_c03fa624(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(param_1,1);
  }
  return LVar1;
}



/* c03fa680 FUN_c03fa680 */

/* Boundary evidence: original MIPS .pdata c03fa680..c03fa6c3. Semantic name remains unreviewed. */

undefined4 * FUN_c03fa680(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_c03f27d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03fa6c4 FUN_c03fa6c4 */

/* Boundary evidence: original MIPS .pdata c03fa6c4..c03fa6df. Semantic name remains unreviewed. */

void FUN_c03fa6c4(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return;
}



/* c03fa6e0 FUN_c03fa6e0 */

/* Boundary evidence: original MIPS .pdata c03fa6e0..c03fa6fb. Semantic name remains unreviewed. */

void FUN_c03fa6e0(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return;
}



/* c03fa6fc FUN_c03fa6fc */

/* Boundary evidence: original MIPS .pdata c03fa6fc..c03fa75f. Semantic name remains unreviewed. */

undefined4 * FUN_c03fa6fc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_c03f27e0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = &PTR_LAB_c03f27d0;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03fa760 FUN_c03fa760 */

/* Boundary evidence: original MIPS .pdata c03fa760..c03fa7bf. Semantic name remains unreviewed. */

int * FUN_c03fa760(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  
  piVar1 = FUN_c03f8000(-0x3fbfec64,param_3,param_1,param_2 & 0xff,1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1);
  }
  return piVar1;
}



/* c03fa7c0 FUN_c03fa7c0 */

/* Boundary evidence: original MIPS .pdata c03fa7c0..c03fa82f. Semantic name remains unreviewed. */

void FUN_c03fa7c0(int param_1,int *param_2)

{
  (**(code **)(*param_2 + 0x14))(param_2);
  FUN_c03f80b4(-0x3fbfec64,param_2[7],param_1,(uint)*(byte *)(param_2 + 0xe),1);
  (**(code **)(*param_2 + 8))(param_2);
  return;
}



/* c03fa830 FUN_c03fa830 */

/* Boundary evidence: original MIPS .pdata c03fa830..c03fa86f. Semantic name remains unreviewed. */

void FUN_c03fa830(int *param_1)

{
  (**(code **)(*param_1 + 0x14))(param_1);
  (**(code **)(*param_1 + 8))(param_1);
  return;
}



/* c03fa870 FUN_c03fa870 */

/* Boundary evidence: original MIPS .pdata c03fa870..c03fa8db. Semantic name remains unreviewed. */

undefined4 FUN_c03fa870(int param_1,uint param_2,uint param_3)

{
  if (param_2 != 3) {
    FUN_c03f8c0c(param_1,param_2,param_3);
  }
  FUN_c03f88d4(param_1,param_2,param_3);
  return 1;
}



/* c03fa8dc FUN_c03fa8dc */

/* Boundary evidence: original MIPS .pdata c03fa8dc..c03fa9b7. Semantic name remains unreviewed. */

void FUN_c03fa8dc(int param_1)

{
  int iVar1;
  uint uVar2;
  byte local_20 [4];
  uint local_1c;
  undefined4 auStack_18 [4];
  
  FUN_c03f8450(auStack_18,&DAT_c040139c);
  iVar1 = FUN_c03f82a0((int)auStack_18,param_1,0,(undefined4 *)0x0,&local_1c,(undefined4 *)0x0,
                       local_20,0);
  while (iVar1 != 0) {
    uVar2 = (uint)local_20[0];
    if (((uVar2 == 1) || (uVar2 == 2)) || (uVar2 == 3)) {
      FUN_c03fa870(param_1,uVar2,local_1c);
    }
    iVar1 = FUN_c03f82a0((int)auStack_18,param_1,0,(undefined4 *)0x0,&local_1c,(undefined4 *)0x0,
                         local_20,0);
  }
  FUN_c03f81cc(auStack_18);
  return;
}



/* c03fa9b8 FUN_c03fa9b8 */

/* Boundary evidence: original MIPS .pdata c03fa9b8..c03faa03. Semantic name remains unreviewed. */

undefined4 FUN_c03fa9b8(int param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  iVar1 = FUN_c03f82a0(param_1,0,0,local_10,(undefined4 *)0x0,(undefined4 *)0x0,(undefined1 *)0x0,1)
  ;
  if (iVar1 == 0) {
    local_10[0] = 0;
  }
  return local_10[0];
}



/* c03faa04 FUN_c03faa04 */

/* Boundary evidence: original MIPS .pdata c03faa04..c03faa47. Semantic name remains unreviewed. */

int * FUN_c03faa04(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_c03fa9b8(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1);
  }
  return piVar1;
}



/* c03faa48 FUN_c03faa48 */

/* Boundary evidence: original MIPS .pdata c03faa48..c03faa9b. Semantic name remains unreviewed. */

undefined4 * FUN_c03faa48(undefined4 *param_1)

{
  param_1[1] = 1;
  *param_1 = &PTR_LAB_c03f27e0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = &PTR_LAB_c03f27f8;
  param_1[0xd] = 0;
  param_1[0x11] = 0;
  return param_1;
}



/* c03faa9c FUN_c03faa9c */

/* Boundary evidence: original MIPS .pdata c03faa9c..c03fab17. Semantic name remains unreviewed. */

void FUN_c03faa9c(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0xd];
  *param_1 = &PTR_LAB_c03f27f8;
  if (iVar1 != 0) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + iVar1 + 4) + 8))();
  }
  LocalFree((HLOCAL)param_1[0x11]);
  *param_1 = &PTR_LAB_c03f27e0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = &PTR_LAB_c03f27d0;
  return;
}



/* c03fab18 FUN_c03fab18 */

/* Boundary evidence: original MIPS .pdata c03fab18..c03fab63. Semantic name remains unreviewed. */

undefined4 * FUN_c03fab18(undefined4 *param_1,uint param_2)

{
  FUN_c03faa9c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03fab64 FUN_c03fab64 */

/* Boundary evidence: original MIPS .pdata c03fab64..c03fac9b. Semantic name remains unreviewed. */

int * FUN_c03fab64(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  
  puVar1 = operator_new(100);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c03faa48(puVar1);
  }
  if (piVar2 != (int *)0x0) {
    uVar3 = FUN_c03f7eb8(-0x3fbfec64,piVar2,param_1,param_3 & 0xff,1);
    piVar2[7] = uVar3;
    if (uVar3 == 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      piVar2 = (int *)0x0;
    }
    else {
      piVar2[0x13] = -1;
      piVar2[0xe] = param_3;
      piVar2[0xb] = 0;
      piVar2[0xc] = param_1;
      piVar2[10] = param_6;
      piVar2[8] = param_4;
      piVar2[9] = param_5;
      piVar2[0x11] = 0;
      piVar2[0x14] = 0;
      piVar2[0x15] = 0;
      piVar2[0x16] = 0;
      piVar2[0x17] = 0;
      piVar2[0x18] = 0;
      piVar2[0x12] = 0;
      piVar2[0xd] = param_2;
      (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + param_2 + 4) + 4))();
      (**(code **)(*piVar2 + 0x10))(piVar2);
    }
  }
  return piVar2;
}



/* c03fac9c FUN_c03fac9c */

/* Boundary evidence: original MIPS .pdata c03fac9c..c03fad0f. Semantic name remains unreviewed. */

undefined4 FUN_c03fac9c(int param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03fa760(param_1,2,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],0x14,piVar1[0xb],0,0);
    FUN_c03fa830(piVar1);
  }
  return uVar2;
}



/* c03fad10 FUN_c03fad10 */

/* Boundary evidence: original MIPS .pdata c03fad10..c03fad83. Semantic name remains unreviewed. */

undefined4 FUN_c03fad10(int param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03fa760(param_1,2,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],10,piVar1[0xb],0,0);
    FUN_c03fa830(piVar1);
  }
  return uVar2;
}



/* c03fad84 FUN_c03fad84 */

/* Boundary evidence: original MIPS .pdata c03fad84..c03fadf7. Semantic name remains unreviewed. */

undefined4 FUN_c03fad84(int param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03fa760(param_1,2,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],0xb,piVar1[0xb],0,0);
    FUN_c03fa830(piVar1);
  }
  return uVar2;
}



/* c03fadf8 FUN_c03fadf8 */

/* Boundary evidence: original MIPS .pdata c03fadf8..c03fae6f. Semantic name remains unreviewed. */

undefined4 FUN_c03fadf8(int param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03fa760(param_1,2,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],0xf,piVar1[0xb],param_3,0);
    FUN_c03fa830(piVar1);
  }
  return uVar2;
}



/* c03fae70 FUN_c03fae70 */

/* Boundary evidence: original MIPS .pdata c03fae70..c03faee7. Semantic name remains unreviewed. */

undefined4 FUN_c03fae70(int param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03fa760(param_1,2,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],0x13,piVar1[0xb],param_3,0);
    FUN_c03fa830(piVar1);
  }
  return uVar2;
}



/* c03faee8 FUN_c03faee8 */

/* Boundary evidence: original MIPS .pdata c03faee8..c03faf6f. Semantic name remains unreviewed. */

LPCRITICAL_SECTION FUN_c03faee8(LPCRITICAL_SECTION param_1)

{
  param_1->SpinCount = 0;
  param_1[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[1].LockCount = 2;
  InitializeCriticalSection(param_1);
  param_1[1].OwningThread = (HANDLE)0x2;
  param_1[1].RecursionCount = 1000;
  param_1[1].SpinCount = 2;
  param_1[1].LockSemaphore = (HANDLE)0x3e8;
  param_1[2].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x3e8;
  param_1[2].LockCount = 6;
  param_1[2].RecursionCount = 1000;
  param_1[2].OwningThread = (HANDLE)0x6;
  param_1[2].LockSemaphore = (HANDLE)0x3e8;
  param_1[2].SpinCount = 4;
  param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x3e8;
  param_1[3].LockCount = 4;
  param_1[3].RecursionCount = 1000;
  param_1[3].OwningThread = (HANDLE)0x4;
  return param_1;
}



/* c03faf70 FUN_c03faf70 */

/* Boundary evidence: original MIPS .pdata c03faf70..c03faff3. Semantic name remains unreviewed. */

void FUN_c03faf70(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)(*(int *)(param_2 + 0x50) * 0xffff) / 0x12c0;
  uVar2 = (*(uint *)(param_2 + 0x4c) & 0xffff) - uVar3;
  iVar1 = *(ushort *)(param_2 + 0x4e) - uVar3;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  (**(code **)(**(int **)(param_2 + 0x34) + 4))
            (*(int **)(param_2 + 0x34),0x11,*(undefined4 *)(param_2 + 0x2c),iVar1 << 0x10 | uVar2,0)
  ;
  return;
}



/* c03faff4 FUN_c03faff4 */

/* Boundary evidence: original MIPS .pdata c03faff4..c03fb067. Semantic name remains unreviewed. */

void FUN_c03faff4(LPCRITICAL_SECTION param_1,int param_2,undefined4 *param_3)

{
  EnterCriticalSection(param_1);
  param_3[1] = (&param_1[1].RecursionCount)[param_2 * 2];
  *param_3 = (&param_1[1].OwningThread)[param_2 * 2];
  LeaveCriticalSection(param_1);
  return;
}



/* c03fb068 FUN_c03fb068 */

/* Boundary evidence: original MIPS .pdata c03fb068..c03fb0e7. Semantic name remains unreviewed. */

void FUN_c03fb068(LPCRITICAL_SECTION param_1,int param_2)

{
  EnterCriticalSection(param_1);
  if ((param_1[1].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) ||
     ((HANDLE)param_1[1].LockCount <= (&param_1[1].OwningThread)[*(int *)(param_2 + 0x48) * 2])) {
    *(undefined4 *)(param_2 + 0x50) = 0;
  }
  else {
    *(PRTL_CRITICAL_SECTION_DEBUG *)(param_2 + 0x50) = param_1[1].DebugInfo;
  }
  LeaveCriticalSection(param_1);
  FUN_c03faf70(param_1,param_2);
  return;
}



/* c03fb0e8 FUN_c03fb0e8 */

/* Boundary evidence: original MIPS .pdata c03fb0e8..c03fb203. Semantic name remains unreviewed. */

void FUN_c03fb0e8(int param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 auStack_28 [4];
  
  uVar4 = 2;
  uVar5 = 0;
  FUN_c03f8450(auStack_28,&DAT_c040139c);
  while (piVar1 = (int *)FUN_c03fa9b8((int)auStack_28), piVar1 != (int *)0x0) {
    if (((piVar1[0xe] == 2) && ((piVar1[0x15] & 2U) == 0)) && (piVar1 != param_2)) {
      puVar3 = (uint *)((piVar1[0x12] + 4) * 8 + param_1);
      uVar2 = puVar3[1];
      if ((uVar4 < uVar2) || ((uVar2 == uVar4 && (uVar5 < *puVar3)))) {
        uVar5 = *puVar3;
        uVar4 = uVar2;
      }
    }
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((uVar4 != *(uint *)(param_1 + 0x1c)) || (uVar5 != *(uint *)(param_1 + 0x18))) {
    *(uint *)(param_1 + 0x1c) = uVar4;
    *(uint *)(param_1 + 0x18) = uVar5;
    *(undefined4 *)(param_1 + 0x14) = 1;
  }
  FUN_c03f81cc(auStack_28);
  return;
}



/* c03fb204 FUN_c03fb204 */

/* Boundary evidence: original MIPS .pdata c03fb204..c03fb313. Semantic name remains unreviewed. */

void FUN_c03fb204(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  PRTL_CRITICAL_SECTION_DEBUG p_Var2;
  undefined4 auStack_20 [4];
  
  EnterCriticalSection(param_1);
  if (param_1->SpinCount != 0) {
    FUN_c03f8450(auStack_20,&DAT_c040139c);
    param_1->SpinCount = 0;
    while (piVar1 = FUN_c03faa04((int)auStack_20), piVar1 != (int *)0x0) {
      if ((piVar1[0xe] == 2) && ((piVar1[0x15] & 2U) == 0)) {
        if ((&param_1[1].OwningThread)[piVar1[0x12] * 2] < (HANDLE)param_1[1].LockCount) {
          p_Var2 = param_1[1].DebugInfo;
        }
        else {
          p_Var2 = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
        }
        if ((PRTL_CRITICAL_SECTION_DEBUG)piVar1[0x14] != p_Var2) {
          piVar1[0x14] = (int)p_Var2;
          FUN_c03faf70(param_1,(int)piVar1);
          if ((piVar1[0x15] & 1U) != 0) {
            FUN_c03f1000((int)piVar1,0x3d8,piVar1[0x14],0,0);
          }
        }
      }
      FUN_c03fa830(piVar1);
    }
    FUN_c03f81cc(auStack_20);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* c03fb314 FUN_c03fb314 */

/* Boundary evidence: original MIPS .pdata c03fb314..c03fb453. Semantic name remains unreviewed. */

undefined4 FUN_c03fb314(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_38 [2];
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 local_24;
  
  local_2c = (undefined4 *)0x0;
  local_30 = (undefined4 *)0x0;
  local_24 = 0;
  FUN_c03f48c0((int *)&local_30,param_3,4,8,0,0);
  puVar4 = local_30;
  if ((local_30 != (undefined4 *)0x0) || (puVar4 = local_2c, local_2c != (undefined4 *)0x0)) {
    piVar1 = FUN_c03fa760(param_1,2,param_2);
    if (piVar1 == (int *)0x0) {
      uVar3 = 5;
      goto LAB_c03fb3b0;
    }
    uVar3 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],0xe,piVar1[0xb],local_38,0);
    FUN_c03fa830(piVar1);
    *puVar4 = local_38[0];
    iVar2 = FUN_c03f28a8((int *)&local_30);
    if (-1 < iVar2) goto LAB_c03fb3b0;
  }
  uVar3 = 0xb;
LAB_c03fb3b0:
  FUN_c03f28a8((int *)&local_30);
  return uVar3;
}



/* c03fb454 FUN_c03fb454 */

/* Boundary evidence: original MIPS .pdata c03fb454..c03fb45f. Semantic name remains unreviewed. */

undefined4 FUN_c03fb454(void)

{
  return 1;
}



/* c03fb460 FUN_c03fb460 */

/* Boundary evidence: original MIPS .pdata c03fb460..c03fb59f. Semantic name remains unreviewed. */

undefined4 FUN_c03fb460(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_38 [2];
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 local_24;
  
  local_2c = (undefined4 *)0x0;
  local_30 = (undefined4 *)0x0;
  local_24 = 0;
  FUN_c03f48c0((int *)&local_30,param_3,4,8,0,0);
  puVar4 = local_30;
  if ((local_30 != (undefined4 *)0x0) || (puVar4 = local_2c, local_2c != (undefined4 *)0x0)) {
    piVar1 = FUN_c03fa760(param_1,2,param_2);
    if (piVar1 == (int *)0x0) {
      uVar3 = 5;
      goto LAB_c03fb4fc;
    }
    uVar3 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],0x12,piVar1[0xb],local_38,0);
    FUN_c03fa830(piVar1);
    *puVar4 = local_38[0];
    iVar2 = FUN_c03f28a8((int *)&local_30);
    if (-1 < iVar2) goto LAB_c03fb4fc;
  }
  uVar3 = 0xb;
LAB_c03fb4fc:
  FUN_c03f28a8((int *)&local_30);
  return uVar3;
}



/* c03fb5a0 FUN_c03fb5a0 */

/* Boundary evidence: original MIPS .pdata c03fb5a0..c03fb5ab. Semantic name remains unreviewed. */

undefined4 FUN_c03fb5a0(void)

{
  return 1;
}



/* c03fb5ac FUN_c03fb5ac */

/* Boundary evidence: original MIPS .pdata c03fb5ac..c03fb757. Semantic name remains unreviewed. */

undefined4 FUN_c03fb5ac(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_38 [2];
  int *local_30;
  int *local_2c;
  undefined4 local_24;
  
  local_2c = (int *)0x0;
  local_30 = (int *)0x0;
  local_24 = 0;
  FUN_c03f48c0((int *)&local_30,param_3,4,8,0,0);
  piVar4 = local_30;
  if ((local_30 != (int *)0x0) || (piVar4 = local_2c, local_2c != (int *)0x0)) {
    uVar3 = 0;
    iVar1 = FUN_c03f2a7c(param_2);
    if (iVar1 == 0) {
      piVar2 = FUN_c03fa760(param_1,2,param_2);
      if (piVar2 == (int *)0x0) {
        uVar3 = 5;
        goto LAB_c03fb6d0;
      }
      local_38[0] = piVar2[0x13];
      FUN_c03fa830(piVar2);
    }
    else {
      uVar3 = 2;
      piVar2 = (int *)FUN_c03f45a0(2,param_2);
      if (piVar2 == (int *)0x0) goto LAB_c03fb6d0;
      uVar3 = (**(code **)(*piVar2 + 4))(piVar2,0x10,0,local_38,0);
      (**(code **)(*(int *)((int)piVar2 + *(int *)(piVar2[1] + 4) + 4) + 8))();
    }
    *piVar4 = local_38[0];
    iVar1 = FUN_c03f28a8((int *)&local_30);
    if (-1 < iVar1) goto LAB_c03fb6d0;
  }
  uVar3 = 0xb;
LAB_c03fb6d0:
  FUN_c03f28a8((int *)&local_30);
  return uVar3;
}



/* c03fb758 FUN_c03fb758 */

/* Boundary evidence: original MIPS .pdata c03fb758..c03fb763. Semantic name remains unreviewed. */

undefined4 FUN_c03fb758(void)

{
  return 1;
}



/* c03fb764 FUN_c03fb764 */

/* Boundary evidence: original MIPS .pdata c03fb764..c03fb857. Semantic name remains unreviewed. */

undefined4 FUN_c03fb764(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_c03f2a7c(param_2);
  if (iVar1 == 0) {
    piVar2 = FUN_c03fa760(param_1,2,param_2);
    if (piVar2 == (int *)0x0) {
      uVar3 = 5;
    }
    else {
      piVar2[0x13] = param_3;
      uVar3 = FUN_c03faf70(DAT_c04011f8,(int)piVar2);
      FUN_c03fa830(piVar2);
    }
  }
  else {
    uVar3 = 2;
    piVar2 = (int *)FUN_c03f45a0(2,param_2);
    if (piVar2 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar2 + 4))(piVar2,0x11,0,param_3,0);
      (**(code **)(*(int *)((int)piVar2 + *(int *)(piVar2[1] + 4) + 4) + 8))();
    }
  }
  return uVar3;
}



/* c03fb858 FUN_c03fb858 */

/* Boundary evidence: original MIPS .pdata c03fb858..c03fb923. Semantic name remains unreviewed. */

void FUN_c03fb858(LPCRITICAL_SECTION param_1,int param_2,int *param_3)

{
  HANDLE pvVar1;
  HANDLE pvVar2;
  
  EnterCriticalSection(param_1);
  pvVar2 = (&param_1[1].OwningThread)[param_2 * 2];
  pvVar1 = (HANDLE)*param_3;
  (&param_1[1].RecursionCount)[param_2 * 2] = param_3[1];
  (&param_1[1].OwningThread)[param_2 * 2] = (HANDLE)*param_3;
  if ((pvVar2 != pvVar1) ||
     ((*param_3 == param_1[1].LockCount &&
      (param_1[1].DebugInfo < (PRTL_CRITICAL_SECTION_DEBUG)param_3[1])))) {
    FUN_c03fb0e8((int)param_1,(int *)0x0);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* c03fb924 FUN_c03fb924 */

/* Boundary evidence: original MIPS .pdata c03fb924..c03fb9bf. Semantic name remains unreviewed. */

void FUN_c03fb924(LPCRITICAL_SECTION param_1,int param_2,undefined4 *param_3)

{
  HANDLE pvVar1;
  
  EnterCriticalSection(param_1);
  pvVar1 = (HANDLE)(&param_1[1].RecursionCount + *(int *)(param_2 + 0x48) * 2)[1];
  if (((HANDLE)param_1[1].LockCount < pvVar1) ||
     ((pvVar1 == (HANDLE)param_1[1].LockCount &&
      (param_1[1].DebugInfo <
       (PRTL_CRITICAL_SECTION_DEBUG)(&param_1[1].RecursionCount)[*(int *)(param_2 + 0x48) * 2])))) {
    *param_3 = 1;
    FUN_c03fb0e8((int)param_1,(int *)0x0);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* c03fb9c0 FUN_c03fb9c0 */

/* Boundary evidence: original MIPS .pdata c03fb9c0..c03fba2f. Semantic name remains unreviewed. */

void FUN_c03fb9c0(LPCRITICAL_SECTION param_1,int *param_2)

{
  EnterCriticalSection(param_1);
  if ((param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) &&
     ((&param_1[1].OwningThread)[param_2[0x12] * 2] == (HANDLE)param_1[1].LockCount)) {
    FUN_c03fb0e8((int)param_1,param_2);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* c03fba30 FUN_c03fba30 */

/* Boundary evidence: original MIPS .pdata c03fba30..c03fbaa3. Semantic name remains unreviewed. */

undefined4 FUN_c03fba30(int param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03fa760(param_1,1,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],0x39,piVar1[0xb],0,0);
    FUN_c03fa830(piVar1);
  }
  return uVar2;
}



/* c03fbaa4 FUN_c03fbaa4 */

/* Boundary evidence: original MIPS .pdata c03fbaa4..c03fbb17. Semantic name remains unreviewed. */

undefined4 FUN_c03fbaa4(int param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03fa760(param_1,1,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(*(int *)piVar1[0xd] + 4))((int *)piVar1[0xd],0x3a,piVar1[0xb],0,0);
    FUN_c03fa830(piVar1);
  }
  return uVar2;
}



/* c03fbb18 FUN_c03fbb18 */

/* Boundary evidence: original MIPS .pdata c03fbb18..c03fbb77. Semantic name remains unreviewed. */

void FUN_c03fbb18(int *param_1)

{
  int iVar1;
  
  if ((int *)param_1[1] != (int *)0x0) {
    FUN_c03fa830((int *)param_1[1]);
  }
  iVar1 = *param_1;
  if (iVar1 != 0) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + iVar1 + 4) + 8))();
  }
  return;
}



/* c03fbb78 FUN_c03fbb78 */

/* Boundary evidence: original MIPS .pdata c03fbb78..c03fbbc7. Semantic name remains unreviewed. */

void FUN_c03fbb78(int param_1,UINT param_2,undefined4 param_3,LPARAM param_4)

{
  if (((param_2 == 0x3d0) || (param_2 == 0x3d1)) &&
     ((*(uint *)(param_1 + 0x28) & 0x70000) == 0x10000)) {
    PostMessageW(*(HWND *)(param_1 + 0x20),param_2,*(WPARAM *)(param_1 + 0x1c),param_4);
  }
  return;
}



/* c03fbbc8 FUN_c03fbbc8 */

/* Boundary evidence: original MIPS .pdata c03fbbc8..c03fbd4b. Semantic name remains unreviewed. */

undefined4 FUN_c03fbbc8(int param_1,uint param_2,int *param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  param_3[1] = 0;
  *param_3 = 0;
  param_3[2] = 0;
  uVar3 = param_4 & 0xf0000000;
  uVar4 = 3;
  if (uVar3 == 0) {
    piVar1 = FUN_c03fa760(param_1,3,param_2);
    param_3[1] = (int)piVar1;
    if (piVar1 != (int *)0x0) goto LAB_c03fbc90;
  }
  if ((param_4 & 0x80000000) == 0) {
    if (uVar3 == 0) {
      iVar2 = audmGetMixerDevice(param_2,param_3);
    }
    else if (uVar3 == 0x10000000) {
      iVar2 = audmGetOutputDevice(param_2,param_3);
    }
    else {
      if (uVar3 != 0x20000000) {
        return 0xb;
      }
      iVar2 = audmGetInputDevice(param_2,param_3);
    }
    if (-1 < iVar2) {
      return 0;
    }
    return 2;
  }
  if (uVar3 != 0x80000000) {
    if (uVar3 == 0x90000000) {
      uVar4 = 2;
    }
    else {
      if (uVar3 != 0xa0000000) {
        return 0xb;
      }
      uVar4 = 1;
    }
  }
  piVar1 = FUN_c03fa760(param_1,uVar4,param_2);
  param_3[1] = (int)piVar1;
  if (piVar1 == (int *)0x0) {
    return 5;
  }
LAB_c03fbc90:
  param_3[2] = piVar1[0xb];
  iVar2 = piVar1[0xd];
  *param_3 = iVar2;
  (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + iVar2 + 4) + 4))();
  return 0;
}



/* c03fbd4c FUN_c03fbd4c */

/* Boundary evidence: original MIPS .pdata c03fbd4c..c03fbe0f. Semantic name remains unreviewed. */

undefined4 FUN_c03fbd4c(int param_1,HLOCAL param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_28;
  int local_24;
  undefined4 local_1c;
  
  local_24 = 0;
  local_28 = 0;
  local_1c = 0;
  uVar2 = 0;
  FUN_c03f48c0(&local_28,param_1,param_3,8,0,0);
  iVar1 = local_28;
  if (local_28 == 0) {
    iVar1 = local_24;
  }
  if (iVar1 != 0) {
    iVar1 = local_28;
    if (local_28 == 0) {
      iVar1 = local_24;
    }
    iVar1 = CeSafeCopyMemory(iVar1,param_2,param_3);
    if ((iVar1 != 0) && (iVar1 = FUN_c03f28a8(&local_28), -1 < iVar1)) goto LAB_c03fbde4;
  }
  uVar2 = 0xb;
LAB_c03fbde4:
  LocalFree(param_2);
  FUN_c03f28a8(&local_28);
  return uVar2;
}



/* c03fbe10 FUN_c03fbe10 */

/* Boundary evidence: original MIPS .pdata c03fbe10..c03fbf2f. Semantic name remains unreviewed. */

int FUN_c03fbe10(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_40 [2];
  undefined4 *local_38 [4];
  int local_28;
  int local_24;
  undefined4 local_1c;
  
  local_24 = 0;
  local_28 = 0;
  local_1c = 0;
  FUN_c03f48c0(&local_28,param_3,4,8,0,0);
  if ((local_28 != 0) || (local_24 != 0)) {
    iVar1 = FUN_c03fbbc8(param_1,param_2,(int *)local_38,param_4);
    if (iVar1 != 0) goto LAB_c03fbf0c;
    iVar2 = (**(code **)*local_38[0])(local_38[0],3,local_40);
    if (iVar2 < 0) {
      local_40[0] = 0xfffffffe;
      iVar1 = 0xb;
    }
    FUN_c03fbb18((int *)local_38);
    if (iVar1 != 0) goto LAB_c03fbf0c;
    iVar2 = local_28;
    if (local_28 == 0) {
      iVar2 = local_24;
    }
    iVar2 = CeSafeCopyMemory(iVar2,local_40,4);
    if ((iVar2 != 0) && (iVar2 = FUN_c03f28a8(&local_28), -1 < iVar2)) goto LAB_c03fbf0c;
  }
  iVar1 = 0xb;
LAB_c03fbf0c:
  FUN_c03f28a8(&local_28);
  return iVar1;
}



/* c03fbf30 FUN_c03fbf30 */

/* Boundary evidence: original MIPS .pdata c03fbf30..c03fc0c7. Semantic name remains unreviewed. */

int FUN_c03fbf30(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_160;
  int local_15c;
  undefined4 local_154;
  int *local_148 [2];
  undefined4 local_140;
  undefined1 local_138 [280];
  uint local_20;
  
  local_20 = DAT_c04011e8;
  local_15c = 0;
  local_160 = 0;
  local_154 = 0;
  FUN_c03f48c0(&local_160,param_3,0x118,0xc,0,0);
  iVar3 = local_160;
  if (local_160 == 0) {
    iVar3 = local_15c;
  }
  if (iVar3 == 0) {
LAB_c03fbfac:
    FUN_c03f28a8(&local_160);
    FUN_c0400008(local_20);
    return 0xb;
  }
  iVar3 = local_160;
  if (local_160 == 0) {
    iVar3 = local_15c;
  }
  iVar3 = CeSafeCopyMemory(local_138,iVar3,0x118);
  if (iVar3 == 0) goto LAB_c03fbfac;
  if (0x117 < (uint)local_138._0_4_) {
    puVar1 = local_138 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x118U >> (3 - uVar2) * 8;
    local_138._0_4_ = 0x118;
    iVar3 = FUN_c03fbbc8(param_1,param_2,(int *)local_148,param_4);
    if (iVar3 != 0) goto LAB_c03fc098;
    iVar3 = (**(code **)(*local_148[0] + 8))(local_148[0],5,local_140,local_138,param_4 & 0xfffffff)
    ;
    FUN_c03fbb18((int *)local_148);
    if (iVar3 != 0) goto LAB_c03fc098;
    iVar4 = local_160;
    if (local_160 == 0) {
      iVar4 = local_15c;
    }
    iVar4 = CeSafeCopyMemory(iVar4,local_138,0x118);
    if ((iVar4 != 0) && (iVar4 = FUN_c03f28a8(&local_160), -1 < iVar4)) goto LAB_c03fc098;
  }
  iVar3 = 0xb;
LAB_c03fc098:
  FUN_c03f28a8(&local_160);
  FUN_c0400008(local_20);
  return iVar3;
}



/* c03fc0c8 FUN_c03fc0c8 */

/* Boundary evidence: original MIPS .pdata c03fc0c8..c03fc2ab. Semantic name remains unreviewed. */

int FUN_c03fc0c8(int param_1,int param_2,uint param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *local_50 [4];
  int *local_40;
  undefined4 local_3c;
  code *local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  undefined4 local_24;
  
  if ((((param_6 & 0x70000) != 0) && ((param_6 & 0x10000) != 0x10000)) || (param_2 == 0)) {
    return 0xb;
  }
  iVar1 = FUN_c03fbbc8(param_1,param_3,(int *)local_50,param_6);
  if (iVar1 != 0) {
    return iVar1;
  }
  piVar2 = FUN_c03fab64(param_1,(int)local_50[0],3,param_4,param_5,param_6 & 0x70000);
  if (piVar2 == (int *)0x0) {
    iVar1 = 7;
    goto LAB_c03fc280;
  }
  local_38 = FUN_c03fbb78;
  local_3c = 0;
  local_34 = 0;
  local_40 = piVar2;
  iVar1 = (**(code **)(*local_50[0] + 8))(local_50[0],3,piVar2 + 0xb,&local_40,0x30000);
  if (iVar1 != 0) {
    FUN_c03fa7c0(param_1,piVar2);
    goto LAB_c03fc280;
  }
  local_2c = 0;
  local_30 = 0;
  local_24 = 0;
  FUN_c03f48c0(&local_30,param_2,4,8,0,0);
  iVar3 = local_30;
  if (local_30 == 0) {
    iVar3 = local_2c;
  }
  if (iVar3 == 0) {
LAB_c03fc254:
    FUN_c03fa7c0(param_1,piVar2);
    piVar2 = (int *)0x0;
    iVar1 = 0xb;
  }
  else {
    iVar3 = local_30;
    if (local_30 == 0) {
      iVar3 = local_2c;
    }
    iVar3 = CeSafeCopyMemory(iVar3,piVar2 + 7,4);
    if ((iVar3 == 0) || (iVar3 = FUN_c03f28a8(&local_30), iVar3 < 0)) goto LAB_c03fc254;
  }
  FUN_c03f28a8(&local_30);
  if (piVar2 != (int *)0x0) {
    FUN_c03fa830(piVar2);
  }
LAB_c03fc280:
  FUN_c03fbb18((int *)local_50);
  return iVar1;
}



/* c03fc2ac FUN_c03fc2ac */

/* Boundary evidence: original MIPS .pdata c03fc2ac..c03fc577. Semantic name remains unreviewed. */

undefined4 FUN_c03fc2ac(int param_1,int param_2,SIZE_T *param_3,int *param_4)

{
  uint uBytes;
  int iVar1;
  uint *puVar2;
  SIZE_T *pSVar3;
  HLOCAL pvVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint local_60;
  SIZE_T local_5c;
  uint local_58;
  SIZE_T local_54;
  int local_50;
  int local_4c;
  undefined4 local_44;
  int local_38;
  int local_34;
  undefined4 local_2c;
  
  local_4c = 0;
  local_50 = 0;
  local_44 = 0;
  FUN_c03f48c0(&local_50,param_2,0x18,4,0,0);
  iVar1 = local_50;
  if (local_50 == 0) {
    iVar1 = local_4c;
  }
  if (iVar1 == 0) {
LAB_c03fc330:
    FUN_c03f28a8(&local_50);
    return 0xb;
  }
  iVar1 = local_50;
  if (local_50 == 0) {
    iVar1 = local_4c;
  }
  iVar1 = CeSafeCopyMemory(param_1,iVar1,0x18);
  if ((iVar1 == 0) || (local_60 = *(uint *)(param_1 + 0x10), local_60 < 4)) goto LAB_c03fc330;
  local_5c = 0xffffffff;
  if (*(uint *)(param_1 + 8) != 0) {
    puVar2 = FUN_c03fca9c(&local_60,local_60,*(uint *)(param_1 + 8));
    local_60 = *puVar2;
    local_58 = local_60;
    if (*(uint *)(param_1 + 0xc) != 0) {
      pSVar3 = FUN_c03fca9c(&local_58,local_60,*(uint *)(param_1 + 0xc));
      local_60 = *pSVar3;
      local_54 = local_60;
    }
  }
  uBytes = local_60;
  local_34 = 0;
  local_38 = 0;
  local_2c = 0;
  piVar6 = (int *)(param_1 + 0x14);
  local_5c = local_60;
  FUN_c03f48c0(&local_38,*piVar6,local_60,0xc,0,0);
  if ((local_38 != 0) || (local_34 != 0)) {
    iVar1 = *piVar6;
    pvVar4 = LocalAlloc(0,uBytes);
    *piVar6 = (int)pvVar4;
    if (pvVar4 == (HLOCAL)0x0) {
      uVar7 = 7;
      goto LAB_c03fc4f8;
    }
    iVar5 = local_38;
    if (local_38 == 0) {
      iVar5 = local_34;
    }
    iVar5 = CeSafeCopyMemory(pvVar4,iVar5,uBytes);
    if (iVar5 != 0) {
      *param_3 = uBytes;
      *param_4 = iVar1;
      FUN_c03f28a8(&local_38);
      FUN_c03f28a8(&local_50);
      return 0;
    }
    LocalFree((HLOCAL)*piVar6);
    *piVar6 = *param_4;
    *param_4 = 0;
  }
  uVar7 = 0xb;
LAB_c03fc4f8:
  FUN_c03f28a8(&local_38);
  FUN_c03f28a8(&local_50);
  return uVar7;
}



/* c03fc578 FUN_c03fc578 */

/* Boundary evidence: original MIPS .pdata c03fc578..c03fc583. Semantic name remains unreviewed. */

undefined4 FUN_c03fc578(void)

{
  return 1;
}



/* c03fc584 FUN_c03fc584 */

/* Boundary evidence: original MIPS .pdata c03fc584..c03fc663. Semantic name remains unreviewed. */

int FUN_c03fc584(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  SIZE_T local_48;
  int local_44;
  int *local_40 [2];
  undefined4 local_38;
  undefined1 auStack_30 [20];
  HLOCAL local_1c;
  
  iVar1 = FUN_c03fc2ac((int)auStack_30,param_3,&local_48,&local_44);
  if (iVar1 == 0) {
    iVar1 = FUN_c03fbbc8(param_1,param_2,(int *)local_40,param_4);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_40[0] + 8))(local_40[0],7,local_38,auStack_30,param_4 & 0xfffffff)
      ;
      FUN_c03fbb18((int *)local_40);
    }
    iVar2 = FUN_c03fbd4c(local_44,local_1c,local_48);
    if (iVar1 == 0) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}



/* c03fc664 FUN_c03fc664 */

/* Boundary evidence: original MIPS .pdata c03fc664..c03fc9af. Semantic name remains unreviewed. */

int FUN_c03fc664(int param_1,uint param_2,int param_3,uint param_4)

{
  HLOCAL pvVar1;
  int iVar2;
  SIZE_T *pSVar3;
  int iVar4;
  SIZE_T uBytes;
  SIZE_T local_88;
  SIZE_T local_84;
  SIZE_T local_80;
  int *local_78 [2];
  undefined4 local_70;
  int local_68;
  int local_64;
  undefined4 local_5c;
  int local_50;
  int local_4c;
  undefined4 local_44;
  uint local_38 [3];
  uint local_2c;
  uint local_28;
  HLOCAL local_24;
  
  local_64 = 0;
  local_68 = 0;
  local_5c = 0;
  FUN_c03f48c0(&local_68,param_3,0x18,0xc,0,0);
  iVar2 = local_68;
  if (local_68 == 0) {
    iVar2 = local_64;
  }
  if (iVar2 == 0) {
LAB_c03fc6f4:
    FUN_c03f28a8(&local_68);
    return 0xb;
  }
  iVar2 = local_68;
  if (local_68 == 0) {
    iVar2 = local_64;
  }
  iVar2 = CeSafeCopyMemory(local_38,iVar2,0x18);
  if ((iVar2 == 0) || (local_38[0] < 0x18)) goto LAB_c03fc6f4;
  local_88 = local_28;
  pSVar3 = FUN_c03fca9c(&local_88,local_28,local_2c);
  pvVar1 = local_24;
  uBytes = *pSVar3;
  local_88 = uBytes;
  local_84 = uBytes;
  local_80 = uBytes;
  if (local_24 == (HLOCAL)0x0) goto LAB_c03fc6f4;
  local_4c = 0;
  local_50 = 0;
  local_44 = 0;
  FUN_c03f48c0(&local_50,(int)local_24,uBytes,0xc,0,0);
  if ((local_50 != 0) || (local_4c != 0)) {
    local_24 = LocalAlloc(0,uBytes);
    if (local_24 == (HLOCAL)0x0) {
      iVar2 = 7;
      goto LAB_c03fc82c;
    }
    iVar2 = FUN_c03fbbc8(param_1,param_2,(int *)local_78,param_4);
    if (iVar2 != 0) {
      LocalFree(local_24);
      goto LAB_c03fc82c;
    }
    iVar2 = (**(code **)(*local_78[0] + 8))(local_78[0],6,local_70,local_38,param_4 & 0xfffffff);
    FUN_c03fbb18((int *)local_78);
    if (iVar2 == 0) {
      iVar4 = local_50;
      if (local_50 == 0) {
        iVar4 = local_4c;
      }
      iVar4 = CeSafeCopyMemory(iVar4,local_24,uBytes);
      if ((iVar4 == 0) || (iVar4 = FUN_c03f28a8(&local_50), iVar4 < 0)) {
        iVar2 = 0xb;
      }
    }
    LocalFree(local_24);
    local_24 = pvVar1;
    if (iVar2 != 0) goto LAB_c03fc82c;
    iVar4 = local_68;
    if (local_68 == 0) {
      iVar4 = local_64;
    }
    iVar4 = CeSafeCopyMemory(iVar4,local_38,0x18);
    if ((iVar4 != 0) && (iVar4 = FUN_c03f28a8(&local_68), -1 < iVar4)) goto LAB_c03fc82c;
  }
  iVar2 = 0xb;
LAB_c03fc82c:
  FUN_c03f28a8(&local_50);
  FUN_c03f28a8(&local_68);
  return iVar2;
}



/* c03fc9b0 FUN_c03fc9b0 */

/* Boundary evidence: original MIPS .pdata c03fc9b0..c03fc9bb. Semantic name remains unreviewed. */

undefined4 FUN_c03fc9b0(void)

{
  return 1;
}



/* c03fc9bc FUN_c03fc9bc */

/* Boundary evidence: original MIPS .pdata c03fc9bc..c03fca9b. Semantic name remains unreviewed. */

int FUN_c03fc9bc(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  SIZE_T local_48;
  int local_44;
  int *local_40 [2];
  undefined4 local_38;
  undefined1 auStack_30 [20];
  HLOCAL local_1c;
  
  iVar1 = FUN_c03fc2ac((int)auStack_30,param_3,&local_48,&local_44);
  if (iVar1 == 0) {
    iVar1 = FUN_c03fbbc8(param_1,param_2,(int *)local_40,param_4);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_40[0] + 8))(local_40[0],8,local_38,auStack_30,param_4 & 0xfffffff)
      ;
      FUN_c03fbb18((int *)local_40);
    }
    iVar2 = FUN_c03fbd4c(local_44,local_1c,local_48);
    if (iVar1 == 0) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}



/* c03fca9c FUN_c03fca9c */

/* Boundary evidence: original MIPS .pdata c03fca9c..c03fcaef. Semantic name remains unreviewed. */

undefined4 * FUN_c03fca9c(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = (undefined4)((ulonglong)param_2 * (ulonglong)param_3);
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) != 0) {
    param_1 = (undefined4 *)&DAT_c0000095;
    RaiseException(0xc0000095,0,0,(ULONG_PTR *)0x0);
  }
  *param_1 = uVar1;
  return param_1;
}



/* c03fcaf0 FUN_c03fcaf0 */

/* Boundary evidence: original MIPS .pdata c03fcaf0..c03fcc67. Semantic name remains unreviewed. */

int FUN_c03fcaf0(int param_1,void *param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  undefined4 local_6c;
  WCHAR aWStack_68 [32];
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined4 local_20;
  uint local_1c;
  
  local_1c = DAT_c04011e8;
  if (param_1 == 0) {
    if (0x54 < param_3) {
      param_3 = 0x54;
    }
    uVar2 = waveOutGetNumDevs();
  }
  else {
    if (0x50 < param_3) {
      param_3 = 0x50;
    }
    uVar2 = waveInGetNumDevs();
  }
  bVar1 = false;
  uVar5 = 0;
  if (uVar2 == 0) {
LAB_c03fcbb8:
    local_20 = 0xc;
    iVar3 = 0;
  }
  else {
    do {
      uVar4 = uVar5;
      if (bVar1) goto LAB_c03fcbb8;
      uVar5 = uVar4 + 1;
      bVar1 = true;
    } while (uVar5 < uVar2);
    if (param_1 == 0) {
      iVar3 = waveOutGetDevCaps(uVar4,&local_70,param_3);
    }
    else {
      iVar3 = waveInGetDevCaps();
    }
  }
  if (iVar3 == 0) {
    local_6f = 0;
    local_6d = 0;
    local_23 = 0;
    local_70 = 1;
    local_6e = 2;
    local_6c = 0x332;
    local_24 = 2;
    LoadStringW((HINSTANCE)*DAT_c04013cc,400,aWStack_68,0x20);
    local_28 = 0xfff;
    memcpy(param_2,&local_70,param_3);
    iVar3 = 0;
  }
  FUN_c0400008(local_1c);
  return iVar3;
}



/* c03fcc68 FUN_c03fcc68 */

undefined4 FUN_c03fcc68(undefined4 param_1)

{
  DAT_c04013cc = &DAT_c04013d0;
  DAT_c04013d0 = param_1;
  return 1;
}



/* c03fcc84 FUN_c03fcc84 */

/* Boundary evidence: original MIPS .pdata c03fcc84..c03fccb7. Semantic name remains unreviewed. */

void FUN_c03fcc84(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x28))
            (*(undefined4 *)(param_1 + 0x34),param_2,*(undefined4 *)(param_1 + 0x2c),param_3,param_4
            );
  return;
}



/* c03fccb8 FUN_c03fccb8 */

/* Boundary evidence: original MIPS .pdata c03fccb8..c03fcd5f. Semantic name remains unreviewed. */

void FUN_c03fccb8(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  if (param_2 == 0x3bd) {
    if (*(int *)(param_3 + 0xc) != 0) {
      param_4 = (undefined4 *)param_4[3];
      param_4[4] = param_4[4] & 0xffffffef | 1;
    }
    (**(code **)(param_3 + 0x28))
              (*(undefined4 *)(param_3 + 0x34),0x3bd,*(undefined4 *)(param_3 + 0x2c),param_4,0);
  }
  else if (param_2 == 0x3c0) {
    if (*(int *)(param_3 + 0xc) == 0) {
      (**(code **)(param_3 + 0x28))
                (*(undefined4 *)(param_3 + 0x34),0x3c0,*(undefined4 *)(param_3 + 0x2c),param_4,0);
    }
    else {
      FUN_c03f56f8(param_4);
    }
  }
  return;
}



/* c03fcd60 FUN_c03fcd60 */

/* Boundary evidence: original MIPS .pdata c03fcd60..c03fcebb. Semantic name remains unreviewed. */

int FUN_c03fcd60(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 < 0xc) {
LAB_c03fcd88:
    iVar1 = 1;
  }
  else {
    if ((*param_2 != 2) && (*param_2 != 4)) {
      *param_2 = 4;
    }
    iVar1 = (**(code **)(param_1 + 0x5c))(*(undefined4 *)(param_1 + 0x44),param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      if (*param_2 == 2) {
        uVar2 = *(uint *)(*(int *)(param_1 + 0x38) + 4);
        if (uVar2 == 0) {
          trap(0x1c00);
        }
        param_2[1] = (*(int *)(*(int *)(param_1 + 0x30) + 4) * param_2[1] + (uVar2 >> 1)) / uVar2;
      }
      else {
        if (*param_2 != 4) goto LAB_c03fcd88;
        uVar2 = *(uint *)(*(int *)(param_1 + 0x38) + 8);
        if (uVar2 == 0) {
          trap(0x1c00);
        }
        param_2[1] = (*(int *)(*(int *)(param_1 + 0x30) + 8) * param_2[1] + (uVar2 >> 1)) / uVar2;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c03fcebc FUN_c03fcebc */

undefined4 FUN_c03fcebc(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = 1;
    if (param_1 == 1) {
      uVar1 = 0;
    }
    else if (param_1 == 4) {
      uVar1 = 5;
    }
    else if (param_1 == 7) {
      uVar1 = 2;
    }
    else if (param_1 == 0x20) {
      uVar1 = 4;
    }
    else if (param_1 == 0x23) {
      uVar1 = 3;
    }
  }
  return uVar1;
}



/* c03fcf34 FUN_c03fcf34 */

/* Boundary evidence: original MIPS .pdata c03fcf34..c03fcf8b. Semantic name remains unreviewed. */

void FUN_c03fcf34(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_c03fcebc(*param_1);
  uVar2 = FUN_c03fcebc(param_2);
  if (uVar1 < uVar2) {
    *param_1 = param_2;
  }
  return;
}



/* c03fcf8c FUN_c03fcf8c */

undefined4 FUN_c03fcf8c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 6;
  }
  else {
    uVar1 = 1;
    if (param_1 == 1) {
      uVar1 = 0;
    }
    else if (param_1 == 4) {
      uVar1 = 4;
    }
    else if (param_1 == 7) {
      uVar1 = 2;
    }
    else if (param_1 == 0x20) {
      uVar1 = 5;
    }
    else if (param_1 == 0x23) {
      uVar1 = 3;
    }
  }
  return uVar1;
}



/* c03fd004 FUN_c03fd004 */

/* Boundary evidence: original MIPS .pdata c03fd004..c03fd05b. Semantic name remains unreviewed. */

void FUN_c03fd004(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_c03fcf8c(*param_1);
  uVar2 = FUN_c03fcf8c(param_2);
  if (uVar1 < uVar2) {
    *param_1 = param_2;
  }
  return;
}



/* c03fd05c FUN_c03fd05c */

/* Boundary evidence: original MIPS .pdata c03fd05c..c03fd2af. Semantic name remains unreviewed. */

int FUN_c03fd05c(int *param_1,undefined4 param_2)

{
  bool bVar1;
  UINT UVar2;
  uint uVar3;
  int iVar4;
  int local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  uint local_30;
  
  local_30 = DAT_c04011e8;
  local_3a = 0x493a;
  local_40 = 0x40e953ae;
  local_34 = 0x30;
  local_3c = 0xee3e;
  local_38 = 0x93;
  local_37 = 0xee;
  local_36 = 0xda;
  local_35 = 0x3e;
  local_33 = 0x76;
  local_32 = 0x43;
  bVar1 = (param_1[8] & 1U) == 0;
  local_31 = 0x90;
  if (param_1[7] == 0) {
    UVar2 = waveOutGetNumDevs();
  }
  else {
    UVar2 = waveInGetNumDevs();
  }
  iVar4 = 0;
  local_50[0] = 1;
  if ((param_1[8] & 4U) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = param_1[9];
    UVar2 = uVar3 + 1;
  }
  do {
    if (UVar2 <= uVar3) {
LAB_c03fd278:
      FUN_c0400008(local_30);
      return local_50[0];
    }
    if (bVar1) {
      iVar4 = (*(code *)param_1[0x12])
                        (param_1 + 0x11,uVar3,param_2,0,0,*(ushort *)(param_1 + 8) & 0xfffb | 1);
    }
    if (iVar4 == 0) {
      iVar4 = (*(code *)param_1[0x12])
                        (param_1 + 0x11,uVar3,param_2,FUN_c03fccb8,param_1,
                         *(ushort *)(param_1 + 8) & 0xfffffffb | 0x30000);
    }
    FUN_c03fcf34(param_1,iVar4);
    FUN_c03fd004(local_50,iVar4);
    if ((iVar4 == 0) && (bVar1)) {
      param_1[0x10] = uVar3;
      if (param_1[7] == 0) {
        local_44 = 2;
        local_48 = 0;
        waveOutSetProperty(param_1[0x11],&local_40,1,0,0,&local_48,8);
      }
      goto LAB_c03fd278;
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



/* c03fd2b0 FUN_c03fd2b0 */

/* Boundary evidence: original MIPS .pdata c03fd2b0..c03fd337. Semantic name remains unreviewed. */

int FUN_c03fd2b0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c03ffd4c();
  if ((iVar1 == 0) && (iVar1 = FUN_c03ffd4c(), iVar1 == 0)) {
    iVar1 = FUN_c03fd05c(param_1,param_1[0xe]);
    return iVar1;
  }
  return 0x20;
}



/* c03fd338 FUN_c03fd338 */

/* Boundary evidence: original MIPS .pdata c03fd338..c03fd3db. Semantic name remains unreviewed. */

int FUN_c03fd338(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)param_1[0xe];
  *puVar2 = 1;
  puVar2[1] = 0;
  iVar1 = FUN_c03ffd4c();
  if ((iVar1 == 0) && (iVar1 = FUN_c03ffd4c(), iVar1 == 0)) {
    iVar1 = FUN_c03fd05c(param_1,param_1[0xe]);
    return iVar1;
  }
  return 0x20;
}



/* c03fd3dc FUN_c03fd3dc */

/* Boundary evidence: original MIPS .pdata c03fd3dc..c03fd48f. Semantic name remains unreviewed. */

int FUN_c03fd3dc(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)param_1[0xe];
  *puVar1 = 1;
  puVar1[1] = 0;
  iVar2 = param_1[0xe];
  *(undefined1 *)(iVar2 + 2) = 1;
  *(undefined1 *)(iVar2 + 3) = 0;
  iVar2 = FUN_c03ffd4c();
  if ((iVar2 == 0) && (iVar2 = FUN_c03ffd4c(), iVar2 == 0)) {
    iVar2 = FUN_c03fd05c(param_1,param_1[0xe]);
    return iVar2;
  }
  return 0x20;
}



/* c03fd490 FUN_c03fd490 */

/* Boundary evidence: original MIPS .pdata c03fd490..c03fd547. Semantic name remains unreviewed. */

int FUN_c03fd490(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)param_1[0xe];
  *puVar1 = 1;
  puVar1[1] = 0;
  iVar2 = param_1[0xe];
  *(undefined1 *)(iVar2 + 0xe) = 8;
  *(undefined1 *)(iVar2 + 0xf) = 0;
  iVar2 = FUN_c03ffd4c();
  if ((iVar2 == 0) && (iVar2 = FUN_c03ffd4c(), iVar2 == 0)) {
    iVar2 = FUN_c03fd05c(param_1,param_1[0xe]);
    return iVar2;
  }
  return 0x20;
}



/* c03fd548 FUN_c03fd548 */

/* Boundary evidence: original MIPS .pdata c03fd548..c03fd60f. Semantic name remains unreviewed. */

int FUN_c03fd548(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)param_1[0xe];
  *puVar1 = 1;
  puVar1[1] = 0;
  iVar2 = param_1[0xe];
  *(undefined1 *)(iVar2 + 2) = 1;
  *(undefined1 *)(iVar2 + 3) = 0;
  iVar2 = param_1[0xe];
  *(undefined1 *)(iVar2 + 0xe) = 8;
  *(undefined1 *)(iVar2 + 0xf) = 0;
  iVar2 = FUN_c03ffd4c();
  if ((iVar2 == 0) && (iVar2 = FUN_c03ffd4c(), iVar2 == 0)) {
    iVar2 = FUN_c03fd05c(param_1,param_1[0xe]);
    return iVar2;
  }
  return 0x20;
}



/* c03fd610 FUN_c03fd610 */

/* Boundary evidence: original MIPS .pdata c03fd610..c03fd7b3. Semantic name remains unreviewed. */

undefined4 FUN_c03fd610(undefined4 param_1,int *param_2,uint param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_90 [8];
  undefined1 local_88 [104];
  uint local_20;
  
  local_20 = DAT_c04011e8;
  if ((param_3 & param_2[6]) == 0) {
    FUN_c0400008(DAT_c04011e8);
    return 1;
  }
  auStack_90._0_4_ = ZEXT24(*(ushort *)param_2[0xc]);
  puVar1 = auStack_90 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 |
       (uint)(*(ushort *)param_2[0xc] >> (3 - uVar2) * 8);
  puVar1 = local_88 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  local_88._0_4_ = 0;
  iVar3 = FUN_c03ffd4c();
  if ((iVar3 == 0) && ((local_88._0_4_ & param_2[6]) != 0)) {
    iVar3 = FUN_c03ffd4c();
    if (iVar3 != 0) goto LAB_c03fd78c;
    iVar3 = param_2[1];
    if (iVar3 == 0) {
      iVar3 = FUN_c03fd2b0(param_2);
    }
    else if (iVar3 == 1) {
      iVar3 = FUN_c03fd338(param_2);
    }
    else if (iVar3 == 2) {
      iVar3 = FUN_c03fd3dc(param_2);
    }
    else if (iVar3 == 3) {
      iVar3 = FUN_c03fd490(param_2);
    }
    else {
      if (iVar3 != 4) goto LAB_c03fd768;
      iVar3 = FUN_c03fd548(param_2);
    }
    if (iVar3 != 0) {
      FUN_c03ffd4c();
      param_2[2] = 0;
      if (iVar3 != 4) goto LAB_c03fd78c;
    }
LAB_c03fd768:
    FUN_c0400008(local_20);
    return 0;
  }
LAB_c03fd78c:
  FUN_c0400008(local_20);
  return 1;
}



/* c03fd7b4 FUN_c03fd7b4 */

/* Boundary evidence: original MIPS .pdata c03fd7b4..c03fd8df. Semantic name remains unreviewed. */

undefined4 FUN_c03fd7b4(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 2;
  if (*(short *)param_1[0xc] != 1) {
    uVar3 = 1;
  }
  uVar2 = (uint)(*(short *)param_1[0xc] == 1);
  *param_1 = 0x20;
  param_1[2] = 0;
  uVar4 = uVar2;
  if (uVar2 < 5) {
    do {
      param_1[1] = uVar4;
      if (uVar4 == 0) {
        param_1[6] = 3;
      }
      else {
        param_1[6] = uVar3;
      }
      iVar1 = FUN_c03ffd4c();
      if ((iVar1 == 0) && (param_1[2] != 0)) {
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 5);
  }
  if (uVar2 != 0) {
    param_1[1] = 0;
    param_1[6] = 3;
    iVar1 = FUN_c03ffd4c();
    if ((iVar1 == 0) && (param_1[2] != 0)) {
      return 0;
    }
  }
  return *param_1;
}



/* c03fd8e0 FUN_c03fd8e0 */

/* Boundary evidence: original MIPS .pdata c03fd8e0..c03fd93f. Semantic name remains unreviewed. */

int FUN_c03fd8e0(HLOCAL param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)((int)param_1 + 0x4c))(*(undefined4 *)((int)param_1 + 0x44));
  if (iVar1 == 0) {
    if (*(int *)((int)param_1 + 0xc) != 0) {
      FUN_c03ffd4c();
      FUN_c03ffd4c();
    }
    LocalFree(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* c03fd940 FUN_c03fd940 */

/* Boundary evidence: original MIPS .pdata c03fd940..c03fdd1f. Semantic name remains unreviewed. */

uint FUN_c03fd940(uint param_1,uint *param_2,uint *param_3,uint param_4)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  undefined1 *puVar5;
  short *_Src;
  uint uVar6;
  size_t _Size;
  uint local_30;
  
  bVar1 = (param_4 & 1) == 0;
  _Src = (short *)param_3[1];
  if (*_Src == 1) {
    _Size = 0x10;
  }
  else {
    _Size = (ushort)_Src[8] + 0x12;
  }
  puVar2 = LocalAlloc(0,_Size + 100);
  if (puVar2 == (uint *)0x0) {
LAB_c03fdc14:
    uVar6 = 7;
  }
  else {
    puVar2[7] = param_1;
    puVar2[8] = param_4;
    puVar2[10] = param_3[2];
    puVar2[0xb] = param_3[3];
    puVar2[0xd] = *param_3;
    if ((param_4 & 4) != 0) {
      puVar2[9] = param_3[4];
    }
    puVar2[0xc] = (uint)(puVar2 + 0x19);
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x10] = 0xffffffff;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    memcpy(puVar2 + 0x19,_Src,_Size);
    if (param_1 == 0) {
      puVar2[0x12] = (uint)waveOutOpen;
      puVar2[0x13] = (uint)waveOutClose;
      puVar2[0x15] = (uint)waveOutUnprepareHeader;
      puVar2[0x14] = (uint)waveOutPrepareHeader;
      puVar5 = &LAB_c03ffc4c;
      puVar2[0x16] = (uint)waveOutWrite;
      puVar2[0x18] = (uint)waveOutMessage;
    }
    else {
      puVar2[0x12] = (uint)&LAB_c03ffcac;
      puVar2[0x13] = (uint)&LAB_c03ffc9c;
      puVar2[0x15] = (uint)&LAB_c03ffc8c;
      puVar2[0x14] = (uint)&LAB_c03ffc7c;
      puVar5 = &LAB_c03ffc5c;
      puVar2[0x16] = (uint)&LAB_c03ffc6c;
      puVar2[0x18] = (uint)waveInMessage;
    }
    puVar2[0x17] = (uint)puVar5;
    *param_2 = (uint)puVar2;
    *puVar2 = 1;
    iVar3 = FUN_c03fd05c((int *)puVar2,_Src);
    puVar4 = puVar2;
    if (iVar3 == 0) {
      if (bVar1) {
        return 0;
      }
      *param_2 = puVar2[0x10];
LAB_c03fdb5c:
      LocalFree(puVar4);
      return 0;
    }
    if (((puVar2[8] & 8) == 0) && (iVar3 != 4)) {
      iVar3 = FUN_c03ffd4c();
      if (iVar3 != 0) {
        local_30 = 0;
      }
      puVar4 = LocalReAlloc(puVar2,local_30 + _Size + 100,2);
      if (puVar4 == (uint *)0x0) {
        LocalFree(puVar2);
        goto LAB_c03fdc14;
      }
      puVar2 = puVar4 + 0x19;
      uVar6 = (int)puVar4 + _Size + 100;
      puVar4[0xc] = (uint)puVar2;
      puVar4[0xe] = uVar6;
      puVar4[0xf] = local_30;
      if (param_1 == 0) {
        puVar4[4] = (uint)puVar2;
        puVar4[5] = uVar6;
      }
      else {
        puVar4[4] = uVar6;
        puVar4[5] = (uint)puVar2;
      }
      *param_2 = (uint)puVar4;
      if ((param_1 != 0) && (bVar1)) {
        uVar6 = FUN_c03f5628(puVar4);
        return uVar6;
      }
      uVar6 = FUN_c03fd7b4(puVar4);
      if (uVar6 == 0) {
        if (bVar1) {
          uVar6 = FUN_c03ffd4c();
          if (uVar6 == 0) {
            return 0;
          }
          (*(code *)puVar4[0x13])(puVar4[0x11]);
          FUN_c03ffd4c();
          LocalFree(puVar4);
          if (0x1f < uVar6) {
            return 0x20;
          }
          return uVar6;
        }
        *param_2 = puVar4[0x10];
        FUN_c03ffd4c();
        goto LAB_c03fdb5c;
      }
    }
    else {
      uVar6 = *puVar2;
    }
    LocalFree(puVar4);
  }
  return uVar6;
}



/* c03fdd20 FUN_c03fdd20 */

/* Boundary evidence: original MIPS .pdata c03fdd20..c03fdfa7. Semantic name remains unreviewed. */

int FUN_c03fdd20(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *hMem;
  undefined4 uVar2;
  uint uVar3;
  uint local_20;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = (**(code **)(param_1 + 0x50))(*(undefined4 *)(param_1 + 0x44),param_2,0x20);
  }
  else {
    local_20 = param_2[1];
    if (*(int *)(param_1 + 0x1c) != 0) {
      uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x30) + 0xc);
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      local_20 = (local_20 / uVar3) * uVar3;
    }
    iVar1 = FUN_c03ffd4c();
    if (((iVar1 == 0) && (local_20 < 0xffffff87)) &&
       (hMem = LocalAlloc(0,local_20 + 0x78), hMem != (undefined4 *)0x0)) {
      hMem[6] = 0;
      hMem[7] = 0;
      hMem[8] = 0x54;
      hMem[9] = 0;
      hMem[10] = param_1;
      *hMem = hMem + 0x1d;
      hMem[1] = local_20;
      hMem[2] = 0;
      hMem[3] = param_2;
      if (*(int *)(param_1 + 0x1c) == 0) {
        hMem[4] = param_2[4] & 0xc;
        hMem[5] = param_2[5];
        hMem[0xb] = *param_2;
        hMem[0xc] = param_2[1];
        hMem[0xd] = 0;
        hMem[0xe] = hMem;
        hMem[0xf] = *hMem;
        hMem[0x10] = hMem[1];
        hMem[0x11] = 0;
        uVar2 = param_2[1];
      }
      else {
        hMem[4] = 0;
        hMem[5] = 0;
        hMem[0xb] = hMem + 0x1d;
        hMem[0xc] = hMem[1];
        hMem[0xd] = 0;
        hMem[0xe] = hMem;
        hMem[0xf] = *param_2;
        hMem[0x10] = param_2[1];
        hMem[0x11] = 0;
        uVar2 = hMem[1];
      }
      hMem[0x12] = uVar2;
      iVar1 = (**(code **)(param_1 + 0x50))(*(undefined4 *)(param_1 + 0x44),hMem,0x20);
      if (iVar1 == 0) {
        iVar1 = FUN_c03ffd4c();
        if (iVar1 == 0) {
          param_2[7] = hMem + 8;
          param_2[4] = param_2[4] | 2;
          return 0;
        }
        (**(code **)(param_1 + 0x54))(*(undefined4 *)(param_1 + 0x44),hMem,0x20);
      }
      LocalFree(hMem);
    }
    else {
      iVar1 = 7;
    }
  }
  return iVar1;
}



/* c03fdfa8 FUN_c03fdfa8 */

/* Boundary evidence: original MIPS .pdata c03fdfa8..c03fe0bf. Semantic name remains unreviewed. */

undefined4 FUN_c03fdfa8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  HLOCAL hMem;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar1 = (**(code **)(param_1 + 0x54))(*(undefined4 *)(param_1 + 0x44),param_2,0x20);
  }
  else {
    iVar2 = *(int *)(param_2 + 0x1c);
    hMem = *(HLOCAL *)(iVar2 + 0x18);
    if (*(int *)(param_1 + 0x1c) == 0) {
      uVar1 = *(undefined4 *)(iVar2 + 0x20);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 0x28);
    }
    else {
      uVar1 = *(undefined4 *)(iVar2 + 0x28);
      *(undefined4 *)(iVar2 + 0x10) = uVar1;
    }
    *(undefined4 *)((int)hMem + 4) = uVar1;
    uVar1 = (**(code **)(param_1 + 0x54))(*(undefined4 *)(param_1 + 0x44),hMem,0x20);
    if ((*(uint *)((int)hMem + 0x10) & 2) == 0) {
      FUN_c03ffd4c();
      LocalFree(hMem);
      *(undefined4 *)(param_2 + 0x1c) = 0;
      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xfffffffd;
    }
  }
  return uVar1;
}



/* c03fe0c0 FUN_c03fe0c0 */

/* Boundary evidence: original MIPS .pdata c03fe0c0..c03fe293. Semantic name remains unreviewed. */

int FUN_c03fe0c0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (param_1 == 0) {
    iVar1 = 0xb;
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = (**(code **)(param_1 + 0x58))(*(undefined4 *)(param_1 + 0x44),param_2,0x20);
  }
  else {
    iVar1 = param_2[7];
    if (iVar1 == 0) {
      iVar1 = 0x22;
    }
    else {
      puVar5 = *(undefined4 **)(iVar1 + 0x18);
      if (*(int *)(param_1 + 0x1c) == 0) {
        *(undefined4 *)(iVar1 + 0x24) = 0;
        if (param_2[1] != 0) {
          *(undefined4 *)(iVar1 + 0xc) = *param_2;
          *(undefined4 *)(iVar1 + 0x10) = param_2[1];
          *(undefined4 *)(iVar1 + 0x1c) = *puVar5;
          iVar2 = FUN_c03ffd4c();
          if (iVar2 != 0) {
            return iVar2;
          }
        }
        puVar5[4] = param_2[4] & 0xffffefff;
        puVar5[5] = param_2[5];
        puVar5[1] = *(undefined4 *)(iVar1 + 0x24);
      }
      else {
        uVar4 = (uint)*(ushort *)(*(int *)(param_1 + 0x30) + 0xc);
        uVar3 = param_2[1];
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        iVar1 = FUN_c03ffd4c();
        if (iVar1 != 0) {
          return 7;
        }
        puVar5[1] = (uVar3 / uVar4) * uVar4;
        puVar5[2] = 0;
        param_2[4] = param_2[4] & 0xfffffffe;
      }
      param_2[4] = param_2[4] | 0x10;
      iVar1 = (**(code **)(param_1 + 0x58))(*(undefined4 *)(param_1 + 0x44),puVar5,0x20);
      if (iVar1 != 0) {
        param_2[4] = param_2[4] & 0xffffffef;
      }
    }
  }
  return iVar1;
}



/* c03fe294 FUN_c03fe294 */

/* Boundary evidence: original MIPS .pdata c03fe294..c03fe2ef. Semantic name remains unreviewed. */

undefined4 FUN_c03fe294(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0xb;
  }
  else {
    *param_2 = 0;
  }
  return uVar1;
}



/* c03fe2f0 FUN_c03fe2f0 */

/* Boundary evidence: original MIPS .pdata c03fe2f0..c03fe2fb. Semantic name remains unreviewed. */

undefined4 FUN_c03fe2f0(void)

{
  return 1;
}



/* c03fe2fc FUN_c03fe2fc */

undefined4 FUN_c03fe2fc(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == -0x7ff8fff2) {
    return 7;
  }
  if (param_1 == -0x7787ff9c) {
LAB_c03fe394:
    uVar1 = 0x20;
  }
  else {
    if (param_1 != -0x777fffff) {
      if (param_1 == -0x777effff) goto LAB_c03fe394;
      if (param_1 == -0x777efffe) {
        return 4;
      }
      if (param_1 != -0x777efffd) {
        if (param_1 != 0) {
          return 1;
        }
        return 0;
      }
    }
    uVar1 = 6;
  }
  return uVar1;
}



/* c03fe3a8 FUN_c03fe3a8 */

/* Boundary evidence: original MIPS .pdata c03fe3a8..c03fe44f. Semantic name remains unreviewed. */

void FUN_c03fe3a8(int param_1)

{
  int iVar1;
  
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x1c) + 4) + param_1 + -0x1c) = &PTR_LAB_c03f2824;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x1c) + 8) + param_1 + -0x1c) = &PTR_LAB_c03f2814;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x1c) + 0xc) + param_1 + -0x1c) = &PTR_FUN_c03f2810;
  iVar1 = *(int *)(*(int *)(param_1 + -0x1c) + 4);
  *(int *)(iVar1 + param_1 + -0x20) = iVar1 + -0xc;
  iVar1 = *(int *)(*(int *)(param_1 + -0x1c) + 8);
  *(int *)(iVar1 + param_1 + -0x20) = iVar1 + -0x14;
  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x18) + 4) + 4) +
                        *(int *)(param_1 + -0x18) + 4) + 8))();
  return;
}



/* c03fe450 FUN_c03fe450 */

/* Boundary evidence: original MIPS .pdata c03fe450..c03fe49b. Semantic name remains unreviewed. */

undefined4 FUN_c03fe450(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 3) {
    (**(code **)**(undefined4 **)(param_1 + -0x10))(*(undefined4 **)(param_1 + -0x10),3);
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* c03fe49c FUN_c03fe49c */

/* Boundary evidence: original MIPS .pdata c03fe49c..c03fe4c7. Semantic name remains unreviewed. */

void FUN_c03fe49c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -0x10) + 8))();
  return;
}



/* c03fe4c8 FUN_c03fe4c8 */

/* Boundary evidence: original MIPS .pdata c03fe4c8..c03fe533. Semantic name remains unreviewed. */

void FUN_c03fe4c8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03f2850;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c03f2844;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x8c;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  param_1[0x22] = 0xcdcdcdcd;
  return;
}



/* c03fe534 FUN_c03fe534 */

/* Boundary evidence: original MIPS .pdata c03fe534..c03fe57f. Semantic name remains unreviewed. */

void FUN_c03fe534(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_2)(param_2,param_1);
  if (-1 < iVar1) {
    *(undefined4 **)(param_1 + 0x2c) = param_2;
  }
  return;
}



/* c03fe580 FUN_c03fe580 */

/* Boundary evidence: original MIPS .pdata c03fe580..c03fe59b. Semantic name remains unreviewed. */

void FUN_c03fe580(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + -0x68));
  return;
}



/* c03fe59c FUN_c03fe59c */

/* Boundary evidence: original MIPS .pdata c03fe59c..c03fe633. Semantic name remains unreviewed. */

undefined4 FUN_c03fe59c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar1 = *(int *)(param_1 + 0x70);
    piVar2 = *(int **)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 1;
    *(undefined4 *)(param_1 + 0x70) = 0;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
      if (iVar1 != 0) {
        iVar1 = iVar1 - *(int *)(param_1 + 0x74);
      }
      (**(code **)(**(int **)(param_1 + 0x2c) + 0x24))
                (*(int **)(param_1 + 0x2c),iVar1 + *piVar2,piVar2[1] - iVar1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return 0;
}



/* c03fe634 FUN_c03fe634 */

/* Boundary evidence: original MIPS .pdata c03fe634..c03fe6c7. Semantic name remains unreviewed. */

undefined4 FUN_c03fe634(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (*(int *)(param_1 + 0x24) != 0) {
      (**(code **)(**(int **)(param_1 + 0x2c) + 0x28))();
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      (**(code **)(**(int **)(param_1 + 0x2c) + 8))(*(int **)(param_1 + 0x2c),0,param_1 + 0x70);
    }
    *(undefined4 *)(param_1 + 0x1c) = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return 0;
}



/* c03fe6c8 FUN_c03fe6c8 */

/* Boundary evidence: original MIPS .pdata c03fe6c8..c03fe797. Semantic name remains unreviewed. */

undefined4 FUN_c03fe6c8(int param_1,uint param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_2 == 0x10000) {
    uVar4 = *(uint *)(param_1 + 0x34);
  }
  else {
    if ((param_2 < 0x10) || (0x10000000 < param_2)) {
      return 0xb;
    }
    lVar1 = (ulonglong)*(uint *)(param_1 + 0x34) * (ulonglong)param_2;
    uVar4 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  }
  iVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))(*(int **)(param_1 + 0x2c),uVar4);
  if (iVar2 < 0) {
    uVar3 = FUN_c03fe2fc(iVar2);
  }
  else {
    *(uint *)(param_1 + 0x48) = param_2;
    uVar3 = 0;
    *(uint *)(param_1 + 0x44) = uVar4;
  }
  return uVar3;
}



/* c03fe798 FUN_c03fe798 */

/* Boundary evidence: original MIPS .pdata c03fe798..c03fe81b. Semantic name remains unreviewed. */

void FUN_c03fe798(int param_1,uint param_2)

{
  int iVar1;
  
  *(uint *)(param_1 + 0x4c) = param_2;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x14))
                    (*(int **)(param_1 + 0x2c),(int)(((param_2 & 0xffff) - 0xffff) * 10000) / 0xffff
                     ,(int)(((param_2 >> 0x10) - 0xffff) * 10000) / 0xffff);
  FUN_c03fe2fc(iVar1);
  return;
}



/* c03fe81c FUN_c03fe81c */

/* Boundary evidence: original MIPS .pdata c03fe81c..c03fe993. Semantic name remains unreviewed. */

undefined4 FUN_c03fe81c(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar3;
  uint local_20;
  undefined1 auStack_1c [4];
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 0x24) == 0) {
    local_20 = *(uint *)(param_1 + 0x6c);
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 8))
                      (*(int **)(param_1 + 0x2c),&local_20,auStack_1c);
    if (iVar1 < 0) {
      LeaveCriticalSection(lpCriticalSection);
      uVar2 = FUN_c03fe2fc(iVar1);
      return uVar2;
    }
  }
  iVar1 = *param_2;
  if (iVar1 == 1) {
    if (*(int *)(param_1 + 0x44) == 0) {
LAB_c03fe96c:
      LeaveCriticalSection(lpCriticalSection);
      return 8;
    }
    uVar3 = (uint)*(ushort *)(param_1 + 0x3c) * *(int *)(param_1 + 0x44);
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    param_2[1] = (local_20 * 1000) / uVar3;
  }
  else {
    if (iVar1 == 2) {
      uVar3 = local_20 / *(ushort *)(param_1 + 0x3c);
      if (*(ushort *)(param_1 + 0x3c) == 0) {
        trap(0x1c00);
      }
    }
    else {
      uVar3 = local_20;
      if (iVar1 != 4) goto LAB_c03fe96c;
    }
    param_2[1] = uVar3;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* c03fe994 FUN_c03fe994 */

/* Boundary evidence: original MIPS .pdata c03fe994..c03fea2f. Semantic name remains unreviewed. */

undefined4 FUN_c03fe994(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x58);
    if (iVar1 == 0) goto LAB_c03fea10;
    do {
      if (*(int *)(iVar1 + 0x1c) != 0) break;
      iVar1 = *(int *)(iVar1 + 0x18);
    } while (iVar1 != 0);
  }
  else {
    *(undefined4 *)(param_1 + 100) = 0;
  }
  for (; (iVar1 != 0 && (*(int *)(iVar1 + 0x1c) != 0)); iVar1 = *(int *)(iVar1 + 0x18)) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
LAB_c03fea10:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return 0;
}



/* c03fea30 FUN_c03fea30 */

/* Boundary evidence: original MIPS .pdata c03fea30..c03feb07. Semantic name remains unreviewed. */

void FUN_c03fea30(int param_1)

{
  int iVar1;
  int iVar2;
  
  while ((iVar1 = *(int *)(param_1 + 0x50), iVar1 != 0 &&
         (((*(uint *)(iVar1 + 0x10) & 1) != 0 || (*(uint *)(iVar1 + 4) <= *(uint *)(iVar1 + 8))))))
  {
    iVar2 = *(int *)(iVar1 + 0x18);
    *(int *)(param_1 + 0x50) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xffffffef | 1;
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) - *(int *)(iVar1 + 8);
    (**(code **)(param_1 + 0x7c))
              (*(undefined4 *)(param_1 + 0x80),0x3bd,*(undefined4 *)(param_1 + 0x84),iVar1,0);
  }
  return;
}



/* c03feb08 FUN_c03feb08 */

/* Boundary evidence: original MIPS .pdata c03feb08..c03feb13. Semantic name remains unreviewed. */

undefined4 FUN_c03feb08(void)

{
  return 1;
}



/* c03feb14 FUN_c03feb14 */

/* Boundary evidence: original MIPS .pdata c03feb14..c03fec7b. Semantic name remains unreviewed. */

void FUN_c03feb14(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  iVar2 = *(int *)(param_1 + 0x58);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x1c) == 0) {
LAB_c03febd0:
      *(int *)(param_1 + 0x74) = *(int *)(iVar2 + 4) + *(int *)(param_1 + 0x74);
      iVar1 = *(int *)(iVar2 + 0x18);
    }
    else {
      if (((*(uint *)(iVar2 + 0x10) & 4) != 0) && (*(int *)(param_1 + 100) == 0)) {
        *(int *)(param_1 + 100) = iVar2;
        *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(iVar2 + 0x14);
        *(uint *)(param_1 + 0x60) = (uint)(*(int *)(iVar2 + 0x14) != -1);
      }
      if ((*(uint *)(iVar2 + 0x10) & 8) == 0) goto LAB_c03febd0;
      iVar1 = *(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x60);
      *(int *)(param_1 + 0x5c) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 100) = 0;
        goto LAB_c03febd0;
      }
      iVar1 = *(int *)(param_1 + 100);
      *(int *)(param_1 + 0x74) = *(int *)(iVar2 + 4) + *(int *)(param_1 + 0x74);
    }
    *(int *)(param_1 + 0x58) = iVar1;
    while ((iVar1 != 0 && (*(int *)(*(int *)(param_1 + 0x58) + 4) == 0))) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x18);
      *(int *)(param_1 + 0x58) = iVar1;
    }
    if (*(undefined4 **)(param_1 + 0x58) != (undefined4 *)0x0) {
      *param_2 = **(undefined4 **)(param_1 + 0x58);
      *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x58) + 4);
      goto LAB_c03fec58;
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  *param_2 = 0;
  *param_3 = 0;
LAB_c03fec58:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return;
}



/* c03fec7c FUN_c03fec7c */

/* Boundary evidence: original MIPS .pdata c03fec7c..c03fee33. Semantic name remains unreviewed. */

undefined4 FUN_c03fec7c(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if (*(int *)(param_1 + 0x50) != 0) {
    if (((*(int *)(param_1 + 0x20) == 0) && (*(uint *)(param_1 + 0x70) != 0)) &&
       (*(uint *)(param_1 + 0x70) <= param_2)) {
      *(undefined4 *)(param_1 + 0x20) = 1;
      (**(code **)(**(int **)(param_1 + 0x2c) + 0x1c))();
    }
    iVar2 = *(int *)(param_1 + 0x6c);
    *(uint *)(param_1 + 0x6c) = param_2;
    uVar4 = param_2 - iVar2;
    iVar2 = *(int *)(param_1 + 0x50);
    for (; (iVar2 != 0 && (uVar4 != 0)); uVar4 = uVar4 - uVar1) {
      uVar5 = *(uint *)(iVar2 + 4);
      uVar1 = (~(*(ushort *)(param_1 + 0x3c) - 1) & uVar5) - *(int *)(iVar2 + 8);
      if (uVar4 < uVar1) {
        *(uint *)(iVar2 + 8) = *(int *)(iVar2 + 8) + uVar4;
        uVar1 = uVar4;
        iVar3 = iVar2;
      }
      else {
        iVar3 = *(int *)(iVar2 + 0x1c);
        if (iVar3 == 0) {
          *(uint *)(iVar2 + 8) = uVar5;
          *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | 1;
        }
        else {
          if (*(int *)(iVar3 + 0x14) == 1) {
            *(uint *)(iVar2 + 8) = uVar5;
            *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | 1;
          }
          else {
            *(undefined4 *)(iVar2 + 8) = 0;
          }
          if ((*(uint *)(iVar2 + 0x10) & 8) != 0) {
            if (*(int *)(iVar3 + 0x14) != -1) {
              *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + -1;
            }
            if (*(int *)(iVar3 + 0x14) != 0) goto LAB_c03fedd8;
          }
        }
        iVar3 = *(int *)(iVar2 + 0x18);
      }
LAB_c03fedd8:
      iVar2 = iVar3;
    }
    FUN_c03fea30(param_1);
    if (*(int *)(param_1 + 0x50) == 0) {
      (**(code **)(**(int **)(param_1 + 0x2c) + 0x1c))();
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return 0;
}



/* c03fef1c FUN_c03fef1c */

/* Boundary evidence: original MIPS .pdata c03fef1c..c03ff03b. Semantic name remains unreviewed. */

int * FUN_c03fef1c(int *param_1,int param_2,int param_3)

{
  if (param_3 != 0) {
    *param_1 = (int)&DAT_c03f286c;
    param_1[8] = (int)&DAT_c03f2858;
    param_1[6] = (int)&DAT_c03f2864;
    param_1[5] = (int)&PTR_LAB_c03f2094;
    *(undefined ***)((int)(param_1 + 5) + *(int *)(param_1[6] + 4) + 4) = &PTR_LAB_c03f2088;
    FUN_c03f464c(param_1 + 7,0);
  }
  *(undefined ***)(*(int *)(*param_1 + 4) + (int)param_1) = &PTR_LAB_c03f2824;
  *(undefined ***)(*(int *)(*param_1 + 8) + (int)param_1) = &PTR_LAB_c03f2814;
  *(undefined ***)(*(int *)(*param_1 + 0xc) + (int)param_1) = &PTR_FUN_c03f2810;
  *(int *)((int)param_1 + *(int *)(*param_1 + 4) + -4) = *(int *)(*param_1 + 4) + -0xc;
  *(int *)((int)param_1 + *(int *)(*param_1 + 8) + -4) = *(int *)(*param_1 + 8) + -0x14;
  param_1[1] = param_2;
  (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + param_2 + 4) + 4))();
  return param_1;
}



/* c03ff03c FUN_c03ff03c */

/* Boundary evidence: original MIPS .pdata c03ff03c..c03ff187. Semantic name remains unreviewed. */

undefined4 *
FUN_c03ff03c(undefined4 *param_1,void *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  if (param_6 != 0) {
    param_1[1] = &DAT_c03f287c;
  }
  *param_1 = &PTR_LAB_c03f283c;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c03f2830;
  *param_1 = &PTR_FUN_c03f2850;
  *(undefined ***)((int)param_1 + *(int *)(param_1[1] + 4) + 4) = &PTR_LAB_c03f2844;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x8c;
  memcpy(param_1 + 0xc,param_2,0x12);
  param_1[0x1f] = param_3;
  param_1[0x20] = param_4;
  param_1[0x21] = param_5;
  param_1[0x22] = param_1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  param_1[10] = 1;
  param_1[9] = 0;
  param_1[7] = 0;
  param_1[8] = 1;
  param_1[0x16] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  param_1[0xb] = 0;
  param_1[0x11] = *(undefined4 *)((int)param_2 + 4);
  param_1[0x12] = 0x10000;
  param_1[0x13] = 0xffffffff;
  param_1[0x1e] = 0;
  param_1[0x1d] = 0;
  return param_1;
}



/* c03ff188 FUN_c03ff188 */

/* Boundary evidence: original MIPS .pdata c03ff188..c03ff1e3. Semantic name remains unreviewed. */

LONG FUN_c03ff188(int param_1)

{
  LONG LVar1;
  undefined4 *puVar2;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + -0x68));
  if ((LVar1 == 0) && (puVar2 = (undefined4 *)(param_1 + -0x90), puVar2 != (undefined4 *)0x0)) {
    FUN_c03fe4c8(puVar2);
    operator_delete(puVar2);
  }
  return LVar1;
}



/* c03ff1e4 FUN_c03ff1e4 */

/* Boundary evidence: original MIPS .pdata c03ff1e4..c03ff387. Semantic name remains unreviewed. */

undefined4 FUN_c03ff1e4(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);
  EnterCriticalSection(lpCriticalSection);
  uVar1 = *(uint *)(param_2 + 0x10);
  if ((uVar1 & 0x10) != 0) {
    LeaveCriticalSection(lpCriticalSection);
    return 0xb;
  }
  if (((*(int *)(param_2 + 4) == 0) && ((uVar1 & 4) != 0)) && ((uVar1 & 8) != 0)) {
    uVar3 = 0xb;
    goto LAB_c03ff364;
  }
  if ((uVar1 & 4) != 0) {
    if (*(int *)(param_1 + 0x68) != 0) {
      *(uint *)(*(int *)(param_1 + 0x54) + 0x10) = *(uint *)(*(int *)(param_1 + 0x54) + 0x10) | 8;
    }
    *(int *)(param_1 + 0x68) = param_2;
  }
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x68);
  if ((*(uint *)(param_2 + 0x10) & 8) != 0) {
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    *(int *)(param_1 + 0x50) = param_2;
    *(int *)(param_1 + 0x54) = param_2;
LAB_c03ff2c8:
    *(int *)(param_1 + 0x58) = param_2;
  }
  else {
    *(int *)(*(int *)(param_1 + 0x54) + 0x18) = param_2;
    *(int *)(param_1 + 0x54) = param_2;
    if (*(int *)(param_1 + 0x58) == 0) goto LAB_c03ff2c8;
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) & 0xfffffffe | 0x10;
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + *(int *)(param_2 + 4);
  if ((*(int *)(param_1 + 0x1c) == 0) && (*(int *)(param_1 + 0x24) == 0)) {
    puVar2 = *(undefined4 **)(param_1 + 0x58);
    if (puVar2[1] == 0) {
      puVar2[4] = puVar2[4] | 1;
      *(undefined4 *)(param_1 + 0x58) = 0;
      FUN_c03fea30(param_1);
    }
    else {
      *(undefined4 *)(param_1 + 0x24) = 1;
      (**(code **)(**(int **)(param_1 + 0x2c) + 0x24))(*(int **)(param_1 + 0x2c),*puVar2,puVar2[1]);
    }
  }
  uVar3 = 0;
LAB_c03ff364:
  LeaveCriticalSection(lpCriticalSection);
  return uVar3;
}



/* c03ff388 FUN_c03ff388 */

/* Boundary evidence: original MIPS .pdata c03ff388..c03ff44f. Semantic name remains unreviewed. */

undefined4 FUN_c03ff388(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x1c))();
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x20))();
  for (iVar1 = *(int *)(param_1 + 0x50); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  FUN_c03fea30(param_1);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return 0;
}



/* c03ff468 FUN_c03ff468 */

/* Boundary evidence: original MIPS .pdata c03ff468..c03ff6ff. Semantic name remains unreviewed. */

undefined4 FUN_c03ff468(int *param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *local_28;
  undefined4 *local_24;
  
  puVar5 = (undefined4 *)*param_1;
  iVar1 = (**(code **)*puVar5)(puVar5,1,&local_28);
  if (-1 < iVar1) {
    if ((param_4 & 1) == 0) {
      iVar1 = (**(code **)(*local_28 + 4))(local_28,param_3[1],&local_24);
      (**(code **)(*(int *)((int)local_28 + *(int *)(local_28[1] + 4) + 4) + 8))();
      if (-1 < iVar1) {
        puVar3 = operator_new(0x94);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = FUN_c03ff03c(puVar3,(void *)param_3[1],param_3[2],*param_3,param_3[3],1);
        }
        if (puVar3 != (undefined4 *)0x0) {
          iVar1 = FUN_c03fe534((int)puVar3,local_24);
          if (iVar1 < 0) {
            (**(code **)(*(int *)((int)local_24 + *(int *)(local_24[1] + 4) + 4) + 8))();
            (**(code **)(*(int *)((int)puVar3 + *(int *)(puVar3[1] + 4) + 4) + 8))();
            goto LAB_c03ff4c8;
          }
          piVar4 = operator_new(0x28);
          if (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = FUN_c03fef1c(piVar4,(int)puVar5,1);
          }
          if ((piVar4 != (int *)0x0) && (iVar1 = *(int *)(*piVar4 + 8) + (int)piVar4, iVar1 != 0)) {
            *param_2 = puVar3;
            *param_1 = iVar1;
            (**(code **)(*(int *)((int)puVar5 + *(int *)(puVar5[1] + 4) + 4) + 8))();
            return 0;
          }
        }
        (**(code **)(*(int *)((int)local_24 + *(int *)(local_24[1] + 4) + 4) + 8))();
        return 7;
      }
    }
    else {
      iVar1 = (**(code **)*local_28)(local_28,param_3[1]);
      (**(code **)(*(int *)((int)local_28 + *(int *)(local_28[1] + 4) + 4) + 8))();
    }
  }
LAB_c03ff4c8:
  uVar2 = FUN_c03fe2fc(iVar1);
  return uVar2;
}



/* c03ff700 FUN_c03ff700 */

/* Boundary evidence: original MIPS .pdata c03ff700..c03ff75f. Semantic name remains unreviewed. */

undefined4 * FUN_c03ff700(undefined4 *param_1,uint param_2)

{
  FUN_c03fe3a8((int)param_1);
  FUN_c03f4708(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1 + -7);
  }
  return param_1 + -7;
}



/* c03ff760 FUN_c03ff760 */

/* Boundary evidence: original MIPS .pdata c03ff760..c03ff8d3. Semantic name remains unreviewed. */

undefined4 FUN_c03ff760(int param_1,undefined4 param_2,int param_3,int *param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  switch(param_2) {
  case 4:
    uVar1 = (**(code **)(**(int **)(param_1 + -0x10) + 4))
                      (*(int **)(param_1 + -0x10),4,0,param_4,param_5);
    break;
  default:
    uVar1 = 8;
    break;
  case 6:
    if (*(int *)(param_3 + 0x24) != 0) {
      return 0x21;
    }
    (**(code **)(**(int **)(param_3 + 0x2c) + 4))();
    goto LAB_c03ff820;
  case 9:
    uVar1 = FUN_c03ff1e4(param_3,(int)param_4);
    break;
  case 10:
    uVar1 = FUN_c03fe634(param_3);
    break;
  case 0xb:
    uVar1 = FUN_c03fe59c(param_3);
    break;
  case 0xc:
    uVar1 = FUN_c03ff388(param_3);
    break;
  case 0xd:
    uVar1 = FUN_c03fe81c(param_3,param_4);
    break;
  case 0x10:
    iVar2 = *(int *)(param_3 + 0x4c);
    goto LAB_c03ff81c;
  case 0x11:
    uVar1 = FUN_c03fe798(param_3,(uint)param_4);
    break;
  case 0x12:
    iVar2 = *(int *)(param_3 + 0x48);
LAB_c03ff81c:
    *param_4 = iVar2;
LAB_c03ff820:
    uVar1 = 0;
    break;
  case 0x13:
    uVar1 = FUN_c03fe6c8(param_3,(uint)param_4);
    break;
  case 0x14:
    uVar1 = FUN_c03fe994(param_3);
  }
  return uVar1;
}



/* c03ffd4c FUN_c03ffd4c */

undefined4 FUN_c03ffd4c(void)

{
  return 1;
}



/* c03ffd54 FUN_c03ffd54 */

/* Boundary evidence: original MIPS .pdata c03ffd54..c03ffe8f. Semantic name remains unreviewed. */

int FUN_c03ffd54(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c04013f4 != (code *)0x0) {
      iVar2 = (*DAT_c04013f4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c03ffe04;
    FUN_c04004d8();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c03f31dc(param_1,param_2);
  }
LAB_c03ffe04:
  if (((param_2 == 0) && (FUN_c0400460(), iVar1 != 0)) && (DAT_c04013f4 != (code *)0x0)) {
    iVar1 = (*DAT_c04013f4)(param_1,0,param_3);
  }
  return iVar1;
}



/* c03ffe90 FUN_c03ffe90 */

/* Boundary evidence: original MIPS .pdata c03ffe90..c03ffebb. Semantic name remains unreviewed. */

void FUN_c03ffe90(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c03ffebc entry */

/* Boundary evidence: original MIPS .pdata c03ffebc..c03fff13. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c03fff14();
  }
  FUN_c03ffd54(param_1,param_2,param_3);
  return;
}



/* c03fff14 FUN_c03fff14 */

/* Boundary evidence: original MIPS .pdata c03fff14..c03fff87. Semantic name remains unreviewed. */

void FUN_c03fff14(void)

{
  uint uVar1;
  
  if ((DAT_c04011e8 == 0) || (DAT_c04011e8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c04011e8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c04011e8 == 0) {
      DAT_c04011e8 = 0xb064;
    }
  }
  DAT_c04011ec = ~DAT_c04011e8;
  return;
}



/* c03fff88 FUN_c03fff88 */

/* Boundary evidence: original MIPS .pdata c03fff88..c03fffdb. Semantic name remains unreviewed. */

void FUN_c03fff88(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0400008(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c03fffdc FUN_c03fffdc */

/* Boundary evidence: original MIPS .pdata c03fffdc..c0400007. Semantic name remains unreviewed. */

undefined4 FUN_c03fffdc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c03fff88(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0400008 FUN_c0400008 */

/* Boundary evidence: original MIPS .pdata c0400008..c040004f. Semantic name remains unreviewed. */

void FUN_c0400008(uint param_1)

{
  if ((param_1 == DAT_c04011e8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0400050 FUN_c0400050 */

/* Boundary evidence: original MIPS .pdata c0400050..c04000cb. Semantic name remains unreviewed. */

void FUN_c0400050(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c03fff88(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c04000cc FUN_c04000cc */

/* Boundary evidence: original MIPS .pdata c04000cc..c04001d7. Semantic name remains unreviewed. */

undefined4 FUN_c04000cc(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c04013ec;
  puVar3 = DAT_c04013e8;
  iVar4 = (int)DAT_c04013e8 - (int)DAT_c04013ec;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c0400110:
    param_1 = 0;
  }
  else {
    if (DAT_c04013ec != (void *)0x0) {
      uVar1 = _msize(DAT_c04013ec);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c0400184:
        if (pvVar2 == (void *)0x0) goto LAB_c0400110;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c0400184;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c04013e8 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c04013ec = pvVar2;
  }
  return param_1;
}



/* c04001d8 FUN_c04001d8 */

/* Boundary evidence: original MIPS .pdata c04001d8..c04002c3. Semantic name remains unreviewed. */

undefined4 FUN_c04001d8(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c04013f0 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c04013f0,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c04013f0 == (LPCRITICAL_SECTION)0x0) goto LAB_c040027c;
  }
  EnterCriticalSection(DAT_c04013f0);
LAB_c040027c:
  uVar2 = FUN_c04000cc(param_1);
  FUN_c04002c4();
  return uVar2;
}



/* c04002c4 FUN_c04002c4 */

/* Boundary evidence: original MIPS .pdata c04002c4..c040030f. Semantic name remains unreviewed. */

void FUN_c04002c4(void)

{
  if (DAT_c04013f0 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c04013f0);
  }
  return;
}



/* c0400310 FUN_c0400310 */

/* Boundary evidence: original MIPS .pdata c0400310..c040033f. Semantic name remains unreviewed. */

undefined4 FUN_c0400310(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04001d8(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0400340 FUN_c0400340 */

/* Boundary evidence: original MIPS .pdata c0400340..c040045f. Semantic name remains unreviewed. */

void FUN_c0400340(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c04013e4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c04013ec;
    if (DAT_c04013ec != (undefined4 *)0x0) {
      while (DAT_c04013e8 = DAT_c04013e8 + -1, _Memory <= DAT_c04013e8) {
        if ((code *)*DAT_c04013e8 != (code *)0x0) {
          (*(code *)*DAT_c04013e8)();
          _Memory = DAT_c04013ec;
        }
      }
      free(_Memory);
      DAT_c04013e8 = (undefined4 *)0x0;
      DAT_c04013ec = (undefined4 *)0x0;
    }
    FUN_c0400484((undefined4 *)&DAT_c03f2018,(undefined4 *)&DAT_c03f201c);
  }
  FUN_c0400484((undefined4 *)&DAT_c03f2020,(undefined4 *)&DAT_c03f2024);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c04013f0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0400460 FUN_c0400460 */

/* Boundary evidence: original MIPS .pdata c0400460..c0400483. Semantic name remains unreviewed. */

void FUN_c0400460(void)

{
  FUN_c0400340(0,0,1);
  return;
}



/* c0400484 FUN_c0400484 */

/* Boundary evidence: original MIPS .pdata c0400484..c04004d7. Semantic name remains unreviewed. */

void FUN_c0400484(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c04004d8 FUN_c04004d8 */

/* Boundary evidence: original MIPS .pdata c04004d8..c0400513. Semantic name remains unreviewed. */

void FUN_c04004d8(void)

{
  FUN_c0400484((undefined4 *)&DAT_c03f2010,(undefined4 *)&DAT_c03f2014);
  FUN_c0400484((undefined4 *)&DAT_c03f2000,(undefined4 *)&DAT_c03f200c);
  return;
}



/* c0400654 FUN_c0400654 */

/* Boundary evidence: original MIPS .pdata c0400654..c0400687. Semantic name remains unreviewed. */

void FUN_c0400654(void)

{
  FUN_c03f7bf0((undefined4 *)&DAT_c040136c,0x10,0x400);
  FUN_c0400310(FUN_c04006bc);
  return;
}



/* c0400688 FUN_c0400688 */

/* Boundary evidence: original MIPS .pdata c0400688..c04006bb. Semantic name remains unreviewed. */

void FUN_c0400688(void)

{
  FUN_c03f7bf0((undefined4 *)&DAT_c040139c,0x10,0x100);
  FUN_c0400310(FUN_c04006dc);
  return;
}



/* c04006bc FUN_c04006bc */

/* Boundary evidence: original MIPS .pdata c04006bc..c04006db. Semantic name remains unreviewed. */

void FUN_c04006bc(void)

{
  FUN_c03f7c60((undefined4 *)&DAT_c040136c);
  return;
}



/* c04006dc FUN_c04006dc */

/* Boundary evidence: original MIPS .pdata c04006dc..c04006fb. Semantic name remains unreviewed. */

void FUN_c04006dc(void)

{
  FUN_c03f7c60((undefined4 *)&DAT_c040139c);
  return;
}


