/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c09e16ec PHM_Close */

/* Boundary evidence: original MIPS .pdata c09e16ec..c09e170f. Semantic name remains unreviewed. */

undefined4 PHM_Close(void)

{
                    /* 0x16ec  1  PHM_Close */
  NKDbgPrintfW(L"[SF][PHYMGR] PHM_Close \r\n");
  return 1;
}



/* c09e1710 PHM_Deinit */

/* Boundary evidence: original MIPS .pdata c09e1710..c09e1733. Semantic name remains unreviewed. */

undefined4 PHM_Deinit(void)

{
                    /* 0x1710  2  PHM_Deinit */
  NKDbgPrintfW(L"[SF][PHYMGR] Deinitialize PHMory for Application \r\n");
  return 1;
}



/* c09e1734 PHM_Init */

/* Boundary evidence: original MIPS .pdata c09e1734..c09e1757. Semantic name remains unreviewed. */

undefined4 PHM_Init(void)

{
                    /* 0x1734  4  PHM_Init */
  NKDbgPrintfW(L"[SF][PHYMGR] PHYMGR Driver is initialized. (Jun  2 2014 at 20:23:57)\r\n");
  return 1;
}



/* c09e1758 PHM_Open */

/* Boundary evidence: original MIPS .pdata c09e1758..c09e177b. Semantic name remains unreviewed. */

undefined4 PHM_Open(void)

{
                    /* 0x1758  5  PHM_Open */
  NKDbgPrintfW(L"[SF][PHYMGR] Opened driver for Application \r\n");
  return 1;
}



/* c09e177c PHM_PowerDown */

void PHM_PowerDown(void)

{
                    /* 0x177c  6  PHM_PowerDown
                       0x177c  7  PHM_PowerUp */
  return;
}



/* c09e1784 PHM_Read */

undefined4 PHM_Read(void)

{
                    /* 0x1784  8  PHM_Read
                       0x1784  9  PHM_Seek
                       0x1784  10  PHM_Write */
  return 1;
}



/* c09e178c FUN_c09e178c */

void FUN_c09e178c(uint param_1,int *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  uVar2 = 0xbfc00000;
  do {
    if (uVar2 <= param_1) break;
    uVar2 = uVar2 - 0x400000;
    iVar4 = iVar4 + -1;
  } while (-0x40400001 < (int)uVar2);
  iVar3 = 0;
  uVar2 = (iVar4 + 0x2ff) * 0x400000;
  iVar5 = 0;
  while( true ) {
    uVar1 = uVar2;
    if (iVar3 != 0) {
      uVar1 = iVar5 + uVar2;
    }
    if (param_1 < uVar1) break;
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x8000;
  }
  *param_2 = iVar4;
  *param_3 = iVar3 + -1;
  return;
}



/* c09e1800 FUN_c09e1800 */

/* Boundary evidence: original MIPS .pdata c09e1800..c09e1a6b. Semantic name remains unreviewed. */

void FUN_c09e1800(int param_1,undefined2 *param_2,uint param_3)

{
  uint local_18;
  undefined2 *local_14;
  
  if (param_1 == 0x1000) {
    *(undefined2 *)((int)param_2 * 0x400000 + -0x40400000) = 0xf0;
    SYNC(0);
  }
  else if (param_1 == 0x1001) {
    *(undefined2 *)((int)param_2 * 0x400000 + -0x403ff556) = 0xaa;
    SYNC(0);
    *(undefined2 *)((int)param_2 * 0x400000 + -0x403ffaac) = 0x55;
    SYNC(0);
  }
  else if (param_1 == 0x1003) {
    *(undefined2 *)((int)param_2 * 0x400000 + -0x403ff556) = 0x80;
    SYNC(0);
  }
  else if (param_1 == 0x1004) {
    local_14 = (undefined2 *)((int)param_2 * 0x400000 + -0x40400000);
    for (local_18 = 0; local_18 < param_3; local_18 = local_18 + 1) {
      local_14 = local_14 + 0x4000;
    }
    *local_14 = 0x30;
    SYNC(0);
  }
  else if (param_1 == 0x1007) {
    *(undefined2 *)((int)param_2 * 0x400000 + -0x403ff556) = 0xa0;
    SYNC(0);
  }
  else if (param_1 == 0x1015) {
    *param_2 = 0x25;
    SYNC(0);
    *param_2 = (short)param_3;
    SYNC(0);
  }
  else if (param_1 == 0x1016) {
    *param_2 = 0x29;
    SYNC(0);
  }
  return;
}



