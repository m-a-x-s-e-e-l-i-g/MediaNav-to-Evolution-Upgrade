/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c085205c DllEntry */

/* Boundary evidence: original MIPS .pdata c085205c..c08520df. Semantic name remains unreviewed. */

undefined4 DllEntry(HMODULE param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x205c  1  DllEntry */
  uVar2 = 1;
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    iVar1 = FUN_c08552b4();
    if (iVar1 != 0) {
      iVar1 = FUN_c0855530();
      if (-1 < iVar1) {
        return 1;
      }
      FUN_c08552f4();
    }
    uVar2 = 0;
  }
  else if (param_2 == 0) {
    SDP_IOControl();
    FUN_c08552f4();
  }
  return uVar2;
}



/* c08520e0 SDP_Deinit */

/* Boundary evidence: original MIPS .pdata c08520e0..c085212f. Semantic name remains unreviewed. */

undefined4 SDP_Deinit(int param_1)

{
                    /* 0x20e0  3  SDP_Deinit */
  FUN_c08555f0();
  if ((param_1 != 0) && (*(void **)(param_1 + 0x4c) != (void *)0x0)) {
    free(*(void **)(param_1 + 0x4c));
  }
  FUN_c08555a0();
  return 1;
}



/* c0852130 SDP_Init */

/* Boundary evidence: original MIPS .pdata c0852130..c085236b. Semantic name remains unreviewed. */

int SDP_Init(LPCWSTR param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *_Dst;
  LSTATUS LVar3;
  int *piVar4;
  int local_28 [2];
  HKEY local_20;
  int local_1c;
  int local_18 [2];
  
                    /* 0x2130  5  SDP_Init */
  local_18[0] = 0;
  local_1c = 0;
  uVar1 = SDP_Close();
  iVar2 = FUN_c0855558(uVar1,local_28);
  if ((-1 < iVar2) && (_Dst = malloc(0x370), _Dst != (void *)0x0)) {
    memset(_Dst,0,0x370);
    *(void **)(local_28[0] + 0x4c) = _Dst;
    piVar4 = *(int **)(local_28[0] + 0x4c);
    LVar3 = FUN_c0855320(param_1,(LPBYTE)(piVar4 + 0x54),0x200);
    if (LVar3 == 0) {
      piVar4[0x34] = 1;
      piVar4[0xc] = 1;
      piVar4[0x26] = 1;
      piVar4[0x1a] = 0;
      LVar3 = RegOpenKeyExW((HKEY)0x80000002,(LPCWSTR)(piVar4 + 0x54),0,0xf003f,&local_20);
      if (LVar3 == 0) {
        local_28[1] = 4;
        RegQueryValueExW(local_20,L"Disable8BitBus",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_1c,
                         (LPDWORD)(local_28 + 1));
        if (local_1c != 0) {
          piVar4[0x34] = 0;
        }
        local_28[1] = 4;
        RegQueryValueExW(local_20,L"PIOMode",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_18,
                         (LPDWORD)(local_28 + 1));
        if (local_18[0] != 0) {
          piVar4[0xc] = 0;
          piVar4[0x26] = 0;
        }
        RegCloseKey(local_20);
      }
      iVar2 = InterruptConnect(0,0,0x59,0);
      piVar4[0xd4] = iVar2;
      if (iVar2 != 0) {
        *piVar4 = local_28[0];
        wcsncpy((wchar_t *)(local_28[0] + 4),L"Au1100 SDIO",0xf);
        *(code **)(local_28[0] + 0x44) = FUN_c0854ee4;
        *(code **)(local_28[0] + 0x48) = FUN_c085498c;
        *(code **)(local_28[0] + 0x38) = FUN_c0852bbc;
        *(code **)(local_28[0] + 0x40) = FUN_c0853264;
        *(code **)(local_28[0] + 0x3c) = FUN_c0854a7c;
        iVar2 = FUN_c08555c8();
        if (-1 < iVar2) {
          return local_28[0];
        }
        FUN_c08555a0();
      }
    }
  }
  return 0;
}



/* c085236c SDP_PowerDown */

/* Boundary evidence: original MIPS .pdata c085236c..c08523e7. Semantic name remains unreviewed. */

void SDP_PowerDown(void)

{
  int iVar1;
  int iVar2;
  
                    /* 0x236c  7  SDP_PowerDown */
  iVar2 = 0;
  iVar1 = SDP_Close();
  if (0 < iVar1) {
    do {
      FUN_c0855668();
      SDP_IOControl();
      iVar2 = iVar2 + 1;
      iVar1 = SDP_Close();
    } while (iVar2 < iVar1);
  }
  return;
}



/* c08523e8 SDP_PowerUp */

/* Boundary evidence: original MIPS .pdata c08523e8..c0852493. Semantic name remains unreviewed. */

void SDP_PowerUp(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
                    /* 0x23e8  8  SDP_PowerUp */
  iVar4 = *(int *)(param_1 + 0x4c);
  iVar3 = 0;
  iVar1 = SDP_Close();
  if (0 < iVar1) {
    puVar2 = (undefined4 *)(iVar4 + 0x1c);
    do {
      FUN_c0855668();
      SDP_IOControl();
      *puVar2 = 1;
      if (puVar2[0x12] != 0) {
        SetInterruptEvent(puVar2[10]);
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 0x1a;
      iVar1 = SDP_Close();
    } while (iVar3 < iVar1);
  }
  return;
}



/* c0852494 FUN_c0852494 */

/* Boundary evidence: original MIPS .pdata c0852494..c08526c3. Semantic name remains unreviewed. */

void FUN_c0852494(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 4;
  do {
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
  } while ((uVar1 & 0x20) != 0);
  WRITE_REGISTER_ULONG(param_1[1] + 0x18,0xffffffff);
  EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
  uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
  WRITE_REGISTER_ULONG(param_1[1] + 8,uVar1 & 0xff8cffff);
  param_1[7] = param_1[7] & 0xff8cffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
  WRITE_REGISTER_ULONG(param_1[1] + 0x18,0xffffffff);
  do {
    WRITE_REGISTER_ULONG(param_1[1] + 0x24,DAT_c0856164);
    WRITE_REGISTER_ULONG(param_1[1] + 0x20,0x10d01);
    do {
      uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x20);
    } while ((uVar1 & 1) != 0);
    do {
      uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
    } while ((uVar1 & 0x10) != 0);
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
    if ((uVar1 & 0x120000) == 0) {
      READ_REGISTER_ULONG(param_1[1] + 0x34);
    }
    WRITE_REGISTER_ULONG(param_1[1] + 0x18,0xffffffff);
    WRITE_REGISTER_ULONG(param_1[1] + 0x18,0xffffffff);
    WRITE_REGISTER_ULONG(param_1[1] + 0x24,param_2);
    WRITE_REGISTER_ULONG(param_1[1] + 0x20,0x11701);
    do {
      uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x20);
    } while ((uVar1 & 1) != 0);
    do {
      uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
    } while ((uVar1 & 0x10) != 0);
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x34);
    uVar2 = READ_REGISTER_ULONG(param_1[1] + 0x18);
    if ((uVar2 & 0x120000) != 0) {
      uVar1 = 0;
    }
    WRITE_REGISTER_ULONG(param_1[1] + 0x18,0xffffffff);
    WRITE_REGISTER_ULONG(param_1[1] + 0x18,0xffffffff);
    iVar3 = iVar3 + -1;
  } while ((((uVar1 & 0x400000) != 0) || (uVar1 == 0)) && (iVar3 != 0));
  return;
}



/* c08526c4 FUN_c08526c4 */

/* Boundary evidence: original MIPS .pdata c08526c4..c085280b. Semantic name remains unreviewed. */

void FUN_c08526c4(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 == 0) {
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x10);
    uVar2 = READ_REGISTER_ULONG(param_1[1] + 8);
    uVar2 = uVar2 & 0x1ff;
  }
  else {
    uVar1 = 0x400;
  }
  WRITE_REGISTER_ULONG(param_1[1] + 0xc,0);
  WRITE_REGISTER_ULONG(param_1[1] + 0xc,1);
  WRITE_REGISTER_ULONG(param_1[1] + 0xc,3);
  WRITE_REGISTER_ULONG(param_1[1] + 0x10,uVar1 | 1);
  WRITE_REGISTER_ULONG(param_1[1] + 0x38,0x1e0000);
  WRITE_REGISTER_ULONG(param_1[1] + 8,uVar2 | 0x200);
  EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
  READ_REGISTER_ULONG(param_1[1] + 8);
  WRITE_REGISTER_ULONG(param_1[1] + 8,0);
  param_1[7] = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
  WRITE_REGISTER_ULONG(param_1[1] + 0x18,0xffffffff);
  EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
  uVar2 = READ_REGISTER_ULONG(param_1[1] + 8);
  WRITE_REGISTER_ULONG(param_1[1] + 8,uVar2 | 0x8000);
  param_1[7] = param_1[7] | 0x8000;
  LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
  return;
}



