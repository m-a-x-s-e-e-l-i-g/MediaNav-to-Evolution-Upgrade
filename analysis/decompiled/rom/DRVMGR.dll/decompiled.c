/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c09a13b4 FUN_c09a13b4 */

undefined4 FUN_c09a13b4(void)

{
  return 1;
}



/* c09a13bc MGR_Deinit */

/* Boundary evidence: original MIPS .pdata c09a13bc..c09a13ef. Semantic name remains unreviewed. */

undefined4 MGR_Deinit(HLOCAL param_1)

{
                    /* 0x13bc  2  MGR_Deinit */
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 4));
  LocalFree(param_1);
  return 1;
}



/* c09a13f0 FUN_c09a13f0 */

/* Boundary evidence: original MIPS .pdata c09a13f0..c09a14cf. Semantic name remains unreviewed. */

void FUN_c09a13f0(void)

{
  GPINTR_SetPinConfiguration(0x27,2);
  Sleep(5);
  GPINTR_SetPinConfiguration(0x27,3);
  GPINTR_SetPinConfiguration(0xe,2);
  GPINTR_SetPinConfiguration(0x3e,2);
  Sleep(0x33);
  GPINTR_SetPinConfiguration(0x3e,3);
  GPINTR_SetPinConfiguration(0x3f,2);
  Sleep(1);
  GPINTR_SetPinConfiguration(0x3f,3);
  Sleep(0x1e);
  GPINTR_SetPinConfiguration(0x28,2);
  Sleep(1);
  GPINTR_SetPinConfiguration(0x28,3);
  GPINTR_SetPinConfiguration(0x41,0);
  GPINTR_SetPinConfiguration(0x45,0);
  return;
}



/* c09a14d0 FUN_c09a14d0 */

/* Boundary evidence: original MIPS .pdata c09a14d0..c09a165f. Semantic name remains unreviewed. */

void FUN_c09a14d0(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 == 0xe) {
    GPINTR_SetPinConfiguration(0xe,2);
    Sleep(5);
    GPINTR_SetPinConfiguration(0xe,3);
    Sleep(1);
    GPINTR_SetPinConfiguration(0xe,2);
    pwVar1 = L"[DRVMGR] DAB reset\r\n";
  }
  else if (param_1 == 0x16) {
    GPINTR_SetPinConfiguration(0x16,3);
    Sleep(5);
    GPINTR_SetPinConfiguration(0x16,2);
    Sleep(10);
    GPINTR_SetPinConfiguration(0x16,3);
    pwVar1 = L"[DRVMGR] BT reset\r\n";
  }
  else if (param_1 == 0x3e) {
    GPINTR_SetPinConfiguration(0x3e,3);
    Sleep(5);
    GPINTR_SetPinConfiguration(0x3e,2);
    Sleep(0x33);
    GPINTR_SetPinConfiguration(0x3e,3);
    pwVar1 = L"[DRVMGR] CIM reset\r\n";
  }
  else {
    if (param_1 != 0x3f) {
      return;
    }
    GPINTR_SetPinConfiguration(0x3f,3);
    Sleep(5);
    GPINTR_SetPinConfiguration(0x3f,2);
    Sleep(1);
    GPINTR_SetPinConfiguration(0x3f,3);
    Sleep(0x1e);
    pwVar1 = L"[DRVMGR] CP reset\r\n";
  }
  NKDbgPrintfW(pwVar1);
  return;
}



/* c09a1660 FUN_c09a1660 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c09a1660..c09a16ff. Semantic name remains unreviewed. */

void FUN_c09a1660(void)

{
  _DAT_b40210c8 = 7;
  _DAT_b402102c = _DAT_b402102c & 0xfffffffd;
  _DAT_b4021004 = 7;
  Sleep(0x19);
  if ((_DAT_b40210c4 & 0x10) != 0) {
    _DAT_b40210c4 = _DAT_b40210c4 | 0x10;
  }
  _DAT_b40210c8 = _DAT_b40210c8 | 0x18;
  return;
}



