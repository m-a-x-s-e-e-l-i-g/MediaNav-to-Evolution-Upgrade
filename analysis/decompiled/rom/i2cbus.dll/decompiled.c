/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c093104c entry */

undefined4 entry(void)

{
  return 1;
}



/* c0931054 I2C_Init */

/* Boundary evidence: original MIPS .pdata c0931054..c093109f. Semantic name remains unreviewed. */

HLOCAL I2C_Init(void)

{
  HLOCAL pvVar1;
  
                    /* 0x1054  4  I2C_Init */
  pvVar1 = LocalAlloc(0x40,8);
  if (pvVar1 == (HLOCAL)0x0) {
    pvVar1 = (HLOCAL)0x0;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
  }
  return pvVar1;
}



/* c09310a0 I2C_Deinit */

/* Boundary evidence: original MIPS .pdata c09310a0..c09310d7. Semantic name remains unreviewed. */

undefined4 I2C_Deinit(HLOCAL param_1)

{
                    /* 0x10a0  2  I2C_Deinit */
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
  LocalFree(param_1);
  return 1;
}



/* c09310d8 I2C_Open */

int * I2C_Open(int *param_1)

{
                    /* 0x10d8  5  I2C_Open */
  *param_1 = *param_1 + 1;
  return param_1;
}



/* c09310ec I2C_Close */

undefined4 I2C_Close(int *param_1)

{
                    /* 0x10ec  1  I2C_Close */
  *param_1 = *param_1 + -1;
  return 1;
}



/* c0931100 I2C_Read */

undefined4 I2C_Read(void)

{
                    /* 0x1100  8  I2C_Read
                       0x1100  10  I2C_Write */
  return 0;
}



/* c0931108 I2C_Seek */

undefined4 I2C_Seek(void)

{
                    /* 0x1108  9  I2C_Seek */
  return 0xffffffff;
}



/* c0931110 I2C_PowerDown */

void I2C_PowerDown(void)

{
                    /* 0x1110  6  I2C_PowerDown
                       0x1110  7  I2C_PowerUp */
  return;
}



/* c0931118 FUN_c0931118 */

/* Boundary evidence: original MIPS .pdata c0931118..c093119f. Semantic name remains unreviewed. */

void FUN_c0931118(void)

{
  *DAT_c0932040 = 0x200000;
  OALStallExecution(0xf);
  *DAT_c0932040 = 0x100000;
  OALStallExecution(0xf);
  *DAT_c0932044 = 0x200000;
  OALStallExecution(0xf);
  *DAT_c0932044 = 0x100000;
  OALStallExecution(0xf);
  *(undefined4 *)(DAT_c093203c + 0x54) = 0;
  return;
}



/* c09311a0 FUN_c09311a0 */

/* Boundary evidence: original MIPS .pdata c09311a0..c0931233. Semantic name remains unreviewed. */

void FUN_c09311a0(void)

{
  Sleep(1);
  *DAT_c0932044 = 0x200000;
  OALStallExecution(0xf);
  *DAT_c0932040 = 0x100000;
  OALStallExecution(0xf);
  *DAT_c0932040 = 0x200000;
  OALStallExecution(0xf);
  *(undefined4 *)(DAT_c093203c + 0x54) = 0;
  Sleep(1);
  return;
}



/* c0931234 FUN_c0931234 */

/* Boundary evidence: original MIPS .pdata c0931234..c093130b. Semantic name remains unreviewed. */

void FUN_c0931234(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0x80;
  do {
    if ((param_1 & uVar1) == 0) {
      *DAT_c0932044 = 0x200000;
    }
    else {
      *DAT_c0932040 = 0x200000;
    }
    OALStallExecution(0xf);
    *DAT_c0932040 = 0x100000;
    OALStallExecution(0xf);
    OALStallExecution(0xf);
    *DAT_c0932044 = 0x100000;
    OALStallExecution(0xf);
    uVar1 = uVar1 >> 1;
  } while (uVar1 != 0);
  *(undefined4 *)(DAT_c093203c + 0x54) = 0;
  return;
}