/* c085280c FUN_c085280c */

/* Boundary evidence: original MIPS .pdata c085280c..c085293f. Semantic name remains unreviewed. */

void FUN_c085280c(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (52000000 < *param_2) {
    *param_2 = 52000000;
  }
  if (*param_2 == 0) {
    *param_2 = 1;
  }
  uVar3 = *param_2;
  uVar1 = GetPBUSSpeed();
  uVar4 = uVar1 / (*param_2 << 1);
  if (*param_2 << 1 == 0) {
    trap(0x1c00);
  }
  if (1 < uVar4) {
    uVar4 = uVar4 - 1;
  }
  if (0x1ff < uVar4) {
    uVar4 = 0x1ff;
  }
  uVar2 = (uVar4 + 1) * 2;
  uVar5 = uVar1 / uVar2;
  if (uVar2 == 0) {
    trap(0x1c00);
  }
  *param_2 = uVar5;
  uVar2 = uVar4;
  if ((uVar3 < uVar5) && (uVar4 < 0x1ff)) {
    uVar2 = uVar4 + 1;
    uVar4 = (uVar4 + 2) * 2;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    *param_2 = uVar1 / uVar4;
  }
  uVar1 = READ_REGISTER_ULONG(*(int *)(param_1 + 4) + 8);
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 4) + 8,uVar1 & 0xfffffe00 | uVar2 | 0x200);
  return;
}



/* c0852940 FUN_c0852940 */

/* Boundary evidence: original MIPS .pdata c0852940..c08529e7. Semantic name remains unreviewed. */

void FUN_c0852940(int param_1,void *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0x4000 / *(uint *)(param_1 + 0x40);
  uVar1 = *(int *)(param_1 + 0x3c) - **(int **)(param_1 + 0x44);
  if (*(uint *)(param_1 + 0x40) == 0) {
    trap(0x1c00);
  }
  if (uVar1 <= uVar2) {
    uVar2 = uVar1;
  }
  FUN_c08553d4((void *)(*(int *)(param_1 + 0x40) * **(int **)(param_1 + 0x44) +
                       *(int *)(param_1 + 0x48)),param_2,*(int *)(param_1 + 0x40) * uVar2);
  **(int **)(param_1 + 0x44) = uVar2 + **(int **)(param_1 + 0x44);
  *(int *)(*(int *)(param_1 + 0x44) + 8) = *(int *)(*(int *)(param_1 + 0x44) + 8) + -1;
  return;
}



/* c08529e8 FUN_c08529e8 */

/* Boundary evidence: original MIPS .pdata c08529e8..c0852aa3. Semantic name remains unreviewed. */

int FUN_c08529e8(int param_1,void *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0x4000 / *(uint *)(param_1 + 0x40);
  uVar1 = *(int *)(param_1 + 0x3c) - **(int **)(param_1 + 0x44);
  if (*(uint *)(param_1 + 0x40) == 0) {
    trap(0x1c00);
  }
  if (uVar1 <= uVar2) {
    uVar2 = uVar1;
  }
  FUN_c08553d4(param_2,(void *)(*(int *)(param_1 + 0x40) * **(int **)(param_1 + 0x44) +
                               *(int *)(param_1 + 0x48)),*(int *)(param_1 + 0x40) * uVar2);
  **(int **)(param_1 + 0x44) = uVar2 + **(int **)(param_1 + 0x44);
  *(int *)(*(int *)(param_1 + 0x44) + 8) = *(int *)(*(int *)(param_1 + 0x44) + 8) + 1;
  return *(int *)(param_1 + 0x40) * uVar2;
}



/* c0852aa4 FUN_c0852aa4 */

/* Boundary evidence: original MIPS .pdata c0852aa4..c0852b5b. Semantic name remains unreviewed. */

void FUN_c0852aa4(int param_1)

{
  InterruptDisable(*(undefined4 *)(param_1 + 0x4c));
  if (*(int *)(param_1 + 0x44) != 0) {
    HalFreeDMAChannel();
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    HalFreeDMAChannel();
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  if (*(int *)(param_1 + 0x54) != 0) {
    EventModify(*(undefined4 *)(param_1 + 0x50),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x54),0xffffffff);
    CloseHandle(*(HANDLE *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  if (*(HANDLE *)(param_1 + 0x50) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x50));
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  return;
}



/* c0852b5c FUN_c0852b5c */

/* Boundary evidence: original MIPS .pdata c0852b5c..c0852bbb. Semantic name remains unreviewed. */

void FUN_c0852b5c(int param_1)

{
  if (*(int *)(param_1 + 0x24) != 0) {
    *(undefined4 *)(param_1 + 0x24) = 0;
    READ_REGISTER_ULONG(*(int *)(param_1 + 4) + 0xc);
    FUN_c0855640();
  }
  return;
}



/* c0852bbc FUN_c0852bbc */

/* Boundary evidence: original MIPS .pdata c0852bbc..c0853263. Semantic name remains unreviewed. */

undefined4 FUN_c0852bbc(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  
  bVar1 = false;
  uVar2 = SDP_Close();
  if (uVar2 <= param_2) {
    uVar3 = SDP_Close();
    NKDbgPrintfW(L"SDIOSDSendHandler - Slot %d outside valid range 0-%d\r\n",param_2,uVar3);
    return 0xc0000007;
  }
  if ((*(int *)(&DAT_c08560d8 + param_2 * 0x14) == 1) && (*(char *)(param_3 + 0x14) == '\x01')) {
    *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 0xc0000000;
  }
  iVar5 = param_2 * 0x68 + *(int *)(param_1 + 0x4c);
  piVar9 = (int *)(iVar5 + 4);
  *(int *)(iVar5 + 0x28) = param_3;
  *(undefined **)(param_3 + 0x44) = &DAT_c085613c + (uint)*(byte *)(iVar5 + 0x2c) * 0xc;
  WRITE_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x18,0xffffffff);
  if ((*(int *)(&DAT_c08560d8 + param_2 * 0x14) == 1) && (*(char *)(param_3 + 0x14) == '\x03')) {
    DAT_c0856164 = *(uint *)(param_3 + 0x18) | DAT_c0856164;
  }
  if (*(char *)(param_3 + 0x14) == '\x19') {
    FUN_c0852494(piVar9,*(undefined4 *)(param_3 + 0x3c));
  }
  *(undefined4 *)(&DAT_c0856140 + (uint)*(byte *)(iVar5 + 0x2c) * 0xc) = 0;
  *(undefined4 *)(&DAT_c085613c + (uint)*(byte *)(iVar5 + 0x2c) * 0xc) = 0;
  *(undefined4 *)(&DAT_c0856144 + (uint)*(byte *)(iVar5 + 0x2c) * 0xc) = 0;
  uVar7 = (uint)*(byte *)(param_3 + 0x14);
  uVar8 = uVar7 << 8 | 1;
  uVar2 = 0x30000;
  switch(*(undefined4 *)(param_3 + 0x1c)) {
  case 0:
    goto switchD_c0852dbc_caseD_0;
  case 1:
  case 8:
    uVar2 = 0x10000;
    break;
  case 2:
    uVar2 = 0x810000;
    goto LAB_c0852dd4;
  case 3:
    uVar2 = 0x20000;
    break;
  case 4:
    break;
  case 5:
    uVar2 = 0x40000;
    goto LAB_c0852dd4;
  case 6:
    uVar2 = 0x50000;
    break;
  case 7:
    uVar2 = 0x60000;
LAB_c0852dd4:
    uVar8 = uVar8 | uVar2;
    goto switchD_c0852dbc_caseD_0;
  default:
    goto switchD_c0852dbc_default;
  }
  uVar8 = uVar8 | uVar2;
switchD_c0852dbc_caseD_0:
  iVar6 = *(int *)(param_3 + 0x10);
  if (iVar6 == 2) {
    if (uVar7 == 0xc) {
      uVar8 = uVar8 | 0x70;
    }
    else if ((uVar7 == 0x34) && ((*(uint *)(param_3 + 0x18) & 0x3fffe00) == 0xc00)) {
      uVar8 = uVar8 | 0x80;
      bVar1 = true;
    }
  }
  else if (uVar7 == 0x35) {
    if ((*(uint *)(param_3 + 0x18) & 0x8000000) == 0) {
      if (iVar6 == 0) {
LAB_c0852e98:
        uVar8 = uVar8 | 0x20;
      }
      else {
LAB_c0852e80:
        uVar8 = uVar8 | 0x10;
      }
    }
    else {
      if ((*(uint *)(param_3 + 0x18) & 0x1ff) == 0) {
        if (iVar6 != 0) goto LAB_c0852ea8;
        goto LAB_c0852e58;
      }
      if (iVar6 == 0) {
        uVar8 = uVar8 | 0x60;
      }
      else {
        uVar8 = uVar8 | 0x50;
      }
    }
  }
  else if (iVar6 == 0) {
    if (uVar7 != 0x12) goto LAB_c0852e98;
LAB_c0852e58:
    uVar8 = uVar8 | 0x40;
  }
  else {
    if (uVar7 != 0x19) goto LAB_c0852e80;
LAB_c0852ea8:
    uVar8 = uVar8 | 0x30;
  }
  if (*(int *)(iVar5 + 0x24) == 0) {
    Sleep(2);
    *(undefined4 *)(iVar5 + 0x24) = 1;
  }
  if ((*(char *)(param_3 + 0x14) != '\f') && (!bVar1)) {
    if ((DAT_c0856168 != 0) &&
       (uVar2 = READ_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x18), (uVar2 & 0x20) != 0)) {
      uVar2 = READ_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x10);
      WRITE_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x10,uVar2 | 8);
    }
    do {
      uVar2 = READ_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x18);
    } while ((uVar2 & 0x20) != 0);
  }
  if (*(int *)(param_3 + 0x10) != 2) {
    if ((0x1ff < *(uint *)(param_3 + 0x3c)) || (0x800 < *(uint *)(param_3 + 0x40))) {
switchD_c0852dbc_default:
      return 0xc0000007;
    }
    WRITE_REGISTER_ULONG
              (*(int *)(iVar5 + 8) + 0x14,
               (*(uint *)(param_3 + 0x3c) - 1) * 0x10000 | *(uint *)(param_3 + 0x40) - 1);
    uVar2 = READ_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x10);
    WRITE_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x10,uVar2 & 0xfffffff7 | 2);
  }
  if ((*(int *)(iVar5 + 0x30) == 0) ||
     ((*(int *)(param_3 + 0x10) != 2 && ((*(uint *)(param_3 + 0x40) & 0x1f) != 0)))) {
    *(undefined4 *)(iVar5 + 0x34) = 0;
  }
  else {
    *(undefined4 *)(iVar5 + 0x34) = 1;
  }
  if ((*(int *)(iVar5 + 0x34) == 0) || (iVar6 = *(int *)(param_3 + 0x10), iVar6 == 2))
  goto LAB_c0853108;
  if (iVar6 == 0) {
    uVar2 = *(int *)(param_3 + 0x40) * *(int *)(param_3 + 0x3c);
    if (*(uint *)(iVar5 + 0x60) <= uVar2) {
      uVar2 = *(uint *)(iVar5 + 0x60);
    }
    HalStopDMA(*(undefined4 *)(iVar5 + 0x4c));
    uVar3 = HalGetNextDMABuffer(*(undefined4 *)(iVar5 + 0x4c));
    HalActivateDMABuffer(*(undefined4 *)(iVar5 + 0x4c),uVar3,uVar2);
    pvVar4 = (void *)HalGetNextDMABuffer(*(undefined4 *)(iVar5 + 0x4c));
    uVar3 = *(undefined4 *)(iVar5 + 0x4c);
  }
  else {
    if (iVar6 != 1) goto LAB_c0853108;
    HalStopDMA(*(undefined4 *)(iVar5 + 0x48));
    pvVar4 = (void *)HalGetNextDMABuffer(*(undefined4 *)(iVar5 + 0x48));
    iVar6 = FUN_c08529e8(param_3,pvVar4);
    HalActivateDMABuffer(*(undefined4 *)(iVar5 + 0x48),pvVar4,iVar6);
    if (*(uint *)(param_3 + 0x3c) <= **(uint **)(param_3 + 0x44)) goto LAB_c0853108;
    pvVar4 = (void *)HalGetNextDMABuffer(*(undefined4 *)(iVar5 + 0x48));
    uVar2 = FUN_c08529e8(param_3,pvVar4);
    uVar3 = *(undefined4 *)(iVar5 + 0x48);
  }
  HalActivateDMABuffer(uVar3,pvVar4,uVar2);
