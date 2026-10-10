/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0571070 DriverEntry */

/* Boundary evidence: original MIPS .pdata c0571070..c057120b. Semantic name remains unreviewed. */

undefined4 DriverEntry(void)

{
  undefined4 uVar1;
  int local_90 [2];
  undefined4 local_88;
  undefined1 local_80;
  undefined1 local_7f;
  code *local_78;
  code *local_74;
  code *local_70;
  code *local_6c;
  undefined1 *local_68;
  code *local_64;
  code *local_60;
  undefined1 *local_5c;
  code *local_58;
  undefined1 *local_54;
  undefined4 local_50;
  wchar_t *local_4c;
  code *local_48;
  code *local_44;
  code *local_40;
  code *local_3c;
  undefined4 local_38;
  
                    /* 0x1070  1  DriverEntry */
  local_90[0] = 0;
  local_88 = 0x10000e;
  NdisInitializeEvent(&DAT_c0577150);
  DAT_c0577138 = &DAT_c0577134;
  DAT_c0577134 = &DAT_c0577134;
  NdisAllocateSpinLock(&DAT_c057713c);
  memset(&local_80,0,0x6c);
  local_50 = local_88;
  local_78 = FUN_c05740fc;
  local_74 = FUN_c0574124;
  local_70 = FUN_c0576164;
  local_6c = FUN_c0575c34;
  local_68 = &LAB_c0574740;
  local_64 = FUN_c0574748;
  local_60 = FUN_c0575ec0;
  local_5c = &LAB_c0574740;
  local_58 = FUN_c0574770;
  local_54 = &LAB_c0574740;
  local_44 = FUN_c05755f4;
  local_40 = FUN_c0575070;
  local_80 = 5;
  local_7f = 0;
  local_4c = L"NDISUIO";
  local_38 = 0;
  local_48 = FUN_c0575d08;
  local_3c = FUN_c0574dec;
  NdisRegisterProtocol(local_90,&DAT_c0577128,&local_80,0x6c);
  if (local_90[0] == 0) {
    NdisGeneratePartialCancelId();
    DAT_c057712c = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



/* c057120c FUN_c057120c */

/* Boundary evidence: original MIPS .pdata c057120c..c0571307. Semantic name remains unreviewed. */

undefined4 FUN_c057120c(int param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0x10;
    NdisAcquireSpinLock(iVar1);
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffff0f;
    NdisReleaseSpinLock(iVar1);
    if ((*(uint *)(param_1 + 8) & 0xf) == 4) {
      local_20 = 0;
      FUN_c057463c(param_1,1,0x1010e,&local_20,4,&uStack_1c);
    }
    NdisAcquireSpinLock(iVar1);
    *(undefined4 *)(param_1 + 0x88) = 1;
    *(undefined2 *)(param_1 + 0x80) = 0x8001;
    if (*(int *)(param_1 + 0x50) != 0) {
      NdisSetEvent(param_1 + 0x4c);
    }
    NdisReleaseSpinLock(iVar1);
  }
  return 0;
}



/* c0571308 FUN_c0571308 */

/* Boundary evidence: original MIPS .pdata c0571308..c057132b. Semantic name remains unreviewed. */

void FUN_c0571308(int param_1)

{
  NdisInterlockedIncrement(param_1 + 0xc);
  return;
}



/* c057132c FUN_c057132c */

/* Boundary evidence: original MIPS .pdata c057132c..c0571417. Semantic name remains unreviewed. */

void FUN_c057132c(int *param_1)

{
  int iVar1;
  
  iVar1 = NdisInterlockedDecrement(param_1 + 3);
  if (iVar1 == 0) {
    param_1[0x23] = param_1[0x23] + 1;
    NdisAcquireSpinLock(&DAT_c057713c);
    *(int *)param_1[1] = *param_1;
    *(int *)(*param_1 + 4) = param_1[1];
    NdisReleaseSpinLock(&DAT_c057713c);
    NdisFreeSpinLock(param_1 + 4);
    if (param_1[0x1f] != 0) {
      NdisFreeEvent();
    }
    if (param_1[0x13] != 0) {
      NdisFreeEvent();
    }
    NdisFreeMemory(param_1,0,0);
  }
  return;
}



/* c0571418 FUN_c0571418 */

/* Boundary evidence: original MIPS .pdata c0571418..c05714d7. Semantic name remains unreviewed. */

undefined4 FUN_c0571418(int param_1,undefined2 *param_2,uint param_3)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  
  NdisAcquireSpinLock(param_1 + 0x10);
  if (param_3 < 5) {
    *(uint *)(param_1 + 0x88) = param_3;
    if (param_3 != 0) {
      puVar2 = (undefined2 *)(param_1 + 0x80);
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 - 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
      } while (param_3 != 0);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc0010015;
  }
  NdisReleaseSpinLock(param_1 + 0x10);
  return uVar3;
}



/* c05714d8 FUN_c05714d8 */

/* Boundary evidence: original MIPS .pdata c05714d8..c05717ff. Semantic name remains unreviewed. */

size_t FUN_c05714d8(int *param_1,int *param_2,int param_3,void *param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  size_t _Size;
  int *piVar4;
  int *piVar5;
  int *local_30;
  int local_2c;
  
  piVar5 = param_1 + 4;
  *param_2 = 0;
  _Size = 0;
  NdisAcquireSpinLock(piVar5);
  uVar2 = param_1[2];
  if ((uVar2 & 0xf) == 4) {
    if (((uVar2 & 0x200000) == 0) && ((uVar2 & 0x200) == 0x200)) {
      NdisReleaseSpinLock(piVar5);
    }
    else {
      piVar4 = param_1 + 0x16;
      piVar3 = (int *)*piVar4;
      if (piVar3 != piVar4) {
LAB_c057167c:
        *(int *)piVar3[1] = *piVar3;
        *(int *)(*piVar3 + 4) = piVar3[1];
        param_1[0x18] = param_1[0x18] + -1;
        FUN_c057132c(param_1);
        NdisReleaseSpinLock(piVar5);
        local_30 = piVar3 + -0xe;
        piVar5 = (int *)piVar3[-0xc];
        piVar3 = local_30;
        if (param_3 != 0) {
          _Size = param_5;
          if (4 < param_5) {
            _Size = 4;
          }
          iVar1 = NdisGetPoolFromPacket(local_30);
          piVar3 = local_30;
          if (iVar1 == param_1[0xc]) {
            local_2c = local_30[0x10];
          }
          else {
            local_2c = 0;
          }
          memcpy(param_4,&local_2c,_Size);
          param_5 = param_5 - _Size;
          param_4 = (void *)(_Size + (int)param_4);
        }
        for (; (param_5 != 0 && (piVar3 = local_30, piVar5 != (int *)0x0)); piVar5 = (int *)*piVar5)
        {
          uVar2 = piVar5[2];
          if (uVar2 != 0) {
            if (param_5 <= uVar2) {
              uVar2 = param_5;
            }
            memcpy(param_4,(void *)piVar5[1],uVar2);
            param_5 = param_5 - uVar2;
            param_4 = (void *)(uVar2 + (int)param_4);
            _Size = uVar2 + _Size;
          }
          piVar3 = local_30;
        }
        iVar1 = NdisGetPoolFromPacket(piVar3);
        if (iVar1 == param_1[0xc]) {
          FUN_c0575954((int)param_1,(int)local_30);
        }
        else {
          NdisReturnPackets(&local_30,1);
        }
        if (*param_2 != 0) {
          return 0xffffffff;
        }
        return _Size;
      }
      param_1[0x14] = 1;
      NdisReleaseSpinLock(piVar5);
      NdisWaitEvent(param_1 + 0x13,param_1[0x15]);
      NdisAcquireSpinLock(piVar5);
      param_1[0x14] = 0;
      NdisResetEvent(param_1 + 0x13);
      uVar2 = param_1[2];
      if ((uVar2 & 0xf) != 4) {
        NdisReleaseSpinLock(piVar5);
        goto LAB_c0571554;
      }
      if (((uVar2 & 0x200000) != 0) || ((uVar2 & 0x200) != 0x200)) {
        piVar3 = (int *)*piVar4;
        if (piVar3 == piVar4) {
          NdisReleaseSpinLock(piVar5);
          *param_2 = 0;
          return 0;
        }
        goto LAB_c057167c;
      }
      NdisReleaseSpinLock(piVar5);
    }
    iVar1 = -0x3fffff63;
  }
  else {
    NdisReleaseSpinLock(piVar5);
LAB_c0571554:
    iVar1 = -0x3ffffff8;
  }
  *param_2 = iVar1;
  return 0xffffffff;
}



/* c0571800 FUN_c0571800 */

/* Boundary evidence: original MIPS .pdata c0571800..c057185b. Semantic name remains unreviewed. */

void FUN_c0571800(int param_1)

{
  NdisAcquireSpinLock(param_1 + 0x10);
  NdisSetEvent(param_1 + 0x4c);
  NdisReleaseSpinLock(param_1 + 0x10);
  return;
}



/* c057185c FUN_c057185c */

/* Boundary evidence: original MIPS .pdata c057185c..c0571c0b. Semantic name remains unreviewed. */

uint FUN_c057185c(int param_1,int *param_2,undefined4 param_3,uint param_4)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_28;
  int *local_24;
  int local_20 [2];
  
  local_28 = 0;
  if (param_4 < 0xe) {
    *param_2 = -0x3fffffdd;
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x3c) + 0xeU < param_4) {
    *param_2 = -0x3ffffdfa;
    return 0xffffffff;
  }
  iVar4 = param_1 + 0x10;
  NdisAcquireSpinLock(iVar4);
  if ((*(uint *)(param_1 + 8) & 0xf) != 4) {
    NdisReleaseSpinLock(iVar4);
    iVar4 = -0x3ffffff8;
    goto LAB_c0571908;
  }
  NdisAllocatePacket(local_20,&local_28,*(undefined4 *)(param_1 + 0x28));
  pcVar1 = NdisReleaseSpinLock_exref;
  if (local_20[0] == 0) {
    NdisAllocateBuffer(local_20,&local_24,*(undefined4 *)(param_1 + 0x2c),param_3,param_4);
    if (local_20[0] == 0) {
      *(undefined4 *)(local_28 + 0x40) = 1;
      NdisInterlockedIncrement(param_1 + 0x48);
      NdisReleaseSpinLock(iVar4);
      NdisInitializeEvent(local_28 + 0x38);
      *param_2 = 0x103;
      *local_24 = 0;
      iVar4 = *local_24;
      piVar2 = local_24;
      while (iVar4 != 0) {
        piVar2 = (int *)*piVar2;
        iVar4 = *piVar2;
      }
      if (*(int *)(local_28 + 8) == 0) {
        *(int **)(local_28 + 0xc) = piVar2;
      }
      *piVar2 = *(int *)(local_28 + 8);
      *(int **)(local_28 + 8) = local_24;
      *(undefined1 *)(local_28 + 0x1c) = 0;
      (**(code **)(*(int *)(param_1 + 0x24) + 100))(*(int *)(param_1 + 0x24),&local_28,1);
      NdisWaitEvent(local_28 + 0x38,0);
      NdisFreeEvent(local_28 + 0x38);
      NdisInterlockedDecrement(param_1 + 0x48);
      iVar4 = *(int *)(local_28 + 0x3c);
      if (iVar4 == 0) {
        *param_2 = 0;
        goto LAB_c0571b9c;
      }
      if ((((iVar4 == 0x103) || (iVar4 == -0x7ffffffb)) ||
          (iVar3 = -0x3fffffff, iVar4 == -0x3fffffff)) ||
         ((iVar4 == -0x3fffff66 || (iVar4 == -0x3fffff45)))) {
        *param_2 = iVar4;
        goto LAB_c0571b9c;
      }
      if (iVar4 == -0x3ffeffea) {
        iVar3 = -0x3fffffdd;
LAB_c0571b0c:
        *param_2 = iVar3;
      }
      else {
        if (iVar4 == -0x3ffeffec) {
          iVar4 = -0x3ffffdfa;
        }
        else {
          if (iVar4 == -0x3ffeffeb) {
            *param_2 = -0x3ffffff3;
            goto LAB_c0571b9c;
          }
          if (iVar4 == -0x3ffefffa) {
            *param_2 = -0x7fffffe6;
            goto LAB_c0571b9c;
          }
          if (iVar4 != -0x3ffeffef) goto LAB_c0571b0c;
          iVar4 = -0x3fffff63;
        }
        *param_2 = iVar4;
      }
LAB_c0571b9c:
      NdisFreeBuffer(local_24);
      iVar4 = NdisInterlockedDecrement(local_28 + 0x40);
      if (iVar4 == 0) {
        NdisFreePacket(local_28);
      }
      if (*param_2 != 0) {
        return 0xffffffff;
      }
      return param_4;
    }
    NdisReleaseSpinLock(iVar4);
    iVar4 = local_28;
    pcVar1 = NdisFreePacket_exref;
  }
  (*pcVar1)(iVar4);
  iVar4 = -0x3fffff66;
