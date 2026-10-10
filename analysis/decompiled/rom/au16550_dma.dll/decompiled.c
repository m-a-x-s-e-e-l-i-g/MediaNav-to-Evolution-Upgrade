/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c088119c FUN_c088119c */

/* Boundary evidence: original MIPS .pdata c088119c..c088126f. Semantic name remains unreviewed. */

byte FUN_c088119c(int *param_1)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = READ_PORT_ULONG(*param_1 + 0x1c);
  if ((bVar1 & 0xe) != 0) {
    if ((bVar1 & 2) != 0) {
      param_1[0xd] = param_1[0xd] + 1;
      param_1[0xc] = param_1[0xc] | 2;
    }
    if ((bVar1 & 4) != 0) {
      param_1[0xc] = param_1[0xc] | 4;
    }
    if ((bVar1 & 8) != 0) {
      param_1[0xc] = param_1[0xc] | 8;
    }
    uVar2 = 0x80;
  }
  if ((bVar1 & 0x10) != 0) {
    uVar2 = uVar2 | 0x40;
  }
  if (uVar2 != 0) {
    FUN_c0883a70(param_1[3],uVar2);
  }
  return bVar1;
}



/* c0881270 FUN_c0881270 */

/* Boundary evidence: original MIPS .pdata c0881270..c088130f. Semantic name remains unreviewed. */

byte FUN_c0881270(int *param_1)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = READ_PORT_ULONG(*param_1 + 0x20);
  if ((bVar1 & 1) != 0) {
    uVar2 = 8;
  }
  if ((bVar1 & 2) != 0) {
    uVar2 = uVar2 | 0x10;
  }
  if ((bVar1 & 4) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((bVar1 & 8) != 0) {
    uVar2 = uVar2 | 0x20;
  }
  if (uVar2 != 0) {
    FUN_c0883a70(param_1[3],uVar2);
  }
  return bVar1;
}



/* c0881310 FUN_c0881310 */

/* Boundary evidence: original MIPS .pdata c0881310..c08813a7. Semantic name remains unreviewed. */

undefined4 FUN_c0881310(int *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((0x6d < param_2) && (param_2 < 0x2dc6c1)) {
    uVar2 = GetPBUSSpeed();
    if (param_2 << 4 == 0) {
      trap(0x1c00);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
    WRITE_PORT_ULONG(*param_1 + 0x28,uVar2 / (param_2 << 4));
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
    uVar1 = 1;
  }
  return uVar1;
}



/* c08813a8 FUN_c08813a8 */

/* Boundary evidence: original MIPS .pdata c08813a8..c088147b. Semantic name remains unreviewed. */

undefined4 FUN_c08813a8(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else if (param_2 == 1) {
    uVar2 = 8;
  }
  else if (param_2 == 2) {
    uVar2 = 0x18;
  }
  else if (param_2 == 3) {
    uVar2 = 0x28;
  }
  else {
    if (param_2 != 4) {
      return 0;
    }
    uVar2 = 0x38;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  uVar1 = READ_PORT_ULONG(*param_1 + 0x14);
  WRITE_PORT_ULONG(*param_1 + 0x14,uVar1 & 0xfb | uVar2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return 1;
}



/* c088147c FUN_c088147c */

/* Boundary evidence: original MIPS .pdata c088147c..c0881513. Semantic name remains unreviewed. */

undefined4 FUN_c088147c(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_2 < 1) {
      return 0;
    }
    if (2 < param_2) {
      return 0;
    }
    uVar2 = 4;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  uVar1 = READ_PORT_ULONG(*param_1 + 0x14);
  WRITE_PORT_ULONG(*param_1 + 0x14,uVar1 & 0xfb | uVar2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return 1;
}



/* c0881514 FUN_c0881514 */

/* Boundary evidence: original MIPS .pdata c0881514..c088154f. Semantic name remains unreviewed. */

void FUN_c0881514(void)

{
  undefined4 *puVar1;
  
  puVar1 = malloc(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 2;
    puVar1[1] = 0;
    puVar1[2] = &PTR_FUN_c08860f4;
  }
  return;
}



/* c0881550 FUN_c0881550 */

/* Boundary evidence: original MIPS .pdata c0881550..c08815f7. Semantic name remains unreviewed. */

undefined4 FUN_c0881550(int *param_1)

{
  if (*param_1 != 0) {
    WRITE_PORT_ULONG(*param_1 + 0x100,0);
    MmUnmapIoSpace(*param_1,0x1000);
  }
  InterruptDisconnect(param_1[2]);
  InterruptDisconnect(param_1[0x23]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  if ((HANDLE)param_1[0x21] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x21]);
  }
  if ((HANDLE)param_1[0x24] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x24]);
  }
  free(param_1);
  return 1;
}



/* c08815f8 FUN_c08815f8 */

/* Boundary evidence: original MIPS .pdata c08815f8..c088168b. Semantic name remains unreviewed. */

undefined4 FUN_c08815f8(int *param_1)

{
  if (param_1[4] != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
    InterruptDisconnect(param_1[0x23]);
    if ((HANDLE)param_1[0x24] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[0x24]);
    }
    WRITE_PORT_ULONG(*param_1 + 8,0);
    WRITE_PORT_ULONG(*param_1 + 0x18,0);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
    param_1[4] = 0;
  }
  return 0xffffffff;
}



/* c088168c FUN_c088168c */

/* Boundary evidence: original MIPS .pdata c088168c..c08817c7. Semantic name remains unreviewed. */

uint FUN_c088168c(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = READ_PORT_ULONG(*param_1 + 0xc);
  if ((uVar1 & 1) == 0) {
    uVar1 = uVar1 & 0xe;
    if (uVar1 == 0) {
      uVar3 = 8;
      goto LAB_c0881720;
    }
    uVar3 = 2;
    if (uVar1 == 2) {
      uVar3 = 4;
      goto LAB_c0881720;
    }
    if (uVar1 == 4) goto LAB_c0881720;
    if (uVar1 == 6) {
      uVar3 = 1;
      goto LAB_c0881720;
    }
    if (uVar1 == 0xc) goto LAB_c0881720;
  }
  uVar3 = 0;
LAB_c0881720:
  if (param_1[0x14] != 0) {
    uVar3 = uVar3 | 4;
    param_1[0x14] = 0;
  }
  iVar2 = HalCheckForDMAInterrupt(DAT_c0886198);
  if (iVar2 != 0) {
    HalAckDMAInterrupt(DAT_c0886198,iVar2);
    uVar3 = uVar3 | 2;
  }
  if (DAT_c08861b0 != 0) {
    uVar3 = uVar3 | 2;
  }
  if (DAT_c08861a8 != 0) {
    DAT_c08861a8 = 0;
    uVar3 = uVar3 | 2;
  }
  while (iVar2 = HalCheckForDMAInterrupt(DAT_c08861a0), iVar2 != 0) {
    HalAckDMAInterrupt(DAT_c08861a0,iVar2);
    uVar3 = uVar3 | 4;
  }
  return uVar3;
}



/* c08817c8 FUN_c08817c8 */

/* Boundary evidence: original MIPS .pdata c08817c8..c088193f. Semantic name remains unreviewed. */

undefined4 FUN_c08817c8(int *param_1,void *param_2,uint *param_3)

{
  uint uVar1;
  uint _Size;
  uint uVar2;
  
  uVar2 = *param_3;
  *param_3 = 0;
  FUN_c088119c(param_1);
  if (DAT_c08861b0 == 0) {
    DAT_c088619c = (void *)HalGetNextDMABuffer(DAT_c0886198);
    uVar1 = HalGetDMABufferRxSize(DAT_c0886198,DAT_c088619c);
    _Size = uVar1;
    if (uVar2 <= uVar1) {
      _Size = uVar2;
    }
    memcpy(param_2,DAT_c088619c,_Size);
    DAT_c08861b0 = uVar1 - _Size;
    if (DAT_c08861b0 != 0) {
      DAT_c08861b4 = (void *)((int)DAT_c088619c + _Size);
      goto LAB_c08818fc;
    }
  }
  else {
    _Size = DAT_c08861b0;
    if (uVar2 <= DAT_c08861b0) {
      _Size = uVar2;
    }
    memcpy(param_2,DAT_c08861b4,_Size);
    DAT_c08861b0 = DAT_c08861b0 - _Size;
    if (DAT_c08861b0 != 0) {
      DAT_c08861b4 = (void *)((int)DAT_c08861b4 + _Size);
      goto LAB_c08818fc;
    }
  }
  HalActivateDMABuffer(DAT_c0886198,DAT_c088619c,DAT_c08861a4);
LAB_c08818fc:
  *param_3 = *param_3 + _Size;
  param_1[0xd] = 0;
  return 0;
}



/* c0881940 FUN_c0881940 */

/* Boundary evidence: original MIPS .pdata c0881940..c0881aab. Semantic name remains unreviewed. */

void FUN_c0881940(int *param_1,void *param_2,size_t *param_3)

{
  byte bVar1;
  uint _Size;
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar2;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x17);
  EnterCriticalSection(lpCriticalSection);
  if (*param_3 == 0) {
    WRITE_PORT_ULONG(*param_1 + 8,5);
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    EventModify(param_1[0x21],1);
    if (((param_1[7] & 4U) == 0) || (bVar1 = FUN_c0881270(param_1), (bVar1 & 0x10) != 0)) {
      if (((param_1[7] & 8U) == 0) || (bVar1 = FUN_c0881270(param_1), (bVar1 & 0x20) != 0)) {
        LeaveCriticalSection(lpCriticalSection);
        FUN_c088119c(param_1);
        uVar2 = *param_3;
        DAT_c08861ac = (void *)HalGetNextDMABuffer(DAT_c08861a0);
        _Size = DAT_c08861a4;
        if (uVar2 <= DAT_c08861a4) {
          _Size = uVar2;
        }
        memcpy(DAT_c08861ac,param_2,_Size);
        HalActivateDMABuffer(DAT_c08861a0,DAT_c08861ac,_Size);
        *param_3 = _Size;
        return;
      }
      param_1[0x16] = 1;
    }
    else {
      param_1[0x15] = 1;
    }
    WRITE_PORT_ULONG(*param_1 + 8,5);
    LeaveCriticalSection(lpCriticalSection);
    *param_3 = 0;
  }
  return;
}



/* c0881aac FUN_c0881aac */

/* Boundary evidence: original MIPS .pdata c0881aac..c0881b63. Semantic name remains unreviewed. */

void FUN_c0881aac(int *param_1)