LAB_c0853108:
  WRITE_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x18,0x730000);
  EnterCriticalSection((LPCRITICAL_SECTION)(*piVar9 + 0x358));
  uVar2 = READ_REGISTER_ULONG(*(int *)(iVar5 + 8) + 8);
  WRITE_REGISTER_ULONG(*(int *)(iVar5 + 8) + 8,uVar2 | 0x30000);
  *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | 0x30000;
  LeaveCriticalSection((LPCRITICAL_SECTION)(*piVar9 + 0x358));
  if ((*(char *)(param_3 + 0x14) == '\f') ||
     ((*(char *)(param_3 + 0x14) == '4' && ((*(uint *)(param_3 + 0x18) & 0x3fffe00) == 0xc00)))) {
    uVar2 = READ_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x10);
    if ((param_2 == 1) && ((*(char *)(param_3 + 0x14) == '\f' && (DAT_c085616c == 0x19)))) {
      Sleep(1);
    }
    WRITE_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x10,uVar2 | 8);
  }
  uVar2 = (uint)*(byte *)(param_3 + 0x14);
  DAT_c0856168 = (uint)(uVar2 == 0x35);
  if ((uVar2 == 0x19) || (uVar2 == 0x12)) {
    DAT_c0856160 = uVar2;
  }
  WRITE_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x24,*(undefined4 *)(param_3 + 0x18));
  WRITE_REGISTER_ULONG(*(int *)(iVar5 + 8) + 0x20,uVar8);
  DAT_c085616c = (uint)*(byte *)(param_3 + 0x14);
  return 1;
}



/* c0853264 FUN_c0853264 */

/* Boundary evidence: original MIPS .pdata c0853264..c08532af. Semantic name remains unreviewed. */

undefined4 FUN_c0853264(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  FUN_c0855640();
  return 1;
}



/* c08532b0 FUN_c08532b0 */

/* Boundary evidence: original MIPS .pdata c08532b0..c085331b. Semantic name remains unreviewed. */

void FUN_c08532b0(int *param_1)

{
  FUN_c0855618();
  NKDbgPrintfW(L"RemoveDevice: Card Removal Detected - \r\n");
  if (param_1[9] != 0) {
    FUN_c0852b5c((int)param_1);
  }
  FUN_c08526c4(param_1,0);
  return;
}



/* c085331c FUN_c085331c */

/* Boundary evidence: original MIPS .pdata c085331c..c0853473. Semantic name remains unreviewed. */

undefined4 FUN_c085331c(int *param_1,undefined4 param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar2;
  wchar_t *pwVar3;
  
  uVar2 = READ_REGISTER_ULONG(param_1[1] + 0x18);
  WRITE_REGISTER_ULONG(param_1[1] + 0x18,param_3 | 0xa0000);
  if ((DAT_c08560f0 == 0x90) && (param_3 == 0x400000)) {
    if ((uVar2 & 7) == 3) {
      FUN_c08526c4(param_1,0);
      uVar1 = (undefined1)param_1[10];
      pwVar3 = L"SDIO[%d]-SK: CRC Error %08X\r\n";
LAB_c08533a4:
      NKDbgPrintfW(pwVar3,uVar1,uVar2);
      goto LAB_c08533b4;
    }
  }
  else if ((uVar2 & param_3) != 0) {
    FUN_c08526c4(param_1,0);
    uVar1 = (undefined1)param_1[10];
    pwVar3 = L"SDIO[%d]: CRC Error %08X\r\n";
    goto LAB_c08533a4;
  }
  if ((uVar2 & 0x80000) == 0) {
    if ((uVar2 & 0x20000) == 0) {
      return 0;
    }
    NKDbgPrintfW(L"SDIO[%d]: Response Timeout %08X\r\n",(char)param_1[10],uVar2);
  }
  else {
    NKDbgPrintfW(L"SDIO[%d]: Data Timeout %08X\r\n",(char)param_1[10],uVar2);
  }
LAB_c08533b4:
  FUN_c0852b5c((int)param_1);
  return 1;
}



/* c0853474 FUN_c0853474 */

/* Boundary evidence: original MIPS .pdata c0853474..c08535f3. Semantic name remains unreviewed. */