LAB_c0571908:
  *param_2 = iVar4;
  return 0xffffffff;
}



/* c0571c0c FUN_c0571c0c */

/* Boundary evidence: original MIPS .pdata c0571c0c..c0571e2f. Semantic name remains unreviewed. */

int FUN_c0571c0c(void *param_1,size_t param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_28;
  undefined4 uStack_24;
  
  piVar2 = FUN_c0574aa4(param_1,param_2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x3fffffcc;
  }
  else {
    piVar4 = piVar2 + 4;
    NdisAcquireSpinLock(piVar4);
    if ((piVar2[2] & 0xf0U) == 0) {
      piVar2[2] = piVar2[2] & 0xffffff1fU | 0x10;
      NdisReleaseSpinLock(piVar4);
      local_28 = 0xb;
      iVar3 = FUN_c057463c((int)piVar2,1,0x1010e,&local_28,4,&uStack_24);
      if (iVar3 == 0) {
        *param_3 = piVar2;
        iVar3 = 0;
      }
      else {
        NdisAcquireSpinLock(piVar4);
        piVar2[2] = piVar2[2] & 0xffffff0f;
        NdisReleaseSpinLock(piVar4);
        FUN_c057132c(piVar2);
        if ((((iVar3 != 0x103) && (iVar3 != -0x7ffffffb)) && (iVar3 != -0x3fffffff)) &&
           ((iVar3 != -0x3fffff66 && (iVar3 != -0x3fffff45)))) {
          if (iVar3 == -0x3ffeffea) {
            iVar3 = -0x3fffffdd;
          }
          else if (iVar3 == -0x3ffeffec) {
            iVar3 = -0x3ffffdfa;
          }
          else if (iVar3 == -0x3ffeffeb) {
            iVar3 = -0x3ffffff3;
          }
          else if (iVar3 == -0x3ffefffa) {
            iVar3 = -0x7fffffe6;
          }
          else {
            bVar1 = iVar3 == -0x3ffeffef;
            iVar3 = -0x3fffffff;
            if (bVar1) {
              iVar3 = -0x3fffff63;
            }
          }
        }
      }
    }
    else {
      NdisReleaseSpinLock();
      FUN_c057132c(piVar2);
      iVar3 = -0x7fffffef;
    }
  }
  return iVar3;
}



/* c0571e30 FUN_c0571e30 */

/* Boundary evidence: original MIPS .pdata c0571e30..c0571e73. Semantic name remains unreviewed. */

undefined4 FUN_c0571e30(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    trap(0x400);
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0571e74 FUN_c0571e74 */

void FUN_c0571e74(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = &DAT_c0577180 + (param_1 & 7);
  puVar2 = (undefined4 *)(&DAT_c0577180)[param_1 & 7];
  while( true ) {
    if ((puVar2 == (undefined4 *)0x0) || (puVar2[7] == param_1)) goto LAB_c0571ec8;
    if ((uint)puVar2[7] < param_1) break;
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  puVar2 = (undefined4 *)0x0;
LAB_c0571ec8:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = puVar2;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = puVar1;
  }
  return;
}



/* c0571ee8 FUN_c0571ee8 */

/* Boundary evidence: original MIPS .pdata c0571ee8..c0571f4f. Semantic name remains unreviewed. */

bool FUN_c0571ee8(uint param_1,int *param_2)

{
  int local_18;
  int *local_14;
  
  FUN_c0571e74(param_1,&local_18,&local_14);
  if (local_18 == 0) {
    *param_2 = *local_14;
    *local_14 = (int)param_2;
    param_2[7] = param_1;
  }
  return local_18 == 0;
}



/* c0571f50 FUN_c0571f50 */

void FUN_c0571f50(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    *param_2 = 0;
    return;
  }
  if (param_1 == 0x103) {
    uVar1 = 0x3e5;
    goto LAB_c057204c;
  }
  if (param_1 == -0x7ffffffb) {
    uVar1 = 0xea;
    goto LAB_c0572058;
  }
  if (param_1 == -0x3fffffff) {
    uVar1 = 0x1f;
LAB_c0571fe8:
    *param_2 = uVar1;
    return;
  }
  if (param_1 == -0x3fffff66) {
    uVar1 = 0x5aa;
    goto LAB_c057204c;
  }
  if (param_1 == -0x3fffff45) {
    uVar1 = 0x32;
    goto LAB_c0572058;
  }
  if (param_1 == -0x3fffffdd) {
    uVar1 = 0x7a;
    goto LAB_c0571fe8;
  }
  if (param_1 == -0x3ffffdfa) {
    uVar1 = 0x6f8;
LAB_c057204c:
    *param_2 = uVar1;
  }
  else {
    if (param_1 == -0x3ffffff3) {
      uVar1 = 0x57;
    }
    else {
      if (param_1 == -0x7fffffe6) {
        *param_2 = 0x103;
        return;
      }
      if (param_1 == -0x3fffff63) {
        uVar1 = 0x48f;
        goto LAB_c057204c;
      }
      uVar1 = 0x1f;
    }
LAB_c0572058:
    *param_2 = uVar1;
  }
  return;
}



/* c0572064 UIO_Init */

/* Boundary evidence: original MIPS .pdata c0572064..c05720b7. Semantic name remains unreviewed. */

undefined4 UIO_Init(void)

{
  undefined4 *puVar1;
  
                    /* 0x2064  5  UIO_Init */
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
  puVar1 = &DAT_c0577180;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != &DAT_c05771a0);
  DriverEntry();
  return 0x400ce400;
}



/* c05720b8 UIO_Deinit */

/* Boundary evidence: original MIPS .pdata c05720b8..c05720db. Semantic name remains unreviewed. */

undefined4 UIO_Deinit(void)

{
                    /* 0x20b8  3  UIO_Deinit */
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
  return 1;
}



/* c05720dc UIO_Open */

/* Boundary evidence: original MIPS .pdata c05720dc..c057222f. Semantic name remains unreviewed. */

uint UIO_Open(undefined4 param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  int *local_28 [2];
  
                    /* 0x20dc  6  UIO_Open */
  NdisAllocateMemoryWithTag(local_28,0x4c,0x6f69754e);
  if (local_28[0] == (int *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    memset(local_28[0],0,0x4c);
    InitializeCriticalSection((LPCRITICAL_SECTION)(local_28[0] + 1));
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    iVar4 = 1;
    do {
      uVar2 = InterlockedIncrement((LONG *)&DAT_c0577154);
      bVar1 = FUN_c0571ee8(uVar2,local_28[0]);
      uVar3 = 0xffffffff;
      if (CONCAT31(extraout_var,bVar1) != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(local_28[0] + 1));
        local_28[0][6] = local_28[0][6] + 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)(local_28[0] + 1));
        uVar3 = uVar2;
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    if (uVar3 == 0xffffffff) {
      DeleteCriticalSection((LPCRITICAL_SECTION)(local_28[0] + 1));
      NdisFreeMemory(local_28[0],0,0);
    }
    else {
      local_28[0][8] = param_2;
    }
  }
  return uVar3;
}



/* c0572230 UIO_Close */

/* Boundary evidence: original MIPS .pdata c0572230..c057239b. Semantic name remains unreviewed. */