/* c09a1700 MGR_Init */

/* Boundary evidence: original MIPS .pdata c09a1700..c09a1783. Semantic name remains unreviewed. */

HLOCAL MGR_Init(void)

{
  HLOCAL pvVar1;
  
                    /* 0x1700  4  MGR_Init */
  pvVar1 = LocalAlloc(0x40,0x18);
  if (pvVar1 == (HLOCAL)0x0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)0x4);
    LocalFree((HLOCAL)0x0);
    pvVar1 = (HLOCAL)0x0;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)((int)pvVar1 + 4));
    FUN_c09a13f0();
    FUN_c09a14d0(0x16);
    NKDbgPrintfW(L"[DRVMGR] Driver Manager is initialized. (Nov 28 2014 at 11:54:57)\r\n");
  }
  return pvVar1;
}



/* c09a1784 MGR_Open */

int * MGR_Open(int *param_1)

{
                    /* 0x1784  5  MGR_Open */
  *param_1 = *param_1 + 1;
  return param_1;
}



/* c09a1798 MGR_Close */

undefined4 MGR_Close(int *param_1)

{
                    /* 0x1798  1  MGR_Close */
  *param_1 = *param_1 + -1;
  return 1;
}



/* c09a17ac FUN_c09a17ac */

undefined4 FUN_c09a17ac(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10a00000;
  if (param_1 != 0) {
    if (param_1 == 1) {
      uVar1 = 0x10a01000;
    }
    else if (param_1 == 2) {
      uVar1 = 0x10a02000;
    }
    else if (param_1 == 3) {
      uVar1 = 0x10a03000;
    }
  }
  return uVar1;
}



/* c09a17f4 FUN_c09a17f4 */

/* Boundary evidence: original MIPS .pdata c09a17f4..c09a1843. Semantic name remains unreviewed. */

void FUN_c09a17f4(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)MmMapIoSpace(0x14004000,0,0xd4,0);
  if (puVar1 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
  }
  *puVar1 = *puVar1 | 1;
  MmUnmapIoSpace(puVar1,0xd4);
  return;
}



/* c09a1844 FUN_c09a1844 */

/* Boundary evidence: original MIPS .pdata c09a1844..c09a189b. Semantic name remains unreviewed. */

void FUN_c09a1844(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)MmMapIoSpace(0x14004000,0,0xd4,0);
  if (puVar1 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
  }
  *puVar1 = *puVar1 & 0xfffffffe;
  MmUnmapIoSpace(puVar1,0xd4);
  return;
}



/* c09a189c FUN_c09a189c */

/* Boundary evidence: original MIPS .pdata c09a189c..c09a18ef. Semantic name remains unreviewed. */

void FUN_c09a189c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_c09a17ac(param_1);
  iVar2 = MmMapIoSpace(uVar1,0,0x20,0);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) | 3;
  MmUnmapIoSpace(iVar2,0x20);
  return;
}



/* c09a18f0 FUN_c09a18f0 */

/* Boundary evidence: original MIPS .pdata c09a18f0..c09a194b. Semantic name remains unreviewed. */

void FUN_c09a18f0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_c09a17ac(param_1);
  iVar2 = MmMapIoSpace(uVar1,0,0x20,0);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xfffffffc;
  MmUnmapIoSpace(iVar2,0x20);
  return;
}



/* c09a194c MGR_IOControl */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c09a194c..c09a1d2f. Semantic name remains unreviewed. */