void FUN_c0853474(int *param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_20 [4];
  
  iVar5 = param_1[9];
  if (param_1[9] != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
    WRITE_REGISTER_ULONG(param_1[1] + 8,uVar1 & 0xfffcffff);
    param_1[7] = param_1[7] & 0xfffcffff;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
    WRITE_REGISTER_ULONG(param_1[1] + 0x18,0x30000);
    if ((DAT_c0856160 == 0x19) && (*(char *)(iVar5 + 0x14) == '\f')) {
      READ_REGISTER_ULONG(param_1[1] + 0x34);
      READ_REGISTER_ULONG(param_1[1] + 0x30);
      READ_REGISTER_ULONG(param_1[1] + 0x2c);
      READ_REGISTER_ULONG(param_1[1] + 0x28);
      local_20[0] = 0x900;
      local_20[1] = 0;
      local_20[2] = 0;
      local_20[3] = 0;
      if (*(int *)(iVar5 + 0x1c) != 0) {
        puVar2 = (undefined1 *)(iVar5 + 0x21);
        puVar4 = local_20;
        iVar5 = 4;
        do {
          uVar3 = *puVar4;
          *puVar2 = (char)uVar3;
          puVar2[1] = (char)((uint)uVar3 >> 8);
          puVar2[2] = (char)((uint)uVar3 >> 0x10);
          puVar2[3] = (char)((uint)uVar3 >> 0x18);
          puVar2 = puVar2 + 4;
          iVar5 = iVar5 + -1;
          puVar4 = puVar4 + 1;
        } while (iVar5 != 0);
      }
      do {
        uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
      } while ((uVar1 & 0x20) != 0);
    }
    FUN_c0852b5c((int)param_1);
  }
  return;
}



/* c08535f4 FUN_c08535f4 */

/* Boundary evidence: original MIPS .pdata c08535f4..c0853693. Semantic name remains unreviewed. */

void FUN_c08535f4(int *param_1)

{
  uint uVar1;
  
  if (param_1[9] != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
    WRITE_REGISTER_ULONG(param_1[1] + 8,uVar1 & 0xfdf7fbff);
    param_1[7] = param_1[7] & 0xfdf7fbff;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
    WRITE_REGISTER_ULONG(param_1[1] + 0x18,0x2080400);
    FUN_c0852b5c((int)param_1);
  }
  return;
}



/* c0853694 FUN_c0853694 */

/* Boundary evidence: original MIPS .pdata c0853694..c08538bb. Semantic name remains unreviewed. */

void FUN_c0853694(int *param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_20 [4];
  
  iVar6 = param_1[9];
  if (iVar6 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
    WRITE_REGISTER_ULONG(param_1[1] + 8,uVar1 & 0xfffeffff);
    param_1[7] = param_1[7] & 0xfffeffff;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
    WRITE_REGISTER_ULONG(param_1[1] + 0x18,0x10000);
    local_20[0] = READ_REGISTER_ULONG(param_1[1] + 0x34);
    local_20[1] = READ_REGISTER_ULONG(param_1[1] + 0x30);
    local_20[2] = READ_REGISTER_ULONG(param_1[1] + 0x2c);
    local_20[3] = READ_REGISTER_ULONG(param_1[1] + 0x28);
    if (*(int *)(iVar6 + 0x1c) != 0) {
      puVar2 = (undefined1 *)(iVar6 + 0x21);
      puVar4 = local_20;
      iVar5 = 4;
      do {
        uVar3 = *puVar4;
        *puVar2 = (char)uVar3;
        puVar2[1] = (char)((uint)uVar3 >> 8);
        puVar2[2] = (char)((uint)uVar3 >> 0x10);
        puVar2[3] = (char)((uint)uVar3 >> 0x18);
        puVar2 = puVar2 + 4;
        iVar5 = iVar5 + -1;
        puVar4 = puVar4 + 1;
      } while (iVar5 != 0);
    }
    if (*(int *)(iVar6 + 0x10) == 2) {
      iVar6 = FUN_c085331c(param_1,iVar6,0x100000);
      if (iVar6 == 0) {
        FUN_c0852b5c((int)param_1);
      }
    }
    else if (param_1[0xc] == 0) {
      *(undefined4 *)(*(int *)(iVar6 + 0x44) + 4) = 0;
      if (*(int *)(iVar6 + 0x10) == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
        uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
        uVar7 = 0x80400;
      }
      else {
        EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
        uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
        uVar7 = 0x2080000;
      }
      WRITE_REGISTER_ULONG(param_1[1] + 8,uVar1 | uVar7);
      param_1[7] = param_1[7] | uVar7;
      LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
    }
    else {
      if (*(int *)(iVar6 + 0x10) == 0) {
        uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x10);
        WRITE_REGISTER_ULONG(param_1[1] + 0x10,uVar1 | 0x10);
        iVar6 = param_1[0x12];
      }
      else {
        iVar6 = param_1[0x11];
      }
      HalStartDMA(iVar6);
    }
  }
  return;
}



/* c08538bc FUN_c08538bc */

/* Boundary evidence: original MIPS .pdata c08538bc..c0853aa7. Semantic name remains unreviewed. */

void FUN_c08538bc(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = param_1[9];
  if ((iVar3 != 0) &&
     (*(int *)(*(int *)(iVar3 + 0x44) + 4) != *(int *)(iVar3 + 0x40) * *(int *)(iVar3 + 0x3c))) {
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
    while (((uVar1 & 0x400) != 0 &&
           (uVar1 = *(uint *)(*(int *)(iVar3 + 0x44) + 4),
           uVar1 < (uint)(*(int *)(iVar3 + 0x40) * *(int *)(iVar3 + 0x3c))))) {
      puVar4 = (undefined4 *)(uVar1 + *(int *)(iVar3 + 0x48));
      if (((uint)puVar4 & 3) == 0) {
        uVar2 = READ_REGISTER_ULONG(param_1[1] + 4);
        *puVar4 = uVar2;
        *(int *)(*(int *)(iVar3 + 0x44) + 4) = *(int *)(*(int *)(iVar3 + 0x44) + 4) + 4;
      }
      else {
        uVar2 = READ_REGISTER_ULONG(param_1[1] + 4);
        *(char *)(*(int *)(*(int *)(iVar3 + 0x44) + 4) + *(int *)(iVar3 + 0x48)) = (char)uVar2;
        *(char *)(*(int *)(*(int *)(iVar3 + 0x44) + 4) + *(int *)(iVar3 + 0x48) + 1) =
             (char)((uint)uVar2 >> 8);
        *(char *)(*(int *)(*(int *)(iVar3 + 0x44) + 4) + *(int *)(iVar3 + 0x48) + 2) =
             (char)((uint)uVar2 >> 0x10);
        *(char *)(*(int *)(*(int *)(iVar3 + 0x44) + 4) + *(int *)(iVar3 + 0x48) + 3) =
             (char)((uint)uVar2 >> 0x18);
        *(int *)(*(int *)(iVar3 + 0x44) + 4) = *(int *)(*(int *)(iVar3 + 0x44) + 4) + 4;
      }
      uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
    }
    if (*(int *)(*(int *)(iVar3 + 0x44) + 4) == *(int *)(iVar3 + 0x40) * *(int *)(iVar3 + 0x3c)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
      uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
      WRITE_REGISTER_ULONG(param_1[1] + 8,uVar1 & 0xfffffbff);
      param_1[7] = param_1[7] & 0xfffffbff;
      LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
      iVar3 = FUN_c085331c(param_1,iVar3,0x200000);
      if (iVar3 == 0) {
        FUN_c0852b5c((int)param_1);
      }
    }
  }
  return;
}



/* c0853aa8 FUN_c0853aa8 */

/* Boundary evidence: original MIPS .pdata c0853aa8..c0853c5b. Semantic name remains unreviewed. */

void FUN_c0853aa8(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1[9];
  if ((iVar2 == 0) ||
     (*(int *)(*(int *)(iVar2 + 0x44) + 4) == *(int *)(iVar2 + 0x40) * *(int *)(iVar2 + 0x3c))) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
    WRITE_REGISTER_ULONG(param_1[1] + 8,uVar1 & 0xfdffffff);
    param_1[7] = param_1[7] & 0xfdffffff;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
  }
  else {
    uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
    while (((uVar1 & 0x2000000) != 0 &&
           (uVar1 = *(uint *)(*(int *)(iVar2 + 0x44) + 4),
           uVar1 < (uint)(*(int *)(iVar2 + 0x40) * *(int *)(iVar2 + 0x3c))))) {
      WRITE_REGISTER_ULONG(param_1[1],*(undefined4 *)(*(int *)(iVar2 + 0x48) + uVar1));
      *(int *)(*(int *)(iVar2 + 0x44) + 4) = *(int *)(*(int *)(iVar2 + 0x44) + 4) + 4;
      uVar1 = READ_REGISTER_ULONG(param_1[1] + 0x18);
    }
    if (*(int *)(*(int *)(iVar2 + 0x44) + 4) == *(int *)(iVar2 + 0x40) * *(int *)(iVar2 + 0x3c)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
      uVar1 = READ_REGISTER_ULONG(param_1[1] + 8);
      WRITE_REGISTER_ULONG(param_1[1] + 8,uVar1 & 0xfdffffff);
      param_1[7] = param_1[7] & 0xfdffffff;
      LeaveCriticalSection((LPCRITICAL_SECTION)(*param_1 + 0x358));
      iVar2 = FUN_c085331c(param_1,iVar2,0x400000);
      if (iVar2 == 0) {
        FUN_c0852b5c((int)param_1);
      }
    }
  }
  return;
}