undefined4 UIO_Close(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar3;
  undefined4 *local_20;
  undefined4 *local_1c;
  
                    /* 0x2230  2  UIO_Close */
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
  FUN_c0571e74(param_1,&local_20,&local_1c);
  if (local_20 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *local_1c = *local_20;
    puVar2 = local_20;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
  if (puVar2 != (undefined4 *)0x0) {
    uVar3 = 1;
    if ((puVar2[0x12] != 0) && (puVar2[10] != 0)) {
      FUN_c057463c(puVar2[10],1,0xffff0002,0,0,&local_1c);
    }
    if (puVar2[0xd] != 0) {
      CloseMsgQueue();
      puVar2[0xf] = 0;
      puVar2[0xd] = 0;
    }
    if (puVar2[10] != 0) {
      FUN_c057120c(puVar2[10]);
      FUN_c057132c((int *)puVar2[10]);
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(puVar2 + 1);
    EnterCriticalSection(lpCriticalSection);
    iVar1 = puVar2[6];
    puVar2[6] = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      if (puVar2[9] != 0) {
        NdisFreeMemory(puVar2[9],0,0);
      }
      LeaveCriticalSection(lpCriticalSection);
      DeleteCriticalSection(lpCriticalSection);
      NdisFreeMemory(puVar2,0,0);
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return uVar3;
}



/* c057239c UIO_Write */

/* Boundary evidence: original MIPS .pdata c057239c..c0572627. Semantic name remains unreviewed. */

uint UIO_Write(uint param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  int *piVar6;
  wchar_t *_Str;
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar7;
  int local_38;
  undefined4 local_34;
  DWORD local_30 [2];
  
                    /* 0x239c  9  UIO_Write */
  local_38 = 0;
  uVar7 = 0xffffffff;
  piVar6 = (int *)0x0;
  bVar1 = false;
  bVar2 = false;
  iVar3 = CeGetCallerTrust();
  if (iVar3 != 2) {
    local_30[0] = 0xa0;
    goto LAB_c0572404;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
  iVar3 = FUN_c0571e74(param_1,(undefined4 *)0x0,(undefined4 *)0x0);
  if (iVar3 == 0) {
    local_38 = -0x3ffffff3;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    uVar7 = 0xffffffff;
LAB_c0572548:
    if ((piVar6 != (int *)0x0) && (bVar1)) {
      FUN_c057132c(piVar6);
    }
    if (bVar2) goto LAB_c0572568;
  }
  else {
    bVar2 = true;
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));
    *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    piVar6 = *(int **)(iVar3 + 0x28);
    if (piVar6 != (int *)0x0) {
LAB_c05724d0:
      iVar5 = CeAllocAsynchronousBuffer(&local_34,param_2,param_3,8);
      if (iVar5 == 0) {
        *(undefined4 *)(iVar3 + 0x30) = 1;
        uVar7 = FUN_c057185c((int)piVar6,&local_38,local_34,param_3);
        *(undefined4 *)(iVar3 + 0x30) = 0;
        CeFreeAsynchronousBuffer(local_34,param_2,param_3,8);
      }
      else {
        local_38 = -0x3fffff66;
      }
      goto LAB_c0572548;
    }
    _Str = *(wchar_t **)(iVar3 + 0x24);
    if (_Str != (wchar_t *)0x0) {
      sVar4 = wcslen(_Str);
      piVar6 = FUN_c0574aa4(_Str,sVar4 << 1);
      if (piVar6 == (int *)0x0) {
        local_38 = -0x3fffff63;
        goto LAB_c0572548;
      }
      bVar1 = true;
      goto LAB_c05724d0;
    }
    local_38 = -0x3ffffff3;
LAB_c0572568:
    lpCriticalSection = (LPCRITICAL_SECTION)(iVar3 + 4);
    EnterCriticalSection(lpCriticalSection);
    iVar5 = *(int *)(iVar3 + 0x18) + -1;
    *(int *)(iVar3 + 0x18) = iVar5;
    if (iVar5 == 0) {
      if (*(int *)(iVar3 + 0x24) != 0) {
        NdisFreeMemory(*(int *)(iVar3 + 0x24),0,0);
      }
      LeaveCriticalSection(lpCriticalSection);
      DeleteCriticalSection(lpCriticalSection);
      NdisFreeMemory(iVar3,0,0);
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  if (local_38 == 0) {
    return uVar7;
  }
  FUN_c0571f50(local_38,local_30);
LAB_c0572404:
  SetLastError(local_30[0]);
  return 0xffffffff;
}



/* c0572628 UIO_Read */

/* Boundary evidence: original MIPS .pdata c0572628..c0572813. Semantic name remains unreviewed. */

size_t UIO_Read(uint param_1,void *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  size_t sVar4;
  int local_28;
  DWORD local_24;
  
                    /* 0x2628  7  UIO_Read */
  local_28 = 0;
  bVar1 = false;
  sVar4 = 0xffffffff;
  iVar2 = CeGetCallerTrust();
  if (iVar2 == 2) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    iVar2 = FUN_c0571e74(param_1,(undefined4 *)0x0,(undefined4 *)0x0);
    if (iVar2 == 0) {
      local_28 = -0x3ffffff8;
    }
    else if ((*(int *)(iVar2 + 0x2c) == 0) && (*(int *)(iVar2 + 0x28) != 0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));
      *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));
      FUN_c0571308(*(int *)(iVar2 + 0x28));
      bVar1 = true;
    }
    else {
      local_28 = -0x3fffffff;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    if (local_28 == 0) {
      *(undefined4 *)(iVar2 + 0x2c) = 1;
      sVar4 = FUN_c05714d8(*(int **)(iVar2 + 0x28),&local_28,*(int *)(iVar2 + 0x44),param_2,param_3)
      ;
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
    if (bVar1) {
      FUN_c057132c(*(int **)(iVar2 + 0x28));
      lpCriticalSection = (LPCRITICAL_SECTION)(iVar2 + 4);
      EnterCriticalSection(lpCriticalSection);
      iVar3 = *(int *)(iVar2 + 0x18) + -1;
      *(int *)(iVar2 + 0x18) = iVar3;
      if (iVar3 == 0) {
        if (*(int *)(iVar2 + 0x24) != 0) {
          NdisFreeMemory(*(int *)(iVar2 + 0x24),0,0);
        }
        LeaveCriticalSection(lpCriticalSection);
        DeleteCriticalSection(lpCriticalSection);
        NdisFreeMemory(iVar2,0,0);
      }
      else {
        LeaveCriticalSection(lpCriticalSection);
      }
    }
    if (local_28 == 0) {
      return sVar4;
    }
    FUN_c0571f50(local_28,&local_24);
  }
  else {
    local_24 = 0xa0;
  }
  SetLastError(local_24);
  return sVar4;
}



/* c0572814 UIO_Seek */

undefined4 UIO_Seek(void)

{
                    /* 0x2814  8  UIO_Seek */
  return 0xffffffff;
}



/* c057281c FUN_c057281c */

/* Boundary evidence: original MIPS .pdata c057281c..c057292f. Semantic name remains unreviewed. */

undefined4 * FUN_c057281c(int param_1,wchar_t *param_2,undefined4 *param_3,int *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  size_t sVar3;
  undefined4 *puVar4;
  
  *param_4 = 0;
  *param_3 = 0;
  if (param_2 == (wchar_t *)0x0) {
    if (*(int *)(param_1 + 0x24) == 0) {
      *param_4 = -0x3ffeffeb;
      return (undefined4 *)0x0;
    }
    puVar4 = *(undefined4 **)(param_1 + 0x28);
LAB_c05728b0:
    puVar1 = puVar4;
    if (puVar4 != (undefined4 *)0x0) goto LAB_c05728f8;
  }
  else {
    puVar4 = *(undefined4 **)(param_1 + 0x28);
    puVar1 = (undefined4 *)0x0;
    if (puVar4 != (undefined4 *)0x0) {
      sVar3 = wcslen(param_2);
      iVar2 = memcmp(*(void **)(param_1 + 0x24),param_2,sVar3 << 1);
      if (iVar2 == 0) goto LAB_c05728b0;
    }
  }
  puVar4 = puVar1;
  if (param_2 != (wchar_t *)0x0) {
    sVar3 = wcslen(param_2);
    puVar4 = FUN_c0574aa4(param_2,sVar3 << 1);
    if (puVar4 == (undefined4 *)0x0) {
      *param_4 = -0x3fffff63;
      return (undefined4 *)0x0;
    }
    *param_3 = 1;
  }
LAB_c05728f8:
  if (*param_4 != 0) {
    return (undefined4 *)0x0;
  }
  return puVar4;
}



/* c0572930 FUN_c0572930 */

/* Boundary evidence: original MIPS .pdata c0572930..c05729a3. Semantic name remains unreviewed. */

void FUN_c0572930(int param_1,int param_2)

{
  if (param_1 != 0) {
    NdisFreeMemory(param_1,0,0);
  }
  if ((param_2 != 0) && (param_2 != param_1)) {
    NdisFreeMemory(param_2,0,0);
  }
  return;
}



/* c05729a4 FUN_c05729a4 */

undefined4 FUN_c05729a4(uint param_1)

{
  if (param_1 < 0x41) {
    if (param_1 == 0x40) {
      return 5;
    }
    if (param_1 == 1) {
      return 3;
    }
    if (param_1 == 2) {
      return 4;
    }
    if (param_1 == 4) {
      return 1;
    }
    if (param_1 == 8) {
      return 2;
    }
  }
  else {
    if (param_1 == 0x80) {
      return 6;
    }
    if (param_1 == 0x100) {
      return 7;
    }
    if (param_1 == 0x200) {
      return 8;
    }
    if (param_1 == 0x400) {
      return 9;
    }
  }
  return 10;
}



/* c0572a70 FUN_c0572a70 */

/* Boundary evidence: original MIPS .pdata c0572a70..c0572d8b. Semantic name remains unreviewed. */

void FUN_c0572a70(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                 void *param_7,uint param_8)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  uint *local_240 [2];
  uint auStack_238 [133];
  uint local_24;
  
  local_24 = DAT_c05770fc;
  uVar7 = param_8 + 0x214;
  if (param_8 == 0) {
    local_240[0] = auStack_238;
  }
  else {
    if (uVar7 < param_8) goto LAB_c0572d5c;
    NdisAllocateMemoryWithTag(local_240,uVar7,0x6f69754e);
  }
  if (local_240[0] == (uint *)0x0) goto LAB_c0572d5c;
  local_240[0][0x83] = 0x214;
  local_240[0][0x84] = param_8;
  if (param_2 == 0) {
    if (param_4 != 0) {
      if (param_5 == 0) {
        *local_240[0] = 0x20;
        goto LAB_c0572c14;
      }
      param_6 = 0x10;
    }
    *local_240[0] = param_6;
LAB_c0572c14:
    uVar3 = *(ushort *)(param_1 + 0x68) + 2;
    if (0x208 < uVar3) goto joined_r0xc0572c30;
    memcpy(local_240[0] + 1,*(void **)(param_1 + 0x6c),uVar3);
    if (param_8 != 0) {
      memcpy((void *)(local_240[0][0x83] + (int)local_240[0]),param_7,param_8);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    piVar6 = &DAT_c0577180;
    puVar4 = local_240[0];
    do {
      for (piVar5 = (int *)*piVar6; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
        if ((piVar5[0xf] & *puVar4) != 0) {
          WriteMsgQueue(piVar5[0xe],puVar4,uVar7,0,0);
          puVar4 = local_240[0];
        }
        if ((piVar5[0x10] & *puVar4) != 0) {
          uVar1 = FUN_c05729a4(*puVar4);
          iVar2 = FUN_c05757a8(param_1,uVar1,0,(int *)0x0);
          FUN_c0575b0c(param_1,iVar2);
          puVar4 = local_240[0];
        }
      }
      piVar6 = piVar6 + 1;
    } while ((int)piVar6 < -0x3fa88e60);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    if (local_240[0] == auStack_238) goto LAB_c0572d5c;
  }
  else {
    if (param_3 == 0x40010004) {
      uVar3 = 1;
LAB_c0572bd0:
      *local_240[0] = uVar3;
      goto LAB_c0572c14;
    }
    if (param_3 == 0x40010005) {
      uVar3 = 2;
LAB_c0572bc0:
      *local_240[0] = uVar3;
      goto LAB_c0572c14;
    }
    if (param_3 == 0x4001000b) {
      uVar3 = 4;
      goto LAB_c0572bd0;
    }
    if (param_3 == 0x4001000c) {
      uVar3 = 8;
      goto LAB_c0572bc0;
    }
    if (param_3 == 0x40010012) {
      uVar3 = 0x40;
      goto LAB_c0572bd0;
    }
    if (param_3 == 0x40020000) {
      uVar3 = 0x80;
      goto LAB_c0572bc0;
    }
    if (param_3 == 0x40020001) {
      *local_240[0] = 0x100;
      goto LAB_c0572c14;
    }
joined_r0xc0572c30:
    if (local_240[0] == auStack_238) goto LAB_c0572d5c;
  }
  NdisFreeMemory(local_240[0],0,0);
LAB_c0572d5c:
  FUN_c05763c4(local_24);
  return;
}



/* c0572d8c FUN_c0572d8c */

/* Boundary evidence: original MIPS .pdata c0572d8c..c0573193. Semantic name remains unreviewed. */

undefined4 FUN_c0572d8c(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  ushort *local_28 [2];
  
  local_28[0] = (ushort *)0x0;
  uVar9 = 0;
  NdisAllocateMemoryWithTag(local_28,0x30,0x6f69754e);
  if (local_28[0] == (ushort *)0x0) {
    uVar9 = 0xc000009a;
  }
  else {
    iVar8 = param_1 + 0x10;
    NdisAcquireSpinLock(iVar8);
    bVar1 = (*(uint *)(param_1 + 8) & 0xf) == 4;
    if (bVar1) {
      NdisInterlockedIncrement(param_1 + 0x48);
      NdisReleaseSpinLock(iVar8);
      memset((undefined4 *)(param_2 + 8),0,0x68);
      *(undefined4 *)(param_2 + 8) = 0;
      *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
      *(undefined4 *)(param_2 + 0x14) = 0;
      local_28[0][0] = 0;
      local_28[0][1] = 0;
      FUN_c0574554(param_1,0x10104,param_2 + 0xc,4);
      *(uint *)(param_2 + 100) = (uint)local_28[0][1];
      *(uint *)(param_2 + 0x68) = (uint)*local_28[0];
      *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(local_28[0] + 2);
      *(undefined4 *)(param_2 + 0x54) = 0;
      uVar2 = *(uint *)(local_28[0] + 0x14);
      iVar4 = *(int *)(local_28[0] + 0x16);
      iVar8 = *(int *)(local_28[0] + 0xe);
      uVar6 = uVar2 + *(int *)(local_28[0] + 0xc);
      iVar3 = *(int *)(local_28[0] + 4);
      iVar5 = *(int *)(local_28[0] + 6);
      *(uint *)(param_2 + 0x38) = uVar6 + iVar3;
      *(uint *)(param_2 + 0x3c) =
           iVar4 + iVar8 + (uint)(uVar6 < uVar2) + iVar5 + (uint)(uVar6 + iVar3 < uVar6);
      uVar2 = *(uint *)(local_28[0] + 0x10);
      iVar3 = *(int *)(local_28[0] + 0x12);
      iVar8 = *(int *)(local_28[0] + 10);
      uVar6 = uVar2 + *(int *)(local_28[0] + 8);
      uVar7 = uVar6 + *(int *)(param_2 + 0x48);
      *(uint *)(param_2 + 0x40) = uVar7;
      *(uint *)(param_2 + 0x44) =
           iVar3 + iVar8 + (uint)(uVar6 < uVar2) + *(int *)(param_2 + 0x4c) + (uint)(uVar7 < uVar6);
    }
    else {
      NdisReleaseSpinLock(iVar8);
      uVar9 = 0xc0000001;
    }
    if (local_28[0] != (ushort *)0x0) {
      NdisFreeMemory(local_28[0],0,0);
    }
    if (bVar1) {
      NdisInterlockedDecrement(param_1 + 0x48);
    }
  }
  return uVar9;
}



/* c0573194 UIO_IOControl */

/* WARNING: Removing unreachable block (ram,0xc0573d6c) */
/* Boundary evidence: original MIPS .pdata c0573194..c05740bf. Semantic name remains unreviewed. */

undefined4
UIO_IOControl(int *param_1,uint param_2,void *param_3,uint param_4,void *param_5,uint param_6,
             int *param_7)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  void *_Dst;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  LPCRITICAL_SECTION lpCriticalSection;
  int *local_294;
  int local_290;
  int *local_28c;
  int *local_288;
  void *local_284;
  int local_280;
  void *local_27c;
  uint local_278;
  code *local_274;
  undefined4 local_270;
  int local_26c;
  int *local_268;
  void *local_264;
  int *local_260;
  int iStack_25c;
  int local_258;
  undefined4 local_250 [3];
  undefined4 local_244;
  undefined4 local_240;
  wchar_t local_238 [260];
  uint local_30;
  
                    /* 0x3194  4  UIO_IOControl */
  local_30 = DAT_c05770fc;
  local_27c = param_5;
  local_268 = param_7;
  local_280 = 0;
  local_270 = 0;
  local_258 = 0;
  iVar9 = 0;
  local_290 = 0;
  local_294 = (int *)0x0;
  local_28c = (int *)0x0;
  local_260 = (int *)0x0;
  local_238[0] = L'\0';
  local_288 = param_1;
  local_284 = param_3;
  local_278 = param_4;
  local_264 = param_3;
  iVar1 = CeGetCallerTrust();
  if ((iVar1 != 2) &&
     ((((param_2 == 0x120800 || (param_2 == 0x120808)) || (param_2 == 0x120814)) ||
      (param_2 == 0x120818)))) goto LAB_c0573284;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
  iVar1 = FUN_c0571e74((uint)param_1,(undefined4 *)0x0,(undefined4 *)0x0);
  local_26c = iVar1;
  if (iVar1 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
    goto LAB_c0573dd4;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0577160);
  if ((local_284 == param_5) || ((param_5 == (void *)0x0 && (param_6 != 0)))) {
    uVar6 = param_4;
    if (param_4 <= param_6) {
      uVar6 = param_6;
    }
    local_274 = NdisAllocateMemoryWithTag;
    NdisAllocateMemoryWithTag(&local_294,uVar6,0x6f69754e);
    local_28c = local_294;
  }
  else {
    if ((param_2 == 0x12080c) || (param_2 == 0x120804)) goto LAB_c0573dd4;
    if (param_4 == 0) {
      local_274 = NdisAllocateMemoryWithTag;
    }
    else {
      local_274 = NdisAllocateMemoryWithTag;
      NdisAllocateMemoryWithTag(&local_294,param_4,0x6f69754e);
    }
    if (param_6 != 0) {
      NdisAllocateMemoryWithTag(&local_28c,param_6,0x6f69754e);
    }
  }
  if (((param_4 == 0) || (local_294 != (int *)0x0)) && ((param_6 == 0 || (local_28c != (int *)0x0)))
     ) {
    local_260 = &iStack_25c;
    if (param_4 != 0) {
      memcpy(local_294,local_284,param_4);
    }
    if ((param_5 != (void *)0x0) && (param_6 != 0)) {
      memcpy(local_28c,param_5,param_6);
    }
    piVar3 = local_288;
    piVar8 = local_294;
    iVar7 = -0x3ffeffeb;
    if (param_2 < 0x12081d) {
      if (param_2 == 0x12081c) {
        if (param_4 != 8) goto LAB_c0573dd4;
        local_250[0] = 0x14;
        local_240 = 0;
        local_244 = 0x1000;
        uVar4 = GetCallerProcess();
        iVar5 = OpenMsgQueue(uVar4,*local_294,local_250);
        *(int *)(iVar1 + 0x38) = iVar5;
        if (iVar5 != 0) {
          *(int *)(iVar1 + 0x34) = *piVar8;
          *(int *)(iVar1 + 0x3c) = piVar8[1];
          iVar7 = iVar9;
        }
      }
      else if (param_2 == 0x120800) {
LAB_c0573a6c:
        piVar8 = (int *)(iVar1 + 0x28);
        if (*piVar8 == 0) {
          local_258 = 1;
          if (param_2 == 0x120830) {
            if (((0xf < param_4) && ((uint)local_294[1] <= param_4 - 0xc)) && (*local_294 == 1)) {
              local_27c = (void *)local_294[2];
              uVar6 = local_294[1];
              piVar3 = local_294 + 3;
LAB_c0573b2c:
              local_280 = FUN_c0571c0c(piVar3,uVar6,piVar8);
              iVar7 = iVar9;
              if (local_280 == 0) {
                (**(code **)local_274)(iVar1 + 0x24,uVar6 + 2,0x6f69754e);
                if (*(void **)(iVar1 + 0x24) == (void *)0x0) {
                  FUN_c057120c(*piVar8);
                  *piVar8 = 0;
                  local_280 = -0x3fffff66;
                }
                else {
                  memcpy(*(void **)(iVar1 + 0x24),piVar3,uVar6);
                  *(undefined2 *)((uVar6 & 0xfffffffe) + *(int *)(iVar1 + 0x24)) = 0;
                  *(void **)(iVar1 + 0x40) = local_27c;
                  *(uint *)(iVar1 + 0x44) = (uint)(param_2 == 0x120830);
                  if (param_2 == 0x120830) {
                    *(uint *)(*piVar8 + 8) = *(uint *)(*piVar8 + 8) | 0x200000;
                  }
                }
              }
            }
          }
          else if (param_4 < 0x105) {
            local_27c = (void *)0x0;
            uVar6 = local_278;
            piVar3 = local_294;
            goto LAB_c0573b2c;
          }
        }
        else {
          iVar7 = -0x3fffffff;
        }
      }
      else if (param_2 == 0x120804) {
        if (param_6 < 0xc) {
LAB_c0573dd4:
          iVar7 = -0x3ffeffeb;
        }
        else if (((STRSAFE_LPCWSTR)local_294[1] == (STRSAFE_LPCWSTR)0x0) ||
                (HVar2 = StringCchCopyW(local_238,0x104,(STRSAFE_LPCWSTR)local_294[1]), HVar2 == 0))
        {
          piVar8 = FUN_c057281c(iVar1,local_238,&local_288,&local_290);
          if (piVar8 == (int *)0x0) goto LAB_c0573dd4;
          iVar7 = FUN_c0574b68((int)piVar8,local_294,param_6,&iStack_25c);
          if (local_288 != (int *)0x0) {
            FUN_c057132c(piVar8);
          }
        }
        else {
          local_290 = -0x3ffeffeb;
          iVar7 = -0x3ffeffeb;
        }
      }
      else if (param_2 == 0x120808) {
        if ((*(int *)(iVar1 + 0x20) == -0x40000000) && (*(int **)(iVar1 + 0x28) != (int *)0x0)) {
          FUN_c0575a2c(*(int **)(iVar1 + 0x28));
          iVar7 = FUN_c0571418(*(int *)(iVar1 + 0x28),(undefined2 *)local_294,param_4 >> 1);
        }
        else {
LAB_c0573810:
          iVar7 = -0x3fffff45;
        }
      }
      else if (param_2 == 0x12080c) {
        iVar7 = FUN_c05748b4(local_294,param_4,param_6,&iStack_25c);
      }
      else if (param_2 == 0x120814) {
        if (param_4 < 0xc) goto LAB_c0573dd4;
        local_288 = local_294;
        if (((STRSAFE_LPCWSTR)local_294[1] == (STRSAFE_LPCWSTR)0x0) ||
           (HVar2 = StringCchCopyW(local_238,0x104,(STRSAFE_LPCWSTR)local_294[1]), HVar2 == 0)) {
          piVar3 = FUN_c057281c(iVar1,local_238,&local_288,&local_290);
          if (piVar3 != (int *)0x0) {
            iVar7 = FUN_c0574cb8((int)piVar3,local_294,param_4);
            if (iVar7 == 0) {
              if (*piVar8 == -0xffff) {
                *(undefined4 *)(iVar1 + 0x48) = 1;
              }
              else if (*piVar8 == -0xfffe) {
                *(undefined4 *)(iVar1 + 0x48) = 0;
              }
            }
            if (local_288 != (int *)0x0) {
              FUN_c057132c(piVar3);
            }
            goto LAB_c0573e00;
          }
        }
        else {
          local_290 = -0x3ffeffeb;
        }
LAB_c0573708:
        iVar7 = -0x3ffeffeb;
      }
      else {
        if (param_2 != 0x120818) goto LAB_c0573810;
        if ((*(uint *)(iVar1 + 0x20) & 0x80000000) == 0) {
          if (0x104 < param_4) goto LAB_c0573dd4;
          piVar8 = (int *)(iVar1 + 0x24);
          (**(code **)local_274)(piVar8,param_4 + 2,0x6f69754e);
          if ((void *)*piVar8 == (void *)0x0) goto LAB_c0573448;
          memcpy((void *)*piVar8,local_294,param_4);
          *(undefined2 *)((param_4 & 0xfffffffe) + *piVar8) = 0;
          iVar7 = iVar9;
        }
        else {
          iVar7 = -0x3fffffff;
        }
      }
    }
    else if (param_2 == 0x120820) {
      if (*(int *)(iVar1 + 0x34) == 0) goto LAB_c0573dd4;
      CloseMsgQueue();
      *(undefined4 *)(iVar1 + 0x3c) = 0;
      *(undefined4 *)(iVar1 + 0x34) = 0;
      iVar7 = iVar9;
    }
    else if (param_2 == 0x120824) {
      if (param_6 != 0x70) goto LAB_c0573dd4;
      HVar2 = StringCchCopyW(local_238,0x104,(STRSAFE_LPCWSTR)local_28c[1]);
      if (HVar2 != 0) {
        local_290 = -0x3ffeffeb;
        goto LAB_c0573708;
      }
      piVar8 = FUN_c057281c(iVar1,local_238,&local_288,&local_290);
      if (piVar8 != (int *)0x0) {
        if (piVar8[0x19] == 1) {
          iVar7 = FUN_c0572d8c((int)piVar8,(int)local_28c);
          if (local_288 != (int *)0x0) {
            FUN_c057132c(piVar8);
          }
        }
        else {
          iVar7 = -0x3ffeffef;
        }
      }
    }
    else if (param_2 == 0x120828) {
      FUN_c0571800(*(int *)(iVar1 + 0x28));
      iVar7 = iVar9;
    }
    else {
      if (param_2 == 0x120830) goto LAB_c0573a6c;
      if (param_2 != 0x10303ff) goto LAB_c0573810;
      if (*(int *)(iVar1 + 0x28) != 0) {
        FUN_c0571800(*(int *)(iVar1 + 0x28));
      }
      iVar7 = *(int *)(iVar1 + 0x30);
      while (iVar7 != 0) {
        Sleep(1000);
        iVar7 = *(int *)(iVar1 + 0x30);
      }
      UIO_Close((uint)piVar3);
      iVar7 = iVar9;
    }
  }
  else {
LAB_c0573448:
    iVar7 = -0x3fffff66;
  }
LAB_c0573e00:
  iVar9 = local_280;
  if ((((local_258 == 0) && (iVar9 = iVar7, iVar7 != 0)) && (iVar7 != 0x103)) &&
     (((iVar7 != -0x7ffffffb && (iVar7 != -0x3fffffff)) &&
      ((iVar7 != -0x3fffff66 && (iVar7 != -0x3fffff45)))))) {
    if (iVar7 == -0x3ffeffea) {
      iVar9 = -0x3fffffdd;
    }
    else if (iVar7 == -0x3ffeffec) {
      iVar9 = -0x3ffffdfa;
    }
    else if (iVar7 == -0x3ffeffeb) {
      iVar9 = -0x3ffffff3;
    }
    else if (iVar7 == -0x3ffefffa) {
      iVar9 = -0x7fffffe6;
    }
    else {
      iVar9 = -0x3fffffff;
      if (iVar7 == -0x3ffeffef) {
        iVar9 = -0x3fffff63;
      }
    }
  }
  if (iVar1 != 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(iVar1 + 4);
    EnterCriticalSection(lpCriticalSection);
    iVar7 = *(int *)(iVar1 + 0x18) + -1;
    *(int *)(iVar1 + 0x18) = iVar7;
    if (iVar7 == 0) {
      if (*(int *)(iVar1 + 0x24) != 0) {
        NdisFreeMemory(*(int *)(iVar1 + 0x24),0,0);
      }
      LeaveCriticalSection(lpCriticalSection);
      DeleteCriticalSection(lpCriticalSection);
      NdisFreeMemory(iVar1,0,0);
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  _Dst = local_284;
  if (local_294 != (int *)0x0) {
    memcpy(local_284,local_294,local_278);
  }
  if (local_28c != (int *)0x0) {
    if (param_5 != (void *)0x0) {
      _Dst = param_5;
    }
    memcpy(_Dst,local_28c,param_6);
  }
  if ((local_268 != (int *)0x0) && (local_260 != (int *)0x0)) {
    *local_268 = *local_260;
  }
  FUN_c0572930((int)local_294,(int)local_28c);
  if (iVar9 == 0) {
    FUN_c05763c4(local_30);
    return 1;
  }
  FUN_c0571f50(iVar9,&local_268);
  SetLastError((DWORD)local_268);
LAB_c0573284:
  FUN_c05763c4(local_30);
  return 0;
}



/* c05740c0 FUN_c05740c0 */

/* Boundary evidence: original MIPS .pdata c05740c0..c05740cb. Semantic name remains unreviewed. */

undefined4 FUN_c05740c0(void)

{
  return 1;
}



/* c05740cc FUN_c05740cc */

/* Boundary evidence: original MIPS .pdata c05740cc..c05740d7. Semantic name remains unreviewed. */

undefined4 FUN_c05740cc(void)

{
  return 1;
}



/* c05740d8 FUN_c05740d8 */

/* Boundary evidence: original MIPS .pdata c05740d8..c05740e3. Semantic name remains unreviewed. */

undefined4 FUN_c05740d8(void)

{
  return 1;
}



/* c05740e4 FUN_c05740e4 */

/* Boundary evidence: original MIPS .pdata c05740e4..c05740ef. Semantic name remains unreviewed. */

undefined4 FUN_c05740e4(void)

{
  return 1;
}



/* c05740f0 FUN_c05740f0 */

/* Boundary evidence: original MIPS .pdata c05740f0..c05740fb. Semantic name remains unreviewed. */

undefined4 FUN_c05740f0(void)

{
  return 1;
}



/* c05740fc FUN_c05740fc */

/* Boundary evidence: original MIPS .pdata c05740fc..c0574123. Semantic name remains unreviewed. */

void FUN_c05740fc(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x78) = param_2;
  NdisSetEvent(param_1 + 0x7c);
  return;
}



/* c0574124 FUN_c0574124 */

/* Boundary evidence: original MIPS .pdata c0574124..c057414b. Semantic name remains unreviewed. */

void FUN_c0574124(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x78) = param_2;
  NdisSetEvent(param_1 + 0x7c);
  return;
}



/* c057414c FUN_c057414c */

/* Boundary evidence: original MIPS .pdata c057414c..c057422b. Semantic name remains unreviewed. */

void FUN_c057414c(int param_1)

{
  if (*(int *)(param_1 + 0x28) != 0) {
    NdisFreePacketPool();
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    NdisFreePacketPool();
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    NdisFreeBufferPool();
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    NdisFreeBufferPool();
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    NdisFreeMemory(*(int *)(param_1 + 0x6c),0,0);
    *(undefined4 *)(param_1 + 0x6c) = 0;
    *(undefined2 *)(param_1 + 0x6a) = 0;
    *(undefined2 *)(param_1 + 0x68) = 0;
  }
  if (*(int *)(param_1 + 0x74) != 0) {
    NdisFreeMemory(*(int *)(param_1 + 0x74),0,0);
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  return;
}



/* c057422c FUN_c057422c */

/* Boundary evidence: original MIPS .pdata c057422c..c057432f. Semantic name remains unreviewed. */

void FUN_c057422c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int local_20 [2];
  
  uVar2 = 0;
  do {
    iVar1 = NdisQueryPendingIOCount(*(undefined4 *)(param_1 + 0x24),local_20);
    if ((iVar1 != 0) || (local_20[0] == 0)) break;
    Sleep(2000);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x3c);
  uVar2 = 0;
  do {
    if (*(int *)(param_1 + 0x48) == 0) break;
    Sleep(1000);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x14);
  if (param_2 != 0) {
    NdisAcquireSpinLock(param_1 + 0x10);
    if (*(int *)(param_1 + 0x50) != 0) {
      NdisSetEvent(param_1 + 0x4c);
    }
    NdisReleaseSpinLock(param_1 + 0x10);
  }
  return;
}



/* c0574330 FUN_c0574330 */

/* Boundary evidence: original MIPS .pdata c0574330..c0574553. Semantic name remains unreviewed. */

int FUN_c0574330(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_30 [2];
  
  uVar3 = 0;
  NdisAllocateMemoryWithTag(local_30,100,0x6f69754e);
  if (local_30[0] != 0) {
    do {
      iVar1 = local_30[0];
      NdisAcquireSpinLock(param_1 + 0x10);
      if ((*(uint *)(param_1 + 8) & 0x10000000) == 0x10000000) {
        NdisReleaseSpinLock(param_1 + 0x10);
        iVar2 = -0x3fffffff;
        goto LAB_c05744e4;
      }
      NdisReleaseSpinLock();
      NdisInitializeEvent(local_30[0] + 0x5c);
      *(int *)(iVar1 + 0x10) = param_2;
      if ((param_2 == 0) || (param_2 == 1)) {
        *(undefined4 *)(iVar1 + 0x1c) = param_5;
        *(undefined4 *)(iVar1 + 0x18) = param_4;
        *(undefined4 *)(iVar1 + 0x14) = param_3;
      }
      iVar2 = (**(code **)(*(int *)(param_1 + 0x24) + 0x6c))(*(int *)(param_1 + 0x24),iVar1);
      if (iVar2 == 0x103) {
        NdisWaitEvent(local_30[0] + 0x5c,0);
        iVar2 = *(int *)(local_30[0] + 0x60);
      }
      if (iVar2 == 0) {
        *param_6 = *(undefined4 *)(iVar1 + 0x20);
      }
      NdisFreeEvent(local_30[0] + 0x5c);
      if ((iVar2 != -0x3ffefff4) || (uVar3 = uVar3 + 1, 2 < uVar3)) goto LAB_c05744e4;
      Sleep(1000);
      NdisAllocateMemoryWithTag(local_30,100,0x6f69754e);
    } while (local_30[0] != 0);
  }
  iVar2 = -0x3fffff66;
LAB_c05744e4:
  if (local_30[0] != 0) {
    NdisFreeMemory(local_30[0],0,0);
  }
  return iVar2;
}



/* c0574554 FUN_c0574554 */

/* Boundary evidence: original MIPS .pdata c0574554..c057463b. Semantic name remains unreviewed. */

void FUN_c0574554(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 auStack_18 [2];
  
  piVar4 = (int *)register0x00000074;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  while( true ) {
    piVar1 = piVar4 + 1;
    if (*piVar1 == 0) break;
    piVar2 = piVar4 + 2;
    piVar3 = piVar4 + 3;
    piVar4 = piVar4 + 4;
    puVar5 = (undefined4 *)*piVar4;
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = auStack_18;
    }
    FUN_c0574330(param_1,0,*piVar1,*piVar2,*piVar3,puVar5);
  }
  return;
}



