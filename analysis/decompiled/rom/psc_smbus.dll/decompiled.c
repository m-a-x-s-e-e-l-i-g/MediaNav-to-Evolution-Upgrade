/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c092158c FUN_c092158c */

/* Boundary evidence: original MIPS .pdata c092158c..c092171b. Semantic name remains unreviewed. */

undefined4 FUN_c092158c(int param_1)

{
  int iVar1;
  uint uVar2;
  wchar_t *pwVar3;
  
  iVar1 = MmMapIoSpace(0x10900000,0,0x114,0);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"Can not map System Control registers!\r\n");
  }
  else {
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfff11fff;
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | 0x40011c00;
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xd9ffffff;
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) | 0x18000000;
    MmUnmapIoSpace(iVar1,0x114);
  }
  WRITE_REGISTER_ULONG(param_1,5);
  WRITE_REGISTER_ULONG(param_1 + 4,3);
  iVar1 = 0x14;
  do {
    uVar2 = READ_REGISTER_ULONG(param_1 + 0x14);
    if ((uVar2 & 1) != 0) break;
    iVar1 = iVar1 + -1;
    StallExecution(100);
  } while (iVar1 != 0);
  if (iVar1 == 0) {
    pwVar3 = L"Failed waiting for SR\r\n";
  }
  else {
    WRITE_REGISTER_ULONG(param_1 + 0xc,0xffffffff);
    WRITE_REGISTER_ULONG(param_1 + 0x20,0xffffffff);
    WRITE_REGISTER_ULONG(param_1 + 8,0xfc000000);
    iVar1 = 0x32;
    do {
      uVar2 = READ_REGISTER_ULONG(param_1 + 0x14);
      if ((uVar2 & 2) != 0) break;
      StallExecution(1000);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (iVar1 != 0) {
      return 1;
    }
    pwVar3 = L"Failed waiting for DR\r\n";
  }
  NKDbgPrintfW(pwVar3);
  return 0;
}



/* c092171c FUN_c092171c */

/* Boundary evidence: original MIPS .pdata c092171c..c09217df. Semantic name remains unreviewed. */

bool FUN_c092171c(int param_1)

{
  DWORD DVar1;
  uint uVar2;
  DWORD DVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  DVar1 = GetTickCount();
  uVar4 = 0;
  puVar5 = (undefined4 *)(param_1 + 0x18);
  do {
    uVar2 = READ_REGISTER_ULONG(puVar5);
    if ((uVar2 & 0x10) != 0) break;
    DVar3 = GetTickCount();
    uVar4 = DVar3 - DVar1;
  } while (uVar4 < 3000);
  if (uVar4 < 0xbb9) {
    WRITE_REGISTER_ULONG(puVar5,0x10);
  }
  else {
    NKDbgPrintfW(L"SMB:: sts:%08x evnt:%08x pcr:%08x\r\n",*(undefined4 *)(param_1 + 0x14),*puVar5,
                 *(undefined4 *)(param_1 + 0x10));
  }
  return uVar4 < 0xbb9;
}



/* c09217e0 FUN_c09217e0 */

/* Boundary evidence: original MIPS .pdata c09217e0..c0921a3b. Semantic name remains unreviewed. */