/* c0853c5c FUN_c0853c5c */

/* Boundary evidence: original MIPS .pdata c0853c5c..c0853cab. Semantic name remains unreviewed. */

bool FUN_c0853c5c(int param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = READ_REGISTER_ULONG(*(int *)(param_1 + 4) + 0x18);
  uVar1 = *(uint *)(param_1 + 0x1c) & uVar1;
  *param_2 = uVar1;
  return uVar1 != 0;
}



/* c0853cac FUN_c0853cac */

/* Boundary evidence: original MIPS .pdata c0853cac..c0853eab. Semantic name remains unreviewed. */

undefined4 FUN_c0853cac(int *param_1)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  uint local_28 [2];
  
  CeSetThreadPriority(0x41,param_1[0xf]);
  DVar2 = WaitForSingleObject((HANDLE)param_1[0xd],0xffffffff);
  do {
    if (DVar2 != 0) {
      return 0;
    }
    if (*(int *)(*param_1 + 0x14c) != 0) {
      NKDbgPrintfW(L"SDIOInsertionIstThread[%d]: Thread Exiting\r\n",(char)param_1[10]);
      return 0;
    }
    if (param_1[6] == 0) {
      iVar3 = 0;
      bVar1 = false;
      do {
        iVar4 = SDP_Close();
        if (iVar4 == 0) {
          if (bVar1) {
            bVar1 = false;
            goto LAB_c0853dc0;
          }
LAB_c0853dc8:
          iVar3 = iVar3 + 1;
        }
        else {
          if (bVar1) goto LAB_c0853dc8;
          bVar1 = true;
LAB_c0853dc0:
          iVar3 = 0;
        }
        Sleep(0x14);
      } while (iVar3 < 10);
      if (bVar1) {
        if (param_1[5] == 0) {
          local_28[0] = 200000;
          FUN_c085280c((int)param_1,local_28);
          param_1[5] = 1;
          param_1[8] = 0;
          FUN_c0855618();
        }
      }
      else if (param_1[5] != 0) {
        FUN_c08532b0(param_1);
        param_1[5] = 0;
      }
    }
    else {
      FUN_c08532b0(param_1);
      FUN_c08526c4(param_1,0);
      iVar3 = SDP_Close();
      if (iVar3 == 0) {
        param_1[5] = 0;
      }
      else {
        param_1[5] = 1;
        param_1[8] = 0;
        FUN_c0855618();
      }
      param_1[6] = 0;
    }
    InterruptDone(param_1[0x10]);
    DVar2 = WaitForSingleObject((HANDLE)param_1[0xd],0xffffffff);
  } while( true );
}



/* c0853eac FUN_c0853eac */

/* Boundary evidence: original MIPS .pdata c0853eac..c0854163. Semantic name remains unreviewed. */

undefined4 FUN_c0853eac(int param_1)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  undefined3 extraout_var;
  int *piVar5;
  uint uVar6;
  uint local_30 [2];
  
  CeSetThreadPriority(0x41,*(undefined4 *)(param_1 + 0x144));
  DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x13c),0xffffffff);
  while( true ) {
    if (DVar2 != 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x14c) != 0) break;
    uVar6 = 0;
    iVar3 = SDP_Close();
    if (0 < iVar3) {
      do {
        iVar3 = uVar6 * 0x68 + param_1;
        piVar5 = (int *)(iVar3 + 4);
        while (bVar1 = FUN_c0853c5c((int)piVar5,local_30), uVar4 = local_30[0],
              CONCAT31(extraout_var,bVar1) != 0) {
          if ((local_30[0] & 0x20000) != 0) {
            WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x18,0x20000);
            FUN_c0853474(piVar5);
          }
          if ((uVar4 & 0x80000) != 0) {
            WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x18,0x80000);
            NKDbgPrintfW(L"SDIO - Data Transfer Timeout Interrupt\r\n");
            FUN_c08535f4(piVar5);
          }
          if ((uVar4 & 0x10000) != 0) {
            WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x18,0x10000);
            FUN_c0853694(piVar5);
          }
          if ((uVar4 & 0x400) != 0) {
            WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x18,0x400);
            FUN_c08538bc(piVar5);
          }
          if ((uVar4 & 0x2000000) != 0) {
            WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x18,0x2000000);
            FUN_c0853aa8(piVar5);
          }
          if ((uVar4 & 0x400000) != 0) {
            WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x18,0xffffffff);
            NKDbgPrintfW(L"SDIO - SDIO Write CRC (OKAY for Hynix!) Interrupt\r\n");
          }
          if ((uVar4 & 0x80000000) != 0) {
            EnterCriticalSection((LPCRITICAL_SECTION)(*piVar5 + 0x358));
            uVar4 = READ_REGISTER_ULONG(*(int *)(iVar3 + 8) + 8);
            WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 8,uVar4 & 0x7fffffff);
            *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0x7fffffff;
            LeaveCriticalSection((LPCRITICAL_SECTION)(*piVar5 + 0x358));
            WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x18,0x80000000);
            FUN_c0855618();
          }
        }
        uVar6 = uVar6 + 1 & 0xff;
        iVar3 = SDP_Close();
      } while ((int)uVar6 < iVar3);
    }
    InterruptDone(*(undefined4 *)(param_1 + 0x350));
    DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x13c),0xffffffff);
  }
  NKDbgPrintfW(L"SDIOControllerIstThread: Thread Exiting\r\n");
  return 0;
}



/* c0854164 FUN_c0854164 */

/* Boundary evidence: original MIPS .pdata c0854164..c0854443. Semantic name remains unreviewed. */

undefined4 FUN_c0854164(int *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  
  CeSetThreadPriority(0x41,param_1[0x16]);
  DVar1 = WaitForSingleObject((HANDLE)param_1[0x14],0xffffffff);
  do {
    if (DVar1 != 0) {
      return 0;
    }
    if (*(int *)(*param_1 + 0x14c) != 0) {
      NKDbgPrintfW(L"SDIODmaIstThread[%d]: Thread Exiting\r\n",(char)param_1[10]);
      return 0;
    }
    iVar6 = param_1[9];
    if (iVar6 == 0) {
LAB_c08541fc:
      uVar2 = HalCheckForDMAInterrupt(param_1[0x11]);
      NKDbgPrintfW(L"Spurious Tx %d\r\n",uVar2);
      HalAckDMAInterrupt(param_1[0x11],uVar2);
      uVar2 = HalCheckForDMAInterrupt(param_1[0x12]);
      NKDbgPrintfW(L"Spurious Rx %d\r\n",uVar2);
      HalAckDMAInterrupt(param_1[0x12],uVar2);
    }
    else {
      if (*(int *)(iVar6 + 0x10) == 0) {
        do {
          while( true ) {
            do {
              iVar5 = HalCheckForDMAInterrupt(param_1[0x12]);
              if (iVar5 == 0) goto LAB_c0854244;
              HalAckDMAInterrupt(param_1[0x12],iVar5);
            } while (*(uint *)(iVar6 + 0x3c) <= **(uint **)(iVar6 + 0x44));
            pvVar4 = (void *)HalGetNextDMABuffer(param_1[0x12]);
            FUN_c0852940(iVar6,pvVar4);
            if (**(int **)(iVar6 + 0x44) == *(int *)(iVar6 + 0x3c)) break;
            uVar3 = (*(int *)(iVar6 + 0x3c) - **(int **)(iVar6 + 0x44)) * *(int *)(iVar6 + 0x40);
            if ((uint)param_1[0x17] <= uVar3) {
              uVar3 = param_1[0x17];
            }
            HalActivateDMABuffer(param_1[0x12],pvVar4,uVar3);
          }
          HalStopDMA(param_1[0x12]);
          iVar5 = FUN_c085331c(param_1,iVar6,0x200000);
        } while (iVar5 != 0);
        uVar3 = READ_REGISTER_ULONG(param_1[1] + 0x10);
        WRITE_REGISTER_ULONG(param_1[1] + 0x10,uVar3 & 0xffffffef);
      }
      else {
        if (*(int *)(iVar6 + 0x10) != 1) goto LAB_c08541fc;
        do {
          while( true ) {
            iVar5 = HalCheckForDMAInterrupt(param_1[0x11]);
            if (iVar5 == 0) goto LAB_c0854244;
            HalAckDMAInterrupt(param_1[0x11],iVar5);
            *(int *)(*(int *)(iVar6 + 0x44) + 8) = *(int *)(*(int *)(iVar6 + 0x44) + 8) + -1;
            if (*(int *)(*(int *)(iVar6 + 0x44) + 8) == 0) break;
            if (**(uint **)(iVar6 + 0x44) < *(uint *)(iVar6 + 0x3c)) {
              pvVar4 = (void *)HalGetNextDMABuffer(param_1[0x11]);
              iVar5 = FUN_c08529e8(iVar6,pvVar4);
              HalActivateDMABuffer(param_1[0x11],pvVar4,iVar5);
            }
          }
          HalStopDMA(param_1[0x11]);
          iVar5 = FUN_c085331c(param_1,iVar6,0x400000);
        } while (iVar5 != 0);
      }
      FUN_c0852b5c((int)param_1);
    }
LAB_c0854244:
    InterruptDone(param_1[0x13]);
    DVar1 = WaitForSingleObject((HANDLE)param_1[0x14],0xffffffff);
  } while( true );
}