/* c057463c FUN_c057463c */

/* Boundary evidence: original MIPS .pdata c057463c..c057473f. Semantic name remains unreviewed. */

int FUN_c057463c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 *param_6)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0x10;
    NdisAcquireSpinLock(iVar1);
    if ((*(uint *)(param_1 + 8) & 0xf) == 4) {
      NdisInterlockedIncrement(param_1 + 0x48);
      NdisReleaseSpinLock(iVar1);
      iVar1 = FUN_c0574330(param_1,param_2,param_3,param_4,param_5,param_6);
      NdisInterlockedDecrement(param_1 + 0x48);
      return iVar1;
    }
    NdisReleaseSpinLock(iVar1);
  }
  return -0x3ffeffeb;
}



/* c0574748 FUN_c0574748 */

/* Boundary evidence: original MIPS .pdata c0574748..c057476f. Semantic name remains unreviewed. */

void FUN_c0574748(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x60) = param_3;
  NdisSetEvent(param_2 + 0x5c);
  return;
}



/* c0574770 FUN_c0574770 */

/* Boundary evidence: original MIPS .pdata c0574770..c05748b3. Semantic name remains unreviewed. */

void FUN_c0574770(int param_1,int param_2,void *param_3,uint param_4)

{
  NdisAcquireSpinLock(param_1 + 0x10);
  if (*(int *)(param_1 + 100) == 1) {
    if (param_2 == 0x40010004) {
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x100;
    }
    else if (param_2 == 0x40010005) {
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffeff;
    }
    else if (param_2 == 0x4001000b) {
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffdff;
    }
    else if ((param_2 == 0x4001000c) &&
            (*(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x200, *(int *)(param_1 + 0x50) != 0)
            ) {
      NdisSetEvent(param_1 + 0x4c);
    }
  }
  FUN_c0572a70(param_1,1,param_2,0,0,0,param_3,param_4);
  NdisReleaseSpinLock(param_1 + 0x10);
  return;
}



/* c05748b4 FUN_c05748b4 */

/* Boundary evidence: original MIPS .pdata c05748b4..c0574aa3. Semantic name remains unreviewed. */

undefined4 FUN_c05748b4(int *param_1,uint param_2,uint param_3,int *param_4)

{
  ushort uVar1;
  uint _Size;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (param_2 < 0x14) {
    uVar2 = 0xc000009a;
  }
  else if (param_3 < 0x14) {
    uVar2 = 0x80000005;
  }
  else {
    iVar5 = *param_1;
    uVar2 = 0xc0010006;
    NdisAcquireSpinLock(&DAT_c057713c);
    for (puVar3 = DAT_c0577134; (undefined4 **)puVar3 != &DAT_c0577134;
        puVar3 = (undefined4 *)*puVar3) {
      puVar4 = puVar3 + 4;
      NdisAcquireSpinLock(puVar4);
      if ((puVar3[2] & 0xf) == 4) {
        if (iVar5 == 0) {
          uVar1 = *(ushort *)(puVar3 + 0x1a);
          param_1[2] = uVar1 + 2;
          _Size = *(ushort *)(puVar3 + 0x1c) + 2 + uVar1 + 2;
          param_1[4] = *(ushort *)(puVar3 + 0x1c) + 2;
          if (param_3 - 0x14 < _Size) {
            NdisReleaseSpinLock(puVar3 + 4);
            uVar2 = 0x80000005;
          }
          else {
            memset(param_1 + 5,0,_Size);
            param_1[1] = 0x14;
            memcpy(param_1 + 5,(void *)puVar3[0x1b],(uint)*(ushort *)(puVar3 + 0x1a));
            param_1[3] = param_1[2] + param_1[1];
            memcpy((void *)(param_1[2] + param_1[1] + (int)param_1),(void *)puVar3[0x1d],
                   (uint)*(ushort *)(puVar3 + 0x1c));
            NdisReleaseSpinLock(puVar3 + 4);
            uVar2 = 0;
            *param_4 = param_1[3] + param_1[4];
          }
          break;
        }
        NdisReleaseSpinLock(puVar4);
        iVar5 = iVar5 + -1;
      }
      else {
        NdisReleaseSpinLock(puVar4);
      }
    }
    NdisReleaseSpinLock(&DAT_c057713c);
  }
  return uVar2;
}



/* c0574aa4 FUN_c0574aa4 */

/* Boundary evidence: original MIPS .pdata c0574aa4..c0574b67. Semantic name remains unreviewed. */

undefined4 * FUN_c0574aa4(void *param_1,size_t param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  NdisAcquireSpinLock(&DAT_c057713c);
  puVar2 = DAT_c0577134;
  do {
    puVar3 = (undefined4 *)0x0;
    if ((undefined4 **)puVar2 == &DAT_c0577134) {
LAB_c0574b34:
      NdisReleaseSpinLock(&DAT_c057713c);
      return puVar3;
    }
    if ((*(ushort *)(puVar2 + 0x1a) == param_2) &&
       (iVar1 = memcmp((void *)puVar2[0x1b],param_1,param_2), iVar1 == 0)) {
      FUN_c0571308((int)puVar2);
      puVar3 = puVar2;
      goto LAB_c0574b34;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* c0574b68 FUN_c0574b68 */

/* Boundary evidence: original MIPS .pdata c0574b68..c0574cb7. Semantic name remains unreviewed. */

int FUN_c0574b68(int param_1,undefined4 *param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_3 < 0xc) {
    iVar1 = -0x3ffeffea;
  }
  else {
    iVar2 = param_1 + 0x10;
    uVar3 = *param_2;
    NdisAcquireSpinLock(iVar2);
    if ((*(uint *)(param_1 + 8) & 0xf) == 4) {
      NdisInterlockedIncrement(param_1 + 0x48);
      NdisReleaseSpinLock(iVar2);
      iVar1 = FUN_c0574330(param_1,0,uVar3,param_2 + 2,param_3 - 8,param_4);
      NdisAcquireSpinLock(iVar2);
      NdisInterlockedDecrement(param_1 + 0x48);
      NdisReleaseSpinLock(iVar2);
      if (iVar1 == 0) {
        *param_4 = *param_4 + 8;
      }
    }
    else {
      NdisReleaseSpinLock(iVar2);
      iVar1 = -0x3fffffff;
    }
  }
  return iVar1;
}



/* c0574cb8 FUN_c0574cb8 */

/* Boundary evidence: original MIPS .pdata c0574cb8..c0574deb. Semantic name remains unreviewed. */

int FUN_c0574cb8(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 auStack_30 [2];
  
  if (param_3 < 0xc) {
    iVar1 = -0x3ffeffea;
  }
  else {
    iVar2 = param_1 + 0x10;
    uVar3 = *param_2;
    NdisAcquireSpinLock(iVar2);
    if ((*(uint *)(param_1 + 8) & 0xf) == 4) {
      NdisInterlockedIncrement(param_1 + 0x48);
      NdisReleaseSpinLock(iVar2);
      iVar1 = FUN_c0574330(param_1,1,uVar3,param_2 + 2,param_3 - 8,auStack_30);
      NdisAcquireSpinLock(iVar2);
      NdisInterlockedDecrement(param_1 + 0x48);
      NdisReleaseSpinLock(iVar2);
    }
    else {
      NdisReleaseSpinLock(iVar2);
      iVar1 = -0x3fffffff;
    }
  }
  return iVar1;
}



/* c0574dec FUN_c0574dec */

/* Boundary evidence: original MIPS .pdata c0574dec..c0574f13. Semantic name remains unreviewed. */

undefined4 FUN_c0574dec(int *param_1,int *param_2)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *param_2;
  if (iVar3 == 0) {
    iVar3 = *(int *)param_2[1];
    param_1[0x19] = iVar3;
    if (1 < iVar3) {
      FUN_c057422c((int)param_1,0);
      FUN_c0575a2c(param_1);
    }
    uVar4 = 0x200;
    if (param_1[0x19] != 1) {
      uVar4 = 0x400;
    }
    piVar1 = param_1 + 4;
    NdisAcquireSpinLock(piVar1);
    FUN_c0572a70((int)param_1,0,0,0,0,uVar4,(void *)0x0,0);
    pcVar2 = NdisReleaseSpinLock_exref;
  }
  else {
    if (iVar3 == 1) {
      return 0;
    }
    if (iVar3 < 2) {
      return 0xc00000bb;
    }
    if (iVar3 < 6) {
      return 0;
    }
    if (iVar3 != 6) {
      if (iVar3 == 7) {
        return 0;
      }
      return 0xc00000bb;
    }
    piVar1 = (int *)&DAT_c0577150;
    pcVar2 = NdisSetEvent_exref;
  }
  (*pcVar2)(piVar1);
  return 0;
}



/* c0574f14 FUN_c0574f14 */

/* Boundary evidence: original MIPS .pdata c0574f14..c057506f. Semantic name remains unreviewed. */

void FUN_c0574f14(int *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int local_20 [2];
  
  piVar3 = param_1 + 4;
  NdisAcquireSpinLock(piVar3);
  uVar2 = param_1[2] & 0xf;
  if (uVar2 == 1) {
    NdisReleaseSpinLock(piVar3);
  }
  else {
    bVar1 = uVar2 == 4;
    if (bVar1) {
      param_1[2] = param_1[2] & 0xfffffff8U | 8;
    }
    NdisReleaseSpinLock(piVar3);
    if (bVar1) {
      FUN_c057422c((int)param_1,1);
      FUN_c0575a2c(param_1);
      NdisCloseAdapter(local_20,param_1[9]);
      if (local_20[0] == 0x103) {
        NdisWaitEvent(param_1 + 0x1f,0);
        local_20[0] = param_1[0x1e];
      }
      param_1[9] = 0;
    }
    FUN_c057414c((int)param_1);
    if (bVar1) {
      NdisAcquireSpinLock(piVar3);
      param_1[2] = param_1[2] & 0xfffffff0;
      NdisReleaseSpinLock(piVar3);
    }
    FUN_c057132c(param_1);
  }
  return;
}



/* c0575070 FUN_c0575070 */

/* Boundary evidence: original MIPS .pdata c0575070..c057513b. Semantic name remains unreviewed. */

void FUN_c0575070(int *param_1,int *param_2)

{
  if (*param_1 == 0) {
    NdisAcquireSpinLock(param_2 + 4);
    FUN_c0572a70((int)param_2,0,0,1,0,0,(void *)0x0,0);
    NdisReleaseSpinLock(param_2 + 4);
  }
  NdisAcquireSpinLock(param_2 + 4);
  param_2[2] = param_2[2] | 0x10000000;
  NdisReleaseSpinLock(param_2 + 4);
  FUN_c0574f14(param_2);
  *param_1 = 0;
  return;
}



/* c057513c FUN_c057513c */

/* Boundary evidence: original MIPS .pdata c057513c..c05755f3. Semantic name remains unreviewed. */

int FUN_c057513c(int *param_1,void *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int local_40;
  int local_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [8];
  
  local_3c = 0;
  local_40 = 0;
  bVar1 = false;
  bVar2 = false;
  piVar3 = FUN_c0574aa4(param_2,param_3);
  if (piVar3 == (int *)0x0) {
    piVar3 = param_1 + 4;
    NdisAcquireSpinLock(piVar3);
    uVar5 = param_1[2];
    if (((uVar5 & 0xf) == 0) && ((uVar5 & 0x10000000) != 0x10000000)) {
      param_1[2] = uVar5 & 0xfffffff1 | 1;
      NdisReleaseSpinLock(piVar3);
      if (param_3 + 2 < param_3) {
        local_40 = -0x3ffeffeb;
      }
      else {
        piVar6 = param_1 + 0x1b;
        NdisAllocateMemoryWithTag(piVar6,param_3 + 2,0x6f69754e);
        if ((void *)*piVar6 == (void *)0x0) {
          local_40 = -0x3fffff66;
        }
        else {
          memcpy((void *)*piVar6,param_2,param_3);
          *(undefined2 *)(*piVar6 + param_3) = 0;
          NdisInitUnicodeString(param_1 + 0x1a,*piVar6);
          NdisAllocatePacketPoolEx(&local_40,param_1 + 10,0x14,0x17c,0xc);
          if (local_40 == 0) {
            NdisSetPacketPoolProtocolId(param_1[10],4);
            NdisAllocatePacketPoolEx(&local_40,param_1 + 0xc,4,0x10,0x10);
            if ((local_40 == 0) &&
               (NdisAllocateBufferPool(&local_40,param_1 + 0xd,0x14), local_40 == 0)) {
              NdisInitializeEvent(param_1 + 0x1f);
              NdisOpenAdapter(&local_40,auStack_30,param_1 + 9,auStack_34,&DAT_c05770f4,2,
                              DAT_c0577128,param_1,param_1 + 0x1a,0,0);
              if (local_40 == 0x103) {
                NdisWaitEvent(param_1 + 0x1f,0);
                local_40 = param_1[0x1e];
              }
              if (local_40 == 0) {
                bVar2 = true;
                NdisQueryAdapterInstanceName(param_1 + 0x1c,param_1[9]);
                local_40 = FUN_c0574330((int)param_1,0,0x10113,param_1 + 0xe,4,&uStack_38);
                if ((local_40 == 0) &&
                   (local_40 = FUN_c0574330((int)param_1,0,0x10106,param_1 + 0xf,4,&uStack_38),
                   local_40 == 0)) {
                  iVar4 = FUN_c0574330((int)param_1,0,0x10114,&local_3c,4,&uStack_38);
                  if (iVar4 != 0) {
                    local_3c = 0;
                  }
                  local_40 = 0;
                  if (local_3c == 0) {
                    param_1[2] = param_1[2] & 0xfffffdff;
                  }
                  else {
                    param_1[2] = param_1[2] | 0x200;
                  }
                  param_1[0x19] = 1;
                  NdisAcquireSpinLock(piVar3);
                  uVar5 = param_1[2];
                  param_1[2] = uVar5 & 0xfffffff4 | 4;
                  if ((uVar5 & 0x10000000) == 0x10000000) {
                    local_40 = -0x3fffffff;
                  }
                  *(undefined2 *)(param_1 + 0x20) = 0x8001;
                  param_1[0x22] = 1;
                  NdisReleaseSpinLock(piVar3);
                  goto LAB_c0575578;
                }
              }
            }
          }
        }
      }
    }
    else {
      NdisReleaseSpinLock(piVar3);
      bVar1 = true;
      local_40 = 0x10003;
LAB_c0575578:
      if (local_40 == 0) {
        return 0;
      }
    }
  }
  else {
    FUN_c057132c(piVar3);
    local_40 = -0x3fffffff;
  }
  if (bVar1) {
    return local_40;
  }
  NdisAcquireSpinLock(param_1 + 4);
  if (bVar2) {
    uVar5 = param_1[2] & 0xfffffff4U | 4;
  }
  else {
    if ((param_1[2] & 0xfU) != 1) goto LAB_c05755ac;
    uVar5 = param_1[2] & 0xfffffff2U | 2;
  }
  param_1[2] = uVar5;
LAB_c05755ac:
  NdisReleaseSpinLock(param_1 + 4);
  FUN_c0574f14(param_1);
  return local_40;
}



/* c05755f4 FUN_c05755f4 */

/* Boundary evidence: original MIPS .pdata c05755f4..c05757a7. Semantic name remains unreviewed. */

void FUN_c05755f4(int *param_1,undefined4 param_2,ushort *param_3)

{
  int iVar1;
  int *local_20 [2];
  
  NdisAllocateMemoryWithTag(local_20,0x90,0x6f69754e);
  if (local_20[0] == (int *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    memset(local_20[0],0,0x90);
    NdisAllocateSpinLock(local_20[0] + 4);
    NdisInitializeEvent(local_20[0] + 0x13);
    local_20[0][0x14] = 0;
    local_20[0][0x15] = -1;
    local_20[0][0x11] = (int)(local_20[0] + 0x10);
    local_20[0][0x10] = local_20[0][0x11];
    local_20[0][0x17] = (int)(local_20[0] + 0x16);
    local_20[0][0x16] = local_20[0][0x17];
    FUN_c0571308((int)local_20[0]);
    NdisAcquireSpinLock(&DAT_c057713c);
    *local_20[0] = (int)&DAT_c0577134;
    local_20[0][1] = (int)DAT_c0577138;
    *DAT_c0577138 = (int)local_20[0];
    DAT_c0577138 = local_20[0];
    NdisReleaseSpinLock(&DAT_c057713c);
    iVar1 = FUN_c057513c(local_20[0],*(void **)(param_3 + 2),(uint)*param_3);
  }
  *param_1 = iVar1;
  if (iVar1 == 0) {
    NdisAcquireSpinLock(local_20[0] + 4);
    FUN_c0572a70((int)local_20[0],0,0,1,1,0,(void *)0x0,0);
    NdisReleaseSpinLock(local_20[0] + 4);
  }
  return;
}



/* c05757a8 FUN_c05757a8 */

/* Boundary evidence: original MIPS .pdata c05757a8..c0575953. Semantic name remains unreviewed. */

int FUN_c05757a8(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int local_28;
  int *local_24;
  int local_20;
  int local_1c;
  
  local_28 = 0;
  local_24 = (int *)0x0;
  local_20 = 0;
  if (((param_3 == 0) ||
      ((NdisAllocateMemoryWithTag(&local_20,param_3,0x6f69754e), local_20 != 0 &&
       (NdisAllocateBuffer(&local_1c,&local_24,*(undefined4 *)(param_1 + 0x34),local_20,param_3),
       local_1c == 0)))) &&
     (NdisAllocatePacket(&local_1c,&local_28,*(undefined4 *)(param_1 + 0x30)), local_1c == 0)) {
    *(undefined4 *)((uint)*(ushort *)(local_28 + 0x1e) + local_28 + 0x1c) = 0;
    *(undefined4 *)(local_28 + 0x44) = 0;
    *(undefined4 *)(local_28 + 0x40) = param_2;
    if (local_24 != (int *)0x0) {
      iVar2 = *local_24;
      piVar1 = local_24;
      while (iVar2 != 0) {
        piVar1 = (int *)*piVar1;
        iVar2 = *piVar1;
      }
      if (*(int *)(local_28 + 8) == 0) {
        *(int **)(local_28 + 0xc) = piVar1;
      }
      *piVar1 = *(int *)(local_28 + 8);
      *(int **)(local_28 + 8) = local_24;
      *(undefined1 *)(local_28 + 0x1c) = 0;
      *param_4 = local_20;
    }
  }
  if (local_28 == 0) {
    if (local_24 != (int *)0x0) {
      NdisFreeBuffer();
    }
    if (local_20 != 0) {
      NdisFreeMemory(local_20,0,0);
    }
  }
  return local_28;
}



/* c0575954 FUN_c0575954 */

/* Boundary evidence: original MIPS .pdata c0575954..c0575a2b. Semantic name remains unreviewed. */

void FUN_c0575954(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_res4 [3];
  
  local_res4[0] = param_2;
  iVar1 = NdisGetPoolFromPacket(param_2);
  if (iVar1 == *(int *)(param_1 + 0x30)) {
    piVar3 = *(int **)(local_res4[0] + 8);
    if (piVar3 == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = piVar3[1];
      for (piVar2 = (int *)*piVar3; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      }
    }
    NdisFreePacket();
    if (piVar3 != (int *)0x0) {
      NdisFreeBuffer(piVar3);
      NdisFreeMemory(iVar1,0,0);
    }
  }
  else {
    NdisReturnPackets(local_res4,1);
  }
  return;
}



/* c0575a2c FUN_c0575a2c */

/* Boundary evidence: original MIPS .pdata c0575a2c..c0575b0b. Semantic name remains unreviewed. */

void FUN_c0575a2c(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  FUN_c0571308((int)param_1);
  piVar1 = param_1 + 4;
  NdisAcquireSpinLock(piVar1);
  while (piVar2 = (int *)param_1[0x16], piVar2 != param_1 + 0x16) {
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
    param_1[0x18] = param_1[0x18] + -1;
    NdisReleaseSpinLock();
    FUN_c0575954((int)param_1,(int)(piVar2 + -0xe));
    FUN_c057132c(param_1);
    NdisAcquireSpinLock(piVar1);
  }
  NdisReleaseSpinLock(piVar1);
  FUN_c057132c(param_1);
  return;
}



/* c0575b0c FUN_c0575b0c */

/* Boundary evidence: original MIPS .pdata c0575b0c..c0575c33. Semantic name remains unreviewed. */

void FUN_c0575b0c(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = param_1 + 0x10;
  piVar3 = (int *)(param_2 + 0x38);
  NdisAcquireSpinLock(iVar4);
  puVar1 = *(undefined4 **)(param_1 + 0x5c);
  *piVar3 = param_1 + 0x58;
  *(undefined4 **)(param_2 + 0x3c) = puVar1;
  *puVar1 = piVar3;
  *(int **)(param_1 + 0x5c) = piVar3;
  uVar2 = *(int *)(param_1 + 0x60) + 1;
  *(uint *)(param_1 + 0x60) = uVar2;
  if (uVar2 < 9) {
    NdisReleaseSpinLock(iVar4);
    FUN_c0571308(param_1);
  }
  else {
    piVar3 = *(int **)(param_1 + 0x58);
    *(int *)piVar3[1] = *piVar3;
    *(int *)(*piVar3 + 4) = piVar3[1];
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + -1;
    NdisReleaseSpinLock(iVar4);
    FUN_c0575954(param_1,(int)(piVar3 + -0xe));
  }
  NdisAcquireSpinLock(iVar4);
  if (*(int *)(param_1 + 0x50) != 0) {
    NdisSetEvent(param_1 + 0x4c);
  }
  NdisReleaseSpinLock(iVar4);
  return;
}



/* c0575c34 FUN_c0575c34 */

/* Boundary evidence: original MIPS .pdata c0575c34..c0575d07. Semantic name remains unreviewed. */

void FUN_c0575c34(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_20 [2];
  
  piVar3 = *(int **)(param_2 + 0x44);
  if (piVar3 != (int *)0x0) {
    NdisUnchainBufferAtFront(param_2,local_20);
    iVar2 = *piVar3;
    piVar1 = piVar3;
    while (iVar2 != 0) {
      piVar1 = (int *)*piVar1;
      iVar2 = *piVar1;
    }
    if (*(int *)(param_2 + 8) == 0) {
      *(int **)(param_2 + 8) = piVar3;
    }
    else {
      **(undefined4 **)(param_2 + 0xc) = piVar3;
    }
    *(int **)(param_2 + 0xc) = piVar1;
    *piVar1 = 0;
    *(undefined1 *)(param_2 + 0x1c) = 0;
    NdisFreeBuffer(local_20[0]);
  }
  if (param_3 == 0) {
    FUN_c0575b0c(param_1,param_2);
  }
  else {
    FUN_c0575954(param_1,param_2);
  }
  return;
}



/* c0575d08 FUN_c0575d08 */

/* Boundary evidence: original MIPS .pdata c0575d08..c0575ebf. Semantic name remains unreviewed. */

undefined4 FUN_c0575d08(int param_1,int param_2)

{
  int *piVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iStack_20;
  undefined1 auStack_1c [4];
  
  piVar1 = *(int **)(param_2 + 8);
  uVar6 = 0;
  if (piVar1 == (int *)0x0) {
    iVar3 = 0;
    uVar4 = 0;
    uVar5 = 0;
  }
  else {
    uVar4 = piVar1[2];
    iVar3 = piVar1[1];
    uVar5 = uVar4;
    while (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0) {
      uVar5 = piVar1[2] + uVar5;
    }
  }
  if (0xd < uVar4) {
    if (*(short *)(iVar3 + 0xc) == 0x81) {
      uVar4 = 0;
      if (*(uint *)(param_1 + 0x88) != 0) {
        psVar2 = (short *)(param_1 + 0x80);
        do {
          if (*psVar2 == *(short *)(iVar3 + 0x10)) {
LAB_c0575e20:
            if (*(int *)((uint)*(ushort *)(param_2 + 0x1e) + param_2 + 0x1c) == -0x3fffff66) {
              iVar3 = FUN_c05757a8(param_1,0,uVar5,&iStack_20);
              if (iVar3 == 0) {
                return 0;
              }
              NdisCopyFromPacketToPacket(iVar3,0,uVar5,param_2,0,auStack_1c);
              param_2 = iVar3;
            }
            else {
              uVar6 = 1;
            }
            FUN_c0575b0c(param_1,param_2);
            return uVar6;
          }
          uVar4 = uVar4 + 1;
          psVar2 = psVar2 + 1;
        } while (uVar4 < *(uint *)(param_1 + 0x88));
      }
    }
    else {
      uVar4 = 0;
      if (*(uint *)(param_1 + 0x88) != 0) {
        psVar2 = (short *)(param_1 + 0x80);
        do {
          if (*psVar2 == *(short *)(iVar3 + 0xc)) goto LAB_c0575e20;
          uVar4 = uVar4 + 1;
          psVar2 = psVar2 + 1;
        } while (uVar4 < *(uint *)(param_1 + 0x88));
      }
    }
  }
  return 0;
}



/* c0575ec0 FUN_c0575ec0 */

/* Boundary evidence: original MIPS .pdata c0575ec0..c0576163. Semantic name remains unreviewed. */

int FUN_c0575ec0(int param_1,undefined4 param_2,void *param_3,int param_4,void *param_5,
                size_t param_6,uint param_7)

{
  void *pvVar1;
  int iVar2;
  short *psVar3;
  int *piVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int local_30;
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20 [2];
  
  local_2c = (void *)0x0;
  local_30 = 0;
  if (param_4 == 0xe) {
    if (*(short *)((int)param_3 + 0xc) == 0x81) {
      uVar5 = 0;
      if (*(uint *)(param_1 + 0x88) != 0) {
        psVar3 = (short *)(param_1 + 0x80);
        do {
          if (*psVar3 == 0x81) {
LAB_c0575fa4:
            if (param_7 + 0xe < param_7) {
              return -0x3ffeffeb;
            }
            iVar2 = FUN_c05757a8(param_1,0,param_7 + 0xe,(int *)&local_2c);
            pvVar1 = local_2c;
            if (iVar2 == 0) {
              return 0x10003;
            }
            memcpy(local_2c,param_3,0xe);
            if (param_7 == param_6) {
              if ((*(uint *)(param_1 + 0x38) & 1) == 0) {
                puVar6 = (undefined1 *)((int)pvVar1 + 0xe);
                puVar7 = puVar6 + param_6;
                if (puVar6 < puVar7) {
                  iVar8 = (int)param_5 - (int)puVar6;
                  do {
                    *puVar6 = puVar6[iVar8];
                    puVar6 = puVar6 + 1;
                  } while (puVar6 < puVar7);
                }
              }
              else {
                memcpy((void *)((int)pvVar1 + 0xe),param_5,param_6);
              }
              FUN_c0575b0c(param_1,iVar2);
              return local_30;
            }
            NdisAllocateBuffer(&local_30,local_20,*(undefined4 *)(param_1 + 0x34),(int)pvVar1 + 0xe,
                               param_7);
            if (local_30 == 0) {
              NdisUnchainBufferAtFront(iVar2,&local_24);
              *(undefined4 *)(iVar2 + 0x44) = local_24;
              iVar8 = *local_20[0];
              piVar4 = local_20[0];
              while (iVar8 != 0) {
                piVar4 = (int *)*piVar4;
                iVar8 = *piVar4;
              }
              if (*(int *)(iVar2 + 8) == 0) {
                *(int **)(iVar2 + 8) = local_20[0];
              }
              else {
                **(undefined4 **)(iVar2 + 0xc) = local_20[0];
              }
              *(int **)(iVar2 + 0xc) = piVar4;
              *piVar4 = 0;
              *(undefined1 *)(iVar2 + 0x1c) = 0;
              local_30 = (**(code **)(*(int *)(param_1 + 0x24) + 0x44))
                                   (*(int *)(param_1 + 0x24),param_2,0,param_7,iVar2,&local_28);
            }
            else {
              local_28 = 0;
            }
            if (local_30 != 0x103) {
              FUN_c0575c34(param_1,iVar2,local_30);
              return local_30;
            }
            return 0x103;
          }
          uVar5 = uVar5 + 1;
          psVar3 = psVar3 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0x88));
      }
    }
    else {
      uVar5 = 0;
      if (*(uint *)(param_1 + 0x88) != 0) {
        psVar3 = (short *)(param_1 + 0x80);
        do {
          if (*psVar3 == *(short *)((int)param_3 + 0xc)) goto LAB_c0575fa4;
          uVar5 = uVar5 + 1;
          psVar3 = psVar3 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0x88));
      }
    }
  }
  return 0x10003;
}



/* c0576164 FUN_c0576164 */

/* Boundary evidence: original MIPS .pdata c0576164..c057618b. Semantic name remains unreviewed. */

void FUN_c0576164(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x3c) = param_3;
  NdisSetEvent(param_2 + 0x38);
  return;
}