bool FUN_c09217e0(int param_1,byte *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined3 extraout_var;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  iVar9 = *(int *)(param_1 + 4);
  if (*(uint *)(param_2 + 4) < 8) {
    iVar10 = iVar9 + 0x14;
    uVar6 = READ_REGISTER_ULONG(iVar10);
    while ((uVar6 & 0x10000030) != 0) {
      Sleep(1);
      uVar6 = READ_REGISTER_ULONG(iVar10);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    uVar6 = READ_REGISTER_ULONG(iVar10);
    if ((uVar6 & 0x200) == 0) {
      WRITE_REGISTER_ULONG(iVar9 + 0x10,4);
    }
    uVar6 = READ_REGISTER_ULONG(iVar10);
    if ((uVar6 & 0x1000) == 0) {
      WRITE_REGISTER_ULONG(iVar9 + 0x10,0x40);
    }
    iVar10 = iVar9 + 0x18;
    uVar7 = READ_REGISTER_ULONG(iVar10);
    WRITE_REGISTER_ULONG(iVar10,uVar7);
    iVar12 = iVar9 + 0x1c;
    WRITE_REGISTER_ULONG(iVar12,(uint)*param_2 << 1 | 1);
    uVar6 = *(uint *)(param_2 + 4);
    uVar11 = 0;
    if (uVar6 != 0) {
      do {
        uVar7 = 0x20000000;
        if (uVar11 != uVar6 - 1) {
          uVar7 = 0;
        }
        WRITE_REGISTER_ULONG(iVar12,uVar7);
        uVar6 = *(uint *)(param_2 + 4);
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar6);
    }
    WRITE_REGISTER_ULONG(iVar9 + 0x10,1);
    bVar4 = FUN_c092171c(iVar9);
    bVar4 = CONCAT31(extraout_var,bVar4) != 0;
    if (!bVar4) {
      NKDbgPrintfW(L"SMB ReadData: Timeout waiting for MASTER DONE\r\n");
    }
    uVar6 = READ_REGISTER_ULONG(iVar10);
    bVar1 = (uVar6 & 0x10000000) == 0;
    if (!bVar1) {
      WRITE_REGISTER_ULONG(iVar10);
      NKDbgPrintfW(L"SMB ReadData: Event for Arbitration Lost\r\n");
    }
    uVar6 = READ_REGISTER_ULONG(iVar10);
    bVar2 = (uVar6 & 0x20000000) == 0;
    if (!bVar2) {
      WRITE_REGISTER_ULONG(iVar10,0x20000000);
      NKDbgPrintfW(L"SMB ReadData: Event for Address NACK\r\n");
    }
    bVar3 = bVar2 && (bVar1 && bVar4);
    if ((bVar2 && (bVar1 && bVar4)) && (uVar6 = 0, *(int *)(param_2 + 4) != 0)) {
      do {
        uVar5 = READ_REGISTER_ULONG(iVar12);
        puVar8 = (undefined1 *)(uVar6 + param_3);
        uVar6 = uVar6 + 1;
        *puVar8 = uVar5;
      } while (uVar6 < *(uint *)(param_2 + 4));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}



/* c0921a3c FUN_c0921a3c */

/* Boundary evidence: original MIPS .pdata c0921a3c..c0921c93. Semantic name remains unreviewed. */

bool FUN_c0921a3c(int param_1,byte *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined3 extraout_var;
  bool bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  iVar8 = *(int *)(param_1 + 4);
  if (*(uint *)(param_2 + 4) < 8) {
    iVar7 = iVar8 + 0x14;
    uVar4 = READ_REGISTER_ULONG(iVar7);
    while ((uVar4 & 0x10000030) != 0) {
      Sleep(1);
      uVar4 = READ_REGISTER_ULONG(iVar7);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    uVar4 = READ_REGISTER_ULONG(iVar7);
    if ((uVar4 & 0x200) == 0) {
      WRITE_REGISTER_ULONG(iVar8 + 0x10,4);
    }
    uVar4 = READ_REGISTER_ULONG(iVar7);
    if ((uVar4 & 0x1000) == 0) {
      WRITE_REGISTER_ULONG(iVar8 + 0x10,0x40);
    }
    iVar7 = iVar8 + 0x18;
    uVar5 = READ_REGISTER_ULONG(iVar7);
    WRITE_REGISTER_ULONG(iVar7,uVar5);
    WRITE_REGISTER_ULONG(iVar8 + 0x1c,(uint)*param_2 << 1);
    uVar4 = *(uint *)(param_2 + 4);
    uVar9 = 0;
    if (uVar4 != 0) {
      do {
        if (uVar9 == uVar4 - 1) {
          uVar4 = param_2[uVar9 + 8] | 0x20000000;
        }
        else {
          uVar4 = (uint)param_2[uVar9 + 8];
        }
        WRITE_REGISTER_ULONG(iVar8 + 0x1c,uVar4);
        uVar4 = *(uint *)(param_2 + 4);
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar4);
    }
    WRITE_REGISTER_ULONG(iVar8 + 0x10,1);
    bVar3 = FUN_c092171c(iVar8);
    bVar3 = CONCAT31(extraout_var,bVar3) != 0;
    if (!bVar3) {
      NKDbgPrintfW(L"SMB WriteData: Timeout waiting for MASTER DONE\r\n");
    }
    uVar4 = READ_REGISTER_ULONG(iVar7);
    bVar1 = (uVar4 & 0x10000000) == 0;
    if (!bVar1) {
      WRITE_REGISTER_ULONG(iVar7);
      NKDbgPrintfW(L"SMB WriteData: Event for Arbitration Lost\r\n");
    }
    uVar4 = READ_REGISTER_ULONG(iVar7);
    bVar2 = (uVar4 & 0x20000000) == 0;
    if (!bVar2) {
      WRITE_REGISTER_ULONG(iVar7,0x20000000);
      NKDbgPrintfW(L"SMB WriteData: Event for Address NACK\r\n");
    }
    uVar4 = READ_REGISTER_ULONG(iVar7);
    bVar6 = (uVar4 & 0x40000000) == 0;
    if (!bVar6) {
      WRITE_REGISTER_ULONG(iVar7);
      NKDbgPrintfW(L"SMB WriteData: Event for Tx Data NACK\r\n");
    }
    bVar6 = bVar6 && (bVar2 && (bVar1 && bVar3));
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  else {
    bVar6 = false;
  }
  return bVar6;
}



/* c0921c94 FUN_c0921c94 */

/* Boundary evidence: original MIPS .pdata c0921c94..c0921f43. Semantic name remains unreviewed. */

bool FUN_c0921c94(int param_1,byte *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined3 extraout_var;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  iVar11 = *(int *)(param_1 + 4);
  if (*(uint *)(param_2 + 4) < 6) {
    iVar10 = iVar11 + 0x14;
    uVar7 = READ_REGISTER_ULONG(iVar10);
    while ((uVar7 & 0x10000030) != 0) {
      Sleep(1);
      uVar7 = READ_REGISTER_ULONG(iVar10);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    uVar7 = READ_REGISTER_ULONG(iVar10);
    if ((uVar7 & 0x200) == 0) {
      WRITE_REGISTER_ULONG(iVar11 + 0x10,4);
    }
    uVar7 = READ_REGISTER_ULONG(iVar10);
    if ((uVar7 & 0x1000) == 0) {
      WRITE_REGISTER_ULONG(iVar11 + 0x10,0x40);
    }
    iVar10 = iVar11 + 0x18;
    uVar8 = READ_REGISTER_ULONG(iVar10);
    WRITE_REGISTER_ULONG(iVar10,uVar8);
    iVar13 = iVar11 + 0x1c;
    WRITE_REGISTER_ULONG(iVar13,(uint)*param_2 << 1);
    WRITE_REGISTER_ULONG(iVar13,param_2[8] | 0x10000000);
    WRITE_REGISTER_ULONG(iVar13,(uint)*param_2 << 1 | 1);
    uVar7 = *(uint *)(param_2 + 4);
    uVar12 = 0;
    if (uVar7 != 0) {
      do {
        uVar8 = 0x20000000;
        if (uVar12 != uVar7 - 1) {
          uVar8 = 0;
        }
        WRITE_REGISTER_ULONG(iVar13,uVar8);
        uVar7 = *(uint *)(param_2 + 4);
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar7);
    }
    WRITE_REGISTER_ULONG(iVar11 + 0x10,1);
    bVar5 = FUN_c092171c(iVar11);
    bVar5 = CONCAT31(extraout_var,bVar5) != 0;
    if (!bVar5) {
      NKDbgPrintfW(L"SMB ReadRegData: Timeout waiting for MASTER DONE\r\n");
    }
    uVar7 = READ_REGISTER_ULONG(iVar10);
    bVar1 = (uVar7 & 0x10000000) == 0;
    if (!bVar1) {
      WRITE_REGISTER_ULONG(iVar10);
      NKDbgPrintfW(L"SMB ReadRegData: Event for Arbitration Lost\r\n");
    }
    uVar7 = READ_REGISTER_ULONG(iVar10);
    bVar2 = (uVar7 & 0x20000000) == 0;
    if (!bVar2) {
      WRITE_REGISTER_ULONG(iVar10,0x20000000);
      NKDbgPrintfW(L"SMB ReadRegData: Event for Address NACK\r\n");
    }
    uVar7 = READ_REGISTER_ULONG(iVar10);
    bVar3 = (uVar7 & 0x40000000) == 0;
    if (!bVar3) {
      WRITE_REGISTER_ULONG(iVar10);
      NKDbgPrintfW(L"SMB ReadRegData: Event for Tx Data NACK\r\n");
    }
    bVar4 = bVar3 && (bVar2 && (bVar1 && bVar5));
    if ((bVar3 && (bVar2 && (bVar1 && bVar5))) && (uVar7 = 0, *(int *)(param_2 + 4) != 0)) {
      do {
        uVar6 = READ_REGISTER_ULONG(iVar13);
        puVar9 = (undefined1 *)(uVar7 + param_3);
        uVar7 = uVar7 + 1;
        *puVar9 = uVar6;
      } while (uVar7 < *(uint *)(param_2 + 4));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}



/* c0921f44 DllMain */

undefined4 DllMain(void)

{
                    /* 0x1f44  1  DllMain */
  return 1;
}



/* c0921f4c SMB_Deinit */

/* Boundary evidence: original MIPS .pdata c0921f4c..c0921f93. Semantic name remains unreviewed. */

undefined4 SMB_Deinit(HLOCAL param_1)

{
                    /* 0x1f4c  3  SMB_Deinit */
  if (*(int *)((int)param_1 + 4) != 0) {
    MmUnmapIoSpace(*(int *)((int)param_1 + 4),0x24);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 8));
  LocalFree(param_1);
  return 1;
}



/* c0921f94 SMB_Init */

/* Boundary evidence: original MIPS .pdata c0921f94..c0922043. Semantic name remains unreviewed. */

HLOCAL SMB_Init(void)

{
  HLOCAL pvVar1;
  int iVar2;
  uint uVar3;
  
                    /* 0x1f94  5  SMB_Init */
  uVar3 = 0;
  pvVar1 = LocalAlloc(0x40,0x1c);
  if (pvVar1 != (HLOCAL)0x0) {
    NKDbgPrintfW(L"Initializing PSC%d for SMBUS operation\r\n",3);
    iVar2 = MmMapIoSpace(0x10a03000,0,0x24,0);
    if (iVar2 != 0) {
      *(int *)((int)pvVar1 + 4) = iVar2;
      InitializeCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 8));
      uVar3 = FUN_c092158c(iVar2);
      uVar3 = uVar3 & 0xff;
    }
  }
  if (uVar3 == 0) {
    SMB_Deinit(pvVar1);
    pvVar1 = (HLOCAL)0x0;
  }
  return pvVar1;
}



/* c0922044 SMB_Open */

int * SMB_Open(int *param_1)

{
                    /* 0x2044  6  SMB_Open */
  *param_1 = *param_1 + 1;
  return param_1;
}



/* c0922058 SMB_Close */

undefined4 SMB_Close(int *param_1)

{
                    /* 0x2058  2  SMB_Close */
  *param_1 = *param_1 + -1;
  return 1;
}



/* c092206c SMB_Read */

undefined4 SMB_Read(void)

{
                    /* 0x206c  9  SMB_Read
                       0x206c  11  SMB_Write */
  return 0;
}



/* c0922074 SMB_Seek */

/* Boundary evidence: original MIPS .pdata c0922074..c092209b. Semantic name remains unreviewed. */

undefined4 SMB_Seek(void)

{
                    /* 0x2074  10  SMB_Seek */
  SetLastError(0x78);
  return 0xffffffff;
}



/* c092209c SMB_IOControl */

/* Boundary evidence: original MIPS .pdata c092209c..c092213b. Semantic name remains unreviewed. */

bool SMB_IOControl(int param_1,int param_2,byte *param_3,undefined4 param_4,int param_5,
                  undefined4 param_6,undefined4 *param_7)

{
  bool bVar1;
  
                    /* 0x209c  4  SMB_IOControl */
  if (param_2 == -0x7fffe000) {
    bVar1 = FUN_c09217e0(param_1,param_3,param_5);
  }
  else {
    if (param_2 == -0x7fffdfff) {
      bVar1 = FUN_c0921a3c(param_1,param_3);
      *param_7 = 0;
      return bVar1;
    }
    if (param_2 != -0x7fffdffe) {
      SetLastError(0x78);
      return false;
    }
    bVar1 = FUN_c0921c94(param_1,param_3,param_5);
  }
  *param_7 = *(undefined4 *)(param_3 + 4);
  return bVar1;
}



/* c092213c SMB_PowerDown */

/* Boundary evidence: original MIPS .pdata c092213c..c092215f. Semantic name remains unreviewed. */

void SMB_PowerDown(int param_1)

{
                    /* 0x213c  7  SMB_PowerDown */
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 4) + 4,0);
  return;
}



/* c0922160 SMB_PowerUp */

/* Boundary evidence: original MIPS .pdata c0922160..c092217b. Semantic name remains unreviewed. */

void SMB_PowerUp(int param_1)

{
                    /* 0x2160  8  SMB_PowerUp */
  FUN_c092158c(*(int *)(param_1 + 4));
  return;
}



/* c092217c SMBus_ReadData */

/* Boundary evidence: original MIPS .pdata c092217c..c09221c7. Semantic name remains unreviewed. */

void SMBus_ReadData(HANDLE param_1,LPVOID param_2)

{
  DWORD aDStack_10 [2];
  
                    /* 0x217c  13  SMBus_ReadData */
  DeviceIoControl(param_1,0x80002000,param_2,0x208,(LPVOID)((int)param_2 + 8),
                  *(DWORD *)((int)param_2 + 4),aDStack_10,(LPOVERLAPPED)0x0);
  return;
}



/* c09221c8 SMBus_WriteData */

/* Boundary evidence: original MIPS .pdata c09221c8..c092220f. Semantic name remains unreviewed. */

void SMBus_WriteData(HANDLE param_1,LPVOID param_2)

{
  DWORD aDStack_10 [2];
  
                    /* 0x21c8  15  SMBus_WriteData */
  DeviceIoControl(param_1,0x80002001,param_2,*(int *)((int)param_2 + 4) + 0x207,(LPVOID)0x0,0,
                  aDStack_10,(LPOVERLAPPED)0x0);
  return;
}



/* c0922210 SMBus_ReadRegData */

/* Boundary evidence: original MIPS .pdata c0922210..c092225b. Semantic name remains unreviewed. */

void SMBus_ReadRegData(HANDLE param_1,LPVOID param_2)

{
  DWORD aDStack_10 [2];
  
                    /* 0x2210  14  SMBus_ReadRegData */
  DeviceIoControl(param_1,0x80002002,param_2,0x208,(LPVOID)((int)param_2 + 9),
                  *(DWORD *)((int)param_2 + 4),aDStack_10,(LPOVERLAPPED)0x0);
  return;
}



/* c092225c SMBus_Initialize */

/* Boundary evidence: original MIPS .pdata c092225c..c09222a3. Semantic name remains unreviewed. */

void SMBus_Initialize(void)

{
                    /* 0x225c  12  SMBus_Initialize */
  CreateFileW(L"SMB1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  return;
}



/* c0922364 FUN_c0922364 */

/* Boundary evidence: original MIPS .pdata c0922364..c092249f. Semantic name remains unreviewed. */

int FUN_c0922364(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c092307c != (code *)0x0) {
      iVar2 = (*DAT_c092307c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0922414;
    FUN_c09226bc();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain();
  }
LAB_c0922414:
  if (((param_2 == 0) && (FUN_c0922644(), iVar1 != 0)) && (DAT_c092307c != (code *)0x0)) {
    iVar1 = (*DAT_c092307c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c09224a0 FUN_c09224a0 */

/* Boundary evidence: original MIPS .pdata c09224a0..c09224cb. Semantic name remains unreviewed. */

void FUN_c09224a0(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c09224cc entry */

/* Boundary evidence: original MIPS .pdata c09224cc..c0922523. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c09226f8();
  }
  FUN_c0922364(param_1,param_2,param_3);
  return;
}



/* c0922524 FUN_c0922524 */

/* Boundary evidence: original MIPS .pdata c0922524..c0922643. Semantic name remains unreviewed. */

void FUN_c0922524(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c092306c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0923074;
    if (DAT_c0923074 != (undefined4 *)0x0) {
      while (DAT_c0923070 = DAT_c0923070 + -1, _Memory <= DAT_c0923070) {
        if ((code *)*DAT_c0923070 != (code *)0x0) {
          (*(code *)*DAT_c0923070)();
          _Memory = DAT_c0923074;
        }
      }
      free(_Memory);
      DAT_c0923070 = (undefined4 *)0x0;
      DAT_c0923074 = (undefined4 *)0x0;
    }
    FUN_c0922668((undefined4 *)&DAT_c0921010,(undefined4 *)&DAT_c0921014);
  }
  FUN_c0922668((undefined4 *)&DAT_c0921018,(undefined4 *)&DAT_c092101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0923078,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0922644 FUN_c0922644 */

/* Boundary evidence: original MIPS .pdata c0922644..c0922667. Semantic name remains unreviewed. */

void FUN_c0922644(void)

{
  FUN_c0922524(0,0,1);
  return;
}



/* c0922668 FUN_c0922668 */

/* Boundary evidence: original MIPS .pdata c0922668..c09226bb. Semantic name remains unreviewed. */

void FUN_c0922668(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c09226bc FUN_c09226bc */

/* Boundary evidence: original MIPS .pdata c09226bc..c09226f7. Semantic name remains unreviewed. */

void FUN_c09226bc(void)

{
  FUN_c0922668((undefined4 *)&DAT_c0921008,(undefined4 *)&DAT_c092100c);
  FUN_c0922668((undefined4 *)&DAT_c0921000,(undefined4 *)&DAT_c0921004);
  return;
}



/* c09226f8 FUN_c09226f8 */

/* Boundary evidence: original MIPS .pdata c09226f8..c092276b. Semantic name remains unreviewed. */

void FUN_c09226f8(void)

{
  uint uVar1;
  
  if ((DAT_c0923064 == 0) || (DAT_c0923064 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0923064 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0923064 == 0) {
      DAT_c0923064 = 0xb064;
    }
  }
  DAT_c0923068 = ~DAT_c0923064;
  return;
}