/* c0854444 FUN_c0854444 */

/* Boundary evidence: original MIPS .pdata c0854444..c0854543. Semantic name remains unreviewed. */

int FUN_c0854444(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 *param_4)

{
  LSTATUS LVar1;
  int iVar2;
  DWORD local_20;
  HKEY local_1c;
  undefined4 local_18;
  DWORD DStack_14;
  
  iVar2 = 0;
  if (param_4 != (undefined4 *)0x0) {
    LVar1 = RegCreateKeyExW(param_1,param_2,0,L"",0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,&local_1c,
                            &DStack_14);
    if (LVar1 == 0) {
      local_20 = 4;
      LVar1 = RegQueryValueExW(local_1c,param_3,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_18,
                               &local_20);
      if ((LVar1 == 0) && (local_20 == 4)) {
        iVar2 = 1;
      }
      else {
        iVar2 = 0;
      }
      RegCloseKey(local_1c);
      if (iVar2 == 0) {
        *param_4 = 0;
      }
      else {
        *param_4 = local_18;
      }
    }
  }
  return iVar2;
}



/* c0854544 FUN_c0854544 */

/* Boundary evidence: original MIPS .pdata c0854544..c0854713. Semantic name remains unreviewed. */

undefined4 FUN_c0854544(LPVOID param_1)

{
  int iVar1;
  HANDLE pvVar2;
  wchar_t *pwVar3;
  uint uVar4;
  DWORD aDStack_20 [2];
  
  iVar1 = HalAllocateDMAChannel();
  *(int *)((int)param_1 + 0x44) = iVar1;
  if (iVar1 == 0) {
    pwVar3 = L"SDIO[%d]: Can\'t allocate Tx DMA Channel\r\r\n";
  }
  else {
    iVar1 = HalAllocateDMAChannel();
    uVar4 = (uint)*(byte *)((int)param_1 + 0x28);
    *(int *)((int)param_1 + 0x48) = iVar1;
    if (iVar1 == 0) {
      pwVar3 = L"SDIO[%d]: Can\'t allocate Rx DMA Channel\r\n";
      goto LAB_c08546e0;
    }
    *(undefined4 *)((int)param_1 + 0x2c) = 1;
    HalInitDmaChannel(*(undefined4 *)((int)param_1 + 0x44),
                      *(undefined4 *)(&DAT_c08560cc + uVar4 * 0x14),
                      *(undefined4 *)((int)param_1 + 0x5c),1);
    HalInitDmaChannel(*(undefined4 *)((int)param_1 + 0x48),
                      *(undefined4 *)(&DAT_c08560d0 + (uint)*(byte *)((int)param_1 + 0x28) * 0x14),
                      *(undefined4 *)((int)param_1 + 0x5c),1);
    HalSetDMAForReceive(*(undefined4 *)((int)param_1 + 0x48));
    uVar4 = HalGetDMAHwIntr(*(undefined4 *)((int)param_1 + 0x44));
    iVar1 = HalGetDMAHwIntr(*(undefined4 *)((int)param_1 + 0x48));
    iVar1 = InterruptConnect(0,0,iVar1 << 8 | uVar4,0);
    *(int *)((int)param_1 + 0x4c) = iVar1;
    if (iVar1 == 0) {
      pwVar3 = L"SDIO[%d]: Can\'t allocate DMA SYSINTR\r\n";
    }
    else {
      pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      *(HANDLE *)((int)param_1 + 0x50) = pvVar2;
      if (pvVar2 == (HANDLE)0x0) {
        pwVar3 = L"SDIO[%d]: Can\'t create DMA interrupt event\r\n";
      }
      else {
        iVar1 = InterruptInitialize(*(undefined4 *)((int)param_1 + 0x4c),pvVar2,0,0);
        if (iVar1 == 0) {
          NKDbgPrintfW(L"SDIO[%d]: Call to InterruptInitialize failed\r\n",
                       *(undefined1 *)((int)param_1 + 0x28));
        }
        *(undefined4 *)((int)param_1 + 0x58) = 100;
        pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0854164,param_1,0,aDStack_20);
        *(HANDLE *)((int)param_1 + 0x54) = pvVar2;
        if (pvVar2 != (HANDLE)0x0) {
          return 1;
        }
        pwVar3 = L"SDIO[%d]: Can\'t create DMA interrupt thread\r\n";
      }
    }
  }
  uVar4 = (uint)*(byte *)((int)param_1 + 0x28);
LAB_c08546e0:
  NKDbgPrintfW(pwVar3,uVar4);
  FUN_c0852aa4((int)param_1);
  return 0;
}



/* c0854714 FUN_c0854714 */

/* Boundary evidence: original MIPS .pdata c0854714..c08548b3. Semantic name remains unreviewed. */

undefined4 FUN_c0854714(int *param_1)

{
  HANDLE pvVar1;
  int iVar2;
  DWORD aDStack_20 [2];
  
  NKDbgPrintfW(L"SDIOInitializeSlot:: Slot:0x%x\r\n",(char)param_1[10]);
  param_1[0x18] = *(int *)(&DAT_c08560d4 + (uint)*(byte *)(param_1 + 10) * 0x14);
  SDP_IOControl();
  if (param_1[0x18] != 0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    param_1[0xd] = (int)pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      return 0xc000000e;
    }
    iVar2 = InterruptInitialize(param_1[0x10],pvVar1,0,0);
    if (iVar2 == 0) {
      return 0xc000000e;
    }
    param_1[0xf] = 100;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0853cac,param_1,0,aDStack_20);
    param_1[0xe] = (int)pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      return 0xc000000e;
    }
  }
  iVar2 = MmMapIoSpace(*(undefined4 *)(&DAT_c08560c8 + (uint)*(byte *)(param_1 + 10) * 0x14),0,0x3c,
                       0);
  param_1[1] = iVar2;
  if (iVar2 == 0) {
    NKDbgPrintfW(L"SDIOInitialize - failed to map registers\r\n");
    return 0xc000000e;
  }
  if (param_1[0xb] != 0) {
    param_1[0x17] = 0x4000;
    iVar2 = FUN_c0854544(param_1);
    if (iVar2 == 0) {
      param_1[0xb] = 0;
    }
  }
  if (param_1[0x18] != 0) {
    param_1[5] = 0;
    param_1[9] = 0;
  }
  FUN_c08526c4(param_1,1);
  return 0;
}



/* c08548b4 FUN_c08548b4 */

/* Boundary evidence: original MIPS .pdata c08548b4..c085498b. Semantic name remains unreviewed. */

void FUN_c08548b4(int *param_1)

{
  if (param_1[0x18] != 0) {
    InterruptDisable(param_1[0x10]);
  }
  if (param_1[5] != 0) {
    param_1[5] = 0;
    FUN_c08532b0(param_1);
  }
  if (param_1[0xe] != 0) {
    EventModify(param_1[0xd],3);
    WaitForSingleObject((HANDLE)param_1[0xe],0xffffffff);
    CloseHandle((HANDLE)param_1[0xe]);
    param_1[0xe] = 0;
  }
  if ((HANDLE)param_1[0xd] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0xd]);
    param_1[0xd] = 0;
  }
  if (param_1[1] != 0) {
    MmUnmapIoSpace(param_1[1],0x40);
    param_1[1] = 0;
  }
  if (param_1[0xb] != 0) {
    FUN_c0852aa4((int)param_1);
  }
  return;
}