/* c09e1a6c FUN_c09e1a6c */

/* Boundary evidence: original MIPS .pdata c09e1a6c..c09e1adb. Semantic name remains unreviewed. */

undefined4 FUN_c09e1a6c(undefined2 *param_1,uint param_2)

{
  FUN_c09e1800(0x1001,param_1,0);
  FUN_c09e1800(0x1003,param_1,0);
  FUN_c09e1800(0x1001,param_1,0);
  FUN_c09e1800(0x1004,param_1,param_2);
  return 1;
}



/* c09e1adc FUN_c09e1adc */

/* Boundary evidence: original MIPS .pdata c09e1adc..c09e1bd7. Semantic name remains unreviewed. */

undefined4 FUN_c09e1adc(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  
  puVar4 = (undefined2 *)0x0;
  puVar3 = (ushort *)0xbfc00000;
  do {
    if (puVar3 <= param_1) break;
    puVar3 = puVar3 + -0x200000;
    puVar4 = (undefined2 *)((int)puVar4 + -1);
  } while (-0x40400001 < (int)puVar3);
  uVar2 = *param_1 ^ *param_1;
  uVar1 = *param_1;
  while( true ) {
    if ((uVar2 & 0x40) == 0) {
      return 100;
    }
    if ((uVar1 & 0x20) == 0x20) break;
    uVar2 = *param_1 ^ uVar1;
    uVar1 = *param_1;
  }
  uVar2 = *param_1 ^ *param_1;
  if ((uVar2 & 0x40) == 0) {
    return 100;
  }
  NKDbgPrintfW(L"FLASH: Fail 0x%08X status 0x%X 0x%08X 0x%08X\r\n",param_1,*param_1,*param_1,uVar2);
  FUN_c09e1800(0x1000,puVar4,0);
  return 0x66;
}



/* c09e1bd8 FUN_c09e1bd8 */

/* Boundary evidence: original MIPS .pdata c09e1bd8..c09e1c7b. Semantic name remains unreviewed. */

undefined4 FUN_c09e1bd8(undefined2 *param_1,uint param_2,int param_3)

{
  int iVar1;
  ushort *puVar2;
  
  puVar2 = (ushort *)(((int)param_1 + 0x2ff) * 0x400000);
  if (param_2 != 0) {
    puVar2 = puVar2 + param_2 * 0x4000;
  }
  FUN_c09e1a6c(param_1,param_2);
  if (param_3 == 0) {
    iVar1 = 100;
  }
  else {
    iVar1 = FUN_c09e1adc(puVar2);
    if (iVar1 == 100) {
      return 1;
    }
    NKDbgPrintfW(L"FLASH: Erase failed on Sector 0x%x",param_2);
  }
  if (iVar1 == 100) {
    return 1;
  }
  return 0;
}



/* c09e1c7c FUN_c09e1c7c */

/* Boundary evidence: original MIPS .pdata c09e1c7c..c09e1e8b. Semantic name remains unreviewed. */

bool FUN_c09e1c7c(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  ushort *puVar3;
  undefined2 *local_res0;
  undefined2 *local_30;
  uint local_2c;
  undefined2 *local_1c;
  
  for (local_1c = (undefined2 *)0x0;
      (-1 < (int)local_1c && (param_1 < (undefined2 *)((int)local_1c * 0x400000 + -0x40400000)));
      local_1c = (undefined2 *)((int)local_1c + -1)) {
  }
  if (((param_3 & 3) == 0) && (param_3 != 0)) {
    local_2c = param_3 >> 1;
    FUN_c09e1800(0x1001,local_1c,0);
    FUN_c09e1800(0x1015,param_1,local_2c - 1 | (local_2c - 1) * 0x10000);
    local_res0 = param_1;
    local_30 = param_2;
    while (local_2c != 0) {
      *local_res0 = *local_30;
      SYNC(0);
      local_res0 = local_res0 + 1;
      local_30 = local_30 + 1;
      local_2c = local_2c - 1;
    }
    puVar3 = local_res0 + -1;
    FUN_c09e1800(0x1016,puVar3,0);
    iVar2 = FUN_c09e1adc(puVar3);
    bVar1 = iVar2 != 0x66;
    if (!bVar1) {
      NKDbgPrintfW(L"Flash Write timeout at %X \r\n",puVar3);
    }
  }
  else {
    NKDbgPrintfW(L"Flash Write buffer requires a whole multiple of words\r\n");
    bVar1 = false;
  }
  return bVar1;
}