{
  byte bVar1;
  
  bVar1 = FUN_c0881270(param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  if ((param_1[0x16] != 0) && ((bVar1 & 0x20) != 0)) {
    param_1[0x16] = 0;
    WRITE_PORT_ULONG(*param_1 + 8,7);
    param_1[0x14] = 1;
  }
  if ((param_1[0x15] != 0) && ((bVar1 & 0x10) != 0)) {
    param_1[0x15] = 0;
    WRITE_PORT_ULONG(*param_1 + 8,7);
    param_1[0x14] = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881b64 FUN_c0881b64 */

/* Boundary evidence: original MIPS .pdata c0881b64..c0881beb. Semantic name remains unreviewed. */

void FUN_c0881b64(int *param_1)

{
  byte bVar1;
  
  FUN_c088119c(param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  bVar1 = READ_PORT_ULONG(*param_1 + 0x10);
  WRITE_PORT_ULONG(*param_1 + 0x10,bVar1 | 2);
  while (bVar1 = FUN_c088119c(param_1), (bVar1 & 1) != 0) {
    READ_PORT_ULONG(*param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881bec FUN_c0881bec */

/* Boundary evidence: original MIPS .pdata c0881bec..c0881c67. Semantic name remains unreviewed. */

undefined4 FUN_c0881bec(int *param_1)

{
  undefined1 uVar1;
  
  uVar1 = READ_PORT_ULONG(*param_1 + 0x10);
  *(undefined1 *)(param_1 + 0x13) = uVar1;
  uVar1 = READ_PORT_ULONG(*param_1 + 0x14);
  *(undefined1 *)((int)param_1 + 0x4d) = uVar1;
  uVar1 = READ_PORT_ULONG(*param_1 + 0x18);
  *(undefined1 *)((int)param_1 + 0x4e) = uVar1;
  uVar1 = READ_PORT_ULONG(*param_1 + 0x28);
  *(undefined1 *)((int)param_1 + 0x4f) = uVar1;
  WRITE_PORT_ULONG(*param_1 + 0x100,0);
  param_1[0x12] = 1;
  return 1;
}



/* c0881c68 FUN_c0881c68 */

/* Boundary evidence: original MIPS .pdata c0881c68..c0881cfb. Semantic name remains unreviewed. */

undefined4 FUN_c0881c68(int *param_1)

{
  if (param_1[0x12] != 0) {
    WRITE_PORT_ULONG(*param_1 + 0x100,1);
    WRITE_PORT_ULONG(*param_1 + 0x100,3);
    WRITE_PORT_ULONG(*param_1 + 0x10,(char)param_1[0x13]);
    WRITE_PORT_ULONG(*param_1 + 0x14,*(undefined1 *)((int)param_1 + 0x4d));
    WRITE_PORT_ULONG(*param_1 + 0x18,*(undefined1 *)((int)param_1 + 0x4e));
    WRITE_PORT_ULONG(*param_1 + 0x28,*(undefined1 *)((int)param_1 + 0x4f));
    param_1[0x12] = 0;
  }
  return 1;
}



/* c0881cfc FUN_c0881cfc */

/* Boundary evidence: original MIPS .pdata c0881cfc..c0881d5f. Semantic name remains unreviewed. */

void FUN_c0881cfc(int *param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  uVar1 = READ_PORT_ULONG(*param_1 + 0x18);
  WRITE_PORT_ULONG(*param_1 + 0x18,uVar1 & 0xfe);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881d60 FUN_c0881d60 */

/* Boundary evidence: original MIPS .pdata c0881d60..c0881dbb. Semantic name remains unreviewed. */

void FUN_c0881d60(int *param_1)

{
  byte bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  bVar1 = READ_PORT_ULONG(*param_1 + 0x18);
  WRITE_PORT_ULONG(*param_1 + 0x18,bVar1 | 1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881dbc FUN_c0881dbc */

/* Boundary evidence: original MIPS .pdata c0881dbc..c0881e1f. Semantic name remains unreviewed. */

void FUN_c0881dbc(int *param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  uVar1 = READ_PORT_ULONG(*param_1 + 0x18);
  WRITE_PORT_ULONG(*param_1 + 0x18,uVar1 & 0xfd);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881e20 FUN_c0881e20 */

/* Boundary evidence: original MIPS .pdata c0881e20..c0881e7b. Semantic name remains unreviewed. */

void FUN_c0881e20(int *param_1)

{
  byte bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  bVar1 = READ_PORT_ULONG(*param_1 + 0x18);
  WRITE_PORT_ULONG(*param_1 + 0x18,bVar1 | 2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881e84 FUN_c0881e84 */

/* Boundary evidence: original MIPS .pdata c0881e84..c0881ee7. Semantic name remains unreviewed. */

void FUN_c0881e84(int *param_1)

{
  uint uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  uVar1 = READ_PORT_ULONG(*param_1 + 0x14);
  WRITE_PORT_ULONG(*param_1 + 0x14,uVar1 & 0xbf);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881ee8 FUN_c0881ee8 */

/* Boundary evidence: original MIPS .pdata c0881ee8..c0881f43. Semantic name remains unreviewed. */

void FUN_c0881ee8(int *param_1)

{
  byte bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  bVar1 = READ_PORT_ULONG(*param_1 + 0x14);
  WRITE_PORT_ULONG(*param_1 + 0x14,bVar1 | 0x40);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881f44 FUN_c0881f44 */

/* Boundary evidence: original MIPS .pdata c0881f44..c0881f8f. Semantic name remains unreviewed. */

void FUN_c0881f44(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  WRITE_PORT_ULONG(*param_1 + 8,5);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0881f90 FUN_c0881f90 */

/* Boundary evidence: original MIPS .pdata c0881f90..c0882013. Semantic name remains unreviewed. */

void FUN_c0881f90(int *param_1,uint *param_2)

{
  byte bVar1;
  
  bVar1 = FUN_c0881270(param_1);
  *param_2 = 0;
  if ((bVar1 & 0x10) != 0) {
    *param_2 = 0x10;
  }
  if ((bVar1 & 0x20) != 0) {
    *param_2 = *param_2 | 0x20;
  }
  if ((bVar1 & 0x40) != 0) {
    *param_2 = *param_2 | 0x40;
  }
  if ((bVar1 & 0x80) != 0) {
    *param_2 = *param_2 | 0x80;
  }
  return;
}



/* c0882014 FUN_c0882014 */

/* Boundary evidence: original MIPS .pdata c0882014..c08820ff. Semantic name remains unreviewed. */

undefined4 FUN_c0882014(int *param_1,undefined4 param_2)

{
  byte bVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x17);
  EnterCriticalSection(lpCriticalSection);
  bVar1 = FUN_c088119c(param_1);
  while ((bVar1 & 0x20) == 0) {
    WRITE_PORT_ULONG(*param_1 + 8,7);
    LeaveCriticalSection(lpCriticalSection);
    WaitForSingleObject((HANDLE)param_1[0x21],1000);
    EnterCriticalSection(lpCriticalSection);
    bVar1 = FUN_c088119c(param_1);
  }
  WRITE_PORT_ULONG(*param_1 + 4,param_2);
  WRITE_PORT_ULONG(*param_1 + 8,7);
  LeaveCriticalSection(lpCriticalSection);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return 1;
}



/* c0882174 FUN_c0882174 */

/* Boundary evidence: original MIPS .pdata c0882174..c08821fb. Semantic name remains unreviewed. */

void FUN_c0882174(undefined4 param_1,undefined2 *param_2)

{
  memset(param_2,0,0x40);
  *(undefined4 *)(param_2 + 6) = 0x10;
  *(undefined4 *)(param_2 + 8) = 0x10;
  *(undefined4 *)(param_2 + 2) = 1;
  *(undefined4 *)(param_2 + 10) = 0x10000000;
  *(undefined4 *)(param_2 + 0xc) = 1;
  *param_2 = 0xffff;
  param_2[1] = 0xffff;
  *(undefined4 *)(param_2 + 0xe) = 0x1ff;
  *(undefined4 *)(param_2 + 0x10) = 0x7f;
  *(undefined4 *)(param_2 + 0x12) = 0x67ffb;
  param_2[0x14] = 0xf;
  param_2[0x15] = 0x1f05;
  return;
}



/* c08821fc FUN_c08821fc */

/* Boundary evidence: original MIPS .pdata c08821fc..c088227f. Semantic name remains unreviewed. */

void FUN_c08821fc(int *param_1,uint param_2)

{
  byte bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  bVar1 = READ_PORT_ULONG(*param_1 + 0x10);
  if ((param_2 & 4) != 0) {
    bVar1 = bVar1 | 4;
  }
  if ((param_2 & 8) != 0) {
    bVar1 = bVar1 | 2;
  }
  WRITE_PORT_ULONG(*param_1 + 0x10,bVar1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
  return;
}



/* c0882280 FUN_c0882280 */

/* Boundary evidence: original MIPS .pdata c0882280..c08823b3. Semantic name remains unreviewed. */

undefined4 FUN_c0882280(int *param_1,void *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  if (param_1[4] != 0) {
    if ((*(uint *)((int)param_2 + 4) != param_1[6]) &&
       (iVar3 = FUN_c0881310(param_1,*(uint *)((int)param_2 + 4)), iVar3 == 0)) {
      return 0;
    }
    bVar1 = *(byte *)((int)param_2 + 0x12);
    if (bVar1 != *(byte *)((int)param_1 + 0x26)) {
      if (bVar1 < 5) {
        return 0;
      }
      if (8 < bVar1) {
        return 0;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
      bVar2 = READ_PORT_ULONG(*param_1 + 0x14);
      WRITE_PORT_ULONG(*param_1 + 0x14,bVar2 & 3 | bVar1 - 5);
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x17));
    }
    if (((uint)*(byte *)((int)param_2 + 0x13) != (uint)*(byte *)((int)param_1 + 0x27)) &&
       (iVar3 = FUN_c08813a8(param_1,(uint)*(byte *)((int)param_2 + 0x13)), iVar3 == 0)) {
      return 0;
    }
    if (((uint)*(byte *)((int)param_2 + 0x14) != (uint)*(byte *)(param_1 + 10)) &&
       (iVar3 = FUN_c088147c(param_1,(uint)*(byte *)((int)param_2 + 0x14)), iVar3 == 0)) {
      return 0;
    }
  }
  memcpy(param_1 + 5,param_2,0x1c);
  return 1;
}



/* c08823bc FUN_c08823bc */

/* Boundary evidence: original MIPS .pdata c08823bc..c0882433. Semantic name remains unreviewed. */

undefined4 FUN_c08823bc(int param_1)

{
  DWORD DVar1;
  
  while ((DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x90),10), DVar1 == 0 ||
         (DVar1 == 0x102))) {
    DAT_c08861a8 = 1;
    SetInterruptEvent(*(undefined4 *)(param_1 + 8));
  }
  return 0;
}



/* c0882434 FUN_c0882434 */

/* Boundary evidence: original MIPS .pdata c0882434..c0882717. Semantic name remains unreviewed. */

int * FUN_c0882434(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  int *_Dst;
  HKEY hKey;
  LSTATUS LVar2;
  int iVar3;
  HANDLE pvVar4;
  uint uVar5;
  uint local_30;
  DWORD local_2c;
  
  bVar1 = false;
  _Dst = malloc(0xa0);
  if (_Dst != (int *)0x0) {
    memset(_Dst,0,0xa0);
    hKey = (HKEY)OpenDeviceKey(param_1);
    if (hKey != (HKEY)0x0) {
      local_2c = 4;
      LVar2 = RegQueryValueExW(hKey,L"UnitIndex",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_30,
                               &local_2c);
      if (LVar2 == 0) {
        if ((local_30 < 5) && (*(int *)(&DAT_c088616c + local_30 * 8) != 0)) {
          iVar3 = MmMapIoSpace(*(int *)(&DAT_c088616c + local_30 * 8),0,0x10c,0);
          *_Dst = iVar3;
          if (iVar3 != 0) {
            _Dst[0x27] = *(int *)(&DAT_c0886170 + local_30 * 8);
            DAT_c08861a4 = 0x400;
            DAT_c08861a0 = HalAllocateDMAChannel();
            DAT_c0886198 = HalAllocateDMAChannel();
            if ((DAT_c08861a0 != 0) && (DAT_c0886198 != 0)) {
              HalInitDmaChannel(DAT_c08861a0,0,DAT_c08861a4,1);
              HalInitDmaChannel(DAT_c0886198,1,DAT_c08861a4,1);
              HalSetDMAForReceive(DAT_c0886198);
              HalStartDMA(DAT_c0886198);
              HalStartDMA(DAT_c08861a0);
              iVar3 = HalGetDMAHwIntr(DAT_c08861a0);
              _Dst[1] = iVar3;
              iVar3 = HalGetDMAHwIntr(DAT_c0886198);
              uVar5 = iVar3 << 8 | _Dst[1];
              _Dst[1] = uVar5;
              iVar3 = InterruptConnect(0,0,uVar5,0);
              _Dst[2] = iVar3;
              if (iVar3 != 0) {
                *(int *)(param_3 + 4) = iVar3;
                InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 0x17));
                InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 0x1c));
                pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
                _Dst[0x21] = (int)pvVar4;
                if (pvVar4 != (HANDLE)0x0) {
                  WRITE_PORT_ULONG(*_Dst + 0x100,0);
                  WRITE_PORT_ULONG(*_Dst + 0x100,1);
                  WRITE_PORT_ULONG(*_Dst + 0x100,3);
                  WRITE_PORT_ULONG(*_Dst + 8,0);
                  _Dst[3] = param_2;
                  WRITE_PORT_ULONG(0xb0200058,0x1000000);
                  WRITE_PORT_ULONG(0xb0201160,1);
                  WRITE_PORT_ULONG(0xb0200048,0x1000000);
                  bVar1 = true;
                }
              }
            }
          }
        }
        else {
          NKDbgPrintfW(L" au1uart::HWInit - UnitIndex %d is invalid\n");
        }
      }
      else {
        NKDbgPrintfW(L" au1uart::HWInit - Failed open \"UnitIndex\" registry entry\n");
      }
      RegCloseKey(hKey);
      if (bVar1) {
        return _Dst;
      }
    }
    FUN_c0881550(_Dst);
  }
  return (int *)0x0;
}



/* c0882718 FUN_c0882718 */

/* Boundary evidence: original MIPS .pdata c0882718..c0882953. Semantic name remains unreviewed. */

undefined4 FUN_c0882718(int *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  HANDLE pvVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar5;
  DWORD aDStack_20 [2];
  
  uVar5 = 0;
  if (param_1[4] == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x17);
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x14] = 0;
    param_1[0x12] = 0;
    param_1[4] = 1;
    param_1[0xe] = 0x10;
    param_1[0xf] = 8;
    param_1[0x10] = 0x10;
    param_1[0x11] = 1;
    EnterCriticalSection(lpCriticalSection);
    WRITE_PORT_ULONG(*param_1 + 0x14,0);
    FUN_c0881310(param_1,param_1[6]);
    bVar1 = *(byte *)((int)param_1 + 0x26);
    if ((4 < bVar1) && (bVar1 < 9)) {
      EnterCriticalSection(lpCriticalSection);
      bVar2 = READ_PORT_ULONG(*param_1 + 0x14);
      WRITE_PORT_ULONG(*param_1 + 0x14,bVar2 & 3 | bVar1 - 5);
      LeaveCriticalSection(lpCriticalSection);
    }
    FUN_c088147c(param_1,(uint)*(byte *)(param_1 + 10));
    FUN_c08813a8(param_1,(uint)*(byte *)((int)param_1 + 0x27));
    WRITE_PORT_ULONG(*param_1 + 0x18,0);
    WRITE_PORT_ULONG(*param_1 + 0x10,0xaf);
    WRITE_PORT_ULONG(*param_1 + 8,5);
    FUN_c088119c(param_1);
    FUN_c0881270(param_1);
    param_1[0x22] = param_1[0x27];
    iVar3 = InterruptConnect(0,0,param_1[0x27],0);
    param_1[0x23] = iVar3;
    if (iVar3 != 0) {
      pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      param_1[0x24] = (int)pvVar4;
      if (pvVar4 != (HANDLE)0x0) {
        InterruptInitialize(param_1[0x23],pvVar4,0,0);
        param_1[0x26] = 0x65;
        pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c08823bc,param_1,0,aDStack_20);
        param_1[0x25] = (int)pvVar4;
        iVar3 = GetThreadPriority(pvVar4);
        NKDbgPrintfW(L"UART DMA Thread[%d] [%d]\r\n",iVar3,0);
        CeSetThreadPriority(param_1[0x25],0x32);
        if (param_1[0x25] != 0) {
          LeaveCriticalSection(lpCriticalSection);
          uVar5 = 1;
        }
      }
    }
  }
  return uVar5;
}



/* c0882954 entry */

/* Boundary evidence: original MIPS .pdata c0882954..c0882987. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0882988 FUN_c0882988 */

/* Boundary evidence: original MIPS .pdata c0882988..c0882ad7. Semantic name remains unreviewed. */

void FUN_c0882988(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_20 [2];
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x28) + 8);
  uVar2 = *(undefined4 *)(param_1 + 0x2c);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd0));
  if (*(int *)(param_1 + 0x90) == 0) {
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  if ((*(int *)(param_1 + 0xcc) == 0) || (*(int *)(param_1 + 200) == *(int *)(param_1 + 0xc4))) {
    local_20[0] = 0;
    (**(code **)(iVar1 + 0x1c))(uVar2,0,local_20);
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    EventModify(*(undefined4 *)(param_1 + 0x3c),3);
  }
  else {
    if ((*(uint *)(param_1 + 0x68) & 0x3000) == 0x3000) {
      (**(code **)(iVar1 + 0x40))(uVar2);
    }
    if ((*(uint *)(param_1 + 0x94) & 4) == 0) {
      local_20[0] = *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc4);
    }
    else {
      local_20[0] = 0;
    }
    (**(code **)(iVar1 + 0x1c))(uVar2,*(int *)(param_1 + 0xcc) + *(int *)(param_1 + 0xc4),local_20);
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + local_20[0];
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + local_20[0];
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + local_20[0];
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd0));
  return;
}



/* c0882ad8 FUN_c0882ad8 */

/* Boundary evidence: original MIPS .pdata c0882ad8..c0882b9b. Semantic name remains unreviewed. */

undefined4 FUN_c0882ad8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    uVar1 = CeGetThreadPriority(0x41);
    CeSetThreadPriority(*(undefined4 *)(param_1 + 0x40),uVar1);
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 1;
    EventModify(*(undefined4 *)(param_1 + 0x30),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x38),3000);
    Sleep(10);
    CloseHandle(*(HANDLE *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    InterruptDone(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
    InterruptDisable(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
  }
  return 1;
}



/* c0882b9c FUN_c0882b9c */

/* Boundary evidence: original MIPS .pdata c0882b9c..c0882ed7. Semantic name remains unreviewed. */

undefined4 FUN_c0882b9c(int param_1,void *param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x28);
  if ((((*(uint *)(param_1 + 0xa4) <= (uint)*(ushort *)((int)param_2 + 0x10)) ||
       (*(uint *)(param_1 + 0xa4) - (uint)*(ushort *)((int)param_2 + 0x10) <=
        (uint)*(ushort *)((int)param_2 + 0xe))) ||
      ((((*(uint *)((int)param_2 + 8) & 0x100) != 0 || ((*(uint *)((int)param_2 + 8) & 0x200) != 0))
       && (*(char *)((int)param_2 + 0x15) == *(char *)((int)param_2 + 0x16))))) ||
     (iVar1 = (**(code **)(*(int *)(iVar5 + 8) + 0x6c))(*(undefined4 *)(param_1 + 0x2c),param_2),
     iVar1 == 0)) {
    return 0;
  }
  if (param_3 == 0) {
    return 1;
  }
  memcpy((void *)(param_1 + 0x60),param_2,0x1c);
  uVar3 = *(uint *)(param_1 + 0x68) >> 4 & 3;
  if (uVar3 == 0) {
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x34);
LAB_c0882c84:
    (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
  }
  else if (uVar3 == 1) {
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x38);
    goto LAB_c0882c84;
  }
  uVar3 = *(uint *)(param_1 + 0x68) >> 0xc & 3;
  if (uVar3 == 0) {
    (**(code **)(*(int *)(iVar5 + 8) + 0x3c))(*(undefined4 *)(param_1 + 0x2c));
  }
  else if (uVar3 == 1) {
    (**(code **)(*(int *)(iVar5 + 8) + 0x40))(*(undefined4 *)(param_1 + 0x2c));
  }
  if ((*(uint *)(param_1 + 0x68) & 0x30) == 0x20) {
    uVar3 = *(uint *)(param_1 + 0x94);
    if ((uVar3 & 0x10) == 0) {
      uVar4 = *(uint *)(param_1 + 0x9c);
      if (*(uint *)(param_1 + 0xa0) < uVar4) {
        iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
      }
      else {
        iVar1 = -uVar4;
      }
      if ((uint)*(ushort *)(param_1 + 0x70) <
          *(int *)(param_1 + 0xa4) - (*(uint *)(param_1 + 0xa0) + iVar1)) goto LAB_c0882d48;
      *(uint *)(param_1 + 0x94) = uVar3 | 0x10;
      pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x34);
    }
    else {
LAB_c0882d48:
      uVar4 = *(uint *)(param_1 + 0x9c);
      if (*(uint *)(param_1 + 0xa0) < uVar4) {
        iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
      }
      else {
        iVar1 = -uVar4;
      }
      if ((uint)*(ushort *)(param_1 + 0x6e) < *(uint *)(param_1 + 0xa0) + iVar1) goto LAB_c0882da0;
      *(uint *)(param_1 + 0x94) = uVar3 & 0xffffffef;
      pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x38);
    }
    (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
  }
