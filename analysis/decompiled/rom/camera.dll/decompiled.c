/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0972cd0 FUN_c0972cd0 */

/* Boundary evidence: original MIPS .pdata c0972cd0..c0972e77. Semantic name remains unreviewed. */

undefined4 FUN_c0972cd0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = *(int **)(param_1 + 0x18);
  uVar2 = piVar5[1] * *piVar5;
  if (piVar5[0x24] == 0) {
    if (piVar5[0x22] == 1) {
      *(uint *)(param_1 + 0xc) = uVar2 * 2;
      goto LAB_c0972d6c;
    }
  }
  else {
    if (piVar5[0x24] == 1) {
      *(uint *)(param_1 + 0xc) = uVar2 >> 2;
      *(uint *)(param_1 + 0x10) = uVar2 >> 1;
      *(uint *)(param_1 + 0x14) = uVar2 >> 2;
      goto LAB_c0972d6c;
    }
    if (piVar5[0x22] == 2) {
      *(uint *)(param_1 + 0x10) = uVar2;
    }
    else {
      *(uint *)(param_1 + 0x10) = uVar2 >> 1;
      *(uint *)(param_1 + 0x14) = uVar2 >> 1;
    }
  }
  *(uint *)(param_1 + 0xc) = uVar2;
LAB_c0972d6c:
  iVar6 = 0;
  if (0 < piVar5[0x28]) {
    do {
      if (iVar6 == 0) {
        Sleep(1);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < piVar5[0x28]);
  }
  if (iVar6 == piVar5[0x28]) {
    *DAT_c097404c = 1;
    DAT_c097404c[4] = 4;
    uVar4 = piVar5[0x24];
    uVar2 = ((piVar5[0x25] & 3U) << 2 | uVar4 & 3) << 6;
    uVar3 = uVar2 | 0x4808;
    if (uVar4 == 0) {
      uVar3 = uVar2 | 0x4809;
    }
    else if (uVar4 != 1) {
      if (uVar4 == 2) {
        if (piVar5[0x22] == 2) {
          uVar3 = uVar2 | 0x44808;
        }
      }
      else {
        uVar3 = uVar2 | 0x14808;
      }
    }
    DAT_c097404c[1] = uVar3;
    DAT_c097404c[7] = 0xbf;
    DAT_c097404c[6] = 0xbf;
    Sleep(6);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* c0972e78 CAM_Deinit */

/* Boundary evidence: original MIPS .pdata c0972e78..c0972f0f. Semantic name remains unreviewed. */

undefined4 CAM_Deinit(undefined4 *param_1)

{
                    /* 0x2e78  2  CAM_Deinit */
  if (param_1 != (undefined4 *)0x0) {
    param_1[10] = 0;
    *param_1 = 0;
    if (param_1[3] != 0) {
      if (param_1[2] != 0) {
        InterruptDisable();
        InterruptDisconnect(param_1[2]);
      }
      CloseHandle((HANDLE)param_1[3]);
    }
    if (DAT_c097404c != 0) {
      MmUnmapIoSpace(DAT_c097404c,0xd4);
      DAT_c097404c = 0;
    }
    LocalFree(param_1);
  }
  return 1;
}



/* c0972f10 CAM_Open */

undefined4 CAM_Open(undefined4 param_1)

{
                    /* 0x2f10  5  CAM_Open */
  return param_1;
}



/* c0972f18 CAM_Close */

undefined4 CAM_Close(void)

{
                    /* 0x2f18  1  CAM_Close */
  return 1;
}



/* c0972f20 CAM_PowerUp */

void CAM_PowerUp(undefined4 *param_1)

{
                    /* 0x2f20  7  CAM_PowerUp */
  *param_1 = 1;
  DAT_c0974050 = 0;
  return;
}



/* c0972f38 CAM_PowerDown */

void CAM_PowerDown(undefined4 *param_1)

{
                    /* 0x2f38  6  CAM_PowerDown */
  *param_1 = 0;
  DAT_c0974050 = 0;
  return;
}



/* c0972f4c CAM_IOControl */

/* Boundary evidence: original MIPS .pdata c0972f4c..c097335b. Semantic name remains unreviewed. */

bool CAM_IOControl(int *param_1,int param_2,int *param_3,int param_4,undefined4 *param_5,
                  uint param_6,undefined4 *param_7)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  DWORD dwErrCode;
  undefined4 *puVar5;
  undefined4 uVar6;
  
                    /* 0x2f4c  3  CAM_IOControl */
  uVar6 = 0;
  dwErrCode = 0;
  if (param_1 == (int *)0x0) {
    NKDbgPrintfW(L"CAM_IOControl - Device context not allocated\r\n");
LAB_c0972f98:
    dwErrCode = 0x1f;
    goto LAB_c09732fc;
  }
  if (param_2 == 0x1012000) {
    if (param_6 < 0x50) {
      dwErrCode = 0x7a;
      goto LAB_c09732fc;
    }
    puVar5 = (undefined4 *)param_1[10];
    if (puVar5 != (undefined4 *)0x0) {
      *param_5 = puVar5[0x23];
      memcpy(param_5 + 1,puVar5 + 0x12,0x40);
      param_5[0x11] = *puVar5;
      uVar6 = 0x50;
      param_5[0x12] = puVar5[1];
      param_5[0x13] = puVar5[0x26];
      goto LAB_c09732fc;
    }
LAB_c09732f8:
    dwErrCode = 0x8ca;
    goto LAB_c09732fc;
  }
  if (param_2 == 0x101a004) {
    if (param_4 != 4) {
      dwErrCode = 0xd;
      goto LAB_c09732fc;
    }
    iVar2 = 0;
    uVar3 = 0;
    do {
      if (*param_3 == *(int *)((int)&DAT_c09710a8 + uVar3)) break;
      uVar3 = uVar3 + 0x18c;
      iVar2 = iVar2 + 1;
    } while (uVar3 < 0x1bd8);
    if (iVar2 == 0x12) {
      dwErrCode = 0x585;
      goto LAB_c09732fc;
    }
    param_1[1] = iVar2;
    param_1[10] = (int)(&UNK_c097101c + iVar2 * 0x18c);
    if (*param_1 == 0) {
      *param_1 = 1;
    }
    *DAT_c097404c = *DAT_c097404c & 0xfffffffe;
    iVar2 = FUN_c0972cd0((int)(param_1 + 4));
    if (iVar2 == 0) {
      *param_1 = 0;
      Sleep(1);
      *param_1 = 1;
      Sleep(6);
      goto LAB_c09732fc;
    }
    goto LAB_c0972f98;
  }
  if (param_2 != 0x101a008) {
    dwErrCode = 0x32;
    goto LAB_c09732fc;
  }
  piVar4 = (int *)param_1[10];
  if (piVar4 == (int *)0x0) goto LAB_c09732f8;
  if (((uint)param_5 & 3) != 0) {
    dwErrCode = 0xd;
  }
  if (param_6 < (uint)(piVar4[1] * *piVar4)) {
    dwErrCode = 0x7a;
  }
  if (dwErrCode != 0) goto LAB_c09732fc;
  DVar1 = WaitForSingleObject((HANDLE)param_1[3],0);
  while (DVar1 == 0) {
    DAT_c097404c[7] = 0x1ff;
    InterruptDone(param_1[2]);
    DVar1 = WaitForSingleObject((HANDLE)param_1[3],0);
  }
  DAT_c097404c[0x30] = 0;
  DAT_c097404c[0x33] = 0;
  DAT_c097404c[0x28] = 0;
  DAT_c097404c[0x2b] = 0;
  DAT_c097404c[0x20] = 0;
  DAT_c097404c[0x23] = 0;
  iVar2 = piVar4[0x26];
  if (iVar2 == 1) {
LAB_c0973110:
    DAT_c097404c[0x20] = (uint)param_5;
    DAT_c097404c[0x23] = param_1[7];
  }
  else {
    if (iVar2 == 2) {
LAB_c09730f4:
      DAT_c097404c[0x28] = param_1[7] + (int)param_5;
      DAT_c097404c[0x2b] = param_1[8];
      goto LAB_c0973110;
    }
    if (iVar2 == 3) {
      DAT_c097404c[0x30] = param_1[8] + param_1[7] + (int)param_5;
      DAT_c097404c[0x33] = param_1[9];
      goto LAB_c09730f4;
    }
    NKDbgPrintfW(L"Unsupported number of DMA channels [0x%x]\r\n");
  }
  DAT_c097404c[2] = 0x93;
  DAT_c097404c[4] = 0;
  uVar3 = DAT_c097404c[5];
  while ((uVar3 & 3) != 0) {
    Sleep(10);
    uVar3 = DAT_c097404c[5];
  }
  DAT_c097404c[4] = 4;
  DAT_c097404c[4] = 2;
  WaitForSingleObject((HANDLE)param_1[3],1000);
  uVar3 = DAT_c097404c[7];
  DAT_c097404c[7] = uVar3;
  InterruptDone(param_1[2]);
  if ((uVar3 & 1) == 0) {
    dwErrCode = 0x5b4;
  }
LAB_c09732fc:
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = uVar6;
  }
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c097335c CAM_Init */

/* Boundary evidence: original MIPS .pdata c097335c..c097344f. Semantic name remains unreviewed. */

undefined4 * CAM_Init(void)

{
  undefined4 *_Dst;
  HANDLE pvVar1;
  int iVar2;
  
                    /* 0x335c  4  CAM_Init */
  _Dst = LocalAlloc(0x40,0x2c);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x2c);
    DAT_c097404c = MmMapIoSpace(0x14004000,0,0xd4,0);
    if (DAT_c097404c != 0) {
      pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      _Dst[3] = pvVar1;
      if (pvVar1 == (HANDLE)0xffffffff) {
        _Dst[3] = 0;
      }
      else {
        iVar2 = InterruptConnect(0,0,0x60,0);
        _Dst[2] = iVar2;
        if ((iVar2 != 0) && (iVar2 = InterruptInitialize(iVar2,_Dst[3],0,0), iVar2 != 0)) {
          InterruptDone(_Dst[2]);
          *_Dst = 0;
          _Dst[1] = 0;
          return _Dst;
        }
      }
    }
    CAM_Deinit(_Dst);
  }
  return (undefined4 *)0x0;
}