/* c09e1e8c FUN_c09e1e8c */

/* Boundary evidence: original MIPS .pdata c09e1e8c..c09e1fcb. Semantic name remains unreviewed. */

undefined4 FUN_c09e1e8c(ushort *param_1,uint param_2)

{
  int iVar1;
  ushort *local_res0;
  uint local_res4;
  int local_20;
  undefined2 *local_18;
  
  for (local_18 = (undefined2 *)0x0;
      (-1 < (int)local_18 && (param_1 < (ushort *)((int)local_18 * 0x400000 + -0x40400000)));
      local_18 = (undefined2 *)((int)local_18 + -1)) {
  }
  local_res0 = param_1;
  local_res4 = param_2;
  for (local_20 = 0; local_20 < 2; local_20 = local_20 + 1) {
    FUN_c09e1800(0x1001,local_18,0);
    FUN_c09e1800(0x1007,local_18,0);
    *local_res0 = (ushort)local_res4;
    SYNC(0);
    do {
      iVar1 = FUN_c09e1adc(local_res0);
    } while (iVar1 != 100);
    local_res0 = local_res0 + 1;
    local_res4 = local_res4 >> 0x10;
  }
  return 1;
}



/* c09e1fcc FUN_c09e1fcc */

/* Boundary evidence: original MIPS .pdata c09e1fcc..c09e2117. Semantic name remains unreviewed. */

undefined4 FUN_c09e1fcc(ushort *param_1,int param_2)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  uint local_30;
  undefined2 *local_2c;
  
  puVar5 = (ushort *)((int)param_1 + param_2 + -1);
  NKDbgPrintfW(L"[SF][PHYMGR] Erasing from 0x%x to 0x%x\r\n",param_1,puVar5);
  FUN_c09e1800(0x1000,(undefined2 *)0x0,0);
  uVar7 = (int)puVar5 - (int)param_1;
  uVar6 = 0;
  uVar4 = 1;
  do {
    FUN_c09e178c((uint)param_1,(int *)&local_2c,(int *)&local_30);
    puVar2 = local_2c;
    uVar1 = local_30;
    FUN_c09e1bd8(local_2c,local_30,1);
    uVar6 = uVar6 + 0x320000;
    param_1 = param_1 + 0x4000;
    if (uVar7 == 0) {
      trap(0x1c00);
    }
    NKDbgPrintfW(L"[SF][PHYMGR] erased :: addr %08x, bank %d, sector %d --> status %d%%\r\n",param_1
                 ,puVar2,uVar1,uVar6 / uVar7);
  } while (param_1 < puVar5);
  NKDbgPrintfW(L"[SF][PHYMGR] End of Erasing\r\n");
  if ((param_1 < (ushort *)0xc0000000) && (iVar3 = FUN_c09e1adc(param_1), iVar3 != 100)) {
    NKDbgPrintfW(L"[SF][PHYMGR] Erase status failure at 0x%X\r\n",param_1);
    uVar4 = 0;
  }
  return uVar4;
}



/* c09e2118 FUN_c09e2118 */

/* Boundary evidence: original MIPS .pdata c09e2118..c09e22fb. Semantic name remains unreviewed. */