LAB_c0882da0:
  if ((*(uint *)(param_1 + 0x68) & 0x3000) != 0x2000) goto LAB_c0882e70;
  uVar3 = *(uint *)(param_1 + 0x94);
  if ((uVar3 & 0x20) == 0) {
    uVar4 = *(uint *)(param_1 + 0x9c);
    if (*(uint *)(param_1 + 0xa0) < uVar4) {
      iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
    }
    else {
      iVar1 = -uVar4;
    }
    if ((uint)*(ushort *)(param_1 + 0x70) <
        *(int *)(param_1 + 0xa4) - (*(uint *)(param_1 + 0xa0) + iVar1)) goto LAB_c0882e18;
    *(uint *)(param_1 + 0x94) = uVar3 | 0x20;
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x3c);
  }
  else {
LAB_c0882e18:
    uVar4 = *(uint *)(param_1 + 0x9c);
    if (*(uint *)(param_1 + 0xa0) < uVar4) {
      iVar1 = *(int *)(param_1 + 0xa4) - uVar4;
    }
    else {
      iVar1 = -uVar4;
    }
    if ((uint)*(ushort *)(param_1 + 0x6e) < *(uint *)(param_1 + 0xa0) + iVar1) goto LAB_c0882e70;
    *(uint *)(param_1 + 0x94) = uVar3 & 0xffffffdf;
    pcVar2 = *(code **)(*(int *)(iVar5 + 8) + 0x40);
  }
  (*pcVar2)(*(undefined4 *)(param_1 + 0x2c));