undefined4 MGR_IOControl(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined4 *in_stack_00000018;
  uint local_18 [2];
  
                    /* 0x194c  3  MGR_IOControl */
  local_18[0] = 0;
  uVar5 = 1;
  switch(param_2) {
  case 0:
    FUN_c09a14d0((uint)*param_3);
    break;
  case 1:
    GPINTR_GetPinState(*param_3,local_18);
    uVar2 = (uint)*param_3;
    if (uVar2 < 0x20) {
      if ((1 << (uVar2 & 0x1f) & local_18[0]) == 0) goto LAB_c09a1a34;
LAB_c09a1a74:
      *in_stack_00000018 = 0xff;
    }
    else {
      if (uVar2 < 0x40) {
        uVar2 = uVar2 - 0x20;
      }
      else {
        uVar2 = uVar2 - 0x40;
      }
      if ((1 << (uVar2 & 0x1f) & local_18[0]) != 0) goto LAB_c09a1a74;
LAB_c09a1a34:
      *in_stack_00000018 = 0;
    }
    NKDbgPrintfW(L"[DRVMGR] read GPIO%d into %d\r\n",*param_3,*in_stack_00000018);
    break;
  case 2:
    if (param_3[1] == 0) {
      GPINTR_SetPinConfiguration(*param_3,2);
      bVar1 = *param_3;
      pwVar4 = L"[DRVMGR] set GPIO%d into LOW\r\n";
    }
    else {
      GPINTR_SetPinConfiguration(*param_3,3);
      bVar1 = *param_3;
      pwVar4 = L"[DRVMGR] set GPIO%d into HIGH\r\n";
    }
    NKDbgPrintfW(pwVar4,bVar1);
    break;
  case 3:
    if (*param_3 == 0) goto switchD_c09a1988_default;
    FUN_c09a1660();
    pwVar4 = L"[DRVMGR] enable USB phy\r\n";
    goto LAB_c09a1b80;
  case 4:
    if (*param_3 == 0) {
      _DAT_b4020010 = 2;
      pwVar4 = L"[DRVMGR] disable USB test mode\r\n";
    }
    else {
      _DAT_b402101c = 0xf0000;
      _DAT_b4021004 = 7;
      _DAT_b4021000 = 2;
      _DAT_b4020054 = 0x43000;
      pwVar4 = L"[DRVMGR] enable USB test mode\r\n";
      _DAT_b4020058 = 0x43000;
    }
    goto LAB_c09a1b80;
  case 5:
    GPINTR_SetPinConfiguration(0x44,2);
    Sleep(0x33);
    GPINTR_SetPinConfiguration(0x2a,2);
    Sleep(0x33);
    Sleep(0x33);
    GPINTR_SetPinConfiguration(0x2a,3);
    Sleep(0x33);
    GPINTR_SetPinConfiguration(0x44,3);
    pwVar4 = L"[DRVMGR] start xm\r\n";
    goto LAB_c09a1b80;
  case 6:
    GPINTR_SetPinConfiguration(0x44,2);
    Sleep(0x33);
    GPINTR_SetPinConfiguration(0x2a,2);
    Sleep(0x33);
    pwVar4 = L"[DRVMGR] stop xm\r\n";
    goto LAB_c09a1b80;
  case 7:
    iVar3 = 0;
    goto LAB_c09a1c44;
  case 8:
    iVar3 = 0;
    goto LAB_c09a1c58;
  case 9:
    iVar3 = 1;
    goto LAB_c09a1c44;
  case 10:
    iVar3 = 1;
    goto LAB_c09a1c58;
  case 0xb:
    iVar3 = 2;
    goto LAB_c09a1c44;
  case 0xc:
    iVar3 = 2;
    goto LAB_c09a1c58;
  case 0xd:
    iVar3 = 3;
LAB_c09a1c44:
    FUN_c09a189c(iVar3);
    break;
  case 0xe:
    iVar3 = 3;
LAB_c09a1c58:
    FUN_c09a18f0(iVar3);
    break;
  case 0xf:
    FUN_c09a17f4();
    break;
  case 0x10:
    FUN_c09a1844();
    break;
  case 0x11:
  case 0x12:
    break;
  case 0x13:
    GPINTR_SetPinConfiguration(0x16,2);
    Sleep(10);
    GPINTR_SetPinConfiguration(0x16,3);
    pwVar4 = L"[DRVMGR] BT Enable!\r\n";
    goto LAB_c09a1b80;
  case 0x14:
    GPINTR_SetPinConfiguration(0x16,2);
    pwVar4 = L"[DRVMGR] BT disable!\r\n";
LAB_c09a1b80:
    NKDbgPrintfW(pwVar4);
    break;
  default:
switchD_c09a1988_default:
    SetLastError(0x78);
    uVar5 = 0;
  }
  return uVar5;
}