/* c085498c FUN_c085498c */

/* Boundary evidence: original MIPS .pdata c085498c..c0854a7b. Semantic name remains unreviewed. */

undefined4 FUN_c085498c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x4c);
  *(undefined4 *)(iVar2 + 0x14c) = 1;
  if (*(int *)(iVar2 + 0x148) != 0) {
    InterruptDisable(*(undefined4 *)(iVar2 + 0x350));
    if (*(int *)(iVar2 + 0x140) != 0) {
      EventModify(*(undefined4 *)(iVar2 + 0x13c),3);
      WaitForSingleObject(*(HANDLE *)(iVar2 + 0x140),0xffffffff);
      CloseHandle(*(HANDLE *)(iVar2 + 0x140));
      *(undefined4 *)(iVar2 + 0x140) = 0;
    }
    if (*(HANDLE *)(iVar2 + 0x13c) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)(iVar2 + 0x13c));
      *(undefined4 *)(iVar2 + 0x13c) = 0;
    }
    CloseHandle(*(HANDLE *)(iVar2 + 0x354));
    DeleteCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x358));
    SDP_IOControl();
    iVar4 = 0;
    iVar1 = SDP_Close();
    if (0 < iVar1) {
      piVar3 = (int *)(iVar2 + 4);
      do {
        FUN_c08548b4(piVar3);
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 0x1a;
        iVar2 = SDP_Close();
      } while (iVar4 < iVar2);
    }
  }
  return 0;
}



/* c0854a7c FUN_c0854a7c */

/* Boundary evidence: original MIPS .pdata c0854a7c..c0854ee3. Semantic name remains unreviewed. */

undefined4 FUN_c0854a7c(int param_1,int param_2,undefined4 param_3,ushort *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_28 [2];
  
  local_28[0] = 0x45;
  iVar3 = *(int *)(param_1 + 0x4c);
  uVar4 = 0;
  switch(param_3) {
  case 0:
    break;
  case 1:
    iVar3 = param_2 * 0x68 + iVar3;
    READ_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0xc);
    NKDbgPrintfW(L"SDIOSDSlotOptionHandler - called - SetSlotInterface : Clock Setting: %d \r\n",
                 *(uint *)(param_4 + 2));
    if (*(int *)param_4 == 0) {
      NKDbgPrintfW(
                  L"SDIOSDSlotOptionHandler - called - SetSlotInterface : setting for 1 bit mode \r\n"
                  );
      uVar1 = READ_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x10);
      uVar1 = uVar1 & 0xfffffeff;
LAB_c0854bc8:
      WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x10,uVar1);
    }
    else if (*(int *)param_4 == 1) {
      uVar1 = READ_REGISTER_ULONG(*(int *)(iVar3 + 8) + 0x10);
      if ((*(int *)(&DAT_c08560d8 + param_2 * 0x14) == 1) && (*(int *)(iVar3 + 0x68) == 1)) {
        NKDbgPrintfW(
                    L"SDIOSDSlotOptionHandler - called - SetSlotInterface : setting for 8 bit mode \r\n"
                    );
        uVar1 = uVar1 | 0x80;
      }
      else {
        NKDbgPrintfW(
                    L"SDIOSDSlotOptionHandler - called - SetSlotInterface : setting for 4 bit mode \r\n"
                    );
        uVar1 = uVar1 | 0x100;
      }
      goto LAB_c0854bc8;
    }
    FUN_c0854444((HKEY)0x80000002,L"LGE\\SystemInfo",L"eMMCID",local_28);
    if (local_28[0] == 0x90) {
      DAT_c08560f0 = 0x90;
    }
    NKDbgPrintfW(L" ManufactuerID: 0x%x \r\n",DAT_c08560f0);
    FUN_c085280c(iVar3 + 4,(uint *)(param_4 + 2));
    break;
  case 2:
    NKDbgPrintfW(L"SDIOSDSlotOptionHandler - called - EnableSDIOInterrupts : on slot %d  \r\n",
                 param_2);
    goto LAB_c0854c48;
  case 3:
    NKDbgPrintfW(L"SDIOSDSlotOptionHandler - called - DisableSDIOInterrupts : on slot %d  \r\n",
                 param_2);
    iVar3 = param_2 * 0x68 + iVar3;
    EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + 4) + 0x358));
    uVar1 = READ_REGISTER_ULONG(*(int *)(iVar3 + 8) + 8);
    WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 8,uVar1 & 0x7fffffff);
    uVar1 = *(uint *)(iVar3 + 0x20) & 0x7fffffff;
    goto LAB_c0854c84;
  case 4:
LAB_c0854c48:
    iVar3 = param_2 * 0x68 + iVar3;
    EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + 4) + 0x358));
    uVar1 = READ_REGISTER_ULONG(*(int *)(iVar3 + 8) + 8);
    WRITE_REGISTER_ULONG(*(int *)(iVar3 + 8) + 8,uVar1 | 0x80000000);
    uVar1 = *(uint *)(iVar3 + 0x20) | 0x80000000;
LAB_c0854c84:
    *(uint *)(iVar3 + 0x20) = uVar1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + 4) + 0x358));
    break;
  case 5:
    NKDbgPrintfW(L"SDIOSDSlotOptionHandler - called - SDHCDGetWriteProtectStatus : on slot %d  \r\n"
                 ,param_2);
    iVar3 = SDP_IOControl();
    if (iVar3 == 0) {
      NKDbgPrintfW(L"SDIOSDSlotOptionHandler - Card is NOT Write Protected\r\n");
      param_4[4] = 0;
      param_4[5] = 0;
    }
    else {
      NKDbgPrintfW(L"SDIOSDSlotOptionHandler - Card is Write Protected\r\n");
      param_4[4] = 1;
      param_4[5] = 0;
    }
    break;
  case 6:
    NKDbgPrintfW(L"SDIOSDSlotOptionHandler - called - SDHCDQueryBlockCapability : on slot %d  \r\n",
                 param_2);
    NKDbgPrintfW(L"SDIOSDSlotOptionHandler: Read Block Length: %d , Read Blocks: %d\r\n",*param_4,
                 param_4[2]);
    NKDbgPrintfW(L"SDIOSDSlotOptionHandler: Write Block Length: %d , Write Blocks: %d\r\n",
                 param_4[1],param_4[3]);
    if (0x800 < *param_4) {
      NKDbgPrintfW(L"SDIOSDSlotOptionHandler: Read Block Length: %d is out of the range!\r\n");
      *param_4 = 0x800;
    }
    if (0x800 < param_4[1]) {
      NKDbgPrintfW(L"SDIOSDSlotOptionHandler: Write Block Length: %d is out of the range!\r\n");
      param_4[1] = 0x800;
    }
    if (0x1ff < param_4[2]) {
      NKDbgPrintfW(L"SDIOSDSlotOptionHandler: Read Block count: %d is out of the range!\r\n");
      param_4[2] = 0x1ff;
    }
    if (0x1ff < param_4[3]) {
      NKDbgPrintfW(L"SDIOSDSlotOptionHandler: Write Block count: %d is out of the range!\r\n");
      param_4[3] = 0x1ff;
    }
    break;
  default:
    uVar4 = 0xc0000007;
    break;
  case 0xb:
    uVar2 = 0x13c;
    if ((*(int *)(&DAT_c08560d8 + param_2 * 0x14) == 1) &&
       (*(int *)((param_2 + 1) * 0x68 + iVar3) == 1)) {
      uVar2 = 0x8000013c;
    }
    *(undefined4 *)param_4 = uVar2;
    param_4[2] = 0x8000;
    param_4[3] = 0xff;
    param_4[4] = 0;
    param_4[5] = 0x10;
    param_4[6] = 0x7500;
    param_4[7] = 0x319;
    param_4[8] = 2;
    param_4[9] = 0;
  }
  return uVar4;
}



/* c0854ee4 FUN_c0854ee4 */

/* Boundary evidence: original MIPS .pdata c0854ee4..c08550e3. Semantic name remains unreviewed. */

int FUN_c0854ee4(int param_1)