LAB_c0882e70:
  if (((*(uint *)(param_1 + 0x68) & 0x100) == 0) && ((*(uint *)(param_1 + 0x68) & 0x200) == 0)) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 2;
  }
  return 1;
}



/* c0882ed8 FUN_c0882ed8 */

/* Boundary evidence: original MIPS .pdata c0882ed8..c0882fe3. Semantic name remains unreviewed. */

undefined4 FUN_c0882ed8(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xec));
    uVar2 = 1;
    if ((param_1[1] & 0x100U) == 0) {
      if (*(int *)(iVar1 + 0x90) == 0) {
        SetLastError(6);
      }
      else {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        param_1[5] = 0;
        param_1[7] = 1;
        EventModify(param_1[4],3);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        if ((param_1[1] & 0xc0000000U) != 0) {
          *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x40;
          EventModify(*(undefined4 *)(iVar1 + 0x34),3);
          *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x80;
          EventModify(*(undefined4 *)(iVar1 + 0x3c),3);
        }
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xec));
  }
  return uVar2;
}



/* c0882fe4 COM_Close */

/* Boundary evidence: original MIPS .pdata c0882fe4..c088318b. Semantic name remains unreviewed. */

undefined4 COM_Close(int *param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  
                    /* 0x2fe4  1  COM_Close */
  iVar2 = *param_1;
  uVar4 = 1;
  if (iVar2 == 0) {
    SetLastError(6);
    return 0;
  }
  puVar3 = *(uint **)(iVar2 + 0x28);
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xec));
  if ((param_1[1] & 0x100U) == 0) {
    if (*(int *)(iVar2 + 0x90) == 0) {
      SetLastError(6);
      uVar4 = 0;
      goto LAB_c0883160;
    }
    iVar1 = *(int *)(iVar2 + 0x90) + -1;
    *(int *)(iVar2 + 0x90) = iVar1;
    if ((((puVar3 != (uint *)0x0) && (iVar1 == 0)) && ((*puVar3 & 3) != 0)) &&
       (*(HANDLE *)(iVar2 + 0x40) != (HANDLE)0x0)) {
      SetThreadPriority(*(HANDLE *)(iVar2 + 0x40),3);
    }
    if (*(int *)(iVar2 + 0x90) == 0) {
      if (puVar3 != (uint *)0x0) {
        (**(code **)(puVar3[2] + 0x10))(*(undefined4 *)(iVar2 + 0x2c));
      }
      if ((**(uint **)(iVar2 + 0x28) & 2) != 0) {
        FUN_c0882ad8(iVar2);
      }
    }
    if (param_1 == *(int **)(iVar2 + 0x100)) {
      *(undefined4 *)(iVar2 + 0x100) = 0;
    }
    *(int *)param_1[0xe] = param_1[0xd];
    *(int *)(param_1[0xd] + 4) = param_1[0xe];
  }
  else {
    *(int *)param_1[0xe] = param_1[0xd];
    *(int *)(param_1[0xd] + 4) = param_1[0xe];
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if ((HANDLE)param_1[4] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[4]);
  }
  LocalFree(param_1);
LAB_c0883160:
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xec));
  return uVar4;
}



/* c088318c FUN_c088318c */

/* Boundary evidence: original MIPS .pdata c088318c..c08831cf. Semantic name remains unreviewed. */

bool FUN_c088318c(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_c0882ed8(param_1);
  }
  else {
    SetLastError(6);
  }
  return iVar1 != 0;
}



/* c08831d0 COM_Deinit */

/* Boundary evidence: original MIPS .pdata c08831d0..c0883367. Semantic name remains unreviewed. */

undefined4 COM_Deinit(LPCRITICAL_SECTION param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  ULONG_PTR *lpCriticalSection;
  
                    /* 0x31d0  2  COM_Deinit */
  if (param_1 == (LPCRITICAL_SECTION)0x0) {
    SetLastError(6);
    uVar1 = 0;
  }
  else {
    if ((param_1[1].LockSemaphore != (uint *)0x0) && ((*(uint *)param_1[1].LockSemaphore & 3) != 0))
    {
      FUN_c0882ad8((int)param_1);
    }
    lpCriticalSection = &param_1[9].SpinCount;
    EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if (param_1[6].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
      piVar4 = param_1[9].OwningThread;
      while ((HANDLE *)piVar4 != &param_1[9].OwningThread) {
        piVar2 = piVar4 + -0xd;
        piVar4 = (int *)*piVar4;
        COM_Close(piVar2);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if (param_1[2].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
      CloseHandle(param_1[2].DebugInfo);
    }
    if ((HANDLE)param_1[2].RecursionCount != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[2].RecursionCount);
    }
    if (param_1[2].OwningThread != (HANDLE)0x0) {
      CloseHandle(param_1[2].OwningThread);
    }
    if ((HANDLE)param_1[2].LockCount != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[2].LockCount);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1->SpinCount);
    DeleteCriticalSection(param_1);
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1[7].RecursionCount);
    DeleteCriticalSection((LPCRITICAL_SECTION)&param_1[8].LockSemaphore);
    DeleteCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);
    if ((HLOCAL)param_1[7].LockCount != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[7].LockCount);
    }
    if (((param_1[1].SpinCount != 0) && (param_1[1].LockSemaphore != (HANDLE)0x0)) &&
       (iVar3 = *(int *)((int)param_1[1].LockSemaphore + 8), iVar3 != 0)) {
      (**(code **)(iVar3 + 8))();
    }
    LocalFree(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



/* c0883368 COM_Read */

/* Boundary evidence: original MIPS .pdata c0883368..c08837ff. Semantic name remains unreviewed. */

int COM_Read(int *param_1,int param_2,uint param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
                    /* 0x3368  8  COM_Read */
  iVar11 = 0;
  uVar14 = 0;
  if (((param_1 == (int *)0x0) || (iVar9 = *param_1, iVar9 == 0)) || (*(int *)(iVar9 + 0x90) == 0))
  {
    DVar1 = 6;
  }
  else {
    iVar3 = *(int *)(*(int *)(iVar9 + 0x28) + 8);
    uVar4 = *(undefined4 *)(iVar9 + 0x2c);
    if ((param_1[1] & 0x80000000U) == 0) {
      SetLastError(0xc);
      return -1;
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      InterlockedIncrement(param_1 + 3);
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0x14));
      iVar5 = *(int *)(iVar9 + 0x80);
      *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffbf;
      if (iVar5 == -1) {
        uVar13 = *(uint *)(iVar9 + 0x84);
        iVar6 = 0;
      }
      else {
        iVar6 = iVar5 << 3;
        uVar13 = iVar5 * param_3 + *(int *)(iVar9 + 0x84);
      }
      uVar12 = *(uint *)(iVar9 + 0x7c);
      if ((uVar12 < -iVar6 - 1U) && (uVar12 != 0)) {
        uVar12 = uVar12 + iVar6;
      }
      do {
        uVar8 = 0xffffffff;
        uVar7 = *(uint *)(iVar9 + 0x9c);
        if (*(uint *)(iVar9 + 0xa0) < uVar7) {
          iVar5 = *(int *)(iVar9 + 0xa4) - uVar7;
        }
        else {
          iVar5 = -uVar7;
        }
        if (*(uint *)(iVar9 + 0xa0) + iVar5 == 0) {
          if ((uVar12 == 0xffffffff) && ((uVar13 == 0 || (iVar11 != 0)))) goto LAB_c0883790;
          uVar7 = uVar13;
          if (uVar13 == 0) {
            uVar7 = uVar8;
          }
          if (uVar7 <= uVar14) goto LAB_c0883790;
          uVar7 = uVar7 - uVar14;
          if (iVar11 != 0) {
            uVar10 = uVar12;
            if (uVar12 == 0) {
              uVar10 = uVar8;
            }
            if ((uVar10 <= uVar7) && (uVar7 = uVar12, uVar12 == 0)) {
              uVar7 = uVar8;
            }
          }
          DVar1 = GetTickCount();
          DVar2 = WaitForSingleObject(*(HANDLE *)(iVar9 + 0x34),uVar7);
          if (DVar2 == 0x102) goto LAB_c0883790;
          DVar2 = GetTickCount();
          uVar14 = DVar2 + (uVar14 - DVar1);
          if ((*(uint *)(iVar9 + 0x94) & 0x40) != 0) goto LAB_c0883790;
          if (*(int *)(iVar9 + 0x90) == 0) {
            SetLastError(6);
            goto LAB_c0883790;
          }
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0xb0));
          uVar7 = *(uint *)(iVar9 + 0xa0);
          uVar8 = *(uint *)(iVar9 + 0x9c);
          if (uVar7 < uVar8) {
            iVar5 = *(int *)(iVar9 + 0xa4) - uVar8;
          }
          else {
            iVar5 = -uVar8;
          }
          uVar10 = *(int *)(iVar9 + 0xa4) - uVar8;
          if (uVar7 + iVar5 < uVar10) {
            if (uVar7 < uVar8) {
              uVar10 = (*(int *)(iVar9 + 0xa4) - uVar8) + uVar7;
            }
            else {
              uVar10 = uVar7 - uVar8;
            }
          }
          if (param_3 <= uVar10) {
            uVar10 = param_3;
          }
          CeSafeCopyMemory(param_2,*(int *)(iVar9 + 0xac) + uVar8,uVar10);
          uVar7 = *(int *)(iVar9 + 0x9c) + uVar10;
          if (*(uint *)(iVar9 + 0xa4) <= uVar7) {
            uVar7 = (*(int *)(iVar9 + 0x9c) - *(uint *)(iVar9 + 0xa4)) + uVar10;
          }
          *(uint *)(iVar9 + 0x9c) = uVar7;
          param_3 = param_3 - uVar10;
          param_2 = uVar10 + param_2;
          iVar11 = uVar10 + iVar11;
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0xb0));
        }
        uVar7 = *(uint *)(iVar9 + 0x9c);
        if (*(uint *)(iVar9 + 0xa0) < uVar7) {
          iVar5 = *(int *)(iVar9 + 0xa4) - uVar7;
        }
        else {
          iVar5 = -uVar7;
        }
        if (*(uint *)(iVar9 + 0xa0) + iVar5 <= (uint)*(ushort *)(iVar9 + 0x6e)) {
          if (((*(uint *)(iVar9 + 0x68) & 0x200) != 0) &&
             (uVar7 = *(uint *)(iVar9 + 0x94), (uVar7 & 8) != 0)) {
            *(uint *)(iVar9 + 0x94) = uVar7 & 0xfffffff7;
            if ((*(uint *)(iVar9 + 0x68) & 0x80) == 0) {
              *(uint *)(iVar9 + 0x94) = uVar7 & 0xfffffff3;
            }
            (**(code **)(*(int *)(*(int *)(iVar9 + 0x28) + 8) + 0x54))
                      (*(undefined4 *)(iVar9 + 0x2c),*(undefined1 *)(iVar9 + 0x75));
          }
          if (((*(uint *)(iVar9 + 0x94) & 0x20) != 0) &&
             ((*(uint *)(iVar9 + 0x68) & 0x3000) == 0x2000)) {
            *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffdf;
            (**(code **)(iVar3 + 0x40))(uVar4);
          }
          if (((*(uint *)(iVar9 + 0x94) & 0x10) != 0) && ((*(uint *)(iVar9 + 0x68) & 0x30) == 0x20))
          {
            *(uint *)(iVar9 + 0x94) = *(uint *)(iVar9 + 0x94) & 0xffffffef;
            (**(code **)(iVar3 + 0x38))(uVar4);
          }
        }
        if (param_3 == 0) {
LAB_c0883790:
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar9 + 0x14));
          InterlockedDecrement(param_1 + 3);
          return iVar11;
        }
      } while( true );
    }
    DVar1 = 0x57;
  }
  SetLastError(DVar1);
  return -1;
}



