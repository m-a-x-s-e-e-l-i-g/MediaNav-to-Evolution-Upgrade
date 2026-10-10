/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..000110a3. Semantic name remains unreviewed. */

undefined4 *
FUN_00011000(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00030010(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_0004f160;
  param_1[3] = param_4;
  memset(param_1 + 4,0,0x18);
  param_1[10] = 0;
  param_1[0xe] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x10] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x13] = 1;
  param_1[0xf] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined1 *)((int)param_1 + 0x61) = 0;
  *(undefined1 *)((int)param_1 + 0x62) = 0;
  *(undefined1 *)((int)param_1 + 99) = 0;
  *(undefined1 *)(param_1 + 0x19) = 0;
  param_1[0x17] = 0;
  return param_1;
}



/* 000110a4 FUN_000110a4 */

void FUN_000110a4(int param_1)

{
  if (*(int *)(param_1 + 0x5c) == 1) {
    DAT_00067678._3_1_ = *(undefined1 *)(param_1 + 0x60);
    DAT_0006767c = *(undefined1 *)(param_1 + 0x61);
    DAT_0006767d = *(undefined1 *)(param_1 + 0x62);
    DAT_0006767e = *(undefined1 *)(param_1 + 99);
    DAT_0006767f = *(undefined1 *)(param_1 + 100);
  }
  return;
}



/* 000110ec FUN_000110ec */

/* Boundary evidence: original MIPS .pdata 000110ec..000111e3. Semantic name remains unreviewed. */

void FUN_000110ec(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 local_20 [8];
  
  iVar1 = FUN_0001ddc8(DAT_00064a24);
  if ((iVar1 == 1) &&
     ((uVar2 = *(uint *)(param_1 + 0x38), uVar2 < 6 ||
      ((10 < uVar2 && ((uVar2 < 0xc || (0xd < uVar2)))))))) {
    local_20[0] = (undefined1)param_2;
    DAT_00067683 = local_20[0];
    if (*(int *)(param_1 + 0x44) == 1) {
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    if (*(int *)(DAT_00064a24 + 0x48) == 0) {
      FUN_00019e28(DAT_000648ec,param_2,*(undefined4 *)(param_1 + 0x44));
    }
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_20,1,0x32);
  }
  return;
}



/* 000111e4 FUN_000111e4 */

undefined1 FUN_000111e4(void)

{
  return DAT_00067683;
}



/* 000111f4 FUN_000111f4 */

/* Boundary evidence: original MIPS .pdata 000111f4..00011263. Semantic name remains unreviewed. */

void FUN_000111f4(int param_1,int param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00067678 = (param_2 << 0xb ^ DAT_00067678) & 0x800 ^ DAT_00067678;
  local_res4[0] = (undefined1)param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf9) = local_res4[0];
  FUN_00015158(DAT_000648e4,5,1,0x13,(int)local_res4,1,0x32);
  return;
}



/* 00011264 FUN_00011264 */

/* Boundary evidence: original MIPS .pdata 00011264..000112cb. Semantic name remains unreviewed. */

void FUN_00011264(int param_1,int param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00067678 = (param_2 << 8 ^ DAT_00067678) & 0x700 ^ DAT_00067678;
  local_res4[0] = (undefined1)param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf3) = local_res4[0];
  FUN_00014db0(DAT_000648e4,9,0x40,(int)local_res4,1,0x32);
  return;
}



/* 000112cc FUN_000112cc */

/* Boundary evidence: original MIPS .pdata 000112cc..00011327. Semantic name remains unreviewed. */

void FUN_000112cc(int param_1,undefined1 param_2)

{
  undefined1 local_res4 [12];
  
  DAT_0006767c = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf5) = param_2;
  local_res4[0] = param_2;
  FUN_00015158(DAT_000648e4,5,1,0x20,(int)local_res4,1,0x32);
  return;
}



/* 00011328 FUN_00011328 */

/* Boundary evidence: original MIPS .pdata 00011328..00011383. Semantic name remains unreviewed. */

void FUN_00011328(int param_1,undefined1 param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00067678._3_1_ = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf4) = param_2;
  local_res4[0] = param_2;
  FUN_00015158(DAT_000648e4,5,1,0x21,(int)local_res4,1,0x32);
  return;
}



/* 00011384 FUN_00011384 */

/* Boundary evidence: original MIPS .pdata 00011384..000113df. Semantic name remains unreviewed. */

void FUN_00011384(int param_1,undefined1 param_2)

{
  undefined1 local_res4 [12];
  
  DAT_0006767d = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf6) = param_2;
  local_res4[0] = param_2;
  FUN_00015158(DAT_000648e4,5,1,0x22,(int)local_res4,1,0x32);
  return;
}



/* 000113e0 FUN_000113e0 */

/* Boundary evidence: original MIPS .pdata 000113e0..0001143b. Semantic name remains unreviewed. */

void FUN_000113e0(int param_1,undefined1 param_2)

{
  undefined1 local_res4 [12];
  
  DAT_0006767e = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf7) = param_2;
  local_res4[0] = param_2;
  FUN_00015158(DAT_000648e4,5,1,0x23,(int)local_res4,1,0x32);
  return;
}



/* 0001143c FUN_0001143c */

/* Boundary evidence: original MIPS .pdata 0001143c..00011497. Semantic name remains unreviewed. */

void FUN_0001143c(int param_1,undefined1 param_2)

{
  undefined1 local_res4 [12];
  
  DAT_0006767f = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf8) = param_2;
  local_res4[0] = param_2;
  FUN_00015158(DAT_000648e4,5,1,0x24,(int)local_res4,1,0x32);
  return;
}



/* 00011498 FUN_00011498 */

/* Boundary evidence: original MIPS .pdata 00011498..000115b7. Semantic name remains unreviewed. */

void FUN_00011498(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 local_18 [8];
  
  if (*(int *)(param_1 + 0x44) == 1) {
    if (param_3 == 0) {
      iVar1 = *(int *)(param_1 + 0x38);
      if (((iVar1 == 8) || (iVar1 == 10)) || (iVar1 == 0xc)) {
        param_3 = (uint)DAT_00067685;
      }
      else if (iVar1 == 7) {
        param_3 = (uint)DAT_00067684;
      }
      else {
        param_3 = (uint)DAT_00067683;
      }
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
    local_18[0] = (undefined1)param_3;
    if ((*(int *)(DAT_00064a24 + 0x48) == 0) && (param_2 == 1)) {
      FUN_00019e28(DAT_000648ec,param_3,0);
    }
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_18,1,0x32);
    iVar1 = *(int *)(param_1 + 0x44);
    if (*(int *)(param_1 + 0x48) != iVar1) {
      *(int *)(param_1 + 0x48) = iVar1;
      FUN_00036de8(0x75,iVar1);
    }
  }
  return;
}



/* 000115b8 FUN_000115b8 */

/* Boundary evidence: original MIPS .pdata 000115b8..00011903. Semantic name remains unreviewed. */

void FUN_000115b8(int param_1,undefined4 param_2,int param_3)

{
  BOOL BVar1;
  wchar_t *pwVar2;
  int iVar3;
  undefined4 uVar4;
  byte local_28 [2];
  byte local_26;
  byte local_25;
  
  if (*(int *)(param_1 + 0x2c) == 1) {
    local_25 = 0;
  }
  else {
    local_25 = DAT_00067683;
  }
  switch(param_2) {
  case 0:
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_RADIO\r\n");
    local_26 = 0;
    break;
  case 1:
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_AUX\r\n");
    local_26 = 2;
    break;
  case 2:
    pwVar2 = L"MGRMCM_AUDIOSRC_USB\r\n";
    goto LAB_0001166c;
  case 3:
    pwVar2 = L"MGRMCM_AUDIOSRC_IPOD\r\n";
    goto LAB_0001166c;
  case 4:
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_DAB\r\n");
    local_26 = 1;
    break;
  case 5:
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_BTAUDIO\r\n");
    local_26 = 5;
    break;
  case 6:
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_AHA_BT\r\n");
    goto LAB_000116d4;
  case 7:
    pwVar2 = L"MGRMCM_AUDIOSRC_AHA_USB\r\n";
LAB_0001166c:
    NKDbgPrintfW(pwVar2);
LAB_0001170c:
    local_26 = 3;
    break;
  case 8:
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_AHA_USB\r\n");
LAB_000116d4:
    local_26 = 3;
    break;
  default:
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_NONE\r\n");
    local_25 = 0;
    goto LAB_0001170c;
  }
  FUN_00015158(DAT_000648e4,5,1,0,(int)&local_26,2,0x32);
  *(uint *)(param_1 + 0x38) = (uint)local_26;
  if (param_3 != 0) {
    local_28[0] = 0;
    Sleep(0xfa);
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_28,1,0x32);
    FUN_00015158(DAT_000648e4,5,1,0x1b,(int)local_28,1,0x32);
    goto LAB_000118cc;
  }
  if (*(int *)(param_1 + 0x44) != 1) goto LAB_000118cc;
  NKDbgPrintfW(L"Audio Source CHANGED!!!!! VOL status: MUTE %d \n",
               *(undefined4 *)(DAT_00064a24 + 0x48));
  local_28[0] = DAT_00067683;
  if (*(int *)(param_1 + 0x2c) == 1) {
    local_28[0] = DAT_00067686;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  if (*(int *)(DAT_00064a24 + 0x48) == 0) {
    uVar4 = 0;
LAB_0001183c:
    FUN_00019e28(DAT_000648ec,(uint)local_28[0],uVar4);
  }
  else {
    BVar1 = IsWindowVisible(*(HWND *)(param_1 + 4));
    if ((BVar1 != 0) && (*(int *)(DAT_000648ec + 0x1c) == 3)) {
      uVar4 = *(undefined4 *)(param_1 + 0x44);
      goto LAB_0001183c;
    }
  }
  Sleep(0xfa);
  if (*(int *)(param_1 + 0x2c) == 1) {
    FUN_00015158(DAT_000648e4,5,1,0x1b,(int)local_28,1,0x32);
  }
  else {
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_28,1,0x32);
  }
  iVar3 = *(int *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x48) != iVar3) {
    *(int *)(param_1 + 0x48) = iVar3;
    FUN_00036de8(0x75,iVar3);
    NKDbgPrintfW(L"Audio : Send IDM_MMCM_AMAIN_MUTE : 0x%x\r\n",*(undefined4 *)(param_1 + 0x44));
  }
LAB_000118cc:
  *(undefined4 *)(param_1 + 0x4c) = 1;
  FUN_0002fec8(DAT_000673c8);
  return;
}



/* 00011904 FUN_00011904 */

/* Boundary evidence: original MIPS .pdata 00011904..00011cdb. Semantic name remains unreviewed. */

void FUN_00011904(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  UINT UVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  undefined1 local_30 [4];
  int local_2c;
  
  piVar4 = (int *)((param_2 + 4) * 4 + param_1);
  if (*piVar4 == param_3) {
    return;
  }
  *piVar4 = param_3;
  local_2c = param_1;
  if (param_3 == 1) {
    piVar6 = (int *)(param_1 + 0x10);
    uVar5 = 0;
    piVar4 = piVar6;
    do {
      if (((uVar5 == 0) || (uVar5 == 1)) || (uVar5 == 4)) {
        if ((*piVar4 == 1) && (uVar5 != param_2)) {
          *piVar4 = 0;
          NKDbgPrintfW(L"[=================================]\r\n");
          NKDbgPrintfW(L"[= SoundOverlay() Enable %d <= %d =\r\n",uVar5,param_2);
          NKDbgPrintfW(L"[=================================]\r\n");
        }
      }
      else {
        NKDbgPrintfW(L"\r\n====>[INFO] SoundOverlay() Enable %d <= %d[%d] <====\r\n",uVar5,param_2,
                     *piVar4);
      }
      iVar2 = local_2c;
      uVar5 = uVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar5 < 6);
    uVar5 = 0;
    if (param_2 != 0) {
      do {
        if (*piVar6 == 1) break;
        uVar5 = uVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (uVar5 < param_2);
    }
    if (uVar5 != param_2) {
      return;
    }
    FUN_000290b8(DAT_000673c8);
    *(undefined4 *)(iVar2 + 0x3c) = 1;
    *(uint *)(iVar2 + 0x54) = param_2;
    *(undefined4 *)(iVar2 + 0x50) = 2;
    FUN_00030044(iVar2,0x32);
    local_30[0] = 0;
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_30,1,0x32);
    if (param_2 == 0) {
      iVar2 = 0;
    }
    else {
      if (param_2 != 4) {
        if (param_2 != 1) {
          return;
        }
        if (DAT_0006482c != 1) {
          return;
        }
        goto LAB_00011c98;
      }
      iVar2 = 1;
    }
    DAT_0006482c = 1;
    StartEC(iVar2,1);
  }
  else {
    uVar5 = 0;
    if (param_2 != 0) {
      piVar6 = (int *)(param_1 + 0x10);
      do {
        if (*piVar6 == 1) break;
        uVar5 = uVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (uVar5 < param_2);
    }
    uVar1 = param_2;
    if (uVar5 == param_2) {
      for (; (uVar1 < 6 && (*piVar4 != 1)); piVar4 = piVar4 + 1) {
        uVar1 = uVar1 + 1;
      }
      if (uVar1 == 6) {
        FUN_000290b8(DAT_000673c8);
        *(undefined4 *)(param_1 + 0x3c) = 1;
        *(uint *)(param_1 + 0x54) = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0xaec);
        *(undefined4 *)(param_1 + 0x50) = 1;
        if ((*(int *)(param_1 + 0x44) == 1) && ((param_2 == 1 || (param_2 == 2)))) {
          *(undefined4 *)(param_1 + 0x50) = 3;
          FUN_00030044(param_1,0);
        }
        else {
          FUN_00030044(param_1,0x32);
          local_30[0] = 0;
          FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_30,1,0x32);
        }
      }
      else {
        FUN_000290b8(DAT_000673c8);
        *(undefined4 *)(param_1 + 0x3c) = 1;
        *(uint *)(param_1 + 0x54) = uVar1;
        *(undefined4 *)(param_1 + 0x50) = 2;
        UVar3 = 500;
        if (uVar1 != 4) {
          UVar3 = 0xfa;
        }
        FUN_00030044(param_1,UVar3);
        local_30[0] = 0;
        FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_30,1,0x32);
      }
    }
    if ((param_2 != 0) && (param_2 != 4)) {
      if (param_2 != 2) {
        return;
      }
      FUN_0002fde4(DAT_000673c8,0);
      if (*(int *)(param_1 + 0x44) != 0) {
        return;
      }
      FUN_00036de8(0x75,0);
      return;
    }
LAB_00011c98:
    DAT_0006482c = 0;
    EndEC();
  }
  return;
}



/* 00011cdc FUN_00011cdc */

/* Boundary evidence: original MIPS .pdata 00011cdc..00011db7. Semantic name remains unreviewed. */

void FUN_00011cdc(int param_1)

{
  uint uVar1;
  undefined1 local_20 [8];
  
  uVar1 = *(uint *)(param_1 + 0x38);
  if ((((uVar1 < 6) || (uVar1 == 9)) || (uVar1 == 0xb)) || (uVar1 == 0xd)) {
    local_20[0] = 0;
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_20,1,0x32);
  }
  local_20[0] = DAT_00067686;
  if (*(int *)(param_1 + 0x44) == 1) {
    local_20[0] = 0;
  }
  FUN_00015158(DAT_000648e4,5,1,0x1b,(int)local_20,1,0x32);
  return;
}



/* 00011db8 FUN_00011db8 */

/* Boundary evidence: original MIPS .pdata 00011db8..00011e87. Semantic name remains unreviewed. */

void FUN_00011db8(int param_1)

{
  uint uVar1;
  undefined1 local_10 [8];
  
  uVar1 = *(uint *)(param_1 + 0x38);
  if (5 < uVar1) {
    if (uVar1 == 9) {
      local_10[0] = DAT_00067687;
      FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_10,1,0x32);
      return;
    }
    if ((uVar1 != 0xb) && (uVar1 != 0xd)) {
      return;
    }
  }
  local_10[0] = DAT_00067683;
  FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_10,1,0x32);
  return;
}



/* 00011e88 FUN_00011e88 */

undefined4 FUN_00011e88(int param_1)

{
  return *(undefined4 *)(param_1 + 0x38);
}



/* 00011e90 FUN_00011e90 */

/* Boundary evidence: original MIPS .pdata 00011e90..00011f3f. Semantic name remains unreviewed. */

undefined1 FUN_00011e90(int param_1)

{
  undefined1 uVar1;
  
  switch(*(undefined4 *)(param_1 + 0x38)) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 0xb:
  case 0xd:
    uVar1 = DAT_00067683;
    break;
  default:
    NKDbgPrintfW(L"[Error][%s] --- [%d]\r\n","CAudio::GetCurSourceVolume");
    uVar1 = 0xff;
    break;
  case 7:
    uVar1 = DAT_00067684;
    break;
  case 8:
  case 10:
  case 0xc:
    uVar1 = DAT_00067685;
    break;
  case 9:
    uVar1 = DAT_00067687;
  }
  return uVar1;
}



/* 00011f40 FUN_00011f40 */

undefined4 FUN_00011f40(int param_1)

{
  return *(undefined4 *)(param_1 + 0x3c);
}



/* 00011f48 FUN_00011f48 */

/* Boundary evidence: original MIPS .pdata 00011f48..00011fab. Semantic name remains unreviewed. */

void FUN_00011f48(int param_1)

{
  undefined1 local_10 [8];
  
  if (*(int *)(param_1 + 0x2c) == 1) {
    local_10[0] = 0;
    FUN_00015158(DAT_000648e4,5,1,0x1b,(int)local_10,1,0x32);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return;
}



/* 00011fac FUN_00011fac */

/* Boundary evidence: original MIPS .pdata 00011fac..0001221b. Semantic name remains unreviewed. */

void FUN_00011fac(void)

{
  errno_t eVar1;
  long lVar2;
  undefined1 *puVar3;
  uint uVar4;
  FILE *local_428;
  char local_424 [12];
  undefined1 local_418 [1024];
  uint local_18;
  
  local_18 = DAT_00064820;
  memset(local_418,0,0x400);
  eVar1 = fopen_s(&local_428,".\\Storage Card\\system\\arkamys_update.dat","rb");
  if (eVar1 != 0) {
    local_428 = (FILE *)0x0;
  }
  if (local_428 != (FILE *)0x0) {
    fseek(local_428,0,2);
    lVar2 = ftell(local_428);
    fseek(local_428,0,0);
    if (lVar2 == 0x395) {
      fread(local_418,0x395,1,local_428);
    }
    else if (lVar2 == 0x72a) {
      uVar4 = 0;
      local_424[0] = '\0';
      local_424[1] = 0;
      local_424[2] = 0;
      local_424[3] = 0;
      do {
        fread(local_424,2,1,local_428);
        local_424[3] = 0;
        sscanf_s(local_424,"%x",local_424 + 4);
        puVar3 = local_418 + uVar4;
        uVar4 = uVar4 + 1;
        *puVar3 = (char)local_424._4_4_;
      } while (uVar4 < 0x395);
    }
    fclose(local_428);
    FUN_00014db0(DAT_000648e4,0xf,0x21,(int)local_418,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x22,(int)(local_418 + 0x80),0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x23,(int)(local_418 + 0x100),0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x24,(int)(local_418 + 0x180),0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x25,(int)(local_418 + 0x200),0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x26,(int)(local_418 + 0x280),0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x27,(int)(local_418 + 0x300),0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x28,(int)(local_418 + 0x380),0x80,300);
    FUN_00015158(DAT_000648e4,5,1,0x60,0,0,200);
    DeleteFileW(L".\\Storage Card\\system\\arkamys_update.dat");
  }
  FUN_0004a3f4(local_18);
  return;
}



/* 0001221c FUN_0001221c */

/* Boundary evidence: original MIPS .pdata 0001221c..00012417. Semantic name remains unreviewed. */

void FUN_0001221c(int param_1,int param_2)

{
  byte local_10 [8];
  
  if (param_2 == 0) {
    DAT_00067683 = 0xf;
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaee) = 0xf;
    DAT_00067684 = 0xf;
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaef) = 0xf;
    DAT_00067685 = 0xf;
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf0) = 0xf;
    DAT_00067686 = 0xf;
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf1) = 0xf;
  }
  else {
    if (0xf < DAT_00067683) {
      DAT_00067683 = 0xf;
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaee) = 0xf;
    }
    if (0x1f < DAT_00067684) {
      DAT_00067684 = 0xf;
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaef) = 0xf;
    }
    if (0x1f < DAT_00067685) {
      DAT_00067685 = 0xf;
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf0) = 0xf;
    }
    if (0x1f < DAT_00067686) {
      DAT_00067686 = 0xf;
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf1) = 0xf;
    }
    if (DAT_00067687 < 0x20) goto LAB_00012340;
  }
  DAT_00067687 = 0xf;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaf2) = 0xf;
  DAT_00067688 = 5;
LAB_00012340:
  if (*(int *)(param_1 + 0x28) == 1) {
    FUN_00011cdc(param_1);
  }
  else {
    switch(*(undefined4 *)(param_1 + 0x38)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 0xb:
    case 0xd:
      local_10[0] = DAT_00067683;
      break;
    default:
      NKDbgPrintfW(L"[Error][%s] Oh~~~~ Invalid m_nCurAudioSrc[%d]\r\n","CAudio::ResetVolume");
      break;
    case 7:
      local_10[0] = DAT_00067684;
      break;
    case 8:
    case 10:
    case 0xc:
      local_10[0] = DAT_00067685;
      break;
    case 9:
      local_10[0] = DAT_00067687;
    }
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_10,1,0x32);
  }
  FUN_00036de8(0x82,5);
  return;
}



/* 00012418 FUN_00012418 */

/* Boundary evidence: original MIPS .pdata 00012418..0001246f. Semantic name remains unreviewed. */

undefined4 * FUN_00012418(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0004f160;
  FUN_0003008c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00012470 FUN_00012470 */

/* Boundary evidence: original MIPS .pdata 00012470..000126bb. Semantic name remains unreviewed. */

void FUN_00012470(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined1 local_28;
  undefined1 local_27 [7];
  
  iVar2 = FUN_0001de14(DAT_00064a24);
  if (iVar2 != 1) {
    return;
  }
  bVar1 = false;
  if ((((*(int *)(param_1 + 0x28) == 1) && (iVar2 = *(int *)(param_1 + 0x38), iVar2 != 7)) &&
      (iVar2 != 8)) && ((iVar2 != 10 && (iVar2 != 0xc)))) {
    if (*(int *)(param_1 + 0x44) == 1) {
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    FUN_00011cdc(param_1);
    goto LAB_0001266c;
  }
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 == 6) {
    local_28 = DAT_00067686;
    if (param_2 == 1) goto LAB_000125c4;
  }
  else {
    if (iVar2 == 7) {
      iVar2 = 3;
      local_28 = DAT_00067684;
    }
    else {
      if (iVar2 != 8) {
        if (iVar2 == 9) {
          iVar2 = 4;
          local_28 = DAT_00067687;
          goto LAB_00012578;
        }
        if ((iVar2 != 10) && (iVar2 != 0xc)) {
          local_28 = DAT_00067683;
          if (param_2 == 0) goto LAB_000125c4;
          goto LAB_000125c8;
        }
      }
      iVar2 = 2;
      local_28 = DAT_00067685;
    }
LAB_00012578:
    if (param_2 == iVar2) {
LAB_000125c4:
      bVar1 = true;
    }
  }
LAB_000125c8:
  if (*(int *)(param_1 + 0x44) == 1) {
    *(undefined4 *)(param_1 + 0x44) = 0;
    bVar1 = true;
  }
  if (DAT_00068074 == 1) {
    local_27[0] = 0;
    FUN_00014db0(DAT_000648e4,0,0x30,(int)local_27,1,0x32);
  }
  if (bVar1) {
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)&local_28,1,0x32);
  }
  if (DAT_00068074 == 1) {
    local_27[0] = 1;
    FUN_00014db0(DAT_000648e4,0,0x30,(int)local_27,1,0x32);
  }
LAB_0001266c:
  iVar2 = *(int *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x48) != iVar2) {
    *(int *)(param_1 + 0x48) = iVar2;
    FUN_00036de8(0x75,iVar2);
    NKDbgPrintfW(L"Audio : Send IDM_MMCM_AMAIN_MUTE : 0x%x\r\n",*(undefined4 *)(param_1 + 0x44));
  }
  return;
}



/* 000126bc FUN_000126bc */

/* Boundary evidence: original MIPS .pdata 000126bc..00012787. Semantic name remains unreviewed. */

void FUN_000126bc(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  undefined1 local_18 [8];
  
  if (*(byte *)(*(int *)(param_1 + 0xc) + 0xaec) != param_2) {
    uVar2 = 0;
    piVar1 = (int *)(param_1 + 0x10);
    do {
      if (*piVar1 == 1) goto LAB_00012768;
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (uVar2 < 6);
    FUN_000290b8(DAT_000673c8);
    *(undefined4 *)(param_1 + 0x3c) = 1;
    *(uint *)(param_1 + 0x54) = param_2;
    *(undefined4 *)(param_1 + 0x50) = 1;
    FUN_00030044(param_1,0x32);
    local_18[0] = 0;
    FUN_00015158(DAT_000648e4,5,1,0x12,(int)local_18,1,100);
LAB_00012768:
    *(char *)(*(int *)(param_1 + 0xc) + 0xaec) = (char)param_2;
  }
  return;
}



/* 00012788 FUN_00012788 */

/* Boundary evidence: original MIPS .pdata 00012788..00012847. Semantic name remains unreviewed. */

void FUN_00012788(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x28) != param_2) {
    *(undefined4 *)(param_1 + 0x4c) = 1;
    *(int *)(param_1 + 0x28) = param_2;
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0x2c) = 1;
      if (*(int *)(param_1 + 0x50) == 4) {
        *(undefined4 *)(param_1 + 0x34) = 1;
      }
      else {
        FUN_00011cdc(param_1);
        Sleep(100);
      }
    }
    else if (*(int *)(param_1 + 0x44) == 1) {
      FUN_00011f48(param_1);
    }
    else {
      FUN_00011f48(param_1);
      if (*(int *)(param_1 + 0x50) == 4) {
        *(undefined4 *)(param_1 + 0x30) = 1;
      }
      else {
        FUN_00011db8(param_1);
      }
    }
  }
  return;
}



/* 00012848 FUN_00012848 */

/* Boundary evidence: original MIPS .pdata 00012848..000128e7. Semantic name remains unreviewed. */

void FUN_00012848(int param_1)

{
  FUN_00011264(param_1,DAT_00067678 >> 8 & 7);
  FUN_000111f4(param_1,DAT_00067678 >> 0xb & 1);
  FUN_000112cc(param_1,DAT_0006767c);
  FUN_00011328(param_1,DAT_00067678._3_1_);
  FUN_00011384(param_1,DAT_0006767d);
  FUN_000113e0(param_1,DAT_0006767e);
  FUN_0001143c(param_1,DAT_0006767f);
  FUN_0001221c(param_1,0);
  return;
}



/* 000128e8 FUN_000128e8 */

/* Boundary evidence: original MIPS .pdata 000128e8..00012a53. Semantic name remains unreviewed. */

void FUN_000128e8(int param_1,uint param_2,uint param_3,int param_4)

{
  wchar_t *pwVar1;
  byte bVar2;
  int iVar3;
  
  if (param_3 < 0x20) {
    bVar2 = (byte)param_3;
    if (param_2 == 0) {
      iVar3 = 0;
      DAT_00067683 = bVar2;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaee) = bVar2;
    }
    else if (param_2 == 1) {
      iVar3 = 1;
      DAT_00067686 = bVar2;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaf1) = bVar2;
    }
    else if (param_2 == 2) {
      iVar3 = 2;
      DAT_00067685 = bVar2;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaf0) = bVar2;
    }
    else if (param_2 == 3) {
      iVar3 = 3;
      DAT_00067684 = bVar2;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaef) = bVar2;
    }
    else {
      if (param_2 != 4) {
        pwVar1 = L"[Error][%d] Oh~~~~ Invalid source[%d]\r\n";
        param_3 = param_2;
        goto LAB_0001295c;
      }
      iVar3 = ((param_3 & 0xff) - (uint)DAT_00067683) + 5;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else if (0xf < iVar3) {
        iVar3 = 0xf;
      }
      DAT_00067688 = (undefined1)iVar3;
      iVar3 = 4;
      DAT_00067687 = bVar2;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaf2) = bVar2;
    }
    if (param_4 == 0) {
      FUN_00012470(param_1,iVar3);
    }
    else {
      FUN_00036de8(0x82,iVar3);
    }
  }
  else {
    pwVar1 = L"[Error][%s] Oh~~~~ Invalid volume level[%d]\r\n";
LAB_0001295c:
    NKDbgPrintfW(pwVar1,"CAudio::UpdateIndSrcVolume",param_3);
  }
  return;
}



/* 00012a54 FUN_00012a54 */

/* Boundary evidence: original MIPS .pdata 00012a54..00013013. Semantic name remains unreviewed. */

void FUN_00012a54(int param_1,uint param_2,char *param_3)

{
  wchar_t *pwVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  char *pcVar6;
  undefined1 local_20;
  byte local_1f;
  
  if (0xcd < param_2) {
    if (param_2 != 0xd0) {
      return;
    }
    uVar3 = (uint)(param_3 != (char *)0x0);
    uVar2 = 5;
    goto LAB_00012ff0;
  }
  if (param_2 == 0xcd) {
    uVar3 = (uint)(param_3 != (char *)0x0);
    uVar2 = 4;
    goto LAB_00012ff0;
  }
  bVar5 = (byte)param_3;
  switch(param_2) {
  case 100:
    FUN_000126bc(param_1,(uint)param_3);
    break;
  case 0x66:
    uVar3 = (uint)(param_3 != (char *)0x0);
    uVar2 = 1;
    goto LAB_00012ff0;
  case 0x67:
    uVar3 = (uint)(param_3 != (char *)0x0);
    uVar2 = 0;
LAB_00012ff0:
    FUN_00011904(param_1,uVar2,uVar3);
    break;
  case 0x68:
    pcVar6 = "CAudio::OnMessage";
    NKDbgPrintfW(L"%S : IDM_X_MMCM_SOEN_TA : %d\r\n","CAudio::OnMessage",param_3);
    if (param_3 == (char *)0x0) {
      FUN_00011904(param_1,2,0);
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xae9) = 0;
      return;
    }
    iVar4 = FUN_000298b0(DAT_000673c8);
    if (iVar4 == 1) {
      FUN_00011904(param_1,2,1);
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xae9) = 1;
      return;
    }
    FUN_00011904(param_1,2,0);
    pwVar1 = L"%S : IDM_X_MMCM_SOEN_TA : g_pRadio->IsTA() returns FALSE. Check out!!\r\n";
    goto LAB_00012e64;
  case 0x69:
    FUN_00012788(param_1,(uint)(param_3 != (char *)0x0));
    break;
  case 0x72:
    if (param_3 < (char *)0x20) {
      iVar4 = 0;
      DAT_00067683 = bVar5;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaee) = bVar5;
LAB_00012c38:
      FUN_00012470(param_1,iVar4);
      return;
    }
    goto LAB_00012c00;
  case 0x73:
    if (param_3 < (char *)0x20) {
      iVar4 = 3;
      DAT_00067684 = bVar5;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaef) = bVar5;
      goto LAB_00012c38;
    }
    goto LAB_00012c00;
  case 0x74:
    if (param_3 < (char *)0x20) {
      iVar4 = 2;
      DAT_00067685 = bVar5;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaf0) = bVar5;
      goto LAB_00012c38;
    }
    goto LAB_00012c00;
  case 0x75:
    if (param_3 < (char *)0x20) {
      iVar4 = 1;
      DAT_00067686 = bVar5;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaf1) = bVar5;
      goto LAB_00012c38;
    }
LAB_00012c00:
    NKDbgPrintfW(L"[Error][%s] Oh~~~~ Invalid volume level[%d]\r\n","CAudio::UpdateIndSrcVolume",
                 param_3);
    break;
  case 0x76:
    FUN_000128e8(param_1,4,(uint)param_3,0);
    break;
  case 0x77:
    FUN_00011264(param_1,(uint)param_3 & 0xff);
    break;
  case 0x78:
    FUN_00011328(param_1,bVar5);
    break;
  case 0x79:
    FUN_000112cc(param_1,bVar5);
    break;
  case 0x7a:
    FUN_00011384(param_1,bVar5);
    break;
  case 0x7b:
    FUN_000113e0(param_1,bVar5);
    break;
  case 0x7c:
    FUN_0001143c(param_1,bVar5);
    break;
  case 0x7d:
    FUN_000111f4(param_1,(uint)param_3 & 0xff);
    break;
  case 0x7e:
    goto switchD_00012ab0_caseD_7e;
  case 0x7f:
    if (*(int *)(param_1 + 0x5c) != 1) {
      return;
    }
    FUN_00011328(param_1,*(undefined1 *)(param_1 + 0x60));
    FUN_000112cc(param_1,*(undefined1 *)(param_1 + 0x61));
    FUN_00011384(param_1,*(undefined1 *)(param_1 + 0x62));
    FUN_000113e0(param_1,*(undefined1 *)(param_1 + 99));
    FUN_0001143c(param_1,*(undefined1 *)(param_1 + 100));
    goto switchD_00012ab0_caseD_7e;
  case 0x80:
    iVar4 = *(int *)(param_1 + 0xc);
    *(undefined1 *)(param_1 + 0x60) = *(undefined1 *)(iVar4 + 0xaf4);
    *(undefined1 *)(param_1 + 0x61) = *(undefined1 *)(iVar4 + 0xaf5);
    *(undefined1 *)(param_1 + 0x62) = *(undefined1 *)(iVar4 + 0xaf6);
    *(undefined1 *)(param_1 + 99) = *(undefined1 *)(iVar4 + 0xaf7);
    *(undefined1 *)(param_1 + 100) = *(undefined1 *)(iVar4 + 0xaf8);
    *(undefined4 *)(param_1 + 0x5c) = 1;
    break;
  case 0x8a:
    if (DAT_00062490 != param_3) {
      if (param_3 == (char *)0x0) {
        FUN_00015158(DAT_000648e4,5,1,0x16,0,0,0x32);
        DAT_00062490 = param_3;
        return;
      }
      FUN_00015158(DAT_000648e4,5,1,0x15,0,0,0x32);
      DAT_00062490 = param_3;
      return;
    }
    pwVar1 = L" [Micom manager]SAME AS PRIVIOUS : g_ulMuteMic %d!!\r\n";
    pcVar6 = DAT_00062490;
    goto LAB_00012e64;
  case 0x8b:
    if (DAT_00062494 != param_3) {
      if (param_3 == (char *)0x0) {
        FUN_00015158(DAT_000648e4,5,1,0x1f,0,0,0x32);
        DAT_00062494 = param_3;
        return;
      }
      FUN_00015158(DAT_000648e4,5,1,0x1e,0,0,0x32);
      DAT_00062494 = param_3;
      return;
    }
    pwVar1 = L" [Micom manager]SAME AS PRIVIOUS : g_ulMuteMedia %d!!\r\n";
    pcVar6 = DAT_00062494;
LAB_00012e64:
    NKDbgPrintfW(pwVar1,pcVar6);
    break;
  case 0x8c:
    if (param_3 == (char *)0x0) {
      FUN_00011498(param_1,1,0);
      NKDbgPrintfW(L" [Micom manager]IDM_X_MMCM_VOL_MUTE : Unmute!!\r\n");
    }
    break;
  case 0x8e:
    if (*(int *)(param_1 + 0x48) == 1) {
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      FUN_00036de8(0x75,0);
      NKDbgPrintfW(L"Audio::OnMessage(IDM_X_MMCM_SET_VOL_RESET) : Send IDM_MMCM_AMAIN_MUTE : 0x%x\r\n"
                   ,*(undefined4 *)(param_1 + 0x44));
    }
    FUN_0001221c(param_1,0);
    break;
  case 0x8f:
    local_20 = 3;
    local_1f = DAT_00067683;
    if (DAT_00067683 < 10) {
      local_1f = 10;
    }
    FUN_00015158(DAT_000648e4,5,1,0x40,(int)&local_20,2,100);
  }
  return;
switchD_00012ab0_caseD_7e:
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}



/* 00013014 FUN_00013014 */

/* Boundary evidence: original MIPS .pdata 00013014..0001358b. Semantic name remains unreviewed. */

void FUN_00013014(int param_1,int param_2)

{
  int iVar1;
  LPARAM LVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_20;
  undefined1 local_1f [7];
  
  iVar1 = FUN_0001de14(DAT_00064a24);
  if (iVar1 != 1) {
    return;
  }
  if ((((*(int *)(param_1 + 0x28) == 1) && (iVar1 = *(int *)(param_1 + 0x38), iVar1 != 7)) &&
      (iVar1 != 8)) && ((iVar1 != 10 && (iVar1 != 0xc)))) {
    if (param_2 == 6) {
      if (*(int *)(param_1 + 0x44) == 0) {
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
      else {
LAB_000130c4:
        *(undefined4 *)(param_1 + 0x44) = 0;
      }
      uVar4 = (uint)DAT_00067686;
    }
    else {
      if (*(int *)(param_1 + 0x44) == 1) goto LAB_000130c4;
      if ((param_2 == 2) || (param_2 == 4)) {
        iVar1 = 1;
      }
      else {
        iVar1 = -1;
      }
      uVar5 = iVar1 + (uint)DAT_00067686;
      if ((int)uVar5 < 1) {
        uVar5 = 1;
      }
      else if (0x1f < (int)uVar5) {
        uVar5 = 0x1f;
      }
      uVar4 = uVar5 & 0xff;
      DAT_00067686 = (byte)uVar5;
    }
    if (*(int *)(DAT_00064a24 + 0x48) == 0) {
      iVar1 = *(int *)(param_1 + 0x44);
      if (iVar1 == 1) {
        uVar4 = (uint)DAT_00067683;
        iVar1 = 1;
      }
      FUN_00019e28(DAT_000648ec,uVar4,iVar1);
    }
    FUN_00011cdc(param_1);
    if (DAT_00067686 < 0x20) {
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaf1) = DAT_00067686;
      FUN_00036de8(0x82,1);
    }
    else {
      NKDbgPrintfW(L"[Error][%s] Oh~~~~ Invalid volume level[%d]\r\n","CAudio::UpdateIndSrcVolume",
                   DAT_00067686);
    }
    goto LAB_00013540;
  }
  iVar1 = *(int *)(param_1 + 0x38);
  uVar4 = (uint)DAT_00067685;
  uVar5 = (uint)DAT_00067683;
  if (iVar1 == 6) {
    uVar6 = (uint)DAT_00067686;
  }
  else {
    uVar6 = (uint)DAT_00067684;
    if (((iVar1 != 7) && (uVar6 = uVar4, iVar1 != 8)) &&
       ((uVar6 = (uint)DAT_00067687, iVar1 != 9 && ((uVar6 = uVar4, iVar1 != 10 && (iVar1 != 0xc))))
       )) {
      uVar6 = uVar5;
    }
  }
  if (param_2 == 6) {
    if (iVar1 == 9) {
      FUN_00036de8(0x6e,0);
      return;
    }
    if (iVar1 == 7) {
      if (*(int *)(param_1 + 0x44) == 0) {
        return;
      }
    }
    else {
      if (iVar1 == 8) {
        return;
      }
      if (iVar1 == 10) {
        return;
      }
      if (iVar1 == 0xc) {
        return;
      }
      if (*(int *)(param_1 + 0x44) == 0) {
        *(undefined4 *)(param_1 + 0x44) = 1;
        goto LAB_00013470;
      }
    }
LAB_000132a8:
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x44) == 1) goto LAB_000132a8;
    if ((param_2 == 2) || (iVar3 = -1, param_2 == 4)) {
      iVar3 = 1;
    }
    if (iVar1 == 7) {
      uVar6 = (uint)DAT_00067684 + iVar3;
      if ((int)uVar6 < 0) {
        uVar6 = 0;
      }
      else if (0x1f < (int)uVar6) {
        uVar6 = 0x1f;
      }
      uVar5 = uVar6 & 0xff;
      DAT_00067684 = (byte)uVar6;
      if (0x1f < uVar5) goto LAB_00013438;
      LVar2 = 3;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaef) = DAT_00067684;
    }
    else {
      if (iVar1 != 8) {
        if (iVar1 == 9) {
          uVar6 = (uint)DAT_00067687 + iVar3;
          if ((int)uVar6 < 1) {
            uVar6 = 1;
          }
          else if (0x1f < (int)uVar6) {
            uVar6 = 0x1f;
          }
          iVar1 = (uVar6 - uVar5) + 5;
          if (iVar1 < 0) {
            iVar1 = 0;
          }
          else if (0xf < iVar1) {
            iVar1 = 0xf;
          }
          DAT_00067688 = (undefined1)iVar1;
          DAT_00067687 = (byte)uVar6;
          FUN_000128e8(param_1,4,uVar6 & 0xff,1);
          goto LAB_00013470;
        }
        if ((iVar1 != 10) && (iVar1 != 0xc)) {
          uVar6 = uVar5 + iVar3;
          if ((int)uVar6 < 0) {
            uVar6 = 0;
          }
          else if (0x1f < (int)uVar6) {
            uVar6 = 0x1f;
          }
          uVar5 = uVar6 & 0xff;
          DAT_00067683 = (byte)uVar6;
          if (0x1f < uVar5) goto LAB_00013438;
          LVar2 = 0;
          *(byte *)(*(int *)(param_1 + 0xc) + 0xaee) = DAT_00067683;
          goto LAB_00013468;
        }
      }
      uVar6 = uVar4 + iVar3;
      if ((int)uVar6 < 0) {
        uVar6 = 0;
      }
      else if (0x1f < (int)uVar6) {
        uVar6 = 0x1f;
      }
      uVar5 = uVar6 & 0xff;
      DAT_00067685 = (byte)uVar6;
      if (0x1f < uVar5) {
LAB_00013438:
        NKDbgPrintfW(L"[Error][%s] Oh~~~~ Invalid volume level[%d]\r\n","CAudio::UpdateIndSrcVolume"
                     ,uVar5);
        goto LAB_00013470;
      }
      LVar2 = 2;
      *(byte *)(*(int *)(param_1 + 0xc) + 0xaf0) = DAT_00067685;
    }
LAB_00013468:
    FUN_00036de8(0x82,LVar2);
  }
LAB_00013470:
  Sleep(1);
  local_20 = (undefined1)uVar6;
  if (*(int *)(DAT_00064a24 + 0x48) == 0) {
    FUN_00019e28(DAT_000648ec,uVar6 & 0xff,*(undefined4 *)(param_1 + 0x44));
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    local_20 = 0;
  }
  if (DAT_00068074 == 1) {
    local_1f[0] = 0;
    FUN_00014db0(DAT_000648e4,0,0x30,(int)local_1f,1,0x32);
  }
  FUN_00015158(DAT_000648e4,5,1,0x12,(int)&local_20,1,0x32);
  if (DAT_00068074 == 1) {
    local_1f[0] = 1;
    FUN_00014db0(DAT_000648e4,0,0x30,(int)local_1f,1,0x32);
  }
LAB_00013540:
  iVar1 = *(int *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x48) != iVar1) {
    *(int *)(param_1 + 0x48) = iVar1;
    FUN_00036de8(0x75,iVar1);
    NKDbgPrintfW(L"Audio : Send IDM_MMCM_AMAIN_MUTE : 0x%x\r\n",*(undefined4 *)(param_1 + 0x44));
  }
  return;
}



/* 0001358c FUN_0001358c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 0001358c..000138b7. Semantic name remains unreviewed. */

void FUN_0001358c(int param_1,uint *param_2)

{
  char cVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  undefined1 local_18 [8];
  
  if ((*param_2 & 0xf00) != 0x200) {
    return;
  }
  cVar1 = *(char *)((int)param_2 + 2);
  if (cVar1 == '\0') {
    FUN_00011fac();
    FUN_00011264(param_1,DAT_00067678 >> 8 & 7);
    FUN_000111f4(param_1,DAT_00067678 >> 0xb & 1);
  }
  else {
    if (cVar1 != '\x05') {
      if (cVar1 != ' ') {
        return;
      }
      bVar2 = FUN_0001df1c(DAT_00064a24);
      if (CONCAT31(extraout_var,bVar2) != 0) {
        return;
      }
      uVar3 = (uint)(byte)param_2[1];
      if (uVar3 < 2) {
        return;
      }
      if (uVar3 < 4) {
        if (*(int *)(param_1 + 0x3c) != 0) {
          return;
        }
        *(undefined4 *)(param_1 + 0x4c) = 0;
        if (*(char *)(*(int *)(param_1 + 0xc) + 0xaec) == '\t') {
          return;
        }
        if (*(int *)(DAT_00064a24 + 0x4c) != 0) {
          return;
        }
        uVar3 = (uint)(byte)param_2[1];
      }
      else {
        if (uVar3 < 6) {
          if (*(int *)(param_1 + 0x3c) != 0) {
            return;
          }
          if (*(int *)(param_1 + 0x4c) != 0) {
            return;
          }
          if (*(char *)(*(int *)(param_1 + 0xc) + 0xaec) == '\t') {
            return;
          }
          iVar4 = *(int *)(DAT_00064a24 + 0x4c);
        }
        else {
          if (uVar3 != 6) {
            return;
          }
          if (*(int *)(param_1 + 0x3c) != 0) {
            return;
          }
          if (*(char *)(*(int *)(param_1 + 0xc) + 0xaec) == '\t') {
            return;
          }
          iVar4 = *(int *)(DAT_00064a24 + 0x4c);
        }
        if (iVar4 != 0) {
          return;
        }
      }
      FUN_00013014(param_1,uVar3);
      return;
    }
    if ((char)param_2[1] == 'U') {
      local_18[0] = 0x80;
      NKDbgPrintfW(L"\n\n[NAM]CAudio::OnCommand():NOTI_APP_DIAG_TWR[START] - \n\n");
      FUN_00015158(DAT_000648e4,5,1,0x20,(int)local_18,1,0x32);
      FUN_00015158(DAT_000648e4,5,1,0x21,(int)local_18,1,0x32);
      FUN_00015158(DAT_000648e4,5,1,0x22,(int)local_18,1,0x32);
      FUN_00015158(DAT_000648e4,5,1,0x23,(int)local_18,1,0x32);
      FUN_00015158(DAT_000648e4,5,1,0x24,(int)local_18,1,0x32);
      return;
    }
    if ((char)param_2[1] != -0x56) {
      return;
    }
    NKDbgPrintfW(L"\n\n[NAM]CAudio::OnCommand():NOTI_APP_DIAG_TWR[STOP] - Bal(%d), Fad(%d), Bas(%d), Mid(%d), Treb(%d)\n\n"
                 ,_DAT_0006767c & 0xff,DAT_00067678._3_1_,DAT_0006767d,_DAT_0006767c >> 0x10 & 0xff,
                 _DAT_0006767c >> 0x18);
  }
  FUN_000112cc(param_1,DAT_0006767c);
  FUN_00011328(param_1,DAT_00067678._3_1_);
  FUN_00011384(param_1,DAT_0006767d);
  FUN_000113e0(param_1,DAT_0006767e);
  FUN_0001143c(param_1,DAT_0006767f);
  return;
}



/* 000138b8 FUN_000138b8 */

/* Boundary evidence: original MIPS .pdata 000138b8..00013b27. Semantic name remains unreviewed. */

void FUN_000138b8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte local_20;
  byte local_1f;
  
  if (param_2 == 0) {
    if ((DAT_00067678 & 2) == 0) {
      local_20 = 8;
    }
    else {
      local_20 = 10;
    }
    local_1f = DAT_00067685;
  }
  else if (param_2 == 1) {
    local_20 = 7;
    local_1f = DAT_00067684;
  }
  else {
    if (param_2 == 2) {
      local_20 = 9;
      uVar1 = ((uint)DAT_00067683 + (uint)DAT_00067688) - 5;
      if ((int)uVar1 < 0xb) {
        uVar1 = 10;
      }
      else if (0x1f < (int)uVar1) {
        uVar1 = 0x1f;
      }
      uVar2 = uVar1 & 0xff;
      DAT_00067687 = (byte)uVar1;
      local_1f = DAT_00067687;
      if (*(int *)(param_1 + 0x2c) == 1) {
        uVar1 = (uint)DAT_00067686 - (uint)DAT_00067689 & 0xff;
        if (uVar2 < uVar1) {
          uVar1 = uVar2;
        }
        local_1f = (byte)uVar1;
      }
      FUN_000128e8(param_1,4,uVar2,1);
      goto LAB_00013a30;
    }
    if (param_2 == 4) {
      local_20 = 0xc;
      local_1f = DAT_00067685;
    }
    else {
      if (param_2 != 5) goto LAB_00013a30;
      local_20 = 0xd;
      local_1f = DAT_00067683;
    }
  }
  FUN_00011f48(param_1);
LAB_00013a30:
  if ((((*(int *)(param_1 + 0x44) == 1) && (param_2 != 1)) && (param_2 != 0)) && (param_2 != 4)) {
    local_1f = 0;
  }
  FUN_00015158(DAT_000648e4,5,1,0,(int)&local_20,2,0x32);
  if ((*(int *)(param_1 + 0x44) == 1) && (((param_2 == 1 || (param_2 == 0)) || (param_2 == 4)))) {
    *(uint *)(param_1 + 0x38) = (uint)local_20;
    Sleep(500);
    FUN_00011498(param_1,1,(uint)local_1f);
  }
  *(uint *)(param_1 + 0x38) = (uint)local_20;
  *(undefined4 *)(param_1 + 0x4c) = 1;
  FUN_0002fec8(DAT_000673c8);
  if (param_2 == 2) {
    FUN_0002fde4(DAT_000673c8,1);
    FUN_00036de8(0x75,1);
  }
  return;
}



/* 00013b28 FUN_00013b28 */

/* Boundary evidence: original MIPS .pdata 00013b28..00013cab. Semantic name remains unreviewed. */

void FUN_00013b28(int param_1)

{
  UINT UVar1;
  int iVar2;
  
  FUN_0003006c(param_1);
  iVar2 = *(int *)(param_1 + 0x50);
  if (iVar2 == 1) {
    FUN_000115b8(param_1,*(undefined4 *)(param_1 + 0x54),0);
    *(undefined4 *)(param_1 + 0x50) = 4;
  }
  else {
    if (iVar2 != 2) {
      if (iVar2 == 3) {
        FUN_000290b8(DAT_000673c8);
        *(undefined4 *)(param_1 + 0x3c) = 0;
        FUN_000115b8(param_1,*(undefined4 *)(param_1 + 0x54),1);
      }
      else if (iVar2 == 4) {
        FUN_000290b8(DAT_000673c8);
        *(undefined4 *)(param_1 + 0x3c) = 0;
        if (*(int *)(param_1 + 0x30) == 1) {
          if (*(int *)(param_1 + 0x2c) == 0) {
            FUN_00011db8(param_1);
          }
          *(undefined4 *)(param_1 + 0x30) = 0;
        }
        if (*(int *)(param_1 + 0x34) == 1) {
          FUN_00011cdc(param_1);
          Sleep(100);
          *(undefined4 *)(param_1 + 0x34) = 0;
        }
      }
      else {
        if (iVar2 != 5) {
          return;
        }
        FUN_000290b8(DAT_000673c8);
        *(undefined4 *)(param_1 + 0x3c) = 0;
      }
      *(undefined4 *)(param_1 + 0x50) = 0;
      return;
    }
    FUN_000138b8(param_1,*(int *)(param_1 + 0x54));
    iVar2 = *(int *)(param_1 + 0x54);
    *(undefined4 *)(param_1 + 0x50) = 5;
    if ((((iVar2 == 3) || (iVar2 == 1)) || (iVar2 == 2)) || (iVar2 == 5)) {
      UVar1 = 200;
      goto LAB_00013c8c;
    }
  }
  UVar1 = 700;
LAB_00013c8c:
  FUN_00030044(param_1,UVar1);
  return;
}



/* 00013cac FUN_00013cac */

/* Boundary evidence: original MIPS .pdata 00013cac..00013d43. Semantic name remains unreviewed. */

undefined4 *
FUN_00013cac(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00030010(param_1,param_2,param_3);
  param_1[3] = param_4;
  *param_1 = &PTR_FUN_0004fd8c;
  param_1[4] = 0xff;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 1;
  param_1[5] = 0xff;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return param_1;
}



/* 00013d44 FUN_00013d44 */

/* Boundary evidence: original MIPS .pdata 00013d44..0001405f. Semantic name remains unreviewed. */

void FUN_00013d44(int param_1,int param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  byte bVar3;
  HANDLE pvVar4;
  BOOL BVar5;
  undefined3 extraout_var;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  DWORD DStack_40;
  DWORD DStack_3c;
  uint local_38;
  undefined1 local_34 [4];
  byte local_30;
  
  memset(&local_38,0,9);
  *(undefined1 *)(param_1 + 0x19) = param_3;
  pwVar7 = L"\\Storage Card2\\EcoDrive.cfg";
  *(char *)(param_1 + 0x18) = (char)param_2;
  pvVar4 = CreateFileW(L"\\Storage Card2\\EcoDrive.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  if (pvVar4 == (HANDLE)0xffffffff) {
    pvVar4 = CreateFileW(L"\\Storage Card2\\EcoDrive.cfg",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                         0x80,(HANDLE)0x0);
    local_38 = (uint)*(byte *)(param_1 + 0x19);
    local_34 = (undefined1  [4])(uint)*(byte *)(param_1 + 0x18);
    puVar1 = local_34 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 |
         (uint)(*(byte *)(param_1 + 0x18) >> (3 - uVar2) * 8);
    local_30 = FUN_000326c0((int)&local_38,8);
    if (pvVar4 == (HANDLE)0xffffffff) {
      NKDbgPrintfW(L"[error#1]EcoDrive.cfg Create by micom manager\r\n");
      return;
    }
    BVar5 = WriteFile(pvVar4,&local_38,9,&DStack_40,(LPOVERLAPPED)0x0);
    if (BVar5 == 0) {
      pwVar7 = L"EcoDrive.cfg write error\r\n";
    }
    else {
      pwVar7 = L"[error#0]EcoDrive.cfg Create by micom manager\r\n";
    }
    NKDbgPrintfW(pwVar7);
    goto LAB_0001402c;
  }
  BVar5 = ReadFile(pvVar4,&local_38,9,&DStack_3c,(LPOVERLAPPED)0x0);
  if (BVar5 == 0) {
    pwVar7 = (wchar_t *)GetLastError();
    pwVar6 = L"[error] file read [0x%X]\r\n";
LAB_00013f60:
    NKDbgPrintfW(pwVar6,pwVar7);
  }
  else {
    bVar3 = FUN_000326c0((int)&local_38,8);
    if (CONCAT31(extraout_var,bVar3) != (uint)local_30) {
      pwVar6 = L"[error] %s crc error => using DSI config...\r\n";
      goto LAB_00013f60;
    }
    if ((param_2 == 0) || (2 < (uint)local_34)) {
      *(undefined1 *)(param_1 + 0x18) = 0;
    }
    else if (local_34 == (undefined1  [4])0x0) {
      NKDbgPrintfW(L"[#######]!!!!!!! [%d][%d]\r\n",param_2,0);
    }
    else {
      *(char *)(param_1 + 0x18) = local_34[0];
    }
    *(undefined1 *)(param_1 + 0x19) = (undefined1)local_38;
  }
  CloseHandle(pvVar4);
  if (param_2 != 0) {
    return;
  }
  if (local_34 == (undefined1  [4])0x0) {
    return;
  }
  pvVar4 = CreateFileW(L"\\Storage Card2\\EcoDrive.cfg",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  if (pvVar4 == (HANDLE)0xffffffff) {
    return;
  }
  local_38 = (uint)*(byte *)(param_1 + 0x19);
  local_34 = (undefined1  [4])(uint)*(byte *)(param_1 + 0x18);
  local_30 = FUN_000326c0((int)&local_38,8);
  WriteFile(pvVar4,&local_38,9,&DStack_40,(LPOVERLAPPED)0x0);
  NKDbgPrintfW(L"[exception process #1] EcoDrive.cfg Create by micom manager[0x%08X, %d, %d]\r\n",
               pvVar4,0,local_34);
LAB_0001402c:
  CloseHandle(pvVar4);
  return;
}



/* 00014060 FUN_00014060 */

void FUN_00014060(int param_1,undefined1 param_2)

{
  if (3 < *(byte *)(param_1 + 0x18)) {
    *(undefined1 *)(param_1 + 0x18) = 0;
  }
  *(undefined1 *)(param_1 + 0x18) = param_2;
  DAT_0006488c = 1;
  return;
}



/* 00014088 FUN_00014088 */

void FUN_00014088(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x19) = param_2;
  return;
}



/* 00014090 FUN_00014090 */

/* Boundary evidence: original MIPS .pdata 00014090..00014197. Semantic name remains unreviewed. */

undefined4 FUN_00014090(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = param_2 + -0x28;
  if ((*(int *)(param_1 + 0x10) == param_2) && (param_3 == 0)) {
    uVar1 = 0;
  }
  else {
    *(int *)(param_1 + 0x10) = param_2;
    if (param_2 == 0xff) {
      iVar2 = 0x1a2;
    }
    else if (*(char *)(param_1 + 0x18) == '\x02') {
      uVar3 = __litodp(iVar2);
      uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0xcccccccd,0x3ffccccc);
      uVar3 = __dpadd((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x40400000);
      uVar3 = __dpadd((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x3fe00000);
      iVar2 = __dptoli((int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    }
    if (DAT_0006488c != 0) {
      DAT_0006488c = 0;
      FUN_00036de8(0xcd,0);
    }
    if (*(int *)(param_1 + 0x20) != 0) {
      FUN_00036de8(0xc9,(uint)*(byte *)(param_1 + 0x18) | iVar2 << 8);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 00014198 FUN_00014198 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 00014198..0001439b. Semantic name remains unreviewed. */

undefined4 FUN_00014198(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  if ((((*(char *)(*(int *)(param_1 + 0xc) + 0xb07) == '\x01') ||
       (iVar2 = *(int *)(param_1 + 0x10), iVar2 == 0xff)) || (param_2 == 0xff)) ||
     (iVar2 == *(int *)(param_1 + 0x14))) {
    return 0;
  }
  uVar5 = 0xffffffff;
  if (iVar2 - param_2 < 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = -1;
    if (iVar2 - param_2 < 1) {
      iVar3 = 0;
    }
  }
  if (DAT_00064890 == iVar3) {
    DAT_00064894 = DAT_00064894 + 1;
  }
  else {
    DAT_00064894 = 0;
    DAT_00064890 = iVar3;
  }
  if ((DAT_00064890 < 0) && (DAT_00064894 == 1)) {
    DAT_00064894 = 0;
    iVar3 = *(int *)(param_1 + 0x10);
    iVar4 = iVar3 + -1;
    iVar2 = iVar3 + -0x29;
    if (iVar3 == iVar4) {
      DAT_00064894 = 0;
      return 0xffffffff;
    }
    *(int *)(param_1 + 0x10) = iVar4;
    if (iVar4 == 0xff) {
LAB_00014330:
      iVar2 = 0x1a2;
      goto LAB_00014334;
    }
    cVar1 = *(char *)(param_1 + 0x18);
  }
  else {
    if (DAT_00064890 < 1) {
      return 0;
    }
    if (DAT_00064894 != 0x14) {
      return 0;
    }
    DAT_00064894 = 0;
    iVar3 = *(int *)(param_1 + 0x10);
    iVar4 = iVar3 + 1;
    uVar5 = 1;
    iVar2 = iVar3 + -0x27;
    if (iVar3 == iVar4) {
      DAT_00064894 = 0;
      return 1;
    }
    *(int *)(param_1 + 0x10) = iVar4;
    if (iVar4 == 0xff) goto LAB_00014330;
    cVar1 = *(char *)(param_1 + 0x18);
  }
  if (cVar1 == '\x02') {
    uVar6 = __litodp(iVar2);
    uVar6 = __dpmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0xcccccccd,0x3ffccccc);
    uVar6 = __dpadd((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40400000);
    uVar6 = __dpadd((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
    iVar2 = __dptoli((int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
  }
LAB_00014334:
  if (DAT_0006488c != 0) {
    DAT_0006488c = 0;
    FUN_00036de8(0xcd,0);
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_00036de8(0xc9,(uint)*(byte *)(param_1 + 0x18) | iVar2 << 8);
  }
  return uVar5;
}



/* 0001439c FUN_0001439c */

/* Boundary evidence: original MIPS .pdata 0001439c..00014a4f. Semantic name remains unreviewed. */

void FUN_0001439c(int param_1,uint *param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  byte local_60;
  byte local_5f;
  byte local_5e;
  byte local_5d;
  byte local_5c;
  byte local_5a;
  byte local_59;
  undefined4 local_58;
  uint local_50;
  uint local_4c;
  undefined1 uStack_48;
  undefined1 auStack_47 [3];
  byte local_44;
  byte local_33;
  uint local_2c;
  
  local_2c = DAT_00064820;
  if ((*param_2 & 0xf00) != 0x200) goto switchD_000146fc_caseD_2;
  cVar1 = *(char *)((int)param_2 + 2);
  if (cVar1 == 'f') {
    if (((*(char *)(*(int *)(param_1 + 0xc) + 0xb07) != '\0') ||
        (bVar2 = *(byte *)((int)param_2 + 3), bVar2 == 0)) || (*(int *)(param_1 + 0x1c) != 0))
    goto switchD_000146fc_caseD_2;
    memset((void *)((int)&local_58 + 1),0,7);
    memcpy(&local_58,param_2 + 1,(uint)bVar2);
    uVar3 = local_58 >> 0x10 & 0xff;
    *(uint *)(param_1 + 0x14) = uVar3;
    if (*(int *)(param_1 + 0x10) == 0xff) {
      iVar5 = uVar3 - 0x28;
      if (uVar3 == 0xff) goto switchD_000146fc_caseD_2;
      *(uint *)(param_1 + 0x10) = uVar3;
      if (*(char *)(param_1 + 0x18) == '\x02') {
        uVar13 = __litodp(iVar5);
        uVar13 = __dpmul((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0xcccccccd,0x3ffccccc);
        uVar13 = __dpadd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,0x40400000);
        uVar13 = __dpadd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,0x3fe00000);
        iVar5 = __dptoli((int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
      }
      if (DAT_0006488c != 0) {
        DAT_0006488c = 0;
        FUN_00036de8(0xcd,0);
      }
      if (*(int *)(param_1 + 0x20) == 0) goto switchD_000146fc_caseD_2;
      uVar3 = iVar5 << 8 | (uint)*(byte *)(param_1 + 0x18);
    }
    else {
      if ((uVar3 != 0xff) || (*(undefined4 *)(param_1 + 0x10) = 0xff, *(int *)(param_1 + 0x20) == 0)
         ) goto switchD_000146fc_caseD_2;
      uVar3 = *(byte *)(param_1 + 0x18) | 0x1a200;
    }
    FUN_00036de8(0xc9,uVar3);
    goto switchD_000146fc_caseD_2;
  }
  if (cVar1 != 'i') {
    if (((cVar1 == 'j') && (bVar2 = *(byte *)((int)param_2 + 3), bVar2 != 0)) &&
       (*(char *)(*(int *)(param_1 + 0xc) + 0xb07) == '\0')) {
      memset(auStack_47,0,0x1b);
      memcpy(&uStack_48,param_2 + 1,(uint)bVar2);
      uVar3 = (uint)local_44;
      *(uint *)(param_1 + 0x14) = uVar3;
      if ((*(int *)(param_1 + 0x10) == 0xff) && (iVar5 = uVar3 - 0x28, uVar3 != 0xff)) {
        *(uint *)(param_1 + 0x10) = uVar3;
        if (*(char *)(param_1 + 0x18) == '\x02') {
          uVar13 = __litodp(iVar5);
          uVar13 = __dpmul((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0xcccccccd,0x3ffccccc);
          uVar13 = __dpadd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,0x40400000);
          uVar13 = __dpadd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,0x3fe00000);
          iVar5 = __dptoli((int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
        }
        if (DAT_0006488c != 0) {
          DAT_0006488c = 0;
          FUN_00036de8(0xcd,0);
        }
        if (*(int *)(param_1 + 0x20) != 0) {
          FUN_00036de8(0xc9,iVar5 << 8 | (uint)*(byte *)(param_1 + 0x18));
        }
      }
      *(uint *)(param_1 + 0x38) = local_33 & 3;
    }
    goto switchD_000146fc_caseD_2;
  }
  if ((*(char *)((int)param_2 + 3) != '\b') || (*(int *)(param_1 + 0x1c) != 0))
  goto switchD_000146fc_caseD_2;
  memcpy(&local_60,param_2 + 1,8);
  uVar3 = (uint)local_5f;
  uVar7 = local_60 >> 4 & 3;
  uVar8 = local_5e >> 2 & 3;
  uVar12 = (uint)(local_5e >> 4);
  uVar6 = local_5e & 3;
  local_50 = (uint)(local_5c >> 6);
  local_4c = (uint)(local_5d >> 4);
  local_58 = local_5d & 0xf;
  uVar9 = local_5a >> 2 & 3;
  uVar10 = local_5a & 3;
  uVar11 = (uint)(local_59 >> 6);
  NKDbgPrintfW(L"[eClimBlowerLevelDisplay] [eClimLastFuncModifiedByCustomer] : [%x, %x]\r\n",
               local_4c);
  if (*(uint *)(param_1 + 0x3c) != local_4c) {
    *(uint *)(param_1 + 0x3c) = local_4c;
  }
  if (*(uint *)(param_1 + 0x44) != local_50) {
    *(uint *)(param_1 + 0x44) = local_50;
  }
  if (*(char *)(param_1 + 0x19) == '\x01') {
    if (local_50 != 2) goto switchD_000146fc_caseD_2;
    if (*(uint *)(param_1 + 0x40) != local_58) {
      *(uint *)(param_1 + 0x40) = local_58;
    }
    iVar5 = *(int *)(DAT_000648ec + 0x1c);
    if (((((iVar5 != 1) && (iVar5 != 2)) && (iVar5 != 6)) &&
        ((*(int *)(DAT_00064a24 + 0x48) != 1 && (*(int *)(DAT_00064a24 + 0x3c) != 1)))) &&
       (iVar5 != 4)) {
      if (*(uint *)(param_1 + 0x38) == uVar6) {
        switch(local_58) {
        case 1:
          if (*(uint *)(param_1 + 0x2c) != uVar3) {
            *(uint *)(param_1 + 0x2c) = uVar3;
          }
          if (uVar3 != 0) {
            if (((uVar3 == 8) || (uVar3 == 10)) || ((0x13 < uVar3 && (uVar3 < 0x100)))) {
              FUN_00016570(DAT_000648ec);
            }
            goto switchD_000146fc_caseD_2;
          }
          break;
        default:
          goto switchD_000146fc_caseD_2;
        case 3:
          if (*(uint *)(param_1 + 0x24) != uVar7) {
            *(uint *)(param_1 + 0x24) = uVar7;
          }
          if ((uVar7 == 1) || (uVar7 == 2)) {
            uVar4 = 0;
LAB_000146c4:
            FUN_00016438(DAT_000648ec,uVar4);
            goto switchD_000146fc_caseD_2;
          }
          break;
        case 4:
          if (*(uint *)(param_1 + 0x50) != uVar11) {
            *(uint *)(param_1 + 0x50) = uVar11;
          }
          if ((uVar11 == 1) || (uVar11 == 2)) {
            uVar4 = 0xb;
            goto LAB_000146c4;
          }
          break;
        case 5:
          if (*(uint *)(param_1 + 0x30) != uVar12) {
            *(uint *)(param_1 + 0x30) = uVar12;
          }
          if (uVar12 != 0) {
            FUN_000164d4(DAT_000648ec,3);
            goto switchD_000146fc_caseD_2;
          }
          break;
        case 6:
          if (*(uint *)(param_1 + 0x34) != uVar8) {
            *(uint *)(param_1 + 0x34) = uVar8;
          }
          if ((uVar8 == 1) || (uVar8 == 2)) {
            uVar4 = 4;
            goto LAB_000146c4;
          }
          break;
        case 8:
          if (*(int *)(param_1 + 0x3c) != 0) {
            if (*(int *)(param_1 + 0x3c) != 0xf) {
              FUN_000163a0(DAT_000648ec);
              goto switchD_000146fc_caseD_2;
            }
            uVar4 = 6;
            goto LAB_000146c4;
          }
          break;
        case 10:
          if (*(uint *)(param_1 + 0x48) != uVar9) {
            *(uint *)(param_1 + 0x48) = uVar9;
          }
          if ((uVar9 == 1) || (uVar9 == 2)) {
            uVar4 = 9;
            goto LAB_000146c4;
          }
          break;
        case 0xb:
          if (*(uint *)(param_1 + 0x4c) != uVar10) {
            *(uint *)(param_1 + 0x4c) = uVar10;
          }
          if ((uVar10 == 1) || (uVar10 == 2)) {
            uVar4 = 10;
            goto LAB_000146c4;
          }
        }
      }
      else {
        *(uint *)(param_1 + 0x38) = uVar6;
        if ((uVar6 == 1) || (uVar6 == 2)) {
          uVar4 = 5;
          goto LAB_000146c4;
        }
      }
      FUN_0001660c(DAT_000648ec);
      goto switchD_000146fc_caseD_2;
    }
    uVar3 = *(uint *)(param_1 + 0x38);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x38);
  }
  if (uVar3 != uVar6) {
    *(uint *)(param_1 + 0x38) = uVar6;
  }
switchD_000146fc_caseD_2:
  FUN_0004a3f4(local_2c);
  return;
}



/* 00014a50 FUN_00014a50 */

/* Boundary evidence: original MIPS .pdata 00014a50..00014a6b. Semantic name remains unreviewed. */

void FUN_00014a50(int param_1)

{
  FUN_00014198(param_1,*(int *)(param_1 + 0x14));
  return;
}



/* 00014a6c FUN_00014a6c */

/* Boundary evidence: original MIPS .pdata 00014a6c..00014afb. Semantic name remains unreviewed. */

void FUN_00014a6c(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x1c) = param_2;
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x10) = 0xff;
    if (*(int *)(param_1 + 0x20) != 0) {
      FUN_00036de8(0xc9,*(byte *)(param_1 + 0x18) | 0x1a200);
    }
  }
  else {
    iVar1 = FUN_0001c568(DAT_000649b8);
    if (iVar1 == 0) {
      FUN_00015158(DAT_000648e4,1,1,0xb,0,0,100);
    }
  }
  return;
}



/* 00014afc FUN_00014afc */

/* Boundary evidence: original MIPS .pdata 00014afc..00014b3b. Semantic name remains unreviewed. */

void FUN_00014afc(int param_1,int param_2)

{
  *(int *)(param_1 + 0x20) = param_2;
  if (param_2 == 0) {
    KillTimer(*(HWND *)(param_1 + 4),0x709);
  }
  else {
    SetTimer(*(HWND *)(param_1 + 4),0x709,1000,(TIMERPROC)0x0);
  }
  return;
}



/* 00014b3c FUN_00014b3c */

/* Boundary evidence: original MIPS .pdata 00014b3c..00014b93. Semantic name remains unreviewed. */

undefined4 * FUN_00014b3c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0004fd8c;
  FUN_0003008c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00014b94 FUN_00014b94 */

/* Boundary evidence: original MIPS .pdata 00014b94..00014c1f. Semantic name remains unreviewed. */

undefined4 * FUN_00014b94(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  
  FUN_00030010(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_000500c8;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  memset(param_1 + 8,0,0x90);
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[0x31] = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[3] = pvVar1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return param_1;
}



/* 00014c20 FUN_00014c20 */

/* Boundary evidence: original MIPS .pdata 00014c20..00014c6b. Semantic name remains unreviewed. */

void FUN_00014c20(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000500c8;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  CloseHandle((HANDLE)param_1[3]);
  FUN_0003008c(param_1);
  return;
}



/* 00014c6c FUN_00014c6c */

/* Boundary evidence: original MIPS .pdata 00014c6c..00014daf. Semantic name remains unreviewed. */

void FUN_00014c6c(int param_1,uint param_2,uint param_3,uint param_4,void *param_5,byte param_6,
                 UINT param_7)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  if (*(int *)(param_1 + 0x14) == 1) {
    if (*(int *)(param_1 + 0x1c) == 4) {
      NKDbgPrintfW(L"ERROR : Send Command Queue full!!!!.\r\n");
    }
    else {
      iVar1 = (*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x1c) & 3U) * 0x24 + param_1;
      *(byte *)(iVar1 + 0x20) = (byte)(param_2 << 4) | (byte)param_3 & 0xf;
      *(char *)(iVar1 + 0x21) = (char)param_4;
      *(byte *)(iVar1 + 0x22) = param_6;
      if (param_6 != 0) {
        memcpy((void *)(iVar1 + 0x23),param_5,(uint)param_6);
      }
      *(UINT *)(iVar1 + 0x40) = param_7;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    }
  }
  else {
    FUN_00028588((undefined4 *)&DAT_00064b44,param_2,param_3,param_4,(int)param_5,param_6);
    *(byte *)(param_1 + 0x10) = (byte)param_3;
    *(char *)(param_1 + 0x11) = (char)param_2;
    *(char *)(param_1 + 0x12) = (char)param_4;
    *(undefined4 *)(param_1 + 0x14) = 1;
    FUN_00030044(param_1,param_7);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  return;
}



/* 00014db0 FUN_00014db0 */

/* Boundary evidence: original MIPS .pdata 00014db0..00014f8b. Semantic name remains unreviewed. */

undefined4
FUN_00014db0(int param_1,uint param_2,undefined4 param_3,int param_4,byte param_5,DWORD param_6)

{
  DWORD DVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 local_f0;
  undefined1 local_ef;
  undefined1 local_ee;
  undefined1 local_ed;
  undefined1 local_ec [188];
  uint local_30;
  
  local_30 = DAT_00064820;
  if (*(int *)(param_1 + 0xc4) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
    uVar5 = (uint)param_5;
    uVar3 = 0;
    local_f0 = (undefined1)param_3;
    local_ef = (undefined1)((uint)param_3 >> 8);
    local_ee = (undefined1)((uint)param_3 >> 0x10);
    local_ed = (undefined1)((uint)param_3 >> 0x18);
    if (uVar5 != 0) {
      do {
        local_ec[uVar3] = *(undefined1 *)(uVar3 + param_4);
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < uVar5);
    }
    EventModify(*(undefined4 *)(param_1 + 0xc),2);
    bVar2 = 0;
    do {
      FUN_00028588((undefined4 *)&DAT_00064b44,param_2,6,uVar5,(int)&local_f0,param_5 + 4);
      DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),param_6);
      if (DVar1 == 0) {
        uVar4 = 1;
        goto LAB_00014f48;
      }
      NKDbgPrintfW(L"%S(ret = 0x%x)\r\n","CCmd::SendWriteCmd",DVar1);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 3);
    NKDbgPrintfW(L"MGRMCM : SendWriteCmd(0x%02X, 0x%08X) timeout!!!!!!!!!!!!!\r\n",param_2,param_3);
    uVar4 = 0;
LAB_00014f48:
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
    FUN_0004a3f4(local_30);
  }
  else {
    NKDbgPrintfW(L"%S(m_bTest) : NOT NOT!!!!!!!!\r\n","CCmd::SendWriteCmd");
    FUN_0004a3f4(local_30);
    uVar4 = 0;
  }
  return uVar4;
}



/* 00014f8c FUN_00014f8c */

/* Boundary evidence: original MIPS .pdata 00014f8c..0001501b. Semantic name remains unreviewed. */

void FUN_00014f8c(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar1 = *(int *)(param_1 + 0x18) * 0x24 + param_1;
    FUN_00014c6c(param_1,(uint)(*(byte *)(iVar1 + 0x20) >> 4),*(byte *)(iVar1 + 0x20) & 0xf,
                 (uint)*(byte *)(iVar1 + 0x21),(void *)(iVar1 + 0x23),*(byte *)(iVar1 + 0x22),
                 *(UINT *)(iVar1 + 0x40));
    *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1U & 3;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  }
  return;
}



/* 0001501c FUN_0001501c */

/* Boundary evidence: original MIPS .pdata 0001501c..0001506b. Semantic name remains unreviewed. */

void FUN_0001501c(int param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_0003006c(param_1);
  FUN_00014f8c(param_1);
  NKDbgPrintfW(L"ERROR : The request timeout is occured. Please figure out problems. GRP=0x%02X, CMD=0x%02X\r\n"
               ,*(undefined1 *)(param_1 + 0x10),*(undefined1 *)(param_1 + 0x12));
  return;
}



/* 0001506c FUN_0001506c */

/* Boundary evidence: original MIPS .pdata 0001506c..000150d7. Semantic name remains unreviewed. */

void FUN_0001506c(int param_1,uint *param_2)

{
  if (((*(int *)(param_1 + 0x14) == 1) && ((uint)*(byte *)(param_1 + 0x10) == (*param_2 >> 8 & 0xf))
      ) && (*(char *)(param_1 + 0x12) == *(char *)((int)param_2 + 2))) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    FUN_0003006c(param_1);
    FUN_00014f8c(param_1);
  }
  return;
}



/* 000150d8 FUN_000150d8 */

/* Boundary evidence: original MIPS .pdata 000150d8..0001510b. Semantic name remains unreviewed. */

void FUN_000150d8(int param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_0003006c(param_1);
  FUN_00014f8c(param_1);
  return;
}



/* 0001510c FUN_0001510c */

/* Boundary evidence: original MIPS .pdata 0001510c..00015157. Semantic name remains unreviewed. */

undefined4 * FUN_0001510c(undefined4 *param_1,uint param_2)

{
  FUN_00014c20(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00015158 FUN_00015158 */

/* Boundary evidence: original MIPS .pdata 00015158..000152c7. Semantic name remains unreviewed. */

undefined4
FUN_00015158(int param_1,uint param_2,uint param_3,uint param_4,int param_5,byte param_6,int param_7
            )

{
  DWORD DVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0xc4) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
    EventModify(*(undefined4 *)(param_1 + 0xc),2);
    uVar3 = 0;
    do {
      FUN_00028588((undefined4 *)&DAT_00064b44,param_2,param_3,param_4,param_5,param_6);
      DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),param_7 + 0x32);
      if (DVar1 == 0) {
        uVar2 = 1;
        goto LAB_0001528c;
      }
      NKDbgPrintfW(L"%S(ret = 0x%x)\r\n","CCmd::SendCommandEx",DVar1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 3);
    NKDbgPrintfW(L"%S(mgr=%d,grp=%d,cmd=0x%02X,buf,len=%d,tout=%d) : TIMEOUT!!!!!!!!\r\n",
                 "CCmd::SendCommandEx",param_2,param_3,param_4,param_6,param_7);
    uVar2 = 0;
LAB_0001528c:
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  }
  else {
    NKDbgPrintfW(L"%S(m_bTest) : NOT NOT!!!!!!!!\r\n","CCmd::SendCommandEx");
    uVar2 = 0;
  }
  return uVar2;
}



/* 000152c8 FUN_000152c8 */

/* Boundary evidence: original MIPS .pdata 000152c8..000153db. Semantic name remains unreviewed. */

bool FUN_000152c8(int param_1,uint param_2,uint param_3,uint param_4,int param_5,byte param_6,
                 int param_7)

{
  DWORD DVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  EventModify(*(undefined4 *)(param_1 + 0xc),2);
  FUN_00028588((undefined4 *)&DAT_00064b44,param_2,param_3,param_4,param_5,param_6);
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),param_7 + 0x32);
  if (DVar1 != 0) {
    NKDbgPrintfW(L"%S(ret = 0x%x)\r\n","CCmd::SendCommandEx2",DVar1);
    NKDbgPrintfW(L"%S(mgr=%d,grp=%d,cmd=0x%02X,buf,len=%d,tout=%d) : TIMEOUT!!!!!!!!\r\n",
                 "CCmd::SendCommandEx2",param_2,param_3,param_4,param_6,param_7);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  return DVar1 == 0;
}



/* 000153dc FUN_000153dc */

/* Boundary evidence: original MIPS .pdata 000153dc..00015603. Semantic name remains unreviewed. */

uint FUN_000153dc(int param_1,uint param_2,undefined4 param_3,void *param_4,byte param_5,
                 DWORD param_6)

{
  DWORD DVar1;
  void *pvVar2;
  uint _Size;
  undefined1 local_1e0;
  undefined1 local_1df;
  undefined1 local_1de;
  undefined1 local_1dd;
  uint local_1dc;
  undefined1 auStack_1d8 [144];
  undefined1 auStack_148 [144];
  uint local_b8;
  undefined1 auStack_b4 [136];
  uint local_2c;
  
  local_2c = DAT_00064820;
  if (*(int *)(param_1 + 0xc4) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
    local_1e0 = (undefined1)param_3;
    local_1df = (undefined1)((uint)param_3 >> 8);
    local_1de = (undefined1)((uint)param_3 >> 0x10);
    local_1dd = (undefined1)((uint)param_3 >> 0x18);
    EventModify(*(undefined4 *)(param_1 + 0xc),2);
    local_1dc = 0;
    do {
      FUN_00028588((undefined4 *)&DAT_00064b44,param_2,5,(uint)param_5,(int)&local_1e0,4);
      DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),param_6);
      if (DVar1 == 0) {
        pvVar2 = FUN_00028994(0x64b44,auStack_1d8);
        memcpy(&local_b8,pvVar2,0x8c);
        _Size = local_b8 >> 0x18;
        memcpy(param_4,auStack_b4,_Size);
        goto LAB_000155c0;
      }
      pvVar2 = FUN_00028994(0x64b44,auStack_148);
      memcpy(&local_b8,pvVar2,0x8c);
      NKDbgPrintfW(L"%S(ret = 0x%x)\r\n","CCmd::SendReadCmd",DVar1);
      NKDbgPrintfW(L"stItem(mgr = %d, grp = %d, cmd = %d, len = %d)\r\n",local_b8 >> 0xc & 0xf,
                   local_b8 >> 8 & 0xf,local_b8 >> 0x10 & 0xff,local_b8 >> 0x18);
      local_1dc = local_1dc + 1;
    } while (local_1dc < 3);
    NKDbgPrintfW(L"%S(mgr=%d,addr=0x%08X,buf,len=%d,tout=%d) : TIMEOUT!!!!!!!!!!\r\n",
                 "CCmd::SendReadCmd",param_2,param_3,(uint)param_5,param_6);
    _Size = 0;
LAB_000155c0:
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
    FUN_0004a3f4(local_2c);
  }
  else {
    NKDbgPrintfW(L"%S(m_bTest) : NOT NOT!!!!!!!!\r\n","CCmd::SendReadCmd");
    FUN_0004a3f4(local_2c);
    _Size = 0;
  }
  return _Size;
}



/* 00015604 FUN_00015604 */

undefined4 * FUN_00015604(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = &PTR_FUN_00050484;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



/* 00015624 FUN_00015624 */

/* Boundary evidence: original MIPS .pdata 00015624..0001568f. Semantic name remains unreviewed. */

void FUN_00015624(int param_1)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    SetWindowPos(*(HWND *)(param_1 + 8),(HWND)0xffffffff,10,0,0x30c,0x3c,0x10);
    ShowWindow(*(HWND *)(param_1 + 8),5);
    *(undefined4 *)(param_1 + 0xc) = 1;
  }
  return;
}



/* 00015690 FUN_00015690 */

/* Boundary evidence: original MIPS .pdata 00015690..000156b7. Semantic name remains unreviewed. */

void FUN_00015690(int param_1)

{
  SetTimer(*(HWND *)(param_1 + 8),0x432,2000,(TIMERPROC)0x0);
  return;
}



/* 000156b8 FUN_000156b8 */

/* Boundary evidence: original MIPS .pdata 000156b8..0001577b. Semantic name remains unreviewed. */

void FUN_000156b8(int param_1)

{
  LSTATUS LVar1;
  HKEY local_18;
  DWORD local_14 [3];
  
  local_14[1] = 4;
  local_14[0] = 4;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_18);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_18,L"TEST_MODE",(LPDWORD)0x0,local_14 + 1,(LPBYTE)(local_14 + 2),
                             local_14);
    if ((LVar1 == 0) && (local_14[2] != 0)) {
      *(undefined4 *)(param_1 + 0x10) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    RegCloseKey(local_18);
  }
  return;
}



/* 0001577c FUN_0001577c */

/* Boundary evidence: original MIPS .pdata 0001577c..000157df. Semantic name remains unreviewed. */

undefined4 * FUN_0001577c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00050484;
  SendMessageW((HWND)param_1[2],0x10,0,0);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000157e0 FUN_000157e0 */

/* Boundary evidence: original MIPS .pdata 000157e0..00015847. Semantic name remains unreviewed. */

LRESULT FUN_000157e0(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int iVar1;
  LRESULT LVar2;
  
  if (param_2 == 0x113) {
    KillTimer(param_1,0x432);
    iVar1 = DAT_000648e8;
    if (*(int *)(DAT_000648e8 + 0xc) != 0) {
      ShowWindow(*(HWND *)(DAT_000648e8 + 8),0);
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    LVar2 = 0;
  }
  else {
    LVar2 = DefWindowProcW(param_1,param_2,param_3,param_4);
  }
  return LVar2;
}



/* 00015848 FUN_00015848 */

/* Boundary evidence: original MIPS .pdata 00015848..0001598f. Semantic name remains unreviewed. */

undefined4 FUN_00015848(int param_1)

{
  HWND hWnd;
  BOOL BVar1;
  WNDCLASSW local_40;
  
  local_40.hInstance = *(HINSTANCE *)(param_1 + 4);
  if (local_40.hInstance != (HINSTANCE)0xffffffff) {
    local_40.lpfnWndProc = FUN_000157e0;
    local_40.style = 3;
    local_40.cbClsExtra = 0;
    local_40.cbWndExtra = 0;
    local_40.hIcon = (HICON)0x0;
    local_40.hCursor = (HCURSOR)0x0;
    local_40.hbrBackground = (HBRUSH)0x0;
    local_40.lpszMenuName = (LPCWSTR)0x0;
    local_40.lpszClassName = L"MICOM_DSICAN_MSGWIN";
    RegisterClassW(&local_40);
    hWnd = CreateWindowExW(0,L"MICOM_DSICAN_MSGWIN",L"MICOM_DSICAN_MSGWIN",0x90000000,10,0,0x30c,
                           0x3c,(HWND)0x0,(HMENU)0x0,*(HINSTANCE *)(param_1 + 4),(LPVOID)0x0);
    *(HWND *)(param_1 + 8) = hWnd;
    BVar1 = IsWindow(hWnd);
    if (BVar1 != 0) {
      CreateWindowExW(0x200,L"listbox",L"",0x50200180,0,0,0x30c,0x3c,*(HWND *)(param_1 + 8),
                      (HMENU)0x3,*(HINSTANCE *)(param_1 + 4),(LPVOID)0x0);
      *(undefined4 *)(param_1 + 0xc) = 1;
      return 1;
    }
  }
  return 0;
}



/* 00015990 FUN_00015990 */

/* Boundary evidence: original MIPS .pdata 00015990..00015a07. Semantic name remains unreviewed. */

undefined4 FUN_00015990(int param_1,LPARAM param_2)

{
  WPARAM wParam;
  
  if (*(HWND *)(param_1 + 8) != (HWND)0x0) {
    wParam = SendDlgItemMessageW(*(HWND *)(param_1 + 8),3,0x180,0,param_2);
    if (wParam != 0xffffffff) {
      SendDlgItemMessageW(*(HWND *)(param_1 + 8),3,0x197,wParam,param_2);
    }
    FUN_00015624(param_1);
  }
  return 0;
}



/* 00015a08 FUN_00015a08 */

/* Boundary evidence: original MIPS .pdata 00015a08..00015b93. Semantic name remains unreviewed. */

undefined4 *
FUN_00015a08(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  
  FUN_00030010(param_1,param_3,param_4);
  *param_1 = &PTR_FUN_0005117c;
  param_1[5] = 100;
  param_1[7] = 0;
  param_1[0xf] = param_2;
  param_1[0x10] = 1;
  param_1[4] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xe] = 0;
  param_1[3] = 0;
  param_1[0xd] = 0;
  param_1[0x11] = param_5;
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x634);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_00030bd8(puVar1);
  }
  param_1[0xc] = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00030628((int)puVar1,5,L"Tahoma",0x21,0,'\0','\0');
    FUN_00030628(param_1[0xc],6,L"Tahoma",0x24,0,'\0','\0');
    FUN_00030628(param_1[0xc],7,L"Tahoma",0x26,0,'\0','\0');
    FUN_00030628(param_1[0xc],8,L"Tahoma",0x2a,0,'\0','\0');
    FUN_00030628(param_1[0xc],9,L"Tahoma",0x34,0,'\0','\0');
  }
  return param_1;
}



/* 00015b94 Unwind@00015b94 */

/* Boundary evidence: original MIPS .pdata 00015b94..00015bc3. Semantic name remains unreviewed. */

void Unwind_00015b94(void)

{
  undefined4 *in_v0;
  
  FUN_0003008c((undefined4 *)*in_v0);
  return;
}



/* 00015bc4 Unwind@00015bc4 */

/* Boundary evidence: original MIPS .pdata 00015bc4..00015bf3. Semantic name remains unreviewed. */

void Unwind_00015bc4(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00015bf4 FUN_00015bf4 */

/* Boundary evidence: original MIPS .pdata 00015bf4..00015c63. Semantic name remains unreviewed. */

void FUN_00015bf4(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_0005117c;
  piVar1 = (int *)param_1[0xc];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
    param_1[0xc] = 0;
  }
  FUN_0003008c(param_1);
  return;
}



/* 00015c64 Unwind@00015c64 */

/* Boundary evidence: original MIPS .pdata 00015c64..00015c93. Semantic name remains unreviewed. */

void Unwind_00015c64(void)

{
  undefined4 *in_v0;
  
  FUN_0003008c((undefined4 *)*in_v0);
  return;
}



/* 00015c94 FUN_00015c94 */

/* Boundary evidence: original MIPS .pdata 00015c94..00015d07. Semantic name remains unreviewed. */

void FUN_00015c94(int param_1,HDC param_2)

{
  HGDIOBJ pvVar1;
  tagRECT local_20;
  
  GetWindowRect(*(HWND *)(param_1 + 4),&local_20);
  pvVar1 = GetStockObject(4);
  pvVar1 = SelectObject(param_2,pvVar1);
  Rectangle(param_2,local_20.left,local_20.top,local_20.right,local_20.bottom);
  SelectObject(param_2,pvVar1);
  return;
}



/* 00015d08 FUN_00015d08 */

/* Boundary evidence: original MIPS .pdata 00015d08..00015f5f. Semantic name remains unreviewed. */

void FUN_00015d08(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HBRUSH hbr;
  int iVar1;
  int *piVar2;
  tagRECT local_40;
  tagRECT local_30;
  
  GetWindowRect(*(HWND *)(param_1 + 4),&local_40);
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,local_40.right - local_40.left,local_40.bottom - local_40.top);
  h_00 = SelectObject(hdc,h);
  hbr = CreateSolidBrush(0xffffff);
  FillRect(hdc,&local_40,hbr);
  DeleteObject(hbr);
  local_30.top = 10;
  local_30.left = 0;
  local_30.right = 800;
  local_30.bottom = 0x2d;
  if (((DAT_00062788 == 0) || (DAT_00062788 == 0x1f)) || (DAT_00062788 == 0x15)) {
    DrawTextW(hdc,L"Carefully press and Repeat as the target moves around the screen.",-1,&local_30,
              0x20005);
  }
  else {
    DrawTextW(hdc,L"Carefully press and Repeat as the target moves around the screen.",-1,&local_30,
              5);
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 == 0) {
LAB_00015eb0:
    piVar2 = &DAT_000627a4 + iVar1 * 4;
LAB_00015ec0:
    if (piVar2 == (int *)0x0) goto LAB_00015ee4;
  }
  else {
    if (iVar1 == 1) {
LAB_00015ea4:
      piVar2 = &DAT_000627a4 + iVar1 * 4;
      goto LAB_00015ec0;
    }
    if (iVar1 == 2) goto LAB_00015eb0;
    if (iVar1 == 3) goto LAB_00015ea4;
    if (iVar1 == 4) {
      piVar2 = (int *)0x627e4;
      goto LAB_00015ec0;
    }
    piVar2 = &DAT_000627a4;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  Rectangle(hdc,*piVar2,piVar2[1],piVar2[2],piVar2[3]);
LAB_00015ee4:
  BitBlt(param_2,local_40.left,local_40.top,local_40.right - local_40.left,
         local_40.bottom - local_40.top,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00015f60 FUN_00015f60 */

/* Boundary evidence: original MIPS .pdata 00015f60..00016023. Semantic name remains unreviewed. */

void FUN_00015f60(int param_1,HDC param_2)

{
  char cVar1;
  HBRUSH hbr;
  COLORREF color;
  tagRECT tStack_20;
  
  GetWindowRect(*(HWND *)(param_1 + 4),&tStack_20);
  cVar1 = *(char *)(param_1 + 0x24);
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      color = 0xff00;
      goto LAB_00015fec;
    }
    if (cVar1 == '\x02') {
      color = 0xff0000;
      goto LAB_00015fec;
    }
    if (cVar1 == '\x03') {
      color = 0;
      goto LAB_00015fec;
    }
    if (cVar1 == '\x04') {
      color = 0xffffff;
      goto LAB_00015fec;
    }
  }
  color = 0xff;
LAB_00015fec:
  hbr = CreateSolidBrush(color);
  FillRect(param_2,&tStack_20,hbr);
  DeleteObject(hbr);
  return;
}



/* 00016024 FUN_00016024 */

/* Boundary evidence: original MIPS .pdata 00016024..000160b7. Semantic name remains unreviewed. */

void FUN_00016024(int param_1)

{
  if (*(int *)(param_1 + 0x1c) == 2) {
    FUN_00036de8(0x70,0);
    PostMessageW((HWND)0xffff,DAT_00064908,0,0);
    StopRVD();
    PostMessageW((HWND)0xffff,DAT_00064938,0,0);
  }
  FUN_0003006c(param_1);
  ShowWindow(*(HWND *)(param_1 + 4),0);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



/* 000160b8 FUN_000160b8 */

/* Boundary evidence: original MIPS .pdata 000160b8..00016163. Semantic name remains unreviewed. */

void FUN_000160b8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if ((iVar1 != 2) && (iVar1 != 6)) {
    if ((iVar1 == 3) || (iVar1 == 1)) {
      FUN_0003006c(param_1);
    }
    FUN_00036de8(0x70,1);
    PostMessageW((HWND)0xffff,DAT_00064908,0,1);
    *(undefined4 *)(param_1 + 0x1c) = 2;
    StartRVD();
    PostMessageW((HWND)0xffff,DAT_00064938,0,1);
  }
  return;
}



/* 00016164 FUN_00016164 */

/* Boundary evidence: original MIPS .pdata 00016164..000161f7. Semantic name remains unreviewed. */

void FUN_00016164(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 6) {
    if (*(int *)(param_1 + 0x1c) == 3) {
      FUN_0003006c(param_1);
    }
    FUN_00036de8(0x70,1);
    PostMessageW((HWND)0xffff,DAT_00064908,0,1);
    *(undefined4 *)(param_1 + 0x1c) = 2;
    StartRVD();
    PostMessageW((HWND)0xffff,DAT_00064938,0,1);
  }
  return;
}



/* 000161f8 FUN_000161f8 */

/* Boundary evidence: original MIPS .pdata 000161f8..000162eb. Semantic name remains unreviewed. */

void FUN_000161f8(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 4) {
    if (*(int *)(param_1 + 0x1c) == 2) {
      FUN_00036de8(0x70,0);
      PostMessageW((HWND)0xffff,DAT_00064908,0,0);
      StopRVD();
      PostMessageW((HWND)0xffff,DAT_00064938,0,0);
    }
    *(undefined4 *)(param_1 + 0x1c) = 4;
    if (*(int *)(DAT_00064a24 + 0x3c) == 1) {
      ShowWindow(*(HWND *)(param_1 + 4),0);
    }
    else {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
      InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    }
  }
  return;
}



/* 000162ec FUN_000162ec */

/* Boundary evidence: original MIPS .pdata 000162ec..0001639f. Semantic name remains unreviewed. */

void FUN_000162ec(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x1c) == 6) {
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 6;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xfffffffe,0,0,800,0x1e0,0x40);
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x0,0,0,800,0x1e0,0x40);
  }
  *(undefined4 *)(param_1 + 0x34) = param_2;
  return;
}



/* 000163a0 FUN_000163a0 */

/* Boundary evidence: original MIPS .pdata 000163a0..00016437. Semantic name remains unreviewed. */

void FUN_000163a0(int param_1)

{
  HWND hWnd;
  
  if (*(int *)(param_1 + 0x1c) == 3) {
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  hWnd = *(HWND *)(param_1 + 4);
  if (*(int *)(param_1 + 0x1c) != 7) {
    *(undefined4 *)(param_1 + 0x1c) = 7;
    SetWindowPos(hWnd,(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    hWnd = *(HWND *)(param_1 + 4);
  }
  InvalidateRect(hWnd,(RECT *)0x0,0);
  FUN_00030044(param_1,3000);
  return;
}



/* 00016438 FUN_00016438 */

/* Boundary evidence: original MIPS .pdata 00016438..000164d3. Semantic name remains unreviewed. */

void FUN_00016438(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  if (*(int *)(param_1 + 0x1c) == 3) {
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  if (*(int *)(param_1 + 0x1c) != 8) {
    *(undefined4 *)(param_1 + 0x1c) = 8;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
  }
  InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  FUN_00030044(param_1,3000);
  return;
}



/* 000164d4 FUN_000164d4 */

/* Boundary evidence: original MIPS .pdata 000164d4..0001656f. Semantic name remains unreviewed. */

void FUN_000164d4(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  if (*(int *)(param_1 + 0x1c) == 3) {
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  if (*(int *)(param_1 + 0x1c) != 9) {
    *(undefined4 *)(param_1 + 0x1c) = 9;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
  }
  InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  FUN_00030044(param_1,3000);
  return;
}



/* 00016570 FUN_00016570 */

/* Boundary evidence: original MIPS .pdata 00016570..0001660b. Semantic name remains unreviewed. */

void FUN_00016570(int param_1)

{
  if (*(int *)(param_1 + 0x1c) == 3) {
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  if (*(int *)(param_1 + 0x1c) != 10) {
    *(undefined4 *)(param_1 + 0x1c) = 10;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
  }
  InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  FUN_00030044(param_1,3000);
  return;
}



/* 0001660c FUN_0001660c */

/* Boundary evidence: original MIPS .pdata 0001660c..00016697. Semantic name remains unreviewed. */

void FUN_0001660c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if ((((iVar1 == 7) || (iVar1 == 8)) || (iVar1 == 9)) || (iVar1 == 10)) {
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x0,0x6c,0x10,0x246,0x3f,0x80);
    FUN_0003006c(param_1);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}



/* 00016698 FUN_00016698 */

/* Boundary evidence: original MIPS .pdata 00016698..0001670f. Semantic name remains unreviewed. */

void FUN_00016698(int param_1)

{
  NKDbgPrintfW(L"\r\n =====> HideVolume() ====> m_nViewState %d\r\n",*(undefined4 *)(param_1 + 0x1c)
              );
  if (*(int *)(param_1 + 0x1c) == 3) {
    FUN_0003006c(param_1);
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x0,0x6c,0x10,0x246,0x3f,0x80);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}



/* 00016710 FUN_00016710 */

/* Boundary evidence: original MIPS .pdata 00016710..0001683f. Semantic name remains unreviewed. */

undefined4 FUN_00016710(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar2 = 0;
  if (((iVar1 == 2) || (iVar1 == 1)) || (iVar1 == 6)) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (param_2 == 1) {
      if (iVar1 != 0xb) {
        *(undefined4 *)(param_1 + 0x1c) = 0xb;
        SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
        FUN_00030044(param_1,60000);
      }
    }
    else if (iVar1 == 0xb) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      FUN_0003006c(param_1);
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x1,0,0,800,0x1e0,0x80);
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 00016840 FUN_00016840 */

/* Boundary evidence: original MIPS .pdata 00016840..0001696b. Semantic name remains unreviewed. */

undefined4 FUN_00016840(int param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar2 = 0;
  if (((iVar1 == 2) || (iVar1 == 1)) || (iVar1 == 6)) {
    uVar2 = 0;
  }
  else if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x24) = param_3;
    if (iVar1 != 0xc) {
      *(undefined4 *)(param_1 + 0x1c) = 0xc;
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
    }
    uVar2 = 1;
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  else if (iVar1 == 0xc) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x1,0,0,800,0x1e0,0x80);
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001696c FUN_0001696c */

/* Boundary evidence: original MIPS .pdata 0001696c..00016a9f. Semantic name remains unreviewed. */

undefined4 FUN_0001696c(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar2 = 0;
  if (((iVar1 != 2) && (iVar1 != 1)) && (iVar1 != 6)) {
    if (param_2 == 3) {
      if (iVar1 == 0xd) {
        *(undefined4 *)(param_1 + 0x1c) = 0;
        SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
        SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x1,0,0,800,0x1e0,0x80);
        uVar2 = 1;
      }
    }
    else {
      *(int *)(param_1 + 0x28) = param_2;
      *(undefined4 *)(param_1 + 0x2c) = param_3;
      if (iVar1 != 0xd) {
        *(undefined4 *)(param_1 + 0x1c) = 0xd;
        SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
      }
      uVar2 = 1;
      InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    }
  }
  return uVar2;
}



/* 00016aa0 FUN_00016aa0 */

void FUN_00016aa0(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1c) == 0xb) {
    iVar1 = *(int *)(param_1 + 0x20);
    if (((((int)(param_3 & 0xffff) < (int)(&DAT_000627a4)[iVar1 * 4]) ||
         ((int)(&DAT_000627ac)[iVar1 * 4] < (int)(param_3 & 0xffff))) ||
        ((int)(param_3 >> 0x10) < (int)(&DAT_000627a8)[iVar1 * 4])) ||
       ((int)(&DAT_000627b0)[iVar1 * 4] < (int)(param_3 >> 0x10))) {
      DAT_000648f4 = 0;
    }
    else {
      DAT_000648f4 = 1;
    }
  }
  return;
}



/* 00016b48 FUN_00016b48 */

/* Boundary evidence: original MIPS .pdata 00016b48..00016c43. Semantic name remains unreviewed. */

void FUN_00016b48(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  LPARAM lParam;
  
  if (*(int *)(param_1 + 0x1c) != 0xb) {
    return;
  }
  if (DAT_000648f4 == 0) {
LAB_00016c10:
    lParam = 0xf00000;
  }
  else {
    DAT_000648f4 = 0;
    iVar1 = *(int *)(param_1 + 0x20);
    if (((((int)(param_3 & 0xffff) < (int)(&DAT_000627a4)[iVar1 * 4]) ||
         ((int)(&DAT_000627ac)[iVar1 * 4] < (int)(param_3 & 0xffff))) ||
        ((int)(param_3 >> 0x10) < (int)(&DAT_000627a8)[iVar1 * 4])) ||
       ((int)(&DAT_000627b0)[iVar1 * 4] < (int)(param_3 >> 0x10))) goto LAB_00016c10;
    *(uint *)(param_1 + 0x20) = iVar1 + 1U;
    if (iVar1 + 1U < 5) goto LAB_00016c24;
    lParam = 0xf00001;
  }
  PostMessageW(*(HWND *)(param_1 + 4),0x8064,0xb50000,lParam);
LAB_00016c24:
  InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  return;
}



/* 00016c44 FUN_00016c44 */

/* Boundary evidence: original MIPS .pdata 00016c44..00016c7f. Semantic name remains unreviewed. */

void FUN_00016c44(int param_1)

{
  HMODULE pHVar1;
  
  if (*(int *)(param_1 + 0x38) == 0) {
    pHVar1 = LoadLibraryW(L"\\Storage Card\\system\\data\\LangDllEng.dll");
    *(HMODULE *)(param_1 + 0x38) = pHVar1;
  }
  return;
}



/* 00016c80 FUN_00016c80 */

/* Boundary evidence: original MIPS .pdata 00016c80..00016d7b. Semantic name remains unreviewed. */

void FUN_00016c80(int param_1,uint param_2)

{
  HMODULE pHVar1;
  LSTATUS LVar2;
  uint local_res4 [3];
  HKEY local_10 [2];
  
  local_res4[0] = param_2;
  if (*(HMODULE *)(param_1 + 0x38) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  DAT_00062788 = local_res4[0];
  if (0x1f < local_res4[0]) {
    DAT_00062788 = 2;
  }
  pHVar1 = LoadLibraryW((LPCWSTR)(&PTR_u__Storage_Card_system_data_LangDl_00062834)[DAT_00062788]);
  *(HMODULE *)(param_1 + 0x38) = pHVar1;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,local_10);
  if (LVar2 == 0) {
    RegSetValueExW(local_10[0],L"SYS_LANG_TYPE",0,4,(BYTE *)local_res4,4);
    RegCloseKey(local_10[0]);
  }
  return;
}



/* 00016d7c FUN_00016d7c */

/* Boundary evidence: original MIPS .pdata 00016d7c..00016dbb. Semantic name remains unreviewed. */

void FUN_00016d7c(int param_1)

{
  if (*(HMODULE *)(param_1 + 0x38) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0x38));
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}



/* 00016dbc FUN_00016dbc */

undefined4 FUN_00016dbc(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x30) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x61c);
  }
  return uVar1;
}



/* 00016ddc FUN_00016ddc */

/* Boundary evidence: original MIPS .pdata 00016ddc..00016e03. Semantic name remains unreviewed. */

void FUN_00016ddc(int param_1,int param_2)

{
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    FUN_00030a78(*(int **)(param_1 + 0x30),param_2);
  }
  return;
}



/* 00016e04 FUN_00016e04 */

/* Boundary evidence: original MIPS .pdata 00016e04..00016e4f. Semantic name remains unreviewed. */

undefined4 * FUN_00016e04(undefined4 *param_1,uint param_2)

{
  FUN_00015bf4(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00016e50 FUN_00016e50 */

/* Boundary evidence: original MIPS .pdata 00016e50..00016ef3. Semantic name remains unreviewed. */

void FUN_00016e50(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x1c);
  if (uVar1 == 1) {
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    return;
  }
  if (uVar1 != 3) {
    if (uVar1 < 7) {
      return;
    }
    if (10 < uVar1) {
      if (uVar1 != 0xb) {
        return;
      }
      FUN_0003006c(param_1);
      PostMessageW(*(HWND *)(param_1 + 4),0x8064,0xb50000,0xf00000);
      return;
    }
  }
  FUN_00016024(param_1);
  return;
}



/* 00016ef4 FUN_00016ef4 */

/* Boundary evidence: original MIPS .pdata 00016ef4..00017457. Semantic name remains unreviewed. */

void FUN_00016ef4(int param_1,HDC param_2)

{
  undefined1 uVar1;
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  COLORREF color;
  uint uVar5;
  int iVar6;
  tagRECT local_c0;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00064820;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar2 = (HGDIOBJ)0x0;
  }
  else {
    pvVar2 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0);
  }
  pvVar2 = SelectObject(hdc_00,pvVar2);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar2);
  if (*(int *)(DAT_00064828 + 0x2c) != 0) {
    if ((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0x18) == 1)) {
      piVar3 = *(int **)(param_1 + 0x30);
      if (piVar3 == (int *)0x0) goto LAB_00017044;
      iVar4 = 2;
    }
    else {
      piVar3 = *(int **)(param_1 + 0x30);
      if (piVar3 == (int *)0x0) {
LAB_00017044:
        pvVar2 = (HGDIOBJ)0x0;
        goto LAB_00017130;
      }
      iVar4 = 3;
    }
    pvVar2 = (HGDIOBJ)FUN_00030adc(piVar3,iVar4);
    goto LAB_00017130;
  }
  iVar4 = FUN_00011e88(DAT_00064828);
  if (iVar4 == 7) {
    piVar3 = *(int **)(param_1 + 0x30);
    if (piVar3 != (int *)0x0) {
      iVar4 = 5;
      goto LAB_000170e4;
    }
LAB_000170f4:
    pvVar2 = (HGDIOBJ)0x0;
  }
  else {
    if (iVar4 == 8) {
LAB_000170c0:
      piVar3 = *(int **)(param_1 + 0x30);
      if (piVar3 != (int *)0x0) {
        iVar4 = 6;
        goto LAB_000170e4;
      }
      goto LAB_000170f4;
    }
    if (iVar4 != 9) {
      if ((iVar4 == 10) || (iVar4 == 0xc)) goto LAB_000170c0;
      if (iVar4 != 0xd) {
        piVar3 = *(int **)(param_1 + 0x30);
        if (piVar3 != (int *)0x0) {
          iVar4 = 2;
          goto LAB_000170e4;
        }
        goto LAB_000170f4;
      }
    }
    piVar3 = *(int **)(param_1 + 0x30);
    if (piVar3 == (int *)0x0) goto LAB_000170f4;
    iVar4 = 4;
LAB_000170e4:
    pvVar2 = (HGDIOBJ)FUN_00030adc(piVar3,iVar4);
  }
  uVar1 = FUN_00011e90(DAT_00064828);
  iVar4 = CONCAT31(extraout_var,uVar1);
  if ((iVar4 != 0xff) && (*(int *)(param_1 + 0x10) != iVar4)) {
    NKDbgPrintfW(L"~!@#$ FFFFFFFFF [%d, %d] $#@!~\r\n",*(int *)(param_1 + 0x10),iVar4);
    *(int *)(param_1 + 0x10) = iVar4;
  }
LAB_00017130:
  pvVar2 = SelectObject(hdc_00,pvVar2);
  if ((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0x18) == 1)) {
    TransparentImage(hdc,0x12,0xb,0x24,0x27,hdc_00,0x24,0,0x24,0x27,0xffff);
  }
  else {
    TransparentImage(hdc,0x12,0xb,0x24,0x27,hdc_00,0,0,0x24,0x27,0xffff);
  }
  SelectObject(hdc_00,pvVar2);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar2 = (HGDIOBJ)0x0;
  }
  else {
    pvVar2 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),1);
  }
  pvVar2 = SelectObject(hdc_00,pvVar2);
  uVar5 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar4 = 0x3f;
    do {
      BitBlt(hdc,iVar4,0xe,8,0x20,hdc_00,8,0,0xcc0020);
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0xe;
    } while (uVar5 < *(uint *)(param_1 + 0x10));
  }
  uVar5 = *(uint *)(param_1 + 0x10);
  if (uVar5 < 0x1f) {
    iVar6 = 0x1f - uVar5;
    iVar4 = uVar5 * 0xe + 0x3f;
    do {
      BitBlt(hdc,iVar4,0xe,8,0x20,hdc_00,0,0,0xcc0020);
      iVar6 = iVar6 + -1;
      iVar4 = iVar4 + 0xe;
    } while (iVar6 != 0);
  }
  SelectObject(hdc_00,pvVar2);
  DeleteDC(hdc_00);
  SetBkMode(hdc,1);
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x30) + 0x61c);
  }
  if (iVar4 == 2) {
    color = 0;
  }
  else {
    color = 0xffffff;
  }
  SetTextColor(hdc,color);
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar2 = (HGDIOBJ)0x0;
  }
  else {
    pvVar2 = (HGDIOBJ)FUN_000305f8(*(int *)(param_1 + 0x30),8);
  }
  pvVar2 = SelectObject(hdc,pvVar2);
  local_c0.left = 0x201;
  local_c0.top = 9;
  local_c0.right = 0x233;
  local_c0.bottom = 0x33;
  wsprintfW(aWStack_b0,L"%02d",*(undefined4 *)(param_1 + 0x10));
  DrawTextW(hdc,aWStack_b0,-1,&local_c0,0);
  SelectObject(hdc,pvVar2);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_0004a3f4(local_30);
  return;
}



/* 00017458 FUN_00017458 */

/* Boundary evidence: original MIPS .pdata 00017458..000178db. Semantic name remains unreviewed. */

void FUN_00017458(int param_1,HDC param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  HDC hdc;
  uint uVar4;
  HGDIOBJ pvVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  
  uVar3 = DAT_00064820;
  if (DAT_00064888 != 0) {
    hdc = CreateCompatibleDC(param_2);
    cVar2 = *(char *)(DAT_00064888 + 0x18);
    iVar7 = 2;
    uVar8 = *(int *)(DAT_00064888 + 0x10) - 0x28;
    uVar4 = uVar8;
    if (cVar2 == '\x02') {
      uVar9 = __litodp(uVar8);
      uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0xcccccccd,0x3ffccccc);
      uVar9 = __dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0x40400000);
      uVar9 = __dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0x3fe00000);
      uVar4 = __dptoli((int)uVar9,(int)((ulonglong)uVar9 >> 0x20));
    }
    if (((param_3 == 0) ||
        ((((cVar2 != '\x01' || ((int)uVar4 < -3)) || (3 < (int)uVar4)) &&
         (((cVar2 != '\x02' || ((int)uVar4 < 0x1b)) || (0x25 < (int)uVar4)))))) && (cVar2 != '\0'))
    {
      if (*(int **)(param_1 + 0x30) == (int *)0x0) {
        pvVar5 = (HGDIOBJ)0x0;
      }
      else {
        iVar6 = 0xc;
        if (cVar2 != '\x02') {
          iVar6 = 0xd;
        }
        pvVar5 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),iVar6);
      }
      pvVar5 = SelectObject(hdc,pvVar5);
      TransparentImage(param_2,0x2f0,0x32,0x11,0xf,hdc,0,0,0x11,0xf,0xffff);
      SelectObject(hdc,pvVar5);
    }
    if (*(int **)(param_1 + 0x30) == (int *)0x0) {
      pvVar5 = (HGDIOBJ)0x0;
    }
    else {
      pvVar5 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0xe);
    }
    pvVar5 = SelectObject(hdc,pvVar5);
    if ((int)uVar8 < 0xd7) {
      bVar1 = (int)uVar4 < 0;
      if (bVar1) {
        uVar4 = -uVar4;
      }
      TransparentImage(param_2,0x2e1,0x32,0xd,0x19,hdc,(uVar4 % 10) * 0xd,0,0xd,0x19,0xffff);
      uVar8 = uVar4 / 10;
      if (uVar4 / 100 == 0) {
        if (uVar8 != 0) {
          TransparentImage(param_2,0x2d4,0x32,0xd,0x19,hdc,(uVar8 % 10) * 0xd,0,0xd,0x19,0xffff);
          iVar7 = 3;
        }
      }
      else {
        TransparentImage(param_2,0x2d4,0x32,0xd,0x19,hdc,(uVar8 % 10) * 0xd,0,0xd,0x19,0xffff);
        TransparentImage(param_2,0x2c7,0x32,0xd,0x19,hdc,((uVar4 / 100) % 10) * 0xd,0,0xd,0x19,
                         0xffff);
        iVar7 = 4;
      }
      if (bVar1) {
        TransparentImage(param_2,iVar7 * -0xd + 0x2ee,0x32,0xd,0x19,hdc,0x82,0,0xd,0x19,0xffff);
      }
    }
    else {
      TransparentImage(param_2,0x2e1,0x32,0xd,0x19,hdc,0x82,0,0xd,0x19,0xffff);
      TransparentImage(param_2,0x2d4,0x32,0xd,0x19,hdc,0x82,0,0xd,0x19,0xffff);
    }
    SelectObject(hdc,pvVar5);
    DeleteDC(hdc);
  }
  FUN_0004a3f4(uVar3);
  return;
}



/* 000178dc FUN_000178dc */

/* Boundary evidence: original MIPS .pdata 000178dc..00017e7b. Semantic name remains unreviewed. */

void FUN_000178dc(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  COLORREF color;
  int iVar2;
  int iVar3;
  uint uVar4;
  UINT format;
  int iVar5;
  tagRECT local_250;
  HGDIOBJ local_240;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00064820;
  format = 1;
  if (((DAT_00062788 == 0) || (DAT_00062788 == 0x1f)) || (DAT_00062788 == 0x15)) {
    format = 0x20001;
  }
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  uVar4 = 7;
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),7);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,800,0x1e0,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  SetBkMode(hdc,1);
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x61c);
  }
  if (iVar2 == 2) {
    color = 0;
  }
  else {
    color = 0xffffff;
  }
  SetTextColor(hdc,color);
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_000305f8(*(int *)(param_1 + 0x30),6);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_250.right = 800;
  local_250.left = 0;
  local_250.top = 0x15;
  local_250.bottom = 0x42;
  if (*(HINSTANCE *)(param_1 + 0x38) == (HINSTANCE)0x0) {
    wsprintfW(aWStack_238,L"Software Update");
  }
  else {
    LoadStringW(*(HINSTANCE *)(param_1 + 0x38),0x4ba,aWStack_238,0x40);
  }
  DrawTextW(hdc,aWStack_238,-1,&local_250,1);
  local_250.top = 0x8b;
  local_250.bottom = 0x103;
  if (*(HINSTANCE *)(param_1 + 0x38) == (HINSTANCE)0x0) {
    wsprintfW(aWStack_238,
              L"Update in progress\r\nDo not disconnect the USB\r\nor turn off the engine");
  }
  else {
    LoadStringW(*(HINSTANCE *)(param_1 + 0x38),0x4bb,aWStack_238,0x104);
  }
  DrawTextW(hdc,aWStack_238,-1,&local_250,format);
  SelectObject(hdc,pvVar1);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0xb);
  }
  local_240 = SelectObject(hdc_00,pvVar1);
  iVar5 = 7;
  iVar2 = 0;
  do {
    iVar3 = iVar2;
    BitBlt(hdc,iVar3 + 0xd8,0x128,0x24,0x12,hdc_00,0x24,0,0xcc0020);
    iVar5 = iVar5 + -1;
    iVar2 = iVar3 + 0x25;
  } while (iVar5 != 0);
  if (*(uint *)(param_1 + 0x14) == 1000) {
    iVar3 = iVar3 + 0xfd;
    do {
      BitBlt(hdc,iVar3,0x128,0x24,0x12,hdc_00,0x24,0,0xcc0020);
      iVar3 = iVar3 + 0x25;
      if (uVar4 < 9) {
        iVar5 = 9 - uVar4;
        iVar2 = iVar3;
        do {
          BitBlt(hdc,iVar2,0x128,0x24,0x12,hdc_00,0,0,0xcc0020);
          iVar5 = iVar5 + -1;
          iVar2 = iVar2 + 0x25;
        } while (iVar5 != 0);
      }
      BitBlt(hdc,0,0,800,0x1e0,hdc,0,0,0xcc0020);
      Sleep(1000);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 10);
  }
  else {
    if (*(uint *)(param_1 + 0x14) < 0x21) {
      iVar5 = 3;
      uVar4 = 10;
      do {
        BitBlt(hdc,iVar2 + 0xd8,0x128,0x24,0x12,hdc_00,0,0,0xcc0020);
        iVar5 = iVar5 + -1;
        iVar2 = iVar2 + 0x25;
      } while (iVar5 != 0);
    }
    if (uVar4 < 10) {
      iVar2 = iVar2 + 0xd8;
      do {
        if (uVar4 < *(uint *)(param_1 + 0x14) / 0x21 + 7) {
          BitBlt(hdc,iVar2,0x128,0x24,0x12,hdc_00,0x24,0,0xcc0020);
          iVar2 = iVar2 + 0x25;
          if (uVar4 < 9) {
            iVar3 = 9 - uVar4;
            iVar5 = iVar2;
            do {
              BitBlt(hdc,iVar5,0x128,0x24,0x12,hdc_00,0,0,0xcc0020);
              iVar3 = iVar3 + -1;
              iVar5 = iVar5 + 0x25;
            } while (iVar3 != 0);
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < 10);
    }
  }
  SelectObject(hdc_00,local_240);
  DeleteDC(hdc_00);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_0004a3f4(local_30);
  return;
}



/* 00017e7c FUN_00017e7c */

/* Boundary evidence: original MIPS .pdata 00017e7c..00018087. Semantic name remains unreviewed. */

void FUN_00017e7c(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HBRUSH hbr;
  HGDIOBJ pvVar1;
  tagRECT local_58;
  tagRECT local_48;
  tagRECT local_38;
  
  GetWindowRect(*(HWND *)(param_1 + 4),&local_58);
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,local_58.right - local_58.left,local_58.bottom - local_58.top);
  h_00 = SelectObject(hdc,h);
  hbr = CreateSolidBrush(0);
  FillRect(hdc,&local_58,hbr);
  DeleteObject(hbr);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xffffff);
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_000305f8(*(int *)(param_1 + 0x30),6);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_48.top = 0xbe;
  local_38.bottom = 0x118;
  local_48.right = 700;
  local_38.right = 700;
  local_48.left = 100;
  local_38.left = 100;
  local_48.bottom = 0xe6;
  local_38.top = 0xf0;
  DrawTextW(hdc,(LPCWSTR)(&PTR_u_System_not_configured__0006278c)[*(int *)(param_1 + 0x34) * 2],-1,
            &local_48,1);
  DrawTextW(hdc,(LPCWSTR)(&PTR_u_Please_connect_Diag_tool_00062790)[*(int *)(param_1 + 0x34) * 2],-1
            ,&local_38,1);
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,local_58.left,local_58.top,local_58.right - local_58.left,
         local_58.bottom - local_58.top,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00018088 FUN_00018088 */

/* Boundary evidence: original MIPS .pdata 00018088..0001837f. Semantic name remains unreviewed. */

void FUN_00018088(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HBRUSH hbr;
  HGDIOBJ pvVar1;
  int iVar2;
  tagRECT local_58;
  tagRECT local_48;
  tagRECT local_38;
  
  GetWindowRect(*(HWND *)(param_1 + 4),&local_58);
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,local_58.right - local_58.left,local_58.bottom - local_58.top);
  h_00 = SelectObject(hdc,h);
  hbr = CreateSolidBrush(0);
  FillRect(hdc,&local_58,hbr);
  DeleteObject(hbr);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xffffff);
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_000305f8(*(int *)(param_1 + 0x30),6);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_48.top = 0xbe;
  local_48.left = 100;
  local_38.left = 100;
  local_38.bottom = 0x140;
  iVar2 = *(int *)(param_1 + 0x28);
  local_48.right = 700;
  local_48.bottom = 0xe6;
  local_38.top = 0xf0;
  local_38.right = 700;
  if (iVar2 == 0) {
    DrawTextW(hdc,L"FRONT BUTTON TEST",-1,&local_48,1);
  }
  else if (iVar2 == 1) {
    DrawTextW(hdc,L"SWRC BUTTON TEST",-1,&local_48,1);
  }
  else if (iVar2 == 2) {
    DrawTextW(hdc,L"PTT TEST",-1,&local_48,1);
  }
  else if (iVar2 == 4) {
    DrawTextW(hdc,L"BUTTON TEST",-1,&local_48,1);
  }
  else {
    DrawTextW(hdc,L"UNKNOWN BUTTON TEST",-1,&local_48,1);
  }
  SelectObject(hdc,pvVar1);
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_000305f8(*(int *)(param_1 + 0x30),9);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  SetTextColor(hdc,0xffffff);
  if (*(uint *)(param_1 + 0x2c) < 0x10) {
    DrawTextW(hdc,(LPCWSTR)(&PTR_u_START_000627f4)[*(uint *)(param_1 + 0x2c)],-1,&local_38,1);
  }
  else {
    DrawTextW(hdc,L"Unknown button",-1,&local_38,1);
  }
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,local_58.left,local_58.top,local_58.right - local_58.left,
         local_58.bottom - local_58.top,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00018380 FUN_00018380 */

/* Boundary evidence: original MIPS .pdata 00018380..00018767. Semantic name remains unreviewed. */

void FUN_00018380(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  COLORREF color;
  int iVar2;
  uint x;
  uint uVar3;
  tagRECT local_c0;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00064820;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0xf);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  x = 0x4a;
  uVar3 = 0x4a;
  do {
    BitBlt(hdc,uVar3,0x10,0x2f,0x1d,hdc_00,0,0,0xcc0020);
    uVar3 = uVar3 + 0x39;
  } while (uVar3 < 0x212);
  if ((0 < *(int *)(DAT_00064888 + 0x3c)) && (uVar3 = 0, *(int *)(DAT_00064888 + 0x3c) != 0)) {
    do {
      if (0x211 < x) break;
      BitBlt(hdc,x,0x10,0x2f,0x1d,hdc_00,0x2f,0,0xcc0020);
      uVar3 = uVar3 + 1;
      x = x + 0x39;
    } while (uVar3 < *(uint *)(DAT_00064888 + 0x3c));
  }
  SelectObject(hdc_00,pvVar1);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x10);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
  SelectObject(hdc_00,pvVar1);
  DeleteDC(hdc_00);
  SetBkMode(hdc,1);
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x61c);
  }
  if (iVar2 == 2) {
    color = 0;
  }
  else {
    color = 0xffffff;
  }
  SetTextColor(hdc,color);
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_000305f8(*(int *)(param_1 + 0x30),8);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_c0.left = 0x240;
  local_c0.top = 9;
  local_c0.right = 0x201;
  local_c0.bottom = 0x33;
  wsprintfW(aWStack_b0,L"%d",*(undefined4 *)(DAT_00064888 + 0x3c));
  DrawTextW(hdc,aWStack_b0,-1,&local_c0,0x101);
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_0004a3f4(local_30);
  return;
}



/* 00018768 FUN_00018768 */

/* Boundary evidence: original MIPS .pdata 00018768..00018d5f. Semantic name remains unreviewed. */

void FUN_00018768(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  HINSTANCE hInstance;
  COLORREF color;
  UINT uID;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  tagRECT local_460;
  tagRECT local_450;
  WCHAR local_440;
  undefined1 auStack_43e [518];
  WCHAR local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_00064820;
  iVar4 = *(int *)(DAT_00064888 + 0x2c);
  if (((iVar4 != 8) && (iVar4 != 10)) && ((iVar4 < 0x14 || (0xff < iVar4)))) goto LAB_00018d2c;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x14);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
  SelectObject(hdc_00,pvVar1);
  SetBkMode(hdc,1);
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x30) + 0x61c);
  }
  if (iVar3 == 2) {
    color = 0;
  }
  else {
    color = 0xffffff;
  }
  SetTextColor(hdc,color);
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_000305f8(*(int *)(param_1 + 0x30),7);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_440 = L'\0';
  memset(auStack_43e,0,0x206);
  local_238 = L'\0';
  memset(auStack_236,0,0x206);
  local_460.left = 0x3c;
  local_460.top = 4;
  local_460.right = 0x20a;
  local_460.bottom = 0x37;
  if (iVar4 == 8) {
    hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38);
    if (hInstance != (HINSTANCE)0x0) {
      uID = 0x872;
LAB_00018a04:
      LoadStringW(hInstance,uID,&local_440,0x103);
    }
  }
  else if (iVar4 == 10) {
    hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38);
    if (hInstance != (HINSTANCE)0x0) {
      uID = 0x871;
      goto LAB_00018a04;
    }
  }
  else if ((0x13 < iVar4) && (iVar4 < 0x100)) {
    if (*(char *)(DAT_00064888 + 0x18) == '\x02') {
      uVar5 = __litodp(iVar4);
      uVar5 = __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x3fe00000);
      uVar5 = __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0xcccccccd,0x3ffccccc);
      __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40400000);
    }
    else {
      uVar5 = __litodp(iVar4);
      __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x3fe00000);
    }
    if (*(HINSTANCE *)(DAT_000648ec + 0x38) != (HINSTANCE)0x0) {
      LoadStringW(*(HINSTANCE *)(DAT_000648ec + 0x38),0x870,&local_238,0x103);
    }
    wsprintfW(&local_440,L"%s%.1f",&local_238);
  }
  DrawTextW(hdc,&local_440,-1,&local_450,0x505);
  DrawTextW(hdc,&local_440,-1,&local_460,0x105);
  SelectObject(hdc,pvVar1);
  if ((0x13 < iVar4) && (iVar4 < 0x100)) {
    iVar3 = local_450.right - local_450.left;
    iVar4 = local_450.bottom - local_450.top;
    if (*(int **)(param_1 + 0x30) == (int *)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      iVar2 = 0x1c;
      if (*(char *)(DAT_00064888 + 0x18) != '\x02') {
        iVar2 = 0x1d;
      }
      pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),iVar2);
    }
    pvVar1 = SelectObject(hdc_00,pvVar1);
    iVar2 = iVar4 >> 1;
    if (((DAT_00062788 == 0) || (DAT_00062788 == 0x1f)) || (DAT_00062788 == 0x15)) {
      if (iVar4 < 0) {
        iVar2 = iVar4 + 1 >> 1;
      }
      iVar4 = iVar2 + 10;
      if (iVar4 < 0) {
        iVar4 = iVar2 + 0xb;
      }
      iVar2 = -iVar3 + 0x1ce;
      if (iVar2 < 0) {
        iVar2 = -iVar3 + 0x1cf;
      }
      TransparentImage(hdc,(iVar2 >> 1) + 0x19,iVar4 >> 1,0x1e,0x1e,hdc_00,0,0,0x1e,0x1e,0xffff);
    }
    else {
      if (iVar4 < 0) {
        iVar2 = iVar4 + 1 >> 1;
      }
      iVar4 = iVar2 + 10;
      if (iVar4 < 0) {
        iVar4 = iVar2 + 0xb;
      }
      iVar2 = -iVar3 + 0x1ce;
      if (iVar2 < 0) {
        iVar2 = -iVar3 + 0x1cf;
      }
      TransparentImage(hdc,(iVar2 >> 1) + iVar3 + 0x41,iVar4 >> 1,0x1e,0x1e,hdc_00,0,0,0x1e,0x1e,
                       0xffff);
    }
    SelectObject(hdc_00,pvVar1);
  }
  DeleteDC(hdc_00);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
LAB_00018d2c:
  FUN_0004a3f4(local_30);
  return;
}



/* 00018d60 FUN_00018d60 */

/* Boundary evidence: original MIPS .pdata 00018d60..0001955b. Semantic name remains unreviewed. */

void FUN_00018d60(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  HINSTANCE hInstance;
  int iVar2;
  COLORREF color;
  int iVar3;
  UINT uID;
  int iVar4;
  tagRECT local_258;
  tagRECT local_248;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00064820;
  iVar2 = *(int *)(param_1 + 0xc);
  iVar4 = 0;
  if (iVar2 == 0) {
    iVar4 = *(int *)(DAT_00064888 + 0x24);
  }
  else if (iVar2 == 4) {
    iVar4 = *(int *)(DAT_00064888 + 0x34);
  }
  else if (iVar2 == 5) {
    iVar4 = *(int *)(DAT_00064888 + 0x38);
  }
  else if (iVar2 == 6) {
    iVar4 = *(int *)(DAT_00064888 + 0x3c);
  }
  else if (iVar2 == 9) {
    iVar4 = *(int *)(DAT_00064888 + 0x48);
  }
  else if (iVar2 == 10) {
    iVar4 = *(int *)(DAT_00064888 + 0x4c);
  }
  else if (iVar2 == 0xb) {
    iVar4 = *(int *)(DAT_00064888 + 0x50);
  }
  else {
    NKDbgPrintfW(L"ERROR [DrawEcoTEXT] m_eClime_type : [%d]\r\n");
  }
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == 0) {
    if (*(int **)(param_1 + 0x30) == (int *)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x13);
    }
    pvVar1 = SelectObject(hdc_00,pvVar1);
    TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
LAB_0001910c:
    SelectObject(hdc_00,pvVar1);
    DeleteDC(hdc_00);
  }
  else {
    if (iVar2 == 4) {
      if (*(int **)(param_1 + 0x30) == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x12);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      goto LAB_0001910c;
    }
    if (iVar2 == 6) {
      if (*(int **)(param_1 + 0x30) == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x10);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      SelectObject(hdc_00,pvVar1);
    }
    else if (iVar2 == 0xb) {
      if (*(int **)(param_1 + 0x30) == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x11);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      goto LAB_0001910c;
    }
  }
  DeleteDC(hdc_00);
  SetBkMode(hdc,1);
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x61c);
  }
  if (iVar2 == 2) {
    color = 0;
  }
  else {
    color = 0xffffff;
  }
  SetTextColor(hdc,color);
  if ((DAT_00062788 == 0) || (DAT_00062788 == 0x1f)) {
    iVar2 = *(int *)(param_1 + 0x30);
    if (iVar2 != 0) {
      iVar3 = 5;
      goto LAB_000191b0;
    }
LAB_000191c0:
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x30);
    if (iVar2 == 0) goto LAB_000191c0;
    iVar3 = 7;
LAB_000191b0:
    pvVar1 = (HGDIOBJ)FUN_000305f8(iVar2,iVar3);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_258.bottom = 0x37;
  local_248.bottom = 0x37;
  local_258.left = 0x3c;
  local_258.top = 4;
  local_258.right = 0x20a;
  local_248.left = 0x5a;
  local_248.top = 4;
  local_248.right = 0x20a;
  wsprintfW(aWStack_238,L"");
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == 0xb) {
    if (iVar4 == 1) {
      hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38);
      if (hInstance == (HINSTANCE)0x0) goto LAB_00019260;
      uID = 0x86b;
    }
    else {
      if ((iVar4 != 2) ||
         (hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38), hInstance == (HINSTANCE)0x0))
      goto LAB_00019260;
      uID = 0x86c;
    }
  }
  else if (iVar2 == 9) {
    if (iVar4 == 1) {
      hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38);
      if (hInstance == (HINSTANCE)0x0) goto LAB_00019260;
      uID = 0x878;
    }
    else {
      if ((iVar4 != 2) ||
         (hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38), hInstance == (HINSTANCE)0x0))
      goto LAB_00019260;
      uID = 0x879;
    }
  }
  else if (iVar2 == 10) {
    if (iVar4 == 1) {
      hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38);
      if (hInstance == (HINSTANCE)0x0) goto LAB_00019260;
      uID = 0x87a;
    }
    else {
      if ((iVar4 != 2) ||
         (hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38), hInstance == (HINSTANCE)0x0))
      goto LAB_00019260;
      uID = 0x87b;
    }
  }
  else if (iVar2 == 4) {
    if (iVar4 == 1) {
      hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38);
      if (hInstance == (HINSTANCE)0x0) goto LAB_00019260;
      uID = 0x873;
    }
    else {
      if ((iVar4 != 2) ||
         (hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38), hInstance == (HINSTANCE)0x0))
      goto LAB_00019260;
      uID = 0x874;
    }
  }
  else if (iVar2 == 0) {
    if (iVar4 == 1) {
      hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38);
      if (hInstance == (HINSTANCE)0x0) goto LAB_00019260;
      uID = 0x86d;
    }
    else {
      if ((iVar4 != 2) ||
         (hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38), hInstance == (HINSTANCE)0x0))
      goto LAB_00019260;
      uID = 0x86e;
    }
  }
  else if (iVar2 == 5) {
    if (iVar4 == 1) {
      hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38);
      if (hInstance == (HINSTANCE)0x0) goto LAB_00019260;
      uID = 0x875;
    }
    else {
      if ((iVar4 != 2) ||
         (hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38), hInstance == (HINSTANCE)0x0))
      goto LAB_00019260;
      uID = 0x876;
    }
  }
  else {
    if (((iVar2 != 6) || (iVar4 != 0xf)) ||
       (hInstance = *(HINSTANCE *)(DAT_000648ec + 0x38), hInstance == (HINSTANCE)0x0))
    goto LAB_00019260;
    uID = 0x877;
  }
  LoadStringW(hInstance,uID,aWStack_238,0x103);
LAB_00019260:
  iVar2 = *(int *)(param_1 + 0xc);
  if (((iVar2 == 5) || (iVar2 == 10)) || (iVar2 == 9)) {
    DrawTextW(hdc,aWStack_238,-1,&local_258,0x105);
  }
  else {
    DrawTextW(hdc,aWStack_238,-1,&local_248,0x105);
  }
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_0004a3f4(local_30);
  return;
}



/* 0001955c FUN_0001955c */

/* Boundary evidence: original MIPS .pdata 0001955c..00019e27. Semantic name remains unreviewed. */

void FUN_0001955c(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  int *piVar2;
  COLORREF color;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  tagRECT local_248;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00064820;
  uVar5 = 0;
  if (*(int *)(param_1 + 0xc) == 3) {
    uVar5 = *(uint *)(DAT_00064888 + 0x30);
  }
  else {
    NKDbgPrintfW(L"ERROR [DrawFlowDis] m_eClime_type : [%d]\r\n");
  }
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  uVar3 = uVar5 & 2;
  uVar7 = uVar5 & 4;
  uVar6 = uVar5 & 8;
  if ((uVar5 & 1) == 0) {
LAB_000199b8:
    if (uVar3 != 0) {
      piVar2 = *(int **)(param_1 + 0x30);
      if (uVar6 == 0) {
        if (uVar7 == 0) {
          if (piVar2 == (int *)0x0) {
            pvVar1 = (HGDIOBJ)0x0;
          }
          else {
            pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x16);
          }
          pvVar1 = SelectObject(hdc_00,pvVar1);
          TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
        }
        else {
          if (piVar2 == (int *)0x0) {
            pvVar1 = (HGDIOBJ)0x0;
          }
          else {
            pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x1b);
          }
          pvVar1 = SelectObject(hdc_00,pvVar1);
          TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
        }
      }
      else if (uVar7 == 0) {
        if (piVar2 == (int *)0x0) {
          pvVar1 = (HGDIOBJ)0x0;
        }
        else {
          pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x1b);
        }
        pvVar1 = SelectObject(hdc_00,pvVar1);
        TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      }
      else {
        if (piVar2 == (int *)0x0) {
          pvVar1 = (HGDIOBJ)0x0;
        }
        else {
          pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x1b);
        }
        pvVar1 = SelectObject(hdc_00,pvVar1);
        TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      }
LAB_00019b60:
      SelectObject(hdc_00,pvVar1);
    }
    if (uVar7 == 0) goto LAB_00019c48;
    piVar2 = *(int **)(param_1 + 0x30);
    if (uVar6 == 0) {
      if (piVar2 == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x17);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
    }
    else {
      if (piVar2 == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x17);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
    }
  }
  else {
    if ((uVar3 != 0) && (uVar6 != 0)) {
      piVar2 = *(int **)(param_1 + 0x30);
      if (uVar7 == 0) {
        if (piVar2 == (int *)0x0) {
          pvVar1 = (HGDIOBJ)0x0;
        }
        else {
          pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x1a);
        }
        pvVar1 = SelectObject(hdc_00,pvVar1);
        TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      }
      else {
        if (piVar2 == (int *)0x0) {
          pvVar1 = (HGDIOBJ)0x0;
        }
        else {
          pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x1a);
        }
        pvVar1 = SelectObject(hdc_00,pvVar1);
        TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      }
LAB_000199a8:
      SelectObject(hdc_00,pvVar1);
      goto LAB_000199b8;
    }
    if ((uVar7 != 0) && (uVar6 != 0)) {
      if (*(int **)(param_1 + 0x30) == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x19);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      goto LAB_000199a8;
    }
    if (uVar3 != 0) {
      if (*(int **)(param_1 + 0x30) == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x18);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      goto LAB_000199a8;
    }
    piVar2 = *(int **)(param_1 + 0x30);
    if (uVar7 != 0) {
      if (piVar2 == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x19);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      goto LAB_00019b60;
    }
    if (uVar6 == 0) {
      if (piVar2 == (int *)0x0) {
        pvVar1 = (HGDIOBJ)0x0;
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x15);
      }
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
      goto LAB_000199a8;
    }
    if (piVar2 == (int *)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = (HGDIOBJ)FUN_00030adc(piVar2,0x19);
    }
    pvVar1 = SelectObject(hdc_00,pvVar1);
    TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
  }
  SelectObject(hdc_00,pvVar1);
LAB_00019c48:
  if (uVar6 != 0) {
    if (*(int **)(param_1 + 0x30) == (int *)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),0x17);
    }
    pvVar1 = SelectObject(hdc_00,pvVar1);
    TransparentImage(hdc,0xc,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff);
    SelectObject(hdc_00,pvVar1);
  }
  DeleteDC(hdc_00);
  SetBkMode(hdc,1);
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x30) + 0x61c);
  }
  if (iVar4 == 2) {
    color = 0;
  }
  else {
    color = 0xffffff;
  }
  SetTextColor(hdc,color);
  if (*(int *)(param_1 + 0x30) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_000305f8(*(int *)(param_1 + 0x30),7);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_248.left = 0x3c;
  local_248.top = 4;
  local_248.right = 0x20a;
  local_248.bottom = 0x37;
  if (*(HINSTANCE *)(DAT_000648ec + 0x38) != (HINSTANCE)0x0) {
    LoadStringW(*(HINSTANCE *)(DAT_000648ec + 0x38),0x86f,aWStack_238,0x103);
  }
  DrawTextW(hdc,aWStack_238,-1,&local_248,0x105);
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_0004a3f4(local_30);
  return;
}



/* 00019e28 FUN_00019e28 */

/* Boundary evidence: original MIPS .pdata 00019e28..00019f4b. Semantic name remains unreviewed. */

void FUN_00019e28(int param_1,undefined4 param_2,undefined4 param_3)

{
  HWND pHVar1;
  HDC hDC;
  int iVar2;
  HWND hWnd;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  if ((((iVar2 != 1) && (iVar2 != 2)) && (iVar2 != 6)) && (DAT_000648f0 != 1)) {
    *(undefined4 *)(param_1 + 0x10) = param_2;
    *(undefined4 *)(param_1 + 0x18) = param_3;
    if (iVar2 == 3) {
      hWnd = *(HWND *)(param_1 + 4);
      pHVar1 = GetForegroundWindow();
      if (pHVar1 != hWnd) {
        SetWindowPos(hWnd,(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 3;
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
      hDC = GetDC(*(HWND *)(param_1 + 4));
      FUN_00016ef4(param_1,hDC);
      ReleaseDC(*(HWND *)(param_1 + 4),hDC);
    }
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    FUN_00030044(param_1,3000);
  }
  return;
}



/* 00019f4c FUN_00019f4c */

/* Boundary evidence: original MIPS .pdata 00019f4c..00019ffb. Semantic name remains unreviewed. */

void FUN_00019f4c(int param_1,int param_2)

{
  HDC hDC;
  
  if (*(int *)(param_1 + 0x14) != param_2) {
    *(int *)(param_1 + 0x14) = param_2;
    if (*(int *)(param_1 + 0x1c) != 5) {
      FUN_0003006c(param_1);
      *(undefined4 *)(param_1 + 0x1c) = 5;
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
    }
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    hDC = GetDC(*(HWND *)(param_1 + 4));
    FUN_000178dc(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 4),hDC);
  }
  return;
}



/* 00019ffc FUN_00019ffc */

/* Boundary evidence: original MIPS .pdata 00019ffc..0001a79f. Semantic name remains unreviewed. */

void FUN_00019ffc(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  uint uVar2;
  uint uVar3;
  _SYSTEMTIME _Stack_38;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),7);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,800,0x1e0,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  GetLocalTime(&_Stack_38);
  uVar3 = (uint)_Stack_38.wMinute;
  uVar2 = (uint)_Stack_38.wHour;
  if (*(int **)(param_1 + 0x30) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),8);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  if (*(char *)(*(int *)(param_1 + 0x44) + 0xb02) == '\0') {
    if (uVar2 == 0) {
      uVar2 = 0xc;
    }
    if (0xc < uVar2) {
      uVar2 = uVar2 - 0xc;
    }
    if ((int)uVar2 < 10) {
      TransparentImage(hdc,0x124,0xbc,0x3c,0x55,hdc_00,((int)uVar2 % 10) * 0x3c,0,0x3c,0x55,0xffff);
      TransparentImage(hdc,0x189,0xbc,0x3c,0x55,hdc_00,(uVar3 / 10) * 0x3c,0,0x3c,0x55,0xffff);
      TransparentImage(hdc,0x1cd,0xbc,0x3c,0x55,hdc_00,(uVar3 % 10) * 0x3c,0,0x3c,0x55,0xffff);
    }
    else {
      TransparentImage(hdc,0xe0,0xbc,0x3c,0x55,hdc_00,((int)uVar2 / 10) * 0x3c,0,0x3c,0x55,0xffff);
      TransparentImage(hdc,0x124,0xbc,0x3c,0x55,hdc_00,((int)uVar2 % 10) * 0x3c,0,0x3c,0x55,0xffff);
      TransparentImage(hdc,0x189,0xbc,0x3c,0x55,hdc_00,(uVar3 / 10) * 0x3c,0,0x3c,0x55,0xffff);
      TransparentImage(hdc,0x1cd,0xbc,0x3c,0x55,hdc_00,(uVar3 % 10) * 0x3c,0,0x3c,0x55,0xffff);
    }
  }
  else {
    TransparentImage(hdc,0xfc,0xbc,0x3c,0x55,hdc_00,(uVar2 / 10) * 0x3c,0,0x3c,0x55,0xffff);
    TransparentImage(hdc,0x140,0xbc,0x3c,0x55,hdc_00,(uVar2 % 10) * 0x3c,0,0x3c,0x55,0xffff);
    TransparentImage(hdc,0x1a5,0xbc,0x3c,0x55,hdc_00,(uVar3 / 10) * 0x3c,0,0x3c,0x55,0xffff);
    TransparentImage(hdc,0x1e9,0xbc,0x3c,0x55,hdc_00,(uVar3 % 10) * 0x3c,0,0x3c,0x55,0xffff);
  }
  SelectObject(hdc_00,pvVar1);
  if (*(char *)(*(int *)(param_1 + 0x44) + 0xb02) == '\0') {
    if (*(int **)(param_1 + 0x30) == (int *)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),9);
    }
    pvVar1 = SelectObject(hdc_00,pvVar1);
    if (_Stack_38.wHour < 0xc) {
      if ((int)uVar2 < 10) {
        TransparentImage(hdc,0x215,0xbc,0x9b,0x55,hdc_00,0,0,0x9b,0x55,0xffff);
      }
      else {
        TransparentImage(hdc,0x215,0xbc,0x9b,0x55,hdc_00,0,0,0x9b,0x55,0xffff);
      }
    }
    else if ((int)uVar2 < 10) {
      TransparentImage(hdc,0x215,0xbc,0x9b,0x55,hdc_00,0x9b,0,0x9b,0x55,0xffff);
    }
    else {
      TransparentImage(hdc,0x215,0xbc,0x9b,0x55,hdc_00,0x9b,0,0x9b,0x55,0xffff);
    }
    SelectObject(hdc_00,pvVar1);
  }
  if (*(int *)(param_1 + 0x40) == 1) {
    if (*(int **)(param_1 + 0x30) == (int *)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = (HGDIOBJ)FUN_00030adc(*(int **)(param_1 + 0x30),10);
    }
    pvVar1 = SelectObject(hdc_00,pvVar1);
    if (*(char *)(*(int *)(param_1 + 0x44) + 0xb02) == '\0') {
      if ((int)uVar2 < 10) {
        TransparentImage(hdc,0x168,0xbc,0x19,0x55,hdc_00,0,0,0x19,0x55,0xffff);
      }
      else {
        TransparentImage(hdc,0x168,0xbc,0x19,0x55,hdc_00,0,0,0x19,0x55,0xffff);
      }
    }
    else {
      TransparentImage(hdc,0x184,0xbc,0x19,0x55,hdc_00,0,0,0x19,0x55,0xffff);
    }
    SelectObject(hdc_00,pvVar1);
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  if ((*(char *)(DAT_00064888 + 0x18) == '\x01') || (*(char *)(DAT_00064888 + 0x18) == '\x02')) {
    FUN_00017458(param_1,hdc,*(int *)(param_1 + 0x40));
  }
  DeleteDC(hdc_00);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0001a7a0 FUN_0001a7a0 */

/* Boundary evidence: original MIPS .pdata 0001a7a0..0001a8db. Semantic name remains unreviewed. */

void FUN_0001a7a0(int param_1)

{
  HDC hDC;
  
  if (*(int *)(param_1 + 0x1c) == 2) {
    FUN_00036de8(0x70,0);
    PostMessageW((HWND)0xffff,DAT_00064908,0,0);
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
    FUN_00019ffc(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 4),hDC);
    StopRVD();
    PostMessageW((HWND)0xffff,DAT_00064938,0,0);
  }
  *(undefined4 *)(param_1 + 0x1c) = 1;
  PostMessageW((HWND)0xffff,0x9e62,0,0);
  SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
  ShowWindow(*(HWND *)(param_1 + 4),5);
  FUN_00030044(param_1,1000);
  return;
}



/* 0001a8dc FUN_0001a8dc */

/* Boundary evidence: original MIPS .pdata 0001a8dc..0001aa4f. Semantic name remains unreviewed. */

void FUN_0001a8dc(int param_1,HDC param_2)

{
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 1:
    if (*(int *)(DAT_00064a24 + 0x4c) == 0) {
      FUN_00019ffc(param_1,param_2);
    }
    break;
  case 2:
    FUN_00015c94(param_1,param_2);
    break;
  case 3:
    FUN_00016ef4(param_1,param_2);
    break;
  case 4:
    if (*(int *)(DAT_00064a24 + 0x3c) == 1) {
      NKDbgPrintfW(L" CDisp::OnDraw() %d, %d\r\n",*(undefined4 *)(param_1 + 0x1c),1);
    }
    else {
      FUN_00015c94(param_1,param_2);
    }
    break;
  case 5:
    FUN_000178dc(param_1,param_2);
    break;
  case 6:
    FUN_00017e7c(param_1,param_2);
    break;
  case 7:
    FUN_00018380(param_1,param_2);
    break;
  case 8:
    FUN_00018d60(param_1,param_2);
    break;
  case 9:
    FUN_0001955c(param_1,param_2);
    break;
  case 10:
    FUN_00018768(param_1,param_2);
    break;
  case 0xb:
    FUN_00015d08(param_1,param_2);
    break;
  case 0xc:
    FUN_00015f60(param_1,param_2);
    break;
  case 0xd:
    FUN_00018088(param_1,param_2);
  }
  return;
}



/* 0001aa50 FUN_0001aa50 */

/* Boundary evidence: original MIPS .pdata 0001aa50..0001ab03. Semantic name remains unreviewed. */

undefined4 FUN_0001aa50(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = CONCAT44(DAT_0006494c,DAT_00064948);
  if (param_1 == DAT_0006497c) {
    DAT_00064980 = DAT_00064980 + 1;
  }
  else {
    DAT_00064980 = 0;
  }
  DAT_0006497c = param_1;
  if (4 < DAT_00064980) {
    DAT_00064980 = 0;
    uVar1 = __dpmul(param_3,param_4,0,0x40140000);
    uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0x5a912e32,0x3efd208a);
    uVar1 = __dpadd((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_00064948,DAT_0006494c);
  }
  DAT_0006494c = (undefined4)((ulonglong)uVar1 >> 0x20);
  DAT_00064948 = (undefined4)uVar1;
  return DAT_00064948;
}



/* 0001ab04 FUN_0001ab04 */

/* Boundary evidence: original MIPS .pdata 0001ab04..0001ade7. Semantic name remains unreviewed. */

longlong FUN_0001ab04(int param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  longlong lVar13;
  
  if ((param_1 < 0) || (100 < param_1)) {
    DAT_00064998 = GetTickCount();
    uVar8 = 0xbff00000;
  }
  else {
    DVar1 = GetTickCount();
    iVar6 = DAT_00064998;
    if (DAT_00064998 == 0) {
      iVar6 = DVar1 - 100;
    }
    uVar9 = __ultodp(DVar1 - iVar6);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0xd2f1a9fc,0x3f50624d);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),*(undefined4 *)(DAT_000649b8 + 0x10),
                    *(undefined4 *)(DAT_000649b8 + 0x14));
    uVar10 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0x789abcdf,0x3f323456);
    uVar7 = (undefined4)((ulonglong)uVar10 >> 0x20);
    DAT_00064998 = DVar1;
    uVar11 = __litodp(param_1);
    uVar3 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar9 = __dpsub(0,0x40540000,(int)uVar11,uVar3);
    iVar6 = __gtd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0);
    if (iVar6 == 0) {
      uVar9 = 0;
    }
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0x3fd00000);
    uVar9 = __dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0x3ff00000);
    uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
    uVar12 = __dpmul((int)uVar9,uVar4,(int)uVar10,uVar7);
    uVar12 = __dpadd((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_00064950,DAT_00064954);
    uVar5 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar2 = (undefined4)uVar12;
    DAT_00064950 = uVar2;
    DAT_00064954 = uVar5;
    uVar9 = __dpmul((int)uVar11,uVar3,(int)uVar9,uVar4);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar10,uVar7);
    uVar9 = __dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_00064958,DAT_0006495c);
    uVar7 = (undefined4)((ulonglong)uVar9 >> 0x20);
    DAT_00064958 = (int)uVar9;
    DAT_0006495c = uVar7;
    iVar6 = __gtd(uVar2,uVar5,0,0);
    if (iVar6 == 0) {
      return 0;
    }
    lVar13 = __dpdiv((int)uVar9,uVar7,uVar2,uVar5);
    iVar6 = __gtd((int)lVar13,(int)((ulonglong)lVar13 >> 0x20),0,0);
    if (iVar6 == 0) {
      lVar13 = 0;
    }
    uVar7 = (undefined4)((ulonglong)lVar13 >> 0x20);
    iVar6 = __ltd((int)lVar13,uVar7,0,0);
    if (iVar6 == 0) {
      iVar6 = __gtd((int)lVar13,uVar7,0,0x40590000);
      if (iVar6 == 0) {
        return lVar13;
      }
      uVar8 = 0x40590000;
    }
    else {
      uVar8 = 0;
    }
  }
  return (ulonglong)uVar8 << 0x20;
}



/* 0001ade8 FUN_0001ade8 */

/* Boundary evidence: original MIPS .pdata 0001ade8..0001b0cb. Semantic name remains unreviewed. */

longlong FUN_0001ade8(int param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  longlong lVar13;
  
  if ((param_1 < 0) || (100 < param_1)) {
    DAT_000649a8 = GetTickCount();
    uVar8 = 0xbff00000;
  }
  else {
    DVar1 = GetTickCount();
    iVar6 = DAT_000649a8;
    if (DAT_000649a8 == 0) {
      iVar6 = DVar1 - 100;
    }
    uVar9 = __ultodp(DVar1 - iVar6);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0xd2f1a9fc,0x3f50624d);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),*(undefined4 *)(DAT_000649b8 + 0x10),
                    *(undefined4 *)(DAT_000649b8 + 0x14));
    uVar10 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0x789abcdf,0x3f323456);
    uVar7 = (undefined4)((ulonglong)uVar10 >> 0x20);
    DAT_000649a8 = DVar1;
    uVar11 = __litodp(param_1);
    uVar3 = (undefined4)((ulonglong)uVar11 >> 0x20);
    uVar9 = __dpsub(0,0x40540000,(int)uVar11,uVar3);
    iVar6 = __gtd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0);
    if (iVar6 == 0) {
      uVar9 = 0;
    }
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0x3fe80000);
    uVar9 = __dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0x3ff00000);
    uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
    uVar12 = __dpmul((int)uVar9,uVar4,(int)uVar10,uVar7);
    uVar12 = __dpadd((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_00064960,DAT_00064964);
    uVar5 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar2 = (undefined4)uVar12;
    DAT_00064960 = uVar2;
    DAT_00064964 = uVar5;
    uVar9 = __dpmul((int)uVar11,uVar3,(int)uVar9,uVar4);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar10,uVar7);
    uVar9 = __dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_00064968,DAT_0006496c);
    uVar7 = (undefined4)((ulonglong)uVar9 >> 0x20);
    DAT_00064968 = (int)uVar9;
    DAT_0006496c = uVar7;
    iVar6 = __gtd(uVar2,uVar5,0,0);
    if (iVar6 == 0) {
      return 0;
    }
    lVar13 = __dpdiv((int)uVar9,uVar7,uVar2,uVar5);
    iVar6 = __gtd((int)lVar13,(int)((ulonglong)lVar13 >> 0x20),0,0);
    if (iVar6 == 0) {
      lVar13 = 0;
    }
    uVar7 = (undefined4)((ulonglong)lVar13 >> 0x20);
    iVar6 = __ltd((int)lVar13,uVar7,0,0);
    if (iVar6 == 0) {
      iVar6 = __gtd((int)lVar13,uVar7,0,0x40590000);
      if (iVar6 == 0) {
        return lVar13;
      }
      uVar8 = 0x40590000;
    }
    else {
      uVar8 = 0;
    }
  }
  return (ulonglong)uVar8 << 0x20;
}



/* 0001b0cc FUN_0001b0cc */

/* Boundary evidence: original MIPS .pdata 0001b0cc..0001b1f7. Semantic name remains unreviewed. */

longlong FUN_0001b0cc(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  uVar4 = __litodp();
  uVar4 = __dpadd((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_00064970,DAT_00064974);
  uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
  DAT_00064978 = DAT_00064978 + 1;
  DAT_00064970 = (int)uVar4;
  DAT_00064974 = uVar2;
  uVar5 = __litodp();
  uVar4 = __dpdiv((int)uVar4,uVar2,(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  uVar4 = __dpsub((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x404e0000);
  lVar6 = __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x40040000);
  iVar1 = __gtd((int)lVar6,(int)((ulonglong)lVar6 >> 0x20),0,0);
  if (iVar1 == 0) {
    lVar6 = 0;
  }
  uVar2 = (undefined4)((ulonglong)lVar6 >> 0x20);
  iVar1 = __ltd((int)lVar6,uVar2,0,0);
  if (iVar1 == 0) {
    iVar1 = __gtd((int)lVar6,uVar2,0,0x40590000);
    if (iVar1 == 0) {
      return lVar6;
    }
    uVar3 = 0x40590000;
  }
  else {
    uVar3 = 0;
  }
  return (ulonglong)uVar3 << 0x20;
}



/* 0001b1f8 FUN_0001b1f8 */

/* Boundary evidence: original MIPS .pdata 0001b1f8..0001b307. Semantic name remains unreviewed. */

longlong FUN_0001b1f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  uVar4 = __dpadd(param_3,param_4,param_5,param_6);
  uVar4 = __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0x9999999a,0x3fd99999);
  uVar5 = __dpmul(param_1,param_2,0x9999999a,0x3fc99999);
  lVar6 = __dpadd((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,
                  (int)((ulonglong)uVar5 >> 0x20));
  uVar2 = (undefined4)((ulonglong)lVar6 >> 0x20);
  iVar1 = __ltd((int)lVar6,uVar2,0,0);
  if (iVar1 == 0) {
    iVar1 = __gtd((int)lVar6,uVar2,0,0x40590000);
    if (iVar1 == 0) {
      return lVar6;
    }
    uVar3 = 0x40590000;
  }
  else {
    uVar3 = 0;
  }
  return (ulonglong)uVar3 << 0x20;
}



/* 0001b308 FUN_0001b308 */

/* Boundary evidence: original MIPS .pdata 0001b308..0001b3ab. Semantic name remains unreviewed. */

longlong FUN_0001b308(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  uVar4 = __dpadd();
  lVar5 = __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
  uVar2 = (undefined4)((ulonglong)lVar5 >> 0x20);
  iVar1 = __ltd((int)lVar5,uVar2,0,0);
  if (iVar1 == 0) {
    iVar1 = __gtd((int)lVar5,uVar2,0,0x40590000);
    if (iVar1 == 0) {
      return lVar5;
    }
    uVar3 = 0x40590000;
  }
  else {
    uVar3 = 0;
  }
  return (ulonglong)uVar3 << 0x20;
}



/* 0001b3ac FUN_0001b3ac */

/* Boundary evidence: original MIPS .pdata 0001b3ac..0001b5a3. Semantic name remains unreviewed. */

void FUN_0001b3ac(int param_1)

{
  DWORD DVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x50) = 1;
  *(undefined4 *)(param_1 + 0x2c) = 1;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0xb18) = 0;
  *(undefined4 *)(iVar2 + 0xb1c) = 0;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar2 + 0xb38);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar2 + 0xb3c);
  *(undefined4 *)(param_1 + 0x5c) = 0x65;
  *(undefined4 *)(iVar2 + 0xb38) = 0;
  *(undefined4 *)(iVar2 + 0xb3c) = 0;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0xb40) = 0;
  *(undefined4 *)(iVar2 + 0xb44) = 0;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0xb30) = 0xcccccccd;
  *(undefined4 *)(iVar2 + 0xb34) = 0x40598ccc;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0xb48) = 0x66666666;
  *(undefined4 *)(iVar2 + 0xb4c) = 0x40799666;
  DAT_00064948 = 0;
  DAT_00064950 = 0;
  DAT_00064958 = 0;
  DAT_00064960 = 0;
  DAT_00064968 = 0;
  DAT_00064970 = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0x3fe;
  *(undefined4 *)(param_1 + 0x4c) = 0xffe;
  *(undefined4 *)(param_1 + 0x60) = 0;
  DAT_0006494c = 0;
  DAT_00064980 = 0;
  DAT_00064954 = 0;
  DAT_0006495c = 0;
  DAT_00064964 = 0;
  DAT_0006496c = 0;
  DAT_00064974 = 0;
  DAT_00064978 = 0;
  memset(&DAT_00062a30,100,0x140);
  DAT_00064990 = 0;
  DAT_00064984 = 0;
  DAT_00064988 = 0;
  DAT_00064994 = 0;
  memset(&DAT_00062b70,100,0x140);
  DAT_000649a0 = 0;
  DAT_0006499c = 0;
  DAT_00064989 = 0;
  DAT_000649a4 = 0;
  memset(&DAT_00062cb8,100,0x140);
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0xb60) = 0;
  *(undefined4 *)(iVar2 + 0xb64) = 0;
  DAT_0006498a = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb50) = 100;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb54) = 100;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb58) = 100;
  DAT_000649b0 = 0;
  DAT_000649ac = 0;
  DAT_000649b4 = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb5c) = 0x65;
  DVar1 = GetTickCount();
  *(DWORD *)(param_1 + 0x18) = DVar1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  DAT_0006497c = 0;
  DAT_00064998 = 0;
  DAT_000649a8 = 0;
  return;
}



/* 0001b5a4 FUN_0001b5a4 */

/* Boundary evidence: original MIPS .pdata 0001b5a4..0001b643. Semantic name remains unreviewed. */

bool FUN_0001b5a4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = __litodp(param_2);
  uVar2 = __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0x47ae147b,0x3f847ae1);
  iVar1 = __ned(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),(int)uVar2,
                (int)((ulonglong)uVar2 >> 0x20));
  if (iVar1 != 0) {
    *(undefined8 *)(param_1 + 0x10) = uVar2;
    *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0xb10) = uVar2;
  }
  return iVar1 != 0;
}



/* 0001b644 FUN_0001b644 */

/* Boundary evidence: original MIPS .pdata 0001b644..0001b6fb. Semantic name remains unreviewed. */

undefined4 FUN_0001b644(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0x40) == param_2) {
    uVar1 = 0;
  }
  else {
    if ((*(int *)(param_1 + 0x28) == 0) && (*(int *)(param_1 + 0x2c) == 0)) {
      uVar3 = __litodp(param_2);
      uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x9999999a,0x3fb99999);
      *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0xb30) = uVar3;
      *(int *)(param_1 + 0x40) = param_2;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(iVar2 + 0xb30) = 0xcccccccd;
      *(undefined4 *)(iVar2 + 0xb34) = 0x40598ccc;
      *(undefined4 *)(param_1 + 0x40) = 0x3fe;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001b6fc FUN_0001b6fc */

/* Boundary evidence: original MIPS .pdata 0001b6fc..0001b79f. Semantic name remains unreviewed. */

undefined4 FUN_0001b6fc(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0x44) == param_2) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x28) == 0) {
      if (0x1fffd < param_2) {
        param_2 = 0;
      }
      *(int *)(param_1 + 0x44) = param_2;
      uVar3 = __litodp(param_2);
      uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x9999999a,0x3fb99999);
      *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0xb38) = uVar3;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(iVar2 + 0xb38) = 0;
      *(undefined4 *)(iVar2 + 0xb3c) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001b7a0 FUN_0001b7a0 */

/* Boundary evidence: original MIPS .pdata 0001b7a0..0001b8bb. Semantic name remains unreviewed. */

undefined4 FUN_0001b7a0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0x48) == param_2) {
    uVar2 = 0;
  }
  else {
    if ((*(int *)(param_1 + 0x28) == 0) && (*(int *)(param_1 + 0x2c) == 0)) {
      *(int *)(param_1 + 0x48) = param_2;
      if ((*(int *)(param_1 + 0x38) == 4) || (*(int *)(param_1 + 0x38) == 5)) {
        if (9999 < param_2) {
          param_2 = 0;
        }
        uVar3 = __litodp(param_2);
        *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0xb40) = uVar3;
      }
      else {
        uVar3 = __litodp(param_2);
        uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x9999999a,0x3fb99999);
        iVar1 = __gtd((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x33333333,0x40a99933);
        if (iVar1 != 0) {
          uVar3 = 0;
        }
        *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0xb40) = uVar3;
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(iVar1 + 0xb40) = 0;
      *(undefined4 *)(iVar1 + 0xb44) = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001b8bc FUN_0001b8bc */

/* Boundary evidence: original MIPS .pdata 0001b8bc..0001b973. Semantic name remains unreviewed. */

undefined4 FUN_0001b8bc(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0x4c) == param_2) {
    uVar1 = 0;
  }
  else {
    if ((*(int *)(param_1 + 0x28) == 0) && (*(int *)(param_1 + 0x2c) == 0)) {
      uVar3 = __litodp(param_2);
      uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x9999999a,0x3fb99999);
      *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0xb48) = uVar3;
      *(int *)(param_1 + 0x4c) = param_2;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(iVar2 + 0xb48) = 0x66666666;
      *(undefined4 *)(iVar2 + 0xb4c) = 0x40799666;
      *(undefined4 *)(param_1 + 0x4c) = 0xffe;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001b974 FUN_0001b974 */

/* Boundary evidence: original MIPS .pdata 0001b974..0001ba7b. Semantic name remains unreviewed. */

void FUN_0001b974(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  iVar1 = __led(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,0);
  if ((((iVar1 == 0) && (*(int *)(DAT_00064a24 + 0x14) == 0)) &&
      (*(int *)(DAT_00064a24 + 0x28) == 0)) &&
     ((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)))) {
    iVar2 = *(int *)(param_1 + 0x1c);
    iVar1 = __ltd(*(undefined4 *)(iVar2 + 0xb38),*(undefined4 *)(iVar2 + 0xb3c),0x9999999a,
                  0x3fd99999);
    if (iVar1 == 0) {
      __dptofp(*(undefined4 *)(iVar2 + 0xb18),*(undefined4 *)(iVar2 + 0xb1c));
      lVar4 = FUN_0001ade8(*(int *)(param_1 + 0x58));
      uVar3 = (undefined4)((ulonglong)lVar4 >> 0x20);
      iVar1 = __ged((int)lVar4,uVar3,0,0);
      if ((iVar1 != 0) && (0 < *(int *)(param_1 + 0x40))) {
        uVar3 = __dptoli((int)lVar4,uVar3);
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb54) = uVar3;
      }
    }
  }
  return;
}



/* 0001ba7c FUN_0001ba7c */

/* Boundary evidence: original MIPS .pdata 0001ba7c..0001bb83. Semantic name remains unreviewed. */

void FUN_0001ba7c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  iVar1 = __led(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,0);
  if ((((iVar1 == 0) && (*(int *)(DAT_00064a24 + 0x14) == 0)) &&
      (*(int *)(DAT_00064a24 + 0x28) == 0)) &&
     ((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)))) {
    iVar2 = *(int *)(param_1 + 0x1c);
    iVar1 = __ltd(*(undefined4 *)(iVar2 + 0xb38),*(undefined4 *)(iVar2 + 0xb3c),0x9999999a,
                  0x3fd99999);
    if (iVar1 == 0) {
      __dptofp(*(undefined4 *)(iVar2 + 0xb18),*(undefined4 *)(iVar2 + 0xb1c));
      lVar4 = FUN_0001ab04(*(int *)(param_1 + 0x54));
      uVar3 = (undefined4)((ulonglong)lVar4 >> 0x20);
      iVar1 = __ged((int)lVar4,uVar3,0,0);
      if ((iVar1 != 0) && (0 < *(int *)(param_1 + 0x40))) {
        uVar3 = __dptoli((int)lVar4,uVar3);
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb50) = uVar3;
      }
    }
  }
  return;
}



/* 0001bb84 FUN_0001bb84 */

/* Boundary evidence: original MIPS .pdata 0001bb84..0001bda3. Semantic name remains unreviewed. */

void FUN_0001bb84(int param_1)

{
  int iVar1;
  undefined4 extraout_v1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  uVar4 = *(undefined4 *)(param_1 + 0x14);
  iVar1 = __led(uVar2,uVar4,0,0);
  if (iVar1 != 0) {
    return;
  }
  if (*(int *)(DAT_00064a24 + 0x14) != 0) {
    return;
  }
  if (*(int *)(DAT_00064a24 + 0x28) != 0) {
    return;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    return;
  }
  uVar5 = __dpmul(uVar2,uVar4,0x5a912e32,0x3efd208a);
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar5 = __dpadd(*(undefined4 *)(iVar1 + 0xb18),*(undefined4 *)(iVar1 + 0xb1c),(int)uVar5,
                  (int)((ulonglong)uVar5 >> 0x20));
  *(undefined8 *)(iVar1 + 0xb18) = uVar5;
  iVar3 = *(int *)(param_1 + 0x1c);
  iVar1 = __ged(*(undefined4 *)(iVar3 + 0xb18),*(undefined4 *)(iVar3 + 0xb1c),0x9999999a,0x3fd99999)
  ;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar3 + 0xb18) = 0x9999999a;
    *(undefined4 *)(iVar3 + 0xb1c) = 0x3fd99999;
  }
  iVar3 = *(int *)(param_1 + 0x1c);
  iVar1 = __ged(*(undefined4 *)(iVar3 + 0xb18),*(undefined4 *)(iVar3 + 0xb1c),0x9999999a,0x3fd99999)
  ;
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x2c) == 0)) {
    uVar5 = __dpsub(*(undefined4 *)(iVar3 + 0xb38),*(undefined4 *)(iVar3 + 0xb3c),
                    *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34));
    iVar1 = __ged((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fd99999);
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x2c) == 0)) goto LAB_0001bd00;
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_00015158(DAT_000648e4,1,1,0xb,0,0,100);
LAB_0001bd00:
  if (*(int *)(param_1 + 0x2c) == 0) {
    iVar3 = *(int *)(param_1 + 0x1c);
    iVar1 = __ltd(*(undefined4 *)(iVar3 + 0xb38),*(undefined4 *)(iVar3 + 0xb3c),0x9999999a,
                  0x3fd99999);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(iVar3 + 0xb14);
      iVar1 = __gtd(*(undefined4 *)(iVar3 + 0xb10),uVar2,0,0);
      if (iVar1 != 0) {
        uVar2 = FUN_0001aa50(*(int *)(param_1 + 0x60),uVar2,*(undefined4 *)(param_1 + 0x10),
                             *(undefined4 *)(param_1 + 0x14));
        iVar1 = __ged(uVar2,extraout_v1,0,0);
        if (iVar1 != 0) {
          iVar1 = *(int *)(param_1 + 0x1c);
          *(undefined4 *)(iVar1 + 0xb60) = uVar2;
          *(undefined4 *)(iVar1 + 0xb64) = extraout_v1;
        }
      }
    }
  }
  return;
}



/* 0001bda4 FUN_0001bda4 */

/* Boundary evidence: original MIPS .pdata 0001bda4..0001bf0f. Semantic name remains unreviewed. */

void FUN_0001bda4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  iVar1 = __led(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,0);
  if ((((iVar1 == 0) && (*(int *)(DAT_00064a24 + 0x14) == 0)) &&
      (*(int *)(DAT_00064a24 + 0x28) == 0)) &&
     ((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)))) {
    iVar3 = *(int *)(param_1 + 0x1c);
    iVar1 = __ltd(*(undefined4 *)(iVar3 + 0xb38),*(undefined4 *)(iVar3 + 0xb3c),0x9999999a,
                  0x3fd99999);
    if ((iVar1 == 0) && (*(int *)(param_1 + 0x50) == 0)) {
      if (*(int *)(param_1 + 0x24) == 0) {
        iVar1 = *(int *)(param_1 + 0x1c);
        __litodp(*(undefined4 *)(iVar1 + 0xb50));
        __litodp(*(undefined4 *)(iVar1 + 0xb54));
        lVar7 = FUN_0001b308();
      }
      else {
        uVar4 = __litodp(*(undefined4 *)(iVar3 + 0xb50));
        uVar5 = __litodp(*(undefined4 *)(iVar3 + 0xb54));
        uVar6 = __litodp(*(undefined4 *)(iVar3 + 0xb58));
        lVar7 = FUN_0001b1f8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                             (int)((ulonglong)uVar5 >> 0x20),(int)uVar4,
                             (int)((ulonglong)uVar4 >> 0x20));
      }
      uVar2 = __dptoli((int)lVar7,(int)((ulonglong)lVar7 >> 0x20));
      *(undefined4 *)(iVar3 + 0xb5c) = uVar2;
    }
  }
  return;
}



/* 0001bf10 FUN_0001bf10 */

/* Boundary evidence: original MIPS .pdata 0001bf10..0001c02f. Semantic name remains unreviewed. */

void FUN_0001bf10(int param_1)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  iVar2 = *(int *)(param_1 + 0x5c);
  uVar1 = 0xbff0000000000000;
  uVar5 = uVar1;
  if ((iVar2 < 0x65) && (iVar2 != 0)) {
    if (iVar2 < DAT_00062cb0) {
      DAT_00062cb0 = iVar2;
    }
  }
  else {
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = DAT_00062cb0;
    }
    uVar5 = 0xbff0000000000000;
    if (((-1 < iVar3) && (uVar5 = 0xbff0000000000000, iVar3 < 0x65)) &&
       (iVar2 = __ged(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb38),
                      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb3c),0x9999999a,0x3fd99999),
       uVar5 = 0xbff0000000000000, iVar2 != 0)) {
      lVar4 = FUN_0001b0cc();
      iVar2 = __dptoli((int)lVar4,(int)((ulonglong)lVar4 >> 0x20));
      uVar5 = 0xbff0000000000000;
      if ((-1 < iVar2) && (uVar5 = uVar1, 0 < *(int *)(param_1 + 0x40))) {
        uVar5 = __litodp(iVar2);
      }
    }
    DAT_00062cb0 = 0x65;
  }
  iVar2 = __dptoli((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  if (-1 < iVar2) {
    *(int *)(*(int *)(param_1 + 0x1c) + 0xb58) = iVar2;
  }
  return;
}



/* 0001c030 FUN_0001c030 */

/* Boundary evidence: original MIPS .pdata 0001c030..0001c0b3. Semantic name remains unreviewed. */

void FUN_0001c030(int param_1,int param_2,undefined1 param_3)

{
  undefined1 local_18 [8];
  
  if (param_2 == 0xcb) {
    FUN_0001b3ac(param_1);
    local_18[0] = param_3;
    FUN_00015158(DAT_000648e4,1,1,0xc,(int)local_18,1,100);
    SetTimer(*(HWND *)(param_1 + 4),0x70b,0x5dc,(TIMERPROC)0x0);
  }
  return;
}



/* 0001c0b4 FUN_0001c0b4 */

/* Boundary evidence: original MIPS .pdata 0001c0b4..0001c17f. Semantic name remains unreviewed. */

void FUN_0001c0b4(int param_1)

{
  DWORD DVar1;
  uint uVar2;
  uint uVar3;
  
  DVar1 = GetTickCount();
  uVar2 = (DVar1 - *(int *)(param_1 + 0x18)) / 1000 + *(int *)(param_1 + 0x68);
  uVar3 = uVar2 / 0x15180;
  if (uVar3 != 0) {
    DVar1 = GetTickCount();
    uVar2 = 0;
    *(DWORD *)(param_1 + 0x18) = DVar1;
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(uint *)(param_1 + 100) = *(int *)(param_1 + 100) + uVar3;
  }
  *(uint *)(*(int *)(param_1 + 0x1c) + 0xb20) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb24) = *(undefined4 *)(param_1 + 100);
  return;
}



/* 0001c180 FUN_0001c180 */

/* Boundary evidence: original MIPS .pdata 0001c180..0001c333. Semantic name remains unreviewed. */

void FUN_0001c180(int param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  int iVar2;
  DWORD aDStack_70 [2];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  hFile = CreateFileW(L"\\Storage Card2\\DriveInfo.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                      0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    local_68 = 0;
    memset(&local_64,0,0x54);
    BVar1 = ReadFile(hFile,&local_68,0x58,aDStack_70,(LPOVERLAPPED)0x0);
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 0x68) = local_68;
      *(undefined4 *)(param_1 + 100) = local_64;
      FUN_0001c0b4(param_1);
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(iVar2 + 0xb60) = local_60;
      DAT_00064948 = local_60;
      DAT_0006494c = local_5c;
      *(undefined4 *)(iVar2 + 0xb64) = local_5c;
      DAT_00064950 = local_58;
      DAT_00064958 = local_50;
      DAT_00064954 = local_54;
      DAT_00064960 = local_48;
      DAT_00064968 = local_40;
      DAT_0006495c = local_4c;
      DAT_00064964 = local_44;
      DAT_00064970 = local_38;
      DAT_0006496c = local_3c;
      DAT_00064978 = local_30;
      DAT_00064974 = local_34;
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(iVar2 + 0xb18) = local_28;
      *(undefined4 *)(iVar2 + 0xb1c) = local_24;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb5c) = local_20;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb58) = local_1c;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb50) = local_18;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb54) = local_14;
    }
    NKDbgPrintfW(L"read dwDay : %d  dwTime : %d \r\n",local_64,local_68);
  }
  CloseHandle(hFile);
  return;
}



/* 0001c334 FUN_0001c334 */

/* Boundary evidence: original MIPS .pdata 0001c334..0001c51f. Semantic name remains unreviewed. */

void FUN_0001c334(int param_1)

{
  DWORD DVar1;
  HANDLE hFile;
  BOOL BVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  DWORD aDStack_78 [2];
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar7 = *(undefined4 *)(param_1 + 100);
  DVar1 = GetTickCount();
  iVar4 = *(int *)(param_1 + 0x18);
  iVar5 = *(int *)(param_1 + 0x68);
  hFile = CreateFileW(L"\\Storage Card2\\DriveInfo.cfg",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                      0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    memset(&local_6c,0,0x54);
    local_68 = DAT_00064948;
    local_60 = DAT_00064950;
    local_5c = DAT_00064954;
    local_64 = DAT_0006494c;
    local_58 = DAT_00064958;
    local_50 = DAT_00064960;
    local_4c = DAT_00064964;
    local_54 = DAT_0006495c;
    local_48 = DAT_00064968;
    local_40 = DAT_00064970;
    iVar6 = *(int *)(param_1 + 0x1c);
    local_3c = DAT_00064974;
    local_44 = DAT_0006496c;
    local_38 = DAT_00064978;
    local_30 = *(undefined4 *)(iVar6 + 0xb18);
    local_2c = *(undefined4 *)(iVar6 + 0xb1c);
    local_28 = *(undefined4 *)(iVar6 + 0xb5c);
    if (*(int *)(param_1 + 0x24) == 0) {
      local_24 = 100;
    }
    else {
      local_24 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb58);
    }
    local_20 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb50);
    local_1c = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xb54);
    local_70 = (DVar1 - iVar4) / 1000 + iVar5;
    local_6c = uVar7;
    BVar2 = WriteFile(hFile,&local_70,0x58,aDStack_78,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      pwVar3 = L"write DRIVE_INFO_FILE_PATH FAIL \r\n";
    }
    else {
      pwVar3 = L"write DRIVE_INFO_FILE_PATH SUCCESS \r\n";
    }
    NKDbgPrintfW(pwVar3);
    NKDbgPrintfW(L"write dwDay : %d  dwTime : %d \r\n",local_6c,local_70);
  }
  CloseHandle(hFile);
  return;
}



/* 0001c520 FUN_0001c520 */

/* Boundary evidence: original MIPS .pdata 0001c520..0001c567. Semantic name remains unreviewed. */

void FUN_0001c520(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x20) != param_2) {
    *(int *)(param_1 + 0x20) = param_2;
    if (param_2 == 0) {
      FUN_0003006c(param_1);
    }
    else {
      *(undefined4 *)(param_1 + 8) = 100;
      FUN_00030044(param_1,100);
    }
  }
  return;
}



/* 0001c568 FUN_0001c568 */

undefined4 FUN_0001c568(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



/* 0001c570 FUN_0001c570 */

/* Boundary evidence: original MIPS .pdata 0001c570..0001c5ab. Semantic name remains unreviewed. */

void FUN_0001c570(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    FUN_00036de8(0xcb,0);
    NKDbgPrintfW(L"[MicomMgr]send IDM_MMCM_AMAIN_ECO_CLUSTER_RESET_DONE message!!! \r\n");
  }
  return;
}



/* 0001c5ac FUN_0001c5ac */

/* Boundary evidence: original MIPS .pdata 0001c5ac..0001c7d3. Semantic name remains unreviewed. */

void FUN_0001c5ac(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 local_28 [8];
  
  if (param_2 == (byte *)0x0) {
    return;
  }
  bVar1 = *param_2;
  uVar7 = bVar1 >> 2 & 3;
  uVar3 = bVar1 >> 4 & 7;
  uVar2 = (bVar1 & 3) << 8 | (uint)param_2[1];
  uVar4 = (uint)CONCAT11(param_2[2],param_2[3]) << 1 | (uint)(param_2[4] >> 7);
  uVar5 = (param_2[4] & 0x7f) << 8 | (uint)param_2[5];
  uVar6 = (uint)(param_2[7] >> 4) | (uint)param_2[6] << 4;
  if (DAT_000649c0 == 0) {
    DAT_000649c0 = 1;
    if ((((uVar6 == 0xffe) && (uVar2 == 0x3fe)) && (uVar4 == 0)) && (uVar5 == 0)) {
      FUN_0001b3ac(param_1);
      *(undefined4 *)(param_1 + 0x50) = 0;
      goto LAB_0001c734;
    }
    if (*(uint *)(param_1 + 0x38) != uVar3) {
      *(uint *)(param_1 + 0x38) = uVar3;
      *(uint *)(*(int *)(param_1 + 0x1c) + 0xb28) = uVar3;
    }
    if (*(uint *)(param_1 + 0x3c) != uVar7) {
      *(uint *)(param_1 + 0x3c) = uVar7;
      *(uint *)(*(int *)(param_1 + 0x1c) + 0xb2c) = uVar7;
    }
  }
  else {
    if (*(int *)(param_1 + 0x50) != 0) goto LAB_0001c734;
    if (*(uint *)(param_1 + 0x38) != uVar3) {
      *(uint *)(param_1 + 0x38) = uVar3;
      *(uint *)(*(int *)(param_1 + 0x1c) + 0xb28) = uVar3;
    }
    if (*(uint *)(param_1 + 0x3c) != uVar7) {
      *(uint *)(param_1 + 0x3c) = uVar7;
      *(uint *)(*(int *)(param_1 + 0x1c) + 0xb2c) = uVar7;
    }
  }
  FUN_0001b644(param_1,uVar2);
  FUN_0001b6fc(param_1,uVar4);
  FUN_0001b7a0(param_1,uVar5);
  FUN_0001b8bc(param_1,uVar6);
LAB_0001c734:
  if ((char)bVar1 < '\0') {
    FUN_0001b3ac(param_1);
    FUN_00036de8(0xca,0);
    local_28[0] = 0;
    FUN_00015158(DAT_000648e4,1,1,0xc,(int)local_28,1,100);
  }
  else if (*(int *)(param_1 + 0x50) != 0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    FUN_00036de8(0xcb,0);
    NKDbgPrintfW(L"[MicomMgr]send IDM_MMCM_AMAIN_ECO_CLUSTER_RESET_DONE message!!! \r\n");
  }
  return;
}



/* 0001c7d4 FUN_0001c7d4 */

/* Boundary evidence: original MIPS .pdata 0001c7d4..0001c89b. Semantic name remains unreviewed. */

void FUN_0001c7d4(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x28) = param_2;
  if (param_2 == 0) {
    FUN_00015158(DAT_000648e4,1,1,0xb,0,0,100);
  }
  else {
    *(undefined4 *)(param_1 + 0x5c) = 0x65;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0xb38) = 0;
    *(undefined4 *)(iVar1 + 0xb3c) = 0;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0xb40) = 0;
    *(undefined4 *)(iVar1 + 0xb44) = 0;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0xb30) = 0xcccccccd;
    *(undefined4 *)(iVar1 + 0xb34) = 0x40598ccc;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0xb48) = 0x66666666;
    *(undefined4 *)(iVar1 + 0xb4c) = 0x40799666;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0x3fe;
    *(undefined4 *)(param_1 + 0x4c) = 0xffe;
    *(undefined4 *)(param_1 + 0x60) = 0;
    FUN_0001b5a4(param_1,0);
  }
  return;
}



/* 0001c89c FUN_0001c89c */

/* Boundary evidence: original MIPS .pdata 0001c89c..0001c9e7. Semantic name remains unreviewed. */

undefined4 * FUN_0001c89c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  DWORD DVar1;
  int iVar2;
  
  FUN_00030010(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_00051608;
  param_1[7] = param_4;
  param_1[0x10] = 0x3fe;
  param_1[0x13] = 0xffe;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x14] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(undefined4 *)(param_4 + 0xb18) = 0;
  *(undefined4 *)(param_4 + 0xb1c) = 0;
  iVar2 = param_1[7];
  *(undefined4 *)(iVar2 + 0xb60) = 0;
  *(undefined4 *)(iVar2 + 0xb64) = 0;
  *(undefined4 *)(param_1[7] + 0xb50) = 100;
  *(undefined4 *)(param_1[7] + 0xb54) = 100;
  *(undefined4 *)(param_1[7] + 0xb58) = 100;
  *(undefined4 *)(param_1[7] + 0xb5c) = 0x65;
  iVar2 = param_1[7];
  *(undefined4 *)(iVar2 + 0xb30) = 0xcccccccd;
  *(undefined4 *)(iVar2 + 0xb34) = 0x40598ccc;
  iVar2 = param_1[7];
  *(undefined4 *)(iVar2 + 0xb48) = 0x66666666;
  *(undefined4 *)(iVar2 + 0xb4c) = 0x40799666;
  *(undefined4 *)(param_1[7] + 0xb28) = param_1[0xe];
  *(undefined4 *)(param_1[7] + 0xb2c) = param_1[0xf];
  DVar1 = GetTickCount();
  param_1[6] = DVar1;
  FUN_0001c180((int)param_1);
  param_1[0x17] = 0x65;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  return param_1;
}



/* 0001c9e8 FUN_0001c9e8 */

/* Boundary evidence: original MIPS .pdata 0001c9e8..0001ca3f. Semantic name remains unreviewed. */

undefined4 * FUN_0001c9e8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00051608;
  FUN_0003008c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001ca40 FUN_0001ca40 */

/* Boundary evidence: original MIPS .pdata 0001ca40..0001cac7. Semantic name remains unreviewed. */

void FUN_0001ca40(int param_1)

{
  int iVar1;
  
  iVar1 = __led(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,0);
  if ((((iVar1 == 0) && (*(int *)(DAT_00064a24 + 0x14) == 0)) &&
      (*(int *)(DAT_00064a24 + 0x28) == 0)) &&
     (((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)) &&
      (*(int *)(param_1 + 0x24) != 0)))) {
    FUN_0001bf10(param_1);
  }
  return;
}



/* 0001cac8 FUN_0001cac8 */

/* Boundary evidence: original MIPS .pdata 0001cac8..0001cb3b. Semantic name remains unreviewed. */

void FUN_0001cac8(int param_1)

{
  if ((99 < *(uint *)(param_1 + 8)) && (*(uint *)(param_1 + 8) < 0x66)) {
    if (DAT_000649c0 != 0) {
      FUN_0001bb84(param_1);
    }
    FUN_0001c0b4(param_1);
    FUN_0001ba7c(param_1);
    FUN_0001b974(param_1);
    FUN_0001bda4(param_1);
  }
  return;
}



/* 0001cb3c FUN_0001cb3c */

/* Boundary evidence: original MIPS .pdata 0001cb3c..0001cc13. Semantic name remains unreviewed. */

void FUN_0001cb3c(int param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  if ((*(int *)(param_1 + 0x50) == 0) && (*(int *)(param_1 + 0x20) != 0)) {
    bVar1 = *param_2;
    bVar2 = param_2[1];
    bVar3 = param_2[2];
    if (*(uint *)(param_1 + 0x60) != (uint)param_2[3]) {
      *(uint *)(param_1 + 0x60) = (uint)param_2[3];
    }
    if (*(uint *)(param_1 + 0x54) != (uint)(bVar1 >> 1)) {
      *(uint *)(param_1 + 0x54) = (uint)(bVar1 >> 1);
    }
    if (*(uint *)(param_1 + 0x58) != (uint)(bVar2 >> 1)) {
      *(uint *)(param_1 + 0x58) = (uint)(bVar2 >> 1);
    }
    if (*(uint *)(param_1 + 0x5c) != (uint)(bVar3 >> 1)) {
      *(uint *)(param_1 + 0x5c) = (uint)(bVar3 >> 1);
      FUN_0001ca40(param_1);
      DAT_00064a10 = DAT_00064a10 + 1;
    }
    if (DAT_000649bc == 0) {
      DAT_000649bc = 1;
      *(undefined4 *)(param_1 + 8) = 0x65;
      FUN_00030044(param_1,100);
    }
  }
  return;
}



/* 0001cc14 FUN_0001cc14 */

/* Boundary evidence: original MIPS .pdata 0001cc14..0001ce37. Semantic name remains unreviewed. */

void FUN_0001cc14(int param_1,uint *param_2)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  byte local_58;
  undefined1 auStack_57 [7];
  undefined4 local_50;
  byte local_48;
  undefined1 auStack_47 [7];
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 auStack_36 [6];
  undefined1 local_30;
  undefined1 local_2f [6];
  undefined4 local_29;
  undefined4 local_25;
  undefined4 local_21;
  uint local_14;
  
  local_14 = DAT_00064820;
  if ((*(char *)(*(int *)(param_1 + 0x1c) + 0xb07) == '\0') && ((*param_2 & 0xf00) == 0x200)) {
    cVar1 = *(char *)((int)param_2 + 2);
    if (cVar1 == 'e') {
      local_38 = 0;
      memset(&local_37,0,1);
      memset(auStack_36,0,3);
      memcpy(&local_38,param_2 + 1,(uint)*(byte *)((int)param_2 + 3));
      if (*(int *)(param_1 + 0x50) == 0) {
        FUN_0001b5a4(param_1,(uint)CONCAT11(local_38,local_37));
      }
    }
    else if (cVar1 == 'g') {
      local_48 = 0;
      memset(auStack_47,0,7);
      memcpy(&local_48,param_2 + 1,(uint)*(byte *)((int)param_2 + 3));
      FUN_0001c5ac(param_1,&local_48);
    }
    else {
      if (cVar1 == 'h') {
        local_58 = 0;
        memset(auStack_57,0,4);
        memcpy(&local_58,param_2 + 1,(uint)*(byte *)((int)param_2 + 3));
        pbVar3 = &local_58;
      }
      else {
        if ((cVar1 != 'j') || (bVar2 = *(byte *)((int)param_2 + 3), bVar2 == 0)) goto LAB_0001ce18;
        local_30 = 0;
        memset(local_2f,0,0x1a);
        memcpy(&local_30,param_2 + 1,(uint)bVar2);
        if (*(int *)(param_1 + 0x50) == 0) {
          FUN_0001b5a4(param_1,(uint)CONCAT11(local_30,local_2f[0]));
        }
        local_40 = local_29;
        local_3c = local_25;
        FUN_0001c5ac(param_1,(byte *)&local_40);
        memset((void *)((int)&local_50 + 1),0,4);
        local_50 = local_21;
        pbVar3 = (byte *)&local_50;
      }
      FUN_0001cb3c(param_1,pbVar3);
    }
  }
LAB_0001ce18:
  FUN_0004a3f4(local_14);
  return;
}



/* 0001ce38 FUN_0001ce38 */

int FUN_0001ce38(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0x30) || (0x39 < param_2)) {
    if ((param_2 < 0x41) || (0x46 < param_2)) {
      if ((param_2 < 0x61) || (iVar1 = param_2 + -0x37, 0x66 < param_2)) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = param_2 + -0x37;
    }
  }
  else {
    iVar1 = param_2 + -0x30;
  }
  return iVar1;
}



/* 0001cea0 FUN_0001cea0 */

/* Boundary evidence: original MIPS .pdata 0001cea0..0001cf8b. Semantic name remains unreviewed. */

BOOL FUN_0001cea0(LPCWSTR param_1,LPWSTR param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  _PROCESS_INFORMATION local_20;
  
  memset(&local_20,0,0x10);
  BVar1 = CreateProcessW(param_1,param_2,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,
                         (LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,&local_20);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"\r\n[%s(%d) - %s] %s did not excute!!, err code = 0x%08X \r\n",".\\Micom.cpp",
                 0x145,"DoExcuteApplication",param_1,DVar2);
  }
  else {
    if (local_20.hProcess != (HANDLE)0x0) {
      CloseHandle(local_20.hProcess);
    }
    if (local_20.hThread != (HANDLE)0x0) {
      CloseHandle(local_20.hThread);
    }
  }
  return BVar1;
}



/* 0001cf8c FUN_0001cf8c */

/* Boundary evidence: original MIPS .pdata 0001cf8c..0001d037. Semantic name remains unreviewed. */

void FUN_0001cf8c(int param_1,int param_2)

{
  int iVar1;
  bool local_18 [8];
  
  NKDbgPrintfW(L"\r\n[INFO] CMicom::ChangeClockMode() [%d -> %d]\r\n",
               *(undefined4 *)(param_1 + 0x8c),param_2);
  if (*(int *)(param_1 + 0x8c) != param_2) {
    *(int *)(param_1 + 0x8c) = param_2;
    local_18[0] = param_2 == 1;
    iVar1 = FUN_00015158(DAT_000648e4,1,1,1,(int)local_18,1,100);
    if (iVar1 == 0) {
      NKDbgPrintfW(L"\r\n[ERROR] CMicom::ChangeClockMode() failed[%d(%d)]\r\n",
                   *(undefined4 *)(param_1 + 0x8c),local_18[0]);
    }
  }
  return;
}



/* 0001d038 FUN_0001d038 */

/* Boundary evidence: original MIPS .pdata 0001d038..0001d15b. Semantic name remains unreviewed. */

void FUN_0001d038(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD aDStack_18 [2];
  
  DVar2 = 2;
  if (*(char *)(param_3 + 6) != '\0') {
    DVar2 = 3;
  }
  hFile = CreateFileW(param_2,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,DVar2,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"File open error - %s\r\n",param_2);
  }
  else {
    if (*(char *)(param_3 + 6) != '\0') {
      SetFilePointer(hFile,0,(PLONG)0x0,2);
    }
    BVar1 = WriteFile(hFile,(LPCVOID)(param_3 + 8),*(byte *)(param_3 + 4) - 3,aDStack_18,
                      (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      NKDbgPrintfW(L"Write Error - %s [err=%d]\r\n",param_2,DVar2);
    }
    CloseHandle(hFile);
  }
  return;
}



/* 0001d15c FUN_0001d15c */

/* Boundary evidence: original MIPS .pdata 0001d15c..0001d3bf. Semantic name remains unreviewed. */

void FUN_0001d15c(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  byte *_Dst;
  HANDLE hFile;
  BOOL BVar1;
  HANDLE hFile_00;
  DWORD DVar2;
  LPCWSTR pWVar3;
  wchar_t *pwVar4;
  uint nNumberOfBytesToWrite;
  DWORD local_30;
  DWORD DStack_2c;
  
  _Dst = malloc(0x9cc);
  if (_Dst == (byte *)0x0) {
    NKDbgPrintfW(L"[EC bsd write] Memory allocation Fileure for %s!!\n",param_2);
    return;
  }
  memset(_Dst,0,0x9cc);
  hFile = CreateFileW(param_2,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) goto LAB_0001d370;
  BVar1 = ReadFile(hFile,_Dst,0x9c4,&local_30,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    pWVar3 = (LPCWSTR)GetLastError();
    pwVar4 = L"Read Error - %s [err=%d]\n";
    param_3 = param_2;
LAB_0001d35c:
    NKDbgPrintfW(pwVar4,param_3,pWVar3);
  }
  else {
    nNumberOfBytesToWrite = (uint)*_Dst * 0x100 + (uint)_Dst[1];
    if (0x9c2 < nNumberOfBytesToWrite) {
      pwVar4 = L"Cancel to write - %s because data in %s are initailized..\n";
      pWVar3 = param_2;
      goto LAB_0001d35c;
    }
    if (nNumberOfBytesToWrite == 0) {
      NKDbgPrintfW(L"Cancel to write - Wrong size(size=0) in first word of %s..\n",param_2);
    }
    else {
      hFile_00 = CreateFileW(param_3,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
      if (hFile_00 == (HANDLE)0xffffffff) {
        pWVar3 = (LPCWSTR)GetLastError();
        pwVar4 = L"File open error - %s [err=%d]\n";
        goto LAB_0001d35c;
      }
      NKDbgPrintfW(L"MOVE to %s(packet Sz=%d, FileSz=%d)\n",param_3,nNumberOfBytesToWrite,local_30);
      BVar1 = WriteFile(hFile_00,_Dst + 2,nNumberOfBytesToWrite,&DStack_2c,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        DVar2 = GetLastError();
        NKDbgPrintfW(L"Write Error - %s (err=%d)\n",param_3,DVar2);
      }
      CloseHandle(hFile_00);
    }
  }
  CloseHandle(hFile);
LAB_0001d370:
  free(_Dst);
  return;
}



/* 0001d3c0 FUN_0001d3c0 */

/* Boundary evidence: original MIPS .pdata 0001d3c0..0001d597. Semantic name remains unreviewed. */

void FUN_0001d3c0(undefined4 param_1,LPCWSTR param_2)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_670;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00064820;
  NKDbgPrintfW(L"[Micom Manager] [INFO] DoDeleteFile() [%s]\r\n",param_2);
  memset(awStack_238,0,0x104);
  swprintf_s(awStack_238,0x103,L"%s\\*.*",param_2);
  hFindFile = FindFirstFileW(awStack_238,&local_670);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if ((local_670.dwFileAttributes & 0x10) == 0) {
        swprintf_s(local_670.cFileName + 0x102,0x104,L"%s\\%s",param_2,&local_670.dwReserved1);
        DeleteFileW(local_670.cFileName + 0x102);
      }
      else {
        iVar1 = wcscmp((wchar_t *)&local_670.dwReserved1,L".");
        if ((iVar1 != 0) && (iVar1 = wcscmp((wchar_t *)&local_670.dwReserved1,L".."), iVar1 != 0)) {
          memset(local_670.cFileName + 0x102,0,0x104);
          swprintf_s(local_670.cFileName + 0x102,0x103,L"%s\\%s\\",param_2,&local_670.dwReserved1);
          FUN_0001d3c0(param_1,local_670.cFileName + 0x102);
        }
      }
      BVar2 = FindNextFileW(hFindFile,&local_670);
    } while (BVar2 != 0);
    FindClose(hFindFile);
  }
  RemoveDirectoryW(param_2);
  FUN_0004a3f4(local_30);
  return;
}



/* 0001d598 FUN_0001d598 */

/* Boundary evidence: original MIPS .pdata 0001d598..0001d74f. Semantic name remains unreviewed. */

void FUN_0001d598(void)

{
  HANDLE hFindFile;
  wchar_t *pwVar1;
  DWORD DVar2;
  BOOL BVar3;
  WCHAR *pWVar4;
  _WIN32_FIND_DATAW local_670;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00064820;
  memset(awStack_238,0,0x104);
  swprintf_s(awStack_238,0x103,L"%s\\*.*",L"\\Storage Card4\\NNG\\content\\userdata\\POI");
  hFindFile = FindFirstFileW(awStack_238,&local_670);
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      if ((local_670.dwFileAttributes & 0x10) == 0) {
        pwVar1 = wcsstr((wchar_t *)&local_670.dwReserved1,L".zip");
        if (pwVar1 == (wchar_t *)0x0) {
          swprintf_s(local_670.cFileName + 0x102,0x104,L"%s\\%s",
                     L"\\Storage Card4\\NNG\\content\\userdata\\POI",&local_670.dwReserved1);
          BVar3 = DeleteFileW(local_670.cFileName + 0x102);
          if (BVar3 != 0) {
            pWVar4 = local_670.cFileName + 0x102;
            pwVar1 = L"[Micom Manager] [INFO] DeleteBrandPOIFile(%s) \r\n";
            goto LAB_0001d6e8;
          }
          DVar2 = GetLastError();
          NKDbgPrintfW(L"[Info] DeleteBrandPOIFile() - error DeleteFile : [%s][0x%08X]\r\n",
                       local_670.cFileName + 0x102,DVar2);
        }
      }
      else {
        pWVar4 = (WCHAR *)&local_670.dwReserved1;
        pwVar1 = L"DeleteBrandPOIFile() - Directory : [%s]\r\n";
LAB_0001d6e8:
        NKDbgPrintfW(pwVar1,pWVar4);
      }
      BVar3 = FindNextFileW(hFindFile,&local_670);
    } while (BVar3 != 0);
    FindClose(hFindFile);
  }
  FUN_0004a3f4(local_30);
  return;
}



/* 0001d750 FUN_0001d750 */

/* Boundary evidence: original MIPS .pdata 0001d750..0001d91b. Semantic name remains unreviewed. */

void FUN_0001d750(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  uint uVar5;
  undefined1 auStack_420 [1024];
  uint local_20;
  uint uVar4;
  
  local_20 = DAT_00064820;
  if (*(int *)(param_1 + 0x18) != 1) goto LAB_0001d8f8;
  Sleep(0x32);
  if (param_2 == 0x21) {
    NKDbgPrintfW(L"CMicom:OnRequest - checksum fail : %d, %d\r\n",*(undefined4 *)(param_1 + 0x1c),
                 0x21);
    iVar2 = *(int *)(param_1 + 0x1c);
LAB_0001d7f4:
    *(int *)(param_1 + 0x1c) = iVar2 + -1;
  }
  else if (param_2 == 0x22) {
    NKDbgPrintfW(L"CMicom:OnRequest - flash write fail : %d, %d\r\n",*(undefined4 *)(param_1 + 0x1c)
                 ,0x22);
    iVar2 = *(int *)(param_1 + 0x1c);
    goto LAB_0001d7f4;
  }
  if (*(int **)(param_1 + 0x20) == (int *)0x0) {
    memset(auStack_420,0,0x400);
    FUN_000283b0((undefined4 *)&DAT_00064b44,1,'\b',auStack_420);
    goto LAB_0001d8f8;
  }
  uVar5 = *(int *)(param_1 + 0x1c) + 0xffU & 0xff;
  if (0xde < uVar5) {
    uVar5 = 0xdf;
  }
  iVar2 = **(int **)(param_1 + 0x20);
  FUN_00019f4c(DAT_000648ec,(uint)(*(int *)(param_1 + 0x1c) * 100) / 0xe0);
  if (uVar5 < 8) {
    uVar4 = uVar5 + 8 & 0xff;
LAB_0001d8d0:
    cVar3 = (char)uVar4;
    bVar1 = 0;
  }
  else {
    cVar3 = (char)uVar5;
    uVar4 = uVar5;
    if (uVar5 < 0xdf) goto LAB_0001d8d0;
    bVar1 = 4;
  }
  FUN_000283b0((undefined4 *)&DAT_00064b44,bVar1,cVar3,(LPCVOID)(uVar5 * 0x400 + iVar2));
  iVar2 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x1c) = iVar2 + 1;
  if (uVar5 == 7) {
    *(int *)(param_1 + 0x1c) = iVar2 + 9;
  }
LAB_0001d8f8:
  FUN_0004a3f4(local_20);
  return;
}



/* 0001d91c FUN_0001d91c */

/* Boundary evidence: original MIPS .pdata 0001d91c..0001dbaf. Semantic name remains unreviewed. */

void FUN_0001d91c(int param_1)

{
  HWND hWnd;
  int iVar1;
  
  hWnd = FindWindowW((LPCWSTR)0x0,L"MgrDab");
  FUN_0002fec8(DAT_000673c8);
  NKDbgPrintfW(L"\n\n[**UpdatePwrState** %d]  m_bIsAccOff-%d, m_bIsPowerOff-%d, m_bIsLowVoltage-%d, m_bIsLocked-%d\n\n"
               ,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
               *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
               *(undefined4 *)(param_1 + 0x3c));
  if ((((*(int *)(param_1 + 0x28) == 1) || (*(int *)(param_1 + 0x2c) == 1)) ||
      (*(int *)(param_1 + 0x30) == 1)) || (*(int *)(param_1 + 0x3c) == 1)) {
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb08) = 1;
    if (*(int *)(param_1 + 0x2c) == 0) {
      FUN_00036e44(0x71,0);
    }
    FUN_00036f08(0x3030104,0);
    if (hWnd != (HWND)0x0) {
      PostMessageW(hWnd,0x8064,0x700300,1);
    }
    FUN_000161f8(DAT_000648ec);
    return;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 1) {
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb08) = 0;
    if (*(int *)(param_1 + 0x14) == 1) {
      FUN_000160b8(DAT_000648ec);
    }
    else {
      FUN_00016024(DAT_000648ec);
    }
    if (*(int *)(param_1 + 0x4c) == 1) {
      NKDbgPrintfW(L"\r\n~(7)~%s~ PWRSTATE_NORMAL unmuted\r\n","CMicom::UpdatePwrState");
      return;
    }
    Sleep(100);
    FUN_00036f08(0x3030105,0);
    if (hWnd != (HWND)0x0) {
      PostMessageW(hWnd,0x8064,0x700300,0);
    }
    FUN_00036e44(0x72,0);
    iVar1 = 0;
  }
  else {
    if (iVar1 == 2) {
      FUN_00016024(DAT_000648ec);
      FUN_00036e44(0x72,0);
      FUN_0001cf8c(param_1,0);
      FUN_00049c34(*(undefined4 *)(param_1 + 4));
      return;
    }
    if (iVar1 != 3) {
      return;
    }
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb08) = 1;
    FUN_00036e44(0x71,0);
    FUN_00036f08(0x3030104,0);
    if (hWnd != (HWND)0x0) {
      PostMessageW(hWnd,0x8064,0x700300,1);
    }
    if (*(int *)(param_1 + 0x14) == 1) {
      FUN_000160b8(DAT_000648ec);
    }
    else {
      FUN_0001a7a0(DAT_000648ec);
    }
    iVar1 = 1;
  }
  FUN_0001cf8c(param_1,iVar1);
  return;
}



/* 0001dbb0 FUN_0001dbb0 */

/* Boundary evidence: original MIPS .pdata 0001dbb0..0001ddc7. Semantic name remains unreviewed. */

void FUN_0001dbb0(void)

{
  HANDLE pvVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD local_38;
  int local_34;
  int local_30 [2];
  
  local_34 = 0;
  local_38 = 0;
  pvVar1 = CreateFileW(L"\\Storage card2\\pwr_count.bin",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    DVar3 = GetLastError();
    NKDbgPrintfW(L"[%S][%s] file read open error[0x%08X] \r\n","SavePwrCount",
                 L"\\Storage card2\\pwr_count.bin",DVar3);
  }
  else {
    BVar2 = ReadFile(pvVar1,local_30,4,&local_38,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[%S][%s] file read error [%d][0x%08X]\r\n","SavePwrCount",
                   L"\\Storage card2\\pwr_count.bin",local_38,DVar3);
    }
    else {
      local_34 = local_30[0] + 1;
    }
    CloseHandle(pvVar1);
  }
  pvVar1 = CreateFileW(L"\\Storage card2\\pwr_count.bin",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                       0x80,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    DVar3 = GetLastError();
    NKDbgPrintfW(L"[%S][%s] file write open error [0x%08X]\r\n","SavePwrCount",
                 L"\\Storage card2\\pwr_count.bin",DVar3);
  }
  else {
    BVar2 = WriteFile(pvVar1,&local_34,4,&local_38,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[%S][%s] file write error [%d][0x%08X]\r\n","SavePwrCount",
                   L"\\Storage card2\\pwr_count.bin",local_38,DVar3);
    }
    CloseHandle(pvVar1);
  }
  return;
}



/* 0001ddc8 FUN_0001ddc8 */

undefined4 FUN_0001ddc8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(int *)(param_1 + 0x24) != 1) && (*(int *)(param_1 + 0x24) != 2)) ||
      (*(int *)(param_1 + 0x28) != 0)) ||
     ((*(int *)(param_1 + 0x3c) != 0 || (*(int *)(param_1 + 0x48) != 0)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 0001de14 FUN_0001de14 */

undefined4 FUN_0001de14(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(int *)(param_1 + 0x24) != 1) && (*(int *)(param_1 + 0x24) != 2)) ||
      (*(int *)(param_1 + 0x28) != 0)) || (*(int *)(param_1 + 0x3c) != 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 0001de54 FUN_0001de54 */

/* Boundary evidence: original MIPS .pdata 0001de54..0001df1b. Semantic name remains unreviewed. */

void FUN_0001de54(int param_1)

{
  if (*(int *)(param_1 + 0x54) == 2) {
    FUN_00015158(DAT_000648e4,7,1,2,
                 (int)(&UNK_000527bc +
                      (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0xafc) +
                      *(int *)(param_1 + 0x50) * 3),1,100);
  }
  else {
    FUN_00015158(DAT_000648e4,7,1,2,
                 (int)(&UNK_000527bc +
                      (uint)*(byte *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x54) + 0xafa) +
                      *(int *)(param_1 + 0x54) * 3),1,100);
  }
  return;
}



/* 0001df1c FUN_0001df1c */

bool FUN_0001df1c(int param_1)

{
  return *(int *)(param_1 + 0x24) == 2;
}



/* 0001df38 FUN_0001df38 */

/* Boundary evidence: original MIPS .pdata 0001df38..0001dfc3. Semantic name remains unreviewed. */

void FUN_0001df38(int param_1)

{
  BOOL BVar1;
  
  *(undefined4 *)(param_1 + 0x3c) = 1;
  FUN_0001d91c(param_1);
  FUN_0001cf8c(param_1,1);
  if ((*(int *)(param_1 + 0x70) == 0) &&
     (BVar1 = FUN_0001cea0(L"\\Storage Card\\system\\CodeChecker.exe",L"bd9r2a@_4G2g=J2tq7X@app"),
     BVar1 == 0)) {
    FUN_00016024(DAT_000648ec);
    MessageBoxW((HWND)0x0,L"CodeChecker.exe did not excute!!",L"Warning",0);
  }
  return;
}



/* 0001dfc4 FUN_0001dfc4 */

/* Boundary evidence: original MIPS .pdata 0001dfc4..0001e1d7. Semantic name remains unreviewed. */

void FUN_0001dfc4(int param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  UINT uElapse;
  undefined1 local_38;
  undefined1 local_37;
  int local_34;
  DWORD aDStack_30 [2];
  
  uElapse = 60000;
  local_34 = 0;
  if (*(int *)(param_1 + 0x58) == 1) {
    NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~already timer runing\r\n");
    return;
  }
  FUN_00015158(DAT_000648e4,5,1,0x41,0,0,100);
  hFile = CreateFileW(L"\\Storage Card2\\Antitheft.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                      0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) goto LAB_0001e14c;
  BVar1 = ReadFile(hFile,&local_34,4,aDStack_30,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~Read ERROR\r\n");
  }
  else if (local_34 != 0) {
    if (local_34 < 1) {
LAB_0001e124:
      uElapse = 0x1d4c00;
    }
    else if (local_34 < 4) {
      uElapse = 120000;
    }
    else if (local_34 == 4) {
      uElapse = 240000;
    }
    else if (local_34 == 5) {
      uElapse = 480000;
    }
    else {
      if (local_34 != 6) goto LAB_0001e124;
      uElapse = 960000;
    }
  }
  CloseHandle(hFile);
LAB_0001e14c:
  NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~ nCount : %d, timeout : %d\r\n",local_34,uElapse);
  *(undefined4 *)(param_1 + 0x58) = 1;
  SetTimer(*(HWND *)(param_1 + 4),2,uElapse,(TIMERPROC)0x0);
  local_38 = 0;
  local_37 = 0x14;
  FUN_00015158(DAT_000648e4,5,1,0x40,(int)&local_38,2,100);
  return;
}



/* 0001e1d8 FUN_0001e1d8 */

/* Boundary evidence: original MIPS .pdata 0001e1d8..0001e25b. Semantic name remains unreviewed. */

void FUN_0001e1d8(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x84);
  NKDbgPrintfW(L" --- Start CodeChecker code-%d, factory-%d, pwr_state-%d\r\n",uVar1 >> 2 & 1,
               uVar1 & 1,uVar1 >> 4 & 1);
  if ((*(ushort *)(param_1 + 0x84) & 4) == 0) {
    if ((*(ushort *)(param_1 + 0x84) & 1) == 0) {
      FUN_0001dfc4(param_1);
    }
    else {
      FUN_0001df38(param_1);
    }
  }
  return;
}



/* 0001e25c FUN_0001e25c */

/* Boundary evidence: original MIPS .pdata 0001e25c..0001e39b. Semantic name remains unreviewed. */

void FUN_0001e25c(undefined4 param_1,uint param_2,LPWSTR param_3,uint param_4)

{
  wchar_t *pwVar1;
  
  if (param_3 == (LPWSTR)0x0) {
    NKDbgPrintfW(L"[ERROR] Invalid buffer handle [0x%04X]!!!\r\n",param_2);
    return;
  }
  pwVar1 = L"NO MAP";
  if (DAT_000630a4 == 0) {
    NKDbgPrintfW(L"[ERROR]TransMapCode2RegKey() NOT MATCH [%d][0x%04X]!!!\r\n",0,param_2);
  }
  else {
    if (DAT_000630a4 != param_2) goto LAB_0001e344;
    if (2 < param_4) {
      wsprintfW(param_3,L"NO MAP");
      NKDbgPrintfW(L"[ERROR]TransMapCode2RegKey() Invalid CY [%d]!!!\r\n",param_4);
      goto LAB_0001e344;
    }
    pwVar1 = (wchar_t *)(&PTR_u_iATHM_13Q4_000630a8)[param_4];
  }
  wsprintfW(param_3,pwVar1);
LAB_0001e344:
  NKDbgPrintfW(L"TransMapCode2RegKey() [0x%04X][%s]!!!\r\n",param_2,param_3);
  return;
}



/* 0001e39c FUN_0001e39c */

/* Boundary evidence: original MIPS .pdata 0001e39c..0001e41f. Semantic name remains unreviewed. */

void FUN_0001e39c(void)

{
  DWORD DVar1;
  BOOL BVar2;
  
  DVar1 = GetFileAttributesW(L"\\Storage Card\\system\\ULC_DTC.tbl");
  if (DVar1 != 0xffffffff) {
    BVar2 = DeleteFileW(L"\\Storage Card\\system\\ULC_DTC.tbl");
    DVar1 = GetLastError();
    NKDbgPrintfW(L"[DeleteDTCTable %s] [%d][0x%08X] ULC_DTC_NAME is deleted!!!\n",
                 L"\\Storage Card\\system\\ULC_DTC.tbl",BVar2,DVar1);
  }
  return;
}



/* 0001e420 FUN_0001e420 */

/* Boundary evidence: original MIPS .pdata 0001e420..0001e513. Semantic name remains unreviewed. */

DWORD FUN_0001e420(undefined4 param_1,LPVOID param_2,DWORD param_3)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_20 [2];
  
  DVar2 = 0;
  if ((param_2 == (LPVOID)0x0) || (param_3 == 0)) {
    DVar2 = 0;
  }
  else {
    hFile = CreateFileW(L"\\Storage Card\\system\\ULC_DTC.tbl",0x80000000,0,
                        (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      BVar1 = ReadFile(hFile,param_2,param_3,local_20,(LPOVERLAPPED)0x0);
      DVar2 = local_20[0];
      if (BVar1 == 0) {
        NKDbgPrintfW(L"[LoadDTCvalue]Fail to read file - ULC_DTC.tbl\n");
        DVar2 = 0;
      }
      CloseHandle(hFile);
    }
  }
  return DVar2;
}



/* 0001e514 FUN_0001e514 */

bool FUN_0001e514(int param_1)

{
  return (*(ushort *)(param_1 + 0x84) & 4) == 0;
}



/* 0001e530 FUN_0001e530 */

/* Boundary evidence: original MIPS .pdata 0001e530..0001e573. Semantic name remains unreviewed. */

void FUN_0001e530(int param_1)

{
  if ((*(int *)(param_1 + 0x24) == 3) || (*(int *)(param_1 + 0x3c) == 1)) {
    FUN_00036f08(0x3030104,0);
  }
  return;
}



/* 0001e574 FUN_0001e574 */

/* Boundary evidence: original MIPS .pdata 0001e574..0001e5cb. Semantic name remains unreviewed. */

void FUN_0001e574(void)

{
  DWORD DVar1;
  _TIME_ZONE_INFORMATION _Stack_b8;
  uint local_c;
  
  local_c = DAT_00064820;
  DVar1 = GetTimeZoneInformation(&_Stack_b8);
  if (DVar1 != 0xffffffff) {
    memcpy(&DAT_00067fa8,&_Stack_b8,0xac);
  }
  FUN_0004a3f4(local_c);
  return;
}



/* 0001e5cc FUN_0001e5cc */

/* Boundary evidence: original MIPS .pdata 0001e5cc..0001e5e7. Semantic name remains unreviewed. */

void FUN_0001e5cc(int param_1)

{
  FUN_0001df38(param_1);
  return;
}



/* 0001e5e8 FUN_0001e5e8 */

/* Boundary evidence: original MIPS .pdata 0001e5e8..0001e697. Semantic name remains unreviewed. */

void FUN_0001e5e8(void)

{
  LSTATUS LVar1;
  HKEY local_10;
  int local_c;
  
  NKDbgPrintfW(L"~~~~~~~~~~~~\n\n[McmMgr] SetAutoTime()\r\n");
  FUN_0002453c(0);
  FUN_00024668(1);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_10);
  if (LVar1 == 0) {
    local_c = FUN_0002444c();
    RegSetValueExW(local_10,L"ManualTimeSet",0,4,(BYTE *)&local_c,4);
    RegCloseKey(local_10);
  }
  return;
}



/* 0001e698 FUN_0001e698 */

/* Boundary evidence: original MIPS .pdata 0001e698..0001e813. Semantic name remains unreviewed. */

void FUN_0001e698(int param_1)

{
  uint uVar1;
  byte local_18 [8];
  
  if (DAT_00064828 != 0) {
    FUN_0001221c(DAT_00064828,1);
  }
  if (((*(int *)(param_1 + 0x60) != 0) || (*(int *)(param_1 + 0x5c) != 0)) ||
     (*(int *)(param_1 + 100) != 0)) {
    local_18[0] = 0;
    uVar1 = FUN_000153dc(DAT_000648e4,0,0x44,local_18,1,100);
    if (uVar1 != 0) {
      if (local_18[0] != *(byte *)(*(int *)(param_1 + 0xc) + 0xb07)) {
        *(byte *)(*(int *)(param_1 + 0xc) + 0xb07) = local_18[0];
        if (*(int *)(param_1 + 0x5c) != 0) {
          FUN_0001c7d4(DAT_000649b8,(uint)local_18[0]);
        }
        if (*(int *)(param_1 + 0x60) != 0) {
          FUN_00014a6c(DAT_00064888,(uint)local_18[0]);
        }
        if (((*(int *)(param_1 + 0x60) != 0) || (*(int *)(param_1 + 0x5c) != 0)) ||
           (*(int *)(param_1 + 100) != 0)) {
          FUN_00036de8(0xcc,(uint)local_18[0]);
        }
      }
    }
  }
  FUN_0001de54(param_1);
  FUN_00036de8(0x78,0);
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  NKDbgPrintfW(L"[**NOTI_APP_ACC_ON**]  m_bIsPowerOff-%d, m_bIsAccOff-%d\n",
               *(undefined4 *)(param_1 + 0x2c),0);
  FUN_0001d91c(param_1);
  *(undefined4 *)(param_1 + 0x38) = 0;
  FUN_0003006c(param_1);
  FUN_00011498(DAT_00064828,1,0);
  return;
}



/* 0001e814 FUN_0001e814 */

/* Boundary evidence: original MIPS .pdata 0001e814..0001e84b. Semantic name remains unreviewed. */

void FUN_0001e814(int param_1,undefined2 param_2)

{
  *(undefined2 *)(*(int *)(param_1 + 0xc) + 0xafe) = param_2;
  if (*(HWND *)(param_1 + 0x10) != (HWND)0x0) {
    PostMessageW(*(HWND *)(param_1 + 0x10),0x403,0,0);
  }
  return;
}



/* 0001e84c FUN_0001e84c */

/* Boundary evidence: original MIPS .pdata 0001e84c..0001e9a3. Semantic name remains unreviewed. */

void FUN_0001e84c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  HANDLE hObject;
  HANDLE hObject_00;
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  int local_38 [4];
  
  NKDbgPrintfW(L"[**OnDiskDismount()**]  [%d, %d, %d, %d] \r\n",param_2,param_3,param_4,param_5);
  local_38[3] = param_5;
  local_38[0] = param_2;
  local_38[1] = param_3;
  local_38[2] = param_4;
  hObject = (HANDLE)OpenStore(u_DSK1__000633a4);
  if (hObject != (HANDLE)0xffffffff) {
    uVar3 = 0;
    do {
      if (*(int *)((int)local_38 + uVar3) != 0) {
        hObject_00 = (HANDLE)OpenPartition(hObject,*(undefined4 *)
                                                    ((int)&PTR_u_PART00_000635ac + uVar3));
        if (hObject_00 != (HANDLE)0xffffffff) {
          iVar1 = DismountPartition(hObject_00);
          if (iVar1 == 0) {
            DVar2 = GetLastError();
            NKDbgPrintfW(L"[Error][**OnDiskDismount()**] Storage Card [%s] [0x%08X] \r\n",
                         *(undefined4 *)((int)&PTR_u_PART00_000635ac + uVar3),DVar2);
          }
          CloseHandle(hObject_00);
        }
      }
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x10);
    CloseHandle(hObject);
  }
  return;
}



/* 0001e9a4 FUN_0001e9a4 */

/* Boundary evidence: original MIPS .pdata 0001e9a4..0001ea6f. Semantic name remains unreviewed. */

void FUN_0001e9a4(undefined4 param_1,undefined1 param_2,int param_3)

{
  HANDLE hDevice;
  undefined1 local_18;
  undefined1 local_17;
  
  hDevice = CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hDevice != (HANDLE)0xffffffff) {
    local_17 = param_3 != 0;
    local_18 = param_2;
    DeviceIoControl(hDevice,2,&local_18,2,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  return;
}



/* 0001ea70 FUN_0001ea70 */

/* Boundary evidence: original MIPS .pdata 0001ea70..0001eb17. Semantic name remains unreviewed. */

void FUN_0001ea70(void)

{
  HANDLE hDevice;
  undefined1 local_10 [8];
  
  hDevice = CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hDevice != (HANDLE)0xffffffff) {
    local_10[0] = 0x26;
    DeviceIoControl(hDevice,0,local_10,1,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    CloseHandle(hDevice);
  }
  return;
}



/* 0001eb18 FUN_0001eb18 */

/* Boundary evidence: original MIPS .pdata 0001eb18..0001ec1b. Semantic name remains unreviewed. */

int FUN_0001eb18(undefined4 param_1,undefined4 param_2)

{
  HANDLE hDevice;
  wchar_t *pwVar1;
  undefined4 local_res4 [3];
  int local_18 [2];
  
  local_18[1] = 0;
  local_18[0] = 0;
  local_res4[0] = param_2;
  hDevice = CreateFileW(L"DSK1:",0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                        (HANDLE)0xffffffff);
  if (hDevice == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"DSK1 Open error\r\n");
  }
  else {
    DeviceIoControl(hDevice,0x71f84,local_res4,1,local_18,4,(LPDWORD)(local_18 + 1),
                    (LPOVERLAPPED)0x0);
    if (local_18[0] == 0) {
      pwVar1 = L"eMMC Sleep OK\r\n";
    }
    else {
      pwVar1 = L"eMMC Sleep NG\r\n";
    }
    NKDbgPrintfW(pwVar1);
    CloseHandle(hDevice);
  }
  return local_18[0];
}



/* 0001ec1c FUN_0001ec1c */

/* Boundary evidence: original MIPS .pdata 0001ec1c..0001ee1b. Semantic name remains unreviewed. */

void FUN_0001ec1c(void)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD local_80 [2];
  _DCB _Stack_78;
  _COMMTIMEOUTS local_58;
  _DCB _Stack_40;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  uint local_14;
  
  local_14 = DAT_00064820;
  hFile = CreateFileW(L"COM4:",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"[ERROR]-[Cannot open Com4] \r\n");
  }
  else {
    local_20 = 0xb5;
    local_1f = 0x62;
    local_1e = 6;
    local_1a = 0xff;
    local_19 = 0xff;
    local_1d = 4;
    local_1c = 4;
    local_1b = 0;
    local_18 = 2;
    local_17 = 0;
    local_16 = 0xe;
    local_15 = 0x61;
    GetCommState(hFile,&_Stack_78);
    memcpy(&_Stack_40,&_Stack_78,0x1c);
    _Stack_78.BaudRate = 0x2580;
    _Stack_78.fNull = 0;
    _Stack_78.fParity = 0;
    _Stack_78.ByteSize = '\b';
    _Stack_78.Parity = '\0';
    _Stack_78.StopBits = '\0';
    SetCommState(hFile,&_Stack_78);
    local_58.ReadIntervalTimeout = 2000;
    local_58.ReadTotalTimeoutMultiplier = 3000;
    local_58.ReadTotalTimeoutConstant = 1;
    local_58.WriteTotalTimeoutMultiplier = 0;
    local_58.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(hFile,&local_58);
    BVar1 = WriteFile(hFile,&local_20,0xc,local_80,(LPOVERLAPPED)0x0);
    NKDbgPrintfW(L"[%d-%d][GPS Port Close] \r\n",BVar1,local_80[0]);
    Sleep(0xfa);
    BVar1 = WriteFile(hFile,&local_20,0xc,local_80,(LPOVERLAPPED)0x0);
    SetCommState(hFile,&_Stack_40);
    CloseHandle(hFile);
    NKDbgPrintfW(L"[%d-%d][GPS Port Close] \r\n",BVar1,local_80[0]);
  }
  FUN_0004a3f4(local_14);
  return;
}



/* 0001ee1c FUN_0001ee1c */

/* Boundary evidence: original MIPS .pdata 0001ee1c..0001ef7b. Semantic name remains unreviewed. */

void FUN_0001ee1c(undefined4 param_1,void *param_2)

{
  uint uVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined1 local_40 [36];
  uint local_1c;
  
  local_1c = DAT_00064820;
  uVar1 = FUN_000330b0(param_2);
  if (uVar1 != 0) {
    uVar1 = FUN_000153dc(DAT_000648e4,0xd,0xf1,local_40,0xc,0x96);
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 0xc) {
      uVar1 = FUN_000153dc(DAT_000648e4,0xd,0xf2,local_40 + 0xc,0x14,0x96);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 0x14) {
        NKDbgPrintfW(L"\n ****Receiving Data******************  \n");
        uVar1 = 0;
        do {
          NKDbgPrintfW(L" %2X",local_40[uVar1]);
          uVar1 = uVar1 + 1;
        } while (uVar1 < 0x20);
        NKDbgPrintfW(&DAT_00053b4c);
        FUN_00033294(local_40,0x20);
        if (param_2 != (void *)0x0) {
          memcpy(param_2,local_40,0x20);
        }
        goto LAB_0001ef58;
      }
      uVar3 = 0x14;
      pwVar2 = L"\nWrong received size [IPC::REG_DSI_RD_RVC_TEST2].. (Received:%d, Wanted:%d)\n";
    }
    else {
      uVar3 = 0xc;
      pwVar2 = L"\nWrong received size [IPC::REG_DSI_RD_RVC_TEST1].. (Received:%d, Wanted:%d)\n";
    }
    NKDbgPrintfW(pwVar2,uVar1,uVar3);
  }
LAB_0001ef58:
  FUN_0004a3f4(local_1c);
  return;
}



/* 0001ef7c FUN_0001ef7c */

/* Boundary evidence: original MIPS .pdata 0001ef7c..0001f2c3. Semantic name remains unreviewed. */

undefined4 FUN_0001ef7c(int *param_1,char *param_2)

{
  void *_Dst;
  errno_t eVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  FILE *local_80;
  int local_7c;
  int local_78 [2];
  char local_70 [6];
  char local_6a;
  char local_68;
  char local_67 [55];
  uint local_30;
  
  local_30 = DAT_00064820;
  local_80 = (FILE *)0x0;
  uVar10 = 0;
  local_78[0] = 0;
  local_7c = 0;
  _Dst = malloc(0x40000);
  *param_1 = (int)_Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0xff,0x40000);
    eVar1 = fopen_s(&local_80,param_2,"rt");
    if (eVar1 == 0) {
      pcVar2 = fgets(local_70,0x40,local_80);
      do {
        if ((pcVar2 == (char *)0x0) || (sVar3 = strlen(local_70), local_70[0] != ':'))
        goto LAB_0001f280;
        uVar11 = sVar3 - 1 >> 1;
        iVar13 = 0;
        if (uVar11 != 0) {
          pcVar2 = local_70;
          do {
            pcVar2 = pcVar2 + 2;
            iVar4 = FUN_0001ce38(param_1,(int)pcVar2[-1]);
            iVar5 = FUN_0001ce38(param_1,(int)*pcVar2);
            iVar13 = (iVar4 * 0x10 + iVar5 + iVar13) * 0x1000000 >> 0x18;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        if (iVar13 != 0) goto LAB_0001f280;
        iVar13 = FUN_0001ce38(param_1,(int)local_70[1]);
        iVar4 = FUN_0001ce38(param_1,(int)local_70[2]);
        uVar11 = iVar13 * 0x10 + iVar4;
        iVar13 = FUN_0001ce38(param_1,(int)local_70[3]);
        iVar4 = FUN_0001ce38(param_1,(int)local_70[4]);
        iVar5 = FUN_0001ce38(param_1,(int)local_70[5]);
        iVar6 = FUN_0001ce38(param_1,(int)local_6a);
        iVar7 = FUN_0001ce38(param_1,(int)local_68);
        if (iVar7 == 0) {
          iVar4 = local_7c * 0x10 + ((iVar13 * 0x10 + iVar4) * 0x10 + iVar5) * 0x10 + iVar6 +
                  local_78[0];
          iVar13 = *param_1;
          uVar12 = 0;
          if (uVar11 != 0) {
            pcVar2 = local_67 + 1;
            do {
              iVar5 = FUN_0001ce38(param_1,(int)pcVar2[-1]);
              iVar6 = FUN_0001ce38(param_1,(int)*pcVar2);
              pcVar9 = (char *)(iVar4 + iVar13 + uVar12);
              uVar12 = uVar12 + 1;
              *pcVar9 = (char)iVar5 * '\x10' + (char)iVar6;
              pcVar2 = pcVar2 + 2;
            } while (uVar12 < uVar11);
          }
        }
        else {
          if (iVar7 == 1) {
            uVar10 = 1;
LAB_0001f280:
            fclose(local_80);
            FUN_0004a3f4(local_30);
            return uVar10;
          }
          if (iVar7 == 2) {
            local_67[uVar11 * 2] = '\0';
            local_70[uVar11 * 2 + 9 | 1] = '\0';
            piVar8 = &local_7c;
          }
          else {
            if (iVar7 != 3) {
              if ((iVar7 == 4) || (iVar7 == 5)) goto LAB_0001f25c;
              goto LAB_0001f280;
            }
            local_67[uVar11 * 2] = '\0';
            local_67[uVar11 * 2 + 1] = '\0';
            piVar8 = local_78;
          }
          sscanf_s(local_67,"%x",piVar8);
        }
LAB_0001f25c:
        pcVar2 = fgets(local_70,0x40,local_80);
      } while( true );
    }
    if (local_80 != (FILE *)0x0) {
      fclose(local_80);
      local_80 = (FILE *)0x0;
    }
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
      *param_1 = 0;
    }
  }
  FUN_0004a3f4(local_30);
  return 0;
}



/* 0001f2c4 FUN_0001f2c4 */

/* Boundary evidence: original MIPS .pdata 0001f2c4..0001f3bb. Semantic name remains unreviewed. */

undefined4 *
FUN_0001f2c4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00030010(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_000528e8;
  param_1[7] = 0;
  memset(param_1 + 0x21,0,2);
  param_1[0x12] = 1;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = param_4;
  param_1[8] = 0;
  param_1[0xf] = 0;
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  param_1[0x16] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 2;
  param_1[0x10] = 0;
  param_1[0x1a] = 0;
  param_1[0x1c] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1d] = 0;
  param_1[0x23] = 0;
  param_1[0x22] = 0;
  param_1[0xe] = 6;
  FUN_00030044((int)param_1,0x2ee);
  return param_1;
}



/* 0001f3bc Unwind@0001f3bc */

/* Boundary evidence: original MIPS .pdata 0001f3bc..0001f3eb. Semantic name remains unreviewed. */

void Unwind_0001f3bc(void)

{
  undefined4 *in_v0;
  
  FUN_0003008c((undefined4 *)*in_v0);
  return;
}



/* 0001f3ec FUN_0001f3ec */

/* Boundary evidence: original MIPS .pdata 0001f3ec..0001f443. Semantic name remains unreviewed. */

undefined4 * FUN_0001f3ec(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000528e8;
  FUN_0003008c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001f444 FUN_0001f444 */

/* Boundary evidence: original MIPS .pdata 0001f444..00020f83. Semantic name remains unreviewed. */

void FUN_0001f444(int param_1,int param_2)

{
  uint uVar1;
  LSTATUS LVar2;
  HANDLE pvVar3;
  size_t sVar4;
  BOOL BVar5;
  HWND pHVar6;
  DWORD DVar7;
  wchar_t *pwVar8;
  undefined *puVar9;
  BYTE *lpData;
  uint uVar10;
  int iVar11;
  uint *lpData_00;
  ushort *puVar12;
  int *lpData_01;
  FILE *lpSubKey;
  byte local_860 [4];
  HKEY local_85c;
  byte local_858;
  byte local_857;
  byte local_856;
  byte local_855;
  char local_854;
  char local_853;
  byte local_852;
  byte local_851;
  BYTE local_850 [4];
  undefined4 local_84c;
  char local_848 [8];
  uint local_840;
  BYTE local_83c [4];
  uint local_838;
  uint local_834;
  int local_830;
  uint local_82c;
  uint local_828;
  uint local_824;
  FILE *local_820;
  uint local_81c;
  uint local_818;
  uint local_814;
  uint local_810;
  uint local_80c;
  undefined *local_808;
  undefined4 local_804;
  HKEY local_800;
  uint local_7fc;
  uint local_7f8;
  uint local_7f4;
  HKEY local_7f0;
  uint local_7ec;
  BYTE local_7e8 [4];
  uint local_7e4;
  uint local_7e0;
  uint local_7dc;
  uint local_7d8;
  uint local_7d4;
  uint local_7d0 [2];
  wchar_t *local_7c8 [3];
  DWORD DStack_7bc;
  undefined1 local_7b8;
  undefined1 auStack_7b7 [2];
  byte local_7b5;
  byte local_7b4;
  byte local_7b3;
  byte local_7b2;
  byte local_7b1;
  ushort local_7b0;
  byte local_7ae;
  byte local_7ad;
  undefined1 auStack_790 [92];
  uint local_734;
  int local_730;
  int local_72c;
  _WIN32_FIND_DATAW _Stack_710;
  undefined1 local_4b9;
  undefined1 auStack_4b8 [16];
  undefined1 local_4a8;
  char acStack_4a0 [32];
  WCHAR aWStack_480 [32];
  wchar_t awStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00064820;
  local_853 = '\0';
  local_7b8 = 0;
  memset(auStack_7b7,0,2);
  memset(&local_7b5,0,0x21);
  puVar12 = (ushort *)(param_1 + 0x84);
  *puVar12 = *(ushort *)(param_2 + 4);
  local_858 = 0;
  local_830 = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  FUN_0003006c(param_1);
  lpData_01 = (int *)(param_1 + 0x70);
  uVar1 = FUN_000153dc(DAT_000648e4,1,8,lpData_01,1,100);
  if ((uVar1 != 0) &&
     (NKDbgPrintfW(L"[PRODUCT PILOT TEST TOOL] VAL(%d)\n",*lpData_01), *lpData_01 != 0)) {
    iVar11 = 0;
    do {
      if (DAT_00063734 == 0) break;
      NKDbgPrintfW(&DAT_00054980);
      Sleep(100);
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x1e);
    FUN_0001ec1c();
  }
  uVar1 = FUN_000153dc(DAT_000648e4,1,0xca,&local_830,1,100);
  if (((uVar1 != 0) &&
      (NKDbgPrintfW(L"[PRODUCT GUIDELINE TYPE] VAL(%d)\n",local_830), *lpData_01 != 0)) &&
     (local_830 == 0)) {
    local_830 = 1;
  }
  uVar1 = FUN_000153dc(DAT_000648e4,1,0xd5,&local_856,1,0x96);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"[HW REVISION] VAL(%d)\n",local_856);
  }
  if (DAT_00067fa4 == '\x01') {
    *(undefined4 *)(param_1 + 0x24) = 1;
    *puVar12 = *puVar12 | 0x10;
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = 3;
    *puVar12 = *puVar12 & 0xffef;
  }
  FUN_0001ee1c(param_1,&local_7b8);
  local_854 = '\0';
  uVar1 = FUN_000153dc(DAT_000648e4,0,0x44,&local_854,1,100);
  if (uVar1 == 1) {
    *(char *)(*(int *)(param_1 + 0xc) + 0xb07) = local_854;
    if (local_854 != '\0') {
      *(undefined4 *)(param_1 + 0x24) = 1;
      *puVar12 = *puVar12 | 0x10;
    }
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb07) = 0;
  }
  NKDbgPrintfW(L"\r\n\r\npwr_state-%d, tempo_on-%d\r\n\r\n",*puVar12 >> 4 & 1,local_854);
  local_851 = 0;
  local_838 = 0;
  local_808 = (undefined *)0x0;
  local_820 = (FILE *)0x5049c;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_85c);
  lpSubKey = (FILE *)L"LGE\\SystemInfo";
  if (LVar2 == 0) {
    local_838 = (uint)(local_7b1 >> 6);
    local_7d8 = local_7b1 >> 2 & 1;
    local_7f8 = (uint)((local_7b1 & 1) == 0);
    local_7e0 = (uint)local_7b3;
    uVar10 = (uint)local_7b0;
    local_7fc = (uint)local_7b4;
    local_7d0[0] = local_7b1 >> 1 & 1;
    local_7f4 = FUN_00032674((uint)local_7b5);
    local_81c = (uint)((local_7ae & 2) == 0);
    local_814 = (uint)((local_7ae & 4) == 0);
    local_840 = (uint)((local_7ad & 2) != 0);
    local_7d4 = (uint)(local_7ae >> 6);
    local_810 = (uint)((local_7ad & 0x10) == 0);
    local_7ec = local_7ad >> 2 & 1;
    uVar1 = FUN_000153dc(DAT_000648e4,1,0xc9,&local_851,1,0x96);
    if (uVar1 != 0) {
      local_808 = (undefined *)(uint)local_851;
      if (local_808 < (undefined *)0x4b) {
        pwVar8 = L"[SKU REGION] (%s)\n";
        puVar9 = (&PTR_u_M0_WEU_00062f70)[(int)local_808];
      }
      else {
        pwVar8 = L"[SKU REGION] Unknown(%d)\n";
        puVar9 = local_808;
      }
      NKDbgPrintfW(pwVar8,puVar9);
    }
    local_857 = 0;
    uVar1 = FUN_000153dc(DAT_000648e4,0xd,0xd,&local_857,1,0xfa);
    if (uVar1 == 1) {
      NKDbgPrintfW(L"~~ OK Read boot logo type from Micom:[%d]\r\n",local_857);
      if (local_857 < 10) {
        FUN_000326f0(local_857);
      }
    }
    else {
      NKDbgPrintfW(L"~~ Error Read boot logo type from Micom[%d] \r\n",local_857);
      local_857 = local_7b2;
    }
    switch(local_857) {
    default:
      local_84c = 0;
      break;
    case 1:
    case 5:
    case 6:
      local_84c = 1;
      break;
    case 2:
      local_84c = 2;
      break;
    case 3:
      local_84c = 3;
      break;
    case 4:
      local_84c = 4;
      break;
    case 7:
      local_84c = 5;
      break;
    case 8:
      local_84c = 7;
      break;
    case 9:
      local_84c = 6;
    }
    NKDbgPrintfW(L"[INFO] CNF_CMK [%d][%d]\r\n");
    RegSetValueExW(local_85c,L"BOOT_LOGO",0,4,(BYTE *)&local_84c,4);
    local_855 = 0;
    local_818 = 0;
    local_834 = 0;
    local_82c = 0;
    local_824 = 0;
    if (*lpData_01 == 0) {
      FUN_000153dc(DAT_000648e4,1,0xcc,&local_855,1,0xfa);
    }
    else {
      FUN_000153dc(DAT_000648e4,1,10,&local_855,1,0xfa);
    }
    lpData_00 = (uint *)(param_1 + 0x5c);
    *lpData_00 = (uint)(local_855 >> 7);
    local_82c = local_855 >> 5 & 1;
    local_818 = local_855 & 7;
    local_834 = local_855 >> 3 & 3;
    local_824 = local_855 >> 6 & 1;
    *(uint *)(param_1 + 0x60) = local_834;
    RegSetValueExW(local_85c,L"HMI_ADAC_CNF",0,4,(BYTE *)&local_818,4);
    RegSetValueExW(local_85c,L"HMI_TEMP_CNF",0,4,(BYTE *)&local_834,4);
    RegSetValueExW(local_85c,L"HMI_AIR_CNF",0,4,(BYTE *)&local_82c,4);
    RegSetValueExW(local_85c,L"HMI_ENG_CNF",0,4,(BYTE *)&local_824,4);
    RegSetValueExW(local_85c,L"HMI_ECO_CNF",0,4,(BYTE *)lpData_00,4);
    NKDbgPrintfW(L"Specific HMI[0x%02X] : [%d][%d][%d][%d][%d] \r\n",local_855,local_818,local_834,
                 local_82c,local_824,*lpData_00);
    FUN_0001c520(DAT_000649b8,*lpData_00);
    FUN_00014afc(DAT_00064888,local_834);
    FUN_00013d44(DAT_00064888,local_834,(char)local_82c);
    *(uint *)(DAT_000649b8 + 0x24) = (uint)(local_824 == 0);
    if (*lpData_01 != 0) {
      local_852 = 0;
      uVar1 = FUN_000153dc(DAT_000648e4,1,9,&local_852,1,100);
      if (uVar1 != 0) {
        local_838 = (uint)local_852;
        NKDbgPrintfW(L"[PRODUCT PILOT TEST TOOL UI_TYPE] VAL(%d)\n",local_838);
      }
      uVar1 = FUN_000153dc(DAT_000648e4,1,0xb,&local_858,1,100);
      if (uVar1 != 0) {
        NKDbgPrintfW(L"[PRODUCT PILOT TEST TOOL FUNC_TYPE] VAL(%d)\n",local_858);
      }
    }
    memset(aWStack_238,0,0x208);
    if (*lpData_01 == 1) {
      uVar10 = 0x2a2a;
      NKDbgPrintfW(L"\n\n[Tool] Connect map code = %x(%c%c)\n\n",0x2a2a,0x2a,0x2a);
      FUN_0001e39c();
    }
    else {
      NKDbgPrintfW(L"\n\n[Tool] disConnect map code = %x(%c%c)\n\n",uVar10,uVar10 & 0xff,
                   local_7b0 >> 8);
    }
    local_7c8[1] = L"14Q4";
    local_7c8[0] = L"13Q4";
    uVar1 = 0;
    local_7c8[2] = L"15Q2";
    swprintf_s(awStack_440,0x104,L"\\Storage Card4\\NNG\\license\\LGe_Renault_ULC_14CY_Primo_*.*");
    pvVar3 = FindFirstFileW(awStack_440,&_Stack_710);
    if (pvVar3 == (HANDLE)0xffffffff) {
      swprintf_s(awStack_440,0x104,
                 L"\\Storage Card4\\NNG\\license\\LGe_Renault_ULC2_15CY_Primo_IN_15Q2_MMI_POI_KML_iINHM@15Q2RenaultULC.lyc"
                );
      pvVar3 = FindFirstFileW(awStack_440,&_Stack_710);
      if (pvVar3 == (HANDLE)0xffffffff) {
        swprintf_s(awStack_440,0x104,
                   L"\\Storage Card4\\NNG\\license\\LGe_Renault_ULC2_15CY_Primo_*.*");
        pvVar3 = FindFirstFileW(awStack_440,&_Stack_710);
        if (pvVar3 == (HANDLE)0xffffffff) goto LAB_0001fd8c;
        pwVar8 = wcsstr((wchar_t *)&_Stack_710.dwReserved1,L"15Q2");
        uVar1 = 2;
        if (pwVar8 == (wchar_t *)0x0) {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 2;
      }
      FindClose(pvVar3);
    }
    else {
      wcsstr((wchar_t *)&_Stack_710.dwReserved1,L"13Q4");
      uVar1 = 0;
      FindClose(pvVar3);
    }
LAB_0001fd8c:
    NKDbgPrintfW(L"\r\n ulMapIndex %d(%s) %s\n\r",uVar1,local_7c8[uVar1],&_Stack_710.dwReserved1);
    FUN_0001e25c(param_1,uVar10,aWStack_238,uVar1);
    sVar4 = wcslen(aWStack_238);
    RegSetValueExW(local_85c,L"MAPCODE",0,1,(BYTE *)aWStack_238,(sVar4 + 1) * 2);
    RegSetValueExW(local_85c,L"UI_TYPE",0,4,(BYTE *)&local_838,4);
    uVar1 = local_7f4;
    local_828 = 0;
    pvVar3 = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                         0x80,(HANDLE)0x0);
    if (pvVar3 == (HANDLE)0xffffffff) {
      *(undefined4 *)(param_1 + 0x34) = 1;
      local_848[3] = 1;
      FUN_00014db0(DAT_000648e4,9,0x72,(int)(local_848 + 3),1,100);
    }
    else {
      BVar5 = ReadFile(pvVar3,auStack_790,0x80,&DStack_7bc,(LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        *(undefined4 *)(param_1 + 0x34) = 1;
        local_848[1] = 1;
        FUN_00014db0(DAT_000648e4,9,0x72,(int)(local_848 + 1),1,100);
      }
      else {
        if ((local_838 != 0) && (local_828 = (uint)(local_730 == 1), *lpData_01 == 0)) {
          local_838 = local_828 + local_838;
        }
        uVar10 = (uint)(local_72c == 0);
        NKDbgPrintfW(L"~!@#$ RVC OFFON [%d -> %d(%d)]!!!!\r\n",*(undefined4 *)(param_1 + 0x34),
                     uVar10);
        *(uint *)(param_1 + 0x34) = uVar10;
        local_848[4] = local_72c == 0;
        FUN_00014db0(DAT_000648e4,9,0x72,(int)(local_848 + 4),1,100);
        if ((int)local_734 < 0x20) {
          uVar1 = local_734;
        }
      }
      CloseHandle(pvVar3);
    }
    if (DAT_000648ec != 0) {
      FUN_00016c80(DAT_000648ec,uVar1);
      FUN_00016ddc(DAT_000648ec,local_838);
    }
    RegSetValueExW(local_85c,L"INVERSE_TYPE",0,4,(BYTE *)&local_828,4);
    RegSetValueExW(local_85c,L"UI_INVERSE",0,4,(BYTE *)&local_828,4);
    RegSetValueExW(local_85c,L"NONAVI",0,4,(BYTE *)&local_7d8,4);
    RegSetValueExW(local_85c,L"LANG_TYPE",0,4,(BYTE *)&local_7f4,4);
    RegSetValueExW(local_85c,L"CLOCK_TYPE",0,4,(BYTE *)&local_7f8,4);
    RegSetValueExW(local_85c,L"METER_TYPE",0,4,(BYTE *)local_7d0,4);
    RegSetValueExW(local_85c,L"SDVC_TYPE",0,4,(BYTE *)&local_7e0,4);
    RegSetValueExW(local_85c,L"RAD_CONTRY",0,4,(BYTE *)&local_7fc,4);
    local_7dc = *puVar12 & 1;
    RegSetValueExW(local_85c,L"FACTORY_TYPE",0,4,(BYTE *)&local_7dc,4);
    RegSetValueExW(local_85c,L"TOOL_CONNECTED",0,4,(BYTE *)lpData_01,4);
    RegSetValueExW(local_85c,L"GUIDELINE_TYPE",0,4,(BYTE *)&local_830,4);
    local_850[0] = '\0';
    local_850[1] = '\0';
    local_850[2] = '\0';
    local_850[3] = '\0';
    FUN_000153dc(DAT_000648e4,1,0xcd,local_850,1,0xfa);
    RegSetValueExW(local_85c,L"RVC_BRIGHTNESS",0,4,local_850,4);
    FUN_000153dc(DAT_000648e4,1,0xce,local_850,1,0xfa);
    RegSetValueExW(local_85c,L"RVC_CONTRAST",0,4,local_850,4);
    FUN_000153dc(DAT_000648e4,1,0xcf,local_850,1,0xfa);
    RegSetValueExW(local_85c,L"RVC_HUE",0,4,local_850,4);
    FUN_000153dc(DAT_000648e4,1,0xd0,local_850,1,0xfa);
    RegSetValueExW(local_85c,L"RVC_SATU",0,4,local_850,4);
    FUN_000153dc(DAT_000648e4,1,0xd1,local_850,1,0xfa);
    RegSetValueExW(local_85c,L"RVC_SATV",0,4,local_850,4);
    FUN_0003341c(1,&local_7ae);
    RegSetValueExW(local_85c,L"AM_MW",0,4,(BYTE *)&local_81c,4);
    RegSetValueExW(local_85c,L"AM_LW",0,4,(BYTE *)&local_814,4);
    RegSetValueExW(local_85c,L"DAB_EN",0,4,(BYTE *)&local_840,4);
    RegSetValueExW(local_85c,L"RVC_EN",0,4,(BYTE *)&local_7ec,4);
    RegSetValueExW(local_85c,L"SWRC_TYPE",0,4,(BYTE *)&local_7d4,4);
    RegSetValueExW(local_85c,L"REAR_SPK",0,4,(BYTE *)&local_810,4);
    if (local_810 == 0) {
      DAT_00067678._3_1_ = 0x80;
    }
    RegSetValueExW(local_85c,L"SKU_REGION",0,4,(BYTE *)&local_808,4);
    local_80c = 1;
    uVar1 = FUN_000153dc(DAT_000648e4,1,0xc9,local_848,1,0xfa);
    if (uVar1 != 0) {
      local_80c = (uint)(local_848[0] != '\0');
      RegSetValueExW(local_85c,L"REG_DSI_CNF_LOUDNESS",0,4,(BYTE *)&local_80c,4);
    }
    FUN_0002b65c(DAT_000673c8,(byte)local_7fc,(uint)(local_814 == 1),(uint)(local_81c == 1));
    uVar1 = FUN_000153dc(DAT_000648e4,0xd,0x39,local_860,1,0xfa);
    if (uVar1 != 0) {
      NKDbgPrintfW(L"[ECU_CONF] GPS=%d\r\n",local_860[0]);
      FUN_00024b94((uint)local_860[0]);
    }
    uVar1 = FUN_000153dc(DAT_000648e4,0xd,0x38,local_860,1,0xfa);
    if (uVar1 != 0) {
      NKDbgPrintfW(L"[REG_DSI_CNF_SYS_AMP] USE BOSE AMP=%d\r\n",local_860[0]);
    }
    uVar1 = FUN_000153dc(DAT_000648e4,0xd,0x36,local_860,1,0xfa);
    if (uVar1 != 0) {
      NKDbgPrintfW(L"[CNF_PTT] PTT_EN =%d(%d)\r\n",local_860[0]);
      local_7e4 = (uint)local_860[0];
      RegSetValueExW(local_85c,L"PTT_EN",0,4,(BYTE *)&local_7e4,4);
    }
    uVar1 = FUN_000153dc(DAT_000648e4,0xd,0x35,local_860,1,0xfa);
    if (uVar1 != 0) {
      NKDbgPrintfW(L"[CNF_DAB_ACT] DAB_EN =%d(%d)\r\n",local_860[0],local_840);
      if (local_860[0] != local_840) {
        local_840 = (uint)local_860[0];
        RegSetValueExW(local_85c,L"DAB_EN",0,4,(BYTE *)&local_840,4);
      }
    }
    *(uint *)(param_1 + 0x68) = (uint)(local_840 != 0);
    _Stack_710.cFileName[0x102]._0_1_ = 0;
    memset((void *)((int)_Stack_710.cFileName + 0x205),0,0x12);
    uVar1 = FUN_000153dc(DAT_000648e4,0xd,0xe,_Stack_710.cFileName + 0x102,1,100);
    if (uVar1 != 0) {
      local_7e8[0] = '\x01';
      local_7e8[1] = '\0';
      local_7e8[2] = '\0';
      local_7e8[3] = '\0';
      *(uint *)(param_1 + 100) = (byte)_Stack_710.cFileName[0x102] >> 5 & 1;
      NKDbgPrintfW(L"[UI_SETTINGS] [%02X] AHA=%d, RES=%d\r\n",_Stack_710.cFileName + 0x102);
      RegSetValueExW(local_85c,L"AHA_EN",0,4,local_7e8,4);
      RegSetValueExW(local_85c,L"RES_EN",0,4,(BYTE *)(param_1 + 100),4);
    }
    NKDbgPrintfW(L"[VIN INFORMATION]\r\n");
    uVar1 = FUN_000153dc(DAT_000648e4,0xd,0x1f,_Stack_710.cFileName + 0x102,0x13,100);
    if (uVar1 != 0) {
      uVar1 = 0;
      do {
        NKDbgPrintfW(&DAT_00053ec4,*(undefined1 *)((int)_Stack_710.cFileName + uVar1 + 0x204));
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x13);
      NKDbgPrintfW(&DAT_00053ebc);
      RegSetValueExW(local_85c,L"VIN_INFO",0,3,(BYTE *)(_Stack_710.cFileName + 0x102),0x13);
    }
    FUN_000153dc(DAT_000648e4,1,2,&local_804,4,0xfa);
    RegSetValueExW(local_85c,L"F_CODE",0,3,(BYTE *)&local_804,4);
    if (*lpData_01 != 0) {
      local_83c[0] = '\0';
      local_83c[1] = '\0';
      local_83c[2] = '\0';
      local_83c[3] = '\0';
      NKDbgPrintfW(L"[FUNC_TYPE] [%02X]\r\n",local_858);
      if ((local_858 & 1) != 0) {
        lpData = (BYTE *)(param_1 + 100);
        lpData[0] = '\x01';
        lpData[1] = '\0';
        lpData[2] = '\0';
        lpData[3] = '\0';
        RegSetValueExW(local_85c,L"RES_EN",0,4,lpData,4);
      }
      if ((local_858 & 2) != 0) {
        local_83c[0] = '\x01';
        local_83c[1] = '\0';
        local_83c[2] = '\0';
        local_83c[3] = '\0';
        RegSetValueExW(local_85c,L"AHA_EN",0,4,local_83c,4);
      }
      if ((local_858 & 4) != 0) {
        local_83c[0] = '\x01';
        local_83c[1] = '\0';
        local_83c[2] = '\0';
        local_83c[3] = '\0';
        RegSetValueExW(local_85c,L"PTT_EN",0,4,local_83c,4);
      }
      if ((local_858 & 8) != 0) {
        local_83c[0] = '\x01';
        local_83c[1] = '\0';
        local_83c[2] = '\0';
        local_83c[3] = '\0';
        *(undefined4 *)(param_1 + 0x68) = 1;
        RegSetValueExW(local_85c,L"DAB_EN",0,4,local_83c,4);
        local_848[2] = 1;
        FUN_00014db0(DAT_000648e4,1,0xd5,(int)(local_848 + 2),1,200);
        NKDbgPrintfW(L"[DAB Module Reset] Tool connected!!!\r\n");
      }
    }
    RegCloseKey(local_85c);
    lpSubKey = local_820;
  }
  puVar12 = (ushort *)(param_1 + 0x84);
  if (DAT_00067fa6 != '\0') {
    DAT_00067fa6 = '\0';
    *puVar12 = ((ushort)DAT_00067fa5 << 2 ^ *puVar12) & 4 ^ *puVar12;
    FUN_00036f60();
    FUN_00031fa8();
  }
  if ((*puVar12 & 4) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb03) = local_804;
    iVar11 = *(int *)(param_1 + 0xc);
    NKDbgPrintfW(L"~!@#$% 0x%02X, 0x%02X, 0x%02X, 0x%02X \r\n",*(undefined1 *)(iVar11 + 0xb03),
                 *(undefined1 *)(iVar11 + 0xb04),*(undefined1 *)(iVar11 + 0xb05),
                 *(undefined1 *)(iVar11 + 0xb06));
    if (*lpData_01 == 0) {
      FUN_0001e1d8(param_1);
    }
    FUN_0001e5e8();
  }
  FUN_00014db0(DAT_000648e4,1,1,(int)puVar12,2,0x96);
  uVar1 = FUN_000153dc(DAT_000648e4,9,0x90,&local_856,1,0x96);
  if (uVar1 != 0) {
    *(byte *)(*(int *)(param_1 + 0xc) + 0xb00) = local_856;
    if ((local_856 & 2) == 0) {
      *(undefined4 *)(param_1 + 0x50) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x50) = 1;
    }
    if ((local_856 & 0x20) == 0) {
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaed) = 0;
    }
    else {
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xaed) = 1;
    }
    NKDbgPrintfW(L"\n-nIOStatus[%08b]\n\n",*(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb00));
  }
  SetRVDWnd(DAT_00064aac,*(HWND__ **)(param_1 + 4));
  pHVar6 = FindWindowW(L"AppMain",(LPCWSTR)0x0);
  if (pHVar6 == (HWND)0x0) {
    memset(_Stack_710.cAlternateFileName + 10,0,0x10);
    FUN_000153dc(DAT_000648e4,1,4,_Stack_710.cAlternateFileName + 10,0xf,0x32);
    local_4b9 = 0x31;
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,(LPCWSTR)lpSubKey,0,0,&local_800);
    if (LVar2 == 0) {
      RegSetValueExW(local_800,L"UUID",0,3,(BYTE *)(_Stack_710.cAlternateFileName + 10),0x10);
      RegCloseKey(local_800);
    }
    iVar11 = 0;
    do {
      if (DAT_00063734 == 0) break;
      Sleep(100);
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x1e);
    Sleep(1000);
    pvVar3 = CreateFileW(L"\\Storage Card4\\NNG\\license\\device.nng",0x80000000,0,
                         (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar3 != (HANDLE)0xffffffff) {
      DVar7 = GetFileSize(pvVar3,(LPDWORD)0x0);
      CloseHandle(pvVar3);
      NKDbgPrintfW(L"\r\n file name[%s][%d]\r\n",L"\\Storage Card4\\NNG\\license\\device.nng",DVar7)
      ;
      if (DVar7 == 0) {
        iVar11 = FUN_00031b0c(L"\\Storage Card\\device.nng");
        if (iVar11 == 2) {
          DeleteFileW(L"\\Storage Card\\device.nng");
        }
        DeleteFileW(L"\\Storage Card4\\NNG\\license\\device.nng");
      }
    }
    FUN_0001cea0(L"\\Storage Card\\system\\blue.exe",L"er10q4c$=4G2g-H2tq9X@mid");
    FUN_0001cea0(L"\\Storage Card\\system\\AppMain.exe",L"bd9r2a@_4G2g=J2tq7X@app");
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_000153dc(DAT_000648e4,9,1,&local_853,1,0x96);
    if (local_853 == '\0') {
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x14) = 1;
    }
  }
  if (*(int *)(param_1 + 0x24) == 1) {
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb08) = 0;
    FUN_00016024(DAT_000648ec);
    FUN_00036f08(0x3030105,0);
    FUN_00036e44(0x72,0);
    if (*(int *)(param_1 + 0x3c) != 0) goto LAB_00020e44;
    *(undefined4 *)(param_1 + 0x8c) = 1;
    iVar11 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x24) != 3) goto LAB_00020e44;
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb08) = 1;
    FUN_00036e44(0x71,0);
    FUN_00036f08(0x3030104,0);
    FUN_0001a7a0(DAT_000648ec);
    if (*(int *)(param_1 + 0x3c) != 0) goto LAB_00020e44;
    iVar11 = 1;
  }
  FUN_0001cf8c(param_1,iVar11);
LAB_00020e44:
  FUN_0001d91c(param_1);
  uVar1 = FUN_000153dc(DAT_000648e4,1,0,auStack_4b8,0x10,0x96);
  if (uVar1 != 0) {
    local_820 = (FILE *)0x0;
    local_4a8 = 0;
    sprintf_s(acStack_4a0,0x20,"\\mcm %s.ver",auStack_4b8);
    fopen_s(&local_820,acStack_4a0,"wt");
    if (local_820 != (FILE *)0x0) {
      fclose(local_820);
    }
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,(LPCWSTR)lpSubKey,0,0,&local_7f0);
    if (LVar2 == 0) {
      wsprintfW(aWStack_480,L"%S",auStack_4b8);
      sVar4 = wcslen(aWStack_480);
      RegSetValueExW(local_7f0,L"VerMicomFW",0,1,(BYTE *)aWStack_480,sVar4 << 1);
      RegCloseKey(local_7f0);
    }
  }
  FUN_0001de54(param_1);
  FUN_0004a3f4(local_30);
  return;
}



/* 00020f84 FUN_00020f84 */

/* Boundary evidence: original MIPS .pdata 00020f84..0002113b. Semantic name remains unreviewed. */

void FUN_00020f84(undefined4 param_1,LPCWSTR param_2,int param_3,int param_4)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  DWORD aDStack_230 [2];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_00064820;
  if (param_4 == 0) {
    pwVar3 = L"\\Storage Card\\system\\EC_config.bsd";
  }
  else {
    if (param_4 != 1) {
      NKDbgPrintfW(
                  L"Error - Wrong Echo Canceller type.. you should select one of both PACT or SPVR\n"
                  );
      goto LAB_00021118;
    }
    pwVar3 = L"\\Storage Card\\system\\VR_config.bsd";
  }
  StringCchPrintfW(awStack_228,0x104,L"%s",pwVar3);
  hFile = CreateFileW(param_2,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"File open error - %s\r\n",param_2);
  }
  else {
    SetFilePointer(hFile,0,(PLONG)0x0,2);
    BVar1 = WriteFile(hFile,(LPCVOID)(param_3 + 8),*(byte *)(param_3 + 4) - 3,aDStack_230,
                      (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      NKDbgPrintfW(L"Write Error - %s [err=%d]\n",param_2,DVar2);
    }
    SetEndOfFile(hFile);
    CloseHandle(hFile);
  }
  if ((uint)*(byte *)(param_3 + 7) <= *(byte *)(param_3 + 6) + 1) {
    FUN_0001d15c(param_1,param_2,awStack_228);
  }
LAB_00021118:
  FUN_0004a3f4(local_20);
  return;
}



/* 0002113c FUN_0002113c */

/* Boundary evidence: original MIPS .pdata 0002113c..000213ef. Semantic name remains unreviewed. */

void FUN_0002113c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\Antitheft.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\Antitheft.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\MgrSys.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\MgrSys.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\EcoDrive.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\EcoDrive.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\DriveInfo.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\DriveInfo.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\RVC_CFG_PARAM.DAT");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\RVC_CFG_PARAM.DAT");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\mgrmcm2.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\mgrmcm2.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\mgrmcm2_backup.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\stationlist.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\stationlist.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\stationorder.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\stationorder.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\USBMusicResume.dat");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\USBMusicResume.dat");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\DABInfo.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\DABInfo.cfg");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card\\device.nng");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card\\device.nng");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card4\\NNG\\license\\device.nng");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card4\\NNG\\license\\device.nng");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\nng");
  if (iVar1 == 1) {
    FUN_0001d3c0(param_1,L"\\Storage Card2\\nng");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\DATA");
  if (iVar1 == 1) {
    FUN_0001d3c0(param_1,L"\\Storage Card2\\DATA");
  }
  iVar1 = FUN_00031b0c(L"\\Storage Card2\\PB");
  if (iVar1 == 1) {
    FUN_0001d3c0(param_1,L"\\Storage Card2\\PB");
  }
  FUN_0001d598();
  iVar1 = FUN_00031b0c(L"\\Storage card2\\pwr_count.bin");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage card2\\pwr_count.bin");
  }
  return;
}



/* 000213f0 FUN_000213f0 */

/* Boundary evidence: original MIPS .pdata 000213f0..0002153f. Semantic name remains unreviewed. */

void FUN_000213f0(int param_1,int param_2)

{
  uint uVar1;
  byte local_18 [8];
  
  if (*(int *)(param_1 + 0x24) != param_2) {
    if ((*(int *)(param_1 + 0x24) == 3) && (DAT_00064828 != 0)) {
      FUN_0001221c(DAT_00064828,1);
    }
    if (((*(int *)(param_1 + 0x60) != 0) || (*(int *)(param_1 + 0x5c) != 0)) ||
       (*(int *)(param_1 + 100) != 0)) {
      local_18[0] = 0;
      uVar1 = FUN_000153dc(DAT_000648e4,0,0x44,local_18,1,100);
      if (uVar1 != 0) {
        if (local_18[0] != *(byte *)(*(int *)(param_1 + 0xc) + 0xb07)) {
          *(byte *)(*(int *)(param_1 + 0xc) + 0xb07) = local_18[0];
          if (*(int *)(param_1 + 0x5c) != 0) {
            FUN_0001c7d4(DAT_000649b8,(uint)local_18[0]);
          }
          if (*(int *)(param_1 + 0x60) != 0) {
            FUN_00014a6c(DAT_00064888,(uint)local_18[0]);
          }
          if (((*(int *)(param_1 + 0x60) != 0) || (*(int *)(param_1 + 0x5c) != 0)) ||
             (*(int *)(param_1 + 100) != 0)) {
            FUN_00036de8(0xcc,(uint)local_18[0]);
          }
        }
      }
    }
    *(int *)(param_1 + 0x24) = param_2;
    FUN_0001d91c(param_1);
  }
  return;
}



/* 00021540 FUN_00021540 */

/* Boundary evidence: original MIPS .pdata 00021540..0002155b. Semantic name remains unreviewed. */

void FUN_00021540(int param_1)

{
  FUN_000213f0(param_1,3);
  return;
}



/* 0002155c FUN_0002155c */

/* Boundary evidence: original MIPS .pdata 0002155c..00021747. Semantic name remains unreviewed. */

void FUN_0002155c(int param_1,void *param_2,size_t param_3)

{
  void *_Dst;
  int iVar1;
  HANDLE hFile;
  BOOL BVar2;
  wchar_t *pwVar3;
  DWORD aDStack_20 [2];
  
  if ((param_2 == (void *)0x0) || (param_3 == 0)) {
    pwVar3 = L"[SaveDTCTable]Argument is wrong!!\n";
  }
  else if (*(int *)(param_1 + 0x70) == 1) {
    pwVar3 = L"[SaveDTCTable]Tool connected!!! Not saved DTC!!\n";
  }
  else {
    _Dst = (void *)__2_YAPAXI_Z(param_3);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0x10,param_3);
      FUN_0001e420(param_1,_Dst,param_3);
      iVar1 = memcmp(_Dst,param_2,param_3);
      __3_YAXPAX_Z(_Dst);
      if (iVar1 == 0) {
        NKDbgPrintfW(L"\n---< Same DTC Table, Do not sated DTC Table (%d)>---\n",0);
        return;
      }
    }
    NKDbgPrintfW(L"\n---< Save DTC Table (%d)>---\n",param_3);
    iVar1 = 0;
    if (0 < (int)param_3) {
      do {
        NKDbgPrintfW(L"[%d]0x%X ",iVar1,*(undefined1 *)(iVar1 + (int)param_2));
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)param_3);
    }
    NKDbgPrintfW(&DAT_00054e9c);
    hFile = CreateFileW(L"\\Storage Card\\system\\ULC_DTC.tbl",0x40000000,0,
                        (LPSECURITY_ATTRIBUTES)0x0,4,0x80,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      BVar2 = WriteFile(hFile,param_2,param_3,aDStack_20,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        NKDbgPrintfW(L"[SaveDTCTable]Fail to write the DTC table to ULC_DTC.tbl\n");
      }
      CloseHandle(hFile);
      return;
    }
    pwVar3 = L"[SaveDTCTable]Fail to open or create file - ULC_DTC.tbl\n";
  }
  NKDbgPrintfW(pwVar3);
  return;
}



/* 00021748 FUN_00021748 */

/* Boundary evidence: original MIPS .pdata 00021748..00022cfb. Semantic name remains unreviewed. */

void FUN_00021748(double param_1,int param_2,uint *param_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  DWORD DVar4;
  void *_Dst;
  HWND pHVar5;
  wchar_t *pwVar6;
  UINT UVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte local_40 [4];
  char local_3c;
  undefined1 local_3b;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  uVar10 = *param_3 >> 8 & 0xf;
  if (uVar10 != 2) {
    if (uVar10 != 3) {
      if (uVar10 != 8) {
        return;
      }
      cVar1 = *(char *)((int)param_3 + 2);
      if (cVar1 == '\0') {
        if (DAT_000648ec == 0) {
          return;
        }
        iVar8 = 0;
LAB_00021824:
        FUN_0001696c(DAT_000648ec,iVar8,(uint)(byte)param_3[1]);
        return;
      }
      if (cVar1 == '\x01') {
        if (DAT_000648ec == 0) {
          return;
        }
        iVar8 = 1;
        goto LAB_00021824;
      }
      if (cVar1 == '\x02') {
        if (DAT_000648ec == 0) {
          return;
        }
        iVar8 = 2;
        goto LAB_00021824;
      }
      if (cVar1 != '\x03') {
        return;
      }
      *(undefined4 *)(param_2 + 0x38) = 7;
      UVar7 = 1000;
      goto LAB_00021ab0;
    }
    cVar1 = *(char *)((int)param_3 + 2);
    if (cVar1 != ' ') {
      if (cVar1 == '!') {
        if (*(int *)(param_2 + 0x2c) != 0) {
          return;
        }
        if (*(int *)(param_2 + 0x28) != 1) {
          return;
        }
        *(undefined4 *)(param_2 + 0x28) = 0;
        FUN_0001d91c(param_2);
        *(undefined4 *)(param_2 + 0x38) = 0;
        FUN_0003006c(param_2);
        FUN_00015158(DAT_000648e4,0,1,0x10,0,0,0x32);
        return;
      }
      if (cVar1 != '\"') {
        if (cVar1 != '#') {
          return;
        }
        if ((char)param_3[1] == '\0') {
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else {
          *(undefined4 *)(param_2 + 0x30) = 1;
        }
LAB_00021880:
        FUN_0001d91c(param_2);
        return;
      }
      goto LAB_00021a88;
    }
    if ((*(int *)(param_2 + 0x3c) != 1) && ((*(ushort *)(param_2 + 0x84) & 4) != 0)) {
      if (*(int *)(param_2 + 0x2c) != 0) {
        return;
      }
      if (*(int *)(param_2 + 0x28) != 0) {
        return;
      }
      FUN_00036de8(0x77,0);
      FUN_0001c334(DAT_000649b8);
      *(undefined4 *)(param_2 + 0x28) = 1;
      FUN_0001d91c(param_2);
      *(undefined4 *)(param_2 + 0x38) = 1;
      FUN_00030044(param_2,10000);
      FUN_00036f60();
      FUN_00031fa8();
      return;
    }
    *(undefined4 *)(param_2 + 0x28) = 1;
    *(undefined4 *)(param_2 + 0x2c) = 1;
LAB_00021a98:
    FUN_00036de8(0x79,0);
    *(undefined4 *)(param_2 + 0x40) = 0;
    *(undefined4 *)(param_2 + 0x38) = 2;
    UVar7 = 5000;
LAB_00021ab0:
    FUN_00030044(param_2,UVar7);
    return;
  }
  bVar2 = *(byte *)((int)param_3 + 2);
  if (0x33 < bVar2) {
    if (bVar2 < 0x61) {
      if (bVar2 == 0x60) {
        FUN_00034cf0(param_2,(byte *)(param_3 + 1));
        return;
      }
      if (bVar2 == 0x34) {
        local_40[0] = 0;
        uVar10 = FUN_00047434(param_1);
        NKDbgPrintfW(L"\r\n~!@#$ NOTI_APP_TEMP_OVER [0x%02X, 0x%02X] [%d]\r\n",(char)param_3[1],
                     *(undefined1 *)((int)param_3 + 5),uVar10);
        if ((int)uVar10 < 0x6e) {
          NKDbgPrintfW(L"\r\n~!@#$  Temperatur High = [%d] \r\n",DAT_00064a20);
          if (DAT_00064a20 == 1) {
            local_40[0] = 1;
            DAT_00064a20 = 0;
            FUN_00015158(DAT_000648e4,6,1,3,(int)local_40,1,0xfa);
          }
        }
        else if ((int)uVar10 < 0x73) {
          local_3c = '\x05';
          FUN_00015158(DAT_000648e4,5,1,0x12,(int)&local_3c,1,0x32);
          NKDbgPrintfW(L"\r\n~!@#$  decrease volume volume = [ %d ][%d] \r\n",local_3c,DAT_00064a20)
          ;
          if (DAT_00064a20 == 1) {
            local_40[0] = 1;
            DAT_00064a20 = 0;
            FUN_00015158(DAT_000648e4,6,1,3,(int)local_40,1,0xfa);
          }
        }
        else {
          NKDbgPrintfW(L"\r\n~!@#$  AMP STANDBY ON (%d) volume\r\n",DAT_00064a20);
          if (DAT_00064a20 == 0) {
            local_40[0] = 0;
            DAT_00064a20 = 1;
            FUN_00015158(DAT_000648e4,6,1,3,(int)local_40,1,0xfa);
          }
        }
        iVar8 = 200;
      }
      else {
        if (bVar2 == 0x35) {
          if (DAT_00064a20 == 1) {
            local_3c = '\x01';
            DAT_00064a20 = 0;
            FUN_00015158(DAT_000648e4,6,1,3,(int)&local_3c,1,0xfa);
          }
          pwVar6 = L"\r\n~!@#$ NOTI_APP_TEMP_NORMAL\r\n";
          goto LAB_0002224c;
        }
        if (bVar2 == 0x36) {
          uVar10 = (uint)(byte)param_3[1];
          if (uVar10 == 1) {
            NKDbgPrintfW(L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(_KEYEVT_PTT)\r\n");
            uVar10 = 10;
          }
          else {
            if (uVar10 != 2) {
              pwVar6 = L"[INFO]PTT BTN Changed ->>>> UNKNOWN !!!  %d\r\n";
              goto LAB_00021fb0;
            }
            NKDbgPrintfW(L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(_KEYEVT_PTT_LONG)\r\n");
            uVar10 = 0xb;
          }
          iVar8 = 0x76;
        }
        else {
          if (bVar2 != 0x37) {
            return;
          }
          uVar10 = FUN_00047434(param_1);
          NKDbgPrintfW(L"\r\n~!@#$ NOTI_APP_TEMP_LOW [0x%02X, 0x%02X] [%d]\r\n",(char)param_3[1],
                       *(undefined1 *)((int)param_3 + 5),uVar10);
          iVar8 = 199;
        }
      }
LAB_00021a60:
      FUN_00036de8(iVar8,uVar10);
      return;
    }
    if (bVar2 == 0x61) {
      FUN_00036490(param_2,(byte *)(param_3 + 1));
      FUN_000362ec(param_2,(byte *)(param_3 + 1));
      return;
    }
    if (bVar2 == 0x62) {
      cVar1 = (char)param_3[1];
      if (cVar1 != '\x05') {
        if (cVar1 != '\a') {
          if (cVar1 != '\b') {
            if (cVar1 != ')') {
              if (cVar1 != '*') {
                return;
              }
              uVar10 = (uint)*(byte *)((int)param_3 + 6);
              if (uVar10 == 0) {
                SetTimer(*(HWND *)(param_2 + 4),0x70d,0x4e2,(TIMERPROC)0x0);
                FUN_00036f08(0x1100501,0);
                FUN_00036f08(0x1100601,0);
                NKDbgPrintfW(L"~~ DSI_IOCBLID_CMD_BT_RSSI from Micom (0x%02X/0x%02X/0x%02X/0x%02X/0x%02X/0x%02X) \r\n"
                             ,*(undefined1 *)((int)param_3 + 7),(char)param_3[2],
                             *(undefined1 *)((int)param_3 + 9),*(undefined1 *)((int)param_3 + 10),
                             *(undefined1 *)((int)param_3 + 0xb),(char)param_3[3]);
                return;
              }
              if (uVar10 == 1) {
                return;
              }
              if (uVar10 == 2) {
                KillTimer(*(HWND *)(param_2 + 4),0x70d);
                return;
              }
              pwVar6 = L"[ERROR] :: DSI_IOCBLID_CMD_BT_RSSI [%d]\r\n";
              goto LAB_00021fb0;
            }
            iVar8 = 0x7b;
            if (*(char *)((int)param_3 + 6) == '\x01') {
              uVar10 = 0x290000;
            }
            else {
              uVar10 = 0;
            }
            goto LAB_00021a60;
          }
          pHVar5 = FindWindowW((LPCWSTR)0x0,L"RVC WND");
          PostMessageW(pHVar5,0x9e61,(uint)*(byte *)((int)param_3 + 6),0);
          if (*(char *)((int)param_3 + 6) == '\x01') {
            if (*(int *)(DAT_000648ec + 0x1c) == 2) {
              return;
            }
            FUN_00016164(DAT_000648ec);
            return;
          }
          if (*(char *)((int)param_3 + 6) != '\x02') {
            return;
          }
LAB_00022a9c:
          FUN_00016024(DAT_000648ec);
          return;
        }
        pHVar5 = FindWindowW((LPCWSTR)0x0,L"RVC WND");
        if (*(int *)(DAT_000648ec + 0x1c) == 2) {
          if (*(char *)((int)param_3 + 6) == '\x11') {
            uVar10 = (uint)*(byte *)((int)param_3 + 7);
            if ((uVar10 == 0x20) || (uVar10 == 0x40)) {
              SendMessageW(pHVar5,0x9e61,0,uVar10);
            }
            goto LAB_00022a9c;
          }
          if (*(char *)((int)param_3 + 6) != '\0') {
            return;
          }
          if (pHVar5 == (HWND)0xffffffff) {
            return;
          }
          NKDbgPrintfW(L" :: RVC config...func code=0x%x\n",*(undefined1 *)((int)param_3 + 7));
        }
        else {
          if (pHVar5 == (HWND)0xffffffff) {
            return;
          }
          if (*(char *)((int)param_3 + 6) != '\0') {
            return;
          }
          FUN_00016164(DAT_000648ec);
        }
        SendMessageW(pHVar5,0x9e61,0,(uint)*(byte *)((int)param_3 + 7));
        return;
      }
      uVar10 = (uint)*(byte *)((int)param_3 + 6);
      if (uVar10 != 2) {
        iVar8 = (uint)(byte)param_3[2] * 0x100 + (uint)*(byte *)((int)param_3 + 7);
        uVar9 = (uint)*(byte *)(*(int *)(param_2 + 0xc) + 4);
        if (uVar9 == uVar10) {
          if (uVar9 == 0) {
            iVar8 = iVar8 * 10;
          }
          (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x6f,iVar8);
          return;
        }
        FUN_00036de8(0x7b,uVar10 << 0x10);
        *(int *)(param_2 + 0x6c) = iVar8;
        *(undefined4 *)(param_2 + 0x38) = 4;
        UVar7 = 500;
        goto LAB_00021ab0;
      }
      pHVar5 = FindWindowW(L"MgrDab",L"MgrDab");
      if (pHVar5 != (HWND)0x0) {
        local_38 = 0xc9;
        local_30 = (int)param_3 + 7;
        local_34 = 5;
        SendMessageTimeout(pHVar5,0x4a,3,&local_38,0,0x5dc,&local_3c);
        return;
      }
      pwVar6 = L"\r\n...[ERROR] Check MgrDab...\r\n";
    }
    else {
      if (bVar2 != 99) {
        if (bVar2 != 100) {
          return;
        }
        NKDbgPrintfW(L"Synchronize the cleared data in %s\r\n",
                     L"\\Storage Card\\system\\DSI_config.bsd");
        FUN_00033294(param_3 + 1,(uint)*(byte *)((int)param_3 + 3));
        DeleteFileW(L"\\Storage Card\\system\\DSI_EC_config.bsd");
        DeleteFileW(L"\\Storage Card\\system\\DSI_VR_config.bsd");
        local_3c = '\b';
        local_3b = 0;
        FUN_00015158(DAT_000648e4,1,1,10,(int)&local_3c,2,100);
        return;
      }
      uVar10 = (uint)*(byte *)((int)param_3 + 3);
      _Dst = malloc(uVar10 + 1);
      if (_Dst != (void *)0x0) {
        memcpy(_Dst,param_3 + 1,uVar10);
        FUN_0002155c(param_2,_Dst,uVar10);
        free(_Dst);
        return;
      }
      pwVar6 = L"Fail to allocation memory for saving DTC values..Canceled\n";
    }
    goto LAB_0002224c;
  }
  if (bVar2 == 0x33) {
    uVar10 = param_3[1];
    *(uint *)(param_2 + 0x50) = (uint)(byte)uVar10;
    if ((byte)uVar10 == 1) {
      *(byte *)(*(int *)(param_2 + 0xc) + 0xb00) = *(byte *)(*(int *)(param_2 + 0xc) + 0xb00) | 2;
    }
    else {
      *(byte *)(*(int *)(param_2 + 0xc) + 0xb00) = *(byte *)(*(int *)(param_2 + 0xc) + 0xb00) & 0xfd
      ;
    }
    FUN_00036e44(0x80,0);
    FUN_0001de54(param_2);
    return;
  }
  if (bVar2 < 0x21) {
    if (bVar2 == 0x20) {
      NKDbgPrintfW(L"%s - button : %d \r\n","CMicom::OnCommand",(char)param_3[1]);
      uVar10 = (uint)(byte)param_3[1];
      if (uVar10 == 0) {
        if (((*(int *)(param_2 + 0x28) == 0) && (*(int *)(param_2 + 0x3c) == 0)) &&
           (*(int *)(param_2 + 0x48) == 0)) {
          iVar8 = *(int *)(param_2 + 0x24);
          if (iVar8 == 1) {
            local_40[0] = 0;
            uVar10 = FUN_000153dc(DAT_000648e4,0,0x44,local_40,1,100);
            if (uVar10 == 1) {
              if (local_40[0] == 0) {
                *(ushort *)(param_2 + 0x84) = *(ushort *)(param_2 + 0x84) & 0xffef;
                iVar8 = 3;
              }
              else {
                *(undefined4 *)(param_2 + 0x38) = 0;
                FUN_0003006c(param_2);
                iVar8 = 1;
                *(ushort *)(param_2 + 0x84) = *(ushort *)(param_2 + 0x84) | 0x10;
              }
              FUN_000213f0(param_2,iVar8);
            }
          }
          else if (iVar8 == 2) {
            FUN_00045088(0);
          }
          else if (iVar8 == 3) {
            *(ushort *)(param_2 + 0x84) = *(ushort *)(param_2 + 0x84) | 0x10;
            FUN_000213f0(param_2,1);
            FUN_00011498(DAT_00064828,1,0);
          }
        }
        FUN_00014db0(DAT_000648e4,1,1,param_2 + 0x84,2,0x96);
        FUN_00036f60();
        FUN_00031fa8();
      }
      else if (((1 < uVar10) && (uVar10 < 4)) && (*(int *)(param_2 + 0x24) == 2)) {
        FUN_00045088(uVar10);
      }
      iVar8 = FUN_0001ddc8(param_2);
      if (iVar8 != 1) {
        return;
      }
      iVar8 = FUN_00011f40(DAT_00064828);
      if (iVar8 == 1) {
        uVar3 = FUN_00011e88(DAT_00064828);
        NKDbgPrintfW(L"Audio source changing......MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(Blocked...%d)(GetCurSource() : %d)\r\n"
                     ,(char)param_3[1],uVar3);
        return;
      }
      uVar10 = (uint)(byte)param_3[1];
      if (uVar10 < 0x12) {
        uVar10 = *(uint *)(&DAT_000527c8 + uVar10 * 8);
        if (uVar10 == 0xff) {
          uVar10 = 0xff;
          pwVar6 = L"[Info]MGRMCM : Not uesed keyevent(%d)\r\n";
        }
        else {
          FUN_00036de8(0x76,uVar10);
          pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(%d)\r\n";
        }
      }
      else {
        pwVar6 = L"[Error] MGRMCM : Unknown Keyevent %d...\r\n";
      }
LAB_00021fb0:
      NKDbgPrintfW(pwVar6,uVar10);
      return;
    }
    if (bVar2 == 0) {
      if (*(int *)(param_2 + 0x24) != 0) {
        return;
      }
      FUN_0001f444(param_2,(int)param_3);
      return;
    }
    if (bVar2 == 1) {
      FUN_00015158(DAT_000648e4,0,1,0x10,0,0,0x32);
      if ((*(int *)(param_2 + 0x2c) == 0) && (*(int *)(param_2 + 0x28) == 1)) {
        *(undefined4 *)(param_2 + 0x38) = 0;
        FUN_0003006c(param_2);
        *(undefined4 *)(param_2 + 0x28) = 0;
        *(undefined4 *)(param_2 + 0x44) = 0;
        SetTimer(*(HWND *)(param_2 + 4),0x70a,0x1c2,(TIMERPROC)0x0);
      }
      else if ((*(int *)(param_2 + 0x60) != 0) ||
              ((*(int *)(param_2 + 0x5c) != 0 || (*(int *)(param_2 + 100) != 0)))) {
        local_40[0] = 0;
        uVar10 = FUN_000153dc(DAT_000648e4,0,0x44,local_40,1,100);
        if ((uVar10 != 0) && (local_40[0] != *(byte *)(*(int *)(param_2 + 0xc) + 0xb07))) {
          *(byte *)(*(int *)(param_2 + 0xc) + 0xb07) = local_40[0];
          if (*(int *)(param_2 + 0x5c) != 0) {
            FUN_0001c7d4(DAT_000649b8,(uint)local_40[0]);
          }
          if (*(int *)(param_2 + 0x60) != 0) {
            FUN_00014a6c(DAT_00064888,(uint)local_40[0]);
          }
          if (((*(int *)(param_2 + 0x60) != 0) || (*(int *)(param_2 + 0x5c) != 0)) ||
             (*(int *)(param_2 + 100) != 0)) {
            FUN_00036de8(0xcc,(uint)local_40[0]);
          }
        }
      }
      PostMessageW((HWND)0xffff,DAT_00064a3c,0,0);
      return;
    }
    if (bVar2 == 2) {
      NKDbgPrintfW(L"\r\nACC OFF - lock : 0x%x, timerID : 0x%x\r\n",*(undefined4 *)(param_2 + 0x3c),
                   *(undefined4 *)(param_2 + 0x38));
      PostMessageW((HWND)0xffff,DAT_00064a3c,0,1);
      KillTimer(*(HWND *)(param_2 + 4),0x70a);
      FUN_00015158(DAT_000648e4,0,1,0x11,0,0,0x32);
      if (*(int *)(param_2 + 0x4c) != 1) {
        if ((*(int *)(param_2 + 0x2c) == 0) && (*(int *)(param_2 + 0x28) == 0)) {
          FUN_00036de8(0x77,0);
          FUN_0001c334(DAT_000649b8);
          *(undefined4 *)(param_2 + 0x28) = 1;
          FUN_0001d91c(param_2);
          if (*(int *)(param_2 + 0x44) == 0) {
            UVar7 = 10000;
          }
          else {
            NKDbgPrintfW(L"~~~~~ GOTO SLEEP!!!!! \r\n");
            UVar7 = 0x9c4;
          }
          local_3c = '\0';
          FUN_00015158(DAT_000648e4,7,1,2,(int)&local_3c,1,100);
          *(undefined4 *)(param_2 + 0x38) = 1;
          FUN_00030044(param_2,UVar7);
        }
        FUN_0001e574();
        return;
      }
      pwVar6 = L"\r\n~!@#$ NOTI_APP_ACC_OFF detected!!!!!!! \r\n";
      goto LAB_0002224c;
    }
    if (bVar2 != 3) {
      if (bVar2 != 4) {
        return;
      }
      uVar10 = (uint)(byte)param_3[1];
      NKDbgPrintfW(L"%s - IGN changed : %d \r\n","CMicom::OnCommand",uVar10);
      iVar8 = *(int *)(param_2 + 0xc);
      if (iVar8 != 0) {
        if (uVar10 == 0) {
          *(byte *)(iVar8 + 0xb00) = *(byte *)(iVar8 + 0xb00) & 0xfb;
        }
        else {
          *(byte *)(iVar8 + 0xb00) = *(byte *)(iVar8 + 0xb00) | 4;
        }
      }
      iVar8 = 0x83;
      goto LAB_00021a60;
    }
    PostMessageW((HWND)0xffff,DAT_00064a3c,0,1);
LAB_00021a88:
    *(undefined4 *)(param_2 + 0x28) = 1;
    *(undefined4 *)(param_2 + 0x2c) = 1;
    FUN_0001d91c(param_2);
    goto LAB_00021a98;
  }
  if (bVar2 != 0x21) {
    if (bVar2 == 0x22) {
      cVar1 = (char)param_3[1];
      if (cVar1 == '\0') {
        *(undefined4 *)(param_2 + 0x74) = 1;
        NKDbgPrintfW(L"===========================================\n");
        NKDbgPrintfW(L"======  START CONFIGURATION DISPLAY  ======\n");
        NKDbgPrintfW(L"===========================================\n");
        FUN_000162ec(DAT_000648ec,1);
        KillTimer(*(HWND *)(param_2 + 4),2);
      }
      else {
        if (cVar1 == '\x01') {
          *(undefined4 *)(param_2 + 0x74) = 0;
          FUN_000162ec(DAT_000648ec,2);
          local_3c = '\b';
          FUN_00015158(DAT_000648e4,1,1,8,(int)&local_3c,1,0x32);
          pwVar6 = L"===========================================\n";
          NKDbgPrintfW(L"===========================================\n");
          DVar4 = GetTickCount();
          NKDbgPrintfW(L"==== COMPLETE CONFIGURATION (T2= %d) ====\n",DVar4);
          goto LAB_0002224c;
        }
        if (cVar1 != '\x02') {
          return;
        }
        *(undefined4 *)(param_2 + 0x74) = 1;
        NKDbgPrintfW(L"===========================================\n");
        NKDbgPrintfW(L"======     CONNECTED TOOL DISPLAY    ======\n");
        NKDbgPrintfW(L"===========================================\n");
        FUN_000162ec(DAT_000648ec,0);
      }
      FUN_0002113c(param_2);
      return;
    }
    if (bVar2 == 0x30) {
      uVar10 = 0;
      if ((char)param_3[1] == '\0') {
        iVar8 = 0x74;
        *(undefined1 *)(*(int *)(param_2 + 0xc) + 0xaed) = 0;
      }
      else {
        iVar8 = 0x73;
        *(undefined1 *)(*(int *)(param_2 + 0xc) + 0xaed) = 1;
      }
      goto LAB_00021a60;
    }
    if (bVar2 != 0x31) {
      return;
    }
    if (*(uint *)(param_2 + 0x14) == (uint)(byte)param_3[1]) {
      pwVar6 = L"~!@#$ Gear detect !!!! Oh~~~~ My god!!!!!\r\n";
    }
    else {
      if ((byte)param_3[1] == 0) {
        *(undefined4 *)(param_2 + 0x14) = 0;
      }
      else {
        *(undefined4 *)(param_2 + 0x14) = 1;
      }
      NKDbgPrintfW(L"[INFO][%d] Rear gear detection %d(%d)\r\n",*(undefined4 *)(param_2 + 0x48),
                   *(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x34));
      if (*(int *)(param_2 + 0x34) != 0) {
        if ((*(int *)(param_2 + 0x48) != 0) && (*(int *)(param_2 + 0x14) != 0)) {
          DAT_00064a28 = 1;
          return;
        }
        goto LAB_00021880;
      }
      pwVar6 = L"~!@#$ Gear detect !!!! RVC OFF !!!!\r\n";
    }
LAB_0002224c:
    NKDbgPrintfW(pwVar6);
    return;
  }
  memset(&local_3c,0,2);
  if (((DAT_0006309c == *(byte *)((int)param_3 + 5)) &&
      (DAT_000630a0 == *(byte *)((int)param_3 + 6))) &&
     (DVar4 = GetTickCount(), DVar4 - DAT_00064a2c < 1000)) {
    NKDbgPrintfW(L"[CMD_APP_CAN_CONF]  ===================================== \r\n");
    pwVar6 = L"[CMD_APP_CAN_CONF]  ===================EXIT============== \r\n";
    goto LAB_0002224c;
  }
  DAT_0006309c = (uint)*(byte *)((int)param_3 + 5);
  DAT_000630a0 = (uint)*(byte *)((int)param_3 + 6);
  *(undefined4 *)(DAT_000648e4 + 0xc4) = 1;
  DAT_00064a2c = GetTickCount();
  switch(*(undefined1 *)((int)param_3 + 5)) {
  case 0:
    FUN_00033294(param_3 + 2,(byte)param_3[1] + 0xfd & 0xff);
    FUN_00032a38();
    DeleteFileW(L"\\Storage Card2\\EcoDrive.cfg");
    DVar4 = GetTickCount();
    NKDbgPrintfW(L"[CMD_APP_CAN_CONF] Start handshaking data and Delete ECO_DRIVE_CONFIG_FILE (T1 = %d)(%d, %d)\r\nKILL TIMER\r\n"
                 ,DVar4,7,8);
    KillTimer(*(HWND *)(param_2 + 4),0x3e9);
    KillTimer(*(HWND *)(param_2 + 4),0x708);
    KillTimer(*(HWND *)(param_2 + 4),0x70c);
    KillTimer(*(HWND *)(param_2 + 4),0x70e);
    KillTimer(*(HWND *)(param_2 + 4),0x70d);
    KillTimer(*(HWND *)(param_2 + 4),0x76c);
    break;
  case 1:
    pwVar6 = L"\\Storage Card\\system\\DSI_EC_config.bsd";
    goto LAB_0002237c;
  case 2:
    iVar8 = 0;
    pwVar6 = L"\\Storage Card\\system\\DSI_EC_config.bsd";
    goto LAB_0002239c;
  case 3:
    iVar8 = 0;
    pwVar6 = L"\\Storage Card\\system\\DSI_EC_config.bsd";
    goto LAB_000223bc;
  case 4:
    pwVar6 = L"\\Storage Card\\system\\DSI_VR_config.bsd";
LAB_0002237c:
    FUN_0001d038(param_2,pwVar6,(int)param_3);
    break;
  case 5:
    iVar8 = 1;
    pwVar6 = L"\\Storage Card\\system\\DSI_VR_config.bsd";
LAB_0002239c:
    FUN_00020f84(param_2,pwVar6,(int)param_3,iVar8);
    break;
  case 6:
    iVar8 = 1;
    pwVar6 = L"\\Storage Card\\system\\DSI_VR_config.bsd";
LAB_000223bc:
    FUN_00020f84(param_2,pwVar6,(int)param_3,iVar8);
    break;
  case 7:
    FUN_0002155c(param_2,param_3 + 2,(byte)param_3[1] - 3);
  }
  uVar10 = (uint)*(byte *)((int)param_3 + 6);
  cVar1 = *(char *)((int)param_3 + 5);
  if (uVar10 + 1 < (uint)*(byte *)((int)param_3 + 7)) {
    uVar9 = uVar10 + 1 & 0xff;
    local_3c = cVar1;
  }
  else {
    local_3c = cVar1 + '\x01';
    uVar9 = 0;
  }
  local_3b = (undefined1)uVar9;
  NKDbgPrintfW(L"[^To Micom^]CMD_APP_CAN_CONF (index=%d(%d) (%d/%d/%d/%d))\r\n",local_3c,uVar9,
               (char)param_3[1],cVar1,uVar10,(uint)*(byte *)((int)param_3 + 7));
  FUN_000152c8(DAT_000648e4,1,1,10,(int)&local_3c,2,0x1c2);
  if (local_3c == '\b') {
    DAT_0006309c = 0xffffffff;
    DAT_000630a0 = 0xffffffff;
    *(undefined4 *)(DAT_000648e4 + 0xc4) = 0;
  }
  return;
}



/* 00022cfc FUN_00022cfc */

/* Boundary evidence: original MIPS .pdata 00022cfc..00022e63. Semantic name remains unreviewed. */

undefined4 FUN_00022cfc(int param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  KillTimer(*(HWND *)(param_1 + 4),1);
  KillTimer(*(HWND *)(param_1 + 4),0x3e9);
  KillTimer(*(HWND *)(param_1 + 4),2);
  KillTimer(*(HWND *)(param_1 + 4),1000);
  piVar1 = (int *)__2_YAPAXI_Z(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = 0;
  }
  *(int **)(param_1 + 0x20) = piVar1;
  iVar2 = FUN_0001ef7c(piVar1,param_2);
  if (iVar2 == 1) {
    *(undefined4 *)(param_1 + 0x18) = 1;
    FUN_00015158(DAT_000648e4,1,1,5,0,0,0x32);
    *(undefined4 *)(param_1 + 0x1c) = 1;
    FUN_00019f4c(DAT_000648ec,0);
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x20);
    if (puVar3 != (undefined4 *)0x0) {
      if ((void *)*puVar3 != (void *)0x0) {
        free((void *)*puVar3);
        *puVar3 = 0;
      }
      __3_YAXPAX_Z(puVar3);
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x18) = 1;
    FUN_00015158(DAT_000648e4,1,1,5,0,0,0x32);
    *(undefined4 *)(param_1 + 0x1c) = 1;
    FUN_00019f4c(DAT_000648ec,1000);
    uVar4 = 0;
  }
  FUN_0001d750(param_1,0x20);
  return uVar4;
}



/* 00022e64 FUN_00022e64 */

/* Boundary evidence: original MIPS .pdata 00022e64..00023307. Semantic name remains unreviewed. */

void FUN_00022e64(int param_1)

{
  bool bVar1;
  uint uVar2;
  HWND hWnd;
  DWORD DVar3;
  LSTATUS LVar4;
  DWORD DVar5;
  wchar_t *pwVar6;
  wchar_t *lpNewFileName;
  int iVar7;
  ushort *puVar8;
  int local_70;
  HKEY local_6c;
  DWORD local_68 [2];
  undefined1 auStack_60 [48];
  uint local_30;
  
  local_30 = DAT_00064820;
  KillTimer(*(HWND *)(param_1 + 4),1);
  KillTimer(*(HWND *)(param_1 + 4),0x3e9);
  KillTimer(*(HWND *)(param_1 + 4),2);
  KillTimer(*(HWND *)(param_1 + 4),0x709);
  KillTimer(*(HWND *)(param_1 + 4),1000);
  memset(auStack_60,0x10,0x2c);
  uVar2 = FUN_000153dc(DAT_000648e4,0xd,0x2c,auStack_60,0x2c,300);
  NKDbgPrintfW(L"\n---< Save DTC Table [%d, %d] >---\n",0x2c,uVar2);
  if (uVar2 == 0x2c) {
    FUN_0002155c(param_1,auStack_60,0x2c);
  }
  else {
    NKDbgPrintfW(L"\n[ERROR]---< Save DTC Table %d>---\n",uVar2);
  }
  puVar8 = (ushort *)(param_1 + 0x84);
  uVar2 = ((uint)(*(int *)(param_1 + 0x24) != 3) << 4 ^ (uint)*puVar8) & 0x10 ^ (uint)*puVar8;
  *puVar8 = (ushort)uVar2;
  DAT_00067fa4 = (byte)(uVar2 >> 4) & 1;
  if (*(int *)(param_1 + 0x88) != 0) {
    FUN_00024668(0);
  }
  FUN_000110a4(DAT_00064828);
  FUN_00036f60();
  FUN_00031fa8();
  FUN_00031550(DAT_00067670);
  FUN_00014db0(DAT_000648e4,1,1,(int)puVar8,2,0x32);
  FUN_0001dbb0();
  FUN_0001e9a4(param_1,0,1);
  uVar2 = 0;
  do {
    hWnd = FindWindowW(L"NAVI",L"NAVI");
    if (hWnd == (HWND)0x0) break;
    PostMessageW(hWnd,0x10,0,0);
    DVar3 = GetTickCount();
    NKDbgPrintfW(L"\r\n---< %s >--- NNG Still alive == %d [%d]\n","CMicom::PowerOff",uVar2,DVar3);
    Sleep(100);
    bVar1 = uVar2 < 0x14;
    uVar2 = uVar2 + 1;
  } while (bVar1);
  local_68[1] = 4;
  local_68[0] = 4;
  local_70 = 0;
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_6c);
  if (LVar4 != 0) goto LAB_0002325c;
  DVar3 = GetTickCount();
  LVar4 = RegQueryValueExW(local_6c,L"BootSequence",(LPDWORD)0x0,local_68 + 1,(LPBYTE)&local_70,
                           local_68);
  if (LVar4 != 0) {
    local_70 = 0xff;
    NKDbgPrintfW(L"\r\n---< %s >--- ==> Registery is not present.... <==\r\n","CMicom::PowerOff");
  }
  RegCloseKey(local_6c);
  if (local_70 == 0) {
    NKDbgPrintfW(L"\r\n---< %s >--- ==> Kernel loading OK <==\r\n","CMicom::PowerOff");
  }
  else {
    if (local_70 == 1) {
      NKDbgPrintfW(L"\r\n---< %s >--- ==> Kernel loading error %d <==\r\n","CMicom::PowerOff",1);
      lpNewFileName = L"\\Storage Card\\NK.bin";
      pwVar6 = L"\\Storage Card\\NA.bin";
    }
    else {
      if (local_70 != 2) {
        if (local_70 == 3) {
          iVar7 = 3;
          pwVar6 = L"\r\n---< %s >--- ==> NC Kernel loading %d <==\r\n";
        }
        else {
          pwVar6 = L"\r\n---< %s >--- ==> Kernel loading Unknown %d <==\r\n";
          iVar7 = local_70;
        }
        NKDbgPrintfW(pwVar6,"CMicom::PowerOff",iVar7);
        goto LAB_0002323c;
      }
      NKDbgPrintfW(L"\r\n---< %s >--- ==> Kernel loading error %d <==\r\n","CMicom::PowerOff",2);
      pwVar6 = L"\\Storage Card\\NB.bin";
      CopyFileW(L"\\Storage Card\\NB.bin",L"\\Storage Card\\NK.bin",0);
      lpNewFileName = L"\\Storage Card\\NA.bin";
    }
    CopyFileW(pwVar6,lpNewFileName,0);
  }
LAB_0002323c:
  DVar5 = GetTickCount();
  NKDbgPrintfW(L"\r\n---< %s >--- ==> Total Time %d[msec] <==\r\n","CMicom::PowerOff",DVar5 - DVar3)
  ;
LAB_0002325c:
  Sleep(0x96);
  FUN_0001e84c(param_1,0,1,0,1);
  FUN_00015158(DAT_000648e4,0,1,1,0,0,0x96);
  FUN_0001eb18(param_1,0);
  Sleep(100);
  SetSystemPowerState(0,0x200000);
  FUN_0004a3f4(local_30);
  return;
}



/* 00023308 FUN_00023308 */

/* Boundary evidence: original MIPS .pdata 00023308..00023fb7. Semantic name remains unreviewed. */

void FUN_00023308(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  byte bVar2;
  HWND pHVar3;
  LSTATUS LVar4;
  wchar_t *pwVar5;
  int iVar6;
  char *pcVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined4 local_48;
  int local_44;
  int local_40 [4];
  _SYSTEMTIME _Stack_30;
  
  pHVar3 = FindWindowW((LPCWSTR)0x0,L"MgrDab");
  uVar8 = (undefined1)param_3;
  if (param_2 < 0xba) {
    if (param_2 == 0xb9) {
      bVar1 = param_3 == 0;
      if (bVar1) {
        FUN_00036de8(0x78,0);
      }
      else {
        FUN_00036de8(0x77,0);
        FUN_00036de8(0xcf,param_3);
        FUN_0001c334(DAT_000649b8);
      }
      local_48 = (HKEY)(uint)!bVar1;
      DAT_00067fa6 = !bVar1;
      DAT_00067fa5 = (byte)(*(ushort *)(param_1 + 0x84) >> 2) & 1;
      FUN_00036f60();
      FUN_00031fa8();
      FUN_00015158(DAT_000648e4,1,1,7,(int)&local_48,1,0x32);
      FUN_0001660c(DAT_000648ec);
      FUN_00016698(DAT_000648ec);
      if (*(HKEY *)(param_1 + 0x4c) != local_48) {
        bVar2 = 0;
        pHVar3 = FindWindowW((LPCWSTR)0x0,L"MgrDab");
        *(HKEY *)(param_1 + 0x4c) = local_48;
        *(HKEY *)(param_1 + 0x48) = local_48;
        if (local_48 == (HKEY)0x0) {
          if (*(int *)(param_1 + 0x24) == 3) {
            bVar2 = 1;
            FUN_0001a7a0(DAT_000648ec);
          }
          else {
            FUN_00036f08(0x3030105,0);
            FUN_00036e44(0x72,0);
            if (pHVar3 != (HWND)0x0) {
              PostMessageW(pHVar3,0x8064,0x700300,0);
            }
            FUN_00016024(DAT_000648ec);
            if (*(int *)(param_1 + 0x14) == 1) {
              FUN_00016164(DAT_000648ec);
            }
          }
        }
        else {
          bVar2 = 1;
          FUN_00036e44(0x71,param_3);
          FUN_00036f08(0x3030104,0);
          if (pHVar3 != (HWND)0x0) {
            PostMessageW(pHVar3,0x8064,0x700300,1);
          }
          if (*(int *)(param_1 + 0x14) == 1) {
            FUN_00016024(DAT_000648ec);
          }
        }
        FUN_0001cf8c(param_1,(uint)bVar2);
      }
      NKDbgPrintfW(L"\r\nIDM_X_MMCM_FW_UPDATE ==> value : %d, bUpgrade : %d, m_bUpdateStart : %d, m_bEventBlock : %d, m_nPwrState : %d, m_bRearGearDetect : %d\r\n"
                   ,param_3,local_48,*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x48)
                   ,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x14));
      return;
    }
    if (param_2 < 0xb5) {
      if (param_2 != 0xb4) {
        if (param_2 == 0x71) {
          if (param_3 != 0) {
            FUN_00015158(DAT_000648e4,7,1,0,0,0,100);
            return;
          }
          FUN_00015158(DAT_000648e4,7,1,1,0,0,100);
          return;
        }
        if (param_2 != 0x86) {
          if (param_2 == 0x87) {
            FUN_000298d4(DAT_000673c8,1);
            FUN_00025c28();
            PostMessageW((HWND)0xffff,DAT_00064a40,0,0);
            FUN_0001de54(param_1);
            *(undefined4 *)(param_1 + 0x34) = 1;
            local_48 = (HKEY)CONCAT31(local_48._1_3_,1);
            FUN_00014db0(DAT_000648e4,9,0x72,(int)&local_48,1,100);
            return;
          }
          if (param_2 == 0x88) {
            NKDbgPrintfW(L"\r\n==== IDM_X_MMCM_PWR_OFF_CONFIRM :: m_bIsPowerOff - %d ====\r\n",
                         *(undefined4 *)(param_1 + 0x2c));
            if (*(int *)(param_1 + 0x2c) == 1) {
              FUN_00022e64(param_1);
              return;
            }
            return;
          }
          if (param_2 == 0x89) {
            *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb02) = uVar8;
            return;
          }
          return;
        }
        if (2 < *(int *)(param_1 + 0x54)) {
          *(undefined4 *)(param_1 + 0x54) = 2;
        }
        *(undefined1 *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x54) + 0xafa) = uVar8;
        (&DAT_00067680)[*(int *)(param_1 + 0x54)] = uVar8;
        goto LAB_000234a4;
      }
      uVar9 = (uint)(param_3 == 0);
      if ((*(ushort *)(param_1 + 0x84) & 1) == 0) {
        if (uVar9 == 1) {
          uVar9 = 0;
          FUN_0001dfc4(param_1);
        }
        else {
          FUN_00015158(DAT_000648e4,5,1,0x41,0,0,100);
        }
      }
      local_48 = (HKEY)CONCAT31(local_48._1_3_,uVar8);
      if (param_3 != 0) {
        *(ushort *)(param_1 + 0x84) = *(ushort *)(param_1 + 0x84) | 4;
      }
      NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~IDM_X_MMCM_CODE_SUCCESS[%d] m_bIsLocked-%d, bIsLocked-%d, factory-%d, m_nPwrState-%d\r\n"
                   ,param_3,*(undefined4 *)(param_1 + 0x3c),uVar9,*(ushort *)(param_1 + 0x84) & 1,
                   *(undefined4 *)(param_1 + 0x24));
      if (*(uint *)(param_1 + 0x3c) == uVar9) {
        if ((uVar9 != 0) && ((*(ushort *)(param_1 + 0x84) & 1) == 0)) {
          if (*(int *)(param_1 + 0x24) == 1) {
            *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb08) = 0;
            FUN_00016024(DAT_000648ec);
            if (*(int *)(param_1 + 0x14) == 1) {
              FUN_00016164(DAT_000648ec);
            }
            Sleep(100);
            FUN_00036f08(0x3030105,0);
            FUN_00036e44(0x72,0);
            if (pHVar3 != (HWND)0x0) {
              PostMessageW(pHVar3,0x8064,0x700300,0);
            }
            iVar6 = 0;
          }
          else {
            if (*(int *)(param_1 + 0x24) != 3) goto LAB_000236d4;
            *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb08) = 1;
            FUN_00036e44(0x71,0);
            FUN_00036f08(0x3030104,0);
            if (pHVar3 != (HWND)0x0) {
              PostMessageW(pHVar3,0x8064,0x700300,1);
            }
            FUN_0001a7a0(DAT_000648ec);
            iVar6 = 1;
          }
          FUN_0001cf8c(param_1,iVar6);
        }
      }
      else {
        *(uint *)(param_1 + 0x3c) = uVar9;
        FUN_0001d91c(param_1);
      }
LAB_000236d4:
      FUN_00015158(DAT_000648e4,1,1,0x10,(int)&local_48,1,100);
      return;
    }
    if (param_2 == 0xb5) {
      FUN_00035f88(param_1,param_3);
      return;
    }
    if (param_2 == 0xb6) {
      pwVar5 = L"\r\n~!@#$ IDM_X_MMCM_DARKMODE %d\r\n";
      goto LAB_000238a8;
    }
    if (param_2 == 0xb7) {
      NKDbgPrintfW(L"\r\n~!@#$ IDM_X_MMCM_MAINEXCUTE_DONE %d\r\n",*(undefined4 *)(param_1 + 0x48));
      if (*(int *)(param_1 + 0x48) == 1) {
        *(undefined4 *)(param_1 + 0x48) = 0;
        FUN_0002fec8(DAT_000673c8);
        if ((*(int *)(param_1 + 0x24) == 3) || (*(int *)(param_1 + 0x3c) == 1)) {
          pHVar3 = FindWindowW((LPCWSTR)0x0,L"MgrDab");
          FUN_00036e44(0x71,0);
          FUN_00036f08(0x3030104,0);
          if (pHVar3 != (HWND)0x0) {
            PostMessageW(pHVar3,0x8064,0x700300,1);
          }
        }
        else if (DAT_00064a28 != 0) {
          NKDbgPrintfW(L"  \r\n\r\n\r\n  [Micom]  RVC Update  !!!!!!!   \r\n\r\n\r\n");
          DAT_00064a28 = 0;
          FUN_0001d91c(param_1);
        }
        SetTimer(*(HWND *)(param_1 + 4),0x3e9,200,(TIMERPROC)0x0);
        SetTimer(*(HWND *)(param_1 + 4),0x708,0x1c20,(TIMERPROC)0x0);
        return;
      }
      return;
    }
    if (param_2 != 0xb8) {
      return;
    }
    if (param_3 == 0) {
LAB_0002375c:
      local_48 = (HKEY)CONCAT31(local_48._1_3_,1);
    }
    else if (param_3 == 1) {
      local_48 = (HKEY)CONCAT31(local_48._1_3_,2);
    }
    else {
      if (param_3 != 2) goto LAB_0002375c;
      local_48 = (HKEY)CONCAT31(local_48._1_3_,5);
    }
    local_48._0_2_ = CONCAT11(DAT_00067686,(undefined1)local_48);
    FUN_00015158(DAT_000648e4,5,1,0x40,(int)&local_48,2,100);
    pwVar5 = L"\r\n~!@#$ IDM_X_MMCM_SPEED_ALARM %d\r\n";
LAB_000238a8:
    NKDbgPrintfW(pwVar5,param_3);
    return;
  }
  switch(param_2) {
  case 0xba:
    if (param_3 == 0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    else if (param_3 == 1) {
      *(undefined4 *)(param_1 + 0x54) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x54) = 2;
    }
LAB_000234a4:
    FUN_0001de54(param_1);
    return;
  case 0xbb:
    if (((param_3 != 0) && (param_3 != 2)) && (param_3 != 4)) {
      return;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x4c) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x24) != 3) {
      return;
    }
    iVar6 = 1;
    goto LAB_00023c58;
  case 0xbc:
    local_40[0] = -1;
    local_44 = -1;
    local_40[2] = 4;
    local_40[1] = 4;
    LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,(PHKEY)&local_48);
    if (LVar4 == 0) {
      RegQueryValueExW(local_48,L"Manual_Time_Hour",(LPDWORD)0x0,(LPDWORD)(local_40 + 2),
                       (LPBYTE)local_40,(LPDWORD)(local_40 + 1));
      RegQueryValueExW(local_48,L"Manual_Time_Minute",(LPDWORD)0x0,(LPDWORD)(local_40 + 2),
                       (LPBYTE)&local_44,(LPDWORD)(local_40 + 1));
      RegCloseKey(local_48);
      *(undefined4 *)(param_1 + 0x88) = 1;
      if (param_3 == 1000) {
        DAT_00068054 = 0;
      }
      else {
        if (param_3 != 0x3ea) goto LAB_00023db4;
        DAT_00068054 = 2;
        GetLocalTime(&_Stack_30);
        _Stack_30.wMinute = (WORD)local_44;
        _Stack_30.wHour = (WORD)local_40[0];
        iVar6 = local_40[0] * 0x3c + local_44 + 2000;
        FUN_00036de8(0xbc,iVar6);
        NKDbgPrintfW(L"[McmMgr]  MgrMcmPostMessage(IDM_MMCM_AMAIN_USER_TIME_SET, %d)\r\n",iVar6);
      }
      FUN_00024668(1);
    }
LAB_00023db4:
    NKDbgPrintfW(L"\r\n[McmMgr] IDM_X_MMCM_USER_TIME_SET(%d) :: Manual_Time_Hour(%d), Manual_Time_Minute(%d)\r\n"
                 ,param_3,local_40[0],local_44);
    break;
  case 0xc6:
    if (param_3 == 4) {
      FUN_00044948(*(undefined4 *)(param_1 + 4));
      return;
    }
    if (param_3 == 5) {
      FUN_0003a220(*(undefined4 *)(param_1 + 4));
      return;
    }
    if (param_3 == 6) {
      FUN_0003f01c(*(undefined4 *)(param_1 + 4));
      return;
    }
    if (param_3 != 8) {
      return;
    }
    iVar6 = 2;
LAB_00023c58:
    FUN_000213f0(param_1,iVar6);
    break;
  case 199:
    if (param_3 == 0x1234) {
      FUN_0001e574();
      FUN_00024668(0);
      pcVar7 = "\\Storage Card3\\upgrade\\firmware.hex";
    }
    else if (param_3 == 0x1235) {
      pcVar7 = "\\MD\\firmware.hex";
    }
    else {
      if (param_3 != 0x1236) {
        return;
      }
      pcVar7 = "\\MD\\a.hex";
    }
    FUN_00022cfc(param_1,pcVar7);
    uVar9 = 0;
    iVar6 = 0x79;
    goto LAB_00023bc0;
  case 200:
    FUN_00014060(DAT_00064888,uVar8);
    FUN_00014090(DAT_00064888,*(int *)(DAT_00064888 + 0x10),1);
    break;
  case 0xca:
    FUN_00014088(DAT_00064888,uVar8);
    break;
  case 0xce:
    local_48 = (HKEY)((uint)local_48._1_3_ << 8);
    uVar9 = FUN_000153dc(DAT_000648e4,9,0x90,&local_48,1,0x96);
    if (uVar9 == 0) {
      NKDbgPrintfW(L"Getting IGN Start Value is fail\r\n");
      return;
    }
    NKDbgPrintfW(L"%s - IGN changed : %d \r\n","CMicom::OnMessage",(uint)local_48 & 0xff);
    if (*(int *)(param_1 + 0xc) != 0) {
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb00) = (undefined1)local_48;
    }
    uVar9 = (uint)(((uint)local_48 & 4) != 0);
    iVar6 = 0x83;
LAB_00023bc0:
    FUN_00036de8(iVar6,uVar9);
    break;
  case 0xcf:
    if (((param_3 != DAT_000648f0) && (DAT_000648f0 = param_3, param_3 != 0)) &&
       (*(int *)(DAT_000648ec + 0x1c) == 3)) {
      FUN_00016024(DAT_000648ec);
    }
    break;
  case 0xd1:
    *(uint *)(param_1 + 0x34) = (uint)(param_3 != 0);
    local_48 = (HKEY)CONCAT31(local_48._1_3_,param_3 != 0);
    FUN_00014db0(DAT_000648e4,9,0x72,(int)&local_48,1,100);
  }
  return;
}



/* 00023fb8 FUN_00023fb8 */

/* Boundary evidence: original MIPS .pdata 00023fb8..0002430b. Semantic name remains unreviewed. */

void FUN_00023fb8(int param_1)

{
  uint uVar1;
  void *_Dst;
  DWORD DVar2;
  UINT UVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char local_20 [8];
  
  switch(*(undefined4 *)(param_1 + 0x38)) {
  case 0:
    *(undefined4 *)(param_1 + 0x38) = 0;
    FUN_0003006c(param_1);
    break;
  case 1:
    *(undefined4 *)(param_1 + 0x38) = 0;
    FUN_0003006c(param_1);
    FUN_00015158(DAT_000648e4,0,1,0x20,0,0,0xfa);
    *(undefined4 *)(param_1 + 0x2c) = 1;
    local_20[0] = '\0';
    uVar1 = FUN_000153dc(DAT_000648e4,0,0x50,local_20,1,200);
    if ((uVar1 == 1) &&
       (NKDbgPrintfW(L"[[ ====> TIMER_ACC_OFF <==== ]]  state=%d\r\n",local_20[0]),
       local_20[0] == '\x01')) {
      FUN_00015158(DAT_000648e4,0,1,0x20,0,0,0xfa);
    }
    PostMessageW(*(HWND *)(param_1 + 4),0x8064,0x910300,0);
    FUN_00036de8(0x79,0);
    *(undefined4 *)(param_1 + 0x40) = 0;
    uVar5 = 2;
    UVar3 = 5000;
    goto LAB_00024100;
  case 2:
    if (*(uint *)(param_1 + 0x40) < 8) {
      FUN_00036de8(0x79,0);
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = 0;
      FUN_0003006c(param_1);
      FUN_00022e64(param_1);
    }
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x38) = 0;
    FUN_0003006c(param_1);
    FUN_00022e64(param_1);
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x38) = 0;
    FUN_0003006c(param_1);
    iVar6 = *(int *)(param_1 + 0x6c);
    NKDbgPrintfW(L"After set band.... freq=%d\n",iVar6);
    if (*(char *)(*(int *)(param_1 + 0xc) + 4) == '\0') {
      iVar6 = iVar6 * 10;
      pcVar4 = *(code **)(*DAT_000673c8 + 8);
    }
    else {
      pcVar4 = *(code **)(*DAT_000673c8 + 8);
    }
    (*pcVar4)(DAT_000673c8,0x6f,iVar6);
    break;
  case 5:
    FUN_00015158(DAT_000648e4,1,1,0,0,0,100);
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x38) = 0;
    FUN_0003006c(param_1);
    NKDbgPrintfW(L"Restore DTC table to MICOM\n");
    _Dst = malloc(0x2d);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0x10,0x2c);
      DVar2 = FUN_0001e420(param_1,_Dst,0x2c);
      if (DVar2 < 0x2c) {
        NKDbgPrintfW(L"Fail to load DTC table to file - ULC_DTC.tbl\n");
      }
      else {
        FUN_00014db0(DAT_000648e4,0xd,0x2b,(int)_Dst,0x2c,200);
      }
      free(_Dst);
    }
    uVar5 = 5;
    UVar3 = 1000;
LAB_00024100:
    *(undefined4 *)(param_1 + 0x38) = uVar5;
    FUN_00030044(param_1,UVar3);
    break;
  case 7:
    if (DAT_000648ec != 0) {
      *(undefined4 *)(param_1 + 0x38) = 0;
      FUN_0003006c(param_1);
      FUN_0001696c(DAT_000648ec,3,0);
    }
  }
  return;
}



/* 0002430c FUN_0002430c */

/* Boundary evidence: original MIPS .pdata 0002430c..000243db. Semantic name remains unreviewed. */

undefined4 FUN_0002430c(int param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = 0;
  if (param_1 == 0) {
    QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_00064ac0);
    QueryPerformanceCounter((LARGE_INTEGER *)&DAT_00064ab8);
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    QueryPerformanceCounter((LARGE_INTEGER *)&DAT_00064ab0);
    uVar2 = __ll_to_d(DAT_00064ab0 - DAT_00064ab8,
                      (DAT_00064ab4 - DAT_00064abc) - (uint)(DAT_00064ab0 < DAT_00064ab8));
    uVar3 = __ll_to_d(DAT_00064ac0,DAT_00064ac4);
    uVar2 = __dpdiv((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar3,
                    (int)((ulonglong)uVar3 >> 0x20));
    uVar1 = __dptoul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  }
  return uVar1;
}



/* 000243dc FUN_000243dc */

/* Boundary evidence: original MIPS .pdata 000243dc..0002444b. Semantic name remains unreviewed. */

undefined4 FUN_000243dc(int param_1,undefined4 *param_2,size_t param_3)

{
  undefined4 *_Dst;
  undefined4 *_Src;
  
  if (param_1 == 0) {
    _Src = &DAT_00068054;
    _Dst = param_2;
  }
  else {
    if (param_1 != 1) {
      return 0xffffffff;
    }
    _Dst = &DAT_00068054;
    _Src = param_2;
  }
  memcpy(_Dst,_Src,param_3);
  return 0;
}



/* 0002444c FUN_0002444c */

/* Boundary evidence: original MIPS .pdata 0002444c..0002453b. Semantic name remains unreviewed. */

int FUN_0002444c(void)

{
  HANDLE hFile;
  BOOL BVar1;
  int iVar2;
  DWORD aDStack_a0 [2];
  undefined1 auStack_98 [108];
  int local_2c;
  uint local_18;
  
  local_18 = DAT_00064820;
  iVar2 = 0;
  hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    BVar1 = ReadFile(hFile,auStack_98,0x80,aDStack_a0,(LPOVERLAPPED)0x0);
    if (((BVar1 != 0) && (-1 < local_2c)) && (local_2c < 3)) {
      iVar2 = local_2c;
    }
    CloseHandle(hFile);
  }
  NKDbgPrintfW(L"[McmMgr] ReadUserTimeSetting ->> Manual time set: %d \r\n",iVar2);
  FUN_0004a3f4(local_18);
  return iVar2;
}



/* 0002453c FUN_0002453c */

/* Boundary evidence: original MIPS .pdata 0002453c..00024667. Semantic name remains unreviewed. */

uint FUN_0002453c(uint param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  HANDLE hFile;
  BOOL BVar3;
  DWORD DStack_a0;
  DWORD DStack_9c;
  undefined1 auStack_98 [108];
  undefined1 auStack_2c [20];
  uint local_18;
  
  local_18 = DAT_00064820;
  hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    BVar3 = ReadFile(hFile,auStack_98,0x80,&DStack_9c,(LPOVERLAPPED)0x0);
    if (BVar3 != 0) {
      puVar1 = auStack_2c + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_1 >> (3 - uVar2) * 8;
      DAT_00068054 = param_1;
      auStack_2c._0_4_ = param_1;
      SetFilePointer(hFile,0,(PLONG)0x0,0);
      BVar3 = WriteFile(hFile,auStack_98,0x80,&DStack_a0,(LPOVERLAPPED)0x0);
      if (BVar3 == 0) {
        NKDbgPrintfW(L"[%s] write error\r\n","WriteUserTimeSetting");
      }
    }
    CloseHandle(hFile);
  }
  FUN_0004a3f4(local_18);
  return param_1;
}



/* 00024668 FUN_00024668 */

/* Boundary evidence: original MIPS .pdata 00024668..00024877. Semantic name remains unreviewed. */

undefined4 FUN_00024668(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  _SYSTEMTIME _Stack_e8;
  undefined4 local_d8;
  int local_d4;
  _SYSTEMTIME _Stack_d0;
  _TIME_ZONE_INFORMATION local_c0;
  uint local_14;
  
  local_14 = DAT_00064820;
  if (param_1 == 0) {
    GetSystemTime(&_Stack_d0);
    GetLocalTime(&_Stack_e8);
    uVar1 = FUN_0002430c(1);
    if ((((DAT_00064ad8 == 0x7dc) && (DAT_00064ad6 == '\x01')) && (DAT_00064ad3 == '\x01')) ||
       (DAT_00064ad8 == 0)) {
      NKDbgPrintfW(
                  L"[McmMgr]  (g_wRMCYear == 2012 && g_bRMCMonth == 1 && g_bRMCDay == 1) || (g_wRMCYear == 0))\r\n"
                  );
      GetTimeZoneInformation(&local_c0);
      NKDbgPrintfW(L"[McmMgr]  TimeZoneInformation.Bias[%d], TimeZoneInformation.StandardBias[%d] \r\n"
                   ,local_c0.Bias,local_c0.StandardBias);
      iVar4 = ((uint)_Stack_e8.wHour * 0x3c + (uint)_Stack_e8.wMinute + local_c0.Bias) * 0x3c +
              (uint)_Stack_e8.wSecond;
      NKDbgPrintfW(L"[McmMgr]  usStartUtcTime[%d] =((LocalTime.wHour[%d] * 60 * 60) + (LocalTime.wMinute[%d] * 60) + LocalTime.wSecond[%d] ) + (TimeZoneInformation.Bias[%d] * 60))\r\n"
                   ,iVar4,(uint)_Stack_e8.wHour,(uint)_Stack_e8.wMinute,(uint)_Stack_e8.wSecond,
                   local_c0.Bias);
      iVar3 = ((uint)_Stack_e8.wHour * 0x3c + (uint)_Stack_e8.wMinute) * 0x3c +
              (uint)_Stack_e8.wSecond;
      NKDbgPrintfW(L"[McmMgr] =LocalTime= usLocalTime[%d] = (LocalTime.wHour[%d] * 60 * 60) + (LocalTime.wMinute[%d] * 60) + LocalTime.wSecond[%d] \r\n"
                   ,iVar3,(uint)_Stack_e8.wHour,(uint)_Stack_e8.wMinute,(uint)_Stack_e8.wSecond);
    }
    else {
      iVar4 = ((uint)DAT_00064ad0 * 0x3c + (uint)DAT_00064ad1) * 0x3c + (uVar1 & 0xffff) +
              (uint)DAT_00064ad2;
      iVar3 = ((uint)_Stack_e8.wHour * 0x3c + (uint)_Stack_e8.wMinute) * 0x3c +
              (uint)_Stack_e8.wSecond;
    }
    local_d4 = iVar3 - iVar4;
  }
  else {
    local_d4 = 0;
  }
  local_d8 = DAT_00068054;
  NKDbgPrintfW(L"[McmMgr]  userTimeInfo.userTimeSetFlag : %d, userTimeInfo.offset  %d \r\n");
  uVar2 = FUN_000243dc(1,&local_d8,8);
  FUN_0004a3f4(local_14);
  return uVar2;
}



/* 00024878 FUN_00024878 */

/* Boundary evidence: original MIPS .pdata 00024878..0002497f. Semantic name remains unreviewed. */

undefined4 FUN_00024878(char *param_1,undefined1 *param_2,int param_3,int param_4)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  if (((param_1 == (char *)0x0) || (param_2 == (undefined1 *)0x0)) || (param_4 < 1)) {
    NKDbgPrintfW(L"[McmMgr] GetField param error \r\n");
  }
  else {
    iVar4 = 0;
    iVar3 = 0;
    if (param_3 != 0) {
      cVar2 = *param_1;
      do {
        if (cVar2 == '\0') break;
        if (cVar2 == ',') {
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + 1;
        cVar2 = param_1[iVar4];
        if (cVar2 == '\0') goto LAB_00024948;
      } while (iVar3 != param_3);
    }
    pcVar5 = param_1 + iVar4;
    if ((*pcVar5 != ',') && (*pcVar5 != '*')) {
      iVar3 = 0;
      while( true ) {
        cVar2 = *pcVar5;
        if ((cVar2 == '*') || (cVar2 == '\0')) goto LAB_00024954;
        pcVar1 = param_2 + iVar3;
        iVar3 = iVar3 + 1;
        *pcVar1 = cVar2;
        pcVar5 = pcVar5 + 1;
        if (param_4 <= iVar3) break;
        if (*pcVar5 == ',') {
LAB_00024954:
          param_2[iVar3] = 0;
          return 1;
        }
      }
      iVar3 = param_4 + -1;
      goto LAB_00024954;
    }
LAB_00024948:
    *param_2 = 0;
  }
  return 0;
}



/* 00024980 FUN_00024980 */

/* Boundary evidence: original MIPS .pdata 00024980..00024b93. Semantic name remains unreviewed. */

void FUN_00024980(char *param_1)

{
  int iVar1;
  uint uVar2;
  char local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  char local_28;
  undefined1 local_27;
  char local_26;
  undefined1 local_25;
  char local_24;
  undefined1 local_23;
  char local_21;
  undefined1 local_20;
  undefined1 local_1f;
  uint local_c;
  
  local_c = DAT_00064820;
  iVar1 = FUN_00024878(param_1,&local_28,0,0x19);
  if (iVar1 != 0) {
    local_38 = local_28;
    local_37 = local_27;
    local_36 = 0;
    iVar1 = atoi(&local_38);
    DAT_00064ad0 = (undefined1)iVar1;
    local_38 = local_26;
    local_37 = local_25;
    local_36 = 0;
    iVar1 = atoi(&local_38);
    DAT_00064ad1 = (undefined1)iVar1;
    local_38 = local_24;
    local_37 = local_23;
    local_36 = 0;
    iVar1 = atoi(&local_38);
    DAT_00064ad2 = (undefined1)iVar1;
    local_38 = local_21;
    local_37 = local_20;
    local_36 = local_1f;
    local_35 = 0;
    uVar2 = atoi(&local_38);
    DAT_00064ad4 = (undefined2)uVar2;
    if (1000 < (uVar2 & 0xffff)) {
      DAT_00064ad4 = 0;
    }
  }
  FUN_00024878(param_1,&local_28,1,0x19);
  FUN_00024878(param_1,&local_28,2,0x19);
  FUN_00024878(param_1,&local_28,3,0x19);
  FUN_00024878(param_1,&local_28,4,0x19);
  FUN_00024878(param_1,&local_28,5,0x19);
  FUN_00024878(param_1,&local_28,6,0x19);
  FUN_00024878(param_1,&local_28,7,0x19);
  iVar1 = FUN_00024878(param_1,&local_28,8,0x19);
  if (iVar1 != 0) {
    local_38 = local_28;
    local_37 = local_27;
    local_36 = 0;
    iVar1 = atoi(&local_38);
    DAT_00064ad3 = (undefined1)iVar1;
    local_38 = local_26;
    local_37 = local_25;
    local_36 = 0;
    iVar1 = atoi(&local_38);
    DAT_00064ad6 = (undefined1)iVar1;
    local_38 = local_24;
    local_37 = local_23;
    local_36 = 0;
    iVar1 = atoi(&local_38);
    DAT_00064ad8 = (short)iVar1 + 2000;
  }
  FUN_0004a3f4(local_c);
  return;
}



/* 00024b94 FUN_00024b94 */

/* Boundary evidence: original MIPS .pdata 00024b94..0002508f. Semantic name remains unreviewed. */

void FUN_00024b94(uint param_1)

{
  BOOL BVar1;
  DWORD aDStack_128 [2];
  _DCB _Stack_120;
  _COMMTIMEOUTS local_100;
  _DCB _Stack_e8;
  undefined1 local_c8;
  undefined1 local_c7;
  undefined1 local_c6;
  undefined1 local_c5;
  undefined1 local_c4;
  undefined1 local_c3;
  undefined1 local_c2;
  undefined1 local_c1;
  undefined1 local_c0;
  undefined1 local_bf;
  undefined1 local_be;
  undefined1 local_bd;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  undefined1 local_b9;
  undefined1 local_b8;
  undefined1 local_b7;
  undefined1 local_b6;
  undefined1 local_b5;
  undefined1 local_b4;
  undefined1 local_b0;
  undefined1 local_af;
  undefined1 local_ae;
  undefined1 local_ad;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa;
  undefined1 local_a9;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined1 local_a5;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined1 local_a0;
  undefined1 local_9f;
  undefined1 local_9e;
  undefined1 local_9d;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a;
  undefined1 local_99;
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92;
  undefined1 local_91;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined1 local_89;
  undefined1 local_88;
  undefined1 local_87;
  undefined1 local_86;
  undefined1 local_85;
  undefined1 local_80 [88];
  uint local_28;
  
  local_28 = DAT_00064820;
  if (DAT_00063738 == (HANDLE)0xffffffff) {
    DAT_00063738 = CreateFileW(L"COM4:",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (DAT_00063738 == (HANDLE)0xffffffff) goto LAB_00025064;
    local_80[0] = 0xb5;
    local_80[1] = 0x62;
    local_80[2] = 6;
    local_80[3] = 0x3e;
    local_80[4] = 0x24;
    local_80[5] = 0;
    local_80[6] = 0;
    local_80[7] = 0;
    local_80[8] = 0x16;
    local_80[9] = 4;
    local_80[10] = 0;
    local_80[0xb] = 4;
    local_80[0xc] = 0xff;
    local_80[0xd] = 0;
    local_80[0xe] = 1;
    local_80[0xf] = 0;
    local_80[0x10] = 0;
    local_80[0x11] = 1;
    local_80[0x12] = 1;
    local_80[0x13] = 1;
    local_80[0x14] = 3;
    local_80[0x15] = 0;
    local_80[0x16] = 1;
    local_80[0x17] = 0;
    local_80[0x18] = 0;
    local_80[0x19] = 1;
    local_80[0x1a] = 5;
    local_80[0x1b] = 0;
    local_80[0x1c] = 3;
    local_80[0x1d] = 0;
    local_80[0x1e] = 1;
    local_80[0x1f] = 0;
    local_80[0x20] = 0;
    local_80[0x21] = 1;
    local_80[0x22] = 6;
    local_80[0x23] = 8;
    local_80[0x24] = 0xff;
    local_80[0x25] = 0;
    local_80[0x26] = 0;
    local_80[0x27] = 0;
    local_80[0x28] = 0;
    local_80[0x29] = 1;
    local_80[0x2a] = 0xa6;
    local_80[0x2b] = 0x45;
    local_80[0x2c] = 0xb5;
    local_80[0x2d] = 0x62;
    local_80[0x2e] = 6;
    local_80[0x2f] = 0x3e;
    local_80[0x30] = 0x24;
    local_80[0x31] = 0;
    local_80[0x32] = 0;
    local_80[0x33] = 0;
    local_80[0x34] = 0x16;
    local_80[0x35] = 4;
    local_80[0x36] = 0;
    local_80[0x37] = 4;
    local_80[0x38] = 0xff;
    local_80[0x39] = 0;
    local_80[0x3a] = 0;
    local_80[0x3b] = 0;
    local_80[0x3c] = 0;
    local_80[0x3d] = 1;
    local_80[0x3e] = 1;
    local_80[0x3f] = 1;
    local_80[0x40] = 3;
    local_80[0x41] = 0;
    local_80[0x42] = 0;
    local_80[0x43] = 0;
    local_80[0x56] = 0xa4;
    local_b5 = 0x1b;
    local_c5 = 9;
    local_80[0x46] = 5;
    local_a2 = 0x10;
    local_b4 = 0xa9;
    local_80[0x48] = 3;
    local_80[0x57] = 0xd;
    local_c4 = 0xd;
    local_a7 = 3;
    local_9c = 0xfa;
    local_9a = 0xfa;
    local_a1 = 0x27;
    local_80[0x44] = 0;
    local_80[0x45] = 1;
    local_80[0x47] = 0;
    local_80[0x49] = 0;
    local_80[0x4a] = 0;
    local_80[0x4b] = 0;
    local_80[0x4c] = 0;
    local_80[0x4d] = 1;
    local_80[0x4e] = 6;
    local_80[0x4f] = 8;
    local_80[0x50] = 0xff;
    local_80[0x51] = 0;
    local_80[0x52] = 1;
    local_80[0x53] = 0;
    local_80[0x54] = 0;
    local_80[0x55] = 1;
    local_c8 = 0xb5;
    local_c7 = 0x62;
    local_c6 = 6;
    local_c3 = 0;
    local_c2 = 0;
    local_c1 = 0;
    local_c0 = 0;
    local_bf = 0;
    local_be = 0xff;
    local_bd = 0xff;
    local_bc = 0;
    local_bb = 0;
    local_ba = 0;
    local_b9 = 0;
    local_b8 = 0;
    local_b7 = 0;
    local_b6 = 1;
    local_b0 = 0xb5;
    local_af = 0x62;
    local_ae = 6;
    local_ad = 0x24;
    local_ac = 0x24;
    local_ab = 0;
    local_aa = 0xff;
    local_a9 = 0xff;
    local_a8 = 4;
    local_a6 = 0;
    local_a5 = 0;
    local_a4 = 0;
    local_a3 = 0;
    local_a0 = 0;
    local_9f = 0;
    local_9e = 7;
    local_9d = 0;
    local_9b = 0;
    local_99 = 0;
    local_98 = 100;
    local_97 = 0;
    local_96 = 0x2c;
    local_95 = 1;
    local_94 = 0x32;
    local_93 = 0x3c;
    local_92 = 0;
    local_91 = 0xf;
    local_90 = 0;
    local_8f = 0;
    local_8e = 0;
    local_8d = 0;
    local_8c = 0;
    local_8b = 0;
    local_8a = 0;
    local_89 = 0;
    local_88 = 0;
    local_87 = 0;
    local_86 = 0x93;
    local_85 = 0x35;
    GetCommState(DAT_00063738,&_Stack_120);
    memcpy(&_Stack_e8,&_Stack_120,0x1c);
    _Stack_120.BaudRate = 0x2580;
    _Stack_120.fNull = 0;
    _Stack_120.fParity = 0;
    _Stack_120.ByteSize = '\b';
    _Stack_120.Parity = '\0';
    _Stack_120.StopBits = '\0';
    SetCommState(DAT_00063738,&_Stack_120);
    local_100.ReadIntervalTimeout = 2000;
    local_100.ReadTotalTimeoutMultiplier = 3000;
    local_100.ReadTotalTimeoutConstant = 1;
    local_100.WriteTotalTimeoutMultiplier = 0;
    local_100.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(DAT_00063738,&local_100);
    NKDbgPrintfW(L"~~~!!!~~~~ OnSetGPSType() %d\r\n",param_1);
    if (1 < param_1) {
      param_1 = 0;
    }
    BVar1 = WriteFile(DAT_00063738,local_80 + param_1 * 0x2c,0x2c,aDStack_128,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      NKDbgPrintfW(L"[%s] ucSwitchingData write error\r\n","OnSetGPSType");
    }
    BVar1 = WriteFile(DAT_00063738,&local_b0,0x2c,aDStack_128,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      NKDbgPrintfW(L"[%s] ucUBX_CFG_NAV5 write error\r\n","OnSetGPSType");
    }
    BVar1 = WriteFile(DAT_00063738,&local_c8,0x15,aDStack_128,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      NKDbgPrintfW(L"[%s] ucUBX_CFG_CFG write error\r\n","OnSetGPSType");
    }
    SetCommState(DAT_00063738,&_Stack_e8);
    if (DAT_00063738 == (HANDLE)0xffffffff) goto LAB_00025064;
  }
  CloseHandle(DAT_00063738);
  DAT_00063738 = (HANDLE)0xffffffff;
LAB_00025064:
  FUN_0004a3f4(local_28);
  return;
}



/* 00025090 FUN_00025090 */

/* Boundary evidence: original MIPS .pdata 00025090..0002583f. Semantic name remains unreviewed. */

undefined4 FUN_00025090(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  LSTATUS LVar4;
  uint uVar5;
  int iVar6;
  DWORD local_2e8 [2];
  _SYSTEMTIME local_2e0;
  HKEY local_2d0;
  BYTE local_2cc [4];
  int local_2c8 [2];
  int local_2c0;
  int local_2bc;
  _DCB _Stack_2b8;
  _COMMTIMEOUTS local_298;
  _DCB _Stack_280;
  TIME_ZONE_INFORMATION TStack_260;
  char local_1b0;
  char local_1af;
  char local_1ae;
  char local_1ad;
  char local_1ac;
  char acStack_131 [257];
  uint local_30;
  
  local_30 = DAT_00064820;
  DAT_00063738 = CreateFileW(L"COM4:",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (DAT_00063738 != (HANDLE)0xffffffff) {
    GetCommState(DAT_00063738,&_Stack_2b8);
    memcpy(&_Stack_280,&_Stack_2b8,0x1c);
    _Stack_2b8.BaudRate = 0x2580;
    _Stack_2b8.fNull = 0;
    _Stack_2b8.fParity = 0;
    _Stack_2b8.ByteSize = '\b';
    _Stack_2b8.Parity = '\0';
    _Stack_2b8.StopBits = '\0';
    SetCommState(DAT_00063738,&_Stack_2b8);
    local_298.ReadIntervalTimeout = 2000;
    local_298.ReadTotalTimeoutMultiplier = 3000;
    local_298.ReadTotalTimeoutConstant = 1;
    local_298.WriteTotalTimeoutMultiplier = 0;
    local_298.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(DAT_00063738,&local_298);
    local_2e8[0] = 0;
    iVar1 = ReadFile(DAT_00063738,&local_1b0,1,local_2e8,(LPOVERLAPPED)0x0);
    do {
      if ((iVar1 != 1) || (local_2e8[0] != 1)) goto LAB_00025398;
      if (local_1b0 == '$') {
        BVar2 = ReadFile(DAT_00063738,&local_1b0,5,local_2e8,(LPOVERLAPPED)0x0);
        if ((BVar2 != 1) || (local_2e8[0] != 5)) goto LAB_00025398;
        if ((local_1b0 == 'G') &&
           ((((local_1af == 'P' || (local_1af == 'L')) && (local_1ae == 'R')) &&
            ((local_1ad == 'M' && (local_1ac == 'C')))))) {
          BVar2 = ReadFile(DAT_00063738,&local_1b0,1,local_2e8,(LPOVERLAPPED)0x0);
          if ((BVar2 != 1) || (local_2e8[0] != 1)) goto LAB_00025398;
          if (local_1b0 == ',') {
            BVar2 = ReadFile(DAT_00063738,acStack_131 + 1,1,local_2e8,(LPOVERLAPPED)0x0);
            uVar5 = 0;
            if (BVar2 == 1) goto LAB_00025304;
            goto LAB_00025398;
          }
        }
      }
      local_2e8[0] = 0;
      iVar1 = ReadFile(DAT_00063738,&local_1b0,1,local_2e8,(LPOVERLAPPED)0x0);
    } while( true );
  }
LAB_000253c0:
  NKDbgPrintfW(L"[GPS Port Close][%4d:%2d:%2d][%2d:%2d:%2d:%3d] \r\n",DAT_00064ad8,DAT_00064ad6,
               DAT_00064ad3,DAT_00064ad0,DAT_00064ad1,DAT_00064ad2,DAT_00064ad4);
  DAT_00063734 = 0;
  GetSystemTime(&local_2e0);
  local_2cc[0] = '\x01';
  local_2cc[1] = '\0';
  local_2cc[2] = '\0';
  local_2cc[3] = '\0';
  memcpy(&TStack_260,&DAT_00067fa8,0xac);
  if ((((DAT_00064ad0 == 0) && (DAT_00064ad1 == 0)) && (DAT_00064ad2 == 0)) &&
     (((DAT_00064ad3 == 0 && (DAT_00064ad6 == 0)) && (DAT_00064ad8 == 2000)))) {
    DAT_00064ad0 = (byte)DAT_00067ff4;
    DAT_00064ad1 = (byte)DAT_00067ff6;
    DAT_00064ad2 = (byte)DAT_00067ff8;
    DAT_00064ad3 = (byte)DAT_00067ff2;
    DAT_00064ad6 = (byte)DAT_00067fee;
    DAT_00064ad8 = DAT_00067fec;
    local_2cc[0] = '\0';
    local_2cc[1] = '\0';
    local_2cc[2] = '\0';
    local_2cc[3] = '\0';
  }
  else {
    TStack_260.StandardDate.wSecond = (WORD)DAT_00064ad2;
    TStack_260.StandardDate.wYear = DAT_00064ad8;
    TStack_260.StandardDate.wMonth = (WORD)DAT_00064ad6;
    TStack_260.StandardDate.wDay = (WORD)DAT_00064ad3;
    TStack_260.StandardDate.wHour = (WORD)DAT_00064ad0;
    TStack_260.StandardDate.wMinute = (WORD)DAT_00064ad1;
    TStack_260.StandardDate.wMilliseconds = DAT_00064ad4;
  }
  DAT_00064ad4 = TStack_260.StandardDate.wMilliseconds;
  SetTimeZoneInformation(&TStack_260);
  local_2e0.wDay = (WORD)DAT_00064ad3;
  local_2e0.wMonth = (WORD)DAT_00064ad6;
  if (((DAT_00064ad3 == 0) && (DAT_00064ad6 == 0)) && (DAT_00064ad8 == 2000)) {
    DAT_00064ad8 = 0x7df;
    DAT_00064ad6 = 0xb;
    DAT_00064ad3 = 2;
    NKDbgPrintfW(L"[McmMgr]  if(g_bRMCDay == 0 || g_bRMCMonth == 0 || g_wRMCYear == 0) \r\n");
    local_2e0.wDay = (WORD)DAT_00064ad3;
    local_2e0.wMonth = (WORD)DAT_00064ad6;
  }
  local_2e0.wHour = (WORD)DAT_00064ad0;
  local_2e0.wMinute = (WORD)DAT_00064ad1;
  local_2e0.wSecond = (WORD)DAT_00064ad2;
  local_2e0.wMilliseconds = DAT_00064ad4;
  local_2e0.wYear = DAT_00064ad8;
  NKDbgPrintfW(L"[SysClock]   Hour [%d]  Min [%d]  Sec [%d] \r\n[SysClock]   Hour [%d]  Min [%d]  Sec [%d][%d] \r\n"
               ,DAT_00067ff4,DAT_00067ff6,DAT_00067ff8,DAT_00064ad0,DAT_00064ad1,DAT_00064ad2,
               DAT_00064ad4);
  SetSystemTime(&local_2e0);
  FUN_000243dc(0,&local_2c0,8);
  if (local_2c0 != 0) {
    iVar6 = ((uint)DAT_00064ad0 * 0x3c + (uint)DAT_00064ad1) * 0x3c + (uint)DAT_00064ad2;
    iVar1 = local_2bc + iVar6;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x15180;
      NKDbgPrintfW(L"[McmMgr]  sSystemTime = sSystemTime + (1440 * 60) \r\n");
    }
    local_2e0.wHour = (WORD)(iVar1 / 0xe10);
    if (0x17 < (iVar1 / 0xe10 & 0xffffU)) {
      local_2e0.wHour = local_2e0.wHour - 0x18;
    }
    local_2e0.wMinute = (WORD)((iVar1 / 0x3c) % 0x3c);
    BVar2 = SetLocalTime(&local_2e0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[McmMgr]  SetLocalTime FAIL -> [%d] \r\n",DVar3);
    }
    NKDbgPrintfW(L"[McmMgr]  UTC time-> %2d:%2d, UTCTime(%d), userTimeInfo.offset(%d) system Local time -> %d:%d:%d:%d \r\n"
                 ,DAT_00064ad0,DAT_00064ad1,iVar6,local_2bc,local_2e0.wHour,local_2e0.wMinute,
                 local_2e0.wSecond,local_2e0.wMilliseconds);
  }
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_2d0);
  if (LVar4 == 0) {
    local_2c8[0] = FUN_0002444c();
    RegSetValueExW(local_2d0,L"ManualTimeSet",0,4,(BYTE *)local_2c8,4);
    RegSetValueExW(local_2d0,L"RECV_TIME_FROM_GPS",0,4,local_2cc,4);
    RegCloseKey(local_2d0);
  }
  NKDbgPrintfW(L"\r\n================== [%d] ==================\r\n",local_2c0);
  NKDbgPrintfW(L"[RTC Date] %04d:%02d:%02d \r\n",local_2e0.wYear,local_2e0.wMonth,local_2e0.wDay);
  NKDbgPrintfW(L"[RTC Time] %02d:%02d:%02d:%03d \r\n",local_2e0.wHour,local_2e0.wMinute,
               local_2e0.wSecond,local_2e0.wMilliseconds);
  NKDbgPrintfW(L"=========================================\r\n\r\n");
  FUN_0004a3f4(local_30);
  return 0;
LAB_00025304:
  if (local_2e8[0] != 1) goto LAB_00025398;
  if (((uVar5 != 0) && (acStack_131[uVar5] == '\r')) && (acStack_131[uVar5 + 1] == '\n')) {
    FUN_00024980(acStack_131 + 1);
    FUN_0002430c(0);
    goto LAB_00025398;
  }
  if ((0x100 < uVar5 + 1) ||
     (BVar2 = ReadFile(DAT_00063738,acStack_131 + uVar5 + 2,1,local_2e8,(LPOVERLAPPED)0x0),
     uVar5 = uVar5 + 1, BVar2 != 1)) goto LAB_00025398;
  goto LAB_00025304;
LAB_00025398:
  if (DAT_00063738 != (HANDLE)0xffffffff) {
    SetCommState(DAT_00063738,&_Stack_280);
    CloseHandle(DAT_00063738);
    DAT_00063738 = (HANDLE)0xffffffff;
  }
  goto LAB_000253c0;
}



/* 00025840 FUN_00025840 */

/* Boundary evidence: original MIPS .pdata 00025840..000258b7. Semantic name remains unreviewed. */

size_t FUN_00025840(wchar_t *param_1,LPSTR param_2)

{
  size_t cbMultiByte;
  
  cbMultiByte = 0;
  if (param_2 != (LPSTR)0x0) {
    cbMultiByte = wcslen(param_1);
    WideCharToMultiByte(0,0,param_1,-1,param_2,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  return cbMultiByte;
}



/* 000258b8 FUN_000258b8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 000258b8..00025c27. Semantic name remains unreviewed. */

void FUN_000258b8(void)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    FUN_0003220c(0,uVar3);
    FUN_0003220c(1,uVar3);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xc);
  uVar3 = 0;
  do {
    FUN_000323f8(0,uVar3);
    FUN_000323f8(1,uVar3);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x24);
  *(byte *)(DAT_00064ae4 + 4) = (byte)(DAT_00067678 >> 0xc) & 3;
  *(undefined1 *)(DAT_00064ae4 + 0xa93) = (&DAT_0006768c)[(DAT_00067678 >> 0xc & 3) * 0x48c];
  uVar3 = DAT_00067678 >> 0xc & 3;
  if ((DAT_00067678 & 4) == 4) {
    uVar3 = (uint)(ushort)(&DAT_00067690)[uVar3 * 0x246];
    if (uVar3 == 0) {
      *(undefined4 *)(DAT_00064ae4 + 8) = 0;
    }
    else {
      iVar1 = FUN_00030ec0(DAT_00067670,uVar3);
      *(int *)(DAT_00064ae4 + 8) = iVar1;
    }
    if (*(int *)(DAT_00064ae4 + 8) == 0) {
      *(undefined4 *)(DAT_00064ae4 + 8) = (&DAT_00067694)[(DAT_00067678 >> 0xc & 3) * 0x123];
    }
    FUN_00030e3c(DAT_00067670,uVar3,(undefined4 *)(DAT_00064ae4 + 0xa97));
  }
  else {
    *(undefined4 *)(DAT_00064ae4 + 8) = (&DAT_00067694)[uVar3 * 0x123];
    *(undefined1 *)(DAT_00064ae4 + 0xa97) = 0;
  }
  *(bool *)(DAT_00064ae4 + 0xa8c) = (DAT_00067678 & 4) == 4;
  *(bool *)(DAT_00064ae4 + 0xa8d) = (DAT_00067678 & 0x10) == 0x10;
  *(bool *)(DAT_00064ae4 + 0xa8e) = (DAT_00067678 & 0x20) == 0x20;
  *(bool *)(DAT_00064ae4 + 0xa8f) = (DAT_00067678 & 0x40) == 0x40;
  *(bool *)(DAT_00064ae4 + 0xa90) = (DAT_00067678 & 0x80) == 0x80;
  *(undefined1 *)(DAT_00064ae4 + 0xaec) = 9;
  *(byte *)(DAT_00064ae4 + 0xaf3) = (byte)(DAT_00067678 >> 8) & 7;
  *(undefined1 *)(DAT_00064ae4 + 0xaee) = DAT_00067683;
  *(undefined1 *)(DAT_00064ae4 + 0xaef) = DAT_00067684;
  *(undefined1 *)(DAT_00064ae4 + 0xaf0) = DAT_00067685;
  *(undefined1 *)(DAT_00064ae4 + 0xaf1) = DAT_00067686;
  *(undefined1 *)(DAT_00064ae4 + 0xaf2) = DAT_00067687;
  *(byte *)(DAT_00064ae4 + 0xaf9) = (byte)(DAT_00067678 >> 0xb) & 1;
  *(char *)(DAT_00064ae4 + 0xaf5) = (char)_DAT_0006767c;
  *(undefined1 *)(DAT_00064ae4 + 0xaf4) = DAT_00067678._3_1_;
  *(undefined1 *)(DAT_00064ae4 + 0xaf6) = DAT_0006767d;
  uVar3 = 0;
  *(undefined1 *)(DAT_00064ae4 + 0xaf7) = DAT_0006767e;
  *(undefined1 *)(DAT_00064ae4 + 0xaf8) = DAT_0006767f;
  do {
    pbVar2 = &DAT_00067680 + uVar3;
    if (2 < *pbVar2) {
      *pbVar2 = 2;
    }
    iVar1 = DAT_00064ae4 + uVar3;
    uVar3 = uVar3 + 1;
    *(byte *)(iVar1 + 0xafa) = *pbVar2;
  } while (uVar3 < 3);
  *(byte *)(DAT_00064ae4 + 0xb02) = (byte)(DAT_00067678 >> 0xe) & 1;
  return;
}



/* 00025c28 FUN_00025c28 */

/* Boundary evidence: original MIPS .pdata 00025c28..00025cab. Semantic name remains unreviewed. */

void FUN_00025c28(void)

{
  FUN_0002c050((int)DAT_000673c8);
  FUN_00031d3c();
  (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x81,(DAT_00067678 & 4) == 4);
  FUN_000258b8();
  FUN_0002ffa4((int)DAT_000673c8);
  FUN_00012848(DAT_00064828);
  return;
}



/* 00025cac FUN_00025cac */

/* Boundary evidence: original MIPS .pdata 00025cac..00025e1b. Semantic name remains unreviewed. */

undefined4 FUN_00025cac(HWND param_1)

{
  uint *puVar1;
  int iVar2;
  UINT Msg;
  uint uVar3;
  WPARAM wParam;
  uint uVar4;
  
joined_r0x00025cdc:
  while( true ) {
    do {
      if (DAT_00064aec == 0) {
        return 0;
      }
      puVar1 = (uint *)FUN_00028a0c(0x64be8);
      iVar2 = FUN_0002863c((undefined4 *)&DAT_00064b44,(byte *)puVar1);
    } while (iVar2 != 1);
    uVar4 = *puVar1;
    uVar3 = uVar4 & 0xff;
    if (uVar3 != 0xa6) break;
LAB_00025d84:
    EventModify(*(undefined4 *)(DAT_000648e4 + 0xc),3);
  }
  if (uVar3 == 0xaa) {
    if ((uVar4 & 0xf00) == 0xd00) {
      FUN_000288e4(0x64b44,puVar1);
      goto LAB_00025d84;
    }
    iVar2 = FUN_00028a28(0x64be8);
    if (iVar2 == 0) {
      NKDbgPrintfW(L"%S : Q Push Error(0x%02X, 0x%02X)\r\n","CommandThread",*puVar1 >> 8 & 0xf,
                   *(undefined1 *)((int)puVar1 + 2));
    }
    wParam = 0;
    Msg = 0x401;
  }
  else {
    if (uVar3 != 0xab) goto joined_r0x00025cdc;
    wParam = uVar4 & 0xff;
    Msg = 0x402;
  }
  PostMessageW(param_1,Msg,wParam,0);
  goto joined_r0x00025cdc;
}



/* 00025e1c FUN_00025e1c */

/* Boundary evidence: original MIPS .pdata 00025e1c..00025eef. Semantic name remains unreviewed. */

void FUN_00025e1c(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  HWND hWnd;
  uint uVar1;
  ushort local_18 [4];
  
  if ((param_2 == 0x113) && (param_3 == 1000)) {
    local_18[0] = 0;
    hWnd = FindWindowW(L"NAVI",(LPCWSTR)0x0);
    if ((DAT_000648e4 != 0) && (hWnd != (HWND)0x0)) {
      uVar1 = FUN_000153dc(DAT_000648e4,9,4,local_18,2,0x96);
      if (uVar1 == 2) {
        if (DAT_00064a24 != 0) {
          FUN_0001e814(DAT_00064a24,local_18[0]);
        }
        PostMessageW(hWnd,DAT_00064af4,0x7d9,(uint)local_18[0] << 0x10 | param_4 & 0xffff);
      }
    }
  }
  return;
}



/* 00025ef0 FUN_00025ef0 */

/* Boundary evidence: original MIPS .pdata 00025ef0..00027b77. Semantic name remains unreviewed. */

LRESULT FUN_00025ef0(HWND param_1,uint param_2,char *param_3,char *param_4)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  bool bVar3;
  undefined3 extraout_var;
  BOOL BVar4;
  undefined3 extraout_var_00;
  HDC pHVar5;
  DWORD DVar6;
  HANDLE pvVar7;
  LSTATUS LVar8;
  size_t sVar9;
  size_t sVar10;
  int iVar11;
  HWND hWnd;
  LRESULT LVar12;
  undefined4 *puVar13;
  wchar_t *pwVar14;
  int *piVar15;
  UINT_PTR uIDEvent;
  byte bVar16;
  code *pcVar17;
  uint uVar18;
  undefined4 **ppuVar19;
  int *piVar20;
  int iVar21;
  undefined1 local_680;
  char local_67f [3];
  undefined4 *local_67c;
  FILE *local_678;
  byte local_674;
  undefined1 local_673;
  byte local_672;
  byte local_671;
  undefined1 local_670 [4];
  HKEY local_66c;
  HKEY local_668;
  ushort local_664;
  char local_662;
  char local_661;
  char local_660;
  undefined1 local_65e;
  undefined1 local_65d;
  undefined1 local_65c;
  DWORD local_658 [2];
  _PROCESS_INFORMATION local_650;
  tagPAINTSTRUCT tStack_640;
  undefined1 local_600;
  undefined1 local_5ff;
  undefined1 local_5fe;
  undefined1 local_5fd;
  undefined1 local_5fc;
  undefined1 local_5fb;
  undefined1 local_5fa;
  undefined1 local_5f9;
  undefined1 local_5f8;
  undefined1 local_5f7;
  undefined1 local_5f6;
  undefined1 local_5f5;
  undefined1 local_5f4;
  undefined1 local_5f3;
  undefined1 local_5f2;
  undefined1 local_5f1;
  undefined1 local_5f0;
  undefined1 local_5ef;
  undefined1 local_5ee;
  undefined1 local_5ed;
  undefined1 local_5ec;
  undefined1 local_5eb;
  undefined1 local_5ea;
  undefined1 local_5e9;
  undefined1 local_5e8;
  undefined1 local_5e7;
  undefined1 local_5e6;
  undefined1 local_5e5;
  undefined1 local_5e4;
  undefined4 local_5e3;
  undefined1 local_5df;
  undefined1 local_5de;
  undefined4 local_5d8;
  undefined1 local_5d4;
  undefined1 local_5d3;
  char acStack_5d0 [32];
  BYTE aBStack_5b0 [8];
  char acStack_5a8 [32];
  WCHAR aWStack_588 [32];
  char local_548 [2];
  char local_546;
  char local_544;
  wchar_t local_440;
  undefined1 auStack_43e [518];
  wchar_t awStack_238 [260];
  uint local_30;
  
  puVar1 = DAT_00064ae8;
  local_30 = DAT_00064820;
  iVar21 = 1;
  bVar16 = (byte)param_4;
  if (param_2 < 0x203) {
    if (param_2 == 0x202) {
      if (DAT_000648ec != (undefined4 *)0x0) {
        FUN_00016b48((int)DAT_000648ec,param_3,(uint)param_4);
      }
      goto LAB_00027b34;
    }
    if (param_2 == 1) {
      DAT_00064adc = CreateFileMappingW((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,4,0,0xb70,
                                        L"MgrMcmShm");
      if (DAT_00064adc != (HANDLE)0x0) {
        DAT_00064ae4 = MapViewOfFile(DAT_00064adc,0xf001f,0,0,0);
        if (DAT_00064ae4 == (LPVOID)0x0) {
          DVar6 = GetLastError();
          NKDbgPrintfW(L"%S lpName=%s, MapViewOfFile fail, error=%d\r\n","WndProc",L"MgrMcmShm",
                       DVar6);
          CloseHandle(DAT_00064adc);
          DAT_00064adc = (HANDLE)0x0;
          DAT_00064ae4 = (LPCVOID)0x0;
        }
        else {
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x8c);
          if (local_67c == (undefined4 *)0x0) {
            DAT_00067670 = (undefined1 *)0x0;
          }
          else {
            DAT_00067670 = FUN_00031ad4((undefined1 *)local_67c);
          }
          FUN_000258b8();
          DAT_00064ae0 = CreateFileMappingW((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,4,0,0x1c,
                                            L"ShmFmMgrDABDsiInfo");
          if (DAT_00064ae0 == (HANDLE)0x0) {
            DVar6 = GetLastError();
            NKDbgPrintfW(L"%S lpName=%s, CreateFileMapping fail, error=%d\r\n","WndProc",
                         L"ShmFmMgrDABDsiInfo",DVar6);
          }
          else {
            DAT_00064ae8 = MapViewOfFile(DAT_00064ae0,4,0,0,0);
            if (DAT_00064ae8 == (undefined1 *)0x0) {
              DVar6 = GetLastError();
              NKDbgPrintfW(L"%S lpName=%s, MapViewOfFile fail, error=%d\r\n","WndProc",
                           L"ShmFmMgrDABDsiInfo",DVar6);
              CloseHandle(DAT_00064ae0);
              DAT_00064ae0 = (HANDLE)0x0;
            }
          }
          pvVar7 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00025cac,param_1,4,(LPDWORD)0x0);
          if (pvVar7 != (HANDLE)0x0) {
            DAT_00064aec = 1;
            iVar21 = CeSetThreadPriority(pvVar7,0x80);
            if (iVar21 == 0) {
              DVar6 = GetLastError();
              NKDbgPrintfW(L"%S CeSetThreadPriority failed, error=%d\r\n","WndProc",DVar6);
              SetThreadPriority(pvVar7,0);
            }
            ResumeThread(pvVar7);
            CloseHandle(pvVar7);
          }
          LVar8 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_668);
          if (LVar8 == 0) {
            local_678 = (FILE *)0x0;
            sprintf_s(acStack_5d0,0x20,"\\mgrmcm %d.%d.%d.%s.ver",7,0,5,&DAT_00057ba4);
            fopen_s(&local_678,acStack_5d0,"wt");
            if (local_678 != (FILE *)0x0) {
              fclose(local_678);
              local_678 = (FILE *)0x0;
            }
            wsprintfW(aWStack_588,L"%d.%d.%d.%s",7,0,5,L"0220");
            sVar9 = wcslen(aWStack_588);
            RegSetValueExW(local_668,L"VerMgrMcm",0,1,(BYTE *)aWStack_588,sVar9 << 1);
            sprintf_s(acStack_5a8,0x20,"\\voconsse ");
            sprintf_s(acStack_5d0,0x20,"\\ec ");
            sVar9 = strlen(acStack_5a8);
            sVar10 = strlen(acStack_5d0);
            GetECVersion(acStack_5d0 + sVar10,0x18,acStack_5a8 + sVar9,0x10);
            sVar9 = strlen(acStack_5d0);
            sprintf_s(acStack_5d0 + sVar9,5,".ver");
            sVar9 = strlen(acStack_5a8);
            sprintf_s(acStack_5a8 + sVar9,5,".ver");
            fopen_s(&local_678,acStack_5d0,"wt");
            if (local_678 != (FILE *)0x0) {
              fclose(local_678);
              local_678 = (FILE *)0x0;
            }
            fopen_s(&local_678,acStack_5a8,"wt");
            if (local_678 != (FILE *)0x0) {
              fclose(local_678);
              local_678 = (FILE *)0x0;
            }
            GetECVersion(acStack_5d0,0x20,acStack_5a8,0x10);
            wsprintfW(aWStack_588,L"%S",acStack_5d0);
            sVar9 = wcslen(aWStack_588);
            RegSetValueExW(local_668,L"VerEC",0,1,(BYTE *)aWStack_588,sVar9 << 1);
            wsprintfW(aWStack_588,L"%S",acStack_5a8);
            sVar9 = wcslen(aWStack_588);
            RegSetValueExW(local_668,L"VerVoConSSE",0,1,(BYTE *)aWStack_588,sVar9 << 1);
            sprintf_s(acStack_5d0,0x20,"\\rvc ");
            sVar9 = strlen(acStack_5d0);
            GetRVDVersion(acStack_5d0 + sVar9,0x18);
            sVar9 = strlen(acStack_5d0);
            sprintf_s(acStack_5d0 + sVar9,5,".ver");
            fopen_s(&local_678,acStack_5d0,"wt");
            if (local_678 != (FILE *)0x0) {
              fclose(local_678);
              local_678 = (FILE *)0x0;
            }
            GetRVDVersion(acStack_5d0,0x20);
            wsprintfW(aWStack_588,L"%S",acStack_5d0);
            sVar9 = wcslen(aWStack_588);
            RegSetValueExW(local_668,L"VerRVC",0,1,(BYTE *)aWStack_588,sVar9 << 1);
            RegCloseKey(local_668);
          }
          local_440 = L'\0';
          memset(auStack_43e,0,0x206);
          swprintf(&local_440,0x57ab4,L"MGRMCM",L"2016-02-20",L"17230");
          pvVar7 = CreateFileW(&local_440,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0
                              );
          if (pvVar7 != (HANDLE)0xffffffff) {
            CloseHandle(pvVar7);
          }
          Sleep(100);
          NKDbgPrintfW(L"%S : Start MicomManager\r\n","WndProc");
          local_67c = (undefined4 *)__2_YAPAXI_Z(200);
          if (local_67c == (undefined4 *)0x0) {
            DAT_000648e4 = (undefined4 *)0x0;
          }
          else {
            DAT_000648e4 = FUN_00014b94(local_67c,param_1,10);
          }
          DAT_00064a88 = DAT_000648e4;
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x48);
          if (local_67c == (undefined4 *)0x0) {
            DAT_000648ec = (undefined4 *)0x0;
          }
          else {
            DAT_000648ec = FUN_00015a08(local_67c,DAT_00064aac,param_1,0xb,DAT_00064ae4);
          }
          DAT_00064a8c = DAT_000648ec;
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x90);
          if (local_67c == (undefined4 *)0x0) {
            DAT_00064a24 = (int *)0x0;
          }
          else {
            DAT_00064a24 = FUN_0001f2c4(local_67c,param_1,0xc,DAT_00064ae4);
          }
          DAT_00064a90 = DAT_00064a24;
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x68);
          if (local_67c == (undefined4 *)0x0) {
            DAT_00064828 = (undefined4 *)0x0;
          }
          else {
            DAT_00064828 = FUN_00011000(local_67c,param_1,0xd,DAT_00064ae4);
          }
          DAT_00064a94 = DAT_00064828;
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x2a0);
          if (local_67c == (undefined4 *)0x0) {
            DAT_00064a98 = (undefined4 *)0x0;
          }
          else {
            DAT_00064a98 = FUN_00028ad8(local_67c,param_1,0xe,DAT_00064ae4);
          }
          DAT_000673c8 = DAT_00064a98;
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x54);
          if (local_67c == (undefined4 *)0x0) {
            DAT_00064888 = (undefined4 *)0x0;
          }
          else {
            DAT_00064888 = FUN_00013cac(local_67c,param_1,0xf,DAT_00064ae4);
          }
          DAT_00064a9c = DAT_00064888;
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x70);
          if (local_67c == (undefined4 *)0x0) {
            DAT_000649b8 = (undefined4 *)0x0;
          }
          else {
            DAT_000649b8 = FUN_0001c89c(local_67c,param_1,0x10,(int)DAT_00064ae4);
          }
          DAT_00064aa0 = DAT_000649b8;
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x18);
          if (local_67c == (undefined4 *)0x0) {
            DAT_00064aa4 = (undefined4 *)0x0;
          }
          else {
            DAT_00064aa4 = FUN_00033db4(local_67c,param_1,0x11,DAT_00064ae4);
          }
          DAT_00068464 = DAT_00064aa4;
          local_67c = (undefined4 *)__2_YAPAXI_Z(0x10);
          if (local_67c == (undefined4 *)0x0) {
            DAT_00064aa8 = (undefined4 *)0x0;
          }
          else {
            DAT_00064aa8 = FUN_00030114(local_67c,param_1,0x12,DAT_00064ae4);
          }
          DAT_000673f4 = DAT_00064aa8;
          SetTimer(param_1,1,1000,(TIMERPROC)0x0);
          if (DAT_000648ec != (undefined4 *)0x0) {
            FUN_00016c44((int)DAT_000648ec);
          }
          SetWindowPos(param_1,(HWND)0x1,-10,-10,10,10,0x80);
        }
        goto LAB_00027b34;
      }
      DVar6 = GetLastError();
      param_4 = "WndProc";
      NKDbgPrintfW(L"%S lpName=%s, CreateFileMapping fail, error=%d\r\n","WndProc",L"MgrMcmShm",
                   DVar6);
      if (DVar6 != 0xb7) goto LAB_00027b34;
      pwVar14 = L"%S has already been made";
      goto LAB_000272bc;
    }
    if (param_2 == 2) {
      KillTimer(param_1,1);
      KillTimer(param_1,0x3e9);
      KillTimer(param_1,2);
      KillTimer(param_1,0x709);
      KillTimer(param_1,0x708);
      KillTimer(param_1,0x70c);
      KillTimer(param_1,0x70e);
      KillTimer(param_1,0x70d);
      KillTimer(param_1,0x76c);
      DAT_00064aec = 0;
      FUN_00016d7c((int)DAT_000648ec);
      uVar18 = 0;
      do {
        piVar20 = (int *)((int)&DAT_00064a88 + uVar18);
        puVar13 = (undefined4 *)*piVar20;
        if (puVar13 != (undefined4 *)0x0) {
          (**(code **)*puVar13)(puVar13,1);
        }
        uVar18 = uVar18 + 4;
        *piVar20 = 0;
      } while (uVar18 < 0x24);
      Sleep(0x32);
      FUN_00028300((undefined4 *)&DAT_00064b44);
      if (DAT_00064ae4 != (LPCVOID)0x0) {
        UnmapViewOfFile(DAT_00064ae4);
      }
      if (DAT_00064adc != (HANDLE)0x0) {
        CloseHandle(DAT_00064adc);
      }
      if (DAT_00064ae8 != (undefined1 *)0x0) {
        UnmapViewOfFile(DAT_00064ae4);
      }
      if (DAT_00064ae0 != (HANDLE)0x0) {
        CloseHandle(DAT_00064ae0);
      }
      PostQuitMessage(0);
      goto LAB_00027b34;
    }
    if (param_2 == 0xf) {
      pHVar5 = BeginPaint(param_1,&tStack_640);
      if (DAT_000648ec != (undefined4 *)0x0) {
        FUN_0001a8dc((int)DAT_000648ec,pHVar5);
      }
      EndPaint(param_1,&tStack_640);
      goto LAB_00027b34;
    }
    if (param_2 != 0x113) {
      if (param_2 == 0x201) {
        if (DAT_000648ec != (undefined4 *)0x0) {
          FUN_00016aa0((int)DAT_000648ec,param_3,(uint)param_4);
        }
        goto LAB_00027b34;
      }
      goto LAB_00027154;
    }
    if (param_3 == (char *)0x1) {
      FUN_00015158((int)DAT_000648e4,1,1,0xff,0,0,100);
      goto LAB_00027b34;
    }
    if (param_3 == (char *)0x3e9) {
      if (DAT_000648e4 == (undefined4 *)0x0) goto LAB_00027b34;
      FUN_00015158((int)DAT_000648e4,1,1,0xb,0,0,100);
      FUN_00015158((int)DAT_000648e4,1,1,0xe,0,0,100);
      uIDEvent = 0x3e9;
      goto LAB_000265a0;
    }
    if (param_3 == (char *)0x2) {
      KillTimer(param_1,2);
      DAT_00064a24[0x16] = 0;
      FUN_0001e5cc((int)DAT_00064a24);
      goto LAB_00027b34;
    }
    if (param_3 != (char *)0x708) {
      if (param_3 == (char *)0x709) {
        if (DAT_00064888 != (undefined4 *)0x0) {
          FUN_00014a50((int)DAT_00064888);
        }
        goto LAB_00027b34;
      }
      if (param_3 == (char *)0x70a) {
        KillTimer(param_1,0x70a);
        if (DAT_00064a24 != (int *)0x0) {
          FUN_0001e698((int)DAT_00064a24);
        }
        goto LAB_00027b34;
      }
      if ((param_3 == (char *)0x70c) || (param_3 == (char *)0x70e)) {
        if (DAT_00064ae8 == (undefined1 *)0x0) goto LAB_00027b34;
        local_600 = 0;
        memset(&local_5ff,0,0x1b);
        local_600 = *puVar1;
        local_5ff = puVar1[2];
        local_5fe = puVar1[1];
        local_5fd = puVar1[4];
        local_5fc = puVar1[3];
        local_5fb = puVar1[5];
        local_5fa = puVar1[6];
        local_5f9 = puVar1[7];
        local_5f8 = puVar1[8];
        local_5f7 = puVar1[9];
        local_5f6 = puVar1[10];
        local_5f5 = puVar1[0xb];
        local_5f4 = puVar1[0xc];
        local_5f3 = puVar1[0xd];
        local_5f2 = puVar1[0xe];
        local_5f1 = puVar1[0xf];
        local_5f0 = puVar1[0x10];
        local_5ef = puVar1[0x11];
        local_5ee = puVar1[0x13];
        local_5ed = puVar1[0x12];
        local_5ec = puVar1[0x17];
        local_5eb = puVar1[0x16];
        local_5ea = puVar1[0x15];
        local_5e9 = (undefined1)*(undefined4 *)(puVar1 + 0x14);
        local_5e8 = puVar1[0x19];
        local_5e7 = puVar1[0x18];
        local_5e6 = puVar1[0x1a];
        local_5e5 = puVar1[0x1b];
        FUN_00014db0((int)DAT_000648e4,0xd,0x1a,(int)&local_600,0x1c,500);
        if (param_3 != (char *)0x70c) {
          KillTimer(param_1,0x70e);
          if (DAT_00064a24 == (int *)0x0) goto LAB_00027b34;
          uVar18 = 0xf20000;
          goto LAB_000265cc;
        }
        uIDEvent = 0x70c;
LAB_000265a0:
        KillTimer(param_1,uIDEvent);
        goto LAB_00027b34;
      }
      if (param_3 == (char *)0x70f) {
        local_650.hProcess = (HANDLE)0x0;
        memset(&local_650.hThread,0,0xc);
        NKDbgPrintfW(L"~~ WM_TIMER TIMER_DAB_RESTART \r\n");
        BVar4 = CreateProcessW(L"\\Storage Card\\System\\MgrDab.exe",L"er10q4c$=4G2g-H2tq9X@mid",
                               (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0
                               ,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,&local_650);
        if (BVar4 != 0) {
          CloseHandle(local_650.hProcess);
          CloseHandle(local_650.hThread);
          uIDEvent = 0x70f;
          goto LAB_000265a0;
        }
        param_4 = (char *)GetLastError();
        pwVar14 = L"MgrDab.exe did not excute!![0x%08X]\r\n";
      }
      else {
        if (param_3 == (char *)0x70d) {
          FUN_00036f08(0x1100501,0);
          FUN_00036f08(0x1100601,0);
          goto LAB_00027b34;
        }
        if (param_3 == (char *)0x70b) {
          KillTimer(param_1,0x70b);
          FUN_0001c570((int)DAT_000649b8);
          goto LAB_00027b34;
        }
        if (param_3 != (char *)0x76c) {
          uVar18 = 0;
          ppuVar19 = &DAT_00064a88;
          do {
            if ((*ppuVar19 != (undefined4 *)0x0) &&
               (bVar3 = FUN_0003002c((int)*ppuVar19,(int)param_3),
               CONCAT31(extraout_var_00,bVar3) == 1)) {
              local_66c = (HKEY)(&DAT_00064a88)[uVar18];
              pcVar17 = *(code **)(local_66c->unused + 4);
              goto LAB_00026410;
            }
            uVar18 = uVar18 + 1;
            ppuVar19 = ppuVar19 + 1;
          } while (uVar18 < 9);
          goto LAB_00027b34;
        }
        if (DAT_000648e4 == (undefined4 *)0x0) goto LAB_00027b34;
        uVar18 = FUN_000153dc((int)DAT_000648e4,9,6,&local_664,2,100);
        param_4 = (char *)(uint)local_664;
        if (uVar18 == 0) {
          pwVar14 = L"\r\n~!@#$ error - REG_DET_TEMP_SAR %d\r\n";
        }
        else {
          pwVar14 = L"\r\n~!@#$ REG_DET_TEMP_SAR %d\r\n";
        }
      }
      goto LAB_000272bc;
    }
    if (DAT_00064a24 == (int *)0x0) goto LAB_00027b34;
    KillTimer(param_1,0x708);
    memset(&local_5d8,0,8);
    uVar2 = FUN_00036c18(DAT_00064a24,&local_5d8);
    iVar21 = CONCAT31(extraout_var,uVar2);
    if (iVar21 == 0) {
      pwVar14 = L"\n++++++++Success to initail Bluetooht module\r\n";
LAB_00026108:
      NKDbgPrintfW(pwVar14);
    }
    else {
      if (iVar21 == 1) {
        pwVar14 = L"\n++++++++Fail to initail Bluetooht module\r\n";
        goto LAB_00026108;
      }
      if (iVar21 == 2) {
        NKDbgPrintfW(L"\n++++++++Not ready Bluetooth module...%d\r\n",DAT_00066634);
      }
    }
    FUN_00036f08(0x3030106,0);
    if ((iVar21 == 2) && (DAT_00066634 < (char *)0x32)) {
      SetTimer(param_1,0x708,5000,(TIMERPROC)0x0);
      DAT_00066634 = DAT_00066634 + 1;
      goto LAB_00027b34;
    }
    local_5e3 = local_5d8;
    local_5df = local_5d4;
    local_5de = local_5d3;
    local_5e4 = uVar2;
    FUN_00014db0((int)DAT_000648e4,0xd,0x28,(int)&local_5e4,7,100);
    FUN_0001e530((int)DAT_00064a24);
    pwVar14 = 
    L"\n++++++++Send the inform(mac, dtc) of Bluetooth module to MICOM (TryCount=%d)...\r\n";
    param_4 = DAT_00066634;
LAB_000272bc:
    NKDbgPrintfW(pwVar14,param_4);
    goto LAB_00027b34;
  }
  if (param_2 == 0x401) {
    piVar20 = FUN_00028a84((int *)&DAT_00064be8);
    while (piVar20 != (int *)0x0) {
      uVar18 = 0;
      do {
        piVar15 = *(int **)((int)&DAT_00064a88 + uVar18);
        if (piVar15 != (int *)0x0) {
          (**(code **)(*piVar15 + 0xc))(piVar15,piVar20);
        }
        uVar18 = uVar18 + 4;
      } while (uVar18 < 0x24);
      piVar20 = FUN_00028a84((int *)&DAT_00064be8);
    }
    goto LAB_00027b34;
  }
  if (param_2 == 0x402) {
    FUN_000150d8((int)DAT_000648e4);
    FUN_0001d750((int)DAT_00064a24,(uint)param_3 & 0xff);
    goto LAB_00027b34;
  }
  if (param_2 == 0x8064) {
    uVar18 = 0;
    do {
      piVar20 = *(int **)((int)&DAT_00064a88 + uVar18);
      if (piVar20 != (int *)0x0) {
        (**(code **)(*piVar20 + 8))(piVar20,(uint)param_3 >> 0x10,param_4);
      }
      uVar18 = uVar18 + 4;
    } while (uVar18 < 0x24);
    goto LAB_00027b34;
  }
  if (param_2 == 0x8067) {
    if (param_3 == (char *)0x3030102) {
      local_670[0] = 0;
      FUN_00014db0((int)DAT_000648e4,0xd,0x28,(int)local_670,1,100);
      pwVar14 = L"\r\n~~##** Bluetooth has been alive...lParam %d\r\n\r\n";
    }
    else {
      if (param_3 == (char *)0x3030103) goto LAB_00027b34;
      if (param_3 == (char *)0x3030107) {
        if (param_4 != (char *)0x0) {
          local_658[0] = 0x28;
          local_67c = (undefined4 *)0x1;
          LVar8 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_66c);
          if (LVar8 == 0) {
            memset(local_548,0,0x104);
            RegQueryValueExW(local_66c,L"VerBlue",(LPDWORD)0x0,(LPDWORD)&local_67c,
                             (LPBYTE)awStack_238,local_658);
            FUN_00025840(awStack_238,local_548);
            local_662 = local_548[0] + -0x30;
            local_661 = local_546 + -0x30;
            local_660 = local_544 + -0x30;
            memset(local_548,0,0x104);
            RegQueryValueExW(local_66c,L"VerHWBlue",(LPDWORD)0x0,(LPDWORD)&local_67c,
                             (LPBYTE)awStack_238,local_658);
            FUN_00025840(awStack_238,local_548);
            iVar21 = atoi(local_548);
            local_65e = (undefined1)((uint)iVar21 >> 0x10);
            local_65d = (undefined1)((uint)iVar21 >> 8);
            local_65c = (undefined1)iVar21;
            FUN_00014db0((int)DAT_000648e4,1,0xd7,(int)&local_65e,3,0xfa);
            FUN_00014db0((int)DAT_000648e4,1,0xd8,(int)&local_662,3,0xfa);
            RegCloseKey(local_66c);
          }
          else {
            NKDbgPrintfW(L"~~ Error Read BT Ver(SW/HW) \r\n");
          }
          local_658[0] = 8;
          local_67c = (undefined4 *)0x3;
          LVar8 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",0,0,&local_66c);
          if (LVar8 == 0) {
            RegQueryValueExW(local_66c,L"BTAddress",(LPDWORD)0x0,(LPDWORD)&local_67c,aBStack_5b0,
                             local_658);
            FUN_00014db0((int)DAT_000648e4,1,0xd9,(int)aBStack_5b0,6,0xfa);
            pcVar17 = RegCloseKey_exref;
LAB_00026410:
            (*pcVar17)(local_66c);
          }
          else {
            NKDbgPrintfW(L"~~ Error Read BT Ver(Addr) \r\n");
          }
        }
        goto LAB_00027b34;
      }
      if (param_3 == (char *)0x3040101) {
        if (DAT_00064a24 != (int *)0x0) {
          (**(code **)(*DAT_00064a24 + 8))(DAT_00064a24,0xb5,(uint)param_4 & 0xffff | 0xf10000);
        }
        goto LAB_00027b34;
      }
      if (param_3 == (char *)0x3041401) goto LAB_00027b34;
      if (param_3 == (char *)0x4100501) {
        local_672 = bVar16 + 0x7f;
        FUN_00014db0((int)DAT_000648e4,0xd,0x3d,(int)&local_672,1,0xfa);
        param_4 = (char *)(uint)local_672;
        iVar21 = (int)(char)bVar16;
        pwVar14 = L"~~ Received BT RSSI from BT(%d, %d) \r\n";
        goto LAB_00027678;
      }
      if (param_3 == (char *)0x4100601) {
        local_671 = bVar16;
        FUN_00014db0((int)DAT_000648e4,0xd,0x3e,(int)&local_671,1,0xfa);
        param_4 = (char *)(uint)local_671;
        pwVar14 = L"~~ Received BT LINK Q from BT(%d) \r\n";
      }
      else {
        pwVar14 = L"~~ Unknown message form Blue (%d) \r\n";
        param_4 = param_3;
      }
    }
    goto LAB_000272bc;
  }
LAB_00027154:
  if (param_2 == DAT_00064b18) {
    if (DAT_000648ec != (undefined4 *)0x0) {
      FUN_00016c80((int)DAT_000648ec,(uint)param_4);
    }
    goto LAB_00027b34;
  }
  if (param_2 == DAT_00064b04) {
    if (DAT_000648e4 != (undefined4 *)0x0) {
      local_67f[0] = param_4 != (char *)0x0;
      NKDbgPrintfW(L" \r\n [DR_PWR] OnOff %d  \r\n",param_4,local_67f[0]);
      if (local_67f[0] == '\0') {
        FUN_00014db0((int)DAT_000648e4,1,0xdc,(int)local_67f,1,200);
      }
      else {
        FUN_00014db0((int)DAT_000648e4,1,0xd5,(int)local_67f,1,200);
      }
    }
    goto LAB_00027b34;
  }
  if (param_2 == DAT_00064b08) {
    local_680 = 0;
    if ((int)param_4 < 1) {
LAB_000272b0:
      pwVar14 = L" \r\n [DR_DTC]  Unkown Communication ststus %d   \r\n";
    }
    else if ((int)param_4 < 3) {
      local_680 = 1;
      FUN_00014db0((int)DAT_000648e4,1,0xdb,(int)&local_680,1,200);
      pwVar14 = L" \r\n [DR_DTC]  Error[%d]   \r\n";
    }
    else {
      if (param_4 != (char *)0x3) goto LAB_000272b0;
      local_680 = 0;
      FUN_00014db0((int)DAT_000648e4,1,0xdb,(int)&local_680,1,200);
      pwVar14 = L" \r\n [DR_DTC]  Success[%d]   \r\n";
      param_4 = (char *)0x3;
    }
    goto LAB_000272bc;
  }
  if (param_2 != DAT_00064b3c) {
    if (param_2 == DAT_00064b34) {
      if ((((uint)param_4 & 1) != 0) || (local_673 = 1, ((uint)param_4 & 0x80) != 0)) {
        local_673 = 0;
      }
      NKDbgPrintfW(L"[[[ MGRMCM ]]]   g_NotiMsgResRVCInfo [0x%08X, %d] \r\n",param_4,local_673);
      FUN_00014db0((int)DAT_000648e4,0xd,0x3c,(int)&local_673,1,300);
      goto LAB_00027b34;
    }
    if (param_2 == DAT_00064af8) {
      if (param_3 < (char *)0xbcc) goto LAB_00027b34;
      if (param_3 < (char *)0xbd0) {
        if (DAT_00068464 != (undefined4 *)0x0) {
          FUN_00033ffc((int)DAT_00068464,(int)param_3,(uint)param_4);
        }
        goto LAB_00027b34;
      }
      if (param_3 == (char *)0xbd2) {
        SetTimer(param_1,1000,200,FUN_00025e1c);
        goto LAB_00027b34;
      }
      if (param_3 != (char *)0xbd3) goto LAB_00027b34;
      uIDEvent = 1000;
      goto LAB_000265a0;
    }
    if (param_2 == DAT_00064b2c) {
      if ((param_4 != (char *)0x0) && (param_4 == (char *)0x1)) {
        iVar21 = 2;
      }
      iVar11 = FUN_00016dbc((int)DAT_000648ec);
      if (((iVar11 != iVar21) &&
          (FUN_00016ddc((int)DAT_000648ec,iVar21), DAT_000648ec != (undefined4 *)0x0)) &&
         ((iVar21 = DAT_000648ec[7], iVar21 == 3 ||
          ((((iVar21 == 7 || (iVar21 == 8)) || (iVar21 == 9)) || (iVar21 == 10)))))) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      goto LAB_00027b34;
    }
    if (param_2 == DAT_00064b0c) {
      NKDbgPrintfW(L"[[[ MGRMCM ]]]   g_uPowerDownMsg [%d, %d] \r\n",param_3,param_4);
      FUN_00015158((int)DAT_000648e4,1,1,0xfc,0,0,100);
      goto LAB_00027b34;
    }
    if (param_2 != DAT_00064b10) {
      LVar12 = DefWindowProcW(param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
      FUN_0004a3f4(local_30);
      return LVar12;
    }
    NKDbgPrintfW(L"[[[ MGRMCM ]]]   g_ulTriggerSendMsg [%d, %d] \r\n",param_3,param_4);
    if (param_3 == (char *)0x64) {
      hWnd = FindWindowW((LPCWSTR)0x0,L"ULC2_Trigger");
      if (hWnd != (HWND)0x0) {
        PostMessageW(hWnd,DAT_00064b14,100,10);
        goto LAB_00027b34;
      }
      iVar21 = 100;
      pwVar14 = L"[[[ Error ]]][[[ MGRMCM ]]] Trigger Application can not found[%d, %d] \r\n";
    }
    else {
      if (param_3 != (char *)0xc8) goto LAB_00027b34;
      local_674 = bVar16;
      if (((uint)param_4 & 0xff) < 10) {
        iVar21 = FUN_00014db0((int)DAT_000648e4,0xd,0xb,(int)&local_674,1,100);
        if ((iVar21 == 1) && (local_674 < 10)) {
          FUN_000326f0(local_674);
          FUN_0001d598();
        }
        goto LAB_00027b34;
      }
      iVar21 = 200;
      pwVar14 = L"[[[ Error ]]][[[ MGRMCM ]]]  Outof range [%d, %d] \r\n";
    }
LAB_00027678:
    NKDbgPrintfW(pwVar14,iVar21,param_4);
    goto LAB_00027b34;
  }
  NKDbgPrintfW(L" \r\n [g_WM_DAB_FactoryResponse] %d, %d\r\n",param_3,param_4);
  if (param_3 < (char *)0x67) goto LAB_00027b34;
  if (param_3 < (char *)0x69) {
    if (DAT_00064a24 == (int *)0x0) goto LAB_00027b34;
    uVar18 = 0xf30000;
LAB_0002736c:
    uVar18 = (uint)param_4 & 0xffff | uVar18;
  }
  else {
    if (param_3 != (char *)0x69) {
      if ((param_3 != (char *)0x6a) || (DAT_00064a24 == (int *)0x0)) goto LAB_00027b34;
      uVar18 = 0xf40000;
      goto LAB_0002736c;
    }
    if (DAT_00064a24 == (int *)0x0) goto LAB_00027b34;
    uVar18 = 0xf30000;
LAB_000265cc:
    uVar18 = uVar18 | 1;
  }
  FUN_00035f88(DAT_00064a24,uVar18);
LAB_00027b34:
  FUN_0004a3f4(local_30);
  return 0;
}



/* 00027b78 Unwind@00027b78 */

/* Boundary evidence: original MIPS .pdata 00027b78..00027ba7. Semantic name remains unreviewed. */

void Unwind_00027b78(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027ba8 Unwind@00027ba8 */

/* Boundary evidence: original MIPS .pdata 00027ba8..00027bd7. Semantic name remains unreviewed. */

void Unwind_00027ba8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027bd8 Unwind@00027bd8 */

/* Boundary evidence: original MIPS .pdata 00027bd8..00027c07. Semantic name remains unreviewed. */

void Unwind_00027bd8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027c08 Unwind@00027c08 */

/* Boundary evidence: original MIPS .pdata 00027c08..00027c37. Semantic name remains unreviewed. */

void Unwind_00027c08(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027c38 Unwind@00027c38 */

/* Boundary evidence: original MIPS .pdata 00027c38..00027c67. Semantic name remains unreviewed. */

void Unwind_00027c38(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027c68 Unwind@00027c68 */

/* Boundary evidence: original MIPS .pdata 00027c68..00027c97. Semantic name remains unreviewed. */

void Unwind_00027c68(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027c98 Unwind@00027c98 */

/* Boundary evidence: original MIPS .pdata 00027c98..00027cc7. Semantic name remains unreviewed. */

void Unwind_00027c98(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027cc8 Unwind@00027cc8 */

/* Boundary evidence: original MIPS .pdata 00027cc8..00027cf7. Semantic name remains unreviewed. */

void Unwind_00027cc8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027cf8 Unwind@00027cf8 */

/* Boundary evidence: original MIPS .pdata 00027cf8..00027d27. Semantic name remains unreviewed. */

void Unwind_00027cf8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027d28 Unwind@00027d28 */

/* Boundary evidence: original MIPS .pdata 00027d28..00027d57. Semantic name remains unreviewed. */

void Unwind_00027d28(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x67c));
  return;
}



/* 00027d58 FUN_00027d58 */

/* Boundary evidence: original MIPS .pdata 00027d58..00027dbb. Semantic name remains unreviewed. */

void FUN_00027d58(HINSTANCE param_1,LPCWSTR param_2)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_00025ef0;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hInstance = param_1;
  local_30.hIcon = LoadIconW(param_1,(LPCWSTR)0x65);
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = (HBRUSH)0x0;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpszClassName = param_2;
  RegisterClassW(&local_30);
  return;
}



/* 00027dbc FUN_00027dbc */

/* Boundary evidence: original MIPS .pdata 00027dbc..00027e93. Semantic name remains unreviewed. */

undefined4 FUN_00027dbc(HINSTANCE param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  HWND hWnd;
  
  bVar1 = FUN_0002821c((undefined4 *)&DAT_00064b44);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    NKDbgPrintfW(L"[MICOM MANAGER:%S] Can\'t open serial port","InitInstance");
  }
  else {
    DAT_00064aac = param_1;
    iVar2 = FUN_00027d58(param_1,L"MGRMCM");
    if ((iVar2 != 0) &&
       (hWnd = CreateWindowExW(0,L"MGRMCM",L"Micom Manager",0x80000000,0,0,0,0,(HWND)0x0,(HMENU)0x0,
                               param_1,(LPVOID)0x0), hWnd != (HWND)0x0)) {
      ShowWindow(hWnd,0);
      UpdateWindow(hWnd);
      return 1;
    }
  }
  return 0;
}



/* 00027e94 FUN_00027e94 */

/* Boundary evidence: original MIPS .pdata 00027e94..00027fc7. Semantic name remains unreviewed. */

WPARAM FUN_00027e94(HINSTANCE param_1)

{
  HANDLE hThread;
  int iVar1;
  BOOL BVar2;
  MSG MStack_38;
  
  FUN_000336b4();
  hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00025090,(LPVOID)0x0,4,(LPDWORD)0x0);
  if (hThread != (HANDLE)0x0) {
    SetThreadPriority(hThread,0);
    ResumeThread(hThread);
    CloseHandle(hThread);
    Sleep(0);
  }
  SetThreadPriority((HANDLE)0x41,0);
  iVar1 = FUN_00027dbc(param_1);
  if (iVar1 == 0) {
    MStack_38.wParam = 0;
  }
  else {
    while (BVar2 = GetMessageW(&MStack_38,(HWND)0x0,0,0), BVar2 != 0) {
      TranslateMessage(&MStack_38);
      DispatchMessageW(&MStack_38);
    }
  }
  return MStack_38.wParam;
}



/* 00027fc8 FUN_00027fc8 */

/* Boundary evidence: original MIPS .pdata 00027fc8..00028087. Semantic name remains unreviewed. */

undefined4 FUN_00027fc8(void)

{
  DWORD DVar1;
  wchar_t *pwVar2;
  
  if (DAT_0006373c == (HANDLE)0xffffffff) {
    DAT_0006373c = CreateFileW(L"PHM1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (DAT_0006373c == (HANDLE)0xffffffff) {
      DVar1 = GetLastError();
      NKDbgPrintfW(L"[NORW] can\'t open NOR flash driver  [0x%08X]\r\n",DVar1);
      return 0;
    }
    pwVar2 = L"[NORW] NOR flash driver\r\n";
  }
  else {
    pwVar2 = L"[NORW] NOR flash driver is already opened\r\n";
  }
  NKDbgPrintfW(pwVar2);
  return 1;
}



/* 00028088 FUN_00028088 */

/* Boundary evidence: original MIPS .pdata 00028088..000280d7. Semantic name remains unreviewed. */

void FUN_00028088(void)

{
  if (DAT_0006373c != -1) {
    CloseHandle((HANDLE)DAT_0006373c);
    DAT_0006373c = -1;
  }
  return;
}



/* 000280d8 FUN_000280d8 */

/* Boundary evidence: original MIPS .pdata 000280d8..0002812b. Semantic name remains unreviewed. */

void FUN_000280d8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DWORD aDStack_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_2;
  local_14 = param_1;
  local_10 = param_3;
  DeviceIoControl(DAT_0006373c,1,&local_18,0xc,(LPVOID)0x0,0,aDStack_20,(LPOVERLAPPED)0x0);
  return;
}



/* 0002812c FUN_0002812c */

/* Boundary evidence: original MIPS .pdata 0002812c..0002817f. Semantic name remains unreviewed. */

void FUN_0002812c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DWORD aDStack_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  DeviceIoControl(DAT_0006373c,2,&local_18,0xc,(LPVOID)0x0,0,aDStack_20,(LPOVERLAPPED)0x0);
  return;
}



/* 00028180 FUN_00028180 */

/* Boundary evidence: original MIPS .pdata 00028180..000281cf. Semantic name remains unreviewed. */

void FUN_00028180(undefined4 param_1,undefined4 param_2)

{
  DWORD aDStack_20 [2];
  undefined1 auStack_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = param_1;
  local_10 = param_2;
  DeviceIoControl(DAT_0006373c,0,auStack_18,0xc,(LPVOID)0x0,0,aDStack_20,(LPOVERLAPPED)0x0);
  return;
}



/* 000281d0 FUN_000281d0 */

/* Boundary evidence: original MIPS .pdata 000281d0..0002821b. Semantic name remains unreviewed. */

undefined4 * FUN_000281d0(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  memset(param_1 + 1,0,0x14);
  memset(param_1 + 6,0,0x8c);
  return param_1;
}



/* 0002821c FUN_0002821c */

/* Boundary evidence: original MIPS .pdata 0002821c..000282ff. Semantic name remains unreviewed. */

bool FUN_0002821c(undefined4 *param_1)

{
  HANDLE hFile;
  HANDLE hFile_00;
  _DCB _Stack_30;
  
  hFile = CreateFileW(L"COM2:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *param_1 = hFile;
  if (hFile != (HANDLE)0xffffffff) {
    GetCommState(hFile,&_Stack_30);
    _Stack_30.BaudRate = 300000;
    _Stack_30.fNull = 0;
    _Stack_30.fParity = 0;
    _Stack_30.ByteSize = '\b';
    _Stack_30.Parity = '\0';
    _Stack_30.StopBits = '\0';
    SetCommState((HANDLE)*param_1,&_Stack_30);
    hFile_00 = (HANDLE)*param_1;
    ((LPCOMMTIMEOUTS)(param_1 + 1))->ReadIntervalTimeout = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    SetCommTimeouts(hFile_00,(LPCOMMTIMEOUTS)(param_1 + 1));
  }
  return hFile != (HANDLE)0xffffffff;
}



/* 00028300 FUN_00028300 */

/* Boundary evidence: original MIPS .pdata 00028300..0002834f. Semantic name remains unreviewed. */

void FUN_00028300(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)*param_1);
    *param_1 = 0xffffffff;
  }
  return;
}



/* 00028350 FUN_00028350 */

/* Boundary evidence: original MIPS .pdata 00028350..000283af. Semantic name remains unreviewed. */

void FUN_00028350(undefined4 *param_1)

{
  DWORD local_20 [2];
  _COMSTAT _Stack_18;
  
  ClearCommError((HANDLE)*param_1,local_20,&_Stack_18);
  if (local_20[0] == 0) {
    NKDbgPrintfW(L"%S : ?????\r\n","CProtocol::OnError");
  }
  else {
    NKDbgPrintfW(L"%S : 0x%08X\r\n","CProtocol::OnError");
  }
  return;
}



/* 000283b0 FUN_000283b0 */

/* Boundary evidence: original MIPS .pdata 000283b0..000284e7. Semantic name remains unreviewed. */

BOOL FUN_000283b0(undefined4 *param_1,byte param_2,char param_3,LPCVOID param_4)

{
  BOOL BVar1;
  uint uVar2;
  char local_28 [2];
  byte local_26;
  char local_25;
  undefined1 local_24;
  DWORD aDStack_20 [2];
  
  local_26 = 0x55;
  local_28[0] = '\0';
  local_25 = 0x4c;
  local_24 = 0x43;
  WriteFile((HANDLE)*param_1,&local_26,3,aDStack_20,(LPOVERLAPPED)0x0);
  local_26 = param_2 | 0xa0;
  local_28[0] = local_26 + local_28[0] + param_3;
  local_25 = param_3;
  WriteFile((HANDLE)*param_1,&local_26,2,aDStack_20,(LPOVERLAPPED)0x0);
  WriteFile((HANDLE)*param_1,param_4,0x400,aDStack_20,(LPOVERLAPPED)0x0);
  uVar2 = 0;
  do {
    local_28[0] = *(char *)(uVar2 + (int)param_4) + local_28[0];
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x400);
  BVar1 = WriteFile((HANDLE)*param_1,local_28,1,aDStack_20,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    FUN_00028350(param_1);
  }
  return BVar1;
}



/* 000284e8 FUN_000284e8 */

/* Boundary evidence: original MIPS .pdata 000284e8..00028587. Semantic name remains unreviewed. */

BOOL FUN_000284e8(undefined4 *param_1,byte *param_2)

{
  BOOL BVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  DWORD aDStack_18 [2];
  
  bVar2 = *param_2;
  uVar4 = param_2[3] + 4;
  iVar3 = 1;
  if (1 < uVar4) {
    do {
      bVar2 = param_2[iVar3] ^ bVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar4);
  }
  param_2[param_2[3] + 4] = bVar2;
  BVar1 = WriteFile((HANDLE)*param_1,param_2,param_2[3] + 5,aDStack_18,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    FUN_00028350(param_1);
  }
  return BVar1;
}



/* 00028588 FUN_00028588 */

/* Boundary evidence: original MIPS .pdata 00028588..0002863b. Semantic name remains unreviewed. */

BOOL FUN_00028588(undefined4 *param_1,uint param_2,uint param_3,uint param_4,int param_5,
                 byte param_6)

{
  BOOL BVar1;
  uint uVar2;
  uint uVar3;
  uint local_98;
  undefined1 local_94 [136];
  uint local_c;
  
  local_c = DAT_00064820;
  uVar2 = (uint)param_6;
  local_98 = ((param_2 & 0xf | (param_4 & 0xff) << 4 | uVar2 << 0xc) << 4 | param_3 & 0xf) << 8 |
             0xaa;
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      local_94[uVar3] = *(undefined1 *)(uVar3 + param_5);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < uVar2);
  }
  BVar1 = FUN_000284e8(param_1,(byte *)&local_98);
  FUN_0004a3f4(local_c);
  return BVar1;
}



/* 0002863c FUN_0002863c */

/* Boundary evidence: original MIPS .pdata 0002863c..000288e3. Semantic name remains unreviewed. */

undefined4 FUN_0002863c(undefined4 *param_1,byte *param_2)

{
  bool bVar1;
  BOOL BVar2;
  HANDLE pvVar3;
  wchar_t *pwVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  LPCOMMTIMEOUTS lpCommTimeouts;
  char local_28 [4];
  uint local_24;
  
  lpCommTimeouts = (LPCOMMTIMEOUTS)(param_1 + 1);
  pvVar3 = (HANDLE)*param_1;
  lpCommTimeouts->ReadIntervalTimeout = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  SetCommTimeouts(pvVar3,lpCommTimeouts);
  iVar9 = 1;
  BVar2 = ReadFile((HANDLE)*param_1,local_28,1,&local_24,(LPOVERLAPPED)0x0);
  if (BVar2 != 0) {
    if (local_28[0] == -0x5a) {
      *param_2 = 0xa6;
      return 1;
    }
    if (local_28[0] == -0x56) {
      *param_2 = 0xaa;
      pvVar3 = (HANDLE)*param_1;
      lpCommTimeouts->ReadIntervalTimeout = 2;
      param_1[2] = 6;
      param_1[3] = 1;
      SetCommTimeouts(pvVar3,lpCommTimeouts);
      BVar2 = ReadFile((HANDLE)*param_1,param_2 + 1,3,&local_24,(LPOVERLAPPED)0x0);
      if (BVar2 != 0) {
        if (local_24 != 3) {
          return 0;
        }
        param_1[2] = (param_2[3] + 1) * 2;
        SetCommTimeouts((HANDLE)*param_1,lpCommTimeouts);
        BVar2 = ReadFile((HANDLE)*param_1,param_2 + 4,param_2[3] + 1,&local_24,(LPOVERLAPPED)0x0);
        if (BVar2 != 0) {
          uVar6 = (uint)param_2[3];
          uVar5 = uVar6 + 1;
          if (local_24 == uVar5) {
            uVar5 = (uint)*param_2;
            bVar1 = 1 < uVar6 + 4;
            iVar8 = 1;
            uVar7 = uVar5;
            if (bVar1) {
              do {
                uVar7 = param_2[iVar8] ^ uVar7;
                iVar8 = iVar8 + 1;
              } while (iVar8 < (int)(param_2[3] + 4));
            }
            local_24 = (uint)param_2[uVar6 + 4];
            if (local_24 == uVar7) {
              return 1;
            }
            if (bVar1) {
              do {
                uVar5 = param_2[iVar9] ^ uVar5;
                iVar9 = iVar9 + 1;
              } while (iVar9 < (int)(param_2[3] + 4));
            }
            pwVar4 = L"%S : Checksum Error 0x%02X:0x%02X\r\n";
          }
          else {
            pwVar4 = L"%S : Data Length Error : %d/%d\r\n";
          }
          NKDbgPrintfW(pwVar4,"CProtocol::ReadCommand",local_24,uVar5);
          return 0;
        }
      }
    }
    else {
      if (local_28[0] != -0x55) {
        NKDbgPrintfW(L"%S : Data Error? 0x%02X\r\n","CProtocol::ReadCommand");
        return 0;
      }
      *param_2 = 0xab;
      pvVar3 = (HANDLE)*param_1;
      lpCommTimeouts->ReadIntervalTimeout = 2;
      param_1[2] = 2;
      param_1[3] = 1;
      SetCommTimeouts(pvVar3,lpCommTimeouts);
      BVar2 = ReadFile((HANDLE)*param_1,param_2 + 1,1,&local_24,(LPOVERLAPPED)0x0);
      if (BVar2 != 0) {
        if (local_24 != 1) {
          return 0;
        }
        return 1;
      }
    }
  }
  FUN_00028350(param_1);
  return 0;
}



/* 000288e4 FUN_000288e4 */

/* Boundary evidence: original MIPS .pdata 000288e4..00028993. Semantic name remains unreviewed. */

void FUN_000288e4(int param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  
  *(char *)(param_1 + 0x18) = (char)*param_2;
  uVar2 = (*(uint *)(param_1 + 0x18) ^ *param_2) & 0xf00 ^ *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x18) = uVar2;
  *(uint *)(param_1 + 0x18) = (*param_2 ^ uVar2) & 0xf000 ^ uVar2;
  *(char *)(param_1 + 0x1a) = (char)*(undefined2 *)((int)param_2 + 2);
  bVar1 = *(byte *)((int)param_2 + 3);
  *(byte *)(param_1 + 0x1b) = bVar1;
  if (0x88 < bVar1) {
    NKDbgPrintfW(L"%S : Payload length Error? %d X\r\n","CProtocol::SetReadData");
    *(undefined1 *)(param_1 + 0x1b) = 0x88;
  }
  memcpy((void *)(param_1 + 0x1c),param_2 + 1,(uint)*(byte *)(param_1 + 0x1b));
  return;
}



/* 00028994 FUN_00028994 */

/* Boundary evidence: original MIPS .pdata 00028994..000289c7. Semantic name remains unreviewed. */

void * FUN_00028994(int param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x18),0x8c);
  return param_2;
}



/* 000289c8 FUN_000289c8 */

/* Boundary evidence: original MIPS .pdata 000289c8..00028a0b. Semantic name remains unreviewed. */

undefined4 * FUN_000289c8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 0;
  memset(param_1 + 3,0,0x1a40);
  return param_1;
}



/* 00028a0c FUN_00028a0c */

int FUN_00028a0c(int param_1)

{
  return *(int *)(param_1 + 4) * 0x8c + param_1 + 0xc;
}



/* 00028a28 FUN_00028a28 */

/* Boundary evidence: original MIPS .pdata 00028a28..00028a83. Semantic name remains unreviewed. */

undefined4 FUN_00028a28(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) == 0x2f) {
    NKDbgPrintfW(L"Command Queue Full!! Please Check.\r\n");
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 4) + 1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(int *)(param_1 + 4) = iVar2;
    if (iVar2 == 0x30) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 00028a84 FUN_00028a84 */

int * FUN_00028a84(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1[2] == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    iVar2 = *param_1;
    param_1[2] = param_1[2] + -1;
    *param_1 = iVar2 + 1;
    if (iVar2 + 1 == 0x30) {
      *param_1 = 0;
    }
    piVar1 = param_1 + *param_1 * 0x23 + 3;
  }
  return piVar1;
}



/* 00028ad8 FUN_00028ad8 */

/* Boundary evidence: original MIPS .pdata 00028ad8..00028bdf. Semantic name remains unreviewed. */

undefined4 *
FUN_00028ad8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00030010(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_000585b8;
  param_1[0x11] = param_4;
  param_1[0x17] = 0;
  memset(param_1 + 0x18,0,0x80);
  memset(param_1 + 0x38,0,0xd8);
  memset(param_1 + 3,0,0x20);
  param_1[0x74] = 0xffffffff;
  param_1[0x6f] = 2;
  param_1[0x16] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x6e] = 0;
  param_1[0x70] = 0;
  *(undefined2 *)(param_1 + 0x73) = 0;
  *(undefined2 *)(param_1 + 0xb) = 0;
  *(undefined2 *)((int)param_1 + 0x2e) = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined2 *)((int)param_1 + 0x32) = 0;
  *(undefined2 *)(param_1 + 0xd) = 0;
  *(undefined1 *)(param_1 + 0x83) = 0;
  *(undefined1 *)(param_1 + 0x93) = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0xa4] = 0;
  param_1[0x81] = 0;
  param_1[0x82] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x7a] = 0;
  *(undefined2 *)(param_1 + 0x7b) = 0;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0;
  param_1[0xa3] = 0;
  param_1[0xa5] = 100000;
  param_1[0x72] = 0xc;
  return param_1;
}



/* 00028be0 FUN_00028be0 */

/* Boundary evidence: original MIPS .pdata 00028be0..00028c6f. Semantic name remains unreviewed. */

void FUN_00028be0(int param_1,undefined4 param_2,UINT param_3)

{
  NKDbgPrintfW(L"%S(nID=%d,nTout=%d)\r\n","CRadio::SetTimer",param_2,param_3);
  if (*(int *)(param_1 + 0x48) != 0) {
    NKDbgPrintfW(L"%S : Timer is already started. Check it out.!!!!!!!!!!!(OLD:%d, NEW:%d)\r\n",
                 "CRadio::SetTimer",*(int *)(param_1 + 0x48),param_2);
  }
  *(undefined4 *)(param_1 + 0x48) = param_2;
  FUN_00030044(param_1,param_3);
  return;
}



/* 00028c70 FUN_00028c70 */

/* Boundary evidence: original MIPS .pdata 00028c70..00028cf7. Semantic name remains unreviewed. */

void FUN_00028c70(int param_1,int param_2)

{
  NKDbgPrintfW(L"%S(nID=%d)\r\n","CRadio::KillTimer",param_2);
  if ((param_2 == 0) || (*(int *)(param_1 + 0x48) == param_2)) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    FUN_0003006c(param_1);
  }
  else {
    NKDbgPrintfW(L"%S : Already Killed or another timer running.\r\n","CRadio::KillTimer");
  }
  return;
}



/* 00028cf8 FUN_00028cf8 */

/* Boundary evidence: original MIPS .pdata 00028cf8..00028f87. Semantic name remains unreviewed. */

void FUN_00028cf8(int param_1,uint param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_28;
  byte local_27;
  
  if ((param_2 < 0xc) && (*(int *)(param_1 + 0x50) != 3)) {
    (&DAT_0006769c)[param_2 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] =
         *(undefined4 *)(param_1 + 0x1c0);
    (&DAT_00067698)[param_2 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] =
         *(undefined2 *)(param_1 + 0x1cc);
    (&DAT_0006768c)[*(int *)(param_1 + 0x1bc) * 0x48c] = (char)param_2;
    iVar4 = *(int *)(param_1 + 0x1bc);
    if (iVar4 == 1) {
      sprintf_s(&DAT_00067b2c + param_2 * 0x18,0x10,"%dkHz",*(undefined4 *)(param_1 + 0x1c0));
    }
    else if (*(ushort *)(param_1 + 0x1cc) == 0) {
      iVar3 = *(int *)(param_1 + 0x44);
      if ((*(char *)(iVar3 + 0xa97) == '\0') || ((DAT_00067678 & 4) != 4)) {
        uVar2 = __ultofp(*(undefined4 *)(param_1 + 0x1c0));
        uVar5 = __fptodp(uVar2);
        __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0xd2f1a9fc,0x3f50624d);
        sprintf_s((char *)(&DAT_000676a0 + param_2 * 6 + iVar4 * 0x123),0x10,"%6.2fMHz");
      }
      else {
        (&DAT_000676a0)[param_2 * 6 + iVar4 * 0x123] = *(undefined4 *)(iVar3 + 0xa97);
        (&DAT_000676a4)[param_2 * 6 + iVar4 * 0x123] = *(undefined4 *)(iVar3 + 0xa9b);
        (&DAT_000676a8)[iVar4 * 0x48c + param_2 * 0x18] = *(undefined1 *)(iVar3 + 0xa9f);
      }
    }
    else {
      FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                   &DAT_000676a0 + param_2 * 6 + iVar4 * 0x123);
    }
    *(uint *)(param_1 + 0x1d4) = param_2;
    *(char *)(*(int *)(param_1 + 0x44) + 0xa93) = (char)param_2;
    FUN_0003220c(*(int *)(param_1 + 0x1bc),param_2);
    if ((*(int *)(DAT_00064828 + 0x44) == 0) &&
       (bVar1 = FUN_0001e514(DAT_00064a24), CONCAT31(extraout_var,bVar1) == 0)) {
      local_28 = 3;
      local_27 = DAT_00067683;
      if (DAT_00067683 < 10) {
        local_27 = 10;
      }
      FUN_00015158(DAT_000648e4,5,1,0x40,(int)&local_28,2,100);
    }
  }
  return;
}



/* 00028f88 FUN_00028f88 */

/* Boundary evidence: original MIPS .pdata 00028f88..000290b7. Semantic name remains unreviewed. */

void FUN_00028f88(int param_1)

{
  LPARAM LVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  if ((*(int *)(param_1 + 0x50) == 5) && (iVar2 = *(int *)(param_1 + 0x1dc), iVar2 != 0)) {
    if ((iVar2 == 1) || ((iVar2 == 2 && (*(int *)(param_1 + 0x48) != 2)))) {
      FUN_00028c70(param_1,6);
      if ((*(int *)(param_1 + 0x1e0) != 0) &&
         ((*(int *)(param_1 + 0x1dc) == 1 && ((DAT_00067678 & 0x40) == 0x40)))) {
        *(undefined4 *)(param_1 + 0x1dc) = 0;
        NKDbgPrintfW(L"\r\n\r\n CmdSubTAOFF m_nAnnounceType[0]   [%d],  m_nAnnounceType[1]   [%d] ",
                     0);
        iVar2 = *(int *)(param_1 + 0x1e0);
        if ((*(int *)(param_1 + 0x200) + 1 == iVar2) && (iVar2 == 2)) {
          LVar1 = 0;
          iVar2 = 0x6e;
        }
        else {
          LVar1 = iVar2 + 2;
          iVar2 = 0x6d;
        }
        FUN_00036de8(iVar2,LVar1);
        goto LAB_0002909c;
      }
    }
  }
  else if ((*(int *)(param_1 + 0x1dc) == 0) || (*(int *)(param_1 + 0x1e0) != 0)) goto LAB_0002909c;
  FUN_00028be0(param_1,5,500);
LAB_0002909c:
  *(undefined4 *)(param_1 + 0x204) = 0;
  return;
}



/* 000290b8 FUN_000290b8 */

/* Boundary evidence: original MIPS .pdata 000290b8..00029157. Semantic name remains unreviewed. */

void FUN_000290b8(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x54);
  if (uVar1 == 2) {
    NKDbgPrintfW(L"%S(nID=%d)\r\n","CRadio::KillTimer",0);
    *(undefined4 *)(param_1 + 0x48) = 0;
    FUN_0003006c(param_1);
  }
  else {
    if (uVar1 < 3) {
      return;
    }
    if (4 < uVar1) {
      return;
    }
    FUN_00015158(DAT_000648e4,3,1,7,0,0,0x32);
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  return;
}



/* 00029158 FUN_00029158 */

undefined4 FUN_00029158(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c0);
}



/* 00029160 FUN_00029160 */

undefined2 FUN_00029160(int param_1)

{
  return *(undefined2 *)(param_1 + 0x1cc);
}



/* 00029168 FUN_00029168 */

undefined4 FUN_00029168(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x44);
  *param_2 = *(undefined4 *)(iVar1 + 0xa97);
  param_2[1] = *(undefined4 *)(iVar1 + 0xa9b);
  return 8;
}



/* 00029198 FUN_00029198 */

/* Boundary evidence: original MIPS .pdata 00029198..0002921b. Semantic name remains unreviewed. */

void FUN_00029198(int param_1)

{
  if ((*(int *)(param_1 + 0x4c) == 1) &&
     ((*(int *)(param_1 + 0x50) != 5 || (*(int *)(param_1 + 0x1dc) != 2)))) {
    *(undefined4 *)(*(int *)(param_1 + 0x44) + 8) = *(undefined4 *)(param_1 + 0x1c0);
    FUN_00036de8(0x65,*(LPARAM *)(param_1 + 0x1c0));
    if (*(HWND *)(param_1 + 0x5c) != (HWND)0x0) {
      PostMessageW(*(HWND *)(param_1 + 0x5c),0x403,0,*(LPARAM *)(param_1 + 0x1c0));
    }
  }
  return;
}



/* 0002921c FUN_0002921c */

uint FUN_0002921c(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  iVar2 = *(int *)(param_1 + 0x1bc) * 0x40 + param_1;
  uVar3 = *(uint *)(iVar2 + 0x60);
  uVar1 = 0;
  if (1 < uVar3) {
    uVar1 = 0;
    if (uVar3 != 0) {
      puVar4 = (uint *)(iVar2 + 0x68);
      do {
        if ((*puVar4 <= *(uint *)(param_1 + 0x1c0)) && (*(uint *)(param_1 + 0x1c0) <= puVar4[1]))
        break;
        uVar1 = uVar1 + 1;
        puVar4 = puVar4 + 5;
      } while (uVar1 < uVar3);
    }
    if (uVar1 == uVar3) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 0002928c FUN_0002928c */

/* Boundary evidence: original MIPS .pdata 0002928c..000292eb. Semantic name remains unreviewed. */

void FUN_0002928c(int param_1)

{
  *(undefined1 *)(param_1 + 0x20c) = 0;
  *(undefined1 *)(param_1 + 0x24c) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa95) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xaa3) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  FUN_00036de8(0x6a,0);
  FUN_00036de8(0x6b,0);
  FUN_00036de8(0x6c,0);
  return;
}



/* 000292ec FUN_000292ec */

/* Boundary evidence: original MIPS .pdata 000292ec..0002959b. Semantic name remains unreviewed. */

void FUN_000292ec(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = *(int *)(param_1 + 0x1bc);
  uVar5 = (uint)(byte)(&DAT_0006768c)[iVar2 * 0x48c];
  if ((DAT_00067678 & 4) == 4) {
    uVar4 = 0;
    if (*(short *)(param_1 + 0x1cc) == 0) {
      piVar3 = &DAT_0006769c + iVar2 * 0x123;
      do {
        if (((short)piVar3[-1] == 0) && (*piVar3 == *(int *)(param_1 + 0x1c0))) {
          if ((uVar5 < 0xc) &&
             (((&DAT_00067698)[iVar2 * 0x246 + uVar5 * 0xc] == 0 &&
              ((&DAT_0006769c)[iVar2 * 0x123 + uVar5 * 6] == *(int *)(param_1 + 0x1c0))))) {
LAB_000294c0:
            uVar4 = uVar5;
          }
          break;
        }
        uVar4 = uVar4 + 1;
        piVar3 = piVar3 + 6;
      } while (uVar4 < 0xc);
    }
    else {
      uVar6 = 0;
      do {
        uVar1 = *(ushort *)((int)&DAT_00067698 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar6);
        if (uVar1 == *(ushort *)(param_1 + 0x1cc)) {
          if (((uVar5 < 0xc) &&
              ((&DAT_00067698)[*(int *)(param_1 + 0x1bc) * 0x246 + uVar5 * 0xc] ==
               *(short *)(param_1 + 0x1cc))) &&
             ((&DAT_0006769c)[*(int *)(param_1 + 0x1bc) * 0x123 + uVar5 * 6] ==
              *(int *)(param_1 + 0x1c0))) goto LAB_000294c0;
          break;
        }
        if (((uVar1 ^ *(ushort *)(param_1 + 0x1cc)) & 0xf0ff) == 0) {
          NKDbgPrintfW(L"\n\n #### rgnrgnrgnrgnrgnrgnrgn   !@#!@#!@#!@#    [%d] \n\n",uVar4);
        }
        uVar6 = uVar6 + 0x18;
        uVar4 = uVar4 + 1;
      } while (uVar6 < 0x120);
    }
    if (uVar4 < 0xc) {
      *(uint *)(param_1 + 0x1d4) = uVar4;
    }
    else {
      *(undefined4 *)(param_1 + 0x1d4) = 0xc;
    }
  }
  else {
    uVar4 = 0;
    piVar3 = &DAT_0006769c + iVar2 * 0x123;
    do {
      if (*piVar3 == *(int *)(param_1 + 0x1c0)) {
        if ((uVar5 < 0xc) &&
           ((&DAT_0006769c)[iVar2 * 0x123 + uVar5 * 6] == *(int *)(param_1 + 0x1c0))) {
          uVar4 = uVar5;
        }
        break;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 6;
    } while (uVar4 < 0xc);
    *(uint *)(param_1 + 0x1d4) = uVar4;
  }
  *(char *)(*(int *)(param_1 + 0x44) + 0xa93) = (char)*(undefined4 *)(param_1 + 0x1d4);
  if (param_2 != 0) {
    FUN_00036de8(0x66,0);
  }
  return;
}



/* 0002959c FUN_0002959c */

/* Boundary evidence: original MIPS .pdata 0002959c..00029753. Semantic name remains unreviewed. */

void FUN_0002959c(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  
  if ((DAT_00067678 & 4) == 4) {
    uVar1 = *(ushort *)(param_1 + 0x1cc);
    uVar5 = 0x24;
    uVar2 = 0;
    if (uVar1 == 0) {
      iVar4 = *(int *)(param_1 + 0x1bc) * 0x48c;
      piVar3 = &DAT_000677bc + *(int *)(param_1 + 0x1bc) * 0x123;
      do {
        if (((short)piVar3[-1] == 0) && (*piVar3 == *(int *)(param_1 + 0x1c0))) break;
        uVar2 = uVar2 + 1;
        piVar3 = piVar3 + 6;
      } while (uVar2 < 0x24);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x1bc) * 0x48c;
      puVar6 = &DAT_000677b8 + *(int *)(param_1 + 0x1bc) * 0x246;
      do {
        if (*puVar6 == uVar1) break;
        if ((uVar5 == 0x24) && (((*puVar6 ^ uVar1) & 0xf0ff) == 0)) {
          uVar5 = uVar2;
        }
        uVar2 = uVar2 + 1;
        puVar6 = puVar6 + 0xc;
      } while (uVar2 < 0x24);
    }
    if (uVar2 < 0x24) {
      *(uint *)(param_1 + 0x1d8) = uVar2;
    }
    else {
      *(uint *)(param_1 + 0x1d8) = uVar5;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x1bc) * 0x48c;
    uVar5 = 0;
    piVar3 = &DAT_000677bc + *(int *)(param_1 + 0x1bc) * 0x123;
    do {
      if (*piVar3 == *(int *)(param_1 + 0x1c0)) break;
      uVar5 = uVar5 + 1;
      piVar3 = piVar3 + 6;
    } while (uVar5 < 0x24);
    *(uint *)(param_1 + 0x1d8) = uVar5;
  }
  uVar5 = *(uint *)(param_1 + 0x1d8);
  if (uVar5 < 0x24) {
    iVar4 = uVar5 * 0x18 + iVar4;
    NKDbgPrintfW(L"\n\n [ Freauency = %d  ] [ List Index = %d] [ PSN = %S] [PI 0x%04x)\n\n",
                 *(undefined4 *)((int)&DAT_000677bc + iVar4),uVar5,(int)&DAT_000677c0 + iVar4,
                 *(undefined2 *)(param_1 + 0x1cc));
  }
  *(char *)(*(int *)(param_1 + 0x44) + 0xa94) = (char)*(undefined4 *)(param_1 + 0x1d8);
  if (param_2 != 0) {
    FUN_00036de8(0x66,0);
  }
  return;
}



/* 00029754 FUN_00029754 */

/* Boundary evidence: original MIPS .pdata 00029754..000298af. Semantic name remains unreviewed. */

void FUN_00029754(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint local_1c;
  
  local_1c = DAT_00064820;
  memset(&uStack_40,0,0x24);
  uVar3 = 3;
  if (param_2 != 1) {
    uVar3 = 4;
  }
  uVar2 = 0;
  do {
    uVar1 = FUN_000153dc(DAT_000648e4,3,uVar3,&uStack_40,0x24,300);
    if (uVar1 == 0x24) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 3);
  if (uVar2 < 3) {
    FUN_000318e0(DAT_00067670,uStack_40,uStack_3c,uStack_38);
  }
  else {
    NKDbgPrintfW(L"%S : Can\'t read Station Info\r\n","CRadio::UpdateStationInfo");
  }
  FUN_0004a3f4(local_1c);
  return;
}



/* 000298b0 FUN_000298b0 */

undefined4 FUN_000298b0(int param_1)

{
  undefined4 uVar1;
  
  if ((0 < *(int *)(param_1 + 0x1dc)) || (uVar1 = 0, 0 < *(int *)(param_1 + 0x1e0))) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 000298d4 FUN_000298d4 */

void FUN_000298d4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1bc) * 0x48c;
  if (param_2 == 0) {
    (&DAT_0006768c)[iVar1] = (char)*(undefined4 *)(param_1 + 0x1d4);
  }
  else {
    *(undefined4 *)(param_1 + 0x1d4) = 0xc;
    (&DAT_0006768c)[iVar1] = 0xc;
  }
  if ((DAT_00067678 & 4) == 4) {
    (&DAT_00067690)[*(int *)(param_1 + 0x1bc) * 0x246] = *(undefined2 *)(param_1 + 0x1cc);
  }
  else {
    (&DAT_00067690)[*(int *)(param_1 + 0x1bc) * 0x246] = 0;
  }
  (&DAT_00067694)[*(int *)(param_1 + 0x1bc) * 0x123] = *(undefined4 *)(param_1 + 0x1c0);
  return;
}



/* 0002997c FUN_0002997c */

/* Boundary evidence: original MIPS .pdata 0002997c..00029ad3. Semantic name remains unreviewed. */

void FUN_0002997c(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = DAT_00067678 >> 0xc & 3;
  *(uint *)(param_1 + 0x1bc) = uVar3;
  *(uint *)(param_1 + 0x1d4) = (uint)(byte)(&DAT_0006768c)[uVar3 * 0x48c];
  if ((DAT_00067678 & 4) == 4) {
    uVar1 = (&DAT_00067690)[*(int *)(param_1 + 0x1bc) * 0x246];
    *(ushort *)(param_1 + 0x1cc) = uVar1;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    if (uVar1 != 0) {
      iVar2 = FUN_00030ec0(DAT_00067670,(uint)uVar1);
      *(int *)(param_1 + 0x1c0) = iVar2;
    }
    if (*(int *)(param_1 + 0x1c0) == 0) {
      *(undefined4 *)(param_1 + 0x1c0) = (&DAT_00067694)[*(int *)(param_1 + 0x1bc) * 0x123];
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x1cc) = 0;
    *(undefined4 *)(param_1 + 0x1c0) = (&DAT_00067694)[*(int *)(param_1 + 0x1bc) * 0x123];
  }
  *(char *)(*(int *)(param_1 + 0x44) + 0xa93) = (char)*(undefined4 *)(param_1 + 0x1d4);
  *(char *)(*(int *)(param_1 + 0x44) + 4) = (char)*(undefined4 *)(param_1 + 0x1bc);
  *(undefined4 *)(*(int *)(param_1 + 0x44) + 8) = *(undefined4 *)(param_1 + 0x1c0);
  if (*(ushort *)(param_1 + 0x1cc) == 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
  }
  else {
    FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                 (undefined4 *)(*(int *)(param_1 + 0x44) + 0xa97));
  }
  FUN_00036de8(0x6a,0);
  FUN_0002959c(param_1,1);
  return;
}



/* 00029ad4 FUN_00029ad4 */

/* Boundary evidence: original MIPS .pdata 00029ad4..00029d9b. Semantic name remains unreviewed. */

void FUN_00029ad4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = *(int *)(param_1 + 0x50);
  if ((iVar2 == 3) || (iVar2 == 4)) {
    NKDbgPrintfW(L"%S : SubMode is SEEK or AST(%d)\r\n","CRadio::StartSubModeTune");
  }
  else {
    if (iVar2 != 2) goto LAB_00029b5c;
    FUN_00028c70(param_1,1);
  }
  *(undefined4 *)(param_1 + 0x50) = 0;
LAB_00029b5c:
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeTune");
  }
  puVar3 = (uint *)(param_1 + 0x1c0);
  NKDbgPrintfW(L"%S : CurPI=%04X, CurFreq=%d)\r\n","CRadio::StartSubModeTune",
               *(undefined2 *)(param_1 + 0x1cc),*puVar3);
  if (param_3 == 1) {
    *(undefined4 *)(param_1 + 0x50) = 9;
  }
  else {
    *(undefined4 *)(param_1 + 0x50) = 1;
  }
  *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
  if (*(int *)(param_1 + 0x1bc) == 0) {
    iVar2 = FUN_00031860(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),*puVar3);
    *(int *)(param_1 + 0x1d0) = iVar2;
    if (-1 < iVar2) {
      uVar1 = FUN_00030f2c(DAT_00067670);
      *puVar3 = uVar1;
    }
  }
  if (*(int *)(param_1 + 0x1d0) < 0) {
    uVar1 = FUN_0002921c(param_1);
    iVar2 = *(int *)((uVar1 + 5) * 0x14 + *(int *)(param_1 + 0x1bc) * 0x40 + param_1);
    if (iVar2 == 0) {
      FUN_00015158(DAT_000648e4,3,1,0x33,(int)puVar3,4,100);
    }
    else if (iVar2 == 1) {
      FUN_00015158(DAT_000648e4,3,1,0x34,(int)puVar3,4,100);
    }
    else if (iVar2 == 4) {
      FUN_00015158(DAT_000648e4,3,1,0x32,(int)puVar3,4,100);
    }
  }
  else {
    iVar2 = FUN_00031014(DAT_00067670);
    if (param_2 == 1) {
      FUN_00015158(DAT_000648e4,3,1,0x31,iVar2,0x24,100);
    }
    else {
      FUN_00015158(DAT_000648e4,3,1,0x30,iVar2,0x24,100);
    }
  }
  if (*(int *)(param_1 + 0x1f0) == 1) {
    FUN_00029754(param_1,0);
    *(undefined4 *)(param_1 + 0x1f0) = 0;
  }
  if (*(short *)(param_1 + 0x1cc) != 0) {
    *(undefined4 *)(param_1 + 0x1f0) = 1;
  }
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  FUN_000292ec(param_1,0);
  FUN_0002959c(param_1,1);
  return;
}



/* 00029d9c FUN_00029d9c */

/* Boundary evidence: original MIPS .pdata 00029d9c..0002a107. Semantic name remains unreviewed. */

void FUN_00029d9c(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined2 local_5c;
  undefined1 local_5a;
  undefined1 local_59;
  undefined1 local_58;
  int local_50 [7];
  undefined2 local_34;
  undefined1 local_32;
  byte local_31;
  undefined1 local_30 [8];
  uint local_28;
  
  local_28 = DAT_00064820;
  bVar3 = false;
  bVar2 = true;
  if (*(int *)(param_1 + 0x50) != 3) {
    if (*(int *)(param_1 + 0x50) != 2) goto LAB_00029e10;
    FUN_00028c70(param_1,1);
    bVar3 = true;
  }
  bVar2 = false;
  *(undefined4 *)(param_1 + 0x50) = 0;
LAB_00029e10:
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeSeek");
  }
  NKDbgPrintfW(L"%S : CurPI=%04X, CurFreq=%d)\r\n","CRadio::StartSubModeSeek",
               *(undefined2 *)(param_1 + 0x1cc),*(undefined4 *)(param_1 + 0x1c0));
  *(undefined4 *)(param_1 + 0x50) = 3;
  *(undefined2 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1d4) = 0xc;
  *(undefined4 *)(param_1 + 0x1d8) = 0x24;
  if (bVar2) {
    *(undefined4 *)(param_1 + 0x1c4) = *(undefined4 *)(param_1 + 0x1c0);
  }
  uVar4 = FUN_0002921c(param_1);
  iVar9 = *(int *)(param_1 + 0x1bc) * 0x40;
  iVar5 = iVar9 + param_1;
  if (*(uint *)(iVar5 + 0x60) < 2) {
    local_59 = param_2 == 0;
    local_68 = *(int *)(param_1 + 0x1c0);
    local_5a = (undefined1)*(undefined4 *)((uVar4 + 5) * 0x14 + iVar9 + param_1);
    iVar5 = uVar4 * 0x14 + iVar9 + param_1;
    uVar4 = (uint)(local_68 - *(int *)(iVar5 + 0x68)) % *(uint *)(iVar5 + 0x70);
    if (*(uint *)(iVar5 + 0x70) == 0) {
      trap(0x1c00);
    }
    if (uVar4 != 0) {
      if (param_2 == 1) {
        local_68 = (local_68 - uVar4) + *(int *)(iVar5 + 0x70);
      }
      else {
        local_68 = local_68 - uVar4;
      }
    }
    local_64 = *(undefined4 *)(iVar5 + 0x68);
    local_60 = *(undefined4 *)(iVar5 + 0x6c);
    local_58 = (undefined1)*(undefined4 *)(iVar5 + 0x70);
    local_5c = 0;
    FUN_00015158(DAT_000648e4,3,1,1,(int)&local_68,0x14,100);
  }
  else {
    local_32 = param_2 == 0;
    local_31 = *(byte *)(iVar5 + 0x60);
    if (local_31 != 0) {
      piVar7 = local_50;
      puVar6 = (undefined4 *)(iVar5 + 0x70);
      uVar10 = 0;
      do {
        uVar8 = uVar10 + 1;
        local_30[uVar10] = (char)puVar6[-3];
        local_30[uVar10 + 3] = (char)*puVar6;
        *piVar7 = puVar6[-2];
        piVar1 = puVar6 + -1;
        puVar6 = puVar6 + 5;
        piVar7[3] = *piVar1;
        piVar7 = piVar7 + 1;
        uVar10 = uVar8;
      } while (uVar8 < local_31);
    }
    local_50[6] = *(int *)(param_1 + 0x1c0);
    iVar5 = uVar4 * 0x14 + iVar9 + param_1;
    uVar4 = *(uint *)(iVar5 + 0x70);
    uVar10 = (uint)(local_50[6] - *(int *)(iVar5 + 0x68)) % uVar4;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    if (uVar10 != 0) {
      if (param_2 == 1) {
        local_50[6] = (uVar4 - uVar10) + local_50[6];
      }
      else {
        local_50[6] = local_50[6] - uVar10;
      }
    }
    local_34 = 0;
    FUN_00015158(DAT_000648e4,3,1,2,(int)local_50,0x28,100);
  }
  *(char *)(*(int *)(param_1 + 0x44) + 0xa93) = (char)*(undefined4 *)(param_1 + 0x1d4);
  *(char *)(*(int *)(param_1 + 0x44) + 0xa94) = (char)*(undefined4 *)(param_1 + 0x1d8);
  if (*(int *)(param_1 + 0x1f0) == 1) {
    FUN_00029754(param_1,0);
    *(undefined4 *)(param_1 + 0x1f0) = 0;
  }
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  if (bVar3) {
    FUN_00015158(DAT_000648e4,3,1,0x21,0,0,100);
  }
  FUN_0004a3f4(local_28);
  return;
}



/* 0002a108 FUN_0002a108 */

/* Boundary evidence: original MIPS .pdata 0002a108..0002a267. Semantic name remains unreviewed. */

void FUN_0002a108(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  void *_Src;
  int iVar5;
  int iVar6;
  char local_60 [68];
  uint local_1c;
  
  local_1c = DAT_00064820;
  _Src = (void *)(*(int *)(param_1 + 0x44) + 0xaa3);
  iVar6 = 0;
  iVar5 = 0;
  memcpy(local_60,_Src,0x40);
  memset(_Src,0,0x44);
  uVar2 = 0;
  do {
    cVar1 = local_60[uVar2];
    if ((((cVar1 != ' ') && (cVar1 != '\0')) && (cVar1 != '\n')) && (cVar1 != '\r')) break;
    uVar2 = uVar2 + 1;
    iVar6 = iVar6 + 1;
  } while (uVar2 < 0x40);
  iVar4 = 0x3f;
  do {
    cVar1 = local_60[iVar4];
    if (((cVar1 != ' ') && (cVar1 != '\0')) && ((cVar1 != '\n' && (cVar1 != '\r')))) break;
    iVar4 = iVar4 + -1;
    iVar5 = iVar5 + 1;
  } while (iVar4 != 0);
  if ((uint)(iVar5 + iVar6) < 0x40) {
    uVar2 = 0;
    if (iVar5 != 0x40) {
      do {
        iVar4 = uVar2 + iVar6;
        iVar3 = uVar2 + *(int *)(param_1 + 0x44);
        uVar2 = uVar2 + 1;
        *(char *)(iVar3 + 0xaa3) = local_60[iVar4];
      } while (uVar2 < 0x40U - iVar5);
    }
  }
  FUN_0004a3f4(local_1c);
  return;
}



/* 0002a268 FUN_0002a268 */

/* Boundary evidence: original MIPS .pdata 0002a268..0002af83. Semantic name remains unreviewed. */

void FUN_0002a268(int param_1,int param_2,int param_3)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined2 *puVar14;
  char *_DstBuf;
  undefined2 *puVar15;
  int iVar16;
  int local_84;
  char local_70;
  undefined1 auStack_6f [15];
  byte local_60 [16];
  char acStack_50 [16];
  char acStack_40 [16];
  uint local_30;
  
  local_30 = DAT_00064820;
  local_70 = '\0';
  memset(auStack_6f,0,0xf);
  uVar8 = 0;
  do {
    _snprintf_s(&DAT_00066d10 + uVar8,0x10,0xf,"%s",
                (int)&DAT_000677c0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8);
    *(undefined2 *)((int)&DAT_00066d08 + uVar8) =
         *(undefined2 *)((int)&DAT_000677b8 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8);
    uVar12 = uVar8 + 0x18;
    *(undefined4 *)((int)&DAT_00066d0c + uVar8) =
         *(undefined4 *)((int)&DAT_000677bc + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8);
    uVar8 = uVar12;
  } while (uVar12 < 0x360);
  if (param_3 == 1) {
    uVar12 = 0;
    uVar8 = 0;
    do {
      uVar12 = uVar12 + 1;
      if (uVar12 < 0x24) {
        piVar9 = (int *)((int)&DAT_00066d24 + uVar8);
        iVar16 = 0x24 - uVar12;
        do {
          if ((*(int *)(param_1 + 0x1bc) == 0) && (param_2 == 1)) {
            if (((*(int *)((int)&DAT_00066d0c + uVar8) == *piVar9) ||
                (*(short *)((int)&DAT_00066d08 + uVar8) == (short)piVar9[-1])) &&
               (*(short *)((int)&DAT_00066d08 + uVar8) != 0)) {
              *(short *)((int)&DAT_00066d08 + uVar8) = 0;
              *(int *)((int)&DAT_00066d0c + uVar8) = 0;
LAB_0002a440:
              (&DAT_00066d10)[uVar8] = 0;
            }
          }
          else if (((param_2 == 0) || (*(int *)(param_1 + 0x1bc) == 1)) &&
                  (*(int *)((int)&DAT_00066d0c + uVar8) == *piVar9)) {
            *(undefined2 *)((int)&DAT_00066d08 + uVar8) = 0;
            *(int *)((int)&DAT_00066d0c + uVar8) = 0;
            goto LAB_0002a440;
          }
          iVar16 = iVar16 + -1;
          piVar9 = piVar9 + 6;
        } while (iVar16 != 0);
      }
      uVar8 = uVar8 + 0x18;
    } while (uVar8 < 0x348);
  }
  if ((*(int *)(param_1 + 0x1bc) == 0) && (param_2 == 1)) {
    DAT_00066638 = 0;
    DAT_0006663c = 0;
    DAT_00066640 = 0;
    DAT_00066644 = 0;
    uVar12 = 0;
    uVar8 = 0;
    do {
      uVar12 = uVar12 + 1;
      if (uVar12 < 0x24) {
        _DstBuf = &DAT_00066d28 + uVar8;
        pcVar10 = &DAT_00066d10 + uVar8;
        iVar16 = 0x24 - uVar12;
        do {
          bVar1 = false;
          uVar7 = 0;
          pbVar6 = local_60;
          do {
            bVar2 = pcVar10[uVar7];
            if (((bVar2 != 0x20) && (!bVar1)) || (bVar1)) {
              *pbVar6 = bVar2;
              if ((0x60 < bVar2) && (bVar2 < 0x7b)) {
                *pbVar6 = bVar2 - 0x20;
              }
              pbVar6 = pbVar6 + 1;
              bVar1 = true;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 0x10);
          sprintf_s(acStack_40,0x10,"%s",local_60);
          bVar1 = false;
          uVar7 = 0;
          pbVar6 = local_60;
          do {
            bVar2 = _DstBuf[uVar7];
            if (((bVar2 != 0x20) && (!bVar1)) || (bVar1)) {
              *pbVar6 = bVar2;
              if ((0x60 < bVar2) && (bVar2 < 0x7b)) {
                *pbVar6 = bVar2 - 0x20;
              }
              pbVar6 = pbVar6 + 1;
              bVar1 = true;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 0x10);
          sprintf_s(acStack_50,0x10,"%s",local_60);
          iVar5 = strcmp(acStack_40,acStack_50);
          if (0 < iVar5) {
            _snprintf_s(&local_70,0x10,0xf,"%s",_DstBuf);
            uVar4 = *(undefined2 *)(_DstBuf + -8);
            uVar13 = *(undefined4 *)(_DstBuf + -4);
            _snprintf_s(_DstBuf,0x10,0xf,"%s",pcVar10);
            *(undefined2 *)(_DstBuf + -8) = *(undefined2 *)((int)&DAT_00066d08 + uVar8);
            *(undefined4 *)(_DstBuf + -4) = *(undefined4 *)((int)&DAT_00066d0c + uVar8);
            _snprintf_s(pcVar10,0x10,0xf,"%s",&local_70);
            *(undefined4 *)((int)&DAT_00066d0c + uVar8) = uVar13;
            *(undefined2 *)((int)&DAT_00066d08 + uVar8) = uVar4;
          }
          iVar16 = iVar16 + -1;
          _DstBuf = _DstBuf + 0x18;
        } while (iVar16 != 0);
      }
      uVar8 = uVar8 + 0x18;
    } while (uVar8 < 0x348);
    uVar11 = 0;
    uVar8 = DAT_00066640;
    uVar12 = DAT_0006663c;
    uVar7 = DAT_00066644;
    do {
      pcVar10 = &DAT_00066d10 + uVar11;
      iVar16 = *(int *)((int)&DAT_00066d0c + uVar11);
      if (iVar16 == 0) {
LAB_0002a7e8:
        if (*(short *)((int)&DAT_00066d08 + uVar11) == 0) {
          DAT_00066644 = uVar7 + 1;
          uVar7 = DAT_00066644;
        }
      }
      else if ((*(short *)((int)&DAT_00066d08 + uVar11) == 0) ||
              ((*pcVar10 != '\0' && (*pcVar10 != '[')))) {
        if (iVar16 == 0) goto LAB_0002a7e8;
        if (*(short *)((int)&DAT_00066d08 + uVar11) == 0) {
          _snprintf_s(&DAT_00066650 + uVar8 * 0x18,0x10,0xf,"%s",pcVar10);
          (&DAT_00066648)[DAT_00066640 * 0xc] = *(short *)((int)&DAT_00066d08 + uVar11);
          (&DAT_0006664c)[DAT_00066640 * 6] = *(undefined4 *)((int)&DAT_00066d0c + uVar11);
          uVar8 = DAT_00066640 + 1;
          uVar12 = DAT_0006663c;
          uVar7 = DAT_00066644;
          DAT_00066640 = uVar8;
        }
        else if (iVar16 == 0) goto LAB_0002a7e8;
      }
      else {
        _snprintf_s(&DAT_000669b0 + uVar12 * 0x18,0x10,0xf,"%s",pcVar10);
        (&DAT_000669a8)[DAT_0006663c * 0xc] = *(short *)((int)&DAT_00066d08 + uVar11);
        (&DAT_000669ac)[DAT_0006663c * 6] = *(undefined4 *)((int)&DAT_00066d0c + uVar11);
        DAT_0006663c = DAT_0006663c + 1;
        uVar8 = DAT_00066640;
        uVar12 = DAT_0006663c;
        uVar7 = DAT_00066644;
      }
      uVar11 = uVar11 + 0x18;
    } while (uVar11 < 0x360);
    if ((uVar12 != 0) && (uVar7 = 0, uVar12 != 1)) {
      local_84 = 0;
      puVar15 = &DAT_000669c0;
      do {
        uVar7 = uVar7 + 1;
        puVar14 = puVar15;
        uVar8 = uVar7;
        if (uVar7 < uVar12) {
          do {
            if (*(uint *)(puVar14 + 2) < *(uint *)(puVar15 + -10)) {
              _snprintf_s(&local_70,0x10,0xf,"%s",puVar14 + 4);
              uVar4 = *puVar14;
              uVar13 = *(undefined4 *)(puVar14 + 2);
              _snprintf_s((char *)(puVar14 + 4),0x10,0xf,"%s",&DAT_000669b0 + local_84);
              *puVar14 = *(undefined2 *)((int)&DAT_000669a8 + local_84);
              *(undefined4 *)(puVar14 + 2) = *(undefined4 *)(puVar15 + -10);
              _snprintf_s(&DAT_000669b0 + local_84,0x10,0xf,"%s",&local_70);
              *(undefined2 *)((int)&DAT_000669a8 + local_84) = uVar4;
              *(undefined4 *)(puVar15 + -10) = uVar13;
              uVar12 = DAT_0006663c;
            }
            uVar8 = uVar8 + 1;
            puVar14 = puVar14 + 0xc;
          } while (uVar8 < uVar12);
        }
        local_84 = local_84 + 0x18;
        puVar15 = puVar15 + 0xc;
        uVar8 = DAT_00066640;
      } while (uVar7 < uVar12 - 1);
    }
    if ((uVar8 != 0) && (uVar12 = 0, uVar8 != 1)) {
      local_84 = 0;
      puVar15 = &DAT_00066660;
      do {
        uVar12 = uVar12 + 1;
        puVar14 = puVar15;
        uVar7 = uVar12;
        if (uVar12 < uVar8) {
          do {
            if (*(uint *)(puVar14 + 2) < *(uint *)(puVar15 + -10)) {
              _snprintf_s(&local_70,0x10,0xf,"%s",puVar14 + 4);
              uVar4 = *puVar14;
              uVar13 = *(undefined4 *)(puVar14 + 2);
              _snprintf_s((char *)(puVar14 + 4),0x10,0xf,"%s",&DAT_00066650 + local_84);
              *puVar14 = *(undefined2 *)((int)&DAT_00066648 + local_84);
              *(undefined4 *)(puVar14 + 2) = *(undefined4 *)(puVar15 + -10);
              _snprintf_s(&DAT_00066650 + local_84,0x10,0xf,"%s",&local_70);
              *(undefined2 *)((int)&DAT_00066648 + local_84) = uVar4;
              *(undefined4 *)(puVar15 + -10) = uVar13;
              uVar8 = DAT_00066640;
            }
            uVar7 = uVar7 + 1;
            puVar14 = puVar14 + 0xc;
          } while (uVar7 < uVar8);
        }
        local_84 = local_84 + 0x18;
        puVar15 = puVar15 + 0xc;
      } while (uVar12 < uVar8 - 1);
    }
    uVar12 = 0;
    uVar8 = DAT_00066638;
    do {
      if ((*(int *)((int)&DAT_00066d0c + uVar12) != 0) &&
         (*(short *)((int)&DAT_00066d08 + uVar12) != 0)) {
        cVar3 = (&DAT_00066d10)[uVar12];
        if ((cVar3 != '\0') && (cVar3 != '[')) {
          _snprintf_s(&DAT_00067070 + uVar8 * 0x18,0x10,0xf,"%s",&DAT_00066d10 + uVar12);
          (&DAT_00067068)[DAT_00066638 * 0xc] = *(short *)((int)&DAT_00066d08 + uVar12);
          (&DAT_0006706c)[DAT_00066638 * 6] = *(int *)((int)&DAT_00066d0c + uVar12);
          uVar8 = DAT_00066638 + 1;
          DAT_00066638 = uVar8;
        }
      }
      uVar12 = uVar12 + 0x18;
    } while (uVar12 < 0x360);
    uVar7 = 0;
    uVar12 = uVar8;
    if (uVar8 < 0x24) {
      puVar14 = &DAT_000669a8;
      puVar15 = &DAT_00067068 + uVar8 * 0xc;
      do {
        uVar12 = DAT_00066638;
        if (DAT_0006663c <= uVar7) break;
        _snprintf_s((char *)(puVar15 + 4),0x10,0xf,"%s",puVar14 + 4);
        uVar8 = uVar8 + 1;
        *puVar15 = *puVar14;
        uVar7 = uVar7 + 1;
        *(undefined4 *)(puVar15 + 2) = *(undefined4 *)(puVar14 + 2);
        puVar15 = puVar15 + 0xc;
        puVar14 = puVar14 + 0xc;
        uVar12 = DAT_00066638;
      } while (uVar8 < 0x24);
    }
    uVar8 = DAT_0006663c + uVar12;
    uVar7 = 0;
    if (uVar8 < 0x24) {
      puVar14 = &DAT_00066648;
      puVar15 = &DAT_00067068 + uVar8 * 0xc;
      do {
        uVar12 = DAT_00066638;
        if (DAT_00066640 <= uVar7) break;
        _snprintf_s((char *)(puVar15 + 4),0x10,0xf,"%s",puVar14 + 4);
        uVar8 = uVar8 + 1;
        *puVar15 = *puVar14;
        uVar7 = uVar7 + 1;
        *(undefined4 *)(puVar15 + 2) = *(undefined4 *)(puVar14 + 2);
        puVar15 = puVar15 + 0xc;
        puVar14 = puVar14 + 0xc;
        uVar12 = DAT_00066638;
      } while (uVar8 < 0x24);
    }
    uVar12 = DAT_00066640 + DAT_0006663c + uVar12;
    uVar8 = 0;
    if (uVar12 < 0x24) {
      puVar15 = &DAT_00067068 + uVar12 * 0xc;
      do {
        if (DAT_00066644 <= uVar8) break;
        uVar12 = uVar12 + 1;
        *(undefined1 *)(puVar15 + 4) = 0;
        *puVar15 = 0;
        *(undefined4 *)(puVar15 + 2) = 0;
        puVar15 = puVar15 + 0xc;
        uVar8 = uVar8 + 1;
      } while (uVar12 < 0x24);
    }
    iVar16 = 0;
    uVar8 = 0;
    do {
      *(undefined4 *)((int)&DAT_000677bc + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8) =
           *(undefined4 *)((int)&DAT_0006706c + uVar8);
      *(undefined2 *)((int)&DAT_000677b8 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8) =
           *(undefined2 *)((int)&DAT_00067068 + uVar8);
      _snprintf_s((char *)((int)&DAT_000677c0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8),0x10,0xf,
                  "%s",&DAT_00067070 + uVar8);
      FUN_000323f8(*(int *)(param_1 + 0x1bc),iVar16);
      uVar8 = uVar8 + 0x18;
      iVar16 = iVar16 + 1;
    } while (uVar8 < 0x360);
  }
  else if ((param_2 == 0) || (*(int *)(param_1 + 0x1bc) == 1)) {
    DAT_00066638 = 0;
    DAT_0006663c = 0;
    DAT_00066640 = 0;
    DAT_00066644 = 0;
    uVar12 = 0;
    uVar8 = 0;
    do {
      uVar7 = uVar8;
      if (*(int *)((int)&DAT_00066d0c + uVar12) == 0) break;
      uVar12 = uVar12 + 0x18;
      uVar8 = uVar7 + 1;
      DAT_00066638 = uVar7;
    } while (uVar12 < 0x360);
    if (DAT_00066638 != 0) {
      uVar8 = DAT_00066638 + 1;
      bVar1 = DAT_00066638 != 0;
      uVar12 = 0;
      DAT_00066638 = uVar8;
      if (bVar1) {
        local_84 = 0;
        puVar15 = &DAT_00066d20;
        do {
          uVar12 = uVar12 + 1;
          puVar14 = puVar15;
          uVar7 = uVar12;
          if (uVar12 < uVar8) {
            do {
              if (*(uint *)(puVar14 + 2) < *(uint *)(puVar15 + -10)) {
                _snprintf_s(&local_70,0x10,0xf,"%s",puVar14 + 4);
                uVar4 = *puVar14;
                uVar13 = *(undefined4 *)(puVar14 + 2);
                _snprintf_s((char *)(puVar14 + 4),0x10,0xf,"%s",&DAT_00066d10 + local_84);
                *puVar14 = *(undefined2 *)((int)&DAT_00066d08 + local_84);
                *(undefined4 *)(puVar14 + 2) = *(undefined4 *)(puVar15 + -10);
                _snprintf_s(&DAT_00066d10 + local_84,0x10,0xf,"%s",&local_70);
                *(undefined2 *)((int)&DAT_00066d08 + local_84) = uVar4;
                *(undefined4 *)(puVar15 + -10) = uVar13;
                uVar8 = DAT_00066638;
              }
              uVar7 = uVar7 + 1;
              puVar14 = puVar14 + 0xc;
            } while (uVar7 < uVar8);
          }
          local_84 = local_84 + 0x18;
          puVar15 = puVar15 + 0xc;
        } while (uVar12 < uVar8 - 1);
      }
    }
    iVar16 = 0;
    uVar8 = 0;
    do {
      *(undefined4 *)((int)&DAT_000677bc + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8) =
           *(undefined4 *)((int)&DAT_00066d0c + uVar8);
      *(undefined2 *)((int)&DAT_000677b8 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8) =
           *(undefined2 *)((int)&DAT_00066d08 + uVar8);
      _snprintf_s((char *)((int)&DAT_000677c0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8),0x10,0xf,
                  "%s",&DAT_00066d10 + uVar8);
      FUN_000323f8(*(int *)(param_1 + 0x1bc),iVar16);
      uVar8 = uVar8 + 0x18;
      iVar16 = iVar16 + 1;
    } while (uVar8 < 0x360);
  }
  FUN_0004a3f4(local_30);
  return;
}



/* 0002af84 FUN_0002af84 */

/* Boundary evidence: original MIPS .pdata 0002af84..0002b127. Semantic name remains unreviewed. */

void FUN_0002af84(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  UINT UVar3;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeTA");
  }
  NKDbgPrintfW(L"%S : CurPI=%04X, EONPI=0x%04X, CurFreq=%d, Type=%d,%d)\r\n",
               "CRadio::StartSubModeTA",*(undefined2 *)(param_1 + 0x1cc),
               *(undefined2 *)(param_1 + 0x1e4),*(undefined4 *)(param_1 + 0x1c0),
               *(undefined4 *)(param_1 + 0x1dc),*(undefined4 *)(param_1 + 0x1e0));
  if (*(int *)(param_1 + 0x4c) == 2) {
    *(undefined4 *)(param_1 + 0x290) = 0;
    FUN_00028c70(param_1,4);
  }
  *(undefined4 *)(param_1 + 0x50) = 5;
  if (*(int *)(param_1 + 0x1dc) == 2) {
    if (*(int *)(param_1 + 0x4c) == 1) {
      FUN_000298d4(param_1,0);
    }
    *(ushort *)(param_1 + 0x1cc) = *(ushort *)(param_1 + 0x1e4);
    uVar1 = FUN_00030fa8(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1e4));
    *(undefined4 *)(param_1 + 0x1d0) = uVar1;
    iVar2 = FUN_00030f2c(DAT_00067670);
    *(int *)(param_1 + 0x1c0) = iVar2;
    iVar2 = FUN_00031014(DAT_00067670);
    FUN_00015158(DAT_000648e4,3,1,0x37,iVar2,0x24,100);
    if (*(int *)(param_1 + 0x1f0) == 1) {
      FUN_00029754(param_1,0);
      *(undefined4 *)(param_1 + 0x1f0) = 0;
    }
    *(undefined4 *)(param_1 + 0x1f0) = 1;
    UVar3 = 3000;
    uVar1 = 2;
  }
  else {
    if (*(int *)(param_1 + 0x1dc) != 1) goto LAB_0002b0e8;
    UVar3 = 1000;
    uVar1 = 6;
  }
  FUN_00028be0(param_1,uVar1,UVar3);
LAB_0002b0e8:
  FUN_00015158(DAT_000648e4,3,1,0x21,0,0,100);
  return;
}



/* 0002b128 FUN_0002b128 */

/* Boundary evidence: original MIPS .pdata 0002b128..0002b277. Semantic name remains unreviewed. */

void FUN_0002b128(int param_1)

{
  uint uVar1;
  int iVar2;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  
  NKDbgPrintfW(L"%S : CurPI=%04X, CurFreq=%d)\r\n","CRadio::StartSubModeTPSeek",
               *(undefined2 *)(param_1 + 0x1cc),*(undefined4 *)(param_1 + 0x1c0));
  *(undefined4 *)(param_1 + 0x50) = 8;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined2 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1d4) = 0xc;
  *(undefined4 *)(param_1 + 0x1d8) = 0x24;
  uVar1 = FUN_0002921c(param_1);
  local_28 = *(int *)(param_1 + 0x1c0);
  local_19 = 1;
  local_1a = (undefined1)*(undefined4 *)((uVar1 + 5) * 0x14 + param_1);
  iVar2 = uVar1 * 0x14 + param_1;
  uVar1 = (uint)(local_28 - *(int *)(iVar2 + 0x68)) % *(uint *)(iVar2 + 0x70);
  if (*(uint *)(iVar2 + 0x70) == 0) {
    trap(0x1c00);
  }
  if (uVar1 != 0) {
    local_28 = local_28 - uVar1;
  }
  local_24 = *(undefined4 *)(iVar2 + 0x68);
  local_20 = *(undefined4 *)(iVar2 + 0x6c);
  local_18 = (undefined1)*(undefined4 *)(iVar2 + 0x70);
  local_1c = 0;
  FUN_00015158(DAT_000648e4,3,1,0x35,(int)&local_28,0x14,0x32);
  if (*(int *)(param_1 + 0x1f0) == 1) {
    FUN_00029754(param_1,0);
    *(undefined4 *)(param_1 + 0x1f0) = 0;
  }
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  return;
}



/* 0002b278 FUN_0002b278 */

/* Boundary evidence: original MIPS .pdata 0002b278..0002b2d7. Semantic name remains unreviewed. */

void FUN_0002b278(void)

{
  undefined1 local_10 [8];
  
  local_10[0] = (DAT_00067678 & 8) == 8;
  FUN_00014db0(DAT_000648e4,3,0,(int)local_10,1,0x32);
  return;
}



/* 0002b2d8 FUN_0002b2d8 */

/* Boundary evidence: original MIPS .pdata 0002b2d8..0002b337. Semantic name remains unreviewed. */

void FUN_0002b2d8(void)

{
  undefined1 local_10 [8];
  
  local_10[0] = (DAT_00067678 & 0x20) == 0x20;
  FUN_00014db0(DAT_000648e4,3,1,(int)local_10,1,0x32);
  return;
}



/* 0002b338 FUN_0002b338 */

/* Boundary evidence: original MIPS .pdata 0002b338..0002b46f. Semantic name remains unreviewed. */

void FUN_0002b338(void)

{
  errno_t eVar1;
  uint uVar2;
  undefined1 *puVar3;
  FILE *local_420 [2];
  undefined1 auStack_418 [1024];
  uint local_18;
  
  local_18 = DAT_00064820;
  eVar1 = fopen_s(local_420,".\\Storage Card\\system\\radparam_update.bin","rb");
  if (eVar1 == 0) {
    fread(auStack_418,0x400,1,local_420[0]);
    fclose(local_420[0]);
    uVar2 = 0;
    puVar3 = auStack_418;
    do {
      FUN_00014db0(DAT_000648e4,3,uVar2 + 0xe0,(int)puVar3,0x80,300);
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 0x80;
    } while (uVar2 < 8);
    FUN_00015158(DAT_000648e4,3,1,0xe1,0,0,1000);
    FUN_00015158(DAT_000648e4,3,1,0xe0,0,0,1000);
    FUN_00015158(DAT_000648e4,3,1,0xe2,0,0,100);
    DeleteFileW(L".\\Storage Card\\system\\radparam_update.bin");
  }
  FUN_0004a3f4(local_18);
  return;
}



/* 0002b470 FUN_0002b470 */

void FUN_0002b470(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  param_2[1] = 4;
  *param_2 = 1;
  param_2[4] = 100;
  if (param_3 == 3) {
    uVar1 = 76000;
    param_2[5] = 100;
    uVar2 = 90000;
LAB_0002b4ec:
    param_2[3] = uVar2;
    param_2[2] = uVar1;
    if (param_3 == 1) {
LAB_0002b5d8:
      uVar1 = 0x642;
      uVar2 = 0x213;
LAB_0002b5e0:
      param_2[0x12] = uVar2;
      param_2[0x14] = 9;
      param_2[0x15] = 1;
    }
    else {
      if (param_3 == 2) {
        if (param_4 != 1) {
          param_2[0x11] = 0;
          param_2[0x14] = 1;
          param_2[0x15] = 1;
          param_2[0x12] = 0x95;
          param_2[0x13] = 0x11b;
          if (param_4 != 2) {
            param_2[0x10] = 2;
            uVar2 = 0x213;
            uVar1 = 0x642;
LAB_0002b554:
            param_2[0x17] = uVar2;
            param_2[0x16] = 1;
            param_2[0x18] = uVar1;
            param_2[0x19] = 9;
            param_2[0x1a] = 1;
            return;
          }
          goto LAB_0002b5f8;
        }
        goto LAB_0002b5d8;
      }
      if (param_3 != 3) {
        if (param_3 == 4) goto LAB_0002b4c0;
        if (param_3 == 5) {
          uVar1 = 0x6ae;
          goto LAB_0002b580;
        }
        if (param_4 != 1) {
          param_2[0x11] = 0;
          param_2[0x14] = 1;
          param_2[0x15] = 1;
          param_2[0x12] = 0x95;
          param_2[0x13] = 0x11b;
          if (param_4 != 2) {
            param_2[0x10] = 2;
            uVar2 = 0x20a;
            uVar1 = 0x64b;
            goto LAB_0002b554;
          }
          goto LAB_0002b5f8;
        }
        uVar2 = 0x20a;
        uVar1 = 0x64b;
        goto LAB_0002b5e0;
      }
      uVar1 = 0x65d;
LAB_0002b580:
      param_2[0x12] = 0x20a;
      param_2[0x14] = 9;
      param_2[0x15] = 9;
    }
    param_2[0x13] = uVar1;
  }
  else {
    param_2[5] = 0x32;
    if (param_3 != 4) {
      uVar1 = 0x155cc;
      uVar2 = 0x1a5e0;
      goto LAB_0002b4ec;
    }
    param_2[2] = 0x15694;
    param_2[3] = 0x1a57c;
LAB_0002b4c0:
    param_2[0x12] = 0x212;
    param_2[0x13] = 0x6ae;
    param_2[0x14] = 10;
    param_2[0x15] = 1;
  }
  param_2[0x11] = 1;
LAB_0002b5f8:
  param_2[0x10] = 1;
  return;
}



/* 0002b604 FUN_0002b604 */

/* Boundary evidence: original MIPS .pdata 0002b604..0002b65b. Semantic name remains unreviewed. */

undefined4 * FUN_0002b604(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000585b8;
  FUN_0003008c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002b65c FUN_0002b65c */

/* Boundary evidence: original MIPS .pdata 0002b65c..0002b6f7. Semantic name remains unreviewed. */

void FUN_0002b65c(int param_1,byte param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = 2;
  if (param_3 != 1) {
    iVar1 = 0;
  }
  uVar3 = (uint)DAT_00068078;
  uVar4 = (uint)(param_4 == 1) + iVar1;
  if ((uVar3 != param_2) || (uVar2 = (uint)DAT_00063a30, uVar2 != uVar4)) {
    DAT_00063a30 = (byte)uVar4;
    DAT_00068078 = param_2;
    FUN_00031b58();
    uVar3 = (uint)DAT_00068078;
    uVar2 = (uint)DAT_00063a30;
  }
  FUN_0002b470(param_1,(undefined4 *)(param_1 + 0x60),uVar3,uVar2);
  return;
}



/* 0002b6f8 FUN_0002b6f8 */

/* Boundary evidence: original MIPS .pdata 0002b6f8..0002bc27. Semantic name remains unreviewed. */

void FUN_0002b6f8(int param_1,uint param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  if ((*(int *)(param_1 + 0x50) == 0) || (*(int *)(param_1 + 0x50) == 5)) {
    *(short *)(param_1 + 0x1cc) = (short)param_2;
    uVar4 = param_2 >> 8 & 0xf;
    uVar6 = 0;
    do {
      iVar3 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar6;
      uVar1 = *(ushort *)((int)&DAT_000677b8 + iVar3);
      uVar7 = uVar1 >> 8 & 0xf;
      if ((((((param_2 >> 0xc & 0xf) == (uint)(uVar1 >> 0xc)) && (uVar4 != uVar7)) &&
           ((param_2 >> 4 & 0xf) == (uVar1 >> 4 & 0xf))) &&
          (((param_2 & 0xf) == (uVar1 & 0xf) && (uVar4 == 3)))) && (uVar7 != 3)) {
        *(undefined4 *)((int)&DAT_000677bc + iVar3) = *(undefined4 *)(param_1 + 0x1c0);
        *(undefined2 *)((int)&DAT_000677b8 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar6) =
             *(undefined2 *)(param_1 + 0x1cc);
      }
      uVar6 = uVar6 + 0x18;
    } while (uVar6 < 0x360);
    iVar3 = 0;
    uVar4 = 0;
    do {
      iVar5 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar4;
      uVar6 = *(uint *)((int)&DAT_000677bc + iVar5);
      if (uVar6 == *(uint *)(param_1 + 0x1c0)) {
        if (*(short *)((int)&DAT_000677b8 + iVar5) == 0) {
          (&DAT_000677b8)[iVar3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] =
               *(undefined2 *)(param_1 + 0x1cc);
          iVar5 = *(int *)(param_1 + 0x1bc);
          if (iVar5 == 1) {
            sprintf_s(&DAT_00067c4c + iVar3 * 0x18,0x10,"%dkHz",(&DAT_00067c48)[iVar3 * 6]);
          }
          else if ((ushort)(&DAT_000677b8)[iVar3 * 0xc + iVar5 * 0x246] == 0) {
            uVar2 = __ultofp((&DAT_000677bc)[iVar3 * 6 + iVar5 * 0x123]);
            uVar8 = __fptodp(uVar2);
            __dpmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0xd2f1a9fc,0x3f50624d);
            sprintf_s((char *)(&DAT_000677c0 + iVar3 * 6 + iVar5 * 0x123),0x10,"%6.2fMHz");
          }
          else {
            FUN_000319b4(DAT_00067670,(uint)(ushort)(&DAT_000677b8)[iVar3 * 0xc + iVar5 * 0x246],
                         (&DAT_000677bc)[iVar3 * 6 + iVar5 * 0x123]);
            FUN_00030e3c(DAT_00067670,
                         (uint)(ushort)(&DAT_000677b8)
                                       [iVar3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246],
                         &DAT_000677c0 + iVar3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123);
          }
          break;
        }
        if ((uVar6 == *(uint *)(param_1 + 0x1c0)) &&
           (uVar7 = (uint)*(ushort *)((int)&DAT_000677b8 + iVar5),
           uVar7 == *(ushort *)(param_1 + 0x1cc))) {
          if (*(int *)(param_1 + 0x1bc) == 1) {
            sprintf_s((char *)((int)&DAT_000677c0 + iVar5),0x10,"%dkHz",uVar6);
          }
          else if (uVar7 == 0) {
            uVar2 = __ultofp(uVar6);
            uVar8 = __fptodp(uVar2);
            __dpmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0xd2f1a9fc,0x3f50624d);
            sprintf_s((char *)((int)&DAT_000677c0 + iVar5),0x10,"%6.2fMHz");
          }
          else {
            FUN_000319b4(DAT_00067670,uVar7,uVar6);
            iVar5 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar4;
            FUN_00030e3c(DAT_00067670,(uint)*(ushort *)((int)&DAT_000677b8 + iVar5),
                         (undefined4 *)((int)&DAT_000677c0 + iVar5));
          }
        }
      }
      uVar4 = uVar4 + 0x18;
      iVar3 = iVar3 + 1;
    } while (uVar4 < 0x360);
    FUN_0002a268(param_1,DAT_00067678 >> 2 & 1,0);
    uVar4 = 0;
    do {
      FUN_000323f8(*(int *)(param_1 + 0x1bc),uVar4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x24);
    if (*(HWND *)(param_1 + 0x5c) != (HWND)0x0) {
      PostMessageW(*(HWND *)(param_1 + 0x5c),0x403,5,(uint)*(ushort *)(param_1 + 0x1cc));
    }
    uVar2 = FUN_00031860(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),*(uint *)(param_1 + 0x1c0))
    ;
    *(undefined4 *)(param_1 + 0x1d0) = uVar2;
    iVar3 = FUN_00031014(DAT_00067670);
    FUN_00014db0(DAT_000648e4,3,3,iVar3,0x24,300);
    FUN_00029198(param_1);
    if (((DAT_00067678 & 4) == 4) &&
       (FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                     (undefined4 *)(*(int *)(param_1 + 0x44) + 0xa97)),
       *(int *)(param_1 + 0x4c) == 1)) {
      FUN_00036de8(0x6a,0);
    }
    if (*(int *)(param_1 + 0x28c) == 0) {
      FUN_000292ec(param_1,0);
      FUN_0002959c(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x1f0) = 1;
  }
  return;
}



/* 0002bc28 FUN_0002bc28 */

/* Boundary evidence: original MIPS .pdata 0002bc28..0002bd67. Semantic name remains unreviewed. */

void FUN_0002bc28(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x1c0);
  uVar1 = FUN_0002921c(param_1);
  if (param_3 == 1) {
    iVar4 = *(int *)(param_1 + 0x1bc) * 0x40;
    iVar3 = uVar1 * 0x14 + iVar4 + param_1;
    iVar2 = *(int *)(iVar3 + 0x70);
    if ((*(int *)(param_1 + 0x1bc) == 0) && (iVar2 == 0x32)) {
      iVar2 = 100;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x1bc) * 0x40;
    iVar3 = uVar1 * 0x14 + iVar4 + param_1;
    iVar2 = *(int *)(iVar3 + 0x74);
  }
  if (param_2 == 0) {
    uVar5 = iVar2 + uVar5;
    if (*(uint *)(iVar3 + 0x6c) < uVar5) {
      iVar2 = 0;
      if (uVar1 != *(int *)(iVar4 + param_1 + 0x60) - 1U) {
        iVar2 = uVar1 + 1;
      }
      uVar5 = *(uint *)(iVar2 * 0x14 + iVar4 + param_1 + 0x68);
    }
  }
  else if ((param_2 == 1) && (uVar5 = uVar5 - iVar2, uVar5 < *(uint *)(iVar3 + 0x68))) {
    if (uVar1 == 0) {
      uVar1 = *(uint *)(iVar4 + param_1 + 0x60);
    }
    uVar5 = *(uint *)((uVar1 - 1) * 0x14 + iVar4 + param_1 + 0x6c);
  }
  *(uint *)(param_1 + 0x1c0) = uVar5;
  return;
}



/* 0002bd68 FUN_0002bd68 */

/* Boundary evidence: original MIPS .pdata 0002bd68..0002c04f. Semantic name remains unreviewed. */

void FUN_0002bd68(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  NKDbgPrintfW(L"%S : main mode=%d, main mode step=%d, m_nSubMode=%d)\r\n",
               "CRadio::StartSubModeNone",*(undefined4 *)(param_1 + 0x4c),
               *(undefined4 *)(param_1 + 0x290),*(undefined4 *)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae7) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae8) = 0;
  iVar2 = *(int *)(param_1 + 0x4c);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x290) != 0) {
      return;
    }
    FUN_00015158(DAT_000648e4,3,1,0x20,0,0,100);
    FUN_0002997c(param_1);
    FUN_00029ad4(param_1,0,1);
    *(int *)(param_1 + 0x290) = *(int *)(param_1 + 0x290) + 1;
    FUN_0002b278();
    return;
  }
  if (iVar2 == 1) {
    if (*(int *)(param_1 + 0x290) != 0) {
      return;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa95) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xaa3) = 0;
    FUN_0002997c(param_1);
    FUN_00029ad4(param_1,0,1);
    *(int *)(param_1 + 0x290) = *(int *)(param_1 + 0x290) + 1;
    FUN_0002b278();
    FUN_00015158(DAT_000648e4,3,1,0x21,0,0,100);
    FUN_00036de8(0x6a,0);
    FUN_00036de8(0x6b,0);
    FUN_00036de8(0x6c,0);
    return;
  }
  if (iVar2 != 2) {
    return;
  }
  if (*(int *)(param_1 + 0x290) != 0) {
    return;
  }
  FUN_00015158(DAT_000648e4,3,1,0x20,0,0,100);
  FUN_0002b278();
  uVar1 = (&DAT_00067690)[*(int *)(param_1 + 0x1bc) * 0x246];
  *(ushort *)(param_1 + 0x1cc) = uVar1;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  if (uVar1 != 0) {
    iVar2 = FUN_00030ec0(DAT_00067670,(uint)uVar1);
    *(int *)(param_1 + 0x1c0) = iVar2;
  }
  if (*(int *)(param_1 + 0x1c0) == 0) {
    *(undefined4 *)(param_1 + 0x1c0) = (&DAT_00067694)[*(int *)(param_1 + 0x1bc) * 0x123];
  }
  *(undefined2 *)(param_1 + 0x1cc) = 0;
  if (*(int *)(param_1 + 0x1bc) == 0) {
    NKDbgPrintfW(L" Frequency !@!@!@   [ %d ] \r\n",*(undefined4 *)(param_1 + 0x1c0));
    if (*(uint *)(param_1 + 0x1c0) < 0x15630) {
      iVar2 = 0x2a30;
    }
    else {
      iVar2 = *(uint *)(param_1 + 0x1c0) - 100;
    }
  }
  else {
    if (*(int *)(param_1 + 0x1bc) != 1) goto LAB_0002bf14;
    NKDbgPrintfW(L" Frequency !@!@!@   [ %d ] \r\n",*(undefined4 *)(param_1 + 0x1c0));
    if (*(uint *)(param_1 + 0x1c0) < 0x65e) {
      if (*(uint *)(param_1 + 0x1c0) < 0x90) {
        *(undefined4 *)(param_1 + 0x1c0) = 0x90;
      }
      goto LAB_0002bf14;
    }
    iVar2 = 0x438;
  }
  *(int *)(param_1 + 0x1c0) = iVar2;
LAB_0002bf14:
  if (*(int *)(param_1 + 0x1bc) == 0) {
    FUN_0002b128(param_1);
  }
  *(undefined4 *)(param_1 + 0x290) = 1;
  return;
}



/* 0002c050 FUN_0002c050 */

/* Boundary evidence: original MIPS .pdata 0002c050..0002c15f. Semantic name remains unreviewed. */

void FUN_0002c050(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x50);
  if ((iVar1 == 3) || (iVar1 == 2)) {
    if (iVar1 == 2) {
      FUN_00015158(DAT_000648e4,3,1,0x21,0,0,100);
    }
    *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c4);
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (((iVar1 == 3) || (iVar1 == 4)) || (iVar1 == 2)) {
    FUN_00029ad4(param_1,0,1);
  }
  else if (((DAT_00067678 & 4) == 4) && (*(short *)(param_1 + 0x1cc) == 0)) {
    FUN_00015158(DAT_000648e4,3,1,0x32,param_1 + 0x1c0,4,100);
  }
  return;
}



/* 0002c160 FUN_0002c160 */

/* Boundary evidence: original MIPS .pdata 0002c160..0002c21b. Semantic name remains unreviewed. */

void FUN_0002c160(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 1) {
    if (iVar1 == 5) {
      *(undefined4 *)(param_1 + 0x1c0) = param_2;
      NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_TUNE_COMPLETE(TA) : %d\r\n","CRadio::StopSubModeTune",
                   param_2);
      FUN_00029198(param_1);
      return;
    }
    if (iVar1 != 9) {
      NKDbgPrintfW(L"%S[%d] : Sub-Mode is not SUBMODE_TUNE or SUBMODE_TA Check it out.!!!\r\n",
                   "CRadio::StopSubModeTune");
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x1c0) = param_2;
  NKDbgPrintfW(L"%S : SUBMODE_TUNE %d\r\n","CRadio::StopSubModeTune",param_2);
  FUN_00029198(param_1);
  FUN_0002bd68(param_1);
  return;
}



/* 0002c21c FUN_0002c21c */

/* Boundary evidence: original MIPS .pdata 0002c21c..0002c2c7. Semantic name remains unreviewed. */

void FUN_0002c21c(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x50) == 3) {
    *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c0) = param_2;
    *(undefined2 *)(param_1 + 0x1cc) = 0;
    NKDbgPrintfW(L"%S : m_nCurFreq-%d\r\n","CRadio::StopSubModeSeekFail",param_2);
    if (0xb < *(uint *)(param_1 + 0x1d4)) {
      FUN_000292ec(param_1,0);
    }
    FUN_0002959c(param_1,1);
    FUN_00029198(param_1);
    FUN_0002bd68(param_1);
  }
  else {
    NKDbgPrintfW(L"%S : Sub-Mode is not SUBMODE_SEEK. Check it out.!!!\r\n",
                 "CRadio::StopSubModeSeekFail");
  }
  return;
}



/* 0002c2c8 FUN_0002c2c8 */

/* Boundary evidence: original MIPS .pdata 0002c2c8..0002c373. Semantic name remains unreviewed. */

void FUN_0002c2c8(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x50) == 3) {
    *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c0) = param_2;
    *(undefined2 *)(param_1 + 0x1cc) = 0;
    NKDbgPrintfW(L"%S : m_nCurFreq-%d\r\n","CRadio::StopSubModeSeek",param_2);
    if (0xb < *(uint *)(param_1 + 0x1d4)) {
      FUN_000292ec(param_1,0);
    }
    FUN_0002959c(param_1,1);
    FUN_00029198(param_1);
    FUN_0002bd68(param_1);
  }
  else {
    NKDbgPrintfW(L"%S : Sub-Mode is not SUBMODE_SEEK. Check it out.!!!\r\n",
                 "CRadio::StopSubModeSeek");
  }
  return;
}



/* 0002c374 FUN_0002c374 */

/* Boundary evidence: original MIPS .pdata 0002c374..0002c61b. Semantic name remains unreviewed. */

void FUN_0002c374(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined4 local_48 [7];
  undefined1 local_2a;
  byte local_29;
  undefined1 local_28 [8];
  uint local_20;
  
  local_20 = DAT_00064820;
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeAST");
    if (*(int *)(param_1 + 0x50) == 2) {
      FUN_00028c70(param_1,1);
    }
    else if (*(int *)(param_1 + 0x50) != 3) goto LAB_0002c400;
    *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c4);
    FUN_0002bd68(param_1);
  }
LAB_0002c400:
  NKDbgPrintfW(L"%S : CurPI=%04X, CurFreq=%d)\r\n","CRadio::StartSubModeAST",
               *(undefined2 *)(param_1 + 0x1cc),*(undefined4 *)(param_1 + 0x1c0));
  *(undefined4 *)(param_1 + 0x50) = 4;
  *(undefined2 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1d4) = 0xc;
  *(undefined4 *)(param_1 + 0x1d8) = 0x24;
  uVar2 = FUN_0002921c(param_1);
  iVar5 = *(int *)(param_1 + 0x1bc) * 0x40;
  iVar3 = iVar5 + param_1;
  if (*(uint *)(iVar3 + 0x60) < 2) {
    local_51 = 1;
    local_52 = (undefined1)*(undefined4 *)((uVar2 + 5) * 0x14 + iVar5 + param_1);
    iVar3 = uVar2 * 0x14 + iVar5 + param_1;
    local_60 = *(undefined4 *)(iVar3 + 0x68);
    local_58 = *(undefined4 *)(iVar3 + 0x6c);
    local_50 = (undefined1)*(undefined4 *)(iVar3 + 0x70);
    local_5c = local_60;
    FUN_00015158(DAT_000648e4,3,1,5,(int)&local_60,0x14,100);
  }
  else {
    local_2a = 1;
    local_29 = *(byte *)(iVar3 + 0x60);
    if (local_29 != 0) {
      puVar6 = local_48;
      puVar4 = (undefined4 *)(iVar3 + 0x70);
      uVar2 = 0;
      do {
        uVar7 = uVar2 + 1;
        local_28[uVar2] = (char)puVar4[-3];
        local_28[uVar2 + 3] = (char)*puVar4;
        *puVar6 = puVar4[-2];
        puVar1 = puVar4 + -1;
        puVar4 = puVar4 + 5;
        puVar6[3] = *puVar1;
        puVar6 = puVar6 + 1;
        uVar2 = uVar7;
      } while (uVar7 < local_29);
    }
    local_48[6] = local_48[0];
    FUN_00015158(DAT_000648e4,3,1,6,(int)local_48,0x28,100);
  }
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae7) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae8) = 0;
  *(char *)(*(int *)(param_1 + 0x44) + 0xa93) = (char)*(undefined4 *)(param_1 + 0x1d4);
  *(char *)(*(int *)(param_1 + 0x44) + 0xa94) = (char)*(undefined4 *)(param_1 + 0x1d8);
  if (*(int *)(param_1 + 0x1f0) == 1) {
    FUN_00029754(param_1,0);
    *(undefined4 *)(param_1 + 0x1f0) = 0;
  }
  if (*(int *)(param_1 + 0x1f8) == 1) {
    *(undefined4 *)(param_1 + 0x204) = 1;
  }
  if ((*(int *)(param_1 + 0x200) == 1) || (*(int *)(param_1 + 0x200) == 0x1f)) {
    *(undefined4 *)(param_1 + 0x208) = 1;
  }
  FUN_0004a3f4(local_20);
  return;
}



/* 0002c61c FUN_0002c61c */

/* Boundary evidence: original MIPS .pdata 0002c61c..0002ccdb. Semantic name remains unreviewed. */

void FUN_0002c61c(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  int local_30 [2];
  
  NKDbgPrintfW(L"%S\r\n","CRadio::StopSubModeAST");
  if (*(int *)(param_1 + 0x50) == 4) {
    *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
    if (*(int *)(param_1 + 0x4c) == 1) {
      *(undefined2 *)(param_1 + 0x1cc) = 0;
      *(undefined4 *)(param_1 + 0x1c0) = param_2;
    }
    else {
      (&DAT_0006768c)[*(int *)(param_1 + 0x1bc) * 0x48c] = 0xc;
      (&DAT_00067690)[*(int *)(param_1 + 0x1bc) * 0x246] = 0;
      (&DAT_00067694)[*(int *)(param_1 + 0x1bc) * 0x123] = param_2;
    }
    NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_AST_COMPLETE : %d (SRC=%d)\r\n","CRadio::StopSubModeAST",
                 param_2,*(undefined4 *)(param_1 + 0x1bc));
    iVar6 = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    uVar5 = 0;
    do {
      uVar4 = 0;
      do {
        uVar1 = FUN_000153dc(DAT_000648e4,3,iVar6 + 0x20,local_30,8,300);
        if (uVar1 == 8) break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 3);
      if (uVar4 == 3) {
        NKDbgPrintfW(L"%S : Can\'t read AST Result.\r\n","CRadio::StopSubModeAST");
        break;
      }
      NKDbgPrintfW(L"%S : AST result get success[%d].\r\n","CRadio::StopSubModeAST",local_30[0]);
      iVar3 = local_30[0];
      if (local_30[0] == 0) {
        *(undefined4 *)((int)&DAT_000677bc + *(int *)(param_1 + 0x1bc) * 0x48c + uVar5) = 0;
        *(undefined2 *)((int)&DAT_000677b8 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar5) = 0;
        *(undefined1 *)((int)&DAT_000677c0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar5) = 0;
      }
      else {
        memset((void *)((int)&DAT_000677c0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar5),0,0x10);
        *(int *)((int)&DAT_000677bc + *(int *)(param_1 + 0x1bc) * 0x48c + uVar5) = iVar3;
        *(short *)((int)&DAT_000677b8 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar5) =
             (short)local_30[1];
        iVar3 = *(int *)(param_1 + 0x1bc);
        NKDbgPrintfW(L"PSN Before get success.\r\n");
        FUN_000153dc(DAT_000648e4,3,iVar6 + 0x60,
                     (void *)((int)&DAT_000677c0 + iVar3 * 0x48c + uVar5),8,300);
        iVar3 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar5;
        NKDbgPrintfW(L"%S : %d : FREQ-%d, PI-0x%04X, PSN - %c%c%c%c%c%c%c%c\r\n",
                     "CRadio::StopSubModeAST",iVar6,*(undefined4 *)((int)&DAT_000677bc + iVar3),
                     *(undefined2 *)((int)&DAT_000677b8 + iVar3),
                     *(undefined1 *)((int)&DAT_000677c0 + iVar3),
                     *(undefined1 *)((int)&DAT_000677c0 + iVar3 + 1),
                     *(undefined1 *)((int)&DAT_000677c0 + iVar3 + 2),
                     *(undefined1 *)((int)&DAT_000677c0 + iVar3 + 3),
                     *(undefined1 *)((int)&DAT_000677c4 + iVar3),
                     *(undefined1 *)((int)&DAT_000677c4 + iVar3 + 1),
                     *(undefined1 *)((int)&DAT_000677c4 + iVar3 + 2),
                     *(undefined1 *)((int)&DAT_000677c4 + iVar3 + 3));
        if (*(int *)(param_1 + 0x1bc) == 1) {
          sprintf_s(&DAT_00067c4c + uVar5,0x10,"%dkHz",*(undefined4 *)((int)&DAT_00067c48 + uVar5));
        }
        else {
          iVar3 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar5;
          if (*(ushort *)((int)&DAT_000677b8 + iVar3) == 0) {
            uVar2 = __ultofp(*(undefined4 *)((int)&DAT_000677bc + iVar3));
            uVar7 = __fptodp(uVar2);
            __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0xd2f1a9fc,0x3f50624d);
            sprintf_s((char *)((int)&DAT_000677c0 + iVar3),0x10,"%6.2fMHz");
          }
          else {
            FUN_000319b4(DAT_00067670,(uint)*(ushort *)((int)&DAT_000677b8 + iVar3),
                         *(uint *)((int)&DAT_000677bc + iVar3));
          }
        }
      }
      uVar5 = uVar5 + 0x18;
      iVar6 = iVar6 + 1;
    } while (uVar5 < 0x360);
    FUN_0002a268(param_1,DAT_00067678 >> 2 & 1,1);
    uVar5 = 0;
    do {
      FUN_0003220c(*(int *)(param_1 + 0x1bc),uVar5);
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0xc);
    FUN_0002928c(param_1);
    iVar6 = *(int *)(param_1 + 0x1bc);
    if (((&DAT_000677bc)[iVar6 * 0x123] != 0) &&
       (*(int *)(param_1 + 0x1c0) = (&DAT_000677bc)[iVar6 * 0x123], iVar6 == 0)) {
      *(ushort *)(param_1 + 0x1cc) = DAT_000677b8;
    }
    if (*(int *)(param_1 + 0x4c) == 1) {
      if ((iVar6 == 0) && ((DAT_00067678 & 4) == 4)) {
        if (DAT_000677bc != 0) {
          uVar5 = (uint)DAT_000677b8;
          *(ushort *)(param_1 + 0x1cc) = DAT_000677b8;
          iVar6 = FUN_00030ec0(DAT_00067670,uVar5);
          *(int *)(param_1 + 0x1c0) = iVar6;
          if (iVar6 == 0) {
            *(int *)(param_1 + 0x1c0) = (&DAT_000677bc)[*(int *)(param_1 + 0x1bc) * 0x123];
          }
        }
        *(undefined4 *)(param_1 + 0x1d8) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa94) = 0;
        FUN_00029ad4(param_1,1,0);
        if (*(ushort *)(param_1 + 0x1cc) != 0) {
          FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                       (undefined4 *)(*(int *)(param_1 + 0x44) + 0xa97));
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x1d8) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa94) = 0;
        FUN_00029ad4(param_1,1,0);
      }
    }
    else {
      (&DAT_00067690)[iVar6 * 0x246] = *(undefined2 *)(param_1 + 0x1cc);
      (&DAT_00067694)[*(int *)(param_1 + 0x1bc) * 0x123] = *(undefined4 *)(param_1 + 0x1c0);
      FUN_0002bd68(param_1);
    }
    FUN_00014db0(DAT_000648e4,3,0x20,0,0,0x1e);
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae7) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae8) = 0;
    FUN_00036de8(0x69,0);
    FUN_00015158(DAT_000648e4,3,1,0x21,0,0,100);
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    *(undefined4 *)(param_1 + 0x1f8) = 0;
    *(undefined4 *)(param_1 + 0x200) = 0;
    *(undefined4 *)(param_1 + 0x204) = 0;
    *(undefined4 *)(param_1 + 0x208) = 0;
    *(undefined4 *)(param_1 + 0x1dc) = 0;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
  }
  else {
    NKDbgPrintfW(L"%S : Sub-Mode is not SUBMODE_AST. Check it out.!!!\r\n","CRadio::StopSubModeAST")
    ;
  }
  return;
}



/* 0002ccdc FUN_0002ccdc */

/* Boundary evidence: original MIPS .pdata 0002ccdc..0002ce0b. Semantic name remains unreviewed. */

void FUN_0002ccdc(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 5) {
    NKDbgPrintfW(L"%S : SubMode is not SUBMODE_TA. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StopSubModeTA");
  }
  if (*(int *)(param_1 + 0x4c) != 1) {
    Sleep(200);
    FUN_00015158(DAT_000648e4,3,1,0x20,0,0,100);
  }
  if (*(int *)(param_1 + 0x4c) == 2) {
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
  }
  if (*(int *)(param_1 + 0x1dc) == 2) {
    NKDbgPrintfW(L"%S : Return to original frequency)\r\n","CRadio::StopSubModeTA",
                 *(undefined4 *)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined2 *)(param_1 + 0x1ec) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(undefined1 *)(param_1 + 0x1ee) = 0;
  }
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  if (*(int *)(param_1 + 0x200) == 1) {
    *(undefined4 *)(param_1 + 0x1e0) = 2;
  }
  else if (*(int *)(param_1 + 0x200) == 0x1f) {
    *(undefined4 *)(param_1 + 0x1e0) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x1e0) = 0;
  }
  *(undefined2 *)(param_1 + 0x1e4) = 0;
  FUN_00028c70(param_1,6);
  FUN_0002bd68(param_1);
  return;
}



/* 0002ce0c FUN_0002ce0c */

/* Boundary evidence: original MIPS .pdata 0002ce0c..0002d01f. Semantic name remains unreviewed. */

void FUN_0002ce0c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(int *)(param_1 + 0x50) == 3) {
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeCTune");
  }
  *(undefined4 *)(param_1 + 0x50) = 2;
  *(undefined2 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
  *(int *)(param_1 + 0x1c8) = *(int *)(param_1 + 0x1d4);
  if (*(int *)(param_1 + 0x1d4) != 0xc) {
    *(undefined4 *)(param_1 + 0x1d4) = 0xc;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa93) = 0xc;
    FUN_00036de8(0x66,0);
  }
  *(undefined4 *)(param_1 + 0x1d8) = 0x24;
  *(undefined4 *)(param_1 + 0x1c4) = *(undefined4 *)(param_1 + 0x1c0);
  FUN_00015158(DAT_000648e4,3,1,0x20,0,0,100);
  uVar1 = FUN_0002921c(param_1);
  iVar3 = *(int *)(param_1 + 0x1bc) * 0x40;
  if (*(int *)((uVar1 + 5) * 0x14 + iVar3 + param_1) == 4) {
    uVar2 = *(uint *)(param_1 + 0x1c0);
    iVar3 = uVar1 * 0x14 + iVar3 + param_1;
    uVar1 = *(uint *)(iVar3 + 0x68);
    uVar4 = *(uint *)(iVar3 + 0x70);
    uVar5 = (uVar2 - uVar1) % uVar4;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    if (uVar5 != 0) {
      if (param_2 == 0) {
        uVar2 = uVar2 - uVar5;
      }
      else {
        uVar2 = (uVar4 - uVar5) + uVar2;
      }
    }
    if (uVar2 % 100 != 0) {
      if (param_2 == 0) {
        uVar4 = uVar2 + 0x32;
      }
      else {
        uVar4 = uVar2 - 0x32;
      }
      uVar2 = uVar1;
      if ((uVar4 <= *(uint *)(iVar3 + 0x6c)) && (uVar2 = uVar4, uVar4 < uVar1)) {
        uVar2 = *(uint *)(iVar3 + 0x6c);
      }
    }
    *(uint *)(param_1 + 0x1c0) = uVar2;
  }
  *(int *)(param_1 + 0x58) = param_2;
  FUN_0002bc28(param_1,param_2,1);
  FUN_00029198(param_1);
  if (*(int *)(param_1 + 0x1f0) == 1) {
    FUN_00029754(param_1,0);
    *(undefined4 *)(param_1 + 0x1f0) = 0;
  }
  FUN_00028be0(param_1,1,0x32);
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  return;
}



/* 0002d020 FUN_0002d020 */

/* Boundary evidence: original MIPS .pdata 0002d020..0002d07b. Semantic name remains unreviewed. */

void FUN_0002d020(int param_1,undefined4 param_2)

{
  NKDbgPrintfW(L"%S : CurFreq=%d)\r\n","CRadio::StopSubModeTPSeek",param_2);
  *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = param_2;
  FUN_0002bd68(param_1);
  return;
}



/* 0002d07c FUN_0002d07c */

/* Boundary evidence: original MIPS .pdata 0002d07c..0002d0f3. Semantic name remains unreviewed. */

void FUN_0002d07c(int param_1,undefined4 param_2)

{
  NKDbgPrintfW(L"%S\r\n","CRadio::StopSubModeOffSeek");
  *(undefined4 *)(param_1 + 0x1d0) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = param_2;
  NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_SEEK_COMPLETE : m_nCurFreq-%d\r\n",
               "CRadio::StopSubModeOffSeek",param_2);
  FUN_0002bd68(param_1);
  return;
}



/* 0002d0f4 FUN_0002d0f4 */

/* Boundary evidence: original MIPS .pdata 0002d0f4..0002d35f. Semantic name remains unreviewed. */

void FUN_0002d0f4(int param_1)

{
  uint uVar1;
  int iVar2;
  char local_18 [8];
  
  iVar2 = *(int *)(param_1 + 0x48);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x54) != 2) {
      if (*(int *)(param_1 + 0x54) == 6) {
        NKDbgPrintfW(L"%S(nID=%d)\r\n","CRadio::KillTimer",0);
        *(undefined4 *)(param_1 + 0x48) = 0;
        FUN_0003006c(param_1);
        *(undefined4 *)(param_1 + 0x54) = 0;
      }
      else {
        NKDbgPrintfW(L"%S(nID=%d)\r\n","CRadio::KillTimer",0);
        *(undefined4 *)(param_1 + 0x48) = 0;
        FUN_0003006c(param_1);
      }
    }
  }
  else if (iVar2 == 1) {
    FUN_0002bc28(param_1,*(int *)(param_1 + 0x58),1);
    FUN_0002bc28(param_1,*(int *)(param_1 + 0x58),1);
    FUN_00029198(param_1);
  }
  else if (iVar2 == 2) {
    FUN_00028c70(param_1,2);
    FUN_00028be0(param_1,6,500);
  }
  else {
    if (iVar2 == 3) {
      iVar2 = 3;
    }
    else {
      if (iVar2 != 4) {
        if (iVar2 == 5) {
          FUN_00028c70(param_1,5);
          NKDbgPrintfW(L"%S : TT_TA_OFF_DELAY : Send IDM_MMCM_AMAIN_TA_PTY31_STOP, m_nAnnounceType[0] : %d, m_nSubMode : %d\r\n"
                       ,"CRadio::OnTimer",*(undefined4 *)(param_1 + 0x1dc),
                       *(undefined4 *)(param_1 + 0x50));
          FUN_00036de8(0x6e,0);
          iVar2 = FUN_00011e88(DAT_00064828);
          if ((((iVar2 != 8) && (iVar2 = FUN_00011e88(DAT_00064828), iVar2 != 10)) &&
              (iVar2 = FUN_00011e88(DAT_00064828), iVar2 != 7)) &&
             (iVar2 = FUN_00011e88(DAT_00064828), iVar2 != 0xc)) {
            return;
          }
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae9) = 0;
          return;
        }
        if (iVar2 != 6) {
          return;
        }
        NKDbgPrintfW(L"%S : TT_CHECK_TA_OFF : Running\r\n","CRadio::OnTimer");
        uVar1 = FUN_000153dc(DAT_000648e4,4,0x12,local_18,1,0x32);
        if (uVar1 != 1) {
          return;
        }
        if ((local_18[0] != '\0') && (local_18[0] != '\x02')) {
          return;
        }
        FUN_00028c70(param_1,6);
        FUN_00028f88(param_1);
        return;
      }
      iVar2 = 4;
    }
    FUN_00028c70(param_1,iVar2);
    FUN_0002bd68(param_1);
  }
  return;
}



/* 0002d360 FUN_0002d360 */

/* Boundary evidence: original MIPS .pdata 0002d360..0002de07. Semantic name remains unreviewed. */

void FUN_0002d360(int param_1,undefined4 param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  LPARAM *pLVar5;
  uint uVar6;
  undefined1 local_28;
  undefined1 local_27;
  
  switch(param_2) {
  case 0x65:
    if ((DAT_00067678 >> 0xc & 3) == param_3) {
      local_27 = DAT_00067683;
      local_28 = 0;
      FUN_00015158(DAT_000648e4,5,1,0,(int)&local_28,2,0x32);
    }
    else {
      *(undefined1 *)(param_1 + 0x20c) = 0;
      *(undefined1 *)(param_1 + 0x24c) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa95) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xaa3) = 0;
      iVar3 = *(int *)(param_1 + 0x50);
      if ((iVar3 == 3) || (iVar3 == 2)) {
        if (iVar3 == 2) {
          FUN_00015158(DAT_000648e4,3,1,0x21,0,0,100);
        }
        *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c4);
      }
      if (*(int *)(param_1 + 0x4c) == 1) {
        FUN_000298d4(param_1,0);
      }
      DAT_00067678 = (param_3 << 0xc ^ DAT_00067678) & 0x3000 ^ DAT_00067678;
      FUN_0002997c(param_1);
      FUN_00029ad4(param_1,0,1);
      FUN_00011498(DAT_00064828,1,0);
    }
    break;
  case 0x6a:
    if (*(int *)(param_1 + 0x4c) == 1) {
      FUN_0002928c(param_1);
      FUN_00029d9c(param_1,param_3);
    }
    break;
  case 0x6b:
    FUN_0002928c(param_1);
    iVar3 = *(int *)(param_1 + 0x50);
    *(undefined2 *)(param_1 + 0x1cc) = 0;
    if (((iVar3 != 2) && (iVar3 != 3)) && (iVar3 != 4)) {
      FUN_0002bc28(param_1,param_3,0);
    }
    goto LAB_0002da94;
  case 0x6c:
    FUN_0002928c(param_1);
    FUN_0002ce0c(param_1,param_3);
    break;
  case 0x6d:
    FUN_0002c374(param_1);
    break;
  case 0x6e:
    if (*(int *)(param_1 + 0x50) != 4) {
      return;
    }
    *(undefined2 *)(param_1 + 0x1cc) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae7) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae8) = 0;
LAB_0002da94:
    FUN_00029ad4(param_1,0,0);
    break;
  case 0x6f:
    if (param_3 < 0x30) {
      if (param_3 < 0xc) {
        if (*(uint *)(param_1 + 0x1d4) == param_3) {
          return;
        }
        if ((&DAT_0006769c)[param_3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] == 0) {
          return;
        }
        *(undefined1 *)(param_1 + 0x20c) = 0;
        *(undefined1 *)(param_1 + 0x24c) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
        pLVar5 = (LPARAM *)(param_1 + 0x1c0);
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa95) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xaa3) = 0;
        *pLVar5 = (&DAT_0006769c)[param_3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123];
        *(uint *)(param_1 + 0x1d4) = param_3;
        *(char *)(*(int *)(param_1 + 0x44) + 0xa93) = (char)param_3;
        (&DAT_0006768c)[*(int *)(param_1 + 0x1bc) * 0x48c] = (char)*(undefined4 *)(param_1 + 0x1d4);
        if ((DAT_00067678 & 4) == 4) {
          *(undefined2 *)(param_1 + 0x1cc) =
               (&DAT_00067698)[param_3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246];
          *(LPARAM *)(*(int *)(param_1 + 0x44) + 8) = *pLVar5;
          FUN_00036de8(0x65,*pLVar5);
          iVar3 = *(int *)(param_1 + 0x50);
          if ((iVar3 == 3) || (iVar3 == 4)) {
            NKDbgPrintfW(L"%S : SubMode is SEEK or AST(%d)\r\n","CRadio::OnMessage");
          }
          else {
            if (iVar3 != 2) goto LAB_0002d6b4;
            FUN_00028c70(param_1,1);
          }
          *(undefined4 *)(param_1 + 0x50) = 0;
LAB_0002d6b4:
          if (*(int *)(param_1 + 0x50) != 0) {
            NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                         "CRadio::OnMessage");
          }
          NKDbgPrintfW(L"%S : CurPI=%04X, CurFreq=%d)\r\n","CRadio::OnMessage",
                       *(undefined2 *)(param_1 + 0x1cc),*pLVar5);
          *(undefined4 *)(param_1 + 0x50) = 1;
          uVar6 = FUN_0002921c(param_1);
          iVar3 = *(int *)((uVar6 + 5) * 0x14 + *(int *)(param_1 + 0x1bc) * 0x40 + param_1);
          if (iVar3 == 0) {
            FUN_00015158(DAT_000648e4,3,1,0x33,(int)pLVar5,4,100);
          }
          else if (iVar3 == 1) {
            FUN_00015158(DAT_000648e4,3,1,0x34,(int)pLVar5,4,100);
          }
          else if (iVar3 == 4) {
            FUN_00015158(DAT_000648e4,3,1,0x32,(int)pLVar5,4,100);
          }
          *(undefined4 *)(param_1 + 0x1fc) = 0;
          *(undefined4 *)(param_1 + 0x1f8) = 0;
          *(undefined4 *)(param_1 + 0x200) = 0;
          FUN_000292ec(param_1,0);
          FUN_0002959c(param_1,1);
          return;
        }
        *(undefined2 *)(param_1 + 0x1cc) = 0;
      }
      else {
        iVar3 = param_3 - 0xc;
        if (*(int *)(param_1 + 0x1d8) == iVar3) {
          return;
        }
        if ((&DAT_000677bc)[iVar3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] == 0) {
          return;
        }
        uVar4 = (undefined1)iVar3;
        if ((DAT_00067678 & 4) == 4) {
          if ((*(short *)(param_1 + 0x1cc) != 0) &&
             (*(short *)(param_1 + 0x1cc) ==
              (&DAT_000677b8)[iVar3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246])) {
            *(int *)(param_1 + 0x1d8) = iVar3;
            *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa94) = uVar4;
            return;
          }
          *(undefined1 *)(param_1 + 0x20c) = 0;
          *(undefined1 *)(param_1 + 0x24c) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa95) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xaa3) = 0;
          uVar1 = (&DAT_000677b8)[iVar3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246];
          *(ushort *)(param_1 + 0x1cc) = uVar1;
          iVar2 = FUN_00030ec0(DAT_00067670,(uint)uVar1);
          *(int *)(param_1 + 0x1c0) = iVar2;
          if (iVar2 == 0) {
            *(undefined4 *)(param_1 + 0x1c0) =
                 (&DAT_000677bc)[iVar3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123];
          }
          *(int *)(param_1 + 0x1d8) = iVar3;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa94) = uVar4;
          FUN_00029ad4(param_1,1,0);
          if (*(ushort *)(param_1 + 0x1cc) != 0) {
            FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                         (undefined4 *)(*(int *)(param_1 + 0x44) + 0xa97));
          }
          goto LAB_0002d9a4;
        }
        *(undefined1 *)(param_1 + 0x20c) = 0;
        *(undefined1 *)(param_1 + 0x24c) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa95) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xaa3) = 0;
        *(undefined2 *)(param_1 + 0x1cc) = 0;
        *(undefined4 *)(param_1 + 0x1c0) =
             (&DAT_000677bc)[iVar3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123];
        *(int *)(param_1 + 0x1d8) = iVar3;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa94) = uVar4;
      }
      FUN_00029ad4(param_1,1,0);
LAB_0002d9a4:
      FUN_00036de8(0x6a,0);
      FUN_00036de8(0x6b,0);
      FUN_00036de8(0x6c,0);
      *(undefined4 *)(param_1 + 0x204) = 0;
      *(undefined4 *)(param_1 + 0x208) = 0;
      *(undefined4 *)(param_1 + 0x1dc) = 0;
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      return;
    }
    if (param_3 < 0x65) {
      return;
    }
    if (199999 < param_3) {
      return;
    }
    *(uint *)(param_1 + 0x1c0) = param_3;
    goto LAB_0002da00;
  case 0x70:
    if (*(int *)(param_1 + 0x50) == 2) {
      FUN_00028c70(param_1,1);
LAB_0002db30:
      FUN_0002bd68(param_1);
      FUN_00029198(param_1);
      FUN_00029ad4(param_1,1,0);
    }
    else if (*(int *)(param_1 + 0x50) == 3) goto LAB_0002db30;
    FUN_00028cf8(param_1,param_3);
    break;
  case 0x81:
    if (*(byte *)(*(int *)(param_1 + 0x44) + 0xa8c) == param_3) {
      return;
    }
    DAT_00067678 = ((uint)(param_3 != 0) << 2 ^ DAT_00067678) & 4 ^ DAT_00067678;
    *(bool *)(*(int *)(param_1 + 0x44) + 0xa8c) = (DAT_00067678 & 4) != 0;
    if (DAT_00068078 != '\x04') {
      DAT_00067678 = (DAT_00067678 << 1 ^ DAT_00067678) & 8 ^ DAT_00067678;
    }
    FUN_0002a268(param_1,DAT_00067678 >> 2 & 1,0);
    uVar6 = 0;
    do {
      FUN_0003220c(0,uVar6);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0xc);
    FUN_0002b2d8();
    FUN_0002b278();
    local_28 = (DAT_00067678 & 4) != 4;
    FUN_00014db0(DAT_000648e4,4,0x80,(int)&local_28,1,0x32);
    FUN_00014db0(DAT_000648e4,3,8,(int)&local_28,1,100);
LAB_0002da00:
    *(undefined2 *)(param_1 + 0x1cc) = 0;
    FUN_00029ad4(param_1,1,0);
    FUN_0002928c(param_1);
    *(undefined4 *)(param_1 + 0x204) = 0;
    *(undefined4 *)(param_1 + 0x208) = 0;
    break;
  case 0x82:
    DAT_00067678 = ((uint)(param_3 != 0) << 4 ^ DAT_00067678) & 0x10 ^ DAT_00067678;
    *(bool *)(*(int *)(param_1 + 0x44) + 0xa8d) = param_3 != 0;
    break;
  case 0x83:
    DAT_00067678 = ((uint)(param_3 != 0) << 5 ^ DAT_00067678) & 0x20 ^ DAT_00067678;
    FUN_0002b2d8();
    *(bool *)(*(int *)(param_1 + 0x44) + 0xa8e) = param_3 != 0;
    break;
  case 0x84:
    DAT_00067678 = ((uint)(param_3 != 0) << 6 ^ DAT_00067678) & 0x40 ^ DAT_00067678;
    *(bool *)(*(int *)(param_1 + 0x44) + 0xa8f) = param_3 != 0;
    break;
  case 0x85:
    DAT_00067678 = ((uint)(param_3 != 0) << 7 ^ DAT_00067678) & 0x80 ^ DAT_00067678;
    *(bool *)(*(int *)(param_1 + 0x44) + 0xa90) = param_3 != 0;
    break;
  case 0x8d:
    DAT_00067678 = ((uint)(param_3 != 0) << 3 ^ DAT_00067678) & 8 ^ DAT_00067678;
    FUN_0002b278();
  }
  return;
}



/* 0002de08 FUN_0002de08 */

/* Boundary evidence: original MIPS .pdata 0002de08..0002f953. Semantic name remains unreviewed. */

void FUN_0002de08(int param_1,uint *param_2)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  HWND hWnd;
  wchar_t *pwVar4;
  LPARAM LVar5;
  WPARAM wParam;
  int iVar6;
  int iVar7;
  char cVar8;
  size_t _Size;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  char *pcVar19;
  uint *puVar20;
  undefined4 *_Buf2;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined1 local_30 [4];
  uint local_2c;
  
  local_2c = DAT_00064820;
  uVar10 = *param_2 >> 8 & 0xf;
  if (uVar10 != 2) {
    if ((uVar10 != 3) || (*(char *)((int)param_2 + 2) != '\x02')) goto switchD_0002df3c_caseD_1;
    NKDbgPrintfW(L"%S : CMD_APP_RADIO_ALIGNMENT_NOTI : %d : ","CRadio::OnCommand",
                 *(undefined1 *)((int)param_2 + 5));
    uVar10 = param_2[1];
    uVar17 = 0;
    if ((byte)uVar10 != 2) {
      puVar20 = param_2 + 2;
      do {
        *(undefined1 *)(param_1 + 0xc + uVar17) = *(undefined1 *)((int)param_2 + uVar17 + 6);
        NKDbgPrintfW(L"0x%02X ",(short)*puVar20);
        uVar17 = uVar17 + 1;
        puVar20 = (uint *)((int)puVar20 + 2);
      } while (uVar17 < (byte)uVar10 - 2);
    }
    NKDbgPrintfW(&DAT_00053ebc);
    hWnd = *(HWND *)(param_1 + 0x5c);
    if (hWnd == (HWND)0x0) goto switchD_0002df3c_caseD_1;
    bVar1 = *(byte *)((int)param_2 + 5);
    wParam = 4;
LAB_0002e118:
    uVar10 = (uint)bVar1;
    goto LAB_0002e11c;
  }
  switch(*(undefined1 *)((int)param_2 + 2)) {
  case 0:
    FUN_0002b338();
    if (DAT_00068078 == '\x04') {
      DAT_00067678 = DAT_00067678 & 0xfffffff7;
    }
    else {
      DAT_00067678 = (DAT_00067678 << 1 ^ DAT_00067678) & 8 ^ DAT_00067678;
    }
    NKDbgPrintfW(L"[RADIO RDS] case CMD_APP_BOOT_STAT_NOTI : g_radio_country = %d, g_stData.en_rds = %d, g_stData.en_af = %d\r\n"
                 ,DAT_00068078,DAT_00067678 >> 2 & 1,DAT_00067678 >> 3 & 1);
    FUN_0002b2d8();
    FUN_0002b278();
    local_30[0] = (DAT_00067678 & 4) != 4;
    FUN_00014db0(DAT_000648e4,4,0x80,(int)local_30,1,0x32);
    FUN_00014db0(DAT_000648e4,3,8,(int)local_30,1,100);
    break;
  case 0x1e:
    hWnd = *(HWND *)(param_1 + 0x5c);
    if (hWnd == (HWND)0x0) break;
    uVar10 = 0;
    wParam = 10;
    goto LAB_0002e11c;
  case 0x1f:
    if (*(int *)(param_1 + 0x5c) == 0) break;
    wParam = 9;
    *(uint *)(param_1 + 0x2c) = param_2[1];
    *(uint *)(param_1 + 0x30) = param_2[2];
    *(uint *)(param_1 + 0x34) = param_2[3];
    *(short *)(param_1 + 0x38) = (short)param_2[4];
    goto LAB_0002f8a4;
  case 0x40:
    if ((*(int *)(param_1 + 0x1bc) == 0) &&
       (uVar10 = param_2[1], uVar10 < *(uint *)(param_1 + 0x68))) {
      iVar6 = 0;
    }
    else {
      if ((*(int *)(param_1 + 0x1bc) != 1) ||
         (uVar10 = param_2[1], uVar10 <= *(uint *)(param_1 + 0x68))) goto LAB_0002e35c;
      iVar6 = 1;
    }
    pwVar4 = L"[band error] %S : NOTI_APP_FREQCHG_TUNE_COMPLETE : [%d]%d\r\n";
    goto LAB_0002e34c;
  case 0x41:
    *(undefined4 *)(param_1 + 0x1f0) = 0;
    *(uint *)(param_1 + 0x1c0) = (*(ushort *)((int)param_2 + 6) + 0x36b) * 100;
    NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_STATION_TUNE_RGN : %04X, %d\r\n","CRadio::OnCommand",
                 (short)param_2[1]);
    FUN_0002b6f8(param_1,(uint)(ushort)param_2[1]);
    uVar10 = *(uint *)(param_1 + 0x1c0);
    goto LAB_0002e360;
  case 0x42:
    *(undefined2 *)(param_1 + 0x1cc) = 0;
    *(undefined4 *)(param_1 + 0x1f0) = 0;
    NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_STATION_TUNE_FAIL : %d\r\n","CRadio::OnCommand",param_2[1])
    ;
LAB_0002e35c:
    uVar10 = param_2[1];
LAB_0002e360:
    FUN_0002c160(param_1,uVar10);
    FUN_000292ec(param_1,0);
LAB_0002e22c:
    FUN_0002959c(param_1,1);
    break;
  case 0x43:
    if (*(int *)(param_1 + 0x4c) != 1) break;
    iVar6 = *(int *)(param_1 + 0x50);
    if ((iVar6 == 3) || (iVar6 == 2)) {
      FUN_0002c2c8(param_1,param_2[1]);
      break;
    }
    if (iVar6 != 6) {
      NKDbgPrintfW(L"%S : Sub-Mode(%d) is not SUBMODE_SEEK/SUBMODE_OFF_SEEK. Check it out.!!! m_nCurFreq %d\r\n"
                   ,"CRadio::OnCommand",iVar6,*(undefined4 *)(param_1 + 0x1c0));
      if (param_2[1] == *(uint *)(param_1 + 0x1c0)) break;
LAB_0002e460:
      FUN_00029ad4(param_1,1,0);
      break;
    }
    goto LAB_0002e424;
  case 0x44:
    FUN_0002c61c(param_1,param_2[1]);
    break;
  case 0x45:
    if ((*(int *)(param_1 + 0x1bc) != 0) || (*(int *)(param_1 + 0x4c) != 1)) break;
    *(uint *)(param_1 + 0x1c0) = ((byte)param_2[1] + 0x36b) * 100;
    FUN_00029198(param_1);
    FUN_000292ec(param_1,0);
    if (*(short *)(param_1 + 0x1cc) != 0) {
      iVar6 = 0;
      uVar10 = 0;
      do {
        iVar12 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar10;
        if (*(short *)((int)&DAT_000677b8 + iVar12) == *(short *)(param_1 + 0x1cc)) {
          piVar14 = (int *)((int)&DAT_000677bc + iVar12);
          if (*piVar14 != *(int *)(param_1 + 0x1c0)) {
            *piVar14 = *(int *)(param_1 + 0x1c0);
            FUN_000323f8(0,iVar6);
          }
        }
        uVar10 = uVar10 + 0x18;
        iVar6 = iVar6 + 1;
      } while (uVar10 < 0x360);
    }
    goto LAB_0002e22c;
  case 0x46:
    if (((((DAT_00067678 & 4) == 4) && (*(int *)(param_1 + 0x1bc) == 0)) &&
        (*(int *)(param_1 + 0x50) != 3)) && (*(int *)(param_1 + 0x50) != 4)) {
      if (*(int *)(param_1 + 0x1f0) == 1) {
        FUN_00029754(param_1,0);
        *(undefined4 *)(param_1 + 0x1f0) = 0;
      }
      *(uint *)(param_1 + 0x1c0) = (*(ushort *)((int)param_2 + 6) + 0x36b) * 100;
      NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_RGN_JUMP_COMPLETE : %04X, %d\r\n","CRadio::OnCommand",
                   (short)param_2[1]);
      FUN_0002b6f8(param_1,(uint)(ushort)param_2[1]);
    }
    break;
  case 0x47:
    if (*(int *)(param_1 + 0x4c) == 2) {
      FUN_0002d020(param_1,param_2[1]);
    }
    break;
  case 0x48:
    if ((*(int *)(param_1 + 0x4c) != 1) || (*(int *)(param_1 + 0x50) != 3)) break;
    *(uint *)(param_1 + 0x1c0) = param_2[1];
    goto LAB_0002e154;
  case 0x49:
    *(char *)(*(int *)(param_1 + 0x44) + 0xae8) = (char)param_2[1];
    FUN_00036de8(0x68,(uint)(byte)param_2[1]);
    hWnd = *(HWND *)(param_1 + 0x5c);
    if (hWnd == (HWND)0x0) break;
    bVar1 = (byte)param_2[1];
    wParam = 3;
    goto LAB_0002e118;
  case 0x4a:
    if ((DAT_00067678 & 4) != 4) break;
    if (((*(int *)(param_1 + 0x1bc) != 0) || (*(int *)(param_1 + 0x50) == 3)) ||
       (*(int *)(param_1 + 0x50) == 4)) {
      pwVar4 = L"%S : NOTI_APP_RAD_UPDATE_PI : Check it out.!!!\r\n";
      goto LAB_0002e640;
    }
    FUN_0002b6f8(param_1,(uint)(ushort)param_2[1]);
    FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                 (undefined4 *)(*(int *)(param_1 + 0x44) + 0xa97));
    iVar6 = 0x6a;
    goto LAB_0002f910;
  case 0x4b:
    if ((DAT_00067678 & 4) == 4) {
      FUN_0002928c(param_1);
      FUN_0002b6f8(param_1,(uint)(ushort)param_2[1]);
      FUN_00029754(param_1,0);
    }
    break;
  case 0x4c:
    NKDbgPrintfW(L"%S : NOTI_APP_UPDATE_CUR_FREQ_OF_PI : 0x%04X, %d\r\n","CRadio::OnCommand",
                 (short)param_2[1],(*(ushort *)((int)param_2 + 6) + 0x36b) * 100);
    if (*(int *)(param_1 + 0x4c) == 1) {
      FUN_000319b4(DAT_00067670,(uint)(ushort)param_2[1],
                   (*(ushort *)((int)param_2 + 6) + 0x36b) * 100);
    }
    break;
  case 0x4d:
    *(char *)(*(int *)(param_1 + 0x44) + 0xa92) = (char)param_2[1];
    goto LAB_0002f90c;
  case 0x4e:
    uVar10 = param_2[1];
    NKDbgPrintfW(L"%S : NOTI_APP_TA : %d\r\n","CRadio::OnCommand",(char)uVar10);
    if ((char)uVar10 == '\0') {
      FUN_00028f88(param_1);
      break;
    }
    if (*(int *)(param_1 + 0x204) == 1) {
      *(undefined4 *)(param_1 + 0x204) = 0;
      break;
    }
    *(undefined4 *)(param_1 + 0x1f8) = 1;
    if ((((DAT_00067678 & 0x10) != 0x10) ||
        ((*(int *)(param_1 + 0x4c) != 1 && (*(int *)(param_1 + 0x4c) != 2)))) ||
       ((*(int *)(param_1 + 0x50) != 0 &&
        ((*(int *)(param_1 + 0x50) != 5 || (*(int *)(param_1 + 0x1dc) == 2)))))) {
      if ((*(int *)(param_1 + 0x50) == 5) && (*(int *)(param_1 + 0x1dc) == 2)) {
        FUN_00028c70(param_1,2);
        FUN_00028be0(param_1,6,500);
      }
      else {
        iVar6 = FUN_00011e88(DAT_00064828);
        if ((((iVar6 == 8) || (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 10)) ||
            (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 7)) ||
           (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 0xc)) {
          *(undefined4 *)(param_1 + 0x208) = 1;
        }
      }
      break;
    }
    *(undefined4 *)(param_1 + 0x1dc) = 1;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                 (undefined4 *)(*(int *)(param_1 + 0x44) + 0xa97));
    NKDbgPrintfW(L"%S : NOTI_APP_TA : Send IDM_MMCM_AMAIN_TA_PTY31_START\r\n","CRadio::OnCommand");
    FUN_00036de8(0x6d,*(LPARAM *)(param_1 + 0x1dc));
    iVar6 = FUN_00011e88(DAT_00064828);
    if (((iVar6 != 8) && (iVar6 = FUN_00011e88(DAT_00064828), iVar6 != 10)) &&
       (iVar6 = FUN_00011e88(DAT_00064828), iVar6 != 7)) {
      iVar6 = FUN_00011e88(DAT_00064828);
      goto joined_r0x0002f4f4;
    }
LAB_0002f4fc:
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae9) = 1;
    break;
  case 0x4f:
    if ((DAT_00067678 & 0x10) != 0x10) {
      pwVar4 = L"\r\n%S : NOTI_APP_TA_START, But TA inactivated...... \r\n";
LAB_0002e640:
      NKDbgPrintfW(pwVar4,"CRadio::OnCommand");
      break;
    }
    iVar6 = *(int *)(param_1 + 0x4c);
    if (((iVar6 == 1) || (iVar6 == 2)) && (*(int *)(param_1 + 0x50) == 0)) {
      *(undefined4 *)(param_1 + 0x1f8) = 1;
      *(undefined4 *)(param_1 + 0x1dc) = 1;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      NKDbgPrintfW(L"%S : NOTI_APP_TA_START : Send IDM_MMCM_AMAIN_TA_PTY31_START\r\n",
                   "CRadio::OnCommand");
      FUN_00036de8(0x6d,*(LPARAM *)(param_1 + 0x1dc));
      iVar6 = FUN_00011e88(DAT_00064828);
      if (((iVar6 != 8) && (iVar6 = FUN_00011e88(DAT_00064828), iVar6 != 10)) &&
         (iVar6 = FUN_00011e88(DAT_00064828), iVar6 != 7)) {
        iVar6 = FUN_00011e88(DAT_00064828);
joined_r0x0002f4f4:
        if (iVar6 != 0xc) break;
      }
      goto LAB_0002f4fc;
    }
    uVar10 = *(uint *)(param_1 + 0x50);
    pwVar4 = L"\r\n%S : NOTI_APP_TA_START, TA Activated...... m_nMainMode : %d, m_nSubMode : %d\r\n"
    ;
LAB_0002e34c:
    NKDbgPrintfW(pwVar4,"CRadio::OnCommand",iVar6,uVar10);
    break;
  case 0x50:
    uVar2 = (ushort)param_2[1];
    if (uVar2 == 0) {
      *(undefined4 *)(param_1 + 0x1fc) = 0;
      iVar6 = 0x6e;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      goto LAB_0002f910;
    }
    if (*(short *)(param_1 + 0x1e4) != 0) break;
    *(ushort *)(param_1 + 0x1e4) = uVar2;
    if (((((DAT_00067678 & 0x10) != 0x10) || (*(int *)(param_1 + 0x50) != 0)) ||
        (*(int *)(param_1 + 0x4c) != 1)) ||
       (uVar10 = FUN_00030f70(DAT_00067670,(uint)uVar2), (int)uVar10 < 0)) {
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      break;
    }
    cVar8 = *(char *)(param_1 + 0x1ee) + '\x01';
    *(char *)(param_1 + 0x1ee) = cVar8;
    if (cVar8 == '\x01') {
      *(undefined4 *)(param_1 + 0x1e8) = *(undefined4 *)(*(int *)(param_1 + 0x44) + 8);
      *(undefined2 *)(param_1 + 0x1ec) = *(undefined2 *)(param_1 + 0x1cc);
    }
    *(undefined4 *)(param_1 + 0x1fc) = 1;
    *(undefined4 *)(param_1 + 0x1dc) = 2;
    FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1e4),
                 (undefined4 *)(*(int *)(param_1 + 0x44) + 0xa97));
    NKDbgPrintfW(L"%S : NOTI_APP_TA : Send IDM_MMCM_AMAIN_TA_PTY31_START\r\n","CRadio::OnCommand");
    LVar5 = *(LPARAM *)(param_1 + 0x1dc);
    iVar6 = 0x6d;
    goto LAB_0002f914;
  case 0x51:
    if (*(int *)(param_1 + 0x28c) != 0) break;
    puVar20 = param_2 + 1;
    pcVar19 = (char *)((int)param_2 + 6);
    NKDbgPrintfW(L"%S : Curpreset [%d] Update PSN(%d,%c%c%c%c%c%c%c%c).\r\n","CRadio::OnCommand",
                 *(undefined4 *)(param_1 + 0x1d4),(ushort)*puVar20,*pcVar19,
                 *(undefined1 *)((int)param_2 + 7),(char)param_2[2],
                 *(undefined1 *)((int)param_2 + 9),*(undefined1 *)((int)param_2 + 10),
                 *(undefined1 *)((int)param_2 + 0xb),(char)param_2[3],
                 *(undefined1 *)((int)param_2 + 0xd));
    if ((ushort)*puVar20 == 0) {
      NKDbgPrintfW(L"%S :PI = 0x0000(%d).\r\n","CRadio::OnCommand",0);
      uVar21 = *(undefined4 *)pcVar19;
      uVar22 = *(undefined4 *)((int)param_2 + 10);
      iVar6 = 0;
      uVar10 = 0;
      do {
        if ((*(int *)((int)&DAT_0006769c + uVar10) == *(int *)(param_1 + 0x1c0)) &&
           (((((*pcVar19 != '\0' || (*(char *)((int)param_2 + 7) != '\0')) ||
              ((char)param_2[2] != '\0')) ||
             ((*(char *)((int)param_2 + 9) != '\0' || (*(char *)((int)param_2 + 10) != '\0')))) ||
            ((*(char *)((int)param_2 + 0xb) != '\0' ||
             (((char)param_2[3] != '\0' || (*(char *)((int)param_2 + 0xd) != '\0')))))))) {
          *(undefined4 *)((int)&DAT_000676a0 + uVar10) = uVar21;
          *(undefined4 *)((int)&DAT_000676a4 + uVar10) = uVar22;
          (&DAT_000676a8)[uVar10] = 0;
          FUN_0003220c(0,iVar6);
        }
        uVar10 = uVar10 + 0x18;
        iVar6 = iVar6 + 1;
      } while (uVar10 < 0x120);
      uVar10 = 0;
      do {
        if ((*(int *)((int)&DAT_000677bc + uVar10) == *(int *)(param_1 + 0x1c0)) &&
           ((((*pcVar19 != '\0' || (*(char *)((int)param_2 + 7) != '\0')) ||
             ((char)param_2[2] != '\0')) ||
            (((*(char *)((int)param_2 + 9) != '\0' || (*(char *)((int)param_2 + 10) != '\0')) ||
             ((*(char *)((int)param_2 + 0xb) != '\0' ||
              (((char)param_2[3] != '\0' || (*(char *)((int)param_2 + 0xd) != '\0')))))))))) {
          *(undefined4 *)((int)&DAT_000677c0 + uVar10) = uVar21;
          *(undefined4 *)((int)&DAT_000677c4 + uVar10) = uVar22;
          (&DAT_000677c8)[uVar10] = 0;
        }
        uVar10 = uVar10 + 0x18;
      } while (uVar10 < 0x360);
      iVar6 = *(int *)(param_1 + 0x44);
      *(undefined4 *)(iVar6 + 0xa97) = *(undefined4 *)pcVar19;
      *(undefined4 *)(iVar6 + 0xa9b) = *(undefined4 *)((int)param_2 + 10);
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa9f) = 0;
    }
    else {
      iVar6 = FUN_00031048(DAT_00067670,(uint)(ushort)*puVar20,(undefined4 *)pcVar19);
      if (iVar6 == 1) {
        iVar6 = 0;
        uVar10 = 0;
        do {
          if ((*(int *)((int)&DAT_0006769c + uVar10) != 0) &&
             ((uint)*(ushort *)((int)&DAT_00067698 + uVar10) == (uint)(ushort)*puVar20)) {
            FUN_00030e3c(DAT_00067670,(uint)(ushort)*puVar20,
                         (undefined4 *)((int)&DAT_000676a0 + uVar10));
            FUN_0003220c(0,iVar6);
          }
          uVar10 = uVar10 + 0x18;
          iVar6 = iVar6 + 1;
        } while (uVar10 < 0x120);
        uVar10 = 0;
        do {
          if ((*(int *)((int)&DAT_000677bc + uVar10) != 0) &&
             ((uint)*(ushort *)((int)&DAT_000677b8 + uVar10) == (uint)(ushort)*puVar20)) {
            FUN_00030e3c(DAT_00067670,(uint)(ushort)*puVar20,
                         (undefined4 *)((int)&DAT_000677c0 + uVar10));
          }
          uVar10 = uVar10 + 0x18;
        } while (uVar10 < 0x360);
      }
    }
    FUN_0002a268(param_1,DAT_00067678 >> 2 & 1,0);
    uVar10 = 0;
    do {
      FUN_000323f8(*(int *)(param_1 + 0x1bc),uVar10);
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x24);
    FUN_0002959c(param_1,1);
    goto LAB_0002eb6c;
  case 0x52:
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa91) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa92) = 0;
LAB_0002f90c:
    iVar6 = 0x6f;
LAB_0002f910:
    LVar5 = 0;
LAB_0002f914:
    FUN_00036de8(iVar6,LVar5);
    break;
  case 0x53:
    *(uint *)(param_1 + 0x200) = (uint)(byte)param_2[1];
    if (((*(char *)(*(int *)(param_1 + 0x44) + 0xa95) != (char)param_2[1]) &&
        ((DAT_00067678 & 4) == 4)) &&
       ((*(int *)(param_1 + 0x4c) == 1 || (*(int *)(param_1 + 0x28c) == 0)))) {
      *(char *)(*(int *)(param_1 + 0x44) + 0xa95) = (char)param_2[1];
LAB_0002f0ac:
      FUN_00036de8(0x6b,0);
    }
    goto LAB_0002f0b8;
  case 0x54:
    if (*(int *)(param_1 + 0x1dc) != 2) {
      if ((char)param_2[1] == '\x01') {
        if (*(int *)(param_1 + 0x208) != 1) {
          if (((((DAT_00067678 & 0x40) == 0x40) &&
               ((*(int *)(param_1 + 0x4c) == 1 || (*(int *)(param_1 + 0x4c) == 2)))) &&
              ((*(int *)(param_1 + 0x50) == 0 || (*(int *)(param_1 + 0x50) == 5)))) &&
             (iVar6 = *(int *)(param_1 + 0x48), iVar6 != 4)) {
            if (iVar6 == 5) {
              FUN_00028c70(param_1,5);
            }
            else if ((iVar6 != 6) && (iVar6 != 0)) {
              NKDbgPrintfW(L"%S : Other Timer is already started. Check it out.!!!!!!!!(OLD:%d)\r\n"
                           ,"CRadio::OnCommand");
            }
            *(undefined4 *)(param_1 + 0x1e0) = 2;
            if (*(int *)(param_1 + 0x1dc) == 0) {
              iVar6 = *(int *)(param_1 + 0x44);
              goto LAB_0002f188;
            }
          }
          else {
            iVar6 = FUN_00011e88(DAT_00064828);
            if ((((iVar6 == 8) || (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 10)) ||
                (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 7)) ||
               (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 0xc)) {
LAB_0002f05c:
              *(undefined4 *)(param_1 + 0x208) = 1;
            }
            else if (*(int *)(param_1 + 0x1e0) == 1) {
              *(undefined4 *)(param_1 + 0x1e0) = 0;
              if (*(int *)(param_1 + 0x1dc) != 0) {
                FUN_00028be0(param_1,6,1000);
                LVar5 = *(int *)(param_1 + 0x1dc);
                goto LAB_0002f220;
              }
              LVar5 = 0;
              iVar6 = 0x6e;
              goto LAB_0002f224;
            }
          }
          goto LAB_0002f060;
        }
      }
      else {
        if ((char)param_2[1] == '\x1f') {
          if (*(int *)(param_1 + 0x208) == 1) goto LAB_0002f0dc;
          if ((((DAT_00067678 & 4) == 0) ||
              ((*(int *)(param_1 + 0x50) != 0 && (*(int *)(param_1 + 0x50) != 5)))) ||
             (iVar6 = *(int *)(param_1 + 0x48), iVar6 == 4)) {
            iVar6 = FUN_00011e88(DAT_00064828);
            if ((((iVar6 == 8) || (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 10)) ||
                (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 7)) ||
               (iVar6 = FUN_00011e88(DAT_00064828), iVar6 == 0xc)) goto LAB_0002f05c;
          }
          else {
            if (iVar6 == 5) {
              FUN_00028c70(param_1,5);
            }
            else if ((iVar6 != 6) && (iVar6 != 0)) {
              NKDbgPrintfW(L"%S : Other Timer is already started. Check it out.!!!!!!!!(OLD:%d)\r\n"
                           ,"CRadio::OnCommand");
            }
            iVar6 = *(int *)(param_1 + 0x44);
            *(undefined4 *)(param_1 + 0x1e0) = 1;
LAB_0002f188:
            FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                         (undefined4 *)(iVar6 + 0xa97));
            LVar5 = *(int *)(param_1 + 0x1e0) + 2;
LAB_0002f220:
            iVar6 = 0x6d;
LAB_0002f224:
            FUN_00036de8(iVar6,LVar5);
          }
          goto LAB_0002f060;
        }
        if ((*(int *)(param_1 + 0x50) == 5) && (*(int *)(param_1 + 0x1e0) != 0)) {
          if (*(int *)(param_1 + 0x1dc) == 0) goto LAB_0002ef5c;
          *(undefined4 *)(param_1 + 0x1e0) = 0;
          FUN_00028be0(param_1,6,1000);
          LVar5 = *(LPARAM *)(param_1 + 0x1dc);
          iVar6 = 0x6d;
        }
        else {
          if (*(int *)(param_1 + 0x1e0) == 0) goto LAB_0002f0dc;
          *(undefined4 *)(param_1 + 0x1e0) = 0;
LAB_0002ef5c:
          iVar6 = 0x6e;
          LVar5 = 0;
        }
        FUN_00036de8(iVar6,LVar5);
      }
LAB_0002f0dc:
      *(undefined4 *)(param_1 + 0x208) = 0;
    }
LAB_0002f060:
    *(uint *)(param_1 + 0x200) = (uint)(byte)param_2[1];
    if (((*(char *)(*(int *)(param_1 + 0x44) + 0xa95) != (char)param_2[1]) &&
        ((DAT_00067678 & 4) == 4)) &&
       ((*(int *)(param_1 + 0x4c) == 1 || (*(int *)(param_1 + 0x28c) == 0)))) {
      *(char *)(*(int *)(param_1 + 0x44) + 0xa95) = (char)param_2[1];
      goto LAB_0002f0ac;
    }
LAB_0002f0b8:
    hWnd = *(HWND *)(param_1 + 0x5c);
    if (hWnd == (HWND)0x0) break;
    uVar10 = *(uint *)(param_1 + 0x200);
    wParam = 6;
    goto LAB_0002e11c;
  case 0x55:
    uVar10 = (uint)*(byte *)((int)param_2 + 0xb);
    uVar17 = (uint)*(byte *)((int)param_2 + 10);
    uVar9 = (uint)*(byte *)((int)param_2 + 9);
    uVar11 = (uint)(byte)param_2[2];
    uVar13 = (uint)*(byte *)((int)param_2 + 7);
    uVar15 = (uint)*(byte *)((int)param_2 + 6);
    uVar16 = (uint)*(byte *)((int)param_2 + 5);
    NKDbgPrintfW(L"%S :CurPreset[%d] PSN(%c%c%c%c%c%c%c%c).\r\n","CRadio::OnCommand",
                 *(undefined4 *)(param_1 + 0x1d4),(char)param_2[1],uVar16,uVar15,uVar13,uVar11,uVar9
                 ,uVar17,uVar10);
    if (((*(int *)(param_1 + 0x28c) != 0) || ((DAT_00067678 & 4) != 4)) ||
       ((*(int *)(param_1 + 0x50) != 0 && (*(int *)(param_1 + 0x50) != 5)))) break;
    iVar6 = *(int *)(param_1 + 0x44);
    *(uint *)(iVar6 + 0xa97) = param_2[1];
    *(uint *)(iVar6 + 0xa9b) = param_2[2];
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa9f) = 0;
    if (*(ushort *)(param_1 + 0x1cc) == 0) {
      NKDbgPrintfW(L"%S :PI = 0x0000(%d).\r\n","CRadio::OnCommand",0);
      iVar6 = 0;
      uVar10 = 0;
      do {
        if ((*(int *)((int)&DAT_0006769c + uVar10) == *(int *)(param_1 + 0x1c0)) &&
           (((((char)param_2[1] != '\0' || (*(char *)((int)param_2 + 5) != '\0')) ||
             (*(char *)((int)param_2 + 6) != '\0')) ||
            (((*(char *)((int)param_2 + 7) != '\0' || ((char)param_2[2] != '\0')) ||
             ((*(char *)((int)param_2 + 9) != '\0' ||
              ((*(char *)((int)param_2 + 10) != '\0' || (*(char *)((int)param_2 + 0xb) != '\0'))))))
            )))) {
          iVar12 = *(int *)(param_1 + 0x44);
          *(undefined4 *)((int)&DAT_000676a0 + uVar10) = *(undefined4 *)(iVar12 + 0xa97);
          *(undefined4 *)((int)&DAT_000676a4 + uVar10) = *(undefined4 *)(iVar12 + 0xa9b);
          (&DAT_000676a8)[uVar10] = *(undefined1 *)(iVar12 + 0xa9f);
          FUN_0003220c(0,iVar6);
        }
        uVar10 = uVar10 + 0x18;
        iVar6 = iVar6 + 1;
      } while (uVar10 < 0x120);
      iVar6 = 0;
      uVar10 = 0;
      do {
        if ((*(int *)((int)&DAT_000677bc + uVar10) == *(int *)(param_1 + 0x1c0)) &&
           (((((((char)param_2[1] != '\0' || (*(char *)((int)param_2 + 5) != '\0')) ||
               (*(char *)((int)param_2 + 6) != '\0')) ||
              ((*(char *)((int)param_2 + 7) != '\0' || ((char)param_2[2] != '\0')))) ||
             (*(char *)((int)param_2 + 9) != '\0')) ||
            ((*(char *)((int)param_2 + 10) != '\0' || (*(char *)((int)param_2 + 0xb) != '\0')))))) {
          iVar12 = *(int *)(param_1 + 0x44);
          *(undefined4 *)((int)&DAT_000677c0 + uVar10) = *(undefined4 *)(iVar12 + 0xa97);
          *(undefined4 *)((int)&DAT_000677c4 + uVar10) = *(undefined4 *)(iVar12 + 0xa9b);
          (&DAT_000677c8)[uVar10] = *(undefined1 *)(iVar12 + 0xa9f);
          FUN_000323f8(0,iVar6);
        }
        uVar10 = uVar10 + 0x18;
        iVar6 = iVar6 + 1;
      } while (uVar10 < 0x360);
    }
    else {
      iVar6 = FUN_00031048(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                           (undefined4 *)(*(int *)(param_1 + 0x44) + 0xa97));
      uVar18 = 0;
      if (iVar6 == 1) {
        uVar10 = 0;
        do {
          if ((*(int *)((int)&DAT_0006769c + uVar10) != 0) &&
             ((uint)*(ushort *)((int)&DAT_00067698 + uVar10) == (uint)*(ushort *)(param_1 + 0x1cc)))
          {
            FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                         (undefined4 *)((int)&DAT_000676a0 + uVar10));
            FUN_0003220c(0,uVar18);
          }
          uVar10 = uVar10 + 0x18;
          uVar18 = uVar18 + 1;
        } while (uVar10 < 0x120);
        iVar6 = 0;
        uVar10 = 0;
        do {
          if ((*(int *)((int)&DAT_000677bc + uVar10) != 0) &&
             ((uint)*(ushort *)((int)&DAT_000677b8 + uVar10) == (uint)*(ushort *)(param_1 + 0x1cc)))
          {
            FUN_00030e3c(DAT_00067670,(uint)*(ushort *)(param_1 + 0x1cc),
                         (undefined4 *)((int)&DAT_000677c0 + uVar10));
            FUN_000323f8(0,iVar6);
          }
          uVar10 = uVar10 + 0x18;
          iVar6 = iVar6 + 1;
        } while (uVar10 < 0x360);
      }
      else {
        iVar6 = 0;
        do {
          if ((*(int *)((int)&DAT_000677bc + uVar18) != 0) &&
             (*(short *)((int)&DAT_000677b8 + uVar18) == *(short *)(param_1 + 0x1cc))) {
            iVar7 = *(int *)(param_1 + 0x44);
            _Buf2 = (undefined4 *)(iVar7 + 0xa97);
            iVar12 = memcmp((undefined4 *)((int)&DAT_000677c0 + uVar18),_Buf2,8);
            if (iVar12 != 0) {
              *(undefined4 *)((int)&DAT_000677c0 + uVar18) = *_Buf2;
              *(undefined4 *)((int)&DAT_000677c4 + uVar18) = *(undefined4 *)(iVar7 + 0xa9b);
              (&DAT_000677c8)[uVar18] = 0;
            }
            FUN_000323f8(0,iVar6);
          }
          uVar18 = uVar18 + 0x18;
          iVar6 = iVar6 + 1;
        } while (uVar18 < 0x360);
        bVar3 = false;
        uVar18 = 0;
        do {
          if (((*(int *)((int)&DAT_0006769c + uVar18) != 0) &&
              (*(short *)((int)&DAT_00067698 + uVar18) == *(short *)(param_1 + 0x1cc))) &&
             (*(int *)((int)&DAT_0006769c + uVar18) == *(int *)(param_1 + 0x1c0))) {
            bVar3 = true;
          }
          uVar18 = uVar18 + 0x18;
        } while (uVar18 < 0x120);
        if (bVar3) {
          NKDbgPrintfW(L"Refresh preset <==> %S :PI = 0x%04X, FREQ = %d.\r\n","CRadio::OnCommand",
                       *(undefined2 *)(param_1 + 0x1cc),*(undefined4 *)(param_1 + 0x1c0),uVar16,
                       uVar15,uVar13,uVar11,uVar9,uVar17,uVar10);
          FUN_000292ec(param_1,1);
        }
      }
    }
LAB_0002eb6c:
    FUN_00036de8(0x6a,0);
    iVar6 = 0x67;
    goto LAB_0002f910;
  case 0x56:
    if ((((DAT_00067678 & 4) != 4) || (*(int *)(param_1 + 0x28c) != 0)) ||
       ((*(int *)(param_1 + 0x50) != 0 || (uVar10 = (uint)(byte)param_2[1], 1 < uVar10)))) break;
    pcVar19 = (char *)(uVar10 * 0x40 + param_1 + 0x20c);
    if ((*pcVar19 == '\0') &&
       (uVar10 = FUN_000153dc(DAT_000648e4,4,uVar10 + 0x15,pcVar19,0x40,200), uVar10 == 0)) {
      NKDbgPrintfW(L"MGRMCM Read Error \r\n");
    }
    goto LAB_0002f350;
  case 0x57:
    if (((((DAT_00067678 & 4) != 4) || (*(int *)(param_1 + 0x28c) != 0)) ||
        (*(int *)(param_1 + 0x50) != 0)) || (uVar10 = (uint)(byte)param_2[1], 1 < uVar10)) break;
    pcVar19 = (char *)(uVar10 * 0x40 + param_1 + 0x20c);
    uVar17 = FUN_000153dc(DAT_000648e4,4,uVar10 + 0x15,pcVar19,0x40,200);
    if (uVar17 == 0) {
      NKDbgPrintfW(L"MGRMCM Read Error \r\n");
    }
    if (uVar10 == 0) {
      *(undefined1 *)(param_1 + 0x24c) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x20c) = 0;
    }
LAB_0002f350:
    memcpy((void *)(*(int *)(param_1 + 0x44) + 0xaa3),pcVar19,0x40);
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae3) = 0;
    if (*(char *)(*(int *)(param_1 + 0x44) + 0xaa3) != '\0') {
      FUN_0002a108(param_1);
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae3) = 0;
    }
    iVar6 = 0x6c;
    goto LAB_0002f910;
  case 0x58:
    *(char *)(*(int *)(param_1 + 0x44) + 0xa91) = (char)param_2[1];
    FUN_00036de8(0x6f,0);
    if ((char)param_2[1] != '\0') break;
    if ((*(int *)(param_1 + 0x4c) == 2) && (*(int *)(param_1 + 0x290) == 1)) {
      FUN_0002b128(param_1);
      break;
    }
    if (*(int *)(param_1 + 0x4c) != 1) break;
    FUN_0002928c(param_1);
    *(undefined2 *)(param_1 + 0x1cc) = 0;
    FUN_00029ad4(param_1,0,0);
LAB_0002e154:
    FUN_00029198(param_1);
    break;
  case 0x59:
    if ((DAT_00067678 & 4) == 4) {
      *(undefined4 *)(param_1 + 0x1f0) = 0;
      *(undefined2 *)(param_1 + 0x1cc) = 0;
      FUN_000292ec(param_1,0);
      FUN_0002959c(param_1,1);
      FUN_00029198(param_1);
      FUN_0002928c(param_1);
    }
    break;
  case 0x5a:
    if (*(int *)(param_1 + 0x5c) == 0) break;
    _Size = (size_t)*(byte *)((int)param_2 + 3);
    if (8 < _Size) {
      _Size = 8;
    }
    memcpy((void *)(param_1 + 0x3a),param_2 + 1,_Size);
    wParam = 0xb;
LAB_0002f8a4:
    hWnd = *(HWND *)(param_1 + 0x5c);
    uVar10 = 0;
LAB_0002e11c:
    PostMessageW(hWnd,0x403,wParam,uVar10);
    break;
  case 0x5b:
    NKDbgPrintfW(L"========================================================================\r\n");
    NKDbgPrintfW(L"[Seek] Fail Freq %d\r\n",param_2[1]);
    NKDbgPrintfW(L"========================================================================\r\n");
    if (*(int *)(param_1 + 0x4c) != 1) break;
    iVar6 = *(int *)(param_1 + 0x50);
    if ((iVar6 == 3) || (iVar6 == 2)) {
      FUN_0002c21c(param_1,param_2[1]);
      break;
    }
    if (iVar6 != 6) {
      NKDbgPrintfW(L"%S : Sub-Mode(%d) is not SUBMODE_SEEK/SUBMODE_OFF_SEEK. Check it out. m_nCurFreq %d!!!\r\n"
                   ,"CRadio::OnCommand",iVar6,*(undefined4 *)(param_1 + 0x1c0));
      if (param_2[1] == *(uint *)(param_1 + 0x1c0)) break;
      *(uint *)(param_1 + 0x1c0) = param_2[1];
      goto LAB_0002e460;
    }
LAB_0002e424:
    FUN_0002d07c(param_1,param_2[1]);
  }
switchD_0002df3c_caseD_1:
  FUN_0004a3f4(local_2c);
  return;
}



/* 0002f954 FUN_0002f954 */

/* Boundary evidence: original MIPS .pdata 0002f954..0002fb1f. Semantic name remains unreviewed. */

void FUN_0002f954(int param_1)

{
  int iVar1;
  uint uVar2;
  
  NKDbgPrintfW(L"%S : Current main mode = %d, m_nSubMode = %d\r\n","CRadio::ChangeToOffMode",
               *(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x50));
  if (*(int *)(param_1 + 0x4c) != 1) {
    if (*(int *)(param_1 + 0x4c) != 2) {
      return;
    }
    if (*(int *)(param_1 + 0x1f0) == 1) {
      FUN_00029754(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0x50) != 8)) {
      return;
    }
    goto LAB_0002f9e0;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if ((iVar1 == 3) || (iVar1 == 2)) {
    uVar2 = *(uint *)(param_1 + 0x1c8);
    *(int *)(param_1 + 0x1c0) = *(int *)(param_1 + 0x1c4);
    if ((uVar2 < 0xc) &&
       ((&DAT_0006769c)[uVar2 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] == *(int *)(param_1 + 0x1c4))
       ) {
      *(uint *)(param_1 + 0x1d4) = uVar2;
    }
LAB_0002fab0:
    FUN_00029198(param_1);
  }
  else if (((iVar1 == 5) && (*(int *)(param_1 + 0x1dc) == 2)) && (*(int *)(param_1 + 0x1e8) != 0)) {
    *(int *)(param_1 + 0x1c0) = *(int *)(param_1 + 0x1e8);
    *(undefined2 *)(param_1 + 0x1cc) = *(undefined2 *)(param_1 + 0x1ec);
    goto LAB_0002fab0;
  }
  FUN_000298d4(param_1,0);
  if (*(int *)(param_1 + 0x1f0) == 1) {
    FUN_00029754(param_1,1);
  }
  iVar1 = *(int *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x290) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if ((iVar1 != 0) && (iVar1 != 3)) {
    if (iVar1 != 2) {
      if (iVar1 != 5) {
        return;
      }
      *(undefined1 *)(param_1 + 0x1ee) = 1;
      return;
    }
    FUN_00028c70(param_1,1);
  }
LAB_0002f9e0:
  FUN_0002bd68(param_1);
  return;
}



/* 0002fb20 FUN_0002fb20 */

/* Boundary evidence: original MIPS .pdata 0002fb20..0002fc2f. Semantic name remains unreviewed. */

void FUN_0002fb20(int param_1)

{
  int iVar1;
  
  NKDbgPrintfW(L"%S : Current main mode = %d, m_nSubMode = %d\r\n","CRadio::ChangeToFgMode",
               *(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x50));
  if (*(int *)(param_1 + 0x4c) == 0) {
    iVar1 = *(int *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 1;
    if (iVar1 != 0) {
      if (iVar1 == 4) goto LAB_0002fc04;
      if (iVar1 == 6) goto LAB_0002fc18;
      if (iVar1 == 7) goto LAB_0002fbb0;
joined_r0x0002fbf4:
      if (iVar1 != 8) {
        return;
      }
      goto LAB_0002fc18;
    }
LAB_0002fc0c:
    iVar1 = 4;
  }
  else {
    if (*(int *)(param_1 + 0x4c) != 2) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 1;
    if (iVar1 == 0) goto LAB_0002fc0c;
    if (iVar1 == 4) {
LAB_0002fc04:
      *(undefined4 *)(param_1 + 0x290) = 1;
      return;
    }
    if (iVar1 == 6) goto LAB_0002fc18;
    if (iVar1 != 7) goto joined_r0x0002fbf4;
LAB_0002fbb0:
    iVar1 = 3;
  }
  FUN_00028c70(param_1,iVar1);
LAB_0002fc18:
  FUN_0002bd68(param_1);
  return;
}



/* 0002fc30 FUN_0002fc30 */

/* Boundary evidence: original MIPS .pdata 0002fc30..0002fde3. Semantic name remains unreviewed. */

void FUN_0002fc30(int param_1)

{
  int iVar1;
  uint uVar2;
  
  NKDbgPrintfW(L"%S : Current main mode = %d, m_nSubMode = %d\r\n","CRadio::ChangeToBgMode",
               *(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x50));
  if (*(int *)(param_1 + 0x4c) == 0) {
    if (*(int *)(param_1 + 0x1f0) == 1) {
      FUN_00029754(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x294) = DAT_00067694;
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 2;
    if (*(int *)(param_1 + 0x50) != 0) {
      return;
    }
  }
  else {
    if (*(int *)(param_1 + 0x4c) != 1) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x50);
    if ((iVar1 == 3) || (iVar1 == 2)) {
      uVar2 = *(uint *)(param_1 + 0x1c8);
      *(int *)(param_1 + 0x1c0) = *(int *)(param_1 + 0x1c4);
      if ((uVar2 < 0xc) &&
         ((&DAT_0006769c)[uVar2 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] ==
          *(int *)(param_1 + 0x1c4))) {
        *(uint *)(param_1 + 0x1d4) = uVar2;
      }
      FUN_00029198(param_1);
    }
    else if (iVar1 == 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa97) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xa95) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xaa3) = 0;
    }
    FUN_000298d4(param_1,0);
    if (*(int *)(param_1 + 0x1f0) == 1) {
      FUN_00029754(param_1,1);
    }
    iVar1 = *(int *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x294) = DAT_00067694;
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 2;
    if ((iVar1 != 0) && (iVar1 != 3)) {
      if (iVar1 != 2) {
        return;
      }
      FUN_00028c70(param_1,1);
    }
  }
  FUN_0002bd68(param_1);
  return;
}



/* 0002fde4 FUN_0002fde4 */

/* Boundary evidence: original MIPS .pdata 0002fde4..0002fec7. Semantic name remains unreviewed. */

void FUN_0002fde4(int param_1,int param_2)

{
  wchar_t *pwVar1;
  
  if (param_2 == 1) {
    pwVar1 = L"ENABLE";
  }
  else {
    pwVar1 = L"DISABLE";
  }
  NKDbgPrintfW(L"%S(%s)\r\n","CRadio::SetSubModeTA",pwVar1);
  if (param_2 == 1) {
    if ((((*(int *)(param_1 + 0x1f8) == 1) || (*(int *)(param_1 + 0x200) == 1)) ||
        (*(int *)(param_1 + 0x200) == 0x1f)) || (*(int *)(param_1 + 0x1fc) == 1)) {
      FUN_0002af84(param_1);
    }
    else {
      FUN_00036de8(0x6e,0);
    }
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae9) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0xae9) = 0;
    FUN_00036de8(0x6e,0);
    FUN_0002ccdc(param_1);
  }
  return;
}



/* 0002fec8 FUN_0002fec8 */

/* Boundary evidence: original MIPS .pdata 0002fec8..0002ffa3. Semantic name remains unreviewed. */

void FUN_0002fec8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  NKDbgPrintfW(L"%S\r\n","CRadio::ModeChange");
  iVar1 = FUN_0001de14(DAT_00064a24);
  if (iVar1 == 0) goto switchD_0002ff2c_default;
  uVar2 = FUN_00011e88(DAT_00064828);
  switch(uVar2) {
  case 0:
    FUN_0002fb20(param_1);
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 7:
  case 8:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    if (((DAT_00067678 & 0x10) == 0x10) || ((DAT_00067678 & 0x40) != 0)) {
      FUN_0002fc30(param_1);
      return;
    }
  default:
switchD_0002ff2c_default:
    FUN_0002f954(param_1);
    break;
  case 6:
  case 9:
    break;
  }
  return;
}



/* 0002ffa4 FUN_0002ffa4 */

/* Boundary evidence: original MIPS .pdata 0002ffa4..0003000f. Semantic name remains unreviewed. */

void FUN_0002ffa4(int param_1)

{
  FUN_0002959c(param_1,1);
  if (*(int *)(param_1 + 0x4c) == 0) {
    FUN_0002fec8(param_1);
  }
  else if (*(int *)(param_1 + 0x4c) == 1) {
    FUN_0002b278();
    FUN_00029198(param_1);
  }
  return;
}



/* 00030010 FUN_00030010 */

undefined4 * FUN_00030010(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = &PTR_FUN_00059ec0;
  param_1[1] = param_2;
  param_1[2] = param_3;
  return param_1;
}



/* 0003002c FUN_0003002c */

bool FUN_0003002c(int param_1,int param_2)

{
  return *(int *)(param_1 + 8) == param_2;
}



/* 00030044 FUN_00030044 */

/* Boundary evidence: original MIPS .pdata 00030044..0003006b. Semantic name remains unreviewed. */

void FUN_00030044(int param_1,UINT param_2)

{
  SetTimer(*(HWND *)(param_1 + 4),*(UINT_PTR *)(param_1 + 8),param_2,(TIMERPROC)0x0);
  return;
}



/* 0003006c FUN_0003006c */

/* Boundary evidence: original MIPS .pdata 0003006c..0003008b. Semantic name remains unreviewed. */

void FUN_0003006c(int param_1)

{
  KillTimer(*(HWND *)(param_1 + 4),*(UINT_PTR *)(param_1 + 8));
  return;
}



/* 0003008c FUN_0003008c */

/* Boundary evidence: original MIPS .pdata 0003008c..000300b7. Semantic name remains unreviewed. */

void FUN_0003008c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00059ec0;
  KillTimer((HWND)param_1[1],param_1[2]);
  return;
}



/* 000300b8 FUN_000300b8 */

/* Boundary evidence: original MIPS .pdata 000300b8..00030113. Semantic name remains unreviewed. */

undefined4 * FUN_000300b8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00059ec0;
  KillTimer((HWND)param_1[1],param_1[2]);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00030114 FUN_00030114 */

/* Boundary evidence: original MIPS .pdata 00030114..0003015b. Semantic name remains unreviewed. */

undefined4 *
FUN_00030114(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00030010(param_1,param_2,param_3);
  param_1[3] = param_4;
  *param_1 = &PTR_FUN_00059ed0;
  return param_1;
}



/* 0003015c FUN_0003015c */

/* Boundary evidence: original MIPS .pdata 0003015c..00030397. Semantic name remains unreviewed. */

void FUN_0003015c(int param_1,uint *param_2)

{
  char cVar1;
  undefined1 uVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  uint uVar5;
  size_t _Size;
  byte local_18;
  byte local_17;
  byte local_16;
  
  if ((*param_2 & 0xf00) == 0x200) {
    cVar1 = *(char *)((int)param_2 + 2);
    if (cVar1 == 'k') {
      if (*(char *)((int)param_2 + 3) != '\0') {
        NKDbgPrintfW(L"NOTI_CAN_MMI_REARCAMINFO len %d, 0x%02X\r\n",*(char *)((int)param_2 + 3),
                     (char)param_2[1]);
        PostMessageW((HWND)0xffff,DAT_00067430,0,(uint)(byte)param_2[1]);
      }
    }
    else {
      if (cVar1 == 'l') {
        if (*(char *)((int)param_2 + 3) != '\x03') {
          return;
        }
        memcpy(&local_18,param_2 + 1,3);
        uVar5 = (uint)(local_16 >> 5) | (uint)local_17 << 3;
        if (0x5a0 < uVar5) {
          NKDbgPrintfW(L"[ERROR]ulLeftTimeBeforeRES(%d) -> Upper limit!!!! \r\n",uVar5);
        }
        if (*(int *)(param_1 + 0xc) == 0) {
          return;
        }
        *(char *)(*(int *)(param_1 + 0xc) + 0xb6c) = (char)((local_18 & 0x18) >> 3);
        *(uint *)(*(int *)(param_1 + 0xc) + 0xb68) = uVar5;
        uVar2 = *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb6c);
        uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb68);
        pwVar3 = L"\n[MgrMCM_RES]===NOTI_CAN_RES_STATUS programmed: %d, time value: %d\r\n";
      }
      else {
        if (cVar1 != 'm') {
          return;
        }
        if (*(char *)((int)param_2 + 3) == '\0') {
          return;
        }
        NKDbgPrintfW(L"NOTI_CAN_RES_ALL len %d, 0x%02X\r\n",*(char *)((int)param_2 + 3),
                     (char)param_2[1]);
        PostMessageW((HWND)0xffff,DAT_00067430,0,(uint)(byte)param_2[1]);
        local_18 = 0;
        memset(&local_17,0,2);
        _Size = *(byte *)((int)param_2 + 3) - 1;
        if (3 < *(byte *)((int)param_2 + 3) - 1) {
          _Size = 3;
          NKDbgPrintfW(L"[MgrMCM_RES]===RES data lengh Error!!!\r\n");
        }
        memcpy(&local_18,(void *)((int)param_2 + 5),_Size);
        if (*(int *)(param_1 + 0xc) == 0) {
          return;
        }
        *(char *)(*(int *)(param_1 + 0xc) + 0xb6c) = (char)((local_18 & 0x18) >> 3);
        *(uint *)(*(int *)(param_1 + 0xc) + 0xb68) = (uint)(local_16 >> 5) | (uint)local_17 << 3;
        uVar2 = *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xb6c);
        uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xb68);
        pwVar3 = L"\n[MgrMCM_RES]===NOTI_CAN_RES_ALL programmed: %d, time value: %d\r\n";
      }
      NKDbgPrintfW(pwVar3,uVar2,uVar4);
      FUN_00036de8(0xce,0);
    }
  }
  return;
}



/* 00030398 FUN_00030398 */

/* Boundary evidence: original MIPS .pdata 00030398..00030433. Semantic name remains unreviewed. */

void FUN_00030398(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_18;
  undefined1 local_17 [7];
  
  if (param_2 == 0xcc) {
    memset(local_17,0,1);
    local_18 = (undefined1)((uint)param_3 >> 8);
    local_17[0] = (undefined1)param_3;
    if (DAT_000648e4 != 0) {
      iVar1 = FUN_00015158(DAT_000648e4,1,1,0xd,(int)&local_18,2,0x96);
      if (iVar1 != 1) {
        NKDbgPrintfW(L"[MgrMCM_RES]=== SEND ERROR -> CMD_CAN_RES_TIMER ERROR===================");
      }
    }
  }
  return;
}



/* 00030434 FUN_00030434 */

/* Boundary evidence: original MIPS .pdata 00030434..0003048b. Semantic name remains unreviewed. */

undefined4 * FUN_00030434(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00059ed0;
  FUN_0003008c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00030498 FUN_00030498 */

/* Boundary evidence: original MIPS .pdata 00030498..00030503. Semantic name remains unreviewed. */

undefined * FUN_00030498(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)*param_1)();
  _snwprintf_s((wchar_t *)&DAT_00067444,0x103,0x103,L"%s%s\\",uVar1,(&PTR_DAT_0006396c)[param_2]);
  return &DAT_00067444;
}



/* 00030504 FUN_00030504 */

/* Boundary evidence: original MIPS .pdata 00030504..0003056b. Semantic name remains unreviewed. */

LPWSTR FUN_00030504(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_2 < *(int *)(param_1 + 0x630)) {
    puVar1 = (&PTR_u_etc_etc_volume_bg_bmp_000638b8)[param_2];
  }
  else {
    puVar1 = &DAT_000504cc;
  }
  wsprintfW((LPWSTR)(param_1 + 0x414),L"%s%s",param_1 + 0x20c,puVar1);
  return (LPWSTR)(param_1 + 0x414);
}



/* 0003056c FUN_0003056c */

void FUN_0003056c(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0005a200;
  return;
}



/* 0003057c FUN_0003057c */

/* Boundary evidence: original MIPS .pdata 0003057c..000305f7. Semantic name remains unreviewed. */

void FUN_0003057c(int param_1)

{
  HGDIOBJ ho;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x630)) {
    iVar1 = 0;
    do {
      ho = *(HGDIOBJ *)(*(int *)(param_1 + 0x62c) + iVar1);
      if (ho != (HGDIOBJ)0x0) {
        DeleteObject(ho);
        *(undefined4 *)(*(int *)(param_1 + 0x62c) + iVar1) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 0x630));
  }
  return;
}



/* 000305f8 FUN_000305f8 */

undefined4 FUN_000305f8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x628)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x620) + param_2 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 00030628 FUN_00030628 */

/* Boundary evidence: original MIPS .pdata 00030628..0003072b. Semantic name remains unreviewed. */

undefined4
FUN_00030628(int param_1,int param_2,LPCWSTR param_3,LONG param_4,undefined4 param_5,BYTE param_6,
            BYTE param_7)

{
  undefined4 uVar1;
  HFONT pHVar2;
  int iVar3;
  LOGFONTW local_78;
  uint local_1c;
  
  local_1c = DAT_00064820;
  if ((param_2 < *(int *)(param_1 + 0x628)) &&
     (iVar3 = param_2 * 4, *(int *)(*(int *)(param_1 + 0x620) + iVar3) == 0)) {
    memset(&local_78,0,0x5c);
    wsprintfW(local_78.lfFaceName,param_3);
    local_78.lfPitchAndFamily = '\x02';
    local_78.lfQuality = '\x06';
    local_78.lfCharSet = '\0';
    local_78.lfWeight = 0;
    local_78.lfOutPrecision = '\0';
    local_78.lfClipPrecision = '\0';
    local_78.lfItalic = param_6;
    local_78.lfUnderline = param_7;
    local_78.lfWidth = 0;
    local_78.lfHeight = param_4;
    pHVar2 = CreateFontIndirectW(&local_78);
    *(HFONT *)(*(int *)(param_1 + 0x620) + iVar3) = pHVar2;
    *(LONG *)(*(int *)(param_1 + 0x624) + iVar3) = param_4;
    FUN_0004a3f4(local_1c);
    uVar1 = 1;
  }
  else {
    FUN_0004a3f4(DAT_00064820);
    uVar1 = 0;
  }
  return uVar1;
}



/* 0003072c FUN_0003072c */

/* Boundary evidence: original MIPS .pdata 0003072c..0003077b. Semantic name remains unreviewed. */

int FUN_0003072c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = SHLoadDIBitmap(param_2);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"\r\n~~~~~~~~ (%s) file not found!!!!\r\n",param_2);
  }
  return iVar1;
}



/* 0003077c FUN_0003077c */

/* Boundary evidence: original MIPS .pdata 0003077c..00030837. Semantic name remains unreviewed. */

void FUN_0003077c(int param_1)

{
  HMODULE hModule;
  size_t sVar1;
  short *psVar2;
  wchar_t *lpFilename;
  
  lpFilename = (wchar_t *)(param_1 + 4);
  hModule = GetModuleHandleW((LPCWSTR)0x0);
  GetModuleFileNameW(hModule,lpFilename,0x104);
  sVar1 = wcslen(lpFilename);
  if (0 < (int)sVar1) {
    psVar2 = (short *)((sVar1 + 2) * 2 + param_1);
    do {
      if (*psVar2 == 0x5c) {
        *(undefined2 *)((sVar1 + 3) * 2 + param_1) = 0;
        wcsncpy_s((wchar_t *)(param_1 + 0x20c),0x103,lpFilename,0x103);
        return;
      }
      sVar1 = sVar1 - 1;
      psVar2 = psVar2 + -1;
    } while (0 < (int)sVar1);
  }
  *(undefined2 *)(param_1 + 0x20c) = 0x5c;
  *(undefined2 *)(param_1 + 0x20e) = 0;
  return;
}



/* 00030838 FUN_00030838 */

/* Boundary evidence: original MIPS .pdata 00030838..00030893. Semantic name remains unreviewed. */

void FUN_00030838(int param_1,short *param_2)

{
  undefined *puVar1;
  
  if (param_2 != (short *)0x0) {
    if (*param_2 == 0x5c) {
      puVar1 = &DAT_000504cc;
    }
    else {
      puVar1 = (undefined *)(param_1 + 4);
    }
    _snwprintf_s((wchar_t *)(param_1 + 0x20c),0x103,0x103,L"%s%s",puVar1,param_2);
  }
  return;
}



/* 00030894 FUN_00030894 */

/* Boundary evidence: original MIPS .pdata 00030894..00030933. Semantic name remains unreviewed. */

void FUN_00030894(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0005a25c;
  if (param_1[0x18b] != 0) {
    FUN_0003057c((int)param_1);
    __3_YAXPAX_Z(param_1[0x18b]);
    param_1[0x18b] = 0;
  }
  if (param_1[0x189] != 0) {
    __3_YAXPAX_Z();
    param_1[0x189] = 0;
  }
  if (param_1[0x188] != 0) {
    __3_YAXPAX_Z();
    param_1[0x188] = 0;
  }
  *param_1 = &PTR_LAB_0005a200;
  return;
}



/* 00030934 Unwind@00030934 */

/* Boundary evidence: original MIPS .pdata 00030934..00030963. Semantic name remains unreviewed. */

void Unwind_00030934(void)

{
  undefined4 *in_v0;
  
  FUN_0003056c((undefined4 *)*in_v0);
  return;
}



/* 00030964 FUN_00030964 */

/* Boundary evidence: original MIPS .pdata 00030964..000309af. Semantic name remains unreviewed. */

undefined4 * FUN_00030964(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0005a200;
  param_1[0x18b] = 0;
  param_1[0x188] = 0;
  param_1[0x189] = 0;
  param_1[0x18c] = 0;
  param_1[0x18a] = 0;
  FUN_0003077c((int)param_1);
  return param_1;
}



/* 000309b0 FUN_000309b0 */

/* Boundary evidence: original MIPS .pdata 000309b0..000309f3. Semantic name remains unreviewed. */

undefined4 * FUN_000309b0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_0005a200;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000309f4 FUN_000309f4 */

/* Boundary evidence: original MIPS .pdata 000309f4..00030a77. Semantic name remains unreviewed. */

void FUN_000309f4(int param_1,short *param_2)

{
  HGDIOBJ ho;
  int iVar1;
  int iVar2;
  
  FUN_00030838(param_1,param_2);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x630)) {
    iVar1 = 0;
    do {
      ho = *(HGDIOBJ *)(*(int *)(param_1 + 0x62c) + iVar1);
      if (ho != (HGDIOBJ)0x0) {
        DeleteObject(ho);
        *(undefined4 *)(*(int *)(param_1 + 0x62c) + iVar1) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 0x630));
  }
  return;
}



/* 00030a78 FUN_00030a78 */

/* Boundary evidence: original MIPS .pdata 00030a78..00030adb. Semantic name remains unreviewed. */

void FUN_00030a78(int *param_1,int param_2)

{
  short *psVar1;
  
  if ((param_1[0x187] != param_2) &&
     (psVar1 = (short *)(**(code **)(*param_1 + 4))(param_1,param_2), psVar1 != (short *)0x0)) {
    param_1[0x187] = param_2;
    FUN_000309f4((int)param_1,psVar1);
  }
  return;
}



/* 00030adc FUN_00030adc */

/* Boundary evidence: original MIPS .pdata 00030adc..00030bd7. Semantic name remains unreviewed. */

int FUN_00030adc(int *param_1,int param_2)

{
  wchar_t *_Str;
  size_t sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_2 < param_1[0x18c]) && (param_2 != -1)) {
    iVar4 = param_2 * 4;
    iVar3 = *(int *)(param_1[0x18b] + iVar4);
    if (iVar3 == 0) {
      _Str = (wchar_t *)(**(code **)(*param_1 + 0xc))(param_1);
      iVar3 = param_1[0x18b];
      if ((*(int *)(iVar3 + iVar4) == 0) && (_Str != (wchar_t *)0x0)) {
        sVar1 = wcslen(_Str);
        iVar2 = wcscmp(_Str + (sVar1 - 3),L"png");
        if (iVar2 == 0) {
          *(int *)(iVar3 + iVar4) = 0;
        }
        else {
          iVar3 = FUN_0003072c(param_1,_Str);
          *(int *)(param_1[0x18b] + iVar4) = iVar3;
        }
      }
      iVar3 = *(int *)(param_1[0x18b] + iVar4);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



/* 00030bd8 FUN_00030bd8 */

/* Boundary evidence: original MIPS .pdata 00030bd8..00030cef. Semantic name remains unreviewed. */

undefined4 * FUN_00030bd8(undefined4 *param_1)

{
  void *_Dst;
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  wchar_t local_220;
  undefined1 auStack_21e [518];
  uint local_18;
  
  local_18 = DAT_00064820;
  puVar3 = param_1;
  FUN_00030964(param_1);
  *param_1 = &PTR_LAB_0005a25c;
  local_220 = L'\0';
  memset(auStack_21e,0,0x206);
  param_1[0x187] = 0;
  _snwprintf_s(&local_220,0x103,0x103,L"%s%s\\",L"Img\\",PTR_DAT_0006396c,puVar3);
  FUN_00030838((int)param_1,&local_220);
  _Dst = (void *)__2_YAPAXI_Z(0xb4);
  param_1[0x18b] = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0xb4);
    param_1[0x18c] = 0x2d;
  }
  iVar1 = __2_YAPAXI_Z(0x28);
  param_1[0x188] = iVar1;
  if (iVar1 != 0) {
    uVar2 = __2_YAPAXI_Z(0x28);
    param_1[0x189] = uVar2;
    memset((void *)param_1[0x188],0,0x28);
    param_1[0x18a] = 10;
  }
  FUN_0004a3f4(local_18);
  return param_1;
}



/* 00030cf0 Unwind@00030cf0 */

/* Boundary evidence: original MIPS .pdata 00030cf0..00030d1f. Semantic name remains unreviewed. */

void Unwind_00030cf0(void)

{
  int in_v0;
  
  FUN_0003056c(*(undefined4 **)(in_v0 + -0x228));
  return;
}



/* 00030d20 FUN_00030d20 */

/* Boundary evidence: original MIPS .pdata 00030d20..00030d6b. Semantic name remains unreviewed. */

undefined4 * FUN_00030d20(undefined4 *param_1,uint param_2)

{
  FUN_00030894(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00030d6c FUN_00030d6c */

/* Boundary evidence: original MIPS .pdata 00030d6c..00030d8f. Semantic name remains unreviewed. */

void FUN_00030d6c(int param_1)

{
  memset(*(void **)(param_1 + 4),0,0x1600);
  return;
}



/* 00030d90 FUN_00030d90 */

/* Boundary evidence: original MIPS .pdata 00030d90..00030e3b. Semantic name remains unreviewed. */

void FUN_00030d90(int param_1,uint param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  
  uVar1 = 0;
  puVar2 = (undefined1 *)(param_1 + 8);
  do {
    if ((byte)puVar2[uVar1] == param_2) break;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x80);
  if (uVar1 == 0x80) {
    NKDbgPrintfW(L"%S : !!!!!!!!!!!!!!!!!!!!!!!!!!!!Serious problem......\r\n",
                 "CStationList::OrderRearrange");
    uVar1 = 0;
    do {
      puVar2[uVar1] = (char)uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x80);
  }
  else {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      puVar2[uVar1] = puVar2[uVar1 - 1];
    }
    *puVar2 = (char)param_2;
  }
  return;
}



/* 00030e3c FUN_00030e3c */

/* Boundary evidence: original MIPS .pdata 00030e3c..00030ebf. Semantic name remains unreviewed. */

void FUN_00030e3c(int param_1,uint param_2,undefined4 *param_3)

{
  ushort *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar1 = (ushort *)(*(int *)(param_1 + 4) + 8);
  do {
    if (param_2 == *puVar1) {
      puVar2 = (undefined4 *)(uVar3 * 0x2c + *(int *)(param_1 + 4));
      *param_3 = *puVar2;
      param_3[1] = puVar2[1];
      *(undefined1 *)(param_3 + 2) = 0;
      FUN_00030d90(param_1,uVar3);
      return;
    }
    uVar3 = uVar3 + 1;
    puVar1 = puVar1 + 0x16;
  } while (uVar3 < 0x80);
  return;
}



/* 00030ec0 FUN_00030ec0 */

int FUN_00030ec0(int param_1,uint param_2)

{
  ushort *puVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    uVar2 = 0;
    puVar1 = (ushort *)(*(int *)(param_1 + 4) + 8);
    do {
      if (param_2 == *puVar1) {
        return (*(byte *)(uVar2 * 0x2c + *(int *)(param_1 + 4) + 0xb) + 0x36b) * 100;
      }
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 0x16;
    } while (uVar2 < 0x80);
  }
  return 0;
}



/* 00030f2c FUN_00030f2c */

int FUN_00030f2c(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x88) < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(byte *)(*(int *)(param_1 + 0x88) * 0x2c + *(int *)(param_1 + 4) + 0xb) + 0x36b) * 100
    ;
  }
  return iVar1;
}



/* 00030f70 FUN_00030f70 */

uint FUN_00030f70(int param_1,uint param_2)

{
  uint uVar1;
  ushort *puVar2;
  
  uVar1 = 0;
  puVar2 = (ushort *)(*(int *)(param_1 + 4) + 8);
  do {
    if (param_2 == *puVar2) {
      return uVar1;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 0x16;
  } while (uVar1 < 0x80);
  return 0xffffffff;
}



/* 00030fa8 FUN_00030fa8 */

/* Boundary evidence: original MIPS .pdata 00030fa8..00031013. Semantic name remains unreviewed. */

undefined4 FUN_00030fa8(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = 0;
    puVar3 = (ushort *)(*(int *)(param_1 + 4) + 8);
    do {
      if (param_2 == *puVar3) goto LAB_00030ff4;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 0x16;
    } while (uVar2 < 0x80);
    uVar2 = 0xffffffff;
LAB_00030ff4:
    *(uint *)(param_1 + 0x88) = uVar2;
    FUN_00030d90(param_1,uVar2);
    uVar1 = *(undefined4 *)(param_1 + 0x88);
  }
  return uVar1;
}



/* 00031014 FUN_00031014 */

int FUN_00031014(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x88) < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x88) * 0x2c + *(int *)(param_1 + 4) + 8;
  }
  return iVar1;
}



/* 00031048 FUN_00031048 */

/* Boundary evidence: original MIPS .pdata 00031048..000311eb. Semantic name remains unreviewed. */

undefined4 FUN_00031048(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  undefined4 *_Buf1;
  uint uVar6;
  int iVar7;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  
  local_20 = DAT_00064820;
  iVar7 = *(int *)(param_1 + 4);
  uVar5 = 0;
  puVar4 = (ushort *)(iVar7 + 8);
  do {
    if (param_2 == *puVar4) goto LAB_000310a4;
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 0x16;
  } while (uVar5 < 0x80);
  uVar5 = 0xffffffff;
LAB_000310a4:
  if (-1 < (int)uVar5) {
    uVar6 = 0;
    memset(&local_28,0,8);
    uVar3 = 0;
    do {
      if (*(char *)(uVar3 + (int)param_3) != ' ') break;
      uVar3 = uVar3 + 1 & 0xff;
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar3 < 8);
    if ((uVar6 == 0) || (7 < uVar6)) {
      local_28 = *param_3;
      local_24 = param_3[1];
    }
    else {
      memcpy(&local_28,(void *)(uVar6 + (int)param_3),8 - uVar6);
    }
    uVar2 = local_24;
    uVar1 = local_28;
    _Buf1 = (undefined4 *)(uVar5 * 0x2c + iVar7);
    iVar7 = memcmp(_Buf1,&local_28,8);
    if ((iVar7 != 0) || (iVar7 = memcmp(_Buf1,param_3,8), iVar7 != 0)) {
      *_Buf1 = uVar1;
      _Buf1[1] = uVar2;
      *param_3 = uVar1;
      param_3[1] = uVar2;
      FUN_0004a3f4(local_20);
      return 1;
    }
  }
  FUN_0004a3f4(local_20);
  return 0;
}



/* 000311ec FUN_000311ec */

/* Boundary evidence: original MIPS .pdata 000311ec..00031343. Semantic name remains unreviewed. */

void FUN_000311ec(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  HANDLE hFile;
  DWORD local_30 [2];
  ushort local_28;
  undefined4 local_26;
  undefined4 local_22;
  uint local_1c;
  
  local_1c = DAT_00064820;
  memset(param_3,0,8);
  hFile = CreateFileW(L"\\Storage Card\\system\\psnlist.dbf",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0
                      ,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    ReadFile(hFile,&local_28,10,local_30,(LPOVERLAPPED)0x0);
    while (local_30[0] == 10) {
      if (local_28 == param_2) {
        *param_3 = local_26;
        param_3[1] = local_22;
        break;
      }
      ReadFile(hFile,&local_28,10,local_30,(LPOVERLAPPED)0x0);
    }
    CloseHandle(hFile);
  }
  FUN_0004a3f4(local_1c);
  return;
}



/* 00031344 FUN_00031344 */

/* Boundary evidence: original MIPS .pdata 00031344..0003154f. Semantic name remains unreviewed. */

void FUN_00031344(undefined1 *param_1)

{
  HANDLE pvVar1;
  BOOL BVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  LPVOID lpBuffer;
  DWORD local_30 [2];
  
  lpBuffer = *(LPVOID *)(param_1 + 4);
  pvVar1 = CreateFileW(L"\\Storage Card2\\stationlist.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3
                       ,0x80,(HANDLE)0x0);
  iVar6 = 0;
  if (pvVar1 == (HANDLE)0xffffffff) {
    memset(*(void **)(param_1 + 4),0,0x1600);
  }
  else {
    BVar2 = ReadFile(pvVar1,lpBuffer,0x1600,local_30,(LPOVERLAPPED)0x0);
    if ((BVar2 == 0) || (local_30[0] != 0x1600)) {
      memset(*(void **)(param_1 + 4),0,0x1600);
    }
    CloseHandle(pvVar1);
  }
  uVar5 = 0;
  do {
    pbVar3 = (byte *)(uVar5 + (int)lpBuffer);
    uVar4 = uVar5 & 3;
    uVar5 = uVar5 + 1;
    iVar6 = (uint)*pbVar3 * (uVar4 + 1) + iVar6;
  } while (uVar5 < 0x1600);
  *param_1 = (char)iVar6;
  pvVar1 = CreateFileW(L"\\Storage Card2\\stationorder.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,
                       3,0x80,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    uVar5 = 0;
    do {
      param_1[uVar5 + 8] = (char)uVar5;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x80);
  }
  else {
    BVar2 = ReadFile(pvVar1,param_1 + 8,0x80,local_30,(LPOVERLAPPED)0x0);
    if ((BVar2 == 0) || (local_30[0] != 0x80)) {
      uVar5 = 0;
      do {
        (param_1 + 8)[uVar5] = (char)uVar5;
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0x80);
    }
    CloseHandle(pvVar1);
  }
  return;
}



/* 00031550 FUN_00031550 */

/* Boundary evidence: original MIPS .pdata 00031550..00031787. Semantic name remains unreviewed. */

void FUN_00031550(byte *param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  LPCVOID lpBuffer;
  DWORD local_30 [2];
  
  iVar6 = 0;
  lpBuffer = *(LPCVOID *)(param_1 + 4);
  uVar5 = 0;
  uVar4 = 0;
  do {
    pbVar2 = (byte *)(uVar4 + (int)lpBuffer);
    uVar3 = uVar4 & 3;
    uVar4 = uVar4 + 1;
    uVar5 = (uint)*pbVar2 * (uVar3 + 1) + uVar5;
  } while (uVar4 < 0x1600);
  if ((uint)*param_1 == (uVar5 & 0xff)) {
    return;
  }
  hFile = CreateFileW(L"\\Storage Card2\\stationlist.cfg",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                      0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
LAB_00031614:
    NKDbgPrintfW(L"McmMgr : File write error.\r\n");
  }
  else {
    BVar1 = WriteFile(hFile,lpBuffer,0x1600,local_30,(LPOVERLAPPED)0x0);
    if ((BVar1 == 0) || (local_30[0] != 0x1600)) {
      NKDbgPrintfW(L"McmMgr : File write error.");
    }
    else {
      CloseHandle(hFile);
      uVar5 = 0;
      do {
        pbVar2 = (byte *)(uVar5 + (int)lpBuffer);
        uVar4 = uVar5 & 3;
        uVar5 = uVar5 + 1;
        iVar6 = (uint)*pbVar2 * (uVar4 + 1) + iVar6;
      } while (uVar5 < 0x1600);
      *param_1 = (byte)iVar6;
      hFile = CreateFileW(L"\\Storage Card2\\stationorder.cfg",0x40000000,0,
                          (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
      if (hFile == (HANDLE)0xffffffff) goto LAB_00031614;
      BVar1 = WriteFile(hFile,param_1 + 8,0x80,local_30,(LPOVERLAPPED)0x0);
      if ((BVar1 != 0) && (local_30[0] == 0x80)) {
        CloseHandle(hFile);
        return;
      }
      NKDbgPrintfW(L"McmMgr : File write error.");
    }
    CloseHandle(hFile);
  }
  return;
}



/* 00031788 FUN_00031788 */

/* Boundary evidence: original MIPS .pdata 00031788..0003185f. Semantic name remains unreviewed. */

uint FUN_00031788(int param_1,uint param_2,uint param_3)

{
  short *psVar1;
  undefined4 *_Dst;
  uint uVar2;
  
  uVar2 = 0;
  psVar1 = (short *)(*(int *)(param_1 + 4) + 8);
  do {
    if (*psVar1 == 0) break;
    uVar2 = uVar2 + 1;
    psVar1 = psVar1 + 0x16;
  } while (uVar2 < 0x80);
  if (uVar2 == 0x80) {
    uVar2 = (uint)*(byte *)(param_1 + 0x87);
  }
  _Dst = (undefined4 *)(uVar2 * 0x2c + *(int *)(param_1 + 4));
  memset(_Dst,0,0x2c);
  *(short *)(_Dst + 2) = (short)param_2;
  *(undefined1 *)((int)_Dst + 10) = 1;
  *(char *)((int)_Dst + 0xb) = (char)(param_3 / 100) + -0x6b;
  FUN_000311ec(param_1,param_2,_Dst);
  return uVar2;
}



/* 00031860 FUN_00031860 */

/* Boundary evidence: original MIPS .pdata 00031860..000318df. Semantic name remains unreviewed. */

undefined4 FUN_00031860(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = 0;
    puVar3 = (ushort *)(*(int *)(param_1 + 4) + 8);
    do {
      if (param_2 == *puVar3) goto LAB_000318ac;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 0x16;
    } while (uVar2 < 0x80);
    uVar2 = 0xffffffff;
LAB_000318ac:
    *(uint *)(param_1 + 0x88) = uVar2;
    if (uVar2 == 0xffffffff) {
      uVar2 = FUN_00031788(param_1,param_2,param_3);
      *(uint *)(param_1 + 0x88) = uVar2;
    }
    FUN_00030d90(param_1,*(uint *)(param_1 + 0x88));
    uVar1 = *(undefined4 *)(param_1 + 0x88);
  }
  return uVar1;
}



/* 000318e0 FUN_000318e0 */

/* Boundary evidence: original MIPS .pdata 000318e0..000319b3. Semantic name remains unreviewed. */

void FUN_000318e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  ushort local_38 [18];
  uint local_14;
  
  local_14 = DAT_00064820;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memcpy(local_38,&local_res4,0x24);
  uVar2 = (uint)local_38[0];
  if (uVar2 != 0) {
    iVar4 = *(int *)(param_1 + 4);
    uVar1 = 0;
    puVar3 = (ushort *)(iVar4 + 8);
    do {
      if (uVar2 == *puVar3) goto LAB_00031964;
      uVar1 = uVar1 + 1;
      puVar3 = puVar3 + 0x16;
    } while (uVar1 < 0x80);
    uVar1 = 0xffffffff;
LAB_00031964:
    if ((int)uVar1 < 0) {
      uVar1 = FUN_00031788(param_1,uVar2,0);
    }
    memcpy((void *)(uVar1 * 0x2c + iVar4 + 8),local_38,0x24);
  }
  FUN_0004a3f4(local_14);
  return;
}



/* 000319b4 FUN_000319b4 */

/* Boundary evidence: original MIPS .pdata 000319b4..00031ad3. Semantic name remains unreviewed. */

void FUN_000319b4(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 4);
  uVar2 = 0;
  puVar4 = (ushort *)(iVar8 + 8);
  do {
    if (param_2 == *puVar4) goto LAB_000319ec;
    uVar2 = uVar2 + 1;
    puVar4 = puVar4 + 0x16;
  } while (uVar2 < 0x80);
  uVar2 = 0xffffffff;
LAB_000319ec:
  if ((int)uVar2 < 0) {
    FUN_00031788(param_1,param_2,param_3);
  }
  else {
    uVar6 = 0;
    iVar1 = uVar2 * 0x2c;
    uVar3 = param_3 / 100 + 0x95;
    iVar7 = iVar1 + iVar8;
    uVar2 = (uint)*(byte *)(iVar7 + 10);
    if (uVar2 != 0) {
      do {
        if ((uint)*(byte *)(uVar6 + iVar1 + iVar8 + 0xb) == (uVar3 & 0xff)) break;
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < *(byte *)(iVar7 + 10));
    }
    if (uVar6 == uVar2) {
      if (uVar2 < 0x20) {
        *(byte *)(iVar7 + 10) = *(byte *)(iVar7 + 10) + 1;
      }
      else {
        *(undefined1 *)(iVar7 + 10) = 0x20;
        uVar6 = 0xf;
      }
    }
    for (; uVar6 != 0; uVar6 = uVar6 + 0xff & 0xff) {
      iVar5 = uVar6 + iVar1 + iVar8;
      *(undefined1 *)(iVar5 + 0xb) = *(undefined1 *)(iVar5 + 10);
    }
    *(char *)(iVar7 + 0xb) = (char)uVar3;
  }
  return;
}



/* 00031ad4 FUN_00031ad4 */

/* Boundary evidence: original MIPS .pdata 00031ad4..00031b0b. Semantic name remains unreviewed. */

undefined1 * FUN_00031ad4(undefined1 *param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(0x1600);
  *(void **)(param_1 + 4) = pvVar1;
  FUN_00031344(param_1);
  return param_1;
}



/* 00031b0c FUN_00031b0c */

/* Boundary evidence: original MIPS .pdata 00031b0c..00031b57. Semantic name remains unreviewed. */

undefined4 FUN_00031b0c(LPCWSTR param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  DVar1 = GetFileAttributesW(param_1);
  if (DVar1 == 0xffffffff) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    if ((DVar1 & 0x10) == 0) {
      uVar2 = 2;
    }
  }
  return uVar2;
}



/* 00031b58 FUN_00031b58 */

undefined4 FUN_00031b58(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0;
  uVar5 = 0;
  if (DAT_00068078 == '\x03') {
    uVar6 = 76000;
    uVar2 = 90000;
  }
  else if (DAT_00068078 == '\x04') {
    uVar6 = 0x15694;
    uVar2 = 0x1a57c;
  }
  else {
    uVar6 = 0x155cc;
    uVar2 = 0x1a5e0;
  }
  if (DAT_00068078 != '\x01') {
    if (DAT_00068078 != '\x02') {
      if (DAT_00068078 == '\x03') {
        uVar1 = 0x20a;
        uVar3 = 0x65d;
      }
      else {
        if (DAT_00068078 == '\x04') {
          uVar1 = 0x212;
        }
        else {
          if (DAT_00068078 != '\x05') {
            if (DAT_00063a30 == '\x01') {
              uVar1 = 0x20a;
              uVar3 = 0x64b;
            }
            else {
              uVar3 = 0x11b;
              if (DAT_00063a30 == '\x02') {
                uVar1 = 0x95;
              }
              else {
                uVar1 = 0x95;
                uVar4 = 0x20a;
                uVar5 = 0x64b;
              }
            }
            goto LAB_00031c70;
          }
          uVar1 = 0x20a;
        }
        uVar3 = 0x6ae;
      }
      goto LAB_00031c70;
    }
    if (DAT_00063a30 != '\x01') {
      uVar1 = 0x95;
      uVar3 = 0x11b;
      if (DAT_00063a30 != '\x02') {
        uVar4 = 0x213;
        uVar5 = 0x642;
      }
      goto LAB_00031c70;
    }
  }
  uVar3 = 0x642;
  uVar1 = 0x213;
LAB_00031c70:
  if (DAT_00067694 < uVar6) {
    DAT_00067690 = 0;
    DAT_00067694 = uVar6;
  }
  else if (uVar2 < DAT_00067694) {
    DAT_00067690 = 0;
    DAT_00067694 = uVar2;
  }
  if (DAT_00067b20 < uVar1) {
    DAT_00067b1c = 0;
    DAT_00067b20 = uVar1;
    return 1;
  }
  if (uVar4 != 0) {
    if (DAT_00067b20 <= uVar3) {
      return 1;
    }
    if (DAT_00067b20 < uVar4) {
      DAT_00067b1c = 0;
      DAT_00067b20 = uVar4;
      return 1;
    }
  }
  if (((uVar3 < DAT_00067b20) && (uVar5 < DAT_00067b20)) &&
     (DAT_00067b1c = 0, DAT_00067b20 = uVar5, uVar5 < uVar3)) {
    DAT_00067b20 = uVar3;
  }
  return 1;
}



/* 00031d3c FUN_00031d3c */

void FUN_00031d3c(void)

{
  uint3 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  if (DAT_00068078 == '\0') {
    uVar1 = (uint3)DAT_00067678 & 0xffffaf | 0x2c;
  }
  else if (DAT_00068078 == '\x04') {
    uVar1 = (uint3)DAT_00067678 & 0xffff87 | 4;
  }
  else {
    uVar1 = (uint3)DAT_00067678 & 0xffff8f | 0xc;
  }
  DAT_00067678 = CONCAT13(0x80,uVar1 & 0xfff0ff | 0x80);
  DAT_0006767c = 0x80;
  DAT_0006767d = 0x80;
  DAT_0006767e = 0x80;
  DAT_0006767f = 0x80;
  DAT_00067683 = 0xf;
  DAT_00067684 = 0xf;
  DAT_00067685 = 0xf;
  DAT_00067686 = 0xf;
  DAT_00067687 = 0xf;
  DAT_00067689 = 6;
  puVar2 = &DAT_00067680;
  DAT_00067688 = 5;
  do {
    *puVar2 = 2;
    puVar2 = puVar2 + 1;
  } while (puVar2 != &DAT_00067683);
  DAT_00067678 = DAT_00067678 | 0x4000;
  DAT_0006768c = 0xc;
  uVar5 = 0;
  do {
    puVar3 = (undefined4 *)((int)&DAT_0006769c + uVar5);
    puVar4 = (undefined2 *)((int)&DAT_00067698 + uVar5);
    puVar2 = (undefined1 *)((int)&DAT_000676a0 + uVar5);
    uVar5 = uVar5 + 0x18;
    *puVar3 = 0;
    *puVar4 = 0;
    *puVar2 = 0;
  } while (uVar5 < 0x120);
  uVar5 = 0;
  do {
    puVar3 = (undefined4 *)((int)&DAT_000677bc + uVar5);
    puVar4 = (undefined2 *)((int)&DAT_000677b8 + uVar5);
    puVar2 = (undefined1 *)((int)&DAT_000677c0 + uVar5);
    uVar5 = uVar5 + 0x18;
    *puVar3 = 0;
    *puVar4 = 0;
    *puVar2 = 0;
  } while (uVar5 < 0x360);
  DAT_00067b18 = 0xc;
  uVar5 = 0;
  do {
    puVar3 = (undefined4 *)((int)&DAT_00067b28 + uVar5);
    puVar4 = (undefined2 *)((int)&DAT_00067b24 + uVar5);
    puVar2 = &DAT_00067b2c + uVar5;
    uVar5 = uVar5 + 0x18;
    *puVar3 = 0;
    *puVar4 = 0;
    *puVar2 = 0;
  } while (uVar5 < 0x120);
  uVar5 = 0;
  do {
    puVar3 = (undefined4 *)((int)&DAT_00067c48 + uVar5);
    puVar4 = (undefined2 *)((int)&DAT_00067c44 + uVar5);
    puVar2 = &DAT_00067c4c + uVar5;
    uVar5 = uVar5 + 0x18;
    *puVar3 = 0;
    *puVar4 = 0;
    *puVar2 = 0;
  } while (uVar5 < 0x360);
  return;
}



/* 00031efc FUN_00031efc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 00031efc..00031fa7. Semantic name remains unreviewed. */

void FUN_00031efc(void)

{
  memset(&DAT_00067674,0,0xa00);
  _DAT_00067674 = 0x14;
  DAT_00067678 = DAT_00067678 & 0xffffcfff | 2;
  DAT_0006768c = 0xc;
  DAT_00067690 = 0;
  DAT_00067694 = 0x15630;
  DAT_00067b18 = 0xc;
  DAT_00067b1c = 0;
  DAT_00067b20 = 900;
  DAT_00067fa4 = 1;
  DAT_00067fec = 0x7df;
  DAT_00067fee = 0xb;
  DAT_00067ff2 = 2;
  DAT_00067ff4 = 0xc;
  FUN_00031d3c();
  return;
}



/* 00031fa8 FUN_00031fa8 */

/* Boundary evidence: original MIPS .pdata 00031fa8..0003220b. Semantic name remains unreviewed. */

void FUN_00031fa8(void)

{
  HANDLE hFile;
  HANDLE hFile_00;
  BOOL BVar1;
  BOOL BVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  DWORD local_30;
  DWORD local_2c;
  
  uVar6 = 0x9f8;
  uVar5 = 0;
  pbVar8 = &DAT_00067674;
  do {
    pbVar3 = &DAT_00067674 + uVar5;
    uVar4 = uVar5 & 3;
    uVar5 = uVar5 + 1;
    uVar6 = (uint)*pbVar3 * (uVar4 + 1) + uVar6;
  } while (uVar5 < 0x9f8);
  DAT_0006806c = uVar6 & 0xff;
  iVar7 = 0x9fc;
  uVar5 = 0xffffffff;
  do {
    iVar7 = iVar7 + -1;
    uVar5 = *(uint *)(&DAT_00063a34 + ((*pbVar8 ^ uVar5) & 0xff) * 4) ^ uVar5 >> 8;
    pbVar8 = pbVar8 + 1;
  } while (iVar7 != 0);
  uVar5 = ~uVar5;
  if ((DAT_00068079 != DAT_0006806c) || (DAT_0006807c != uVar5)) {
    hFile = CreateFileW(L"\\Storage Card2\\mgrmcm2.cfg",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                        0x80,(HANDLE)0x0);
    hFile_00 = CreateFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",0x40000000,0,
                           (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
    if ((hFile == (HANDLE)0xffffffff) && (hFile_00 == (HANDLE)0xffffffff)) {
      NKDbgPrintfW(L"McmMgr : File write error.\r\n");
    }
    else {
      DAT_00068070 = uVar5;
      BVar1 = WriteFile(hFile,&DAT_00067674,0xa00,&local_30,(LPOVERLAPPED)0x0);
      BVar2 = WriteFile(hFile_00,&DAT_00067674,0xa00,&local_2c,(LPOVERLAPPED)0x0);
      if (((BVar1 == 0) || (local_30 != 0xa00)) && ((BVar2 == 0 || (local_2c != 0xa00)))) {
        NKDbgPrintfW(L"McmMgr : File write error.");
        if (hFile != (HANDLE)0xffffffff) {
          CloseHandle(hFile);
        }
        if (hFile_00 != (HANDLE)0xffffffff) {
          CloseHandle(hFile_00);
        }
      }
      else {
        if (hFile != (HANDLE)0xffffffff) {
          CloseHandle(hFile);
        }
        if (hFile_00 != (HANDLE)0xffffffff) {
          CloseHandle(hFile_00);
        }
        DAT_00068079 = (byte)uVar6;
        DAT_0006807c = uVar5;
      }
    }
  }
  return;
}



/* 0003220c FUN_0003220c */

/* Boundary evidence: original MIPS .pdata 0003220c..000323f7. Semantic name remains unreviewed. */

void FUN_0003220c(int param_1,int param_2)

{
  undefined4 uVar1;
  char *_Format;
  char *_DstBuf;
  undefined8 uVar2;
  
  _DstBuf = (char *)((param_1 * 0x54 + param_2) * 0x10 + DAT_00064ae4 + 0xc);
  if ((DAT_00067678 & 4) == 0) {
    if ((&DAT_0006769c)[param_2 * 6 + param_1 * 0x123] == 0) {
LAB_000323e4:
      *_DstBuf = '\0';
      return;
    }
    if (param_1 != 1) {
      uVar1 = __ultofp((&DAT_0006769c)[param_2 * 6 + param_1 * 0x123]);
      uVar2 = __fptodp(uVar1);
      __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(_DstBuf,0x10,"%6.2fMHz");
      return;
    }
    _Format = "%dkHz";
  }
  else {
    if (*(char *)(&DAT_000676a0 + param_2 * 6 + param_1 * 0x123) != '\0') {
      strncpy_s(_DstBuf,0x10,(char *)(&DAT_000676a0 + param_2 * 6 + param_1 * 0x123),0xf);
      return;
    }
    if ((&DAT_0006769c)[param_2 * 6 + param_1 * 0x123] == 0) goto LAB_000323e4;
    if (param_1 != 1) {
      uVar1 = __ultofp((&DAT_0006769c)[param_2 * 6 + param_1 * 0x123]);
      uVar2 = __fptodp(uVar1);
      __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(_DstBuf,0x10,"[%6.2fMHz]");
      return;
    }
    _Format = "[%dkHz]";
  }
  sprintf_s(_DstBuf,0x10,_Format,(&DAT_00067b28)[param_2 * 6]);
  return;
}



/* 000323f8 FUN_000323f8 */

/* Boundary evidence: original MIPS .pdata 000323f8..00032673. Semantic name remains unreviewed. */

void FUN_000323f8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *_DstBuf;
  char *pcVar3;
  undefined8 uVar4;
  
  iVar2 = (param_1 * 0x2a + param_2) * 0x20 + DAT_00064ae4;
  pcVar3 = (char *)(iVar2 + 0xdc);
  *pcVar3 = '\0';
  _DstBuf = (char *)(iVar2 + 0xcc);
  if ((DAT_00067678 & 4) == 0) {
    if ((&DAT_000677bc)[param_2 * 6 + param_1 * 0x123] == 0) {
LAB_00032650:
      *_DstBuf = '\0';
      return;
    }
    if (param_1 != 1) {
      uVar1 = __ultofp();
      uVar4 = __fptodp(uVar1);
      __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(_DstBuf,0x10,"%6.2fMHz");
      return;
    }
    pcVar3 = "%dkHz";
  }
  else {
    if (*(char *)(&DAT_000677c0 + param_2 * 6 + param_1 * 0x123) != '\0') {
      strncpy_s(_DstBuf,0x10,(char *)(&DAT_000677c0 + param_2 * 6 + param_1 * 0x123),0xf);
      if (param_1 == 1) {
        return;
      }
      if ((&DAT_000677b8)[param_2 * 0xc + param_1 * 0x246] == 0) {
        return;
      }
      uVar1 = __ultofp((&DAT_000677bc)[param_2 * 6 + param_1 * 0x123]);
      uVar4 = __fptodp(uVar1);
      __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(pcVar3,0x10,"%6.2fMHz");
      return;
    }
    if ((&DAT_000677bc)[param_2 * 6 + param_1 * 0x123] == 0) goto LAB_00032650;
    if (param_1 != 1) {
      uVar1 = __ultofp();
      uVar4 = __fptodp(uVar1);
      __dpmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(_DstBuf,0x10,"[%6.2fMHz]");
      return;
    }
    pcVar3 = "[%dkHz]";
  }
  sprintf_s(_DstBuf,0x10,pcVar3,(&DAT_00067c48)[param_2 * 6]);
  return;
}



/* 00032674 FUN_00032674 */

/* Boundary evidence: original MIPS .pdata 00032674..000326bf. Semantic name remains unreviewed. */

undefined4 FUN_00032674(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x23) {
    uVar1 = *(undefined4 *)(&DAT_00063e34 + param_1 * 4);
  }
  else {
    NKDbgPrintfW(L"**[error unkown]  CovertLanguageIndexFromDsi = %d\r\n",param_1);
    uVar1 = 2;
  }
  return uVar1;
}



/* 000326c0 FUN_000326c0 */

byte FUN_000326c0(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      bVar1 = *(byte *)(iVar2 + param_1) ^ bVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return bVar1;
}



/* 000326f0 FUN_000326f0 */

/* Boundary evidence: original MIPS .pdata 000326f0..00032883. Semantic name remains unreviewed. */

char FUN_000326f0(char param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  char cVar3;
  
  cVar3 = -1;
  memset(&DAT_00068084,0xff,4);
  memset(&DAT_00068080,0xff,4);
  iVar1 = FUN_00027fc8();
  if (iVar1 != 0) {
    DAT_00068080 = param_1;
    DAT_00068083 = param_1;
    iVar1 = FUN_0002812c(&DAT_00068084,0xbfeee000,4);
    if (iVar1 != 0) {
      NKDbgPrintfW(L"** Storead CAR TYPE= %d, Changing CAR TYPE= %d\r\n",DAT_00068084,DAT_00068080);
    }
    if (DAT_00068084 == DAT_00068080) {
      NKDbgPrintfW(L"Car Maker is same !!! [%d] \r\n",DAT_00068084);
    }
    else {
      iVar1 = FUN_00028180(0xbfeee000,4);
      if (iVar1 == 0) {
        pwVar2 = L"ERROR! Fail to erase NOR flash..\n";
      }
      else {
        iVar1 = FUN_000280d8(0xbfeee000,&DAT_00068080,4);
        if (iVar1 == 0) {
          pwVar2 = L"Failed to write flash\r\n";
        }
        else {
          pwVar2 = L"Success to write flash\r\n";
        }
      }
      NKDbgPrintfW(pwVar2);
      iVar1 = FUN_0002812c(&DAT_00068084,0xbfeee000,4);
      if (iVar1 != 0) {
        NKDbgPrintfW(L"** Validation Car TYPE changed from %d to %d\r\n",DAT_00068080,DAT_00068084);
      }
    }
    cVar3 = DAT_00068084;
    FUN_00028088();
    NKDbgPrintfW(L"[INFO] %s errCode %d \r\n","SetCarType",cVar3);
  }
  return cVar3;
}



/* 00032884 FUN_00032884 */

/* Boundary evidence: original MIPS .pdata 00032884..00032a37. Semantic name remains unreviewed. */

undefined4
FUN_00032884(undefined4 *param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5,
            uint *param_6)

{
  HANDLE hFile;
  undefined4 uVar1;
  DWORD aDStack_58 [2];
  undefined1 auStack_50 [3];
  byte local_4d;
  byte local_4c;
  byte local_4b;
  byte local_49;
  ushort local_48;
  uint local_2c;
  
  local_2c = DAT_00064820;
  memset(auStack_50,0,0x24);
  local_48 = 0x2a2a;
  hFile = CreateFileW(L"\\Storage Card\\system\\DSI_config.bsd",0x80000000,0,
                      (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"%s : File open error.\r\n",L"\\Storage Card\\system\\DSI_config.bsd");
    FUN_0004a3f4(local_2c);
    uVar1 = 0;
  }
  else {
    ReadFile(hFile,auStack_50,0x24,aDStack_58,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
    if (param_1 != (undefined4 *)0x0) {
      uVar1 = FUN_00032674((uint)local_4d);
      *param_1 = uVar1;
    }
    uVar1 = 1;
    if (param_2 != (undefined4 *)0x0) {
      if ((local_49 & 1) == 0) {
        *param_2 = 1;
      }
      else {
        *param_2 = 0;
      }
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = local_49 >> 1 & 1;
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = (uint)local_4b;
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = (uint)local_48;
    }
    if (param_6 != (uint *)0x0) {
      *param_6 = (uint)local_4c;
    }
    FUN_0004a3f4(local_2c);
  }
  return uVar1;
}



/* 00032a38 FUN_00032a38 */

/* Boundary evidence: original MIPS .pdata 00032a38..00032c6b. Semantic name remains unreviewed. */

void FUN_00032a38(void)

{
  int iVar1;
  HANDLE hFile;
  BOOL BVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_138;
  undefined4 local_134;
  uint local_130;
  uint local_12c;
  DWORD DStack_128;
  DWORD DStack_124;
  byte local_120 [68];
  undefined4 local_dc;
  uint local_d8;
  undefined4 local_c4;
  byte local_a1;
  undefined1 auStack_a0 [128];
  uint local_20;
  
  local_20 = DAT_00064820;
  iVar1 = FUN_00032884(&local_138,&local_134,&local_130,&local_12c,(uint *)0x0,(uint *)0x0);
  uVar4 = local_138;
  uVar5 = local_134;
  uVar6 = local_130;
  uVar7 = local_12c;
  if (iVar1 == 0) {
    NKDbgPrintfW(L"Fail to get DSI setting Info.. default setting\n");
    uVar4 = 2;
    uVar5 = 0;
    uVar6 = 0;
    uVar7 = 0;
  }
  hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"[SetUserData]Fail to open file : MgrSys.cfg\n");
    goto LAB_00032c14;
  }
  BVar2 = ReadFile(hFile,auStack_a0,0x80,&DStack_128,(LPOVERLAPPED)0x0);
  if (BVar2 != 0) {
    memcpy(local_120,auStack_a0,0x80);
    local_dc = uVar5;
    local_a1 = 0;
    local_d8 = uVar6;
    iVar1 = 0;
    local_c4 = uVar4;
    do {
      local_a1 = local_120[iVar1] ^ local_a1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x7f);
    iVar1 = memcmp(auStack_a0,local_120,0x80);
    if (iVar1 == 0) {
      pwVar3 = L"[SetUserData] MgrSys configuration changed !!!\n";
    }
    else {
      SetFilePointer(hFile,0,(PLONG)0x0,0);
      BVar2 = WriteFile(hFile,local_120,0x80,&DStack_124,(LPOVERLAPPED)0x0);
      if (BVar2 != 0) goto LAB_00032bf0;
      pwVar3 = L"MgrSys.cfg write error\r\n";
    }
    NKDbgPrintfW(pwVar3);
  }
LAB_00032bf0:
  CloseHandle(hFile);
LAB_00032c14:
  DAT_00067678 = (uVar7 << 8 ^ DAT_00067678) & 0x700 ^ DAT_00067678;
  *(char *)(DAT_00064ae4 + 0xaf3) = (char)uVar7;
  FUN_00031fa8();
  FUN_0004a3f4(local_20);
  return;
}



/* 00032c6c FUN_00032c6c */

/* Boundary evidence: original MIPS .pdata 00032c6c..00032e7b. Semantic name remains unreviewed. */

void FUN_00032c6c(uint param_1,undefined1 *param_2)

{
  uint uVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  wchar_t *pwVar4;
  int iVar5;
  uint uVar6;
  DWORD DStack_b8;
  DWORD DStack_b4;
  byte local_b0 [92];
  uint local_54;
  byte local_31;
  uint local_30;
  
  local_30 = DAT_00064820;
  if (param_1 < 0x23) {
    uVar1 = FUN_00032674(param_1);
    uVar6 = uVar1 & 0xff;
    *param_2 = (char)uVar1;
    pvVar2 = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                         0x80,(HANDLE)0x0);
    if (pvVar2 != (HANDLE)0xffffffff) {
      BVar3 = ReadFile(pvVar2,local_b0,0x80,&DStack_b4,(LPOVERLAPPED)0x0);
      uVar1 = uVar6;
      if (BVar3 != 0) {
        uVar1 = local_54 & 0xff;
      }
      CloseHandle(pvVar2);
      if (uVar1 == uVar6) {
        pwVar4 = L"=== same language - (%d/%d)\n";
      }
      else {
        pvVar2 = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,
                             3,0x80,(HANDLE)0x0);
        if (pvVar2 == (HANDLE)0xffffffff) {
          pwVar4 = L"=== error no mgrsys.cfg file - (%d/%d)\n";
        }
        else {
          local_31 = 0;
          local_54 = uVar6;
          iVar5 = 0;
          do {
            local_31 = local_b0[iVar5] ^ local_31;
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0x7f);
          BVar3 = WriteFile(pvVar2,local_b0,0x80,&DStack_b8,(LPOVERLAPPED)0x0);
          if (BVar3 == 0) {
            NKDbgPrintfW(L"[%s] write error\r\n","SaveDSILanguage");
          }
          CloseHandle(pvVar2);
          pwVar4 = L"=== saved new language - (%d/%d)\n";
        }
      }
      NKDbgPrintfW(pwVar4,uVar1,uVar6);
    }
  }
  else {
    *param_2 = 2;
  }
  FUN_0004a3f4(local_30);
  return;
}



/* 00032e7c FUN_00032e7c */

/* Boundary evidence: original MIPS .pdata 00032e7c..0003302b. Semantic name remains unreviewed. */

void FUN_00032e7c(uint param_1,byte *param_2,byte *param_3,byte *param_4)

{
  HANDLE hFile;
  BOOL BVar1;
  int iVar2;
  DWORD DStack_a8;
  DWORD DStack_a4;
  byte local_a0 [68];
  uint local_5c;
  uint local_58;
  uint local_38;
  byte local_21;
  uint local_20;
  
  local_20 = DAT_00064820;
  *param_3 = (param_1 & 1) == 0;
  *param_2 = (byte)((param_1 & 2) >> 1);
  *param_4 = (byte)((param_1 & 4) >> 2);
  hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    BVar1 = ReadFile(hFile,local_a0,0x80,&DStack_a4,(LPOVERLAPPED)0x0);
    if (BVar1 != 0) {
      local_21 = 0;
      iVar2 = 0;
      local_5c = (uint)*param_3;
      local_58 = (uint)*param_2;
      local_38 = (uint)*param_4;
      do {
        local_21 = local_a0[iVar2] ^ local_21;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x7f);
      SetFilePointer(hFile,0,(PLONG)0x0,0);
      BVar1 = WriteFile(hFile,local_a0,0x80,&DStack_a8,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        NKDbgPrintfW(L"[%s] write error\r\n","SaveDSIUserInterface");
      }
    }
    CloseHandle(hFile);
  }
  FUN_0004a3f4(local_20);
  return;
}



/* 0003302c FUN_0003302c */

undefined4 FUN_0003302c(byte *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 < 0x20) && (param_1[1] < 0xd)) && (param_1[2] < 100)) &&
     (((param_1[3] < 0x23 && (param_1[4] < 6)) && (param_1[5] < 6)))) {
    uVar1 = 0xffffffff;
    if (param_1[6] < 10) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* 000330b0 FUN_000330b0 */

/* Boundary evidence: original MIPS .pdata 000330b0..00033293. Semantic name remains unreviewed. */

uint FUN_000330b0(void *param_1)

{
  HANDLE hFile;
  DWORD DVar1;
  void *lpBuffer;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  DWORD aDStack_48 [2];
  byte local_40 [32];
  uint local_20;
  uint local_1c;
  
  local_1c = DAT_00064820;
  uVar4 = 0xffffffff;
  hFile = CreateFileW(L"\\Storage Card\\system\\DSI_config.bsd",0x80000000,0,
                      (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"\n[CheckDsiConfigFile] **No file!!\n");
  }
  else {
    DVar1 = GetFileSize(hFile,(LPDWORD)0x0);
    if (DVar1 == 0x24) {
      lpBuffer = malloc(0x25);
      if (lpBuffer == (void *)0x0) {
        NKDbgPrintfW(L"\n[CheckDsiConfigFile] **Memmory allocation error!!\n");
        uVar4 = 1;
      }
      else {
        ReadFile(hFile,lpBuffer,0x24,aDStack_48,(LPOVERLAPPED)0x0);
        memcpy(local_40,lpBuffer,0x24);
        iVar2 = FUN_0003302c(local_40);
        if (iVar2 != -1) {
          iVar2 = 0x20;
          pbVar3 = local_40;
          do {
            iVar2 = iVar2 + -1;
            uVar4 = *(uint *)(&DAT_00063a34 + ((*pbVar3 ^ uVar4) & 0xff) * 4) ^ uVar4 >> 8;
            pbVar3 = pbVar3 + 1;
          } while (iVar2 != 0);
          if (~uVar4 == local_20) {
            if (param_1 != (void *)0x0) {
              memcpy(param_1,lpBuffer,0x24);
            }
            uVar4 = 0;
          }
          else {
            NKDbgPrintfW(L"\n[CheckDsiConfigFile] **Diff CRC** ::saved=%d, calcurated=%d\n");
            uVar4 = 2;
          }
        }
        free(lpBuffer);
      }
    }
    else {
      NKDbgPrintfW(L"\n[CheckDsiConfigFile] **Diff val** ::fsize=%d, dwData=%d\n",DVar1,0x24);
      uVar4 = 3;
    }
    CloseHandle(hFile);
  }
  FUN_0004a3f4(local_1c);
  return uVar4;
}



/* 00033294 FUN_00033294 */

/* Boundary evidence: original MIPS .pdata 00033294..0003341b. Semantic name remains unreviewed. */

undefined4 FUN_00033294(void *param_1,size_t param_2)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  DWORD aDStack_40 [2];
  byte local_38 [32];
  uint local_18;
  uint local_14;
  
  local_14 = DAT_00064820;
  uVar5 = 0;
  memset(local_38,0,0x24);
  memcpy(local_38,param_1,param_2);
  iVar3 = 0x20;
  pbVar4 = local_38;
  local_18 = ~local_18;
  do {
    iVar3 = iVar3 + -1;
    local_18 = *(uint *)(&DAT_00063a34 + ((*pbVar4 ^ local_18) & 0xff) * 4) ^ local_18 >> 8;
    pbVar4 = pbVar4 + 1;
  } while (iVar3 != 0);
  local_18 = ~local_18;
  hFile = CreateFileW(L"\\Storage Card\\system\\DSI_config.bsd",0x40000000,0,
                      (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"Error!! %s [%s]file open error [0x%08X]!!!\n","SetDSIConfigData",
                 L"\\Storage Card\\system\\DSI_config.bsd",DVar2);
  }
  else {
    BVar1 = WriteFile(hFile,local_38,0x24,aDStack_40,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      NKDbgPrintfW(L"[%s] write error\r\n","SetDSIConfigData");
    }
    CloseHandle(hFile);
    uVar5 = 1;
  }
  FUN_0004a3f4(local_14);
  return uVar5;
}



/* 0003341c FUN_0003341c */

/* Boundary evidence: original MIPS .pdata 0003341c..000336b3. Semantic name remains unreviewed. */

void FUN_0003341c(int param_1,byte *param_2)

{
  byte bVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t awStack_f0 [100];
  uint local_28;
  
  local_28 = DAT_00064820;
  if ((param_1 != 0) && (param_2 != (byte *)0x0)) {
    NKDbgPrintfW(L"\n===============================================");
    pwVar2 = L"Active";
    if ((*param_2 & 1) == 0) {
      pwVar2 = L"Passive";
    }
    NKDbgPrintfW(L"\n AM-FM antenna : %s",pwVar2);
    pwVar5 = L"Deactivated";
    pwVar2 = pwVar5;
    if ((*param_2 & 2) == 0) {
      pwVar2 = L"Activated";
    }
    NKDbgPrintfW(L"\n AM_MW : %s",pwVar2);
    pwVar2 = pwVar5;
    if ((*param_2 & 4) == 0) {
      pwVar2 = L"Activated";
    }
    NKDbgPrintfW(L"\n AM_LW : %s",pwVar2);
    pwVar3 = L"Not fitted";
    pwVar4 = L"Fitted";
    pwVar2 = pwVar3;
    if ((*param_2 & 8) == 0) {
      pwVar2 = L"Fitted";
    }
    NKDbgPrintfW(L"\n SDVC : %s",pwVar2);
    pwVar2 = pwVar4;
    if ((*param_2 & 0x10) == 0) {
      pwVar2 = L"Not fitted";
    }
    NKDbgPrintfW(L"\n AUX : %s",pwVar2);
    pwVar2 = pwVar3;
    if ((*param_2 & 0x20) == 0) {
      pwVar2 = L"Fitted";
    }
    NKDbgPrintfW(L"\n MIC : %s",pwVar2);
    bVar1 = *param_2 >> 6;
    if (bVar1 == 0) {
      pwVar2 = L"No SWRC";
    }
    else if (bVar1 == 1) {
      pwVar2 = L"TYPE #1";
    }
    else if (bVar1 == 2) {
      pwVar2 = L"TYPE #2";
    }
    else {
      pwVar2 = L"Unknown type";
    }
    StringCchPrintfW(awStack_f0,100,pwVar2);
    NKDbgPrintfW(L"\n SWRC : %s",awStack_f0);
    pwVar2 = L"Active";
    if ((param_2[1] & 1) == 0) {
      pwVar2 = L"Passive";
    }
    NKDbgPrintfW(L"\n DR antenna : %s",pwVar2);
    pwVar2 = L"Activated";
    if ((param_2[1] & 2) == 0) {
      pwVar2 = pwVar5;
    }
    NKDbgPrintfW(L"\n DR(DAB) : %s",pwVar2);
    pwVar2 = pwVar4;
    if ((param_2[1] & 4) == 0) {
      pwVar2 = L"Not fitted";
    }
    NKDbgPrintfW(L"\n RVC : %s",pwVar2);
    pwVar2 = pwVar3;
    if ((param_2[1] & 8) == 0) {
      pwVar2 = L"Fitted";
    }
    NKDbgPrintfW(L"\n GPS : %s",pwVar2);
    if ((param_2[1] & 0x10) == 0) {
      pwVar3 = pwVar4;
    }
    NKDbgPrintfW(L"\n Rear SPEAKER : %s",pwVar3);
    NKDbgPrintfW(L"\n===============================================\n");
  }
  FUN_0004a3f4(local_28);
  return;
}



/* 000336b4 FUN_000336b4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 000336b4..00033bd3. Semantic name remains unreviewed. */

void FUN_000336b4(void)

{
  HANDLE pvVar1;
  HANDLE hObject;
  BOOL BVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  bool bVar9;
  HANDLE hFile;
  int iVar10;
  uint uVar11;
  DWORD local_a3c;
  undefined *local_a38;
  undefined1 auStack_a30 [2556];
  uint local_34;
  uint local_30;
  
  local_30 = DAT_00064820;
  pvVar1 = CreateFileW(L"\\Storage Card2\\mgrmcm2.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  hObject = CreateFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",0x80000000,0,
                        (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  uVar11 = 0x9f8;
  uVar8 = 0xffffffff;
  pbVar7 = &DAT_00067674;
  local_a38 = &DAT_00063a34;
  if ((pvVar1 == (HANDLE)0xffffffff) && (hObject == (HANDLE)0xffffffff)) {
    FUN_00031efc();
    bVar9 = true;
  }
  else {
    bVar9 = pvVar1 == (HANDLE)0xffffffff;
    hFile = hObject;
    if (!bVar9) {
      hFile = pvVar1;
    }
    memset(&DAT_00067674,0,0xa00);
    BVar2 = ReadFile(hFile,&DAT_00067674,0xa00,&local_a3c,(LPOVERLAPPED)0x0);
    if (pvVar1 != (HANDLE)0x0) {
      CloseHandle(pvVar1);
    }
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
    uVar5 = 0x9f8;
    uVar6 = 0;
    do {
      pbVar3 = &DAT_00067674 + uVar6;
      uVar4 = uVar6 & 3;
      uVar6 = uVar6 + 1;
      uVar5 = (uint)*pbVar3 * (uVar4 + 1) + uVar5;
    } while (uVar6 < 0x9f8);
    uVar5 = uVar5 & 0xff;
    iVar10 = 0x9fc;
    uVar6 = uVar8;
    pbVar3 = pbVar7;
    do {
      iVar10 = iVar10 + -1;
      uVar6 = *(uint *)(local_a38 + ((*pbVar3 ^ uVar6) & 0xff) * 4) ^ uVar6 >> 8;
      pbVar3 = pbVar3 + 1;
    } while (iVar10 != 0);
    uVar6 = ~uVar6;
    if (((BVar2 == 0) || (local_a3c != 0xa00)) || (_DAT_00067674 != 0x14)) {
LAB_000338d8:
      if ((uVar5 == DAT_0006806c) && (uVar6 == DAT_00068070)) {
        FUN_00031efc();
      }
      else {
LAB_000338f8:
        NKDbgPrintfW(L"[ERROR] %s : Checksum value [%d][0x%02X, 0x%02X][0x%08X, 0x%08X]\n",
                     "LoadGlobalDataFile",!bVar9,uVar5,DAT_0006806c,uVar6,DAT_00068070);
        if ((uVar6 != DAT_00068070) &&
           ((!bVar9 &&
            (pvVar1 = CreateFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",0x80000000,0,
                                  (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0),
            pvVar1 != (HANDLE)0xffffffff)))) {
          ReadFile(pvVar1,auStack_a30,0xa00,&local_a3c,(LPOVERLAPPED)0x0);
          CloseHandle(pvVar1);
          if (uVar6 == local_34) {
            memcpy(&DAT_00067674,auStack_a30,0xa00);
            NKDbgPrintfW(L"[ERROR] %s : backup configuration loaded!!!\n","LoadGlobalDataFile");
          }
        }
      }
      bVar9 = true;
    }
    else {
      if (uVar5 != DAT_0006806c) goto LAB_000338f8;
      if (uVar6 != DAT_00068070) goto LAB_000338d8;
    }
    if (0xf < DAT_00067683) {
      DAT_00067683 = 0xf;
    }
    if (0x1f < DAT_00067684) {
      DAT_00067684 = 0xf;
    }
    if (0x1f < DAT_00067685) {
      DAT_00067685 = 0xf;
    }
    if (0x1f < DAT_00067686) {
      DAT_00067686 = 0xf;
    }
    if (0x1f < DAT_00067687) {
      DAT_00067687 = 0xf;
    }
    if ((DAT_00067fa8 < -0x2d0) || (0x2d0 < DAT_00067fa8)) {
      memset(&DAT_00067fa8,0,0xac);
    }
    DAT_00067fa4 = DAT_00067fa4 != '\0';
    if (DAT_00067fa6 != '\x01') {
      DAT_00067fa6 = '\0';
    }
    if (DAT_00067fa5 != '\x01') {
      DAT_00067fa5 = '\0';
    }
    uVar6 = 0;
    do {
      if (2 < (byte)(&DAT_00067680)[uVar6]) {
        (&DAT_00067680)[uVar6] = 2;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 3);
    if (bVar9 == false) goto LAB_00033af8;
  }
  FUN_00031fa8();
LAB_00033af8:
  uVar6 = 0;
  do {
    pbVar3 = &DAT_00067674 + uVar6;
    uVar5 = uVar6 & 3;
    uVar6 = uVar6 + 1;
    uVar11 = (uint)*pbVar3 * (uVar5 + 1) + uVar11;
  } while (uVar6 < 0x9f8);
  DAT_00068079 = (undefined1)uVar11;
  iVar10 = 0x9fc;
  do {
    iVar10 = iVar10 + -1;
    uVar8 = *(uint *)(local_a38 + ((*pbVar7 ^ uVar8) & 0xff) * 4) ^ uVar8 >> 8;
    pbVar7 = pbVar7 + 1;
  } while (iVar10 != 0);
  DAT_0006807c = ~uVar8;
  NKDbgPrintfW(L"[!!OKOK!!] %s : [%d] Checksum value [0x%02X, 0x%08X], Bias %d\n",
               "LoadGlobalDataFile",bVar9,uVar11 & 0xff,DAT_0006807c,DAT_00067fa8);
  FUN_0004a3f4(local_30);
  return;
}



/* 00033bd4 FUN_00033bd4 */

/* Boundary evidence: original MIPS .pdata 00033bd4..00033db3. Semantic name remains unreviewed. */

undefined4 FUN_00033bd4(void)

{
  int iVar1;
  uint uVar2;
  HWND pHVar3;
  int iVar4;
  DWORD DVar5;
  undefined4 local_40 [2];
  undefined4 local_38;
  uint local_34;
  undefined *local_30;
  
  local_40[0] = 0;
  local_38 = 0;
  memset(&local_34,0,8);
  DAT_00064038 = 0;
  do {
    WaitForSingleObject(DAT_00068468,0xffffffff);
    uVar2 = GetEventData(DAT_00068468);
    if (uVar2 != 0) {
      iVar1 = (uVar2 >> 0x10) * 0x31;
      local_34 = uVar2 & 0xffff;
      local_38 = 0x7ef;
      local_30 = &DAT_0006808f + iVar1;
      pHVar3 = FindWindowW(L"NAVI",(LPCWSTR)0x0);
      if (pHVar3 == (HWND)0x0) {
        NKDbgPrintfW(L"[[[ TMC THREAD ]]]]   IDM_MMCM_NNG_TMC_RECEIVED  hWnd Error  \r\n");
      }
      else {
        iVar4 = SendMessageTimeout(pHVar3,0x4a,DAT_00068470,&local_38,0,0x5dc,local_40);
        if (iVar4 == 0) {
          DVar5 = GetLastError();
          NKDbgPrintfW(L"[[[ TMC THREAD ]]]]   WM_COPYDATA  Error [0x%08X] \r\n",DVar5);
          iVar4 = SendMessageTimeout(pHVar3,0x4a,DAT_00068470,&local_38,0,0x5dc,local_40);
          if (iVar4 == 0) {
            DVar5 = GetLastError();
            NKDbgPrintfW(L"[[[ TMC THREAD ]]]] Opss!!!  WM_COPYDATA  Error [0x%08X] \r\n",DVar5);
          }
        }
      }
      (&DAT_0006808e)[iVar1] = 0;
    }
  } while (DAT_00064038 == 0);
  return 0;
}



/* 00033db4 FUN_00033db4 */

/* Boundary evidence: original MIPS .pdata 00033db4..00033e57. Semantic name remains unreviewed. */

undefined4 *
FUN_00033db4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00030010(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_0005b104;
  param_1[4] = param_4;
  param_1[3] = 0;
  DAT_00064038 = 1;
  DAT_00068462 = 0;
  memset(&DAT_00068088,0,0x3da);
  param_1[5] = 0;
  DAT_00068468 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"Received TMC Data");
  return param_1;
}



/* 00033e58 FUN_00033e58 */

/* Boundary evidence: original MIPS .pdata 00033e58..00033f0f. Semantic name remains unreviewed. */

void FUN_00033e58(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0005b104;
  if (param_1[5] != 0) {
    DAT_00064038 = 1;
    SetEventData(DAT_00068468,0);
    EventModify(DAT_00068468,3);
    Sleep(100);
    CloseHandle((HANDLE)param_1[5]);
    param_1[5] = 0;
  }
  if (DAT_00068468 != 0) {
    CloseHandle((HANDLE)DAT_00068468);
    DAT_00068468 = 0;
  }
  FUN_0003008c(param_1);
  return;
}



/* 00033f10 FUN_00033f10 */

/* Boundary evidence: original MIPS .pdata 00033f10..00033ffb. Semantic name remains unreviewed. */

void FUN_00033f10(int param_1,int param_2)

{
  if ((param_2 != 0x90) && (param_2 == 0x91)) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    FUN_00015158(DAT_000648e4,0xb,1,0x71,0,0,0x32);
    if (*(int *)(param_1 + 0x14) != 0) {
      DAT_00064038 = 1;
      SetEventData(DAT_00068468,0);
      EventModify(DAT_00068468,3);
      Sleep(100);
      CloseHandle(*(HANDLE *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    DAT_00068462 = 0;
    memset(&DAT_00068088,0,0x3da);
    NKDbgPrintfW(L"[[[ TMC ]]]]   IDM_X_MMCM_TMC_OFF\r\n");
  }
  return;
}



/* 00033ffc FUN_00033ffc */

/* Boundary evidence: original MIPS .pdata 00033ffc..000342eb. Semantic name remains unreviewed. */

void FUN_00033ffc(int param_1,int param_2,uint param_3)

{
  HANDLE hThread;
  wchar_t *pwVar1;
  uint uVar2;
  uint uVar3;
  uint local_18 [2];
  
  if (param_2 == 0xbcc) {
    DAT_00068462 = 0;
    memset(&DAT_00068088,0,0x3da);
    *(undefined4 *)(param_1 + 0xc) = 1;
    hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00033bd4,(LPVOID)0x0,4,(LPDWORD)0x0);
    *(HANDLE *)(param_1 + 0x14) = hThread;
    if (hThread != (HANDLE)0x0) {
      SetThreadPriority(hThread,2);
      ResumeThread(*(HANDLE *)(param_1 + 0x14));
    }
    FUN_00015158(DAT_000648e4,0xb,1,0x70,0,0,0x32);
  }
  else if (param_2 == 0xbcd) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    FUN_00015158(DAT_000648e4,0xb,1,0x71,0,0,0x32);
    if (*(int *)(param_1 + 0x14) != 0) {
      DAT_00064038 = 1;
      SetEventData(DAT_00068468,0);
      EventModify(DAT_00068468,3);
      Sleep(100);
      CloseHandle(*(HANDLE *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    DAT_00068462 = 0;
    memset(&DAT_00068088,0,0x3da);
  }
  else {
    if (param_2 == 0xbce) {
      if (*(int *)(param_1 + 0xc) != 0) {
        uVar2 = param_3 & 0xffff;
        if ((0x36a < uVar2) && (uVar2 < 0x439)) {
          local_18[0]._0_2_ = (undefined2)param_3;
          FUN_00015158(DAT_000648e4,0xb,1,0x72,(int)local_18,2,0x32);
          return;
        }
        NKDbgPrintfW(L"[ERROR Out of range] [ NNG-TMC ]   IDM_NNG_TMC_SET_FREQ --- Freq(%d)\r\n",
                     uVar2);
        return;
      }
      uVar2 = 0;
      pwVar1 = L"[[[ NNG-TMC ]]]   Error.... IDM_NNG_TMC_SET_FREQ... m_bEnableTMC[%d] (%d)\r\n";
    }
    else {
      if (param_2 != 0xbcf) {
        return;
      }
      if (*(int *)(param_1 + 0xc) == 0) {
        NKDbgPrintfW(L"[[[ NNG-TMC ]]]   Error.... IDM_NNG_TMC_SCANING_FREQ... m_bEnableTMC[%d] Freq(%d, %d)\r\n"
                     ,0,param_3 >> 0x10,param_3 & 0xffff);
        return;
      }
      uVar3 = param_3 & 0xffff;
      if ((0x36a < uVar3) && (uVar3 < 0x439)) {
        local_18[0] = param_3;
        FUN_00015158(DAT_000648e4,0xb,1,0x73,(int)local_18,3,0x32);
        return;
      }
      uVar2 = param_3 >> 0x10;
      pwVar1 = L"[ERROR Out of range] [ NNG-TMC ]   IDM_NNG_TMC_SCANING_FREQ --- Freq(%d, %d)\r\n";
      param_3 = uVar3;
    }
    NKDbgPrintfW(pwVar1,uVar2,param_3);
  }
  return;
}



/* 000342ec FUN_000342ec */

/* Boundary evidence: original MIPS .pdata 000342ec..0003467f. Semantic name remains unreviewed. */

void FUN_000342ec(undefined4 param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  HWND hWnd;
  wchar_t *pwVar3;
  WPARAM wParam;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  byte *pbVar7;
  
  hWnd = FindWindowW(L"NAVI",(LPCWSTR)0x0);
  if ((*param_2 & 0xf00) != 0x200) {
    return;
  }
  cVar1 = *(char *)((int)param_2 + 2);
  if (cVar1 == 'p') {
    uVar4 = (uint)(byte)param_2[1];
    if (uVar4 == 4) {
      if (hWnd != (HWND)0x0) {
        uVar4 = 4;
        wParam = 0x7ee;
        goto LAB_00034648;
      }
      pwVar3 = L"[[[ TMC ]]]]   NOTI_TMC_STATUS  hWnd Error %d \r\n";
    }
    else if (uVar4 < 4) {
      if (hWnd != (HWND)0x0) {
        wParam = 0x7ed;
        goto LAB_00034648;
      }
      pwVar3 = L"[[[ TMC ]]]]   NOTI_TMC_STATUS  hWnd Error %d \r\n";
    }
    else {
      pwVar3 = 
      L"[ERROR] [[[ NOTI_TMC_STATUS ]]]]   Unknown NOTI_TMC_STATUS !!!!!  (status[ %d ])  \r\n";
    }
  }
  else {
    if (cVar1 != 'q') {
      if (cVar1 == 'r') {
        if (*(char *)((int)param_2 + 3) != '\x04') {
          NKDbgPrintfW(L"[[[ TMC ]]]]   NOTI_TMC_FREQ_CHANGED  Length error[%d][%d,%d,%d,%d]\r\n",
                       *(char *)((int)param_2 + 3),(char)param_2[1],
                       *(undefined1 *)((int)param_2 + 5),*(undefined1 *)((int)param_2 + 6),
                       *(undefined1 *)((int)param_2 + 7));
          return;
        }
        DAT_00068088 = (undefined2)param_2[1];
        uVar5 = (ushort)*(byte *)((int)param_2 + 6);
        DAT_0006808c = (ushort)*(byte *)((int)param_2 + 6);
        if ((uVar5 == 0) || (uVar5 == 0xff)) {
          uVar5 = 0x66;
          DAT_0006808c = 0x66;
        }
        if (hWnd == (HWND)0x0) {
          pwVar3 = L"[[[ TMC ]]]]   NOTI_TMC_FREQ_CHANGED  hWnd Error  \r\n";
          goto LAB_000343e0;
        }
        wParam = 0x7f0;
      }
      else {
        if (cVar1 != 's') {
          return;
        }
        if (*(char *)((int)param_2 + 3) != '\x04') {
          NKDbgPrintfW(L"[[[ TMC ]]]]   NOTI_TMC_PI_CHANGED  Length errorLength error[%d][%d,%d,%d,%d]\r\n"
                       ,*(char *)((int)param_2 + 3),(char)param_2[1],
                       *(undefined1 *)((int)param_2 + 5),*(undefined1 *)((int)param_2 + 6),
                       *(undefined1 *)((int)param_2 + 7));
          return;
        }
        DAT_00068088 = (undefined2)param_2[1];
        DAT_0006808a = *(ushort *)((int)param_2 + 6);
        if (hWnd == (HWND)0x0) {
          pwVar3 = L"[[[ TMC ]]]]   NOTI_TMC_PI_CHANGED  hWnd Error  \r\n";
LAB_000343e0:
          NKDbgPrintfW(pwVar3);
          return;
        }
        wParam = 0x7f1;
        uVar5 = DAT_0006808a;
      }
      uVar4 = CONCAT22(uVar5,DAT_00068088);
LAB_00034648:
      PostMessageW(hWnd,DAT_00068470,wParam,uVar4);
      return;
    }
    if (*(char *)((int)param_2 + 3) != '\0') {
      uVar4 = (uint)DAT_00068462;
      uVar6 = 0;
      if (*(char *)((int)param_2 + 3) != '\0') {
        iVar2 = uVar4 * 0x31;
        pbVar7 = &DAT_0006808e + iVar2;
        do {
          if (uVar6 % 2 == 0) {
            (&DAT_0006808f)[(uint)*pbVar7 + iVar2] = *(undefined1 *)((int)param_2 + uVar6 + 5);
          }
          else {
            (&DAT_0006808f)[(uint)*pbVar7 + iVar2] = *(undefined1 *)((int)param_2 + uVar6 + 3);
          }
          *pbVar7 = *pbVar7 + 1;
          uVar6 = uVar6 + 1 & 0xff;
        } while (uVar6 < *(byte *)((int)param_2 + 3));
      }
      if ((byte)(&DAT_0006808e)[uVar4 * 0x31] < 0x30) {
        return;
      }
      SetEventData(DAT_00068468,uVar4 << 0x10 | (uint)(byte)(&DAT_0006808e)[uVar4 * 0x31]);
      EventModify(DAT_00068468,3);
      if ((byte)(DAT_00068462 + 1) < 0x14) {
        DAT_00068462 = DAT_00068462 + 1;
        return;
      }
      DAT_00068462 = 0;
      return;
    }
    uVar4 = 0;
    pwVar3 = L"[[[ TMC ]]]]   NOTI_TMC_INFO  Length error[%d]\r\n";
  }
  NKDbgPrintfW(pwVar3,uVar4);
  return;
}



/* 00034680 FUN_00034680 */

undefined2 FUN_00034680(void)

{
  return DAT_00068088;
}



/* 0003468c FUN_0003468c */

undefined2 FUN_0003468c(void)

{
  return DAT_0006808a;
}



/* 0003469c FUN_0003469c */

undefined4 FUN_0003469c(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* 000346a4 FUN_000346a4 */

undefined4 FUN_000346a4(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return param_2;
}



/* 000346b0 FUN_000346b0 */

/* Boundary evidence: original MIPS .pdata 000346b0..000346fb. Semantic name remains unreviewed. */

undefined4 * FUN_000346b0(undefined4 *param_1,uint param_2)

{
  FUN_00033e58(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000346fc FUN_000346fc */

/* Boundary evidence: original MIPS .pdata 000346fc..00034807. Semantic name remains unreviewed. */

void FUN_000346fc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char acStack_119 [261];
  uint local_14;
  
  local_14 = DAT_00064820;
  acStack_119[1] = 0;
  memset(acStack_119 + 2,0,0x103);
  iVar1 = 0;
  while (param_1 != 0) {
    if (param_2 == 0) {
      trap(0x1c00);
    }
    if ((param_2 == -1) && (param_1 == -0x80000000)) {
      trap(0x1800);
    }
    acStack_119[iVar1 + 1] = (char)(param_1 % param_2) + '0';
    if (param_2 == 0) {
      trap(0x1c00);
    }
    if ((param_2 == -1) && (param_1 == -0x80000000)) {
      trap(0x1800);
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 / param_2;
  }
  iVar2 = 0;
  while (-1 < iVar1 + -1) {
    *(char *)(param_3 + iVar2) = acStack_119[iVar1];
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + -1;
  }
  *(undefined1 *)(param_3 + iVar2) = 0;
  FUN_0004a3f4(local_14);
  return;
}



/* 00034808 FUN_00034808 */

/* Boundary evidence: original MIPS .pdata 00034808..000348db. Semantic name remains unreviewed. */

undefined4 FUN_00034808(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  HKEY local_28;
  undefined4 local_24;
  DWORD local_20 [4];
  
  local_20[1] = 4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_28,local_20 + 2);
  if (LVar1 == 0) {
    local_20[0] = 4;
    LVar1 = RegQueryValueExW(local_28,param_3,(LPDWORD)0x0,local_20 + 1,(LPBYTE)&local_24,local_20);
    if (LVar1 != 0) {
      local_24 = param_4;
    }
    RegCloseKey(local_28);
  }
  else {
    local_24 = 0;
  }
  return local_24;
}



/* 000348dc FUN_000348dc */

/* Boundary evidence: original MIPS .pdata 000348dc..000349d7. Semantic name remains unreviewed. */

bool FUN_000348dc(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,wchar_t *param_4,wchar_t *param_5,
                 DWORD param_6)

{
  LSTATUS LVar1;
  bool bVar2;
  DWORD local_28;
  HKEY local_24;
  DWORD local_20;
  DWORD DStack_1c;
  
  local_20 = 1;
  bVar2 = false;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_24,&DStack_1c);
  if (LVar1 == 0) {
    local_28 = param_6;
    LVar1 = RegQueryValueExW(local_24,param_3,(LPDWORD)0x0,&local_20,(LPBYTE)param_5,&local_28);
    if (LVar1 != 0) {
      wcsncpy(param_5,param_4,local_28 - 1);
    }
    bVar2 = LVar1 == 0;
    RegCloseKey(local_24);
  }
  return bVar2;
}



/* 000349d8 FUN_000349d8 */

/* Boundary evidence: original MIPS .pdata 000349d8..00034aa7. Semantic name remains unreviewed. */

bool FUN_000349d8(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,LPBYTE param_4,DWORD param_5)

{
  LSTATUS LVar1;
  bool bVar2;
  HKEY local_20;
  DWORD local_1c [3];
  
  local_1c[1] = 3;
  bVar2 = false;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_20,local_1c + 2);
  if (LVar1 == 0) {
    local_1c[0] = param_5;
    LVar1 = RegQueryValueExW(local_20,param_3,(LPDWORD)0x0,local_1c + 1,param_4,local_1c);
    bVar2 = LVar1 == 0;
    RegCloseKey(local_20);
  }
  return bVar2;
}



/* 00034aa8 FUN_00034aa8 */

/* Boundary evidence: original MIPS .pdata 00034aa8..00034b67. Semantic name remains unreviewed. */

bool FUN_00034aa8(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,BYTE *param_4,DWORD param_5)

{
  LSTATUS LVar1;
  bool bVar2;
  HKEY local_18;
  DWORD DStack_14;
  
  bVar2 = false;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20006,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_18,&DStack_14);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_18,param_3,0,3,param_4,param_5);
    bVar2 = LVar1 == 0;
    RegCloseKey(local_18);
  }
  return bVar2;
}



/* 00034b68 FUN_00034b68 */

/* Boundary evidence: original MIPS .pdata 00034b68..00034c23. Semantic name remains unreviewed. */

bool FUN_00034b68(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  bool bVar2;
  undefined4 local_resc;
  HKEY local_18;
  DWORD DStack_14;
  
  bVar2 = false;
  local_resc = param_4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20006,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_18,&DStack_14);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_18,param_3,0,4,(BYTE *)&local_resc,4);
    bVar2 = LVar1 == 0;
    RegCloseKey(local_18);
  }
  return bVar2;
}



/* 00034c24 FUN_00034c24 */

/* Boundary evidence: original MIPS .pdata 00034c24..00034cef. Semantic name remains unreviewed. */

bool FUN_00034c24(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,wchar_t *param_4)

{
  LSTATUS LVar1;
  size_t sVar2;
  bool bVar3;
  HKEY local_18;
  DWORD DStack_14;
  
  bVar3 = false;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20006,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_18,&DStack_14);
  if (LVar1 == 0) {
    sVar2 = wcslen(param_4);
    LVar1 = RegSetValueExW(local_18,param_3,0,1,(BYTE *)param_4,(sVar2 + 1) * 2);
    bVar3 = LVar1 == 0;
    RegCloseKey(local_18);
  }
  return bVar3;
}



/* 00034cf0 FUN_00034cf0 */

/* Boundary evidence: original MIPS .pdata 00034cf0..00035f87. Semantic name remains unreviewed. */

void FUN_00034cf0(int param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  char cVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  size_t sVar5;
  LSTATUS LVar6;
  DWORD DVar7;
  HWND pHVar8;
  wchar_t *pwVar9;
  UINT Msg;
  LPARAM LVar10;
  char *pcVar11;
  undefined4 uVar12;
  int iVar13;
  undefined *puVar14;
  uint uVar15;
  byte bVar16;
  byte bVar17;
  uint uVar18;
  WPARAM WVar19;
  undefined2 uVar20;
  byte local_478 [4];
  HKEY local_474;
  uint local_470;
  byte local_46c;
  undefined2 local_46a;
  uint local_468 [2];
  undefined4 local_460;
  undefined4 local_45c;
  int local_458;
  undefined1 auStack_454 [4];
  byte local_450;
  char local_44f;
  byte local_44e;
  undefined4 local_44d;
  undefined4 local_449;
  char acStack_348 [16];
  uint local_338;
  undefined4 local_334;
  wchar_t awStack_230 [10];
  undefined2 local_21c;
  undefined2 local_21a;
  uint local_28;
  
  local_28 = DAT_00064820;
  uVar18 = 0;
  memset(&local_450,0,0x104);
  memset(awStack_230,0,0x208);
  memset(&local_338,0,0x104);
  bVar16 = *param_2;
  bVar17 = 1;
  switch(bVar16) {
  case 2:
    bVar16 = param_2[2];
    if (bVar16 == 0) {
      iVar13 = FUN_00016710(DAT_000648ec,0);
    }
    else {
      if (bVar16 == 1) {
        FUN_00016710(DAT_000648ec,1);
        break;
      }
      if (bVar16 != 2) {
        if (bVar16 != 3) break;
        iVar13 = FUN_00016840(DAT_000648ec,1,param_2[3]);
        local_450 = *param_2;
        local_44e = param_2[2];
        local_44d._0_2_ = CONCAT11(iVar13 != 0,param_2[3]);
        goto LAB_00034e70;
      }
      iVar13 = FUN_00016840(DAT_000648ec,0,0);
    }
    local_44f = '\x02';
    local_44e = param_2[2];
    local_450 = *param_2 | 0x80;
    if (iVar13 == 0) {
      bVar17 = 0;
    }
    goto LAB_00034ee0;
  case 6:
    bVar16 = param_2[2];
    if (bVar16 == 0) {
      iVar13 = (uint)param_2[4] * 0x100 + (uint)param_2[3];
      if (*(char *)(*(int *)(param_1 + 0xc) + 4) == '\0') {
        iVar13 = iVar13 * 10;
      }
      (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x6f,iVar13);
      bVar16 = param_2[2];
      goto LAB_00035060;
    }
    if (bVar16 == 1) {
      if (*(char *)(*(int *)(param_1 + 0xc) + 4) == '\0') {
        uVar18 = FUN_00029158((int)DAT_000673c8);
        uVar20 = (undefined2)(uVar18 / 10);
      }
      else {
        uVar12 = FUN_00029158((int)DAT_000673c8);
        uVar20 = (undefined2)uVar12;
      }
      local_450 = *param_2;
      local_44e = param_2[2];
      local_44d = CONCAT22(local_44d._2_2_,uVar20);
LAB_00034e70:
      local_450 = local_450 | 0x80;
      local_44f = '\x03';
      uVar18 = 5;
      break;
    }
    if (bVar16 == 2) {
      uVar12 = 0;
    }
    else {
      if (bVar16 != 3) {
        if (bVar16 == 4) {
          uVar12 = 0;
        }
        else {
          if (bVar16 != 5) break;
          uVar12 = 1;
        }
        (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x6a,uVar12);
LAB_00034f5c:
        local_44f = '\x02';
        local_44e = param_2[2];
        local_450 = *param_2 | 0x80;
        uVar18 = 4;
        local_44d = CONCAT31(local_44d._1_3_,1);
        break;
      }
      uVar12 = 1;
    }
    (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x6b,uVar12);
    goto LAB_00035168;
  case 7:
    bVar1 = param_2[2];
    if (bVar1 == 0) {
      uVar12 = 0;
    }
    else {
      if (bVar1 != 1) {
        if (bVar1 < 2) break;
        if (3 < bVar1) {
          if (bVar1 == 4) {
            uVar12 = 0;
          }
          else {
            if (bVar1 != 5) {
              if (bVar1 != 6) break;
              local_450 = bVar16 | 0x80;
              local_44f = '\t';
              local_44e = bVar1;
              FUN_00029168((int)DAT_000673c8,&local_44d);
              goto LAB_000350ec;
            }
            uVar12 = 1;
          }
          (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x82,uVar12);
          goto LAB_00034f5c;
        }
        local_450 = bVar16 | 0x80;
        local_44e = bVar1;
        goto LAB_00035350;
      }
      uVar12 = 1;
    }
    (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x81,uVar12);
    goto LAB_00035168;
  case 8:
    LVar10 = 0x280000;
    goto LAB_00035184;
  case 9:
    if (0xb < param_2[2]) break;
    LVar10 = (uint)param_2[2] << 0x10;
    goto LAB_00035184;
  case 0xb:
    if (7 < param_2[2]) break;
    LVar10 = (param_2[2] + 0x14) * 0x10000;
    goto LAB_00035184;
  case 0xc:
    uVar15 = (uint)param_2[2];
    if (uVar15 == 0) {
      bVar2 = FUN_000349d8((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",L"BTAddress",(LPBYTE)&local_338
                           ,6);
      if (CONCAT31(extraout_var,bVar2) != 0) {
        local_450 = *param_2 | 0x80;
        local_44f = '\a';
        local_44e = param_2[2];
        uVar18 = 9;
        local_44d = local_338;
        local_449._0_2_ = (undefined2)local_334;
        break;
      }
      bVar2 = FUN_000349d8((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",L"BTAddress",(LPBYTE)&local_338
                           ,8);
      if (CONCAT31(extraout_var_00,bVar2) != 0) {
        local_450 = *param_2 | 0x80;
        local_44d = local_338;
        local_449 = local_334;
        local_44f = '\t';
        local_44e = param_2[2];
LAB_000350ec:
        uVar18 = 0xb;
        break;
      }
      local_450 = *param_2 | 0x80;
      goto LAB_00035340;
    }
    if (uVar15 == 0) break;
    if (6 < uVar15) {
      if (uVar15 != 7) break;
      FUN_00036ea0(0x70,0x1030101,0);
      goto LAB_00035168;
    }
    LVar10 = (uVar15 + 0x1e) * 0x10000;
    goto LAB_00035184;
  case 0xd:
    bVar16 = param_2[2];
    if (bVar16 == 0) {
      FUN_00013014(DAT_00064828,3);
    }
    else {
      if (bVar16 != 1) {
        if (bVar16 != 2) break;
        iVar13 = *(int *)(DAT_00064828 + 0x44);
        FUN_000110ec(DAT_00064828,(uint)param_2[3]);
        if (iVar13 != 0) {
          FUN_00036de8(0x75,*(LPARAM *)(DAT_00064828 + 0x44));
        }
        local_44e = param_2[2];
        local_450 = *param_2 | 0x80;
        local_44f = '\x02';
        uVar3 = FUN_000111e4();
        local_44d = CONCAT31(local_44d._1_3_,uVar3);
        goto LAB_00034ee4;
      }
      FUN_00013014(DAT_00064828,2);
    }
LAB_00035168:
    local_44f = '\x02';
    local_44e = param_2[2];
    local_450 = *param_2 | 0x80;
    goto LAB_00034ee0;
  case 0xe:
    switch(param_2[2]) {
    case 1:
      local_450 = bVar16 | 0x80;
      bVar2 = FUN_000348dc((HKEY)0x80000002,L"LGE\\SystemInfo",L"VerMicomFW",L"no info",awStack_230,
                           0x103);
      iVar13 = CONCAT31(extraout_var_01,bVar2);
      break;
    case 2:
      local_450 = bVar16 | 0x80;
      bVar2 = FUN_000348dc((HKEY)0x80000002,L"LGE\\SystemInfo",L"VerAppmain",L"no info",awStack_230,
                           0x103);
      iVar13 = CONCAT31(extraout_var_02,bVar2);
      break;
    case 3:
      local_450 = bVar16 | 0x80;
      bVar2 = FUN_000348dc((HKEY)0x80000002,L"LGE\\SystemInfo",L"NaviVersion",L"no info",awStack_230
                           ,0x103);
      iVar13 = CONCAT31(extraout_var_03,bVar2);
      break;
    case 4:
      local_450 = bVar16 | 0x80;
      bVar2 = FUN_000348dc((HKEY)0x80000002,L"LGE\\SystemInfo",L"OSVersion2",L"no info",awStack_230,
                           0x103);
      if (CONCAT31(extraout_var_04,bVar2) == 0) goto LAB_00035340;
      local_21c = 0x2e;
      local_21a = 0x30;
      NKDbgPrintfW(L"\r\n %s\n",awStack_230);
      goto LAB_00035484;
    case 5:
      iVar13 = FUN_00034808((HKEY)0x80000002,L"LGE\\SystemInfo",L"Bootversion",0);
      local_44e = param_2[2];
      local_450 = *param_2 | 0x80;
      memset(acStack_348,0,0x10);
      FUN_000346fc(iVar13,10,(int)acStack_348);
      sVar5 = strlen(acStack_348);
      if (0x10 < (int)sVar5) {
        sVar5 = 0x10;
      }
      memcpy(&local_44d,acStack_348,sVar5);
      local_44f = (char)sVar5 + '\x01';
      uVar18 = sVar5 + 3 & 0xff;
      goto switchD_00034d8c_caseD_3;
    case 6:
      local_450 = bVar16 | 0x80;
      bVar2 = FUN_000348dc((HKEY)0x80000002,L"LGE\\SystemInfo",L"VerBlue",L"no info",awStack_230,
                           0x103);
      iVar13 = CONCAT31(extraout_var_05,bVar2);
      break;
    case 7:
      local_450 = bVar16 | 0x80;
      bVar2 = FUN_000348dc((HKEY)0x80000002,L"LGE\\SystemInfo",L"DAB Mgr Version",L"no info",
                           awStack_230,0x103);
      iVar13 = CONCAT31(extraout_var_06,bVar2);
      break;
    case 8:
      local_450 = bVar16 | 0x80;
      bVar2 = FUN_000348dc((HKEY)0x80000002,L"LGE\\SystemInfo",L"DAB FW Version",L"no info",
                           awStack_230,0x103);
      if (CONCAT31(extraout_var_07,bVar2) != 0) {
        sVar5 = FUN_00025840(awStack_230,(LPSTR)&local_338);
        if (0xff < sVar5) {
          sVar5 = 0xff;
        }
        local_44e = param_2[2];
        local_44f = (char)sVar5 + '\x01';
        memcpy(&local_44d,&local_338,sVar5);
        uVar18 = sVar5 + 3 & 0xff;
        KillTimer(*(HWND *)(param_1 + 4),0x70f);
        goto switchD_00034d8c_caseD_3;
      }
      pHVar8 = FindWindowW(L"MgrDab",L"MgrDab");
      if (pHVar8 != (HWND)0x0) {
        uVar18 = 0;
        if ((DAT_000684bc == 0) || (DVar7 = GetTickCount(), 0x30d4 < DVar7 - DAT_000684bc)) {
          PostMessageW(pHVar8,0x10,0,0);
          SetTimer(*(HWND *)(param_1 + 4),0x70f,500,(TIMERPROC)0x0);
          DAT_000684bc = GetTickCount();
        }
        goto switchD_00034d8c_caseD_3;
      }
      goto LAB_00035340;
    default:
      goto switchD_00034d8c_caseD_3;
    }
    if (iVar13 != 0) {
LAB_00035484:
      sVar5 = FUN_00025840(awStack_230,(LPSTR)&local_338);
      if (0xff < sVar5) {
        sVar5 = 0xff;
      }
      local_44e = param_2[2];
      local_44f = (char)sVar5 + '\x01';
      memcpy(&local_44d,&local_338,sVar5);
      uVar18 = sVar5 + 3 & 0xff;
      break;
    }
LAB_00035340:
    local_44e = param_2[2];
    goto LAB_00035350;
  case 0x11:
    if (param_2[2] == 0) {
      if (DAT_00064828 != 0) {
        iVar13 = 0;
        goto LAB_00035854;
      }
    }
    else if ((param_2[2] == 1) && (DAT_00064828 != 0)) {
      iVar13 = 1;
LAB_00035854:
      FUN_00011904(DAT_00064828,0,iVar13);
    }
    bVar16 = param_2[2];
    if ((bVar16 != 0) && (bVar16 != 1)) break;
LAB_00035060:
    local_44f = '\x02';
    local_450 = *param_2 | 0x80;
    local_44e = bVar16;
    goto LAB_00034ee0;
  case 0x13:
    if (param_2[2] == 0) {
      pHVar8 = FindWindowW(L"TESTWND",(LPCWSTR)0x0);
      local_44e = param_2[2];
      local_450 = *param_2 | 0x80;
      if (pHVar8 != (HWND)0x0) {
        WVar19 = 0x13;
LAB_00035904:
        local_44f = '\x02';
        uVar18 = 0;
        Msg = 0x111;
LAB_00035ad8:
        PostMessageW(pHVar8,Msg,WVar19,uVar18);
        goto LAB_00034ee0;
      }
    }
    else {
      if (param_2[2] != 1) break;
      pHVar8 = FindWindowW(L"TESTWND",(LPCWSTR)0x0);
      local_44e = param_2[2];
      local_450 = *param_2 | 0x80;
      if (pHVar8 != (HWND)0x0) {
        WVar19 = 0x14;
        goto LAB_00035904;
      }
    }
    goto LAB_00035350;
  case 0x14:
    *(undefined4 *)(DAT_00064a24 + 0x44) = 1;
    local_450 = *param_2 | 0x80;
    local_44e = bVar17;
    goto LAB_00035934;
  case 0x17:
    local_44f = '\x02';
    local_44e = param_2[2];
    local_450 = bVar16 | 0x80;
    if (5 < local_44e) goto LAB_00035350;
    FUN_00011264(DAT_00064828,(uint)local_44e);
LAB_00034ee0:
    local_44d = CONCAT31(local_44d._1_3_,bVar17);
LAB_00034ee4:
    uVar18 = 4;
    break;
  case 0x20:
    LVar10 = 0x320000;
LAB_00035184:
    FUN_00036de8(0x7b,LVar10);
    break;
  case 0x27:
    local_44f = '\x02';
    local_44e = param_2[2];
    local_450 = bVar16 | 0x80;
    uVar15 = (uint)param_2[2];
    if (local_44e < 0x17) {
      uVar18 = 4;
      local_44d = CONCAT31(local_44d._1_3_,1);
      local_468[0] = uVar15;
      LVar6 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_474);
      if (LVar6 == 0) {
        RegSetValueExW(local_474,L"GUIDELINE_TYPE",0,4,(BYTE *)local_468,4);
        RegCloseKey(local_474);
      }
      break;
    }
    if ((uVar15 == 0xfe) || (uVar15 == 0xff)) {
      pHVar8 = FindWindowW(L"RVC WND",L"RVC WND");
      if (param_2[2] == 0xfe) {
        puVar14 = &DAT_0005c614;
      }
      else {
        puVar14 = &DAT_0005c60c;
      }
      NKDbgPrintfW(L"[INFO] [0x%08X]rvc guideline on/off [%s]\n",pHVar8,puVar14);
      DVar7 = GetLastError();
      NKDbgPrintfW(L"[INFO] [0x%08X][0x%08X]rvc guideline on/off [0x%08X]\n",pHVar8,DAT_0006850c,
                   DVar7);
      uVar18 = (uint)param_2[2];
      WVar19 = 0;
      Msg = DAT_0006850c;
      if (pHVar8 == (HWND)0x0) {
        pHVar8 = (HWND)0xffff;
      }
      goto LAB_00035ad8;
    }
LAB_00035350:
    local_44f = '\x02';
    local_44d = local_44d & 0xffffff00;
    goto LAB_00034ee4;
  case 0x28:
    local_44f = '\x02';
    local_44e = param_2[2];
    local_450 = bVar16 | 0x80;
    if ((local_44e < 10) || (param_2[2] == 0xf)) {
      cVar4 = FUN_000326f0(param_2[2]);
      uVar18 = 4;
      local_44d = CONCAT31(local_44d._1_3_,cVar4);
      FUN_0001d598();
      break;
    }
    local_44d = CONCAT31(local_44d._1_3_,0xff);
    goto LAB_00034ee4;
  case 0x2a:
    memset(&local_470,0,8);
    local_470 = (uint)CONCAT21(CONCAT11(param_2[2],param_2[3]),param_2[4]);
    local_46a = CONCAT11(param_2[6],param_2[7]);
    local_46c = param_2[5];
    FUN_00034aa8((HKEY)0x80000002,L"LGE\\SystemStatus\\BTDirect",L"DirectAddress",(BYTE *)&local_470
                 ,8);
    FUN_00036f08(0x3030109,0);
    DAT_000684b8 = 1;
    break;
  case 0x2b:
    NKDbgPrintfW(L"\r\n Get Mute  0x%08X : ",DAT_00064828);
    if (DAT_00064828 == 0) break;
    NKDbgPrintfW(L"GetIsMute() -> %d\r\n",*(undefined4 *)(DAT_00064828 + 0x44));
    local_450 = *param_2 | 0x80;
    local_44e = bVar17;
    if (*(int *)(DAT_00064828 + 0x44) != 1) {
      local_44e = 0;
    }
    goto LAB_00035934;
  case 0x2e:
    bVar16 = 0;
    DVar7 = GetFileAttributesW(L"\\Storage Card4\\NNG\\content\\map\\France.fbl");
    if (DVar7 == 0xffffffff) {
      DVar7 = GetFileAttributesW(L"\\Storage Card4\\NNG\\content\\map\\India.fbl");
      if (DVar7 == 0xffffffff) {
        DVar7 = GetFileAttributesW(L"\\Storage Card4\\NNG\\content\\map\\Brazil.fbl");
        if (DVar7 != 0xffffffff) {
          bVar16 = 3;
        }
      }
      else {
        bVar16 = 2;
      }
    }
    else {
      bVar16 = 1;
    }
    NKDbgPrintfW(L"\r\n Check Map package ....%d\r\n",bVar16);
    local_450 = *param_2 | 0x80;
    uVar18 = 3;
    local_44f = '\x01';
    local_44e = bVar16;
    break;
  case 0x31:
    local_478[0] = param_2[2];
    if (100 < local_478[0]) break;
    FUN_00015158(DAT_000648e4,7,1,2,(int)local_478,1,100);
    local_450 = *param_2 | 0x80;
    local_44e = param_2[2];
LAB_00035934:
    local_44f = '\x01';
    uVar18 = 3;
    break;
  case 0x32:
    pHVar8 = FindWindowW(L"MgrDab",L"MgrDab");
    DAT_00064304 = (uint)param_2[2];
    WVar19 = 0;
    if (pHVar8 != (HWND)0x0) {
      if (DAT_00064304 == 0) {
        WVar19 = 0xca;
      }
      else if (DAT_00064304 == 1) {
        WVar19 = 0xc9;
      }
      else if (DAT_00064304 == 100) {
        WVar19 = 200;
      }
      NKDbgPrintfW(L"\r\n...ToolFunc...Start DAB Seek %d. [%d, %d]\r\n",DAT_00064304,WVar19,0);
      PostMessageW(pHVar8,DAT_00068514,WVar19,0);
    }
    break;
  case 0x33:
    pHVar8 = FindWindowW(L"MgrDab",L"MgrDab");
    DAT_00064308 = (uint)param_2[2];
    if ((pHVar8 != (HWND)0x0) && (DAT_00064308 < 0x40)) {
      local_460 = 0xc9;
      local_45c = 5;
      local_458 = DAT_00064308 * 0xc + 0x6430c;
      SendMessageTimeout(pHVar8,0x4a,3,&local_460,0,0x5dc,auStack_454);
      NKDbgPrintfW(L"\r\n...ToolFunc...Start DAB Tune %d.\r\n",param_2[2]);
      break;
    }
    pwVar9 = L"\r\n...ToolFunc...[ERROR] Check MgrDab...\r\n";
    goto LAB_00035e60;
  case 0x34:
    SetTimer(*(HWND *)(param_1 + 4),0x70e,0xfa,(TIMERPROC)0x0);
    pwVar9 = L"\r\n...ToolFunc...Get DAB Information.\r\n";
LAB_00035e60:
    NKDbgPrintfW(pwVar9);
    break;
  case 0x37:
    NKDbgPrintfW(L"\r\n...ToolFunc...for engineering testing... %d\r\n",param_2[2]);
    bVar16 = param_2[2];
    if (bVar16 == 0) {
      FUN_00034b68((HKEY)0x80000001,L"ControlPanel\\Comm",L"AutoCnct",1);
      FUN_00034c24((HKEY)0x80000001,L"ControlPanel\\Comm",L"Cnct",L"`Default USB`");
    }
    else {
      if (bVar16 == 1) {
        pcVar11 = "\\Storage Card\\firmware.hex";
      }
      else {
        if (bVar16 != 2) break;
        pcVar11 = "\\MD\\firmware.hex";
      }
      FUN_00022cfc(param_1,pcVar11);
    }
  }
switchD_00034d8c_caseD_3:
  if (uVar18 != 0) {
    FUN_00014db0(DAT_000648e4,1,0x80,(int)&local_450,(byte)uVar18,0x32);
  }
  FUN_0004a3f4(local_28);
  return;
}



/* 00035f88 FUN_00035f88 */

/* Boundary evidence: original MIPS .pdata 00035f88..000362eb. Semantic name remains unreviewed. */

void FUN_00035f88(undefined4 param_1,uint param_2)

{
  DWORD DVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  undefined1 local_30;
  undefined1 local_2f;
  char local_2e;
  undefined1 local_2d;
  uint local_1c;
  
  local_1c = DAT_00064820;
  uVar2 = param_2 >> 0x10;
  uVar4 = param_2 & 0xffff;
  bVar5 = 0;
  cVar3 = '\x01';
  if (uVar2 < 0xf1) {
    if (uVar2 == 0xf0) {
      local_30 = 0x82;
      local_2f = 2;
      local_2d = uVar4 != 0;
      local_2e = '\x01';
      bVar5 = 4;
      FUN_00016710(DAT_000648ec,0);
      goto LAB_000362a0;
    }
    if (0x24 < uVar2) {
      if (uVar2 == 0x28) {
        local_30 = 0x88;
        local_2f = 2;
        local_2e = (char)(uVar4 >> 8);
        local_2d = (undefined1)uVar4;
        bVar5 = 4;
        if ((uVar4 == 0) &&
           ((DAT_000684c0 == 0 || (DVar1 = GetTickCount(), 62000 < DVar1 - DAT_000684c0)))) {
          FUN_0001ea70();
          DAT_000684c0 = GetTickCount();
        }
        goto LAB_000362a0;
      }
      if (uVar2 != 0x32) goto LAB_000362a0;
      local_30 = 0xa0;
      goto LAB_00036298;
    }
    cVar3 = (char)(param_2 >> 0x10);
    if (0x1e < uVar2) {
      local_2f = 2;
      local_30 = 0x8c;
      local_2e = cVar3 + -0x1e;
      local_2d = uVar4 != 0;
      bVar5 = 4;
      if (uVar2 == 0x23) {
        NKDbgPrintfW(L"********* TOOL_BT_CALL_ACCEPT *********\n");
        FUN_00036ea0(0x70,0x303010a,0);
      }
      goto LAB_000362a0;
    }
    if (uVar2 < 0xc) {
      local_30 = 0x89;
      local_2e = cVar3;
    }
    else {
      if ((uVar2 < 0x14) || (0x1b < uVar2)) goto LAB_000362a0;
      local_30 = 0x8b;
      local_2e = cVar3 + -0x14;
    }
  }
  else {
    if (uVar2 == 0xf1) {
      if (DAT_000684b8 == 0) goto LAB_000362a0;
      DAT_000684b8 = 0;
      local_30 = 0xaa;
      if (uVar4 == 0) {
        cVar3 = '\0';
      }
LAB_00036298:
      local_2f = 1;
      bVar5 = 3;
      local_2e = cVar3;
      goto LAB_000362a0;
    }
    if (uVar2 != 0xf2) {
      if (uVar2 == 0xf3) {
        if (DAT_00064304 != 0xff) {
          local_30 = 0xb2;
          local_2f = 2;
          local_2d = uVar4 != 0;
          local_2e = (char)DAT_00064304;
          bVar5 = 4;
        }
        DAT_00064304 = 0xff;
      }
      else if (uVar2 == 0xf4) {
        if (DAT_00064308 != 0xff) {
          local_30 = 0xb3;
          local_2f = 2;
          local_2d = uVar4 != 0;
          local_2e = (char)DAT_00064308;
          bVar5 = 4;
        }
        DAT_00064308 = 0xff;
      }
      goto LAB_000362a0;
    }
    local_30 = 0xb4;
    local_2e = '\0';
  }
  local_2f = 2;
  local_2d = uVar4 != 0;
  bVar5 = 4;
LAB_000362a0:
  if (bVar5 != 0) {
    FUN_00014db0(DAT_000648e4,1,0x80,(int)&local_30,bVar5,0x32);
  }
  FUN_0004a3f4(local_1c);
  return;
}



/* 000362ec FUN_000362ec */

/* Boundary evidence: original MIPS .pdata 000362ec..0003645f. Semantic name remains unreviewed. */

void FUN_000362ec(undefined4 param_1,byte *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00064820;
  if (0x53 < *param_2) goto LAB_00036440;
  StringCchPrintfW(awStack_220,0x104,L"%s",(&PTR_u_DSI_TBD_TBC_000641b4)[*param_2]);
  if (DAT_000648e8 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_000648e8 = (undefined4 *)0x0;
    }
    else {
      DAT_000648e8 = FUN_00015604(puVar1,DAT_00064aac);
    }
    if ((DAT_000648e8 == (undefined4 *)0x0) || (DAT_000648e8[3] != 0)) goto LAB_00036440;
    FUN_000156b8((int)DAT_000648e8);
    if (DAT_000648e8[4] == 0) goto LAB_00036440;
    iVar2 = FUN_00015848((int)DAT_000648e8);
    if (iVar2 == 0) {
      if (DAT_000648e8 != (undefined4 *)0x0) {
        (**(code **)*DAT_000648e8)(DAT_000648e8,1);
      }
      DAT_000648e8 = (undefined4 *)0x0;
      goto LAB_00036440;
    }
  }
  else {
    FUN_000156b8((int)DAT_000648e8);
    if (DAT_000648e8[4] != 1) goto LAB_00036440;
    if (DAT_000648e8[3] == 1) {
      FUN_00015990((int)DAT_000648e8,(LPARAM)awStack_220);
      goto LAB_00036440;
    }
  }
  FUN_00015624((int)DAT_000648e8);
  FUN_00015990((int)DAT_000648e8,(LPARAM)awStack_220);
  FUN_00015690((int)DAT_000648e8);
LAB_00036440:
  FUN_0004a3f4(local_18);
  return;
}



/* 00036460 Unwind@00036460 */

/* Boundary evidence: original MIPS .pdata 00036460..0003648f. Semantic name remains unreviewed. */

void Unwind_00036460(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x228));
  return;
}



/* 00036490 FUN_00036490 */

/* Boundary evidence: original MIPS .pdata 00036490..00036c17. Semantic name remains unreviewed. */

void FUN_00036490(int param_1,byte *param_2)

{
  undefined2 uVar1;
  HWND hWnd;
  LSTATUS LVar2;
  wchar_t *pwVar3;
  int iVar4;
  uint uVar5;
  byte local_50;
  byte local_4f;
  byte local_4e;
  byte local_4d;
  HKEY local_4c;
  uint local_48 [2];
  undefined1 auStack_40 [44];
  uint local_14;
  
  local_14 = DAT_00064820;
  uVar5 = (uint)*param_2;
  local_4f = 0;
  local_4e = 0;
  local_50 = 0;
  local_4d = 0;
  switch(uVar5) {
  case 4:
    pwVar3 = L"[DsiSaveUIConfProc] !!! HARD RESET !!!\n";
    break;
  default:
    goto switchD_000364f4_caseD_5;
  case 7:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] CLR DTC - 0x%X",param_2[1]);
    memset(auStack_40,0x10,0x2c);
    FUN_0002155c(param_1,auStack_40,0x2c);
    goto switchD_000364f4_caseD_5;
  case 0xe:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] LastAfterSalesOperationDate - 0x%X, 0x%X, 0x%X",param_2[1],
                 param_2[2],param_2[3]);
    if (*(int *)(param_1 + 0x74) == 1) {
      NKDbgPrintfW(L"- in VIRGIN\n");
      *(undefined2 *)(param_1 + 0x78) = *(undefined2 *)(param_2 + 1);
      *(byte *)(param_1 + 0x7a) = param_2[3];
    }
    goto switchD_000364f4_caseD_5;
  case 0xf:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] MMI Language - 0x%X",param_2[1]);
    if (*(int *)(param_1 + 0x74) == 1) {
      NKDbgPrintfW(L"- in VIRGIN\n");
      *(byte *)(param_1 + 0x7b) = param_2[1];
      goto switchD_000364f4_caseD_5;
    }
    NKDbgPrintfW(&DAT_00054e9c);
    FUN_00032c6c((uint)param_2[1],&local_4f);
    uVar5 = (uint)local_4f;
    iVar4 = 0x7c;
    goto LAB_00036730;
  case 0x10:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] UI(Dist&Spd, Nav, Coloring etc - 0x%X",param_2[1]);
    if (*(int *)(param_1 + 0x74) == 1) {
      NKDbgPrintfW(L"- in VIRGIN\n");
      *(byte *)(param_1 + 0x7f) = param_2[1];
      goto switchD_000364f4_caseD_5;
    }
    NKDbgPrintfW(&DAT_00054e9c);
    FUN_00032e7c((uint)param_2[1],&local_4e,&local_50,&local_4d);
    FUN_00036de8(0x81,(uint)local_4d);
    FUN_00036de8(0x7e,(uint)local_4e);
    uVar5 = (uint)local_50;
    iVar4 = 0x7f;
    goto LAB_00036730;
  case 0x11:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] Radio Contry - 0x%X",param_2[1]);
    if (*(int *)(param_1 + 0x74) == 1) {
      NKDbgPrintfW(L"- in VIRGIN\n");
      *(byte *)(param_1 + 0x7c) = param_2[1];
      goto switchD_000364f4_caseD_5;
    }
    goto LAB_00036914;
  case 0x12:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] SDVC - 0x%X",param_2[1]);
    if (*(int *)(param_1 + 0x74) == 1) {
      NKDbgPrintfW(L"- in VIRGIN\n");
      *(byte *)(param_1 + 0x7d) = param_2[1];
      goto switchD_000364f4_caseD_5;
    }
    NKDbgPrintfW(&DAT_00054e9c);
    uVar5 = (uint)param_2[1];
    iVar4 = 0x7d;
LAB_00036730:
    FUN_00036de8(iVar4,uVar5);
    goto switchD_000364f4_caseD_5;
  case 0x13:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] CAR Maker - 0x%X",param_2[1]);
    if (*(int *)(param_1 + 0x74) == 1) {
      NKDbgPrintfW(L"- in VIRGIN\n");
      *(byte *)(param_1 + 0x7e) = param_2[1];
    }
    else {
      NKDbgPrintfW(&DAT_00054e9c);
    }
    FUN_000326f0(param_2[1]);
    FUN_0001d598();
    goto switchD_000364f4_caseD_5;
  case 0x14:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] CNF_ECU - 0x%X, 0x%X",param_2[1],param_2[2]);
    if (*(int *)(param_1 + 0x74) == 1) {
      NKDbgPrintfW(L"- in VIRGIN\n");
      *(byte *)(param_1 + 0x82) = param_2[1];
      goto switchD_000364f4_caseD_5;
    }
    pwVar3 = L"\n";
    break;
  case 0x15:
    pwVar3 = L"[DsiSaveUIConfProc] LongParam - Phone Accoustic PACT1\n";
    break;
  case 0x16:
    pwVar3 = L"[DsiSaveUIConfProc] LongParam - Phone Acoustic PACT2\n";
    break;
  case 0x17:
    pwVar3 = L"[DsiSaveUIConfProc] LongParam - Acoustic Tuning SOUND3\n";
    break;
  case 0x18:
    pwVar3 = L"[DsiSaveUIConfProc] LongParam - Radio Reception\n";
    break;
  case 0x19:
    NKDbgPrintfW(L"[DsiSaveUIConfProc] Map code - 0x%X",param_2[1]);
    uVar1 = *(undefined2 *)(param_2 + 1);
    if (*(int *)(param_1 + 0x74) == 1) {
      NKDbgPrintfW(L"- in VIRGIN\n");
      *(undefined2 *)(param_1 + 0x80) = uVar1;
      goto switchD_000364f4_caseD_5;
    }
LAB_00036914:
    pwVar3 = L"\n";
    break;
  case 0x24:
    if (*(int *)(param_1 + 0x68) == 0) goto switchD_000364f4_caseD_5;
    SetTimer(*(HWND *)(param_1 + 4),0x70c,200,(TIMERPROC)0x0);
    pwVar3 = L"\r\n\r\n  DSI_CAN_RDBI_MES_TUN_DR \r\n\r\n ";
    break;
  case 0x3a:
    if (*(int *)(param_1 + 0x74) != 1) {
      hWnd = FindWindowW((LPCWSTR)0x0,L"RVC WND");
      NKDbgPrintfW(L"[DsiSaveUIConfProc] Write RVC Type - 0x%02X\n",param_2[1]);
      if (hWnd != (HWND)0x0) {
        SendMessageW(hWnd,0x9e64,0,(uint)param_2[1]);
      }
      goto switchD_000364f4_caseD_5;
    }
    goto LAB_00036a34;
  case 0x3b:
    pwVar3 = L"[DsiSaveUIConfProc] Read RVC Type - 0x%02X\n";
    goto LAB_00036658;
  case 0x3c:
    pwVar3 = L"[DsiSaveUIConfProc] Write CAR Type - 0x%02X\n";
    goto LAB_00036658;
  case 0x3d:
    pwVar3 = L"[DsiSaveUIConfProc] Read CAR Type - 0x%02X\n";
    goto LAB_00036658;
  case 0x3e:
    pwVar3 = L"[DsiSaveUIConfProc] Write ECO - 0x%02X\n";
    goto LAB_00036658;
  case 0x40:
  case 0x42:
  case 0x44:
  case 0x46:
  case 0x48:
    if (*(int *)(param_1 + 0x74) != 1) {
      LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_4c);
      if (LVar2 == 0) {
        local_48[0] = (uint)param_2[1];
        if (uVar5 == 0x40) {
          RegSetValueExW(local_4c,L"RVC_BRIGHTNESS",0,4,(BYTE *)local_48,4);
        }
        else if (uVar5 == 0x42) {
          RegSetValueExW(local_4c,L"RVC_CONTRAST",0,4,(BYTE *)local_48,4);
        }
        else if (uVar5 == 0x44) {
          RegSetValueExW(local_4c,L"RVC_HUE",0,4,(BYTE *)local_48,4);
        }
        else if (uVar5 == 0x46) {
          RegSetValueExW(local_4c,L"RVC_SATU",0,4,(BYTE *)local_48,4);
        }
        else if (uVar5 == 0x48) {
          RegSetValueExW(local_4c,L"RVC_SATV",0,4,(BYTE *)local_48,4);
        }
        RegCloseKey(local_4c);
        PostMessageW((HWND)0xffff,DAT_000684f8,uVar5,local_48[0]);
      }
      goto switchD_000364f4_caseD_5;
    }
LAB_00036a34:
    pwVar3 = L"- in VIRGIN\n";
    break;
  case 0x4e:
    pwVar3 = L"[DsiSaveUIConfProc] LongParam - SPVR1\n";
    break;
  case 0x4f:
    pwVar3 = L"[DsiSaveUIConfProc] LongParam - SPVR2\n";
    break;
  case 0x50:
    pwVar3 = L"[DsiSaveUIConfProc] LongParam - Phone Acoustic PACT3\n";
    break;
  case 0x51:
    pwVar3 = L"[DsiSaveUIConfProc] LongParam - SPVR3\n";
    break;
  case 0x52:
    pwVar3 = L"[DsiSaveUIConfProc] DSI_CAN_RDBI_SYS_AMP\n";
    break;
  case 0x53:
    pwVar3 = L"[DsiSaveUIConfProc] DSI_CAN_WDBI_SYS_AMP - %d\n";
LAB_00036658:
    NKDbgPrintfW(pwVar3,param_2[1]);
    goto switchD_000364f4_caseD_5;
  }
  NKDbgPrintfW(pwVar3);
switchD_000364f4_caseD_5:
  FUN_0004a3f4(local_14);
  return;
}



/* 00036c18 FUN_00036c18 */

/* Boundary evidence: original MIPS .pdata 00036c18..00036de7. Semantic name remains unreviewed. */

undefined1 FUN_00036c18(undefined4 param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined2 local_128;
  undefined2 uStack_126;
  undefined1 local_124;
  undefined1 local_123;
  undefined1 local_122;
  undefined1 local_121;
  uint local_24;
  
  local_24 = DAT_00064820;
  iVar4 = 0;
  bVar1 = FUN_000349d8((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",L"BTAddress",(LPBYTE)&local_128,6);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_000349d8((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",L"BTAddress",(LPBYTE)&local_128,8
                        );
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      uVar3 = 2;
    }
    else {
      NKDbgPrintfW(L"[CheckBTInit 8] ");
      iVar5 = 0;
      do {
        NKDbgPrintfW(L"0x%02X ",*(char *)((int)&local_128 + iVar5));
        if (*(char *)((int)&local_128 + iVar5) == '\0') {
          iVar4 = iVar4 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      if (iVar4 == 8) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    uVar2 = CONCAT13(local_123,CONCAT12(local_124,uStack_126));
    local_123 = local_121;
    local_124 = local_122;
  }
  else {
    NKDbgPrintfW(L"[CheckBTInit 6] ");
    iVar5 = 0;
    do {
      NKDbgPrintfW(L"0x%02X ",*(char *)((int)&local_128 + iVar5));
      if (*(char *)((int)&local_128 + iVar5) == '\0') {
        iVar4 = iVar4 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 6);
    uVar3 = iVar4 == 6;
    uVar2 = CONCAT22(uStack_126,local_128);
  }
  *(undefined1 *)((int)param_2 + 5) = local_123;
  *(undefined1 *)(param_2 + 1) = local_124;
  *param_2 = uVar2;
  FUN_0004a3f4(local_24);
  return uVar3;
}



/* 00036de8 FUN_00036de8 */

/* Boundary evidence: original MIPS .pdata 00036de8..00036e43. Semantic name remains unreviewed. */

void FUN_00036de8(int param_1,LPARAM param_2)

{
  HWND hWnd;
  
  hWnd = FindWindowW(L"AppMain",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    PostMessageW(hWnd,0x8064,param_1 << 0x10 | 0x300,param_2);
  }
  return;
}



/* 00036e44 FUN_00036e44 */

/* Boundary evidence: original MIPS .pdata 00036e44..00036e9f. Semantic name remains unreviewed. */

void FUN_00036e44(int param_1,LPARAM param_2)

{
  HWND hWnd;
  
  hWnd = FindWindowW(L"AppMain",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    SendMessageW(hWnd,0x8064,param_1 << 0x10 | 0x300,param_2);
  }
  return;
}



/* 00036ea0 FUN_00036ea0 */

/* Boundary evidence: original MIPS .pdata 00036ea0..00036f07. Semantic name remains unreviewed. */

void FUN_00036ea0(int param_1,WPARAM param_2,LPARAM param_3)

{
  HWND hWnd;
  
  hWnd = FindWindowW(L"Blue",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    PostMessageW(hWnd,param_1 + 0x8000,param_2,param_3);
  }
  return;
}



/* 00036f08 FUN_00036f08 */

/* Boundary evidence: original MIPS .pdata 00036f08..00036f5f. Semantic name remains unreviewed. */

void FUN_00036f08(WPARAM param_1,LPARAM param_2)

{
  HWND hWnd;
  
  hWnd = FindWindowW(L"Blue",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    PostMessageW(hWnd,0x8082,param_1,param_2);
  }
  return;
}



/* 00036f60 FUN_00036f60 */

void FUN_00036f60(void)

{
  return;
}



/* 00036f68 FUN_00036f68 */

/* Boundary evidence: original MIPS .pdata 00036f68..0003709b. Semantic name remains unreviewed. */

undefined4 * FUN_00036f68(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  char *_DstBuf;
  
  FUN_00044b4c(param_1);
  *param_1 = &PTR_FUN_0005d6f8;
  param_1[0x13] = 0x32;
  param_1[0x14] = 0x1e;
  param_1[0x15] = 0xfffffff6;
  param_1[0x16] = 0x19;
  param_1[0x17] = 0x19;
  param_1[0x18] = 0;
  puVar1 = param_1 + 0x28;
  param_1[0x19] = 0;
  iVar2 = 0x20;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)(param_1 + 0x70) = 0;
  *(undefined1 *)((int)param_1 + 0x1c1) = 0;
  *(undefined1 *)((int)param_1 + 0x1c2) = 0;
  *(undefined1 *)((int)param_1 + 0x1c3) = 0;
  *(undefined1 *)(param_1 + 0x71) = 0;
  param_1[0x11] = 0;
  param_1[0x23] = 0;
  *(undefined1 *)(param_1 + 0x22) = 0;
  do {
    *puVar1 = 0;
    puVar1[0x20] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0);
  param_1[0x6d] = 0x5a;
  param_1[0x6b] = 9;
  *(undefined1 *)(param_1 + 0x12) = 0;
  param_1[0x24] = 0;
  uVar3 = 0;
  param_1[0xd] = 0;
  _DstBuf = (char *)((int)param_1 + 0x1c5);
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  param_1[0x6c] = 0;
  param_1[0x26] = 1;
  param_1[0x6f] = 0;
  param_1[0x6e] = 0xffffffff;
  do {
    sprintf_s(_DstBuf,0x80,"No Log...(%d)",uVar3);
    uVar3 = uVar3 + 1;
    _DstBuf = _DstBuf + 0x80;
  } while (uVar3 < 0x10);
  return param_1;
}



/* 0003709c FUN_0003709c */

/* Boundary evidence: original MIPS .pdata 0003709c..0003719b. Semantic name remains unreviewed. */

void FUN_0003709c(int param_1)

{
  undefined1 local_18 [8];
  
  FUN_00044f54(param_1,100);
  FUN_00044f54(param_1,0x65);
  FUN_00044f54(param_1,0x66);
  FUN_00044f54(param_1,0x67);
  FUN_00044f54(param_1,0x6c);
  FUN_00044f54(param_1,0x6d);
  *(undefined4 *)(DAT_000673c8 + 0x5c) = 0;
  if (*(int *)(param_1 + 0x98) == 0) {
    local_18[0] = 0;
    FUN_00014db0(DAT_000648e4,0,0x30,(int)local_18,1,0x32);
  }
  local_18[0] = 0;
  FUN_00014db0(DAT_000648e4,3,0xf0,(int)local_18,1,0x32);
  if (DAT_00068568 != (undefined4 *)0x0) {
    (**(code **)*DAT_00068568)(DAT_00068568,1);
    DAT_00068568 = (undefined4 *)0x0;
  }
  return;
}



/* 0003719c FUN_0003719c */

/* Boundary evidence: original MIPS .pdata 0003719c..000373af. Semantic name remains unreviewed. */

void FUN_0003719c(int param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,COLORREF param_6
                 ,LPCWSTR param_7)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT h_01;
  HGDIOBJ h_02;
  int x;
  int y;
  RECT *lprc;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  if (*(int *)(param_1 + 0x1ac) == param_3) {
    param_6 = 0x50503c;
  }
  else if (*(int *)(param_1 + 0x1b4) == param_3) {
    param_6 = 0x323232;
  }
  lprc = (RECT *)(&DAT_0005d148 + param_3 * 4);
  FUN_0003da78(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_000440e8(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,5);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_0005d14c)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_0005d150)[param_3 * 4] - x,(&DAT_0005d154)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 000373b0 FUN_000373b0 */

/* Boundary evidence: original MIPS .pdata 000373b0..000375c3. Semantic name remains unreviewed. */

void FUN_000373b0(int param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,COLORREF param_6
                 ,LPCWSTR param_7)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT h_01;
  HGDIOBJ h_02;
  int x;
  int y;
  RECT *lprc;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  if (*(int *)(param_1 + 0x1ac) == param_3) {
    param_6 = 0x50503c;
  }
  else if (*(int *)(param_1 + 0x1b4) == param_3) {
    param_6 = 0x323232;
  }
  lprc = (RECT *)(&DAT_0005d148 + param_3 * 4);
  FUN_0003da78(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_000440e8(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,4);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_0005d14c)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_0005d150)[param_3 * 4] - x,(&DAT_0005d154)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 000375c4 FUN_000375c4 */

/* Boundary evidence: original MIPS .pdata 000375c4..00037877. Semantic name remains unreviewed. */

void FUN_000375c4(int param_1,HDC param_2,int param_3,LONG param_4,LONG param_5,COLORREF param_6,
                 COLORREF param_7,COLORREF param_8,LPCWSTR param_9,LPCWSTR param_10)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT pHVar1;
  HGDIOBJ pvVar2;
  int x;
  int y;
  RECT *lprc;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  if (*(int *)(param_1 + 0x1ac) == param_3) {
    param_8 = 0x50503c;
  }
  else if (*(int *)(param_1 + 0x1b4) == param_3) {
    param_8 = 0x323232;
  }
  lprc = (RECT *)(&DAT_0005d148 + param_3 * 4);
  FUN_0003da78(param_1,hdc,lprc,param_8);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_6);
  pHVar1 = FUN_000440e8(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_9,-1,lprc,1);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_7);
  pHVar1 = FUN_000440e8(param_5,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_10,-1,lprc,9);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  y = (&DAT_0005d14c)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_0005d150)[param_3 * 4] - x,(&DAT_0005d154)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00037878 FUN_00037878 */

/* Boundary evidence: original MIPS .pdata 00037878..0003797f. Semantic name remains unreviewed. */

void FUN_00037878(int param_1,HDC param_2)

{
  undefined4 uVar1;
  COLORREF CVar2;
  undefined8 uVar3;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  uVar1 = FUN_00029158(DAT_000673c8);
  if ((DAT_00067678 & 0x3000) == 0) {
    uVar1 = __ultofp(uVar1);
    uVar1 = __fpmul(uVar1,0x3a83126f);
    uVar3 = __fptodp(uVar1);
    wsprintfW(aWStack_98,L"%6.2fMHz",(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  }
  else {
    wsprintfW(aWStack_98,L"%4dkHz",uVar1);
  }
  if (*(char *)(param_1 + 0x48) == '\0') {
    CVar2 = 0xffffff;
  }
  else {
    CVar2 = 0xff;
    if (*(char *)(param_1 + 0x48) != -1) {
      CVar2 = 0xffff;
    }
  }
  FUN_0003719c(param_1,param_2,0xb,0x2e,CVar2,0,aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 00037980 FUN_00037980 */

/* Boundary evidence: original MIPS .pdata 00037980..0003800f. Semantic name remains unreviewed. */

void FUN_00037980(int param_1,int param_2,HDC param_3)

{
  undefined1 *puVar1;
  uint *puVar2;
  RECT *lprc;
  HDC hdc;
  HBRUSH hbr;
  HFONT pHVar3;
  HGDIOBJ pvVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  RECT local_168;
  HGDIOBJ local_158;
  HBITMAP local_154;
  int *local_150;
  RECT *local_14c;
  int *local_148;
  WCHAR WStack_140;
  undefined1 auStack_13d [4];
  undefined1 auStack_139 [4];
  undefined4 uStack_135;
  undefined1 auStack_130 [4];
  undefined1 auStack_12c [4];
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [4];
  undefined1 auStack_118 [4];
  undefined1 auStack_114 [4];
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 auStack_108 [4];
  undefined1 auStack_104 [4];
  undefined1 auStack_100 [4];
  undefined1 auStack_fc [4];
  undefined1 auStack_f8 [4];
  undefined1 auStack_f4 [4];
  undefined1 auStack_f0 [4];
  undefined1 auStack_ec [4];
  undefined1 auStack_e8 [4];
  undefined1 auStack_e4 [4];
  undefined1 auStack_e0 [4];
  undefined1 auStack_dc [4];
  undefined1 auStack_d8 [4];
  undefined1 auStack_d4 [4];
  undefined1 auStack_d0 [4];
  undefined1 auStack_cc [4];
  undefined1 auStack_c8 [4];
  undefined1 auStack_c4 [4];
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined1 auStack_b4 [4];
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00064820;
  hdc = CreateCompatibleDC(param_3);
  local_154 = CreateCompatibleBitmap(param_3,800,0x1e0);
  local_158 = SelectObject(hdc,local_154);
  iVar8 = param_2 * 0x10;
  local_14c = (RECT *)(&DAT_0005d248 + iVar8);
  hbr = GetStockObject(4);
  FillRect(hdc,(RECT *)(&DAT_0005d248 + iVar8),hbr);
  iVar7 = 0x3a;
  switch(param_2) {
  case 0:
  case 6:
  case 7:
  case 8:
    iVar7 = (*(int *)((param_2 + 0x13) * 4 + param_1) * 0x3a) / 100;
    break;
  case 1:
    iVar7 = (*(int *)(param_1 + 0x50) * 0x3a) / 0x3c;
    break;
  case 2:
    uVar6 = (int)*(uint *)(param_1 + 0x54) >> 0x1f;
    iVar7 = 0x3a - (int)(((*(uint *)(param_1 + 0x54) ^ uVar6) - uVar6) * 0x3a) / 0x14;
    break;
  case 3:
    iVar7 = *(int *)(param_1 + 0x58);
    goto LAB_00037b08;
  case 4:
    iVar7 = *(int *)(param_1 + 0x5c);
LAB_00037b08:
    iVar7 = 0x3a - (iVar7 * 0x3a) / 0x32;
    break;
  case 5:
    iVar5 = *(int *)(param_1 + 0x60) * 0x3a;
    iVar7 = iVar5 >> 4;
    if (iVar5 < 0) {
      iVar7 = iVar5 + 0xf >> 4;
    }
  }
  local_150 = (int *)(&DAT_0005d24c + iVar8);
  local_168.right = *(LONG *)(&DAT_0005d250 + iVar8);
  local_168.left = local_168.right + -0x12;
  local_168.top = *local_150 + 1;
  local_148 = (int *)(&DAT_0005d254 + iVar8);
  local_168.right = local_168.right + -5;
  local_168.bottom = *local_148 + -1;
  FUN_0003da78(param_1,hdc,&local_168,0xff);
  if (0 < iVar7) {
    if (local_168.top < local_168.bottom - iVar7) {
      local_168.top = local_168.bottom - iVar7;
    }
    FUN_0003da78(param_1,hdc,&local_168,0xff00);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xb4b4b4);
  pHVar3 = FUN_000440e8(0x10,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar4 = SelectObject(hdc,pHVar3);
  uVar6 = (uint)auStack_13d & 3;
  puVar2 = (uint *)(auStack_13d + -uVar6);
  *puVar2 = *puVar2 & -1 << (uVar6 + 1) * 8 | 0x200020U >> (3 - uVar6) * 8;
  uVar6 = (uint)auStack_139 & 3;
  puVar2 = (uint *)(auStack_139 + -uVar6);
  *puVar2 = *puVar2 & -1 << (uVar6 + 1) * 8 | 0x200051U >> (3 - uVar6) * 8;
  uVar6 = (uint)&uStack_135 & 3;
  puVar2 = (uint *)((int)&uStack_135 - uVar6);
  *puVar2 = *puVar2 & -1 << (uVar6 + 1) * 8 | 0x20U >> (3 - uVar6) * 8;
  _WStack_140 = 0x200020;
  stack0xfffffec4 = 0x200051;
  stack0xfffffec8 = 0x20;
  memset((void *)((int)&uStack_135 + 1),0,4);
  puVar1 = auStack_130 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x460020U >> (3 - uVar6) * 8;
  puVar1 = auStack_12c + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x200053U >> (3 - uVar6) * 8;
  puVar1 = auStack_128 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x20U >> (3 - uVar6) * 8;
  auStack_130 = (undefined1  [4])0x460020;
  auStack_12c = (undefined1  [4])0x200053;
  auStack_128 = (undefined1  [4])0x20;
  memset(auStack_124,0,4);
  puVar1 = auStack_120 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x460020U >> (3 - uVar6) * 8;
  puVar1 = auStack_11c + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x20004fU >> (3 - uVar6) * 8;
  puVar1 = auStack_118 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x20U >> (3 - uVar6) * 8;
  auStack_120 = (undefined1  [4])0x460020;
  auStack_11c = (undefined1  [4])0x20004f;
  auStack_118 = (undefined1  [4])0x20;
  memset(auStack_114,0,4);
  local_110 = 0x550020;
  puVar1 = auStack_108 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x20U >> (3 - uVar6) * 8;
  local_10c = 0x4e0053;
  auStack_108 = (undefined1  [4])0x20;
  memset(auStack_104,0,4);
  puVar1 = auStack_100 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x4d0020U >> (3 - uVar6) * 8;
  puVar1 = auStack_fc + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x200050U >> (3 - uVar6) * 8;
  puVar1 = auStack_f8 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x20U >> (3 - uVar6) * 8;
  auStack_100 = (undefined1  [4])0x4d0020;
  auStack_fc = (undefined1  [4])0x200050;
  auStack_f8 = (undefined1  [4])0x20;
  memset(auStack_f4,0,4);
  puVar1 = auStack_f0 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x420020U >> (3 - uVar6) * 8;
  puVar1 = auStack_ec + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x200057U >> (3 - uVar6) * 8;
  puVar1 = auStack_e8 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x20U >> (3 - uVar6) * 8;
  auStack_f0 = (undefined1  [4])0x420020;
  auStack_ec = (undefined1  [4])0x200057;
  auStack_e8 = (undefined1  [4])0x20;
  memset(auStack_e4,0,4);
  puVar1 = auStack_e0 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x4d0020U >> (3 - uVar6) * 8;
  puVar1 = auStack_dc + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x200053U >> (3 - uVar6) * 8;
  puVar1 = auStack_d8 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x20U >> (3 - uVar6) * 8;
  auStack_e0 = (undefined1  [4])0x4d0020;
  auStack_dc = (undefined1  [4])0x200053;
  auStack_d8 = (undefined1  [4])0x20;
  memset(auStack_d4,0,4);
  puVar1 = auStack_d0 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x480020U >> (3 - uVar6) * 8;
  puVar1 = auStack_cc + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x200043U >> (3 - uVar6) * 8;
  puVar1 = auStack_c8 + 3;
  uVar6 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar6) =
       *(uint *)(puVar1 + -uVar6) & -1 << (uVar6 + 1) * 8 | 0x20U >> (3 - uVar6) * 8;
  auStack_d0 = (undefined1  [4])0x480020;
  auStack_cc = (undefined1  [4])0x200043;
  auStack_c8 = (undefined1  [4])0x20;
  memset(auStack_c4,0,4);
  local_c0 = 0x530020;
  local_bc = 0x20004d;
  local_b8 = 0x20;
  memset(auStack_b4,0,4);
  lprc = local_14c;
  DrawTextW(hdc,&WStack_140 + param_2 * 8,-1,local_14c,1);
  SelectObject(hdc,pvVar4);
  DeleteObject(pHVar3);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xffffff);
  pHVar3 = FUN_000440e8(0x24,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar4 = SelectObject(hdc,pHVar3);
  wsprintfW(aWStack_b0,L"%3d",*(undefined4 *)((param_2 + 0x13) * 4 + param_1));
  DrawTextW(hdc,aWStack_b0,-1,lprc,8);
  SelectObject(hdc,pvVar4);
  DeleteObject(pHVar3);
  iVar5 = *local_150;
  iVar7 = lprc->left;
  BitBlt(param_3,iVar7,iVar5,*(int *)(&DAT_0005d250 + iVar8) - iVar7,*local_148 - iVar5,hdc,iVar7,
         iVar5,0xcc0020);
  SelectObject(hdc,local_158);
  DeleteObject(local_154);
  DeleteDC(hdc);
  FUN_0004a3f4(local_30);
  return;
}



/* 00038010 FUN_00038010 */

/* Boundary evidence: original MIPS .pdata 00038010..0003811f. Semantic name remains unreviewed. */

void FUN_00038010(int param_1,int param_2,HDC param_3)

{
  WCHAR local_58 [3];
  undefined1 auStack_52 [10];
  undefined4 local_48;
  undefined1 auStack_44 [12];
  undefined4 local_38;
  undefined1 auStack_34 [12];
  undefined4 local_28;
  undefined2 local_24;
  undefined1 auStack_22 [10];
  uint local_18;
  
  local_18 = DAT_00064820;
  local_58[0] = L'<';
  local_58[1] = L'<';
  local_58[2] = 0;
  memset(auStack_52,0,10);
  local_48 = 0x3c;
  memset(auStack_44,0,0xc);
  local_38 = 0x3e;
  memset(auStack_34,0,0xc);
  local_28 = 0x3e003e;
  local_24 = 0;
  memset(auStack_22,0,10);
  FUN_0003719c(param_1,param_3,param_2 + 1,0x20,0xffffff,0,local_58 + param_2 * 8);
  FUN_0004a3f4(local_18);
  return;
}



/* 00038120 FUN_00038120 */

/* Boundary evidence: original MIPS .pdata 00038120..00038227. Semantic name remains unreviewed. */

void FUN_00038120(int param_1,int param_2,HDC param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  WCHAR local_48 [3];
  undefined1 auStack_42 [10];
  undefined4 local_38;
  undefined2 local_34;
  undefined1 auStack_32 [10];
  undefined4 local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [8];
  uint local_18;
  
  local_18 = DAT_00064820;
  local_48[0] = L'<';
  local_48[1] = L'<';
  local_48[2] = 0;
  memset(auStack_42,0,10);
  local_38 = 0x3e003e;
  local_34 = 0;
  memset(auStack_32,0,10);
  puVar1 = auStack_24 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x46U >> (3 - uVar2) * 8;
  local_28 = 0x46004f;
  auStack_24 = (undefined1  [4])0x46;
  memset(auStack_20,0,8);
  FUN_0003719c(param_1,param_3,param_2 + 0x4c,0x20,0xffffff,0,local_48 + param_2 * 8);
  FUN_0004a3f4(local_18);
  return;
}



/* 00038228 FUN_00038228 */

/* Boundary evidence: original MIPS .pdata 00038228..00038287. Semantic name remains unreviewed. */

void FUN_00038228(int param_1,HDC param_2)

{
  LPCWSTR pWVar1;
  
  if ((DAT_00067678 & 0x3000) == 0) {
    pWVar1 = L"FM";
  }
  else {
    pWVar1 = L"AM";
  }
  FUN_0003719c(param_1,param_2,0,0x24,0xffffff,0,pWVar1);
  return;
}



/* 00038288 FUN_00038288 */

/* Boundary evidence: original MIPS .pdata 00038288..000382e7. Semantic name remains unreviewed. */

void FUN_00038288(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if ((DAT_00067678 & 8) == 0) {
    CVar1 = 0x808080;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_0003719c(param_1,param_2,5,0x18,CVar1,0,L"AF");
  return;
}



/* 000382e8 FUN_000382e8 */

/* Boundary evidence: original MIPS .pdata 000382e8..00038347. Semantic name remains unreviewed. */

void FUN_000382e8(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if ((DAT_00067678 & 0x20) == 0) {
    CVar1 = 0x808080;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_0003719c(param_1,param_2,6,0x18,CVar1,0,L"RGN");
  return;
}



/* 00038348 FUN_00038348 */

/* Boundary evidence: original MIPS .pdata 00038348..000383a7. Semantic name remains unreviewed. */

void FUN_00038348(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if ((DAT_00067678 & 4) == 0) {
    CVar1 = 0x808080;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_0003719c(param_1,param_2,7,0x18,CVar1,0,L"RDS");
  return;
}



/* 000383a8 FUN_000383a8 */

/* Boundary evidence: original MIPS .pdata 000383a8..0003846b. Semantic name remains unreviewed. */

void FUN_000383a8(int param_1,HDC param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
  uVar1 = __fpmul(uVar1,0x3951b717);
  uVar2 = __fptodp(uVar1);
  wsprintfW(aWStack_98,L"%5.2f",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  FUN_000375c4(param_1,param_2,10,0x18,0x26,0xb4b4b4,0xffffff,0,L"DIST(Km)",aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 0003846c FUN_0003846c */

/* Boundary evidence: original MIPS .pdata 0003846c..0003856b. Semantic name remains unreviewed. */

void FUN_0003846c(int param_1,HDC param_2)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  char local_a8 [16];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  builtin_strncpy(local_a8,"--------",9);
  memset(local_a8 + 9,0,7);
  uVar1 = FUN_00029160(DAT_000673c8);
  if (CONCAT22(extraout_var,uVar1) != 0) {
    uVar1 = FUN_00029160(DAT_000673c8);
    FUN_00030e3c(DAT_00067670,CONCAT22(extraout_var_00,uVar1),(undefined4 *)local_a8);
  }
  uVar1 = FUN_00029160(DAT_000673c8);
  wsprintfW(aWStack_98,L"%04X(%S)",CONCAT22(extraout_var_01,uVar1),local_a8);
  FUN_0003719c(param_1,param_2,0xc,0x20,0xffffff,0,aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 0003856c FUN_0003856c */

/* Boundary evidence: original MIPS .pdata 0003856c..00038c1b. Semantic name remains unreviewed. */

void FUN_0003856c(int param_1,HDC param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 local_1b8;
  undefined1 local_1b4;
  undefined1 auStack_1b3 [4];
  undefined4 local_1af;
  undefined1 local_1ab;
  undefined1 auStack_1aa [4];
  char local_1a6 [4];
  undefined1 auStack_1a2 [4];
  undefined1 uStack_19e;
  undefined4 local_19d;
  undefined1 local_199;
  undefined1 auStack_198 [4];
  char local_194 [5];
  undefined1 local_18f;
  undefined1 auStack_18e [3];
  char local_18b [4];
  undefined1 auStack_187 [4];
  undefined1 uStack_183;
  undefined2 local_182;
  undefined2 uStack_180;
  undefined1 local_17e;
  undefined1 local_17d;
  undefined1 auStack_17c [3];
  char local_179 [4];
  undefined1 auStack_175 [4];
  undefined1 uStack_171;
  char local_170 [7];
  undefined1 auStack_169 [6];
  undefined1 local_163;
  undefined1 local_162;
  char local_161;
  undefined1 auStack_160 [2];
  undefined4 local_15e;
  undefined1 local_15a;
  undefined1 local_159;
  undefined1 auStack_158 [3];
  undefined4 local_155;
  undefined1 local_151;
  undefined1 local_150;
  undefined1 local_14f;
  undefined1 auStack_14e [2];
  undefined4 local_14c;
  undefined1 local_148;
  undefined1 local_147;
  undefined1 local_146;
  undefined1 auStack_145 [2];
  char local_143 [4];
  undefined1 auStack_13f [4];
  undefined1 uStack_13b;
  undefined2 local_13a;
  undefined2 uStack_138;
  char local_136 [5];
  undefined1 auStack_131 [4];
  undefined1 auStack_12d [4];
  undefined1 uStack_129;
  char local_128 [7];
  undefined1 auStack_121 [6];
  undefined1 auStack_11b [4];
  undefined1 uStack_117;
  undefined2 local_116;
  undefined2 uStack_114;
  char local_112 [5];
  undefined1 auStack_10d [4];
  undefined1 local_109;
  undefined1 local_108;
  char local_107;
  undefined1 auStack_106 [2];
  char local_104 [23];
  undefined1 local_ed;
  char local_ec;
  undefined1 auStack_eb [2];
  char local_e9 [4];
  undefined1 auStack_e5 [4];
  undefined1 uStack_e1;
  undefined4 local_e0;
  undefined1 local_dc;
  undefined1 auStack_db [4];
  char local_d7 [4];
  undefined1 auStack_d3 [4];
  undefined1 uStack_cf;
  undefined2 local_ce;
  undefined2 uStack_cc;
  char local_ca [10];
  undefined1 local_c0;
  char local_bf;
  undefined1 auStack_be [2];
  undefined4 local_bc;
  undefined1 local_b8;
  undefined1 local_b7;
  undefined1 local_b6;
  undefined1 auStack_b5 [2];
  char local_b3 [18];
  undefined4 local_a1;
  undefined1 auStack_9d [4];
  undefined1 uStack_99;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  local_1b8 = 0x656e6f4e;
  local_1b4 = 0;
  memset(auStack_1b3,0,4);
  local_1af = 0x7377654e;
  local_1ab = 0;
  memset(auStack_1aa,0,4);
  puVar1 = auStack_1a2 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)0x737269 >> (3 - uVar2) * 8;
  builtin_strncpy(local_1a6,"Affa",4);
  uVar2 = (uint)auStack_1a2 & 3;
  puVar3 = (uint *)(auStack_1a2 + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x737269U << uVar2 * 8;
  memset(auStack_1a2 + 4,0,1);
  local_19d = 0x6f666e49;
  local_199 = 0;
  memset(auStack_198,0,4);
  local_194[4] = 0x74;
  builtin_strncpy(local_194,"Spor",4);
  local_18f = 0;
  memset(auStack_18e,0,3);
  uVar2 = CONCAT22(local_182,stack0xfffffe7c) & 0xffffff00;
  stack0xfffffe7c = (undefined2)uVar2;
  local_182 = (undefined2)(uVar2 >> 0x10);
  builtin_strncpy(local_18b,"Educ",4);
  uVar2 = (uint)auStack_187 & 3;
  puVar3 = (uint *)(auStack_187 + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x657461U << uVar2 * 8;
  memset(&uStack_183,0,1);
  local_182 = 0x7244;
  uStack_180 = 0x6d61;
  local_17e = 0x61;
  local_17d = 0;
  memset(auStack_17c,0,3);
  puVar1 = auStack_175 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)0x657275 >> (3 - uVar2) * 8;
  builtin_strncpy(local_179,"Cult",4);
  uVar2 = (uint)auStack_175 & 3;
  puVar3 = (uint *)(auStack_175 + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x657275U << uVar2 * 8;
  memset(auStack_175 + 4,0,1);
  uVar2 = (uint)auStack_169 & 3;
  puVar3 = (uint *)(auStack_169 + -uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | (uint)0x65636e >> (3 - uVar2) * 8;
  builtin_strncpy(local_170,"Science",7);
  auStack_169[0] = '\0';
  memset(auStack_169 + 1,0,1);
  local_163 = 0x65;
  auStack_169[2] = 'V';
  auStack_169[3] = 'a';
  auStack_169[4] = 'r';
  auStack_169[5] = 'i';
  local_162 = 100;
  local_161 = '\0';
  memset(auStack_160,0,2);
  local_15a = 0x4d;
  local_15e = 0x20706f50;
  local_159 = 0;
  memset(auStack_158,0,3);
  local_151 = 0x20;
  local_155 = 0x6b636f52;
  local_150 = 0x4d;
  local_14f = 0;
  memset(auStack_14e,0,2);
  local_14c = 0x79736145;
  local_148 = 0x20;
  local_147 = 0x4d;
  local_146 = 0;
  memset(auStack_145,0,2);
  uVar2 = CONCAT22(local_13a,stack0xfffffec4) & 0xffffff00;
  stack0xfffffec4 = (undefined2)uVar2;
  local_13a = (undefined2)(uVar2 >> 0x10);
  builtin_strncpy(local_143,"Ligh",4);
  uVar2 = (uint)auStack_13f & 3;
  puVar3 = (uint *)(auStack_13f + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x4d2074U << uVar2 * 8;
  memset(&uStack_13b,0,1);
  local_13a = 0x6c43;
  uStack_138 = 0x7361;
  builtin_strncpy(local_136,"sics",4);
  puVar1 = auStack_131 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)0x6568744f >> (3 - uVar2) * 8;
  puVar1 = auStack_131 + 7;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)0x4d2072 >> (3 - uVar2) * 8;
  local_136[4] = '\0';
  uVar2 = (uint)auStack_131 & 3;
  puVar3 = (uint *)(auStack_131 + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x6568744fU << uVar2 * 8;
  puVar1 = auStack_131 + 4;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & 0xffffffffU >> (4 - uVar2) * 8 | 0x4d2072U << uVar2 * 8;
  memset(auStack_131 + 8,0,1);
  uVar2 = (uint)auStack_121 & 3;
  puVar3 = (uint *)(auStack_121 + -uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | (uint)0x726568 >> (3 - uVar2) * 8;
  builtin_strncpy(local_128,"Weather",7);
  auStack_121[0] = '\0';
  memset(auStack_121 + 1,0,1);
  uVar2 = CONCAT22(local_116,stack0xfffffee8) & 0xffffff00;
  stack0xfffffee8 = (undefined2)uVar2;
  local_116 = (undefined2)(uVar2 >> 0x10);
  auStack_121[2] = 'F';
  auStack_121[3] = 'i';
  auStack_121[4] = 'n';
  auStack_121[5] = 'a';
  uVar2 = (uint)auStack_11b & 3;
  puVar3 = (uint *)(auStack_11b + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x65636eU << uVar2 * 8;
  memset(&uStack_117,0,1);
  local_116 = 0x6843;
  uStack_114 = 0x6c69;
  builtin_strncpy(local_112,"dren",5);
  puVar1 = auStack_10d + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)0x69636f53 >> (3 - uVar2) * 8;
  local_109 = 0x61;
  uVar2 = (uint)auStack_10d & 3;
  puVar3 = (uint *)(auStack_10d + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x69636f53U << uVar2 * 8;
  local_108 = 0x6c;
  local_107 = '\0';
  memset(auStack_10d + 7,0,2);
  builtin_strncpy(local_104,"Religion",9);
  builtin_strncpy(local_104 + 9,"Phone In",9);
  local_104[0x16] = 0x65;
  builtin_strncpy(local_104 + 0x12,"Trav",4);
  local_ed = 0x6c;
  local_ec = '\0';
  memset(auStack_eb,0,2);
  puVar1 = auStack_e5 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)0x657275 >> (3 - uVar2) * 8;
  builtin_strncpy(local_e9,"Leis",4);
  uVar2 = (uint)auStack_e5 & 3;
  puVar3 = (uint *)(auStack_e5 + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x657275U << uVar2 * 8;
  memset(auStack_e5 + 4,0,1);
  local_e0 = 0x7a7a614a;
  local_dc = 0;
  memset(auStack_db,0,4);
  uVar2 = CONCAT22(local_ce,stack0xffffff30) & 0xffffff00;
  stack0xffffff30 = (undefined2)uVar2;
  local_ce = (undefined2)(uVar2 >> 0x10);
  builtin_strncpy(local_d7,"Coun",4);
  uVar2 = (uint)auStack_d3 & 3;
  puVar3 = (uint *)(auStack_d3 + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x797274U << uVar2 * 8;
  memset(&uStack_cf,0,1);
  builtin_strncpy(local_ca,"on M",5);
  local_ce = 0x614e;
  uStack_cc = 0x6974;
  local_ca[9] = 0x65;
  builtin_strncpy(local_ca + 5,"Oldi",4);
  local_c0 = 0x73;
  local_bf = '\0';
  memset(auStack_be,0,2);
  local_b8 = 0x20;
  local_bc = 0x6b6c6f46;
  local_b7 = 0x4d;
  local_b6 = 0;
  memset(auStack_b5,0,2);
  builtin_strncpy(local_b3,"Document",9);
  builtin_strncpy(local_b3 + 9,"TEST",5);
  memset(local_b3 + 0xe,0,4);
  puVar1 = auStack_9d + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x21206dU >> (3 - uVar2) * 8;
  local_a1 = 0x72616c41;
  uVar2 = (uint)auStack_9d & 3;
  puVar3 = (uint *)(auStack_9d + -uVar2);
  *puVar3 = *puVar3 & 0xffffffffU >> (4 - uVar2) * 8 | 0x21206d << uVar2 * 8;
  memset(auStack_9d + 4,0,1);
  wsprintfW((LPWSTR)(auStack_9d + 5),L"%S",(int)&local_1b8 + *(int *)(param_1 + 0x8c) * 9);
  FUN_0003719c(param_1,param_2,0xd,0x20,0xffffff,0,(LPCWSTR)(auStack_9d + 5));
  FUN_0004a3f4(local_18);
  return;
}



/* 00038c1c FUN_00038c1c */

/* Boundary evidence: original MIPS .pdata 00038c1c..00038d0b. Semantic name remains unreviewed. */

void FUN_00038c1c(int param_1,HDC param_2)

{
  byte bVar1;
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00064820;
  bVar1 = *(byte *)(param_1 + 0x88);
  wsprintfW(aWStack_218,L"%d/%d/%d/%d",(uint)((bVar1 & 1) != 0),(uint)((bVar1 & 2) != 0),
            (uint)((bVar1 & 4) != 0),(uint)((bVar1 & 8) != 0));
  FUN_000375c4(param_1,param_2,0xe,0xe,0x18,0xb4b4b4,0xffffff,0,L"TP/TA/ETP/ETA",aWStack_218);
  FUN_0004a3f4(local_18);
  return;
}



/* 00038d0c FUN_00038d0c */

/* Boundary evidence: original MIPS .pdata 00038d0c..00039257. Semantic name remains unreviewed. */

void FUN_00038d0c(int param_1,HDC param_2)

{
  int iVar1;
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT h_01;
  HGDIOBJ h_02;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  LPRECT lprc;
  undefined8 uVar5;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00064820;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  h_01 = FUN_000440e8(0x10,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  lprc = (LPRECT)&DAT_0005d2e8;
  piVar4 = (int *)(param_1 + 0xa0);
  iVar1 = 0;
  do {
    iVar3 = iVar1;
    if ((*piVar4 == 0) || (0x1f < iVar3)) {
      FUN_0003719c(param_1,hdc,iVar3 + 0x1a,0x16,
                   ((uint)(piVar4[0x20] * 0x96) / 100 + 100 & 0xff) << 8 | 0x640064,0,L"-");
    }
    else {
      uVar2 = __ultofp();
      uVar2 = __fpmul(uVar2,0x3a83126f);
      uVar5 = __fptodp(uVar2);
      wsprintfW(aWStack_b0,L"%4.1f",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      FUN_0003719c(param_1,hdc,iVar3 + 0x1a,0x16,
                   ((uint)(piVar4[0x20] * 0x96) / 100 + 100 & 0xff) << 8 | 0x640064,0,aWStack_b0);
      SetBkMode(hdc,1);
      SetTextColor(hdc,0x808080);
      wsprintfW(aWStack_b0,L"%d",piVar4[0x20]);
      DrawTextW(hdc,aWStack_b0,-1,lprc,9);
    }
    lprc = lprc + 1;
    piVar4 = piVar4 + 1;
    iVar1 = iVar3 + 1;
  } while ((int)lprc < 0x5d4d8);
  if ((*(int *)((*(int *)(param_1 + 0x1b0) + 0x47) * 4 + param_1) == 0) ||
     (0x1f < *(int *)(param_1 + 0x1b0) + 0x1fU)) {
    FUN_0003719c(param_1,hdc,0x39,0x16,
                 ((uint)(*(int *)((iVar3 + 0x49) * 4 + param_1) * 0x96) / 100 + 100 & 0xff) << 8 |
                 0x640064,0,L"-");
  }
  else {
    uVar2 = __ultofp();
    uVar2 = __fpmul(uVar2,0x3a83126f);
    uVar5 = __fptodp(uVar2);
    wsprintfW(aWStack_b0,L"%4.1f",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    FUN_0003719c(param_1,hdc,0x39,0x16,
                 ((uint)(*(int *)((iVar3 + 0x49) * 4 + param_1) * 0x96) / 100 + 100 & 0xff) << 8 |
                 0x640064,0,aWStack_b0);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xb4b4b4);
  wsprintfW(aWStack_b0,L"%d(%d)",*(int *)(param_1 + 0x1b0) + 0x20,(uint)*(byte *)(param_1 + 0x12));
  DrawTextW(hdc,aWStack_b0,-1,(LPRECT)&DAT_0005d4d8,9);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  uVar2 = __ultofp(*(undefined4 *)(param_1 + 0x44));
  uVar2 = __fpmul(uVar2,0x3a83126f);
  uVar5 = __fptodp(uVar2);
  wsprintfW(aWStack_b0,L"%4.1f",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  FUN_0003719c(param_1,hdc,0xf,0x1e,0xc8c8c8,0,aWStack_b0);
  BitBlt(param_2,0,0xb4,800,0x5a,hdc,0,0xb4,0xcc0020);
  BitBlt(param_2,700,0x3c,100,0x3c,hdc,700,0x3c,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_0004a3f4(local_30);
  return;
}



/* 00039258 FUN_00039258 */

/* Boundary evidence: original MIPS .pdata 00039258..0003934b. Semantic name remains unreviewed. */

void FUN_00039258(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  int iVar1;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  iVar1 = 0;
  do {
    FUN_00037980(param_1,iVar1,hdc);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  BitBlt(param_2,0,0x78,0x276,0x3c,hdc,0,0x78,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003934c FUN_0003934c */

/* Boundary evidence: original MIPS .pdata 0003934c..000394c7. Semantic name remains unreviewed. */

void FUN_0003934c(int param_1,int param_2,HDC param_3)

{
  wchar_t *pwVar1;
  WCHAR aWStack_118 [64];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  switch(param_2) {
  case 0:
    pwVar1 = L"FS R";
    break;
  case 1:
    pwVar1 = L"FO R";
    break;
  case 2:
    pwVar1 = L"USN R";
    break;
  case 3:
    pwVar1 = L"MP R";
    break;
  case 4:
    pwVar1 = L"FM Sk St";
    break;
  case 5:
    pwVar1 = L"St AF";
    break;
  case 6:
    pwVar1 = L"Good";
    break;
  case 7:
    pwVar1 = L"Diff";
    break;
  case 8:
    pwVar1 = L"EmgSt";
    break;
  case 9:
    pwVar1 = L"EmgJmp";
    break;
  case 10:
    pwVar1 = L"AM Sk St";
    break;
  default:
    goto switchD_0003939c_default;
  }
  wsprintfW(aWStack_118,pwVar1);
switchD_0003939c_default:
  wsprintfW(aWStack_98,L"%d",(uint)*(byte *)(param_2 + param_1 + 0x1a0));
  FUN_000375c4(param_1,param_3,param_2 + 0x3a,0xc,0x1c,0xb4b4b4,0xffffff,0,aWStack_118,aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 000394c8 FUN_000394c8 */

/* Boundary evidence: original MIPS .pdata 000394c8..000395bb. Semantic name remains unreviewed. */

void FUN_000394c8(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  int iVar1;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  iVar1 = 0;
  do {
    FUN_0003934c(param_1,iVar1,hdc);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xc);
  BitBlt(param_2,0,0x118,0x32,0x5a,hdc,0,0x118,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 000395bc FUN_000395bc */

/* Boundary evidence: original MIPS .pdata 000395bc..000397a3. Semantic name remains unreviewed. */

void FUN_000395bc(int param_1,int param_2,HDC param_3)

{
  LPCWSTR pWVar1;
  uint uVar2;
  WCHAR aWStack_120 [64];
  WCHAR aWStack_a0 [64];
  uint local_20;
  
  local_20 = DAT_00064820;
  if (param_2 == 0) {
    wsprintfW(aWStack_120,L"Q");
LAB_000396b8:
    if (param_2 < 5) goto LAB_000396c4;
    if (param_2 != 5) {
      if (param_2 == 6) {
LAB_00039710:
        uVar2 = (uint)*(ushort *)(param_1 + 0x86);
        pWVar1 = L"%x";
        goto LAB_00039720;
      }
      goto LAB_00039728;
    }
LAB_000396e8:
    wsprintfW(aWStack_a0,L"%d",(uint)*(ushort *)(param_1 + 0x84));
  }
  else {
    if (param_2 == 1) {
      pWVar1 = L"FS";
    }
    else if (param_2 == 2) {
      pWVar1 = L"FO";
    }
    else if (param_2 == 3) {
      pWVar1 = L"USN";
    }
    else {
      if (param_2 != 4) {
        if (param_2 != 5) {
          if (param_2 != 6) goto LAB_000396b8;
          wsprintfW(aWStack_120,L"PI");
          goto LAB_00039710;
        }
        wsprintfW(aWStack_120,L"FREQ");
        goto LAB_000396e8;
      }
      pWVar1 = L"MP";
    }
    wsprintfW(aWStack_120,pWVar1);
LAB_000396c4:
    uVar2 = *(uint *)((param_2 + 0x1c) * 4 + param_1);
    pWVar1 = L"%d";
LAB_00039720:
    wsprintfW(aWStack_a0,pWVar1,uVar2);
LAB_00039728:
    if (6 < param_2) goto LAB_0003977c;
  }
  FUN_000375c4(param_1,param_3,param_2 + 0x45,0xc,0x1c,0xb4b4b4,0xffffff,0,aWStack_120,aWStack_a0);
LAB_0003977c:
  FUN_0004a3f4(local_20);
  return;
}



/* 000397a4 FUN_000397a4 */

/* Boundary evidence: original MIPS .pdata 000397a4..0003983b. Semantic name remains unreviewed. */

void FUN_000397a4(int param_1,HDC param_2)

{
  int iVar1;
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00064820;
  iVar1 = *(int *)(param_1 + 0x1bc);
  if (-1 < iVar1) {
    wsprintfW(aWStack_218,L"%d : %S",iVar1,iVar1 * 0x80 + param_1 + 0x1c5);
    FUN_000373b0(param_1,param_2,0x4f,0x18,0xb4b4b4,0,aWStack_218);
  }
  FUN_0004a3f4(local_18);
  return;
}



/* 0003983c FUN_0003983c */

/* Boundary evidence: original MIPS .pdata 0003983c..00039897. Semantic name remains unreviewed. */

void FUN_0003983c(int param_1,HDC param_2)

{
  FUN_000375c4(param_1,param_2,0x50,0xc,0x1a,0xb4b4b4,0xffffff,0,L"STATION",L"ERASE");
  return;
}



/* 00039898 FUN_00039898 */

/* Boundary evidence: original MIPS .pdata 00039898..000398f3. Semantic name remains unreviewed. */

void FUN_00039898(int param_1,HDC param_2)

{
  FUN_000375c4(param_1,param_2,0x51,0xc,0x1a,0xb4b4b4,0xffffff,0,L"STATION",L"SAVE");
  return;
}



/* 000398f4 FUN_000398f4 */

/* Boundary evidence: original MIPS .pdata 000398f4..00039967. Semantic name remains unreviewed. */

void FUN_000398f4(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if (*(int *)(param_1 + 0x40) == 1) {
    CVar1 = 0xff00;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_000375c4(param_1,param_2,0x55,0xc,0x1a,0xb4b4b4,CVar1,0,L"LOG",L"QUAL");
  return;
}



/* 00039968 FUN_00039968 */

/* Boundary evidence: original MIPS .pdata 00039968..000399db. Semantic name remains unreviewed. */

void FUN_00039968(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if (*(int *)(param_1 + 0x40) == 1) {
    CVar1 = 0xff00;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_000375c4(param_1,param_2,0x56,0xc,0x1a,0xb4b4b4,CVar1,0,L"LOG",L"EVENT");
  return;
}



/* 000399dc FUN_000399dc */

/* Boundary evidence: original MIPS .pdata 000399dc..00039adf. Semantic name remains unreviewed. */

void FUN_000399dc(int param_1,HDC param_2)

{
  FUN_000375c4(param_1,param_2,0x52,0xc,0x1a,0xb4b4b4,0xffffff,0,L"PARAM",L"APPLY");
  FUN_000375c4(param_1,param_2,0x53,0xc,0x1a,0xb4b4b4,0xffffff,0,L"PARAM",L"SAVE");
  FUN_000375c4(param_1,param_2,0x54,0xc,0x1a,0xb4b4b4,0xffffff,0,L"PARAM",L"RESET");
  return;
}



/* 00039ae0 FUN_00039ae0 */

/* Boundary evidence: original MIPS .pdata 00039ae0..00039b57. Semantic name remains unreviewed. */

void FUN_00039ae0(int param_1,HDC param_2)

{
  wchar_t *pwVar1;
  
  if (*(int *)(param_1 + 0x98) == 1) {
    pwVar1 = L"MICOM";
  }
  else {
    pwVar1 = L"PC";
  }
  FUN_000375c4(param_1,param_2,0x57,0xc,0x1a,0xb4b4b4,0xffffff,0,L"GUI SELECT",pwVar1);
  return;
}



/* 00039b58 FUN_00039b58 */

/* Boundary evidence: original MIPS .pdata 00039b58..00039bcf. Semantic name remains unreviewed. */

void FUN_00039b58(int param_1,HDC param_2)

{
  LPCWSTR pWVar1;
  
  if (*(int *)(param_1 + 0x9c) == 1) {
    pWVar1 = L"ON";
  }
  else {
    pWVar1 = L"OFF";
  }
  FUN_000375c4(param_1,param_2,0x58,0xc,0x1a,0xb4b4b4,0xffffff,0,L"TUNER FREQ",pWVar1);
  return;
}



/* 00039bd0 FUN_00039bd0 */

/* Boundary evidence: original MIPS .pdata 00039bd0..00039c93. Semantic name remains unreviewed. */

void FUN_00039bd0(int param_1,HDC param_2)

{
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00064820;
  wsprintfW(aWStack_218,L"%d/%d/%d/%d/(%d)",(uint)*(byte *)(param_1 + 0x1c0),
            (uint)*(byte *)(param_1 + 0x1c1),(uint)*(byte *)(param_1 + 0x1c2),
            (uint)*(byte *)(param_1 + 0x1c3),(uint)*(byte *)(param_1 + 0x1c4));
  FUN_000375c4(param_1,param_2,0x19,0x10,0x1c,0xb4b4b4,0xffffff,0,L"RIATT/RGATT/MFATT/IFATT",
               aWStack_218);
  FUN_0004a3f4(local_18);
  return;
}



/* 00039c94 FUN_00039c94 */

/* Boundary evidence: original MIPS .pdata 00039c94..00039f7f. Semantic name remains unreviewed. */

void FUN_00039c94(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  RECT local_30;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  local_30.left = 0;
  local_30.top = 0;
  local_30.right = 800;
  local_30.bottom = 0x1e0;
  FUN_0003da78(param_1,hdc,&local_30,0);
  FUN_00038228(param_1,hdc);
  FUN_00038010(param_1,0,hdc);
  FUN_00038010(param_1,1,hdc);
  FUN_00038010(param_1,2,hdc);
  FUN_00038010(param_1,3,hdc);
  FUN_00038120(param_1,0,hdc);
  FUN_00038120(param_1,1,hdc);
  FUN_00038120(param_1,2,hdc);
  FUN_00038288(param_1,hdc);
  FUN_000382e8(param_1,hdc);
  FUN_00038348(param_1,hdc);
  FUN_0003719c(param_1,hdc,8,0x18,0xffffff,0,L"PST1");
  FUN_0003719c(param_1,hdc,9,0x18,0xffffff,0,L"VOL");
  FUN_000383a8(param_1,hdc);
  FUN_00037878(param_1,hdc);
  FUN_0003846c(param_1,hdc);
  FUN_0003856c(param_1,hdc);
  FUN_00038c1c(param_1,hdc);
  FUN_00039258(param_1,hdc);
  FUN_00039bd0(param_1,hdc);
  FUN_00038d0c(param_1,hdc);
  FUN_000394c8(param_1,hdc);
  FUN_000397a4(param_1,hdc);
  FUN_0003983c(param_1,hdc);
  FUN_00039898(param_1,hdc);
  FUN_000399dc(param_1,hdc);
  FUN_000398f4(param_1,hdc);
  FUN_00039968(param_1,hdc);
  FUN_00039ae0(param_1,hdc);
  FUN_00039b58(param_1,hdc);
  FUN_0003719c(param_1,hdc,0x59,0x20,0xffffff,0,L"EXIT");
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00039f80 FUN_00039f80 */

void FUN_00039f80(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = &DAT_0005d148;
  while ((((param_2 <= *piVar2 || (piVar2[2] <= param_2)) || (param_3 <= piVar2[1])) ||
         (piVar2[3] <= param_3))) {
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 4;
    if (0x59 < uVar1) {
      return;
    }
  }
  return;
}



/* 00039fec FUN_00039fec */

/* Boundary evidence: original MIPS .pdata 00039fec..0003a103. Semantic name remains unreviewed. */

void FUN_00039fec(int param_1)

{
  HDC pHVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x1ac);
  if (uVar2 == 9) {
    FUN_00013014(DAT_00064828,3);
  }
  else if (uVar2 == 0x4f) {
    if (0 < *(int *)(param_1 + 0x1bc)) {
      *(int *)(param_1 + 0x1bc) = *(int *)(param_1 + 0x1bc) + -1;
      pHVar1 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000397a4(param_1,pHVar1);
      ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar1);
    }
  }
  else if ((0x39 < uVar2) && (uVar2 < 0x46)) {
    *(char *)(uVar2 + param_1 + 0x166) = *(char *)(uVar2 + param_1 + 0x166) + -1;
    pHVar1 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_0003934c(param_1,*(int *)(param_1 + 0x1ac) + -0x3a,pHVar1);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar1);
    FUN_00014db0(DAT_000648e4,3,0xc0,param_1 + 0x1a0,0xc,0x32);
  }
  return;
}



/* 0003a104 FUN_0003a104 */

/* Boundary evidence: original MIPS .pdata 0003a104..0003a21f. Semantic name remains unreviewed. */

void FUN_0003a104(int param_1)

{
  HDC pHVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x1ac);
  if (uVar2 == 9) {
    FUN_00013014(DAT_00064828,2);
  }
  else if (uVar2 == 0x4f) {
    if (*(int *)(param_1 + 0x1bc) < 0xf) {
      *(int *)(param_1 + 0x1bc) = *(int *)(param_1 + 0x1bc) + 1;
      pHVar1 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000397a4(param_1,pHVar1);
      ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar1);
    }
  }
  else if ((0x39 < uVar2) && (uVar2 < 0x46)) {
    *(char *)(uVar2 + param_1 + 0x166) = *(char *)(uVar2 + param_1 + 0x166) + '\x01';
    pHVar1 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_0003934c(param_1,*(int *)(param_1 + 0x1ac) + -0x3a,pHVar1);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar1);
    FUN_00014db0(DAT_000648e4,3,0xc0,param_1 + 0x1a0,0xc,0x32);
  }
  return;
}



/* 0003a220 FUN_0003a220 */

/* Boundary evidence: original MIPS .pdata 0003a220..0003a2b3. Semantic name remains unreviewed. */

void FUN_0003a220(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_000450c0();
  if (DAT_00068568 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x9c8);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00068568 = (undefined4 *)0x0;
    }
    else {
      DAT_00068568 = FUN_00036f68(puVar1);
    }
    FUN_00044b7c((int)DAT_00068568,DAT_00064aac,param_1);
  }
  return;
}



/* 0003a2b4 Unwind@0003a2b4 */

/* Boundary evidence: original MIPS .pdata 0003a2b4..0003a2e3. Semantic name remains unreviewed. */

void Unwind_0003a2b4(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0003a2e4 FUN_0003a2e4 */

/* Boundary evidence: original MIPS .pdata 0003a2e4..0003a33b. Semantic name remains unreviewed. */

undefined4 * FUN_0003a2e4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0005d6f8;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003a33c FUN_0003a33c */

/* Boundary evidence: original MIPS .pdata 0003a33c..0003a467. Semantic name remains unreviewed. */

void FUN_0003a33c(int param_1)

{
  uint uVar1;
  HDC hDC;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar5;
  uint uVar6;
  
  memset((void *)(param_1 + 0x10),0,0x24);
  uVar6 = 0;
  do {
    uVar1 = FUN_000153dc(DAT_000648e4,3,3,(void *)(param_1 + 0x10),0x24,300);
    if (uVar1 == 0x24) break;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 3);
  if (uVar6 < 3) {
    hDC = GetDC(*(HWND *)(param_1 + 0xc));
    piVar5 = (int *)(param_1 + 0xa0);
    iVar3 = 0x20;
    piVar2 = piVar5;
    do {
      *piVar2 = 0;
      piVar2[0x20] = 0x1e;
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + 1;
    } while (iVar3 != 0);
    uVar6 = 0;
    if (*(char *)(param_1 + 0x12) != '\0') {
      do {
        pbVar4 = (byte *)(param_1 + 0x13 + uVar6);
        uVar6 = uVar6 + 1;
        *piVar5 = (*pbVar4 + 0x36b) * 100;
        piVar5 = piVar5 + 1;
      } while (uVar6 < *(byte *)(param_1 + 0x12));
    }
    FUN_00038d0c(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 0xc),hDC);
  }
  return;
}



/* 0003a468 FUN_0003a468 */

/* Boundary evidence: original MIPS .pdata 0003a468..0003aedf. Semantic name remains unreviewed. */

void FUN_0003a468(int param_1,UINT_PTR param_2)

{
  undefined2 uVar1;
  uint uVar2;
  HDC pHVar3;
  byte *pbVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  byte local_90;
  byte local_8f;
  byte local_8e;
  char local_8d;
  char local_8c;
  byte local_8b;
  byte local_8a;
  byte local_88;
  byte local_87;
  ushort local_84 [2];
  RECT local_80;
  short local_70;
  short local_6e;
  short local_6c;
  short local_6a;
  short local_68;
  short local_60;
  short local_5e;
  short local_5c;
  short local_5a;
  short local_58;
  byte local_50 [32];
  uint local_30;
  
  local_30 = DAT_00064820;
  switch(param_2) {
  case 100:
    FUN_00044f54(param_1,param_2);
    FUN_0003a33c(param_1);
    goto switchD_0003a4c8_default;
  case 0x65:
    if (*(int *)(param_1 + 0x98) == 1) {
      uVar2 = FUN_000153dc(DAT_000648e4,3,0xd0,&local_70,10,100);
      if (uVar2 == 10) {
        *(int *)(param_1 + 0x4c) = (int)local_68;
        *(int *)(param_1 + 0x50) = (int)local_70 / 0x147;
        *(int *)(param_1 + 0x54) = (int)local_6e / 200;
        if ((DAT_00067678 & 0x3000) == 0) {
          *(int *)(param_1 + 0x58) = (int)local_6c / 0x147;
        }
        else {
          *(int *)(param_1 + 0x58) = (int)local_6c;
        }
        *(int *)(param_1 + 0x5c) = (int)local_6a / 0x147;
      }
      if ((DAT_00067678 & 0x3000) == 0) {
        uVar2 = FUN_000153dc(DAT_000648e4,2,0x10070,&local_90,3,100);
        if (uVar2 == 3) {
          *(uint *)(param_1 + 0x60) = (uint)local_8e;
        }
        uVar2 = FUN_000153dc(DAT_000648e4,2,0x31030,&local_90,2,100);
        if (uVar2 == 2) {
          iVar5 = ((int)((uint)local_90 << 0x18) >> 0x10 | (uint)local_8f) * 100;
          iVar7 = iVar5 + 0x3ff;
          if (iVar7 < 0) {
            iVar7 = iVar5 + 0xbfe;
          }
          *(int *)(param_1 + 100) = iVar7 >> 0xb;
        }
        uVar2 = FUN_000153dc(DAT_000648e4,2,0x3102b,&local_90,2,100);
        if (uVar2 == 2) {
          iVar5 = ((int)((uint)local_90 << 0x18) >> 0x10 | (uint)local_8f) * 100;
          iVar7 = iVar5 + 0x3ff;
          if (iVar7 < 0) {
            iVar7 = iVar5 + 0xbfe;
          }
          *(int *)(param_1 + 0x68) = iVar7 >> 0xb;
        }
        uVar2 = FUN_000153dc(DAT_000648e4,2,0x31020,&local_90,2,100);
        if (uVar2 == 2) {
          iVar5 = ((int)((uint)local_90 << 0x18) >> 0x10 | (uint)local_8f) * 100;
          iVar7 = iVar5 + 0x3ff;
          if (iVar7 < 0) {
            iVar7 = iVar5 + 0xbfe;
          }
          *(int *)(param_1 + 0x6c) = iVar7 >> 0xb;
        }
      }
      else {
        uVar2 = FUN_000153dc(DAT_000648e4,2,0x100ce,&local_88,3,100);
        if (uVar2 == 3) {
          *(int *)(param_1 + 100) =
               (int)((int)((uint)local_88 << 0x18) >> 0x10 | (uint)local_87) / 0x148;
        }
        *(undefined4 *)(param_1 + 0x60) = 0;
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x6c) = 0;
      }
      uVar2 = FUN_000153dc(DAT_000648e4,0xb,0xd4,&local_60,10,100);
      if (uVar2 == 10) {
        *(int *)(param_1 + 0x70) = (int)local_58;
        *(int *)(param_1 + 0x74) = (int)local_60 / 0x147;
        *(int *)(param_1 + 0x78) = (int)local_5e / 200;
        *(int *)(param_1 + 0x7c) = (int)local_5c / 0x147;
        *(int *)(param_1 + 0x80) = (int)local_5a / 0x147;
        uVar1 = FUN_00034680();
        *(undefined2 *)(param_1 + 0x84) = uVar1;
        uVar1 = FUN_0003468c();
        *(undefined2 *)(param_1 + 0x86) = uVar1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(undefined4 *)(param_1 + 100) = 0;
      *(undefined4 *)(param_1 + 0x70) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x78) = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
    uVar2 = FUN_000153dc(DAT_000648e4,9,5,local_84,2,100);
    if (uVar2 == 2) {
      *(uint *)(param_1 + 0x90) =
           ((uint)local_84[0] - (uint)*(ushort *)(param_1 + 0x94) & 0xffff) +
           *(int *)(param_1 + 0x90);
      *(ushort *)(param_1 + 0x94) = local_84[0];
    }
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    if (*(int *)(param_1 + 0x98) == 1) {
      FUN_00039258(param_1,pHVar3);
      FUN_000395bc(param_1,0,pHVar3);
      FUN_000395bc(param_1,1,pHVar3);
      FUN_000395bc(param_1,2,pHVar3);
      FUN_000395bc(param_1,3,pHVar3);
      FUN_000395bc(param_1,4,pHVar3);
      FUN_000395bc(param_1,5,pHVar3);
      FUN_000395bc(param_1,6,pHVar3);
    }
    FUN_000383a8(param_1,pHVar3);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar3);
    if (*(int *)(param_1 + 0x34) != 0) {
      uVar2 = FUN_00029158(DAT_000673c8);
      fprintf(*(FILE **)(param_1 + 0x34),"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
              *(uint *)(param_1 + 0x90) / 5,uVar2 / 100,*(undefined4 *)(param_1 + 0x4c),
              *(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
              *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
              *(undefined4 *)(param_1 + 0x60));
    }
    goto switchD_0003a4c8_default;
  case 0x66:
    if ((DAT_00067678 & 0x3000) != 0) goto switchD_0003a4c8_default;
    uVar2 = FUN_000153dc(DAT_000648e4,3,0xd1,local_50,0x20,100);
    if (uVar2 == 0x20) {
      iVar5 = 0;
      puVar6 = (uint *)(param_1 + 0x120);
      do {
        pbVar4 = local_50 + iVar5;
        iVar5 = iVar5 + 1;
        *puVar6 = (uint)*pbVar4;
        puVar6 = puVar6 + 1;
      } while (iVar5 < 0x20);
    }
    FUN_000153dc(DAT_000648e4,3,0x12,(void *)(param_1 + 0x44),4,100);
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00038d0c(param_1,pHVar3);
    break;
  case 0x67:
    uVar2 = FUN_000153dc(DAT_000648e4,3,0xd3,(void *)(param_1 + 0x48),1,100);
    if (uVar2 != 1) goto switchD_0003a4c8_default;
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00037878(param_1,pHVar3);
    break;
  case 0x68:
    FUN_00044f54(param_1,0x68);
    *(undefined4 *)(param_1 + 0x1b4) = 0x5a;
    local_80.left = 0;
    local_80.top = 0;
    local_80.right = 800;
    local_80.bottom = 0x1e0;
    InvalidateRect(*(HWND *)(param_1 + 0xc),&local_80,0);
    goto switchD_0003a4c8_default;
  case 0x69:
    FUN_00044f54(param_1,0x69);
    FUN_00015158(DAT_000648e4,3,1,0xe1,0,0,1000);
    FUN_00015158(DAT_000648e4,3,1,0xe0,0,0,1000);
    FUN_00015158(DAT_000648e4,3,1,0xe2,0,0,100);
    FUN_000153dc(DAT_000648e4,3,0xc0,(void *)(param_1 + 0x1a0),0xc,0x32);
    goto LAB_0003abac;
  case 0x6a:
    FUN_00044f54(param_1,0x6a);
    FUN_00015158(DAT_000648e4,3,1,0xe0,0,0,1000);
    FUN_00015158(DAT_000648e4,3,1,0xe2,0,0,100);
    FUN_000153dc(DAT_000648e4,3,0xc0,(void *)(param_1 + 0x1a0),0xc,0x32);
LAB_0003abac:
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_0003934c(param_1,0,pHVar3);
    FUN_0003934c(param_1,1,pHVar3);
    FUN_0003934c(param_1,2,pHVar3);
    FUN_0003934c(param_1,3,pHVar3);
    FUN_0003934c(param_1,4,pHVar3);
    FUN_0003934c(param_1,5,pHVar3);
    FUN_0003934c(param_1,6,pHVar3);
    FUN_0003934c(param_1,7,pHVar3);
    FUN_0003934c(param_1,8,pHVar3);
    break;
  case 0x6b:
    if ((*(int *)(param_1 + 0x34) == 0) && (*(int *)(param_1 + 0x38) == 0))
    goto switchD_0003a4c8_default;
    *(uint *)(param_1 + 0x40) = (uint)(*(int *)(param_1 + 0x40) == 0);
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    if (*(int *)(param_1 + 0x34) != 0) {
      FUN_000398f4(param_1,pHVar3);
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      FUN_00039968(param_1,pHVar3);
    }
    break;
  case 0x6c:
    uVar2 = FUN_000153dc(DAT_000648e4,2,0x10000c0,&local_8c,3,100);
    if (uVar2 == 3) {
      *(byte *)(param_1 + 0x1c0) = local_8a >> 5;
      *(char *)(param_1 + 0x1c1) = (char)((local_8a & 0x1c) >> 2);
      *(byte *)(param_1 + 0x1c2) = local_8a & 1;
      *(char *)(param_1 + 0x1c3) = (char)((local_8b & 0xc) >> 2);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00039bd0(param_1,pHVar3);
      ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar3);
    }
    uVar2 = FUN_000153dc(DAT_000648e4,2,0x312a0,&local_8c,2,100);
    if (uVar2 == 2) {
      if ((local_8c == '\0') && (local_8b == 0)) {
        *(undefined1 *)(param_1 + 0x1c4) = 0;
      }
      else if ((local_8c == '\a') && (local_8b == 0xff)) {
        *(undefined1 *)(param_1 + 0x1c4) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x1c4) = 2;
      }
    }
    goto switchD_0003a4c8_default;
  case 0x6d:
    uVar2 = FUN_000153dc(DAT_000648e4,4,0x40,&local_8d,1,100);
    if ((uVar2 != 1) || (local_8d == *(char *)(param_1 + 0x88))) goto switchD_0003a4c8_default;
    *(char *)(param_1 + 0x88) = local_8d;
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00038c1c(param_1,pHVar3);
    break;
  default:
    goto switchD_0003a4c8_default;
  }
  ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar3);
switchD_0003a4c8_default:
  FUN_0004a3f4(local_30);
  return;
}



/* 0003aee0 FUN_0003aee0 */

/* Boundary evidence: original MIPS .pdata 0003aee0..0003b4cf. Semantic name remains unreviewed. */

void FUN_0003aee0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  HDC pHVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_2 == 0) {
    pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00037878(param_1,pHVar2);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar2);
    FUN_00044f38(param_1,100,1000,(TIMERPROC)0x0);
  }
  else {
    if (param_2 == 5) {
      pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_0003846c(param_1,pHVar2);
    }
    else if (param_2 == 6) {
      *(undefined4 *)(param_1 + 0x8c) = param_3;
      pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_0003856c(param_1,pHVar2);
    }
    else {
      if (param_2 != 0xb) {
        return;
      }
      iVar3 = *(int *)(param_1 + 0x1b8) + 1;
      *(int *)(param_1 + 0x1b8) = iVar3;
      if (0xf < iVar3) {
        iVar3 = 0xf;
        pcVar4 = (char *)(param_1 + 0x1c5);
        do {
          strcpy_s(pcVar4,0x80,pcVar4 + 0x80);
          iVar3 = iVar3 + -1;
          pcVar4 = pcVar4 + 0x80;
        } while (iVar3 != 0);
        *(int *)(param_1 + 0x1b8) = *(int *)(param_1 + 0x1b8) + -1;
      }
      pcVar4 = (char *)(*(int *)(param_1 + 0x1b8) * 0x80 + param_1 + 0x1c5);
      switch(*(undefined1 *)(DAT_000673c8 + 0x3a)) {
      case 0:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : %sAF Jump(without PI check) Success - from %d(%d) to %d(%d)")
        ;
        break;
      case 1:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : %sAF Jump(with PI check) Success - %d(%d) -> %d(%d)");
        break;
      case 2:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : AF Jump Success(Old Recent Freq) - %d(%d) -> %d(%d)");
        break;
      case 3:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : AF Jump Fail(PI Check error) - %d(%d) -> %d(%d)");
        break;
      case 4:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : AF Jump Fail(Wrong PI) - %d(%d) -> %d(%d)");
        break;
      case 5:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,
                  "%4.2f : Emergency AF Jump Success(Old Recent Freq) - %d(%d) -> %d(%d)");
        break;
      case 6:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : PI(Regional) changed - %04X -> %04X");
        break;
      case 7:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : PI(Wrong) changed - %04X -> %04X");
        break;
      case 8:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x90));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : Return to Last Freq - %d -> %d");
      }
      if (*(FILE **)(param_1 + 0x38) != (FILE *)0x0) {
        fprintf(*(FILE **)(param_1 + 0x38),"%s\n",pcVar4);
      }
      *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1b8);
      pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000397a4(param_1,pHVar2);
    }
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar2);
  }
  return;
}



/* 0003b4d0 FUN_0003b4d0 */

/* Boundary evidence: original MIPS .pdata 0003b4d0..0003be4f. Semantic name remains unreviewed. */

void FUN_0003b4d0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  HDC pHVar3;
  errno_t eVar4;
  wchar_t *pwVar5;
  undefined4 uVar6;
  UINT_PTR UVar7;
  char *pcVar8;
  RECT *lpRect;
  undefined4 uVar9;
  UINT UVar10;
  code *pcVar11;
  int iVar12;
  int *piVar13;
  FILE **_File;
  uint uVar14;
  undefined1 *puVar15;
  undefined1 local_4a8;
  undefined1 local_4a7;
  undefined1 local_4a6;
  undefined1 local_4a5;
  undefined1 local_4a4;
  undefined1 local_4a3;
  undefined1 local_4a2;
  undefined1 local_4a1;
  undefined1 local_4a0;
  undefined1 local_49e;
  undefined1 local_49d;
  undefined1 local_49c;
  FILE *local_498 [2];
  RECT local_490;
  RECT local_480;
  RECT local_470;
  char acStack_460 [64];
  undefined1 auStack_420 [1024];
  uint local_20;
  
  local_20 = DAT_00064820;
  uVar2 = FUN_00039f80(param_1,param_2,param_3);
  if (uVar2 < 0x3a) {
    if (uVar2 == 0x39) {
      iVar12 = *(int *)(param_1 + 0x1b0);
      *(int *)(param_1 + 0x1b0) = iVar12 + 1;
      if (0x1f < iVar12 + 0x20U) {
        *(undefined4 *)(param_1 + 0x1b0) = 0;
      }
switchD_0003b544_caseD_b:
      FUN_0003a33c(param_1);
      goto LAB_0003be28;
    }
    switch(uVar2) {
    case 0:
      (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x65,(DAT_00067678 & 0x3000) == 0);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00038228(param_1,pHVar3);
      break;
    case 1:
      uVar9 = 1;
      goto LAB_0003b638;
    case 2:
      uVar9 = 1;
      goto LAB_0003b690;
    case 3:
      uVar9 = 0;
LAB_0003b690:
      uVar6 = 0x6b;
      goto LAB_0003b63c;
    case 4:
      uVar9 = 0;
LAB_0003b638:
      uVar6 = 0x6a;
LAB_0003b63c:
      (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,uVar6,uVar9);
      *(undefined4 *)(param_1 + 0x8c) = 0;
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_0003846c(param_1,pHVar3);
      FUN_0003856c(param_1,pHVar3);
      break;
    case 5:
      if ((DAT_00067678 & 8) == 0) {
        DAT_00067678 = DAT_00067678 | 8;
      }
      else {
        DAT_00067678 = DAT_00067678 & 0xfffffff7;
      }
      local_4a4 = (DAT_00067678 & 8) == 8;
      FUN_00014db0(DAT_000648e4,3,0,(int)&local_4a4,1,0x32);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00038288(param_1,pHVar3);
      break;
    case 6:
      if ((DAT_00067678 & 0x20) == 0) {
        DAT_00067678 = DAT_00067678 | 0x20;
      }
      else {
        DAT_00067678 = DAT_00067678 & 0xffffffdf;
      }
      local_4a6 = (DAT_00067678 & 0x20) == 0x20;
      FUN_00014db0(DAT_000648e4,3,1,(int)&local_4a6,1,0x32);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000382e8(param_1,pHVar3);
      break;
    case 7:
      bVar1 = (DAT_00067678 & 4) != 0;
      if (bVar1) {
        pcVar11 = *(code **)(*DAT_000673c8 + 8);
      }
      else {
        pcVar11 = *(code **)(*DAT_000673c8 + 8);
      }
      (*pcVar11)(DAT_000673c8,0x81,!bVar1);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00038348(param_1,pHVar3);
      break;
    case 8:
      (**(code **)(*DAT_000673c8 + 8))(DAT_000673c8,0x6f,0);
      goto LAB_0003be28;
    case 9:
      *(undefined4 *)(param_1 + 0x1ac) = 9;
      local_470.left = 0;
      local_470.top = 0;
      local_470.right = 800;
      lpRect = &local_470;
      local_470.bottom = 0x1e0;
      goto LAB_0003be1c;
    case 10:
      *(undefined4 *)(param_1 + 0x90) = 0;
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000383a8(param_1,pHVar3);
      break;
    case 0xb:
      goto switchD_0003b544_caseD_b;
    default:
      goto switchD_0003b544_default;
    }
    goto LAB_0003b5b4;
  }
  switch(uVar2) {
  case 0x4c:
    uVar2 = FUN_000153dc(DAT_000648e4,0xb,0xd5,&local_4a2,3,100);
    if (uVar2 != 2) goto LAB_0003be28;
    local_4a0 = 0;
    FUN_00015158(DAT_000648e4,0xb,1,0x73,(int)&local_4a2,3,0x32);
    pwVar5 = L"[[[ TMC_TEST_MODE ]]]]   CMD_TMC_SCAN_DOWN   [%d]\r\n";
    local_49e = local_4a2;
    local_49d = local_4a1;
    goto LAB_0003b920;
  case 0x4d:
    uVar2 = FUN_000153dc(DAT_000648e4,0xb,0xd5,&local_49e,3,100);
    if (uVar2 != 2) goto LAB_0003be28;
    local_49c = 1;
    FUN_00015158(DAT_000648e4,0xb,1,0x73,(int)&local_49e,3,0x32);
    pwVar5 = L"[[[ TMC_TEST_MODE ]]]]   CMD_TMC_SCAN_UP  [%d]\r\n";
LAB_0003b920:
    uVar2 = (uint)CONCAT11(local_49d,local_49e);
LAB_0003b924:
    NKDbgPrintfW(pwVar5,uVar2);
    goto LAB_0003be28;
  case 0x4e:
    iVar12 = FUN_0003469c(DAT_00068464);
    if (iVar12 == 0) {
      FUN_000346a4(DAT_00068464,1);
      uVar2 = FUN_0003469c(DAT_00068464);
      pwVar5 = L"[[[ TMC_TEST_MODE ]]]]   NNG IPC ON   %d  Mode\r\n";
    }
    else {
      FUN_000346a4(DAT_00068464,0);
      uVar2 = FUN_0003469c(DAT_00068464);
      pwVar5 = L"[[[ TMC_TEST_MODE ]]]]   NNG IPC OFF %d  Mode\r\n";
    }
    goto LAB_0003b924;
  case 0x4f:
    *(undefined4 *)(param_1 + 0x1ac) = 0x4f;
    local_490.left = 0;
    local_490.top = 0;
    local_490.right = 800;
    lpRect = &local_490;
    local_490.bottom = 0x1e0;
    goto LAB_0003be1c;
  case 0x50:
    FUN_00030d6c(DAT_00067670);
    goto LAB_0003be28;
  default:
switchD_0003b544_default:
    if ((0x19 < uVar2) && (uVar2 < 0x39)) {
      piVar13 = (int *)((uVar2 + 0xe) * 4 + param_1);
      if (*piVar13 != 0) {
        FUN_00015158(DAT_000648e4,3,1,0xf1,(int)piVar13,4,0x1e);
      }
      goto LAB_0003be28;
    }
    if ((uVar2 < 0x3a) || (0x45 < uVar2)) goto LAB_0003be28;
    *(uint *)(param_1 + 0x1ac) = uVar2;
    local_480.left = 0;
    local_480.top = 0;
    lpRect = &local_480;
    local_480.right = 800;
    local_480.bottom = 0x1e0;
LAB_0003be1c:
    InvalidateRect(*(HWND *)(param_1 + 0xc),lpRect,0);
    goto LAB_0003be28;
  case 0x52:
  case 0x53:
  case 0x54:
    *(uint *)(param_1 + 0x1b4) = uVar2;
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_000399dc(param_1,pHVar3);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar3);
    FUN_00044f38(param_1,0x68,500,(TIMERPROC)0x0);
    if (uVar2 == 0x54) {
      pcVar8 = ".\\Storage Card\\system\\radparam.bin";
    }
    else {
      pcVar8 = ".\\Storage Card\\ULC_RAD_PARAM.bin";
    }
    strcpy_s(acStack_460,0x40,pcVar8);
    eVar4 = fopen_s(local_498,acStack_460,"rb");
    if (eVar4 != 0) goto LAB_0003be28;
    fread(auStack_420,0x400,1,local_498[0]);
    fclose(local_498[0]);
    uVar14 = 0;
    puVar15 = auStack_420;
    do {
      FUN_00014db0(DAT_000648e4,3,uVar14 + 0xe0,(int)puVar15,0x80,300);
      uVar14 = uVar14 + 1;
      puVar15 = puVar15 + 0x80;
    } while (uVar14 < 8);
    UVar10 = 0x96;
    UVar7 = 0x69;
    if (uVar2 == 0x52) {
      UVar7 = 0x6a;
    }
    goto LAB_0003bc54;
  case 0x55:
    if ((*(int *)(param_1 + 0x98) != 1) || (*(int *)(param_1 + 0x38) != 0)) goto LAB_0003be28;
    _File = (FILE **)(param_1 + 0x34);
    if (*_File != (FILE *)0x0) {
      fclose(*_File);
      FUN_00044f54(param_1,0x6b);
      *_File = (FILE *)0x0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000398f4(param_1,pHVar3);
      break;
    }
    pcVar8 = "\\Storage Card\\qlog.txt";
LAB_0003ba38:
    eVar4 = fopen_s(_File,pcVar8,"wt");
    if (eVar4 != 0) {
      *_File = (FILE *)0x0;
      goto LAB_0003be28;
    }
    UVar10 = 500;
    UVar7 = 0x6b;
LAB_0003bc54:
    FUN_00044f38(param_1,UVar7,UVar10,(TIMERPROC)0x0);
    goto LAB_0003be28;
  case 0x56:
    if ((*(int *)(param_1 + 0x98) != 1) || (*(int *)(param_1 + 0x34) != 0)) goto LAB_0003be28;
    _File = (FILE **)(param_1 + 0x38);
    if (*_File == (FILE *)0x0) {
      pcVar8 = "\\Storage Card\\evtlog.txt";
      goto LAB_0003ba38;
    }
    fclose(*_File);
    FUN_00044f54(param_1,0x6b);
    *_File = (FILE *)0x0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00039968(param_1,pHVar3);
    break;
  case 0x57:
    if (*(int *)(param_1 + 0x34) != 0) goto LAB_0003be28;
    if (*(int *)(param_1 + 0x98) == 1) {
      local_4a8 = 1;
      FUN_00014db0(DAT_000648e4,0,0x30,(int)&local_4a8,1,0x32);
      *(undefined4 *)(param_1 + 0x98) = 0;
    }
    else {
      local_4a7 = 0;
      FUN_00014db0(DAT_000648e4,0,0x30,(int)&local_4a7,1,0x32);
      *(undefined4 *)(param_1 + 0x98) = 1;
    }
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00039ae0(param_1,pHVar3);
    break;
  case 0x58:
    if (*(int *)(param_1 + 0x9c) == 0) {
      local_4a5 = 1;
      FUN_00014db0(DAT_000648e4,0,0x31,(int)&local_4a5,1,0x32);
      *(undefined4 *)(param_1 + 0x9c) = 1;
    }
    else {
      local_4a3 = 0;
      FUN_00014db0(DAT_000648e4,0,0x31,(int)&local_4a3,1,0x32);
      *(undefined4 *)(param_1 + 0x9c) = 0;
    }
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00039b58(param_1,pHVar3);
    break;
  case 0x59:
    DestroyWindow(*(HWND *)(param_1 + 0xc));
    goto LAB_0003be28;
  }
LAB_0003b5b4:
  ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar3);
LAB_0003be28:
  FUN_0004a3f4(local_20);
  return;
}



/* 0003be50 FUN_0003be50 */

/* Boundary evidence: original MIPS .pdata 0003be50..0003bf8b. Semantic name remains unreviewed. */

void FUN_0003be50(int param_1)

{
  undefined1 local_20 [8];
  
  local_20[0] = 1;
  *(undefined4 *)(DAT_000673c8 + 0x5c) = *(undefined4 *)(param_1 + 0xc);
  FUN_000153dc(DAT_000648e4,3,0xc0,(void *)(param_1 + 0x1a0),0xc,0x32);
  FUN_000153dc(DAT_000648e4,9,5,(void *)(param_1 + 0x94),2,100);
  FUN_00014db0(DAT_000648e4,3,0xf0,(int)local_20,1,0x32);
  FUN_0003a33c(param_1);
  FUN_00044f38(param_1,0x65,0xfa,(TIMERPROC)0x0);
  if ((DAT_00067678 & 0x3000) == 0) {
    FUN_00044f38(param_1,0x66,0x14a,(TIMERPROC)0x0);
    FUN_00044f38(param_1,0x67,300,(TIMERPROC)0x0);
    FUN_00044f38(param_1,0x6c,1000,(TIMERPROC)0x0);
    FUN_00044f38(param_1,0x6d,1000,(TIMERPROC)0x0);
  }
  return;
}



/* 0003bf8c FUN_0003bf8c */

/* Boundary evidence: original MIPS .pdata 0003bf8c..0003c00b. Semantic name remains unreviewed. */

undefined4 * FUN_0003bf8c(undefined4 *param_1)

{
  FUN_00044b4c(param_1);
  *param_1 = &PTR_FUN_0005e008;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0x37;
  return param_1;
}



/* 0003c00c FUN_0003c00c */

/* Boundary evidence: original MIPS .pdata 0003c00c..0003c06b. Semantic name remains unreviewed. */

void FUN_0003c00c(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00064820;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00064ae4 + 0xaf5) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x2c),aWStack_30);
  FUN_0004a3f4(local_10);
  return;
}



/* 0003c06c FUN_0003c06c */

/* Boundary evidence: original MIPS .pdata 0003c06c..0003c0cb. Semantic name remains unreviewed. */

void FUN_0003c06c(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00064820;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00064ae4 + 0xaf4) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x30),aWStack_30);
  FUN_0004a3f4(local_10);
  return;
}



/* 0003c0cc FUN_0003c0cc */

/* Boundary evidence: original MIPS .pdata 0003c0cc..0003c12b. Semantic name remains unreviewed. */

void FUN_0003c0cc(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00064820;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00064ae4 + 0xaf6) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x34),aWStack_30);
  FUN_0004a3f4(local_10);
  return;
}



/* 0003c12c FUN_0003c12c */

/* Boundary evidence: original MIPS .pdata 0003c12c..0003c18b. Semantic name remains unreviewed. */

void FUN_0003c12c(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00064820;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00064ae4 + 0xaf7) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x38),aWStack_30);
  FUN_0004a3f4(local_10);
  return;
}



/* 0003c18c FUN_0003c18c */

/* Boundary evidence: original MIPS .pdata 0003c18c..0003c1eb. Semantic name remains unreviewed. */

void FUN_0003c18c(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00064820;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00064ae4 + 0xaf8) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x3c),aWStack_30);
  FUN_0004a3f4(local_10);
  return;
}



/* 0003c1ec FUN_0003c1ec */

/* Boundary evidence: original MIPS .pdata 0003c1ec..0003c243. Semantic name remains unreviewed. */

undefined4 * FUN_0003c1ec(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0005e008;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003c244 FUN_0003c244 */

/* Boundary evidence: original MIPS .pdata 0003c244..0003cb8b. Semantic name remains unreviewed. */

void FUN_0003c244(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  HWND pHVar3;
  undefined4 auStack_78 [8];
  undefined1 local_58;
  undefined1 local_57;
  WCHAR aWStack_50 [16];
  uint local_30;
  
  local_30 = DAT_00064820;
  uVar1 = FUN_00044f30();
  uVar2 = FUN_00044f28();
  FUN_0003f5e0(auStack_78,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar2,uVar1);
  FUN_0003f6bc(auStack_78,1,L"LOAD EOL FILE",6,(HMENU)0x1);
  FUN_0003f614((int)auStack_78,0);
  FUN_0003f6bc(auStack_78,0,L"AUDIO SOURCE",0,(HMENU)0x0);
  FUN_0003f6bc(auStack_78,1,L"RADIO",2,(HMENU)0x2);
  FUN_0003f6bc(auStack_78,1,L"DAB",2,(HMENU)0x3);
  FUN_0003f6bc(auStack_78,1,L"AUX",2,(HMENU)0x4);
  FUN_0003f6bc(auStack_78,1,L"USB",2,(HMENU)0x5);
  FUN_0003f6bc(auStack_78,1,L"IPOD",2,(HMENU)0x6);
  pHVar3 = FUN_0003f6bc(auStack_78,1,L"CALL\r\n(OFF)",2,(HMENU)0x7);
  *(HWND *)(param_1 + 0x14) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_78,1,L"NAVI\r\n(OFF)",2,(HMENU)0x8);
  *(HWND *)(param_1 + 0x20) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_78,1,L"SIRI\r\n(OFF)",2,(HMENU)0x9);
  *(HWND *)(param_1 + 0x24) = pHVar3;
  FUN_0003f614((int)auStack_78,0);
  FUN_0003f6bc(auStack_78,0,L"Sound",0,(HMENU)0x0);
  FUN_0003f6bc(auStack_78,1,L"BALANCE",4,(HMENU)0x0);
  FUN_0003f614((int)auStack_78,1);
  FUN_0003f6bc(auStack_78,1,L"-",2,(HMENU)0xb);
  pHVar3 = FUN_0003f6bc(auStack_78,2,L"",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x2c) = pHVar3;
  FUN_0003f6bc(auStack_78,1,L"+",2,(HMENU)0xc);
  FUN_0003f674((int)auStack_78);
  FUN_0003f6bc(auStack_78,1,L"FADER",4,(HMENU)0x0);
  FUN_0003f614((int)auStack_78,1);
  FUN_0003f6bc(auStack_78,1,L"-",2,(HMENU)0xd);
  pHVar3 = FUN_0003f6bc(auStack_78,2,L"",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x30) = pHVar3;
  FUN_0003f6bc(auStack_78,1,L"+",2,(HMENU)0xe);
  FUN_0003f674((int)auStack_78);
  FUN_0003f6bc(auStack_78,1,L"BASS",4,(HMENU)0x0);
  FUN_0003f614((int)auStack_78,1);
  FUN_0003f6bc(auStack_78,1,L"-",2,(HMENU)0xf);
  pHVar3 = FUN_0003f6bc(auStack_78,2,L"",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x34) = pHVar3;
  FUN_0003f6bc(auStack_78,1,L"+",2,(HMENU)0x10);
  FUN_0003f674((int)auStack_78);
  FUN_0003f6bc(auStack_78,1,L"MID",4,(HMENU)0x0);
  FUN_0003f614((int)auStack_78,1);
  FUN_0003f6bc(auStack_78,1,L"-",2,(HMENU)0x11);
  pHVar3 = FUN_0003f6bc(auStack_78,2,L"",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x38) = pHVar3;
  FUN_0003f6bc(auStack_78,1,L"+",2,(HMENU)0x12);
  FUN_0003f674((int)auStack_78);
  FUN_0003f6bc(auStack_78,1,L"TREBLE",4,(HMENU)0x0);
  FUN_0003f614((int)auStack_78,1);
  FUN_0003f6bc(auStack_78,1,L"-",2,(HMENU)0x13);
  pHVar3 = FUN_0003f6bc(auStack_78,2,L"",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x3c) = pHVar3;
  FUN_0003f6bc(auStack_78,1,L"+",2,(HMENU)0x14);
  FUN_0003f69c((int)auStack_78);
  if ((DAT_00067678 & 2) == 0) {
    pHVar3 = FUN_0003f6bc(auStack_78,1,L"MIC(INT)",4,(HMENU)0x0);
  }
  else {
    pHVar3 = FUN_0003f6bc(auStack_78,1,L"MIC(EXT)",4,(HMENU)0x0);
  }
  *(HWND *)(param_1 + 0x40) = pHVar3;
  FUN_0003f614((int)auStack_78,1);
  FUN_0003f6bc(auStack_78,1,L"INTERNAL",4,(HMENU)0x15);
  FUN_0003f6bc(auStack_78,1,L"EXTERNAL",4,(HMENU)0x16);
  FUN_0003f614((int)auStack_78,0);
  FUN_0003f6bc(auStack_78,1,L"LOUDNESS",4,(HMENU)0x0);
  FUN_0003f614((int)auStack_78,1);
  FUN_0003f6bc(auStack_78,1,L"ON",2,(HMENU)0x17);
  FUN_0003f6bc(auStack_78,1,L"OFF",2,(HMENU)0x18);
  FUN_0003f614((int)auStack_78,0);
  FUN_0003f6bc(auStack_78,1,L"SDVC",2,(HMENU)0x0);
  FUN_0003f614((int)auStack_78,1);
  FUN_0003f6bc(auStack_78,1,L"0",2,(HMENU)0x19);
  FUN_0003f6bc(auStack_78,1,L"1",2,(HMENU)0x1a);
  FUN_0003f6bc(auStack_78,1,L"2",2,(HMENU)0x1b);
  FUN_0003f6bc(auStack_78,1,L"3",2,(HMENU)0x1c);
  FUN_0003f6bc(auStack_78,1,L"4",2,(HMENU)0x1d);
  FUN_0003f6bc(auStack_78,1,L"5",2,(HMENU)0x1e);
  FUN_0003f674((int)auStack_78);
  pHVar3 = FUN_0003f6bc(auStack_78,1,L"REC MICIN\r\n(OFF)",4,(HMENU)0x21);
  *(HWND *)(param_1 + 0x50) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_78,1,L"REC MICOUT\r\n(OFF)",4,(HMENU)0x22);
  *(HWND *)(param_1 + 0x58) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_78,1,L"REC RECVIN\r\n(OFF)",4,(HMENU)0x23);
  *(HWND *)(param_1 + 0x60) = pHVar3;
  FUN_0003f674((int)auStack_78);
  FUN_0003f6bc(auStack_78,0,L"Volume(Call channel)",0,(HMENU)0x0);
  FUN_0003f6bc(auStack_78,1,L"-",2,(HMENU)0x1f);
  pHVar3 = FUN_0003f6bc(auStack_78,2,L"",4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x44) = pHVar3;
  wsprintfW(aWStack_50,L"0x%04X",*(undefined4 *)(param_1 + 0x48));
  SetWindowTextW(*(HWND *)(param_1 + 0x44),aWStack_50);
  local_58 = *(undefined1 *)(param_1 + 0x49);
  local_57 = (undefined1)*(undefined4 *)(param_1 + 0x48);
  FUN_00014db0(DAT_000648e4,2,0xd1086,(int)&local_58,2,100);
  FUN_0003f6bc(auStack_78,1,L"+",2,(HMENU)0x20);
  FUN_0003f674((int)auStack_78);
  FUN_0003f6bc(auStack_78,0,L"CHIME",0,(HMENU)0x0);
  FUN_0003f6bc(auStack_78,1,L"0",2,(HMENU)0x24);
  FUN_0003f6bc(auStack_78,1,L"1",2,(HMENU)0x25);
  FUN_0003f6bc(auStack_78,1,L"2",2,(HMENU)0x26);
  FUN_0003f6bc(auStack_78,1,L"3",2,(HMENU)0x27);
  FUN_0003f6bc(auStack_78,1,L"4",2,(HMENU)0x28);
  FUN_0003f6bc(auStack_78,1,L"5",2,(HMENU)0x29);
  FUN_0003f674((int)auStack_78);
  FUN_0003c00c(param_1);
  FUN_0003c06c(param_1);
  FUN_0003c0cc(param_1);
  FUN_0003c12c(param_1);
  FUN_0003c18c(param_1);
  FUN_00036f60();
  FUN_0004a3f4(local_30);
  return;
}



/* 0003cb8c Unwind@0003cb8c */

/* Boundary evidence: original MIPS .pdata 0003cb8c..0003cbbb. Semantic name remains unreviewed. */

void Unwind_0003cb8c(void)

{
  FUN_00036f60();
  return;
}



/* 0003cbbc FUN_0003cbbc */

/* Boundary evidence: original MIPS .pdata 0003cbbc..0003d55b. Semantic name remains unreviewed. */

void FUN_0003cbbc(int param_1,int param_2)

{
  errno_t eVar1;
  long lVar2;
  uint uVar3;
  LPCWSTR lpString;
  int iVar4;
  undefined4 *puVar5;
  char cVar6;
  undefined1 *puVar7;
  code *pcVar8;
  FILE *local_5a8;
  char local_5a4 [5];
  undefined1 local_59f;
  undefined1 local_59e;
  undefined1 local_59d;
  undefined1 local_59c [4];
  WCHAR aWStack_598 [16];
  WCHAR aWStack_578 [16];
  WCHAR aWStack_558 [16];
  WCHAR aWStack_538 [16];
  WCHAR aWStack_518 [16];
  WCHAR aWStack_4f8 [16];
  WCHAR aWStack_4d8 [32];
  WCHAR aWStack_498 [32];
  WCHAR aWStack_458 [32];
  undefined1 local_418 [1024];
  uint local_18;
  
  local_18 = DAT_00064820;
  switch(param_2) {
  case 1:
    memset(local_418,0,0x400);
    eVar1 = fopen_s(&local_5a8,".\\MD\\arkamys_eol.dat","rb");
    if (((eVar1 == 0) ||
        (eVar1 = fopen_s(&local_5a8,".\\Storage Card\\system\\arkamys_default.dat","rb"), eVar1 == 0
        )) && (local_5a8 != (FILE *)0x0)) {
      fseek(local_5a8,0,2);
      lVar2 = ftell(local_5a8);
      fseek(local_5a8,0,0);
      if (lVar2 == 0x395) {
        fread(local_418,0x395,1,local_5a8);
      }
      else if (lVar2 == 0x72a) {
        uVar3 = 0;
        local_5a4[0] = '\0';
        local_5a4[1] = 0;
        local_5a4[2] = 0;
        local_5a4[3] = 0;
        do {
          fread(local_5a4,2,1,local_5a8);
          local_5a4[3] = 0;
          sscanf_s(local_5a4,"%x",local_59c);
          puVar7 = local_418 + uVar3;
          uVar3 = uVar3 + 1;
          *puVar7 = local_59c[0];
        } while (uVar3 < 0x395);
      }
      fclose(local_5a8);
      FUN_00014db0(DAT_000648e4,0xf,0x21,(int)local_418,0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x22,(int)(local_418 + 0x80),0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x23,(int)(local_418 + 0x100),0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x24,(int)(local_418 + 0x180),0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x25,(int)(local_418 + 0x200),0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x26,(int)(local_418 + 0x280),0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x27,(int)(local_418 + 0x300),0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x28,(int)(local_418 + 0x380),0x80,300);
      FUN_00015158(DAT_000648e4,5,1,0x60,0,0,200);
    }
    break;
  case 2:
    uVar3 = 0;
    goto LAB_0003cea0;
  case 3:
    uVar3 = 4;
    goto LAB_0003cea0;
  case 4:
    uVar3 = 1;
    goto LAB_0003cea0;
  case 5:
    uVar3 = 2;
    goto LAB_0003cea0;
  case 6:
    uVar3 = 3;
LAB_0003cea0:
    FUN_000126bc(DAT_00064828,uVar3);
    break;
  case 7:
    if (*(int *)(param_1 + 0x10) == 1) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = 1;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      puVar5 = &DAT_0005d7b8;
    }
    else {
      puVar5 = (undefined4 *)&DAT_0005db30;
    }
    wsprintfW(aWStack_4f8,L"CALL\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x14),aWStack_4f8);
    iVar4 = *(int *)(param_1 + 0x10);
    uVar3 = 0;
    goto LAB_0003cf34;
  case 8:
    if (*(int *)(param_1 + 0x18) == 1) {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
    if (*(int *)(param_1 + 0x18) == 0) {
      puVar5 = &DAT_0005d7b8;
    }
    else {
      puVar5 = (undefined4 *)&DAT_0005db30;
    }
    wsprintfW(aWStack_558,L"NAVI\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x20),aWStack_558);
    iVar4 = *(int *)(param_1 + 0x18);
    uVar3 = 3;
    goto LAB_0003cf34;
  case 9:
    if (*(int *)(param_1 + 0x1c) == 1) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 1;
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
      puVar5 = &DAT_0005d7b8;
    }
    else {
      puVar5 = (undefined4 *)&DAT_0005db30;
    }
    wsprintfW(aWStack_598,L"SIRI\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x24),aWStack_598);
    iVar4 = *(int *)(param_1 + 0x1c);
    uVar3 = 4;
LAB_0003cf34:
    FUN_00011904(DAT_00064828,uVar3,iVar4);
    break;
  case 0xb:
    if (*(byte *)(DAT_00064ae4 + 0xaf5) < 0x7c) {
      cVar6 = '{';
    }
    else {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf5) - 1;
    }
    goto LAB_0003d04c;
  case 0xc:
    if (*(byte *)(DAT_00064ae4 + 0xaf5) < 0x85) {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf5) + 1;
    }
    else {
      cVar6 = -0x7b;
    }
LAB_0003d04c:
    FUN_000112cc(DAT_00064828,cVar6);
    FUN_0003c00c(param_1);
    break;
  case 0xd:
    if (*(byte *)(DAT_00064ae4 + 0xaf4) < 0x7c) {
      cVar6 = '{';
    }
    else {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf4) - 1;
    }
    goto LAB_0003d0cc;
  case 0xe:
    if (*(byte *)(DAT_00064ae4 + 0xaf4) < 0x85) {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf4) + 1;
    }
    else {
      cVar6 = -0x7b;
    }
LAB_0003d0cc:
    FUN_00011328(DAT_00064828,cVar6);
    FUN_0003c06c(param_1);
    break;
  case 0xf:
    if (*(byte *)(DAT_00064ae4 + 0xaf6) < 0x7c) {
      cVar6 = '{';
    }
    else {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf6) - 1;
    }
    goto LAB_0003d14c;
  case 0x10:
    if (*(byte *)(DAT_00064ae4 + 0xaf6) < 0x85) {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf6) + 1;
    }
    else {
      cVar6 = -0x7b;
    }
LAB_0003d14c:
    FUN_00011384(DAT_00064828,cVar6);
    FUN_0003c0cc(param_1);
    break;
  case 0x11:
    if (*(byte *)(DAT_00064ae4 + 0xaf7) < 0x7c) {
      cVar6 = '{';
    }
    else {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf7) - 1;
    }
    goto LAB_0003d1cc;
  case 0x12:
    if (*(byte *)(DAT_00064ae4 + 0xaf7) < 0x85) {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf7) + 1;
    }
    else {
      cVar6 = -0x7b;
    }
LAB_0003d1cc:
    FUN_000113e0(DAT_00064828,cVar6);
    FUN_0003c12c(param_1);
    break;
  case 0x13:
    if (*(byte *)(DAT_00064ae4 + 0xaf8) < 0x7c) {
      cVar6 = '{';
    }
    else {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf8) - 1;
    }
    goto LAB_0003d24c;
  case 0x14:
    if (*(byte *)(DAT_00064ae4 + 0xaf8) < 0x85) {
      cVar6 = *(byte *)(DAT_00064ae4 + 0xaf8) + 1;
    }
    else {
      cVar6 = -0x7b;
    }
LAB_0003d24c:
    FUN_0001143c(DAT_00064828,cVar6);
    FUN_0003c18c(param_1);
    break;
  case 0x15:
    DAT_00067678 = DAT_00067678 & 0xfffffffd;
    wsprintfW(aWStack_518,L"MIC(INT)");
    lpString = aWStack_518;
    goto LAB_0003d2c0;
  case 0x16:
    DAT_00067678 = DAT_00067678 | 2;
    wsprintfW(aWStack_538,L"MIC(EXT)");
    lpString = aWStack_538;
LAB_0003d2c0:
    SetWindowTextW(*(HWND *)(param_1 + 0x40),lpString);
    break;
  case 0x17:
    iVar4 = 1;
    goto LAB_0003d300;
  case 0x18:
    iVar4 = 0;
LAB_0003d300:
    FUN_000111f4(DAT_00064828,iVar4);
    break;
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
    FUN_00011264(DAT_00064828,param_2 + 0xe7U & 0xff);
    break;
  case 0x1f:
  case 0x20:
    if (param_2 == 0x1f) {
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + -1;
    }
    else {
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
    }
    wsprintfW(aWStack_578,L"0x%04X",*(undefined4 *)(param_1 + 0x48));
    SetWindowTextW(*(HWND *)(param_1 + 0x44),aWStack_578);
    local_59e = *(undefined1 *)(param_1 + 0x49);
    local_59d = (undefined1)*(undefined4 *)(param_1 + 0x48);
    FUN_00014db0(DAT_000648e4,2,0xd1086,(int)&local_59e,2,100);
    break;
  case 0x21:
    if (*(int *)(param_1 + 0x4c) == 1) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 1;
    }
    if (*(int *)(param_1 + 0x4c) == 0) {
      puVar5 = &DAT_0005d7b8;
    }
    else {
      puVar5 = (undefined4 *)&DAT_0005db30;
    }
    wsprintfW(aWStack_4d8,L"REC MICIN\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x50),aWStack_4d8);
    pcVar8 = OnRecMicInBNT_exref;
    goto LAB_0003d534;
  case 0x22:
    if (*(int *)(param_1 + 0x54) == 1) {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x54) = 1;
    }
    if (*(int *)(param_1 + 0x54) == 0) {
      puVar5 = &DAT_0005d7b8;
    }
    else {
      puVar5 = (undefined4 *)&DAT_0005db30;
    }
    wsprintfW(aWStack_458,L"REC MICOUT\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x58),aWStack_458);
    pcVar8 = OnRecMicOutBNT_exref;
    goto LAB_0003d534;
  case 0x23:
    if (*(int *)(param_1 + 0x5c) == 1) {
      *(undefined4 *)(param_1 + 0x5c) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x5c) = 1;
    }
    if (*(int *)(param_1 + 0x5c) == 0) {
      puVar5 = &DAT_0005d7b8;
    }
    else {
      puVar5 = (undefined4 *)&DAT_0005db30;
    }
    wsprintfW(aWStack_498,L"REC RECVIN\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x60),aWStack_498);
    pcVar8 = OnRecRecvInBNT_exref;
LAB_0003d534:
    (*pcVar8)();
    break;
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    local_5a4[4] = (char)param_2 + -0x24;
    local_59f = 0xf;
    FUN_00015158(DAT_000648e4,5,1,0x40,(int)(local_5a4 + 4),2,100);
  }
  FUN_0004a3f4(local_18);
  return;
}



/* 0003d55c FUN_0003d55c */

/* Boundary evidence: original MIPS .pdata 0003d55c..0003d5cf. Semantic name remains unreviewed. */

undefined4 * FUN_0003d55c(undefined4 *param_1)

{
  FUN_00044b4c(param_1);
  *param_1 = &PTR_FUN_0005e444;
  param_1[6] = 10;
  param_1[5] = 1;
  param_1[4] = 1;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  *(undefined2 *)((int)param_1 + 0x1e) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  *(undefined2 *)(param_1 + 9) = 0;
  return param_1;
}



/* 0003d5d0 FUN_0003d5d0 */

/* Boundary evidence: original MIPS .pdata 0003d5d0..0003d633. Semantic name remains unreviewed. */

void FUN_0003d5d0(int param_1,int param_2)

{
  RECT local_18;
  
  if (param_2 == 100) {
    FUN_00044f54(param_1,100);
    *(undefined4 *)(param_1 + 0x18) = 10;
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 800;
    local_18.bottom = 0x1e0;
    InvalidateRect(*(HWND *)(param_1 + 0xc),&local_18,0);
  }
  return;
}



/* 0003d634 FUN_0003d634 */

/* Boundary evidence: original MIPS .pdata 0003d634..0003d6db. Semantic name remains unreviewed. */

void FUN_0003d634(int param_1)

{
  undefined1 local_18 [8];
  
  if (*(int *)(param_1 + 0x10) == 0) {
    local_18[0] = 0;
    FUN_00014db0(DAT_000648e4,0,0x30,(int)local_18,1,0x32);
  }
  local_18[0] = 0;
  FUN_00014db0(DAT_000648e4,3,0xf0,(int)local_18,1,0x32);
  if (DAT_00068594 != (undefined4 *)0x0) {
    (**(code **)*DAT_00068594)(DAT_00068594,1);
    DAT_00068594 = (undefined4 *)0x0;
  }
  return;
}



/* 0003d6dc FUN_0003d6dc */

/* Boundary evidence: original MIPS .pdata 0003d6dc..0003d76f. Semantic name remains unreviewed. */

undefined2 FUN_0003d6dc(double param_1,double param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 extraout_v0;
  undefined4 extraout_v1;
  undefined8 uVar3;
  
  uVar2 = __fpsub(param_4,0x40c0a3d7);
  uVar2 = __fpmul(uVar2,0x3d4ccccd);
  __fptodp(uVar2);
  pow(param_1,param_2);
  uVar2 = __dptofp(extraout_v0,extraout_v1);
  uVar2 = __fpmul(uVar2,0x45000000);
  uVar3 = __fptodp(uVar2);
  uVar3 = __dpadd((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x3fe00000);
  uVar1 = __dptoul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  return uVar1;
}



/* 0003d770 FUN_0003d770 */

/* Boundary evidence: original MIPS .pdata 0003d770..0003da77. Semantic name remains unreviewed. */

void FUN_0003d770(double param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_v0;
  undefined4 extraout_v0_00;
  undefined4 extraout_v0_01;
  undefined4 extraout_v0_02;
  undefined4 extraout_v0_03;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  undefined4 extraout_v1_01;
  undefined4 extraout_v1_02;
  undefined4 extraout_v1_03;
  byte local_20;
  byte local_1f;
  byte local_1e;
  byte local_1d;
  
  uVar1 = FUN_000153dc(DAT_000648e4,2,0xd102d,&local_20,2,200);
  if (uVar1 == 2) {
    *(ushort *)(param_2 + 0x1c) = (ushort)local_20 * 0x100 + (ushort)local_1f;
  }
  uVar1 = FUN_000153dc(DAT_000648e4,2,0xd1086,&local_20,2,200);
  if (uVar1 == 2) {
    *(ushort *)(param_2 + 0x24) = (ushort)local_20 * 0x100 + (ushort)local_1f;
  }
  uVar1 = FUN_000153dc(DAT_000648e4,2,0xd105e,&local_20,4,200);
  if (uVar1 == 4) {
    *(ushort *)(param_2 + 0x1e) = (ushort)local_20 * 0x100 + (ushort)local_1f;
    *(ushort *)(param_2 + 0x20) = (ushort)local_1e * 0x100 + (ushort)local_1d;
  }
  uVar1 = FUN_000153dc(DAT_000648e4,2,0xd10d5,&local_20,2,200);
  if (uVar1 == 2) {
    *(ushort *)(param_2 + 0x22) = (ushort)local_20 * 0x100 + (ushort)local_1f;
  }
  uVar2 = __litofp(*(undefined2 *)(param_2 + 0x1c));
  uVar2 = __fpmul(uVar2,0x3a000000);
  __fptodp(uVar2);
  log10(param_1);
  uVar2 = __dptofp(extraout_v0,extraout_v1);
  uVar2 = __fpmul(uVar2,0x41a00000);
  uVar2 = __fpadd(uVar2,0x40c0a3d7);
  *(undefined4 *)(param_2 + 0x28) = uVar2;
  uVar2 = __litofp(*(undefined2 *)(param_2 + 0x1e));
  uVar2 = __fpmul(uVar2,0x3a000000);
  __fptodp(uVar2);
  log10(param_1);
  uVar2 = __dptofp(extraout_v0_00,extraout_v1_00);
  uVar2 = __fpmul(uVar2,0x41a00000);
  uVar2 = __fpadd(uVar2,0x40c0a3d7);
  *(undefined4 *)(param_2 + 0x2c) = uVar2;
  uVar2 = __litofp(*(undefined2 *)(param_2 + 0x20));
  uVar2 = __fpmul(uVar2,0x3a000000);
  __fptodp(uVar2);
  log10(param_1);
  uVar2 = __dptofp(extraout_v0_01,extraout_v1_01);
  uVar2 = __fpmul(uVar2,0x41a00000);
  uVar2 = __fpadd(uVar2,0x40c0a3d7);
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  uVar2 = __litofp(*(undefined2 *)(param_2 + 0x22));
  uVar2 = __fpmul(uVar2,0x3a000000);
  __fptodp(uVar2);
  log10(param_1);
  uVar2 = __dptofp(extraout_v0_02,extraout_v1_02);
  uVar2 = __fpmul(uVar2,0x41a00000);
  uVar2 = __fpadd(uVar2,0x40c0a3d7);
  *(undefined4 *)(param_2 + 0x34) = uVar2;
  uVar2 = __litofp(*(undefined2 *)(param_2 + 0x24));
  uVar2 = __fpmul(uVar2,0x3a000000);
  __fptodp(uVar2);
  log10(param_1);
  uVar2 = __dptofp(extraout_v0_03,extraout_v1_03);
  uVar2 = __fpmul(uVar2,0x41a00000);
  uVar2 = __fpadd(uVar2,0x40c0a3d7);
  *(undefined4 *)(param_2 + 0x38) = uVar2;
  return;
}



/* 0003da78 FUN_0003da78 */

/* Boundary evidence: original MIPS .pdata 0003da78..0003db0f. Semantic name remains unreviewed. */

BOOL FUN_0003da78(undefined4 param_1,HDC param_2,RECT *param_3,COLORREF param_4)

{
  COLORREF color;
  BOOL BVar1;
  
  BVar1 = 0;
  color = SetBkColor(param_2,param_4);
  if (color != 0xffffffff) {
    BVar1 = ExtTextOutW(param_2,0,0,2,param_3,(LPCWSTR)0x0,0,(INT *)0x0);
    SetBkColor(param_2,color);
  }
  return BVar1;
}



/* 0003db10 FUN_0003db10 */

/* Boundary evidence: original MIPS .pdata 0003db10..0003dd23. Semantic name remains unreviewed. */

void FUN_0003db10(int param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,COLORREF param_6
                 ,LPCWSTR param_7)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT h_01;
  HGDIOBJ h_02;
  int x;
  int y;
  RECT *lprc;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  if (*(int *)(param_1 + 0x14) == param_3) {
    param_6 = 0x46461e;
  }
  else if (*(int *)(param_1 + 0x18) == param_3) {
    param_6 = 0x323232;
  }
  lprc = (RECT *)(&DAT_0005e3a4 + param_3 * 4);
  FUN_0003da78(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_000440e8(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,5);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_0005e3a8)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_0005e3ac)[param_3 * 4] - x,(&DAT_0005e3b0)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003dd24 FUN_0003dd24 */

/* Boundary evidence: original MIPS .pdata 0003dd24..0003dfd7. Semantic name remains unreviewed. */

void FUN_0003dd24(int param_1,HDC param_2,int param_3,LONG param_4,LONG param_5,COLORREF param_6,
                 COLORREF param_7,COLORREF param_8,LPCWSTR param_9,LPCWSTR param_10)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT pHVar1;
  HGDIOBJ pvVar2;
  int x;
  int y;
  RECT *lprc;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  if (*(int *)(param_1 + 0x14) == param_3) {
    param_8 = 0x46461e;
  }
  else if (*(int *)(param_1 + 0x18) == param_3) {
    param_8 = 0x323232;
  }
  lprc = (RECT *)(&DAT_0005e3a4 + param_3 * 4);
  FUN_0003da78(param_1,hdc,lprc,param_8);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_6);
  pHVar1 = FUN_000440e8(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_9,-1,lprc,1);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_7);
  pHVar1 = FUN_000440e8(param_5,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_10,-1,lprc,9);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  y = (&DAT_0005e3a8)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_0005e3ac)[param_3 * 4] - x,(&DAT_0005e3b0)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003dfd8 FUN_0003dfd8 */

/* Boundary evidence: original MIPS .pdata 0003dfd8..0003e093. Semantic name remains unreviewed. */

void FUN_0003dfd8(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  uVar1 = *(ushort *)(param_1 + 0x1c);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x28));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003dd24(param_1,param_2,4,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Primary",aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 0003e094 FUN_0003e094 */

/* Boundary evidence: original MIPS .pdata 0003e094..0003e14f. Semantic name remains unreviewed. */

void FUN_0003e094(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  uVar1 = *(ushort *)(param_1 + 0x24);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x38));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003dd24(param_1,param_2,5,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Secondary",aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 0003e150 FUN_0003e150 */

/* Boundary evidence: original MIPS .pdata 0003e150..0003e20b. Semantic name remains unreviewed. */

void FUN_0003e150(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  uVar1 = *(ushort *)(param_1 + 0x1e);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x2c));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003dd24(param_1,param_2,6,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Navi",aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 0003e20c FUN_0003e20c */

/* Boundary evidence: original MIPS .pdata 0003e20c..0003e2c7. Semantic name remains unreviewed. */

void FUN_0003e20c(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  uVar1 = *(ushort *)(param_1 + 0x20);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x30));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003dd24(param_1,param_2,7,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Phone",aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 0003e2c8 FUN_0003e2c8 */

/* Boundary evidence: original MIPS .pdata 0003e2c8..0003e383. Semantic name remains unreviewed. */

void FUN_0003e2c8(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  uVar1 = *(ushort *)(param_1 + 0x22);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x34));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003dd24(param_1,param_2,8,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Beep",aWStack_98);
  FUN_0004a3f4(local_18);
  return;
}



/* 0003e384 FUN_0003e384 */

/* Boundary evidence: original MIPS .pdata 0003e384..0003e3fb. Semantic name remains unreviewed. */

void FUN_0003e384(int param_1,HDC param_2)

{
  wchar_t *pwVar1;
  
  if (*(int *)(param_1 + 0x10) == 1) {
    pwVar1 = L"MICOM";
  }
  else {
    pwVar1 = L"PC";
  }
  FUN_0003dd24(param_1,param_2,9,0xc,0x1a,0xb4b4b4,0xffffff,0,L"GUI SELECT",pwVar1);
  return;
}



/* 0003e3fc FUN_0003e3fc */

/* Boundary evidence: original MIPS .pdata 0003e3fc..0003e5ef. Semantic name remains unreviewed. */

void FUN_0003e3fc(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  RECT local_30;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  local_30.left = 0;
  local_30.top = 0;
  local_30.right = 800;
  local_30.bottom = 0x1e0;
  FUN_0003da78(param_1,hdc,&local_30,0);
  FUN_0003db10(param_1,hdc,0,0x24,0xffffff,0,L"Debug Mode - Audio");
  FUN_0003db10(param_1,hdc,1,0x18,0xffffff,0,L"VOL");
  FUN_0003db10(param_1,hdc,2,0x20,0xffffff,0,L"X");
  FUN_0003db10(param_1,hdc,3,0x1c,0xffffff,0x505050,L"SOURCE GAIN");
  FUN_0003dfd8(param_1,hdc);
  FUN_0003e094(param_1,hdc);
  FUN_0003e150(param_1,hdc);
  FUN_0003e20c(param_1,hdc);
  FUN_0003e2c8(param_1,hdc);
  FUN_0003e384(param_1,hdc);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003e5f0 FUN_0003e5f0 */

void FUN_0003e5f0(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = &DAT_0005e3a4;
  while ((((param_2 <= *piVar2 || (piVar2[2] <= param_2)) || (param_3 <= piVar2[1])) ||
         (piVar2[3] <= param_3))) {
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 4;
    if (9 < uVar1) {
      return;
    }
  }
  return;
}



/* 0003e65c FUN_0003e65c */

/* Boundary evidence: original MIPS .pdata 0003e65c..0003e7eb. Semantic name remains unreviewed. */

void FUN_0003e65c(double param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  HDC hDC;
  undefined1 local_28 [8];
  RECT local_20;
  
  uVar1 = FUN_0003e5f0(param_2,param_3,param_4);
  if (uVar1 == 1) {
LAB_0003e7ac:
    *(uint *)(param_2 + 0x14) = uVar1;
    local_20.left = 0;
    local_20.top = 0;
    local_20.right = 800;
    local_20.bottom = 0x1e0;
    InvalidateRect(*(HWND *)(param_2 + 0xc),&local_20,0);
  }
  else {
    if (uVar1 == 2) {
      DestroyWindow(*(HWND *)(param_2 + 0xc));
      return;
    }
    if (uVar1 == 3) {
      FUN_0003d770(param_1,param_2);
      hDC = GetDC(*(HWND *)(param_2 + 0xc));
      FUN_0003dfd8(param_2,hDC);
      FUN_0003e094(param_2,hDC);
      FUN_0003e150(param_2,hDC);
      FUN_0003e20c(param_2,hDC);
      FUN_0003e2c8(param_2,hDC);
    }
    else {
      if (uVar1 < 4) {
        return;
      }
      if (uVar1 < 9) goto LAB_0003e7ac;
      if (uVar1 != 9) {
        return;
      }
      if (*(int *)(param_2 + 0x10) == 1) {
        local_28[0] = 1;
        FUN_00014db0(DAT_000648e4,0,0x30,(int)local_28,1,0x32);
        *(undefined4 *)(param_2 + 0x10) = 0;
      }
      else {
        local_28[0] = 0;
        FUN_00014db0(DAT_000648e4,0,0x30,(int)local_28,1,0x32);
        *(undefined4 *)(param_2 + 0x10) = 1;
      }
      hDC = GetDC(*(HWND *)(param_2 + 0xc));
      FUN_0003e384(param_2,hDC);
    }
    ReleaseDC(*(HWND *)(param_2 + 0xc),hDC);
  }
  return;
}



/* 0003e7ec FUN_0003e7ec */

/* Boundary evidence: original MIPS .pdata 0003e7ec..0003ec03. Semantic name remains unreviewed. */

void FUN_0003e7ec(double param_1,double param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  HDC pHVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_20;
  byte local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  iVar4 = *(int *)(param_3 + 0x14);
  if (iVar4 == 1) {
    FUN_00013014(DAT_00064828,3);
  }
  else {
    if (iVar4 == 4) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x28));
      uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x28) = uVar2;
      uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x1c) = uVar1;
      local_1f = (byte)uVar1;
      FUN_00014db0(DAT_000648e4,2,0xd102d,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003dfd8(param_3,pHVar3);
    }
    else if (iVar4 == 5) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x38));
      uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x38) = uVar2;
      uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x24) = uVar1;
      local_1f = (byte)uVar1;
      FUN_00014db0(DAT_000648e4,2,0xd1086,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003e094(param_3,pHVar3);
    }
    else if (iVar4 == 6) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x2c));
      uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x2c) = uVar2;
      uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x1e) = uVar1;
      local_1f = (byte)uVar1;
      FUN_00014db0(DAT_000648e4,2,0xd105e,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003e150(param_3,pHVar3);
    }
    else {
      if (iVar4 != 7) {
        if (iVar4 != 8) {
          return;
        }
        uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x34));
        uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
        uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
        *(undefined4 *)(param_3 + 0x34) = uVar2;
        uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
        *(undefined2 *)(param_3 + 0x22) = uVar1;
        local_20 = (undefined1)((ushort)uVar1 >> 8);
        local_1f = (byte)uVar1;
        local_1e = local_20;
        local_1d = local_1f;
        FUN_00014db0(DAT_000648e4,2,0xd10d5,(int)&local_20,4,200);
        pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
        FUN_0003e2c8(param_3,pHVar3);
        ReleaseDC(*(HWND *)(param_3 + 0xc),pHVar3);
        local_20 = 3;
        local_1f = DAT_00067683;
        if (DAT_00067683 < 10) {
          local_1f = 10;
        }
        FUN_00015158(DAT_000648e4,5,1,0x40,(int)&local_20,2,100);
        return;
      }
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x30));
      uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x30) = uVar2;
      uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x20) = uVar1;
      local_1f = (byte)uVar1;
      FUN_00014db0(DAT_000648e4,2,0xd105f,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003e20c(param_3,pHVar3);
    }
    ReleaseDC(*(HWND *)(param_3 + 0xc),pHVar3);
  }
  return;
}



/* 0003ec04 FUN_0003ec04 */

/* Boundary evidence: original MIPS .pdata 0003ec04..0003f01b. Semantic name remains unreviewed. */

void FUN_0003ec04(double param_1,double param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  HDC pHVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_20;
  byte local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  iVar4 = *(int *)(param_3 + 0x14);
  if (iVar4 == 1) {
    FUN_00013014(DAT_00064828,2);
  }
  else {
    if (iVar4 == 4) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x28));
      uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x28) = uVar2;
      uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x1c) = uVar1;
      local_1f = (byte)uVar1;
      FUN_00014db0(DAT_000648e4,2,0xd102d,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003dfd8(param_3,pHVar3);
    }
    else if (iVar4 == 5) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x38));
      uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x38) = uVar2;
      uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x24) = uVar1;
      local_1f = (byte)uVar1;
      FUN_00014db0(DAT_000648e4,2,0xd1086,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003e094(param_3,pHVar3);
    }
    else if (iVar4 == 6) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x2c));
      uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x2c) = uVar2;
      uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x1e) = uVar1;
      local_1f = (byte)uVar1;
      FUN_00014db0(DAT_000648e4,2,0xd105e,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003e150(param_3,pHVar3);
    }
    else {
      if (iVar4 != 7) {
        if (iVar4 != 8) {
          return;
        }
        uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x34));
        uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
        uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
        *(undefined4 *)(param_3 + 0x34) = uVar2;
        uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
        *(undefined2 *)(param_3 + 0x22) = uVar1;
        local_20 = (undefined1)((ushort)uVar1 >> 8);
        local_1f = (byte)uVar1;
        local_1e = local_20;
        local_1d = local_1f;
        FUN_00014db0(DAT_000648e4,2,0xd10d5,(int)&local_20,4,200);
        pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
        FUN_0003e2c8(param_3,pHVar3);
        ReleaseDC(*(HWND *)(param_3 + 0xc),pHVar3);
        local_20 = 3;
        local_1f = DAT_00067683;
        if (DAT_00067683 < 10) {
          local_1f = 10;
        }
        FUN_00015158(DAT_000648e4,5,1,0x40,(int)&local_20,2,100);
        return;
      }
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x30));
      uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x30) = uVar2;
      uVar1 = FUN_0003d6dc(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x20) = uVar1;
      local_1f = (byte)uVar1;
      FUN_00014db0(DAT_000648e4,2,0xd105f,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003e20c(param_3,pHVar3);
    }
    ReleaseDC(*(HWND *)(param_3 + 0xc),pHVar3);
  }
  return;
}



/* 0003f01c FUN_0003f01c */

/* Boundary evidence: original MIPS .pdata 0003f01c..0003f0af. Semantic name remains unreviewed. */

void FUN_0003f01c(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_000450c0();
  if (DAT_00068594 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x3c);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00068594 = (undefined4 *)0x0;
    }
    else {
      DAT_00068594 = FUN_0003d55c(puVar1);
    }
    FUN_00044b7c((int)DAT_00068594,DAT_00064aac,param_1);
  }
  return;
}



/* 0003f0b0 Unwind@0003f0b0 */

/* Boundary evidence: original MIPS .pdata 0003f0b0..0003f0df. Semantic name remains unreviewed. */

void Unwind_0003f0b0(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0003f0e0 FUN_0003f0e0 */

/* Boundary evidence: original MIPS .pdata 0003f0e0..0003f137. Semantic name remains unreviewed. */

undefined4 * FUN_0003f0e0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0005e444;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003f138 FUN_0003f138 */

/* Boundary evidence: original MIPS .pdata 0003f138..0003f153. Semantic name remains unreviewed. */

void FUN_0003f138(double param_1,int param_2)

{
  FUN_0003d770(param_1,param_2);
  return;
}



/* 0003f154 FUN_0003f154 */

/* Boundary evidence: original MIPS .pdata 0003f154..0003f18b. Semantic name remains unreviewed. */

undefined4 * FUN_0003f154(undefined4 *param_1)

{
  FUN_00044b4c(param_1);
  *param_1 = &PTR_FUN_0005e558;
  return param_1;
}



/* 0003f18c FUN_0003f18c */

/* Boundary evidence: original MIPS .pdata 0003f18c..0003f467. Semantic name remains unreviewed. */

void FUN_0003f18c(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 auStack_30 [8];
  
  uVar1 = FUN_00044f30();
  uVar2 = FUN_00044f28();
  FUN_0003f5e0(auStack_30,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar2,uVar1);
  FUN_0003f6bc(auStack_30,0,L"Bluetooth Test",0,(HMENU)0x0);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT DUT MODE",0xe,(HMENU)0x1);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT RF TEST",0xe,(HMENU)0x2);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT iAP Enable",0xe,(HMENU)0x3);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT iAP Disable",0xe,(HMENU)0x4);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f69c((int)auStack_30);
  FUN_0003f6bc(auStack_30,0,L"Bluetooth SIG",0,(HMENU)0x0);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT SIG ENABLE",0xe,(HMENU)0x5);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT SIG DISABLE",0xe,(HMENU)0x6);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT SIG PBAP CONNECT",0xe,(HMENU)0x7);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT SIG PBAP DOWNLOAD",0xe,(HMENU)0x8);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT SIG PBAP ABORT",0xe,(HMENU)0x9);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT SIG PBAP DISCONNECT",0xe,(HMENU)0xa);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT SIG VR CONNECT",0xe,(HMENU)0xb);
  FUN_0003f614((int)auStack_30,0);
  FUN_0003f6bc(auStack_30,1,L"BT SIG VR DISCONNECT",0xe,(HMENU)0xc);
  FUN_0003f614((int)auStack_30,0);
  FUN_00036f60();
  return;
}



/* 0003f468 Unwind@0003f468 */

/* Boundary evidence: original MIPS .pdata 0003f468..0003f497. Semantic name remains unreviewed. */

void Unwind_0003f468(void)

{
  FUN_00036f60();
  return;
}



/* 0003f498 FUN_0003f498 */

/* Boundary evidence: original MIPS .pdata 0003f498..0003f587. Semantic name remains unreviewed. */

void FUN_0003f498(undefined4 param_1,undefined4 param_2)

{
  WPARAM WVar1;
  
  switch(param_2) {
  case 1:
    WVar1 = 0x1010b01;
    break;
  case 2:
    WVar1 = 0x3010c02;
    break;
  case 3:
    WVar1 = 0x3060b04;
    break;
  case 4:
    WVar1 = 0x3060b05;
    break;
  case 5:
    WVar1 = 0x1010e01;
    break;
  case 6:
    WVar1 = 0x1010f01;
    break;
  case 7:
    WVar1 = 0x1011001;
    break;
  case 8:
    WVar1 = 0x1012001;
    break;
  case 9:
    WVar1 = 0x1013101;
    break;
  case 10:
    WVar1 = 0x1014101;
    break;
  case 0xb:
    WVar1 = 0x1015101;
    break;
  case 0xc:
    WVar1 = 0x1016101;
    break;
  default:
    goto switchD_0003f4c8_default;
  }
  FUN_00036f08(WVar1,0);
switchD_0003f4c8_default:
  return;
}



/* 0003f588 FUN_0003f588 */

/* Boundary evidence: original MIPS .pdata 0003f588..0003f5df. Semantic name remains unreviewed. */

undefined4 * FUN_0003f588(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0005e558;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003f5e0 FUN_0003f5e0 */

undefined4 *
FUN_0003f5e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4,
            undefined4 param_5)

{
  param_1[2] = 0x18;
  param_1[3] = 0x18;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[4] = param_4;
  param_1[5] = param_5;
  param_1[6] = param_4 >> 1;
  param_1[7] = 0;
  return param_1;
}



/* 0003f614 FUN_0003f614 */

void FUN_0003f614(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18) + 0x18;
    if (*(int *)(param_1 + 8) != iVar1) {
      *(int *)(param_1 + 8) = iVar1;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x30;
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 8;
  }
  return;
}



/* 0003f674 FUN_0003f674 */

void FUN_0003f674(int param_1)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x30;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18) + 0x18;
  return;
}



/* 0003f69c FUN_0003f69c */

void FUN_0003f69c(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0x18) + 0x18;
  *(undefined4 *)(param_1 + 0xc) = 0x18;
  return;
}



/* 0003f6bc FUN_0003f6bc */

/* Boundary evidence: original MIPS .pdata 0003f6bc..0003f877. Semantic name remains unreviewed. */

HWND FUN_0003f6bc(undefined4 *param_1,int param_2,LPCWSTR param_3,int param_4,HMENU param_5)

{
  HWND pHVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = param_1[7] * param_1[6] + 0x18;
    if (param_1[2] != iVar2) {
      param_1[2] = iVar2;
      param_1[3] = param_1[3] + 0x30;
    }
    pHVar1 = CreateWindowExW(0,L"button",param_3,0x50000000,param_1[2],param_1[3],param_1[6] + -0x30
                             ,0x18,(HWND)param_1[1],param_5,(HINSTANCE)*param_1,(LPVOID)0x0);
    param_1[3] = param_1[3] + 0x18;
  }
  else {
    if (param_2 == 1) {
      pHVar1 = CreateWindowExW(0,L"button",param_3,0x50802000,param_1[2] + 2,param_1[3] + 2,
                               param_4 * 0x18 + -2,0x2e,(HWND)param_1[1],param_5,(HINSTANCE)*param_1
                               ,(LPVOID)0x0);
    }
    else {
      if (param_2 != 2) {
        return (HWND)0x0;
      }
      pHVar1 = CreateWindowExW(0,L"button",param_3,0x50002000,param_1[2] + 2,param_1[3] + 2,
                               param_4 * 0x18 + -2,0x2e,(HWND)param_1[1],param_5,(HINSTANCE)*param_1
                               ,(LPVOID)0x0);
    }
    param_1[2] = param_1[2] + param_4 * 0x18;
  }
  return pHVar1;
}



/* 0003f878 FUN_0003f878 */

/* Boundary evidence: original MIPS .pdata 0003f878..0003f8bf. Semantic name remains unreviewed. */

undefined4 * FUN_0003f878(undefined4 *param_1)

{
  FUN_00044b4c(param_1);
  *param_1 = &PTR_FUN_0005e978;
  memset(param_1 + 4,0,0x1c);
  return param_1;
}



/* 0003f8c0 FUN_0003f8c0 */

/* Boundary evidence: original MIPS .pdata 0003f8c0..0003f903. Semantic name remains unreviewed. */

void FUN_0003f8c0(void)

{
  if (DAT_000685c0 != (undefined4 *)0x0) {
    (**(code **)*DAT_000685c0)(DAT_000685c0,1);
    DAT_000685c0 = (undefined4 *)0x0;
  }
  return;
}



/* 0003f904 FUN_0003f904 */

/* Boundary evidence: original MIPS .pdata 0003f904..0003f9b7. Semantic name remains unreviewed. */

void FUN_0003f904(int param_1)

{
  uint uVar1;
  uint uVar2;
  short *psVar3;
  byte local_20;
  byte local_1f;
  
  uVar2 = 0;
  psVar3 = (short *)(param_1 + 0x10);
  do {
    uVar1 = FUN_000153dc(DAT_000648e4,9,uVar2 + 0x80,&local_20,2,200);
    if (uVar1 == 2) {
      *psVar3 = (ushort)local_1f * 0x100 + (ushort)local_20;
    }
    else {
      NKDbgPrintfW(L" \r\n []read error of REG_DET_ADC_LV+%d\r\n",uVar2);
    }
    uVar2 = uVar2 + 1;
    psVar3 = psVar3 + 1;
  } while (uVar2 < 0xe);
  return;
}



/* 0003f9b8 FUN_0003f9b8 */

/* Boundary evidence: original MIPS .pdata 0003f9b8..0003fb9b. Semantic name remains unreviewed. */

void FUN_0003f9b8(undefined4 param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,
                 COLORREF param_6,LPCWSTR param_7)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT h_01;
  HGDIOBJ h_02;
  int x;
  int y;
  RECT *lprc;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  lprc = (RECT *)(&DAT_0005e858 + param_3 * 4);
  FUN_0003da78(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_000440e8(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,5);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_0005e85c)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_0005e860)[param_3 * 4] - x,(&DAT_0005e864)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003fb9c FUN_0003fb9c */

/* Boundary evidence: original MIPS .pdata 0003fb9c..0003fe1f. Semantic name remains unreviewed. */

void FUN_0003fb9c(undefined4 param_1,HDC param_2,int param_3,LONG param_4,LONG param_5,
                 COLORREF param_6,COLORREF param_7,COLORREF param_8,LPCWSTR param_9,LPCWSTR param_10
                 )

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT pHVar1;
  HGDIOBJ pvVar2;
  int x;
  int y;
  RECT *lprc;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  lprc = (RECT *)(&DAT_0005e858 + param_3 * 4);
  FUN_0003da78(param_1,hdc,lprc,param_8);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_6);
  pHVar1 = FUN_000440e8(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_9,-1,lprc,1);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_7);
  pHVar1 = FUN_000440e8(param_5,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_10,-1,lprc,9);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  y = (&DAT_0005e85c)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_0005e860)[param_3 * 4] - x,(&DAT_0005e864)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003fe20 FUN_0003fe20 */

void FUN_0003fe20(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = &DAT_0005e858;
  while ((((param_2 <= *piVar2 || (piVar2[2] <= param_2)) || (param_3 <= piVar2[1])) ||
         (piVar2[3] <= param_3))) {
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 4;
    if (0x11 < uVar1) {
      return;
    }
  }
  return;
}



/* 0003fe8c FUN_0003fe8c */

/* Boundary evidence: original MIPS .pdata 0003fe8c..0003ff1b. Semantic name remains unreviewed. */

void FUN_0003fe8c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  RECT local_18;
  
  uVar1 = FUN_0003fe20(param_1,param_2,param_3);
  if (uVar1 == 1) {
    FUN_00044f54(param_1,1000);
    DestroyWindow(*(HWND *)(param_1 + 0xc));
  }
  else if ((1 < uVar1) && (uVar1 < 0x10)) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 800;
    local_18.bottom = 0x1e0;
    InvalidateRect(*(HWND *)(param_1 + 0xc),&local_18,0);
  }
  return;
}



/* 0003ff1c FUN_0003ff1c */

/* Boundary evidence: original MIPS .pdata 0003ff1c..0003ff73. Semantic name remains unreviewed. */

undefined4 * FUN_0003ff1c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0005e978;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003ff74 FUN_0003ff74 */

/* Boundary evidence: original MIPS .pdata 0003ff74..0003ffaf. Semantic name remains unreviewed. */

void FUN_0003ff74(int param_1)

{
  FUN_0003f904(param_1);
  FUN_00044f38(param_1,1000,0x5dc,(TIMERPROC)0x0);
  return;
}



/* 0003ffb0 FUN_0003ffb0 */

/* Boundary evidence: original MIPS .pdata 0003ffb0..0003ffef. Semantic name remains unreviewed. */

void FUN_0003ffb0(int param_1,int param_2)

{
  if (param_2 == 1000) {
    FUN_0003f904(param_1);
    InvalidateRect(*(HWND *)(param_1 + 0xc),(RECT *)0x0,0);
  }
  return;
}



/* 0003fff0 FUN_0003fff0 */

/* Boundary evidence: original MIPS .pdata 0003fff0..00040123. Semantic name remains unreviewed. */

void FUN_0003fff0(int param_1,HDC param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined **ppuVar3;
  ushort *puVar4;
  undefined8 uVar5;
  WCHAR aWStack_a8 [64];
  uint local_28;
  
  local_28 = DAT_00064820;
  uVar2 = 0;
  ppuVar3 = &PTR_u_adc1_0006460c;
  puVar4 = (ushort *)(param_1 + 0x10);
  do {
    uVar1 = *puVar4;
    uVar5 = __litodp((uint)uVar1);
    uVar5 = __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x66666666,0x400a6666);
    __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x3f500000);
    wsprintfW(aWStack_a8,L"%4d(%3.2f[V])",(uint)uVar1);
    FUN_0003fb9c(param_1,param_2,uVar2 + 2,0x12,0x1c,0xb4b4b4,0xffffff,0,(LPCWSTR)*ppuVar3,
                 aWStack_a8);
    uVar2 = uVar2 + 1;
    puVar4 = puVar4 + 1;
    ppuVar3 = ppuVar3 + 1;
  } while (uVar2 < 0xe);
  FUN_0004a3f4(local_28);
  return;
}



/* 00040124 FUN_00040124 */

/* Boundary evidence: original MIPS .pdata 00040124..00040283. Semantic name remains unreviewed. */

void FUN_00040124(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  RECT local_30;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  local_30.left = 0;
  local_30.top = 0;
  local_30.right = 800;
  local_30.bottom = 0x1e0;
  FUN_0003da78(param_1,hdc,&local_30,0);
  FUN_0003f9b8(param_1,hdc,0,0x24,0xffffff,0,L"Debug Mode - ADC");
  FUN_0003f9b8(param_1,hdc,1,0x20,0xffffff,0,L"X");
  FUN_0003fff0(param_1,hdc);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00040284 FUN_00040284 */

/* Boundary evidence: original MIPS .pdata 00040284..00040363. Semantic name remains unreviewed. */

undefined4 * FUN_00040284(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  FUN_00044b4c(param_1);
  puVar1 = param_1 + 7;
  *param_1 = &PTR_FUN_0005eb54;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x16);
  puVar1 = param_1 + 0x1e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x23);
  *(undefined1 *)((int)param_1 + 0xb6) = 0xff;
  memset((void *)((int)param_1 + 0x12),0xff,1);
  memset(param_1 + 4,0,2);
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x26] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x27] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  *(undefined1 *)((int)param_1 + 0xb7) = 0;
  *(undefined1 *)(param_1 + 0x2d) = 10;
  *(undefined1 *)((int)param_1 + 0xb5) = 10;
  return param_1;
}



/* 00040364 FUN_00040364 */

/* Boundary evidence: original MIPS .pdata 00040364..00040647. Semantic name remains unreviewed. */

undefined4 FUN_00040364(int param_1,int param_2,undefined4 param_3,char *param_4)

{
  FILE *_File;
  uint uVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  byte local_f0 [3];
  byte local_ed;
  byte local_ec;
  byte local_eb;
  WCHAR local_b0;
  undefined1 auStack_ae [126];
  uint local_30;
  
  local_30 = DAT_00064820;
  local_b0 = L'\0';
  uVar4 = 0;
  memset(auStack_ae,0,0x7e);
  wsprintfW(&local_b0,L"Start-RD-%s",param_3);
  SetWindowTextW(*(HWND *)(param_1 + 0x58),&local_b0);
  _File = fopen(param_4,"wb");
  if (_File == (FILE *)0x0) {
    NKDbgPrintfW(L"File open error.\r\n");
    wsprintfW(&local_b0,L"ERR-open-RD-%s",param_3);
    SetWindowTextW(*(HWND *)(param_1 + 0x58),&local_b0);
LAB_00040608:
    FUN_0004a3f4(local_30);
    uVar5 = 0;
  }
  else {
    uVar3 = 0;
    uVar5 = 1;
    do {
      local_f0[0] = (byte)uVar3;
      uVar1 = FUN_000153dc(DAT_000648e4,0xd,param_2,local_f0,0x40,100);
      if (uVar1 == 0) {
        NKDbgPrintfW(L"send timeout.");
        wsprintfW(&local_b0,L"ERR-send-RD-%s",param_3);
        SetWindowTextW(*(HWND *)(param_1 + 0x58),&local_b0);
        fclose(_File);
        goto LAB_00040608;
      }
      if (uVar3 == 0) {
        if (param_2 == 0x22) {
          uVar4 = 0x20;
        }
        else if (param_2 == 0x23) {
          uVar4 = (uint)local_ec * 0x100 + (uint)local_eb;
          DAT_000685ec = (ushort)uVar4;
        }
        else if (param_2 == 0x24) {
          uVar4 = DAT_000685ec + 0xfcdd & 0xffff;
        }
        else if (param_2 == 0x25) {
          uVar4 = 0x395;
        }
        else if (param_2 == 0x26) {
          uVar4 = 800;
        }
      }
      uVar1 = local_f0[0] - 3;
      if ((int)uVar4 < (int)uVar1) {
        uVar1 = 0x3c;
      }
      sVar2 = fwrite(&local_ec,uVar1 & 0xffff,1,_File);
      if (sVar2 == 0) {
        NKDbgPrintfW(L"File read error.");
        wsprintfW(&local_b0,L"ERR-save-RD-%s",param_3);
        SetWindowTextW(*(HWND *)(param_1 + 0x58),&local_b0);
        uVar5 = 0;
        break;
      }
      if ((int)(local_f0[0] - 3) <= (int)uVar4) break;
      uVar3 = uVar3 + 1 & 0xff;
      uVar4 = uVar4 + 0xffc4 & 0xffff;
    } while ((int)(uint)local_ed <= (int)(uVar3 - 1));
    fclose(_File);
    FUN_0004a3f4(local_30);
  }
  return uVar5;
}



/* 00040648 FUN_00040648 */

/* Boundary evidence: original MIPS .pdata 00040648..00040c93. Semantic name remains unreviewed. */

undefined4 FUN_00040648(int param_1,int param_2,undefined4 param_3,char *param_4)

{
  FILE *_File;
  size_t sVar1;
  byte bVar2;
  size_t _ElementSize;
  undefined4 uVar3;
  WCHAR local_498;
  undefined1 auStack_496 [126];
  byte local_418;
  byte local_417 [127];
  undefined1 auStack_398 [128];
  undefined1 auStack_318 [128];
  undefined1 auStack_298 [128];
  undefined1 auStack_218 [128];
  undefined1 auStack_198 [128];
  undefined1 auStack_118 [128];
  undefined1 auStack_98 [104];
  uint local_30;
  
  local_30 = DAT_00064820;
  local_418 = 0;
  memset(local_417,0,999);
  local_498 = L'\0';
  _ElementSize = 0;
  memset(auStack_496,0,0x7e);
  wsprintfW(&local_498,L"Start-WD-%s",param_3);
  SetWindowTextW(*(HWND *)(param_1 + 0x5c),&local_498);
  _File = fopen(param_4,"rb");
  if (_File == (FILE *)0x0) {
    NKDbgPrintfW(L"File open error.\r\n");
    wsprintfW(&local_498,L"ERR-open-WD-%s",param_3);
    SetWindowTextW(*(HWND *)(param_1 + 0x5c),&local_498);
    goto LAB_00040724;
  }
  if (param_2 == 0x22) {
LAB_00040778:
    _ElementSize = 0x20;
  }
  else if (param_2 == 0x23) {
    _ElementSize = 0x23;
  }
  else if (param_2 == 0x24) {
    _ElementSize = (int)(DAT_000685f0 - 0x323) % 0x80 & 0xff;
  }
  else if (param_2 == 0x25) {
    _ElementSize = 0x15;
  }
  else if (param_2 == 0x26) goto LAB_00040778;
  uVar3 = 1;
  sVar1 = fread(&local_418,_ElementSize,1,_File);
  if (sVar1 != 0) {
    if (param_2 == 0x23) {
      DAT_000685f0 = (ushort)local_418 * 0x100 + (ushort)local_417[0];
    }
    bVar2 = (byte)_ElementSize;
    if (param_2 == 0x22) {
      FUN_00014db0(DAT_000648e4,0xf,0x2b,(int)&local_418,bVar2,300);
LAB_00040c50:
      fclose(_File);
      FUN_0004a3f4(local_30);
      return uVar3;
    }
    if (param_2 != 0x23) {
      if (param_2 == 0x24) {
        if (DAT_000685f0 == 0) {
          NKDbgPrintfW(L"File write error.");
          wsprintfW(&local_498,L"ERR-save-WD-%s",param_3);
          SetWindowTextW(*(HWND *)(param_1 + 0x5c),&local_498);
          uVar3 = 0;
        }
        else {
          FUN_00014db0(DAT_000648e4,0xf,0x33,(int)&local_418,0x80,300);
          FUN_00014db0(DAT_000648e4,0xf,0x34,(int)auStack_398,0x80,300);
          FUN_00014db0(DAT_000648e4,0xf,0x35,(int)auStack_318,0x80,300);
          FUN_00014db0(DAT_000648e4,0xf,0x36,(int)auStack_298,0x80,300);
          FUN_00014db0(DAT_000648e4,0xf,0x37,(int)auStack_218,0x80,300);
          FUN_00014db0(DAT_000648e4,0xf,0x38,(int)auStack_198,0x80,300);
          FUN_00014db0(DAT_000648e4,0xf,0x39,(int)auStack_118,bVar2,300);
        }
      }
      else if (param_2 == 0x25) {
        FUN_00014db0(DAT_000648e4,0xf,0x21,(int)&local_418,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x22,(int)auStack_398,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x23,(int)auStack_318,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x24,(int)auStack_298,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x25,(int)auStack_218,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x26,(int)auStack_198,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x27,(int)auStack_118,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x28,(int)auStack_98,bVar2,300);
      }
      else if (param_2 == 0x26) {
        FUN_00014db0(DAT_000648e4,0xf,0x11,(int)&local_418,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x12,(int)auStack_398,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x13,(int)auStack_318,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x14,(int)auStack_298,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x15,(int)auStack_218,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x16,(int)auStack_198,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x17,(int)auStack_118,0x80,300);
        FUN_00014db0(DAT_000648e4,0xf,0x18,(int)auStack_98,bVar2,300);
      }
      goto LAB_00040c50;
    }
    if (DAT_000685f0 != 0) {
      FUN_00014db0(DAT_000648e4,0xf,0x2c,(int)&local_418,0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x2d,(int)auStack_398,0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x2e,(int)auStack_318,0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x2f,(int)auStack_298,0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x30,(int)auStack_218,0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x31,(int)auStack_198,0x80,300);
      FUN_00014db0(DAT_000648e4,0xf,0x32,(int)auStack_118,bVar2,300);
      goto LAB_00040c50;
    }
  }
  NKDbgPrintfW(L"File write error.");
  wsprintfW(&local_498,L"ERR-save-WD-%s",param_3);
  SetWindowTextW(*(HWND *)(param_1 + 0x5c),&local_498);
  fclose(_File);
LAB_00040724:
  FUN_0004a3f4(local_30);
  return 0;
}



/* 00040c94 FUN_00040c94 */

/* Boundary evidence: original MIPS .pdata 00040c94..00040d2b. Semantic name remains unreviewed. */

void FUN_00040c94(int param_1)

{
  uint uVar1;
  wchar_t *lpString;
  char local_18 [8];
  
  local_18[0] = '\0';
  uVar1 = FUN_000153dc(DAT_000648e4,1,0xde,local_18,1,100);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"Get Loudness config... %d.\n",local_18[0]);
    if (local_18[0] == '\x01') {
      lpString = L"LDNS On";
    }
    else {
      lpString = L"LDNS Off";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x74),lpString);
  }
  return;
}



/* 00040d2c FUN_00040d2c */

/* Boundary evidence: original MIPS .pdata 00040d2c..00040df3. Semantic name remains unreviewed. */

void FUN_00040d2c(int param_1)

{
  uint uVar1;
  wchar_t *lpString;
  char local_18 [8];
  
  local_18[0] = '\0';
  uVar1 = FUN_000153dc(DAT_000648e4,1,0xcb,local_18,1,100);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"Get LHD Configuration .%d.\n",local_18[0]);
    if (local_18[0] == '\0') {
      lpString = L"LHD LHD";
    }
    else if (local_18[0] == '\x01') {
      lpString = L"LHD RHD";
    }
    else if (local_18[0] == '\x02') {
      lpString = L"LHD BHD";
    }
    else {
      lpString = L"LHD Unknown";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x70),lpString);
  }
  return;
}



/* 00040df4 FUN_00040df4 */

/* Boundary evidence: original MIPS .pdata 00040df4..00040e7f. Semantic name remains unreviewed. */

void FUN_00040df4(int param_1)

{
  uint uVar1;
  wchar_t *lpString;
  byte local_10 [8];
  
  local_10[0] = 0;
  uVar1 = FUN_000153dc(DAT_000648e4,1,0xca,local_10,1,100);
  if (uVar1 != 0) {
    if (local_10[0] < 0x17) {
      lpString = (wchar_t *)(&PTR_u_None_00064760)[local_10[0]];
    }
    else {
      lpString = L"xxxxxxxxx";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0xa0),lpString);
  }
  return;
}



/* 00040e80 FUN_00040e80 */

/* Boundary evidence: original MIPS .pdata 00040e80..00040f63. Semantic name remains unreviewed. */

void FUN_00040e80(int param_1)

{
  uint uVar1;
  byte local_a0;
  byte local_9f;
  byte local_9e;
  byte local_9d;
  byte local_9c;
  byte local_9b;
  byte local_9a;
  byte local_99;
  byte local_98;
  byte local_97;
  WCHAR aWStack_90 [64];
  uint local_10;
  
  local_10 = DAT_00064820;
  uVar1 = FUN_000153dc(DAT_000648e4,0xd,0x16,&local_a0,10,100);
  if (uVar1 == 0) {
    NKDbgPrintfW(L"\r\n[Error] UpdatePartNumber() == Get REG_DSI_CNF_REF...\r\n");
  }
  else {
    wsprintfW(aWStack_90,L"%C%C%C%C%C%C%C%C%C%C",(uint)local_a0,(uint)local_9f,(uint)local_9e,
              (uint)local_9d,(uint)local_9c,(uint)local_9b,(uint)local_9a,(uint)local_99,
              (uint)local_98,(uint)local_97);
    SetWindowTextW(*(HWND *)(param_1 + 0x98),aWStack_90);
  }
  FUN_0004a3f4(local_10);
  return;
}



/* 00040f64 FUN_00040f64 */

/* Boundary evidence: original MIPS .pdata 00040f64..00040ff3. Semantic name remains unreviewed. */

void FUN_00040f64(int param_1)

{
  uint uVar1;
  byte local_98;
  byte local_97;
  WCHAR aWStack_90 [64];
  uint local_10;
  
  local_10 = DAT_00064820;
  uVar1 = FUN_000153dc(DAT_000648e4,0xd,0xf,&local_98,2,0x96);
  if (uVar1 != 0) {
    wsprintfW(aWStack_90,L"MAP_CODE (%c%c)",(uint)local_98,(uint)local_97);
    SetWindowTextW(*(HWND *)(param_1 + 0xa4),aWStack_90);
  }
  FUN_0004a3f4(local_10);
  return;
}



/* 00040ff4 FUN_00040ff4 */

/* Boundary evidence: original MIPS .pdata 00040ff4..00041087. Semantic name remains unreviewed. */

void FUN_00040ff4(int param_1)

{
  uint uVar1;
  byte local_10 [8];
  
  uVar1 = FUN_000153dc(DAT_000648e4,0xd,0xd,local_10,1,0x96);
  if (uVar1 != 0) {
    uVar1 = (uint)local_10[0];
    if ((*(byte *)(param_1 + 0xb4) != uVar1) && (uVar1 < 10)) {
      *(byte *)(param_1 + 0xb4) = local_10[0];
      *(byte *)(param_1 + 0xb5) = local_10[0];
      SetWindowTextW(*(HWND *)(param_1 + 0x6c),(LPCWSTR)(&PTR_u_Dacia_000647bc)[uVar1]);
    }
  }
  return;
}



/* 00041088 FUN_00041088 */

/* Boundary evidence: original MIPS .pdata 00041088..0004114b. Semantic name remains unreviewed. */

void FUN_00041088(int param_1)

{
  uint uVar1;
  wchar_t *lpString;
  undefined1 local_18;
  undefined1 local_17;
  byte local_16;
  undefined1 local_15;
  undefined1 local_14;
  uint local_10;
  
  local_10 = DAT_00064820;
  uVar1 = FUN_000153dc(DAT_000648e4,6,7,&local_18,5,0x96);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"CMD_AMP_IB... [0x%02X][0x%02X][0x%02X][0x%02X][0x%02X]\n",local_18,local_17,
                 local_16,local_15,local_14);
    if ((local_16 & 0x40) == 0) {
      lpString = L"26dB Gain";
    }
    else {
      lpString = L"16dB Gain";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x68),lpString);
  }
  FUN_0004a3f4(local_10);
  return;
}



/* 0004114c FUN_0004114c */

/* Boundary evidence: original MIPS .pdata 0004114c..000411c3. Semantic name remains unreviewed. */

void FUN_0004114c(undefined4 param_1,undefined1 param_2)

{
  byte local_18;
  undefined1 local_17 [11];
  uint local_c;
  
  local_c = DAT_00064820;
  local_18 = 0;
  memset(local_17,0,9);
  DeleteFileW(L"\\Storage Card2\\EcoDrive.cfg");
  local_18 = 0x3e;
  local_17[0] = param_2;
  FUN_00036490(DAT_00064a24,&local_18);
  FUN_0004a3f4(local_c);
  return;
}



/* 000411c4 FUN_000411c4 */

/* Boundary evidence: original MIPS .pdata 000411c4..0004137f. Semantic name remains unreviewed. */

void FUN_000411c4(int param_1)

{
  uint uVar1;
  byte local_98 [8];
  WCHAR aWStack_90 [64];
  uint local_10;
  
  local_10 = DAT_00064820;
  local_98[0] = 0;
  uVar1 = FUN_000153dc(DAT_000648e4,1,0xcc,local_98,1,0x96);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"CONTROL_GET_ECO... [0x%02X][0x%02X]\n",*(undefined1 *)(param_1 + 0xb6),
                 local_98[0]);
    if ((uint)*(byte *)(param_1 + 0xb6) != (uint)local_98[0]) {
      *(byte *)(param_1 + 0xb6) = local_98[0];
      wsprintfW(aWStack_90,L"ADAC (%s)",(&PTR_u_L_100km_000647e4)[local_98[0] & 7]);
      SetWindowTextW(*(HWND *)(param_1 + 0x78),aWStack_90);
      wsprintfW(aWStack_90,L"TEMP (%s)",(&PTR_u_NoDisp_000647f8)[*(byte *)(param_1 + 0xb6) >> 3 & 3]
               );
      SetWindowTextW(*(HWND *)(param_1 + 0x7c),aWStack_90);
      wsprintfW(aWStack_90,L"AIR (%s)",
                (&PTR_u_Deactive_00064804)[*(byte *)(param_1 + 0xb6) >> 5 & 1]);
      SetWindowTextW(*(HWND *)(param_1 + 0x80),aWStack_90);
      wsprintfW(aWStack_90,L"ENG (%s)",(&PTR_DAT_0006480c)[*(byte *)(param_1 + 0xb6) >> 6 & 1]);
      SetWindowTextW(*(HWND *)(param_1 + 0x84),aWStack_90);
      wsprintfW(aWStack_90,L"ECO (%s)",(&PTR_u_Deactive_00064814)[*(byte *)(param_1 + 0xb6) >> 7]);
      SetWindowTextW(*(HWND *)(param_1 + 0x88),aWStack_90);
    }
  }
  FUN_0004a3f4(local_10);
  return;
}



/* 00041380 FUN_00041380 */

/* Boundary evidence: original MIPS .pdata 00041380..00041443. Semantic name remains unreviewed. */

void FUN_00041380(int param_1)

{
  uint uVar1;
  wchar_t *pwVar2;
  byte local_10 [8];
  
  uVar1 = FUN_000153dc(DAT_000648e4,0xd,0xe,local_10,1,0x96);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"CONTROL_GET_UI... [0x%02X][0x%02X]\n",*(undefined1 *)(param_1 + 0x12),local_10[0]
                );
    *(byte *)(param_1 + 0x12) = local_10[0];
    if ((local_10[0] & 0x20) == 0) {
      pwVar2 = L"RES Off";
    }
    else {
      pwVar2 = L"RES On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x8c),pwVar2);
    if ((*(byte *)(param_1 + 0x12) & 0x10) == 0) {
      pwVar2 = L"AHA Off";
    }
    else {
      pwVar2 = L"AHA On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x90),pwVar2);
  }
  return;
}



/* 00041444 FUN_00041444 */

/* Boundary evidence: original MIPS .pdata 00041444..000414ef. Semantic name remains unreviewed. */

void FUN_00041444(int param_1)

{
  uint uVar1;
  wchar_t *lpString;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + 0x13);
  if (*pcVar2 == '\0') {
    *pcVar2 = '\x01';
  }
  else {
    *pcVar2 = '\0';
  }
  uVar1 = FUN_000153dc(DAT_000648e4,0xd,0x4c,pcVar2,1,0xfa);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"[REG_DSI_CNF_SYS_AMP] USE BOSE AMP=%d\r\n",*pcVar2);
    if (*pcVar2 == '\0') {
      lpString = L"BOSE Deactivated";
    }
    else {
      lpString = L"BOSE Activated";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x94),lpString);
  }
  return;
}



/* 000414f0 FUN_000414f0 */

/* Boundary evidence: original MIPS .pdata 000414f0..0004183b. Semantic name remains unreviewed. */

void FUN_000414f0(int param_1)

{
  byte bVar1;
  uint uVar2;
  wchar_t *pwVar3;
  undefined2 local_18 [4];
  
  uVar2 = FUN_000153dc(DAT_000648e4,0xd,6,local_18,2,100);
  if (uVar2 != 0) {
    *(undefined2 *)(param_1 + 0x10) = local_18[0];
    if ((*(byte *)(param_1 + 0x10) & 1) == 1) {
      pwVar3 = L"RAD A(A)";
    }
    else {
      pwVar3 = L"RAD A(P)";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x1c),pwVar3);
    if ((*(byte *)(param_1 + 0x10) & 2) == 2) {
      pwVar3 = L"MW Off";
    }
    else {
      pwVar3 = L"MW On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x20),pwVar3);
    if ((*(byte *)(param_1 + 0x10) & 4) == 4) {
      pwVar3 = L"LW Off";
    }
    else {
      pwVar3 = L"LW On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x24),pwVar3);
    if ((*(byte *)(param_1 + 0x10) & 8) == 8) {
      pwVar3 = L"SPEED Off";
    }
    else {
      pwVar3 = L"SPEED On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x28),pwVar3);
    if ((*(byte *)(param_1 + 0x10) & 0x10) == 0) {
      pwVar3 = L"E-Call Off";
    }
    else {
      pwVar3 = L"E-Call On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x2c),pwVar3);
    if ((*(byte *)(param_1 + 0x10) & 0x20) == 0x20) {
      pwVar3 = L"MIC Off";
    }
    else {
      pwVar3 = L"MIC On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x30),pwVar3);
    bVar1 = *(byte *)(param_1 + 0x10) >> 6;
    if (bVar1 == 0) {
      pwVar3 = L"SWRC None";
    }
    else if (bVar1 == 1) {
      pwVar3 = L"SWRC #1";
    }
    else if (bVar1 == 2) {
      pwVar3 = L"SWRC #2";
    }
    else {
      pwVar3 = L"SWRC Unknown";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x34),pwVar3);
    if ((*(byte *)(param_1 + 0x11) & 1) == 1) {
      pwVar3 = L"DAB A(A)";
    }
    else {
      pwVar3 = L"DAB A(P)";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x38),pwVar3);
    if ((*(byte *)(param_1 + 0x11) & 2) == 0) {
      pwVar3 = L"DAB Off";
    }
    else {
      pwVar3 = L"DAB On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x3c),pwVar3);
    if ((*(byte *)(param_1 + 0x11) & 4) == 0) {
      pwVar3 = L"RVC Off";
    }
    else {
      pwVar3 = L"RVC On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x40),pwVar3);
    if ((*(byte *)(param_1 + 0x11) & 8) == 0) {
      pwVar3 = L"GPS";
    }
    else {
      pwVar3 = L"GNSS";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x44),pwVar3);
    if ((*(byte *)(param_1 + 0x11) & 0x10) == 0) {
      pwVar3 = L"SPK_R On";
    }
    else {
      pwVar3 = L"SPK_R Off";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x48),pwVar3);
    if ((*(byte *)(param_1 + 0x11) & 0x20) == 0) {
      pwVar3 = L"TWR_F On";
    }
    else {
      pwVar3 = L"TWR_F Off";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x4c),pwVar3);
    if ((*(byte *)(param_1 + 0x11) & 0x40) == 0) {
      pwVar3 = L"TWR_R On";
    }
    else {
      pwVar3 = L"TWR_R Off";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x50),pwVar3);
    if ((*(byte *)(param_1 + 0x11) & 0x80) == 0) {
      pwVar3 = L"PTT Off";
    }
    else {
      pwVar3 = L"PTT On";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x54),pwVar3);
  }
  return;
}



/* 0004183c FUN_0004183c */

/* Boundary evidence: original MIPS .pdata 0004183c..00042f93. Semantic name remains unreviewed. */

void FUN_0004183c(int param_1,uint param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  HWND hWnd;
  byte *pbVar5;
  char *pcVar6;
  byte bVar7;
  uint uVar8;
  wchar_t *pwVar9;
  undefined8 uVar10;
  undefined1 local_310;
  undefined1 local_30f;
  byte local_30e;
  bool local_30d;
  byte local_30c;
  char local_30b;
  byte local_30a;
  char local_309;
  byte local_308;
  byte local_307;
  byte local_306;
  undefined1 local_305;
  char local_304;
  undefined1 local_303;
  undefined1 local_302;
  undefined1 local_301;
  undefined1 local_300;
  undefined1 local_2ff;
  undefined1 local_2fe;
  undefined1 local_2fd;
  undefined1 local_2fc;
  byte local_2fb;
  undefined1 local_2fa;
  undefined1 local_2f9;
  undefined1 local_2f8 [88];
  WCHAR local_2a0;
  undefined1 auStack_29e [126];
  WCHAR local_220;
  undefined1 auStack_21e [126];
  WCHAR aWStack_1a0 [64];
  WCHAR aWStack_120 [64];
  WCHAR aWStack_a0 [64];
  uint local_20;
  
  local_20 = DAT_00064820;
  switch(param_2) {
  case 1:
    local_2fd = 0;
    FUN_00014db0(DAT_000648e4,1,0xd5,(int)&local_2fd,1,0x32);
    break;
  case 2:
    local_302 = 0;
    FUN_00015158(DAT_000648e4,1,1,0x1f,(int)&local_302,1,100);
    break;
  case 3:
    FUN_000153dc(DAT_000648e4,9,0x10,&local_2fc,2,0x32);
    uVar10 = __ultodp(local_2fc);
    uVar10 = __dpmul((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0x9999999a,0x3fb99999);
    wsprintfW(aWStack_1a0,L"BAT : %6.2fV(%d)",(int)uVar10,(int)((ulonglong)uVar10 >> 0x20),
              (uint)local_2fb);
    hWnd = *(HWND *)(param_1 + 0x14);
    pwVar9 = aWStack_1a0;
    goto LAB_00041c88;
  default:
    if ((param_2 < 0x14) || (0x28 < param_2)) {
      if ((param_2 < 0x2e) || (0x44 < param_2)) break;
      local_304 = (char)param_2 + -0x2e;
      FUN_00014db0(DAT_000648e4,1,0xca,(int)&local_304,1,100);
      goto switchD_0004188c_caseD_2d;
    }
    local_2f8[1] = 0x12;
    uVar8 = param_2 + 0xec & 0xff;
    local_2f8[3] = 0x24;
    local_2f8[4] = 0xc;
    local_2f8[6] = 0x3a;
    local_2f8[2] = 0x39;
    local_2f8[9] = 0x14;
    local_2f8[10] = 0x3b;
    local_2f8[0xb] = 0x26;
    local_2f8[7] = 0x25;
    local_2f8[0xf] = 0x27;
    local_2f8[0x10] = 3;
    local_2f8[0x11] = 0x16;
    local_2f8[5] = 0x13;
    local_2f8[0x12] = 0x3d;
    local_2f8[0x14] = 0xd;
    local_2f8[0x15] = 0x17;
    local_2f8[0x16] = 0x3e;
    local_2f8[0x13] = 0x28;
    local_2f8[0x17] = 0x29;
    local_2f8[0x19] = 0x18;
    local_2f8[0x1a] = 0x3f;
    local_2f8[0x1b] = 0x2a;
    local_2f8[0x18] = 4;
    local_2f8[0x1f] = 0x2b;
    local_2f8[0x20] = 6;
    local_2f8[0x21] = 0x1a;
    local_2f8[0x22] = 0x41;
    local_2f8[0] = 0;
    local_2f8[8] = 1;
    local_2f8[0xc] = 2;
    local_2f8[0xd] = 0x15;
    local_2f8[0xe] = 0x3c;
    local_2f8[0x1c] = 5;
    local_2f8[0x1d] = 0x19;
    local_2f8[0x1e] = 0x40;
    local_2f8[0x23] = 0x2c;
    local_2f8[0x24] = 0xe;
    local_2f8[0x25] = 0x1b;
    local_2f8[0x26] = 0x42;
    local_2f8[0x27] = 0x2d;
    local_2f8[0x29] = 0x1c;
    local_2f8[0x2a] = 0x43;
    local_2f8[0x2f] = 0x2f;
    local_2f8[0x30] = 9;
    local_2f8[0x28] = 7;
    local_2f8[0x2b] = 0x2e;
    local_2f8[0x34] = 0xf;
    local_2f8[0x35] = 0x1f;
    local_2f8[0x31] = 0x1e;
    local_2f8[0x32] = 0x45;
    local_2f8[0x33] = 0x30;
    local_2f8[0x39] = 0x20;
    local_2f8[0x3a] = 0x47;
    local_2f8[0x36] = 0x46;
    local_2f8[0x37] = 0x31;
    local_2f8[0x38] = 10;
    local_2f8[0x3e] = 0x48;
    local_2f8[0x3f] = 0x34;
    local_2f8[0x3b] = 0x33;
    local_2f8[0x3c] = 0x10;
    local_2f8[0x3d] = 0x21;
    local_2f8[0x43] = 0x36;
    local_2f8[0x44] = 0x11;
    local_2f8[0x40] = 0xb;
    local_2f8[0x41] = 0x22;
    local_2f8[0x42] = 0x49;
    local_2f8[0x4b] = 0x32;
    local_2f8[0x4f] = 0x35;
    local_2f8[0x2c] = 8;
    local_2f8[0x2d] = 0x1d;
    local_2f8[0x2e] = 0x44;
    local_2f8[0x45] = 0x23;
    local_2f8[0x46] = 0x4a;
    local_2f8[0x47] = 0x37;
    local_2f8[0x48] = 2;
    local_2f8[0x49] = 0x15;
    local_2f8[0x4a] = 0x3c;
    local_2f8[0x4c] = 5;
    local_2f8[0x4d] = 0x19;
    local_2f8[0x4e] = 0x40;
    local_2f8[0x50] = 8;
    local_2f8[0x51] = 0x1d;
    local_2f8[0x52] = 0x44;
    local_2f8[0x53] = 0x38;
    local_2fa = local_2f8[(uint)*(byte *)(param_1 + 0xb7) + uVar8 * 4];
    local_2f9 = 0x55;
    NKDbgPrintfW(L"Set ULC2x SKU Index..[%d][%d] \n",uVar8,local_2fa);
    FUN_00014db0(DAT_000648e4,1,0xc9,(int)&local_2fa,2,100);
  case 0x13:
    FUN_00040e80(param_1);
    break;
  case 6:
    local_305 = 0;
    NKDbgPrintfW(L"\n==>CONTROL_REQ_CAN_CONF - DSI config\n");
    FUN_00015158(DAT_000648e4,1,1,10,(int)&local_305,1,100);
    break;
  case 7:
    local_2fe = 1;
    NKDbgPrintfW(L"\n==>CONTROL_REQ_CLEAR_VIRGIN - Clear Virgin\n");
    FUN_00015158(DAT_000648e4,1,1,0x1f,(int)&local_2fe,1,100);
    break;
  case 8:
    local_300 = 1;
    NKDbgPrintfW(
                L"\n==>CONTROL_REQ_CLR_ALLCNF - All clear CAN configuration including Map code(2D2D) forcely..\n"
                );
    FUN_00015158(DAT_000648e4,0xd,1,2,(int)&local_300,1,0xfa);
    break;
  case 9:
    local_303 = 2;
    NKDbgPrintfW(
                L"\n==>CONTROL_REQ_CLR_ALLCNF2 - All clear CAN configuration including Map code(2A2A) forcely..\n"
                );
    FUN_00015158(DAT_000648e4,0xd,1,2,(int)&local_303,1,0xfa);
    break;
  case 10:
    local_301 = 3;
    NKDbgPrintfW(L"\n==>CONTROL_REQ_RVC_SWRC - Set active....RVC, SWRC \n");
    FUN_00015158(DAT_000648e4,0xd,1,2,(int)&local_301,1,0xfa);
    break;
  case 0xb:
    local_2ff = 4;
    NKDbgPrintfW(L"\n==>CONTROL_REQ_RVC_SWRC2 - Set active....RVC, new SWRC \n");
    FUN_00015158(DAT_000648e4,0xd,1,2,(int)&local_2ff,1,0xfa);
    break;
  case 0xc:
    local_220 = L'\0';
    memset(auStack_21e,0,0x7e);
    if (DAT_000685f3 == '\0') {
      pcVar6 = "\\Storage Card2\\ReadDsiDataConfig.bin";
      pwVar9 = L"CNF";
      iVar4 = 0x22;
    }
    else if (DAT_000685f3 == '\x01') {
      pcVar6 = "\\Storage Card2\\ReadDsiDataPact1.bin";
      pwVar9 = L"PACT1";
      iVar4 = 0x23;
    }
    else if (DAT_000685f3 == '\x02') {
      pcVar6 = "\\Storage Card2\\ReadDsiDataPact2.bin";
      pwVar9 = L"PACT2";
      iVar4 = 0x24;
    }
    else if (DAT_000685f3 == '\x03') {
      pcVar6 = "\\Storage Card2\\ReadDsiDataAudio.bin";
      pwVar9 = L"AUDIO";
      iVar4 = 0x25;
    }
    else {
      if (DAT_000685f3 != '\x04') {
        DAT_000685f3 = '\0';
        wsprintfW(&local_220,L"Complete-RD-DSI");
        hWnd = *(HWND *)(param_1 + 0x58);
        pwVar9 = &local_220;
        goto LAB_00041c88;
      }
      pcVar6 = "\\Storage Card2\\ReadDsiDataRadio.bin";
      pwVar9 = L"RADIO";
      iVar4 = 0x26;
    }
    iVar4 = FUN_00040364(param_1,iVar4,pwVar9,pcVar6);
    if (iVar4 == 0) {
      DAT_000685f3 = '\0';
      break;
    }
    DAT_000685f3 = DAT_000685f3 + '\x01';
    goto LAB_00041aa4;
  case 0xd:
    local_2a0 = L'\0';
    memset(auStack_29e,0,0x7e);
    if (DAT_000685f2 == '\0') {
      pcVar6 = "\\Storage Card2\\WriteDsiDataConfig.bin";
      pwVar9 = L"CNF";
      iVar4 = 0x22;
    }
    else if (DAT_000685f2 == '\x01') {
      pcVar6 = "\\Storage Card2\\WriteDsiDataPact1.bin";
      pwVar9 = L"PACT1";
      iVar4 = 0x23;
    }
    else if (DAT_000685f2 == '\x02') {
      pcVar6 = "\\Storage Card2\\WriteDsiDataPact2.bin";
      pwVar9 = L"PACT2";
      iVar4 = 0x24;
    }
    else if (DAT_000685f2 == '\x03') {
      pcVar6 = "\\Storage Card2\\WriteDsiDataAudio.bin";
      pwVar9 = L"AUDIO";
      iVar4 = 0x25;
    }
    else {
      if (DAT_000685f2 != '\x04') {
        DAT_000685f2 = '\0';
        wsprintfW(&local_2a0,L"Complete-WD-DSI");
        hWnd = *(HWND *)(param_1 + 0x5c);
        pwVar9 = &local_2a0;
        goto LAB_00041c88;
      }
      pcVar6 = "\\Storage Card2\\WriteDsiDataRadio.bin";
      pwVar9 = L"RADIO";
      iVar4 = 0x26;
    }
    iVar4 = FUN_00040648(param_1,iVar4,pwVar9,pcVar6);
    if (iVar4 == 0) {
      DAT_000685f2 = '\0';
      break;
    }
    DAT_000685f2 = DAT_000685f2 + '\x01';
LAB_00041aa4:
    PostMessageW(*(HWND *)(param_1 + 0xc),0xc,0,0);
    break;
  case 0xe:
    local_307 = 0;
    FUN_000153dc(DAT_000648e4,9,0x42,&local_307,1,0x96);
    wsprintfW(aWStack_120,L"ILL[%d]",(uint)local_307);
    hWnd = *(HWND *)(param_1 + 0x60);
    pwVar9 = aWStack_120;
    goto LAB_00041c88;
  case 0xf:
    if (*(char *)(param_1 + 0xb5) == '\0') {
      *(undefined1 *)(param_1 + 0xb5) = 9;
    }
    else {
      *(char *)(param_1 + 0xb5) = *(char *)(param_1 + 0xb5) + -1;
    }
    bVar7 = *(byte *)(param_1 + 0xb5);
    goto joined_r0x00041fdc;
  case 0x10:
    pbVar5 = (byte *)(param_1 + 0xb5);
    if ((*pbVar5 != *(byte *)(param_1 + 0xb4)) && (*pbVar5 < 10)) {
      FUN_00014db0(DAT_000648e4,0xd,0xb,(int)pbVar5,1,0x96);
      FUN_000326f0(*pbVar5);
      FUN_0001d598();
      FUN_00040ff4(param_1);
    }
    break;
  case 0x11:
    if (*(byte *)(param_1 + 0xb5) < 9) {
      *(byte *)(param_1 + 0xb5) = *(byte *)(param_1 + 0xb5) + 1;
    }
    else {
      *(undefined1 *)(param_1 + 0xb5) = 0;
    }
    bVar7 = *(byte *)(param_1 + 0xb5);
joined_r0x00041fdc:
    if (9 < bVar7) break;
    pwVar9 = (wchar_t *)(&PTR_u_Dacia_000647bc)[bVar7];
    hWnd = *(HWND *)(param_1 + 0x6c);
    goto LAB_00041c88;
  case 0x12:
    cVar2 = *(char *)(param_1 + 0xb7);
    if (cVar2 == '\0') {
      *(undefined1 *)(param_1 + 0xb7) = 1;
    }
    else if (cVar2 == '\x01') {
      *(undefined1 *)(param_1 + 0xb7) = 2;
    }
    else if (cVar2 == '\x02') {
      *(undefined1 *)(param_1 + 0xb7) = 3;
    }
    else {
      *(undefined1 *)(param_1 + 0xb7) = 0;
    }
    bVar1 = *(char *)(param_1 + 0xb7) == '\x03';
    if (bVar1) {
      EnableWindow(*(HWND *)(param_1 + 0xa8),1);
      EnableWindow(*(HWND *)(param_1 + 0xac),1);
    }
    else {
      EnableWindow(*(HWND *)(param_1 + 0xa8),0);
      EnableWindow(*(HWND *)(param_1 + 0xac),0);
    }
    EnableWindow(*(HWND *)(param_1 + 0xb0),(uint)bVar1);
    cVar2 = *(char *)(param_1 + 0xb7);
    if (cVar2 == '\0') {
      pwVar9 = L"ULC2.0";
    }
    else if (cVar2 == '\x01') {
      pwVar9 = L"ULC2.2";
    }
    else {
      if (cVar2 != '\x02') {
        hWnd = *(HWND *)(param_1 + 0x9c);
        if (cVar2 == '\x03') {
          pwVar9 = L"ULC2.3";
        }
        else {
          pwVar9 = L"TBD";
        }
        goto LAB_00041c88;
      }
      pwVar9 = L"ULC2.2 V";
    }
    hWnd = *(HWND *)(param_1 + 0x9c);
LAB_00041c88:
    SetWindowTextW(hWnd,pwVar9);
    break;
  case 0x2a:
    GetWindowTextW(*(HWND *)(param_1 + 100),aWStack_a0,10);
    pwVar9 = L"STB ON";
    iVar4 = wcscmp(aWStack_a0,L"STB ON");
    local_30d = iVar4 == 0;
    if (local_30d) {
      pwVar9 = L"STB OFF";
    }
    SetWindowTextW(*(HWND *)(param_1 + 100),pwVar9);
    FUN_00015158(DAT_000648e4,6,1,3,(int)&local_30d,1,0xfa);
    break;
  case 0x2b:
    FUN_00015158(DAT_000648e4,6,1,5,0,0,0xfa);
    FUN_00041088(param_1);
    break;
  case 0x2d:
switchD_0004188c_caseD_2d:
    FUN_00040df4(param_1);
    break;
  case 0x46:
    local_309 = '\0';
    uVar8 = FUN_000153dc(DAT_000648e4,1,0xcb,&local_309,1,100);
    if (uVar8 != 0) {
      if (local_309 == '\0') {
        local_310 = 1;
      }
      else if (local_309 == '\x01') {
        local_310 = 2;
      }
      else {
        local_310 = 0;
      }
      NKDbgPrintfW(L"Toggle LHD %d -> %d.\n",local_309,local_310);
      FUN_00014db0(DAT_000648e4,1,0xcb,(int)&local_310,1,100);
      FUN_00040d2c(param_1);
    }
    break;
  case 0x47:
    local_30b = '\0';
    uVar8 = FUN_000153dc(DAT_000648e4,1,0xde,&local_30b,1,100);
    if (uVar8 != 0) {
      local_30f = local_30b == '\0';
      NKDbgPrintfW(L"Toggle Loudness %d -> %d.\n",local_30b,local_30f);
      FUN_00014db0(DAT_000648e4,1,0xde,(int)&local_30f,1,100);
      FUN_00040c94(param_1);
    }
    break;
  case 0x48:
    local_30e = *(byte *)(param_1 + 0xb6);
    if ((local_30e & 7) < 5) {
      bVar7 = (local_30e & 7) + 1;
    }
    else {
      bVar7 = 0;
    }
    if (4 < bVar7) {
      bVar7 = 0;
    }
    local_30e = (bVar7 ^ local_30e) & 7 ^ local_30e;
    iVar4 = FUN_00014db0(DAT_000648e4,1,0xcc,(int)&local_30e,1,0x96);
    bVar7 = local_30e;
    goto joined_r0x0004244c;
  case 0x49:
    local_30c = *(byte *)(param_1 + 0xb6);
    uVar8 = (local_30c & 0x18) >> 3;
    if (uVar8 < 3) {
      uVar8 = uVar8 + 1;
    }
    else {
      uVar8 = 0;
    }
    if (2 < uVar8) {
      uVar8 = 0;
    }
    local_30c = ((byte)(uVar8 << 3) ^ local_30c) & 0x18 ^ local_30c;
    iVar4 = FUN_00014db0(DAT_000648e4,1,0xcc,(int)&local_30c,1,0x96);
    bVar7 = local_30c;
    goto joined_r0x00042338;
  case 0x4a:
    local_30a = *(byte *)(param_1 + 0xb6);
    uVar8 = (local_30a & 0x20) >> 5;
    if (uVar8 < 2) {
      uVar8 = uVar8 + 1;
    }
    else {
      uVar8 = 0;
    }
    if (1 < uVar8) {
      uVar8 = 0;
    }
    local_30a = ((byte)(uVar8 << 5) ^ local_30a) & 0x20 ^ local_30a;
    iVar4 = FUN_00014db0(DAT_000648e4,1,0xcc,(int)&local_30a,1,0x96);
    bVar7 = local_30a;
joined_r0x00042338:
    if (iVar4 == 0) break;
    goto LAB_00042210;
  case 0x4b:
    local_308 = *(byte *)(param_1 + 0xb6);
    uVar8 = (local_308 & 0x40) >> 6;
    if (uVar8 < 2) {
      uVar8 = uVar8 + 1;
    }
    else {
      uVar8 = 0;
    }
    if (1 < uVar8) {
      uVar8 = 0;
    }
    local_308 = ((byte)(uVar8 << 6) ^ local_308) & 0x40 ^ local_308;
    iVar4 = FUN_00014db0(DAT_000648e4,1,0xcc,(int)&local_308,1,0x96);
    bVar7 = local_308;
    goto joined_r0x0004244c;
  case 0x4c:
    bVar7 = -((char)*(byte *)(param_1 + 0xb6) >> 7);
    if (bVar7 < 2) {
      bVar7 = bVar7 + 1;
    }
    else {
      bVar7 = 0;
    }
    if (1 < bVar7) {
      bVar7 = 0;
    }
    local_306 = *(byte *)(param_1 + 0xb6) & 0x7f | bVar7 << 7;
    iVar4 = FUN_00014db0(DAT_000648e4,1,0xcc,(int)&local_306,1,0x96);
    bVar7 = local_306;
joined_r0x0004244c:
    if (iVar4 != 0) {
LAB_00042210:
      FUN_0004114c(param_1,bVar7);
      FUN_000411c4(param_1);
    }
    break;
  case 0x4d:
    pbVar5 = (byte *)(param_1 + 0x10);
    bVar7 = *pbVar5;
    if ((bVar7 & 1) == 1) {
      *pbVar5 = bVar7 & 0xfe;
    }
    else {
      *pbVar5 = bVar7 | 1;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,(int)pbVar5,2,100);
    goto LAB_000424b0;
  case 0x4e:
    pbVar5 = (byte *)(param_1 + 0x10);
    bVar7 = *pbVar5;
    if ((bVar7 & 2) == 2) {
      *pbVar5 = bVar7 & 0xfd;
    }
    else {
      *pbVar5 = bVar7 | 2;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,(int)pbVar5,2,100);
    goto LAB_000424b0;
  case 0x4f:
    pbVar5 = (byte *)(param_1 + 0x10);
    bVar7 = *pbVar5;
    if ((bVar7 & 4) == 4) {
      *pbVar5 = bVar7 & 0xfb;
    }
    else {
      *pbVar5 = bVar7 | 4;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,(int)pbVar5,2,100);
    goto LAB_000424b0;
  case 0x50:
    pbVar5 = (byte *)(param_1 + 0x10);
    bVar7 = *pbVar5;
    if ((bVar7 & 8) == 8) {
      *pbVar5 = bVar7 & 0xf7;
    }
    else {
      *pbVar5 = bVar7 | 8;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,(int)pbVar5,2,100);
    goto LAB_000424b0;
  case 0x51:
    pbVar5 = (byte *)(param_1 + 0x10);
    bVar7 = *pbVar5;
    if ((bVar7 & 0x10) == 0x10) {
      *pbVar5 = bVar7 & 0xef;
    }
    else {
      *pbVar5 = bVar7 | 0x10;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,(int)pbVar5,2,100);
    goto LAB_000424b0;
  case 0x52:
    pbVar5 = (byte *)(param_1 + 0x10);
    bVar7 = *pbVar5;
    if ((bVar7 & 0x20) == 0x20) {
      *pbVar5 = bVar7 & 0xdf;
    }
    else {
      *pbVar5 = bVar7 | 0x20;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,(int)pbVar5,2,100);
    goto LAB_000424b0;
  case 0x53:
    pbVar5 = (byte *)(param_1 + 0x10);
    bVar7 = *pbVar5;
    bVar3 = bVar7 >> 6;
    if (bVar3 == 0) {
      bVar7 = bVar7 & 0x3f | 0x40;
LAB_000426e8:
      *pbVar5 = bVar7;
    }
    else if (bVar3 == 1) {
      *pbVar5 = bVar7 & 0x3f | 0x80;
    }
    else {
      if (bVar3 == 2) {
        bVar7 = bVar7 & 0x3f;
        goto LAB_000426e8;
      }
      *pbVar5 = bVar7 | 0xc0;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,(int)pbVar5,2,100);
    goto LAB_000424b0;
  case 0x54:
    bVar7 = *(byte *)(param_1 + 0x11);
    if ((bVar7 & 1) == 1) {
      *(byte *)(param_1 + 0x11) = bVar7 & 0xfe;
    }
    else {
      *(byte *)(param_1 + 0x11) = bVar7 | 1;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,param_1 + 0x10,2,100);
    goto LAB_000424b0;
  case 0x55:
    bVar7 = *(byte *)(param_1 + 0x11);
    if ((bVar7 & 2) == 2) {
      *(byte *)(param_1 + 0x11) = bVar7 & 0xfd;
    }
    else {
      *(byte *)(param_1 + 0x11) = bVar7 | 2;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,param_1 + 0x10,2,100);
    goto LAB_000424b0;
  case 0x56:
    bVar7 = *(byte *)(param_1 + 0x11);
    if ((bVar7 & 4) == 4) {
      *(byte *)(param_1 + 0x11) = bVar7 & 0xfb;
    }
    else {
      *(byte *)(param_1 + 0x11) = bVar7 | 4;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,param_1 + 0x10,2,100);
    goto LAB_000424b0;
  case 0x57:
    bVar7 = *(byte *)(param_1 + 0x11);
    if ((bVar7 & 8) == 8) {
      *(byte *)(param_1 + 0x11) = bVar7 & 0xf7;
    }
    else {
      *(byte *)(param_1 + 0x11) = bVar7 | 8;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,param_1 + 0x10,2,100);
    goto LAB_000424b0;
  case 0x58:
    bVar7 = *(byte *)(param_1 + 0x11);
    if ((bVar7 & 0x10) == 0x10) {
      *(byte *)(param_1 + 0x11) = bVar7 & 0xef;
    }
    else {
      *(byte *)(param_1 + 0x11) = bVar7 | 0x10;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,param_1 + 0x10,2,100);
    goto LAB_000424b0;
  case 0x59:
    bVar7 = *(byte *)(param_1 + 0x11);
    if ((bVar7 & 0x20) == 0x20) {
      *(byte *)(param_1 + 0x11) = bVar7 & 0xdf;
    }
    else {
      *(byte *)(param_1 + 0x11) = bVar7 | 0x20;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,param_1 + 0x10,2,100);
    goto LAB_000424b0;
  case 0x5a:
    bVar7 = *(byte *)(param_1 + 0x11);
    if ((bVar7 & 0x40) == 0x40) {
      *(byte *)(param_1 + 0x11) = bVar7 & 0xbf;
    }
    else {
      *(byte *)(param_1 + 0x11) = bVar7 | 0x40;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,param_1 + 0x10,2,100);
    goto LAB_000424b0;
  case 0x5b:
    bVar7 = *(byte *)(param_1 + 0x11);
    if ((bVar7 & 0x80) == 0x80) {
      *(byte *)(param_1 + 0x11) = bVar7 & 0x7f;
    }
    else {
      *(byte *)(param_1 + 0x11) = bVar7 | 0x80;
    }
    FUN_00014db0(DAT_000648e4,0xd,6,param_1 + 0x10,2,100);
LAB_000424b0:
    FUN_000414f0(param_1);
    break;
  case 0x5c:
    pbVar5 = (byte *)(param_1 + 0x12);
    bVar7 = *pbVar5;
    if ((bVar7 & 0x20) == 0) {
      *pbVar5 = bVar7 | 0x20;
    }
    else {
      *pbVar5 = bVar7 & 0xdf;
    }
    FUN_00014db0(DAT_000648e4,0xd,0xc,(int)pbVar5,1,0x96);
    goto LAB_00042a70;
  case 0x5d:
    pbVar5 = (byte *)(param_1 + 0x12);
    bVar7 = *pbVar5;
    if ((bVar7 & 0x10) == 0) {
      *pbVar5 = bVar7 | 0x10;
    }
    else {
      *pbVar5 = bVar7 & 0xef;
    }
    FUN_00014db0(DAT_000648e4,0xd,0xf5,(int)pbVar5,1,0x96);
LAB_00042a70:
    FUN_00041380(param_1);
    break;
  case 0x5e:
    pcVar6 = (char *)(param_1 + 0x13);
    if (*pcVar6 == '\0') {
      *pcVar6 = '\x01';
    }
    else {
      *pcVar6 = '\0';
    }
    FUN_00014db0(DAT_000648e4,0xd,0x4c,(int)pcVar6,1,0x96);
    FUN_00041444(param_1);
  }
  FUN_0004a3f4(local_20);
  return;
}



/* 00042fa4 FUN_00042fa4 */

/* Boundary evidence: original MIPS .pdata 00042fa4..0004300b. Semantic name remains unreviewed. */

void FUN_00042fa4(int param_1,int param_2)

{
  WCHAR aWStack_90 [64];
  uint local_10;
  
  local_10 = DAT_00064820;
  if (param_2 == 0) {
    wsprintfW(aWStack_90,L"SPEED : %dcm/s",(uint)*(ushort *)(DAT_00064ae4 + 0xafe));
    SetWindowTextW(*(HWND *)(param_1 + 0x18),aWStack_90);
  }
  FUN_0004a3f4(local_10);
  return;
}



/* 0004300c FUN_0004300c */

/* Boundary evidence: original MIPS .pdata 0004300c..00043063. Semantic name remains unreviewed. */

undefined4 * FUN_0004300c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0005eb54;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00043064 FUN_00043064 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 00043064..00044047. Semantic name remains unreviewed. */

void FUN_00043064(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  HWND pHVar4;
  DWORD DVar5;
  wchar_t *lpString;
  HWND *ppHVar6;
  int iVar7;
  undefined4 auStack_100 [8];
  HWND local_e0 [4];
  HWND local_d0;
  HWND local_cc;
  HWND local_c8;
  HWND local_c4;
  HWND local_c0;
  HWND local_bc;
  HWND local_b8;
  HWND local_b4;
  HWND local_b0;
  HWND local_ac;
  HWND local_a8;
  HWND local_a4;
  HWND local_a0;
  HWND local_9c;
  HWND local_98;
  HWND local_94;
  HWND local_90;
  HWND local_8c;
  HWND local_88;
  HWND local_84;
  HWND local_80;
  HWND local_7c;
  HWND local_78;
  HWND local_74;
  HWND local_70;
  HWND local_6c;
  HWND local_68;
  HWND local_64;
  HWND local_60;
  HWND local_5c;
  HWND local_58;
  HWND local_54;
  HWND local_50;
  HWND local_4c;
  HWND local_48;
  HWND local_44;
  HWND local_40;
  HWND local_3c;
  HWND local_38;
  HWND local_34;
  HWND local_30;
  HWND local_2c;
  HWND local_28;
  HWND local_24;
  HWND local_20;
  HWND local_1c;
  
  memset(local_e0 + 1,0,0xc4);
  *(undefined4 *)(DAT_00064a24 + 0x10) = *(undefined4 *)(param_1 + 0xc);
  uVar2 = FUN_00044f30();
  uVar3 = FUN_00044f28();
  FUN_0003f5e0(auStack_100,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar3,uVar2);
  local_e0[0] = FUN_0003f6bc(auStack_100,2,L"DSI_Config",4,(HMENU)0x6);
  local_e0[1] = FUN_0003f6bc(auStack_100,2,L"Clear Virgin",4,(HMENU)0x7);
  local_e0[2] = FUN_0003f6bc(auStack_100,2,L"ClrCnf(2D)",4,(HMENU)0x8);
  local_e0[3] = FUN_0003f6bc(auStack_100,2,L"ClrCnf(2A)",4,(HMENU)0x9);
  local_d0 = FUN_0003f6bc(auStack_100,2,L"RVC_SWRC #2(2A)",6,(HMENU)0xa);
  local_cc = FUN_0003f6bc(auStack_100,2,L"RVC_SWRC #1(2A)",6,(HMENU)0xb);
  local_c8 = FUN_0003f6bc(auStack_100,2,L"DAB RESET",4,(HMENU)0x1);
  FUN_0003f674((int)auStack_100);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"BAT : xx.xV",6,(HMENU)0x3);
  *(HWND *)(param_1 + 0x14) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"SPEED : x cm/s",6,(HMENU)0x0);
  *(HWND *)(param_1 + 0x18) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"ILL[x]",4,(HMENU)0xe);
  *(HWND *)(param_1 + 0x60) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"STB OFF",4,(HMENU)0x2a);
  *(HWND *)(param_1 + 100) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"xxdB Gain",4,(HMENU)0x2b);
  *(HWND *)(param_1 + 0x68) = pHVar4;
  local_c4 = FUN_0003f6bc(auStack_100,2,L"<",2,(HMENU)0xf);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"xCNF_CMKx",4,(HMENU)0x10);
  *(HWND *)(param_1 + 0x6c) = pHVar4;
  local_c0 = FUN_0003f6bc(auStack_100,2,L">",2,(HMENU)0x11);
  FUN_0003f674((int)auStack_100);
  FUN_0003f614((int)auStack_100,0);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"ULC2.x",4,(HMENU)0x12);
  cVar1 = *(char *)(param_1 + 0xb7);
  *(HWND *)(param_1 + 0x9c) = pHVar4;
  if (cVar1 == '\0') {
    lpString = L"ULC2.0";
  }
  else if (cVar1 == '\x01') {
    lpString = L"ULC2.2";
  }
  else if (cVar1 == '\x02') {
    lpString = L"ULC2.2 V";
  }
  else if (cVar1 == '\x03') {
    lpString = L"ULC2.3";
  }
  else {
    lpString = L"TBD";
  }
  SetWindowTextW(pHVar4,lpString);
  local_bc = FUN_0003f6bc(auStack_100,2,L"M0 WEU",2,(HMENU)0x14);
  local_b8 = FUN_0003f6bc(auStack_100,2,L"M0 EEU",2,(HMENU)0x15);
  local_b4 = FUN_0003f6bc(auStack_100,2,L"M0 AMR",2,(HMENU)0x16);
  local_b0 = FUN_0003f6bc(auStack_100,2,L"M0 OTH",2,(HMENU)0x17);
  local_ac = FUN_0003f6bc(auStack_100,2,L"MI WEU",2,(HMENU)0x18);
  local_a8 = FUN_0003f6bc(auStack_100,2,L"MI EEU",2,(HMENU)0x19);
  local_a4 = FUN_0003f6bc(auStack_100,2,L"MI AMR",2,(HMENU)0x1a);
  local_a0 = FUN_0003f6bc(auStack_100,2,L"MI OTH",2,(HMENU)0x1b);
  local_9c = FUN_0003f6bc(auStack_100,2,L"X87 WEU",2,(HMENU)0x1c);
  local_98 = FUN_0003f6bc(auStack_100,2,L"X87 EEU",2,(HMENU)0x1d);
  local_94 = FUN_0003f6bc(auStack_100,2,L"X87 AMR",2,(HMENU)0x1e);
  local_90 = FUN_0003f6bc(auStack_100,2,L"X87 OTH",2,(HMENU)0x1f);
  FUN_0003f674((int)auStack_100);
  FUN_0003f614((int)auStack_100,0);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"28115xxxxR",4,(HMENU)0x13);
  *(HWND *)(param_1 + 0x98) = pHVar4;
  local_8c = FUN_0003f6bc(auStack_100,2,L"M0_WEU (+DAB)",3,(HMENU)0x20);
  local_88 = FUN_0003f6bc(auStack_100,2,L"M0_EEU (+DAB)",3,(HMENU)0x21);
  local_84 = FUN_0003f6bc(auStack_100,2,L"MI_WEU (+DAB)",3,(HMENU)0x22);
  local_80 = FUN_0003f6bc(auStack_100,2,L"MI_EEU (+DAB)",3,(HMENU)0x23);
  local_7c = FUN_0003f6bc(auStack_100,2,L"X87_WEU (+DAB)",3,(HMENU)0x24);
  local_78 = FUN_0003f6bc(auStack_100,2,L"X87_EEU (+DAB)",3,(HMENU)0x25);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"M0_OTH (+DAB)",3,(HMENU)0x26);
  *(HWND *)(param_1 + 0xa8) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"MI_OTH (+DAB)",3,(HMENU)0x27);
  *(HWND *)(param_1 + 0xac) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"X87_OTH (+DAB)",3,(HMENU)0x28);
  *(HWND *)(param_1 + 0xb0) = pHVar4;
  if (*(char *)(param_1 + 0xb7) != '\x03') {
    EnableWindow(*(HWND *)(param_1 + 0xa8),0);
    EnableWindow(*(HWND *)(param_1 + 0xac),0);
    EnableWindow(*(HWND *)(param_1 + 0xb0),0);
  }
  FUN_0003f674((int)auStack_100);
  FUN_0003f614((int)auStack_100,0);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"$xx xxxxxx",4,(HMENU)0x2d);
  *(HWND *)(param_1 + 0xa0) = pHVar4;
  local_74 = FUN_0003f6bc(auStack_100,2,L"$00 None",2,(HMENU)0x2e);
  local_70 = FUN_0003f6bc(auStack_100,2,L"$01 X87",2,(HMENU)0x2f);
  local_6c = FUN_0003f6bc(auStack_100,2,L"$02 B98",2,(HMENU)0x30);
  local_68 = FUN_0003f6bc(auStack_100,2,L"$03 K98",2,(HMENU)0x31);
  iVar7 = 0x32;
  local_64 = FUN_0003f6bc(auStack_100,2,L"$04 H79",2,(HMENU)0x32);
  local_60 = FUN_0003f6bc(auStack_100,2,L"$05 X87_2",2,(HMENU)0x33);
  local_5c = FUN_0003f6bc(auStack_100,2,L"$06 B98_2",2,(HMENU)0x34);
  local_58 = FUN_0003f6bc(auStack_100,2,L"$07 K98_2",2,(HMENU)0x35);
  local_54 = FUN_0003f6bc(auStack_100,2,L"$08 HHA",2,(HMENU)0x36);
  local_50 = FUN_0003f6bc(auStack_100,2,L"$09 X92",2,(HMENU)0x37);
  local_4c = FUN_0003f6bc(auStack_100,2,L"$0A BGA",2,(HMENU)0x38);
  local_48 = FUN_0003f6bc(auStack_100,2,L"$0B HGA",2,(HMENU)0x39);
  local_44 = FUN_0003f6bc(auStack_100,2,L"$0C X67",2,(HMENU)0x3a);
  FUN_0003f674((int)auStack_100);
  FUN_0003f614((int)auStack_100,0);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"MAP_CODE (xx)",4,(HMENU)0x2c);
  *(HWND *)(param_1 + 0xa4) = pHVar4;
  local_40 = FUN_0003f6bc(auStack_100,2,L"$0D X52Ph1  ",3,(HMENU)0x3b);
  local_3c = FUN_0003f6bc(auStack_100,2,L"$0E X52Ph2_1",3,(HMENU)0x3c);
  local_38 = FUN_0003f6bc(auStack_100,2,L"$0F X52Ph2_2",3,(HMENU)0x3d);
  local_34 = FUN_0003f6bc(auStack_100,2,L"$10 X52Ph2_3",3,(HMENU)0x3e);
  local_30 = FUN_0003f6bc(auStack_100,2,L"$11 X52Ph2_4",3,(HMENU)0x3f);
  local_2c = FUN_0003f6bc(auStack_100,2,L"$12 X52Ph2_5",3,(HMENU)0x40);
  local_28 = FUN_0003f6bc(auStack_100,2,L"$13 X62",2,(HMENU)0x41);
  local_24 = FUN_0003f6bc(auStack_100,2,L"$14 X82",2,(HMENU)0x42);
  local_20 = FUN_0003f6bc(auStack_100,2,L"$15 X82Ph2",3,(HMENU)0x43);
  local_1c = FUN_0003f6bc(auStack_100,2,L"$16 XBB",2,(HMENU)0x44);
  FUN_0003f674((int)auStack_100);
  FUN_0003f614((int)auStack_100,0);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"ADAC (xxx)",4,(HMENU)0x48);
  *(HWND *)(param_1 + 0x78) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"TEMP (xxx)",4,(HMENU)0x49);
  *(HWND *)(param_1 + 0x7c) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"AIR (xxx)",4,(HMENU)0x4a);
  *(HWND *)(param_1 + 0x80) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"ENG (xxx)",4,(HMENU)0x4b);
  *(HWND *)(param_1 + 0x84) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"ECO (xxx)",4,(HMENU)0x4c);
  *(HWND *)(param_1 + 0x88) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"LHD xxx",2,(HMENU)0x46);
  *(HWND *)(param_1 + 0x70) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"TMC xx",2,(HMENU)0x47);
  *(HWND *)(param_1 + 0x74) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"RES xxx",2,(HMENU)0x5c);
  *(HWND *)(param_1 + 0x8c) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"AHA xxx",2,(HMENU)0x5d);
  *(HWND *)(param_1 + 0x90) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"BOSE xxx",4,(HMENU)0x5e);
  *(HWND *)(param_1 + 0x94) = pHVar4;
  FUN_0003f674((int)auStack_100);
  FUN_0003f614((int)auStack_100,0);
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"RAD A(X)",2,(HMENU)0x4d);
  *(HWND *)(param_1 + 0x1c) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"MW (x)",2,(HMENU)0x4e);
  *(HWND *)(param_1 + 0x20) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"LW (x)",2,(HMENU)0x4f);
  *(HWND *)(param_1 + 0x24) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"SPEEED (x)",2,(HMENU)0x50);
  *(HWND *)(param_1 + 0x28) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"E-Call (x)",2,(HMENU)0x51);
  *(HWND *)(param_1 + 0x2c) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"MIC (x)",2,(HMENU)0x52);
  *(HWND *)(param_1 + 0x30) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"SWRC (x)",4,(HMENU)0x53);
  *(HWND *)(param_1 + 0x34) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"DAB A(X)",2,(HMENU)0x54);
  *(HWND *)(param_1 + 0x38) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"DAB (x)",2,(HMENU)0x55);
  *(HWND *)(param_1 + 0x3c) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"RVC (x)",2,(HMENU)0x56);
  *(HWND *)(param_1 + 0x40) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"GPS (x)",2,(HMENU)0x57);
  *(HWND *)(param_1 + 0x44) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"SPK_R (x)",2,(HMENU)0x58);
  *(HWND *)(param_1 + 0x48) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"TWR_F (x)",2,(HMENU)0x59);
  *(HWND *)(param_1 + 0x4c) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"TWR_R (x)",2,(HMENU)0x5a);
  *(HWND *)(param_1 + 0x50) = pHVar4;
  pHVar4 = FUN_0003f6bc(auStack_100,2,L"PTT (x)",2,(HMENU)0x5b);
  *(HWND *)(param_1 + 0x54) = pHVar4;
  DVar5 = GetFileAttributesW(L"\\MD\\mcmtest_activate.ini");
  if ((DVar5 == 0xffffffff) &&
     (DVar5 = GetFileAttributesW(L"\\MD\\mcmtest_activate_4nng.ini"), DVar5 != 0xffffffff)) {
    ppHVar6 = local_e0;
    do {
      EnableWindow(*ppHVar6,0);
      iVar7 = iVar7 + -1;
      ppHVar6 = ppHVar6 + 1;
    } while (iVar7 != 0);
    EnableWindow(*(HWND *)(param_1 + 0x14),0);
    EnableWindow(*(HWND *)(param_1 + 0x18),0);
    EnableWindow(*(HWND *)(param_1 + 0x60),0);
    EnableWindow(*(HWND *)(param_1 + 100),0);
    EnableWindow(*(HWND *)(param_1 + 0x68),0);
    EnableWindow(*(HWND *)(param_1 + 0x6c),0);
    EnableWindow(*(HWND *)(param_1 + 0x9c),0);
    EnableWindow(*(HWND *)(param_1 + 0x70),0);
    EnableWindow(*(HWND *)(param_1 + 0x74),0);
    EnableWindow(*(HWND *)(param_1 + 0x94),0);
    EnableWindow(*(HWND *)(param_1 + 0x1c),0);
    EnableWindow(*(HWND *)(param_1 + 0x20),0);
    EnableWindow(*(HWND *)(param_1 + 0x24),0);
    EnableWindow(*(HWND *)(param_1 + 0x28),0);
    EnableWindow(*(HWND *)(param_1 + 0x2c),0);
    EnableWindow(*(HWND *)(param_1 + 0x30),0);
    EnableWindow(*(HWND *)(param_1 + 0x34),0);
    EnableWindow(*(HWND *)(param_1 + 0x38),0);
    EnableWindow(*(HWND *)(param_1 + 0x3c),0);
    EnableWindow(*(HWND *)(param_1 + 0x40),0);
    EnableWindow(*(HWND *)(param_1 + 0x48),0);
    EnableWindow(*(HWND *)(param_1 + 0x4c),0);
    EnableWindow(*(HWND *)(param_1 + 0x50),0);
  }
  FUN_000414f0(param_1);
  FUN_00041380(param_1);
  FUN_00041444(param_1);
  FUN_000411c4(param_1);
  FUN_00040f64(param_1);
  FUN_00040ff4(param_1);
  FUN_00041088(param_1);
  FUN_00040e80(param_1);
  FUN_00040df4(param_1);
  FUN_00040d2c(param_1);
  FUN_00040c94(param_1);
  FUN_00036f60();
  return;
}



/* 00044048 Unwind@00044048 */

/* Boundary evidence: original MIPS .pdata 00044048..00044077. Semantic name remains unreviewed. */

void Unwind_00044048(void)

{
  FUN_00036f60();
  return;
}



/* 00044078 FUN_00044078 */

/* Boundary evidence: original MIPS .pdata 00044078..0004409b. Semantic name remains unreviewed. */

void FUN_00044078(int param_1)

{
  FUN_00044f38(param_1,100,500,(TIMERPROC)0x0);
  return;
}



/* 0004409c FUN_0004409c */

/* Boundary evidence: original MIPS .pdata 0004409c..000440e7. Semantic name remains unreviewed. */

void FUN_0004409c(int param_1)

{
  FUN_00044f54(param_1,100);
  if (DAT_000685f4 != (undefined4 *)0x0) {
    (**(code **)*DAT_000685f4)(DAT_000685f4,1);
    DAT_000685f4 = (undefined4 *)0x0;
  }
  return;
}



/* 000440e8 FUN_000440e8 */

/* Boundary evidence: original MIPS .pdata 000440e8..000441cf. Semantic name remains unreviewed. */

HFONT FUN_000440e8(LONG param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,BYTE param_6,
                  BYTE param_7,BYTE param_8,BYTE param_9,BYTE param_10,BYTE param_11,BYTE param_12,
                  BYTE param_13,LPCWSTR param_14)

{
  HFONT pHVar1;
  LOGFONTW local_78;
  uint local_1c;
  
  local_1c = DAT_00064820;
  memset(&local_78,0,0x5c);
  local_78.lfWeight = param_5;
  local_78.lfItalic = param_6;
  local_78.lfUnderline = param_7;
  local_78.lfStrikeOut = param_8;
  local_78.lfCharSet = param_9;
  local_78.lfOutPrecision = param_10;
  local_78.lfClipPrecision = param_11;
  local_78.lfQuality = param_12;
  local_78.lfPitchAndFamily = param_13;
  local_78.lfHeight = param_1;
  local_78.lfWidth = param_2;
  local_78.lfEscapement = param_3;
  local_78.lfOrientation = param_4;
  wsprintfW(local_78.lfFaceName,param_14);
  pHVar1 = CreateFontIndirectW(&local_78);
  FUN_0004a3f4(local_1c);
  return pHVar1;
}



/* 000441d0 FUN_000441d0 */

/* Boundary evidence: original MIPS .pdata 000441d0..000443b3. Semantic name remains unreviewed. */

void FUN_000441d0(undefined4 param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,
                 COLORREF param_6,LPCWSTR param_7)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HFONT h_01;
  HGDIOBJ h_02;
  int x;
  int y;
  RECT *lprc;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  lprc = (RECT *)(&DAT_000600e8 + param_3 * 4);
  FUN_0003da78(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_000440e8(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,5);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_000600ec)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_000600f0)[param_3 * 4] - x,(&DAT_000600f4)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 000443b4 FUN_000443b4 */

/* Boundary evidence: original MIPS .pdata 000443b4..000444a7. Semantic name remains unreviewed. */

void FUN_000443b4(undefined4 param_1,HDC param_2)

{
  if (DAT_00068074 == 1) {
    FUN_000441d0(param_1,param_2,2,0x1c,0xc8c8c8,0,L"MICOM");
    FUN_000441d0(param_1,param_2,3,0x1c,0xc8c8c8,0xb43232,L"PC");
  }
  else {
    FUN_000441d0(param_1,param_2,2,0x1c,0xc8c8c8,0xb43232,L"MICOM");
    FUN_000441d0(param_1,param_2,3,0x1c,0xc8c8c8,0,L"PC");
  }
  return;
}



/* 000444a8 FUN_000444a8 */

/* Boundary evidence: original MIPS .pdata 000444a8..00044653. Semantic name remains unreviewed. */

void FUN_000444a8(undefined4 param_1,HDC param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  byte local_138;
  byte local_137;
  WCHAR aWStack_130 [128];
  uint local_30;
  
  local_30 = DAT_00064820;
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = 0;
  uVar1 = FUN_000153dc(DAT_000648e4,9,4,&local_138,2,200);
  if (uVar1 == 2) {
    uVar5 = __ultofp((uint)local_137 * 0x100 + (uint)local_138);
  }
  uVar1 = FUN_000153dc(DAT_000648e4,9,0x40,&local_138,1,200);
  if (uVar1 == 1) {
    uVar4 = (uint)local_138;
  }
  uVar1 = FUN_000153dc(DAT_000648e4,9,3,&local_138,1,200);
  if (uVar1 == 1) {
    uVar3 = (uint)local_138;
  }
  uVar2 = __fpmul(uVar5,0x3d1374bc);
  uVar6 = __fptodp(uVar2);
  uVar5 = __fpmul(uVar5,0x3c23d70a);
  uVar7 = __fptodp(uVar5);
  wsprintfW(aWStack_130,L"%6.2fm/s   %6.2fKm/h   %d   %d",(int)uVar7,(int)((ulonglong)uVar7 >> 0x20)
            ,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar4,uVar3);
  FUN_000441d0(param_1,param_2,5,0x1c,0xffffff,0,aWStack_130);
  FUN_0004a3f4(local_30);
  return;
}



/* 00044654 FUN_00044654 */

/* Boundary evidence: original MIPS .pdata 00044654..000447eb. Semantic name remains unreviewed. */

void FUN_00044654(undefined4 param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  RECT local_30;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  local_30.left = 0;
  local_30.top = 0;
  local_30.right = 800;
  local_30.bottom = 0x1e0;
  FUN_0003da78(param_1,hdc,&local_30,0);
  FUN_000441d0(param_1,hdc,0,0x2e,0xffffff,0,L"BACK");
  FUN_000441d0(param_1,hdc,1,0x24,0xffffff,0,L"DSP target device");
  FUN_000443b4(param_1,hdc);
  FUN_000441d0(param_1,hdc,4,0x24,0xffffff,0,L"Vehicle Speed");
  FUN_000444a8(param_1,hdc);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 000447ec FUN_000447ec */

void FUN_000447ec(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = &DAT_000600e8;
  while ((((param_2 <= *piVar2 || (piVar2[2] <= param_2)) || (param_3 <= piVar2[1])) ||
         (piVar2[3] <= param_3))) {
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 4;
    if (5 < uVar1) {
      return;
    }
  }
  return;
}



/* 00044858 FUN_00044858 */

/* Boundary evidence: original MIPS .pdata 00044858..00044947. Semantic name remains unreviewed. */

void FUN_00044858(int param_1,int param_2,int param_3)

{
  int iVar1;
  HDC hDC;
  undefined1 local_18 [8];
  
  iVar1 = FUN_000447ec(param_1,param_2,param_3);
  if (iVar1 == 0) {
    DestroyWindow(*(HWND *)(param_1 + 0xc));
  }
  else {
    if (iVar1 == 2) {
      local_18[0] = 0;
      FUN_00014db0(DAT_000648e4,0,0x30,(int)local_18,1,0x32);
      DAT_00068074 = 0;
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      local_18[0] = 1;
      FUN_00014db0(DAT_000648e4,0,0x30,(int)local_18,1,0x32);
      DAT_00068074 = 1;
    }
    hDC = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_000443b4(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 0xc),hDC);
  }
  return;
}



/* 00044948 FUN_00044948 */

/* Boundary evidence: original MIPS .pdata 00044948..000449ef. Semantic name remains unreviewed. */

void FUN_00044948(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_000450c0();
  if (DAT_000685f4 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_00044b4c(puVar1);
      *puVar1 = &PTR_FUN_00060148;
    }
    DAT_000685f4 = puVar1;
    FUN_00044b7c((int)puVar1,DAT_00064aac,param_1);
  }
  return;
}



/* 000449f0 Unwind@000449f0 */

/* Boundary evidence: original MIPS .pdata 000449f0..00044a1f. Semantic name remains unreviewed. */

void Unwind_000449f0(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x20));
  return;
}



/* 00044a20 FUN_00044a20 */

/* Boundary evidence: original MIPS .pdata 00044a20..00044a77. Semantic name remains unreviewed. */

undefined4 * FUN_00044a20(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00060148;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00044a78 FUN_00044a78 */

/* Boundary evidence: original MIPS .pdata 00044a78..00044acb. Semantic name remains unreviewed. */

void FUN_00044a78(int param_1,int param_2)

{
  HDC hDC;
  
  if (param_2 == 100) {
    hDC = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_000444a8(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 0xc),hDC);
  }
  return;
}



/* 00044acc FUN_00044acc */

/* Boundary evidence: original MIPS .pdata 00044acc..00044b4b. Semantic name remains unreviewed. */

void FUN_00044acc(void)

{
  HWND hWnd;
  HWND hWnd_00;
  
  hWnd = FindWindowW(L"TESTWND",(LPCWSTR)0x0);
  hWnd_00 = FindWindowW(L"TESTWND2",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    PostMessageW(hWnd,0x10,0,0);
  }
  if (hWnd_00 != (HWND)0x0) {
    PostMessageW(hWnd_00,0x10,0,0);
  }
  return;
}



/* 00044b4c FUN_00044b4c */

undefined4 * FUN_00044b4c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00060254;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



/* 00044b6c FUN_00044b6c */

void FUN_00044b6c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00060254;
  return;
}



/* 00044b7c FUN_00044b7c */

/* Boundary evidence: original MIPS .pdata 00044b7c..00044c6b. Semantic name remains unreviewed. */

void FUN_00044b7c(int param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  int *piVar1;
  
  DAT_0006481c = DAT_0006481c + 1;
  piVar1 = &DAT_000685fc + DAT_0006481c;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *piVar1 = param_1;
  hWnd = CreateWindowExW(0,L"TESTWND",L"",0x10000000,0,0,800,0x1e0,(HWND)0x0,(HMENU)0x0,DAT_00064aac
                         ,(LPVOID)0x0);
  SetWindowPos(hWnd,(HWND)0xffffffff,0,0,0,0,3);
  ShowWindow(hWnd,1);
  SetWindowPos(hWnd,(HWND)0x0,0,0,0,0,3);
  return;
}



/* 00044c6c FUN_00044c6c */

/* Boundary evidence: original MIPS .pdata 00044c6c..00044d5b. Semantic name remains unreviewed. */

void FUN_00044c6c(int param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  int *piVar1;
  
  DAT_0006481c = DAT_0006481c + 1;
  piVar1 = &DAT_000685fc + DAT_0006481c;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *piVar1 = param_1;
  hWnd = CreateWindowExW(0,L"TESTWND2",L"",0x10000000,0,0,800,0x1e0,(HWND)0x0,(HMENU)0x0,
                         DAT_00064aac,(LPVOID)0x0);
  SetWindowPos(hWnd,(HWND)0xffffffff,0,0,0,0,3);
  ShowWindow(hWnd,1);
  SetWindowPos(hWnd,(HWND)0x0,0,0,0,0,3);
  return;
}



/* 00044d5c FUN_00044d5c */

/* Boundary evidence: original MIPS .pdata 00044d5c..00044f27. Semantic name remains unreviewed. */

LRESULT FUN_00044d5c(int *param_1,HWND param_2,uint param_3,uint param_4,uint param_5)

{
  HDC pHVar1;
  code *pcVar2;
  LRESULT LVar3;
  tagPAINTSTRUCT tStack_58;
  uint local_18;
  
  local_18 = DAT_00064820;
  LVar3 = 0;
  if (param_3 < 0x114) {
    if (param_3 == 0x113) {
      (**(code **)(*param_1 + 0x1c))(param_1,param_4);
      goto LAB_00044f04;
    }
    if (param_3 == 1) {
      pcVar2 = *(code **)(*param_1 + 0xc);
      param_1[3] = (int)param_2;
    }
    else {
      if (param_3 != 2) {
        if (param_3 == 0xf) {
          pHVar1 = BeginPaint(param_2,&tStack_58);
          (**(code **)(*param_1 + 0x10))(param_1,pHVar1);
          EndPaint(param_2,&tStack_58);
          goto LAB_00044f04;
        }
        if (param_3 == 0x111) {
          (**(code **)(*param_1 + 0x20))(param_1,param_4 & 0xffff);
          goto LAB_00044f04;
        }
        goto LAB_00044e90;
      }
      pcVar2 = *(code **)(*param_1 + 0x28);
    }
    (*pcVar2)(param_1);
  }
  else {
    if (param_3 == 0x201) {
      pcVar2 = *(code **)(*param_1 + 0x14);
    }
    else {
      if (param_3 != 0x202) {
        if (param_3 == 0x403) {
          (**(code **)(*param_1 + 0x24))(param_1,param_4,param_5);
          goto LAB_00044f04;
        }
LAB_00044e90:
        LVar3 = DefWindowProcW(param_2,param_3,param_4,param_5);
        goto LAB_00044f04;
      }
      pcVar2 = *(code **)(*param_1 + 0x18);
    }
    (*pcVar2)(param_1,param_5 & 0xffff,param_5 >> 0x10);
  }
LAB_00044f04:
  FUN_0004a3f4(local_18);
  return LVar3;
}



/* 00044f28 FUN_00044f28 */

undefined4 FUN_00044f28(void)

{
  return 800;
}



/* 00044f30 FUN_00044f30 */

undefined4 FUN_00044f30(void)

{
  return 0x1e0;
}



/* 00044f38 FUN_00044f38 */

/* Boundary evidence: original MIPS .pdata 00044f38..00044f53. Semantic name remains unreviewed. */

void FUN_00044f38(int param_1,UINT_PTR param_2,UINT param_3,TIMERPROC param_4)

{
  SetTimer(*(HWND *)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}



/* 00044f54 FUN_00044f54 */

/* Boundary evidence: original MIPS .pdata 00044f54..00044f6f. Semantic name remains unreviewed. */

void FUN_00044f54(int param_1,UINT_PTR param_2)

{
  KillTimer(*(HWND *)(param_1 + 0xc),param_2);
  return;
}



/* 00044f70 FUN_00044f70 */

/* Boundary evidence: original MIPS .pdata 00044f70..00044fcf. Semantic name remains unreviewed. */

void FUN_00044f70(int *param_1,int param_2)

{
  code *pcVar1;
  
  if (param_2 == 0) {
    DestroyWindow((HWND)param_1[3]);
  }
  else {
    if (param_2 == 2) {
      pcVar1 = *(code **)(*param_1 + 8);
    }
    else {
      if (param_2 != 3) {
        return;
      }
      pcVar1 = *(code **)(*param_1 + 4);
    }
    (*pcVar1)();
  }
  return;
}



/* 00044fd0 FUN_00044fd0 */

/* Boundary evidence: original MIPS .pdata 00044fd0..00045087. Semantic name remains unreviewed. */

LRESULT FUN_00044fd0(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  LRESULT LVar1;
  undefined4 *puVar2;
  
  LVar1 = FUN_00044d5c((int *)(&DAT_000685fc)[DAT_0006481c],param_1,param_2,param_3,param_4);
  if (param_2 == 2) {
    puVar2 = (undefined4 *)(&DAT_000685fc)[DAT_0006481c];
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(puVar2,1);
    }
    puVar2 = &DAT_000685fc + DAT_0006481c;
    DAT_0006481c = DAT_0006481c + -1;
    *puVar2 = 0;
  }
  return LVar1;
}



/* 00045088 FUN_00045088 */

/* Boundary evidence: original MIPS .pdata 00045088..000450bf. Semantic name remains unreviewed. */

void FUN_00045088(int param_1)

{
  FUN_00044f70((int *)(&DAT_000685fc)[DAT_0006481c],param_1);
  return;
}



/* 000450c0 FUN_000450c0 */

/* Boundary evidence: original MIPS .pdata 000450c0..000451c3. Semantic name remains unreviewed. */

void FUN_000450c0(void)

{
  WNDCLASSW local_40;
  
  if (DAT_000685f8 == 0) {
    local_40.cbClsExtra = 0;
    local_40.cbWndExtra = 0;
    local_40.hbrBackground = GetStockObject(1);
    local_40.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_40.hIcon = (HICON)0x0;
    local_40.hInstance = DAT_00064aac;
    local_40.lpfnWndProc = FUN_00044fd0;
    local_40.lpszClassName = L"TESTWND";
    local_40.lpszMenuName = (LPCWSTR)0x0;
    local_40.style = 3;
    RegisterClassW(&local_40);
    local_40.cbClsExtra = 0;
    local_40.cbWndExtra = 0;
    local_40.hbrBackground = GetStockObject(4);
    local_40.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_40.hIcon = (HICON)0x0;
    local_40.hInstance = DAT_00064aac;
    local_40.lpfnWndProc = FUN_00044fd0;
    local_40.lpszClassName = L"TESTWND2";
    local_40.lpszMenuName = (LPCWSTR)0x0;
    local_40.style = 3;
    RegisterClassW(&local_40);
    DAT_000685f8 = 1;
  }
  return;
}



/* 000451c4 FUN_000451c4 */

/* Boundary evidence: original MIPS .pdata 000451c4..00045207. Semantic name remains unreviewed. */

undefined4 * FUN_000451c4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00060254;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00045208 FUN_00045208 */

/* Boundary evidence: original MIPS .pdata 00045208..00045277. Semantic name remains unreviewed. */

undefined4 * FUN_00045208(undefined4 *param_1)

{
  FUN_00044b4c(param_1);
  *param_1 = &PTR_FUN_00060280;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  return param_1;
}



/* 00045278 FUN_00045278 */

/* Boundary evidence: original MIPS .pdata 00045278..00045767. Semantic name remains unreviewed. */

void FUN_00045278(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  HWND pHVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined4 auStack_188 [8];
  undefined1 auStack_168 [4];
  byte local_164;
  byte local_163;
  ushort local_162;
  undefined4 local_140;
  undefined4 local_13c;
  ushort local_120;
  ushort local_11e;
  ushort local_118;
  ushort local_110;
  byte local_10c;
  ushort local_c0;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00064820;
  *(undefined4 *)(DAT_000673c8 + 0x5c) = *(undefined4 *)(param_1 + 0xc);
  puVar6 = auStack_168;
  FUN_00015158(DAT_000648e4,0xf,1,3,0,0,0x32);
  uVar4 = 0xb4;
  do {
    uVar5 = 0x40;
    if (uVar4 < 0x41) {
      uVar5 = uVar4;
    }
    uVar1 = FUN_000153dc(DAT_000648e4,0xf,1,puVar6,(byte)uVar5,100);
    if (uVar1 != 0) {
      puVar6 = puVar6 + uVar5;
      uVar4 = uVar4 - uVar5;
    }
  } while (uVar4 != 0);
  uVar2 = FUN_00044f30();
  uVar4 = FUN_00044f28();
  FUN_0003f5e0(auStack_188,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar4,uVar2);
  FUN_0003f6bc(auStack_188,1,L"IF FILTER(TMC/FM/AM)",6,(HMENU)0x0);
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_10c);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x1c) = pHVar3;
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_164);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x20) = pHVar3;
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_163);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x24) = pHVar3;
  FUN_0003f674((int)auStack_188);
  FUN_0003f6bc(auStack_188,1,L"DSP-Xtal Error",6,(HMENU)0x0);
  if ((local_162 & 0x800) != 0) {
    local_162 = local_162 | 0xf000;
  }
  uVar7 = __litodp((int)(short)local_162);
  uVar7 = __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3fa90000);
  wsprintfW(aWStack_b0,L"%5.2f",(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x28) = pHVar3;
  FUN_0003f674((int)auStack_188);
  FUN_0003f6bc(auStack_188,1,L"FM OFFSET",6,(HMENU)0x0);
  wsprintfW(aWStack_b0,L"0x%06X",local_140);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x2c) = pHVar3;
  wsprintfW(aWStack_b0,L"0x%06X",local_13c);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x30) = pHVar3;
  FUN_0003f674((int)auStack_188);
  FUN_0003f6bc(auStack_188,1,L"LV(TMC/FM/MW/LW)",6,(HMENU)0x0);
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_c0);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x34) = pHVar3;
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_118);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x38) = pHVar3;
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_11e);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x3c) = pHVar3;
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_120);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x40) = pHVar3;
  FUN_0003f674((int)auStack_188);
  FUN_0003f6bc(auStack_188,1,L"FM CH SEP",6,(HMENU)0x0);
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_110);
  pHVar3 = FUN_0003f6bc(auStack_188,1,aWStack_b0,4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x44) = pHVar3;
  FUN_0003f69c((int)auStack_188);
  pHVar3 = FUN_0003f6bc(auStack_188,1,L"START",0xe,(HMENU)0x1);
  *(HWND *)(param_1 + 0x10) = pHVar3;
  FUN_0003f674((int)auStack_188);
  pHVar3 = FUN_0003f6bc(auStack_188,1,L"NEXT",0xe,(HMENU)0x2);
  *(HWND *)(param_1 + 0x14) = pHVar3;
  FUN_0003f674((int)auStack_188);
  pHVar3 = FUN_0003f6bc(auStack_188,1,L"SAVE",0xe,(HMENU)0x3);
  *(HWND *)(param_1 + 0x18) = pHVar3;
  EnableWindow(*(HWND *)(param_1 + 0x10),1);
  EnableWindow(*(HWND *)(param_1 + 0x14),0);
  EnableWindow(*(HWND *)(param_1 + 0x18),0);
  FUN_00036f60();
  FUN_0004a3f4(local_30);
  return;
}



/* 00045768 Unwind@00045768 */

/* Boundary evidence: original MIPS .pdata 00045768..00045797. Semantic name remains unreviewed. */

void Unwind_00045768(void)

{
  FUN_00036f60();
  return;
}



/* 00045798 FUN_00045798 */

/* Boundary evidence: original MIPS .pdata 00045798..000458cf. Semantic name remains unreviewed. */

void FUN_00045798(int param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_00015158(DAT_000648e4,3,1,0x80,0,0,100);
    EnableWindow(*(HWND *)(param_1 + 0x10),0);
    EnableWindow(*(HWND *)(param_1 + 0x14),0);
    EnableWindow(*(HWND *)(param_1 + 0x18),0);
    Sleep(0x1e);
    FUN_00015158(DAT_000648e4,3,1,0x80,0,0,100);
  }
  else if (param_2 == 2) {
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    EnableWindow(*(HWND *)(param_1 + 0x14),0);
  }
  else if (param_2 == 3) {
    FUN_00015158(DAT_000648e4,3,1,0x83,0,0,100);
  }
  return;
}



/* 000458d0 FUN_000458d0 */

/* Boundary evidence: original MIPS .pdata 000458d0..00045ebf. Semantic name remains unreviewed. */

void FUN_000458d0(int param_1,int param_2,undefined4 param_3)

{
  HWND hWnd;
  LPCWSTR lpString;
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_718 [64];
  WCHAR aWStack_698 [64];
  WCHAR aWStack_618 [64];
  WCHAR aWStack_598 [64];
  WCHAR aWStack_518 [64];
  WCHAR aWStack_498 [64];
  WCHAR aWStack_418 [64];
  WCHAR aWStack_398 [64];
  WCHAR aWStack_318 [64];
  WCHAR aWStack_298 [64];
  WCHAR aWStack_218 [64];
  WCHAR aWStack_198 [64];
  WCHAR aWStack_118 [64];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  if (param_2 != 4) goto switchD_00045928_caseD_3;
  switch(param_3) {
  case 1:
    wsprintfW(aWStack_218,L"SUB TUNER : 97.7MHz, 200uV, MOD(OFF)");
    SetWindowTextW(*(HWND *)(param_1 + 0x14),aWStack_218);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 2:
    wsprintfW(aWStack_318,L"0x%02X",(uint)*(byte *)(DAT_000673c8 + 0xc));
    SetWindowTextW(*(HWND *)(param_1 + 0x1c),aWStack_318);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 4:
    uVar1 = CONCAT11(*(byte *)(DAT_000673c8 + 0xc),*(undefined1 *)(DAT_000673c8 + 0xd));
    if ((*(byte *)(DAT_000673c8 + 0xc) & 8) != 0) {
      uVar1 = uVar1 | 0xf000;
    }
    uVar2 = __litodp((int)(short)uVar1);
    uVar2 = __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3fa90000);
    wsprintfW(aWStack_718,L"%5.2f",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
    SetWindowTextW(*(HWND *)(param_1 + 0x28),aWStack_718);
    wsprintfW(aWStack_718,L"0x%06X",
              ((uint)*(byte *)(DAT_000673c8 + 0xe) * 0x100 + (uint)*(byte *)(DAT_000673c8 + 0xf)) *
              0x100 + (uint)*(byte *)(DAT_000673c8 + 0x10));
    SetWindowTextW(*(HWND *)(param_1 + 0x2c),aWStack_718);
    wsprintfW(aWStack_718,L"0x%06X",
              ((uint)*(byte *)(DAT_000673c8 + 0x11) * 0x100 + (uint)*(byte *)(DAT_000673c8 + 0x12))
              * 0x100 + (uint)*(byte *)(DAT_000673c8 + 0x13));
    SetWindowTextW(*(HWND *)(param_1 + 0x30),aWStack_718);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 6:
    wsprintfW(aWStack_518,L"0x%02X",
              (uint)*(byte *)(DAT_000673c8 + 0xc) * 0x100 + (uint)*(byte *)(DAT_000673c8 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x34),aWStack_518);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 7:
    wsprintfW(aWStack_118,L"MAIN TUNER : 97.7MHz, 200uV, MOD(OFF)");
    lpString = aWStack_118;
    goto LAB_00045a9c;
  case 8:
    wsprintfW(aWStack_418,L"0x%02X",(uint)*(byte *)(DAT_000673c8 + 0xc));
    SetWindowTextW(*(HWND *)(param_1 + 0x20),aWStack_418);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 10:
    wsprintfW(aWStack_698,L"0x%02X",
              (uint)*(byte *)(DAT_000673c8 + 0xc) * 0x100 + (uint)*(byte *)(DAT_000673c8 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x38),aWStack_698);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 0xb:
    wsprintfW(aWStack_618,L"MAIN TUNER : 97.7MHz, 1mV, MOD(ON,40kHz), AF(1kHz)");
    lpString = aWStack_618;
    goto LAB_00045a9c;
  case 0xc:
    wsprintfW(aWStack_598,L"0x%02X",
              (uint)*(byte *)(DAT_000673c8 + 0xc) * 0x100 + (uint)*(byte *)(DAT_000673c8 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x44),aWStack_598);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 0x20:
    wsprintfW(aWStack_498,L"MAIN TUNER : 1080kHz, 1mV, MOD(OFF)");
    lpString = aWStack_498;
    goto LAB_00045a9c;
  case 0x21:
    wsprintfW(aWStack_398,L"0x%02X",(uint)*(byte *)(DAT_000673c8 + 0xc));
    SetWindowTextW(*(HWND *)(param_1 + 0x24),aWStack_398);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 0x22:
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 0x23:
    wsprintfW(aWStack_298,L"0x%02X",
              (uint)*(byte *)(DAT_000673c8 + 0xc) * 0x100 + (uint)*(byte *)(DAT_000673c8 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x3c),aWStack_298);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    break;
  case 0x24:
    wsprintfW(aWStack_198,L"MAIN TUNER : 216kHz, 1mV, MOD(OFF)");
    lpString = aWStack_198;
LAB_00045a9c:
    SetWindowTextW(*(HWND *)(param_1 + 0x14),lpString);
    hWnd = *(HWND *)(param_1 + 0x14);
LAB_00045e98:
    EnableWindow(hWnd,1);
    break;
  case 0x25:
    wsprintfW(aWStack_98,L"0x%02X",
              (uint)*(byte *)(DAT_000673c8 + 0xc) * 0x100 + (uint)*(byte *)(DAT_000673c8 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x40),aWStack_98);
    FUN_00015158(DAT_000648e4,3,1,0x81,0,0,100);
    EnableWindow(*(HWND *)(param_1 + 0x10),1);
    hWnd = *(HWND *)(param_1 + 0x18);
    goto LAB_00045e98;
  }
switchD_00045928_caseD_3:
  FUN_0004a3f4(local_18);
  return;
}



/* 00045ed0 FUN_00045ed0 */

/* Boundary evidence: original MIPS .pdata 00045ed0..00045f27. Semantic name remains unreviewed. */

undefined4 * FUN_00045ed0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00060280;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00045f28 FUN_00045f28 */

/* Boundary evidence: original MIPS .pdata 00045f28..00045fbf. Semantic name remains unreviewed. */

undefined4 * FUN_00045f28(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  FUN_00044b4c(param_1);
  puVar1 = param_1 + 6;
  *param_1 = &PTR_FUN_00060540;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x12);
  puVar1 = param_1 + 0x13;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x1f);
  param_1[0x12] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  return param_1;
}



/* 00045fc0 FUN_00045fc0 */

/* Boundary evidence: original MIPS .pdata 00045fc0..0004600b. Semantic name remains unreviewed. */

void FUN_00045fc0(int param_1)

{
  if (*(int *)(param_1 + 0x90) == 1) {
    FUN_00044f54(param_1,0xb);
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  *(undefined4 *)(DAT_000673c8 + 0x5c) = 0;
  return;
}



/* 0004600c FUN_0004600c */

/* Boundary evidence: original MIPS .pdata 0004600c..000460b3. Semantic name remains unreviewed. */

void FUN_0004600c(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  WCHAR aWStack_40 [16];
  uint local_20;
  
  local_20 = DAT_00064820;
  uVar1 = 0;
  puVar2 = (undefined4 *)(param_1 + 0x18);
  do {
    wsprintfW(aWStack_40,L"%S",
              ((uint)*(byte *)(DAT_00064ae4 + 4) * 0x54 + uVar1) * 0x10 + DAT_00064ae4 + 0xc);
    SetWindowTextW((HWND)*puVar2,aWStack_40);
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 0xc);
  FUN_0004a3f4(local_20);
  return;
}



/* 000460b4 FUN_000460b4 */

/* Boundary evidence: original MIPS .pdata 000460b4..0004610b. Semantic name remains unreviewed. */

undefined4 * FUN_000460b4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00060540;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0004610c FUN_0004610c */

/* Boundary evidence: original MIPS .pdata 0004610c..00046827. Semantic name remains unreviewed. */

void FUN_0004610c(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  HWND pHVar3;
  byte local_258;
  byte local_257;
  undefined4 auStack_250 [8];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_00064820;
  *(undefined4 *)(DAT_000673c8 + 0x5c) = *(undefined4 *)(param_1 + 0xc);
  uVar1 = FUN_00044f30();
  uVar2 = FUN_00044f28();
  FUN_0003f5e0(auStack_250,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar2,uVar1);
  FUN_0003f6bc(auStack_250,1,L"FM",2,(HMENU)0x1);
  FUN_0003f6bc(auStack_250,1,L"AM",2,(HMENU)0x2);
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f6bc(auStack_250,1,L"A",2,(HMENU)0x1a);
  FUN_0003f6bc(auStack_250,1,L"S",2,(HMENU)0x1b);
  FUN_0003f6bc(auStack_250,1,L"R",2,(HMENU)0x1c);
  FUN_0003f614((int)auStack_250,0);
  FUN_0003f6bc(auStack_250,0,L"SEEK/TUNE",0,(HMENU)0x0);
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f6bc(auStack_250,1,L"<<",2,(HMENU)0x3);
  FUN_0003f6bc(auStack_250,1,L"<",2,(HMENU)0x5);
  pHVar3 = FUN_0003f6bc(auStack_250,2,L"",6,(HMENU)0x0);
  *(HWND *)(param_1 + 0x14) = pHVar3;
  FUN_0003f6bc(auStack_250,1,L">",2,(HMENU)0x6);
  FUN_0003f6bc(auStack_250,1,L">>",2,(HMENU)0x4);
  FUN_0003f614((int)auStack_250,0);
  FUN_0003f6bc(auStack_250,0,L"PRESET",0,(HMENU)0x0);
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f6bc(auStack_250,1,L"P1",2,(HMENU)0x7);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"",4,(HMENU)0x13);
  *(HWND *)(param_1 + 0x18) = pHVar3;
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f6bc(auStack_250,1,L"P2",2,(HMENU)0x8);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"",4,(HMENU)0x14);
  *(HWND *)(param_1 + 0x1c) = pHVar3;
  FUN_0003f674((int)auStack_250);
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f6bc(auStack_250,1,L"P3",2,(HMENU)0x9);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"",4,(HMENU)0x15);
  *(HWND *)(param_1 + 0x20) = pHVar3;
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f6bc(auStack_250,1,L"P4",2,(HMENU)0xa);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"",4,(HMENU)0x16);
  *(HWND *)(param_1 + 0x24) = pHVar3;
  FUN_0003f674((int)auStack_250);
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f6bc(auStack_250,1,L"P5",2,(HMENU)0xb);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"",4,(HMENU)0x17);
  *(HWND *)(param_1 + 0x28) = pHVar3;
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f6bc(auStack_250,1,L"P6",2,(HMENU)0xc);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"",4,(HMENU)0x18);
  *(HWND *)(param_1 + 0x2c) = pHVar3;
  FUN_0003f674((int)auStack_250);
  FUN_0003f614((int)auStack_250,0);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"0000",4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x7c) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"00",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x80) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"X",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x84) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"X",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x88) = pHVar3;
  FUN_0003f69c((int)auStack_250);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"0dBuV",4,(HMENU)0x0);
  *(HWND *)(param_1 + 0x8c) = pHVar3;
  FUN_0004600c(param_1);
  FUN_0003f6bc(auStack_250,0,L"TMC Test BTN",0,(HMENU)0x1d);
  FUN_0003f674((int)auStack_250);
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"TMC_ON",4,(HMENU)0x1e);
  *(HWND *)(param_1 + 0x8c) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"TMC_OFF",4,(HMENU)0x1f);
  *(HWND *)(param_1 + 0x8c) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"TMC_SET_FREQ_99.9",4,(HMENU)0x20);
  *(HWND *)(param_1 + 0x8c) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_250,1,L"TMC_SCAN_UP",4,(HMENU)0x21);
  *(HWND *)(param_1 + 0x8c) = pHVar3;
  FUN_0003f614((int)auStack_250,1);
  FUN_0003f614((int)auStack_250,0);
  FUN_0003f614((int)auStack_250,0);
  FUN_000153dc(DAT_000648e4,2,0x31282,&local_258,3,500);
  wsprintfW(aWStack_230,L"0x%02X%02X",(uint)local_258,(uint)local_257);
  FUN_0003f6bc(auStack_250,2,aWStack_230,4,(HMENU)0x0);
  FUN_0003f614((int)auStack_250,1);
  FUN_000153dc(DAT_000648e4,2,0x31283,&local_258,3,500);
  wsprintfW(aWStack_230,L"0x%02X%02X",(uint)local_258,(uint)local_257);
  FUN_0003f6bc(auStack_250,2,aWStack_230,4,(HMENU)0x0);
  FUN_0003f614((int)auStack_250,1);
  FUN_000153dc(DAT_000648e4,2,0x31284,&local_258,3,500);
  wsprintfW(aWStack_230,L"0x%02X%02X",(uint)local_258,(uint)local_257);
  FUN_0003f6bc(auStack_250,2,aWStack_230,4,(HMENU)0x0);
  FUN_00044f38(param_1,0xb,300,(TIMERPROC)0x0);
  FUN_00036f60();
  FUN_0004a3f4(local_28);
  return;
}



/* 00046828 Unwind@00046828 */

/* Boundary evidence: original MIPS .pdata 00046828..00046857. Semantic name remains unreviewed. */

void Unwind_00046828(void)

{
  FUN_00036f60();
  return;
}



/* 00046858 FUN_00046858 */

/* Boundary evidence: original MIPS .pdata 00046858..00046b83. Semantic name remains unreviewed. */

void FUN_00046858(int param_1,int param_2)

{
  errno_t eVar1;
  uint uVar2;
  wchar_t *pwVar3;
  char *_Src;
  undefined1 *puVar4;
  undefined1 local_470;
  undefined1 local_46f;
  undefined1 auStack_46e [2];
  undefined1 local_46c;
  FILE *local_468 [2];
  char acStack_460 [64];
  undefined1 auStack_420 [1024];
  uint local_20;
  
  local_20 = DAT_00064820;
  switch(param_2) {
  case 1:
  case 2:
    goto switchD_000468ac_caseD_1;
  default:
    goto switchD_000468ac_caseD_3;
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
    FUN_00028cf8(DAT_000673c8,param_2 - 7);
    goto switchD_000468ac_caseD_1;
  case 0x1a:
  case 0x1b:
  case 0x1c:
    if (param_2 == 0x1c) {
      _Src = ".\\Storage Card\\system\\radparam.bin";
    }
    else {
      _Src = ".\\Storage Card\\ULC_RAD_PARAM.bin";
    }
    strcpy_s(acStack_460,0x40,_Src);
    eVar1 = fopen_s(local_468,acStack_460,"rb");
    if (eVar1 == 0) {
      fread(auStack_420,0x400,1,local_468[0]);
      fclose(local_468[0]);
      uVar2 = 0;
      puVar4 = auStack_420;
      do {
        FUN_00014db0(DAT_000648e4,3,uVar2 + 0xe0,(int)puVar4,0x80,300);
        uVar2 = uVar2 + 1;
        puVar4 = puVar4 + 0x80;
      } while (uVar2 < 8);
      if (param_2 != 0x1a) {
        FUN_00015158(DAT_000648e4,3,1,0xe1,0,0,500);
      }
      FUN_00015158(DAT_000648e4,3,1,0xe0,0,0,500);
      FUN_00015158(DAT_000648e4,3,1,0xe2,0,0,0x1e);
    }
    goto switchD_000468ac_caseD_3;
  case 0x1e:
    FUN_00015158(DAT_000648e4,0xb,1,0x70,0,0,0x32);
    pwVar3 = L"[[[ TMC_TEST_MODE ]]]]   CMD_TMC_ON\r\n";
    break;
  case 0x1f:
    FUN_00015158(DAT_000648e4,0xb,1,0x71,0,0,0x32);
    pwVar3 = L"[[[ TMC_TEST_MODE ]]]]   CMD_TMC_OFF\r\n";
    break;
  case 0x20:
    local_470 = 0xe7;
    local_46f = 3;
    FUN_00015158(DAT_000648e4,0xb,1,0x72,(int)&local_470,2,0x32);
    pwVar3 = L"[[[ TMC_TEST_MODE ]]]]   CMD_TMC_SET_FREQ ---\t \r\n";
    break;
  case 0x21:
    uVar2 = FUN_000153dc(DAT_000648e4,0xb,0xd5,auStack_46e,3,100);
    if (uVar2 != 3) goto switchD_000468ac_caseD_3;
    local_46c = 1;
    FUN_00015158(DAT_000648e4,0xb,1,0x73,(int)auStack_46e,3,0x32);
    pwVar3 = L"[[[ TMC_TEST_MODE ]]]]   CMD_TMC_SCAN\r\n";
  }
  NKDbgPrintfW(pwVar3);
switchD_000468ac_caseD_3:
  FUN_0004a3f4(local_20);
  return;
switchD_000468ac_caseD_1:
  FUN_0004600c(param_1);
  goto switchD_000468ac_caseD_3;
}



/* 00046b84 FUN_00046b84 */

/* Boundary evidence: original MIPS .pdata 00046b84..00046d03. Semantic name remains unreviewed. */

void FUN_00046b84(int param_1,int param_2,int param_3)

{
  HWND hWnd;
  LPCWSTR pWVar1;
  WCHAR aWStack_298 [64];
  WCHAR aWStack_218 [64];
  WCHAR aWStack_198 [64];
  WCHAR aWStack_118 [64];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00064820;
  if (param_2 == 0) {
    SetWindowTextW(*(HWND *)(param_1 + 0x7c),L"0000");
    SetWindowTextW(*(HWND *)(param_1 + 0x80),L"00");
    pWVar1 = L"X";
    SetWindowTextW(*(HWND *)(param_1 + 0x84),L"X");
LAB_00046cdc:
    hWnd = *(HWND *)(param_1 + 0x88);
  }
  else {
    if (param_2 == 1) goto LAB_00046ce8;
    if (param_2 == 3) {
      wsprintfW(aWStack_98,L"AST(%d)");
      hWnd = *(HWND *)(param_1 + 0x48);
      pWVar1 = aWStack_98;
    }
    else if (param_2 == 5) {
      wsprintfW(aWStack_198,L"%04X");
      hWnd = *(HWND *)(param_1 + 0x7c);
      pWVar1 = aWStack_198;
    }
    else if (param_2 == 6) {
      wsprintfW(aWStack_298,L"%d");
      hWnd = *(HWND *)(param_1 + 0x80);
      pWVar1 = aWStack_298;
    }
    else {
      if (param_2 != 7) {
        if (param_2 != 8) goto LAB_00046ce8;
        if (param_3 == 1) {
          pWVar1 = L"O";
        }
        else {
          pWVar1 = L"X";
        }
        wsprintfW(aWStack_218,pWVar1);
        pWVar1 = aWStack_218;
        goto LAB_00046cdc;
      }
      if (param_3 == 1) {
        pWVar1 = L"O";
      }
      else {
        pWVar1 = L"X";
      }
      wsprintfW(aWStack_118,pWVar1);
      hWnd = *(HWND *)(param_1 + 0x84);
      pWVar1 = aWStack_118;
    }
  }
  SetWindowTextW(hWnd,pWVar1);
LAB_00046ce8:
  FUN_0004a3f4(local_18);
  return;
}



/* 00046d04 FUN_00046d04 */

/* Boundary evidence: original MIPS .pdata 00046d04..00046d3b. Semantic name remains unreviewed. */

undefined4 * FUN_00046d04(undefined4 *param_1)

{
  FUN_00044b4c(param_1);
  *param_1 = &PTR_FUN_00060814;
  return param_1;
}



/* 00046d3c FUN_00046d3c */

/* Boundary evidence: original MIPS .pdata 00046d3c..00046e47. Semantic name remains unreviewed. */

void FUN_00046d3c(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0006866c == 1) {
    iVar1 = FUN_00044f30();
    iVar2 = FUN_00044f28();
    CreateWindowExW(0,L"button",
                    L"Radio Tuning...(Current DSP --- PC)\r\nIf you press this button DSP will be connected to MICOM.\r\nIf you want to go back to main menu, press power button."
                    ,0x50802000,100,100,iVar2 + -200,iVar1 + -200,*(HWND *)(param_1 + 0xc),
                    (HMENU)0x0,*(HINSTANCE *)(param_1 + 4),(LPVOID)0x0);
  }
  else {
    iVar1 = FUN_00044f30();
    iVar2 = FUN_00044f28();
    CreateWindowExW(0,L"button",
                    L"Radio Tuning...(Current DSP --- MICOM)\r\nIf you press this button DSP will be connected to PC.\r\nIf you want to go back to main menu, press power button."
                    ,0x50802000,100,100,iVar2 + -200,iVar1 + -200,*(HWND *)(param_1 + 0xc),
                    (HMENU)0x0,*(HINSTANCE *)(param_1 + 4),(LPVOID)0x0);
  }
  return;
}



/* 00046e48 FUN_00046e48 */

/* Boundary evidence: original MIPS .pdata 00046e48..00046edf. Semantic name remains unreviewed. */

void FUN_00046e48(int param_1)

{
  bool bVar1;
  undefined1 local_18 [8];
  
  bVar1 = DAT_0006866c != 1;
  if (bVar1) {
    local_18[0] = 1;
    FUN_00014db0(DAT_000648e4,0,0x30,(int)local_18,1,0x32);
  }
  else {
    local_18[0] = 0;
    FUN_00014db0(DAT_000648e4,0,0x30,(int)local_18,1,0x32);
  }
  DAT_0006866c = (uint)bVar1;
  DestroyWindow(*(HWND *)(param_1 + 0xc));
  return;
}



/* 00046ee0 FUN_00046ee0 */

/* Boundary evidence: original MIPS .pdata 00046ee0..00046f37. Semantic name remains unreviewed. */

undefined4 * FUN_00046ee0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00060814;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00046f38 FUN_00046f38 */

/* Boundary evidence: original MIPS .pdata 00046f38..00046f87. Semantic name remains unreviewed. */

undefined4 * FUN_00046f38(undefined4 *param_1)

{
  FUN_00044b4c(param_1);
  *param_1 = &PTR_FUN_00060aa0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  return param_1;
}



/* 00046f88 FUN_00046f88 */

/* Boundary evidence: original MIPS .pdata 00046f88..00047403. Semantic name remains unreviewed. */

void FUN_00046f88(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  HWND pHVar3;
  HWND pHVar4;
  DWORD DVar5;
  DWORD DVar6;
  undefined4 auStack_d0 [8];
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00064820;
  uVar1 = FUN_00044f30();
  uVar2 = FUN_00044f28();
  FUN_0003f5e0(auStack_d0,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar2,uVar1);
  wsprintfW(aWStack_b0,L"MICOM MANAGER VERSION : %d.%d.%d.%s",7,0,5,L"0220");
  FUN_0003f6bc(auStack_d0,0,aWStack_b0,0,(HMENU)0x0);
  pHVar3 = FUN_0003f6bc(auStack_d0,1,L"SET init. ROM for AUD & RAD",0xe,(HMENU)0xb);
  *(HWND *)(param_1 + 0x14) = pHVar3;
  FUN_0003f614((int)auStack_d0,0);
  pHVar3 = FUN_0003f6bc(auStack_d0,1,L"TEMP : xx",0xe,(HMENU)0xe);
  *(HWND *)(param_1 + 0x10) = pHVar3;
  FUN_0003f69c((int)auStack_d0);
  FUN_0003f6bc(auStack_d0,1,L"RADIO TEST",8,(HMENU)0x1);
  pHVar3 = FUN_0003f6bc(auStack_d0,1,L"DAB TEST",6,(HMENU)0xf);
  *(HWND *)(param_1 + 0x18) = pHVar3;
  FUN_0003f614((int)auStack_d0,0);
  FUN_0003f6bc(auStack_d0,1,L"AF TEST",0xe,(HMENU)0x2);
  FUN_0003f614((int)auStack_d0,0);
  pHVar3 = FUN_0003f6bc(auStack_d0,1,L"AUDIO TEST",10,(HMENU)0x3);
  *(HWND *)(param_1 + 0x1c) = pHVar3;
  pHVar3 = FUN_0003f6bc(auStack_d0,1,L"XXXX",4,(HMENU)0x4);
  FUN_0003f614((int)auStack_d0,0);
  pHVar4 = FUN_0003f6bc(auStack_d0,1,L"MICOM TEST",10,(HMENU)0x5);
  *(HWND *)(param_1 + 0x20) = pHVar4;
  FUN_0003f6bc(auStack_d0,1,L"XXXX",4,(HMENU)0x6);
  FUN_0003f614((int)auStack_d0,0);
  FUN_0003f6bc(auStack_d0,1,L"RADIO TUNING",0xe,(HMENU)0x7);
  FUN_0003f614((int)auStack_d0,0);
  pHVar4 = FUN_0003f6bc(auStack_d0,1,L"TUNER ALIGNMENT",0xe,(HMENU)0x8);
  *(HWND *)(param_1 + 0x24) = pHVar4;
  FUN_0003f614((int)auStack_d0,0);
  FUN_0003f6bc(auStack_d0,1,L"UPDATE FIRMWARE",10,(HMENU)0x9);
  FUN_0003f6bc(auStack_d0,1,L"XXXXX",4,(HMENU)0xa);
  FUN_0003f614((int)auStack_d0,0);
  if (*(int *)(DAT_00064a24 + 0x68) == 1) {
    FUN_0003f6bc(auStack_d0,1,L"BT TEST",10,(HMENU)0x10);
    FUN_0003f6bc(auStack_d0,1,L"DAB FW",4,(HMENU)0x11);
  }
  else {
    FUN_0003f6bc(auStack_d0,1,L"BT TEST",0xe,(HMENU)0x10);
  }
  FUN_0003f614((int)auStack_d0,0);
  DVar5 = GetFileAttributesW(L"\\MD\\mcmtest_activate.ini");
  if (DVar5 == 0xffffffff) {
    EnableWindow(*(HWND *)(param_1 + 0x14),0);
    EnableWindow(*(HWND *)(param_1 + 0x1c),0);
    EnableWindow(pHVar3,0);
    DVar6 = GetFileAttributesW(L"\\MD\\mcmtest_activate_4nng.ini");
    EnableWindow(*(HWND *)(param_1 + 0x20),(uint)(DVar6 != 0xffffffff));
  }
  else {
    EnableWindow(*(HWND *)(param_1 + 0x14),1);
    EnableWindow(*(HWND *)(param_1 + 0x1c),1);
    EnableWindow(pHVar3,1);
    EnableWindow(*(HWND *)(param_1 + 0x20),1);
  }
  EnableWindow(*(HWND *)(param_1 + 0x24),(uint)(DVar5 != 0xffffffff));
  EnableWindow(*(HWND *)(param_1 + 0x18),(uint)(*(int *)(DAT_00064a24 + 0x68) == 1));
  SetTimer(*(HWND *)(param_1 + 0xc),1000,0x5dc,(TIMERPROC)0x0);
  FUN_00036f60();
  FUN_0004a3f4(local_30);
  return;
}



/* 00047404 Unwind@00047404 */

/* Boundary evidence: original MIPS .pdata 00047404..00047433. Semantic name remains unreviewed. */

void Unwind_00047404(void)

{
  FUN_00036f60();
  return;
}



/* 00047434 FUN_00047434 */

/* Boundary evidence: original MIPS .pdata 00047434..0004753b. Semantic name remains unreviewed. */

void FUN_00047434(double param_1)

{
  undefined4 extraout_v0;
  undefined4 extraout_v1;
  undefined8 uVar1;
  
  uVar1 = __ultodp();
  uVar1 = __dpsub((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x3fe00000);
  uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x40408000);
  uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0x9999999a,0x3f199999);
  uVar1 = __dpsub(0xce703afb,0x3ffdd288,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0x4768ca44,0xbef0461e);
  __dpsub(0xd98bf7f0,0x3f215592,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  sqrt(param_1);
  uVar1 = __dpsub(0xdf3b645a,0x3f878d4f,extraout_v0,extraout_v1);
  uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0xab8be054,0xc0ff761f);
  __dptoli((int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  return;
}



/* 0004753c FUN_0004753c */

/* Boundary evidence: original MIPS .pdata 0004753c..000475e3. Semantic name remains unreviewed. */

void FUN_0004753c(double param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ushort local_228 [4];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00064820;
  if (param_3 == 1000) {
    uVar1 = FUN_000153dc(DAT_000648e4,9,6,local_228,2,100);
    if (uVar1 != 0) {
      uVar2 = FUN_00047434(param_1);
      wsprintfW(aWStack_220,L"ULC_TEMP %d,(%d)",(uint)local_228[0],uVar2);
      SetWindowTextW(*(HWND *)(param_2 + 0x10),aWStack_220);
    }
  }
  FUN_0004a3f4(local_18);
  return;
}



/* 000475e4 FUN_000475e4 */

/* Boundary evidence: original MIPS .pdata 000475e4..00049a1f. Semantic name remains unreviewed. */

void FUN_000475e4(int param_1,undefined4 param_2)

{
  HWND hWnd;
  undefined4 *puVar1;
  undefined4 uVar2;
  WPARAM wParam;
  undefined4 uVar3;
  LPARAM lParam;
  undefined1 local_830;
  undefined1 local_82f;
  undefined1 local_82e;
  undefined1 local_82d;
  undefined1 local_82c;
  undefined1 local_82b;
  undefined1 local_82a;
  undefined1 local_829;
  undefined1 local_828;
  undefined1 local_827;
  undefined1 local_826;
  undefined1 local_825;
  undefined1 local_824;
  undefined1 local_823;
  undefined1 local_822;
  undefined1 local_821;
  undefined1 local_820;
  undefined1 local_81f;
  undefined1 local_81e;
  undefined1 local_81d;
  undefined1 local_81c;
  undefined1 local_81b;
  undefined1 local_81a;
  undefined1 local_819;
  undefined1 local_818;
  undefined1 local_817;
  undefined1 local_816;
  undefined1 local_815;
  undefined1 local_814;
  undefined1 local_813;
  undefined1 local_812;
  undefined1 local_811;
  undefined1 local_810;
  undefined1 local_80f;
  undefined1 local_80e;
  undefined1 local_80d;
  undefined1 local_80c;
  undefined1 local_80b;
  undefined1 local_80a;
  undefined1 local_809;
  undefined1 local_808;
  undefined1 local_807;
  undefined1 local_806;
  undefined1 local_805;
  undefined1 local_804;
  undefined1 local_803;
  undefined1 local_802;
  undefined1 local_801;
  undefined1 local_800;
  undefined1 local_7ff;
  undefined1 local_7fe;
  undefined1 local_7fd;
  undefined1 local_7fc;
  undefined1 local_7fb;
  undefined1 local_7fa;
  undefined1 local_7f9;
  undefined1 local_7f8;
  undefined1 local_7f7;
  undefined1 local_7f6;
  undefined1 local_7f5;
  undefined1 local_7f4;
  undefined1 local_7f3;
  undefined1 local_7f2;
  undefined1 local_7f1;
  undefined1 local_7f0;
  undefined1 local_7ef;
  undefined1 local_7ee;
  undefined1 local_7ed;
  undefined1 local_7ec;
  undefined1 local_7eb;
  undefined1 local_7ea;
  undefined1 local_7e9;
  undefined1 local_7e8;
  undefined1 local_7e7;
  undefined1 local_7e6;
  undefined1 local_7e5;
  undefined1 local_7e4;
  undefined1 local_7e3;
  undefined1 local_7e2;
  undefined1 local_7e1;
  undefined1 local_7e0;
  undefined1 local_7df;
  undefined1 local_7de;
  undefined1 local_7dd;
  undefined1 local_7dc;
  undefined1 local_7db;
  undefined1 local_7da;
  undefined1 local_7d9;
  undefined1 local_7d8;
  undefined1 local_7d7;
  undefined1 local_7d6;
  undefined1 local_7d5;
  undefined1 local_7d4;
  undefined1 local_7d3;
  undefined1 local_7d2;
  undefined1 local_7d1;
  undefined1 local_7d0;
  undefined1 local_7cf;
  undefined1 local_7ce;
  undefined1 local_7cd;
  undefined1 local_7cc;
  undefined1 local_7cb;
  undefined1 local_7ca;
  undefined1 local_7c9;
  undefined1 local_7c8;
  undefined1 local_7c7;
  undefined1 local_7c6;
  undefined1 local_7c5;
  undefined1 local_7c4;
  undefined1 local_7c3;
  undefined1 local_7c2;
  undefined1 local_7c1;
  undefined1 local_7c0;
  undefined1 local_7bf;
  undefined1 local_7be;
  undefined1 local_7bd;
  undefined1 local_7bc;
  undefined1 local_7bb;
  undefined1 local_7ba;
  undefined1 local_7b9;
  undefined1 local_7b8;
  undefined1 local_7b7;
  undefined1 local_7b6;
  undefined1 local_7b5;
  undefined1 local_7b4;
  undefined1 local_7b3;
  undefined1 local_7b2;
  undefined1 local_7b1;
  undefined1 local_7b0;
  undefined1 local_7af;
  undefined1 local_7ae;
  undefined1 local_7ad;
  undefined1 local_7ac;
  undefined1 local_7ab;
  undefined1 local_7aa;
  undefined1 local_7a9;
  undefined1 local_7a8;
  undefined1 local_7a7;
  undefined1 local_7a6;
  undefined1 local_7a5;
  undefined1 local_7a4;
  undefined1 local_7a3;
  undefined1 local_7a2;
  undefined1 local_7a1;
  undefined1 local_7a0;
  undefined1 local_79f;
  undefined1 local_79e;
  undefined1 local_79d;
  undefined1 local_79c;
  undefined1 local_79b;
  undefined1 local_79a;
  undefined1 local_799;
  undefined1 local_798;
  undefined1 local_797;
  undefined1 local_796;
  undefined1 local_795;
  undefined1 local_794;
  undefined1 local_793;
  undefined1 local_792;
  undefined1 local_791;
  undefined1 local_790;
  undefined1 local_78f;
  undefined1 local_78e;
  undefined1 local_78d;
  undefined1 local_78c;
  undefined1 local_78b;
  undefined1 local_78a;
  undefined1 local_789;
  undefined1 local_788;
  undefined1 local_787;
  undefined1 local_786;
  undefined1 local_785;
  undefined1 local_784;
  undefined1 local_783;
  undefined1 local_782;
  undefined1 local_781;
  undefined1 local_780;
  undefined1 local_77f;
  undefined1 local_77e;
  undefined1 local_77d;
  undefined1 local_77c;
  undefined1 local_77b;
  undefined1 local_77a;
  undefined1 local_779;
  undefined1 local_778;
  undefined1 local_777;
  undefined1 local_776;
  undefined1 local_775;
  undefined1 local_774;
  undefined1 local_773;
  undefined1 local_772;
  undefined1 local_771;
  undefined1 local_770;
  undefined1 local_76f;
  undefined1 local_76e;
  undefined1 local_76d;
  undefined1 local_76c;
  undefined1 local_76b;
  undefined1 local_76a;
  undefined1 local_769;
  undefined1 local_768;
  undefined1 local_767;
  undefined1 local_766;
  undefined1 local_765;
  undefined1 local_764;
  undefined1 local_763;
  undefined1 local_762;
  undefined1 local_761;
  undefined1 local_760;
  undefined1 local_75f;
  undefined1 local_75e;
  undefined1 local_75d;
  undefined1 local_75c;
  undefined1 local_75b;
  undefined1 local_75a;
  undefined1 local_759;
  undefined1 local_758;
  undefined1 local_757;
  undefined1 local_756;
  undefined1 local_755;
  undefined1 local_754;
  undefined1 local_753;
  undefined1 local_752;
  undefined1 local_751;
  undefined1 local_750;
  undefined1 local_74f;
  undefined1 local_74e;
  undefined1 local_74d;
  undefined1 local_74c;
  undefined1 local_74b;
  undefined1 local_74a;
  undefined1 local_749;
  undefined1 local_748;
  undefined1 local_747;
  undefined1 local_746;
  undefined1 local_745;
  undefined1 local_744;
  undefined1 local_743;
  undefined1 local_742;
  undefined1 local_741;
  undefined1 local_740;
  undefined1 local_73f;
  undefined1 local_73e;
  undefined1 local_73d;
  undefined1 local_73c;
  undefined1 local_73b;
  undefined1 local_73a;
  undefined1 local_739;
  undefined1 local_738;
  undefined1 local_737;
  undefined1 local_736;
  undefined1 local_735;
  undefined1 local_734;
  undefined1 local_733;
  undefined1 local_732;
  undefined1 local_731;
  undefined1 local_730;
  undefined1 local_72f;
  undefined1 local_72e;
  undefined1 local_72d;
  undefined1 local_72c;
  undefined1 local_72b;
  undefined1 local_72a;
  undefined1 local_729;
  undefined1 local_728;
  undefined1 local_727;
  undefined1 local_726;
  undefined1 local_725;
  undefined1 local_724;
  undefined1 local_723;
  undefined1 local_722;
  undefined1 local_721;
  undefined1 local_720;
  undefined1 local_71f;
  undefined1 local_71e;
  undefined1 local_71d;
  undefined1 local_71c;
  undefined1 local_71b;
  undefined1 local_71a;
  undefined1 local_719;
  undefined1 local_718;
  undefined1 local_717;
  undefined1 local_716;
  undefined1 local_715;
  undefined1 local_714;
  undefined1 local_713;
  undefined1 local_712;
  undefined1 local_711;
  undefined1 local_710;
  undefined1 local_70f;
  undefined1 local_70e;
  undefined1 local_70d;
  undefined1 local_70c;
  undefined1 local_70b;
  undefined1 local_70a;
  undefined1 local_709;
  undefined1 local_708;
  undefined1 local_707;
  undefined1 local_706;
  undefined1 local_705;
  undefined1 local_704;
  undefined1 local_703;
  undefined1 local_702;
  undefined1 local_701;
  undefined1 local_700;
  undefined1 local_6ff;
  undefined1 local_6fe;
  undefined1 local_6fd;
  undefined1 local_6fc;
  undefined1 local_6fb;
  undefined1 local_6fa;
  undefined1 local_6f9;
  undefined1 local_6f8;
  undefined1 local_6f7;
  undefined1 local_6f6;
  undefined1 local_6f5;
  undefined1 local_6f4;
  undefined1 local_6f3;
  undefined1 local_6f2;
  undefined1 local_6f1;
  undefined1 local_6f0;
  undefined1 local_6ef;
  undefined1 local_6ee;
  undefined1 local_6ed;
  undefined1 local_6ec;
  undefined1 local_6eb;
  undefined1 local_6ea;
  undefined1 local_6e9;
  undefined1 local_6e8;
  undefined1 local_6e7;
  undefined1 local_6e6;
  undefined1 local_6e5;
  undefined1 local_6e4;
  undefined1 local_6e3;
  undefined1 local_6e2;
  undefined1 local_6e1;
  undefined1 local_6e0;
  undefined1 local_6df;
  undefined1 local_6de;
  undefined1 local_6dd;
  undefined1 local_6dc;
  undefined1 local_6db;
  undefined1 local_6da;
  undefined1 local_6d9;
  undefined1 local_6d8;
  undefined1 local_6d7;
  undefined1 local_6d6;
  undefined1 local_6d5;
  undefined1 local_6d4;
  undefined1 local_6d3;
  undefined1 local_6d2;
  undefined1 local_6d1;
  undefined1 local_6d0;
  undefined1 local_6cf;
  undefined1 local_6ce;
  undefined1 local_6cd;
  undefined1 local_6cc;
  undefined1 local_6cb;
  undefined1 local_6ca;
  undefined1 local_6c9;
  undefined1 local_6c8;
  undefined1 local_6c7;
  undefined1 local_6c6;
  undefined1 local_6c5;
  undefined1 local_6c4;
  undefined1 local_6c3;
  undefined1 local_6c2;
  undefined1 local_6c1;
  undefined1 local_6c0;
  undefined1 local_6bf;
  undefined1 local_6be;
  undefined1 local_6bd;
  undefined1 local_6bc;
  undefined1 local_6bb;
  undefined1 local_6ba;
  undefined1 local_6b9;
  undefined1 local_6b8;
  undefined1 local_6b7;
  undefined1 local_6b6;
  undefined1 local_6b5;
  undefined1 local_6b4;
  undefined1 local_6b3;
  undefined1 local_6b2;
  undefined1 local_6b1;
  undefined1 local_6b0;
  undefined1 local_6af;
  undefined1 local_6ae;
  undefined1 local_6ad;
  undefined1 local_6ac;
  undefined1 local_6ab;
  undefined1 local_6aa;
  undefined1 local_6a9;
  undefined1 local_6a8;
  undefined1 local_6a7;
  undefined1 local_6a6;
  undefined1 local_6a5;
  undefined1 local_6a4;
  undefined1 local_6a3;
  undefined1 local_6a2;
  undefined1 local_6a1;
  undefined1 local_6a0;
  undefined1 local_69f;
  undefined1 local_69e;
  undefined1 local_69d;
  undefined1 local_69c;
  undefined1 local_69b;
  undefined1 local_69a;
  undefined1 local_699;
  undefined1 local_698;
  undefined1 local_697;
  undefined1 local_696;
  undefined1 local_695;
  undefined1 local_694;
  undefined1 local_693;
  undefined1 local_692;
  undefined1 local_691;
  undefined1 local_690;
  undefined1 local_68f;
  undefined1 local_68e;
  undefined1 local_68d;
  undefined1 local_68c;
  undefined1 local_68b;
  undefined1 local_68a;
  undefined1 local_689;
  undefined1 local_688;
  undefined1 local_687;
  undefined1 local_686;
  undefined1 local_685;
  undefined1 local_684;
  undefined1 local_683;
  undefined1 local_682;
  undefined1 local_681;
  undefined1 local_680;
  undefined1 local_67f;
  undefined1 local_67e;
  undefined1 local_67d;
  undefined1 local_67c;
  undefined1 local_67b;
  undefined1 local_67a;
  undefined1 local_679;
  undefined1 local_678;
  undefined1 local_677;
  undefined1 local_676;
  undefined1 local_675;
  undefined1 local_674;
  undefined1 local_673;
  undefined1 local_672;
  undefined1 local_671;
  undefined1 local_670;
  undefined1 local_66f;
  undefined1 local_66e;
  undefined1 local_66d;
  undefined1 local_66c;
  undefined1 local_66b;
  undefined1 local_66a;
  undefined1 local_669;
  undefined1 local_668;
  undefined1 local_667;
  undefined1 local_666;
  undefined1 local_665;
  undefined1 local_664;
  undefined1 local_663;
  undefined1 local_662;
  undefined1 local_661;
  undefined1 local_660;
  undefined1 local_65f;
  undefined1 local_65e;
  undefined1 local_65d;
  undefined1 local_65c;
  undefined1 local_65b;
  undefined1 local_65a;
  undefined1 local_659;
  undefined1 local_658;
  undefined1 local_657;
  undefined1 local_656;
  undefined1 local_655;
  undefined1 local_654;
  undefined1 local_653;
  undefined1 local_652;
  undefined1 local_651;
  undefined1 local_650;
  undefined1 local_64f;
  undefined1 local_64e;
  undefined1 local_64d;
  undefined1 local_64c;
  undefined1 local_64b;
  undefined1 local_64a;
  undefined1 local_649;
  undefined1 local_648;
  undefined1 local_647;
  undefined1 local_646;
  undefined1 local_645;
  undefined1 local_644;
  undefined1 local_643;
  undefined1 local_642;
  undefined1 local_641;
  undefined1 local_640;
  undefined1 local_63f;
  undefined1 local_63e;
  undefined1 local_63d;
  undefined1 local_63c;
  undefined1 local_63b;
  undefined1 local_63a;
  undefined1 local_639;
  undefined1 local_638;
  undefined1 local_637;
  undefined1 local_636;
  undefined1 local_635;
  undefined1 local_634;
  undefined1 local_633;
  undefined1 local_632;
  undefined1 local_631;
  undefined1 local_630;
  undefined1 local_62f;
  undefined1 local_62e;
  undefined1 local_62d;
  undefined1 local_62c;
  undefined1 local_62b;
  undefined1 local_62a;
  undefined1 local_629;
  undefined1 local_628;
  undefined1 local_627;
  undefined1 local_626;
  undefined1 local_625;
  undefined1 local_624;
  undefined1 local_623;
  undefined1 local_622;
  undefined1 local_621;
  undefined1 local_620;
  undefined1 local_61f;
  undefined1 local_61e;
  undefined1 local_61d;
  undefined1 local_61c;
  undefined1 local_61b;
  undefined1 local_61a;
  undefined1 local_619;
  undefined1 local_618;
  undefined1 local_617;
  undefined1 local_616;
  undefined1 local_615;
  undefined1 local_614;
  undefined1 local_613;
  undefined1 local_612;
  undefined1 local_611;
  undefined1 local_610;
  undefined1 local_60f;
  undefined1 local_60e;
  undefined1 local_60d;
  undefined1 local_60c;
  undefined1 local_60b;
  undefined1 local_60a;
  undefined1 local_609;
  undefined1 local_608;
  undefined1 local_607;
  undefined1 local_606;
  undefined1 local_605;
  undefined1 local_604;
  undefined1 local_603;
  undefined1 local_602;
  undefined1 local_601;
  undefined1 local_600;
  undefined1 local_5ff;
  undefined1 local_5fe;
  undefined1 local_5fd;
  undefined1 local_5fc;
  undefined1 local_5fb;
  undefined1 local_5fa;
  undefined1 local_5f9;
  undefined1 local_5f8;
  undefined1 local_5f7;
  undefined1 local_5f6;
  undefined1 local_5f5;
  undefined1 local_5f4;
  undefined1 local_5f3;
  undefined1 local_5f2;
  undefined1 local_5f1;
  undefined1 local_5f0;
  undefined1 local_5ef;
  undefined1 local_5ee;
  undefined1 local_5ed;
  undefined1 local_5ec;
  undefined1 local_5eb;
  undefined1 local_5ea;
  undefined1 local_5e9;
  undefined1 local_5e8;
  undefined1 local_5e7;
  undefined1 local_5e6;
  undefined1 local_5e5;
  undefined1 local_5e4;
  undefined1 local_5e3;
  undefined1 local_5e2;
  undefined1 local_5e1;
  undefined1 local_5e0;
  undefined1 local_5df;
  undefined1 local_5de;
  undefined1 local_5dd;
  undefined1 local_5dc;
  undefined1 local_5db;
  undefined1 local_5da;
  undefined1 local_5d9;
  undefined1 local_5d8;
  undefined1 local_5d7;
  undefined1 local_5d6;
  undefined1 local_5d5;
  undefined1 local_5d4;
  undefined1 local_5d3;
  undefined1 local_5d2;
  undefined1 local_5d1;
  undefined1 local_5d0;
  undefined1 local_5cf;
  undefined1 local_5ce;
  undefined1 local_5cd;
  undefined1 local_5cc;
  undefined1 local_5cb;
  undefined1 local_5ca;
  undefined1 local_5c9;
  undefined1 local_5c8;
  undefined1 local_5c7;
  undefined1 local_5c6;
  undefined1 local_5c5;
  undefined1 local_5c4;
  undefined1 local_5c3;
  undefined1 local_5c2;
  undefined1 local_5c1;
  undefined1 local_5c0;
  undefined1 local_5bf;
  undefined1 local_5be;
  undefined1 local_5bd;
  undefined1 local_5bc;
  undefined1 local_5bb;
  undefined1 local_5ba;
  undefined1 local_5b9;
  undefined1 local_5b8;
  undefined1 local_5b7;
  undefined1 local_5b6;
  undefined1 local_5b5;
  undefined1 local_5b4;
  undefined1 local_5b3;
  undefined1 local_5b2;
  undefined1 local_5b1;
  undefined1 local_5b0;
  undefined1 local_5af;
  undefined1 local_5ae;
  undefined1 local_5ad;
  undefined1 local_5ac;
  undefined1 local_5ab;
  undefined1 local_5aa;
  undefined1 local_5a9;
  undefined1 local_5a8;
  undefined1 local_5a7;
  undefined1 local_5a6;
  undefined1 local_5a5;
  undefined1 local_5a4;
  undefined1 local_5a3;
  undefined1 local_5a2;
  undefined1 local_5a1;
  undefined1 local_5a0;
  undefined1 local_59f;
  undefined1 local_59e;
  undefined1 local_59d;
  undefined1 local_59c;
  undefined1 local_59b;
  undefined1 local_59a;
  undefined1 local_599;
  undefined1 local_598;
  undefined1 local_597;
  undefined1 local_596;
  undefined1 local_595;
  undefined1 local_594;
  undefined1 local_593;
  undefined1 local_592;
  undefined1 local_591;
  undefined1 local_590;
  undefined1 local_58f;
  undefined1 local_58e;
  undefined1 local_58d;
  undefined1 local_58c;
  undefined1 local_58b;
  undefined1 local_58a;
  undefined1 local_589;
  undefined1 local_588;
  undefined1 local_587;
  undefined1 local_586;
  undefined1 local_585;
  undefined1 local_584;
  undefined1 local_583;
  undefined1 local_582;
  undefined1 local_581;
  undefined1 local_580;
  undefined1 local_57f;
  undefined1 local_57e;
  undefined1 local_57d;
  undefined1 local_57c;
  undefined1 local_57b;
  undefined1 local_57a;
  undefined1 local_579;
  undefined1 local_578;
  undefined1 local_577;
  undefined1 local_576;
  undefined1 local_575;
  undefined1 local_574;
  undefined1 local_573;
  undefined1 local_572;
  undefined1 local_571;
  undefined1 local_570;
  undefined1 local_56f;
  undefined1 local_56e;
  undefined1 local_56d;
  undefined1 local_56c;
  undefined1 local_56b;
  undefined1 local_56a;
  undefined1 local_569;
  undefined1 local_568;
  undefined1 local_567;
  undefined1 local_566;
  undefined1 local_565;
  undefined1 local_564;
  undefined1 local_563;
  undefined1 local_562;
  undefined1 local_561;
  undefined1 local_560;
  undefined1 local_55f;
  undefined1 local_55e;
  undefined1 local_55d;
  undefined1 local_55c;
  undefined1 local_55b;
  undefined1 local_55a;
  undefined1 local_559;
  undefined1 local_558;
  undefined1 local_557;
  undefined1 local_556;
  undefined1 local_555;
  undefined1 local_554;
  undefined1 local_553;
  undefined1 local_552;
  undefined1 local_551;
  undefined1 local_550;
  undefined1 local_54f;
  undefined1 local_54e;
  undefined1 local_54d;
  undefined1 local_54c;
  undefined1 local_54b;
  undefined1 local_54a;
  undefined1 local_549;
  undefined1 local_548;
  undefined1 local_547;
  undefined1 local_546;
  undefined1 local_545;
  undefined1 local_544;
  undefined1 local_543;
  undefined1 local_542;
  undefined1 local_541;
  undefined1 local_540;
  undefined1 local_53f;
  undefined1 local_53e;
  undefined1 local_53d;
  undefined1 local_53c;
  undefined1 local_53b;
  undefined1 local_53a;
  undefined1 local_539;
  undefined1 local_538;
  undefined1 local_537;
  undefined1 local_536;
  undefined1 local_535;
  undefined1 local_534;
  undefined1 local_533;
  undefined1 local_532;
  undefined1 local_531;
  undefined1 local_530;
  undefined1 local_52f;
  undefined1 local_52e;
  undefined1 local_52d;
  undefined1 local_52c;
  undefined1 local_52b;
  undefined1 local_52a;
  undefined1 local_529;
  undefined1 local_528;
  undefined1 local_527;
  undefined1 local_526;
  undefined1 local_525;
  undefined1 local_524;
  undefined1 local_523;
  undefined1 local_522;
  undefined1 local_521;
  undefined1 local_520;
  undefined1 local_51f;
  undefined1 local_51e;
  undefined1 local_51d;
  undefined1 local_51c;
  undefined1 local_51b;
  undefined1 local_51a;
  undefined1 local_519;
  undefined1 local_518;
  undefined1 local_517;
  undefined1 local_516;
  undefined1 local_515;
  undefined1 local_514;
  undefined1 local_513;
  undefined1 local_512;
  undefined1 local_511;
  undefined1 local_510;
  undefined1 local_50f;
  undefined1 local_50e;
  undefined1 local_50d;
  undefined1 local_50c;
  undefined1 local_50b;
  undefined1 local_50a;
  undefined1 local_509;
  undefined1 local_508;
  undefined1 local_507;
  undefined1 local_506;
  undefined1 local_505;
  undefined1 local_504;
  undefined1 local_503;
  undefined1 local_502;
  undefined1 local_501;
  undefined1 local_500;
  undefined1 local_4ff;
  undefined1 local_4fe;
  undefined1 local_4fd;
  undefined1 local_4fc;
  undefined1 local_4fb;
  undefined1 local_4fa;
  undefined1 local_4f9;
  undefined1 local_4f8;
  undefined1 local_4f7;
  undefined1 local_4f6;
  undefined1 local_4f5;
  undefined1 local_4f4;
  undefined1 local_4f3;
  undefined1 local_4f2;
  undefined1 local_4f1;
  undefined1 local_4f0;
  undefined1 local_4ef;
  undefined1 local_4ee;
  undefined1 local_4ed;
  undefined1 local_4ec;
  undefined1 local_4eb;
  undefined1 local_4ea;
  undefined1 local_4e9;
  undefined1 local_4e8;
  undefined1 local_4e7;
  undefined1 local_4e6;
  undefined1 local_4e5;
  undefined1 local_4e4;
  undefined1 local_4e3;
  undefined1 local_4e2;
  undefined1 local_4e1;
  undefined1 local_4e0;
  undefined1 local_4df;
  undefined1 local_4de;
  undefined1 local_4dd;
  undefined1 local_4dc;
  undefined1 local_4db;
  undefined1 local_4da;
  undefined1 local_4d9;
  undefined1 local_4d8;
  undefined1 local_4d7;
  undefined1 local_4d6;
  undefined1 local_4d5;
  undefined1 local_4d4;
  undefined1 local_4d3;
  undefined1 local_4d2;
  undefined1 local_4d1;
  undefined1 local_4d0;
  undefined1 local_4cf;
  undefined1 local_4ce;
  undefined1 local_4cd;
  undefined1 local_4cc;
  undefined1 local_4cb;
  undefined1 local_4ca;
  undefined1 local_4c9;
  undefined1 local_4c8;
  undefined1 local_4c7;
  undefined1 local_4c6;
  undefined1 local_4c5;
  undefined1 local_4c4;
  undefined1 local_4c3;
  undefined1 local_4c2;
  undefined1 local_4c1;
  undefined1 local_4c0;
  undefined1 local_4bf;
  undefined1 local_4be;
  undefined1 local_4bd;
  undefined1 local_4bc;
  undefined1 local_4bb;
  undefined1 local_4ba;
  undefined1 local_4b9;
  undefined1 local_4b8;
  undefined1 local_4b7;
  undefined1 local_4b6;
  undefined1 local_4b5;
  undefined1 local_4b4;
  undefined1 local_4b3;
  undefined1 local_4b2;
  undefined1 local_4b1;
  undefined1 local_4b0;
  undefined1 local_4af;
  undefined1 local_4ae;
  undefined1 local_4ad;
  undefined1 local_4ac;
  undefined1 local_4ab;
  undefined1 local_4aa;
  undefined1 local_4a9;
  undefined1 local_4a8;
  undefined1 local_4a7;
  undefined1 local_4a6;
  undefined1 local_4a5;
  undefined1 local_4a4;
  undefined1 local_4a3;
  undefined1 local_4a2;
  undefined1 local_4a1;
  undefined1 local_4a0;
  undefined1 local_49f;
  undefined1 local_49e;
  undefined1 auStack_49d [109];
  undefined1 local_430;
  undefined1 local_42f;
  undefined1 local_42e;
  undefined1 local_42d;
  undefined1 local_42c;
  undefined1 local_42b;
  undefined1 local_42a;
  undefined1 local_429;
  undefined1 local_428;
  undefined1 local_427;
  undefined1 local_426;
  undefined1 local_425;
  undefined1 local_424;
  undefined1 local_423;
  undefined1 local_422;
  undefined1 local_421;
  undefined1 local_420;
  undefined1 local_41f;
  undefined1 local_41e;
  undefined1 local_41d;
  undefined1 local_41c;
  undefined1 local_41b;
  undefined1 local_41a;
  undefined1 local_419;
  undefined1 local_418;
  undefined1 local_417;
  undefined1 local_416;
  undefined1 local_415;
  undefined1 local_414;
  undefined1 local_413;
  undefined1 local_412;
  undefined1 local_411;
  undefined1 local_410;
  undefined1 local_40f;
  undefined1 local_40e;
  undefined1 local_40d;
  undefined1 local_40c;
  undefined1 local_40b;
  undefined1 local_40a;
  undefined1 local_409;
  undefined1 local_408;
  undefined1 local_407;
  undefined1 local_406;
  undefined1 local_405;
  undefined1 local_404;
  undefined1 local_403;
  undefined1 local_402;
  undefined1 local_401;
  undefined1 local_400;
  undefined1 local_3ff;
  undefined1 local_3fe;
  undefined1 local_3fd;
  undefined1 local_3fc;
  undefined1 local_3fb;
  undefined1 local_3fa;
  undefined1 local_3f9;
  undefined1 local_3f8;
  undefined1 local_3f7;
  undefined1 local_3f6;
  undefined1 local_3f5;
  undefined1 local_3f4;
  undefined1 local_3f3;
  undefined1 local_3f2;
  undefined1 local_3f1;
  undefined1 local_3f0;
  undefined1 local_3ef;
  undefined1 local_3ee;
  undefined1 local_3ed;
  undefined1 local_3ec;
  undefined1 local_3eb;
  undefined1 local_3ea;
  undefined1 local_3e9;
  undefined1 local_3e8;
  undefined1 local_3e7;
  undefined1 local_3e6;
  undefined1 local_3e5;
  undefined1 local_3e4;
  undefined1 local_3e3;
  undefined1 local_3e2;
  undefined1 local_3e1;
  undefined1 local_3e0;
  undefined1 local_3df;
  undefined1 local_3de;
  undefined1 local_3dd;
  undefined1 local_3dc;
  undefined1 local_3db;
  undefined1 local_3da;
  undefined1 local_3d9;
  undefined1 local_3d8;
  undefined1 local_3d7;
  undefined1 local_3d6;
  undefined1 local_3d5;
  undefined1 local_3d4;
  undefined1 local_3d3;
  undefined1 local_3d2;
  undefined1 local_3d1;
  undefined1 local_3d0;
  undefined1 local_3cf;
  undefined1 local_3ce;
  undefined1 local_3cd;
  undefined1 local_3cc;
  undefined1 local_3cb;
  undefined1 local_3ca;
  undefined1 local_3c9;
  undefined1 local_3c8;
  undefined1 local_3c7;
  undefined1 local_3c6;
  undefined1 local_3c5;
  undefined1 local_3c4;
  undefined1 local_3c3;
  undefined1 local_3c2;
  undefined1 local_3c1;
  undefined1 local_3c0;
  undefined1 local_3bf;
  undefined1 local_3be;
  undefined1 local_3bd;
  undefined1 local_3bc;
  undefined1 local_3bb;
  undefined1 local_3ba;
  undefined1 local_3b9;
  undefined1 local_3b8;
  undefined1 local_3b7;
  undefined1 local_3b6;
  undefined1 local_3b5;
  undefined1 local_3b4;
  undefined1 local_3b3;
  undefined1 local_3b2;
  undefined1 local_3b1;
  undefined1 local_3b0;
  undefined1 local_3af;
  undefined1 local_3ae;
  undefined1 local_3ad;
  undefined1 local_3ac;
  undefined1 local_3ab;
  undefined1 local_3aa;
  undefined1 local_3a9;
  undefined1 local_3a8;
  undefined1 local_3a7;
  undefined1 local_3a6;
  undefined1 local_3a5;
  undefined1 local_3a4;
  undefined1 local_3a3;
  undefined1 local_3a2;
  undefined1 local_3a1;
  undefined1 local_3a0;
  undefined1 local_39f;
  undefined1 local_39e;
  undefined1 local_39d;
  undefined1 local_39c;
  undefined1 local_39b;
  undefined1 local_39a;
  undefined1 local_399;
  undefined1 local_398;
  undefined1 local_397;
  undefined1 local_396;
  undefined1 local_395;
  undefined1 local_394;
  undefined1 local_393;
  undefined1 local_392;
  undefined1 local_391;
  undefined1 local_390;
  undefined1 local_38f;
  undefined1 local_38e;
  undefined1 local_38d;
  undefined1 local_38c;
  undefined1 local_38b;
  undefined1 local_38a;
  undefined1 local_389;
  undefined1 local_388;
  undefined1 local_387;
  undefined1 local_386;
  undefined1 local_385;
  undefined1 local_384;
  undefined1 local_383;
  undefined1 local_382;
  undefined1 local_381;
  undefined1 local_380;
  undefined1 local_37f;
  undefined1 local_37e;
  undefined1 local_37d;
  undefined1 local_37c;
  undefined1 local_37b;
  undefined1 local_37a;
  undefined1 local_379;
  undefined1 local_378;
  undefined1 local_377;
  undefined1 local_376;
  undefined1 local_375;
  undefined1 local_374;
  undefined1 local_373;
  undefined1 local_372;
  undefined1 local_371;
  undefined1 local_370;
  undefined1 local_36f;
  undefined1 local_36e;
  undefined1 local_36d;
  undefined1 local_36c;
  undefined1 local_36b;
  undefined1 local_36a;
  undefined1 local_369;
  undefined1 local_368;
  undefined1 local_367;
  undefined1 local_366;
  undefined1 local_365;
  undefined1 local_364;
  undefined1 local_363;
  undefined1 local_362;
  undefined1 local_361;
  undefined1 local_360;
  undefined1 local_35f;
  undefined1 local_35e;
  undefined1 local_35d;
  undefined1 local_35c;
  undefined1 local_35b;
  undefined1 local_35a;
  undefined1 local_359;
  undefined1 local_358;
  undefined1 local_357;
  undefined1 local_356;
  undefined1 local_355;
  undefined1 local_354;
  undefined1 local_353;
  undefined1 local_352;
  undefined1 local_351;
  undefined1 local_350;
  undefined1 local_34f;
  undefined1 local_34e;
  undefined1 local_34d;
  undefined1 local_34c;
  undefined1 local_34b;
  undefined1 local_34a;
  undefined1 local_349;
  undefined1 local_348;
  undefined1 local_347;
  undefined1 local_346;
  undefined1 local_345;
  undefined1 local_344;
  undefined1 local_343;
  undefined1 local_342;
  undefined1 local_341;
  undefined1 local_340;
  undefined1 local_33f;
  undefined1 local_33e;
  undefined1 local_33d;
  undefined1 local_33c;
  undefined1 local_33b;
  undefined1 local_33a;
  undefined1 local_339;
  undefined1 local_338;
  undefined1 local_337;
  undefined1 local_336;
  undefined1 local_335;
  undefined1 local_334;
  undefined1 local_333;
  undefined1 local_332;
  undefined1 local_331;
  undefined1 local_330;
  undefined1 local_32f;
  undefined1 local_32e;
  undefined1 local_32d;
  undefined1 local_32c;
  undefined1 local_32b;
  undefined1 local_32a;
  undefined1 local_329;
  undefined1 local_328;
  undefined1 local_327;
  undefined1 local_326;
  undefined1 local_325;
  undefined1 local_324;
  undefined1 local_323;
  undefined1 local_322;
  undefined1 local_321;
  undefined1 local_320;
  undefined1 local_31f;
  undefined1 local_31e;
  undefined1 local_31d;
  undefined1 local_31c;
  undefined1 local_31b;
  undefined1 local_31a;
  undefined1 local_319;
  undefined1 local_318;
  undefined1 local_317;
  undefined1 local_316;
  undefined1 local_315;
  undefined1 local_314;
  undefined1 local_313;
  undefined1 local_312;
  undefined1 local_311;
  undefined1 local_310;
  undefined1 local_30f;
  undefined1 local_30e;
  undefined1 local_30d;
  undefined1 local_30c;
  undefined1 local_30b;
  undefined1 local_30a;
  undefined1 local_309;
  undefined1 local_308;
  undefined1 local_307;
  undefined1 local_306;
  undefined1 local_305;
  undefined1 local_304;
  undefined1 local_303;
  undefined1 local_302;
  undefined1 local_301;
  undefined1 local_300;
  undefined1 local_2ff;
  undefined1 local_2fe;
  undefined1 local_2fd;
  undefined1 local_2fc;
  undefined1 local_2fb;
  undefined1 local_2fa;
  undefined1 local_2f9;
  undefined1 local_2f8;
  undefined1 local_2f7;
  undefined1 local_2f6;
  undefined1 local_2f5;
  undefined1 local_2f4;
  undefined1 local_2f3;
  undefined1 local_2f2;
  undefined1 local_2f1;
  undefined1 local_2f0;
  undefined1 local_2ef;
  undefined1 local_2ee;
  undefined1 local_2ed;
  undefined1 local_2ec;
  undefined1 local_2eb;
  undefined1 local_2ea;
  undefined1 local_2e9;
  undefined1 local_2e8;
  undefined1 local_2e7;
  undefined1 local_2e6;
  undefined1 local_2e5;
  undefined1 local_2e4;
  undefined1 local_2e3;
  undefined1 local_2e2;
  undefined1 local_2e1;
  undefined1 local_2e0;
  undefined1 local_2df;
  undefined1 local_2de;
  undefined1 local_2dd;
  undefined1 local_2dc;
  undefined1 local_2db;
  undefined1 local_2da;
  undefined1 local_2d9;
  undefined1 local_2d8;
  undefined1 local_2d7;
  undefined1 local_2d6;
  undefined1 local_2d5;
  undefined1 local_2d4;
  undefined1 local_2d3;
  undefined1 local_2d2;
  undefined1 local_2d1;
  undefined1 local_2d0;
  undefined1 local_2cf;
  undefined1 local_2ce;
  undefined1 local_2cd;
  undefined1 local_2cc;
  undefined1 local_2cb;
  undefined1 local_2ca;
  undefined1 local_2c9;
  undefined1 local_2c8;
  undefined1 local_2c7;
  undefined1 local_2c6;
  undefined1 local_2c5;
  undefined1 local_2c4;
  undefined1 local_2c3;
  undefined1 local_2c2;
  undefined1 local_2c1;
  undefined1 local_2c0;
  undefined1 local_2bf;
  undefined1 local_2be;
  undefined1 local_2bd;
  undefined1 local_2bc;
  undefined1 local_2bb;
  undefined1 local_2ba;
  undefined1 local_2b9;
  undefined1 local_2b8;
  undefined1 local_2b7;
  undefined1 local_2b6;
  undefined1 local_2b5;
  undefined1 local_2b4;
  undefined1 local_2b3;
  undefined1 local_2b2;
  undefined1 local_2b1;
  undefined1 local_2b0;
  undefined1 local_2af;
  undefined1 local_2ae;
  undefined1 local_2ad;
  undefined1 local_2ac;
  undefined1 local_2ab;
  undefined1 local_2aa;
  undefined1 local_2a9;
  undefined1 local_2a8;
  undefined1 local_2a7;
  undefined1 local_2a6;
  undefined1 local_2a5;
  undefined1 local_2a4;
  undefined1 local_2a3;
  undefined1 local_2a2;
  undefined1 local_2a1;
  undefined1 local_2a0;
  undefined1 local_29f;
  undefined1 local_29e;
  undefined1 local_29d;
  undefined1 local_29c;
  undefined1 local_29b;
  undefined1 local_29a;
  undefined1 local_299;
  undefined1 local_298;
  undefined1 local_297;
  undefined1 local_296;
  undefined1 local_295;
  undefined1 local_294;
  undefined1 local_293;
  undefined1 local_292;
  undefined1 local_291;
  undefined1 local_290;
  undefined1 local_28f;
  undefined1 local_28e;
  undefined1 local_28d;
  undefined1 local_28c;
  undefined1 local_28b;
  undefined1 local_28a;
  undefined1 local_289;
  undefined1 local_288;
  undefined1 local_287;
  undefined1 local_286;
  undefined1 local_285;
  undefined1 local_284;
  undefined1 local_283;
  undefined1 local_282;
  undefined1 local_281;
  undefined1 local_280;
  undefined1 local_27f;
  undefined1 local_27e;
  undefined1 local_27d;
  undefined1 local_27c;
  undefined1 local_27b;
  undefined1 local_27a;
  undefined1 local_279;
  undefined1 local_278;
  undefined1 local_277;
  undefined1 local_276;
  undefined1 local_275;
  undefined1 local_274;
  undefined1 local_273;
  undefined1 local_272;
  undefined1 local_271;
  undefined1 local_270;
  undefined1 local_26f;
  undefined1 local_26e;
  undefined1 local_26d;
  undefined1 local_26c;
  undefined1 local_26b;
  undefined1 local_26a;
  undefined1 local_269;
  undefined1 local_268;
  undefined1 local_267;
  undefined1 local_266;
  undefined1 local_265;
  undefined1 local_264;
  undefined1 local_263;
  undefined1 local_262;
  undefined1 local_261;
  undefined1 local_260;
  undefined1 local_25f;
  undefined1 local_25e;
  undefined1 local_25d;
  undefined1 local_25c;
  undefined1 local_25b;
  undefined1 local_25a;
  undefined1 local_259;
  undefined1 local_258;
  undefined1 local_257;
  undefined1 local_256;
  undefined1 local_255;
  undefined1 local_254;
  undefined1 local_253;
  undefined1 local_252;
  undefined1 local_251;
  undefined1 local_250;
  undefined1 local_24f;
  undefined1 local_24e;
  undefined1 local_24d;
  undefined1 local_24c;
  undefined1 local_24b;
  undefined1 local_24a;
  undefined1 local_249;
  undefined1 local_248;
  undefined1 local_247;
  undefined1 local_246;
  undefined1 local_245;
  undefined1 local_244;
  undefined1 local_243;
  undefined1 local_242;
  undefined1 local_241;
  undefined1 local_240;
  undefined1 local_23f;
  undefined1 local_23e;
  undefined1 local_23d;
  undefined1 local_23c;
  undefined1 local_23b;
  undefined1 local_23a;
  undefined1 local_239;
  undefined1 local_238;
  undefined1 local_237;
  undefined1 local_236;
  undefined1 local_235;
  undefined1 local_234;
  undefined1 local_233;
  undefined1 local_232;
  undefined1 local_231;
  undefined1 local_230;
  undefined1 local_22f;
  undefined1 local_22e;
  undefined1 local_22d;
  undefined1 local_22c;
  undefined1 local_22b;
  undefined1 local_22a;
  undefined1 local_229;
  undefined1 local_228;
  undefined1 local_227;
  undefined1 local_226;
  undefined1 local_225;
  undefined1 local_224;
  undefined1 local_223;
  undefined1 local_222;
  undefined1 local_221;
  undefined1 local_220;
  undefined1 local_21f;
  undefined1 local_21e;
  undefined1 local_21d;
  undefined1 local_21c;
  undefined1 local_21b;
  undefined1 local_21a;
  undefined1 local_219;
  undefined1 local_218;
  undefined1 local_217;
  undefined1 local_216;
  undefined1 local_215;
  undefined1 local_214;
  undefined1 local_213;
  undefined1 local_212;
  undefined1 local_211;
  undefined1 local_210;
  undefined1 local_20f;
  undefined1 local_20e;
  undefined1 local_20d;
  undefined1 local_20c;
  undefined1 local_20b;
  undefined1 local_20a;
  undefined1 local_209;
  undefined1 local_208;
  undefined1 local_207;
  undefined1 local_206;
  undefined1 local_205;
  undefined1 local_204;
  undefined1 local_203;
  undefined1 local_202;
  undefined1 local_201;
  undefined1 local_200;
  undefined1 local_1ff;
  undefined1 local_1fe;
  undefined1 local_1fd;
  undefined1 local_1fc;
  undefined1 local_1fb;
  undefined1 local_1fa;
  undefined1 local_1f9;
  undefined1 local_1f8;
  undefined1 local_1f7;
  undefined1 local_1f6;
  undefined1 local_1f5;
  undefined1 local_1f4;
  undefined1 local_1f3;
  undefined1 local_1f2;
  undefined1 local_1f1;
  undefined1 local_1f0;
  undefined1 local_1ef;
  undefined1 local_1ee;
  undefined1 local_1ed;
  undefined1 local_1ec;
  undefined1 local_1eb;
  undefined1 local_1ea;
  undefined1 local_1e9;
  undefined1 local_1e8;
  undefined1 local_1e7;
  undefined1 local_1e6;
  undefined1 local_1e5;
  undefined1 local_1e4;
  undefined1 local_1e3;
  undefined1 local_1e2;
  undefined1 local_1e1;
  undefined1 local_1e0;
  undefined1 local_1df;
  undefined1 local_1de;
  undefined1 local_1dd;
  undefined1 local_1dc;
  undefined1 local_1db;
  undefined1 local_1da;
  undefined1 local_1d9;
  undefined1 local_1d8;
  undefined1 local_1d7;
  undefined1 local_1d6;
  undefined1 local_1d5;
  undefined1 local_1d4;
  undefined1 local_1d3;
  undefined1 local_1d2;
  undefined1 local_1d1;
  undefined1 local_1d0;
  undefined1 local_1cf;
  undefined1 local_1ce;
  undefined1 local_1cd;
  undefined1 local_1cc;
  undefined1 local_1cb;
  undefined1 local_1ca;
  undefined1 local_1c9;
  undefined1 local_1c8;
  undefined1 local_1c7;
  undefined1 local_1c6;
  undefined1 local_1c5;
  undefined1 local_1c4;
  undefined1 local_1c3;
  undefined1 local_1c2;
  undefined1 local_1c1;
  undefined1 local_1c0;
  undefined1 local_1bf;
  undefined1 local_1be;
  undefined1 local_1bd;
  undefined1 local_1bc;
  undefined1 local_1bb;
  undefined1 local_1ba;
  undefined1 local_1b9;
  undefined1 local_1b8;
  undefined1 local_1b7;
  undefined1 local_1b6;
  undefined1 local_1b5;
  undefined1 local_1b4;
  undefined1 local_1b3;
  undefined1 local_1b2;
  undefined1 local_1b1;
  undefined1 local_1b0;
  undefined1 local_1af;
  undefined1 local_1ae;
  undefined1 local_1ad;
  undefined1 local_1ac;
  undefined1 local_1ab;
  undefined1 local_1aa;
  undefined1 local_1a9;
  undefined1 local_1a8;
  undefined1 local_1a7;
  undefined1 local_1a6;
  undefined1 local_1a5;
  undefined1 local_1a4;
  undefined1 local_1a3;
  undefined1 local_1a2;
  undefined1 local_1a1;
  undefined1 local_1a0;
  undefined1 local_19f;
  undefined1 local_19e;
  undefined1 local_19d;
  undefined1 local_19c;
  undefined1 local_19b;
  undefined1 local_19a;
  undefined1 local_199;
  undefined1 local_198;
  undefined1 local_197;
  undefined1 local_196;
  undefined1 local_195;
  undefined1 local_194;
  undefined1 local_193;
  undefined1 local_192;
  undefined1 local_191;
  undefined1 local_190;
  undefined1 local_18f;
  undefined1 local_18e;
  undefined1 local_18d;
  undefined1 local_18c;
  undefined1 local_18b;
  undefined1 local_18a;
  undefined1 local_189;
  undefined1 local_188;
  undefined1 local_187;
  undefined1 local_186;
  undefined1 local_185;
  undefined1 local_184;
  undefined1 local_183;
  undefined1 local_182;
  undefined1 local_181;
  undefined1 local_180;
  undefined1 local_17f;
  undefined1 local_17e;
  undefined1 local_17d;
  undefined1 local_17c;
  undefined1 local_17b;
  undefined1 local_17a;
  undefined1 local_179;
  undefined1 local_178;
  undefined1 local_177;
  undefined1 local_176;
  undefined1 local_175;
  undefined1 local_174;
  undefined1 local_173;
  undefined1 local_172;
  undefined1 local_171;
  undefined1 local_170;
  undefined1 local_16f;
  undefined1 local_16e;
  undefined1 local_16d;
  undefined1 local_16c;
  undefined1 local_16b;
  undefined1 local_16a;
  undefined1 local_169;
  undefined1 local_168;
  undefined1 local_167;
  undefined1 local_166;
  undefined1 local_165;
  undefined1 local_164;
  undefined1 local_163;
  undefined1 local_162;
  undefined1 local_161;
  undefined1 local_160;
  undefined1 local_15f;
  undefined1 local_15e;
  undefined1 local_15d;
  undefined1 local_15c;
  undefined1 local_15b;
  undefined1 local_15a;
  undefined1 local_159;
  undefined1 local_158;
  undefined1 local_157;
  undefined1 local_156;
  undefined1 local_155;
  undefined1 local_154;
  undefined1 local_153;
  undefined1 local_152;
  undefined1 local_151;
  undefined1 local_150;
  undefined1 local_14f;
  undefined1 local_14e;
  undefined1 local_14d;
  undefined1 local_14c;
  undefined1 local_14b;
  undefined1 local_14a;
  undefined1 local_149;
  undefined1 local_148;
  undefined1 local_147;
  undefined1 auStack_146 [22];
  undefined1 auStack_130 [128];
  undefined1 auStack_b0 [128];
  uint local_30;
  
  local_30 = DAT_00064820;
  switch(param_2) {
  case 1:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x98);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_00045f28(puVar1);
    }
    if (puVar1 == (undefined4 *)0x0) goto switchD_0004764c_caseD_c;
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 4);
    break;
  case 2:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x9c8);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_00036f68(puVar1);
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_00044c6c((int)puVar1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc));
    }
    goto switchD_0004764c_caseD_c;
  case 3:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(100);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_0003bf8c(puVar1);
    }
    if (puVar1 == (undefined4 *)0x0) goto switchD_0004764c_caseD_c;
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 4);
    break;
  case 4:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x3c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_0003d55c(puVar1);
    }
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 4);
    break;
  case 5:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0xb8);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_00040284(puVar1);
    }
    if (puVar1 == (undefined4 *)0x0) goto switchD_0004764c_caseD_c;
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 4);
    break;
  case 6:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x2c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_0003f878(puVar1);
    }
    if (puVar1 == (undefined4 *)0x0) goto switchD_0004764c_caseD_c;
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 4);
    break;
  case 7:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_00046d04(puVar1);
    }
    if (puVar1 == (undefined4 *)0x0) goto switchD_0004764c_caseD_c;
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 4);
    break;
  case 8:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x48);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_00045208(puVar1);
    }
    if (puVar1 == (undefined4 *)0x0) goto switchD_0004764c_caseD_c;
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 4);
    break;
  case 9:
    lParam = 0x1235;
    goto LAB_00047964;
  case 10:
    lParam = 0x1236;
LAB_00047964:
    PostMessageW(*(HWND *)(param_1 + 8),0x8064,0xc70300,lParam);
    DestroyWindow(*(HWND *)(param_1 + 0xc));
    goto switchD_0004764c_caseD_c;
  case 0xb:
    local_82e = 0x62;
    local_816 = 0x2f;
    local_80b = 0x34;
    local_800 = 0x56;
    local_830 = 0xd;
    local_82f = 5;
    local_82d = 0;
    local_82c = 0;
    local_82b = 1;
    local_82a = 0;
    local_829 = 0;
    local_828 = 1;
    local_827 = 0;
    local_826 = 0;
    local_825 = 1;
    local_824 = 0;
    local_823 = 0;
    local_822 = 1;
    local_821 = 0;
    local_820 = 0;
    local_81f = 1;
    local_81e = 0;
    local_81d = 0;
    local_81c = 1;
    local_81b = 0x7f;
    local_81a = 0xff;
    local_819 = 0xff;
    local_818 = 0xd;
    local_817 = 0x10;
    local_815 = 7;
    local_814 = 0xff;
    local_813 = 7;
    local_812 = 0xff;
    local_811 = 7;
    local_810 = 0xff;
    local_80f = 7;
    local_80e = 0xff;
    local_80d = 0xd;
    local_80c = 0x10;
    local_80a = 4;
    local_809 = 0;
    local_808 = 4;
    local_807 = 0;
    local_806 = 4;
    local_805 = 0;
    local_804 = 4;
    local_803 = 0;
    local_802 = 0xd;
    local_801 = 0x10;
    local_7ff = 7;
    local_7fe = 0xff;
    local_7fd = 7;
    local_7fc = 0xff;
    local_7fb = 4;
    local_7fa = 0;
    local_7f9 = 4;
    local_7f8 = 0;
    local_7f7 = 7;
    local_7f6 = 0xff;
    local_7f5 = 7;
    local_7f4 = 0xff;
    local_7f3 = 0xd;
    local_7f2 = 0x10;
    local_7f1 = 0x7a;
    local_7f0 = 7;
    local_7ef = 0xff;
    local_7ee = 0xd;
    local_7ed = 0x10;
    local_7ec = 0x7f;
    local_7dd = 0x21;
    local_7eb = 7;
    local_7ea = 0xff;
    local_7e9 = 7;
    local_7e8 = 0xff;
    local_7e7 = 7;
    local_7e6 = 0xff;
    local_7e5 = 7;
    local_7e4 = 0xff;
    local_7e3 = 7;
    local_7e2 = 0xff;
    local_7e1 = 7;
    local_7e0 = 0xff;
    local_7df = 0xd;
    local_7de = 0x11;
    local_7dc = 7;
    local_7db = 0x8c;
    local_7da = 1;
    local_7d9 = 0xc;
    local_7d8 = 7;
    local_7d7 = 0x18;
    local_7d6 = 0xe;
    local_7d5 = 0x19;
    local_7d4 = 6;
    local_7d3 = 0xf0;
    local_7d2 = 4;
    local_7d1 = 0x76;
    local_7d0 = 0;
    local_7cf = 0;
    local_7ce = 7;
    local_7cd = 0x8c;
    local_7cc = 1;
    local_7cb = 0xc;
    local_7ca = 7;
    local_7c9 = 0x18;
    local_7c8 = 0xe;
    local_7c7 = 0x19;
    local_7c6 = 6;
    local_7c5 = 0xf0;
    local_7c4 = 4;
    local_7c3 = 0x76;
    local_7c2 = 0;
    local_7c1 = 0;
    local_7c0 = 7;
    local_7bf = 0x8c;
    local_7be = 1;
    local_7bd = 0xc;
    local_7bc = 7;
    local_7bb = 0x18;
    local_7ba = 0xe;
    local_7b9 = 0x19;
    local_7b8 = 6;
    local_7b7 = 0xf0;
    local_7b6 = 4;
    local_7b5 = 0x76;
    local_7b4 = 0;
    local_7b3 = 0;
    local_7b2 = 7;
    local_7b1 = 0x8c;
    local_7b0 = 1;
    local_7af = 0xc;
    local_7ae = 7;
    local_7ad = 0x18;
    local_7ac = 0xe;
    local_7ab = 0x19;
    local_7aa = 6;
    local_7a9 = 0xf0;
    local_7a8 = 4;
    local_7a7 = 0x76;
    local_7a6 = 0;
    local_7a2 = 0x3d;
    local_7a5 = 0;
    local_7a4 = 0xd;
    local_7a3 = 0x11;
    local_7a1 = 7;
    local_7a0 = 0x8c;
    local_79f = 1;
    local_79e = 0xc;
    local_79d = 7;
    local_79c = 0x18;
    local_79b = 0xe;
    local_79a = 0x19;
    local_799 = 6;
    local_798 = 0xf0;
    local_797 = 4;
    local_796 = 0x76;
    local_795 = 0;
    local_794 = 0;
    local_793 = 7;
    local_792 = 0x8c;
    local_791 = 1;
    local_790 = 0xc;
    local_78f = 7;
    local_78e = 0x18;
    local_78d = 0xe;
    local_78c = 0x19;
    local_78b = 6;
    local_78a = 0xf0;
    local_789 = 4;
    local_788 = 0x76;
    local_787 = 0;
    local_786 = 0;
    local_785 = 7;
    local_784 = 0x8c;
    local_783 = 1;
    local_782 = 0xc;
    local_781 = 7;
    local_780 = 0x18;
    local_77f = 0xe;
    local_77e = 0x19;
    local_77d = 6;
    local_77c = 0xf0;
    local_77b = 4;
    local_77a = 0x76;
    local_779 = 0;
    local_778 = 0;
    local_777 = 7;
    local_776 = 0x8c;
    local_775 = 1;
    local_774 = 0xc;
    local_773 = 7;
    local_772 = 0x18;
    local_771 = 0xe;
    local_770 = 0x19;
    local_76f = 6;
    local_76e = 0xf0;
    local_76d = 4;
    local_76c = 0x76;
    local_76b = 0;
    local_76a = 0;
    local_769 = 0xd;
    local_768 = 0x11;
    local_767 = 0x59;
    local_766 = 7;
    local_765 = 0x8c;
    local_764 = 1;
    local_763 = 0xc;
    local_762 = 7;
    local_761 = 0x18;
    local_760 = 0xe;
    local_75f = 0x19;
    local_75e = 6;
    local_75d = 0xf0;
    local_75c = 4;
    local_75b = 0x76;
    local_75a = 0;
    local_759 = 0;
    local_758 = 7;
    local_757 = 0x8c;
    local_756 = 1;
    local_755 = 0xc;
    local_754 = 7;
    local_753 = 0x18;
    local_752 = 0xe;
    local_751 = 0x19;
    local_750 = 6;
    local_74f = 0xf0;
    local_74e = 4;
    local_74d = 0x76;
    local_74c = 0;
    local_74b = 0;
    local_74a = 7;
    local_749 = 0x8c;
    local_748 = 1;
    local_747 = 0xc;
    local_746 = 7;
    local_745 = 0x18;
    local_744 = 0xe;
    local_743 = 0x19;
    local_742 = 6;
    local_741 = 0xf0;
    local_740 = 4;
    local_73f = 0x76;
    local_73e = 0;
    local_73d = 0;
    local_73c = 7;
    local_73b = 0x8c;
    local_73a = 1;
    local_739 = 0xc;
    local_738 = 7;
    local_737 = 0x18;
    local_736 = 0xe;
    local_735 = 0x19;
    local_734 = 6;
    local_733 = 0xf0;
    local_732 = 4;
    local_731 = 0x76;
    local_730 = 0;
    local_72f = 0;
    local_72e = 0xd;
    local_72d = 0x11;
    local_72c = 0x75;
    local_72b = 7;
    local_72a = 0x8c;
    local_729 = 1;
    local_728 = 0xc;
    local_727 = 7;
    local_726 = 0x18;
    local_725 = 0xe;
    local_724 = 0x19;
    local_723 = 6;
    local_722 = 0xf0;
    local_721 = 4;
    local_720 = 0x76;
    local_71f = 0;
    local_71e = 0;
    local_71d = 7;
    local_71c = 0x8c;
    local_71b = 1;
    local_71a = 0xc;
    local_719 = 7;
    local_718 = 0x18;
    local_717 = 0xe;
    local_716 = 0x19;
    local_715 = 6;
    local_714 = 0xf0;
    local_713 = 4;
    local_712 = 0x76;
    local_711 = 0;
    local_710 = 0;
    local_70f = 7;
    local_70e = 0x8c;
    local_70d = 1;
    local_70c = 0xc;
    local_70b = 7;
    local_70a = 0x18;
    local_709 = 0xe;
    local_708 = 0x19;
    local_707 = 6;
    local_706 = 0xf0;
    local_6f8 = 0xf0;
    local_705 = 4;
    local_704 = 0x76;
    local_703 = 0;
    local_702 = 0;
    local_701 = 7;
    local_700 = 0x8c;
    local_6ff = 1;
    local_6fe = 0xc;
    local_6fd = 7;
    local_6fc = 0x18;
    local_6fb = 0xe;
    local_6fa = 0x19;
    local_6f9 = 6;
    local_6f7 = 4;
    local_6f6 = 0x76;
    local_6f5 = 0;
    local_6f4 = 0;
    local_6f3 = 0xd;
    local_6f2 = 0x11;
    local_6f1 = 0x93;
    local_6f0 = 0;
    local_6ef = 0;
    local_6ee = 4;
    local_6ed = 0;
    local_6ec = 0;
    local_6eb = 0;
    local_6ea = 0;
    local_6e9 = 0;
    local_6e8 = 0;
    local_6e7 = 0;
    local_6e6 = 0;
    local_6e5 = 0;
    local_6e4 = 0;
    local_6e3 = 0;
    local_6e2 = 0;
    local_6e1 = 0;
    local_6e0 = 0;
    local_6df = 0;
    local_6de = 0;
    local_6dd = 0;
    local_6dc = 0;
    local_6db = 0;
    local_6da = 4;
    local_6d9 = 0;
    local_6d8 = 0;
    local_6d7 = 0;
    local_6d6 = 0;
    local_6d5 = 0;
    local_6d4 = 0;
    local_6d3 = 0;
    local_6d2 = 0;
    local_6d1 = 0;
    local_6d0 = 0;
    local_6cf = 0;
    local_6ce = 0;
    local_6cd = 0;
    local_6cc = 0;
    local_6cb = 0;
    local_6ca = 0;
    local_6c9 = 0;
    local_6c8 = 0;
    local_6c7 = 0;
    local_6c6 = 4;
    local_6c5 = 0;
    local_6c4 = 0;
    local_6c3 = 0;
    local_6c2 = 0;
    local_6c1 = 0;
    local_6c0 = 0;
    local_6bf = 0;
    local_6be = 0;
    local_6bd = 0;
    local_6bc = 0;
    local_6bb = 0;
    local_6ba = 0;
    local_6b9 = 0;
    local_6b8 = 0;
    local_6b7 = 0;
    local_6b6 = 0;
    local_6b5 = 0;
    local_6b4 = 0xd;
    local_6b3 = 0x11;
    local_6b2 = 0xb1;
    local_6b1 = 0;
    local_6b0 = 0;
    local_6af = 4;
    local_6ae = 0;
    local_6ad = 0;
    local_6ac = 0;
    local_6ab = 0;
    local_6aa = 0;
    local_6a9 = 0;
    local_6a8 = 0;
    local_6a7 = 0;
    local_6a6 = 0;
    local_6a5 = 0;
    local_6a4 = 0;
    local_6a3 = 0;
    local_6a2 = 0;
    local_6a1 = 0;
    local_6a0 = 0;
    local_69f = 0;
    local_69e = 0;
    local_69d = 0;
    local_69c = 0;
    local_69b = 4;
    local_69a = 0;
    local_699 = 0;
    local_698 = 0;
    local_697 = 0;
    local_696 = 0;
    local_695 = 0;
    local_694 = 0;
    local_693 = 0;
    local_692 = 0;
    local_691 = 0;
    local_690 = 0;
    local_68f = 0;
    local_68e = 0;
    local_68d = 0;
    local_68c = 0;
    local_68b = 0;
    local_68a = 0;
    local_689 = 0;
    local_688 = 0;
    local_687 = 4;
    local_686 = 0;
    local_685 = 0;
    local_684 = 0;
    local_683 = 0;
    local_682 = 0;
    local_681 = 0;
    local_680 = 0;
    local_67f = 0;
    local_67e = 0;
    local_67d = 0;
    local_67c = 0;
    local_67b = 0;
    local_67a = 0;
    local_679 = 0;
    local_678 = 0;
    local_677 = 0;
    local_676 = 0;
    local_675 = 0xd;
    local_674 = 0x11;
    local_673 = 0xcf;
    local_672 = 0;
    local_671 = 0;
    local_670 = 4;
    local_66f = 0;
    local_66e = 0;
    local_66d = 0;
    local_66c = 0;
    local_66b = 0;
    local_66a = 0;
    local_669 = 0;
    local_668 = 0;
    local_667 = 0;
    local_666 = 0;
    local_665 = 0;
    local_664 = 0;
    local_663 = 0;
    local_662 = 0;
    local_661 = 0;
    local_660 = 0;
    local_65f = 0;
    local_65e = 0;
    local_65d = 0;
    local_65c = 4;
    local_65b = 0;
    local_65a = 0;
    local_659 = 0;
    local_658 = 0;
    local_657 = 0;
    local_656 = 0;
    local_655 = 0;
    local_654 = 0;
    local_653 = 0;
    local_652 = 0;
    local_651 = 0;
    local_650 = 0;
    local_64f = 0;
    local_64e = 0;
    local_64d = 0;
    local_64c = 0;
    local_64b = 0;
    local_64a = 0;
    local_649 = 0;
    local_648 = 4;
    local_647 = 0;
    local_646 = 0;
    local_645 = 0;
    local_644 = 0;
    local_643 = 0;
    local_642 = 0;
    local_641 = 0;
    local_640 = 0;
    local_63f = 0;
    local_63e = 0;
    local_63d = 0;
    local_63c = 0;
    local_63b = 0;
    local_63a = 0;
    local_639 = 0;
    local_638 = 0;
    local_637 = 0;
    local_636 = 0xd;
    local_635 = 0x11;
    local_634 = 0xed;
    local_633 = 0;
    local_632 = 0;
    local_631 = 4;
    local_630 = 0;
    local_62f = 0;
    local_62e = 0;
    local_62d = 0;
    local_62c = 0;
    local_62b = 0;
    local_62a = 0;
    local_629 = 0;
    local_628 = 0;
    local_627 = 0;
    local_626 = 0;
    local_625 = 0;
    local_624 = 0;
    local_623 = 0;
    local_622 = 0;
    local_621 = 0;
    local_620 = 0;
    local_61f = 0;
    local_61e = 0;
    local_61d = 4;
    local_61c = 0;
    local_61b = 0;
    local_61a = 0;
    local_619 = 0;
    local_618 = 0;
    local_617 = 0;
    local_616 = 0;
    local_615 = 0;
    local_614 = 0;
    local_613 = 0;
    local_612 = 0;
    local_611 = 0;
    local_610 = 0;
    local_60f = 0;
    local_60e = 0;
    local_60d = 0;
    local_60c = 0;
    local_60b = 0;
    local_60a = 0;
    local_609 = 4;
    local_608 = 0;
    local_607 = 0;
    local_606 = 0;
    local_605 = 0;
    local_604 = 0;
    local_603 = 0;
    local_602 = 0;
    local_601 = 0;
    local_600 = 0;
    local_5ff = 0;
    local_5fe = 0;
    local_5fd = 0;
    local_5fc = 0;
    local_5fb = 0;
    local_5fa = 0;
    local_5f9 = 0;
    local_5f8 = 0;
    local_5f7 = 0xd;
    local_5f6 = 0x12;
    local_5f5 = 0xb;
    local_5f4 = 0;
    local_5f3 = 0;
    local_5f2 = 4;
    local_5f1 = 0;
    local_5f0 = 0;
    local_5ef = 0;
    local_5ee = 0;
    local_5ed = 0;
    local_5ec = 0;
    local_5eb = 0;
    local_5ea = 0;
    local_5e9 = 0;
    local_5e8 = 0;
    local_5e7 = 0;
    local_5e6 = 0;
    local_5e5 = 0;
    local_5e4 = 0;
    local_5e3 = 0;
    local_5e2 = 0;
    local_5e1 = 0;
    local_5e0 = 0;
    local_5df = 0;
    local_5de = 4;
    local_5dd = 0;
    local_5dc = 0;
    local_5db = 0;
    local_5da = 0;
    local_5d9 = 0;
    local_5d8 = 0;
    local_5d7 = 0;
    local_5d6 = 0;
    local_5d5 = 0;
    local_5d4 = 0;
    local_5d3 = 0;
    local_5d2 = 0;
    local_5d1 = 0;
    local_5d0 = 0;
    local_5cf = 0;
    local_5ce = 0;
    local_5cd = 0;
    local_5cc = 0;
    local_5cb = 0;
    local_5ca = 4;
    local_5c9 = 0;
    local_5c8 = 0;
    local_5c7 = 0;
    local_5c6 = 0;
    local_5c5 = 0;
    local_5c4 = 0;
    local_5c3 = 0;
    local_5c2 = 0;
    local_5c1 = 0;
    local_5c0 = 0;
    local_5bf = 0;
    local_5be = 0;
    local_5bd = 0;
    local_5bc = 0;
    local_5bb = 0;
    local_5ba = 0;
    local_5b9 = 0;
    local_5b8 = 0;
    local_5b7 = 0;
    local_5b6 = 4;
    local_5b5 = 0;
    local_5b4 = 0;
    local_5b3 = 0;
    local_5b2 = 0;
    local_5b1 = 0;
    local_5b0 = 0;
    local_5af = 0;
    local_5ae = 0;
    local_5ad = 0;
    local_5ac = 0;
    local_5ab = 0;
    local_5aa = 0;
    local_5a9 = 0;
    local_5a8 = 0;
    local_5a7 = 0;
    local_5a6 = 0;
    local_5a5 = 0;
    local_5a4 = 0xd;
    local_5a3 = 0x12;
    local_5a2 = 0x33;
    local_5a1 = 0;
    local_5a0 = 0;
    local_59f = 4;
    local_59e = 0;
    local_59d = 0;
    local_59c = 0;
    local_59b = 0;
    local_59a = 0;
    local_599 = 0;
    local_598 = 0;
    local_597 = 0;
    local_596 = 0;
    local_595 = 0;
    local_594 = 0;
    local_593 = 0;
    local_592 = 0;
    local_591 = 0;
    local_590 = 0;
    local_58f = 0;
    local_58e = 0;
    local_58d = 0;
    local_58c = 0;
    local_58b = 4;
    local_58a = 0;
    local_589 = 0;
    local_588 = 0;
    local_587 = 0;
    local_586 = 0;
    local_585 = 0;
    local_584 = 0;
    local_583 = 0;
    local_582 = 0;
    local_581 = 0;
    local_580 = 0;
    local_57f = 0;
    local_57e = 0;
    local_57d = 0;
    local_57c = 0;
    local_57b = 0;
    local_57a = 0;
    local_579 = 0xd;
    local_577 = 0x47;
    local_560 = 0x51;
    local_578 = 0x12;
    local_576 = 0;
    local_575 = 0;
    local_574 = 4;
    local_573 = 0;
    local_572 = 0;
    local_571 = 0;
    local_570 = 0;
    local_56f = 0;
    local_56e = 0;
    local_56d = 0;
    local_56c = 0;
    local_56b = 0;
    local_56a = 0;
    local_569 = 0;
    local_568 = 0;
    local_567 = 0;
    local_566 = 0;
    local_565 = 0;
    local_564 = 0;
    local_563 = 0;
    local_562 = 0xd;
    local_561 = 0x12;
    local_55f = 0;
    local_55e = 0;
    local_55d = 4;
    local_55c = 0;
    local_55b = 0;
    local_55a = 0;
    local_559 = 0;
    local_558 = 0;
    local_557 = 0;
    local_556 = 0;
    local_555 = 0;
    local_554 = 0;
    local_553 = 0;
    local_552 = 0;
    local_551 = 0;
    local_550 = 0;
    local_54f = 0;
    local_54e = 0;
    local_54d = 0;
    local_54c = 0;
    local_54b = 0;
    local_54a = 0;
    local_549 = 4;
    local_548 = 0;
    local_547 = 0;
    local_546 = 0;
    local_545 = 0;
    local_544 = 0;
    local_543 = 0;
    local_542 = 0;
    local_541 = 0;
    local_540 = 0;
    local_53f = 0;
    local_53e = 0;
    local_53d = 0;
    local_53c = 0;
    local_53b = 0;
    local_53a = 0;
    local_539 = 0;
    local_538 = 0;
    local_537 = 0xd;
    local_536 = 0x12;
    local_535 = 0x65;
    local_534 = 0;
    local_533 = 0;
    local_532 = 0;
    local_531 = 0;
    local_530 = 0;
    local_52f = 0;
    local_52e = 0;
    local_52d = 0;
    local_52c = 0;
    local_52b = 0;
    local_507 = 0xa1;
    local_505 = 0x13;
    local_4fb = 0xf8;
    local_4f7 = 0x14;
    local_51e = 0x6f;
    local_501 = 0x27;
    local_4fd = 0x6f;
    local_4f3 = 0x27;
    local_4ef = 0x4a;
    local_52a = 0;
    local_529 = 0;
    local_528 = 0;
    local_527 = 0;
    local_526 = 0;
    local_525 = 0;
    local_524 = 0;
    local_523 = 0;
    local_522 = 0;
    local_521 = 0;
    local_520 = 0xd;
    local_51f = 0x12;
    local_51d = 0;
    local_51c = 0;
    local_51b = 4;
    local_51a = 0;
    local_519 = 0;
    local_518 = 0;
    local_517 = 0;
    local_516 = 0;
    local_515 = 0;
    local_514 = 0;
    local_513 = 0;
    local_512 = 0;
    local_511 = 0;
    local_510 = 0;
    local_50f = 0;
    local_50e = 0;
    local_50d = 0;
    local_50c = 0;
    local_50b = 0;
    local_50a = 0;
    local_509 = 0xd;
    local_508 = 0x12;
    local_506 = 5;
    local_504 = 0;
    local_503 = 3;
    local_502 = 2;
    local_500 = 0xc;
    local_4ff = 7;
    local_4fe = 5;
    local_4fc = 7;
    local_4fa = 0;
    local_4f9 = 0;
    local_4f8 = 3;
    local_4f6 = 0;
    local_4f5 = 0xe;
    local_4f4 = 6;
    local_4f2 = 0xc;
    local_4f1 = 0x1c;
    local_4f0 = 3;
    local_4ee = 7;
    local_4ed = 0xe2;
    local_4ec = 0;
    local_4eb = 0;
    local_4ea = 1;
    local_4e9 = 0xb1;
    local_4e8 = 0;
    local_4e7 = 0x37;
    local_4e6 = 3;
    local_4df = 0x85;
    local_4db = 0xbe;
    local_4d3 = 0xe8;
    local_4d2 = 0xf;
    local_4d1 = 0xd1;
    local_4ca = 0xc0;
    local_4be = 0xf1;
    local_4ba = 0xf7;
    local_4b6 = 0xee;
    local_4b2 = 0x35;
    local_4e5 = 99;
    local_4b0 = 0xc4;
    local_4d9 = 0x7c;
    local_4ac = 0x69;
    local_4e4 = 0xc;
    local_4e3 = 0x6e;
    local_4e2 = 0;
    local_4e1 = 9;
    local_4e0 = 7;
    local_4de = 0;
    local_4dd = 0;
    local_4dc = 0;
    local_4da = 0xd;
    local_4d8 = 5;
    local_4d7 = 0xd9;
    local_4d6 = 0;
    local_4d5 = 0;
    local_4d4 = 1;
    local_4d0 = 0xe;
    local_4cf = 0xf4;
    local_4ce = 0;
    local_4cd = 0;
    local_4cc = 0xd;
    local_4cb = 0x12;
    local_4c9 = 1;
    local_4c8 = 0xf2;
    local_4c7 = 0;
    local_4c6 = 7;
    local_4c5 = 3;
    local_4c4 = 0xe4;
    local_4c3 = 0xc;
    local_4c2 = 0xe;
    local_4c1 = 2;
    local_4c0 = 0x75;
    local_4bf = 7;
    local_4bd = 0;
    local_4bc = 0;
    local_4bb = 2;
    local_4b9 = 0;
    local_4b8 = 0x1c;
    local_4b7 = 5;
    local_4b5 = 0xc;
    local_4b4 = 0x38;
    local_4b3 = 0;
    local_4b1 = 7;
    local_4af = 0;
    local_4ae = 0;
    local_4ad = 0;
    local_4ab = 0xc;
    local_4aa = 0xd2;
    local_4a5 = 1;
    local_4a9 = 6;
    local_4a8 = 0xff;
    local_4a7 = 0;
    local_4a6 = 0;
    local_4a4 = 0x41;
    local_4a3 = 0xe;
    local_4a2 = 0x81;
    local_4a1 = 3;
    local_4a0 = 0x5d;
    local_49f = 0;
    local_49e = 0;
    memset(auStack_49d,0,0x6d);
    local_42d = 0x9b;
    local_425 = 0x7a;
    local_424 = 0xb9;
    local_41d = 0xb6;
    local_42c = 5;
    local_429 = 3;
    local_427 = 5;
    local_420 = 5;
    local_417 = 0xa0;
    local_430 = 0xc;
    local_42f = 0x6c;
    local_42e = 0;
    local_42b = 0;
    local_42a = 0;
    local_428 = 0;
    local_426 = 0xfd;
    local_423 = 0;
    local_422 = 0x2d;
    local_421 = 0;
    local_41f = 0xff;
    local_41e = 0xfe;
    local_41c = 0;
    local_41b = 0;
    local_41a = 1;
    local_419 = 0x40;
    local_418 = 0xf;
    local_416 = 7;
    local_415 = 0xff;
    local_414 = 0;
    local_413 = 1;
    local_412 = 0;
    local_411 = 0x12;
    local_410 = 0xff;
    local_40f = 0xbf;
    local_40e = 0x79;
    local_40d = 0;
    local_40c = 10;
    local_40b = 0;
    local_40a = 0x12;
    local_409 = 0xff;
    local_408 = 0xff;
    local_3f6 = 0x10;
    local_3e9 = 0xe8;
    local_407 = 0x92;
    local_401 = 0x92;
    local_3e2 = 6;
    local_404 = 1;
    local_3fd = 1;
    local_3e6 = 0x18;
    local_3e5 = 0xe;
    local_3e3 = 1;
    local_3da = 0x7e;
    local_3d3 = 0x7e;
    local_3cf = 1;
    local_406 = 0;
    local_405 = 0;
    local_403 = 0x6e;
    local_402 = 0xf;
    local_400 = 7;
    local_3ff = 0xff;
    local_3fe = 0;
    local_3fc = 0;
    local_3fb = 0x12;
    local_3fa = 0xff;
    local_3f9 = 0xdf;
    local_3f8 = 0xbc;
    local_3f7 = 0;
    local_3f5 = 0;
    local_3f4 = 0x12;
    local_3f3 = 0xff;
    local_3f2 = 0xdf;
    local_3f1 = 0xbc;
    local_3f0 = 0;
    local_3ef = 0;
    local_3ee = 0;
    local_3ed = 0;
    local_3ec = 0;
    local_3eb = 0;
    local_3ea = 0xc;
    local_3e8 = 0xff;
    local_3e7 = 0xf3;
    local_3e4 = 0x25;
    local_3e1 = 7;
    local_3e0 = 0xff;
    local_3df = 0;
    local_3de = 0x40;
    local_3dd = 0;
    local_3dc = 2;
    local_3db = 0xff;
    local_3d9 = 0xf2;
    local_3d8 = 0;
    local_3d7 = 0x66;
    local_3d6 = 0;
    local_3d5 = 2;
    local_3d4 = 0xff;
    local_3d2 = 0xf2;
    local_3d1 = 0;
    local_3d0 = 0;
    local_3ce = 0x6e;
    local_3cd = 0xf;
    local_3cc = 0xa5;
    local_3cb = 7;
    local_3ca = 0xff;
    local_3c9 = 0;
    local_3c8 = 0x40;
    local_3c7 = 0;
    local_3c6 = 0x5b;
    local_3b9 = 1;
    local_3b8 = 0xab;
    local_3b6 = 0x95;
    local_3a8 = 0xff;
    local_3a2 = 0xff;
    local_397 = 1;
    local_395 = 10;
    local_394 = 0x3d;
    local_393 = 0x71;
    local_391 = 0xc;
    local_390 = 0xe8;
    local_38f = 0xff;
    local_38d = 0x18;
    local_3c5 = 0xff;
    local_3c4 = 0xfb;
    local_3c3 = 0xb3;
    local_3be = 0xff;
    local_3bd = 0xfb;
    local_3bc = 0xb3;
    local_3b7 = 0xf;
    local_3b4 = 0xff;
    local_3af = 0xff;
    local_3ae = 0xfb;
    local_3ad = 0xb3;
    local_3a7 = 0xfb;
    local_3a6 = 0xb3;
    local_3a1 = 0xf;
    local_38c = 0xc;
    local_3c2 = 0;
    local_3c1 = 0x66;
    local_3c0 = 0;
    local_3bf = 0x5b;
    local_3bb = 0;
    local_3ba = 0;
    local_3b5 = 7;
    local_3b3 = 0;
    local_3b2 = 0x66;
    local_3b1 = 0;
    local_3b0 = 0x5b;
    local_3ac = 0;
    local_3ab = 0x80;
    local_3aa = 0;
    local_3a9 = 8;
    local_3a5 = 0;
    local_3a4 = 0;
    local_3a3 = 7;
    local_3a0 = 0x55;
    local_39f = 0;
    local_39e = 0x2e;
    local_39d = 0;
    local_39c = 0x1f;
    local_39b = 0;
    local_39a = 0;
    local_399 = 0;
    local_398 = 0;
    local_396 = 0x9a;
    local_392 = 0;
    local_38e = 0xf3;
    local_38b = 0x6c;
    local_38a = 2;
    local_383 = 0x12;
    local_36d = 0x12;
    local_366 = 0x12;
    local_365 = 0xff;
    local_361 = 0xff;
    local_37e = 0x80;
    local_360 = 1;
    local_387 = 0xff;
    local_382 = 0xff;
    local_37b = 0xff;
    local_377 = 0xff;
    local_35e = 0xf;
    local_388 = 7;
    local_381 = 0xf7;
    local_378 = 7;
    local_376 = 2;
    local_372 = 7;
    local_36b = 0xf7;
    local_364 = 0xf7;
    local_35b = 0xff;
    local_356 = 0xff;
    local_389 = 0x25;
    local_374 = 0xf;
    local_371 = 0xff;
    local_36c = 0xff;
    local_35f = 0xab;
    local_35d = 0xab;
    local_355 = 0xf7;
    local_386 = 0;
    local_385 = 0;
    local_384 = 0;
    local_380 = 0xef;
    local_37f = 0;
    local_37d = 0;
    local_37c = 0x5b;
    local_37a = 0xbf;
    local_379 = 0x79;
    local_375 = 0;
    local_373 = 0x80;
    local_370 = 0;
    local_36f = 0;
    local_36e = 0;
    local_36a = 0xef;
    local_369 = 0;
    local_368 = 0x80;
    local_367 = 0;
    local_363 = 0xef;
    local_362 = 7;
    local_35c = 7;
    local_35a = 0;
    local_359 = 0x80;
    local_358 = 0;
    local_357 = 0xb2;
    local_354 = 0xef;
    local_353 = 0;
    local_352 = 0x80;
    local_351 = 0;
    local_350 = 0x5b;
    local_34f = 0xff;
    local_34e = 0xbf;
    local_34d = 0x79;
    local_34c = 0;
    local_349 = 0xff;
    local_337 = 0xe8;
    local_336 = 0xff;
    local_334 = 0x18;
    local_34a = 7;
    local_347 = 0x55;
    local_345 = 0x2e;
    local_343 = 0x2e;
    local_341 = 0x55;
    local_33d = 0x9a;
    local_332 = 0xfa;
    local_330 = 0x58;
    local_32a = 0x2e;
    local_320 = 0xd9;
    local_34b = 0;
    local_348 = 0xf;
    local_346 = 0;
    local_344 = 0;
    local_342 = 0;
    local_340 = 0xf;
    local_33f = 0xef;
    local_33e = 1;
    local_33c = 0x40;
    local_33b = 0;
    local_33a = 0;
    local_339 = 0;
    local_338 = 0xc;
    local_335 = 0xf3;
    local_333 = 9;
    local_331 = 1;
    local_32f = 7;
    local_32e = 0xff;
    local_32d = 0;
    local_32c = 0x1a;
    local_32b = 0;
    local_329 = 0xff;
    local_328 = 0xdf;
    local_327 = 0xbc;
    local_326 = 0;
    local_325 = 0x40;
    local_324 = 0;
    local_323 = 9;
    local_322 = 0xff;
    local_321 = 0xfd;
    local_31f = 0;
    local_31e = 0;
    local_31d = 1;
    local_31c = 0x6e;
    local_31b = 0xf;
    local_31a = 0x92;
    local_319 = 7;
    local_318 = 0xff;
    local_317 = 0;
    local_316 = 0x1a;
    local_315 = 0;
    local_314 = 0x5b;
    local_313 = 0xff;
    local_312 = 0xf3;
    local_311 = 0x18;
    local_310 = 0;
    local_30f = 0x40;
    local_30e = 0;
    local_30d = 9;
    local_30c = 0xff;
    local_30b = 0xff;
    local_30a = 0x92;
    local_309 = 0;
    local_308 = 0;
    local_302 = 0xff;
    local_2fd = 0xff;
    local_2f9 = 0x5a;
    local_2f6 = 0xff;
    local_2eb = 0xff;
    local_2e3 = 0x77;
    local_300 = 0x1a;
    local_2db = 0x19;
    local_307 = 1;
    local_2f4 = 0xb6;
    local_2e2 = 1;
    local_2d7 = 0x93;
    local_306 = 0x6e;
    local_305 = 0xf;
    local_2fe = 0xb2;
    local_2f7 = 9;
    local_2f5 = 0xfe;
    local_2ed = 0xc;
    local_2ea = 0xf3;
    local_2e9 = 0x18;
    local_2e7 = 0x41;
    local_2e5 = 0xfe;
    local_2e1 = 0x89;
    local_2df = 0xf4;
    local_2dd = 0xf4;
    local_2d1 = 0x85;
    local_304 = 0x92;
    local_303 = 7;
    local_301 = 0;
    local_2ff = 0;
    local_2fc = 0xf7;
    local_2fb = 0xef;
    local_2fa = 0;
    local_2f8 = 0;
    local_2f3 = 0;
    local_2f2 = 0;
    local_2f1 = 0;
    local_2f0 = 0;
    local_2ef = 0;
    local_2ee = 0;
    local_2ec = 0xe8;
    local_2e8 = 6;
    local_2e6 = 0;
    local_2e4 = 6;
    local_2e0 = 3;
    local_2de = 3;
    local_2dc = 0;
    local_2da = 7;
    local_2d9 = 0x69;
    local_2d8 = 3;
    local_2d6 = 10;
    local_2d5 = 0xd1;
    local_2d4 = 6;
    local_2d3 = 0xcc;
    local_2d2 = 2;
    local_2d0 = 0;
    local_2cf = 0x97;
    local_2ce = 5;
    local_2cd = 0xad;
    local_2cc = 4;
    local_2c8 = 0xd;
    local_2c5 = 0xb1;
    local_2bd = 0xb8;
    local_2b5 = 0x14;
    local_2b3 = 0x43;
    local_2ba = 0x5c;
    local_2ae = 0xff;
    local_2b2 = 0xe0;
    local_2a5 = 0x96;
    local_2c6 = 6;
    local_2c1 = 0xfd;
    local_2bf = 3;
    local_2b8 = 0x66;
    local_2aa = 3;
    local_299 = 5;
    local_295 = 3;
    local_2cb = 0xfb;
    local_2ca = 7;
    local_2c9 = 0x3b;
    local_2c7 = 0x92;
    local_2c4 = 0;
    local_2c3 = 0;
    local_2c2 = 7;
    local_2c0 = 0;
    local_2be = 0;
    local_2bc = 2;
    local_2bb = 0x8f;
    local_2b9 = 0;
    local_2b7 = 0;
    local_2b6 = 0;
    local_2b4 = 0;
    local_2b1 = 0;
    local_2b0 = 0;
    local_2af = 7;
    local_2ad = 0;
    local_2ac = 0;
    local_2ab = 8;
    local_2a9 = 0x80;
    local_2a8 = 2;
    local_2a7 = 0;
    local_2a6 = 0;
    local_2a4 = 0;
    local_2a3 = 0x1c;
    local_2a2 = 0;
    local_2a1 = 0;
    local_2a0 = 0;
    local_29f = 0xf;
    local_29e = 0xc0;
    local_29d = 0xfc;
    local_29c = 0;
    local_29b = 2;
    local_29a = 0;
    local_298 = 0;
    local_297 = 0;
    local_296 = 0;
    local_294 = 1;
    local_293 = 0x1f;
    local_292 = 0xf;
    local_291 = 0xdc;
    local_290 = 1;
    local_288 = 4;
    local_282 = 5;
    local_281 = 0xc3;
    local_27b = 5;
    local_279 = 0x52;
    local_273 = 0xc;
    local_271 = 0xc;
    local_270 = 0x26;
    local_26e = 0x83;
    local_28f = 0x45;
    local_26d = 6;
    local_284 = 1;
    local_27e = 1;
    local_26b = 2;
    local_27d = 0xea;
    local_266 = 0xe;
    local_26c = 0x3a;
    local_264 = 6;
    local_268 = 0x59;
    local_263 = 0x74;
    local_28a = 2;
    local_287 = 0xe4;
    local_275 = 0x1c;
    local_262 = 5;
    local_261 = 0x76;
    local_28e = 0;
    local_28d = 0;
    local_28c = 0;
    local_28b = 0x8f;
    local_289 = 0xc0;
    local_286 = 0;
    local_285 = 0x85;
    local_283 = 0xf6;
    local_280 = 0;
    local_27f = 0x85;
    local_27c = 0;
    local_27a = 0;
    local_278 = 0;
    local_277 = 0;
    local_276 = 0;
    local_274 = 0;
    local_272 = 0xe8;
    local_26f = 0;
    local_26a = 0x80;
    local_269 = 0xf;
    local_267 = 0;
    local_265 = 0;
    local_260 = 1;
    local_25f = 0x30;
    local_25e = 7;
    local_25d = 0xfb;
    local_25c = 8;
    local_25b = 0;
    local_25a = 7;
    local_259 = 0xf6;
    local_250 = 0xd;
    local_24a = 5;
    local_245 = 0x93;
    local_249 = 0x90;
    local_23c = 5;
    local_246 = 3;
    local_22e = 3;
    local_258 = 7;
    local_254 = 7;
    local_253 = 0xf6;
    local_248 = 7;
    local_23a = 4;
    local_238 = 7;
    local_22c = 4;
    local_22d = 0xd7;
    local_251 = 0x5b;
    local_24d = 0x5b;
    local_242 = 6;
    local_236 = 0xd;
    local_234 = 6;
    local_22b = 0x29;
    local_224 = 0x80;
    local_223 = 0x80;
    local_21e = 0xff;
    local_257 = 0xfb;
    local_256 = 8;
    local_255 = 0;
    local_252 = 0;
    local_24f = 0xad;
    local_24e = 0;
    local_24c = 0;
    local_24b = 8;
    local_247 = 0x69;
    local_244 = 10;
    local_243 = 0xd1;
    local_241 = 0xcc;
    local_240 = 2;
    local_23f = 0x85;
    local_23e = 0;
    local_23d = 0x97;
    local_23b = 0xad;
    local_239 = 0xfb;
    local_237 = 0x3b;
    local_235 = 0x92;
    local_233 = 0xb1;
    local_232 = 0;
    local_231 = 0;
    local_230 = 10;
    local_22f = 0;
    local_22a = 0xfa;
    local_229 = 0;
    local_228 = 0;
    local_227 = 0;
    local_226 = 10;
    local_225 = 2;
    local_222 = 0;
    local_221 = 0;
    local_220 = 0x32;
    local_21f = 7;
    local_21d = 0;
    local_21c = 0;
    local_21b = 0;
    local_21a = 8;
    local_219 = 0xe;
    local_215 = 1;
    local_210 = 0xbb;
    local_1f9 = 1;
    local_1f3 = 1;
    local_1f2 = 0x25;
    local_1ee = 0x4b;
    local_218 = 0xc0;
    local_214 = 0xc0;
    local_213 = 5;
    local_212 = 0xc0;
    local_20f = 0xf;
    local_20e = 0xe8;
    local_20b = 5;
    local_204 = 0xf7;
    local_203 = 7;
    local_1fd = 5;
    local_1fb = 7;
    local_1ef = 0xf;
    local_1e0 = 0x9e;
    local_217 = 0;
    local_216 = 0x32;
    local_211 = 0;
    local_20d = 2;
    local_20c = 0;
    local_20a = 0x80;
    local_209 = 0;
    local_208 = 0;
    local_207 = 0;
    local_206 = 0;
    local_205 = 3;
    local_202 = 0xff;
    local_201 = 2;
    local_200 = 4;
    local_1ff = 0;
    local_1fe = 0;
    local_1fc = 0xfc;
    local_1fa = 0xff;
    local_1f8 = 2;
    local_1f7 = 0;
    local_1f6 = 0;
    local_1f5 = 6;
    local_1f4 = 0xdb;
    local_1f1 = 6;
    local_1f0 = 0x80;
    local_1ed = 7;
    local_1ec = 0xff;
    local_1eb = 7;
    local_1ea = 0xff;
    local_1e9 = 0;
    local_1e8 = 0;
    local_1e7 = 0;
    local_1e6 = 0;
    local_1e5 = 0;
    local_1e4 = 0;
    local_1e3 = 0;
    local_1e2 = 0;
    local_1e1 = 0;
    local_1df = 0xb1;
    local_1de = 0;
    local_1dd = 0;
    local_1dc = 0x10;
    local_1db = 0;
    local_1da = 0;
    local_1d9 = 0;
    local_1d8 = 0;
    local_1d6 = 0xc;
    local_1d3 = 0xc;
    local_1cd = 0x93;
    local_1be = 0xd;
    local_1b7 = 0x20;
    local_1b3 = 0x20;
    local_1ac = 0x18;
    local_1a8 = 0x13;
    local_1a2 = 0x1e;
    local_1cc = 10;
    local_1c1 = 0xfb;
    local_1bf = 0x3b;
    local_1bb = 0xb1;
    local_1ab = 0xdb;
    local_19a = 0x62;
    local_1d7 = 0;
    local_1d5 = 0xcc;
    local_1d4 = 0xcd;
    local_1d2 = 0xcc;
    local_1d1 = 0xcd;
    local_1d0 = 7;
    local_1cf = 0x69;
    local_1ce = 3;
    local_1cb = 0xd1;
    local_1ca = 6;
    local_1c9 = 0xcc;
    local_1c8 = 2;
    local_1c7 = 0x85;
    local_1c6 = 0;
    local_1c5 = 0x97;
    local_1c4 = 5;
    local_1c3 = 0xad;
    local_1c2 = 4;
    local_1c0 = 7;
    local_1bd = 0x92;
    local_1bc = 6;
    local_1ba = 7;
    local_1b9 = 0xff;
    local_1b8 = 0;
    local_1b6 = 0x1f;
    local_1b5 = 0x80;
    local_1b4 = 0;
    local_1b2 = 0x1f;
    local_1b1 = 0x80;
    local_1b0 = 0;
    local_1af = 0;
    local_1ae = 1;
    local_1ad = 3;
    local_1aa = 0;
    local_1a9 = 0;
    local_1a7 = 0;
    local_1a6 = 0xff;
    local_1a5 = 0;
    local_1a4 = 0xff;
    local_1a3 = 0;
    local_1a1 = 0;
    local_1a0 = 200;
    local_19f = 3;
    local_19e = 0x11;
    local_19d = 0x61;
    local_19c = 3;
    local_19b = 0x11;
    local_199 = 3;
    local_198 = 0x11;
    local_197 = 0xe5;
    local_196 = 2;
    local_195 = 0xcd;
    local_183 = 0xca;
    local_194 = 0;
    local_193 = 0;
    local_192 = 0;
    local_191 = 0;
    local_190 = 7;
    local_18f = 0x8f;
    local_18e = 0;
    local_18d = 0;
    local_18c = 5;
    local_18b = 0xb6;
    local_18a = 5;
    local_189 = 0xb6;
    local_188 = 3;
    local_187 = 0xab;
    local_186 = 0;
    local_185 = 0xe;
    local_184 = 5;
    local_182 = 0;
    local_181 = 7;
    local_180 = 0;
    local_17f = 0x80;
    local_17e = 6;
    local_17d = 0x4d;
    local_17c = 0x32;
    local_17b = 1;
    local_17a = 0x97;
    local_179 = 0xe;
    local_178 = 0;
    local_177 = 100;
    local_176 = 0xd3;
    local_175 = 0;
    local_174 = 0x35;
    local_173 = 0xc6;
    local_172 = 0;
    local_171 = 0x80;
    local_170 = 0;
    local_16f = 0;
    local_16e = 0;
    local_16d = 0;
    local_16c = 7;
    local_16b = 0x8f;
    local_16a = 0;
    local_169 = 0;
    local_168 = 5;
    local_167 = 0xb6;
    local_166 = 5;
    local_165 = 0xb6;
    local_164 = 3;
    local_163 = 0xab;
    local_162 = 0;
    local_161 = 0xe;
    local_160 = 3;
    local_15f = 0xab;
    local_15e = 0;
    local_15d = 0xe;
    local_15c = 0;
    local_15b = 0x80;
    local_15a = 6;
    local_159 = 0x4d;
    local_158 = 0x32;
    local_157 = 1;
    local_156 = 0x97;
    local_155 = 0xe;
    local_154 = 0;
    local_153 = 100;
    local_152 = 0xd3;
    local_151 = 0;
    local_150 = 0x35;
    local_14f = 0xc6;
    local_14e = 0;
    local_14d = 0x80;
    local_14c = 0;
    local_14b = 0;
    local_14a = 0;
    local_149 = 0;
    local_148 = 0;
    local_147 = 0;
    memset(auStack_146,0,0x116);
    FUN_00014db0(DAT_000648e4,0xf,0x11,(int)&local_430,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x12,(int)&local_3b0,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x13,(int)&local_330,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x14,(int)&local_2b0,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x15,(int)&local_230,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x16,(int)&local_1b0,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x17,(int)auStack_130,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x18,(int)auStack_b0,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x21,(int)&local_830,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x22,(int)&local_7b0,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x23,(int)&local_730,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x24,(int)&local_6b0,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x25,(int)&local_630,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x26,(int)&local_5b0,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x27,(int)&local_530,0x80,300);
    FUN_00014db0(DAT_000648e4,0xf,0x28,(int)&local_4b0,0x80,300);
  default:
    goto switchD_0004764c_caseD_c;
  case 0xf:
    hWnd = FindWindowW(L"MgrDAB",(LPCWSTR)0x0);
    if (hWnd == (HWND)0x0) goto switchD_0004764c_caseD_c;
    wParam = 0;
    goto LAB_000476e4;
  case 0x10:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_0003f154(puVar1);
    }
    if (puVar1 == (undefined4 *)0x0) goto switchD_0004764c_caseD_c;
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 4);
    break;
  case 0x11:
    hWnd = FindWindowW(L"MgrDAB",(LPCWSTR)0x0);
    if (hWnd == (HWND)0x0) goto switchD_0004764c_caseD_c;
    wParam = 100;
LAB_000476e4:
    PostMessageW(hWnd,DAT_00068680,wParam,0);
    goto switchD_0004764c_caseD_c;
  }
  FUN_00044b7c((int)puVar1,uVar2,uVar3);
switchD_0004764c_caseD_c:
  FUN_0004a3f4(local_30);
  return;
}



/* 00049a20 Unwind@00049a20 */

/* Boundary evidence: original MIPS .pdata 00049a20..00049a4f. Semantic name remains unreviewed. */

void Unwind_00049a20(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049a50 Unwind@00049a50 */

/* Boundary evidence: original MIPS .pdata 00049a50..00049a7f. Semantic name remains unreviewed. */

void Unwind_00049a50(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049a80 Unwind@00049a80 */

/* Boundary evidence: original MIPS .pdata 00049a80..00049aaf. Semantic name remains unreviewed. */

void Unwind_00049a80(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049ab0 Unwind@00049ab0 */

/* Boundary evidence: original MIPS .pdata 00049ab0..00049adf. Semantic name remains unreviewed. */

void Unwind_00049ab0(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049ae0 Unwind@00049ae0 */

/* Boundary evidence: original MIPS .pdata 00049ae0..00049b0f. Semantic name remains unreviewed. */

void Unwind_00049ae0(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049b10 Unwind@00049b10 */

/* Boundary evidence: original MIPS .pdata 00049b10..00049b3f. Semantic name remains unreviewed. */

void Unwind_00049b10(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049b40 Unwind@00049b40 */

/* Boundary evidence: original MIPS .pdata 00049b40..00049b6f. Semantic name remains unreviewed. */

void Unwind_00049b40(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049b70 Unwind@00049b70 */

/* Boundary evidence: original MIPS .pdata 00049b70..00049b9f. Semantic name remains unreviewed. */

void Unwind_00049b70(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049ba0 Unwind@00049ba0 */

/* Boundary evidence: original MIPS .pdata 00049ba0..00049bcf. Semantic name remains unreviewed. */

void Unwind_00049ba0(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00049bd0 FUN_00049bd0 */

/* Boundary evidence: original MIPS .pdata 00049bd0..00049c33. Semantic name remains unreviewed. */

void FUN_00049bd0(int param_1)

{
  KillTimer(*(HWND *)(param_1 + 0xc),1000);
  FUN_00021540(DAT_00064a24);
  FUN_00044acc();
  if (DAT_00068670 != (undefined4 *)0x0) {
    (**(code **)*DAT_00068670)(DAT_00068670,1);
    DAT_00068670 = (undefined4 *)0x0;
  }
  return;
}



/* 00049c34 FUN_00049c34 */

/* Boundary evidence: original MIPS .pdata 00049c34..00049cc7. Semantic name remains unreviewed. */

void FUN_00049c34(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_000450c0();
  if (DAT_00068670 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x28);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00068670 = (undefined4 *)0x0;
    }
    else {
      DAT_00068670 = FUN_00046f38(puVar1);
    }
    FUN_00044b7c((int)DAT_00068670,DAT_00064aac,param_1);
  }
  return;
}



/* 00049cc8 Unwind@00049cc8 */

/* Boundary evidence: original MIPS .pdata 00049cc8..00049cf7. Semantic name remains unreviewed. */

void Unwind_00049cc8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00049cf8 FUN_00049cf8 */

/* Boundary evidence: original MIPS .pdata 00049cf8..00049d4f. Semantic name remains unreviewed. */

undefined4 * FUN_00049cf8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00060aa0;
  FUN_00044b6c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0004a300 FUN_0004a300 */

/* Boundary evidence: original MIPS .pdata 0004a300..0004a373. Semantic name remains unreviewed. */

void FUN_0004a300(void)

{
  uint uVar1;
  
  if ((DAT_00064820 == 0) || (DAT_00064820 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00064820 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00064820 == 0) {
      DAT_00064820 = 0xb064;
    }
  }
  DAT_00064824 = ~DAT_00064820;
  return;
}



/* 0004a374 FUN_0004a374 */

/* Boundary evidence: original MIPS .pdata 0004a374..0004a3c7. Semantic name remains unreviewed. */

void FUN_0004a374(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0004a3f4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0004a3c8 FUN_0004a3c8 */

/* Boundary evidence: original MIPS .pdata 0004a3c8..0004a3f3. Semantic name remains unreviewed. */

undefined4 FUN_0004a3c8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0004a374(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0004a3f4 FUN_0004a3f4 */

/* Boundary evidence: original MIPS .pdata 0004a3f4..0004a43b. Semantic name remains unreviewed. */

void FUN_0004a3f4(uint param_1)

{
  if ((param_1 == DAT_00064820) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0004a62c FUN_0004a62c */

/* Boundary evidence: original MIPS .pdata 0004a62c..0004a69b. Semantic name remains unreviewed. */

void FUN_0004a62c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0004a374(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 0004a6ac FUN_0004a6ac */

/* Boundary evidence: original MIPS .pdata 0004a6ac..0004a7b7. Semantic name remains unreviewed. */

undefined4 FUN_0004a6ac(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_000686a4;
  puVar3 = DAT_000686a0;
  iVar4 = (int)DAT_000686a0 - (int)DAT_000686a4;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_0004a6f0:
    param_1 = 0;
  }
  else {
    if (DAT_000686a4 != (void *)0x0) {
      uVar1 = _msize(DAT_000686a4);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_0004a764:
        if (pvVar2 == (void *)0x0) goto LAB_0004a6f0;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_0004a764;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_000686a0 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_000686a4 = pvVar2;
  }
  return param_1;
}



/* 0004a7b8 FUN_0004a7b8 */

/* Boundary evidence: original MIPS .pdata 0004a7b8..0004a8a3. Semantic name remains unreviewed. */

undefined4 FUN_0004a7b8(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_000686a8 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_000686a8,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_000686a8 == (LPCRITICAL_SECTION)0x0) goto LAB_0004a85c;
  }
  EnterCriticalSection(DAT_000686a8);
LAB_0004a85c:
  uVar2 = FUN_0004a6ac(param_1);
  FUN_0004a8a4();
  return uVar2;
}



/* 0004a8a4 FUN_0004a8a4 */

/* Boundary evidence: original MIPS .pdata 0004a8a4..0004a8ef. Semantic name remains unreviewed. */

void FUN_0004a8a4(void)

{
  if (DAT_000686a8 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_000686a8);
  }
  return;
}



/* 0004a8f0 FUN_0004a8f0 */

/* Boundary evidence: original MIPS .pdata 0004a8f0..0004a91f. Semantic name remains unreviewed. */

undefined4 FUN_0004a8f0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0004a7b8(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0004aa60 FUN_0004aa60 */

/* Boundary evidence: original MIPS .pdata 0004aa60..0004aaf3. Semantic name remains unreviewed. */

void FUN_0004aa60(HINSTANCE param_1)

{
  WPARAM WVar1;
  
  FUN_0004add0();
  WVar1 = FUN_00027e94(param_1);
  FUN_0004ad10(WVar1);
  FUN_0004ad30(WVar1);
  return;
}



/* 0004aaf4 FUN_0004aaf4 */

/* Boundary evidence: original MIPS .pdata 0004aaf4..0004ab33. Semantic name remains unreviewed. */

void FUN_0004aaf4(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 0004ab34 entry */

/* Boundary evidence: original MIPS .pdata 0004ab34..0004ab8f. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1)

{
  FUN_0004a300();
  FUN_0004aa60(param_1);
  return;
}



/* 0004abf0 FUN_0004abf0 */

/* Boundary evidence: original MIPS .pdata 0004abf0..0004ad0f. Semantic name remains unreviewed. */

void FUN_0004abf0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0006869c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000686a4;
    if (DAT_000686a4 != (undefined4 *)0x0) {
      while (DAT_000686a0 = DAT_000686a0 + -1, _Memory <= DAT_000686a0) {
        if ((code *)*DAT_000686a0 != (code *)0x0) {
          (*(code *)*DAT_000686a0)();
          _Memory = DAT_000686a4;
        }
      }
      free(_Memory);
      DAT_000686a0 = (undefined4 *)0x0;
      DAT_000686a4 = (undefined4 *)0x0;
    }
    FUN_0004ad7c((undefined4 *)&DAT_0004e464,(undefined4 *)&DAT_0004e468);
  }
  FUN_0004ad7c((undefined4 *)&DAT_0004e46c,(undefined4 *)&DAT_0004e470);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_000686a8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 0004ad10 FUN_0004ad10 */

/* Boundary evidence: original MIPS .pdata 0004ad10..0004ad2f. Semantic name remains unreviewed. */

void FUN_0004ad10(UINT param_1)

{
  FUN_0004abf0(param_1,0,0);
  return;
}



/* 0004ad30 FUN_0004ad30 */

/* Boundary evidence: original MIPS .pdata 0004ad30..0004ad7b. Semantic name remains unreviewed. */

void FUN_0004ad30(UINT param_1)

{
  DAT_0006869c = 0;
  FUN_0004ad7c((undefined4 *)&DAT_0004e46c,(undefined4 *)&DAT_0004e470);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 0004ad7c FUN_0004ad7c */

/* Boundary evidence: original MIPS .pdata 0004ad7c..0004adcf. Semantic name remains unreviewed. */

void FUN_0004ad7c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0004add0 FUN_0004add0 */

/* Boundary evidence: original MIPS .pdata 0004add0..0004ae0b. Semantic name remains unreviewed. */

void FUN_0004add0(void)

{
  FUN_0004ad7c((undefined4 *)&DAT_0004e45c,(undefined4 *)&DAT_0004e460);
  FUN_0004ad7c((undefined4 *)&DAT_0004e000,(undefined4 *)&DAT_0004e458);
  return;
}



/* 0004ae3c FUN_0004ae3c */

/* Boundary evidence: original MIPS .pdata 0004ae3c..0004ae63. Semantic name remains unreviewed. */

void FUN_0004ae3c(void)

{
  DAT_00064830 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004ae64 FUN_0004ae64 */

/* Boundary evidence: original MIPS .pdata 0004ae64..0004ae8b. Semantic name remains unreviewed. */

void FUN_0004ae64(void)

{
  DAT_00064834 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004ae8c FUN_0004ae8c */

/* Boundary evidence: original MIPS .pdata 0004ae8c..0004aeb3. Semantic name remains unreviewed. */

void FUN_0004ae8c(void)

{
  DAT_00064838 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004aeb4 FUN_0004aeb4 */

/* Boundary evidence: original MIPS .pdata 0004aeb4..0004aedb. Semantic name remains unreviewed. */

void FUN_0004aeb4(void)

{
  DAT_0006483c = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004aedc FUN_0004aedc */

/* Boundary evidence: original MIPS .pdata 0004aedc..0004af03. Semantic name remains unreviewed. */

void FUN_0004aedc(void)

{
  DAT_00064840 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004af04 FUN_0004af04 */

/* Boundary evidence: original MIPS .pdata 0004af04..0004af2b. Semantic name remains unreviewed. */

void FUN_0004af04(void)

{
  DAT_00064844 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004af2c FUN_0004af2c */

/* Boundary evidence: original MIPS .pdata 0004af2c..0004af53. Semantic name remains unreviewed. */

void FUN_0004af2c(void)

{
  DAT_00064848 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004af54 FUN_0004af54 */

/* Boundary evidence: original MIPS .pdata 0004af54..0004af7b. Semantic name remains unreviewed. */

void FUN_0004af54(void)

{
  DAT_0006484c = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004af7c FUN_0004af7c */

/* Boundary evidence: original MIPS .pdata 0004af7c..0004afa3. Semantic name remains unreviewed. */

void FUN_0004af7c(void)

{
  DAT_00064850 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004afa4 FUN_0004afa4 */

/* Boundary evidence: original MIPS .pdata 0004afa4..0004afcb. Semantic name remains unreviewed. */

void FUN_0004afa4(void)

{
  DAT_00064854 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004afcc FUN_0004afcc */

/* Boundary evidence: original MIPS .pdata 0004afcc..0004aff3. Semantic name remains unreviewed. */

void FUN_0004afcc(void)

{
  DAT_00064858 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004aff4 FUN_0004aff4 */

/* Boundary evidence: original MIPS .pdata 0004aff4..0004b01b. Semantic name remains unreviewed. */

void FUN_0004aff4(void)

{
  DAT_0006485c = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004b01c FUN_0004b01c */

/* Boundary evidence: original MIPS .pdata 0004b01c..0004b043. Semantic name remains unreviewed. */

void FUN_0004b01c(void)

{
  DAT_00064860 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004b044 FUN_0004b044 */

/* Boundary evidence: original MIPS .pdata 0004b044..0004b06b. Semantic name remains unreviewed. */

void FUN_0004b044(void)

{
  DAT_00064864 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004b06c FUN_0004b06c */

/* Boundary evidence: original MIPS .pdata 0004b06c..0004b093. Semantic name remains unreviewed. */

void FUN_0004b06c(void)

{
  DAT_00064868 = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004b094 FUN_0004b094 */

/* Boundary evidence: original MIPS .pdata 0004b094..0004b0bb. Semantic name remains unreviewed. */

void FUN_0004b094(void)

{
  DAT_0006486c = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004b0bc FUN_0004b0bc */

/* Boundary evidence: original MIPS .pdata 0004b0bc..0004b0e3. Semantic name remains unreviewed. */

void FUN_0004b0bc(void)

{
  DAT_00064870 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004b0e4 FUN_0004b0e4 */

/* Boundary evidence: original MIPS .pdata 0004b0e4..0004b10b. Semantic name remains unreviewed. */

void FUN_0004b0e4(void)

{
  DAT_00064874 = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004b10c FUN_0004b10c */

/* Boundary evidence: original MIPS .pdata 0004b10c..0004b133. Semantic name remains unreviewed. */

void FUN_0004b10c(void)

{
  DAT_00064878 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004b134 FUN_0004b134 */

/* Boundary evidence: original MIPS .pdata 0004b134..0004b15b. Semantic name remains unreviewed. */

void FUN_0004b134(void)

{
  DAT_00064898 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004b15c FUN_0004b15c */

/* Boundary evidence: original MIPS .pdata 0004b15c..0004b183. Semantic name remains unreviewed. */

void FUN_0004b15c(void)

{
  DAT_0006489c = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004b184 FUN_0004b184 */

/* Boundary evidence: original MIPS .pdata 0004b184..0004b1ab. Semantic name remains unreviewed. */

void FUN_0004b184(void)

{
  DAT_000648a0 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004b1ac FUN_0004b1ac */

/* Boundary evidence: original MIPS .pdata 0004b1ac..0004b1d3. Semantic name remains unreviewed. */

void FUN_0004b1ac(void)

{
  DAT_000648a4 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004b1d4 FUN_0004b1d4 */

/* Boundary evidence: original MIPS .pdata 0004b1d4..0004b1fb. Semantic name remains unreviewed. */

void FUN_0004b1d4(void)

{
  DAT_000648a8 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004b1fc FUN_0004b1fc */

/* Boundary evidence: original MIPS .pdata 0004b1fc..0004b223. Semantic name remains unreviewed. */

void FUN_0004b1fc(void)

{
  DAT_000648ac = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004b224 FUN_0004b224 */

/* Boundary evidence: original MIPS .pdata 0004b224..0004b24b. Semantic name remains unreviewed. */

void FUN_0004b224(void)

{
  DAT_000648b0 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004b24c FUN_0004b24c */

/* Boundary evidence: original MIPS .pdata 0004b24c..0004b273. Semantic name remains unreviewed. */

void FUN_0004b24c(void)

{
  DAT_000648b4 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004b274 FUN_0004b274 */

/* Boundary evidence: original MIPS .pdata 0004b274..0004b29b. Semantic name remains unreviewed. */

void FUN_0004b274(void)

{
  DAT_000648b8 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004b29c FUN_0004b29c */

/* Boundary evidence: original MIPS .pdata 0004b29c..0004b2c3. Semantic name remains unreviewed. */

void FUN_0004b29c(void)

{
  DAT_000648bc = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004b2c4 FUN_0004b2c4 */

/* Boundary evidence: original MIPS .pdata 0004b2c4..0004b2eb. Semantic name remains unreviewed. */

void FUN_0004b2c4(void)

{
  DAT_000648c0 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004b2ec FUN_0004b2ec */

/* Boundary evidence: original MIPS .pdata 0004b2ec..0004b313. Semantic name remains unreviewed. */

void FUN_0004b2ec(void)

{
  DAT_000648c4 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004b314 FUN_0004b314 */

/* Boundary evidence: original MIPS .pdata 0004b314..0004b33b. Semantic name remains unreviewed. */

void FUN_0004b314(void)

{
  DAT_000648c8 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004b33c FUN_0004b33c */

/* Boundary evidence: original MIPS .pdata 0004b33c..0004b363. Semantic name remains unreviewed. */

void FUN_0004b33c(void)

{
  DAT_000648cc = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004b364 FUN_0004b364 */

/* Boundary evidence: original MIPS .pdata 0004b364..0004b38b. Semantic name remains unreviewed. */

void FUN_0004b364(void)

{
  DAT_000648d0 = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004b38c FUN_0004b38c */

/* Boundary evidence: original MIPS .pdata 0004b38c..0004b3b3. Semantic name remains unreviewed. */

void FUN_0004b38c(void)

{
  DAT_000648d4 = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004b3b4 FUN_0004b3b4 */

/* Boundary evidence: original MIPS .pdata 0004b3b4..0004b3db. Semantic name remains unreviewed. */

void FUN_0004b3b4(void)

{
  DAT_000648d8 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004b3dc FUN_0004b3dc */

/* Boundary evidence: original MIPS .pdata 0004b3dc..0004b403. Semantic name remains unreviewed. */

void FUN_0004b3dc(void)

{
  DAT_000648dc = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004b404 FUN_0004b404 */

/* Boundary evidence: original MIPS .pdata 0004b404..0004b42b. Semantic name remains unreviewed. */

void FUN_0004b404(void)

{
  DAT_000648e0 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004b42c FUN_0004b42c */

/* Boundary evidence: original MIPS .pdata 0004b42c..0004b453. Semantic name remains unreviewed. */

void FUN_0004b42c(void)

{
  DAT_000648f8 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004b454 FUN_0004b454 */

/* Boundary evidence: original MIPS .pdata 0004b454..0004b47b. Semantic name remains unreviewed. */

void FUN_0004b454(void)

{
  DAT_000648fc = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004b47c FUN_0004b47c */

/* Boundary evidence: original MIPS .pdata 0004b47c..0004b4a3. Semantic name remains unreviewed. */

void FUN_0004b47c(void)

{
  DAT_00064900 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004b4a4 FUN_0004b4a4 */

/* Boundary evidence: original MIPS .pdata 0004b4a4..0004b4cb. Semantic name remains unreviewed. */

void FUN_0004b4a4(void)

{
  DAT_00064904 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004b4cc FUN_0004b4cc */

/* Boundary evidence: original MIPS .pdata 0004b4cc..0004b4f3. Semantic name remains unreviewed. */

void FUN_0004b4cc(void)

{
  DAT_00064908 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004b4f4 FUN_0004b4f4 */

/* Boundary evidence: original MIPS .pdata 0004b4f4..0004b51b. Semantic name remains unreviewed. */

void FUN_0004b4f4(void)

{
  DAT_0006490c = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004b51c FUN_0004b51c */

/* Boundary evidence: original MIPS .pdata 0004b51c..0004b543. Semantic name remains unreviewed. */

void FUN_0004b51c(void)

{
  DAT_00064910 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004b544 FUN_0004b544 */

/* Boundary evidence: original MIPS .pdata 0004b544..0004b56b. Semantic name remains unreviewed. */

void FUN_0004b544(void)

{
  DAT_00064914 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004b56c FUN_0004b56c */

/* Boundary evidence: original MIPS .pdata 0004b56c..0004b593. Semantic name remains unreviewed. */

void FUN_0004b56c(void)

{
  DAT_00064918 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004b594 FUN_0004b594 */

/* Boundary evidence: original MIPS .pdata 0004b594..0004b5bb. Semantic name remains unreviewed. */

void FUN_0004b594(void)

{
  DAT_0006491c = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004b5bc FUN_0004b5bc */

/* Boundary evidence: original MIPS .pdata 0004b5bc..0004b5e3. Semantic name remains unreviewed. */

void FUN_0004b5bc(void)

{
  DAT_00064920 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004b5e4 FUN_0004b5e4 */

/* Boundary evidence: original MIPS .pdata 0004b5e4..0004b60b. Semantic name remains unreviewed. */

void FUN_0004b5e4(void)

{
  DAT_00064924 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004b60c FUN_0004b60c */

/* Boundary evidence: original MIPS .pdata 0004b60c..0004b633. Semantic name remains unreviewed. */

void FUN_0004b60c(void)

{
  DAT_00064928 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004b634 FUN_0004b634 */

/* Boundary evidence: original MIPS .pdata 0004b634..0004b65b. Semantic name remains unreviewed. */

void FUN_0004b634(void)

{
  DAT_0006492c = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004b65c FUN_0004b65c */

/* Boundary evidence: original MIPS .pdata 0004b65c..0004b683. Semantic name remains unreviewed. */

void FUN_0004b65c(void)

{
  DAT_00064930 = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004b684 FUN_0004b684 */

/* Boundary evidence: original MIPS .pdata 0004b684..0004b6ab. Semantic name remains unreviewed. */

void FUN_0004b684(void)

{
  DAT_00064934 = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004b6ac FUN_0004b6ac */

/* Boundary evidence: original MIPS .pdata 0004b6ac..0004b6d3. Semantic name remains unreviewed. */

void FUN_0004b6ac(void)

{
  DAT_00064938 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004b6d4 FUN_0004b6d4 */

/* Boundary evidence: original MIPS .pdata 0004b6d4..0004b6fb. Semantic name remains unreviewed. */

void FUN_0004b6d4(void)

{
  DAT_0006493c = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004b6fc FUN_0004b6fc */

/* Boundary evidence: original MIPS .pdata 0004b6fc..0004b723. Semantic name remains unreviewed. */

void FUN_0004b6fc(void)

{
  DAT_00064940 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004b724 FUN_0004b724 */

/* Boundary evidence: original MIPS .pdata 0004b724..0004b74b. Semantic name remains unreviewed. */

void FUN_0004b724(void)

{
  DAT_000649c4 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004b74c FUN_0004b74c */

/* Boundary evidence: original MIPS .pdata 0004b74c..0004b773. Semantic name remains unreviewed. */

void FUN_0004b74c(void)

{
  DAT_000649c8 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004b774 FUN_0004b774 */

/* Boundary evidence: original MIPS .pdata 0004b774..0004b79b. Semantic name remains unreviewed. */

void FUN_0004b774(void)

{
  DAT_000649cc = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004b79c FUN_0004b79c */

/* Boundary evidence: original MIPS .pdata 0004b79c..0004b7c3. Semantic name remains unreviewed. */

void FUN_0004b79c(void)

{
  DAT_000649d0 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004b7c4 FUN_0004b7c4 */

/* Boundary evidence: original MIPS .pdata 0004b7c4..0004b7eb. Semantic name remains unreviewed. */

void FUN_0004b7c4(void)

{
  DAT_000649d4 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004b7ec FUN_0004b7ec */

/* Boundary evidence: original MIPS .pdata 0004b7ec..0004b813. Semantic name remains unreviewed. */

void FUN_0004b7ec(void)

{
  DAT_000649d8 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004b814 FUN_0004b814 */

/* Boundary evidence: original MIPS .pdata 0004b814..0004b83b. Semantic name remains unreviewed. */

void FUN_0004b814(void)

{
  DAT_000649dc = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004b83c FUN_0004b83c */

/* Boundary evidence: original MIPS .pdata 0004b83c..0004b863. Semantic name remains unreviewed. */

void FUN_0004b83c(void)

{
  DAT_000649e0 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004b864 FUN_0004b864 */

/* Boundary evidence: original MIPS .pdata 0004b864..0004b88b. Semantic name remains unreviewed. */

void FUN_0004b864(void)

{
  DAT_000649e4 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004b88c FUN_0004b88c */

/* Boundary evidence: original MIPS .pdata 0004b88c..0004b8b3. Semantic name remains unreviewed. */

void FUN_0004b88c(void)

{
  DAT_000649e8 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004b8b4 FUN_0004b8b4 */

/* Boundary evidence: original MIPS .pdata 0004b8b4..0004b8db. Semantic name remains unreviewed. */

void FUN_0004b8b4(void)

{
  DAT_000649ec = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004b8dc FUN_0004b8dc */

/* Boundary evidence: original MIPS .pdata 0004b8dc..0004b903. Semantic name remains unreviewed. */

void FUN_0004b8dc(void)

{
  DAT_000649f0 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004b904 FUN_0004b904 */

/* Boundary evidence: original MIPS .pdata 0004b904..0004b92b. Semantic name remains unreviewed. */

void FUN_0004b904(void)

{
  DAT_000649f4 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004b92c FUN_0004b92c */

/* Boundary evidence: original MIPS .pdata 0004b92c..0004b953. Semantic name remains unreviewed. */

void FUN_0004b92c(void)

{
  DAT_000649f8 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004b954 FUN_0004b954 */

/* Boundary evidence: original MIPS .pdata 0004b954..0004b97b. Semantic name remains unreviewed. */

void FUN_0004b954(void)

{
  DAT_000649fc = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004b97c FUN_0004b97c */

/* Boundary evidence: original MIPS .pdata 0004b97c..0004b9a3. Semantic name remains unreviewed. */

void FUN_0004b97c(void)

{
  DAT_00064a00 = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004b9a4 FUN_0004b9a4 */

/* Boundary evidence: original MIPS .pdata 0004b9a4..0004b9cb. Semantic name remains unreviewed. */

void FUN_0004b9a4(void)

{
  DAT_00064a04 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004b9cc FUN_0004b9cc */

/* Boundary evidence: original MIPS .pdata 0004b9cc..0004b9f3. Semantic name remains unreviewed. */

void FUN_0004b9cc(void)

{
  DAT_00064a08 = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004b9f4 FUN_0004b9f4 */

/* Boundary evidence: original MIPS .pdata 0004b9f4..0004ba1b. Semantic name remains unreviewed. */

void FUN_0004b9f4(void)

{
  DAT_00064a0c = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004ba1c FUN_0004ba1c */

/* Boundary evidence: original MIPS .pdata 0004ba1c..0004ba43. Semantic name remains unreviewed. */

void FUN_0004ba1c(void)

{
  DAT_00064a30 = RegisterWindowMessageW(L"DAB FACTORY RESPONSE");
  return;
}



/* 0004ba44 FUN_0004ba44 */

/* Boundary evidence: original MIPS .pdata 0004ba44..0004ba6b. Semantic name remains unreviewed. */

void FUN_0004ba44(void)

{
  DAT_00064a34 = RegisterWindowMessageW(L"DAB FACTORY RECEIVE");
  return;
}



/* 0004ba6c FUN_0004ba6c */

/* Boundary evidence: original MIPS .pdata 0004ba6c..0004ba93. Semantic name remains unreviewed. */

void FUN_0004ba6c(void)

{
  DAT_00064a38 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004ba94 FUN_0004ba94 */

/* Boundary evidence: original MIPS .pdata 0004ba94..0004babb. Semantic name remains unreviewed. */

void FUN_0004ba94(void)

{
  DAT_00064a3c = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004babc FUN_0004babc */

/* Boundary evidence: original MIPS .pdata 0004babc..0004bae3. Semantic name remains unreviewed. */

void FUN_0004babc(void)

{
  DAT_00064a40 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004bae4 FUN_0004bae4 */

/* Boundary evidence: original MIPS .pdata 0004bae4..0004bb0b. Semantic name remains unreviewed. */

void FUN_0004bae4(void)

{
  DAT_00064a44 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004bb0c FUN_0004bb0c */

/* Boundary evidence: original MIPS .pdata 0004bb0c..0004bb33. Semantic name remains unreviewed. */

void FUN_0004bb0c(void)

{
  DAT_00064a48 = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004bb34 FUN_0004bb34 */

/* Boundary evidence: original MIPS .pdata 0004bb34..0004bb5b. Semantic name remains unreviewed. */

void FUN_0004bb34(void)

{
  DAT_00064a4c = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004bb5c FUN_0004bb5c */

/* Boundary evidence: original MIPS .pdata 0004bb5c..0004bb83. Semantic name remains unreviewed. */

void FUN_0004bb5c(void)

{
  DAT_00064a50 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004bb84 FUN_0004bb84 */

/* Boundary evidence: original MIPS .pdata 0004bb84..0004bbab. Semantic name remains unreviewed. */

void FUN_0004bb84(void)

{
  DAT_00064a54 = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004bbac FUN_0004bbac */

/* Boundary evidence: original MIPS .pdata 0004bbac..0004bbd3. Semantic name remains unreviewed. */

void FUN_0004bbac(void)

{
  DAT_00064a58 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004bbd4 FUN_0004bbd4 */

/* Boundary evidence: original MIPS .pdata 0004bbd4..0004bbfb. Semantic name remains unreviewed. */

void FUN_0004bbd4(void)

{
  DAT_00064a5c = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004bbfc FUN_0004bbfc */

/* Boundary evidence: original MIPS .pdata 0004bbfc..0004bc23. Semantic name remains unreviewed. */

void FUN_0004bbfc(void)

{
  DAT_00064a60 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004bc24 FUN_0004bc24 */

/* Boundary evidence: original MIPS .pdata 0004bc24..0004bc4b. Semantic name remains unreviewed. */

void FUN_0004bc24(void)

{
  DAT_00064a64 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004bc4c FUN_0004bc4c */

/* Boundary evidence: original MIPS .pdata 0004bc4c..0004bc73. Semantic name remains unreviewed. */

void FUN_0004bc4c(void)

{
  DAT_00064a68 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004bc74 FUN_0004bc74 */

/* Boundary evidence: original MIPS .pdata 0004bc74..0004bc9b. Semantic name remains unreviewed. */

void FUN_0004bc74(void)

{
  DAT_00064a6c = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004bc9c FUN_0004bc9c */

/* Boundary evidence: original MIPS .pdata 0004bc9c..0004bcc3. Semantic name remains unreviewed. */

void FUN_0004bc9c(void)

{
  DAT_00064a70 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004bcc4 FUN_0004bcc4 */

/* Boundary evidence: original MIPS .pdata 0004bcc4..0004bceb. Semantic name remains unreviewed. */

void FUN_0004bcc4(void)

{
  DAT_00064a74 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004bcec FUN_0004bcec */

/* Boundary evidence: original MIPS .pdata 0004bcec..0004bd13. Semantic name remains unreviewed. */

void FUN_0004bcec(void)

{
  DAT_00064a78 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004bd14 FUN_0004bd14 */

/* Boundary evidence: original MIPS .pdata 0004bd14..0004bd3b. Semantic name remains unreviewed. */

void FUN_0004bd14(void)

{
  DAT_00064a7c = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004bd3c FUN_0004bd3c */

/* Boundary evidence: original MIPS .pdata 0004bd3c..0004bd63. Semantic name remains unreviewed. */

void FUN_0004bd3c(void)

{
  DAT_00064a80 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004bd64 FUN_0004bd64 */

/* Boundary evidence: original MIPS .pdata 0004bd64..0004bd8b. Semantic name remains unreviewed. */

void FUN_0004bd64(void)

{
  DAT_00064af0 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004bd8c FUN_0004bd8c */

/* Boundary evidence: original MIPS .pdata 0004bd8c..0004bdb3. Semantic name remains unreviewed. */

void FUN_0004bd8c(void)

{
  DAT_00064af4 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004bdb4 FUN_0004bdb4 */

/* Boundary evidence: original MIPS .pdata 0004bdb4..0004bddb. Semantic name remains unreviewed. */

void FUN_0004bdb4(void)

{
  DAT_00064af8 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004bddc FUN_0004bddc */

/* Boundary evidence: original MIPS .pdata 0004bddc..0004be03. Semantic name remains unreviewed. */

void FUN_0004bddc(void)

{
  DAT_00064afc = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004be04 FUN_0004be04 */

/* Boundary evidence: original MIPS .pdata 0004be04..0004be2b. Semantic name remains unreviewed. */

void FUN_0004be04(void)

{
  DAT_00064b00 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004be2c FUN_0004be2c */

/* Boundary evidence: original MIPS .pdata 0004be2c..0004be53. Semantic name remains unreviewed. */

void FUN_0004be2c(void)

{
  DAT_00064b04 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004be54 FUN_0004be54 */

/* Boundary evidence: original MIPS .pdata 0004be54..0004be7b. Semantic name remains unreviewed. */

void FUN_0004be54(void)

{
  DAT_00064b08 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004be7c FUN_0004be7c */

/* Boundary evidence: original MIPS .pdata 0004be7c..0004bea3. Semantic name remains unreviewed. */

void FUN_0004be7c(void)

{
  DAT_00064b0c = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004bea4 FUN_0004bea4 */

/* Boundary evidence: original MIPS .pdata 0004bea4..0004becb. Semantic name remains unreviewed. */

void FUN_0004bea4(void)

{
  DAT_00064b10 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004becc FUN_0004becc */

/* Boundary evidence: original MIPS .pdata 0004becc..0004bef3. Semantic name remains unreviewed. */

void FUN_0004becc(void)

{
  DAT_00064b14 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004bef4 FUN_0004bef4 */

/* Boundary evidence: original MIPS .pdata 0004bef4..0004bf1b. Semantic name remains unreviewed. */

void FUN_0004bef4(void)

{
  DAT_00064b18 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004bf1c FUN_0004bf1c */

/* Boundary evidence: original MIPS .pdata 0004bf1c..0004bf43. Semantic name remains unreviewed. */

void FUN_0004bf1c(void)

{
  DAT_00064b1c = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004bf44 FUN_0004bf44 */

/* Boundary evidence: original MIPS .pdata 0004bf44..0004bf6b. Semantic name remains unreviewed. */

void FUN_0004bf44(void)

{
  DAT_00064b20 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004bf6c FUN_0004bf6c */

/* Boundary evidence: original MIPS .pdata 0004bf6c..0004bf93. Semantic name remains unreviewed. */

void FUN_0004bf6c(void)

{
  DAT_00064b24 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004bf94 FUN_0004bf94 */

/* Boundary evidence: original MIPS .pdata 0004bf94..0004bfbb. Semantic name remains unreviewed. */

void FUN_0004bf94(void)

{
  DAT_00064b28 = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004bfbc FUN_0004bfbc */

/* Boundary evidence: original MIPS .pdata 0004bfbc..0004bfe3. Semantic name remains unreviewed. */

void FUN_0004bfbc(void)

{
  DAT_00064b2c = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004bfe4 FUN_0004bfe4 */

/* Boundary evidence: original MIPS .pdata 0004bfe4..0004c00b. Semantic name remains unreviewed. */

void FUN_0004bfe4(void)

{
  DAT_00064b30 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004c00c FUN_0004c00c */

/* Boundary evidence: original MIPS .pdata 0004c00c..0004c033. Semantic name remains unreviewed. */

void FUN_0004c00c(void)

{
  DAT_00064b34 = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004c034 FUN_0004c034 */

/* Boundary evidence: original MIPS .pdata 0004c034..0004c05b. Semantic name remains unreviewed. */

void FUN_0004c034(void)

{
  DAT_00064b38 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004c05c FUN_0004c05c */

/* Boundary evidence: original MIPS .pdata 0004c05c..0004c083. Semantic name remains unreviewed. */

void FUN_0004c05c(void)

{
  DAT_00064b3c = RegisterWindowMessageW(L"DAB FACTORY RESPONSE");
  return;
}



/* 0004c084 FUN_0004c084 */

/* Boundary evidence: original MIPS .pdata 0004c084..0004c0ab. Semantic name remains unreviewed. */

void FUN_0004c084(void)

{
  DAT_00064b40 = RegisterWindowMessageW(L"DAB FACTORY RECEIVE");
  return;
}



/* 0004c0ac FUN_0004c0ac */

/* Boundary evidence: original MIPS .pdata 0004c0ac..0004c0d7. Semantic name remains unreviewed. */

void FUN_0004c0ac(void)

{
  FUN_000281d0((undefined4 *)&DAT_00064b44);
  FUN_0004a8f0(FUN_0004d98c);
  return;
}



/* 0004c0d8 FUN_0004c0d8 */

/* Boundary evidence: original MIPS .pdata 0004c0d8..0004c103. Semantic name remains unreviewed. */

void FUN_0004c0d8(void)

{
  FUN_000289c8((undefined4 *)&DAT_00064be8);
  FUN_0004a8f0(FUN_0004d9ac);
  return;
}



/* 0004c104 FUN_0004c104 */

/* Boundary evidence: original MIPS .pdata 0004c104..0004c12b. Semantic name remains unreviewed. */

void FUN_0004c104(void)

{
  DAT_000673cc = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004c12c FUN_0004c12c */

/* Boundary evidence: original MIPS .pdata 0004c12c..0004c153. Semantic name remains unreviewed. */

void FUN_0004c12c(void)

{
  DAT_000673d0 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004c154 FUN_0004c154 */

/* Boundary evidence: original MIPS .pdata 0004c154..0004c17b. Semantic name remains unreviewed. */

void FUN_0004c154(void)

{
  DAT_000673d4 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004c17c FUN_0004c17c */

/* Boundary evidence: original MIPS .pdata 0004c17c..0004c1a3. Semantic name remains unreviewed. */

void FUN_0004c17c(void)

{
  DAT_000673d8 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004c1a4 FUN_0004c1a4 */

/* Boundary evidence: original MIPS .pdata 0004c1a4..0004c1cb. Semantic name remains unreviewed. */

void FUN_0004c1a4(void)

{
  DAT_000673dc = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004c1cc FUN_0004c1cc */

/* Boundary evidence: original MIPS .pdata 0004c1cc..0004c1f3. Semantic name remains unreviewed. */

void FUN_0004c1cc(void)

{
  DAT_000673e0 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004c1f4 FUN_0004c1f4 */

/* Boundary evidence: original MIPS .pdata 0004c1f4..0004c21b. Semantic name remains unreviewed. */

void FUN_0004c1f4(void)

{
  DAT_000673e4 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004c21c FUN_0004c21c */

/* Boundary evidence: original MIPS .pdata 0004c21c..0004c243. Semantic name remains unreviewed. */

void FUN_0004c21c(void)

{
  DAT_000673e8 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004c244 FUN_0004c244 */

/* Boundary evidence: original MIPS .pdata 0004c244..0004c26b. Semantic name remains unreviewed. */

void FUN_0004c244(void)

{
  DAT_000673ec = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004c26c FUN_0004c26c */

/* Boundary evidence: original MIPS .pdata 0004c26c..0004c293. Semantic name remains unreviewed. */

void FUN_0004c26c(void)

{
  DAT_000673f0 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004c294 FUN_0004c294 */

/* Boundary evidence: original MIPS .pdata 0004c294..0004c2bb. Semantic name remains unreviewed. */

void FUN_0004c294(void)

{
  DAT_000673f8 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004c2bc FUN_0004c2bc */

/* Boundary evidence: original MIPS .pdata 0004c2bc..0004c2e3. Semantic name remains unreviewed. */

void FUN_0004c2bc(void)

{
  DAT_000673fc = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004c2e4 FUN_0004c2e4 */

/* Boundary evidence: original MIPS .pdata 0004c2e4..0004c30b. Semantic name remains unreviewed. */

void FUN_0004c2e4(void)

{
  DAT_00067400 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004c30c FUN_0004c30c */

/* Boundary evidence: original MIPS .pdata 0004c30c..0004c333. Semantic name remains unreviewed. */

void FUN_0004c30c(void)

{
  DAT_00067404 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004c334 FUN_0004c334 */

/* Boundary evidence: original MIPS .pdata 0004c334..0004c35b. Semantic name remains unreviewed. */

void FUN_0004c334(void)

{
  DAT_00067408 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004c35c FUN_0004c35c */

/* Boundary evidence: original MIPS .pdata 0004c35c..0004c383. Semantic name remains unreviewed. */

void FUN_0004c35c(void)

{
  DAT_0006740c = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004c384 FUN_0004c384 */

/* Boundary evidence: original MIPS .pdata 0004c384..0004c3ab. Semantic name remains unreviewed. */

void FUN_0004c384(void)

{
  DAT_00067410 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004c3ac FUN_0004c3ac */

/* Boundary evidence: original MIPS .pdata 0004c3ac..0004c3d3. Semantic name remains unreviewed. */

void FUN_0004c3ac(void)

{
  DAT_00067414 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004c3d4 FUN_0004c3d4 */

/* Boundary evidence: original MIPS .pdata 0004c3d4..0004c3fb. Semantic name remains unreviewed. */

void FUN_0004c3d4(void)

{
  DAT_00067418 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004c3fc FUN_0004c3fc */

/* Boundary evidence: original MIPS .pdata 0004c3fc..0004c423. Semantic name remains unreviewed. */

void FUN_0004c3fc(void)

{
  DAT_0006741c = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004c424 FUN_0004c424 */

/* Boundary evidence: original MIPS .pdata 0004c424..0004c44b. Semantic name remains unreviewed. */

void FUN_0004c424(void)

{
  DAT_00067420 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004c44c FUN_0004c44c */

/* Boundary evidence: original MIPS .pdata 0004c44c..0004c473. Semantic name remains unreviewed. */

void FUN_0004c44c(void)

{
  DAT_00067424 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004c474 FUN_0004c474 */

/* Boundary evidence: original MIPS .pdata 0004c474..0004c49b. Semantic name remains unreviewed. */

void FUN_0004c474(void)

{
  DAT_00067428 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004c49c FUN_0004c49c */

/* Boundary evidence: original MIPS .pdata 0004c49c..0004c4c3. Semantic name remains unreviewed. */

void FUN_0004c49c(void)

{
  DAT_0006742c = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004c4c4 FUN_0004c4c4 */

/* Boundary evidence: original MIPS .pdata 0004c4c4..0004c4eb. Semantic name remains unreviewed. */

void FUN_0004c4c4(void)

{
  DAT_00067430 = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004c4ec FUN_0004c4ec */

/* Boundary evidence: original MIPS .pdata 0004c4ec..0004c513. Semantic name remains unreviewed. */

void FUN_0004c4ec(void)

{
  DAT_00067434 = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004c514 FUN_0004c514 */

/* Boundary evidence: original MIPS .pdata 0004c514..0004c53b. Semantic name remains unreviewed. */

void FUN_0004c514(void)

{
  DAT_00067438 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004c53c FUN_0004c53c */

/* Boundary evidence: original MIPS .pdata 0004c53c..0004c563. Semantic name remains unreviewed. */

void FUN_0004c53c(void)

{
  DAT_0006743c = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004c564 FUN_0004c564 */

/* Boundary evidence: original MIPS .pdata 0004c564..0004c58b. Semantic name remains unreviewed. */

void FUN_0004c564(void)

{
  DAT_00067440 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004c58c FUN_0004c58c */

/* Boundary evidence: original MIPS .pdata 0004c58c..0004c5b3. Semantic name remains unreviewed. */

void FUN_0004c58c(void)

{
  DAT_0006764c = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004c5b4 FUN_0004c5b4 */

/* Boundary evidence: original MIPS .pdata 0004c5b4..0004c5db. Semantic name remains unreviewed. */

void FUN_0004c5b4(void)

{
  DAT_00067650 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004c5dc FUN_0004c5dc */

/* Boundary evidence: original MIPS .pdata 0004c5dc..0004c603. Semantic name remains unreviewed. */

void FUN_0004c5dc(void)

{
  DAT_00067654 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004c604 FUN_0004c604 */

/* Boundary evidence: original MIPS .pdata 0004c604..0004c62b. Semantic name remains unreviewed. */

void FUN_0004c604(void)

{
  DAT_00067658 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004c62c FUN_0004c62c */

/* Boundary evidence: original MIPS .pdata 0004c62c..0004c653. Semantic name remains unreviewed. */

void FUN_0004c62c(void)

{
  DAT_0006765c = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004c654 FUN_0004c654 */

/* Boundary evidence: original MIPS .pdata 0004c654..0004c67b. Semantic name remains unreviewed. */

void FUN_0004c654(void)

{
  DAT_00067660 = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004c67c FUN_0004c67c */

/* Boundary evidence: original MIPS .pdata 0004c67c..0004c6a3. Semantic name remains unreviewed. */

void FUN_0004c67c(void)

{
  DAT_00067664 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004c6a4 FUN_0004c6a4 */

/* Boundary evidence: original MIPS .pdata 0004c6a4..0004c6cb. Semantic name remains unreviewed. */

void FUN_0004c6a4(void)

{
  DAT_00067668 = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004c6cc FUN_0004c6cc */

/* Boundary evidence: original MIPS .pdata 0004c6cc..0004c6f3. Semantic name remains unreviewed. */

void FUN_0004c6cc(void)

{
  DAT_0006766c = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004c6f4 FUN_0004c6f4 */

/* Boundary evidence: original MIPS .pdata 0004c6f4..0004c71b. Semantic name remains unreviewed. */

void FUN_0004c6f4(void)

{
  DAT_0006846c = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004c71c FUN_0004c71c */

/* Boundary evidence: original MIPS .pdata 0004c71c..0004c743. Semantic name remains unreviewed. */

void FUN_0004c71c(void)

{
  DAT_00068470 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004c744 FUN_0004c744 */

/* Boundary evidence: original MIPS .pdata 0004c744..0004c76b. Semantic name remains unreviewed. */

void FUN_0004c744(void)

{
  DAT_00068474 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004c76c FUN_0004c76c */

/* Boundary evidence: original MIPS .pdata 0004c76c..0004c793. Semantic name remains unreviewed. */

void FUN_0004c76c(void)

{
  DAT_00068478 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004c794 FUN_0004c794 */

/* Boundary evidence: original MIPS .pdata 0004c794..0004c7bb. Semantic name remains unreviewed. */

void FUN_0004c794(void)

{
  DAT_0006847c = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004c7bc FUN_0004c7bc */

/* Boundary evidence: original MIPS .pdata 0004c7bc..0004c7e3. Semantic name remains unreviewed. */

void FUN_0004c7bc(void)

{
  DAT_00068480 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004c7e4 FUN_0004c7e4 */

/* Boundary evidence: original MIPS .pdata 0004c7e4..0004c80b. Semantic name remains unreviewed. */

void FUN_0004c7e4(void)

{
  DAT_00068484 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004c80c FUN_0004c80c */

/* Boundary evidence: original MIPS .pdata 0004c80c..0004c833. Semantic name remains unreviewed. */

void FUN_0004c80c(void)

{
  DAT_00068488 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004c834 FUN_0004c834 */

/* Boundary evidence: original MIPS .pdata 0004c834..0004c85b. Semantic name remains unreviewed. */

void FUN_0004c834(void)

{
  DAT_0006848c = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004c85c FUN_0004c85c */

/* Boundary evidence: original MIPS .pdata 0004c85c..0004c883. Semantic name remains unreviewed. */

void FUN_0004c85c(void)

{
  DAT_00068490 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004c884 FUN_0004c884 */

/* Boundary evidence: original MIPS .pdata 0004c884..0004c8ab. Semantic name remains unreviewed. */

void FUN_0004c884(void)

{
  DAT_00068494 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004c8ac FUN_0004c8ac */

/* Boundary evidence: original MIPS .pdata 0004c8ac..0004c8d3. Semantic name remains unreviewed. */

void FUN_0004c8ac(void)

{
  DAT_00068498 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004c8d4 FUN_0004c8d4 */

/* Boundary evidence: original MIPS .pdata 0004c8d4..0004c8fb. Semantic name remains unreviewed. */

void FUN_0004c8d4(void)

{
  DAT_0006849c = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004c8fc FUN_0004c8fc */

/* Boundary evidence: original MIPS .pdata 0004c8fc..0004c923. Semantic name remains unreviewed. */

void FUN_0004c8fc(void)

{
  DAT_000684a0 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004c924 FUN_0004c924 */

/* Boundary evidence: original MIPS .pdata 0004c924..0004c94b. Semantic name remains unreviewed. */

void FUN_0004c924(void)

{
  DAT_000684a4 = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004c94c FUN_0004c94c */

/* Boundary evidence: original MIPS .pdata 0004c94c..0004c973. Semantic name remains unreviewed. */

void FUN_0004c94c(void)

{
  DAT_000684a8 = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004c974 FUN_0004c974 */

/* Boundary evidence: original MIPS .pdata 0004c974..0004c99b. Semantic name remains unreviewed. */

void FUN_0004c974(void)

{
  DAT_000684ac = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004c99c FUN_0004c99c */

/* Boundary evidence: original MIPS .pdata 0004c99c..0004c9c3. Semantic name remains unreviewed. */

void FUN_0004c99c(void)

{
  DAT_000684b0 = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004c9c4 FUN_0004c9c4 */

/* Boundary evidence: original MIPS .pdata 0004c9c4..0004c9eb. Semantic name remains unreviewed. */

void FUN_0004c9c4(void)

{
  DAT_000684b4 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004c9ec FUN_0004c9ec */

/* Boundary evidence: original MIPS .pdata 0004c9ec..0004ca13. Semantic name remains unreviewed. */

void FUN_0004c9ec(void)

{
  DAT_000684c4 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004ca14 FUN_0004ca14 */

/* Boundary evidence: original MIPS .pdata 0004ca14..0004ca3b. Semantic name remains unreviewed. */

void FUN_0004ca14(void)

{
  DAT_000684c8 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004ca3c FUN_0004ca3c */

/* Boundary evidence: original MIPS .pdata 0004ca3c..0004ca63. Semantic name remains unreviewed. */

void FUN_0004ca3c(void)

{
  DAT_000684cc = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004ca64 FUN_0004ca64 */

/* Boundary evidence: original MIPS .pdata 0004ca64..0004ca8b. Semantic name remains unreviewed. */

void FUN_0004ca64(void)

{
  DAT_000684d0 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004ca8c FUN_0004ca8c */

/* Boundary evidence: original MIPS .pdata 0004ca8c..0004cab3. Semantic name remains unreviewed. */

void FUN_0004ca8c(void)

{
  DAT_000684d4 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004cab4 FUN_0004cab4 */

/* Boundary evidence: original MIPS .pdata 0004cab4..0004cadb. Semantic name remains unreviewed. */

void FUN_0004cab4(void)

{
  DAT_000684d8 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004cadc FUN_0004cadc */

/* Boundary evidence: original MIPS .pdata 0004cadc..0004cb03. Semantic name remains unreviewed. */

void FUN_0004cadc(void)

{
  DAT_000684dc = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004cb04 FUN_0004cb04 */

/* Boundary evidence: original MIPS .pdata 0004cb04..0004cb2b. Semantic name remains unreviewed. */

void FUN_0004cb04(void)

{
  DAT_000684e0 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004cb2c FUN_0004cb2c */

/* Boundary evidence: original MIPS .pdata 0004cb2c..0004cb53. Semantic name remains unreviewed. */

void FUN_0004cb2c(void)

{
  DAT_000684e4 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004cb54 FUN_0004cb54 */

/* Boundary evidence: original MIPS .pdata 0004cb54..0004cb7b. Semantic name remains unreviewed. */

void FUN_0004cb54(void)

{
  DAT_000684e8 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004cb7c FUN_0004cb7c */

/* Boundary evidence: original MIPS .pdata 0004cb7c..0004cba3. Semantic name remains unreviewed. */

void FUN_0004cb7c(void)

{
  DAT_000684ec = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004cba4 FUN_0004cba4 */

/* Boundary evidence: original MIPS .pdata 0004cba4..0004cbcb. Semantic name remains unreviewed. */

void FUN_0004cba4(void)

{
  DAT_000684f0 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004cbcc FUN_0004cbcc */

/* Boundary evidence: original MIPS .pdata 0004cbcc..0004cbf3. Semantic name remains unreviewed. */

void FUN_0004cbcc(void)

{
  DAT_000684f4 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004cbf4 FUN_0004cbf4 */

/* Boundary evidence: original MIPS .pdata 0004cbf4..0004cc1b. Semantic name remains unreviewed. */

void FUN_0004cbf4(void)

{
  DAT_000684f8 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004cc1c FUN_0004cc1c */

/* Boundary evidence: original MIPS .pdata 0004cc1c..0004cc43. Semantic name remains unreviewed. */

void FUN_0004cc1c(void)

{
  DAT_000684fc = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004cc44 FUN_0004cc44 */

/* Boundary evidence: original MIPS .pdata 0004cc44..0004cc6b. Semantic name remains unreviewed. */

void FUN_0004cc44(void)

{
  DAT_00068500 = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004cc6c FUN_0004cc6c */

/* Boundary evidence: original MIPS .pdata 0004cc6c..0004cc93. Semantic name remains unreviewed. */

void FUN_0004cc6c(void)

{
  DAT_00068504 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004cc94 FUN_0004cc94 */

/* Boundary evidence: original MIPS .pdata 0004cc94..0004ccbb. Semantic name remains unreviewed. */

void FUN_0004cc94(void)

{
  DAT_00068508 = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004ccbc FUN_0004ccbc */

/* Boundary evidence: original MIPS .pdata 0004ccbc..0004cce3. Semantic name remains unreviewed. */

void FUN_0004ccbc(void)

{
  DAT_0006850c = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004cce4 FUN_0004cce4 */

/* Boundary evidence: original MIPS .pdata 0004cce4..0004cd0b. Semantic name remains unreviewed. */

void FUN_0004cce4(void)

{
  DAT_00068510 = RegisterWindowMessageW(L"DAB FACTORY RESPONSE");
  return;
}



/* 0004cd0c FUN_0004cd0c */

/* Boundary evidence: original MIPS .pdata 0004cd0c..0004cd33. Semantic name remains unreviewed. */

void FUN_0004cd0c(void)

{
  DAT_00068514 = RegisterWindowMessageW(L"DAB FACTORY RECEIVE");
  return;
}



/* 0004cd34 FUN_0004cd34 */

/* Boundary evidence: original MIPS .pdata 0004cd34..0004cd5b. Semantic name remains unreviewed. */

void FUN_0004cd34(void)

{
  DAT_00068518 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004cd5c FUN_0004cd5c */

/* Boundary evidence: original MIPS .pdata 0004cd5c..0004cd83. Semantic name remains unreviewed. */

void FUN_0004cd5c(void)

{
  DAT_0006851c = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004cd84 FUN_0004cd84 */

/* Boundary evidence: original MIPS .pdata 0004cd84..0004cdab. Semantic name remains unreviewed. */

void FUN_0004cd84(void)

{
  DAT_00068520 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004cdac FUN_0004cdac */

/* Boundary evidence: original MIPS .pdata 0004cdac..0004cdd3. Semantic name remains unreviewed. */

void FUN_0004cdac(void)

{
  DAT_00068524 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004cdd4 FUN_0004cdd4 */

/* Boundary evidence: original MIPS .pdata 0004cdd4..0004cdfb. Semantic name remains unreviewed. */

void FUN_0004cdd4(void)

{
  DAT_00068528 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004cdfc FUN_0004cdfc */

/* Boundary evidence: original MIPS .pdata 0004cdfc..0004ce23. Semantic name remains unreviewed. */

void FUN_0004cdfc(void)

{
  DAT_0006852c = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004ce24 FUN_0004ce24 */

/* Boundary evidence: original MIPS .pdata 0004ce24..0004ce4b. Semantic name remains unreviewed. */

void FUN_0004ce24(void)

{
  DAT_00068530 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004ce4c FUN_0004ce4c */

/* Boundary evidence: original MIPS .pdata 0004ce4c..0004ce73. Semantic name remains unreviewed. */

void FUN_0004ce4c(void)

{
  DAT_00068534 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004ce74 FUN_0004ce74 */

/* Boundary evidence: original MIPS .pdata 0004ce74..0004ce9b. Semantic name remains unreviewed. */

void FUN_0004ce74(void)

{
  DAT_00068538 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004ce9c FUN_0004ce9c */

/* Boundary evidence: original MIPS .pdata 0004ce9c..0004cec3. Semantic name remains unreviewed. */

void FUN_0004ce9c(void)

{
  DAT_0006853c = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004cec4 FUN_0004cec4 */

/* Boundary evidence: original MIPS .pdata 0004cec4..0004ceeb. Semantic name remains unreviewed. */

void FUN_0004cec4(void)

{
  DAT_00068540 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004ceec FUN_0004ceec */

/* Boundary evidence: original MIPS .pdata 0004ceec..0004cf13. Semantic name remains unreviewed. */

void FUN_0004ceec(void)

{
  DAT_00068544 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004cf14 FUN_0004cf14 */

/* Boundary evidence: original MIPS .pdata 0004cf14..0004cf3b. Semantic name remains unreviewed. */

void FUN_0004cf14(void)

{
  DAT_00068548 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004cf3c FUN_0004cf3c */

/* Boundary evidence: original MIPS .pdata 0004cf3c..0004cf63. Semantic name remains unreviewed. */

void FUN_0004cf3c(void)

{
  DAT_0006854c = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004cf64 FUN_0004cf64 */

/* Boundary evidence: original MIPS .pdata 0004cf64..0004cf8b. Semantic name remains unreviewed. */

void FUN_0004cf64(void)

{
  DAT_00068550 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004cf8c FUN_0004cf8c */

/* Boundary evidence: original MIPS .pdata 0004cf8c..0004cfb3. Semantic name remains unreviewed. */

void FUN_0004cf8c(void)

{
  DAT_00068554 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004cfb4 FUN_0004cfb4 */

/* Boundary evidence: original MIPS .pdata 0004cfb4..0004cfdb. Semantic name remains unreviewed. */

void FUN_0004cfb4(void)

{
  DAT_00068558 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004cfdc FUN_0004cfdc */

/* Boundary evidence: original MIPS .pdata 0004cfdc..0004d003. Semantic name remains unreviewed. */

void FUN_0004cfdc(void)

{
  DAT_0006855c = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004d004 FUN_0004d004 */

/* Boundary evidence: original MIPS .pdata 0004d004..0004d02b. Semantic name remains unreviewed. */

void FUN_0004d004(void)

{
  DAT_00068560 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004d02c FUN_0004d02c */

/* Boundary evidence: original MIPS .pdata 0004d02c..0004d053. Semantic name remains unreviewed. */

void FUN_0004d02c(void)

{
  DAT_00068564 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004d054 FUN_0004d054 */

/* Boundary evidence: original MIPS .pdata 0004d054..0004d07b. Semantic name remains unreviewed. */

void FUN_0004d054(void)

{
  DAT_0006856c = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004d07c FUN_0004d07c */

/* Boundary evidence: original MIPS .pdata 0004d07c..0004d0a3. Semantic name remains unreviewed. */

void FUN_0004d07c(void)

{
  DAT_00068570 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004d0a4 FUN_0004d0a4 */

/* Boundary evidence: original MIPS .pdata 0004d0a4..0004d0cb. Semantic name remains unreviewed. */

void FUN_0004d0a4(void)

{
  DAT_00068574 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004d0cc FUN_0004d0cc */

/* Boundary evidence: original MIPS .pdata 0004d0cc..0004d0f3. Semantic name remains unreviewed. */

void FUN_0004d0cc(void)

{
  DAT_00068578 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004d0f4 FUN_0004d0f4 */

/* Boundary evidence: original MIPS .pdata 0004d0f4..0004d11b. Semantic name remains unreviewed. */

void FUN_0004d0f4(void)

{
  DAT_0006857c = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004d11c FUN_0004d11c */

/* Boundary evidence: original MIPS .pdata 0004d11c..0004d143. Semantic name remains unreviewed. */

void FUN_0004d11c(void)

{
  DAT_00068580 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004d144 FUN_0004d144 */

/* Boundary evidence: original MIPS .pdata 0004d144..0004d16b. Semantic name remains unreviewed. */

void FUN_0004d144(void)

{
  DAT_00068584 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004d16c FUN_0004d16c */

/* Boundary evidence: original MIPS .pdata 0004d16c..0004d193. Semantic name remains unreviewed. */

void FUN_0004d16c(void)

{
  DAT_00068588 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004d194 FUN_0004d194 */

/* Boundary evidence: original MIPS .pdata 0004d194..0004d1bb. Semantic name remains unreviewed. */

void FUN_0004d194(void)

{
  DAT_0006858c = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004d1bc FUN_0004d1bc */

/* Boundary evidence: original MIPS .pdata 0004d1bc..0004d1e3. Semantic name remains unreviewed. */

void FUN_0004d1bc(void)

{
  DAT_00068590 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004d1e4 FUN_0004d1e4 */

/* Boundary evidence: original MIPS .pdata 0004d1e4..0004d20b. Semantic name remains unreviewed. */

void FUN_0004d1e4(void)

{
  DAT_00068598 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004d20c FUN_0004d20c */

/* Boundary evidence: original MIPS .pdata 0004d20c..0004d233. Semantic name remains unreviewed. */

void FUN_0004d20c(void)

{
  DAT_0006859c = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004d234 FUN_0004d234 */

/* Boundary evidence: original MIPS .pdata 0004d234..0004d25b. Semantic name remains unreviewed. */

void FUN_0004d234(void)

{
  DAT_000685a0 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004d25c FUN_0004d25c */

/* Boundary evidence: original MIPS .pdata 0004d25c..0004d283. Semantic name remains unreviewed. */

void FUN_0004d25c(void)

{
  DAT_000685a4 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004d284 FUN_0004d284 */

/* Boundary evidence: original MIPS .pdata 0004d284..0004d2ab. Semantic name remains unreviewed. */

void FUN_0004d284(void)

{
  DAT_000685a8 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004d2ac FUN_0004d2ac */

/* Boundary evidence: original MIPS .pdata 0004d2ac..0004d2d3. Semantic name remains unreviewed. */

void FUN_0004d2ac(void)

{
  DAT_000685ac = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004d2d4 FUN_0004d2d4 */

/* Boundary evidence: original MIPS .pdata 0004d2d4..0004d2fb. Semantic name remains unreviewed. */

void FUN_0004d2d4(void)

{
  DAT_000685b0 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004d2fc FUN_0004d2fc */

/* Boundary evidence: original MIPS .pdata 0004d2fc..0004d323. Semantic name remains unreviewed. */

void FUN_0004d2fc(void)

{
  DAT_000685b4 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004d324 FUN_0004d324 */

/* Boundary evidence: original MIPS .pdata 0004d324..0004d34b. Semantic name remains unreviewed. */

void FUN_0004d324(void)

{
  DAT_000685b8 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004d34c FUN_0004d34c */

/* Boundary evidence: original MIPS .pdata 0004d34c..0004d373. Semantic name remains unreviewed. */

void FUN_0004d34c(void)

{
  DAT_000685bc = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004d374 FUN_0004d374 */

/* Boundary evidence: original MIPS .pdata 0004d374..0004d39b. Semantic name remains unreviewed. */

void FUN_0004d374(void)

{
  DAT_000685c8 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004d39c FUN_0004d39c */

/* Boundary evidence: original MIPS .pdata 0004d39c..0004d3c3. Semantic name remains unreviewed. */

void FUN_0004d39c(void)

{
  DAT_000685cc = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004d3c4 FUN_0004d3c4 */

/* Boundary evidence: original MIPS .pdata 0004d3c4..0004d3eb. Semantic name remains unreviewed. */

void FUN_0004d3c4(void)

{
  DAT_000685d0 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004d3ec FUN_0004d3ec */

/* Boundary evidence: original MIPS .pdata 0004d3ec..0004d413. Semantic name remains unreviewed. */

void FUN_0004d3ec(void)

{
  DAT_000685d4 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004d414 FUN_0004d414 */

/* Boundary evidence: original MIPS .pdata 0004d414..0004d43b. Semantic name remains unreviewed. */

void FUN_0004d414(void)

{
  DAT_000685d8 = RegisterWindowMessageW(L"ULC RES CAMINFO");
  return;
}



/* 0004d43c FUN_0004d43c */

/* Boundary evidence: original MIPS .pdata 0004d43c..0004d463. Semantic name remains unreviewed. */

void FUN_0004d43c(void)

{
  DAT_000685dc = RegisterWindowMessageW(L"Inverse Skin Change");
  return;
}



/* 0004d464 FUN_0004d464 */

/* Boundary evidence: original MIPS .pdata 0004d464..0004d48b. Semantic name remains unreviewed. */

void FUN_0004d464(void)

{
  DAT_000685e0 = RegisterWindowMessageW(L"ULC REQ DSI RVC INFO");
  return;
}



/* 0004d48c FUN_0004d48c */

/* Boundary evidence: original MIPS .pdata 0004d48c..0004d4b3. Semantic name remains unreviewed. */

void FUN_0004d48c(void)

{
  DAT_000685e4 = RegisterWindowMessageW(L"ULC RES DSI RVC INFO");
  return;
}



/* 0004d4b4 FUN_0004d4b4 */

/* Boundary evidence: original MIPS .pdata 0004d4b4..0004d4db. Semantic name remains unreviewed. */

void FUN_0004d4b4(void)

{
  DAT_000685e8 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004d4dc FUN_0004d4dc */

/* Boundary evidence: original MIPS .pdata 0004d4dc..0004d503. Semantic name remains unreviewed. */

void FUN_0004d4dc(void)

{
  DAT_0006861c = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004d504 FUN_0004d504 */

/* Boundary evidence: original MIPS .pdata 0004d504..0004d52b. Semantic name remains unreviewed. */

void FUN_0004d504(void)

{
  DAT_00068620 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004d52c FUN_0004d52c */

/* Boundary evidence: original MIPS .pdata 0004d52c..0004d553. Semantic name remains unreviewed. */

void FUN_0004d52c(void)

{
  DAT_00068624 = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004d554 FUN_0004d554 */

/* Boundary evidence: original MIPS .pdata 0004d554..0004d57b. Semantic name remains unreviewed. */

void FUN_0004d554(void)

{
  DAT_00068628 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004d57c FUN_0004d57c */

/* Boundary evidence: original MIPS .pdata 0004d57c..0004d5a3. Semantic name remains unreviewed. */

void FUN_0004d57c(void)

{
  DAT_0006862c = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004d5a4 FUN_0004d5a4 */

/* Boundary evidence: original MIPS .pdata 0004d5a4..0004d5cb. Semantic name remains unreviewed. */

void FUN_0004d5a4(void)

{
  DAT_00068630 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004d5cc FUN_0004d5cc */

/* Boundary evidence: original MIPS .pdata 0004d5cc..0004d5f3. Semantic name remains unreviewed. */

void FUN_0004d5cc(void)

{
  DAT_00068634 = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004d5f4 FUN_0004d5f4 */

/* Boundary evidence: original MIPS .pdata 0004d5f4..0004d61b. Semantic name remains unreviewed. */

void FUN_0004d5f4(void)

{
  DAT_00068638 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004d61c FUN_0004d61c */

/* Boundary evidence: original MIPS .pdata 0004d61c..0004d643. Semantic name remains unreviewed. */

void FUN_0004d61c(void)

{
  DAT_0006863c = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004d644 FUN_0004d644 */

/* Boundary evidence: original MIPS .pdata 0004d644..0004d66b. Semantic name remains unreviewed. */

void FUN_0004d644(void)

{
  DAT_00068640 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004d66c FUN_0004d66c */

/* Boundary evidence: original MIPS .pdata 0004d66c..0004d693. Semantic name remains unreviewed. */

void FUN_0004d66c(void)

{
  DAT_00068644 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004d694 FUN_0004d694 */

/* Boundary evidence: original MIPS .pdata 0004d694..0004d6bb. Semantic name remains unreviewed. */

void FUN_0004d694(void)

{
  DAT_00068648 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004d6bc FUN_0004d6bc */

/* Boundary evidence: original MIPS .pdata 0004d6bc..0004d6e3. Semantic name remains unreviewed. */

void FUN_0004d6bc(void)

{
  DAT_0006864c = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004d6e4 FUN_0004d6e4 */

/* Boundary evidence: original MIPS .pdata 0004d6e4..0004d70b. Semantic name remains unreviewed. */

void FUN_0004d6e4(void)

{
  DAT_00068650 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004d70c FUN_0004d70c */

/* Boundary evidence: original MIPS .pdata 0004d70c..0004d733. Semantic name remains unreviewed. */

void FUN_0004d70c(void)

{
  DAT_00068654 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004d734 FUN_0004d734 */

/* Boundary evidence: original MIPS .pdata 0004d734..0004d75b. Semantic name remains unreviewed. */

void FUN_0004d734(void)

{
  DAT_00068658 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004d75c FUN_0004d75c */

/* Boundary evidence: original MIPS .pdata 0004d75c..0004d783. Semantic name remains unreviewed. */

void FUN_0004d75c(void)

{
  DAT_0006865c = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004d784 FUN_0004d784 */

/* Boundary evidence: original MIPS .pdata 0004d784..0004d7ab. Semantic name remains unreviewed. */

void FUN_0004d784(void)

{
  DAT_00068660 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004d7ac FUN_0004d7ac */

/* Boundary evidence: original MIPS .pdata 0004d7ac..0004d7d3. Semantic name remains unreviewed. */

void FUN_0004d7ac(void)

{
  DAT_00068664 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004d7d4 FUN_0004d7d4 */

/* Boundary evidence: original MIPS .pdata 0004d7d4..0004d7fb. Semantic name remains unreviewed. */

void FUN_0004d7d4(void)

{
  DAT_00068668 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004d7fc FUN_0004d7fc */

/* Boundary evidence: original MIPS .pdata 0004d7fc..0004d823. Semantic name remains unreviewed. */

void FUN_0004d7fc(void)

{
  DAT_00068674 = RegisterWindowMessageW(L"SYSTEMtoMICOM");
  return;
}



/* 0004d824 FUN_0004d824 */

/* Boundary evidence: original MIPS .pdata 0004d824..0004d84b. Semantic name remains unreviewed. */

void FUN_0004d824(void)

{
  DAT_00068678 = RegisterWindowMessageW(L"MICOMtoNAVI");
  return;
}



/* 0004d84c FUN_0004d84c */

/* Boundary evidence: original MIPS .pdata 0004d84c..0004d873. Semantic name remains unreviewed. */

void FUN_0004d84c(void)

{
  DAT_0006867c = RegisterWindowMessageW(L"NAVItoMICOM");
  return;
}



/* 0004d874 FUN_0004d874 */

/* Boundary evidence: original MIPS .pdata 0004d874..0004d89b. Semantic name remains unreviewed. */

void FUN_0004d874(void)

{
  DAT_00068680 = RegisterWindowMessageW(L"DAB TEST");
  return;
}



/* 0004d89c FUN_0004d89c */

/* Boundary evidence: original MIPS .pdata 0004d89c..0004d8c3. Semantic name remains unreviewed. */

void FUN_0004d89c(void)

{
  DAT_00068684 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 0004d8c4 FUN_0004d8c4 */

/* Boundary evidence: original MIPS .pdata 0004d8c4..0004d8eb. Semantic name remains unreviewed. */

void FUN_0004d8c4(void)

{
  DAT_00068688 = RegisterWindowMessageW(L"DAB POWER CONTROL");
  return;
}



/* 0004d8ec FUN_0004d8ec */

/* Boundary evidence: original MIPS .pdata 0004d8ec..0004d913. Semantic name remains unreviewed. */

void FUN_0004d8ec(void)

{
  DAT_0006868c = RegisterWindowMessageW(L"DAB DR DTC");
  return;
}



/* 0004d914 FUN_0004d914 */

/* Boundary evidence: original MIPS .pdata 0004d914..0004d93b. Semantic name remains unreviewed. */

void FUN_0004d914(void)

{
  DAT_00068690 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004d93c FUN_0004d93c */

/* Boundary evidence: original MIPS .pdata 0004d93c..0004d963. Semantic name remains unreviewed. */

void FUN_0004d93c(void)

{
  DAT_00068694 = RegisterWindowMessageW(L"Msg for ULC Trigger to MGRMGM");
  return;
}



/* 0004d964 FUN_0004d964 */

/* Boundary evidence: original MIPS .pdata 0004d964..0004d98b. Semantic name remains unreviewed. */

void FUN_0004d964(void)

{
  DAT_00068698 = RegisterWindowMessageW(L"Msg for MGRMGM to ULC Trigger");
  return;
}



/* 0004d98c FUN_0004d98c */

/* Boundary evidence: original MIPS .pdata 0004d98c..0004d9ab. Semantic name remains unreviewed. */

void FUN_0004d98c(void)

{
  FUN_00036f60();
  return;
}



/* 0004d9ac FUN_0004d9ac */

/* Boundary evidence: original MIPS .pdata 0004d9ac..0004d9cb. Semantic name remains unreviewed. */

void FUN_0004d9ac(void)

{
  FUN_00036f60();
  return;
}