{
  HANDLE pvVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  LPVOID lpParameter;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint local_28;
  DWORD DStack_24;
  
  lpParameter = *(LPVOID *)(param_1 + 0x4c);
  piVar5 = (int *)((int)lpParameter + 4);
  *(undefined4 *)((int)lpParameter + 0x14c) = 0;
  iVar3 = 0;
  piVar4 = piVar5;
  do {
    *(char *)(piVar4 + 10) = (char)iVar3;
    iVar3 = iVar3 + 1;
    *piVar4 = (int)lpParameter;
    piVar4 = piVar4 + 0x1a;
  } while (iVar3 < 3);
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)lpParameter + 0x358));
  *(undefined4 *)((int)lpParameter + 0x354) = 0;
  iVar3 = SDP_IOControl();
  if (iVar3 == 0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)lpParameter + 0x13c) = pvVar1;
    if ((pvVar1 != (HANDLE)0x0) &&
       (iVar2 = InterruptInitialize(*(undefined4 *)((int)lpParameter + 0x350),pvVar1,0,0),
       iVar2 != 0)) {
      *(undefined4 *)((int)lpParameter + 0x144) = 100;
      pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0853eac,lpParameter,0,&DStack_24);
      *(HANDLE *)((int)lpParameter + 0x140) = pvVar1;
      if (pvVar1 != (HANDLE)0x0) {
        iVar7 = 0;
        iVar2 = SDP_Close();
        if (0 < iVar2) {
          do {
            iVar3 = FUN_c0854714(piVar5);
            if (iVar3 != 0) goto LAB_c08550ac;
            iVar7 = iVar7 + 1;
            piVar5 = piVar5 + 0x1a;
            iVar2 = SDP_Close();
          } while (iVar7 < iVar2);
        }
        *(undefined4 *)((int)lpParameter + 0x148) = 1;
        EventModify(*(undefined4 *)((int)lpParameter + 0x13c),3);
        iVar7 = 0;
        iVar2 = SDP_Close();
        if (iVar2 < 1) {
          return iVar3;
        }
        puVar6 = (undefined4 *)((int)lpParameter + 0x18);
        do {
          if (puVar6[0x13] == 0) {
            local_28 = 200000;
            FUN_c085280c((int)(puVar6 + -5),&local_28);
            *puVar6 = 1;
            puVar6[3] = 0;
            FUN_c0855618();
          }
          else {
            EventModify(puVar6[8],3);
          }
          iVar7 = iVar7 + 1;
          puVar6 = puVar6 + 0x1a;
          iVar2 = SDP_Close();
        } while (iVar7 < iVar2);
        goto LAB_c08550ac;
      }
    }
    iVar3 = -0x3ffffff2;
  }
  else {
LAB_c08550ac:
    if (-1 < iVar3) {
      return iVar3;
    }
  }
  FUN_c085498c(param_1);
  return iVar3;
}



/* c08550e4 SDP_Close */

undefined4 SDP_Close(void)

{
                    /* 0x50e4  2  SDP_Close */
  return 1;
}



/* c08550ec SDP_IOControl */

undefined4 SDP_IOControl(void)

{
                    /* 0x50ec  4  SDP_IOControl
                       0x50ec  6  SDP_Open
                       0x50ec  9  SDP_Read
                       0x50ec  10  SDP_Seek
                       0x50ec  11  SDP_Write */
  return 0;
}



/* c08552b4 FUN_c08552b4 */

/* Boundary evidence: original MIPS .pdata c08552b4..c08552f3. Semantic name remains unreviewed. */

undefined4 FUN_c08552b4(void)

{
  FUN_c08554d4();
  DAT_c08560f4 = 0x34;
  DAT_c0856174 = 1;
  DAT_c0856178 = 1;
  return 1;
}



/* c08552f4 FUN_c08552f4 */

/* Boundary evidence: original MIPS .pdata c08552f4..c085531f. Semantic name remains unreviewed. */

undefined4 FUN_c08552f4(void)

{
  DAT_c0856178 = 0;
  DAT_c0856174 = 0;
  FUN_c08554d4();
  return 1;
}



/* c0855320 FUN_c0855320 */

/* Boundary evidence: original MIPS .pdata c0855320..c08553d3. Semantic name remains unreviewed. */

LSTATUS FUN_c0855320(LPCWSTR param_1,LPBYTE param_2,DWORD param_3)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14;
  
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0xf003f,&local_18);
  if (LVar1 == 0) {
    local_14 = param_3;
    LVar1 = RegQueryValueExW(local_18,L"Key",(LPDWORD)0x0,(LPDWORD)0x0,param_2,&local_14);
    RegCloseKey(local_18);
  }
  return LVar1;
}



/* c08553d4 FUN_c08553d4 */

/* Boundary evidence: original MIPS .pdata c08553d4..c085544b. Semantic name remains unreviewed. */

void FUN_c08553d4(void *param_1,void *param_2,uint param_3)

{
  if ((param_3 <= (int)param_1 + param_3) && (param_3 <= (int)param_2 + param_3)) {
    memcpy(param_1,param_2,param_3);
  }
  return;
}



/* c085544c FUN_c085544c */

/* Boundary evidence: original MIPS .pdata c085544c..c08554d3. Semantic name remains unreviewed. */

undefined4 FUN_c085544c(undefined4 param_1)

{
  int in_v0;
  
  *(undefined4 *)(in_v0 + -0x10) = param_1;
  *(undefined4 *)(in_v0 + -0x14) = **(undefined4 **)(in_v0 + -0x10);
  while (*(int *)(in_v0 + -0x14) != 0) {
    *(undefined4 *)(in_v0 + -0x14) = *(undefined4 *)(*(int *)(in_v0 + -0x14) + 8);
  }
  return 1;
}



/* c08554d4 FUN_c08554d4 */

void FUN_c08554d4(void)

{
  return;
}



/* c08554dc FUN_c08554dc */

/* Boundary evidence: original MIPS .pdata c08554dc..c08554f7. Semantic name remains unreviewed. */

void FUN_c08554dc(size_t param_1)

{
  malloc(param_1);
  return;
}



/* c08554f8 FUN_c08554f8 */

/* Boundary evidence: original MIPS .pdata c08554f8..c0855513. Semantic name remains unreviewed. */

void FUN_c08554f8(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}



/* c0855514 FUN_c0855514 */

/* Boundary evidence: original MIPS .pdata c0855514..c085552f. Semantic name remains unreviewed. */

void FUN_c0855514(void *param_1)

{
  free(param_1);
  return;
}



/* c0855530 FUN_c0855530 */

/* Boundary evidence: original MIPS .pdata c0855530..c0855557. Semantic name remains unreviewed. */

void FUN_c0855530(void)

{
  DAT_c0856188 = 0x28;
  SDHCDGetHCFunctions();
  return;
}



/* c0855558 FUN_c0855558 */

/* Boundary evidence: original MIPS .pdata c0855558..c085559f. Semantic name remains unreviewed. */

void FUN_c0855558(undefined4 param_1,undefined4 *param_2)

{
  (*DAT_c085618c)(param_1,param_2);
  if ((undefined4 *)*param_2 != (undefined4 *)0x0) {
    *(undefined4 *)*param_2 = 0x10000;
  }
  return;
}



/* c08555a0 FUN_c08555a0 */

/* Boundary evidence: original MIPS .pdata c08555a0..c08555c7. Semantic name remains unreviewed. */

void FUN_c08555a0(void)

{
  (*DAT_c0856190)();
  return;
}



/* c08555c8 FUN_c08555c8 */

/* Boundary evidence: original MIPS .pdata c08555c8..c08555ef. Semantic name remains unreviewed. */

void FUN_c08555c8(void)

{
  (*DAT_c0856194)();
  return;
}



/* c08555f0 FUN_c08555f0 */

/* Boundary evidence: original MIPS .pdata c08555f0..c0855617. Semantic name remains unreviewed. */

void FUN_c08555f0(void)

{
  (*DAT_c0856198)();
  return;
}



/* c0855618 FUN_c0855618 */

/* Boundary evidence: original MIPS .pdata c0855618..c085563f. Semantic name remains unreviewed. */

void FUN_c0855618(void)

{
  (*DAT_c085619c)();
  return;
}



/* c0855640 FUN_c0855640 */

/* Boundary evidence: original MIPS .pdata c0855640..c0855667. Semantic name remains unreviewed. */

void FUN_c0855640(void)

{
  (*DAT_c08561a0)();
  return;
}



/* c0855668 FUN_c0855668 */

/* Boundary evidence: original MIPS .pdata c0855668..c085568f. Semantic name remains unreviewed. */

void FUN_c0855668(void)

{
  (*DAT_c08561ac)();
  return;
}



/* c08556a0 FUN_c08556a0 */

/* Boundary evidence: original MIPS .pdata c08556a0..c08556e7. Semantic name remains unreviewed. */

void FUN_c08556a0(uint param_1)

{
  if ((param_1 == DAT_c0856134) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