/* c057625c entry */

/* Boundary evidence: original MIPS .pdata c057625c..c05762cf. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c05762d0();
    FUN_c0576620();
  }
  uVar1 = FUN_c0571e30(param_1,param_2);
  if (param_2 == 0) {
    FUN_c05765a8();
  }
  return uVar1;
}



/* c05762d0 FUN_c05762d0 */

/* Boundary evidence: original MIPS .pdata c05762d0..c0576343. Semantic name remains unreviewed. */

void FUN_c05762d0(void)

{
  uint uVar1;
  
  if ((DAT_c05770fc == 0) || (DAT_c05770fc == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c05770fc = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c05770fc == 0) {
      DAT_c05770fc = 0xb064;
    }
  }
  DAT_c0577100 = ~DAT_c05770fc;
  return;
}



/* c0576344 FUN_c0576344 */

/* Boundary evidence: original MIPS .pdata c0576344..c0576397. Semantic name remains unreviewed. */

void FUN_c0576344(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c05763c4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0576398 FUN_c0576398 */

/* Boundary evidence: original MIPS .pdata c0576398..c05763c3. Semantic name remains unreviewed. */

undefined4 FUN_c0576398(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0576344(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c05763c4 FUN_c05763c4 */

/* Boundary evidence: original MIPS .pdata c05763c4..c057640b. Semantic name remains unreviewed. */

void FUN_c05763c4(uint param_1)

{
  if ((param_1 == DAT_c05770fc) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c057640c FUN_c057640c */

/* Boundary evidence: original MIPS .pdata c057640c..c0576487. Semantic name remains unreviewed. */

void FUN_c057640c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0576344(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c0576488 FUN_c0576488 */

/* Boundary evidence: original MIPS .pdata c0576488..c05765a7. Semantic name remains unreviewed. */

void FUN_c0576488(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0577158 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c05771a4;
    if (DAT_c05771a4 != (undefined4 *)0x0) {
      while (DAT_c05771a0 = DAT_c05771a0 + -1, _Memory <= DAT_c05771a0) {
        if ((code *)*DAT_c05771a0 != (code *)0x0) {
          (*(code *)*DAT_c05771a0)();
          _Memory = DAT_c05771a4;
        }
      }
      free(_Memory);
      DAT_c05771a0 = (undefined4 *)0x0;
      DAT_c05771a4 = (undefined4 *)0x0;
    }
    FUN_c05765cc((undefined4 *)&DAT_c0571010,(undefined4 *)&DAT_c0571014);
  }
  FUN_c05765cc((undefined4 *)&DAT_c0571018,(undefined4 *)&DAT_c057101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c05771a8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c05765a8 FUN_c05765a8 */

/* Boundary evidence: original MIPS .pdata c05765a8..c05765cb. Semantic name remains unreviewed. */

void FUN_c05765a8(void)

{
  FUN_c0576488(0,0,1);
  return;
}



/* c05765cc FUN_c05765cc */

/* Boundary evidence: original MIPS .pdata c05765cc..c057661f. Semantic name remains unreviewed. */

void FUN_c05765cc(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0576620 FUN_c0576620 */

/* Boundary evidence: original MIPS .pdata c0576620..c057665b. Semantic name remains unreviewed. */

void FUN_c0576620(void)

{
  FUN_c05765cc((undefined4 *)&DAT_c0571008,(undefined4 *)&DAT_c057100c);
  FUN_c05765cc((undefined4 *)&DAT_c0571000,(undefined4 *)&DAT_c0571004);
  return;
}