/* c0883800 COM_Seek */

undefined4 COM_Seek(void)

{
                    /* 0x3800  9  COM_Seek */
  return 0xffffffff;
}



/* c0883808 COM_PowerUp */

/* Boundary evidence: original MIPS .pdata c0883808..c088384b. Semantic name remains unreviewed. */

undefined4 COM_PowerUp(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x3808  7  COM_PowerUp */
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x28) + 8) + 0x30))
                      (*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



/* c088384c COM_PowerDown */

/* Boundary evidence: original MIPS .pdata c088384c..c088388f. Semantic name remains unreviewed. */

undefined4 COM_PowerDown(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x384c  6  COM_PowerDown */
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x28) + 8) + 0x2c))
                      (*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



/* c0883890 FUN_c0883890 */

/* Boundary evidence: original MIPS .pdata c0883890..c0883a63. Semantic name remains unreviewed. */

undefined4 FUN_c0883890(int *param_1,uint *param_2)

{
  uint uVar1;
  DWORD dwErrCode;
  int iVar2;
  
  iVar2 = *param_1;
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x90) != 0)) {
    if (param_1[5] == 0) {
      dwErrCode = 0x57;
      goto LAB_c0883a24;
    }
    InterlockedIncrement(param_1 + 3);
    param_1[7] = 0;
    if (*(int *)(iVar2 + 0x90) != 0) {
      do {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        EventModify(param_1[4],2);
        uVar1 = InterlockedExchange(param_1 + 6,0);
        if (((param_1[5] & uVar1) != 0) || (param_1[5] == 0)) {
          *param_2 = param_1[5] & uVar1;
          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        WaitForSingleObject((HANDLE)param_1[4],0xffffffff);
        if (param_1[7] != 0) {
          *param_2 = 0;
          break;
        }
      } while (*(int *)(iVar2 + 0x90) != 0);
    }
    InterlockedDecrement(param_1 + 3);
    if (*(int *)(iVar2 + 0x90) != 0) {
      return 1;
    }
  }
  dwErrCode = 6;
LAB_c0883a24:
  *param_2 = 0;
  SetLastError(dwErrCode);
  return 0;
}



/* c0883a64 FUN_c0883a64 */

/* Boundary evidence: original MIPS .pdata c0883a64..c0883a6f. Semantic name remains unreviewed. */

undefined4 FUN_c0883a64(void)

{
  return 1;
}



/* c0883a70 FUN_c0883a70 */

/* Boundary evidence: original MIPS .pdata c0883a70..c0883b5f. Semantic name remains unreviewed. */

void FUN_c0883a70(int param_1,uint param_2)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  if (*(int *)(param_1 + 0x90) == 0) {
    SetLastError(6);
  }
  else if ((*(uint *)(param_1 + 0x98) & param_2) != 0) {
    piVar2 = (int *)*(int *)(param_1 + 0xe4);
    while (piVar2 != (int *)(param_1 + 0xe4)) {
      piVar5 = (int *)*piVar2;
      EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + -5));
      if ((piVar2[-8] & param_2) != 0) {
        uVar3 = piVar2[-7];
        do {
          uVar4 = InterlockedExchange(piVar2 + -7,uVar3 | param_2);
          bVar1 = uVar3 != uVar4;
          uVar3 = uVar4;
        } while (bVar1);
        EventModify(piVar2[-9],3);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + -5));
      piVar2 = piVar5;
    }
  }
  return;
}



/* c0883b60 COM_IOControl */

/* Boundary evidence: original MIPS .pdata c0883b60..c08845cb. Semantic name remains unreviewed. */

bool COM_IOControl(int *param_1,int param_2,uint *param_3,uint param_4,uint *param_5,uint param_6,
                  undefined4 *param_7)