undefined4 FUN_c09e2118(ushort *param_1,uint *param_2,uint param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  wchar_t *pwVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  int iVar6;
  
  iVar6 = 1;
  puVar4 = (undefined2 *)0x0;
  puVar5 = (ushort *)0xbfc00000;
  do {
    if (puVar5 <= param_1) break;
    puVar5 = puVar5 + -0x200000;
    puVar4 = (undefined2 *)((int)puVar4 + -1);
  } while (-0x40400001 < (int)puVar5);
  if ((param_3 & 3) != 0) {
    param_3 = (param_3 - (param_3 & 3)) + 4;
  }
  FUN_c09e1800(0x1000,puVar4,0);
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      if (*(char *)(uVar2 + (int)param_1) != -1) {
        NKDbgPrintfW(L"[SF][PHYMGR] Flash not erased at 0x%08X (%02X)\r\n",uVar2 + (int)param_1);
        goto LAB_c09e22e4;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_3);
  }
  while( true ) {
    if (param_3 == 0) goto LAB_c09e2200;
    if (iVar6 == 0) break;
    iVar6 = FUN_c09e1e8c(param_1,*param_2);
    if (iVar6 == 0) {
      pwVar3 = L"[SF][PHYMGR] Write failure at 0x%x(Flash_Write32)\r\n";
      goto LAB_c09e22dc;
    }
    param_3 = param_3 - 4;
    param_1 = param_1 + 2;
    param_2 = param_2 + 1;
  }
  iVar6 = 0;
  while (((param_3 != 0 && (((uint)param_1 & 0x1f) != 0)) && (iVar6 != 0))) {
    uVar2 = param_3;
    if (0x1f < param_3) {
      uVar2 = 0x20;
    }
    bVar1 = FUN_c09e1c7c(param_1,(undefined2 *)param_2,uVar2);
    iVar6 = CONCAT31(extraout_var,bVar1);
    if (iVar6 == 0) {
      pwVar3 = L"[SF][PHYMGR] Write failure at 0x%x(Flash_WriteBuffer)\r\n";
LAB_c09e22dc:
      NKDbgPrintfW(pwVar3,param_1);
LAB_c09e22e4:
      NKDbgPrintfW(L"Flash write Error\r\n");
      return 0;
    }
    param_3 = param_3 - uVar2;
    param_1 = (ushort *)(uVar2 + (int)param_1);
    param_2 = (uint *)((uVar2 & 0xfffffffc) + (int)param_2);
  }
LAB_c09e2200:
  if (((uint)param_1 & 0xffff) == 0) {
    NKDbgPrintfW(L"[SF][PHYMGR] written:: addr 0x%08x, size 0x%x\r\n",param_1,param_3);
  }
  return 1;
}



/* c09e22fc FUN_c09e22fc */

/* Boundary evidence: original MIPS .pdata c09e22fc..c09e239b. Semantic name remains unreviewed. */

undefined4 FUN_c09e22fc(undefined4 *param_1,uint param_2,int param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined2 *)0x0;
  uVar2 = 0xbfc00000;
  do {
    if (uVar2 <= param_2) break;
    uVar2 = uVar2 - 0x400000;
    puVar1 = (undefined2 *)((int)puVar1 + -1);
  } while (-0x40400001 < (int)uVar2);
  FUN_c09e1800(0x1000,puVar1,0);
  if (param_3 != 0) {
    puVar3 = param_1;
    do {
      param_3 = param_3 + -1;
      *puVar3 = *(undefined4 *)((param_2 - (int)param_1) + (int)puVar3);
      puVar3 = puVar3 + 1;
    } while (param_3 != 0);
  }
  return 1;
}



/* c09e239c PHM_IOControl */

/* Boundary evidence: original MIPS .pdata c09e239c..c09e244b. Semantic name remains unreviewed. */

undefined4 PHM_IOControl(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  
                    /* 0x239c  3  PHM_IOControl */
  if (param_2 == 0) {
    iVar3 = param_3[2];
    puVar2 = (ushort *)param_3[1];
  }
  else {
    if (param_2 == 1) {
      uVar1 = FUN_c09e2118((ushort *)param_3[1],(uint *)*param_3,param_3[2]);
      return uVar1;
    }
    if (param_2 == 2) {
      uVar1 = FUN_c09e22fc((undefined4 *)*param_3,param_3[1],param_3[2]);
      return uVar1;
    }
    if (param_2 != 3) {
      SetLastError(0x78);
      return 0;
    }
    NKDbgPrintfW(L"[SF][PHYMGR] delete touch calibration data in NOR\r\n");
    iVar3 = 0x10000;
    puVar2 = (ushort *)0xbfc00000;
  }
  uVar1 = FUN_c09e1fcc(puVar2,iVar3);
  return uVar1;
}