/* c09a1dc0 FUN_c09a1dc0 */

/* Boundary evidence: original MIPS .pdata c09a1dc0..c09a1efb. Semantic name remains unreviewed. */

int FUN_c09a1dc0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c09a3078 != (code *)0x0) {
      iVar2 = (*DAT_c09a3078)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c09a1e70;
    FUN_c09a2118();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c09a13b4();
  }
LAB_c09a1e70:
  if (((param_2 == 0) && (FUN_c09a20a0(), iVar1 != 0)) && (DAT_c09a3078 != (code *)0x0)) {
    iVar1 = (*DAT_c09a3078)(param_1,0,param_3);
  }
  return iVar1;
}



/* c09a1efc FUN_c09a1efc */

/* Boundary evidence: original MIPS .pdata c09a1efc..c09a1f27. Semantic name remains unreviewed. */

void FUN_c09a1efc(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c09a1f28 entry */

/* Boundary evidence: original MIPS .pdata c09a1f28..c09a1f7f. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c09a2154();
  }
  FUN_c09a1dc0(param_1,param_2,param_3);
  return;
}



/* c09a1f80 FUN_c09a1f80 */

/* Boundary evidence: original MIPS .pdata c09a1f80..c09a209f. Semantic name remains unreviewed. */

void FUN_c09a1f80(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c09a3068 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c09a3070;
    if (DAT_c09a3070 != (undefined4 *)0x0) {
      while (DAT_c09a306c = DAT_c09a306c + -1, _Memory <= DAT_c09a306c) {
        if ((code *)*DAT_c09a306c != (code *)0x0) {
          (*(code *)*DAT_c09a306c)();
          _Memory = DAT_c09a3070;
        }
      }
      free(_Memory);
      DAT_c09a306c = (undefined4 *)0x0;
      DAT_c09a3070 = (undefined4 *)0x0;
    }
    FUN_c09a20c4((undefined4 *)&DAT_c09a1010,(undefined4 *)&DAT_c09a1014);
  }
  FUN_c09a20c4((undefined4 *)&DAT_c09a1018,(undefined4 *)&DAT_c09a101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c09a3074,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c09a20a0 FUN_c09a20a0 */

/* Boundary evidence: original MIPS .pdata c09a20a0..c09a20c3. Semantic name remains unreviewed. */

void FUN_c09a20a0(void)

{
  FUN_c09a1f80(0,0,1);
  return;
}



/* c09a20c4 FUN_c09a20c4 */

/* Boundary evidence: original MIPS .pdata c09a20c4..c09a2117. Semantic name remains unreviewed. */

void FUN_c09a20c4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c09a2118 FUN_c09a2118 */

/* Boundary evidence: original MIPS .pdata c09a2118..c09a2153. Semantic name remains unreviewed. */

void FUN_c09a2118(void)

{
  FUN_c09a20c4((undefined4 *)&DAT_c09a1008,(undefined4 *)&DAT_c09a100c);
  FUN_c09a20c4((undefined4 *)&DAT_c09a1000,(undefined4 *)&DAT_c09a1004);
  return;
}



/* c09a2154 FUN_c09a2154 */

/* Boundary evidence: original MIPS .pdata c09a2154..c09a21c7. Semantic name remains unreviewed. */

void FUN_c09a2154(void)

{
  uint uVar1;
  
  if ((DAT_c09a3050 == 0) || (DAT_c09a3050 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c09a3050 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c09a3050 == 0) {
      DAT_c09a3050 = 0xb064;
    }
  }
  DAT_c09a3054 = ~DAT_c09a3050;
  return;
}