{
  DWORD DVar1;
  undefined1 *_Src;
  size_t _Size;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  uint uVar11;
  int iVar12;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar13;
  uint local_a0;
  int *local_9c;
  LONG *local_98;
  uint local_90;
  uint local_8c [7];
  undefined1 auStack_70 [64];
  uint local_30;
  
                    /* 0x3b60  3  COM_IOControl */
  local_30 = DAT_c088618c;
  bVar9 = true;
  bVar10 = true;
  local_a0 = param_4;
  local_9c = param_1;
  if ((param_1 == (int *)0x0) || (iVar7 = *param_1, iVar7 == 0)) {
    SetLastError(6);
    goto LAB_c0884590;
  }
  iVar12 = *(int *)(*(int *)(iVar7 + 0x28) + 8);
  uVar13 = *(undefined4 *)(iVar7 + 0x2c);
  if ((param_1[1] & 0x100U) != 0) {
    if ((((param_2 == 0x321000) || (param_2 == 0x321004)) || (param_2 == 0x321008)) ||
       ((param_2 == 0x32100c || (param_2 == 0x321018)))) {
      if ((*(code **)(iVar12 + 0x74) != (code *)0x0) &&
         (iVar7 = (**(code **)(iVar12 + 0x74))
                            (uVar13,param_2,param_3,param_4,param_5,param_6,param_7), iVar7 != 0))
      goto LAB_c0883c88;
      SetLastError(0x57);
    }
    else {
      SetLastError(6);
    }
    bVar10 = false;
    goto LAB_c0883c88;
  }
  if (*(int *)(iVar7 + 0x90) == 0) {
    DVar1 = 6;
LAB_c0883cb0:
    SetLastError(DVar1);
LAB_c0884590:
    FUN_c088566c(local_30);
    return false;
  }
  if (param_2 == 0x10303ff) {
    if ((*param_3 == 0x10) && (param_3[1] == 4)) {
      FUN_c088318c(param_1);
    }
    goto LAB_c0883c88;
  }
  if ((((param_2 != 0x1b0024) && (param_2 != 0x1b0028)) && (param_2 != 0x1b002c)) &&
     (((((param_2 != 0x1b0034 && (param_2 != 0x1b0038)) &&
        ((param_2 != 0x1b0040 && ((param_2 != 0x321000 && (param_2 != 0x32100c)))))) &&
       (param_2 != 0x321008)) && ((param_1[1] & 0xc0000000U) == 0)))) {
    DVar1 = 0xc;
    goto LAB_c0883cb0;
  }
  local_98 = param_1 + 3;
  InterlockedIncrement(local_98);
  piVar4 = local_9c;
  bVar10 = bVar9;
  switch(param_2) {
  case 0x1b0004:
    (**(code **)(iVar12 + 0x50))(uVar13);
    break;
  default:
    if (*(code **)(iVar12 + 0x74) != (code *)0x0) {
      iVar7 = (**(code **)(iVar12 + 0x74))(uVar13,param_2,param_3,local_a0,param_5,param_6,param_7);
LAB_c0884550:
      if (iVar7 != 0) break;
    }
    goto LAB_c0884560;
  case 0x1b0008:
    pcVar3 = *(code **)(iVar12 + 0x4c);
    goto LAB_c0883ec4;
  case 0x1b000c:
    if ((*(uint *)(iVar7 + 0x68) & 0x30) == 0x20) goto LAB_c0884560;
    pcVar3 = *(code **)(iVar12 + 0x38);
LAB_c0883eec:
    (*pcVar3)(uVar13);
    break;
  case 0x1b0010:
    if ((*(uint *)(iVar7 + 0x68) & 0x30) != 0x20) {
      pcVar3 = *(code **)(iVar12 + 0x34);
      goto LAB_c0883eec;
    }
    goto LAB_c0884560;
  case 0x1b0014:
    if ((*(uint *)(iVar7 + 0x68) & 0x3000) != 0x2000) {
      pcVar3 = *(code **)(iVar12 + 0x40);
      goto LAB_c0883eec;
    }
    goto LAB_c0884560;
  case 0x1b0018:
    if ((*(uint *)(iVar7 + 0x68) & 0x3000) != 0x2000) {
      pcVar3 = *(code **)(iVar12 + 0x3c);
      goto LAB_c0883eec;
    }
    goto LAB_c0884560;
  case 0x1b001c:
    if ((*(uint *)(iVar7 + 0x94) & 2) != 0) {
      uVar11 = *(uint *)(iVar7 + 0x94) | 0xc;
LAB_c0883f64:
      *(uint *)(iVar7 + 0x94) = uVar11;
    }
    break;
  case 0x1b0020:
    if ((*(uint *)(iVar7 + 0x94) & 2) != 0) {
      uVar11 = *(uint *)(iVar7 + 0x94) & 0xfffffff3;
      goto LAB_c0883f64;
    }
    break;
  case 0x1b0024:
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0884560;
    *param_5 = local_9c[5];
    *param_7 = 4;
    break;
  case 0x1b0028:
    if ((local_a0 < 4) || (param_3 == (uint *)0x0)) goto LAB_c0884560;
    uVar11 = *param_3;
    lpCriticalSection = (LPCRITICAL_SECTION)(local_9c + 8);
    EnterCriticalSection(lpCriticalSection);
    piVar4[5] = uVar11;
    piVar4[7] = 1;
    EventModify(piVar4[4],3);
    uVar11 = 0;
    for (piVar4 = *(int **)(iVar7 + 0xe4); piVar4 != (int *)(iVar7 + 0xe4); piVar4 = (int *)*piVar4)
    {
      uVar11 = piVar4[-8] | uVar11;
    }
    *(uint *)(iVar7 + 0x98) = uVar11;
    LeaveCriticalSection(lpCriticalSection);
    break;
  case 0x1b002c:
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0884560;
    local_a0 = 0;
    iVar7 = FUN_c0883890(local_9c,&local_a0);
    *param_5 = local_a0;
    *param_7 = 4;
    bVar10 = iVar7 != 0;
    break;
  case 0x1b0030:
    if (((param_6 < 0x10) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0884560;
    memset(local_8c,0,0xc);
    local_90 = InterlockedExchange((LONG *)(iVar7 + 0x104),0);
    uVar11 = (**(code **)(iVar12 + 0x58))(uVar13,local_8c);
    uVar6 = *(uint *)(iVar7 + 0xa0);
    uVar5 = *(uint *)(iVar7 + 0x9c);
    if (uVar6 < uVar5) {
      iVar12 = *(int *)(iVar7 + 0xa4) - uVar5;
    }
    else {
      iVar12 = -uVar5;
    }
    iVar2 = *(int *)(iVar7 + 0x94);
    uVar5 = *(uint *)(iVar7 + 0x58);
    *param_5 = uVar11 | local_90;
    param_5[1] = (iVar2 << 1 ^ local_8c[0]) & 0x18 ^ local_8c[0];
    param_5[2] = uVar6 + iVar12;
    param_5[3] = uVar5;
    *param_7 = 0x10;
    break;
  case 0x1b0034:
    local_9c = (int *)0x0;
    if (((param_6 < 4) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0884560;
    (**(code **)(iVar12 + 0x60))(uVar13,&local_9c);
    *param_7 = 4;
    *param_5 = (uint)local_9c;
    break;
  case 0x1b0038:
    if (((param_6 < 0x40) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0884560;
    uVar8 = 0x40;
    memset(auStack_70,0,0x40);
    (**(code **)(iVar12 + 100))(uVar13,auStack_70);
    _Src = auStack_70;
    _Size = 0x40;
LAB_c08841f0:
    memcpy(param_5,_Src,_Size);
    *param_7 = uVar8;
    break;
  case 0x1b003c:
    if ((local_a0 < 0x14) || (param_3 == (uint *)0x0)) goto LAB_c0884560;
    *(uint *)(iVar7 + 0x7c) = *param_3;
    *(uint *)(iVar7 + 0x80) = param_3[1];
    *(uint *)(iVar7 + 0x84) = param_3[2];
    *(uint *)(iVar7 + 0x88) = param_3[3];
    *(uint *)(iVar7 + 0x8c) = param_3[4];
    (**(code **)(iVar12 + 0x70))(uVar13);
    break;
  case 0x1b0040:
    if (((param_6 < 0x14) || (param_5 == (uint *)0x0)) || (param_7 == (undefined4 *)0x0))
    goto LAB_c0884560;
    memset(param_5,0,0x14);
    *param_5 = *(uint *)(iVar7 + 0x7c);
    param_5[1] = *(uint *)(iVar7 + 0x80);
    param_5[2] = *(uint *)(iVar7 + 0x84);
    param_5[3] = *(uint *)(iVar7 + 0x88);
    param_5[4] = *(uint *)(iVar7 + 0x8c);
    *param_7 = 0x14;
    break;
  case 0x1b0044:
    if ((local_a0 < 4) || (param_3 == (uint *)0x0)) goto LAB_c0884560;
    uVar11 = *param_3;
    (**(code **)(iVar12 + 0x68))(uVar13,uVar11);
    if ((uVar11 & 8) != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(iVar7 + 0xb0));
      *(undefined4 *)(iVar7 + 0x9c) = *(undefined4 *)(iVar7 + 0xa0);
      memset(*(void **)(iVar7 + 0xac),0,*(size_t *)(iVar7 + 0xa4));
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar7 + 0xb0));
      if (((*(uint *)(iVar7 + 0x68) & 0x200) != 0) &&
         (uVar5 = *(uint *)(iVar7 + 0x94), (uVar5 & 8) != 0)) {
        *(uint *)(iVar7 + 0x94) = uVar5 & 0xfffffff7;
        if ((*(uint *)(iVar7 + 0x68) & 0x80) == 0) {
          *(uint *)(iVar7 + 0x94) = uVar5 & 0xfffffff3;
        }
        (**(code **)(iVar12 + 0x54))(*(undefined4 *)(iVar7 + 0x2c),*(undefined1 *)(iVar7 + 0x75));
      }
      if (((*(uint *)(iVar7 + 0x94) & 0x20) != 0) && ((*(uint *)(iVar7 + 0x68) & 0x3000) == 0x2000))
      {
        *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) & 0xffffffdf;
        (**(code **)(iVar12 + 0x40))(*(undefined4 *)(iVar7 + 0x2c));
      }
      if (((*(uint *)(iVar7 + 0x94) & 0x10) != 0) && ((*(uint *)(iVar7 + 0x68) & 0x30) == 0x20)) {
        *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) & 0xffffffef;
        (**(code **)(iVar12 + 0x38))(uVar13);
      }
    }
    if ((uVar11 & 2) != 0) {
      *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) | 0x40;
      EventModify(*(undefined4 *)(iVar7 + 0x34),1);
    }
    if ((uVar11 & 1) != 0) {
      *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) | 0x80;
      EventModify(*(undefined4 *)(iVar7 + 0x3c),3);
    }
    break;
  case 0x1b0048:
    DVar1 = 0x32;
    goto LAB_c0884564;
  case 0x1b004c:
    if ((local_a0 == 0) || (param_3 == (uint *)0x0)) goto LAB_c0884560;
    (**(code **)(iVar12 + 0x54))(uVar13,(char)*param_3);
    break;
  case 0x1b0050:
    if (((0x1b < param_6) && (param_5 != (uint *)0x0)) && (param_7 != (undefined4 *)0x0)) {
      _Src = (undefined1 *)(iVar7 + 0x60);
      uVar8 = 0x1c;
      _Size = 0x1c;
      goto LAB_c08841f0;
    }
    goto LAB_c0884560;
  case 0x1b0054:
    if ((0x1b < local_a0) && (param_3 != (uint *)0x0)) {
      memcpy(&local_90,param_3,0x1c);
      iVar7 = FUN_c0882b9c(iVar7,&local_90,1);
      goto LAB_c0884550;
    }
LAB_c0884560:
    DVar1 = 0x57;
LAB_c0884564:
    SetLastError(DVar1);
LAB_c088456c:
    bVar10 = false;
    break;
  case 0x1b0058:
    iVar7 = (**(code **)(iVar12 + 0x44))(uVar13,*(undefined4 *)(iVar7 + 100));
    if (iVar7 != 0) break;
    goto LAB_c088456c;
  case 0x1b005c:
    pcVar3 = *(code **)(iVar12 + 0x48);
LAB_c0883ec4:
    (*pcVar3)(uVar13);
  }
  InterlockedDecrement(local_98);
LAB_c0883c88:
  FUN_c088566c(local_30);
  return bVar10;
}



/* c08845cc FUN_c08845cc */

/* Boundary evidence: original MIPS .pdata c08845cc..c08849bf. Semantic name remains unreviewed. */

void FUN_c08845cc(int param_1)