/* c09e245c FUN_c09e245c */

/* Boundary evidence: original MIPS .pdata c09e245c..c09e2487. Semantic name remains unreviewed. */

undefined4 FUN_c09e245c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c09e2488 FUN_c09e2488 */

/* Boundary evidence: original MIPS .pdata c09e2488..c09e25c3. Semantic name remains unreviewed. */

int FUN_c09e2488(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c09e3048 != (code *)0x0) {
      iVar2 = (*DAT_c09e3048)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c09e2538;
    FUN_c09e27e0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c09e245c(param_1,param_2);
  }
LAB_c09e2538:
  if (((param_2 == 0) && (FUN_c09e2768(), iVar1 != 0)) && (DAT_c09e3048 != (code *)0x0)) {
    iVar1 = (*DAT_c09e3048)(param_1,0,param_3);
  }
  return iVar1;
}



/* c09e25c4 FUN_c09e25c4 */

/* Boundary evidence: original MIPS .pdata c09e25c4..c09e25ef. Semantic name remains unreviewed. */

void FUN_c09e25c4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c09e25f0 entry */

/* Boundary evidence: original MIPS .pdata c09e25f0..c09e2647. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c09e281c();
  }
  FUN_c09e2488(param_1,param_2,param_3);
  return;
}



/* c09e2648 FUN_c09e2648 */

/* Boundary evidence: original MIPS .pdata c09e2648..c09e2767. Semantic name remains unreviewed. */

void FUN_c09e2648(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c09e3038 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c09e3040;
    if (DAT_c09e3040 != (undefined4 *)0x0) {
      while (DAT_c09e303c = DAT_c09e303c + -1, _Memory <= DAT_c09e303c) {
        if ((code *)*DAT_c09e303c != (code *)0x0) {
          (*(code *)*DAT_c09e303c)();
          _Memory = DAT_c09e3040;
        }
      }
      free(_Memory);
      DAT_c09e303c = (undefined4 *)0x0;
      DAT_c09e3040 = (undefined4 *)0x0;
    }
    FUN_c09e278c((undefined4 *)&DAT_c09e1010,(undefined4 *)&DAT_c09e1014);
  }
  FUN_c09e278c((undefined4 *)&DAT_c09e1018,(undefined4 *)&DAT_c09e101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c09e3044,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c09e2768 FUN_c09e2768 */

/* Boundary evidence: original MIPS .pdata c09e2768..c09e278b. Semantic name remains unreviewed. */

void FUN_c09e2768(void)

{
  FUN_c09e2648(0,0,1);
  return;
}



/* c09e278c FUN_c09e278c */

/* Boundary evidence: original MIPS .pdata c09e278c..c09e27df. Semantic name remains unreviewed. */

void FUN_c09e278c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c09e27e0 FUN_c09e27e0 */

/* Boundary evidence: original MIPS .pdata c09e27e0..c09e281b. Semantic name remains unreviewed. */

void FUN_c09e27e0(void)

{
  FUN_c09e278c((undefined4 *)&DAT_c09e1008,(undefined4 *)&DAT_c09e100c);
  FUN_c09e278c((undefined4 *)&DAT_c09e1000,(undefined4 *)&DAT_c09e1004);
  return;
}



/* c09e281c FUN_c09e281c */

/* Boundary evidence: original MIPS .pdata c09e281c..c09e288f. Semantic name remains unreviewed. */

void FUN_c09e281c(void)

{
  uint uVar1;
  
  if ((DAT_c09e302c == 0) || (DAT_c09e302c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c09e302c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c09e302c == 0) {
      DAT_c09e302c = 0xb064;
    }
  }
  DAT_c09e3030 = ~DAT_c09e302c;
  return;
}