/* c093130c FUN_c093130c */

/* Boundary evidence: original MIPS .pdata c093130c..c09313a7. Semantic name remains unreviewed. */

bool FUN_c093130c(void)

{
  uint uVar1;
  
  OALStallExecution(0xf);
  *DAT_c0932040 = 0x100000;
  OALStallExecution(0xf);
  uVar1 = *DAT_c0932040;
  OALStallExecution(0xf);
  *DAT_c0932044 = 0x100000;
  OALStallExecution(0xf);
  return (uVar1 & 0x200000) == 0;
}



/* c09313a8 FUN_c09313a8 */

/* Boundary evidence: original MIPS .pdata c09313a8..c0931463. Semantic name remains unreviewed. */

byte FUN_c09313a8(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  iVar2 = 8;
  do {
    OALStallExecution(0xf);
    *DAT_c0932040 = 0x100000;
    OALStallExecution(0xf);
    bVar1 = bVar1 << 1 | (*DAT_c0932040 & 0x200000) != 0;
    OALStallExecution(0xf);
    *DAT_c0932044 = 0x100000;
    OALStallExecution(0xf);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return bVar1;
}



/* c0931464 FUN_c0931464 */

/* Boundary evidence: original MIPS .pdata c0931464..c093157f. Semantic name remains unreviewed. */

undefined4 FUN_c0931464(undefined4 param_1,uint param_2,uint param_3,byte *param_4,uint param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_5 == 0) {
    return 1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
  FUN_c0931118();
  FUN_c0931234((param_2 & 0x7f) << 1);
  bVar1 = FUN_c093130c();
  if (CONCAT31(extraout_var,bVar1) == 0) {
LAB_c09314d4:
    FUN_c09311a0();
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
    uVar2 = 0;
  }
  else {
    if (param_3 != 0xff) {
      FUN_c0931234(param_3);
      bVar1 = FUN_c093130c();
      if (CONCAT31(extraout_var_00,bVar1) == 0) goto LAB_c09314d4;
    }
    uVar3 = 0;
    if (param_5 != 0) {
      do {
        FUN_c0931234((uint)*param_4);
        param_4 = param_4 + 1;
        bVar1 = FUN_c093130c();
        if (CONCAT31(extraout_var_01,bVar1) == 0) {
          uVar2 = 0;
          goto LAB_c0931544;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_5);
    }
    uVar2 = 1;
LAB_c0931544:
    FUN_c09311a0();
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
  }
  return uVar2;
}



/* c0931580 FUN_c0931580 */

/* Boundary evidence: original MIPS .pdata c0931580..c093174f. Semantic name remains unreviewed. */

undefined4 FUN_c0931580(undefined4 param_1,int param_2,uint param_3,byte *param_4,uint param_5)

{
  bool bVar1;
  byte bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 1;
  if (param_5 == 0) {
    return 1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
  FUN_c0931118();
  FUN_c0931234(param_2 << 1 & 0xff);
  bVar1 = FUN_c093130c();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_c0931234(param_3);
    bVar1 = FUN_c093130c();
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      FUN_c09311a0();
      FUN_c0931118();
      FUN_c0931234(param_2 << 1 & 0xffU | 1);
      bVar1 = FUN_c093130c();
      if (CONCAT31(extraout_var_01,bVar1) != 0) {
        uVar4 = 1;
        do {
          bVar2 = FUN_c09313a8();
          *param_4 = bVar2;
          param_4 = param_4 + 1;
          if (uVar4 == param_5) {
            *DAT_c0932040 = 0x200000;
            OALStallExecution(0xf);
            *DAT_c0932040 = 0x100000;
            OALStallExecution(0xf);
            OALStallExecution(0xf);
            *DAT_c0932044 = 0x100000;
            OALStallExecution(0xf);
            *(undefined4 *)(DAT_c093203c + 0x54) = 0;
          }
          else {
            *DAT_c0932044 = 0x200000;
            OALStallExecution(0xf);
            *DAT_c0932040 = 0x100000;
            OALStallExecution(0xf);
            OALStallExecution(0xf);
            *DAT_c0932044 = 0x100000;
            OALStallExecution(0xf);
            *(undefined4 *)(DAT_c093203c + 0x54) = 0;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 <= param_5);
        goto LAB_c093170c;
      }
    }
  }
  uVar3 = 0;
LAB_c093170c:
  FUN_c09311a0();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
  return uVar3;
}



/* c0931750 IICOpen */

/* Boundary evidence: original MIPS .pdata c0931750..c0931797. Semantic name remains unreviewed. */

void IICOpen(void)

{
                    /* 0x1750  12  IICOpen */
  CreateFileW(L"I2C1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  return;
}



/* c0931798 IICClose */

/* Boundary evidence: original MIPS .pdata c0931798..c09317bb. Semantic name remains unreviewed. */

void IICClose(HANDLE param_1)

{
                    /* 0x1798  11  IICClose */
  CloseHandle(param_1);
  return;
}



/* c09317bc IICWriteData */

/* Boundary evidence: original MIPS .pdata c09317bc..c093180f. Semantic name remains unreviewed. */

void IICWriteData(HANDLE param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  DWORD aDStack_20 [2];
  undefined1 local_18;
  undefined1 local_17;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* 0x17bc  14  IICWriteData */
  local_10 = param_5;
  local_18 = param_2;
  local_17 = param_3;
  local_14 = param_4;
  DeviceIoControl(param_1,2,&local_18,0xc,(LPVOID)0x0,0,aDStack_20,(LPOVERLAPPED)0x0);
  return;
}



/* c0931810 IICReadData */

/* Boundary evidence: original MIPS .pdata c0931810..c093186b. Semantic name remains unreviewed. */

void IICReadData(HANDLE param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                undefined4 param_5)

{
  DWORD aDStack_20 [2];
  undefined1 local_18;
  undefined1 local_17;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* 0x1810  13  IICReadData */
  local_10 = param_5;
  local_18 = param_2;
  local_17 = param_3;
  local_14 = param_4;
  DeviceIoControl(param_1,1,(LPVOID)0x0,0,&local_18,0xc,aDStack_20,(LPOVERLAPPED)0x0);
  return;
}



/* c093186c I2C_IOControl */

/* Boundary evidence: original MIPS .pdata c093186c..c0931993. Semantic name remains unreviewed. */

undefined4 I2C_IOControl(undefined4 param_1,int param_2,byte *param_3,int param_4,byte *param_5)

{
  int iVar1;
  
                    /* 0x186c  3  I2C_IOControl */
  if (param_2 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
    *DAT_c0932040 = 0x100000;
    OALStallExecution(0xf);
    *DAT_c0932040 = 0x200000;
    OALStallExecution(0xf);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0932050);
    return 1;
  }
  if (param_2 == 1) {
    if (param_5 == (byte *)0x0) {
      return 0;
    }
    iVar1 = FUN_c0931580(param_1,(uint)*param_5,(uint)param_5[1],*(byte **)(param_5 + 4),
                         *(uint *)(param_5 + 8));
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 4) {
        SetLastError(0x57);
        return 0;
      }
      return 1;
    }
    if (param_3 == (byte *)0x0) {
      return 0;
    }
    if (param_4 != 0xc) {
      return 0;
    }
    iVar1 = FUN_c0931464(param_1,(uint)*param_3,(uint)param_3[1],*(byte **)(param_3 + 4),
                         *(uint *)(param_3 + 8));
  }
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}



/* c0931a04 FUN_c0931a04 */

/* Boundary evidence: original MIPS .pdata c0931a04..c0931a4b. Semantic name remains unreviewed. */

void FUN_c0931a04(uint param_1)

{
  if ((param_1 == DAT_c0932048) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0xc0931a54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __report_gsfailure();
  return;
}