{
  bool bVar1;
  uint uVar2;
  byte *_Dst;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint local_40 [2];
  undefined1 auStack_38 [16];
  uint local_28;
  
  local_28 = DAT_c088618c;
  iVar7 = *(int *)(*(int *)(param_1 + 0x28) + 8);
  uVar8 = *(undefined4 *)(param_1 + 0x2c);
  bVar1 = false;
  local_40[0] = 0;
  if (((*(uint *)(param_1 + 0x94) & 1) != 0) || (*(int *)(param_1 + 0x30) == 0)) {
    EventModify(*(undefined4 *)(param_1 + 0x38),3);
                    /* WARNING: Subroutine does not return */
    ExitThread(0);
  }
  if (*(int *)(param_1 + 0x100) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(param_1 + 0x100) + 0xc));
  }
  uVar2 = (**(code **)(iVar7 + 0x14))(uVar8);
  if (uVar2 != 0) {
    do {
      if ((uVar2 & 2) != 0) {
        uVar4 = *(uint *)(param_1 + 0xa0);
        uVar5 = *(uint *)(param_1 + 0x9c);
        if (uVar5 == 0) {
          iVar3 = *(int *)(param_1 + 0xa4) - uVar4;
LAB_c08846ac:
          local_40[0] = iVar3 - 1;
        }
        else {
          local_40[0] = *(int *)(param_1 + 0xa4) - uVar4;
          if (uVar4 < uVar5) {
            iVar3 = uVar5 - uVar4;
            goto LAB_c08846ac;
          }
        }
        if (local_40[0] == 0) {
          local_40[0] = 0x10;
          (**(code **)(iVar7 + 0x18))(uVar8,auStack_38,local_40);
          uVar4 = local_40[0];
          local_40[0] = 0;
          *(uint *)(param_1 + 0x48) = uVar4 + *(int *)(param_1 + 0x48);
          do {
            uVar5 = *(uint *)(param_1 + 0x104);
            uVar4 = InterlockedCompareExchange((LONG *)(param_1 + 0x104),uVar5 | 1,uVar5);
          } while (uVar5 != uVar4);
        }
        else {
          iVar3 = (**(code **)(iVar7 + 0x18))(uVar8,*(int *)(param_1 + 0xac) + uVar4);
          *(int *)(param_1 + 0x4c) = iVar3 + *(int *)(param_1 + 0x4c);
        }
        uVar4 = local_40[0];
        if (((*(uint *)(param_1 + 0x94) & 2) != 0) && (uVar5 = 0, local_40[0] != 0)) {
          do {
            _Dst = (byte *)(*(int *)(param_1 + 0xac) + uVar5 + *(int *)(param_1 + 0xa0));
            if ((uint)*_Dst == (int)*(char *)(param_1 + 0x76)) {
              *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 4;
              memmove(_Dst,_Dst + 1,uVar4 - uVar5);
              uVar4 = local_40[0] - 1;
              local_40[0] = uVar4;
            }
            else if ((uint)*_Dst == (int)*(char *)(param_1 + 0x75)) {
              *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffffffb;
              memmove(_Dst,_Dst + 1,uVar4 - uVar5);
              uVar2 = uVar2 | 4;
              uVar4 = local_40[0] - 1;
              local_40[0] = uVar4;
            }
            else {
              uVar5 = uVar5 + 1;
            }
          } while (uVar5 < uVar4);
        }
        uVar6 = *(uint *)(param_1 + 0xa4);
        uVar5 = *(int *)(param_1 + 0xa0) + uVar4;
        *(uint *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + uVar4;
        if (uVar6 <= uVar5) {
          uVar5 = (*(int *)(param_1 + 0xa0) - uVar6) + uVar4;
        }
        *(uint *)(param_1 + 0xa0) = uVar5;
        if (uVar4 != 0) {
          bVar1 = true;
        }
        uVar4 = *(uint *)(param_1 + 0x9c);
        if (uVar5 < uVar4) {
          iVar3 = uVar6 - uVar4;
        }
        else {
          iVar3 = -uVar4;
        }
        if (uVar6 - (uVar5 + iVar3) <= (uint)*(ushort *)(param_1 + 0x70)) {
          if (((*(uint *)(param_1 + 0x68) & 0x30) == 0x20) &&
             ((*(uint *)(param_1 + 0x94) & 0x10) == 0)) {
            *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x10;
            (**(code **)(iVar7 + 0x34))(uVar8);
          }
          if (((*(uint *)(param_1 + 0x68) & 0x3000) == 0x2000) &&
             ((*(uint *)(param_1 + 0x94) & 0x20) == 0)) {
            *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0x20;
            (**(code **)(iVar7 + 0x3c))(uVar8);
          }
          if (((*(uint *)(param_1 + 0x68) & 0x200) != 0) && ((*(uint *)(param_1 + 0x94) & 8) == 0))
          {
            (**(code **)(iVar7 + 0x54))(uVar8,*(undefined1 *)(param_1 + 0x76));
            uVar4 = *(uint *)(param_1 + 0x94);
            *(uint *)(param_1 + 0x94) = uVar4 | 8;
            if ((*(uint *)(param_1 + 0x68) & 0x80) == 0) {
              *(uint *)(param_1 + 0x94) = uVar4 | 0xc;
            }
          }
        }
      }
      if ((uVar2 & 4) != 0) {
        FUN_c0882988(param_1);
      }
      if ((uVar2 & 8) != 0) {
        (**(code **)(iVar7 + 0x20))(uVar8);
      }
      if ((uVar2 & 1) != 0) {
        (**(code **)(iVar7 + 0x24))(uVar8);
      }
      uVar2 = (**(code **)(iVar7 + 0x14))(uVar8);
    } while (uVar2 != 0);
    if (bVar1) {
      EventModify(*(undefined4 *)(param_1 + 0x34),3);
      FUN_c0883a70(param_1,1);
    }
  }
  if (*(int *)(param_1 + 0x100) != 0) {
    InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x100) + 0xc));
  }
  FUN_c088566c(local_28);
  return;
}



/* c08849c0 FUN_c08849c0 */

/* Boundary evidence: original MIPS .pdata c08849c0..c0884a6f. Semantic name remains unreviewed. */

undefined4 FUN_c08849c0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((**(uint **)(param_1 + 0x28) & 3) != 0) {
    iVar2 = *(int *)(param_1 + 0x40);
    while (iVar2 == 0) {
      Sleep(0x14);
      iVar2 = *(int *)(param_1 + 0x40);
    }
  }
  uVar1 = *(uint *)(param_1 + 0x94);
  while ((uVar1 & 1) == 0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x30),0xffffffff);
    FUN_c08845cc(param_1);
    InterruptDone(*(undefined4 *)(*(int *)(param_1 + 0x28) + 4));
    uVar1 = *(uint *)(param_1 + 0x94);
  }
  return 0;
}



/* c0884a70 FUN_c0884a70 */

/* Boundary evidence: original MIPS .pdata c0884a70..c0884b07. Semantic name remains unreviewed. */

undefined4 FUN_c0884a70(LPVOID param_1)

{
  int iVar1;
  HANDLE pvVar2;
  
  iVar1 = InterruptInitialize(*(undefined4 *)(*(int *)((int)param_1 + 0x28) + 4),
                              *(undefined4 *)((int)param_1 + 0x30),0,0);
  if (iVar1 != 0) {
    InterruptDone(*(undefined4 *)(*(int *)((int)param_1 + 0x28) + 4));
    *(uint *)((int)param_1 + 0x94) = *(uint *)((int)param_1 + 0x94) & 0xfffffffe;
    *(undefined4 *)((int)param_1 + 0x40) = 0;
    pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c08849c0,param_1,0,(LPDWORD)0x0);
    *(HANDLE *)((int)param_1 + 0x40) = pvVar2;
    if (pvVar2 != (HANDLE)0x0) {
      return 1;
    }
  }
  return 0;
}



/* c0884b08 COM_Init */

/* Boundary evidence: original MIPS .pdata c0884b08..c0884de3. Semantic name remains unreviewed. */

LPCRITICAL_SECTION COM_Init(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  PRTL_CRITICAL_SECTION_DEBUG p_Var1;
  HANDLE pvVar2;
  HKEY hKey;
  LSTATUS LVar3;
  ULONG_PTR UVar4;
  int iVar5;
  HLOCAL pvVar6;
  HANDLE *ppvVar7;
  SIZE_T uBytes;
  uint *puVar8;
  DWORD local_28;
  DWORD DStack_24;
  BYTE local_20 [8];
  
                    /* 0x4b08  4  COM_Init */
  local_28 = 4;
  lpCriticalSection = LocalAlloc(0x40,0x108);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    memset(lpCriticalSection,0,0x108);
    ppvVar7 = &lpCriticalSection[9].OwningThread;
    lpCriticalSection[9].LockSemaphore = ppvVar7;
    *ppvVar7 = ppvVar7;
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[9].SpinCount);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection->SpinCount);
    InitializeCriticalSection(lpCriticalSection);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[7].RecursionCount);
    InitializeCriticalSection((LPCRITICAL_SECTION)&lpCriticalSection[8].LockSemaphore);
    lpCriticalSection[5].LockCount = 0xfa;
    lpCriticalSection[10].LockSemaphore = (HANDLE)0x0;
    lpCriticalSection[6].RecursionCount = 0;
    lpCriticalSection[5].RecursionCount = 10;
    lpCriticalSection[5].OwningThread = (HANDLE)0x64;
    lpCriticalSection[5].LockSemaphore = (HANDLE)0x0;
    lpCriticalSection[5].SpinCount = 0;
    p_Var1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].DebugInfo = p_Var1;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].RecursionCount = (LONG)pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].OwningThread = pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    lpCriticalSection[2].LockCount = (LONG)pvVar2;
    if ((((lpCriticalSection[2].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) &&
         (lpCriticalSection[2].RecursionCount != 0)) &&
        (lpCriticalSection[2].OwningThread != (HANDLE)0x0)) &&
       ((pvVar2 != (HANDLE)0x0 && (hKey = (HKEY)OpenDeviceKey(param_1), hKey != (HKEY)0x0)))) {
      local_28 = 4;
      LVar3 = RegQueryValueExW(hKey,L"DeviceArrayIndex",(LPDWORD)0x0,&DStack_24,local_20,&local_28);
      if (LVar3 == 0) {
        local_28 = 4;
        LVar3 = RegQueryValueExW(hKey,L"Priority256",(LPDWORD)0x0,&DStack_24,
                                 (LPBYTE)&lpCriticalSection[2].SpinCount,&local_28);
        if (LVar3 != 0) {
          lpCriticalSection[2].SpinCount = 0x67;
        }
        RegCloseKey(hKey);
        pvVar2 = (HANDLE)FUN_c0881514();
        lpCriticalSection[1].LockSemaphore = pvVar2;
        if (pvVar2 != (HANDLE)0x0) {
          UVar4 = (*(code *)**(undefined4 **)((int)pvVar2 + 8))(param_1,lpCriticalSection,pvVar2);
          lpCriticalSection[1].SpinCount = UVar4;
          if (UVar4 != 0) {
            iVar5 = (**(code **)(*(int *)((int)lpCriticalSection[1].LockSemaphore + 8) + 0x28))
                              (UVar4);
            uBytes = iVar5 << 1;
            if (uBytes < 0x801) {
              uBytes = 0x800;
            }
            lpCriticalSection[6].SpinCount = uBytes;
            pvVar6 = LocalAlloc(0x40,uBytes);
            lpCriticalSection[7].LockCount = (LONG)pvVar6;
            if (pvVar6 != (HLOCAL)0x0) {
              puVar8 = lpCriticalSection[1].LockSemaphore;
              lpCriticalSection[6].OwningThread = (HANDLE)0x0;
              lpCriticalSection[6].LockSemaphore = (HANDLE)0x0;
              if (((*puVar8 & 1) == 0) || (iVar5 = FUN_c0884a70(lpCriticalSection), iVar5 != 0)) {
                (**(code **)(*(int *)((int)lpCriticalSection[1].LockSemaphore + 8) + 4))(UVar4);
                return lpCriticalSection;
              }
            }
          }
        }
      }
      else {
        RegCloseKey(hKey);
      }
    }
    COM_Deinit(lpCriticalSection);
  }
  return (LPCRITICAL_SECTION)0x0;
}



/* c0884de4 COM_Open */

/* Boundary evidence: original MIPS .pdata c0884de4..c088511f. Semantic name remains unreviewed. */

undefined4 * COM_Open(LPVOID param_1,uint param_2,undefined4 param_3)

{
  undefined4 *hMem;
  HANDLE pvVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar7;
  
                    /* 0x4de4  5  COM_Open */
  puVar7 = *(uint **)((int)param_1 + 0x28);
  if ((param_2 & 0x100) != 0) {
    param_2 = param_2 & 0xfffffff;
  }
  if (((param_2 & 0xc0000000) != 0) && (*(int *)((int)param_1 + 0x100) != 0)) {
    SetLastError(0xc);
    return (undefined4 *)0x0;
  }
  hMem = LocalAlloc(0x40,0x3c);
  if (hMem == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *hMem = param_1;
  hMem[3] = 0;
  hMem[1] = param_2;
  hMem[2] = param_3;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  hMem[4] = pvVar1;
  hMem[5] = 0;
  hMem[6] = 0;
  hMem[7] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(hMem + 8));
  if ((param_2 & 0xc0000000) != 0) {
    *(undefined4 **)((int)param_1 + 0x100) = hMem;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0xec);
  EnterCriticalSection(lpCriticalSection);
  piVar2 = (int *)((int)param_1 + 0xe4);
  iVar3 = *piVar2;
  piVar6 = hMem + 0xd;
  *piVar6 = iVar3;
  hMem[0xe] = piVar2;
  *(int **)(iVar3 + 4) = piVar6;
  *piVar2 = (int)piVar6;
  if ((hMem[1] & 0x100) == 0) {
    if (*(int *)((int)param_1 + 0x90) == 0) {
      if (((**(uint **)((int)param_1 + 0x28) & 2) != 0) &&
         (iVar3 = FUN_c0884a70(param_1), iVar3 == 0)) {
LAB_c0885020:
        SetLastError(0x6e);
        if (hMem == *(undefined4 **)((int)param_1 + 0x100)) {
          *(undefined4 *)((int)param_1 + 0x100) = 0;
        }
        *(int *)hMem[0xe] = *piVar6;
        *(undefined4 *)(*piVar6 + 4) = hMem[0xe];
        LeaveCriticalSection(lpCriticalSection);
        if ((HANDLE)hMem[4] != (HANDLE)0x0) {
          CloseHandle((HANDLE)hMem[4]);
        }
        DeleteCriticalSection((LPCRITICAL_SECTION)(hMem + 8));
        LocalFree(hMem);
        return (undefined4 *)0x0;
      }
      *(undefined4 *)((int)param_1 + 0x60) = 0x1c;
      uVar4 = *(uint *)((int)param_1 + 0xa4);
      *(undefined4 *)((int)param_1 + 100) = 0x2580;
      *(uint *)((int)param_1 + 0x68) = *(uint *)((int)param_1 + 0x68) & 0xffff9011 | 0x1011;
      uVar5 = uVar4 - (uVar4 >> 3 & 0xffff);
      *(short *)((int)param_1 + 0x70) = (short)(uVar4 >> 3);
      *(undefined4 *)((int)param_1 + 0x50) = 0;
      *(undefined4 *)((int)param_1 + 0x54) = 0;
      *(undefined4 *)((int)param_1 + 0x58) = 0;
      *(undefined4 *)((int)param_1 + 0x48) = 0;
      *(undefined4 *)((int)param_1 + 0x4c) = 0;
      *(short *)((int)param_1 + 0x6e) = (short)(uVar4 >> 1);
      if (uVar5 <= (uVar4 >> 1 & 0xffff)) {
        *(short *)((int)param_1 + 0x6e) = (short)uVar5 + -1;
      }
      *(undefined1 *)((int)param_1 + 0x72) = 8;
      *(undefined1 *)((int)param_1 + 0x76) = 0x13;
      *(undefined1 *)((int)param_1 + 0x75) = 0x11;
      *(undefined1 *)((int)param_1 + 0x73) = 0;
      *(undefined1 *)((int)param_1 + 0x74) = 0;
      *(undefined1 *)((int)param_1 + 0x77) = 0xd;
      *(undefined1 *)((int)param_1 + 0x78) = 0xd;
      *(undefined1 *)((int)param_1 + 0x79) = 0xd;
      *(uint *)((int)param_1 + 0x94) = *(uint *)((int)param_1 + 0x94) & 0xffffffc3;
      FUN_c0882b9c((int)param_1,(undefined4 *)((int)param_1 + 0x60),0);
      (**(code **)(puVar7[2] + 0x70))(*(undefined4 *)((int)param_1 + 0x2c),(int)param_1 + 0x7c);
      iVar3 = (**(code **)(puVar7[2] + 0xc))(*(undefined4 *)((int)param_1 + 0x2c));
      if (iVar3 == 0) goto LAB_c0885020;
      (**(code **)(puVar7[2] + 0x68))(*(undefined4 *)((int)param_1 + 0x2c),8);
      memset(*(void **)((int)param_1 + 0xac),0,*(size_t *)((int)param_1 + 0xa4));
      if ((*puVar7 & 3) != 0) {
        CeSetThreadPriority(*(undefined4 *)((int)param_1 + 0x40),
                            *(undefined4 *)((int)param_1 + 0x44));
      }
      *(undefined4 *)((int)param_1 + 0x9c) = 0;
      *(undefined4 *)((int)param_1 + 0xa0) = 0;
    }
    *(int *)((int)param_1 + 0x90) = *(int *)((int)param_1 + 0x90) + 1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return hMem;
}



/* c0885120 COM_Write */

/* Boundary evidence: original MIPS .pdata c0885120..c088537b. Semantic name remains unreviewed. */

ULONG_PTR COM_Write(undefined4 *param_1,int param_2,HANDLE param_3)

{
  int iVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  HANDLE *lpCriticalSection_00;
  ULONG_PTR UVar4;
  HANDLE local_30 [2];
  
                    /* 0x5120  10  COM_Write */
  lpCriticalSection = (LPCRITICAL_SECTION)*param_1;
  local_30[0] = (HANDLE)0x0;
  if ((lpCriticalSection == (LPCRITICAL_SECTION)0x0) ||
     (lpCriticalSection[6].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0)) {
    DVar2 = 6;
  }
  else if ((param_1[1] & 0x40000000) == 0) {
    DVar2 = 0xc;
  }
  else {
    if ((param_2 != 0) && (param_3 != (HANDLE)0x0)) {
      iVar1 = CeAllocAsynchronousBuffer(local_30,param_2,param_3,4);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
      if (local_30[0] == (HANDLE)0x0) {
        return 0xffffffff;
      }
      InterlockedIncrement(param_1 + 3);
      UVar4 = lpCriticalSection[1].SpinCount;
      iVar1 = *(int *)((int)lpCriticalSection[1].LockSemaphore + 8);
      EnterCriticalSection(lpCriticalSection);
      lpCriticalSection_00 = &lpCriticalSection[8].LockSemaphore;
      EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      lpCriticalSection[6].LockCount = lpCriticalSection[6].LockCount & 0xffffff7f;
      WaitForSingleObject(lpCriticalSection[2].OwningThread,0);
      pvVar3 = lpCriticalSection[2].OwningThread;
      lpCriticalSection[8].OwningThread = local_30[0];
      lpCriticalSection[8].RecursionCount = (LONG)param_3;
      lpCriticalSection[8].LockCount = 0;
      lpCriticalSection[3].SpinCount = 0;
      lpCriticalSection[3].LockSemaphore = param_3;
      EventModify(pvVar3,2);
      LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      FUN_c0882988((int)lpCriticalSection);
      DVar2 = (int)lpCriticalSection[5].LockSemaphore * (int)param_3 +
              lpCriticalSection[5].SpinCount;
      if (DVar2 == 0) {
        DVar2 = 0xffffffff;
      }
      WaitForSingleObject(lpCriticalSection[2].OwningThread,DVar2);
      if (((lpCriticalSection[6].LockCount & 0x80U) == 0) &&
         (lpCriticalSection[6].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0)) {
        SetLastError(6);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      lpCriticalSection[8].OwningThread = (HANDLE)0x0;
      lpCriticalSection[8].RecursionCount = 0;
      lpCriticalSection[3].LockSemaphore = (HANDLE)0x0;
      lpCriticalSection[8].LockCount = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection_00);
      LeaveCriticalSection(lpCriticalSection);
      FUN_c0883a70((int)lpCriticalSection,4);
      if ((lpCriticalSection[4].RecursionCount & 0x3000U) == 0x3000) {
        (**(code **)(iVar1 + 0x3c))(UVar4);
      }
      InterlockedDecrement(param_1 + 3);
      if (local_30[0] != (HANDLE)0x0) {
        CeFreeAsynchronousBuffer(local_30[0],param_2,param_3,4);
      }
      return lpCriticalSection[3].SpinCount;
    }
    DVar2 = 0x57;
  }
  SetLastError(DVar2);
  return 0xffffffff;
}



/* c08855ec FUN_c08855ec */

/* Boundary evidence: original MIPS .pdata c08855ec..c088563f. Semantic name remains unreviewed. */

void FUN_c08855ec(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c088566c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0885640 FUN_c0885640 */

/* Boundary evidence: original MIPS .pdata c0885640..c088566b. Semantic name remains unreviewed. */

undefined4 FUN_c0885640(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c08855ec(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c088566c FUN_c088566c */

/* Boundary evidence: original MIPS .pdata c088566c..c08856b3. Semantic name remains unreviewed. */

void FUN_c088566c(uint param_1)

{
  if ((param_1 == DAT_c088618c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


